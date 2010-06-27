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
 *  PoCMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements poc main functions
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *=============================================================
 *******************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_POC__

#ifndef __MTK_TARGET__
#include <Windows.h>
#endif
#include "MMI_include.h"
#include "mdi_datatype.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "CallSetup.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "DataAccountGProt.h"
#include "sip_msg_api.h"
#include "sip_ua_api.h"
#include "app2soc_struct.h"
#include "soc_api.h"
#include "app2sip_struct.h"
#include "app2xdm_struct.h"
#include "mmi2poc_struct.h"
#include "custom_poc_config.h"
#include "PoCGprot.h"
#include "PoCProt.h"
#include "CallhistoryEnum.h"
#include "DateTimeGprot.h"

mmi_poc_context_struct g_poc_cntx;  /* global context of poc */
mmi_poc_context_struct *g_poc_cntx_p = &g_poc_cntx;

#ifdef __MMI_POC_ADHOC_STR_INPUT__
U8 g_poc_adhoc_str_disp[POC_AD_HOC_STR_MAX_LEN * 2];
#endif 

const S8 g_poc_three_dot[] = { '.', '\0', '.', '\0', '.', '\0', '\0', '\0' };
const S8 g_poc_zero_ip[] = { '0', '\0', '0', '\0', '0', '\0', '\0', '\0' };     /* 000 */

U8 g_poc_app_id;
/*****************************************************************************
 * FUNCTION
 *  mmi_poc_init
 * DESCRIPTION
 *  Initialize PoC application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_init(void)
{
#if (0)
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
#endif /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_poc_cntx, 0, sizeof(g_poc_cntx));
    mmi_poc_init_highlight_hdlr();  /* init highlight handler */
    mmi_poc_init_protocol_hdlr();   /* init protocol event handler */
    poc_custom_set_conference_factory_uri(POC_AD_HOC_STR);

    g_poc_cntx_p->contact_list = custom_mmi_contact_list;
    g_poc_cntx_p->contact_list_disp = custom_mmi_contact_list_disp;
    g_poc_cntx_p->adhoc_sel_disp = custom_mmi_adhoc_sel_disp;
    g_poc_cntx_p->talk_group_list = custom_mmi_talk_group_list;
    g_poc_cntx_p->talk_group_disp.entries = custom_mmi_talk_group_entries;
    g_poc_app_id = always_ask_register_app_id(STR_ID_POC_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_init_highlight_hdlr
 * DESCRIPTION
 *  Initialize all highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_init_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* highlight handler */
    SetHiliteHandler(MENU_ID_POC_STATUS, mmi_poc_highlight_status);
    SetHiliteHandler(MENU_ID_POC_CONTACT, mmi_poc_highlight_contact);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT, mmi_poc_highlight_contact_opt);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS, mmi_poc_highlight_contact_opt_settings);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_MODIFY, mmi_poc_highlight_contact_opt_settings_modify);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_ADD, mmi_poc_highlight_contact_opt_settings_add);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_DELETE, mmi_poc_highlight_contact_opt_settings_delete);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_INFO, mmi_poc_highlight_contact_opt_settings_info);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_INVITE,
        mmi_poc_highlight_contact_opt_settings_attributes_allow_invite);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_INVITE_ACCEPT,
        mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_accept);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_INVITE_AUTO,
        mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_auto);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_INVITE_REJECT,
        mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_reject);

    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_SUBSCRIBE,
        mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_SUBSCRIBE_BLOCK,
        mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_block);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_SUBSCRIBE_POLITE_BLOCK,
        mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_polite_block);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_SUBSCRIBE_ALLOW,
        mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_allow);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_PROVIDE_PRES,
        mmi_poc_highlight_contact_opt_settings_attributes_provide_pres);
    SetHiliteHandler(
        MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_SUBSCRIBE_PRES,
        mmi_poc_highlight_contact_opt_settings_attributes_subscribe_pres);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT_SEND_ALERT, mmi_poc_highlight_contact_opt_send_alert);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT_ADHOC_TALK, mmi_poc_highlight_contact_opt_adhoc_talk);
    SetHiliteHandler(MENU_ID_POC_CONTACT_OPT_REFRESH_STATUS, mmi_poc_highlight_contact_opt_refresh_status);

    SetHiliteHandler(MENU_ID_POC_TALK_GROUPS, mmi_poc_highlight_talk_groups);
    SetHiliteHandler(MENU_ID_POC_TALK_GROUPS_OPT, mmi_poc_highlight_talk_groups_opt);
    SetHiliteHandler(MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS, mmi_poc_highlight_talk_groups_opt_entry_settings);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ADD,
        mmi_poc_highlight_talk_groups_opt_entry_settings_add);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ADD_FROM_CONTACT,
        mmi_poc_highlight_talk_groups_opt_entry_settings_add_from_contact);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_DELETE,
        mmi_poc_highlight_talk_groups_opt_entry_settings_delete);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_INFO,
        mmi_poc_highlight_talk_groups_opt_entry_settings_entry_info);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_CONF_STATE,
        mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_conf_state);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_INVITE_USER_DYNA,
        mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_invite_user_dyna);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_JOIN_HANDLING,
        mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_join_handling);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_INIT_CONF,
        mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_init_conf);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_ANONYMITY,
        mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_anonymity);
    SetHiliteHandler(MENU_ID_POC_TALK_GROUPS_OPT_ADD_GROUP, mmi_poc_highlight_talk_groups_opt_add_group);
    SetHiliteHandler(MENU_ID_POC_TALK_GROUPS_OPT_DELETE_GROUP, mmi_poc_highlight_talk_groups_opt_delete_group);
    SetHiliteHandler(MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO, mmi_poc_highlight_talk_groups_opt_group_info);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_CONF_STATE,
        mmi_poc_highlight_talk_groups_info_entry_attributes_conf_state);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_INVITE_USER_DYNA,
        mmi_poc_highlight_talk_groups_info_entry_attributes_invite_user_dyna);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_JOIN_HANDLING,
        mmi_poc_highlight_talk_groups_info_entry_attributes_join_handling);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_INIT_CONF,
        mmi_poc_highlight_talk_groups_info_entry_attributes_init_conf);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_ANONYMITY,
        mmi_poc_highlight_talk_groups_info_entry_attributes_anonymity);
    SetHiliteHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_CALL_OTHERS_GROUP,
        mmi_poc_highlight_talk_groups_opt_call_others_group);

    SetHiliteHandler(MENU_ID_POC_CALL_HISTORY, mmi_poc_highlight_call_history);
    SetHiliteHandler(MENU_ID_POC_CALL_HISTORY_INFO_VIEW, mmi_poc_highlight_call_history_info);
    SetHiliteHandler(MENU_ID_POC_CALL_HISTORY_INFO_OPTION_DELETE, mmi_poc_highlight_call_history_info_option_delete);
    SetHiliteHandler(
        MENU_ID_POC_CALL_HISTORY_INFO_OPTION_DELETE_ALL,
        mmi_poc_highlight_call_history_info_option_delete_all);
#ifdef __MMI_POC_ETS_TESTCODE__
    SetHiliteHandler(
        MENU_ID_POC_CALL_HISTORY_INFO_OPTION_SEND_FAKE_SESSION,
        mmi_poc_highlight_call_history_rejoin_fake);
#endif /* __MMI_POC_ETS_TESTCODE__ */ 
    SetHiliteHandler(MENU_ID_POC_SETTINGS, mmi_poc_highlight_settings);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_MY_STATUS, mmi_poc_highlight_settings_my_status);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_MY_STATUS_ACTIVITY, mmi_poc_highlight_settings_my_status_activity);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_MY_STATUS_MOOD, mmi_poc_highlight_settings_my_status_mood);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_ANS_MODE, mmi_poc_highlight_settings_ans_mode);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_CALL_BARRING, mmi_poc_highlight_settings_call_barring);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_ALERT_BARRING, mmi_poc_highlight_settings_alert_barring);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_MAO, mmi_poc_highlight_settings_mao);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_PRIVACY, mmi_poc_highlight_settings_privacy);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_PRIVACY_DISABLE, mmi_poc_highlight_settings_privacy_disable);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_PRIVACY_ENABLE, mmi_poc_highlight_settings_privacy_enable);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_START_AT_BOOTUP, mmi_poc_highlight_settings_start_at_bootup);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_USE_XDM, mmi_poc_highlight_settings_use_xdm);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_USE_PRES, mmi_poc_highlight_settings_use_pres);
#ifdef __MMI_POC_ADHOC_STR_INPUT__
    SetHiliteHandler(MENU_ID_POC_SETTINGS_ADHOC_STR, mmi_poc_highlight_settings_adhoc_str);
#endif 
    SetHiliteHandler(MENU_ID_POC_SETTINGS_PROFILES, mmi_poc_highlight_settings_profiles);
    SetHiliteHandler(
        MENU_ID_POC_SETTINGS_PROFILES_OPTION_ACTIVATE,
        mmi_poc_highlight_settings_profiles_option_activate);
    SetHiliteHandler(MENU_ID_POC_SETTINGS_PROFILES_OPTION_EDIT, mmi_poc_highlight_settings_profiles_option_edit);
    SetHiliteHandler(
        MENU_ID_POC_SETTINGS_PROFILES_OPTION_EDIT_POC,
        mmi_poc_highlight_settings_profiles_option_edit_poc);
    SetHiliteHandler(
        MENU_ID_POC_SETTINGS_PROFILES_OPTION_EDIT_CONN,
        mmi_poc_highlight_settings_profiles_option_edit_conn);

    SetHiliteHandler(MENU_ID_POC_CM_ADD_USER, mmi_poc_highlight_cm_add_user);
    SetHiliteHandler(MENU_ID_POC_CM_SUBSCRIBE, mmi_poc_highlight_cm_subscribe);
    SetHiliteHandler(MENU_ID_POC_CM_UNSUBSCRIBE, mmi_poc_highlight_cm_unsubscribe);
    SetHiliteHandler(MENU_ID_POC_CM_TALK_GROUP, mmi_poc_highlight_cm_talk_group);

    /* hint handler */
    SetHintHandler(MENU_ID_POC_STATUS, mmi_poc_hint_status);
    SetHintHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_INVITE, mmi_poc_hint_allow_invite);
    SetHintHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_SUBSCRIBE, mmi_poc_hint_allow_subscribe);
    SetHintHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_SUBSCRIBE_PRES, mmi_poc_hint_subscribe_pres);
    SetHintHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_INFO_ACTIVITY, mmi_poc_hint_entry_activity);
    SetHintHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_INFO_MOOD, mmi_poc_hint_entry_mood);

    SetHintHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_CONF_STATE,
        mmi_poc_hint_talk_group_entry_conf_state);
    SetHintHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_INVITE_USER_DYNA,
        mmi_poc_hint_talk_group_entry_invite_user_dyna);
    SetHintHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_JOIN_HANDLING,
        mmi_poc_hint_talk_group_entry_join_handling);
    SetHintHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_INIT_CONF,
        mmi_poc_hint_talk_group_entry_init_conf);
    SetHintHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES_ANONYMITY,
        mmi_poc_hint_talk_group_entry_anonymity);

    SetHintHandler(MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_CONF_STATE, mmi_poc_hint_talk_group_conf_state);
    SetHintHandler(
        MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_INVITE_USER_DYNA,
        mmi_poc_hint_talk_group_invite_user_dyna);
    SetHintHandler(MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_JOIN_HANDLING, mmi_poc_hint_talk_group_join_handling);
    SetHintHandler(MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_INIT_CONF, mmi_poc_hint_talk_group_init_conf);
    SetHintHandler(MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR_ANONYMITY, mmi_poc_hint_talk_group_anonymity);

    SetHintHandler(MENU_ID_POC_SETTINGS_MY_STATUS_ACTIVITY, mmi_poc_hint_my_activity);
    SetHintHandler(MENU_ID_POC_SETTINGS_MY_STATUS_MOOD, mmi_poc_hint_my_mood);
    SetHintHandler(MENU_ID_POC_SETTINGS_ANS_MODE, mmi_poc_hint_ans_mode);
    SetHintHandler(MENU_ID_POC_SETTINGS_CALL_BARRING, mmi_poc_hint_call_barring_mode);
    SetHintHandler(MENU_ID_POC_SETTINGS_ALERT_BARRING, mmi_poc_hint_alert_barring_mode);
    SetHintHandler(MENU_ID_POC_SETTINGS_MAO, mmi_poc_hint_mao_mode);

    SetHintHandler(MENU_ID_POC_SETTINGS_PRIVACY, mmi_poc_hint_privacy_mode);
    SetHintHandler(MENU_ID_POC_SETTINGS_START_AT_BOOTUP, mmi_poc_hint_boot_start);
    SetHintHandler(MENU_ID_POC_SETTINGS_USE_XDM, mmi_poc_hint_use_xdm);
    SetHintHandler(MENU_ID_POC_SETTINGS_USE_PRES, mmi_poc_hint_use_pres);
    SetHintHandler(MENU_ID_POC_SETTINGS_PROFILES, mmi_poc_hint_prof);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_init_protocol_hdlr
 * DESCRIPTION
 *  init all protocol handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_init_protocol_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_poc_register_ind, PRT_POC_REGISTER_IND);
    SetProtocolEventHandler(mmi_poc_progress_ind, PRT_POC_TALK_PROGRESS_IND);
    SetProtocolEventHandler(mmi_poc_connect_ind, PRT_POC_TALK_CONNECT_IND);
    SetProtocolEventHandler(mmi_poc_ring_ind, PRT_POC_TALK_RING_IND);
    SetProtocolEventHandler(mmi_poc_disconnect_ind, PRT_POC_TALK_DISCONNECT_IND);
    SetProtocolEventHandler(mmi_poc_floor_grant_ind, PRT_POC_FLOOR_GRANT_IND);
    SetProtocolEventHandler(mmi_poc_floor_deny_ind, PRT_POC_FLOOR_DENY_IND);
    SetProtocolEventHandler(mmi_poc_floor_taken_ind, PRT_POC_FLOOR_TAKEN_IND);
    SetProtocolEventHandler(mmi_poc_floor_revoke_ind, PRT_POC_FLOOR_REVOKE_IND);
    SetProtocolEventHandler(mmi_poc_floor_idle_ind, PRT_POC_FLOOR_IDLE_IND);

    SetProtocolEventHandler(mmi_poc_presence_notify_ind, MSG_ID_POC_PRESENCE_NOTIFY_IND);
    SetProtocolEventHandler(mmi_poc_talk_status_notify_ind, MSG_ID_POC_TALK_STATUS_NOTIFY_IND);
    SetProtocolEventHandler(mmi_poc_new_personal_alert_ind, MSG_ID_POC_NEW_PERSONAL_ALERT_IND);

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_main
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_main_pre, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_main_pre, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_status
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_status, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_call_history
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_call_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_call_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_call_history, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_call_history_info
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_call_history_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_call_history_info, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_call_history_info_option_delete
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_call_history_info_option_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_call_history_delete_cfrm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_call_history_info_option_delete_all
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_call_history_info_option_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_call_history_delete_all_cfrm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#ifdef __MMI_POC_ETS_TESTCODE__


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_call_history_rejoin_fake
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_call_history_rejoin_fake(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_call_history_rejoin_fake, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_POC_ETS_TESTCODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_my_status
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_my_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_my_status, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings_my_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_my_status_activity
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_my_status_activity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_my_status_activity, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings_my_status_activity, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_my_status_mood
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_my_status_mood(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_my_status_mood, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings_my_status_mood, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_ans_mode
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_ans_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_poc_switch_ans_mode, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_call_barring
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_call_barring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_call_bar_mode == MMI_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    SetLeftSoftkeyFunction(mmi_poc_switch_call_barring_mode, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_alert_barring
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_alert_barring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_alert_bar_mode == MMI_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    SetLeftSoftkeyFunction(mmi_poc_switch_alert_barring_mode, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_mao
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_mao(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_mao_mode == MMI_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    SetLeftSoftkeyFunction(mmi_poc_switch_mao_mode, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_privacy
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_privacy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_privacy, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings_privacy, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_privacy_disable
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_privacy_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_set_privacy_disable, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_privacy_enable
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_privacy_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_privacy_enable, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_start_at_bootup
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_start_at_bootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_boot_start_mode == MMI_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    SetLeftSoftkeyFunction(mmi_poc_set_start_at_bootup, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_use_xdm
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_use_xdm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    SetLeftSoftkeyFunction(mmi_poc_set_xdm_mode, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_use_pres
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_use_pres(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    SetLeftSoftkeyFunction(mmi_poc_set_pres_mode, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_POC_ADHOC_STR_INPUT__


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_adhoc_str
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_adhoc_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_adhoc_str, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_POC_ADHOC_STR_INPUT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_profiles
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_profiles, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings_profiles, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_profiles_option_activate
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_profiles_option_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_set_activate_profile, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_profiles_option_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_profiles_option_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_setting_prof_edit_pre, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_setting_prof_edit_pre, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_profiles_option_edit_poc
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_profiles_option_edit_poc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_profiles_option_edit_poc, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings_profiles_option_edit_poc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_settings_profiles_option_edit_conn
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_settings_profiles_option_edit_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_settings_profiles_option_edit_conn, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings_profiles_option_edit_conn, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_status
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_status(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (g_poc_cntx_p->curr_reg_state)
    {
        case POC_REG_NONE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_REG_REGED:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_REG_REGING:
        case POC_REG_DEREGING:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_PROCESSING));
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_my_activity
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_my_activity(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->person_pres.activity_present == MMI_TRUE)
    {
        switch (g_poc_cntx_p->person_pres.activity)
        {
            case POC_ACTIVITY_AWAY:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_AWAY));
                break;
            case POC_ACTIVITY_APPOINTMENT:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_APPOINTMENT));
                break;
            case POC_ACTIVITY_BUSY:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_BUSY));
                break;
            default:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
                break;
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_my_mood
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_my_mood(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->person_pres.mood_present == MMI_TRUE)
    {
        switch (g_poc_cntx_p->person_pres.mood)
        {
            case POC_MOOD_HAPPY:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_HAPPY));
                break;
            case POC_MOOD_BORED:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_BORED));
                break;
            case POC_MOOD_DEPRESSED:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_DEPRESSED));
                break;
            default:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
                break;
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_ans_mode
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_ans_mode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->curr_ans_mode == MMI_TRUE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_AUTO_ANS));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_MANUAL_ANS));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_call_barring_mode
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_call_barring_mode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->curr_call_bar_mode)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_alert_barring_mode
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_alert_barring_mode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->curr_alert_bar_mode)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_mao_mode
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_mao_mode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->curr_mao_mode)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_privacy_mode
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_privacy_mode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->curr_privacy_mode)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_boot_start
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_boot_start(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->curr_boot_start_mode)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_use_xdm
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_use_xdm(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->curr_use_xdm_mode)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_use_pres
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_use_pres(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_poc_cntx_p->curr_use_pres_mode)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_prof
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_prof(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_poc_profile_struct temp_profile;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    for (i = 0; i < POC_MAX_PROFILE_NUM; i++)
    {
        ReadRecord(NVRAM_EF_POC_PROFILE_LID, (U8) (i + 1), &temp_profile, NVRAM_MAX_POC_PROFILE_SIZE, &error);
        if (temp_profile.prof_name[0] == 0xFF)
        {
            memset(&g_poc_cntx_p->profile_list[i], 0, sizeof(g_poc_cntx_p->profile_list[i]));
            mmi_ucs2cpy(
                (PS8) g_poc_cntx_p->profile_list[i].prof_name,
                (PS8) GetString((U16) (STR_ID_POC_PROFILE_1 + i)));
        }
    }

    if (mmi_ucs2strlen((S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].prof_name) > 0)
    {
        memcpy(
            hintData[index],
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].prof_name,
            sizeof(g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].prof_name));
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) hintData[index],
            (PS8) GetString((U16) (STR_ID_POC_PROFILE_1 + g_poc_cntx_p->profile_active)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_main_pre
 * DESCRIPTION
 *  entry poc main
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_main_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_init_prof_setting_check(mmi_poc_entry_main);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_init_prof_setting_check
 * DESCRIPTION
 *  check for profile ready
 * PARAMETERS
 *  ready_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_init_prof_setting_check(FuncPtr ready_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 i;
    mmi_poc_profile_struct temp_profile;
    mmi_poc_history_struct temp_history;
    poc_addr_struct temp_privacy;
    static U8 prof_setting_ready = 0;
    U8 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof_setting_ready == 0)
    {
        /* Initiate History */
        ReadRecord(NVRAM_EF_POC_HISTORY_LID, 1, &temp_history, NVRAM_MAX_POC_HISTORY_SIZE, &error);
        if (temp_history.no_entries == 0xFF)
        {
            memset(&g_poc_cntx_p->history, 0, sizeof(g_poc_cntx_p->history));
        }
        else
        {
            memcpy(&g_poc_cntx_p->history, &temp_history, sizeof(g_poc_cntx_p->history));
        }

        /* Initiate Profile */
        for (i = 0; i < POC_MAX_PROFILE_NUM; i++)
        {
            ReadRecord(NVRAM_EF_POC_PROFILE_LID, (U8) (i + 1), &temp_profile, NVRAM_MAX_POC_PROFILE_SIZE, &error);
            if (temp_profile.prof_name[0] == 0xFF)
            {
                memset(&g_poc_cntx_p->profile_list[i], 0, sizeof(g_poc_cntx_p->profile_list[i]));
                g_poc_cntx_p->profile_list[i].data_account = CUSTOM_DEFAULT_POC_DTCNT_ID;/* mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI);*/
                mmi_ucs2cpy(
                    (PS8) g_poc_cntx_p->profile_list[i].prof_name,
                    (PS8) GetString((U16) (STR_ID_POC_PROFILE_1 + i)));
            }
            else
            {
                if (mmi_ucs2strlen((S8*) temp_profile.prof_name) > 0)
                {
                    memcpy(
                        g_poc_cntx_p->profile_list[i].prof_name,
                        temp_profile.prof_name,
                        sizeof(temp_profile.prof_name));
                }
                else
                {
                    mmi_ucs2cpy(
                        (PS8) g_poc_cntx_p->profile_list[i].prof_name,
                        (PS8) GetString((U16) (STR_ID_POC_PROFILE_1 + i)));
                }
                memcpy(g_poc_cntx_p->profile_list[i].disp_name, temp_profile.disp_name, sizeof(temp_profile.disp_name));
                g_poc_cntx_p->profile_list[i].disp_charset = temp_profile.disp_charset;
                memcpy(g_poc_cntx_p->profile_list[i].uri, temp_profile.uri, sizeof(temp_profile.uri));
                memcpy(g_poc_cntx_p->profile_list[i].password, temp_profile.password, sizeof(temp_profile.password));
                memcpy(g_poc_cntx_p->profile_list[i].poc_addr, temp_profile.poc_addr, sizeof(temp_profile.poc_addr));
                g_poc_cntx_p->profile_list[i].poc_port = temp_profile.poc_port;
                memcpy(g_poc_cntx_p->profile_list[i].xdm_addr, temp_profile.xdm_addr, sizeof(temp_profile.xdm_addr));
                g_poc_cntx_p->profile_list[i].data_account = temp_profile.data_account;
                g_poc_cntx_p->profile_list[i].use_proxy = temp_profile.use_proxy;
                memcpy(
                    g_poc_cntx_p->profile_list[i].proxy_username,
                    temp_profile.proxy_username,
                    sizeof(temp_profile.proxy_username));
                memcpy(
                    g_poc_cntx_p->profile_list[i].proxy_password,
                    temp_profile.proxy_password,
                    sizeof(temp_profile.proxy_password));
                memcpy(g_poc_cntx_p->profile_list[i].proxy_ip, temp_profile.proxy_ip, sizeof(temp_profile.proxy_ip));
                g_poc_cntx_p->profile_list[i].proxy_port = temp_profile.proxy_port;
                g_poc_cntx_p->profile_list[i].proxy_port = temp_profile.proxy_port;
                g_poc_cntx_p->profile_list[i].data_account = temp_profile.data_account;
            }
        }

        memset(&g_poc_cntx_p->person_pres, 0, sizeof(mmi_poc_person_pinfo_struct));
        ReadValue(NVRAM_POC_ACTIVITY_PRESENT, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_ACTIVITY_PRESENT, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->person_pres.activity_present = data;
        ReadValue(NVRAM_POC_ACTIVITY, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_ACTIVITY, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->person_pres.activity = data;
        ReadValue(NVRAM_POC_MOOD_PRESENT, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_MOOD_PRESENT, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->person_pres.mood_present = data;
        ReadValue(NVRAM_POC_MOOD, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_MOOD, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->person_pres.mood = data;

        ReadValue(NVRAM_POC_ANS_MODE, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 1;
            WriteValue(NVRAM_POC_ANS_MODE, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->curr_ans_mode = data;

        ReadValue(NVRAM_POC_CALL_BAR_MODE, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_CALL_BAR_MODE, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->curr_call_bar_mode = data;

        ReadValue(NVRAM_POC_ALERT_BAR_MODE, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_ALERT_BAR_MODE, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->curr_alert_bar_mode = data;

        ReadValue(NVRAM_POC_MAO_MODE, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_MAO_MODE, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->curr_mao_mode = data;

        ReadValue(NVRAM_POC_PRIVACY_MODE, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_PRIVACY_MODE, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->curr_privacy_mode = data;

        ReadRecord(NVRAM_EF_POC_PRIVACY_LID, 1, &temp_privacy, NVRAM_MAX_POC_PRIVACY_SIZE, &error);
        if (((U8) temp_privacy.disp_name[0]) == 0xFF)
        {
            memset(&g_poc_cntx_p->privacy_addr, 0, sizeof(g_poc_cntx_p->privacy_addr));
        }
        else
        {
            memcpy(&g_poc_cntx_p->privacy_addr, &temp_privacy, sizeof(g_poc_cntx_p->privacy_addr));
        }

        ReadValue(NVRAM_POC_START_BOOTUP, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_START_BOOTUP, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->curr_boot_start_mode = data;

        ReadValue(NVRAM_POC_USE_XDM, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 1;
            WriteValue(NVRAM_POC_USE_XDM, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->curr_use_xdm_mode = data;

        ReadValue(NVRAM_POC_USE_PRES, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 1;
            WriteValue(NVRAM_POC_USE_PRES, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->curr_use_pres_mode = data;

        ReadValue(NVRAM_POC_PROFILE_ACTIVE, &data, DS_BYTE, &error);
        if (data == 0xFF)
        {
            data = 0;
            WriteValue(NVRAM_POC_PROFILE_ACTIVE, &data, DS_BYTE, &error);
        }
        g_poc_cntx_p->profile_active = data;

        prof_setting_ready = 1;
    }
    if (ready_callback != NULL)
    {
        ready_callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_main
 * DESCRIPTION
 *  poc main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 *PoCHint[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_ON_WIN32
    PopupNoSupport();
    return;
#endif /* MMI_ON_WIN32 */ 

    EntryNewScreen(SCR_ID_POC_MAIN, NULL, mmi_poc_entry_main, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_MAIN);

    if (g_poc_cntx_p->curr_reg_state == POC_REG_REGED)
    {
        nNumofItem = GetNumOfChild(MENU_ID_POC_MAIN_REGOK);
        GetSequenceStringIds(MENU_ID_POC_MAIN_REGOK, nStrItemList);
        SetParentHandler(MENU_ID_POC_MAIN_REGOK);
        ConstructHintsList(MENU_ID_POC_MAIN_REGOK, PoCHint);
    }
    else
    {
        nNumofItem = GetNumOfChild(MENU_ID_POC_MAIN);
        GetSequenceStringIds(MENU_ID_POC_MAIN, nStrItemList);
        SetParentHandler(MENU_ID_POC_MAIN);
        ConstructHintsList(MENU_ID_POC_MAIN, PoCHint);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        PoCHint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_call_history
 * DESCRIPTION
 *  poc call history screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_call_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Cat23DemoIcons[POC_MAX_HISTORY_NUM];
    U8 *guiBuffer;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->history.no_entries == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    EntryNewScreen(STR_ID_POC_CALL_HISTORY, NULL, mmi_poc_entry_call_history, NULL);

    guiBuffer = GetCurrGuiBuffer(STR_ID_POC_CALL_HISTORY);

    RegisterHighlightHandler(mmi_poc_history_highlight_handler);

    for (count = 0; count < g_poc_cntx_p->history.no_entries; count++)
    {
        switch (g_poc_cntx_p->history.entries[count].type)
        {
            case POC_INCOMING_CALL:
                Cat23DemoIcons[count] = IMG_MENU8101_RECEIVED_CALLS;
                break;
            case POC_INCOMING_ALERT:
                Cat23DemoIcons[count] = IMG_MENU8101_RECEIVED_CALLS;
                break;
            case POC_OUTGOING_CALL:
                Cat23DemoIcons[count] = IMG_MENU8102_DIALED_CALLS;
                break;
            case POC_OUTGOING_ALERT:
                Cat23DemoIcons[count] = IMG_MENU8102_DIALED_CALLS;
                break;
            default:
                break;
        }

        subMenuDataPtrs[count] = subMenuData[count];
        hintDataPtrs[count] = hintData[count];

        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        memset((S8*) hintDataPtrs[count], 0, MAX_SUB_MENU_HINT_SIZE);

        if (strlen((S8*) g_poc_cntx_p->history.entries[count].list_name) == 0)
        {
            mmi_poc_util_copy_with_dot(
                (S8*) g_poc_cntx_p->history.entries[count].uri,
                (S8*) subMenuDataPtrs[count],
                MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_poc_util_copy_with_dot(
                (S8*) g_poc_cntx_p->history.entries[count].list_name,
                (S8*) subMenuDataPtrs[count],
                MAX_SUBMENU_CHARACTERS - 1);
        }
        mmi_poc_util_copy_with_dot(
            (S8*) g_poc_cntx_p->history.entries[count].uri,
            (S8*) hintDataPtrs[count],
            MAX_SUBMENU_CHARACTERS - 1);
    }

    ShowCategory53Screen(
        STR_ID_POC_CALL_HISTORY,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_poc_cntx_p->history.no_entries,
        subMenuDataPtrs,
        (U16*) Cat23DemoIcons,
        hintDataPtrs,
        0,
        0,
        guiBuffer);

    if (g_poc_cntx_p->curr_reg_state == POC_REG_REGED)
    {
        SetKeyHandler(mmi_poc_call_history_rejoin, KEY_SEND, KEY_EVENT_DOWN);
    }
    SetKeyHandler(mmi_poc_entry_call_history_info_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_poc_entry_call_history_info_option, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_history_highlight_handler
 * DESCRIPTION
 *  poc history highlight handler
 * PARAMETERS
 *  ind     [IN]        Currently selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_history_highlight_handler(S32 ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->call_history_selected = (U8) ind;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_call_history_rejoin
 * DESCRIPTION
 *  call rejoin from history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_call_history_rejoin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_addr_struct callee;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    memcpy(
        callee.uri,
        g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].uri,
        sizeof(U8) * POC_MAX_URI_LEN);
    memcpy(
        callee.disp_name,
        g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].list_name,
        sizeof(U8) * POC_MAX_DISP_LEN);
    callee.disp_charset = 0;

    memset(g_poc_cntx_p->cm_talk_group_name, 0, sizeof(g_poc_cntx_p->cm_talk_group_name));
    if (strlen((S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].list_name))
    {
        strncpy(
            (S8*) g_poc_cntx_p->cm_talk_group_name,
            (S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].list_name,
            POC_MAX_DISP_LEN - 1);
    }
    else
    {
        strncpy(
            (S8*) g_poc_cntx_p->cm_talk_group_name,
            (S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].uri,
            POC_MAX_DISP_LEN - 1);
    }

    memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
    g_poc_cntx_p->cm_talk_list_num = 0;
    strncpy((S8*) g_poc_cntx_p->calling_disp.name, (S8*) callee.disp_name, POC_MAX_DISP_LEN - 1);
    strncpy((S8*) g_poc_cntx_p->calling_disp.uri, (S8*) callee.uri, POC_MAX_URI_LEN - 1);

    mmi_poc_entry_inviting();
    if (g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].rejoinable == MMI_TRUE)
    {
        mmi_poc_talk_invite_req(POC_AD_HOC_GROUP_TALK, 1, &callee, 0, 0, 1);
    }
    else
    {
        mmi_poc_talk_invite_req(POC_AD_HOC_GROUP_TALK, 1, &callee, 0, 0, 0);
    }
}

#ifdef __MMI_POC_ETS_TESTCODE__


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_call_history_rejoin_fake
 * DESCRIPTION
 *  call a fake rejoin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_call_history_rejoin_fake(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_addr_struct callee;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    strncpy((S8*) callee.uri, POC_MMI_DEFAULT_PRIVACY_ADDR, POC_MAX_URI_LEN - 1);
    strncpy((S8*) callee.disp_name, POC_MMI_DEFAULT_PRIVACY_ADDR, POC_MAX_DISP_LEN - 1);

    callee.disp_charset = 0;

    memset(g_poc_cntx_p->cm_talk_group_name, 0, sizeof(g_poc_cntx_p->cm_talk_group_name));
    if (strlen((S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].list_name))
    {
        strncpy(
            (S8*) g_poc_cntx_p->cm_talk_group_name,
            (S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].list_name,
            POC_MAX_DISP_LEN - 1);
    }
    else
    {
        strncpy(
            (S8*) g_poc_cntx_p->cm_talk_group_name,
            (S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].uri,
            POC_MAX_DISP_LEN - 1);
    }

    memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
    g_poc_cntx_p->cm_talk_list_num = 0;
    strncpy((S8*) g_poc_cntx_p->calling_disp.name, (S8*) callee.disp_name, POC_MAX_DISP_LEN - 1);
    strncpy((S8*) g_poc_cntx_p->calling_disp.uri, (S8*) callee.uri, POC_MAX_URI_LEN - 1);

    mmi_poc_entry_inviting();
    mmi_poc_talk_invite_req(POC_AD_HOC_GROUP_TALK, 1, &callee, 0, 0, 0);
}

#endif /* __MMI_POC_ETS_TESTCODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_call_history_info
 * DESCRIPTION
 *  history info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_call_history_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    U16 icon_list[] = 
    {
        IMG_ID_POC_DATE, IMG_ID_POC_TIME, IMG_ID_POC_CONTACT_NAME,
        0, IMG_ID_POC_CONTACT_URI, 0, IMG_ID_POC_MSG, 0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_STATUS);

    EntryNewScreen(SCR_ID_POC_HISTORY_INFO, mmi_poc_exit_call_history_info, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_HISTORY_INFO);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_HISTORY_INFO, &inputBufferSize);

    SetParentHandler(0);

    mmi_poc_history_fill_inline_struct();

    date_string(
        &g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].time,
        (UI_string_type) g_poc_cntx_p->history_disp.date,
        DT_IDLE_SCREEN);

    time_string(
        &g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].time,
        (UI_string_type) g_poc_cntx_p->history_disp.time,
        DT_IDLE_SCREEN);

    mmi_poc_util_copy_with_dot(
        (S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].list_name,
        (S8*) g_poc_cntx_p->history_disp.list_name,
        POC_MAX_DISP_LEN - 1);

    mmi_poc_util_copy_with_dot(
        (S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].uri,
        (S8*) g_poc_cntx_p->history_disp.uri,
        POC_MAX_URI_LEN - 1);

    mmi_poc_util_copy_with_dot(
        (S8*) g_poc_cntx_p->history.entries[g_poc_cntx_p->call_history_selected].message,
        (S8*) g_poc_cntx_p->history_disp.message,
        MMI_POC_MAX_MSG_LEN - 1);

    ShowCategory57Screen(
        STR_ID_POC_CALL_HISTORY,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_HISTORY_INFO_INLINE_NUM,
        icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_call_history_info_option, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_call_history_info
 * DESCRIPTION
 *  Exit function of View screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_call_history_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_POC_HISTORY_INFO, mmi_poc_entry_call_history_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_history_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure for poc history info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_history_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation((wgui_inline_items + POC_HISTORY_INFO_DATE), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_HISTORY_INFO_TIME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_HISTORY_INFO_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_HISTORY_INFO_URI), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_HISTORY_INFO_MSG), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemDisplayOnly((wgui_inline_items + POC_HISTORY_INFO_DATE), (U8*) g_poc_cntx_p->history_disp.date);
    SetInlineItemDisplayOnly((wgui_inline_items + POC_HISTORY_INFO_TIME), (U8*) g_poc_cntx_p->history_disp.time);
    SetInlineItemCaption((wgui_inline_items + POC_HISTORY_INFO_NAME_STR), (U8*) GetString(STR_ID_POC_NAME));
    SetInlineItemDisplayOnly((wgui_inline_items + POC_HISTORY_INFO_NAME), (U8*) g_poc_cntx_p->history_disp.list_name);
    SetInlineItemCaption((wgui_inline_items + POC_HISTORY_INFO_URI_STR), (U8*) GetString(STR_ID_POC_URI));
    SetInlineItemDisplayOnly((wgui_inline_items + POC_HISTORY_INFO_URI), (U8*) g_poc_cntx_p->history_disp.uri);
    SetInlineItemCaption((wgui_inline_items + POC_HISTORY_INFO_MSG_STR), (U8*) GetString(STR_ID_POC_MESSAGE));
    SetInlineItemDisplayOnly((wgui_inline_items + POC_HISTORY_INFO_MSG), (U8*) g_poc_cntx_p->history_disp.message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_call_history_info_option
 * DESCRIPTION
 *  history info option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_call_history_info_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_HISTORY_OPT, NULL, mmi_poc_entry_call_history_info_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_HISTORY_OPT);
    menuId = MENU_ID_POC_CALL_HISTORY_INFO_OPTION;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_call_history_delete_cfrm
 * DESCRIPTION
 *  delete confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_call_history_delete_cfrm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_poc_history_delete_nvram, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_history_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_history_delete_nvram
 * DESCRIPTION
 *  delete history from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_history_delete_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = g_poc_cntx_p->call_history_selected; i < g_poc_cntx_p->history.no_entries - 1; i++)
    {
        memcpy(
            &g_poc_cntx_p->history.entries[i],
            &g_poc_cntx_p->history.entries[i + 1],
            sizeof(mmi_poc_history_entry_struct));
    }
    memset(
        &g_poc_cntx_p->history.entries[g_poc_cntx_p->history.no_entries - 1],
        (U8) 0,
        sizeof(mmi_poc_history_entry_struct));

    if (g_poc_cntx_p->history.no_entries > 0)
    {
        g_poc_cntx_p->history.no_entries--;
    }

    if (WriteRecord(
            NVRAM_EF_POC_HISTORY_LID,
            1,
            &g_poc_cntx.history,
            NVRAM_MAX_POC_HISTORY_SIZE,
            &error) < NVRAM_MAX_POC_HISTORY_SIZE)
    {
        ASSERT(0);
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteUptoScrID(STR_ID_POC_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_go_back_history_list
 * DESCRIPTION
 *  go back history list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_go_back_history_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(STR_ID_POC_CALL_HISTORY);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_call_history_delete_all_cfrm
 * DESCRIPTION
 *  delete all confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_call_history_delete_all_cfrm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DELETE_ALL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_poc_history_delete_all_nvram, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_history_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_history_delete_all_nvram
 * DESCRIPTION
 *  delete all from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_history_delete_all_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_poc_cntx_p->history, (U8) 0, sizeof(mmi_poc_history_struct));

    if (WriteRecord(
            NVRAM_EF_POC_HISTORY_LID,
            1,
            &g_poc_cntx.history,
            NVRAM_MAX_POC_HISTORY_SIZE,
            &error) < NVRAM_MAX_POC_HISTORY_SIZE)
    {
        ASSERT(0);
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteUptoScrID(STR_ID_POC_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_history_add
 * DESCRIPTION
 *  add history interface
 * PARAMETERS
 *  type            [IN]        
 *  rejoinable      [IN]        
 *  list_name       [?]         
 *  uri             [?]         
 *  message         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_history_add(U8 type, U8 rejoinable, U8 *list_name, U8 *uri, U8 *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, curr_total;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (message != NULL)
    {
        if (!strlen((S8*) uri) && !strlen((S8*) message) && (type != POC_INCOMING_ALERT))
        {
            return;
        }
    }

    for (i = POC_MAX_HISTORY_NUM - 1; i > 0; i--)
    {
        memcpy(
            &g_poc_cntx_p->history.entries[i],
            &g_poc_cntx_p->history.entries[i - 1],
            sizeof(mmi_poc_history_entry_struct));
    }
    memset(&g_poc_cntx_p->history.entries[0], 0, sizeof(mmi_poc_history_entry_struct));
    strncpy((S8*) g_poc_cntx_p->history.entries[0].list_name, (S8*) list_name, POC_MAX_DISP_LEN - 1);
    strncpy((S8*) g_poc_cntx_p->history.entries[0].uri, (S8*) uri, POC_MAX_URI_LEN - 1);

    if (message == NULL)
    {
        memset(g_poc_cntx_p->history.entries[0].message, 0, sizeof(g_poc_cntx_p->history.entries[0].message));
    }
    else
    {
        strncpy((S8*) g_poc_cntx_p->history.entries[0].message, (S8*) message, MMI_POC_MAX_MSG_LEN - 1);
    }
    DTGetRTCTime(&g_poc_cntx_p->history.entries[0].time);
    g_poc_cntx_p->history.entries[0].type = type;
    g_poc_cntx_p->history.entries[0].rejoinable = rejoinable;

    if (g_poc_cntx_p->history.no_entries < POC_MAX_HISTORY_NUM)
    {
        g_poc_cntx_p->history.no_entries++;
    }

    curr_total = g_poc_cntx_p->history.no_entries;

    for (i = 1; i < curr_total; i++)
    {
        if ((g_poc_cntx_p->history.entries[i].type == type) &&
            (!strncmp((S8*) g_poc_cntx_p->history.entries[i].list_name, (S8*) list_name, POC_MAX_DISP_LEN - 1)) &&
            (!strncmp((S8*) g_poc_cntx_p->history.entries[i].uri, (S8*) uri, POC_MAX_URI_LEN - 1) || uri[0] == 0 ||
             uri == 0) && (message == NULL))
        {
            for (j = i; j < curr_total - 1; j++)
            {
                memcpy(
                    &g_poc_cntx_p->history.entries[j],
                    &g_poc_cntx_p->history.entries[j + 1],
                    sizeof(mmi_poc_history_entry_struct));
            }
            ASSERT(g_poc_cntx_p->history.no_entries > 0);
            g_poc_cntx_p->history.no_entries--;
        }
    }

    for (i = g_poc_cntx_p->history.no_entries; i < POC_MAX_HISTORY_NUM; i++)
    {
        memset(&g_poc_cntx_p->history.entries[i], 0, sizeof(mmi_poc_history_entry_struct));
    }

    if (WriteRecord(
            NVRAM_EF_POC_HISTORY_LID,
            1,
            &g_poc_cntx.history,
            NVRAM_MAX_POC_HISTORY_SIZE,
            &error) < NVRAM_MAX_POC_HISTORY_SIZE)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings
 * DESCRIPTION
 *  poc settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 *PoCHint[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING, NULL, mmi_poc_entry_settings, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING);

    if (g_poc_cntx_p->curr_reg_state == POC_REG_REGED)
    {
        nNumofItem = GetNumOfChild(MENU_ID_POC_SETTINGS);
        GetSequenceStringIds(MENU_ID_POC_SETTINGS, nStrItemList);
        SetParentHandler(MENU_ID_POC_SETTINGS);
        ConstructHintsList(MENU_ID_POC_SETTINGS, PoCHint);
    }
    else
    {
        nNumofItem = GetNumOfChild(MENU_ID_POC_SETTINGS_NOREG);
        GetSequenceStringIds(MENU_ID_POC_SETTINGS_NOREG, nStrItemList);
        SetParentHandler(MENU_ID_POC_SETTINGS_NOREG);
        ConstructHintsList(MENU_ID_POC_SETTINGS_NOREG, PoCHint);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_POC_POC_SETTINGS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        PoCHint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_my_status
 * DESCRIPTION
 *  settings my status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_my_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 *PoCHint[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->progressing.my_status == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
    if (g_poc_cntx_p->curr_reg_state != POC_REG_REGED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_POC_SETTING_MYSTATUS, NULL, mmi_poc_entry_settings_my_status, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_MYSTATUS);

    nNumofItem = GetNumOfChild(MENU_ID_POC_SETTINGS_MY_STATUS);
    GetSequenceStringIds(MENU_ID_POC_SETTINGS_MY_STATUS, nStrItemList);
    SetParentHandler(MENU_ID_POC_SETTINGS_MY_STATUS);
    ConstructHintsList(MENU_ID_POC_SETTINGS_MY_STATUS, PoCHint);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_POC_MY_STATUS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        PoCHint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_my_status_activity
 * DESCRIPTION
 *  activity screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_my_status_activity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING_MYSTATUS_ACTIVITY, NULL, mmi_poc_entry_settings_my_status_activity, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_MYSTATUS_ACTIVITY);

    nNumofItem = POC_MAX_ACTIVITY_NUM;

    SetParentHandler(MENU_ID_POC_SETTINGS_MY_STATUS_ACTIVITY);

    RegisterHighlightHandler(mmi_poc_activity_highlight_handler);

    GetSequenceStringIds(MENU_ID_POC_SETTINGS_MY_STATUS_ACTIVITY, nStrItemList);

    nStrItemList[0] = STR_GLOBAL_EMPTY;

    for (i = 1; i < nNumofItem; i++)
    {
        nStrItemList[i] = STR_ID_POC_AWAY + i - 1;
    }

    if (guiBuffer == NULL)
    {
        g_poc_cntx_p->activity_selected = 0;
    }

    ShowCategory52Screen(
        STR_ID_POC_ACTIVITY,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        g_poc_cntx_p->activity_selected,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_poc_entry_set_activity, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_activity_highlight_handler
 * DESCRIPTION
 *  activity highlight handler
 * PARAMETERS
 *  index       [IN]        Currently selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_activity_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->activity_selected = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_set_activity
 * DESCRIPTION
 *  set activity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_set_activity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&g_poc_cntx_p->person_pres_disp, &g_poc_cntx_p->person_pres, sizeof(mmi_poc_person_pinfo_struct));

    switch (g_poc_cntx_p->activity_selected)
    {
        case 0:
            g_poc_cntx_p->person_pres_disp.activity_present = MMI_FALSE;
            break;
        case 1:
            g_poc_cntx_p->person_pres_disp.activity_present = MMI_TRUE;
            g_poc_cntx_p->person_pres_disp.activity = POC_ACTIVITY_AWAY;
            break;
        case 2:
            g_poc_cntx_p->person_pres_disp.activity_present = MMI_TRUE;
            g_poc_cntx_p->person_pres_disp.activity = POC_ACTIVITY_APPOINTMENT;
            break;
        case 3:
            g_poc_cntx_p->person_pres_disp.activity_present = MMI_TRUE;
            g_poc_cntx_p->person_pres_disp.activity = POC_ACTIVITY_BUSY;
            break;
        default:
            break;
    }

    mmi_poc_entry_progressing();
    DeleteUptoScrID(SCR_ID_POC_SETTING);
    mmi_poc_presence_publish_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_presence_publish_req
 * DESCRIPTION
 *  presence publish request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_presence_publish_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_publish_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->progressing.my_status = MMI_TRUE;

    myMsgPtr = (poc_presence_publish_req_struct*) OslConstructDataPtr(sizeof(poc_presence_publish_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_presence_publish_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->remove = MMI_FALSE;

    memcpy(
        myMsgPtr->pinfo.entity,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].uri,
        POC_MAX_URI_LEN * sizeof(U8));
    myMsgPtr->pinfo.is_active = MMI_TRUE;

    myMsgPtr->pinfo.person.activity_present = g_poc_cntx_p->person_pres_disp.activity_present;
    myMsgPtr->pinfo.person.activity = g_poc_cntx_p->person_pres_disp.activity;
    myMsgPtr->pinfo.person.mood_present = g_poc_cntx_p->person_pres_disp.mood_present;
    myMsgPtr->pinfo.person.mood = g_poc_cntx_p->person_pres_disp.mood;

    myMsgPtr->pinfo.num_service = 0;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_PRESENCE_PUBLISH_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_presence_publish_rsp, MSG_ID_POC_PRESENCE_PUBLISH_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_presence_publish_rsp
 * DESCRIPTION
 *  presence publish response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_presence_publish_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_presence_publish_rsp_struct *msgRsp;
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_publish_rsp_struct*) info;
    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_PUBLISH_RSP);

    g_poc_cntx_p->progressing.my_status = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        g_poc_cntx_p->person_pres.activity_present = g_poc_cntx_p->person_pres_disp.activity_present;
        g_poc_cntx_p->person_pres.activity = g_poc_cntx_p->person_pres_disp.activity;
        g_poc_cntx_p->person_pres.mood_present = g_poc_cntx_p->person_pres_disp.mood_present;
        g_poc_cntx_p->person_pres.mood = g_poc_cntx_p->person_pres_disp.mood;

        data = g_poc_cntx_p->person_pres.activity_present;
        WriteValue(NVRAM_POC_ACTIVITY_PRESENT, &data, DS_BYTE, &error);
        data = g_poc_cntx_p->person_pres.activity;
        WriteValue(NVRAM_POC_ACTIVITY, &data, DS_BYTE, &error);
        data = g_poc_cntx_p->person_pres.mood_present;
        WriteValue(NVRAM_POC_MOOD_PRESENT, &data, DS_BYTE, &error);
        data = g_poc_cntx_p->person_pres.mood;
        WriteValue(NVRAM_POC_MOOD, &data, DS_BYTE, &error);

    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_my_status_mood
 * DESCRIPTION
 *  mood screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_my_status_mood(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING_MYSTATUS_MOOD, NULL, mmi_poc_entry_settings_my_status_mood, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_MYSTATUS_MOOD);

    nNumofItem = POC_MAX_MOOD_NUM;

    SetParentHandler(MENU_ID_POC_SETTINGS_MY_STATUS_MOOD);

    RegisterHighlightHandler(mmi_poc_mood_highlight_handler);

    nStrItemList[0] = STR_GLOBAL_EMPTY;

    for (i = 1; i < nNumofItem; i++)
    {
        nStrItemList[i] = STR_ID_POC_HAPPY + i - 1;
    }

    if (guiBuffer == NULL)
    {
        g_poc_cntx_p->mood_selected = 0;
    }

    ShowCategory52Screen(
        STR_ID_POC_MOOD,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        g_poc_cntx_p->mood_selected,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_poc_entry_set_mood, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_mood_highlight_handler
 * DESCRIPTION
 *  mood screen highlight handler
 * PARAMETERS
 *  index       [IN]        Currently selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_mood_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->mood_selected = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_set_mood
 * DESCRIPTION
 *  set mood
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_set_mood(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&g_poc_cntx_p->person_pres_disp, &g_poc_cntx_p->person_pres, sizeof(mmi_poc_person_pinfo_struct));

    switch (g_poc_cntx_p->mood_selected)
    {
        case 0:
            g_poc_cntx_p->person_pres_disp.mood_present = MMI_FALSE;
            break;
        case 1:
            g_poc_cntx_p->person_pres_disp.mood_present = MMI_TRUE;
            g_poc_cntx_p->person_pres_disp.mood = POC_MOOD_HAPPY;
            break;
        case 2:
            g_poc_cntx_p->person_pres_disp.mood_present = MMI_TRUE;
            g_poc_cntx_p->person_pres_disp.mood = POC_MOOD_BORED;
            break;
        case 3:
            g_poc_cntx_p->person_pres_disp.mood_present = MMI_TRUE;
            g_poc_cntx_p->person_pres_disp.mood = POC_MOOD_DEPRESSED;
            break;
        default:
            break;
    }
    mmi_poc_entry_progressing();
    DeleteUptoScrID(SCR_ID_POC_SETTING);
    mmi_poc_presence_publish_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_ans_mode
 * DESCRIPTION
 *  switch answer mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_ans_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_REGED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    if (g_poc_cntx_p->progressing.poc_settings == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    mmi_poc_entry_progressing();
    mmi_poc_switch_ans_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_ans_mode_req
 * DESCRIPTION
 *  switch answer mode request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_ans_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_setting_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_setting_req_struct*) OslConstructDataPtr(sizeof(poc_setting_req_struct));

    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_setting_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    g_poc_cntx_p->progressing.poc_settings = MMI_TRUE;

    if (g_poc_cntx_p->curr_ans_mode == MMI_TRUE)
    {
        myMsgPtr->data.auto_answer = MMI_FALSE;
    }
    else
    {
        myMsgPtr->data.auto_answer = MMI_TRUE;
    }
    myMsgPtr->data.isb = g_poc_cntx_p->curr_call_bar_mode;
    myMsgPtr->data.ipab = g_poc_cntx_p->curr_alert_bar_mode;
    myMsgPtr->data.enable_mao = g_poc_cntx_p->curr_mao_mode;
    myMsgPtr->data.enable_privacy = g_poc_cntx_p->curr_privacy_mode;
    memcpy(&myMsgPtr->data.privacy_addr, &g_poc_cntx_p->privacy_addr, sizeof(poc_addr_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_SETTING_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_switch_ans_mode_rsp, PRT_POC_SETTING_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_ans_mode_rsp
 * DESCRIPTION
 *  switch ans mode response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_ans_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    poc_setting_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_setting_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_SETTING_RSP);

    g_poc_cntx_p->progressing.poc_settings = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if ((GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING) || (GetActiveScreenId() == SCR_ID_POC_SETTING))
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        if (g_poc_cntx_p->curr_ans_mode == MMI_TRUE)
        {
            g_poc_cntx_p->curr_ans_mode = MMI_FALSE;
        }
        else
        {
            g_poc_cntx_p->curr_ans_mode = MMI_TRUE;
        }

        data = g_poc_cntx_p->curr_ans_mode;
        WriteValue(NVRAM_POC_ANS_MODE, &data, DS_BYTE, &error);
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_call_barring_mode
 * DESCRIPTION
 *  switch call barring mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_call_barring_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_REGED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    if (g_poc_cntx_p->progressing.poc_settings == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    mmi_poc_entry_progressing();
    mmi_poc_switch_call_barring_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_call_barring_mode_req
 * DESCRIPTION
 *  switch call barring mode request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_call_barring_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_setting_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_setting_req_struct*) OslConstructDataPtr(sizeof(poc_setting_req_struct));

    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_setting_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    g_poc_cntx_p->progressing.poc_settings = MMI_TRUE;

    myMsgPtr->data.auto_answer = g_poc_cntx_p->curr_ans_mode;

    if (g_poc_cntx_p->curr_call_bar_mode == MMI_TRUE)
    {
        myMsgPtr->data.isb = MMI_FALSE;
    }
    else
    {
        myMsgPtr->data.isb = MMI_TRUE;
    }
    myMsgPtr->data.ipab = g_poc_cntx_p->curr_alert_bar_mode;
    myMsgPtr->data.enable_mao = g_poc_cntx_p->curr_mao_mode;
    myMsgPtr->data.enable_privacy = g_poc_cntx_p->curr_privacy_mode;
    memcpy(&myMsgPtr->data.privacy_addr, &g_poc_cntx_p->privacy_addr, sizeof(poc_addr_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_SETTING_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_switch_call_barring_mode_rsp, PRT_POC_SETTING_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_call_barring_mode_rsp
 * DESCRIPTION
 *  switch call barring mode response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_call_barring_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    poc_setting_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_setting_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_SETTING_RSP);

    g_poc_cntx_p->progressing.poc_settings = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if ((GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING) || (GetActiveScreenId() == SCR_ID_POC_SETTING))
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        if (g_poc_cntx_p->curr_call_bar_mode == MMI_TRUE)
        {
            g_poc_cntx_p->curr_call_bar_mode = MMI_FALSE;
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        }
        else
        {
            g_poc_cntx_p->curr_call_bar_mode = MMI_TRUE;
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        }

        data = g_poc_cntx_p->curr_call_bar_mode;
        WriteValue(NVRAM_POC_CALL_BAR_MODE, &data, DS_BYTE, &error);
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_alert_barring_mode
 * DESCRIPTION
 *  switch alert barring mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_alert_barring_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_REGED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    if (g_poc_cntx_p->progressing.poc_settings == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    mmi_poc_entry_progressing();
    mmi_poc_switch_alert_barring_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_mao_mode
 * DESCRIPTION
 *  switch mao mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_mao_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_REGED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    if (g_poc_cntx_p->progressing.poc_settings == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    mmi_poc_entry_progressing();
    mmi_poc_switch_mao_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_alert_barring_mode_req
 * DESCRIPTION
 *  switch alert barring mode request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_alert_barring_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_setting_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_setting_req_struct*) OslConstructDataPtr(sizeof(poc_setting_req_struct));

    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_setting_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    g_poc_cntx_p->progressing.poc_settings = MMI_TRUE;

    myMsgPtr->data.auto_answer = g_poc_cntx_p->curr_ans_mode;
    myMsgPtr->data.isb = g_poc_cntx_p->curr_call_bar_mode;

    if (g_poc_cntx_p->curr_alert_bar_mode == MMI_TRUE)
    {
        myMsgPtr->data.ipab = MMI_FALSE;
    }
    else
    {
        myMsgPtr->data.ipab = MMI_TRUE;
    }
    myMsgPtr->data.enable_mao = g_poc_cntx_p->curr_mao_mode;
    myMsgPtr->data.enable_privacy = g_poc_cntx_p->curr_privacy_mode;
    memcpy(&myMsgPtr->data.privacy_addr, &g_poc_cntx_p->privacy_addr, sizeof(poc_addr_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_SETTING_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_switch_alert_barring_mode_rsp, PRT_POC_SETTING_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_mao_mode_req
 * DESCRIPTION
 *  switch mao mode request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_mao_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_setting_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_setting_req_struct*) OslConstructDataPtr(sizeof(poc_setting_req_struct));

    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_setting_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    g_poc_cntx_p->progressing.poc_settings = MMI_TRUE;

    myMsgPtr->data.auto_answer = g_poc_cntx_p->curr_ans_mode;
    myMsgPtr->data.isb = g_poc_cntx_p->curr_call_bar_mode;
    myMsgPtr->data.ipab = g_poc_cntx_p->curr_alert_bar_mode;

    if (g_poc_cntx_p->curr_mao_mode == MMI_TRUE)
    {
        myMsgPtr->data.enable_mao = MMI_FALSE;
    }
    else
    {
        myMsgPtr->data.enable_mao = MMI_TRUE;
    }
    myMsgPtr->data.enable_privacy = g_poc_cntx_p->curr_privacy_mode;
    memcpy(&myMsgPtr->data.privacy_addr, &g_poc_cntx_p->privacy_addr, sizeof(poc_addr_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_SETTING_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_switch_mao_mode_rsp, PRT_POC_SETTING_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_alert_barring_mode_rsp
 * DESCRIPTION
 *  switch alert barring mode response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_alert_barring_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    poc_setting_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_setting_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_SETTING_RSP);

    g_poc_cntx_p->progressing.poc_settings = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if ((GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING) || (GetActiveScreenId() == SCR_ID_POC_SETTING))
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        if (g_poc_cntx_p->curr_alert_bar_mode == MMI_TRUE)
        {
            g_poc_cntx_p->curr_alert_bar_mode = MMI_FALSE;
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        }
        else
        {
            g_poc_cntx_p->curr_alert_bar_mode = MMI_TRUE;
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        }
        
        data = g_poc_cntx_p->curr_alert_bar_mode;
        WriteValue(NVRAM_POC_ALERT_BAR_MODE, &data, DS_BYTE, &error);
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_switch_mao_mode_rsp
 * DESCRIPTION
 *  switch mao mode response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_switch_mao_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    poc_setting_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_setting_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_SETTING_RSP);

    g_poc_cntx_p->progressing.poc_settings = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if ((GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING) || (GetActiveScreenId() == SCR_ID_POC_SETTING))
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        if (g_poc_cntx_p->curr_mao_mode == MMI_TRUE)
        {
            g_poc_cntx_p->curr_mao_mode = MMI_FALSE;
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        }
        else
        {
            g_poc_cntx_p->curr_mao_mode = MMI_TRUE;
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        }

        data = g_poc_cntx_p->curr_mao_mode;
        WriteValue(NVRAM_POC_MAO_MODE, &data, DS_BYTE, &error);
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_privacy
 * DESCRIPTION
 *  privacy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_privacy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_REGED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    if (g_poc_cntx_p->progressing.poc_settings == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_POC_SETTING_PRIVACY, NULL, mmi_poc_entry_settings_privacy, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_PRIVACY);
    menuId = MENU_ID_POC_SETTINGS_PRIVACY;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_ID_POC_PRIVACY,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_privacy_disable
 * DESCRIPTION
 *  set privacy disable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_privacy_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_REGED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(STR_ID_POC_SETTINGS);
        return;
    }
    if (g_poc_cntx_p->progressing.poc_settings == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        DeleteUptoScrID(STR_ID_POC_SETTINGS);
        return;
    }
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        DeleteUptoScrID(STR_ID_POC_SETTINGS);
        return;
    }

    mmi_poc_entry_progressing();
    DeleteScreenIfPresent(SCR_ID_POC_SETTING_PRIVACY);
    mmi_poc_set_privacy_disable_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_privacy_disable_req
 * DESCRIPTION
 *  set privacy disable request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_privacy_disable_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_setting_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_setting_req_struct*) OslConstructDataPtr(sizeof(poc_setting_req_struct));

    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_setting_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    g_poc_cntx_p->progressing.poc_settings = MMI_TRUE;

    myMsgPtr->data.auto_answer = g_poc_cntx_p->curr_ans_mode;
    myMsgPtr->data.isb = g_poc_cntx_p->curr_call_bar_mode;
    myMsgPtr->data.ipab = g_poc_cntx_p->curr_alert_bar_mode;
    myMsgPtr->data.enable_mao = g_poc_cntx_p->curr_mao_mode;
    myMsgPtr->data.enable_privacy = MMI_FALSE;
    memcpy(&myMsgPtr->data.privacy_addr, &g_poc_cntx_p->privacy_addr, sizeof(poc_addr_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_SETTING_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_set_privacy_disable_rsp, PRT_POC_SETTING_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_privacy_disable_rsp
 * DESCRIPTION
 *  set privacy disable response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_privacy_disable_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    poc_setting_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_setting_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_SETTING_RSP);

    g_poc_cntx_p->progressing.poc_settings = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if ((GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING) || (GetActiveScreenId() == SCR_ID_POC_SETTING))
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        g_poc_cntx_p->curr_privacy_mode = MMI_FALSE;

        data = g_poc_cntx_p->curr_privacy_mode;
        WriteValue(NVRAM_POC_PRIVACY_MODE, &data, DS_BYTE, &error);
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_privacy_enable
 * DESCRIPTION
 *  privacy enable screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_privacy_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_REGED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(STR_ID_POC_SETTINGS);
        return;
    }
    if (g_poc_cntx_p->progressing.poc_settings == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        DeleteUptoScrID(STR_ID_POC_SETTINGS);
        return;
    }
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        DeleteUptoScrID(STR_ID_POC_SETTINGS);
        return;
    }

    EntryNewScreen(SCR_ID_POC_SETTING_PRIVACY_ADDR, NULL, mmi_poc_entry_settings_privacy_enable, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_PRIVACY_ADDR);

    if (guiBuffer == NULL)
    {
        memset(g_poc_cntx_p->privacy_addr_disp, 0, sizeof(g_poc_cntx_p->privacy_addr_disp));
        if (strlen((S8*) g_poc_cntx_p->privacy_addr.uri) == 0)
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->privacy_addr_disp,
                (S8*) POC_MMI_DEFAULT_PRIVACY_ADDR,
                POC_MAX_URI_LEN - 1);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->privacy_addr_disp,
                (S8*) g_poc_cntx_p->privacy_addr.uri,
                POC_MAX_URI_LEN - 1);
        }
    }

    RegisterInputBoxValidationFunction(mmi_poc_privacy_addr_msg_key);
    ShowCategory5Screen(
        STR_ID_POC_PRIVACY_ADDR,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        (U8*) g_poc_cntx_p->privacy_addr_disp,
        POC_MAX_URI_LEN,
        guiBuffer);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_poc_set_privacy_enable_req, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_LONG_PRESS);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_LONG_PRESS);

    if (mmi_ucs2strlen((S8*) g_poc_cntx_p->privacy_addr_disp) == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_privacy_addr_msg_key
 * DESCRIPTION
 *  privacy address message key
 * PARAMETERS
 *  text        [?]         
 *  cursor      [?]         
 *  length      [IN]        
 *  Framework parameters, don't care.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_privacy_addr_msg_key(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the validity of the input password */
    if ((length) < 1)
    {
        /* if length is short then disable lsk */
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        /* if its valid length then enable lsk */
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_privacy_enable_req
 * DESCRIPTION
 *  set privacy enable request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_privacy_enable_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_setting_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_setting_req_struct*) OslConstructDataPtr(sizeof(poc_setting_req_struct));

    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_setting_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    mmi_poc_entry_progressing();
    DeleteScreenIfPresent(SCR_ID_POC_SETTING_PRIVACY);
    DeleteScreenIfPresent(SCR_ID_POC_SETTING_PRIVACY_ADDR);

    g_poc_cntx_p->progressing.poc_settings = MMI_TRUE;

    myMsgPtr->data.auto_answer = g_poc_cntx_p->curr_ans_mode;
    myMsgPtr->data.isb = g_poc_cntx_p->curr_call_bar_mode;
    myMsgPtr->data.ipab = g_poc_cntx_p->curr_alert_bar_mode;
    myMsgPtr->data.enable_mao = g_poc_cntx_p->curr_mao_mode;
    myMsgPtr->data.enable_privacy = MMI_TRUE;
    memset(&myMsgPtr->data.privacy_addr, 0, sizeof(myMsgPtr->data.privacy_addr));
    mmi_ucs2_n_to_asc(
        (S8*) myMsgPtr->data.privacy_addr.uri,
        (S8*) g_poc_cntx_p->privacy_addr_disp,
        POC_MAX_URI_LEN - 1);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_SETTING_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_set_privacy_enable_rsp, PRT_POC_SETTING_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_privacy_enable_rsp
 * DESCRIPTION
 *  set privacy enable response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_privacy_enable_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    poc_setting_rsp_struct *msgRsp;
    poc_addr_struct temp_privacy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_setting_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_SETTING_RSP);

    g_poc_cntx_p->progressing.poc_settings = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if ((GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING) || (GetActiveScreenId() == SCR_ID_POC_SETTING))
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
        memset(g_poc_cntx_p->privacy_addr.uri, 0, sizeof(g_poc_cntx_p->privacy_addr.uri));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->privacy_addr.uri,
            (S8*) g_poc_cntx_p->privacy_addr_disp,
            POC_MAX_URI_LEN - 1);

        g_poc_cntx_p->curr_privacy_mode = MMI_TRUE;
        data = g_poc_cntx_p->curr_privacy_mode;
        WriteValue(NVRAM_POC_PRIVACY_MODE, &data, DS_BYTE, &error);

        memset(&temp_privacy, 0, sizeof(poc_addr_struct));
        memcpy(temp_privacy.uri, g_poc_cntx_p->privacy_addr.uri, sizeof(temp_privacy.uri));

        WriteRecord(NVRAM_EF_POC_PRIVACY_LID, 1, &temp_privacy, NVRAM_MAX_POC_PRIVACY_SIZE, &error);

    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_start_at_bootup
 * DESCRIPTION
 *  set start at bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_start_at_bootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_boot_start_mode == MMI_TRUE)
    {
        g_poc_cntx_p->curr_boot_start_mode = MMI_FALSE;
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        g_poc_cntx_p->curr_boot_start_mode = MMI_TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }

    data = g_poc_cntx_p->curr_boot_start_mode;
    WriteValue(NVRAM_POC_START_BOOTUP, &data, DS_BYTE, &error);
    
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_xdm_mode
 * DESCRIPTION
 *  set xdm mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_xdm_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_NONE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_DEREGISTER_FIRST),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }

    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        g_poc_cntx_p->curr_use_xdm_mode = MMI_FALSE;
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        g_poc_cntx_p->curr_use_xdm_mode = MMI_TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }

    data = g_poc_cntx_p->curr_use_xdm_mode;
    WriteValue(NVRAM_POC_USE_XDM, &data, DS_BYTE, &error);
    
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_pres_mode
 * DESCRIPTION
 *  set presence mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_pres_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_NONE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_DEREGISTER_FIRST),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }

    if (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE)
    {
        g_poc_cntx_p->curr_use_pres_mode = MMI_FALSE;
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        g_poc_cntx_p->curr_use_pres_mode = MMI_TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }

    data = g_poc_cntx_p->curr_use_pres_mode;
    WriteValue(NVRAM_POC_USE_PRES, &data, DS_BYTE, &error);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
}

#ifdef __MMI_POC_ADHOC_STR_INPUT__


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_adhoc_str
 * DESCRIPTION
 *  adhoc string screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_adhoc_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING_ADHOC_STR, NULL, mmi_poc_entry_settings_adhoc_str, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_ADHOC_STR);

    if (guiBuffer == NULL)
    {
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_adhoc_str_disp,
            (S8*) poc_custom_get_conference_factory_uri(),
            POC_AD_HOC_STR_MAX_LEN - 1);
    }

    RegisterInputBoxValidationFunction(mmi_poc_privacy_addr_msg_key);
    ShowCategory5Screen(
        STR_ID_POC_ADHOC_STR,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        (U8*) g_poc_adhoc_str_disp,
        POC_AD_HOC_STR_MAX_LEN - 1,
        guiBuffer);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_poc_set_adhoc_str, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_LONG_PRESS);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_LONG_PRESS);

    if (mmi_ucs2strlen((S8*) g_poc_adhoc_str_disp) == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_adhoc_str
 * DESCRIPTION
 *  set adhoc string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_adhoc_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_buf[POC_AD_HOC_STR_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_POC_SETTING_ADHOC_STR);

    memset(temp_buf, 0, sizeof(temp_buf));
    mmi_ucs2_to_asc((S8*) temp_buf, (S8*) g_poc_adhoc_str_disp);

    poc_custom_set_conference_factory_uri((kal_char*) temp_buf);
}

#endif /* __MMI_POC_ADHOC_STR_INPUT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_profiles
 * DESCRIPTION
 *  setting profiles screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 i;
    U16 icon_list[POC_MAX_PROFILE_NUM];
    U8 *nStrItemList[POC_MAX_PROFILE_NUM];
    mmi_poc_profile_struct temp_profile;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING_PROF, NULL, mmi_poc_entry_settings_profiles, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_PROF);

    RegisterHighlightHandler(mmi_poc_profile_highlight_handler);

    memset(icon_list, 0, sizeof(icon_list));
    icon_list[g_poc_cntx_p->profile_active] = IMG_ID_POC_PROFILE_SELECTED;

    for (i = 0; i < POC_MAX_PROFILE_NUM; i++)
    {
        ReadRecord(NVRAM_EF_POC_PROFILE_LID, (U8) (i + 1), &temp_profile, NVRAM_MAX_POC_PROFILE_SIZE, &error);
        if (temp_profile.prof_name[0] == 0xFF)
        {
            memset(&g_poc_cntx_p->profile_list[i], 0, sizeof(g_poc_cntx_p->profile_list[i]));
            g_poc_cntx_p->profile_list[i].data_account = CUSTOM_DEFAULT_POC_DTCNT_ID; /*mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI);*/
            mmi_ucs2cpy(
                (PS8) g_poc_cntx_p->profile_list[i].prof_name,
                (PS8) GetString((U16) (STR_ID_POC_PROFILE_1 + i)));
        }
    }

    for (i = 0; i < POC_MAX_PROFILE_NUM; i++)
    {
        if (mmi_ucs2strlen((S8*) g_poc_cntx_p->profile_list[i].prof_name) > 0)
        {
            nStrItemList[i] = g_poc_cntx_p->profile_list[i].prof_name;
        }
        else
        {
            nStrItemList[i] = (U8*) GetString((U16) (STR_ID_POC_PROFILE_1 + i));
        }
    }

    ShowCategory84Screen(
        STR_ID_POC_PROFILES,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_MAX_PROFILE_NUM,
        (U8 **) nStrItemList,
        icon_list,
        1,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_poc_entry_settings_profiles_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_settings_profiles_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_profile_highlight_handler
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  index       [IN]        Currently selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_profile_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->profile_selected = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_profiles_opt
 * DESCRIPTION
 *  profiles option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_profiles_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING_PROF_OPT, NULL, mmi_poc_entry_settings_profiles_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_PROF_OPT);

    nNumofItem = GetNumOfChild(MENU_ID_POC_SETTINGS_PROFILES_OPTION);

    GetSequenceStringIds(MENU_ID_POC_SETTINGS_PROFILES_OPTION, nStrItemList);

    SetParentHandler(MENU_ID_POC_SETTINGS_PROFILES_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_set_activate_profile
 * DESCRIPTION
 *  set active profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_set_activate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state != POC_REG_NONE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_DEREGISTER_FIRST),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }

    if (g_poc_cntx_p->profile_active != (U8) g_poc_cntx_p->profile_selected)
    {
        data = (U8) g_poc_cntx_p->profile_selected;
        WriteValue(NVRAM_POC_PROFILE_ACTIVE, &data, DS_BYTE, &error);
        g_poc_cntx_p->profile_active = (U8) g_poc_cntx_p->profile_selected;
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_ACTIVATED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_POC_SETTING_PROF_OPT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_setting_prof_edit_pre
 * DESCRIPTION
 *  profile edit pre-handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_setting_prof_edit_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    DataAccountReadyCheck(mmi_poc_entry_settings_profiles_edit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_profiles_edit
 * DESCRIPTION
 *  profile edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_profiles_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 *PoCHint[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING_PROF_OPT_EDIT, NULL, mmi_poc_entry_settings_profiles_edit, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_PROF_OPT_EDIT);

    nNumofItem = GetNumOfChild(MENU_ID_POC_SETTINGS_PROFILES_OPTION_EDIT);

    GetSequenceStringIds(MENU_ID_POC_SETTINGS_PROFILES_OPTION_EDIT, nStrItemList);

    SetParentHandler(MENU_ID_POC_SETTINGS_PROFILES_OPTION_EDIT);

    ConstructHintsList(MENU_ID_POC_SETTINGS_PROFILES_OPTION_EDIT, PoCHint);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        PoCHint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_profiles_option_edit_poc
 * DESCRIPTION
 *  edit poc screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_profiles_option_edit_poc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ImageLocation = 0;
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;
    U16 IconList[POC_PROFILE_POC_INLINE_NUM];
    U8 tempPortBuf[POC_MAX_PROFILE_PORT_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING_PROF_OPT_EDIT_POC, mmi_poc_exit_settings_profiles_option_edit_poc, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_PROF_OPT_EDIT_POC);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_SETTING_PROF_OPT_EDIT_POC, &inputBufferSize);
    SetParentHandler(0);

    if (inputBuffer == NULL)
    {
        memcpy(
            g_poc_cntx_p->profile_disp.prof_name,
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].prof_name,
            POC_MAX_PROF_NAME_LEN);
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->profile_disp.disp_name,
            (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].disp_name,
            POC_MAX_DISP_LEN - 1);
        if (strlen((S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].uri))
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->profile_disp.uri,
                (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].uri,
                POC_MAX_URI_LEN - 1);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->profile_disp.uri,
                (S8*) POC_MMI_SIP_PREFIX,
                POC_MAX_URI_LEN - 1);
        }
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->profile_disp.password,
            (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].password,
            POC_MAX_PASSWORD_LEN - 1);
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->profile_disp.poc_addr,
            (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].poc_addr,
            POC_PROXY_ADDR_LEN - 1);
        if (g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].poc_port == 0)
        {
            sprintf((char*)tempPortBuf, "");
        }
        else
        {
            sprintf((char*)tempPortBuf, "%d", g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].poc_port);
        }
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->profile_disp.poc_port,
            (S8*) tempPortBuf,
            POC_MAX_PROFILE_PORT_LEN - 1);
        if (strlen((S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].xdm_addr))
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->profile_disp.xdm_addr,
                (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].xdm_addr,
                POC_PROXY_ADDR_LEN - 1);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->profile_disp.xdm_addr,
                (S8*) POC_MMI_HTTP_PREFIX,
                POC_PROXY_ADDR_LEN - 1);
        }
    }

    mmi_poc_profile_fill_inline_struct();

    if (inputBuffer != NULL)
    {
        U8 tmp_profile_port_disp[POC_MAX_PROFILE_PORT_LEN * ENCODING_LENGTH];

        memcpy(tmp_profile_port_disp, g_poc_cntx_p->profile_disp.poc_port, sizeof(tmp_profile_port_disp));
        SetCategory57Data(wgui_inline_items, POC_PROFILE_POC_INLINE_NUM, inputBuffer);
        memcpy(g_poc_cntx_p->profile_disp.poc_port, tmp_profile_port_disp, sizeof(g_poc_cntx_p->profile_disp.poc_port));
    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    for (i = 0; i < POC_PROFILE_POC_INLINE_NUM; i++)
    {
        if (i % 2)
        {
            IconList[i] = IMG_ID_POC_NOIMAGE;
        }
        else
        {
            IconList[i] = IMG_ID_POC_PROFILE_NAME + ImageLocation;
            ImageLocation++;
        }
    }

    ShowCategory57Screen(
        STR_ID_POC_POC_SETTINGS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_PROFILE_POC_INLINE_NUM,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_profile_edit_cfrm, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_settings_profiles_option_edit_poc
 * DESCRIPTION
 *  exit function for edit poc screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_settings_profiles_option_edit_poc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_SETTING_PROF_OPT_EDIT_POC, mmi_poc_entry_settings_profiles_option_edit_poc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_profile_edit_cfrm
 * DESCRIPTION
 *  edit confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_profile_edit_cfrm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_poc_profile_edit_nvram, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_profile, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_go_back_profile
 * DESCRIPTION
 *  go back profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_go_back_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteUptoScrID(SCR_ID_POC_SETTING_PROF_OPT_EDIT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_profile_fill_inline_struct
 * DESCRIPTION
 *  fill profile inline structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_profile_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(FALSE);

    SetInlineItemActivation((wgui_inline_items + POC_PROFILE_POC_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_PROFILE_POC_DISP_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_PROFILE_POC_URI), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_PROFILE_POC_PASS), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_PROFILE_POC_SERVERADDR), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(
        (wgui_inline_items + POC_PROFILE_POC_SERVERPORT),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemActivation((wgui_inline_items + POC_PROFILE_POC_XDMADDR), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemCaption((wgui_inline_items + POC_PROFILE_POC_NAME_STR), (U8*) GetString(STR_ID_POC_PROFILE_NAME));
    SetInlineItemCaption((wgui_inline_items + POC_PROFILE_POC_DISP_NAME_STR), (U8*) GetString(STR_ID_POC_NAME));
    SetInlineItemCaption((wgui_inline_items + POC_PROFILE_POC_URI_STR), (U8*) GetString(STR_ID_POC_URI));
    SetInlineItemCaption((wgui_inline_items + POC_PROFILE_POC_PASS_STR), (U8*) GetString(STR_ID_POC_PASSWORD));
    SetInlineItemCaption(
        (wgui_inline_items + POC_PROFILE_POC_SERVERADDR_STR),
        (U8*) GetString(STR_ID_POC_SERVER_ADDR));
    SetInlineItemCaption(
        (wgui_inline_items + POC_PROFILE_POC_SERVERPORT_STR),
        (U8*) GetString(STR_ID_POC_SERVER_PORT));
    SetInlineItemCaption((wgui_inline_items + POC_PROFILE_POC_XDMADDR_STR), (U8*) GetString(STR_ID_POC_XDM_ADDR));

    BufferSize = POC_MAX_PROF_NAME_LEN / 2;

    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_PROFILE_POC_NAME),
        STR_ID_POC_PROFILE_NAME,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->profile_disp.prof_name),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_PROFILE_POC_NAME, mmi_poc_entry_full_line_edit);

    BufferSize = POC_MAX_DISP_LEN / 2;
    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_PROFILE_POC_DISP_NAME),
        STR_ID_POC_NAME,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->profile_disp.disp_name),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_PROFILE_POC_DISP_NAME, mmi_poc_entry_full_line_edit);

    /* BufferSize = POC_MAX_URI_LEN ; */
    BufferSize = POC_MAX_INLINE_ADDR_LEN;

    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_PROFILE_POC_URI),
        STR_ID_POC_URI,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->profile_disp.uri),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_PROFILE_POC_URI, mmi_poc_entry_full_line_edit);

    BufferSize = POC_MAX_PASSWORD_LEN;

    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_PROFILE_POC_PASS),
        STR_ID_POC_PASSWORD,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->profile_disp.password),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_PROFILE_POC_PASS, mmi_poc_entry_full_line_edit);

    /* BufferSize = POC_PROXY_ADDR_LEN ; */
    BufferSize = POC_MAX_INLINE_ADDR_LEN;

    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_PROFILE_POC_SERVERADDR),
        STR_ID_POC_SERVER_ADDR,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->profile_disp.poc_addr),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_PROFILE_POC_SERVERADDR, mmi_poc_entry_full_line_edit);

    BufferSize = POC_MAX_PROFILE_PORT_LEN;
    SetInlineItemTextEdit(
        (wgui_inline_items + POC_PROFILE_POC_SERVERPORT),
        (U8*) (g_poc_cntx_p->profile_disp.poc_port),
        BufferSize,
        INPUT_TYPE_NUMERIC);
    /*EnableInlineItemBoundary(wgui_inline_items + POC_PROFILE_POC_SERVERPORT);*/
    DisableInlineItemHighlight(wgui_inline_items + POC_PROFILE_POC_SERVERPORT);

    BufferSize = POC_PROXY_ADDR_LEN;
    /* BufferSize = POC_MAX_INLINE_ADDR_LEN ; */
    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_PROFILE_POC_XDMADDR),
        STR_ID_POC_XDM_ADDR,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->profile_disp.xdm_addr),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_PROFILE_POC_XDMADDR, mmi_poc_entry_full_line_edit);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_full_line_edit
 * DESCRIPTION
 *  entry inline editor full line editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_full_line_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(MENU_ID_POC_MAIN));
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_profile_edit_nvram
 * DESCRIPTION
 *  profile edit nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_profile_edit_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 temp_proxy_port = 0;
    mmi_poc_profile_struct temp_profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&temp_profile, 0, sizeof(mmi_poc_profile_struct));

    if (g_poc_cntx_p->curr_reg_state != POC_REG_NONE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_DEREGISTER_FIRST),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_POC_SETTING_PROF_OPT_EDIT_POC);
        return;
    }

    memcpy(temp_profile.prof_name, g_poc_cntx_p->profile_disp.prof_name, sizeof(temp_profile.prof_name));
    mmi_ucs2_n_to_asc((S8*) temp_profile.disp_name, (S8*) g_poc_cntx_p->profile_disp.disp_name, POC_MAX_DISP_LEN - 1);
    temp_profile.disp_charset = 0;
    mmi_ucs2_n_to_asc((S8*) temp_profile.uri, (S8*) g_poc_cntx_p->profile_disp.uri, POC_MAX_URI_LEN - 1);
    mmi_ucs2_n_to_asc((S8*) temp_profile.password, (S8*) g_poc_cntx_p->profile_disp.password, POC_MAX_PASSWORD_LEN - 1);
    mmi_ucs2_n_to_asc((S8*) temp_profile.poc_addr, (S8*) g_poc_cntx_p->profile_disp.poc_addr, POC_PROXY_ADDR_LEN - 1);

    temp_proxy_port = gui_atoi((UI_string_type) g_poc_cntx_p->profile_disp.poc_port);
    if (temp_proxy_port > 65535 || temp_proxy_port == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_INVALID_SETTING),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }
    else
    {
        temp_profile.poc_port = (U16) temp_proxy_port;
    }

    mmi_ucs2_n_to_asc((S8*) temp_profile.xdm_addr, (S8*) g_poc_cntx_p->profile_disp.xdm_addr, POC_PROXY_ADDR_LEN - 1);

    temp_profile.data_account = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].data_account;
    temp_profile.use_proxy = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].use_proxy;
    memcpy(
        temp_profile.proxy_username,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_username,
        sizeof(temp_profile.proxy_username));
    memcpy(
        temp_profile.proxy_password,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_password,
        sizeof(temp_profile.proxy_password));
    memcpy(
        temp_profile.proxy_ip,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_ip,
        sizeof(temp_profile.proxy_ip));
    temp_profile.proxy_port = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_port;

    if (temp_profile.uri[0] == 0 || temp_profile.poc_addr[0] == 0 || temp_profile.poc_port > 65535 ||
        temp_profile.xdm_addr[0] == 0)
    {
        DisplayPopup((PU8) GetString(STR_ID_POC_NULL_STR_ERR), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }
    else
    {
        if (WriteRecord(
                NVRAM_EF_POC_PROFILE_LID,
                (U8) (g_poc_cntx_p->profile_selected + 1),
                &temp_profile,
                NVRAM_MAX_POC_PROFILE_SIZE,
                &error) < NVRAM_MAX_POC_PROFILE_SIZE)
        {
            ASSERT(0);
        }
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].prof_name,
            temp_profile.prof_name,
            sizeof(U8) * POC_MAX_PROF_NAME_LEN);
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].disp_charset = temp_profile.disp_charset;
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].disp_name,
            temp_profile.disp_name,
            sizeof(U8) * POC_MAX_DISP_LEN);
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].uri,
            temp_profile.uri,
            sizeof(U8) * POC_MAX_URI_LEN);
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].password,
            temp_profile.password,
            sizeof(U8) * POC_MAX_PASSWORD_LEN);
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].poc_addr,
            temp_profile.poc_addr,
            sizeof(U8) * POC_PROXY_ADDR_LEN);
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].poc_port = temp_profile.poc_port;
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].xdm_addr,
            temp_profile.xdm_addr,
            sizeof(U8) * POC_PROXY_ADDR_LEN);

        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_POC_SETTING_PROF_OPT_EDIT_POC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_settings_profiles_option_edit_conn
 * DESCRIPTION
 *  edit connection settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_settings_profiles_option_edit_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 IPAddress[4];
    U8 LocalBuffer[8];
    U16 icon_list[] = 
    {
        IMG_GLOBAL_L1, 0,
        IMG_GLOBAL_L2, 0,
        IMG_GLOBAL_L3, 0,
        IMG_GLOBAL_L4, 0,
        IMG_GLOBAL_L5, 0,
        IMG_GLOBAL_L6, 0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_SETTING_PROF_OPT_EDIT_CONN, mmi_poc_exit_settings_profiles_option_edit_conn, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_SETTING_PROF_OPT_EDIT_CONN);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_SETTING_PROF_OPT_EDIT_CONN, &inputBufferSize);

    if (inputBuffer == NULL)
    {
        g_poc_cntx_p->profile_disp.data_account =
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].data_account;
        g_poc_cntx_p->profile_disp.use_proxy = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].use_proxy;
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->profile_disp.proxy_username,
            (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_username,
            XDM_MAX_PROXY_USERNAME_LEN);
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->profile_disp.proxy_password,
            (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_password,
            XDM_MAX_PROXY_PASS_LEN);
        if (g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_ip[0] == 0)
        {
            mmi_ucs2cpy((S8*) g_poc_cntx_p->profile_disp.proxy_ip[0], (S8*) g_poc_zero_ip);
            mmi_ucs2cpy((S8*) g_poc_cntx_p->profile_disp.proxy_ip[1], (S8*) g_poc_zero_ip);
            mmi_ucs2cpy((S8*) g_poc_cntx_p->profile_disp.proxy_ip[2], (S8*) g_poc_zero_ip);
            mmi_ucs2cpy((S8*) g_poc_cntx_p->profile_disp.proxy_ip[3], (S8*) g_poc_zero_ip);
        }
        else
        {
            mmi_poc_three_digit_string((PU8) LocalBuffer, 
                                       (U8) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_ip[0]);
            mmi_ucs2cpy((S8*) g_poc_cntx_p->profile_disp.proxy_ip[0], (S8*) LocalBuffer);

            mmi_poc_three_digit_string((PU8) LocalBuffer, 
                (U8) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_ip[1]);
            mmi_ucs2cpy((S8*) g_poc_cntx_p->profile_disp.proxy_ip[1], (S8*) LocalBuffer);

            mmi_poc_three_digit_string((PU8) LocalBuffer, 
                (U8) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_ip[2]);
            mmi_ucs2cpy((S8*) g_poc_cntx_p->profile_disp.proxy_ip[2], (S8*) LocalBuffer);

            mmi_poc_three_digit_string((PU8) LocalBuffer, 
                (U8) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_ip[3]);
            mmi_ucs2cpy((S8*) g_poc_cntx_p->profile_disp.proxy_ip[3], (S8*) LocalBuffer);
        }

        if (g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_port == 0)
        {
            memset(g_poc_cntx_p->profile_disp.proxy_port, 0, sizeof(g_poc_cntx_p->profile_disp.proxy_port));
        }
        else
        {
            gui_itoa(
                g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_port,
                (UI_string_type) g_poc_cntx_p->profile_disp.proxy_port,
                10);
        }

        mmi_dtcnt_get_account_name(
            g_poc_cntx_p->profile_disp.data_account,
            (S8*) g_poc_cntx_p->profile_disp.dt_acct_name,
            MAX_DATA_ACCOUNT_NAME_LEN);
    }
    mmi_poc_prof_conn_fill_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, POC_PROFILE_CONN_INLINE_NUM, inputBuffer);
    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
        STR_ID_POC_CONNECTION_SETTINGS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        POC_PROFILE_CONN_INLINE_NUM,
        (U16*) icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_profile_edit_conn_cfrm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_settings_profiles_option_edit_conn
 * DESCRIPTION
 *  Exit function for inlnine editor screen of Connection Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_settings_profiles_option_edit_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_SETTING_PROF_OPT_EDIT_CONN, mmi_poc_entry_settings_profiles_option_edit_conn);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_prof_conn_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure of profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_prof_conn_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  Yes/No */
    g_poc_cntx_p->profile_disp.yes_no_list[0] = (U8*) GetString(STR_GLOBAL_NO);
    g_poc_cntx_p->profile_disp.yes_no_list[1] = (U8*) GetString(STR_GLOBAL_YES);

    set_leading_zero(FALSE);

    /* Data Account */
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_DATA_ACCOUNT_STR], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(
        &wgui_inline_items[POC_PROFILE_CONN_DATA_ACCOUNT_STR],
        (U8*) GetString(STR_ID_POC_DATA_ACCOUNT));
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_DATA_ACCOUNT], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &wgui_inline_items[POC_PROFILE_CONN_DATA_ACCOUNT],
        (U8*) g_poc_cntx_p->profile_disp.dt_acct_name,
        (PU8) NULL,
        NULL,
        NULL,
        MAX_DATA_ACCOUNT_NAME_LEN,
        0,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(
        &wgui_inline_items[POC_PROFILE_CONN_DATA_ACCOUNT],
        mmi_poc_prof_list_data_acct);
    ShowAsControl(&wgui_inline_items[POC_PROFILE_CONN_DATA_ACCOUNT]);

    /* Use proxy */
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_USE_PROXY_STR], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[POC_PROFILE_CONN_USE_PROXY_STR], (U8*) GetString(STR_ID_POC_USE_PROXY));
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_USE_PROXY], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[POC_PROFILE_CONN_USE_PROXY],
        2,
        g_poc_cntx_p->profile_disp.yes_no_list,
        &g_poc_cntx_p->profile_disp.use_proxy);

    /* Proxy server */
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_PROXYADDR_STR], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[POC_PROFILE_CONN_PROXYADDR_STR], (U8*) GetString(STR_ID_POC_PROXY_ADDR));
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_PROXYRADDR], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[POC_PROFILE_CONN_PROXYRADDR],
        (U8*) g_poc_cntx_p->profile_disp.proxy_ip[0],
        (U8*) g_poc_cntx_p->profile_disp.proxy_ip[1],
        (U8*) g_poc_cntx_p->profile_disp.proxy_ip[2],
        (U8*) g_poc_cntx_p->profile_disp.proxy_ip[3],
        mmi_poc_prof_ip_addr_callback);

    /* Proxy port */
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_PROXYPORT_STR], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[POC_PROFILE_CONN_PROXYPORT_STR], (U8*) GetString(STR_ID_POC_PROXY_PORT));
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_PROXYPORT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[POC_PROFILE_CONN_PROXYPORT],
        (U8*) (g_poc_cntx_p->profile_disp.proxy_port),
        POC_MAX_PROFILE_PORT_LEN,
        INPUT_TYPE_NUMERIC);
    /*EnableInlineItemBoundary(&wgui_inline_items[POC_PROFILE_CONN_PROXYPORT]);*/
    DisableInlineItemHighlight(&wgui_inline_items[POC_PROFILE_CONN_PROXYPORT]);

    /* Proxy User Name */
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_USERNAME_STR], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(
        &wgui_inline_items[POC_PROFILE_CONN_USERNAME_STR],
        (U8*) GetString(STR_ID_POC_PROXY_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_USERNAME], KEY_LSK, KEY_EVENT_UP);

    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[POC_PROFILE_CONN_USERNAME],
        STR_ID_POC_PROXY_USERNAME,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) g_poc_cntx_p->profile_disp.proxy_username,
        XDM_MAX_PROXY_USERNAME_LEN,
        (INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[POC_PROFILE_CONN_USERNAME], mmi_poc_entry_full_line_edit);

    /* Proxy Password */
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_PASS_STR], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[POC_PROFILE_CONN_PASS_STR], (U8*) GetString(STR_ID_POC_PASSWORD));
    SetInlineItemActivation(&wgui_inline_items[POC_PROFILE_CONN_PASS], KEY_LSK, KEY_EVENT_UP);

    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[POC_PROFILE_CONN_PASS],
        STR_ID_POC_PROXY_PASSWORD,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) g_poc_cntx_p->profile_disp.proxy_password,
        XDM_MAX_PROXY_PASS_LEN,
        (INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[POC_PROFILE_CONN_PASS], mmi_poc_entry_full_line_edit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_prof_list_data_acct
 * DESCRIPTION
 *  LSK handler of Data Account item in Profile Setting inline editor screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_prof_list_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*mmi_dtcnt_select_account(
        mmi_poc_prof_gprs_dt_callback,
        MENU_ID_POC_MAIN,
        DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI);*/

    mmi_dtcnt_select_account_option(
        mmi_poc_prof_gprs_dt_callback,
        MENU_ID_POC_MAIN,
        DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI,
        DTCNT_SELECT_SIM,
        DTCNT_SELECT_NO_ALWAYS_ASK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_prof_gprs_dt_callback
 * DESCRIPTION
 *  Callback function for GPRS Data Account
 * PARAMETERS
 *  index       [IN]        Highlight index of selected account
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_prof_gprs_dt_callback(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 acct_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    acct_id = always_ask_encode_app_id_data_account_id(index, g_poc_app_id);

    g_poc_cntx_p->profile_disp.data_account = acct_id;
    
    mmi_dtcnt_get_account_name(
        g_poc_cntx_p->profile_disp.data_account,
        (S8*) g_poc_cntx_p->profile_disp.dt_acct_name,
        MAX_DATA_ACCOUNT_NAME_LEN);

    DeleteUptoScrID(SCR_ID_POC_SETTING_PROF_OPT_EDIT_CONN);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_prof_ip_addr_callback
 * DESCRIPTION
 *  Callback function for IP address editor in inline editor screen
 * PARAMETERS
 *  string_buffer       [?]     
 *  IP1                 [?]     
 *  IP2                 [?]     
 *  IP3                 [?]     
 *  IP4                 [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_prof_ip_addr_callback(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Point[4];
    S32 IPAddress[4];
    U8 LocalBuffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) Point, (S8*) ".");

    IPAddress[0] = (S32) gui_atoi((UI_string_type) IP1);
    IPAddress[1] = (S32) gui_atoi((UI_string_type) IP2);
    IPAddress[2] = (S32) gui_atoi((UI_string_type) IP3);
    IPAddress[3] = (S32) gui_atoi((UI_string_type) IP4);

    mmi_poc_three_digit_string((PU8) LocalBuffer, (U8) IPAddress[0]);
    mmi_ucs2cpy((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    mmi_poc_three_digit_string((PU8) LocalBuffer, (U8) IPAddress[1]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    mmi_poc_three_digit_string((PU8) LocalBuffer, (U8) IPAddress[2]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    mmi_poc_three_digit_string((PU8) LocalBuffer, (U8) IPAddress[3]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  ReturnThreeDigitString
 * DESCRIPTION
 *  This Fun Convert the integer value to String with prefix zero.
 *  
 *  Works only for three digit integer.(0-256)
 * PARAMETERS
 *  StringVal       [IN]        
 *  DigitVal        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_three_digit_string(PU8 StringVal, U8 DigitVal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 LocalBuffer[8];
    S8 StrVal[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DigitVal == 0)
    {
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) "000");
    }
    else if (DigitVal < 10)
    {
        sprintf(LocalBuffer, "00%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    else if (DigitVal < 100)
    {
        sprintf(LocalBuffer, "0%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    else
    {
        sprintf(LocalBuffer, "%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    mmi_ucs2cpy((PS8) StringVal, (PS8) StrVal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_profile_edit_conn_cfrm
 * DESCRIPTION
 *  edit connection screen confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_profile_edit_conn_cfrm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_poc_profile_edit_conn_nvram, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_profile, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_profile_edit_conn_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_profile_edit_conn_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 temp_proxy_port = 0;
    mmi_poc_profile_struct temp_profile;
    U8  bearer_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&temp_profile, 0, sizeof(mmi_poc_profile_struct));

    if (g_poc_cntx_p->curr_reg_state != POC_REG_NONE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_DEREGISTER_FIRST),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_POC_SETTING_PROF_OPT_EDIT_CONN);
        return;
    }

    /* set existing values */
    memcpy(
        temp_profile.prof_name,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].prof_name,
        sizeof(temp_profile.prof_name));
    memcpy(
        temp_profile.disp_name,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].disp_name,
        sizeof(temp_profile.prof_name));
    temp_profile.disp_charset = 0;
    memcpy(temp_profile.uri, g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].uri, sizeof(temp_profile.uri));
    memcpy(
        temp_profile.password,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].password,
        sizeof(temp_profile.password));
    memcpy(
        temp_profile.poc_addr,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].poc_addr,
        sizeof(temp_profile.poc_addr));
    temp_profile.poc_port = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].poc_port;
    memcpy(
        temp_profile.xdm_addr,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].xdm_addr,
        sizeof(temp_profile.xdm_addr));

    /* set new values from display buffer */
    temp_profile.data_account = g_poc_cntx_p->profile_disp.data_account;
    bearer_type = mmi_dtcnt_get_bearer_type((U8)g_poc_cntx_p->profile_disp.data_account);
    temp_profile.use_proxy = g_poc_cntx_p->profile_disp.use_proxy;
    mmi_ucs2_n_to_asc(
        (S8*) temp_profile.proxy_username,
        (S8*) g_poc_cntx_p->profile_disp.proxy_username,
        XDM_MAX_PROXY_USERNAME_LEN - 1);
    mmi_ucs2_n_to_asc(
        (S8*) temp_profile.proxy_password,
        (S8*) g_poc_cntx_p->profile_disp.proxy_password,
        XDM_MAX_PROXY_PASS_LEN - 1);
    temp_profile.proxy_ip[0] = (U8) gui_atoi((UI_string_type) g_poc_cntx_p->profile_disp.proxy_ip[0]);
    temp_profile.proxy_ip[1] = (U8) gui_atoi((UI_string_type) g_poc_cntx_p->profile_disp.proxy_ip[1]);
    temp_profile.proxy_ip[2] = (U8) gui_atoi((UI_string_type) g_poc_cntx_p->profile_disp.proxy_ip[2]);
    temp_profile.proxy_ip[3] = (U8) gui_atoi((UI_string_type) g_poc_cntx_p->profile_disp.proxy_ip[3]);

    if((temp_profile.proxy_ip[0] == 0) && (bearer_type != DATA_ACCOUNT_BEARER_WIFI))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_INVALID_SETTING),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }

    temp_proxy_port = gui_atoi((UI_string_type) g_poc_cntx_p->profile_disp.proxy_port);
    if (temp_proxy_port > 65535)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_INVALID_SETTING),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }
    else
    {
        temp_profile.proxy_port = (U16) temp_proxy_port;
    }

    if (temp_profile.use_proxy == MMI_TRUE && temp_profile.proxy_port == 0  && (bearer_type != DATA_ACCOUNT_BEARER_WIFI))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_POC_ERR_INVALID_SETTING),
            IMG_GLOBAL_UNFINISHED,
            1,
            CS_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }

    if (temp_profile.use_proxy == MMI_TRUE && temp_profile.proxy_ip[0] == 0  && (bearer_type != DATA_ACCOUNT_BEARER_WIFI))
    {
        DisplayPopup((PU8) GetString(STR_ID_POC_NULL_STR_ERR), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
        return;
    }
    else
    {
        if (WriteRecord(
                NVRAM_EF_POC_PROFILE_LID,
                (U8) (g_poc_cntx_p->profile_selected + 1),
                &temp_profile,
                NVRAM_MAX_POC_PROFILE_SIZE,
                &error) < NVRAM_MAX_POC_PROFILE_SIZE)
        {
            ASSERT(0);
        }
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].data_account = temp_profile.data_account;
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].use_proxy = temp_profile.use_proxy;
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_username,
            temp_profile.proxy_username,
            sizeof(U8) * XDM_MAX_PROXY_USERNAME_LEN);
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_password,
            temp_profile.proxy_password,
            sizeof(U8) * XDM_MAX_PROXY_PASS_LEN);
        memcpy(
            g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_ip,
            temp_profile.proxy_ip,
            sizeof(U8) * XDM_MAX_IP_LEN);
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_selected].proxy_port = temp_profile.proxy_port;
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_POC_SETTING_PROF_OPT_EDIT_CONN);
    }
}

#endif /* __MMI_POC__ */ 

