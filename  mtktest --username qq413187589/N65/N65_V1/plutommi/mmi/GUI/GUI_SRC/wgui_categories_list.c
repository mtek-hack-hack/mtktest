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
 *   wgui_categories_list.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  list category related funtions
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
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "GlobalDefs.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "gui_themes.h"
#include "wgui_categories.h"
#include "wgui_status_icons.h"
#include "wgui_softkeys.h"
#include "wgui_categories_calendar.h"
#include "wgui_categories_list.h"
#include "MMI_features.h"
#include "DebugInitDef.h"
#include "wgui_draw_manager.h"
#include "DateTimeGprot.h"
#include "DateTimeType.h"
#include "wgui_categories_defs.h"
#include "wgui_softkeys.h"
#include "wgui_categories_defs.h"
#include "CalendarDef.h"        /* Calendar image */
#include "CalendarProt.h"
#include "wgui_calendar.h"
#include "Gui_Setting.h"
#include "gui_windows.h"
#include "ScrMemMgrGprot.h"
#include "FrameworkStruct.h"
#include "gdi_include.h"
#include "lcd_if.h"
#include "ScreenRotationGprot.h"


extern void wgui_title_set_no_icon_shct(MMI_BOOL no_icon_shct);


/*----------------------------Async Dynamic Multi Row List-----------------------------*/
// *************************************************************************************//
extern S32 gui_asyncdynamic_list_error;
extern U16 title_bg_id;


/*****************************************************************************
 * FUNCTION
 *  mmi_cat_refresh_asyncdynamic_list
 * DESCRIPTION
 *  Refresh asyncdynamic list
 *  Please notice that only those categories which do not have list effect are suggested to refresh
 * PARAMETERS
 *  number_of_items     [IN]        number of menu-items
 *  highlighted_item    [IN]        currently highlighted item
 *  get_item_func       [IN]        get item function callback
 *  get_hint_func       [IN]        get hint function callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cat_refresh_asyncdynamic_list(
        S32 number_of_items,
        S32 highlighted_item,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    
    gui_asyncdynamic_list_error = 0;

    MMI_fixed_list_menu.n_items = number_of_items;

    MMI_menu_shortcut_number = highlighted_item + 1;
    set_menu_item_count(number_of_items);

    init_asyncdynamic_item_buffer(number_of_items, get_item_func, get_hint_func);

    asyncdynamic_list_goto_item_no_redraw(highlighted_item);
    MMI_ASSERT (!gui_asyncdynamic_list_error)

    set_asyncdynamic_pop_up_descriptions(highlighted_item);

    gdi_layer_unlock_frame_buffer();

    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  cat85_clear_icon_bg
 * DESCRIPTION
 *  Clear button background function
 * PARAMETERS
 *  button      [IN]        Button pointer
 * RETURNS
 *  void
 *****************************************************************************/
void cat85_clear_icon_bg(void *button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = (icontext_button*) button;
    S32 x1 = b->x;
    S32 y1 = b->y;
    S32 x2 = b->x + b->width - 1;
    S32 y2 = b->y + b->height - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    //gdi_layer_set_clip(x1, y1, x2, y2);
    //gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    //gdi_layer_pop_clip();

    gdi_layer_set_clip(x1, y1, x2 + 1, y2 + 1);
    gdi_draw_solid_rect(MMI_title_x, MMI_title_y, MMI_title_x + MMI_title_width - 1, MMI_title_y + MMI_title_height - 1, GDI_COLOR_TRANSPARENT);    /* 061705 Calvin added */
    if (title_bg_id != 0)
    {
        gdi_image_draw_id(MMI_title_x, MMI_title_y, title_bg_id);
    }
    else
    {
        gui_draw_filled_area(
            MMI_title_x,
            MMI_title_y,
            MMI_title_x + MMI_title_width - 1,
            MMI_title_y + MMI_title_height - 1,
            current_UI_theme->window_title_theme->active_filler);
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory85Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory85Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    title_bg_id = 0;
    MMI_disable_title_shortcut_display = 0;
    disable_menu_shortcut_box_display = 0;

    wgui_reset_touch_title_bar_buttons();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
}

// *************************************************************************************//


/*****************************************************************************
 * FUNCTION
 *  ShowCategory85Screen
 * DESCRIPTION
 *  category screen of integrated calendar (daily)
 * PARAMETERS
 *  title                   [IN]         
 *  title_icon              [IN]          
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  number_of_items         [IN]        
 *  get_item_func           [IN]        
 *  get_hint_func           [IN]        
 *  highlighted_item        [IN]        
 *  main_icon               [IN]        
 *  sub_icon              [IN]        
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory85Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U16 main_icon,
        U16 sub_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 shortcut_width;
    U8 h_flag;
    PU8 img;
    S32 h, w, h1, w1, text_width, text_width1;
    S32 font_height_m;
    UI_fixed_icontext_list_menuitem_theme theme;
    U16 btn_prev_item_id = 0, btn_next_item_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset The Error Variable */
    gui_asyncdynamic_list_error = 0;
    /* Set The Application Side Variable To True */
    
    gdi_layer_lock_frame_buffer();

    MMI_menu_shortcut_number = -1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();
    create_fixed_icontext_list_menuitems(2, 2);

    img = (U8*) GetImage(main_icon);
    gui_measure_image(img, &w, &h);

    if (w == 0)
    {
        w = CAT85_MAIN_IMAGE_WIDTH;
    }
    if (h == 0)
    {
        h = CAT85_MAIN_IMAGE_HEIGHT;
    }

    img = (U8*) GetImage(sub_icon);
    gui_measure_image(img, &w1, &h1);

    if (w1 == 0)
    {
        w1 = CAT85_SUB_IMAGE_WIDTH;
    }
    if (h1 == 0)
    {
        h1 = CAT85_SUB_IMAGE_HEIGHT;
    }

    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - w1 - CAT85_MENUITEM_OFFSET*3 - 3;
    text_width1 = UI_device_width - MMI_fixed_list_menu.vbar.width - w - CAT85_MENUITEM_OFFSET*3 - 3;

    //gui_set_font(&MMI_small_font);
    //font_height_s = gui_get_character_height();
    gui_set_font(&MMI_medium_font);
    /* It may contain non-alphanumeric characters like Chinese */
	font_height_m = Get_CharHeightOfAllLang(MEDIUM_FONT);
    set_fixed_icontext_list_text_coordinates(
        0,
        CAT85_MENUITEM_OFFSET,
        CAT85_MENUITEM_OFFSET,
        text_width,
        font_height_m);
    set_fixed_icontext_list_icon_coordinates(
        0,
        UI_device_width - MMI_fixed_list_menu.vbar.width - CAT85_MENUITEM_OFFSET - w1 - 3,
        CAT85_MENUITEM_OFFSET,
        w1,
        h1);
    set_fixed_icontext_list_icon_coordinates(
        1,
        CAT85_MENUITEM_OFFSET,
        MMI_MULTIROW_MENUITEM_HEIGHT - CAT85_MENUITEM_OFFSET - h,
        w,
        h);
    set_fixed_icontext_list_text_coordinates(
        1,
        CAT85_MENUITEM_OFFSET + w + CAT85_MENUITEM_OFFSET,
        MMI_MULTIROW_MENUITEM_HEIGHT - CAT85_MENUITEM_OFFSET - font_height_m,
        text_width1,
        font_height_m);
    associate_fixed_multirow_list_list(MMI_MULTIROW_MENUITEM_HEIGHT);
    memcpy(
        (U8*) & theme,
        (U8*) current_fixed_icontext_list_menuitem_theme,
        sizeof(UI_fixed_icontext_list_menuitem_theme));
    theme.text_fonts[0] = &MMI_small_font;
    theme.text_fonts[1] = &MMI_default_font;
    fixed_icontext_list_menuitem_apply_theme(&theme);
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;  /* 111306 scrolling */

#ifdef __MMI_SCREEN_ROTATE__
    if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
    {    
        MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
        MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
    }

    MMI_current_menu_type = LIST_MENU;

    MMI_fixed_list_menu.n_items = number_of_items;
    if (!init_asyncdynamic_item_buffer(number_of_items, get_item_func, get_hint_func))
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    register_asyncdynamic_list_keys();

    register_fixed_list_highlight_handler(asyncdynamic_list_highlight_handler);
    
    if (wgui_is_touch_title_bar_buttons())
    {
        dm_data.s32CatId = MMI_CATEGORY85_ID;
    }
    else
    {
        dm_data.s32CatId = MMI_CATEGORY85_NO_BUTTON_ID;
    }
    
    h_flag = set_list_menu_category_history((U16)dm_data.s32CatId, history_buffer);
    asyncdynamic_list_goto_item_no_redraw(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);
    if (gui_asyncdynamic_list_error)
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_RIGHT_JUSTIFY;

    MMI_title_string = (UI_string_type) title;
    if (wgui_is_touch_title_bar_buttons())
    {
        MMI_title_icon = NULL;
        MMI_disable_title_shortcut_display = 1;
        disable_menu_shortcut_box_display = 1;
        btn_prev_item_id = dm_add_button(
                            NULL,
                            get_image(LEFT_RED_ARROW),
                            get_image(LEFT_RED_ARROW),
                            cat85_clear_icon_bg);
        btn_next_item_id = dm_add_button(
                            NULL,
                            get_image(RIGHT_RED_ARROW),
                            get_image(RIGHT_RED_ARROW),
                            cat85_clear_icon_bg);
        title_bg_id = IMAGE_VIEW_TITLEBAR_BG;   /* for showing different title bar. */
    }
    else
    {
        wgui_title_set_no_icon_shct(MMI_TRUE);
        MMI_title_icon = (PU8) get_image(title_icon);
    }
    set_menu_item_count(number_of_items);
    register_asyncdynamic_list_shortcut_handler();

#if defined(__MMI_TOUCH_SCREEN__)
    if (wgui_is_touch_title_bar_buttons())
    {
        /* register the handler for pen event down istead of pen event up */
        dm_register_button_functions(btn_prev_item_id, KEY_EVENT_UP, gMMI_touch_title_button1_up_handler);
        dm_register_button_functions(btn_next_item_id, KEY_EVENT_UP, gMMI_touch_title_button2_up_handler);
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    resize_asyncdynamic_icontext_menuitems_to_list_width();
    set_asyncdynamic_pop_up_descriptions(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory85Screen;

    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
* Category 384
* Dynamic icon-text list with check-box
*****************************************************************************/
static U8* cat384_info_message = NULL;
static scrolling_text cat384_info_text;
#define CAT384_MARGIN_GAP   2


/*****************************************************************************
 * FUNCTION
 *  DrawCate384CategoryControlAreaScrollingText
 * DESCRIPTION
 *  draw the scrolling text of category 384
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate384CategoryControlAreaScrollingText(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&cat384_info_text);
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate384CategoryControlArea
 * DESCRIPTION
 *  draw the information message for category 384
 * PARAMETERS
 *  coordinate      [IN] Coordinated of the control area     
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate384CategoryControlAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_push_clip();
	gui_reset_clip();
#ifdef __MMI_MAINLCD_128X128__
    gdi_draw_solid_rect(
        x1, y1, x2, y2,
        GDI_COLOR_WHITE);
#else /* __MMI_MAINLCD_128X128__ */
    gdi_draw_solid_rect(
        x1, y1, x2, y2,
        GDI_COLOR_TRANSPARENT);
#endif /* __MMI_MAINLCD_128X128__ */
	gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate384CategoryControlArea
 * DESCRIPTION
 *  draw the information message for category 384
 * PARAMETERS
 *  coordinate      [IN] Coordinated of the control area     
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate384CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawCate384CategoryControlAreaBackground(
        MMI_CONTENT_X,
        MMI_CONTENT_Y,
        MMI_CONTENT_X + MMI_CONTENT_WIDTH - 1,
        MMI_CONTENT_Y + MMI_MENUITEM_HEIGHT - 1);

    gui_show_scrolling_text(&cat384_info_text);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory384Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                   [IN] Char array of title
 *  title_icon              [IN] Byte array of title icon
 *  left_softkey            [IN] String ID of left softkey
 *  left_softkey_icon       [IN] Image ID of left softkey icon
 *  right_softkey           [IN] String ID of right softkey
 *  right_softkey_icon      [IN] Image ID of right softkey icon
 *  info_message            [IN] Char array of information message
 *  number_of_items         [IN] Number of items of list
 *  get_item_func           [IN] Get item function pointer
 *  get_hint_func           [IN] Get hint function pointer
 *  get_state_func          [IN] Get state of check-box function pointer
 *  set_state_func          [IN] Set state of check-box function pointer
 *  highlighted_item        [IN] Currently highlighted item
 *  history_buffer          [IN] History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory384Screen(
        UI_string_type title,
        PU8 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8* info_message,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    // gui_block_list_effect();
#endif

    gdi_layer_lock_frame_buffer();

    /* set title */
    MMI_title_string = (UI_string_type)title;
    MMI_title_icon = (PU8)title_icon;
    MMI_menu_shortcut_number = -1;

    /* set softkey */
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();    

    /* initialize list */
    MMI_current_menu_type = LIST_MENU;
    create_fixed_icontext_menuitems();
    resize_fixed_list(MMI_content_width, MMI_content_height);
    associate_fixed_icontext_list();
    init_dynamic_item_buffer(number_of_items, get_item_func, get_hint_func, UI_dummy_function);
    MMI_fixed_list_menu.n_items = number_of_items;

    /* set list keys */
    register_dynamic_list_shortcut_handler();
    register_dynamic_list_keys();
    
    /* set information message */
    cat384_info_message = info_message;

    /* adjust list */
    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_positions(2*MMI_ICONTEXT_MENUITEM_HEIGHT + 3, 0, MMI_ICONTEXT_MENUITEM_HEIGHT + 2, 0);
    register_fixed_list_highlight_handler(dynamic_list_highlight_handler);

    /* set check-box */
    wgui_menuitem_set_icontext_checkbox_position(1, 0);
    wgui_menuitem_register_icontext_checkbox_callback(set_state_func, get_state_func);

    /* set hint */
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    if (get_hint_func)
    {
        wgui_enable_hint_highlight_in_icontext_menuitem();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        gui_block_list_effect();
#endif 
    }
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

    /* set the layout of the list */
    if (cat384_info_message != NULL)
    {
        gui_create_scrolling_text(
            &cat384_info_text,
            MMI_CONTENT_X + CAT384_MARGIN_GAP,
            MMI_CONTENT_Y,
            MMI_CONTENT_WIDTH - CAT384_MARGIN_GAP*2,
            MMI_MENUITEM_HEIGHT,
            (UI_string_type) cat384_info_message,
            DrawCate384CategoryControlAreaScrollingText,
            DrawCate384CategoryControlAreaBackground,
#ifdef __MMI_MAINLCD_128X128__
            gui_color(0, 0, 0),
            gui_color(255, 255, 255)
#else /* __MMI_MAINLCD_128X128__ */
		    *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255)
#endif /* __MMI_MAINLCD_128X128__ */
		    );

        move_fixed_list(MMI_CONTENT_X, MMI_CONTENT_Y + MMI_MENUITEM_HEIGHT);
        resize_fixed_list(MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT);
    }
    else
    {
        move_fixed_list(MMI_CONTENT_X, MMI_CONTENT_Y);
        resize_fixed_list(MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT);
    }

    /* set highlight */
    h_flag = set_list_menu_category_history(MMI_CATEGORY384_ID, history_buffer);
    dynamic_list_goto_item_no_redraw(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);
    set_dynamic_pop_up_descriptions(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);

    gdi_layer_unlock_frame_buffer();

    /* set draw manager */
    ExitCategoryFunction = ExitCategory384Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    if (cat384_info_message != NULL)
    {
        dm_register_category_controlled_callback(DrawCate384CategoryControlArea);
    }
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY384_ID;
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);

    /* redraw category screen */
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory384Screen
 * DESCRIPTION
 *  exit category 384
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory384Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    // gui_unblock_list_effect();
#endif
    cat384_info_message = NULL;
	gui_scrolling_text_stop(&cat384_info_text);
    ExitCategory184Screen();
}

#ifdef __MMI_CAT265_SUPPORT__//051507 channel list

/*-------------------------------
External Global variables
-------------------------------*/
extern S32 gui_asyncdynamic_list_error;

/*-------------------------------
External Global Functions
-------------------------------*/

/*-------------------------------
Global variables
-------------------------------*/
static U8 *wgui_cat265_title = NULL;
static scrolling_text wgui_cat265_title_scrolling_text;
static U8* wgui_cat265_preview_buf = NULL;
static gdi_handle* wgui_cat265_preview_handle = NULL;
static U32 wgui_cat265_blt_layer_flag = 0;
static U32 wgui_cat265_preview_layer_flag = 0;
static FuncPtr wgui_cat265_pre_highlight_callback = NULL;
static LayerRedrawCallback wgui_cat265_redraw_preview_area = NULL;
static GetAsyncItemFuncPtr wgui_cat265_get_item = NULL;
static GetAsyncHintFuncPtr wgui_cat265_get_hint = NULL;


/***************************************************************************** 
* Local Function
*****************************************************************************/

/*----------------------------Async Dynamic Multi Row List-----------------------------*/
// *************************************************************************************//


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_set_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat265_set_title(U8 *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat265_title = title;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_scrolling_text_draw_background
 * DESCRIPTION
 *  draw background callback function of scrolling text of category265
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat265_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_scrolling_timer
 * DESCRIPTION
 *  timer callback of category265scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer(?)
 *****************************************************************************/
static void wgui_cat265_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&wgui_cat265_title_scrolling_text);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_create_scrolling_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat265_create_scrolling_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_scrolling_text(
        &wgui_cat265_title_scrolling_text,
        CAT265_TITLE_X,
        CAT265_TITLE_Y,
        CAT265_TITLE_WIDTH,
        CAT265_TITLE_HEIGHT,
        (UI_string_type) wgui_cat265_title,
        wgui_cat265_scrolling_timer,
        wgui_cat265_scrolling_text_draw_background,
        *current_MMI_theme->list_normal_text_color,
        *current_MMI_theme->list_normal_text_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_list_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat265_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Process before we change the highlight, ex. stop preview */
    if(wgui_cat265_pre_highlight_callback)
    {
        wgui_cat265_pre_highlight_callback();
    }

    /* Process the highlight */
    MMI_highlighted_item_text = get_asyncdynamic_item_text(item_index);
    MMI_list_highlight_handler(item_index);
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 

    /* update title scrolling text */
    gui_scrolling_text_stop(&wgui_cat265_title_scrolling_text);
    wgui_cat265_create_scrolling_title();
    gui_show_scrolling_text(&wgui_cat265_title_scrolling_text);

    /* Process after we change the highlight, ex. redraw preview */
    if(wgui_cat265_redraw_preview_area && wgui_cat265_preview_handle)
    {
        wgui_cat265_redraw_preview_area(*wgui_cat265_preview_handle, 
                                        wgui_cat265_blt_layer_flag,
                                        wgui_cat265_preview_layer_flag, 
                                        CAT265_PREVIEW_X, 
                                        CAT265_PREVIEW_Y, 
                                        CAT265_PREVIEW_WIDTH, 
                                        CAT265_PREVIEW_HEIGHT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_draw_control_area
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category265 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat265_draw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x = coordinate->s16X;
    S32 y = coordinate->s16Y;
    S32 width = coordinate->s16Width;
    S32 height = coordinate->s16Height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x, y, x+width-1, y+height-1, GDI_COLOR_TRANSPARENT);
    
    gui_scrolling_text_stop(&wgui_cat265_title_scrolling_text);
    wgui_cat265_create_scrolling_title();
    gui_show_scrolling_text(&wgui_cat265_title_scrolling_text);

    /* preview area */
    wgui_cat265_preview_buf = (U8*)mmi_frm_scrmem_alloc(CAT265_PREVIEW_AREA_SIZE);
    dm_create_layer_using_outside_memory(CAT265_PREVIEW_X, 
                                         CAT265_PREVIEW_Y, 
                                         CAT265_PREVIEW_WIDTH, 
                                         CAT265_PREVIEW_HEIGHT, 
                                         &wgui_cat265_preview_handle, 
                                         wgui_cat265_preview_buf, 
                                         CAT265_PREVIEW_AREA_SIZE, 
                                         DM_LAYER_TOP);
    if(wgui_cat265_preview_handle)
    {
        wgui_cat265_blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
        wgui_cat265_preview_layer_flag = GDI_LAYER_ENABLE_LAYER_2;
        if(wgui_cat265_redraw_preview_area)
        {
            wgui_cat265_redraw_preview_area(*wgui_cat265_preview_handle, 
                                            wgui_cat265_blt_layer_flag,
                                            wgui_cat265_preview_layer_flag, 
                                            CAT265_PREVIEW_X, 
                                            CAT265_PREVIEW_Y, 
                                            CAT265_PREVIEW_WIDTH, 
                                            CAT265_PREVIEW_HEIGHT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory265Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory265Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //title_bg_id = 0;
    MMI_disable_title_shortcut_display = 0;
    disable_menu_shortcut_box_display = 0;

    wgui_reset_touch_title_bar_buttons();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();

    /* reset global variables */
    wgui_cat265_title = NULL;
    gui_scrolling_text_stop(&wgui_cat265_title_scrolling_text);
    if (wgui_cat265_preview_buf != NULL)
    {
        mmi_frm_scrmem_free(wgui_cat265_preview_buf);
        wgui_cat265_preview_buf = NULL;
    }
    wgui_cat265_preview_handle = NULL;
    wgui_cat265_blt_layer_flag = 0;
    wgui_cat265_preview_layer_flag = 0;
    wgui_cat265_pre_highlight_callback = NULL;
    wgui_cat265_redraw_preview_area = NULL;
    wgui_cat265_get_item = NULL;
    wgui_cat265_get_hint = NULL;
}

// *************************************************************************************//


/*****************************************************************************
 * FUNCTION
 *  ShowCategory265Screen
 * DESCRIPTION
 *  category screen of integrated calendar (daily)
 * PARAMETERS
 *  title                   [IN]    initial title string pointer         
 *  left_softkey            [IN]    left softkey string id
 *  left_softkey_icon       [IN]    left softkey icon id    
 *  right_softkey           [IN]    right softkey string id
 *  right_softkey_icon      [IN]    right softkey icon id    
 *  number_of_items         [IN]    total number of menu items    
 *  get_item_func           [IN]    callback to prepare menuitem data
 *  get_hint_func           [IN]    callback to prepare hint date
 *  pre_highlight_callback  [IN]    callback before highlight is changed
 *  redraw_callback         [IN]    callback after highlight is changed
 *  highlighted_item        [IN]    default highlighted item
 *  history_buffer          [IN]    history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory265Screen(
        U8 *title,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        FuncPtr pre_highlight_callback,
        LayerRedrawCallback redraw_callback,
        S32 highlighted_item,
        //U16 list_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    //S32 shortcut_width;
    U8 h_flag;
    //PU8 img;
    //S32 h, w;
    S32 text_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    gui_asyncdynamic_list_error = 0;
    //*category_error_flag = 1;
    MMI_menu_shortcut_number = -1;
    //MMI_title_string = (UI_string_type) title;
    //MMI_title_icon = (PU8) get_image(title_icon);
    wgui_cat265_pre_highlight_callback = pre_highlight_callback;
    wgui_cat265_redraw_preview_area = redraw_callback;
    wgui_cat265_get_item = get_item_func;
    wgui_cat265_get_hint = get_hint_func;
    
    wgui_cat265_title = title;

    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();
    create_fixed_icontext_list_menuitems(2, 1);

    MMI_disable_title_shortcut_display = 1;
    disable_menu_shortcut_box_display = 1;

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    set_fixed_icontext_list_text_coordinates(0, CAT265_TEXT_0_X+CAT265_TEXT_0_OFFSET, 0, CAT265_TEXT_0_WIDTH-(CAT265_TEXT_0_OFFSET*2), get_menu_item_height());
    set_fixed_icontext_list_icon_coordinates(0, CAT265_ICON_X+CAT265_ICON_OFFSET, 0, CAT265_ICON_WIDTH-(CAT265_ICON_OFFSET*2), get_menu_item_height());
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - CAT265_TEXT_0_WIDTH - CAT265_ICON_WIDTH - (CAT265_TEXT_1_OFFSET*2);
    set_fixed_icontext_list_text_coordinates(1, CAT265_TEXT_1_X+CAT265_TEXT_1_OFFSET, 0, text_width, get_menu_item_height());
    associate_fixed_icontext_list_list();
    MMI_current_menu_type = LIST_MENU;
    MMI_fixed_list_menu.n_items = number_of_items;

    if (!init_asyncdynamic_item_buffer(number_of_items, get_item_func, get_hint_func))
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    register_asyncdynamic_list_keys();
    //register_asyncdynamic_list_shortcut_handler();
    //shortcut_width = set_menu_item_count(number_of_items) + 7;
    //resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    //move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);

    //register_hide_menu_shortcut(draw_title);

    register_fixed_list_highlight_handler(wgui_cat265_list_highlight_handler);
    h_flag = set_list_menu_category_history(MMI_CATEGORY265_ID, history_buffer);
    asyncdynamic_list_goto_item_no_redraw(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);
    if (gui_asyncdynamic_list_error)
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    set_asyncdynamic_pop_up_descriptions(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory265Screen;

    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY265_ID;
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(wgui_cat265_draw_control_area);
    dm_redraw_category_screen();

    //*category_error_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_refresh_list
 * DESCRIPTION
 *  Refresh the cat265 list
 *  (it will reload menu item data with 'get_item_func' passed in ShowCategory265Screen)
 *  
 *  Category 265 screen should be currently displayed.
 * PARAMETERS
 *  number_of_items         [IN]        The number of menu items.
 *  highlighted_item        [IN]        The highlighted item
 *  redraw_flag             [IN]        to redraw or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat265_refresh_list(S32 number_of_items, S32 highlighted_item, MMI_BOOL redraw_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 shortcut_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (!g_mmi_gui_cat425_context_p)
    //{
    //    MMI_DBG_ASSERT(0);
    //    return;
    //}

    gui_asyncdynamic_list_error = 0;

    gui_lock_double_buffer();

    MMI_fixed_list_menu.n_items = number_of_items;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    init_asyncdynamic_item_buffer(number_of_items, wgui_cat265_get_item, wgui_cat265_get_hint);

    asyncdynamic_list_goto_item_no_redraw(highlighted_item);
    if (gui_asyncdynamic_list_error)
    {
        MMI_DBG_ASSERT(0);  /* not recoverable */
        //category425_reset_context();
        gui_unlock_double_buffer();
        return;
    }

    set_asyncdynamic_pop_up_descriptions(highlighted_item);

    gui_unlock_double_buffer();

    if(redraw_flag)
    {
        show_asyncdynamic_list();
    }
    //RedrawCategoryFunction();
}
#endif /* __MMI_CAT265_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  ExitCategory427Screen
 * DESCRIPTION
 *  Exit the category427 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory427Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 

    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory427Screen
 * DESCRIPTION
 *  Displays the category427 screen for multi-download list
 *  
 *  1. Each menu item has three text strings: name(scrolling) [0], percentage [1], and size [2].
 *  2. Each menu item has one image icons: state of this item [0].
 *  An empty icon can be set as NULL in 'get_item_func'
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of menu items
 *  get_item_func           [IN]        Callback function to get menu text.
 *  highlighted_item        [IN]        Default highlighted menu item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory427Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text0_width, text1_width, text2_width;
    dm_data_struct dm_data;
    U8 h_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();    /* in order let APP to refresh quickly, we block this effect */
#endif 

    gdi_layer_lock_frame_buffer();
    
    /* set title */
    dm_add_title(title, title_icon);
    
    /* set softkey */
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);
    
    /* set list */
    create_fixed_icontext_list_menuitems(3, 1);
    
    /* set icon-text-list */
    associate_fixed_icontext_list_list();
    MMI_fixed_icontext_list_menuitem.flags |=
        UI_MENUITEM_AUTO_CHOOSE_MARQUEE | UI_MENUITEM_DOTTED_UNDERLINE | UI_MENUITEM_RIGHT_JUSTIFY_COL2;
    resize_fixed_icontext_list_menuitems(0, (MMI_MENUITEM_HEIGHT << 1));
    
    /* compute string width */
    {
        U16 temp[] = L"0123456789K/%";
        S32 w, h;

        gui_set_font(&MMI_small_font);
        mmi_fe_measure_string_by_char_num((U8*)temp, 4/* text1 can only show 4 characters, eg. 100% */, &w, &h);
        text1_width = w;

        /* text2 can only show 10 characters, eg. 9999/9999K */
        text2_width = MMI_fixed_icontext_list_menuitem.width - text1_width - (GUI_TEXT_MENUITEM_TEXT_X * 3);

        /* may need error control about text width */

        text0_width = MMI_fixed_icontext_list_menuitem.width - MMI_MENUITEM_HEIGHT /* icon widh */ - (GUI_TEXT_MENUITEM_TEXT_X * 3) /* gap */;
    }

    /* set item position */
    set_fixed_icontext_list_text_coordinates(0, /* name */
        GUI_TEXT_MENUITEM_TEXT_X, 2 /* gap */,
        text0_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(1, /* percentage */
        MMI_fixed_icontext_list_menuitem.width - GUI_TEXT_MENUITEM_TEXT_X - text1_width, MMI_MENUITEM_HEIGHT + 2 /* gap */,
        text1_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(2, /* size */
        GUI_TEXT_MENUITEM_TEXT_X, MMI_MENUITEM_HEIGHT + 2 /* gap */,
        text2_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_icon_coordinates(0, /* state icon */
        MMI_fixed_icontext_list_menuitem.width - GUI_TEXT_MENUITEM_TEXT_X - MMI_MENUITEM_HEIGHT /* icon width */ + 2 /* gap */, 2 /* gap */,
        MMI_MENUITEM_HEIGHT, MMI_MENUITEM_HEIGHT);
    
    /* override menu item style */
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_ICON_X | UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_Y);

    /* set image highlight */
#ifdef __MMI_SCREEN_ROTATE__
    if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
    {    
        MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_two_line_highlight_filler;
        MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_two_line_highlight_filler;
    }

    /* setup asyncdynamic menu */
    MMI_current_menu_type = LIST_MENU;
    MMI_fixed_list_menu.n_items = number_of_items;
    gui_asyncdynamic_list_error = 0;    
    init_asyncdynamic_item_buffer(number_of_items, get_item_func, NULL);

    /* set highlight handler before loading data */
    register_fixed_list_highlight_handler(asyncdynamic_list_highlight_handler);
    
    /* load data */
    h_flag = set_list_menu_category_history(MMI_CATEGORY427_ID, history_buffer);
    if (h_flag)
    {
        highlighted_item = MMI_fixed_list_menu.highlighted_item;
    }
    asyncdynamic_list_goto_item_no_redraw(highlighted_item);
    MMI_ASSERT(!gui_asyncdynamic_list_error);
    set_asyncdynamic_pop_up_descriptions(highlighted_item);

    /* key handler */
    register_asyncdynamic_list_keys();

    /* set menu shortcut */
    MMI_menu_shortcut_number = highlighted_item + 1;
    set_menu_item_count(number_of_items);
    register_asyncdynamic_list_shortcut_handler();
    
    gdi_layer_unlock_frame_buffer();

    /* Setup category/draw manager data */
    ExitCategoryFunction = ExitCategory427Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY427_ID;
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
