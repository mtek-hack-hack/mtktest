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
 *  gui_text_label.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Text Label - UI component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */


#include "gui.h"
#include "gui_themes.h"
#include "gui_text_label.h"
#include "wgui_text_label.h"
#include "DebugInitDef.h"
#include "wgui_categories_defs.h"
#include "BIDIDEF.h"
#include "BIDIProt.h"
#include "UCS2Prot.h"
#include "gdi_include.h"

/* for R2L characters */
extern BOOL r2lMMIFlag;


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_create
 * DESCRIPTION
 *  create the text label component
 * PARAMETERS
 *  t                   [IN]        Pointer of text label component
 *  x                   [IN]        Start x posiion
 *  y                   [IN]        Start y position
 *  width               [IN]        Width of clock
 *  height              [IN]        Height of clock
 *  title               [IN]        Title of the text label
 *  text_font           [IN]        Font of title
 *  text_color          [IN]        Color of title
 *  border_enable       [IN]        Enable border text or not
 *  border_color        [IN]        Border color of title
 *  background          [IN]        Background painter of text label
 *  text_align_x_type   [IN]        Text algin type in x-axis
 *  text_align_y_type   [IN]        Text algin type in y-axis
 *  target_layer        [IN]        Target layer to display
 *  target_lcd          [IN]        Target lcd to dispaly
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_create(
        gui_text_label_struct *t,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U8 *title,
        UI_font_type text_font,
        color text_color,
        MMI_BOOL border_enable,
        color border_color,
        gui_util_painter_struct background, 
        gui_text_label_align_enum text_h_align_type,
        gui_text_label_align_enum text_v_align_type,
        GDI_HANDLE target_layer,
        GDI_HANDLE target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->x = x;
    t->y = y;
    t->width = width;
    t->height = height;
    t->title = title;
    t->text_font = text_font;
    t->text_color = text_color;
    t->border_enable = border_enable;
    t->border_color = border_color;
    t->background = background;

    if (text_h_align_type >GUI_TEXT_LABEL_H_ALIGN_START && text_h_align_type < GUI_TEXT_LABEL_H_ALIGN_END)
    {
        t->text_h_align_type = text_h_align_type;    
    }
    else
    {
        t->text_h_align_type = GUI_TEXT_LABEL_H_ALIGN_LEFT;
    }

    if (text_v_align_type > GUI_TEXT_LABEL_V_ALIGN_START && text_v_align_type < GUI_TEXT_LABEL_V_ALIGN_END)
    {
        t->text_v_align_type = text_v_align_type;    
    }
    else
    {
        t->text_v_align_type = GUI_TEXT_LABEL_V_ALIGN_TOP;  
    }
    
    t->target_layer = target_layer;
    t->target_lcd = target_lcd;
    t->active = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_close
 * DESCRIPTION
 *  close the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_close(gui_text_label_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->active = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_show
 * DESCRIPTION
 *  show the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_show(gui_text_label_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 text_x1, text_x2, text_y1, text_y2, text_w, text_h, dx, dy, border_gap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    gui_push_clip();
    gui_set_clip(t->x, t->y, t->x + t->width - 1, t->y + t->height - 1);

    gui_util_painter_show(&t->background, t->x, t->y, t->x + t->width - 1, t->y + t->height - 1);

    gui_set_font(t->text_font);
    gui_set_text_color(t->text_color);
    
    if (t->border_enable)
    {
        gui_set_text_border_color(t->border_color);
        border_gap = 1;
    }
    else
    {
        border_gap = 0;
    }

    gui_measure_string((UI_string_type)t->title, &text_w, &text_h);
    dx = (t->width >> 1) - (text_w >> 1);
    dy = (t->height >> 1) - (text_h >> 1);
    text_x2 = t->x + t->width - 1;
    text_y2 = t->y + t->height - 1;
    
    if (t->text_h_align_type == GUI_TEXT_LABEL_H_ALIGN_LEFT)
    {
        text_x1 = t->x;
    }
    else if (t->text_h_align_type == GUI_TEXT_LABEL_H_ALIGN_CENTER)
    {
        text_x1 = t->x + dx;
    }
    else if (t->text_h_align_type == GUI_TEXT_LABEL_H_ALIGN_RIGHT)
    {
        text_x1 = t->x + t->width - text_w - border_gap * 2;
    }
    else if (t->text_h_align_type == GUI_TEXT_LABEL_H_ALIGN_LANG_DEP)
    {
        if (r2lMMIFlag)
        {
            text_x1 = t->x + t->width - text_w - border_gap * 2;
        }
        else
        {
            text_x1 = t->x;
        }
    }
    else
    {
        gui_pop_clip();
        return;
    }

    if (t->text_v_align_type == GUI_TEXT_LABEL_V_ALIGN_TOP)
    {
        text_y1 = t->y;
    }
    else if (t->text_v_align_type == GUI_TEXT_LABEL_V_ALIGN_CENTER)
    {
        text_y1 = t->y + dy;
    }
    else if (t->text_v_align_type == GUI_TEXT_LABEL_V_ALIGN_BOTTOM)
    {
        text_y1 = t->y + t->height - text_h - border_gap * 2; 
    }
    else
    {
        gui_pop_clip();
        return;
    }
    
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(text_x1 + text_w - 1 + border_gap, text_y1 + border_gap);
    }
    else
    {
        gui_move_text_cursor(text_x1 + border_gap, text_y1 + border_gap);
    }

    if (t->border_enable)
    {
        gui_print_bordered_text((UI_string_type)t->title);
    }
    else
    {
        gui_print_text((UI_string_type)t->title);
    }

    gui_pop_clip();
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_move
 * DESCRIPTION
 *  move the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  x       [IN]        New x position
 *  y       [IN]        New y position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_move(gui_text_label_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    
    t->x = x;
    t->y = y;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_resize
 * DESCRIPTION
 *  resize the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  width   [IN]        New width of component
 *  height  [IN]        New height of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_resize(gui_text_label_struct *t, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->width = width;
    t->height = height;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_set_title
 * DESCRIPTION
 *  set the title of text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  new_title   [IN]        New title of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_set_title(gui_text_label_struct *t, U8 *new_title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->title = new_title;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_get_title
 * DESCRIPTION
 *  get the title of text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 * RETURNS
 *  pointer of the title
 *****************************************************************************/
U8 * gui_text_label_get_title(gui_text_label_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return NULL;
    }

    return t->title;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_set_text_font
 * DESCRIPTION
 *  set the text font of text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  new_font   [IN]        New font of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_set_text_font(gui_text_label_struct *t, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->text_font = new_font;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_get_text_font
 * DESCRIPTION
 *  get text font of the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  font    [IN/OUT]    Return the text font
 * RETURNS
 *  MMI_TRUE - success / MMI_FALSE - fail
 *****************************************************************************/
MMI_BOOL gui_text_label_get_text_font(gui_text_label_struct *t, UI_font_type *font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return MMI_FALSE;
    }

    *font = t->text_font;
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_set_text_color
 * DESCRIPTION
 *  set text color of the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  new_text_color   [IN]        New text color of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_set_text_color(gui_text_label_struct *t, color new_text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->text_color = new_text_color;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_get_text_color
 * DESCRIPTION
 *  get text color of the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  text_color  [IN/OUT]    Return text color
 * RETURNS
 *  MMI_TRUE - success / MMI_FALSE - fail
 *****************************************************************************/
MMI_BOOL gui_text_label_get_text_color(gui_text_label_struct *t, color *text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return MMI_FALSE;
    }

    *text_color = t->text_color;
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_set_border_enable
 * DESCRIPTION
 *  set the border enabled or not of the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  border_enable   [IN]        Enable the border or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_set_border_enable(gui_text_label_struct *t, MMI_BOOL border_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->border_enable = border_enable;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_get_border_enable
 * DESCRIPTION
 *  get the enable status of the text label component
 * PARAMETERS
 *  t               [IN]        Pointer of text label component
 *  border_color    [IN/OUT]    Return border enable
 * RETURNS
 *  MMI_TRUE - success / MMI_FALSE - fail
 *****************************************************************************/
MMI_BOOL gui_text_label_get_border_enable(gui_text_label_struct *t, MMI_BOOL *border_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return MMI_FALSE;
    }

    *border_enable = t->border_enable;
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_set_border_color
 * DESCRIPTION
 *  set the border color of the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  new_border_color   [IN]        New border color of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_set_border_color(gui_text_label_struct *t, color new_border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->border_color = new_border_color;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_get_border_color
 * DESCRIPTION
 *  get border color of the text label component
 * PARAMETERS
 *  t               [IN]        Pointer of text label component
 *  border_color    [IN/OUT]    Return border color
 * RETURNS
 *  MMI_TRUE - success / MMI_FALSE - fail
 *****************************************************************************/
MMI_BOOL gui_text_label_get_border_color(gui_text_label_struct *t, color *border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return MMI_FALSE;
    }

    *border_color = t->border_color;
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_set_background_painter
 * DESCRIPTION
 *  set background painter of the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  new_background   [IN]        New background painter of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_set_background_painter(gui_text_label_struct *t, gui_util_painter_struct new_background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->background = new_background;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_set_text_attribute
 * DESCRIPTION
 *  set text attribute of the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  new_title   [IN]        New title of component
 *  new_font    [IN]        New font of component
 *  new_text_color  [IN]    New text color of component
 *  new_background  [IN]    New background painter of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_set_text_attribute(
        gui_text_label_struct *t,
        U8 *new_title,
        UI_font_type new_font,
        color new_text_color,
        gui_util_painter_struct new_background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->title = new_title;
    t->text_font = new_font;
    t->text_color = new_text_color;
    t->background = new_background;

}


/*****************************************************************************
 * FUNCTION
 *  gui_text_label_set_border_attribute
 * DESCRIPTION
 *  set border attribute of the text label component
 * PARAMETERS
 *  t       [IN]        Pointer of text label component
 *  border_enable       [IN]        New border enable status of component
 *  new_border_color    [IN]        New border color of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_label_set_border_attribute(gui_text_label_struct *t, MMI_BOOL border_enable, color new_border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!t)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    t->border_enable = border_enable;
    t->border_color = new_border_color;

}



