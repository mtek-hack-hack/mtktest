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
 *   wgui_tab_bars.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Tab Bar - Category component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "wgui_tab_bars.h"
#include "gui_setting.h"
#include "DebugInitDef.h"
#include "wgui_categories_util.h"
#include "wgui_status_icons.h"

#define MMI_CATEGORYTAB_ID MMI_CATEGORY425_ID

extern U16 title_bg_id;

/***************************************************************************** 
* Define
*****************************************************************************/
/* To restore the first displayed item after tab bar is scrolled with pen */
#define WGUI_TAB_BAR_RESTORE_DISPLAY_TIME       (3000)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

#ifdef __MMI_TOUCH_SCREEN__

/* Default value is -1. Used to store the display area of tab bar after pen is up. */
S16 MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;

/* Default value is -1. Used to set  the display area of tab bar when it enters a new screen. */
S16 MMI_horizontal_tab_bar_first_displayed_on_screen_switched = -1;

/* Used by wgui_horizontal_tab_bar_translate_pen_event() */
void (*MMI_horizontal_tab_bar_select_callback) (int index);

#endif /* __MMI_TOUCH_SCREEN__ */ 

UI_window_title_theme *current_tab_title_theme = NULL;


/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_reset_title_bg_id
 * DESCRIPTION
 *  reset the tittle background image id of tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_reset_title_bg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    title_bg_id = 0;
}

/***************************************************************************** 
* Global Variable
*****************************************************************************/

horizontal_tab_bar MMI_horizontal_tab_bar;

tab_bar_item_type MMI_tab_bar_items[UI_MAX_TAB_BAR_ITEMS];

/***************************************************************************** 
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_title_timer_callback
 * DESCRIPTION
 *  This function is called when the menu shortcut handler times out
 *  
 *  Internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL modify = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_shortcut_handler_display = 0;
    MMI_horizontal_tab_bar.title.sc.display = 0;
    MMI_horizontal_tab_bar.title.sc.input_buffer[0] = 0;
    gdi_layer_lock_frame_buffer();

    MMI_horizontal_tab_bar.title.pre_goto_callback(gui_shortcut_get_index(&MMI_horizontal_tab_bar.title.sc) - 1);
    if (MMI_menu_shortcut_number == g_wgui_title_bar.sc.number + 1)
    {
        modify = MMI_TRUE;
    }
    gui_shortcut_set_index(&MMI_horizontal_tab_bar.title.sc, MMI_menu_shortcut_number);

    if (MMI_horizontal_tab_bar.title.icon2 == NULL)
    {
        wgui_horizontal_show(GUI_TITLE_PART_SHORTCUT);
    }
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    if (is_enable_animated_title_effect())
    {
        wgui_title_start_animation();
    }
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 
    gdi_layer_unlock_frame_buffer();
    /* BLT together with the previous BLT region */
    gdi_layer_blt_previous(
        MMI_content_x,
        MMI_content_y,
        MMI_content_x + MMI_content_width - 1,
        MMI_content_y + MMI_content_height - 1);

    if (modify)
    {
        MMI_horizontal_tab_bar.title.goto_callback(gui_shortcut_get_index(&MMI_horizontal_tab_bar.title.sc) - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_shortcut_show_background
 * DESCRIPTION
 *  This function is called when the menu shortcut handler times out
 *  
 *  Internal function
 * PARAMETERS
 *  x       [IN]        coordinate of show area
 *  y       [IN]        coordinate of show area
 *  w       [IN]        width of show area
 *  h       [IN]        height of show area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_shortcut_show_background(S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_horizontal_tab_bar.title.icon2 == NULL)
    {
        gui_title_show_background(&MMI_horizontal_tab_bar.title, x, y, w, h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_title_dummy_goto_item
 * DESCRIPTION
 *  Dummy function used in MMI
 * PARAMETERS
 *  index       [IN]        index of item
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_dummy_goto_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(index);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_pre_key_down
 * DESCRIPTION
 *  pre function of key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_pre_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    if (is_enable_animated_title_effect())
    {
        gui_title_stop_animation(&MMI_horizontal_tab_bar.title);
    }
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 
    if (MMI_horizontal_tab_bar.title.sc.input_buffer[0] == 0)
    {
        MMI_horizontal_tab_bar.title.sc.display = menu_shortcut_handler_display;
        gui_shortcut_set_show(&MMI_horizontal_tab_bar.title.sc, (MMI_BOOL) disable_menu_shortcut_box_display);
    }
}



/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_1_key_down
 * DESCRIPTION
 *  key '1' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_1_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '1');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_2_key_down
 * DESCRIPTION
 *  key '2' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_2_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '2');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_3_key_down
 * DESCRIPTION
 *  key '3' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_3_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '3');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_4_key_down
 * DESCRIPTION
 *  key '4' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_4_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '4');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_5_key_down
 * DESCRIPTION
 *  key '5' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_5_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '5');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_6_key_down
 * DESCRIPTION
 *  key '6' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_6_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '6');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_7_key_down
 * DESCRIPTION
 *  key '7' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_7_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '7');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_8_key_down
 * DESCRIPTION
 *  key '8' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_8_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '8');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_9_key_down
 * DESCRIPTION
 *  key '9' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_9_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '9');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_0_key_down
 * DESCRIPTION
 *  key '0' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_0_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '0');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_show
 * DESCRIPTION
 *  draw the title
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_shortcut_set_index(&MMI_horizontal_tab_bar.title.sc, MMI_menu_shortcut_number);
    wgui_horizontal_show(GUI_TITLE_PART_SHORTCUT);
        
}



/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_show
 * DESCRIPTION
 *  draw the title
 * PARAMETERS
 *  part        [IN]        draw a part of title
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_show(U32 part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bitblt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_integrated_enable(MMI_FALSE);
    bitblt = gui_title_show(&MMI_horizontal_tab_bar.title, part);
    wgui_status_icon_integrated_enable(MMI_TRUE);
    if (bitblt)
    {
        gdi_layer_blt_previous(
            MMI_horizontal_tab_bar.title.x,
            MMI_horizontal_tab_bar.title.y,
            MMI_horizontal_tab_bar.title.x + MMI_horizontal_tab_bar.title.width - 1,
            MMI_horizontal_tab_bar.title.y + MMI_horizontal_tab_bar.title.height - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_set_shortcut_count
 * DESCRIPTION
 *  Sets the number of digits allowed in the menu shortcut
 *  handler. This is based on the number of items in the menu.
 * PARAMETERS
 *  n_items     [IN]        number of digits allowed in the menu shortcut
 *                          handler
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_set_shortcut_count(S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_shortcut_set_item_count(&MMI_horizontal_tab_bar.title.sc, n_items);
    width = gui_shortcut_auto_resize(&MMI_horizontal_tab_bar.title.sc, MMI_horizontal_tab_bar.title.height);
    if (!r2lMMIFlag)
    {
        gui_shortcut_move(&MMI_horizontal_tab_bar.title.sc, MMI_horizontal_tab_bar.title.width - width, MMI_horizontal_tab_bar.title.y);
    }
    else
    {
        gui_shortcut_move(&MMI_horizontal_tab_bar.title.sc, MMI_horizontal_tab_bar.title.x, MMI_horizontal_tab_bar.title.y);
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_shortcut_register_callback
 * DESCRIPTION
 *  Registers the keys used by the menu shortcut handler
 * PARAMETERS
 *  pre_goto_funcptr        [IN]      pre goto function pointer  
 *  goto_funcptr            [IN]      goto function pointer  
 *  flag                    [IN]      flag
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_shortcut_register_callback(void (*pre_goto_funcptr) (S32 i), void (*goto_funcptr) (S32 i), U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_title_register_callback(&MMI_horizontal_tab_bar.title, pre_goto_funcptr, goto_funcptr, flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_title_register_keys
 * DESCRIPTION
 *  Registers the keys used by the menu shortcut handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_horizontal_tab_bar_0_key_down, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_1_key_down, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_2_key_down, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_3_key_down, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_4_key_down, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_5_key_down, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_6_key_down, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_7_key_down, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_8_key_down, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_9_key_down, KEY_9, KEY_EVENT_DOWN);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_create_horizontal_tab_bar
 * DESCRIPTION
 *  Cerate horizontal tab bar component in category
 * PARAMETERS
 *  contain_hint            [IN]        Whether the tab bar contains hint area
 *  hint                    [IN]        string of hint
 *  n_item                  [IN]        number of tabs
 *  focused_item            [IN]        focused tab index
 *  keep_pen_context        [IN]        keep pen context or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_create_horizontal_tab_bar(
        BOOL contain_hint,
        UI_string_type hint,
        S8 n_item,
        S8 focused_item,
        MMI_BOOL keep_pen_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_item > UI_MAX_TAB_BAR_ITEMS)
    {
        n_item = UI_MAX_TAB_BAR_ITEMS;
    }

    gui_create_horizontal_tab_bar(
        &MMI_horizontal_tab_bar,
        MMI_HORIZONTAL_TAB_BAR_X,
        MMI_HORIZONTAL_TAB_BAR_Y,
        MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT,
        (S16) (contain_hint ? MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT : 0),
        MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH,
        hint,
        n_item,
        focused_item,
        MMI_tab_bar_items);

    if (contain_hint)
    {
        gui_title_create(
            &MMI_horizontal_tab_bar.title, 
            MMI_horizontal_tab_bar.x, 
            MMI_horizontal_tab_bar.y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, 
            MMI_horizontal_tab_bar.width,
            MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
		gui_shortcut_create(
			&MMI_horizontal_tab_bar.title.sc,
			MMI_horizontal_tab_bar.title.x,
			MMI_horizontal_tab_bar.title.y,
			MMI_horizontal_tab_bar.title.width,
			MMI_horizontal_tab_bar.title.height);
        gui_shortcut_register_callback(
            &MMI_horizontal_tab_bar.title.sc,
            wgui_horizontal_tab_bar_timer_callback,
            wgui_horizontal_tab_bar_shortcut_show_background);
        gui_title_set_theme(&MMI_horizontal_tab_bar.title, current_tab_title_theme);
        gui_title_set_no_icon_shct(&MMI_horizontal_tab_bar.title, MMI_FALSE);
    }

    MMI_horizontal_tab_bar.flags |= UI_TAB_BAR_LOOP;
    gui_horizontal_tab_bar_set_icon_position(&MMI_horizontal_tab_bar, 13, 5);
    if (g_dm_data.s32CatId == 0)
    {
        g_dm_data.s32CatId = MMI_CATEGORYTAB_ID;
    }

#ifdef __MMI_TOUCH_SCREEN__
    if (!keep_pen_context)
    {
        MMI_horizontal_tab_bar_select_callback = NULL;
        MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
        if (MMI_horizontal_tab_bar_first_displayed_on_screen_switched >= 0)
        {
            gui_set_horizontal_tab_bar_display_range(
                &MMI_horizontal_tab_bar,
                MMI_horizontal_tab_bar_first_displayed_on_screen_switched);
        }
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_close_horizontal_tab_bar
 * DESCRIPTION
 *  Close the horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_close_horizontal_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_stop_blinking(&MMI_horizontal_tab_bar);
    gui_shortcut_close(&MMI_horizontal_tab_bar.title.sc);
    MMI_horizontal_tab_bar.title.pre_goto_callback = wgui_horizontal_tab_bar_dummy_goto_item;
    MMI_horizontal_tab_bar.title.goto_callback = wgui_horizontal_tab_bar_dummy_goto_item;
    MMI_horizontal_tab_bar.n_items = 0;
    gui_title_unset_style(&MMI_horizontal_tab_bar.title, GUI_TITLE_STYLE_SCROLLING);    
    gui_title_stop_scrolling(&MMI_horizontal_tab_bar.title);
    
    MMI_horizontal_tab_bar.title.sc.display_enabled = 0;
    
    if (MMI_horizontal_tab_bar.title.icon_ani_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(MMI_horizontal_tab_bar.title.icon_ani_handle);
        MMI_horizontal_tab_bar.title.icon_ani_handle = GDI_ERROR_HANDLE;
    }

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    gui_title_stop_animation(&MMI_horizontal_tab_bar.title);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_horizontal_tab_bar
 * DESCRIPTION
 *  Show the horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_horizontal_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_horizontal_tab_bar.theme->hint_bg_image && title_bg_id == 0)
    {
        //title_bg_id = MMI_horizontal_tab_bar.theme->hint_bg_image;
        gui_add_cleanup_hook(wgui_horizontal_tab_bar_reset_title_bg_id);
    }
    gui_lock_double_buffer();
    gui_show_horizontal_tab_bar(&MMI_horizontal_tab_bar, MMI_FALSE, MMI_FALSE);
    gui_title_change(&MMI_horizontal_tab_bar.title, NULL, NULL, (U8*)MMI_horizontal_tab_bar.hint);
    wgui_status_icon_integrated_enable(MMI_FALSE);
    gui_title_show(&MMI_horizontal_tab_bar.title, GUI_TITLE_PART_ALL);
    wgui_status_icon_integrated_enable(MMI_TRUE);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_horizontal_tab_bar.x,
        MMI_horizontal_tab_bar.y,
        MMI_horizontal_tab_bar.x + MMI_horizontal_tab_bar.width - 1,
        MMI_horizontal_tab_bar.y + MMI_horizontal_tab_bar.height - 1);

    gui_horizontal_tab_bar_start_blinking(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_horizontal_tab_bar_hint_area
 * DESCRIPTION
 *  show hint area of tab
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_horizontal_tab_bar_hint_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_horizontal_tab_bar(&MMI_horizontal_tab_bar, MMI_TRUE, MMI_FALSE);
    wgui_status_icon_integrated_enable(MMI_FALSE);
    gui_title_show(&MMI_horizontal_tab_bar.title, GUI_TITLE_PART_ALL);
    wgui_status_icon_integrated_enable(MMI_TRUE);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_horizontal_tab_bar.x,
        MMI_horizontal_tab_bar.y + MMI_horizontal_tab_bar.tab_area_height,
        MMI_horizontal_tab_bar.x + MMI_horizontal_tab_bar.width - 1,
        MMI_horizontal_tab_bar.y + MMI_horizontal_tab_bar.height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_horizontal_tab_bar_tab_area
 * DESCRIPTION
 *  show tab area of tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  Used in category 435 that popup overlaps with hint area, and we do not want to redraw the
 *  whole screen. As a result, we redraw the tab area only.
 *****************************************************************************/
void wgui_show_horizontal_tab_bar_tab_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_horizontal_tab_bar(&MMI_horizontal_tab_bar, MMI_FALSE, MMI_TRUE);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_horizontal_tab_bar.x,
        MMI_horizontal_tab_bar.y,
        MMI_horizontal_tab_bar.x + MMI_horizontal_tab_bar.width - 1,
        MMI_horizontal_tab_bar.y + MMI_horizontal_tab_bar.tab_area_height - 1);

    gui_horizontal_tab_bar_start_blinking(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_horizontal_tab_bar
 * DESCRIPTION
 *  Move the horizontal tab bar
 * PARAMETERS
 *  x       [IN]        new position
 *  y       [IN]        new position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_horizontal_tab_bar(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_horizontal_tab_bar(&MMI_horizontal_tab_bar, x, y);
    gui_title_move(
        &MMI_horizontal_tab_bar.title, 
        x, 
        y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_home
 * DESCRIPTION
 *  Focus the first item of horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_first_item(&MMI_horizontal_tab_bar);
    wgui_show_horizontal_tab_bar();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_end
 * DESCRIPTION
 *  Focus the last item of horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_last_item(&MMI_horizontal_tab_bar);
    wgui_show_horizontal_tab_bar();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_item
 * DESCRIPTION
 *  Focus certain item of horizontal tab bar
 * PARAMETERS
 *  index       [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_item(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_item(&MMI_horizontal_tab_bar, (S8) index);
    wgui_show_horizontal_tab_bar();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_next_item
 * DESCRIPTION
 *  Focus the next item of horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_next_item(&MMI_horizontal_tab_bar);
    wgui_show_horizontal_tab_bar();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_prev_item
 * DESCRIPTION
 *  Focus the previous item of horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_prev_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_prev_item(&MMI_horizontal_tab_bar);
    wgui_show_horizontal_tab_bar();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_start_blinking
 * DESCRIPTION
 *  Start the blinking of certain tab
 * PARAMETERS
 *  index       [IN]        Index of the item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_start_blinking(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_tab_bar_items[index].flags |= UI_TAB_BAR_ITEM_STATE_BLINKING;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_stop_blinking
 * DESCRIPTION
 *  Stop the blinking of certain tab
 * PARAMETERS
 *  index       [IN]      index of the item  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_stop_blinking(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 old_flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_flags = MMI_tab_bar_items[index].flags;

    MMI_tab_bar_items[index].flags &= ~UI_TAB_BAR_ITEM_STATE_BLINKING;

    /* We need to refresh the tab bar */
    if ((old_flags & UI_TAB_BAR_ITEM_STATE_BLINKING) &&
        gui_horizontal_tab_bar_is_item_displayed(&MMI_horizontal_tab_bar, index))
    {
        wgui_show_horizontal_tab_bar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_get_horizontal_tab_bar_history
 * DESCRIPTION
 *  Focus the previous item of horizontal tab bar
 * PARAMETERS
 *  history     [OUT]   store tab bar history     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_get_horizontal_tab_bar_history(wgui_tab_bar_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history->flags = MMI_horizontal_tab_bar.flags;
    history->first_displayed_item = MMI_horizontal_tab_bar.first_displayed_item;
    history->last_displayed_item = MMI_horizontal_tab_bar.last_displayed_item;
    history->focused_item = MMI_horizontal_tab_bar.focused_item;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_horizontal_tab_bar_history
 * DESCRIPTION
 *  Focus the previous item of horizontal tab bar
 * PARAMETERS
 *  history     [IN] history of tab bar     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_horizontal_tab_bar_history(wgui_tab_bar_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_horizontal_tab_bar.flags = history->flags;
    MMI_horizontal_tab_bar.first_displayed_item = history->first_displayed_item;
    MMI_horizontal_tab_bar.last_displayed_item = history->last_displayed_item;
    MMI_horizontal_tab_bar.focused_item = history->focused_item;
}

#ifdef __MMI_WGUI_MINI_TAB_BAR__

gui_mini_tab_bar_struct wgui_mini_tab_bar;


/*****************************************************************************
 * FUNCTION
 *  wgui_init_mini_tab_bar
 * DESCRIPTION
 *  Initialize mini tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_init_mini_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_mini_tab_bar.flags = 0;
    wgui_mini_tab_bar.num_of_items = 0;

}


/*****************************************************************************
 * FUNCTION
 *  wgui_setup_mini_tab_bar
 * DESCRIPTION
 *  Setup mini tab bar data
 * PARAMETERS
 *  x                   [IN]        X-coordinate of mini tab bar
 *  y                   [IN]        Y-coordinate of mini tab bar
 *  width               [IN]        Width of mini tab bar
 *  height              [IN]        Height of mini tab bar
 *  bg_color            [IN]        Background color of mini tab bar
 *  selected_color      [IN]        Selected item color
 *  normal_color        [IN]        Normal item color
 *  count               [IN]        Number of items in mini tab bar
 *  menu_item_id        [IN]        Menu id array of each item in mini tab bar
 *  item_entry_func     [IN]        Entry function array of each item in mini tab bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_setup_mini_tab_bar(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        color bg_color,
        color selected_color,
        color normal_color,
        U8 count,
        U16 *menu_item_id,
        FuncPtr *item_entry_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_mini_tab_bar.x = x;
    wgui_mini_tab_bar.y = y;
    wgui_mini_tab_bar.width = width;
    wgui_mini_tab_bar.height = height;
    wgui_mini_tab_bar.bg_color = bg_color;
    wgui_mini_tab_bar.selected_item_color = selected_color;
    wgui_mini_tab_bar.normal_item_color = normal_color;
    wgui_mini_tab_bar.flags = 0;

    wgui_mini_tab_bar.num_of_items = count;

    MMI_ASSERT(menu_item_id != NULL);

    for (idx = 0; idx < count; idx++)
    {
        wgui_mini_tab_bar.menu_item_id[idx] = menu_item_id[idx];
        if (item_entry_func != NULL)
        {
            wgui_mini_tab_bar.item_entry_func[idx] = item_entry_func[idx];
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_if_mini_tab_bar_enable
 * DESCRIPTION
 *  check if mini tab bar is enabled
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL MMI_TRUE for enabled mini tab bar, MMI_FALSE else
 *****************************************************************************/
MMI_BOOL wgui_if_mini_tab_bar_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_mini_tab_bar.flags & WGUI_MINI_TAB_BAR_ENABLED)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_if_mini_tab_bar_in_parent
 * DESCRIPTION
 *  check if current screen is the parent of mini tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL MMI_TRUE for yes, MMI_FALSE else
 *****************************************************************************/
MMI_BOOL wgui_if_mini_tab_bar_in_parent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_mini_tab_bar.flags & WGUI_MINI_TAB_BAR_IN_PARENT)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_enable_mini_tab_bar
 * DESCRIPTION
 *  Enable mini tab bar
 * PARAMETERS
 *  item_id     [IN]        Enable the mini tab bar and entry the item with id=item_id
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_enable_mini_tab_bar(U16 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (idx = 0; idx < wgui_mini_tab_bar.num_of_items; idx++)
        if (wgui_mini_tab_bar.menu_item_id[idx] == item_id)
        {
            wgui_mini_tab_bar.curr_index = idx;
            wgui_mini_tab_bar.flags |= WGUI_MINI_TAB_BAR_ENABLED;
            return;
        }
    /* the item is not included in any mini_tab_bar */
    /* MMI_ASSERT(0); */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_disable_mini_tab_bar
 * DESCRIPTION
 *  Disable mini tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_disable_mini_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_mini_tab_bar.flags &= ~WGUI_MINI_TAB_BAR_ENABLED;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mini_tab_bar_set_flag_on
 * DESCRIPTION
 *  API to turn on flag of mini tab bar
 * PARAMETERS
 *  flag        [IN]        Flag to be on
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_mini_tab_bar_set_flag_on(S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_mini_tab_bar.flags |= flag;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mini_tab_bar_set_flag_off
 * DESCRIPTION
 *  API to turn off flag of mini tab bar
 * PARAMETERS
 *  flag        [IN]        Flag to be off
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_mini_tab_bar_set_flag_off(S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_mini_tab_bar.flags &= ~flag;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_mini_tab_bar_func
 * DESCRIPTION
 *  register items entry function of mini tab bar
 * PARAMETERS
 *  menu_item_id        [IN]        Array of ids of menu items
 *  item_entry_func     [IN]        Array of entry functions of menu items
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_mini_tab_bar_func(U16 *menu_item_id, FuncPtr item_entry_func[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;
    U8 count = wgui_mini_tab_bar.num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_entry_func != NULL);

    for (idx = 0; idx < count; idx++)
    {
        if (wgui_mini_tab_bar.menu_item_id[idx] == menu_item_id[idx])
        {
            wgui_mini_tab_bar.item_entry_func[idx] = item_entry_func[idx];
            return;
        }
    }

    MMI_ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mini_tab_bar_goto_next
 * DESCRIPTION
 *  Goto next item of mini tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_mini_tab_bar_goto_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* increase index */
    if (wgui_mini_tab_bar.curr_index == wgui_mini_tab_bar.num_of_items - 1)
    {
        wgui_mini_tab_bar.curr_index = 0;
    }
    else
    {
        wgui_mini_tab_bar.curr_index++;
    }

    /* execute entry function */
    ExecuteItemHiliteHandler(wgui_mini_tab_bar.menu_item_id[wgui_mini_tab_bar.curr_index]);
    execute_left_softkey_function(KEY_EVENT_UP);

    /* delete toppest history */
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mini_tab_bar_goto_prev
 * DESCRIPTION
 *  Goto previous item of mini tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_mini_tab_bar_goto_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* decrease index */
    if (wgui_mini_tab_bar.curr_index == 0)
    {
        wgui_mini_tab_bar.curr_index = wgui_mini_tab_bar.num_of_items - 1;
    }
    else
    {
        wgui_mini_tab_bar.curr_index--;
    }

    /* execute entry function */
    ExecuteItemHiliteHandler(wgui_mini_tab_bar.menu_item_id[wgui_mini_tab_bar.curr_index]);
    execute_left_softkey_function(KEY_EVENT_UP);

    /* delete toppest history */
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_mini_tab_bar
 * DESCRIPTION
 *  Display the mini tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_mini_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;
    S32 x1, x2, y1, y2;
    color bg_color, selected_color, normal_color;
    U16 bar_width, bar_height;
    U16 cell_width, cell_pad = 2, cell_count;
    U16 left_pad;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = wgui_mini_tab_bar.x;
    x2 = wgui_mini_tab_bar.x + wgui_mini_tab_bar.width - 1;
    y1 = wgui_mini_tab_bar.y;
    y2 = wgui_mini_tab_bar.y + wgui_mini_tab_bar.height - 1;
    cell_count = wgui_mini_tab_bar.num_of_items;
    bar_width = wgui_mini_tab_bar.width;
    bar_height = wgui_mini_tab_bar.height;
    bg_color = wgui_mini_tab_bar.bg_color;
    selected_color = wgui_mini_tab_bar.selected_item_color;
    normal_color = wgui_mini_tab_bar.normal_item_color;

    cell_width = (bar_width - cell_pad * (cell_count + 1)) / cell_count;
    left_pad = (bar_width - (cell_width * cell_count) - (cell_pad * (cell_count - 1))) >> 1;

    gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);

    for (idx = 0; idx < cell_count; idx++)
    {
        if (idx == wgui_mini_tab_bar.curr_index)    /* selected item */
        {
            gdi_draw_solid_rect(
                left_pad + (cell_pad + cell_width) * idx,
                y1 + 1,
                left_pad + cell_pad * idx + cell_width * (idx + 1),
                y2 - 1,
                selected_color);
        }
        else    /* normal item */
        {
            gdi_draw_solid_rect(
                left_pad + (cell_pad + cell_width) * idx,
                y1 + 1,
                left_pad + cell_pad * idx + cell_width * (idx + 1),
                y2 - 1,
                normal_color);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_mini_tab_bar_get_index
 * DESCRIPTION
 *  Get the current index of mini tab bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8    current item index of mini tab bar
 *****************************************************************************/
U8 wgui_mini_tab_bar_get_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_mini_tab_bar.curr_index;
}

#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_set_horizontal_tab_bar_select_callback
 * DESCRIPTION
 *  Focus the previous item of horizontal tab bar
 * PARAMETERS
 *  select_callback     [IN]        select callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_horizontal_tab_bar_select_callback(void (*select_callback) (int index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    MMI_horizontal_tab_bar_select_callback = select_callback;
#endif 
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_enable_horizontal_tab_bar_pen_events
 * DESCRIPTION
 *  Handle pen events in horizontal tab bar and
 * PARAMETERS
 *  enable      [IN]        enable pen event or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_enable_horizontal_tab_bar_pen_events(BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        MMI_horizontal_tab_bar.flags &= ~UI_TAB_BAR_DISABLE_PEN;
    }
    else
    {
        MMI_horizontal_tab_bar.flags |= UI_TAB_BAR_DISABLE_PEN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_restore_offset_timer_hdlr
 * DESCRIPTION
 *  Handle pen events in horizontal tab bar and
 * PARAMETERS
 *  void
 *  tb(?)
 *  pen_event(?)
 *  x(?)
 *  y(?)
 * RETURNS
 *  void
 *****************************************************************************/
/* Timer handler to restore the display range of tab bar */
static void wgui_horizontal_tab_bar_restore_offset_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_horizontal_tab_bar_first_displayed_before_pen_down >= 0)
    {
        gui_set_horizontal_tab_bar_display_range(
            &MMI_horizontal_tab_bar,
            MMI_horizontal_tab_bar_first_displayed_before_pen_down);
        wgui_show_horizontal_tab_bar_tab_area();

        MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_abort_restore_offset_timer
 * DESCRIPTION
 *  abort restore offset timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_abort_restore_offset_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
}

/* Start timer to restore the display range of tab bar */


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_start_restore_offset_timer
 * DESCRIPTION
 *  start restore offset timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_start_restore_offset_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_horizontal_tab_bar_first_displayed_before_pen_down >= 0)
    {
        gui_start_timer(WGUI_TAB_BAR_RESTORE_DISPLAY_TIME, wgui_horizontal_tab_bar_restore_offset_timer_hdlr);
        gui_add_cleanup_hook(wgui_horizontal_tab_bar_abort_restore_offset_timer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_translate_pen_event
 * DESCRIPTION
 *  translate pen event function
 * PARAMETERS
 *  pen_event       [IN]       pen event 
 *  x               [IN]       pen position
 *  y               [IN]       pen position
 * RETURNS
 *  
 *****************************************************************************/
BOOL wgui_horizontal_tab_bar_translate_pen_event(mmi_pen_event_type_enum pen_event, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_tab_bar_pen_enum tab_event;
    gui_pen_event_param_struct tab_param;
    horizontal_tab_bar *tb = &MMI_horizontal_tab_bar;
    S32 prev_fdisp; /* first displayed item before pen down */
    S32 prev_focus; /* focused item before pen down */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_fdisp = tb->first_displayed_item;
    prev_focus = tb->focused_item;
    ret = gui_horizontal_tab_bar_translate_pen_event(tb, pen_event, x, y, &tab_event, &tab_param);

    if (ret)
    {
        if (pen_event == MMI_PEN_EVENT_DOWN)
        {
            gui_cancel_timer(wgui_horizontal_tab_bar_restore_offset_timer_hdlr);
            if (MMI_horizontal_tab_bar_first_displayed_before_pen_down < 0)
            {
                MMI_horizontal_tab_bar_first_displayed_before_pen_down = prev_fdisp;
            }
        }

        if (tab_event == GUI_TAB_BAR_PEN_NEED_REDRAW)
        {
            wgui_show_horizontal_tab_bar_tab_area();
        }
        else if (tab_event == GUI_TAB_BAR_PEN_JUMP_TO_I)
        {
            if (MMI_horizontal_tab_bar_select_callback)
            {
                MMI_horizontal_tab_bar_first_displayed_on_screen_switched = tb->first_displayed_item;
                MMI_horizontal_tab_bar_select_callback(tab_param._u.i);
                MMI_horizontal_tab_bar_first_displayed_on_screen_switched = -1;
            }
        }

        if ((pen_event == MMI_PEN_EVENT_ABORT || pen_event == MMI_PEN_EVENT_UP) &&
            MMI_horizontal_tab_bar.focused_item == prev_focus &&
            MMI_horizontal_tab_bar.first_displayed_item != MMI_horizontal_tab_bar_first_displayed_before_pen_down)
        {
            if (gui_horizontal_tab_bar_is_item_displayed(tb, tb->focused_item))
            {
                MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
            }
            else
            {
                wgui_horizontal_tab_bar_start_restore_offset_timer();
            }
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

