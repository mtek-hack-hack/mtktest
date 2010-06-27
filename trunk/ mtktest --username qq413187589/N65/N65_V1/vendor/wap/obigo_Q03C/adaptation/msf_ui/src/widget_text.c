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
 * widget_text.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Text input for MsfDialog 
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
/****************************************************************
 TEXT 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetTextSetText
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text                [IN]        
 *  initialString       [IN]        
 *  type                [IN]        
 *  maxSize             [IN]        
 *  inputString         [IN]        
 *  singleLine          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetTextSetText(
        MSF_UINT32 text,
        MsfStringHandle initialString,
        MsfTextType type,
        int maxSize,
        MsfStringHandle inputString,
        int singleLine)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (maxSize <= 0)
    {
        maxSize = WIDGET_MAX_INPUT_LEN;
    }

    WIDGET_UNUSED(initialString);   /* We dropped the support of initialString */

    if (IS_EDITOR_TYPE(text))
    {
        /* widget_set_attrib(_EDITOR(text),prompt,initialString); */
        if (inputString)
        {
            MsfStringHandle str = widget_copy_string(_H(text)->module_id, inputString);

            widget_set_attrib(_EDITOR(text), text, str);
            DEC_REF(_EDITOR(text)->text);   /* need it to automatic free */
        }

        if (!_EDITOR(text)->text)
        {
            _EDITOR(text)->text = (MsfStringHandle) widget_create_string(_H(text)->module_id);
            _H(_EDITOR(text)->text)->module_id = _H(text)->module_id;
        #ifndef WIDGET_COMPACT_RUNTIME_STRUCT
            _STR(_EDITOR(text)->text)->string_format = WIDGET_ENCODING;
        #endif 
            DEC_REF(_EDITOR(text)->text);   /* need it to automatic free */
        }

        if (type != MsfNoTextType)
        {
            _EDITOR(text)->text_type = type;
        }
        _EDITOR(text)->is_single_line = singleLine ? KAL_TRUE : KAL_FALSE;
        _EDITOR(text)->input_max_size = maxSize;
        widget_resize_string(_STR(_EDITOR(text)->text), maxSize);
        return 1;
    }
    if (IS_GADGET_INPUT_TYPE(text))
    {
        if (maxSize > WIDGET_MAX_INPUT_LEN)
        {
            /* The default and max size is WIDGET_MAX_INPUT_LEN */
            maxSize = WIDGET_MAX_INPUT_LEN;
        }
        /* widget_set_attrib(_GINP(text),prompt,initialString); */
        if (inputString)
        {
            MsfStringHandle str = widget_copy_string(_H(text)->module_id, inputString);

            widget_set_attrib(_GINP(text), text, str);
            DEC_REF(_GINP(text)->text); /* need it to automatic free */
        }

        if (!_GINP(text)->text)
        {
            _GINP(text)->text = (MsfStringHandle) widget_create_string(_H(text)->module_id);
            _H(_GINP(text)->text)->module_id = _H(text)->module_id;
        #ifndef WIDGET_COMPACT_RUNTIME_STRUCT
            _STR(_GINP(text)->text)->string_format = WIDGET_ENCODING;
        #endif 
            DEC_REF(_GINP(text)->text); /* need it to automatic free */
        }

        if (type != MsfNoTextType)
        {
            _GINP(text)->text_type = type;
        }
        _GINP(text)->is_single_line = singleLine ? KAL_TRUE : KAL_FALSE;
        _GINP(text)->input_max_size = maxSize;
        widget_resize_string(_STR(_GINP(text)->text), maxSize);

    #ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ 
        {
            /* Check and modify the max_size first */
            kal_uint8 *temp = NULL;

            temp = MSF_MEM_ALLOC(MSF_MODID_WIDGET, (WIDGET_MAX_INPUT_LEN + 1)*ENCODING_LENGTH);
            widget_set_wcss_input_format_default_value(
                (kal_uint8*) temp,
                &(_GINP(text)->input_max_size),
                (const char*)_GINP(text)->format_pattern);
            MSF_MEM_FREE(MSF_MODID_WIDGET, temp);
            if (_GINP(text)->input_max_size > WIDGET_MAX_INPUT_LEN)
            {
                /* The max size is WIDGET_MAX_INPUT_LEN */
                _GINP(text)->input_max_size = WIDGET_MAX_INPUT_LEN;
            }
        }

        /* initialize CSS pattern; We will check the inputbox content is valid in WCSS format */
        widget_init_input_CSS_pattern((char*)_GINP(text)->format_pattern);
        if (widget_is_match_CSS_pattern(widget_string_content(_GINP(text)->text)) == KAL_FALSE)
        {
            widget_set_wcss_input_format_default_value(
                (kal_uint8*) widget_string_content(_GINP(text)->text),
                &(_GINP(text)->input_max_size),
                (const char*)_GINP(text)->format_pattern);
        }
    #endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */

        return 1;
    }

    WAP_RST_ASSERT(KAL_FALSE);  /* maybe we should just ASSERT() */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetTextMaxSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetTextMaxSize(MSF_UINT32 text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_EDITOR_TYPE(text))
    {
        return _EDITOR(text)->input_max_size;
    }
    if (IS_GADGET_INPUT_TYPE(text))
    {
        return _GINP(text)->input_max_size;
    }

    WAP_RST_ASSERT(KAL_FALSE);  /* maybe we should just ASSERT() */
    return 0;
}

// TODO: other type


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetTextClear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetTextClear(MSF_UINT32 text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_EDITOR_TYPE(text))
    {
        int size = _EDITOR(text)->input_max_size;

        memset(_RAW(_EDITOR(text)->text)->data, 0, STR_SIZE(size + 1));
        return 1;
    }
    if (IS_GADGET_INPUT_TYPE(text))
    {
        int size = _GADGET_INPUT(text)->input_max_size;

        memset(_RAW(_GADGET_INPUT(text)->text)->data, 0, STR_SIZE(size + 1));
        return 1;
    }
    WAP_RST_ASSERT(KAL_FALSE);
    return 0;
}

/* FIXME. HDIa_widgetTextSetProperty(), HDIa_widgetTextGetProperty should support string gadget */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetTextSetProperty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle              [IN]        
 *  color               [?]         
 *  font                [?]         
 *  textProperty        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetTextSetProperty(MSF_UINT32 handle, MsfColor *color, MsfFont *font, MsfTextProperty *textProperty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_EDITOR_TYPE(handle))
    {
        if (color)
        {
            _EDITOR(handle)->color = *color;
        }
        if (font)
        {
            _EDITOR(handle)->font = *font;
        }
        if (textProperty)
        {
            _EDITOR(handle)->text_property = *textProperty;
        }
        return 1;
    }
    if (IS_GADGET_INPUT_TYPE(handle))
    {
        if (color)
        {
            _GINP(handle)->color = *color;
        }
        if (font)
        {
            _GINP(handle)->font = *font;
        }
        if (textProperty)
        {
            _GINP(handle)->text_property = *textProperty;
        }
        return 1;
    }
    if (IS_DIALOG_TYPE(handle) && _DIALOG(handle)->dialog_type == MsfPrompt)
    {
        if (color)
        {
            _DIALOG(handle)->color = *color;
        }
        if (font)
        {
            _DIALOG(handle)->font = *font;
        }
        if (textProperty)
        {
            _DIALOG(handle)->text_property = *textProperty;
        }
        return 1;
    }
    WAP_DBG_ASSERT(KAL_FALSE);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetTextGetProperty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle              [IN]        
 *  color               [?]         
 *  font                [?]         
 *  textProperty        [?]         
 *  baseline            [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetTextGetProperty(
        MSF_UINT32 handle,
        MsfColor *color,
        MsfFont *font,
        MsfTextProperty *textProperty,
        MsfPosition *baseline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(0);  /* hjf not process MsfPosition* baseline */
    if (IS_EDITOR_TYPE(handle))
    {
        if (color)
        {
            *color = _EDITOR(handle)->color;
        }
        if (font)
        {
            *font = _EDITOR(handle)->font;
        }
        if (textProperty)
        {
            *textProperty = _EDITOR(handle)->text_property;
        }
        return 1;
    }
    if (IS_GADGET_INPUT_TYPE(handle))
    {
        if (color)
        {
            *color = _GINP(handle)->color;
        }
        if (font)
        {
            *font = _GINP(handle)->font;
        }
        if (textProperty)
        {
            *textProperty = _GINP(handle)->text_property;
        }
        return 1;
    }
    if (IS_DIALOG_TYPE(handle) && _DIALOG(handle)->dialog_type == MsfPrompt)
    {
        if (color)
        {
            *color = _DIALOG(handle)->color;
        }
        if (font)
        {
            *font = _DIALOG(handle)->font;
        }
        if (textProperty)
        {
            *textProperty = _DIALOG(handle)->text_property;
        }
        return 1;
    }
    WAP_RST_ASSERT(KAL_FALSE);
    return 0;
}

