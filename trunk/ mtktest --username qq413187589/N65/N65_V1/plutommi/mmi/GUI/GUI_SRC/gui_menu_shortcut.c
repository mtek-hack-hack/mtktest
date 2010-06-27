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
 *  gui_menu_shortcuts.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  shortcuts related funtions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_themes.h"
#include "gui_menu_shortcut.h"
#include "wgui_categories_util.h"
#include "Wgui_title.h"

#ifdef __MMI_UI_TECHNO_STATUS_ICON__
#include "MainMenuDef.h"
#endif 

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define GUI_SHORTCUT_DEFLEN             3       /* default wdith of shortcut */

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/*****************************************************************************              
 * Variable                                                                    
 *****************************************************************************/
extern BOOL r2lMMIFlag;

UI_shortcut_box_theme *current_shortcut_box_theme = NULL;
U8 menu_shortcut_handler_display = 0;
U8 disable_menu_shortcut_box_display = 0;

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/
static void gui_shortcut_dummy_hide_menu(S32 x, S32 y, S32 w, S32 h);
static void gui_shortcut_dummy_timer_callback(void);


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_dummy_hide_menu
 * DESCRIPTION
 *  Dummy function used in shortcut
 * PARAMETERS
 *  x       [IN]        Is the left-top conner position
 *  y       [IN]        Is the left-top conner position
 *  w       [IN]        Is the right-bottom conner position
 *  h       [IN]        Is the right-bottom conner position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_shortcut_dummy_hide_menu(S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x);
    UI_UNUSED_PARAMETER(y);
    UI_UNUSED_PARAMETER(w);
    UI_UNUSED_PARAMETER(h);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_dummy_timer_callback
 * DESCRIPTION
 *  Dummy function used in shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_shortcut_dummy_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_handler_keyinput
 * DESCRIPTION
 *  This function is called when a menu shortcut key is pressed
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  c       [IN]            The character that is input
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_handler_keyinput(gui_shortcut_struct *sc, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, nstr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sc->number < 0)
    {
        return;
    }

    if (mmi_ucs2strlen((const S8*)sc->input_buffer) >= sc->input_length)
    {
        sc->timer_callback();
    }
    else if (sc->display == 0 && c == '0' && sc->input_buffer[0] == 0)
    {
        return;
    }
    else
    {

        if (sc->display == 0)
        {
            sc->display = 1;
            sc->input_buffer[0] = 0;
        }

        gdi_layer_lock_frame_buffer();
        nstr = mmi_ucs2strlen((const S8*)sc->input_buffer);
        sc->input_buffer[nstr] = c;
        sc->input_buffer[nstr + 1] = 0;
        i = gui_atoi((UI_string_type) sc->input_buffer);
        sc->number = i - 1;
        gui_start_timer(MMI_MENU_SHORTCUT_TIMEOUT, sc->timer_callback);

        if (!sc->display_enabled)
        {
            sc->hide_callback(sc->x, sc->y, sc->width, sc->height);
            if (!r2lMMIFlag)
            {
                sc->x -= GUI_SHORTCUT_INSERT_GAP;
            }
            else
            {
                sc->x += GUI_SHORTCUT_INSERT_GAP;
            }
            gui_shortcut_show(sc);
            if (!r2lMMIFlag)
            {
                sc->x += GUI_SHORTCUT_INSERT_GAP;
            }
            else
            {
                sc->x -= GUI_SHORTCUT_INSERT_GAP;
            }

        }

        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(sc->x, sc->y, sc->x + sc->width - 1, sc->y + sc->height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_create
 * DESCRIPTION
 *  Creates the menu shortcut
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  x       [IN]            Is the left-top corner position
 *  y       [IN]            Is the left-top corner position
 *  w       [IN]            Is the width of shortcut
 *  h       [IN]            Is the height of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_create(gui_shortcut_struct *sc, S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!r2lMMIFlag)
    {
        sc->x = x + w - GUI_SHORTCUT_WIDTH;
    }
    else
    {
        sc->x = x;
    }
    sc->y = y;
    sc->width = GUI_SHORTCUT_WIDTH;
    sc->height = h;
    sc->input_length = GUI_SHORTCUT_DEFLEN;
    gui_shortcut_set_current_theme(sc);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_register_callback
 * DESCRIPTION
 *  Registers the function to be called when a shortcut
 *  is being entered.
 * PARAMETERS
 *  sc                  [IN/OUT]        Is the struct of shortcut
 *  timer_callback      [IN]            Callback function of timer out
 *  hide_funcptr        [IN]            Callback funtion of hide
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_register_callback(
        gui_shortcut_struct *sc,
        void (*timer_callback) (void),
        void (*hide_funcptr) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (timer_callback)
    {
        sc->timer_callback = timer_callback;
    }
    if (hide_funcptr)
    {
        sc->hide_callback = hide_funcptr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_move
 * DESCRIPTION
 *  Moves the menu shortcut indicator to a new position
 * PARAMETERS
 *  sc      [IN/OUT]        Struct of shortcut
 *  x       [IN]            Is the new left-top corner position
 *  y       [IN]            Is the new left-top corner position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_move(gui_shortcut_struct *sc, S32 x, S32 y)
{
#ifdef __MMI_UI_TECHNO_STATUS_ICON__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == MAIN_MENU_SCREENID)
    {
        sc->x = x - MMI_SIGNAL_WIDTH;
    }
    else
#endif /* __MMI_UI_TECHNO_STATUS_ICON__ */ 
    {
        sc->x = x;
    }
    sc->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_auto_resize
 * DESCRIPTION
 *  Auto resizes the menu shortcut indicator
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  h       [IN]            Is the height of shortcut
 * RETURNS
 *  width of shortcut
 *****************************************************************************/
S32 gui_shortcut_auto_resize(gui_shortcut_struct *sc, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 s[GUI_SHORTCUT_MAX_SIZE];
    S32 l, w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(8, (UI_string_type) s, 10);
    gui_set_font(sc->normal_font);
    gui_measure_string((UI_string_type) s, &w, &l);
    w = w * sc->input_length + GUI_SHORTCUT_GAP;
    sc->width = w;
    sc->height = h;
    return w;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_show
 * DESCRIPTION
 *  show the menu shortcut
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_show(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height;
    UI_character_type s[GUI_SHORTCUT_MAX_SIZE];
    stFontAttribute *font = sc->normal_font;
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* __MMI_WALLPAPER_ON_BOTTOM__ does not show shortcut in title */
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__

    if (!sc->display_enabled && sc->number >= 0)
    {
        gui_push_clip();
        gui_itoa(sc->number + 1, (UI_string_type) s, 10);
        gui_set_font(font);
        gui_set_clip(sc->x, sc->y, sc->x + sc->width - 1, sc->y + sc->height - 1);
        gui_set_text_color(sc->normal_text_color);
        if (sc->use_border)
        {
            gui_set_text_border_color(sc->normal_text_border_color);
        }
        /* For Animated effect */
        if (sc->input_buffer[0] == 0)
        {
            gui_measure_string((UI_string_type) s, &l, &character_height);
        }
        else
        {
            gui_measure_string((UI_string_type) sc->input_buffer, &l, &character_height);
        }

        if (!r2lMMIFlag)
        {
        #ifdef __MMI_UI_TECHNO_STATUS_ICON__
            if (GetActiveScreenId() == MAIN_MENU_SCREENID)
            {
                gui_move_text_cursor(
                    sc->x + sc->width - l - GUI_SHORTCUT_TEXT_BORDER_X_GAP,
                    sc->y + ((sc->height) - (character_height + TITLE_TEXT_GAP)));
            }
            else
        #endif /* __MMI_UI_TECHNO_STATUS_ICON__ */ 
            {
                gui_move_text_cursor(
                    sc->x + sc->width - l - GUI_SHORTCUT_TEXT_BORDER_X_GAP,
                    sc->y + ((sc->height >> 1) - (character_height >> 1)));
            }
        }
        else
        {
        #ifdef __MMI_UI_TECHNO_STATUS_ICON__
            if (GetActiveScreenId() == MAIN_MENU_SCREENID)
            {
                gui_move_text_cursor(
                    sc->x + GUI_SHORTCUT_TEXT_BORDER_X_GAP + l,
                    sc->y + ((sc->height) - (character_height + TITLE_TEXT_GAP)));
            }
            else
        #endif /* __MMI_UI_TECHNO_STATUS_ICON__ */ 
            {
                gui_move_text_cursor(
                    sc->x + GUI_SHORTCUT_TEXT_BORDER_X_GAP + l,
                    sc->y + ((sc->height >> 1) - (character_height >> 1)));
            }
        }

        gui_set_line_height(character_height);
        if (sc->use_border)
        {
            if (sc->input_buffer[0] == 0)
            {
                gui_print_bordered_text(s);
            }
            else
            {
                gui_print_bordered_text((UI_string_type) sc->input_buffer);
            }
        }
        else
        {
            if (sc->input_buffer[0] == 0)
            {
                gui_print_text(s);
            }
            else
            {
                gui_print_text((UI_string_type) sc->input_buffer);
            }

        }

        gui_pop_clip();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_close
 * DESCRIPTION
 *  Clears keyboard and keypad handlers registerd with the menu shortcut handler.
 *  Also clears the menu handling and hide functions.
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_close(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(sc->timer_callback);
    sc->hide_callback = gui_shortcut_dummy_hide_menu;
    sc->timer_callback = gui_shortcut_dummy_timer_callback;
    sc->display = 0;
    menu_shortcut_handler_display = 0;
    sc->input_buffer[0] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_theme
 * DESCRIPTION
 *  set the specify theme
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  th      [IN]            Is the point of theme structure of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_set_theme(gui_shortcut_struct *sc, UI_shortcut_box_theme *th)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sc->normal_text_color = th->normal_text_color;
    sc->normal_text_border_color = th->normal_text_border_color;
    sc->use_border = th->use_border;
    sc->normal_font = current_MMI_theme->title_text_font;
    sc->active_font = current_MMI_theme->title_text_font;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_current_theme
 * DESCRIPTION
 *  set the current theme
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_set_current_theme(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_shortcut_set_theme(sc, current_shortcut_box_theme);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_item_count
 * DESCRIPTION
 *  Sets the number of digits allowed in the menu shortcut
 *  This is based on the number of items in the menu.
 * PARAMETERS
 *  sc          [IN/OUT]        Is the struct of shortcut
 *  n_items     [IN]            Is the number of menu items in a screen
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_set_item_count(gui_shortcut_struct *sc, S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 s[GUI_SHORTCUT_MAX_SIZE];
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(n_items, (UI_string_type) s, 10);
    l = mmi_ucs2strlen(s);
    sc->input_length = (U8) l;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_get_width
 * DESCRIPTION
 *  Get the width of shortcut's area.
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_shortcut_get_width(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sc->display_enabled && sc->number >= 0)
    {
        width = sc->width;
    }
    return width;

}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_index
 * DESCRIPTION
 *  Set current number of the shortcut to be showed
 * PARAMETERS
 *  sc          [IN/OUT]        Is the struct of shortcut
 *  index       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_set_index(gui_shortcut_struct *sc, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sc->number = index - 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_get_index
 * DESCRIPTION
 *  Get current number of the shortcut to be showed
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_shortcut_get_index(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sc->number + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_is_show
 * DESCRIPTION
 *  shortcut is shown or not
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  shortcut is shown or not
 *****************************************************************************/
MMI_BOOL gui_shortcut_is_show(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sc->display_enabled && sc->number >= 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_show
 * DESCRIPTION
 *  Set shortcut shown or not
 * PARAMETERS
 *  sc          [IN/OUT]        Is the struct of shortcut
 *  show        [IN]            
 * RETURNS
 *  Shortcut is shown or not.
 *****************************************************************************/
void gui_shortcut_set_show(gui_shortcut_struct *sc, MMI_BOOL show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sc->display_enabled = show;
}

