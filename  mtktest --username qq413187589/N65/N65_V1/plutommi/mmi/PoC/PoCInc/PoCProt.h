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
 * PoCProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines mmi poc prototypes
 *
 * Author:
 * -------
 * -------
 *
==============================================================
 *              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *=============================================================
 *******************************************************************************/

#ifndef _MMI_POC_PROT_H
#define _MMI_POC_PROT_H

#define __MMI_POC_REM_OTHERS_GROUP__

// #define __POC_MMI_TEST_XDM_ONLY__

/*---------------------------------------------------------------------------*/
/* Header files */
/*---------------------------------------------------------------------------*/

// #include "PoCTempPSSAP.h"
#include "app2sip_struct.h"
#include "mmi2poc_enums.h"
#include "mmi2poc_struct.h"

/*---------------------------------------------------------------------------*/
/* Definition */
/*---------------------------------------------------------------------------*/

#define POC_MAX_TALK_STATUS_ENTRY_NUM   10
#define POC_MAX_HISTORY_NUM 10
#define POC_MAX_PROFILE_NUM 3
#define POC_MAX_PROF_NAME_LEN   20
#define POC_MAX_PROFILE_PORT_LEN    6
#define POC_MAX_GROUP_PARTICIPANT_LEN   3
#define POC_MAX_GROUP_TYPE_OPTION_NUM 2
#define MMI_POC_MAX_MSG_LEN 32
#define POC_REQUEST_ID  1
#define POC_MAX_ENTRY_INFO_DISP_NUM 200
#define POC_MAX_DAY_LEN             14*ENCODING_LENGTH  /* 04/03/12 Thu */
#define POC_MAX_TIME_LEN                14*ENCODING_LENGTH      /* 12:12 - 13:15 */
#define POC_MAX_ACTIVITY_NUM    4
#define POC_MAX_MOOD_NUM        4
#define POC_MAX_INLINE_ADDR_LEN 40

#define POC_TALK_TONE   TONE_GENERAL_BEEP
#define POC_MO_RING_TONE    TONE_RINGING_CALL_GSM_STK
#define POC_MT_RING_TONE    TONE_POSITIVE_ACK_STK

#define POC_MMI_MTK_RLS_URI                 "sip:mtkrls_"
#define POC_MMI_SIP_PREFIX                      "sip:"
#define POC_MMI_HTTP_PREFIX                 "http://"
#define POC_MMI_DEFAULT_PRIVACY_ADDR            "sip:anonymous@x.x"

extern const S8 g_poc_three_dot[];

/*---------------------------------------------------------------------------*/
/* Enum */
/*---------------------------------------------------------------------------*/
typedef enum
{
    POC_REG_NONE,
    POC_REG_REGED,
    POC_REG_REGING,
    POC_REG_DEREGING
} POC_REG_STATE;

typedef enum
{
    POC_CONTACT_NAME_STR = 0,
    POC_CONTACT_NAME,
    POC_CONTACT_URI_STR,
    POC_CONTACT_URI,
    POC_CONTACT_ATTR_STR,
    POC_CONTACT_ATTR,
    POC_CONTACT_INLINE_NUM
} POC_CONTACT_INLINE;

typedef enum
{
    POC_TALK_GROUP_NAME_STR = 0,
    POC_TALK_GROUP_NAME,
    POC_TALK_GROUP_URI_STR,
    POC_TALK_GROUP_URI,
    POC_TALK_GROUP_MAX_PARTICIPANT_STR,
    POC_TALK_GROUP_MAX_PARTICIPANT,
    POC_TALK_GROUP_INVITE_MEMBER_STR,
    POC_TALK_GROUP_INVITE_MEMBER,
    POC_TALK_GROUP_DEFAULT_RULE_STR,
    POC_TALK_GROUP_DEFAULT_RULE,
    POC_TALK_GROUP_INLINE_NUM
} POC_TALK_GROUP_INLINE;

typedef enum
{
    POC_CALL_OTHERS_GROUP_URI_STR = 0,
    POC_CALL_OTHERS_GROUP_URI,
    POC_CALL_OTHERS_GROUP_INVITE_MEMBER_STR,
    POC_CALL_OTHERS_GROUP_INVITE_MEMBER,
    POC_CALL_OTHERS_GROUP_INLINE_NUM
} POC_CALL_OTHERS_GROUP_INLINE;

typedef enum
{
    POC_TALK_GROUP_ENTRY_URI_STR = 0,
    POC_TALK_GROUP_ENTRY_URI,
    POC_TALK_GROUP_ENTRY_ATTR_STR,
    POC_TALK_GROUP_ENTRY_ATTR,
    POC_TALK_GROUP_ENTRY_INLINE_NUM
} POC_TALK_GROUP_ENTRY_INLINE;

typedef enum
{
    POC_HISTORY_INFO_DATE = 0,
    POC_HISTORY_INFO_TIME,
    POC_HISTORY_INFO_NAME_STR,
    POC_HISTORY_INFO_NAME,
    POC_HISTORY_INFO_URI_STR,
    POC_HISTORY_INFO_URI,
    POC_HISTORY_INFO_MSG_STR,
    POC_HISTORY_INFO_MSG,
    POC_HISTORY_INFO_INLINE_NUM
} POC_HISTORY_INFO_INLIN;

typedef enum
{
    POC_PROFILE_POC_NAME_STR = 0,
    POC_PROFILE_POC_NAME,
    POC_PROFILE_POC_DISP_NAME_STR,
    POC_PROFILE_POC_DISP_NAME,
    POC_PROFILE_POC_URI_STR,
    POC_PROFILE_POC_URI,
    POC_PROFILE_POC_PASS_STR,
    POC_PROFILE_POC_PASS,
    POC_PROFILE_POC_SERVERADDR_STR,
    POC_PROFILE_POC_SERVERADDR,
    POC_PROFILE_POC_SERVERPORT_STR,
    POC_PROFILE_POC_SERVERPORT,
    POC_PROFILE_POC_XDMADDR_STR,
    POC_PROFILE_POC_XDMADDR,
    POC_PROFILE_POC_INLINE_NUM
} POC_PROFILE_POC_INLINE;

typedef enum
{
    POC_PROFILE_CONN_DATA_ACCOUNT_STR = 0,
    POC_PROFILE_CONN_DATA_ACCOUNT,
    POC_PROFILE_CONN_USE_PROXY_STR,
    POC_PROFILE_CONN_USE_PROXY,
    POC_PROFILE_CONN_PROXYADDR_STR,
    POC_PROFILE_CONN_PROXYRADDR,
    POC_PROFILE_CONN_PROXYPORT_STR,
    POC_PROFILE_CONN_PROXYPORT,
    POC_PROFILE_CONN_USERNAME_STR,
    POC_PROFILE_CONN_USERNAME,
    POC_PROFILE_CONN_PASS_STR,
    POC_PROFILE_CONN_PASS,
    POC_PROFILE_CONN_INLINE_NUM
} POC_PROFILE_CONN_INLINE;

typedef enum
{
    POC_PTT_UP,
    POC_PTT_DOWN
} POC_PTT_BUTTON_STATUS;

typedef enum
{
    POC_CALL_NONE,
    POC_CALL_ACTIVE,
    POC_CALL_PROGRESSING
} POC_CALL_STATUS;

typedef enum
{
    POC_ABORT_NONE,
    POC_ABORT_BACK,
    POC_ABORT_END
} POC_PTT_ABORT_TYPE;

typedef enum
{
    POC_AUDIO_NONE,
    POC_AUDIO_ENCODING,
    POC_AUDIO_DECODING
} POC_PTT_AUDIO_STATUS;

typedef enum
{
    POC_BOOTREG_NONE,
    POC_BOOTREG_SENT,
    POC_BOOTREG_FINISH
} POC_BOOTREG_STATUS;

typedef enum
{
    POC_HIS_NONE,
    POC_HIS_IN_CALL,
    POC_HIS_IN_ALERT,
    POC_HIS_OUT_CALL,
    POC_HIS_OUT_ALERT
} POC_HISTORY_TYPE;

typedef enum
{
    POC_PRES_ACTIVITY,
    POC_PRES_MOOD,
    POC_PRES_ALL,
    POC_PRES_TOTAL_NUM
} POC_PRES_ATTR;

typedef enum
{
    POC_TALK_ENTRY_NEW,
    POC_TALK_ENTRY_FROM_CONTACT
} POC_TALK_ENTRY_SOURCE;

typedef enum
{
    POC_INCOMING_CALL,
    POC_INCOMING_ALERT,
    POC_OUTGOING_CALL,
    POC_OUTGOING_ALERT
} POC_CALL_TYPE_ENUM;

typedef enum
{
    POC_TALK_STATUS_NOT_READY,
    POC_TALK_STATUS_ON,
    POC_TALK_STATUS_OFF
} POC_TALK_STATUS_ENUM;

typedef enum
{
    POC_MMI_SUB_EMPTY,
    POC_MMI_SUB_BLOCK,
    POC_MMI_SUB_CONFIRM,
    POC_MMI_SUB_POLITE_BLOCK,
    POC_MMI_SUB_ALLOW,
    POC_MMI_SUB_UNRECOGNIZED
} POC_MMI_SUB_HANDLING_ENUM;

/*--------------------------------------------------------------------------*/
/* Struct */
/*---------------------------------------------------------------------------*/

typedef struct
{
    /* poc settings */
    U8 prof_name[POC_MAX_PROF_NAME_LEN];
    U8 disp_charset;
    U8 disp_name[POC_MAX_DISP_LEN];
    U8 uri[POC_MAX_URI_LEN];                    /* ASCII, null-terminated */
    U8 password[POC_MAX_PASSWORD_LEN];          /* ASCII, null-terminated */
    U8 poc_addr[POC_PROXY_ADDR_LEN];            /* ASCII, null-terminated */
    U16 poc_port;
    U8 xdm_addr[POC_PROXY_ADDR_LEN];
    /* conn settings */
    U8 data_account;
    U8 use_proxy;
    U8 proxy_username[XDM_MAX_PROXY_USERNAME_LEN];
    U8 proxy_password[XDM_MAX_PROXY_PASS_LEN];  /* ASCII, null-terminated */
    U8 proxy_ip[XDM_MAX_IP_LEN];                /* ASCII, null-terminated */
    U16 proxy_port;
} mmi_poc_profile_struct;

typedef struct
{
    /* poc settings */
    U8 prof_name[POC_MAX_PROF_NAME_LEN];
    U8 disp_charset;
    U8 disp_name[POC_MAX_DISP_LEN *ENCODING_LENGTH];
    U8 uri[POC_MAX_URI_LEN *ENCODING_LENGTH];           /* ASCII, null-terminated */
    U8 password[POC_MAX_PASSWORD_LEN *ENCODING_LENGTH]; /* ASCII, null-terminated */
    U8 poc_addr[POC_PROXY_ADDR_LEN *ENCODING_LENGTH];   /* ASCII, null-terminated */
    U8 poc_port[POC_MAX_PROFILE_PORT_LEN *ENCODING_LENGTH];
    U8 xdm_addr[POC_PROXY_ADDR_LEN *ENCODING_LENGTH];
    /* conn settings */
    U8 data_account;
    S32 use_proxy;
    U8 proxy_username[XDM_MAX_PROXY_USERNAME_LEN *ENCODING_LENGTH];
    U8 proxy_password[XDM_MAX_PROXY_PASS_LEN *ENCODING_LENGTH];        /* ASCII, null-terminated */
    U8 proxy_ip[XDM_MAX_IP_LEN][XDM_MAX_IP_LEN *ENCODING_LENGTH];      /* ASCII, null-terminated */
    U8 proxy_port[POC_MAX_PROFILE_PORT_LEN *ENCODING_LENGTH];
    U8 *yes_no_list[2];
    U8 dt_acct_name[(MAX_DATA_ACCOUNT_NAME_LEN + 1)];   /* Name of current selected data account */
} mmi_poc_profile_disp_struct;

typedef struct
{
    U8 allow_invite;    /* poc_setting_enum */
    U8 sub_pres;
    poc_pres_authrule_struct auth_rule;
    U8 uri[POC_MAX_URI_LEN *ENCODING_LENGTH];
    U8 display_name[POC_MAX_DISP_LEN *ENCODING_LENGTH];
    mmi_poc_presence_struct pres;
} mmi_poc_contact_entry_disp_struct;

typedef struct
{
    U8 list_name[POC_MAX_DISP_LEN];
    U8 uri[POC_MAX_URI_LEN];
    U8 message[MMI_POC_MAX_MSG_LEN];
    MYTIME time;
    U8 type;    /* POC_CALL_TYPE_ENUM */
    U8 rejoinable;
} mmi_poc_history_entry_struct;

typedef struct
{
    U8 date[POC_MAX_DAY_LEN];
    U8 time[POC_MAX_TIME_LEN];
    U8 list_name[POC_MAX_DISP_LEN *ENCODING_LENGTH];
    U8 uri[POC_MAX_URI_LEN *ENCODING_LENGTH];
    U8 message[MMI_POC_MAX_MSG_LEN *ENCODING_LENGTH];
} mmi_poc_history_entry_disp_struct;

typedef struct
{
    mmi_poc_history_entry_struct entries[POC_MAX_HISTORY_NUM];
    U8 no_entries;
} mmi_poc_history_struct;

typedef struct
{
    poc_group_param_struct group_rule;
    U8 uri[POC_MAX_URI_LEN *ENCODING_LENGTH];
} poc_talk_group_entry_disp_struct;

typedef struct
{
    U8 list_uri[POC_MAX_URI_LEN *ENCODING_LENGTH];
    U8 display_name_lang;
    U8 display_name[POC_MAX_DISP_LEN *ENCODING_LENGTH];
    U8 max_participant_count[POC_MAX_GROUP_PARTICIPANT_LEN *ENCODING_LENGTH];
    U8 *invite_member_option[POC_MAX_GROUP_TYPE_OPTION_NUM];
    S32 invite_member;
    poc_group_param_struct default_rule;
    U8 no_entries;
    poc_talk_group_entry_struct *entries;
} poc_talk_group_disp_struct;

typedef struct
{
    U8 contact;
    U8 alert;
    U8 refresh;
    U8 my_status;
    U8 poc_settings;
} mmi_poc_progressing_struct;

typedef struct
{
    U8 status;
    U8 name[POC_MAX_DISP_LEN];
    U8 uri[POC_MAX_URI_LEN];
} mmi_poc_talk_list_struct;

typedef struct
{
    /* structure and array */
    mmi_poc_contact_struct *contact_list;
    poc_talk_group_struct *talk_group_list;
    mmi_poc_history_struct history;
    mmi_poc_profile_struct profile_list[POC_MAX_PROFILE_NUM];
    mmi_poc_person_pinfo_struct person_pres;
    poc_addr_struct privacy_addr;

    mmi_poc_contact_list_disp *contact_list_disp;
    mmi_poc_contact_entry_disp_struct contact_entry_disp;

    poc_talk_group_entry_disp_struct talk_entry_disp;
    poc_talk_group_disp_struct talk_group_disp;
    mmi_poc_history_entry_disp_struct history_disp;
    mmi_poc_person_pinfo_struct person_pres_disp;
    U8 privacy_addr_disp[POC_MAX_URI_LEN *ENCODING_LENGTH];
    U8 pres_attr_disp[POC_PRES_TOTAL_NUM];
    U8 *adhoc_sel_disp;
    mmi_poc_profile_disp_struct profile_disp;
    mmi_poc_progressing_struct progressing;
    U8 cm_talk_list_num;
    mmi_poc_talk_list_struct cm_talk_list[POC_MAX_TALK_STATUS_ENTRY_NUM];
    mmi_poc_talk_list_struct calling_disp;

#ifdef __MMI_POC_REM_OTHERS_GROUP__
    poc_talk_group_disp_struct others_group_disp;
#endif 

    U8 cm_disp[POC_MAX_DISP_LEN *3];    /* disp_name +  operation string ( inviting / connection / ....) */
    U8 cm_talk_group_name[POC_MAX_DISP_LEN];
    U8 alert_text_buf[MMI_POC_MAX_MSG_LEN *ENCODING_LENGTH];

    /* 4 bytes */
    FuncPtr media_stop_encode_callback;
    FuncPtr media_stop_decode_callback;
    S32 contact_selected;
    S32 talk_group_selected;
    S32 talk_entry_selected;
    S32 call_history_selected;
    S32 activity_selected;
    S32 mood_selected;
    S32 profile_selected;
    S32 general_err_cause;
    U32 active_talk_id;

    /* 2 bytes */
    U16 proxy_port;

    /* 1 byte */
    U8 talk_entry_info_source;
    U8 curr_contact_op;
    U8 curr_talk_group_op;
    U8 contact_local_updated;
    U8 talk_group_local_updated;
    U8 contact_num;
    U8 talk_group_num;
    U8 profile_active;
    U8 curr_reg_state;
    U8 curr_ans_mode;   /* TRUE: Auto, FALSE, manual */
    U8 curr_call_bar_mode;
    U8 curr_alert_bar_mode;
    U8 curr_mao_mode;
    U8 curr_privacy_mode;
    U8 curr_boot_start_mode;
    U8 curr_use_xdm_mode;
    U8 curr_use_pres_mode;
    U8 ptt_button_status;
    U8 abort_type;
    U8 audio_status;
    U8 mo_inviting;
    U8 call_status;
    U8 power_on_reg_sent;
    U8 curr_group_id;
    U8 curr_entry_id;
    U8 reg_error;
    U8 talk_pres_ind_recved;
    U8 in_call_inviting;
    U8 curr_talk_staus_subscribe;
    U8 session_xdm;
    U8 floor_idle_recved;
    U8 update_grp_idx;
    U8 inline_item_changed;
} mmi_poc_context_struct;

typedef struct
{
    U8 ref_count;
    U16 msg_len;
} mmi_poc_dummy_req_struct;

/*---------------------------------------------------------------------------*/
/* Variables */
/*---------------------------------------------------------------------------*/

extern mmi_poc_context_struct *g_poc_cntx_p;    /* global context of poc */

/*---------------------------------------------------------------------------*/
/* Prototypes */
/*---------------------------------------------------------------------------*/

/* PoC Main functions */
extern void mmi_poc_init(void);
extern void mmi_poc_init_highlight_hdlr(void);
extern void mmi_poc_init_protocol_hdlr(void);
extern void mmi_poc_highlight_main(void);
extern void mmi_poc_highlight_status(void);
extern void mmi_poc_highlight_call_history(void);
extern void mmi_poc_highlight_call_history_info(void);
extern void mmi_poc_highlight_call_history_info_option_delete(void);
extern void mmi_poc_highlight_call_history_info_option_delete_all(void);
extern void mmi_poc_highlight_settings(void);
extern void mmi_poc_highlight_settings_my_status(void);
extern void mmi_poc_highlight_settings_my_status_activity(void);
extern void mmi_poc_highlight_settings_my_status_mood(void);
extern void mmi_poc_highlight_settings_ans_mode(void);
extern void mmi_poc_highlight_settings_call_barring(void);
extern void mmi_poc_highlight_settings_alert_barring(void);
extern void mmi_poc_highlight_settings_mao(void);
extern void mmi_poc_highlight_settings_privacy(void);
extern void mmi_poc_highlight_settings_privacy_disable(void);
extern void mmi_poc_highlight_settings_privacy_enable(void);
extern void mmi_poc_highlight_settings_start_at_bootup(void);
extern void mmi_poc_highlight_settings_use_xdm(void);
extern void mmi_poc_highlight_settings_use_pres(void);
extern void mmi_poc_highlight_settings_profiles(void);
extern void mmi_poc_highlight_settings_profiles_option_activate(void);
extern void mmi_poc_highlight_settings_profiles_option_edit(void);
extern void mmi_poc_highlight_settings_profiles_option_edit_poc(void);
extern void mmi_poc_highlight_settings_profiles_option_edit_conn(void);
extern void mmi_poc_hint_status(U16 index);
extern void mmi_poc_hint_my_activity(U16 index);
extern void mmi_poc_hint_my_mood(U16 index);
extern void mmi_poc_hint_ans_mode(U16 index);
extern void mmi_poc_hint_call_barring_mode(U16 index);
extern void mmi_poc_hint_alert_barring_mode(U16 index);
extern void mmi_poc_hint_mao_mode(U16 index);
extern void mmi_poc_hint_privacy_mode(U16 index);
extern void mmi_poc_hint_boot_start(U16 index);
extern void mmi_poc_hint_use_xdm(U16 index);
extern void mmi_poc_hint_use_pres(U16 index);
extern void mmi_poc_hint_prof(U16 index);
extern void mmi_poc_entry_main_pre(void);
extern void mmi_poc_init_prof_setting_check(FuncPtr ready_callback);
extern void mmi_poc_entry_main(void);
extern void mmi_poc_entry_call_history(void);
extern void mmi_poc_history_highlight_handler(S32 ind);
extern void mmi_poc_call_history_rejoin(void);
extern void mmi_poc_three_digit_string(PU8 StringVal, U8 DigitVal);

#ifdef __MMI_POC_ETS_TESTCODE__
extern void mmi_poc_highlight_call_history_rejoin_fake(void);
extern void mmi_poc_call_history_rejoin_fake(void);
#endif /* __MMI_POC_ETS_TESTCODE__ */ 
extern void mmi_poc_entry_call_history_info(void);
extern void mmi_poc_exit_call_history_info(void);
extern void mmi_poc_history_fill_inline_struct(void);
extern void mmi_poc_entry_call_history_info_option(void);
extern void mmi_poc_call_history_delete_cfrm(void);
extern void mmi_poc_history_delete_nvram(void);
extern void mmi_poc_go_back_history_list(void);
extern void mmi_poc_call_history_delete_all_cfrm(void);
extern void mmi_poc_history_delete_all_nvram(void);
extern void mmi_poc_history_add(U8 type, U8 rejoinable, U8 *list_name, U8 *uri, U8 *message);
extern void mmi_poc_entry_settings(void);
extern void mmi_poc_entry_settings_my_status(void);
extern void mmi_poc_entry_settings_my_status_activity(void);
extern void mmi_poc_activity_highlight_handler(S32 index);
extern void mmi_poc_entry_set_activity(void);
extern void mmi_poc_presence_publish_req(void);
extern void mmi_poc_presence_publish_rsp(void *info);
extern void mmi_poc_entry_settings_my_status_mood(void);
extern void mmi_poc_mood_highlight_handler(S32 index);
extern void mmi_poc_entry_set_mood(void);
extern void mmi_poc_switch_ans_mode(void);
extern void mmi_poc_switch_ans_mode_req(void);
extern void mmi_poc_switch_ans_mode_rsp(void *info);
extern void mmi_poc_switch_call_barring_mode(void);
extern void mmi_poc_switch_call_barring_mode_req(void);
extern void mmi_poc_switch_call_barring_mode_rsp(void *info);
extern void mmi_poc_switch_alert_barring_mode(void);
extern void mmi_poc_switch_mao_mode(void);
extern void mmi_poc_switch_alert_barring_mode_req(void);
extern void mmi_poc_switch_mao_mode_req(void);
extern void mmi_poc_switch_alert_barring_mode_rsp(void *info);
extern void mmi_poc_switch_mao_mode_rsp(void *info);
extern void mmi_poc_entry_settings_privacy(void);
extern void mmi_poc_set_privacy_disable(void);
extern void mmi_poc_set_privacy_disable_req(void);
extern void mmi_poc_set_privacy_disable_rsp(void *info);
extern void mmi_poc_entry_settings_privacy_enable(void);
extern void mmi_poc_privacy_addr_msg_key(U8 *text, U8 *cursor, S32 length);
extern void mmi_poc_set_privacy_enable_req(void);
extern void mmi_poc_set_privacy_enable_rsp(void *info);
extern void mmi_poc_set_start_at_bootup(void);
extern void mmi_poc_set_xdm_mode(void);
extern void mmi_poc_set_pres_mode(void);
extern void mmi_poc_entry_settings_profiles(void);
extern void mmi_poc_profile_highlight_handler(S32 index);
extern void mmi_poc_entry_settings_profiles_opt(void);
extern void mmi_poc_set_activate_profile(void);
extern void mmi_poc_entry_setting_prof_edit_pre(void);
extern void mmi_poc_entry_settings_profiles_edit(void);
extern void mmi_poc_entry_settings_profiles_option_edit_poc(void);
extern void mmi_poc_exit_settings_profiles_option_edit_poc(void);
extern void mmi_poc_entry_profile_edit_cfrm(void);
extern void mmi_poc_go_back_profile(void);
extern void mmi_poc_profile_fill_inline_struct(void);
extern void mmi_poc_entry_full_line_edit(void);
extern void mmi_poc_profile_edit_nvram(void);
extern void mmi_poc_entry_settings_profiles_option_edit_conn(void);
extern void mmi_poc_exit_settings_profiles_option_edit_conn(void);
extern void mmi_poc_prof_conn_fill_inline_struct(void);
extern void mmi_poc_prof_list_data_acct(void);
extern void mmi_poc_prof_gprs_dt_callback(U32 index);
extern void mmi_poc_prof_ip_addr_callback(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);
extern void mmi_poc_entry_profile_edit_conn_cfrm(void);
extern void mmi_poc_profile_edit_conn_nvram(void);

/* PoC Group functions */
extern void mmi_poc_highlight_contact(void);
extern void mmi_poc_highlight_contact_opt(void);
extern void mmi_poc_highlight_contact_opt_settings(void);
extern void mmi_poc_highlight_contact_opt_settings_modify(void);
extern void mmi_poc_highlight_contact_opt_settings_add(void);
extern void mmi_poc_highlight_contact_opt_settings_delete(void);
extern void mmi_poc_highlight_contact_opt_settings_info(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_allow_invite(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_accept(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_auto(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_reject(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_block(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_polite_block(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_allow(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_provide_pres(void);
extern void mmi_poc_highlight_contact_opt_settings_attributes_subscribe_pres(void);
extern void mmi_poc_highlight_contact_opt_send_alert(void);
extern void mmi_poc_highlight_contact_opt_adhoc_talk(void);
extern void mmi_poc_highlight_contact_opt_refresh_status(void);
extern void mmi_poc_highlight_talk_groups(void);
extern void mmi_poc_highlight_talk_groups_opt(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_add(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_add_from_contact(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_delete(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_info(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_conf_state(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_invite_user_dyna(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_join_handling(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_init_conf(void);
extern void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_anonymity(void);
extern void mmi_poc_highlight_talk_groups_opt_add_group(void);
extern void mmi_poc_highlight_talk_groups_opt_delete_group(void);
extern void mmi_poc_highlight_talk_groups_opt_group_info(void);
extern void mmi_poc_highlight_talk_groups_info_entry_attributes_conf_state(void);
extern void mmi_poc_highlight_talk_groups_info_entry_attributes_invite_user_dyna(void);
extern void mmi_poc_highlight_talk_groups_info_entry_attributes_join_handling(void);
extern void mmi_poc_highlight_talk_groups_info_entry_attributes_init_conf(void);
extern void mmi_poc_highlight_talk_groups_info_entry_attributes_anonymity(void);
extern void mmi_poc_highlight_talk_groups_opt_call_others_group(void);
extern void mmi_poc_hint_allow_invite(U16 index);
extern void mmi_poc_hint_allow_subscribe(U16 index);
extern void mmi_poc_hint_subscribe_pres(U16 index);
extern void mmi_poc_entry_contact(void);
extern S32 mmi_poc_contact_get_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
extern S32 mmi_poc_contact_get_hints(S32 start_index, UI_string_type *hint_array);
extern void mmi_poc_util_copy_with_dot(S8 *source, S8 *dest, S32 max_len);
extern void mmi_poc_sort_contact_by_name(void);
extern void mmi_poc_check_and_update_contact(void);
extern void mmi_poc_contact_highlight_handler(S32 index);
extern void mmi_poc_entry_contact_opt(void);
extern void mmi_poc_entry_contact_opt_settings(void);
extern void mmi_poc_entry_contact_opt_settings_modify(void);
extern void mmi_poc_exit_contact_opt_settings_modify(void);
extern void mmi_poc_contact_fill_inline_struct(U8 op);
extern void mmi_poc_entry_contact_opt_settings_add(void);
extern void mmi_poc_exit_contact_opt_settings_add(void);
extern void mmi_poc_entry_contact_opt_settings_attributes(void);
extern void mmi_poc_go_back_contact_list(void);
extern void mmi_poc_entry_contact_opt_settings_attributes_allow_invite(void);
extern void mmi_poc_contact_set_allow_invite_accept(void);
extern void mmi_poc_contact_set_allow_invite_auto(void);
extern void mmi_poc_contact_set_allow_invite_reject(void);
extern void mmi_poc_contact_set_allow_subscribe(void);
extern void mmi_poc_entry_allow_subscribe(void);
extern void mmi_poc_entry_allow_subscribe_block(void);
extern void mmi_poc_entry_allow_subscribe_polite_block(void);
extern void mmi_poc_entry_allow_subscribe_allow(void);
extern void mmi_poc_contact_set_subscribe_pres(void);
extern void mmi_poc_entry_contact_opt_settings_attributes_provide_pres(void);
extern void mmi_poc_contact_set_pres_attr_cfrm(void);
extern void mmi_poc_contact_set_pres_attr(void);
extern void poc_go_back_entry_attr(void);
extern void mmi_poc_entry_contact_opt_settings_modify_cfrm(void);
extern void mmi_poc_contact_send_modify(void);
extern void mmi_poc_entry_contact_opt_settings_add_cfrm(void);
extern void mmi_poc_contact_send_add(void);
extern void mmi_poc_entry_progressing(void);
extern void mmi_poc_update_group_entry_req(U8 op);
extern void mmi_poc_update_group_entry_rsp(void *info);
extern void mmi_poc_update_subscribe_success_rsp(void *info);
extern void mmi_poc_update_subscribe_partial_success_rsp(void *info);
extern void mmi_poc_create_group_list_req(void);
extern void mmi_poc_create_group_list_rsp(void *info);
extern void mmi_poc_entry_update_subscribe_req(U8 op, U8 *uri);
extern void mmi_poc_entry_contact_opt_settings_delete_cfrm(void);
extern void mmi_poc_contact_send_delete(void);
extern void mmi_poc_del_group_entry_req(void);
extern void mmi_poc_del_group_entry_rsp(void *info);
extern void mmi_poc_entry_contact_opt_settings_info(void);
extern void mmi_poc_hint_entry_activity(U16 index);
extern void mmi_poc_hint_entry_mood(U16 index);
extern void mmi_poc_entry_contact_opt_send_alert(void);
extern void mmi_poc_send_personal_alert_req(void);
extern void mmi_poc_send_personal_alert_rsp(void *info);
extern void mmi_poc_entry_contact_opt_adhoc_talk(void);
extern void mmi_poc_contact_call_adhoc_cfrm(void);
extern void mmi_poc_contact_call_adhoc(void);
extern void poc_go_back_entry_opt(void);
extern void mmi_poc_contact_send_refresh_status(void);
extern void mmi_poc_oneshot_pres_subscribe_req(U8 *uri);
extern void mmi_poc_oneshot_pres_subscribe_rsp(void *info);
extern void mmi_poc_entry_talk_groups(void);
extern void mmi_poc_talk_group_highlight_handler(S32 index);
extern void mmi_poc_sort_talk_group_by_name(void);
extern void mmi_poc_entry_talk_groups_opt_empty(void);
extern void mmi_poc_entry_talk_groups_entry(void);
extern void mmi_poc_talk_group_entry_highlight_handler(S32 index);
extern void mmi_poc_entry_talk_groups_opt(void);
extern void mmi_poc_entry_talk_groups_opt_entry_settings(void);
extern void mmi_poc_entry_talk_groups_opt_entry_settings_add(void);
extern void mmi_poc_entry_talk_groups_opt_entry_settings_add_general(void);
extern void mmi_poc_exit_talk_groups_opt_entry_settings_add_general(void);
extern void mmi_poc_talk_entry_fill_inline_struct(U8 op);
extern void mmi_poc_entry_talk_groups_opt_entry_attr(void);
extern void mmi_poc_talk_group_set_conf_state(void);
extern void mmi_poc_talk_group_set_invite_user_dyna(void);
extern void mmi_poc_talk_group_set_join_handling(void);
extern void mmi_poc_talk_group_set_init_conf(void);
extern void mmi_poc_talk_group_set_anonymity(void);
extern void mmi_poc_talk_group_set_default_conf_state(void);
extern void mmi_poc_talk_group_set_default_invite_user_dyna(void);
extern void mmi_poc_talk_group_set_default_join_handling(void);
extern void mmi_poc_talk_group_set_default_init_conf(void);
extern void mmi_poc_talk_group_set_default_anonymity(void);
extern void mmi_poc_hint_talk_group_entry_conf_state(U16 index);
extern void mmi_poc_hint_talk_group_entry_invite_user_dyna(U16 index);
extern void mmi_poc_hint_talk_group_entry_join_handling(U16 index);
extern void mmi_poc_hint_talk_group_entry_init_conf(U16 index);
extern void mmi_poc_hint_talk_group_entry_anonymity(U16 index);
extern void mmi_poc_hint_talk_group_conf_state(U16 index);
extern void mmi_poc_hint_talk_group_invite_user_dyna(U16 index);
extern void mmi_poc_hint_talk_group_join_handling(U16 index);
extern void mmi_poc_hint_talk_group_init_conf(U16 index);
extern void mmi_poc_hint_talk_group_anonymity(U16 index);
extern void mmi_poc_entry_talk_group_opt_settings_add_cfrm(void);
extern void mmi_poc_talk_group_entry_send_add(void);
extern void mmi_poc_go_back_talk_group_entry_list(void);
extern void mmi_poc_go_back_talk_group_list(void);
extern void mmi_poc_update_talk_group_entry_req(U8 op);
extern void mmi_poc_update_talk_group_entry_rsp(void *info);
extern void mmi_poc_entry_talk_groups_opt_entry_settings_entry_info(void);
extern void mmi_poc_exit_talk_groups_opt_entry_settings_entry_info(void);
extern void mmi_poc_entry_talk_group_entry_info_cfrm(void);
extern void mmi_poc_talk_group_entry_send_modify(void);
extern void mmi_poc_entry_talk_groups_opt_entry_settings_add_from_contact(void);
extern void mmi_poc_talk_groups_add_from_contact_highlight_hdlr(S32 index);
extern pBOOL mmi_poc_add_talk_entry_contact_name(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
extern S32 mmi_poc_add_talk_entry_contact_uri(S32 item_index, UI_string_type *hint_array);
extern void mmi_poc_pass_contact_to_talk_entry(void);
extern void mmi_poc_talk_groups_opt_entry_delete_cfrm(void);
extern void mmi_poc_talk_group_entry_send_delete(void);
extern void mmi_poc_del_talk_group_entry_req(void);
extern void mmi_poc_del_talk_group_entry_rsp(void *info);
extern void mmi_poc_entry_talk_groups_opt_add_group(void);
extern void mmi_poc_exit_talk_groups_opt_add_group(void);
extern void mmi_poc_talk_group_fill_inline_struct(U8 op);
extern void mmi_poc_entry_talk_groups_opt_attr(void);

extern void mmi_poc_entry_talk_groups_opt_add_select_entry(void);
extern void mmi_poc_entry_talk_groups_opt_add_group_cfrm(void);
extern void poc_go_back_create_talk_group_add_contact(void);
extern void mmi_poc_create_talk_group_list_req(void);
extern void mmi_poc_create_talk_group_list_rsp(void *info);
extern void mmi_poc_entry_talk_group_opt_delete_cfrm(void);
extern void mmi_poc_talk_group_send_delete(void);
extern void mmi_poc_del_talk_group_req(void);
extern void mmi_poc_del_talk_group_rsp(void *info);
extern void mmi_poc_entry_talk_groups_opt_group_info(void);
extern void mmi_poc_exit_talk_groups_opt_group_info(void);
extern void mmi_poc_entry_talk_groups_opt_group_info_cfrm(void);
extern void mmi_poc_update_talk_group_param_req(void);
extern void mmi_poc_update_talk_group_param_rsp(void *info);
extern void mmi_poc_presence_notify_ind(void *info);
extern void mmi_poc_presence_notify_res(void);
extern void mmi_poc_entry_talk_groups_opt_call_others_group(void);
extern void mmi_poc_exit_talk_groups_opt_call_others_group(void);
extern void mmi_poc_call_others_group_fill_inline_struct(void);
extern void mmi_poc_entry_talk_groups_opt_call_others_group_cfrm(void);
extern void mmi_poc_call_others_group_req(void);

/* PoC CM functions */
extern void mmi_poc_highlight_cm_add_user(void);
extern void mmi_poc_highlight_cm_subscribe(void);
extern void mmi_poc_highlight_cm_unsubscribe(void);
extern void mmi_poc_highlight_cm_talk_group(void);
extern void mmi_poc_entry_status(void);
extern void mmi_poc_poweron_reg(void);
extern void mmi_poc_poweron_reg_wifi(void);
extern void mmi_poc_poweroff_dereg(void);
extern void mmi_poc_wps_query_req(void);
extern void mmi_poc_wps_query_rsp(void *info);
extern void mmi_poc_wps_ready_ind(void *info);
extern void mmi_poc_group_init_req(void);
extern void mmi_poc_group_init_rsp(void *info);
extern void mmi_poc_get_group_list_req(void);
extern void mmi_poc_get_group_list_rsp(void *info);
extern void mmi_poc_get_talk_group_list_req(void);
extern void mmi_poc_get_talk_group_list_rsp(void *info);
extern void mmi_poc_register_req(void);
extern void mmi_poc_register_rsp(void *info);
extern void mmi_poc_register_ind(void *info);
extern void mmi_poc_entry_registering(void);
extern void mmi_poc_reg_send_setting_req(void);
extern void mmi_poc_reg_send_setting_rsp(void *info);
extern void mmi_poc_reg_pres_subscribe_req(void);
extern void mmi_poc_reg_pres_subscribe_rsp(void *info);
extern void mmi_poc_reg_pres_publish_req(void);
extern void mmi_poc_reg_pres_publish_rsp(void *info);
extern void mmi_poc_dereg_pres_unsubscribe_req(void);
extern void mmi_poc_dereg_pres_unsubscribe_rsp(void *info);
extern void mmi_poc_dereg_pres_unpublish_req(void);
extern void mmi_poc_dereg_pres_unpublish_rsp(void *info);
extern void mmi_poc_deregister_req(void);
extern void mmi_poc_deregister_rsp(void *info);
extern void mmi_poc_group_deinit_req(void);
extern void mmi_poc_group_deinit_rsp(void *info);
extern void mmi_poc_contact_1_to_1_invite(void);
extern void mmi_poc_talk_group_invite(void);
extern void mmi_poc_talk_invite_req(
                U8 talk_type,
                U8 no_callee,
                poc_addr_struct *callee,
                U32 talk_id,
                U8 refer,
                U8 rejoin);
extern void mmi_poc_invite_rsp(void *info);
extern void mmi_poc_entry_inviting(void);
extern void mmi_poc_exit_release_ptt(void);
extern void mmi_poc_ptt_press(void);
extern void mmi_poc_ptt_release(void);
extern void mmi_poc_progress_ind(void *info);
extern void mmi_poc_entry_mo_ringing(void);
extern void mmi_poc_exit_mo_ringing(void);
extern void mmi_poc_disconnect_back(void);
extern void mmi_poc_disconnect_end(void);
extern void mmi_poc_talk_disconnect_req(void);
extern void mmi_poc_talk_disconnect_rsp(void *info);
extern void mmi_poc_connect_ind(void *info);
extern void mmi_poc_ring_ind(void *info);
extern void mmi_poc_start_mt_ringing(void);
extern void mmi_poc_stop_mt_ringing(void);
extern void mmi_poc_entry_mt_ringing(void);
extern void mmi_poc_exit_mt_ringing(void);
extern void mmi_poc_mt_ringing_yes(void);
extern void mmi_poc_mt_ringin_no(void);
extern void mmi_poc_mt_ringing_end(void);
extern void mmi_poc_entry_mt_ringing_answered(void);
extern void mmi_poc_exit_mt_ringing_answered(void);
extern void mmi_poc_talk_answer_req(U8 accept);
extern void mmi_poc_talk_answer_rsp(void *info);
extern void mmi_poc_disconnect_ind(void *info);
extern void mmi_poc_disconnect_callback(void);
extern void mmi_poc_entry_connected_idle(void);
extern void mmi_poc_exit_connected_idle(void);
extern void mmi_poc_entry_talk_options(void);
extern void mmi_poc_entry_cm_add_user(void);
extern void mmi_poc_entry_cm_add_user_cfrm(void);
extern void mmi_poc_cm_add_user_back(void);
extern void mmi_poc_cm_add_user(void);
extern void mmi_poc_in_call_invite_rsp(void *info);
extern void mmi_poc_floor_take_key(void);
extern void mmi_poc_floor_grant_ind(void *info);
extern void mmi_poc_floor_deny_ind(void *info);
extern void mmi_poc_floor_taken_ind(void *info);
extern void mmi_poc_floor_idle_ind(void *info);
extern void mmi_poc_floor_revoke_ind(void *info);
extern void mmi_poc_entry_revoke(void);
extern void mmi_poc_floor_take_req(void);
extern void mmi_poc_floor_release_req(void);
extern void mmi_poc_audio_encode_start(void);
extern void mmi_poc_audio_encode_stop(FuncPtr callback);
extern void mmi_poc_audio_decode_start(void);
extern void mmi_poc_audio_decode_stop(FuncPtr callback);
extern void mmi_poc_media_start_encode(void);
extern void mmi_poc_mdi_start_encode_callback(mdi_result result);
extern void mmi_poc_media_stop_encode(void);
extern void mmi_poc_media_start_decode(void);
extern void mmi_poc_mdi_start_decode_callback(mdi_result result);
extern void mmi_poc_media_stop_decode(void);
extern void mmi_poc_entry_talking(void);
extern void mmi_poc_exit_talking(void);
extern void mmi_poc_entry_media_processing(void);
extern void mmi_poc_talking_release_ptt(void);
extern void mmi_poc_entry_listening(void);
extern void mmi_poc_exit_listening(void);
extern void mmi_poc_reset_all_audio(void);
extern void mmi_poc_show_error_cause(kal_int32 result, kal_int32 cause);
extern void mmi_poc_enter_cm_key_light(void);
extern void mmi_poc_exit_cm_key_light(void);
extern void mmi_poc_remove_cm_screens(void);
extern void mmi_poc_talk_status_notify_ind(void *info);
extern void mmi_poc_talk_status_notify_res(void);
extern void mmi_poc_talk_status_subscribe(void);
extern void mmi_poc_talk_status_unsubscribe(void);
extern void mmi_poc_talk_status_subscribe_req(U8 subscribe);
extern void mmi_poc_talk_status_subscribe_rsp(void *info);
extern BOOL mmi_poc_mdi_background_handler(mdi_result result);
extern void mmi_poc_new_personal_alert_ind(void *info);
extern void mmi_poc_entry_personal_alert(void);
extern void mmi_poc_exit_personal_alert(void);
extern void mmi_poc_alert_ringing_view(void);
extern void mmi_poc_alert_ringing_back(void);
extern void mmi_poc_alert_ringing_end(void);
extern void mmi_poc_start_alert_ringing(void);
extern void mmi_poc_stop_alert_ringing(void);
extern U8 mmi_poc_cm_history_del_handler(void *in_param);

#ifdef __MMI_POC_ADHOC_STR_INPUT__
extern void mmi_poc_highlight_settings_adhoc_str(void);
extern void mmi_poc_entry_settings_adhoc_str(void);
extern void mmi_poc_set_adhoc_str(void);
#endif /* __MMI_POC_ADHOC_STR_INPUT__ */ 

extern void set_leading_zero(U8 u8type);

#endif /* _MMI_POC_PROT_H */ 

