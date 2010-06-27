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
 * widget_paint_menu.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MsfMenu paint routines
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
 *==============================================================================
 *******************************************************************************/

/*******************************************************************************
 * Problems:
 * we redraw the same objects for more than one times, maybe we need to redesign the workflow
 *
 *
 * Note:
 * We always check (WGUI_CTX->current_menu==NULL) before doing any operation of menu. 
 *
 * Race condition: (Scenario: Option->Goto to a link containing archor of the current page)
 * Sometimes the menu widget is released first, and user press some key before widget_paint_hdlr().
 * The key events are queued and processed later.  The key handler might access data of 
 * previously released menu widget, and cause memory corruption.
 *
 *******************************************************************************/

#include "widget.h"
#include "IdleAppDef.h"
#include "wgui_categories.h"
#include "wgui_categories_defs.h"
#include "UserProfilesResDef.h"       /* IMG_PROFILES_ACTIVATED */
#include "wgui_menu_shortcuts.h"

/****************************************************************
 paint menu
 ***************************************************************/

#ifndef WIDGET_USE_MMI_ICONTEXT_MENU
static fixed_icontext_list_menuitem widget_icontext_menu_item;
static fixed_icontext_list_menuitem_type widget_icontext_menu_items[MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS];
#endif /* WIDGET_USE_MMI_ICONTEXT_MENU */ 

static fixed_twostate_menuitem widget_twostate_menu_item;
static fixed_twostate_menuitem_type widget_twostate_menu_items[MAX_FIXED_TWOSTATE_MENU_ITEMS];

static void *widget_menuitem_pointers[MAX_FIXED_MENU_ITEM_POINTERS];


/*****************************************************************************
 * FUNCTION
 *  widget_toggle_menu_item_selection
 * DESCRIPTION
 *  Toggle the selected state of the focused menu item
 *  Reference:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_toggle_menu_item_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_choice_element_struct *node = NULL;
    int cnt = 0;
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_menu == NULL)
    {
        return;
    }

    index = WGUI_CTX->current_menu->highlight_index;

    if (index < 0 || index >= (*fixed_twostate_menu_n_items))
    {
        return;
    }

    if (WGUI_CTX->current_menu->choice_type == MsfExclusiveChoice)
    {
        radio_list_handle_item_select(index);

        foreach(WGUI_CTX->current_menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                    {
                        disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                        if ((cnt == index)
                            && (MMI_fixed_twostate_menuitems[index].flags & UI_MENUITEM_STATE_SELECTED))
                            enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                        cnt++;
                    }
                }
            }
        );
    }
    else
    {
        /* change state and draw it */
        standard_check_list_handle_item_select(index);

        foreach(WGUI_CTX->current_menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (cnt == index)
                    {
                        /* select or unselect */
                        set_bit_flag(node->state,
                                     MSF_CHOICE_ELEMENT_SELECTED | MSF_CHOICE_ELEMENT_FOCUSED,
                                     MMI_fixed_twostate_menuitems[index].flags & UI_MENUITEM_STATE_SELECTED);
                    }
                    cnt++;
                }
            }
        );
    }
    widget_notify(_H(WGUI_CTX->current_menu), MsfNotifyStateChange);
    widget_send_update_event_to_wap();

    gui_lock_double_buffer();
    widget_paint_outside_look();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_menu_select_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_menu_select_highlight(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_menu)
    {
        widget_choice_element_struct *node = NULL;
        int cnt = 0;

        if (IS_GADGET_SELECT_GROUP_TYPE(WGUI_CTX->current_menu))
        {
            foreach(WGUI_CTX->current_menu, CHOICE_ELEMENT, node,
                {
                    /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                    if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                    {
                        disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                        set_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED, cnt == index);
                        cnt++;
                    }
                }
            );
        }
        else
        {
            foreach(WGUI_CTX->current_menu, CHOICE_ELEMENT, node,
                {
                    /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                    if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                    {
                        /* XXX the following line is redundant */
                        disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                        set_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED, cnt == index);
                        cnt++;
                    }
                }
            );
        }
        WGUI_CTX->current_menu->highlight_index = index;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_menu_select_none
 * DESCRIPTION
 *  
 * PARAMETERS
 *  disable_highlight       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_menu_select_none(kal_bool disable_highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_menu)
    {
        widget_choice_element_struct *node = NULL;
        int cnt = 0;

        foreach(WGUI_CTX->current_menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                    cnt++;
                }
            }
        );
        if (disable_highlight)
        {
            WGUI_CTX->current_menu->highlight_index = -2;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_menu_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_menu_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_menu)
    {
        WGUI_CTX->current_menu->first_displayed_item = MMI_fixed_list_menu.first_displayed_item;
        WGUI_CTX->current_menu->last_displayed_item = MMI_fixed_list_menu.last_displayed_item;

        MMI_menu_shortcut_number = item_index + 1;
        MMI_highlighted_item_text = get_item_text(item_index);
        if (!menu_shortcut_handler_display)
        {
            draw_title();
        }

        /* setting the menuitem state */
        widget_paint_menu_select_highlight(item_index);
    }
}


/* Reference: ShowCategory24Screen */


/*****************************************************************************
 * FUNCTION
 *  widget_show_icontext_list_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_key_focus        [IN]        
 *  menu                [IN]         
 *  size                [IN]         
 *  pos                 [IN]         
 *  is_gadget           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_show_icontext_list_menu(
                kal_bool is_key_focus,
                widget_menu_struct *menu,
                MsfSize *size,
                MsfPosition *pos,
                kal_bool is_gadget)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int text_width, icon_width;
    int text_x, icon_x;
    int text_columns, icon_columns;

    int cnt;
    int i;
    void **menuitem_pointers;
    widget_choice_element_struct *node = NULL;

    fixed_icontext_list_menuitem *menu_item;
    fixed_icontext_list_menuitem_type *menu_items;
    fixed_list_menu *menu_gui;

#ifndef WIDGET_USE_MMI_ICONTEXT_MENU
    fixed_list_menu MENU;
#endif 

    kal_bool has_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu->property_mask & MSF_WINDOW_PROPERTY_EXT_DISBALE_SLIM_MENU_STYLE)
    {
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    }
#ifdef __MMI_WAP_MMS_NUMERIC_LIST_ICON__
    else
    {
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
    }
#endif /* __MMI_WAP_MMS_NUMERIC_LIST_ICON__ */ 

#ifndef WIDGET_USE_MMI_ICONTEXT_MENU
    if (is_key_focus)
    {
        menu_item = &MMI_fixed_icontext_list_menuitem;
        menu_items = MMI_fixed_icontext_list_menuitems;
        menu_gui = &MMI_fixed_list_menu;
        menuitem_pointers = MMI_fixed_menuitem_pointers;
    }
    else    /* Deprecated. At-most one icontext list in current design */
    {
        WAP_DBG_ASSERT(0);
        menu_item = &(widget_icontext_menu_item);
        menu_items = widget_icontext_menu_items;
        menu_gui = &MENU;
        menuitem_pointers = widget_menuitem_pointers;
    }
#else /* WIDGET_USE_MMI_ICONTEXT_MENU */ 
    menu_item = &MMI_fixed_icontext_list_menuitem;
    menu_items = MMI_fixed_icontext_list_menuitems;
    menu_gui = &MMI_fixed_list_menu;
    menuitem_pointers = MMI_fixed_menuitem_pointers;
#endif /* WIDGET_USE_MMI_ICONTEXT_MENU */ 

    gui_create_fixed_list_menu(
        menu_gui,
        pos->x + menu->position.x,
        pos->y + menu->position.y,
        menu->size.width,
        menu->size.height);

    /* detect number of columns */
    has_icon = KAL_FALSE;
    foreach(menu, CHOICE_ELEMENT, node,
        {
            /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
            if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
            {
                if (node->image1 && IS_PRE_IMAGE_TYPE(node->image1))
                {
                    has_icon = KAL_TRUE;
                    break;
                }
            }
        }
    );

    GUI_current_fixed_icontext_list_menuitem_column = 0;

    if (has_icon)
    {
        text_columns = 1;
        icon_columns = 1;
        icon_x = GUI_ICONTEXT_MENUITEM_ICON_X;
        text_x = GUI_ICONTEXT_MENUITEM_TEXT_X;
        icon_width = widget_image_width(node->image1);
        text_width = size->width - text_x - 3 - MMI_fixed_list_menu.vbar.width;
    }
    else
    {
        text_columns = 1;
        icon_columns = 0;
        icon_x = 0;
        text_x = GUI_TEXT_MENUITEM_TEXT_X;
        icon_width = 0;
        text_width = size->width - text_x - 3 - MMI_fixed_list_menu.vbar.width;
    }

    /* create menu list item (create_fixed_icontext_list_menuitems) */
    gui_create_fixed_icontext_list_menuitem(menu_item, 108, get_menu_item_height(), text_columns, icon_columns);
    for (i = 0; i < MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS && i < menu->menu_items_sum; i++)
    {
        menu_items[i].flags = 0;
        menuitem_pointers[i] = (void*)&(menu_items[i]);
    }

    menu_item->flags |= UI_MENUITEM_CENTER_TEXT_Y;
    menu_item->flags |= UI_MENUITEM_CENTER_ICON_Y;
    menu_item->flags |= UI_MENUITEM_MARQUEE_SCROLL;

    /* set menu position and size (move_fixed_list & resize_fixed_list) */
    gui_move_fixed_list_menu(menu_gui, pos->x + menu->position.x, pos->y + menu->position.y);

    gui_resize_fixed_list_menu(menu_gui, menu->size.width, menu->size.height);

    /* Widget region */
    gui_set_clip(
        pos->x + menu->position.x,
        pos->y + menu->position.y,
        pos->x + menu->position.x + menu->size.width,
        pos->y + menu->position.y + menu->size.height);

    widget_record_used_range(
        _H(menu),
        KAL_TRUE,
        is_key_focus,
        pos->x + menu->position.x,
        pos->y + menu->position.y,
        pos->x + menu->position.x + menu->size.width,
        pos->y + menu->position.y + menu->size.height);

    /* Sett the text column coordinate */
    gui_fixed_icontext_list_menuitem_set_text_coordinates(menu_item, 0, text_x, 0, text_width, get_menu_item_height());

    if (icon_columns)
    {
        gui_fixed_icontext_list_menuitem_set_icon_coordinates(
            menu_item,
            0,
            icon_x,
            0,
            icon_width,
            get_menu_item_height());
    }

    /* Refernce: associate_fixed_icontext_list_list() */

    /* clear_fixed_list_highlight_handler(); */
    gui_set_fixed_list_menu_item_functions(
        menu_gui,
        gui_show_fixed_icontext_list_menuitem,
        gui_measure_fixed_icontext_list_menuitem,
        gui_highlight_fixed_icontext_list_menuitem,
        gui_remove_highlight_fixed_icontext_list_menuitem,
        UI_fixed_menuitem_dummy_hide_function,
        resize_fixed_icontext_list_menuitems);

#ifdef __MMI_TOUCH_SCREEN__
    gui_set_fixed_list_menu_item_pen_function(menu_gui, UI_fixed_menuitem_dummy_pen_function, MMI_FALSE, MMI_FALSE);
#endif 

    menu_gui->first_displayed_item = menu->first_displayed_item;
    menu_gui->last_displayed_item = menu->last_displayed_item;
    menu_gui->highlighted_item = 0;
    MMI_disable_title_shortcut_display = is_gadget;

    menu_gui->items = menuitem_pointers;    /* MMI_fixed_menuitem_pointers; */
    menu_item->flags &= ~UI_MENUITEM_DISABLE_HIGHLIGHT;
    menu_item->flags |= UI_MENUITEM_DISABLE_BACKGROUND;
    menu_gui->common_item_data = menu_item;

    /* call resize_fixed_list() to get menu's top position and spacing value */
    resize_fixed_list((S32)menu->size.width, (S32)menu->size.height);
    gui_resize_fixed_icontext_list_menuitem(
        menu_item,
        menu_gui->width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
        get_menu_item_height());

    /* setting theme */
    set_MMI_current_fixed_icontext_list_menuitem_theme_list();
    gui_set_fixed_icontext_list_menuitem_current_theme(menu_item);

    /* / */
    cnt = 0;

    menu->highlight_index = -1;
    foreach(menu, CHOICE_ELEMENT, node,
        {
            /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
            if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED &&
                 cnt < MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS)
            {
                int j;
                menu_items[cnt].item_texts[0] = NULL;
                menu_items[cnt].item_icons[0] = NULL;
                for (j = 0; j < FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS; j++)
                {
                    menu_items[cnt].item_icon_handles[j] = GDI_ERROR_HANDLE;
                }
                if (node->string1)
                {
                    menu_items[cnt].item_texts[0] = (UI_string_type) widget_string_content(node->string1);
                }
                if (node->image1)
                    if (IS_PRE_IMAGE_TYPE(node->image1))
                    {
                        menu_items[cnt].item_icons[0] = wgui_get_list_menu_icon(cnt, (MMI_ID_TYPE) widget_image_resid(node->image1));
                    }

                if (node->state & (MSF_CHOICE_ELEMENT_SELECTED | MSF_CHOICE_ELEMENT_FOCUSED))
                    if (cnt < menu->menu_items_sum)
                        menu->highlight_index = cnt;
                cnt++;
            }
        }
    );
    menu_gui->n_items = cnt;

    menu_gui->highlighted_item = -1;
    if (menu->highlight_index < 0)
    {
        menu->highlight_index = 0;
    }
    /* register list key handler */
    if (is_key_focus)
    {
        register_fixed_list_highlight_handler(widget_paint_menu_highlight_handler);
        /* move cursor to item 0 */
        gui_fixed_list_menu_goto_item(menu_gui, menu->highlight_index);
    }

    /* show it */
    gui_show_fixed_list_menu(menu_gui);

#ifdef __MMI_WAP_MMS_NUMERIC_LIST_ICON__
    wgui_restore_list_menu_slim_style();
#else /* __MMI_WAP_MMS_NUMERIC_LIST_ICON__ */ 
    if (menu->property_mask & MSF_WINDOW_PROPERTY_EXT_DISBALE_SLIM_MENU_STYLE)
    {
        wgui_restore_list_menu_slim_style();
    }
#endif /* __MMI_WAP_MMS_NUMERIC_LIST_ICON__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_show_radio_list_menu
 * DESCRIPTION
 *  show a fixed list
 * PARAMETERS
 *  is_multi_selection      [IN]        -  multi-selection
 *  is_key_focus            [IN]        -  focused (by pressing SEND key)
 *  menu                    [IN]        -  widget menu structure
 *  size                    [IN]        -  content size
 *  pos                     [IN]        -  content position (absolute coordinate)
 *  is_gadget               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#define WIDGET_MENU_FOCUSED_ELEMENT_OFFSET      (3)
const UI_filled_area g_widget_option_group_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {50, 50, 50, 100},
    {0, 0, 0, 0},
    0
};
static void widget_show_radio_list_menu(
                kal_bool is_multi_selection,
                kal_bool is_key_focus,
                widget_menu_struct *menu,
                MsfSize *size,
                MsfPosition *pos,
                kal_bool is_gadget)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt;
    int i;
    S32 icon_width, icon_height;
    widget_choice_element_struct *node = NULL;

    fixed_twostate_menuitem *menu_item;
    fixed_twostate_menuitem_type *menu_items;
    fixed_list_menu *menu_gui, MENU;
    void **menuitem_pointers;
    S32 new_height = menu->size.height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_key_focus)
    {
        menu_item = &MMI_fixed_twostate_menuitem;
        menu_items = MMI_fixed_twostate_menuitems;
        menu_gui = &MMI_fixed_list_menu;
        menuitem_pointers = MMI_fixed_menuitem_pointers;
    }
    else
    {
        menu_item = &(widget_twostate_menu_item);
        menu_items = widget_twostate_menu_items;
        menu_gui = &MENU;
        menuitem_pointers = widget_menuitem_pointers;
    }
    gui_create_fixed_list_menu(
        menu_gui,
        pos->x + menu->position.x,
        pos->y + menu->position.y,
        menu->size.width,
        new_height);

    /* create menu list item */
    if (is_multi_selection)
    {
        // TODO: use customizable size
        widget_image_id img_on, img_off;

        if (menu->menu_flags & WIDGET_MENU_FLAG_PROFILE_STYLE)
        {
            img_on = IMG_PROFILES_ACTIVATED;
            img_off = 0;
        }
        else
        {
            img_on = CHECKBOX_ON_IMAGE_ID;
            img_off = CHECKBOX_OFF_IMAGE_ID;
        }

        gui_create_fixed_twostate_menuitem(
            menu_item,
            108 /* resized later */ ,
            get_menu_item_height(),
            get_image(img_on),
            get_image(img_off));
        gui_measure_image(get_image(img_on), &icon_width, &icon_height);
    }
    else
    {
        gui_create_fixed_twostate_menuitem(
            menu_item,
            108 /* resized later */ ,
            get_menu_item_height(),
            get_image(RADIO_ON_IMAGE_ID),
            get_image(RADIO_OFF_IMAGE_ID));
        gui_measure_image(get_image(RADIO_ON_IMAGE_ID), &icon_width, &icon_height);
    }
    /* set menu position */
    gui_move_fixed_list_menu(menu_gui, pos->x + menu->position.x, pos->y + menu->position.y);

    gui_resize_fixed_list_menu(menu_gui, menu->size.width, new_height);

    gui_set_clip(
        pos->x + menu->position.x,
        pos->y + menu->position.y,
        pos->x + menu->position.x + menu->size.width,
        pos->y + menu->position.y + new_height);

    widget_record_used_range(
        _H(menu),
        KAL_TRUE,
        is_key_focus,
        pos->x + menu->position.x,
        pos->y + menu->position.y,
        pos->x + menu->position.x + menu->size.width,
        pos->y + menu->position.y + new_height);

    gui_fixed_twostate_menuitem_set_icon_position(menu_item, GUI_ICONTEXT_MENUITEM_ICON_X, get_menu_item_height()/2 - icon_height/2);
    gui_fixed_twostate_menuitem_set_text_position(menu_item, GUI_ICONTEXT_MENUITEM_TEXT_X, 0);

    menu_item->flags |= UI_MENUITEM_CENTER_TEXT_Y;
    menu_item->flags |= UI_MENUITEM_CENTER_ICON_Y;
    menu_item->flags |= UI_MENUITEM_MARQUEE_SCROLL;

    for (i = 0; i < MAX_FIXED_ICONTEXT_MENU_ITEMS; i++)
    {
        menuitem_pointers[i] = (void*)&(menu_items[i]);
    }

    /* associate_fixed_twostate_list */
    gui_set_fixed_list_menu_item_functions(
        menu_gui,
        gui_show_fixed_twostate_menuitem,
        gui_measure_fixed_twostate_menuitem,
        (menu->menu_flags & WIDGET_MENU_FLAG_PROFILE_STYLE || !WGUI_CTX->in_paintbox)?
                gui_highlight_fixed_twostate_menuitem:
                UI_fixed_menuitem_dummy_highlight_function,
        gui_remove_highlight_fixed_twostate_menuitem,
        UI_fixed_menuitem_dummy_hide_function,
        resize_fixed_twostate_menuitems);

#ifdef __MMI_TOUCH_SCREEN__
    if (menu->menu_flags & WIDGET_MENU_FLAG_PROFILE_STYLE)
    {
        gui_set_fixed_list_menu_item_pen_function(menu_gui, UI_fixed_menuitem_dummy_pen_function, MMI_FALSE, MMI_FALSE);
    }
    else
    {
        gui_set_fixed_list_menu_item_pen_function(menu_gui, UI_fixed_menuitem_dummy_pen_function, MMI_FALSE, MMI_TRUE);
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    menu_gui->first_displayed_item = menu->first_displayed_item;
    menu_gui->last_displayed_item = menu->last_displayed_item;
    menu_gui->highlighted_item = 0;
    menu_gui->items = menuitem_pointers;    /* MMI_fixed_menuitem_pointers; */
    menu_item->flags &= ~UI_MENUITEM_DISABLE_HIGHLIGHT;
    menu_item->flags |= UI_MENUITEM_DISABLE_BACKGROUND;
    menu_gui->common_item_data = (void*)menu_item;
    /* call resize_fixed_list() to get menu's top position and spacing value */
    resize_fixed_list((S32)menu->size.width, (S32)menu->size.height);

    MMI_disable_title_shortcut_display = is_gadget;
    set_MMI_current_fixed_twostate_menuitem_theme_list();
    gui_set_fixed_twostate_menuitem_current_theme(menu_item);

    /* setting the text column coordinate */
    cnt = 0;
    if (menu->highlight_index < 0)
    {
        menu->highlight_index = -1;
    }

    /* 
     * Note that menu->profile_activated_index != the original menu item with MSF_CHOICE_ELEMENT_SELECTED.
     * However, widget_paint_menu_select_highlight() will set the MSF_CHOICE_ELEMENT_SELECTED to the highlighted 
     * menu item in MMI (i.e. menu->profile_activated_index).
     */
    foreach(menu, CHOICE_ELEMENT, node,
        {
            /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
	        if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
	        {
		        if (node->string1)
		        {
                    if (cnt < MAX_FIXED_TWOSTATE_MENU_ITEMS)
                    {
                        menu_items[cnt].item_text = (UI_string_type)
			            	widget_string_content(node->string1); 
                    }
		        }

                if (cnt < MAX_FIXED_TWOSTATE_MENU_ITEMS)
                {
                    /* init the flag */
                    menu_items[cnt].flags = 0;
                }
                if (menu->profile_activated_index >= 0)
		        {
                    /* 
                     * In WAP profile setting menu list screen.
                     * the users scroll in this screen, and we need to keep the selected and highlighted item.
                     * the menu list should not be more than MAX_FIXED_TWOSTATE_MENU_ITEMS.
                     */
                    WAP_DBG_ASSERT(cnt < MAX_FIXED_TWOSTATE_MENU_ITEMS);
			        if (cnt == menu->highlight_index)
			        {
			            /* If cnt is highlight_index, we should focus on it */
			            menu->highlight_index = cnt;
			            if (cnt == menu->profile_activated_index)
			            {
    			            /* If cnt is profile_actived_index, we should select this item */
    			            menu_items[cnt].flags = UI_MENUITEM_STATE_SELECTED; 
			            }
			            else
			            {
			                menu_items[cnt].flags = 0;
			            }
			        }
                    else if (cnt == menu->profile_activated_index)
			        {
			            /* If cnt is profile_actived_index, we should select this item */
			            menu_items[cnt].flags = UI_MENUITEM_STATE_SELECTED; 
			        }
			        else
			        {
			            menu_items[cnt].flags = 0;
			        }
		        }
		        else
		        {
                    /*
                     * Option menu in the browser: MsfMultipleChoice or MsfExclusiveChoice
                     * If the menu items are more than MAX_FIXED_TWOSTATE_MENU_ITEMS,
                     * it will exceed menu_items[] array size.
                     * We only keep the first MAX_FIXED_TWOSTATE_MENU_ITEMS in the menu_items[] here.
                     */
			        if (node->state & MSF_CHOICE_ELEMENT_SELECTED)
			        {
                        if (cnt < MAX_FIXED_TWOSTATE_MENU_ITEMS)
                        {
					        menu_items[cnt].flags = UI_MENUITEM_STATE_SELECTED;
                        }
				        if (cnt < menu->menu_items_sum)
				        {
                            if (menu->highlight_index == -1)
                            {
                                /* store the first focused menu item */
			            	    menu->highlight_index = cnt;
                            }
					        if (menu->menu_flags & WIDGET_MENU_FLAG_PROFILE_STYLE)
					        {
					            menu->profile_activated_index = cnt;
					        }
				        }
			        }
			        else
			        {
                        if (cnt < MAX_FIXED_TWOSTATE_MENU_ITEMS)
                        {
			            	menu_items[cnt].flags = 0;
                        }
			        }
			    }
		        cnt++;
	        }
        }

    );

    /*
     * None of the menu items are selected 
     * Tricky. At least one should be chosen.
     */
    if (menu->highlight_index == -1 && menu->choice_type == MsfExclusiveChoice)
    {
        menu_items[0].flags = UI_MENUITEM_STATE_SELECTED;
        menu->highlight_index = 0;
        if (menu->menu_flags & WIDGET_MENU_FLAG_PROFILE_STYLE)
        {
            menu->profile_activated_index = 0;
        }
    }

    if (menu->highlight_index < 
        (MAX_FIXED_TWOSTATE_MENU_ITEMS - WIDGET_MENU_FOCUSED_ELEMENT_OFFSET))
    {
        menu_gui->n_items = menu->menu_items_sum;

        if (menu->menu_flags & WIDGET_MENU_FLAG_PROFILE_STYLE || !WGUI_CTX->in_paintbox)
        {
            /* In WAP profile setting menu list screen */
            gui_fixed_list_menu_goto_item(menu_gui, menu->highlight_index);
        }
        else
        {
            /* Option menu in the browser: shift to the focused menu item */
            if (menu->highlight_index + WIDGET_MENU_FOCUSED_ELEMENT_OFFSET > 
                menu->menu_items_sum - 1)
            {
                gui_fixed_list_menu_goto_item(
                    menu_gui, 
                    menu->menu_items_sum - 1);
            }
            else
            {
                gui_fixed_list_menu_goto_item(
                    menu_gui, 
                    menu->highlight_index + WIDGET_MENU_FOCUSED_ELEMENT_OFFSET);
            }
        }
    }
    else
    {
        int offset = (-2) * WIDGET_MENU_FOCUSED_ELEMENT_OFFSET;
        int index = 0;
        int highlight = -1;
        int menu_index = menu->highlight_index;

        /* 
         * Option menu in the browser:
         * The focused menu item index is large and 
         * need to re-establish the menu items
         */
        cnt = 0;
        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
	            if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
	            {
		            if (node->string1)
		            {
                        if (cnt >= offset + menu_index && index < MAX_FIXED_TWOSTATE_MENU_ITEMS)
                        {
                            menu_items[index].item_text = (UI_string_type)
			            	    widget_string_content(node->string1); 
                        }
		            }

                    //WAP_DBG_ASSERT(menu_index < MAX_FIXED_TWOSTATE_MENU_ITEMS);
			        if (node->state & MSF_CHOICE_ELEMENT_SELECTED)
			        {
                        if (cnt >= offset + menu_index && index < MAX_FIXED_TWOSTATE_MENU_ITEMS)
                        {
					        //menu_items[cnt].flags = UI_MENUITEM_STATE_SELECTED;
                            menu_items[index].flags = UI_MENUITEM_STATE_SELECTED; 
                            if (highlight == -1)
                            {
                                highlight = index;
                            }
                        }
			        }
			        else
			        {
                        if (cnt >= offset + menu_index && index < MAX_FIXED_TWOSTATE_MENU_ITEMS)
                        {
			            	//menu_items[cnt].flags = 0;
                            menu_items[index].flags = 0; 
                        }
			        }
		            cnt++;
                    if (cnt >= offset + menu_index && index < MAX_FIXED_TWOSTATE_MENU_ITEMS)
                    {
                        index++;
                    }
	            }
            }
        );

        menu_gui->n_items = index;
        if (highlight+WIDGET_MENU_FOCUSED_ELEMENT_OFFSET > index-1)
        {
            gui_fixed_list_menu_goto_item(menu_gui, index-1);
        }
        else
        {
            gui_fixed_list_menu_goto_item(menu_gui, highlight+WIDGET_MENU_FOCUSED_ELEMENT_OFFSET);
        }
    }
    /* the menu item numbers must less than MAX_FIXED_TWOSTATE_MENU_ITEMS */
    if (menu_gui->n_items > MAX_FIXED_TWOSTATE_MENU_ITEMS)
    {
        menu_gui->n_items = MAX_FIXED_TWOSTATE_MENU_ITEMS;
    }

    /* Compute real width */
    menu_gui->highlighted_item = -1;
    gui_show_fixed_list_menu_no_draw(menu_gui);
    if (is_gadget && menu_gui->displayed_items == menu_gui->n_items)
    {
        enable_bit_flag(menu_gui->flags, UI_LIST_MENU_DISABLE_SCROLLBAR);
        gui_resize_fixed_twostate_menuitem(menu_item, menu_gui->width - 3, get_menu_item_height());
    }
    else
    {
        gui_resize_fixed_twostate_menuitem(
            menu_item,
            menu_gui->width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
            get_menu_item_height());
    }

    /* Set default highlight item and register key handler 
       (list width must be computed earlier for menu item scrolling) */
    if (menu->highlight_index < 0)
    {
        menu->highlight_index = 0;
    }
    if (is_key_focus)
    {
        fixed_twostate_menu_n_items = (S32*) (&menu->menu_items_sum);
        register_fixed_list_highlight_handler(widget_paint_menu_highlight_handler);
        menu_gui->highlighted_item = -1;    /* Default value before anything is highlighted */
        gui_fixed_list_menu_goto_item(menu_gui, menu->highlight_index);
    }

    /* Disable list background image (possible cached in GDI layer) for option group */
    if (is_gadget)
    {
        if (!WGUI_CTX->is_list_menu_filler_overrided && menu_gui == &MMI_fixed_list_menu)
        {
            WGUI_CTX->is_list_menu_filler_overrided = 1;
            WGUI_CTX->backup_list_focussed_filler = menu_gui->focussed_filler;
            WGUI_CTX->backup_list_normal_filler = menu_gui->normal_filler;
        }
        menu_gui->focussed_filler = (UI_filled_area*)&g_widget_option_group_filler;
        menu_gui->normal_filler = (UI_filled_area*)&g_widget_option_group_filler;
        menu_gui->flags |= UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER;
    }

    /* avoid the option group menu's text color is white in web page because the background color is white. */
    if (is_gadget)
    {
        /* Override menu text color */
        color backup_c1 = menu_item->normal_text_color;
        color backup_c2 = menu_item->focussed_text_color;
        color backup_c3 = menu_item->selected_text_color;
        color black = {0, 0, 0, 100};
        menu_item->normal_text_color = black;
        menu_item->focussed_text_color = black;
        menu_item->selected_text_color = black;
        
        /* Show option group menu */
        gui_show_fixed_list_menu(menu_gui);

        /* Restore menu text color */
        menu_item->normal_text_color = backup_c1;
        menu_item->focussed_text_color = backup_c2;
        menu_item->selected_text_color = backup_c3;
    }
    else
    {
        gui_show_fixed_list_menu(menu_gui);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_restore_menu_background_if_required
 * DESCRIPTION
 *  Restore default menu filler
 *  Note: this hack can be removed if we display multiple-choice option groupin fullscreen menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_restore_menu_background_if_required(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_list_menu_filler_overrided)
    {
        return;
    }

    MMI_fixed_list_menu.focussed_filler = WGUI_CTX->backup_list_focussed_filler;
    MMI_fixed_list_menu.normal_filler = WGUI_CTX->backup_list_normal_filler;
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER;

    WGUI_CTX->is_list_menu_filler_overrided = 0;
    WGUI_CTX->backup_list_focussed_filler = NULL;
    WGUI_CTX->backup_list_normal_filler = NULL;
}

/* 
 *change menu index
 */


/*****************************************************************************
 * FUNCTION
 *  widget_menu_update_selection_after_focus_changed
 * DESCRIPTION
 *  select item if necessary when the focus is changed
 *  
 *  Reference: widget_toggle_menu_item_selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_menu_update_selection_after_focus_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;
    int cnt = 0;
    widget_choice_element_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_menu == NULL)
    {
        return;
    }

    index = WGUI_CTX->current_menu->highlight_index;

    if (!IS_GADGET_SELECT_GROUP_TYPE(WGUI_CTX->current_menu) &&
        WGUI_CTX->current_menu->choice_type == MsfExclusiveChoice)
    {
        /*
         * a radio list (menu )
         * * to follow MMI style to always select the focused menu item
         * * 
         * * XXX maybe we should also apply it to Choice Group in paint box
         */
        if (fixed_twostate_menu_n_items == NULL || index < 0 || index >= (*fixed_twostate_menu_n_items))
        {
            return; /* assert? */
        }

        radio_list_handle_item_select(index);

        foreach(WGUI_CTX->current_menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                    if ((cnt == index))
                    {
                        WAP_RST_ASSERT(MMI_fixed_twostate_menuitems[index].flags & UI_MENUITEM_STATE_SELECTED);
                        enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    cnt++;
                }
            }
        );

        /* send notification signal */
        widget_notify(_H(WGUI_CTX->current_menu), MsfNotifyStateChange);
        widget_send_update_event_to_wap();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_menu_prev_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_menu_prev_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_menu == NULL)
    {
        return;
    }

    if (MMI_fixed_list_menu.highlighted_item == 0)
        if (widget_prev_keyfocus)
        {
            if (!WGUI_CTX->in_paintbox)
            {
                widget_goto_prev_keyfocus_keyboard_handler();
                widget_paint_menu_select_none(KAL_TRUE);
            }
            //else
            //     widget_paint_menu_select_none(KAL_FALSE);
            return;
        }

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_lock_double_buffer();

    gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);

    widget_menu_update_selection_after_focus_changed();
    if (WGUI_CTX->current_menu->highlight_handler)
    {
        WGUI_CTX->current_menu->highlight_handler(
            (MsfWindowHandle)WGUI_CTX->current_menu, 
            MMI_fixed_list_menu.highlighted_item);
    }

    widget_paint_action(_H(WGUI_CTX->current_menu));

    gui_show_fixed_list_menu(&MMI_fixed_list_menu);

    widget_paint_outside_look();
    gui_unlock_double_buffer();
    
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  widget_menu_OK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_menu_OK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wap_is_busy && WGUI_CTX->is_widget_screen && WGUI_CTX->current_menu)
    {
        MSF_UINT8 flags;
        int ret;

        ret = HDIa_widgetExtChoiceGetFocusedElemFlags((MSF_UINT32) WGUI_CTX->current_menu, &flags);
        if (ret && !(flags & WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW))
        {
            widget_fire_LSK(_W(WGUI_CTX->current_menu));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_menu_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_menu_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wap_is_busy && WGUI_CTX->is_widget_screen && WGUI_CTX->current_menu)
    {
        widget_fire_RSK(_W(WGUI_CTX->current_menu));
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_menu_next_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_menu_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_menu == NULL)
    {
        return;
    }

    if (MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1)
        if (widget_next_keyfocus)
        {
            if (!WGUI_CTX->in_paintbox)
            {
                widget_goto_next_keyfocus_keyboard_handler();
                widget_paint_menu_select_none(KAL_TRUE);
            }
            //else
            //     widget_paint_menu_select_none(KAL_FALSE);
            return;
        }

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_lock_double_buffer();

    gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);

    widget_menu_update_selection_after_focus_changed();
    if (WGUI_CTX->current_menu->highlight_handler)
    {
        WGUI_CTX->current_menu->highlight_handler(
            (MsfWindowHandle)WGUI_CTX->current_menu, 
            MMI_fixed_list_menu.highlighted_item);
    }

    widget_paint_action(_H(WGUI_CTX->current_menu));

    gui_show_fixed_list_menu(&MMI_fixed_list_menu);

    widget_paint_outside_look();
    gui_unlock_double_buffer();

    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  widget_menu_select_item_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_menu_select_item_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_menu == NULL)
    {
        return;
    }

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_lock_double_buffer();

    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, index);

    widget_menu_update_selection_after_focus_changed();
    if (WGUI_CTX->current_menu->highlight_handler)
    {
        WGUI_CTX->current_menu->highlight_handler(
            (MsfWindowHandle)WGUI_CTX->current_menu, 
            MMI_fixed_list_menu.highlighted_item);
    }

    widget_paint_action(_H(WGUI_CTX->current_menu));

    gui_show_fixed_list_menu(&MMI_fixed_list_menu);

    widget_paint_outside_look();
    gui_unlock_double_buffer();
    
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    /*
     * In MsfMenu case, the users press number keys to select the menu item. 
     * The GUI component, menu list, will start the timer to select the index one,
     * and we need to avoid the user press LSK or MsfYes at the same time.
     */
    WGUI_CTX->is_menu_item_index_selection_process = 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_menu
 * DESCRIPTION
 *  Paint MsfMenu window or option group
 *  Note: we may use MMI category to display MsfImplicitChoice (fullscreen menu) in the future
 * PARAMETERS
 *  menu        [IN]        Menu object (widget_menu_struct or widget_gadget_select_group_struct)
 *  size        [IN]        Dimension of drawn region
 *  pos         [IN]        Offset position of drawn region
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_menu(widget_menu_struct *menu, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_key_focus;
    kal_bool is_gadget;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * The menu have no choice element , should not be visible.
     * (BRS can also prevent this to happen)
     */
    if (!menu->menu_items_sum)
    {
        return;
    }
    if (menu->choice_type == MsfImplicitChoice && menu->menu_items_sum > MAX_FIXED_ICONTEXT_MENU_ITEMS)
    {
        /* Typically it is menu. It should not happen */
        WAP_DBG_ASSERT(0);
        return;
    }
    if (IS_WINDOW_TYPE(menu))
    {
        is_gadget = KAL_FALSE;
    }
    else
    {
        is_gadget = KAL_TRUE;
    }

    MMI_current_menu_type = LIST_MENU;

    if (is_gadget && !widget_gadget_in_form(size, &menu->position, &menu->size))
    {
        return;
    }

    if (is_gadget)
    {
        /* It does not need to check widget_form_gadget_want_focus */
        is_key_focus = KAL_FALSE;
    }
    else
    {
        is_key_focus = KAL_TRUE;
    }

    /* Display the menu in fullscreen mode */
    if (menu == WENTER_MENU_CTX->target_menu && WENTER_MENU_CTX->state == WIDGET_ENTER_MENU_PREPARE_TO_ENTER)
    {
        WAP_DBG_ASSERT((menu->choice_type == MsfExclusiveChoice || menu->choice_type == MsfMultipleChoice) &&
                       is_gadget && !WGUI_CTX->in_form);

        widget_enter_fullscreen_menu(menu);
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_ENTERED;

        return; /* Stop the paint */
    }

    if (is_key_focus)
    {
        WGUI_CTX->current_menu = menu;
    }

    if (!is_gadget)
    {
        /* Use WGUI API to setup menu shortcut handler. */
        S32 shortcut_width;

        MMI_menu_shortcut_number = -1;

        /* Reference: register_fixed_list_shortcut_handler() */
        register_menu_shortcut_keys();
        register_menu_shortcut_handler(widget_menu_select_item_index);

        shortcut_width = set_menu_item_count(menu->menu_items_sum) + 7;
        resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
        move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
        register_hide_menu_shortcut(gui_redraw_menu_shortcut);
    }

#ifdef WIDGET_RESIDENT_STATUS_ICON
    if (is_gadget)
    {
        if (pos->y + menu->position.y <= WGUI_CTX->status_icons_pane_bottom.y &&
            pos->y + menu->position.y + menu->size.height - 1 >= WGUI_CTX->status_icons_pane_top.y)
        {
            WGUI_CTX->redraw_status_icons_pane = 1;
        }
    }
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 

    switch (menu->choice_type)
    {
        case MsfImplicitChoice:
            widget_show_icontext_list_menu(is_key_focus, menu, size, pos, is_gadget);
            break;
        case MsfMultipleChoice:
        case MsfExclusiveChoice:
            if (menu->choice_type == MsfMultipleChoice)
            {
                widget_show_radio_list_menu(KAL_TRUE, is_key_focus, menu, size, pos, is_gadget);
            }
            else
            {
                widget_show_radio_list_menu(KAL_FALSE, is_key_focus, menu, size, pos, is_gadget);
            }
            break;
        default:
            WAP_DBG_ASSERT(0);
            return;
    }
    if (is_key_focus)
    {
        SetKeyHandler((FuncPtr) widget_menu_prev_item, KEY_UP_ARROW, KEY_EVENT_UP);
        ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler((FuncPtr) widget_menu_prev_item, KEY_UP_ARROW, KEY_REPEAT);
        SetKeyHandler((FuncPtr) widget_menu_prev_item, KEY_VOL_UP, KEY_EVENT_UP);
        ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler((FuncPtr) widget_menu_prev_item, KEY_VOL_UP, KEY_REPEAT);
        SetKeyHandler((FuncPtr) widget_menu_next_item, KEY_DOWN_ARROW, KEY_EVENT_UP);
        ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler((FuncPtr) widget_menu_next_item, KEY_DOWN_ARROW, KEY_REPEAT);
        SetKeyHandler((FuncPtr) widget_menu_next_item, KEY_VOL_DOWN, KEY_EVENT_UP);
        ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler((FuncPtr) widget_menu_next_item, KEY_VOL_DOWN, KEY_REPEAT);

        SetKeyHandler((FuncPtr) widget_menu_back, KEY_LEFT_ARROW, KEY_EVENT_UP);
        ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        if (!is_gadget && menu->choice_type == MsfImplicitChoice        /* menu */
            && !(menu->property_mask & MSF_WINDOW_PROPERTY_EXT_DISABLE_RIGHT_ARROW))
        {
            /* Only menu should enable right arrow as entering */
            SetKeyHandler((FuncPtr) widget_menu_OK, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
        else if (!is_gadget && menu->choice_type == MsfMultipleChoice)
        {
            SetKeyHandler((FuncPtr) widget_menu_OK, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }

        if (IS_GADGET_SELECT_GROUP_TYPE(menu))
        {
            SetKeyHandler(widget_toggle_menu_item_selection, KEY_SEND, KEY_EVENT_UP);

            /* for dummies */
            if (WGUI_CTX->in_paintbox)
            {
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_1, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_2, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_3, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_4, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_5, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_6, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_7, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_8, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_9, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_STAR, KEY_EVENT_UP);
                SetKeyHandler((FuncPtr) widget_toggle_menu_item_selection, KEY_POUND, KEY_EVENT_UP);
            }
        }
    }
}

