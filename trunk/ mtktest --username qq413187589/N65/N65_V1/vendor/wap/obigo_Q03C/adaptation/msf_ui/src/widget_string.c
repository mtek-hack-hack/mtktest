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

/*******************************************************************************
 * Filename:
 * ---------
 * widget_string.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfString creation/attributes
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "widget.h"
#include "wgui_categories.h"    /* for get_string() */

extern void PopulateResData(void);
static const char NULL_PATTERN[] = {0, 0};

#ifdef WIDGET_RO_PRE_STRING
const
#endif 
static widget_pre_string_struct widget_predefined_string_table[WAP_STR_ID_SUM];


/*****************************************************************************
 * FUNCTION
 *  widget_get_raw_data_from_pre_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pstr        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static const kal_uint8 *widget_get_raw_data_from_pre_string(widget_pre_string_struct *pstr)
{
#ifdef WIDGET_COMPACT_PRE_STRING
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int resid;
    const kal_uint8 *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!pstr || pstr < widget_predefined_string_table)
    {
        WAP_DBG_ASSERT(0);
        return (const kal_uint8*)NULL_PATTERN;
    }

    resid = pstr - widget_predefined_string_table;

    if (resid >= WAP_STR_ID_SUM)
    {
        WAP_DBG_ASSERT(0);
        return (const kal_uint8*)NULL_PATTERN;
    }

    resid += WAP_STR_ID_BEGIN;
    res = (const kal_uint8*)get_string((MMI_ID_TYPE) resid);
    if (!res)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_STRING_NOT_FOUND);
        res = (const kal_uint8*)NULL_PATTERN;
    }
    return res;
#else /* WIDGET_COMPACT_PRE_STRING */ 
    return pstr->string;
#endif /* WIDGET_COMPACT_PRE_STRING */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_create_string_internal
 * DESCRIPTION
 *  Create an new MsfString object
 * PARAMETERS
 *  modId               [IN]        Module ID
 *  stringData          [IN]        Source data
 *  stringFormat        [IN]        Encoding of 'stringData'
 *  defaultStyle        [IN]        Default style (0 for no default style)
 *  max_size            [IN]        Maximum number of character (0 for using the whole string)
 * RETURNS
 *  MsfString handle
 *****************************************************************************/
static MsfStringHandle widget_create_string_internal(
                        MSF_UINT8 modId,
                        const char *stringData,
                        MsfStringFormat stringFormat,
                        MsfStyleHandle defaultStyle,
                        int max_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_raw_data_struct *string = NULL;
    widget_string_struct *w;
    int size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stringData == NULL)
    {
        stringData = NULL_PATTERN;
    }

    /* create string raw data */
    switch (stringFormat)
    {
        case MsfUtf8:
            size = widget_utf8_length((const kal_uint8*)stringData);
            if (max_size > 0 && max_size < size)
            {
                size = max_size;
            }
            size = (size + 1) << 1;
            string = widget_create_raw_data_ext(modId, size);

            widget_utf8_to_ucs2_string(string->data, size, (kal_uint8*) stringData);
            break;

        case MsfUcs2:
            size = widget_ucs2_length((const kal_uint8*)stringData);
            if (max_size > 0 && max_size < size)
            {
                size = max_size;
            }
            size = (size + 1) << 1;
            string = widget_create_raw_data_ext(modId, size);

            memcpy(string->data, stringData, size);
            if (size >= 2)
            {
                string->data[size - 2] = 0;
                string->data[size - 1] = 0;
            }
            break;

        default:
            ASSERT(KAL_FALSE);
    }

    /* create string widget */
    w = widget_create_string(modId);
    w->module_id = modId;
    widget_set_attrib(w, raw, string);

#ifndef WIDGET_COMPACT_RUNTIME_STRUCT
    w->string_format = WIDGET_ENCODING;
#endif 

    widget_set_attrib(w, style, defaultStyle);

    WAP_DBG_ASSERT(w->parent_cnt == 1);
    WAP_DBG_ASSERT(w->raw->parent_cnt == 1);

    return (MsfStringHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  stringData          [IN]        
 *  stringFormat        [IN]        
 *  length              [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfStringHandle HDIa_widgetStringCreate(
                    MSF_UINT8 modId,
                    const char *stringData,
                    MsfStringFormat stringFormat,
                    int length,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(length);

    return widget_create_string_internal(modId, stringData, stringFormat, defaultStyle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_copy_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  s           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfStringHandle widget_copy_string(MSF_UINT8 modId, MsfStringHandle s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PRE_STRING_TYPE(s))
    {
        widget_pre_string_struct *str = _PSTR(s);

        return HDIa_widgetStringCreate(
                modId,
                (const char*)widget_get_raw_data_from_pre_string(str),
                WIDGET_ENCODING,
                0,
                0);
    }
    else
    {
        widget_string_struct *str = _STR(s);

        WAP_DBG_ASSERT(IS_STRING_TYPE(s));

        return HDIa_widgetStringCreate(modId, (const char*)str->raw->data,
    #ifdef WIDGET_COMPACT_RUNTIME_STRUCT
                                       WIDGET_ENCODING,
    #else 
                                       str->string_format,
    #endif 
                                       0, str->style);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_copy_partial_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  s               [IN]        
 *  index           [IN]        
 *  nbrOfChars      [IN]        
 *  copy_style      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfStringHandle widget_copy_partial_string(
                    MSF_UINT8 modId,
                    MsfStringHandle s,
                    int index,
                    int nbrOfChars,
                    kal_bool copy_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PRE_STRING_TYPE(s))
    {
        widget_pre_string_struct *str = _PSTR(s);

        WAP_DBG_ASSERT(index < STR_LEN(widget_get_raw_data_from_pre_string(str)));
        src = STR_AT(widget_get_raw_data_from_pre_string(str), index);
        WAP_DBG_ASSERT(nbrOfChars <= STR_LEN(src));

        return widget_create_string_internal(modId, src, WIDGET_ENCODING, 0, nbrOfChars);
    }
    else
    {
        widget_string_struct *str = _STR(s);

        WAP_DBG_ASSERT(IS_STRING_TYPE(s));

        WAP_DBG_ASSERT(index < STR_LEN(str->raw->data));
        src = STR_AT(str->raw->data, index);
        WAP_DBG_ASSERT(nbrOfChars <= STR_LEN(src));

        return widget_create_string_internal(modId, src,
    #ifdef WIDGET_COMPACT_RUNTIME_STRUCT
                                             WIDGET_ENCODING,
    #else 
                                             str->string_format,
    #endif 
                                             copy_style ? str->style : 0, nbrOfChars);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_resize_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str         [?]         
 *  max_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_resize_string(widget_string_struct *str, int max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_raw_data_struct *string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!str)
    {
        return;
    }

    ASSERT(IS_STRING_TYPE(str));

    max_len = (max_len + 1) << 1;
    string = widget_create_raw_data_ext(str->module_id, max_len + 2);   /* +2 is for paranoid */
    /* Original reference count of raw data is 0 */

    if (str->raw)
    {
        int len;

        if (str->raw->size > max_len)
        {
            len = max_len;
        }
        else
        {
            len = str->raw->size;
        }
        widget_set_raw_data(string, str->raw->data, len);

        /* max_len is already incremented by 1 before this point */
        string->data[max_len - 1] = 0;
        string->data[max_len - 2] = 0;
    }
    widget_set_attrib(str, raw, string);
    WAP_DBG_ASSERT(str->raw->parent_cnt == 1);
}

/* static kal_bool is_mmi_resource_initialized=KAL_FALSE; */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringGetPredefined
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resId       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfStringHandle HDIa_widgetStringGetPredefined(MSF_UINT32 resId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index = resId - WAP_STR_ID_BEGIN;

#ifndef WIDGET_COMPACT_PRE_STRING
    const kal_uint8 *string;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      if(!is_mmi_resource_initialized)
    //      {
    //              PopulateResData();
    //              is_mmi_resource_initialized=KAL_TRUE;
    //      }

    WAP_DBG_ASSERT(resId >= WAP_STR_ID_BEGIN);
    WAP_DBG_ASSERT(index < WAP_STR_ID_SUM);

    if (resId < WAP_STR_ID_BEGIN || index >= WAP_STR_ID_SUM)
    {
        resId = WAP_STR_ID_BEGIN;
        index = 0;
    }

#ifndef WIDGET_RO_PRE_STRING
    widget_predefined_string_table[index].data_type = WIDGET_PRE_STRING_TYPE;
    widget_predefined_string_table[index].flag = WIDGET_FLAG_STATIC;
#endif /* WIDGET_RO_PRE_STRING */ 
#ifndef WIDGET_COMPACT_PRE_STRING
    string = (const kal_uint8*)get_string((MMI_ID_TYPE) (resId));

    if (string == NULL)
    {
        string = (const kal_uint8*)NULL_PATTERN;
    }
    widget_predefined_string_table[index].string = string;
#endif /* WIDGET_COMPACT_PRE_STRING */ 

    return (MsfStringHandle) & (widget_predefined_string_table[index]);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringCreateText
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  handle      [IN]        
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfStringHandle HDIa_widgetStringCreateText(MSF_UINT8 modId, MSF_UINT32 handle, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_GADGET_INPUT_TYPE(handle))
    {
        return widget_copy_string(modId, _GINP(handle)->text);
    }
    else if (IS_EDITOR_TYPE(handle))
    {
        return widget_copy_string(modId, _EDITOR(handle)->text);
    }
    else if (IS_DIALOG_TYPE(handle))
    {
        widget_gadget_input_struct *node;

        if (_DIALOG(handle)->input_sum < index + 1)
        {
            return 0;
        }

        foreach(handle, GADGET_INPUT, node,
                {
                if (node->index == index) return HDIa_widgetStringCreateText(modId, (MSF_UINT32) node, 0);}
        );
    }

    WAP_RST_ASSERT(KAL_FALSE);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringGetLength
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string              [IN]        
 *  lengthInBytes       [IN]        
 *  format              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetStringGetLength(MsfStringHandle string, int lengthInBytes, MsfStringFormat format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lengthInBytes)
    {
        return widget_string_length_in_bytes(string) + 1;   /* including the tailing null */
    }
    else
    {
        return widget_string_length(string);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringGetData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 *  buffer      [?]         
 *  format      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetStringGetData(MsfStringHandle string, char *buffer, MsfStringFormat format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_string_copy_content_to_utf8((kal_uint8*) buffer, string);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringCompare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string1     [IN]        
 *  string2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetStringCompare(MsfStringHandle string1, MsfStringHandle string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    kal_uint8 *s1 = widget_string_content(string1);
    kal_uint8 *s2 = widget_string_content(string2);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0;; i++)
    {
        int cmp = CHR_AT(s1, i) - CHR_AT(s2, i);

        if (cmp == 0)
        {
            if (CHR_AT(s1, i) == CHR(0))
            {
                return 0;
            }
        }
        else
        {
            return cmp;
        }
    }
}

/****************************************************************
 * Utility functions for MsfString handle
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_string_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *widget_string_content(MsfStringHandle str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!str)
    {
        return NULL;
    }
    if (IS_PRE_STRING_TYPE(str))
    {
        return (kal_uint8*) widget_get_raw_data_from_pre_string(_PSTR(str));
    }
    if (IS_STRING_TYPE(str))
    {
        return (kal_uint8*) _STR(str)->raw->data;
    }
    ASSERT(KAL_FALSE);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_string_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_string_length(MsfStringHandle str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PRE_STRING_TYPE(str))
    {
        return STR_LEN(widget_get_raw_data_from_pre_string(_PSTR(str)));
    }
    else if (IS_STRING_TYPE(str))
    {
        return STR_LEN(_STR(str)->raw->data);
    }
    ASSERT(KAL_FALSE);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_string_copy_content_to_utf8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [?]         
 *  str         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_string_copy_content_to_utf8(kal_uint8 *buffer, MsfStringHandle str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ucs2_to_utf8_string(
        buffer,
        100000000, // TODO: fix this
        (kal_uint8*)widget_string_content(str));
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStringGetUCS2buffer
 * DESCRIPTION
 *  Get the content of an MsfString in UCS2
 * PARAMETERS
 *  str     [IN]        A string handle
 * RETURNS
 *  The content of the string handle (static, read-only)
 *****************************************************************************/
const kal_uint8 *HDIa_widgetExtStringGetUCS2buffer(MsfStringHandle str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8*) widget_string_content(str);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStringGetPredefinedUCS2buffer
 * DESCRIPTION
 *  Get the content of a string ID in UCS2
 * PARAMETERS
 *  resid       [IN]        String ID
 * RETURNS
 *  The content of the string ID (static, read-only)
 *****************************************************************************/
const kal_uint8 *HDIa_widgetExtStringGetPredefinedUCS2buffer(MSF_UINT32 resid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str = GetString((U16) resid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str)
    {
        return (const kal_uint8*)str;
    }
    else
    {
        return (const kal_uint8*)NULL_PATTERN;
    }
}

