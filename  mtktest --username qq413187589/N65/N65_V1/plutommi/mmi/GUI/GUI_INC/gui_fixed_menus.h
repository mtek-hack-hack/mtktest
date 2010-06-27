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
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Fixed-list menu - UI component
 *  1. The number of menu items stays unchanged after the UI component is created.
 *  2. The storage of all menu item data is preallocated.
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __GUI_FIXED_MENUS_H__
#define __GUI_FIXED_MENUS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui.h"
#include "gui_scrollbars.h"
#include "gui_common_menus.h"
#include "gui_theme_struct.h"
#include "gdi_include.h"
    
#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"
#endif /* __MMI_TOUCH_SCREEN__ */

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_BI_DEGREE_MAIN_MENU_ARROW_IND_SIZE          8
#define MMI_BI_DEGREE_MAIN_MENU_ARROW_BAR_HEIGHT        20
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_IND_BG_SIZE    20

#define UI_DROP_DOWN_CONTROL_STATE_NORMAL               0x00000000
#define UI_DROP_DOWN_CONTROL_STATE_FOCUSSED             0x00000001
#define UI_DROP_DOWN_CONTROL_STATE_CLICKED              0x00000002
#define UI_DROP_DOWN_CONTROL_STATE_DISABLED             0x00000004
#define UI_DROP_DOWN_CONTROL_STATE_SELECTED             0x00000008
#define UI_DROP_DOWN_CONTROL_TEXT_LEFT_JUSTIFY          0x00000010
#define UI_DROP_DOWN_CONTROL_TEXT_RIGHT_JUSTIFY         0x00000020
#define UI_DROP_DOWN_CONTROL_TEXT_CENTER_JUSTIFY        0x00000040
#define UI_DROP_DOWN_CONTROL_DISABLE_BACKGROUND         0x00000100
#define UI_DROP_DOWN_CONTROL_DISABLE_DRAW               0x00000200
#define UI_DROP_DOWN_CONTROL_SHOW_BUTTON_ON_FOCUS       0x00000400

/* displacement tolerated on tapping left/right arrows */
#define GUI_HORIZONTAL_SELECT_PEN_VALID_REGION          5

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * fixed list
 */
typedef enum
{
    GUI_LIST_PEN_NONE,
    GUI_LIST_PEN_HIGHLIGHT_CHANGED,
    GUI_LIST_PEN_NEED_REDRAW,
    GUI_LIST_PEN_ITEM_SELECTED,
    /* Two-state menu item */
    GUI_TWOSTATE_PEN_TOGGLE,
    GUI_LIST_PEN_TWO_LINE_NEXT,
    GUI_LIST_PEN_TWO_LINE_PREVIOUS
} gui_list_pen_enum;

typedef struct
{
    S8 pen_on_scrollbar;
    /* pen events are handled by menu item directly */
    S8 handled_by_menu_item;
    /* highlighted item is changed between Pen Down and Pen Up */
    S8 highlight_changed;
    /* highlighted item on pen down */
    S32 first_highlighed_item;
} gui_list_pen_state_struct;

#ifdef __MMI_TOUCH_SCREEN__
typedef BOOL (*fixed_menuitem_pen_hdlr)(void *item, void *common_item_data, S32 item_x, S32 item_y,
                                        mmi_pen_event_type_enum pen_event, S16 x, S16 y,
                                        gui_list_pen_enum *menuitem_event,
                                        gui_pen_event_param_struct *menuitem_param);
#endif /* __MMI_TOUCH_SCREEN__ */

typedef struct _fixed_list_menu
{
    S32 x, y;
    S32 width, height;
    UI_filled_area *normal_filler;
    UI_filled_area *focussed_filler;
    U32 flags;
    vertical_scrollbar vbar;
    S32 n_items;
    S32 displayed_items;
    S32 first_displayed_item;
    S32 last_displayed_item;
    S32 highlighted_item;

    S32 current_displayed_item;
    
    S32 highlight_x;
    S32 highlight_y;
    
    S32 spacing, top;
    /* MTK Leo end */
    void **items;
    void *common_item_data;
    void (*item_unhighlighted)(S32 i);
    void (*item_highlighted)(S32 i);
    void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y);
    void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height);
    void (*item_highlight_function)(void *item, void *common_item_data);
    void (*item_remove_highlight_function)(void *item, void *common_item_data);
    void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y);
    void (*item_displayed_callback)(S32 index, S32 x1, S32 y1, S32 x2, S32 y2);
    void (*item_resize_function)(S32 x, S32 y);

    void (*pre_display_function)(void);

    MMI_BOOL resized_before_locate;
    gdi_handle act_layer_handle;
    gdi_handle act_lcd_handle;
#ifdef __MMI_TOUCH_SCREEN__
    /* Configured in gui_set_fixed_list_menu_item_pen_function() */
    fixed_menuitem_pen_hdlr item_pen_function;
    MMI_BOOL disable_move_highlight;
    MMI_BOOL disable_up_select;
    /* Configured in associate_fixed_xxx_list */
    void (*pen_event_current_selected_callback_function)(void);
    void (*pen_event_default_selected_callback_function)(void);
    /* Configured in pen handler */
    void (*pen_redraw_menu_function) (void);
    /* Configured in gui_fixed_list_menu_set_pen_scroll_delay() */
    S16 pen_scroll_delay_time;
    S16 pen_scroll_after_delay;
    /* Runtime data */
    gui_list_pen_state_struct pen_state;
#endif /* __MMI_TOUCH_SCREEN__ */ 
} fixed_list_menu;                                        


/*
 * fixed matrix
 */
typedef enum
{
    GUI_MATRIX_PEN_NONE,
    GUI_MATRIX_PEN_HIGHLIGHT_CHANGED,
    GUI_MATRIX_PEN_NEED_REDRAW,
    GUI_MATRIX_PEN_ITEM_SELECTED
} gui_matrix_pen_enum;

typedef struct
{
    S8 pen_on_horizontal_scrollbar;
    S8 pen_on_vertical_scrollbar;
    /* highlighted item is changed between Pen Down and Pen Up */
    S8 highlight_changed;
    /* highlighted item on pen down */
    S32 first_highlighed_item;
} gui_matrix_pen_state_struct;

typedef struct
{
    S32 x;
    S32 y;
    S32 width;
    S32 height;
    U8 *string;
    U16 img_id;
} gui_matrix_ind_area_struct;

typedef struct _fixed_matrix_menu
{
    S32 x, y;
    S32 width, height;
    UI_filled_area *normal_filler;
    UI_filled_area *focussed_filler;
    U32 flags;
    vertical_scrollbar vbar;
    horizontal_scrollbar hbar;
    S32 n_columns;
    S32 n_rows;
    S32 n_items;
    S32 first_displayed_column;
    S32 first_displayed_row;
    S32 last_hilited_x;
    S32 last_hilited_y;
    S32 displayed_columns;
    S32 displayed_rows;
    S32 highlighted_column;
    S32 highlighted_row;
    S32 highlighted_item;
    S32 item_width;
    S32 item_height;
    S32 last_highlighted_item;
    S32 highlighted_item_width;
    S32 highlighted_item_height;
    void **items;
    void *common_item_data;
    void (*item_unhighlighted)(S32 i);
    void (*item_highlighted)(S32 i);
    void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y);
    void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height);
    void (*item_highlight_function)(void *item, void *common_item_data);
    void (*item_remove_highlight_function)(void *item, void *common_item_data);
    void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y);
    /* When row number < 0 && UI_MATRIX_MENU_VERTICAL_TRIGGER */
    void (*trigger_top_function) (void);
    /* When row number > max  && UI_MATRIX_MENU_VERTICAL_TRIGGER */
    void (*trigger_bottom_function) (void);
    S32 cache_bmp_x1;
    S32 cache_bmp_x2;
    S32 cache_bmp_y1;
    S32 cache_bmp_y2;
    gdi_image_cache_bmp_struct buffer;
#ifdef __MMI_TOUCH_SCREEN__
    /* Runtime data */
    gui_matrix_pen_state_struct pen_state;
    /* Configured in associate_fixed_xxx_mtraix */
    void (*pen_event_current_selected_callback_function) (void);
    void (*pen_event_default_selected_callback_function) (void);
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    gui_matrix_ind_area_struct up_ind_area;
    gui_matrix_ind_area_struct down_ind_area;
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#endif /* __MMI_TOUCH_SCREEN__ */ 
} fixed_matrix_menu;


/*
 * drop down control
 */
typedef struct _drop_down_control
{
    S32 x, y;
    S32 width, height;
    UI_filled_area *normal_filler;
    UI_filled_area *disabled_filler;
    UI_filled_area *focussed_filler;
    UI_filled_area *clicked_filler;
    color normal_text_color;
    color disabled_text_color;
    color focussed_text_color;
    color clicked_text_color;
    U32 flags;
    UI_string_type text;
    UI_font_type text_font;
    icon_button down_button;
} drop_down_control;


/*
 * horizontal select
 */
typedef enum
{
    GUI_HORIZONTAL_SELECT_PEN_NONE,
    GUI_HORIZONTAL_SELECT_PEN_PREV,
    GUI_HORIZONTAL_SELECT_PEN_NEXT
} gui_horizontal_select_pen_enum;

typedef struct
{
    S16 left_region_x, left_region_y;
    S16 left_region_width, left_region_height;
    S16 right_region_x, right_region_y;
    S16 right_region_width, right_region_height;

    S8 pen_down_left_arrow;
    S8 pen_down_right_arrow;
} gui_horizontal_select_pen_state_struct;

typedef struct _horizontal_select
{
    S32 x, y;
    S32 width, height;
    UI_filled_area *background_filler;
    U32 flags;
    S8 left_arrow_pressed;
    S8 right_arrow_pressed;
    PU8 left_arrow_image;
    PU8 right_arrow_image;
    S32 lx, ly;
    S32 rx, ry;
    S32 ix1, iy1, ix2, iy2;
    S32 n_items;
    S32 highlighted_item;
    void **items;
    void *common_item_data;
    /* Clear the background of the whole horizontal selection.
       Usually used together with UI_LIST_MENU_DISABLE_BACKGROUND. */
    void (*clear_background_callback)(S32 x1, S32 y1, S32 x2, S32 y2);
    void (*item_unhighlighted)(S32 i);
    void (*item_highlighted)(S32 i);
    void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y);
    void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height);
    void (*item_highlight_function)(void *item, void *common_item_data);
    void (*item_remove_highlight_function)(void *item, void *common_item_data);
    void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y);
    void (*item_displayed_callback)(S32 index, S32 x1, S32 y1, S32 x2, S32 y2);
#ifdef __MMI_TOUCH_SCREEN__
    gui_horizontal_select_pen_state_struct pen_state;
#endif 
} horizontal_select;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern UI_fixed_list_menu_theme *current_fixed_list_menu_theme;
extern S32 current_fixed_list_menuitem_display_index;


extern UI_fixed_matrix_menu_theme *current_fixed_matrix_menu_theme;


extern UI_drop_down_control_theme *current_drop_down_control_theme;


extern UI_horizontal_select_theme *current_horizontal_select_theme;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* 
 * fixed list menu
 */
extern void gui_show_list_menu_background_outside_area(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2);
extern void gui_set_fixed_list_menu_current_theme(fixed_list_menu *m);
extern void gui_set_fixed_list_menu_theme(fixed_list_menu *m, UI_fixed_list_menu_theme *t);
extern void gui_create_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y, S32 width, S32 height);
extern void gui_resize_fixed_list_menu(fixed_list_menu *m, S32 width, S32 height);
extern void gui_move_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y);
extern void gui_fixed_list_menu_locate_highlighted_item(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_item(fixed_list_menu *m, S32 i);
extern void gui_fixed_list_menu_goto_next_item(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_previous_item(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_next_page(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_previous_page(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_first_item(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_last_item(fixed_list_menu *m);
extern void gui_show_fixed_list_menu(fixed_list_menu *m);
extern void gui_hide_fixed_list_menu_highlighted_item(fixed_list_menu *m);
extern void gui_set_fixed_list_menu_item_functions(fixed_list_menu *m,
                                                   void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y),
                                                   void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height),
                                                   void (*item_highlight_function)(void *item, void *common_item_data),
                                                   void (*item_remove_highlight_function)(void *item, void *common_item_data),
                                                   void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y), 
                                                   void (*item_resize_function)(S32 x, S32 y));
extern void gui_set_fixed_list_menu_common_item_data(fixed_list_menu *m, void *c);
extern void gui_show_fixed_list_menu_no_draw(fixed_list_menu *m);

#ifdef __MMI_TOUCH_SCREEN__
extern void gui_fixed_list_menu_set_pen_scroll_delay(fixed_list_menu *m, S32 delay_time);
extern void gui_set_fixed_list_menu_item_pen_function(
                fixed_list_menu *m,
                fixed_menuitem_pen_hdlr item_pen_function,
                BOOL disable_move_highlight,
                BOOL disable_up_select);
extern BOOL gui_fixed_list_menu_translate_pen_event(
                fixed_list_menu *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_list_pen_enum *menu_event);
extern BOOL gui_fixed_list_menu_translate_pen_position(fixed_list_menu *m, S32 y, S32 *item_index);
#endif /* __MMI_TOUCH_SCREEN__ */


/*
 * fixed matrix menu
 */
extern void gui_set_fixed_matrix_menu_current_theme(fixed_matrix_menu *m);
extern void gui_set_fixed_matrix_menu_theme(fixed_matrix_menu *m, UI_fixed_matrix_menu_theme *t);
extern void gui_create_fixed_matrix_menu(fixed_matrix_menu *m, S32 x, S32 y, S32 width, S32 height);
extern void gui_fixed_matrix_menu_setup(
                fixed_matrix_menu *m,
                S32 item_width,
                S32 item_height,
                S32 n_columns,
                S32 n_rows);
extern void gui_resize_fixed_matrix_menu(fixed_matrix_menu *m, S32 width, S32 height);
extern void gui_move_fixed_matrix_menu(fixed_matrix_menu *m, S32 x, S32 y);
extern void gui_fixed_matrix_menu_locate_highlighted_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_next_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_previous_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_previous_row(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_next_row(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_previous_column(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_next_column(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_first_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_last_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_next_page(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_previous_page(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_item(fixed_matrix_menu *m, S32 i);

extern void mtk_UI_show_fixed_matrix_menu(fixed_matrix_menu *m);

#ifdef __MMI_TOUCH_SCREEN__
extern BOOL gui_fixed_matrix_menu_translate_pen_event(
                fixed_matrix_menu *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_matrix_pen_enum *menu_event);
#endif /* __MMI_TOUCH_SCREEN__ */

extern void gui_show_fixed_matrix_menu(fixed_matrix_menu *m);
extern void gui_hide_fixed_matrix_menu_highlighted_item(fixed_matrix_menu *m);
extern void gui_set_fixed_matrix_menu_item_functions(fixed_matrix_menu *m,
                                                     void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y),
                                                     void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height),
                                                     void (*item_highlight_function)(void *item, void *common_item_data),
                                                     void (*item_remove_highlight_function)(void *item, void *common_item_data),
                                                     void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y));
extern void gui_set_fixed_matrix_menu_common_item_data(fixed_matrix_menu *m, void *c);

extern void gui_reset_fixed_matrix_col_rows(fixed_matrix_menu *m);
extern S32 gui_fixed_matrix_auto_disable_scrollbar(fixed_matrix_menu *m);

/* dummy functions used by fixed menus */
extern void UI_fixed_menuitem_dummy_display_function(void *item, void *common_item_data, S32 x, S32 y);
extern void UI_fixed_menuitem_dummy_hide_function(void *item, void *common_item_data, S32 x, S32 y);
extern void UI_fixed_menuitem_dummy_measure_function(void *item, void *common_item_data, S32 *width, S32 *height);
extern void UI_fixed_menuitem_dummy_highlight_function(void *item, void *common_item_data);
extern void UI_fixed_menuitem_dummy_remove_highlight_function(void *item, void *common_item_data);
extern void UI_fixed_menuitem_dummy_resize_function(S32 x, S32 y);

#ifdef __MMI_TOUCH_SCREEN__
extern BOOL UI_fixed_menuitem_dummy_pen_function(
                void *item,
                void *common_item_data,
                S32 item_x,
                S32 item_y,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_list_pen_enum *menuitem_event,
                gui_pen_event_param_struct *menuitem_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 


/* 
 * drop down control
 */
extern void gui_set_drop_down_control_current_theme(drop_down_control *o);
extern void gui_set_drop_down_control_theme(drop_down_control *o, UI_drop_down_control_theme *t);
extern void gui_create_drop_down_control(drop_down_control *o, S32 x, S32 y, S32 width, S32 height);
extern void gui_resize_drop_down_control(drop_down_control *o, S32 width, S32 height);
extern void gui_move_drop_down_control(drop_down_control *o, S32 x, S32 y);
extern void gui_show_drop_down_control(drop_down_control *o);


/* 
 * horizontal select
 */
extern void gui_set_horizontal_select_current_theme(horizontal_select *m);
extern void gui_set_horizontal_select_theme(horizontal_select *m, UI_horizontal_select_theme *t);
extern void gui_create_horizontal_select(horizontal_select *m, S32 x, S32 y, S32 width, S32 height);
extern void gui_resize_horizontal_select(horizontal_select *m, S32 width, S32 height);
extern void gui_move_horizontal_select(horizontal_select *m, S32 x, S32 y);
extern void gui_horizontal_select_goto_item(horizontal_select *m, S32 i);
extern void gui_horizontal_select_goto_next_item(horizontal_select *m);
extern void gui_horizontal_select_goto_previous_item(horizontal_select *m);
extern void gui_horizontal_select_goto_first_item(horizontal_select *m);
extern void gui_horizontal_select_goto_last_item(horizontal_select *m);
extern void gui_show_horizontal_select(horizontal_select *m);
extern void gui_hide_horizontal_select_highlighted_item(horizontal_select *m);
extern void gui_set_horizontal_select_clear_background_function(
                horizontal_select *m,
                void (*clear_bg_function)(S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_set_horizontal_select_item_functions(
                horizontal_select *m,
                void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y),
                void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height),
                void (*item_highlight_function)(void *item, void *common_item_data),
                void (*item_remove_highlight_function)(void *item, void *common_item_data),
                void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y));
extern void gui_set_horizontal_select_common_item_data(horizontal_select *m, void *c);
extern void gui_set_horizontal_select_images(horizontal_select *m, PU8 left_arrow, PU8 right_arrow);

#ifdef __MMI_TOUCH_SCREEN__
extern BOOL gui_horizontal_select_translate_pen_event(
                horizontal_select *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_horizontal_select_pen_enum *select_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __GUI_FIXED_MENUS_H__ */ 

