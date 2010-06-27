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
 *  wgui_fixed_menuitems.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  menuitems related funtions
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
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Always return MMI_MENUITEM_HEIGHT for get_menu_item_height().
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 *
 *
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "wgui_fixed_menuitems.h"
#ifdef __MMI_SLIM_LISTMENU__
#include "GlobalDefs.h"
#endif 
#include "MainMenuDef.h"
#include "CustMenuRes.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/ 

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/ 
integrated_menuitem integratedMenus;

void (*wgui_text_menuitem_reset_scrolling) (void) = UI_dummy_function;
void (*wgui_text_menuitem_restart_scrolling) (void) = UI_dummy_function;

fixed_text_menuitem MMI_fixed_text_menuitem;

fixed_text_menuitem_type *MMI_fixed_text_menuitems = (fixed_text_menuitem_type *) & integratedMenus;
S32 *fixed_text_menu_n_items;

extern U8 GetMenuItemHeight(U8 font_height);
extern U16 gCurrLangIndex;
extern S32 MMI_menuitem_height;

void *MMI_fixed_menuitem_pointers[MAX_FIXED_MENU_ITEM_POINTERS];

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
void *MMI_fixed_menuitem_pointers2[MAX_MAIN_MENU_ITEMS];
#endif

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  get_menu_item_height
 * DESCRIPTION
 *  Get the height of menuitem according to current font height. However, to support 
 *  image highlight, this function always returns MMI_MENUITEM_HEIGHT.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 get_menu_item_height()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0      
/* under construction !*/
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8)MMI_MENUITEM_HEIGHT;

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
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  fixed_text_menuitem_apply_current_theme
 * DESCRIPTION
 *  Apply the current theme for the fixed text menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_text_menuitem_apply_current_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_text_menuitem_current_theme(&MMI_fixed_text_menuitem);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_text_menuitem_apply_theme
 * DESCRIPTION
 *  Apply the given theme to the fixed text menu items.
 * PARAMETERS
 *  t       [IN]        fixed text menu item theme     
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_text_menuitem_apply_theme(UI_fixed_text_menuitem_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_text_menuitem_theme(&MMI_fixed_text_menuitem, t);
}


/*****************************************************************************
 * FUNCTION
 *  create_fixed_text_menuitems
 * DESCRIPTION
 *  Create the fixed text menu items and configure the common data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_text_menuitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_fixed_icontext_menuitems();
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_text_menuitems
 * DESCRIPTION
 *  Resize the fixed text menu items.
 * PARAMETERS
 *  width       [IN]        new width
 *  height      [IN]        new height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_text_menuitems(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_icontext_menuitems(width, height);
}


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_text_list
 * DESCRIPTION
 *  Associate the fixed text menu items with the fixed list menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_text_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    associate_fixed_icontext_list();

	/* set text position */
	set_fixed_text_positions(GUI_TEXT_MENUITEM_TEXT_X, 0);
}


/*****************************************************************************
 * FUNCTION
 *  set_fixed_text_positions
 * DESCRIPTION
 *  Set the text position of the fixed text menu item.
 * PARAMETERS
 *  tx      [IN]        X position of text   (0: centered horizontally)
 *  ty      [IN]        Y position of text   (0: centered vertically)
 * RETURNS
 *  void
 *****************************************************************************/
void set_fixed_text_positions(S32 tx, S32 ty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_fixed_icontext_positions(tx, ty, 1, 0);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_auto_disable_scrollbar
 * DESCRIPTION
 *  Associate fixed text menu items with the fixed list menu (auto disable the
 *  scroll bar).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 fixed_matrix_auto_disable_scrollbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gui_fixed_matrix_auto_disable_scrollbar(&MMI_fixed_matrix_menu));
}


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_text_matrix
 * DESCRIPTION
 *  Associate fixed text menu items with the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_text_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    associate_fixed_icontext_matrix();
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_X;
}


/*****************************************************************************
 * FUNCTION
 *  add_fixed_text_item
 * DESCRIPTION
 *  Add an item to the list of fixed text menu items at the end.
 * PARAMETERS
 *  s       [IN]        item text
 * RETURNS
 *  void
 *****************************************************************************/
void add_fixed_text_item(UI_string_type s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    add_fixed_icontext_item(s, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  add_location_fixed_text_item
 * DESCRIPTION
 *  Add an item to the list of fixed text menu items at a specified index.
 * PARAMETERS
 *  index       [IN]        the location at which the new item is added (zero based)
 *  s           [IN]        item text
 * RETURNS
 *  void
 *****************************************************************************/
void add_location_fixed_text_item(S32 index, UI_string_type s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    add_location_fixed_icontext_item(index, s, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  remove_fixed_text_item
 * DESCRIPTION
 *  Remove a specified item from the fixed list
 * PARAMETERS
 *  index       [IN]        the location of the item to be removed (zero based)
 * RETURNS
 *  void
 *****************************************************************************/
void remove_fixed_text_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    remove_fixed_icontext_item(index);
}


/*****************************************************************************
 * FUNCTION
 *  add_fixed_text_items
 * DESCRIPTION
 *  Add an array of items to the list of fixed text menu items at the end.
 * PARAMETERS
 *  n_items     [IN]        number of items to be added
 *  s           [IN]        an array of item text
 * RETURNS
 *  void
 *****************************************************************************/
void add_fixed_text_items(S32 n_items, UI_string_type *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    add_fixed_icontext_items(n_items, s, NULL);
}

/* fixed icontext item wrappers */

fixed_icontext_menuitem MMI_fixed_icontext_menuitem;
fixed_icontext_menuitem_type *MMI_fixed_icontext_menuitems = (fixed_icontext_menuitem_type *) & integratedMenus;

S32 *fixed_icontext_menu_n_items;

#ifdef __MMI_UI_TRANSPARENT_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  disable_fixed_icontext_menuitem_transparent_effect
 * DESCRIPTION
 *  Disable the transparent effect flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void disable_fixed_icontext_menuitem_transparent_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fixed_icontext_disable_transparent_effect(&MMI_fixed_icontext_menuitem);
    gui_block_transparency_effect();
}


/*****************************************************************************
 * FUNCTION
 *  enable_fixed_icontext_menuitem_transparent_effect
 * DESCRIPTION
 *  Enable the transparent effect flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void enable_fixed_icontext_menuitem_transparent_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_unblock_transparency_effect();
    gui_fixed_icontext_enable_transparent_effect(&MMI_fixed_icontext_menuitem);
}
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  fixed_icontext_menuitem_apply_current_theme
 * DESCRIPTION
 *  Apply the current theme to the fixed icontext menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_icontext_menuitem_apply_current_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_icontext_menuitem_current_theme(&MMI_fixed_icontext_menuitem);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_icontext_menuitem_apply_theme
 * DESCRIPTION
 *  Apply the given theme to the fixed icontext menuitems.
 * PARAMETERS
 *  t       [IN]        fixed icontext menu item theme
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_icontext_menuitem_apply_theme(UI_fixed_icontext_menuitem_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_icontext_menuitem_theme(&MMI_fixed_icontext_menuitem, t);
}


/*****************************************************************************
 * FUNCTION
 *  create_fixed_icontext_menuitems
 * DESCRIPTION
 *  Create a list of icontext menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_icontext_menuitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_icontext_menuitem(&MMI_fixed_icontext_menuitem, 108, 18);
    gui_fixed_icontext_menuitem_set_text_position(&MMI_fixed_icontext_menuitem, 2, 0);
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    gui_set_current_two_line_menuitem_data = set_current_two_line_menuitem_data;
    MMI_fixed_icontext_menuitem.ext_flags &= ~UI_MENUITEM_EXT_SHOW_TWO_LINE_SELECT;
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 

    for (i = 0; i < MAX_FIXED_ICONTEXT_MENU_ITEMS && i < MAX_FIXED_MENU_ITEM_POINTERS; i++)
    {
        MMI_fixed_icontext_menuitems[i].flags = 0;

    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        MMI_fixed_icontext_menuitems[i].ext_flags = 0;
    #endif 

        MMI_fixed_menuitem_pointers[i] = (void*)&MMI_fixed_icontext_menuitems[i];
        MMI_fixed_icontext_menuitems[i].item_icon_handle = GDI_ERROR_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  stop_fixed_icontext_menuitem_animation
 * DESCRIPTION
 *  Stop the icon animation of the specified icontext menu item.
 * PARAMETERS
 *  index       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void stop_fixed_icontext_menuitem_animation(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_icontext_menuitems[index].item_icon_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(MMI_fixed_icontext_menuitems[index].item_icon_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_icontext_menuitems
 * DESCRIPTION
 *  Resize all fixed icontext menu items.
 * PARAMETERS
 *  width       [IN]        new width
 *  height      [IN]        new height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_icontext_menuitems(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width == 0)
    {
        width = MMI_fixed_icontext_menuitem.width;
    }
    if (height == 0)
    {
        height = MMI_fixed_icontext_menuitem.height;
    }
    gui_resize_fixed_icontext_menuitem(&MMI_fixed_icontext_menuitem, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_icontext_list
 * DESCRIPTION
 *  Associate the list of fixed icontext menu items with the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_icontext_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_fixed_list_highlight_handler();
    gui_set_fixed_list_menu_item_functions(
        &MMI_fixed_list_menu,
        gui_show_fixed_icontext_menuitem,
        gui_measure_fixed_icontext_menuitem,
        gui_highlight_fixed_icontext_menuitem,
        gui_remove_highlight_fixed_icontext_menuitem,
        gui_hide_fixed_icontext_menuitem,
        resize_fixed_icontext_menuitems);
#ifdef __MMI_TOUCH_SCREEN__
    gui_set_fixed_list_menu_item_pen_function(
        &MMI_fixed_list_menu,
        gui_fixed_icontext_menuitem_translate_pen_event,
        MMI_FALSE,
        MMI_FALSE);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    set_start_position_and_item_parameters_for_list_highlighter_effect(NULL, NULL, 0, 0);
#endif 
    MMI_fixed_list_menu.first_displayed_item = 0;
    MMI_fixed_list_menu.highlighted_item = 0;
    fixed_icontext_menu_n_items = &MMI_fixed_list_menu.n_items;
    MMI_fixed_list_menu.items = MMI_fixed_menuitem_pointers;
    MMI_fixed_icontext_menuitem.parent_list = &MMI_fixed_list_menu;
    MMI_fixed_icontext_menuitem.parent_matrix = NULL;
    MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_DISABLE_HIGHLIGHT;

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    MMI_fixed_icontext_menuitem.ext_flags &= ~UI_MENUITEM_SHOW_ALL_HINTS;
    MMI_fixed_icontext_menuitem.ext_flags &= ~UI_MENUITEM_SHOW_HIGHLIGHTED_HINT;
    MMI_fixed_icontext_menuitem.ext_flags &= ~UI_MENUITEM_SHOW_ICON_ONLY_ON_HIGHLIGHT;
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_BACKGROUND;
#if(UI_TEXT_MENUITEM_SCROLL_TYPE == UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE)
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_MARQUEE_SCROLL;
#elif(UI_TEXT_MENUITEM_SCROLL_TYPE==UI_TEXT_MENUITEM_SCROLL_TYPE_TWO_DIRECTION)
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_TWO_DIRECTION_SCROLL;
#endif 
    MMI_fixed_list_menu.common_item_data = (void*)&MMI_fixed_icontext_menuitem;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_list_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_list_menu.pen_event_default_selected_callback_function = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    (*fixed_icontext_menu_n_items) = 0;

    resize_fixed_icontext_menuitems(
        MMI_fixed_list_menu.width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
        get_menu_item_height());

	/* set icon text positions */		
	set_fixed_icontext_positions(GUI_ICONTEXT_MENUITEM_TEXT_X, 0, GUI_ICONTEXT_MENUITEM_ICON_X, 0);

    MMI_disable_title_shortcut_display = 0;
    set_MMI_current_fixed_icontext_menuitem_theme_list();
    gui_set_fixed_icontext_menuitem_current_theme(&MMI_fixed_icontext_menuitem);
    wgui_text_menuitem_reset_scrolling = gui_fixed_icontext_menuitem_stop_scroll;
    wgui_text_menuitem_restart_scrolling = gui_fixed_icontext_menuitem_start_scroll;
}


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_icontext_matrix
 * DESCRIPTION
 *  Associate the list of fixed icontext menu items with the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_icontext_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_fixed_matrix_highlight_handler();
    gui_set_fixed_matrix_menu_item_functions(
        &MMI_fixed_matrix_menu,
        gui_show_fixed_icontext_menuitem,
        gui_measure_fixed_icontext_menuitem,
        gui_highlight_fixed_icontext_menuitem,
        gui_remove_highlight_fixed_icontext_menuitem,
        gui_hide_fixed_icontext_menuitem);
    MMI_fixed_matrix_menu.displayed_columns = 0;
    MMI_fixed_matrix_menu.displayed_rows = 0;
    MMI_fixed_matrix_menu.first_displayed_column = 0;
    MMI_fixed_matrix_menu.first_displayed_row = 0;
    MMI_fixed_matrix_menu.highlighted_column = 0;
    MMI_fixed_matrix_menu.highlighted_row = 0;
    MMI_fixed_matrix_menu.highlighted_item = 0;
    MMI_fixed_matrix_menu.last_hilited_x = -1;
    MMI_fixed_matrix_menu.last_hilited_y = -1;
    MMI_fixed_matrix_menu.last_highlighted_item = -1;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_matrix_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_matrix_menu.pen_event_default_selected_callback_function = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    fixed_icontext_menu_n_items = &MMI_fixed_matrix_menu.n_items;
    MMI_fixed_matrix_menu.items = MMI_fixed_menuitem_pointers;
    MMI_fixed_icontext_menuitem.parent_list = NULL;
    MMI_fixed_icontext_menuitem.parent_matrix = &MMI_fixed_matrix_menu;        
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_BACKGROUND;
    MMI_fixed_matrix_menu.common_item_data = &MMI_fixed_icontext_menuitem;
    (*fixed_icontext_menu_n_items) = 0;
    resize_fixed_matrix_menuitems = resize_fixed_icontext_menuitems;
    MMI_disable_title_shortcut_display = 1;
    set_MMI_current_fixed_icontext_menuitem_theme_matrix();
    gui_set_fixed_icontext_menuitem_current_theme(&MMI_fixed_icontext_menuitem);

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    wgui_text_menuitem_reset_scrolling = gui_fixed_icontext_menuitem_stop_scroll;
    wgui_text_menuitem_restart_scrolling = gui_fixed_icontext_menuitem_start_scroll;
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  center_fixed_icontext_positions
 * DESCRIPTION
 *  Set center justification of text and icons within the fixed icontext menu items.
 * PARAMETERS
 *  tx      [IN]        1: Center text horizontally, 0: normal
 *  ty      [IN]        1: Center text vertically, 0: normal
 *  ix      [IN]        1: Center icon horizontally, 0: normal
 *  iy      [IN]        1: Center icon vertically, 0: normal
 * RETURNS
 *  void
 *****************************************************************************/
void center_fixed_icontext_positions(U8 tx, U8 ty, U8 ix, U8 iy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitem.flags &=
        ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_X |
          UI_MENUITEM_CENTER_ICON_Y);

    if (tx)
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_X;
    }
    
    if (ty)
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    }
    
    if (ix)
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_ICON_X;
    }
    
    if (iy)
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_fixed_icontext_positions
 * DESCRIPTION
 *  Set the positions of text and icons within the fixed icontext menu items.
 * PARAMETERS
 *  tx      [IN]        X position of text   (0: The text is centered horizontally.)
 *  ty      [IN]        Y position of text   (0: The text is centered vertically.)
 *  ix      [IN]        X position of icon   (0: The icon is centered horizontally.)
 *  iy      [IN]        Y position of icon   (0: The icon is centered vertically.)
 * RETURNS
 *  void
 *****************************************************************************/
void set_fixed_icontext_positions(S32 tx, S32 ty, S32 ix, S32 iy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitem.flags &=
        ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_X |
          UI_MENUITEM_CENTER_ICON_Y);
              
    if (ix)
    {
        MMI_fixed_icontext_menuitem.icon_x = ix;
    }
    else
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_ICON_X;
    }
    
    if (iy)
    {
        MMI_fixed_icontext_menuitem.icon_y = iy;
    }
    else
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;
    }

	/* Resizing is related to icon_x. The setting order is important here. */
    if (tx)
    {
        MMI_fixed_icontext_menuitem.text_x = tx;
        gui_resize_fixed_icontext_menuitem(
            &MMI_fixed_icontext_menuitem,
            MMI_fixed_icontext_menuitem.width,
            MMI_fixed_icontext_menuitem.height);
    }
    else
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_X;
    }
    
    if (ty)
    {
        MMI_fixed_icontext_menuitem.text_y = ty;
    }
    else
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_menuitem_set_icontext_checkbox_position
 * DESCRIPTION
 *  Set the checkbox x and y offset to menu item (x1, y1).
 * PARAMETERS
 *  x_offset       [IN]     x offset
 *  y_offset       [IN]     y offset
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_menuitem_set_icontext_checkbox_position(S32 x_offset, S32 y_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitem.ext_flags |= UI_MENUITEM_EXT_SHOW_ICONTEXT_CHECKBOX;
    
    MMI_fixed_icontext_menuitem.checkbox_x = x_offset;
    MMI_fixed_icontext_menuitem.checkbox_y = y_offset;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_menuitem_register_icontext_checkbox_callback
 * DESCRIPTION
 *  Register the icontext checkbox callback function.
 * PARAMETERS
 *  clicked_cb      [IN]    checkbox clicked callback function pointer
 *  get_image_cb    [IN]    checkbox get image callback function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_menuitem_register_icontext_checkbox_callback(
        checkbox_clicked_funcptr_type clicked_cb, 
        checkbox_get_image_funcptr_type get_image_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clicked_cb)
    {
        MMI_fixed_icontext_menuitem.checkbox_clicked_callback = clicked_cb;    
    }

    if (get_image_cb)
    {
        MMI_fixed_icontext_menuitem.checkbox_get_image_callback = get_image_cb;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  add_fixed_icontext_item
 * DESCRIPTION
 *  Add a new item to the list of fixed icontext menu items at the end.
 * PARAMETERS
 *  s       [IN]        item text
 *  img     [IN]        item icon
 * RETURNS
 *  void
 *****************************************************************************/
void add_fixed_icontext_item(UI_string_type s, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_icontext_menu_n_items) >= MAX_FIXED_ICONTEXT_MENU_ITEMS)
    {
        return;
    }
    MMI_fixed_icontext_menuitems[(*fixed_icontext_menu_n_items)].item_text = s;
    MMI_fixed_icontext_menuitems[(*fixed_icontext_menu_n_items)].item_icon = img;
    MMI_fixed_icontext_menuitems[(*fixed_icontext_menu_n_items)].item_icon_handle = GDI_ERROR_HANDLE;
    (*fixed_icontext_menu_n_items)++;
}


/*****************************************************************************
 * FUNCTION
 *  change_fixed_icontext_item
 * DESCRIPTION
 *  Change the text and icon of the specified item.
 * PARAMETERS
 *  index       [IN]        item index
 *  s           [IN]        item text
 *  img         [IN]        item icon
 * RETURNS
 *  void
 *****************************************************************************/
void change_fixed_icontext_item(S32 index, UI_string_type s, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitems[index].item_text = s;
    MMI_fixed_icontext_menuitems[index].item_icon = img;
}


/*****************************************************************************
 * FUNCTION
 *  add_location_fixed_icontext_item
 * DESCRIPTION
 *  Add a new item to the list of fixed icontext menu items at the specified index.
 * PARAMETERS
 *  index       [IN]        the location at which the item is added (zero based)
 *  s           [IN]        item text
 *  img         [IN]        item icon
 * RETURNS
 *  void
 *****************************************************************************/
void add_location_fixed_icontext_item(S32 index, UI_string_type s, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_icontext_menu_n_items) >= MAX_FIXED_ICONTEXT_MENU_ITEMS)
    {
        return;
    }
    for (i = (*fixed_icontext_menu_n_items); i > index; i--)
    {
        MMI_fixed_icontext_menuitems[i] = MMI_fixed_icontext_menuitems[i - 1];
    }
    MMI_fixed_icontext_menuitems[index].item_text = s;
    MMI_fixed_icontext_menuitems[index].item_icon = img;
    (*fixed_icontext_menu_n_items)++;
}


/*****************************************************************************
 * FUNCTION
 *  remove_fixed_icontext_item
 * DESCRIPTION
 *  Remove the specified fixed icontext menu item.
 * PARAMETERS
 *  index       [IN]        the location of the item to be removed
 * RETURNS
 *  void
 *****************************************************************************/
void remove_fixed_icontext_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_icontext_menu_n_items) <= 0)
    {
        return;
    }
    for (i = index; i < (*fixed_icontext_menu_n_items) - 1; i++)
    {
        MMI_fixed_icontext_menuitems[i] = MMI_fixed_icontext_menuitems[i + 1];
    }
    (*fixed_icontext_menu_n_items)--;
}


/*****************************************************************************
 * FUNCTION
 *  add_fixed_icontext_items
 * DESCRIPTION
 *  Adds an array of items at the end.
 * PARAMETERS
 *  n_items     [IN]        number of items to be added
 *  s           [IN]        an array of item text strings
 *  img         [IN]        an array of item icons
 * RETURNS
 *  void
 *****************************************************************************/
void add_fixed_icontext_items(S32 n_items, UI_string_type *s, PU8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_items > MAX_FIXED_ICONTEXT_MENU_ITEMS)
    {
        n_items = MAX_FIXED_ICONTEXT_MENU_ITEMS;
    }
    for (i = 0; i < n_items; i++)
    {
        MMI_fixed_icontext_menuitems[i].item_text = s[i];
    #ifdef __MMI_SLIM_LISTMENU__
        MMI_fixed_icontext_menuitems[i].item_icon = (PU8) GetImage(IMG_GLOBAL_L1 + i);
    #else
        if (img == NULL)
        {
            MMI_fixed_icontext_menuitems[i].item_icon = NULL;
        }
        else
        {
            MMI_fixed_icontext_menuitems[i].item_icon = img[i];
        }
    #endif 
    }
    (*fixed_icontext_menu_n_items) = n_items;
}

/* fixed icontext list wrappers        */

fixed_icontext_list_menuitem MMI_fixed_icontext_list_menuitem;

fixed_icontext_list_menuitem_type *MMI_fixed_icontext_list_menuitems =
    (fixed_icontext_list_menuitem_type *) & integratedMenus;

S32 *fixed_icontext_list_menu_n_items;

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
fixed_icontext_list_menuitem_type _MMI_fixed_icontext_list_menuitems[MAX_MAIN_MENU_ITEMS];


/*****************************************************************************
 * FUNCTION
 *  set_fixed_icontext_list_type2
 * DESCRIPTION
 *  Set the icontext menu item pointer to another storage. 
 *  Only for the BI-DEGREE main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_fixed_icontext_list_type2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_list_menuitems = _MMI_fixed_icontext_list_menuitems;
}


/*****************************************************************************
 * FUNCTION
 *  restore_fixed_icontext_list_type
 * DESCRIPTION
 *  Restore the icontext menu item pointer to the original storage. 
 *  Only for the BI-DEGREE main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_fixed_icontext_list_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_list_menuitems = (fixed_icontext_list_menuitem_type*)&integratedMenus;
}

#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  fixed_icontext_list_menuitem_total
 * DESCRIPTION
 *  Get the total number of icontext list menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of icontext list menu items.
 *****************************************************************************/
S32 fixed_icontext_list_menuitem_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (*fixed_icontext_list_menu_n_items);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_icontext_list_menuitem_apply_current_theme
 * DESCRIPTION
 *  Apply the current theme to the fixed icontext list menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_icontext_list_menuitem_apply_current_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_icontext_list_menuitem_current_theme(&MMI_fixed_icontext_list_menuitem);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_icontext_list_menuitem_apply_theme
 * DESCRIPTION
 *  Apply the given theme to the fixed icontext list menu items
 * PARAMETERS
 *  t       [IN]     fixed icontext list menu item theme
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_icontext_list_menuitem_apply_theme(UI_fixed_icontext_list_menuitem_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_icontext_list_menuitem_theme(&MMI_fixed_icontext_list_menuitem, t);
}


/*****************************************************************************
 * FUNCTION
 *  create_fixed_icontext_list_menuitems
 * DESCRIPTION
 *  Create a list of fixed icontext list menuitems.
 * PARAMETERS
 *  n_text_columns      [IN]        number of text columns
 *  n_icon_columns      [IN]        number of icon columns
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_icontext_list_menuitems(S32 n_text_columns, S32 n_icon_columns)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_icontext_list_menuitem(&MMI_fixed_icontext_list_menuitem, 108, 18, n_text_columns, n_icon_columns);
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;

    for (i = 0; i < MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS && i < MAX_FIXED_MENU_ITEM_POINTERS; i++)
    {
        S32 j = 0;

        MMI_fixed_icontext_list_menuitems[i].flags = 0;
        MMI_fixed_menuitem_pointers[i] = (void*)&MMI_fixed_icontext_list_menuitems[i];
        for (j = 0; j < FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS; j++)
        {
            MMI_fixed_icontext_list_menuitems[i].item_icon_handles[j] = GDI_ERROR_HANDLE;
        }
    }
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__


/*****************************************************************************
 * FUNCTION
 *  create_fixed_icontext_list_menuitems2
 * DESCRIPTION
 *  Create the fixed icontext list menu items and initialize individual menu items
 *  at another storage. Only for the BI-DEGREE main menu.
 * PARAMETERS
 *  n_text_columns      [IN]        number of text columns
 *  n_icon_columns      [IN]        number of icon columns
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_icontext_list_menuitems2(S32 n_text_columns, S32 n_icon_columns)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_icontext_list_menuitem(&MMI_fixed_icontext_list_menuitem, 108, 18, n_text_columns, n_icon_columns);
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;

    for (i = 0; i < MAX_MAIN_MENU_ITEMS; i++)
    {
        MMI_fixed_icontext_list_menuitems[i].flags = 0;
        MMI_fixed_menuitem_pointers2[i] = (void*)&MMI_fixed_icontext_list_menuitems[i];
    }
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  set_fixed_icontext_list_menuitems_post_display
 * DESCRIPTION
 *  Register callback handler after an icontext-list menu item is displayed.
 *  
 *  Icontext-list menu item is a general form of menu item that has more than one text & icon item
 *  It can be further extended by registering post-display function which is called after each menu item
 *  is drawn (not bitblted yet).
 * PARAMETERS
 *  post_display_function       [IN]        post display callback function
 * RETURNS
 *  void
 *****************************************************************************/
void set_fixed_icontext_list_menuitems_post_display(void (*post_display_function)(void *item, void *common_item_data, S32 x, S32 y))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fixed_icontext_list_menuitem_set_post_display(&MMI_fixed_icontext_list_menuitem, post_display_function);
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_icontext_list_menuitems
 * DESCRIPTION
 *  Resize all the fixed icontext list menu items.
 * PARAMETERS
 *  width       [IN]        new width
 *  height      [IN]        new height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_icontext_list_menuitems(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width == 0)
    {
        width = MMI_fixed_icontext_list_menuitem.width;
    }
    if (height == 0)
    {
        height = MMI_fixed_icontext_list_menuitem.height;
    }

    gui_resize_fixed_icontext_list_menuitem(&MMI_fixed_icontext_list_menuitem, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  set_fixed_icontext_list_text_coordinates
 * DESCRIPTION
 *  Set the coordinates of the specified text column.
 * PARAMETERS
 *  c           [IN]        index of the text column (zero based)
 *  x           [IN]        position of the text column within the item
 *  y           [IN]        position of the text column within the item
 *  width       [IN]        width of the text column
 *  height      [IN]        height of the text column
 * RETURNS
 *  void
 *****************************************************************************/
void set_fixed_icontext_list_text_coordinates(S32 c, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fixed_icontext_list_menuitem_set_text_coordinates(&MMI_fixed_icontext_list_menuitem, c, x, y, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  set_fixed_icontext_list_icon_coordinates
 * DESCRIPTION
 *  Set the coordinates of the specified icon column.
 * PARAMETERS
 *  c           [IN]        index of the icon column (zero based)
 *  x           [IN]        position of the icon column within the item
 *  y           [IN]        position of the icon column within the item
 *  width       [IN]        width of the icon column
 *  height      [IN]        height of the icon column
 * RETURNS
 *  void
 *****************************************************************************/
void set_fixed_icontext_list_icon_coordinates(S32 c, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fixed_icontext_list_menuitem_set_icon_coordinates(&MMI_fixed_icontext_list_menuitem, c, x, y, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_icontext_list_list
 * DESCRIPTION
 *  Associate the list of fixed icontext list menu items with the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_icontext_list_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_fixed_list_highlight_handler();
    gui_set_fixed_list_menu_item_functions(
        &MMI_fixed_list_menu,
        gui_show_fixed_icontext_list_menuitem,
        gui_measure_fixed_icontext_list_menuitem,
        gui_highlight_fixed_icontext_list_menuitem,
        gui_remove_highlight_fixed_icontext_list_menuitem,
        UI_fixed_menuitem_dummy_hide_function,
        resize_fixed_icontext_list_menuitems);
#ifdef __MMI_TOUCH_SCREEN__
    gui_set_fixed_list_menu_item_pen_function(
        &MMI_fixed_list_menu,
        UI_fixed_menuitem_dummy_pen_function,
        MMI_FALSE,
        MMI_FALSE);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    set_start_position_and_item_parameters_for_list_highlighter_effect(NULL, NULL, 0, 0);
#endif 
    MMI_fixed_list_menu.first_displayed_item = 0;
    MMI_fixed_list_menu.highlighted_item = 0;
    fixed_icontext_list_menu_n_items = &MMI_fixed_list_menu.n_items;
    MMI_fixed_list_menu.items = MMI_fixed_menuitem_pointers;
    MMI_fixed_icontext_list_menuitem.parent_list = &MMI_fixed_list_menu;
    MMI_fixed_icontext_list_menuitem.parent_matrix = NULL;
    MMI_fixed_icontext_list_menuitem.flags &= ~UI_MENUITEM_DISABLE_HIGHLIGHT;
    MMI_fixed_icontext_list_menuitem.flags &= ~UI_MENUITEM_AUTO_CHOOSE_MARQUEE;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_DISABLE_BACKGROUND;
#if(UI_TEXT_MENUITEM_SCROLL_TYPE == UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE)
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_MARQUEE_SCROLL;
#elif(UI_TEXT_MENUITEM_SCROLL_TYPE==UI_TEXT_MENUITEM_SCROLL_TYPE_TWO_DIRECTION)
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_TWO_DIRECTION_SCROLL;
#endif 
    MMI_fixed_list_menu.common_item_data = &MMI_fixed_icontext_list_menuitem;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_list_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_list_menu.pen_event_default_selected_callback_function = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    (*fixed_icontext_list_menu_n_items) = 0;
    resize_fixed_icontext_list_menuitems(
        MMI_fixed_list_menu.width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
        get_menu_item_height());
    MMI_disable_title_shortcut_display = 0;
    set_MMI_current_fixed_icontext_list_menuitem_theme_list();
    gui_set_fixed_icontext_list_menuitem_current_theme(&MMI_fixed_icontext_list_menuitem);
    wgui_text_menuitem_reset_scrolling = gui_fixed_icontext_list_menuitem_stop_scroll;
    wgui_text_menuitem_restart_scrolling = gui_fixed_icontext_list_menuitem_start_scroll;
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_icontext_list_list2
 * DESCRIPTION
 *  Associate the list of fixed icontext list menu items with the fixed list but
 *  with a different menu item storage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_icontext_list_list2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    associate_fixed_icontext_list_list();
    MMI_fixed_list_menu.items = MMI_fixed_menuitem_pointers2;
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_icontext_list_matrix
 * DESCRIPTION
 *  Associate the list of fixed icontext list menu items with the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_icontext_list_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_fixed_matrix_highlight_handler();
    gui_set_fixed_matrix_menu_item_functions(
        &MMI_fixed_matrix_menu,
        gui_show_fixed_icontext_list_menuitem,
        gui_measure_fixed_icontext_list_menuitem,
        gui_highlight_fixed_icontext_list_menuitem,
        gui_remove_highlight_fixed_icontext_list_menuitem,
        UI_fixed_menuitem_dummy_hide_function);
    MMI_fixed_matrix_menu.displayed_columns = 0;
    MMI_fixed_matrix_menu.displayed_rows = 0;
    MMI_fixed_matrix_menu.first_displayed_column = 0;
    MMI_fixed_matrix_menu.first_displayed_row = 0;
    MMI_fixed_matrix_menu.highlighted_column = 0;
    MMI_fixed_matrix_menu.highlighted_row = 0;
    MMI_fixed_matrix_menu.highlighted_item = 0;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_matrix_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_matrix_menu.pen_event_default_selected_callback_function = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    fixed_icontext_list_menu_n_items = &MMI_fixed_matrix_menu.n_items;
    MMI_fixed_matrix_menu.items = MMI_fixed_menuitem_pointers;
    MMI_fixed_icontext_list_menuitem.parent_list = NULL;
    MMI_fixed_icontext_list_menuitem.parent_matrix = &MMI_fixed_matrix_menu;            
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_DISABLE_BACKGROUND;
    MMI_fixed_matrix_menu.common_item_data = &MMI_fixed_icontext_list_menuitem;
    (*fixed_icontext_list_menu_n_items) = 0;
    resize_fixed_matrix_menuitems = resize_fixed_icontext_list_menuitems;
    MMI_disable_title_shortcut_display = 1;
    set_MMI_current_fixed_icontext_list_menuitem_theme_matrix();
    gui_set_fixed_icontext_list_menuitem_current_theme(&MMI_fixed_icontext_list_menuitem);
}


/*****************************************************************************
 * FUNCTION
 *  remove_all_fixed_icontext_item
 * DESCRIPTION
 *  Remove all items in fixed list menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void remove_all_fixed_icontext_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_icontext_list_menu_n_items) <= 0)
    {
        return;
    }
    (*fixed_icontext_list_menu_n_items) = 0;
}


/*****************************************************************************
 * FUNCTION
 *  add_fixed_icontext_list_item_text
 * DESCRIPTION
 *  Change the text in the specified column of an item.
 * PARAMETERS
 *  index       [IN]        item index
 *  c           [IN]        text column index (zero based)
 *  s           [IN]        string to be displayed in this text column
 * RETURNS
 *  void
 *****************************************************************************/
void add_fixed_icontext_list_item_text(S32 index, S32 c, UI_string_type s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_list_menuitems[index].item_texts[c] = s;
}


/*****************************************************************************
 * FUNCTION
 *  add_fixed_icontext_list_item_icon
 * DESCRIPTION
 *  Change the icon in the specified column of an item.
 * PARAMETERS
 *  index       [IN]        item index
 *  c           [IN]        icon column index (zero based)
 *  img         [IN]        icon to be displayed in this icon column
 * RETURNS
 *  void
 *****************************************************************************/
void add_fixed_icontext_list_item_icon(S32 index, S32 c, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_list_menuitems[index].item_icons[c] = img;
}


/*****************************************************************************
 * FUNCTION
 *  fixed_icontext_list_item_insert
 * DESCRIPTION
 *  Inserts a new item to the list of fixed icontext list menu items.
 * PARAMETERS
 *  index       [IN]        index at which a new item is inserted (zero based)
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_icontext_list_item_insert(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_icontext_list_menu_n_items) >= MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS)
    {
        return;
    }
    for (i = 0; i < FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS; i++)
    {
        MMI_fixed_icontext_list_menuitems[index].item_icons[i] = NULL;
        MMI_fixed_icontext_list_menuitems[index].item_icon_handles[i] = GDI_ERROR_HANDLE;
    }
    for (i = 0; i < FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS; i++)
    {
        MMI_fixed_icontext_list_menuitems[index].item_texts[i] = NULL;
    }
    for (i = (*fixed_icontext_list_menu_n_items); i > index; i--)
    {
        MMI_fixed_icontext_list_menuitems[i] = MMI_fixed_icontext_list_menuitems[i - 1];
    }
    (*fixed_icontext_list_menu_n_items)++;
}


/*****************************************************************************
 * FUNCTION
 *  remove_fixed_icontext_list_item
 * DESCRIPTION
 *  Removs an item at the specified index.
 * PARAMETERS
 *  index       [IN]        index of the item to be removed (zero based) 
 * RETURNS
 *  void
 *****************************************************************************/
void remove_fixed_icontext_list_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_icontext_list_menu_n_items) <= 0)
    {
        return;
    }
    for (i = index; i < (*fixed_icontext_list_menu_n_items) - 1; i++)
    {
        MMI_fixed_icontext_list_menuitems[i] = MMI_fixed_icontext_list_menuitems[i + 1];
    }
    (*fixed_icontext_list_menu_n_items)--;
}

/* Fixed twostate item wrappers        */

fixed_twostate_menuitem MMI_fixed_twostate_menuitem;
fixed_twostate_menuitem_type *MMI_fixed_twostate_menuitems = (fixed_twostate_menuitem_type *) & integratedMenus;

S32 *fixed_twostate_menu_n_items;


/*****************************************************************************
 * FUNCTION
 *  fixed_twostate_menuitem_apply_current_theme
 * DESCRIPTION
 *  Apply the current theme to the fixed twostate menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_twostate_menuitem_apply_current_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_twostate_menuitem_current_theme(&MMI_fixed_twostate_menuitem);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_twostate_menuitem_apply_theme
 * DESCRIPTION
 *  Apply the current theme to the fixed twostate menu items.
 * PARAMETERS
 *  t       [IN]        fixed two-state menu item theme     
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_twostate_menuitem_apply_theme(UI_fixed_twostate_menuitem_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_twostate_menuitem_theme(&MMI_fixed_twostate_menuitem, t);
}


/*****************************************************************************
 * FUNCTION
 *  create_fixed_twostate_menuitems
 * DESCRIPTION
 *  Create a list of fixed two-state menu items.
 * PARAMETERS
 *  ON_icon         [IN]        common ON icon
 *  OFF_icon        [IN]        common OFF icon
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_twostate_menuitems(PU8 ON_icon, PU8 OFF_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_twostate_menuitem(&MMI_fixed_twostate_menuitem, 108, MMI_MENUITEM_HEIGHT, ON_icon, OFF_icon);      /* 082205 Calvin modified */
    gui_fixed_twostate_menuitem_set_text_position(&MMI_fixed_twostate_menuitem, 24, 0);
    MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;

    for (i = 0; i < MAX_FIXED_TWOSTATE_MENU_ITEMS && i < MAX_FIXED_MENU_ITEM_POINTERS; i++)
    {
        MMI_fixed_twostate_menuitems[i].flags = 0;
        MMI_fixed_menuitem_pointers[i] = (void*)&MMI_fixed_twostate_menuitems[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_twostate_menuitems
 * DESCRIPTION
 *  Resize all the fixed two-state menu items.
 * PARAMETERS
 *  width       [IN]        new width
 *  height      [IN]        new height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_twostate_menuitems(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width == 0)
    {
        width = MMI_fixed_twostate_menuitem.width;
    }
    if (height == 0)
    {
        height = MMI_fixed_twostate_menuitem.height;
    }
    gui_resize_fixed_twostate_menuitem(&MMI_fixed_twostate_menuitem, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_twostate_list
 * DESCRIPTION
 *  Associate the list of fixed two-state menuitems with the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_twostate_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_fixed_list_highlight_handler();
    gui_set_fixed_list_menu_item_functions(
        &MMI_fixed_list_menu,
        gui_show_fixed_twostate_menuitem,
        gui_measure_fixed_twostate_menuitem,
        gui_highlight_fixed_twostate_menuitem,
        gui_remove_highlight_fixed_twostate_menuitem,
        UI_fixed_menuitem_dummy_hide_function,
        resize_fixed_twostate_menuitems);
#ifdef __MMI_TOUCH_SCREEN__
    gui_set_fixed_list_menu_item_pen_function(
        &MMI_fixed_list_menu,
        gui_fixed_twostate_menuitem_translate_pen_event,
        MMI_FALSE,
        MMI_TRUE);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    set_start_position_and_item_parameters_for_list_highlighter_effect(NULL, NULL, 0, 0);
#endif 
    MMI_fixed_list_menu.first_displayed_item = 0;
    MMI_fixed_list_menu.highlighted_item = 0;
    fixed_twostate_menu_n_items = &MMI_fixed_list_menu.n_items;
    MMI_fixed_list_menu.items = MMI_fixed_menuitem_pointers;
    MMI_fixed_twostate_menuitem.parent_list = &MMI_fixed_list_menu;
    MMI_fixed_twostate_menuitem.parent_matrix = NULL;    
    MMI_fixed_twostate_menuitem.flags &= ~UI_MENUITEM_DISABLE_HIGHLIGHT;
    MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_DISABLE_BACKGROUND;
#if(UI_TEXT_MENUITEM_SCROLL_TYPE == UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE)
    MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_MARQUEE_SCROLL;
#elif(UI_TEXT_MENUITEM_SCROLL_TYPE==UI_TEXT_MENUITEM_SCROLL_TYPE_TWO_DIRECTION)
    MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_TWO_DIRECTION_SCROLL;
#endif 
    MMI_fixed_list_menu.common_item_data = (void*)&MMI_fixed_twostate_menuitem;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_list_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_list_menu.pen_event_default_selected_callback_function = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    (*fixed_twostate_menu_n_items) = 0;
    resize_fixed_twostate_menuitems(
        MMI_fixed_list_menu.width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
        get_menu_item_height());

	/* set twostate positions (share the same positions with the icontext menuitem) */
	set_fixed_twostate_positions(GUI_ICONTEXT_MENUITEM_TEXT_X, 0, GUI_ICONTEXT_MENUITEM_ICON_X, 0);

    MMI_disable_title_shortcut_display = 0;
    set_MMI_current_fixed_twostate_menuitem_theme_list();
    gui_set_fixed_twostate_menuitem_current_theme(&MMI_fixed_twostate_menuitem);
    wgui_text_menuitem_reset_scrolling = gui_fixed_twostate_menuitem_stop_scroll;
    wgui_text_menuitem_restart_scrolling = gui_fixed_twostate_menuitem_start_scroll;
}


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_twostate_matrix
 * DESCRIPTION
 *  Associate the list of fixed twos-tate menu items with the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_twostate_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_fixed_matrix_highlight_handler();
    gui_set_fixed_matrix_menu_item_functions(
        &MMI_fixed_matrix_menu,
        gui_show_fixed_twostate_menuitem,
        gui_measure_fixed_twostate_menuitem,
        gui_highlight_fixed_twostate_menuitem,
        gui_remove_highlight_fixed_twostate_menuitem,
        UI_fixed_menuitem_dummy_hide_function);
    MMI_fixed_matrix_menu.displayed_columns = 0;
    MMI_fixed_matrix_menu.displayed_rows = 0;
    MMI_fixed_matrix_menu.first_displayed_column = 0;
    MMI_fixed_matrix_menu.first_displayed_row = 0;
    MMI_fixed_matrix_menu.highlighted_column = 0;
    MMI_fixed_matrix_menu.highlighted_row = 0;
    MMI_fixed_matrix_menu.highlighted_item = 0;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_matrix_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_matrix_menu.pen_event_default_selected_callback_function = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    fixed_twostate_menu_n_items = &MMI_fixed_matrix_menu.n_items;
    MMI_fixed_matrix_menu.items = MMI_fixed_menuitem_pointers;
    MMI_fixed_twostate_menuitem.parent_list = NULL;
    MMI_fixed_twostate_menuitem.parent_matrix = &MMI_fixed_matrix_menu;                
    MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_DISABLE_BACKGROUND;
    MMI_fixed_matrix_menu.common_item_data = &MMI_fixed_twostate_menuitem;
    (*fixed_twostate_menu_n_items) = 0;
    resize_fixed_matrix_menuitems = resize_fixed_twostate_menuitems;
    MMI_disable_title_shortcut_display = 1;
    set_MMI_current_fixed_twostate_menuitem_theme_matrix();
    gui_set_fixed_twostate_menuitem_current_theme(&MMI_fixed_twostate_menuitem);
}


/*****************************************************************************
 * FUNCTION
 *  center_fixed_twostate_positions
 * DESCRIPTION
 *  Set center justification of text and icons within the fixed two-state menu items.
 * PARAMETERS
 *  tx      [IN]        1: Center text horizontally, 0: normal
 *  ty      [IN]        1: Center text vertically, 0: normal
 *  ix      [IN]        1: Center icon horizontally, 0: normal
 *  iy      [IN]        1: Center icon vertically, 0: normal
 * RETURNS
 *  void
 *****************************************************************************/
void center_fixed_twostate_positions(U8 tx, U8 ty, U8 ix, U8 iy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_twostate_menuitem.flags &=
        ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_X |
          UI_MENUITEM_CENTER_ICON_Y);
    if (tx)
    {
        MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_X;
    }
    if (ty)
    {
        MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    }
    if (ix)
    {
        MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_ICON_X;
    }
    if (iy)
    {
        MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_fixed_twostate_positions
 * DESCRIPTION
 *  Set the positions of text and icons within the fixed two-state menu items.
 * PARAMETERS
 *  tx      [IN]        X position of text   (0: The text is centered horizontally.)
 *  ty      [IN]        Y position of text   (0: The text is centered vertically.)
 *  ix      [IN]        X position of icon   (0: The icon is centered horizontally.)
 *  iy      [IN]        Y position of icon   (0: The icon is centered vertically.)
 * RETURNS
 *  void
 *****************************************************************************/
void set_fixed_twostate_positions(S32 tx, S32 ty, S32 ix, S32 iy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_twostate_menuitem.flags &=
        ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_X |
          UI_MENUITEM_CENTER_ICON_Y);

    if (ix)
    {
        MMI_fixed_twostate_menuitem.icon_x = ix;
    }
    else
    {
        MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_ICON_X;
    }

    if (iy)
    {
        MMI_fixed_twostate_menuitem.icon_y = iy;
    }
    else
    {
        MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;
    }

	/* Resizing is related to icon_x. The setting order is important here. */
    if (tx)
    {
        MMI_fixed_twostate_menuitem.text_x = tx;
        gui_resize_fixed_twostate_menuitem(
            &MMI_fixed_twostate_menuitem,
            MMI_fixed_twostate_menuitem.width,
            MMI_fixed_twostate_menuitem.height);
    }
    else
    {
        MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_X;
    }

    if (ty)
    {
        MMI_fixed_twostate_menuitem.text_y = ty;
    }
    else
    {
        MMI_fixed_twostate_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_fixed_twostate_icons
 * DESCRIPTION
 *  Change the icons to be used in fixed two-state menu items.
 * PARAMETERS
 *  ON_icon         [IN]        icon to be displayed when an item is selected
 *  OFF_icon        [IN]        icon to be displayed when the item is not selected
 * RETURNS
 *  void
 *****************************************************************************/
void set_fixed_twostate_icons(PU8 ON_icon, PU8 OFF_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fixed_twostate_menuitem_set_icons(&MMI_fixed_twostate_menuitem, ON_icon, OFF_icon);
}


/*****************************************************************************
 * FUNCTION
 *  add_fixed_twostate_item
 * DESCRIPTION
 *  Adds an item to the list of fixed two-state menu items at the end.
 * PARAMETERS
 *  s       [IN]        item text
 * RETURNS
 *  void
 *****************************************************************************/
void add_fixed_twostate_item(UI_string_type s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_twostate_menu_n_items) >= MAX_FIXED_TWOSTATE_MENU_ITEMS)
    {
        return;
    }
    MMI_fixed_twostate_menuitems[(*fixed_twostate_menu_n_items)].item_text = s;
    MMI_fixed_twostate_menuitems[(*fixed_twostate_menu_n_items)].flags = 0;
    (*fixed_twostate_menu_n_items)++;
}


/*****************************************************************************
 * FUNCTION
 *  add_location_fixed_twostate_item
 * DESCRIPTION
 *  Adds an item to the list of fixed two-state menu items at the specified index.
 * PARAMETERS
 *  index       [IN]        index at which the item is added (zero based)
 *  s           [IN]        item text
 * RETURNS
 *  void
 *****************************************************************************/
void add_location_fixed_twostate_item(S32 index, UI_string_type s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_twostate_menu_n_items) >= MAX_FIXED_TWOSTATE_MENU_ITEMS)
    {
        return;
    }
    for (i = (*fixed_twostate_menu_n_items); i > index; i--)
    {
        MMI_fixed_twostate_menuitems[i] = MMI_fixed_twostate_menuitems[i - 1];
    }
    MMI_fixed_twostate_menuitems[index].item_text = s;
    MMI_fixed_twostate_menuitems[index].flags = 0;
    (*fixed_twostate_menu_n_items)++;
}


/*****************************************************************************
 * FUNCTION
 *  remove_fixed_twostate_item
 * DESCRIPTION
 *  Remove an item at the specified location.
 * PARAMETERS
 *  index       [IN]        index at which the item is removed (zero based)
 * RETURNS
 *  void
 *****************************************************************************/
void remove_fixed_twostate_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*fixed_twostate_menu_n_items) <= 0)
    {
        return;
    }
    for (i = index; i < (*fixed_twostate_menu_n_items) - 1; i++)
    {
        MMI_fixed_twostate_menuitems[i] = MMI_fixed_twostate_menuitems[i + 1];
    }
    (*fixed_twostate_menu_n_items)--;
}


/*****************************************************************************
 * FUNCTION
 *  add_fixed_twostate_items
 * DESCRIPTION
 *  Add an array of items to the fixed two-state menu item list.
 * PARAMETERS
 *  n_items     [IN]        number of items
 *  s           [IN]        an array of item text strings
 * RETURNS
 *  void
 *****************************************************************************/
void add_fixed_twostate_items(S32 n_items, UI_string_type *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_items > MAX_FIXED_TWOSTATE_MENU_ITEMS)
    {
        n_items = MAX_FIXED_TWOSTATE_MENU_ITEMS;
    }
    for (i = 0; i < n_items; i++)
    {
        MMI_fixed_twostate_menuitems[i].item_text = s[i];
        MMI_fixed_twostate_menuitems[i].flags = 0;
    }
    (*fixed_twostate_menu_n_items) = n_items;
}


/*****************************************************************************
 * FUNCTION
 *  select_fixed_twostate_item
 * DESCRIPTION
 *  Select an item. Set the item to ON state.
 * PARAMETERS
 *  index       [IN]        index of the item to be selected
 * RETURNS
 *  void
 *****************************************************************************/
void select_fixed_twostate_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 0 && index < (*fixed_twostate_menu_n_items))
    {
        MMI_fixed_twostate_menuitems[index].flags |= UI_MENUITEM_STATE_SELECTED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  unselect_fixed_twostate_item
 * DESCRIPTION
 *  Un-select an item. Set the item to OFF state.
 * PARAMETERS
 *  index       [IN]        index of the item to be selected
 * RETURNS
 *  void
 *****************************************************************************/
void unselect_fixed_twostate_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 0 && index < (*fixed_twostate_menu_n_items))
    {
        MMI_fixed_twostate_menuitems[index].flags &= ~UI_MENUITEM_STATE_SELECTED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  toggle_fixed_twostate_item
 * DESCRIPTION
 *  Toggle the state of the specified item.
 * PARAMETERS
 *  index       [IN]        index of the item to be selected
 * RETURNS
 *  void
 *****************************************************************************/
void toggle_fixed_twostate_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 0 && index < (*fixed_twostate_menu_n_items))
    {
        if (MMI_fixed_twostate_menuitems[index].flags & UI_MENUITEM_STATE_SELECTED)
        {
            MMI_fixed_twostate_menuitems[index].flags &= ~UI_MENUITEM_STATE_SELECTED;
        }
        else
        {
            MMI_fixed_twostate_menuitems[index].flags |= UI_MENUITEM_STATE_SELECTED;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_fixed_twostate_item_state
 * DESCRIPTION
 *  Get the state of the item at the given index.
 * PARAMETERS
 *  index       [IN]        item index
 * RETURNS
 *  Return 0 if the item is unselected and 1 if the item is selected.
 *****************************************************************************/
U8 get_fixed_twostate_item_state(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 0 && index < (*fixed_twostate_menu_n_items))
    {
        if (MMI_fixed_twostate_menuitems[index].flags & UI_MENUITEM_STATE_SELECTED)
        {
            return (1);
        }
        else
        {
            return (0);
        }
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_icontext_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the fixed icontext menu item to the maximum width.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 MMI_current_menu_type;
void resize_fixed_icontext_menuitems_to_list_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == PAGE_MENU)
    {
        resize_fixed_icontext_menuitems(MMI_fixed_list_menu.width, MMI_fixed_icontext_menuitem.height);
    }
    else if (MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_DRAW;
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
        MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_DRAW;
        if (MMI_fixed_list_menu.vbar.scale >= MMI_fixed_list_menu.vbar.range)
        {
            resize_fixed_icontext_menuitems(MMI_fixed_list_menu.width - 4, MMI_fixed_icontext_menuitem.height);
        }
    }
    else if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR)
    {
        resize_fixed_icontext_menuitems(MMI_fixed_list_menu.width - 4, MMI_fixed_icontext_menuitem.height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_text_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the fixed text menu item to the maximum width.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_text_menuitems_to_list_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_icontext_menuitems_to_list_width();    
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_icontext_list_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the fixed icontext list menu item to the maximum width.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_icontext_list_menuitems_to_list_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_DRAW;
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
        MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_DRAW;
        if (MMI_fixed_list_menu.vbar.scale >= MMI_fixed_list_menu.vbar.range)
        {
            resize_fixed_icontext_list_menuitems(MMI_fixed_list_menu.width - 4, get_menu_item_height());
        }
    }
    else if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR)
    {
        resize_fixed_icontext_list_menuitems(MMI_fixed_list_menu.width - 4, get_menu_item_height());
    }
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_twostate_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the fixed two-state menu item to the maximum width.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_twostate_menuitems_to_list_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_DRAW;
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
        MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_DRAW;
        if (MMI_fixed_list_menu.vbar.scale >= MMI_fixed_list_menu.vbar.range)
        {
            resize_fixed_twostate_menuitems(MMI_fixed_list_menu.width - 4, get_menu_item_height());
        }
    }
    else if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR)
    {
        resize_fixed_twostate_menuitems(MMI_fixed_list_menu.width - 4, get_menu_item_height());
    }
}


/*****************************************************************************
 * FUNCTION
 *  associate_fixed_multirow_list_list
 * DESCRIPTION
 *  Associate the list of fixed multirow list menu items with the fixed list.
 * PARAMETERS
 *  menu_item_height        [IN]        menu item height
 * RETURNS
 *  void
 *****************************************************************************/
void associate_fixed_multirow_list_list(S32 menu_item_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_fixed_list_highlight_handler();
    gui_set_fixed_list_menu_item_functions(
        &MMI_fixed_list_menu,
        gui_show_fixed_icontext_list_menuitem,
        gui_measure_fixed_icontext_list_menuitem,
        gui_highlight_fixed_icontext_list_menuitem,
        gui_remove_highlight_fixed_icontext_list_menuitem,
        UI_fixed_menuitem_dummy_hide_function,
        resize_fixed_icontext_list_menuitems);
#ifdef __MMI_TOUCH_SCREEN__
    gui_set_fixed_list_menu_item_pen_function(
        &MMI_fixed_list_menu,
        UI_fixed_menuitem_dummy_pen_function,
        MMI_FALSE,
        MMI_FALSE);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    set_start_position_and_item_parameters_for_list_highlighter_effect(NULL, NULL, 0, 0);
#endif 
    MMI_fixed_list_menu.first_displayed_item = 0;
    MMI_fixed_list_menu.highlighted_item = 0;
    MMI_fixed_icontext_list_menuitem.flags |= MENU_MUTLIROW_ICON_LIST;
    fixed_icontext_list_menu_n_items = &MMI_fixed_list_menu.n_items;
    MMI_fixed_list_menu.items = MMI_fixed_menuitem_pointers;
    MMI_fixed_icontext_list_menuitem.parent_list = &MMI_fixed_list_menu;
    MMI_fixed_icontext_list_menuitem.parent_matrix = NULL;        
    MMI_fixed_icontext_list_menuitem.flags &= ~UI_MENUITEM_DISABLE_HIGHLIGHT;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_DISABLE_BACKGROUND;
#if(UI_TEXT_MENUITEM_SCROLL_TYPE == UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE)
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_MARQUEE_SCROLL;
#elif(UI_TEXT_MENUITEM_SCROLL_TYPE==UI_TEXT_MENUITEM_SCROLL_TYPE_TWO_DIRECTION)
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_TWO_DIRECTION_SCROLL;
#endif 
    MMI_fixed_list_menu.common_item_data = &MMI_fixed_icontext_list_menuitem;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_list_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_list_menu.pen_event_default_selected_callback_function = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    (*fixed_icontext_list_menu_n_items) = 0;
    resize_fixed_icontext_list_menuitems(
        MMI_fixed_list_menu.width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
        menu_item_height);
    MMI_disable_title_shortcut_display = 0;
    set_MMI_current_fixed_icontext_list_menuitem_theme_list();
    gui_set_fixed_icontext_list_menuitem_current_theme(&MMI_fixed_icontext_list_menuitem);
    wgui_text_menuitem_reset_scrolling = gui_fixed_icontext_list_menuitem_stop_scroll;
    wgui_text_menuitem_restart_scrolling = gui_fixed_icontext_list_menuitem_start_scroll;
}


/*****************************************************************************
 * FUNCTION
 *  set_single_row_iconlist_fixed_list
 * DESCRIPTION
 *  Remove the multirow list flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_single_row_iconlist_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_list_menuitem.flags &= ~MENU_MUTLIROW_ICON_LIST;
}

#ifdef __MMI_UI_HINTS_IN_MENUITEM__


/*****************************************************************************
 * FUNCTION
 *  wgui_enable_hints_in_icontext_menuitem
 * DESCRIPTION
 *  Enable hints for all menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_enable_hints_in_icontext_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitem.ext_flags |= UI_MENUITEM_SHOW_ALL_HINTS;
    /* Unset in normal_fixed_list() */
    // MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_enable_hint_highlight_in_icontext_menuitem
 * DESCRIPTION
 *  Enable hints for the highlighted menu item only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_enable_hint_highlight_in_icontext_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitem.ext_flags |= UI_MENUITEM_SHOW_HIGHLIGHTED_HINT;
    /* Unset in normal_fixed_list() */
    // MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_icon_only_highlight_in_icontext_menuitem
 * DESCRIPTION
 *  Shows icon only if the menu item is highlighted.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_icon_only_highlight_in_icontext_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitem.ext_flags |= UI_MENUITEM_SHOW_ICON_ONLY_ON_HIGHLIGHT;
    /* Unset in normal_fixed_list() */
    // MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;
}
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

/*
 * Two-line menu item
 */

#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)
scrolling_text wgui_two_line_scroll_text;
extern BOOL r2lMMIFlag;
#endif /* (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__) */ 

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
#include "wgui_categories_defs.h"
#include "wgui_categories_util.h"
#define INLINE_LEVEL_SELECT_USE_IMAGE  1
#define MAXIMUM_TWO_LINE_LENGTH        256
wgui_horizontal_select_menuitem_struct two_line_horizontal_select_menuitem;
wgui_level_select_menutitem_struct two_line_level_select_menuitem;

U8 two_line_string_data[MAXIMUM_TWO_LINE_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH];


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_two_line_two_line_level_select
 * DESCRIPTION
 *  Resize the two line volume selct menu.
 * PARAMETERS
 *  width       [IN]        new width
 *  height      [IN]        new height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_two_line_two_line_level_select(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    two_line_level_select_menuitem.width = width;
    two_line_level_select_menuitem.height = height;
}


#if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) && defined(__MMI_TOUCH_SCREEN__)
static wgui_two_line_arrow_struct mmi_menuitem_right_arrow;
static wgui_two_line_arrow_struct mmi_menuitem_left_arrow;
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_show_two_line_inline_level_select
 * DESCRIPTION
 *  Show the two line level volume select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_two_line_inline_level_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 icon_x;
    S32 icon_end_x;
    PU8 left_arrow;
    PU8 right_arrow;

#if(INLINE_LEVEL_SELECT_USE_IMAGE)
    PU8 volume_image;
    S32 ix, iy;
    U16 i;
#endif /* (INLINE_LEVEL_SELECT_USE_IMAGE) */ 
    S32 width, height;
    S32 lx, ly, rx, ry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!two_line_level_select_menuitem.two_line_select_get_data)
    {
        return;
    }
    x1 = two_line_level_select_menuitem.x;
    y1 = two_line_level_select_menuitem.y;
    x2 = x1 + two_line_level_select_menuitem.width - 1;
    y2 = y1 + two_line_level_select_menuitem.height - 1;

    left_arrow = get_image(LEFT_RED_ARROW);
    right_arrow = get_image(RIGHT_RED_ARROW);
#if(INLINE_LEVEL_SELECT_USE_IMAGE)
    volume_image = get_image(TWO_LINE_VOLUME_IMAGE);
#endif 
    gui_measure_image(left_arrow, &width, &height);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_menuitem_left_arrow.width = width;
    mmi_menuitem_left_arrow.height = height;
#endif /* __MMI_TOUCH_SCREEN__ */
    lx = 0;
    icon_x = lx + width;
    ly = (two_line_level_select_menuitem.height >> 1) - (height >> 1);
    gui_measure_image(right_arrow, &width, &height);
    rx = two_line_level_select_menuitem.width - width - 1;
    icon_end_x = rx;
    ry = (two_line_level_select_menuitem.height >> 1) - (height >> 1);
    gui_measure_image(right_arrow, &width, &height);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_menuitem_right_arrow.width = width;
    mmi_menuitem_right_arrow.height = height;
#endif /* __MMI_TOUCH_SCREEN__ */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    if (!gui_is_current_transparency_with_multi_layer())
    {
        gui_fixed_icontext_disable_transparent_effect(&MMI_fixed_icontext_menuitem);    /* To hide text below scrolling text */
    }
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */ 
    gui_draw_filled_area(x1 + 1, y1, x2, y2, MMI_fixed_icontext_menuitem.focussed_filler);
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    gui_fixed_icontext_enable_transparent_effect(&MMI_fixed_icontext_menuitem); /* To hide text below scrolling text */
#endif 
    if (two_line_level_select_menuitem.current_item)
    {
        gui_show_transparent_image(x1 + lx, y1 + ly, left_arrow, 0);
    }
#ifdef __MMI_TOUCH_SCREEN__
    mmi_menuitem_left_arrow.x = x1 + lx;
    mmi_menuitem_left_arrow.y = y1 + ly;
#endif /* __MMI_TOUCH_SCREEN__ */
    if (two_line_level_select_menuitem.current_item < two_line_level_select_menuitem.no_of_items - 1)
    {
        gui_show_transparent_image(x1 + rx, y1 + ry, right_arrow, 0);
    }
#ifdef __MMI_TOUCH_SCREEN__
	mmi_menuitem_right_arrow.x = x1 + rx;
	mmi_menuitem_right_arrow.y = y1 + ry;
#endif /* __MMI_TOUCH_SCREEN__ */
    gui_set_clip(x1 + icon_x, y1, x1 + icon_end_x, y2);
#if(INLINE_LEVEL_SELECT_USE_IMAGE)
    gui_measure_image(volume_image, &width, &height);
    iy = (two_line_level_select_menuitem.height >> 1) - (height >> 1);
    if (width < icon_end_x - icon_x + 1)
    {
        ix = ((icon_end_x - icon_x + 1) >> 1) - (width >> 1);
    }
    else
    {
        ix = 0;
    }

    for (i = 0; i <= two_line_level_select_menuitem.current_item; i++)
    {
        gdi_image_draw_animation_single_frame(x1 + icon_x, y1 + iy, volume_image, i);
    }
#else /* (INLINE_LEVEL_SELECT_USE_IMAGE) */ 
    {
        S32 total_width = icon_end_x - icon_x + 1;
        S32 total_height = two_line_level_select_menuitem.height - 2;
        S32 x_gap = total_width / (((two_line_level_select_menuitem.no_of_items - 1) << 1) + 1);
        S32 y_gap = total_height / (two_line_level_select_menuitem.no_of_items - 1);
        S32 i;
        color colori;

        y2 = y2 - 1;
        for (i = 0; i < two_line_level_select_menuitem.no_of_items - 1; i++)
        {
            x1 = icon_x + (x_gap * ((i + 1) * 2 - 1));
            x2 = x1 + x_gap;
            y1 = two_line_level_select_menuitem.y + (y_gap * (two_line_level_select_menuitem.no_of_items - 1 - i));
            if (i < two_line_level_select_menuitem.current_item)
            {
                colori = UI_COLOR_BLACK;
            }
            else
            {
                colori = UI_COLOR_WHITE;
            }
            gui_fill_rectangle(x1, y1, x2, y2, colori);
        }
    }
#endif /* (INLINE_LEVEL_SELECT_USE_IMAGE) */ 

    gui_pop_clip();

}


/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_level_select_volume_move_next_item
 * DESCRIPTION
 *  This is called when the user presses right arrow key on volume select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_two_line_level_select_volume_move_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (two_line_level_select_menuitem.current_item == two_line_level_select_menuitem.no_of_items - 1)
    {
        return;
    }
    else
    {
        if (!two_line_level_select_menuitem.
            two_line_select_get_data(
                MMI_fixed_list_menu.highlighted_item,
                two_line_level_select_menuitem.current_item + 1))
        {
            return;
        }
        two_line_level_select_menuitem.current_item++;
    }
    gui_show_two_line_inline_level_select();

    gui_BLT_double_buffer(
        two_line_level_select_menuitem.x,
        two_line_level_select_menuitem.y,
        two_line_level_select_menuitem.x + two_line_level_select_menuitem.width - 1,
        two_line_level_select_menuitem.y + two_line_level_select_menuitem.height - 1);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_level_select_volume_move_previous_item
 * DESCRIPTION
 *  This is called when the user presses left arrow key on volume select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_two_line_level_select_volume_move_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (two_line_level_select_menuitem.current_item == 0)
    {
        return;
    }
    else
    {
        if (!two_line_level_select_menuitem.
            two_line_select_get_data(
                MMI_fixed_list_menu.highlighted_item,
                two_line_level_select_menuitem.current_item - 1))
        {
            return;
        }
        two_line_level_select_menuitem.current_item--;
    }
    gui_show_two_line_inline_level_select();

    gui_BLT_double_buffer(
        two_line_level_select_menuitem.x,
        two_line_level_select_menuitem.y,
        two_line_level_select_menuitem.x + two_line_level_select_menuitem.width - 1,
        two_line_level_select_menuitem.y + two_line_level_select_menuitem.height - 1);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_and_set_keyhandlers_two_line_level_select
 * DESCRIPTION
 *  Set the x and y for inline volume select and its key handlers.
 * PARAMETERS
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_and_set_keyhandlers_two_line_level_select(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    two_line_level_select_menuitem.x = x;
    two_line_level_select_menuitem.y = y;
    if (two_line_level_select_menuitem.two_line_default_value)
    {
        two_line_level_select_menuitem.current_item = two_line_level_select_menuitem.two_line_default_value(MMI_fixed_list_menu.highlighted_item);
    }

    SetKeyHandler(wgui_two_line_level_select_volume_move_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_two_line_level_select_volume_move_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_complete_two_line_level_select
 * DESCRIPTION
 *  This function is called when the user moves out from the current volume select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_complete_two_line_level_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    gui_scrolling_text_stop(&wgui_two_line_scroll_text);

    if (two_line_level_select_menuitem.two_line_select_complete)
    {
        two_line_level_select_menuitem.two_line_select_complete(
                                        MMI_fixed_list_menu.highlighted_item,
                                        two_line_level_select_menuitem.current_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_initialise_and_set_two_line_level_select_callbacks
 * DESCRIPTION
 *  This function is called to set the callbacks for the current volume select.
 * PARAMETERS
 *  no_of_items                 [IN]        number of items
 *  get_data_callback           [IN]        get menu item callback
 *  default_value_callback      [IN]        callback to set default values
 *  complete_callback           [IN]        callback to remove highlight
 * RETURNS
 *  void
 *****************************************************************************/
void gui_initialise_and_set_two_line_level_select_callbacks(
        S32 no_of_items,
        wgui_two_line_get_level_select_data_callback get_data_callback,
        wgui_two_line_menuitem_get_default_callback default_value_callback,
        wgui_two_line_menuitem_complete_callback complete_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    two_line_level_select_menuitem.width = 0;
    two_line_level_select_menuitem.height = 0;
    two_line_level_select_menuitem.current_item = 0;
    two_line_level_select_menuitem.no_of_items = no_of_items;
    two_line_level_select_menuitem.two_line_select_get_data = get_data_callback;
    two_line_level_select_menuitem.two_line_select_complete = complete_callback;
    two_line_level_select_menuitem.two_line_default_value = default_value_callback;
    gui_show_two_line_menuitem_part = gui_show_two_line_inline_level_select;
    gui_move_two_line_menuitem_part = wgui_move_and_set_keyhandlers_two_line_level_select;
    gui_resize_two_line_menuitem_part = wgui_resize_two_line_two_line_level_select;
    gui_reset_current_two_line_menuitem_data = wgui_complete_two_line_level_select;
    gui_reset_two_line = wgui_two_line_reset_all_pointers;
}


/*****************************************************************************
 * FUNCTION
 *  reset_fixed_icontext_menuitem_type
 * DESCRIPTION
 *  Set default two-line menu item callback fucntions.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_fixed_icontext_menuitem_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&wgui_two_line_scroll_text);
    gui_get_two_line_menuitem_height = UI_dummy_get_two_line_menuitem_height;
    gui_set_current_two_line_menuitem_data = UI_dummy_set_current_two_line_menuitem_data;
    gui_reset_current_two_line_menuitem_data = UI_dummy_reset_current_two_line_menuitem_data;
    gui_two_line_toggle_thumbnail_direction = UI_dummy_function;
    gui_two_line_get_thumbnail_flags = UI_dummy_two_line_get_thumbnail_flags;
}

// TODO: add symbol name prefixes and comments
static wgui_get_display_style get_current_menu_item_displaystyle = NULL;
static wgui_two_line_menuitem_struct current_menu_item_properties;
static wgui_get_two_line_menu_item_properties get_current_menu_item_properties = NULL;


/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_reset_all_pointers
 * DESCRIPTION
 *  Reset pointers related to two line function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_two_line_reset_all_pointers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_set_pfn_to_get_display_style(NULL);
    wgui_set_pfn_to_get_current_menu_item_properties(NULL);
    gui_reset_two_line = UI_dummy_function;
    two_line_level_select_menuitem.two_line_select_complete = NULL;
    two_line_horizontal_select_menuitem.two_line_select_complete = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_get_thumbnail_flags
 * DESCRIPTION
 *  Get the thumbnail flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current thumbnail flag.
 *****************************************************************************/
U8 wgui_two_line_get_thumbnail_flags(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return current_menu_item_properties.image_flags;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_toggle_thumbnail_direction
 * DESCRIPTION
 *  Toggle the thumbnail direction.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_two_line_toggle_thumbnail_direction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_menu_item_properties.image_flags ^= UI_TWO_LINE_TOGGLE_THUMBNAIL_DIRECTION_MASK;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_pfn_to_get_display_style
 * DESCRIPTION
 *  Set the callback function to get current menu item display style.
 * PARAMETERS
 *  pfn     [IN]        get display style callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_pfn_to_get_display_style(wgui_get_display_style pfn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_current_menu_item_displaystyle = pfn;
    if (pfn)
    {
        /* Unset in normal_fixed_list() */
        // MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;
        gui_get_two_line_menuitem_height = get_two_line_menuitem_height;
        gui_add_cleanup_hook(two_line_menuitem_cleanup_function);//053006 2 line Calvin
    }
    else
    {
        gui_get_two_line_menuitem_height = UI_dummy_get_two_line_menuitem_height;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_pfn_to_get_current_menu_item_properties
 * DESCRIPTION
 *  Set the callback function to get current menu item property.
 * PARAMETERS
 *  pfn     [IN]        callback to get the two-line item property
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_pfn_to_get_current_menu_item_properties(wgui_get_two_line_menu_item_properties pfn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_current_menu_item_properties = pfn;
}


/*****************************************************************************
 * FUNCTION
 *  set_current_two_line_menuitem_data
 * DESCRIPTION
 *  Check if two line  horizontal select or level and sets the data for a particular
 *  menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_two_line_menuitem_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_current_menu_item_displaystyle)
    {
        style = get_current_menu_item_displaystyle(MMI_fixed_list_menu.highlighted_item);
    }
    else
    {
        return;
    }

    switch (style)
    {
        case TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT:
            get_current_menu_item_properties(MMI_fixed_list_menu.highlighted_item, &current_menu_item_properties);
            wgui_initialise_and_set_two_line_horizontal_select_callbacks(
                current_menu_item_properties.num_of_items,
                (wgui_two_line_get_horizontal_select_data_callback) current_menu_item_properties. two_line_data_callback. get_data_for_horizontal_select,
                (wgui_two_line_menuitem_get_default_callback) current_menu_item_properties. defualt_value_callback,
                (wgui_two_line_menuitem_complete_callback) current_menu_item_properties. complete_callback);
            break;
        case TWO_LINE_MENUITEM_STYLE_DISPLAY_LEVEL_SELECT:
            get_current_menu_item_properties(MMI_fixed_list_menu.highlighted_item, &current_menu_item_properties);
            gui_initialise_and_set_two_line_level_select_callbacks(
                current_menu_item_properties.num_of_items,
                (wgui_two_line_get_level_select_data_callback) current_menu_item_properties.two_line_data_callback. get_data_for_level_select,
                (wgui_two_line_menuitem_get_default_callback) current_menu_item_properties.defualt_value_callback,
                (wgui_two_line_menuitem_complete_callback) current_menu_item_properties.complete_callback);
            break;

        default:
            break;
    }
}

#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 


#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)

/*****************************************************************************
 * FUNCTION
 *  two_line_scrolling_text_timer_handler
 * DESCRIPTION
 *  Scrolling handler for two line select text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void two_line_scrolling_text_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&wgui_two_line_scroll_text);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_scrolling_text_draw_two_line_background
 * DESCRIPTION
 *  Draw the two line select text background.
 * PARAMETERS
 *  x1      [IN]        x1
 *  y1      [IN]        y1
 *  x2      [IN]        x2
 *  y2      [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_scrolling_text_draw_two_line_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_two_line_background(x1, y1, x2, y2);
}

#endif /* (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__) */ 


#if defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__

/*****************************************************************************
 * FUNCTION
 *  wgui_initialise_and_set_two_line_horizontal_select_callbacks
 * DESCRIPTION
 *  Initialize the two line horizontal select.
 * PARAMETERS
 *  no_of_items                 [IN]        number of items
 *  get_data_callback           [IN]        get menu item callback
 *  default_value_callback      [IN]        callback to set default values
 *  complete_callback           [IN]        callback to remove highlight
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_initialise_and_set_two_line_horizontal_select_callbacks(
        S32 no_of_items,
        wgui_two_line_get_horizontal_select_data_callback get_data_callback,
        wgui_two_line_menuitem_get_default_callback default_value_callback,
        wgui_two_line_menuitem_complete_callback complete_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    two_line_horizontal_select_menuitem.width = 0;
    two_line_horizontal_select_menuitem.height = 0;
    two_line_horizontal_select_menuitem.current_item = 0;
    two_line_horizontal_select_menuitem.no_of_items = no_of_items;
    two_line_horizontal_select_menuitem.two_line_select_get_data = get_data_callback;
    two_line_horizontal_select_menuitem.two_line_select_complete = complete_callback;
    two_line_horizontal_select_menuitem.two_line_default_value = default_value_callback;
    gui_show_two_line_menuitem_part = wgui_show_two_line_horizontal_select;
    gui_move_two_line_menuitem_part = wgui_move_and_set_keyhandlers_two_line_horizontal_select;
    gui_resize_two_line_menuitem_part = wgui_resize_two_line_horizontal_select;
    gui_reset_current_two_line_menuitem_data = wgui_complete_two_line_horizontal_select;
    gui_reset_two_line = wgui_two_line_reset_all_pointers;
    gui_two_line_toggle_thumbnail_direction = wgui_two_line_toggle_thumbnail_direction;
    gui_two_line_get_thumbnail_flags = wgui_two_line_get_thumbnail_flags;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_and_set_keyhandlers_two_line_horizontal_select
 * DESCRIPTION
 *  Move the two line inline select and set its key handlers.
 * PARAMETERS
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_and_set_keyhandlers_two_line_horizontal_select(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    two_line_horizontal_select_menuitem.x = x;
    two_line_horizontal_select_menuitem.y = y;
    if (two_line_horizontal_select_menuitem.two_line_default_value)
    {
        two_line_horizontal_select_menuitem.current_item = two_line_horizontal_select_menuitem.two_line_default_value(MMI_fixed_list_menu.highlighted_item);
    }
    if (two_line_horizontal_select_menuitem.no_of_items > 1)
    {
        SetKeyHandler(wgui_two_line_horizontal_select_move_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_two_line_horizontal_select_move_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_two_line_horizontal_select
 * DESCRIPTION
 *  Resize the two line inline select menu item.
 * PARAMETERS
 *  width       [IN]        new width
 *  height      [IN]        new height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_two_line_horizontal_select(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    two_line_horizontal_select_menuitem.width = width;
    two_line_horizontal_select_menuitem.height = height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_two_line_background
 * DESCRIPTION
 *  Show the two line background.
 * PARAMETERS
 *  x1       [IN]   x coordinate of the top-left point
 *  y1       [IN]   y coordinate of the top-left point
 *  x2       [IN]   x coordinate of the bottom-right point
 *  y2       [IN]   y coordinate of the bottom-right point
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_two_line_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_two_line_background(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_two_line_horizontal_select
 * DESCRIPTION
 *  Show the two line horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_two_line_horizontal_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    S32 text_x;
    S32 text_end_x;
    S32 sw, sh;
    S32 text_y;
    PU8 image_data;
    PU8 left_arrow;
    PU8 right_arrow;
    S32 width, height;
    S32 lx, ly, rx, ry;
    S32 ix, iy;
    wgui_thumbnail_image_union thumbnail;
    U8 thumbnail_area_width, thumbnail_area_height;
    S32 thumb_x = 0, thumb_y = 0, thumb_width = 0, thumb_height = 0;
    S32 width_for_horizontal_select;
    S8 ret_val_resize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define THUMBNAIL_GAP_FROM_SIDES 2

    if (!two_line_horizontal_select_menuitem.two_line_select_get_data)
    {
        return;
    }
    if (!two_line_horizontal_select_menuitem.
        two_line_select_get_data(
            MMI_fixed_list_menu.highlighted_item,
            two_line_horizontal_select_menuitem.current_item,
            (UI_string_type) two_line_string_data,
            &image_data,
            &thumbnail))
    {
        return;
    }
    if (current_menu_item_properties.image_flags)
    {
        thumbnail_area_width = thumbnail_area_height = two_line_horizontal_select_menuitem.height << 1;
        width_for_horizontal_select = two_line_horizontal_select_menuitem.width - thumbnail_area_width;

        if (current_menu_item_properties.image_flags & UI_TWO_LINE_MENUITEM_LEFT_ALIGN_THUMBNAIL)
        {
            x1 = two_line_horizontal_select_menuitem.x + thumbnail_area_width;
            y1 = two_line_horizontal_select_menuitem.y;
            x2 = x1 + width_for_horizontal_select;
            y2 = y1 + two_line_horizontal_select_menuitem.height - 1;
            thumb_x = two_line_horizontal_select_menuitem.x;
            thumb_y = two_line_horizontal_select_menuitem.y - two_line_horizontal_select_menuitem.height + 1;
            thumb_height = thumb_width = thumbnail_area_width - (THUMBNAIL_GAP_FROM_SIDES << 1);

        }
        else if (current_menu_item_properties.image_flags & UI_TWO_LINE_MENUITEM_RIGHT_ALIGN_THUMBNAIL)
        {
            x1 = two_line_horizontal_select_menuitem.x;
            y1 = two_line_horizontal_select_menuitem.y;
            x2 = x1 + width_for_horizontal_select;
            y2 = y1 + two_line_horizontal_select_menuitem.height - 1;
            thumb_x = x2 + (THUMBNAIL_GAP_FROM_SIDES << 1);
            thumb_y = two_line_horizontal_select_menuitem.y - two_line_horizontal_select_menuitem.height + 1;
            /* thumb_width=thumbnail_area_width; */
            thumb_width = thumb_height = thumbnail_area_height - (THUMBNAIL_GAP_FROM_SIDES << 1);
        }
    }
    else
    {
        x1 = two_line_horizontal_select_menuitem.x;
        y1 = two_line_horizontal_select_menuitem.y;
        x2 = x1 + two_line_horizontal_select_menuitem.width - 1;
        y2 = y1 + two_line_horizontal_select_menuitem.height - 1;
        width_for_horizontal_select = two_line_horizontal_select_menuitem.width;
    }

    left_arrow = get_image(LEFT_RED_ARROW);
    right_arrow = get_image(RIGHT_RED_ARROW);
    gui_measure_image(left_arrow, &width, &height);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_menuitem_left_arrow.width = width;
    mmi_menuitem_left_arrow.height = height;
#endif /* __MMI_TOUCH_SCREEN__ */
    lx = 2;
    text_x = lx + width + 2;
    ly = (two_line_horizontal_select_menuitem.height >> 1) - (height >> 1);
    gui_measure_image(right_arrow, &width, &height);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_menuitem_right_arrow.width = width;
    mmi_menuitem_right_arrow.height = height;
#endif /* __MMI_TOUCH_SCREEN__ */
    rx = width_for_horizontal_select - width - 2;
    text_end_x = rx;
    ry = (two_line_horizontal_select_menuitem.height >> 1) - (height >> 1);
    gui_measure_image(right_arrow, &width, &height);
    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(x1, y1, x2, y2);

    wgui_show_two_line_background(x1, y1, x2, y2);

    if (two_line_horizontal_select_menuitem.no_of_items > 1)
    {
        gui_show_transparent_image(x1 + lx, y1 + ly, left_arrow, 0);
        gui_show_transparent_image(x1 + rx, y1 + ry, right_arrow, 0);
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_menuitem_left_arrow.x = x1 + lx;
        mmi_menuitem_left_arrow.y = y1 + ly;
        mmi_menuitem_right_arrow.x = x1 + rx;
        mmi_menuitem_right_arrow.y = y1 + ry;
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
    else
    {
        text_x = lx = width = 0;
        text_end_x = rx = width_for_horizontal_select - 2;
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_menuitem_left_arrow.x = 0;
        mmi_menuitem_left_arrow.y = 0;
        mmi_menuitem_left_arrow.width = 0;
        mmi_menuitem_left_arrow.height = 0;
        mmi_menuitem_right_arrow.x = 0;
        mmi_menuitem_right_arrow.x = 0;
        mmi_menuitem_right_arrow.x = 0;
        mmi_menuitem_right_arrow.x = 0;
    #endif /* __MMI_TOUCH_SCREEN__ */
    }

    if (image_data)
    {
        ix = lx + width + 2;
        gui_measure_image(image_data, &width, &height);
        iy = (two_line_horizontal_select_menuitem.height >> 1) - (height >> 1);
        if (!r2lMMIFlag)
        {
            text_x = ix + width + 4;
            gui_show_transparent_image(x1 + ix, y1 + iy, image_data, 0);
        }
        else
        {
            gui_show_transparent_image(x1 + text_end_x - width, y1 + iy, image_data, 0);
            text_end_x = text_end_x - width - 4;
        }
    }
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_font(MMI_fixed_icontext_menuitem.text_font);
    gui_measure_string((UI_string_type) two_line_string_data, &sw, &sh);
    text_y = (two_line_horizontal_select_menuitem.height >> 1) - (sh >> 1);
    gui_set_text_color(MMI_fixed_icontext_menuitem.focussed_text_color);
    if (sw < text_end_x - text_x - 1)
    {
        if (!r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + text_x, y1 + text_y);
        }
        else
        {
            if (HaveThaiCharacter((UI_string_type) two_line_string_data))
            {
                gui_move_text_cursor(x1 + text_end_x - sw, y1 + text_y);
            }
            else
            {
                gui_move_text_cursor(x1 + text_end_x, y1 + text_y);
            }
        }
        gui_print_text((UI_string_type) two_line_string_data);
    }
    else
    {
        gui_create_scrolling_text(
            &wgui_two_line_scroll_text,
            x1 + text_x,
            y1 + text_y,
            text_end_x - text_x - 1,
            sh + 1,
            (UI_string_type) two_line_string_data,
            two_line_scrolling_text_timer_handler,
            wgui_scrolling_text_draw_two_line_background,
            MMI_fixed_icontext_menuitem.focussed_text_color,
            MMI_fixed_icontext_menuitem.focussed_text_color);
        gui_show_scrolling_text(&wgui_two_line_scroll_text);
    }
    gui_pop_text_clip();
    gui_pop_clip();

    if (current_menu_item_properties.image_flags & UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_ID)
    {
        PU8 thumbmeasure;
        S32 tw, th;

        gui_push_clip();
        gui_set_clip(thumb_x - THUMBNAIL_GAP_FROM_SIDES, thumb_y, thumb_x + thumb_width, thumb_y + thumb_height);
        thumbmeasure = (PU8) GetImage(thumbnail.id);
        gui_measure_image(thumbmeasure, &tw, &th);
        if (tw > thumb_width && th > thumb_height)
        {
            ret_val_resize = gdi_image_draw_resized_id(
                                thumb_x,
                                thumb_y + THUMBNAIL_GAP_FROM_SIDES,
                                thumb_width,
                                thumb_height,
                                thumbnail.id);
        }
        else
        {
            S32 start_x, start_y;

            start_x = thumb_x + ((thumb_width - tw) >> 1);
            start_y = thumb_y + ((thumb_height - th) >> 1);
            ret_val_resize = gdi_image_draw_resized_id(start_x, start_y + THUMBNAIL_GAP_FROM_SIDES, tw, th, thumbnail.id);
        }
        gui_pop_clip();
    }
    else if (current_menu_item_properties.image_flags & UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_FILE)
    {
        S32 tw, th;

        gui_push_clip();
        gui_set_clip(thumb_x - THUMBNAIL_GAP_FROM_SIDES, thumb_y, thumb_x + thumb_width, thumb_y + thumb_height);
        gdi_image_get_dimension_file(thumbnail.path, &tw, &th);
        if (tw > thumb_width && th > thumb_height)
        {
            ret_val_resize = gdi_image_draw_resized_file(
                                thumb_x,
                                thumb_y + THUMBNAIL_GAP_FROM_SIDES,
                                thumb_width,
                                thumb_height,
                                thumbnail.path);
        }
        else
        {
            S32 start_x, start_y;

            start_x = thumb_x + ((thumb_width - tw) >> 1);
            start_y = thumb_y + ((thumb_height - th) >> 1);
            ret_val_resize = gdi_image_draw_resized_file(start_x, start_y + THUMBNAIL_GAP_FROM_SIDES, tw, th, thumbnail.path);

        }
        gui_pop_clip();
    }
    if (ret_val_resize != GDI_SUCCEED)
    {
        /* Draw wire frame */
        gui_draw_vertical_line(
            thumb_y + THUMBNAIL_GAP_FROM_SIDES,
            thumb_y + thumb_height,
            thumb_x,
            MMI_fixed_icontext_menuitem.normal_text_color);
        gui_draw_vertical_line(
            thumb_y + THUMBNAIL_GAP_FROM_SIDES,
            thumb_y + thumb_height,
            thumb_x - THUMBNAIL_GAP_FROM_SIDES + thumb_width,
            MMI_fixed_icontext_menuitem.normal_text_color);
        gui_draw_horizontal_line(
            thumb_x,
            thumb_x - THUMBNAIL_GAP_FROM_SIDES + thumb_width,
            thumb_y + THUMBNAIL_GAP_FROM_SIDES,
            MMI_fixed_icontext_menuitem.normal_text_color);
        gui_draw_horizontal_line(
            thumb_x,
            thumb_x - THUMBNAIL_GAP_FROM_SIDES + thumb_width,
            thumb_y + thumb_height,
            MMI_fixed_icontext_menuitem.normal_text_color);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_complete_two_line_horizontal_select
 * DESCRIPTION
 *  Remove highlight function of the two-line horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_complete_two_line_horizontal_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    gui_scrolling_text_stop(&wgui_two_line_scroll_text);
    if (two_line_horizontal_select_menuitem.two_line_select_complete)
    {
        two_line_horizontal_select_menuitem.two_line_select_complete(
                                                MMI_fixed_list_menu.highlighted_item,
                                                two_line_horizontal_select_menuitem.current_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_horizontal_select_move_next_item
 * DESCRIPTION
 *  This is called when users presses right arraw key on horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_two_line_horizontal_select_move_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&wgui_two_line_scroll_text);

    if (two_line_horizontal_select_menuitem.current_item == two_line_horizontal_select_menuitem.no_of_items - 1)
    {
        two_line_horizontal_select_menuitem.current_item = 0;
    }
    else
    {
        two_line_horizontal_select_menuitem.current_item++;
    }
    wgui_show_two_line_horizontal_select();
    gui_BLT_double_buffer(
        two_line_horizontal_select_menuitem.x,
        two_line_horizontal_select_menuitem.y,
        two_line_horizontal_select_menuitem.x + two_line_horizontal_select_menuitem.width - 1,
        two_line_horizontal_select_menuitem.y + two_line_horizontal_select_menuitem.height - 1);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_horizontal_select_move_previous_item
 * DESCRIPTION
 *  This is called when users presses left arraw key on horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_two_line_horizontal_select_move_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&wgui_two_line_scroll_text);
    if (two_line_horizontal_select_menuitem.current_item == 0)
    {
        two_line_horizontal_select_menuitem.current_item = two_line_horizontal_select_menuitem.no_of_items - 1;
    }
    else
    {
        two_line_horizontal_select_menuitem.current_item--;
    }

    wgui_show_two_line_horizontal_select();
    gui_BLT_double_buffer(
        two_line_horizontal_select_menuitem.x,
        two_line_horizontal_select_menuitem.y,
        two_line_horizontal_select_menuitem.x + two_line_horizontal_select_menuitem.width - 1,
        two_line_horizontal_select_menuitem.y + two_line_horizontal_select_menuitem.height - 1);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  get_two_line_menuitem_height
 * DESCRIPTION
 *  Callback function to check if the the current item is two line.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 1 for two line; otherwise, 0 for single line.
 *****************************************************************************/
pBOOL get_two_line_menuitem_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_current_menu_item_displaystyle && get_current_menu_item_displaystyle(MMI_fixed_list_menu.highlighted_item))
    {
        return 1;
    }
    
    return 0;
}

two_line_dynamic_menuitem_style two_line_display_asyncdynamic_menuitem_callback;


/*****************************************************************************
 * FUNCTION
 *  get_two_line_asyncdynamic_menuitem_height
 * DESCRIPTION
 *  Callback function to check if the the current item is two line for the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 1 for two line; otherwise, 0 for single line.
 *****************************************************************************/
pBOOL get_two_line_asyncdynamic_menuitem_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index, menuitem_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_fixed_list_menuitem_display_index == -1)
    {
        index = MMI_fixed_list_menu.highlighted_item;
        menuitem_index = (index - asyncdynamic_item_buffer.head_item_index +
                          asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
        if (two_line_display_asyncdynamic_menuitem_callback)
        {
            if (two_line_display_asyncdynamic_menuitem_callback(index, menuitem_index))
            {
                gui_get_two_line_menuitem_height = get_two_line_asyncdynamic_menuitem_height;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_two_line_display_for_asyncdynamic_menus
 * DESCRIPTION
 *  Set the callback to get display style in case of asyncdynamic menus.
 * PARAMETERS
 *  callback        [IN]        get display style callback function
 * RETURNS
 *  void
 *****************************************************************************/
void set_two_line_display_for_asyncdynamic_menus(two_line_dynamic_menuitem_style callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    two_line_display_asyncdynamic_menuitem_callback = callback;
    gui_get_two_line_menuitem_height = get_two_line_asyncdynamic_menuitem_height;
}

two_line_dynamic_menuitem_style two_line_display_dynamic_menuitem_callback;


/*****************************************************************************
 * FUNCTION
 *  get_two_line_dynamic_menuitem_height
 * DESCRIPTION
 *  Callback function to check if the the current item is two line for the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 1 for two line; otherwise, 0 for single line.
 *****************************************************************************/
pBOOL get_two_line_dynamic_menuitem_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index, menuitem_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_fixed_list_menuitem_display_index == -1)
    {
        index = MMI_fixed_list_menu.highlighted_item;
        menuitem_index = (index - dynamic_item_buffer.head_item_index +
                          dynamic_item_buffer.head) & MASK_DYNAMIC_ITEMS_BUFF;
        if (two_line_display_dynamic_menuitem_callback)
        {
            if (two_line_display_dynamic_menuitem_callback(index, menuitem_index))
            {
                gui_get_two_line_menuitem_height = get_two_line_dynamic_menuitem_height;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_two_line_display_for_dynamic_menus
 * DESCRIPTION
 *  Set the callback to get display style in case of dynamic menus.
 * PARAMETERS
 *  callback        [IN]        get display style callback function
 * RETURNS
 *  void
 *****************************************************************************/
void set_two_line_display_for_dynamic_menus(two_line_dynamic_menuitem_style callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    two_line_display_dynamic_menuitem_callback = callback;
    gui_get_two_line_menuitem_height = get_two_line_dynamic_menuitem_height;
}

#endif /* defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 


#ifdef __MMI_UI_HINTS_IN_MENUITEM__

/*****************************************************************************
 * FUNCTION
 *  gui_disable_scroller_for_hints
 * DESCRIPTION
 *  Disable scrolling for hints.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_disable_scroller_for_hints(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&wgui_two_line_scroll_text);
    gui_reset_current_two_line_menuitem_data = UI_dummy_reset_current_two_line_menuitem_data;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_two_line_hint_part
 * DESCRIPTION
 *  Show the two line hint.
 * PARAMETERS
 *  hint_x1         [IN]        x1
 *  hint_x2         [IN]        x2
 *  hint_y1         [IN]        y1
 *  hint_y2         [IN]        y2
 *  _hint_text      [IN]        hint text
 *  flags           [IN]        menu item flag
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_two_line_hint_part(
        S32 hint_x1,
        S32 hint_x2,
        S32 hint_y1,
        S32 hint_y2,
        UI_string_type _hint_text,
        U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_current_two_line_menuitem_data = gui_disable_scroller_for_hints;
    gui_push_text_clip();
    gui_set_text_clip(hint_x1, hint_y1, hint_x2, hint_y2);

    gui_set_font(MMI_fixed_icontext_menuitem.text_font);
    gui_measure_string(_hint_text, &sw, &sh);

    hint_y1 += ((hint_y2 - hint_y1) >> 1) - (sh >> 1);  /* Center Vertically */
    /* gui_set_text_color(MMI_fixed_icontext_menuitem.focussed_text_color); */
    if (sw < hint_x2 - hint_x1 - 1 || (!(flags & UI_MENUITEM_STATE_FOCUSSED)))
    {
        if (!r2lMMIFlag)
        {
            gui_move_text_cursor(hint_x1, hint_y1);
        }
        else
        {
            gui_move_text_cursor(hint_x2, hint_y1);

        }
        gui_print_text((UI_string_type) _hint_text);
    }
    else
    {
        gui_create_scrolling_text(
            &wgui_two_line_scroll_text,
            hint_x1,
            hint_y1,
            hint_x2 - hint_x1,
            sh + 1,
            (UI_string_type) _hint_text,
            two_line_scrolling_text_timer_handler,
            wgui_scrolling_text_draw_two_line_background,
            MMI_fixed_icontext_menuitem.focussed_text_color,
            MMI_fixed_icontext_menuitem.focussed_text_color);
        gui_show_scrolling_text(&wgui_two_line_scroll_text);
    }
    gui_pop_text_clip();

}

#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 


#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
static BOOL wgui_two_line_disable_complete_callback_flag = TRUE;

/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_disable_complete_callback
 * DESCRIPTION
 *  Disable two line remove highlight callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_two_line_disable_complete_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_two_line_disable_complete_callback_flag = FALSE;
}

#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 


#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)

/*****************************************************************************
 * FUNCTION
 *  wgui_two_line_stop_scroller
 * DESCRIPTION
 *  Stop the scrolling for the two-line.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_two_line_stop_scroller(void)
{
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wgui_two_line_disable_complete_callback_flag)
    {
        wgui_two_line_disable_complete_callback_flag = TRUE;
        return;
    }
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 

    gui_scrolling_text_stop(&wgui_two_line_scroll_text);

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    if (two_line_level_select_menuitem.two_line_select_complete)
    {
        two_line_level_select_menuitem.two_line_select_complete(
                                        MMI_fixed_list_menu.highlighted_item,
                                        two_line_level_select_menuitem.current_item);
    }
    if (two_line_horizontal_select_menuitem.two_line_select_complete)
    {
        two_line_horizontal_select_menuitem.two_line_select_complete(
                                                MMI_fixed_list_menu.highlighted_item,
                                                two_line_horizontal_select_menuitem.current_item);
    }
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 
    gui_two_line_scroller_stop();
}

#endif /* (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__) */ 


#if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) && defined(__MMI_TOUCH_SCREEN__)

// TODO: This function should not be called from underlying gui layer.

/*****************************************************************************
 * FUNCTION
 *  mmi_two_line_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the two-line.
 * PARAMETERS
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  pen_event       [IN]        pen event type
 *  menuitem_event  [OUT]       result pen event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_two_line_translate_pen_event(S32 x, S32 y, mmi_pen_event_type_enum pen_event,gui_list_pen_enum *menuitem_event)
{
    if (PEN_CHECK_BOUND(
            x,
            y,
            mmi_menuitem_left_arrow.x,
            mmi_menuitem_left_arrow.y,
            mmi_menuitem_left_arrow.width,
            mmi_menuitem_left_arrow.height))
    {
        *menuitem_event = GUI_LIST_PEN_TWO_LINE_PREVIOUS;
    }
    else if (PEN_CHECK_BOUND(
                x,
                y,
                mmi_menuitem_right_arrow.x,
                mmi_menuitem_right_arrow.y,
                mmi_menuitem_right_arrow.width,
                mmi_menuitem_right_arrow.height))
    {
    	    *menuitem_event = GUI_LIST_PEN_TWO_LINE_NEXT;
    }
}

#endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) && defined(__MMI_TOUCH_SCREEN__) */


