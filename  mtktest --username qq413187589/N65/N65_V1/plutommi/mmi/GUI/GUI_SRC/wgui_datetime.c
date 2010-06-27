/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * MMITask.C
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
 *============================================================================
 ****************************************************************************/

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
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
   Filename:      wgui_datetime.c
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines for Date and Time input / display
**********************************************************************************/

#include "Globaldefs.h"

/*  Include: MMI header file */
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"
/* ... Add More MMI header */

#include "DateTimeType.h"
#include "L4Dr.h"
#include "SettingGprots.h"
#include "wgui_datetime.h"
#include "gdi_include.h"
#include "gui_themes.h"
#include "DateTimeGprot.h"
#include "wgui_fixed_menus.h"
#include "wgui_fixed_menuitems.h"
#include "ScreenSaverDefs.h"
#include "CallManagementGprot.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_CM.h"
#include "BIDIDEF.h"
#include "BIDIProt.h"
#include "UCS2Prot.h"
#include "MiscFunctions.h"
#include "wgui_draw_manager.h"

#include "DebugInitDef.h"

#include "wgui_clock.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif

#if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) || defined(__MMI_UI_STATUS_BAR_AT_BOTTOM__)
#include "wgui_categories_idlescreen.h"
#endif 

#define DT_FLAGS_TYPE   (0x00000fff)

#ifdef __MMI_SUBLCD__
typedef enum
{
    /* Show date before time */
    SUBLCD_DT_DATE_THEN_TIME_TYPE1,
    /* Show time before date */
    SUBLCD_DT_TIME_THEN_DATE_TYPE1,
    SUBLCD_DT_TIME_THEN_DATE_TYPE2
} SUBLCD_DATE_TIME_DISPLAY_TYPE;
#endif /* __MMI_SUBLCD__ */ 
/* MTK Elvis for R2L characters */
#ifdef __MMI_BIDI_ALG__
extern U8 visual_str[];
#endif 
extern BOOL r2lMMIFlag;

/* MTK end */

#ifdef __MMI_AUDIO_PLAYER__
extern BOOL mmi_audply_is_playing(void);
#endif 

/* Date and Time input related objects    */
/* Currently only input boxes are used    */

extern void idle_screen_show_network_details(void);
extern pBOOL IsChineseSet(void);

#ifdef __MMI_SUBLCD__
extern S32 Sub_lcd_title_height;
#endif 
#ifdef __MMI_SUB_WALLPAPER__
extern GDI_HANDLE sublcd_base_layer;
#endif 

/* a single input box for day input */
single_line_input_box wgui_date_input_day;

/* a single input box for month  input */
single_line_input_box wgui_date_input_month;

/* a single input box for year  input */
single_line_input_box wgui_date_input_year;

/* a single input box for hours input */
single_line_input_box wgui_time_input_hours;

/* a single input box for minutes input */
single_line_input_box wgui_time_input_minutes;

/* a single input box for seconds input */
single_line_input_box wgui_time_input_seconds;

/* a single input box for am - pm input */
single_line_input_box wgui_time_input_AM_PM;

single_line_input_box *wgui_date_time_input_object_focus = NULL;

U8 wgui_date_time_input_focus = WGUI_DATE_TIME_INPUT_FOCUS_NONE;

/* store the position of day input previous focus */
U8 wgui_day_input_previous_focus;

/* store the position of day input next focus */
U8 wgui_day_input_next_focus;

/* store the position of month  input previous focus */
U8 wgui_month_input_previous_focus;

/* store the position of month  input next focus */
U8 wgui_month_input_next_focus;

/* store the position of year  input previous focus */
U8 wgui_year_input_previous_focus;

/* store the position of month  input previous focus */
U8 wgui_year_input_next_focus;

/* store the position of month  input previous focus */
U8 wgui_hours_input_previous_focus;

/* store the position of hours   input next focus */
U8 wgui_hours_input_next_focus;

/* store the position of minutes  input previous focus */
U8 wgui_minutes_input_previous_focus;

/* store the position of month  input next focus */
U8 wgui_minutes_input_next_focus;

/* store the position of seconds  input previous focus */
U8 wgui_seconds_input_previous_focus;

/* store the position of seconds   input next focus */
U8 wgui_seconds_input_next_focus;

/* store the position of AM - PM   input previous focus */
U8 wgui_AM_PM_input_previous_focus;

/* store the position of AM -= Pm   input next  focus */
U8 wgui_AM_PM_input_next_focus;

U8 wgui_seconds_input_enabled = 0;
U8 wgui_AM_PM_input_enabled = 0;

U8 wgui_date_input_enabled = 0;
U8 wgui_time_input_enabled = 0;

U8 show_date = 0;
MMI_BOOL main_lcd_update_date_time = MMI_TRUE;

#ifdef __MMI_SUBLCD__
MMI_BOOL sub_lcd_update_date_time = MMI_TRUE;
#endif 
/* MTK Elvis for date boundary setting */
S32 g_date_year_max = 2030, g_date_year_min = 1970, g_date_month_max = 12, g_date_month_min = 1;

/* MTK end */

/* global variable of main lcd date objet */
UI_date_time_display main_LCD_dt_object;

#ifdef __MMI_SUBLCD__
   /* global variable of sublcd lcd date objet city 1 */
UI_date_time_display sub_LCD_dt_object1;

   /* global variable of sublcd lcd date objet city 2 */
UI_date_time_display sub_LCD_dt_object2;
SUBLCD_DATE_TIME_DISPLAY_TYPE sublcd_date_time_display_type;
#endif /* __MMI_SUBLCD__ */ 

/* PMT HIMANSHU START 20050721 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
extern MMI_ID_TYPE idlescreen_bar_id;//070306 Alpha layer

U8 g_clock_type = ANALOG;   /* default clock for Techno Idlescreen Bar */

U16 *day_string = NULL; /* pointer storing the address of the MMI_ID_TYPE of day string. */
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
/* PMT HIMANSHU END 20050721 */

/* global variable of main lcd time objet */
UI_date_time_display main_LCD_time_object;


extern U16 GetTotalHoldCallCount(void);
extern S16 GetTotalActiveCallCount(void);
extern S32 UI_get_font_height(UI_font_type f);
extern void CheckCtrExpiry(MYTIME *last_time, MYTIME *curr_time);
extern MYTIME *GetStartCallTime(void);
extern MYTIME *GetCurrStartCallTime(void);
extern U8 PhnsetGetDateFormat(void);
extern U8 PhnsetGetTimeFormat(void);
extern UI_string_type UI_strcat(UI_string_type text1, UI_string_type text2);
extern UI_string_type UI_strcpy(UI_string_type text1, UI_string_type text2);
extern void (*gui_set_clip) (S32 x1, S32 y1, S32 x2, S32 y2);

/* Externals for graphics context switching  */
extern bitmap main_LCD_device_bitmap;           /* main lcd graphicd context */
extern bitmap sub_LCD_device_bitmap;            /* sub lcd graphic context */
void UI_set_main_LCD_graphics_context(void);    /* set main lcd graphic contrext */
void UI_set_sub_LCD_graphics_context(void);     /* set sub lcd graphic cntext */
extern bitmap *current_LCD_device_bitmap;       /* store current graphic context */

#ifdef __MMI_SUBLCD__
extern stFontAttribute MMI_sublcd_font;
extern S32 SUB_LCD_device_width;
extern void RedrawSubLCDAnalogClockScreen(void);
#endif /* __MMI_SUBLCD__ */ 


/* MTK Tim */
extern void kal_get_time(U32 *ticks_ptr);
U32 last_duration_ticks;
U32 last_duration;

UI_time last_duration_time;

/*----------------------------------------------------------------------------
Function:         wgui_date_time_input_callback
Description:      a function pointer store teh address of function
               of date time input callback
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*wgui_date_time_input_callback) (void);

/* theme scheme of inline date time input box */
UI_single_line_input_box_theme wgui_date_time_input_theme = { (UI_filled_area *)&MMI_formatted_inputbox_normal_filler,
    (UI_filled_area *)&MMI_formatted_inputbox_disabled_filler,
    (UI_filled_area *)&MMI_formatted_inputbox_selected_filler,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &UI_DEFAULT_FONT,
    1,
    UI_SINGLE_LINE_INPUT_BOX_CENTER_Y,
    '*'
};


/*****************************************************************************
 * FUNCTION
 *  wgui_set_day_input_navigation
 * DESCRIPTION
 *  function set thevaleu of previous and next cursor focus
 *  of day input single box
 * PARAMETERS
 *  previous_focus      [IN]        Previous cursor position
 *  next_focus          [IN]        Next cursor position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_day_input_navigation(U8 previous_focus, U8 next_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_day_input_previous_focus = previous_focus;
    wgui_day_input_next_focus = next_focus;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_month_input_navigation
 * DESCRIPTION
 *  function set thevaleu of previous and next cursor focus
 *  of month input single box
 * PARAMETERS
 *  previous_focus      [IN]        Previous cursor position
 *  next_focus          [IN]        Next cursor position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_month_input_navigation(U8 previous_focus, U8 next_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_month_input_previous_focus = previous_focus;
    wgui_month_input_next_focus = next_focus;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_year_input_navigation
 * DESCRIPTION
 *  function set the valeu of previous and next cursor focus
 *  of year input single box
 * PARAMETERS
 *  previous_focus      [IN]        Previous cursor position
 *  next_focus          [IN]        Next cursor position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_year_input_navigation(U8 previous_focus, U8 next_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_year_input_previous_focus = previous_focus;
    wgui_year_input_next_focus = next_focus;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_hours_input_navigation
 * DESCRIPTION
 *  function set the valeu of previous and next cursor focus
 *  of hours input single box
 * PARAMETERS
 *  previous_focus      [IN]        Previous cursor position
 *  next_focus          [IN]        Next cursor position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_hours_input_navigation(U8 previous_focus, U8 next_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_hours_input_previous_focus = previous_focus;
    wgui_hours_input_next_focus = next_focus;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_minutes_input_navigation
 * DESCRIPTION
 *  function set the valeu of previous and next cursor focus
 *  of minutes input single box
 * PARAMETERS
 *  previous_focus      [IN]        Previous cursor position
 *  next_focus          [IN]        Next cursor position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_minutes_input_navigation(U8 previous_focus, U8 next_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_minutes_input_previous_focus = previous_focus;
    wgui_minutes_input_next_focus = next_focus;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_seconds_input_navigation
 * DESCRIPTION
 *  function set the valeu of previous and next cursor focus
 *  of seconds input single box
 * PARAMETERS
 *  previous_focus      [IN]        Previous cursor position
 *  next_focus          [IN]        Next cursor position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_seconds_input_navigation(U8 previous_focus, U8 next_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_seconds_input_previous_focus = previous_focus;
    wgui_seconds_input_next_focus = next_focus;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_AM_PM_input_navigation
 * DESCRIPTION
 *  function set the valeu of previous and next cursor focus
 *  of am-pm input single box
 * PARAMETERS
 *  previous_focus      [IN]        Previous cursor position
 *  next_focus          [IN]        Next cursor position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_AM_PM_input_navigation(U8 previous_focus, U8 next_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_AM_PM_input_previous_focus = previous_focus;
    wgui_AM_PM_input_next_focus = next_focus;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_date_input
 * DESCRIPTION
 *  show date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_date_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* show day single line inputr box */
    gui_show_single_line_input_box(&wgui_date_input_day);
    /* show month single line input box */
    gui_show_single_line_input_box(&wgui_date_input_month);
    /* show year single line input box */
    gui_show_single_line_input_box(&wgui_date_input_year);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_time_input
 * DESCRIPTION
 *  show time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_time_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* show hours input box */
    gui_show_single_line_input_box(&wgui_time_input_hours);
    /* show minutes input box */
    gui_show_single_line_input_box(&wgui_time_input_minutes);
    if (wgui_seconds_input_enabled) /* if seconds input is enabled */
    {                               /* show seconds input box */
        gui_show_single_line_input_box(&wgui_time_input_seconds);
    }
    if (wgui_AM_PM_input_enabled)   /* if am-pm input enabled */
    {                               /* show am pm input box */
        gui_show_single_line_input_box(&wgui_time_input_AM_PM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_date_time_input
 * DESCRIPTION
 *  show date time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_date_time_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    if (wgui_date_input_enabled)    /* if date input box enabled */
    {
        wgui_show_date_input(); /* show date input box -day/month/year */
    }
    if (wgui_time_input_enabled)    /* if time input is enabled */
    {
        wgui_show_time_input(); /* show time input box */
    }
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_create_date_time_inputbox
 * DESCRIPTION
 *  create single input box of date or time
 * PARAMETERS
 *  b                   [IN]        Single input box
 *  buffer              [IN]        Buffer
 *  buffer_length       [IN]        Total buffer length
 *  text_length         [IN]        Current text length
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_create_date_time_inputbox(single_line_input_box *b, U8 *buffer, S32 buffer_length, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create single iput box and set buffer */
    gui_create_single_line_input_box_set_buffer(
        b,
        0,
        0,
        0,
        0,
        (UI_string_type) buffer,
        (buffer_length + 1) * 2,
        (text_length + 1) * 2,
        text_length);
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE;
    /* set the cursor position to first character */
    gui_single_line_input_box_goto_first_character(b);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_initialize_date_input
 * DESCRIPTION
 *  set the day,month,year value and length of date input box
 * PARAMETERS
 *  day_buffer              [IN]        Store valeu of day
 *  day_buffer_length       [IN]        Length of day buffer
 *  month_buffer            [IN]        Store value of minth
 *  month_buffer_length     [IN]        Length of month buffer
 *  year_buffer             [IN]        Store valeu of year
 *  year_buffer_length      [IN]        Length of year buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_initialize_date_input(
        UI_buffer_type day_buffer,
        S32 day_buffer_length,
        UI_buffer_type month_buffer,
        S32 month_buffer_length,
        UI_buffer_type year_buffer,
        S32 year_buffer_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the theme of  date input */
    wgui_date_time_input_theme.normal_filler = current_MMI_theme->formatted_inputbox_normal_filler;
    wgui_date_time_input_theme.disabled_filler = current_MMI_theme->formatted_inputbox_normal_filler;
    wgui_date_time_input_theme.selected_filler = current_MMI_theme->formatted_inputbox_selected_filler;
    /* set the theme of single line input box equal to date time input themem */
    current_single_line_input_box_theme = &wgui_date_time_input_theme;
    l = gui_strlen((UI_string_type) day_buffer);
    /* create day input box and set the buffe of day input box */
    wgui_create_date_time_inputbox(&wgui_date_input_day, day_buffer, day_buffer_length, l);
    l = gui_strlen((UI_string_type) month_buffer);
    /* create month input box and set the buffer of month input box */
    wgui_create_date_time_inputbox(&wgui_date_input_month, month_buffer, month_buffer_length, l);
    l = gui_strlen((UI_string_type) year_buffer);
    /* create year  input box and set the buffer of year  input box */
    wgui_create_date_time_inputbox(&wgui_date_input_year, year_buffer, year_buffer_length, l);
    current_single_line_input_box_theme = current_UI_theme->single_line_input_box_theme;
    wgui_date_time_input_remove_object_focus(&wgui_date_input_day);
    wgui_date_time_input_remove_object_focus(&wgui_date_input_month);
    wgui_date_time_input_remove_object_focus(&wgui_date_input_year);
    /* set the flag of date input enabled */
    wgui_date_input_enabled = 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_initialize_time_input
 * DESCRIPTION
 *  set the hour ,minute,second  value and length of time  input box
 * PARAMETERS
 *  hours_buffer                [IN]        Store valeu of hours
 *  hours_buffer_length         [IN]        Length of hours buffer
 *  minutes_buffer              [IN]        Store value of minute
 *  minutes_buffer_length       [IN]        Length of minute buffer
 *  seconds_buffer              [IN]        Store valeu of seconds
 *  seconds_buffer_length       [IN]        Length of second  buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_initialize_time_input(
        UI_buffer_type hours_buffer,
        S32 hours_buffer_length,
        UI_buffer_type minutes_buffer,
        S32 minutes_buffer_length,
        UI_buffer_type seconds_buffer,
        S32 seconds_buffer_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the theme of time input box */
    wgui_date_time_input_theme.normal_filler = current_MMI_theme->formatted_inputbox_normal_filler;
    wgui_date_time_input_theme.disabled_filler = current_MMI_theme->formatted_inputbox_normal_filler;
    wgui_date_time_input_theme.selected_filler = current_MMI_theme->formatted_inputbox_selected_filler;
    current_single_line_input_box_theme = &wgui_date_time_input_theme;
    l = gui_strlen((UI_string_type) hours_buffer);
    /* create hour inputbox and set the buffer of hour input box */
    wgui_create_date_time_inputbox(&wgui_time_input_hours, hours_buffer, hours_buffer_length, l);
    l = gui_strlen((UI_string_type) minutes_buffer);
    /* create minutes inputbox and set the buffer of minutes input box */
    wgui_create_date_time_inputbox(&wgui_time_input_minutes, minutes_buffer, minutes_buffer_length, l);
    l = gui_strlen((UI_string_type) seconds_buffer);
    /* create seconds inputbox and set the buffer of second  input box */
    wgui_create_date_time_inputbox(&wgui_time_input_seconds, seconds_buffer, seconds_buffer_length, l);
    current_single_line_input_box_theme = current_UI_theme->single_line_input_box_theme;
    wgui_date_time_input_remove_object_focus(&wgui_time_input_hours);
    wgui_date_time_input_remove_object_focus(&wgui_time_input_minutes);
    wgui_date_time_input_remove_object_focus(&wgui_time_input_seconds);
    wgui_date_time_input_remove_object_focus(&wgui_time_input_AM_PM);
    wgui_time_input_enabled = 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_date_input
 * DESCRIPTION
 *  set the flag of date input to default valeu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_date_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_date_input_enabled = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_time_input
 * DESCRIPTION
 *  set the flag of time input to default valeu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_time_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_time_input_enabled = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_day_input
 * DESCRIPTION
 *  move day input box to particula position x , y equal to valeu pass as parameter
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_day_input(S32 x, S32 y)
{   /* move the day input box to particular x,y position */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&wgui_date_input_day, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_day_input
 * DESCRIPTION
 *  resize day inpuit box
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_day_input(S32 width, S32 height)
{   /* resize da input box equal to width and height pass as parameter */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&wgui_date_input_day, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_month_input
 * DESCRIPTION
 *  move month input box to particula position x , y equal to valeu pass as parameter
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_month_input(S32 x, S32 y)
{   /* move the month input box to particular x,y position */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&wgui_date_input_month, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_month_input
 * DESCRIPTION
 *  resize month inpuit box
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_month_input(S32 width, S32 height)
{   /* resize month input box equal to width and height pass as parameter */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&wgui_date_input_month, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_year_input
 * DESCRIPTION
 *  move year input box to particula position x , y equal to valeu pass as parameter
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_year_input(S32 x, S32 y)
{   /* move the year input box to particular x,y position */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&wgui_date_input_year, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_year_input
 * DESCRIPTION
 *  resize year inpuit box
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_year_input(S32 width, S32 height)
{   /* resize year input box equal to width and height pass as parameter */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&wgui_date_input_year, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_hours_input
 * DESCRIPTION
 *  move hours input box to particula position x , y equal to valeu pass as parameter
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_hours_input(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&wgui_time_input_hours, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_hours_input
 * DESCRIPTION
 *  resize hours  inpuit box
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_hours_input(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&wgui_time_input_hours, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_minutes_input
 * DESCRIPTION
 *  move minutes input box to particula position x , y equal to valeu pass as parameter
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_minutes_input(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&wgui_time_input_minutes, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_minutes_input
 * DESCRIPTION
 *  resize minutes  inpuit box
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_minutes_input(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&wgui_time_input_minutes, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_seconds_input
 * DESCRIPTION
 *  move seconds input box to particula position x , y equal to valeu pass as parameter
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_seconds_input(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&wgui_time_input_seconds, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_seconds_input
 * DESCRIPTION
 *  resize seconds  inpuit box
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_seconds_input(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&wgui_time_input_seconds, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_AM_PM_input
 * DESCRIPTION
 *  move am-pm input box to particula position x , y equal to valeu pass as parameter
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_AM_PM_input(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&wgui_time_input_AM_PM, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_resize_AM_PM_input
 * DESCRIPTION
 *  resize am-pm  inpuit box
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_resize_AM_PM_input(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&wgui_time_input_AM_PM, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_enable_seconds_input
 * DESCRIPTION
 *  enbale second input flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_enable_seconds_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_seconds_input_enabled = 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_disable_seconds_input
 * DESCRIPTION
 *  disable second input flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_disable_seconds_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_seconds_input_enabled = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_enable_AM_PM_input
 * DESCRIPTION
 *  enbale am pm input flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_enable_AM_PM_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_AM_PM_input_enabled = 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_disable_AM_PM_input
 * DESCRIPTION
 *  disable am pm input flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_disable_AM_PM_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_AM_PM_input_enabled = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_set_object_focus
 * DESCRIPTION
 *  set focus on input box pass as paaremter
 * PARAMETERS
 *  b       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_input_set_object_focus(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b == NULL)
    {
        return;
    }
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_remove_object_focus
 * DESCRIPTION
 *  remove  focus from input box pass as paaremter
 * PARAMETERS
 *  b       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_input_remove_object_focus(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b == NULL)
    {
        return;
    }
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_set_focus
 * DESCRIPTION
 *  set focus on input box pass as paaremter
 * PARAMETERS
 *  focus       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_input_set_focus(U8 focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_date_time_input_focus = focus;
    switch (wgui_date_time_input_focus)
    {
        case WGUI_DATE_TIME_INPUT_FOCUS_NONE:
            wgui_date_time_input_object_focus = NULL;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_DAY:
            wgui_date_time_input_object_focus = &wgui_date_input_day;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_MONTH:
            wgui_date_time_input_object_focus = &wgui_date_input_month;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_YEAR:
            wgui_date_time_input_object_focus = &wgui_date_input_year;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_HOURS:
            wgui_date_time_input_object_focus = &wgui_time_input_hours;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_MINUTES:
            wgui_date_time_input_object_focus = &wgui_time_input_minutes;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_SECONDS:
            wgui_date_time_input_object_focus = &wgui_time_input_seconds;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_AM_PM:
            wgui_date_time_input_object_focus = &wgui_time_input_AM_PM;
            break;
        default:
            wgui_date_time_input_object_focus = NULL;
            break;
    }
    wgui_date_time_input_set_object_focus(wgui_date_time_input_object_focus);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_remove_focus
 * DESCRIPTION
 *  remove focus from  input box pass as paaremter
 * PARAMETERS
 *  focus       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_input_remove_focus(U8 focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *f = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (focus)
    {
        case WGUI_DATE_TIME_INPUT_FOCUS_NONE:
            f = NULL;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_DAY:
            f = &wgui_date_input_day;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_MONTH:
            f = &wgui_date_input_month;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_YEAR:
            f = &wgui_date_input_year;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_HOURS:
            f = &wgui_time_input_hours;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_MINUTES:
            f = &wgui_time_input_minutes;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_SECONDS:
            f = &wgui_time_input_seconds;
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_AM_PM:
            f = &wgui_time_input_AM_PM;
            break;
        default:
            f = NULL;
            break;
    }
    wgui_date_time_input_remove_object_focus(f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_set_previous_focus
 * DESCRIPTION
 *  set focus to previous position of current input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_input_set_previous_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_date_time_input_remove_focus(wgui_date_time_input_focus);
    switch (wgui_date_time_input_focus)
    {
        case WGUI_DATE_TIME_INPUT_FOCUS_NONE:
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_DAY:
            wgui_date_time_input_set_focus(wgui_day_input_previous_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_MONTH:
            wgui_date_time_input_set_focus(wgui_month_input_previous_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_YEAR:
            wgui_date_time_input_set_focus(wgui_year_input_previous_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_HOURS:
            wgui_date_time_input_set_focus(wgui_hours_input_previous_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_MINUTES:
            wgui_date_time_input_set_focus(wgui_minutes_input_previous_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_SECONDS:
            wgui_date_time_input_set_focus(wgui_seconds_input_previous_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_AM_PM:
            wgui_date_time_input_set_focus(wgui_AM_PM_input_previous_focus);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_set_next_focus
 * DESCRIPTION
 *  set focus to next  position of current input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_input_set_next_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_date_time_input_remove_focus(wgui_date_time_input_focus);
    switch (wgui_date_time_input_focus)
    {
        case WGUI_DATE_TIME_INPUT_FOCUS_NONE:
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_DAY:
            wgui_date_time_input_set_focus(wgui_day_input_next_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_MONTH:
            wgui_date_time_input_set_focus(wgui_month_input_next_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_YEAR:
            wgui_date_time_input_set_focus(wgui_year_input_next_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_HOURS:
            wgui_date_time_input_set_focus(wgui_hours_input_next_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_MINUTES:
            wgui_date_time_input_set_focus(wgui_minutes_input_next_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_SECONDS:
            wgui_date_time_input_set_focus(wgui_seconds_input_next_focus);
            break;
        case WGUI_DATE_TIME_INPUT_FOCUS_AM_PM:
            wgui_date_time_input_set_focus(wgui_AM_PM_input_next_focus);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_get_previous_focus
 * DESCRIPTION
 *  return the previous focus input box
 * PARAMETERS
 *  void
 * RETURNS
 *  byte:- return the previous  focus input box ..day/month/year/hour/minute/second
 *****************************************************************************/
U8 wgui_date_time_input_get_previous_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (wgui_date_time_input_focus)
    {
        case WGUI_DATE_TIME_INPUT_FOCUS_NONE:
            return (WGUI_DATE_TIME_INPUT_FOCUS_NONE);
        case WGUI_DATE_TIME_INPUT_FOCUS_DAY:
            return (wgui_day_input_previous_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_MONTH:
            return (wgui_month_input_previous_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_YEAR:
            return (wgui_year_input_previous_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_HOURS:
            return (wgui_hours_input_previous_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_MINUTES:
            return (wgui_minutes_input_previous_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_SECONDS:
            return (wgui_seconds_input_previous_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_AM_PM:
            return (wgui_AM_PM_input_previous_focus);
        default:
            return (WGUI_DATE_TIME_INPUT_FOCUS_NONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_get_next_focus
 * DESCRIPTION
 *  return the next foucs input box
 * PARAMETERS
 *  void
 * RETURNS
 *  byte:- return the previous  focus input box ..day/month/year/hour/minute/second
 *****************************************************************************/
U8 wgui_date_time_input_get_next_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (wgui_date_time_input_focus)
    {
        case WGUI_DATE_TIME_INPUT_FOCUS_NONE:
            return (WGUI_DATE_TIME_INPUT_FOCUS_NONE);
        case WGUI_DATE_TIME_INPUT_FOCUS_DAY:
            return (wgui_day_input_next_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_MONTH:
            return (wgui_month_input_next_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_YEAR:
            return (wgui_year_input_next_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_HOURS:
            return (wgui_hours_input_next_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_MINUTES:
            return (wgui_minutes_input_next_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_SECONDS:
            return (wgui_seconds_input_next_focus);
        case WGUI_DATE_TIME_INPUT_FOCUS_AM_PM:
            return (wgui_AM_PM_input_next_focus);
        default:
            return (WGUI_DATE_TIME_INPUT_FOCUS_NONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_redraw_date_time_input
 * DESCRIPTION
 *  redraw dte/time input box depend on current focus input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_redraw_date_time_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_date_time_input_object_focus == NULL)
    {
        return;
    }
    gdi_layer_lock_frame_buffer();
    gui_show_single_line_input_box(wgui_date_time_input_object_focus);
    gdi_layer_unlock_frame_buffer();
    x1 = wgui_date_time_input_object_focus->x;
    y1 = wgui_date_time_input_object_focus->y;
    x2 = x1 + wgui_date_time_input_object_focus->width - 1;
    y2 = y1 + wgui_date_time_input_object_focus->height - 1;
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_direct_input
 * DESCRIPTION
 *  input the character enter by user in date tiem input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_date_time_input_object_focus == NULL)
    {
        return;
    }
    if (gui_single_line_input_box_test_last_position_overflow(wgui_date_time_input_object_focus))
    {
        if (wgui_date_time_input_get_next_focus() != WGUI_DATE_TIME_INPUT_FOCUS_NONE)
        {
            wgui_date_time_input_set_next_focus();
            gui_single_line_input_box_insert_character(wgui_date_time_input_object_focus, c);
            wgui_show_date_time_input();
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(wgui_date_time_input_object_focus, c);
        wgui_redraw_date_time_input();
        if (gui_single_line_input_box_test_last_position_overflow(wgui_date_time_input_object_focus))
        {
            if (wgui_date_time_input_get_next_focus() != WGUI_DATE_TIME_INPUT_FOCUS_NONE)
            {
                wgui_date_time_input_set_next_focus();
                wgui_show_date_time_input();
            }
        }
    }
    wgui_date_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_delete_character
 * DESCRIPTION
 *  delete the character from  date time input box - current input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_date_time_input_object_focus == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(wgui_date_time_input_object_focus))
    {
        if (wgui_date_time_input_get_previous_focus() != WGUI_DATE_TIME_INPUT_FOCUS_NONE)
        {
            wgui_date_time_input_set_previous_focus();
            wgui_show_date_time_input();
        }
    }
    else
    {
        gui_single_line_input_box_delete_character(wgui_date_time_input_object_focus);
        wgui_redraw_date_time_input();
        if (gui_single_line_input_box_test_first_position(wgui_date_time_input_object_focus))
        {
            if (wgui_date_time_input_get_previous_focus() != WGUI_DATE_TIME_INPUT_FOCUS_NONE)
            {
                wgui_date_time_input_set_previous_focus();
                wgui_show_date_time_input();
            }
        }
    }
    wgui_date_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_previous_character
 * DESCRIPTION
 *  move the cursor to previous caharcter of date /time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_date_time_input_object_focus == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(wgui_date_time_input_object_focus))
    {
        if (wgui_date_time_input_get_previous_focus() != WGUI_DATE_TIME_INPUT_FOCUS_NONE)
        {
            wgui_date_time_input_set_previous_focus();
            wgui_show_date_time_input();
        }
    }
    else
    {
        gui_single_line_input_box_previous(wgui_date_time_input_object_focus);
        wgui_redraw_date_time_input();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_next_character
 * DESCRIPTION
 *  move the cursor to next caharcter of date /time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_date_time_input_object_focus == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position(wgui_date_time_input_object_focus))
    {
        if (wgui_date_time_input_get_next_focus() != WGUI_DATE_TIME_INPUT_FOCUS_NONE)
        {
            wgui_date_time_input_set_next_focus();
            wgui_show_date_time_input();
        }
    }
    else
    {
        gui_single_line_input_box_next(wgui_date_time_input_object_focus);
        wgui_redraw_date_time_input();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_toggle_insert_mode
 * DESCRIPTION
 *  toggle insert mode of date /time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_date_time_input_object_focus == NULL)
    {
        return;
    }

    gui_single_line_input_box_toggle_insert_mode(wgui_date_time_input_object_focus);
    wgui_redraw_date_time_input();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_delete_current_character
 * DESCRIPTION
 *  delete current character of date /time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_date_time_input_object_focus == NULL)
    {
        return;
    }

    gui_single_line_input_box_delete_current_character(wgui_date_time_input_object_focus);
    wgui_redraw_date_time_input();
    wgui_date_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_delete_all_characters
 * DESCRIPTION
 *  delete all characters of date /time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_date_time_input_object_focus == NULL)
    {
        return;
    }

    gui_single_line_input_box_delete_all(wgui_date_time_input_object_focus);
    wgui_redraw_date_time_input();
    wgui_date_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_numeric_keyboard_input_handler
 * DESCRIPTION
 *  handle numeric key inoput of date /time input box
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        wgui_date_time_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        wgui_date_time_delete_character();
    }
    else if (keyc == 0x1b)
    {
        wgui_date_time_delete_all_characters();
    }
    else if (keyc == 0x0d);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_handle_key_down
 * DESCRIPTION
 *  handle key board input of date /time
 * PARAMETERS
 *  k           [IN]        
 *  S32(?)      [IN]        Keyc
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_date_time_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_key_handler
 * DESCRIPTION
 *  handle key board input of date /time
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                wgui_date_time_previous_character();
                break;
            case 38:    /* up */
                break;
            case 39:
                wgui_date_time_next_character();
                break;
            case 40:    /* down */
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                wgui_date_time_toggle_insert_mode();
                break;
            case 46:
                wgui_date_time_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_register_keys
 * DESCRIPTION
 *  register date / time input keys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_down_handler(wgui_date_time_handle_key_down);
    register_keyboard_input_handler(wgui_date_time_numeric_keyboard_input_handler);
    SetKeyHandler(wgui_date_time_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_date_time_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    register_keyboard_key_handler(wgui_date_time_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_date_time_input_clear_keys
 * DESCRIPTION
 *  clear all register keys of adet /time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_date_time_input_clear_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();
    clear_key_down_handler();
    clear_keyboard_input_handler();
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    clear_keyboard_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  register_wgui_date_time_input_callback
 * DESCRIPTION
 *  register date/time input callback function
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointers
 * RETURNS
 *  void
 *****************************************************************************/
void register_wgui_date_time_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_date_time_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_wgui_date_time_input_callback
 * DESCRIPTION
 *  clear date time input callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_wgui_date_time_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_date_time_input_callback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  get_year
 * DESCRIPTION
 *  return year of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* Date and time display related code  */
U16 get_year(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nYear);
}


/*****************************************************************************
 * FUNCTION
 *  get_month
 * DESCRIPTION
 *  return month of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_month(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nMonth);
}


/*****************************************************************************
 * FUNCTION
 *  get_day
 * DESCRIPTION
 *  return day of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_day(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nDay);
}


/*****************************************************************************
 * FUNCTION
 *  get_hours
 * DESCRIPTION
 *  return hours of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_hours(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nHour);
}


/*****************************************************************************
 * FUNCTION
 *  get_minutes
 * DESCRIPTION
 *  return minutes of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_minutes(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nMin);
}


/*****************************************************************************
 * FUNCTION
 *  get_seconds
 * DESCRIPTION
 *  return seconds of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_seconds(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nSec);
}


/*****************************************************************************
 * FUNCTION
 *  get_dayofweek
 * DESCRIPTION
 *  return day of week  of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_dayofweek(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->DayIndex);
}


/*****************************************************************************
 * FUNCTION
 *  date_string
 * DESCRIPTION
 *  get date time string for different requirement
 * PARAMETERS
 *  time        [IN]        Date time to convert
 *  string      [OUT]       Date time string
 *  flags       [IN]        Date time type
 * RETURNS
 *  void
 *****************************************************************************/
void date_string(UI_time *time, UI_string_type string, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 day, month, year, day_index;
    S8 ts[32];

#ifdef __MMI_SUBLCD__
    /* MAUI_00169917 START */
    S8 as[64];
    U8 Tempbuffer[64];

    /* MAUI_00169917 END */

    U8 *day_name = NULL;
#endif /* __MMI_SUBLCD__ */ 
#ifdef __MMI_DATE_TIME_IN_DIFF_LANG__
    S8 ts2[32];
#endif 
#ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
    U8 month_str[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
#else 
    UI_string_type month_str;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    day_index = get_dayofweek(time);
    day = get_day(time);
    month = get_month(time);
    year = get_year(time);

    if (month > 12 || month < 1)
    {
        month = 1;
    }

    switch (flags & DT_FLAGS_TYPE)
    {

      /***** MainLCD DataTime *****/
        case DT_IDLE_SCREEN:
        case DT_IDLE_SCREEN_ENGLISH_ONLY:
        case DT_NETWORK_SEARCH:
        case DT_MO_CALL_SCREEN:
        case DT_MO_CALLING_SCREEN:
        case DT_TABBED_CALL_SCREEN:
        case DT_VOIP_CALL_SCREEN:
        case DT_MT_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        case DT_DIGITAL_CLOCK_SC1:
        case DT_DIGITAL_CLOCK_SC2:
        case DT_DIGITAL_CLOCK_SC3:
        case DT_ANALOG_CLOCK_SC:
        {
            switch (PhnsetGetDateFormat())  /* Get the current format of date */
            {
                case 0:
            #ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
                    sprintf((S8*) ts, "%02d-%3s-%04d", day, month_str[month - 1], year);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
            #else /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
                    sprintf((S8*) ts, "%02d-", day);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    if ((flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN_ENGLISH_ONLY)
                    {
                        month_str = get_string_lang((MMI_ID_TYPE) (STR_GUI_MONTH_BASE + month), (S8*) "*#0044#");
                    }
                    else
                    {
                        month_str = get_string((MMI_ID_TYPE) (STR_GUI_MONTH_BASE + month));
                    }
                    if (month_str)
                    {
                        UI_strcat(string, month_str);
                    }

                    sprintf((S8*) ts, "-%04d", year);
                    mmi_asc_to_ucs2((S8*) ts2, ts);
                    UI_strcat(string, (UI_string_type) ts2);
                    break;
            #endif /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
                case 1:
                    sprintf((S8*) ts, "%02d/%02d/%04d", day, month, year);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;

                case 2:
                    sprintf((S8*) ts, "%02d/%02d/%04d", month, day, year);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;

                case 3:
                    sprintf((S8*) ts, "%04d/%02d/%02d", year, month, day);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;

                case 4:
                    sprintf((S8*) ts, "%04d-%02d-%02d", year, month, day);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;

                case 5:
                #ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
                    sprintf((S8*) ts, "%3s %02d, %04d", month_str[month - 1], day, year);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
                #else /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
                    sprintf((S8*) ts, " %02d, %04d", day, year);

                    if ((flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN_ENGLISH_ONLY)
                    {
                        month_str = get_string_lang((MMI_ID_TYPE) (STR_GUI_MONTH_BASE + month), (S8*) "*#0044#");
                    }
                    else
                    {
                        month_str = get_string((MMI_ID_TYPE) (STR_GUI_MONTH_BASE + month));
                    }
                    if (month_str)
                    {
                        UI_strcpy(string, month_str);
                    }
                    else
                    {
                        UI_strcpy(string, L"");
                    }
                    mmi_asc_to_ucs2((S8*) ts2, ts);
                    UI_strcat(string, (UI_string_type) ts2);
                    break;
                #endif /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
            }
        }
            break;
        case DT_IDLE_SCREEN_2:
        {
            switch (PhnsetGetDateFormat())
            {
                case 0:
                case 1:
                    sprintf((S8*) ts, "%02d %3s", day, month_str[month - 1]);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    sprintf((S8*) ts, "%3s %02d", month_str[month - 1], day);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
            }
        }
            break;

    #ifdef __MMI_SUBLCD__
      /***** SubLCD DataTime *****/
        case DT_SUBLCD_IDLE_SCREEN1:
        case DT_SUBLCD_IDLE_SCREEN2:
        case DT_SUBLCD_IDLE_SCREEN3:
        case DT_SUBLCD_IDLE_SCREEN4:
        {
            if (IsChineseSet()) /* check if current language is chinese or not */
            {
                switch (day_index)
                {
                    case 0:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_SUNDAY);
                        break;

                    case 1:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_MONDAY);
                        break;

                    case 2:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_TUESDAY);
                        break;

                    case 3:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_WEDNESDAY);
                        break;

                    case 4:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_THURSDAY);
                        break;

                    case 5:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_FRIDAY);
                        break;

                    case 6:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_SATURDAY);
                        break;
                }
            }
            else
            {
                /* not chinese */
                switch (day_index)
                {
                    case 0:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_SUNDAY);
                        break;

                    case 1:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_MONDAY);
                        break;

                    case 2:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_TUESDAY);
                        break;

                    case 3:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_WEDNESDAY);
                        break;

                    case 4:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_THURSDAY);
                        break;

                    case 5:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_FRIDAY);
                        break;

                    case 6:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_SATURDAY);
                        break;
                }
            }   /* end of check chiese */
            /* MAUI_00169917 START */
            mmi_ucs2cpy((S8*) as, (S8*) day_name);
            /* MAUI_00169917 END */

            if ((flags & DT_FLAGS_TYPE) == DT_SUBLCD_IDLE_SCREEN3)
            {
                year %= 100;

                switch (PhnsetGetDateFormat())  /* Get the current format of date */
                {
                    case 0:
                    case 1:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d/%02d", day, month, year);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;

                    case 2:
                    case 5:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d/%02d", month, day, year);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;

                    case 3:
                    case 4:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d/%02d", year, month, day);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;
                }

            }
            /* 101804 MTK Calvin added */
            else if ((flags & DT_FLAGS_TYPE) == DT_SUBLCD_IDLE_SCREEN2)
            {
                year %= 100;

                switch (PhnsetGetDateFormat())  /* Get the current format of date */
                {
                    case 0:
                    case 1:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d", day, month);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;

                    case 2:
                    case 3:
                    case 4:
                    case 5:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d", month, day);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;
                }

            }
            /* MTK Calvin end */
            else
            {
                /* MAUI_00169917 START */
                sprintf((S8*) ts, "%02d/%02d", day, month);
                mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                /* MAUI_00169917 END */
            }

            /* MAUI_00169917 START */
            mmi_ucs2cpy((S8*) string, (S8*) as);
            /* MAUI_00169917 END */
            break;
        }
            /* break; */
    #endif /* __MMI_SUBLCD__ */ 

      /***** FileManager DataTime *****/
        case DT_FILEMANAGER:
        {
            year %= 100;

            switch (PhnsetGetDateFormat())  /* Get the current format of date */
            {
                case 0:
                case 1:
                    sprintf((S8*) ts, "%02d/%02d/%02d", day, month, year);
                    break;

                case 2:
                case 5:
                    sprintf((S8*) ts, "%02d/%02d/%02d", month, day, year);
                    break;

                case 3:
                case 4:
                    sprintf((S8*) ts, "%02d/%02d/%02d", year, month, day);
                    break;
            }   /* end of switch */

            mmi_asc_to_ucs2((S8*) string, ts);
            break;
        }
            /* break; */

    }
}


/*****************************************************************************
 * FUNCTION
 *  time_string
 * DESCRIPTION
 *  convert time to string accoding to current time format
 * PARAMETERS
 *  t           [IN]        Date to convets
 *  s           [OUT]       String format of time
 *  flags       [IN]        Date type
 * RETURNS
 *  void
 *****************************************************************************/
void time_string(UI_time *t, UI_string_type s, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hours, minutes;

#ifdef __MMI_DATE_TIME_IN_DIFF_LANG__
    UI_string_type postfix;
#endif 
    S8 ts[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hours = get_hours(t);
    minutes = get_minutes(t);
    switch (flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
        case DT_IDLE_SCREEN_2:
        case DT_IDLE_SCREEN_ENGLISH_ONLY:
        case DT_NETWORK_SEARCH:
        case DT_MO_CALL_SCREEN:
        case DT_MO_CALLING_SCREEN:
        case DT_MT_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        case DT_TABBED_CALL_SCREEN:
        case DT_VOIP_CALL_SCREEN:
        case DT_DIGITAL_CLOCK_SC1:
        case DT_DIGITAL_CLOCK_SC2:
        case DT_DIGITAL_CLOCK_SC3:
        case DT_ANALOG_CLOCK_SC:

            if (PhnsetGetTimeFormat())  /* get current time format */
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                mmi_asc_to_ucs2((S8*) s, ts);
            }
            else
            {
            #ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d AM", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d AM", hours, minutes);
                }
                mmi_asc_to_ucs2((S8*) s, ts);
            #else /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
                mmi_asc_to_ucs2((S8*) s, ts);

                if (hours >= 12)
                {
                    postfix = ((flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN_ENGLISH_ONLY) ?
                        (UI_string_type) get_string_lang(STR_GUI_TIME_PM, (S8*) "*#0044#") :
                        (UI_string_type) get_string(STR_GUI_TIME_PM);
                }
                else
                {
                    postfix = ((flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN_ENGLISH_ONLY) ?
                        (UI_string_type) get_string_lang(STR_GUI_TIME_AM, (S8*) "*#0044#") :
                        (UI_string_type) get_string(STR_GUI_TIME_AM);
                }

                if (postfix)
                {
                    UI_strcat((UI_string_type) s, postfix);
                }
            #endif /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
            }
            break;

        #ifdef __MMI_SUBLCD__
        case DT_SUBLCD_IDLE_SCREEN1:
        case DT_SUBLCD_IDLE_SCREEN2:
        case DT_SUBLCD_IDLE_SCREEN3:
            if (PhnsetGetTimeFormat())
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
            }
            else
            {
                S32 width, height;

                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d AM", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d AM", hours, minutes);
                }
                mmi_asc_to_ucs2((S8*) s, ts);
                gui_measure_string((UI_string_type) s, &width, &height);
                if (width > SUB_LCD_device_width)
                {
                    if (hours == 12)
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    }
                    else if (hours == 0)
                    {
                        sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                    }
                    else if (hours > 12)
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                    }
                    else
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    }
                }
            }
            mmi_asc_to_ucs2((S8*) s, ts);
            break;

        case DT_SUBLCD_IDLE_SCREEN4:
            if (PhnsetGetTimeFormat())
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
            }
            else
            {
                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
            }
            mmi_asc_to_ucs2((S8*) s, ts);
            break;
        #endif /* __MMI_SUBLCD__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  duration_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t           [?]         
 *  s           [IN]        
 *  flags       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void duration_string(UI_time *t, UI_string_type s, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hours, minutes, seconds;
    S8 ts[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hours = get_hours(t);
    minutes = get_minutes(t);
    seconds = get_seconds(t);
    switch (flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
        case DT_IDLE_SCREEN_ENGLISH_ONLY:
        case DT_NETWORK_SEARCH:
        case DT_MO_CALL_SCREEN:
        case DT_MO_CALLING_SCREEN:
        case DT_MT_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        case DT_TABBED_CALL_SCREEN:
        case DT_VOIP_CALL_SCREEN:
    #ifdef __MMI_SUBLCD__
        case DT_SUBLCD_IDLE_SCREEN1:
        case DT_SUBLCD_IDLE_SCREEN2:
    #endif /* __MMI_SUBLCD__ */ 
            sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
            break;
        case DT_AUDIO_PLAY_DURATION:
            sprintf((S8*) ts, "%02d:%02d", minutes, seconds);
            break;
        default:
            hours = 0;
            minutes = 0;
            seconds = 0;
            sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
            break;
                
    }
    mmi_asc_to_ucs2((S8*) s, ts);
}


/*****************************************************************************
 * FUNCTION
 *  get_time_difference2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_time        [?]     
 *  ref_time        [?]     
 *  diff_time       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void get_time_difference2(UI_time *new_time, UI_time *ref_time, UI_time *diff_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 min_flag = 0, hour_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_time->nSec >= ref_time->nSec)
    {
        diff_time->nSec = new_time->nSec - ref_time->nSec;
    }
    else
    {
        diff_time->nSec = new_time->nSec + 60 - ref_time->nSec;
        min_flag = 1;

    }
    if (new_time->nMin >= ref_time->nMin + min_flag)
    {
        diff_time->nMin = new_time->nMin - ref_time->nMin - min_flag;
    }
    else
    {
        diff_time->nMin = new_time->nMin + 60 - ref_time->nMin - min_flag;
        hour_flag = 1;
    }
    if (new_time->nHour >= ref_time->nHour + hour_flag)
    {
        diff_time->nHour = new_time->nHour - ref_time->nHour - hour_flag;
    }
    else
    {
        diff_time->nHour = new_time->nHour + 24 - ref_time->nHour - hour_flag;
        new_time->nDay -= 1;
    }
    diff_time->nDay = 0;
    diff_time->nMonth = 0;
    diff_time->nYear = 0;
    diff_time->DayIndex = 0;
}


/*****************************************************************************
 * FUNCTION
 *  increment_seconds
 * DESCRIPTION
 *  increment the seconds by 1
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void increment_seconds(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_time curr_time, diff_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&curr_time);
    get_time_difference2(&curr_time, &last_duration_time, &diff_time);
    IncrementTime(*t, diff_time, t );
    last_duration_time.nSec = curr_time.nSec;
    last_duration_time.nMin = curr_time.nMin;
    last_duration_time.nHour = curr_time.nHour;
    last_duration_time.nDay = curr_time.nDay;
    last_duration_time.nMonth = curr_time.nMonth;
    last_duration_time.DayIndex = curr_time.DayIndex;
}


/*****************************************************************************
 * FUNCTION
 *  increment_ticks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void increment_ticks(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_time;
    U32 secs, mins, hrs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);
    secs = (U32) ((current_time - last_duration_ticks + last_duration) * 0.004615 + 0.5);
    mins = secs / 60;
    hrs = mins / 60;
    t->nSec = (U8) (secs - mins * 60);
    t->nMin = (U8) (mins - hrs * 60);
    t->nHour = (U8) hrs;
    t->nYear = t->nMonth = t->nDay = 0;
}

FLOAT dt_difference1;
FLOAT dt_difference2;

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  get_time_difference
 * DESCRIPTION
 *  calculate time difference between two times pass as parameter
 * PARAMETERS
 *  time_303            [?]         
 *  city_diff_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_time_difference(MYTIME *time_303, FLOAT city_diff_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_time, hour_sublcd1, min_sublcd1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_time = ((time_303->nHour * 60) + time_303->nMin) + ((S32) (city_diff_time * 60));

    if (total_time < 0)
    {
        total_time = 1440 + total_time;
    }
    if (total_time > 1440)
    {
        total_time = total_time - 1440;
    }
    hour_sublcd1 = total_time / 60;
    min_sublcd1 = total_time % 60;
    time_303->nHour = (U8) hour_sublcd1;
    time_303->nMin = (U8) min_sublcd1;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  set_time_difference
 * DESCRIPTION
 *  set value of output parameter equal to input parameter
 * PARAMETERS
 *  t           [OUT]       
 *  diff        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_time_difference(MYTIME *t, MYTIME *diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *t = *diff;
}


/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_hide_function
Description:      function pointer of main lcd date hide function
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_main_LCD_dt_hide_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_update_function
Description:      function pointer of main lcd date update  function
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_main_LCD_dt_update_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_display_function
Description:      function pointer of main lcd date display  function
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_main_LCD_dt_display_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_close_function
Description:      function pointer of close date display  of main lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_main_LCD_dt_close_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_hide_function
Description:      function pointer of date hide function of sub lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_sub_LCD_dt_hide_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_update_function
Description:      function pointer of date update  function of sub lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_sub_LCD_dt_update_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_display_function
Description:      function pointer of date display  function of sub lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_sub_LCD_dt_display_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_close_function
Description:      function pointer of date close display  function of sub lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_sub_LCD_dt_close_function) (void) = UI_dummy_function;

/* PMT HIMANSHU START 20050721 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_day_hide_function
Description:      day hide funtion pointer of main lcd 
Input Parameters: function pointer
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_main_LCD_dt_day_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
/* PMT HIMANSHU END 20050721 */

/* Lisen0522 */


/*****************************************************************************
 * FUNCTION
 *  update_mainlcd_dt_display
 * DESCRIPTION
 *  updaet date tiem dispaly on main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_mainlcd_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    MMI_main_LCD_dt_hide_function();    /* call current hide function of date time of main lcd */
    MMI_main_LCD_dt_update_function();  /* call current update function of date time of main lcd */
    MMI_main_LCD_dt_display_function(); /* call display function of  date time of main lcd */
    gdi_layer_unlock_frame_buffer();
    /* if datetime has actual display action */
    if (MMI_main_LCD_dt_update_function != UI_dummy_function || MMI_main_LCD_dt_display_function != UI_dummy_function)
    {
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}

/* Lisen0522 */


/*****************************************************************************
 * FUNCTION
 *  update_sublcd_dt_display
 * DESCRIPTION
 *  updaet date tiem dispaly on main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_sublcd_dt_display(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_hide_function();     /* call current hide function of date time of sub lcd */
    MMI_sub_LCD_dt_update_function();   /* call current update function of date time of sub lcd */
    MMI_sub_LCD_dt_display_function();  /* call display function of  date time of sub lcd */
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  show_main_LCD_dt_display
 * DESCRIPTION
 *  get current tiem and update date time of main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_main_LCD_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_update_function();  /* call update function of date teime of main lcd */
    MMI_main_LCD_dt_display_function(); /* call display func of date time of main lcd */
}


/*****************************************************************************
 * FUNCTION
 *  show_sub_LCD_dt_display
 * DESCRIPTION
 *  get current tiem and update date time of sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_sub_LCD_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_update_function();   /* call update function of date teime of sub lcd */
    MMI_sub_LCD_dt_display_function();  /* call display func of date time of sub lcd */
}


/*****************************************************************************
 * FUNCTION
 *  UI_dummy_hide_function
 * DESCRIPTION
 *  dummy hide function :- clear the particular area with white color
 * PARAMETERS
 *  x1      [IN]        Start x postion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // PMT DLT_FIXES - TK 200603225 START   /*background color should be taken from the current MMI theme*/
    color c = *current_MMI_theme->datetime_bar_background_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      color c=gui_color(255,255,255);
    //PMT DLT_FIXES - TK 200603225 END
    gdi_layer_reset_clip();
    gui_fill_rectangle(x1, y1, x2, y2, c);
}

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
extern S32 MAIN_LCD_device_width;
#endif 

#define DT_DISPLAY_GAP  1
#define DT_SOFTKEY_GAP  2


U8 enable_main_LCD_date_time_display = 1;
U8 enable_sub_LCD_date_time_display = 1;

#if defined (__MMI_MAINLCD_128X128__)
#define GUI_CALENDAR_TIME_Y     93
#define GUI_CALENDAR_DATE_Y     76
#endif/* defined (__MMI_MAINLCD_128X128__) */

/*****************************************************************************
 * FUNCTION
 *  show_main_LCD_date_time
 * DESCRIPTION
 *  show upadte date time on main lcd /sub lcd depend on the
 *  current date flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_main_LCD_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 h, w, x, y;
    UI_character_type s[64];
    S32 x1, y1, x2, y2;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;
    S32 old_x1, old_y1, old_x2, old_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (main_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    UI_set_main_LCD_graphics_context();

    old_x1 =
        (main_LCD_dt_object.time.x < main_LCD_dt_object.date.x) ? main_LCD_dt_object.time.x : main_LCD_dt_object.date.x;
    old_y1 =
        (main_LCD_dt_object.time.y < main_LCD_dt_object.date.y) ? main_LCD_dt_object.time.y : main_LCD_dt_object.date.y;
    old_x2 =
        (main_LCD_dt_object.time.x + main_LCD_dt_object.time.width >
         main_LCD_dt_object.date.x + main_LCD_dt_object.date.width) ? main_LCD_dt_object.time.x +
        main_LCD_dt_object.time.width : main_LCD_dt_object.date.x + main_LCD_dt_object.date.width;
    old_y2 =
        (main_LCD_dt_object.time.y + main_LCD_dt_object.time.height >
         main_LCD_dt_object.date.y + main_LCD_dt_object.date.height) ? main_LCD_dt_object.time.y +
        main_LCD_dt_object.time.height : main_LCD_dt_object.date.y + main_LCD_dt_object.date.height;

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    switch (main_LCD_dt_object.flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
        {
                    if (enable_main_LCD_date_time_display)
                    {
                wgui_clock_show_main_lcd();
                    }

                #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            show_main_LCD_day_display();
                #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                coordinates.s16X = main_LCD_dt_object.time.x;
                coordinates.s16Y = main_LCD_dt_object.time.y;
                coordinates.s16Width = main_LCD_dt_object.time.width;
                coordinates.s16Height = main_LCD_dt_object.time.height;
                setup_previous_control(&coordinates);
            }
        }
            break;

        case DT_IDLE_SCREEN_2:
        {
            if (enable_main_LCD_date_time_display)
            {
                wgui_clock_show_main_lcd();
            }

        }
            break;

        case DT_NETWORK_SEARCH:
        {
            gui_set_font(main_LCD_dt_object.time.font);
            /* get current time in string format */
            time_string(&main_LCD_dt_object.time.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = (UI_device_width >> 1) - (w >> 1);

        #if defined(__MMI_UI_DALMATIAN_IDLESCREEN__)
            y = UI_device_height - MMI_button_bar_height - (h + (BAR_CONTENT_GAP));
        #else 
            y = UI_device_height - MMI_softkey_height - (h + (DT_DISPLAY_GAP << 1)) - 1;
        #endif 

            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.time.text_color);
                gui_set_text_border_color(main_LCD_dt_object.time.text_border_color);

            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
            #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y + 1);
                }
                else
                {
                    gui_move_text_cursor(x, y + 1);
                }
            #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
                x2 = x1 + main_LCD_dt_object.time.width - 1;
                y2 = y1 + main_LCD_dt_object.time.height - 1;

            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                gui_set_text_clip(x1 - 1, y1, x2, y2);  /* For proper clipping of the text */
            #else 
                gui_set_text_clip(x1, y1, x2, y2);
            #endif 
                gui_print_bordered_text(s);

                if (x1 < old_x1)
                {
                    old_x1 = x1;
                }
                if (y1 < old_y1)
                {
                    old_y1 = y1;
                }
                if (x2 > old_x2)
                {
                    old_x2 = x2;
                }
                if (y2 > old_y2)
                {
                    old_y2 = y2;
                }
            }
            gui_set_font(main_LCD_dt_object.date.font);
            /* get date in string format */
            date_string(&main_LCD_dt_object.date.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = (UI_device_width >> 1) - (w >> 1);
        #if defined(__MMI_UI_DALMATIAN_IDLESCREEN__) || defined(__MMI_MAINLCD_128X128__)//060606 network search Calvin
            y = y - h - 1;  /* to handle the font height change on dalmatian */
        #else 
            y = y - main_LCD_dt_object.time.height;
        #endif 

            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.date.text_color);
                gui_set_text_border_color(main_LCD_dt_object.date.text_border_color);

            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
            #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y + 1);
                }
                else
                {
                    gui_move_text_cursor(x, y + 1);
                }
            #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

                x2 = x1 + main_LCD_dt_object.date.width - 1;
                y2 = y1 + main_LCD_dt_object.date.height - 1;

            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                gui_set_text_clip(x1 - 1, y1, x2, y2);
            #else 
                gui_set_text_clip(x1, y1, x2, y2);
            #endif 
                gui_print_bordered_text(s);
                gdi_layer_blt_previous(
                    x1 < old_x1 ? x1 : old_x1,
                    y1 < old_y1 ? y1 : old_y1,
                    x2 > old_x2 ? x2 : old_x2,
                    y2 > old_y2 ? y2 : old_y2);
            }
            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                coordinates.s16X = main_LCD_dt_object.time.x;
                coordinates.s16Y = main_LCD_dt_object.time.y;
                coordinates.s16Width = main_LCD_dt_object.time.width;
                coordinates.s16Height = main_LCD_dt_object.time.height;
                setup_previous_control(&coordinates);
            }
        }
            break;

        case DT_MO_CALL_SCREEN:
        case DT_MO_CALLING_SCREEN:
        {
            y = MMI_status_bar_height;
            gui_set_font(main_LCD_dt_object.date.font);
            /* get current date in string format */
            date_string(&main_LCD_dt_object.date.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = 2;
            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w;
            main_LCD_dt_object.date.height = h;
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.date.text_color);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = x1 + main_LCD_dt_object.date.width - 1;
                y2 = y1 + main_LCD_dt_object.date.height - 1;
                /* print current date */
                gui_print_text(s);
                if (x1 < old_x1)
                {
                    old_x1 = x1;
                }
                if (y1 < old_y1)
                {
                    old_y1 = y1;
                }
                if (x2 > old_x2)
                {
                    old_x2 = x2;
                }
                if (y2 > old_y2)
                {
                    old_y2 = y2;
                }
            }

            gui_set_font(main_LCD_dt_object.time.font);
            x = 2;
            y = y + h;
            time_string(&main_LCD_dt_object.time.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            /* get current tiem in string format */
            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w;
            main_LCD_dt_object.time.height = h;
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.time.text_color);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = x1 + main_LCD_dt_object.time.width - 1;
                y2 = y1 + main_LCD_dt_object.time.height - 1;
                gui_set_text_clip(x1, y1, x2, y2);
                /* print time */
                gui_print_text(s);

                gdi_layer_blt_previous(
                    x1 < old_x1 ? x1 : old_x1,
                    y1 < old_y1 ? y1 : old_y1,
                    x2 > old_x2 ? x2 : old_x2,
                    y2 > old_y2 ? y2 : old_y2);
            }
            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                coordinates.s16X = main_LCD_dt_object.time.x;
                coordinates.s16Y = main_LCD_dt_object.time.y;
                coordinates.s16Width = main_LCD_dt_object.time.width;
                coordinates.s16Height = main_LCD_dt_object.time.height;
                setup_previous_control(&coordinates);
            }
        }
            break;

        case DT_MT_CALL_SCREEN:
        {
            y = (MMI_title_y + MMI_title_height);
            gui_set_font(main_LCD_dt_object.date.font);
            /* get current date in string format */
            date_string(&main_LCD_dt_object.date.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = 2;
            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w;
            main_LCD_dt_object.date.height = h;
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.date.text_color);

                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }

                x2 = x1 + main_LCD_dt_object.date.width - 1;
                y2 = y1 + main_LCD_dt_object.date.height - 1;
                /* print date */
                gui_print_text(s);

                if (x1 < old_x1)
                {
                    old_x1 = x1;
                }
                if (y1 < old_y1)
                {
                    old_y1 = y1;
                }
                if (x2 > old_x2)
                {
                    old_x2 = x2;
                }
                if (y2 > old_y2)
                {
                    old_y2 = y2;
                }
            }

            gui_set_font(main_LCD_dt_object.time.font);
            time_string(&main_LCD_dt_object.time.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = 2;
            y = y + h;
            /* get current time in string format */
            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w;
            main_LCD_dt_object.time.height = h;
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.time.text_color);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = x1 + main_LCD_dt_object.time.width - 1;
                y2 = y1 + main_LCD_dt_object.time.height - 1;
                /* print time */
                gui_print_text(s);
                gdi_layer_blt_previous(
                    x1 < old_x1 ? x1 : old_x1,
                    y1 < old_y1 ? y1 : old_y1,
                    x2 > old_x2 ? x2 : old_x2,
                    y2 > old_y2 ? y2 : old_y2);
            }
            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                coordinates.s16X = main_LCD_dt_object.time.x;
                coordinates.s16Y = main_LCD_dt_object.time.y;
                coordinates.s16Width = main_LCD_dt_object.time.width;
                coordinates.s16Height = main_LCD_dt_object.time.height;
                setup_previous_control(&coordinates);
            }
        }
            break;
        case DT_TABBED_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        {
            if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_ACTIVE_CALL_SCREEN)//080106 active call
            {
                y = MMI_status_bar_height;
            }
            else
            {
                y = MMI_CONTENT_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT -
                    MMI_TITLE_HEIGHT;
            }

            gui_set_font(main_LCD_dt_object.date.font);
            /* get current date in string format */
            date_string(&main_LCD_dt_object.date.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = 2;
            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w;
            main_LCD_dt_object.date.height = h;
            if (enable_main_LCD_date_time_display)
            {
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
                gui_set_text_color(main_LCD_dt_object.date.text_color);
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
                if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_ACTIVE_CALL_SCREEN)
                {
                    /* use list text color to match the full screen background */
                    gui_set_text_color(*current_MMI_theme->list_normal_text_color);
                }
                else
                {
                gui_set_text_color(main_LCD_dt_object.date.text_color);
                }
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */

                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = UI_device_width - 1;
                y2 = y1 + main_LCD_dt_object.date.height - 1;
                /* print date */
                gui_print_text(s);
                if (x1 < old_x1)
                {
                    old_x1 = x1;
                }
                if (y1 < old_y1)
                {
                    old_y1 = y1;
                }
                if (x2 > old_x2)
                {
                    old_x2 = x2;
                }
                if (y2 > old_y2)
                {
                    old_y2 = y2;
                }

            }
            gui_set_font(main_LCD_dt_object.time.font);
            /* get current time in string format */
            time_string(&main_LCD_dt_object.time.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = 2;
            y = y + h;
            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w;
            main_LCD_dt_object.time.height = h;
            if (enable_main_LCD_date_time_display)
            {
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
                gui_set_text_color(main_LCD_dt_object.time.text_color);
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
                if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_ACTIVE_CALL_SCREEN)
                {
                    /* use list text color to match the full screen background */
                    gui_set_text_color(*current_MMI_theme->list_normal_text_color);
                }
                else
                {
                gui_set_text_color(main_LCD_dt_object.time.text_color);
                }
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */

                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = x1 + main_LCD_dt_object.time.width - 1;
                y2 = y1 + main_LCD_dt_object.time.height - 1;
                /* print time */
                gui_print_text(s);
                gdi_layer_blt_previous(
                    x1 < old_x1 ? x1 : old_x1,
                    y1 < old_y1 ? y1 : old_y1,
                    x2 > old_x2 ? x2 : old_x2,
                    y2 > old_y2 ? y2 : old_y2);
            }
            if (!(FALSE == GetCallTimeDisplay()))
            {
                gui_set_font(main_LCD_dt_object.duration.font);
                x = 2;
                y = y + h;
                /* get call duration in string format */
                duration_string(&main_LCD_dt_object.duration.t, (UI_string_type) s, main_LCD_dt_object.flags);
                gui_measure_string(s, &w, &h);
                x1 = main_LCD_dt_object.duration.x = x;
                y1 = main_LCD_dt_object.duration.y = y;
                main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
                if (enable_main_LCD_date_time_display)
                {
                    gui_set_text_color(main_LCD_dt_object.duration.text_color);

                    if (r2lMMIFlag)
                    {
                        gui_move_text_cursor(x + w - 1, y);
                    }
                    else
                    {
                        gui_move_text_cursor(x, y);
                    }
                    x2 = x1 + main_LCD_dt_object.duration.width - 1;
                    y2 = y1 + main_LCD_dt_object.duration.height - 1;
                    /* display call duration in active acll screen */
                    gui_print_text(s);
                    gdi_layer_blt_previous(
                        x1 < old_x1 ? x1 : old_x1,
                        y1 < old_y1 ? y1 : old_y1,
                        x2 > old_x2 ? x2 : old_x2,
                        y2 > old_y2 ? y2 : old_y2);
                }
            }
            else
            {
                y = y + h;
                x1 = main_LCD_dt_object.duration.x = x;
                #ifdef __MMI_UCM__
                    if (mmi_ucm_app_active_call(MMI_UCM_VOICE_CALL_TYPE_ALL) + mmi_ucm_app_held_call(MMI_UCM_VOICE_CALL_TYPE_ALL) != 1)
                #else /* __MMI_UCM__ */   
                if (GetTotalActiveCallCount() + GetTotalHoldCallCount() != 1)
                #endif /* __MMI_UCM__ */
                {
                    y1 = main_LCD_dt_object.duration.y = main_LCD_dt_object.date.y + main_LCD_dt_object.date.height;
                }
                else
                {
                    y1 = main_LCD_dt_object.duration.y = y;
                }
                main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
            }
            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                coordinates.s16X = main_LCD_dt_object.duration.x;
                coordinates.s16Y = main_LCD_dt_object.duration.y;
                coordinates.s16Width = main_LCD_dt_object.duration.width;
                coordinates.s16Height = main_LCD_dt_object.duration.height;
                setup_previous_control(&coordinates);
            }
        }
            break;

        case DT_VOIP_CALL_SCREEN:
        {
            gui_set_font(main_LCD_dt_object.duration.font);
            /* get call duration in string format */
            duration_string(&main_LCD_dt_object.duration.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);

            if (!(FALSE == GetCallTimeDisplay()))
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
                if (enable_main_LCD_date_time_display)
                {
                    gui_set_text_color(main_LCD_dt_object.duration.text_color);

                    if (r2lMMIFlag)
                    {
                        gui_move_text_cursor(x1 + w - 1, y1);
                    }
                    else
                    {
                        gui_move_text_cursor(x1, y1);
                    }
                    x2 = x1 + main_LCD_dt_object.duration.width - 1;
                    y2 = y1 + main_LCD_dt_object.duration.height - 1;
                    /* display call duration in active acll screen */
                    gui_print_text(s);
                    if (x1 < old_x1)
                    {
                        old_x1 = x1;
                    }
                    if (y1 < old_y1)
                    {
                        old_y1 = y1;
                    }
                    if (x2 > old_x2)
                    {
                        old_x2 = x2;
                    }
                    if (y2 > old_y2)
                    {
                        old_y2 = y2;
                    }
                    gdi_layer_blt_previous(
                        x1 < old_x1 ? x1 : old_x1,
                        y1 < old_y1 ? y1 : old_y1,
                        x2 > old_x2 ? x2 : old_x2,
                        y2 > old_y2 ? y2 : old_y2);
                }
            }
            else
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
            }
            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                coordinates.s16X = main_LCD_dt_object.duration.x;
                coordinates.s16Y = main_LCD_dt_object.duration.y;
                coordinates.s16Width = main_LCD_dt_object.duration.width;
                coordinates.s16Height = main_LCD_dt_object.duration.height;
                setup_previous_control(&coordinates);
            }
        }
            break;

        case DT_DIGITAL_CLOCK_SC1:
        {
                if (enable_main_LCD_date_time_display)
                {
                wgui_clock_show_main_lcd();
                    }

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                gdi_layer_push_clip();
                gui_set_clip(
                    0,
                    0,
                    UI_device_width - 1,
                    UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 2 - 1);
                show_boundries_to_status_bar_at_bottom_idlescreen();
                gdi_layer_pop_clip();
                gdi_layer_blt_previous(
                    0,
                    0,
                    (UI_device_width - 1),
                    (UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 1 - 2));
            }
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                if (show_date == 0)
                {
                    coordinates.s16X = main_LCD_dt_object.date.x;
                    coordinates.s16Y = main_LCD_dt_object.date.y;
                    coordinates.s16Width = main_LCD_dt_object.date.width;
                    coordinates.s16Height = main_LCD_dt_object.date.height;
                    setup_previous_control(&coordinates);
                }
                else
                {
                    coordinates.s16X = main_LCD_dt_object.time.x;
                    coordinates.s16Y = main_LCD_dt_object.time.y;
                    coordinates.s16Width = main_LCD_dt_object.time.width;
                    coordinates.s16Height = main_LCD_dt_object.time.height;
                    setup_previous_control(&coordinates);
                }
            }
        }
            break;

        case DT_DIGITAL_CLOCK_SC2:
        {
            if (enable_main_LCD_date_time_display)
            {
                wgui_clock_show_main_lcd();
            }

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                gdi_layer_push_clip();
                gui_set_clip(
                    0,
                    0,
                    UI_device_width - 1,
                    UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 2 - 1);
                show_boundries_to_status_bar_at_bottom_idlescreen();
                gdi_layer_pop_clip();
                gdi_layer_blt_previous(
                    0,
                    0,
                    (UI_device_width - 1),
                    (UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 1 - 2));
            }
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                coordinates.s16X = main_LCD_dt_object.date.x;
                coordinates.s16Y = main_LCD_dt_object.date.y;
                coordinates.s16Width = main_LCD_dt_object.date.width;
                coordinates.s16Height = main_LCD_dt_object.date.height;
                setup_previous_control(&coordinates);
            }
        }
            break;

        case DT_DIGITAL_CLOCK_SC3:
        {
            if (enable_main_LCD_date_time_display)
            {
                wgui_clock_show_main_lcd();
            }
        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                gdi_layer_push_clip();
                gdi_layer_set_clip(
                    0,
                    0,
                    UI_device_width - 1,
                    UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 2 - 1);
                show_boundries_to_status_bar_at_bottom_idlescreen();
                gdi_layer_pop_clip();
                gdi_layer_blt_previous(
                    0,
                    0,
                    (UI_device_width - 1),
                    (UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 1 - 2));
            }
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                coordinates.s16X = main_LCD_dt_object.time.x;
                coordinates.s16Y = main_LCD_dt_object.time.y;
                coordinates.s16Width = main_LCD_dt_object.time.width;
                coordinates.s16Height = main_LCD_dt_object.time.height;
                setup_previous_control(&coordinates);
            }
        }
            break;

    #ifdef __MMI_ANALOG_CLOCK__
        case DT_ANALOG_CLOCK_SC:
        {
        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                gdi_layer_push_clip();
                gui_set_clip(
                    0,
                    0,
                    UI_device_width - 1,
                    UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 2 - 1);
            }
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
            if (enable_main_LCD_date_time_display)
            {
                gdi_layer_lock_frame_buffer();
                wgui_clock_show_main_lcd();
            }

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                gdi_layer_pop_clip();
                show_boundries_to_status_bar_at_bottom_idlescreen();
            }
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            if (enable_main_LCD_date_time_display)
            {
                gdi_layer_unlock_frame_buffer();

            #if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                gdi_layer_blt_previous(
                    0,
                    (MMI_title_y + MMI_title_height),
                    (UI_device_width - 1),
                    (UI_device_height - max_touch_idle_screen_shortcut_height() - 1));
            #else /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 

            #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
                if (is_on_idlescreen())
                {
                    gdi_layer_blt_previous(
                        0,
                        0,
                        (UI_device_width - 1),
                        (UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 1 - 2));
                }
                else
            #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
                    gdi_layer_blt_previous(
                        0,
                        (MMI_title_y + MMI_title_height),
                        (UI_device_width - 1),
                        (UI_device_height - 1));
            #endif /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 
            }
            if (enable_main_LCD_date_time_display)
            {
                dm_coordinates coordinates;

                if (show_date == 0)
                {
                    coordinates.s16X = main_LCD_dt_object.date.x;
                    coordinates.s16Y = main_LCD_dt_object.date.y;
                    coordinates.s16Width = main_LCD_dt_object.date.width;
                    coordinates.s16Height = main_LCD_dt_object.date.height;
                    setup_previous_control(&coordinates);
                }
                else
                {
                    coordinates.s16X = ANALOG_CLOCK_DIAL_X;
                    coordinates.s16Y = ANALOG_CLOCK_DIAL_Y;
                    coordinates.s16Width = ANALOG_CLOCK_DIAL_WIDTH;
                    coordinates.s16Height = ANALOG_CLOCK_DIAL_HEIGHT;
                    setup_previous_control(&coordinates);
                }
            }
        }
            break;
    #endif /* __MMI_ANALOG_CLOCK__ */ 
    }
    gdi_layer_pop_clip();

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
}


/*****************************************************************************
 * FUNCTION
 *  hide_main_LCD_date_time
 * DESCRIPTION
 *  hide function of main lcd date time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void hide_main_LCD_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (main_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    UI_set_main_LCD_graphics_context();
    switch (main_LCD_dt_object.flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
        case DT_IDLE_SCREEN_2:
        case DT_NETWORK_SEARCH:
        case DT_MO_CALL_SCREEN:
        case DT_MO_CALLING_SCREEN:
        case DT_MT_CALL_SCREEN:
        {
            /*
             * MTK Justin
             * 
             * Note that we should hide "date" first, then hide "time".
             * The sequence should not be changed.
             * 
             * This is for a hack for optimizing the speed of redraw background image.
             * Please refer to  idle_screen_hide_date_display and
             * idle_screen_hide_time_display
             * 
             * MTK Justin end
             */
            x1 = main_LCD_dt_object.date.x;
            y1 = main_LCD_dt_object.date.y;
            x2 = main_LCD_dt_object.date.width + x1 - 1;
            y2 = main_LCD_dt_object.date.height + y1 - 1;
            main_LCD_dt_object.date.hide_function(x1, y1, x2, y2);

            if (x1 > main_LCD_dt_object.time.x)
            {
                x1 = main_LCD_dt_object.time.x;
            }
            y1 = main_LCD_dt_object.date.y - 1;
            if (x2 < main_LCD_dt_object.time.width + main_LCD_dt_object.time.x)
            {
                x2 = main_LCD_dt_object.time.width + main_LCD_dt_object.time.x - 1;
            }
            y2 = main_LCD_dt_object.time.y + main_LCD_dt_object.time.height - 1;
            main_LCD_dt_object.time.hide_function(x1, y1, x2, y2);      /* call hide function of idle,netwroksearch,call screen */
        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN)
            {
                if (g_clock_type == ANALOG)
				{
                x1 = ANALOG_BACKGROUND_X + ANALOG_BACKGROUND_WIDTH;
				}
				else
				{
					x1 = DIGITAL_BACKGROUND_X + DIGITAL_BACKGROUND_WIDTH;
				}
                y1 = MMI_status_bar_height + (MMI_IDLESCREEN_BAR_HEIGHT >> 1);
                x2 = UI_device_width - MMI_SIGNAL_WIDTH;
                y2 = y1 + (MMI_IDLESCREEN_BAR_HEIGHT >> 1) - 1;
                MMI_main_LCD_dt_day_hide_function(x1, y1, x2, y2);
            }
        #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

        }
            break;
        case DT_TABBED_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        {
            x1 = main_LCD_dt_object.date.x;
            y1 = main_LCD_dt_object.date.y;
            x2 = main_LCD_dt_object.date.width + x1 - 1;
            y2 = main_LCD_dt_object.date.height + y1 - 1;
            if (main_LCD_dt_object.flags & DT_FLAGS_TYPE == DT_ACTIVE_CALL_SCREEN)
            {
                main_LCD_dt_object.date.hide_function(x1, y1, x2, y2);
            }
            else
            {
                main_LCD_dt_object.date.hide_function(0, y1, UI_device_width - 1, y2);
            }

            x1 = main_LCD_dt_object.time.x;
            y1 = main_LCD_dt_object.time.y;
            x2 = main_LCD_dt_object.time.width + x1 - 1;
            y2 = main_LCD_dt_object.time.height + y1 - 1;
            if (main_LCD_dt_object.flags & DT_FLAGS_TYPE == DT_ACTIVE_CALL_SCREEN)
            {
                main_LCD_dt_object.time.hide_function(x1, y1, x2, y2);
            }
            else
            {
                main_LCD_dt_object.time.hide_function(0, y1, UI_device_width - 1, y2);
            }

            if (!(FALSE == GetCallTimeDisplay()))
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                x2 = main_LCD_dt_object.duration.width + x1 - 1;
                y2 = main_LCD_dt_object.duration.height + y1 - 1;
                if (main_LCD_dt_object.flags & DT_FLAGS_TYPE == DT_ACTIVE_CALL_SCREEN)
                {
                    main_LCD_dt_object.duration.hide_function(x1, y1, x2, y2);
                }
                else
                {
                    main_LCD_dt_object.duration.hide_function(0, y1, UI_device_width - 1, y2);
                }
            }
        }
            break;
        case DT_VOIP_CALL_SCREEN:
        {
            if (!(FALSE == GetCallTimeDisplay()))
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                x2 = main_LCD_dt_object.duration.width + x1 - 1;
                y2 = main_LCD_dt_object.duration.height + y1 - 1;
                main_LCD_dt_object.duration.hide_function(0, y1, UI_device_width - 1, y2);
            }
        }

            break;

        case DT_DIGITAL_CLOCK_SC1:
        case DT_DIGITAL_CLOCK_SC2:
        case DT_DIGITAL_CLOCK_SC3:
        {
            x1 = main_LCD_dt_object.date.x;
            y1 = main_LCD_dt_object.date.y;
            x2 = main_LCD_dt_object.date.width + x1 - 1;
            y2 = main_LCD_dt_object.date.height + y1 - 1;
            main_LCD_dt_object.date.hide_function(x1, y1, x2, y2);

            x1 = main_LCD_dt_object.time.x;
            y1 = main_LCD_dt_object.time.y;
            x2 = main_LCD_dt_object.time.width + x1 - 1;
            y2 = main_LCD_dt_object.time.height + y1 - 1;
            main_LCD_dt_object.time.hide_function(x1, y1, x2, y2);
        }
            break;

    #ifdef __MMI_ANALOG_CLOCK__
        case DT_ANALOG_CLOCK_SC:
        {
            x1 = main_LCD_dt_object.time.x;
            y1 = main_LCD_dt_object.time.y;
            x2 = main_LCD_dt_object.time.width + x1 - 1;
            y2 = main_LCD_dt_object.time.height + y1 - 1;
            main_LCD_dt_object.time.hide_function(x1, y1, x2, y2);
        }
            break;
    #endif /* __MMI_ANALOG_CLOCK__ */ 
    }
    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
}


/*****************************************************************************
 * FUNCTION
 *  update_main_LCD_date_time
 * DESCRIPTION
 *  update main lcd date time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_main_LCD_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&main_LCD_dt_object.date.t);
    main_LCD_dt_object.time.t = main_LCD_dt_object.date.t;
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    set_day_display();
#endif 

    wgui_clock_update_main_lcd();
}


/*****************************************************************************
 * FUNCTION
 *  set_dt_duration
 * DESCRIPTION
 *  set the call duration of category17
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_dt_duration(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_dt_object.duration.t = *t; /* set the duration value */
    DTGetRTCTime(&last_duration_time);
}

void main_LCD_measure_time_duration_string(S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    UI_character_type s[64];
    U16 hours, minutes, seconds;
    S8 ts[32];
    U16 i;
    S32 width, height, max_width, max_height;
    
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(main_LCD_time_object.duration.font);

    for (i = 0, max_width = 0, max_height = 0; i <= 9; i ++)
    {
        hours = i;
        minutes = i;
        seconds = i;
    switch (main_LCD_dt_object.flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
        case DT_IDLE_SCREEN_ENGLISH_ONLY:
        case DT_NETWORK_SEARCH:
        case DT_MO_CALL_SCREEN:
        case DT_MO_CALLING_SCREEN:
        case DT_MT_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        case DT_TABBED_CALL_SCREEN:
        case DT_VOIP_CALL_SCREEN:
#ifdef __MMI_SUBLCD__
        case DT_SUBLCD_IDLE_SCREEN1:
        case DT_SUBLCD_IDLE_SCREEN2:
#endif /* __MMI_SUBLCD__ */ 
            sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
            break;
        case DT_AUDIO_PLAY_DURATION:
            sprintf((S8*) ts, "%02d:%02d", minutes, seconds);
            break;
        default:
                hours = i;
                minutes = i;
                seconds = i;
            sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
            break;
                
    }
    mmi_asc_to_ucs2((S8*) s, ts);

        gui_measure_string(s, &width, &height);

        if (width > max_width)
        {
            max_width = width;
        }

        if (height > max_height)
        {
            max_height = height;
        }
    }

    *w = max_width;
    *h = max_height;


}


#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  show_sub_LCD_date_time1
 * DESCRIPTION
 *  show sub lcd date time when ther is one city set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_sub_LCD_date_time1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bitmap *saved_graphics_context = current_LCD_device_bitmap;
    dm_coordinates coordinates;

#if defined(__MMI_SUBLCD_SHOW_DATE__) || defined(__MMI_SUBLCD_SHOW_TIME__)
    S32 h, w, x, y;
    UI_character_type s[64];
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y = 16; /* magic number by Pixtel */
#endif /* defined(__MMI_SUBLCD_SHOW_DATE__) || defined(__MMI_SUBLCD_SHOW_TIME__) */ 
    if (sub_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    if (enable_sub_LCD_date_time_display)
    {
        GDI_LOCK;
        UI_set_sub_LCD_graphics_context();  /* change graphic context to sub lcd */
    #ifdef __MMI_SUB_WALLPAPER__
        if (sublcd_base_layer != GDI_ERROR_HANDLE)
        {
            gdi_layer_push_and_set_active(sublcd_base_layer);
        }
    #endif /* __MMI_SUB_WALLPAPER__ */ 
    }

#ifdef __MMI_SUBLCD_SHOW_DATE__
    gui_set_font(sub_LCD_dt_object1.date.font);
    /* get current date in string format */
    date_string(&sub_LCD_dt_object1.date.t, (UI_string_type) s, sub_LCD_dt_object1.flags);
    gui_measure_string(s, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);
    x1 = sub_LCD_dt_object1.date.x = x;
    y1 = sub_LCD_dt_object1.date.y = y;
    sub_LCD_dt_object1.date.width = w;
    sub_LCD_dt_object1.date.height = h - 2;
    if (enable_sub_LCD_date_time_display)
    {

        gui_set_text_color(sub_LCD_dt_object1.date.text_color);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x + sub_LCD_dt_object1.date.width, y);
        }
        else
        {
            gui_move_text_cursor(x, y);
        }

        x2 = x1 + sub_LCD_dt_object1.date.width - 1;
        y2 = y1 + sub_LCD_dt_object1.date.height - 1;
        gui_set_text_clip(x1, y1, x2, y2);
        /* print date */
        gui_print_text(s);
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
    coordinates.s16X = sub_LCD_dt_object1.date.x;
    coordinates.s16Y = sub_LCD_dt_object1.date.y;
    coordinates.s16Width = sub_LCD_dt_object1.date.width;
    coordinates.s16Height = sub_LCD_dt_object1.date.height;
    y = y + h;
#endif /* __MMI_SUBLCD_SHOW_DATE__ */ 

#ifdef __MMI_SUBLCD_SHOW_TIME__
    gui_set_font(sub_LCD_dt_object1.time.font);
    /* get current time instring format */
    time_string(&sub_LCD_dt_object1.time.t, (UI_string_type) s, sub_LCD_dt_object1.flags);
    gui_measure_string(s, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);
#ifdef __MMI_SUBLCD_SHOW_WORLD_CLOCK__
    y = y + 14;
#endif 
    x1 = sub_LCD_dt_object1.time.x = x;
    y1 = sub_LCD_dt_object1.time.y = y;
    sub_LCD_dt_object1.time.width = w;
    sub_LCD_dt_object1.time.height = h;
    if (enable_sub_LCD_date_time_display)
    {
        gui_set_text_color(sub_LCD_dt_object1.time.text_color);
        gui_set_text_border_color(sub_LCD_dt_object1.time.text_border_color);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x + sub_LCD_dt_object1.time.width, y);
        }
        else
        {
            gui_move_text_cursor(x, y);
        }

        x2 = x1 + sub_LCD_dt_object1.time.width - 1;
        y2 = y1 + sub_LCD_dt_object1.time.height - 1;
        gui_set_text_clip(x1, y1, x2, y2);
        /* print time */
        gui_print_text(s);
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
    coordinates.s16X = sub_LCD_dt_object1.time.x;
    coordinates.s16Y = sub_LCD_dt_object1.time.y;
    coordinates.s16Width = sub_LCD_dt_object1.time.width;
    coordinates.s16Height = sub_LCD_dt_object1.time.height;

#ifndef __MMI_SUBLCD_SHOW_ONE_CITY__
    gui_set_font(sub_LCD_dt_object2.time.font);
    time_string(&sub_LCD_dt_object2.time.t, (UI_string_type) s, sub_LCD_dt_object2.flags);
    gui_measure_string(s, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);
    y = UI_device_height - h;
    x1 = sub_LCD_dt_object2.time.x = x;
    y1 = sub_LCD_dt_object2.time.y = y;
    sub_LCD_dt_object2.time.width = w;
    sub_LCD_dt_object2.time.height = h;
    if (enable_sub_LCD_date_time_display)
    {
        gui_set_text_color(sub_LCD_dt_object2.time.text_color);
        gui_set_text_border_color(sub_LCD_dt_object2.time.text_border_color);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x + sub_LCD_dt_object2.time.width, y);
        }
        else
        {
            gui_move_text_cursor(x, y);
        }
        x2 = x1 + sub_LCD_dt_object2.time.width - 1;
        y2 = y1 + sub_LCD_dt_object2.time.height - 1;
        gui_set_text_clip(x1, y1, x2, y2);
        gui_print_text(s);
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
    coordinates.s16X = sub_LCD_dt_object2.time.x;
    coordinates.s16Y = sub_LCD_dt_object2.time.y;
    coordinates.s16Width = sub_LCD_dt_object2.time.width;
    coordinates.s16Height = sub_LCD_dt_object2.time.height;
#endif /* __MMI_SUBLCD_SHOW_ONE_CITY__ */ 

#endif /* __MMI_SUBLCD_SHOW_TIME__ */ 

    setup_previous_control(&coordinates);

    if (enable_sub_LCD_date_time_display)
    {
        if (saved_graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (saved_graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }
        GDI_UNLOCK;
    #ifdef __MMI_SUB_WALLPAPER__
        if (sublcd_base_layer != GDI_ERROR_HANDLE)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __MMI_SUB_WALLPAPER__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  hide_sub_LCD_date_time1
 * DESCRIPTION
 *  hide function of date time of sub lcd when only 1 city is set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void hide_sub_LCD_date_time1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sub_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    GDI_LOCK;
    UI_set_sub_LCD_graphics_context();

#ifdef __MMI_SUBLCD_SHOW_DATE__
    x1 = sub_LCD_dt_object1.date.x;
    y1 = sub_LCD_dt_object1.date.y;
    x2 = sub_LCD_dt_object1.date.width + x1 - 1;
    y2 = sub_LCD_dt_object1.date.height + y1 - 1;
    sub_LCD_dt_object1.date.hide_function(x1, y1, x2, y2);
#endif /* __MMI_SUBLCD_SHOW_DATE__ */ 

    x1 = sub_LCD_dt_object1.time.x;
    y1 = sub_LCD_dt_object1.time.y;
    x2 = sub_LCD_dt_object1.time.width + x1 - 1;
    y2 = sub_LCD_dt_object1.time.height + y1 - 1;
    sub_LCD_dt_object1.time.hide_function(x1, y1, x2, y2);

#ifndef __MMI_SUBLCD_SHOW_ONE_CITY__
    x1 = sub_LCD_dt_object2.time.x;
    y1 = sub_LCD_dt_object2.time.y;
    x2 = sub_LCD_dt_object2.time.width + x1 - 1;
    y2 = sub_LCD_dt_object2.time.height + y1 - 1;
    sub_LCD_dt_object2.time.hide_function(x1, y1, x2, y2);
#endif /* __MMI_SUBLCD_SHOW_ONE_CITY__ */ 

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  update_sub_LCD_date_time1
 * DESCRIPTION
 *  get current date time and update date time on sublcd
 *  when one sub lcd city is set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_sub_LCD_date_time1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    GetDateTime(&sub_LCD_dt_object1.date.t);
    sub_LCD_dt_object2.date.t = sub_LCD_dt_object1.date.t;
    get_time_difference(&sub_LCD_dt_object1.date.t, dt_difference1);    /* get tiem diff of city1 with current time */
    sub_LCD_dt_object1.time.t = sub_LCD_dt_object1.date.t;

#ifndef __MMI_SUBLCD_SHOW_ONE_CITY__
    get_time_difference(&sub_LCD_dt_object2.date.t, dt_difference2);    /* get tiem diff of city2 with current time */
    sub_LCD_dt_object2.time.t = sub_LCD_dt_object2.date.t;
#endif /* __MMI_SUBLCD_SHOW_ONE_CITY__ */ 

    GDI_UNLOCK;

    wgui_clock_update_sub_lcd();
}


/*****************************************************************************
 * FUNCTION
 *  show_sub_LCD_date_time2
 * DESCRIPTION
 *  show sub lcd date tiem of 2 cities
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_sub_LCD_date_time2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sub_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    if (enable_sub_LCD_date_time_display)
    {
        wgui_clock_show_sub_lcd();
    }

}


/*****************************************************************************
 * FUNCTION
 *  hide_sub_LCD_date_time2
 * DESCRIPTION
 *  hide function of date tiem of sub lcd when 2 cities is set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void hide_sub_LCD_date_time2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sub_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    GDI_LOCK;
    UI_set_sub_LCD_graphics_context();

#if (defined  __MMI_SUBLCD_SHOW_DATE__) && (defined __MMI_SUBLCD_SHOW_TIME__)

    x1 = sub_LCD_dt_object1.date.x;
    x2 = sub_LCD_dt_object1.date.width + x1 - 1;

    if (sublcd_date_time_display_type == SUBLCD_DT_DATE_THEN_TIME_TYPE1)
    {
        y1 = sub_LCD_dt_object1.date.y;
        y2 = sub_LCD_dt_object1.time.height + sub_LCD_dt_object1.time.y - 1;
    }
    else if (sublcd_date_time_display_type == SUBLCD_DT_TIME_THEN_DATE_TYPE1)
    {
        y1 = sub_LCD_dt_object1.time.y;
        y2 = sub_LCD_dt_object1.date.height + sub_LCD_dt_object1.date.y - 1;
    }

    if (x1 > sub_LCD_dt_object1.time.x)
    {
        x1 = sub_LCD_dt_object1.time.x;
    }

    if (x2 < sub_LCD_dt_object1.time.width + sub_LCD_dt_object1.time.x - 1)
    {
        x2 = sub_LCD_dt_object1.time.width + sub_LCD_dt_object1.time.x - 1;
    }

    sub_LCD_dt_object1.time.hide_function(x1, y1, x2, y2);  /* call hide function of time sub lcd */

#elif defined (__MMI_SUBLCD_SHOW_DATE__)

    x1 = sub_LCD_dt_object1.date.x;
    y1 = sub_LCD_dt_object1.date.y;
    x2 = sub_LCD_dt_object1.date.width + x1 - 1;
    y2 = sub_LCD_dt_object1.date.height + y1 - 1;
    sub_LCD_dt_object1.time.hide_function(x1, y1, x2, y2);  /* call hide func of date sub lcd */

#elif defined (__MMI_SUBLCD_SHOW_TIME__)

    x1 = sub_LCD_dt_object1.time.x;
    y1 = sub_LCD_dt_object1.time.y;
    x2 = sub_LCD_dt_object1.time.width + x1 - 1;
    y2 = sub_LCD_dt_object1.time.height + y1 - 1;
    sub_LCD_dt_object1.time.hide_function(x1, y1, x2, y2);  /* call hide function of time sub lcd */

#endif 

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }

    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  update_sub_LCD_date_time2
 * DESCRIPTION
 *  upadet date tiem of sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_sub_LCD_date_time2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    GetDateTime(&sub_LCD_dt_object1.date.t);    /* get current date time */
    get_time_difference(&sub_LCD_dt_object1.date.t, dt_difference1);    /* get time diff between city1 and and current time */
    sub_LCD_dt_object1.time.t = sub_LCD_dt_object1.date.t;
    GDI_UNLOCK;

    wgui_clock_update_sub_lcd();

}
#endif /* __MMI_SUBLCD__ */ 

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_date_hide_function
Description:      date hide funtion pointer of main lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_main_LCD_dt_date_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_time_hide_function
Description:      time hide funtion pointer of main lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_main_LCD_dt_time_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_duration_hide_function
Description:      call time  duration  hide funtion pointer of main lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_main_LCD_dt_duration_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_date_hide_function
Description:      date  hide funtion pointer of sub  lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_sub_LCD_dt_date_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_time_hide_function
Description:      time  hide funtion pointer of sub  lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_sub_LCD_dt_time_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_duration_hide_function
Description:      call time duration   hide funtion pointer of sub  lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_sub_LCD_dt_duration_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_dt_date_hide_function
 * DESCRIPTION
 *  register date hide function of main lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_dt_date_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_date_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_dt_time_hide_function
 * DESCRIPTION
 *  register time hide function of main lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_dt_time_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_time_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_dt_duration_hide_function
 * DESCRIPTION
 *  register call time duration  hide function of main lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_dt_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_duration_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_sub_LCD_dt_date_hide_function
 * DESCRIPTION
 *  register date hide function of sub lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_sub_LCD_dt_date_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_date_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_sub_LCD_dt_time_hide_function
 * DESCRIPTION
 *  register time hide function of sub lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_sub_LCD_dt_time_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_time_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_sub_LCD_dt_duration_hide_function
 * DESCRIPTION
 *  register cal time duration  hide function of sub lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_sub_LCD_dt_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_duration_hide_function = f;
}

/* PMT HIMANSHU START 20050721 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_day_hide_function
 * DESCRIPTION
 *  register day hide function of Main LCD
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_day_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_day_hide_function = f;
}
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
/* PMT HIMANSHU END 20050721 */


/*****************************************************************************
 * FUNCTION
 *  dt_show_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void dt_show_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type s[64];
    S32 x1, y1, x2, y2;
    S32 w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    x1 = main_LCD_dt_object.duration.x;
    y1 = main_LCD_dt_object.duration.y;
    x2 = main_LCD_dt_object.duration.width + x1 - 1;
    y2 = main_LCD_dt_object.duration.height + y1 - 1;
    main_LCD_dt_object.duration.hide_function(x1, y1, x2, y2);  /* call hide function of call duration */

    gui_set_font(main_LCD_dt_object.duration.font);
    /* get call duration in string fromat */
    duration_string(&main_LCD_dt_object.duration.t, (UI_string_type) s, main_LCD_dt_object.flags);
    gui_set_text_color(main_LCD_dt_object.duration.text_color);
    w = gui_get_string_width(s);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + w - 1, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }

    gui_set_text_clip(x1, y1, x2, y2);
    /* print call duration */
    gui_print_text(s);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  dt_update_duration_cat19
 * DESCRIPTION
 *  update teh call time duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dt_update_duration_cat19(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_time, duration;
    MYTIME *start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&duration, 0, sizeof(MYTIME));

    DTGetRTCTime(&curr_time);
    start_time = GetCurrStartCallTime();

    if (start_time == NULL)
    {
        return;
    }

    /* overflow 2030/12/31/23:59:59 */
    if (start_time->nYear == 2030 && 
        curr_time.nYear < start_time->nYear)
    {
        curr_time.nYear = start_time->nYear;
        curr_time.nMonth = start_time->nMonth;
        curr_time.nDay = start_time->nDay+1;
    }

    GetTimeDifference(&curr_time, start_time, &duration);

    memcpy(&main_LCD_dt_object.duration.t, &duration, sizeof(MYTIME));

    if (!(FALSE == GetCallTimeDisplay()))
    {
		dt_show_duration();
    }
    gui_start_timer(1000, dt_update_duration_cat19);
}


/*****************************************************************************
 * FUNCTION
 *  dt_update_duration
 * DESCRIPTION
 *  update teh call time duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dt_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_time, duration;
    MYTIME *start_time;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&duration, 0, sizeof(MYTIME));

    DTGetRTCTime(&curr_time);
    start_time = GetStartCallTime();

    if (start_time == NULL)
    {
        return;
    }

    /* overflow 2030/12/31/23:59:59 */
    if (start_time->nYear == 2030 && 
        curr_time.nYear < start_time->nYear)
    {
        curr_time.nYear = start_time->nYear;
        curr_time.nMonth = start_time->nMonth;
        curr_time.nDay = start_time->nDay+1;
    }

    GetTimeDifference(&curr_time, start_time, &duration);

    memcpy(&main_LCD_dt_object.duration.t, &duration, sizeof(MYTIME));

    if (!(FALSE == GetCallTimeDisplay()))
    {
        dt_show_duration();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    }
    gui_start_timer(1000, dt_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  dt_update_duration_gprs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dt_update_duration_gprs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
#endif 
#endif /* 0 */

    increment_seconds(&main_LCD_dt_object.duration.t);  /* increment secods by 1 */
#ifdef __MMI_UCM__
    if (!(FALSE == GetCallTimeDisplay()))
    {
#endif /* __MMI_UCM__ */
    dt_show_duration();
#ifdef __MMI_UCM__
    }
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    gui_start_timer(1000, dt_update_duration_gprs);
}


/*****************************************************************************
 * FUNCTION
 *  CategoryScreenUpdateDuration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Cat19UpdateDuration(MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYTIME curr_time, duration;
    MYTIME *start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&duration, 0, sizeof(MYTIME));

    DTGetRTCTime(&curr_time);
    start_time = GetCurrStartCallTime();

    if (start_time == NULL)
    {
        return;
    }

    /* overflow 2030/12/31/23:59:59 */
    if (start_time->nYear == 2030 && 
        curr_time.nYear < start_time->nYear)
    {
        curr_time.nYear = start_time->nYear;
        curr_time.nMonth = start_time->nMonth;
        curr_time.nDay = start_time->nDay+1;
    }

    GetTimeDifference(&curr_time, start_time, &duration);

    gui_cancel_timer(dt_update_duration);
    set_dt_duration(&duration);
    if (!(FALSE == GetCallTimeDisplay()))
    {
        dt_show_duration();
    }
    gui_start_timer(1000, dt_update_duration_cat19);
}


/*****************************************************************************
 * FUNCTION
 *  reset_dt_display
 * DESCRIPTION
 *  set dt_display object to initialized value:0
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_dt_object.date.x = main_LCD_dt_object.date.y = 0;
    main_LCD_dt_object.date.height = main_LCD_dt_object.date.width = 0;
    main_LCD_dt_object.time.x = main_LCD_dt_object.time.y = 0;
    main_LCD_dt_object.time.height = main_LCD_dt_object.time.width = 0;
}

/*****************************************************************************
 * FUNCTION
 *  set_dt_update_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_dt_update_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_main_LCD_dt_update_function = update_main_LCD_date_time;        /* set function of upadet date time of main lcd */

}

/*****************************************************************************
 * FUNCTION
 *  set_dt_display
 * DESCRIPTION
 *  set teh hide/dispaly function od date time depend on the
 *  date flag passed as parameter
 * PARAMETERS
 *  flags       [IN]        Date type flag
 * RETURNS
 *  void
 *****************************************************************************/
void set_dt_display(U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 w, h, x, y, x1, y1, x2, y2, x3, y3, x4, y4;
#ifdef __MMI_SUBLCD__    
    S32 date_height, date_width;
    S32 gap;
    S32 time_height, time_width;
    S32 min_x1 = 0, min_y1 = 0, max_x2 = 0, max_y2 = 0;
#endif /* __MMI_SUBLCD__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    switch (flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
        {
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                break;  /* check if dispaly tiem date on idel screen is enabel or not */
            }
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;

        #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined(__MMI_MAINLCD_240X320__)
            main_LCD_dt_object.date.font = &MMI_large_font;
        #elif defined(__MMI_UI_DALMATIAN_IDLESCREEN__)
            main_LCD_dt_object.date.font = &MMI_medium_font;
        #else 
            main_LCD_dt_object.date.font = &MMI_medium_font;
        #endif 
	
            main_LCD_dt_object.date.text_color = *current_MMI_theme->idle_scr_date_color;
            main_LCD_dt_object.date.text_border_color = *current_MMI_theme->idle_scr_date_border_color;

        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            /* reset the display settings */
            main_LCD_dt_object.time.font = &MMI_medium_font;
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            {
        #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
            main_LCD_dt_object.time.font = &MMI_medium_font;
        #else 
            main_LCD_dt_object.time.font = &MMI_large_font;
        #endif 
            }
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
        
            main_LCD_dt_object.time.text_color = *current_MMI_theme->idle_scr_time_color;
            main_LCD_dt_object.time.text_border_color = *current_MMI_theme->idle_scr_time_border_color;
	
            /*test start*/

        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            switch (g_clock_type)
            {
                case ANALOG:
                    {
                    wgui_clock_create(
                        WGUI_CLOCK_MAINLCD_CLOCK1,
                        ANALOG_CLOCK_DIAL_X + 12 + 1,
                        ANALOG_CLOCK_DIAL_Y + 12 + 1,
                        ANALOG_CLOCK_DIAL_WIDTH - 24,
                        ANALOG_CLOCK_DIAL_HEIGHT - 24,
                        GUI_CLOCK_TYPE_ANALOG);
                    wgui_clock_set_on_idle(WGUI_CLOCK_MAINLCD_CLOCK1, MMI_TRUE);
                    }
                    break;
                case DIGITAL:

        #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

                    wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK1,
                        0,0,0,0,
                        GUI_CLOCK_TYPE_DIGITAL_TIME);

                    wgui_clock_set_on_idle(WGUI_CLOCK_MAINLCD_CLOCK1, MMI_TRUE);

                    wgui_clock_set_time_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                        main_LCD_dt_object.time.font);
                    wgui_clock_set_time_text_color(WGUI_CLOCK_MAINLCD_CLOCK1,
                        main_LCD_dt_object.time.text_color);
                    wgui_clock_set_time_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                        main_LCD_dt_object.time.text_border_color);
	
                    wgui_clock_measure_time_text(WGUI_CLOCK_MAINLCD_CLOCK1, 
                        &w, &h, main_LCD_dt_object.time.font);

                #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
                    x = DIGITAL_BACKGROUND_X + (DIGITAL_BACKGROUND_WIDTH >> 1) - (w >> 1);
                    y = MMI_status_bar_height + (MMI_IDLESCREEN_BAR_HEIGHT >> 1) - (h >> 1);

                #elif defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                    /* change in value of y, when the __MMI_UI_TECHNO_IDLESCREEN_BAR__
                       is not enabled and idlescreen shortcuts are enabled. */
                    x = (UI_device_width >> 1) - (w >> 1);
                    y = UI_device_height - max_touch_idle_screen_shortcut_height() - (h + (DT_DISPLAY_GAP << 1)) - 4;
        #else 
                    /* calculate start x ,y and end x,y position of time display string */
                    x = (UI_device_width >> 1) - (w >> 1);
                    y = UI_device_height - MMI_softkey_height - (h + (DT_DISPLAY_GAP << 1)) - 4;
        #endif 

            #if defined (__MMI_MAINLCD_128X128__)
                    y = GUI_CALENDAR_TIME_Y;
            #endif /* defined (__MMI_MAINLCD_128X128__) */

                    w += 2;                
                    main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
                    main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);
					x1 = main_LCD_dt_object.time.x = x - DT_DISPLAY_GAP;
                    y1 = main_LCD_dt_object.time.y = y - DT_DISPLAY_GAP;

                    wgui_clock_move(WGUI_CLOCK_MAINLCD_CLOCK1, 
                        x1, y1);
                    wgui_clock_resize(WGUI_CLOCK_MAINLCD_CLOCK1,
                        main_LCD_dt_object.time.width,
                        main_LCD_dt_object.time.height);

                    x2 = x1 + main_LCD_dt_object.time.width - 1;
                    y2 = y1 + main_LCD_dt_object.time.height - 1;
                    
        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            }
        #endif /*__MMI_UI_TECHNO_IDLESCREEN_BAR__*/


            wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK2, 
                0,0,0,0, 
                GUI_CLOCK_TYPE_DIGITAL_DATE);

            wgui_clock_set_on_idle(WGUI_CLOCK_MAINLCD_CLOCK2, MMI_TRUE);


            wgui_clock_set_date_text_font(WGUI_CLOCK_MAINLCD_CLOCK2, 
                main_LCD_dt_object.date.font);
            wgui_clock_set_date_text_color(WGUI_CLOCK_MAINLCD_CLOCK2,
                main_LCD_dt_object.date.text_color);
            wgui_clock_set_date_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK2, 
                main_LCD_dt_object.date.text_border_color);

            wgui_clock_measure_date_text(WGUI_CLOCK_MAINLCD_CLOCK2, 
                &w, &h, main_LCD_dt_object.date.font);
        
            /* calculate start x,y and end x,y position of date string display */
            w += 2;
            main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);

        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            x = ((MAIN_LCD_device_width - MMI_SIGNAL_WIDTH - 2) - w);
            y = MMI_status_bar_height + (MMI_IDLESCREEN_BAR_HEIGHT >> 2) - (h >> 1);
        #else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
            x = (UI_device_width >> 1) - (main_LCD_dt_object.date.width >> 1);
            y = y - main_LCD_dt_object.time.height;
        #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

        #if defined (__MMI_MAINLCD_128X128__)
            y = GUI_CALENDAR_DATE_Y;
        #endif /* defined (__MMI_MAINLCD_128X128__) */

            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;

            wgui_clock_move(WGUI_CLOCK_MAINLCD_CLOCK2,
                x1, y1);
            wgui_clock_resize(WGUI_CLOCK_MAINLCD_CLOCK2,
                main_LCD_dt_object.date.width,
                main_LCD_dt_object.date.height);

            /*test end*/
	

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;    /* set function pointer of hide func of date time of main lcd */
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time; /* set func piinter of show date time of main lcd */

        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
        #else 
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;        /* set function of upadet date time of main lcd */
        #endif 

            MMI_main_LCD_dt_update_function();  /* upadet date tiem */
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function(); /* display date tiem on main lcd */
            enable_main_LCD_date_time_display = 1;
        }
            break;

            /* Date/Time display is above softkeys */
        case DT_IDLE_SCREEN_2:
        {
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                break;  /* check if dispaly tiem date on idel screen is enabel or not */
            }

            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;

            main_LCD_dt_object.date.font = &MMI_medium_font;
            main_LCD_dt_object.date.text_color = *current_MMI_theme->idle_scr_date_color;
            main_LCD_dt_object.date.text_border_color = *current_MMI_theme->idle_scr_date_border_color;

            main_LCD_dt_object.time.font = &MMI_medium_font;
            main_LCD_dt_object.time.text_color = *current_MMI_theme->idle_scr_time_color;
            main_LCD_dt_object.time.text_border_color = *current_MMI_theme->idle_scr_time_border_color;

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;    /* set function pointer of hide func of date time of main lcd */
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time; /* set func piinter of show date time of main lcd */
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;        /* set function of upadet date time of main lcd */

            wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK1,
                0,0,0,0,
                GUI_CLOCK_TYPE_DIGITAL_TIME_DATE_ONE_LINE);

            wgui_clock_set_time_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.font);
            
            wgui_clock_set_time_text_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.text_color);

            wgui_clock_set_time_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.text_border_color);

            wgui_clock_set_date_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.font);

            wgui_clock_set_date_text_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.text_color);

            wgui_clock_set_date_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.text_border_color);

            wgui_clock_measure_time_text(WGUI_CLOCK_START_ID_MAIN_LCD, 
                &w, &h, main_LCD_dt_object.time.font);

            /* calculate start x ,y and end x,y position of time display string */
            x = DT_SOFTKEY_GAP;

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
        #else 
            y = UI_device_height - MMI_button_bar_height - h - DT_SOFTKEY_GAP - 1;
        #endif 

            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);
            x2 = x1 + main_LCD_dt_object.time.width - 1;
            y2 = y1 + main_LCD_dt_object.time.height - 1;

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            main_LCD_dt_object.flags &= ~DT_IDLE_SCREEN_2;
            main_LCD_dt_object.flags |= DT_IDLE_SCREEN;

        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
        
        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            main_LCD_dt_object.flags &= ~DT_IDLE_SCREEN;
            main_LCD_dt_object.flags |= DT_IDLE_SCREEN_2;
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
        
            /* calculate date string width */
            wgui_clock_measure_date_text(WGUI_CLOCK_MAINLCD_CLOCK1, 
                &w, &h, main_LCD_dt_object.date.font);
        
            /* calculate start x,y and end x,y position of date string display */
            x = UI_device_width - 1 - w - DT_SOFTKEY_GAP;

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
        #else 
            y = UI_device_height - MMI_button_bar_height - h - DT_SOFTKEY_GAP - 1;
        #endif 

            x3 = main_LCD_dt_object.date.x = x;
            y3 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);
            x4 = x3 + main_LCD_dt_object.date.width - 1;
            y4 = y3 + main_LCD_dt_object.date.height - 1;

            wgui_clock_move(WGUI_CLOCK_MAINLCD_CLOCK1, 
                min(x1, x3), min(y1,y3));

            wgui_clock_resize(WGUI_CLOCK_MAINLCD_CLOCK1, 
                max(x2, x4) - min(x1, x3) + 1, 
                max(y2, y4) - min(y1,y3) + 1);

            MMI_main_LCD_dt_update_function();  /* upadet date tiem */
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function(); /* display date tiem on main lcd */
            enable_main_LCD_date_time_display = 1;
        }
            break;

        case DT_NETWORK_SEARCH:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = &MMI_medium_font;
        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            main_LCD_dt_object.time.font = &MMI_large_font;

        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.time.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.time.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;    /* set function pointer of hide func of main lcd */
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time; /* set function pointer of show date/time of main lcd */
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;        /* set function pointer of upadet date/time of main lcd */
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;

    #ifndef __MMI_CM_SCREEN_HIDE_DATE_TIME__
        case DT_MO_CALL_SCREEN:
        case DT_MO_CALLING_SCREEN:
        case DT_MT_CALL_SCREEN:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = &MMI_medium_font;
            main_LCD_dt_object.date.text_color = *current_MMI_theme->datetime_bar_date_text_color;
            main_LCD_dt_object.time.font = &MMI_medium_font;
            main_LCD_dt_object.time.text_color = *current_MMI_theme->datetime_bar_time_text_color;
            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;

        case DT_TABBED_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;
            main_LCD_dt_object.date.font = &MMI_medium_font;
            main_LCD_dt_object.date.text_color = *current_MMI_theme->datetime_bar_date_text_color;
            main_LCD_dt_object.time.font = &MMI_medium_font;
            main_LCD_dt_object.time.text_color = *current_MMI_theme->datetime_bar_time_text_color;
            main_LCD_dt_object.duration.font = &MMI_large_font;
            main_LCD_dt_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            if ((flags & DT_FLAGS_TYPE) == DT_TABBED_CALL_SCREEN)
            {
                gui_start_timer(1000, dt_update_duration_gprs);
            }
            else
            {
                gui_start_timer(1000, dt_update_duration);
            }
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
        case DT_VOIP_CALL_SCREEN:
            {
                main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
                main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;
                main_LCD_dt_object.duration.font = &MMI_large_font;
                main_LCD_dt_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
                MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
                MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
                MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
                gui_start_timer(1000, dt_update_duration_gprs);
                MMI_main_LCD_dt_update_function();
                enable_main_LCD_date_time_display = 0;
                MMI_main_LCD_dt_display_function();
                enable_main_LCD_date_time_display = 1;
            }
                break;
    #endif /* __MMI_CM_SCREEN_HIDE_DATE_TIME__ */ 
        case DT_GPRS_ACTIVE_CALL:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;
            main_LCD_dt_object.duration.font = &MMI_small_font;
            main_LCD_dt_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
            main_LCD_dt_object.duration.x = 0;
            main_LCD_dt_object.duration.y = MMI_status_bar_height;
            main_LCD_dt_object.duration.width = UI_device_width - 1;
            main_LCD_dt_object.duration.height = DURATION_CM_HEIGHT;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time; /* set func piinter of show date time of main lcd */
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            gui_start_timer(1000, dt_update_duration_gprs);
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;

        }
            break;
        case DT_GPRS_CONF_CALL:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;
            main_LCD_dt_object.duration.font = &MMI_medium_font;
            main_LCD_dt_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
            main_LCD_dt_object.duration.x = 0;
            main_LCD_dt_object.duration.y = MMI_status_bar_height + 20;
            main_LCD_dt_object.duration.width = UI_device_width - 1;
            main_LCD_dt_object.duration.height = DURATION_CM_HEIGHT;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time; /* set func piinter of show date time of main lcd */
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            gui_start_timer(1000, dt_update_duration_gprs);
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }

    #ifdef __MMI_SUBLCD__
        case DT_SUBLCD_IDLE_SCREEN1:
        {
            sub_LCD_dt_object1.flags = (flags & DT_FLAGS_TYPE);
            sub_LCD_dt_object1.date.hide_function = MMI_sub_LCD_dt_date_hide_function;
            sub_LCD_dt_object1.time.hide_function = MMI_sub_LCD_dt_time_hide_function;
            sub_LCD_dt_object1.date.font = &MMI_small_font;
            sub_LCD_dt_object1.date.text_color = gui_color(0, 0, 0);
            sub_LCD_dt_object1.time.font = &MMI_medium_font;
            sub_LCD_dt_object1.time.text_color = gui_color(0, 0, 0);

            sub_LCD_dt_object2.flags = (flags & DT_FLAGS_TYPE);
            sub_LCD_dt_object2.date.hide_function = MMI_sub_LCD_dt_date_hide_function;
            sub_LCD_dt_object2.time.hide_function = MMI_sub_LCD_dt_time_hide_function;
            sub_LCD_dt_object2.date.font = &MMI_small_font;
            sub_LCD_dt_object2.date.text_color = gui_color(0, 0, 0);
            sub_LCD_dt_object2.time.font = &MMI_medium_font;
            sub_LCD_dt_object2.time.text_color = gui_color(0, 0, 0);

            MMI_sub_LCD_dt_hide_function = hide_sub_LCD_date_time1;
            MMI_sub_LCD_dt_display_function = show_sub_LCD_date_time1;
            MMI_sub_LCD_dt_update_function = update_sub_LCD_date_time1;
            MMI_sub_LCD_dt_update_function();
            enable_sub_LCD_date_time_display = 0;
            MMI_sub_LCD_dt_display_function();
            enable_sub_LCD_date_time_display = 1;
        }
            break;

        case DT_SUBLCD_IDLE_SCREEN2:
        {
            sublcd_date_time_display_type = SUBLCD_DT_DATE_THEN_TIME_TYPE1;
            sub_LCD_dt_object1.flags = (flags & DT_FLAGS_TYPE);
            sub_LCD_dt_object1.date.hide_function = MMI_sub_LCD_dt_date_hide_function;
            sub_LCD_dt_object1.time.hide_function = MMI_sub_LCD_dt_time_hide_function;
        #ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
            sub_LCD_dt_object1.date.font = &MMI_large_font;
        #else 
            sub_LCD_dt_object1.date.font = &MMI_small_font;
        #endif 

        #ifdef __MMI_SUB_WALLPAPER__
            sub_LCD_dt_object1.date.text_color = gui_color(255, 255, 255);
            sub_LCD_dt_object1.date.text_border_color = gui_color(0, 0, 0);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            sub_LCD_dt_object1.date.text_color = gui_color(0, 0, 0);
        #endif /* __MMI_SUB_WALLPAPER__ */ 
        #ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
            sub_LCD_dt_object1.time.font = &MMI_large_font;
        #else 
            sub_LCD_dt_object1.time.font = &MMI_medium_font;
        #endif 

        #ifdef __MMI_SUB_WALLPAPER__
            sub_LCD_dt_object1.time.text_color = gui_color(255, 255, 255);
            sub_LCD_dt_object1.time.text_border_color = gui_color(0, 0, 0);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            sub_LCD_dt_object1.time.text_color = gui_color(0, 0, 0);
        #endif /* __MMI_SUB_WALLPAPER__ */ 


            wgui_clock_create(WGUI_CLOCK_SUBLCD_CLOCK1,
                0,0,0,0,
                GUI_CLOCK_SUBLCD_TYPE2);

        #ifndef __MMI_SUB_WALLPAPER__
            wgui_clock_set_text_border_enable(WGUI_CLOCK_SUBLCD_CLOCK1, MMI_FALSE);
        #endif /* __MMI_SUB_WALLPAPER__ */ 

        #if defined (__MMI_SUBLCD_SHOW_DATE__) && defined (__MMI_SUBLCD_SHOW_TIME__)
            wgui_clock_measure_date_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &date_width,
                &date_height,
                sub_LCD_dt_object1.date.font);
        #ifdef __MMI_SUB_WALLPAPER__
            date_width += 2;    /* 2 is for border size. */
            date_height += 2;   /* 2 is for border size. */
        #endif /* __MMI_SUB_WALLPAPER__ */ 

            wgui_clock_measure_time_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &time_width,
                &time_height,
                sub_LCD_dt_object1.time.font);
        
            time_width += 2;    /* 2 is for border size. */
            time_height += 2;   /* 2 is for border size. */

            gap = (UI_device_height - Sub_lcd_title_height - date_height - time_height) / 3;

            if (sublcd_date_time_display_type == SUBLCD_DT_DATE_THEN_TIME_TYPE1)
            {
                sub_LCD_dt_object1.date.y = UI_device_height - (gap << 1) - date_height - time_height - 1;
                sub_LCD_dt_object1.time.y = UI_device_height - gap - time_height - 1;
            }
            else if (sublcd_date_time_display_type == SUBLCD_DT_TIME_THEN_DATE_TYPE1)
            {
                sub_LCD_dt_object1.time.y = UI_device_height - (gap << 1) - date_height - time_height - 1;
                sub_LCD_dt_object1.date.y = UI_device_height - gap - date_height - 1;
            }

        #elif defined (__MMI_SUBLCD_SHOW_DATE__)
            wgui_clock_measure_date_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &date_width,
                &date_height,
                sub_LCD_dt_object1.date.font);
        #ifdef __MMI_SUB_WALLPAPER__
            date_width += 2;    /* 2 is for border size. */
            date_height += 2;   /* 2 is for border size. */
        #endif /* __MMI_SUB_WALLPAPER__ */ 
            gap = (UI_device_height - Sub_lcd_title_height - date_height) >> 1;
            sub_LCD_dt_object1.date.y = UI_device_height - gap - date_height - 1;

        #elif defined (__MMI_SUBLCD_SHOW_TIME__)

            wgui_clock_measure_time_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &time_width,
                &time_height,
                sub_LCD_dt_object1.time.font);
        
            time_width += 2;    /* 2 is for border size. */
            time_height += 2;   /* 2 is for border size. */

            gap = (UI_device_height - Sub_lcd_title_height - time_height) >> 1;
            sub_LCD_dt_object1.time.y = UI_device_height - gap - time_height - 1;

        #endif 

        #ifdef __MMI_SUBLCD_SHOW_DATE__

            x1 = sub_LCD_dt_object1.date.x = (UI_device_width - date_width) >> 1;
            y1 = sub_LCD_dt_object1.date.y;
            sub_LCD_dt_object1.date.width = date_width;
            sub_LCD_dt_object1.date.height = date_height;
            x2 = x1 + date_width - 1;
            y2 = y1 + date_height - 1;

            min_x1 = x1;
            min_y1 = y1;
            max_x2 = x2;
            max_y2 = y2;

        #endif /* __MMI_SUBLCD_SHOW_DATE__ */ 

        #ifdef __MMI_SUBLCD_SHOW_TIME__
            x3 = sub_LCD_dt_object1.time.x = (UI_device_width - time_width) >> 1;
            y3 = sub_LCD_dt_object1.time.y;
            sub_LCD_dt_object1.time.width = time_width;
            sub_LCD_dt_object1.time.height = time_height;
            x4 = x3 + time_width - 1;
            y4 = y3 + time_height - 1;

            if (min_x1 == max_x2 && min_y1 == max_y2)
            {
                min_x1 = x3;
                min_y1 = y3;
                max_x2 = x4;
                max_y2 = y4;
            }
            else
            {
                min_x1 = min(min_x1, x3);
                min_y1 = min(min_y1, y3);
                max_x2 = max(max_x2, x4);
                max_y2 = max(max_y2, y4);
            }
            
        #endif /* __MMI_SUBLCD_SHOW_TIME__ */ 

            wgui_clock_move(WGUI_CLOCK_SUBLCD_CLOCK1, 0, min_y1);

            wgui_clock_resize(WGUI_CLOCK_SUBLCD_CLOCK1,
                SUBLCD_WIDTH, max_y2 - min_y1 + 1);

            wgui_clock_set_gap_between_two_lines(WGUI_CLOCK_SUBLCD_CLOCK1, 
                gap);
        
            MMI_sub_LCD_dt_hide_function = hide_sub_LCD_date_time2;
            MMI_sub_LCD_dt_display_function = show_sub_LCD_date_time2;
            MMI_sub_LCD_dt_update_function = update_sub_LCD_date_time2;
            MMI_sub_LCD_dt_update_function();
            enable_sub_LCD_date_time_display = 0;
            MMI_sub_LCD_dt_display_function();
            enable_sub_LCD_date_time_display = 1;
        }
            break;

        case DT_SUBLCD_IDLE_SCREEN3:
        {
            sublcd_date_time_display_type = SUBLCD_DT_TIME_THEN_DATE_TYPE1;
            sub_LCD_dt_object1.flags = (flags & DT_FLAGS_TYPE);
            sub_LCD_dt_object1.date.hide_function = MMI_sub_LCD_dt_date_hide_function;
            sub_LCD_dt_object1.time.hide_function = MMI_sub_LCD_dt_time_hide_function;
        #ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
            sub_LCD_dt_object1.date.font = &MMI_large_font;
        #else 
            sub_LCD_dt_object1.date.font = &MMI_small_font;
        #endif 

        #ifdef __MMI_SUB_WALLPAPER__
            sub_LCD_dt_object1.date.text_color = gui_color(255, 255, 255);
            sub_LCD_dt_object1.date.text_border_color = gui_color(0, 0, 0);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            sub_LCD_dt_object1.date.text_color = gui_color(0, 0, 0);
        #endif /* __MMI_SUB_WALLPAPER__ */ 

        #ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
            sub_LCD_dt_object1.time.font = &MMI_sublcd_font;
        #else 
            sub_LCD_dt_object1.time.font = &MMI_medium_font;
        #endif 

        #ifdef __MMI_SUB_WALLPAPER__
            sub_LCD_dt_object1.time.text_color = gui_color(255, 255, 255);
            sub_LCD_dt_object1.time.text_border_color = gui_color(0, 0, 0);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            sub_LCD_dt_object1.time.text_color = gui_color(0, 0, 0);
        #endif /* __MMI_SUB_WALLPAPER__ */ 

            wgui_clock_create(WGUI_CLOCK_SUBLCD_CLOCK1,
                0,0,0,0,
                GUI_CLOCK_SUBLCD_TYPE3);

            
        #ifndef __MMI_SUB_WALLPAPER__
            wgui_clock_set_text_border_enable(WGUI_CLOCK_SUBLCD_CLOCK1, MMI_FALSE);
        #endif /* __MMI_SUB_WALLPAPER__ */ 

        #if defined (__MMI_SUBLCD_SHOW_DATE__) && defined (__MMI_SUBLCD_SHOW_TIME__)
            wgui_clock_measure_date_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &date_width,
                &date_height,
                sub_LCD_dt_object1.date.font);
        #ifdef __MMI_SUB_WALLPAPER__
            date_width += 2;    /* 2 is for border size. */
            date_height += 2;   /* 2 is for border size. */
        #endif /* __MMI_SUB_WALLPAPER__ */ 

            wgui_clock_measure_time_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &time_width,
                &time_height,
                sub_LCD_dt_object1.time.font);
        
            time_width += 2;    /* 2 is for border size. */
            time_height += 2;   /* 2 is for border size. */

            gap = (UI_device_height - Sub_lcd_title_height - date_height - time_height) / 3;

            if (sublcd_date_time_display_type == SUBLCD_DT_DATE_THEN_TIME_TYPE1)
            {
                sub_LCD_dt_object1.date.y = UI_device_height - (gap << 1) - date_height - time_height - 1;
                sub_LCD_dt_object1.time.y = UI_device_height - gap - time_height - 1;
            }
            else if (sublcd_date_time_display_type == SUBLCD_DT_TIME_THEN_DATE_TYPE1)
            {
                sub_LCD_dt_object1.time.y = UI_device_height - (gap << 1) - date_height - time_height - 1;
                sub_LCD_dt_object1.date.y = UI_device_height - gap - date_height - 1;
            }

        #elif defined (__MMI_SUBLCD_SHOW_DATE__)
            wgui_clock_measure_date_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &date_width,
                &date_height,
                sub_LCD_dt_object1.date.font);
        #ifdef __MMI_SUB_WALLPAPER__
            date_width += 2;    /* 2 is for border size. */
            date_height += 2;   /* 2 is for border size. */
        #endif /* __MMI_SUB_WALLPAPER__ */ 
            gap = (UI_device_height - Sub_lcd_title_height - date_height) >> 1;
            sub_LCD_dt_object1.date.y = UI_device_height - gap - date_height - 1;

        #elif defined (__MMI_SUBLCD_SHOW_TIME__)

            wgui_clock_measure_time_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &time_width,
                &time_height,
                sub_LCD_dt_object1.time.font);
        
            time_width += 2;    /* 2 is for border size. */
            time_height += 2;   /* 2 is for border size. */

            gap = (UI_device_height - Sub_lcd_title_height - time_height) >> 1;
            sub_LCD_dt_object1.time.y = UI_device_height - gap - time_height - 1;

        #endif 

        #ifdef __MMI_SUBLCD_SHOW_DATE__

            x1 = sub_LCD_dt_object1.date.x = (UI_device_width - date_width) >> 1;
            y1 = sub_LCD_dt_object1.date.y;
            sub_LCD_dt_object1.date.width = date_width;
            sub_LCD_dt_object1.date.height = date_height;
            x2 = x1 + date_width - 1;
            y2 = y1 + date_height - 1;

            min_x1 = x1;
            min_y1 = y1;
            max_x2 = x2;
            max_y2 = y2;

        #endif /* __MMI_SUBLCD_SHOW_DATE__ */ 

        #ifdef __MMI_SUBLCD_SHOW_TIME__
            x3 = sub_LCD_dt_object1.time.x = (UI_device_width - time_width) >> 1;
            y3 = sub_LCD_dt_object1.time.y;
            sub_LCD_dt_object1.time.width = time_width;
            sub_LCD_dt_object1.time.height = time_height;
            x4 = x3 + time_width - 1;
            y4 = y3 + time_height - 1;

            if (min_x1 == max_x2 && min_y1 == max_y2)
            {
                min_x1 = x3;
                min_y1 = y3;
                max_x2 = x4;
                max_y2 = y4;
            }
            else
            {
                min_x1 = min(min_x1, x3);
                min_y1 = min(min_y1, y3);
                max_x2 = max(max_x2, x4);
                max_y2 = max(max_y2, y4);
            }
            
        #endif /* __MMI_SUBLCD_SHOW_TIME__ */ 

            wgui_clock_move(WGUI_CLOCK_SUBLCD_CLOCK1,
                0, min_y1);

            wgui_clock_resize(WGUI_CLOCK_SUBLCD_CLOCK1,
                SUBLCD_WIDTH, max_y2 - min_y1 + 1);

            wgui_clock_set_gap_between_two_lines(WGUI_CLOCK_SUBLCD_CLOCK1, 
                gap);
        

            MMI_sub_LCD_dt_hide_function = hide_sub_LCD_date_time2;
            MMI_sub_LCD_dt_display_function = show_sub_LCD_date_time2;
            MMI_sub_LCD_dt_update_function = update_sub_LCD_date_time2;
            MMI_sub_LCD_dt_update_function();
            enable_sub_LCD_date_time_display = 0;
            MMI_sub_LCD_dt_display_function();
            enable_sub_LCD_date_time_display = 1;
        }
            break;

        case DT_SUBLCD_IDLE_SCREEN4:
        {
            sublcd_date_time_display_type = SUBLCD_DT_TIME_THEN_DATE_TYPE1;
            sub_LCD_dt_object1.flags = (flags & DT_FLAGS_TYPE);
            sub_LCD_dt_object1.date.hide_function = MMI_sub_LCD_dt_date_hide_function;
            sub_LCD_dt_object1.time.hide_function = MMI_sub_LCD_dt_time_hide_function;
            sub_LCD_dt_object1.date.font = &MMI_medium_font;
        #ifdef __MMI_SUB_WALLPAPER__
            sub_LCD_dt_object1.date.text_color = gui_color(255, 255, 255);
            sub_LCD_dt_object1.date.text_border_color = gui_color(0, 0, 0);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            sub_LCD_dt_object1.date.text_color = gui_color(130, 230, 220);
        #endif /* __MMI_SUB_WALLPAPER__ */ 
            sub_LCD_dt_object1.time.font = &MMI_sublcd_font;
        #ifdef __MMI_SUB_WALLPAPER__
            sub_LCD_dt_object1.time.text_color = gui_color(255, 255, 255);
            sub_LCD_dt_object1.time.text_border_color = gui_color(0, 0, 0);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            sub_LCD_dt_object1.time.text_color = gui_color(255, 255, 0);
        #endif /* __MMI_SUB_WALLPAPER__ */ 

            wgui_clock_create(WGUI_CLOCK_SUBLCD_CLOCK1,
                0,0,0,0,
                GUI_CLOCK_SUBLCD_TYPE4);

        #ifndef __MMI_SUB_WALLPAPER__
            wgui_clock_set_text_border_enable(WGUI_CLOCK_SUBLCD_CLOCK1, MMI_FALSE);
        #endif /* __MMI_SUB_WALLPAPER__ */ 

        #if defined (__MMI_SUBLCD_SHOW_DATE__) && defined (__MMI_SUBLCD_SHOW_TIME__)
            wgui_clock_measure_date_text(WGUI_CLOCK_SUBLCD_CLOCK1, 
                &date_width, &date_height, sub_LCD_dt_object1.date.font);
        #ifdef __MMI_SUB_WALLPAPER__
            date_width += 2;    /* 2 is for border size. */
            date_height += 2;   /* 2 is for border size. */
        #endif /* __MMI_SUB_WALLPAPER__ */ 

            wgui_clock_measure_time_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &time_width,
                &time_height,
                sub_LCD_dt_object1.time.font);
        
            time_width += 2;    /* 2 is for border size. */
            time_height += 2;   /* 2 is for border size. */

            gap = (UI_device_height - Sub_lcd_title_height - date_height - time_height) / 3;

            if (sublcd_date_time_display_type == SUBLCD_DT_DATE_THEN_TIME_TYPE1)
            {
                sub_LCD_dt_object1.date.y = UI_device_height - (gap << 1) - date_height - time_height - 1;
                sub_LCD_dt_object1.time.y = UI_device_height - gap - time_height - 1;
            }
            else if (sublcd_date_time_display_type == SUBLCD_DT_TIME_THEN_DATE_TYPE1)
            {
                sub_LCD_dt_object1.time.y = UI_device_height - (gap << 1) - date_height - time_height - 1;
                sub_LCD_dt_object1.date.y = UI_device_height - gap - date_height - 1;
            }

        #elif defined (__MMI_SUBLCD_SHOW_DATE__)
            wgui_clock_measure_date_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &date_width,
                &date_height,
                sub_LCD_dt_object1.date.font);
        #ifdef __MMI_SUB_WALLPAPER__
            date_width += 2;    /* 2 is for border size. */
            date_height += 2;   /* 2 is for border size. */
        #endif /* __MMI_SUB_WALLPAPER__ */ 
            gap = (UI_device_height - Sub_lcd_title_height - date_height) >> 1;
            sub_LCD_dt_object1.date.y = UI_device_height - gap - date_height - 1;

        #elif defined (__MMI_SUBLCD_SHOW_TIME__)

            wgui_clock_measure_time_text(
                WGUI_CLOCK_SUBLCD_CLOCK1,
                &time_width,
                &time_height,
                sub_LCD_dt_object1.time.font);
        
            time_width += 2;    /* 2 is for border size. */
            time_height += 2;   /* 2 is for border size. */

            gap = (UI_device_height - Sub_lcd_title_height - time_height) >> 1;
            sub_LCD_dt_object1.time.y = UI_device_height - gap - time_height - 1;

        #endif 

        #ifdef __MMI_SUBLCD_SHOW_DATE__

            x1 = sub_LCD_dt_object1.date.x = (UI_device_width - date_width) >> 1;
            y1 = sub_LCD_dt_object1.date.y;
            sub_LCD_dt_object1.date.width = date_width;
            sub_LCD_dt_object1.date.height = date_height;
            x2 = x1 + date_width - 1;
            y2 = y1 + date_height - 1;

            min_x1 = x1;
            min_y1 = y1;
            max_x2 = x2;
            max_y2 = y2;

        #endif /* __MMI_SUBLCD_SHOW_DATE__ */ 

        #ifdef __MMI_SUBLCD_SHOW_TIME__
            x3 = sub_LCD_dt_object1.time.x = (UI_device_width - time_width) >> 1;
            y3 = sub_LCD_dt_object1.time.y;
            sub_LCD_dt_object1.time.width = time_width;
            sub_LCD_dt_object1.time.height = time_height;
            x4 = x3 + time_width - 1;
            y4 = y3 + time_height - 1;

            if (min_x1 == max_x2 && min_y1 == max_y2)
            {
                min_x1 = x3;
                min_y1 = y3;
                max_x2 = x4;
                max_y2 = y4;
            }
            else
            {
                min_x1 = min(min_x1, x3);
                min_y1 = min(min_y1, y3);
                max_x2 = max(max_x2, x4);
                max_y2 = max(max_y2, y4);
            }
            
        #endif /* __MMI_SUBLCD_SHOW_TIME__ */ 

            wgui_clock_move(WGUI_CLOCK_SUBLCD_CLOCK1,
                0, min_y1);

            wgui_clock_resize(WGUI_CLOCK_SUBLCD_CLOCK1,
                SUBLCD_WIDTH, max_y2 - min_y1 + 1);

            wgui_clock_set_gap_between_two_lines(WGUI_CLOCK_SUBLCD_CLOCK1, 
                gap);

            MMI_sub_LCD_dt_hide_function = hide_sub_LCD_date_time2;
            MMI_sub_LCD_dt_display_function = show_sub_LCD_date_time2;
            MMI_sub_LCD_dt_update_function = update_sub_LCD_date_time2;
            MMI_sub_LCD_dt_update_function();
            enable_sub_LCD_date_time_display = 0;
            MMI_sub_LCD_dt_display_function();
            enable_sub_LCD_date_time_display = 1;
        }
            break;
    #endif /* __MMI_SUBLCD__ */ 
        case DT_DIGITAL_CLOCK_SC1:
        {
        
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                show_date = 1;
            }
            else
            {
                show_date = 0;
            }
        
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = &MMI_medium_font;
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
            main_LCD_dt_object.time.font = &MMI_medium_font;
            main_LCD_dt_object.time.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
#else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = *current_MMI_theme->idle_scr_date_color;
            main_LCD_dt_object.date.text_border_color = *current_MMI_theme->idle_scr_date_border_color;
            main_LCD_dt_object.time.font = &MMI_large_font;
            main_LCD_dt_object.time.text_color = *current_MMI_theme->idle_scr_time_color;
            main_LCD_dt_object.time.text_border_color = *current_MMI_theme->idle_scr_time_border_color;
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 


            wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK1,0,0,
                0,
                0,
                GUI_CLOCK_TYPE_DIGITAL_TIME);

            wgui_clock_set_date_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.font);
            wgui_clock_set_date_text_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.text_color);
            wgui_clock_set_date_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.text_border_color);
            
            wgui_clock_set_time_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.font);
            wgui_clock_set_time_text_color(WGUI_CLOCK_MAINLCD_CLOCK1,
                main_LCD_dt_object.time.text_color);
            wgui_clock_set_time_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.text_border_color);

            wgui_clock_measure_time_text(WGUI_CLOCK_MAINLCD_CLOCK1, 
                &w, &h, main_LCD_dt_object.time.font);
            
            x = (UI_device_width >> 1) - (w >> 1);
            y = (UI_device_height >> 1) - (h >> 1);
            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);

            wgui_clock_move(WGUI_CLOCK_MAINLCD_CLOCK1, x1, y1);
            
            wgui_clock_resize(WGUI_CLOCK_MAINLCD_CLOCK1, main_LCD_dt_object.time.width, main_LCD_dt_object.time.height);

            if (show_date == 0) /* if display date time is enable */
            {
                wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    0,0,0,0, 
                    GUI_CLOCK_TYPE_DIGITAL_DATE);
                
                wgui_clock_set_date_text_font(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.date.font);
                wgui_clock_set_date_text_color(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.date.text_color);
                wgui_clock_set_date_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.date.text_border_color);
                
                wgui_clock_set_time_text_font(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.time.font);
                wgui_clock_set_time_text_color(WGUI_CLOCK_MAINLCD_CLOCK2,
                    main_LCD_dt_object.time.text_color);
                wgui_clock_set_time_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.time.text_border_color);
                
                wgui_clock_measure_date_text(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    &w, &h, 
                    main_LCD_dt_object.date.font);
                
                x = (UI_device_width >> 1) - (w >> 1);
            #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
                if (is_on_idlescreen())
                {
                    y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
                }
                else
            #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            #if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                    /* change in value of y, when idlescreen shortcuts are enabled. */
                    y = UI_device_height - max_touch_idle_screen_shortcut_height() - h - 4;
            #else /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 
                    y = UI_device_height - MMI_button_bar_height - h - 4;
            #endif /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 

                x1 = main_LCD_dt_object.date.x = x;
                y1 = main_LCD_dt_object.date.y = y;
                main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
                main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);

                wgui_clock_move(WGUI_CLOCK_MAINLCD_CLOCK2, x1, y1);
                wgui_clock_resize(
                    WGUI_CLOCK_MAINLCD_CLOCK2,
                    main_LCD_dt_object.date.width,
                    main_LCD_dt_object.date.height);

            }   /* show_date == 0 */
        
            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
        case DT_DIGITAL_CLOCK_SC2:
        {
        
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                show_date = 1;
            }
            else
            {
                show_date = 0;
            }
        
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = &MMI_medium_font;
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
            main_LCD_dt_object.time.font = &MMI_medium_font;
            main_LCD_dt_object.time.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
#else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
            main_LCD_dt_object.time.font = &MMI_large_font;
            main_LCD_dt_object.time.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 


            wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK1,0,0,
                0,
                0,
                GUI_CLOCK_TYPE_DIGITAL_DATE);

            wgui_clock_set_date_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.font);
            wgui_clock_set_date_text_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.text_color);
            wgui_clock_set_date_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.text_border_color);
            
            wgui_clock_set_time_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.font);
            wgui_clock_set_time_text_color(WGUI_CLOCK_MAINLCD_CLOCK1,
                main_LCD_dt_object.time.text_color);
            wgui_clock_set_time_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.text_border_color);

            wgui_clock_measure_date_text(WGUI_CLOCK_MAINLCD_CLOCK1, 
                &w, &h, main_LCD_dt_object.date.font);

            x = (UI_device_width >> 1) - (w >> 1);
        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
            }
            else
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
                y = UI_device_height - MMI_button_bar_height - (h + (DT_DISPLAY_GAP << 1)) - 4;

            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);

            
            wgui_clock_move(WGUI_CLOCK_MAINLCD_CLOCK1, 
                x1, y1);

            wgui_clock_resize(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.width, 
                main_LCD_dt_object.date.height);

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
                break;
        case DT_DIGITAL_CLOCK_SC3:
        {

            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                show_date = 1;
            }
            else
            {
                show_date = 0;
            }

            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = &MMI_medium_font;
        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
            main_LCD_dt_object.time.font = &MMI_medium_font;
            main_LCD_dt_object.time.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
            main_LCD_dt_object.time.font = &MMI_large_font;
            main_LCD_dt_object.time.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK1,0,0,
                0,
                0,
                GUI_CLOCK_TYPE_DIGITAL_TIME);
            
            wgui_clock_set_date_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.font);
            wgui_clock_set_date_text_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.text_color);
            wgui_clock_set_date_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.date.text_border_color);
            
            wgui_clock_set_time_text_font(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.font);
            wgui_clock_set_time_text_color(WGUI_CLOCK_MAINLCD_CLOCK1,
                main_LCD_dt_object.time.text_color);
            wgui_clock_set_time_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.text_border_color);
            
            wgui_clock_measure_time_text(WGUI_CLOCK_MAINLCD_CLOCK1, 
                &w, &h, main_LCD_dt_object.time.font);

            x = (UI_device_width >> 1) - (w >> 1);
            y = (UI_device_height >> 1) - (h >> 1);
            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);

            
            wgui_clock_move(WGUI_CLOCK_MAINLCD_CLOCK1, 
                x1, y1);

            wgui_clock_resize(WGUI_CLOCK_MAINLCD_CLOCK1, 
                main_LCD_dt_object.time.width, 
                main_LCD_dt_object.time.height);

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;

    #ifdef __MMI_ANALOG_CLOCK__
        case DT_ANALOG_CLOCK_SC:
        {
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE) /* check if display of date is enable on idle screen or not */
            {
                show_date = 1;
            }
            else
            {
                show_date = 0;
            }
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = &MMI_medium_font;

        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = *current_MMI_theme->idle_scr_date_color;
            main_LCD_dt_object.date.text_border_color = *current_MMI_theme->idle_scr_date_border_color;
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK1,
                ANALOG_CLOCK_DIAL_X,
                ANALOG_CLOCK_DIAL_Y,
                ANALOG_CLOCK_DIAL_WIDTH,
                ANALOG_CLOCK_DIAL_HEIGHT,
                GUI_CLOCK_TYPE_ANALOG);

            if (show_date == 0)
            {
                wgui_clock_create(WGUI_CLOCK_MAINLCD_CLOCK2,
                    0,0,0,0,
                    GUI_CLOCK_TYPE_DIGITAL_DATE);

                wgui_clock_set_date_text_font(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.date.font);
                wgui_clock_set_date_text_color(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.date.text_color);
                wgui_clock_set_date_text_border_color(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.date.text_border_color);

                wgui_clock_measure_date_text(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    &w, &h, main_LCD_dt_object.date.font);
                                
                x = (UI_device_width >> 1) - (w >> 1);

            #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
                if (is_on_idlescreen())
                {
                    y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
                }
                else
            #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            #if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                    /* change in value of y, when idlescreen shortcuts are enabled. */
                    y = UI_device_height - max_touch_idle_screen_shortcut_height() - (h + (DT_DISPLAY_GAP << 1));
            #else /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 
                    y = UI_device_height - MMI_button_bar_height - (h + (DT_DISPLAY_GAP << 1));
            #endif /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 

                x1 = main_LCD_dt_object.date.x = x;
                y1 = main_LCD_dt_object.date.y = y;
                main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
                main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);

                wgui_clock_move(WGUI_CLOCK_MAINLCD_CLOCK2,
                    x1, y1);
                wgui_clock_resize(WGUI_CLOCK_MAINLCD_CLOCK2, 
                    main_LCD_dt_object.date.width, 
                    main_LCD_dt_object.date.height);
            }

        

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
    #endif /* __MMI_ANALOG_CLOCK__ */ 
        case DT_AUDIO_PLAY_DURATION:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.duration.x = 6;
            main_LCD_dt_object.duration.y = 30;
            main_LCD_dt_object.duration.width = 44;
            main_LCD_dt_object.duration.height = 19;
            main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;
        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.duration.font = &MMI_medium_font;
            main_LCD_dt_object.duration.text_color = *current_MMI_theme->title_text_color;
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.duration.font = &MMI_large_font;
            main_LCD_dt_object.duration.text_color = gui_color(0, 255, 0);
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
    #ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
        case DT_SUBLCD_ANALOG_CLOCK:
        {
            wgui_clock_create(WGUI_CLOCK_SUBLCD_CLOCK1,
                g_gui_clock_sub_lcd_analog_clock_dial_x,
                g_gui_clock_sub_lcd_analog_clock_dial_y,
                GUI_CLOCK_SUB_ANALOG_CLOCK_SECONDS_HAND_LENGTH,
                GUI_CLOCK_SUB_ANALOG_CLOCK_SECONDS_HAND_LENGTH,
                GUI_CLOCK_SUBLCD_ANALOG_CLOCK);
            
            MMI_sub_LCD_dt_hide_function = UI_dummy_function;
            MMI_sub_LCD_dt_display_function = RedrawSubLCDAnalogClockScreen;
            MMI_sub_LCD_dt_update_function = update_sub_LCD_date_time1;
        }
            break;
    #endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
        default:
            reset_dt_display();
    }
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  close_main_LCD_dt_display
 * DESCRIPTION
 *  set all function pointer of date tiem display ofmain lcd
 *  to dummy functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_main_LCD_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_update_function = UI_dummy_function;
    MMI_main_LCD_dt_display_function = UI_dummy_function;
    MMI_main_LCD_dt_hide_function = UI_dummy_function;
    MMI_main_LCD_dt_close_function();
    MMI_main_LCD_dt_close_function = UI_dummy_function;
    MMI_main_LCD_dt_date_hide_function = UI_dummy_hide_function;
    MMI_main_LCD_dt_time_hide_function = UI_dummy_hide_function;
    MMI_main_LCD_dt_duration_hide_function = UI_dummy_hide_function;
    gui_cancel_timer(dt_update_duration);
    gui_cancel_timer(dt_update_duration_gprs);
    gui_cancel_timer(dt_update_duration_cat19);
    wgui_clock_close_main_lcd();
    
}


/*****************************************************************************
 * FUNCTION
 *  close_sub_LCD_dt_display
 * DESCRIPTION
 *  set all function pointer of date tiem display of sub  lcd
 *  to dummy functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_sub_LCD_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_update_function = UI_dummy_function;
    MMI_sub_LCD_dt_display_function = UI_dummy_function;
    MMI_sub_LCD_dt_hide_function = UI_dummy_function;
    MMI_sub_LCD_dt_close_function();
    MMI_sub_LCD_dt_close_function = UI_dummy_function;
    MMI_sub_LCD_dt_date_hide_function = UI_dummy_hide_function;
    MMI_sub_LCD_dt_time_hide_function = UI_dummy_hide_function;
    MMI_sub_LCD_dt_duration_hide_function = UI_dummy_hide_function;

    wgui_clock_close_sub_lcd();
    
}

/* global variable store the call cost symbol */
PU8 UI_call_cost_symbol = NULL;

/* global variable store the call cost valeu */
PU8 UI_call_cost_value = NULL;

#if 0
/* under construction !*/
#endif
extern pBOOL GetShowAOC(void);
/*****************************************************************************
 * FUNCTION
 *  reset_call_cost_UI
 * DESCRIPTION
 *  reset the call cost and call symbol to null
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_call_cost_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_call_cost_symbol = NULL;
    UI_call_cost_value = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  show_call_cost_UI
 * DESCRIPTION
 *  show call cost on active calll screen
 * PARAMETERS
 *  symbol      [IN]        Currency symbol
 *  value       [IN]        Total cost
 * RETURNS
 *  void
 *****************************************************************************/
/* code added vandana mehtani AOC   */
void show_call_cost_UI(PU8 symbol, PU8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width, string_height;
    UI_character_type Buffer[30];
    S32 tx, ty, x;
    color c = *current_MMI_theme->datetime_bar_AOC_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_call_cost_symbol = symbol;
    UI_call_cost_value = value;

    PRINT_INFORMATION("show_call_cost_UI: In show_call_cost_UI");

    if ((NULL == symbol) || (NULL == value))
    {
        PRINT_INFORMATION("show_call_cost_UI: Null symbol or Null Value");
        return;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if (!GetShowAOC())
    {
        return ;
    }

    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    x = (UI_device_width >> 1) + 16;
    gui_set_font(&MMI_default_font);
    gui_strcpy(Buffer, (U16*) symbol);
    gui_strcat(Buffer, (UI_string_type) " ");
    gui_strcat(Buffer, (UI_string_type) value);
    string_width = gui_get_string_width(Buffer);
    string_height = gui_get_character_height();
    ty = main_LCD_dt_object.duration.y;
    MMI_ASSERT(main_LCD_dt_object.duration.hide_function!=NULL);//102506 call cost    
    main_LCD_dt_object.duration.hide_function(x, ty, UI_device_width - 1, ty + string_height - 1);      /* call duration hide function */
    tx = UI_device_width - string_width - 2;
    gdi_layer_reset_clip();

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(tx + string_width, ty);
    }
    else
    {
        gui_move_text_cursor(tx, ty);
    }

    gui_set_text_color(c);
    /* print callcost */
    gui_print_text(Buffer);
    gdi_layer_pop_clip();
    gdi_layer_blt_previous((UI_device_width - 1) >> 1, ty, UI_device_width - 1, ty + string_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  redraw_call_cost_UI
 * DESCRIPTION
 *  update cost value on active call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_call_cost_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_call_cost_UI(UI_call_cost_symbol, UI_call_cost_value);
}

/* code ended vandana mehtani */

/* Theme data for formatted input objects. Should be obtained from theme resource   */
/* date time input box background color scheme */
UI_filled_area date_time_input_background_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* date time input box field color scheme */
UI_filled_area date_time_input_field_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

UI_single_line_input_box_theme date_time_input_theme = { &date_time_input_field_filler,
    &date_time_input_field_filler,
    &date_time_input_field_filler,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &UI_DEFAULT_FONT,
    0,
    UI_SINGLE_LINE_INPUT_BOX_CENTER_Y,
    '*'
};


/*****************************************************************************
 * FUNCTION
 *  max_num_of_days
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y       [IN]        
 *  m       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 max_num_of_days(S32 y, S32 m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        return 31;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }
    else    /* Feb */
    {
        U8 isLeap = 0;

        if (y % 400 == 0)
        {
            isLeap = 1;
        }
        else if (y % 100 == 0)
        {
            isLeap = 0;
        }
        else if (y % 4 == 0)
        {
            isLeap = 1;
        }
        else
        {
            isLeap = 0;
        }

        return 28 + isLeap;
    }
}


/*****************************************************************************
 * FUNCTION
 *  validMonth
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y       [IN]        
 *  m       [IN]        
 *  d       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL validMonth(S32 y, S32 m, S32 d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31)
    {
        return TRUE;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d <= 30)
    {
        return TRUE;
    }
    else    /* Feb */
    {
        /* U8 isLeap = 0; */
        if ((y % 400 == 0) && d <= 29)
        {
            return TRUE;
        }
        else if (y % 100 == 0 && d <= 28)
        {
            return TRUE;
        }
        else if (y % 4 == 0 && d <= 29)
        {
            return TRUE;
        }
        else if (d <= 28)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }

    }
}

/* Default Date validation functions   */


/*****************************************************************************
 * FUNCTION
 *  default_inline_date_day_validation
 * DESCRIPTION
 *  validation function of day input of inline editing
 * PARAMETERS
 *  text            [IN]        Text
 *  cursor          [IN]        
 *  text_length     [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_date_day_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);
    S32 l = gui_strlen((UI_string_type) text);
    S32 y = gui_atoi((UI_string_type) current_date_input->year_input_box.text);
    S32 m = gui_atoi((UI_string_type) current_date_input->month_input_box.text);
    U8 d = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d = max_num_of_days(y, m);

    if ((i < 1) && (l > 1))
    {
        i = 1;
        gui_sprintf((UI_string_type) text, "%02d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
    else if (i > d)
    {
        i = d;
        gui_sprintf((UI_string_type) text, "%02d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_inline_date_boundary
 * DESCRIPTION
 *  to set date setting boundary
 * PARAMETERS
 *  date_year_max       [IN]        
 *  date_year_min       [IN]        
 *  date_month_max      [IN]        
 *  date_month_min      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_inline_date_boundary(S32 date_year_max, S32 date_year_min, S32 date_month_max, S32 date_month_min)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_date_year_max = date_year_max;
    g_date_year_min = date_year_min;
    g_date_month_max = date_month_max;
    g_date_month_min = date_month_min;
}


/*****************************************************************************
 * FUNCTION
 *  default_inline_date_month_validation
 * DESCRIPTION
 *  validation function of month input of inline editing
 * PARAMETERS
 *  text            [IN]        Text
 *  cursor          [IN]        
 *  text_length     [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_date_month_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);
    S32 l = gui_strlen((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < g_date_month_min) && (l > 1))
    {
        i = g_date_month_min;
        gui_sprintf((UI_string_type) text, "%02d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
    else if (i > g_date_month_max)
    {
        i = g_date_month_max;
        gui_sprintf((UI_string_type) text, "%02d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }

    default_inline_date_day_validation(
        current_date_input->day_input_box.text,
        current_date_input->day_input_box.current_text_p,
        (current_date_input->day_input_box.text_length >> 1) - 1);
}


/*****************************************************************************
 * FUNCTION
 *  default_inline_date_year_validation
 * DESCRIPTION
 *  validation function of year input of inline editing
 * PARAMETERS
 *  text            [IN]        Text
 *  cursor          [IN]        
 *  text_length     [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_date_year_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);
    S32 l = gui_strlen((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < g_date_year_min) && (l > 3))
    {
        i = g_date_year_min;
        gui_sprintf((UI_string_type) text, "%04d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
    else if (i > g_date_year_max)
    {
        i = g_date_year_max;
        gui_sprintf((UI_string_type) text, "%04d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }

    default_inline_date_month_validation(
        current_date_input->month_input_box.text,
        current_date_input->month_input_box.current_text_p,
        (current_date_input->month_input_box.text_length >> 1) - 1);
    default_inline_date_day_validation(
        current_date_input->day_input_box.text,
        current_date_input->day_input_box.current_text_p,
        (current_date_input->day_input_box.text_length >> 1) - 1);
}

/* Date input object */


/*****************************************************************************
 * FUNCTION
 *  date_input_show_background
 * DESCRIPTION
 *  show the background color of date input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_show_background(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();
    x1 = d->x;
    y1 = d->y;
    x2 = x1 + d->width - 1;
    y2 = y1 + d->height - 1;
    gui_draw_filled_area(x1, y1, x2, y2, &date_time_input_background_filler);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_reset_focus
 * DESCRIPTION
 *  reset focus of date input box to noram state
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_reset_focus(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->day_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->day_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->day_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->month_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->month_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->month_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->year_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->year_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->year_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->focus_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  date_input_set_focus
 * DESCRIPTION
 *  reset focus of date input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_set_focus(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((d->current_focus < 1) || (d->current_focus > 3))
    {
        return;
    }

    switch (d->focus_list[d->current_focus])
    {
        case DATE_INPUT_FOCUS_DAY:
            d->day_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->day_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->day_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->day_input_box;
            break;
        case DATE_INPUT_FOCUS_MONTH:
            d->month_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->month_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->month_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->month_input_box;
            break;
        case DATE_INPUT_FOCUS_YEAR:
            d->year_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->year_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->year_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->year_input_box;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  date_input_set_default_focus
 * DESCRIPTION
 *  set the defualt focus of date input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_set_default_focus(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d->flags & DATE_INPUT_TYPE_DEFAULT_FOCUS_MASK)
    {
        case DATE_INPUT_TYPE_DEFAULT_FOCUS_DAY:
            for (i = 0; i < 5; i++)
            {
                if (d->focus_list[i] == DATE_INPUT_FOCUS_DAY)
                {
                    d->current_focus = i;
                }
            }
            break;
        case DATE_INPUT_TYPE_DEFAULT_FOCUS_MONTH:
            for (i = 0; i < 5; i++)
            {
                if (d->focus_list[i] == DATE_INPUT_FOCUS_MONTH)
                {
                    d->current_focus = i;
                }
            }
            break;
        case DATE_INPUT_TYPE_DEFAULT_FOCUS_YEAR:
            for (i = 0; i < 5; i++)
            {
                if (d->focus_list[i] == DATE_INPUT_FOCUS_YEAR)
                {
                    d->current_focus = i;
                }
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  create_date_input
 * DESCRIPTION
 *  create date input box
 * PARAMETERS
 *  d                   [IN]        Date input box
 *  x                   [IN]        Start x position of date input box
 *  y                   [IN]        Styart y position of date input box
 *  width               [IN]        Width of date iput box
 *  height              [IN]        Height of date input box
 *  flags               [IN]        
 *  day_buffer          [IN]        Store day value
 *  month_buffer        [IN]        Store month value
 *  year_buffer         [IN]        Store year value
 * RETURNS
 *  void
 *****************************************************************************/
void create_date_input(
        date_input *d,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags,
        UI_buffer_type day_buffer,
        UI_buffer_type month_buffer,
        UI_buffer_type year_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, w2, w3, h, ox, oy, sw, tw, l, w;
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->x = x;
    d->y = y;
    d->width = width;
    d->height = height;
    d->flags = flags;
    
    w= gui_get_character_width((UI_character_type)'0');
    w1 = 2 * w + 8; /* DATE_INPUT_DAY_WIDTH; */
    w2 = 2 * w + 8; /* DATE_INPUT_MONTH_WIDTH; */
    w3 = 4 * w + 8; /*DATE_INPUT_YEAR_WIDTH; */
    sw = DATE_INPUT_SEPERATOR_WIDTH;
    tw = w1 + sw + w2 + sw + w3;

    /* START VIJAY PMT 20060111...as menuitem height is one pixel less for this LCD size */
#if defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__
    if (IsInlineItemDefaultTextEnable())
    {
        h =  gui_get_character_height() + 1;
        h = (h < DATE_INPUT_HEIGHT - 1) ? DATE_INPUT_HEIGHT - 1 : h;
    }
    else
#endif /* defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__ */ 
        /* END VIJAY PMT 20060111 */
    {
        h =  gui_get_character_height() + 1;
        h = (h < DATE_INPUT_HEIGHT) ? DATE_INPUT_HEIGHT : h;
    }

    oy = (height >> 1) - (h >> 1);
    switch (flags & DATE_INPUT_JUSTIFY_MASK)
    {
        case DATE_INPUT_RIGHT_JUSTIFY:
            ox = (width - tw);
            break;

        case DATE_INPUT_CENTER_JUSTIFY:
            ox = (width >> 1) - (tw >> 1);
            break;

        default:
            ox = 0;
            break;
    }

    /* 20051012 HIMANSHU START INLINE DATE */
    /* Inline item type Date must be left align in normal case and it must be right
       align in case of r2lMMIFlag is ON, when the default text effect is enabled */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        if (r2lMMIFlag)
        {
            ox = width - ox - tw - 1;
        }
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
    /* 20051012 HIMANSHU END INLINE DATE */

    d->focus_list[0] = DATE_INPUT_FOCUS_NONE;
    d->focus_list[4] = DATE_INPUT_FOCUS_NONE;
    switch (flags & DATE_INPUT_TYPE_MASK)
    {
        case DATE_INPUT_TYPE_DD_MM_YYYY:
            d->focus_list[1] = DATE_INPUT_FOCUS_DAY;
            d->focus_list[2] = DATE_INPUT_FOCUS_MONTH;
            d->focus_list[3] = DATE_INPUT_FOCUS_YEAR;
            d->day_x = ox;
            ox += w1 + sw;
            d->month_x = ox;
            ox += w2 + sw;
            d->year_x = ox;
            d->flags |= DATE_INPUT_TYPE_DEFAULT_FOCUS_DAY;
            break;
        case DATE_INPUT_TYPE_MM_DD_YYYY:
            d->focus_list[1] = DATE_INPUT_FOCUS_MONTH;
            d->focus_list[2] = DATE_INPUT_FOCUS_DAY;
            d->focus_list[3] = DATE_INPUT_FOCUS_YEAR;
            d->month_x = ox;
            ox += w2 + sw;
            d->day_x = ox;
            ox += w1 + sw;
            d->year_x = ox;
            d->flags |= DATE_INPUT_TYPE_DEFAULT_FOCUS_MONTH;
            break;
        case DATE_INPUT_TYPE_YYYY_MM_DD:
            d->focus_list[1] = DATE_INPUT_FOCUS_YEAR;
            d->focus_list[2] = DATE_INPUT_FOCUS_MONTH;
            d->focus_list[3] = DATE_INPUT_FOCUS_DAY;
            d->year_x = ox;
            ox += w3 + sw;
            d->month_x = ox;
            ox += w2 + sw;
            d->day_x = ox;
            d->flags |= DATE_INPUT_TYPE_DEFAULT_FOCUS_YEAR;
            break;
    }
    current_single_line_input_box_theme = &date_time_input_theme;
    d->day_y = oy;
    d->month_y = oy;
    d->year_y = oy;
    d->s1_y = oy;
    d->s2_y = oy;
#if defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__
    if (!IsInlineItemDefaultTextEnable())
    {
#endif /* defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__ */ 
        if ((h + 2) > height)
        {
            h = height - 2;
        }
    #if defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__
    }
    #endif 
    l = gui_strlen((UI_string_type) day_buffer) /* +1 */ ;
    /* craete single inputbox of day */
    gui_create_single_line_input_box_set_buffer(
        &d->day_input_box,
        x + d->day_x,
        y + d->day_y,
        w1,
        h,
        (UI_string_type) day_buffer,
        DATE_INPUT_DAY_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->day_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->day_input_box);
    l = gui_strlen((UI_string_type) month_buffer) /* +1 */ ;
    /* craete single inputbox of month  */
    gui_create_single_line_input_box_set_buffer(
        &d->month_input_box,
        x + d->month_x,
        y + d->month_y,
        w2,
        h,
        (UI_string_type) month_buffer,
        DATE_INPUT_MONTH_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->month_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->month_input_box);
    l = gui_strlen((UI_string_type) year_buffer) /* +1 */ ;
    /* craete single inputbox of year */
    gui_create_single_line_input_box_set_buffer(
        &d->year_input_box,
        x + d->year_x,
        y + d->year_y,
        w3,
        h,
        (UI_string_type) year_buffer,
        DATE_INPUT_YEAR_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    /* MTK end */
    d->year_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->year_input_box);
    date_input_reset_focus(d);
    date_input_set_default_focus(d);
    date_input_set_focus(d);
    /* set theme of input box */
    current_single_line_input_box_theme = t;

    /* Setup default validation functions  */
    d->day_input_box.validation_callback = default_inline_date_day_validation;  /* set function pointer of validation of day input */
    d->month_input_box.validation_callback = default_inline_date_month_validation;      /* set function pointer of validation of month input */
    d->year_input_box.validation_callback = default_inline_date_year_validation;        /* set function pointer of validation of year input */
}


/*****************************************************************************
 * FUNCTION
 *  show_date_input
 * DESCRIPTION
 *  shaow date input box
 * PARAMETERS
 *  d       [IN]        Date input box
 * RETURNS
 *  void
 *****************************************************************************/
void show_date_input(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw = 0;

    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_single_line_input_box_theme = &date_time_input_theme;
    gui_set_single_line_input_box_current_theme(&d->day_input_box);
    gui_set_single_line_input_box_current_theme(&d->month_input_box);
    gui_set_single_line_input_box_current_theme(&d->year_input_box);

    /* show day input box */
    gui_show_single_line_input_box(&d->day_input_box);
    /* show month input box */
    gui_show_single_line_input_box(&d->month_input_box);
    /* show day year box */
    gui_show_single_line_input_box(&d->year_input_box);
    gdi_layer_reset_clip();
    gui_set_font(d->day_input_box.text_font);
    gui_set_text_color(d->day_input_box.normal_text_color);

    if (r2lMMIFlag)
    {
        gui_set_font(d->day_input_box.text_font);
        sw = gui_get_character_width(d->seperator);
        gui_move_text_cursor(d->s1_x + sw, d->s1_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s1_x, d->s1_y + d->y);
    }

    gui_print_character(d->seperator);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(d->s2_x + sw, d->s2_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s2_x, d->s2_y + d->y);
    }

    /* print separtor */
    gui_print_character(d->seperator);
    gdi_layer_blt_previous(d->x, d->y, d->x + d->width - 1, d->y + d->height - 1);
    current_single_line_input_box_theme = t;
}


/*****************************************************************************
 * FUNCTION
 *  date_input_set_next_focus
 * DESCRIPTION
 *  set the fous to next box of date input box
 * PARAMETERS
 *  d       [IN]        Date input box
 * RETURNS
 *  byte
 *****************************************************************************/
U8 date_input_set_next_focus(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus + 1] == DATE_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        date_input_reset_focus(d);
        d->current_focus++;
        date_input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_single_line_input_box_goto_first_character(d->focus_input_box);
    #endif 
        return (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  date_input_set_previous_focus
 * DESCRIPTION
 *  set the focus to previous box oof date input box
 * PARAMETERS
 *  d       [IN]        Date input box
 * RETURNS
 *  byte
 *****************************************************************************/
U8 date_input_set_previous_focus(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus - 1] == DATE_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        date_input_reset_focus(d);
        d->current_focus--;
        date_input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_single_line_input_box_goto_last_character(d->focus_input_box);
        gui_single_line_input_box_previous(d->focus_input_box);
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
        return (1);
    }
}

#if defined (__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  date_input_move_to_x_y
 * DESCRIPTION
 *  set the cursor position to (x,y) position
 * PARAMETERS
 *  d       [IN]        Date input box S32 x S32 y
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_move_to_x_y(date_input *d, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, d->x, d->y, d->width, d->height))
    {
        if (PEN_CHECK_BOUND
            (x, y, d->day_input_box.x, d->day_input_box.y, d->day_input_box.width, d->day_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(d->focus_input_box);
            date_input_reset_focus(d);
            for (;; i++)
            {
                if (d->focus_list[i] == DATE_INPUT_FOCUS_DAY)
                {
                    d->current_focus = i;
                    break;
                }
            }
            date_input_set_focus(d);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, d->month_input_box.x, d->month_input_box.y, d->month_input_box.width,
                  d->month_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(d->focus_input_box);
            date_input_reset_focus(d);
            for (;; i++)
            {
                if (d->focus_list[i] == DATE_INPUT_FOCUS_MONTH)
                {
                    d->current_focus = i;
                    break;
                }
            }
            date_input_set_focus(d);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, d->year_input_box.x, d->year_input_box.y, d->year_input_box.width, d->year_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(d->focus_input_box);
            date_input_reset_focus(d);
            for (;; i++)
            {
                if (d->focus_list[i] == DATE_INPUT_FOCUS_YEAR)
                {
                    d->current_focus = i;
                    break;
                }
            }
            date_input_set_focus(d);
        }
        else
        {
            return;
        }
        gui_show_single_line_input_box_ext(d->focus_input_box, x, y);
        if (gui_single_line_input_box_test_last_character_position(d->focus_input_box))
        {
            gui_single_line_input_box_goto_last_character(d->focus_input_box);
            gui_single_line_input_box_previous(d->focus_input_box);
        }
        show_date_input(d);
    }
}
#endif /* defined (__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  date_input_set_seperator
 * DESCRIPTION
 *  set the mask of date input box
 * PARAMETERS
 *  d               [IN]        Date input box
 *  seperator       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_set_seperator(date_input *d, UI_character_type seperator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, x1, x2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->seperator = seperator;
    gui_set_font(d->day_input_box.text_font);
    sw = gui_get_character_width(d->seperator);
    switch (d->flags & DATE_INPUT_TYPE_MASK)
    {
        case DATE_INPUT_TYPE_DD_MM_YYYY:
            x1 = d->day_input_box.x + d->day_input_box.width - 1;
            x2 = d->month_input_box.x;
            d->s1_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            x1 = d->month_input_box.x + d->month_input_box.width - 1;
            x2 = d->year_input_box.x;
            d->s2_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            break;

        case DATE_INPUT_TYPE_MM_DD_YYYY:
            x1 = d->month_input_box.x + d->month_input_box.width - 1;
            x2 = d->day_input_box.x;
            d->s1_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            x1 = d->day_input_box.x + d->day_input_box.width - 1;
            x2 = d->year_input_box.x;
            d->s2_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            break;

        case DATE_INPUT_TYPE_YYYY_MM_DD:
            x1 = d->year_input_box.x + d->year_input_box.width - 1;
            x2 = d->month_input_box.x;
            d->s1_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            x1 = d->month_input_box.x + d->month_input_box.width - 1;
            x2 = d->day_input_box.x;
            d->s2_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            break;
    }
}

/* store the value of current date input */

date_input *current_date_input = NULL;

/*----------------------------------------------------------------------------
Function:         current_date_input_callback
Description:      a function pointer of current date input callback
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*current_date_input_callback) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  set_current_date_input
 * DESCRIPTION
 *  set current date input to global variable
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_date_input(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_date_input = d;
}


/*****************************************************************************
 * FUNCTION
 *  date_input_direct_input
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL)
    {
        return;
    }
    if (current_date_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position_overflow(current_date_input->focus_input_box))
    {
        if (date_input_set_next_focus(current_date_input))
        {
            gui_single_line_input_box_insert_character(current_date_input->focus_input_box, c);
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(current_date_input->focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(current_date_input->focus_input_box))
        {
            if (!date_input_set_next_focus(current_date_input))
            {
                gui_single_line_input_box_previous(current_date_input->focus_input_box);
            }
        }
    }
    /* show date input box */
    show_date_input(current_date_input);
    /* call daet input validation function */
    current_date_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  date_input_direct_input_nodraw
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_direct_input_nodraw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL)
    {
        return;
    }

    if (current_date_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position_overflow(current_date_input->focus_input_box))
    {
        if (date_input_set_next_focus(current_date_input))
        {
            gui_single_line_input_box_insert_character(current_date_input->focus_input_box, c);
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(current_date_input->focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(current_date_input->focus_input_box))
        {
            if (!date_input_set_next_focus(current_date_input))
            {
                gui_single_line_input_box_previous(current_date_input->focus_input_box);
            }
        }
    }
    current_date_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  date_input_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 date_input_test_last_position(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus + 1] != DATE_INPUT_FOCUS_NONE)
    {
        return 0;
    }
    else
    {
        if (gui_single_line_input_box_test_last_character_position(d->focus_input_box))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  date_input_delete_character
 * DESCRIPTION
 *  delete current character of date input box
 * PARAMETERS
 *  void
 *  nonoe(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL)
    {
        return;
    }

    if (current_date_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(current_date_input->focus_input_box))
    {
        date_input_set_previous_focus(current_date_input);
    }
    else
    {
        gui_single_line_input_box_delete_character(current_date_input->focus_input_box);
        if (gui_single_line_input_box_test_first_position(current_date_input->focus_input_box))
        {
            date_input_set_previous_focus(current_date_input);
        }
    }
    /* show date input box */
    show_date_input(current_date_input);
    current_date_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  date_input_previous_character
 * DESCRIPTION
 *  set the focus to previous caharacter  of daet input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL)
    {
        return;
    }

    if (current_date_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(current_date_input->focus_input_box))
    {
        if (date_input_set_previous_focus(current_date_input))
        {
            gui_single_line_input_box_goto_last_character(current_date_input->focus_input_box);
            gui_single_line_input_box_previous(current_date_input->focus_input_box);
        }
    }
    else
    {
        gui_single_line_input_box_previous(current_date_input->focus_input_box);
    }
    /* show date input box */
    show_date_input(current_date_input);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_next_character
 * DESCRIPTION
 *  set the focus to next caharacter  of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL)
    {
        return;
    }

    if (current_date_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_character_position(current_date_input->focus_input_box))
    {
        date_input_set_next_focus(current_date_input);
    }
    else
    {
        gui_single_line_input_box_next(current_date_input->focus_input_box);
    }
    /* show date input box */
    show_date_input(current_date_input);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_toggle_insert_mode
 * DESCRIPTION
 *  toggle the insert mode of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL)
    {
        return;
    }

    if (current_date_input->focus_input_box == NULL)
    {
        return;
    }

    gui_single_line_input_box_toggle_insert_mode(current_date_input->focus_input_box);
    /* show date input box */
    show_date_input(current_date_input);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_delete_current_character
 * DESCRIPTION
 *  delete the current character of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL)
    {
        return;
    }

    if (current_date_input->focus_input_box == NULL)
    {
        return;
    }

    gui_single_line_input_box_delete_current_character(current_date_input->focus_input_box);
    /* show date input box */
    show_date_input(current_date_input);
    current_date_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  date_input_delete_all_characters
 * DESCRIPTION
 *  delete all characters of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL)
    {
        return;
    }

    if (current_date_input->focus_input_box == NULL)
    {
        return;
    }

    /* delete all characters */
    gui_single_line_input_box_delete_all(current_date_input->focus_input_box);
    /* show date input box */
    show_date_input(current_date_input);
    current_date_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  date_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  handle numeric key input of date input box
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        date_input_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        date_input_delete_character();
    }
    else if (keyc == 0x1b)
    {
        date_input_delete_all_characters();
    }
    else if (keyc == 0x0d);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_handle_key_down
 * DESCRIPTION
 *  handle date input key down
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    date_input_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  date_input_key_handler
 * DESCRIPTION
 *  register the key handler of date input box
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                date_input_previous_character();
                break;
            case 38:    /* up */
                break;
            case 39:
                date_input_next_character();
                break;
            case 40:    /* down */
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                date_input_toggle_insert_mode();
                break;
            case 46:
                date_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  date_input_register_keys
 * DESCRIPTION
 *  register date input box key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_down_handler(date_input_handle_key_down);
    register_keyboard_input_handler(date_input_numeric_keyboard_input_handler);
    SetKeyHandler(date_input_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(date_input_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    register_keyboard_key_handler(date_input_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_clear_keys
 * DESCRIPTION
 *  clear all key handlers of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_clear_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();
    clear_key_down_handler();
    clear_keyboard_input_handler();
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    clear_keyboard_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  register_date_input_callback
 * DESCRIPTION
 *  register date input call back function
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void register_date_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_date_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_date_input_callback
 * DESCRIPTION
 *  clear date input callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_date_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_date_input_callback = UI_dummy_function;
}

/* Default Time validation functions   */


/*****************************************************************************
 * FUNCTION
 *  default_inline_time_minutes_validation
 * DESCRIPTION
 *  deafult function of time mnutes validation
 * PARAMETERS
 *  text            [IN]        
 *  cursor          [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_time_minutes_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i < 0)
    {
        i = 0;
        gui_sprintf((UI_string_type) text, "%02d", i);
        UI_editor_play_tone_invalid_data();
    }
    else if (i > 59)
    {
        i = 59;
        gui_sprintf((UI_string_type) text, "%02d", i);
        UI_editor_play_tone_invalid_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  default_inline_time_hours_validation
 * DESCRIPTION
 *  deafult function of time hours validation
 * PARAMETERS
 *  text            [IN]        
 *  cursor          [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_time_hours_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i < 0)
    {
        i = 0;
        gui_sprintf((UI_string_type) text, "%02d", i);
        UI_editor_play_tone_invalid_data();
    }
    else if (i > 23)
    {
        i = 23;
        gui_sprintf((UI_string_type) text, "%02d", i);
        UI_editor_play_tone_invalid_data();
    }
}

/* Time input object */


/*****************************************************************************
 * FUNCTION
 *  time_input_show_background
 * DESCRIPTION
 *  show time input bkg color
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_show_background(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();
    x1 = d->x;
    y1 = d->y;
    x2 = x1 + d->width - 1;
    y2 = y1 + d->height - 1;
    gui_draw_filled_area(x1, y1, x2, y2, &date_time_input_background_filler);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_reset_focus
 * DESCRIPTION
 *  reset teh foucs of time input
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_reset_focus(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->hours_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->hours_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->hours_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->minutes_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->minutes_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->minutes_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->seconds_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->seconds_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->seconds_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->focus_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_focus
 * DESCRIPTION
 *  set the focus of time input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_set_focus(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((d->current_focus < 1) || (d->current_focus > 3))
    {
        return;
    }

    switch (d->focus_list[d->current_focus])
    {
        case TIME_INPUT_FOCUS_HOURS:
            d->hours_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->hours_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->hours_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->hours_input_box;
            break;

        case TIME_INPUT_FOCUS_MINUTES:
            d->minutes_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->minutes_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->minutes_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->minutes_input_box;
            break;

        case TIME_INPUT_FOCUS_SECONDS:
            d->seconds_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->seconds_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->seconds_input_box.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->seconds_input_box;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_default_focus
 * DESCRIPTION
 *  set the default  focus of time input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_set_default_focus(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d->flags & TIME_INPUT_TYPE_DEFAULT_FOCUS_MASK)
    {
        case TIME_INPUT_TYPE_DEFAULT_FOCUS_HOURS:
            for (i = 0; i < 5; i++)
            {
                if (d->focus_list[i] == TIME_INPUT_FOCUS_HOURS)
                {
                    d->current_focus = i;
                }
            }
            break;

        case TIME_INPUT_TYPE_DEFAULT_FOCUS_MINUTES:
            for (i = 0; i < 5; i++)
            {
                if (d->focus_list[i] == TIME_INPUT_FOCUS_MINUTES)
                {
                    d->current_focus = i;
                }
            }
            break;

        case TIME_INPUT_TYPE_DEFAULT_FOCUS_SECONDS:
            for (i = 0; i < 5; i++)
            {
                if (d->focus_list[i] == TIME_INPUT_FOCUS_SECONDS)
                {
                    d->current_focus = i;
                }
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  create_time_input
 * DESCRIPTION
 *  create time input box
 * PARAMETERS
 *  d                   [IN]        Time input box
 *  x                   [IN]        Start x position of time input box
 *  y                   [IN]        Strat y position of time input box
 *  width               [IN]        Width of time input box
 *  height              [IN]        Height of time input box
 *  flags               [IN]        
 *  hours_buffer        [IN]        Hours buffer
 *  minutes_buffer      [IN]        Minutes buffer
 *  seconds_buffer      [IN]        Seconds buffer
 * RETURNS
 *  void
 *****************************************************************************/
void create_time_input(
        time_input *d,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags,
        UI_buffer_type hours_buffer,
        UI_buffer_type minutes_buffer,
        UI_buffer_type seconds_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, w2, w3, h, ox, oy, sw, tw, l, w;
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->x = x;
    d->y = y;
    d->width = width;
    d->height = height;
    d->flags = flags;
    w= gui_get_character_width((UI_character_type)'0');
   /* 
    w1 = TIME_INPUT_HOURS_WIDTH;
    w2 = TIME_INPUT_MINUTES_WIDTH;
    w3 = TIME_INPUT_SECONDS_WIDTH;
   */
    w1 = 2 * w + 8;
    w2 = 2 * w + 8;
    w3 = 2 * w + 8;
    sw = TIME_INPUT_SEPERATOR_WIDTH;

    if ((flags & TIME_INPUT_TYPE_MASK) == TIME_INPUT_TYPE_HH_MM)
    {
        tw = w1 + sw + w2;
    }
    else
    {
        tw = w1 + sw + w2 + sw + w3;
    }
    h =  gui_get_character_height() + 1;
    h = h < TIME_INPUT_HEIGHT ? TIME_INPUT_HEIGHT : h;
    oy = (height >> 1) - (h >> 1);
    switch (flags & TIME_INPUT_JUSTIFY_MASK)
    {
        case TIME_INPUT_RIGHT_JUSTIFY:
            ox = (width - tw);
            break;

        case TIME_INPUT_CENTER_JUSTIFY:
            ox = (width >> 1) - (tw >> 1);
            break;

        default:
            ox = 0;
            break;
    }

    /* 20051012 HIMANSHU START INLINE TIME */
    /* Inline item type Time must be left align in normal case and it must be right
       align in case of r2lMMIFlag is ON, when the default text effect is enabled */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        if (r2lMMIFlag)
        {
            ox = width - ox - tw - 1;
        }
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
    /* 20051012 HIMANSHU END INLINE TIME */

    d->focus_list[0] = TIME_INPUT_FOCUS_NONE;
    d->focus_list[4] = TIME_INPUT_FOCUS_NONE;
    switch (flags & TIME_INPUT_TYPE_MASK)
    {
        case TIME_INPUT_TYPE_HH_MM:
            d->focus_list[1] = TIME_INPUT_FOCUS_HOURS;
            d->focus_list[2] = TIME_INPUT_FOCUS_MINUTES;
            d->focus_list[3] = TIME_INPUT_FOCUS_NONE;
            d->hours_x = ox;
            ox += w1 + sw;
            d->minutes_x = ox;
            d->flags |= TIME_INPUT_TYPE_DEFAULT_FOCUS_HOURS;
            d->seconds_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
            break;

        case TIME_INPUT_TYPE_HH_MM_SS:
            d->focus_list[1] = TIME_INPUT_FOCUS_HOURS;
            d->focus_list[2] = TIME_INPUT_FOCUS_MINUTES;
            d->focus_list[3] = TIME_INPUT_FOCUS_SECONDS;
            d->hours_x = ox;
            ox += w1 + sw;
            d->minutes_x = ox;
            ox += w2 + sw;
            d->seconds_x = ox;
            d->flags |= TIME_INPUT_TYPE_DEFAULT_FOCUS_HOURS;
            break;
    }
    current_single_line_input_box_theme = &date_time_input_theme;
    d->hours_y = oy;
    d->minutes_y = oy;
    d->seconds_y = oy;
    d->s1_y = oy;
    d->s2_y = oy;
    if ((h + 2) > height)
    {
        h = height - 2;
    }

    /* MTK Terry for Bidi Issue */
    l = gui_strlen((UI_string_type) hours_buffer);
    /* create single input box of hours */
    /* MTK Elvis for R2L characters */
    gui_create_single_line_input_box_set_buffer(
        &d->hours_input_box,
        x + d->hours_x,
        y + d->hours_y,
        w1,
        h,
        (UI_string_type) hours_buffer,
        TIME_INPUT_HOURS_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->hours_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->hours_input_box);

    l = gui_strlen((UI_string_type) minutes_buffer);
    /* create single input box of minutes */
    /* MTK Elvis for R2L characters */
    gui_create_single_line_input_box_set_buffer(
        &d->minutes_input_box,
        x + d->minutes_x,
        y + d->minutes_y,
        w2,
        h,
        (UI_string_type) minutes_buffer,
        TIME_INPUT_MINUTES_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->minutes_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->minutes_input_box);

    l = gui_strlen((UI_string_type) seconds_buffer);
    /* create single input box of seconds */
    /* MTK Elvis for R2L characters */
    gui_create_single_line_input_box_set_buffer(
        &d->seconds_input_box,
        x + d->seconds_x,
        y + d->seconds_y,
        w3,
        h,
        (UI_string_type) seconds_buffer,
        TIME_INPUT_SECONDS_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->seconds_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->seconds_input_box);
    time_input_reset_focus(d);
    time_input_set_default_focus(d);
    time_input_set_focus(d);
    /* set theme of input box */
    current_single_line_input_box_theme = t;

    /* Setup default validation functions  */
    d->hours_input_box.validation_callback = default_inline_time_hours_validation;
    d->minutes_input_box.validation_callback = default_inline_time_minutes_validation;
    d->seconds_input_box.validation_callback = default_inline_time_minutes_validation;
}


/*****************************************************************************
 * FUNCTION
 *  show_time_input
 * DESCRIPTION
 *  shoe time input box
 * PARAMETERS
 *  d       [IN]        Time input box
 * RETURNS
 *  void
 *****************************************************************************/
void show_time_input(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;
    S32 sw = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_single_line_input_box_theme = &date_time_input_theme;
    gui_set_single_line_input_box_current_theme(&d->hours_input_box);
    gui_set_single_line_input_box_current_theme(&d->minutes_input_box);

    /* show hours inout box */
    gui_show_single_line_input_box(&d->hours_input_box);
    /* show minutes input box */
    gui_show_single_line_input_box(&d->minutes_input_box);
    if ((d->flags & TIME_INPUT_TYPE_MASK) != TIME_INPUT_TYPE_HH_MM)
    {
        gui_show_single_line_input_box(&d->seconds_input_box);  /* show seconds input box */
    }
    gdi_layer_reset_clip();
    gui_set_font(d->hours_input_box.text_font);
    gui_set_text_color(d->hours_input_box.normal_text_color);

    if (r2lMMIFlag)
    {
        gui_set_font(d->hours_input_box.text_font);
        sw = gui_get_character_width(d->seperator);
        gui_move_text_cursor(d->s1_x + sw, d->s1_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s1_x, d->s1_y + d->y);
    }

    gui_print_character(d->seperator);
    if ((d->flags & TIME_INPUT_TYPE_MASK) != TIME_INPUT_TYPE_HH_MM)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(d->s2_x + sw, d->s2_y + d->y);
        }
        else
        {
            gui_move_text_cursor(d->s2_x, d->s2_y + d->y);
        }
        gui_print_character(d->seperator);
    }
    gdi_layer_blt_previous(d->x, d->y, d->x + d->width - 1, d->y + d->height - 1);
    current_single_line_input_box_theme = t;
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_next_focus
 * DESCRIPTION
 *  set the focus of time input box to next box
 * PARAMETERS
 *  d       [IN]        Time input box
 * RETURNS
 *  byte
 *****************************************************************************/
U8 time_input_set_next_focus(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus + 1] == TIME_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        time_input_reset_focus(d);
        d->current_focus++;
        time_input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_single_line_input_box_goto_first_character(d->focus_input_box);
    #endif 
        return (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_previous_focus
 * DESCRIPTION
 *  set the focus of time input box to previous box
 * PARAMETERS
 *  d       [IN]        Time input box
 * RETURNS
 *  byte
 *****************************************************************************/
U8 time_input_set_previous_focus(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus - 1] == TIME_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        time_input_reset_focus(d);
        d->current_focus--;
        time_input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_single_line_input_box_goto_last_character(d->focus_input_box);
        gui_single_line_input_box_previous(d->focus_input_box);
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
        return (1);
    }
}

#if defined (__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  time_input_move_to_x_y
 * DESCRIPTION
 *  set the cursor position to (x,y) position
 * PARAMETERS
 *  t           [?]         
 *  x           [IN]        
 *  y           [IN]        
 *  tp(?)       [IN]        Time input box S32 x S32 y
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_move_to_x_y(time_input *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, t->x, t->y, t->width, t->height))
    {
        if (PEN_CHECK_BOUND
            (x, y, t->hours_input_box.x, t->hours_input_box.y, t->hours_input_box.width, t->hours_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(t->focus_input_box);
            time_input_reset_focus(t);
            for (;; i++)
            {
                if (t->focus_list[i] == TIME_INPUT_FOCUS_HOURS)
                {
                    t->current_focus = i;
                    break;
                }
            }
            time_input_set_focus(t);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, t->minutes_input_box.x, t->minutes_input_box.y, t->minutes_input_box.width,
                  t->minutes_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(t->focus_input_box);
            time_input_reset_focus(t);
            for (;; i++)
            {
                if (t->focus_list[i] == TIME_INPUT_FOCUS_MINUTES)
                {
                    t->current_focus = i;
                    break;
                }
            }
            time_input_set_focus(t);
        }
        else if (((t->flags & TIME_INPUT_TYPE_MASK) == TIME_INPUT_TYPE_HH_MM_SS) &&PEN_CHECK_BOUND
                 (x, y, t->seconds_input_box.x, t->seconds_input_box.y, t->seconds_input_box.width,
                  t->seconds_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(t->focus_input_box);
            time_input_reset_focus(t);
            for (;; i++)
            {
                if (t->focus_list[i] == TIME_INPUT_FOCUS_SECONDS)
                {
                    t->current_focus = i;
                    break;
                }
            }
            time_input_set_focus(t);
        }
        else
        {
            return;
        }
        gui_show_single_line_input_box_ext(t->focus_input_box, x, y);
        if (gui_single_line_input_box_test_last_character_position(t->focus_input_box))
        {
            gui_single_line_input_box_goto_last_character(t->focus_input_box);
            gui_single_line_input_box_previous(t->focus_input_box);
        }
        show_time_input(t);
    }
}
#endif /* defined (__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  time_input_set_seperator
 * DESCRIPTION
 *  set the mask of time input box
 * PARAMETERS
 *  d               [IN]        
 *  seperator       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_set_seperator(time_input *d, UI_character_type seperator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, x1, x2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->seperator = seperator;
    gui_set_font(d->hours_input_box.text_font);
    sw = gui_get_character_width(d->seperator);
    switch (d->flags & TIME_INPUT_TYPE_MASK)
    {
        case TIME_INPUT_TYPE_HH_MM:
            x1 = d->hours_input_box.x + d->hours_input_box.width - 1;
            x2 = d->minutes_input_box.x;
            d->s1_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            x1 = d->minutes_input_box.x + d->minutes_input_box.width - 1;
            x2 = d->seconds_input_box.x;
            d->s2_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            break;
        case TIME_INPUT_TYPE_HH_MM_SS:
            x1 = d->hours_input_box.x + d->hours_input_box.width - 1;
            x2 = d->minutes_input_box.x;
            d->s1_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            x1 = d->minutes_input_box.x + d->minutes_input_box.width - 1;
            x2 = d->seconds_input_box.x;
            d->s2_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
            break;
    }
}

/* global variable store current time input */
time_input *current_time_input = NULL;

/*----------------------------------------------------------------------------
Function:         current_time_input_callback
Description:      a function pointer of current time input callback 
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*current_time_input_callback) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  set_current_time_input
 * DESCRIPTION
 *  set the valeu of global variable store current
 *  time input equal to valeu pass as parameter
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_time_input(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_input = d;
}


/*****************************************************************************
 * FUNCTION
 *  time_input_direct_input
 * DESCRIPTION
 *  enter the current character in time input box and show the time input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL)
    {
        return;
    }

    if (current_time_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position_overflow(current_time_input->focus_input_box))
    {
        if (time_input_set_next_focus(current_time_input))
        {
            gui_single_line_input_box_insert_character(current_time_input->focus_input_box, c);
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(current_time_input->focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(current_time_input->focus_input_box))
        {
            if (!time_input_set_next_focus(current_time_input))
            {
                gui_single_line_input_box_previous(current_time_input->focus_input_box);
            }
        }
    }
    /* show time input box */
    show_time_input(current_time_input);
    current_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_input_direct_input_nodraw
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_direct_input_nodraw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL)
    {
        return;
    }

    if (current_time_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position_overflow(current_time_input->focus_input_box))
    {
        if (time_input_set_next_focus(current_time_input))
        {
            gui_single_line_input_box_insert_character(current_time_input->focus_input_box, c);
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(current_time_input->focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(current_time_input->focus_input_box))
        {
            if (!time_input_set_next_focus(current_time_input))
            {
                gui_single_line_input_box_previous(current_time_input->focus_input_box);
            }
        }
    }
    current_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_input_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 time_input_test_last_position(time_input *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (t->focus_list[t->current_focus + 1] != TIME_INPUT_FOCUS_NONE)
    {
        return 0;
    }
    else
    {
        if (gui_single_line_input_box_test_last_character_position(t->focus_input_box))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_input_delete_character
 * DESCRIPTION
 *  delete character of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL)
    {
        return;
    }

    if (current_time_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(current_time_input->focus_input_box))
    {
        time_input_set_previous_focus(current_time_input);
    }
    else
    {
        gui_single_line_input_box_delete_character(current_time_input->focus_input_box);
        if (gui_single_line_input_box_test_first_position(current_time_input->focus_input_box))
        {
            time_input_set_previous_focus(current_time_input);
        }
    }
    /* show time input box */
    show_time_input(current_time_input);
    /* current time input callback fuc */
    current_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_input_previous_character
 * DESCRIPTION
 *  delete previous cahracter of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL)
    {
        return;
    }

    if (current_time_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(current_time_input->focus_input_box))
    {
        if (time_input_set_previous_focus(current_time_input))
        {
            gui_single_line_input_box_goto_last_character(current_time_input->focus_input_box);
            gui_single_line_input_box_previous(current_time_input->focus_input_box);
        }
    }
    else
    {
        gui_single_line_input_box_previous(current_time_input->focus_input_box);
    }
    /* show time input box */
    show_time_input(current_time_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_next_character
 * DESCRIPTION
 *  delete next  cahracter of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL)
    {
        return;
    }

    if (current_time_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_character_position(current_time_input->focus_input_box))
    {
        time_input_set_next_focus(current_time_input);
    }
    else
    {
        gui_single_line_input_box_next(current_time_input->focus_input_box);
    }
    /* show time input box */
    show_time_input(current_time_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_toggle_insert_mode
 * DESCRIPTION
 *  toggle insert mode of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL)
    {
        return;
    }

    if (current_time_input->focus_input_box == NULL)
    {
        return;
    }

    gui_single_line_input_box_toggle_insert_mode(current_time_input->focus_input_box);
    /* show time input box */
    show_time_input(current_time_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_delete_current_character
 * DESCRIPTION
 *  delete current character of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL)
    {
        return;
    }

    if (current_time_input->focus_input_box == NULL)
    {
        return;
    }
    gui_single_line_input_box_delete_current_character(current_time_input->focus_input_box);
    /* show time input box */
    show_time_input(current_time_input);
    current_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_input_delete_all_characters
 * DESCRIPTION
 *  delete all characters of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL)
    {
        return;
    }

    if (current_time_input->focus_input_box == NULL)
    {
        return;
    }

    gui_single_line_input_box_delete_all(current_time_input->focus_input_box);
    /* show time input box */
    show_time_input(current_time_input);
    current_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  numeric key handle of time input box
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        time_input_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        time_input_delete_character();
    }
    else if (keyc == 0x1b)
    {
        time_input_delete_all_characters();
    }
    else if (keyc == 0x0d);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_handle_key_down
 * DESCRIPTION
 *  handle key down of time input box
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_input_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  time_input_key_handler
 * DESCRIPTION
 *  register key handlers of time input box
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                time_input_previous_character();
                break;
            case 38:    /* up */
                break;
            case 39:
                time_input_next_character();
                break;
            case 40:    /* down */
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                time_input_toggle_insert_mode();
                break;
            case 46:
                time_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  time_input_register_keys
 * DESCRIPTION
 *  register key handlers of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_down_handler(time_input_handle_key_down);
    register_keyboard_input_handler(time_input_numeric_keyboard_input_handler);
    SetKeyHandler(time_input_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(time_input_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    register_keyboard_key_handler(time_input_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_clear_keys
 * DESCRIPTION
 *  clear key handlers of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_clear_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();
    clear_key_down_handler();
    clear_keyboard_input_handler();
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    clear_keyboard_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  register_time_input_callback
 * DESCRIPTION
 *  register time input call back function
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void register_time_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_time_input_callback
 * DESCRIPTION
 *  clear  time input call back function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_time_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_input_callback = UI_dummy_function;
}

UI_filled_area DOW_normal_cell_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* theme when DOW is highlighted */
UI_filled_area DOW_normal_highlighted_cell_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {9, 235, 253, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* theme when DOW is selected */
UI_filled_area DOW_selected_highlighted_cell_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {9, 235, 253, 100},
    {0, 0, 0, 0},
    {235, 247, 17, 100},
    {0, 0, 0, 0},
    0
};

UI_filled_area DOW_selected_cell_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 240, 0, 100},
    {0, 0, 0, 0},
    {235, 247, 17, 100},
    {0, 0, 0, 0},
    0
};

UI_filled_area list_menu_DOW_normal_BG_filler = {UI_FILLED_AREA_TYPE_NO_BACKGROUND,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

UI_filled_area list_menu_DOW_selected_cell_filler = {UI_FILLED_AREA_TYPE_NO_BACKGROUND | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {255, 0, 0, 100},
    {0, 0, 0, 0},
    0
};


/*****************************************************************************
 * FUNCTION
 *  create_DOW_select
 * DESCRIPTION
 *  create DOW selct input box
 * PARAMETERS
 *  d           [IN]        DOW input box
 *  x           [IN]        Start x position of DOW
 *  y           [IN]        Start y position of DOW
 *  width       [IN]        Width of DOW box
 *  height      [IN]        Height of DOW box
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 get_menu_item_height(void);
void create_DOW_select(DOW_select *d, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    color c1 = {235, 247, 17, 100};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DOW_normal_cell_filler = *MMI_fixed_icontext_menuitem.focussed_filler;
    DOW_normal_cell_filler.flags &= 0X00000FFF;
    DOW_selected_cell_filler = *MMI_fixed_icontext_menuitem.focussed_filler;
    DOW_selected_cell_filler.flags &= 0X00000FFF;
    DOW_selected_cell_filler.flags |= UI_FILLED_AREA_SINGLE_BORDER;
    DOW_selected_cell_filler.border_color = c1;

    d->background_filler = &DOW_normal_cell_filler;
    d->normal_cell_filler = &DOW_normal_cell_filler;
    d->normal_highlighted_cell_filler = &DOW_normal_highlighted_cell_filler;
    d->selected_highlighted_cell_filler = &DOW_selected_highlighted_cell_filler;
    d->selected_cell_filler = &DOW_selected_cell_filler;
    d->normal_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->normal_highlighted_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->selected_highlighted_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->selected_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->cell_width = DOW_CELL_WIDTH;
    d->cell_height = MMI_MENUITEM_HEIGHT;
    d->x = x;
    d->y = y;
    d->width = width;
    d->height = height;
    d->cell_gap = DOW_CELL_GAP;
    d->offset_x = (width >> 1) - ((7 * (d->cell_width + d->cell_gap)) >> 1);
    d->offset_y = (height >> 1) - (d->cell_height >> 1);
    d->highlighted_cell = 0;
    d->text_font = &MMI_medium_font;
    d->flags = 0;
    for (i = 0; i < 7; i++)
    {
        d->states[i] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_DOW_select_list_menu_theme
 * DESCRIPTION
 *  set color theme of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void set_DOW_select_list_menu_theme(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c1 = {255, 0, 0, 100};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_menu_DOW_selected_cell_filler = *MMI_fixed_list_menu.normal_filler;
    list_menu_DOW_selected_cell_filler.flags = (UI_FILLED_AREA_TYPE_NO_BACKGROUND | UI_FILLED_AREA_SINGLE_BORDER);
    list_menu_DOW_selected_cell_filler.border_color = c1;
    list_menu_DOW_normal_BG_filler = *MMI_fixed_list_menu.normal_filler;
    list_menu_DOW_normal_BG_filler.flags = UI_FILLED_AREA_TYPE_NO_BACKGROUND;

    d->background_filler = &list_menu_DOW_normal_BG_filler;
    d->normal_cell_filler = &list_menu_DOW_normal_BG_filler;
    d->normal_highlighted_cell_filler = &list_menu_DOW_normal_BG_filler;
    d->selected_highlighted_cell_filler = &list_menu_DOW_selected_cell_filler;
    d->selected_cell_filler = &list_menu_DOW_selected_cell_filler;
    d->normal_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->normal_highlighted_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->selected_highlighted_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->selected_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
}


/*****************************************************************************
 * FUNCTION
 *  set_DOW_select_states
 * DESCRIPTION
 *  set staes of days in DOW input box
 * PARAMETERS
 *  d           [IN]        DOW input box
 *  states      [IN]        []  :- store teh states valeu
 * RETURNS
 *  void
 *****************************************************************************/
void set_DOW_select_states(DOW_select *d, U8 states[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 7; i++)
    {
        d->states[i] = states[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  show_DOW_select_background
 * DESCRIPTION
 *  show DOW bkg
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void show_DOW_select_background(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = d->x;
    y1 = d->y;
    x2 = x1 + d->width - 1;
    y2 = y1 + d->height - 1;
    gdi_layer_reset_clip();
    gui_draw_filled_area(x1, y1, x2, y2, d->background_filler);
}


/*****************************************************************************
 * FUNCTION
 *  show_DOW_select
 * DESCRIPTION
 *  show DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void show_DOW_select(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 DOW_list[] = { 'S', 'M', 'T', 'W', 'T', 'F', 'S' };
    S32 i, x, y, character_width, character_height;
    color text_color;
    UI_filled_area *f;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    x = d->x + d->offset_x;
    y = d->y + d->offset_y;
    gui_set_font(d->text_font);
    character_height = gui_get_character_height();
    for (i = 0; i < 7; i++)
    {
        if (i == d->highlighted_cell)
        {
            if (d->states[i])
            {
                f = d->selected_highlighted_cell_filler;
                text_color = d->selected_highlighted_text_color;
            }
            else
            {
                f = d->normal_highlighted_cell_filler;
                text_color = d->normal_highlighted_text_color;
            }
        }
        else
        {
            if (d->states[i])
            {
                f = d->selected_cell_filler;
                text_color = d->selected_text_color;
            }
            else
            {
                f = d->normal_cell_filler;
                text_color = d->normal_text_color;
            }
        }
        x1 = x;
        y1 = y;
        x2 = x1 + d->cell_width - 1;
        y2 = y1 + d->cell_height - 1;
        gui_set_clip(x1, y1, x2, y2);
        gui_set_text_clip(x1, y1, x2, y2);
        gui_draw_filled_area(x1, y1, x2, y2, f);
        character_width = gui_get_character_width((UI_character_type) DOW_list[i]);

        gui_move_text_cursor(
            x + ((d->cell_width - character_width) / 2) + (r2lMMIFlag ? character_width : 0),
            y + ((d->cell_height - character_height) / 2));

        gui_set_text_color(text_color);
        gui_print_character((UI_character_type) DOW_list[i]);
        x += d->cell_width + d->cell_gap;
    }
    gdi_layer_pop_clip();
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  DOW_translate_pen_position
 * DESCRIPTION
 *  Translate pen events for DOW
 * PARAMETERS
 *  d               [IN]        DOW input box
 *  x               [IN]        X coordniate
 *  cell_index      [OUT]       Corresponding cell index ( -1 for invalid position)
 * RETURNS
 *  void
 *****************************************************************************/
static void DOW_translate_pen_position(DOW_select *d, S32 x, S32 *cell_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = d->x + d->offset_x;

    if (x < offset)
    {
        *cell_index = -1;
        return;
    }

    for (i = 0; i < 7; i++)
    {
        offset += d->cell_width + d->cell_gap;
        if (x < offset)
        {
            *cell_index = i;
            return;
        }
    }
    *cell_index = -1;
}


/*****************************************************************************
 * FUNCTION
 *  DOW_translate_pen_event
 * DESCRIPTION
 *  Translate pen events for DOW
 * PARAMETERS
 *  d               [IN]        DOW input box
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  DOW_event       [?]         
 *  DOW_param       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
BOOL DOW_translate_pen_event(
        DOW_select *d,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        DOW_pen_event_enum *DOW_event,
        gui_pen_event_param_struct *DOW_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *DOW_event = DOW_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(DOW_param);

    /* Only react to pen down event */
    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        if (PEN_CHECK_BOUND(x, y, d->x, d->y, d->width, d->height))
        {
            S32 cell_index;

            DOW_translate_pen_position(d, x, &cell_index);

            if (cell_index >= 0)
            {
                if (d->highlighted_cell != cell_index)
                {
                    *DOW_event = DOW_PEN_CHANGE_HIGHLIGHT_AND_TOGGLE_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(DOW_param, cell_index);
                }
                else
                {
                    *DOW_event = DOW_PEN_TOGGLE_CURRENT_ITEM;
                }
            }
        }
        else
        {
            ret = MMI_FALSE;
        }
    }

    return ret;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  DOW_select_previous
 * DESCRIPTION
 *  set focus on previous select day of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void DOW_select_previous(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((S32) d->highlighted_cell <= 0)
    {
        return;
    }

    d->highlighted_cell--;
}


/*****************************************************************************
 * FUNCTION
 *  DOW_select_next
 * DESCRIPTION
 *  set focus on next  select day of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void DOW_select_next(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->highlighted_cell >= 6)
    {
        return;
    }

    d->highlighted_cell++;
}


/*****************************************************************************
 * FUNCTION
 *  DOW_select_toggle_item
 * DESCRIPTION
 *  toggle the select or unslect day of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void DOW_select_toggle_item(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((S32) d->highlighted_cell < 0) || (d->highlighted_cell > 6))
    {
        return;
    }

    if (d->states[d->highlighted_cell] == 1)
    {
        d->states[d->highlighted_cell] = 0;
    }
    else if (d->states[d->highlighted_cell] == 0)
    {
        d->states[d->highlighted_cell] = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DOW_select_highlight_item
 * DESCRIPTION
 *  highlight particular day of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 *  i       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void DOW_select_highlight_item(DOW_select *d, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < 0) || (i > 6))
    {
        return;
    }

    d->highlighted_cell = (U8) i;
}

/* Time period input object   */
/* color theme of time period input box */
UI_filled_area time_period_input_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};


/*****************************************************************************
 * FUNCTION
 *  time_period_input_show_background
 * DESCRIPTION
 *  show background of time period
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_show_background(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();
    x1 = d->x;
    y1 = d->y;
    x2 = x1 + d->width - 1;
    y2 = y1 + d->height - 1;
    //20051012 HIMANSHU START INLINE TIME PERIOD
    // for drawing the transparent background for highlighted Time-Period menu item.
    //PMT HIMANSHU INLINE TIME PERIOD START 20051022
    /* There is no need to draw white background now as the text now will not be
       shown because of the flag UI_MENUITEM_EXT_DISABLE_FOCUSSED_TEXT_DISPLAY */
    //      if(wgui_is_wallpaper_on_bottom()==MMI_TRUE)
    //              gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);
    //      else
    //              gui_draw_filled_area(x1,y1,x2,y2,&time_period_input_background_filler);
    //PMT HIMANSHU INLINE TIME PERIOD END 20051022
    //20051012 HIMANSHU END INLINE TIME PERIOD
    x1 = d->hours_input_box1.x;
    y1 = d->y;
    x2 = d->minutes_input_box1.x + d->minutes_input_box1.width - 1;
    y2 = y1 + d->height - 1;
    gui_draw_filled_area(x1, y1, x2, y2, &date_time_input_background_filler);
    x1 = d->hours_input_box2.x;
    y1 = d->y;
    x2 = d->minutes_input_box2.x + d->minutes_input_box2.width - 1;
    y2 = y1 + d->height - 1;
    gui_draw_filled_area(x1, y1, x2, y2, &date_time_input_background_filler);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_reset_focus
 * DESCRIPTION
 *  reset foucus of time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_reset_focus(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->hours_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->hours_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->hours_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->minutes_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->minutes_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->minutes_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->hours_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->hours_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->hours_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->minutes_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->minutes_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->minutes_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->focus_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_focus
 * DESCRIPTION
 *  set foucus of time period input box depend on current focus
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_set_focus(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((d->current_focus < 1) || (d->current_focus > 4))
    {
        return;
    }

    switch (d->focus_list[d->current_focus])
    {
        case TIME_PERIOD_INPUT_FOCUS_HOURS1:
            d->hours_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->hours_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->hours_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->hours_input_box1;
            break;

        case TIME_PERIOD_INPUT_FOCUS_MINUTES1:
            d->minutes_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->minutes_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->minutes_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->minutes_input_box1;
            break;

        case TIME_PERIOD_INPUT_FOCUS_HOURS2:
            d->hours_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->hours_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->hours_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->hours_input_box2;
            break;

        case TIME_PERIOD_INPUT_FOCUS_MINUTES2:
            d->minutes_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->minutes_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->minutes_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->minutes_input_box2;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_default_focus
 * DESCRIPTION
 *  set defualt foucs of time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_set_default_focus(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d->flags & TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MASK)
    {
        case TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS1:
            for (i = 0; i < 6; i++)
            {
                if (d->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_HOURS1)
                {
                    d->current_focus = i;
                }
            }
            break;

        case TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MINUTES1:
            for (i = 0; i < 6; i++)
            {
                if (d->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_MINUTES1)
                {
                    d->current_focus = i;
                }
            }
            break;

        case TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS2:
            for (i = 0; i < 6; i++)
            {
                if (d->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_HOURS2)
                {
                    d->current_focus = i;
                }
            }
            break;

        case TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MINUTES2:
            for (i = 0; i < 6; i++)
            {
                if (d->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_MINUTES2)
                {
                    d->current_focus = i;
                }
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  create_time_period_input
 * DESCRIPTION
 *  set defualt foucs of time period input box
 * PARAMETERS
 *  d                   [IN]        
 *  x                   [IN]        Start x position of time period input
 *  y                   [IN]        Start y position of time period input
 *  width               [IN]        Width of time  period input
 *  height              [IN]        Height of time period input
 *  flags               [IN]        
 *  hours_buffer1       [IN]        Hours buffer first range
 *  minutes_buffer1     [IN]        Minutes buffer first range
 *  hours_buffer2       [IN]        Hours buffer max range
 *  minutes_buffer2     [IN]        Minutes buffer max range
 * RETURNS
 *  void
 *****************************************************************************/
void create_time_period_input(
        time_period_input *d,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags,
        UI_buffer_type hours_buffer1,
        UI_buffer_type minutes_buffer1,
        UI_buffer_type hours_buffer2,
        UI_buffer_type minutes_buffer2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, w2, h, ox, oy, sw1, sw2, tw, l, w;
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->x = x;
    d->y = y;
    d->width = width;
    d->height = height;
    d->flags = flags;

    w= gui_get_character_width((UI_character_type)'0');
    w1 = 2 * w + 6;
    w2 = 2 * w + 6;
    sw1 = TIME_PERIOD_INPUT_SEPERATOR_WIDTH1;
    sw2 = TIME_PERIOD_INPUT_SEPERATOR_WIDTH2;
    tw = w1 + sw1 + w2 + sw2 + w1 + sw1 + w2;
    h = TIME_PERIOD_INPUT_HEIGHT;
    oy = (height >> 1) - (h >> 1);
    switch (flags & TIME_PERIOD_INPUT_JUSTIFY_MASK)
    {
        case TIME_PERIOD_INPUT_RIGHT_JUSTIFY:
            ox = (width - tw);
            break;

        case TIME_PERIOD_INPUT_CENTER_JUSTIFY:
            ox = (width >> 1) - (tw >> 1);
            break;

        default:
            ox = 0;
            break;
    }

    d->focus_list[0] = TIME_PERIOD_INPUT_FOCUS_NONE;
    d->focus_list[5] = TIME_PERIOD_INPUT_FOCUS_NONE;
    d->focus_list[1] = TIME_PERIOD_INPUT_FOCUS_HOURS1;
    d->focus_list[2] = TIME_PERIOD_INPUT_FOCUS_MINUTES1;
    d->focus_list[3] = TIME_PERIOD_INPUT_FOCUS_HOURS2;
    d->focus_list[4] = TIME_PERIOD_INPUT_FOCUS_MINUTES2;
    d->hours1_x = ox;
    ox += w1 + sw1;
    d->minutes1_x = ox;
    ox += w2 + sw2;
    d->hours2_x = ox;
    ox += w1 + sw1;
    d->minutes2_x = ox;
    d->flags |= TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS1;
    current_single_line_input_box_theme = &date_time_input_theme;
    d->hours1_y = oy;
    d->minutes1_y = oy;
    d->hours2_y = oy;
    d->minutes2_y = oy;
    d->s1_y = oy;
    d->s2_y = oy;
    d->s3_y = oy;
    if ((h + 2) > height)
    {
        h = height - 2;
    }
    /* MTK Elvis for R2L characters */
    l = gui_strlen((UI_string_type) hours_buffer1) /* +1 */ ;
    /* create single input box of hours 1 */
    gui_create_single_line_input_box_set_buffer(
        &d->hours_input_box1,
        x + d->hours1_x,
        y + d->hours1_y,
        w1,
        h,
        (UI_string_type) hours_buffer1,
        TIME_PERIOD_INPUT_HOURS_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->hours_input_box1.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->hours_input_box1);
    l = gui_strlen((UI_string_type) minutes_buffer1) /* +1 */ ;
    /* create single input box of minutes 1 */
    gui_create_single_line_input_box_set_buffer(
        &d->minutes_input_box1,
        x + d->minutes1_x,
        y + d->minutes1_y,
        w2,
        h,
        (UI_string_type) minutes_buffer1,
        TIME_PERIOD_INPUT_MINUTES_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->minutes_input_box1.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->minutes_input_box1);
    l = gui_strlen((UI_string_type) hours_buffer1) /* +1 */ ;
    /* create single input box of hours 2 */
    gui_create_single_line_input_box_set_buffer(
        &d->hours_input_box2,
        x + d->hours2_x,
        y + d->hours2_y,
        w1,
        h,
        (UI_string_type) hours_buffer2,
        TIME_PERIOD_INPUT_HOURS_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->hours_input_box2.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->hours_input_box2);
    l = gui_strlen((UI_string_type) minutes_buffer2) /* +1 */ ;
    /* create single input box of minutes 2 */
    gui_create_single_line_input_box_set_buffer(
        &d->minutes_input_box2,
        x + d->minutes2_x,
        y + d->minutes2_y,
        w2,
        h,
        (UI_string_type) minutes_buffer2,
        TIME_PERIOD_INPUT_MINUTES_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->minutes_input_box2.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->minutes_input_box2);
    time_period_input_reset_focus(d);
    time_period_input_set_default_focus(d);
    time_period_input_set_focus(d);
    current_single_line_input_box_theme = t;
    /* MTK end */

    /* Setup default validation functions  */
    d->hours_input_box1.validation_callback = default_inline_time_hours_validation;
    d->minutes_input_box1.validation_callback = default_inline_time_minutes_validation;
    d->hours_input_box2.validation_callback = default_inline_time_hours_validation;
    d->minutes_input_box2.validation_callback = default_inline_time_minutes_validation;
}


/*****************************************************************************
 * FUNCTION
 *  show_time_period_input
 * DESCRIPTION
 *  show time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void show_time_period_input(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;
    S32 sw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_single_line_input_box_theme = &date_time_input_theme;
    gui_set_single_line_input_box_current_theme(&d->hours_input_box1);
    gui_set_single_line_input_box_current_theme(&d->minutes_input_box1);
    gui_set_single_line_input_box_current_theme(&d->hours_input_box2);
    gui_set_single_line_input_box_current_theme(&d->minutes_input_box2);
    /* show single input box of hours 1 */
    gui_show_single_line_input_box(&d->hours_input_box1);
    /* show single input box of minutes 1 */
    gui_show_single_line_input_box(&d->minutes_input_box1);
    /* show single input box of hours2 */
    gui_show_single_line_input_box(&d->hours_input_box2);
    /* show single input box of minutes2 */
    gui_show_single_line_input_box(&d->minutes_input_box2);
    gdi_layer_reset_clip();
    gui_set_font(d->hours_input_box1.text_font);
    gui_set_text_color(d->hours_input_box1.normal_text_color);

    if (r2lMMIFlag)
    {
        gui_set_font(d->hours_input_box1.text_font);
        sw = gui_get_character_width(d->seperator1);
        gui_move_text_cursor(d->s1_x + sw, d->s1_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s1_x, d->s1_y + d->y);
    }

    gui_print_character(d->seperator1);

    if (r2lMMIFlag)
    {
        gui_set_font(d->hours_input_box1.text_font);
        sw = gui_get_character_width(d->seperator2);
        gui_move_text_cursor(d->s2_x + sw, d->s2_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s2_x, d->s2_y + d->y);
    }

    gui_print_character(d->seperator2);

    if (r2lMMIFlag)
    {
        gui_set_font(d->hours_input_box2.text_font);
        sw = gui_get_character_width(d->seperator1);
        gui_move_text_cursor(d->s3_x + sw, d->s3_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s3_x, d->s3_y + d->y);
    }

    gui_print_character(d->seperator1);
    gdi_layer_blt_previous(d->x, d->y, d->x + d->width - 1, d->y + d->height - 1);
    current_single_line_input_box_theme = t;

}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_next_focus
 * DESCRIPTION
 *  set fopcus to next box of time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  byte
 *****************************************************************************/
U8 time_period_input_set_next_focus(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus + 1] == TIME_PERIOD_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        time_period_input_reset_focus(d);
        d->current_focus++;
        time_period_input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_single_line_input_box_goto_first_character(d->focus_input_box);
    #endif 
        return (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_previous_focus
 * DESCRIPTION
 *  set fopcus to previous  box of time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  byte
 *****************************************************************************/
U8 time_period_input_set_previous_focus(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus - 1] == TIME_PERIOD_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        time_period_input_reset_focus(d);
        d->current_focus--;
        time_period_input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_single_line_input_box_goto_last_character(d->focus_input_box);
        gui_single_line_input_box_previous(d->focus_input_box);
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
        return (1);
    }
}

#if defined (__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  time_period_input_move_to_x_y
 * DESCRIPTION
 *  set the cursor position to (x,y) position
 * PARAMETERS
 *  tp      [IN]        Time period input box S32 x S32 y
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_move_to_x_y(time_period_input *tp, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, tp->x, tp->y, tp->width, tp->height) &&
        !(PEN_CHECK_BOUND
          (x, y, tp->minutes_input_box1.x + tp->minutes_input_box1.width, tp->y,
           tp->hours_input_box1.x - (tp->minutes_input_box1.x + tp->minutes_input_box1.width), tp->height)))
    {
        if (PEN_CHECK_BOUND
            (x, y, tp->hours_input_box1.x, tp->hours_input_box1.y, tp->hours_input_box1.width,
             tp->hours_input_box1.height))
        {
            gui_single_line_input_box_goto_first_character(tp->focus_input_box);
            time_period_input_reset_focus(tp);
            for (;; i++)
            {
                if (tp->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_HOURS1)
                {
                    tp->current_focus = i;
                    break;
                }
            }
            time_period_input_set_focus(tp);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, tp->minutes_input_box1.x, tp->minutes_input_box1.y, tp->minutes_input_box1.width,
                  tp->minutes_input_box1.height))
        {
            gui_single_line_input_box_goto_first_character(tp->focus_input_box);
            time_period_input_reset_focus(tp);
            for (;; i++)
            {
                if (tp->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_MINUTES1)
                {
                    tp->current_focus = i;
                    break;
                }
            }
            time_period_input_set_focus(tp);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, tp->hours_input_box2.x, tp->hours_input_box2.y, tp->hours_input_box2.width,
                  tp->hours_input_box2.height))
        {
            gui_single_line_input_box_goto_first_character(tp->focus_input_box);
            time_period_input_reset_focus(tp);
            for (;; i++)
            {
                if (tp->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_HOURS2)
                {
                    tp->current_focus = i;
                    break;
                }
            }
            time_period_input_set_focus(tp);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, tp->minutes_input_box2.x, tp->minutes_input_box2.y, tp->minutes_input_box2.width,
                  tp->minutes_input_box2.height))
        {
            gui_single_line_input_box_goto_first_character(tp->focus_input_box);
            time_period_input_reset_focus(tp);
            for (;; i++)
            {
                if (tp->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_MINUTES2)
                {
                    tp->current_focus = i;
                    break;
                }
            }
            time_period_input_set_focus(tp);
        }
        else
        {
            return;
        }
        gui_show_single_line_input_box_ext(tp->focus_input_box, x, y);
        if (gui_single_line_input_box_test_last_character_position(tp->focus_input_box))
        {
            gui_single_line_input_box_goto_last_character(tp->focus_input_box);
            gui_single_line_input_box_previous(tp->focus_input_box);
        }
        show_time_period_input(tp);
    }
}
#endif /* defined (__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_seperators
 * DESCRIPTION
 *  set the mask of time period input box
 * PARAMETERS
 *  d               [IN]        
 *  seperator1      [IN]        Separator of first time period
 *  seperator2      [IN]        Seperartor of second time period
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_set_seperators(time_period_input *d, UI_character_type seperator1, UI_character_type seperator2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw1, sw2, x1, x2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->seperator1 = seperator1;
    d->seperator2 = seperator2;
    gui_set_font(d->hours_input_box1.text_font);
    sw1 = gui_get_character_width(d->seperator1);
    sw2 = gui_get_character_width(d->seperator2);
    x1 = d->hours_input_box1.x + d->hours_input_box1.width - 1;
    x2 = d->minutes_input_box1.x;
    d->s1_x = x1 + ((x2 - x1) >> 1) - (sw1 >> 1);
    x1 = d->minutes_input_box1.x + d->minutes_input_box1.width - 1;
    x2 = d->hours_input_box2.x;
    d->s2_x = x1 + ((x2 - x1) >> 1) - (sw2 >> 1);
    x1 = d->hours_input_box2.x + d->hours_input_box2.width - 1;
    x2 = d->minutes_input_box2.x;
    d->s3_x = x1 + ((x2 - x1) >> 1) - (sw1 >> 1);
}

/* glbal variable store value of current time period input box */
time_period_input *current_time_period_input = NULL;

/*----------------------------------------------------------------------------
Function:         current_time_period_input_callback
Description:   a function pointer of time period input callback 
Input Parameters: none
               
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*current_time_period_input_callback) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  set_current_time_period_input
 * DESCRIPTION
 *  set the valeu of global variable of current time period input
 *  equal to value pass as parameter
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_time_period_input(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_period_input = d;
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_direct_input
 * DESCRIPTION
 *  insert the character in time period input
 *  and show the time period input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL)
    {
        return;
    }

    if (current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position_overflow(current_time_period_input->focus_input_box))
    {
        if (time_period_input_set_next_focus(current_time_period_input))
        {
            gui_single_line_input_box_insert_character(current_time_period_input->focus_input_box, c);
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(current_time_period_input->focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(current_time_period_input->focus_input_box))
        {
            if (!time_period_input_set_next_focus(current_time_period_input))
            {
                gui_single_line_input_box_previous(current_time_period_input->focus_input_box);
            }
        }
    }
    show_time_period_input(current_time_period_input);
    current_time_period_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_direct_input_nodraw
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_direct_input_nodraw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL)
    {
        return;
    }

    if (current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position_overflow(current_time_period_input->focus_input_box))
    {
        if (time_period_input_set_next_focus(current_time_period_input))
        {
            gui_single_line_input_box_insert_character(current_time_period_input->focus_input_box, c);
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(current_time_period_input->focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(current_time_period_input->focus_input_box))
        {
            if (!time_period_input_set_next_focus(current_time_period_input))
            {
                gui_single_line_input_box_previous(current_time_period_input->focus_input_box);
            }
        }
    }

    current_time_period_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  tp                  [?]         
 *  time_input(?)       [IN]        *t
 * RETURNS
 *  S32
 *****************************************************************************/
S32 time_period_input_test_last_position(time_period_input *tp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tp->focus_list[tp->current_focus + 1] != TIME_PERIOD_INPUT_FOCUS_NONE)
    {
        return 0;
    }
    else
    {
        if (gui_single_line_input_box_test_last_character_position(tp->focus_input_box))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_delete_character
 * DESCRIPTION
 *  delete caharcter of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL)
    {
        return;
    }

    if (current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(current_time_period_input->focus_input_box))
    {
        time_period_input_set_previous_focus(current_time_period_input);
    }
    else
    {
        gui_single_line_input_box_delete_character(current_time_period_input->focus_input_box);
        if (gui_single_line_input_box_test_first_position(current_time_period_input->focus_input_box))
        {
            time_period_input_set_previous_focus(current_time_period_input);
        }
    }
    /* show time period input box */
    show_time_period_input(current_time_period_input);
    current_time_period_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_previous_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL)
    {
        return;
    }

    if (current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(current_time_period_input->focus_input_box))
    {
        if (time_period_input_set_previous_focus(current_time_period_input))
        {
            gui_single_line_input_box_goto_last_character(current_time_period_input->focus_input_box);
            gui_single_line_input_box_previous(current_time_period_input->focus_input_box);
        }
    }
    else
    {
        gui_single_line_input_box_previous(current_time_period_input->focus_input_box);
    }
    /* show time period input box */
    show_time_period_input(current_time_period_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_next_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL)
    {
        return;
    }

    if (current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_character_position(current_time_period_input->focus_input_box))
    {
        time_period_input_set_next_focus(current_time_period_input);
    }
    else
    {
        gui_single_line_input_box_next(current_time_period_input->focus_input_box);
    }
    /* show time period input box */
    show_time_period_input(current_time_period_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_toggle_insert_mode
 * DESCRIPTION
 *  cahneg the insert mode of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL)
    {
        return;
    }
    if (current_time_period_input->focus_input_box == NULL)
    {
        return;
    }
    gui_single_line_input_box_toggle_insert_mode(current_time_period_input->focus_input_box);
    /* show time period input box */
    show_time_period_input(current_time_period_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_delete_current_character
 * DESCRIPTION
 *  delete current  character of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL)
    {
        return;
    }

    if (current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    gui_single_line_input_box_delete_current_character(current_time_period_input->focus_input_box);
    /* show time period input box */
    show_time_period_input(current_time_period_input);
    current_time_period_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_delete_all_characters
 * DESCRIPTION
 *  delete all character of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL)
    {
        return;
    }
    if (current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    gui_single_line_input_box_delete_all(current_time_period_input->focus_input_box);
    /* show time period input box */
    show_time_period_input(current_time_period_input);
    current_time_period_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  handle time period numeric input
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        time_period_input_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        time_period_input_delete_character();
    }
    else if (keyc == 0x1b)
    {
        time_period_input_delete_all_characters();
    }
    else if (keyc == 0x0d);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_handle_key_down
 * DESCRIPTION
 *  handle time periosd key down event
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_period_input_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_key_handler
 * DESCRIPTION
 *  register  key handlers of time period input box
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                time_period_input_previous_character();
                break;
            case 38:    /* up */
                break;
            case 39:
                time_period_input_next_character();
                break;
            case 40:    /* down */
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                time_period_input_toggle_insert_mode();
                break;
            case 46:
                time_period_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_register_keys
 * DESCRIPTION
 *  register all key handlers of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_down_handler(time_period_input_handle_key_down);
    register_keyboard_input_handler(time_period_input_numeric_keyboard_input_handler);
    SetKeyHandler(time_period_input_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(time_period_input_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    register_keyboard_key_handler(time_period_input_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_clear_keys
 * DESCRIPTION
 *  clear all key handlers of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_clear_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();
    clear_key_down_handler();
    clear_keyboard_input_handler();
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    clear_keyboard_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  register_time_period_input_callback
 * DESCRIPTION
 *  register current time period input callback function
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void register_time_period_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_period_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_time_period_input_callback
 * DESCRIPTION
 *  set current time period input callback to dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_time_period_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_period_input_callback = UI_dummy_function;
}

/* Default IP field validation functions  */


/*****************************************************************************
 * FUNCTION
 *  default_inline_IP_field_validation
 * DESCRIPTION
 *  validaion function of IP4 input box
 * PARAMETERS
 *  text            [IN]        
 *  cursor          [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_IP_field_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i < 0)
    {
        i = 0;
        gui_sprintf((UI_string_type) text, "%03d", i);
        UI_editor_play_tone_invalid_data();
    }
    else if (i > 255)
    {
        i = 255;
        gui_sprintf((UI_string_type) text, "%03d", i);
        UI_editor_play_tone_invalid_data();
    }
}

/* IP4 input object  */


/*****************************************************************************
 * FUNCTION
 *  IP4_input_show_background
 * DESCRIPTION
 *  show background of Ip4 input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_show_background(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();
    x1 = d->x;
    y1 = d->y;
    x2 = x1 + d->width - 1;
    y2 = y1 + d->height - 1;
    gui_draw_filled_area(x1, y1, x2, y2, &date_time_input_background_filler);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_reset_focus
 * DESCRIPTION
 *  reset focus of IP4 input box to default
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_reset_focus(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->field_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->field_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->field_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->field_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->field_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->field_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->field_input_box3.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->field_input_box3.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->field_input_box3.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->field_input_box4.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    d->field_input_box4.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    d->field_input_box4.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    d->focus_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_focus
 * DESCRIPTION
 *  set focus to particaulr field depend on teh value
 *  of current focus
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_set_focus(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((d->current_focus < 1) || (d->current_focus > 4))
    {
        return;
    }

    switch (d->focus_list[d->current_focus])
    {
        case IP4_INPUT_FOCUS_FIELD1:
            d->field_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->field_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->field_input_box1.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->field_input_box1;
            break;

        case IP4_INPUT_FOCUS_FIELD2:
            d->field_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->field_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->field_input_box2.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->field_input_box2;
            break;

        case IP4_INPUT_FOCUS_FIELD3:
            d->field_input_box3.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->field_input_box3.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->field_input_box3.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->field_input_box3;
            break;

        case IP4_INPUT_FOCUS_FIELD4:
            d->field_input_box4.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
            d->field_input_box4.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
            d->field_input_box4.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            d->focus_input_box = &d->field_input_box4;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_default_focus
 * DESCRIPTION
 *  set focus to default box of IP4
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_set_default_focus(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d->flags & IP4_INPUT_TYPE_DEFAULT_FOCUS_MASK)
    {
        case IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD1:
            for (i = 0; i < 6; i++)
            {
                if (d->focus_list[i] == IP4_INPUT_FOCUS_FIELD1)
                {
                    d->current_focus = i;
                }
            }
            break;

        case IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD2:
            for (i = 0; i < 6; i++)
            {
                if (d->focus_list[i] == IP4_INPUT_FOCUS_FIELD2)
                {
                    d->current_focus = i;
                }
            }
            break;

        case IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD3:
            for (i = 0; i < 6; i++)
            {
                if (d->focus_list[i] == IP4_INPUT_FOCUS_FIELD3)
                {
                    d->current_focus = i;
                }
            }
            break;

        case IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD4:
            for (i = 0; i < 6; i++)
            {
                if (d->focus_list[i] == IP4_INPUT_FOCUS_FIELD4)
                {
                    d->current_focus = i;
                }
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  create_IP4_input
 * DESCRIPTION
 *  create Ip4 input box
 * PARAMETERS
 *  d                   [IN]        
 *  x                   [IN]        Start x postion of ip4 input box
 *  y                   [IN]        Start y position of ip4 input box
 *  width               [IN]        Width of ip4 input box
 *  height              [IN]        
 *  flags               [IN]        
 *  b1                  [IN]        Buffer1 of ip4 input box
 *  b2                  [IN]        Buffer 2 of ip4 input box
 *  b3                  [IN]        Buffer 3o f ip4 input box
 *  b4                  [IN]        Buffer 4 of ip4 input box
 *  heighthight(?)      [IN]        Of ip4 input box
 * RETURNS
 *  void
 *****************************************************************************/
void create_IP4_input(
        IP4_input *d,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags,
        UI_buffer_type b1,
        UI_buffer_type b2,
        UI_buffer_type b3,
        UI_buffer_type b4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, ox, oy, sw, tw, l;
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->x = x;
    d->y = y;
    d->width = width;
    d->height = height;
    d->flags = flags;
    if (((width >> 2) - 1) < IP4_INPUT_FIELD_WIDTH)
    {
        w = (width >> 2) - 1;
    }
    else
    {
        w= gui_get_character_width((UI_character_type)'0') * 3 + 6;
        /* w = IP4_INPUT_FIELD_WIDTH; */
    }
    sw = IP4_INPUT_SEPERATOR_WIDTH;
    tw = w + sw + w + sw + w + sw + w;
    h =  gui_get_character_height() + 1;
    h = (h < IP4_INPUT_HEIGHT) ? IP4_INPUT_HEIGHT : h;
    oy = (height >> 1) - (h >> 1);
    switch (flags & IP4_INPUT_JUSTIFY_MASK)
    {
        case IP4_INPUT_RIGHT_JUSTIFY:
            ox = (width - tw - 2);
            break;
        case IP4_INPUT_CENTER_JUSTIFY:
            ox = (width >> 1) - (tw >> 1);
            break;
        default:
            ox = 2;
            break;
    }

    d->focus_list[0] = IP4_INPUT_FOCUS_NONE;
    d->focus_list[5] = IP4_INPUT_FOCUS_NONE;
    d->focus_list[1] = IP4_INPUT_FOCUS_FIELD1;
    d->focus_list[2] = IP4_INPUT_FOCUS_FIELD2;
    d->focus_list[3] = IP4_INPUT_FOCUS_FIELD3;
    d->focus_list[4] = IP4_INPUT_FOCUS_FIELD4;
    d->field1_x = ox;
    ox += w + sw;
    d->field2_x = ox;
    ox += w + sw;
    d->field3_x = ox;
    ox += w + sw;
    d->field4_x = ox;
    ox += w + sw;
    d->flags |= IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD1;
    current_single_line_input_box_theme = &date_time_input_theme;
    d->field1_y = oy;
    d->field2_y = oy;
    d->field3_y = oy;
    d->field4_y = oy;
    d->s1_y = oy;
    d->s2_y = oy;
    d->s3_y = oy;
    if ((h + 2) > height)
    {
        h = height - 2;
    }

    l = gui_strlen((UI_string_type) b1) /* +1 */ ;
    /* craete single inpyut box of field1 */
    gui_create_single_line_input_box_set_buffer(
        &d->field_input_box1,
        x + d->field1_x,
        y + d->field1_y,
        w,
        h,
        (UI_string_type) b1,
        IP4_INPUT_FIELD_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->field_input_box1.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->field_input_box1);
    l = gui_strlen((UI_string_type) b2) /* +1 */ ;
    /* craete single inpyut box of field2 */
    gui_create_single_line_input_box_set_buffer(
        &d->field_input_box2,
        x + d->field2_x,
        y + d->field2_y,
        w,
        h,
        (UI_string_type) b2,
        IP4_INPUT_FIELD_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->field_input_box2.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->field_input_box2);
    l = gui_strlen((UI_string_type) b3) /* +1 */ ;
    /* craete single inpyut box of field3 */
    gui_create_single_line_input_box_set_buffer(
        &d->field_input_box3,
        x + d->field3_x,
        y + d->field3_y,
        w,
        h,
        (UI_string_type) b3,
        IP4_INPUT_FIELD_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->field_input_box3.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->field_input_box3);
    l = gui_strlen((UI_string_type) b4) /* +1 */ ;
    /* craete single inpyut box of field4 */
    gui_create_single_line_input_box_set_buffer(
        &d->field_input_box4,
        x + d->field4_x,
        y + d->field4_y,
        w,
        h,
        (UI_string_type) b4,
        IP4_INPUT_FIELD_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->field_input_box4.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
    gui_single_line_input_box_goto_first_character(&d->field_input_box4);
    IP4_input_reset_focus(d);
    IP4_input_set_default_focus(d);
    IP4_input_set_focus(d);
    current_single_line_input_box_theme = t;
    /* MTK end */

    /* Setup default validation functions  */
    d->field_input_box1.validation_callback = default_inline_IP_field_validation;
    d->field_input_box2.validation_callback = default_inline_IP_field_validation;
    d->field_input_box3.validation_callback = default_inline_IP_field_validation;
    d->field_input_box4.validation_callback = default_inline_IP_field_validation;
}


/*****************************************************************************
 * FUNCTION
 *  show_IP4_input
 * DESCRIPTION
 *  show Ip4 input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void show_IP4_input(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* show single input box  field1 */
    gui_show_single_line_input_box(&d->field_input_box1);
    /* show single input box  field2 */
    gui_show_single_line_input_box(&d->field_input_box2);
    /* show single input box  field3 */
    gui_show_single_line_input_box(&d->field_input_box3);
    /* show single input box  field4 */
    gui_show_single_line_input_box(&d->field_input_box4);
    gdi_layer_reset_clip();
    gui_set_font(d->field_input_box1.text_font);
    gui_set_text_color(d->field_input_box1.normal_text_color);

    if (r2lMMIFlag)
    {
        gui_set_font(d->field_input_box1.text_font);
        sw = gui_get_character_width(d->seperator);
        gui_move_text_cursor(d->s1_x + sw, d->s1_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s1_x, d->s1_y + d->y);
    }
    gui_print_character(d->seperator);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(d->s2_x + sw, d->s2_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s2_x, d->s2_y + d->y);
    }

    gui_print_character(d->seperator);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(d->s3_x + sw, d->s3_y + d->y);
    }
    else
    {
        gui_move_text_cursor(d->s3_x, d->s3_y + d->y);
    }

    gui_print_character(d->seperator);
    gdi_layer_blt_previous(d->x, d->y, d->x + d->width - 1, d->y + d->height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_next_focus
 * DESCRIPTION
 *  set focus to next  character
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 IP4_input_set_next_focus(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus + 1] == IP4_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        IP4_input_reset_focus(d);
        d->current_focus++;
        IP4_input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_single_line_input_box_goto_first_character(d->focus_input_box);
    #endif 
        return (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_previous_focus
 * DESCRIPTION
 *  set focus to previous character
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 IP4_input_set_previous_focus(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->focus_list[d->current_focus - 1] == IP4_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        IP4_input_reset_focus(d);
        d->current_focus--;
        IP4_input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_single_line_input_box_goto_last_character(d->focus_input_box);
        gui_single_line_input_box_previous(d->focus_input_box);
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
        return (1);
    }
}

#if defined (__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  IP4_input_move_to_x_y
 * DESCRIPTION
 *  set the cursor position to (x,y) position
 * PARAMETERS
 *  ip4     [IN]        IP4 input box S32 x S32 y
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_move_to_x_y(IP4_input *ip4, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, ip4->x, ip4->y, ip4->width, ip4->height))
    {
        if (PEN_CHECK_BOUND
            (x, y, ip4->field_input_box1.x, ip4->field_input_box1.y, ip4->field_input_box1.width,
             ip4->field_input_box1.height))
        {
            gui_single_line_input_box_goto_first_character(ip4->focus_input_box);
            IP4_input_reset_focus(ip4);
            for (;; i++)
            {
                if (ip4->focus_list[i] == IP4_INPUT_FOCUS_FIELD1)
                {
                    ip4->current_focus = i;
                    break;
                }
            }
            IP4_input_set_focus(ip4);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, ip4->field_input_box2.x, ip4->field_input_box2.y, ip4->field_input_box2.width,
                  ip4->field_input_box2.height))
        {
            gui_single_line_input_box_goto_first_character(ip4->focus_input_box);
            IP4_input_reset_focus(ip4);
            for (;; i++)
            {
                if (ip4->focus_list[i] == IP4_INPUT_FOCUS_FIELD2)
                {
                    ip4->current_focus = i;
                    break;
                }
            }
            IP4_input_set_focus(ip4);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, ip4->field_input_box3.x, ip4->field_input_box3.y, ip4->field_input_box3.width,
                  ip4->field_input_box3.height))
        {
            gui_single_line_input_box_goto_first_character(ip4->focus_input_box);
            IP4_input_reset_focus(ip4);
            for (;; i++)
            {
                if (ip4->focus_list[i] == IP4_INPUT_FOCUS_FIELD3)
                {
                    ip4->current_focus = i;
                    break;
                }
            }
            IP4_input_set_focus(ip4);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, ip4->field_input_box4.x, ip4->field_input_box4.y, ip4->field_input_box4.width,
                  ip4->field_input_box4.height))
        {
            gui_single_line_input_box_goto_first_character(ip4->focus_input_box);
            IP4_input_reset_focus(ip4);
            for (;; i++)
            {
                if (ip4->focus_list[i] == IP4_INPUT_FOCUS_FIELD4)
                {
                    ip4->current_focus = i;
                    break;
                }
            }
            IP4_input_set_focus(ip4);
        }
        else
        {
            /*
             * for(;;i++)
             * {
             * if (ip4->focus_list[i]==IP4_INPUT_FOCUS_NONE)
             * {
             * ip4->current_focus = i-1;
             * break;
             * }
             * }
             * IP4_input_set_focus(ip4);
             */
            return;
        }
        gui_show_single_line_input_box_ext(ip4->focus_input_box, x, y);
        if (gui_single_line_input_box_test_last_character_position(ip4->focus_input_box))
        {
            gui_single_line_input_box_goto_last_character(ip4->focus_input_box);
            gui_single_line_input_box_previous(ip4->focus_input_box);
        }
        show_IP4_input(ip4);
    }
}
#endif /* defined (__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_seperator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  d               [IN]        
 *  seperator       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_set_seperator(IP4_input *d, UI_character_type seperator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, x1, x2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->seperator = seperator;
    gui_set_font(d->field_input_box1.text_font);
    sw = gui_get_character_width(d->seperator);
    x1 = d->field_input_box1.x + d->field_input_box1.width - 1;
    x2 = d->field_input_box2.x;
    d->s1_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
    x1 = d->field_input_box2.x + d->field_input_box2.width - 1;
    x2 = d->field_input_box3.x;
    d->s2_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
    x1 = d->field_input_box3.x + d->field_input_box3.width - 1;
    x2 = d->field_input_box4.x;
    d->s3_x = x1 + ((x2 - x1) >> 1) - (sw >> 1);
}

/* a global variabel o ftype IP4_input */
IP4_input *current_IP4_input = NULL;

/*----------------------------------------------------------------------------
Function:         current_IP4_input_callback
Description:      a function pointer store the address of function 
               of I4 input callback 
Input Parameters: none
               
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/
void (*current_IP4_input_callback) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  set_current_IP4_input
 * DESCRIPTION
 *  Set the global variable of IP4_input equal to valeu pass as parameter
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_IP4_input(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_IP4_input = d;
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_direct_input
 * DESCRIPTION
 *  append the currentinsert character to IP4 text and show the Ip4 text box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL)
    {
        return;
    }

    if (current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position_overflow(current_IP4_input->focus_input_box))
    {
        if (IP4_input_set_next_focus(current_IP4_input))
        {
            gui_single_line_input_box_insert_character(current_IP4_input->focus_input_box, c);
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(current_IP4_input->focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(current_IP4_input->focus_input_box))
        {
            if (!IP4_input_set_next_focus(current_IP4_input))
            {
                gui_single_line_input_box_previous(current_IP4_input->focus_input_box);
            }
        }
    }
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
    current_IP4_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_direct_input_nodraw
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_direct_input_nodraw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL)
    {
        return;
    }

    if (current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_position_overflow(current_IP4_input->focus_input_box))
    {
        if (IP4_input_set_next_focus(current_IP4_input))
        {
            gui_single_line_input_box_insert_character(current_IP4_input->focus_input_box, c);
        }
    }
    else
    {
        gui_single_line_input_box_insert_character(current_IP4_input->focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(current_IP4_input->focus_input_box))
        {
            if (!IP4_input_set_next_focus(current_IP4_input))
            {
                gui_single_line_input_box_previous(current_IP4_input->focus_input_box);
            }
        }
    }
    current_IP4_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  ip4     [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 IP4_input_test_last_position(IP4_input *ip4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ip4->focus_list[ip4->current_focus + 1] != IP4_INPUT_FOCUS_NONE)
    {
        return 0;
    }
    else
    {
        if (gui_single_line_input_box_test_last_character_position(ip4->focus_input_box))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_delete_character
 * DESCRIPTION
 *  delete character of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL)
    {
        return;
    }

    if (current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(current_IP4_input->focus_input_box))
    {
        IP4_input_set_previous_focus(current_IP4_input);
    }
    else
    {
        gui_single_line_input_box_delete_character(current_IP4_input->focus_input_box);
        if (gui_single_line_input_box_test_first_position(current_IP4_input->focus_input_box))
        {
            IP4_input_set_previous_focus(current_IP4_input);
        }
    }
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
    current_IP4_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_previous_character
 * DESCRIPTION
 *  set focus to previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL)
    {
        return;
    }

    if (current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_first_position(current_IP4_input->focus_input_box))
    {
        if (IP4_input_set_previous_focus(current_IP4_input))
        {
            gui_single_line_input_box_goto_last_character(current_IP4_input->focus_input_box);
            gui_single_line_input_box_previous(current_IP4_input->focus_input_box);
        }
    }
    else
    {
        gui_single_line_input_box_previous(current_IP4_input->focus_input_box);
    }
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_next_character
 * DESCRIPTION
 *  set focus to next caharacter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL)
    {
        return;
    }

    if (current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    if (gui_single_line_input_box_test_last_character_position(current_IP4_input->focus_input_box))
    {
        IP4_input_set_next_focus(current_IP4_input);
    }
    else
    {
        gui_single_line_input_box_next(current_IP4_input->focus_input_box);
    }
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_toggle_insert_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL)
    {
        return;
    }

    if (current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    gui_single_line_input_box_toggle_insert_mode(current_IP4_input->focus_input_box);
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_delete_current_character
 * DESCRIPTION
 *  delete current charactert of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL)
    {
        return;
    }

    if (current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    /* delete current caharcter of IP4 input box */
    gui_single_line_input_box_delete_current_character(current_IP4_input->focus_input_box);
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
    current_IP4_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_delete_all_characters
 * DESCRIPTION
 *  delete all characterts of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL)
    {
        return;
    }

    if (current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    /* delete all charcters of IP4 input box */
    gui_single_line_input_box_delete_all(current_IP4_input->focus_input_box);
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
    current_IP4_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  handle numeric key input of IP4 input box
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        IP4_input_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        IP4_input_delete_character();
    }
    else if (keyc == 0x1b)
    {
        IP4_input_delete_all_characters();
    }
    else if (keyc == 0x0d);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_handle_key_down
 * DESCRIPTION
 *  funtion handle key down event of IP4 input box
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IP4_input_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_key_handler
 * DESCRIPTION
 *  regsiter key handlers of IP4 input box
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                IP4_input_previous_character();
                break;
            case 38:    /* up */
                break;
            case 39:
                IP4_input_next_character();
                break;
            case 40:    /* down */
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                IP4_input_toggle_insert_mode();
                break;
            case 46:
                IP4_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_register_keys
 * DESCRIPTION
 *  regsiter key handlers of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_down_handler(IP4_input_handle_key_down);
    register_keyboard_input_handler(IP4_input_numeric_keyboard_input_handler);
    SetKeyHandler(IP4_input_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(IP4_input_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    register_keyboard_key_handler(IP4_input_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_clear_keys
 * DESCRIPTION
 *  clear all key events of IP4 input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_clear_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();
    clear_key_down_handler();
    clear_keyboard_input_handler();
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    clear_keyboard_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  register_IP4_input_callback
 * DESCRIPTION
 *  registe IP4 input callback function
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void register_IP4_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_IP4_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_IP4_input_callback
 * DESCRIPTION
 *  clear ip4 input callback to dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_IP4_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_IP4_input_callback = UI_dummy_function;
}


void (*MMI_main_LCD_time_duration_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_time_duration_hide_function
 * DESCRIPTION
 *  set hide time duration function for main lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Ptr f
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_time_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_time_duration_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_time_duration
 * DESCRIPTION
 *  set main lcd time duration object
 * PARAMETERS
 *  t               [IN]        
 *  duration        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_time_duration(UI_time *t, U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_time_object.duration.t = *t;   /* set the duration value */
    kal_get_time(&last_duration_ticks);
    last_duration = duration;
}


/*****************************************************************************
 * FUNCTION
 *  get_time_duration
 * DESCRIPTION
 *  get main lcd time duration object
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_time_duration(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *t = main_LCD_time_object.duration.t;   /* get the duration value */
}


/*****************************************************************************
 * FUNCTION
 *  get_duration_string
 * DESCRIPTION
 *  get main lcd time duration string
 * PARAMETERS
 *  t           [IN]        
 *  s           [IN]        
 *  flags       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_duration_string(UI_time *t, UI_string_type s, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hours, minutes, seconds;
    S8 ts[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hours = get_hours(t);
    minutes = get_minutes(t);
    seconds = get_seconds(t);
    sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
    mmi_asc_to_ucs2((S8*) s, ts);
}


/*****************************************************************************
 * FUNCTION
 *  time_display_duration
 * DESCRIPTION
 *  display time duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_display_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type s[64];
    S32 x1, y1, x2, y2;
    S32 w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = main_LCD_time_object.duration.x;
    y1 = main_LCD_time_object.duration.y;
    x2 = main_LCD_time_object.duration.width + x1 - 1;
    y2 = main_LCD_time_object.duration.height + y1 - 1;
    main_LCD_time_object.duration.hide_function(x1, y1, x2, y2);        /* call hide function of call duration */

    gui_set_font(main_LCD_time_object.duration.font);
    /* get call duration in string fromat */
    get_duration_string(&main_LCD_time_object.duration.t, (UI_string_type) s, main_LCD_time_object.flags);
    gui_set_text_color(main_LCD_time_object.duration.text_color);
    w = gui_get_string_width(s);

    if (r2lMMIFlag)
    {
        //gui_move_text_cursor(x1 + w, y1);
        gui_move_text_cursor(x1+((main_LCD_time_object.duration.width-w)>>1)+w, y1);
    }
    else
    {
        //gui_move_text_cursor(x1, y1);
        gui_move_text_cursor(x1+((main_LCD_time_object.duration.width-w)>>1), y1);
    }

    gui_set_text_clip(x1, y1, x2, y2);
    /* print call duration */
    gui_print_text(s);
    gdi_layer_blt_previous(x1, y1, x2, y2);

}


/*****************************************************************************
 * FUNCTION
 *  time_update_duration
 * DESCRIPTION
 *  update time duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    increment_ticks(&main_LCD_time_object.duration.t);  /* increment secods by 1 */
    time_display_duration();
    gui_start_timer(300, time_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  set_time_display
 * DESCRIPTION
 *  set time duration object properties
 * PARAMETERS
 *  flags       [IN]        
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_time_display(U32 flags, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    main_LCD_time_object.flags = (flags & DT_FLAGS_TYPE);
    main_LCD_time_object.duration.hide_function = MMI_main_LCD_time_duration_hide_function;
    main_LCD_time_object.duration.font = &MMI_large_font;
	main_LCD_time_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
    main_LCD_time_object.duration.x = x;
    main_LCD_time_object.duration.y = y;
    main_LCD_time_object.duration.width = width;
    main_LCD_time_object.duration.height = height;
    gui_cancel_timer(time_update_duration);
    if (flags != 0)
    {
        gui_start_timer(300, time_update_duration);
    }
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  close_main_LCD_time_display
 * DESCRIPTION
 *  disable main lcd time display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_main_LCD_time_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(time_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  enactive_main_lcd_update_date_time
 * DESCRIPTION
 *  enable update date time for main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void enactive_main_lcd_update_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_lcd_update_date_time = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  deactive_main_lcd_update_date_time
 * DESCRIPTION
 *  disable update date time for main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void deactive_main_lcd_update_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_lcd_update_date_time = MMI_FALSE;
}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  enactive_sub_lcd_update_date_time
 * DESCRIPTION
 *  enable update date time display for sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void enactive_sub_lcd_update_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sub_lcd_update_date_time = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  deactive_sub_lcd_update_date_time
 * DESCRIPTION
 *  disable update date time display for sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void deactive_sub_lcd_update_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sub_lcd_update_date_time = MMI_FALSE;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  set_main_lcd_duration_position
 * DESCRIPTION
 *  set the position of duration display on main lcd
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_lcd_duration_position(U16 x, U16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_dt_object.duration.x = x;
    main_LCD_dt_object.duration.y = y;
}

/* PMT HIMANSHU START 20050721 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__


/*****************************************************************************
 * FUNCTION
 *  wgui_set_clock_type
 * DESCRIPTION
 *  set the value of the current clock to be displayed.
 * PARAMETERS
 *  clock_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_clock_type(U8 clock_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (clock_type)
    {
        case ANALOG:
            g_clock_type = ANALOG;
            idlescreen_bar_id = IMG_TECHNO_ANALOG_CLOCK;//070306 Alpha layer
            break;
        case DIGITAL:
            g_clock_type = DIGITAL;
            idlescreen_bar_id = IMG_TECHNO_DIGITAL_CLOCK;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_day_display
 * DESCRIPTION
 *  set the pointer to point to the current day string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_day_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    day_string = get_string((U16) (STR_IDLESCREEN_SUNDAY + main_LCD_dt_object.date.t.DayIndex));
}


/*****************************************************************************
 * FUNCTION
 *  show_main_LCD_day_display
 * DESCRIPTION
 *  show the day string on main lcd in techon idlescreeen
 *  bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_main_LCD_day_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 x1, y1, x2, y2;
    S32 w, h;
    stFontAttribute *font;
    color text_color, text_border_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_color = *current_MMI_theme->idle_scr_weekday_color;
    text_border_color = *current_MMI_theme->idle_scr_weekday_border_color;
#ifdef __MMI_MAINLCD_240X320__
    font = (&MMI_medium_font);
#else /* __MMI_MAINLCD_240X320__ */ 
    font = (&MMI_small_font);
#endif /* __MMI_MAINLCD_240X320__ */ 
    gui_set_font(font);
    gui_measure_string(day_string, &w, &h);
    gui_set_text_color(text_color);
    gui_set_text_border_color(text_border_color);
	if (g_clock_type == ANALOG)
	{
    x1 = ANALOG_BACKGROUND_X + ANALOG_BACKGROUND_WIDTH + 1;
	}
	else
	{
		x1 = DIGITAL_BACKGROUND_X + DIGITAL_BACKGROUND_WIDTH + 1;
	}
    y1 = MMI_status_bar_height + ((MMI_IDLESCREEN_BAR_HEIGHT + (MMI_IDLESCREEN_BAR_HEIGHT >> 1) - h) >> 1);
    x2 = UI_device_width - MMI_SIGNAL_WIDTH;
    y2 = y1 + h - 1;
    gdi_layer_push_clip();
    gui_set_clip(x1, y1-1, x2, y2+1);//091206 idlescreen day
    /* PMT HIMANSHU START 20051012 */
    /* Day string is not coming at right location in case of r2lMMIFlag is ON.
       So move the cursor at correct position. */
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2 - 2, y1);
    }
    else
    {
        gui_move_text_cursor(((x2 - 2) - w), y1);
    }
    /* PMT HIMANSHU END 20051012 */
    gui_print_bordered_text(day_string);
    gdi_layer_pop_clip();

    gdi_layer_blt_previous(x1, y1-1, x2, y2+1);
    
}
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
/* PMT HIMANSHU END 20050721 */

