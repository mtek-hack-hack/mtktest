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
 * DateTime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * This file implements date/time related utilities for other applications
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2004
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * DateTime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements date/time related utilities for other applications
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
/**************************************************************

   FILENAME : DateTime.c

   PURPOSE     : Utility functions to enable date and time display on idle screen

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma, Vijay Vaidya

   DATE     : Aug' 28, 2002

**************************************************************/

#include "MMI_include.h"
#ifndef _MMI_DATETIME_C
#define _MMI_DATETIME_C

/*  Include: MMI header file */
#include "Stdafx.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"
#include <time.h>
#include "rtc_sw.h"

#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "AlarmFrameworkProt.h"
#include "SettingStructs.h"
#include "ProtocolEvents.h"

#ifdef __MMI_LCD_PARTIAL_ON__
#include "IdleAppProt.h"
#endif 

/*  Include: PS header file */

/* 
 * Define
 */
#define  DT_UTC_BASE_YEAR  1970
#define  DT_MONTH_PER_YEAR    12
#define  DT_DAY_PER_YEAR         365
#define  DT_SEC_PER_DAY    86400
#define  DT_SEC_PER_HOUR      3600
#define  DT_SEC_PER_MIN    60
#define MMI_DT_YEAR_BOUNDARY     30
/* 
 * Typedef 
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */
static void DTResetTime(void);

/* 
 * Global Variable
 */
/* extern U8 idleScreenFirst; */
U8 CMDateTimeRequest = 0;
U8 CMCallCount = 0;
U8 CMCallBackCount = 0;
extern U8 g_dst;
DateTimeFuncPtr CMDateTimeCallBack[MAX_CM_CALLS];

#ifndef __MTK_TARGET__
extern MYTIME MyTime;
#endif 
extern rtc_format_struct gclockData;

#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
extern BOOL gIsInSleepMode;
#endif 
/* 
 * Global Function
 */
extern FLOAT GetTimeZone(U8);
extern U8 PhnsetGetHomeCity(void);

/*****************************************************************************
 * FUNCTION
 *  CMGetExactTime
 * DESCRIPTION
 *  Used by CM to get the Exact Time. Asyncronous Call. Callback is passeds
 * PARAMETERS
 *  callback        [IN]        Callback function to be called when get time response comes back
 * RETURNS
 *  void
 *****************************************************************************/
void CMGetExactTime(DateTimeFuncPtr callback)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        /* MYTIME curtime;
           DTGetRTCTime(&curtime);
           callback(&curtime); */
        PRINT_INFORMATION("<<** CMGetExactTime ** >> CMCallCount = %d, CMCallBackCount = %d\n", CMCallCount,
                           CMCallBackCount);
        CMDateTimeRequest++;
        CMDateTimeCallBack[CMCallCount++] = callback;
        if (CMCallCount == MAX_CM_CALLS)
        {
            CMCallCount = 0;
        }
        L4GetClockTime(CMGetExactTimeCB);

    }
#else /* __MTK_TARGET__ */ 
    {
        CMDateTimeRequest++;
        CMDateTimeCallBack[CMCallCount++] = callback;
        if (CMCallCount == MAX_CM_CALLS)
        {
            CMCallCount = 0;
        }
        StartTimer(CM_GET_TIME_CALLBACK, 1000, CMCallBackTimer);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  CMGetExactTimeCB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CMGetExactTimeCB(void *buf)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_rtc_time_rsp_struct *local_data = (mmi_eq_get_rtc_time_rsp_struct*) buf;

    /* Lisen0522 */
    extern void update_mainlcd_dt_display(void);
    extern void update_sublcd_dt_display(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDateTime(&(local_data->rtctime[0].data_time));
    /* gclockData.rtc_wday = local_data->rtctime[0].data_time.rtc_wday;
       gclockData.rtc_year = local_data->rtctime[0].data_time.rtc_year,
       gclockData.rtc_mon = local_data->rtctime[0].data_time.rtc_mon,
       gclockData.rtc_day = local_data->rtctime[0].data_time.rtc_day,
       gclockData.rtc_hour = local_data->rtctime[0].data_time.rtc_hour,
       gclockData.rtc_min = local_data->rtctime[0].data_time.rtc_min,
       gclockData.rtc_sec = local_data->rtctime[0].data_time.rtc_sec; */

    PRINT_INFORMATION("<<** CMGetExactTimeCB ** >>\n");

    if (CMDateTimeRequest > 0)
    {
        MYTIME curtime;

        PRINT_INFORMATION("<<** CMGetExactTimeCB ** >> CMCallCount = %d, CMCallBackCount = %d\n", CMCallCount,
                           CMCallBackCount);

        GetDateTime(&curtime);
        CMDateTimeCallBack[CMCallBackCount++] (&curtime);
        if (CMCallBackCount == MAX_CM_CALLS)
        {
            CMCallBackCount = 0;
        }
        CMDateTimeRequest--;
        return;
    }

    /* Lisen0522 */
    update_mainlcd_dt_display();
    update_sublcd_dt_display();
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  CMCallBackTimer
 * DESCRIPTION
 *  Used to simulate CM time function on widows. Calls CM Callback function as set by CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CMCallBackTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CMDateTimeRequest)
    {
        MYTIME curtime;

        GetDateTime(&curtime);
        CMDateTimeCallBack[CMCallBackCount++] (&curtime);
        if (CMCallBackCount == MAX_CM_CALLS)
        {
            CMCallBackCount = 0;
        }
        CMDateTimeRequest--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_get_tz
 * DESCRIPTION
 *  Get current time zone of MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  time zone of current home city.
 *****************************************************************************/
FLOAT mmi_dt_get_tz(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetTimeZone(PhnsetGetHomeCity());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_set_dst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_set_dst(U8 dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_SETTING_DT_DST, &dst, DS_BYTE, &error);
    g_dst = (U8) dst;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_set_rtc_dt
 * DESCRIPTION
 *  This function is to send set time request to L4
 *  Functionality:
 * PARAMETERS
 *  t       [?]     [?]
 *  a(?)        [IN/OUT](?)
 *  b(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_set_rtc_dt(MYTIME *t)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    RTCTIMEFORMAT *time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time = OslConstructDataPtr(sizeof(RTCTIMEFORMAT));
    time->info.alarm_format = 0;
    time->info.alarm_index = 0;
    time->info.type = 0;
    time->info.text[0] = '\0';
    time->info.recurr = 0;
    time->info.data_time.rtc_sec = 0;
    time->info.data_time.rtc_min = t->nMin;
    time->info.data_time.rtc_hour = t->nHour;

    time->rtc_type = RTC_TIME_CLOCK_IND;
    time->set_type = RTC_SETTING_TYPE_DATETIME;
    time->info.data_time.rtc_day = t->nDay;
    time->info.data_time.rtc_mon = t->nMonth;
    time->info.data_time.rtc_year = t->nYear - YEARFORMATE;
    time->info.data_time.rtc_wday = applib_dt_dow(t->nYear, t->nMonth, t->nDay);

    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = HW_SET_TIME_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) time;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
#else /* __MTK_TARGET__ */ 
    MyTime = *t;
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  SetDateTime
 * DESCRIPTION
 *  Function to set date and time information to global variable of MMI
 * PARAMETERS
 *  t       [IN]        Struct variable that stores date and time information from PS
 * RETURNS
 *  void
 *****************************************************************************/
void SetDateTime(void *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rtc_format_struct *local_data = (rtc_format_struct*) t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__

    gclockData.rtc_wday = local_data->rtc_wday;
    gclockData.rtc_year = local_data->rtc_year;
    gclockData.rtc_mon = local_data->rtc_mon;
    gclockData.rtc_day = local_data->rtc_day;
    gclockData.rtc_hour = local_data->rtc_hour;
    gclockData.rtc_min = local_data->rtc_min;
    gclockData.rtc_sec = local_data->rtc_sec;

    if (gclockData.rtc_year > MMI_DT_YEAR_BOUNDARY)
    {
        gclockData.rtc_year = 0;    /* reset to 2000 */
        DTResetTime();
    }
#else /* __MTK_TARGET__ */ 
    MyTime.DayIndex = local_data->rtc_wday;
    MyTime.nYear = local_data->rtc_year;
    MyTime.nMonth = local_data->rtc_mon;
    MyTime.nDay = local_data->rtc_day;
    MyTime.nHour = local_data->rtc_hour;
    MyTime.nMin = local_data->rtc_min;
    MyTime.nSec = local_data->rtc_sec;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  DTResetTimeRsp
 * DESCRIPTION
 *  Response handler of reset date/time.
 * PARAMETERS
 *  rsp     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void DTResetTimeRsp(void *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmReInitialize();
    SetProtocolEventHandler(L4SetClockRSP, MSG_ID_MMI_EQ_SET_RTC_TIME_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  DTResetTime
 * DESCRIPTION
 *  Reset Date/Time function when time reaches boundary
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void DTResetTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    mmi_eq_set_rtc_time_req_struct *time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time = OslConstructDataPtr(sizeof(mmi_eq_set_rtc_time_req_struct));
    time->info.alarm_format = 0;
    time->info.alarm_index = 0;
    time->info.type = 0;
    time->info.text[0] = '\0';
    time->info.recurr = 0;

    time->rtc_type = RTC_TIME_CLOCK_IND;
    time->set_type = RTC_SETTING_TYPE_DATETIME;
    time->info.data_time.rtc_sec = 0;
    time->info.data_time.rtc_min = gclockData.rtc_min;
    time->info.data_time.rtc_hour = gclockData.rtc_hour;
    time->info.data_time.rtc_day = gclockData.rtc_day;
    time->info.data_time.rtc_mon = gclockData.rtc_mon;
    time->info.data_time.rtc_wday = gclockData.rtc_wday;
    time->info.data_time.rtc_year = gclockData.rtc_year;

    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = MSG_ID_MMI_EQ_SET_RTC_TIME_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) time;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);

    SetProtocolEventHandler(DTResetTimeRsp, MSG_ID_MMI_EQ_SET_RTC_TIME_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  DateTimerIndication
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EQ_CLOCK_TICK_IND.
 *  1. Update global variable in MMI.
 *  2. Update date/time display in IDLE screen.
 * PARAMETERS
 *  p       [?]     [?]
 *  t(?)        [IN]        Struct variable that stores date and time information from PS(?)
 * RETURNS
 *  void
 *****************************************************************************/
void DateTimerIndication(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__
    mmi_eq_clock_tick_ind_struct *local_data = (mmi_eq_clock_tick_ind_struct*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gclockData.rtc_wday = local_data->rtc_time.rtc_wday;
    gclockData.rtc_year = local_data->rtc_time.rtc_year;
    gclockData.rtc_mon = local_data->rtc_time.rtc_mon;
    gclockData.rtc_day = local_data->rtc_time.rtc_day;
    gclockData.rtc_hour = local_data->rtc_time.rtc_hour;
    gclockData.rtc_min = local_data->rtc_time.rtc_min;
    gclockData.rtc_sec = local_data->rtc_time.rtc_sec;

    if (gclockData.rtc_year > MMI_DT_YEAR_BOUNDARY)
    {
        gclockData.rtc_year = 0;    /* reset to 2000 */
        DTResetTime();
    }

#ifdef __DAILY_WALLPAPER__
    if ((mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE) && (GetWallpaperRotateStatus() == MMI_TRUE))
    {
        if (gWallpaperChangeDate.rtc_year == 0xFF
            || gWallpaperChangeDate.rtc_mon == 0xFF || gWallpaperChangeDate.rtc_day == 0xFF)
        {
            gWallpaperChangeDate.rtc_wday = gclockData.rtc_wday;
            gWallpaperChangeDate.rtc_year = gclockData.rtc_year;
            gWallpaperChangeDate.rtc_mon = gclockData.rtc_mon;
            gWallpaperChangeDate.rtc_day = gclockData.rtc_day;
            gWallpaperChangeDate.rtc_hour = gclockData.rtc_hour;
            gWallpaperChangeDate.rtc_min = gclockData.rtc_min;
            gWallpaperChangeDate.rtc_sec = gclockData.rtc_sec;
        }
        else if (gWallpaperChangeDate.rtc_year != gclockData.rtc_year
                 || gWallpaperChangeDate.rtc_mon != gclockData.rtc_mon
                 || gWallpaperChangeDate.rtc_day != gclockData.rtc_day)
        {
            /* S16 error; */
            WallPaperDailyChange();
            gWallpaperChangeDate.rtc_wday = gclockData.rtc_wday;
            gWallpaperChangeDate.rtc_year = gclockData.rtc_year;
            gWallpaperChangeDate.rtc_mon = gclockData.rtc_mon;
            gWallpaperChangeDate.rtc_day = gclockData.rtc_day;
            gWallpaperChangeDate.rtc_hour = gclockData.rtc_hour;
            gWallpaperChangeDate.rtc_min = gclockData.rtc_min;
            gWallpaperChangeDate.rtc_sec = gclockData.rtc_sec;
            /* WriteRecord(NVRAM_MMI_EF_WALLPAPER_MODTIME_LID,1,(void *)&gWallpaperChangeDate, sizeof(gWallpaperChangeDate), &error); */
        }
    }
#endif /* __DAILY_WALLPAPER__ */ 

#ifdef __MMI_LCD_PARTIAL_ON__
    if ((mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE) || mmi_bootup_is_sim_removed() == MMI_TRUE)
    {
        RedrawPartialOnScreenSaverIfOk();
    }
#endif /* __MMI_LCD_PARTIAL_ON__ */ 

    /* Lisen0522 */
#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
    if (gIsInSleepMode == KAL_FALSE)
    {
        update_mainlcd_dt_display();
    }
#else /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
    update_mainlcd_dt_display();
#endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
    update_sublcd_dt_display();

#else /* __MTK_TARGET__ */ 
    DateTimerProc();
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dt_check_rtc_time
 * DESCRIPTION
 * Check if rtc time is valid
 * PARAMETERS
 *  p       [?]     [?]
 *  t(?)        [IN]        Struct variable that stores date and time information from PS(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_check_rtc_time(void)
{
    if (gclockData.rtc_year > MMI_DT_YEAR_BOUNDARY)
    {
        gclockData.rtc_year = 0;    /* reset to 2000 */
        DTResetTime();
    }
}
#endif /* _MMI_DATETIME_C */ // #ifndef _MMI_DATETIME_C
