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
 * wgui_datetime.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for datetime screen control.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

 /*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

/**********************************************************************************
   Filename:      wgui_datetime.h
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines header for Date and Time input / display
**********************************************************************************/

#ifndef __WGUI_DATETIME_H__
#define __WGUI_DATETIME_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "globalconstants.h"
#include "DateTimeType.h"
#include "wgui.h"
#include "Ucs2prot.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 

#define WGUI_DATE_TIME_INPUT_FOCUS_NONE         0
#define WGUI_DATE_TIME_INPUT_FOCUS_DAY       1
#define WGUI_DATE_TIME_INPUT_FOCUS_MONTH     2
#define WGUI_DATE_TIME_INPUT_FOCUS_YEAR         3
#define WGUI_DATE_TIME_INPUT_FOCUS_HOURS     4
#define WGUI_DATE_TIME_INPUT_FOCUS_MINUTES      5
#define WGUI_DATE_TIME_INPUT_FOCUS_SECONDS      6
#define WGUI_DATE_TIME_INPUT_FOCUS_AM_PM     7

    extern single_line_input_box wgui_date_input_day;
    extern single_line_input_box wgui_date_input_month;
    extern single_line_input_box wgui_date_input_year;
    extern single_line_input_box wgui_time_input_hours;
    extern single_line_input_box wgui_time_input_minutes;
    extern single_line_input_box wgui_time_input_seconds;
    extern single_line_input_box wgui_time_input_AM_PM;
    extern single_line_input_box *wgui_date_time_input_object_focus;

    extern void wgui_set_day_input_navigation(U8 previous_focus, U8 next_focus);
    extern void wgui_set_month_input_navigation(U8 previous_focus, U8 next_focus);
    extern void wgui_set_year_input_navigation(U8 previous_focus, U8 next_focus);
    extern void wgui_set_hours_input_navigation(U8 previous_focus, U8 next_focus);
    extern void wgui_set_minutes_input_navigation(U8 previous_focus, U8 next_focus);
    extern void wgui_set_seconds_input_navigation(U8 previous_focus, U8 next_focus);
    extern void wgui_set_AM_PM_input_navigation(U8 previous_focus, U8 next_focus);
    extern void wgui_show_date_input(void);
    extern void wgui_show_time_input(void);
    extern void wgui_show_date_time_input(void);
    extern void wgui_initialize_date_input(
                    UI_buffer_type day_buffer,
                    S32 day_buffer_length,
                    UI_buffer_type month_buffer,
                    S32 month_buffer_length,
                    UI_buffer_type year_buffer,
                    S32 year_buffer_length);
    extern void wgui_initialize_time_input(
                    UI_buffer_type hours_buffer,
                    S32 hours_buffer_length,
                    UI_buffer_type minutes_buffer,
                    S32 minutes_buffer_length,
                    UI_buffer_type seconds_buffer,
                    S32 seconds_buffer_length);
    extern void wgui_reset_date_input(void);
    extern void wgui_reset_time_input(void);
    extern void wgui_move_day_input(S32 x, S32 y);
    extern void wgui_resize_day_input(S32 width, S32 height);
    extern void wgui_move_month_input(S32 x, S32 y);
    extern void wgui_resize_month_input(S32 width, S32 height);
    extern void wgui_move_year_input(S32 x, S32 y);
    extern void wgui_resize_year_input(S32 width, S32 height);
    extern void wgui_move_hours_input(S32 x, S32 y);
    extern void wgui_resize_hours_input(S32 width, S32 height);
    extern void wgui_move_minutes_input(S32 x, S32 y);
    extern void wgui_resize_minutes_input(S32 width, S32 height);
    extern void wgui_move_seconds_input(S32 x, S32 y);
    extern void wgui_resize_seconds_input(S32 width, S32 height);
    extern void wgui_move_AM_PM_input(S32 x, S32 y);
    extern void wgui_resize_AM_PM_input(S32 width, S32 height);
    extern void wgui_enable_seconds_input(void);
    extern void wgui_disable_seconds_input(void);
    extern void wgui_enable_AM_PM_input(void);
    extern void wgui_disable_AM_PM_input(void);
    extern void wgui_date_time_input_set_object_focus(single_line_input_box *b);
    extern void wgui_date_time_input_remove_object_focus(single_line_input_box *b);
    extern void wgui_date_time_input_set_focus(U8 focus);
    extern void wgui_date_time_input_remove_focus(U8 focus);
    extern void wgui_date_time_input_set_previous_focus(void);
    extern void wgui_date_time_input_set_next_focus(void);
    extern U8 wgui_date_time_input_get_previous_focus(void);
    extern U8 wgui_date_time_input_get_next_focus(void);
    extern void wgui_redraw_date_time_input(void);
    extern void wgui_date_time_direct_input(UI_character_type c);
    extern void wgui_date_time_delete_character(void);
    extern void wgui_date_time_previous_character(void);
    extern void wgui_date_time_next_character(void);
    extern void wgui_date_time_toggle_insert_mode(void);
    extern void wgui_date_time_delete_current_character(void);
    extern void wgui_date_time_delete_all_characters(void);
    extern void wgui_date_time_numeric_keyboard_input_handler(S32 keyc);
    extern void wgui_date_time_handle_key_down(MMI_key_code_type k);
    extern void wgui_date_time_key_handler(S32 vkey_code, S32 key_state);
    extern void wgui_date_time_input_register_keys(void);
    void register_wgui_date_time_input_callback(void (*f) (void));
    extern void clear_wgui_date_time_input_callback(void);
    extern void wgui_date_time_input_clear_keys(void);

    /* Date and time display   */

    extern void UI_dummy_hide_function(S32 x1, S32 y1, S32 x2, S32 y2);

    typedef enum _DT_DISPLAY_TYPE
    {
        DT_IDLE_SCREEN,
        DT_IDLE_SCREEN_2,
        DT_MO_CALL_SCREEN,
        DT_MO_CALLING_SCREEN,
        DT_ACTIVE_CALL_SCREEN,
        DT_TABBED_CALL_SCREEN,
        DT_MT_CALL_SCREEN,
        DT_NETWORK_SEARCH,
        DT_SUBLCD_IDLE_SCREEN1,
        DT_SUBLCD_IDLE_SCREEN2,
        DT_SUBLCD_IDLE_SCREEN3,
        DT_SUBLCD_IDLE_SCREEN4,
        DT_DIGITAL_CLOCK_SC1,
        DT_DIGITAL_CLOCK_SC2,
        DT_DIGITAL_CLOCK_SC3,
        DT_ANALOG_CLOCK_SC,
        DT_AUDIO_PLAY_DURATION,
        DT_GPRS_ACTIVE_CALL,
        DT_GPRS_CONF_CALL,
        DT_FILEMANAGER,
        DT_SUBLCD_ANALOG_CLOCK,
        DT_IDLE_SCREEN_ENGLISH_ONLY,
        DT_VOIP_CALL_SCREEN
    } DT_DISPLAY_TYPE;

    typedef struct _UI_date_time
    {
        UI_time t;
        S32 x;
        S32 y;
        S32 width;
        S32 height;
        UI_font_type font;
        color text_color;
        color text_border_color;
        U32 flags;
        void (*hide_function) (S32 x1, S32 y1, S32 x2, S32 y2);

    } UI_date_time;

    typedef struct _UI_date_time_display
    {
        UI_date_time date;
        UI_date_time time;
        UI_date_time duration;
        U32 flags;

    } UI_date_time_display;

    extern void (*MMI_main_LCD_dt_hide_function) (void);
    extern void (*MMI_main_LCD_dt_update_function) (void);
    extern void (*MMI_main_LCD_dt_display_function) (void);
    extern void (*MMI_main_LCD_dt_close_function) (void);
    extern void (*MMI_sub_LCD_dt_hide_function) (void);
    extern void (*MMI_sub_LCD_dt_update_function) (void);
    extern void (*MMI_sub_LCD_dt_display_function) (void);
    extern void (*MMI_sub_LCD_dt_close_function) (void);

    extern void update_mainlcd_dt_display(void);
    extern void update_sublcd_dt_display(void);
    extern void show_main_LCD_dt_display(void);
    extern void show_sub_LCD_dt_display(void);

    extern UI_date_time_display main_LCD_dt_object;
    extern UI_date_time_display sub_LCD_dt_object1;
    extern UI_date_time_display sub_LCD_dt_object2;

    extern FLOAT dt_difference1;
    extern FLOAT dt_difference2;

    void set_main_LCD_dt_date_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
    void set_main_LCD_dt_time_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
    void set_main_LCD_dt_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
    void set_sub_LCD_dt_date_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
    void set_sub_LCD_dt_time_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
    void set_sub_LCD_dt_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
    extern void set_dt_display(U32 flags);
    extern void set_dt_update_function(void);
    extern void close_main_LCD_dt_display(void);
    extern void close_sub_LCD_dt_display(void);
    extern void set_dt_duration(UI_time *t);
    extern void date_string(UI_time *t, UI_string_type s, U32 flags);
    extern void time_string(UI_time *t, UI_string_type s, U32 flags);
    extern void duration_string(UI_time *t, UI_string_type s, U32 flags);

    extern void main_LCD_measure_time_duration_string(S32 *w, S32 *h);
    

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    typedef enum
    {
        ANALOG,
        DIGITAL
    } MMI_CLOCK_TYPE;

    extern void wgui_set_clock_type(U8 clock_type);

    void set_main_LCD_day_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
    extern void set_day_display(void);
    extern void show_main_LCD_day_display(void);
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

    /* Date input object */

#define DATE_INPUT_MAX_FOCUS              8
#if defined(__MMI_MAINLCD_240X320__)
#define DATE_INPUT_HEIGHT                 22
#define DATE_INPUT_DAY_WIDTH              26
#define DATE_INPUT_MONTH_WIDTH               26
#define DATE_INPUT_YEAR_WIDTH             46
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define DATE_INPUT_HEIGHT                 16
#define DATE_INPUT_DAY_WIDTH              22
#define DATE_INPUT_MONTH_WIDTH               22
#define DATE_INPUT_YEAR_WIDTH             38
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#define DATE_INPUT_SEPERATOR_WIDTH           0
#define DATE_INPUT_DAY_BUFFER_LENGTH         (3*ENCODING_LENGTH)
#define DATE_INPUT_MONTH_BUFFER_LENGTH       (3*ENCODING_LENGTH)
#define DATE_INPUT_YEAR_BUFFER_LENGTH        (5*ENCODING_LENGTH)

#define DATE_INPUT_FOCUS_NONE             0
#define DATE_INPUT_FOCUS_DAY              1
#define DATE_INPUT_FOCUS_MONTH               2
#define DATE_INPUT_FOCUS_YEAR             3

#define DATE_INPUT_TYPE_DD_MM_YYYY           0x00000001
#define DATE_INPUT_TYPE_MM_DD_YYYY           0x00000002
#define DATE_INPUT_TYPE_YYYY_MM_DD           0x00000003
#define DATE_INPUT_TYPE_MASK              0x000000FF
#define DATE_INPUT_TYPE_DEFAULT_FOCUS_DAY    0x00000100
#define DATE_INPUT_TYPE_DEFAULT_FOCUS_MONTH     0x00000200
#define DATE_INPUT_TYPE_DEFAULT_FOCUS_YEAR      0x00000300
#define DATE_INPUT_TYPE_DEFAULT_FOCUS_MASK      0x0000FF00
#define DATE_INPUT_JUSTIFY_MASK              0x00030000
#define DATE_INPUT_LEFT_JUSTIFY              0x00000000
#define DATE_INPUT_RIGHT_JUSTIFY          0x00010000
#define DATE_INPUT_CENTER_JUSTIFY            0x00020000

    typedef struct _date_input
    {
        S32 x, y;
        S32 width, height;
        S32 offset_x, offset_y;
        single_line_input_box day_input_box;
        single_line_input_box month_input_box;
        single_line_input_box year_input_box;
        single_line_input_box *focus_input_box;
        U32 flags;
        U32 focus_list[DATE_INPUT_MAX_FOCUS];
        U32 current_focus;
        UI_character_type seperator;
        S32 day_x, day_y;
        S32 month_x, month_y;
        S32 year_x, year_y;
        S32 s1_x, s1_y;
        S32 s2_x, s2_y;

    } date_input;

    extern void date_input_show_background(date_input *d);
    extern void date_input_reset_focus(date_input *d);
    extern void date_input_set_focus(date_input *d);
    extern void date_input_set_default_focus(date_input *d);
    extern void create_date_input(
                    date_input *d,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 flags,
                    UI_buffer_type day_buffer,
                    UI_buffer_type month_buffer,
                    UI_buffer_type year_buffer);
    extern void show_date_input(date_input *d);
    extern U8 date_input_set_next_focus(date_input *d);
    extern U8 date_input_set_previous_focus(date_input *d);
    extern void date_input_set_seperator(date_input *d, UI_character_type seperator);

    extern date_input *current_date_input;
    extern void (*current_date_input_callback) (void);

    extern void set_current_date_input(date_input *d);
    extern void date_input_direct_input(UI_character_type c);
    extern void date_input_delete_character(void);
    extern void date_input_previous_character(void);
    extern void date_input_next_character(void);
    extern void date_input_toggle_insert_mode(void);
    extern void date_input_delete_current_character(void);
    extern void date_input_delete_all_characters(void);
    extern void date_input_numeric_keyboard_input_handler(S32 keyc);
    extern void date_input_handle_key_down(MMI_key_code_type k);
    extern void date_input_key_handler(S32 vkey_code, S32 key_state);
    extern void date_input_register_keys(void);
    extern void date_input_clear_keys(void);
    void register_date_input_callback(void (*f) (void));
    extern void clear_date_input_callback(void);

    /* Time input object */

#define TIME_INPUT_MAX_FOCUS              8
#if defined(__MMI_MAINLCD_240X320__)
#define TIME_INPUT_HEIGHT                 22
#define TIME_INPUT_HOURS_WIDTH               26
#define TIME_INPUT_MINUTES_WIDTH          26
#define TIME_INPUT_SECONDS_WIDTH          26
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define TIME_INPUT_HEIGHT                 16
#define TIME_INPUT_HOURS_WIDTH               22
#define TIME_INPUT_MINUTES_WIDTH          22
#define TIME_INPUT_SECONDS_WIDTH          22
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#define TIME_INPUT_SEPERATOR_WIDTH           0
#define TIME_INPUT_HOURS_BUFFER_LENGTH       (3*ENCODING_LENGTH)
#define TIME_INPUT_MINUTES_BUFFER_LENGTH     (3*ENCODING_LENGTH)
#define TIME_INPUT_SECONDS_BUFFER_LENGTH     (3*ENCODING_LENGTH)

#define TIME_INPUT_FOCUS_NONE             0
#define TIME_INPUT_FOCUS_HOURS               1
#define TIME_INPUT_FOCUS_MINUTES          2
#define TIME_INPUT_FOCUS_SECONDS          3

#define TIME_INPUT_TYPE_HH_MM             0x00000001
#define TIME_INPUT_TYPE_HH_MM_SS          0x00000002
#define TIME_INPUT_TYPE_MASK              0x000000FF
#define TIME_INPUT_TYPE_DEFAULT_FOCUS_HOURS     0x00000100
#define TIME_INPUT_TYPE_DEFAULT_FOCUS_MINUTES   0x00000200
#define TIME_INPUT_TYPE_DEFAULT_FOCUS_SECONDS   0x00000300
#define TIME_INPUT_TYPE_DEFAULT_FOCUS_MASK      0x0000FF00
#define TIME_INPUT_JUSTIFY_MASK              0x00030000
#define TIME_INPUT_LEFT_JUSTIFY              0x00000000
#define TIME_INPUT_RIGHT_JUSTIFY          0x00010000
#define TIME_INPUT_CENTER_JUSTIFY            0x00020000

    typedef struct _time_input
    {
        S32 x, y;
        S32 width, height;
        S32 offset_x, offset_y;
        single_line_input_box hours_input_box;
        single_line_input_box minutes_input_box;
        single_line_input_box seconds_input_box;
        single_line_input_box *focus_input_box;
        U32 flags;
        U32 focus_list[TIME_INPUT_MAX_FOCUS];
        U32 current_focus;
        UI_character_type seperator;
        S32 hours_x, hours_y;
        S32 minutes_x, minutes_y;
        S32 seconds_x, seconds_y;
        S32 s1_x, s1_y;
        S32 s2_x, s2_y;

    } time_input;

    extern void time_input_show_background(time_input *d);
    extern void time_input_reset_focus(time_input *d);
    extern void time_input_set_focus(time_input *d);
    extern void time_input_set_default_focus(time_input *d);
    extern void create_time_input(
                    time_input *d,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 flags,
                    UI_buffer_type hours_buffer,
                    UI_buffer_type minutes_buffer,
                    UI_buffer_type seconds_buffer);
    extern void show_time_input(time_input *d);
    extern U8 time_input_set_next_focus(time_input *d);
    extern U8 time_input_set_previous_focus(time_input *d);
    extern void time_input_set_seperator(time_input *d, UI_character_type seperator);

    extern time_input *current_time_input;
    extern void (*current_time_input_callback) (void);

    extern void set_current_time_input(time_input *d);
    extern void time_input_direct_input(UI_character_type c);
    extern void time_input_delete_character(void);
    extern void time_input_previous_character(void);
    extern void time_input_next_character(void);
    extern void time_input_toggle_insert_mode(void);
    extern void time_input_delete_current_character(void);
    extern void time_input_delete_all_characters(void);
    extern void time_input_numeric_keyboard_input_handler(S32 keyc);
    extern void time_input_handle_key_down(MMI_key_code_type k);
    extern void time_input_key_handler(S32 vkey_code, S32 key_state);
    extern void time_input_register_keys(void);
    extern void time_input_clear_keys(void);
    void register_time_input_callback(void (*f) (void));
    extern void clear_time_input_callback(void);

    /* Day of Week select object  */

#ifdef __MMI_MAINLCD_240X320__
#define DOW_CELL_WIDTH        17
#elif __MMI_MAINLCD_128X160__
#define DOW_CELL_WIDTH        12
#else 
#define DOW_CELL_WIDTH        13
#endif 
#define DOW_CELL_HEIGHT       18
#define DOW_CELL_GAP       1

#ifdef __MMI_TOUCH_SCREEN__

    typedef enum
    {
        DOW_PEN_NONE,
        DOW_PEN_TOGGLE_CURRENT_ITEM,
        DOW_PEN_CHANGE_HIGHLIGHT_AND_TOGGLE_I
    } DOW_pen_event_enum;

#endif /* __MMI_TOUCH_SCREEN__ */ 

    typedef struct _DOW_select
    {
        S32 x, y;
        S32 width, height;
        S32 cell_width, cell_height;
        U8 states[8];
        S32 highlighted_cell;
        UI_filled_area *background_filler;
        UI_filled_area *normal_cell_filler;
        UI_filled_area *normal_highlighted_cell_filler;
        UI_filled_area *selected_highlighted_cell_filler;
        UI_filled_area *selected_cell_filler;
        color normal_text_color;
        color normal_highlighted_text_color;
        color selected_highlighted_text_color;
        color selected_text_color;
        S32 offset_x, offset_y;
        S32 cell_gap;
        UI_font_type text_font;
        U32 flags;
    } DOW_select;

    extern void create_DOW_select(DOW_select *d, S32 x, S32 y, S32 width, S32 height);
    extern void set_DOW_select_states(DOW_select *d, U8 states[]);
    extern void set_DOW_select_list_menu_theme(DOW_select *d);
    extern void show_DOW_select(DOW_select *d);
    extern void show_DOW_select_background(DOW_select *d);
    extern void DOW_select_previous(DOW_select *d);
    extern void DOW_select_next(DOW_select *d);
    extern void DOW_select_toggle_item(DOW_select *d);
    extern void DOW_select_highlight_item(DOW_select *d, S32 i);
#ifdef __MMI_TOUCH_SCREEN__
    extern BOOL DOW_translate_pen_event(
                    DOW_select *d,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    DOW_pen_event_enum *DOW_event,
                    gui_pen_event_param_struct *DOW_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* Time period input object   */

#define TIME_PERIOD_INPUT_MAX_FOCUS                8
#if defined(__MMI_MAINLCD_240X320__)
#define TIME_PERIOD_INPUT_HEIGHT                22
#define TIME_PERIOD_INPUT_HOURS_WIDTH              26
#define TIME_PERIOD_INPUT_MINUTES_WIDTH               26
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define TIME_PERIOD_INPUT_HEIGHT                16
#define TIME_PERIOD_INPUT_HOURS_WIDTH              22
#define TIME_PERIOD_INPUT_MINUTES_WIDTH               22
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#define TIME_PERIOD_INPUT_SEPERATOR_WIDTH1            0
#define TIME_PERIOD_INPUT_SEPERATOR_WIDTH2            12
#define TIME_PERIOD_INPUT_HOURS_BUFFER_LENGTH         (3*ENCODING_LENGTH)
#define TIME_PERIOD_INPUT_MINUTES_BUFFER_LENGTH       (3*ENCODING_LENGTH)

#define TIME_PERIOD_INPUT_FOCUS_NONE               0
#define TIME_PERIOD_INPUT_FOCUS_HOURS1             1
#define TIME_PERIOD_INPUT_FOCUS_MINUTES1           2
#define TIME_PERIOD_INPUT_FOCUS_HOURS2             3
#define TIME_PERIOD_INPUT_FOCUS_MINUTES2           4

#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS1      0x00000100
#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MINUTES1 0x00000200
#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS2      0x00000300
#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MINUTES2 0x00000400
#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MASK     0x0000FF00
#define TIME_PERIOD_INPUT_JUSTIFY_MASK             0x00030000
#define TIME_PERIOD_INPUT_LEFT_JUSTIFY             0x00000000
#define TIME_PERIOD_INPUT_RIGHT_JUSTIFY               0x00010000
#define TIME_PERIOD_INPUT_CENTER_JUSTIFY           0x00020000

    typedef struct _time_period_input
    {
        S32 x, y;
        S32 width, height;
        S32 offset_x, offset_y;
        single_line_input_box hours_input_box1;
        single_line_input_box minutes_input_box1;
        single_line_input_box hours_input_box2;
        single_line_input_box minutes_input_box2;
        single_line_input_box *focus_input_box;
        U32 flags;
        U32 focus_list[TIME_PERIOD_INPUT_MAX_FOCUS];
        U32 current_focus;
        UI_character_type seperator1;
        UI_character_type seperator2;
        S32 hours1_x, hours1_y;
        S32 s1_x, s1_y;
        S32 minutes1_x, minutes1_y;
        S32 s2_x, s2_y;
        S32 hours2_x, hours2_y;
        S32 s3_x, s3_y;
        S32 minutes2_x, minutes2_y;

    } time_period_input;

    extern void time_period_input_show_background(time_period_input *d);
    extern void time_period_input_reset_focus(time_period_input *d);
    extern void time_period_input_set_focus(time_period_input *d);
    extern void time_period_input_set_default_focus(time_period_input *d);
    extern void create_time_period_input(
                    time_period_input *d,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 flags,
                    UI_buffer_type hours_buffer1,
                    UI_buffer_type minutes_buffer1,
                    UI_buffer_type hours_buffer2,
                    UI_buffer_type minutes_buffer2);
    extern void show_time_period_input(time_period_input *d);
    extern U8 time_period_input_set_next_focus(time_period_input *d);
    extern U8 time_period_input_set_previous_focus(time_period_input *d);
    extern void time_period_input_set_seperators(
                    time_period_input *d,
                    UI_character_type seperator1,
                    UI_character_type seperator2);

    extern time_period_input *current_time_period_input;
    extern void (*current_time_period_input_callback) (void);

    extern void set_current_time_period_input(time_period_input *d);
    extern void time_period_input_direct_input(UI_character_type c);
    extern void time_period_input_delete_character(void);
    extern void time_period_input_previous_character(void);
    extern void time_period_input_next_character(void);
    extern void time_period_input_toggle_insert_mode(void);
    extern void time_period_input_delete_current_character(void);
    extern void time_period_input_delete_all_characters(void);
    extern void time_period_input_numeric_keyboard_input_handler(S32 keyc);
    extern void time_period_input_handle_key_down(MMI_key_code_type k);
    extern void time_period_input_key_handler(S32 vkey_code, S32 key_state);
    extern void time_period_input_register_keys(void);
    extern void time_period_input_clear_keys(void);
    void register_time_period_input_callback(void (*f) (void));
    extern void clear_time_period_input_callback(void);

    /* Time IP4 input object   */

#define IP4_INPUT_MAX_FOCUS                  8
#if defined(__MMI_MAINLCD_240X320__)
#define IP4_INPUT_HEIGHT                  22
#define IP4_INPUT_FIELD_WIDTH             36
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define IP4_INPUT_HEIGHT                  16
#define IP4_INPUT_FIELD_WIDTH             30
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#define IP4_INPUT_SEPERATOR_WIDTH            0
#define IP4_INPUT_FIELD_BUFFER_LENGTH        (4*ENCODING_LENGTH)

#define IP4_INPUT_FOCUS_NONE              0
#define IP4_INPUT_FOCUS_FIELD1               1
#define IP4_INPUT_FOCUS_FIELD2               2
#define IP4_INPUT_FOCUS_FIELD3               3
#define IP4_INPUT_FOCUS_FIELD4               4

#define IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD1     0x00000100
#define IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD2     0x00000200
#define IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD3     0x00000300
#define IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD4     0x00000400
#define IP4_INPUT_TYPE_DEFAULT_FOCUS_MASK    0x0000FF00
#define IP4_INPUT_JUSTIFY_MASK               0x00030000
#define IP4_INPUT_LEFT_JUSTIFY               0x00000000
#define IP4_INPUT_RIGHT_JUSTIFY              0x00010000
#define IP4_INPUT_CENTER_JUSTIFY          0x00020000

    typedef struct _IP4_input
    {
        S32 x, y;
        S32 width, height;
        S32 offset_x, offset_y;
        single_line_input_box field_input_box1;
        single_line_input_box field_input_box2;
        single_line_input_box field_input_box3;
        single_line_input_box field_input_box4;
        single_line_input_box *focus_input_box;
        U32 flags;
        U32 focus_list[IP4_INPUT_MAX_FOCUS];
        U32 current_focus;
        UI_character_type seperator;
        S32 field1_x, field1_y;
        S32 s1_x, s1_y;
        S32 field2_x, field2_y;
        S32 s2_x, s2_y;
        S32 field3_x, field3_y;
        S32 s3_x, s3_y;
        S32 field4_x, field4_y;

    } IP4_input;

#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
#define DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM 2
#endif 

    extern void IP4_input_show_background(IP4_input *d);
    extern void IP4_input_reset_focus(IP4_input *d);
    extern void IP4_input_set_focus(IP4_input *d);
    extern void IP4_input_set_default_focus(IP4_input *d);
    extern void create_IP4_input(
                    IP4_input *d,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 flags,
                    UI_buffer_type b1,
                    UI_buffer_type b2,
                    UI_buffer_type b3,
                    UI_buffer_type b4);
    extern void show_IP4_input(IP4_input *d);
    extern U8 IP4_input_set_next_focus(IP4_input *d);
    extern U8 IP4_input_set_previous_focus(IP4_input *d);
    extern void IP4_input_set_seperator(IP4_input *d, UI_character_type seperator);

    extern IP4_input *current_IP4_input;
    extern void (*current_IP4_input_callback) (void);

    extern void set_current_IP4_input(IP4_input *d);
    extern void IP4_input_direct_input(UI_character_type c);
    extern void IP4_input_delete_character(void);
    extern void IP4_input_previous_character(void);
    extern void IP4_input_next_character(void);
    extern void IP4_input_toggle_insert_mode(void);
    extern void IP4_input_delete_current_character(void);
    extern void IP4_input_delete_all_characters(void);
    extern void IP4_input_numeric_keyboard_input_handler(S32 keyc);
    extern void IP4_input_handle_key_down(MMI_key_code_type k);
    extern void IP4_input_key_handler(S32 vkey_code, S32 key_state);
    extern void IP4_input_register_keys(void);
    extern void IP4_input_clear_keys(void);
    void register_IP4_input_callback(void (*f) (void));
    extern void clear_IP4_input_callback(void);
    extern void set_inline_date_boundary(S32 date_year_max, S32 date_year_min, S32 date_month_max, S32 date_month_min);

#ifdef __MMI_SOUND_RECORDER__
    extern UI_date_time_display main_LCD_time_object;
    extern void set_time_duration(UI_time *t, U32 duration);
    extern void get_time_duration(UI_time *t);
    extern void time_display_duration(void);
    extern void time_update_duration(void);
    extern void set_time_display(U32 flags, S32 x, S32 y, S32 width, S32 height);
    extern void close_main_LCD_time_display(void);
#endif /* __MMI_SOUND_RECORDER__ */ 
    extern void enactive_main_lcd_update_date_time(void);
    extern void deactive_main_lcd_update_date_time(void);
    extern void enactive_sub_lcd_update_date_time(void);
    extern void deactive_sub_lcd_update_date_time(void);

    extern void Cat19UpdateDuration(MYTIME *t);

#ifdef __cplusplus
}
#endif 

#endif /* __WGUI_DATETIME_H__ */ 

