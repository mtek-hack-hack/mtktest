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
 *   app_datetime.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines structure, contant, and function prototypes for date/time interfaces.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __APP_DATETIME_H__
#define __APP_DATETIME_H__

#include "kal_non_specific_general_types.h"
#include "rtc_sw.h"

 /***************************************************************************** 
* Define
*****************************************************************************/
#define DT_TIME_LESS -1
#define DT_TIME_EQUAL 0
#define DT_TIME_GREATER 1

#define CLNDR_MAX_WEEK_NUM 54
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    kal_uint16 nYear;
    kal_uint8 nMonth;
    kal_uint8 nDay;
    kal_uint8 nHour;
    kal_uint8 nMin;
    kal_uint8 nSec;
    kal_uint8 DayIndex; /* 0=Sunday */
} applib_time_struct;

#ifndef NUM_MONTHS
#define NUM_MONTHS 12
#define NUM_MIN_HR  60
#define NUM_HRS_DAY  24

typedef enum MONTH_LIST
{
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
} MONTH_LIST;
#endif /* NUM_MONTHS */ 
/*****************************************************************************              
* Extern Global Variable                                                                    
**************************************************************************** */

/*****************************************************************************              
* Extern Global Function                                                                    
**************************************************************************** */
extern kal_uint8 applib_dt_is_leap_year(kal_uint16 year);
extern kal_uint8 applib_dt_last_day_of_mon(kal_uint8 month, kal_uint16 year);
extern kal_uint8 applib_dt_dow(kal_uint16 y, kal_uint8 m, kal_uint8 d);
extern void applib_dt_utc_to_rtc(float tz, applib_time_struct *utc, applib_time_struct *result);
extern applib_time_struct applib_conv_tz_to_mytime(float tz);
extern void applib_dt_decrease_time(
                applib_time_struct *timeToIncrement,
                applib_time_struct *increment,
                applib_time_struct *Result);
extern void applib_dt_increase_time(
                applib_time_struct *timeToIncrement,
                applib_time_struct *increment,
                applib_time_struct *Result);
extern kal_int32 applib_dt_compare_time(
                    applib_time_struct *referenceTime,
                    applib_time_struct *compareTime,
                    applib_time_struct *diff);
extern kal_bool applib_dt_is_valid(applib_time_struct *t);
extern kal_bool applib_dt_is_dst_enabled(void);
extern kal_bool applib_dt_time2rfc1123dateString(kal_uint32 gmt_time, kal_char *buffer);
extern kal_bool applib_dt_rfc1123_rfc850_asctime_dateString2Time(const kal_char *date, kal_uint32 *time);
extern void applib_dt_2time_decreament(
                applib_time_struct timeToDecrement,
                applib_time_struct decrement,
                applib_time_struct *Result);
extern applib_time_struct *applib_get_time_difference(
                            applib_time_struct *t1,
                            applib_time_struct *t2,
                            applib_time_struct *result);
extern applib_time_struct *applib_get_time_difference_ext(
                            applib_time_struct *t1,
                            applib_time_struct *t2,
                            applib_time_struct *result);
extern kal_uint32 applib_get_time_difference_ext_in_second(
                        applib_time_struct *t1,
                        applib_time_struct *t2);
extern kal_uint16 applib_find_max_time(applib_time_struct *t1, applib_time_struct *t2);
extern void applib_dt_get_date_time(applib_time_struct *t);
extern void applib_dt_get_rtc_time(applib_time_struct *t);
extern kal_uint32 applib_dt_mytime_2_utc_sec(applib_time_struct *currTime, kal_bool daylightSaving);
extern kal_uint8 applib_dt_utc_sec_2_mytime(kal_uint32 utc_sec, applib_time_struct *result, kal_bool daylightSaving);
extern kal_uint8 applib_dt_utc_sec_2_mytime_ext(kal_int64 utc_sec, applib_time_struct *result, kal_bool daylightSaving);
extern kal_int64 applib_dt_mytime_2_utc_sec_ext(applib_time_struct *currTime, kal_bool daylightSaving);
extern kal_uint32 applib_dt_sec_utc_to_local(kal_uint32 utc_sec);
extern kal_uint32 applib_dt_sec_local_to_utc(kal_uint32 local_sec);
extern void applib_dt_get_rtc_without_daylight_impact(applib_time_struct *t);
extern void applib_dt_modify_dt_with_daylight_impact(applib_time_struct *t);
extern void applib_dt_init_time(void);
extern void applib_dt_get_tz_string(kal_char *result);
extern void applib_dt_get_secure_time(applib_time_struct *t);
extern kal_uint8 applib_dt_get_week_number(applib_time_struct *date);
extern t_rtc applib_dt_conv_utc_to_local(float tz, t_rtc *utc_time);
extern kal_uint32 app_getcurrtime(void);
#endif /* __APP_DATETIME_H__ */ 

