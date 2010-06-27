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
 *  wgui_fixed_menus.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  fixed menu external interface
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

#ifndef __WGUI_FIXED_MENUS_H__
#define __WGUI_FIXED_MENUS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui.h"
#include "wgui_menu_shortcuts.h"
#include "gui_custom_menus.h"
#include "gdi_include.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define LIMIT_MENU_ITEM_NUMBER(n)      ((n) > (MAX_SUB_MENUS) ? (MAX_SUB_MENUS) : (n))

/* The number of menu item pointers is limited to MAX_SUB_MENUS. */
#define MAX_FIXED_MENU_ITEM_POINTERS   LIMIT_MENU_ITEM_NUMBER(100)

/* 
 * circular 3D menu 
 */
#define WGUI_CM3D_MAX_ITEMS             16
#define WGUI_CM3D_N_ITEM_IMAGES         3
#define WGUI_CM3D_N_COMMON_IMAGES       4
#define WGUI_CM3D_N_DISPLAYED_ITEMS     7


/*
 * techno main menu
 */
#define BACKGROUND_FRAMES               5
#define FIRST_FRAME                     0
#define LAST_FRAME                      (BACKGROUND_FRAMES - 1)


/*
 * list transition
 */
#ifdef __MMI_UI_LIST_TRANSITION__
#define LIST_TRANSITION_STYLE_NON_BLOCKING 1
#define LIST_TRANSITION_NON_BLOCKING_TIMER 10
#else /* __MMI_UI_LIST_TRANSITION__ */
#define LIST_TRANSITION_STYLE_NON_BLOCKING 0
#endif /* __MMI_UI_LIST_TRANSITION__ */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * techno main menu
 */
typedef struct _MMTechno_image_position
{
    S32 x;
    S32 y;
} MMTechno_image_position;

typedef struct _MMTechno_animo_menu
{
    PU8 item_image;
    MMTechno_image_position *item_position;
} MMTechno_animo_menu;


/*
 * slider control
 */
typedef enum
{
    GUI_SLIDE_CONTROL_PEN_NONE,     /* No event is generated. (but the low-level pen events might be still accepted) */
    GUI_SLIDE_CONTROL_PEN_JUMP_TO_I /* Jump to certain value */
} gui_slide_control_pen_event_enum;

typedef enum
{
    GUI_SLIDE_CONTROL_PEN_STATE_INVALID,
    GUI_SLIDE_CONTROL_PEN_STATE_AREA1,
    GUI_SLIDE_CONTROL_PEN_STATE_AREA2,
    GUI_SLIDE_CONTROL_PEN_STATE_SLIDE
} gui_slide_control_pen_state_enum;

typedef enum
{
    GUI_SLIDE_CONTROL_VALUE_POS_NONE,
    GUI_SLIDE_CONTROL_VALUE_POS_HEAD,
    GUI_SLIDE_CONTROL_VALUE_POS_TAIL,
    GUI_SLIDE_CONTROL_VALUE_POS_NEXT_LINE
} gui_slide_control_value_postion_enum;

typedef struct _slide_control
{
    S32 x, y;                                       /* position of background image */
    PU8 background_image;
    PU8 slide_image;
    U32 flags;
    S32 bg_image_width;
    S32 bg_image_height;
    S32 slide_image_width;
    S32 slide_image_height;
    S32 width;
    S32 lower_limit;
    S32 upper_limit;
    S32 current_value;
    S32 value_string_width, value_string_height;    /* position of value string */
    S32 value_string_gap;
    U8 *label_string;                               /* label string is always above the background image */
    void (*change_callback) (S32);
#ifdef GDI_USING_LAYER
    gdi_handle display_layer;
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    gui_slide_control_pen_state_enum pen_state;
#endif 
} slide_control;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern fixed_list_menu MMI_fixed_list_menu;


extern fixed_matrix_menu MMI_fixed_matrix_menu;


#if ENABLE_CIRCULAR_3D_MENU
extern UI_string_type wgui_CM3D_items[];
extern PU8 wgui_CM3D_images[];
extern PU8 wgui_CM3D_common_images[];
extern S32 wgui_CM3D_n_items;
extern UI_3D_circular_menu wgui_CM3D_menu;
#endif /* ENABLE_CIRCULAR_3D_MENU */

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* 
 * fixed list menu
 */
extern void create_fixed_list(void);
extern void plain_fixed_list(void);
extern void normal_fixed_list(void);
extern void register_hide_fixed_list(void (*f) (void));
extern void move_fixed_list(S32 x, S32 y);
extern void show_fixed_list(void);
extern void redraw_fixed_list(void);
extern void register_fixed_list_highlight_handler(void (*f) (S32 item_index));
extern void register_fixed_list_unhighlight_handler(void (*f) (S32 item_index));
extern void clear_fixed_list_highlight_handler(void);
extern void fixed_list_goto_previous_item(void);
extern void fixed_list_goto_next_item(void);
extern void fixed_list_goto_home(void);
extern void fixed_list_goto_end(void);
extern void fixed_list_goto_previous_page(void);
extern void fixed_list_goto_next_page(void);
extern void fixed_list_goto_item(S32 item_index);
extern void fixed_list_goto_item_no_redraw(S32 item_index);
extern void fixed_list_goto_item_push_first(S32 item_index);
extern void register_fixed_list_shortcut_handler(void);
extern void fixed_list_measure(S32 *width, S32 *height);
extern void resize_fixed_list(S32 width, S32 height);
extern void move_fixed_list(S32 x, S32 y);
extern void register_fixed_list_keys(void);
extern void reset_fixed_list(void);
extern void fixed_list_disable_looping(void);
extern void fixed_list_enable_looping(void);
extern void wgui_list_menu_show_empty_label_if_needed(void);

/* 
 * fixed matrix menu
 */
extern void (*resize_fixed_matrix_menuitems) (S32 item_width, S32 item_height);

extern void create_fixed_matrix(void);
extern void move_fixed_matrix(S32 x, S32 y);
extern void show_fixed_matrix(void);
extern void configure_fixed_matrix(S32 item_width, S32 item_height, S32 n_columns, S32 n_rows);
extern void register_fixed_matrix_highlight_handler(void (*f) (S32 item_index));
extern void clear_fixed_matrix_highlight_handler(void);
extern void fixed_matrix_goto_previous_item(void);
extern void fixed_matrix_goto_next_item(void);
extern void fixed_matrix_goto_previous_column(void);
extern void fixed_matrix_goto_next_column(void);
extern void fixed_matrix_goto_previous_row(void);
extern void fixed_matrix_goto_next_row(void);
extern void fixed_matrix_goto_home(void);
extern void fixed_matrix_goto_end(void);
extern void fixed_matrix_goto_previous_page(void);
extern void fixed_matrix_goto_next_page(void);
extern void fixed_matrix_goto_item(S32 item_index);
extern void fixed_matrix_goto_item_no_redraw(S32 item_index);
extern void register_fixed_matrix_shortcut_handler(void);
extern void fixed_matrix_measure(S32 *width, S32 *height);
extern void resize_fixed_matrix(S32 width, S32 height);
extern void move_fixed_matrix(S32 x, S32 y);
extern void register_fixed_matrix_keys(void);
extern void reset_fixed_matrix(void);
extern void reset_fixed_matrix_col_rows(void);


/*
 * circular 3D menu
 */
#if ENABLE_CIRCULAR_3D_MENU
extern void show_circular_3d_menu(void);
extern void create_circular_3d_menu(S32 n_items, MMI_ID_TYPE *items, MMI_ID_TYPE *images);
extern void register_circular_3d_menu_keys(void);
extern void register_rotate_menu_keys(void);    /* 111904 Calvin added for ROTATE mainmenu */
extern void register_circular_3d_highlight_handler(void (*f) (S32 item_index));
extern void circular_3d_menu_goto_item_no_redraw(S32 item_index);
extern void circular_3d_menu_next(void);
extern void circular_3d_menu_previous(void);
extern void circular_3d_menu_goto_item(S32 item_index);
extern void register_3d_menu_shortcut_handler(void);
extern void move_circular_3d_menu(S32 s32X, S32 s32Y);
extern void resize_circular_3d_menu(S32 s32Width, S32 s32Height);
#endif /* ENABLE_CIRCULAR_3D_MENU */ 


/*
 * techno main menu
 */
#ifdef __MMI_UI_TECHNO_MAINMENU__
extern void create_techno_main_menu(S32 no_of_main_menu_items, MMI_ID_TYPE *image);
extern void show_techno_menu_animation(void);
extern void show_techno_menu(void);
extern void associate_techno_item_positions(U8 is_next);
#endif /* __MMI_UI_TECHNO_MAINMENU__ */ 


/*
 * slider control
 */
extern void create_slide_control(slide_control *s, S32 x, S32 y);

#ifdef GDI_USING_LAYER
extern void set_slide_control_layer(slide_control *s, gdi_handle layer);
extern void reset_slide_control_layer(slide_control *s);
#endif /* GDI_USING_LAYER */ 

extern void show_slide_control(slide_control *s);
extern void show_slide_control_value(slide_control *s);
extern void show_slide_control_label(slide_control *s);
extern void show_slide_control_focus_area(slide_control *s);
extern void hide_slide_control_focus_area(slide_control *s);
extern void slide_control_previous(slide_control *s);
extern void slide_control_next(slide_control *s);
extern void set_slide_control_limits(slide_control *s, S32 lower_limit, S32 upper_limit);
extern void set_slide_control_label(slide_control *s, U8 *label_string);
extern void set_slide_control_value(slide_control *s, S32 value);
extern void set_slide_control_images(slide_control *s, PU8 background_image, PU8 slide_image);
extern void move_slide_control_value(slide_control *s, S32 x, S32 y);
extern void wgui_setup_slide_control(slide_control *s, S32 x, S32 y, S32 lower_limit, S32 upper_limit, S32 current_value, void (*change_callback) (S32 value));
 
#ifdef __MMI_TOUCH_SCREEN__
extern BOOL wgui_slide_control_translate_pen_event(
                slide_control *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_slide_control_pen_event_enum *slide_event,
                gui_pen_event_param_struct *slide_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*
 * list transition effect
 */
#if LIST_TRANSITION_STYLE_NON_BLOCKING
extern void draw_transition_list_non_blocking(void);
extern void wgui_stop_list_transition_non_blocking(void);
extern S32 is_in_nonblocking_list_transition(void);
extern S32 get_original_prev_list_y_value(void);
extern void wgui_list_tranisition_abort_cleanup_function(void);
extern void save_copy_original_list_data(void);
extern void restore_saved_original_list_data(void);
#endif /* LIST_TRANSITION_STYLE_NON_BLOCKING */ 
 
#if defined(__MMI_UI_TRANSPARENT_EFFECT__) || defined(__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) 
extern void gui_reset_transparent_source_layer(void);
#endif 

#endif /* __WGUI_FIXED_MENUS_H__ */ 

