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
 * widget_style.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfStyle creation/attributes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"

const MsfColor widget_transparent_color = { -1, -1, -1};


/*****************************************************************************
 * FUNCTION
 *  widget_is_transparent_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_is_transparent_color(MsfColor *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We do not allow any color value to be negative */
    return ((c->r == -1) || (c->g == -1) || (c->b == -1)) ? KAL_TRUE : KAL_FALSE;
}

/****************************************************************
 STYLE
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStyleCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  color               [?]         
 *  backgroundColor     [?]         
 *  foreground          [?]         
 *  background          [?]         
 *  lineStyle           [?]         
 *  font                [?]         
 *  textProperty        [?]         
 * RETURNS
 *  
 *****************************************************************************/
MsfStyleHandle HDIa_widgetStyleCreate(
                MSF_UINT8 modId,
                MsfColor *color,
                MsfColor *backgroundColor,
                MsfPattern *foreground,
                MsfPattern *background,
                MsfLineStyle *lineStyle,
                MsfFont *font,
                MsfTextProperty *textProperty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_style_struct *w = (widget_style_struct*) widget_create_style(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    if (color)
    {
        w->fg_color = *color;
    }
    if (backgroundColor)
    {
        w->bg_color = *backgroundColor;
    }
    else
    {
        w->bg_color = widget_transparent_color; /* cf. HDIa_widgetDrawString() */
    }
    if (foreground)
    {
        w->fg_pattern = *foreground;
    }
    if (background)
    {
        w->bg_pattern = *background;
    }
    if (lineStyle)
    {
        w->line_style = *lineStyle;
    }
    if (font)
    {
        w->font = *font;
    }
    if (textProperty)
    {
        w->text_property = *textProperty;
    }

    return (MsfStyleHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  widget_style_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfStyleHandle widget_style_copy(MSF_UINT8 modId, MsfStyleHandle src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_style_struct *w = (widget_style_struct*) widget_create_style(modId);
    widget_style_struct *old_style = _STYLE(src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(src);

    w->module_id = modId;

    w->fg_color = old_style->fg_color;
    w->bg_color = old_style->bg_color;
    w->fg_pattern = old_style->fg_pattern;
    w->bg_pattern = old_style->bg_pattern;
    w->line_style = old_style->line_style;
    w->font = old_style->font;
    w->text_property = old_style->text_property;

    return (MsfStyleHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetBrush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfBrushHandle HDIa_widgetGetBrush(MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only paintbox and image have Brush */
    /* WAP_DBG_ASSERT(IS_PAINTBOX_TYPE(handle) || IS_IMAGE_TYPE(handle)); */

    if (style == 0)
    {
        WAP_RST_ASSERT(0);
        return 0;
    }

    return (MsfBrushHandle) style;
}

/* int HDIa_widgetSetBrushProperty(MSF_UINT32 handle, MsfLineStyle* lineStyle, MsfColor* lineColor, MsfColor* fillColor, MsfImageHandle linePattern, MsfImageHandle fillPattern, int padded, MsfFont* font, MsfTextProperty* textProperty){return 0;} */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetColor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  color           [?]         
 *  background      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetColor(MSF_UINT32 msfHandle, MsfColor *color, int background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_DBG_ASSERT(0);
        return 1;
    }

    if (background)
    {
        _STYLE(style)->bg_color = *color;
    }
    else
    {
        _STYLE(style)->fg_color = *color;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetLineStyle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  lineStyle       [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetLineStyle(MSF_UINT32 msfHandle, MsfLineStyle *lineStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_DBG_ASSERT(0);
        return 1;
    }

    if (lineStyle)
    {
        _STYLE(style)->line_style = *lineStyle;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetTextProperty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle           [IN]        
 *  textProperty        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetTextProperty(MSF_UINT32 msfHandle, MsfTextProperty *textProperty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_DBG_ASSERT(0);
        return 1;
    }

    if (textProperty)
    {
        _STYLE(style)->text_property = *textProperty;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetPattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  pattern         [?]         
 *  background      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetPattern(MSF_UINT32 msfHandle, MsfPattern *pattern, int background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_DBG_ASSERT(0);
        return 1;
    }

    WAP_DBG_ASSERT(pattern->padding == MsfNoPadding);

    if (background)
    {
        _STYLE(style)->bg_pattern = *pattern;
    }
    else
    {
        _STYLE(style)->fg_pattern = *pattern;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetFont
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  font            [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetFont(MSF_UINT32 msfHandle, MsfFont *font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_DBG_ASSERT(0);
        return 1;
    }

    if (font)
    {
        _STYLE(style)->font = *font;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetFont
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  font            [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetFont(MSF_UINT32 msfHandle, MsfFont *font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_RST_ASSERT(0);
        return 1;
    }

    if (font)
    {
        *font = _STYLE(style)->font;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetColor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  color           [?]         
 *  background      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetColor(MSF_UINT32 msfHandle, MsfColor *color, int background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_RST_ASSERT(0);
        return 1;
    }

    if (background)
    {
        *color = _STYLE(style)->bg_color;
    }
    else
    {
        *color = _STYLE(style)->fg_color;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetLineStyle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle           [IN]        
 *  msfLineStyle        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetLineStyle(MSF_UINT32 msfHandle, MsfLineStyle *msfLineStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_RST_ASSERT(0);
        return 1;
    }

    *msfLineStyle = (_STYLE(style))->line_style;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetTextProperty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle           [IN]        
 *  textProperty        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetTextProperty(MSF_UINT32 msfHandle, MsfTextProperty *textProperty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_RST_ASSERT(0);
        return 1;
    }
    *textProperty = (_STYLE(style))->text_property;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetPattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  background      [IN]        
 *  pattern         [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetPattern(MSF_UINT32 msfHandle, int background, MsfPattern *pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle style = widget_get_style(msfHandle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style == 0)
    {
        WAP_RST_ASSERT(0);
        return 1;
    }

    if (background)
    {
        *pattern = (_STYLE(style))->bg_pattern;
    }
    else
    {
        *pattern = (_STYLE(style))->fg_pattern;
    }

    return 1;
}

/*
 * Create default style if it doesn't already have one
 */


/*****************************************************************************
 * FUNCTION
 *  widget_initialize_default_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_initialize_default_style(widget_style_struct *style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(style, 0, sizeof(widget_style_struct));
    style->data_type = WIDGET_STYLE_TYPE;
    style->flag = WIDGET_FLAG_STATIC | WIDGET_FLAG_RESOURCE;
    style->parent_cnt = 0;
}

/*
 * We pass a dummy style even if handle is invalid and handle it silently.
 * * The Obigo applications seem to require it implicitly.
 */


/*****************************************************************************
 * FUNCTION
 *  widget_get_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfStyleHandle widget_get_style(MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 'Static' because we pass widget_default_style to caller */
    static widget_style_struct widget_default_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!handle)
    {
        WAP_DBG_ASSERT(0);

        widget_initialize_default_style(&widget_default_style);
        return (MsfStyleHandle) & widget_default_style;
    }

    if (IS_STYLE_TYPE(handle))
    {
        ASSERT(handle);
        return (MsfStyleHandle) handle;
    }
    else if (IS_STRING_TYPE(handle))
    {
        widget_string_struct *w = _STR(handle);
        MsfStyleHandle sh = w->style;

        if (sh)
        {
            return sh;
        }
        else
        {
            sh = HDIa_widgetStyleCreate(w->module_id, 0, 0, 0, 0, 0, 0, 0);
            widget_set_attrib(w, style, sh);
            DEC_REF(sh);
        }
        return w->style;
    }
    else if (IS_PRE_STRING_TYPE(handle))
    {
        /* create a default style (testing) */
        WAP_DBG_ASSERT(0);  /* Should not happen */

        widget_initialize_default_style(&widget_default_style);
        return (MsfStyleHandle) & widget_default_style;
    }
    else if (IS_IMAGE_TYPE(handle))
    {
        widget_image_struct *w = _IMG(handle);
        MsfStyleHandle sh = w->style;

        if (sh)
        {
            return sh;
        }
        else
        {
            sh = HDIa_widgetStyleCreate(w->module_id, 0, 0, 0, 0, 0, 0, 0);
            widget_set_attrib(w, style, sh);
            DEC_REF(sh);
        }
        return w->style;
    }
    else if (IS_ICON_TYPE(handle))
    {
        widget_icon_struct *w = _ICON(handle);
        MsfStyleHandle sh = w->style;

        if (sh)
        {
            return sh;
        }
        else
        {
            sh = HDIa_widgetStyleCreate(w->module_id, 0, 0, 0, 0, 0, 0, 0);
            widget_set_attrib(w, style, sh);
            DEC_REF(sh);
        }
        return w->style;
    }
    else if (IS_WINDOW_TYPE(handle) || IS_GADGET_TYPE(handle))
    {
        widget_window_struct *w = _W(handle);
        MsfStyleHandle sh = w->style;

        if (sh)
        {
            return sh;
        }
        else
        {
            sh = HDIa_widgetStyleCreate(w->module_id, 0, 0, 0, 0, 0, 0, 0);
            widget_set_attrib(w, style, sh);
            DEC_REF(sh);
        }
        return w->style;
    }
    else
    {
        WAP_DBG_ASSERT(0);

        widget_initialize_default_style(&widget_default_style);
        return (MsfStyleHandle) & widget_default_style;
    }
}

