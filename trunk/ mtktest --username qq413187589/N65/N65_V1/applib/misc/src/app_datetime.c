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
 *   app_datetime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements common interfaces for date/time.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "kal_release.h"
#include "rtc_sw.h"
#include "app_datetime.h"

#include "l4c2uem_struct.h"
#include "TimerEvents.h"

#include "NVRAMType.h"
#include "NVRAMEnum.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define DT_UTC_BASE_YEAR 1970
#define DT_MONTH_PER_YEAR 12
#define DT_DAY_PER_YEAR 365
#define DT_SEC_PER_DAY 86400
#define DT_SEC_PER_HOUR 3600
#define DT_SEC_PER_MIN 60
#define DT_MIN_PER_HR 60
#define DT_HRS_PRE_DAY 24

#define DT_MAX_YEAR 2030
#define DT_MIN_YEAR 2000

#define YEARFORMATE  2000
#define DT_DAYS_OF_WEEK    7

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#if defined (PLUTO_MMI)
const kal_uint8 gDaysInMonth[NUM_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#else
extern const kal_uint8 gDaysInMonth[];
#endif

#ifndef __MTK_TARGET__
applib_time_struct MyTime = {0, 1, 1, 1, 1, 1, 0};  /* Variable used by Setting Application */
kal_int8 DateTimeStrings[2][30];                    /* amitm5 to be removed as told by manju */
static kal_int8 NameOfMonth[12][4] =
    { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
static kal_int8 NameOfday[7][4] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
#endif /* __MTK_TARGET__ */ 
/***************************************************************************** 
* Local Variable
*****************************************************************************/
static kal_char *weekday_c[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };     /* Compact String */
static kal_char *weekday_f[] = { "Sunday", "Monday", "Tuesday", "Wedensday", "Thursday", "Friday", "Saturday" };        /* Full string */
static kal_char *months_c[] = { "Dec", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov" };   /* Compact string */
static kal_char *months_f[] = { "December", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" };     /* Full string */
static const kal_int16 accumulating_monthdays[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
const kal_uint8 g_dt_day_per_mon[DT_MONTH_PER_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#if defined (PLUTO_MMI)

rtc_format_struct gclockData;

#ifdef __DAILY_WALLPAPER__
rtc_format_struct gWallpaperChangeDate;
#endif 

extern kal_uint8 g_dst;
#else /* defined (PLUTO_MMI) */ 
extern rtc_format_struct gclockData;

#ifdef __DAILY_WALLPAPER__
extern rtc_format_struct gWallpaperChangeDate;
#endif 

kal_uint8 g_dst;

#endif /* defined (PLUTO_MMI) */ 
/***************************************************************************** 
* Global Function
*****************************************************************************/
/* MMI functions */
extern float GetTimeZone(kal_uint8 cityIndex);
extern kal_uint8 PhnsetGetHomeCity(void);


/*****************************************************************************
 * FUNCTION
 *  applib_dt_is_leap_year
 * DESCRIPTION
 *  Function to find out if given year is a leap year
 * PARAMETERS
 *  year        [IN]        
 *  y(?)        [IN]        Year of the date to be computed  (example, 2004)
 * RETURNS
 *  1 if the year is leap; otherwise 0.
 *****************************************************************************/
kal_uint8 applib_dt_is_leap_year(kal_uint16 year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((year % 400) == 0)
    {
        return 1;
    }
    else if ((year % 100) == 0)
    {
        return 0;
    }
    else if ((year % 4) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_last_day_of_mon
 * DESCRIPTION
 *  Function to find the last day of specific month.
 * PARAMETERS
 *  month       [IN]        Month
 *  year        [IN]        Year
 * RETURNS
 *  number of days
 *****************************************************************************/
kal_uint8 applib_dt_last_day_of_mon(kal_uint8 month, kal_uint16 year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (month != 2)
    {
        return g_dt_day_per_mon[month - 1];
    }
    else
    {
        return g_dt_day_per_mon[1] + applib_dt_is_leap_year(year);
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_dow
 * DESCRIPTION
 *  Function to compute current day of week.
 * PARAMETERS
 *  y       [IN]        Year of the date to be computed. (example, 2004)
 *  m       [IN]        Month of the date to be computed
 *  d       [IN]        Day of the date to be computed
 * RETURNS
 *  kal_uint8   index of day of week
 *****************************************************************************/
kal_uint8 applib_dt_dow(kal_uint16 y, kal_uint8 m, kal_uint8 d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m < 3)
    {
        m += 13;
        y--;
    }
    else
    {
        m++;
    }

    return (d + 26 * m / 10 + y + y / 4 - y / 100 + y / 400 + 6) % 7;
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_utc_to_rtc
 * DESCRIPTION
 *  compute utc time to rtc time
 * PARAMETERS
 *  tz      [IN]        Time zone
 *  utc     [IN]        Utc time
 * RETURNS
 *  result of time
 *****************************************************************************/
void applib_dt_utc_to_rtc(float tz, applib_time_struct *utc, applib_time_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct incTime;
    kal_bool negative = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tz < 0)
    {
        negative = KAL_TRUE;
        tz = 0 - tz;
    }

    incTime = applib_conv_tz_to_mytime(tz);

    if (negative)
    {
        applib_dt_decrease_time(utc, &incTime, result);
    }
    else
    {
        applib_dt_increase_time(utc, &incTime, result);
    }

}


/*****************************************************************************
 * FUNCTION
 *  applib_conv_tz_to_mytime
 * DESCRIPTION
 *  contert timezone to MYTIME structure
 * PARAMETERS
 *  tz      [IN]        Time zone to be converted
 * RETURNS
 *  result in MYTIME structure
 *****************************************************************************/
applib_time_struct applib_conv_tz_to_mytime(float tz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct result;
    kal_int16 timezone = (kal_int16) (tz * 4);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&result, 0, sizeof(applib_time_struct));
    result.nHour = (kal_uint8) (timezone / 4);
    result.nMin = (kal_uint8) ((timezone % 4) * 15);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_decrease_time
 * DESCRIPTION
 *  Decrease a reference time by some time
 * PARAMETERS
 *  timeToDecrement     [IN]            Time to be decreased
 *  decrement           [IN]            Time to decrease
 *  Result              [IN/OUT]        Result of compuatation
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_decrease_time(
        applib_time_struct *timeToDecrement,
        applib_time_struct *decrement,
        applib_time_struct *Result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (decrement->nSec != 0)
    {
        if (timeToDecrement->nSec >= decrement->nSec)
        {
            Result->nSec = timeToDecrement->nSec - decrement->nSec;
        }
        else
        {
            Result->nSec = DT_MIN_PER_HR + timeToDecrement->nSec - decrement->nSec;
            decrement->nMin++;
        }
    }
    else
    {
        Result->nSec = timeToDecrement->nSec;
    }

    if (decrement->nMin != 0)
    {
        if (timeToDecrement->nMin >= decrement->nMin)
        {
            Result->nMin = timeToDecrement->nMin - decrement->nMin;
        }
        else
        {
            Result->nMin = DT_MIN_PER_HR + timeToDecrement->nMin - decrement->nMin;
            decrement->nHour++;
        }
    }
    else
    {
        Result->nMin = timeToDecrement->nMin;
    }

    if (decrement->nHour != 0)
    {
        if (timeToDecrement->nHour >= decrement->nHour)
        {
            Result->nHour = timeToDecrement->nHour - decrement->nHour;
        }
        else
        {
            Result->nHour = DT_HRS_PRE_DAY + timeToDecrement->nHour - decrement->nHour;
            decrement->nDay++;
        }
    }
    else
    {
        Result->nHour = timeToDecrement->nHour;
    }

    if (decrement->nDay != 0)
    {
        if (timeToDecrement->nDay > decrement->nDay)
        {
            Result->nDay = timeToDecrement->nDay - decrement->nDay;
        }
        else
        {
            decrement->nMonth++;
            if (timeToDecrement->nMonth != 1)
            {
                Result->nDay = applib_dt_last_day_of_mon(
                                (kal_uint8) (timeToDecrement->nMonth - 1),
                                timeToDecrement->nYear) + timeToDecrement->nDay - decrement->nDay;
            }
            else
            {
                Result->nDay = 31 + timeToDecrement->nDay - decrement->nDay;
            }
        }
    }
    else
    {
        Result->nDay = timeToDecrement->nDay;
    }

    if (decrement->nMonth != 0)
    {
        if (timeToDecrement->nMonth > decrement->nMonth)
        {
            Result->nMonth = timeToDecrement->nMonth - decrement->nMonth;
        }
        else
        {
            Result->nMonth = DT_MONTH_PER_YEAR + timeToDecrement->nMonth - decrement->nMonth;
            decrement->nYear++;
        }
    }
    else
    {
        Result->nMonth = timeToDecrement->nMonth;
    }

    Result->nYear = timeToDecrement->nYear - decrement->nYear;

    Result->DayIndex = applib_dt_dow(Result->nYear, Result->nMonth, Result->nDay);

}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_increase_time
 * DESCRIPTION
 *  Increase a reference time by some time
 * PARAMETERS
 *  timeToIncrement     [IN]        Time to be increased
 *  increment           [?]         
 *  Result              [?]         
 *  decrement(?)        [IN]        Time to increase
 * RETURNS
 *  result of computation(?)
 *****************************************************************************/
void applib_dt_increase_time(
        applib_time_struct *timeToIncrement,
        applib_time_struct *increment,
        applib_time_struct *Result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 NumOfDays;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* second */
    Result->nSec = (timeToIncrement->nSec + increment->nSec);

    /* minute */
    Result->nMin = (timeToIncrement->nMin + increment->nMin);
    if (Result->nSec >= DT_MIN_PER_HR)
    {
        Result->nSec -= DT_MIN_PER_HR;
        Result->nMin += 1;
    }

    /* hour */
    Result->nHour = (timeToIncrement->nHour + increment->nHour);
    if (Result->nMin >= DT_MIN_PER_HR)
    {
        Result->nMin -= DT_MIN_PER_HR;
        Result->nHour += 1;
    }

    /* day */
    Result->nDay = (timeToIncrement->nDay + increment->nDay);
    if (Result->nHour >= DT_HRS_PRE_DAY)
    {
        Result->nHour -= DT_HRS_PRE_DAY;
        Result->nDay += +1;
    }

    /* month, year */
    Result->nMonth = timeToIncrement->nMonth + increment->nMonth;
    Result->nYear = timeToIncrement->nYear + increment->nYear;

    if (Result->nMonth > DT_MONTH_PER_YEAR)
    {
        Result->nMonth -= DT_MONTH_PER_YEAR;
        Result->nYear++;
    }

    /* correct day */
    NumOfDays = applib_dt_last_day_of_mon(timeToIncrement->nMonth, timeToIncrement->nYear);

    if (Result->nDay > NumOfDays)
    {
        Result->nDay -= NumOfDays;

        if (Result->nMonth != 12)
        {
            Result->nMonth += 1;
        }
        else
        {
            Result->nMonth = 1;
            Result->nYear += 1;
        }
    }

    Result->DayIndex = applib_dt_dow(Result->nYear, Result->nMonth, Result->nDay);
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_compare_time
 * DESCRIPTION
 *  Compare the equality between 2 times.
 * PARAMETERS
 *  referenceTime       [IN]        Time to be compare in right-hand side
 *  compareTime         [IN]        Time to be compare in left-hand side
 *  diff                [IN]        Not yet used
 * RETURNS
 *  DT_TIME_LESS      if referenceTime < compareTime
 *  DT_TIME_EQUAL     if referenceTime = compareTime
 *  DT_TIME_GREATER   if referenceTime > compareTime
 *****************************************************************************/
kal_int32 applib_dt_compare_time(
            applib_time_struct *referenceTime,
            applib_time_struct *compareTime,
            applib_time_struct *diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 toReturn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (referenceTime->nYear == compareTime->nYear)
    {
        if (referenceTime->nMonth == compareTime->nMonth)
        {
            if (referenceTime->nDay == compareTime->nDay)
            {
                if (referenceTime->nHour == compareTime->nHour)
                {
                    if (referenceTime->nMin == compareTime->nMin)
                    {
                        if (referenceTime->nSec == compareTime->nSec)
                        {
                            toReturn = DT_TIME_EQUAL;
                        }
                        else
                        {
                            if (referenceTime->nSec < compareTime->nSec)
                            {
                                toReturn = DT_TIME_LESS;
                            }
                            else
                            {
                                toReturn = DT_TIME_GREATER;
                            }
                        }
                    }
                    else
                    {
                        if (referenceTime->nMin < compareTime->nMin)
                        {
                            toReturn = DT_TIME_LESS;
                        }
                        else
                        {
                            toReturn = DT_TIME_GREATER;
                        }
                    }
                }
                else
                {
                    if (referenceTime->nHour < compareTime->nHour)
                    {
                        toReturn = DT_TIME_LESS;
                    }
                    else
                    {
                        toReturn = DT_TIME_GREATER;
                    }
                }
            }
            else
            {
                if (referenceTime->nDay < compareTime->nDay)
                {
                    toReturn = DT_TIME_LESS;
                }
                else
                {
                    toReturn = DT_TIME_GREATER;
                }
            }
        }
        else
        {
            if (referenceTime->nMonth < compareTime->nMonth)
            {
                toReturn = DT_TIME_LESS;
            }
            else
            {
                toReturn = DT_TIME_GREATER;
            }
        }
    }
    else
    {
        if (referenceTime->nYear < compareTime->nYear)
        {
            toReturn = DT_TIME_LESS;
        }
        else
        {
            toReturn = DT_TIME_GREATER;
        }
    }

    return toReturn;
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_is_valid
 * DESCRIPTION
 *  To compute is the date/time is within reasonable range
 * PARAMETERS
 *  t       [?]     Time to be computed
 * RETURNS
 *  TURE if date/time valid; otherwise, KAL_FALSE
 *****************************************************************************/
kal_bool applib_dt_is_valid(applib_time_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error handling */
    if (t->nYear > DT_MAX_YEAR || t->nYear < DT_MIN_YEAR)
    {
        return KAL_FALSE;
    }

    if (t->nMonth > 12)
    {
        return KAL_FALSE;
    }

    if (t->nMonth == 2)
    {
        if (t->nDay > (g_dt_day_per_mon[t->nMonth - 1] + applib_dt_is_leap_year(t->nYear)))
        {
            return KAL_FALSE;
        }
    }
    else
    {
        if (t->nDay > g_dt_day_per_mon[t->nMonth - 1])
        {
            return KAL_FALSE;
        }
    }

    if (t->nHour > 23)
    {
        return KAL_FALSE;
    }

    if (t->nMin > 59)
    {
        return KAL_FALSE;
    }

    if (t->nSec > 59)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_is_dst_enabled
 * DESCRIPTION
 *  Tp check if daylight saving time is enabled
 * PARAMETERS
 *  void
 *  t  time to be computed(?)
 * RETURNS
 *  TURE if enabled; otherwise, false
 *****************************************************************************/
kal_bool applib_dt_is_dst_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_bool) g_dst;
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_get_tz_string
 * DESCRIPTION
 *  Get timezone information of home city in +/- xx:xx format
 * PARAMETERS
 *  result      [IN/OUT]        String pointer to store the result
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_get_tz_string(kal_char *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char tmpBuff[40];
    kal_int16 homeTimeZone = (kal_int16) (GetTimeZone(PhnsetGetHomeCity()) * 4);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (homeTimeZone < 0)
    {
        homeTimeZone = 0 - homeTimeZone;
        sprintf(tmpBuff, "-%02d%02d", (homeTimeZone / 4), (homeTimeZone % 4) * 15);
    }
    else
    {
        sprintf(tmpBuff, "+%02d%02d", (homeTimeZone / 4), (homeTimeZone % 4) * 15);
    }

    strcpy(result, tmpBuff);
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_conv_utc_to_local
 * DESCRIPTION
 *  compute utc time to local time
 * PARAMETERS
 *  tz              [IN]        Time zone
 *  utc_time        [IN]        Utc time
 * RETURNS
 *  result of time
 *****************************************************************************/
t_rtc applib_dt_conv_utc_to_local(float tz, t_rtc *utc_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc outcome;
    applib_time_struct origin_t;
    applib_time_struct result_t;

    float home_tz = GetTimeZone(PhnsetGetHomeCity());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tz = home_tz - tz;

    origin_t.nYear = utc_time->rtc_year + YEARFORMATE;
    origin_t.nMonth = utc_time->rtc_mon;
    origin_t.nDay = utc_time->rtc_day;
    origin_t.nHour = utc_time->rtc_hour;
    origin_t.nMin = utc_time->rtc_min;
    origin_t.nSec = utc_time->rtc_sec;

    applib_dt_utc_to_rtc(tz, &origin_t, &result_t);

    outcome.rtc_year = result_t.nYear - YEARFORMATE;
    outcome.rtc_mon = result_t.nMonth;
    outcome.rtc_day = result_t.nDay;
    outcome.rtc_hour = result_t.nHour;
    outcome.rtc_min = result_t.nMin;
    outcome.rtc_sec = result_t.nSec;
    outcome.rtc_wday = result_t.DayIndex;

    return outcome;
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_mytime_2_utc_sec
 * DESCRIPTION
 *  convert applib_time_struct format of time to seconds after 1970/1/1
 * PARAMETERS
 *  currTime        [?]     
 *  daylightSaving  [IN]    If daylight saving should be considered.
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 applib_dt_mytime_2_utc_sec(applib_time_struct *currTime, kal_bool daylightSaving)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint32 no_of_days = 0;
    kal_int32 utc_time;
    kal_int32 is_leap;
    kal_uint8 dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currTime->nYear < DT_UTC_BASE_YEAR)
    {
        return 0;
    }

    /* year */
    for (i = DT_UTC_BASE_YEAR; i < currTime->nYear; i++)
    {
        no_of_days += (365 + applib_dt_is_leap_year(i));
    }

    /* month */
    is_leap = applib_dt_is_leap_year(currTime->nYear);
    for (i = 1; i < currTime->nMonth; i++)
    {
        no_of_days += applib_dt_last_day_of_mon((kal_uint8) i, currTime->nYear);
    }

    /* day */
    no_of_days += (currTime->nDay - 1);

    /* sec */
    utc_time =
        (kal_uint32) no_of_days *DT_SEC_PER_DAY + (kal_uint32) (currTime->nHour * DT_SEC_PER_HOUR +
                                                                currTime->nMin * DT_SEC_PER_MIN + currTime->nSec);

    dst = applib_dt_is_dst_enabled();

    if (dst && daylightSaving)
    {
        utc_time -= DT_SEC_PER_HOUR;
    }
    return utc_time;
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_utc_sec_2_mytime
 * DESCRIPTION
 *  convert from UTC second to applib_time_struct struct
 * PARAMETERS
 *  utc_sec     [IN]        Uct_sec
 *  result      [IN]        Result of time
 *  daylightSaving  [IN]    If daylight saving should be considered.
 * RETURNS
 *  KAL_TRUE if success; otherwise, KAL_FALSE.
 *****************************************************************************/
kal_uint8 applib_dt_utc_sec_2_mytime(kal_uint32 utc_sec, applib_time_struct *result, kal_bool daylightSaving)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 sec, day;
    kal_uint16 y;
    kal_uint8 m;
    kal_uint16 d;
    kal_uint8 dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst = applib_dt_is_dst_enabled();

    if (dst && daylightSaving)
    {
        utc_sec += DT_SEC_PER_HOUR;
    }

    /* hour, min, sec */
    /* hour */
    sec = utc_sec % DT_SEC_PER_DAY;
    result->nHour = sec / DT_SEC_PER_HOUR;

    /* min */
    sec %= DT_SEC_PER_HOUR;
    result->nMin = sec / DT_SEC_PER_MIN;

    /* sec */
    result->nSec = sec % DT_SEC_PER_MIN;

    /* year, month, day */
    /* year */
    /* year */
    day = utc_sec / DT_SEC_PER_DAY;
    for (y = DT_UTC_BASE_YEAR; day > 0; y++)
    {
        d = (DT_DAY_PER_YEAR + applib_dt_is_leap_year(y));
        if (day >= d)
        {
            day -= d;
        }
        else
        {
            break;
        }
    }
    result->nYear = y;

    for (m = 1; m < DT_MONTH_PER_YEAR; m++)
    {
        d = applib_dt_last_day_of_mon(m, y);
        if (day >= d)
        {
            day -= d;
        }
        else
        {
            break;
        }
    }

    result->nMonth = m;
    result->nDay = (kal_uint8) (day + 1);

    return KAL_TRUE;
}

 /*****************************************************************************
  * FUNCTION
  *  applib_dt_mytime_2_utc_sec_ext
  * DESCRIPTION
  *  convert applib_time_struct format of time to seconds after.
  *  The difference from applib_dt_mytime_2_utc_sec is that 
  *  if the date is before 1970/01/01, the return value will be negative.
  * PARAMETERS
  *  currTime        [?]     
  *  daylightSaving  [IN]    If daylight saving should be considered.
  * RETURNS
  *  void
  *****************************************************************************/
 kal_int64 applib_dt_mytime_2_utc_sec_ext(applib_time_struct *currTime, kal_bool daylightSaving)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     kal_uint16 i;
     kal_uint32 no_of_days = 0;
     kal_int64 utc_time;
     kal_int32 is_leap;
     kal_uint8 dst;
     applib_time_struct baseTime, diffTime;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     if (currTime->nYear >= DT_UTC_BASE_YEAR)
    {
        return (kal_uint32)applib_dt_mytime_2_utc_sec(currTime, daylightSaving);
    }
    else
    {       
        /* year */
         //for (i = currTime->nYear; i < DT_UTC_BASE_YEAR; i++)   
		 for (i = DT_UTC_BASE_YEAR - 1; i > currTime->nYear; i--)   
         {
             no_of_days += (365 + applib_dt_is_leap_year(i));
         }
     
         /* month */
         is_leap = applib_dt_is_leap_year(currTime->nYear);         
		 for (i = DT_MONTH_PER_YEAR; i > currTime->nMonth; i--)
         {
             no_of_days += applib_dt_last_day_of_mon((kal_uint8) i, currTime->nYear);
         }
     
         /* day */         
		 no_of_days += applib_dt_last_day_of_mon(currTime->nMonth, currTime->nYear) - currTime->nDay;
     
         /* sec */
		 memcpy(&baseTime, currTime, sizeof(applib_time_struct));
		 memset(&diffTime, 0, sizeof(applib_time_struct));
         baseTime.nHour = 23;
         baseTime.nMin = 59;
         baseTime.nSec = 59;

         applib_dt_2time_decreament(baseTime, *currTime, &diffTime);
         utc_time =
             (kal_uint32) no_of_days *DT_SEC_PER_DAY + (kal_uint32) (diffTime.nHour* DT_SEC_PER_HOUR +
                                                                     diffTime.nMin* DT_SEC_PER_MIN + diffTime.nSec + 1);         
     
         dst = applib_dt_is_dst_enabled();
     
         if (dst && daylightSaving)
         {
             utc_time -= DT_SEC_PER_HOUR;
         }
         utc_time = 0 - utc_time;
         
         return utc_time;
        
    }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  applib_dt_utc_sec_2_mytime_ext
  * DESCRIPTION
  *  convert from UTC second to applib_time_struct struct.
  *  It could handle the negative second that represent the date before 1970/01/01
  * PARAMETERS
  *  utc_sec     [IN]        Uct_sec
  *  result      [IN]        Result of time
  *  daylightSaving  [IN]    If daylight saving should be considered.
  * RETURNS
  *  KAL_TRUE if success; otherwise, KAL_FALSE.
  *****************************************************************************/
 kal_uint8 applib_dt_utc_sec_2_mytime_ext(kal_int64 utc_sec, applib_time_struct *result, kal_bool daylightSaving)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     kal_int32 sec, day;
     kal_uint16 y;
     kal_uint8 m;
     kal_uint16 d;
     kal_uint8 dst;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     if (utc_sec >= 0)
     {
        return applib_dt_utc_sec_2_mytime((kal_uint32)utc_sec, result, daylightSaving);
     }
     else
    {
         dst = applib_dt_is_dst_enabled();
     
         if (dst && daylightSaving)
         {
             utc_sec += DT_SEC_PER_HOUR;
         }
     
         /* hour, min, sec */
         /* hour */
         sec = 0 - (utc_sec % DT_SEC_PER_DAY);
		 if (sec % DT_SEC_PER_HOUR == 0)
		 {
			result->nHour = DT_HRS_PRE_DAY - sec / DT_SEC_PER_HOUR;
		 }
		 else
		 {
			result->nHour = DT_HRS_PRE_DAY - sec / DT_SEC_PER_HOUR - 1;
			/* min */
			sec %= DT_SEC_PER_HOUR;
			if (sec == 0)
			{
				result->nMin = DT_MIN_PER_HR - sec / DT_SEC_PER_MIN;
			}
			else
			{
				result->nMin = DT_MIN_PER_HR - sec / DT_SEC_PER_MIN - 1;
				/* sec */
				result->nSec = DT_SEC_PER_MIN - sec % DT_SEC_PER_MIN;
			}
		 }
              
         /* year, month, day */
         /* year */
         day = utc_sec / DT_SEC_PER_DAY;         
         for (y = DT_UTC_BASE_YEAR - 1; day > 0; y--)
         {
             d = (DT_DAY_PER_YEAR + applib_dt_is_leap_year(y));
             if (day >= d)
             {
                 day -= d;
             }
             else
             {
                 break;
             }
         }
         result->nYear = y;
     
         for (m = DT_MONTH_PER_YEAR; m > 0; m--)
         {
             d = applib_dt_last_day_of_mon(m, y);
             if (day >= d)
             {
                 day -= d;
             }
             else
             {
                 break;
             }
         }
     
         result->nMonth = m;
         result->nDay = applib_dt_last_day_of_mon(result->nMonth, result->nYear) - (kal_uint8) (day);
     
         return KAL_TRUE;
    }
 }


/*****************************************************************************
 * FUNCTION
 *  applib_dt_rfc1123_rfc850_asctime_dateString2Time
 * DESCRIPTION
 *  This function is used to convert rfc1123, rfc850 and asctime date string to time seconds.
 * PARAMETERS
 *  date            [IN]            
 *  time            [IN/OUT]        The time seconds for date_str
 *  date_str(?)     [IN]            The rfc1123 date string
 * RETURNS
 *  KAL_TRUE: Success
 *  KAL_FALSE: Wrong Format
 *****************************************************************************/
kal_bool applib_dt_rfc1123_rfc850_asctime_dateString2Time(const kal_char *date, kal_uint32 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 year = 0;
    kal_uint16 month = 0;
    kal_uint16 day = 0;
    kal_uint16 wkday = 0;
    kal_uint16 hours = 0;
    kal_uint16 mins = 0;
    kal_uint16 secs = 0;
    kal_uint16 leap_year = 0;

    kal_char *str1, *str2, *pp;
    kal_uint32 i;
    kal_char date_str[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (date == NULL || strlen(date) > 99)
    {
        return KAL_FALSE;
    }
    else
    {
        strcpy(date_str, date);
    }
    if ((str1 = strchr(date_str, ',')) != NULL)
    {

        *str1 = '\0';
        str1++;

        /* The date_string may be rfc1123 or rfc850 date string */
        for (i = 0; i < 7; i++)
        {
            if (strcmp(date_str, weekday_c[i]) == 0 || strcmp(date_str, weekday_f[i]) == 0)
            {
                wkday = i;
                if (i == 0)
                {
                    wkday = 7;
                }
            }
        }
        if (wkday == 0) /* Wrong date format */
        {
            return KAL_FALSE;
        }

        str1++; /* Ingore one space */
        if (strchr(str1, '-') != NULL)
        {
            /* The date_string may be rfc850 date string */
            /* Retrieve day */
            if (NULL == (str2 = kal_strtok_r(str1, "-", &pp)))
            {
                return KAL_FALSE;
            }
            day = atoi(str2);

            /* Retrieve month */
            if (NULL == (str2 = kal_strtok_r(NULL, "-", &pp)))
            {
                return KAL_FALSE;
            }
            for (i = 0; i < 12; i++)
            {
                if (strcmp(str2, months_c[i]) == 0 || strcmp(str2, months_f[i]) == 0)
                {
                    month = i;
                    if (i == 0)
                    {
                        month = 12;
                    }
                }
            }
            if (month == 0) /* Wrong date format */
            {
                return KAL_FALSE;
            }
            /* Retrieve year */
            if (NULL == (str2 = kal_strtok_r(NULL, " ", &pp)))
            {
                return KAL_FALSE;
            }
            year = atoi(str2);

            if (year < 1970)
            {
                if (year >= 70)
                {
                    year += 1900;
                }
                else if (year <= 38)
                {
                    year += 2000;
                }
            }
        }
        else
        {
            /* The date_string may be rfc1123 date string */

            /* Retrieve day */
            if (NULL == (str2 = kal_strtok_r(str1, " ", &pp)))
            {
                return KAL_FALSE;
            }
            day = atoi(str2);

            /* Retrieve month */
            if (NULL == (str2 = kal_strtok_r(NULL, " ", &pp)))
            {
                return KAL_FALSE;
            }
            for (i = 0; i < 12; i++)
            {
                if (strcmp(str2, months_c[i]) == 0 || strcmp(str2, months_f[i]) == 0)
                {
                    month = i;
                    if (i == 0)
                    {
                        month = 12;
                    }
                }
            }
            if (month == 0) /* Wrong date format */
            {
                return KAL_FALSE;
            }
            /* Retrieve year */
            if (NULL == (str2 = kal_strtok_r(NULL, " ", &pp)))
            {
                return KAL_FALSE;
            }
            year = atoi(str2);
        }
    }
    else
    {
        /* The date_string may be asctime date string */

        /* Retrieve weekday */
        if (NULL == (str2 = kal_strtok_r(date_str, " ", &pp)))
        {
            return KAL_FALSE;
        }
        for (i = 0; i < 7; i++)
        {
            if (strcmp(str2, weekday_c[i]) == 0 || strcmp(str2, weekday_f[i]) == 0)
            {
                wkday = i;
                if (i == 0)
                {
                    wkday = 7;
                }
            }
        }
        if (wkday == 0) /* Wrong date format */
        {
            return KAL_FALSE;
        }
        /* Retrieve month */
        if (NULL == (str2 = kal_strtok_r(NULL, " ", &pp)))
        {
            return KAL_FALSE;
        }
        for (i = 0; i < 12; i++)
        {
            if (strcmp(str2, months_c[i]) == 0 || strcmp(str2, months_f[i]) == 0)
            {
                month = i;
                if (i == 0)
                {
                    month = 12;
                }
            }
        }
        if (month == 0) /* Wrong date format */
        {
            return KAL_FALSE;
        }

        /* Retrieve day */
        if (*pp == ' ')
        {
            pp++;   /* Ingore one space */
        }
        if (NULL == (str2 = kal_strtok_r(NULL, " ", &pp)))
        {
            return KAL_FALSE;
        }
        day = atoi(str2);

        if (NULL == (str2 = kal_strtok_r(NULL, " ", &pp)))
        {
            return KAL_FALSE;
        }
        if (pp == NULL)
        {
            return KAL_FALSE;
        }
        year = atoi(pp);
        pp = str2;
    }

    /* Retrieve hours */
    if (NULL == (str2 = kal_strtok_r(NULL, ":", &pp)))
    {
        return KAL_FALSE;
    }
    hours = atoi(str2);

    /* Retrieve mins */
    if (NULL == (str2 = kal_strtok_r(NULL, ":", &pp)))
    {
        return KAL_FALSE;
    }
    mins = atoi(str2);

    /* Retrieve secs */
    if (NULL == (str2 = kal_strtok_r(NULL, ":", &pp)))
    {
        return KAL_FALSE;
    }
    secs = atoi(str2);

    /* calculatet time seconds */
    if (year < 1970 || year > 2038)
    {
        return KAL_FALSE;
    }

    for (i = 1970; i <= year; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            leap_year++;
        }
    }
    year -= 1970;
    *time =
        year * 31536000 + (leap_year + accumulating_monthdays[month - 1] + day - 1) * 86400 + hours * 3600 + mins * 60 +
        secs;
    return KAL_TRUE;
}   /* applib_dt_rfc1123_rfc850_asctime_datestring2Time */


/*****************************************************************************
 * FUNCTION
 *  applib_dt_sec_utc_to_local
 * DESCRIPTION
 *  This function is used to convert utc time to local time, considering day light saving.
 * PARAMETERS
 *  utc_sec     [IN]        The time seconds of utc time from now to 1970/1/1,0:0:0
 * RETURNS
 *  The time seconds of local time from now to 1970/1/1,0:0:0
 *****************************************************************************/
kal_uint32 applib_dt_sec_utc_to_local(kal_uint32 utc_sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct utc_time, local_time;
    kal_uint32 result;
    float home_tz = GetTimeZone(PhnsetGetHomeCity());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_utc_sec_2_mytime(utc_sec, &utc_time, KAL_TRUE);
    applib_dt_utc_to_rtc(home_tz, &utc_time, &local_time);
    result = applib_dt_mytime_2_utc_sec(&local_time,KAL_FALSE);
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_sec_local_to_utc
 * DESCRIPTION
 *  This function is used to convert local time to utc time, considering day light saving.
 * PARAMETERS
 *  local_sec       [IN]        The time seconds of local time from now to 1970/1/1,0:0:0
 * RETURNS
 *  The time seconds of utc time from now to 1970/1/1,0:0:0
 *****************************************************************************/
kal_uint32 applib_dt_sec_local_to_utc(kal_uint32 local_sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct utc_time, local_time, inc_time;
    kal_uint32 result;
    float home_tz = (0 - GetTimeZone(PhnsetGetHomeCity()));
    kal_bool dst = applib_dt_is_dst_enabled();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_utc_sec_2_mytime(local_sec, &utc_time, KAL_TRUE);
    if (dst)
    {
        memset(&inc_time, 0, sizeof(applib_time_struct));
        inc_time.nHour = 2;
        applib_dt_decrease_time(&utc_time, &inc_time, &utc_time);
    }
    applib_dt_utc_to_rtc(home_tz, &utc_time, &local_time);
    result = applib_dt_mytime_2_utc_sec(&local_time, KAL_FALSE);
    return result;
}

extern kal_uint8 applib_dt_utc_sec_2_mytime(kal_uint32 utc_sec, applib_time_struct *result, kal_bool daylightSaving);


/*****************************************************************************
 * FUNCTION
 *  applib_dt_time2rfc1123dateString
 * DESCRIPTION
 *  This function is used to convert time to rfc1123 date string.
 * PARAMETERS
 *  gmt_time        [IN]            
 *  buffer          [IN/OUT]        The buffer to store the rfc1123 date string. The buffer size must be larger than 31bytes.
 *  time(?)         [IN]            The time seconds from now to 1970/1/1,0:0:0
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool applib_dt_time2rfc1123dateString(kal_uint32 gmt_time, kal_char *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct mytime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applib_dt_utc_sec_2_mytime((kal_int32) gmt_time, &mytime, KAL_TRUE) == KAL_FALSE)
    {
        return KAL_FALSE;
    }
    sprintf(
        buffer,
        "%s, %02d %s %04d %02d:%02d:%02d GMT",
        weekday_c[(((gmt_time / 86400) + 4) % 7)],
        mytime.nDay,
        months_c[mytime.nMonth],
        (mytime.nYear),
        mytime.nHour,
        mytime.nMin,
        mytime.nSec);

    return KAL_TRUE;
}   /* applib_dt_time2rfc1123dateString */


/*****************************************************************************
 * FUNCTION
 *  applib_dt_get_secure_time
 * DESCRIPTION
 *  Get secure RTC time of system.
 * PARAMETERS
 *  t       [IN/OUT]        Variable to store current time.
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_get_secure_time(applib_time_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for customer to provide specific secure clock mechanism */
    applib_dt_get_rtc_time(t);
}


/*****************************************************************************
 * FUNCTION
 *  applib_get_time_difference
 * DESCRIPTION
 *  Function to calculate the difference between 2 times.
 * PARAMETERS
 *  t1          [IN]            The target time
 *  t2          [IN]            The base time  (t1 shall be greater than t2)
 *  result      [IN/OUT]        Result of t1-t2
 * RETURNS
 *  NULL if t1 < t2; otherwise, return result
 *****************************************************************************/
applib_time_struct *applib_get_time_difference(
                        applib_time_struct *t1,
                        applib_time_struct *t2,
                        applib_time_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Validate year ..no need of validating for month .. */
    /* /Handled NULL  changes by Kuldeep for Network Simulator 2.0 */
    if (NULL == t2)
    {
        return NULL;
    }
    /* /Handled NULL  changes by Kuldeep */
    if (t1->nYear < t2->nYear)
    {
        return NULL;
    }
    else
    {
        applib_dt_2time_decreament(*t1, *t2, result);
        return result;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_get_time_difference_ext
 * DESCRIPTION
 *  Function to calculate the difference between 2 times.
 *  This function can handle the case of t1 < t2 
 *  ex: t2 is 2001/xx/xx because of overflow.
 * PARAMETERS
 *  t1          [IN]            The target time
 *  t2          [IN]            The base time  (t1 shall be greater than t2)
 *  result      [IN/OUT]        Result of t1-t2
 * RETURNS
 *  NULL if t1 < t2; otherwise, return result
 *****************************************************************************/
applib_time_struct *applib_get_time_difference_ext(
                        applib_time_struct *t1,
                        applib_time_struct *t2,
                        applib_time_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct max_rtc, min_rtc;
    kal_uint32 max, min, temp;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Validate year ..no need of validating for month .. */
    /* /Handled NULL  changes by Kuldeep for Network Simulator 2.0 */
    if (NULL == t2)
    {
        return NULL;
    }
    /* /Handled NULL  changes by Kuldeep */
    if (t1->nYear < t2->nYear)
    {
        max_rtc.nYear = DT_MAX_YEAR;
        max_rtc.nMonth = 12;
        max_rtc.nDay = 31;
        max_rtc.nHour = 23;
        max_rtc.nMin =59;
        max_rtc.nSec = 59;  
        max = applib_dt_mytime_2_utc_sec(&max_rtc, KAL_FALSE);
        temp = max - applib_dt_mytime_2_utc_sec(t2, KAL_FALSE);

        min_rtc.nYear = DT_MIN_YEAR;
        min_rtc.nMonth = 1;
        min_rtc.nDay = 1;
        min_rtc.nHour = 0;
        min_rtc.nMin = 0;
        min_rtc.nSec = 0;        
        if (applib_find_max_time(t1, &min_rtc))
        {
            min = applib_dt_mytime_2_utc_sec(&min_rtc, KAL_FALSE);
            temp += (applib_dt_mytime_2_utc_sec(t1, KAL_FALSE) - min) + 1;
        }
        
        applib_dt_utc_sec_2_mytime(temp, result, KAL_FALSE);
        result->nYear -= DT_UTC_BASE_YEAR;
		result->nMonth -= 1;
		result->nDay -= 1;                
    }
    else
    {
        applib_dt_2time_decreament(*t1, *t2, result);
    }
	return result;
}

/*****************************************************************************
 * FUNCTION
 *  applib_dt_2time_decreament
 * DESCRIPTION
 *  Decrease a reference time by some time.
 *  The difference between DecrementTime is the result may not be a "time"
 *  Because it's just to get the "difference", the time may be 1 month, 0 day, 12 minutes,
 *  and it is for internal use. To get time difference should take use of applib_get_time_difference.
 * PARAMETERS
 *  timeToDecrement     [IN]            Time to be decreased
 *  decrement           [IN]            Time to decrease
 *  Result              [IN/OUT]        Result of compuatation
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_2time_decreament(
        applib_time_struct timeToDecrement,
        applib_time_struct decrement,
        applib_time_struct *Result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (decrement.nSec != 0)
    {
        if (timeToDecrement.nSec >= decrement.nSec)
        {
            Result->nSec = timeToDecrement.nSec - decrement.nSec;
        }
        else
        {
            Result->nSec = NUM_MIN_HR + timeToDecrement.nSec - decrement.nSec;
            decrement.nMin++;
        }
    }
    else
    {
        Result->nSec = timeToDecrement.nSec;
    }

    if (decrement.nMin != 0)
    {
        if (timeToDecrement.nMin >= decrement.nMin)
        {
            Result->nMin = timeToDecrement.nMin - decrement.nMin;
        }
        else
        {
            Result->nMin = NUM_MIN_HR + timeToDecrement.nMin - decrement.nMin;
            decrement.nHour++;
        }
    }
    else
    {
        Result->nMin = timeToDecrement.nMin;
    }

    if (decrement.nHour != 0)
    {
        if (timeToDecrement.nHour >= decrement.nHour)
        {
            Result->nHour = timeToDecrement.nHour - decrement.nHour;
        }
        else
        {
            Result->nHour = NUM_HRS_DAY + timeToDecrement.nHour - decrement.nHour;
            decrement.nDay++;
        }
    }
    else
    {
        Result->nHour = timeToDecrement.nHour;
    }

    if (decrement.nDay != 0)
    {
        if (timeToDecrement.nDay >= decrement.nDay)
        {
            Result->nDay = timeToDecrement.nDay - decrement.nDay;
        }
        else
        {
            kal_uint8 tmp_last_day;

            decrement.nMonth++;
            if (timeToDecrement.nMonth != JAN)
            {
                tmp_last_day = applib_dt_last_day_of_mon((kal_uint8) (timeToDecrement.nMonth - 1), timeToDecrement.nYear);
            }
            else
            {
                tmp_last_day = 31;
            }

            if (tmp_last_day < (tmp_last_day + timeToDecrement.nDay - decrement.nDay))
            {
                if (DEC == timeToDecrement.nMonth)
                {
                    tmp_last_day += 31;
                }
                else
                {
                    tmp_last_day += applib_dt_last_day_of_mon((kal_uint8) (timeToDecrement.nMonth), timeToDecrement.nYear);
                }
                decrement.nMonth++;
            }

            Result->nDay = tmp_last_day + timeToDecrement.nDay - decrement.nDay;
        }
    }
    else
    {
        Result->nDay = timeToDecrement.nDay;
    }

    if (decrement.nMonth != 0)
    {
        if (timeToDecrement.nMonth >= decrement.nMonth)
        {
            Result->nMonth = timeToDecrement.nMonth - decrement.nMonth;
        }
        else
        {
            Result->nMonth = NUM_MONTHS + timeToDecrement.nMonth - decrement.nMonth;
            decrement.nYear++;
        }
    }
    else
    {
        Result->nMonth = timeToDecrement.nMonth;
    }

    Result->nYear = timeToDecrement.nYear - decrement.nYear;

    Result->DayIndex = applib_dt_dow(Result->nYear, Result->nMonth, Result->nDay);
}


/*****************************************************************************
 * FUNCTION
 *  applib_get_time_difference_ext_in_second
 * DESCRIPTION
 *  Function to calculate the difference between 2 times in second.
 *  This function can handle the case of t1 < t2 
 *  ex: t2 is 2001/xx/xx because of overflow.
 * PARAMETERS
 *  t1          [IN]            The target time
 *  t2          [IN]            The base time  (t1 shall be greater than t2)
 * RETURNS
 *  the difference between these two times
 *****************************************************************************/
kal_uint32 applib_get_time_difference_ext_in_second(
                        applib_time_struct *t1,
                        applib_time_struct *t2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct max_rtc, min_rtc;
    kal_uint32 max, min, diff = 0;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == t2)
    {
        return NULL;
    }

    if (t1->nYear < t2->nYear)
    {
        max_rtc.nYear = DT_MAX_YEAR;
        max_rtc.nMonth = 12;
        max_rtc.nDay = 31;
        max_rtc.nHour = 23;
        max_rtc.nMin =59;
        max_rtc.nSec = 59;  
        max = applib_dt_mytime_2_utc_sec(&max_rtc, KAL_FALSE);
        diff = max - applib_dt_mytime_2_utc_sec(t2, KAL_FALSE);

        min_rtc.nYear = DT_MIN_YEAR;
        min_rtc.nMonth = 1;
        min_rtc.nDay = 1;
        min_rtc.nHour = 0;
        min_rtc.nMin = 0;
        min_rtc.nSec = 0;        
        if (applib_find_max_time(t1, &min_rtc))
        {
            min = applib_dt_mytime_2_utc_sec(&min_rtc, KAL_FALSE);
            diff += (applib_dt_mytime_2_utc_sec(t1, KAL_FALSE) - min) + 1;
        }              
    }
    else
    {
        diff = applib_dt_mytime_2_utc_sec(t1, KAL_FALSE) - applib_dt_mytime_2_utc_sec(t2, KAL_FALSE);
    }
	return diff;
}


/*****************************************************************************
 * FUNCTION
 *  applib_find_max_time
 * DESCRIPTION
 *  Function to find the larger one between two times
 * PARAMETERS
 *  t1      [IN]        The first time to be compared.
 *  t2      [IN]        The second time to be compared.
 * RETURNS
 *  0 if t1 < t2; otherwise 1.
 *****************************************************************************/
kal_uint16 applib_find_max_time(applib_time_struct *t1, applib_time_struct *t2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (t1->nYear == t2->nYear)
    {
        if (t1->nMonth == t2->nMonth)
        {
            if (t1->nDay == t2->nDay)
            {
                if (t1->nHour == t2->nHour)
                {
                    if (t1->nMin == t2->nMin)
                    {
                        if (t1->nSec >= t2->nSec)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else if (t1->nMin > t2->nMin)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (t1->nHour > t2->nHour)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if (t1->nDay > t2->nDay)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (t1->nMonth > t2->nMonth)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (t1->nYear > t2->nYear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef __MTK_TARGET__


/*****************************************************************************
 * FUNCTION
 *  MyMonth
 * DESCRIPTION
 *  Fucntion to update year and month, this function is used in PC simulator only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MyMonth()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MyTime.nMonth == 12)
    {
        MyTime.nMonth = 1;
        MyTime.nYear++;
    }
    else
    {
        MyTime.nMonth++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DateTimerProc
 * DESCRIPTION
 *  Fucntion to update and display date and time. This function is used in PC simulator only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DateTimerProc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    kal_int32 CompareDay = 28;
    kal_int16 isLeapYear = 0;
    kal_uint8 nDateChanged = 0x0;
    kal_uint8 update_flag = 0;

/********************************************************
Patch for the demo:: Min_Change_flag has been added to support low power mode.
(May be we should have timer for 60 seconds).
**********************************************************/
    kal_int32 Min_Change_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(TIMER_REAL_TIME_CLOCK, 1000, DateTimerProc); /* 072605 Calvin added */

    if (MyTime.nSec == 59)
    {
        MyTime.nSec = 0;
        Min_Change_flag = 1;
        update_flag = 1;
        if (MyTime.nMin == 59)
        {
            MyTime.nMin = 0;
            if (MyTime.nHour == 23)
            {
                MyTime.nHour = 0;
                nDateChanged = 0x1;
                update_flag = 1;
                if (MyTime.DayIndex == 6)
                {
                    MyTime.DayIndex = 0;
                }
                else
                {
                    MyTime.DayIndex++;
                }
                switch (MyTime.nMonth)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if (MyTime.nDay == 31)
                        {
                            MyTime.nDay = 1;
                            MyMonth();
                        }
                        else
                        {
                            MyTime.nDay++;
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if (MyTime.nDay == 30)
                        {
                            MyTime.nDay = 1;
                            MyMonth();
                        }
                        else
                        {
                            MyTime.nDay++;
                        }
                        break;
                    case 2: /* Check for leap year */
                        if (((MyTime.nYear % 100) == 0) && ((MyTime.nYear % 400) == 0))
                        {
                            isLeapYear = 1;
                        }
                        else if ((MyTime.nYear % 4) == 0)
                        {
                            isLeapYear = 1;
                        }
                        else    /* Not a leap year */
                        {
                            isLeapYear = 0;
                        }
                        if (isLeapYear)
                        {
                            CompareDay = 29;
                        }
                        else
                        {
                            CompareDay = 28;
                        }
                        /* (isLeapYear) ? CompareDay = 29 : CompareDay = 28; */
                        if (MyTime.nDay == CompareDay)
                        {
                            MyTime.nDay = 1;
                            MyMonth();
                        }
                        else
                        {
                            MyTime.nDay++;
                        }
                        break;
                    default:
                        break;
                }
                //Right now only for time...need to expand to accommodate year and month
                //update
            }
            else
            {
                MyTime.nHour++;
            }
        }
        else
        {
            MyTime.nMin++;
        }
    }
    else
    {
        MyTime.nSec++;
    }
    //sprintf(DateTimeStrings[0],"%s %02d %s %d",NameOfday[MyTime.DayIndex],MyTime.nDay,NameOfMonth[MyTime.nMonth-1],MyTime.nYear);
    //sprintf(DateTimeStrings[1],"%02d:%02d:%02d",MyTime.nHour,MyTime.nMin,MyTime.nSec); 
    if (update_flag)
    {   /* Lisen0522 */
        update_mainlcd_dt_display();
        update_sublcd_dt_display();
    }
    /*  */
}

#endif /* __MTK_TARGET__ */ 

/*****************************************************************************
 * FUNCTION
 *  applib_dt_init_time
 * DESCRIPTION
 *  Function to initialize golbal variables and local date and time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_init_time(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DAILY_WALLPAPER__
    memset(&gWallpaperChangeDate, 0xFF, sizeof(gWallpaperChangeDate));  /* Robin 1226 */
#endif 
#elif __MMI_ON_WIN32__
    SYSTEMTIME systime;
    long ltime;
    kal_int8 MyDay[4];
    kal_int16 i;

    GetLocalTime(&systime);
    time(&ltime);
    strncpy(MyDay, ctime(&ltime), 3);
    /* stack corruption fixed Kuldeep for Network Simulator 2.0 */
    MyDay[3] = '\0';
    /* changes done by Kuldeep */

    for (i = 0; i < 7; i++)
    {
        if (strncmp(MyDay, NameOfday[i], 3) == 0)
        {
            break;
        }
    }

    MyTime.nYear = systime.wYear;
    MyTime.nMonth = (U8) systime.wMonth;
    MyTime.nDay = (U8) systime.wDay;
    MyTime.nHour = (U8) systime.wHour;
    MyTime.nMin = (U8) systime.wMinute;
    MyTime.nSec = (U8) systime.wSecond;
    MyTime.DayIndex = (U8) i;

    sprintf(
        DateTimeStrings[0],
        "%s  %02d %s  %d",
        NameOfday[MyTime.DayIndex],
        MyTime.nDay,
        NameOfMonth[MyTime.nMonth - 1],
        MyTime.nYear);
    //sprintf(DateTimeStrings[1],"%02d::%02d::%02d",MyTime.nHour,MyTime.nMin,MyTime.nSec);
    //sprintf(DateTimeStrings[1],"%02d:%02d",MyTime.nHour,MyTime.nMin);
    StartTimer(TIMER_REAL_TIME_CLOCK, 1000, DateTimerProc);
#else 
    MyTime.nYear += YEARFORMATE;
    StartTimer(TIMER_REAL_TIME_CLOCK, 1000, DateTimerProc);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_get_date_time
 * DESCRIPTION
 *  Function to get the current date and time.
 * PARAMETERS
 *  t       [IN/OUT]        Variable to store the result.
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_get_date_time(applib_time_struct *t)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->nSec = gclockData.rtc_sec;
    t->nMin = gclockData.rtc_min;
    t->nHour = gclockData.rtc_hour;
    t->nDay = gclockData.rtc_day;
    t->nMonth = gclockData.rtc_mon;
    t->DayIndex = gclockData.rtc_wday;
    t->nYear = YEARFORMATE + gclockData.rtc_year;
#else /* __MTK_TARGET__ */ 
    t->DayIndex = MyTime.DayIndex;
    t->nDay = MyTime.nDay;
    t->nHour = MyTime.nHour;
    t->nMin = MyTime.nMin;
    t->nSec = MyTime.nSec;
    t->nMonth = MyTime.nMonth;
    t->nYear = MyTime.nYear;
#endif /* __MTK_TARGET__ */ 
    t->DayIndex = applib_dt_dow(t->nYear, t->nMonth, t->nDay);
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_get_rtc_time
 * DESCRIPTION
 *  Get current RTC time of system.
 * PARAMETERS
 *  t       [IN/OUT]        Variable to store current time.
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_get_rtc_time(applib_time_struct *t)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc rtc_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RTC_GetTime(&rtc_time);

    t->nYear = rtc_time.rtc_year + YEARFORMATE;
    t->nMonth = rtc_time.rtc_mon;
    t->nDay = rtc_time.rtc_day;
    t->nHour = rtc_time.rtc_hour;
    t->nMin = rtc_time.rtc_min;
    t->nSec = rtc_time.rtc_sec;
    t->DayIndex = applib_dt_dow(t->nYear, t->nMonth, t->nDay);
#else /* __MTK_TARGET__ */ 
    applib_dt_get_date_time(&(*t));
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_get_rtc_without_daylight_impact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_get_rtc_without_daylight_impact(applib_time_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 dst;
    applib_time_struct decreaseDST;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(t);
    dst = applib_dt_is_dst_enabled();

    if (dst)
    {
        memset(&decreaseDST, 0, sizeof(applib_time_struct));
        decreaseDST.nHour = 1;

        applib_dt_decrease_time(t, &decreaseDST, t);
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_modify_dt_with_daylight_impact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void applib_dt_modify_dt_with_daylight_impact(applib_time_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 dst;
    applib_time_struct increaseDST;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst = applib_dt_is_dst_enabled();

    if (dst)
    {
        memset(&increaseDST, 0, sizeof(applib_time_struct));
        increaseDST.nHour = 1;

        applib_dt_increase_time(t, &increaseDST, t);
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_dt_get_week_number
 * DESCRIPTION
 *  Compute the week number of a date
 * PARAMETERS
 *  date        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 applib_dt_get_week_number(applib_time_struct *date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i, no_of_days, week_num, numdays_inmonth, day_on_firstjan;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    no_of_days = date->nDay;

    for (i = date->nMonth - 1; i > 0; i--)
    {

        /* get the num of days in todays month */
        numdays_inmonth = applib_dt_last_day_of_mon((kal_uint8) i, date->nYear);
        no_of_days += numdays_inmonth;
    }

    day_on_firstjan = applib_dt_dow(date->nYear, 1, 1);

    /* Total no of days/ weekdays */
    no_of_days += day_on_firstjan;

    week_num = (no_of_days) / DT_DAYS_OF_WEEK;
    if ((no_of_days) % DT_DAYS_OF_WEEK > 0)
    {
        week_num += 1;
    }

    ASSERT(week_num <= CLNDR_MAX_WEEK_NUM);
    return week_num;

}

/*
 * Returns the time since the Epoch (00:00:00 UTC, January 1, 1970),
 * measured in seconds.
 */
kal_uint32 app_getcurrtime(void)
{
    kal_uint32 secs;

#ifdef __MTK_TARGET__
    t_rtc rtc;
    struct tm when;

    RTC_GetTime(&rtc);
    /* RTC_GetTime() returns the timestamp of current time.
     * the returned 'year' counts from 2000, i.e., for year 2004, year is 4 */
    when.tm_sec = rtc.rtc_sec;
    when.tm_min = rtc.rtc_min;
    when.tm_hour = rtc.rtc_hour;
    when.tm_mday = rtc.rtc_day;
    when.tm_mon = rtc.rtc_mon - 1;
    /* mktime() expects the yeaer counting from 1900,
     * and returns total seconds elapsed since 1970.01.01 midnight */
    when.tm_year = rtc.rtc_year + (2000-1900);
    when.tm_isdst = 0;
    secs = (kal_uint32)mktime(&when);

#else /* !__MTK_TARGET__ */ 
    kal_uint32 ltime;
    secs = (kal_uint32)time(&ltime);
#endif /* !__MTK_TARGET__ */ 

    return secs;
}


