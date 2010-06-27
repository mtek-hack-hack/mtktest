/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSViewerXML.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Decoder XML Related Functionality
 *
 *
 * Author: Sukrit K Mehra (PMT0050)
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define __MMI_MMSXMLDECODER_C
#include "MMI_include.h"
#ifdef __MMI_MMSXMLDECODER_C

#ifdef __MMI_MMS_2__

#include "MMSMsgXMLTags.h"
#include "MMSXMLDef.h"
#include "app_base64.h"

static mmi_umms_msg_parser_cntx g_umms_parser_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compare_string_ignore_case
 * DESCRIPTION
 *  compare two strings
 * PARAMETERS
 *  addr_1      [?]     
 *  addr_2      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static BOOL mmi_umms_compare_string_ignore_case(U16* addr_1, U16* addr_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 addr_index = 0;
    U16 char_A = 0x0041;
    U16 char_Z = 0x005A;
    U16 char_a = 0x0061;
    U16 addr_1_len = mmi_ucs2strlen((S8*)addr_1);
    U16 addr_2_len = mmi_ucs2strlen((S8*)addr_2);
    U16 addr_1_char = 0;
    U16 addr_2_char = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_1_len != addr_2_len)
    {
        return MMI_FALSE;
    }
    
    while (addr_index < addr_1_len)
    {
        if (addr_1[addr_index] >= char_A && addr_1[addr_index] <= char_Z)
        {
            addr_1_char = char_a + addr_1[addr_index] - char_A;
        }
        else
        {
            addr_1_char = addr_1[addr_index];            
        }

        if (addr_2[addr_index] >= char_A && addr_2[addr_index] <= char_Z)
        {
            addr_2_char = char_a + addr_2[addr_index] - char_A;
        }
        else
        {
            addr_2_char = addr_2[addr_index];
        }

        if (addr_1_char != addr_2_char)
        {
            return MMI_FALSE;
        }

        addr_index++;
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_duplicate_address
 * DESCRIPTION
 *  check duplicate addresses
 * PARAMETERS
 *  ucs2_addr       [?]         
 *  type            [IN]        
 *  group           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_umms_addr_struct *mmi_umms_check_duplicate_address(
                                U8 *ucs2_addr,
                                mmi_umms_address_type_enum type,
                                mmi_umms_address_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_addr_struct* addr_tail = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (group)
    {
        case MMI_UMMS_ADDRESS_GROUP_TYPE_TO:
        {
            addr_tail = g_umms_parser_cntx.msg->to_head;
        }
        break;
        
        case MMI_UMMS_ADDRESS_GROUP_TYPE_CC:
        {
            addr_tail = g_umms_parser_cntx.msg->cc_head;
        }
        break;

        case MMI_UMMS_ADDRESS_GROUP_TYPE_BCC:
        {
            addr_tail = g_umms_parser_cntx.msg->bcc_head;
        }
        break;

        case MMI_UMMS_ADDRESS_GROUP_TYPE_FROM:
        {
            addr_tail = g_umms_parser_cntx.msg->from;
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;        
    }
    
    if (type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
    {
        U8 addr[(MMI_UMMS_XML_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
        
        memset(addr, 0, sizeof(addr));
        mmi_ucs2_n_to_asc((S8*) addr, (S8*) ucs2_addr, MMI_UMMS_XML_MAX_ADDR_LEN * ENCODING_LENGTH);

        for (; addr_tail != NULL ; addr_tail = addr_tail->next)
        {
            if (addr_tail->type != MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
            {
                continue;
            }
            
            /* Compare number will compare only 40 digits!*/
            if (ComparePhoneNum(addr, addr_tail->addr) == MMI_TRUE )
            {
                return addr_tail;
            }
        }
    }
    else if (type == MMI_UMMS_ADDRESS_TYPE_EMAIL)
    {
        for (; addr_tail != NULL ; addr_tail = addr_tail->next)
        {
            if (addr_tail->type != MMI_UMMS_ADDRESS_TYPE_EMAIL)
            {
                continue;
            }
        
            if (mmi_umms_compare_string_ignore_case((U16*)ucs2_addr, (U16*)addr_tail->addr) == MMI_TRUE)
            {
                return addr_tail;
            }
        }        
    }
    else
    {
        MMI_ASSERT(0);
    }

    return NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_add_address
 * DESCRIPTION
 *  add address
 * PARAMETERS
 *  ucs2_addr       [?]         
 *  type            [IN]        
 *  group           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_umms_add_address(U8* ucs2_addr, mmi_umms_address_type_enum type, mmi_umms_address_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_addr_struct** addr_head = &(g_umms_parser_cntx.msg->to_head);
    mmi_umms_addr_struct* addr_tail = NULL;
    mmi_umms_addr_struct* addr_new = NULL;
    U8 addr_num_calculated = 0;
    U8* addr_num = NULL;
    U8* total_count = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (group)
    {
        case MMI_UMMS_ADDRESS_GROUP_TYPE_TO:
        {
            addr_tail = g_umms_parser_cntx.msg->to_head;
            addr_head = &(g_umms_parser_cntx.msg->to_head);
            addr_num = &(g_umms_parser_cntx.msg->to_num);
        }
        break;
        
        case MMI_UMMS_ADDRESS_GROUP_TYPE_CC:
        {
            addr_tail = g_umms_parser_cntx.msg->cc_head;
            addr_head = &(g_umms_parser_cntx.msg->cc_head);
            addr_num = &(g_umms_parser_cntx.msg->cc_num);
        }
        break;

        case MMI_UMMS_ADDRESS_GROUP_TYPE_BCC:
        {
            addr_tail = g_umms_parser_cntx.msg->bcc_head;
            addr_head = &(g_umms_parser_cntx.msg->bcc_head);
            addr_num = &(g_umms_parser_cntx.msg->bcc_num);
        }
        break;

        case MMI_UMMS_ADDRESS_GROUP_TYPE_FROM:
        {
            addr_tail = g_umms_parser_cntx.msg->from;
            addr_head = &(g_umms_parser_cntx.msg->from);
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;        
    }
    
    if (group != MMI_UMMS_ADDRESS_GROUP_TYPE_FROM)
    {
        if (addr_tail == NULL)
        {
            addr_num_calculated = 0;
        }
        else
        {
            addr_num_calculated = 1;
            
            for (; addr_tail->next != NULL ; addr_tail = addr_tail->next)
            {
                addr_num_calculated++;
            }
        }

        MMI_ASSERT((addr_num_calculated == (*addr_num)));
    }

    addr_new = g_umms_parser_cntx.mem_alloc_fn(sizeof(mmi_umms_addr_struct));

    MMI_ASSERT(addr_new);

    addr_new->type = type;
    addr_new->group = group;    
    addr_new->next = NULL;

    if (addr_new->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
    {
        U16 len = mmi_ucs2strlen((S8*)ucs2_addr);

        //MMI_ASSERT(len <= MMI_UMMS_XML_MAX_ADDR_LEN);
        
        addr_new->addr = g_umms_parser_cntx.mem_alloc_fn(len + 1);
        MMI_ASSERT(addr_new->addr);
        
        memset(addr_new->addr, 0, len + 1);
        mmi_ucs2_n_to_asc((S8*) addr_new->addr, (S8*) ucs2_addr, (len * ENCODING_LENGTH)-ENCODING_LENGTH); 
        total_count = &(g_umms_parser_cntx.msg->ph_num);
    }
    else if (addr_new->type == MMI_UMMS_ADDRESS_TYPE_EMAIL)
    {    
        U16 len = mmi_ucs2strlen((S8*)ucs2_addr);

        //MMI_ASSERT(len <= MMI_UMMS_XML_MAX_ADDR_LEN);
        
        addr_new->addr = g_umms_parser_cntx.mem_alloc_fn((len + 1) * ENCODING_LENGTH);
        MMI_ASSERT(addr_new->addr);

        memset(addr_new->addr, 0, ((len + 1) * ENCODING_LENGTH));
        memcpy(addr_new->addr, ucs2_addr, (len * ENCODING_LENGTH));
        total_count = &(g_umms_parser_cntx.msg->email_num);
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* First entry */
    if (addr_tail == NULL)
    {
        addr_new->previous = NULL;
        
        *addr_head = addr_new;
    }
    else
    {
        addr_new->previous = addr_tail;
        addr_tail->next = addr_new;
    }

    if (group != MMI_UMMS_ADDRESS_GROUP_TYPE_FROM)
    {
        (*addr_num) = (*addr_num) + 1;
    }

        (*total_count)++;

    return MMI_TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_xml_data_address_hdlr
 * DESCRIPTION
 *  xml handler for address tag's data field
 * PARAMETERS
 *  utf8_addr           [?]         
 *  addr_len            [IN]        
 *  addr_type           [IN]        
 *  addr_group_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_xml_data_address_hdlr(
                U8 *utf8_addr,
                S32 addr_len,
                mmi_umms_address_type_enum addr_type,
                mmi_umms_address_group_type_enum addr_group_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ucs2;
    U32 ucs2_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    if (addr_len == 0)
    {
        return;
    }

    ucs2_len = (addr_len + 1) * ENCODING_LENGTH;        
    ucs2 = g_umms_parser_cntx.mem_alloc_fn(ucs2_len);
    MMI_ASSERT(ucs2);
    memset(ucs2, 0, ucs2_len);
        
    mmi_chset_utf8_to_ucs2_string(ucs2, ucs2_len, utf8_addr);

    if (mmi_umms_check_duplicate_address(ucs2, addr_type, addr_group_type) != NULL)
    {
        PRINT_INFORMATION("");
    }
    else
    {    
        if (addr_type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER || addr_type == MMI_UMMS_ADDRESS_TYPE_EMAIL)
        {
            mmi_umms_add_address(ucs2, addr_type, addr_group_type);
        }
        else
        {
            MMI_ASSERT(0);
            PRINT_INFORMATION("");            
        }
    }
    
    g_umms_parser_cntx.mem_free_fn(ucs2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_insert_object_to_attachment
 * DESCRIPTION
 *  inserts object to attachment
 * PARAMETERS
 *  object          [?]     
 *  attachment      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_insert_object_to_attachment(
                mmi_umms_object_struct *object,
                mmi_umms_attachment_info_struct *attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attachment->object = object;
    object->reference_count++;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_insert_attachment
 * DESCRIPTION
 *  insert new attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_umms_attachment_info_struct* mmi_umms_insert_attachment()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_attachment_info_struct* new_attach;
    U32 attach_size;
    U32 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attach_size = sizeof(mmi_umms_attachment_info_struct);
    new_attach = g_umms_parser_cntx.mem_alloc_fn(attach_size);
    MMI_ASSERT(new_attach);
    memset(new_attach, 0, attach_size);

    if (g_umms_parser_cntx.msg->total_attachment_num == 0)
    {
        MMI_ASSERT(g_umms_parser_cntx.msg->attachment_head == NULL);
        g_umms_parser_cntx.msg->attachment_head = new_attach;

        new_attach->next = NULL;
        new_attach->previous = NULL;        
    }
    else
    {
        mmi_umms_attachment_info_struct* cur_attach = g_umms_parser_cntx.msg->attachment_head;

        MMI_ASSERT(cur_attach);
        
        for ( ; cur_attach->next != NULL; cur_attach = cur_attach->next)
        {
            i++;
        }

        MMI_ASSERT(i == g_umms_parser_cntx.msg->total_attachment_num);

        cur_attach->next = new_attach;
        new_attach->next = NULL;
        new_attach->previous = cur_attach;
    }
    
    g_umms_parser_cntx.msg->total_attachment_num++;

    return new_attach;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_convert_ascii_hex_to_dec
 * DESCRIPTION
 *  Converts Ascii value to Decimal value
 * PARAMETERS
 *  character       [IN]        
 *  S8 ascii values(?)(?)
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
static U32 mmi_umms_convert_ascii_hex_to_dec(U8* character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 value = 0;
    U8 c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip prefix "0x" or "0X" */
    if (character[0] == '0' && (character[1] == 'x' || character[1] == 'X'))
    {
        i = 2;
    }
    
    while ((c = character[i]) != 0)
    {
        value = value * 16;
        
        if (c > 47 && c < 58)   /* Digits 0..9 */
        {
            value += (c - 48);
        }
        else if (c > 64 && c < 71)  /* Characters A..F */
        {
            value += (c - 55);
        }
        else if (c > 96 && c < 103) /* Characters a..f */
        {
            value += (c - 87);
        }
        i++;
    }
    return value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_convert_mms_layout_type
 * DESCRIPTION
 *  convert layout
 * PARAMETERS
 *  layout_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_slide_layout_enum mmi_umms_convert_mms_layout_type(U8 layout_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( layout_type == MMA_LAYOUT_TEXT_ON_TOP )
    {
        return MMA_LAYOUT_TEXT_ON_TOP;
    }

    return MMA_LAYOUT_IMAGE_ON_TOP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_end_slide
 * DESCRIPTION
 *  get the last slide
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_umms_slide_struct* mmi_umms_get_end_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_slide_struct* slide = g_umms_parser_cntx.msg->slide_head;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(slide == NULL)
    {
        return NULL;
    }
    
    while (slide->next != NULL)
    {
        slide = slide->next;
    }

    return slide;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_insert_slide
 * DESCRIPTION
 *  insert a slide
 * PARAMETERS
 *  cur_slide       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_umms_slide_struct* mmi_umms_insert_slide(mmi_umms_slide_struct* cur_slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_slide_struct* new_slide;
    U32 slide_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide_size = sizeof(mmi_umms_slide_struct);
    new_slide = g_umms_parser_cntx.mem_alloc_fn(slide_size);
    MMI_ASSERT(new_slide);
    memset(new_slide, 0, slide_size);

    g_umms_parser_cntx.msg->total_slide_num++;
    /* new_slide->duration = g_umms_parser_cntx.msg->sliding_time; */

    MMI_ASSERT(g_umms_parser_cntx.msg->total_slide_num <= MMA_MAX_SLIDE_NO);

    /* First slide */
    if (cur_slide == NULL)
    {
        /* MMI_ASSERT( g_umms_p->msg.total_slide_num == 1 ); */
        new_slide->next = g_umms_parser_cntx.msg->slide_head;
        new_slide->previous = NULL;

        if (g_umms_parser_cntx.msg->slide_head)
        {
            g_umms_parser_cntx.msg->slide_head->previous = new_slide;
        }
        
        g_umms_parser_cntx.msg->slide_head = new_slide;        

        new_slide->slide_num = 1;

        if (new_slide->next)
        {
            mmi_umms_slide_struct* update_slide = mmi_umms_get_end_slide();            

            while (update_slide != new_slide)
            {
                update_slide->slide_num++;
                /* mmi_umms_update_text_object_path(update_slide); */
                update_slide = update_slide->previous;
            }
        }       
    }
    else
    {
        new_slide->slide_num = cur_slide->slide_num + 1;
        
        new_slide->next = cur_slide->next;
        new_slide->previous = cur_slide;
        
        if (cur_slide->next)
        {
            mmi_umms_slide_struct* update_slide = mmi_umms_get_end_slide(); 
            
            cur_slide->next->previous = new_slide;

            while (update_slide != new_slide)
            {
                update_slide->slide_num++;
                /* mmi_umms_update_text_object_path(update_slide); */
                update_slide = update_slide->previous;
            }
        }                
        cur_slide->next = new_slide;
    }

    return new_slide;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_insert_slide_by_number
 * DESCRIPTION
 *  insert slide by number
 * PARAMETERS
 *  slide_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_umms_slide_struct* mmi_umms_insert_slide_by_number(U8 slide_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_slide_struct* cur_slide = g_umms_parser_cntx.msg->slide_head;
    mmi_umms_slide_struct* pre_slide = cur_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide_number == 1)
    {
        return mmi_umms_insert_slide(NULL);        
    }
    else
    {
        while (cur_slide && (cur_slide->slide_num < slide_number))
        {
            pre_slide = cur_slide;
            cur_slide = cur_slide->next;
        }

        return mmi_umms_insert_slide(pre_slide);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_insert_object_to_list_tail
 * DESCRIPTION
 *  insert object to list tail
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_umms_object_struct* mmi_umms_insert_object_to_list_tail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_object_struct* new_object;
    U32 object_size;     
    U32 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_size = sizeof(mmi_umms_object_struct);
    new_object = g_umms_parser_cntx.mem_alloc_fn(object_size);
    MMI_ASSERT(new_object);
    memset(new_object, 0, object_size);

    /* First object */
    if (g_umms_parser_cntx.msg->object_head == NULL)
    {
        g_umms_parser_cntx.msg->object_head = new_object;
        new_object->next = NULL;
        new_object->previous = NULL;
    }
    else
    {
        mmi_umms_object_struct* cur_object = g_umms_parser_cntx.msg->object_head;

        while (cur_object->next)
        {
            MMI_ASSERT( i < g_umms_parser_cntx.msg->total_object_num);
            cur_object = cur_object->next;
            i++;
        }        

        cur_object->next = new_object;
        
        new_object->next = NULL;
        new_object->previous = cur_object;
    }

    g_umms_parser_cntx.msg->total_object_num++;

    return new_object;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_xml_start_element_hdlr
 * DESCRIPTION
 *  start handler for xml tags
 * PARAMETERS
 *  data        [?]         
 *  el          [IN]        
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != 0)
    {
        return;
    }
    
    if ((!strcmp(MMI_UMMS_XML_ELEMENT_TO, el)) || 
        (!strcmp(MMI_UMMS_XML_ELEMENT_CC, el)) ||
        (!strcmp(MMI_UMMS_XML_ELEMENT_BCC, el)) || (!strcmp(MMI_UMMS_XML_ELEMENT_FROM, el)))
    {
        if (!strcmp(MMI_UMMS_XML_ATTR_TYPE, attr[0]))
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_POHNE_NUMBER, attr[1]))
            {
               g_umms_parser_cntx.addr_type = MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER;
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_EMAIL_ADDR, attr[1]))
            {
               g_umms_parser_cntx.addr_type = MMI_UMMS_ADDRESS_TYPE_EMAIL;
            }
            else
            {                
                MMI_ASSERT(0);
                
                PRINT_INFORMATION("");

            }
        }
    }

    if (g_umms_parser_cntx.flags & MMI_UMMS_MSG_PARSER_IGNORE_SLIDES)
    {
        return;
    }
    
    if (!strcmp(MMI_UMMS_XML_ELEMENT_BODY , el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_BGCOLOR , attr[i]))
            {
                g_umms_parser_cntx.msg->background_color = mmi_umms_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_FGCOLOR , attr[i]))
            {
                g_umms_parser_cntx.msg->foreground_color = mmi_umms_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_SLIDE_NUM , attr[i]))
            {
                /* updated in mmi_umms_insert_slide_by_number*/
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_OBJ_NUM , attr[i]))
            {
                /* updated in mmi_umms_insert_object_to_list_tail() */
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_LAYOUT , attr[i]))
            {
                g_umms_parser_cntx.msg->layout = mmi_umms_convert_mms_layout_type((U8)atoi((S8*) attr[i + 1]));
            }                
        }        
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_SLIDE, el))
    {
        U8 slide_number = 0;
        U8 duration = 0;

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_INDEX, attr[i]))
            {
                slide_number = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_DURATION , attr[i]))
            {
                duration = atoi((S8*) attr[i + 1]);
            }
        }

        if (slide_number)
        {
            g_umms_parser_cntx.slide = mmi_umms_insert_slide_by_number(slide_number);

            if (g_umms_parser_cntx.slide)
            {
                MMI_ASSERT(g_umms_parser_cntx.slide->slide_num == slide_number);
                if (duration)
                {
                    g_umms_parser_cntx.slide->duration = duration;
                }
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_TEXT , el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID , attr[i]))
            {
                g_umms_parser_cntx.slide->text.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BEGIN , attr[i]))
            {
                g_umms_parser_cntx.slide->text.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_END , attr[i]))
            {
                g_umms_parser_cntx.slide->text.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BGCOLOR , attr[i]))
            {
                g_umms_parser_cntx.slide->text.background_color = mmi_umms_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_FGCOLOR , attr[i]))
            {
                g_umms_parser_cntx.slide->text.foreground_color = mmi_umms_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_TEXT_SIZE, attr[i]))
        {
                g_umms_parser_cntx.slide->text.txtSize = atoi((S8*) attr[i + 1]) - 1;
                                                                                    /*-1 to convert from mma_text_size_enum to WGUI_FONT_SIZE */
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_TEXT_STYLE, attr[i]))
            {
                g_umms_parser_cntx.slide->text.txtStyle = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATRR_ALT_STR, attr[i]))
            {
                g_umms_parser_cntx.slide->text.alt_str = g_umms_parser_cntx.mem_alloc_fn(MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                memset(g_umms_parser_cntx.slide->text.alt_str, 0, MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) g_umms_parser_cntx.slide->text.alt_str,
                    MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH,
                    (kal_uint8*) attr[i + 1]);
            }

        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_IMAGE, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID , attr[i]))
            {
                g_umms_parser_cntx.slide->image.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BEGIN , attr[i]))
            {
                g_umms_parser_cntx.slide->image.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_END , attr[i]))
            {
                g_umms_parser_cntx.slide->image.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATRR_ALT_STR, attr[i]))
            {
                g_umms_parser_cntx.slide->image.alt_str = g_umms_parser_cntx.mem_alloc_fn(MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                memset(g_umms_parser_cntx.slide->image.alt_str, 0, MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) g_umms_parser_cntx.slide->image.alt_str,
                    MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH,
                    (kal_uint8*) attr[i + 1]);
            }
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_AUDIO, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID , attr[i]))
            {
                g_umms_parser_cntx.slide->audio.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BEGIN , attr[i]))
            {
                g_umms_parser_cntx.slide->audio.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_END , attr[i]))
            {
                g_umms_parser_cntx.slide->audio.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATRR_ALT_STR, attr[i]))
            {
                g_umms_parser_cntx.slide->audio.alt_str = g_umms_parser_cntx.mem_alloc_fn(MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                memset(g_umms_parser_cntx.slide->audio.alt_str, 0, MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) g_umms_parser_cntx.slide->audio.alt_str,
                    MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH,
                    (kal_uint8*) attr[i + 1]);
            }
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_VIDEO, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID , attr[i]))
            {
                g_umms_parser_cntx.slide->video.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BEGIN , attr[i]))
            {
                g_umms_parser_cntx.slide->video.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_END , attr[i]))
            {
                g_umms_parser_cntx.slide->video.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATRR_ALT_STR, attr[i]))
            {
                g_umms_parser_cntx.slide->video.alt_str = g_umms_parser_cntx.mem_alloc_fn(MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                memset(g_umms_parser_cntx.slide->video.alt_str, 0, MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) g_umms_parser_cntx.slide->video.alt_str,
                    MMI_UMMS_MAX_ALT_STR_LEN * ENCODING_LENGTH,
                    (kal_uint8*) attr[i + 1]);
            }
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_OBJECT, el))
    {
        g_umms_parser_cntx.object = mmi_umms_insert_object_to_list_tail();
        
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID , attr[i]))
            {
                g_umms_parser_cntx.object->id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_ATTACH , attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_umms_parser_cntx.object->type = MMI_UMMS_OBJECT_TYPE_ATTACHMENT;
                }
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_VIRTUAL_FILE , attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_umms_parser_cntx.object->is_virtual_file = MMI_TRUE;
                }
                else
                {
                    g_umms_parser_cntx.object->is_virtual_file = MMI_FALSE;
                }
            }            
            else if (!strcmp(MMI_UMMS_XML_ATTR_DRM, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_umms_parser_cntx.object->drm_type = (atoi((S8*) attr[i + 1]));
                }
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_SIZE , attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_umms_parser_cntx.object->size = (atoi((S8*) attr[i + 1]));
                }
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_OFFSET  , attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_umms_parser_cntx.object->offset = (atoi((S8*) attr[i + 1]));
                }
            }            
            else if (!strcmp(MMI_UMMS_XML_ATTR_ENCODING_SCHEME, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_umms_parser_cntx.object->encoding_scheme = (atoi((S8*) attr[i + 1]));
                }
            }
        }        
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_xml_end_element_hdlr
 * DESCRIPTION
 *  xml handler for end tag
 * PARAMETERS
 *  data        [?]         
 *  el          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_xml_end_element_hdlr(void *data, const char *el, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != 0)
    {
        return;
    }
    
    
    if (g_umms_parser_cntx.flags & MMI_UMMS_MSG_PARSER_IGNORE_SLIDES)
    {
        return;
    }
    
    if (!strcmp(MMI_UMMS_XML_ELEMENT_OBJECT, el))
    {   
        if (g_umms_parser_cntx.object->type == MMI_UMMS_OBJECT_TYPE_ATTACHMENT)
        {
            mmi_umms_attachment_info_struct* att;

            att = mmi_umms_insert_attachment();
            mmi_umms_insert_object_to_attachment(g_umms_parser_cntx.object, att);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_xml_data_hdlr
 * DESCRIPTION
 *  xml handler for data elements
 * PARAMETERS
 *  data        [?]         
 *  el          [IN]        
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error)
{
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != 0)
    {
        return;
    }
    
    if (!strcmp(MMI_UMMS_XML_ELEMENT_TO, el))
    {   
        mmi_umms_xml_data_address_hdlr((U8*) value, len, g_umms_parser_cntx.addr_type, MMI_UMMS_ADDRESS_GROUP_TYPE_TO);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_CC, el))
    {
        mmi_umms_xml_data_address_hdlr((U8*) value, len, g_umms_parser_cntx.addr_type, MMI_UMMS_ADDRESS_GROUP_TYPE_CC);
    }    
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_BCC, el))
    {
        mmi_umms_xml_data_address_hdlr(
                (U8*)value,
                len,
                g_umms_parser_cntx.addr_type, 
                MMI_UMMS_ADDRESS_GROUP_TYPE_BCC);
    }    
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_FROM, el))
    {
        mmi_umms_xml_data_address_hdlr((U8*) value, len, g_umms_parser_cntx.addr_type, MMI_UMMS_ADDRESS_GROUP_TYPE_FROM);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_SUBJECT, el))
    {
        U8 *utf8_data = NULL;
        U32 base64_len = 0;
        U32 utf8_len = 0;

        memset(g_umms_parser_cntx.msg->subject, 0 ,MMI_UMMS_XML_MAX_SUBJECT_LEN * ENCODING_LENGTH);        
        if (0 == len)
        {
            return;
        }

        base64_len = strlen((S8*)value);
        utf8_len = applib_base64_decode_len((S8*)value, base64_len);
        utf8_data = g_umms_parser_cntx.mem_alloc_fn(utf8_len + 1);
        
		memset(utf8_data, 0 , utf8_len + 1);
        applib_base64_decode((S8*)value, base64_len, (S8*)utf8_data,utf8_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_umms_parser_cntx.msg->subject,
            (MMI_UMMS_XML_MAX_SUBJECT_LEN +1) * ENCODING_LENGTH,
            (kal_uint8*) utf8_data);
		g_umms_parser_cntx.mem_free_fn(utf8_data);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_REPORTED_SUBJECT, el))
    {
        U8 *utf8_data = NULL;
        U32 base64_len = 0;
        U32 utf8_len = 0;
        memset(g_umms_parser_cntx.msg->reported_subject, 0 ,MMI_UMMS_XML_MAX_SUBJECT_LEN * ENCODING_LENGTH);
        if (0 == len)
        {
            return;
        }
        base64_len = strlen((S8*)value);
        utf8_len = applib_base64_decode_len((S8*)value, base64_len);
        utf8_data = g_umms_parser_cntx.mem_alloc_fn(utf8_len + 1);
		memset(utf8_data, 0 , utf8_len + 1);
        applib_base64_decode((S8*)value, base64_len, (S8*)utf8_data,utf8_len);

        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_umms_parser_cntx.msg->reported_subject,
            (MMI_UMMS_XML_MAX_SUBJECT_LEN +1) * ENCODING_LENGTH,
            (kal_uint8*) utf8_data);
		g_umms_parser_cntx.mem_free_fn(utf8_data);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_READ_REPORT, el))
    {
        if (atoi((S8*) value))
        {
            g_umms_parser_cntx.msg->read_report = MMI_TRUE;
        }
        else
        {
            g_umms_parser_cntx.msg->read_report = MMI_FALSE;
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_DELIVERY_REPORT, el))
    {
        if (atoi((S8*) value))
        {
            g_umms_parser_cntx.msg->delivery_report = MMI_TRUE;
        }
        else
        {
            g_umms_parser_cntx.msg->delivery_report = MMI_FALSE;
        }
    }    
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_PRIORITY , el))
    {
        g_umms_parser_cntx.msg->priority = atoi((S8*) value);        
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_EXPIRY , el))
    {
        g_umms_parser_cntx.msg->expiry_time = atoi((S8*) value);        
    }    
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_DL_SIZE, el))
    {
        g_umms_parser_cntx.msg->download_size = atoi((S8*) value);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_DELIVERY_TIME , el))
    {
        g_umms_parser_cntx.msg->delivery_time = atoi((S8*) value);        
    }    
	else if (!strcmp(MMI_UMMS_XML_ELEMENT_DATE , el))
    {
        g_umms_parser_cntx.msg->date = atoi((S8*) value);        
    }    
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_VISIBLE , el))
    {
        if (atoi((S8*) value))
        {
            g_umms_parser_cntx.msg->sender_visibility = MMI_TRUE;
        }
        else
        {
            g_umms_parser_cntx.msg->sender_visibility = MMI_FALSE;
        }
    }    
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_JAVA_APP_ID, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        MMI_ASSERT(g_umms_parser_cntx.msg);
 //       MMI_ASSERT(g_umms_parser_cntx.msg->java_app_id == NULL);

        /* g_umms_parser_cntx.msg->java_app_id = g_umms_parser_cntx.mem_alloc_fn(ucs2_len); */
        //MMI_ASSERT(g_umms_parser_cntx.msg->java_app_id);
        memset(g_umms_parser_cntx.msg->java_app_id, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string((kal_uint8*) g_umms_parser_cntx.msg->java_app_id, ucs2_len, (kal_uint8*) value);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_JAVA_REPLY_APP_ID, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        MMI_ASSERT(g_umms_parser_cntx.msg);
        //MMI_ASSERT(g_umms_parser_cntx.msg->java_reply_app_id == NULL);

        /* g_umms_parser_cntx.msg->java_reply_app_id = g_umms_parser_cntx.mem_alloc_fn(ucs2_len); */
        //MMI_ASSERT(g_umms_parser_cntx.msg->java_reply_app_id);
        memset(g_umms_parser_cntx.msg->java_reply_app_id, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_umms_parser_cntx.msg->java_reply_app_id,
            ucs2_len,
            (kal_uint8*) value);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_MIME_TYPE, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        MMI_ASSERT(g_umms_parser_cntx.object);
        MMI_ASSERT(g_umms_parser_cntx.object->mime_type == NULL);

        g_umms_parser_cntx.object->mime_type = g_umms_parser_cntx.mem_alloc_fn(ucs2_len);
        MMI_ASSERT(g_umms_parser_cntx.object->mime_type);
        memset(g_umms_parser_cntx.object->mime_type, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_umms_parser_cntx.object->mime_type,
            ucs2_len,
            (kal_uint8*) value);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_CONTENT_ID, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        MMI_ASSERT(g_umms_parser_cntx.object);
        MMI_ASSERT(g_umms_parser_cntx.object->content_id == NULL);

        g_umms_parser_cntx.object->content_id = g_umms_parser_cntx.mem_alloc_fn(ucs2_len);
        MMI_ASSERT(g_umms_parser_cntx.object->content_id);
        memset(g_umms_parser_cntx.object->content_id, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_umms_parser_cntx.object->content_id,
            ucs2_len,
            (kal_uint8*) value);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_CONTENT_LOCATION, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        MMI_ASSERT(g_umms_parser_cntx.object);
        MMI_ASSERT(g_umms_parser_cntx.object->content_location == NULL);

        g_umms_parser_cntx.object->content_location = g_umms_parser_cntx.mem_alloc_fn(ucs2_len);
        MMI_ASSERT(g_umms_parser_cntx.object->content_location);
        memset(g_umms_parser_cntx.object->content_location, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_umms_parser_cntx.object->content_location,
            ucs2_len,
            (kal_uint8*) value);
    }

    else if (!strcmp(MMI_UMMS_XML_ELEMENT_STATUS, el))
    {
        g_umms_parser_cntx.msg->status = atoi((S8*) value);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_REPORT_MSG_ID, el))
    {
        g_umms_parser_cntx.msg->reported_msg_id = atoi((S8*) value);
    }
        
    if (g_umms_parser_cntx.flags & MMI_UMMS_MSG_PARSER_IGNORE_SLIDES)
    {
        return;
    }
    
    if (!strcmp(MMI_UMMS_XML_ELEMENT_NAME , el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;
        
        MMI_ASSERT(len);
        MMI_ASSERT(g_umms_parser_cntx.object);
        MMI_ASSERT(g_umms_parser_cntx.object->file_name == NULL);

        g_umms_parser_cntx.object->file_name = g_umms_parser_cntx.mem_alloc_fn(ucs2_len);
        MMI_ASSERT(g_umms_parser_cntx.object->file_name);
        memset(g_umms_parser_cntx.object->file_name, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_umms_parser_cntx.object->file_name,
            ucs2_len,
            (kal_uint8*) value);
    }    
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_FILE_PATH  , el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;
        
        MMI_ASSERT(len);
        MMI_ASSERT(g_umms_parser_cntx.object);
        MMI_ASSERT(g_umms_parser_cntx.object->file_path == NULL);

        g_umms_parser_cntx.object->file_path = g_umms_parser_cntx.mem_alloc_fn(ucs2_len);
        MMI_ASSERT(g_umms_parser_cntx.object->file_path);
        memset(g_umms_parser_cntx.object->file_path, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_umms_parser_cntx.object->file_path,
            ucs2_len,
            (kal_uint8*) value);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_object_by_id
 * DESCRIPTION
 *  get an object by id
 * PARAMETERS
 *  object_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_umms_object_struct* mmi_umms_get_object_by_id(U32 object_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_object_struct* cur_object = g_umms_parser_cntx.msg->object_head;
    U32 object_num = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; cur_object != NULL; cur_object = cur_object->next, object_num++)
    {
        MMI_ASSERT( object_num <= g_umms_parser_cntx.msg->total_object_num);
        
        if (cur_object->id == object_id)
        {
            return cur_object;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_insert_object_to_slide
 * DESCRIPTION
 *  inserts an object to a slide
 * PARAMETERS
 *  object          [?]         
 *  slide           [?]         
 *  object_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_insert_object_to_slide(
                mmi_umms_object_struct *object,
                mmi_umms_slide_struct *slide,
                mmi_umms_object_type object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch (object_type)
    {
        case MMI_UMMS_OBJECT_TYPE_IMAGE:
        {
            slide->image.object = object;
            /*slide->image.begin = MMI_UMMS_INVALID_VALUE;*/
            /*slide->image.end = MMI_UMMS_INVALID_VALUE;*/
            object->reference_count++;
        }
        break;

        case MMI_UMMS_OBJECT_TYPE_AUDIO:
        {
            slide->audio.object = object;
            /*slide->audio.begin = MMI_UMMS_INVALID_VALUE;*/
            /*slide->audio.end = MMI_UMMS_INVALID_VALUE;*/
            object->reference_count++;
        }
        break;

        case MMI_UMMS_OBJECT_TYPE_VIDEO:
        {
            slide->video.object = object;
            /*slide->video.begin = MMI_UMMS_INVALID_VALUE;*/
            /*slide->video.end = MMI_UMMS_INVALID_VALUE;*/
            object->reference_count++;
        }
        break;

        case MMI_UMMS_OBJECT_TYPE_TEXT:
        {
            slide->text.object = object;
            /*slide->text.background_color = MMI_UMMS_DEFAULT_BG_COLOR;*/
            /*slide->text.foreground_color = MMI_UMMS_DEFAULT_FG_COLOR;*/
            /*slide->text.begin = MMI_UMMS_INVALID_VALUE;*/
            /*slide->text.end = MMI_UMMS_INVALID_VALUE;*/
            object->reference_count++;
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_match_object_id
 * DESCRIPTION
 *  match object ids
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_match_object_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_slide_struct* cur_slide = g_umms_parser_cntx.msg->slide_head;
    U32 slide_num = 0;
    mmi_umms_object_struct* cur_object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; cur_slide != NULL; cur_slide = cur_slide->next, slide_num++)
    {
        if (cur_slide->text.id)
        {
            MMI_ASSERT((cur_object = mmi_umms_get_object_by_id(cur_slide->text.id)) != NULL);                        
                mmi_umms_insert_object_to_slide(cur_object, cur_slide, MMI_UMMS_OBJECT_TYPE_TEXT);
                cur_slide->text.object->type = MMI_UMMS_OBJECT_TYPE_TEXT;
            }
        if (cur_slide->image.id)
        {
            MMI_ASSERT((cur_object = mmi_umms_get_object_by_id(cur_slide->image.id)) != NULL);                    
            mmi_umms_insert_object_to_slide(cur_object, cur_slide, MMI_UMMS_OBJECT_TYPE_IMAGE);
            cur_slide->image.object->type = MMI_UMMS_OBJECT_TYPE_IMAGE;    
        }
        if (cur_slide->audio.id)
        {
            MMI_ASSERT((cur_object = mmi_umms_get_object_by_id(cur_slide->audio.id)) != NULL);
            mmi_umms_insert_object_to_slide(cur_object, cur_slide, MMI_UMMS_OBJECT_TYPE_AUDIO);
            cur_slide->audio.object->type = MMI_UMMS_OBJECT_TYPE_AUDIO;            
        }
        if (cur_slide->video.id)
        {
            MMI_ASSERT((cur_object = mmi_umms_get_object_by_id(cur_slide->video.id)) != NULL);
            mmi_umms_insert_object_to_slide(cur_object, cur_slide, MMI_UMMS_OBJECT_TYPE_VIDEO);
            cur_slide->video.object->type = MMI_UMMS_OBJECT_TYPE_VIDEO;            
        }        
    }

    MMI_ASSERT( slide_num == g_umms_parser_cntx.msg->total_slide_num);

}

/* External Interfaces */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_parse_mms_xml_description_file
 * DESCRIPTION
 *  main exported API to parse mms xml file
 * PARAMETERS
 *  file_path           [IN]        
 *  mem_alloc_fn        [IN]        
 *  mem_free_fn         [IN]        
 *  msg                 [?]         
 *  flags               [IN]     currently unused   
 * RETURNS
 *  
 *****************************************************************************/
XML_RESULT_ENUM mmi_umms_parse_mms_xml_description_file(
                    PU16 file_path,
                    mmi_umms_alloc_mem mem_alloc_fn,
                    mmi_umms_free_mem mem_free_fn,
                    mmi_umms_xml_msg_struct *msg,
                    U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    XML_PARSER_STRUCT* xml_parser;

	/*flags currently unused */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    xml_parser = OslMalloc(sizeof(XML_PARSER_STRUCT));

    memset(xml_parser, 0, sizeof(XML_PARSER_STRUCT));

    result = xml_new_parser(xml_parser);

    if (result)
    {
        xml_close_parser(xml_parser);
        OslMfree(xml_parser);
        xml_parser = NULL;
        return XML_RESULT_FAIL;
    }
    memset(&g_umms_parser_cntx, 0, sizeof(mmi_umms_msg_parser_cntx));
    g_umms_parser_cntx.mem_alloc_fn = mem_alloc_fn;
    g_umms_parser_cntx.mem_free_fn = mem_free_fn;
    g_umms_parser_cntx.msg = msg;
    g_umms_parser_cntx.flags = flags;

    xml_register_element_handler(xml_parser, mmi_umms_xml_start_element_hdlr, mmi_umms_xml_end_element_hdlr);

    xml_register_data_handler(xml_parser, mmi_umms_xml_data_hdlr);

    result = xml_parse(xml_parser, file_path);

    xml_close_parser(xml_parser);

    OslMfree(xml_parser);
    xml_parser = NULL;

    if (result)
    {
        return XML_RESULT_FAIL;
    }
    else
    {
        mmi_umms_match_object_id();
        return XML_RESULT_OK;
    }
}

#endif /* __MMI_MMS_2__ */
#endif /*__MMI_MMSXMLDECODER_C*/
