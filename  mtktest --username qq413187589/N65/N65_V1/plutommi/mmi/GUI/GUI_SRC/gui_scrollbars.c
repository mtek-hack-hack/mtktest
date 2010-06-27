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
 *  gui_scrollbars.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  UI component - Scrollbar & Progress Indicator
 *
 *  o Vertical scrollbar
 *  o Horizontal scrollbar 
 *  o Vertical Progress Indicator 
 *  o Horizontal Progress Indicator
 *  o Alternative Vertical Slider
 *  o Alternative Horizontal Slider
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
 *============================================================================
 ****************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#include "gui_scrollbars.h"
#include "wgui_categories_defs.h"
#include "gdi_include.h"
#include "DebugInitDef.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_util.h"

extern MMI_theme *current_MMI_theme;

MMI_BOOL gui_scrollbar_redraw_clip_enable = MMI_TRUE;
void (*gui_show_vertical_scrollbar)(vertical_scrollbar *v) = NULL;
void (*gui_vertical_scrollbar_redraw_button)(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed) = NULL;
void (*gui_show_horizontal_scrollbar)(horizontal_scrollbar *v);
void (*gui_horizontal_scrollbar_redraw_button)(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed) = NULL;

/***************************************************************************** 
 * General Scrollbar Utility Functions
 *****************************************************************************/

/* 
 * Custom-draw function for scrollbar. 
 * We do not use image because scrollbar may have different width
 */




/***************************************************************************** 
 * Vertical Scrollbar
 *****************************************************************************/

UI_vertical_scrollbar_theme *current_vertical_scrollbar_theme = NULL;

/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_current_theme
 * DESCRIPTION
 *  Applies the current theme for the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_current_theme(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = current_vertical_scrollbar_theme->focussed_bar_filler;
    v->normal_bar_filler = current_vertical_scrollbar_theme->normal_bar_filler;
    v->disabled_bar_filler = current_vertical_scrollbar_theme->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->up_button, current_vertical_scrollbar_theme->up_button_theme);
    gui_set_icon_button_BG_theme(&v->down_button, current_vertical_scrollbar_theme->down_button_theme);
    gui_set_icon_button_BG_theme(&v->scroll_button, current_vertical_scrollbar_theme->scroll_button_theme);
    gui_icon_button_set_icon(
        &v->up_button,
        current_vertical_scrollbar_theme->up_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(
        &v->down_button,
        current_vertical_scrollbar_theme->down_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(
        &v->scroll_button,
        current_vertical_scrollbar_theme->scroll_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= current_vertical_scrollbar_theme->flags;
    if (v->flags & UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT1)
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT2)
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
    }
    else
    {
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_theme
 * DESCRIPTION
 *  Applies the given theme to the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 *  t       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_theme(vertical_scrollbar *v, UI_vertical_scrollbar_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = t->focussed_bar_filler;
    v->normal_bar_filler = t->normal_bar_filler;
    v->disabled_bar_filler = t->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->up_button, t->up_button_theme);
    gui_set_icon_button_BG_theme(&v->down_button, t->down_button_theme);
    gui_set_icon_button_BG_theme(&v->scroll_button, t->scroll_button_theme);
    gui_icon_button_set_icon(&v->up_button, t->up_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(&v->down_button, t->down_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(&v->scroll_button, t->scroll_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= t->flags;
    if (v->flags & UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT1)
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT2)
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
    }
    else
    {
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_scrollbar
 * DESCRIPTION
 *  Creates a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the vertical scrollbar (smaller)
 *  height      [IN]        Is the height of the vertical scrollbar (larger)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_scrollbar(vertical_scrollbar *v, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
    S32 button_height;
#elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
    S32 button_height;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->width = width;
    v->height = height;
    v->value = 0;
    v->range = 0;
    v->flags = 0;

#if defined(UI_SCROLLBAR_STYLE_1)
    gui_create_icon_button(
        &v->up_button,
        v->x,
        v->y,
        v->width,
        v->width,
        current_vertical_scrollbar_theme->up_button_icon);
    gui_create_icon_button(
        &v->down_button,
        v->x,
        v->y + v->height - v->width,
        v->width,
        v->width,
        current_vertical_scrollbar_theme->down_button_icon);
#elif defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
    button_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_UP, v->width);
    if (button_height * 2 >= height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT)
    {
        button_height = 0;
    }
    gui_create_icon_button(
        &v->up_button,
        v->x,
        v->y,
        v->width,
        button_height,
        current_vertical_scrollbar_theme->up_button_icon);
    gui_create_icon_button(
        &v->down_button,
        v->x,
        v->y + v->height - button_height,
        v->width,
        button_height,
        current_vertical_scrollbar_theme->down_button_icon);
#elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
#if defined (__MMI_MAINLCD_128X160__)
    button_height = v->width + 2;
#else
    button_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2 + 3;
#endif
    if (button_height * 2 >= height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT)
    {
        button_height = 0;
    }
    gui_create_icon_button(
        &v->up_button,
        v->x,
        v->y,
        v->width,
        button_height,
        current_vertical_scrollbar_theme->up_button_icon);
    gui_create_icon_button(
        &v->down_button,
        v->x,
        v->y + v->height - button_height,
        v->width,
        button_height,
        current_vertical_scrollbar_theme->down_button_icon);
#endif 
    
    /* height of scroll button is set later */
    gui_create_icon_button(
        &v->scroll_button,
        v->x,
        v->y + v->up_button.height,
        v->width,
        v->width,
        current_vertical_scrollbar_theme->scroll_button_icon);
    gui_set_vertical_scrollbar_current_theme(v);

#if defined(UI_SCROLLBAR_STYLE_1)
    gui_show_vertical_scrollbar = gui_show_vertical_scrollbar_style_1;
    gui_vertical_scrollbar_redraw_button = gui_vertical_scrollbar_redraw_button_style_1;
#elif defined(UI_SCROLLBAR_STYLE_2)
    gui_show_vertical_scrollbar = gui_show_vertical_scrollbar_style_2;
    gui_vertical_scrollbar_redraw_button = gui_vertical_scrollbar_redraw_button_style_2;
#elif defined(UI_SCROLLBAR_STYLE_3)
    gui_show_vertical_scrollbar = gui_show_vertical_scrollbar_style_3;
    gui_vertical_scrollbar_redraw_button = gui_vertical_scrollbar_redraw_button_style_3;
#elif defined(UI_SCROLLBAR_STYLE_4)
    gui_show_vertical_scrollbar = gui_show_vertical_scrollbar_style_4;
    gui_vertical_scrollbar_redraw_button = gui_vertical_scrollbar_redraw_button_style_4;
#elif defined(UI_SCROLLBAR_STYLE_5)
    gui_show_vertical_scrollbar = gui_show_vertical_scrollbar_style_5;
    gui_vertical_scrollbar_redraw_button = gui_vertical_scrollbar_redraw_button_style_5;
#endif /* UI_SCROLLBAR_STYLE_1 */

#ifdef __MMI_TOUCH_SCREEN__
    v->min_pen_offset = 1;
    v->pen_self_scroll = 1;
    memset(&(v->pen_state), 0, sizeof(gui_scrollbar_pen_state_struct));
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_range
 * DESCRIPTION
 *  Sets the range of a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  range       [IN]        (positive value: Example: Total number of items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_range(vertical_scrollbar *v, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    v->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_value
 * DESCRIPTION
 *  Sets the value of a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  value       [IN]        (positive value: Example: First displayed item in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_value(vertical_scrollbar *v, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    v->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_scale
 * DESCRIPTION
 *  Sets the scale of a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  scale       [IN]        (positive value: Example: Number of displayed items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_scale(vertical_scrollbar *v, S32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scale < 0)
    {
        scale = 0;
    }
    v->scale = (U32) scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_vertical_scrollbar
 * DESCRIPTION
 *  Moves the scrollbar to a differnt location
 * PARAMETERS
 *  v       [IN/OUT]    Is the vertical scrollbar object
 *  x       [IN]        Is the left-top corner of the scrollbar
 *  y       [IN]        Is the left-top corner of the scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_vertical_scrollbar(vertical_scrollbar *v, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->up_button.x = x;
    v->down_button.x = x;
    v->up_button.y = y;
    v->down_button.y = v->y + v->height - v->down_button.height;
    v->scroll_button.x = x;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_vertical_scrollbar
 * DESCRIPTION
 *  Changes the size of a scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_vertical_scrollbar(vertical_scrollbar *v, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
    S32 button_height;
#elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
    S32 button_height;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->width = width;
    v->height = height;
    v->up_button.width = width;
    v->down_button.width = width;
#if defined(UI_SCROLLBAR_STYLE_1)
    v->up_button.height = width;
    v->down_button.height = width;
#elif defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
    button_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_UP, v->width);
    if (button_height * 2 >= height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT)
    {
        button_height = 0;
    }
    v->up_button.height = button_height;
    v->down_button.height = button_height;
#elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
#if defined (__MMI_MAINLCD_128X160__)
    button_height = v->width + 2;
#else
    button_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2 + 3;
#endif
    if (button_height * 2 >= height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT)
    {
        button_height = 0;
    }
    v->up_button.height = button_height;
    v->down_button.height = button_height;
#endif 
    v->up_button.x = v->x;
    v->down_button.x = v->x;
    v->up_button.y = v->y;
    v->down_button.y = v->y + v->height - v->down_button.height;
    v->scroll_button.x = v->x;
    v->scroll_button.width = v->width;
}



#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sbutton_pos         [IN]        
 *  remain_space        [IN]        
 *  range               [IN]        
 *  scale               [IN]        
 *  new_value           [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_translate_pen_position(
                S32 sbutton_pos /* relative position */ ,
                S16 remain_space,
                S32 range,
                S32 scale,
                U32 *new_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 r = range - scale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r < 0)
    {
        r = 0;
    }

    if (r == 0 || sbutton_pos <= 0)
    {
        *new_value = 0;
    }
    else if (sbutton_pos > remain_space)
    {
        *new_value = r;
    }
    else
    {
        /* 
         * sbutton_pos = round((remain_space * value) / r)
         * 
         *       ==> 
         *
         * new_value is round(sbutton_pos * r / remain_space) or +1 or -1
         * 
         */
        S32 new_sbutton_pos;
        S32 margin; /* 1/2 of jump distance when value is incremented by 1 */

        *new_value = (S32) ((S64) (sbutton_pos * r + remain_space - 1) / remain_space);

        margin = (remain_space / r) / 2;

        /* In case that (scale/range) is large, move within +-margin  */
        if (margin > 3 /* random-chosen magic number! */ )
        {
            new_sbutton_pos = (S32) ((S64) remain_space * (*new_value) / r);

            if (*new_value > 0 && sbutton_pos < new_sbutton_pos - margin)
            {
                (*new_value)--;
            }
            else if (*new_value < r && sbutton_pos > new_sbutton_pos + margin)
            {
                (*new_value)++;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_translate_pen_more
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value               [IN]        
 *  range               [IN]        
 *  scale               [IN]        
 *  diff                [IN]        
 *  scrollbar_event     [OUT]         
 *  scrollbar_param     [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_translate_pen_more(
                U32 value,
                U32 range,
                U32 scale,
                int diff,
                gui_scrollbar_pen_enum *scrollbar_event,
                gui_pen_event_param_struct *scrollbar_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int new_value = value + diff;
    int r = ((int)range - (int)scale);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r < 0)
    {
        r = 0;
    }

    if (new_value > r)
    {
        new_value = r;
    }

    if (new_value != value)
    {
        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, new_value);
    }
    else
    {
        *scrollbar_event = GUI_SCROLLBAR_PEN_NONE;
        GUI_PEN_EVENT_PARAM_SET_VOID(scrollbar_param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_translate_pen_less
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value               [IN]        
 *  diff                [IN]        
 *  scrollbar_event     [OUT]         
 *  scrollbar_param     [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_translate_pen_less(
                U32 value,
                int diff,
                gui_scrollbar_pen_enum *scrollbar_event,
                gui_pen_event_param_struct *scrollbar_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int new_value = value - diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_value < 0)
    {
        new_value = 0;
    }

    if (new_value != value)
    {
        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, new_value);
    }
    else
    {
        *scrollbar_event = GUI_SCROLLBAR_PEN_NONE;
        GUI_PEN_EVENT_PARAM_SET_VOID(scrollbar_param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_redraw_vertical_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_redraw_vertical_scrollbar(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_vertical_scrollbar(v);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(v->x, v->y, v->x + v->width - 1, v->y + v->height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_button1_show_clicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_vertical_scrollbar_button1_show_clicked(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(v->up_button.flags & UI_BUTTON_SHIFT_BUTTON1))
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_vertical_scrollbar(v);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_button1_show_unclicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_vertical_scrollbar_button1_show_unclicked(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->up_button.flags & UI_BUTTON_SHIFT_BUTTON1)
    {
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_vertical_scrollbar(v);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_button2_show_clicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_vertical_scrollbar_button2_show_clicked(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(v->down_button.flags & UI_BUTTON_SHIFT_BUTTON1))
    {
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_vertical_scrollbar(v);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_button2_show_unclicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_vertical_scrollbar_button2_show_unclicked(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->down_button.flags & UI_BUTTON_SHIFT_BUTTON1)
    {
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_vertical_scrollbar(v);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_set_minimum_pen_offset
 * DESCRIPTION
 *  Set the minimum scrolling offset in scrollbar.
 *  
 *  Used in GUI_SCROLLBAR_PEN_STATE_AREA1, GUI_SCROLLBAR_PEN_STATE_AREA2,
 *  GUI_SCROLLBAR_PEN_STATE_BUTTON1, GUI_SCROLLBAR_PEN_STATE_BUTTON2
 * PARAMETERS
 *  v               [IN/OUT]            Is the vertical scrollbar object
 *  min_offset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_set_minimum_pen_offset(vertical_scrollbar *v, S32 min_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->min_pen_offset = min_offset;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_set_pen_self_scroll
 * DESCRIPTION
 *  Setup whether the scrollbar is redrawn when it is scrolled by pen.
 *  If 'enable' is MMI_FALSE, the scrollbar is scrolled by its parent GUI component.
 * PARAMETERS
 *  v           [IN/OUT]            Is the horizontal scrollbar object
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_set_pen_self_scroll(vertical_scrollbar *v, BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        v->pen_self_scroll = 1;
    }
    else
    {
        v->pen_self_scroll = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_reconfigure_pen_value
 * DESCRIPTION
 *  Reconfigure scrollbar position if it is  scrolled passively by parent components
 *  
 *  Take inline editor as example, if gui_vertical_scrollbar_translate_pen_event() returns 1
 *  for GUI_SCROLLBAR_PEN_JUMP_TO_I, Inline editor might set scrollbar value to 0 instead of 1.
 *  As a result, scroll button might be moved away from the original pen down position,
 *  and this function should be used to fix internal scrollbar states.
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_reconfigure_pen_value(vertical_scrollbar *v, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_state_struct *pen_state;
    U32 new_value;
    S32 sbutton_y1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x);
    pen_state = &v->pen_state;

    if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
    {
        sbutton_y1 = v->scroll_button.y;

        gui_scrollbar_translate_pen_position(
            pen_state->initial_sbutton_pos + (y - pen_state->initial_pen_down_pos),
            pen_state->remain_space,
            v->range,
            v->scale,
            &new_value);

        if ((v->value < pen_state->previous_value && new_value > v->value) ||
            (v->value > pen_state->previous_value && new_value < v->value))
        {
            /* Note: y might not be on scroll button! */
            pen_state->initial_pen_down_pos = y;
            if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
            {
                pen_state->initial_sbutton_pos = (S16) (sbutton_y1 - v->y);
            }
            else
            {
                pen_state->initial_sbutton_pos = (S16) (sbutton_y1 - v->y - v->up_button.height);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v                   [IN/OUT]         
 *  pen_event           [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  scrollbar_event     [OUT]         
 *  scrollbar_param     [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_vertical_scrollbar_translate_pen_event(
        vertical_scrollbar *v,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_scrollbar_pen_enum *scrollbar_event,
        gui_pen_event_param_struct *scrollbar_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * If the Up/Down button is pressed or released, we need to gui_redraw_vertical_scrollbar()
     * even if GUI_SCROLLBAR_PEN_JUMP_TO_I is also returned.
     *
     * The reason is that parent component might discard the scrollbar event and not redraw itself.
     */

    BOOL ret;
    S32 sbutton_y1, sbutton_y2, up_button_y2, down_button_y1;
    gui_scrollbar_pen_state_struct *pen_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &v->pen_state;
    ret = MMI_TRUE;
    sbutton_y1 = v->scroll_button.y;
    sbutton_y2 = sbutton_y1 + v->scroll_button.height - 1;
    up_button_y2 = v->up_button.y + v->up_button.height - 1;
    down_button_y1 = v->down_button.y;

    *scrollbar_event = GUI_SCROLLBAR_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(scrollbar_param);

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
            {
                pen_state->initial_pen_down_pos = y;
                if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
                {
                    pen_state->initial_sbutton_pos = (S16) (sbutton_y1 - v->y);
                }
                else
                {
                    pen_state->initial_sbutton_pos = (S16) (sbutton_y1 - v->y - v->up_button.height);
                }
                pen_state->original_value = v->value;

                if (y <= up_button_y2)
                {
                    gui_vertical_scrollbar_button1_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1;
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
                else if (y >= down_button_y1)
                {
                    gui_vertical_scrollbar_button2_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2;
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
                else if (y >= sbutton_y1 && y <= sbutton_y2)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON;
                }
                else if (y < sbutton_y1)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1;
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
                else
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2;
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else
            {
                ret = MMI_FALSE;
                pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                gui_scrollbar_translate_pen_more(
                    v->value,
                    v->range,
                    v->scale,
                    v->min_pen_offset,
                    scrollbar_event,
                    scrollbar_param);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (y < sbutton_y1))
                {
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
                else
                {
                    /* Scroll button is moved to pen position */
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (y > sbutton_y2))
                {
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
                else
                {
                    /* Scroll button is moved to pen position */
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE;
                }
            }
            break;

        case MMI_PEN_EVENT_UP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_MOVE:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    gui_vertical_scrollbar_button1_show_unclicked(v);
                }
                else if (!PEN_CHECK_BOUND
                         (x, y, v->up_button.x, v->up_button.y, v->up_button.width, v->up_button.height))
                {
                    gui_vertical_scrollbar_button1_show_unclicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Do nothing */
                    MMI_DBG_ASSERT(!(v->up_button.flags & UI_BUTTON_SHIFT_BUTTON1));
                }
                else if (PEN_CHECK_BOUND(x, y, v->up_button.x, v->up_button.y, v->up_button.width, v->up_button.height))
                {
                    gui_vertical_scrollbar_button1_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1;
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    gui_vertical_scrollbar_button2_show_unclicked(v);
                }
                else if (!PEN_CHECK_BOUND
                         (x, y, v->down_button.x, v->down_button.y, v->down_button.width, v->down_button.height))
                {
                    gui_vertical_scrollbar_button2_show_unclicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Do nothing */
                    MMI_DBG_ASSERT(!(v->down_button.flags & UI_BUTTON_SHIFT_BUTTON1));
                }
                else if (PEN_CHECK_BOUND
                         (x, y, v->down_button.x, v->down_button.y, v->down_button.width, v->down_button.height))
                {
                    gui_vertical_scrollbar_button2_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2;
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (y < sbutton_y1))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1;
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                if (!PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) || !(y < sbutton_y1))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE;
                }
            }
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (y > sbutton_y2))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2;
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                if (!PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) || !(y > sbutton_y2))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
            {
                if (PEN_ABS(x, v->x) > GUI_SCROLLBAR_VALID_RANGE)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE;
                    /* Reset to original position */
                    *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)pen_state->original_value);
                }
                else
                {
                    U32 new_value;

                    gui_scrollbar_translate_pen_position(
                        pen_state->initial_sbutton_pos + (y - pen_state->initial_pen_down_pos),
                        pen_state->remain_space,
                        v->range,
                        v->scale,
                        &new_value);
                    if (new_value != v->value)
                    {
                        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)new_value);
                    }
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE)
            {
                if (PEN_ABS(x, v->x) < GUI_SCROLLBAR_VALID_RANGE)
                {
                    U32 new_value;

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON;

                    gui_scrollbar_translate_pen_position(
                        pen_state->initial_sbutton_pos + (y - pen_state->initial_pen_down_pos),
                        pen_state->remain_space,
                        v->range,
                        v->scale,
                        &new_value);
                    if (new_value != v->value)
                    {
                        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)new_value);
                    }
                }
            }

            if (pen_event == MMI_PEN_EVENT_UP)
            {
                pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            }

            break;

        case MMI_PEN_EVENT_ABORT:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
            {
                /* Reset to original position */
                *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)pen_state->original_value);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                gui_vertical_scrollbar_button1_show_unclicked(v);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                gui_vertical_scrollbar_button2_show_unclicked(v);
            }

            pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            break;

        default:
            MMI_ASSERT(0);
    }

    if (ret)
    {
        /*
         * Scrollbar does not change its value. Instead, parent components should change the value
         * * if GUI_SCROLLBAR_PEN_JUMP_TO_I is returned.
         */
        pen_state->previous_value = v->value;
    }

    if (ret && v->pen_self_scroll && *scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
    {
        v->value = scrollbar_param->_u.i;
        gui_redraw_vertical_scrollbar(v);
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/***************************************************************************** 
 * Horizontal Scrollbar
 *****************************************************************************/

UI_horizontal_scrollbar_theme *current_horizontal_scrollbar_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_current_theme
 * DESCRIPTION
 *  Applies the current theme for the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_current_theme(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = current_horizontal_scrollbar_theme->focussed_bar_filler;
    v->normal_bar_filler = current_horizontal_scrollbar_theme->normal_bar_filler;
    v->disabled_bar_filler = current_horizontal_scrollbar_theme->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->left_button, current_horizontal_scrollbar_theme->left_button_theme);
    gui_set_icon_button_BG_theme(&v->right_button, current_horizontal_scrollbar_theme->right_button_theme);
    gui_set_icon_button_BG_theme(&v->scroll_button, current_horizontal_scrollbar_theme->scroll_button_theme);
    gui_icon_button_set_icon(
        &v->left_button,
        current_horizontal_scrollbar_theme->left_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(
        &v->right_button,
        current_horizontal_scrollbar_theme->right_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(
        &v->scroll_button,
        current_horizontal_scrollbar_theme->scroll_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= current_horizontal_scrollbar_theme->flags;
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT1)
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT2)
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
    }
    else
    {
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_theme
 * DESCRIPTION
 *  Applies the given theme to the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the horizontal scrollbar object
 *  t       [IN]            Horizontal scrollbar theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_theme(horizontal_scrollbar *v, UI_horizontal_scrollbar_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = t->focussed_bar_filler;
    v->normal_bar_filler = t->normal_bar_filler;
    v->disabled_bar_filler = t->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->left_button, t->left_button_theme);
    gui_set_icon_button_BG_theme(&v->right_button, t->right_button_theme);
    gui_set_icon_button_BG_theme(&v->scroll_button, t->scroll_button_theme);
    gui_icon_button_set_icon(&v->left_button, t->left_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(&v->right_button, t->right_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(&v->scroll_button, t->scroll_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= t->flags;
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT1)
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT2)
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
    }
    else
    {
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_scrollbar
 * DESCRIPTION
 *  Creates a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the horizontal scrollbar (larger)
 *  height      [IN]        Is the height of the horizontal scrollbar (smaller)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_scrollbar(horizontal_scrollbar *v, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
    S32 button_width;
#elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
    S32 button_width;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->width = width;
    v->height = height;
    v->value = 0;
    v->range = 0;
    v->flags = 0;

#if defined(UI_SCROLLBAR_STYLE_1)
    gui_create_icon_button(
        &v->left_button,
        v->x,
        v->y,
        v->height,
        v->height,
        current_horizontal_scrollbar_theme->left_button_icon);
    gui_create_icon_button(
        &v->right_button,
        v->x + v->width - v->height,
        v->y,
        v->height,
        v->height,
        current_horizontal_scrollbar_theme->right_button_icon);
#elif defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
    button_width = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_LEFT, v->height);
    if (button_width * 2 >= width)
    {
        button_width = 0;
    }
    gui_create_icon_button(
        &v->left_button,
        v->x,
        v->y,
        button_width,
        v->height,
        current_horizontal_scrollbar_theme->left_button_icon);
    gui_create_icon_button(
        &v->right_button,
        v->x + v->width - button_width,
        v->y,
        button_width,
        v->height,
        current_horizontal_scrollbar_theme->right_button_icon);
#elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
    #if defined (__MMI_MAINLCD_128X160__)
        button_width = v->height + 2;
    #else
    button_width = v->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2 + 3;
    #endif
    if (button_width * 2 >= width)
    {
        button_width = 0;
    }
    gui_create_icon_button(
        &v->left_button,
        v->x,
        v->y,
        button_width,
        v->height,
        current_horizontal_scrollbar_theme->left_button_icon);
    gui_create_icon_button(
        &v->right_button,
        v->x + v->width - button_width,
        v->y,
        button_width,
        v->height,
        current_horizontal_scrollbar_theme->right_button_icon);
#endif 
    /* width of scroll button is set later */
    gui_create_icon_button(
        &v->scroll_button,
        v->x + v->left_button.width,
        v->y,
        v->height,
        v->height,
        current_horizontal_scrollbar_theme->scroll_button_icon);
    gui_set_horizontal_scrollbar_current_theme(v);

    #if defined(UI_SCROLLBAR_STYLE_1)
        gui_show_horizontal_scrollbar = gui_show_horizontal_scrollbar_style_1;
        gui_horizontal_scrollbar_redraw_button = gui_horizontal_scrollbar_redraw_button_style_1;
    #elif defined(UI_SCROLLBAR_STYLE_2)
        gui_show_horizontal_scrollbar = gui_show_horizontal_scrollbar_style_2;
        gui_horizontal_scrollbar_redraw_button = gui_horizontal_scrollbar_redraw_button_style_2;
    #elif defined(UI_SCROLLBAR_STYLE_3)
        gui_show_horizontal_scrollbar = gui_show_horizontal_scrollbar_style_3;
        gui_horizontal_scrollbar_redraw_button = gui_horizontal_scrollbar_redraw_button_style_3;
    #elif defined(UI_SCROLLBAR_STYLE_4)
        gui_show_horizontal_scrollbar = gui_show_horizontal_scrollbar_style_4;
        gui_horizontal_scrollbar_redraw_button = gui_horizontal_scrollbar_redraw_button_style_4;
    #elif defined(UI_SCROLLBAR_STYLE_5)
        gui_show_horizontal_scrollbar = gui_show_horizontal_scrollbar_style_5;
        gui_horizontal_scrollbar_redraw_button = gui_horizontal_scrollbar_redraw_button_style_5;
    #endif /* UI_SCROLLBAR_STYLE_1 */
#ifdef __MMI_TOUCH_SCREEN__
    v->min_pen_offset = 1;
    v->pen_self_scroll = 1;
    memset(&(v->pen_state), 0, sizeof(gui_scrollbar_pen_state_struct));
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_range
 * DESCRIPTION
 *  Sets the range of a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  range       [IN]        (positive value: Example: Total number of items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_range(horizontal_scrollbar *v, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    v->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_value
 * DESCRIPTION
 *  Sets the value of a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  value       [IN]        (positive value: Example: First displayed item in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_value(horizontal_scrollbar *v, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    v->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_scale
 * DESCRIPTION
 *  Sets the scale of a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  scale       [IN]        (positive value: Example: Number of displayed items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_scale(horizontal_scrollbar *v, S32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scale < 0)
    {
        scale = 0;
    }
    v->scale = (U32) scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_horizontal_scrollbar
 * DESCRIPTION
 *  Moves the scrollbar to a differnt location
 * PARAMETERS
 *  v       [IN/OUT]    Is the horizontal scrollbar object
 *  x       [IN]        Is the left-top corner of the scrollbar
 *  y       [IN]        Is the left-top corner of the scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_horizontal_scrollbar(horizontal_scrollbar *v, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->left_button.x = x;
    v->right_button.x = v->x + v->width - v->right_button.width;
    v->left_button.y = y;
    v->right_button.y = y;
    v->scroll_button.x = x = v->x + v->left_button.width;
    v->scroll_button.y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_horizontal_scrollbar
 * DESCRIPTION
 *  Changes the size of a scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_horizontal_scrollbar(horizontal_scrollbar *v, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
    S32 button_width;
#elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
    S32 button_width;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->width = width;
    v->height = height;
    v->left_button.height = height;
    v->right_button.height = height;
#if defined(UI_SCROLLBAR_STYLE_1)
    v->left_button.width = height;
    v->right_button.width = height;
#elif defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
    button_width = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_LEFT, v->height);
    if (button_width * 2 >= width)
    {
        button_width = 0;
    }
    v->left_button.width = button_width;
    v->right_button.width = button_width;
#elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
    #if defined (__MMI_MAINLCD_128X160__)
        button_width = v->height + 2;
    #else
    button_width = v->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2 + 3;
    #endif
    if (button_width * 2 >= width)
    {
        button_width = 0;
    }
    v->left_button.width = button_width;
    v->right_button.width = button_width;
#endif 
    v->left_button.x = v->x;
    v->right_button.x = v->x + v->width - v->right_button.width;
    v->left_button.y = v->y;
    v->right_button.y = v->y;
    v->scroll_button.y = v->y;
    v->scroll_button.height = v->height;
}


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_redraw_horizontal_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_redraw_horizontal_scrollbar(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_horizontal_scrollbar(v);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(v->x, v->y, v->x + v->width - 1, v->y + v->height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_button1_show_clicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_scrollbar_button1_show_clicked(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(v->left_button.flags & UI_BUTTON_SHIFT_BUTTON1))
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_horizontal_scrollbar(v);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_button1_show_unclicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_scrollbar_button1_show_unclicked(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->left_button.flags & UI_BUTTON_SHIFT_BUTTON1)
    {
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_horizontal_scrollbar(v);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_button2_show_clicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_scrollbar_button2_show_clicked(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(v->right_button.flags & UI_BUTTON_SHIFT_BUTTON1))
    {
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_horizontal_scrollbar(v);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_button2_show_unclicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_scrollbar_button2_show_unclicked(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->right_button.flags & UI_BUTTON_SHIFT_BUTTON1)
    {
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_horizontal_scrollbar(v);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_set_minimum_pen_offset
 * DESCRIPTION
 *  Set the minimum scrolling offset in scrollbar.
 *  
 *  Used in GUI_SCROLLBAR_PEN_STATE_AREA1, GUI_SCROLLBAR_PEN_STATE_AREA2,
 *  GUI_SCROLLBAR_PEN_STATE_BUTTON1, GUI_SCROLLBAR_PEN_STATE_BUTTON2
 * PARAMETERS
 *  v               [IN/OUT]    Is the horizontal scrollbar object
 *  min_offset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_set_minimum_pen_offset(horizontal_scrollbar *v, S32 min_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->min_pen_offset = min_offset;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_set_pen_self_scroll
 * DESCRIPTION
 *  Setup whether the scrollbar is redrawn when it is scrolled by pen.
 *  If 'enable' is MMI_FALSE, the scrollbar is scrolled by its parent GUI component.
 * PARAMETERS
 *  h           [IN/OUT]        Is the horizontal scrollbar object
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_set_pen_self_scroll(horizontal_scrollbar *h, BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        h->pen_self_scroll = 1;
    }
    else
    {
        h->pen_self_scroll = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_reconfigure_pen_value
 * DESCRIPTION
 *  Reconfigure scrollbar position if it is  scrolled passively by parent components
 *  
 *  Take inline editor as example, if gui_horizontal_scrollbar_translate_pen_event() returns 1
 *  for GUI_SCROLLBAR_PEN_JUMP_TO_I, Inline editor might set scrollbar value to 0 instead of 1.
 *  As a result, scroll button might be moved away from the original pen down position,
 *  and this function should be used to fix internal scrollbar states.
 * PARAMETERS
 *  v       [IN/OUT]    Is the horizontal scrollbar object
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_reconfigure_pen_value(horizontal_scrollbar *v, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_state_struct *pen_state;
    U32 new_value;
    S32 sbutton_x1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(y);
    pen_state = &v->pen_state;

    if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
    {
        sbutton_x1 = v->scroll_button.x;

        gui_scrollbar_translate_pen_position(
            pen_state->initial_sbutton_pos + (x - pen_state->initial_pen_down_pos),
            pen_state->remain_space,
            v->range,
            v->scale,
            &new_value);

        if ((v->value < pen_state->previous_value && new_value > v->value) ||
            (v->value > pen_state->previous_value && new_value < v->value))
        {
            /* Note: x might not be on scroll button! */
            pen_state->initial_pen_down_pos = x;
            if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
            {
                pen_state->initial_sbutton_pos = (S16) (sbutton_x1 - v->x);
            }
            else
            {
                pen_state->initial_sbutton_pos = (S16) (sbutton_x1 - v->x - v->left_button.width);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v                   [IN/OUT]         
 *  pen_event           [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  scrollbar_event     [OUT]         
 *  scrollbar_param     [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_horizontal_scrollbar_translate_pen_event(
        horizontal_scrollbar *v,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_scrollbar_pen_enum *scrollbar_event,
        gui_pen_event_param_struct *scrollbar_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * If the Left/Right button is pressed or released, we need to gui_redraw_horizontal_scrollbar()
     * even if GUI_SCROLLBAR_PEN_JUMP_TO_I is also returned.
     *
     * The reason is that parent component might discard the scrollbar event and not redraw itself.
     */

    BOOL ret;
    S32 sbutton_x1, sbutton_x2, left_button_x2, right_button_x1;
    gui_scrollbar_pen_state_struct *pen_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &v->pen_state;
    ret = MMI_TRUE;
    sbutton_x1 = v->scroll_button.x;
    sbutton_x2 = sbutton_x1 + v->scroll_button.width - 1;
    left_button_x2 = v->left_button.x + v->left_button.width - 1;
    right_button_x1 = v->right_button.x;

    *scrollbar_event = GUI_SCROLLBAR_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(scrollbar_param);

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
            {
                pen_state->initial_pen_down_pos = x;
                if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
                {
                    pen_state->initial_sbutton_pos = (S16) (sbutton_x1 - v->x);
                }
                else
                {
                    pen_state->initial_sbutton_pos = (S16) (sbutton_x1 - v->x - v->left_button.width);
                }
                pen_state->original_value = v->value;

                if (x <= left_button_x2)
                {
                    gui_horizontal_scrollbar_button1_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1;
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
                else if (x >= right_button_x1)
                {
                    gui_horizontal_scrollbar_button2_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2;
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
                else if (x >= sbutton_x1 && x <= sbutton_x2)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON;
                }
                else if (x < sbutton_x1)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1;
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
                else
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2;
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else
            {
                ret = MMI_FALSE;
                pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                gui_scrollbar_translate_pen_more(
                    v->value,
                    v->range,
                    v->scale,
                    v->min_pen_offset,
                    scrollbar_event,
                    scrollbar_param);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (x < sbutton_x1))
                {
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
                else
                {
                    /* Scroll button is moved to pen position */
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (x > sbutton_x2))
                {
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
                else
                {
                    /* Scroll button is moved to pen position */
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE;
                }
            }
            break;

        case MMI_PEN_EVENT_UP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_MOVE:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    gui_horizontal_scrollbar_button1_show_unclicked(v);
                }
                else if (!PEN_CHECK_BOUND
                         (x, y, v->left_button.x, v->left_button.y, v->left_button.width, v->left_button.height))
                {
                    gui_horizontal_scrollbar_button1_show_unclicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Do nothing */
                    MMI_DBG_ASSERT(!(v->left_button.flags & UI_BUTTON_SHIFT_BUTTON1));
                }
                else if (PEN_CHECK_BOUND
                         (x, y, v->left_button.x, v->left_button.y, v->left_button.width, v->left_button.height))
                {
                    gui_horizontal_scrollbar_button1_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1;
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    gui_horizontal_scrollbar_button2_show_unclicked(v);
                }
                else if (!PEN_CHECK_BOUND
                         (x, y, v->right_button.x, v->right_button.y, v->right_button.width, v->right_button.height))
                {
                    gui_horizontal_scrollbar_button2_show_unclicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Do nothing */
                    MMI_DBG_ASSERT(!(v->right_button.flags & UI_BUTTON_SHIFT_BUTTON1));
                }
                else if (PEN_CHECK_BOUND
                         (x, y, v->right_button.x, v->right_button.y, v->right_button.width, v->right_button.height))
                {
                    gui_horizontal_scrollbar_button2_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2;
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (x < sbutton_x1))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1;
                    gui_scrollbar_translate_pen_less(v->value, v->min_pen_offset, scrollbar_event, scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                if (!PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) || !(x < sbutton_x1))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE;
                }
            }
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (x > sbutton_x2))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2;
                    gui_scrollbar_translate_pen_more(
                        v->value,
                        v->range,
                        v->scale,
                        v->min_pen_offset,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                if (!PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) || !(x > sbutton_x2))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
            {
                if (PEN_ABS(y, v->y) > GUI_SCROLLBAR_VALID_RANGE)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE;
                    /* Reset to original position */
                    *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)pen_state->original_value);
                }
                else
                {
                    U32 new_value;

                    gui_scrollbar_translate_pen_position(
                        pen_state->initial_sbutton_pos + (x - pen_state->initial_pen_down_pos),
                        pen_state->remain_space,
                        v->range,
                        v->scale,
                        &new_value);
                    if (new_value != v->value)
                    {
                        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)new_value);
                    }
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE)
            {
                if (PEN_ABS(y, v->y) < GUI_SCROLLBAR_VALID_RANGE)
                {
                    U32 new_value;

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON;

                    gui_scrollbar_translate_pen_position(
                        pen_state->initial_sbutton_pos + (x - pen_state->initial_pen_down_pos),
                        pen_state->remain_space,
                        v->range,
                        v->scale,
                        &new_value);
                    if (new_value != v->value)
                    {
                        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)new_value);
                    }
                }
            }

            if (pen_event == MMI_PEN_EVENT_UP)
            {
                pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            }

            break;

        case MMI_PEN_EVENT_ABORT:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
            {
                /* Reset to original position */
                *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)pen_state->original_value);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                gui_horizontal_scrollbar_button1_show_unclicked(v);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                gui_horizontal_scrollbar_button2_show_unclicked(v);
            }

            pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            break;

        default:
            MMI_ASSERT(0);
    }

    if (ret)
    {
        /*
         * Scrollbar does not change its value. Instead, parent components should change the value
         * * if GUI_SCROLLBAR_PEN_JUMP_TO_I is returned.
         */
        pen_state->previous_value = v->value;
    }

    if (ret && v->pen_self_scroll && *scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
    {
        v->value = scrollbar_param->_u.i;
        gui_redraw_horizontal_scrollbar(v);
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_enable_scrollbar_redraw_clip
 * DESCRIPTION
 *  enabel scrollbar self redraw clip
 * PARAMETERS
 *  enable      [IN]        enable or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_enable_scrollbar_redraw_clip(MMI_BOOL enable)
{
    gui_scrollbar_redraw_clip_enable = enable;
}


/***************************************************************************** 
 * Horizontal Progress Indicator
 *****************************************************************************/

UI_horizontal_progress_indicator_theme *current_horizontal_progress_indicator_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_progress_indicator_theme
 * DESCRIPTION
 *  Applies the current theme to the progress indicator object
 * PARAMETERS
 *  pi      [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_progress_indicator_theme(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->flags = current_horizontal_progress_indicator_theme->flags;
    pi->background_filler = current_horizontal_progress_indicator_theme->background_filler;
    pi->foreground_filler = current_horizontal_progress_indicator_theme->foreground_filler;
    pi->n_fillers = current_horizontal_progress_indicator_theme->n_fillers;
    pi->percentages = current_horizontal_progress_indicator_theme->percentages;
    pi->block_width = current_horizontal_progress_indicator_theme->block_width;
    pi->block_gap = current_horizontal_progress_indicator_theme->block_gap;
    pi->border_gap = current_horizontal_progress_indicator_theme->border_gap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_progress_indicator
 * DESCRIPTION
 *  creates a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object (pre-allocated)
 *  x           [IN]        Left-top corner
 *  y           [IN]        Left-top corner
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_progress_indicator(horizontal_progress_indicator *pi, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->x = x;
    pi->y = y;
    pi->width = width;
    pi->height = height;
    gui_set_horizontal_progress_indicator_theme(pi);
    pi->range = 100;
    pi->value = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_progress_indicator_range
 * DESCRIPTION
 *  Sets the range of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 *  range       [IN]        Is the range (positive number Ex: Available text length in an inputbox)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_progress_indicator_range(horizontal_progress_indicator *pi, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    pi->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_progress_indicator_value
 * DESCRIPTION
 *  Sets the value of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 *  value       [IN]        Is the value (positive number Ex: current text length in an inputbox)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_progress_indicator_value(horizontal_progress_indicator *pi, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    pi->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_horizontal_progress_indicator
 * DESCRIPTION
 *  Displays a horizontal progress indicator
 * PARAMETERS
 *  pi      [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_progress_indicator(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 ax1, ay1, ax2, ay2;
    S32 fx1, fy1, fx2, fy2;
    S32 fill_width, total_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = pi->x;
    y1 = pi->y;
    x2 = x1 + pi->width;
    y2 = y1 + pi->height;
    ax1 = x1 + pi->border_gap;
    ay1 = y1 + pi->border_gap;
    ax2 = x2 - pi->border_gap;
    ay2 = y2 - pi->border_gap;
    total_width = ax2 - ax1 + 1;
    if (pi->range == 0)
    {
        fill_width = total_width;
    }
    else
    {
        fill_width = pi->value * total_width / pi->range;
    }
    fx1 = ax1;
    fy1 = ay1;
    fy2 = ay2;

    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    gui_draw_filled_area(x1, y1, x2, y2, pi->background_filler);

    if (pi->value > 0)
    {
        if (pi->flags & UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_MULTICOLOR)
        {
            if (pi->flags & UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_STEP)
            {
                S32 block_width, block_gap, sum_of_widths;
                S32 i = 0, j = 0;
                UI_filled_area *f = &pi->foreground_filler[j];

                block_width = pi->block_width;
                block_gap = pi->block_gap;
                sum_of_widths = pi->percentages[j] * total_width / 100;
                while (i < fill_width)
                {
                    if (i > sum_of_widths)
                    {
                        j++;
                        sum_of_widths += pi->percentages[j] * total_width / 100;
                        if (j >= pi->n_fillers)
                        {
                            j = pi->n_fillers - 1;
                        }
                    }
                    f = &pi->foreground_filler[j];
                    fx1 = i + ax1;
                    fx2 = fx1 + block_width - 1;
                    if (fx2 > ax2)
                    {
                        fx2 = ax2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, f);
                    i += block_width;
                    i += block_gap;
                }
            }
            else
            {
                S32 i = 0, j = 0, w, done = 0, sum_of_widths = 0;
                UI_filled_area *f;

                i = 0;
                for (j = 0; (j < pi->n_fillers) && (!done); j++)
                {
                    f = &pi->foreground_filler[j];
                    fx1 = i + ax1;
                    w = pi->percentages[j] * total_width / 100;
                    sum_of_widths += w;
                    if (sum_of_widths > fill_width)
                    {
                        w -= (sum_of_widths - fill_width);
                        done = 1;
                    }
                    fx2 = fx1 + w - 1;
                    if (fx2 > ax2)
                    {
                        fx2 = ax2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, f);
                    i += w;
                }
            }
        }
        else
        {
            if (pi->flags & UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_STEP)
            {
                S32 block_width, block_gap;
                S32 i = 0;

                block_width = pi->block_width;
                block_gap = pi->block_gap;
                while (i < fill_width)
                {
                    fx1 = i + ax1;
                    fx2 = fx1 + block_width - 1;
                    if (fx2 > ax2)
                    {
                        fx2 = ax2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, pi->foreground_filler);
                    i += block_width;
                    i += block_gap;
                }
            }
            else
            {
                fx2 = ax1 + fill_width;
                if (fx2 > ax2)
                {
                    fx2 = ax2;
                }
                gui_draw_filled_area(fx1, fy1, fx2, fy2, pi->foreground_filler);
            }
        }
    }
    gui_pop_clip();
}

/***************************************************************************** 
 * Vertical Progress Indicator
 *****************************************************************************/

UI_vertical_progress_indicator_theme *current_vertical_progress_indicator_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_progress_indicator_theme
 * DESCRIPTION
 *  Applies the current theme to the progress indicator object
 * PARAMETERS
 *  pi      [IN]        Is the vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_progress_indicator_theme(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->flags = current_vertical_progress_indicator_theme->flags;
    pi->background_filler = current_vertical_progress_indicator_theme->background_filler;
    pi->foreground_filler = current_vertical_progress_indicator_theme->foreground_filler;
    pi->n_fillers = current_vertical_progress_indicator_theme->n_fillers;
    pi->percentages = current_vertical_progress_indicator_theme->percentages;
    pi->block_height = current_vertical_progress_indicator_theme->block_height;
    pi->block_gap = current_vertical_progress_indicator_theme->block_gap;
    pi->border_gap = current_vertical_progress_indicator_theme->border_gap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_progress_indicator
 * DESCRIPTION
 *  creates a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object (pre-allocated)
 *  x           [IN]        Left-top corner
 *  y           [IN]        Left-top corner
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_progress_indicator(vertical_progress_indicator *pi, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->x = x;
    pi->y = y;
    pi->width = width;
    pi->height = height;
    gui_set_vertical_progress_indicator_theme(pi);
    pi->range = 100;
    pi->value = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_progress_indicator_range
 * DESCRIPTION
 *  Sets the range of a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 *  range       [IN]        Is the range (positive number Ex: Available text length in an inputbox)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_progress_indicator_range(vertical_progress_indicator *pi, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    pi->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_progress_indicator_value
 * DESCRIPTION
 *  Sets the value of a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 *  value       [IN]        Is the value (positive number Ex: current text length in an inputbox)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_progress_indicator_value(vertical_progress_indicator *pi, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    pi->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_vertical_progress_indicator
 * DESCRIPTION
 *  Displays a vertical progress indicator
 * PARAMETERS
 *  pi      [IN]        Is the vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_progress_indicator(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, fyh;
    S32 ax1, ay1, ax2, ay2;
    S32 fx1, fy1, fx2, fy2;
    S32 fill_height, total_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = pi->x;
    y1 = pi->y;
    x2 = x1 + pi->width;
    y2 = y1 + pi->height;
    ax1 = x1 + pi->border_gap;
    ay1 = y1 + pi->border_gap;
    ax2 = x2 - pi->border_gap;
    ay2 = y2 - pi->border_gap;
    total_height = ay2 - ay1 + 1;
    if (pi->range == 0)
    {
        fill_height = total_height;
    }
    else
    {
        fill_height = pi->value * total_height / pi->range;
    }
    fx1 = ax1;
    fy1 = ay1;
    fx2 = ax2;

    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    gui_draw_filled_area(x1, y1, x2, y2, pi->background_filler);

    if (pi->value > 0)
    {
        if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_MULTICOLOR)
        {
            if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_STEP)
            {
                S32 block_height, block_gap, sum_of_heights;
                S32 i = 0, j = 0;
                UI_filled_area *f = &pi->foreground_filler[j];

                block_height = pi->block_height;
                block_gap = pi->block_gap;
                sum_of_heights = pi->percentages[j] * total_height / 100;
                while (i < fill_height)
                {
                    if (i > sum_of_heights)
                    {
                        j++;
                        sum_of_heights += pi->percentages[j] * total_height / 100;
                        if (j >= pi->n_fillers)
                        {
                            j = pi->n_fillers - 1;
                        }
                    }
                    f = &pi->foreground_filler[j];
                    fy1 = i + ay1;
                    fy2 = fy1 + block_height - 1;
                    if (fy2 > ay2)
                    {
                        fy2 = ay2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, f);
                    i += block_height;
                    i += block_gap;
                }
            }
            else
            {
                S32 i = 0, j = 0, w, done = 0, sum_of_heights = 0;
                UI_filled_area *f;

                i = 0;
                for (j = 0; (j < pi->n_fillers) && (!done); j++)
                {
                    f = &pi->foreground_filler[j];
                    fy1 = i + ay1;
                    w = pi->percentages[j] * total_height / 100;
                    sum_of_heights += w;
                    if (sum_of_heights > fill_height)
                    {
                        w -= (sum_of_heights - fill_height);
                        done = 1;
                    }
                    fy2 = fy1 + w - 1;
                    if (fy2 > ay2)
                    {
                        fy2 = ay2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, f);
                    i += w;
                }
            }
        }
        else
        {
            if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_STEP)
            {
                S32 block_height, block_gap;
                S32 i = 0;

                block_height = pi->block_height;
                block_gap = pi->block_gap;
                while (i < fill_height)
                {
                    fy1 = i + ay1;
                    fy2 = fy1 + block_height - 1;
                    if (fy2 > ay2)
                    {
                        fy2 = ay2;
                    }
                    if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_REVERSE)
                    {
                        fyh = fy2 - fy1 + 1;
                        fy1 = (ay2 - fyh + 1) - i;
                        fy2 = ay2 - i;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, pi->foreground_filler);
                    i += block_height;
                    i += block_gap;
                }
            }
            else
            {
                fy2 = ay1 + fill_height;
                if (fy2 > ay2)
                {
                    fy2 = ay2;
                }
                if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_REVERSE)
                {
                    fyh = fy2 - fy1 + 1;
                    fy1 = ay2 - fyh + 1;
                    fy2 = ay2;
                }
                gui_draw_filled_area(fx1, fy1, fx2, fy2, pi->foreground_filler);
            }
        }
    }
    gui_pop_clip();
}


/***************************************************************************** 
 * Vertical Slider (Used by Multimedia Application)
 *****************************************************************************/

UI_vertical_slide_theme *current_vertical_slide_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_current_theme
 * DESCRIPTION
 *  Applies the current theme for the vertical slide
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_current_theme(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = current_vertical_slide_theme->focussed_bar_filler;
    v->normal_bar_filler = current_vertical_slide_theme->normal_bar_filler;
    v->disabled_bar_filler = current_vertical_slide_theme->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->scroll_button, current_vertical_slide_theme->scroll_button_theme);
    gui_icon_button_set_icon(
        &v->scroll_button,
        current_vertical_slide_theme->scroll_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= current_vertical_slide_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_theme
 * DESCRIPTION
 *  Applies the given theme to the vertical slide
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical slide object
 *  t       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_theme(vertical_slide *v, UI_vertical_slide_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = t->focussed_bar_filler;
    v->normal_bar_filler = t->normal_bar_filler;
    v->disabled_bar_filler = t->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->scroll_button, t->scroll_button_theme);
    gui_icon_button_set_icon(&v->scroll_button, t->scroll_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_slide
 * DESCRIPTION
 *  Creates a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the vertical slide (smaller)
 *  height      [IN]        Is the height of the vertical slide (larger)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_slide(vertical_slide *v, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->width = width;
    v->height = height;
    v->value = 0;
    v->range = 0;
    v->flags = 0;
    gui_create_icon_button(
        &v->scroll_button,
        v->x,
        v->y,
        v->width,
        v->width,
        current_vertical_slide_theme->scroll_button_icon);
    gui_set_vertical_slide_current_theme(v);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_range
 * DESCRIPTION
 *  Sets the range of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  range       [IN]        (positive value: Example: Total number of items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_range(vertical_slide *v, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    v->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_value
 * DESCRIPTION
 *  Sets the value of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  value       [IN]        (positive value: Example: First displayed item in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_value(vertical_slide *v, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    v->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_scale
 * DESCRIPTION
 *  Sets the scale of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  scale       [IN]        (positive value: Example: Number of displayed items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_scale(vertical_slide *v, S32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scale < 0)
    {
        scale = 0;
    }
    v->scale = (U32) scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_vertical_slide
 * DESCRIPTION
 *  Moves the slide to a differnt location
 * PARAMETERS
 *  v       [IN/OUT]    Is the vertical slide object
 *  x       [IN]        Is the left-top corner of the slide
 *  y       [IN]        Is the left-top corner of the slide
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_vertical_slide(vertical_slide *v, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->scroll_button.x = x;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_vertical_slide
 * DESCRIPTION
 *  Changes the size of a slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_vertical_slide(vertical_slide *v, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->width = width;
    v->height = height;
    v->scroll_button.x = v->x;
    v->scroll_button.width = v->width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_vertical_slide
 * DESCRIPTION
 *  Displays the vertical slide
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_slide(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height, max_height;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = v->x;
    y1 = v->y;
    x2 = x1 + v->width - 1;
    y2 = y1 + v->height - 1;
    if (v->flags & UI_VERTICAL_SLIDE_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SLIDE_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    gui_draw_filled_area(x1, y1, x2, y2, f);
    gui_pop_clip();

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    max_height = y2 - y1 + 1;
    min_height = v->width;
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_height = (v->scale * max_height) / v->range;
        }
        else
        {
            sbutton_height = max_height;
        }
    }
    else
    {
        sbutton_height = min_height;
    }
    if (sbutton_height < min_height)
    {
        sbutton_height = min_height;
    }
    if (sbutton_height > max_height)
    {
        sbutton_height = max_height;
    }
    sb_yrange = max_height - sbutton_height;
    if (r > 0)
    {
        sb_y = (sb_yrange * v->value) / r;
    }
    else
    {
        sb_y = 0;
    }
    if (sb_y < 0)
    {
        sb_y = 0;
    }
    if (sb_y > sb_yrange)
    {
        sb_y = sb_yrange;
    }
    if (v->flags & UI_VERTICAL_SLIDE_TYPE_REVERSE)
    {
        sb_y = v->height - sb_y - v->scroll_button.height;
    }

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1;
    gui_show_icon_button(&v->scroll_button);
}


/***************************************************************************** 
 * Horizontal Slider (Used by Multimedia Application)
 *****************************************************************************/

UI_horizontal_slide_theme *current_horizontal_slide_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_current_theme
 * DESCRIPTION
 *  Applies the current theme for the horizontal slide
 * PARAMETERS
 *  h       [IN/OUT]        Is the horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_current_theme(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->focussed_bar_filler = current_horizontal_slide_theme->focussed_bar_filler;
    h->normal_bar_filler = current_horizontal_slide_theme->normal_bar_filler;
    h->disabled_bar_filler = current_horizontal_slide_theme->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&h->scroll_button, current_horizontal_slide_theme->scroll_button_theme);
    gui_icon_button_set_icon(
        &h->scroll_button,
        current_horizontal_slide_theme->scroll_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    h->flags |= current_horizontal_slide_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_theme
 * DESCRIPTION
 *  Applies the given theme to the horizontal slide
 * PARAMETERS
 *  h       [IN/OUT]        Is the horizontal slide object
 *  t       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_theme(horizontal_slide *h, UI_horizontal_slide_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->focussed_bar_filler = t->focussed_bar_filler;
    h->normal_bar_filler = t->normal_bar_filler;
    h->disabled_bar_filler = t->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&h->scroll_button, t->scroll_button_theme);
    gui_icon_button_set_icon(&h->scroll_button, t->scroll_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    h->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_slide
 * DESCRIPTION
 *  Creates a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the horizontal slide (smaller)
 *  height      [IN]        Is the height of the horizontal slide (larger)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_slide(horizontal_slide *h, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->x = x;
    h->y = y;
    h->width = width;
    h->height = height;
    h->value = 0;
    h->range = 0;
    h->flags = 0;
    gui_create_icon_button(
        &h->scroll_button,
        h->x,
        h->y,
        h->height,
        h->height,
        current_horizontal_slide_theme->scroll_button_icon);
    gui_set_horizontal_slide_current_theme(h);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_range
 * DESCRIPTION
 *  Sets the range of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  range       [IN]        (positive value: Example: Total number of items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_range(horizontal_slide *h, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    h->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_value
 * DESCRIPTION
 *  Sets the value of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  value       [IN]        (positive value: Example: First displayed item in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_value(horizontal_slide *h, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    h->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_scale
 * DESCRIPTION
 *  Sets the scale of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  scale       [IN]        (positive value: Example: Number of displayed items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_scale(horizontal_slide *h, S32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scale < 0)
    {
        scale = 0;
    }
    h->scale = (U32) scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_horizontal_slide
 * DESCRIPTION
 *  Moves the slide to a differnt location
 * PARAMETERS
 *  h       [IN/OUT]    Is the horizontal slide object
 *  x       [IN]        Is the left-top corner of the slide
 *  y       [IN]        Is the left-top corner of the slide
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_horizontal_slide(horizontal_slide *h, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->x = x;
    h->y = y;
    h->scroll_button.x = x;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_horizontal_slide
 * DESCRIPTION
 *  Changes the size of a slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_horizontal_slide(horizontal_slide *h, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->width = width;
    h->height = height;
    h->scroll_button.x = h->x;
    h->scroll_button.width = h->width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_horizontal_slide
 * DESCRIPTION
 *  Displays the horizontal slide
 * PARAMETERS
 *  h       [IN/OUT]        Is the horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_slide(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width, max_width;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = h->x;
    y1 = h->y;
    x2 = x1 + h->width - 1;
    y2 = y1 + h->height - 1;
    if (h->flags & UI_HORIZONTAL_SLIDE_STATE_FOCUSSED)
    {
        f = h->focussed_bar_filler;
    }
    else if (h->flags & UI_HORIZONTAL_SLIDE_STATE_DISABLED)
    {
        f = h->disabled_bar_filler;
    }
    else
    {
        f = h->normal_bar_filler;
    }
    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    gui_draw_filled_area(x1, y1, x2, y2, f);
    gui_pop_clip();

    /* Show the scroll button based on range and value */
    r = h->range - h->scale;
    max_width = x2 - x1 + 1;
    min_width = h->height;
    if (h->scale > 0)
    {
        if (h->range > 0)
        {
            sbutton_width = (h->scale * max_width) / h->range;
        }
        else
        {
            sbutton_width = max_width;
        }
    }
    else
    {
        sbutton_width = min_width;
    }
    if (sbutton_width < min_width)
    {
        sbutton_width = min_width;
    }
    if (sbutton_width > max_width)
    {
        sbutton_width = max_width;
    }
    sb_xrange = max_width - sbutton_width;
    if (r > 0)
    {
        sb_x = (sb_xrange * h->value) / r;
    }
    else
    {
        sb_x = 0;
    }
    if (sb_x < 0)
    {
        sb_x = 0;
    }
    if (sb_x > sb_xrange)
    {
        sb_x = sb_xrange;
    }
    if (h->flags & UI_HORIZONTAL_SLIDE_TYPE_REVERSE)
    {
        sb_x = h->width - sb_x - h->scroll_button.width;
    }

    h->scroll_button.width = sbutton_width;
    h->scroll_button.x = sb_x + x1;
    gui_show_icon_button(&h->scroll_button);
}

