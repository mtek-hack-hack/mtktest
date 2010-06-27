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
 * AlarmFrameworkProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines constant, enum value, structure, and function prototypes used in alarm framework.
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

   FILENAME : AlarmFrameWorkProt.h

   PURPOSE     : Alarms application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Jun 16,03

**************************************************************/

#ifndef _PIXTEL_ALARMFRAMEWORKPROT_H
#define _PIXTEL_ALARMFRAMEWORKPROT_H

#include "MMI_features.h"
#include "DateTimeType.h"
#include "custom_mmi_default_value.h"
/* 
 * Define
 */
#define  ALM_ALL_DAYS         0x7F
#define  ALM_WEEK_DAYS        0x3e      /* 0111110, default day of week */

#define  ALM_SNOOZE_INTERVAL  4 /* in minutes */
#define  ALM_EXPIRE_DURATION     30000
#define  ALM_FACTORY_RTC_TIME 3
#define ALM_DEFAULT_EXPIRY_PERIOD 30
#define ALM_WITHOUD_EXPIRY_PERIOD 0

/* 
 * Typedef 
 */
typedef struct
{
    U8 CurrAlmIndex;    /* index of current expired alarm */
    U8 EnabledAlarms;
    U8 IsAlmTonePlaying;
    U8 IsPwronAlarm;    /* tells if power on is bcos of alarm */
    U8 IsExitByTimer;
    U8 IsWaitForPwroff;
    U8 IsPendingAlm;
    U8 IsSpofDisabled;
    U8 IsExpiryDisabled;
    U8 IsATPwrOffAnimation;
    U8 ATPwrCycle;
    U8 IsAppExecuting;  /* set true when application is executing and could not power off */
} alm_framework_context_struct;

typedef struct
{
    MYTIME Time;
    U8 Index;
    U8 IsExpired;
} alm_queue_node_struct;

typedef enum
{
    ALM_SPON_START = 0,
    ALM_THM_START = (ALM_SPON_START + NUM_OF_SPOF),
    ALM_TDL_START = (ALM_THM_START + NUM_OF_THM_ALM),
    ALM_ALM_START = (ALM_TDL_START + NUM_OF_TDL),
    ALM_FMSR_START = (ALM_ALM_START + NUM_OF_ALM),  /* For Schedule FM Record */
    ALM_SPOF_START = (ALM_FMSR_START + NUM_OF_FMSR),
    ALM_FACTORY = (ALM_SPOF_START + NUM_OF_SPOF),
    ALM_PWR_RESET,
    ALM_SYNCML, /* 1 alarm for syncml */
    ALM_LANGLN,
    ALM_INDEX_TOTAL
} ALM_INDEX_ENUM;

typedef enum
{
    ALM_HAS_NO_IND = 0,
    ALM_HAS_IND
} ALM_INDICATION_ENUM;

typedef enum
{
    ALM_TYPE_SPON = 0,
#ifdef __MMI_THEMES_APPLICATION__
    ALM_TYPE_THEME,
#endif 
#if defined(__MMI_TODOLIST__)
    ALM_TYPE_TDL,
#endif 
    ALM_TYPE_ALARM,
#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
    ALM_TYPE_FMSR,
#endif 
    ALM_TYPE_SPOF,
    ALM_TYPE_FACTORY,
    ALM_TYPE_PWR_RESET,
#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))
    ALM_TYPE_SYNCML,
#endif
#if (defined(__MMI_LANGLN_WK_ALARM__))
    ALM_TYPE_LANGLN,
#endif
    ALM_TYPE_TOTAL_NUM
} ALM_TYPE_ENUM;

typedef enum
{
    ALM_FREQ_OFF,
    ALM_FREQ_ONCE,
    ALM_FREQ_HOURLY,
    ALM_FREQ_EVERYDAY,
    ALM_FREQ_DAYS,
    ALM_FREQ_WEEKLY,
    ALM_FREQ_MONTHLY,
    ALM_FREQ_SEASONALLY,
    ALM_FREQ_YEARLY,
    ALM_FREQ_TOTAL
} FREQ_ALARM;

typedef void (*ExpiryTimeCBPtr) (U8, MYTIME *, U8 *, U8 *, MYTIME *);
typedef U8(*ExpiryHandlerCBPtr) (U8 index, U16 *period, BOOL power_on);
typedef void (*InitAlarmNvramCBPtr) (void);
typedef void (*ReInitAlarmQueueCBPtr) (void);
typedef void (*StopAlarmCBPtr) (void);

/* alarm callback functionstuct */
typedef struct
{
    U8 alarmStartIndex;
    ExpiryTimeCBPtr expiryTimeCBPtr;
    ExpiryHandlerCBPtr expiryHandlerCBPtr;
    InitAlarmNvramCBPtr initAlarmNvramCBPtr;
    ReInitAlarmQueueCBPtr reInitAlarmQueueCBPtr;
    StopAlarmCBPtr stopAlarmCBPtr;
} AlarmCallback;

/* 
 * Extern Global Variable
 */
extern alm_framework_context_struct g_alm_frm_cntx;
extern AlarmCallback gAlmCBHandler[ALM_TYPE_TOTAL_NUM];
extern S8 *gAlmFreqList[ALM_FREQ_TOTAL];

/* 
 * Extern Global Function
 */
   /* global */
extern void InitAlarmFrameWork(void);
extern void AlmDeInit(void);
extern void AlmInitRTCPwron(void);
extern void PendingAlarmReminder(void);
extern void PendingAlarmInPwronPeriod(void);
extern U8 AlmIsRTCPwron(void);
extern void AlmReInitialize(void);
extern void AlmDisableSPOF(void);
extern void AlmEnableSPOF(void);
extern U8 AlmIsTonePlaying(void);
extern MMI_BOOL mmi_alm_is_in_alarm(void);

   /* alarm related files */
extern void AlmSendPowerOn(void);
extern void AlmSendPowerOff(void);
extern void AlmPlayAlarmTone(void);
extern void AlmsStopAlarmTone(void);
extern void AlmExecPwrOffAlarm(void);
extern void AlmExecPwrOnAlarm(void);
extern void AlmSetAlarm(U8 index);
extern void AlmCancelAlarm(U8 index);
extern void AlmCancelMulltiAlarm(U8* index, U8 amount);
extern void AlmGetStringValue(S8 *StringVal, U8 Val);

extern void AlmSetExpiryTimeCB(U8 AlmType, ExpiryTimeCBPtr funcPtr);
extern void AlmSetExpiryHandlerCB(U8 AlmType, ExpiryHandlerCBPtr expiryHandler);
extern void AlmSetInitHandlerCB(U8 AlmType, InitAlarmNvramCBPtr initNvram, ReInitAlarmQueueCBPtr reInitQueue);
extern void AlmSetStopAlarmCB(U8 AlmType, StopAlarmCBPtr stopAlarm);
extern void mmi_alm_set_start_index(U8 AlmType, U8 startIndex);
extern U8 mmi_alm_get_index_from_queue(U8 num);
extern U8 mmi_alm_get_freq_order(U8 freqNum, const U8 *freqSet, U8 freq);
extern void mmi_alm_disable_pwroff(void);
extern void mmi_alm_enable_pwroff(void);

   /* local */
extern void AlmStartAlarmOnHW(MYTIME alarmTime);
extern void AlmStopAlarmOnHW(void);
extern U8 AlmInsertIntoQueue(U8 index, U8 saveflag);
extern U8 AlmRemoveFromQueue(U8 index, U8 saveflag);
extern MYTIME AlmActualTime(MYTIME t, FREQ_ALARM frequency, U8 weekDays);
extern U8 AlmFindNodeInQueue(U8 index);
extern U8 AlmGetType(U8 index);
extern void AlmWriteQueueToNvram(void);
extern void AlmInitQueue(void);
extern U8 AlmGetRepeat(U8 index);
extern void AlmExpiryHandler(void *msg);
extern void AlmExitPreviousAlarm(void);
extern void AlmSetAlarmRSP(void *msg);
extern void AlmHandleAlarmTimeout(void);
extern void AlmHandlePendingTimeout(void);
extern void AlmCheckAlarmState(void);
extern void AlmInitLCDModule(void);
extern void AlmDisableExpiryHandler(void);
extern void AlmEnableExpiryHandler(void);
extern MYTIME AlmGetAlarmTime(U8 index);
extern void AlmATPowerReset(U8 power_off, U8 time);
extern BOOL AlmIsPowerOffMode(void);
extern void FactoryExpiryTimeCB(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder);
extern void ResetExpiryTimeCB(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder);
extern U8 ResetExpiryHandler(U8 index, U16 *period, BOOL power_on);
extern U8 mmi_alm_spof_disable_check(void);

#if (defined(__MMI_ENGINEER_MODE__))      /* Robin Add 1001 for MMI Feature */
extern void FactorySetAlarm(U8 sec);
extern U8 FactoryExpiryHandler(U8 Index, U16 *period, BOOL power_on);
#endif /* defined(__MMI_ENGINEER_MODE__)) */ 

#endif /* _PIXTEL_ALARMFRAMEWORKPROT_H */ 

