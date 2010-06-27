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
 * CalendarProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum value, structure, and function prototypes for calendar application.
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

/**********************************************************************************
   Filename:      CalendarProt.h
   Author:        GAUTAM
   Date Created:  July-12-2003
   Contains:      Calendar Prot
**********************************************************************************/
#ifndef _MMI_CALENDARPROT_H
#define _MMI_CALENDARPROT_H
#include "MMI_features.h"
#ifdef __MMI_CALENDAR__
#include "wgui_categories_calendar.h"
#include "MMIDataType.h"

#ifdef __MMI_BPP_SUPPORT__
#include "BTMMICm.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBppXhtmlGprot.h"
#endif /* __MMI_BPP_SUPPORT__ */ 

/* 
 * Define
 */

/* 
 * Typedef 
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

extern void ClndrInit(void);
extern U8 ClndrDeInit(void);

extern void ClndrComputeLunarInfo(clndr_lnuar_date_info_struct *DI);
extern S16 ClndrComputeSolarTerm(S16 year, S16 month, S16 solar_index);
extern void ClndrPreEntryApp(void);
extern void EntryClndrScreen(void);
extern void ExitClndrScreen(void);
extern void HighlightClndrMenu(void);
extern void HighlightClndrDate(S32 date);
extern void ClndrGetScreenInfo(void);
extern void ClndrGoBackFromCalendar(void);

extern void ExitClndrOptions(void);
extern void EntryClndrOptions(void);
extern void HighlightClndrViewTask(void);
extern void HighlightClndrLunar(void);
extern void ClndrDisplayTask(void);
extern void ClndrLunarHintHandler(U16);

extern void HighlightJumpToDate(void);
extern void EntryClndrJumpToDate(void);
extern void ClndrDateEditorCallBack(U8 *par1, U8 *par2, U8 *par3, U8 *par4);

extern void mmi_clndr_set_date(MYTIME *date);

#ifdef __MMI_CALENDAR_V2__
/* construct calendar information */
extern void mmi_clndr_get_week_numbers(U16 year, U8 month, U8 **weekStr);
extern void mmi_clndr_get_date_str(MYTIME *date, U8 *dateStr);
extern void mmi_clndr_get_weekday(U8 **weekdayStr);
extern void mmi_clndr_util_num_to_unicode(S32 num, U8 *str, U8 len);

extern void mmi_clndr_construct_monthly_cell_info(void);
extern void mmi_clndr_construct_weekly_cell_info(void);
extern void mmi_clndr_highlight_monthly_view(void);
extern void mmi_pre_entry_monthly_view_screen(void);
extern MMI_BOOL mmi_clndr_monthly_highlight(U32 row, U32 column);
extern MMI_BOOL mmi_clndr_monthly_movement(U32 type);
extern MMI_BOOL mmi_clndr_left_out_of_boundary(U32 row, U32 column);
extern MMI_BOOL mmi_clndr_right_out_of_boundary(U32 row, U32 column);
extern MMI_BOOL mmi_clndr_up_out_of_boundary(U32 row, U32 column);
extern MMI_BOOL mmi_clndr_down_out_of_boundary(U32 row, U32 column);
extern void mmi_clndr_monthly_set_content(void);
extern MMI_BOOL mmi_clndr_monthly_compute_next_time(U32 arrow);
extern MMI_BOOL mmi_clndr_monthly_out_of_boundary(MYTIME *resultDate);

#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_clndr_touch_year_increase(U32 row, U32 column);
MMI_BOOL mmi_clndr_touch_year_decrease(U32 row, U32 column);
MMI_BOOL mmi_clndr_touch_month_increase(U32 row, U32 column);
MMI_BOOL mmi_clndr_touch_month_decrease(U32 row, U32 column);
MMI_BOOL mmi_clndr_periodly_movement(U32 type);

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
extern void mmi_clndr_highlight_weekly_view(void);
extern void mmi_pre_entry_weekly_view_screen(void);
extern void mmi_clndr_get_first_date_of_week(MYTIME *currDate, MYTIME *firstDateOfWeek);
extern void mmi_clndr_get_weekly_dates(MYTIME *currDate, U8 **dateStr);
extern void mmi_clndr_get_period_range(U8 PeriodStart, U8 **periodStr);
extern MMI_BOOL mmi_clndr_weekly_highlight(U32 row, U32 column);
extern void mmi_clndr_weekly_set_cell_validation(U32 dow, U32 type);
extern MMI_BOOL mmi_clndr_weekly_movement(U32 type);
extern U8 mmi_clndr_get_period_interval(void);
extern MMI_BOOL mmi_clndr_weekly_compute_next_time(U32 arrow);

/* extern MMI_BOOL mmi_clndr_weekly_out_of_boundary(U32 arrow, U32 row, U32 column); */
extern MMI_BOOL mmi_clndr_weekly_out_of_boundary(MYTIME *resultDate, U32 highlightRow);

extern void mmi_clndr_weekly_set_content(void);
extern MMI_BOOL mmi_clndr_weekly_increase(U32 row, U32 column);
extern MMI_BOOL mmi_clndr_weekly_decrease(U32 row, U32 column);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL mmi_clndr_touch_multi_periodly_increase(U32 row, U32 column);
extern MMI_BOOL mmi_clndr_touch_multi_periodly_decrease(U32 row, U32 column);
extern MMI_BOOL mmi_clndr_touch_single_periodly_increase(U32 row, U32 column);
extern MMI_BOOL mmi_clndr_touch_single_periodly_decrease(U32 row, U32 column);

extern MMI_BOOLmmi_clndr_periodly_movement(U32 type);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 
#ifdef __MMI_TODOLIST__
extern void mmi_prepare_for_add_task(void);
extern void mmi_clndr_highlight_add_task(void);
#endif /* __MMI_TODOLIST__ */ 
#ifdef __MMI_CLNDR_ICON_SUPPORT__
/* extern MMI_BOOL mmi_clndr_get_task_by_date(U8 date, clndr_task_icon_struct* task); */
extern void mmi_momthly_clndr_set_info_box(void);
extern void mmi_weekly_clndr_set_info_box(void);
#endif /* __MMI_CLNDR_ICON_SUPPORT__ */ 

#endif /* __MMI_CALENDAR_V2__ */ 

#ifdef __MMI_BIRTHDAY_REMINDER__
extern void mmi_clndr_get_monthly_birthday_info(U16 year, U8 month, birthday_info_struct *BirthdayInfo);
extern void mmi_clndr_get_daily_birthday_info(U16 year, U8 month, U8 day, U16 amount, U16 *PBIndexList);
extern void mmi_clndr_read_birthday_info(MMI_PHB_BDAY_STRUCT *bday);
extern U16 mmi_clndr_get_daily_birthday_amount(U8 date);
extern void mmi_clndr_set_birthday_table(U16 year, U8 month);

#endif /* __MMI_BIRTHDAY_REMINDER__ */ 

#ifdef __MMI_BPP_SUPPORT__
extern void mmi_clndr_bpp_get_snapshot_file_path(S8* file_path);
extern void mmi_clndr_bpp_create_snapshot(S8* file_path);
extern void mmi_clndr_highlight_bpp_print(void);
extern void mmi_clndr_bpp_print(void);
extern void mmi_clndr_xhtml_table_constructer(mmi_bpp_xhtml_rsp_enum rsp_code);
extern void mmi_clndr_bpp_img_file_callback(mmi_bpp_xhtml_rsp_enum rsp_code);
extern mmi_bpp_xhtml_rsp_enum mmi_clndr_bpp_compose_tasks(void);
extern void mmi_clndr_bpp_compose_task_callback(mmi_bpp_xhtml_rsp_enum rsp_code);
extern void mmi_clndr_bpp_compose_file_end(void);
extern void mmi_clndr_get_task_string(ToDoListNode *task, S8 *task_str);
extern U8 mmi_clndr_bpp_delete_callback(void);
#endif /* __MMI_BPP_SUPPORT__ */ 

#endif /* __MMI_CALENDAR__ */ 

#endif /* _MMI_CALENDARPROT_H */ // #ifndef _MMI_CALENDARPROT_H
