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
*  wgui_asyncdynamic_menus.c
*
* Project:
* --------
*   PlutoMMI
*
* Description:
* ------------
*   In order to use limited memory (size decided in compile-time) to load unlimited items (size decide in run-time) 
*   to a category screen, a modification in MMI for dynamic item loading is required as the following.
*
* Author:
* -------
*  Glory Hung (mtk01688)
*
*******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "CustMenuRes.h"
#include "CustDataRes.h"
#include "wgui_fixed_menus.h"
#include "wgui_asyncdynamic_menus.h"
#include "gui_asyncdynamic_menus.h"
#include "wgui_categories.h"
#include "gui_custom_menus.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern void dummy_highlight_handler(S32 item_index);
extern void (*_MMI_hide_fixed_list_menu) (void);
extern void wgui_display_fixed_text_list_pop_up_description(void);
extern void wgui_display_asyncdynamic_text_list_pop_up_description(void);

extern S32 gui_asyncdynamic_list_error;

#if( UI_ENABLE_FRAME_SKIPPING )
extern S32 wgui_fixed_list_menu_frame_counter;
#endif 

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  reset_asyncdynamic_list
 * DESCRIPTION
 *  Reset the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_asyncdynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear asyncdynamic list pre-display handler */
    register_asyncdynamic_list_pre_display_handler(NULL);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 
#if( UI_ENABLE_FRAME_SKIPPING )
    gui_cancel_timer(wgui_asyncdynamic_list_menu_end_frame);
    wgui_fixed_list_menu_frame_counter = 0;
#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
    normal_fixed_list();
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)      /* 072505 Calvin modified */
    gui_reset_transparent_source_layer();
#endif 
    clear_keyboard_key_handler();
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);

    MMI_fixed_list_menu.item_highlighted = dummy_highlight_handler;
    wgui_text_menuitem_reset_scrolling();

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    reset_fixed_icontext_menuitem_type();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  show_asyncdynamic_list
 * DESCRIPTION
 *  Show the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_asyncdynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
    {
        _MMI_hide_fixed_list_menu();
    }
    gui_hide_animations();
    gui_show_asyncdynamic_list_menu(&MMI_fixed_list_menu);
    wgui_display_asyncdynamic_text_list_pop_up_description();

    wgui_list_menu_show_empty_label_if_needed();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y - 1, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);     /* 052305 Calvin modified */
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  redraw_asyncdynamic_list
 * DESCRIPTION
 *  Redraw the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_asyncdynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == ANI_BG_LIST_MENU)
    {
        return;
    }
#if( UI_ENABLE_FRAME_SKIPPING )
    if (wgui_fixed_list_menu_frame_counter > 0)
    {
        wgui_fixed_list_menu_frame_counter++;
        gui_show_asyncdynamic_list_menu_no_draw(&MMI_fixed_list_menu);
    }
    else
    {
        wgui_fixed_list_menu_frame_counter = 1;
        gui_show_asyncdynamic_list_menu_no_draw(&MMI_fixed_list_menu);
        gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_asyncdynamic_list_menu_end_frame);
    }
#else /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
    show_asyncdynamic_list();
#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_list_effect_slide_start();
    
    gui_asyncdynamic_list_menu_goto_previous_item(&MMI_fixed_list_menu);

    if (gui_asyncdynamic_list_error)
    {
        gui_list_effect_slide_end();
        gui_list_effect_slide_stop();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        if (gui_get_current_list_effect() == MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE)
        {
            gdi_layer_blt_previous(0, 0, 0, 0);
        }
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

        return;
    }
    
    redraw_asyncdynamic_list();

    gui_list_effect_slide_end();      
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_list_effect_slide_start();
    
    gui_asyncdynamic_list_menu_goto_next_item(&MMI_fixed_list_menu);

    if (gui_asyncdynamic_list_error)
    {
        gui_list_effect_slide_end();
        gui_list_effect_slide_stop();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        if (gui_get_current_list_effect() == MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE)
        {
            gdi_layer_blt_previous(0, 0, 0, 0);
        }
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

        return;
    }

    redraw_asyncdynamic_list();

    gui_list_effect_slide_end();    
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    /* To avoid highlight effect when user jump to wrong menu index */
    if (item_index >= MMI_fixed_list_menu.n_items)
    {
        return;
    }
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
    gui_asyncdynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    
    redraw_asyncdynamic_list();
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the asyncdynamic list is shown by the draw manager.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index < 0)
    {
        item_index = 0;
    }
    if (item_index > (MMI_fixed_list_menu.n_items - 1))
    {
        item_index = MMI_fixed_list_menu.n_items - 1;
    }
    /* 
     * This is used in menu setup. Highlighted item is set to -1 at first because
     * 1. gui_asyncdynamic_list_menu_goto_item() might return directly if (highlighted_item==m->highlighted_item)
     * 2. m->item_remove_highlight_function will not be invoked on the previous highlighted item.
     */
    MMI_fixed_list_menu.highlighted_item = -1;

    gui_asyncdynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(asyncdynamic_list_goto_item);
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_keys
 * DESCRIPTION
 *  Register key handlers of the asyncdynamic list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_keyboard_key_handler();
    SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


#if( UI_ENABLE_FRAME_SKIPPING )

/*****************************************************************************
 * FUNCTION
 *  wgui_asyncdynamic_list_menu_end_frame
 * DESCRIPTION
 *  Show the dynamic list for the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_asyncdynamic_list_menu_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_menu_frame_counter >= 1)
    {
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_hide_animations();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
    #endif 
        gui_show_asyncdynamic_list_menu(&MMI_fixed_list_menu);
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
    #endif 
        wgui_display_asyncdynamic_text_list_pop_up_description();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_BLT_double_buffer(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_fixed_list_menu_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_asyncdynamic_list_menu_end_frame);
    }
}

#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_pre_display_handler
 * DESCRIPTION
 *  Register the handler function before displaying the menu.
 * PARAMETERS
 *  (*pre_display_handler)(void)       [IN]     pre-display callback function
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_pre_display_handler(void (*pre_display_handler)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.pre_display_function = pre_display_handler;
}


