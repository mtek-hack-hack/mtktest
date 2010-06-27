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
 * ToDoListDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines global function prototypes of To Do List application.
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

   FILENAME : ToDoListDef.h

   PURPOSE     : Data Account application

   REMARKS     : nil

   AUTHOR      : Arvind

   DATE     : 14th July,2003

**************************************************************/
#ifndef _MMI_TODOLISTDEF_H
#define _MMI_TODOLISTDEF_H
#include "MMI_features.h"
#ifdef __MMI_TODOLIST__

#include "MMIDataType.h"
#include "AlarmFrameworkProt.h"
#include "CalendarDef.h"

/* 
 * Define
 */
#ifdef __MMI_ADVANCED_TODO__
#define MAX_INLINE_ITEM_TODO_LIST      18
#else 
#define MAX_INLINE_ITEM_TODO_LIST      9
#endif 
#define MAX_LEN_LEAST_VAR           8
#define MAX_LEN_MOST_VAR            32
#define TDL_MAX_TIME_STR_LEN        14*ENCODING_LENGTH  /* 12:12 - 13:15 */
//PMT START LANGUAGE 20060104
//This is required because in Bulgairan the maximum length of day is 20
#define TDL_MAX_DAY_STR_LEN            21*ENCODING_LENGTH       /* 04/03/12 Thu */
/* PMT END LANGUAGE 20060104 */
#define MAX_MONTH_LEN               3*ENCODING_LENGTH
#define MAX_YEAR_LEN             5*ENCODING_LENGTH
#define TODO_FREQ_NUM         5
#define  TDL_MAX_DAYS_PER_MONTH        31

#define  MAX_DAY_IN_WEEK               7

#define MAX_TODO_LIST_TEMPLATE         10

#ifdef __MMI_ADVANCED_TODO__
#define TDL_MAX_NOTE_PREFIX_LEN        65*ENCODING_LENGTH
#define MAX_TODO_LIST_REM_NOTE         (MAX_TODO_LIST_NOTE*2) + TDL_MAX_NOTE_PREFIX_LEN
#else
#define TDL_MAX_NOTE_PREFIX_LEN        30*ENCODING_LENGTH
#define MAX_TODO_LIST_REM_NOTE         MAX_TODO_LIST_NOTE + TDL_MAX_NOTE_PREFIX_LEN
#endif

#ifdef __MMI_ADVANCED_TODO__
#define TDL_DT_DATE_AND_TIMEPERIOD  0
#define TDL_DT_ONLY_START_DT 1
#define TDL_DT_ALL  2

#define TDL_FIELD_MASK_LOCATION 0x04
#define TDL_FIELD_MASK_NOTE 0x08
#define TDL_FIELD_MASK_ALARM 0x10
#define TDL_FIELD_MASK_REPEAT 0x20
#define TDL_FIELD_MASK_PRIORITY 0x40

#define NUM_OF_TASK_PRIORITY 3

#define TDL_TASK_VIEW 0
#define TDL_TASK_EDIT 1

#endif /* __MMI_ADVANCED_TODO__ */ 

#ifdef __MMI_BIRTHDAY_REMINDER__
#define TDL_BIRTHDAY_INDEX_POOL (sizeof(U16) * MAX_PB_PHONE_ENTRIES)
#endif /*__MMI_BIRTHDAY_REMINDER__*/

/* 
 * Typedef 
 */

typedef struct
{
    S32 HilitedAlmState;    /* alarm on/off state in inline editor screen */
    S32 HilitedRepeat;      /* repeat criterion in inline editor screen */
    history *HistoryPtr;    /* pointer to store history buffer when inserting template */
    MYTIME ClndrDate;       /* date/time information from calendar application */
    ToDoListNode TaskList[NUM_OF_TDL];
    S8 MonBuff[MAX_MONTH_LEN];
    S8 DayBuff[MAX_MONTH_LEN];
    S8 YearBuff[MAX_YEAR_LEN];
    S8 HourBuff1[MAX_MONTH_LEN];
    S8 MinBuff1[MAX_MONTH_LEN];
    S8 HourBuff2[MAX_MONTH_LEN];
    S8 MinBuff2[MAX_MONTH_LEN];
    S8 RminderNote[MAX_TODO_LIST_REM_NOTE];
    S8 NoteBuff[MAX_TODO_LIST_NOTE];
    U8 DateStrBuff[TDL_MAX_DAY_STR_LEN];
    U8 TimeStrBuff[TDL_MAX_TIME_STR_LEN];
    U8 SortedList[NUM_OF_TDL];
    U8 IsCalledByCalender;  /* if to do list is entered via Calendar app */
    U8 CurrSelectedTask;    /* index of current selected task */
    U8 CurrHiliteOption;    /* index of current higlighted option */
    U8 TotalListedTask;     /* total number of listed task */
    U8 SelectedTemplate;    /* index of current selected template */
    U8 IsListModified;
    U8 SelectedItemInView;  /* index of selected item in View screen */
    U8 CurrTaskIndex;       /* index of current selected task */
    U8 IsDOWSet;
    U8 NoteIndex;           /* index of inline editor for notes */
    U8 DOWIndex;            /* index of inline editor for notes */
    U8 IsSaveToHistory;     /* shall alarm screen save to history or not */
#ifdef __MMI_ADVANCED_TODO__
    U8 CurrTaskType;
    U8 FieldFlag;       /* used to indicate the fields of the task
                           First two bits are for datetime/format, and the following bits are for location, note, alarm, repeat, priority */
    S8 MonBuffEnd[MAX_MONTH_LEN];
    S8 DayBuffEnd[MAX_MONTH_LEN];
    S8 YearBuffEnd[MAX_YEAR_LEN];

    U8 EndDateStrBuff[TDL_MAX_DAY_STR_LEN];
    U8 EndTimeStrBuff[TDL_MAX_TIME_STR_LEN];

    S8 LocationBuff[MAX_TODO_LIST_NOTE];
    U8 LocationIndex;   /* index of inline editor for location */

    S32 HilitedPriorityState;   /* priority state in inline editor screen */
    S32 HilitedInlineEditor;    /* current index of inline editor */

    U8 DateUpdate;
    S8 title[25 * ENCODING_LENGTH]; /* title string, the max length is 25 characters */
#endif /* __MMI_ADVANCED_TODO__ */ 
#ifdef __MMI_BIRTHDAY_REMINDER__
    U16 *PBIndexList;
    U16 CurrHighlightBRIndex;
#endif /* __MMI_BIRTHDAY_REMINDER__ */ 

} tdl_context_struct;

typedef enum
{
    TODO_LIST_ALARM_OFF = 0,
    TODO_LIST_ALARM_ON,
#ifdef __MMI_ADVANCED_TODO__
    TODO_LIST_ALARM_BEFORE_5_MINS,
    TODO_LIST_ALARM_BEFORE_15_MINS,
    TODO_LIST_ALARM_BEFORE_30_MINS,
#endif /* __MMI_ADVANCED_TODO__ */ 
    TODO_LIST_ALARM_TOTAL
} TODO_LIST_ALARM;
typedef enum
{
    TODO_LIST_TASK_OPTION_VIEW = 0,
    TODO_LIST_TASK_OPTION_ADD,
    TODO_LIST_TASK_OPTION_EDIT,
    TODO_LIST_TASK_OPTION_DELETE,
    TODO_LIST_TASK_OPTION_DELETE_ALL,
#if defined(__MMI_VCALENDAR__)
    TODO_FROM_FMGR,
    TODO_FROM_NETWORK,
#endif /* defined(__MMI_VCALENDAR__) */ 
    TODO_LIST_OPTION_TOTAL
} TDL_OPTION_ENUM;

#ifdef __MMI_ADVANCED_TODO__
typedef enum
{
    TDL_TASK_REMINDER = 0,
    TDL_TASK_MEETING,
    TDL_TASK_COURSE,
    TDL_TASK_DATE,
    TDL_TASK_CALL,
    TDL_TASK_ANNIVERSARY,
    TDL_TOTAL_TASK
} TDL_TASK_TYPE_ENUM;

typedef enum
{
    TDL_TASK_PRIORITY_LOW = 0,
    TDL_TASK_PRIORITY_MEDIUM,
    TDL_TASK_PRIORITY_HIGH,
    TDL_TOTAL_PRIORITY
} TDL_TASK_PRIORITY;

#endif /* __MMI_ADVANCED_TODO__ */ 
/* 
 * Extern Global Variable
 */
extern tdl_context_struct g_tdl_cntx;
extern const U8 g_tdl_freq_set[];

/* 
 * Extern Global Function
 */
extern void InitToDoListApp(void);
extern void DeInitToDoListApp(void);    /* currently unused */
extern void TDLShowSpecificDateList(void);
extern void TDLGetDaysToBeHilited(MYTIME mytime, U8 *daylist);
extern void TDLExitReminderScreen(void);
extern void EntryTDLReminder(void);
extern void mmi_tdl_set_clndr(MYTIME *CalTime, U8 Type);

extern void TDLFCBInit(void);

/* local function */
extern void TDLReInitQueueCBH(void);
extern void TDLExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder);
extern U8 TDLExpiryHandler(U8 index, U16 *period, BOOL power_on);
extern void mmi_tdl_reset_handler(void *msg);
extern void HighlightTDLMenu(void);
extern void EntryTDLTaskList(void);
extern void mmi_tdl_task_list_goback(void);
extern void HighlightTDLTaskList(S32 nIndex);

extern void EntryTDLTaskListOption(void);
extern void HighlightTDLTaskOption(S32 nIndex);

extern void EntryTDLDelete(void);
extern void EntryTDLDeleteAll(void);

extern void EntryTDLNoteOption(void);

extern void EntryTDLTemplate(void);
extern void HighlightTDLTemplateIndex(S32 nIndex);
extern void TDLInsertTemplate(void);

extern void mmi_tdl_highlight_hdlr_note_option_save(void);
extern void mmi_tdl_highlight_hdlr_note_option_template(void);
extern void mmi_tdl_highlight_hdlr_note_option_input_method(void);

extern void EntryTDLViewTask(void);
extern void ExitTDLViewTask(void);

extern void EntryTDLEditTask(void);
extern void ExitTDLTaskList(void);
extern void ExitTDLEditTask(void);
extern void HighlightTDLInlineRepeat(S32 index);
extern void EditToDoListTask(void);
extern void HighlightTDLViewInlineItem(S32 index);

extern void HighlightTDLEditInlineItem(S32 index);
extern void EntryTDLEditNote(void);

extern void TDLShowAllList(void);

extern void EntryTDLReminder(void);
extern void ExitTDLReminder(void);
extern void ToDoListReminder(void *ReminderId);
extern tdl_context_struct* mmi_tdl_get_context(void);

extern void TDLGoBackInlineScreen(void);

extern void EntryTDLSaveConfirm(void);

extern void TDLInitInlineVariables(void);

extern U8 TDLFillInlineStruct(void);
extern U8 TDLFillInlineStructForView(void);

extern void TDLGoBack2History(void);

extern void TDLDateEditorCallBack(U8 *DateStr, U8 *day, U8 *month, U8 *year);
extern void TDLTimeEditorCallBack(
                U8 *string_buffer,
                U8 *hours_buffer1,
                U8 *minutes_buffer1,
                U8 *AM_PM_flag1,
                U8 *hours_buffer2,
                U8 *minutes_buffer2,
                U8 *AM_PM_flag2);

extern void TDLWriteToNvram(U8 index);
extern void TDLReadFromNvram(void);

extern void TDLGoToSelectedOption(void);

extern void TDLAddDefaultRecord(void);

extern void TDLDeleteOneTask(void);
extern void TDLDeleteAllTask(void);

extern void TDLShowPopupScreen(U16 Msg);

extern void TDLGotoListOrOptionScreen(void);

extern void TDLSaveTask(void);

extern void TDLMakeListOfAllTask(void);
extern void TDLMakeListOfSelectedDate(U8 Type);
extern void TDLSortTask(U8 *sorted_list, U8 total_task);

extern U8 TDLIsTaskChanged(void);
extern void SetToDoListAlarm(U8 i);

extern void HighlightTdlView(void);
extern void HighlightTdlEdit(void);
extern void HighlightTdlDelete(void);
extern void HighlightTdlAdd(void);
extern void HighlightTdlDeleteAll(void);

extern void TdlExecView(void);
extern void TdlExecEdit(void);
extern void TdlExecDelete(void);

extern U8 mmi_tdl_pim_util_get_new_index(void);
extern U8 mmi_tdl_delete_record(U8 index);
extern U16 mmi_tdl_is_valid_fields(ToDoListNode *tdlItem);
extern MMI_BOOL mmi_tdl_get_time_info(U8 tdl_index);
extern U8 TDLGetTotalItem(void);
#ifdef __SYNCML_SUPPORT__
extern U16 mmi_tdl_get_total_index(U16* list);
extern U16 mmi_tdl_sync_task(U8 action, S8 *path, U16 *index, U8 sync_chset);
extern U16 mmi_tdl_vcalendar_err_mapping(U16 vCalenar_err);
extern S32 mmi_tdl_synML_convert_vtodo_to_vevent(S8 *file_path_name);
extern S32 mmi_tdl_synML_quoted_printable_trick(S8 *file_path_name);
#endif
#ifdef __MMI_VCALENDAR__
extern U8 TdlInsertTask(ToDoListNode *, U8);

#endif /* __MMI_VCALENDAR__ */ 

#ifdef __MMI_ADVANCED_TODO__
extern void mmi_tdl_entry_select_task_type(void);
extern void mmi_tdl_set_dt_type(U8 dt_type);
extern U8 mmi_tdl_get_dt_type(void);
extern void mmi_tdl_disable_field(U8 index);
extern MMI_BOOL mmi_tdl_get_field_state(U8 index);
extern void mmi_tdl_time_editor_callback(U8 *string_buffer, U8 *hours_buffer, U8 *min_buffer, U8 *AM_PM_flag);

extern void mmi_tdl_highlight_meeting(void);
extern void mmi_tdl_highlight_course(void);
extern void mmi_tdl_highlight_date(void);
extern void mmi_tdl_highlight_call(void);
extern void mmi_tdl_highlight_anniversary(void);
extern void mmi_tdl_highlight_reminder(void);
extern void mmi_tdl_set_inline_icon(U16 *icons, U8 inline_num);
extern MMI_BOOL mmi_tdl_get_fields_of_task(U8 task_type);
extern void mmi_tdl_compute_reminder_time(ToDoListNode *task, MYTIME *preReminder);
extern void mmi_tdl_get_time_string(ToDoListNode *task, MYTIME* seletedDate, S8 *timeString);
extern void mmi_tdl_get_date_string(U16 year, U8 month, U8 day, S8 *timeString);
extern S32 mmi_tdl_get_daily_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
extern S32 mmi_tdl_get_all_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
extern void mmi_tdl_get_next_day_redraw(void);
extern void mmi_tdl_get_previous_day_redraw(void);
#endif /* __MMI_ADVANCED_TODO__ */ 
#ifdef __MMI_CALENDAR_V2__
#if defined(__MMI_ADVANCED_TODO__)
extern void mmi_tdl_get_monthly_task_with_icon(MYTIME *ClndrTime, clndr_task_icon_struct *daylist);
extern void mmi_tdl_set_task_icon(clndr_task_icon_struct *TaskInDay, U8 date, ToDoListNode *task);
#endif /* defined(__MMI_ADVANCED_TODO__) */ 
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
extern void mmi_tdl_get_period_task(void);
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */
#endif /* __MMI_CLNDR_ICON_SUPPORT__ */ 

#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
/* extern void mmi_tdl_get_weekly_tasks (MYTIME* SelectedDate, clndr_weekly_task_struct *PeriodList, U8 PeriodInterval, U8 PeriodRow); */
extern void mmi_tdl_get_weekly_tasks(
                MYTIME *SelectedDate,
                clndr_task_icon_struct *TaskInPeriod,
                U8 PeriodInterval,
                U8 PeriodRow);
extern void mmi_tdl_set_weekly_task(
                clndr_task_icon_struct *TaskInPeriod,
                ToDoListNode *task,
                U8 dow,
                U8 PeriodInterval,
                U8 StartCheck);

#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 

#endif /* __MMI_TODOLIST__ */ 
#ifdef __MMI_BIRTHDAY_REMINDER__
extern void mmi_tdl_construct_birthday_memory(void);
extern void mmi_tdl_destruct_birthday_memory(void);
extern void mmi_birthday_highlight_make_call(void);
extern void mmi_birthday_make_call(void);
extern void mmi_birthday_highlight_send_sms(void);
extern void mmi_entry_birthday_option_screen(void);
extern void mmi_birthday_send_sms(void);
#ifdef MMS_SUPPORT
extern void mmi_birthday_highlight_send_mms(void);
extern void mmi_birthday_send_mms(void);
#endif /*# MMS_SUPPORT */
extern MMI_BOOL mmi_birthday_check_pb_number(U8 *pbNumber);

#endif /* __MMI_BIRTHDAY_REMINDER__ */ 

#endif /* _MMI_TODOLISTDEF_H */ 
