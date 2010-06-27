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
 * widget_gadget.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget gadgets creation/attributes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"

/****************************************************************
 GADGET 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGadgetSetProperties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gadget              [IN]        
 *  propertyMask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGadgetSetProperties(MsfGadgetHandle gadget, int propertyMask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _W(gadget)->property_mask = propertyMask;
    widget_paint();
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGadgetSetAlignment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gadget          [IN]        
 *  alignment       [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGadgetSetAlignment(MsfGadgetHandle gadget, MsfAlignment *alignment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef WIDGET_COMPACT_RUNTIME_STRUCT
    _W(gadget)->alignment = *alignment;
#endif 
    widget_paint();
    return 1;
}

/****************************************************************
 STRING GADGET 
 ***************************************************************/

/*
 * We want to use multiline readonly input to emulate multiline string gadget
 * * The following functions use StringGadget:
 * *
 * * HDIa_widgetStringGadgetCreate()
 * * HDIa_widgetStringGadgetSet()
 * * HDIa_widgetTextSetProperty()
 * * HDIa_widgetTextGetProperty()
 * *
 * * FIXME. the last two functions are not implemented
 */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringGadgetCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  text                [IN]        
 *  size                [IN]         
 *  singleLine          [IN]        
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfGadgetHandle HDIa_widgetStringGadgetCreate(
                    MSF_UINT8 modId,
                    MsfStringHandle text,
                    MsfSize *size,
                    int singleLine,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (singleLine)
    {
        widget_gadget_string_struct *w;

        w = widget_create_gadget_string(modId);
        w->module_id = modId;
        widget_set_attrib(w, text, text);
        widget_set_attrib(w, style, defaultStyle);

        if (size)
        {
            w->size = *size;
        }
        w->property_mask = propertyMask;
        w->is_single_line = singleLine ? KAL_TRUE : KAL_FALSE;

        return (MsfGadgetHandle) w;
    }
    else
    {
        widget_gadget_input_struct *w = (widget_gadget_input_struct*) HDIa_widgetTextInputCreateCss(
                                                                        modId,
                                                                        0,
                                                                        text,
                                                                        MsfText,
                                                                        NULL,
                                                                        0,
                                                                        0,
                                                                        0, /* not single-line */
                                                                        size,
                                                                        propertyMask,
                                                                        defaultStyle);

        w->is_readonly = KAL_TRUE;
        w->is_string_gadget_emulation = KAL_TRUE;
        return (MsfGadgetHandle) w;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringGadgetSet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stringGadget        [IN]        
 *  text                [IN]        
 *  singleLine          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetStringGadgetSet(MsfGadgetHandle stringGadget, MsfStringHandle text, int singleLine)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_GADGET_INPUT_TYPE(stringGadget)) /* user input gadget to emulate string gadget */
    {
        widget_gadget_input_struct *w = (widget_gadget_input_struct*) stringGadget;

        ASSERT(w->is_string_gadget_emulation);
        WAP_DBG_ASSERT(w->is_single_line == KAL_FALSE);
        WAP_DBG_ASSERT(w->is_readonly);

        // WAP_DBG_ASSERT(!singleLine); /* FIXME. unfinished, simply ignore it*/

        widget_set_attrib(w, text, text);
    }
    else
    {
        widget_gadget_string_struct *w = _GSTR(stringGadget);

        WAP_DBG_ASSERT(w->is_single_line);

        // WAP_DBG_ASSERT(singleLine);  /* FIXME. unfinished, simply ignore it */

        widget_set_attrib(w, text, text);
    }

    widget_paint();

    return 1;
}


/****************************************************************
 TEXT INPUT GADGET 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetTextInputCreateCss
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  initialString       [IN]        
 *  inputString         [IN]        
 *  type                [IN]        
 *  formatString        [IN]        
 *  inputRequired       [IN]        
 *  maxSize             [IN]        
 *  singleLine          [IN]        
 *  size                [IN]         
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfGadgetHandle HDIa_widgetTextInputCreateCss(
                    MSF_UINT8 modId,
                    MsfStringHandle initialString,
                    MsfStringHandle inputString,
                    MsfTextType type,
                    const char *formatString,
                    int inputRequired,
                    int maxSize,
                    int singleLine,
                    MsfSize *size,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStringHandle str;
    widget_gadget_input_struct *w = widget_create_gadget_input(modId);
    kal_uint8 *raw_text = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    /* widget_set_attrib(w,prompt,initialString); */

    if (!inputString)
    {
        str = HDIa_widgetStringCreate(modId, "", MsfUtf8, 1, 0);
    }
    else
    {
        str = widget_copy_string(modId, inputString);
    }

    widget_set_attrib(w, text, str);
    DEC_REF(w->text);   /* need it to automatic free */

    if (!formatString || strlen(formatString) >= WIDGET_MAX_FORMAT_PATTERN_LEN)
    {
        formatString = "*m";
    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
    /* For example, replace "*n" with "n*n" if wap-input-required=true */
    if (inputRequired == 1 && formatString[0] == '*' && formatString[1] != '\0')
    {
        widget_utf8_to_ucs2_string((kal_uint8*)w->format_pattern, 4, (const kal_uint8*)&formatString[1]);
        widget_utf8_to_ucs2_string((kal_uint8*)w->format_pattern, WIDGET_MAX_FORMAT_PATTERN_LEN, (const kal_uint8*)formatString);
    }
    else
    {
        widget_utf8_to_ucs2_string((kal_uint8*)w->format_pattern, WIDGET_MAX_FORMAT_PATTERN_LEN, (const kal_uint8*)formatString);
    }
#else /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 
    /* The old implementation is not very robust. */
    widget_utf8_to_ucs2_string((kal_uint8*)w->format_pattern, WIDGET_MAX_FORMAT_PATTERN_LEN, (const kal_uint8*)formatString);
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 

    if (maxSize <= 0 || maxSize > WIDGET_MAX_INPUT_LEN)
    {
        /* The default and max size is WIDGET_MAX_INPUT_LEN */
        maxSize = WIDGET_MAX_INPUT_LEN;
    }

    widget_resize_string(_STR(w->text), maxSize);
    /* DEC_REF(w->text); */

    WAP_DBG_ASSERT(_STR(w->text)->parent_cnt == 1);
    WAP_DBG_ASSERT(_STR(w->text)->raw->parent_cnt == 1);

    w->text_type = type;
    w->input_max_size = maxSize;
    w->is_single_line = singleLine ? KAL_TRUE : KAL_FALSE;
    if (size)
    {
        w->size = *size;
        /* We don't folllow widget spec here because GUI input requires minimum height  */
        if (singleLine && (w->size.height < WIDGET_DEFAULT_SINGLE_LINE_INPUT_HEIGHT))
        {
            w->size.height = (short)WIDGET_DEFAULT_SINGLE_LINE_INPUT_HEIGHT;
        }
        /* gui multiline inputbox will handle the situation when the width is too small */
    }
    else
    {
        if (singleLine)
        {
            w->size.width = (short)WIDGET_DEFAULT_SINGLE_LINE_INPUT_WIDTH;
            w->size.height = (short)WIDGET_DEFAULT_SINGLE_LINE_INPUT_HEIGHT;
        }
        else
        {
            w->size.width = WIDGET_DEFAULT_MULTI_LINE_INPUT_WIDTH;
            w->size.height = WIDGET_DEFAULT_MULTI_LINE_INPUT_HEIGHT;
        }
    }

    w->property_mask = propertyMask;
    w->index = -1;  /* default no index */

    w->is_input_required = inputRequired;

    widget_set_attrib(w, style, defaultStyle);

    /*
     * Extract default value in CSS input format 
     * * If -wap-input-required = false, pend initialization of default value till entering MMI editor.
     */
    raw_text = widget_string_content(w->text);
    {
        /* Adjust the WCSS input box length */
        kal_uint8* tmp_buf = NULL;

        tmp_buf = MSF_MEM_ALLOC(MSF_MODID_WIDGET, (WIDGET_MAX_INPUT_LEN + 1)*ENCODING_LENGTH);
        widget_set_wcss_input_format_default_value(
            (kal_uint8*) tmp_buf,
            &(w->input_max_size),
            (const char*)w->format_pattern);
        MSF_MEM_FREE(MSF_MODID_WIDGET, tmp_buf);
        if (w->input_max_size > WIDGET_MAX_INPUT_LEN)
        {
            /* The max size is WIDGET_MAX_INPUT_LEN */
            w->input_max_size = WIDGET_MAX_INPUT_LEN;
        }

    }
    if (inputRequired != 0 /* 1 or -1 */  &&
        (CHR_AT(raw_text, 0) == CHR(0)) &&
        widget_set_wcss_input_format_default_value(
            (kal_uint8*) raw_text,
            &(w->input_max_size),
            (const char*)w->format_pattern) < 0)
    {
        SET_CHR_AT(raw_text, 0, 0);
        widget_utf8_to_ucs2_string((kal_uint8*)w->format_pattern, WIDGET_MAX_FORMAT_PATTERN_LEN, (const kal_uint8*)"*m");
    }

    return (MsfGadgetHandle) w;

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetTextInputCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  initialString       [IN]        
 *  inputString         [IN]        
 *  type                [IN]        
 *  maxSize             [IN]        
 *  singleLine          [IN]        
 *  size                [IN]         
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfGadgetHandle HDIa_widgetTextInputCreate(
                    MSF_UINT8 modId,
                    MsfStringHandle initialString,
                    MsfStringHandle inputString,
                    MsfTextType type,
                    int maxSize,
                    int singleLine,
                    MsfSize *size,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HDIa_widgetTextInputCreateCss(
            modId,
            initialString,
            inputString,
            type,
            NULL,
            -1,
            maxSize,
            singleLine,
            size,
            propertyMask,
            defaultStyle);
}

/****************************************************************
 SELECT GROUP GADGET 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSelectgroupCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  type                [IN]        
 *  size                [IN]         
 *  elementPos          [IN]         
 *  bitmask             [IN]        
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfGadgetHandle HDIa_widgetSelectgroupCreate(
                    MSF_UINT8 modId,
                    MsfChoiceType type,
                    MsfSize *size,
                    MsfElementPosition *elementPos,
                    int bitmask,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_select_group_struct *w = widget_create_gadget_select_group(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    if (type == MsfExclusiveChoiceDropDown)
    {
        type = MsfExclusiveChoice;
    }
    w->choice_type = type;
    if (size)
    {
        w->size = *size;
    }
    if (elementPos)
    {
        w->element_position = *elementPos;
    }
    w->element_bitmask = bitmask;
    w->property_mask = propertyMask;
    w->highlight_index = -1;
    w->profile_activated_index = -1;

    widget_set_attrib(w, style, defaultStyle);

    return (MsfGadgetHandle) w;
}

/****************************************************************
 IMAGE GADGET
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageGadgetCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  image               [IN]        
 *  size                [IN]         
 *  imageZoom           [IN]        
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfGadgetHandle HDIa_widgetImageGadgetCreate(
                    MSF_UINT8 modId,
                    MsfImageHandle image,
                    MsfSize *size,
                    MsfImageZoom imageZoom,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *w = widget_create_gadget_image(modId);
    MsfStyleHandle copy_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    widget_set_attrib(w, image, image);

    if (image)  /* image might be 0 */
    {
        w->size.width = widget_image_width(image);
        w->size.height = widget_image_height(image);
    }

    /*
     * size might be later modified by HDIa_widgetSetSize 
     * * Integration manual ask to clip to the intersection of size & maxSize given by HDIa_widgetSetSize,
     * * but we simply let HDIa_widgetSetSize override the size.
     */
    if (size)
    {
        w->size = *size;
    }

    w->zoom = imageZoom;
    w->property_mask = propertyMask;

#ifdef WIDGET_BROWSER_AUTORESIZE_JPEG
    if (_IMG(image)->is_jpeg_auto_resize == 1)
    {
        w->size = _IMG(image)->size;
        w->zoom = MsfImageZoomAutofit;
    }
#endif /* WIDGET_BROWSER_AUTORESIZE_JPEG */ 

    if (defaultStyle)
    {
        /*
         * Because background color of marquee box is used later, and we should not share
         * * the same style object with paintbox because paintbox style will be modified later.
         * * FIXME. COPY-ON-WRITE of style object is a better solution. 
         * * However, the implementation will be much more complex.
         * * cf. HDIa_widgetImageCreateEmpty()
         */
        copy_style = widget_style_copy(modId, defaultStyle);
        widget_set_attrib(w, style, copy_style);
        DEC_REF(copy_style);
    }
    else
    {
        widget_set_attrib(w, style, 0);
    }

    return (MsfGadgetHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageGadgetSet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imageGadget     [IN]        
 *  image           [IN]        
 *  imageZoom       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetImageGadgetSet(MsfGadgetHandle imageGadget, MsfImageHandle image, MsfImageZoom imageZoom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_set_attrib(_GIMG(imageGadget), image, image);

#if 0   /* Application should invokes HDIa_widgetSetSize instead */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    _GIMG(imageGadget)->zoom = imageZoom;

#ifdef WIDGET_BROWSER_AUTORESIZE_JPEG
    {
        widget_gadget_image_struct *gimg = _GIMG(imageGadget);

        if (_IMG(image)->is_jpeg_auto_resize == 1)
        {
            gimg->size = _IMG(image)->size;
            gimg->zoom = MsfImageZoomAutofit;
        }
    }
#endif /* WIDGET_BROWSER_AUTORESIZE_JPEG */ 

    /* 
     * MTR and SMTR of MMS invoke HDIa_widgetImageGadgetSet() on scrolling text. 
     * As a result, we should not invoke widget_paint() due to performance issue.
     * Instead. we redraw the image gadget only.
     */
    widget_add_paint_gadget_command(_H(imageGadget));

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGetImageFromGadget
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gimg        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetExtGetImageFromGadget(MsfGadgetHandle gimg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gimg)
    {
        return 0;
    }
    if (!IS_GADGET_IMAGE_TYPE(gimg))
    {
        return 0;
    }
    return _GIMG(gimg)->image;
}

/****************************************************************
 DATE TIME GADGET
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDateTimeCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  mode                [IN]        
 *  time                [IN]         
 *  date                [IN]         
 *  size                [IN]         
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfGadgetHandle HDIa_widgetDateTimeCreate(
                    MSF_UINT8 modId,
                    MsfDateTimeType mode,
                    MsfTime *time,
                    MsfDate *date,
                    MsfSize *size,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_date_struct *w = widget_create_gadget_date(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    w->datetime_type = mode;
    if (time)
    {
        w->time = *time;
    }
    if (date)
    {
        w->date = *date;
    }
    if (size)
    {
        w->size = *size;
    }
    w->property_mask = propertyMask;

    widget_set_attrib(w, style, defaultStyle);

    return (MsfGadgetHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDateTimeSetValues
 * DESCRIPTION
 *  
 * PARAMETERS
 *  datetimeGadget      [IN]        
 *  mode                [IN]        
 *  time                [IN]         
 *  date                [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDateTimeSetValues(MsfGadgetHandle datetimeGadget, MsfDateTimeType mode, MsfTime *time, MsfDate *date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _GDATE(datetimeGadget)->datetime_type = mode;
    if (time)
    {
        _GDATE(datetimeGadget)->time = *time;
    }
    if (date)
    {
        _GDATE(datetimeGadget)->date = *date;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDateTimeGetValues
 * DESCRIPTION
 *  
 * PARAMETERS
 *  datetimeGadget      [IN]        
 *  time                [OUT]         
 *  date                [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDateTimeGetValues(MsfGadgetHandle datetimeGadget, MsfTime *time, MsfDate *date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *time = _GDATE(datetimeGadget)->time;
    *date = _GDATE(datetimeGadget)->date;
    return 1;
}

/****************************************************************
 BAR GADGET
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetBarCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  barType             [IN]        
 *  maxValue            [IN]        
 *  initialValue        [IN]        
 *  size                [IN]         
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfGadgetHandle HDIa_widgetBarCreate(
                    MSF_UINT8 modId,
                    MsfBarType barType,
                    int maxValue,
                    int initialValue,
                    MsfSize *size,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_bar_struct *w = widget_create_gadget_bar(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;
    w->bar_type = barType;
    w->max_value = maxValue;
    w->value = initialValue;
    w->pen_min_offset = -1;     /* -1: use widget original setting on pen min offset */
    if (size)
    {
        w->size = *size;
    }
    w->property_mask = propertyMask;

    widget_set_attrib(w, style, defaultStyle);

    return (MsfGadgetHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetBarSetValues
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bar             [IN]        
 *  value           [IN]        
 *  maxValue        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetBarSetValues(MsfGadgetHandle bar, int value, int maxValue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _GBAR(bar)->value = value;
    _GBAR(bar)->max_value = maxValue;

#ifdef __MMI_TOUCH_SCREEN__
    if (WPEN_CTX->vbar_indication_in_queue)
    {
        /* Update the browser content by the pen event */
        if (_GBAR(bar) == WGUI_CTX->current_vertical_scrollbar)
        {
            WPEN_CTX->current_vbar_indication_offset = value;
        }
        else
        {
            WAP_DBG_ASSERT(0);
        }
    }
    else if (WPEN_CTX->hbar_indication_in_queue)
    {
        /* Update the browser content by the pen event */
        if (_GBAR(bar) == WGUI_CTX->current_horizontal_scrollbar)
        {
            WPEN_CTX->current_hbar_indication_offset = value;
        }
        else
        {
            WAP_DBG_ASSERT(0);
        }
    }
#endif  /* __MMI_TOUCH_SCREEN__ */
    widget_paint();
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetBarGetValues
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bar             [IN]        
 *  value           [OUT]         
 *  maxValue        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetBarGetValues(MsfGadgetHandle bar, int *value, int *maxValue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *value = _GBAR(bar)->value;
    *maxValue = _GBAR(bar)->max_value;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtBarSetMinPenOffsetValue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bar             [IN]        
 *  min_value       [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtBarSetMinPenOffsetValue(MsfGadgetHandle bar, int min_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _GBAR(bar)->pen_min_offset = min_value;

    return 1;
}



