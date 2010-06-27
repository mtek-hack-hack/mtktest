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
 * wgui_categories_tab.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intended for tab control categories screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "gui_config.h"
#include "CustThemesRes.h"
#include "gui_tab_bars.h"
#include "gui.h"
#include "wgui_tab_bars.h"
#include "wgui_categories.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static S32 cat626_tab_num = 0;
/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ExitCategory626Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory626Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat626_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        cat626_tab_num = 0;
    }

    MMI_disable_title_shortcut_display = 0; 
    disable_menu_shortcut_box_display = 0;
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    reset_pop_up_descriptions();

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    reset_all_force_flags_for_hints();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory626Screen
 * DESCRIPTION
 *  Displays the category626 screen (Tab List menu with description )
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  n_tabs                  [IN]
 *  highlighted_tab         [IN]
 *  tab_items               [IN]
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory626Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        S8 highlighted_tab,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 i;
    U8 h_flag;
    S32 shortcut_width;
    S8 n_tabs;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_lock_frame_buffer();

    /* Show Tab bars */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    cat626_tab_num = n_tabs;

    if (n_tabs)
    {
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
    }

    /* Softkeys */
    set_left_softkey_label((UI_string_type)GetString(left_softkey));
    set_left_softkey_icon((PU8)GetImage(left_softkey_icon));
    set_right_softkey_label((UI_string_type)GetString(right_softkey));
    set_right_softkey_icon((PU8)GetImage(right_softkey_icon));
    SetupCategoryKeyHandlers();

    /* Show List */
    create_fixed_icontext_menuitems();
    associate_fixed_icontext_list();

    MMI_current_menu_type = LIST_MENU;
    register_fixed_list_keys();
    
    if (n_tabs)
    {
        resize_fixed_list(MMI_CONTENT_WIDTH_WITH_H_TAB, MMI_CONTENT_HEIGHT_WITH_H_TAB);
        move_fixed_list(MMI_CONTENT_X_WITH_H_TAB, MMI_CONTENT_Y_WITH_H_TAB);
    }
    else
    {
        MMI_title_string = (UI_string_type)title;
        MMI_title_icon = (PU8)GetImage(title_icon);
        resize_fixed_list(MMI_content_width, MMI_content_height);
        move_fixed_list(MMI_content_x, MMI_content_y);
    }

    register_fixed_list_highlight_handler(standard_list_highlight_handler);

    if (list_of_descriptions == NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            add_fixed_icontext_item((UI_string_type) list_of_items[i], wgui_get_list_menu_icon(i, list_of_icons[i]));
            wgui_pop_up_description_strings[i].text_strings[0] = NULL;
        }
    }
    else
    {
        for (i = 0; i < number_of_items; i++)
        {
            add_fixed_icontext_item((UI_string_type) list_of_items[i], wgui_get_list_menu_icon(i, list_of_icons[i]));
            wgui_pop_up_description_strings[i].text_strings[0] = (UI_string_type) list_of_descriptions[i];
        }
    }
    h_flag = set_list_menu_category_history(MMI_CATEGORY626_ID, history_buffer);

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    if (list_of_descriptions != NULL)
    {
        S32 hints = 0;

        for (i = 0; i < number_of_items; i++)
        {
            if (wgui_pop_up_description_strings[i].text_strings[0])
            {
                hints = 1;
                break;
            }
        }
        if (hints)
        {
            if (is_set_force_icon_on_highlight_only_in_menuitem())
            {
                wgui_show_icon_only_highlight_in_icontext_menuitem();
            }
            if (is_set_force_all_hints_in_menuitem())
            {
                wgui_enable_hints_in_icontext_menuitem();
            }
            else if (is_set_force_hints_on_highlight_in_menuitem())
            {
                wgui_enable_hint_highlight_in_icontext_menuitem();
            }
            else
            {
                wgui_enable_hint_highlight_in_icontext_menuitem();
            }

            set_pop_up_descriptions(1, number_of_items, MMI_fixed_list_menu.highlighted_item);
    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
            gui_block_list_effect();
    #endif 
        }
    }
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

    if (h_flag)
    {
        fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    }
    else
    {
        fixed_list_goto_item_no_redraw(highlighted_item);
    }
    MMI_title_string = (UI_string_type) title;
    MMI_title_icon = (PU8) get_image(title_icon);
    set_pop_up_descriptions(1, number_of_items, MMI_fixed_list_menu.highlighted_item);

    /* Setup (hidden) menu shortcut. */
    MMI_menu_shortcut_number = highlighted_item + 1;
    register_fixed_list_shortcut_handler();
    shortcut_width = set_menu_item_count(number_of_items) + 7;
    if (n_tabs)
    {
        resize_menu_shortcut_handler(shortcut_width, MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
        move_menu_shortcut_handler(
            MMI_HORIZONTAL_TAB_BAR_X + MMI_HORIZONTAL_TAB_BAR_WIDTH - MMI_menu_shortcut_box.width,
            MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
        register_hide_menu_shortcut(wgui_show_horizontal_tab_bar_hint_area);
    }
    else
    {
        resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
        move_menu_shortcut_handler(MMI_title_x + MMI_title_width - MMI_menu_shortcut_box.width, MMI_title_y);
        register_hide_menu_shortcut(gui_redraw_menu_shortcut);
    }


    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory626Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY626_ID;
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

}




