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
 * TimerEvents.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI timer resource.
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

   FILENAME : TimerEvents.h

   PURPOSE     : struct, defines & globle variables

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : sep' 03, 2002

**************************************************************/

#ifndef _PIXCOM_TIMER_EVENT_H
#define _PIXCOM_TIMER_EVENT_H

typedef enum
{
    /*
     * Start for for Keypad based timer.
     */
    KEY_TIMER_ID_NONE = 0,
    KEY_TIMER_ID0 = 1,
    KEY_TIMER_ID1,
    KEY_TIMER_ID2,
    KEY_TIMER_ID3,
    KEY_TIMER_ID4,
    KEY_TIMER_ID5,
    KEY_TIMER_ID6,
    KEY_TIMER_ID7,
    KEY_TIMER_ID8,
    KEY_TIMER_ID9,
    KEY_TIMER_ID10,
    KEY_TIMER_ID11,
    KEY_TIMER_ID12,
    KEY_TIMER_ID13,
    KEY_TIMER_ID14,
    KEY_TIMER_ID15,
    KEY_TIMER_ID16,
    KEY_TIMER_ID17,
    KEY_TIMER_ID18,
    KEY_TIMER_ID19,
    KEY_TIMER_ID20,
    KEY_TIMER_ID21,
    KEY_TIMER_ID22,
    KEY_TIMER_ID23,
    KEY_TIMER_ID24,
    KEY_TIMER_ID25,
    KEY_TIMER_ID26,
    KEY_TIMER_ID27,
    KEY_TIMER_ID28,
    KEY_TIMER_ID29,
    KEY_TIMER_ID30,
    KEY_TIMER_ID31,
    KEY_TIMER_ID32,
    KEY_TIMER_ID33,

    /*
     * Start for for UI based timer.
     */
    UI_TIMER_ID_BASE,
    UI_TIMER_ID_MAX = (UI_TIMER_ID_BASE + 10),

    /*
     * Start for MMI APP based timer
     */
    MMI_TIMER_BASE = UI_TIMER_ID_MAX + 1,

    /*
     * For GUI
     */
    UI_ELEMENTS_TIMER,

    /*
     * For Sim detection timers
     */
    SAT_MESSAGE_WAIT_TIMER,
    SAT_TERMINAL_RESP_TIMER,
    /* micha1108 */
    SAT_PLAY_TONE_TIMER,
    SAT_SEND_DTMF_TIMER,
    SAT_HELP_TIMER,
    /* micha0201 */
    SAT_REFRESH_REBOOT_TIMER,
    KEYPADUNLOCKEDMESSAGE_TIMER,

    /*
     * Timer for showing "press to unlock" after pressing
     */
    KEYPADUNLOCKEDHELPMESSAGE_TIMER,

    /*
     * For Call Management 
     */
    CM_REDIAL_TIMER,
    CM_ALERT_NOTIFYDURATION_TIMER,
    CM_AUTOANSWER_NOTIFYDURATION_TIMER,
    CM_AUTO_DTMF_CONFIRM_TIMER,
    CM_CCBS_NOTIFYDURATION_TIMER,
    CM_GET_TIME_CALLBACK,
    CM_NOTIFYDURATION_TIMER,
    CM_CTR_TIMER,
    CM_AUTO_QUICK_END_TIMER,

	/*
     * For SS
     */ 
    USSR_SESSION_TIMER,
    USSD_UCM_DISPLAY_TIMER,
    SS_NOTIFY_TIMER,

    /*
     * For Boot Up and system
     */
    SYSTEM_SHUTDOWN,
    TIMER_REAL_TIME_CLOCK,
    APHORISM_SCR_TIMER,
    WELCOME_SCR_TIMER,
    KEYPAD_LOCK_TIMER,
    LOW_BATTERY_SCR_TIMER,
    BOOTUP_CHARGER_DETECT_TIMER,
    SEARCHING_SCREEN_TIMER, /* Robin 1107 */
    RAC_ACTIVATION_TIMER, /* Gemini: timer of RAC activation */
    DUAL_SIM_ON_TIMER, /* Gemini: timer of power on the second SIM in case 12 */

    /*
     * for PHB 
     */
    PHB_NOTIFYDURATION_TIMER,
    PHB_READ_OPT_FILED_TIMER,
    PHB_READ_SPEED_DIAL_TIMER,
    PHB_QUICK_SEARCH_TIMER,
    PHB_LIST_SPEAK_NAME_TIMER,
    PHB_NAME_SORT_TIMER,  // only for __MMI_PHB_BOOT_UP_RECURSIVE_SORTING__

    /*
     * for SMS
     */
    MESSAGES_SMS_BOOTUP_TIMER_ID,
    MESSAGES_SMS_BOOTUP_NO_LIST_RSP_TIMER_ID,
    MESSAGES_CB_BOOTUP_TIMER_ID,
    MESSAGES_SUBLCD_TIMER_ID,
    MESSAGES_INPROGRESS_TIMER_ID,
    MESSAGES_LMS_RECV_TIMER_ID,
    MESSAGES_EMS_OBJECT_PLAY_TIMER_ID,
    MESSAGES_CONTINUE_SEND_SMS_PROCESS_TIMER_ID,

	MMI_MSG_FAILED_POPUP_TIMER_ID,

    /*
     * for Help Application Timer
     */
    HELP_APPLICATION_TIMER,

    /*
     * for Ring Tone Compser Timer
     */
    TIMER_COMPOSE_RINGTONE,

    /*
     * for Alarm timer
     */
    ALARM_TIMER_WAIT_FOR_CALL,
    ALARM_TIMER_WAIT_FOR_RESPONSE,
    ALARM_SIMULATE_ON_WIN32,
    ALARM_ALERT_NOTIFYDURATION_TIMER,

    /*
     * for Idle and Misc 
     */
    KEY_VOL_TIMER_ID,
    TOGGLE_TIMER,
    SP_FAIL_TIMER,
    EARPHONE_SCR_TIMER,
    BACKLIGHT_TIMER,
    IDLE_SHOW_BADFILE_WARNING_TIMER,
    IDLE_SHOW_SUB_BADFILE_WARNING_TIMER,
    IDLE_APP_AUTO_LOCK_TIMER_ID,
    EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER,
    SML_AUTOLOCK_IDLE_NOTIFY_TIMER,

    /*
     * for SIM 
     */
    CODE_VERIFIED_TIMER,

    /*
     * for Organize,  Fun and Game
     */
    PLAY_DOWNLOAD_AUDIO,
    SCREENSAVER_TIMER,
    AT_TEST_TIMER,
    TIMER_POPUP_HEALTH_MENSIS,

    /*
     * for input method
     */
    T9_REQ_TIMER,
    T9_FRAME_TIMER,
    BLINKING_CURSOR,
    ZI_REQ_TIMER,
    ZI_FRAME_TIMER,
    NOTE_MULTITAP_TIMER,
    CSTAR_REQ_TIMER,
    CSTAR_FRAME_TIMER,

    /*
     * for Engineering mode
     */
    EM_NOTIFYDURATION_TIMER,
    EM_RINGTONE_HIGHLIGHT_TIMER,
    EM_GPRS_PING_TIMER,
    EM_GPRS_SOC_DEMO_APP_TIMER,
    EM_NW_EVENT_PLAY_TONE_TIMER,
    FM_LCD_COLOR_CHANGE_TIMER,
    FM_AUTO_TEST_COMMNON_TIMER,
    FM_RTC_START_TIMER,
    FM_VIB_TIMER,
    FM_GENERAL_TIMER,

    /*
     * for Profiles and Settings
     */
    TIMER_PROFILES_TONE_PLAY,
    TIMER_PROFILES_ALERT_PLAY,
    TIMER_KEYPAD_BACKLIGHT,
    /* micha1109 */
    TIMER_SET_GPRS_MODE,
    AT_PUK_IN_CALL_TIMER,
    FLIGHT_MODE_CAMP_ON_TONE_TIMER,
    FLIGHT_MODE_DEACTIVATE_BT_TIMER,

    /*
     * for Common Screen
     */
    POPUP_TIMER,
    BOOTUP_POPUP_TIMER,
    POPUP_SUBLCD,

    /*
     * for USB
     */
    USB_SHUTDOWN_SCR_TIMER,
    PENDING_USBDETECTION_HDLR_TIMER,

    /*
     * for file management
     */
    FMGR_AUDIO_TIMER,
    FMGR_SCR_TIMER,
    FMGR_PROG_UPDATE_TIMER,
    FMGR_DELAY_DECODE_0,
    FMGR_DELAY_DECODE_1,
    FMGR_DELAY_DECODE_2,
    FMGR_DELAY_DECODE_3,
    FMGR_DELAY_DECODE_4,
    FMGR_DELAY_DECODE_5,
    FMGR_DELAY_DECODE_6,
    FMGR_DELAY_DECODE_7,
    FMGR_DELAY_DECODE_8,
    FMGR_DELAY_DECODE_9,
    FMGR_DELAY_DECODE_10,
    FMGR_DELAY_DECODE_11,
    FMGR_DELAY_DECODE_12,
    FMGR_DELAY_DECODE_13,
    FMGR_DELAY_DECODE_14,
    FMGR_DELAY_DECODE_15,
    FMGR_DM_FWU_SHUTDOWN_TIMER,


    /*
     * for Bluetooth
     */
    BT_INQ_TIMER,
    BT_RING_TIMER,
    BT_AUD_OFF_TIMER,
    BT_DEV_DISC_TIMER,
    BT_DISCOVER_PERIOD_TIMER,
    BT_CMD_GUARD_TIMER,
    BT_MAKE_IDLE_STATE_TIMER,
    BT_WAIT_POWER_OFF_TIMER,
    BT_WAIT_POWER_ON_TIMER,
    BT_POPUP_TIMER,
    BT_PASSCODE_INPUT_PROMPTED_TIMER,
    BT_DISCONNECT_2ND_INCOMING_HFG_TIMER,
    BT_DEACTIVATE_PROHIBITED_PROFILES_TIMER,
    BT_ACTIVATE_PROFILE_TIMER,
    BT_WAIT_HW_READY_TIMER,
    BT_LP2_TESTING_TIMER,
    BT_LP2_DELAY_TIMER,
    BT_DELAY_DEACTIVATE_OBEX_RELATED_PROFILES_TIMER,
    BT_DELAY_AVRCP_CONN_POPUP_TIMER,
    BT_DELAY_AVRCP_DISC_POPUP_TIMER,
    BT_POWER_OFF_GUARD_TIMER,
    BT_DELAY_SCO_CONN_POPUP_TIMER,
    BT_RELEASE_ALL_CON_GUARD_TIMER,
    BT_DUMMY_SCR_TIMER,

    /*
     * for BT OPP request timeout
     */
    BT_OPP_REQ_TIMER,
    BT_OPP_ACCEPT_CONNECT_TIMER,
    BT_OPP_ABORT_REQ_TIMER,
    /*
     * for BT FTP request timeout
     */
    BT_FTP_REQ_TIMER,
    BT_FTP_ACCEPT_CONNECT_TIMER,
    BT_FTPS_PULL_IND_TIMER,
    BT_FTPC_BROWSE_FILES_FAILED_TIMER,

    /*
     * for BT BPP printing timeout
     */
    BT_BPP_PRINTING_TIMER,
    
    /*
     * for BT BIP request timeout
     */
    BT_BIP_REQ_TIMER,
    BT_BIP_BLINKING_TIMER,
    
    /*
     * for audio player
     */
    AUDPLY_PROCESS_ADD_FILE_TIMER,
    AUDPLY_COUNT_PLAY_TIMER,
    AUDPLY_DELAY_PLAY_TIMER,
    AUDPLY_SINGLE_PLAY_TIMER,
    AUDPLY_SEEKING_TIMER,

    /*
     * for AB repeater
     */
    ABREPEAT_PROGRESS_BAR_DRAW_TIMER,
    ABREPEAT_BUILD_CACHE_DELAY_TIMER,
    ABREPEAT_DUMMY_FILE_PROG_TIMER,

    /*
     * for mdi_audio_play_text
     */
    MDI_AUDIO_PLAYER_TEXT_TIMER,

    /*
     * for fm radio
     */
    FMRDO_TWINKLE_FREQUENCY_TIMER,
    FMRDO_REPEAT_STEP_TIMER,

    /*
     * for sound recorder SMS record
     */
    SND_SMS_RECORD_STOP_TIMER,
    
    /*
     * for MMIAPI
     */
    MMIAPI_SMS_TIMER,

    /*
     * for GPIO
     */
    GPIO_KEYPAD_LIGHT_TIMER,

    /*
     * for WAP
     */
    WAP_NOT_READY_TIMER,
    WAP_GOTO_IDLE_TIMER,
    WAP_EDITOR_MESSAGEBOX_TIMER,

    /*
     * for J2ME
     */
    J2ME_TIMEALARM_TIMER,
    J2ME_NOT_READY_TIMER,
    J2ME_VM_TERMINATING_TIMER,

    /*
     * for DownloadAgent
     */
    MMI_DA_TIMER_1,
    MMI_DA_TIMER_2,
    MMI_DA_TIMER_3,

    MMI_DA_WPS_TIMER_1,
    MMI_DA_WPS_TIMER_END = MMI_DA_WPS_TIMER_1 + 5,
    
    /*
     * for VRSD
     */
    VRSD_DIAL_AUTO_DIAL_TIMER,
    VRSD_DIAL_PLAYBACK_TIMER,
    VRSD_PLAYTONE_TIMER,

    /*
     * for touch screen
     */
    PEN_POLLING_TIMER,

    /*
     * for GDI,( allocate 128 timer id )
     */
    GDI_TIMER_BASE,
    GDI_TIMER_END = GDI_TIMER_BASE + 128,

    /*
     * for SVG
     */
    SVG_TIMER_BASE,

    /* micha_PoC */
    /*
     * for PoC
     */
    POC_IND_TIMER,

    /*
     * for Shcedule FM Recording
     */
    FMSR_CHCEK_STOP_TIMER,

    /*
     * for calling background sound
     */
    BGSND_HIGHLIGHT_TIMER,
    BGSND_INTERVAL_TIMER,

    /*
     * for Jataayu WAP and MMS
     */
    JDD_TIMER_00,
    JDD_TIMER_01,
    JDD_TIMER_02,
    JDD_TIMER_03,
    JDD_TIMER_04,
    JBROWSER_WAP_NOT_READY_TIMER,
    JMMS_WAP_NOT_READY_TIMER,
    JMMS_NO_COMM_TIMER_CHECK,
    JMMS_VIEW_PREVIEW_TIMER,
	JMMS_ASYNC_PARSE_TIMER,
	JMMS_ASYNC_SEND_TIMER,
	JMMS_ASYNC_SAVE_TIMER,
    JMMS_SEND_TIMEOUT_TIMER,

	/* For Generic Browser */
	BRW_SPLASH_SCREEN_TIMER,
	/* For Generic Browser */
    /*
     * for Unified Message
     */
    UM_INPROGRESS_TIMER_ID,
    EBOOK_RECURSIVE_TIMER,
   	UMMS_SEND_TIMER,
	UMMS_DOWNLOAD_TIMER,
	UMMS_INPROGRESS_TIMER_ID,
    MMS_VIEWER_TIMER,
    MMI_MMS_BGSR_TIMER,    /*Add for BGSR*/
    /*
     * AV BT app
     */ 
    AV_BT_DISC_TIMER,
    AV_BT_START_TIMER,
    BT_AVRCP_AUTO_RELEASE_TIMER,
    BT_AVRCP_TEST_TIMER,

    /*
     * for SyncML
     */
    SYNCML_POWER_ON_SYNC_TIMER,

    /*
     * for VoIP
     */
    VOIP_AUTOLOGIN_TIMER,
    VOIP_AUTOANSWER_TIMER,
    VOIP_AUTOREDIAL_TIMER,
    VOIP_DTMF_TIMER,
    VOIP_POPUP_TIMER,

    /*
     * for UCM
     */
    UCM_NOTIFY_DURATION_TIMER,
    UCM_CONFIRM_TIMER_ID,
    UCM_AUTO_REDIAL_TIMER,
    UCM_AUTO_ANSWER_TIMER,

    /*
     * for VT
     */
    VT_START_CAMERA_QUERY_TIMER,

    /*
     * for Unified Composer
     */
    UC_INPROGRESS_TIMER_ID,
    UC_MSG_TYPE_CHECK_TIMER_ID,

    /*
     * for Audio via SCO
     */
    BT_SCO_CONNECT_TIMER,
    BT_SCO_ENABLE_CONNECT_DELAY_TIMER,
    /*
    * for Ebook
    */
    EBR_SEARCH_BLOCK_TIMER,
    CMS_WAPMMS_TIMER_BASE,
    CMS_WAPMMS_TIMER_END=CMS_WAPMMS_TIMER_BASE+10,

    /*
     * Avatar
     */
    AVATAR_DELAY_DECODE_0,
    AVATAR_DELAY_DECODE_1,
    AVATAR_DELAY_DECODE_2,
    AVATAR_DELAY_DECODE_3,
    AVATAR_DELAY_DECODE_4,


    AVATAR_DELAY_DECODE_5,
    AVATAR_DELAY_DECODE_6,
    AVATAR_DELAY_DECODE_7,
    AVATAR_DELAY_DECODE_8,
    AVATAR_DELAY_DECODE_9,

    /* for Q05A Browser */
	BRW_PSH_INIT_TIMER,

    /*
     * for owl sound integration
     */
    OWL_SND_VIB_TIMER,

    /*
     * for Category screen browser
     */
    CSB_AUTO_MODE_TIMER_ID,
    /*
    * for dictionary
    */
    DICTIONARY_TTS_TIMER,

	/*
	 *for DM Self-Register
	 */
	DM_SR_REPEAT_TIMER_ID,

    /*
     * for Language Learning
     */
     LANGLN_UPDATE_TIMER_ID,
     LANGLN_DK_PLAY_DELAY_TIME,
     LANGLN_SK_PLAY_DELAY_TIME,
     LANGLN_LK_PLAYING_TIMER,
     LANGLN_LK_INTERVAL_TIMER,
     LANGLN_WK_ALERT_TOP_TIMER_ID,
	 
    /*
     * EM benchmark
     */
     BENCHMARK_TIMER_ID,

	 /*Certificate Manger */
	 MMI_CERTMAN_TIMER_ID,

 /*
* for dual mode support
* MERCURY MASTER USE
*/
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_RELEASE_SLAVE_PWRKEY_TIMER,
    MTPNP_RESET_SLAVE_TIMER,
    MTPNP_MODESWITCH_TIMER,
    MTPNP_AUTOANSWER_NOTIFYDURATION_TIMER,
    MTPNP_NOTIFYDURATION_TIMER,
    MTPNP_NOTIFY_INCOMING_CONFLICT,
    MTPNP_ALERT_NOTIFYDURATION_TIMER,
    MTPNP_DYNAMIC_FM_RETRY_TIMER,
    MTPNP_SWITCHMODE_DEACTIVATE_BT_TIMER,
#endif	/* __MMI_DUAL_SIM_MASTER__ */

/* 2009.04.25 hongzhe.liu move it to here + */
   POLL_TIMER,
/* 2009.04.25 hongzhe.liu move it to here - */

#if ( defined(G_SENSOR_SUPPORT) || defined(HORSERACE_SUPPORT) || defined(M_SENSOR_SUPPORT))
   
#if defined(G_SENSOR_SUPPORT)   
   POLL_G_SENSOR_TIMER,
#endif

#if defined(HORSERACE_SUPPORT)
   POLL_HORSERACE_TIMER,
#endif
#endif

#if defined (__VIBRATOR_TONE_SUPPORT__)   //huyi-2008/01/11
	AUDIO_VIBRATOT_TIMER,	
#endif


    MAX_TIMERS  /* Imp: Please do not modify this */
} MMI_TIMER_IDS;

#endif /* _PIXCOM_TIMER_EVENT_H */ 

