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
/* **** Copy Right Note ********* 
 *  Copyright Notice
 *  (c) PMT.
 *  All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 *******************************************************************************
 * Filename:
 * ---------
 * wgui_draw_manager.h
 *
 * Project:
 * --------
 * PDG2
 *
 * Description:
 * ------------
 * This file contains the prototypes for Draw Manager.
 * Author:
 * -------
 * -------
 *==============================================================================
 * HISTORY
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

#ifndef __WGUI_DRAW_MANAGER_H__
#define __WGUI_DRAW_MANAGER_H__

#include "MMI_features.h"
#ifdef __MMI_DRAW_MANAGER__

#include "gui_panel.h"
#include "gui_data_types.h"
#include "CustThemesRes.h"
#include "FontRes.h"
#include "gdi_include.h"
#include "CustDataRes.h"
#include "gui_buttons.h"

/* Constants */
#if !defined(LOW_COST_SUPPORT)
#define DM_MAX_STRINGS                       3
#define DM_MAX_SUBLCD_STRINGS                2
#define DM_MAX_IMAGES                        5
#define DM_MAX_SUBLCD_IMAGES                 2
#define DM_MAX_FILL_AREAS                    3
#define DM_MAX_RECTANGLES                    3
#define DM_MAX_LINES                         3
#define DM_MAX_SCROLL_TEXT                   3
#define DM_MAX_BUTTONS                       6
#define DM_MAX_PERCENTAGE_BAR                2
#define DM_MAX_PANEL                         1
#else /* !defined(LOW_COST_SUPPORT) */
#define DM_MAX_STRINGS                       2
#define DM_MAX_SUBLCD_STRINGS                1
#define DM_MAX_IMAGES                        1
#define DM_MAX_SUBLCD_IMAGES                 1
#define DM_MAX_FILL_AREAS                    1
#define DM_MAX_RECTANGLES                    2
#define DM_MAX_LINES                         1
#define DM_MAX_SCROLL_TEXT                   1
#define DM_MAX_BUTTONS                       2
#define DM_MAX_PERCENTAGE_BAR                1
#define DM_MAX_PANEL                         1
#endif /* !defined(LOW_COST_SUPPORT) */

#define  DEFAULT_FONT   MAX_FONT_TYPES
#define DM_CALCULATED_HEIGHT  0
#define DM_CALCULATED_WIDTH   0

/* shared coordinate set, to reduce memory usage */
#define DM_DUMMY_COORDINATE                 (-10000)
#define DM_NULL_COORDINATE                  (-10001)
#define DM_FULL_SCREEN_COORDINATE_FLAG      (-10002)
#define DM_FULL_SCREEN_COORDINATE           (-10003)
#define DM_CONTENT_COORDINATE_FLAG          (-10004)
#define DM_CONTENT_COORDINATE               (-10005)
#define DM_POPUP_SCREEN_COORDINATE_FLAG     (-10006)
#define DM_POPUP_SCREEN_COORDINATE          (-10007)
#define DM_DEFAULT_STATUS_BAR_FLAG          (-10008)
#define DM_DEFAULT_STATUS_BAR               (-10009)
#define DM_DEFAULT_TITLE_BAR_FLAG           (-10010)
#define DM_DEFAULT_TITLE_BAR                (-10011)
#define DM_DEFAULT_BUTTON_BAR_FLAG          (-10012)
#define DM_DEFAULT_BUTTON_BAR               (-10013)
#define DM_SUBMENU_CONTENT_COORDINATE_FLAG  (-10014)
#define DM_SUBMENU_CONTENT_COORDINATE       (-10015)
#define DM_COMMON_CONTENT_COORDINATE_FLAG   (-10016)
#define DM_COMMON_CONTENT_COORDINATE        (-10017)
#define DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG   (-10018)
#define DM_DEFAULT_TITLE_LEFT_BUTTON        (-10019)
#define DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG  (-10020)
#define DM_DEFAULT_TITLE_RIGHT_BUTTON       (-10021)
#define DM_EDITOR_CONTENT_COORDINATE_FLAG   (-10022)
#define DM_EDITOR_CONTENT_COORDINATE        (-10023)

/* Global Flags ( Used in category screens for global dm_struct ) */
#define DM_NO_FLAGS                          0x00000000 /* Default flag */
#define DM_NO_SOFTKEY                        0x00000001 /* Softkey is disabled and not displayed */
#define DM_NO_TITLE                          0x00000002 /* Title is disabled and not displayed */
#define DM_NO_STATUS_BAR                     0x00000004 /* Status bar is disabled and not displayed */
#define DM_NO_POPUP_BACKGROUND               0x00000008 /* Popup background is disabled and not displayed */
#define DM_LEFT_ALIGN_TITLE                  0x00000010 /* Title string is left alignment */
#define DM_SCROLL_TITLE                      0x00000020 /* Scroll the title string when needed */
#define DM_CLEAR_SCREEN_BACKGROUND           0x00000040 /* Clear screen background */
#define DM_SHOW_VKPAD                        0x00000080 /* Show virtual keypad */

#define DM_SUB_LCD_CONTEXT                   0x00000100 /* Set sub lcd context */
#define DM_SUB_LCD_TRANSPARENT_BG            0x00000200
#define DM_SUB_LCD_ROTATE_180                0x00000400
#define DM_SPECIFIC_HIDE_STATUS_BAR          0x00000800
#define DM_NO_BLT                            0x00001000
#define DM_LITE_DISP_WALLPAPER               0x00002000
#define DM_USER_DEFINE_ROTATE_BG_IMG         0x00004000 /* Do not use default rotate wallpaper */
#define DM_SET_AS_ABM_LAYER                  0x00008000 /* Set new layer as ABM source layer */
#define DM_SET_NEW_LAYER_ACTIVE              0x00010000 /* Set new layer as acitve layer */
#define DM_CLEAR_SCREEN_BACKGROUND_COLOR     0x00020000 /* Clear screen background with GDI default color */
#define DM_LITE_DISP_WALLPAPER_USER_COLOR    0x00040000 /* Show scr bg user user color */

/* 2009.04.29 added by hongzhe.liu for charger screen background + */
#define DM_POWER_ON_CHARGER_BG_COLOR            0x00000000 
/* 2009.04.29 added by hongzhe.liu for charger screen background - */

//#define DM_NO_STRING                                                          0x00008000
//#define DM_MAIN_LCD_CONTEXT                                                   0x00000020      /* Set Main lcd context */
//#define DM_NO_BUILD_BUFFER                                                    0x00000200

/* Control Specific Flags */
/* One Byte is for control specific flags
   Second Byte is for previous control specific flags (Common Flags ) */

/* title */
#define DM_TITLE_SET_THICK      0x0001

/* 082906 scr_bg */
/* scr_bg */
#define DM_SCR_BG_FORCE_SHOW    0x0001

/* String & Images */
#define DM_LEFT_ALIGN_X			0x0001
#define DM_FORCE_CENTRE_ALIGN_X     0x0001//062706 cat129
#define DM_CENTRE_ALIGN_X     0x0002
#define DM_RIGHT_ALIGN_X      0x0004

#define DM_TOP_ALIGN_Y			0x0008
#define DM_FORCE_CENTER_ALIGN_Y      0x0008
#define DM_CENTER_ALIGN_Y     0x0010
#define DM_BOTTOM_ALIGN_Y     0x0020

#define DM_STRING_BORDERED    0x0040
#define DM_BACK_FILL       0x0080



/* Button Specific Flags */
#define DM_BUTTON_DISABLE_BACKGROUND   0x0001
#define DM_BUTTON_BAR_UP_ARROW         0x0002
#define DM_BUTTON_BAR_DOWN_ARROW       0x0004
#define DM_BUTTON_BAR_LEFT_ARROW       0x0008
#define DM_BUTTON_BAR_RIGHT_ARROW         0x0010

/* Popup Background Specific Flags */
#define DM_DRAW_POPUP_BACKGROUND_3D          0x0001
#define DM_POPUP_BACKGROUND_HATCH_FILL       0x0002
#define DM_POPUP_BACKGROUND_GREYSCALE        0x0004

/* Multiline inputbox Specific Flags */
#define DM_FIXED_MULTILINE_INPUTBOX_HEIGHT   0x0001     /* The height of multiline inputbox is decided by category */
#define DM_FIXED_MULTILINE_INPUTBOX_WIDTH    0x0002     /* The width of multiline inputbox is decided by category */
#define DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP  0x0004

/* Singleline Inputbox Specific Flags */
#define DM_SINGLE_LINE_INPUTBOX_SPECIFIC_HEIGHT 0x0001

/* Alligned Area Specific Flags */
#define DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM      0x0001
#define DM_ALLIGNED_AREA_NO_BACK_FILL              0x0002
#define  DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED   0x0004

/* List Specific Flags */
#define DM_CATEGORY_CONTROL_COORDINATES         0x0001

#define DM_SLIDE_CONTROL_VALUE_POS_NONE      0x0001
#define DM_SLIDE_CONTROL_VALUE_POS_HEAD      0x0002
#define DM_SLIDE_CONTROL_VALUE_POS_TAIL         0x0004
#define DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE    0x0008

#define DM_BUTTON_RIGHT_ALIGN          0x0001

#define DM_SCROLL_TEXT_LEFT_ALIGN_X       0x0001
#define DM_SCROLL_TEXT_CENTRE_ALIGN_X     0x0002
#define DM_SCROLL_TEXT_RIGHT_ALIGN_X      0x0004

#define DM_SCROLL_TEXT_TOP_ALIGN_Y        0x0008
#define DM_SCROLL_TEXT_CENTER_ALIGN_Y     0x0010
#define DM_SCROLL_TEXT_BOTTOM_ALIGN_Y     0x0020
#define DM_SCROLL_TEXT_USE_FONT_HEIGHT    0x0040

/* Common Flags ( used for all components ) */
#define DM_PREVIOUS_CONTROL_END_X               0x0100
#define DM_PREVIOUS_CONTROL_END_Y               0x0200
#define DM_PREVIOUS_CONTROL_END_Y_OFFSET_HEIGHT    0x0400
#define DM_PREVIOUS_CONTROL_END_X_OFFSET_WIDTH     0x0800

#define DM_WIDTH_OFFSET_PREVIOUS_CONTROL_END_X     0x1000
#define DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y    0x2000
#define DM_WIDTH_PREVIOUS_CONTROL_WIDTH            0x4000
#define DM_HEIGHT_PREVIOUS_CONTROL_HEIGHT       0x8000

/* Draw Manager Controls */
typedef enum
{
    DM_BASE_LAYER_START,
    DM_BASE_LAYER_END,
    DM_NEW_LAYER_START,
    DM_NEW_LAYER_END,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET1,
    DM_BASE_CONTROL_SET2,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CIRCULAR_MENU1,
    DM_LIST1,
    DM_ROTATE_MENU1,
    DM_INLINE_FIXED_LIST1,
    DM_MATRIX_MENU1,
    DM_DYNAMIC_LIST1,
    DM_ASYNCDYNAMIC_LIST1,
    DM_SINGLELINE_INPUTBOX1,
    DM_MULTILINE_INPUTBOX1,
    DM_EMS_INPUTBOX1,
    DM_DIALER_INPUT_BOX1,
    DM_TAB_CONTROL,
    DM_HORIZONTAL_TAB_BAR,
    DM_DATE_TIME_DISPLAY,
    DM_TITLE1,
    DM_STATUS_BAR1,
    DM_LSK,
    DM_RSK,
    DM_CSK,
    DM_BUTTON_BAR1,
    DM_BUTTON,
    DM_CALENDAR,
    DM_ALIGNED_AREA_START,
    DM_ALIGNED_AREA_END,
    DM_STRING,
    DM_IMAGE,
    DM_BACK_FILL_AREA,
    DM_RECTANGLE,
    DM_LINE,
    DM_SLIDE_CONTROL,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_POPUP_BACKGROUND,
    DM_NWAY_STOPWATCH,
    DM_TYPICAL_STOPWATCH,
    DM_WALL_PAPER,
    DM_SCROLL_TEXT,
    DM_PERCENTAGE_BAR,
    DM_PANEL,
    DM_CONTROL_TOTAL
} mmi_dm_control_ids_enum;

/* flags used to create layer in draw manager */
typedef enum
{
    DM_LAYER_TOP,
    DM_LAYER_BOTTOM,
    DM_LAYER_ACTIVE_TOP,
    DM_LAYER_ACTIVE_BOTTOM
} mmi_dm_new_layer_flags_enum;

/* flags of title area style */
typedef enum
{
    DM_TITLE_AREA_NORMAL,
    DM_TITLE_AREA_STATUS_ICON_ONLY,
    DM_TITLE_AREA_NONE
} mmi_dm_title_area_type_enum;

/* type of drawing state */
typedef enum
{
    NORMAL_EXIT,    /* Normal procedure: ExitCategory function state */
    NORMAL_SHOW,    /* Normal procedure: Showcategory function state */
    NORMAL_REDRAW,  /* Normal procedure: RedrawCategory function state */
    REDRAW_2_SHOW,  /* Abnormal procedure: ShowCategory function is called without calling ExitCategory function */
    REDRAW_2_REDRAW /* Abnormal procedure: RedrawCategory function is called directly without EixtCategory function and ShowCategory function */
} dm_redraw_state_enum;

/* small screen flatten state */
typedef enum
{
    DM_SMALL_SCREEN_FLATTEN_ON,         /* Flattening to keep the old screen in the main base layer. */
    DM_SMALL_SCREEN_FLATTEN_OFF,        /* No flattening to discard the old screen. */
    DM_SMALL_SCREEN_FLATTEN_FORCE_ON    /* Force flattening on. Used only when going back to a small screen in the history. */
} dm_small_screen_flatten_state_enum;

/* Structures used by Draw Manager */
typedef struct
{
    dm_redraw_state_enum redraw_screen_main;
    U8 redraw_scr_directly;
    U8 redraw_scr_bg_flag;
    U8 lock_redraw_main;
    U8 exit_full_screen_on_exit;
    U8 is_context_reset;
#ifdef __MMI_SUBLCD__
    dm_redraw_state_enum redraw_screen_sub;
    U8 lock_redraw_sub;
#endif /* __MMI_SUBLCD__ */ 
    dm_small_screen_flatten_state_enum enable_small_screen_flatten; /* small screen flatten flag */
} dm_cntx_struct;

typedef struct
{
    GDI_HANDLE layer_handle;
    /* GDI_HANDLE           animation_handle; */
    U16 image_id;
    S8 *image_name;
    U8 is_used;
    MMI_BOOL scr_bg_layer_exist;
    S32 offset_x;
    S32 offset_y;
    U8 layer_opacity;
    S32 flags;//082906 scr_bg
} dm_scr_bg_cntx_struct;

typedef struct
{
    S32 s32ScrId;
    S32 s32CatId;
    S32 s32flags;
} dm_data_struct;

typedef struct
{
    S32 screen_id;
    S16 *coordinate_set_p;
} dm_screen_id_coordinate_set_map_struct;

typedef struct
{
    U16 category_id;
    U8 *control_set_p;
    S16 *default_coordinate_set_p;
    S16 *rotated_coordinate_set_p;
} dm_category_id_control_set_map_struct;

typedef struct
{
    S16 s16X;
    S16 s16Y;
    S16 s16Width;
    S16 s16Height;
    S32 Flags;
} dm_coordinates;

typedef struct
{
    dm_coordinates coordinate;
    S16 s16X2;
    S16 s16Y2;
} dm_previous_control_coordinates_struct;

typedef struct
{
    S16 x1;
    S16 y1;
    S16 x2;
    S16 y2;
    S16 flags;
} dm_cat_scr_info_struct;

typedef struct
{
    S16 x;  /* Icons are offset from this position                */
    S16 y;  /* Icons are offset from this position                */
    S16 x1; /* Area occupied by the status bar: Used for hiding      */
    S16 y1; /* Area occupied by the status bar: Used for hiding      */
    S16 x2; /* Area occupied by the status bar: Used for hiding      */
    S16 y2; /* Area occupied by the status bar: Used for hiding      */
    S16 flags;
} dm_status_info_struct;

typedef struct
{
    dm_coordinates coordinate;
    S16 button_width;
} dm_buttonbar_info_struct;

typedef struct
{
    UI_string_type string;
    UI_font_type font;
    color text_color;
    color border_color;
    UI_filled_area back_fill;
} dm_string_data_struct;

/* START VIJAY PMT 20050930 */
typedef enum
{
    DM_RECTANGLE_NO_FILL = 0,
    DM_RECTANGLE_FILL_COLOR = 1,
    DM_RECTANGLE_FILL_GRAYSCALE = 2
} dm_rectangle_fill_style;

typedef struct
{
    color line_color;
    dm_rectangle_fill_style fill_rectangle;
} dm_rectangle_data_struct;

/* END VIJAY PMT 20050930 */

typedef struct
{
    S16 x, y;
    S32 width, height;
    PU8 image;
    UI_string_type name;
    UI_filled_area *back_fill;
    gdi_handle image_handle;
} dm_image_data_struct;


typedef struct
{
    S16 s16X;
    S16 s16Y;
    S16 s16width;
    S16 s16height;
    U16 x_space;
    U16 y_space;
    S32 Flags;
    MMI_BOOL is_in_aligned_area;
} dm_aligned_area_data_struct;

typedef struct
{
    dm_coordinates coordinate;
    S16 typ_timer_x;
    S16 typ_timer_y;
    S16 typ_milsec_x;
    S16 typ_milsec_y;
    S16 typ_history_height;
} dm_typical_stopwatch_info_struct;

typedef struct
{
    dm_coordinates coordinate;
    S16 nway_main_timer_x1;
    S16 nway_main_timer_y1;
    S16 nway_main_timer_x2;
    S16 nway_main_timer_y2;
    S16 nway_dialog_x1;
    S16 nway_dialog_y1;
    S16 nway_dialog_x2;
    S16 nway_dialog_y2;
    S16 separator_height;
} dm_nway_stopwatch_info_struct;

typedef struct
{
    S16 x;
    S16 y;
    S16 width;
    S16 height;
    U16 value;
    color bar_color;
    U16 bg_image;
    U16 left_side_image;
    U16 right_side_image;
    U8  *progres_string;
} dm_percentage_bar_struct;

extern const S16 g_screenid_coordinate_sets_map_entries_count;
extern dm_data_struct g_dm_data, g_dm_sublcd_data;
extern const dm_category_id_control_set_map_struct g_categories_controls_map[];
extern const dm_screen_id_coordinate_set_map_struct g_screenid_coordinate_sets_map[];

extern void dm_init(void);
extern void dm_reset_context(void);
extern void dm_reset_context_ext(void);

#ifdef __MMI_SUBLCD__
extern void dm_reset_sublcd_context(void);
#endif 
extern U16 dm_get_image_count(void);
extern U16 dm_get_button_count(void);
extern icontext_button *dm_get_button(U16 index);
extern void dm_reset_button_functions(void);

extern void dm_set_scr_bg_redraw(MMI_BOOL status);
extern MMI_BOOL dm_is_activated(void);
extern void dm_setup_data(dm_data_struct *dm_data);
extern void dm_redraw_category_screen(void);
void dm_setup_category_functions(FuncPtr redraw_function, U8 *(*get_history_function) (U8 *buffer),
                                 S32(*get_history_size_function) (void));
extern U8 *dm_search_control_set(S32 category_id, S16 **default_coordinate_set_p);
extern S16 *dm_search_coordinate_set(S32 ScrId);
extern S16 *dm_get_cat_scr_coordinates(S16 *UICtrlAccessPtr_p, dm_cat_scr_info_struct *dm_cat_scr_info);
extern MMI_BOOL dm_check_control_exist(S32 category_id, mmi_dm_control_ids_enum control_id);

extern void dm_update_multitap_coordinates(
                dm_coordinates *dm_multiline_inputbox_info,
                dm_cat_scr_info_struct *dm_cat_scr_info);
extern S16 *dm_get_status_icon_bar_coordinates(S16 *UICtrlAccessPtr_p, dm_status_info_struct *dm_status_info);
extern S16 *dm_get_button_bar_coordinates(S16 *UICtrlAccessPtr_p, dm_buttonbar_info_struct *dm_status_info);

extern U8 *dm_get_category_history(U8 *history_buffer);
extern S32 dm_get_category_history_size(void);

/* Reset functions for the coordinates of the controls so that other category screens get the original values only. */
extern void dm_reset_title_coordinates(void);
extern void dm_reset_fixed_list_coordinates(void);
extern void dm_reset_lsk_coordinates(void);
extern void dm_reset_rsk_coordinates(void);
extern void dm_reset_button_bar_coordinates(void);
extern void dm_reset_multitaps_coordinates(void);
extern void dm_reset_inline_fixed_list_coordinates(void);

#ifdef __MMI_SUBLCD__
void dm_register_sub_category_controlled_callback(void (*f) (dm_coordinates *coordinate));
extern void dm_reset_sub_category_controlled_callback(void);
#endif /* __MMI_SUBLCD__ */ 
void dm_register_category_controlled_callback(void (*f) (dm_coordinates *coordinate));
void dm_register_category_controlled2_callback(void (*f) (dm_coordinates *coordinate));
extern void dm_reset_category_controlled_callback(void);

extern void dm_move_control_without_layer(S16 *comp_x, S16 *comp_y);

extern S32 dm_setup_new_layer(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_circular_menu(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_fixed_list(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_dynamic_list(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_matrix_menu(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_multiline_inputbox(S16 **UICtrlAccessPtr_p, dm_cat_scr_info_struct *dm_cat_scr_info);
extern S32 dm_setup_and_draw_ems_inputbox(S16 **UICtrlAccessPtr_p, dm_cat_scr_info_struct *dm_cat_scr_info);
extern S32 dm_setup_and_draw_dialer_inputbox(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_singleline_inputbox(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_left_softkey(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_right_softkey(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_title(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_category_controlled_area(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_status_icons(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_button_bar(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_inline_item(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_base_control_set(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_base_control_set2(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_base_control_submenu(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_base_control_common(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_string(S16 **UICtrlAccessPtr_p, S32 index);
extern S32 dm_setup_and_draw_image(S16 **UICtrlAccessPtr_p, S32 index);
extern S32 dm_setup_and_draw_slide_control(S16 **UICtrlAccessPtr_p, S32 index);
extern S32 dm_setup_and_draw_aligned_area(S16 **UICtrlAccessPtr_p, U8 *control_set_ptr);
extern S32 dm_setup_and_draw_scroll_text(S16 **UICtrlAccessPtr_p, S32 index);
extern S32 dm_setup_and_draw_scr_bg(S16 **UICtrlAccessPtr_p);
extern S32 dm_setup_and_draw_button(S16 **UICtrlAccessPtr_p, S32 index);
extern S32 dm_setup_and_draw_panel(S16 **UICtrlAccessPtr_p, S32 count);
extern void dm_register_vkpad_callback(FuncPtr f);

extern GDI_HANDLE dm_get_wallpaper_layer(void);
extern S32 dm_setup_and_draw_scr_bg(S16 **UICtrlAccessPtr_p);
extern void dm_set_scr_bg_image(U16 image_id, S8 *file_name, S32 x, S32 y, U8 opacity);
extern void dm_set_scr_bg_image_no_draw(U16 image_id, S8 *file_name, S32 x, S32 y, U8 opacity);
extern void dm_set_scr_bg_lite_color(gdi_color lite_color);
extern void dm_get_scr_bg_image(U16 *image_id, S8 **file_name, S32 *x, S32 *y, U8 *opacity);
extern GDI_HANDLE dm_get_scr_bg_layer(void);
extern void dm_set_scr_bg_redraw(MMI_BOOL status);
extern void dm_get_scr_bg_opacity(U8 *opacity);
extern void dm_set_scr_bg_opacity(U8 opacity);
extern void dm_get_scr_bg_flag(S32 *flags);//082906 scr_bg
extern void dm_set_scr_bg_flag(S32 flags);

extern void dm_add_title(UI_string_type text, PU8 icon);
extern void dm_add_softkey(UI_string_type lsk_text, PU8 lsk_icon, UI_string_type rsk_text, PU8 rsk_icon);
extern void dm_add_image(PU8 image, UI_string_type image_name, UI_filled_area *background);
extern gdi_handle dm_get_image_handle(S32 count);//070706
extern void dm_change_image(PU8 image, UI_string_type name, S32 index);
extern void dm_add_string(
                UI_string_type string,
                UI_font_type font,
                color text_color,
                color border_color,
                UI_filled_area *background);
extern void dm_reset_str_image(void);

/* START VIJAY PMT 20050930 */
extern void dm_add_rectangle(color line_color, dm_rectangle_fill_style fill_rectangle);

/* END VIJAY PMT 20050930 */
extern void dm_add_line(color line_color);
extern void dm_add_back_fill_area(UI_filled_area *background);
void dm_add_scroll_text(UI_string_type text, void (*timer_callback) (void),
                        void (*draw_background) (S32 x1, S32 y1, S32 x2, S32 y2), color text_color, color border_color);
void dm_add_slide_control(S32 lower_limit, S32 upper_limit, S32 current_value, void (*change_callback) (S32 value),
                          U8 *label_string);
extern S32 dm_get_slide_control_count(void);
extern U16 dm_add_button(UI_string_type text, PU8 up_image, PU8 down_image, gui_button_clear_background_hdlr clear_fp);
extern U16 dm_add_percentage_bar(
            U16 init_value,
            U8 *string,
            color bar_color,
            U16 bg_image,
            U16 left_side_image,
            U16 right_side_image);
extern void dm_update_percentage_bar_value(S32 id, U16 value, U8 *string);
extern void dm_redraw_percentage_bar(S32 id);
extern void dm_change_percentage_bar_color(S32 id, color c);
extern S32 dm_add_panel(
        S32 x, 
        S32 y, 
        S32 width, 
        S32 height, 
        gui_util_painter_struct background,
        MMI_BOOL display_focus,
        U32 repeat_period);
extern S32 dm_add_panel_element(
        S32 panel_handle,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U16 keycode,
        FuncPtr down_event_callback,
        FuncPtr up_event_callback,
        FuncPtr repeat_event_callback,
        gui_util_painter_struct normal_painter,
        gui_util_painter_struct focussed_painter,
        gui_util_painter_struct down_painter,
        gui_util_painter_struct disable_painter,
        MMI_BOOL redraw_bg_after_state_changed);

extern void dm_set_panel_enable_element(S32 panel_handle, S32 elem_idx, MMI_BOOL enabled, MMI_BOOL update_display);
extern void dm_set_panel_element_focus(
        S32 panel_handle,
        S32 element_index,
        MMI_BOOL update_display);
extern S32 dm_get_panel_element_focus(S32 panel_handle);
extern S32 dm_get_panel_count(void);
extern S32 dm_register_panel_keys(S32 panel_handle, FuncPtr handler);
extern gui_panel_struct* dm_get_panel(S32 panel_handle);

extern void dm_get_control_coordinates_from_category(
                S32 s32ScrId,
                S32 s32CatId,
                mmi_dm_control_ids_enum control,
                S32 index,
                dm_coordinates *coordinate);
extern void setup_previous_control(dm_coordinates *dm_coordinate_info);
extern void dm_sublcd_setup_data(dm_data_struct *dm_data);
extern void dm_sublcd_redraw_category_screen(void);
extern S16 *dm_get_typical_stopwatch_coordinates(
                S16 *UICtrlAccessPtr_p,
                dm_typical_stopwatch_info_struct *dm_typical_stopwatch_info);
extern S16 *dm_get_nway_stopwatch_coordinates(
                S16 *UICtrlAccessPtr_p,
                dm_nway_stopwatch_info_struct *dm_nway_stopwatch_info);

extern gdi_result dm_create_layer(S32 x, S32 y, S32 width, S32 height, gdi_handle *handle_ptr, U32 flags);
extern gdi_result dm_create_layer_using_outside_memory(
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    gdi_handle **handle_ptr,
                    U8 *outside_memory,
                    S32 outside_memory_size,
                    U32 flags);
extern MMI_BOOL dm_add_blt_layer(gdi_handle handle_ptr, U32 flags);

extern void dm_register_button_functions(U16 button_index, U16 key_type, FuncPtr f);
extern void dm_execute_button_handler(U16 btn_index, U16 key_type);

extern GDI_HANDLE dm_get_layer_handle(U8 index);
extern GDI_HANDLE *dm_get_layer_handle_ptr(U8 index);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL dm_check_image_bound(U16 index, mmi_pen_point_struct point);
#endif 

extern MMI_BOOL dm_is_redraw_screen(void);
#endif /* __MMI_DRAW_MANAGER__ */ 

extern void dm_register_wallpaper_anim_update_callback(FuncPtr f);

/* small screen flatten */
extern void dm_disable_small_screen_flatten(void);
extern void dm_enable_small_screen_flatten(void);
extern void dm_force_small_screen_flatten(void);
extern void dm_unforce_small_screen_flatten(void);

extern void dm_set_dm_data_flag(S32 flag);
extern void dm_get_dm_data_flag(S32* flag);
#endif /* __WGUI_DRAW_MANAGER_H__ */ 

