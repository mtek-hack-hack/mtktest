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
 *   wgui_categories_stopwatch.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Functions to display Stop Watch related Screens
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_STOPWATCH__

#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"

#include "GlobalDefs.h"
#include "gui_data_types.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "EventsDef.h"
#include "gdi_lcd_config.h"     /* LCD_WIDTH */
#include "gui_themes.h"
#include "gui.h"
#include "wgui.h"
#include "CustThemesRes.h"
#include "wgui_categories.h"
#include "wgui_categories_defs.h"
#include "wgui_fixed_menus.h"

/* Stopwatch Header Files */
#include "wgui_categories_stopwatch.h"
#include "StopwatchGprot.h"
#include "StopwatchResDef.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h" 
#endif 

/*  Include: PS header file */
#include "l1_const.h"
#include "l1_types.h"

#include "wgui_draw_manager.h"
extern stFontAttribute wgui_dialer_box_f1;
/***************************************************************************** 
* Local Variable
*****************************************************************************/
U8 stop_play_flag = 0;

static U32 gInitialTime = 0;
static U32 gCurrentTime = 0;

static U32 gMPInitialTime = 0;
static U32 gMPCurrentTime = 0;

/* Component coordinate setup */
#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) )

#define STPWACH_NW_SPAC_SIDE 0
#define STPWACH_NW_SPAC_TOP 0
#define STPWACH_NW_FRAM_BORDER   3

wtchSkinResStruct wtch_pos = 
{
    {(LCD_WIDTH >> 1), 70, 0, 0},             /* wtch_coor_type typ_timer */ 
    {(LCD_WIDTH >> 1), 85, 0, 0},             /* wtch_coor_type typ_milsec */
    {MMI_MENUITEM_HEIGHT << 1},         /* typ_history_height, 2 line */ 

    {0},                                /* U16 separator_height */ 
    {0, 0, 0, 0},                             /* nWay_maintimer_start */ 
    {LCD_WIDTH, MMI_MENUITEM_HEIGHT, 0, 0},   /* nWay_maintimer_end */ 
    {0, MMI_MENUITEM_HEIGHT, 0, 0},           /* nWay_dialog_start */ 
    {LCD_WIDTH, LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - STPWACH_NW_FRAM_BORDER, 0, 0}, /* nWay_dialog_end */ 
};

#elif ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )

#define STPWACH_NW_SPAC_SIDE 0
#define STPWACH_NW_SPAC_TOP 0
#define STPWACH_NW_FRAM_BORDER   1

wtchSkinResStruct wtch_pos = 
{
    {(LCD_WIDTH >> 1), 88, 0, 0},             /* wtch_coor_type typ_timer */ 
    {(LCD_WIDTH >> 1), 105, 0, 0},            /* wtch_coor_type typ_milsec */
    {MMI_MENUITEM_HEIGHT << 1},         /* typ_history_height, 2 line */ 

    {MMI_MENUITEM_HEIGHT},              /* U16 separator_height */ 
    {0, 0, 0, 0},                             /* nWay_maintimer_start */ 
    {LCD_WIDTH, MMI_MENUITEM_HEIGHT, 0, 0},   /* nWay_maintimer_end */ 
    {0, MMI_MENUITEM_HEIGHT, 0, 0},           /* nWay_dialog_start */ 
    {LCD_WIDTH, LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - STPWACH_NW_FRAM_BORDER, 0, 0}, /* nWay_dialog_end */ 
};

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )

#define STPWACH_NW_SPAC_SIDE 0
#define STPWACH_NW_SPAC_TOP 0
#define STPWACH_NW_FRAM_BORDER   3

wtchSkinResStruct wtch_pos = 
{
    {(LCD_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 61, 0, 0},    /* wtch_coor_type typ_timer */ 
    {(LCD_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 73, 0, 0},    /* wtch_coor_type typ_milsec */
    {(MMI_MENUITEM_HEIGHT << 2)},                           /* typ_history_height, 4 line */ 

    {30},                                                   /* U16 separator_height */ 
    {10, 10, 0, 0},                                               /* nWay_maintimer_start */ 
    {LCD_WIDTH - 10, 40, 0, 0},                                   /* nWay_maintimer_end */ 
    {10, 40, 0, 0},                                               /* nWay_dialog_start */ 
    {LCD_WIDTH - 10, LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10, 0, 0}, /* nWay_dialog_end */ 
};

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) ) 

#define STPWACH_NW_SPAC_SIDE 0
#define STPWACH_NW_SPAC_TOP 0
#define STPWACH_NW_FRAM_BORDER   3

wtchSkinResStruct wtch_pos = 
{
    {(LCD_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 61, 0, 0},    /* wtch_coor_type typ_timer */ 
    {(LCD_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 73, 0, 0},    /* wtch_coor_type typ_milsec */
    {(MMI_MENUITEM_HEIGHT *5)},                             /* typ_history_height, 4 line */ 

    {30},                                                   /* U16 separator_height */ 
    {10, 10, 0, 0},                                               /* nWay_maintimer_start */ 
    {LCD_WIDTH - 10, 40, 0, 0},                                   /* nWay_maintimer_end */     
    {10, 40, 0, 0},                                               /* nWay_dialog_start */ 
    {LCD_WIDTH - 10, LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10, 0, 0}, /* nWay_dialog_end */ 
};

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) ) 

#define STPWACH_NW_SPAC_SIDE 0
#define STPWACH_NW_SPAC_TOP 0
#define STPWACH_NW_FRAM_BORDER   3

wtchSkinResStruct wtch_pos = 
{
    {(LCD_WIDTH >> 1) + 10, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 48, 0, 0},    /* wtch_coor_type typ_timer */ 
    {(LCD_WIDTH >> 1) + 100, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 48, 0, 0},    /* wtch_coor_type typ_milsec */
    {MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 82},                             /* typ_history_height, 4 line */ 

    {30},                                                   /* U16 separator_height */ 
    {10, 10, 0, 0},                                               /* nWay_maintimer_start */ 
    {LCD_WIDTH - 10, 40, 0, 0},                                   /* nWay_maintimer_end */     
    {10, 40, 0, 0},                                               /* nWay_dialog_start */ 
    {LCD_WIDTH - 10, LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10, 0, 0}, /* nWay_dialog_end */ 
};

#else 

#define STPWACH_NW_SPAC_SIDE 0
#define STPWACH_NW_SPAC_TOP 0
#define STPWACH_NW_FRAM_BORDER   3

wtchSkinResStruct wtch_pos = 
{
    {(LCD_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 61, 0, 0},    /* wtch_coor_type typ_timer */ 
    {(LCD_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 73, 0, 0},    /* wtch_coor_type typ_milsec */
    {(MMI_MENUITEM_HEIGHT << 2)},                           /* typ_history_height, 4 line */         

    {30},                                                   /* U16 separator_height */ 
    {10, 10, 0, 0},                                               /* nWay_maintimer_start */     
    {LCD_WIDTH - 10, 40, 0, 0},                                   /* nWay_maintimer_end */     
    {10, 40, 0, 0},                                               /* nWay_dialog_start */ 
    {LCD_WIDTH - 10, LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10, 0, 0}, /* nWay_dialog_end */ 
};

#endif 

/***************************************************************************** 
* Type Defination
*****************************************************************************/

typedef enum _SCREEN_NAME
{
    NOT_STOPWATCH_SCREEN = 0,
    MP_TIMER_SCR,
    TYPICAL_TIMER_SCR
} SCREEN_NAME;

SCREEN_NAME g_current_screen = NOT_STOPWATCH_SCREEN;

typedef enum _INCREMENT_TYPE
{
    NO_INCREMENT,
    TYP_TIMER_INCREMENT,
    MP_TITLE_TIME_INCREMENT,
    MP_LIST_TIMER_INCREMENT
} INCREMENT_TYPE;

INCREMENT_TYPE gDoNotIncrement;

/***************************************************************************** 
* External variable / function
*****************************************************************************/
extern S32 GUI_current_fixed_icontext_list_menuitem_column;
extern BOOL r2lMMIFlag;

extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);

extern void L1I_GetTime(Time *);
extern kal_uint32 L1I_GetTimeStamp(void);

/*****************************************************************************/
/***  N-way Stopwatch                                                      ***/
/*****************************************************************************/

/**********************************************************************************/
/*** nWay Stopwatch Screen                                                      ***/
/*** Screen ID: 306                                                             ***/
/**********************************************************************************/
/***                                                                            ***/
/***                                                                            ***/
/***   CategoryScreen306:                                                       ***/
/***                                                                            ***/
/***   ====================                                                     ***/
/***   =   00:14:56:07    =    <-- Main timer (title_time)                      ***/
/***   ====================                                                     ***/
/***   =    StopWatch     =    <-- Tile Bar, might be removed in 128 x 128 Scr  ***/
/***   ====================        (top_title_msg)                              ***/
/***   = A 00:01:12:33    =    <-- individual timer #1                          ***/
/***   = B 00:03:25:36    =    <-- individual timer #2                          ***/
/***   = C 00:02:56:11    =    <-- individual timer #3                          ***/
/***   = D 00:07:23:27    =    <-- individual timer #4  (list_watch[])          ***/
/***   ====================                                                     ***/
/***   == LSK ==||== RSK ==                                                     ***/
/***   ====================                                                     ***/
/***                                                                            ***/
/***                                                                            ***/
/**********************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* Timer Variable Declearation */
static UI_stop_watch title_time;                            /* Main Timer */
static UI_stop_watch list_watch[MAX_MULTIPURPOSE_TIMER];    /* Individual Timer */

/* String Variable Declaration */
static UI_string_type top_title_msg;    /* nWay stopwatch separate title bar ("StopWatch") */

/* Position Variable Declearation */
static U16 bkg_stop_watch_img = 0;          /* Background image, Reserved */
static U16 multi_stop_watch_title_img = 0;  /* Title image, Reserved */

static S32 category306_text_x_offset;   /* Active indivial timer text x coordinate */
static S32 category306_text_y_offset;   /* Active indivial timer text y coordinate */
static S32 category306_img_x_offset;    /* Active indivial timer image x coordinate */
static S32 category306_img_y_offset;    /* Active indivial timer image y coordinate */
static S32 category306_area_height;     /* Active indivial timer area height */
static S32 category306_img_width;       /* Active indivial timer image height */
static S32 category306_img_height;      /* Active indivial timer image height */
static S32 category306_text_width;      /* Active indivial timer text height */
static S32 category306_text_height;     /* Active indivial timer text height */

static S32 current_stop_watch_highlight = 0;    /* The current highligh timer idx */

/* Using in increement timer */
static DOUBLE gTypTimerLogMSecValue = 0;
static DOUBLE gMPTimerLogMSecValue = 0;

/***************************************************************************** 
* Local Function Defination
*****************************************************************************/
void update_stop_watch_time(void);
void display_stop_watch_list_content(S32, S32, S32, S32);
void clean_active_timer(void);
void display_stop_watch_list_header(S32, S32, S32, S32);
void draw_stopwatch_title(void);
void redraw_stop_watch_list(void);
static S32 category306_get_text_y_offset(S32 idx);
static S32 category306_get_img_y_offset(S32 idx);
static S32 category306_get_timer_text_width(S32 idx);


/*****************************************************************************
 * FUNCTION
 *  GetMultipurposeTimeValues
 * DESCRIPTION
 *  This function is to retrieve current active timer
 * PARAMETERS
 *  high_light      [OUT]     get highlight index 
 * RETURNS
 *  void
 *****************************************************************************/
void GetMultipurposeTimeValues(S32 *high_light)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *high_light = current_stop_watch_highlight;
}


/*****************************************************************************
 * FUNCTION
 *  stop_multipurpose_timers
 * DESCRIPTION
 *  This function is to retrieve current active timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void stop_multipurpose_timers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(update_stop_watch_time);
    stop_play_flag = TIMER_STOP;
}


/*****************************************************************************
 * FUNCTION
 *  start_multipurpose_list_watch
 * DESCRIPTION
 *  This function is to start certain individual timer
 * PARAMETERS
 *  index       [IN]        index of stop watch
 * RETURNS
 *  void
 *****************************************************************************/
void start_multipurpose_list_watch(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(update_stop_watch_time);
    if (stop_play_flag == TIMER_STOP)
    {
        gMPInitialTime = L1I_GetTimeStamp();

        stop_play_flag = TIMER_START;
    }
    else
    {
        update_stop_watch_time();
        gui_cancel_timer(update_stop_watch_time);
    }
    current_stop_watch_highlight = index;
    gui_start_timer(STPWACH_UI_UPDATE_PERIOD, update_stop_watch_time);

    gui_lock_double_buffer();

    gui_reset_clip();
    gui_reset_text_clip();

    category306_text_y_offset = category306_get_text_y_offset(current_stop_watch_highlight);
    category306_img_y_offset = category306_get_img_y_offset(current_stop_watch_highlight);

    draw_stopwatch_title();
    redraw_stop_watch_list();

    /* Draw Separator */
    display_stop_watch_list_header(
        wtch_pos.nWay_dialog_start.x,
        wtch_pos.nWay_dialog_start.y,
        wtch_pos.nWay_dialog_end.x,
        wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height);

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - MMI_button_bar_height);

}


/*****************************************************************************
 * FUNCTION
 *  set_stop_watch_history
 * DESCRIPTION
 *  This function is to set stopwatch history
 * PARAMETERS
 *  history_ID          [IN]        History ID
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
U8 set_stop_watch_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        UI_stop_watch_history *h = (UI_stop_watch_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            current_stop_watch_highlight = h->highlight_item;
            stop_play_flag = h->cur_stop_play_flag;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  get_stop_watch_history
 * DESCRIPTION
 *  This function is to get stopwatch history
 * PARAMETERS
 *  history_ID          [IN]         History ID
 *  history_buffer      [OUT]        History buffer to set
 * RETURNS
 *  void
 *****************************************************************************/
void get_stop_watch_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        UI_stop_watch_history *h = (UI_stop_watch_history*) history_buffer;

        h->history_ID = hID;
        h->cur_stop_play_flag = stop_play_flag;
        h->highlight_item = current_stop_watch_highlight;
    }
}


/*****************************************************************************
 * FUNCTION
 *  reset_all_multipurpose_time
 * DESCRIPTION
 *  This function is to reset all timer when long press LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_all_multipurpose_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(update_stop_watch_time);
    stop_play_flag = TIMER_STOP;

    /* Reset main timer */
    memset(&title_time, 0, sizeof(UI_stop_watch));

    /* Reset individual timer */
    for (index = 0; index < MAX_MULTIPURPOSE_TIMER; index++)
    {
        list_watch[index].hour = list_watch[index].mili_sec = list_watch[index].min = list_watch[index].sec = 0;
        memset(list_watch[index].watch_string, 0, 40);
    }

    current_stop_watch_highlight = 0;
    category306_text_y_offset = category306_get_text_y_offset(current_stop_watch_highlight);
    category306_img_y_offset = category306_get_img_y_offset(current_stop_watch_highlight);

    /* Update screen */
    gui_lock_double_buffer();

    change_stopwatchtime_to_string(
        title_time.mili_sec,
        title_time.hour,
        title_time.min,
        title_time.sec,
        title_time.watch_string,
        DISPLAY_MILISEC_TRUE);

    draw_stopwatch_title();
    redraw_stop_watch_list();

    /* Draw Separator */
    display_stop_watch_list_header(
        wtch_pos.nWay_dialog_start.x,
        wtch_pos.nWay_dialog_start.y,
        wtch_pos.nWay_dialog_end.x,
        wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height);

    gui_unlock_double_buffer();

    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - MMI_button_bar_height);
}


/*****************************************************************************
 * FUNCTION
 *  clean_active_timer
 * DESCRIPTION
 *  This function is to clear (drew white background on) active individual timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clean_active_timer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        gui_fill_rectangle(
            category306_text_x_offset + category306_text_width - category306_get_timer_text_width(current_stop_watch_highlight),
            category306_text_y_offset,
            category306_text_x_offset + category306_text_width,
            category306_text_y_offset + category306_text_height,
            UI_COLOR_WHITE);
    }
    else
    {
        gui_fill_rectangle(
            category306_text_x_offset,
            category306_text_y_offset,
            category306_text_x_offset + category306_get_timer_text_width(current_stop_watch_highlight),
            category306_text_y_offset + category306_text_height,
            UI_COLOR_WHITE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  redraw_stop_watch_list
 * DESCRIPTION
 *  This function is to redraw the individual timer list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_stop_watch_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    display_stop_watch_list_content(
        wtch_pos.nWay_dialog_start.x,
        wtch_pos.nWay_dialog_start.y,
        wtch_pos.nWay_dialog_end.x,
        wtch_pos.nWay_dialog_end.y);
}


/*****************************************************************************
 * FUNCTION
 *  display_stop_watch_list_content
 * DESCRIPTION
 *  This function is nWay stopwatch to drew individual timer
 * PARAMETERS
 *  x1      [IN]        start x
 *  y1      [IN]        start y
 *  x2      [IN]        end x
 *  y2      [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
void display_stop_watch_list_content(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S32 list_y = 0;
    S32 img_y = 0, text_y = 0;
    PU8 cur_image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_screen == MP_TIMER_SCR)
    {
        list_y = y1 + wtch_pos.separator_height;

        /* Draw nWay stopwatch content background */
        gui_fill_rectangle(x1, list_y, x2, y2, UI_COLOR_GREY);

        gui_fill_rectangle(
            x1 + STPWACH_NW_FRAM_BORDER,
            list_y + STPWACH_NW_FRAM_BORDER,
            x2 - STPWACH_NW_FRAM_BORDER,
            y2 - STPWACH_NW_FRAM_BORDER,
            UI_COLOR_WHITE);

        for (index = 0; index < MAX_MULTIPURPOSE_TIMER; index++)
        {
            img_y = category306_get_img_y_offset(index);
            text_y = category306_get_text_y_offset(index);

            if (index == current_stop_watch_highlight)
            {
                clean_active_timer();
                cur_image = (PU8) list_watch[index].highlightimagedata;
                gui_set_text_color(UI_COLOR_RED);

            }
            else
            {
                cur_image = (PU8) list_watch[index].normalimagedata;
                gui_set_text_color(UI_COLOR_BLACK);
            }

            /* Make timer string */
            change_stopwatchtime_to_string(
                list_watch[index].mili_sec,
                list_watch[index].hour,
                list_watch[index].min,
                list_watch[index].sec,
                list_watch[index].watch_string,
                DISPLAY_MILISEC_TRUE);

            /* Draw image */
            gui_show_image(category306_img_x_offset, img_y, cur_image);

            /* Draw text */
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(category306_text_x_offset + category306_text_width, text_y);
            }
            else
            {
                gui_move_text_cursor(category306_text_x_offset, text_y);
            }

            gui_print_text((UI_string_type) list_watch[index].watch_string);

        }   /* end of for loop */
    }

}


/*****************************************************************************
 * FUNCTION
 *  draw_stopwatch_title
 * DESCRIPTION
 *  This function is to draw main timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void draw_stopwatch_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_screen == MP_TIMER_SCR)
    {
        S32 maintimer_height;
        S32 title_x, title_y;

        maintimer_height =
            wtch_pos.nWay_maintimer_end.y - wtch_pos.nWay_maintimer_start.y - (STPWACH_NW_FRAM_BORDER << 1);

        gui_fill_rectangle(
            wtch_pos.nWay_maintimer_start.x,
            wtch_pos.nWay_maintimer_start.y,
            wtch_pos.nWay_maintimer_end.x,
            wtch_pos.nWay_maintimer_end.y,
            UI_COLOR_GREY);

        gui_fill_rectangle(
            wtch_pos.nWay_maintimer_start.x + STPWACH_NW_FRAM_BORDER,
            wtch_pos.nWay_maintimer_start.y + STPWACH_NW_FRAM_BORDER,
            wtch_pos.nWay_maintimer_end.x - STPWACH_NW_FRAM_BORDER,
            wtch_pos.nWay_maintimer_end.y - STPWACH_NW_FRAM_BORDER,
            UI_COLOR_WHITE);

        /* Main timer start x, y coordinate */
        title_x = wtch_pos.nWay_maintimer_start.x + STPWACH_NW_FRAM_BORDER
            + ((wtch_pos.nWay_maintimer_end.x - wtch_pos.nWay_maintimer_start.x - category306_text_width) >> 1);

        title_y = wtch_pos.nWay_maintimer_start.y + STPWACH_NW_FRAM_BORDER
            + ((maintimer_height >> 1) - (category306_text_height >> 1));

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(title_x + category306_text_width, title_y);
        }
        else
        {
            gui_move_text_cursor(title_x, title_y);
        }

        gui_set_text_color(UI_COLOR_BLACK);

        MMI_title_string = (UI_string_type) title_time.watch_string;
        gui_print_text((UI_string_type) MMI_title_string);
    }
}


/*****************************************************************************
 * FUNCTION
 *  display_stop_watch_list_header
 * DESCRIPTION
 *  This function is to draw separator
 * PARAMETERS
 *  x1      [IN]        start x
 *  y1      [IN]        start y
 *  x2      [IN]        end x 
 *  y2      [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
void display_stop_watch_list_header(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh = 0;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Don't drew separator */
    if (wtch_pos.separator_height == 0)
    {
        return;
    }

    if (g_current_screen == MP_TIMER_SCR)
    {
        /* Draw Separator window frame and background */
        gui_fill_rectangle(
            x1, 
            y1, 
            x2,
            y2, 
            UI_COLOR_DARK_GREY);
        gui_fill_rectangle(
            x1 + STPWACH_NW_FRAM_BORDER,
            y1 + STPWACH_NW_FRAM_BORDER,
            x2 - STPWACH_NW_FRAM_BORDER,
            y2 - STPWACH_NW_FRAM_BORDER,
            UI_COLOR_GREY);

        /* Config Text */
        gui_set_font(&MMI_medium_font);
        gui_set_text_color(UI_COLOR_BLACK);
        fh = gui_get_character_height();
        gui_measure_string(top_title_msg, &width, &height);

        /* Show Separator text */
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(
                x1 + STPWACH_NW_FRAM_BORDER + ((x2 - x1 - (2 * STPWACH_NW_FRAM_BORDER) - width) >> 1) + width,
                y1 + STPWACH_NW_FRAM_BORDER + ((y2 - y1 - (2 * STPWACH_NW_FRAM_BORDER) - height) >> 1));
        }
        else
        {
            gui_move_text_cursor(
                x1 + STPWACH_NW_FRAM_BORDER + ((x2 - x1 - (2 * STPWACH_NW_FRAM_BORDER) - width) >> 1),
                y1 + STPWACH_NW_FRAM_BORDER + ((y2 - y1 - (2 * STPWACH_NW_FRAM_BORDER) - height) >> 1));
        }

        gui_print_text(top_title_msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  increment_time_stopwatch
 * DESCRIPTION
 *  This function is to increase time different for certain timer record
 * PARAMETERS
 *  stop_watch      [IN/OUT]     stop watch struct
 * RETURNS
 *  void
 *****************************************************************************/
void increment_time_stopwatch(UI_stop_watch *stop_watch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    {
        U32 initTime = 0, currTime = 0;
        DOUBLE TotalTime;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        if (gDoNotIncrement == TYP_TIMER_INCREMENT || gDoNotIncrement == NO_INCREMENT)
        {
            initTime = gInitialTime;
            currTime = gCurrentTime;
        }
        else if (gDoNotIncrement == MP_TITLE_TIME_INCREMENT || gDoNotIncrement == MP_LIST_TIMER_INCREMENT)
        {
            initTime = gMPInitialTime;
            currTime = gMPCurrentTime;
        }

        if (initTime > currTime)
        {
            TotalTime = (0xffffffff - initTime) + currTime;
        }
        else
        {
            TotalTime = currTime - initTime;
        }

        TotalTime = TotalTime * 4.6153846;
        if (TotalTime >= 10)
        {
            stop_watch->mili_sec += (U32) TotalTime / 10;
            TotalTime = TotalTime - ((U32) TotalTime / 10) * 10;
        }
        if (TotalTime)
        {
            if (gDoNotIncrement == TYP_TIMER_INCREMENT)
            {
                gTypTimerLogMSecValue = gTypTimerLogMSecValue + TotalTime;
                if (gTypTimerLogMSecValue >= 10.0)
                {
                    stop_watch->mili_sec++;
                    gTypTimerLogMSecValue = gTypTimerLogMSecValue - 10.0;
                }
            }
            else if (gDoNotIncrement == MP_TITLE_TIME_INCREMENT || gDoNotIncrement == MP_LIST_TIMER_INCREMENT)
            {
                if (gDoNotIncrement == MP_TITLE_TIME_INCREMENT)
                {
                    gMPTimerLogMSecValue = gMPTimerLogMSecValue + TotalTime;
                }
                if (gMPTimerLogMSecValue >= 10.0)
                {
                    stop_watch->mili_sec++;
                    if (gDoNotIncrement == MP_LIST_TIMER_INCREMENT)
                    {
                        gMPTimerLogMSecValue = gMPTimerLogMSecValue - 10.0;
                    }
                }
            }
        }
    }

    if (stop_watch->mili_sec >= 100)
    {
        stop_watch->sec += stop_watch->mili_sec / 100;
        stop_watch->mili_sec -= (stop_watch->mili_sec / 100) * 100;
        if (stop_watch->sec >= 60)
        {
            stop_watch->min += stop_watch->sec / 60;
            stop_watch->sec -= (stop_watch->sec / 60) * 60;
            if (stop_watch->min >= 60)
            {
                stop_watch->hour += stop_watch->min / 60;
                stop_watch->min -= (stop_watch->min / 60) * 60;
                if (stop_watch->hour >= 100)
                {
                    stop_watch->hour = 0;
                }
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  UpdateMPTime
 * DESCRIPTION
 *  This function is to start timer to update stopwatch screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateMPTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stop_play_flag == TIMER_START)
    {
        gMPCurrentTime = L1I_GetTimeStamp();
        gDoNotIncrement = MP_TITLE_TIME_INCREMENT;

        increment_time_stopwatch(&title_time);

        gDoNotIncrement = MP_LIST_TIMER_INCREMENT;

        increment_time_stopwatch(&list_watch[current_stop_watch_highlight]);

        gMPInitialTime = gMPCurrentTime;

        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, update_stop_watch_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  update_stop_watch_time
 * DESCRIPTION
 *  This function UI update timeout handler (every STPWACH_UI_UPDATE_PERIOD )
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_stop_watch_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateMPTime();

    /* See the stopwatch is running in the background or not */
    if (g_current_screen == MP_TIMER_SCR)
    {
        gui_lock_double_buffer();

        clean_active_timer();

        /* update main timer string */
        change_stopwatchtime_to_string(
            title_time.mili_sec,
            title_time.hour,
            title_time.min,
            title_time.sec,
            title_time.watch_string,
            DISPLAY_MILISEC_TRUE);

        /* update active individual timer string */
        change_stopwatchtime_to_string(
            list_watch[current_stop_watch_highlight].mili_sec,
            list_watch[current_stop_watch_highlight].hour,
            list_watch[current_stop_watch_highlight].min,
            list_watch[current_stop_watch_highlight].sec,
            list_watch[current_stop_watch_highlight].watch_string,
            DISPLAY_MILISEC_TRUE);

        /* Draw main timer */
        draw_stopwatch_title();

        /* Draw Separator */
        display_stop_watch_list_header(
            wtch_pos.nWay_dialog_start.x,
            wtch_pos.nWay_dialog_start.y,
            wtch_pos.nWay_dialog_end.x,
            wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height);

        gui_set_font(&MMI_medium_font);
        gui_set_text_color(UI_COLOR_RED);

        /* Move cursor */
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(category306_text_x_offset + category306_text_width, category306_text_y_offset);
        }
        else
        {
            gui_move_text_cursor(category306_text_x_offset, category306_text_y_offset);
        }

        /* Draw timer text */
        gui_print_text((UI_string_type) list_watch[current_stop_watch_highlight].watch_string);

        gui_unlock_double_buffer();

        gui_BLT_double_buffer(
            wtch_pos.nWay_maintimer_start.x,
            wtch_pos.nWay_maintimer_start.y,
            wtch_pos.nWay_maintimer_end.x,
            wtch_pos.nWay_maintimer_end.y);

        gui_BLT_double_buffer(
            category306_text_x_offset,
            category306_text_y_offset,
            wtch_pos.nWay_dialog_end.x,
            category306_text_y_offset + category306_area_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory306Screen
 * DESCRIPTION
 *  This function is nWay stopwatch exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory306Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(update_stop_watch_time);
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    g_current_screen = NOT_STOPWATCH_SCREEN;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory306Screen
 * DESCRIPTION
 *  This function is to Display nWay stopwatch
 * PARAMETERS
 *  title_values            [IN]        Title string 
 *  title_img               [IN]        Title image
 *  title_side_msg          [IN]        Non-used
 *  left_softkey            [IN]        LSK string
 *  left_softkey_icon       [IN]        LSK icon
 *  right_softkey           [IN]        RSK string
 *  right_softkey_icon      [IN]        RSK icon
 *  number_of_items         [IN]        Number of stopwatch items
 *  stop_watch_list         [IN]        Stopwatch list
 *  bkgrd_image             [IN]        Background image ID
 *  title_text              [IN]        Top title string
 *  history_buffer          [IN]        History buffer
 *  highlight_item          [IN]        Default highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory306Screen(
        UI_stop_watch *title_values,
        U16 title_img,
        U16 title_side_msg,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        UI_stop_watch *stop_watch_list,
        U16 bkgrd_image,
        U16 title_text,
        U8 *history_buffer,
        S32 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;
    S32 img_width_1, img_height_1, img_width_2, img_height_2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_screen = MP_TIMER_SCR;
    UpdateMPTime();

    gui_lock_double_buffer();
    entry_full_screen();
    MMI_menu_shortcut_number = -1;
    clear_category_screen_key_handlers();

    gui_set_font(&MMI_medium_font);

    /* Side message (total), Reserved */
    bkg_stop_watch_img = bkgrd_image;
    multi_stop_watch_title_img = title_img;

    current_stop_watch_highlight = highlight_item;

    /* Make main timer string */
    change_stopwatchtime_to_string(
        title_time.mili_sec,
        title_time.hour,
        title_time.min,
        title_time.sec,
        title_time.watch_string,
        DISPLAY_MILISEC_TRUE);

    /* Full screen stopwatch, the screen title is main timer */
    MMI_title_string = (UI_string_type) title_time.watch_string;

    /* The separator title of main timer and individual timer ("Stopwatch") */
    top_title_msg = (UI_string_type) GetString(title_text);

    /* Store the icon ID in front of each individual timer */
    {
        U8 count = 0;

        for (count = 0; count < MAX_MULTIPURPOSE_TIMER; count++)
        {
            list_watch[count].normalimagedata = stop_watch_list[count].normalimagedata;
            list_watch[count].highlightimagedata = stop_watch_list[count].highlightimagedata;
        }
    }

    /* Store the screen information */
    gui_measure_image((PU8) list_watch[0].normalimagedata, &img_width_1, &img_height_1);
    gui_measure_image((PU8) list_watch[0].highlightimagedata, &img_width_2, &img_height_2);
    category306_text_width = gui_get_string_width((UI_string_type) MMI_title_string);
    category306_text_height = gui_get_character_height();

    ASSERT((img_width_1 == img_width_2) && (img_height_1 == img_height_2));

    category306_img_height = img_height_1;
    category306_img_width = img_width_1;

    /* Set key handler  */
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    clear_left_softkey();
    clear_right_softkey();

    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    h_flag = set_stop_watch_history(MMI_CATEGORY306_ID, history_buffer);

    gui_unlock_double_buffer();

    /* Register screen function pointer */
    ExitCategoryFunction = ExitCategory306Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY306_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  category306_get_text_y_offset
 * DESCRIPTION
 *  This function is to get active timer text y coordinator
 * PARAMETERS
 *  idx     [IN]        index of list
 * RETURNS
 *  void
 *****************************************************************************/
static S32 category306_get_text_y_offset(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height + STPWACH_NW_FRAM_BORDER)
        + (idx * category306_area_height) + (category306_area_height >> 1) - (category306_text_height >> 1);

}


/*****************************************************************************
 * FUNCTION
 *  category306_get_img_y_offset
 * DESCRIPTION
 *  This function is to get active timer imgage y coordinator
 * PARAMETERS
 *  idx     [IN]        index of list
 * RETURNS
 *  void
 *****************************************************************************/
static S32 category306_get_img_y_offset(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height + STPWACH_NW_FRAM_BORDER)
        + (idx * category306_area_height) + (category306_area_height >> 1) - (category306_img_height >> 1);

}


/*****************************************************************************
 * FUNCTION
 *  category306_get_timer_text_width
 * DESCRIPTION
 *  This function is to get active timer imgage y coordinator
 * PARAMETERS
 *  idx     [IN]        index of list
 * RETURNS
 *  void
 *****************************************************************************/
static S32 category306_get_timer_text_width(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_get_string_width((UI_string_type) list_watch[idx].watch_string);
}

/*****************************************************************************/
/***  Typical Stopwatch                                                    ***/
/*****************************************************************************/

/**********************************************************************************/
/*** Typical Stopwatch Screen                                                   ***/
/*** Screen ID: 307                                                             ***/
/**********************************************************************************/
/***                                                                            ***/
/***                                                                            ***/
/***   CategoryScreen307:                                                       ***/
/***                                                                            ***/
/***   ====================                                                     ***/
/***   = Split/Lap 1      =     <--   Split/Lap window, the number of items is  ***/
/***   = Split/Lap 2      =         depends on screen size. In 128x128 and 120  ***/
/***   = Split/Lap 3      =         x160, there are 2 itmes. In 176x220, there  ***/
/***   = ...              =         are 4 items. It is adjusting dynamically.   ***/
/***   ====================                                                     ***/
/***   =  xx xxxxxxxx xx  =                                                     ***/
/***   =  xxxxxxxxxxxxxx  =                                                     ***/
/***   =   x==========x   =                                                     ***/
/***   =   x 10:22:03 x   =     <--   Main window, with a background image and  ***/
/***   =   x    50    x   =          timer running on it. Because there is no   ***/
/***   =   x==========x   =          image cache mechanism implemented, suggest ***/
/***   =  xxxxxxxxxxxxxx  =          use plan color as background color.        ***/
/***   =  xx xxxxxxxx xx  =                                                     ***/
/***   ====================                                                     ***/
/***   == LSK ==||== RSK ==                                                     ***/
/***   ====================                                                     ***/
/***                                                                            ***/
/***                                                                            ***/
/**********************************************************************************/

#if defined (__MMI_MAINLCD_320X240__)
    #define TYP_TIME_FOUNT &wgui_dialer_box_f1
#elif defined (__MMI_MAINLCD_240X320__)
    #define TYP_TIME_FOUNT &MMI_large_font
#else 
    #define TYP_TIME_FOUNT &MMI_small_font
#endif 


S32 stop_watch_total_frames = 0, stop_watch_n_frame = 0;
U16 stop_watch_bkg_img = 0;
S32 stop_watch_x = 0, stop_watch_y = 0, stop_watch_width = 0, stop_watch_height = 0;
S32 center_mili = 0, center_sec = 0, center_hr = 0, center_min = 0;
S32 start_timer_again = -1;
U8 timer_flag_stop_start = 0;
U8 gResetTimer = 0;

extern S32 fixed_icontext_list_menuitem_total(void);
void stop_watch_animation_processor(void);
void show_center_time(void);

U8 stop_watch_values_data[MAX_TIMER_RECORDS][40];

extern U8 category89_string_list[MAX_CATEGORY89_STRINGS][MAX_CATEGORY89_STRING_LENGTH];


/*****************************************************************************
 * FUNCTION
 *  reset_timer
 * DESCRIPTION
 *  reset timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(show_center_time);
    memset(stop_watch_values_data, 0, sizeof(stop_watch_values_data));
    memset(category89_string_list, 0, (MAX_CATEGORY89_STRINGS * MAX_CATEGORY89_STRING_LENGTH));
    timer_flag_stop_start = TIMER_STOP;
    center_mili = center_sec = center_hr = center_min = 0;

    remove_all_fixed_icontext_item();
    MMI_fixed_list_menu.highlighted_item = -1;
    show_fixed_list();
    gResetTimer = 1;
    show_center_time();

    if (stop_watch_total_frames > 1)
    {
        stop_watch_n_frame = -1;
        stop_watch_animation_processor();
    }

    /* Gurinder - 28/4/2004 - Stop Scroll Timer On List Reset. */
    wgui_text_menuitem_reset_scrolling();
}


/*****************************************************************************
 * FUNCTION
 *  initialize_stop_watch_timer
 * DESCRIPTION
 *  Initialize timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_stop_watch_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(stop_watch_animation_processor);
    gui_cancel_timer(show_center_time);
    timer_flag_stop_start = TIMER_STOP;
    center_mili = center_sec = center_hr = center_min = 0;

    if (stop_watch_total_frames > 1)
    {
        stop_watch_n_frame = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UpdateHistoryValue
 * DESCRIPTION
 *  update history value
 * PARAMETERS
 *  mili        [IN]     mile second
 *  hr          [IN]     hour
 *  min         [IN]     minute
 *  sec         [IN]     second
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateHistoryValue(S32 *mili, S32 *hr, S32 *min, S32 *sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total = 0, index = 0;
    U32 TempPrevCurrentValue = 0;
    UI_stop_watch temp_watch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_watch.hour = center_hr;
    temp_watch.mili_sec = center_mili;
    temp_watch.min = center_min;
    temp_watch.sec = center_sec;

    TempPrevCurrentValue = gCurrentTime;
    gCurrentTime = L1I_GetTimeStamp();
    gDoNotIncrement = NO_INCREMENT;

    increment_time_stopwatch(&temp_watch);

    gCurrentTime = TempPrevCurrentValue;

    *mili = temp_watch.mili_sec;
    *hr = temp_watch.hour;
    *min = temp_watch.min;
    *sec = temp_watch.sec;

    if (start_timer_again == STOP_START_AGAIN)
    {
        center_mili = center_hr = center_min = center_sec = 0;
        gResetTimer = 1;
        gInitialTime = L1I_GetTimeStamp();
    }

    if (g_current_screen == TYPICAL_TIMER_SCR)
    {
        MMI_menu_shortcut_number = -1;

        total = fixed_icontext_list_menuitem_total();

        if (total > 0)
        {
            index = total;
        }
        else
        {
            index = 0;
        }

        fixed_icontext_list_item_insert(index);
        gui_itoa(total + 1, (UI_string_type) category89_string_list[index], 10);
        gui_strcat((UI_string_type) category89_string_list[index], (UI_string_type) ".\0");
        add_fixed_icontext_list_item_text(index, 0, (UI_string_type) category89_string_list[index]);

        change_stopwatchtime_to_string(*mili, *hr, *min, *sec, stop_watch_values_data[index], DISPLAY_MILISEC_TRUE);
        add_fixed_icontext_list_item_text(index, 1, (UI_string_type) stop_watch_values_data[index]);

        if (index == 0)
        {
            fixed_list_goto_item_no_redraw(index);
        }
        else
        {
            fixed_list_goto_item(index);
        }

        show_fixed_list();
        gui_BLT_double_buffer(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);

    }
}


/*****************************************************************************
 * FUNCTION
 *  start_stop_watch_timer
 * DESCRIPTION
 *  start stop watch timer
 * PARAMETERS
 *  start_stop_flag     [IN]        stop or stop timer
 * RETURNS
 *  void
 *****************************************************************************/
void start_stop_watch_timer(U8 start_stop_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_stop_flag == TIMER_STOP)
    {
        gui_cancel_timer(show_center_time);
        if (timer_flag_stop_start == TIMER_START)
        {
            show_center_time();
        }
    }
    else if (start_stop_flag == TIMER_START)
    {
        gInitialTime = L1I_GetTimeStamp();
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);

        if (stop_watch_total_frames > 1)
        {
            gui_start_timer(STOP_WATCH_ANIMATION_DELAY, stop_watch_animation_processor);
        }

    }
    timer_flag_stop_start = start_stop_flag;
}

U8 gMainTimeUpdatedFlag = 0;


/*****************************************************************************
 * FUNCTION
 *  UpdateTypicalTimer
 * DESCRIPTION
 *  update typical timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateTypicalTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_stop_watch temp_watch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (timer_flag_stop_start == TIMER_START)
    {
        temp_watch.hour = center_hr;
        temp_watch.mili_sec = center_mili;
        temp_watch.min = center_min;
        temp_watch.sec = center_sec;

        gCurrentTime = L1I_GetTimeStamp();
        gDoNotIncrement = TYP_TIMER_INCREMENT;
        increment_time_stopwatch(&temp_watch);
        gInitialTime = gCurrentTime;

        if ((center_hr == temp_watch.hour) && (center_min == temp_watch.min) && (center_sec == temp_watch.sec))
        {
            gMainTimeUpdatedFlag = 0;
        }
        else
        {
            gMainTimeUpdatedFlag = 1;
        }

        center_hr = temp_watch.hour;
        center_mili = temp_watch.mili_sec;
        center_min = temp_watch.min;
        center_sec = temp_watch.sec;
    }
}


/*****************************************************************************
 * FUNCTION
 *  print_center_time
 * DESCRIPTION
 *  draw center time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void print_center_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 time_string[40];
    U8 mili_string[20], uni_mili_string[40];
    color text_col = gui_color(0, 0, 0);
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateTypicalTimer();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_set_font(TYP_TIME_FOUNT);

    change_stopwatchtime_to_string(0, center_hr, center_min, center_sec, time_string, DISPLAY_MILISEC_FALSE);

    sprintf((S8*) mili_string, "%02d", center_mili);
    mmi_asc_to_ucs2((PS8) uni_mili_string, (PS8) mili_string);

    gui_measure_string((UI_string_type) time_string, &w, &h);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(wtch_pos.typ_timer.x + w, wtch_pos.typ_timer.y);
    }
    else
    {
        gui_move_text_cursor(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y);
    }

    gui_set_text_color(text_col);
    gui_print_text((UI_string_type) time_string);

    gui_measure_string((UI_string_type) uni_mili_string, &w, &h);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(wtch_pos.typ_milsec.x + w, wtch_pos.typ_milsec.y);
    }
    else
    {
        gui_move_text_cursor(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y);
    }

    gui_print_text((UI_string_type) uni_mili_string);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif 

}

bitmap gdata_maintimer;
bitmap gdata_millitimer;

#if (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_24)
#if defined (__MMI_MAINLCD_320X240__)
U8 gbuffer_millitime[2592];
U8 gbuffer_maintime[13068];
#elif defined (__MMI_MAINLCD_240X320__)
U8 gbuffer_millitime[1725];
U8 gbuffer_maintime[5520];
#else /* defined (__MMI_MAINLCD_240X320__) */ 
U8 gbuffer_millitime[900 /* 550 */ ];   /* 32(row bytes) * 16 (y offset) = 512 */
U8 gbuffer_maintime[1800 /* 1100 */ ];  /* 102(row bytes) * 11(y offset) = 1122 */
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
#else
#if defined (__MMI_MAINLCD_320X240__)
U8 gbuffer_millitime[1728];
U8 gbuffer_maintime[6912];
#elif defined (__MMI_MAINLCD_240X320__)
U8 gbuffer_millitime[1150];
U8 gbuffer_maintime[3680];
#else /* defined (__MMI_MAINLCD_240X320__) */ 
U8 gbuffer_millitime[600];   /* 32(row bytes) * 16 (y offset) = 512 */
U8 gbuffer_maintime[1200];  /* 102(row bytes) * 11(y offset) = 1122 */
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
#endif /* defined (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_24) */

extern void reset_fixed_list_show_empty(void);
extern void disable_fixed_list_show_empty(void);

/*****************************************************************************
 * FUNCTION
 *  show_center_time
 * DESCRIPTION
 *  show center time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_center_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w;
    U8 time_string[40];
    U8 mili_string[20], uni_mili_string[40];
    color text_col = gui_color(0, 0, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateTypicalTimer();
    if (g_current_screen == TYPICAL_TIMER_SCR)
    {
        gui_lock_double_buffer();
        gui_reset_clip();
        gui_reset_text_clip();

        gui_set_font(TYP_TIME_FOUNT);

        gui_set_text_color(text_col);
		
        if (stop_watch_total_frames > 1)
        {
            _show_bitmap(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y, &gdata_maintimer);
            _show_bitmap(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y, &gdata_millitimer);
            print_center_time();
        }
        else
        {
            if ((gMainTimeUpdatedFlag == 1) || (gResetTimer))
            {
                change_stopwatchtime_to_string(
                    0,
                    center_hr,
                    center_min,
                    center_sec,
                    time_string,
                    DISPLAY_MILISEC_FALSE);
                sprintf((S8*) mili_string, "%02d", center_mili);
                mmi_asc_to_ucs2((PS8) uni_mili_string, (PS8) mili_string);
                _show_bitmap(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y, &gdata_maintimer);

                w = gui_get_string_width((UI_string_type) time_string);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(wtch_pos.typ_timer.x + w, wtch_pos.typ_timer.y);
                }
                else
                {
                    gui_move_text_cursor(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y);
                }

                gui_print_text((UI_string_type) time_string);

                _show_bitmap(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y, &gdata_millitimer);

                w = gui_get_string_width((UI_string_type) uni_mili_string);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(wtch_pos.typ_milsec.x + w, wtch_pos.typ_milsec.y);
                }
                else
                {
                    gui_move_text_cursor(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y);
                }

                gui_print_text((UI_string_type) uni_mili_string);
                gResetTimer = 0;
            }
            else
            {
                sprintf((S8*) mili_string, "%02d", center_mili);
                mmi_asc_to_ucs2((PS8) uni_mili_string, (PS8) mili_string);
                _show_bitmap(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y, &gdata_millitimer);

                w = gui_get_string_width((UI_string_type) uni_mili_string);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(wtch_pos.typ_milsec.x + w, wtch_pos.typ_milsec.y);
                }
                else
                {
                    gui_move_text_cursor(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y);
                }

                gui_print_text((UI_string_type) uni_mili_string);
            }
        }

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            0,
            (wtch_pos.typ_history_height + 2),
            UI_device_width - 1,
            (UI_device_height - MMI_button_bar_height));
    }

    if (timer_flag_stop_start == TIMER_START)
    {
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);
    }
}

#if defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__)
MMI_ID_TYPE stopwatch_scr_bg_ID;
S8 *stopwatch_scr_bg_filename;
S32 stopwatch_scr_bg_x, stopwatch_scr_bg_y;
U8 stopwatch_scr_bg_opacity; 
#endif /* defined (__MMI_MAINLCD_240X320__) */ 

extern void dm_set_scr_bg_image_no_draw(U16 image_id, S8 *file_name, S32 x, S32 y, U8 opacity);        /* 092005 grayscale Calvin */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory307Screen
 * DESCRIPTION
 *  Exit category 307
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory307Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(show_center_time);

    gui_cancel_timer(stop_watch_animation_processor);

    ClearHighlightHandler();
    reset_softkeys();

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    g_current_screen = NOT_STOPWATCH_SCREEN;
    wgui_text_menuitem_reset_scrolling();
}


/*****************************************************************************
 * FUNCTION
 *  stop_watch_animation_processor
 * DESCRIPTION
 *  Draw Animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void stop_watch_animation_processor()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    PU8 stop_watch_img = get_image(stop_watch_bkg_img);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stop_watch_n_frame++;
    if (stop_watch_n_frame >= stop_watch_total_frames)
    {
        stop_watch_n_frame = 0;
    }

    gui_cancel_timer(stop_watch_animation_processor);
    gui_cancel_timer(show_center_time);

    gui_lock_double_buffer();

    gui_reset_clip();
    gui_reset_text_clip();

    gui_set_clip(0, wtch_pos.typ_history_height + 2, UI_device_width - 1, UI_device_height - MMI_button_bar_height - 1);
    gui_draw_filled_area(
        0,
        wtch_pos.typ_history_height + 2,
        UI_device_width - 1,
        UI_device_height - 1,
        current_MMI_theme->general_background_filler);

    for (i = 0; i <= stop_watch_n_frame; i++)
    {
        gdi_image_draw_animation_single_frame(stop_watch_x, stop_watch_y, stop_watch_img, (S16) i);
    }

   /***********************************************************/
    /* Notices!!!                                              */
    /* Change the X,Y offset should change the buffer size of  */
    /* gbuffer_millitime[] and gbuffer_maintime[] as well      */
   /***********************************************************/
    memset(gbuffer_maintime, 0, sizeof(gbuffer_maintime));
    gdata_maintimer.data = gbuffer_maintime;
    _get_bitmap(
        wtch_pos.typ_timer.x,
        wtch_pos.typ_timer.y,
        (wtch_pos.typ_timer.x + wtch_pos.typ_timer.width - 1),
        (wtch_pos.typ_timer.y + wtch_pos.typ_timer.height - 1),
        &gdata_maintimer);

   /***********************************************************/
    /* Notices!!!                                              */
    /* Change the X,Y offset should change the buffer size of  */
    /* gbuffer_millitime[] and gbuffer_maintime[] as well      */
   /***********************************************************/
    memset(gbuffer_millitime, 0, sizeof(gbuffer_millitime));
    gdata_millitimer.data = gbuffer_millitime;
    _get_bitmap(
        wtch_pos.typ_milsec.x,
        wtch_pos.typ_milsec.y,
        (wtch_pos.typ_milsec.x + wtch_pos.typ_milsec.width - 1),
        (wtch_pos.typ_milsec.y + wtch_pos.typ_milsec.height - 1),
        &gdata_millitimer);

    print_center_time();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, (UI_device_height - MMI_button_bar_height));
    gui_start_timer(STOP_WATCH_ANIMATION_DELAY, stop_watch_animation_processor);

    if (timer_flag_stop_start == TIMER_START)
    {
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory307Screen
 * DESCRIPTION
 *  Redraws the Idle screen
 * PARAMETERS
 *  left_softkey            [IN]        LSK string
 *  left_softkey_icon       [IN]        LSK icon
 *  right_softkey           [IN]        RSK string
 *  right_softkey_icon      [IN]        RSK icon
 *  number_of_items         [IN]        Number of items
 *  list_watch              [IN]        watch list
 *  highlighted_item        [IN]        highlighted item
 *  history_buffer          [IN]        history buffer
 *  bkg_image               [IN]        background image ID
 *  start_continue_flag     [IN]        start continue flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory307Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        UI_stop_watch *list_watch,
        S32 highlighted_item,
        U8 *history_buffer,
        U16 bkg_image,
        S32 start_continue_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 i;
    U8 h_flag;
    PU8 img_bkg_stop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_screen = TYPICAL_TIMER_SCR;

    gui_lock_double_buffer();

    start_timer_again = start_continue_flag;

    MMI_menu_shortcut_number = -1;
    clear_category_screen_key_handlers();
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

#if !(defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__))
    entry_full_screen();
#endif 

    create_fixed_icontext_list_menuitems(2, 0);
    MMI_current_menu_type = LIST_MENU;
    GUI_current_fixed_icontext_list_menuitem_column = 1;

    resize_fixed_list(MMI_content_width, wtch_pos.typ_history_height + 2);

    set_fixed_icontext_list_text_coordinates(0, 1, 0, 30, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(
        1,
        30,
        0,
        UI_device_width - 30 - 4 - MMI_fixed_list_menu.vbar.width,
        MMI_MENUITEM_HEIGHT);
    associate_fixed_icontext_list_list();
    for (i = 0; i < number_of_items; i++)
    {
        fixed_icontext_list_item_insert(i);
        gui_itoa(i + 1, (UI_string_type) category89_string_list[i], 10);
        gui_strcat((UI_string_type) category89_string_list[i], (UI_string_type) ".\0");
        add_fixed_icontext_list_item_text(i, 0, (UI_string_type) category89_string_list[i]);
        change_stopwatchtime_to_string(
            list_watch[i].mili_sec,
            list_watch[i].hour,
            list_watch[i].min,
            list_watch[i].sec,
            list_watch[i].watch_string,
            DISPLAY_MILISEC_TRUE);
        add_fixed_icontext_list_item_text(i, 1, (UI_string_type) list_watch[i].watch_string);
    }

    register_fixed_list_keys();
    resize_fixed_icontext_list_menuitems(0, MMI_menuitem_height);
    set_fixed_icontext_positions(0, 0, 1, 0);
    register_fixed_list_highlight_handler(standard_stop_watch_list_highlight_handler);
    MMI_current_menu_type = LIST_MENU;

    h_flag = set_list_menu_category_history(MMI_CATEGORY307_ID, history_buffer);
    if (h_flag)
    {
        fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    }
    else
    {
        fixed_list_goto_item_no_redraw(highlighted_item);
    }
    MMI_title_string = 0;
    MMI_title_icon = 0;

    stop_watch_bkg_img = bkg_image;
    img_bkg_stop = (PU8) GetImage(bkg_image);
    gui_measure_image(img_bkg_stop, &stop_watch_width, &stop_watch_height);
    stop_watch_total_frames = gui_image_n_frames(img_bkg_stop);

    gui_unlock_double_buffer();

    /* Not to execute LSK function when pen down on list menuitem */
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif 

    ExitCategoryFunction = ExitCategory307Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY307_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_stopwatch_translate_penevent
 * DESCRIPTION
 *  Finds the index of Stopwatch Timer
 * PARAMETERS
 *  x           [IN]        Pen's x position
 *  y           [IN]        Pen's y position
 *  index       [?]         Index of Timer
 * RETURNS
 *  MMI_BOOL True/False
 *****************************************************************************/
MMI_BOOL gui_stopwatch_translate_penevent(S32 x, S32 y, S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_screen == MP_TIMER_SCR)
    {
        S32 y1, y2, i;
        S32 img_y, text_y;

        for (i = 0; i < MAX_MULTIPURPOSE_TIMER; i++)
        {
            img_y = category306_get_img_y_offset(i);
            text_y = category306_get_text_y_offset(i);
            y1 = (img_y < text_y) ? img_y : text_y;
            y2 = (y1 + category306_text_height >
                  y1 + category306_img_height) ? (y1 + category306_text_height) : (y1 + category306_img_height);
            if (y >= y1 && y <= y2)
            {
                *index = i;
                ret = MMI_TRUE;
                break;
            }
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_stopwatch_pen_down_hdlr
 * DESCRIPTION
 *  Handles Pen Down Event on Stopwatch
 * PARAMETERS
 *  point       [IN]        Pen's position
 *  index       [OUT]       Index of Timer
 * RETURNS
 *  MMI_BOOL True/False
 *****************************************************************************/
MMI_BOOL wgui_stopwatch_pen_down_hdlr(mmi_pen_point_struct point, S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    S32 posx = point.x, posy = point.y;
    S32 img_y, text_y;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_screen == NOT_STOPWATCH_SCREEN)
    {
        return ret;
    }
    if (g_current_screen == MP_TIMER_SCR)
    {
        img_y = category306_get_img_y_offset(0);
        text_y = category306_get_text_y_offset(0);
        x1 = category306_img_x_offset;
        y1 = (img_y < text_y) ? img_y : text_y;
        if (y1 < wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height + STPWACH_NW_FRAM_BORDER)
        {
            y1 = wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height + STPWACH_NW_FRAM_BORDER;
        }
        x2 = category306_text_x_offset + category306_text_width;
        img_y = category306_get_img_y_offset(MAX_MULTIPURPOSE_TIMER - 1);
        text_y = category306_get_text_y_offset(MAX_MULTIPURPOSE_TIMER - 1);
        y2 = (img_y + category306_img_height) >
            (text_y + category306_text_height) ? (img_y + category306_img_height) : (text_y + category306_text_height);
        if (y2 > wtch_pos.nWay_dialog_end.y - STPWACH_NW_FRAM_BORDER)
        {
            y2 = wtch_pos.nWay_dialog_end.y - STPWACH_NW_FRAM_BORDER;
        }
    }
    if (posx >= x1 && posx <= x2 && posy >= y1 && posy <= y2)
    {
        ret = gui_stopwatch_translate_penevent(point.x, point.y, index);
    }
    return ret;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

/*****************************************************************************/
/***  Utility Function                                                     ***/
/*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  change_stopwatchtime_to_string
 * DESCRIPTION
 *  This function is to make stopwatch timer value to string
 * PARAMETERS
 *  milisec                     [IN]        mile second
 *  hour                        [IN]        hour
 *  min                         [IN]        minute
 *  sec                         [IN]        second
 *  str_val                     [IN]        string buffer
 *  display_milisec_flag        [IN]        If display mile second
 * RETURNS
 *  void
 *****************************************************************************/
void change_stopwatchtime_to_string(S32 milisec, S32 hour, S32 min, S32 sec, U8 *str_val, U8 display_milisec_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_str[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (display_milisec_flag)
    {
        sprintf((S8*) temp_str, "%02d:%02d:%02d:%02d", hour, min, sec, milisec);
    }
    else
    {
        sprintf((S8*) temp_str, "%02d:%02d:%02d", hour, min, sec);
    }

    mmi_asc_to_ucs2((PS8) str_val, (PS8) temp_str);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  show_typical_stop_watch
 * DESCRIPTION
 *  show typical stop watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_typical_stop_watch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 time_string[40];
    U8 mili_string[20], uni_mili_string[40];
    S32 width, height;

    PU8 stop_watch_img = (PU8) GetImage(stop_watch_bkg_img);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(stop_watch_animation_processor);
    gui_cancel_timer(show_center_time);

    gui_reset_clip();
    gui_reset_text_clip();

    gui_set_clip(0, MMI_status_bar_height, UI_device_width - 1, UI_device_height - MMI_button_bar_height);
    gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->general_background_filler);

    if (stop_watch_total_frames > 1)
    {
        gui_show_animated_image_frame(stop_watch_x, stop_watch_y, stop_watch_img, (S16) stop_watch_n_frame);
    }
    else
    {
        gui_show_image(stop_watch_x, stop_watch_y, stop_watch_img);
    }

   /***********************************************************/
    /* Notices!!!                                              */
    /* Change the X,Y offset should change the buffer size of  */
    /* gbuffer_millitime[] and gbuffer_maintime[] as well      */
   /***********************************************************/
    memset(gbuffer_maintime, 0, sizeof(gbuffer_maintime));
    gdata_maintimer.data = gbuffer_maintime;
    change_stopwatchtime_to_string(0, center_hr, center_min, center_sec, time_string, DISPLAY_MILISEC_FALSE);
    sprintf((S8*) mili_string, "%02d", center_mili);
    mmi_asc_to_ucs2((PS8) uni_mili_string, (PS8) mili_string);

    /* time position */
    gui_set_font(TYP_TIME_FOUNT);

    gui_measure_string((UI_string_type) time_string, &width, &height);
    wtch_pos.typ_timer.height = height;
#if 0
    //Huyanwei Modify it 
    wtch_pos.typ_timer.width = width;
#else
    wtch_pos.typ_timer.width = width+3;
#endif
    wtch_pos.typ_timer.x -= (wtch_pos.typ_timer.width >> 1);
    _get_bitmap(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y, (wtch_pos.typ_timer.x + wtch_pos.typ_timer.width - 1), (wtch_pos.typ_timer.y + wtch_pos.typ_timer.height - 1), &gdata_maintimer); 

   /***********************************************************/
    /* Notices!!!                                              */
    /* Change the X,Y offset should change the buffer size of  */
    /* gbuffer_millitime[] and gbuffer_maintime[] as well      */
   /***********************************************************/
    memset(gbuffer_millitime, 0, sizeof(gbuffer_millitime));
    gdata_millitimer.data = gbuffer_millitime;
    gui_measure_string((UI_string_type) uni_mili_string, &width, &height);
    wtch_pos.typ_milsec.height = height;
#if 0	
    wtch_pos.typ_milsec.width = width;
#else
    wtch_pos.typ_milsec.width = width+3;
#endif
    wtch_pos.typ_milsec.x -= (wtch_pos.typ_milsec.width >> 1);
    _get_bitmap(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y, (wtch_pos.typ_milsec.x + wtch_pos.typ_milsec.width - 1), (wtch_pos.typ_milsec.y + wtch_pos.typ_milsec.height - 1), &gdata_millitimer);

    print_center_time();

    show_fixed_list();

    if (stop_watch_total_frames > 1)
    {
        gui_start_timer(STOP_WATCH_ANIMATION_DELAY, stop_watch_animation_processor);
    }

    if (timer_flag_stop_start == TIMER_START)
    {
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);
    }

}


/*****************************************************************************
 * FUNCTION
 *  show_nway_stop_watch
 * DESCRIPTION
 *  redraw nway stop watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_nway_stop_watch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    gui_reset_text_clip();

    /* Reassign y coordinate according to current highlight timer */
    category306_area_height =
        ((wtch_pos.nWay_dialog_end.y - wtch_pos.nWay_dialog_start.y -
          wtch_pos.separator_height) / MAX_MULTIPURPOSE_TIMER);

    /* Text start position */
    category306_text_y_offset = category306_get_text_y_offset(current_stop_watch_highlight);
    category306_text_x_offset = wtch_pos.nWay_dialog_start.x + STPWACH_NW_FRAM_BORDER
        +
        ((wtch_pos.nWay_dialog_end.x - wtch_pos.nWay_dialog_start.x - category306_img_width - category306_text_width -
          (STPWACH_NW_FRAM_BORDER << 1)) >> 1) + category306_img_width + STPWACH_NW_FRAM_BORDER * 2;

    category306_img_x_offset = category306_text_x_offset - category306_img_width - STPWACH_NW_FRAM_BORDER * 2;
    category306_img_y_offset = category306_get_img_y_offset(current_stop_watch_highlight);

    /* Draw main timer */
    draw_stopwatch_title();

    /* Draw individual timer */
    redraw_stop_watch_list();

    /* Draw Separator */
    display_stop_watch_list_header(
        wtch_pos.nWay_dialog_start.x,
        wtch_pos.nWay_dialog_start.y,
        wtch_pos.nWay_dialog_end.x,
        wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height);

}

#endif /* __MMI_STOPWATCH__ */ 

