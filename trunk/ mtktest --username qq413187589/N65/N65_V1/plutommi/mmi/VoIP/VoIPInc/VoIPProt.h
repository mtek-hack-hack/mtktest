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
 *  VoIPProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines imported prototypes.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VOIP_PROT_H
#define VOIP_PROT_H

#include "mmi2voip_enums.h"
#include "mmi2voip_struct.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#include "DataAccountGProt.h"   /* for MAX_DATA_ACCOUNT_NAME_LEN */

#define MMI_VOIP_MAX_PROFILE_NUM            10
// #define MMI_VOIP_MAX_PROFILE_NAME_LEN    33  /* 32 unicode + 1 null terminator */
#define MMI_VOIP_MAX_PORT_LEN               6   /* 5 digits + 1 null terminator */
// #define MMI_VOIP_MAX_IP_SEG              4
#define MMI_VOIP_MAX_CODEC_NUM              8
#define MMI_VOIP_MAX_CODEC_NAME_LEN         9   /* 8 ascii + 1 null terminator */

#define MMI_VOIP_MAX_ACTIVE_CALL            1
#define MMI_VOIP_MAX_HELD_CALL              3
#define MMI_VOIP_MAX_NUM_CALL               (MMI_VOIP_MAX_ACTIVE_CALL + MMI_VOIP_MAX_HELD_CALL)

#define MMI_VOIP_MAX_NUM_DIGITS             12  /* available DTMF keys */
#define MMI_VOIP_DTMF_LEN                   41
#define MMI_VOIP_MAX_STRING_LEN             129 /* 128 unicode + 1 null terminator */

#define MMI_VOIP_GENERAL_TIMEOUT            2000

#ifdef __MMI_VOIP_OTAP_DMP__
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
#endif /* __MMI_VOIP_OTAP_DMP__ */

typedef enum
{
    MMI_VOIP_PROF_COMMON_PROFNAME_CAP,
    MMI_VOIP_PROF_COMMON_PROFNAME,
    MMI_VOIP_PROF_COMMON_DATAACCT_CAP,
    MMI_VOIP_PROF_COMMON_DATAACCT,
    MMI_VOIP_PROF_COMMON_AUTOLOGIN_CAP,
    MMI_VOIP_PROF_COMMON_AUTOLOGIN,
    MMI_VOIP_PROF_COMMON_VMSERVER_CAP,
    MMI_VOIP_PROF_COMMON_VMSERVER,
    MMI_VOIP_PROF_COMMON_INLINE_TOTAL
} mmi_voip_prof_common_inline_enum;

typedef enum
{
    MMI_VOIP_PROF_ACCT_SIPSERVER_CAP,
    MMI_VOIP_PROF_ACCT_SIPSERVER,
    MMI_VOIP_PROF_ACCT_SIPPORT_CAP,
    MMI_VOIP_PROF_ACCT_SIPPORT,
    MMI_VOIP_PROF_ACCT_DISPNAME_CAP,
    MMI_VOIP_PROF_ACCT_DISPNAME,
    MMI_VOIP_PROF_ACCT_USERNAME_CAP,
    MMI_VOIP_PROF_ACCT_USERNAME,
    MMI_VOIP_PROF_ACCT_PASSWORD_CAP,
    MMI_VOIP_PROF_ACCT_PASSWORD,
    MMI_VOIP_PROF_ACCT_AUTHNAME_CAP,
    MMI_VOIP_PROF_ACCT_AUTHNAME,
    MMI_VOIP_PROF_ACCT_INLINE_TOTAL
} mmi_voip_prof_acct_inline_enum;

typedef enum
{
    MMI_VOIP_PROF_OUTBOUND_STATUS_CAP,
    MMI_VOIP_PROF_OUTBOUND_STATUS,
    MMI_VOIP_PROF_OUTBOUND_SERVER_CAP,
    MMI_VOIP_PROF_OUTBOUND_SERVER,
    MMI_VOIP_PROF_OUTBOUND_PORT_CAP,
    MMI_VOIP_PROF_OUTBOUND_PORT,
    MMI_VOIP_PROF_OUTBOUND_USERNAME_CAP,
    MMI_VOIP_PROF_OUTBOUND_USERNAME,
    MMI_VOIP_PROF_OUTBOUND_PASSWORD_CAP,
    MMI_VOIP_PROF_OUTBOUND_PASSWORD,
    MMI_VOIP_PROF_OUTBOUND_INLINE_TOTAL
} mmi_voip_prof_outbound_inline_enum;

typedef enum
{
    MMI_VOIP_PROF_REGISTER_STATUS_CAP,
    MMI_VOIP_PROF_REGISTER_STATUS,
    MMI_VOIP_PROF_REGISTER_SERVER_CAP,
    MMI_VOIP_PROF_REGISTER_SERVER,
    MMI_VOIP_PROF_REGISTER_PORT_CAP,
    MMI_VOIP_PROF_REGISTER_PORT,
    MMI_VOIP_PROF_REGISTER_USERNAME_CAP,
    MMI_VOIP_PROF_REGISTER_USERNAME,
    MMI_VOIP_PROF_REGISTER_PASSWORD_CAP,
    MMI_VOIP_PROF_REGISTER_PASSWORD,
    MMI_VOIP_PROF_REGISTER_INLINE_TOTAL
} mmi_voip_prof_register_inline_enum;

typedef enum
{
    MMI_VOIP_PROF_NAT_STATUS_CAP,
    MMI_VOIP_PROF_NAT_STATUS,
    MMI_VOIP_PROF_NAT_FIREWALL_CAP,
    MMI_VOIP_PROF_NAT_FIREWALL,
    MMI_VOIP_PROF_NAT_STUNSERVER_CAP,
    MMI_VOIP_PROF_NAT_STUNSERVER,
    MMI_VOIP_PROF_NAT_STUNPORT_CAP,
    MMI_VOIP_PROF_NAT_STUNPORT,
    MMI_VOIP_PROF_NAT_INTERVAL_CAP,
    MMI_VOIP_PROF_NAT_INTERVAL,
    MMI_VOIP_PROF_NAT_INLINE_TOTAL
} mmi_voip_prof_nat_inline_enum;

typedef enum
{
    MMI_VOIP_IDLE_STATE = 0,
    MMI_VOIP_OUTGOING_STATE,
    MMI_VOIP_INCOMING_STATE,
    MMI_VOIP_ACTIVE_STATE,
    MMI_VOIP_HOLD_STATE,
    MMI_VOIP_TRANSFER_STATE,
    MMI_VOIP_DISCONNECTING_STATE,
    MMI_VOIP_CALL_STATE_TOTAL
} mmi_voip_call_state_enum;

typedef enum
{
    MMI_VOIP_NONE = 0,
    MMI_VOIP_RING_TONE,
    MMI_VOIP_WAITING_TONE,
    MMI_VOIP_INCOMING_TONE_TOTAL
} mmi_voip_incoming_tone_enum;

typedef enum
{
    MMI_VOIP_NONE_ORIGIN = 0,
    MMI_VOIP_MO_ORIGIN,
    MMI_VOIP_MT_ORIGIN,
    MMI_VOIP_CALL_ORIGIN_TOTAL
} mmi_voip_call_origin_enum;

typedef enum
{
    MMI_VOIP_PHB = 0x01,
    MMI_VOIP_HISTORY = 0x02,
    MMI_VOIP_SOS = 0x04,
    MMI_VOIP_MO_ORIGIN_TOTAL
} mmi_voip_mo_origin_enum;

typedef struct
{
    S32 errorNo;
    U16 errorStr;
} mmi_voip_error_string_struct;

#if 0 /* define in nvram_user_defs.h */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* define in nvram_user_defs.h */

typedef struct
{
    S32 dataacctIndex;
    S32 selectionIndex;                                     /* auto login / outbound status / register status / nat status */
    S32 intervalIndex;
    U16 profileName[MMI_VOIP_MAX_PROFILE_NAME_LEN];
    U16 dataacctName[MAX_DATA_ACCOUNT_NAME_LEN + 1];
    U16 displayName[VOIP_DISP_NAME_LEN];
    U8 serverName[VOIP_URI_LEN * ENCODING_LENGTH];           /* voice mail / sip / outbound / register / stun */
    U8 portNumber[MMI_VOIP_MAX_PORT_LEN * ENCODING_LENGTH];  /* sip / outbound / register / stun */
    U8 username[VOIP_USERNAME_LEN * ENCODING_LENGTH];        /* sip / outbound / register */
    U8 password[VOIP_PASSWORD_LEN * ENCODING_LENGTH];        /* sip / outbound / register */
    U8 authName[VOIP_USERNAME_LEN * ENCODING_LENGTH];
    U8 ipAddr[MMI_VOIP_MAX_IP_SEG][MMI_VOIP_MAX_IP_SEG * ENCODING_LENGTH];
    U8 *twoList[2];
    U8 *threeList[3];
    U8 *fiveList[5];
} mmi_voip_prof_disp_struct;

typedef struct
{
    S32 actprofIndex;
    S32 currprofIndex;
    U16 currScr;
    mmi_voip_prof_struct saved_prof[MMI_VOIP_MAX_PROFILE_NUM];
    mmi_voip_prof_disp_struct disp_prof;
} mmi_voip_prof_setting_struct;

typedef struct
{
    U8 autoAnswer;
    U8 autoReject;
    U8 autoRedial;
    U8 hidecallerId;
    U8 dtmf;
    U8 srtp;
    U8 comfortNoise;
    U8 codecOrder[VOIP_MAX_NUM_CODEC][MMI_VOIP_MAX_CODEC_NAME_LEN];
} mmi_voip_setting_struct;

typedef struct
{
    S32 currScr;
    S32 currIndex;
    S32 currPriority;
    S32 numCodec;
    U8 dispCodec[VOIP_MAX_NUM_CODEC][MMI_VOIP_MAX_CODEC_NAME_LEN * ENCODING_LENGTH];
    voip_codec_enum codecEnum[VOIP_MAX_NUM_CODEC];  /* actual enum of codec order for VoIP CC */
    mmi_voip_setting_struct saved_setting;
} mmi_voip_call_setting_struct;

typedef struct
{
    U16 title_string;
    U16 body_string;
    U16 animation_image;
    U16 lsk_string;
    FuncPtr lsk_funcPtr;
    U16 rsk_string;
    FuncPtr rsk_funcPtr;
    FuncPtr send_funcPtr;
    FuncPtr end_funcPtr;
} mmi_voip_proc_scr_struct;

typedef struct
{
    U16 ringtoneId;
    U8 alertType;
} mmi_voip_call_alert_struct;

typedef struct
{
    S32 dialogId;
    S32 rtpHandle;
    U16 appName[VOIP_DISP_NAME_LEN];
    U16 dispName[VOIP_DISP_NAME_LEN];
    U8 remoteUri[VOIP_URI_LEN];
    MMI_BOOL isMixer;
    voip_sdp_struct sdp_info;
    mmi_voip_call_origin_enum callOrigin;
    MYTIME startTime;
    MYTIME endTime;
} mmi_voip_dialog_struct;

typedef struct
{
    S32 callId;
    S32 numDialog;
    mmi_voip_call_state_enum currState;
    mmi_voip_dialog_struct dialog_info[VOIP_MAX_NUM_DIALOG];
} mmi_voip_call_struct;

typedef struct
{
    S32 callId;
    U16 appName[VOIP_DISP_NAME_LEN];
    U16 dispName[VOIP_DISP_NAME_LEN];
    U8 remoteUri[VOIP_URI_LEN];
    voip_codec_enum codecList[VOIP_MAX_NUM_CODEC];  /* supported codec list */
} mmi_voip_held_call_struct;

typedef struct
{
    U32 maxnumCall;                     /* max number call that voip cc can allow */
    S32 numHeld;
    S32 numTotal;
    S32 processCId;                     /* current processing call id */
    S32 processDId;                     /* current processing dialog id */
    S32 bkrejCId;                       /* background reject call id */
    S32 bkrejDId;                       /* background reject dialog id */
    MMI_BOOL inSession;                     /* in voip critical session flag */
    mmi_voip_call_conn_enum needConn;   /* need to connect what type of call after release action */
    mmi_voip_call_struct call_info[MMI_VOIP_MAX_NUM_CALL];
    mmi_voip_held_call_struct held_call_info[MMI_VOIP_MAX_HELD_CALL];
} mmi_voip_call_list_struct;

typedef struct
{
    S32 maxAttempt;
    S32 currAttempt;
    U16 redialStr[MMI_VOIP_MAX_STRING_LEN];
    U16 redialName[VOIP_DISP_NAME_LEN];
    U8 redialUri[VOIP_URI_LEN];
} mmi_voip_call_redial_struct;

typedef struct
{
    U16 dtmfQueue[MMI_VOIP_DTMF_LEN * ENCODING_LENGTH];
    U8 currPos;
    U8 timerStatus;
} mmi_voip_dtmf_queue_struct;

typedef struct
{
    S32 currhiliteTab;
    S32 currhiliteIndex;
    S32 currfreeTab;
    U8 dispUri[VOIP_URI_LEN * ENCODING_LENGTH];         /* 128 unicode + 2 bytes null terminator. input and display uri for category screen */
    U8 inputUri[VOIP_URI_LEN];                          /* 64 ascii + 1 byte null terminator. actual inputted uri for VoIP CC */
    U8 dispDtmf[MMI_VOIP_DTMF_LEN * ENCODING_LENGTH];   /* 80 unicode + 2 bytes null terminator. input and display dtmf for category screen */
    U8 inputDtmf[MMI_VOIP_DTMF_LEN];                    /* 40 ascii + 1 byte null terminator. actual inputted dtmf for VoIP RTP */
    MMI_BOOL isSOS;
    MMI_BOOL isAbort;
    MMI_BOOL isDtmf;
    MMI_BOOL isMute;
    MMI_BOOL isLoud;
    mmi_voip_incoming_tone_enum playTone;
    mmi_voip_call_origin_enum actualOrigin;             /* temp origin call flag for merge call or split call */
    MYTIME actualTime;                                  /* temp time buffer for merge call or split call */
} mmi_voip_call_misc_struct;

typedef struct
{
    mmi_voip_mo_origin_enum moOrgin;
    U16 dispName[VOIP_DISP_NAME_LEN];
    U8 remoteUri[VOIP_URI_LEN];
} mmi_voip_call_originapp_struct;

typedef struct
{
    U16 mwiType;
    U16 mwiStr[MMI_VOIP_MAX_STRING_LEN];
    U8 mwiAcct[VOIP_URI_LEN];
    MMI_BOOL isDisp;
    voip_msg_struct mwiMsg;
} mmi_voip_msg_waiting_struct;

typedef struct
{
    mmi_voip_reg_state_enum reg_state_info;
    mmi_voip_prof_setting_struct prof_setting_info;
    mmi_voip_call_setting_struct call_setting_info;
    mmi_voip_proc_scr_struct proc_scr_info;
    mmi_voip_call_alert_struct call_alert_info;
    mmi_voip_call_list_struct call_list_info;
    mmi_voip_call_redial_struct call_redial_info;
    mmi_voip_dtmf_queue_struct dtmf_queue_info;
    mmi_voip_call_misc_struct call_misc_info;
    mmi_voip_call_originapp_struct call_originapp_info;
    mmi_voip_call_log_struct call_log_info;
    mmi_voip_msg_waiting_struct msg_waiting_info;
} mmi_voip_cntx_struct;

extern const U8 sipUri[10];
extern const U8 telUri[10];
extern const U8 anonyUri[30];
extern const U8 sosUri[8];
extern const U8 sos112[8];
extern const U8 sos911[8];
extern const U8 zeroIp[8];
extern const U16 VoIPDTMFDigits[MMI_VOIP_MAX_NUM_DIGITS];
extern mmi_voip_cntx_struct *g_voip_cntx_p;

/* VoIPMain.c */
#ifdef __MMI_WLAN_FEATURES__
extern void mmi_voip_wlan_state_callback(U16 state);
#endif
extern void mmi_voip_init_context(void);
extern void mmi_voip_init_setting_context(void);
extern void mmi_voip_init_call_context(void);
extern void mmi_voip_init_highlight_hdlr(void);
extern void mmi_voip_init_setting_highlight_hdlr(void);
extern void mmi_voip_init_setting_hint_hdlr(void);
extern void mmi_voip_init_call_highlight_hdlr(void);
extern void mmi_voip_init_call_hint_hdlr(void);
extern void mmi_voip_init_protocol_hdlr(void);
extern MMI_BOOL mmi_voip_load_profile(S32 profIndex);
extern MMI_BOOL mmi_voip_save_profile(S32 profIndex);
extern void mmi_voip_load_profile_active_index(void);
extern void mmi_voip_save_profile_active_index(void);
extern MMI_BOOL mmi_voip_load_setting(void);
extern MMI_BOOL mmi_voip_save_setting(void);

/* VoIPSetting.c */
extern void mmi_voip_highlight_main_menu(void);
extern void mmi_voip_highlight_status(void);
extern void mmi_voip_highlight_summary(void);
extern void mmi_voip_highlight_prof_setting(void);
extern void mmi_voip_highlight_prof_setting_option_activate(void);
extern void mmi_voip_highlight_prof_setting_option_edit(void);
extern void mmi_voip_highlight_prof_edit_common(void);
extern void mmi_voip_highlight_prof_edit_account(void);
extern void mmi_voip_highlight_prof_edit_outbound(void);
extern void mmi_voip_highlight_prof_edit_register(void);
extern void mmi_voip_highlight_prof_edit_nat(void);
extern void mmi_voip_highlight_full_screen_editor(void);
extern void mmi_voip_highlight_done(void);
extern void mmi_voip_highlight_input_method_in_menu(void);
extern void mmi_voip_highlight_call_setting(void);
extern void mmi_voip_highlight_auto_answer(void);
extern void mmi_voip_highlight_auto_reject(void);
extern void mmi_voip_highlight_auto_redial(void);
extern void mmi_voip_highlight_hide_caller_id(void);
extern void mmi_voip_highlight_dtmf_in_menu(void);
extern void mmi_voip_highlight_secure_rtp(void);
extern void mmi_voip_highlight_comfort_noise(void);
extern void mmi_voip_highlight_set_codec_order(void);
extern void mmi_voip_hint_auto_answer(U16 index);
extern void mmi_voip_hint_auto_reject(U16 index);
extern void mmi_voip_hint_auto_redial(U16 index);
extern void mmi_voip_hint_hide_caller_id(U16 index);
extern void mmi_voip_hint_dtmf_in_menu(U16 index);
extern void mmi_voip_hint_secure_rtp(U16 index);
extern void mmi_voip_hint_comfort_noise(U16 index);
#ifdef SIP_CONFORMANCE_TEST
extern void mmi_voip_highlight_option_query(void);
#endif
extern void mmi_voip_pre_entry_main_menu(void);
extern void mmi_voip_entry_main_menu(void);
extern void mmi_voip_entry_status(void);
extern void mmi_voip_entry_auto_login(void);
extern void mmi_voip_entry_abort_login(void);
extern void mmi_voip_entry_abort_login_endkey(void);
extern void mmi_voip_entry_summary(void);
extern void mmi_voip_entry_prof_setting(void);
extern void mmi_voip_highlight_prof_setting_item(S32 index);
extern void mmi_voip_entry_prof_setting_option(void);
extern void mmi_voip_entry_prof_activate(void);
extern void mmi_voip_entry_prof_edit(void);
extern void mmi_voip_pre_entry_prof_edit_inlineitems(void);
extern void mmi_voip_entry_prof_edit_inlineitems(void);
extern void mmi_voip_exit_prof_edit_inlineitems(void);
extern void mmi_voip_update_prof_common_cache_to_disp(S32 profIndex);
extern void mmi_voip_update_prof_acct_cache_to_disp(S32 profIndex);
extern void mmi_voip_update_prof_outbound_cache_to_disp(S32 profIndex);
extern void mmi_voip_update_prof_register_cache_to_disp(S32 profIndex);
extern void mmi_voip_update_prof_nat_cache_to_disp(S32 profIndex);
extern void mmi_voip_update_prof_common_disp_to_cache(S32 profIndex);
extern void mmi_voip_update_prof_acct_disp_to_cache(S32 profIndex);
extern void mmi_voip_update_prof_outbound_disp_to_cache(S32 profIndex);
extern void mmi_voip_update_prof_register_disp_to_cache(S32 profIndex);
extern void mmi_voip_update_prof_nat_disp_to_cache(S32 profIndex);
extern S32 mmi_voip_setup_prof_common_inlineitems(void);
extern S32 mmi_voip_setup_prof_acct_inlineitems(void);
extern S32 mmi_voip_setup_prof_outbound_inlineitems(void);
extern S32 mmi_voip_setup_prof_register_inlineitems(void);
extern S32 mmi_voip_setup_prof_nat_inlineitems(void);
extern void mmi_voip_entry_full_screen_editor_option(void);
extern void mmi_voip_entry_prof_data_acct(void);
extern void mmi_voip_prof_data_acct_callback(U32 index);
extern void mmi_voip_prof_ip_addr_convert(U8 *ipStr, U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4);
extern U16 mmi_voip_prof_validate_activation(S32 profIndex);
extern U16 mmi_voip_prof_validate_inputs(void);
extern void mmi_voip_entry_prof_confirm(void);
extern void mmi_voip_entry_prof_save(void);
extern void mmi_voip_go_back_to_prof_edit(void);
extern void mmi_voip_entry_call_setting(void);
extern void mmi_voip_entry_setting_general(void);
extern void mmi_voip_highlight_setting_general_item(S32 index);
extern void mmi_voip_update_setting_answer_cache_to_disp(void);
extern void mmi_voip_update_setting_reject_cache_to_disp(void);
extern void mmi_voip_update_setting_redial_cache_to_disp(void);
extern void mmi_voip_update_setting_hide_cache_to_disp(void);
extern void mmi_voip_update_setting_dtmf_cache_to_disp(void);
extern void mmi_voip_update_setting_srtp_cache_to_disp(void);
extern void mmi_voip_update_setting_noise_cache_to_disp(void);
extern void mmi_voip_update_setting_codec_cache_to_disp(void);
extern MMI_BOOL mmi_voip_update_setting_answer_disp_to_cache(void);
extern MMI_BOOL mmi_voip_update_setting_reject_disp_to_cache(void);
extern MMI_BOOL mmi_voip_update_setting_redial_disp_to_cache(void);
extern MMI_BOOL mmi_voip_update_setting_hide_disp_to_cache(void);
extern MMI_BOOL mmi_voip_update_setting_dtmf_disp_to_cache(void);
extern MMI_BOOL mmi_voip_update_setting_srtp_disp_to_cache(void);
extern MMI_BOOL mmi_voip_update_setting_noise_disp_to_cache(void);
extern MMI_BOOL mmi_voip_update_setting_codec_disp_to_cache(void);
extern void mmi_voip_entry_setting_general_confirm(void);
extern void mmi_voip_entry_setting_general_save(void);
extern void mmi_voip_go_back_to_call_setting(void);
extern void mmi_voip_entry_set_codec_order(void);
extern void mmi_voip_highlight_set_codec_order_item(S32 index);
extern void mmi_voip_entry_set_codec_order_option(void);
extern void mmi_voip_entry_setting_codec_confirm(void);
extern void mmi_voip_entry_setting_codec_save(void);
extern void mmi_voip_go_back_to_codec_order(void);
#ifdef SIP_CONFORMANCE_TEST
extern void mmi_voip_entry_option_query(void);
extern void mmi_voip_entry_option_query_result(U8 *asciiData);
#endif /* SIP_CONFORMANCE_TEST */
extern void mmi_voip_go_back_2_history(void);

/* VoIPCall.c */
extern void mmi_voip_highlight_new_call(void);
extern void mmi_voip_highlight_dial(void);
extern void mmi_voip_highlight_save_phonebook(void);
extern void mmi_voip_highlight_input_method_in_call(void);
extern void mmi_voip_highlight_sos(void);
extern void mmi_voip_highlight_hold_single(void);
extern void mmi_voip_highlight_hold_conference(void);
extern void mmi_voip_highlight_retrieve_single(void);
extern void mmi_voip_highlight_retrieve_conference(void);
extern void mmi_voip_highlight_swap(void);
extern void mmi_voip_highlight_conference(void);
extern void mmi_voip_highlight_split(void);
extern void mmi_voip_highlight_end_single(void);
extern void mmi_voip_highlight_end_conference(void);
extern void mmi_voip_highlight_end_all(void);
extern void mmi_voip_highlight_transfer(void);
extern void mmi_voip_highlight_phonebook(void);
extern void mmi_voip_highlight_sound_recorder(void);
extern void mmi_voip_highlight_mute(void);
extern void mmi_voip_highlight_dtmf_in_call(void);
extern void mmi_voip_highlight_transfer_option(void);
extern void mmi_voip_highlight_transfer_option_done(void);
extern void mmi_voip_hint_mute(U16 index);
extern void mmi_voip_hint_dtmf_in_call(U16 index);
extern void mmi_voip_entry_login_confirm(void);
extern void mmi_voip_go_back_to_call_editor(void);
extern void mmi_voip_entry_new_call(void);
extern void mmi_voip_entry_call_editor_option(void);
extern void mmi_voip_entry_outgoing_call(void);
extern void mmi_voip_entry_redialing_call(void);
extern void mmi_voip_entry_incoming_call(void);
extern void mmi_voip_entry_in_call(void);
extern void mmi_voip_exit_in_call(void);
extern void mmi_voip_highlight_in_call_item(S32 index);
extern void mmi_voip_tab_jump(S32 index);
extern void mmi_voip_tab_prev(void);
extern void mmi_voip_tab_next(void);
extern void mmi_voip_tab_highlight(void);
extern void mmi_voip_entry_dtmf_editor(void);
extern void mmi_voip_entry_call_option(void);
extern void mmi_voip_hide_call_option(void);
extern void mmi_voip_entry_transfer(void);
extern void mmi_voip_entry_transfer_option(void);
extern void mmi_voip_entry_multi_held_call(void);
extern void mmi_voip_highlight_multi_held_call_item(S32 index);
extern void mmi_voip_set_loud_speaker(void);
extern void mmi_voip_set_mute(void);
extern void mmi_voip_set_dtmf_in_call(void);
extern void mmi_voip_entry_popup(U8 *string, U16 imageId);
extern void mmi_voip_exit_popup(void);
extern void mmi_voip_entry_popup_over(void);
extern void mmi_voip_entry_marker(void);
extern void mmi_voip_go_back_screen_check(void);

/* VoIPSignal.c */
#ifdef SIP_CONFORMANCE_TEST
extern void mmi_voip_entry_option_query_check(void);
#endif
extern void mmi_voip_pre_dial(void);
extern void mmi_voip_entry_dial(void);
extern void mmi_voip_entry_redial(void);
extern void mmi_voip_entry_save_phonebook(void);
extern void mmi_voip_entry_sos(void);
extern void mmi_voip_entry_dial_sos(void);
// extern void mmi_voip_entry_abort_call(void);
extern void mmi_voip_entry_abort_redial(void);
extern void mmi_voip_entry_answer_call(void);
extern void mmi_voip_entry_reject_call(void);
extern void mmi_voip_entry_in_call_sendkey(void);
extern void mmi_voip_entry_in_call_endkey(void);
extern void mmi_voip_entry_sidekey(void);
extern void mmi_voip_pre_send_dtmf(void);
extern void mmi_voip_entry_hold_single(void);
extern void mmi_voip_entry_hold_conference(void);
extern void mmi_voip_entry_retrieve_single(void);
extern void mmi_voip_entry_retrieve_conference(void);
extern void mmi_voip_entry_swap(void);
extern void mmi_voip_entry_conference(void);
extern void mmi_voip_entry_split(void);
extern void mmi_voip_entry_end_single(void);
extern void mmi_voip_entry_end_conference(void);
extern void mmi_voip_entry_end_all(void);
extern void mmi_voip_entry_release_call(void);
extern void mmi_voip_entry_force_release(void);
extern void mmi_voip_entry_held_call_selected(void);
extern void mmi_voip_entry_transfer_call_determined(void);
extern S32 mmi_voip_get_active_call_id(void);
extern void mmi_voip_get_held_call_list(MMI_BOOL singlecallOnly);
extern S32 mmi_voip_get_call_index(S32 callId);
extern S32 mmi_voip_get_dialog_index(S32 callIndex, S32 dialogId);
extern void mmi_voip_log_call_end_time(S32 callId, S32 dialogId, MYTIME *duration);
extern void mmi_voip_log_call_history(S32 callId, S32 dialogId, mmi_voip_call_origin_enum callOrigin, MMI_BOOL isConnect);
extern void mmi_voip_log_call_duration(S32 callId, S32 dialogId, mmi_voip_call_origin_enum callOrigin);

/* VoIPVoice.c */
extern void mmi_voip_switch_session(mmi_voip_call_state_enum currState);
extern S32 mmi_voip_create_rtp(voip_sdp_struct *sdp);
extern void mmi_voip_close_rtp(S32 rtpHandle);
extern void mmi_voip_switch_rtp(MMI_BOOL isSuspend, S32 callId, S32 dialogId);
extern void mmi_voip_control_rtp(S32 rtpHandle, S32 rtpDirection);
extern void mmi_voip_remove_mixer_before_close(S32 callIndex);
extern void mmi_voip_dtmf_key_down(void);
extern void mmi_voip_dtmf_key_up(void);
extern void mmi_voip_push_dtmf_queue(U16 keyCode);
extern void mmi_voip_pop_dtmf_queue(void);
extern void mmi_voip_send_dtmf_start(U16 keyCode);
extern void mmi_voip_send_dtmf_stop(void);

/* VoIPMsgHdlr.c */
extern void mmi_voip_send_message(
                module_type moduleSrc,
                module_type moduleDest,
                U16 msgId,
                void *localPara,
                void *peerBuff);
extern void mmi_voip_register_req(void);
extern void mmi_voip_register_rsp(void *inMsg);
extern void mmi_voip_deregister_req(void);
extern void mmi_voip_deregister_rsp(void *inMsg);
extern void mmi_voip_deregister_ind(void *inMsg);
extern void mmi_voip_setting_req(void);
extern void mmi_voip_setting_rsp(void *inMsg);
extern void mmi_voip_progressing_ind(void *inMsg);
extern void mmi_voip_call_ring_ind(void *inMsg);
extern void mmi_voip_call_end_ind(void *inMsg);
extern void mmi_voip_call_state_ind(void *inMsg);
extern void mmi_voip_call_replace_ind(void *inMsg);
extern void mmi_voip_call_replace_cnf(U8 result, void *inMsg);
extern void mmi_voip_call_replace_complete_ind(void *inMsg);
extern void mmi_voip_msg_waiting_ind(void *inMsg);
extern void mmi_voip_at_call_ctrl_approve_ind(void *inMsg);
extern void mmi_voip_at_call_ctrl_approve_res_req(U8 result, U8 action);
extern void mmi_voip_call_status_req(U8 status);
extern void mmi_voip_call_status_rsp(void *inMsg);
#ifdef SIP_CONFORMANCE_TEST
extern void mmi_voip_option_query_req(void);
extern void mmi_voip_option_query_rsp(void *inMsg);
#endif /* SIP_CONFORMANCE_TEST */
extern void mmi_voip_dispatch_call_act_rsp(void *inMsg);
extern void mmi_voip_dial_req(void);
extern void mmi_voip_dial_rsp(void *inMsg);
extern void mmi_voip_accept_req(S32 callId);
extern void mmi_voip_accept_rsp(void *inMsg);
extern void mmi_voip_hold_req(S32 callId);
extern void mmi_voip_hold_rsp(void *inMsg);
extern void mmi_voip_retrieve_req(S32 callId);
extern void mmi_voip_retrieve_rsp(void *inMsg);
extern void mmi_voip_swap_req(S32 activecallId, S32 heldcallId);
extern void mmi_voip_swap_rsp(void *inMsg);
extern void mmi_voip_merge_req(S32 activecallId, S32 heldcallId);
extern void mmi_voip_merge_rsp(void *inMsg);
extern void mmi_voip_split_req(S32 callId, S32 helddialogId);
extern void mmi_voip_split_rsp(void *inMsg);
extern void mmi_voip_release_req(S32 callId, S32 dialogId);
extern void mmi_voip_release_rsp(void *inMsg);
extern void mmi_voip_force_release_req(S32 callId, S32 dialogId);
extern void mmi_voip_force_release_rsp(void *inMsg);
extern void mmi_voip_background_reject_req(S32 callId, S32 dialogId);
extern void mmi_voip_background_reject_rsp(void *inMsg);
extern void mmi_voip_background_release_all_req(void);
extern void mmi_voip_background_release_all_rsp(void *inMsg);
extern void mmi_voip_transfer_req(S32 callId, S32 dialogId);
extern void mmi_voip_transfer_rsp(void *inMsg);
extern void mmi_voip_transferee_cnf(U8 result);
extern void mmi_voip_dial_sos_req(void);
extern void mmi_voip_dial_sos_rsp(void *inMsg);
extern void mmi_voip_hold_and_dial_req(S32 callId);
extern void mmi_voip_hold_and_dial_rsp(void *inMsg);
extern void mmi_voip_hold_and_accept_req(S32 activecallId, S32 mtcallId);
extern void mmi_voip_hold_and_accept_rsp(void *inMsg);

/* VoIPUtil.c */
extern void mmi_voip_set_processing_parameter(U16 titleStr, U16 bodyStr, U16 animationImg, U16 lskStr, FuncPtr lskFunc, U16 rskStr, FuncPtr rskFunc, FuncPtr sendFunc, FuncPtr endFunc);
extern void mmi_voip_entry_processing_screen(void);
extern MMI_BOOL mmi_voip_validate_port(U8 *unicodePort);
extern MMI_BOOL mmi_voip_validate_uri(U8 *unicodeUri);
extern MMI_BOOL mmi_voip_validate_ip(U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4);
extern MMI_BOOL mmi_voip_validate_dtmf(U16 dtmfKey);
extern void mmi_voip_parse_uri(U8 *unicodeUri);
extern void mmi_voip_convert_uri_star_n_pound(U8 *asciiSrc);
extern void mmi_voip_convert_uri_lower_case(U8 *unicodeSrc, U8 *unicodeDest);
extern void mmi_voip_append_uri_prefix(U8 *unicodeUri);
extern void mmi_voip_append_uri_domain(U8 *unicodeUri);
extern void mmi_voip_add_to_call_list(U16 *fileName, S32 callId, S32 dialogId, mmi_voip_call_state_enum currState);
extern void mmi_voip_del_from_call_list(S32 callId, S32 dialogId);
extern void mmi_voip_update_call_list(U16 *fileName, MMI_BOOL isConf);
extern void mmi_voip_update_to_del_call_list(U16 *fileName, MMI_BOOL isConf);
extern void mmi_voip_update_to_add_call_list(U16 *fileName, MMI_BOOL isConf);
extern void mmi_voip_get_summary_string(U8 *unicodeStr);
extern mmi_voip_call_state_enum mmi_voip_get_call_state_enum(voip_dlg_state_enum state);
extern void mmi_voip_get_call_end_string(MYTIME *duration, U8 *unicodeStr);
extern rtp_dtmf_code_enum mmi_voip_get_dtmf_keycode_enum(U16 *keyCode);
extern U16 mmi_voip_get_error_cause(U8 result, S32 cause);
extern U16 mmi_voip_get_error_string(S32 cause);
extern MMI_BOOL mmi_voip_set_outgoing_origin_app(mmi_voip_mo_origin_enum moOrigin);
extern MMI_BOOL mmi_voip_get_outgoing_disp_name(U8 moOrigin, U8 *unicodeSrc, U8 *unicodeDest, U8 destLen);
extern void mmi_voip_get_redial_string(U8 *unicodeStr);
extern U16 mmi_voip_get_mwi_state_enum(voip_mwi_type_enum state);
extern void mmi_voip_get_mwi_string(U8 *unicodeStr);
extern MMI_BOOL mmi_voip_is_idle_state(void);
extern MMI_BOOL mmi_voip_is_keypad_lock_state(void);
extern MMI_BOOL mmi_voip_is_empty_profile(S32 profIndex);
extern MMI_BOOL mmi_voip_is_owner_number(U8 *unicodeSrc1, U8 *unicodeSrc2);
extern MMI_BOOL mmi_voip_is_sos_number(U8 *unicodeUri);
extern MMI_BOOL mmi_voip_is_codec_compatible(voip_codec_enum *codecList, MMI_BOOL firstcodecOnly);
extern MMI_BOOL mmi_voip_is_addr_change(voip_sdp_struct *mmiSdp, voip_sdp_struct *voipSdp);
extern void mmi_voip_play_inbandtone(void);
extern void mmi_voip_stop_inbandtone(void);
extern void mmi_voip_play_incoming_tone(void);
extern void mmi_voip_stop_incoming_tone(void);
extern void mmi_voip_play_ringtone(void);
extern void mmi_voip_stop_ringtone(void);
extern void mmi_voip_play_vibration_then_ring(void);
extern void mmi_voip_play_waitingtone(void);
extern void mmi_voip_stop_waitingtone(void);
extern void mmi_voip_play_droptone(void);
extern void mmi_voip_stop_droptone(void);
#endif /* VOIP_PROT_H */ 

