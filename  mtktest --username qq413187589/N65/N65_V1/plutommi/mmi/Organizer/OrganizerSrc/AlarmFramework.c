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
 * AlarmFramework.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements alarm scheduler for alarm, to do list, schedule power on/off and theme.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/**************************************************************

   FILENAME : AlarmFramework.c

   PURPOSE     : Alarm Application

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma

   DATE     : Jun 16,03

**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_ALARMFRAMEWORK_C
#define _MMI_ALARMFRAMEWORK_C

/*  Include: MMI header file */

/* to be put in include path TBDGS */
#include "AlarmProt.h"
#include "AlarmGProt.h"
#include "DateTimeGprot.h"
#include "AlarmFrameworkProt.h"
#include "ScheduledPowerOnOffGprot.h"
#include "gpioInc.h"
#include "ProfileGprots.h"
#include "MMIThemes.h"
#include "ProtocolEvents.h"
#include "AsyncEventsGprot.h"
#include "SettingGprots.h"
#include "ComposeRingToneProts.h"
#include "DownloadProtos.h"
#include "PowerOnChargerProt.h"
// #include "PopulateResGprot.h"
#include "ScheduledPowerOnOff.h"
#include "ToDoListDef.h"
#include "ToDoListEnum.h"
#include "WrapperGprot.h"
#include "AudioInc.h"
#include "IdleAppProt.h"
#include <time.h>
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "resource_audio.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "sublcd.h"

#include "JavaAgencyDef.h"
/*  Include: PS header file */
//... Add More PS header
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "Bootup.h"
// #include "MMITaskProt.h"
#include "USBDeviceGprot.h"
#include "USBDeviceDefs.h"      /* __USB_IN_NORMAL_MODE__ */
#include "CallManagementGprot.h" /*IsWapCallPresent*/

#if defined(__MMI_ALM_AUDIO_OPTIONS__)
#include "FMRadioDef.h"
#include "FMRadioProt.h"
#include "FMRadioType.h"
extern mmi_fmrdo_struct g_fmrdo;
#endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) */ 

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
#include "FMScheduleRecProt.h"
#endif 
#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))
#include "SyncMLGprot.h"
#endif
#include "SSCStringHandle.h"
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif /*__MMI_UCM__*/
/* 
 * Typedef 
 */

/* 
 * Define
 */
#define ALM_AFTER_CM_DURATUION 5000
#define ALM_MAX_DELAY_ALLOWANCE  ((NUM_OF_SPOF + NUM_OF_ALM + NUM_OF_TDL) / 2 +1)       /* maximum delay of each alarm */
#define ALM_TOLERANCE_TIME       10000
#define ALM_POWER_OFF_TOLERANCE  (POWER_OFF_TIMER_STAGE_1 + POWER_OFF_TIMER_STAGE_2 + ALM_TOLERANCE_TIME)

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
AlarmCallback gAlmCBHandler[ALM_TYPE_TOTAL_NUM];
alm_queue_node_struct gAlmQueue[ALM_NUM_OF_ALAMRS];
alm_framework_context_struct g_alm_frm_cntx;

#ifdef __MMI_FACTORY_MODE__
extern U8 gFactoryAlarm;
#endif 

extern kal_uint16 *MainLCD_ShadowBuf_p;
extern kal_uint16 *SubLCD_ShadowBuf_p;
extern U8 gFScheckdiskflag;
extern rtc_format_struct gclockData;

const U8 gAlmDayOfWeek[] = 
{
    0x01,   /* DAY_SUN */
    0x02,   /* DAY_MON */
    0x04,   /* DAY_TUE */
    0x08,   /* DAY_WED */
    0x10,   /* DAY_THU */
    0x20,   /* DAY_FRI */
    0x40    /* DAY_SAT */
};

/* 
 * Global Function
 */
extern void QuitSystemOperation(void);
extern void InitUnicodeSupport(void);
extern void ResetLanguageSettingFlag(void);
extern pBOOL isInCall(void);
extern void MMICheckDiskDisplay(void);
extern void ShutDownSystemOperation2(void);
extern void PmgInitExtMelodyStruct(void);
extern void InitFramework(void);
extern void gdi_init(void);
extern void ShutdownSystemOperation(void);
extern void InitSoundEffect(void);
extern void InitDownloadNVRAM(void);
#ifdef __J2ME__
extern void jvm_pause_dummy_screen(void);
extern void jvm_resume_dummy_screen(void);
#endif /* __J2ME__ */ 

#ifdef __EM_MODE__
extern void custom_em_pwn_cycle(kal_bool is_on);
#endif 
extern void PhnsetReadGPIOSetting(void);
#ifdef __LANGLN_WK_ALARM__
extern void mmi_langln_init_alarm_pwron(void);
extern void mmi_langln_wk_init_alarm_callback(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  InitAlarmHandler
 * DESCRIPTION
 *  Initialize Alarm handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitAlarmHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(AlmExpiryHandler, MSG_ID_MMI_EQ_ALARM_IND);
}


/*****************************************************************************
 * FUNCTION
 *  InitAlarmFrameWork
 * DESCRIPTION
 *  Initialize global context and retrieve all kinds of alarm from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitAlarmFrameWork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * init callback function
     */
    AlmFCBInit();
#if defined(__MMI_TODOLIST__)
    TDLFCBInit();
#endif 

#ifdef __MMI_THEMES_APPLICATION__
    ThemesFCBInit();
#endif 
    SPOFFCBInit();

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
    mmi_fmsr_int_cb_function();
#endif 

#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))
    mmi_syncml_init_alarm();
#endif

#if (defined(__MMI_LANGLN_WK_ALARM__))
    mmi_langln_init_alarm_pwron();
    mmi_langln_wk_init_alarm_callback();
#endif

    /*
     * init alarm NVRAM
     */
    for (i = 0; i < ALM_TYPE_TOTAL_NUM; i++)
    {
        if (gAlmCBHandler[i].initAlarmNvramCBPtr)
        {
            gAlmCBHandler[i].initAlarmNvramCBPtr();
        }
    }

#if (defined(__MMI_ENGINEER_MODE__))
    /*  init Factory RTC and Reset */
    mmi_alm_set_start_index(ALM_TYPE_FACTORY, ALM_FACTORY);
    gAlmCBHandler[ALM_TYPE_FACTORY].expiryTimeCBPtr = FactoryExpiryTimeCB;
    gAlmCBHandler[ALM_TYPE_FACTORY].expiryHandlerCBPtr = FactoryExpiryHandler;
#endif /* defined(__MMI_ENGINEER_MODE__)) */ 

    mmi_alm_set_start_index(ALM_TYPE_PWR_RESET, ALM_PWR_RESET);
    gAlmCBHandler[ALM_TYPE_PWR_RESET].expiryTimeCBPtr = ResetExpiryTimeCB;
    gAlmCBHandler[ALM_TYPE_PWR_RESET].expiryHandlerCBPtr = ResetExpiryHandler;
    InitAlarmHandler();

    AlmInitQueue();

    memset(&g_alm_frm_cntx, 0, sizeof(alm_framework_context_struct));
    g_alm_frm_cntx.CurrAlmIndex = 0xff;
    g_alm_frm_cntx.IsAppExecuting = MMI_FALSE;

    for (i = 0; i < ALM_NUM_OF_ALAMRS && gAlmQueue[i].Index < ALM_INDEX_TOTAL; i++);

    g_alm_frm_cntx.EnabledAlarms = (U8) i;
    if (i && g_pwr_context.PowerOnMode != POWER_ON_ALARM)
    {
        AlmCheckAlarmState();
    }

}


/*****************************************************************************
 * FUNCTION
 *  AlmCancelAlarmRsp
 * DESCRIPTION
 *  Protocol Handler for Message Alarm Del Response
 *  Enabled Expiry Handler
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void AlmCancelAlarmRsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(AlmExpiryHandler, MSG_ID_MMI_EQ_ALARM_IND);
}


/*****************************************************************************
 * FUNCTION
 *  AlmSetAlarmRSP
 * DESCRIPTION
 *  Protocol Handler for Message Alarm Set Response
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSetAlarmRSP(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_rtc_time_rsp_struct *alarmRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alarmRes = (mmi_eq_set_rtc_time_rsp_struct*) msg;

    SetProtocolEventHandler(AlmExpiryHandler, MSG_ID_MMI_EQ_ALARM_IND);

    if (alarmRes->result == MMI_TRUE)
    {
    #ifdef __MMI_FACTORY_MODE__
        if (gFactoryAlarm == 1)
        {
            gFactoryAlarm = 0;
            if (g_alm_frm_cntx.IsATPwrOffAnimation)
            {
                ShutdownSystemOperation();
            }
            else
            {
            #ifdef __MTK_TARGET__
                CloseBacklight();
                FS_ClearDiskFlag();
                custom_em_pwn_cycle(KAL_FALSE);
            #else /* __MTK_TARGET__ */ 
                exit(0);
            #endif /* __MTK_TARGET__ */ 
            }
            return;
        }
    #endif /* __MMI_FACTORY_MODE__ */ 
        if (g_alm_frm_cntx.IsWaitForPwroff /* == ALM_STATE_POWER_OFF */ )
        {
            g_alm_frm_cntx.IsWaitForPwroff = 0;
            /* if charger connected or power on confirmation screen present */

            if (g_alm_frm_cntx.IsAppExecuting == 0)
            {
                AlmSendPowerOff();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  PendingAlarmReminder
 * DESCRIPTION
 *  Execute pending after a certain period after call or first time entry idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PendingAlarmReminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_frm_cntx.IsPendingAlm && g_alm_frm_cntx.IsAlmTonePlaying == FALSE)
    {
        if (GetActiveScreenId() == SCR_ID_ALM_INDICATION
    #ifdef __MMI_TODOLIST__
             || GetActiveScreenId() == SCR_TDL_REMINDER
    #endif             
             )
        {
            g_alm_frm_cntx.IsExpiryDisabled = TRUE;
            return;
        }
        StartTimer(ALARM_TIMER_WAIT_FOR_CALL, ALM_AFTER_CM_DURATUION, AlmHandlePendingTimeout);
    }
    else if (g_alm_frm_cntx.IsAlmTonePlaying)
    {
        StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, AlmHandleAlarmTimeout);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PendingAlarmInPwronPeriod
 * DESCRIPTION
 *  Execute pending alarm in security check screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PendingAlarmInPwronPeriod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_frm_cntx.IsPendingAlm)
    {
        AlmHandlePendingTimeout();
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmActualTime
 * DESCRIPTION
 *  Calculates the time when alarm will expire as per the frequency and weekdays.
 * PARAMETERS
 *  t               [IN]        Time of the alarm.
 *  frequency       [IN]        Repeat of the alarm.
 *  weekDays        [IN]        
 *  is_tdl(?)       [IN]        If the alarm is to do list.
 *  weekdays(?)     [IN]        Weekdays of the alarm. Each bit is set for every day. Bit 0 for sunday and so on
 * RETURNS
 *  Next expired time of the alarm.
 *****************************************************************************/
MYTIME AlmActualTime(MYTIME t, FREQ_ALARM frequency, U8 weekDays)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime, incTime;
    TIME_EQUALITY diffStatus, diffStatus2;
    U8 hasDate, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&currTime);
    memset(&incTime, 0, sizeof(incTime));
    hasDate = (t.nMonth != 0 && t.nDay != 0);

    /* If frequency is days, alarm time should be calculated even it is greater than current time */
    if (CompareTime(t, currTime, NULL) != TIME_GREATER || frequency == ALM_FREQ_DAYS) 
    {
        switch (frequency)
        {
            case ALM_FREQ_ONCE:
            case ALM_FREQ_HOURLY:
            case ALM_FREQ_EVERYDAY:            
            case ALM_FREQ_WEEKLY:
                t.nYear = currTime.nYear;
                t.nMonth = currTime.nMonth;
                t.nDay = currTime.nDay;
                if (frequency == ALM_FREQ_ONCE || frequency == ALM_FREQ_EVERYDAY || frequency == ALM_FREQ_HOURLY)
                {
                    if (frequency == ALM_FREQ_HOURLY)
                    {
                        t.nHour = currTime.nHour;
                        incTime.nHour = 1;
                    }
                    else
                    {
                        incTime.nDay = 1;
                    }
                    diffStatus = CompareTime(t, currTime, NULL);
                    if (diffStatus == TIME_LESS || diffStatus == TIME_EQUAL)
                    {
                        IncrementTime(t, incTime, &t);
                    }
                }                
                else    /* frequency == ALM_FREQ_WEEKLY */
                {
                    if (t.DayIndex == currTime.DayIndex)
                    {
                        diffStatus = CompareTime(t, currTime, NULL);
                        if (diffStatus == TIME_LESS || diffStatus == TIME_EQUAL)
                        {
                            incTime.nDay = 7;
                             IncrementTime(t, incTime, &t);
                        }
                    }
                    else
                    {
                        incTime.nDay = (7 + t.DayIndex - currTime.DayIndex) % 7;
                        IncrementTime(t, incTime, &t);
                    }
                }
                break;
                
			case ALM_FREQ_DAYS:
            	diffStatus = CompareTime(t, currTime, NULL);
            	/* alarm time is larger than current time, calculate next alarm since alarm time. */
            	if (diffStatus == TIME_GREATER)           			
            	{     
            		memcpy (&currTime, &t, sizeof(MYTIME));
            	}            	      	
                for (j = 0; j < 7; j++)
                {
                    if (gAlmDayOfWeek[(currTime.DayIndex + j) % 7] & weekDays)
                    {
                        break;
                    }
                }
                if (!j) /* if it's the same day */
                {
					/* compare HH:MM:SS */
					t.nYear = currTime.nYear;
					t.nMonth = currTime.nMonth;
					t.nDay = currTime.nDay;
					diffStatus2 = CompareTime(t, currTime, NULL);
					/* alarm time is less than current time and the HH/MM/SS is less than current time*/
                    if (diffStatus != TIME_GREATER && diffStatus2 != TIME_GREATER)//(diffStatus2 == TIME_LESS || diffStatus2 == TIME_EQUAL) )
                    {
                        /* Find Next Day When then the alarm is scheduled */
                        for (j = 1; j < 7; j++)
                        {
                            if (gAlmDayOfWeek[(currTime.DayIndex + j) % 7] & weekDays)
                            {
                                break;
                             }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
				if (diffStatus == TIME_LESS || diffStatus == TIME_EQUAL)
				{
					currTime.nHour = t.nHour;
					currTime.nMin= t.nMin;
					currTime.nSec= t.nSec;
				}
                incTime.nDay = j;
                IncrementTime(currTime, incTime, &t);
                break;
            default:
                break;
        }
    }

    /* for yearly, monthly, seasonally, whether alarm time is before or afeter current time, next expiry time should be re-calculated. */
    switch (frequency)
    {
        case ALM_FREQ_MONTHLY:
                if (!hasDate)
                {
                    t.nDay = 1;
					t.nYear = currTime.nYear;
					t.nMonth = currTime.nMonth;
                }
				else if(CompareTime(t, currTime, NULL) != TIME_GREATER)
				{					
					t.nYear = currTime.nYear;
					t.nMonth = currTime.nMonth;
				}

            diffStatus = CompareTime(t, currTime, NULL);
            if (diffStatus == TIME_LESS || diffStatus == TIME_EQUAL)    /* || (LastDayOfMonth(t.nMonth, t.nYear) < t.nDay)) */
            {
                if (currTime.nMonth == 12)
                {
						t.nMonth = 1;
                    t.nYear++;
                }
                else
                {
						t.nMonth++;
                }
            }
				j = t.nMonth;                

            for (; j <= 12; j++)
            {
                if (LastDayOfMonth(t.nMonth, t.nYear) >= t.nDay)
                {
                    break;
                }
            }
            break;

        case ALM_FREQ_YEARLY:
            if (!hasDate)
            {
                t.nYear = currTime.nYear;
                t.nMonth = 1;
                t.nDay = 1;
                }
				else if(CompareTime(t, currTime, NULL) != TIME_GREATER)
				{
					t.nYear = currTime.nYear;
            }

            diffStatus = CompareTime(t, currTime, NULL);
            if (diffStatus == TIME_LESS || diffStatus == TIME_EQUAL)
            {
				if (t.nMonth == 2 && t.nDay == 29)
				{
					incTime.nYear = 4 - ((t.nYear) % 4);
					IncrementTime(t, incTime, &t);
				}
				else
				{
					t.nYear++;
				}
            }
            
            break;

        case ALM_FREQ_SEASONALLY:
            t.nYear = currTime.nYear;
            if (!hasDate)
            {
                t.nDay = 1;
            }
            switch (currTime.nMonth)
            {
                case 1:
                case 2:
                case 3:
                    t.nMonth = 4;
                    break;
                case 4:
                case 5:
                case 6:
                    t.nMonth = 7;
                    break;
                case 7:
                case 8:
                case 9:
                    t.nMonth = 10;
                    break;
                default:    /* case 10: case 11: case 12: */
                    t.nMonth = 1;
                    t.nYear = (currTime.nYear + 1);
                    break;
            }
            break;
        default:
            break;
    }

    return t;
}


/*****************************************************************************
 * FUNCTION
 *  AlmsStopAlarmTone
 * DESCRIPTION
 *  Stops Any Alarm Tone that may be playing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmsStopAlarmTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
#if defined (__MMI_ALM_ALERT_TYPE__) || defined (__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
        U8 alert_type;
#endif 
        U8 alarm_index = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_frm_cntx.IsAlmTonePlaying)
    {
        if (g_alm_frm_cntx.CurrAlmIndex >= ALM_TDL_START && g_alm_frm_cntx.CurrAlmIndex < ALM_ALM_START)
        {
            VibratorOff();
            mdi_audio_stop_all();
        }
        else
        {
            /* stopRequestedTone(ALARM_TONE); */
        #if defined (__MMI_ALM_ALERT_TYPE__)
            if (AlmGetType(g_alm_frm_cntx.CurrAlmIndex) == ALM_TYPE_ALARM)
            {
                alert_type = g_alm_cntx.AlmList[alarm_index].AlertType;
                switch (alert_type)
                {
                    case ALM_ALERT_VIBRATION_AND_RING:
                        VibratorOff();
                        mdi_audio_stop_all();
                        break;
                    case ALM_ALERT_RING:
                        mdi_audio_stop_all();
                        break;
                    case ALM_ALERT_VIBRATION:
                        VibratorOff();
                        break;
                    default:
                        break;
                }
            }
            else /* ALM_TYPE_TDL */
            {
                mdi_audio_stop_all();
                VibratorOff();
            }
        #else
            mdi_audio_stop_all();
            VibratorOff();
        #endif
        }
        g_alm_frm_cntx.IsAlmTonePlaying = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmPlayAlarmTone
 * DESCRIPTION
 *  Play alarm tone if it's not playing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmPlayAlarmTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_ALM_ALERT_TYPE__) || defined (__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
    U8 alert_type;
#endif 
    U8 alarm_index = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }
    if (g_alm_frm_cntx.IsAlmTonePlaying == FALSE)
    {
        g_alm_frm_cntx.IsAlmTonePlaying = TRUE;
        if (g_alm_frm_cntx.CurrAlmIndex >= ALM_TDL_START && g_alm_frm_cntx.CurrAlmIndex < ALM_ALM_START)
        {
            VibratorOn();
            playRequestedTone(ALARM_TONE);
        }
        else
        {
        #if defined (__MMI_ALM_ALERT_TYPE__)
            alert_type = g_alm_cntx.AlmList[alarm_index].AlertType;
            switch (alert_type)
            {
                case ALM_ALERT_VIBRATION_AND_RING:
                    VibratorOn();
                    break;
                case ALM_ALERT_VIBRATION:
                    VibratorOn();
                    return;
                    break;
                default:
                    break;
            }
        #elif defined(__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
            alert_type = GetMtCallAlertTypeEnum();
            VibratorOn();
            if (alert_type != MMI_VIBRATION_ONLY && alert_type != MMI_SILENT)
        #endif 
            {
                /* Added support for Alarm Audio Options i.e. FM Radio as alarm tone. */
            #ifdef __MMI_ALM_AUDIO_OPTIONS__
                if (g_alm_frm_cntx.CurrAlmIndex >= ALM_ALM_START && g_alm_frm_cntx.CurrAlmIndex < ALM_SPOF_START)
                {
                    if (g_alm_cntx.AlmList[alarm_index].AudioOption == ALM_AUDIO_OPTIONS_TONE)
                    {
                        playRequestedTone(ALARM_TONE);
                    }
                    else
                    {
                        mmi_alm_aud_fmrdo_play_alarm(alarm_index, GetRingVolumeLevel());
                    }
                }
                else
            #endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 
                {
                    playRequestedTone(ALARM_TONE);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmInitLCDModule
 * DESCRIPTION
 *  Initialize main and sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmInitLCDModule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_init();
}


/*****************************************************************************
 * FUNCTION
 *  AlmInitRTCPwron
 * DESCRIPTION
 *  Initialize all required data and modules for RTC power on.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmInitRTCPwron(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitUnicodeSupport();
    PhnsetReadGPIOSetting();

    mdi_audio_init();

    InitFramework();            /* Initialize framework */
    InitHardwareEvents();
    setup_UI_wrappers();
    PopulateResData();
    PowerAndEndKeyHandler();    /* deepali */
    initialize_UI_demo();
    InitProfileApp();
    InitMMI_App();
    InitChargerPwrOn();

    InitDownloadNVRAM();
    initnvramprofapp();
    InitSettingNVRAM();
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
#ifndef WIN32
    InitRingToneComposer();
#endif
#endif 

#ifdef __MMI_USB_SUPPORT__
    InitMMIUsbContext();
#endif 

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    PmgInitExtMelodyStruct();
#endif 

    mdi_audio_init_event_hdlrs();
    InitAlarmFrameWork();
#ifdef __MMI_THEMES_APPLICATION__
    InitThemes();
#endif 

    InitSoundEffect();

    g_alm_frm_cntx.IsPwronAlarm = TRUE;

    AlmExecPwrOffAlarm();
}


/*****************************************************************************
 * FUNCTION
 *  AlmSendPwronReq
 * DESCRIPTION
 *  Send power on request to L4. This function is used for RTC power on.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSendPwronReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_power_on_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_eq_power_on_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_power_on_req_struct));
    myMsgPtr->fun = 2;
    myMsgPtr->rst = 0;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_EQ_POWER_ON_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  AlmSetAlarm
 * DESCRIPTION
 *  To insert alarm into queue and register the nearest alarm to RTC.
 *  Update alarm profile of L4C if it's normal alarm.
 * PARAMETERS
 *  index       [IN]        Index of alarm
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSetAlarm(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmInsertIntoQueue(index, TRUE);
    AlmStartAlarmOnHW(gAlmQueue[0].Time);
}


/*****************************************************************************
 * FUNCTION
 *  AlmCancelAlarm
 * DESCRIPTION
 *  To remove alarm from queue and register the nearest alarm to RTC.
 *  Update alarm profile of L4C if it's normal alarm.
 * PARAMETERS
 *  index       [IN]        Index of alarm
 * RETURNS
 *  void
 *****************************************************************************/
void AlmCancelAlarm(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmRemoveFromQueue(index, TRUE);

    /* re-schedule alarm of RTC, shall be implemented in another function */
    if (g_alm_frm_cntx.EnabledAlarms == 0)
    {
        AlmStopAlarmOnHW();
    }
    else
    {
        AlmStartAlarmOnHW(gAlmQueue[0].Time);
    }

}

/*****************************************************************************
 * FUNCTION
 *  AlmCancelAlarm
 * DESCRIPTION
 *  To remove alarm from queue and register the nearest alarm to RTC.
 *  Update alarm profile of L4C if it's normal alarm.
 * PARAMETERS
 *  index       [IN]        Index of alarm
 * RETURNS
 *  void
 *****************************************************************************/
void AlmCancelMulltiAlarm(U8* index, U8 amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < amount; i++)
    {
        AlmRemoveFromQueue(index[i], FALSE);
    }

    AlmWriteQueueToNvram();

    /* re-schedule alarm of RTC, shall be implemented in another function */
    if (g_alm_frm_cntx.EnabledAlarms == 0)
    {
        AlmStopAlarmOnHW();
    }
    else
    {
        AlmStartAlarmOnHW(gAlmQueue[0].Time);
    }
}

/*****************************************************************************
 * FUNCTION
 *  AlmGetAlarmTime
 * DESCRIPTION
 *  Get the time of specific queue node.
 * PARAMETERS
 *  index       [IN]        Index of alarm
 * RETURNS
 *  Expired time of the alarm.
 *****************************************************************************/
MYTIME AlmGetAlarmTime(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 AlmType;
    U8 AlmIndex;
    MYTIME alarmTime, preReminder, currTime, incTime;
    U8 Freq = 0;
    U8 WeekDays = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&alarmTime, 0, sizeof(MYTIME));
    memset(&preReminder, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));
    GetDateTime(&currTime);
    AlmType = AlmGetType(index);
    AlmIndex = index - gAlmCBHandler[AlmType].alarmStartIndex;
    if (gAlmCBHandler[AlmType].expiryTimeCBPtr)
    {
        gAlmCBHandler[AlmType].expiryTimeCBPtr(AlmIndex, &alarmTime, &Freq, &WeekDays, &preReminder);
    }
    alarmTime = AlmActualTime(alarmTime, (FREQ_ALARM) Freq, WeekDays);
    memcpy(&incTime, &preReminder, sizeof(MYTIME));
    DecrementTime(alarmTime, incTime, &alarmTime);

    /* check for preminder */
    if (CompareTime(alarmTime, currTime, NULL) != TIME_GREATER)
    {
        /* get original alarm time */
        memcpy(&incTime, &preReminder, sizeof(MYTIME));
        IncrementTime(alarmTime, incTime, &alarmTime);

        memset(&incTime, 0, sizeof(MYTIME));
        switch (Freq)
        {
            case ALM_FREQ_YEARLY:
                incTime.nYear = 1;
                break;
            case ALM_FREQ_MONTHLY:
                incTime.nMonth = 1;
                break;
            default:
                incTime.nDay = 1;
                break;
        }
        IncrementTime(alarmTime, incTime, &alarmTime);
        alarmTime = AlmActualTime(alarmTime, (FREQ_ALARM) Freq, WeekDays);

        DecrementTime(alarmTime, preReminder, &alarmTime);
    }

    return alarmTime;
}


/*****************************************************************************
 * FUNCTION
 *  AlmInsertIntoQueue
 * DESCRIPTION
 *  Insert an alarm node to the queue.
 * PARAMETERS
 *  index           [IN]        Index of alarm
 *  saveflag        [IN]        Flag to determine save directly to NVRAM or not
 * RETURNS
 *  The position of alarm in queue.
 *****************************************************************************/
U8 AlmInsertIntoQueue(U8 index, U8 saveflag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    TIME_EQUALITY equality;
    MYTIME alarmTime;   
#ifdef __MMI_ADVANCED_TODO__    
    tdl_context_struct* tdlPtr;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= ALM_INDEX_TOTAL)   /* exceeds boundary */
    {
        return 0;
    }

    AlmRemoveFromQueue(index, FALSE);   /* node is in queue, remove it first */

    alarmTime = AlmGetAlarmTime(index);

    /* Check expiry time */
    if (!mmi_dt_is_valid(&alarmTime))
    {
		AlmWriteQueueToNvram();
        return 0;
    }

    /* insert into proper position */
    for (i = 0; i < g_alm_frm_cntx.EnabledAlarms; i++)
    {
        equality = CompareTime(alarmTime, gAlmQueue[i].Time, NULL);
        if (equality == TIME_GREATER)
        {
            continue;
        }
        else if (equality == TIME_EQUAL)
        {
        #ifdef __MMI_ADVANCED_TODO__
            if (AlmGetType(index) == ALM_TYPE_TDL && AlmGetType(gAlmQueue[i].Index) == ALM_TYPE_TDL)
            {
                tdlPtr = mmi_tdl_get_context(); 
                /* Priority is lower than current node */
                if (tdlPtr->TaskList[index - ALM_TDL_START].Priority > tdlPtr->TaskList[gAlmQueue[i].Index - ALM_TDL_START].Priority)
                {
                    continue;
                }
                /* Priority is equal to current node */
                else if (tdlPtr->TaskList[index - ALM_TDL_START].Priority == tdlPtr->TaskList[gAlmQueue[i].Index - ALM_TDL_START].Priority)
                {
                    if (index >= gAlmQueue[i].Index)
                    {
                        continue;
                    }
                }
                /* If priority is higher than current node, index order should not be considered */
            }
            else if (index >= gAlmQueue[i].Index)
        #else
            if (index >= gAlmQueue[i].Index)
        #endif            
            {
                continue;
            }                        
        }  
        /* shift all nodes right */
        for (j = g_alm_frm_cntx.EnabledAlarms - 1; j >= i; j--)
        {
            memcpy(&gAlmQueue[j + 1], &gAlmQueue[j], sizeof(alm_queue_node_struct));
        }
        break;
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
        #endif
    }

    gAlmQueue[i].Index = index;
    gAlmQueue[i].Time = alarmTime;
    gAlmQueue[i].IsExpired = 0;

    g_alm_frm_cntx.EnabledAlarms++;

    /* write alarm queue to NVRAM */
    if (saveflag)
    {
        AlmWriteQueueToNvram();
    }

    return (U8) i;

}


/*****************************************************************************
 * FUNCTION
 *  AlmRemoveFromQueue
 * DESCRIPTION
 *  Remove an alarm node from the queue.
 * PARAMETERS
 *  index           [IN]        Index of alarm
 *  saveflag        [IN]        Flag to determine save directly to NVRAM or not
 * RETURNS
 *  Number of enabled alarms.
 *****************************************************************************/
U8 AlmRemoveFromQueue(U8 index, U8 saveflag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gAlmQueue[0].Index > ALM_INDEX_TOTAL)   /* queue is empty */
    {
        return 0;
    }

    for (i = 0; i < ALM_NUM_OF_ALAMRS; i++)
        if (gAlmQueue[i].Index == index)
        {
            break;
        }

    if (i >= ALM_NUM_OF_ALAMRS) /* alarm node not found */
    {
        return 0;
    }

    /* remove from queue */
    memcpy(&gAlmQueue[i], &gAlmQueue[i + 1], sizeof(alm_queue_node_struct) * (ALM_NUM_OF_ALAMRS - i - 1));

    g_alm_frm_cntx.EnabledAlarms--;

    memset(&gAlmQueue[g_alm_frm_cntx.EnabledAlarms], 0xff, sizeof(alm_queue_node_struct));

    /* write alarm queue to NVRAM */
    if (saveflag)
    {
        AlmWriteQueueToNvram();
    }

    return g_alm_frm_cntx.EnabledAlarms;
}


/*****************************************************************************
 * FUNCTION
 *  AlmIsExpireAllowed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 AlmIsExpireAllowed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;
    pBOOL PowerOnCheck;
    U16 call_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_before_power_on() == 1)
    {
        PowerOnCheck = MMI_FALSE;   /* the case of alarm expiration + power on indication */
    }
    else if (mmi_bootup_is_in_power_on_period() == 0)
    {
        PowerOnCheck = MMI_TRUE;    /* the case of idle screen reached + alarm expiration */
    }
    else if (GetActiveScreenId() == SCR_ENTER_SSC || IsScreenPresent(SCR_ENTER_SSC) == MMI_TRUE)
    {
        PowerOnCheck = MMI_TRUE;    /* the case of power on animation + MT call + IMEI + call end + alarm expiration */
    }
    else
    {
        PowerOnCheck = MMI_FALSE;   /* the case of power on animation + alarm expiration */
    }

    if (isInCall())
    {
    	if (!IsWapCallPresent())
    	{
    		call_count = isInCall();	
            g_alm_frm_cntx.IsExpiryDisabled = MMI_TRUE;
    	}
    #ifdef __MMI_UCM__
        else if (mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE_ALL) == mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL))
    #else /* __MMI_UCM__ */
    	else if (GetTotalCallCount() == 1)
    #endif /* __MMI_UCM__ */    	
    	{
    		g_alm_frm_cntx.IsExpiryDisabled = MMI_FALSE;
    	}    	
    }


    state = ((call_count == 0) && (PowerOnCheck == MMI_TRUE) && (!g_alm_frm_cntx.IsExpiryDisabled));

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_EXPIRY_STATE, (S32) call_count, (S32) PowerOnCheck,
               (S32) g_alm_frm_cntx.IsExpiryDisabled);

    return state;
}


/*****************************************************************************
 * FUNCTION
 *  AlmHandleAlarmTimeout
 * DESCRIPTION
 *  Timer expiry handler for normal alarm.
 *  Exit previous alarm screen.
 * PARAMETERS
 *  void
 *  index(?)        [IN]        Index of alarm
 * RETURNS
 *  void
 *****************************************************************************/
void AlmHandleAlarmTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 almType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);

    almType = AlmGetType(g_alm_frm_cntx.CurrAlmIndex);
    if (g_alm_frm_cntx.CurrAlmIndex == ALM_FACTORY)
    {
        AlmSendPowerOff();
    }
    else if (GetActiveScreenId() == SCR_ID_SPOF_CONFIRM)
    {
        ShutdownSystemOperation();
    }
    else
    {
        if (AlmIsExpireAllowed())
        {
            g_alm_frm_cntx.IsExitByTimer = TRUE;
            AlmExitPreviousAlarm();
            g_alm_frm_cntx.IsExitByTimer = FALSE;

            if (g_alm_frm_cntx.IsPwronAlarm)
            {
                AlmExecPwrOffAlarm();
            }
            else
            {
                AlmExecPwrOnAlarm();
            }
        }
        else
        {
            g_alm_frm_cntx.IsPendingAlm = TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmExitPreviousAlarm
 * DESCRIPTION
 *  Execute exit handler of previous alarm to to do list alam.
 *  Exit previous alarm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmExitPreviousAlarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 almType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if some alarm is previous displayed, execute previous exit handler */
    if (g_alm_frm_cntx.CurrAlmIndex < ALM_INDEX_TOTAL)
    {
        /* stop previous alarm */
        almType = AlmGetType(g_alm_frm_cntx.CurrAlmIndex);
        if (gAlmCBHandler[almType].stopAlarmCBPtr)
        {
            gAlmCBHandler[almType].stopAlarmCBPtr();
        }
        else
        {
            StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
            g_alm_frm_cntx.CurrAlmIndex = 0xff;
        }
    }

    g_alm_frm_cntx.CurrAlmIndex = 0xff;
}


/*****************************************************************************
 * FUNCTION
 *  EntryAlmDummyScr
 * DESCRIPTION
 *  Dummy screen to exit previous application (Java)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmDummyScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_spof_disable_check
 * DESCRIPTION
 *  SPOF disable handler
 * PARAMETERS
 *  void
 * RETURNS
 *  Expired alarm index in the queue except for SPOF
 *****************************************************************************/
U8 mmi_alm_spof_disable_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;
    U8 i, almIndex = 0xff;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&currTime);
    g_alm_frm_cntx.IsPendingAlm = TRUE;

    /* more alarms in queue and */
    for (i=1; i<NUM_OF_SPOF && i< g_alm_frm_cntx.EnabledAlarms;i++)
    {
        if (CompareTime(gAlmQueue[i].Time, currTime, NULL) == TIME_GREATER)
        {
            AlmStartAlarmOnHW(gAlmQueue[i].Time);
            break;
        }
        else if ( AlmGetType(gAlmQueue[i].Index) != ALM_TYPE_SPOF)
        {
            almIndex = gAlmQueue[i].Index;
            break;
        }
        
    }
    
    return almIndex;
}


/*****************************************************************************
 * FUNCTION
 *  AlmExpiryHandler
 * DESCRIPTION
 *  To set alarm to RTC
 * PARAMETERS
 *  msg             [?]         
 *  index(?)        [IN]        Index of alarm
 * RETURNS
 *  void
 *****************************************************************************/
void AlmExpiryHandler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_alarm_ind_struct *local_data = (mmi_eq_alarm_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update global time */

    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    StopTimer(ALARM_TIMER_WAIT_FOR_CALL);

    gclockData.rtc_wday = local_data->rtc_time.rtc_wday;
    gclockData.rtc_year = local_data->rtc_time.rtc_year;
    gclockData.rtc_mon = local_data->rtc_time.rtc_mon;
    gclockData.rtc_day = local_data->rtc_time.rtc_day;
    gclockData.rtc_hour = local_data->rtc_time.rtc_hour;
    gclockData.rtc_min = local_data->rtc_time.rtc_min;
    gclockData.rtc_sec = local_data->rtc_time.rtc_sec;

    mmi_dt_check_rtc_time();

    /* execute exit handler of previous alarm */
    g_alm_frm_cntx.IsExitByTimer = TRUE;
    AlmExitPreviousAlarm();
    g_alm_frm_cntx.IsExitByTimer = FALSE;

    if (!AlmIsExpireAllowed())
    {
        g_alm_frm_cntx.IsPendingAlm = TRUE;
        return;
    }

    if (AlmIsPowerOffMode())
    {
        g_alm_frm_cntx.IsPwronAlarm = TRUE;
    }

    /* execute next alarm */
    if (g_alm_frm_cntx.IsPwronAlarm)
    {
        AlmExecPwrOffAlarm();
    }
    else
    {
        AlmExecPwrOnAlarm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmExecPwrOnAlarm
 * DESCRIPTION
 *  Popup one alarm entry from queue and execute corresponding handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmExecPwrOnAlarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 almType, almIndex;
    MYTIME currTime, alarmTime, incTime;
    TIME_EQUALITY equality;
    U8 NexAlmToShow = FALSE;
    U8 NextAlmToSet = FALSE;
    U8 AlmSnoozeTime, tmpIndex;
    U8 IsSPOFPending = FALSE;
    U16 period = 0;

#ifdef __J2ME__
    U8 IsJavaPlaying = FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_frm_cntx.CurrAlmIndex = 0xff;
    g_alm_frm_cntx.IsPendingAlm = FALSE;
    /* no alarm expired, to prevent abnormal case */
    if (!g_alm_frm_cntx.EnabledAlarms)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_EMPTY_QUEUE);
        g_alm_frm_cntx.IsPendingAlm = FALSE;
        return;
    }

    if (!AlmIsExpireAllowed())
    {
        g_alm_frm_cntx.IsPendingAlm = TRUE;
        return;
    }

    DTGetRTCTime(&currTime);
    /* to prevent abnormal case */
    if (CompareTime(gAlmQueue[0].Time, currTime, NULL) == TIME_GREATER)
    {
        AlmStartAlarmOnHW(gAlmQueue[0].Time);
        g_alm_frm_cntx.IsPendingAlm = FALSE;
        return;
    }

    almIndex = gAlmQueue[0].Index;
    almType = AlmGetType(almIndex);

    /* spof is disabled, find out next alarm to execute */
    if (almType == ALM_TYPE_SPOF && g_alm_frm_cntx.IsSpofDisabled)
    {
        almIndex = mmi_alm_spof_disable_check();
        if (almIndex == 0xff)   /* no other alarm expired */
        {
            return;
        }
        else
        {
            IsSPOFPending = TRUE;
            almType = AlmGetType(almIndex);
        }
    }

    g_alm_frm_cntx.CurrAlmIndex = almIndex;

#ifdef __J2ME__
    if (GetActiveScreenId() == SCR_JAVA_APP)
    {
        IsJavaPlaying = TRUE;
        jvm_pause_dummy_screen();
    }
#endif /* __J2ME__ */ 

    /* re-organizer alarm queue */
    /* if(!g_alm_frm_cntx.IsPendingAlm) */
    {
        /* if it's a pending alarm, no need to re-schedule right now */
        if (AlmGetRepeat(almIndex) == ALM_FREQ_ONCE)
        {
            AlmRemoveFromQueue(almIndex, TRUE);
        }
        else if (almType != ALM_TYPE_ALARM) /* alarm shall be inserted into queue after stopped */
        {
            AlmInsertIntoQueue(almIndex, TRUE);
        }
        else
        {
            tmpIndex = almIndex - ALM_ALM_START;
            AlmSnoozeTime = g_alm_cntx.AlmList[tmpIndex].Snooze;
            g_alm_cntx.AlmList[tmpIndex].Snooze = 0;
            AlmInsertIntoQueue(almIndex, TRUE);
            g_alm_cntx.AlmList[tmpIndex].Snooze = AlmSnoozeTime;
        }
    }
#ifdef __J2ME__
    if (IsJavaPlaying == TRUE)
    {
        jvm_resume_dummy_screen();
    }
#endif /* __J2ME__ */ 
    /* execute corrpesonding handler */
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_EXPIRY_TYPE, (S32) almType);
    if (gAlmCBHandler[almType].expiryHandlerCBPtr)
    {
        U8 isIndSrc;
        U8 almAppIndex = g_alm_frm_cntx.CurrAlmIndex - gAlmCBHandler[almType].alarmStartIndex;

        isIndSrc = gAlmCBHandler[almType].expiryHandlerCBPtr(almAppIndex, &period, MMI_TRUE);

        if (isIndSrc == ALM_HAS_NO_IND)
        {
        }
    }

    /* set another RTC if requried */
    if (g_alm_frm_cntx.EnabledAlarms > 0)   /* second alarm exists */
    {
        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nSec = period;
        IncrementTime(currTime, incTime, &alarmTime);
        equality = CompareTime(gAlmQueue[0].Time, alarmTime, NULL);
        /* if next alarm will expire within 30 seconds */
        if (equality == TIME_LESS || equality == TIME_EQUAL)    /* alarm expired */
        {
            /* increment n seconds and then set another alarm */
            NexAlmToShow = TRUE;
            NextAlmToSet = TRUE;
        }
        else
        {
            NextAlmToSet = TRUE;
            alarmTime = gAlmQueue[0].Time;
        }
        AlmStartAlarmOnHW(alarmTime);
    }

    if (period == 0)
    {
        if (g_alm_frm_cntx.EnabledAlarms)
        {
            AlmExecPwrOnAlarm();
        }
    }
    else if (!NexAlmToShow)
    {
        StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, (period * 1000), AlmHandleAlarmTimeout);
    }
    else if (NexAlmToShow) /*If next alarm is set, current alarm will be stopped by next alarm, therefore alert timeout is not needed. */
    {
        StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmExecPwrOffAlarm
 * DESCRIPTION
 *  RTC power on handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmExecPwrOffAlarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 almType, almIndex;
    MYTIME currTime, alarmTime, incTime;
    TIME_EQUALITY equality;
    U8 NexAlmToShow = FALSE;
    U8 NextAlmToSet = FALSE;
    U16 period;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* no alarm expired, to prevent abnormal case */
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    g_alm_frm_cntx.CurrAlmIndex = 0xff;
    g_alm_frm_cntx.IsPwronAlarm = TRUE;

    if (!g_alm_frm_cntx.EnabledAlarms)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_EMPTY_QUEUE);
        if (g_alm_frm_cntx.IsAppExecuting == 0)
        {   
            AlmSendPowerOff();
        }
        return;
    }

    /* compare the time */
    almIndex = gAlmQueue[0].Index;
    DTGetRTCTime(&currTime);
    if (CompareTime(gAlmQueue[0].Time, currTime, NULL) == TIME_GREATER)
    {
        g_alm_frm_cntx.IsWaitForPwroff = TRUE;
        AlmStartAlarmOnHW(gAlmQueue[0].Time);
        return;
    }

    almType = AlmGetType(almIndex);
    g_alm_frm_cntx.CurrAlmIndex = almIndex;

    /* spof is disabled, find out next alarm to execute */
    if (almType == ALM_TYPE_SPOF && g_alm_frm_cntx.IsSpofDisabled)
    {
        AlmInsertIntoQueue(almIndex, TRUE);
        if (CompareTime(gAlmQueue[0].Time, currTime, NULL) == TIME_GREATER)
        {
        	AlmStartAlarmOnHW(gAlmQueue[0].Time);
        }
        else
        {
        	AlmExecPwrOffAlarm();
        }
        return;        
    }

    if (AlmGetRepeat(almIndex) == ALM_FREQ_ONCE)
    {
        AlmRemoveFromQueue(almIndex, TRUE);
    }
    else if (almType != ALM_TYPE_ALARM) /* alarm shall be inserted into queue after stopped */
    {
        AlmInsertIntoQueue(almIndex, TRUE);
    }
    else
    {
        U8 tmpIndex, AlmSnoozeTime;

        tmpIndex = almIndex - ALM_ALM_START;
        AlmSnoozeTime = g_alm_cntx.AlmList[tmpIndex].Snooze;
        g_alm_cntx.AlmList[tmpIndex].Snooze = 0;
        AlmInsertIntoQueue(almIndex, TRUE);
        g_alm_cntx.AlmList[tmpIndex].Snooze = AlmSnoozeTime;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_EXPIRY_TYPE, (S32) almType);

    if (gAlmCBHandler[almType].expiryHandlerCBPtr)
    {
        U8 almAppIndex = g_alm_frm_cntx.CurrAlmIndex - gAlmCBHandler[almType].alarmStartIndex;

        gAlmCBHandler[almType].expiryHandlerCBPtr(almAppIndex, &period, MMI_FALSE);
    }

    if (g_alm_frm_cntx.EnabledAlarms > 0)   /* second alarm exists */
    {
        /* increment 30 seconds and then set another alarm */
        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nSec = period;
        IncrementTime(currTime, incTime, &alarmTime);

        equality = CompareTime(gAlmQueue[0].Time, alarmTime, NULL);
        if (equality == TIME_LESS || equality == TIME_EQUAL)    /* alarm expired */
        {
            NexAlmToShow = TRUE;
            NextAlmToSet = TRUE;
        }
        else
        {
            alarmTime = gAlmQueue[0].Time;
            NextAlmToSet = TRUE;
        }
        AlmStartAlarmOnHW(alarmTime);
    }

    if (period == 0)
    {
    	/* power on/off need not execute next alarm */
        if (almType != ALM_TYPE_SPOF && almType != ALM_TYPE_SPON && almType != ALM_TYPE_PWR_RESET)
        {
            AlmExecPwrOffAlarm();
        }
    }
    else if (!NexAlmToShow)
    {
        StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, (period * 1000), AlmHandleAlarmTimeout);
    }
    else if (NexAlmToShow) /*If next alarm is set, current alarm will be stopped by next alarm, therefore alert timeout is not needed. */
    {
        StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmWriteQueueToNvram
 * DESCRIPTION
 *  Write alarm queue to nvram.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmWriteQueueToNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_ALM_QUEUE_LID, (U16) 1, (void*)gAlmQueue, NVRAM_ALM_QUEUE_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  AlmInitQueue
 * DESCRIPTION
 *  Read alarm queue from nvram.
 *  Reset alarm queue if
 *  1. index misordered.
 *  2. the expired time of first alarm is far from current time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmInitQueue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MYTIME currTime, refTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_ALM_QUEUE_LID, (U16) 1, (void*)gAlmQueue, NVRAM_ALM_QUEUE_SIZE, &error);

    if (gAlmQueue[0].Index >= ALM_INDEX_TOTAL /* && gAlmQueue[0].Index != 0xff */ )     /* o prevent alarm queue being corrupted */
    {
        AlmReInitialize();
    }
    else
    {
        memset(&refTime, 0, sizeof(MYTIME));
        refTime.nMin = ALM_MAX_DELAY_ALLOWANCE;
        IncrementTime(gAlmQueue[0].Time, refTime, &refTime);

        DTGetRTCTime(&currTime);

        if (CompareTime(currTime, refTime, NULL) == TIME_GREATER)
        {
            AlmReInitialize();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmFindNodeInQueue
 * DESCRIPTION
 *  To see if the alarm node is currently in alarm queue
 * PARAMETERS
 *  index       [IN]        Index of alarm
 * RETURNS
 *  0xff is the node is not in queue; otherwise, return the position of the alarm node.
 *****************************************************************************/
U8 AlmFindNodeInQueue(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_OF_ALM; i++)
    {
        if (gAlmQueue[i].Index == index)
        {
            return i;
        }

        if (gAlmQueue[i].Index > ALM_INDEX_TOTAL)
        {
            return 0xff;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  AlmGetType
 * DESCRIPTION
 *  To get the type of alarm
 * PARAMETERS
 *  index       [IN]        Index of alarm
 * RETURNS
 *  Enum value of alarm type
 *****************************************************************************/
U8 AlmGetType(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < ALM_TYPE_TOTAL_NUM; i++)
    {
        if (index < gAlmCBHandler[i].alarmStartIndex)
        {
            break;
        }
    }
    return i - 1;
}


/*****************************************************************************
 * FUNCTION
 *  AlmGetRepeat
 * DESCRIPTION
 *  To get the repeat type of an alarm.
 * PARAMETERS
 *  index       [IN]        Index of alarm
 * RETURNS
 *  Enum value of repeat type
 *****************************************************************************/
U8 AlmGetRepeat(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME alarmTime, preReminder;
    U8 Freq = 0;
    U8 WeekDays = 0;
    U8 AlmType, AlmIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&preReminder, 0, sizeof(MYTIME));
    AlmType = AlmGetType(index);
    AlmIndex = index - gAlmCBHandler[AlmType].alarmStartIndex;
    if (gAlmCBHandler[AlmType].expiryTimeCBPtr)
    {
        gAlmCBHandler[AlmType].expiryTimeCBPtr(AlmIndex, &alarmTime, &Freq, &WeekDays, &preReminder);
    }
    return Freq;
}


/*****************************************************************************
 * FUNCTION
 *  AlmGetStringValue
 * DESCRIPTION
 *  Compute the string value of given integer. The string will dispaly exact 2 digits.
 * PARAMETERS
 *  StringVal       [IN/OUT]        Pointer to store the result.
 *  Val             [IN]            Value to be computed
 * RETURNS
 *  void
 *****************************************************************************/
void AlmGetStringValue(S8 *StringVal, U8 Val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 StrVal[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(StrVal, "%02d", Val);
    mmi_asc_to_ucs2(StringVal, StrVal);
}


/*****************************************************************************
 * FUNCTION
 *  AlmIsRTCPwron
 * DESCRIPTION
 *  To see if the it's RTC power on or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  The state of power on alarm.
 *****************************************************************************/
U8 AlmIsRTCPwron(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_alm_frm_cntx.IsPwronAlarm;
}


/*****************************************************************************
 * FUNCTION
 *  AlmStartAlarmOnHW
 * DESCRIPTION
 *  To register RTC alarm on HW
 * PARAMETERS
 *  alarmTime       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AlmStartAlarmOnHW(MYTIME alarmTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_set_rtc_time_req_struct *alarmReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ;
    alarmReq = (mmi_eq_set_rtc_time_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_set_rtc_time_req_struct));
    alarmReq->rtc_type = RTC_ALARM_IND;
    alarmReq->set_type = RTC_SETTING_TYPE_DATETIME;
    alarmReq->info.alarm_format = DEVICE_AL_EN_ChkYMDHMS;
    alarmReq->info.alarm_index = RTC_ALARM1_IND;    /* Should be always zeor as only 1 alarm */
    alarmReq->info.type = RTC_ALARM_SOUND;
    alarmReq->info.text[0] = '\0';
    alarmReq->info.recurr = RTC_ALARM_DAY1;
    alarmReq->info.data_time.rtc_year = alarmTime.nYear - YEARFORMATE;
    alarmReq->info.data_time.rtc_wday = alarmTime.DayIndex;
    alarmReq->info.data_time.rtc_mon = alarmTime.nMonth;
    alarmReq->info.data_time.rtc_day = alarmTime.nDay;
    alarmReq->info.data_time.rtc_hour = alarmTime.nHour;
    alarmReq->info.data_time.rtc_min = alarmTime.nMin;
    alarmReq->info.data_time.rtc_sec = alarmTime.nSec;
    Message.oslDataPtr = (oslParaType*) alarmReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(AlmSetAlarmRSP, MSG_ID_MMI_EQ_EXE_RTC_TIMER_RSP);
    ClearProtocolEventHandler(MSG_ID_MMI_EQ_ALARM_IND);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  AlmStopAlarmOnHW
 * DESCRIPTION
 *  To del RTC from HW.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmStopAlarmOnHW(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    mmi_eq_del_rtc_timer_req_struct *alarmReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    Message.oslMsgId = MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ;

    alarmReq = (mmi_eq_del_rtc_timer_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_del_rtc_timer_req_struct));

    alarmReq->rtc_type = RTC_ALARM_IND;
    alarmReq->rtc_index = RTC_ALARM1_IND;
    /* MTK end */
    Message.oslDataPtr = (oslParaType*) alarmReq;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(AlmCancelAlarmRsp, MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_RSP);
    ClearProtocolEventHandler(MSG_ID_MMI_EQ_ALARM_IND);

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  AlmReInitialize
 * DESCRIPTION
 *  Re construct whole alarm queue and realted variables.
 * PARAMETERS
 *  void
 * RETURNS
 *  The state of power on alarm.(?)
 *****************************************************************************/
void AlmReInitialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, almPreviousState;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    almPreviousState = g_alm_frm_cntx.IsExpiryDisabled;
    
    AlmDisableExpiryHandler();

    AlmStopAlarmOnHW();

    memset(gAlmQueue, 0xff, sizeof(gAlmQueue));

    g_alm_frm_cntx.EnabledAlarms = 0;

    for (i = 0; i < ALM_TYPE_TOTAL_NUM; i++)
    {
        if (gAlmCBHandler[i].reInitAlarmQueueCBPtr)
        {
            gAlmCBHandler[i].reInitAlarmQueueCBPtr();
        }
    }

    AlmWriteQueueToNvram();

    if (gAlmQueue[0].Index != 0xff)
    {
        AlmStartAlarmOnHW(gAlmQueue[0].Time);
    }

    if (almPreviousState == MMI_FALSE)
    {
        AlmEnableExpiryHandler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmSendPowerOn
 * DESCRIPTION
 *  Display check disk screen, reset language, then send power on request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSendPowerOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmsStopAlarmTone();
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ResetLanguageSettingFlag();
#ifdef __NVRAM_IN_USB_MS__
    if (g_pwr_context.PowerOnMode == POWER_ON_USB)
    {
        /* Temporily disable alarm reset in USB boot mode */
        /*
         * mmi_usb_set_reset_type(ALARM_RESET);
         */
        UsbPwnOnThenPwnOn();
    }
    else
#endif /* __NVRAM_IN_USB_MS__ */ 
    {
        MMICheckDiskDisplay();
        AlmSendPwronReq();
    /* turn on backlight to make logo visible for the user */
    TurnOnBacklight(TRUE);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  AlmSendPowerOff
 * DESCRIPTION
 *  Send power off request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSendPowerOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmCommonExitProcedure();
#ifdef __NVRAM_IN_USB_MS__
    if (g_pwr_context.PowerOnMode == POWER_ON_USB)
    {
        mmi_usb_set_reset_type(CHARGING_RESET);
        UsbPwnOnThenPwnOn();
    }
    else
#endif /* __NVRAM_IN_USB_MS__ */ 
        QuitSystemOperation();
}


/*****************************************************************************
 * FUNCTION
 *  AlmCheckAlarmState
 * DESCRIPTION
 *  If first alarm time > currTime, start first alarm on hardware.
 *  Else, set flag to indicate there is some pending alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmCheckAlarmState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&currTime);

    if (CompareTime(gAlmQueue[0].Time, currTime, NULL) == TIME_GREATER)
    {
        AlmStartAlarmOnHW(gAlmQueue[0].Time);
    }
    else
    {
        g_alm_frm_cntx.IsPendingAlm = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmHandlePendingTimeout
 * DESCRIPTION
 *  Execute pending alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmHandlePendingTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!AlmIsExpireAllowed())
    {
        g_alm_frm_cntx.IsPendingAlm = TRUE;
    }
    else
    {
        U8 almType;

        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_PENDING_TIMEOUT);

        almType = AlmGetType(g_alm_frm_cntx.CurrAlmIndex);

        /* stop previous alarm */
        AlmExitPreviousAlarm();

        if (almType != ALM_TYPE_ALARM)
        {
            /* alarm will be executed in the snooze handler. */
            if (AlmIsPowerOffMode())
            {
                AlmExecPwrOffAlarm();
            }
            else
            {
                AlmExecPwrOnAlarm();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmDisableSPOF
 * DESCRIPTION
 *  Disable schedule power off functionality.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmDisableSPOF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_DISABLE_SPOF);
    g_alm_frm_cntx.IsSpofDisabled = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  AlmEnableSPOF
 * DESCRIPTION
 *  Enable schedule power off functionality.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmEnableSPOF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_ENABLE_SPOF);
    if (g_alm_frm_cntx.IsSpofDisabled)
    {
        g_alm_frm_cntx.IsSpofDisabled = FALSE;
        PendingAlarmReminder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmDisableExpiryHandler
 * DESCRIPTION
 *  Disable alarm epxiry handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmDisableExpiryHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_DISABLE_ALARM);
    g_alm_frm_cntx.IsExpiryDisabled = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  AlmEnableExpiryHandler
 * DESCRIPTION
 *  Enable alarm epxiry handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmEnableExpiryHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RTC_ALARM_ENABLE_ALARM);
    if (g_alm_frm_cntx.IsExpiryDisabled)
    {
        g_alm_frm_cntx.IsExpiryDisabled = FALSE;
        PendingAlarmReminder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmDeInit
 * DESCRIPTION
 *  Inspec queue status and pre-set next alarm if required.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shutdown when alarm is on indication screen */
    if (AlmGetType(g_alm_frm_cntx.CurrAlmIndex) == ALM_TYPE_ALARM)
    {
        U8 i = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;

        g_alm_cntx.AlmList[i].Snooze++;

        if (g_alm_cntx.AlmList[i].Snooze <= MAX_SNOOZE_CHANCES)
        {
            g_alm_cntx.AlmList[i].State = SET_STATE;
            AlmWriteToNvram();
            AlmInsertIntoQueue(g_alm_frm_cntx.CurrAlmIndex, TRUE);
            AlmStartAlarmOnHW(gAlmQueue[0].Time);
        }
    }

    /* Set next alarm. if alarm will expire during power off period, delay it */
    if (gAlmQueue[0].Index < ALM_INDEX_TOTAL)
    {
        MYTIME currTime, incTime;

        DTGetRTCTime(&currTime);

        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nSec = (ALM_POWER_OFF_TOLERANCE / 1000);

        IncrementTime(currTime, incTime, &currTime);

        if (CompareTime(gAlmQueue[0].Time, currTime, NULL) != TIME_GREATER)     /* alarm almost expire */
        {
            AlmStartAlarmOnHW(currTime);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmIsTonePlaying
 * DESCRIPTION
 *  Query if alarm tone playing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 AlmIsTonePlaying(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_alm_frm_cntx.IsAlmTonePlaying;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_is_in_alarm
 * DESCRIPTION
 *  Query if alarm tone playing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_alm_is_in_alarm(void)
{
    if ( AlmIsTonePlaying()
#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)    
     || mmi_fmsr_is_schedule_rec_running()
#endif     
     )
    {
		return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  FactorySetAlarm
 * DESCRIPTION
 *  Set facrtory mode alarm.
 * PARAMETERS
 *  sec     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if (defined(__MMI_FACTORY_MODE__))       /* Robin Add 1001 for MMI Feature */
void FactorySetAlarm(U8 sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmSetAlarm(ALM_FACTORY);
}


/*****************************************************************************
 * FUNCTION
 *  FactoryExpiryTimeCB
 * DESCRIPTION
 *  Set facrtory mode alarm.
 * PARAMETERS
 *  index           [IN]        
 *  alarmTime       [?]         
 *  Freq            [?]         
 *  WeekDays        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void FactoryExpiryTimeCB(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(alarmTime);
    memset(&incTime, 0, sizeof(MYTIME));
    incTime.nSec = ALM_FACTORY_RTC_TIME;
    IncrementTime(*alarmTime, incTime, alarmTime);
    *Freq = ALM_FREQ_ONCE;
}


/*****************************************************************************
 * FUNCTION
 *  FactoryExpiryHandler
 * DESCRIPTION
 *  Set facrtory mode alarm.
 * PARAMETERS
 *  Index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 FactoryExpiryHandler(U8 Index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!power_on)
    {
        *period = ALM_DEFAULT_EXPIRY_PERIOD;
        AlmInitLCDModule();
        EntryAlmIndicationScreen();
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: Alarm idle screen */
        return ALM_HAS_IND;
    }
    *period = ALM_WITHOUD_EXPIRY_PERIOD;
    return ALM_HAS_NO_IND;
}
#endif /* (defined(__MMI_FACTORY_MODE__)) */ 


/*****************************************************************************
 * FUNCTION
 *  AlmATPowerReset
 * DESCRIPTION
 *  Set an reboot alarm for AT command
 * PARAMETERS
 *  power_off       [IN]        
 *  time            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AlmATPowerReset(U8 power_off, U8 time)
{
#ifdef __MMI_FACTORY_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reuse the flag of factory alarm */
    gFactoryAlarm = 1;

    if (power_off)
    {
        g_alm_frm_cntx.ATPwrCycle = time;
    }
    else
    {
        g_alm_frm_cntx.ATPwrCycle = ALM_FACTORY_RTC_TIME;
    }

    g_alm_frm_cntx.IsATPwrOffAnimation = power_off;

    AlmSetAlarm(ALM_PWR_RESET);
#endif /* __MMI_FACTORY_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ResetExpiryTimeCB
 * DESCRIPTION
 *  Set facrtory mode alarm.
 * PARAMETERS
 *  index           [IN]        
 *  alarmTime       [?]         
 *  Freq            [?]         
 *  WeekDays        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void ResetExpiryTimeCB(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(alarmTime);
    memset(&incTime, 0, sizeof(MYTIME));
    incTime.nSec = (g_alm_frm_cntx.ATPwrCycle % 60);
    incTime.nMin = (g_alm_frm_cntx.ATPwrCycle / 60);
    IncrementTime(*alarmTime, incTime, alarmTime);
    *Freq = ALM_FREQ_ONCE;
}


/*****************************************************************************
 * FUNCTION
 *  ResetExpiryHandler
 * DESCRIPTION
 *  Set facrtory mode alarm.
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 ResetExpiryHandler(U8 index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!power_on)
    {
        AlmSendPowerOn();
    }
    *period = ALM_WITHOUD_EXPIRY_PERIOD;
    return ALM_HAS_NO_IND;
}


/*****************************************************************************
 * FUNCTION
 *  AlmIsPowerOffMode
 * DESCRIPTION
 *  Function to check if it's currently in power off mode
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if alarm shall be executed as power off mode; otherwise, FALSE.
 *****************************************************************************/
BOOL AlmIsPowerOffMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((g_pwr_context.PowerOnMode != POWER_ON_KEYPAD) && (g_pwr_context.PowerOnMode != POWER_ON_EXCEPTION));
}


/*****************************************************************************
 * FUNCTION
 *  AlmSetExpiryTimeCB
 * DESCRIPTION
 *  Set callback function of getting alarm expiry time by alarm type.
 * PARAMETERS
 *  AlmType                 [IN]        
 *  funcPtr                 [IN]        
 *  ExpiryTimeCBPtr(?)      [IN]        Function point
 *  U8(?)                   [IN]        Alarm type
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSetExpiryTimeCB(U8 AlmType, ExpiryTimeCBPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAlmCBHandler[AlmType].expiryTimeCBPtr = funcPtr;
}


/*****************************************************************************
 * FUNCTION
 *  AlmSetExpiryHandlerCB
 * DESCRIPTION
 *  Set callback function of alarm expiry handler.
 * PARAMETERS
 *  AlmType                     [IN]        
 *  expiryHandler               [IN]        
 *  ExpiryHandlerCBPtr(?)       [IN]        Function point
 *  U8(?)                       [IN]        Alarm type
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSetExpiryHandlerCB(U8 AlmType, ExpiryHandlerCBPtr expiryHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAlmCBHandler[AlmType].expiryHandlerCBPtr = expiryHandler;
}


/*****************************************************************************
 * FUNCTION
 *  AlmSetInitHandlerCB
 * DESCRIPTION
 *  Set callback function of initing NVRAM and re-scheduling alarm queue.
 * PARAMETERS
 *  AlmType                         [IN]        
 *  initNvram                       [IN]        
 *  reInitQueue                     [IN]        
 *  ReInitAlarmQueueCBPtr(?)        [IN]        Function point
 *  InitAlarmNvramCBPtr(?)          [IN]        Function point
 *  U8(?)                           [IN]        Alarm type
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSetInitHandlerCB(U8 AlmType, InitAlarmNvramCBPtr initNvram, ReInitAlarmQueueCBPtr reInitQueue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAlmCBHandler[AlmType].initAlarmNvramCBPtr = initNvram;
    gAlmCBHandler[AlmType].reInitAlarmQueueCBPtr = reInitQueue;
}


/*****************************************************************************
 * FUNCTION
 *  AlmSetStopAlarmCB
 * DESCRIPTION
 *  Set callback function of stopping alarm when timeout
 * PARAMETERS
 *  AlmType                 [IN]        
 *  stopAlarm               [IN]        
 *  StopAlarmCBPtr(?)       [IN]        Function point
 *  U8(?)                   [IN]        Alarm type
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSetStopAlarmCB(U8 AlmType, StopAlarmCBPtr stopAlarm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAlmCBHandler[AlmType].stopAlarmCBPtr = stopAlarm;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_set_start_index
 * DESCRIPTION
 *  Set start index of alarm application
 * PARAMETERS
 *  AlmType         [IN]        
 *  startIndex      [IN]        
 *  U8(?)           [IN]        Start index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_set_start_index(U8 AlmType, U8 startIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAlmCBHandler[AlmType].alarmStartIndex = startIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_index_from_queue
 * DESCRIPTION
 *  get alarm index from queue.
 * PARAMETERS
 *  num         [IN]        
 *  U8(?)       [IN]        Nth item of alarm queue
 * RETURNS
 *  U8 OUT   alarm index
 *****************************************************************************/
U8 mmi_alm_get_index_from_queue(U8 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gAlmQueue[num].Index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_freq_order
 * DESCRIPTION
 *  Get frequency index of inline selection.
 * PARAMETERS
 *  freqNum     [IN]        
 *  freqSet     [IN]        
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_alm_get_freq_order(U8 freqNum, const U8 *freqSet, U8 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < freqNum; i++)
    {
        if (freqSet[i] == freq)
        {
            return i;
        }
    }
    MMI_ASSERT(i < freqNum);

    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_disable_pwroff
 * DESCRIPTION
 *  For applications executing during power off mode,
 *  and not allow alarm framework to shutdown the system when finishing alarm expiry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_disable_pwroff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_frm_cntx.IsAppExecuting++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_enable_pwroff
 * DESCRIPTION
 *  Reference of mmi_alm_disable_pwroff,
 *  need to be executed when stopping application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_enable_pwroff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_frm_cntx.IsAppExecuting != 0)
    {
        g_alm_frm_cntx.IsAppExecuting--;
    }
}
#endif /* _MMI_ALARMFRAMEWORK_C */ // #ifndef _MMI_ALARMFRAMEWORK_C

