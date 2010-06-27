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
 *  gui_fixed_menus.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Fixed-list menu - UI component
 *
 *  1. The number of menu items stays unchanged after the UI component is created.
 *  2. The storage of all menu item data is preallocated.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_Features.h"
#include "gui_config.h"
#include "gui_fixed_menus.h"
#include "CustMenuRes.h"
#include "wgui_inline_edit.h"
#include "gui_windows.h"
#include "DebugInitDef.h"
#include "gui_themes.h"
#include "wgui_categories_util.h"
#include "gui_setting.h"
#include "kal_non_specific_general_types.h"
#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "wgui.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;
extern PU8 get_image(MMI_ID_TYPE);
extern S32 MMI_current_menu_type;

/* for R2L characters */
extern BOOL r2lMMIFlag;

extern S32 menu_item_inline_multiline_box(void);

extern int gdi_layer_get_bit_per_pixel(void);
extern PU8 get_image(U16 i);

S32 current_fixed_list_menuitem_display_index = -1;

UI_fixed_list_menu_theme *current_fixed_list_menu_theme = NULL;
UI_fixed_matrix_menu_theme *current_fixed_matrix_menu_theme = NULL;

#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__

// TODO: THE MATRIX MAIN MENU ITEM NUMBER SHOULD BE CHANGED TO A REAL VALUE.
#define MAX_MATRIX_MM_ITEM_NUM  12
 
S32 matrix_mm_active_image_num = 0;
gui_image_rect matrix_mm_rect[MAX_MATRIX_MM_ITEM_NUM];
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/* 
 * List menu
 */

/*****************************************************************************
 * FUNCTION
 *  UI_dummy_menuitem_displayed_function
 * DESCRIPTION
 *  Dummy item after display callback. This function is OBSOLETE.
 * PARAMETERS
 *  index       [IN]        item index
 *  x1          [IN]        x1
 *  y1          [IN]        y1
 *  x2          [IN]        x2
 *  y2          [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_menuitem_displayed_function(S32 index, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(index);
    UI_UNUSED_PARAMETER(x1);
    UI_UNUSED_PARAMETER(y1);
    UI_UNUSED_PARAMETER(x2);
    UI_UNUSED_PARAMETER(y2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_current_theme
 * DESCRIPTION
 *  Apply the current theme to a fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_current_theme(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags |= current_fixed_list_menu_theme->flags;
    m->focussed_filler = current_fixed_list_menu_theme->focussed_filler;
    m->normal_filler = current_fixed_list_menu_theme->normal_filler;
    gui_resize_vertical_scrollbar(&m->vbar, current_fixed_list_menu_theme->vbar_width, m->vbar.height);
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_list_menu_theme->vbar_width, m->y);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_theme
 * DESCRIPTION
 *  Apply the given theme to a fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  t       [IN]        menu theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_theme(fixed_list_menu *m, UI_fixed_list_menu_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags |= t->flags;
    m->focussed_filler = t->focussed_filler;
    m->normal_filler = t->normal_filler;
    gui_resize_vertical_scrollbar(&m->vbar, t->vbar_width, m->vbar.height);
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_list_menu_theme->vbar_width, m->y);
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_fixed_list_menu
 * DESCRIPTION
 *  Create a fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object
 *  x           [IN]        x1
 *  y           [IN]        y1
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags = 0;
    m->x = x;
    m->y = y;
    m->width = width;
    m->height = height;
    m->n_items = 0;
    m->highlighted_item = 0;
    m->first_displayed_item = 0;
    m->last_displayed_item = 0;
    m->displayed_items = 0;
    m->spacing = 0;
    m->top = 0;
    gui_set_fixed_list_menu_current_theme(m);
    gui_create_vertical_scrollbar(
        &m->vbar,
        m->x + m->width - current_fixed_list_menu_theme->vbar_width,
        m->y,
        current_fixed_list_menu_theme->vbar_width,
        m->height);
    m->item_highlighted = UI_dummy_function_s32;
    m->item_unhighlighted = UI_dummy_function_s32;
    m->item_display_function = UI_fixed_menuitem_dummy_display_function;
    m->item_hide_function = UI_fixed_menuitem_dummy_display_function;
    m->item_measure_function = UI_fixed_menuitem_dummy_measure_function;
    m->item_highlight_function = UI_fixed_menuitem_dummy_highlight_function;
    m->item_remove_highlight_function = UI_fixed_menuitem_dummy_remove_highlight_function;
    m->item_resize_function = UI_fixed_menuitem_dummy_resize_function;
    m->items = NULL;
    m->common_item_data = NULL;
    m->item_displayed_callback = UI_dummy_menuitem_displayed_function;
    m->resized_before_locate = MMI_FALSE;
    m->act_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    m->act_lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
#ifdef __MMI_TOUCH_SCREEN__
    m->pen_event_current_selected_callback_function = NULL;
    m->pen_event_default_selected_callback_function = NULL;
    m->pen_redraw_menu_function = NULL;
    m->item_pen_function = UI_fixed_menuitem_dummy_pen_function;
    m->disable_move_highlight = MMI_FALSE;
    m->disable_up_select = MMI_FALSE;
    m->pen_scroll_delay_time = 0;
    m->pen_scroll_after_delay = -1;
    memset(&(m->pen_state), 0, sizeof(gui_list_pen_state_struct));
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_fixed_list_menu
 * DESCRIPTION
 *  Resize the fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_fixed_list_menu(fixed_list_menu *m, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->width = width;
    m->height = height;
    /* 
     * Example: change highlight in inline editor, list menu is resized 
     * according to virtual keyboard.
     * We have to recompute m->first_displayed_item
     */
    m->resized_before_locate = MMI_TRUE;
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_list_menu_theme->vbar_width, m->y);
    gui_resize_vertical_scrollbar(&m->vbar, m->vbar.width, m->height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_fixed_list_menu
 * DESCRIPTION
 *  Move the fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  x       [IN]        x1
 *  y       [IN]        y1
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->x = x;
    m->y = y;
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_list_menu_theme->vbar_width, m->y);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted menu item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_locate_highlighted_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->flags & UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM)
    {
        S32 total_height = 0, i;
        U8 done = 0;
        S32 list_height = m->height;

        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        m->first_displayed_item = m->highlighted_item;
        for (i = m->n_items - 1; (i >= 0) && (!done); i--)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                current_fixed_list_menuitem_display_index = -1;
            }
            else
            {
                current_fixed_list_menuitem_display_index = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > list_height + 1)
            {
                if (m->first_displayed_item > i)
                {
                    done = 1;
                    m->first_displayed_item = i + 1;
                    m->last_displayed_item = m->n_items - 1;
                }
                break;
            }
        }
        if (total_height <= list_height)
        {
            m->first_displayed_item = 0;
        }
        total_height = 0;
        for (i = m->first_displayed_item; (i < m->n_items) && (!done); i++)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                current_fixed_list_menuitem_display_index = -1;
            }
            else
            {
                current_fixed_list_menuitem_display_index = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > list_height + 1)
            {
                done = 1;
                m->last_displayed_item = i - 1;
            }
        }
    }
    else if (m->flags & UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM)
    {
        S32 total_height = 0, i;
        U8 done = 0;
        S32 list_height = m->height;

        m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
        m->last_displayed_item = m->highlighted_item;

        /* Check if in the first page */
        for (i = 0; (i < m->n_items) && !done; i++)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                current_fixed_list_menuitem_display_index = -1;
            }
            else
            {
                current_fixed_list_menuitem_display_index = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > list_height + 1)
            {
                if (m->last_displayed_item < i)
                {
                    done = 1;
                    m->first_displayed_item = 0;
                    m->last_displayed_item = i - 1;
                }
                break;
            }
        }

        /* Check if in the last page */
        if (!done && total_height <= list_height)
        {
            done = 1;
            m->first_displayed_item = 0;
            m->last_displayed_item = m->n_items - 1;
        }

        /* Align to the bottom */
        total_height = 0;
        if (!done)
        {
            for (i = m->last_displayed_item; (i >= 0) && (!done); i--)
            {
            #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
                if (i == m->highlighted_item)
                {
                    current_fixed_list_menuitem_display_index = -1;
                }
                else
                {
                    current_fixed_list_menuitem_display_index = i;
                }
            #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
                m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
                total_height += iheight;
                if (total_height > list_height + 1)
                {
                    done = 1;
                    m->first_displayed_item = i + 1;
                }
            }
            if (!done)
            {
                m->first_displayed_item = 0;
            }
        }
    }
    else if (m->flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        m->first_displayed_item = m->highlighted_item - 1;
        if (m->first_displayed_item < 0)
        {
            m->first_displayed_item = m->n_items - 1;
        }
        m->last_displayed_item = m->highlighted_item + 1;
        if (m->last_displayed_item >= m->n_items)
        {
            m->last_displayed_item = 0;
        }
    }
    else
    {
        if (m->highlighted_item < m->first_displayed_item)
        {
            m->first_displayed_item = m->highlighted_item;
        }
        else if (m->highlighted_item > m->last_displayed_item)
        {
            U8 done = 0;
            S32 total_height = 0, i;
            S32 list_height = m->height;

            m->last_displayed_item = m->highlighted_item;
            for (i = m->last_displayed_item; i >= 0 && (!done); i--)
            {
            #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
                if (i == m->highlighted_item)
                {
                    current_fixed_list_menuitem_display_index = -1;
                }
                else
                {
                    current_fixed_list_menuitem_display_index = i;
                }
            #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
                m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
                total_height += iheight;
                if (total_height > list_height)
                {
                    done = 1;
                    m->first_displayed_item = i + 1;
                }
            }
        }
        else
        {
            U8 done = 0;
            S32 total_height = 0, i;
            S32 list_height = m->height;

            for (i = m->first_displayed_item; i < m->n_items && (!done); i++)
            {
            #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
                if (i == m->highlighted_item)
                {
                    current_fixed_list_menuitem_display_index = -1;
                }
                else
                {
                    current_fixed_list_menuitem_display_index = i;
                }
            #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
                m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
                total_height += iheight;
                if (total_height > list_height)
                {
                    done = 1;
                    m->last_displayed_item = i - 1;
                }
            }
            if (!done)
            {
                total_height = 0;
                for (i = m->n_items - 1; (i >= 0) && (!done); i--)
                {
                #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
                    if (i == m->highlighted_item)
                    {
                        current_fixed_list_menuitem_display_index = -1;
                    }
                    else
                    {
                        current_fixed_list_menuitem_display_index = i;
                    }
                #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
                    m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
                    total_height += iheight;
                    if (total_height > list_height)
                    {
                        done = 1;
                        m->first_displayed_item = i + 1;
                        m->last_displayed_item = m->n_items - 1;
                        break;
                    }
                }
                if (!done)
                {
                    m->first_displayed_item = 0;
                    m->last_displayed_item = m->n_items - 1;
                }
            }
            if (m->highlighted_item > m->last_displayed_item)
            {
                done = 0;
                total_height = 0;
                m->last_displayed_item = m->highlighted_item;
                for (i = m->last_displayed_item; i >= 0 && (!done); i--)
                {
                #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
                    if (i == m->highlighted_item)
                    {
                        current_fixed_list_menuitem_display_index = -1;
                    }
                    else
                    {
                        current_fixed_list_menuitem_display_index = i;
                    }
                #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
                    m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
                    total_height += iheight;
                    if (total_height > list_height)
                    {
                        done = 1;
                        m->first_displayed_item = i + 1;
                    }
                }
            }
        }
    }

    /* Located after resized */
    m->resized_before_locate = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_locate_previous_item
 * DESCRIPTION
 *  Locate the menu item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object   
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_locate_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        if (m->highlighted_item == 0)
        {
            m->first_displayed_item = m->n_items - 1;
            m->last_displayed_item = 1;
        }
        else
        {
            m->first_displayed_item = m->highlighted_item - 1;
            if (m->first_displayed_item < 0)
            {
                m->first_displayed_item = m->n_items - 1;
            }
            m->last_displayed_item = m->highlighted_item + 1;
            if (m->last_displayed_item > m->n_items - 1)
            {
                m->last_displayed_item = 0;
            }
        }
    }
    else
    {
        if (m->highlighted_item < m->first_displayed_item)
        {
            m->first_displayed_item = m->highlighted_item;
        }
        else if (m->resized_before_locate)
        {
            gui_fixed_list_menu_locate_highlighted_item(m);
        }
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        else if (m->highlighted_item == m->last_displayed_item - 1)
        {
            S32 iwidth, iheight;
            U8 done = 0;
            S32 total_height = 0, i;
            S32 list_height = m->height;

            current_fixed_list_menuitem_display_index = -1;
            for (i = m->last_displayed_item; i >= 0 && (!done); i--)
            {
                if (i == m->highlighted_item)
                {
                    current_fixed_list_menuitem_display_index = -1;
                }
                else
                {
                    current_fixed_list_menuitem_display_index = i;
                }
                m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
                total_height += iheight;
                if (total_height > list_height + 1)
                {
                    done = 1;
                    m->first_displayed_item = i + 1;
                }
            }
        }
    #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
    }

    /* Located after resized */
    m->resized_before_locate = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_locate_next_item
 * DESCRIPTION
 *  Locate the menu item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_locate_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        m->first_displayed_item = m->highlighted_item - 1;
        if (m->first_displayed_item < 0)
        {
            m->first_displayed_item = m->n_items - 1;
        }
        m->last_displayed_item = m->highlighted_item + 1;
        if (m->last_displayed_item >= m->n_items)
        {
            m->last_displayed_item = 0;
        }
    }
    else
    {
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        if (m->highlighted_item >= m->last_displayed_item)
    #else 
        if (m->highlighted_item > m->last_displayed_item)
    #endif 
        {
            U8 done = 0;
            S32 total_height = 0, i;

            S32 list_height = m->height;

            m->last_displayed_item = m->highlighted_item;
            for (i = m->last_displayed_item; i >= 0 && (!done); i--)
            {
            #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
                if (i == m->highlighted_item)
                {
                    current_fixed_list_menuitem_display_index = -1;
                }
                else
                {
                    current_fixed_list_menuitem_display_index = i;
                }
            #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
                m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
                total_height += iheight;
                if (total_height > list_height + 1)
                {
                    done = 1;
                    m->first_displayed_item = i + 1;
                }
            }
        }
        else if (m->resized_before_locate)
        {
            gui_fixed_list_menu_locate_highlighted_item(m);
        }
    }

    /* Located after resized */
    m->resized_before_locate = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_switch_highlighted_item
 * DESCRIPTION
 *  Switch from the old highlighted item index to the new highlighted item.
 * PARAMETERS
 *  m                       [IN]        fixed list menu object          
 *  last_highlighted_item   [IN]        old highlighted menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_switch_highlighted_item(fixed_list_menu *m, S32 last_highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[last_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
    #ifdef __MMI_TOUCH_SCREEN__
        m->pen_event_current_selected_callback_function = m->pen_event_default_selected_callback_function;
    #endif 
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item index.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  i       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_item(fixed_list_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < 0) || (i > m->n_items - 1))
    {
        return;
    }
    if (i == m->highlighted_item)
    {
        return;
    }
    last_highlighted_item = m->highlighted_item;
    m->highlighted_item = i;
    gui_fixed_list_menu_locate_highlighted_item(m);

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object   
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
    U8 loop_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item >= (m->n_items - 1))
    {
        if (m->flags & UI_LIST_MENU_LOOP)
        {
            loop_flag = 1;
        }
        else
        {
            return;
        }
    }
    last_highlighted_item = m->highlighted_item;
    if (loop_flag)
    {
        m->highlighted_item = 0;
        gui_fixed_list_menu_locate_previous_item(m);
    }
    else
    {
        m->highlighted_item++;
        gui_fixed_list_menu_locate_next_item(m);
    }

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
    U8 loop_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item <= 0)
    {
        if (m->flags & UI_LIST_MENU_LOOP)
        {
            loop_flag = 1;
        }
        else
        {
            return;
        }
    }
    last_highlighted_item = m->highlighted_item;
    if (loop_flag)
    {
        m->highlighted_item = m->n_items - 1;
        gui_fixed_list_menu_locate_next_item(m);
    }
    else
    {
        m->highlighted_item--;
        gui_fixed_list_menu_locate_previous_item(m);
    }

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_next_page
 * DESCRIPTION
 *  Go to the next page.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_next_page(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
    S32 iwidth, iheight;
    U8 done = 0;
    S32 total_height = 0, i;
    S32 list_height = m->height - 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_highlighted_item = m->highlighted_item;
    m->first_displayed_item += m->displayed_items;
    if (m->first_displayed_item > (m->n_items - 1))
    {
        m->first_displayed_item = (m->n_items - 1);
        m->last_displayed_item = m->first_displayed_item;
    }
    else
    {
        for (i = m->first_displayed_item; (i < m->n_items) && (!done); i++)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                current_fixed_list_menuitem_display_index = -1;
            }
            else
            {
                current_fixed_list_menuitem_display_index = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > list_height + 1)
            {
                done = 1;
                m->last_displayed_item = i - 1;
            }
        }
    }
    for (i = m->last_displayed_item; i >= 0 && (!done); i--)
    {
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        if (i == m->highlighted_item)
        {
            current_fixed_list_menuitem_display_index = -1;
        }
        else
        {
            current_fixed_list_menuitem_display_index = i;
        }
    #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (total_height > list_height + 1)
        {
            done = 1;
            m->first_displayed_item = i + 1;
        }
    }
    m->highlighted_item = m->first_displayed_item;

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_previous_page
 * DESCRIPTION
 *  Go to the previous page.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_previous_page(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_highlighted_item = m->highlighted_item;
    m->first_displayed_item -= m->displayed_items;
    if (m->first_displayed_item < 0)
    {
        m->first_displayed_item = 0;
    }
    m->highlighted_item = m->first_displayed_item;
    if (last_highlighted_item == m->highlighted_item)
    {
        return;
    }
    gui_fixed_list_menu_locate_highlighted_item(m);

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_first_item
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_first_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == 0)
    {
        return;
    }
    last_highlighted_item = m->highlighted_item;
    m->highlighted_item = 0;
    gui_fixed_list_menu_locate_highlighted_item(m);

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_last_item
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_last_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == (m->n_items - 1))
    {
        return;
    }
    last_highlighted_item = m->highlighted_item;
    m->highlighted_item = (m->n_items - 1);
    gui_fixed_list_menu_locate_highlighted_item(m);

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_list_menu_background_outside_area
 * DESCRIPTION
 *  Show the extended menu background outside the menu display area. 
 *
 *  For example, in handwriting mode of inline editor, we may want to draw 
 *  menu background in the bottom virtual keyboard area when the keyboard is hidden.
 *
 *  Note: This API does not use any menu cache
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  x1      [IN]        left-top x
 *  y1      [IN]        left-top y
 *  x2      [IN]        right-bottom x
 *  y2      [IN]        right-bottom y
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_list_menu_background_outside_area(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2)
{
    UI_filled_area *f;

    if (m->flags & UI_LIST_MENU_STATE_FOCUSSED)
    {
        f = m->focussed_filler;
    }
    else
    {
        f = m->normal_filler;
    }

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    gui_draw_filled_area(m->x, m->y, x2, y2, f);
        
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_fixed_list_menu
 * DESCRIPTION
 *  Show the fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_fixed_list_menu(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, y_offset;

    UI_filled_area *f;
    S32 i;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 iwidth, iheight;
    U8 done = 0;
    S32 total_height, counter, list_height;
    U8 disable_draw = 0;
    MMI_BOOL show_scrollbar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /* if the image highlight dimension does not fit, use default list highlight filler */
    gui_menuitem_verify_image_highlight_dimension(m->common_item_data); 

    if (m->flags & UI_LIST_MENU_DISABLE_DRAW)
    {
        disable_draw = 1;
    }
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);

    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;

    /* Use the original x1, y1, x2, y2 for background filler */

    if (m->flags & UI_LIST_MENU_STATE_FOCUSSED)
    {
        f = m->focussed_filler;
    }
    else
    {
        f = m->normal_filler;
    }

    if (!disable_draw && (!(m->flags & UI_LIST_MENU_DISABLE_BACKGROUND)) && MMI_current_menu_type != PAGE_MENU)
    {
        gui_set_clip(x1, y1, x2, y2);

        if (!(m->flags & UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER) && (wgui_is_wallpaper_on_bottom() == MMI_TRUE))
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);

        #if (defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__))
            if (gui_get_transparent_source_layer() == GDI_LAYER_EMPTY_HANDLE)   /* 110705 WAP menu Clavin add */
            {
                gui_set_transparent_source_layer(dm_get_scr_bg_layer());        /* should remove */
            }
        #endif /* (defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)) */ 
        }
        else
        {
        #if !defined(MT6205B) && !defined(MT6208)
            gui_draw_filled_area(x1, y1, x2, y2, f);
        #else /* !defined(MT6205B) && !defined(MT6208) */
            /* For low-end phone, disable list menu background can greately improve menu performance. 
               We use the color of filler to draw the background (typically white). */
            color c = f->c;
            gdi_draw_solid_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(255, c.r, c.g, c.b));
        #endif /* !defined(MT6205B) && !defined(MT6208) */
        }
    }

    if (m->flags & UI_LIST_MENU_ENABLE_TRANSITION)
    {
        color c = gui_color(255, 255, 255);

        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
        gui_fill_rectangle(x1, y1, x2, y2, c);
        gui_pop_clip();
    }

    if (m->n_items <= 0)
    {
        return;
    }

    /* Check presence of scrollbar */
    show_scrollbar = MMI_FALSE;
    if (!(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR))
    {
        if (m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR)
        {
            if (m->first_displayed_item > 0)
            {
                show_scrollbar = MMI_TRUE;
            }
            else
            {
                /* FIXME. we need to compute m->displayed_items twice */
                gui_show_fixed_list_menu_no_draw(m);
                if (m->displayed_items >= m->n_items)
                {
                    show_scrollbar = MMI_TRUE;
                }
            }
        }
        else
        {
            show_scrollbar = MMI_TRUE;
        }
    }

    /* Configure region of menu items */
    if (show_scrollbar)
    {
        if (!r2lMMIFlag)
        {
            x2 -= m->vbar.width;
        }
        else
        {
            x1 += m->vbar.width;
        }
    }

    /* Display menu items */
    if (MMI_current_menu_type == PAGE_MENU)
    {
        if (!disable_draw)
        {
            m->item_display_function(m->items[m->highlighted_item], m->common_item_data, m->x, m->y);
        }
        return;
    }

    y1 = m->y + m->top;

    list_height = m->height;

    if (!(m->flags & UI_LIST_MENU_DISABLE_MENUITEM_GAP))
    {    
        if (r2lMMIFlag)
        {
            x1 += GUI_MENUITEM_X2_GAP;
            x2 -= GUI_MENUITEM_X1_GAP;
        }
        else
        {
            x1 += GUI_MENUITEM_X1_GAP;
            x2 -= GUI_MENUITEM_X2_GAP;    
        }
    }
    
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);
    total_height = 0;
    counter = 0;
    current_fixed_list_menuitem_display_index = -1;

    if (m->flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        m->item_measure_function(m->items[m->highlighted_item], m->common_item_data, &iwidth, &iheight);

        current_fixed_list_menuitem_display_index = m->first_displayed_item;
        m->item_display_function(m->items[m->first_displayed_item], m->common_item_data, x1, y1);

        current_fixed_list_menuitem_display_index = m->highlighted_item;
        m->item_display_function(m->items[m->highlighted_item], m->common_item_data, x1, y1 + iheight);

        current_fixed_list_menuitem_display_index = m->last_displayed_item;
        m->item_display_function(m->items[m->last_displayed_item], m->common_item_data, x1, y1 + iheight * 2);
    }
    else
    {
        for (i = m->first_displayed_item; (i < m->n_items && !done); i++)
        {
            if (i == m->highlighted_item)
            {
                current_fixed_list_menuitem_display_index = -1;
            }
            else
            {
                current_fixed_list_menuitem_display_index = i;
            }

            m->current_displayed_item = i;

            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);

            y_offset = total_height;
            total_height += iheight;

            if (total_height > list_height + 1)
            {
                done = 1;
                /* This is required so that in trnasition if theire is no area to display the menu item it is not displayed */
                if ((counter == 0) && !disable_draw && !(m->flags & UI_LIST_MENU_ENABLE_TRANSITION))
                {
                    m->item_display_function(m->items[i], m->common_item_data, x1, y_offset + y1);
                }
            }
            else
            {
                if (!disable_draw)
                {
                    if (i == m->highlighted_item)
                    {
                        m->highlight_x = x1;
                        m->highlight_y = y_offset + y1;
                    }

                    m->item_display_function(m->items[i], m->common_item_data, x1, y_offset + y1);
                }
                counter++;
            }
        }

        current_fixed_list_menuitem_display_index = -1;
        if (counter == 0)
        {
            m->last_displayed_item = m->first_displayed_item;
        }
        else
        {
            m->last_displayed_item = m->first_displayed_item + counter - 1;
        }
        m->displayed_items = counter;
    }

    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);

    /* Handle scrollbar */
    if (show_scrollbar)
    {
        /* FIXME. debug only. we can remove the check in the future */
        MMI_DBG_ASSERT(!(m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) ||
                       (total_height > list_height + 1) || (m->first_displayed_item > 0));

        if (r2lMMIFlag)
        {
            gui_move_vertical_scrollbar(&m->vbar, m->x, m->y);
        }
        else
        {
            gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - m->vbar.width, m->y);
        }

        gui_set_vertical_scrollbar_range(&m->vbar, m->n_items);
        gui_set_vertical_scrollbar_scale(&m->vbar, m->displayed_items);
        gui_set_vertical_scrollbar_value(&m->vbar, m->first_displayed_item);

        if (!disable_draw)
        {
            gui_show_vertical_scrollbar(&m->vbar);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_fixed_list_menu_no_draw
 * DESCRIPTION
 *  Calculate the first and the last displayed item indices.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_fixed_list_menu_no_draw(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 iwidth, iheight;
    U8 done = 0;
    S32 total_height, counter, list_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_height = m->height;
    total_height = 0;
    counter = 0;
    current_fixed_list_menuitem_display_index = -1;
    for (i = m->first_displayed_item; (i < m->n_items && !done); i++)
    {
        if (i == m->highlighted_item)
        {
            current_fixed_list_menuitem_display_index = -1;
        }
        else
        {
            current_fixed_list_menuitem_display_index = i;
        }
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (total_height > list_height + 1)
        {
            done = 1;
        }
        else
        {
            counter++;
        }
    }
    current_fixed_list_menuitem_display_index = -1;
    if (counter == 0)
    {
        m->last_displayed_item = m->first_displayed_item;
    }
    else
    {
        m->last_displayed_item = m->first_displayed_item + counter - 1;
    }
    m->displayed_items = counter;
    if (!(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR))
    {
        gui_set_vertical_scrollbar_range(&m->vbar, m->n_items);
        gui_set_vertical_scrollbar_scale(&m->vbar, m->displayed_items);
        gui_set_vertical_scrollbar_value(&m->vbar, m->first_displayed_item);
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_translate_pen_position
 * DESCRIPTION
 *  Translate position to item index
 *  
 *  if y < minimum bound, *item_index is first_displayed_item - 1 or 0
 *  if y > maximum bound, *item_index is last_displayed_item + 1 or (n_items - 1)
 *  Caller of this function might be sensitive to the return result.
 *  Be careful when modifying this function.
 * PARAMETERS
 *  m               [IN]        fixed list menu object
 *  y               [IN]        y
 *  item_index      [OUT]       penned item index
 * RETURNS
 *  Return MMI_TRUE if y is within the menu; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL gui_fixed_list_menu_translate_pen_position(fixed_list_menu *m, S32 y, S32 *item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_height = 0, i;
    S32 iwidth, iheight;
    BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y -= m->y;

    if (m->n_items <= 0)
    {
        *item_index = 0;
        /* ret is false */
    }
    else if (y < 0)
    {
        *item_index = (m->first_displayed_item > 0) ? m->first_displayed_item - 1 : 0;
        /* ret is false */
    }
    else if (y >= m->height)
    {
        *item_index = (m->last_displayed_item < m->n_items - 1) ? m->last_displayed_item + 1 : m->n_items - 1;
        /* ret is false */
    }
    else
    {
        *item_index = m->n_items - 1;
        for (i = m->first_displayed_item; i < m->n_items; i++)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                current_fixed_list_menuitem_display_index = -1;
            }
            else
            {
                current_fixed_list_menuitem_display_index = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > y)
            {
                *item_index = i;
                ret = MMI_TRUE;
                break;
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_get_menuitem_position
 * DESCRIPTION
 *  Get menu item (x1, y1) by a specified item index.
 * PARAMETERS
 *  m           [IN]        dynamic list menu object         
 *  item_index  [IN]        item index
 *  x           [OUT]       x1 of the item  
 *  y           [OUT]       y1 of the item 
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_get_menuitem_position(fixed_list_menu *m, S32 item_index, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_height = m->y;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = m->x;

    // TODO: must consider scrollbar absence
    if (r2lMMIFlag)
    {
        *x += m->vbar.width + GUI_MENUITEM_X2_GAP;
    }

    if (item_index <= m->first_displayed_item)
    {
        *y = total_height;
        return;
    }

    for (i = m->first_displayed_item; i <= m->last_displayed_item; i++)
    {
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        if (i == m->highlighted_item)
        {
            current_fixed_list_menuitem_display_index = -1;
        }
        else
        {
            current_fixed_list_menuitem_display_index = i;
        }
    #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (i + 1 == item_index)
        {
            *y = total_height;
            return;
        }
    }
    *y = total_height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_scroll_by_pen
 * DESCRIPTION
 *  Scroll the menu by pen.
 * PARAMETERS
 *  m                   [IN]        fixed list menu object       
 *  first_displayed     [IN]        first displayed item index
 *  menu_event          [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_scroll_by_pen(fixed_list_menu *m, S32 first_displayed, gui_list_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_height = 0, i;
    S32 iwidth, iheight;
    S32 last_displayed = m->n_items - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_displayed > m->highlighted_item)
    {
        m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        gui_fixed_list_menu_goto_item(m, first_displayed);
        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
    }
    else
    {
        for (i = first_displayed; i < m->n_items; i++)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                current_fixed_list_menuitem_display_index = -1;
            }
            else
            {
                current_fixed_list_menuitem_display_index = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > m->height + 1)
            {
                last_displayed = i - 1;
                break;
            }
        }
        if (i == m->n_items)
        {
            last_displayed = m->n_items - 1;
        }

        if (last_displayed < m->highlighted_item)
        {
            m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            gui_fixed_list_menu_goto_item(m, last_displayed);
            m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            m->first_displayed_item = first_displayed;
            m->last_displayed_item = last_displayed;
            *menu_event = GUI_LIST_PEN_NEED_REDRAW;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object         
 *  pen_event   [IN]        pen event type
 *  x           [IN]        pen x   
 *  y           [IN]        pen y
 *  menu_event  [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL gui_fixed_list_menu_translate_pen_event(
        fixed_list_menu *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_list_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_list_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    gui_list_pen_enum menuitem_event;
    gui_pen_event_param_struct menuitem_param;
    S32 item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &m->pen_state;
    ret = MMI_TRUE;

    GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), 0, GUI_LIST_PEN_NONE);

    *menu_event = GUI_LIST_PEN_NONE;

    if (m->flags & UI_LIST_MENU_DISABLE_PEN)
    {
        return MMI_FALSE;
    }

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_scrollbar)
    {
        gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            gui_fixed_list_menu_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
        }
    }
    else if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->handled_by_menu_item)
    {
        /* For example, tap down on checkbox of two-state menuitem, the subsequent move/up events are discarded */
        S32 item_x, item_y;

        gui_fixed_list_menu_get_menuitem_position(m, m->highlighted_item, &item_x, &item_y);

        GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), m->highlighted_item, GUI_LIST_PEN_NONE);
        
        m->item_pen_function(
            m->items[m->highlighted_item],
            m->common_item_data,
            item_x,
            item_y,
            pen_event,
            x,
            y,
            &menuitem_event,
            &menuitem_param);

        if (menuitem_event == GUI_TWOSTATE_PEN_TOGGLE)
        {
            menuitem_event = GUI_LIST_PEN_ITEM_SELECTED;
        }
        *menu_event = menuitem_event;
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                {
                    pen_state->handled_by_menu_item = 0;
                    pen_state->pen_on_scrollbar = 0;

                    if (m->n_items <= 0)
                    {
                        /* In current design, scrollbar is hidden if m->n_items == 0 */
                        ret = MMI_FALSE;
                    }
                    else if (!(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) &&
                             gui_vertical_scrollbar_translate_pen_event(
                                &m->vbar,
                                MMI_PEN_EVENT_DOWN,
                                x,
                                y,
                                &scrollbar_event,
                                &scrollbar_param))
                    {
                        pen_state->pen_on_scrollbar = 1;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            gui_fixed_list_menu_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                        }
                    }
                    else
                    {
                        if (gui_fixed_list_menu_translate_pen_position(m, y, &item_index))
                        {
                            S32 item_x, item_y;

                            if (item_index != m->highlighted_item)
                            {
                                gui_fixed_list_menu_goto_item(m, item_index);
                                *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;

                                GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), item_index, GUI_LIST_PEN_HIGHLIGHT_CHANGED);
                            }

                            /* Even if highlight is changed, we still need to invoke menuitem pen handler */
                            gui_fixed_list_menu_get_menuitem_position(m, item_index, &item_x, &item_y);
                            if (m->item_pen_function(
                                    m->items[item_index],
                                    m->common_item_data,
                                    item_x,
                                    item_y,
                                    MMI_PEN_EVENT_DOWN,
                                    x,
                                    y,
                                    &menuitem_event,
                                    &menuitem_param))
                            {
                                if (menuitem_event == GUI_TWOSTATE_PEN_TOGGLE)
                                {
                                    menuitem_event = GUI_LIST_PEN_ITEM_SELECTED;
                                }
                                /* original menu_event could be GUI_LIST_PEN_HIGHLIGHT_CHANGED */
                                if (menuitem_event != GUI_LIST_PEN_NONE)
                                {
                                    *menu_event = menuitem_event;
                                }

                                pen_state->handled_by_menu_item = 1;
                            }
                        }
                        else
                        {
                            /* # of menu items < # of displayable menu items */
                            ret = MMI_FALSE;
                        }
                    }
                    pen_state->first_highlighed_item = m->highlighted_item;
                    pen_state->highlight_changed = 0;
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_LONG_TAP:
                /* FALLTHROUGH no break */
            case MMI_PEN_EVENT_REPEAT:
                /* FALLTHROUGH no break */
            case MMI_PEN_EVENT_MOVE:
                if (!m->disable_move_highlight)
                {
                    gui_fixed_list_menu_translate_pen_position(m, y, &item_index);
                    if (item_index != m->highlighted_item)
                    {
                        gui_fixed_list_menu_goto_item(m, item_index);
                        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
                    }
                }
                break;

            case MMI_PEN_EVENT_UP:
                if (!m->disable_up_select)
                {
                    if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                    {
                        gui_fixed_list_menu_translate_pen_position(m, y, &item_index);
                        if (item_index != m->highlighted_item)
                        {
                            if (!m->disable_move_highlight)
                            {
                                /* If MMI_PEN_EVENT_MOVE is not delivered before moving to this item */
                                gui_fixed_list_menu_goto_item(m, item_index);
                                *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
                            }
                        }
                        else if (pen_state->highlight_changed)
                        {
                            *menu_event = GUI_LIST_PEN_NONE;
                        }
                        else
                        {
                            *menu_event = GUI_LIST_PEN_ITEM_SELECTED;
                        }
                    }
                }
                break;

            case MMI_PEN_EVENT_ABORT:
                /* Do nothing */
                break;

            default:
                MMI_ASSERT(0);
        }
    }

    if (ret)
    {
        if (pen_state->first_highlighed_item != m->highlighted_item)
        {
            pen_state->highlight_changed = 1;
        }
    }
    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_hide_fixed_list_menu_highlighted_item
 * DESCRIPTION
 *  Hide the highlighted item in the fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_hide_fixed_list_menu_highlighted_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, y_offset;
    S32 i;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 iwidth, iheight;
    U8 done = 0;
    S32 total_height, counter, list_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);
    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;
    x1 += 3;
    x2 -= (3 - m->vbar.width);
    y1 += 3;
    y2 -= 3;
    list_height = m->height - 4;
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);
    total_height = 0;
    counter = 0;
    for (i = m->first_displayed_item; (i < m->n_items && !done); i++)
    {
        y_offset = total_height;
        if (i == m->highlighted_item)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                current_fixed_list_menuitem_display_index = -1;
            }
            else
            {
                current_fixed_list_menuitem_display_index = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
        }
        if (total_height > list_height + 1)
        {
            done = 1;
            if ((counter == 0) && (i == m->highlighted_item))
            {
                m->item_hide_function(m->items[i], m->common_item_data, x1, y_offset + y1);
            }
        }
        else
        {
            if (i == m->highlighted_item)
            {
                m->item_hide_function(m->items[i], m->common_item_data, x1, y_offset + y1);
            }
            counter++;
        }
    }
    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_item_functions
 * DESCRIPTION
 *  Set the fixed list menu item interface.
 * PARAMETERS
 *  m                                   [IN]        fixed list menu object
 *  item_display_function               [IN]        function to display an item
 *  item_measure_function               [IN]        function to measure an item
 *  item_highlight_function             [IN]        function to highlight an item
 *  item_remove_highlight_function      [IN]        function to remove highlight of an item
 *  item_hide_function                  [IN]        function to hide an item
 *  item_resize_function                [IN]        function to resize the common item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_item_functions(
        fixed_list_menu *m,
        void (*item_display_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_measure_function) (void *item, void *common_item_data, S32 *width, S32 *height),
        void (*item_highlight_function) (void *item, void *common_item_data),
        void (*item_remove_highlight_function) (void *item, void *common_item_data),
        void (*item_hide_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_resize_function) (S32 x, S32 y))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_display_function = item_display_function;
    m->item_measure_function = item_measure_function;
    m->item_highlight_function = item_highlight_function;
    m->item_remove_highlight_function = item_remove_highlight_function;
    m->item_hide_function = item_hide_function;
    m->item_resize_function = item_resize_function;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_set_pen_scroll_delay
 * DESCRIPTION
 *  Set the delay time that menu scrolling after scrollbar is scrolled by pen.
 *  
 *  Typically used in dynamic and asyncdynamic list menu because it need to load
 *  data when menu is scrolled.
 *  
 *  THE SCROLL DELAY IS IMPLEMENTED IN DYNAMIC AND ASYNCDYNAMIC LIST ONLY.
 *  THIS IS DUMMY FUNCTION FOR API CONSISTENCY.
 * PARAMETERS
 *  m               [IN]        fixed list menu object
 *  delay_time      [IN]        time in milliseconds
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_set_pen_scroll_delay(fixed_list_menu *m, S32 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(delay_time < (S32) 0x0000FFFF);
    m->pen_scroll_delay_time = (S16) delay_time;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_item_pen_function
 * DESCRIPTION
 *  Set the pen handler of menu item.
 * PARAMETERS
 *  m                           [IN]        fixed list menu object
 *  item_pen_function           [IN]        function to handle pen events in menu item
 *  disable_move_highlight      [IN]        do not send GUI_LIST_PEN_HIGHLIGHT_CHANGED on Pen Move and (sometimes) Pen Up
 *  disable_up_select           [IN]        do not send GUI_LIST_PEN_ITEM_SELECTED on Pen Up
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_item_pen_function(
        fixed_list_menu *m,
        fixed_menuitem_pen_hdlr item_pen_function,
        BOOL disable_move_highlight,
        BOOL disable_up_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_pen_function = item_pen_function;
    m->disable_move_highlight = disable_move_highlight;
    m->disable_up_select = disable_up_select;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_common_item_data
 * DESCRIPTION
 *  Set the fixed list common menu item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  c       [IN]        common item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_common_item_data(fixed_list_menu *m, void *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->common_item_data = c;
}


/* 
 * Matrix menu
 */

/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_matrix_menu_current_theme
 * DESCRIPTION
 *  Apply the current theme to a fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_matrix_menu_current_theme(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags |= current_fixed_matrix_menu_theme->flags;
    m->focussed_filler = current_fixed_matrix_menu_theme->focussed_filler;
    m->normal_filler = current_fixed_matrix_menu_theme->normal_filler;
    gui_resize_vertical_scrollbar(
        &m->vbar,
        current_fixed_matrix_menu_theme->vbar_width,
        m->height - current_fixed_matrix_menu_theme->hbar_height);
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_matrix_menu_theme->vbar_width, m->y);
    gui_resize_horizontal_scrollbar(
        &m->hbar,
        m->width - current_fixed_matrix_menu_theme->vbar_width,
        current_fixed_matrix_menu_theme->hbar_height);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_matrix_menu_theme
 * DESCRIPTION
 *  Apply the given theme to a fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  t       [IN]        matrix menu theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_matrix_menu_theme(fixed_matrix_menu *m, UI_fixed_matrix_menu_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags |= t->flags;
    m->focussed_filler = t->focussed_filler;
    m->normal_filler = t->normal_filler;
    gui_resize_vertical_scrollbar(
        &m->vbar,
        current_fixed_matrix_menu_theme->vbar_width,
        m->height - current_fixed_matrix_menu_theme->hbar_height);
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_matrix_menu_theme->vbar_width, m->y);
    gui_resize_horizontal_scrollbar(
        &m->hbar,
        m->width - current_fixed_matrix_menu_theme->vbar_width,
        current_fixed_matrix_menu_theme->hbar_height);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_fixed_matrix_menu
 * DESCRIPTION
 *  Create the fixed matrix menu.
 * PARAMETERS
 *  m           [IN]        fixed matrix menu object
 *  x           [IN]        x1 of the menu
 *  y           [IN]        y1 of the menu
 *  width       [IN]        menu width
 *  height      [IN]        menu height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_fixed_matrix_menu(fixed_matrix_menu *m, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags = 0;
    m->x = x;
    m->y = y;
    m->width = width;
    m->height = height;
    m->n_items = 0;
    m->n_columns = 0;
    m->n_rows = 0;
    m->items = NULL;
    m->highlighted_item = 0;
    m->first_displayed_row = 0;
    m->first_displayed_column = 0;
    m->displayed_columns = 0;
    m->displayed_rows = 0;
    m->highlighted_column = 0;
    m->highlighted_row = 0;
    m->item_height = 0;
    m->item_width = 0;
    gui_set_fixed_matrix_menu_current_theme(m);
    gui_create_vertical_scrollbar(
        &m->vbar,
        m->x + m->width - current_fixed_matrix_menu_theme->vbar_width - 1,
        m->y + 2,
        current_fixed_matrix_menu_theme->vbar_width,
        m->height - current_fixed_matrix_menu_theme->hbar_height - 3);
    gui_create_horizontal_scrollbar(
        &m->hbar,
        m->x + 2,
        m->y + m->height - current_fixed_matrix_menu_theme->hbar_height - 1,
        m->width - current_fixed_matrix_menu_theme->vbar_width - 3,
        current_fixed_matrix_menu_theme->hbar_height);
    m->item_highlighted = UI_dummy_function_s32;
    m->item_unhighlighted = UI_dummy_function_s32;
    m->item_display_function = UI_fixed_menuitem_dummy_display_function;
    m->item_hide_function = UI_fixed_menuitem_dummy_display_function;
    m->item_measure_function = UI_fixed_menuitem_dummy_measure_function;
    m->item_highlight_function = UI_fixed_menuitem_dummy_highlight_function;
    m->item_remove_highlight_function = UI_fixed_menuitem_dummy_remove_highlight_function;
    m->trigger_top_function = UI_dummy_function;
    m->trigger_bottom_function = UI_dummy_function;
    m->last_hilited_x = -1;
    m->last_hilited_y = -1;
    m->last_highlighted_item = -1;
    m->cache_bmp_x1 = 0;
    m->cache_bmp_x2 = 0;
    m->cache_bmp_y1 = 0;
    m->cache_bmp_y2 = 0;

    m->buffer.buf_ptr = NULL;

#ifdef __MMI_TOUCH_SCREEN__
    m->pen_event_current_selected_callback_function = NULL;
    m->pen_event_default_selected_callback_function = NULL;
    memset(&(m->pen_state), 0, sizeof(gui_matrix_pen_state_struct));
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    m->up_ind_area.x = 0;
    m->up_ind_area.y = 0;
    m->up_ind_area.width = 0;
    m->up_ind_area.height = 0;
    m->up_ind_area.string = NULL;
    m->up_ind_area.img_id = 0;
    m->down_ind_area.x = 0;
    m->down_ind_area.y = 0;
    m->down_ind_area.width = 0;
    m->down_ind_area.height = 0;
    m->down_ind_area.string = NULL;
    m->down_ind_area.img_id = 0;
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_auto_calculate
 * DESCRIPTION
 *  Automatically calculate a fixed matrix menu.
 *  (Decides the number of columns / rows to be displayed
 *  and the number of items per row or column)
 * PARAMETERS
 *  m           [IN]        fixed matrix menu object
 *  width       [OUT]       menu width
 *  height      [OUT]       menu height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_auto_calculate(fixed_matrix_menu *m, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 menu_width, menu_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    if (m->flags & UI_MATRIX_MENU_SHOW_IND_AREA)
    {
        menu_height = y2 - y1 - MMI_BI_DEGREE_MAIN_MENU_ARROW_BAR_HEIGHT + 1;
    }
    else
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

    menu_height = y2 - y1 + 1;
    menu_width = x2 - x1 + 1;

    /* Autocalculate unspecified parameters               */
    if (m->n_rows == 0 && m->n_columns == 0)    /* both rows and columns is not specified by wgui */
    {
        S32 rows, columns, reminders;

        columns = menu_width / m->item_width;
        rows = pixtel_highdivide(m->n_items, columns);
        while ((columns * 2) / (rows * 3) > 1)
        {
            columns--;
            rows = pixtel_highdivide(m->n_items, columns);
        }
        reminders = m->n_items % columns;
        while (reminders != 0)
        {
            if (reminders + rows - 1 > columns - 1)
            {
                break;
            }
            else
            {
                columns--;
                rows = pixtel_highdivide(m->n_items, columns);
                reminders = m->n_items % columns;
            }
        }
        m->n_rows = rows;
        m->n_columns = columns;
        if (m->item_height <= 0)
        {
            m->item_height = menu_height / m->n_rows;
        }
        if (m->item_width <= 0)
        {
            m->item_width = menu_width / m->n_columns;
        }
    }
    else
    {
        if (m->item_height <= 0)
        {
            m->item_height = menu_height / m->n_rows;
        }
        if (m->n_rows <= 0)
        {
            m->n_rows = menu_height / m->item_height;
        }
        if (m->item_width <= 0)
        {
            m->item_width = menu_width / m->n_columns;
        }
        if (m->n_columns <= 0)
        {
            m->n_columns = menu_width / m->item_width;
        }
    }
    /* Fix rows and columns to match the number of items     */
    if (m->n_items < m->n_columns)
    {
        m->n_rows = 1;
        m->n_columns = m->n_items;
    }
    else
    {
        if (m->n_rows > pixtel_highdivide(m->n_items, m->n_columns))
        {
            m->n_rows = pixtel_highdivide(m->n_items, m->n_columns);
        }
        if ((m->n_columns * m->n_rows) < m->n_items)
        {
            m->n_rows = pixtel_highdivide(m->n_items, m->n_columns);
        }
    }

    *width = menu_width;
    *height = menu_height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_auto_configure
 * DESCRIPTION
 *  Automatically configure a fixed matrix menu.
 *  (Decides the number of columns / rows to be displayed
 *  and the number of items per row or column)
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_auto_configure(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 menu_width, menu_height;
    U8 show_vbar = 0, show_hbar = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((m->n_columns <= 0) && (m->item_width <= 0))
    {
        return;
    }
    if ((m->n_rows <= 0) && (m->item_height <= 0))
    {
        return;
    }
    if (m->n_items == 0)
    {
        return;
    }

    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;

    menu_height = y2 - y1 + 1;
    menu_width = x2 - x1 + 1;

    gui_fixed_matrix_menu_auto_calculate(m, &menu_width, &menu_height);

    /* Calculate the number of displayed rows and columns    */
    m->displayed_rows = menu_height / m->item_height;
    m->displayed_columns = menu_width / m->item_width;

    if (m->displayed_rows < m->n_rows)
    {
        m->flags |= UI_MATRIX_MENU_SHOW_IND_AREA;
        gui_fixed_matrix_menu_auto_calculate(m, &menu_width, &menu_height);
    }

    if (!(m->flags & UI_MATRIX_MENU_DISABLE_SCROLLBAR))
    {
        if ((!(m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR)) ||
            ((m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR) && (m->n_rows > m->displayed_rows)))
        {
            show_vbar = 1;
        }
        if ((!(m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR)) ||
            ((m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR) && (m->n_columns > m->displayed_columns)))
        {
            show_hbar = 1;
        }
    }

    if (show_vbar)
    {
        x2 -= m->vbar.width;
    }
    if (show_hbar)
    {
        y2 -= m->hbar.height;
    }
    menu_height = y2 - y1 + 1;
    menu_width = x2 - x1 + 1;

    /* Recalculate the number of rows that can be displayed  */
    m->displayed_rows = menu_height / m->item_height;
    m->displayed_columns = menu_width / m->item_width;

    /* Fix the number of displayed rows and columns       */
    if (m->displayed_columns > m->n_columns && 
		!(m->n_columns <= 1 && (m->flags & UI_MATRIX_MENU_ALIGN_LEFT_TOP)))
    {
        m->displayed_columns = m->n_columns;
    }
    if (m->displayed_rows > m->n_rows && 
		!(m->n_rows <= 1 && (m->flags & UI_MATRIX_MENU_ALIGN_LEFT_TOP)))
    {
        m->displayed_rows = m->n_rows;
    }
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    else
    {
        if (MMI_current_menu_type == LIST_MATRIX_MENU)
        {
            m->displayed_rows = menu_height / m->item_height;
        }
    }
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

    /* Enable/Disable scrollbars                       */
    if (show_vbar)
    {
        m->flags |= UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR;
    }
    else
    {
        m->flags &= ~UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR;
    }
    if (show_hbar)
    {
        m->flags |= UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR;
    }
    else
    {
        m->flags &= ~UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR;
    }

    if (show_vbar && (!show_hbar))
    {
        gui_resize_vertical_scrollbar(&m->vbar, m->vbar.width, m->height);
    }
    if (show_hbar && (!show_vbar))
    {
        gui_resize_horizontal_scrollbar(&m->hbar, m->width, m->hbar.height);
    }
    if (show_vbar && show_hbar)
    {
        gui_resize_vertical_scrollbar(&m->vbar, m->vbar.width, m->height - m->hbar.height);
        gui_resize_horizontal_scrollbar(&m->hbar, m->width - m->vbar.width, m->hbar.height);
    }
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_matrix_menu_theme->vbar_width, m->y);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_setup
 * DESCRIPTION
 *  Set the number of rows, columns and item dimensions.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  item_width      [IN]        width of each item
 *  item_height     [IN]        height of each item
 *  n_columns       [IN]        number of columns
 *  n_rows          [IN]        number of rows
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_setup(fixed_matrix_menu *m, S32 item_width, S32 item_height, S32 n_columns, S32 n_rows)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_width = item_width;
    m->item_height = item_height;
    m->n_columns = n_columns;
    m->n_rows = n_rows;
    gui_fixed_matrix_menu_auto_configure(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_fixed_matrix_menu
 * DESCRIPTION
 *  Resize the fixed matrix menu.
 * PARAMETERS
 *  m           [IN]        fixed matrix menu object
 *  width       [IN]        new menu width
 *  height      [IN]        new menu height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_fixed_matrix_menu(fixed_matrix_menu *m, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->width = width;
    m->height = height;
    gui_resize_vertical_scrollbar(
        &m->vbar,
        current_fixed_matrix_menu_theme->vbar_width,
        m->height - current_fixed_matrix_menu_theme->hbar_height);
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_matrix_menu_theme->vbar_width, m->y);
    gui_resize_horizontal_scrollbar(
        &m->hbar,
        m->width - current_fixed_matrix_menu_theme->vbar_width,
        current_fixed_matrix_menu_theme->hbar_height);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
    gui_fixed_matrix_menu_auto_configure(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_fixed_matrix_menu
 * DESCRIPTION
 *  Move the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  x       [IN]        new menu x1
 *  y       [IN]        new menu y1
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_fixed_matrix_menu(fixed_matrix_menu *m, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->x = x;
    m->y = y;
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_matrix_menu_theme->vbar_width, m->y);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
    gui_fixed_matrix_menu_auto_configure(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted item in the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_locate_highlighted_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->highlighted_column = m->highlighted_item % m->n_columns;
    m->highlighted_row = m->highlighted_item / m->n_columns;
    if (m->highlighted_column < 0)
    {
        m->highlighted_column = 0;
    }
    if (m->highlighted_row < 0)
    {
        m->highlighted_row = 0;
    }
    if (m->highlighted_column > (m->n_columns - 1))
    {
        m->highlighted_column = m->n_columns - 1;
    }
    if (m->highlighted_row > (m->n_rows - 1))
    {
        m->highlighted_row = m->n_rows - 1;
    }

    if (m->flags & UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW)
    {
        m->first_displayed_row = m->highlighted_row;
        if (m->first_displayed_row > m->n_rows - m->displayed_rows)
        {
            m->first_displayed_row = m->n_rows - m->displayed_rows;
        }
    }
    else if (m->flags & UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW)
    {
        m->first_displayed_row = m->highlighted_row - m->displayed_rows + 1;
        if (m->first_displayed_row < 0)
        {
            m->first_displayed_row = 0;
        }
    }
    if (m->flags & UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL)
    {
        m->first_displayed_column = m->highlighted_column;
        if (m->first_displayed_column > m->n_columns - m->displayed_columns)
        {
            m->first_displayed_column = m->n_columns - m->displayed_columns;
        }
    }
    else if (m->flags & UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL)
    {
        m->first_displayed_column = m->highlighted_column - m->displayed_columns + 1;
        if (m->first_displayed_column < 0)
        {
            m->first_displayed_column = 0;
        }
    }

    if (m->highlighted_column < m->first_displayed_column)
    {
        m->first_displayed_column = m->highlighted_column;
    }
    if (m->highlighted_row < m->first_displayed_row)
    {
        m->first_displayed_row = m->highlighted_row;
    }
    if (m->highlighted_column > (m->first_displayed_column + m->displayed_columns - 1))
    {
        m->first_displayed_column = (m->highlighted_column - m->displayed_columns + 1);
        if (m->first_displayed_column > (m->n_columns - m->displayed_columns))
        {
            m->first_displayed_column = (m->n_columns - m->displayed_columns);
        }
    }
    if (m->highlighted_row > (m->first_displayed_row + m->displayed_rows - 1))
    {
        m->first_displayed_row = (m->highlighted_row - m->displayed_rows + 1);
        if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
        {
            m->first_displayed_row = (m->n_rows - m->displayed_rows);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_next_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item >= (m->n_items - 1))
    {
        if (m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER)
        {
            if (m->trigger_bottom_function)
            {
                m->trigger_bottom_function();
            }
            return; /* exit point */
        }
        else if (m->flags & UI_MATRIX_MENU_LOOP)
        {
            m->highlighted_item = 0;
        }
        else
        {
            return;
        }
    }
    else
    {
        m->highlighted_item++;
    }
    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_previous_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item <= 0)
    {
        if (m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER)
        {
            if (m->trigger_top_function)
            {
                m->trigger_top_function();
            }
            return; /* exit point */
        }
        else if (m->flags & UI_MATRIX_MENU_LOOP)
        {
            m->highlighted_item = m->n_items - 1;
        }
        else
        {
            return;
        }
    }
    else
    {
        m->highlighted_item--;
    }
    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_row
 * DESCRIPTION
 *  Go to the item in the previous row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_previous_row(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;
    S32 old_highlighted_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_row = m->highlighted_row;
    old_highlighted_item = m->highlighted_item;

    /* Menu rotation */
    if ((m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER) && m->highlighted_row <= 0)
    {
        if (m->trigger_top_function)
        {
            m->trigger_top_function();
        }
        return; /* exit point */
    }
    else if (m->highlighted_row <= 0)
    {
        m->highlighted_row = m->n_rows - 1;

        /* matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
        if (m->flags & UI_MATRIX_MENU_VERTICAL_LOOP)
        {
            if (m->highlighted_column == 0)
            {
                m->highlighted_column = m->displayed_columns - 1;
            }
            else
            {
                m->highlighted_column -= 1;
            }
        }

        /* To avoid the blcok cursor go to non-existed item. */
        m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;

        /* To support that a row is not full of items */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 

        if (m->highlighted_item > (m->n_items - 1))
        {
            m->highlighted_row -= 1;
            m->highlighted_item -= m->n_columns;
        }
        m->first_displayed_row = m->highlighted_row - m->displayed_rows + 1;
        if (m->first_displayed_row < 0)
        {
            m->first_displayed_row = 0;
        }
    }
    else
    {
        m->highlighted_row--;
        if (m->highlighted_row < m->first_displayed_row)
        {
            m->first_displayed_row = m->highlighted_row;
        }
    }

    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_next_row
 * DESCRIPTION
 *  Go to the item in the next row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_next_row(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;
    S32 old_highlighted_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_row = m->highlighted_row;
    old_highlighted_item = m->highlighted_item;

    /* Menu rotation */
    if ((m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER) && m->highlighted_row >= (m->n_rows - 1))
    {
        if (m->trigger_bottom_function)
        {
            m->trigger_bottom_function();
        }
        return; /* exit point */
    }
    else if (m->highlighted_row >= (m->n_rows - 1))
    {
        m->highlighted_row = 0;
        m->first_displayed_row = 0;

        /* matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
        if (m->flags & UI_MATRIX_MENU_VERTICAL_LOOP)
        {
            m->highlighted_column += 1;
            if (m->highlighted_column >= m->displayed_columns)
            {
                m->highlighted_column = 0;
            }
        }
    }
    else
    {
        m->highlighted_row++;
        if (m->highlighted_row > (m->first_displayed_row + m->displayed_rows - 1))
        {
            m->first_displayed_row = (m->highlighted_row - m->displayed_rows + 1);
            if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
            {
                m->first_displayed_row = (m->n_rows - m->displayed_rows);
            }
        }
    }

    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    /* to support that a row is not full of items */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    if (m->highlighted_item > (m->n_items - 1)) /* revert   */
    {
        m->highlighted_row = 0;

        /* matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
        if (m->flags & UI_MATRIX_MENU_VERTICAL_LOOP)
        {
            m->highlighted_column += 1;
            if (m->highlighted_column >= m->displayed_columns)
            {
                m->highlighted_column = 0;
            }
        }
        m->highlighted_item = m->highlighted_column;
        m->first_displayed_row = 0;
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_row
 * DESCRIPTION
 *  Go to the specified row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  r       [IN]        row index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_row(fixed_matrix_menu *m, S32 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;
    S32 highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((r < 0) || (r > (m->n_rows - 1)) || (r == m->highlighted_row))
    {
        return;
    }

    highlighted_item = m->highlighted_item;
    highlighted_item += (r - m->highlighted_row) * m->n_columns;
    if (highlighted_item >= m->n_items)
    {
        highlighted_item = m->n_items - 1;
    }
    m->highlighted_item = highlighted_item;

    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_column
 * DESCRIPTION
 *  Go to the previous column. The row index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_previous_column(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For menu rotation */
    if (m->highlighted_column <= 0)
    {
        m->highlighted_column = m->n_columns - 1;
        m->first_displayed_column = m->highlighted_column - m->displayed_columns + 1;
    }
    else
    {
        m->highlighted_column--;
        if (m->highlighted_column < m->first_displayed_column)
        {
            m->first_displayed_column = m->highlighted_column;
        }
    }
    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_next_column
 * DESCRIPTION
 *  Go to the next column. The row index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_next_column(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;
    S32 old_highlighted_column;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_column = m->highlighted_column;
    old_highlighted_item = m->highlighted_item;

    /* for menu rotation */
    if (m->highlighted_column >= (m->n_columns - 1))
    {
        m->highlighted_column = 0;
        m->first_displayed_column = 0;
    }
    else
    {
        m->highlighted_column++;
        if (m->highlighted_column > (m->first_displayed_column + m->displayed_columns - 1))
        {
            m->first_displayed_column = (m->highlighted_column - m->displayed_columns + 1);
            if (m->first_displayed_column > (m->n_columns - m->displayed_columns))
            {
                m->first_displayed_column = (m->n_columns - m->displayed_columns);
            }
        }
    }

    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (m->highlighted_item > (m->n_items - 1)) /* revert   */
    {
        m->highlighted_column = old_highlighted_column;
        m->highlighted_item = old_highlighted_item;
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_column
 * DESCRIPTION
 *  Go to the specified row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  c       [IN]        column index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_column(fixed_matrix_menu *m, S32 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;
    S32 highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((c < 0) || (c > (m->n_columns - 1)) || (c == m->highlighted_column))
    {
        return;
    }

    highlighted_item = m->highlighted_item;
    highlighted_item += c - m->highlighted_column;
    if (highlighted_item >= m->n_items)
    {
        highlighted_item = m->n_items - 1;
    }
    m->highlighted_item = highlighted_item;

    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_first_item
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_first_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->highlighted_column = 0;
    m->highlighted_row = 0;
    m->first_displayed_column = 0;
    m->first_displayed_row = 0;
    m->highlighted_item = 0;
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_last_item
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_last_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->highlighted_item = m->n_items - 1;
    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_next_page
 * DESCRIPTION
 *  Go to the next page.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_next_page(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;
    S32 old_highlighted_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_row = m->highlighted_row;
    old_highlighted_item = m->highlighted_item;
    if (m->highlighted_row >= (m->n_rows - 1))
    {
        return;
    }
    m->first_displayed_row += m->displayed_rows;
    if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
    {
        m->first_displayed_row = (m->n_rows - m->displayed_rows);
    }
    m->highlighted_row = m->first_displayed_row + m->displayed_rows - 1;
    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (m->highlighted_item > (m->n_items - 1)) /* revert   */
    {
        m->highlighted_row = old_highlighted_row;
        m->highlighted_item = old_highlighted_item;
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_page
 * DESCRIPTION
 *  Go to the previous page.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_previous_page(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_item = m->highlighted_item;
    if (m->highlighted_row <= 0)
    {
        return;
    }
    m->first_displayed_row -= m->displayed_rows;
    if (m->first_displayed_row < 0)
    {
        m->first_displayed_row = 0;
    }
    m->highlighted_row = m->first_displayed_row;
    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item by its index.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  i       [IN]        item index to be highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_item(fixed_matrix_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < 0) || (i > (m->n_items - 1)))
    {
        return;
    }
    m->highlighted_item = i;
    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_reset_fixed_matrix_col_rows
 * DESCRIPTION
 *  Zero the number of rows and columns.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_reset_fixed_matrix_col_rows(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* m->n_columns=0; */
    m->n_rows = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_auto_disable_scrollbar
 * DESCRIPTION
 *  Check whether the auto-disable scroll bar option is enabled or not.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object 
 * RETURNS
 *  Return 1 if the auto-disable scroll bar option is enabled; otherwise, -1.
 *****************************************************************************/
S32 gui_fixed_matrix_auto_disable_scrollbar(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(m->flags & UI_MATRIX_MENU_DISABLE_SCROLLBAR))
    {
        if (m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mtk_UI_show_fixed_matrix_menu
 * DESCRIPTION
 *  Show the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void mtk_UI_show_fixed_matrix_menu(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, hilited_x1, hilited_x2, hilited_y1, hilited_y2;
    S32 new_hilited_x1, new_hilited_y1, new_column, new_row;
    S32 xoff, yoff, xoff2, yoff2, width, height;
    S32 first_displayed_item, last_displayed_item;
    U8 show_vbar = 0, show_hbar = 0;
    S32 xPos, xPos2;
    S32 yPos, yPos2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    first_displayed_item = m->first_displayed_row * m->n_columns;
    last_displayed_item = first_displayed_item + (m->displayed_rows * m->n_columns);
    width = m->width;
    height = m->height;
    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        show_hbar = 1;
    }
    if (show_vbar)
    {
        width -= m->vbar.width - 1;
    }
    if (show_hbar)
    {
        height -= m->hbar.height - 1;
    }
    xoff = (width - (m->item_width * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (m->item_height * m->displayed_rows)) / (m->displayed_rows + 1);
    new_row = ((m->last_highlighted_item) / m->n_columns);
    new_column = m->last_highlighted_item - (new_row * m->n_rows);

    x1 = m->x;
    y1 = m->y;
    if (show_vbar && r2lMMIFlag)
    {
        x1 += m->vbar.width;
    }

    new_hilited_x1 = x1 + xoff + (new_column - m->first_displayed_column) * (m->item_width + xoff);
    new_hilited_y1 = y1 + yoff + (new_row - m->first_displayed_row) * (m->item_height + yoff);

    /* if ( m->last_highlighted_item<first_displayed_item || m->last_highlighted_item>last_displayed_item ) */
    if ((m->last_hilited_x != new_hilited_x1 && m->last_hilited_y != new_hilited_y1) ||
        (m->highlighted_item - m->last_highlighted_item) >= (m->displayed_columns * m->displayed_rows))
    {
        m->last_highlighted_item = -1;
        gui_show_fixed_matrix_menu(m);
        return;
    }
    if (m->highlighted_item_width > m->item_width)
    {
        xoff2 = (m->highlighted_item_width - m->item_width);
    }
    else
    {
        xoff2 = 0;
    }
    if (m->highlighted_item_height > m->item_height)
    {
        yoff2 = (m->highlighted_item_height - m->item_height);
    }
    else
    {
        yoff2 = 0;
    }

    gdi_layer_push_clip();
    gdi_layer_set_clip(m->cache_bmp_x1, m->cache_bmp_y1, m->cache_bmp_x2, m->cache_bmp_y2);

#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
    MMI_ASSERT((m->cache_bmp_x2 - m->cache_bmp_x1 + 1) * (m->cache_bmp_y2 - m->cache_bmp_y1 + 1) * gdi_layer_get_bit_per_pixel() >> 3 <=
               MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE);
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */

/* 
 * We cannot use the cache bitmap when matrix main menu sliding comes into play because 
 * it may cache the wrong image. (gui_main_menu_matrix_slide_start() may draw to the cache region.)
 */
#ifndef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
    gdi_image_cache_bmp_draw(m->cache_bmp_x1, m->cache_bmp_y1, &m->buffer);
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

    gdi_layer_pop_clip();

    hilited_x1 = x1 + xoff + (m->highlighted_column - m->first_displayed_column) * (m->item_width + xoff);
    hilited_y1 = y1 + yoff + (m->highlighted_row - m->first_displayed_row) * (m->item_height + yoff);
    hilited_x2 = hilited_x1 + m->highlighted_item_width;
    hilited_y2 = hilited_y1 + m->highlighted_item_height;

    xPos = hilited_x1 - (xoff2 >> 1);
    xPos2 = xPos + m->highlighted_item_width - 1;
    yPos = hilited_y1 - (yoff2 >> 1);
    yPos2 = yPos + m->highlighted_item_height - 1;

    if (xPos < m->x)
    {
        xPos = m->x;
        xPos2 = xPos + m->highlighted_item_width - 1;
    }
    if (xPos2 > m->x + m->width - 1)
    {
        xPos2 = m->x + m->width - 1;
        xPos = xPos2 - m->highlighted_item_width + 1;
    }
    if (yPos < m->y)
    {
        yPos = m->y;
        yPos2 = yPos + m->highlighted_item_height - 1;
    }
    if (yPos2 > m->y + m->height - 1)
    {
        yPos2 = m->y + m->height - 1;
        yPos = yPos2 - m->highlighted_item_height + 1;
    }

    gdi_layer_push_clip();
    gdi_layer_set_clip(xPos, yPos, xPos2, yPos2);

#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
    MMI_ASSERT((xPos2 - xPos + 1) * (yPos2 - yPos + 1) * gdi_layer_get_bit_per_pixel() >> 3 <= 
               MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE);
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */


#ifndef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
    gdi_image_cache_bmp_get(xPos, yPos, xPos2, yPos2, &m->buffer);
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */
    
    gdi_layer_pop_clip();

    m->cache_bmp_x1 = xPos;
    m->cache_bmp_x2 = xPos2;
    m->cache_bmp_y1 = yPos;
    m->cache_bmp_y2 = yPos2;
    m->last_hilited_x = hilited_x1;
    m->last_hilited_y = hilited_y1;

/* The matrix highlight sliding has its own rendering. Do not show here. */
#ifndef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
    m->item_display_function(m->items[m->highlighted_item], m->common_item_data, hilited_x1, hilited_y1);
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

    if (show_vbar)
    {
        gui_set_vertical_scrollbar_range(&m->vbar, m->n_rows);
        gui_set_vertical_scrollbar_scale(&m->vbar, m->displayed_rows);
        gui_set_vertical_scrollbar_value(&m->vbar, m->first_displayed_row);

        if (r2lMMIFlag)
        {
            gui_move_vertical_scrollbar(&m->vbar, m->x, m->y);
        }
        else
        {
            gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - m->vbar.width, m->y);
        }

        gui_show_vertical_scrollbar(&m->vbar); 
    }
    if (show_hbar)
    {
        gui_set_horizontal_scrollbar_range(&m->hbar, m->n_columns);
        gui_set_horizontal_scrollbar_scale(&m->hbar, m->displayed_columns);
        gui_set_horizontal_scrollbar_value(&m->hbar, m->first_displayed_column);
        gui_show_horizontal_scrollbar(&m->hbar);
    }
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__


/*****************************************************************************
 * FUNCTION
 *  gui_setup_fixed_matrix_menu_ind_area
 * DESCRIPTION
 *  Setup matrix menu indication area.
 * PARAMETERS
 *  ind_area        [IN]        indication area object
 *  x               [IN]        x1
 *  y               [IN]        y1
 *  string          [IN]        string 
 *  img_id          [IN]        image id
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_fixed_matrix_menu_ind_area(gui_matrix_ind_area_struct *ind_area, S32 x, S32 y, U8 *string, U16 img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_area->x = x;
    ind_area->y = y;

    ind_area->string = string;
    ind_area->img_id = img_id;
    if (string != NULL && img_id != 0)
    {
        MMI_ASSERT(0);
    }

    ind_area->width = 20;
    ind_area->height = 20;
}

#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_show_fixed_matrix_menu
 * DESCRIPTION
 *  Display the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_fixed_matrix_menu(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, xoff, yoff, width, height;
    UI_filled_area *f;
    S32 i, j, k, o;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 ix, iy, iwidth, iheight, ix2, iy2;
    U8 show_vbar = 0, show_hbar = 0;
    S32 highlite_x = 0, highlite_y = 0; /* Show selected item after all other items displayed //111605 warning Calvin */

#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
    S32 xoff2, yoff2;
    S32 xPos, xPos2, yPos, yPos2;
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */ 
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MMI_BOOL has_previous_page = MMI_FALSE, has_next_page = MMI_FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the image highlight dimension does not fit, use default list highlight filler */
    gui_menuitem_verify_image_highlight_dimension(m->common_item_data);
        
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
    matrix_mm_active_image_num = 0;
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */
        
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        show_hbar = 1;
    }

    if (r2lMMIFlag)
    {
        if (show_vbar)
        {
            x1 = m->x + m->vbar.width;
        }
        else
        {
            x1 = m->x;
        }
        x2 = UI_device_width;
    }
    else
    {
        x1 = m->x;
        x2 = x1 + m->width - 1;
    }

    y1 = m->y;
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    if (m->flags & UI_MATRIX_MENU_SHOW_IND_AREA)
    {
        y2 = y1 + m->height - 1 - MMI_BI_DEGREE_MAIN_MENU_ARROW_BAR_HEIGHT;
    }
    else
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
        y2 = y1 + m->height - 1;

    if (m->flags & UI_LIST_MENU_STATE_FOCUSSED)
    {
        f = m->focussed_filler;
    }
    else
    {
        f = m->normal_filler;
    }
    if (m->flags & UI_MATRIX_MENU_DISABLE_BACKGROUND)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_clip();
    }
    else
    {
        gui_set_clip(x1, y1, x2, y2);
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        #if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
            /* gui_set_transparent_source_layer(dm_get_scr_bg_layer());//should remove */
        #endif 
        }
        else
        {
            UI_filled_area tmp_f = *f;

            /* In current implementation, matrix menu does not support bordered background 
               very well because highlighted item is overlapped with border. */
            tmp_f.flags &= ~(UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_DOUBLE_BORDER);
            
            gui_draw_filled_area(x1, y1, x2, y2, &tmp_f);
        }
    }
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    /* Start Draw Indication Arrows. */
    if (MMI_current_menu_type == LIST_MATRIX_MENU)
    {
        if (m->displayed_rows < m->n_rows)
        {
            S32 hor_gap = 0;

            has_previous_page = MMI_FALSE;
            has_next_page = MMI_FALSE;
            gdi_layer_push_clip();
            gdi_layer_reset_clip();
            if (m->first_displayed_row > 0) /* previous page exists */
            {
                has_previous_page = MMI_TRUE;
            }
            if ((m->first_displayed_row + m->displayed_rows - 1) < m->n_rows - 1)       /* next page exists */
            {
                has_next_page = MMI_TRUE;
            }
            if (has_previous_page && has_next_page)
            {
                hor_gap = (m->width - MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_IND_BG_SIZE * 2) / 3;
                gui_setup_fixed_matrix_menu_ind_area(
                    &(m->up_ind_area),
                    m->x + hor_gap,
                    y2 + 1,
                    (U8*) get_string(26000),
                    0);
                gui_setup_fixed_matrix_menu_ind_area(
                    &(m->down_ind_area),
                    m->x + (hor_gap * 2) + MMI_BI_DEGREE_MAIN_MENU_ARROW_IND_SIZE,
                    y2 + 1,
                    (U8*) get_string(26004),
                    0);
                gdi_draw_solid_rect(
                    m->x + hor_gap,
                    y2 + 1,
                    m->x + hor_gap + MMI_BI_DEGREE_MAIN_MENU_ARROW_IND_SIZE,
                    y2 + MMI_BI_DEGREE_MAIN_MENU_ARROW_BAR_HEIGHT,
                    GDI_COLOR_GREEN);
                gdi_draw_solid_rect(
                    m->x + (hor_gap * 2) + MMI_BI_DEGREE_MAIN_MENU_ARROW_IND_SIZE,
                    y2 - MMI_BI_DEGREE_MAIN_MENU_ARROW_BAR_HEIGHT + 1,
                    m->x + ((hor_gap + MMI_BI_DEGREE_MAIN_MENU_ARROW_IND_SIZE) * 2),
                    y2,
                    GDI_COLOR_GREEN);
            }
            else if (has_previous_page)
            {
                hor_gap = (m->width - MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_IND_BG_SIZE) >> 1;
                gui_setup_fixed_matrix_menu_ind_area(
                    &(m->up_ind_area),
                    m->x + hor_gap,
                    y2 + 1,
                    (U8*) get_string(26000),
                    0);
                gui_setup_fixed_matrix_menu_ind_area(&(m->down_ind_area), 0, 0, NULL, 0);
                gdi_draw_solid_rect(
                    m->x + hor_gap,
                    y2 + 1,
                    m->x + hor_gap + MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_IND_BG_SIZE,
                    y2 + MMI_BI_DEGREE_MAIN_MENU_ARROW_BAR_HEIGHT /* MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT */ ,
                    GDI_COLOR_GREEN);
            }
            else if (has_next_page)
            {
                hor_gap = (m->width - MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_IND_BG_SIZE) >> 1;
                gui_setup_fixed_matrix_menu_ind_area(
                    &(m->down_ind_area),
                    m->x + hor_gap,
                    y2 + 1,
                    (U8*) get_string(26000),
                    0);
                gui_setup_fixed_matrix_menu_ind_area(&(m->up_ind_area), 0, 0, NULL, 0);
                gdi_draw_solid_rect(
                    m->x + hor_gap,
                    y2 + 1,
                    m->x + hor_gap + MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_IND_BG_SIZE,
                    y2 + MMI_BI_DEGREE_MAIN_MENU_ARROW_BAR_HEIGHT /* MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT */ ,
                    GDI_COLOR_RED);
            }
            gdi_layer_pop_clip();
        }
    }
    /* End Draw Indication Arrows. */
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        show_hbar = 1;
    }

    if (m->n_items == 0)
    {
        return;
    }

    if (r2lMMIFlag)
    {
        if (show_hbar)
        {
            y2 -= m->hbar.height - 1;
        }
    }
    else
    {
        if (show_vbar)
        {
            x2 -= m->vbar.width - 1;
        }
        if (show_hbar)
        {
            y2 -= m->hbar.height - 1;
        }
    }

    width = x2 - x1 + 1;
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    if (m->flags & UI_MATRIX_MENU_SHOW_IND_AREA)
    {
        y2 -= MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_IND_BG_SIZE;
    }
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    height = y2 - y1 + 1;
    iwidth = m->item_width;
    iheight = m->item_height;

    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);
    /*
     * xoff=(width>>1)-((iwidth*m->displayed_columns)>>1);
     * yoff=(height>>1)-((iheight*m->displayed_rows)>>1);
     */
    xoff = (width - (iwidth * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (iheight * m->displayed_rows)) / (m->displayed_rows + 1);
    iy = y1 + yoff;
    for (j = 0; j < m->displayed_rows; j++)
    {
        ix = x1 + xoff;
        o = (m->first_displayed_row + j) * m->n_columns;
        for (i = 0; i < m->displayed_columns; i++)
        {
            k = o + (m->first_displayed_column + i);
            if (k > (m->n_items - 1))
            {
                break;
            }
            ix2 = ix + iwidth - 1;
            iy2 = iy + iheight - 1;
            if (ix2 > x2)
            {
                ix2 = x2;
            }
            if (iy2 > y2)
            {
                iy2 = y2;
            }
            gdi_layer_push_clip();
            gui_set_clip(ix, iy, ix2, iy2);
            gui_set_text_clip(ix, iy, ix2, iy2);

        #ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
            /* save matrix icon information for the sliding effect */
            if ((MMI_current_menu_type == MATRIX_MENU) && (MMI_fixed_matrix_menu.flags & UI_MATRIX_MENU_FOR_MAINMENU))
            {
                gui_image_rect    *image_rect = &matrix_mm_rect[matrix_mm_active_image_num];
                fixed_icontext_menuitem_type *mi = (fixed_icontext_menuitem_type*)m->items[k];
                
                image_rect->rect.x = ix;
                image_rect->rect.y = iy;
                image_rect->rect.width = ix2 - ix + 1;
                image_rect->rect.height = iy2 - iy + 1;

                image_rect->image = mi->item_icon;                                
                matrix_mm_active_image_num++;
            }
        #endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */
            
            
            /* show selected item after all other items displayed */
            if (k == m->highlighted_item)
            {
                m->item_remove_highlight_function(m->items[k], m->common_item_data);
                m->item_display_function(m->items[k], m->common_item_data, ix, iy);
                m->item_highlight_function(m->items[k], m->common_item_data);
                highlite_x = ix;
                highlite_y = iy;
            }
            else
            {
                m->item_display_function(m->items[k], m->common_item_data, ix, iy);
            }
            gdi_layer_pop_clip();
            ix += iwidth + xoff;
        }
        iy += iheight + yoff;
    }

    /* EMS menu not optimized in current implementation, but it can be optimized */
    if ((MMI_current_menu_type != MATRIX_MENU_EMS) &&
        (m->flags & UI_MATRIX_MENU_FOR_MAINMENU))
    {
    #ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
        if (m->highlighted_item_width > m->item_width)
        {
            xoff2 = (m->highlighted_item_width - m->item_width);
        }
        else
        {
            xoff2 = 0;
        }
        if (m->highlighted_item_height > m->item_height)
        {
            yoff2 = (m->highlighted_item_height - m->item_height);
        }
        else
        {
            yoff2 = 0;
        }

        xPos = highlite_x - (xoff2 >> 1);
        xPos2 = xPos + m->highlighted_item_width - 1;
        yPos = highlite_y - (yoff2 >> 1);
        yPos2 = yPos + m->highlighted_item_height - 1;

        if (xPos < m->x)
        {
            xPos = m->x;
            xPos2 = xPos + m->highlighted_item_width - 1;
        }
        if (xPos2 > m->x + m->width - 1)
        {
            xPos2 = m->x + m->width - 1;
            xPos = xPos2 - m->highlighted_item_width + 1;
        }
        if (yPos < m->y)
        {
            yPos = m->y;
            yPos2 = yPos + m->highlighted_item_height - 1;
        }
        if (yPos2 > m->y + m->height - 1)
        {
            yPos2 = m->y + m->height - 1;
            yPos = yPos2 - m->highlighted_item_height + 1;
        }

        gdi_layer_push_clip();
        gdi_layer_set_clip(xPos, yPos, xPos2, yPos2);
        
        MMI_ASSERT((xPos2 - xPos + 1) * (yPos2 - yPos + 1) * gdi_layer_get_bit_per_pixel() >> 3 <=
                   MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE);
    
        gdi_image_cache_bmp_get(xPos, yPos, xPos2, yPos2, &m->buffer);
        gdi_layer_pop_clip();

        m->cache_bmp_x1 = xPos;
        m->cache_bmp_x2 = xPos2;
        m->cache_bmp_y1 = yPos;
        m->cache_bmp_y2 = yPos2;
        m->last_hilited_x = highlite_x;
        m->last_hilited_y = highlite_y;
    #endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */ 
    }

    /* gui_set_clip(highlite_x,highlite_y,highlite_x+iwidth,highlite_y+iheight); */

    m->item_display_function(m->items[m->highlighted_item], m->common_item_data, highlite_x, highlite_y);
    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
    if (show_vbar)
    {
        gui_set_vertical_scrollbar_range(&m->vbar, m->n_rows);
        gui_set_vertical_scrollbar_scale(&m->vbar, m->displayed_rows);
        gui_set_vertical_scrollbar_value(&m->vbar, m->first_displayed_row);

        if (r2lMMIFlag)
        {
            gui_move_vertical_scrollbar(&m->vbar, m->x, m->y);
        }
        else
        {
            gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - m->vbar.width, m->y);
        }

        gui_show_vertical_scrollbar(&m->vbar);
    }
    if (show_hbar)
    {
        gui_set_horizontal_scrollbar_range(&m->hbar, m->n_columns);
        gui_set_horizontal_scrollbar_scale(&m->hbar, m->displayed_columns);
        gui_set_horizontal_scrollbar_value(&m->hbar, m->first_displayed_column);
        gui_show_horizontal_scrollbar(&m->hbar);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_hide_fixed_matrix_menu_highlighted_item
 * DESCRIPTION
 *  Hide the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_hide_fixed_matrix_menu_highlighted_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, xoff, yoff, width, height;
    S32 i, j, k;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 ix, iy, iwidth, iheight, ix2, iy2;
    U8 show_vbar = 0, show_hbar = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);
    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        show_hbar = 1;
    }

    if (m->n_items == 0)
    {
        return;
    }
    x1 += 3;
    x2 -= 3;
    y1 += 3;
    y2 -= 3;
    if (show_vbar)
    {
        x2 -= m->vbar.width - 1;
    }
    if (show_hbar)
    {
        y2 -= m->hbar.height - 1;
    }
    iwidth = m->item_width;
    iheight = m->item_height;
    width = x2 - x1 + 1;
    height = y2 - y1 + 1;

    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);

    xoff = (width >> 1) - ((iwidth * m->displayed_columns) >> 1);
    yoff = (height >> 1) - ((iheight * m->displayed_rows) >> 1);
    iy = y1 + yoff;
    for (j = 0; j < m->displayed_rows; j++)
    {
        ix = x1 + xoff;
        for (i = 0; i < m->displayed_columns; i++)
        {
            k = ((m->first_displayed_row + j) * m->n_columns) + (m->first_displayed_column + i);
            if (k > (m->n_items - 1))
            {
                break;
            }
            ix2 = ix + iwidth - 1;
            iy2 = iy + iheight - 1;
            if (ix2 > x2)
            {
                ix2 = x2;
            }
            if (iy2 > y2)
            {
                iy2 = y2;
            }
            gui_set_clip(ix, iy, ix2, iy2);
            gui_set_text_clip(ix, iy, ix2, iy2);
            if (k == m->highlighted_item)
            {
                m->item_hide_function(m->items[k], m->common_item_data, ix, iy);
            }
            ix += iwidth;
        }
        iy += iheight;
    }

    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
}

 
/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_matrix_menu_item_functions
 * DESCRIPTION
 *  Set the fixed matrix menu item interface.
 * PARAMETERS
 *  m                                   [IN]        fixed matrix menu object
 *  item_display_function               [IN]        function to display an item
 *  item_measure_function               [IN]        function to measure an item
 *  item_highlight_function             [IN]        function to highlight an item
 *  item_remove_highlight_function      [IN]        function to remove highlight of an item
 *  item_hide_function                  [IN]        function to hide an item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_matrix_menu_item_functions(
        fixed_matrix_menu *m,
        void (*item_display_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_measure_function) (void *item, void *common_item_data, S32 *width, S32 *height),
        void (*item_highlight_function) (void *item, void *common_item_data),
        void (*item_remove_highlight_function) (void *item, void *common_item_data),
        void (*item_hide_function) (void *item, void *common_item_data, S32 x, S32 y))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_display_function = item_display_function;
    m->item_measure_function = item_measure_function;
    m->item_highlight_function = item_highlight_function;
    m->item_remove_highlight_function = item_remove_highlight_function;
    m->item_hide_function = item_hide_function;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_matrix_menu_common_item_data
 * DESCRIPTION
 *  Set the fixed matrix common menu item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  c       [IN]        common item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_matrix_menu_common_item_data(fixed_matrix_menu *m, void *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->common_item_data = c;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_vertical_scroll_by_pen
 * DESCRIPTION
 *  Scroll the matrix menu vertically by pen.
 * PARAMETERS
 *  m                       [IN]        fixed matrix menu object
 *  first_displayed_row     [IN]        new row index
 *  menu_event              [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_vertical_scroll_by_pen(
                fixed_matrix_menu *m,
                S32 first_displayed_row,
                gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_displayed_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_displayed_row > m->highlighted_row)
    {
        m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
        gui_fixed_matrix_menu_goto_row(m, first_displayed_row);
        m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
        *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
    }
    else
    {
        last_displayed_row = first_displayed_row + m->displayed_rows - 1;
        MMI_DBG_ASSERT(last_displayed_row <= m->n_rows - 1);

        if (last_displayed_row < m->highlighted_row)
        {
            m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
            gui_fixed_matrix_menu_goto_row(m, last_displayed_row);
            m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            /* Scrolling without changing highlight (this case only  happens with pen support) */
            m->first_displayed_row = first_displayed_row;

            /* Although highlighted item stays the same, we need to stop and restart the animation */
            m->item_remove_highlight_function(m->items[m->highlighted_item], m->common_item_data);
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);

            *menu_event = GUI_MATRIX_PEN_NEED_REDRAW;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_horizontal_scroll_by_pen
 * DESCRIPTION
 *  Scroll the matrix menu horizontally by pen.
 * PARAMETERS
 *  m                           [IN]        fixed matrix menu object
 *  first_displayed_column      [IN]        new columnindex
 *  menu_event                  [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_horizontal_scroll_by_pen(
                fixed_matrix_menu *m,
                S32 first_displayed_column,
                gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_displayed_column;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_displayed_column > m->highlighted_column)
    {
        m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;
        gui_fixed_matrix_menu_goto_column(m, first_displayed_column);
        m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;
        *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
    }
    else
    {
        last_displayed_column = first_displayed_column + m->displayed_columns - 1;
        MMI_DBG_ASSERT(last_displayed_column <= m->n_columns - 1);

        if (last_displayed_column < m->highlighted_column)
        {
            m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;
            gui_fixed_matrix_menu_goto_column(m, last_displayed_column);
            m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            /* Scrolling without changing highlight (this case only  happens with pen support) */
            m->first_displayed_column = first_displayed_column;

            /* Although highlighted item stays the same, we need to stop and restart the animation */
            m->item_remove_highlight_function(m->items[m->highlighted_item], m->common_item_data);
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);

            *menu_event = GUI_MATRIX_PEN_NEED_REDRAW;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_handle_pen_position
 * DESCRIPTION
 *  Handle the pen event (down/move/up), go to the menu item, and set the menu event.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  pen_event       [IN]        pen event. Only MMI_PEN_EVENT_DOWN, MMI_PEN_EVENT_MOVE, MMI_PEN_EVENT_UP is supported
 *  menu_event      [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_handle_pen_position(
                fixed_matrix_menu *m,
                S32 x,
                S32 y,
                mmi_pen_event_type_enum pen_event,
                gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * Because the sampling rate of Pen Move events is not very high on hardware, 
     * * we might "jump" to a menu item aparted from the last highlighted menu item.
     */

    /* FIXME. we do not handle the case that hilighted menu item has bigger size, but it is usually okay */

    S32 xoff, yoff;
    S32 width, height;
    S32 iwidth, iheight;
    S32 new_row, new_column, item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define COMPUTE_NEW_ROW()  do {                                            \
      if (y < yoff)                                                           \
         new_row = m->first_displayed_row;                                    \
      else                                                                    \
         new_row = m->first_displayed_row + ((y - yoff) / (iheight + yoff));  \
      if (new_row > m->first_displayed_row + m->displayed_rows - 1)           \
         new_row = m->first_displayed_row + m->displayed_rows - 1;            \
   } while (0)

#define COMPUTE_NEW_COLUMN() do {                                                \
      if (x < xoff)                                                                 \
         new_column = m->first_displayed_column;                                    \
      else                                                                          \
         new_column = m->first_displayed_column + ((x - xoff) / (iwidth + xoff));   \
      if (new_column > m->first_displayed_column + m->displayed_columns - 1)        \
         new_column = m->first_displayed_column + m->displayed_columns - 1;         \
   } while (0)

    y -= m->y;
    x -= m->x;
    iwidth = m->item_width;
    iheight = m->item_height;
    width = m->width;
    height = m->height;
    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        width -= m->vbar.width;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        height -= m->hbar.height;
    }
    xoff = (width - (iwidth * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (iheight * m->displayed_rows)) / (m->displayed_rows + 1);

    MMI_DBG_ASSERT(pen_event == MMI_PEN_EVENT_DOWN || pen_event == MMI_PEN_EVENT_MOVE || pen_event == MMI_PEN_EVENT_UP);

    /* These asumptions are mandatory */
    MMI_DBG_ASSERT(m->first_displayed_row >= 0 &&
                   m->first_displayed_column >= 0 &&
                   m->first_displayed_row <= m->n_rows - m->displayed_rows &&
                   m->first_displayed_column <= m->n_columns - m->displayed_columns);

    if (y < 0)  /* Scroll up */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_row == 0)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
        }
        else
        {
            new_row = m->first_displayed_row - 1;

            COMPUTE_NEW_COLUMN();

            item_index = new_row * m->n_columns + new_column;

            m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
            gui_fixed_matrix_menu_goto_item(m, item_index);
            m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;

            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
    }
    else if (x < 0) /* Scroll left */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_column == 0)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
        }
        else
        {
            new_column = m->first_displayed_column - 1;

            COMPUTE_NEW_ROW();

            item_index = new_row * m->n_columns + new_column;

            m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;
            gui_fixed_matrix_menu_goto_item(m, item_index);
            m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;

            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
    }
    else if (y >= height)   /* Scroll down */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_row == m->n_rows - m->displayed_rows)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
        }
        else
        {
            new_row = m->first_displayed_row + m->displayed_rows;

            COMPUTE_NEW_COLUMN();

            item_index = new_row * m->n_columns + new_column;

            if (item_index < m->n_items)    /* when n_items is not multiple of displayed_columns */
            {
                m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
                gui_fixed_matrix_menu_goto_item(m, item_index);
                m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;

                *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
            }
        }
    }
    else if (x >= width)    /* Scroll right */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_column == m->n_columns - m->displayed_columns)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
        }
        else
        {
            new_column = m->first_displayed_column + m->displayed_columns;

            COMPUTE_NEW_ROW();

            item_index = new_row * m->n_columns + new_column;

            if (item_index < m->n_items)    /* when n_items is not multiple of displayed_columns */
            {
                m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;
                gui_fixed_matrix_menu_goto_item(m, item_index);
                m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;

                *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
            }
        }

    }
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    else if (pen_event == MMI_PEN_EVENT_DOWN
             && (m->up_ind_area.string != NULL || m->up_ind_area.img_id != 0)
             && ((x + m->x) > m->up_ind_area.x && (x + m->x) < (m->up_ind_area.x + m->up_ind_area.width - 1))
             && ((y + m->y) > m->up_ind_area.y && (y + m->y) < (m->up_ind_area.y + m->up_ind_area.height - 1)))
    {

        new_row = m->first_displayed_row - m->displayed_rows;

        item_index = new_row * m->n_columns + m->first_displayed_column;

        m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
        gui_fixed_matrix_menu_goto_item(m, item_index);
        m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;

        *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
    }
    else if (pen_event == MMI_PEN_EVENT_DOWN
             && (m->down_ind_area.string != NULL || m->down_ind_area.img_id != 0)
             && ((x + m->x) > m->down_ind_area.x && (x + m->x) < (m->down_ind_area.x + m->down_ind_area.width - 1))
             && ((y + m->y) > m->down_ind_area.y && (y + m->y) < (m->down_ind_area.y + m->down_ind_area.height - 1)))
    {
        new_row = m->first_displayed_row + m->displayed_rows;

        item_index = new_row * m->n_columns + m->first_displayed_column;

        if (item_index < m->n_items)    /* when n_items is not multiple of displayed_columns */
        {
            m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
            gui_fixed_matrix_menu_goto_item(m, item_index);
            m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;

            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
        }
    }
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    else
    {
        S32 act_x = 0, act_y = 0;

        act_x = xoff * (m->displayed_columns) + (m->displayed_columns) * m->item_width;
        act_y = yoff * (m->displayed_rows) + (m->displayed_rows) * m->item_height;

        if (x > act_x || y > act_y)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            return;
        }

        COMPUTE_NEW_ROW();
        COMPUTE_NEW_COLUMN();

        item_index = new_row * m->n_columns + new_column;
        if (item_index < m->n_items && item_index != m->highlighted_item)
        {
            gui_fixed_matrix_menu_goto_item(m, item_index);
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            if (pen_event == MMI_PEN_EVENT_UP)
            {
                if (m->pen_state.highlight_changed || (item_index >= m->n_items))
                {
                    *menu_event = GUI_MATRIX_PEN_NONE;
                }
                else
                {
                    *menu_event = GUI_MATRIX_PEN_ITEM_SELECTED;
                }
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_translate_pen_event
 * DESCRIPTION
 *  Translate the pen events occured in the matrix menu.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  pen_event       [IN]        pen event type
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  menu_event      [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL gui_fixed_matrix_menu_translate_pen_event(
        fixed_matrix_menu *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_matrix_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &m->pen_state;
    ret = MMI_TRUE;

    *menu_event = GUI_MATRIX_PEN_NONE;

    if (m->flags & UI_MATRIX_MENU_DISABLE_PEN)
    {
        return MMI_FALSE;
    }

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_vertical_scrollbar)
    {
        gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            gui_fixed_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
        }
    }
    else if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_horizontal_scrollbar)
    {
        gui_horizontal_scrollbar_translate_pen_event(&m->hbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            gui_fixed_matrix_menu_horizontal_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
        }
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                {
                    if ((m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR) &&
                        gui_vertical_scrollbar_translate_pen_event(
                            &m->vbar,
                            MMI_PEN_EVENT_DOWN,
                            x,
                            y,
                            &scrollbar_event,
                            &scrollbar_param))
                    {
                        pen_state->pen_on_vertical_scrollbar = 1;
                        pen_state->pen_on_horizontal_scrollbar = 0;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            gui_fixed_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                        }
                    }
                    else if ((m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR) &&
                             gui_horizontal_scrollbar_translate_pen_event(
                                &m->hbar,
                                MMI_PEN_EVENT_DOWN,
                                x,
                                y,
                                &scrollbar_event,
                                &scrollbar_param))
                    {
                        pen_state->pen_on_vertical_scrollbar = 0;
                        pen_state->pen_on_horizontal_scrollbar = 1;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            gui_fixed_matrix_menu_horizontal_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                        }
                    }
                    else
                    {
                        pen_state->pen_on_vertical_scrollbar = 0;
                        pen_state->pen_on_horizontal_scrollbar = 0;

                        gui_fixed_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_DOWN, menu_event);
                    }

                    pen_state->first_highlighed_item = m->highlighted_item;
                    pen_state->highlight_changed = 0;
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_MOVE:
                gui_fixed_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_MOVE, menu_event);
                break;

            case MMI_PEN_EVENT_UP:
                gui_fixed_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_UP, menu_event);
                break;

            case MMI_PEN_EVENT_LONG_TAP:
                /* Do nothing */
                break;

            case MMI_PEN_EVENT_REPEAT:
                /* Do nothing */
                break;

            case MMI_PEN_EVENT_ABORT:
                /* Do nothing */
                break;

            default:
                MMI_ASSERT(0);

        }
    }

    if (ret)
    {
        if (pen_state->first_highlighed_item != m->highlighted_item)
        {
            pen_state->highlight_changed = 1;
        }
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/* GUI: drop down control functions */

UI_drop_down_control_theme *current_drop_down_control_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_drop_down_control_current_theme
 * DESCRIPTION
 *  Set the current theme of the drop down control.
 * PARAMETERS
 *  o           [IN]         drop down control object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_drop_down_control_current_theme(drop_down_control *o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    o->normal_filler = current_drop_down_control_theme->normal_filler;
    o->disabled_filler = current_drop_down_control_theme->disabled_filler;
    o->focussed_filler = current_drop_down_control_theme->focussed_filler;
    o->clicked_filler = current_drop_down_control_theme->clicked_filler;
    o->normal_text_color = current_drop_down_control_theme->normal_text_color;
    o->disabled_text_color = current_drop_down_control_theme->disabled_text_color;
    o->focussed_text_color = current_drop_down_control_theme->focussed_text_color;
    o->clicked_text_color = current_drop_down_control_theme->clicked_text_color;
    o->text_font = current_drop_down_control_theme->text_font;
    o->flags |= current_drop_down_control_theme->flags;
    gui_set_icon_button_BG_theme(&o->down_button, current_drop_down_control_theme->down_button_theme);
    gui_icon_button_set_icon(
        &o->down_button,
        current_drop_down_control_theme->down_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_drop_down_control_theme
 * DESCRIPTION
 *  Set the given theme of the drop down control.
 * PARAMETERS
 *  o           [IN]        drop down control object
 *  t           [IN]        drop down control theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_drop_down_control_theme(drop_down_control *o, UI_drop_down_control_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    o->normal_filler = t->normal_filler;
    o->disabled_filler = t->disabled_filler;
    o->focussed_filler = t->focussed_filler;
    o->clicked_filler = t->clicked_filler;
    o->normal_text_color = t->normal_text_color;
    o->disabled_text_color = t->disabled_text_color;
    o->focussed_text_color = t->focussed_text_color;
    o->clicked_text_color = t->clicked_text_color;
    o->text_font = t->text_font;
    o->flags |= t->flags;
    gui_set_icon_button_BG_theme(&o->down_button, t->down_button_theme);
    gui_icon_button_set_icon(&o->down_button, t->down_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_drop_down_control
 * DESCRIPTION
 *  Create the drop down control.
 * PARAMETERS
 *  o           [IN]        drop down control object
 *  x           [IN]        x
 *  y           [IN]        y
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_drop_down_control(drop_down_control *o, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    o->x = x;
    o->y = y;
    o->width = width;
    o->height = height;
    o->flags = 0;
    gui_create_icon_button(&o->down_button, x + width - height + 1, y + 1, height - 2, height - 2, NULL);
    gui_set_drop_down_control_current_theme(o);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_drop_down_control
 * DESCRIPTION
 *  Resize the drop down control.
 * PARAMETERS
 *  o           [IN]        drop down control object
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_drop_down_control(drop_down_control *o, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    o->width = width;
    o->height = height;
    gui_resize_icon_button(&o->down_button, height - 2, height - 2);
    gui_move_icon_button(&o->down_button, o->x + width - height + 1, o->y + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_drop_down_control
 * DESCRIPTION
 *  Move the drop down control.
 * PARAMETERS
 *  o           [IN]        drop down control object
 *  x           [IN]        x
 *  y           [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_drop_down_control(drop_down_control *o, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    o->x = x;
    o->y = y;
    gui_move_icon_button(&o->down_button, o->x + o->width - o->height + 1, o->y + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_drop_down_control
 * DESCRIPTION
 *  Show the drop down control.
 * PARAMETERS
 *  o           [IN]        drop down control object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_drop_down_control(drop_down_control *o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    UI_filled_area *f;
    color text_color;
    S32 tx, ty, text_width, text_height;
    U32 flags = o->flags;
    U8 button_displayed = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flags & UI_DROP_DOWN_CONTROL_DISABLE_DRAW)
    {
        return;
    }

    x1 = o->x;
    y1 = o->y;
    x2 = x1 + o->width - 1;
    y2 = y1 + o->height - 1;

    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(x1, y1, x2, y2);
    if (flags & UI_DROP_DOWN_CONTROL_STATE_FOCUSSED)
    {
        f = o->focussed_filler;
        text_color = o->focussed_text_color;
    }
    else if (flags & UI_DROP_DOWN_CONTROL_STATE_CLICKED)
    {
        f = o->clicked_filler;
        text_color = o->clicked_text_color;
    }
    else if (flags & UI_DROP_DOWN_CONTROL_STATE_DISABLED)
    {
        f = o->disabled_filler;
        text_color = o->disabled_text_color;
    }
    else
    {
        f = o->normal_filler;
        text_color = o->normal_text_color;
    }
    if (!(flags & UI_DROP_DOWN_CONTROL_DISABLE_BACKGROUND))
    {
        gui_draw_filled_area(x1, y1, x2, y2, f);
    }
    if (flags & UI_DROP_DOWN_CONTROL_SHOW_BUTTON_ON_FOCUS)
    {
        if ((flags & UI_DROP_DOWN_CONTROL_STATE_FOCUSSED) || (flags & UI_DROP_DOWN_CONTROL_STATE_CLICKED))
        {
            gui_show_icon_button(&o->down_button);
            button_displayed = 1;
        }
    }
    else
    {
        gui_show_icon_button(&o->down_button);
        button_displayed = 1;
    }
    if (o->text != NULL)
    {
        gui_set_font(o->text_font);
        gui_measure_string(o->text, &text_width, &text_height);
        ty = y1 + (o->height >> 1) - (text_height >> 1);
        if (flags & UI_DROP_DOWN_CONTROL_TEXT_RIGHT_JUSTIFY)
        {
            if (button_displayed)
            {
                tx = x2 - 4 - text_width - o->down_button.width;
            }
            else
            {
                tx = x2 - 4 - text_width;
            }
        }
        else if (flags & UI_DROP_DOWN_CONTROL_TEXT_CENTER_JUSTIFY)
        {
            if (button_displayed)
            {
                tx = x1 + ((o->width - o->down_button.width) >> 1) - (text_width >> 1);
            }
            else
            {
                tx = x1 + (o->width >> 1) - (text_width >> 1);
            }
        }
        else
        {
            tx = x1 + 5;
        }

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(tx + text_width, ty);
        }
        else
        {
            gui_move_text_cursor(tx, ty);
        }

        gui_set_text_color(text_color);
        gui_set_line_height(text_height);
        gui_print_text(o->text);
    }

    gui_pop_text_clip();
    gui_pop_clip();
}

/* GUI: horizontal select menu functions              */

UI_horizontal_select_theme *current_horizontal_select_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_select_current_theme
 * DESCRIPTION
 *  Apply the current theme to the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_select_current_theme(horizontal_select *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags |= current_horizontal_select_theme->flags;
    m->background_filler = current_horizontal_select_theme->background_filler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_select_theme
 * DESCRIPTION
 *  Apply the given theme to the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 *  t       [IN]        horizontal select menu theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_select_theme(horizontal_select *m, UI_horizontal_select_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags |= t->flags;
    m->background_filler = t->background_filler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_select
 * DESCRIPTION
 *  Create the horizontal select menu.
 * PARAMETERS
 *  m           [IN]        horizontal select menu object
 *  x           [IN]        x
 *  y           [IN]        y
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_select(horizontal_select *m, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->x = x;
    m->y = y;
    m->width = width;
    m->height = height;
    m->n_items = 0;
    m->highlighted_item = 0;
    gui_set_horizontal_select_current_theme(m);
    m->clear_background_callback = NULL;
    m->item_highlighted = UI_dummy_function_s32;
    m->item_unhighlighted = UI_dummy_function_s32;
    m->item_display_function = UI_fixed_menuitem_dummy_display_function;
    m->item_hide_function = UI_fixed_menuitem_dummy_display_function;
    m->item_measure_function = UI_fixed_menuitem_dummy_measure_function;
    m->item_highlight_function = UI_fixed_menuitem_dummy_highlight_function;
    m->item_remove_highlight_function = UI_fixed_menuitem_dummy_remove_highlight_function;
    m->items = NULL;
    m->common_item_data = NULL;
    m->left_arrow_pressed = 0;
    m->right_arrow_pressed = 0;
    m->left_arrow_image = NULL;
    m->right_arrow_image = NULL;
    m->lx = 0;
    m->ly = 0;
    m->rx = 0;
    m->ry = 0;
    m->ix1 = 0;
    m->iy1 = 0;
    m->ix2 = m->width - 1;
    m->iy2 = m->height - 1;
    m->flags = UI_HORIZONTAL_SELECT_NO_ITEM_HIGHLIGHTED;
    m->item_displayed_callback = UI_dummy_menuitem_displayed_function;
#ifdef __MMI_TOUCH_SCREEN__
    memset(&m->pen_state, 0, sizeof(gui_horizontal_select_pen_state_struct));
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_horizontal_select
 * DESCRIPTION
 *  Resize the horizontal select menu.
 * PARAMETERS
 *  m           [IN]        horizontal select menu object
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_horizontal_select(horizontal_select *m, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->width = width;
    m->height = height;
    m->lx = 0;
    m->ly = 0;
    m->rx = 0;
    m->ry = 0;
    m->ix1 = 0;
    m->iy1 = 0;
    m->ix2 = m->width - 1;
    m->iy2 = m->height - 1;

    if (m->left_arrow_image != NULL)
    {
        gui_measure_image(m->left_arrow_image, &iwidth, &iheight);
        m->lx = 2;
        m->ly = (m->height >> 1) - (iheight >> 1);
        m->ix1 = iwidth + 4;
    }
    if (m->right_arrow_image != NULL)
    {
        gui_measure_image(m->right_arrow_image, &iwidth, &iheight);
        m->rx = m->width - iwidth - 2;
        m->ry = (m->height >> 1) - (iheight >> 1);
        m->ix2 = m->width - iwidth - 4;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_horizontal_select
 * DESCRIPTION
 *  Move the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_horizontal_select(horizontal_select *m, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->x = x;
    m->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_item
 * DESCRIPTION
 *  Go to the item by its index.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 *  i       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_goto_item(horizontal_select *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < 0) || (i > m->n_items - 1))
    {
        return;
    }
    if (i == m->highlighted_item)
    {
        return;
    }
    last_highlighted_item = m->highlighted_item;
    m->highlighted_item = i;
    if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[last_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_goto_next_item(horizontal_select *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
    U8 loop_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item >= (m->n_items - 1))
    {
        if (m->flags & UI_LIST_MENU_LOOP)
        {
            loop_flag = 1;
        }
        else
        {
            return;
        }
    }
    last_highlighted_item = m->highlighted_item;
    if (loop_flag)
    {
        m->highlighted_item = 0;
    }
    else
    {
        m->highlighted_item++;
    }
    if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[last_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_goto_previous_item(horizontal_select *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
    U8 loop_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item <= 0)
    {
        if (m->flags & UI_LIST_MENU_LOOP)
        {
            loop_flag = 1;
        }
        else
        {
            return;
        }
    }
    last_highlighted_item = m->highlighted_item;
    if (loop_flag)
    {
        m->highlighted_item = m->n_items - 1;
    }
    else
    {
        m->highlighted_item--;
    }
    if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[last_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_first_item
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_goto_first_item(horizontal_select *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == 0)
    {
        return;
    }
    last_highlighted_item = m->highlighted_item;
    m->highlighted_item = 0;
    if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[last_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_last_item
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_goto_last_item(horizontal_select *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == (m->n_items - 1))
    {
        return;
    }
    last_highlighted_item = m->highlighted_item;
    m->highlighted_item = (m->n_items - 1);
    if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[last_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_horizontal_select
 * DESCRIPTION
 *  Show the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_select(horizontal_select *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    UI_filled_area *f = m->background_filler;
    S32 i;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.hightlight_type = MMI_SCREEN_HIGHLIGHT_FOR_HOR_SELECT;
#endif
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);
    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);

    if (!(m->flags & UI_LIST_MENU_DISABLE_BACKGROUND))
    {
        gui_draw_filled_area(x1 + m->ix1, y1, x1 + m->ix2 - 1, y2, f);
    }

    if (m->clear_background_callback)
    {
        m->clear_background_callback(x1, y1, x2, y2);
    }
    
    if ((m->n_items == 0) || (m->highlighted_item < 0) || (m->highlighted_item > (m->n_items - 1)))
    {
        gui_set_clip(cx1, cy1, cx2, cy2);
        gui_set_text_clip(tx1, ty1, tx2, ty2);
        return;
    }
    if (m->flags & UI_HORIZONTAL_SELECT_NO_ITEM_HIGHLIGHTED)
    {
        m->flags &= ~UI_HORIZONTAL_SELECT_NO_ITEM_HIGHLIGHTED;
        m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
    }
    if (m->left_arrow_image != NULL)
    {
        gui_show_transparent_image(x1 + m->lx, y1 + m->ly + m->left_arrow_pressed, m->left_arrow_image, 0);
    }
    if (m->right_arrow_image != NULL)
    {
        gui_show_transparent_image(x1 + m->rx, y1 + m->ry + m->right_arrow_pressed, m->right_arrow_image, 0);
    }
    x1 = m->x + m->ix1;
    x2 = m->x + m->ix2;
    y1 = m->y + m->iy1;
    y2 = m->y + m->iy2;
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);
    i = m->highlighted_item;
    {
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        m->item_display_function(m->items[i], m->common_item_data, x1, y1);
        m->item_displayed_callback(i, x1, y1, x1 + iwidth - 1, y1 + iheight - 1);
    }

    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_redraw_horizontal_select
 * DESCRIPTION
 *  Draw and blt out the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_redraw_horizontal_select(horizontal_select *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_horizontal_select(m);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(m->x, m->y, m->x + m->width - 1, m->y + m->height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the horizontal select menu.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object     
 *  pen_event       [IN]        pen event type
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  select_event    [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL gui_horizontal_select_translate_pen_event(
        horizontal_select *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_horizontal_select_pen_enum *select_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    S32 in_left_region = 0, in_right_region = 0;
    gui_horizontal_select_pen_state_struct *pen_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &m->pen_state;
    ret = MMI_TRUE;
    *select_event = GUI_HORIZONTAL_SELECT_PEN_NONE;

    if (PEN_CHECK_BOUND(
            x,
            y,
            m->x + pen_state->left_region_x,
            m->y + pen_state->left_region_y,
            pen_state->left_region_width,
            pen_state->left_region_height))
    {
        in_left_region = 1;
    }
    else if (PEN_CHECK_BOUND(
                x,
                y,
                m->x + pen_state->right_region_x,
                m->y + pen_state->right_region_y,
                pen_state->right_region_width,
                pen_state->right_region_height))
    {
        in_right_region = 1;
    }

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            MMI_DBG_ASSERT(!m->left_arrow_pressed && !m->right_arrow_pressed);
            pen_state->pen_down_left_arrow = 0;
            pen_state->pen_down_right_arrow = 0;
            if (in_left_region)
            {
                pen_state->pen_down_left_arrow = 1;
                m->left_arrow_pressed = 1;
                gui_redraw_horizontal_select(m);
            }
            else if (in_right_region)
            {
                pen_state->pen_down_right_arrow = 1;
                m->right_arrow_pressed = 1;
                gui_redraw_horizontal_select(m);
            }
            else if (!PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
            {
                ret = MMI_FALSE;
            }

            break;

        case MMI_PEN_EVENT_UP:
            if (pen_state->pen_down_left_arrow)
            {
                if (in_left_region)
                {
                    *select_event = GUI_HORIZONTAL_SELECT_PEN_PREV;
                }
            }
            else if (pen_state->pen_down_right_arrow)
            {
                if (in_right_region)
                {
                    *select_event = GUI_HORIZONTAL_SELECT_PEN_NEXT;
                }
            }

            if (m->left_arrow_pressed)
            {
                m->left_arrow_pressed = 0;
                gui_redraw_horizontal_select(m);
            }
            else if (m->right_arrow_pressed)
            {
                m->right_arrow_pressed = 0;
                gui_redraw_horizontal_select(m);
            }
            break;

        case MMI_PEN_EVENT_MOVE:
            if (pen_state->pen_down_left_arrow)
            {
                if (in_left_region)
                {
                    if (!m->left_arrow_pressed)
                    {
                        m->left_arrow_pressed = 1;
                        gui_redraw_horizontal_select(m);
                    }
                }
                else
                {
                    if (m->left_arrow_pressed)
                    {
                        m->left_arrow_pressed = 0;
                        gui_redraw_horizontal_select(m);
                    }
                }
            }
            else if (pen_state->pen_down_right_arrow)
            {
                if (in_right_region)
                {
                    if (!m->right_arrow_pressed)
                    {
                        m->right_arrow_pressed = 1;
                        gui_redraw_horizontal_select(m);
                    }
                }
                else
                {
                    if (m->right_arrow_pressed)
                    {
                        m->right_arrow_pressed = 0;
                        gui_redraw_horizontal_select(m);
                    }
                }
            }

            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            break;

        case MMI_PEN_EVENT_ABORT:
            if (m->left_arrow_pressed)
            {
                m->left_arrow_pressed = 0;
                gui_redraw_horizontal_select(m);
            }
            else if (m->right_arrow_pressed)
            {
                m->right_arrow_pressed = 0;
                gui_redraw_horizontal_select(m);
            }
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;

}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_hide_horizontal_select_highlighted_item
 * DESCRIPTION
 *  Hide the highlighted item in the horizontal select menu.
 * PARAMETERS
 *  m       [IN]         horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_hide_horizontal_select_highlighted_item(horizontal_select *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 i;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->n_items == 0)
    {
        return;
    }
    
    if ((m->highlighted_item < 0) || (m->highlighted_item > (m->n_items - 1)))
    {
        return;
    }
    
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);
    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);
    i = m->highlighted_item;
    {
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        m->item_hide_function(m->items[i], m->common_item_data, x1, y1);
    }
    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_select_clear_background_function
 * DESCRIPTION
 *  Set the function used to clear background.
 *  The function is typically used when UI_LIST_MENU_DISABLE_BACKGROUND is set.
 * 
 *  (Set 'clear_bg_function' to NULL to disable the callback)
 * PARAMETERS
 *  m                   [IN]        horizontal select menu object
 *  clear_bg_function   [IN]        callback to clear background
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_select_clear_background_function(
        horizontal_select *m,
        void (*clear_bg_function)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->clear_background_callback = clear_bg_function;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_select_item_functions
 * DESCRIPTION
 *  Set the horizontal select menu item interface.
 * PARAMETERS
 *  m                                   [IN]        horizontal select menu object
 *  item_display_function               [IN]        function to display an item
 *  item_measure_function               [IN]        function to measure an item
 *  item_highlight_function             [IN]        function to highlight an item
 *  item_remove_highlight_function      [IN]        function to remove highlight of an item
 *  item_hide_function                  [IN]        function to hide an item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_select_item_functions(
        horizontal_select *m,
        void (*item_display_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_measure_function) (void *item, void *common_item_data, S32 *width, S32 *height),
        void (*item_highlight_function) (void *item, void *common_item_data),
        void (*item_remove_highlight_function) (void *item, void *common_item_data),
        void (*item_hide_function) (void *item, void *common_item_data, S32 x, S32 y))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_display_function = item_display_function;
    m->item_measure_function = item_measure_function;
    m->item_highlight_function = item_highlight_function;
    m->item_remove_highlight_function = item_remove_highlight_function;
    m->item_hide_function = item_hide_function;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_select_common_item_data
 * DESCRIPTION
 *  Set the horizontal select menu common item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 *  c       [IN]        common item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_select_common_item_data(horizontal_select *m, void *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->common_item_data = c;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_select_images
 * DESCRIPTION
 *  Set horizontal select left and right arrow images.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object        
 *  left_arrow      [IN]        left arrow image
 *  right_arrow     [IN]        right arrow image
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_select_images(horizontal_select *m, PU8 left_arrow, PU8 right_arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->left_arrow_image = left_arrow;
    m->right_arrow_image = right_arrow;
    if (m->left_arrow_image != NULL)
    {
        gui_measure_image(m->left_arrow_image, &width, &height);

    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        m->lx = 0;
        m->ix1 = width + 2;
    #else /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        m->lx = 2;
        m->ly = (m->height >> 1) - (height >> 1);
        m->ix1 = width + 4;
    #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        m->ly = (m->height >> 1) - (height >> 1);

    #ifdef __MMI_TOUCH_SCREEN__
        m->pen_state.left_region_x = m->lx - GUI_HORIZONTAL_SELECT_PEN_VALID_REGION;
        if (m->pen_state.left_region_x < 0)
        {
            m->pen_state.left_region_x = 0;
        }
        m->pen_state.left_region_y = m->ly - GUI_HORIZONTAL_SELECT_PEN_VALID_REGION;
        if (m->pen_state.left_region_y < 0)
        {
            m->pen_state.left_region_y = 0;
        }
        m->pen_state.left_region_width = width + (GUI_HORIZONTAL_SELECT_PEN_VALID_REGION * 2);
        if (m->pen_state.left_region_x + m->pen_state.left_region_width >= (m->width >> 1))
        {
            m->pen_state.left_region_width = (m->width >> 1) - m->pen_state.left_region_x - 1;
        }
        m->pen_state.left_region_height = height + (GUI_HORIZONTAL_SELECT_PEN_VALID_REGION * 2);
        if (m->pen_state.left_region_y + m->pen_state.left_region_height >= m->height)
        {
            m->pen_state.left_region_height = m->height - m->pen_state.left_region_y - 1;
        }
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    if (m->right_arrow_image != NULL)
    {
        gui_measure_image(m->right_arrow_image, &width, &height);

    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        m->rx = m->width - width;
        m->ix2 = m->width - width - 2;
    #else /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        m->rx = m->width - width - 2;
        m->ix2 = m->width - width - 4;
    #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

        m->ry = (m->height >> 1) - (height >> 1);

    #ifdef __MMI_TOUCH_SCREEN__
        m->pen_state.right_region_x = m->rx - GUI_HORIZONTAL_SELECT_PEN_VALID_REGION;
        if (m->pen_state.right_region_x < (m->width >> 1))
        {
            m->pen_state.right_region_x = (m->width >> 1);
        }
        m->pen_state.right_region_y = m->ry - GUI_HORIZONTAL_SELECT_PEN_VALID_REGION;
        if (m->pen_state.right_region_y < 0)
        {
            m->pen_state.right_region_y = 0;
        }
        m->pen_state.right_region_width = width + (GUI_HORIZONTAL_SELECT_PEN_VALID_REGION * 2);
        if (m->pen_state.right_region_x + m->pen_state.right_region_width >= m->width)
        {
            m->pen_state.right_region_width = m->width - m->pen_state.right_region_x - 1;
        }
        m->pen_state.right_region_height = height + (GUI_HORIZONTAL_SELECT_PEN_VALID_REGION * 2);
        if (m->pen_state.right_region_y + m->pen_state.right_region_height >= m->height)
        {
            m->pen_state.right_region_height = m->height - m->pen_state.right_region_y - 1;
        }
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
}


