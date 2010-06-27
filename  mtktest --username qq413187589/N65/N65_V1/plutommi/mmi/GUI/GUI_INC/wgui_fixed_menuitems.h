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

/*****************************************************************************
 * Filename:
 * ---------
 *  wgui_fixed_menu_items.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  fixed menu item external interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_FIXED_MENUITEMS_H__
#define __WGUI_FIXED_MENUITEMS_H__
 
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui.h"
#include "wgui_fixed_menus.h"
#include "gui_themes.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Limit the number of menu items by MAX_SUB_MENUS without wasting RAM. */
#define MAX_FIXED_TEXT_MENU_ITEMS           LIMIT_MENU_ITEM_NUMBER(100)
#define MAX_FIXED_ICONTEXT_MENU_ITEMS       LIMIT_MENU_ITEM_NUMBER(90)
#define MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS  LIMIT_MENU_ITEM_NUMBER(72)
#define MAX_FIXED_TWOSTATE_MENU_ITEMS       LIMIT_MENU_ITEM_NUMBER(45)

#define TWO_LINE_MENUITEM_STYLE_DISPLAY_LEVEL_SELECT        1
#define TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT   2

#define UI_TWO_LINE_MENUITEM_NO_THUMBNAIL           0x00
#define UI_TWO_LINE_MENUITEM_LEFT_ALIGN_THUMBNAIL   0x01
#define UI_TWO_LINE_MENUITEM_RIGHT_ALIGN_THUMBNAIL  0x02
#define UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_FILE      0x04
#define UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_ID        0x08
#define UI_TWO_LINE_TOGGLE_THUMBNAIL_DIRECTION_MASK 0x03

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct _integrated_menuitem
{
    union
    {
        fixed_twostate_menuitem_type fixedtwoStatetype[MAX_FIXED_TWOSTATE_MENU_ITEMS];
        fixed_icontext_list_menuitem_type fixedIconListtype[MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS];
        fixed_icontext_menuitem_type fixedIconTexttype[MAX_FIXED_ICONTEXT_MENU_ITEMS];
        fixed_text_menuitem_type fixedTexttype[MAX_FIXED_TEXT_MENU_ITEMS];
    } menuUnion;
} integrated_menuitem;


typedef union _thumbnail_image
{
    S8 *path;
    U16 id;
} wgui_thumbnail_image_union;

typedef S32 (*wgui_two_line_menuitem_get_default_callback)(S32 menuitem_index);
typedef pBOOL (*wgui_two_line_get_level_select_data_callback)(S32 menuitem_index, S32 item_index);
typedef pBOOL (*wgui_two_line_get_horizontal_select_data_callback)(S32 menuitem_index, S32 item_index,
                                                                   UI_string_type str_buff, PU8 *img_buff_p,
                                                                   wgui_thumbnail_image_union *thumbnail);
typedef void (*wgui_two_line_menuitem_complete_callback)(S32 menuitem_index, S32 selected_index);

typedef union _wgui_two_line_menuitem_data_union
{
    wgui_two_line_get_level_select_data_callback get_data_for_level_select;
    wgui_two_line_get_horizontal_select_data_callback get_data_for_horizontal_select;
} wgui_two_line_menuitem_data_union;

typedef struct _wgui_two_line_menuitem_struct
{
    U8 image_flags;
    S32 num_of_items;
    wgui_two_line_menuitem_get_default_callback defualt_value_callback;
    wgui_two_line_menuitem_complete_callback complete_callback;
    wgui_two_line_menuitem_data_union two_line_data_callback;
} wgui_two_line_menuitem_struct;

typedef void (*wgui_get_two_line_menu_item_properties)(int index,
                                                       wgui_two_line_menuitem_struct *
                                                       current_menuitem_properties);
typedef U8 (*wgui_get_display_style)(S32 absolute_index);
typedef pBOOL (*two_line_dynamic_menuitem_style)(S32 item_index, S32 menuitem_index);


typedef struct _wgui_horizontal_select_menuitem_struct
{
    S32 x;
    S32 y;
    S32 width;
    S32 height;
    S32 current_item;
    S32 no_of_items;
    wgui_two_line_get_horizontal_select_data_callback two_line_select_get_data;
    wgui_two_line_menuitem_complete_callback two_line_select_complete;
    wgui_two_line_menuitem_get_default_callback two_line_default_value;
} wgui_horizontal_select_menuitem_struct;


typedef struct _wgui_level_select_menutitem_struct
{
    S32 x;
    S32 y;
    S32 width;
    S32 height;
    S32 current_item;
    S32 no_of_items;
    wgui_two_line_get_level_select_data_callback two_line_select_get_data;
    wgui_two_line_menuitem_complete_callback two_line_select_complete;
    wgui_two_line_menuitem_get_default_callback two_line_default_value;
} wgui_level_select_menutitem_struct;

typedef struct 
{
    S32 x;
    S32 y;
    S32 width;
    S32 height;
} wgui_two_line_arrow_struct;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/ 
extern fixed_text_menuitem MMI_fixed_text_menuitem;
extern fixed_text_menuitem_type *MMI_fixed_text_menuitems;
extern S32 *fixed_text_menu_n_items;
extern void *MMI_fixed_menuitem_pointers[];


extern fixed_icontext_menuitem MMI_fixed_icontext_menuitem;
extern fixed_icontext_menuitem_type *MMI_fixed_icontext_menuitems;
extern S32 *fixed_icontext_menu_n_items;


extern fixed_icontext_list_menuitem MMI_fixed_icontext_list_menuitem;
extern fixed_icontext_list_menuitem_type *MMI_fixed_icontext_list_menuitems;
extern S32 *fixed_icontext_list_menu_n_items;


extern fixed_twostate_menuitem MMI_fixed_twostate_menuitem;
extern fixed_twostate_menuitem_type *MMI_fixed_twostate_menuitems;
extern S32 *fixed_twostate_menu_n_items;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/ 
/* 
 * fixed text menuitem  
 */
extern void (*wgui_text_menuitem_reset_scrolling)(void);
extern void (*wgui_text_menuitem_restart_scrolling)(void);

extern U8 get_menu_item_height(void);
extern void fixed_text_menuitem_apply_current_theme(void);
extern void fixed_text_menuitem_apply_theme(UI_fixed_text_menuitem_theme *t);
extern void create_fixed_text_menuitems(void);
extern void resize_fixed_text_menuitems(S32 width, S32 height);
extern void associate_fixed_text_list(void);
extern void associate_fixed_text_matrix(void);
extern void add_fixed_text_item(UI_string_type s);
extern void add_location_fixed_text_item(S32 index, UI_string_type s);
extern void remove_fixed_text_item(S32 index);
extern void add_fixed_text_items(S32 n_items, UI_string_type *s);
extern void associate_fixed_multirow_list_list(S32);
extern void set_single_row_iconlist_fixed_list(void);
extern S32 fixed_matrix_auto_disable_scrollbar(void);
extern void set_fixed_text_positions(S32 tx, S32 ty);


/* 
 * fixed icontext menuitem 
 */
extern void fixed_icontext_menuitem_apply_current_theme(void);
extern void fixed_icontext_menuitem_apply_theme(UI_fixed_icontext_menuitem_theme *t);
extern void create_fixed_icontext_menuitems(void);
extern void resize_fixed_icontext_menuitems(S32 width, S32 height);
extern void center_fixed_icontext_positions(U8 tx, U8 ty, U8 ix, U8 iy);
extern void set_fixed_icontext_positions(S32 tx, S32 ty, S32 ix, S32 iy);
extern void associate_fixed_icontext_list(void);
extern void associate_fixed_icontext_matrix(void);
extern void add_fixed_icontext_item(UI_string_type s, PU8 img);
extern void change_fixed_icontext_item(S32 index, UI_string_type s, PU8 img);
extern void add_location_fixed_icontext_item(S32 index, UI_string_type s, PU8 img);
extern void remove_fixed_icontext_item(S32 index);
extern void add_fixed_icontext_items(S32 n_items, UI_string_type *s, PU8 *img);

extern void wgui_menuitem_set_icontext_checkbox_position(S32 x_offset, S32 y_offset);
extern void wgui_menuitem_register_icontext_checkbox_callback(
                checkbox_clicked_funcptr_type clicked_cb, 
                checkbox_get_image_funcptr_type get_image_cb);


/* 
 * fixed icontext list menuitem 
 */
extern void fixed_icontext_list_menuitem_apply_current_theme(void);
extern void fixed_icontext_list_menuitem_apply_theme(UI_fixed_icontext_list_menuitem_theme *t);
extern void create_fixed_icontext_list_menuitems(S32 n_text_columns, S32 n_icon_columns);
void set_fixed_icontext_list_menuitems_post_display(void (*post_display_function)
                                                    (void *item, void *common_item_data, S32 x, S32 y));
extern void resize_fixed_icontext_list_menuitems(S32 width, S32 height);
extern void set_fixed_icontext_list_text_coordinates(S32 c, S32 x, S32 y, S32 width, S32 height);
extern void set_fixed_icontext_list_icon_coordinates(S32 c, S32 x, S32 y, S32 width, S32 height);
extern void associate_fixed_icontext_list_list(void);
extern void associate_fixed_icontext_list_matrix(void);
extern void add_fixed_icontext_list_item_text(S32 index, S32 c, UI_string_type s);
extern void add_fixed_icontext_list_item_icon(S32 index, S32 c, PU8 img);
extern void fixed_icontext_list_item_insert(S32 index);
extern void remove_fixed_icontext_list_item(S32 index);

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
extern void wgui_enable_hints_in_icontext_menuitem(void);
extern void wgui_enable_hint_highlight_in_icontext_menuitem(void);
extern void wgui_show_icon_only_highlight_in_icontext_menuitem(void);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 


/* 
 * fixed twostate menuitem 
 */
extern void fixed_twostate_menuitem_apply_current_theme(void);
extern void fixed_twostate_menuitem_apply_theme(UI_fixed_twostate_menuitem_theme *t);
extern void create_fixed_twostate_menuitems(PU8 ON_icon, PU8 OFF_icon);
extern void resize_fixed_twostate_menuitems(S32 width, S32 height);
extern void associate_fixed_twostate_list(void);
extern void associate_fixed_twostate_matrix(void);
extern void center_fixed_twostate_positions(U8 tx, U8 ty, U8 ix, U8 iy);
extern void set_fixed_twostate_positions(S32 tx, S32 ty, S32 ix, S32 iy);
extern void set_fixed_twostate_icons(PU8 ON_icon, PU8 OFF_icon);
extern void add_fixed_twostate_item(UI_string_type s);
extern void add_location_fixed_twostate_item(S32 index, UI_string_type s);
extern void remove_fixed_twostate_item(S32 index);
extern void add_fixed_twostate_items(S32 n_items, UI_string_type *s);
extern void select_fixed_twostate_item(S32 index);
extern void unselect_fixed_twostate_item(S32 index);
extern void toggle_fixed_twostate_item(S32 index);
extern U8 get_fixed_twostate_item_state(S32 index);

extern void remove_all_fixed_icontext_item(void);

extern UI_string_type get_item_text(S32 index);

extern void resize_fixed_icontext_menuitems_to_list_width(void);
extern void resize_fixed_text_menuitems_to_list_width(void);
extern void resize_fixed_icontext_list_menuitems_to_list_width(void);
extern void resize_fixed_twostate_menuitems_to_list_width(void);

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
extern void disable_fixed_icontext_menuitem_transparent_effect(void);
extern void enable_fixed_icontext_menuitem_transparent_effect(void);
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */  

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
extern U8 wgui_two_line_get_thumbnail_flags(void);
extern void wgui_two_line_toggle_thumbnail_direction(void);
extern void wgui_two_line_reset_all_pointers(void);
extern void wgui_set_pfn_to_get_current_menu_item_properties(wgui_get_two_line_menu_item_properties pfn);
extern void wgui_set_pfn_to_get_display_style(wgui_get_display_style pfn);
extern void reset_fixed_icontext_menuitem_type(void);
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 

#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)
extern void wgui_two_line_stop_scroller(void);
extern void wgui_two_line_disable_complete_callback(void);
extern void set_current_two_line_menuitem_data(void);
#endif /* (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__) */ 

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
extern void gui_show_two_line_hint_part(
                S32 hint_x1,
                S32 hint_x2,
                S32 hint_y1,
                S32 hint_y2,
                UI_string_type _hint_text,
                U32 flags);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
extern void wgui_initialise_and_set_two_line_horizontal_select_callbacks(
                S32 no_of_items,
                wgui_two_line_get_horizontal_select_data_callback get_data_callback,
                wgui_two_line_menuitem_get_default_callback default_value_callback,
                wgui_two_line_menuitem_complete_callback complete_callback);
extern void wgui_show_two_line_horizontal_select(void);
extern void wgui_complete_two_line_horizontal_select(void);
extern void wgui_two_line_horizontal_select_move_next_item(void);
extern void wgui_two_line_horizontal_select_move_previous_item(void);
extern void wgui_move_and_set_keyhandlers_two_line_horizontal_select(S32 x, S32 y);
extern void wgui_resize_two_line_horizontal_select(S32 width, S32 height);
extern pBOOL get_two_line_menuitem_height(void);
extern void set_two_line_display_for_dynamic_menus(two_line_dynamic_menuitem_style callback);
extern pBOOL get_two_line_dynamic_menuitem_height(void);
extern void set_two_line_display_for_asyncdynamic_menus(two_line_dynamic_menuitem_style callback);
extern pBOOL get_two_line_asyncdynamic_menuitem_height(void);

extern void wgui_show_two_line_background(S32 x1, S32 y1, S32 x2, S32 y2);

#ifdef __MMI_TOUCH_SCREEN__
extern void wgui_two_line_translate_pen_event(S32 x, S32 y, mmi_pen_event_type_enum pen_event, gui_list_pen_enum *menuitem_event);
#endif

#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 

#endif /* __WGUI_FIXED_MENUITEMS_H__ */ 

