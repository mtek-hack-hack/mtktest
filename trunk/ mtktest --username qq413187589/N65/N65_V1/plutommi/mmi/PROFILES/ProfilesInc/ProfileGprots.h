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
 * ProfileGprots.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Profiles application global function prototypes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : ProfileGprots.h

   PURPOSE     : Profiles application global function prototypes

   REMARKS     : nil

   AUTHOR      : Ashima Bajaj

   DATE     : 

**************************************************************/

#ifndef _PIXCOM_PROFILESGPROTS_H
#define _PIXCOM_PROFILESGPROTS_H

#include "audioInc.h"
#include "resource_audio.h"

#include "SettingProfile.h"
#include "UserProfilesResDef.h"

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern pBOOL AudioFileDeletedFromFmgr(U16 tone_id);
#endif 

extern BOOL mmi_profiles_check_DRM_content_forwardable(UI_string_type filename);
extern void initnvramprofapp(void);
extern S16 InitProfileApp(void);

#ifdef __MMI_BT_PROFILE__
extern BOOL mmi_profiles_bt_is_activated(void);
extern void mmi_profiles_bt_activate_profile(void);
extern void mmi_profiles_bt_deactivate_profile(void);
extern void mmi_profiles_bt_connect_req(U8 connect_type);
extern void mmi_profiles_bt_disconnect_req(U8 connect_type);
extern void mmi_profiles_bt_connect_callback(U8 connect_type, U8 callback_type, U16 result);
extern void mmi_profiles_bt_disconnect_callback(U8 connect_type, U8 callback_type, U16 result);
extern BOOL mmi_profiles_bt_is_connected(U8 connect_type);
extern BOOL mmi_profiles_bt_is_sco_connect_allowed(void);
extern void mmi_profiles_bt_call_start_callback(void);
extern void mmi_profiles_bt_call_end_callback(void);
extern BOOL mmi_profiles_bt_connect_sco(void (*callback) (void));
extern BOOL mmi_profiles_bt_disconnect_sco(void);

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
extern void mmi_profiles_bt_disable_sco_timeout(void);
extern void mmi_profiles_bt_enable_sco_timeout(void);
extern void mmi_profiles_bt_disable_sco_connection(void);
extern void mmi_profiles_bt_enable_sco_connection(void);
extern void mmi_profiles_bt_sco_timeout(void);
extern MMI_BOOL mmi_profiles_bt_inquery_start_callback(void (*callback) (void));
extern void mmi_profiles_bt_inquery_stop_callback(void);
extern void mmi_profiles_bt_connect_audio_via_sco(void);
#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */


#endif /* __MMI_BT_PROFILE__ */ 
extern void mmi_profiles_headset_activate_profile(void);
extern void mmi_profiles_headset_deactivate_profile(void);
extern void mmi_profiles_earphone_plug_in_callback(void);
extern void mmi_profiles_earphone_plug_out_callback(void);
extern void ActivateSilentProfile(void);
extern void DeactivateSilentProfile(void);
extern void initializeProfiles(void);
extern void mmi_profiles_restore_activated_profile(void);

//Interface functions for other applications
//Interface for ringvolume level
extern MMI_VOLUME_LEVEL_ENUM GetRingVolumeLevel(void);

/* Interface for keypad_volume_level */
extern MMI_VOLUME_LEVEL_ENUM GetKeypadVolumeLevel(void);

/* Interface for loudspeaker volume level */
extern MMI_VOLUME_LEVEL_ENUM GetLoudspkrVolumeLevel(void);

/* Interface for mt_call_alert_type_enum */
extern MMI_ALERT_TYPE GetMtCallAlertTypeEnum(void);

/* Interface for Ring_ToneID */
extern U16 GetRingToneID(void);

/* Interface for Video Call ToneID */
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern U16 GetCard2RingToneID(void);
#endif

/* Interface for Video Call ToneID */
#ifdef __MMI_VIDEO_TELEPHONY__
extern U16 GetVideoCallToneID(void);
#endif

/* Interface for Light */
extern MMI_LEDLIGHT_STATUS_ENUM GetLightStatus(void);

/* Interface for Ring_Type_Enum */
extern MMI_RING_TYPE_ENUM GetRingTypeEnum(void);

#ifdef __MMI_CONNECT_NOTICE__
/* Interface for MMI_CONNECT_NOTICE_TYPE */
extern U16 GetConnectNoticeType(void);
#endif /* __MMI_CONNECT_NOTICE__ */ 
/* Interface for Answering_Mode_Enum */
extern MMI_ANSWERING_MODE *GetAnsweringMode(void);

/* Interface for loud_speaker */
extern pBOOL LoudSpeaker(void);

/* Interface for Font_Size_Enum */
extern MMI_FONT_SIZE_ENUM FontSizeEnum(void);

/* Activating a profile by name */
extern void ActivateProfile(void);
extern void ActivatefirstProfile(void);

/* Interface function for error tone status */
extern pBOOL GetErrorToneStatus(void);

/* Interface function for connect tone status */
extern pBOOL GetConnectToneStatus(void);

/* Interface function for powertone type */
extern POWERON_TONE_ENUM GetPowerOnToneType(void);

/* Interface function for poweroff tone type */
extern POWEROFF_TONE_ENUM GetPowerOffToneType(void);

/* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
/* Interface function for coveropen tone type */
extern COVER_OPEN_TONE_ENUM GetCoverOpenToneType(void);

/* Interface function for coverclose tone type */
extern COVER_CLOSE_TONE_ENUM GetCoverCloseToneType(void);
#endif /* __MMI_CLAMSHELL__ */ 
//MTK end
//Interface function for Keypadtone type
extern KEYPAD_TONE_ENUM GetKeypadToneType(void);

/* Interface function for warning tone type */
extern pBOOL GetWarningToneType(void);

/* Interface function message tone type */
extern MESSAGE_TONE_ENUM GetMessageToneType(void);

/* Interface function alarmtone type */
extern ALARM_TONE_ENUM GetAlarmToneType(void);

/* interface function for lcd timer */
extern U8 get_lcdbacklighttimer(void);

/***********************Proto Types for Set functions***********/
extern S16 SetRingVolumeLevel(MMI_VOLUME_LEVEL_ENUM);

/* MTK Brian added for setting activated ring tone volume, 2003/12/02 */
extern S16 SetActivatedRingVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel);

extern S16 SetKeypadVolumeLevel(MMI_VOLUME_LEVEL_ENUM);

/* MTK Brian added for setting activated keypad volume, 2003/12/02 */
extern S16 SetActivatedKeypadVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel);

extern S16 SetMtCallAlertTypeEnum(MMI_ALERT_TYPE);

extern S16 SetRingToneID(U16);
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern S16 SetCard2RingToneID(U16);
#endif
#ifdef __MMI_VIDEO_TELEPHONY__
extern S16 SetVideoCallToneID(U16);
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern void ThemeManagerSetRingTone(U16 ringtoneid);
extern void ThemeManagerResetRingTone(void);
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern void ThemeManagerSetCard2RingTone(U16 ringtoneid);
extern void ThemeManagerResetCard2RingTone(void);
#endif
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

extern S16 SetLightStatus(MMI_LEDLIGHT_STATUS_ENUM);

extern S16 SetRingTypeEnum(MMI_RING_TYPE_ENUM);

#ifdef __MMI_CONNECT_NOTICE__
extern S16 SetConnectNotice(U16 type);
#endif 

extern S16 SetAnsweringMode(MMI_ANSWERING_MODE);

extern S16 SetLoudSpeaker(pBOOL);

extern S16 SetErrorToneStatus(pBOOL);

#ifndef __MMI_CONNECT_NOTICE__
extern S16 SetConnectToneStatus(pBOOL);
#endif 

extern S16 SetPowerOnToneType(TONE_SETUP);

extern S16 SetPowerOffToneType(TONE_SETUP);

/* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
extern S16 SetCoverOpenToneType(TONE_SETUP);

extern S16 SetCoverCloseToneType(TONE_SETUP);
#endif /* __MMI_CLAMSHELL__ */ 
/* MTK end */

extern S16 SetKeypadToneType(KEYPAD_TONE_ENUM);
extern MMI_INTELLIGENT_CALL_ALERT_TYPE GetIntelligentCallAert(void);
extern S16 SetIntelligentCallAert(MMI_INTELLIGENT_CALL_ALERT_TYPE);
extern S16 SetMessageToneType(TONE_SETUP);
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern S16 SetCard2MessageToneType(TONE_SETUP);
#endif

extern S16 SetAlarmToneID(U16);

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern void ThemeManagerSetAlarmTone(U16 ringtoneid);
extern void ThemeManagerResetAlarmTone(void);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

//extern U8 set_lcdbacklighttimer(void);

extern S16 SetExtraTone(EXTRA_TONE);

extern void playRequestedTone(ALL_TONE_ENUM);

extern void stopRequestedTone(ALL_TONE_ENUM);
extern void playRequestedToneWithId(U16 toneid, ALL_TONE_ENUM playtone);
extern void stopRequestedToneWithId(U16 toneid, ALL_TONE_ENUM playtone);
extern void SetPlayReqToneFlag(pBOOL flag);
extern pBOOL GetPlayReqToneFlag(void);
extern void UpdateDeleteDownloadedRingTone(U16);
extern void UpdateDeleteDownloadedAlarmTone(U16);
extern void SetCurrentProfileAsActivatedProfile(void);
extern BOOL IsHeadsetModeActivated(void);
extern pBOOL IsSilentModeActivated(void);
extern BOOL IsMeetingModeActivated(void);
extern pBOOL SetProfileDefault(void);

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
extern void EntryPrfSetRingToneExtMelodyDrv(void);
extern void HighlightPrfSetRingToneExtMelody(S32 index);
extern void UpdateDeleteExtMldToneSetup(U16 ToneId);
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

#endif /* _PIXCOM_PROFILESGPROTS_H */ 

