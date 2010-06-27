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
 *  JMMSUCXMLDecoder.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the code for Message generation from XML Code.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_JMMS_UC_XML_DECODER_C
#define _MMI_JMMS_UC_XML_DECODER_C

#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT) && defined(__MMI_UNIFIED_COMPOSER__))

#include "mdi_datatype.h"
#include "FileManagerGProt.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"

#include "UnifiedMessageGProt.h"
#include "JMMSStructs.h"
#include "JMMSUCXMLProt.h"
#include "JMMSConfig.h"
#include "JMMSCompose.h"
#include "JMMSWriteMMS.h"
#include "JMMSExdcl.h"
#include "JMMSCoreAPI.h"
#include "ddl.h"
#include "JMMSUCInterfaceProt.h"
#include "Conversions.h"
#include "JMMSProtocols.h"
#include "JMMSView.h"
#include "JMMSStoreHandling.h"
#include "JMMSMainMMS.h"
#include "app_base64.h"
#include "miscutils.h"

extern pBOOL GetUCS2Flag(PS8);
extern U32 get_current_utc_time(void);

const mmi_jmms_uc_tags_map_struct g_jmms_uc_xml_tags_start_handler_map[] = 
{
    {MMI_JMMS_UC_XML_ELEMENT_MMS, NULL},
    {MMI_JMMS_UC_XML_ELEMENT_HEADER, NULL},
    {MMI_JMMS_UC_XML_ELEMENT_TO, mmi_jmms_uc_xml_to_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_CC, mmi_jmms_uc_xml_cc_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_BCC, mmi_jmms_uc_xml_bcc_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_FROM, mmi_jmms_uc_xml_from_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_SUBJECT, mmi_jmms_uc_xml_subject_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_READ_REPORT, mmi_jmms_uc_xml_rr_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_DELIVERY_REPORT, mmi_jmms_uc_xml_dr_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_PRIORITY, mmi_jmms_uc_xml_prio_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_EXPIRY, mmi_jmms_uc_xml_expiry_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_DELIVERY_TIME, mmi_jmms_uc_xml_delivery_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_VISIBLE, mmi_jmms_uc_xml_visible_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_BODY, mmi_jmms_uc_xml_body_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_SLIDE, mmi_jmms_uc_xml_slide_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_TEXT, mmi_jmms_uc_xml_text_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_IMAGE, mmi_jmms_uc_xml_image_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_AUDIO, mmi_jmms_uc_xml_audio_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_VIDEO, mmi_jmms_uc_xml_video_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_OBJECT, mmi_jmms_uc_xml_object_element_start_handler},
    {MMI_JMMS_UC_XML_ELEMENT_NAME, NULL},
    {MMI_JMMS_UC_XML_ELEMENT_FILE_PATH, NULL},
};


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_alloc_buffer
 * DESCRIPTION
 *  Wrapper to jdd_MemAlloc
 * PARAMETERS
 *  buffer_size     [IN]        
 * RETURNS
 *  void *
 *****************************************************************************/
void *mmi_jmms_alloc_buffer(U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((void*)jdd_MemAlloc(1, buffer_size));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_buffer
 * DESCRIPTION
 *  Wrapper to jdd_MemFree
 * PARAMETERS
 *  buffer_p        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_buffer(void *buffer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemFree(buffer_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_convert_ascii_hex_to_dec
 * DESCRIPTION
 *  Converts Ascii value to Decimal value
 * PARAMETERS
 *  character       [IN]        
 * RETURNS
 *  U32 Decimal value.
 *****************************************************************************/
U32 mmi_jmms_uc_convert_ascii_hex_to_dec(U8 *character)
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
 *  mmi_jmms_uc_create_msg_req
 * DESCRIPTION
 *  To handle create msg req
 * PARAMETERS
 *  local_para      [IN]        
 *  result_hdlr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_create_msg_req(void *local_para, mmi_jmms_uc_xml_decoder_result_hdlr result_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    wap_mma_create_req_struct *msg_req = (wap_mma_create_req_struct*) local_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_req->more == 0)
    {
        g_jmms_context->decoder.parsing_error_code = ret_code;
        g_jmms_context->decoder.result_hdlr = result_hdlr;
        switch (msg_req->mode)
        {
            case MMA_MODE_EDIT:
            case MMA_MODE_REPLY:
            case MMA_MODE_REPLY_ALL:
                g_jmms_context->decoder.parsing_mode = JMMS_UC_XML_PARSING_MODE_EDIT;
                ret_code = mmi_jmms_uc_create_msg(msg_req->xml_filepath);
                break;
            case MMA_MODE_FORWARD:
            case MMA_MODE_SEND:
                g_jmms_context->decoder.parsing_mode = JMMS_UC_XML_PARSING_MODE_FORWARD;
                ret_code = mmi_jmms_uc_create_msg(msg_req->xml_filepath);
                break;
            default:
                ret_code = JC_ERR_INVALID_PARAMETER;
                break;

        }
        return ret_code;
    }
    else
    {
        mmi_jmms_uc_create_msg_rsp(ret_code, 0);
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_init_new_mms
 * DESCRIPTION
 *  Initiate the new MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_init_new_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    U8 config_arg = JMMS_CONFIG_PREVIEW;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_uc_init_new_mms");
    g_jmms_context->g_use_local_send_setings = 0;
    g_jmms_context->store_context->current_folder_name = E_JMMS_WRITE_MMS;

    mmi_jmms_init_msg_context_struct();
    mmi_jmms_fill_mms_sending_settings();
    if (g_jmms_context->compose_context == NULL)
    {
        g_jmms_context->compose_context =
            (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
        if (g_jmms_context->compose_context == NULL)
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }
    }
    if (g_jmms_context->msg_handle != NULL)
    {
        ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
    }
    if (ret_code == JC_OK)
    {
        g_jmms_context->msg_handle = NULL;
        ret_code = mmi_jmms_jdi_msg_init(&(g_jmms_context->msg_handle), (void*)config_arg);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_content_class(g_jmms_context->msg_handle, WAP_MMS_CONTENT_CLASS_VIDEO_RICH);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_creation_mode(g_jmms_context->msg_handle, E_CREATION_MODE_FREE);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_msg_type(g_jmms_context->msg_handle, E_TYPE_MMS);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_presentation_type(g_jmms_context->msg_handle, E_PRESENTATION_SMIL);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_msg_register_callback(
                    g_jmms_context->msg_handle,
                    E_CB_ERROR_IND,
                    (void*)mmi_jmms_error_ind_cb);
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_msg
 * DESCRIPTION
 *  Create the message
 * PARAMETERS
 *  file_path       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_create_msg(U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    int xml_parser_result = XML_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_create_msg: %s", file_path);
    g_jmms_context->decoder.xml_parser = jdd_MemAlloc(sizeof(XML_PARSER_STRUCT), 1);
    if (g_jmms_context->decoder.xml_parser == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto error;
    }

    xml_parser_result = xml_new_parser(g_jmms_context->decoder.xml_parser);
    xml_configure_memory(
        g_jmms_context->decoder.xml_parser,
        (XML_malloc_buffer_ptr) mmi_jmms_alloc_buffer,
        (XML_free_buffer_ptr) mmi_jmms_free_buffer);
    if (xml_parser_result != XML_RESULT_OK)
    {
        ret_code = -1;
        goto error;
    }

    xml_register_element_handler(
        g_jmms_context->decoder.xml_parser,
        mmi_jmms_uc_xml_start_element_hdlr,
        mmi_jmms_uc_xml_end_element_hdlr);

    xml_register_data_handler(g_jmms_context->decoder.xml_parser, mmi_jmms_uc_xml_data_hdlr);
    if (g_jmms_context->decoder.parsing_mode == JMMS_UC_XML_PARSING_MODE_EDIT)
    {
        ret_code = mmi_jmms_uc_init_new_mms();
        if (ret_code != JC_OK)
        {
            goto error;
        }
    }
    else
    {
        g_jmms_context->g_use_local_send_setings = 0;
        mmi_jmms_fill_mms_sending_settings();
    }
    xml_parser_result = xml_parse(g_jmms_context->decoder.xml_parser, file_path);

    if (xml_parser_result != XML_RESULT_OK)
    {
        ret_code = -1;
    }
    else
    {
        ret_code = g_jmms_context->decoder.parsing_error_code;
    }

  error:
    if (g_jmms_context->decoder.xml_parser)
    {
        xml_close_parser(g_jmms_context->decoder.xml_parser);
        jdd_MemFree(g_jmms_context->decoder.xml_parser);
    }
    g_jmms_context->decoder.xml_parser = NULL;
    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_start_element_hdlr
 * DESCRIPTION
 *  create list of start tag
 * PARAMETERS
 *  data        [IN]        
 *  el          [IN]        
 *  attr        [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 max_element = sizeof(g_jmms_uc_xml_tags_start_handler_map) / sizeof(g_jmms_uc_xml_tags_start_handler_map[0]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_start_element_hdlr");
    for (i = 0; i < max_element; i++)
    {
        if (!strcmp((S8*) g_jmms_uc_xml_tags_start_handler_map[i].xml_tag, el))
        {
            if (g_jmms_uc_xml_tags_start_handler_map[i].tag_handler)
            {
                g_jmms_uc_xml_tags_start_handler_map[i].tag_handler(attr);
            }
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_data_element_hdlr
 * DESCRIPTION
 *  Fill the data field value
 * PARAMETERS
 *  data        [IN]        
 *  el          [IN]        
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_data_element_hdlr(void *data, const char *el, const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 max_element = sizeof(g_jmms_uc_xml_tags_start_handler_map) / sizeof(g_jmms_uc_xml_tags_start_handler_map[0]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_data_element_hdlr: %s", el);
    for (i = 0; i < max_element; i++)
    {
        if (!strcmp((S8*) g_jmms_uc_xml_tags_start_handler_map[i].xml_tag, el))
        {
            if (g_jmms_uc_xml_tags_start_handler_map[i].tag_handler)
            {
                g_jmms_uc_xml_tags_start_handler_map[i].tag_handler(attr);
            }
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_end_element_hdlr
 * DESCRIPTION
 *  Function to operate on end tags
 * PARAMETERS
 *  data        [IN]        
 *  el          [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_end_element_hdlr(void *data, const char *el, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "mmi_jmms_uc_xml_end_element_hdlr: %d, g_jmms_context->decoder.parsing_state");
    switch (g_jmms_context->decoder.parsing_state)
    {
        case JMMS_UC_XML_ADD_TO_NUM:
        case JMMS_UC_XML_ADD_TO_EMAIL:
        case JMMS_UC_XML_ADD_CC_NUM:
        case JMMS_UC_XML_ADD_CC_EMAIL:
        case JMMS_UC_XML_ADD_BCC_NUM:
        case JMMS_UC_XML_ADD_BCC_EMAIL:
        case JMMS_UC_XML_ADD_FROM_NUM:
        case JMMS_UC_XML_ADD_FROM_EMAIL:
        case JMMS_UC_XML_ADD_SUBJECT:
        case JMMS_UC_XML_SET_RR:
        case JMMS_UC_XML_SET_DR:
        case JMMS_UC_XML_SET_PRIORITY:
        case JMMS_UC_XML_SET_EXPIRY:
        case JMMS_UC_XML_SET_DELIVERY:
        case JMMS_UC_XML_SET_VISIBLE:
            g_jmms_context->decoder.parsing_state = JMMS_UC_XML_NO_ACTIVE_TAG;
            break;
        case JMMS_UC_XML_ADD_SLIDE:
            g_jmms_context->decoder.parsing_state = JMMS_UC_XML_NO_ACTIVE_TAG;
            g_jmms_context->decoder.current_object = NULL;
            break;
        case JMMS_UC_XML_ADD_OBJECT:
            if (!strcmp(MMI_JMMS_UC_XML_ELEMENT_OBJECT, el))
            {
                mmi_jmms_uc_xml_object_element_end_handler();
                g_jmms_context->decoder.parsing_state = JMMS_UC_XML_NO_ACTIVE_TAG;
                g_jmms_context->decoder.current_object = NULL;
            }
            break;
        default:
            if (!strcmp(MMI_JMMS_UC_XML_ELEMENT_HEADER, el))
            {
                mmi_jmms_uc_xml_header_element_end_handler();
            }
            if (!strcmp(MMI_JMMS_UC_XML_ELEMENT_MMS, el))
            {
                mmi_jmms_uc_xml_mms_element_end_handler();
            }
            break;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_data_hdlr
 * DESCRIPTION
 *  Function to choose between different tags
 * PARAMETERS
 *  data        [IN]        
 *  el          [IN]        
 *  value       [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_data_hdlr: %d %s",
                         g_jmms_context->decoder.parsing_state, el);
    switch (g_jmms_context->decoder.parsing_state)
    {
        case JMMS_UC_XML_ADD_TO_NUM:
        case JMMS_UC_XML_ADD_TO_EMAIL:
        case JMMS_UC_XML_ADD_CC_NUM:
        case JMMS_UC_XML_ADD_CC_EMAIL:
        case JMMS_UC_XML_ADD_BCC_NUM:
        case JMMS_UC_XML_ADD_BCC_EMAIL:
            mmi_jmms_uc_xml_address_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_ADD_FROM_NUM:
        case JMMS_UC_XML_ADD_FROM_EMAIL:
            mmi_jmms_uc_xml_from_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_ADD_SUBJECT:
            mmi_jmms_uc_xml_subject_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_SET_RR:
            mmi_jmms_uc_xml_rr_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_SET_DR:
            mmi_jmms_uc_xml_dr_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_SET_PRIORITY:
            mmi_jmms_uc_xml_prio_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_SET_EXPIRY:
            mmi_jmms_uc_xml_expiry_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_SET_DELIVERY:
            mmi_jmms_uc_xml_delivery_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_SET_VISIBLE:
            mmi_jmms_uc_xml_visible_element_data_handler(value, len);
            break;
        case JMMS_UC_XML_ADD_OBJECT:
            if (!strcmp(MMI_JMMS_UC_XML_ELEMENT_NAME, el))
            {
                mmi_jmms_uc_xml_name_element_data_handler(value, len);
            }
            else if (!strcmp(MMI_JMMS_UC_XML_ELEMENT_FILE_PATH, el))
            {
                mmi_jmms_uc_xml_filepath_element_data_handler(value, len);
            }
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_to_element_start_handler
 * DESCRIPTION
 *  to tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_to_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_to_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_TO_NUM;
    g_jmms_context->address_list_flag = E_TO_ADDRESSES;

    if (!strcmp(MMI_JMMS_UC_XML_ATTR_TYPE, attr[0]))
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_EMAIL_ADDR, attr[1]))
        {
            g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_TO_EMAIL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_cc_element_start_handler
 * DESCRIPTION
 *  cc tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_cc_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_cc_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_CC_NUM;
    g_jmms_context->address_list_flag = E_CC_ADDRESSES;
    if (!strcmp(MMI_JMMS_UC_XML_ATTR_TYPE, attr[0]))
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_EMAIL_ADDR, attr[1]))
        {
            g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_CC_EMAIL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_bcc_element_start_handler
 * DESCRIPTION
 *  bcc tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_bcc_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_bcc_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_BCC_NUM;
    g_jmms_context->address_list_flag = E_BCC_ADDRESSES;

    if (!strcmp(MMI_JMMS_UC_XML_ATTR_TYPE, attr[0]))
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_EMAIL_ADDR, attr[1]))
        {
            g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_BCC_EMAIL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_from_element_start_handler
 * DESCRIPTION
 *  from tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_from_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_from_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_FROM_NUM;
    if (!strcmp(MMI_JMMS_UC_XML_ATTR_TYPE, attr[0]))
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_EMAIL_ADDR, attr[1]))
        {
            g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_FROM_EMAIL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_address_element_data_handler
 * DESCRIPTION
 *  address tag data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_address_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ucs2;
    U32 ucs2_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_address_element_data_handler");
    ucs2_len = (len + 1) * ENCODING_LENGTH;
    ucs2 = jdd_MemAlloc(ucs2_len, 1);
    if (ucs2 == NULL)
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, 0, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    memset(ucs2, 0, ucs2_len);
    mmi_chset_utf8_to_ucs2_string(ucs2, ucs2_len, (kal_uint8*) value);
    if (mmi_jmms_add_address_in_addresse_list((S8*) ucs2) != JC_OK)
    {
        jdd_MemFree(ucs2);
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, 1, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    jdd_MemFree(ucs2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_from_element_data_handler
 * DESCRIPTION
 *  from tag data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_from_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ucs2;
    U32 ucs2_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_from_element_data_handler");
    ucs2_len = (len + 1) * ENCODING_LENGTH;
    ucs2 = jdd_MemAlloc(ucs2_len, 1);
    if (ucs2 == NULL)
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, 0, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    memset(ucs2, 0, ucs2_len);
    mmi_chset_utf8_to_ucs2_string(ucs2, ucs2_len, (kal_uint8*) value);
    if (mmi_jmms_add_from_address_in_addresse_list((S8*) ucs2) != JC_OK)
    {
        jdd_MemFree(ucs2);
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, 1, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    jdd_MemFree(ucs2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_subject_element_start_handler
 * DESCRIPTION
 *  subject tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_subject_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_subject_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_SUBJECT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_data_base64_to_ucs2
 * DESCRIPTION
 *  Add data from base 64 to usc2
 * PARAMETERS
 *  base64_data_p       [IN]         
 *  base64_length       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_create_xml_data_base64_to_ucs2(U8 *base64_data_p, U32 base64_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *utf8_data_p = NULL;
    U32 utf8_data_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_data_len = applib_base64_decode_len((S8*) base64_data_p, base64_length);
    utf8_data_p = (U8*) jdd_MemAlloc(utf8_data_len + 1, 1);
    memset(utf8_data_p, 0, utf8_data_len + 1);

    applib_base64_decode((S8*) base64_data_p, base64_length, (S8*) utf8_data_p, utf8_data_len);

    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*) g_jmms_context->subject_input_buffer,
        (MMI_UC_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH,
        (kal_uint8*) utf8_data_p);

    jdd_MemFree(utf8_data_p);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_subject_element_data_handler
 * DESCRIPTION
 *  subject tag data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_subject_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_subject_element_data_handler");
    memset(g_jmms_context->subject_input_buffer, 0, ENCODING_LENGTH);
    mmi_jmms_uc_create_xml_data_base64_to_ucs2((kal_uint8*) value, (U32) len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_rr_element_start_handler
 * DESCRIPTION
 *  rr tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_rr_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_rr_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_SET_RR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_rr_element_data_handler
 * DESCRIPTION
 *  rr tag data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_rr_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 converted_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    converted_val = atoi((S8*) value);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_rr_element_data_handler: %d", converted_val);
    if (converted_val)
    {
        g_jmms_context->sending_settings.read_report = MMI_TRUE;
    }
    else
    {
        g_jmms_context->sending_settings.read_report = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_dr_element_start_handler
 * DESCRIPTION
 *  dr tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_dr_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_dr_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_SET_DR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_dr_element_data_handler
 * DESCRIPTION
 *  dr tag data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_dr_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 converted_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    converted_val = atoi((S8*) value);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_dr_element_data_handler: %d", converted_val);
    if (converted_val)
    {
        g_jmms_context->sending_settings.delivery_report = MMI_TRUE;
    }
    else
    {
        g_jmms_context->sending_settings.delivery_report = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_prio_element_start_handler
 * DESCRIPTION
 *  prio tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_prio_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_prio_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_SET_PRIORITY;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_prio_element_data_handler
 * DESCRIPTION
 *  prio tag data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_prio_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 converted_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    converted_val = atoi((S8*) value);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_prio_element_data_handler: %d", converted_val);
    switch (converted_val)
    {
        case MMA_PRIORITY_LOW:
            g_jmms_context->sending_settings.priority = E_MSG_PRIORITY_LOW;
            break;
        case MMA_PRIORITY_HIGH:
            g_jmms_context->sending_settings.priority = E_MSG_PRIORITY_HIGH;
            break;
        default:
            g_jmms_context->sending_settings.priority = E_MSG_PRIORITY_NORMAL;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_expiry_element_start_handler
 * DESCRIPTION
 *  expiry tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_expiry_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_expiry_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_SET_EXPIRY;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_expiry_element_data_handler
 * DESCRIPTION
 *  expiry data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_expiry_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 converted_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    converted_val = atoi((S8*) value);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_expiry_element_data_handler: %d", converted_val);
    switch (converted_val)
    {
        case MMA_EXPIRY_1_HOUR:
            g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_1HR;
            break;
        case MMA_EXPIRY_12_HOURS:
            g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_12HRS;
            break;
        case MMA_EXPIRY_1_DAY:
            g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_1DAY;
            break;
        case MMA_EXPIRY_1_WEEK:
            g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_1WEEK;
            break;
        default:
            g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_MAX;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_delivery_element_start_handler
 * DESCRIPTION
 *  delivery tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_delivery_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_delivery_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_SET_DELIVERY;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_delivery_element_data_handler
 * DESCRIPTION
 *  delivery data value handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_delivery_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 converted_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    converted_val = atoi((S8*) value);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_delivery_element_data_handler: %d", converted_val);
    switch (converted_val)
    {
        case MMA_DELIVERY_1_HOUR:
            g_jmms_context->sending_settings.delivery_time = E_1_HR;
            break;
        case MMA_DELIVERY_12_HOURS:
            g_jmms_context->sending_settings.delivery_time = E_12_HRS;
            break;
        case MMA_DELIVERY_24_HOURS:
            g_jmms_context->sending_settings.delivery_time = E_24_HRS;
            break;
        default:
            g_jmms_context->sending_settings.delivery_time = E_IMMEDIATE;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_visible_element_start_handler
 * DESCRIPTION
 *  Set the visible state
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_visible_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_visible_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_SET_VISIBLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_visible_element_data_handler
 * DESCRIPTION
 *  hide sender filed value handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_visible_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 converted_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    converted_val = atoi((S8*) value);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_visible_element_data_handler: %d", converted_val);
    if (!converted_val)
    {
        g_jmms_context->sending_settings.hide_sender = MMI_TRUE;
    }
    else
    {
        g_jmms_context->sending_settings.hide_sender = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_header_element_end_handler
 * DESCRIPTION
 *  Header tag end handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_header_element_end_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_header_element_end_handler");
    ret_code = mmi_jmms_create_and_send_new_mms(E_USE_LOCAL_SETTINGS, g_jmms_context, FALSE);
    if (ret_code != JC_OK)
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(ret_code);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    if (g_jmms_context->decoder.parsing_mode == JMMS_UC_XML_PARSING_MODE_FORWARD)
    {
        MEDIA_INFO *media_info_p = NULL;

        xml_stop_parse(g_jmms_context->decoder.xml_parser);
        ret_code = mmi_jmms_jdi_get_media_list(
                    g_jmms_context->msg_handle,
                    0,
                    &media_info_p,
                    &(g_jmms_context->num_attachments),
                    E_TRUE);
        if (ret_code != JC_OK)
        {
            mmi_jmms_uc_xml_parsing_error(ret_code);
            return;
        }
        mmi_jmms_uc_xml_mms_element_end_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_body_element_start_handler
 * DESCRIPTION
 *  MMS body tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_body_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 converted_val;
    S32 i;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_body_element_start_handler");
    for (i = 0; attr[i]; i = i + 2)
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_BGCOLOR, attr[i]))
        {
            g_jmms_context->compose_context->mms_bg_color = mmi_jmms_uc_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            g_jmms_context->compose_context->mms_bg_color =
                ((0x00FFFFFF & g_jmms_context->compose_context->mms_bg_color) << 8) | 0x00000064;
            ret_code = mmi_jmms_set_bg_color_no_error_handling(g_jmms_context->compose_context->mms_bg_color);
            if (ret_code != JC_OK)
            {
            #ifndef __PRODUCTION_RELEASE__
                EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
            #else /* __PRODUCTION_RELEASE__ */ 
                mmi_jmms_uc_xml_parsing_error(ret_code);
                return;
            #endif /* __PRODUCTION_RELEASE__ */ 
            }

        }
        /*
         * else if (!strcmp(MMI_JMMS_UC_XML_ATTR_FGCOLOR , attr[i]))
         * {
         * 
         * }
         */
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_SLIDE_NUM, attr[i]))
        {
            mmi_jmms_jdi_set_max_pages(g_jmms_context->msg_handle, (U8) atoi((S8*) attr[i + 1]));
            if (ret_code != JC_OK)
            {
            #ifndef __PRODUCTION_RELEASE__
                EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
            #else /* __PRODUCTION_RELEASE__ */ 
                mmi_jmms_uc_xml_parsing_error(ret_code);
                return;
            #endif /* __PRODUCTION_RELEASE__ */ 
            }
        }
        /*
         * else if (!strcmp(MMI_JMMS_UC_XML_ATTR_OBJ_NUM , attr[i]))
         * {
         * }
         */
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_LAYOUT, attr[i]))
        {
            converted_val = atoi((S8*) attr[i + 1]);
            if (converted_val == MMA_LAYOUT_IMAGE_ON_TOP)
            {
                ret_code = mmi_jmms_set_potrait_region_list(1);
            }
            else
            {
                ret_code = mmi_jmms_set_potrait_region_list(0);
            }
            if (ret_code != JC_OK)
            {
            #ifndef __PRODUCTION_RELEASE__
                EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
            #else /* __PRODUCTION_RELEASE__ */ 
                mmi_jmms_uc_xml_parsing_error(ret_code);
                return;
            #endif /* __PRODUCTION_RELEASE__ */ 
            }
        }
    }
    g_jmms_context->compose_context->curr_page_index = 0;
    g_jmms_context->num_attachments = 0;
    g_jmms_context->decoder.current_object_count = 0;
    g_jmms_context->decoder.objects = NULL;
    g_jmms_context->decoder.current_object = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_slide_element_start_handler
 * DESCRIPTION
 *  Slide tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_slide_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_slide_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_SLIDE;
    for (i = 0; attr[i]; i = i + 2)
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_JMMS_UC_XML_ATTR_INDEX, attr[i]))
            {
                g_jmms_context->decoder.current_slide_count = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_JMMS_UC_XML_ATTR_DURATION, attr[i]))
            {
                ret_code = mmi_jmms_compose_insert_new_slide(atoi((S8*) attr[i + 1]));
                if (ret_code != JC_OK)
                {
                #ifndef __PRODUCTION_RELEASE__
                    EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
                #else /* __PRODUCTION_RELEASE__ */ 
                    mmi_jmms_uc_xml_parsing_error(ret_code);
                    return;
                #endif /* __PRODUCTION_RELEASE__ */ 
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_insert_object_in_object_list
 * DESCRIPTION
 *  insert the object to the object list
 * PARAMETERS
 *  insert_object       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_insert_object_in_object_list(mmi_jmms_uc_xml_object_info_struct *insert_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_uc_xml_object_info_struct *object = g_jmms_context->decoder.objects;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_insert_object_in_object_list");
    insert_object->next = NULL;
    insert_object->prev = NULL;
    if (object == NULL)
    {
        g_jmms_context->decoder.objects = insert_object;
        return;
    }
    while (object->next && object->id < insert_object->id)
    {
        object = object->next;
    }
    if (object->id < insert_object->id)
    {
        insert_object->next = object->next;
        if (insert_object->next)
        {
            insert_object->next->prev = insert_object;
        }
        object->next = insert_object;
        insert_object->prev = object;
    }
    else
    {
        insert_object->prev = object->prev;
        if (insert_object->prev)
        {
            insert_object->prev->next = insert_object;
        }
        object->prev = insert_object;
        insert_object->next = object;
    }
    if (insert_object->prev == NULL)
    {
        g_jmms_context->decoder.objects = insert_object;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_remove_object_in_object_list
 * DESCRIPTION
 *  remove object in object list
 * PARAMETERS
 *  remove_object       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_remove_object_in_object_list(mmi_jmms_uc_xml_object_info_struct *remove_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_remove_object_in_object_list");
    if (NULL == remove_object)
    {
        return;
    }
    if (remove_object->next)
    {
        remove_object->next->prev = remove_object->prev;
    }
    if (remove_object->prev)
    {
        remove_object->prev->next = remove_object->next;
    }
    if (remove_object->prev == NULL)
    {
        g_jmms_context->decoder.objects = remove_object->next;
    }
    if (remove_object->slide_num)
    {
        jdd_MemFree(remove_object->slide_num);
    }
    if (remove_object->begin)
    {
        jdd_MemFree(remove_object->begin);
    }
    if (remove_object->end)
    {
        jdd_MemFree(remove_object->end);
    }
    if (remove_object->file_name)
    {
        jdd_MemFree(remove_object->file_name);
    }
    if (remove_object->file_path)
    {
        jdd_MemFree(remove_object->file_path);
    }
    jdd_MemFree(remove_object);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_free_object_list
 * DESCRIPTION
 *  Free object list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_free_object_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_free_object_list");
    while (g_jmms_context->decoder.objects)
    {
        mmi_jmms_uc_xml_remove_object_in_object_list(g_jmms_context->decoder.objects);
    }
    if (g_jmms_context->compose_context)
    {
        g_jmms_context->compose_context->curr_page_index = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_find_object_in_object_list
 * DESCRIPTION
 *  Search for the object in list and return the location
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_jmms_uc_xml_object_info_struct *mmi_jmms_uc_xml_find_object_in_object_list(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_uc_xml_object_info_struct *object = g_jmms_context->decoder.objects;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_find_object_in_object_list");
    if (object == NULL)
    {
        return NULL;
    }
    while (object)
    {
        if (object->id == id)
        {
            return object;
        }
        object = object->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_allocate_object_for_object_list
 * DESCRIPTION
 *  alloc memory to object node
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_jmms_uc_xml_object_info_struct *mmi_jmms_uc_xml_allocate_object_for_object_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_jmms_uc_xml_object_info_struct *node;
    S32 node_size = (sizeof(U8)) * MMI_JMMS_UC_MAX_MMS_SLIDE_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (mmi_jmms_uc_xml_object_info_struct*) jdd_MemAlloc(sizeof(mmi_jmms_uc_xml_object_info_struct), 1);
    if (node != NULL)
    {
        node->slide_num = (PU8) jdd_MemAlloc(node_size, 1);
        if (node->slide_num == NULL)
        {
            goto error;
        }
        node->begin = (PU8) jdd_MemAlloc(node_size, 1);
        if (node->begin == NULL)
        {
            goto error;
        }
        node->end = (PU8) jdd_MemAlloc(node_size, 1);
        if (node->end == NULL)
        {
            goto error;
        }
        return node;
    }
  error:
    if (node)
    {
        if (node->slide_num)
        {
            jdd_MemFree(node->slide_num);
        }
        if (node->begin)
        {
            jdd_MemFree(node->begin);
        }
        if (node->end)
        {
            jdd_MemFree(node->begin);
        }
        jdd_MemFree(node);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_text_element_start_handler
 * DESCRIPTION
 *  text tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_text_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 bg_color = 0;
    U32 fg_color = 0;
    U32 id = 0;
    U32 begin = 0;
    U32 end = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_text_element_start_handler");
    for (i = 0; attr[i]; i = i + 2)
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_ID, attr[i]))
        {
            id = (atoi((S8*) attr[i + 1]));
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_BEGIN, attr[i]))
        {
            begin = atoi((S8*) attr[i + 1]);
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_END, attr[i]))
        {
            end = atoi((S8*) attr[i + 1]);
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_BGCOLOR, attr[i]))
        {
            bg_color = mmi_jmms_uc_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_FGCOLOR, attr[i]))
        {
            fg_color = mmi_jmms_uc_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
        }
    }
    g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_find_object_in_object_list(id);
    if (g_jmms_context->decoder.current_object == NULL)
    {
        g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_allocate_object_for_object_list();
        if (g_jmms_context->decoder.current_object == NULL)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, 0, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
    g_jmms_context->decoder.current_object->id = id;
    g_jmms_context->decoder.current_object->slide_num[g_jmms_context->decoder.current_object->total_slides] =
        g_jmms_context->decoder.current_slide_count;
    g_jmms_context->decoder.current_object->begin[g_jmms_context->decoder.current_object->total_slides] = begin;
    g_jmms_context->decoder.current_object->end[g_jmms_context->decoder.current_object->total_slides] = end;
    g_jmms_context->decoder.current_object->object.text.bg_color = bg_color;
    g_jmms_context->decoder.current_object->object.text.fg_color = fg_color;
    g_jmms_context->decoder.current_object->type = JMMS_UC_XML_OBJECT_TYPE_TEXT;
    g_jmms_context->decoder.current_object->total_slides++;
    if (g_jmms_context->decoder.current_object->total_slides == 1)
    {
        mmi_jmms_uc_xml_insert_object_in_object_list(g_jmms_context->decoder.current_object);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_image_element_start_handler
 * DESCRIPTION
 *  image tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_image_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 id = 0;
    U32 begin = 0;
    U32 end = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_image_element_start_handler");
    for (i = 0; attr[i]; i = i + 2)
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_ID, attr[i]))
        {
            id = (atoi((S8*) attr[i + 1]));
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_BEGIN, attr[i]))
        {
            begin = atoi((S8*) attr[i + 1]);
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_END, attr[i]))
        {
            end = atoi((S8*) attr[i + 1]);
        }
    }
    g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_find_object_in_object_list(id);
    if (g_jmms_context->decoder.current_object == NULL)
    {
        g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_allocate_object_for_object_list();
        if (g_jmms_context->decoder.current_object == NULL)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, 0, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
    g_jmms_context->decoder.current_object->id = id;
    g_jmms_context->decoder.current_object->slide_num[g_jmms_context->decoder.current_object->total_slides] =
        g_jmms_context->decoder.current_slide_count;
    g_jmms_context->decoder.current_object->begin[g_jmms_context->decoder.current_object->total_slides] = begin;
    g_jmms_context->decoder.current_object->end[g_jmms_context->decoder.current_object->total_slides] = end;
    g_jmms_context->decoder.current_object->type = JMMS_UC_XML_OBJECT_TYPE_IMAGE;
    g_jmms_context->decoder.current_object->total_slides++;
    if (g_jmms_context->decoder.current_object->total_slides == 1)
    {
        mmi_jmms_uc_xml_insert_object_in_object_list(g_jmms_context->decoder.current_object);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_audio_element_start_handler
 * DESCRIPTION
 *  audio tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_audio_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 id = 0;
    U32 begin = 0;
    U32 end = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_audio_element_start_handler");
    for (i = 0; attr[i]; i = i + 2)
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_ID, attr[i]))
        {
            id = (atoi((S8*) attr[i + 1]));
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_BEGIN, attr[i]))
        {
            begin = atoi((S8*) attr[i + 1]);
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_END, attr[i]))
        {
            end = atoi((S8*) attr[i + 1]);
        }
    }
    g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_find_object_in_object_list(id);
    if (g_jmms_context->decoder.current_object == NULL)
    {
        g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_allocate_object_for_object_list();
        if (g_jmms_context->decoder.current_object == NULL)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, 0, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
    g_jmms_context->decoder.current_object->id = id;
    g_jmms_context->decoder.current_object->slide_num[g_jmms_context->decoder.current_object->total_slides] =
        g_jmms_context->decoder.current_slide_count;
    g_jmms_context->decoder.current_object->begin[g_jmms_context->decoder.current_object->total_slides] = begin;
    g_jmms_context->decoder.current_object->end[g_jmms_context->decoder.current_object->total_slides] = end;
    g_jmms_context->decoder.current_object->type = JMMS_UC_XML_OBJECT_TYPE_AUDIO;
    g_jmms_context->decoder.current_object->total_slides++;
    if (g_jmms_context->decoder.current_object->total_slides == 1)
    {
        mmi_jmms_uc_xml_insert_object_in_object_list(g_jmms_context->decoder.current_object);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_video_element_start_handler
 * DESCRIPTION
 *  video object tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_video_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 id = 0;
    U32 begin = 0;
    U32 end = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_video_element_start_handler");
    for (i = 0; attr[i]; i = i + 2)
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_ID, attr[i]))
        {
            id = (atoi((S8*) attr[i + 1]));
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_BEGIN, attr[i]))
        {
            begin = atoi((S8*) attr[i + 1]);
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_END, attr[i]))
        {
            end = atoi((S8*) attr[i + 1]);
        }
    }
    g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_find_object_in_object_list(id);
    if (g_jmms_context->decoder.current_object == NULL)
    {
        g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_allocate_object_for_object_list();
        if (g_jmms_context->decoder.current_object == NULL)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, 0, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
    g_jmms_context->decoder.current_object->id = id;
    g_jmms_context->decoder.current_object->slide_num[g_jmms_context->decoder.current_object->total_slides] =
        g_jmms_context->decoder.current_slide_count;
    g_jmms_context->decoder.current_object->begin[g_jmms_context->decoder.current_object->total_slides] = begin;
    g_jmms_context->decoder.current_object->end[g_jmms_context->decoder.current_object->total_slides] = end;
    g_jmms_context->decoder.current_object->type = JMMS_UC_XML_OBJECT_TYPE_VIDEO;
    g_jmms_context->decoder.current_object->total_slides++;
    if (g_jmms_context->decoder.current_object->total_slides == 1)
    {
        mmi_jmms_uc_xml_insert_object_in_object_list(g_jmms_context->decoder.current_object);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_object_element_start_handler
 * DESCRIPTION
 *  object tag start handler
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_object_element_start_handler(const char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 id = 0;
    U32 attach = 0;
    U32 vf = 0;
    U32 drm = 0;
    U32 size = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_object_element_start_handler");
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_ADD_OBJECT;
    for (i = 0; attr[i]; i = i + 2)
    {
        if (!strcmp(MMI_JMMS_UC_XML_ATTR_ID, attr[i]))
        {
            id = atoi((S8*) attr[i + 1]);
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_ATTACH, attr[i]))
        {
            if (atoi((S8*) attr[i + 1]))
            {
                attach = 1;
            }
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_VIRTUAL_FILE, attr[i]))
        {
            if (atoi((S8*) attr[i + 1]))
            {
                vf = MMI_TRUE;
            }
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_DRM, attr[i]))
        {
            if (atoi((S8*) attr[i + 1]))
            {
                drm = (atoi((S8*) attr[i + 1]));
            }
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_SIZE, attr[i]))
        {
            if (atoi((S8*) attr[i + 1]))
            {
                size = (atoi((S8*) attr[i + 1]));
            }
        }
        else if (!strcmp(MMI_JMMS_UC_XML_ATTR_OFFSET, attr[i]))
        {
            if (atoi((S8*) attr[i + 1]))
            {
                offset = (atoi((S8*) attr[i + 1]));
            }
        }
    }
    if (attach)
    {
        g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_allocate_object_for_object_list();
        if (g_jmms_context->decoder.current_object == NULL)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, 0, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
        g_jmms_context->decoder.current_object->type = JMMS_UC_XML_OBJECT_TYPE_ATTACHMENT;
        g_jmms_context->decoder.current_object->slide_num[g_jmms_context->decoder.current_object->total_slides] = 0;
        g_jmms_context->decoder.current_object->total_slides++;
        g_jmms_context->decoder.current_object->id = id;
        mmi_jmms_uc_xml_insert_object_in_object_list(g_jmms_context->decoder.current_object);
    }
    else
    {
        g_jmms_context->decoder.current_object = mmi_jmms_uc_xml_find_object_in_object_list(id);
    }
    g_jmms_context->decoder.current_object->vf = vf;
    switch (drm)
    {
        case MMA_DRM_FL_CD:
            g_jmms_context->decoder.current_object->drm = E_DRM_FWD_LOCK;
            break;
        case MMA_DRM_SD:
        case MMA_DRM_SD_NO_RIGHT:
            g_jmms_context->decoder.current_object->drm = E_DRM_SEPARATE_DELIVERY;
            break;
        default:
            g_jmms_context->decoder.current_object->drm = E_DRM_NONE;
            break;
    }
    g_jmms_context->decoder.current_object->size = size;
    g_jmms_context->decoder.current_object->offset = offset;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_add_text
 * DESCRIPTION
 *  text object data handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_add_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute text_font;
    JDD_FILE fh;
    S32 read_bytes;
    U8 *temp_utf8_buffer;
    S32 max_size = (JMMS_COMPOSE_TEXT_LENGTH + 1) * ENCODING_LENGTH;
    JC_RETCODE ret_code = JC_OK;
    U32 media_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_add_text");
    text_font.italic = 0;
    text_font.bold = 0;
    text_font.size = MEDIUM_FONT;
    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        ret_code = jdd_FSInitialize(&g_jmms_context->jmms_fs_handle);
        if (ret_code != JC_OK)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(ret_code);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
    fh = jdd_FSOpen(
            g_jmms_context->jmms_fs_handle,
            (U16*) g_jmms_context->decoder.current_object->file_path,
            E_OPEN_READ_MODE);
    if (fh == NULL)
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, 0, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(JC_ERR_FILE_OPEN);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    temp_utf8_buffer = jdd_MemAlloc(max_size, 1);
    if (temp_utf8_buffer == NULL)
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, 0, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    ret_code = jdd_FSSeek(fh, g_jmms_context->decoder.current_object->offset, E_FILE_SEEK_SET);
    if (ret_code != JC_OK)
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(ret_code);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    read_bytes = jdd_FSRead(temp_utf8_buffer, sizeof(JC_INT8), max_size, fh);
    mmi_chset_utf8_to_ucs2_string(
        g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
        max_size,
        temp_utf8_buffer);
    jdd_MemFree(temp_utf8_buffer);
    for (i = 0; i < g_jmms_context->decoder.current_object->total_slides; i++)
    {
        ret_code = (JC_RETCODE) mmi_jmms_compose_add_text_media(
                                    (U8) (g_jmms_context->decoder.current_object->slide_num[i]),
                                    &(text_font),
                                    (((0x00FFFFFF & g_jmms_context->decoder.current_object->object.text.fg_color) << 8) | 0x00000064),
                                    0,
                                    &media_id);
        if (ret_code == JC_OK)
        {
            ret_code = mmi_jmms_set_media_time_no_error_handling(
                        g_jmms_context->decoder.current_object->begin[i],
                        g_jmms_context->decoder.current_object->begin[i] - g_jmms_context->decoder.current_object->end[i],
                        media_id,
                        (U8) g_jmms_context->decoder.current_object->slide_num[i]);
            if (ret_code != JC_OK)
            {
            #ifndef __PRODUCTION_RELEASE__
                EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
            #else /* __PRODUCTION_RELEASE__ */ 
                mmi_jmms_uc_xml_parsing_error(ret_code);
                return;
            #endif /* __PRODUCTION_RELEASE__ */ 
            }
        }
        else
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(ret_code);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
    if (fh != NULL)
    {
        jdd_FSClose(fh);
        fh = NULL;
    }
    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        ret_code = jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
        if (ret_code != JC_OK)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(ret_code);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_add_audio
 * DESCRIPTION
 *  object audio tag data handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_add_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U32 media_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_add_audio");
    for (i = 0; i < g_jmms_context->decoder.current_object->total_slides; i++)
    {
        ret_code = mmi_jmms_compose_add_media_as_file_offset(
                    (JC_CHAR*) g_jmms_context->decoder.current_object->file_path,
                    g_jmms_context->decoder.current_object->offset,
                    (JC_CHAR*) g_jmms_context->decoder.current_object->file_name,
                    E_MEDIA_AUDIO,
                    0,
                    (U8) g_jmms_context->decoder.current_object->slide_num[i],
                    g_jmms_context->decoder.current_object->size,
                    g_jmms_context->decoder.current_object->drm,
                    &media_id);
        if (ret_code == JC_OK)
        {
            ret_code = mmi_jmms_set_media_time_no_error_handling(
                        g_jmms_context->decoder.current_object->begin[i],
                        g_jmms_context->decoder.current_object->begin[i] - g_jmms_context->decoder.current_object->end[i],
                        media_id,
                        (U8) g_jmms_context->decoder.current_object->slide_num[i]);
            if (ret_code != JC_OK)
            {
            #ifndef __PRODUCTION_RELEASE__
                EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
            #else /* __PRODUCTION_RELEASE__ */ 
                mmi_jmms_uc_xml_parsing_error(ret_code);
                return;
            #endif /* __PRODUCTION_RELEASE__ */ 
            }
        }
        else if (JC_ERR_MSG_EMPTY_FILE == ret_code)
        {
            mmi_jmms_uc_xml_parsing_error(ret_code);
            g_jmms_context->decoder.current_object = NULL;
            return;
        }
        else
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(ret_code);
            g_jmms_context->decoder.current_object = NULL;
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_add_video
 * DESCRIPTION
 *  object video tag handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_add_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U32 media_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_add_video");
    for (i = 0; i < g_jmms_context->decoder.current_object->total_slides; i++)
    {
        ret_code = mmi_jmms_compose_add_media_as_file_offset(
                    (JC_CHAR*) g_jmms_context->decoder.current_object->file_path,
                    g_jmms_context->decoder.current_object->offset,
                    (JC_CHAR*) g_jmms_context->decoder.current_object->file_name,
                    E_MEDIA_VIDEO,
                    0,
                    (U8) g_jmms_context->decoder.current_object->slide_num[i],
                    g_jmms_context->decoder.current_object->size,
                    g_jmms_context->decoder.current_object->drm,
                    &media_id);
        if (ret_code == JC_OK)
        {
            ret_code = mmi_jmms_set_media_time_no_error_handling(
                        g_jmms_context->decoder.current_object->begin[i],
                        g_jmms_context->decoder.current_object->begin[i] - g_jmms_context->decoder.current_object->end[i],
                        media_id,
                        (U8) g_jmms_context->decoder.current_object->slide_num[i]);
            if (ret_code != JC_OK)
            {
            #ifndef __PRODUCTION_RELEASE__
                EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
            #else /* __PRODUCTION_RELEASE__ */ 
                mmi_jmms_uc_xml_parsing_error(ret_code);
                return;
            #endif /* __PRODUCTION_RELEASE__ */ 
            }
        }
        else if (JC_ERR_MSG_EMPTY_FILE == ret_code)
        {
            mmi_jmms_uc_xml_parsing_error(ret_code);
            g_jmms_context->decoder.current_object = NULL;
            return;
        }
        else
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(ret_code);
            g_jmms_context->decoder.current_object = NULL;
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_add_image
 * DESCRIPTION
 *  object image tag handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_add_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U32 media_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_add_image");
    for (i = 0; i < g_jmms_context->decoder.current_object->total_slides; i++)
    {
        ret_code = mmi_jmms_compose_add_media_as_file_offset(
                    (JC_CHAR*) g_jmms_context->decoder.current_object->file_path,
                    g_jmms_context->decoder.current_object->offset,
                    (JC_CHAR*) g_jmms_context->decoder.current_object->file_name,
                    E_MEDIA_IMAGE,
                    0,
                    (U8) g_jmms_context->decoder.current_object->slide_num[i],
                    g_jmms_context->decoder.current_object->size,
                    g_jmms_context->decoder.current_object->drm,
                    &media_id);
        if (ret_code == JC_OK)
        {
            ret_code = mmi_jmms_set_media_time_no_error_handling(
                        g_jmms_context->decoder.current_object->begin[i],
                        g_jmms_context->decoder.current_object->begin[i] - g_jmms_context->decoder.current_object->end[i],
                        media_id,
                        (U8) g_jmms_context->decoder.current_object->slide_num[i]);
            if (ret_code != JC_OK)
            {
            #ifndef __PRODUCTION_RELEASE__
                EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
            #else /* __PRODUCTION_RELEASE__ */ 
                mmi_jmms_uc_xml_parsing_error(ret_code);
                return;
            #endif /* __PRODUCTION_RELEASE__ */ 
            }
        }
        else if (JC_ERR_MSG_EMPTY_FILE == ret_code)
        {
            mmi_jmms_uc_xml_parsing_error(ret_code);
            g_jmms_context->decoder.current_object = NULL;
            return;
        }
        else
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(ret_code);
            g_jmms_context->decoder.current_object = NULL;
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_add_attachment
 * DESCRIPTION
 *  object attachment tag handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_add_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U32 media_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_add_attachment");
    ret_code = mmi_jmms_compose_add_media_as_file_offset(
                (JC_CHAR*) g_jmms_context->decoder.current_object->file_path,
                g_jmms_context->decoder.current_object->offset,
                (JC_CHAR*) g_jmms_context->decoder.current_object->file_name,
                E_MEDIA_OTHERS,
                1,
                0,
                g_jmms_context->decoder.current_object->size,
                g_jmms_context->decoder.current_object->drm,
                &media_id);
    if (ret_code == JC_OK)
    {
        g_jmms_context->num_attachments++;
    }
    else if (JC_ERR_MSG_EMPTY_FILE == ret_code)
    {
        mmi_jmms_uc_xml_parsing_error(ret_code);
        g_jmms_context->decoder.current_object = NULL;
        return;
    }
    else
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(ret_code);
        g_jmms_context->decoder.current_object = NULL;
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_object_element_end_handler
 * DESCRIPTION
 *  object end tag handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_object_element_end_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_object_element_end_handler: %d",
                         g_jmms_context->decoder.current_object->type);
    switch (g_jmms_context->decoder.current_object->type)
    {
        case JMMS_UC_XML_OBJECT_TYPE_TEXT:
            mmi_jmms_uc_xml_add_text();
            break;
        case JMMS_UC_XML_OBJECT_TYPE_AUDIO:
            mmi_jmms_uc_xml_add_audio();
            break;
        case JMMS_UC_XML_OBJECT_TYPE_VIDEO:
            mmi_jmms_uc_xml_add_video();
            break;
        case JMMS_UC_XML_OBJECT_TYPE_IMAGE:
            mmi_jmms_uc_xml_add_image();
            break;
        case JMMS_UC_XML_OBJECT_TYPE_ATTACHMENT:
            mmi_jmms_uc_xml_add_attachment();
            break;
    }
    mmi_jmms_uc_xml_remove_object_in_object_list(g_jmms_context->decoder.current_object);
    g_jmms_context->decoder.parsing_state = JMMS_UC_XML_NO_ACTIVE_TAG;
    g_jmms_context->decoder.current_object = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_name_element_data_handler
 * DESCRIPTION
 *  name tag data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_name_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ucs2_len = (len + 1) * ENCODING_LENGTH;
    JC_CHAR *file_name_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_name_element_data_handler");
    MMI_ASSERT(g_jmms_context->decoder.current_object);
    file_name_p = jdd_MemAlloc(ucs2_len, 1);
    if (file_name_p == NULL)
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, 0, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    mmi_chset_utf8_to_ucs2_string((kal_uint8*) file_name_p, ucs2_len, (kal_uint8*) value);
    if ((GetUCS2Flag((S8*) file_name_p) == FALSE) && (is_extended_char_present((S8*) file_name_p) == FALSE))
    {
        g_jmms_context->decoder.current_object->file_name = (S16*) file_name_p;
    }
    else
    {
        U32 index = 0;
        JC_RETCODE ret_code = JC_OK;
        S8 temp_str[MMA_MAX_INTERNAL_FILENAME_LENGTH];
        JC_CHAR *dst_temp_file_name = NULL;
        JC_CHAR *tmp_file_ext_p = NULL;

        index = jdi_UtilsLastIndexOfTchar('.', file_name_p, jc_tcslen(file_name_p) - 1);
        tmp_file_ext_p = &file_name_p[index];
        sprintf(
            temp_str,
            "%s%d%d",
            JMMS_CHINESE_FILE_NAME_PRE_STRING,
            get_current_utc_time(),
            g_jmms_context->decoder.current_object->id);
        ret_code = jdi_UtilsCharToTchar(&dst_temp_file_name, temp_str);
        if (ret_code != JC_OK)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, 0, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            jdd_MemFree(file_name_p);
            mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 

        }
        g_jmms_context->decoder.current_object->file_name =
            (S16*) jdd_MemAlloc((jc_tcslen(dst_temp_file_name) + jc_tcslen(tmp_file_ext_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->decoder.current_object->file_name == NULL)
        {
        #ifndef __PRODUCTION_RELEASE__
            EXT_ASSERT(KAL_FALSE, 0, 0, 0);
        #else /* __PRODUCTION_RELEASE__ */ 
            mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
            return;
        #endif /* __PRODUCTION_RELEASE__ */ 
        }
        jc_tcscpy((JC_CHAR*) g_jmms_context->decoder.current_object->file_name, (JC_CHAR*) dst_temp_file_name);
        jc_tcscat((JC_CHAR*) g_jmms_context->decoder.current_object->file_name, tmp_file_ext_p);
        jdd_MemFree(dst_temp_file_name);
        jdd_MemFree(file_name_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_filepath_element_data_handler
 * DESCRIPTION
 *  filepath tag data handler
 * PARAMETERS
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_filepath_element_data_handler(const char *value, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_filepath_element_data_handler");
    MMI_ASSERT(g_jmms_context->decoder.current_object);
    g_jmms_context->decoder.current_object->file_path = jdd_MemAlloc(ucs2_len, 1);
    if (g_jmms_context->decoder.current_object->file_path == NULL)
    {
    #ifndef __PRODUCTION_RELEASE__
        EXT_ASSERT(KAL_FALSE, 0, 0, 0);
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(JC_ERR_MEMORY_ALLOCATION);
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*) g_jmms_context->decoder.current_object->file_path,
        ucs2_len,
        (kal_uint8*) value);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_msg_response
 * DESCRIPTION
 *  create the msg responce after creation
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_create_msg_response(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_create_msg_response: %d", ret_code);
    EXT_ASSERT(g_jmms_context->decoder.result_hdlr, 0, 0, 0);
    mmi_jmms_deinit_mms_context(g_jmms_context);
    if (ret_code == JC_ERR_FILE_WRITE)
    {
        ret_code = E_MEMORY_FULL_ERROR;
    }
#ifndef __PRODUCTION_RELEASE__
    if ((ret_code == E_MEMORY_FULL_ERROR
         || ret_code == JC_OK
         || ret_code == JC_ERR_FILE_READ
         || ret_code == JC_ERR_FILE_OPEN || ret_code == JC_ERR_MSG_EMPTY_FILE) && g_jmms_context->decoder.result_hdlr)
    {
        if (ret_code == JC_OK)
        {
            g_jmms_context->decoder.result_hdlr(ret_code, g_jmms_context->saved_mms_id);
        }
        else
        {
            g_jmms_context->decoder.result_hdlr(ret_code, 0);
        }
        g_jmms_context->decoder.result_hdlr = NULL;
    }
    else
    {
        EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
    }
#else /* __PRODUCTION_RELEASE__ */ 
    if (g_jmms_context->decoder.result_hdlr)
    {
        if (ret_code == JC_OK)
        {
            g_jmms_context->decoder.result_hdlr(ret_code, g_jmms_context->saved_mms_id);
        }
        else
        {
            g_jmms_context->decoder.result_hdlr(ret_code, 0);
        }
        g_jmms_context->decoder.result_hdlr = NULL;
    }
#endif /* __PRODUCTION_RELEASE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_mms_element_end_handler
 * DESCRIPTION
 *  xml mms end tag handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_mms_element_end_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_mms_element_end_handler");
    mmi_jmms_uc_xml_free_object_list();
    ret_code = mmi_jmms_save_mms("Drafts", g_jmms_context->msg_handle, MMI_FALSE, 0, mmi_jmms_uc_create_msg_response);
    if (ret_code != JC_ERR_MMS_ENCODE_PENDING && ret_code != JC_OK)
    {
    #ifndef __PRODUCTION_RELEASE__
        if (ret_code == E_MEMORY_FULL_ERROR
            || ret_code == JC_ERR_FILE_WRITE
            || ret_code == JC_ERR_FILE_READ || ret_code == JC_ERR_FILE_OPEN || ret_code == JC_ERR_MSG_EMPTY_FILE)
        {
            mmi_jmms_uc_xml_parsing_error(ret_code);
            g_jmms_context->decoder.current_object = NULL;
        }
        else
        {
            EXT_ASSERT(KAL_FALSE, ret_code, 0, 0);
        }
    #else /* __PRODUCTION_RELEASE__ */ 
        mmi_jmms_uc_xml_parsing_error(ret_code);
        g_jmms_context->decoder.current_object = NULL;
        return;
    #endif /* __PRODUCTION_RELEASE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_xml_parsing_error
 * DESCRIPTION
 *  error handler during parsing
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_xml_parsing_error(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_xml_parsing_error: %d", "ret_code");
    g_jmms_context->decoder.parsing_error_code = ret_code;
    xml_stop_parse(g_jmms_context->decoder.xml_parser);
    mmi_jmms_uc_xml_free_object_list();
    mmi_jmms_deinit_mms_context(g_jmms_context);

    /* it means the message response to UC is not sent yet */
    if (g_jmms_context->decoder.result_hdlr)
    {
        mmi_jmms_uc_create_msg_response(ret_code);
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
#else /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT) && defined(__MMI_UNIFIED_COMPOSER__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_uc_xml_decoder_fun
 * DESCRIPTION
 *  Just to remove warning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_uc_xml_decoder_fun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy */
}
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT) && defined(__MMI_UNIFIED_COMPOSER__)) */ 
#endif /* _MMI_JMMS_UC_XML_DECODER_C */ 

