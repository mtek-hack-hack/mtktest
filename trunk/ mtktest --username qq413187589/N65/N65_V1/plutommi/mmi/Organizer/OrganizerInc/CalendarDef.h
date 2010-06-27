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

/*******************************************************************************
 * Filename:
 * ---------
 *  CalendarDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : CalendarDef.h

   PURPOSE     : 

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : 

**************************************************************/

#ifndef _CALDEF_H
#define _CALDEF_H

#include "MMIDataType.h"
/******************************************************************/
#include "wgui_categories_calendar.h"
#include "gui_calendar.h"

#include "MMI_features.h"
#include "CalendarResDef.h"

#ifdef __MMI_CALENDAR_V2__
#define CLNDR_HORIZON_LIST_CELL_LEN  (4)
#define CLNDR_VERTICAL_LIST_CELL_LEN  (6)
#define CLNDR_VERTICAL_SELECT_LEN (5 * ENCODING_LENGTH)

#define CLNDR_MAX_ROW 24
#define DLNDR_MAX_DAY_HOURS 24

#define CLNDR_COLUMN 7
#define CLNDR_ROW 6

#define CLNDR_START_WEEKDAY 0
#define CLNDR_TOTAL_WEEKDAY 7

#define CLNDR_WEEK_SYMBOL_LEN 1

#define CLNDR_CELL_SIZE sizeof(gui_calendar_cell_struct)
#define CLNDR_MAX_BUFF_SIZE ((CLNDR_TITLE_LEN  * CLNDR_COLUMN + CLNDR_HORIZON_LIST_CELL_LEN * CLNDR_COLUMN + CLNDR_VERTICAL_LIST_CELL_LEN * CLNDR_COLUMN)  * ENCODING_LENGTH +  CLNDR_MAX_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE)

#define CLNDR_MONTHLY_VIEW 1
#define CLNDR_WEEKLY_VIEW 2

#define CLNDR_REMINDER_TASK_AMOUNT  2
#define CLNDR_IDLE_TASK_AMOUNT  2

#define CLNDR_INFO_BOX_ROW 2
#define CLNDR_MAX_INFO_BOX_LEN (MAX_TODO_NOTE_LEN * ENCODING_LENGTH)

#define  CLNDR_START_YEAR     1970      /* the frist year in the database table */
#define  CLNDR_MONTH_DAYS   31
#define  CLNDR_END_YEAR         2030    /* the frist year in the database table */

#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
#define CLNDR_LARGER_THAN_MAX_YEAR  1
#define CLNDR_LARGER_THAN_MIN_YEAR  2


#define CLNDR_WEEKLY_PERIOD_INTERVAL 2
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 

#endif /* __MMI_CALENDAR_V2__ */ 

#define  CLNDR_DAY_LEN           3*ENCODING_LENGTH
#define  CLNDR_MON_LEN           3*ENCODING_LENGTH
#define  CLNDR_YEAR_LEN          6*ENCODING_LENGTH

#define  CLNDR_TABLE_START_YEAR     1969        /* the frist year in the database table */
#define  CLNDR_TABLE_END_YEAR       2031        /* the last year in the database table */
#define  CLNDR_TIME_PER_YEAR        31556926
/* indication codes */
#define CLNDR_BASE 1939

#define CLNDR_TIME_STRING_LENGTH (5)    /* HH:MM */
#define CLNDR_DATE_STRING_LENGTH (10)   /* YYYY/MM/DD */

#ifdef __MMI_BPP_SUPPORT__
#define T_SIZE (((MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT) * MAIN_LCD_DEVICE_WIDTH * GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#endif
/*
 * Typedef 
 */

/* struct clndr_lnuar_date_info_struct defines all data needed for lunar calendar */
typedef struct
{
    U8 BaseDays;    /* different days from solar Jan 1 to lunar Jan 1. */
    U8 BaseWeekday; /* week day of Jan 1 this year. 0=Sunday */
    U8 BaseKanChi;  /* the Kan and Chin of Jan 1 this year. */
    S8 Intercalary;     /* an intercalary month in the lunar calendar.                    
                           0==no intercalary month in this year. */
    U16 MonthDays;  /* the number of days in lunar month, bit-level representation 0=29, 1=30. */
} clndr_lunar_table_struct;

/* struct DateInfo defines all data/result for calendar converting */
typedef struct
{
    U16 SolarYear;                      /* year in solar calendar system. */
    U16 LunarYear;                      /* year in lunar calendar system. */
    U8 SolarMonth;                      /* month in solar calendar system. */
    U8 SolarDay;                        /* day in solar calendar system. */
    U8 LunarMonth;                      /* month in lunar calendar system. */
    U8 LunarDay;                        /* day in lunar calendar system. */
    U8 KanYear;                         /* the Kan symbol of given year */
    U8 ChiYear;                         /* the Chin symbol of given year */
    U8 Direction;                       /* the unfortunate direction of selecting day */
    U8 Age;                             /* the unfortunate age of selecting day */
    U8 Animal;                          /* the unfortunate symbolizing animal today */
    U8 SolarTerm;                       /* solar term today, 25 == NONE */
    U8 SolarDate;                       /* the nearest solar date from today */
    U8 YearAnimal;                      /* the symbolizing animal of this year */
    S8 TitleInfo1[CLNDR_TITLE_LEN];     /* the string shown in the first line of title */
    S8 TitleInfo2[CLNDR_TITLE_LEN];     /* the string shown in the second line of title */
    S8 MessageLine1[CLNDR_HINT_LEN];    /* the string shown solar term */
    S8 MessageLine2[CLNDR_HINT_LEN];    /* the string shown about unlucky direction */
    S8 MessageLine3[CLNDR_HINT_LEN];    /* the string shown about unfortunate age */
} clndr_lnuar_date_info_struct;

typedef struct
{
    U8 date;
#ifdef __MMI_CLNDR_ICON_SUPPORT__
    U16 icon;
#endif 
    ToDoListNode *maxPriorityTask;
} clndr_task_icon_struct;

#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
typedef struct
{
    U8 taskNum;
    U8 weeday;
    U8 periodIndex;
#ifdef __MMI_CLNDR_ICON_SUPPORT__
    U16 icon;
#endif 
    /* ToDoListNode* maxPriorityTask; */
} clndr_weekly_task_struct;
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 

#ifdef __MMI_BIRTHDAY_REMINDER__
typedef struct
{
    U16 firstMatchedIndex;
    U16 count;
} birthday_info_struct;
#endif /* __MMI_BIRTHDAY_REMINDER__ */ 

typedef struct
{
    /* U16  ImgID; */
    MYTIME CalTime;
    clndr_lnuar_date_info_struct LunarInfo;
    /* S8   TitleString[CLNDR_TITLE_LEN]; */
    S8 DayBuf[CLNDR_DAY_LEN];
    S8 MonBuf[CLNDR_MON_LEN];
    S8 YearBuf[CLNDR_YEAR_LEN];
    U8 LunarState;
    U8 DayOnFirst;
    U8 NumDaysInMonth;
#ifdef __MMI_CALENDAR_V2__
    U8 *Title;
    U8 *HorizonList[CLNDR_COLUMN];
    U8 *VerticalList[CLNDR_ROW];
    gui_calendar_cell_struct *CalendarCell;
    U8 RowNumber;
    U8 DisplayType;
    U8 horizon_select1[CLNDR_VERTICAL_SELECT_LEN];
    U8 horizon_select2[CLNDR_VERTICAL_SELECT_LEN];
    clndr_task_icon_struct TaskDayList[CLNDR_COLUMN *CLNDR_MAX_ROW];
#else /* __MMI_CALENDAR_V2__ */ 
    U8 TaskDayList[CLNDR_MAX_DAYS + 1];
#endif /* __MMI_CALENDAR_V2__ */ 
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    U8 WeekNum;
    U8 CurrPeriodIndex; /* start period of weekly view */
    U8 PeriodInterval;  /* unit of each period */
    U8 PeriodStartIndex;
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 

#ifdef __MMI_CLNDR_ICON_SUPPORT__
    /* clndr_weekly_task_struct TaskPeriodList[CLNDR_COLUMN * CLNDR_MAX_ROW]; */
    U16 info_box_icon[CLNDR_INFO_BOX_ROW];
    U8 *info_box_text[CLNDR_INFO_BOX_ROW];
#endif /* __MMI_CLNDR_ICON_SUPPORT__ */ 
#ifdef __MMI_BIRTHDAY_REMINDER__
    birthday_info_struct BirthdayInfo[CLNDR_MONTH_DAYS + 1];
    /* U16 DailylyBirthdayCount; */
#endif /* __MMI_BIRTHDAY_REMINDER__ */ 

#ifdef __MMI_BPP_SUPPORT__
    U8 IsEntryByBPP;
    U8 calendar_task_index;
    U8 IsBPPPreview;
#endif /* __MMI_BPP_SUPPORT__ */ 
} clndr_context_struct;

#ifdef __MMI_CALENDAR_V2__
typedef enum
{
    CLNDR_KEY_UP = 0,
    CLNDR_KEY_DOWN,
    CLNDR_KEY_LEFT,
    CLNDR_KEY_RIGHT,
    CLNDR_KEY_TOTAL
} CLNDR_KEY_ENUM;

typedef enum CLNDR_CLNDAR_MOVEMENT
{
    CLNDR_NEXT_MONTH,
    CLNDR_PRIVOUS_MONTH,
    CLNDR_NEXT_WEEK,
    CLNDR_PRIVOUS_WEEK,
#ifdef __MMI_TOUCH_SCREEN__
    CLNDR_NEXT_YEAR,
    CLNDR_PRIVOUS_YEAR,
    CLNDR_NEXT_PERIOD,
    CLNDR_PRIVOUS_PERIOD,
    CLNDR_NEXT_MULTI_PERIOD,
    CLNDR_PRIVOUS_MULTI_PERIOD,
#endif /* __MMI_TOUCH_SCREEN__ */ 
    CLNDR_CLNDAR_MOVEMENT_TOTAL
} CLNDR_CLNDAR_MOVEMENT_ENUM;

#endif /* __MMI_CALENDAR_V2__ */ 

#endif /* _CALDEF_H */ 
