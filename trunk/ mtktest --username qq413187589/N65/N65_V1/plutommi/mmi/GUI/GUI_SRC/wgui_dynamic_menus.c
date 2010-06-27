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
*  wgui_dynamic_menus.c
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
#include "CustDataRes.h"
#include "wgui_fixed_menus.h"
#include "wgui_dynamic_menus.h"
#include "wgui_categories.h"
#include "gui_custom_menus.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
extern S32 wgui_fixed_list_menu_frame_counter;
#endif

extern void dummy_highlight_handler(S32 item_index);
extern void (*_MMI_hide_fixed_list_menu) (void);
extern void wgui_display_fixed_text_list_pop_up_description(void);
extern void wgui_display_dynamic_text_list_pop_up_description(void);

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  reset_dynamic_list
 * DESCRIPTION
 *  Reset the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_dynamic_list(void)
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

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
    gui_cancel_timer(wgui_dynamic_list_menu_end_frame);
    wgui_fixed_list_menu_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
    normal_fixed_list();

#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
    gui_reset_transparent_source_layer();
#endif 

    clear_keyboard_key_handler();
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    MMI_fixed_list_menu.item_highlighted = dummy_highlight_handler;
    wgui_text_menuitem_reset_scrolling();

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    reset_fixed_icontext_menuitem_type();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  show_dynamic_list
 * DESCRIPTION
 *  Show the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_dynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
    
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 
#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)
    wgui_two_line_stop_scroller();
#endif

    /* call pre-display callback */
    if (MMI_fixed_list_menu.pre_display_function)
    {
        MMI_fixed_list_menu.pre_display_function();
    }
    
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
    {
        _MMI_hide_fixed_list_menu();
    }
    
    gui_show_dynamic_list_menu(&MMI_fixed_list_menu);
    wgui_display_dynamic_text_list_pop_up_description();
    gui_BLT_double_buffer(
        MMI_fixed_list_menu.x,
        MMI_fixed_list_menu.y,
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);

    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);        
}


/*****************************************************************************
 * FUNCTION
 *  redraw_dynamic_list
 * DESCRIPTION
 *  Redraw the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_dynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == ANI_BG_LIST_MENU)
    {
        return;
    }
    
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
    
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
    if (wgui_fixed_list_menu_frame_counter > 0)
    {
        wgui_fixed_list_menu_frame_counter++;
        gui_show_dynamic_list_menu_no_draw(&MMI_fixed_list_menu);
    }
    else
    {
        wgui_fixed_list_menu_frame_counter = 1;
        gui_show_dynamic_list_menu_no_draw(&MMI_fixed_list_menu);
        gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_dynamic_list_menu_end_frame);
    }
#else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
    show_dynamic_list();
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 

    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);        
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

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
    
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
    
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_list_effect_slide_start();

    gui_dynamic_list_menu_goto_previous_item(&MMI_fixed_list_menu);

    redraw_dynamic_list();

    gui_list_effect_slide_end();    

    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);       
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

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

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_list_effect_slide_start();

    gui_dynamic_list_menu_goto_next_item(&MMI_fixed_list_menu);

    redraw_dynamic_list();

    gui_list_effect_slide_end();

    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);        
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

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

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    /* To handle the redraw of hilighter if item index is greater then no of items */
    if (item_index >= MMI_fixed_list_menu.n_items)
    {
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(act_lcd);       
        return;
    }
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    redraw_dynamic_list();

    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);            
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the dynamic list is shown by the draw manager.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
    
    if (item_index < 0)
    {
        item_index = 0;
    }
    if (item_index > (MMI_fixed_list_menu.n_items - 1))
    {
        item_index = MMI_fixed_list_menu.n_items - 1;
    }
    MMI_fixed_list_menu.highlighted_item = -1;
    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);           
}


/*****************************************************************************
 * FUNCTION
 *  register_dynamic_list_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dynamic_list_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(dynamic_list_goto_item);
}


/*****************************************************************************
 * FUNCTION
 *  register_dynamic_list_keys
 * DESCRIPTION
 *  Register key handlers of the dynamic list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dynamic_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_keyboard_key_handler();
    SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))


/*****************************************************************************
 * FUNCTION
 *  wgui_dynamic_list_menu_end_frame
 * DESCRIPTION
 *  Show the dynamic list for the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_dynamic_list_menu_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_menu_frame_counter >= 1)
    {
        gdi_lcd_get_active(&act_lcd);
        gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
        gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
    
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_hide_animations();

        gui_lock_double_buffer();
        gui_show_dynamic_list_menu(&MMI_fixed_list_menu);
        gui_unlock_double_buffer();
        
        wgui_display_dynamic_text_list_pop_up_description();
        gui_BLT_double_buffer(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);

        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(act_lcd);        

        wgui_fixed_list_menu_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_dynamic_list_menu_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  DynamicListIncreaseItem
 * DESCRIPTION
 *  Increase the total number of dynamic item.
 * PARAMETERS
 *  steps       [IN]        Number of items to be increased
 * RETURNS
 *  void
 *****************************************************************************/
void DynamicListIncreaseItem(S16 steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_item_buffer.n_total_items = dynamic_item_buffer.n_total_items + steps;
    MMI_fixed_list_menu.n_items = MMI_fixed_list_menu.n_items + steps;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicListGetItems
 * DESCRIPTION
 *  Return total number of dynamic items and the requested item text from the dynamic buffer.
 *  The caller must take care of the validity of the specified item in the buffer.
 * PARAMETERS
 *  string          [OUT]       Requested item text
 *  item_index      [IN]        Index of the requested item
 * RETURNS
 *  total number of dynamic items
 *****************************************************************************/
S32 DynamicListGetItems(U8 *string, U16 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy((S8*) string, (S8*) MMI_fixed_icontext_menuitems[(item_index) % 32].item_text);
    }

    return MMI_fixed_list_menu.n_items;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicListGetHighlightedItem
 * DESCRIPTION
 *  Return the index and text of the highlighted item.
 * PARAMETERS
 *  string      [OUT]       Highlighted item text
 * RETURNS
 *  Highlighted item index
 *****************************************************************************/
S32 DynamicListGetHighlightedItem(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy(
            (S8*) string,
            (S8*) MMI_fixed_icontext_menuitems[(MMI_fixed_list_menu.highlighted_item) % 32].item_text);
    }

    return MMI_fixed_list_menu.highlighted_item;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicGetFirstDisplayedItem
 * DESCRIPTION
 *  Return the index and text of first displayed item.
 * PARAMETERS
 *  string      [OUT]       First displayed item text
 * RETURNS
 *  First displayed item index
 *****************************************************************************/
S32 DynamicGetFirstDisplayedItem(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy(
            (S8*) string,
            (S8*) MMI_fixed_icontext_menuitems[(MMI_fixed_list_menu.first_displayed_item) % 32].item_text);
    }

    return MMI_fixed_list_menu.first_displayed_item;
}


