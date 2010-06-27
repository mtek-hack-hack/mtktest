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
 * AlarmDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines string, screen, and image ids for alarm application.
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
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : AlarmDef.h

   PURPOSE     : Alarm application 

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : June 16,03

**************************************************************/
#ifndef _MMI_ALARMDEF_H
#define _MMI_ALARMDEF_H

#include "MMIDataType.h"
#include "DateTimeType.h"
#include "AlarmFrameworkProt.h"
#include "AlarmResDef.h"
/* 
 * Define
 */
#define SIZE_OF_DATE_STRING   (13*ENCODING_LENGTH)      /* Jan, 10 2004 + 1 */
#define MAX_SNOOZE_CHANCES 10

/* PMT Pankaj removedd the macro for count of number of menu items in the Edit Alarm screen. */
#define NUM_STATE_FOR_ALM 2

#ifdef __MMI_ADVANCED_TODO__
#define NUM_STATE_FOR_TDL 5
#else /* __MMI_ADVANCED_TODO__ */ 
#define NUM_STATE_FOR_TDL 2
#endif /* __MMI_ADVANCED_TODO__ */ 

#ifdef __MMI_ALM_AUDIO_OPTIONS__
#define NUM_AUDIO_OPTIONS 2
#endif 

#define NUM_DAYS 7
#define HOUR_LENGTH 2
#define MINUTE_LENGTH 2
#define COLON_LENGTH  1
#define AM_PM_LENGTH 2
#define SPACE_LENGTH 1
#define SIZE_OF_ALARM_STRING  ((HOUR_LENGTH + MINUTE_LENGTH + COLON_LENGTH + AM_PM_LENGTH + SPACE_LENGTH + 1) * ENCODING_LENGTH)
#define ALARM_FREQ_NUM 3

#define SET_STATE 1
#define UNSET_STATE  0

#ifdef __MMI_ALM_AUDIO_OPTIONS__
#define MAX_MANUAL_INPUT_LEN 6
#define MIN_FM_FREQUENCY 875
#define MAX_FM_FREQUENCY 1080

typedef enum ALM_AUDIO_OPTIONS
{
    ALM_AUDIO_OPTIONS_TONE,
    ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL,
    ALM_AUDIO_OPTIONS_FMRADIO_MANUAL
} ALM_AUDIO_OPTIONS;
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

/* +3 for AM /PM */
#ifdef __MMI_ALM_SNOOZE_SETTING__
#define ALM_SNOOZE_INTERVAL_SETTING_NUM 11
#endif 
#ifdef __MMI_ALM_ALERT_TYPE__
#ifndef __VIBRATOR_TONE_SUPPORT__  //su-2008/12/04
#define ALM_ALERT_TYPE_SETTING_NUM 3
#define ALM_ALERT_VIBRATION_AND_RING 0
#define ALM_ALERT_RING 1
#define ALM_ALERT_VIBRATION 2
#else
#define ALM_ALERT_TYPE_SETTING_NUM 2
#define ALM_ALERT_VIBRATION_AND_RING 3
#define ALM_ALERT_RING 0
#define ALM_ALERT_VIBRATION 1

#endif
#endif /* __MMI_ALM_ALERT_TYPE__ */ 
/* 
 * Typedef 
 */
typedef struct
{
    S32 CurrHiliteState;                                /* enabled or disabled state */
    S32 CurrHiliteFreq;                                 /* index of current selected frequency, used in inline selection */
#ifdef __MMI_ALM_CUST_VOLUME__
    S32 CurrHiliteVol;                                  /* index of current highlighted volume */
#endif 
    alm_nvram_struct AlmList[NUM_OF_ALM];
    S8 HourBuf[(HOUR_LENGTH + 1) *ENCODING_LENGTH];     /* to take the input for hh */
    S8 MinBuf[(MINUTE_LENGTH + 1) *ENCODING_LENGTH];    /* to take the input for mm */
    U8 CurrHiliteAlarm;                                 /* index of current highlighted alarm */
    U8 IsSaveToHistory;                                 /* shall alarm screen save to history or not */
    U8 IsDOWSet;                                        /* to see if DOW component is enabled */
    U8 CurrHiliteSetting;
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    S32 CurrHiliteAudioOption;                          /* the current alarm's audio option */
    U16 CurrHiliteAudioOptionValue;                     /* The value can be <Ring Tone ID> or <FM Frequency> or <Channel List ID> */
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 
#ifdef __MMI_ALM_SNOOZE_SETTING__
    S32 CurrHilightSnoozeInterval;
#endif 
#ifdef __MMI_ALM_ALERT_TYPE__
    S32 CurrHilightAlertType;
#endif 
} alm_context_struct;

#ifndef NUM_MONTHS
#define NUM_MONTHS 12
#define NUM_MIN_HR  60
#define NUM_HRS_DAY  24

typedef enum MONTH_LIST
{
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
} MONTH_LIST;
#endif /* NUM_MONTHS */ 

typedef enum TIME_EQUALITY
{
    TIME_LESS = -1,
    TIME_EQUAL,
    TIME_GREATER
} TIME_EQUALITY;

/* 
 * Extern Global Variable
 */
extern alm_context_struct g_alm_cntx;

/* 
 * Extern Global Function
 */

#endif /* _MMI_ALARMDEF_H */ // #ifndef _MMI_ALARMDEF_H

