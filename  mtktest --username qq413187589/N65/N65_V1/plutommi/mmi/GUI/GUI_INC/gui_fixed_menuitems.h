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
 *  gui_fixed_menuitems.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Menu items in fixed menu - UI component
 *
 *  [Text menu item]
 *  [Icontext menu item]
 *  [Icontext-list menu item]
 *  [Twostate menu item]
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

#ifndef __GUI_FIXED_MENUITEMS_H__
#define __GUI_FIXED_MENUITEMS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui.h"
#include "gdi_include.h"
#include "gui_theme_struct.h"
#include "gui_fixed_menus.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"
#endif /* __MMI_TOUCH_SCREEN__ */

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define HIGHLIGHTER_COLOR_OPACITY_VALUE     85  /* highlight opacity factor value from 0 to 100 */

#define LIST_TRANSPARENT_HIGHLIGHTER_TIMER  175
#define LIST_FLASH_HIGHLIGHTER_TIMER        150
#define LIST_ANIMATION_HIGHLIGHTER_TIMER    175

#define MAX_OPACITY_VALUE_FACTOR            10
#define TRANSPARENCY_START_OPACITY_VALUE    1
#define JUMP_IN_HIGHLIGHTERS_EFFECTS_FRAME  4

/* 
 * base structure of the common menuitem 
 */
#define GUI_COMMON_MENUITEM_BASE_STRUCT         \
    S32 width, height;                          \
                                                \
    U32 flags;                                  \
    U32 ext_flags;                              \
                                                \
    /* text scrolling */                        \
    S32 scroll_x, scroll_width;                 \
    S32 text_width;                             \
                                                \
    /* menuitem coordinates */                  \
    S32 text_x, text_y;                         \
    S32 icon_x, icon_y;                         \
                                                \
    /* theme */                                 \
    UI_filled_area *normal_filler;              \
    UI_filled_area *disabled_filler;            \
    UI_filled_area *selected_filler;            \
    UI_filled_area *focussed_filler;            \
    color normal_text_color;                    \
    color disabled_text_color;                  \
    color selected_text_color;                  \
    color focussed_text_color;                  \
    UI_font_type text_font;                     \
                                                \
    /* parent menu */                           \
    fixed_list_menu *parent_list;               \
    fixed_matrix_menu *parent_matrix;

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* 
 * base structure of the common menuitem 
 */
typedef struct
{
    GUI_COMMON_MENUITEM_BASE_STRUCT
} gui_common_menuitem_base_struct;


/* 
 * fixed icontext menuitem 
 */
typedef struct _fixed_icontext_menuitem_type
{
    PU8 item_icon;
    gdi_handle item_icon_handle;
    UI_string_type item_text;
    U32 flags;
    U32 ext_flags;
} fixed_icontext_menuitem_type;

/* checkbox structure */
typedef struct
{
    S32     x, y;
    PU8     image;
    S32     image_width, image_height;
} gui_menuitem_icontext_checkbox_struct;

/* checkbox callback function typedef */
typedef S32 (*checkbox_clicked_funcptr_type)(S32 item_index);
typedef S32 (*checkbox_get_image_funcptr_type)(S32 item_index, PU8 *checkbox_image);

typedef struct _fixed_icontext_menuitem
{
    GUI_COMMON_MENUITEM_BASE_STRUCT

    /* checkbox */
    S32 checkbox_x, checkbox_y;
    checkbox_clicked_funcptr_type checkbox_clicked_callback;
    checkbox_get_image_funcptr_type checkbox_get_image_callback;  
} fixed_icontext_menuitem;


/* 
 * fixed text menuitem
 *
 * EQUIVALENT to icontext menuitem
 */
typedef fixed_icontext_menuitem fixed_text_menuitem;
typedef fixed_icontext_menuitem_type fixed_text_menuitem_type;


/* 
 * fixed icontext list menuitem 
 */
typedef struct _fixed_icontext_list_menuitem_type
{
    PU8 item_icons[FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS];
    gdi_handle item_icon_handles[FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS];
    UI_string_type item_texts[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    U32 flags;
} fixed_icontext_list_menuitem_type;

typedef struct _fixed_icontext_list_menuitem
{
    GUI_COMMON_MENUITEM_BASE_STRUCT
    
    S32 n_text_columns;
    S32 n_icon_columns;    
    UI_object_coordinates text_coordinates[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    UI_object_coordinates icon_coordinates[FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS];

    color normal_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    color disabled_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    color selected_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    color focussed_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];    
    UI_font_type text_fonts[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];

    void (*post_display_function) (void *item, void *common_item_data, S32 x, S32 y);
} fixed_icontext_list_menuitem;


/* 
 * fixed twostate menuitem structure 
 */
typedef struct _fixed_twostate_menuitem_type
{
    UI_string_type item_text;
    U32 flags;
} fixed_twostate_menuitem_type;

typedef struct _fixed_twostate_menuitem
{
    GUI_COMMON_MENUITEM_BASE_STRUCT

    PU8 ON_icon;
    PU8 OFF_icon;
} fixed_twostate_menuitem;


/*
 * miscellaneous
 */
typedef enum
{
    ICON_TEXT_ICON = 0,
    ICON_ICON_TEXT,
    TEXT_ICON_ICON
} CAT73DISPLAY;


typedef enum
{
    MMI_UI_LIST_HIGHLIGHT_EFFECT_NONE = 0,          /* No Effect */
    MMI_UI_LIST_HIGHLIGHT_EFFECT_TRANSPARENCY = 1,  /* Transparent with increasing opacity */
    MMI_UI_LIST_HIGHLIGHT_EFFECT_FLASH_FEELING = 2, /* Flash effect with increase in Filler area */
    MMI_UI_LIST_HIGHLIGHT_EFFECT_ANIMATION = 3,     /* Animatian with gif */
    MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE = 4          /* Sliding highlight effect */
} gui_list_effect_styles;


typedef enum
{
    GUI_LIST_EFFECT_FLASH_FEELING_STOP,
    GUI_LIST_EFFECT_FLASH_FEELING_LAST_FRAME,
    GUI_LIST_EFFECT_FLASH_FEELING_RUNNING
} gui_flash_feel_state_enum;

typedef struct
{
    S32             x, y;                   /* animation x and y coordinate */
    PU8             animation;              /* animation */
    UI_filled_area  *background_filler;     /* animation background filler */
    gdi_handle      old_src_layer;          /* old source layer */    
} gui_animation_with_background_struct;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern UI_fixed_text_menuitem_theme             *current_fixed_text_menuitem_theme;
extern UI_fixed_icontext_menuitem_theme         *current_fixed_icontext_menuitem_theme;
extern UI_fixed_icontext_list_menuitem_theme    *current_fixed_icontext_list_menuitem_theme;
extern UI_fixed_twostate_menuitem_theme         *current_fixed_twostate_menuitem_theme;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* 
 * fixed text menuitem  
 */
extern void gui_set_fixed_text_menuitem_theme(fixed_text_menuitem *m, UI_fixed_text_menuitem_theme *t);
extern void gui_set_fixed_text_menuitem_current_theme(fixed_text_menuitem *m);
extern void gui_create_fixed_text_menuitem(fixed_text_menuitem *m, S32 width, S32 height);
extern void gui_fixed_text_menuitem_set_text_position(fixed_text_menuitem *m, S32 x, S32 y);
extern void gui_resize_fixed_text_menuitem(fixed_text_menuitem *m, S32 width, S32 height);
extern void gui_show_fixed_text_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_measure_fixed_text_menuitem(void *item, void *common_item_data, S32 *width, S32 *height);
extern void gui_highlight_fixed_text_menuitem(void *item, void *common_item_data);
extern void gui_remove_highlight_fixed_text_menuitem(void *item, void *common_item_data);
extern void gui_fixed_text_menuitem_start_scroll(void);
extern void gui_fixed_text_menuitem_stop_scroll(void);


/* 
 * fixed icontext menuitem  
 */
extern void gui_set_fixed_icontext_menuitem_current_theme(fixed_icontext_menuitem *m);
extern void gui_set_fixed_icontext_menuitem_theme(fixed_icontext_menuitem *m, UI_fixed_icontext_menuitem_theme *t);
extern void gui_create_fixed_icontext_menuitem(fixed_icontext_menuitem *m, S32 width, S32 height);
extern void gui_fixed_icontext_menuitem_set_text_position(fixed_icontext_menuitem *m, S32 x, S32 y);
extern void gui_fixed_icontext_menuitem_set_icon_position(fixed_icontext_menuitem *m, S32 x, S32 y);
extern void gui_resize_fixed_icontext_menuitem(fixed_icontext_menuitem *m, S32 width, S32 height);
extern void gui_show_fixed_icontext_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_hide_fixed_icontext_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_measure_fixed_icontext_menuitem(void *item, void *common_item_data, S32 *width, S32 *height);
extern void gui_highlight_fixed_icontext_menuitem(void *item, void *common_item_data);
extern void gui_remove_highlight_fixed_icontext_menuitem(void *item, void *common_item_data);
extern void gui_fixed_icontext_menuitem_start_scroll(void);
extern void gui_fixed_icontext_menuitem_stop_scroll(void);

#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)
extern void gui_show_two_line_icontext_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_two_line_scroller_stop(void);
#endif /* (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__) */ 

#ifdef __MMI_TOUCH_SCREEN__
extern BOOL gui_fixed_icontext_menuitem_translate_pen_event(
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
 * fixed icontext list menuitem  
 */
extern void gui_set_fixed_icontext_list_menuitem_current_theme(fixed_icontext_list_menuitem *m);
extern void gui_set_fixed_icontext_list_menuitem_theme(
                fixed_icontext_list_menuitem *m,
                UI_fixed_icontext_list_menuitem_theme *t);
extern void gui_create_fixed_icontext_list_menuitem(
                fixed_icontext_list_menuitem *m,
                S32 width,
                S32 height,
                S32 n_text_columns,
                S32 n_icon_columns);
void gui_fixed_icontext_list_menuitem_set_post_display(fixed_icontext_list_menuitem *m,
                                                       void (*post_display_function)(void *item, void *common_item_data, S32 x, S32 y));
extern void gui_fixed_icontext_list_menuitem_set_text_coordinates(
                fixed_icontext_list_menuitem *m,
                S32 text_column,
                S32 x,
                S32 y,
                S32 width,
                S32 height);
extern void gui_fixed_icontext_list_menuitem_set_icon_coordinates(
                fixed_icontext_list_menuitem *m,
                S32 icon_column,
                S32 x,
                S32 y,
                S32 width,
                S32 height);
extern void gui_resize_fixed_icontext_list_menuitem(fixed_icontext_list_menuitem *m, S32 width, S32 height);
extern void gui_show_fixed_icontext_list_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_measure_fixed_icontext_list_menuitem(void *item, void *common_item_data, S32 *width, S32 *height);
extern void gui_highlight_fixed_icontext_list_menuitem(void *item, void *common_item_data);
extern void gui_remove_highlight_fixed_icontext_list_menuitem(void *item, void *common_item_data);
extern void gui_fixed_icontext_list_menuitem_start_scroll(void);
extern void gui_fixed_icontext_list_menuitem_stop_scroll(void);


/* 
 * fixed twostate menuitem  
 */
extern void gui_set_fixed_twostate_menuitem_current_theme(fixed_twostate_menuitem *m);
extern void gui_set_fixed_twostate_menuitem_theme(
                fixed_twostate_menuitem *m,
                UI_fixed_twostate_menuitem_theme *t);
extern void gui_create_fixed_twostate_menuitem(
                fixed_twostate_menuitem *m,
                S32 width,
                S32 height,
                PU8 ON_icon,
                PU8 OFF_icon);
extern void gui_fixed_twostate_menuitem_set_text_position(fixed_twostate_menuitem *m, S32 x, S32 y);
extern void gui_fixed_twostate_menuitem_set_icon_position(fixed_twostate_menuitem *m, S32 x, S32 y);
extern void gui_fixed_twostate_menuitem_set_icons(fixed_twostate_menuitem *m, PU8 ON_icon, PU8 OFF_icon);
extern void gui_resize_fixed_twostate_menuitem(fixed_twostate_menuitem *m, S32 width, S32 height);
extern void gui_show_fixed_twostate_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_measure_fixed_twostate_menuitem(void *item, void *common_item_data, S32 *width, S32 *height);
extern void gui_highlight_fixed_twostate_menuitem(void *item, void *common_item_data);
extern void gui_remove_highlight_fixed_twostate_menuitem(void *item, void *common_item_data);
extern void gui_fixed_twostate_menuitem_start_scroll(void);
extern void gui_fixed_twostate_menuitem_stop_scroll(void);

#ifdef __MMI_TOUCH_SCREEN__
extern BOOL gui_fixed_twostate_menuitem_translate_pen_event(
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


#ifdef __MMI_UI_TRANSPARENT_EFFECT__
extern void gui_block_transparency_effect(void);
extern void gui_unblock_transparency_effect(void);
extern void gui_fixed_icontext_enable_transparent_effect(fixed_icontext_menuitem *m);
extern void gui_fixed_icontext_disable_transparent_effect(fixed_icontext_menuitem *m);
extern void gui_fixed_icontext_list_enable_transparent_effect(fixed_icontext_list_menuitem *m);
extern void gui_fixed_icontext_list_disable_transparent_effect(fixed_icontext_list_menuitem *m);
extern void gui_fixed_text_menuitem_enable_transparent_effect(fixed_text_menuitem *m);
extern void gui_fixed_text_menuitem_disable_transparent_effect(fixed_text_menuitem *m);
extern void gui_fixed_twostate_menuitem_enable_transparent_effect(fixed_twostate_menuitem *m);
extern void gui_fixed_twostate_menuitem_disable_transparent_effect(fixed_twostate_menuitem *m);
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */ 


#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
extern void gui_callback_highlighter_text_filler(void);
extern void gui_stop_list_highlight_effect(void);
extern void gui_draw_animated_highlight_filler(
                S32 Xstart_effect,
                S32 Ystart_effect,
                S32 Xend_effect,
                S32 Yend_effect,
                UI_filled_area *f);
extern void gui_draw_transparent_color_filler(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
extern void gui_draw_flash_feeling_filler(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
extern void gui_reset_current_list_effect(void);
extern void gui_set_current_list_effect_to_default(void);
extern void gui_draw_list_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
extern void gui_scroll_start_handler_for_list_effects(void);
extern S32 gui_get_current_list_effect(void);
extern void gui_dummy_scroll_handler_for_list_effects(void);
void gui_register_callback_menuitem_scroll(void (*f) (void));
extern void gui_unblock_list_effect(void);
extern void gui_block_list_effect(void);
extern void gui_draw_list_highlight_effect_last_frame(void);
extern void gui_set_current_list_effect(gui_list_effect_styles list_style);
extern void gui_restore_current_list_effect(void);
extern S32 is_draw_next_frame_list_highlight_effect_value(void);
extern void set_start_position_parameter_for_list_highlighter_effect(S32 x, S32 y);
extern void set_start_position_and_item_parameters_for_list_highlighter_effect(
                void *item,
                void *common_item_data,
                S32 x,
                S32 y);
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

#if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
extern void (*gui_reset_current_two_line_menuitem_data)(void);

extern void UI_dummy_reset_current_two_line_menuitem_data(void);

extern void gui_show_two_line_background(S32 x1, S32 y1, S32 x2, S32 y2);
#endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
extern void (*gui_set_current_two_line_menuitem_data)(void);
extern void (*gui_show_two_line_menuitem_part)(void);
extern void (*gui_move_two_line_menuitem_part)(S32 x, S32 y);
extern void (*gui_resize_two_line_menuitem_part)(S32 x, S32 y);
extern pBOOL (*gui_get_two_line_menuitem_height)(void);
extern void (*gui_reset_two_line)(void);
extern void (*gui_two_line_toggle_thumbnail_direction)(void);
extern U8 (*gui_two_line_get_thumbnail_flags)(void);

extern void UI_dummy_show_two_line_menuitem_part(void);
extern pBOOL UI_dummy_get_two_line_menuitem_height(void);
extern void UI_dummy_set_current_two_line_menuitem_data(void);
extern void UI_dummy_move_two_line_menuitem_part(S32 x, S32 y);
extern void UI_dummy_resize_two_line_menuitem_part(S32 x, S32 y);
extern U8 UI_dummy_two_line_get_thumbnail_flags(void);
extern void two_line_menuitem_cleanup_function(void);
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 


extern void (*gui_display_pop_up_description)(S32 x, S32 y, S32 width, S32 height);

extern void UI_dummy_display_pop_up_description(S32 x, S32 y, S32 width, S32 height);

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
extern UI_string_type(*gui_get_current_pop_up_description_string)(void);

extern UI_string_type UI_dummy_get_current_pop_up_description_string(void);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

extern void gui_menuitem_verify_image_highlight_dimension(void *common_menuitem);

extern S32 gui_menuitem_is_two_line(void *item, void *common_item_data);
    
extern void gui_show_animation_with_background_image(S32 x, S32 y, PU8 animation, PU8 anim_bg_image, gdi_handle *animation_handle);
extern void gui_show_animation_with_background_filler(S32 x, S32 y, PU8 animation, UI_filled_area *background_filler, gdi_handle *animation_handle);    

#include "gui_menu_post_oem.h"

#endif /* __GUI_FIXED_MENUITEMS_H__ */ 

