/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  wgui_text_label.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  text label related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * 
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


#include "GlobalDefs.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "gui_themes.h"
#include "wgui_categories.h"
#include "wgui_text_label.h"
#include "gui_text_label.h"
#include "MMI_features.h"
#include "DebugInitDef.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_defs.h"

/* text label list */
static  gui_text_label_struct   wgui_text_label_list[WGUI_TEXT_LABEL_MAX];


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_create
 * DESCRIPTION
 *  create the text label component
 * PARAMETERS
 *  text_label_id       [IN]        Id of text label
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
 *  text_align_type     [IN]        Text algin type
 *  target_layer        [IN]        
 *  target_lcd          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_create(
        U32 text_label_id,
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
    if (text_label_id >= WGUI_TEXT_LABEL_MAX)
    {
        return;
    }

    gui_text_label_create(
        &wgui_text_label_list[text_label_id],
        x,
        y,
        width,
        height,
        title,
        text_font,
        text_color,
        border_enable,
        border_color,
        background,
        text_h_align_type,
        text_v_align_type,
        target_layer,
        target_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_close
 * DESCRIPTION
 *  close the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_close(U32 text_label_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_close(&wgui_text_label_list[text_label_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_show
 * DESCRIPTION
 *  show the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_show(U32 text_label_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    GDI_HANDLE old_lcd, old_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    GDI_LOCK;
            
    gdi_layer_get_active(&old_layer);
    gdi_lcd_get_active(&old_lcd);

    gdi_lcd_set_active(wgui_text_label_list[text_label_id].target_lcd);
    gdi_layer_push_and_set_active(wgui_text_label_list[text_label_id].target_layer);

    gui_text_label_show(&wgui_text_label_list[text_label_id]);

    gdi_layer_pop_and_restore_active();

    gdi_lcd_set_active(old_lcd);
    gdi_layer_set_active(old_layer);
            
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_move
 * DESCRIPTION
 *  move the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  x               [IN]    New x position
 *  y               [IN]    New y position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_move(U32 text_label_id, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_move(&wgui_text_label_list[text_label_id], x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_resize
 * DESCRIPTION
 *  resize the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  width           [IN]    New width
 *  height          [IN]    New height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_resize(U32 text_label_id, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_resize(&wgui_text_label_list[text_label_id], width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_set_title
 * DESCRIPTION
 *  set title of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  new_title       [IN]    New title of the text label
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_set_title(U32 text_label_id, U8 *new_title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_set_title(&wgui_text_label_list[text_label_id], new_title);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_get_title
 * DESCRIPTION
 *  get the title of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 * RETURNS
 *  pointer of title
 *****************************************************************************/
U8 * wgui_text_label_get_title(U32 text_label_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return NULL;
    }

    return gui_text_label_get_title(&wgui_text_label_list[text_label_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_set_text_font
 * DESCRIPTION
 *  set the text font of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  new_font        [IN]    New font of text label
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_set_text_font(U32 text_label_id, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_set_text_font(&wgui_text_label_list[text_label_id], new_font);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_get_text_font
 * DESCRIPTION
 *  get the font of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  text_font       [IN/OUT]   Return text font
 * RETURNS
 *  MMI_TRUE - success / MMI_FALSE - fail
 *****************************************************************************/
MMI_BOOL wgui_text_label_get_text_font(U32 text_label_id, UI_font_type *text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    return gui_text_label_get_text_font(&wgui_text_label_list[text_label_id], text_font);
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_set_text_color
 * DESCRIPTION
 *  set text color of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  new_color       [IN]    New text color of text label
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_set_text_color(U32 text_label_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_set_text_color(&wgui_text_label_list[text_label_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_get_text_color
 * DESCRIPTION
 *  get text color of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  text_color      [IN/OUT]   Return text color
 * RETURNS
 *  MMI_TRUE - success / MMI_FALSE - fail
 *****************************************************************************/
MMI_BOOL wgui_text_label_get_text_color(U32 text_label_id, color * text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    
    return gui_text_label_get_text_color(&wgui_text_label_list[text_label_id], text_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_set_border_enable
 * DESCRIPTION
 *  set the enable status of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  border_enable   [IN]    New enable status of text label
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_set_border_enable(U32 text_label_id, MMI_BOOL border_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_set_border_enable(&wgui_text_label_list[text_label_id], border_enable);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_get_border_enable
 * DESCRIPTION
 *  get the border enabled status of the text label component
 * PARAMETERS
 *  text_label_id   [IN]        Id of text label
 *  border_enable   [IN/OUT]    Return border enable
 * RETURNS
 *  MMI_TRUE - success / MMI_FALSE - fail
 *****************************************************************************/
MMI_BOOL wgui_text_label_get_border_enable(U32 text_label_id, MMI_BOOL *border_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    
    return gui_text_label_get_border_enable(&wgui_text_label_list[text_label_id], border_enable);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_set_border_color
 * DESCRIPTION
 *  set the border color of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  new_color       [IN]    New border color of text label
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_set_border_color(U32 text_label_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_set_border_color(&wgui_text_label_list[text_label_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_get_border_color
 * DESCRIPTION
 *  get the border color of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  border_color    [IN/OUT]   Return border color
 * RETURNS
 *  MMI_TRUE - success / MMI_FALSE - fail
 *****************************************************************************/
MMI_BOOL wgui_text_label_get_border_color(U32 text_label_id, color *border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    
    return gui_text_label_get_border_color(&wgui_text_label_list[text_label_id], border_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_set_background_filler
 * DESCRIPTION
 *  set the background painter of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  new_background  [IN]    New background painter
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_set_background_filler(U32 text_label_id, gui_util_painter_struct new_background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_set_background_painter(&wgui_text_label_list[text_label_id], new_background);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_set_text_attribute
 * DESCRIPTION
 *  set the text attribute of the text label component
 * PARAMETERS
 *  text_label_id   [IN]    Id of text label
 *  new_title       [IN]    New title of component
 *  new_font        [IN]    New font of component
 *  new_text_color  [IN]    New text color of component
 *  new_background  [IN]    New background painter of component
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_set_text_attribute(
        U32 text_label_id,
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
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_set_text_attribute(
        &wgui_text_label_list[text_label_id],
        new_title,
        new_font,
        new_text_color,
        new_background);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_text_label_set_border_attribute
 * DESCRIPTION
 *  set the border attribute of the text label component
 * PARAMETERS
 *  text_label_id       [IN]        Id of text label
 *  border_enable       [IN]        New border enable status of component
 *  new_border_color    [IN]        New border color of component
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_text_label_set_border_attribute(U32 text_label_id, MMI_BOOL border_enable, color new_border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_label_id >= WGUI_TEXT_LABEL_MAX ||
        wgui_text_label_list[text_label_id].active == MMI_FALSE)
    {
        return;
    }

    gui_text_label_set_border_attribute(&wgui_text_label_list[text_label_id], border_enable, new_border_color);
}


