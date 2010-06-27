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
 * SettingProf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for profile API
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/***************** Settings Application implementation *********************/

/**************************************************************

   FILENAME : Profiles.c

   PURPOSE     : API's to all applications.

   REMARKS     : nil

   AUTHOR      : Ashima Bajaj, Deepali

   DATE     : 5/5/2003

**************************************************************/

#include "MMI_include.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "SettingDefs.h"
#include "ProfileGprots.h"
#include "UserProfilesResDef.h"
#include "ProfilesGexdcl.h"
#include "gpioInc.h"
#include "AudioInc.h"
#include "mdi_audio.h"
#include "IdleAppDef.h"
#include "ProfilesGexdcl.h"
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#else
#include "CallManagementGProt.h"
#endif
#include "Profiles_prot.h"
#include "ProfilesDefs.h"       /* MTK robin 1119, AT command set wallpaper and profile */
#include "ATHandlerProt.h"
/* Leo add for DLT */
#include "DownloadDefs.h"
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
/* Leo end */
#ifdef __MMI_BT_PROFILE__
#include "BTMMICM.h"
#include "BTMMICMGprots.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#ifdef __MMI_A2DP_SUPPORT__
#include "BTMMIA2DP.h"
#endif
#endif /* __MMI_BT_PROFILE__ */ 

#ifdef __MMI_USB_SUPPORT__
#define MMI_PROF_GENERAL_KEYPAD_TIMER_DUR 15    /* sec */
extern kal_bool INT_USBBoot(void);
#endif /* __MMI_USB_SUPPORT__ */ 

#ifdef __MMI_AUDIO_PLAYER__
extern BOOL mmi_audply_save_volume(U8 volume);
extern void mmi_audply_bt_power_off_callback(BOOL success);
extern BOOL mmi_audply_is_playing(void);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifdef __MMI_FM_RADIO__
extern void mmi_fmrdo_power_on_main_screen(BOOL turn_on);
extern void mmi_fmrdo_power_on(BOOL turn_on);
#endif /* __MMI_FM_RADIO__ */ 

#if defined(__MMI_ALM_AUDIO_OPTIONS__) || defined(__MMI_ALM_CUSTOMIZE_TONE__)
#include "AlarmDef.h"
#include "AlarmProt.h"

extern alm_context_struct g_alm_cntx;
extern alm_framework_context_struct g_alm_frm_cntx;
#endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) || defined(__MMI_ALM_CUSTOMIZE_TONE__) */ 

extern void mdi_audio_set_audio_mode(U8 mode);
extern void change_font(void);

#ifdef __MMI_BT_PROFILE__
extern void mmi_bt_a2dp_deactivate_req(void);
U8 g_mmi_profiles_bt_reset_pending = 0;
BOOL g_mmi_profiles_bt_in_call = FALSE;
static MMI_BOOL g_mmi_profiles_bt_allow_sco = MMI_TRUE; /* Allow SCO connection */
static MMI_BOOL g_mmi_profiles_bt_inquerying = MMI_FALSE; /* No SCO connection when inquerying */

#ifdef __MMI_HFP_SUPPORT__
BOOL g_mmi_profiles_bt_always_use_in_call = FALSE;
static void (*mmi_profiles_bt_connect_sco_app_callback) (void) = NULL;
BOOL g_mmi_profiles_bt_app_in_use = FALSE;
#endif /* __MMI_HFP_SUPPORT__ */ 
#endif /* __MMI_BT_PROFILE__ */ 

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
#include "mdi_video.h"

#define BT_SCO_CONNECT_TIMEOUT_DURATION 20000 /* Timeout to disconnect duration */
static MMI_BOOL g_mmi_profiles_bt_sco_timeout = MMI_TRUE; /* Timeout mechanism */
static void (*g_mmi_profiles_bt_inquery_callback) (void) = NULL;
#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif/*__MMI_SUBLCD_MASTER_MODE__*/


/*****************************************************************************
 * FUNCTION
 *  initializeProfiles
 * DESCRIPTION
 *  Set default values in profiles structure.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initializeProfiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_profiles_get_dynamic_tone_ids();
    /* Initialising General Profile */
    gprofiles[0].toneSetup.ringTone = gstartMidiId;
    gprofiles[0].toneSetup.videoCallTone = gstartMidiId + 1;
    gprofiles[0].toneSetup.alarmTone = (gstartMidiId + 2);
    gprofiles[0].toneSetup.powerOnTone = (gstartGeneralToneId);
    gprofiles[0].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[0].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[0].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
    /* MTK end */
    gprofiles[0].toneSetup.messageTone = (gstartMiscToneId + 4);
    gprofiles[0].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[0].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[0].ringTypeEnum = REPEAT;
    gprofiles[0].extraTone.connectTone = 0;
    gprofiles[0].extraTone.errorTone = 1;
    gprofiles[0].extraTone.campOnTone = 1;
    gprofiles[0].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[0].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[0].answeringMode.anyKey = 0;
    gprofiles[0].answeringMode.automatic = 1;
    gprofiles[0].light.timer.setsec = 15;
    gprofiles[0].light.status = COLOR_PATTERN1;
    gprofiles[0].fontSizeEnum = THEME_DEFAULT;
    gprofiles[0].keypadVolumeLevel = LEVEL2;
    gprofiles[0].ringVolumeLevel = LEVEL4;
    gprofiles[0].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[0].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[0].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[0].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    gprofiles[1].toneSetup.ringTone = gstartMidiId;
    gprofiles[1].toneSetup.videoCallTone = gstartMidiId + 1;    
    gprofiles[1].toneSetup.alarmTone = (gstartMidiId + 2);
    gprofiles[1].toneSetup.powerOnTone = (POWERON_SILENT);
    gprofiles[1].toneSetup.powerOffTone = (POWEROFF_SILENT);
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[1].toneSetup.coverOpenTone = (COVER_OPEN_SILENT);
    gprofiles[1].toneSetup.coverCloseTone = (COVER_CLOSE_SILENT);
#endif /* __MMI_CLAMSHELL__ */ 
    /* MTK end */
    gprofiles[1].toneSetup.messageTone = (MESSAGE_SILENT);
    gprofiles[1].toneSetup.keypadTone = KEYPAD_SILENT;
    gprofiles[1].mtCallAlertTypeEnum = MMI_VIBRATION_ONLY;
    gprofiles[1].ringTypeEnum = SINGLE;
    gprofiles[1].extraTone.connectTone = 0;
    gprofiles[1].extraTone.errorTone = 0;
    gprofiles[1].extraTone.campOnTone = 0;
    gprofiles[1].extraTone.warningTone = 0;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[1].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[1].answeringMode.anyKey = 0;
    gprofiles[1].answeringMode.automatic = 1;
    gprofiles[1].light.timer.setsec = 15;
    gprofiles[1].light.status = COLOR_PATTERN1;
    gprofiles[1].fontSizeEnum = THEME_DEFAULT;
    gprofiles[1].keypadVolumeLevel = LEVEL1;
    gprofiles[1].ringVolumeLevel = LEVEL4;
    gprofiles[1].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[1].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[1].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[1].toneSetup.card2_messageTone = (MESSAGE_SILENT);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising Outdoor Profile */
    gprofiles[2].toneSetup.ringTone = gstartMidiId;
    gprofiles[2].toneSetup.videoCallTone = gstartMidiId + 1;    
    gprofiles[2].toneSetup.alarmTone = (gstartMidiId + 2);
    gprofiles[2].toneSetup.powerOnTone = (gstartGeneralToneId + 0);
    gprofiles[2].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[2].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[2].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
    /* MTK end */
    gprofiles[2].toneSetup.messageTone = (gstartMiscToneId + 4);
    gprofiles[2].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[2].mtCallAlertTypeEnum = MMI_VIBRATION_AND_RING;
    gprofiles[2].ringTypeEnum = REPEAT;
    gprofiles[2].extraTone.connectTone = 0;
    gprofiles[2].extraTone.errorTone = 1;
    gprofiles[2].extraTone.campOnTone = 1;
    gprofiles[2].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[2].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[2].answeringMode.anyKey = 0;
    gprofiles[2].answeringMode.automatic = 1;
    gprofiles[2].light.timer.setsec = 15;
    gprofiles[2].light.status = COLOR_PATTERN1;
    gprofiles[2].fontSizeEnum = THEME_DEFAULT;
    gprofiles[2].keypadVolumeLevel = LEVEL7;
    gprofiles[2].ringVolumeLevel = LEVEL7;
    gprofiles[2].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[2].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[2].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[2].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising Indoor Profile */
    gprofiles[3].toneSetup.ringTone = gstartMidiId;
    gprofiles[3].toneSetup.videoCallTone = gstartMidiId + 1;
    gprofiles[3].toneSetup.alarmTone = (gstartMidiId + 2);
    gprofiles[3].toneSetup.powerOnTone = (gstartGeneralToneId + 0);
    gprofiles[3].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[3].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[3].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
    /* MTK end */
    gprofiles[3].toneSetup.messageTone = (gstartMiscToneId + 4);
    gprofiles[3].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[3].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[3].ringTypeEnum = ASCENDING;
    gprofiles[3].extraTone.connectTone = 0;
    gprofiles[3].extraTone.errorTone = 1;
    gprofiles[3].extraTone.campOnTone = 1;
    gprofiles[3].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[3].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[3].answeringMode.anyKey = 0;
    gprofiles[3].answeringMode.automatic = 1;
    gprofiles[3].light.timer.setsec = 15;
    gprofiles[3].light.status = COLOR_PATTERN1;
    gprofiles[3].fontSizeEnum = THEME_DEFAULT;
    gprofiles[3].keypadVolumeLevel = LEVEL1;
    gprofiles[3].ringVolumeLevel = LEVEL3;
    gprofiles[3].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[3].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[3].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[3].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising Headset Profile */
    gprofiles[4].toneSetup.ringTone = gstartMidiId;
    gprofiles[4].toneSetup.videoCallTone = gstartMidiId + 1;
    gprofiles[4].toneSetup.alarmTone = (gstartMidiId + 2);
    gprofiles[4].toneSetup.powerOnTone = (gstartGeneralToneId + 0);
    gprofiles[4].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[4].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[4].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
    /* MTK end */
    gprofiles[4].toneSetup.messageTone = (gstartMiscToneId + 4);
    gprofiles[4].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[4].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[4].ringTypeEnum = REPEAT;
    gprofiles[4].extraTone.connectTone = 0;
    gprofiles[4].extraTone.errorTone = 1;
    gprofiles[4].extraTone.campOnTone = 1;
    gprofiles[4].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[4].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */

    gprofiles[4].answeringMode.anyKey = 0;
    /* MTK: Brian added for KLM */
    gprofiles[4].answeringMode.automatic = 1;
    /* MTK end */
    gprofiles[4].light.timer.setsec = 15;
    gprofiles[4].light.status = COLOR_PATTERN1;
    gprofiles[4].fontSizeEnum = THEME_DEFAULT;
    gprofiles[4].keypadVolumeLevel = LEVEL2;
    gprofiles[4].ringVolumeLevel = LEVEL4;
    gprofiles[4].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[4].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[4].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[4].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising Silent Profile */
    gprofiles[5].toneSetup.ringTone = gstartMidiId;
    gprofiles[5].toneSetup.videoCallTone = gstartMidiId + 1;
    gprofiles[5].toneSetup.alarmTone = (gstartMidiId + 2);
    gprofiles[5].toneSetup.powerOnTone = (POWERON_SILENT);
    gprofiles[5].toneSetup.powerOffTone = (POWEROFF_SILENT);
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[5].toneSetup.coverOpenTone = (COVER_OPEN_SILENT);
    gprofiles[5].toneSetup.coverCloseTone = (COVER_CLOSE_SILENT);
#endif /* __MMI_CLAMSHELL__ */ 
    /* MTK end */
    gprofiles[5].toneSetup.messageTone = (MESSAGE_SILENT);
    gprofiles[5].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[5].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[5].ringTypeEnum = REPEAT;
    gprofiles[5].extraTone.connectTone = 0;
    gprofiles[5].extraTone.errorTone = 1;
    gprofiles[5].extraTone.campOnTone = 1;
    gprofiles[5].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[5].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[5].answeringMode.anyKey = 0;
    gprofiles[5].answeringMode.automatic = 1;
    gprofiles[5].light.timer.setsec = 15;
    gprofiles[5].light.status = COLOR_PATTERN1;
    gprofiles[5].fontSizeEnum = THEME_DEFAULT;
    gprofiles[5].keypadVolumeLevel = LEVEL5;
    gprofiles[5].ringVolumeLevel = LEVEL3;
    gprofiles[5].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[5].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[5].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[5].toneSetup.card2_messageTone = (MESSAGE_SILENT);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising LoudSpeaker Profile */
    gprofiles[6].toneSetup.ringTone = gstartMidiId;
    gprofiles[6].toneSetup.videoCallTone = gstartMidiId + 1;
    gprofiles[6].toneSetup.alarmTone = (gstartMidiId + 2);
    gprofiles[6].toneSetup.powerOnTone = (gstartGeneralToneId + 0);
    gprofiles[6].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[6].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[6].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
    /* MTK end */
    gprofiles[6].toneSetup.messageTone = (gstartMiscToneId + 4);
    gprofiles[6].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[6].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[6].ringTypeEnum = REPEAT;
    gprofiles[6].extraTone.connectTone = 0;
    gprofiles[6].extraTone.errorTone = 1;
    gprofiles[6].extraTone.campOnTone = 1;
    gprofiles[6].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[6].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[6].answeringMode.anyKey = 0;
    gprofiles[6].answeringMode.automatic = 1;
    gprofiles[6].light.timer.setsec = 15;
    gprofiles[6].light.status = COLOR_PATTERN1;
    gprofiles[6].fontSizeEnum = THEME_DEFAULT;
    gprofiles[6].keypadVolumeLevel = LEVEL5;
    gprofiles[6].ringVolumeLevel = LEVEL3;
    gprofiles[6].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[6].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[6].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[6].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  GetRingVolumeLevel
 * DESCRIPTION
 *  Setting Ring Volume Level for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_VOLUME_LEVEL_ENUM GetRingVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_VOLUME_LEVEL_ENUM ringVolumeLevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ringVolumeLevel = gcurrentprofile.ringVolumeLevel;

    PRINT_INFORMATION("File: Setting Prof.c <<GetRingVolumeLevel>\
		               the ring volume level is : %d \n", ringVolumeLevel);

    return ringVolumeLevel;
}


/*****************************************************************************
 * FUNCTION
 *  GetLoudspkrVolumeLevel
 * DESCRIPTION
 *  Setting Ring Volume Level for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_VOLUME_LEVEL_ENUM GetLoudspkrVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_VOLUME_LEVEL_ENUM loudspkr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    loudspkr = gprofiles[6].loudSpeakerVolumeLevel;

    PRINT_INFORMATION("File: Setting Prof.c <<GetLoudspkrVolumeLevel>\
		               the loud volume level is : %d \n", loudspkr);

    return loudspkr;
}


/*****************************************************************************
 * FUNCTION
 *  GetKeypadVolumeLevel
 * DESCRIPTION
 *  Setting Keypad Volume Level for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_VOLUME_LEVEL_ENUM GetKeypadVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_VOLUME_LEVEL_ENUM keypadVolumeLevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    keypadVolumeLevel = gcurrentprofile.keypadVolumeLevel;

    PRINT_INFORMATION("File: Setting Prof.c <<GetKeypadVolumeLevel>\
		               the keypadVolumeLevel is : %d \n", keypadVolumeLevel);

    return keypadVolumeLevel;
}


/*****************************************************************************
 * FUNCTION
 *  GetMtCallAlertTypeEnum
 * DESCRIPTION
 *  Setting Call Alert type for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ALERT_TYPE GetMtCallAlertTypeEnum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ALERT_TYPE mtCallAlertTypeEnum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtCallAlertTypeEnum = gcurrentprofile.mtCallAlertTypeEnum;

    PRINT_INFORMATION("File: Setting Prof.c <<GetMtCallAlertTypeEnum>\
		               the mtCallAlertTypeEnum is : %d \n", mtCallAlertTypeEnum);

    return mtCallAlertTypeEnum;
}


/*****************************************************************************
 * FUNCTION
 *  GetLightStatus
 * DESCRIPTION
 *  Setting Light for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_LEDLIGHT_STATUS_ENUM GetLightStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    LIGHT templight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    templight.status = gcurrentprofile.light.status;

    PRINT_INFORMATION("File: Setting Prof.c <<GetLightStatus>\
		               the light color is : %d \n", templight.status);

    return templight.status;
}


/*****************************************************************************
 * FUNCTION
 *  GetRingTypeEnum
 * DESCRIPTION
 *  Setting Ring_Type for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RING_TYPE_ENUM GetRingTypeEnum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_RING_TYPE_ENUM ringType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ringType = gcurrentprofile.ringTypeEnum;
    switch (ringType)
    {
        case SINGLE:
            return 2;
        case REPEAT:
            return 1;
        case ASCENDING:
            return 0;
        default:
            return 1;
    }

    PRINT_INFORMATION("File: Setting Prof.c <<GetRingTypeEnum>\
		               the ringType is : %d \n", ringType);

}

#ifdef __MMI_CONNECT_NOTICE__


/*****************************************************************************
 * FUNCTION
 *  GetConnectNoticeType
 * DESCRIPTION
 *  Setting Call Alert type for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetConnectNoticeType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CONNECT_NOTICE_TYPE connectNotice;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    connectNotice = gcurrentprofile.extraTone.connectTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetConnectNoticeType>\
		               the GetConnectNoticeType is : %d \n", connectNotice);

    return (U16) connectNotice;
}
#endif /* __MMI_CONNECT_NOTICE__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetAnsweringMode
 * DESCRIPTION
 *  Setting Answering mode for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ANSWERING_MODE *GetAnsweringMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_ANSWERING_MODE answeringMode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    answeringMode.coverAnswer = gcurrentprofile.answeringMode.coverAnswer;
#endif 
    /* MTK end */

    /* MTK: Brian modified for auto answer if test sim, 031020 */
#ifdef __GEMINI__
    if (is_test_sim(0x00) || is_test_sim(0x01) || gactivatedprofile == MMI_PROFILE_HEADSET)
    {
#else
    if (is_test_sim() || gactivatedprofile == MMI_PROFILE_HEADSET) 
    {   
#endif
        answeringMode.automatic = gcurrentprofile.answeringMode.automatic;
    }
    else
    {
        answeringMode.automatic = FALSE;
    }
    //MTK: Brian end
    //answeringMode.automatic = gcurrentprofile.answeringMode.automatic;
    answeringMode.anyKey = gcurrentprofile.answeringMode.anyKey;

    return &answeringMode;
}


/*****************************************************************************
 * FUNCTION
 *  LoudSpeaker
 * DESCRIPTION
 *  Setting loud speaker for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL LoudSpeaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL loudSpeaker;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    loudSpeaker = gloudSpeaker;

    PRINT_INFORMATION("File: Setting Prof.c <<LoudSpeaker>\
		               the loudSpeaker is : %d \n", loudSpeaker);

    return loudSpeaker;

}


/*****************************************************************************
 * FUNCTION
 *  FontSizeEnum
 * DESCRIPTION
 *  Setting Font Size for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_FONT_SIZE_ENUM FontSizeEnum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FONT_SIZE_ENUM fontSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fontSize = gcurrentprofile.fontSizeEnum;

    PRINT_INFORMATION("File: Setting Prof.c <<FontSizeEnum>\
		               the fontSize is : %d \n", fontSize);

    return fontSize;
}


/*****************************************************************************
 * FUNCTION
 *  GetConnectToneStatus
 * DESCRIPTION
 *  Setting Extra Tone for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetConnectToneStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EXTRA_TONE tempExtraTone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tempExtraTone.connectTone = gcurrentprofile.extraTone.connectTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetConnectToneStatus>\
		               the connectTone is : %d \n", tempExtraTone.connectTone);

    return tempExtraTone.connectTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetErrorToneStatus
 * DESCRIPTION
 *  Setting Extra Tone for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetErrorToneStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EXTRA_TONE tempExtraTone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tempExtraTone.errorTone = gcurrentprofile.extraTone.errorTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetErrorToneStatus>\
		               the errorTone is : %d \n", tempExtraTone.errorTone);

    return tempExtraTone.errorTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetRingToneID
 * DESCRIPTION
 *  Setting ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetRingToneID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.ringTone = gcurrentprofile.toneSetup.ringTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetRingToneID>\
		               the RingToneID is : %d \n", temptoneSetup.ringTone);

    return temptoneSetup.ringTone;
}

#ifdef __MMI_DUAL_PROFILE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  GetCard2RingToneID
 * DESCRIPTION
 *  Get card2 ring tone id of current profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetCard2RingToneID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.card2_ringTone = gcurrentprofile.toneSetup.card2_ringTone;

    return temptoneSetup.card2_ringTone;
}
#endif

#ifdef __MMI_VIDEO_TELEPHONY__

/*****************************************************************************
 * FUNCTION
 *  GetVideoCallToneID
 * DESCRIPTION
 *  Get video call tone id of current profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetVideoCallToneID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.videoCallTone = gcurrentprofile.toneSetup.videoCallTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetVideoCallToneID>\
		               the VideoCallToneID is : %d \n", temptoneSetup.videoCallTone);

    return temptoneSetup.videoCallTone;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  GetPowerOnToneType
 * DESCRIPTION
 *  Setting power tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
POWERON_TONE_ENUM GetPowerOnToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.powerOnTone = gcurrentprofile.toneSetup.powerOnTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetPowerOnToneType>\
		               the PowerOnTone is : %d \n", temptoneSetup.powerOnTone);

    return temptoneSetup.powerOnTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetPowerOffToneType
 * DESCRIPTION
 *  Setting power tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
POWEROFF_TONE_ENUM GetPowerOffToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.powerOffTone = gcurrentprofile.toneSetup.powerOffTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetPowerOffToneType>\
		               the PowerOffTone is : %d \n", temptoneSetup.powerOffTone);

    return temptoneSetup.powerOffTone;
}

/* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__


/*****************************************************************************
 * FUNCTION
 *  GetCoverOpenToneType
 * DESCRIPTION
 *  Setting coveropentone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
COVER_OPEN_TONE_ENUM GetCoverOpenToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.coverOpenTone = gcurrentprofile.toneSetup.coverOpenTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetCoverOpenToneType>\
		               the CoverOpenTone is : %d \n", temptoneSetup.coverOpenTone);

    return temptoneSetup.coverOpenTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetCoverCloseToneType
 * DESCRIPTION
 *  Setting power tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
COVER_CLOSE_TONE_ENUM GetCoverCloseToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.coverCloseTone = gcurrentprofile.toneSetup.coverCloseTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetCoverCloseToneType>\
		               the CoverCloseTone is : %d \n", temptoneSetup.coverCloseTone);

    return temptoneSetup.coverCloseTone;
}
#endif /* __MMI_CLAMSHELL__ */ 
/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  GetKeypadToneType
 * DESCRIPTION
 *  Setting Keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
KEYPAD_TONE_ENUM GetKeypadToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.keypadTone = gcurrentprofile.toneSetup.keypadTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetKeypadToneType>\
		               the keypadTone is : %d \n", temptoneSetup.keypadTone);

    return temptoneSetup.keypadTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetWarningToneType
 * DESCRIPTION
 *  Setting warning tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetWarningToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EXTRA_TONE temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.warningTone = gcurrentprofile.extraTone.warningTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetWarningToneType>\
		               the warningTone is : %d \n", temptoneSetup.warningTone);

    return temptoneSetup.warningTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetMessageToneType
 * DESCRIPTION
 *  Setting warning tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MESSAGE_TONE_ENUM GetMessageToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.messageTone = gcurrentprofile.toneSetup.messageTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetMessageToneType>\
		               the messageTone is : %d \n", temptoneSetup.messageTone);

    return temptoneSetup.messageTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetAlarmToneType
 * DESCRIPTION
 *  Setting warning tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
ALARM_TONE_ENUM GetAlarmToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.alarmTone = gcurrentprofile.toneSetup.alarmTone;

    PRINT_INFORMATION("File: Setting Prof.c <<GetAlarmToneType>\
		               the alarmTone is : %d \n", temptoneSetup.alarmTone);

    return (ALARM_TONE_ENUM) (temptoneSetup.alarmTone);
}


/*****************************************************************************
 * FUNCTION
 *  get_lcdbacklighttimer
 * DESCRIPTION
 *  Setting lcdbacklight timer value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 get_lcdbacklighttimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    LIGHT tempLight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USB_SUPPORT__
    if (INT_USBBoot())
    {
        return MMI_PROF_GENERAL_KEYPAD_TIMER_DUR;
    }
#endif /* __MMI_USB_SUPPORT__ */ 

    tempLight.timer.setsec = gcurrentprofile.light.timer.setsec;

    PRINT_INFORMATION("File: Setting Prof.c <<get_lcdbacklighttimer>\
		               the timer is %d seconds \n", tempLight.timer.setsec);

    return tempLight.timer.setsec;
}


/*****************************************************************************
 * FUNCTION
 *  ActivateProfile
 * DESCRIPTION
 *  Activating a profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);

    PRINT_INFORMATION("Activated Profile : %d ", (int)gactivatedprofile);

    if (gactivatedprofile == 0xff)
    {
        gactivatedprofile = 0;
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));

        /* SetRingerVolume(GetRingVolumeLevel()); */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
    }
    else
    {
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));

        /* SetRingerVolume(GetRingVolumeLevel()); */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
    }
    mdi_audio_set_mic_volume();
    mmi_profiles_show_alert_status_icon();
    change_font();

/*******************************************************/
    /* Robin 0602, Remove set AT command profile functions */
    /* AT command will query MMI when needed               */
/*******************************************************/
    /*
     * if (gactivatedprofile==5)
     * SilentModeOn();
     * else
     * SilentModeOff();
     */

}


/*****************************************************************************
 * FUNCTION
 *  ActivatefirstProfile
 * DESCRIPTION
 *  Activating the profile first time bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivatefirstProfile()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gactivatedprofile = gprofileId;
    memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_stop_silent_profile_vibrate
 * DESCRIPTION
 *  stop silent profile vibrator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_stop_silent_profile_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TIMER_PROFILES_TONE_PLAY);
    VibratorOff();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_restore_activated_profile
 * DESCRIPTION
 *  restore audio mode & current activated profile after factory mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_restore_activated_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_gpio_is_earphone_plug_in())
    {
        /* enter headset mode */
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
        SetModeSpeechVolume();
        mmi_profiles_headset_activate_profile();
    }
    else
    {
        /* enter non-headset mode */
        mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
        SetModeSpeechVolume();
        ActivateProfile();
    }
#if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ActivateSilentProfile
 * DESCRIPTION
 *  Silent Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateSilentProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_PROFILE__
    if ((gactivatedprofile != MMI_PROFILE_SILENT) && (gprofileheadset != 1) && (gactivatedprofile != MMI_PROFILE_BT))
#else 
    if ((gactivatedprofile != MMI_PROFILE_SILENT) && (gprofileheadset != 1))
#endif 
    {
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
        glastactivatedprofile = gactivatedprofile;
        gactivatedprofile = gprofileId = MMI_PROFILE_SILENT;
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);
        WriteValue(NVRAM_PROFILES_LASTACTIVATED, &glastactivatedprofile, DS_BYTE, &error);
        /* MTK brian modified to make it vibrate in silent mode, 2003/10/28 */
        gcurrentprofile.mtCallAlertTypeEnum = MMI_VIBRATION_ONLY;
        /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
    #ifdef __MMI_CLAMSHELL__
        gcurrentprofile.toneSetup.coverCloseTone = COVER_CLOSE_SILENT;
        gcurrentprofile.toneSetup.coverOpenTone = COVER_OPEN_SILENT;
    #endif /* __MMI_CLAMSHELL__ */ 
        /* MTK end */
        gcurrentprofile.toneSetup.keypadTone = KEYPAD_SILENT;
        gcurrentprofile.toneSetup.messageTone = MESSAGE_SILENT;
        gcurrentprofile.toneSetup.powerOffTone = POWEROFF_SILENT;
        gcurrentprofile.toneSetup.powerOnTone = POWERON_SILENT;

        gcurrentprofile.extraTone.campOnTone = 0;
        gcurrentprofile.extraTone.errorTone = 0;
        gcurrentprofile.extraTone.connectTone = 0;
        gcurrentprofile.extraTone.warningTone = 0;

        gcurrentprofile.intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;

        memcpy(&gprofiles[gactivatedprofile], &gcurrentprofile, sizeof(PROFILE));
        WriteRecord(NVRAM_EF_PROFILES_LID, j, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error);

        DisplayPopup((U8*) GetString(STR_SILENT_ACTIVATE_MESSAGE), IMG_GLOBAL_ACTIVATED, 1, 2000, (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
        DeleteScreenIfPresent(SCR_DIAL_SOS_NUM); /* enable toggle profile from sim error screen */

        mmi_profiles_show_alert_status_icon();

      /************************************************/
        /* Robin 0602, Remove set AT command profile functions */
        /* AT command will query MMI when needed                   */
      /************************************************/
        /* SilentModeOn(); */

        VibratorOn();
        StartTimer(TIMER_PROFILES_TONE_PLAY, 1000, mmi_profiles_stop_silent_profile_vibrate);
    }

}


/*****************************************************************************
 * FUNCTION
 *  DeactivateSilentProfile
 * DESCRIPTION
 *  DeactivateSilent Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeactivateSilentProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_SILENT)
    {
        gprofileId = 0;
        gactivatedprofile = glastactivatedprofile;
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);

        /* SetRingerVolume(GetRingVolumeLevel()); */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
        change_font();

        switch (gactivatedprofile)
        {
            case MMI_PROFILE_GENERAL:
                DisplayPopup(
                    (U8*) GetString(STR_GENERAL_RESTORED_MESSAGE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    2000,
                    (U8) SUCCESS_TONE);
                break;
            case MMI_PROFILE_MEETING:
                DisplayPopup(
                    (U8*) GetString(STR_MEETING_RESTORED_MESSAGE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    2000,
                    (U8) SUCCESS_TONE);
                break;
            case MMI_PROFILE_OUTDOOR:
                DisplayPopup(
                    (U8*) GetString(STR_OUTDOOR_RESTORED_MESSAGE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    2000,
                    (U8) SUCCESS_TONE);
                break;
            case MMI_PROFILE_INDOOR:
                DisplayPopup(
                    (U8*) GetString(STR_INDOOR_RESTORED_MESSAGE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    2000,
                    (U8) SUCCESS_TONE);
                break;
            case MMI_PROFILE_HEADSET:
                /* DisplayPopup((U8*)GetString(STR_HEADSET_RESTORED_MESSAGE),IMG_GLOBAL_ACTIVATED,1,2000,(U8)SUCCESS_TONE); */
                break;

            case MMI_PROFILE_SILENT:
                /* DisplayPopup((U8*)GetString(STR_SILENT_RESTORED_MESSAGE),IMG_GLOBAL_ACTIVATED,1,2000,(U8)SUCCESS_TONE); */
                break;
        #ifdef __MMI_BT_PROFILE__
            case MMI_PROFILE_BT:
        #endif 
                break;
        }
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
        DeleteScreenIfPresent(SCR_DIAL_SOS_NUM); /* enable toggle profile from sim error screen */

        mmi_profiles_show_alert_status_icon();

      /************************************************/
        /* Robin 0602, Remove set AT command profile functions */
        /* AT command will query MMI when needed                   */
      /************************************************/
        /* SilentModeOff(); */
    }
}

/*************************************************************************
               Set Functions
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  SetRingVolumeLevel
 * DESCRIPTION
 *  Setting Ring Volume Level
 * PARAMETERS
 *  volumelevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetRingVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;
    MMI_VOLUME_LEVEL_ENUM ringVolumeLevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].ringVolumeLevel = volumelevel;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetRingVolumeLevel: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
/***** restore the ring volume of activated profile******/
    ringVolumeLevel = gprofiles[gactivatedprofile].ringVolumeLevel;

    SetRingerVolume(ringVolumeLevel);

    return 0;
}

/* MTK Brian added for setting activated ring tone volume, 2003/12/02 */


/*****************************************************************************
 * FUNCTION
 *  SetActivatedRingVolumeLevel
 * DESCRIPTION
 *  Setting Ring Volume Level of the Activated Profile
 * PARAMETERS
 *  volumelevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetActivatedRingVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gactivatedprofile].ringVolumeLevel = volumelevel;
    gcurrentprofile.ringVolumeLevel = volumelevel;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetRingVolumeLevel: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }

    SetRingerVolume(volumelevel);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetKeypadVolumeLevel
 * DESCRIPTION
 *  Setting Keypad Volume Level
 * PARAMETERS
 *  volumelevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetKeypadVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;
    MMI_VOLUME_LEVEL_ENUM keypadVolumelevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].keypadVolumeLevel = volumelevel;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetKeypadVolumeLevel: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
/***** restore the keypad tone volume of activated profile******/
    keypadVolumelevel = gprofiles[gactivatedprofile].keypadVolumeLevel;

    SetKeyPadVolume(keypadVolumelevel);

    return 0;
}

/* MTK Brian added for setting activated keypad volume, 2003/12/02 */


/*****************************************************************************
 * FUNCTION
 *  SetActivatedKeypadVolumeLevel
 * DESCRIPTION
 *  Setting Keypad Volume Level of the Activated Profile
 * PARAMETERS
 *  volumelevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetActivatedKeypadVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gactivatedprofile].keypadVolumeLevel = volumelevel;
    gcurrentprofile.keypadVolumeLevel = volumelevel;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetActivatedKeypadVolumeLevel: WriteRecord "
                           "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }

    SetKeyPadVolume(volumelevel);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetMtCallAlertTypeEnum
 * DESCRIPTION
 *  Setting Call Alert Type
 * PARAMETERS
 *  callalerttype       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetMtCallAlertTypeEnum(MMI_ALERT_TYPE callalerttype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Brian modified to skip writing nvram if no change, 2003/11/26 */
    if (gprofiles[gprofileId].mtCallAlertTypeEnum != callalerttype)
    {
        gprofiles[gprofileId].mtCallAlertTypeEnum = callalerttype;

        if (WriteRecord(
                NVRAM_EF_PROFILES_LID,
                j,
                &gprofiles[0],
                NVRAM_PROFILES_RECORD_SIZE,
                &error) < NVRAM_PROFILES_RECORD_SIZE)
        {
            PRINT_INFORMATION("## ERROR: SetMtCallAlertTypeEnum: WriteRecord "
                               "to NVRAM failed (ecode%d)\n", (int)error);
            return error;
        }
        if (gactivatedprofile == gprofileId)
        {
            memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
        }
        mmi_profiles_show_alert_status_icon();

   /************************************************/
        /* Robin 0602, Remove set AT command profile functions */
        /* AT command will query MMI when needed                   */
   /************************************************/
        /*
         * if (callalerttype == MMI_VIBRATION_ONLY || 
         * callalerttype == MMI_VIBRATION_AND_RING||
         * callalerttype == MMI_VIBRATION_THEN_RING)
         * SendSetVibrationMode(1);
         * else      
         * SendSetVibrationMode(0);
         */
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetRingToneID
 * DESCRIPTION
 *  Setting Ring tone ID.
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetRingToneID(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.ringTone = ringtoneid;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetRingToneID: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}

#ifdef __MMI_DUAL_PROFILE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  SetCard2RingToneID
 * DESCRIPTION
 *  Setting Card2 Ring tone ID.
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetCard2RingToneID(U16 ringtoneid)
{
    S16 error = 0;
    U16 j = 1;

    gprofiles[gprofileId].toneSetup.card2_ringTone = ringtoneid;

    if (WriteRecord(NVRAM_EF_PROFILES_LID,
                    j, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }

    return 0;
}

#endif

#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  SetVideoCallToneID
 * DESCRIPTION
 *  Setting Video Call tone ID.
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetVideoCallToneID(U16 videocalltoneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.videoCallTone = videocalltoneId;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetVideoCallToneID: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  ThemeManagerSetRingTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerSetRingTone(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gactivatedprofile].toneSetup.ringTone = ringtoneid;
    WriteRecord(NVRAM_EF_PROFILES_LID, 1, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error);
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
}


/*****************************************************************************
 * FUNCTION
 *  ThemeManagerResetRingTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerResetRingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = 0, i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ELEMENTS; ++i)
    {
        if (gprofiles[i].toneSetup.ringTone == CURRENT_THEME_INCOMING_CALL_TONE)
        {
            flag = 1;
            gprofiles[i].toneSetup.ringTone = MIDI_1;
        }
    }
    if (flag)
    {
        WriteRecord(NVRAM_EF_PROFILES_LID, 1, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error);
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
    }
}

#ifdef __MMI_DUAL_PROFILE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  ThemeManagerSetCard2RingTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerSetCard2RingTone(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gactivatedprofile].toneSetup.card2_ringTone = ringtoneid;
    WriteRecord(NVRAM_EF_PROFILES_LID, 1, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error);
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
}

/*****************************************************************************
 * FUNCTION
 *  ThemeManagerResetCard2RingTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerResetCard2RingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = 0, i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ELEMENTS; ++i)
    {
        if (gprofiles[i].toneSetup.card2_ringTone == CURRENT_THEME_INCOMING_CALL_TONE)
        {
            flag = 1;
            gprofiles[i].toneSetup.card2_ringTone = MIDI_1;
        }
    }
    if (flag)
    {
        WriteRecord(NVRAM_EF_PROFILES_LID, 1, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error);
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
    }
}
#endif /*__MMI_DUAL_PROFILE_SUPPORT__*/

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetLightStatus
 * DESCRIPTION
 *  Setting Light status (Color)
 * PARAMETERS
 *  backlightstatus     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetLightStatus(MMI_LEDLIGHT_STATUS_ENUM backlightstatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].light.status = backlightstatus;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetLightStatus: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetRingTypeEnum
 * DESCRIPTION
 *  Setting Ring Type
 * PARAMETERS
 *  ringtype        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetRingTypeEnum(MMI_RING_TYPE_ENUM ringtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].ringTypeEnum = ringtype;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetRingTypeEnum: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}

#ifdef __MMI_CONNECT_NOTICE__


/*****************************************************************************
 * FUNCTION
 *  SetConnectNotice
 * DESCRIPTION
 *  Setting Connect Notice Type
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetConnectNotice(U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].extraTone.connectTone = type;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetConnectNoticeEnum: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}
#endif /* __MMI_CONNECT_NOTICE__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetAnsweringMode
 * DESCRIPTION
 *  Setting Answering Mode
 * PARAMETERS
 *  answeringmode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetAnsweringMode(MMI_ANSWERING_MODE answeringmode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&gprofiles[gprofileId].answeringMode, &answeringmode, sizeof(MMI_ANSWERING_MODE));

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetAnsweringModeEnum: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetLoudSpeaker
 * DESCRIPTION
 *  Setting Loud Speaker (On/Off)
 * PARAMETERS
 *  loudspeaker     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetLoudSpeaker(pBOOL loudspeaker)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (loudspeaker == 1)
    {
        gloudSpeaker = loudspeaker;
    }
    else
    {
        gloudSpeaker = loudspeaker;
    }

    SetRingerVolume(GetRingVolumeLevel());
    SetKeyPadVolume(GetKeypadVolumeLevel());

    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  SetErrorToneStatus
 * DESCRIPTION
 *  Setting Error Tone status (On/Off)
 * PARAMETERS
 *  errortonestatus     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetErrorToneStatus(pBOOL errortonestatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].extraTone.errorTone = errortonestatus;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetErrorToneStatus: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}

#ifndef __MMI_CONNECT_NOTICE__


/*****************************************************************************
 * FUNCTION
 *  SetConnectToneStatus
 * DESCRIPTION
 *  Setting Connect Tone status (On/Off)
 * PARAMETERS
 *  connecttone     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetConnectToneStatus(pBOOL connecttone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].extraTone.connectTone = connecttone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetConnectToneStatus: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}
#endif /* __MMI_CONNECT_NOTICE__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetPowerOnToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetPowerOnToneType(TONE_SETUP tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.powerOnTone = tone.powerOnTone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetPowerOnToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetPowerOffToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetPowerOffToneType(TONE_SETUP tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.powerOffTone = tone.powerOffTone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetPowerOffToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}

/* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__


/*****************************************************************************
 * FUNCTION
 *  SetCoverOpenToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetCoverOpenToneType(TONE_SETUP tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.coverOpenTone = tone.coverOpenTone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetCoverOpenToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetCoverCloseToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetCoverCloseToneType(TONE_SETUP tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.coverCloseTone = tone.coverCloseTone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetCoverCloseToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}
#endif /* __MMI_CLAMSHELL__ */ 
/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  SetKeypadToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keypadtone      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetKeypadToneType(KEYPAD_TONE_ENUM keypadtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.keypadTone = keypadtone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetKeypadToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetIntelligentCallAert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_INTELLIGENT_CALL_ALERT_TYPE
 *****************************************************************************/
MMI_INTELLIGENT_CALL_ALERT_TYPE GetIntelligentCallAert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_INTELLIGENT_CALL_ALERT_TYPE intelligentCallAlert = gcurrentprofile.intelligentCallAlert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("File: Setting Prof.c <<GetIntelligentCallAlert> the intelligentCallAlert is : %d \n",
                       intelligentCallAlert);

    return intelligentCallAlert;
}


/*****************************************************************************
 * FUNCTION
 *  SetIntelligentCallAert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  intelligentCallAlert        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetIntelligentCallAert(MMI_INTELLIGENT_CALL_ALERT_TYPE intelligentCallAlert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].intelligentCallAlert = intelligentCallAlert;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetIntelligentCallAert: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetMessageToneType
 * DESCRIPTION
 *  Setting Message Tone
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetMessageToneType(TONE_SETUP tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.messageTone = tone.messageTone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetMessageToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}

#ifdef __MMI_DUAL_PROFILE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  SetCard2MessageToneType
 * DESCRIPTION
 *  Setting Card2 Message Tone
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetCard2MessageToneType(TONE_SETUP tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.card2_messageTone = tone.card2_messageTone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetCard2MessageToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  SetAlarmToneID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetAlarmToneID(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.alarmTone = id;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetAlarmToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */


/*****************************************************************************
 * FUNCTION
 *  ThemeManagerSetAlarmTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerSetAlarmTone(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* PMT SHARIQ DLT_PATCH 20060814 START */
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
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT SHARIQ DLT_PATCH 20060814 END */
}


/*****************************************************************************
 * FUNCTION
 *  ThemeManagerResetAlarmTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerResetAlarmTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = 0, i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ELEMENTS; ++i)
    {
        if (gprofiles[i].toneSetup.alarmTone == CURRENT_THEME_ALARM_EXPIRY_TONE)
        {
            flag = 1;
            gprofiles[i].toneSetup.alarmTone = MIDI_2;
        }
    }
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    for (i = 0; i < NUM_OF_ALM; ++i)
    {
        if (g_alm_cntx.AlmList[i].AudioOptionValue == CURRENT_THEME_ALARM_EXPIRY_TONE)
        {
            g_alm_cntx.AlmList[i].AudioOption = ALM_AUDIO_OPTIONS_TONE;
            g_alm_cntx.AlmList[i].AudioOptionValue = (U16) (gstartMidiId + 1);
        }
    }
    AlmWriteToNvram();
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

    if (flag)
    {
        WriteRecord(NVRAM_EF_PROFILES_LID, 1, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error);
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
    }
}
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

/*****************************************************************************
 * FUNCTION
 *  SetProfileDefault
 * DESCRIPTION
 *  SetProfileDefault
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL SetProfileDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gprofileheadset != 1)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== SetProfileDefault(): Headset mode. ===\n");

        ReadRecord(
            NVRAM_EF_PROFILES_LID,
            2,
            &gprofiles[0],
            MAX_ELEMENTS * sizeof(PROFILE) /* NVRAM_PROFILES_RECORD_SIZE */ ,
            &error);
        gactivatedprofile = 0;
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
        mmi_profiles_show_alert_status_icon(); /* function to show status icon on ilde screen */
        WriteRecord(NVRAM_EF_PROFILES_LID, 1, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error);
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);

        /*          
         * #ifdef __MMI_AUDIO_PLAYER__
         * mmi_audply_save_volume( gactivatedprofile );
         * #endif // __MMI_AUDIO_PLAYER__
         * 
         * SetRingerVolume(GetRingVolumeLevel());
         */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
        change_font();
        if (error == NVRAM_WRITE_SUCCESS)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== SetProfileDefault(): Not Headset mode. ===\n");

        ReadRecord(
            NVRAM_EF_PROFILES_LID,
            2,
            &gprofiles[0],
            MAX_ELEMENTS * sizeof(PROFILE) /* NVRAM_PROFILES_RECORD_SIZE */ ,
            &error);
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
        mmi_profiles_show_alert_status_icon(); /* function to show status icon on ilde screen */
        WriteRecord(NVRAM_EF_PROFILES_LID, 1, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error);
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);

        /*          
         * #ifdef __MMI_AUDIO_PLAYER__
         * mmi_audply_save_volume( gactivatedprofile );
         * #endif // __MMI_AUDIO_PLAYER__
         * 
         * SetRingerVolume(GetRingVolumeLevel());
         */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
        change_font();
        if (error == NVRAM_WRITE_SUCCESS)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  SetExtraTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  extraTone       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetExtraTone(EXTRA_TONE extraTone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].extraTone.warningTone = extraTone.warningTone;
    gprofiles[gprofileId].extraTone.errorTone = extraTone.errorTone;
#ifndef __MMI_CONNECT_NOTICE__
    gprofiles[gprofileId].extraTone.connectTone = extraTone.connectTone;
#endif 
    gprofiles[gprofileId].extraTone.campOnTone = extraTone.campOnTone;

    if (WriteRecord(
            NVRAM_EF_PROFILES_LID,
            j,
            &gprofiles[0],
            NVRAM_PROFILES_RECORD_SIZE,
            &error) < NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetWarningToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return error;
    }
    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  playRequestedTone
 * DESCRIPTION
 *  API to all applications to play tone.
 * PARAMETERS
 *  playtone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void playRequestedTone(ALL_TONE_ENUM playtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL setFlag = FALSE; /*set the tone play flag only for non DTMF tone paly*/
    BOOL DataCallOnly = FALSE;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("[user prof] playRequestedTone(), id=%d, profile=%d", playtone,gactivatedprofile);

    #ifdef __MMI_SUBLCD_MASTER_MODE__
    /*subLCD application requires short tone*/
    playtone = ChangeInterruptToneInMasterMode(playtone);
    #endif/*__MMI_SUBLCD_MASTER_MODE__*/

    
    switch (playtone)
    {
        case CONGESTION_TONE:
            AudioPlayReq(TONE_CONGESTION_GSM, DEVICE_AUDIO_PLAY_ONCE);
            return;
            break;
        case AUTH_FAIL_TONE:
            AudioPlayReq(TONE_AUTH_ERROR, DEVICE_AUDIO_PLAY_ONCE);
            return;
            break;
        case NUM_UNOBTAIN_TONE:
            AudioPlayReq(TONE_NUM_UNOBTAIN, DEVICE_AUDIO_PLAY_ONCE);
            return;
            break;
        case CALL_DROP_TONE:
            AudioPlayReq(TONE_RADIO_NA, DEVICE_AUDIO_PLAY_ONCE);
            return;
            break;
    }

#ifdef __MMI_UCM__
    if (mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE_ALL) == mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL))
#else /* __MMI_UCM__ */
    if (IsWapCallPresent() && GetTotalCallCount()==1)
#endif /* __MMI_UCM__ */
    {
        DataCallOnly = TRUE ;
        PRINT_INFORMATION("[user prof] DataCallOnly");
    }
    
    if (!isInCall() || DataCallOnly)
    {
        switch (playtone)
        {
            case ERROR_TONE:
                if (gcurrentprofile.extraTone.errorTone == 1)
                {
                    AudioPlayReq(TONE_ERROR1, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;

            case CONNECT_TONE:
            #ifndef __MMI_CONNECT_NOTICE__
                if (gcurrentprofile.extraTone.connectTone == 1)
            #endif 
                    AudioPlayReq(TONE_CALL_CONNECT, DEVICE_AUDIO_PLAY_ONCE);
                break;

            case CAMP_ON_TONE:
                if (gcurrentprofile.extraTone.campOnTone == 1)
                {
                    AudioPlayReq(SOUND_3, DEVICE_AUDIO_PLAY_ONCE);
                    setFlag = TRUE;
                }
                break;

            case WARNING_TONE:
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING1, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;

            case INCOMING_CALL_TONE:
                if (gactivatedprofile != MMI_PROFILE_SILENT)
                {
#if defined(NOKE_DEBUG)
            	      noke_dbg_printf("\r\n Huyanwei debug Play playRequestedTone() INCOMING_CALL_TONE\r\n");				
#endif
                    AudioPlayToneWithCallBack(gcurrentprofile.toneSetup.ringTone, (U8) GetRingTypeEnum(), INCOMING_CALL_TONE);
                    setFlag = TRUE;
                }
                break;

            case ALARM_TONE:
            #ifdef __MMI_ALM_CUSTOMIZE_TONE__
                if (g_alm_frm_cntx.CurrAlmIndex >= ALM_ALM_START && g_alm_frm_cntx.CurrAlmIndex < ALM_SPOF_START)
                {
                    AudioPlayToneWithCallBack(
                        g_alm_cntx.AlmList[g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START].AudioOptionValue,
                        DEVICE_AUDIO_PLAY_CRESCENDO,
                        ALARM_TONE);
                }
                else
            #endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
                AudioPlayToneWithCallBack(gcurrentprofile.toneSetup.alarmTone, DEVICE_AUDIO_PLAY_CRESCENDO, ALARM_TONE);

                setFlag = TRUE;
                
                break;

            case POWER_ON_TONE:
#if defined(NOKE_DEBUG)
		  noke_dbg_printf("\r\n Huyanwei debug playRequestedTone() Play POWER_ON_TONE\r\n");
#endif
                LCD_Delayms(200); //sc.wu before power_on_tone
                
                if (gcurrentprofile.toneSetup.powerOnTone != POWERON_SILENT)
                {
                    AudioPlayReq(gcurrentprofile.toneSetup.powerOnTone, DEVICE_AUDIO_PLAY_ONCE);
                    setFlag = TRUE;
                }
                break;

            case POWER_OFF_TONE:
#if defined(NOKE_DEBUG)
		  noke_dbg_printf("\r\n Huyanwei debug Play playRequestedTone() POWER_OFF_TONE\r\n");				
#endif
                if (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT)
                {
                    AudioPlayReq(gcurrentprofile.toneSetup.powerOffTone, DEVICE_AUDIO_PLAY_ONCE);
                    setFlag = TRUE;
                }
                break;

            #ifdef __MMI_CLAMSHELL__
            case COVER_OPEN_TONE:
                if (gcurrentprofile.toneSetup.coverOpenTone != COVER_OPEN_SILENT)
                {
                    AudioPlayReq(gcurrentprofile.toneSetup.coverOpenTone, DEVICE_AUDIO_PLAY_ONCE);
                    setFlag = TRUE;
                }
                break;

            case COVER_CLOSE_TONE:
                if (gcurrentprofile.toneSetup.coverCloseTone != COVER_CLOSE_SILENT)
                {
                    AudioPlayReq(gcurrentprofile.toneSetup.coverCloseTone, DEVICE_AUDIO_PLAY_ONCE);
                    setFlag = TRUE;
                }
                break;
            #endif /* __MMI_CLAMSHELL__ */ 

            case MESSAGE_TONE:
                if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT)
                {
                    AudioPlayToneWithCallBack(
                        gcurrentprofile.toneSetup.messageTone,
                        DEVICE_AUDIO_PLAY_ONCE,
                        MESSAGE_TONE);
                    setFlag = TRUE;
                }
                break;

            case SUCCESS_TONE:
                break;

            case SAVE_TONE:  
                break;

            case SMS_IN_CALL_TONE:
            {
                if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT)
                {
                    AudioPlayReq(TONE_MT_SMS_IN_CALL, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
            }

            case EMPTY_LIST_TONE:
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING1, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;

            case GENERAL_TONE:
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
                
            case AUX_TONE:
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_AUX_IND, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;

            case BATTERY_LOW_TONE:
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_BATTERY_LOW, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
                
            case BATTERY_WARNING_TONE:
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_BATTERY_WARNING, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
                
            case WARNING_TONE_IN_CALL:
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
                
            case ERROR_TONE_IN_CALL:
                if (gcurrentprofile.extraTone.errorTone == 1)
                {
                    AudioPlayReq(TONE_ERROR2, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
        #ifdef __MMI_DUAL_PROFILE_SUPPORT__
            case CARD2_MESSAGE_TONE:
                if(gcurrentprofile.toneSetup.card2_messageTone!= MESSAGE_SILENT)
                {
                    AudioPlayToneWithCallBack(gcurrentprofile.toneSetup.card2_messageTone,
                                DEVICE_AUDIO_PLAY_ONCE, CARD2_MESSAGE_TONE);
                }
                break;
            case CARD2_INCOMING_CALL_TONE:
                if(gactivatedprofile!=MMI_PROFILE_SILENT)
                {
                    AudioPlayToneWithCallBack(gcurrentprofile.toneSetup.card2_ringTone,
                                DEVICE_AUDIO_PLAY_ONCE, CARD2_INCOMING_CALL_TONE);
                    setFlag = TRUE;
                }
                break;
        #endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            
            case FILE_ARRIVAL_TONE:
                if(gactivatedprofile!=MMI_PROFILE_SILENT)
                {
                    AudioPlayReq(SOUND_4, DEVICE_AUDIO_PLAY_ONCE);
                    setFlag = TRUE;
                }
                break;
        }
    }
    else    /* No active call, No on hold call */
    {
        switch (playtone)
        {
            /* Shall play power off tone no matter in call or not */
            /* See CANNON+ SCR 3573, CSD connection, long press END key won't will power off first, then drop call */
            case POWER_OFF_TONE:
            {
#if defined(NOKE_DEBUG)
		  noke_dbg_printf("\r\n Huyanwei debug playRequestedTone(2) Play POWER_OFF_TONE\r\n");						
#endif
                if (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT)
                {
                    AudioPlayReq(gcurrentprofile.toneSetup.powerOffTone, DEVICE_AUDIO_PLAY_ONCE);
                    setFlag = TRUE;
                }
                break;
            }

            case SMS_IN_CALL_TONE:
            {
                if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT)
                {
                    AudioPlayReq(TONE_MT_SMS_IN_CALL, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
            }

            case WARNING_TONE_IN_CALL:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
            }
            
            case ERROR_TONE_IN_CALL:
            {
                if (gcurrentprofile.extraTone.errorTone == 1)
                {
                    AudioPlayReq(TONE_ERROR2, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
            }
            
            case CONNECT_TONE_IN_CALL:
            {
                if (gcurrentprofile.extraTone.connectTone == 1)
                {
                    AudioPlayReq(TONE_CALL_CONNECT, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
            }
            case SUCCESS_TONE_IN_CALL:
            {
                break;
            }
            
            case BATTERY_LOW_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
            }
            
            case BATTERY_WARNING_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
            }

/*            case AUX_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                }
                break;
            }*/
            
            case CONNECT_TONE:
            {
            #ifndef __MMI_CONNECT_NOTICE__
                if (gcurrentprofile.extraTone.connectTone == 1)
            #endif 
                    AudioPlayReq(TONE_CALL_CONNECT, DEVICE_AUDIO_PLAY_ONCE);
                break;
            }
            
            case CALL_REMINDER_TONE:
            case CCBS_TONE:
            {
                AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                break;
            }
        }
    }
    if(setFlag)
    {
#if defined(NOKE_DEBUG)
	 noke_dbg_printf("\r\n Huyanwei Debug : playRequestedTone() => SetPlayReqToneFlag() \r\n");
#endif
        SetPlayReqToneFlag(TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  stopRequestedTone
 * DESCRIPTION
 *  eneral API to all applications to stop tone.
 * PARAMETERS
 *  playtone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void stopRequestedTone(ALL_TONE_ENUM playtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL resetFlag = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("[user prof] stopRequestedTone(), id=%d, profile=%d", playtone,gactivatedprofile);
    
    #ifdef __MMI_SUBLCD_MASTER_MODE__
    /*subLCD application requires short tone*/
    playtone = ChangeInterruptToneInMasterMode(playtone);
    #endif/*__MMI_SUBLCD_MASTER_MODE__*/
    
    switch (playtone)
    {
        case ERROR_TONE:
            if (gcurrentprofile.extraTone.errorTone == 1)
            {
                AudioStopReq(TONE_ERROR1);
            }
            break;

        case CONNECT_TONE:
            if (gcurrentprofile.extraTone.connectTone == 1)
            {
                AudioStopReq(TONE_CALL_CONNECT);
            }
            break;

        case CAMP_ON_TONE:
            if (gcurrentprofile.extraTone.campOnTone == 1 && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(SOUND_3);
            }
            break;

        case WARNING_TONE:
            if (gcurrentprofile.extraTone.warningTone == 1)
            {
                AudioStopReq(TONE_WARNING1);
            }
            break;

        case ALARM_TONE:
            if(GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcallbackToneId);
            }
            break;
            
        case INCOMING_CALL_TONE:
            if (gactivatedprofile != MMI_PROFILE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
#if defined(NOKE_DEBUG)
		  noke_dbg_printf("\r\n Huyanwei Debug : stopRequestedTone() => SetPlayReqToneFlag() \r\n");				
#endif
                AudioStopReq(gcallbackToneId);
            }
            break;
            
        case POWER_ON_TONE:
            if (gcurrentprofile.toneSetup.powerOnTone != POWERON_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.powerOnTone);
            }
            break;

        case POWER_OFF_TONE:
            if (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.powerOffTone);
            }
            break;

        #ifdef __MMI_CLAMSHELL__
        case COVER_OPEN_TONE:
            if (gcurrentprofile.toneSetup.coverOpenTone != COVER_OPEN_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.coverOpenTone);
            }
            break;

        case COVER_CLOSE_TONE:
            if (gcurrentprofile.toneSetup.coverCloseTone != COVER_CLOSE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.coverCloseTone);
            }
            break;
        #endif /* __MMI_CLAMSHELL__ */ 

        case MESSAGE_TONE:
            if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcallbackToneId);
            }
            break;

        case SUCCESS_TONE:
            break;

        case SAVE_TONE:
            if (gactivatedprofile != MMI_PROFILE_SILENT)
            {
                AudioStopReq(TONE_GENERAL_BEEP);
            }
            break;

        case EMPTY_LIST_TONE:
            if (gcurrentprofile.extraTone.warningTone == 1)
            {
                AudioStopReq(TONE_WARNING1);
            }
            break;

        case GENERAL_TONE:
            if (gactivatedprofile != MMI_PROFILE_SILENT)
            {
                AudioStopReq(TONE_GENERAL_BEEP);
            }
            break;

        case SMS_IN_CALL_TONE:
            AudioStopReq(TONE_MT_SMS_IN_CALL);
            break;
            
        case BATTERY_LOW_TONE:
            AudioStopReq(TONE_BATTERY_LOW);
            break;
            
        case BATTERY_WARNING_TONE:
            AudioStopReq(TONE_BATTERY_WARNING);
            break;
            
        case CONGESTION_TONE:
            AudioStopReq(TONE_CONGESTION_GSM);
            break;
            
        case AUTH_FAIL_TONE:
            AudioStopReq(TONE_AUTH_ERROR);
            break;
            
        case NUM_UNOBTAIN_TONE:
            AudioStopReq(TONE_NUM_UNOBTAIN);
            break;
            
        case CALL_DROP_TONE:
            AudioStopReq(TONE_RADIO_NA);
            break;
    #ifdef __MMI_DUAL_PROFILE_SUPPORT__
        case CARD2_INCOMING_CALL_TONE:
            if (gactivatedprofile != MMI_PROFILE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.card2_ringTone);
            }
            break;
        case CARD2_MESSAGE_TONE:
            if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.card2_messageTone);
            }
            break;
    #endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            
        case FILE_ARRIVAL_TONE:
            if (gactivatedprofile != MMI_PROFILE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(SOUND_4);
            }
            break;    
    }

    if(resetFlag)
    {
#if defined(NOKE_DEBUG)
	 noke_dbg_printf("\r\n Huyanwei Debug : stopRequestedTone() => SetPlayReqToneFlag() \r\n");				
#endif
        SetPlayReqToneFlag(FALSE);
    }

}

/*****************************************************************************
 * FUNCTION
 *  playRequestedToneWithid
 * DESCRIPTION
 *  API to all applications to play tone with specific tone id.
 * PARAMETERS
 *  toneid          [IN]
 *  playtone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void playRequestedToneWithId(U16 toneid ,ALL_TONE_ENUM playtone)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL DataCallOnly = FALSE;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("[user prof] playRequestedToneWithId(), id=%d, profile=%d", toneid,gactivatedprofile);

#ifdef __MMI_UCM__
    if (mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE_ALL) == mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL))
#else /* __MMI_UCM__ */
    if (IsWapCallPresent() && GetTotalCallCount()==1)
#endif /* __MMI_UCM__ */
    {
        DataCallOnly = TRUE ;
    }
    
    if (isInCall())
    {
        SetPlayReqToneFlag(TRUE);
        switch (playtone)
        {
            case INCOMING_CALL_TONE:
                if (gactivatedprofile != MMI_PROFILE_SILENT)
                {
                    AudioPlayToneWithCallBack(toneid, (U8) GetRingTypeEnum(), INCOMING_CALL_TONE);
                }
                break;
            default :
                break;
        }
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  stopRequestedToneWithId
 * DESCRIPTION
 *  eneral API to all applications to stop tone with specific tone id.
 * PARAMETERS
 *  toneid          [IN]
 *  playtone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void stopRequestedToneWithId(U16 toneid, ALL_TONE_ENUM playtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("[user prof] stopRequestedToneWithId(), id=%d, profile=%d", toneid,gactivatedprofile);    

    if (GetPlayReqToneFlag() == TRUE)
    {   
        SetPlayReqToneFlag(FALSE);
        switch (playtone)
        {
            case INCOMING_CALL_TONE:
                if (gactivatedprofile != MMI_PROFILE_SILENT)
                {
                    AudioStopReq(gcallbackToneId);
                }
                break;
             default :
                break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  SetPlayReqToneFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetPlayReqToneFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n Huyanwei Debug : SetPlayReqToneFlag() (gPlayReqToneFlag = %d)\r\n",flag);
#endif
    gPlayReqToneFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetPlayReqToneFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetPlayReqToneFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPlayReqToneFlag;
}


/*****************************************************************************
 * FUNCTION
 *  UpdateDeleteDownloadedRingTone
 * DESCRIPTION
 *  set default tone when selected downloaded Ring tone is deleted.
 * PARAMETERS
 *  ToneId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateDeleteDownloadedRingTone(U16 ToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gcurrentprofile.toneSetup.ringTone == ToneId)
    {
        SetRingToneID(gstartMidiId);
    }
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
    else if(gcurrentprofile.toneSetup.card2_ringTone==ToneId)
    {
	    SetCard2RingToneID(gstartMidiId);
    }
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  UpdateDeleteExtMldToneSetup
 * DESCRIPTION
 *  set default tone when selected extented Melody Ring tone is deleted.
 * PARAMETERS
 *  ToneId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
void UpdateDeleteExtMldToneSetup(U16 ToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, dirtyFlag = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update alarm ring tone list */
#if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_ALM_CUSTOMIZE_TONE__)
    mmi_alm_tone_setup_delete_ext_melody(ToneId);
#endif 

    for (i = 0; i < MAX_ELEMENTS; i++)
    {
        if (gprofiles[i].toneSetup.ringTone == ToneId)
        {
            gprofiles[i].toneSetup.ringTone = gstartMidiId;
            dirtyFlag = 1;
        }
        if(gprofiles[i].toneSetup.videoCallTone== ToneId)
        {
            gprofiles[i].toneSetup.ringTone = gstartMidiId + 1;
            dirtyFlag = 1;
        }
        if (gprofiles[i].toneSetup.alarmTone == ToneId)
        {
            gprofiles[i].toneSetup.alarmTone = gstartMidiId + 2;
            dirtyFlag = 1;
        }
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
	if(gprofiles[i].toneSetup.card2_ringTone==ToneId)
        {
             gprofiles[i].toneSetup.card2_ringTone = gstartMidiId;
             dirtyFlag = 1;
        }
#endif	/*__MMI_DUAL_PROFILE_SUPPORT__*/

    }

    if (dirtyFlag == 1)
        if (WriteRecord(
                NVRAM_EF_PROFILES_LID,
                1,
                &gprofiles[0],
                NVRAM_PROFILES_RECORD_SIZE,
                &error) < NVRAM_PROFILES_RECORD_SIZE)
        {
            PRINT_INFORMATION("## ERROR: SetRingToneID: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
            return;
        }

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }
}
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  UpdateDeleteDownloadedAlarmTone
 * DESCRIPTION
 *  set default tone when selected downloaded alarm tone is deleted.
 * PARAMETERS
 *  ToneId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateDeleteDownloadedAlarmTone(U16 ToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gcurrentprofile.toneSetup.alarmTone == ToneId)
    {
        TONE_SETUP tonesetup;

        tonesetup.alarmTone = gstartMidiId + 1;
        SetAlarmToneID(tonesetup.alarmTone);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrentProfileAsActivatedProfile
 * DESCRIPTION
 *  Sets Current Profile As Activated Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrentProfileAsActivatedProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofileId = gactivatedprofile;
}


/*****************************************************************************
 * FUNCTION
 *  IsHeadsetModeActivated
 * DESCRIPTION
 *  Tells if headset mode is activated
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL IsHeadsetModeActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_HEADSET)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsSilentModeActivated
 * DESCRIPTION
 *  Tells if silent mode is activated
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL IsSilentModeActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_SILENT)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsMeetingModeActivated
 * DESCRIPTION
 *  Tells if meeting mode is activated
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
BOOL IsMeetingModeActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_MEETING)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* MTK robin 1119, AT command set wallpaper and profile */


/*****************************************************************************
 * FUNCTION
 *  AtSetProfileTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profileID       [IN]        
 *  tone_type       [IN]        
 *  tone_idx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL AtSetProfileTone(U8 profileID, PROFILE_TONE_TYPE_ENUM tone_type, U8 tone_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profileID >= MAX_PROFILE_NUM || tone_type >= TONE_MAX_TONE_TYPE || tone_idx > 10)
    {
        return MMI_FALSE;
    }

    switch (tone_type)
    {
        case TONE_POWERONTONE:
            if (tone_idx == 0)
            {
                gprofiles[profileID].toneSetup.powerOnTone = POWERON_SILENT;
            }
            else
            {
                gprofiles[profileID].toneSetup.powerOnTone = gstartGeneralToneId + tone_idx - 1;
            }
            break;

        default:
            return MMI_FALSE;
    }

    if (WriteRecord(NVRAM_EF_PROFILES_LID, j, &gprofiles[0], NVRAM_PROFILES_RECORD_SIZE, &error) <
        NVRAM_PROFILES_RECORD_SIZE)
    {
        PRINT_INFORMATION("## ERROR: SetPowerOnToneType: WriteRecord " "to NVRAM failed (ecode%d)\n", (int)error);
        return MMI_FALSE;
    }

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(PROFILE));
    }

    return MMI_TRUE;

}

/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_headset_activate_profile
 * DESCRIPTION
 *  Activating Headset profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_headset_activate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_headset_activate_profile: gactivatedprofile =%d, glastactivatedprofile = %d\n",
                       gactivatedprofile, glastactivatedprofile);

    gprofileheadset = 1;
    /* MTK Modified, Robin 1017, prevent activated profile and last actived profile become same one */
#ifdef __MMI_BT_PROFILE__
    if (gactivatedprofile != MMI_PROFILE_SILENT && gactivatedprofile != MMI_PROFILE_HEADSET &&
        gactivatedprofile != MMI_PROFILE_BT)
#else /* __MMI_BT_PROFILE__ */ 
    if (gactivatedprofile != MMI_PROFILE_SILENT && gactivatedprofile != MMI_PROFILE_HEADSET)
#endif /* __MMI_BT_PROFILE__ */ 
        glastactivatedprofile = gactivatedprofile;
    gactivatedprofile = MMI_PROFILE_HEADSET;
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
    WriteValue(NVRAM_PROFILES_LASTACTIVATED, &glastactivatedprofile, DS_BYTE, &error);
    mmi_profiles_show_alert_status_icon();
    change_font();

    /* SetRingerVolume(GetRingVolumeLevel()); */
    mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

    SetKeyPadVolume(GetKeypadVolumeLevel());
    mdi_audio_set_mic_volume();
    if (gloudSpeaker == 1)
    {
        gloudSpeaker = 0;
        SetLSpkNowOff(TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_headset_deactivate_profile
 * DESCRIPTION
 *  Deactivate Headset profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_headset_deactivate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_headset_deactivate_profile: gactivatedprofile =%d, glastactivatedprofile = %d\n",
                       gactivatedprofile, glastactivatedprofile);

    gprofileheadset = 0;
    ReadValue(NVRAM_PROFILES_LASTACTIVATED, &glastactivatedprofile, DS_BYTE, &error);
#ifdef __MMI_BT_PROFILE__
#endif 
    ReadValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
    mmi_profiles_show_alert_status_icon();
    change_font();

    if(gactivatedprofile == MMI_PROFILE_SILENT)
    {
    #ifdef __MMI_AUDIO_PLAYER__
        if(!mmi_audply_is_playing())
    #endif
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA,TRUE);
        }
    }

    /* SetRingerVolume(GetRingVolumeLevel()); */
    mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

    SetKeyPadVolume(GetKeypadVolumeLevel());
    mdi_audio_set_mic_volume();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_earphone_plug_in_callback
 * DESCRIPTION
 *  invoke it when plug in earphone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_earphone_plug_in_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_earphone_plug_in_callback: gactivatedprofile=%d, gprofilenvram=%d \n", gactivatedprofile,gprofilenvram);
    /*use gprofilenvram to distinguish if the plug out action is before profile application initialized*/
    if(gprofilenvram)
    {
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
        SetModeSpeechVolume();
    #ifdef __MMI_BT_PROFILE__
        if (gactivatedprofile == MMI_PROFILE_BT)
        {
        #ifdef __MMI_HFP_SUPPORT__
            mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
        #endif 
        }
    #endif /* __MMI_BT_PROFILE__ */ 
        mmi_profiles_headset_activate_profile();
    #if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
        mmi_fmrdo_power_on_main_screen(TRUE);
    #endif 
    }
    else
    {
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
    }
#if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_earphone_plug_out_callback
 * DESCRIPTION
 *  invoke it when plug out earphone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_earphone_plug_out_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_earphone_plug_out_callback: gactivatedprofile=%d, gprofilenvram=%d \n", gactivatedprofile,gprofilenvram);
    /*use gprofilenvram to distinguish if the plug out action is before profile application initialized*/
    if(gprofilenvram)
    {
    #if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
        mmi_fmrdo_power_on(FALSE);
    #endif 
    #ifdef __MMI_BT_PROFILE__
    #if 0 /* If in bluetooth profile, try to connect SCO back if in call */
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
    #ifdef __MMI_HFP_SUPPORT__
        if (mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_ACL))
        {
            mmi_profiles_bt_activate_profile();

    #ifdef __MMI_BT_AUDIO_VIA_SCO__
            /* Connect SCO according to HFP audio path setting */
            if (mmi_bt_is_aud2hf())
    #else /*__MMI_BT_AUDIO_VIA_SCO__*/
        #ifdef __MMI_BT_FM_VIA_SCO__
            /* Need to check FM radio if FM via SCO on  */
            if ((g_mmi_profiles_bt_in_call || mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO)) &&
                (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
        #else
            if (g_mmi_profiles_bt_in_call && (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
        #endif
    #endif /*__MMI_BT_AUDIO_VIA_SCO__*/
            {
                mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
            }
        }
    #endif /* __MMI_HFP_SUPPORT__ */ 
    #endif /* __MMI_BT_PROFILE__ */ 
        if (mdi_audio_get_audio_mode() != AUD_MODE_LOUDSPK)
        {
            mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
            SetModeSpeechVolume();
        }
        if (gactivatedprofile == MMI_PROFILE_HEADSET)
        {
            mmi_profiles_headset_deactivate_profile();
        }
    }
    else
    {
        mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
    }
#if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
#endif
}

#ifdef __MMI_BT_PROFILE__


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_allow_popup
 * DESCRIPTION
 *  check is it allowed to popup
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_allow_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_profiles_bt_in_call;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_connect_sco
 * DESCRIPTION
 *  connect sco link
 * PARAMETERS
 *  callback        [IN]        )(void)
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_connect_sco(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL connect = FALSE;
    S32 connect_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    PRINT_INFORMATION("mmi_profiles_bt_connect_sco: Allow SCO=[%d], BT Inquery=[%d]\n", g_mmi_profiles_bt_allow_sco, g_mmi_profiles_bt_inquerying);
    
    if(mmi_profiles_bt_is_sco_connect_allowed() &&
       gactivatedprofile == MMI_PROFILE_BT )
    {
    	if( mmi_bt_is_hs_connected() )
    	{
    		connect_id = mmi_bt_get_active_signal_connection_id( MMI_BT_HFG_PROFILE_UUID );
    		ASSERT( connect_id >= 0 );
    		connect = mdi_audio_bt_open_stream( BT_HFP, (U16)connect_id );
    		if( connect )
    		{
    			mmi_profiles_bt_connect_sco_app_callback = callback;
    		}
        #ifdef __MMI_BT_AUDIO_VIA_SCO__
            /* Already Connected, start a timeout timer */
            else if(g_mmi_profiles_bt_sco_timeout && 
                    mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
            {
                StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
            }
        #endif /* __MMI_BT_AUDIO_VIA_SCO__ */
    	}

    	g_mmi_profiles_bt_app_in_use = TRUE;
    }
#endif /* __MMI_HFP_SUPPORT__ */ 
    return connect;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disconnect_sco
 * DESCRIPTION
 *  disconnect sco link
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_disconnect_sco(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL disconnect = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    PRINT_INFORMATION("mmi_profiles_bt_disconnect_sco: in_call=%d, always_use=%d, aud2hf=%d\n",
        g_mmi_profiles_bt_in_call,g_mmi_profiles_bt_always_use_in_call,mmi_bt_is_aud2hf());

    if (!g_mmi_profiles_bt_in_call || !(g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
    {
        disconnect = mdi_audio_bt_is_stream_open(BT_HFP);
        mdi_audio_bt_close_stream(BT_HFP);
        mmi_profiles_bt_connect_sco_app_callback = NULL;
    }
    g_mmi_profiles_bt_app_in_use = FALSE;
#endif /* __MMI_HFP_SUPPORT__ */ 
    return disconnect;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_deactivate_cnf_hdlr
 * DESCRIPTION
 *  the cnf handler for bt a2dp deactivate req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_deactivate_cnf_hdlr(void)
{
    if (g_mmi_profiles_bt_reset_pending != 0)
    {
        g_mmi_profiles_bt_reset_pending &= 0x0D;
        if (g_mmi_profiles_bt_reset_pending == 0)
        {
            mmi_bt_panic_ind_post_process();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_reset
 * DESCRIPTION
 *  to reset bt profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_reset: reset_pending = %d\n", g_mmi_profiles_bt_reset_pending);

#if defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_PLAYER__)
    mmi_audply_bt_power_off_callback(TRUE);
    mmi_bt_a2dp_deactivate_req();
    if (mmi_bt_a2dp_query_state() != MMI_A2DP_STATE_IDLE)
    {
        g_mmi_profiles_bt_reset_pending |= 2;
        PRINT_INFORMATION("mmi_profiles_bt_reset: reset_pending = %d\n", g_mmi_profiles_bt_reset_pending);
    }
#endif
#ifdef __MMI_HFP_SUPPORT__
    if (mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
    {
        g_mmi_profiles_bt_reset_pending |= 1;
        mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
    }
    mmi_profiles_bt_connect_sco_app_callback = NULL;
#endif /* __MMI_HFP_SUPPORT__ */ 
    if (gactivatedprofile == MMI_PROFILE_BT)
    {
        if (mmi_gpio_is_earphone_plug_in())
        {
            mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
            mmi_profiles_headset_activate_profile();
      #if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
      #endif
        }
        else
        {
            mmi_profiles_bt_deactivate_profile();
        }
    }
    if (g_mmi_profiles_bt_reset_pending == 0)
    {
        mmi_bt_panic_ind_post_process();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_is_activated
 * DESCRIPTION
 *  to check if bt profile is activated
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_is_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gactivatedprofile == MMI_PROFILE_BT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_open_stream_callback
 * DESCRIPTION
 *  a callback function for open bt stream cnf
 * PARAMETERS
 *  profile     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_open_stream_callback(U8 profile, mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_open_stream_callback: profile =%d, result = %d\n", profile, result);

    if (result == MDI_AUDIO_SUCCESS)
    {
        res = MMI_PROFILES_BT_OK;
    }
    else if (result == MDI_AUDIO_BUSY)
    {
        res = MMI_PROFILES_BT_BUSY;
    }
    else
    {
        res = MMI_PROFILES_BT_FAIL;
    }
    switch (profile)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case BT_HFP:
            mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_SCO, MMI_PROFILES_BT_RSP, res);
            if( result == MDI_AUDIO_SUCCESS )
            {
				mmi_bth_sco_connect_ind_hdler(mmi_bt_get_active_signal_connection_id(MMI_BT_HFG_PROFILE_UUID));

    #ifdef __MMI_BT_AUDIO_VIA_SCO__
                PRINT_INFORMATION("Start SCO timer: flag = [%d]\n",g_mmi_profiles_bt_sco_timeout);
    		    if(g_mmi_profiles_bt_sco_timeout)
    		    {
                    StopTimer(BT_SCO_CONNECT_TIMER);
                    StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
                }
    #endif /* #ifdef __MMI_BT_AUDIO_VIA_SCO__ */
			}
			else
			{
				mmi_bth_sco_connect_cnf_hdler(1, mmi_bt_get_active_signal_connection_id(MMI_BT_HFG_PROFILE_UUID));
			}
            if (mmi_profiles_bt_connect_sco_app_callback != NULL)
            {
                mmi_profiles_bt_connect_sco_app_callback();
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_close_stream_callback
 * DESCRIPTION
 *  a callback function for close bt stream cnf
 * PARAMETERS
 *  profile     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_close_stream_callback(U8 profile, mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    void (*inquery_callback) (void);
#endif    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_close_stream_callback: profile =%d, result = %d\n", profile, result);

    switch (profile)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case BT_HFP:
            mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_SCO, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_OK);
    		mmi_bth_sco_disconnect_ind_hdler(mmi_bt_get_active_signal_connection_id(MMI_BT_HFG_PROFILE_UUID));

    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
            /* Callback inquery function because the SCO disconnect is called by BT inquery */
            if(g_mmi_profiles_bt_inquery_callback)
            {
                inquery_callback = g_mmi_profiles_bt_inquery_callback;
                g_mmi_profiles_bt_inquery_callback = NULL;                
                inquery_callback();
            }
    #endif

            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_is_connected
 * DESCRIPTION
 *  to check if bt is connected
 * PARAMETERS
 *  connect_type        [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_is_connected(U8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL bt_connect = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_ACL:
            bt_connect = (BOOL) mmi_bt_is_hs_connected();
            break;
        case MMI_PROFILES_BT_HFP_SCO:
            bt_connect = mdi_audio_bt_is_stream_open(BT_HFP);
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }

    PRINT_INFORMATION("mmi_profiles_bt_is_connected: connect_type =%d, bt_connect = %d\n", connect_type, bt_connect);

    return bt_connect;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_is_sco_connect_allowed
 * DESCRIPTION
 *  check if bt sco connect request is allowed
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if allowed
 *****************************************************************************/
BOOL mmi_profiles_bt_is_sco_connect_allowed(void)
{
    /* Can not connect SCO while FM is recording */
#ifdef __MMI_BT_FM_VIA_SCO__
    if((mdi_audio_get_audio_mode() == MDI_AUDIO_RECORD_FM_RADIO) &&
       (mdi_audio_get_state()== MDI_AUDIO_RECORD))
    {
        return FALSE;
    }
#endif

    return (g_mmi_profiles_bt_allow_sco && !g_mmi_profiles_bt_inquerying);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_connect_req
 * DESCRIPTION
 *  bt connect request
 * PARAMETERS
 *  connect_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_connect_req(U8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 connect_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_connect_req: connect_type =[%d], Allow SCO=[%d], BT Inquery=[%d]\n", 
                        connect_type, g_mmi_profiles_bt_allow_sco, g_mmi_profiles_bt_inquerying);

    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_SCO:
            if(mmi_profiles_bt_is_sco_connect_allowed())
            {
                connect_id = mmi_bt_get_active_signal_connection_id(MMI_BT_HFG_PROFILE_UUID);
                ASSERT(connect_id >= 0);
                mdi_audio_bt_open_stream(BT_HFP, (U16) connect_id);
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disconnect_req
 * DESCRIPTION
 *  bt disconnect request
 * PARAMETERS
 *  connect_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_disconnect_req(U8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_disconnect_req: connect_type =%d\n", connect_type);

    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_SCO:
            mdi_audio_bt_close_stream(BT_HFP);
            mmi_profiles_bt_connect_sco_app_callback = NULL;
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_call_start_callback
 * DESCRIPTION
 *  the call back function for call start
 * PARAMETERS
 *  void
 *  BOOL(?)     [IN]        Turn on
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_call_start_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL speech_on = mdi_audio_is_speech_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_call_start_callback: in_call=%d,speech_on=%d\n", g_mmi_profiles_bt_in_call,
                       speech_on);

    if (!g_mmi_profiles_bt_in_call)
    {
        if (gactivatedprofile == MMI_PROFILE_BT)
        {
        #ifdef __MMI_HFP_SUPPORT__
            if (mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_ACL))
            {
                if (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf())
                {
                    mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
                #ifdef __MMI_BT_AUDIO_VIA_SCO__
                    /* Stop SCO timeout timer during call */
                    StopTimer(BT_SCO_CONNECT_TIMER);
                #endif /* #ifdef __MMI_BT_AUDIO_VIA_SCO__ */
                }
            }
        #endif /* __MMI_HFP_SUPPORT__ */  
        }
        g_mmi_profiles_bt_in_call = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_call_end_callback
 * DESCRIPTION
 *  the call back function for call end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_call_end_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL speech_on = mdi_audio_is_speech_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_call_end_callback: in_call=%d, speech_on=%d\n", g_mmi_profiles_bt_in_call,
                       speech_on);

    if (g_mmi_profiles_bt_in_call)
    {
        if (gactivatedprofile == MMI_PROFILE_BT)
        {
        #ifdef __MMI_HFP_SUPPORT__
            if (mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_ACL))
            {
                #ifdef __MMI_BT_AUDIO_VIA_SCO__
                    if(mmi_bt_is_aud2hf())
                    {
                        /* Disconnect later if support audio via BT SCO */
                        if(g_mmi_profiles_bt_sco_timeout)
                        {
                            StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
                        }
                    }
                    else
                    {
                        mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);                    
                    }
                #else
                    mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
                #endif
            }
        #endif /* __MMI_HFP_SUPPORT__ */ 
        }
        g_mmi_profiles_bt_in_call = FALSE;
    #ifdef __MMI_HFP_SUPPORT__
        g_mmi_profiles_bt_always_use_in_call = FALSE;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_connect_callback
 * DESCRIPTION
 *  the call back function for bt connect indication
 * PARAMETERS
 *  connect_type        [IN]        
 *  callback_type       [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_connect_callback(U8 connect_type, U8 callback_type, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_connect_callback: connect_type =%d, callback_type = %d, result = %d\n",
                       connect_type, callback_type, result);

    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_ACL:
            if (callback_type == MMI_PROFILES_BT_IND || callback_type == MMI_PROFILES_BT_RSP)
            {
                if (result == MMI_PROFILES_BT_OK)
                {
                    if (gactivatedprofile != MMI_PROFILE_BT)
                    {
                        mmi_profiles_bt_activate_profile();
                    }
                    
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                    /* Connect SCO according to HFP audio path setting */
                    if (mmi_bt_is_aud2hf())
            #else /*__MMI_BT_AUDIO_VIA_SCO__*/
                #ifdef __MMI_BT_FM_VIA_SCO__
                    /* Need to check FM radio if FM via SCO on  */
                    if ((g_mmi_profiles_bt_in_call || mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO)) &&
                        (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
                #else
                    if (g_mmi_profiles_bt_in_call && (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
                #endif
            #endif /*__MMI_BT_AUDIO_VIA_SCO__*/
                    {
                        mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
                    }
                }
            }
            break;
        case MMI_PROFILES_BT_HFP_SCO:
            if (callback_type == MMI_PROFILES_BT_IND || callback_type == MMI_PROFILES_BT_RSP)
            {
                if (result == MMI_PROFILES_BT_OK)
                {
                    /* add a condition check for SCO, if it's not allowed, then disconnect it */
            #if !defined(__MMI_BT_AUDIO_VIA_SCO__)
                #ifdef __MMI_BT_FM_VIA_SCO__
                    if( !g_mmi_profiles_bt_app_in_use && !g_mmi_profiles_bt_in_call && !mmi_bt_is_doing_far_end_loopback_test()
                        && !mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO) )
                #else
                    if( !g_mmi_profiles_bt_app_in_use && !g_mmi_profiles_bt_in_call && !mmi_bt_is_doing_far_end_loopback_test())
                #endif            
                    {
                        mmi_profiles_bt_disconnect_req( MMI_PROFILES_BT_HFP_SCO );
                        return;
                    }
            #endif /* #if !defined(__MMI_BT_AUDIO_VIA_SCO__) */
                
                    if (gactivatedprofile != MMI_PROFILE_BT)
                    {
                        mmi_profiles_bt_activate_profile();
                    }
                    if (g_mmi_profiles_bt_in_call)
                    {
                        g_mmi_profiles_bt_always_use_in_call = TRUE;
                    }
                }
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disconnect_callback
 * DESCRIPTION
 *  the call back function for bt disconnect indication
 * PARAMETERS
 *  connect_type        [IN]        
 *  callback_type       [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_disconnect_callback(U8 connect_type, U8 callback_type, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_disconnect_callback: connect_type =%d, callback_type = %d, result = %d\n",
                       connect_type, callback_type, result);

    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_ACL:
            if (callback_type == MMI_PROFILES_BT_IND || callback_type == MMI_PROFILES_BT_RSP)
            {
                mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
                if (gactivatedprofile == MMI_PROFILE_BT)
                {
                    if (mmi_gpio_is_earphone_plug_in())
                    {
                        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
                    #if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
                    #endif
                        mmi_profiles_headset_activate_profile();
                    }
                    else
                    {
                        mmi_profiles_bt_deactivate_profile();
                    }
                }
            }
            /* Change audio path back to phone before disconnect HFP ACL link */
            else if (callback_type == MMI_PROFILES_BT_REQ)
            {
                mdi_audio_bt_hfp_turn_off();
            }
            break;
        case MMI_PROFILES_BT_HFP_SCO:
            if (callback_type == MMI_PROFILES_BT_IND || callback_type == MMI_PROFILES_BT_RSP)
            {
                if (g_mmi_profiles_bt_reset_pending != 0)
                {
                    g_mmi_profiles_bt_reset_pending &= 0x0E;
                    if (g_mmi_profiles_bt_reset_pending == 0)
                    {
                        mmi_bt_panic_ind_post_process();
                    }
                }
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_activate_profile
 * DESCRIPTION
 *  activate BT profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_activate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_activate_profile: gactivatedprofile =%d, glastactivatedprofile = %d\n",
                       gactivatedprofile, glastactivatedprofile);

	gprofileheadset = 0;
    if (gactivatedprofile != MMI_PROFILE_SILENT && gactivatedprofile != MMI_PROFILE_HEADSET &&
        gactivatedprofile != MMI_PROFILE_BT)
    {
        glastactivatedprofile = gactivatedprofile;
    }
    gactivatedprofile = MMI_PROFILE_BT;
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
    WriteValue(NVRAM_PROFILES_LASTACTIVATED, &glastactivatedprofile, DS_BYTE, &error);
    mmi_profiles_show_alert_status_icon();
    change_font();

    mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());
    SetKeyPadVolume(GetKeypadVolumeLevel());
    mdi_audio_set_mic_volume();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_deactivate_profile
 * DESCRIPTION
 *  deactivate BT profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_deactivate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_deactivate_profile: gactivatedprofile =%d, glastactivatedprofile = %d\n",
                       gactivatedprofile, glastactivatedprofile);

    ReadValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(PROFILE));
    mmi_profiles_show_alert_status_icon();
    change_font();

    mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());
    SetKeyPadVolume(GetKeypadVolumeLevel());
    mdi_audio_set_mic_volume();
}


#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disable_sco_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_disable_sco_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_disable_sco_timeout\n");
    
    StopTimer(BT_SCO_CONNECT_TIMER);
    g_mmi_profiles_bt_sco_timeout = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_enable_sco_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_enable_sco_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_enable_sco_timeout\n");

    g_mmi_profiles_bt_sco_timeout = MMI_TRUE;

    if(mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
    {
        StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_enable_sco_connect_delay_timer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_enable_sco_connect_delay_timer_callback(void)
{
    /* Press key or play audio in call will not connect SCO,
    *   call setup may leave the voice in phone */
    if(!g_mmi_profiles_bt_in_call && mmi_bt_is_aud2hf())
    {
        mmi_profiles_bt_connect_sco(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disable_sco_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_disable_sco_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_disable_sco_connection\n");
    
    StopTimer(BT_SCO_CONNECT_TIMER);
    StopTimer(BT_SCO_ENABLE_CONNECT_DELAY_TIMER);
    g_mmi_profiles_bt_allow_sco = MMI_FALSE;

    mmi_profiles_bt_disconnect_sco();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_enable_sco_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_enable_sco_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_enable_sco_connection\n");

    g_mmi_profiles_bt_allow_sco = MMI_TRUE;
    StartTimer(BT_SCO_ENABLE_CONNECT_DELAY_TIMER, 1000, mmi_profiles_bt_enable_sco_connect_delay_timer_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_sco_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_sco_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_sco_timeout: SCO connected =%d, bt_in_call=%d\n", mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO), g_mmi_profiles_bt_in_call);
    
    if(mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
    {
        /* If audio/video is not playing or not in call */
        if(!g_mmi_profiles_bt_in_call
            && mdi_audio_is_idle()
        #if defined(__MMI_VIDEO_PLAYER__)
            && !mdi_video_is_playing()
        #endif
        #if defined(__MMI_VIDEO_RECORDER__)
            && !mdi_video_is_recording()
        #endif
		#if defined(BGSND_ENABLE) 
            && !mdi_audio_snd_is_playing()
        #endif
            && mdi_audio_mma_is_idle() 
            )
        {
            mmi_profiles_bt_disconnect_sco();
        }
        /* still using audio resource, disconnect later */
        else if(g_mmi_profiles_bt_sco_timeout && !g_mmi_profiles_bt_in_call)
        {
            StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
        }
    }
}
                
/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_inquery_start_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_profiles_bt_inquery_start_callback(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sco_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sco_status = mdi_audio_bt_get_stream_status(BT_HFP);
    g_mmi_profiles_bt_inquery_callback = NULL;
    g_mmi_profiles_bt_inquerying = MMI_TRUE;
    
    PRINT_INFORMATION("mmi_profiles_bt_inquery_start_callback: SCO status = [%d]", sco_status);

    switch(sco_status)
    {
        case MDI_AUDIO_BT_STATE_IDLE:
            return MMI_FALSE;
            break;
            
        case MDI_AUDIO_BT_STATE_WAIT_CLOSE:
            g_mmi_profiles_bt_inquery_callback = callback;
            break;
            
        case MDI_AUDIO_BT_STATE_OPEN:
        case MDI_AUDIO_BT_STATE_WAIT_OPEN:
            StopTimer(BT_SCO_CONNECT_TIMER);
            g_mmi_profiles_bt_inquery_callback = callback;    
            mdi_audio_suspend_background_play();
            mmi_profiles_bt_disconnect_sco();
            break;

        default:
            ASSERT(0);
            break;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_inquery_stop_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_inquery_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_inquery_stop_callback");

    g_mmi_profiles_bt_inquery_callback = NULL;

    /* Connect SCO after background play resume */
    g_mmi_profiles_bt_inquerying = MMI_FALSE;
    
    mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_connect_audio_via_sco
 * DESCRIPTION
 *  connect sco link
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *****************************************************************************/
void mmi_profiles_bt_connect_audio_via_sco(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_profiles_bt_connect_audio_via_sco: profiles_bt_in_call=[%d]\n", g_mmi_profiles_bt_in_call);

    /* Press key or play audio in call will not connect SCO,
    *   call setup may leave the voice in phone */
    if(!g_mmi_profiles_bt_in_call && mmi_bt_is_aud2hf())
    {
        mmi_profiles_bt_connect_sco(NULL);
    }
}

#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */

#endif /* __MMI_BT_PROFILE__ */ 

