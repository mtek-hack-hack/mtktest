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
 * AlarmResDef.h
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

   FILENAME : AlarmResDef.h

   PURPOSE     : Alarm application 

   REMARKS     : nil

   AUTHOR      : Sophie Lin

   DATE     : August 14,07

**************************************************************/

#ifndef _MMI_ALARMDEFDEF_H
#define _MMI_ALARMDEFDEF_H


typedef enum
{
    SCR_ID_ALM_LIST = ALARM_BASE + 1,
    SCR_ID_ALM_SAVE_CONFIRM,
    SCR_ID_ALM_INDICATION,
    SCR_ID_ALM_PWRON_CONFIRM,
    SCR_ID_ALM_EDITOR,
    SCR_ID_ALM_SUB_INDICATION,
    SCR_ID_ALM_AUDIO_OPT_FMRADIO,
    SCR_ID_ALM_AUDIO_OPT_FMRADIO_CHANNEL_LIST,
    SCR_ID_ALM_AUDIO_OPT_FMRDO_CHANNEL_OPT,
    SCR_ID_ALM_FMRDO_PREV,
    SCR_ID_ALM_FMRDO_MANUAL_INPUT,
    SCR_ID_ALM_FMRDO_MANUAL_INPUT_OPT,
    SCR_ID_ALM_TONE_SETUP,
    SCR_ID_ALM_TONE_SETUP_EXT_MELODY,
    SCR_ID_ALM_TONE_SETUP_EXT_MELODY_DRV,
    SCR_ID_ALM_SETTING
} SCR_ID_ALM_ENUM;

typedef enum
{
    ORGANIZER_MENU_ALARMS_STRINGID = ALARM_BASE + 1,
    ALARMS_STOP_STRINGID,
    ALARMS_SNOOZE_STRINGID,
    ALARM_EDIT_TITLE_STRINGID,
    ALARM_STR_DONE,
    ALARM_REPEAT_STRING,
    ALARM_REPEAT_OFF_INDEX,
    ALARM_ONCE_STRING,
    ALARM_HOURLY_STRING,
    ALARM_EVREYDAY_STRING,
    ALARM_DAYS_STRING,
    ALARM_WEEKLY_STRING,
    ALARM_MONTHLY_STRING,
    ALARM_SEASONLY_STRING,
    ALARM_YEARLY_STRING,
    ALARMS_EDIT_SOFTKEY_STRINGID,
    ALARMS_POWER_ON,
    ALARMS_VOLUME,
    STR_ID_ALM_AUDIO_OPTIONS,
    STR_ID_ALM_AUDIO_OPTIONS_TONE,
    STR_ID_ALM_AUDIO_OPTIONS_FMRADIO,
    STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_CHANNELLIST,
    STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_MAN_INPUT,
    STR_ID_ALM_AUDIO_OPT_FMRDO_OPT_PREV,
    STR_ID_ALM_FMRDO_VALID_FM_BANDWIDTH,
    STR_ID_ALM_FMRDO_HEADFONE_REMINDER,
    STR_ID_ALM_FMRDO_AUD_OPT_INCOMPLETE_NOTIFY,
    STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE,
    STR_ID_ALM_FMRDO_INCOMPLETE_CHANNEL_INFO,
    ALARMS_SETTING_STRINGID,
    ALARMS_SETTING_SNOOZE_INTERVAL,
    STR_ID_ALM_DEFAULT
} STR_ID_ALM_ENUM;

typedef enum
{
    ALARMS_MAIN_TITLE_IMAGEID = ALARM_BASE + 1,
    ALARMS_EDIT_SOFTKEY_IMAGEID,
    ALARMS_SET_TITLE_IMAGEID,
    ALARM_ANIMATION_INDICATION_IMAGEID,
    ALARM_ANIMATION_INDICATION_SUBLCD_IMAGEID,
    ALARMS_STOP_IMAGEID,
    ALARMS_SNOOZE_IMAGEID,
    ORGANIZER_MENU_ALARMS_IMAGEID,
    ALARM_VOLUME_IMAGEID,
    IMG_ALM_AUD_OPT,
    ALARMS_SET_SNOOZE_PERIOD_IMAGEID,
    ALARMS_SET_ALERT_TYPE_IMAGEID,
    ALARMS_IMAGEID_ALL
} IMG_ID_ALM_ENUM;

#endif /*_MMI_ALARMDEFDEF_H*/
