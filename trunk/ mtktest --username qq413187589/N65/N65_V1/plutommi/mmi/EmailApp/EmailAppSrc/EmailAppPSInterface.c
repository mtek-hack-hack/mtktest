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
 * EmailAppPSInterface.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements utilities to interact with PS.
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

   FILENAME : EmailAppPSInterface.c

   PURPOSE     : nil

   REMARKS     : nil 

   AUTHOR      : Magesh k

   DATE     : 30-01-2004 

**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_EMAILAPPPSINTERFACE_C
#define _MMI_EMAILAPPPSINTERFACE_C

#ifdef __MMI_EMAIL__

#include "ProtocolEvents.h"
#include "Conversions.h"
#include "MemPoolContainerProt.h"
#include "CommonScreens.h"
#include "gpioinc.h"

#include "FileManagerGProt.h"
#include "IdleAppProt.h"
#include "AlarmFrameWorkProt.h"
#include "DataAccountGprot.h"
#include "ProfileGprots.h"
#include "wgui_status_icons.h"
#include "SimDetectionGprot.h"
#include "CallManagementGprot.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif
#include "EmailAppResDef.h"
#include "EmailAppProt.h"
#include "EmailAppGProt.h"

email_msg_list_enum folder_listing = EMAIL_LIST_NONE;
BOOL del_msg_unread = MMI_FALSE;
BOOL folder_empty = MMI_FALSE;
BOOL play_warning_tone = MMI_FALSE;
BOOL delete_abort_req = MMI_FALSE;
FuncPtr popup_callback = NULL;
static BOOL is_sending_mails = MMI_FALSE;
extern kal_uint8 app_cbm_id;

extern kal_uint16 email_get_max_num(void);
extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);

#ifdef __MMI_EMAIL_DRM_SUPPORT__
#include "Drm_gprot.h"
#endif 
#ifdef __MMI_EMAIL_OTAP__
    extern MMI_BOOL mmi_email_is_in_otap;
    extern mmi_email_otap_struct *g_email_otap;
    
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    extern MMI_BOOL mmi_email_is_autochk_at_otap_begin;
#endif /*!defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)*/
#endif /*__MMI_EMAIL_OTAP__*/

static void mmi_email_fldr_get_msg_reply_to(email_address_list *reply_to);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_init_protocol_hdlr
 * DESCRIPTION
 *  Initialize all protocol event handlers of email.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_init_protocol_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init, deinit, start, stop mail */
    SetProtocolEventHandler(mmi_email_ps_init_rsp, PRT_MMI_EMAIL_INIT_RSP);
    SetProtocolEventHandler(mmi_email_ps_deinit_rsp, PRT_MMI_EMAIL_DEINIT_RSP);
    SetProtocolEventHandler(mmi_email_ps_start_rsp, PRT_MMI_EMAIL_START_RSP);
    SetProtocolEventHandler(mmi_email_ps_stop_rsp, PRT_MMI_EMAIL_STOP_RSP);
    SetProtocolEventHandler(mmi_email_ps_abort_rsp, PRT_MMI_EMAIL_ABORT_RSP);

    /* send and receive, auto check */
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    SetProtocolEventHandler(mmi_email_ps_auto_chk_ind, PRT_MMI_EMAIL_AUTOCHECK_EXPIRY_IND);
#endif 
    SetProtocolEventHandler(mmi_email_ps_server_conn_ind, PRT_MMI_EMAIL_SERVER_CONNECT_IND);
    SetProtocolEventHandler(mmi_email_ps_msg_sent_ind, PRT_MMI_EMAIL_MSG_SENT_IND);
    SetProtocolEventHandler(mmi_email_ps_num_msgs_sent_ind, PRT_MMI_EMAIL_NUM_MSGS_SENT_IND);
    SetProtocolEventHandler(mmi_email_ps_authverify_ind, PRT_MMI_EMAIL_AUTHVERIFY_IND);
    SetProtocolEventHandler(mmi_email_ps_recv_msgs_ind, PRT_MMI_EMAIL_RECV_MSGS_IND);
    SetProtocolEventHandler(mmi_email_ps_new_msgs_ind, PRT_MMI_EMAIL_NEW_MSGS_IND);
    SetProtocolEventHandler(mmi_email_ps_snr_rsp, PRT_MMI_EMAIL_SEND_RECV_RSP);
    SetProtocolEventHandler(mmi_email_ps_compose_size_rsp, PRT_MMI_EMAIL_COMPOSE_SIZE_RSP);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    SetProtocolEventHandler(mmi_email_ps_set_mode_rsp, PRT_MMI_EMAIL_SET_MODE_RSP);
#endif 
    SetProtocolEventHandler(mmi_email_ps_folder_msg_set_flag_rsp, PRT_MMI_EMAIL_FOLDER_MSG_SET_FLAG_RSP);

    /* folder */
    SetProtocolEventHandler(mmi_email_ps_list_folders_rsp, PRT_MMI_EMAIL_LIST_FOLDERS_RSP);
    SetProtocolEventHandler(mmi_email_ps_folder_select_rsp, PRT_MMI_EMAIL_FOLDER_SELECT_RSP);
    SetProtocolEventHandler(mmi_email_ps_folder_msg_select_rsp, PRT_MMI_EMAIL_FOLDER_MSG_SELECT_RSP);
    SetProtocolEventHandler(mmi_email_ps_folder_msg_del_rsp, PRT_MMI_EMAIL_FOLDER_MSG_DELETE_RSP);

    /* send/save */
    SetProtocolEventHandler(mmi_email_ps_send_only_rsp, PRT_MMI_EMAIL_SEND_ONLY_RSP);
    SetProtocolEventHandler(mmi_email_ps_save_to_draft_rsp, PRT_MMI_EMAIL_SAVE_DRAFTS_RSP);
    SetProtocolEventHandler(mmi_email_ps_move_to_draft_rsp, PRT_MMI_EMAIL_MSG_MOVE_RSP);
    SetProtocolEventHandler(mmi_email_ps_save_and_send_rsp, PRT_MMI_EMAIL_SEND_NOW_RSP);
    SetProtocolEventHandler(mmi_email_ps_send_from_mailbox_rsp, PRT_MMI_EMAIL_SEND_FROM_MAILBOX_RSP);

    /* memory full, available */
    SetProtocolEventHandler(mmi_email_ps_msg_available_ind, PRT_MMI_EMAIL_MSG_AVAILABLE_IND);
    SetProtocolEventHandler(mmi_email_ps_msg_full_ind, PRT_MMI_EMAIL_MSG_FULL_IND);
    SetProtocolEventHandler(mmi_email_ps_uidl_full_ind, PRT_MMI_EMAIL_UIDL_FULL_IND);

    /* profiles */
    SetProtocolEventHandler(mmi_email_ps_list_acct_profile_rsp, PRT_MMI_EMAIL_LIST_ACCT_PROFILE_RSP);
    SetProtocolEventHandler(mmi_email_ps_set_acct_profile_rsp, PRT_MMI_EMAIL_SET_ACCT_PROFILE_RSP);
    SetProtocolEventHandler(mmi_email_ps_get_acct_profile_rsp, PRT_MMI_EMAIL_GET_ACCT_PROFILE_RSP);
    SetProtocolEventHandler(mmi_email_ps_activate_acct_rsp, PRT_MMI_EMAIL_ACTIVATE_ACCT_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_send_msg
 * DESCRIPTION
 *  Wrapper function to send message to Email module
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         [?]
 *  peer_buf_ptr        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((email_p->main_info.ready_state == EMAIL_READY) &&
        (msg_id != PRT_MMI_EMAIL_START_REQ) && (msg_id != PRT_MMI_EMAIL_DEINIT_REQ) &&
        (msg_id != PRT_MMI_EMAIL_ABORT_REQ))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_SEND_MSG, msg_id, email_p->main_info.stop_cause);
        if ((email_p->main_info.stop_cause == EMAIL_STOP_REQ) ||
            ((email_p->main_info.stop_cause == EMAIL_STOP_GOTO_IDLE) &&
             (msg_id != PRT_MMI_EMAIL_STOP_REQ)))
        {
            OslFreeDataPtr(local_param_ptr);
            return;
        }
        else if (email_p->main_info.stop_cause == EMAIL_STOP_NONE)
        {
            OslFreeDataPtr(local_param_ptr);
            mmi_email_util_exit_scr_by_err();
            return;
        }
    }
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_EMAIL;
    Message.oslMsgId = (msg_type) msg_id;
    Message.oslDataPtr = (oslParaType*) local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    OslMsgSendExtQueue(&Message);
    if (((msg_type) msg_id != PRT_MMI_EMAIL_FOLDER_MSG_SELECT_REQ) && ((msg_type) msg_id != PRT_MMI_EMAIL_ABORT_REQ))
    {
        email_p->fldr_info.curr_sel_flag = EMAIL_SEL_NORMAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_init_req
 * DESCRIPTION
 *  Send of MSG_ID_MMI_EMAIL_INIT_REQ to Email.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_init_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_init_req_struct *msgReq =
        (mmi_email_init_req_struct*) OslConstructDataPtr(sizeof(mmi_email_init_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    msgReq->drm_support = TRUE;
#else
    msgReq->drm_support = FALSE;
#endif
    msgReq->app_cbm_id = app_cbm_id;
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_INIT_REQ, (void*)msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_init_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_INIT_RSP.
 *  Store state variables from PS.
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_init_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_init_rsp_struct *msgRsp = (mmi_email_init_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == MMI_FALSE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_SEND_MSG, PRT_MMI_EMAIL_INIT_REQ, PRT_MMI_EMAIL_INIT_REQ);
        return;
    }
    MMI_EXT_ASSERT((msgRsp->result == MMI_TRUE), 0, 0, 0);

    /* init */
    email_p->inbox_info.mmi_email_cont_addr_num = 0;
    email_p->inbox_info.cont_addr_list = NULL;
    email_p->inbox_info.cont_addr_ucs2_buff = NULL;
    email_p->misc_info.str_compose_size = NULL;

    email_p->main_info.unread_mails = msgRsp->no_unread_inbox_msg;
    email_p->prof_info.act_prof.act_indx = msgRsp->activated_acct_index - 1;

    /* update status icon in IDLE screen */
    /* mmi_email_util_update_status_icon(); */
    mmi_email_bearer_status_show_icon_ex(FALSE);
    email_p->main_info.ready_state |= EMAIL_PS_INIT_DONE;

    /* if profile is activated, get information of current activated profile */
    if (mmi_email_prof_is_activated())
    {
        mmi_email_prof_fill_act_info(&msgRsp->activated_acct);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_deinit_req
 * DESCRIPTION
 *  Send of MSG_ID_MMI_EMAIL_DEINIT_REQ to Email.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_deinit_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_folder_init(MMI_TRUE);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_DEINIT_REQ, email_p->main_info.entry_src);
        if (email_p->main_info.entry_src == EMAIL_FROM_MSG)
        {
            SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_MAIN, NULL);
        }
        else if (email_p->main_info.entry_src == EMAIL_FROM_APP)
        {
            SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_COMP, NULL);
        }
    }
#endif
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_DEINIT_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_deinit_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_DEINIT_RSP.
 *  Store state variables from PS.
 * PARAMETERS
 *  inMsg       [IN]        struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_deinit_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_deinit_rsp_struct *msgRsp = (mmi_email_deinit_rsp_struct*) inMsg;
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == MMI_FALSE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_SEND_MSG, PRT_MMI_EMAIL_DEINIT_REQ, PRT_MMI_EMAIL_DEINIT_REQ);
        return;
    }
    MMI_EXT_ASSERT((msgRsp->result == MMI_TRUE), 0, 0, 0);

    /* similar as abort_rsp */
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    if (email_p->snr_info.is_auto_chk)  /* in case in the middle of email auto-checking */
    {
        email_p->snr_info.is_auto_chk = FALSE;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
    /* in write email screen and in the middle of email sending */
    if (is_sending_mails == MMI_TRUE)
    {
        for (i = 0, j = 1; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
        {
            if (email_p->comp_info.attch_list[i].attch_present)
            {
                mmi_email_util_rename_after_abort(j, (S8*) email_p->comp_info.attch_list[i].file_path);
                j++;
            }
        }
    }

#ifdef __MMI_EMAIL_OTAP__
    if(mmi_email_is_in_otap == MMI_TRUE)
    {
        mmi_email_otap_prepare_for_deinit();
    }
#endif /*__MMI_EMAIL_OTAP__*/

#ifdef __MMI_EMAIL_TEMPLATE__
    mmi_email_deinit_templates();
#endif /*__MMI_EMAIL_TEMPLATE__*/

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_DEINIT_RSP, email_p->main_info.entry_src);
        if (email_p->main_info.entry_src == EMAIL_FROM_MSG)
        {
            mmi_email_util_del_upto_scr(SCR_ID_EMAIL_MAIN);
        }
        else if (email_p->main_info.entry_src == EMAIL_FROM_APP)
        {
            mmi_email_util_del_upto_scr(SCR_ID_EMAIL_COMP);
        }
    }
#endif

    /* similar as stop_rsp */
    mmi_email_util_free_container_pool();
    email_p->main_info.stop_cause = EMAIL_STOP_NONE;
    email_p->main_info.entry_src = EMAIL_FROM_MSG;
    email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_NONE;
    /* email_p->main_info.ready_state = EMAIL_NOT_READY; */
    email_p->main_info.is_mem_full = FALSE;
    email_p->main_info.unread_mails = 0;
    delete_abort_req = MMI_TRUE;
    is_sending_mails = MMI_FALSE;
    email_p->fldr_info.is_part_download = EMAIL_DOWN_NONE;
    email_p->misc_info.delete_req = MMI_FALSE;
    memset(&email_p->snr_info, 0, sizeof(mmi_email_snr_info_struct));
    HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
    UpdateStatusIcons();

    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_start_req
 * DESCRIPTION
 *  Send of MSG_ID_MMI_EMAIL_START_REQ to Email.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_start_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->main_info.stop_cause == EMAIL_START_REQ)
    {
        return;
    }
    if (email_p->main_info.stop_cause != EMAIL_STOP_NONE)
    {
        DisplayPopup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_IN_USE_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
    /* 
     * scenario: show confirm screen download and wait for check interval comes
     * so, check the flag before send start request
     */
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    if (email_p->snr_info.is_auto_chk)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_AUTO_CHECK_BUSY_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
    AlmDisableExpiryHandler();
    mmi_email_util_folder_init(MMI_TRUE);
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_START_REQ, NULL, NULL);
    email_p->main_info.stop_cause = EMAIL_START_REQ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_start_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_START_RSP
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_start_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_start_rsp_struct *msgRsp = (mmi_email_start_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == MMI_TRUE)
    {
        email_p->main_info.stop_cause = EMAIL_MODULE_ACTIVE_NOW;

        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_START_RSP, email_p->main_info.entry_src);

#ifdef __MMI_EMAIL_OTAP__
        if(mmi_email_is_in_otap == MMI_TRUE)
        {
            mmi_email_exec_proc_cca_doc(g_email_otap->conf_id, g_email_otap->doc_hdl); 
        }
        else
 #endif /*__MMI_EMAIL_OTAP__*/
        {
        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
            {
                email_p->mode_status.start_req = EMAIL_LIST_START;
                if (email_p->main_info.entry_src == EMAIL_FROM_APP)
                {
                    email_p->mode_status.req_mode = EMAIL_MODE_ONLINE;
                }
                mmi_email_ps_set_mode_req();
            }
            else
        #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            {
                mmi_email_ps_mode_status_ready();
            }
        }
    }
    else
    {
        mmi_email_util_display_err_popup(
            msgRsp->minor,
            msgRsp->major,
            0,
            SCR_ID_EMAIL_MAIN);
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        email_p->main_info.stop_cause = EMAIL_STOP_NONE;
        if (email_p->main_info.entry_src == EMAIL_FROM_APP)
        {
            /* reset state */
            email_p->misc_info.file_copy_state = EMAIL_FILE_ADD_ATTCH;
            email_p->main_info.entry_src = EMAIL_FROM_MSG;
        }
    }
    delete_abort_req = MMI_FALSE;
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_mode_status_ready
 * DESCRIPTION
 *  Enter specified screen after mode status is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_mode_status_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->main_info.entry_src == EMAIL_FROM_APP)
    {
        /* enter write Email screen from other app like phonebook, file manager */
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_DONE;

        /* add signature attach and text, if present */
        if (mmi_email_comp_add_sig() == FALSE)
        {
            return;
        }

        if(email_p->other_app_info.app_param.is_save_to_draft == MMI_TRUE)
        {
            mmi_email_ps_save_to_draft_req();
        }
        else
        {
            mmi_email_entry_comp();
        }

        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    }
    else
    {
        /* normal entry */
        if (email_p->fldr_info.fldr_update_state == EMAIL_LIST_FLDR_REQUIRED)
        {
            mmi_email_ps_list_folders_req();
        }
        else
        {
            email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_DONE;
            mmi_email_entry_main();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_stop_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_STOP_REQ message to protocol.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free space */
    mmi_email_read_cont_addr_release_buf();

#ifdef __MMI_EMAIL_TEMPLATE__
    mmi_email_deinit_templates();
#endif /*__MMI_EMAIL_TEMPLATE__*/

    AlmDisableExpiryHandler();
    /* in write email screen and in the middle of email sending */
    if (is_sending_mails == MMI_TRUE)
    {
        for (i = 0, j = 1; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
        {
            if (email_p->comp_info.attch_list[i].attch_present)
            {
                mmi_email_util_rename_after_abort(j, (S8*) email_p->comp_info.attch_list[i].file_path);
                j++;
            }
        }
    }
    mmi_email_util_folder_init(MMI_TRUE);
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_STOP_REQ, NULL, NULL);
    if (email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
    {
        email_p->main_info.stop_cause = EMAIL_STOP_REQ;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_stop_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_STOP_RSP message.
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  inMsg    IN    struct variable of response message.(?)(?)
 *****************************************************************************/
void mmi_email_ps_stop_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stop_cause_enum stop_cause = email_p->main_info.stop_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_STOP_RSP, email_p->main_info.stop_cause, email_p->main_info.entry_src);

    /* 
     * GoBackHistory will EntryNewScreen, so if status not reset, 
     * the new screen will have END_KEY handler of Email, 
     * quiting screen will display 
     */
    email_p->main_info.stop_cause = EMAIL_STOP_NONE;
    switch (stop_cause)
    {
        case EMAIL_STOP_BACK_HIST:
            if (IsScreenPresent(SCR_ID_EMAIL_MAIN))
            {
                DeleteNScrId(SCR_ID_EMAIL_MAIN);
            }
            else if (IsScreenPresent(SCR_ID_EMAIL_FOLDER))
            {
                DeleteNScrId(SCR_ID_EMAIL_FOLDER);
            }
            /* do not force call screen to go back history */
            if (GetExitScrnID() == SCR_ID_EMAIL_PROGRESS)
            {
                GoBackHistory();
            }
            break;
        case EMAIL_STOP_GOTO_IDLE:
            DeleteUptoScrID(IDLE_SCREEN_ID);
            /* do not force call screen to go to idle screen */
            if (mmi_email_util_is_scrid_owned(GetExitScrnID()))
            {
                GoBackHistory();
            }
            break;
        default:
            DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
            mmi_email_util_exit_scr_by_err();
            break;
    }

    mmi_email_util_free_container_pool();
    email_p->main_info.entry_src = EMAIL_FROM_MSG;
    email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_NONE;
    delete_abort_req = MMI_TRUE;
    is_sending_mails = MMI_FALSE;
    email_p->fldr_info.is_part_download = EMAIL_DOWN_NONE;
    email_p->misc_info.delete_req = MMI_FALSE;
    memset(&email_p->snr_info, 0, sizeof(mmi_email_snr_info_struct));
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    email_p->mode_status.curr_mode = EMAIL_MODE_OFFLINE;
#endif
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_abort_req
 * DESCRIPTION
 *  Send abort request to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_abort_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmDisableExpiryHandler();
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_CANCEL),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_ABORT_REQ, NULL, NULL);
    if (email_p->fldr_info.curr_sel_flag == EMAIL_SEL_GET_RSP)
    {
        email_p->fldr_info.curr_sel_flag = EMAIL_SEL_ABT_NOT;
    }
    else
    {
        email_p->fldr_info.curr_sel_flag = EMAIL_SEL_ABT_REQ;
    }
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if ((email_p->mode_status.start_req != EMAIL_LIST_NONE) &&
        (EMAIL_IS_PROT(EMAIL_PROT_IMAP4)))
    {
        email_p->mode_status.start_req = EMAIL_LIST_ABORT;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    if (folder_listing == EMAIL_LIST_START)
    {
        folder_listing = EMAIL_LIST_ABORT;
    }
    delete_abort_req = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_abort_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_EMAIL_ABORT_RSP message
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  inMsg    IN    struct variable of response message.(?)(?)
 *****************************************************************************/
void mmi_email_ps_abort_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    mmi_email_abort_rsp_struct *msgRsp = (mmi_email_abort_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_abort_req = MMI_FALSE;
#ifdef __MMI_EMAIL_OTAP__
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    if (mmi_email_is_in_otap == MMI_TRUE)
    {
        if (!(msgRsp->result == MMI_FALSE && 
             msgRsp->major == MMI_EMAIL_MAIL_ERR &&
             msgRsp->minor == MMI_EMAIL_ERROR_MSG_REQ))
        {
            /*after abort, PS start automatically*/
            email_p->main_info.stop_cause = EMAIL_MODULE_ACTIVE_NOW;
        }

        if(mmi_email_is_autochk_at_otap_begin == MMI_TRUE)
        {
            mmi_email_is_autochk_at_otap_begin = MMI_FALSE;
            mmi_email_exec_proc_cca_doc(g_email_otap->conf_id, g_email_otap->doc_hdl);    
        }
        else
        {
            GoBackHistory(); /*delete SCR_ID_EMAIL_PROGRESS which display STR_GLOBAL_CANCEL*/
        }
        
        if (msgRsp->result == MMI_TRUE)
        {
            email_p->snr_info.is_auto_chk = FALSE;
        }
        AlmEnableExpiryHandler();
        return;
    }
#endif /*!defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)*/
#endif /*__MMI_EMAIL_OTAP__*/
    
    if (msgRsp->result == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_EMAIL_CANCELED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        /* 
         * abort success, we do not change the list folder status, 
         * because the status do not need to change
         */
        if (folder_listing == EMAIL_LIST_ABORT)
        {
            email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_REQUIRED;
        }
        else
        {
            folder_listing = EMAIL_LIST_NONE;
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        if (folder_listing == EMAIL_LIST_ABORT)
        {
            email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_REQUIRED;
        }
        if ((folder_listing != EMAIL_LIST_ABORT) && (!folder_empty))
        {
            email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
        }
        else
        {
            folder_listing = EMAIL_LIST_NONE;
        }
        /* 
         * if email is entered by other application and abort is fail also,
         * it should directly return to other application's screen 
         */
        if (email_p->main_info.entry_src == EMAIL_FROM_APP)
        {
            memset(&email_p->snr_info, 0, sizeof(mmi_email_snr_info_struct));
        }
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        DeleteScreenIfPresent(SCR_ID_EMAIL_INBOX_OPT);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_ABORT_RSP, email_p->main_info.curr_menu);
    if (is_sending_mails == MMI_TRUE)        /* in write Email screen, for all folders */
    {
        is_sending_mails = MMI_FALSE;
        for (i = 0, j = 1; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
        {
            if (email_p->comp_info.attch_list[i].attch_present)
            {
                mmi_email_util_rename_after_abort((U8) j, (S8*) email_p->comp_info.attch_list[i].file_path);
                j++;
            }
        }
        mmi_email_util_del_between_scr(SCR_ID_EMAIL_COMP_OPT, SCR_ID_EMAIL_PROGRESS);
    }
    else if (msgRsp->result == MMI_TRUE)
    {
        switch (email_p->main_info.curr_menu)
        {
            case MMI_EMAIL_SNR:
            {
                /* abort send and receive should not do list folder again */
            #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
                if (((email_p->mode_status.start_req == EMAIL_LIST_START) ||
                     (email_p->mode_status.start_req == EMAIL_LIST_ABORT)) &&
                    (EMAIL_IS_PROT(EMAIL_PROT_IMAP4)))
                {
                    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_REQUIRED;
                    email_p->mode_status.start_req = EMAIL_LIST_NONE;
                }
                else
            #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
                {
                    if (email_p->snr_info.num_recv > 0 || email_p->snr_info.num_sent > 0)
                    {
                        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
                        email_p->fldr_info.need_fldr_sel = TRUE;
                    }
                }
                if (!IsScreenPresent(SCR_ID_EMAIL_MAIN))
                {
                    mmi_email_fldr_exec_curr_rsp(
                        SCR_ID_EMAIL_PROGRESS,
                        mmi_email_entry_main,
                        mmi_email_exit_main_menu);
                }
                email_p->snr_info.snr_state = EMAIL_SNR_IDLE;
                break;
            }
            case MMI_EMAIL_COMP:
            {
                if (
                    (email_p->snr_info.num_recv > 0 || email_p->snr_info.num_sent > 0)
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
                    && email_p->snr_info.is_auto_chk
#endif
                    )
                {
                    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
                }
                /* if email is entered by other application, email main menu is definitely not in the history.
                   but email main menu should not show up, instead, the screen should remain as original */
                if (!IsScreenPresent(SCR_ID_EMAIL_MAIN) && email_p->main_info.entry_src != EMAIL_FROM_APP)
                {
                    mmi_email_fldr_exec_curr_rsp(
                        SCR_ID_EMAIL_PROGRESS,
                        mmi_email_entry_main,
                        mmi_email_exit_main_menu);
                }
                break;
            }
            case MMI_EMAIL_INBOX:
            case MMI_EMAIL_UNSENT:
            case MMI_EMAIL_SENT:
            case MMI_EMAIL_DRAFT:
            {
                U16 listScrnId = mmi_email_util_get_fldr_scr_id();

                if (email_p->fldr_info.curr_sel_flag == EMAIL_SEL_ABT_NOT)
                {
                    break;
                }
                else if (((email_p->fldr_info.is_part_download == EMAIL_DOWN_IMAP4) ||
                          (email_p->fldr_info.is_part_download == EMAIL_DOWN_POP3)) &&
                         (IsScreenPresent(SCR_ID_EMAIL_PROGRESS)))
                {
                    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_SENT_OPT);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_UNSENT_OPT);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_DRAFT_OPT);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_INBOX_OPT);
                }
                else if (email_p->misc_info.delete_req)
                {
                    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_SENT_OPT);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_UNSENT_OPT);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_DRAFT_OPT);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_INBOX_OPT);
                    email_p->misc_info.delete_req = MMI_FALSE;
                }
                /* delete screen to inbox / unsent / sent / draft folder only if it doesn't abort from auto check */
                else if (IsScreenPresent(listScrnId) && email_p->snr_info.snr_state == EMAIL_SNR_IDLE)
                {
                    U16 startSrcnId;

                    GetNextScrnIdOf(listScrnId, &startSrcnId);
                    if ((startSrcnId == SCR_ID_EMAIL_FLDR_LIST_PROGRESS) || email_p->misc_info.folder_select_req)
                    {
                        mmi_email_util_del_upto_scr(listScrnId);
                        mmi_email_util_update_status_icon();
                        email_p->misc_info.folder_select_req = MMI_FALSE;
                    }
                    else
                    {
                        mmi_email_util_del_between_scr(startSrcnId, SCR_ID_EMAIL_PROGRESS);
                    }
                }
                else    /* abort from auto check, go back to original screen */
                {
                    if (
                        (email_p->snr_info.num_recv > 0 || email_p->snr_info.num_sent > 0)
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
                        && email_p->snr_info.is_auto_chk
#endif
                        )
                    {
                        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
                    }
                    if (!IsScreenPresent(SCR_ID_EMAIL_MAIN))
                    {
                        mmi_email_fldr_exec_curr_rsp(
                            SCR_ID_EMAIL_PROGRESS,
                            mmi_email_entry_main,
                            mmi_email_exit_main_menu);
                        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                    }
                }
                if (email_p->misc_info.set_flag_result == MMI_TRUE)
                {
                    email_p->misc_info.set_flag_result = MMI_FALSE;
                }

                break;
            }
            case MMI_EMAIL_DEL_ALL_MARK:
            case MMI_EMAIL_DEL_ALL:
            {
                if (!IsScreenPresent(SCR_ID_EMAIL_DELETE_ALL))
                {
                    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_REQUIRED;
                }
                if (!IsScreenPresent(SCR_ID_EMAIL_MAIN))
                {
                    mmi_email_fldr_exec_curr_rsp(
                        SCR_ID_EMAIL_PROGRESS,
                        mmi_email_entry_main,
                        mmi_email_exit_main_menu);
                }

                break;
            }
            default:
            {
                /*
                 * default state, go to main menu. 
                 * case MMI_EMAIL_NONE:    
                 * case MMI_EMAIL_PROF:
                 * case MMI_EMAIL_REFRESH:
                 */
                if (
                    (email_p->snr_info.num_recv > 0 || email_p->snr_info.num_sent > 0)
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
                    && email_p->snr_info.is_auto_chk
#endif
                    )
                {
                    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
                }
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
                if (((email_p->mode_status.start_req == EMAIL_LIST_START) ||
                    (email_p->mode_status.start_req == EMAIL_LIST_ABORT)) &&
                    (EMAIL_IS_PROT(EMAIL_PROT_IMAP4)))
                {
                    email_p->mode_status.start_req = EMAIL_LIST_NONE;
                }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
                if (!IsScreenPresent(SCR_ID_EMAIL_MAIN))
                {
                    mmi_email_fldr_exec_curr_rsp(
                        SCR_ID_EMAIL_PROGRESS,
                        mmi_email_entry_main,
                        mmi_email_exit_main_menu);
                }
                break;
            }
        }
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        DeleteScreenIfPresent(SCR_ID_EMAIL_FLDR_LIST_PROGRESS);
    }
    if (msgRsp->result == MMI_TRUE)
    {
        email_p->snr_info.snr_state = EMAIL_SNR_IDLE;   /* to prevent auto SNR happened in Email app */
        memset(&email_p->snr_info, 0, sizeof(mmi_email_snr_info_struct));
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
        email_p->snr_info.is_auto_chk = FALSE;
#endif
    }
    AlmEnableExpiryHandler();
}


#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_set_mode_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_SET_MODE_REQ messages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_set_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_set_mode_req_struct *msgReq =
        (mmi_email_set_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_email_set_mode_req_struct));
    history interrupt;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->mode_status.req_mode == EMAIL_MODE_ONLINE)
    {
        msgReq->working_mode = MMI_EMAIL_ONLINE_MODE;
    }
    else
    {
        msgReq->working_mode = MMI_EMAIL_OFFLINE_MODE;
    }
    /*
     * add history screen to avoid loading screen been deleted 
     * by other APP and MMI not send stop request
     */
    if (email_p->mode_status.start_req == EMAIL_LIST_START)
    {
        interrupt.scrnID = SCR_ID_EMAIL_INTERRUPT;
        interrupt.entryFuncPtr = mmi_email_ps_stop_req;
        mmi_ucs2cpy((S8*) interrupt.inputBuffer, (S8*) & ucs2InputBuffer);
        AddHistory(interrupt);
        SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_INTERRUPT, (HistoryDelCBPtr) mmi_email_main_del_callback);
    }
    if (email_p->mode_status.reset_mode == MMI_FALSE)
    {
        mmi_email_pre_entry_progressing(
            STR_EMAIL_MAIN_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            0,
            0,
            (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
            (U8*) NULL,
            IMG_EMAIL_CONNECTING_ID,
            NULL,
            NULL,
            NULL);
    }
    else
    {
        mmi_email_pre_entry_progressing(
            STR_EMAIL_MAIN_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            0,
            0,
            (U8*) GetString(STR_EMAIL_COMMON_SWITCHING_ID),
            (U8*) NULL,
            IMG_EMAIL_CONNECTING_ID,
            NULL,
            NULL,
            NULL);
    }
    email_p->mode_status.reset_mode = MMI_FALSE;
    AlmDisableExpiryHandler();
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_SET_MODE_REQ, (void*)msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_set_mode_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_SET_MODE_REQ messages
 * PARAMETERS
 *  inMsg       [IN]        Data of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_set_mode_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 errMsgId;
    mmi_email_set_mode_rsp_struct *msgRsp = (mmi_email_set_mode_rsp_struct*) inMsg;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < EMAIL_FLDR_TOTAL; i++)
    {
        email_p->fldr_info.fldr_data[i].total_mails = 0;
    }
    /*
     * delete the screen for MMI can start normal procedure, 
     * means the procedure should not be interrupted
     */
    if (email_p->mode_status.start_req == EMAIL_LIST_START)
    {
        SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_INTERRUPT, NULL);
        DeleteScreenIfPresent(SCR_ID_EMAIL_INTERRUPT);
    }
    if (msgRsp->result == MMI_TRUE)
    {
        if (email_p->mode_status.req_mode == EMAIL_MODE_ONLINE)
        {
            email_p->mode_status.curr_mode = EMAIL_MODE_ONLINE;
        }
        else
        {
            email_p->mode_status.curr_mode = EMAIL_MODE_OFFLINE;
        }
        if (email_p->mode_status.start_req == EMAIL_LIST_START)
        {
            mmi_email_ps_mode_status_ready();
        }
        else
        {
            mmi_email_ps_list_folders_req();
        }
    }
    else
    {
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
        email_p->mode_status.curr_mode = EMAIL_MODE_OFFLINE;
        if ((email_p->mode_status.start_req == EMAIL_LIST_START) &&
            (email_p->main_info.entry_src != EMAIL_FROM_APP))
        {
            errMsgId = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);
            popup_callback = mmi_email_ps_mode_status_ready;
            mmi_email_util_display_popup(
                (U8*) GetString(errMsgId),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            mmi_email_ps_popup_callback();
        }
        else if ((email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW) &&
            (email_p->main_info.entry_src == EMAIL_FROM_APP))
        {
            errMsgId = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);
            popup_callback = mmi_email_main_quit_to_app_ext;
            mmi_email_util_display_popup(
                (U8*) GetString(errMsgId),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            mmi_email_ps_popup_callback();
        }
        else
        {
            errMsgId = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);
            mmi_email_util_display_popup(
                (U8*) GetString(errMsgId),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        }
    }
    AlmEnableExpiryHandler();
}
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_popup_callback
 * DESCRIPTION
 *  Add interrupt screen to history when set mode fail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_popup_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history interrupt;
    S16 ucs2InputBuffer = 0;
    U16 cmScrnId = GetCmMarkerScrnID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    interrupt.scrnID = SCR_ID_EMAIL_INTERRUPT;
    interrupt.entryFuncPtr = popup_callback;
    mmi_ucs2cpy((S8*) interrupt.inputBuffer, (S8*) & ucs2InputBuffer);
    /*
     * check the call marker screen, if UCM is not defined, the screen of interrupt
     * may be deleted by CM, so add the screen before call marker screen
     */
    if (IsScreenPresent(cmScrnId))
    {
        InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), interrupt);
    }
    else
    {
        AddHistory(interrupt);
    }
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_msg_available_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_MSG_AVAILABLE_IND messages
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_msg_available_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.is_mem_full = FALSE;
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    email_p->fldr_info.need_fldr_sel = TRUE;
    mmi_email_util_update_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_msg_full_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_MSG_FULL_IND messages
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_msg_full_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.is_mem_full = TRUE;
    mmi_email_util_update_status_icon();
    TurnOnBacklight(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_uidl_full_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_UIDL_FULL_IND messages
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_uidl_full_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.is_uidl_full = TRUE;
    TurnOnBacklight(1);
    playRequestedTone(WARNING_TONE);
}

#define PROFILE_PS_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_list_acct_profile_req
 * DESCRIPTION
 *  Send list account request to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_list_acct_profile_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_p->snr_info.is_auto_chk)
    {
        mmi_email_pre_entry_progressing(
            STR_EMAIL_MAIN_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            0,
            0,
            (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
            NULL,
            IMG_GLOBAL_PROGRESS,
            NULL,
            NULL,
            NULL);
        AlmDisableExpiryHandler();
        mmi_email_ps_send_msg(PRT_MMI_EMAIL_LIST_ACCT_PROFILE_REQ, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_list_acct_profile_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_EMAIL_LIST_ACCT_PROFILE_RSP message.
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  inMsg    IN    struct variable of response message.(?)(?)
 *****************************************************************************/
void mmi_email_ps_list_acct_profile_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_list_acct_profile_rsp_struct *msgRsp = (mmi_email_list_acct_profile_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == MMI_TRUE)
    {
        if (GetExitScrnID() == SCR_ID_EMAIL_PROGRESS)
        {
            mmi_email_prof_fill_data(&msgRsp->list_acct);
            DataAccountReadyCheck(mmi_email_ps_dt_acct_callback);
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        }
    }
    else
    {
    #if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
        if (!email_p->snr_info.is_auto_chk)
    #endif 
        {
            U16 errMsgId = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);

            mmi_email_util_display_popup(
                (U8*) GetString(errMsgId),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        }
    }
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_dt_acct_callback
 * DESCRIPTION
 *  Callback function when data account ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_dt_acct_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if(mmi_email_is_in_otap == MMI_TRUE)
    {
        if (GetExitScrnID() == SCR_ID_EMAIL_PROGRESS)
        {
            mmi_email_otap_entry_prof();
        }        
    }
    else
#endif /*__MMI_EMAIL_OTAP__*/
    {
        if (GetExitScrnID() == SCR_ID_EMAIL_PROGRESS)
        {
            mmi_email_entry_prof();
        }
    }

    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_set_acct_profile_req
 * DESCRIPTION
 *  Send request to set profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_set_acct_profile_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_set_acct_profile_req_struct *msgReq =
        (mmi_email_set_acct_profile_req_struct*) OslConstructDataPtr(sizeof(mmi_email_set_acct_profile_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if(mmi_email_is_in_otap == MMI_TRUE)
    {
        mmi_email_otap_prof_set_acct_data((mmi_email_set_acct_profile_req_struct*) msgReq);
    }
    else
#endif /*__MMI_EMAIL_OTAP__*/
    {
        mmi_email_prof_set_acct_data((mmi_email_set_acct_profile_req_struct*) msgReq);
    }

    AlmDisableExpiryHandler();
    if (email_p->prof_info.act_prof.act_indx == email_p->prof_info.prof_misc.curr_sel_prof)
    {
        email_p->main_info.is_acct_change = MMI_TRUE;
    }

    mmi_email_ps_send_msg(PRT_MMI_EMAIL_SET_ACCT_PROFILE_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_set_acct_profile_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_EMAIL_SET_ACCT_PROFILE_RSP message.
 * PARAMETERS
 *  inMsg       [IN]        Variable contains result of saving account
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_set_acct_profile_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 startSrcnId;
    mmi_email_set_acct_profile_rsp_struct *msgRsp = (mmi_email_set_acct_profile_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == MMI_TRUE)
    {
        #ifdef __MMI_EMAIL_OTAP__
        if(mmi_email_is_in_otap == MMI_TRUE)
        {
            /* current OTA Provisioning profile is active profile */
            if (email_p->prof_info.prof_misc.curr_sel_prof == email_p->prof_info.act_prof.act_indx)
            {
                mmi_email_otap_prof_update_act_info();
            }        

            g_email_otap->profile[g_email_otap->profile_index]->cca_prof_status = CCA_STATUS_OK;
            mmi_email_next_profile();
        }
        else
        #endif /*__MMI_EMAIL_OTAP__*/
        {
            mmi_ucs2cpy(
                (S8*) email_p->prof_info.prof_misc.acct_names[email_p->prof_info.prof_misc.curr_sel_prof],
                (S8*) email_p->prof_info.editing_prof.setting_info.prof_name);

            /* current editing profile is active profile */
            if (email_p->prof_info.prof_misc.curr_sel_prof == email_p->prof_info.act_prof.act_indx)
            {
                mmi_email_prof_update_act_info();
            }

            mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            GetNextScrnIdOf(SCR_ID_EMAIL_PROF_OPT_EDIT, &startSrcnId);
            mmi_email_util_del_between_scr(startSrcnId, SCR_ID_EMAIL_PROGRESS);
        }
    }
    else
    {
    #if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
        if (!email_p->snr_info.is_auto_chk)
    #endif 
        {
            U16 errMsgId = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);

            mmi_email_util_display_popup(
                (U8*) GetString(errMsgId),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            GetNextScrnIdOf(email_p->prof_info.prof_misc.curr_scr, &startSrcnId);
            mmi_email_util_del_between_scr(startSrcnId, SCR_ID_EMAIL_PROGRESS);
        }
    }

    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_get_acct_profile_req
 * DESCRIPTION
 *  Send request to get data of a specific profile.
 * PARAMETERS
 *  index       [IN]        Index of profile(indexing from 1).
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_get_acct_profile_req(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_get_acct_profile_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq =
        (mmi_email_get_acct_profile_req_struct*) OslConstructDataPtr(sizeof(mmi_email_get_acct_profile_req_struct));
    msgReq->acct_index = index;

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);

    AlmDisableExpiryHandler();
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_GET_ACCT_PROFILE_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_get_acct_profile_rsp
 * DESCRIPTION
 *  Handler of get profile response
 * PARAMETERS
 *  inMsg       [IN]        Data of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_get_acct_profile_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_get_acct_profile_rsp_struct *msgRsp = (mmi_email_get_acct_profile_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == MMI_TRUE)
    {
        mmi_email_prof_get_acct_data(&msgRsp->acct);
        email_p->prof_info.prof_misc.curr_hilite_indx = 0;
        switch (email_p->prof_info.prof_misc.curr_scr)
        {
            case SCR_ID_EMAIL_PROF_SETTING:
                /* store current protocol to check if protocol changed afterwards */
        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
                email_p->prof_info.prof_misc.curr_prot = msgRsp->acct.imap_pop3_info.in_protocol;
        #endif 
                mmi_email_entry_prof_setting();
                break;
            case SCR_ID_EMAIL_PROF_SMTP:
                mmi_email_entry_prof_smtp();
                break;
            case SCR_ID_EMAIL_PROF_POP3_IMAP4:
                mmi_email_entry_prof_pop3_imap4();
                break;
            case SCR_ID_EMAIL_PROF_SIG:
                mmi_email_prof_pre_entry_sig();
                break;
        }
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    }
    else
    {
    #if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
        if (!email_p->snr_info.is_auto_chk)
    #endif 
        {
            mmi_email_util_display_err_popup(
                msgRsp->minor,
                msgRsp->major,
                0,
                SCR_ID_EMAIL_MAIN);
            DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        }
    }

    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_activate_acct_req
 * DESCRIPTION
 *  Send request to Email to activate a specific account
 * PARAMETERS
 *  index       [IN]        Index of account to be activated.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_activate_acct_req(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_activate_acct_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_email_activate_acct_req_struct*) OslConstructDataPtr(sizeof(mmi_email_activate_acct_req_struct));
    msgReq->acct_index = index;

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_SAVING),
        (U8*) NULL,
        IMG_GLOBAL_SAVE,
        NULL,
        NULL,
        NULL);

    AlmDisableExpiryHandler();
    email_p->main_info.is_acct_change = MMI_TRUE;

    mmi_email_ps_send_msg(PRT_MMI_EMAIL_ACTIVATE_ACCT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_activate_acct_rsp
 * DESCRIPTION
 *  Handler of activate profile response
 * PARAMETERS
 *  inMsg       [IN]        Data of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_activate_acct_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 startScrnid;
    mmi_email_activate_acct_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_email_activate_acct_rsp_struct*) inMsg;

    if (msgRsp->result == MMI_TRUE)
    {
        BOOL prof_changed = FALSE;

        if (email_p->prof_info.act_prof.act_indx != email_p->prof_info.prof_misc.curr_sel_prof)
        {
            prof_changed = TRUE;
        }

        email_p->prof_info.act_prof.act_indx = email_p->prof_info.prof_misc.curr_sel_prof;
        mmi_email_prof_fill_act_info(&msgRsp->acct);

        if (prof_changed)
        {
            mmi_email_prof_update_hint();
        }

        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_PROFILE_ACTIVATED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major)),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    GetNextScrnIdOf(SCR_ID_EMAIL_PROF, &startScrnid);
    mmi_email_util_del_between_scr(startScrnid, SCR_ID_EMAIL_PROGRESS);
    AlmEnableExpiryHandler();
}

#define FOLDER_PS_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_list_folders_req
 * DESCRIPTION
 *  Display progressing screen and send list folder request to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_list_folders_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        mmi_email_util_abort_str(),
        mmi_email_util_abort_img(),
        (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_email_util_get_abort_func(),
        mmi_email_util_get_abort_func());

    AlmDisableExpiryHandler();
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_LIST_FOLDERS_REQ, NULL, NULL);
    folder_listing = EMAIL_LIST_START;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_list_folders_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_LIST_FOLDERS_RSP message.
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of responsed message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_list_folders_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_list_folders_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_email_list_folders_rsp_struct*) inMsg;

    TurnOnBacklight(1);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if ((email_p->mode_status.start_req == EMAIL_LIST_START) &&
        (EMAIL_IS_PROT(EMAIL_PROT_IMAP4)))
    {
        email_p->mode_status.start_req = EMAIL_LIST_NONE;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    if (folder_listing == EMAIL_LIST_START)
    {
        folder_listing = EMAIL_LIST_NONE;
    }

    if (msgRsp->result == MMI_TRUE)
    {
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_DONE;
        mmi_email_fldr_reset_cntx(EMAIL_RESET_ALL_FLDR);
        memcpy(&email_p->fldr_info.fldr_data, &msgRsp->folders, sizeof(email_folder_info_struct) * EMAIL_FLDR_TOTAL);

        /* update unread email status */
        email_p->main_info.unread_mails = email_p->fldr_info.fldr_data[MMI_EMAIL_INBOX].num_unread_mails;
        mmi_email_util_update_status_icon();

        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_LIST_FOLDERS_RSP, email_p->fldr_info.list_fldr_cause);

        switch (email_p->fldr_info.list_fldr_cause)
        {
            case EMAIL_LIST_FLDR_NORMAL:
            {
                mmi_email_fldr_exec_curr_rsp(
                    SCR_ID_EMAIL_PROGRESS,
                    mmi_email_entry_main,
                    mmi_email_exit_main_menu);
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_MAIN, (HistoryDelCBPtr) mmi_email_main_del_callback);
                break;
            }
            case EMAIL_LIST_FLDR_SWITCH:
            {
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                if (!mmi_email_util_is_scrid_owned(GetExitScrnID()))
                {
                    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                }
                else
                {
                    GoBackHistory();
                }
                break;
            }
            case EMAIL_LIST_FLDR_PROF:
            {
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                email_p->main_info.is_acct_change = MMI_FALSE;
                mmi_email_util_update_status_icon();
                GoBackHistory();
                break;
            }
            case EMAIL_LIST_FLDR_REFRESH:
            case EMAIL_LIST_FLDR_BACK_MAIN:
            {
                if (GetExitScrnID() == SCR_ID_EMAIL_PROGRESS)
                {
                    mmi_email_entry_main();
                    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_MAIN, NULL);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_MAIN);
                    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_MAIN, (HistoryDelCBPtr) mmi_email_main_del_callback);
                }
                else
                {
                    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_MAIN, NULL);
                    DeleteScreenIfPresent(SCR_ID_EMAIL_MAIN);
                    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_MAIN, (HistoryDelCBPtr) mmi_email_main_del_callback);
                    HistoryReplace(SCR_ID_EMAIL_PROGRESS, SCR_ID_EMAIL_MAIN, mmi_email_entry_main);
                }
                break;
            }
            case EMAIL_LIST_FLDR_DEL_ALL:
            {
                mmi_email_fldr_exec_curr_rsp(
                    SCR_ID_EMAIL_PROGRESS,
                    mmi_email_entry_del_all,
                    mmi_email_exit_del_all);
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                break;
            }
            case EMAIL_LIST_FLDR_DEL_ALL_MARK:
            {
                mmi_email_fldr_exec_curr_rsp(
                    SCR_ID_EMAIL_PROGRESS,
                    mmi_email_entry_del_all_mark,
                    mmi_email_exit_del_all_mark);
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                break;
            }
        }
    }
    else
    {
        U16 errorMessageId;

        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_DONE;
        errorMessageId = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);
        switch (email_p->fldr_info.list_fldr_cause)
        {
            case EMAIL_LIST_FLDR_NORMAL:
                mmi_email_util_display_popup(
                    (U8*) GetString(errorMessageId),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                if (IsScreenPresent(SCR_ID_EMAIL_PROGRESS))
                {
                    HistoryReplace(SCR_ID_EMAIL_PROGRESS, SCR_ID_EMAIL_MAIN, mmi_email_entry_main);
                }
                break;
            case EMAIL_LIST_FLDR_SWITCH:
                mmi_email_util_display_popup(
                    (U8*) GetString(errorMessageId),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                break;
            case EMAIL_LIST_FLDR_PROF:
                mmi_email_util_display_popup(
                    (U8*) GetString(errorMessageId),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                email_p->main_info.is_acct_change = MMI_FALSE;
                mmi_email_util_update_status_icon();
                break;
            #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            case EMAIL_LIST_FLDR_REFRESH:
                mmi_email_util_display_popup(
                    (U8*) GetString(errorMessageId),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                break;
            #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            case EMAIL_LIST_FLDR_DEL_ALL:
            case EMAIL_LIST_FLDR_DEL_ALL_MARK:
                mmi_email_util_display_popup(
                    (U8*) GetString(errorMessageId),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                break;
            case EMAIL_LIST_FLDR_BACK_MAIN:
                mmi_email_util_display_popup(
                    (U8*) GetString(errorMessageId),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                if (IsScreenPresent(SCR_ID_EMAIL_PROGRESS))
                {
                    HistoryReplace(SCR_ID_EMAIL_PROGRESS, SCR_ID_EMAIL_MAIN, mmi_email_entry_main);
                }
                break;
        }
    }
    email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_NONE;
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_select_req
 * DESCRIPTION
 *  Display progressing screen and send list folder request to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_select_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_select_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_email_folder_select_req_struct*) OslConstructDataPtr(sizeof(mmi_email_folder_select_req_struct));
    msgReq->folder = (email_folder_names_enum) email_p->main_info.curr_menu;
    msgReq->page_number = email_p->fldr_info.curr_page;

    mmi_email_entry_fldr_progress();

    AlmDisableExpiryHandler();
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_FOLDER_SELECT_REQ, msgReq, NULL);
    folder_empty = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_select_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_FOLDER_SELECT_RSP message.
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of responsed message
 * RETURNS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_select_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_select_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_email_folder_select_rsp_struct*) inMsg;

    TurnOnBacklight(1);
    AlmEnableExpiryHandler();
    email_p->misc_info.folder_select_req = MMI_FALSE;
    if (msgRsp->result == MMI_TRUE)
    {
        mmi_email_fldr_sel_rsp_hdlr(msgRsp);
    }
    else
    {
        mmi_email_util_display_err_popup(
            msgRsp->minor,
            msgRsp->major,
            mmi_email_util_get_fldr_scr_id(),
            SCR_ID_EMAIL_FLDR_LIST_PROGRESS);
        email_p->fldr_info.need_fldr_sel = FALSE;
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_REQUIRED;
        EMAIL_SET_GET_CACHE_MASK(email_p->fldr_info.curr_part_mask);
        EMAIL_SET_GET_CACHE_MASK(email_p->fldr_info.curr_get_part_mask);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_msg_select_req
 * DESCRIPTION
 *  Display progressing screen and send folder message select request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_msg_select_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_msg_select_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq =
        (mmi_email_folder_msg_select_req_struct*) OslConstructDataPtr(sizeof(mmi_email_folder_msg_select_req_struct));
    msgReq->folder = (email_folder_names_enum) email_p->main_info.curr_menu;
    msgReq->email_msg_uid = email_p->fldr_info.curr_mail_uid;
    memcpy(msgReq->part_mask, email_p->fldr_info.curr_get_part_mask, MMI_EMAIL_PART_MASK_SIZE * sizeof(kal_uint8));

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        mmi_email_util_abort_str(),
        mmi_email_util_abort_img(),
        (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_email_util_get_abort_func(),
        mmi_email_util_get_abort_func());

    AlmDisableExpiryHandler();
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_FOLDER_MSG_SELECT_REQ, msgReq, NULL);
    email_p->fldr_info.curr_sel_flag = EMAIL_SEL_GET_REQ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_msg_select_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_EMAIL_FOLDER_MSG_SELECT_RSP message.
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_msg_select_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_msg_select_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_email_folder_msg_select_rsp_struct*) inMsg;

    TurnOnBacklight(1);
    AlmEnableExpiryHandler();

    /* folder selection successfully */
    if (msgRsp->result == MMI_TRUE)
    {
        if (email_p->fldr_info.is_part_download != EMAIL_DOWN_NONE)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        mmi_email_fldr_get_msg_rsp_data(msgRsp);
    }
    else
    {   /* some error happens, may because of mail body incorrect/corrupted */
        email_p->inbox_info.read_err_msg = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);
        play_warning_tone = MMI_TRUE;
        mmi_email_fldr_exec_curr_rsp(
            SCR_ID_EMAIL_PROGRESS,
            mmi_email_entry_fldr_corrupt_mail,
            mmi_email_exit_fldr_corrupt_mail);
        EMAIL_SET_GET_CACHE_MASK(email_p->fldr_info.curr_get_part_mask);
    }

    DeleteScreenIfPresent(SCR_ID_EMAIL_FOLDER_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_EMAIL_SENT_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_UNSENT_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_DRAFT_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_INBOX_OPT);
    if (email_p->fldr_info.curr_sel_flag == EMAIL_SEL_ABT_REQ)
    {
        email_p->fldr_info.curr_sel_flag = EMAIL_SEL_ABT_NOT;
    }
    else
    {
        email_p->fldr_info.curr_sel_flag = EMAIL_SEL_GET_RSP;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_msg_mark_unread_req
 * DESCRIPTION
 *  Send request to mark unread single messages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_msg_mark_unread_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_msg_set_flag_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq =
        (mmi_email_folder_msg_set_flag_req_struct*) OslConstructDataPtr(sizeof(mmi_email_folder_msg_set_flag_req_struct));
    msgReq->email_msg_uid = email_p->fldr_info.curr_mail_uid;
    msgReq->folder_id = email_p->main_info.curr_menu;
    msgReq->msg_flag = MMI_EMAIL_MSG_FLAG_UNREAD;
    email_p->fldr_info.curr_set_flag_req = MMI_EMAIL_MSG_FLAG_UNREAD;
    email_p->fldr_info.is_part_download = EMAIL_DOWN_IMAP4;

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        mmi_email_util_abort_str(),
        mmi_email_util_abort_img(),
        (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_email_util_get_abort_func(),
        NULL);

    AlmDisableExpiryHandler();

    mmi_email_ps_send_msg(PRT_MMI_EMAIL_FOLDER_MSG_SET_FLAG_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_msg_mark_del_req
 * DESCRIPTION
 *  Send request to mark delete single messages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_msg_mark_del_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_msg_set_flag_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq =
        (mmi_email_folder_msg_set_flag_req_struct*) OslConstructDataPtr(sizeof(mmi_email_folder_msg_set_flag_req_struct));
    msgReq->email_msg_uid = email_p->fldr_info.curr_mail_uid;
    msgReq->folder_id = email_p->main_info.curr_menu;
    if (email_p->fldr_info.curr_delete_flag == MMI_TRUE)
    {
        msgReq->msg_flag = MMI_EMAIL_MSG_FLAG_UNDELETE;
        email_p->fldr_info.curr_set_flag_req = MMI_EMAIL_MSG_FLAG_UNDELETE;
    }
    else
    {
        msgReq->msg_flag = MMI_EMAIL_MSG_FLAG_DELETE;
        email_p->fldr_info.curr_set_flag_req = MMI_EMAIL_MSG_FLAG_DELETE;
    }
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        mmi_email_util_abort_str(),
        mmi_email_util_abort_img(),
        (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_email_util_get_abort_func(),
        NULL);

    AlmDisableExpiryHandler();

    mmi_email_ps_send_msg(PRT_MMI_EMAIL_FOLDER_MSG_SET_FLAG_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_msg_set_flag_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_EMAIL_FOLDER_MSG_SET_FLAG_RSP
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_msg_set_flag_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_msg_set_flag_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_email_folder_msg_set_flag_rsp_struct*) inMsg;
    TurnOnBacklight(1);
    if (msgRsp->result == MMI_TRUE)
    {
        if ((email_p->fldr_info.curr_set_flag_req == MMI_EMAIL_MSG_FLAG_DELETE) ||
            (email_p->fldr_info.curr_set_flag_req == MMI_EMAIL_MSG_FLAG_UNDELETE))
        {
            if (email_p->fldr_info.curr_delete_flag == MMI_TRUE)
            {
                email_p->fldr_info.curr_delete_flag = MMI_FALSE;
                mmi_email_folder_update_mail_state(email_p->fldr_info.curr_mail_indx, EMAIL_MS_UNDELETED);
            }
            else
            {
                email_p->fldr_info.curr_delete_flag = MMI_TRUE;
                mmi_email_folder_update_mail_state(email_p->fldr_info.curr_mail_indx, EMAIL_MS_DELETED);
            }
            email_p->fldr_info.is_part_download = EMAIL_DOWN_IMAP4;
        }
        else if ((email_p->fldr_info.curr_set_flag_req == MMI_EMAIL_MSG_FLAG_UNREAD) &&
                 (email_p->fldr_info.curr_unread_flag == MMI_FALSE))
        {
            email_p->fldr_info.curr_unread_flag = MMI_TRUE;
            mmi_email_folder_update_mail_state(email_p->fldr_info.curr_mail_indx, EMAIL_MS_UNREAD);
            email_p->main_info.unread_mails++;
            mmi_email_util_update_status_icon();
        }

        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        mmi_email_util_display_err_popup(
            msgRsp->minor,
            msgRsp->major,
            0,
            SCR_ID_EMAIL_PROGRESS);
    }
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_EMAIL_SENT_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_UNSENT_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_DRAFT_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_INBOX_OPT);
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_msg_del_req
 * DESCRIPTION
 *  Send request to delete single/all messages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_msg_del_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_msg_delete_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq =
        (mmi_email_folder_msg_delete_req_struct*) OslConstructDataPtr(sizeof(mmi_email_folder_msg_delete_req_struct));
    msgReq->delete_all = (MMI_BOOL) (EMAIL_IS_MENU(MMI_EMAIL_DEL_ALL));
    msgReq->delete_all_marked = (MMI_BOOL) (EMAIL_IS_MENU(MMI_EMAIL_DEL_ALL_MARK));
    if ((msgReq->delete_all_marked) && email_p->del_info.del_all_fldr)
    {
        for (; email_p->del_info.curr_del_fldr < EMAIL_DEL_ALL_FOLDER_ENUM; email_p->del_info.curr_del_fldr++)
        {
            if (email_p->fldr_info.fldr_data[email_p->del_info.curr_del_fldr].num_mark_del_mails == 0)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (email_p->del_info.curr_del_fldr == EMAIL_DEL_ALL_FOLDER_ENUM)
        {
            mmi_email_del_all_mark_folders();
            return;
        }
    }
    else if ((msgReq->delete_all) && email_p->del_info.del_all_fldr)
    {
        for (; email_p->del_info.curr_del_fldr < EMAIL_DEL_ALL_FOLDER_ENUM; email_p->del_info.curr_del_fldr++)
        {
            if (email_p->fldr_info.fldr_data[email_p->del_info.curr_del_fldr].total_mails == 0)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (email_p->del_info.curr_del_fldr == EMAIL_DEL_ALL_FOLDER_ENUM)
        {
            mmi_email_del_all_folders();
            return;
        }
    }
    msgReq->folder = (email_folder_names_enum) email_p->del_info.curr_del_fldr;
    msgReq->email_msg_uid = email_p->fldr_info.curr_mail_uid;
    if ((email_p->fldr_info.list_fldr_cause == MMI_EMAIL_DEL_ALL_MARK) ||
        (email_p->fldr_info.list_fldr_cause == MMI_EMAIL_DEL_ALL))
    {
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    }

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        mmi_email_util_abort_str(),
        mmi_email_util_abort_img(),
        (U8*) GetString(STR_EMAIL_COMMON_DELETING_ID),
        (U8*) NULL,
        IMG_GLOBAL_DELETED,
        NULL,
        mmi_email_util_get_abort_func(),
        NULL);

    AlmDisableExpiryHandler();

    email_p->misc_info.delete_req = MMI_TRUE;
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_FOLDER_MSG_DELETE_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_folder_msg_del_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_EMAIL_FOLDER_MSG_DELETE_RSP
 *  If it's from each folder, go back to folder list
 *  else if previous operation is to delete all folders, proceed next folder.
 *  else go back to Delete All menu.
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_folder_msg_del_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_folder_msg_delete_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_email_folder_msg_delete_rsp_struct*) inMsg;

    TurnOnBacklight(1);
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    email_p->fldr_info.need_fldr_sel = TRUE;
    email_p->misc_info.delete_req = MMI_FALSE;
    if (msgRsp->result == MMI_TRUE)
    {
        if (EMAIL_IS_MENU(MMI_EMAIL_DEL_ALL_MARK))
        {
            if (email_p->del_info.del_all_fldr) /* delete all mails in all folders */
            {
                email_p->fldr_info.fldr_data[email_p->del_info.curr_del_fldr].num_mark_del_mails = 0;
                email_p->del_info.curr_del_fldr++;
                mmi_email_del_all_mark_folders();
            }
            else
            {
                U16 delScrnId;

                if (EMAIL_IS_MENU(MMI_EMAIL_DEL_ALL_MARK))     /* delete all mails in one folder */
                {
                    email_p->fldr_info.fldr_data[email_p->del_info.curr_del_fldr].num_mark_del_mails = 0;
                    mmi_email_util_display_popup(
                        (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) SUCCESS_TONE);
                    GetNextScrnIdOf(SCR_ID_EMAIL_DELETE_ALL, &delScrnId);
                }
                mmi_email_util_del_between_scr(delScrnId, SCR_ID_EMAIL_PROGRESS);
            }
        }
        else
        {
            if (email_p->del_info.del_all_fldr) /* delete all mails in all folders */
            {
                email_p->fldr_info.fldr_data[email_p->del_info.curr_del_fldr].total_mails = 0;
                email_p->del_info.curr_del_fldr++;
                mmi_email_del_all_folders();
            }
            else
            {
                U16 delScrnId;

                if (EMAIL_IS_MENU(MMI_EMAIL_DEL_ALL))  /* delete all mails in one folder */
                {
                    if (email_p->del_info.curr_del_fldr == MMI_EMAIL_INBOX)
                    {
                        email_p->main_info.unread_mails = 0;
                        mmi_email_util_update_status_icon();
                    }

                    email_p->fldr_info.fldr_data[email_p->del_info.curr_del_fldr].total_mails = 0;
                    mmi_email_util_display_popup(
                        (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) SUCCESS_TONE);
                    GetNextScrnIdOf(SCR_ID_EMAIL_DELETE_ALL, &delScrnId);
                }
                else    /* delete single mail */
                {
                    if (email_p->fldr_info.curr_unread_flag == MMI_TRUE)
                    {
                        email_p->main_info.unread_mails--;
                        mmi_email_util_update_status_icon();
                    }
                    mmi_email_fldr_update_page_num();
                    mmi_email_util_display_popup(
                        (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) SUCCESS_TONE);
                    delScrnId = mmi_email_fldr_get_start_scr();
                }

                mmi_email_util_del_between_scr(delScrnId, SCR_ID_EMAIL_PROGRESS);
            }
        }
    }
    else
    {
        email_p->del_info.del_all_fldr = FALSE;
        if ((EMAIL_IS_MENU(MMI_EMAIL_DEL_ALL)) ||
            (EMAIL_IS_MENU(MMI_EMAIL_DEL_ALL_MARK)))
        {
            U16 startSrcnId;

            GetNextScrnIdOf(SCR_ID_EMAIL_DELETE_ALL, &startSrcnId);
            mmi_email_util_display_err_popup(
                msgRsp->minor,
                msgRsp->major,
                startSrcnId,
                SCR_ID_EMAIL_PROGRESS);
        }
        else
        {
            mmi_email_util_display_err_popup(
                msgRsp->minor,
                msgRsp->major,
                mmi_email_fldr_get_start_scr(),
                SCR_ID_EMAIL_PROGRESS);
        }
    }
    mmi_email_util_update_status_icon();
    AlmEnableExpiryHandler();
}

#define SNR_PS_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_snr_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_snr_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->snr_info.snr_state = EMAIL_SNR_ABORTING;
    mmi_email_ps_abort_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_snr_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_SEND_RECV_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_snr_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&email_p->snr_info, 0, sizeof(mmi_email_snr_info_struct));

    email_p->snr_info.snr_state = EMAIL_SNR_CONN_SMTP;

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_EMAIL_CONNECTING_TO_OUTGOING_SERVER_ID),
        (U8*) NULL,
        IMG_EMAIL_CONNECTING_ID,
        NULL,
        mmi_email_snr_abort,
        NULL);

    AlmDisableExpiryHandler();

    mmi_email_ps_send_msg(PRT_MMI_EMAIL_SEND_RECV_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_snr_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_EMAIL_SEND_RECV_RSP
 * PARAMETERS
 *  inMsg       [IN]        Message struct to store the result, currently it's no usage.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_snr_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_server_conn_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_SERVER_CONNECT_IND.
 * PARAMETERS
 *  inMsg       [IN]        Message struct to store data, currently it's no usage.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_server_conn_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
    {
        if (email_p->snr_info.snr_state == EMAIL_SNR_CONN_SMTP)
        {
            email_p->snr_info.snr_state = EMAIL_SNR_SENDING;
            mmi_email_pre_entry_progressing(
                STR_EMAIL_SENDING_ID,
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
                0,
                0,
                STR_GLOBAL_CANCEL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_EMAIL_SENDING_ID),
                (U8*) NULL,
                IMG_EMAIL_SENDING_ID,
                NULL,
                mmi_email_snr_abort,
                NULL);
        }
        else
        {
            email_p->snr_info.snr_state = EMAIL_SNR_AUTH;
            mmi_email_pre_entry_progressing(
                STR_EMAIL_AUTHORIZING_ID,
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
                0,
                0,
                STR_GLOBAL_CANCEL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_EMAIL_VERIFYING_USERNAME_ID),
                (U8*) GetString(STR_EMAIL_VERIFYING_PASSOWRD_ID),
                IMG_EMAIL_CONNECTING_ID,
                NULL,
                mmi_email_snr_abort,
                NULL);
        }
    }
    memset(&email_p->snr_info.recv_buff, 0, EMAIL_MAX_SNR_RESULT_LEN * sizeof(UI_character_type));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_msg_sent_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_MSG_SENT_IND.
 *  Update display buffer of progressing screen.
 * PARAMETERS
 *  inMsg       [IN]        Message struct to store data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_msg_sent_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    U8 *tmp_buff = OslMalloc(EMAIL_MAX_SNR_RESULT_LEN * ENCODING_LENGTH);

    mmi_email_msg_sent_ind_struct *sentInd = (mmi_email_msg_sent_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->snr_info.num_sent = sentInd->sent_mails;
    sprintf((S8*) tmp_buff, "(%d/%d)", sentInd->sent_mails, sentInd->total_mails);

    len = strlen((S8*) tmp_buff);
    mmi_asc_n_to_ucs2((S8*) email_p->snr_info.sent_buff, (S8*) tmp_buff, len);
    email_p->snr_info.sent_buff[len] = 0x0000;  /* null terminate */

    if (email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
    {
        mmi_email_pre_entry_progressing(
            STR_EMAIL_SENDING_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            (U8*) GetString(STR_EMAIL_SENDING_ID),
            (U8*) email_p->snr_info.sent_buff,
            IMG_EMAIL_SENDING_ID,
            NULL,
            mmi_email_snr_abort,
            NULL);
    }

    OslMfree(tmp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_num_msgs_sent_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_NUM_MSGS_SENT_IND.
 *  Update display buffer of progressing screen.
 *  Change state from sending to receiving.
 * PARAMETERS
 *  inMsg       [IN]        Message struct to store data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_num_msgs_sent_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_num_msgs_ind_struct *msgRsp = (mmi_email_num_msgs_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->snr_info.num_to_be_sent = msgRsp->total_mails;

    if (msgRsp->result == MMI_TRUE)
    {
        email_p->snr_info.num_sent = msgRsp->num_new_mails;

        if (email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
        {
            email_p->fldr_info.fldr_data[MMI_EMAIL_SENT].num_unread_mails += msgRsp->num_new_mails;
        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            if (EMAIL_IS_PROT(EMAIL_PROT_POP3))
        #endif 
                email_p->fldr_info.fldr_data[MMI_EMAIL_SENT].total_mails += msgRsp->num_new_mails;

            mmi_email_main_update_hint(MMI_EMAIL_SENT);
        }
    }
    else
    {
        email_p->snr_info.sent_err_str = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);
    }

    if (email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
    {
        /* success or not, always change state to connecting */
        email_p->snr_info.snr_state = EMAIL_SNR_CONN_POP3;
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        if (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4)
        {
            mmi_email_pre_entry_progressing(
                STR_EMAIL_MAIN_ID,
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
                0,
                0,
                STR_GLOBAL_CANCEL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_EMAIL_CONNECTING_TO_INCOMING_SERVER_IMAP4_ID),
                (U8*) NULL,
                IMG_EMAIL_CONNECTING_ID,
                NULL,
                mmi_email_snr_abort,
                NULL);
        }
        else
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            mmi_email_pre_entry_progressing(
                STR_EMAIL_MAIN_ID,
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
                0,
                0,
                STR_GLOBAL_CANCEL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_EMAIL_CONNECTING_TO_INCOMING_SERVER_POP3_ID),
                (U8*) NULL,
                IMG_EMAIL_CONNECTING_ID,
                NULL,
                mmi_email_snr_abort,
                NULL);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_authverify_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_AUTHVERIFY_IND.
 *  Update display buffer of progressing screen.
 *  Change state from connecting to authr
 * PARAMETERS
 *  inMsg       [IN]        Message struct to store data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_authverify_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->snr_info.snr_state = EMAIL_SNR_RECVING;

    if (email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
    {
        mmi_email_pre_entry_progressing(
            STR_EMAIL_RECEIVING_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            (U8*) GetString(STR_EMAIL_RECEIVING_ID),
            NULL,
            IMG_EMAIL_RECEIVING_ID,
            NULL,
            mmi_email_snr_abort,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_recv_msgs_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_RECV_MSGS_IND.
 *  Update display buffer of progressing screen.
 * PARAMETERS
 *  inMsg       [IN]        Message struct to store data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_recv_msgs_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    U32 num_to_receive;
    S8 *tmp_buff = OslMalloc(EMAIL_MAX_SNR_RESULT_LEN * ENCODING_LENGTH);
    mmi_email_recv_msgs_ind_struct *recvMsgsInd = (mmi_email_recv_msgs_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->snr_info.num_recv = recvMsgsInd->received_mails;
    if (email_p->snr_info.num_to_be_recv != 0)
    {
        email_p->main_info.unread_mails++;
    }
    email_p->snr_info.num_to_be_recv = recvMsgsInd->total_mails + recvMsgsInd->num_exceeded_mails;
    num_to_receive = 
        (email_p->snr_info.num_to_be_recv < (U32)email_get_max_num()) ? (email_p->snr_info.num_to_be_recv) : ((U32)email_get_max_num());
#ifdef __MMI_EMAIL_RECEIVING_NUM_IND__
    if (email_p->snr_info.num_recv < num_to_receive)
#endif 
    {
    #ifdef __MMI_EMAIL_RECEIVING_NUM_IND__
        sprintf((S8*) tmp_buff, "(%u/%u)", email_p->snr_info.num_recv + 1, email_p->snr_info.num_to_be_recv);
    #else 
        sprintf((S8*) tmp_buff, "(%u/%u)", email_p->snr_info.num_recv, email_p->snr_info.num_to_be_recv);
    #endif 
        len = strlen((S8*) tmp_buff);
        mmi_asc_n_to_ucs2((S8*) email_p->snr_info.recv_buff, (S8*) tmp_buff, len);
        if (email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
        {
            mmi_email_pre_entry_progressing(
                STR_EMAIL_RECEIVING_ID,
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
                0,
                0,
                STR_GLOBAL_CANCEL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_EMAIL_RECEIVING_ID),
                (U8*) email_p->snr_info.recv_buff,
                IMG_EMAIL_RECEIVING_ID,
                NULL,
                mmi_email_snr_abort,
                NULL);
        }
        if (email_p->snr_info.num_recv != 0)
        {
            mmi_email_util_update_status_icon();
        }
    }
    OslMfree(tmp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_new_msgs_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_NEW_MSGS_IND.
 *  Update display buffer of progressing screen.
 *  Result screen is displayed in this function.
 * PARAMETERS
 *  inMsg       [IN]        Message struct to store data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_new_msgs_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_new_msgs_ind_struct *msgRsp = (mmi_email_new_msgs_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update number of received mails regardless result is successful or not 
       because some mails may be received though some error happens */
    email_p->snr_info.num_recv = msgRsp->num_new_mails;
    email_p->snr_info.num_to_be_recv = msgRsp->total_mails + msgRsp->num_exceeded_mails;
    /* email_p->main_info.unread_mails += msgRsp->num_new_mails; */
    if (mmi_email_bearer_status_show_icon())
    {
        mmi_email_util_update_status_icon();
    }
    mmi_email_main_update_hint(MMI_EMAIL_INBOX);

    if (msgRsp->result != MMI_TRUE)
    {
        email_p->snr_info.recv_err_str = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);
    }

    /* list folder is required if list folder is not executed yet or number of emails is changed */
    if (email_p->fldr_info.fldr_update_state == EMAIL_LIST_FLDR_REQUIRED ||
        email_p->snr_info.num_recv > 0 || email_p->snr_info.num_sent > 0)
    {
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
        email_p->fldr_info.need_fldr_sel = TRUE;
    }
    else
    {
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_NOT_REQUIRED;
        email_p->fldr_info.need_fldr_sel = FALSE;
    }

    AlmEnableExpiryHandler();

    email_p->snr_info.snr_state = EMAIL_SNR_IDLE;

#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    if (email_p->snr_info.is_auto_chk == TRUE)
    {
        /* it's not in email application */
        if (email_p->main_info.stop_cause != EMAIL_MODULE_ACTIVE_NOW)
        {
            email_p->snr_info.is_auto_chk = FALSE;
            return;
        }
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 

    if (
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
           (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_POP3) &&
#endif 
           (email_p->main_info.is_mem_full) && (!email_p->snr_info.recv_err_str))
    {
        email_p->snr_info.recv_err_str = STR_EMAIL_MEMORY_FULL_ID;
    }
    else if ((email_p->main_info.is_uidl_full) && (!email_p->snr_info.recv_err_str))
    {
        email_p->snr_info.recv_err_str = STR_EMAIL_UIDL_FULL_ID;
        email_p->main_info.is_uidl_full = MMI_FALSE;
    }

    /* directly display detail result screen */
    DeleteScreenIfPresent(SCR_ID_EMAIL_SNR_DETAIL);
    if (GetExitScrnID() == SCR_ID_EMAIL_SNR_DETAIL)
    {
        GoBackHistory();
    }
    if (mmi_email_util_is_call_interrupt_allow())
    {
        mmi_email_entry_snr_detail();
        TurnOnBacklight(1);
    }
    else
    {
        mmi_frm_add_history_before_cm_marker(SCR_ID_EMAIL_SNR_DETAIL, mmi_email_entry_snr_detail);
    }
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    if (email_p->snr_info.is_auto_chk == TRUE)
    {
        email_p->snr_info.is_auto_chk = FALSE;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
}

#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_auto_chk_ind
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_AUTOCHECK_EXPIRY_IND.
 * PARAMETERS
 *  inMsg       [IN]        Message struct to store data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_auto_chk_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_AUTOCHECK_EXPIRY_IND, email_p->main_info.stop_cause);

#ifdef __MMI_EMAIL_OTAP__
    if((mmi_email_is_in_otap == MMI_TRUE) && 
        (mmi_email_is_autochk_at_otap_begin == MMI_TRUE))
    {
        mmi_email_ps_abort_req();
        return;
    }
#endif /*__MMI_EMAIL_OTAP__*/

    /* TurnOnBacklight(TRUE); */

    /* reset context */
    memset(&email_p->snr_info, 0, sizeof(mmi_email_snr_info_struct));

    if (email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
    {
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
        email_p->fldr_info.need_fldr_sel = TRUE;
        email_p->snr_info.snr_state = EMAIL_SNR_CONN_SMTP;

        mmi_email_pre_entry_progressing(
            STR_EMAIL_CONNECTING_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            (U8*) GetString(STR_EMAIL_CONNECTING_TO_OUTGOING_SERVER_ID),
            (U8*) NULL,
            IMG_EMAIL_CONNECTING_ID,
            NULL,
            mmi_email_snr_abort,
            NULL);

        AlmDisableExpiryHandler();
        if (mmi_email_util_is_call_interrupt_allow())
        {
            mmi_email_util_set_insert_history_flag(TRUE);
            mmi_email_exit_progressing();
        }
    }
    email_p->snr_info.is_auto_chk = TRUE;
}
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 

#define SEND_SAVE_PS_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_compose_size_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_COMPOSE_SIZE_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_compose_size_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_compose_size_req_struct *msgReq;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct email */
    msgReq = (mmi_email_compose_size_req_struct*) OslConstructDataPtr(sizeof(mmi_email_compose_size_req_struct));
    memset(&msgReq->email_msg, 0, sizeof(email_msg_info_struct));
    /* just for test */
    if (email_p->comp_info.total_attch > MMI_EMAIL_MAX_NUM_ATTACH)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_UNKNOWN_ID),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    if ((result = mmi_email_ps_compose_fill_msg_struct(&msgReq->email_msg)) != FS_NO_ERROR)
    {
        OslMfree(msgReq);
        mmi_email_util_display_popup(
            (U8*) GetString((U16)GetFileSystemErrorString(result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);
    AlmDisableExpiryHandler();

    mmi_email_ps_send_msg(PRT_MMI_EMAIL_COMPOSE_SIZE_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_compose_size_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_COMPOSE_SIZE_RSP message
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_compose_size_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_compose_size_rsp_struct *msgRsp = (mmi_email_compose_size_rsp_struct*) inMsg;
    S8 *asciiMaxString = OslMalloc(10);
    S8 *ucs2MaxString = OslMalloc(10 * ENCODING_LENGTH);
    U16 errMsgId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    if (msgRsp->result == MMI_TRUE)
    {
        if (email_p->misc_info.str_compose_size != NULL)
        {
            OslMfree(email_p->misc_info.str_compose_size);
            email_p->misc_info.str_compose_size = NULL;
        }
        email_p->misc_info.str_compose_size = OslMalloc(60);
        kal_mem_set(email_p->misc_info.str_compose_size, 0, 60);
        sprintf((S8*) asciiMaxString, ":\n%uKB", (U32) (msgRsp->msg_size + 1023) / 1024);

        mmi_ucs2cpy((S8*) email_p->misc_info.str_compose_size, (S8*) GetString(STR_EMAIL_COMPOSE_SIZE_SEND_ID));
        mmi_asc_to_ucs2((S8*) ucs2MaxString, (S8*) asciiMaxString);
        mmi_ucs2cat((S8*) email_p->misc_info.str_compose_size, (S8*) ucs2MaxString);
        play_warning_tone = MMI_TRUE;
        mmi_email_display_confirm_ex();
    }
    else
    {
        errMsgId = mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major);
        mmi_email_util_display_popup(
            (U8*) GetString(errMsgId),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    }
    OslMfree(asciiMaxString);
    OslMfree(ucs2MaxString);
    mmi_email_util_rename_to_compose();

    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_send_only_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_SEND_ONLY_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_send_only_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 i = 0, j = 0;
    mmi_email_send_only_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check email address */
    if (!mmi_email_comp_is_addr_present())
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    for (; i < EMAIL_ADDR_FROM; i++)
    {
        for (j = 0; j < email_p->comp_info.addr_list[i].num_addr; j++)
        {
            if (!mmi_email_util_chk_addr((U8*) email_p->comp_info.addr_list[i].to_cc_mail[j]))
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID),
                    IMG_GLOBAL_ERROR,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                return;
            }
        }
    }
    /* construct email */
    msgReq = (mmi_email_send_only_req_struct*) OslConstructDataPtr(sizeof(mmi_email_send_only_req_struct));
    memset(&msgReq->email_msg, 0, sizeof(email_msg_info_struct));
    if ((result = mmi_email_ps_compose_fill_msg_struct(&msgReq->email_msg)) != FS_NO_ERROR)
    {
        OslMfree(msgReq);
        mmi_email_util_display_popup(
            (U8*) GetString((U16)GetFileSystemErrorString(result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_EMAIL_COMP_OPT);
        return;
    }

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_EMAIL_SENDING_ID),
        (U8*) NULL,
        IMG_EMAIL_SENDING_ID,
        NULL,
        mmi_email_ps_abort_req,
        NULL);

    AlmDisableExpiryHandler();

    is_sending_mails = MMI_TRUE;
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_SEND_ONLY_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_send_only_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_SEND_ONLY_RSP message
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_send_only_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_send_only_rsp_struct *msgRsp = (mmi_email_send_only_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    email_p->fldr_info.need_fldr_sel = TRUE;
    is_sending_mails = MMI_FALSE;

    if (msgRsp->result == MMI_TRUE)
    {
        mmi_email_comp_reset_member();
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_COMMON_SENT_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), SCR_ID_EMAIL_PROGRESS);
    }
    else
    {
        if (!msgRsp->is_sent && msgRsp->is_saved)
        {
            /* send failed, save successfully, go back to main menu */
            mmi_email_comp_reset_member();
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_SEND_FAILED_SAVE_SUCCESS_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);

            mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), SCR_ID_EMAIL_PROGRESS);
        }
        else
        {
            S32 i, j;

            mmi_email_util_display_popup(
                (U8*) GetString(mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);

            mmi_email_util_del_between_scr(SCR_ID_EMAIL_COMP_OPT, SCR_ID_EMAIL_PROGRESS);
            /* rollback attachment file */
            for (i = 0, j = 1; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
            {
                if (email_p->comp_info.attch_list[i].attch_present)
                {
                    mmi_email_util_rename_after_abort((U8) j, (S8*) email_p->comp_info.attch_list[i].file_path);
                    j++;
                }
            }
        }
    }
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_save_and_send_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_SEND_NOW_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_save_and_send_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 i = 0, j = 0;
    mmi_email_send_now_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check email address */
    if (!mmi_email_comp_is_addr_present())
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    for (; i < EMAIL_ADDR_FROM; i++)
    {
        for (j = 0; j < email_p->comp_info.addr_list[i].num_addr; j++)
        {
            if (!mmi_email_util_chk_addr((U8*) email_p->comp_info.addr_list[i].to_cc_mail[j]))
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID),
                    IMG_GLOBAL_ERROR,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                return;
            }
        }
    }
    /* construct email */
    msgReq = (mmi_email_send_now_req_struct*) OslConstructDataPtr(sizeof(mmi_email_send_now_req_struct));
    memset(&msgReq->email_msg, 0, sizeof(email_msg_info_struct));
    if ((result = mmi_email_ps_compose_fill_msg_struct(&msgReq->email_msg)) != FS_NO_ERROR)
    {
        OslMfree(msgReq);
        mmi_email_util_display_popup(
            (U8*) GetString((U16)GetFileSystemErrorString(result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_EMAIL_COMP_OPT);
        return;
    }
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_EMAIL_SENDING_ID),
        (U8*) NULL,
        IMG_EMAIL_SENDING_ID,
        NULL,
        mmi_email_ps_abort_req,
        NULL);

    AlmDisableExpiryHandler();

    is_sending_mails = MMI_TRUE;
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_SEND_NOW_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_save_and_send_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_SEND_NOW_RSP message
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_save_and_send_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_send_now_rsp_struct *msgRsp = (mmi_email_send_now_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    email_p->fldr_info.need_fldr_sel = TRUE;
    is_sending_mails = MMI_FALSE;

    /* failed only when both sent and saved failed */
    if (!msgRsp->is_sent && !msgRsp->is_saved)
    {
        S32 i, j;

        /* both send and save failed, go back to option screen */
        mmi_email_util_display_popup(
            (U8*) GetString(mmi_email_util_get_err_code(msgRsp->minor, msgRsp->major)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        mmi_email_util_del_between_scr(SCR_ID_EMAIL_COMP_OPT, SCR_ID_EMAIL_PROGRESS);
        /* rollback attachment file */
        for (i = 0, j = 1; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
        {
            if (email_p->comp_info.attch_list[i].attch_present)
            {
                mmi_email_util_rename_after_abort((U8) j, (S8*) email_p->comp_info.attch_list[i].file_path);
                j++;
            }
        }
    }
    else
    {
        if (msgRsp->is_sent && msgRsp->is_saved)
        {
            /* both send and save success, go back to main menu */
            mmi_email_comp_reset_member();
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_SEND_SUCCESS_SAVE_SUCCESS_ID),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
        }
        else if (msgRsp->is_sent && !msgRsp->is_saved)
        {
            /* send success, save failed, go back to main menu */
            mmi_email_comp_reset_member();
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_SEND_SUCCESS_SAVE_FAILED_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }
        else if (!msgRsp->is_sent && msgRsp->is_saved)
        {
            mmi_email_comp_reset_member();
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_SEND_FAILED_SAVE_SUCCESS_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }
        mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), SCR_ID_EMAIL_PROGRESS);
    }
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_save_to_draft_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_SAVE_DRAFTS_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_save_to_draft_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    mmi_email_save_drafts_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct email */
    msgReq = (mmi_email_save_drafts_req_struct*) OslConstructDataPtr(sizeof(mmi_email_save_drafts_req_struct));
    memset(&msgReq->email_msg, 0, sizeof(email_msg_info_struct));
    if ((result = mmi_email_ps_compose_fill_msg_struct(&msgReq->email_msg)) != FS_NO_ERROR)
    {
        OslMfree(msgReq);
        mmi_email_util_display_popup(
            (U8*) GetString((U16)GetFileSystemErrorString(result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_EMAIL_COMP_OPT);
        return;
    }

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        mmi_email_util_abort_str(),
        mmi_email_util_abort_img(),
        (U8*) GetString(STR_GLOBAL_SAVING),
        (U8*) NULL,
        IMG_GLOBAL_SAVE,
        NULL,
        mmi_email_util_get_abort_func(),
        NULL);

    AlmDisableExpiryHandler();

    is_sending_mails = MMI_TRUE;
    mmi_email_ps_send_msg(PRT_MMI_EMAIL_SAVE_DRAFTS_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_save_to_draft_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_SAVE_DRAFTS_RSP message
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_save_to_draft_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_save_drafts_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_email_save_drafts_rsp_struct*) inMsg;
    is_sending_mails = MMI_FALSE;

    TurnOnBacklight(1);
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    email_p->fldr_info.need_fldr_sel = TRUE;
    if (msgRsp->result == MMI_TRUE)
    {
        mmi_email_comp_reset_member();
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        if (email_p->other_app_info.app_param.is_save_to_draft == MMI_TRUE)
        {           
            DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
            email_p->other_app_info.app_param.is_save_to_draft = MMI_FALSE;
            
            mmi_email_main_quit_to_app();
        }        
        else
        {
            mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), SCR_ID_EMAIL_PROGRESS);
        }
    }
    else
    {
        S32 i, j;

        mmi_email_util_display_err_popup(
            msgRsp->minor,
            msgRsp->major,
            mmi_email_fldr_get_start_scr(),
            SCR_ID_EMAIL_PROGRESS);
        if (is_sending_mails)
        {
            /* rollback attachment file */
            for (i = 0, j = 1; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
            {
                if (email_p->comp_info.attch_list[i].attch_present)
                {
                    mmi_email_util_rename_after_abort((U8) j, (S8*) email_p->comp_info.attch_list[i].file_path);
                    j++;
                }
            }
        }
    }
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_move_to_draft_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_MSG_MOVE_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_move_to_draft_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_msg_move_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_email_msg_move_req_struct*) OslConstructDataPtr(sizeof(mmi_email_msg_move_req_struct));
    msgReq->src_folder = (email_folder_names_enum) MMI_EMAIL_UNSENT;
    msgReq->dest_folder = (email_folder_names_enum) MMI_EMAIL_DRAFT;
    msgReq->email_msg_uid = email_p->fldr_info.curr_mail_uid;

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_EMAIL_COMMON_MOVING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_email_ps_abort_req,
        NULL);

    AlmDisableExpiryHandler();

    mmi_email_ps_send_msg(PRT_MMI_EMAIL_MSG_MOVE_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_move_to_draft_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_MSG_MOVE_RSP message
 * PARAMETERS
 *  inMsg       [IN]        Struct variable of response message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_move_to_draft_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_msg_move_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_email_msg_move_rsp_struct*) inMsg;

    TurnOnBacklight(1);
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    email_p->fldr_info.need_fldr_sel = TRUE;
    if (msgRsp->result == MMI_TRUE)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), SCR_ID_EMAIL_PROGRESS);
        email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails--;
    }
    else
    {
        mmi_email_util_display_err_popup(
            msgRsp->minor,
            msgRsp->major,
            mmi_email_fldr_get_start_scr(),
            SCR_ID_EMAIL_PROGRESS);
    }
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_send_from_mailbox_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_EMAIL_SEND_FROM_MAILBOX_REQ to Email
 * PARAMETERS
 *  needSave        [IN]        Flag to indicate Save and Send or Send.
 *  TRUE == Save and Send; otherwisem Send(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_send_from_mailbox_req(BOOL needSave)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_send_from_mailbox_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq =
        (mmi_email_send_from_mailbox_req_struct*) OslConstructDataPtr(sizeof(mmi_email_send_from_mailbox_req_struct));
    msgReq->folder_id = MMI_EMAIL_UNSENT;   /* currently, only Outbox use this function */
    msgReq->need_save = (MMI_BOOL) needSave;
    msgReq->email_msg_uid = email_p->fldr_info.curr_mail_uid;

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_EMAIL_SENDING_ID),
        (U8*) NULL,
        IMG_EMAIL_SENDING_ID,
        NULL,
        mmi_email_ps_abort_req,
        NULL);
    AlmDisableExpiryHandler();

    mmi_email_ps_send_msg(PRT_MMI_EMAIL_SEND_FROM_MAILBOX_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_send_from_mailbox_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EMAIL_SEND_FROM_MAILBOX_RSP
 * PARAMETERS
 *  inMsg       [IN]        Result of the message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_send_from_mailbox_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_send_from_mailbox_rsp_struct *msgRsp = (mmi_email_send_from_mailbox_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);

    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    email_p->fldr_info.need_fldr_sel = TRUE;

    if (msgRsp->result == MMI_TRUE)
    {
        mmi_email_fldr_update_page_num();
        if (msgRsp->is_sent && msgRsp->is_saved)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_SEND_SUCCESS_SAVE_SUCCESS_ID),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_COMMON_SENT_ID),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), SCR_ID_EMAIL_PROGRESS);
    }
    else
    {
        if (msgRsp->is_sent && !msgRsp->is_saved)
        {
            mmi_email_fldr_update_page_num();
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_SEND_SUCCESS_SAVE_FAILED_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), SCR_ID_EMAIL_PROGRESS);
        }
        else if (!msgRsp->is_sent && msgRsp->is_saved)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_SEND_FAILED_SAVE_SUCCESS_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), SCR_ID_EMAIL_PROGRESS);
        }
        else if (!msgRsp->is_sent && !msgRsp->is_saved)
        {
            mmi_email_util_display_err_popup(
                msgRsp->minor,
                msgRsp->major,
                mmi_email_fldr_get_start_scr(),
                SCR_ID_EMAIL_PROGRESS);
        }
    }
    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_update_page_num
 * DESCRIPTION
 *  Update page number after any changed folder operations
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_update_page_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails != 0)
    {
        email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails--;
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        if (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4 && email_p->main_info.curr_menu != MMI_EMAIL_UNSENT)
        {
            if (email_p->fldr_info.fldr_list.num_msgs != 0)
            {
                email_p->fldr_info.fldr_list.num_msgs--;
                if (!email_p->fldr_info.fldr_list.num_msgs)
                {
                    if (email_p->fldr_info.curr_page != 0)
                    {
                        email_p->fldr_info.curr_page--;
                    }
                }
            }
        }
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_is_addr_present
 * DESCRIPTION
 *  Check the presence of Email address
 * PARAMETERS
 *  void
 * RETURNS
 *  If one of To/CC presents, return TURE; otherwise, return FALSE.
 *****************************************************************************/
S8 mmi_email_comp_is_addr_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr != 0 ||
        email_p->comp_info.addr_list[EMAIL_ADDR_CC].num_addr != 0
#ifdef __MMI_EMAIL_BCC__
        || email_p->comp_info.addr_list[EMAIL_ADDR_BCC].num_addr != 0
#endif 
        )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


#define MSG_STRUCT_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_compose_fill_msg_struct
 * DESCRIPTION
 *  Fill message structure for a mail to be sent/saved.
 * PARAMETERS
 *  emailMsg        [IN/OUT]        Address to store data of a mail.
 * RETURNS
 *  Error cause from file system.
 *****************************************************************************/
S32 mmi_email_ps_compose_fill_msg_struct(email_msg_info_struct *emailMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Content */
    if ((result = mmi_email_ps_compose_fill_cont(&emailMsg->total_text_msgs, (mmi_email_msg*) emailMsg->text_msgs)) != FS_NO_ERROR)
    {
        return result;
    }

    /* Attachment */
    if ((result = mmi_email_ps_compose_fill_attach(
                    &emailMsg->total_attachments,
                    (email_attach_struct*) emailMsg->attach)) != FS_NO_ERROR)
    {
        return result;
    }

    /* Subject */
    mmi_email_ps_compose_fill_subj(&emailMsg->subject_len, (U8*) emailMsg->subject, &emailMsg->charset_subject);

    /* To */
    if ((result = mmi_email_ps_compose_fill_addr(&emailMsg->total_to_address, EMAIL_ADDR_TO)) != FS_NO_ERROR)
    {
        return result;
    }

    /* CC */
    if ((result = mmi_email_ps_compose_fill_addr(&emailMsg->total_cc_address, EMAIL_ADDR_CC)) != FS_NO_ERROR)
    {
        return result;
    }

#ifdef __MMI_EMAIL_BCC__
    /* BCC */
    if ((result = mmi_email_ps_compose_fill_addr(&emailMsg->total_bcc_address, EMAIL_ADDR_BCC)) != FS_NO_ERROR)
    {
        return result;
    }
#endif /* __MMI_EMAIL_BCC__ */ 

    /* priority */
    mmi_email_ps_compose_fill_priority(&emailMsg->priority);

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_compose_fill_priority
 * DESCRIPTION
 *  Fill priority data for a sending mail
 * PARAMETERS
 *  priority        [IN/OUT]        Address to priority value
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_ps_compose_fill_priority(U8 *priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->comp_info.priority_indx == 0)
    {
        *priority = MMI_EMAIL_NORMAL_PRIORITY;
    }
    else if (email_p->comp_info.priority_indx == 1)
    {
        *priority = MMI_EMAIL_LOW_PRIORITY;
    }
    else
    {
        *priority = MMI_EMAIL_HIGH_PRIORITY;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_compose_fill_subj
 * DESCRIPTION
 *  Fill subject structure for a mail to be sent/saved.
 * PARAMETERS
 *  subjectLenPtr       [IN/OUT]        Length of subject
 *  subjectDataPtr      [IN/OUT]        Address to store the result of converted
 *  ch_set              [IN/OUT]        Address to store the chaset
 * RETURNS
 *  Error cause from file system.(?)(?)
 *****************************************************************************/
void mmi_email_ps_compose_fill_subj(U8 *subjectLenPtr, U8 *subjectDataPtr, S32 *ch_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *tempPtr;
    U16 inLen;
    U16 outLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *subjectLenPtr = (U8) 0;
    *ch_set = MMI_CHSET_UTF8;
    inLen = (U16) mmi_ucs2strlen((S8*) email_p->comp_info.subj_buff) * ENCODING_LENGTH;
    if (inLen != 0)
    {
        tempPtr = mmi_email_util_ucs2_to_chset((U8*) email_p->comp_info.subj_buff, inLen, (U8) (*ch_set), &outLen);

        if (tempPtr != NULL)
        {
            --outLen;
            *subjectLenPtr = (U8) outLen;
            memcpy(subjectDataPtr, tempPtr, outLen);
            subjectDataPtr[outLen] = 0;
            OslMfree(tempPtr);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_compose_fill_addr
 * DESCRIPTION
 *  Fill address data for a sending mail
 * PARAMETERS
 *  totalAddr       [IN/OUT]        Address to store total number of addresses
 *  type            [IN]            Type of address to be stored
 *  Addr(?)         [IN/OUT]        Address to store addresses
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_email_ps_compose_fill_addr(U8 *totalAddr, email_addr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *fileName = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    FS_HANDLE fileHandle;
    email_address_list Addr[MMI_EMAIL_MAX_LEN_ADDR_LIST];
    S32 result = FS_NO_ERROR;
    U32 fileLen = 0;
    S32 i = 0;
    U16 outLen;
    U8 *tempPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) fileName, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
    switch (type)
    {
        case EMAIL_ADDR_TO:
            mmi_ucs2cat((S8*) fileName, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_TO_ADDR_FILE_NAME));
            break;
        case EMAIL_ADDR_CC:
            mmi_ucs2cat((S8*) fileName, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_CC_ADDR_FILE_NAME));
            break;
    #ifdef __MMI_EMAIL_BCC__
        case EMAIL_ADDR_BCC:
            mmi_ucs2cat((S8*) fileName, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_BCC_ADDR_FILE_NAME));
            break;
    #endif /* __MMI_EMAIL_BCC__ */ 
        default:
            break;
    }

    fileHandle = FS_Open((U16*)fileName, FS_READ_WRITE|FS_CREATE_ALWAYS);
    OslMfree(fileName);

    if (fileHandle > 0)
    {
        for (i = 0; i < email_p->comp_info.addr_list[type].num_addr; i++)
        {
            /* Display Name */
            Addr[i].charset_disp = MMI_CHSET_UTF8;
            Addr[i].disp_name_len =
                (U8) mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[type].to_cc_name[i]) * ENCODING_LENGTH;
            tempPtr = mmi_email_util_ucs2_to_chset(
                        (U8*) email_p->comp_info.addr_list[type].to_cc_name[i],
                        Addr[i].disp_name_len,
                        (Addr[i].charset_disp),
                        &outLen);
            if (tempPtr != NULL)
            {
                --outLen;
                Addr[i].disp_name_len = (U8) outLen;
                memcpy(Addr[i].display_name, tempPtr, Addr[i].disp_name_len);
                Addr[i].display_name[outLen] = 0;
                OslMfree(tempPtr);
            }
            else
            {
                Addr[i].disp_name_len = 0;
            }

            /* Email address */
            Addr[i].email_addr_len = (U8) mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[type].to_cc_mail[i]);
            mmi_ucs2_n_to_asc(
                (S8*) Addr[i].email_address,
                (S8*) email_p->comp_info.addr_list[type].to_cc_mail[i],
                Addr[i].email_addr_len * ENCODING_LENGTH);
            Addr[i].email_address[Addr[i].email_addr_len] = 0;

            /* write to file */
            result = FS_Write(fileHandle, &(Addr[i]), sizeof(email_address_list), &fileLen);
        }
        FS_Close(fileHandle);
    }
    else
    {
        result = fileHandle;
    }
    *totalAddr = email_p->comp_info.addr_list[type].num_addr;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_compose_fill_cont
 * DESCRIPTION
 *  Fill content of the mail. Currently, only 1 text message supported.
 *  To prevent MS Outlook Express issue, always fill content using UTF8.
 * PARAMETERS
 *  totalTxtMsg     [IN/OUT]        Address to store the number of text messages
 *  textMsgList     [IN/OUT]        Address to store the content message data
 * RETURNS
 *  Error cause from file system.
 *****************************************************************************/
S32 mmi_email_ps_compose_fill_cont(U8 *totalTxtMsg, mmi_email_msg *textMsgList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = FS_NO_ERROR;
    U32 wByte;
    U8 *cont_data;
    U16 cont_len;
    U16 inLen;
    U16 outLen;

    FS_HANDLE file_handle;
    S8 *filename_buff = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    textMsgList[0].charset_text = MMI_CHSET_UTF8;

    mmi_email_util_get_cont_name(1, (S8*) filename_buff);

    file_handle = FS_Open((U16*) filename_buff, FS_READ_WRITE|FS_CREATE_ALWAYS);    
    OslMfree(filename_buff);

    if (file_handle > 0)
    {
        inLen = (U16) mmi_ucs2strlen((S8*) email_p->comp_info.cont_buff) * ENCODING_LENGTH;
        if (inLen)
        {
            cont_data = mmi_email_util_ucs2_to_chset((U8*) email_p->comp_info.cont_buff, inLen, MMI_CHSET_UTF8, &outLen);
            cont_len = (outLen != 0) ? (outLen - 1) : outLen;
            result = FS_Write(file_handle, cont_data, cont_len, &wByte);
            *totalTxtMsg = 1;
            if (cont_data != NULL)
            {
                OslMfree(cont_data);
            }
        }
        else
        {
            *totalTxtMsg = 0;
        }

        FS_Close(file_handle);
        return result;
    }
    else
    {
        return file_handle;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_ps_compose_fill_attach
 * DESCRIPTION
 *  Fill attachment information of the mail.
 * PARAMETERS
 *  totalAttach     [IN/OUT]        Address to store the number of attachment
 *  attachList      [IN/OUT]        Address to store data of each attachment
 * RETURNS
 *  Error cause from file system.
 *****************************************************************************/
S32 mmi_email_ps_compose_fill_attach(U8 *totalAttach, email_attach_struct *attachList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->comp_info.total_attch != 0)
    {
        S32 i;
        S32 addIndex;
        U16 outLen;
        U8 *tempPtr;
        BOOL not_support_chset = MMI_FALSE;
#ifndef __MMI_SHOW_DAF_FILE_EXT__
        UI_character_type mp3_str[8];
        UI_character_type file_name[(FMGR_MAX_FILE_LEN + 1)];
#endif

        /* add attachment 1 by 1 */
        for (i = 0, addIndex = 0; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
        {
            /* check if the presence of attachment */
            if (!email_p->comp_info.attch_list[i].attch_present)
            {
                continue;
            }

			if (email_p->comp_info.attch_list[i].ch_set == MMI_CHSET_ASCII)
			{
                attachList[addIndex].charset_attach = MMI_CHSET_ASCII;
                not_support_chset = MMI_FALSE;
			}
            else if (mmi_email_util_get_chset((U8) email_p->comp_info.attch_list[i].ch_set) <= MMI_CHSET_BASE ||
                mmi_email_util_get_chset((U8) email_p->comp_info.attch_list[i].ch_set) >= MMI_CHSET_TOTAL)
            {
                attachList[addIndex].charset_attach = email_p->comp_info.attch_list[i].ch_set;
                not_support_chset = MMI_TRUE;
            }
            else
            {
                attachList[addIndex].charset_attach = MMI_CHSET_UTF8;
                not_support_chset = MMI_FALSE;
            }
            attachList[addIndex].mime_subtype = email_p->comp_info.attch_list[i].attch_subtype;
            attachList[addIndex].mime_type = email_p->comp_info.attch_list[i].attch_type;
            attachList[addIndex].attach_path_len =
                (U16) mmi_ucs2strlen((S8*) email_p->comp_info.attch_list[i].file_name) * ENCODING_LENGTH;
            if (!not_support_chset)
            {
#ifndef __MMI_SHOW_DAF_FILE_EXT__
                if ((email_p->comp_info.attch_list[i].attch_type == MIME_TYPE_AUDIO) &&
                    (email_p->comp_info.attch_list[i].attch_subtype == MIME_SUBTYPE_AUDIO_MP3))
                {
                    mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
                    memset(&file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
                    mmi_ucs2cpy((S8*)file_name, (S8*)email_p->comp_info.attch_list[i].file_name);
                    mmi_ucs2cat((S8*)file_name, (S8*)mp3_str);
                    tempPtr = mmi_email_util_ucs2_to_chset(
                        (U8*) file_name,
                        attachList[addIndex].attach_path_len,
                        (U8) attachList[addIndex].charset_attach,
                        &outLen);
                }
                else if ((email_p->comp_info.attch_list[i].attch_type == MIME_TYPE_AUDIO) &&
                    (email_p->comp_info.attch_list[i].attch_subtype == MIME_SUBTYPE_AUDIO_MP2))
                {
                    mmi_asc_to_ucs2((S8*) mp3_str, ".mp2");
                    memset(&file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
                    mmi_ucs2cpy((S8*)file_name, (S8*)email_p->comp_info.attch_list[i].file_name);
                    mmi_ucs2cat((S8*)file_name, (S8*)mp3_str);
                    tempPtr = mmi_email_util_ucs2_to_chset(
                        (U8*) file_name,
                        attachList[addIndex].attach_path_len,
                        (U8) attachList[addIndex].charset_attach,
                        &outLen);
                }
                else
#endif
                {
                    tempPtr = mmi_email_util_ucs2_to_chset(
                        (U8*) email_p->comp_info.attch_list[i].file_name,
                        attachList[addIndex].attach_path_len,
                        (U8) attachList[addIndex].charset_attach,
                        &outLen);
                }

                /* copy file to file buffer */
                if (tempPtr != NULL)
                {
                    --outLen;
                    attachList[addIndex].attach_path_len = (U8) outLen;
                    memcpy(attachList[addIndex].attach_file_name, tempPtr, outLen);
                    attachList[addIndex].attach_file_name[outLen] = 0;
                }
                OslMfree(tempPtr);
                tempPtr = NULL;
            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) attachList[addIndex].attach_file_name, 
                    (S8*) email_p->comp_info.attch_list[i].file_name, 
                    FMGR_MAX_FILE_LEN);
            }
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_COMPOSE_FILE_ATTACH, email_p->comp_info.total_attch, i);
            result = mmi_email_util_rename_attch((U8) (addIndex + 1), (S8*) email_p->comp_info.attch_list[i].file_path);
            
            if (result != FS_NO_ERROR)
            {
                return result;
            }
#ifdef __MMI_EMAIL_DRM_SUPPORT__
            memcpy(&attachList[addIndex].drm, &email_p->comp_info.attch_list[i].drm, sizeof(email_drm_struct));
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PS_COMPOSE_FILE_ATTACH_DRM,
                email_p->comp_info.attch_list[i].drm.is_valid,
                email_p->comp_info.attch_list[i].drm.mime_type,
                email_p->comp_info.attch_list[i].drm.mime_subtype);
#endif
            addIndex++;
        }
    }
    *totalAttach = email_p->comp_info.total_attch;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_sel_rsp_hdlr
 * DESCRIPTION
 *  Fill mail list to memory pool and entry folder if data complete.
 * PARAMETERS
 *  msgRsp      [IN]        Data of list folder response.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_sel_rsp_hdlr(mmi_email_folder_select_rsp_struct *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_data_ready = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.is_list_updated = TRUE;

    /* update folder info */
    email_p->fldr_info.total_page = msgRsp->num_pages;
    email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails = msgRsp->total_num_msgs;

    if (msgRsp->total_num_msgs != 0)
    {
        U32 i, j;
        U32 currTotalMails;
        mem_pool_struct eMemPool;

        mmi_email_mail_info_struct *listMsgsStruct;
        mmi_email_mail_info_struct *ptrs[MMI_EMAIL_MAX_MSG_PER_PAGE];

        currTotalMails = msgRsp->msgs_in_page;

        eMemPool.nMinId = email_p->mem_pool_info.not_avail_pool * MMI_EMAIL_MAX_MSG_PER_PAGE;
        eMemPool.nMaxId = ((email_p->mem_pool_info.not_avail_pool + 1) * MMI_EMAIL_MAX_MSG_PER_PAGE) - 1;

        listMsgsStruct =
            (mmi_email_mail_info_struct*) mmi_mem_get_free_mem(&email_p->mem_pool_info.mem_container, &eMemPool);
        memset(
            listMsgsStruct,
            0,
            email_p->mem_pool_info.mem_container.unit_size * email_p->mem_pool_info.mem_container.unit_per_pool);

        /* fill data for each mail */
        for (i = 0; i < currTotalMails; i++)
        {
            /* uid, attch flg, read flg info */
            listMsgsStruct[i].mail_uid = msgRsp->mmi_folder_msgs[i].email_msg_uid;
            listMsgsStruct[i].is_read = msgRsp->mmi_folder_msgs[i].read_flag;

            /* attachment info */
            listMsgsStruct[i].attch_num = msgRsp->mmi_folder_msgs[i].attachment_num;
            for (j = 0; j < listMsgsStruct[i].attch_num; j++)
            {
                listMsgsStruct[i].attch_type[j] = msgRsp->mmi_folder_msgs[i].mime_type[j];
                listMsgsStruct[i].attch_subtype[j] = msgRsp->mmi_folder_msgs[i].mime_subtype[j];
            }
            /* delete flag */
            listMsgsStruct[i].delete_flag = msgRsp->mmi_folder_msgs[i].delete_flag;

            /* date and time info */
            mmi_email_util_dt_to_str((S8*) listMsgsStruct[i].dt_buff, &msgRsp->mmi_folder_msgs[i].send_date_time);

            /* size info */
            mmi_email_util_size_to_str((S8*) listMsgsStruct[i].size_buff, msgRsp->mmi_folder_msgs[i].size);
            /* subject */
            mmi_email_fldr_get_msg_subj(
                (U8*) listMsgsStruct[i].subject,
                (U8*) msgRsp->mmi_folder_msgs[i].subject,
                (U8) msgRsp->mmi_folder_msgs[i].subject_len,
                msgRsp->mmi_folder_msgs[i].charset_subject,
                TRUE);

            /* protocol and priority */
            listMsgsStruct[i].priority = msgRsp->mmi_folder_msgs[i].priority;

            /* sender(from) address info */
            mmi_email_fldr_fill_addr_buff(
                (U8*) listMsgsStruct[i].addr_buff,
                &msgRsp->mmi_folder_msgs[i].sender_mail_address);

            ptrs[i] = &listMsgsStruct[i];
        }

        email_p->fldr_info.fldr_list.num_msgs += currTotalMails;

        eMemPool.unit_list = (void **)ptrs;

        mmi_mem_insert_pool(&email_p->mem_pool_info.mem_container, &eMemPool);

        is_data_ready = mmi_email_fldr_is_list_ready();
    }
    else
    {
        folder_empty = MMI_TRUE;
    }

    /* protocol is IMAP4 (only 1 page required) || 
       all data is ready ||
       no page to display */
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) || (is_data_ready == TRUE) ||
        (msgRsp->num_pages == 0))
#else /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    if ((is_data_ready == TRUE) || (msgRsp->num_pages == 0))
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    {
        if (email_p->fldr_info.is_part_download != EMAIL_DOWN_TEMP)
        {
            mmi_email_fldr_enter_curr_list();
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_EMAIL_READ);
            GoBackHistory();
            email_p->fldr_info.is_part_download = EMAIL_DOWN_NONE;
        }
    }
    else
    {
        mmi_email_ps_folder_select_req();
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_enter_curr_list
 * DESCRIPTION
 *  Enter current folder after list folder process complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_enter_curr_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 folderScrnId;
    FuncPtr entryFuncPtr;
    FuncPtr exitFuncPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrieve screen info */
    folderScrnId = SCR_ID_EMAIL_FOLDER;
    entryFuncPtr = mmi_email_entry_folder;
    exitFuncPtr = mmi_email_exit_folder;

    /* if it's in progressing screen */
    if (GetExitScrnID() == SCR_ID_EMAIL_FLDR_LIST_PROGRESS)
    {
        if (IsScreenPresent(folderScrnId))
        {
            /* if folder is already exists */
            GoBackHistory();
        }
        else
        {   /* first time entry */
            (*entryFuncPtr) ();
            DeleteScreenIfPresent(SCR_ID_EMAIL_FLDR_LIST_PROGRESS);
        }
    }
    else if (GetExitScrnID() == SCR_ID_EMAIL_PROGRESS)
    {
        DeleteScreenIfPresent(SCR_ID_EMAIL_FLDR_LIST_PROGRESS);
        if (IsScreenPresent(folderScrnId))
        {
            /* if folder is already exists */
            GoBackHistory();
        }
        else
        {   /* first time entry */
            (*entryFuncPtr) ();
        }
    }
    else
    {
        /*
         * it's not in progressing screen, maybe in call or something else 
         * only to delete the loading screen because the screen is add to
         * history when loading screen shows
         */
        DeleteScreenIfPresent(SCR_ID_EMAIL_FLDR_LIST_PROGRESS);
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    }
    /* else
    {
        mmi_email_util_set_insert_history_flag(TRUE);
        (*exitFuncPtr) ();
        DeleteScreenIfPresent(SCR_ID_EMAIL_FLDR_LIST_PROGRESS);
    } */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_dt_to_str
 * DESCRIPTION
 *  Convert data time to displayed string.
 * PARAMETERS
 *  result          [?]         [?]
 *  date_time       [IN]        Date/time from PS.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_dt_to_str(S8 *result, email_date_time_struct *date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *strBuff = OslMalloc(EMAIL_MAX_DATE_TIME_STR_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((date_time->month == 0) || (date_time->day == 0))
    {
        memset(strBuff, 0, sizeof(EMAIL_MAX_DATE_TIME_STR_LEN * ENCODING_LENGTH));
    }
    else
    {
        sprintf(
            strBuff,
            "%d/%02d/%02d %02d:%02d:%02d",
            date_time->year,
            date_time->month,
            date_time->day,
            date_time->hours,
            date_time->minutes,
            date_time->seconds);
    }

    mmi_asc_to_ucs2((S8*) result, (S8*) strBuff);

    OslMfree(strBuff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_size_to_str
 * DESCRIPTION
 *  Convert size to displayed string.
 * PARAMETERS
 *  result      [IN/OUT]        Buffer to save converted result
 *  size        [IN]            Size from PS.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_size_to_str(S8 *result, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *strBuff = OslMalloc(EMAIL_MAX_SIZE_STR_LEN * ENCODING_LENGTH);
    S8 *strTmp = OslMalloc(EMAIL_MAX_SIZE_STR_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(strBuff, "%d", ((size + 1023) / 1024));
    mmi_asc_to_ucs2((S8*) strTmp, (S8*) strBuff);
    mmi_ucs2cpy((S8*) result, (S8*) g_email_subj_left_op);
    mmi_ucs2cat((S8*) result, (S8*) strTmp);
    mmi_ucs2cat((S8*) result, "K");
    mmi_ucs2cat((S8*) result, (S8*) g_email_subj_right_op);

    OslMfree(strTmp);
    OslMfree(strBuff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_subj
 * DESCRIPTION
 *  Retrieve subject of a mail.
 *  Convert the data to UCS2 encoding and truncated if required.
 * PARAMETERS
 *  out_buff        [IN/OUT]        Buffer to store the result.
 *  in_buff         [IN]            Buffer to store the data to be converted.
 *  subj_len        [IN]            Length of the data (in bytes).
 *  charSet         [IN]            Charset of the data.
 *  truncate        [IN]            BOOL        truncated required or not.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_subj(U8 *out_buff, U8 *in_buff, U8 subj_len, S32 charSet, BOOL truncate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *tempPtr;
    U16 outLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (subj_len)
    {
        tempPtr = mmi_email_util_chset_to_ucs2(in_buff, subj_len, charSet, &outLen);
        if (tempPtr != NULL)
        {
            if (outLen > (EMAIL_COMP_SUBJ_LEN) * ENCODING_LENGTH)
            {
                outLen = (EMAIL_COMP_SUBJ_LEN) * ENCODING_LENGTH;
            }

            if ((truncate == TRUE) && (outLen > ((EMAIL_MAX_SUBJ_DISPLAY_STR_LEN + 1) * ENCODING_LENGTH)))
            {
                memcpy(out_buff, tempPtr, ((EMAIL_MAX_SUBJ_DISPLAY_STR_LEN - 3) * ENCODING_LENGTH));
                mmi_ucs2cat((S8*) out_buff, (S8*) g_email_3dots);
            }
            else
            {
                memcpy(out_buff, tempPtr, outLen);
            }

            OslMfree(tempPtr);
        }
    }
    else
    {
        out_buff[0] = '\0';
        out_buff[1] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_rsp_data
 * DESCRIPTION
 *  Retrieve email data from mmi_email_folder_msg_select_rsp_struct.
 * PARAMETERS
 *  msgRsp      [IN]        Address stores the email data.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_rsp_data(mmi_email_folder_msg_select_rsp_struct *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrieve email data */
    mmi_email_fldr_get_msg_struct(&msgRsp->email_msg);

    {
        /* delete all the file in the folder to release quota */
        if ((email_p->fldr_info.is_part_download != EMAIL_DOWN_IMAP4) &&
            (email_p->fldr_info.is_part_download != EMAIL_DOWN_POP3))
        {
            mmi_email_util_folder_init(MMI_TRUE);
        }
        /* rename attachment file */
        mmi_email_util_rename_default_to_read();

        /* read/unread status of the mail */
        if (email_p->main_info.curr_menu == MMI_EMAIL_INBOX)
        {
            mmi_email_folder_update_mail_state(email_p->fldr_info.curr_mail_indx, EMAIL_MS_READ);
        }

        /* display read email screen */
        if ((email_p->fldr_info.is_part_download != EMAIL_DOWN_IMAP4) &&
            (email_p->fldr_info.is_part_download != EMAIL_DOWN_POP3))
        {
            mmi_email_fldr_exec_curr_rsp(
                SCR_ID_EMAIL_PROGRESS,
                mmi_email_entry_read,
                mmi_email_exit_read);
        }
        else
        {
            if (GetExitScrnID() == SCR_ID_EMAIL_PROGRESS)
            {
                GoBackHistory();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_exec_curr_rsp
 * DESCRIPTION
 *  Execute current handler when receiving a response
 * PARAMETERS
 *  progrScrnId         [IN]        
 *  entryFuncPtr        [IN]        
 *  exitFuncPtr         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_exec_curr_rsp(U16 progrScrnId, FuncPtr entryFuncPtr, FuncPtr exitFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == progrScrnId)
    {
        (*entryFuncPtr) ();
    }
    else
    {
        mmi_email_util_set_insert_history_flag(TRUE);
        (*exitFuncPtr) ();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_struct
 * DESCRIPTION
 *  Retrieve email data from email_msg_info_struct.
 * PARAMETERS
 *  emailMsg        [IN]        Address stores the email data.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_struct(email_msg_info_struct *emailMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset context */
    memset(&email_p->inbox_info.read_info, 0, sizeof(mmi_email_comp_info_struct));
    email_p->fldr_info.curr_total_att = emailMsg->total_attachments;
    email_p->fldr_info.curr_total_txt = emailMsg->total_text_msgs;
    email_p->fldr_info.curr_num_not_cached_txt = emailMsg->total_text_msgs;
    email_p->fldr_info.curr_num_not_cached_att = emailMsg->total_attachments;

    /* Part Mask */
    mmi_email_fldr_get_msg_part_mask(emailMsg->part_mask);

    /* Content */
    mmi_email_fldr_get_msg_cont(emailMsg->total_text_msgs, (mmi_email_msg*) emailMsg->text_msgs);

    /* Attachment */
    mmi_email_fldr_get_msg_attch(emailMsg->total_attachments, (email_attach_struct*) & emailMsg->attach);

    /* Subject */
    mmi_email_fldr_get_msg_subj(
        (U8*) email_p->inbox_info.read_info.subj_buff,
        (U8*) emailMsg->subject,
        emailMsg->subject_len,
        emailMsg->charset_subject,
        FALSE);

    /* Senders email address */
    mmi_email_fldr_get_msg_from(&emailMsg->senders_address);

    /* Recipient address --- TO */
    mmi_email_fldr_get_msg_addr(emailMsg->total_to_address, EMAIL_ADDR_TO);

    /* Recipient address --- CC */
    mmi_email_fldr_get_msg_addr(emailMsg->total_cc_address, EMAIL_ADDR_CC);

#ifdef __MMI_EMAIL_BCC__
    /* Recipient address --- BCC */
    mmi_email_fldr_get_msg_addr(emailMsg->total_bcc_address, EMAIL_ADDR_BCC);
#endif /* __MMI_EMAIL_BCC__ */ 

    /* REPLY-TO address */
    mmi_email_fldr_get_msg_reply_to(&emailMsg->reply_to_addr);

    /* Priority */
    mmi_email_fldr_get_msg_prot(emailMsg->priority);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_cont
 * DESCRIPTION
 *  Retrieve content of a mail.
 * PARAMETERS
 *  totalTextMsg        [IN]        Total number of messages
 *  textMsgList         [IN]        Data of messages
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_cont(U8 totalTextMsg, mmi_email_msg *textMsgList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 outContentLen;
    U8 *contentDataPtr;
    S32 sizeOfContents[MMI_EMAIL_TOTAL_TEXT_MSGS];
    S32 curr_out_len = 0;   /* must be zero initialized */
    S32 len_to_cpy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (totalTextMsg == 0)
    {
        return;
    }

    mmi_email_util_get_cont_size(totalTextMsg, sizeOfContents);

    for (i = 0; i < totalTextMsg; i++)
    {
        if ((ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, i)) &&
            (mmi_email_fldr_read_cont
                 ((U8) (i + 1),
                 sizeOfContents[i],
                 textMsgList[i].charset_text,
                 &contentDataPtr,
                 &outContentLen)))
        {
            if (contentDataPtr != NULL)
            {
                len_to_cpy = outContentLen / 2;
                if (curr_out_len + len_to_cpy == (EMAIL_MAX_CONT_LEN + 1))      /* exact the same size because of null terminate */
                {
                    len_to_cpy = EMAIL_MAX_CONT_LEN - curr_out_len;
                }
                else if (curr_out_len + len_to_cpy > EMAIL_MAX_CONT_LEN)
                {
                    len_to_cpy = EMAIL_MAX_CONT_LEN - curr_out_len - 3; /* 3 == "..." */
                    email_p->inbox_info.read_info.except_popup |= EMAIL_EXCEPT_CON_EXCEED;
                }

                if (curr_out_len)   /* copy a new line */
                {
                    mmi_ucs2cat((S8*) email_p->inbox_info.read_info.cont_buff, (S8*) L"\n");
                    len_to_cpy--;
                }

                mmi_ucs2ncat(
                    (S8*) email_p->inbox_info.read_info.cont_buff,
                    (S8*) contentDataPtr,
                    (S32) len_to_cpy);
                curr_out_len += len_to_cpy;
                OslMfree(contentDataPtr);

                if ((email_p->inbox_info.read_info.except_popup & EMAIL_EXCEPT_CON_EXCEED) == EMAIL_EXCEPT_CON_EXCEED)
                {
                    mmi_ucs2cat((S8*) email_p->inbox_info.read_info.cont_buff, (S8*) g_email_3dots);
                    return; /* because already exceeded, do not have to precess next text message */
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_addr
 * DESCRIPTION
 *  Retrieve recipients' address data of a mail.
 * PARAMETERS
 *  total       [IN]        Total number of addresses
 *  type        [IN]        Type of address -- TO/CC
 *  addr(?)     [IN]        Data of recipients' addresses
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_addr(U8 total, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *fileName = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    FS_HANDLE fileHandle;
    email_address_list addr[MMI_EMAIL_MAX_LEN_ADDR_LIST];
    U32 fileLen = 0;
    S32 i = 0;
    U16 outLen;
    U8 *tempPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) fileName, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
    switch (type)
    {
        case EMAIL_ADDR_TO:
            mmi_ucs2cat((S8*) fileName, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_TO_ADDR_FILE_NAME));
            break;
        case EMAIL_ADDR_CC:
            mmi_ucs2cat((S8*) fileName, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_CC_ADDR_FILE_NAME));
            break;
    #ifdef __MMI_EMAIL_BCC__
        case EMAIL_ADDR_BCC:
            mmi_ucs2cat((S8*) fileName, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_BCC_ADDR_FILE_NAME));
            break;
    #endif /* __MMI_EMAIL_BCC__ */ 
        default:
            break;
    }

    fileHandle = FS_Open((U16*) fileName, FS_READ_WRITE);
    OslMfree(fileName);

    email_p->inbox_info.read_info.addr_list[type].num_addr = total;
    if (fileHandle > 0)
    {
        for (i = 0; i < total; i++)
        {
            FS_Read(fileHandle, &(addr[i]), sizeof(email_address_list), &fileLen);
            /* convert address */
            mmi_asc_n_to_ucs2(
                (S8*) email_p->inbox_info.read_info.addr_list[type].to_cc_mail[i],
                (S8*) addr[i].email_address,
                addr[i].email_addr_len);
            email_p->inbox_info.read_info.addr_list[type].to_cc_mail[i][addr[i].email_addr_len] = 0x0000;

            /* display name */
            tempPtr = mmi_email_util_chset_to_ucs2(
                        (U8*) addr[i].display_name,
                        addr[i].disp_name_len,
                        addr[i].charset_disp,
                        &outLen);

            if (tempPtr != NULL)
            {
                if (outLen > EMAIL_PROF_DISP_NAME_LEN * ENCODING_LENGTH)
                {
                    outLen = EMAIL_PROF_DISP_NAME_LEN * ENCODING_LENGTH;
                }

                memcpy(&email_p->inbox_info.read_info.addr_list[type].to_cc_name[i], tempPtr, outLen);
                email_p->inbox_info.read_info.addr_list[type].to_cc_name[i][outLen / ENCODING_LENGTH] = 0x0000;

                OslMfree(tempPtr);
            }
            else
            {
                email_p->inbox_info.read_info.addr_list[type].to_cc_name[i][0] = 0;
            }
        }
        FS_Close(fileHandle);
    }
    else
    {
        MMI_EXT_ASSERT((fileHandle > 0), 0, 0, 0);
    }

    if (total != 0) /* only display first email address */
    {
        if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_list[type].to_cc_name[0]))
        {
            mmi_ucs2cpy(
                (S8*) email_p->inbox_info.read_info.addr_disp_buff[type],
                (S8*) email_p->inbox_info.read_info.addr_list[type].to_cc_name[0]);
            mmi_ucs2cat((S8*) email_p->inbox_info.read_info.addr_disp_buff[type], (S8*) g_email_subj_left_op);
            mmi_ucs2cat(
                (S8*) email_p->inbox_info.read_info.addr_disp_buff[type],
                (S8*) email_p->inbox_info.read_info.addr_list[type].to_cc_mail[0]);
            mmi_ucs2cat((S8*) email_p->inbox_info.read_info.addr_disp_buff[type], (S8*) g_email_subj_right_op);
        }
        else
        {
            mmi_ucs2cpy(
                (S8*) email_p->inbox_info.read_info.addr_disp_buff[type],
                (S8*) email_p->inbox_info.read_info.addr_list[type].to_cc_mail[0]);
        }

        if (total > 1)
        {
            mmi_ucs2cat((S8*) email_p->inbox_info.read_info.addr_disp_buff[type], (S8*) g_email_3dots);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_from
 * DESCRIPTION
 *  Retrieve sender's address data of a mail.
 * PARAMETERS
 *  senderAddr      [IN]        Data of sender's address
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_from(email_address_list *senderAddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 outLen;
    U8 *tempPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* convert address */
    memset(&email_p->inbox_info.from_info, 0, sizeof(mmi_email_from_struct));
    if (senderAddr->email_addr_len != 0)
    {
        mmi_asc_n_to_ucs2(
            (S8*) email_p->inbox_info.from_info.from_addr,
            (S8*) senderAddr->email_address,
            senderAddr->email_addr_len);
    }
    email_p->inbox_info.from_info.from_addr[senderAddr->email_addr_len] = 0x0000;

    /* convert display name */
    tempPtr = mmi_email_util_chset_to_ucs2(
                (U8*) senderAddr->display_name,
                senderAddr->disp_name_len,
                senderAddr->charset_disp,
                &outLen);
    if (tempPtr != NULL)
    {
        if (outLen > EMAIL_PROF_DISP_NAME_LEN * ENCODING_LENGTH)
        {
            outLen = EMAIL_PROF_DISP_NAME_LEN * ENCODING_LENGTH;
        }

        memcpy(email_p->inbox_info.from_info.from_name, tempPtr, outLen);

        OslMfree(tempPtr);
    }
    else
    {
        email_p->inbox_info.from_info.from_name[0] = 0;
    }

    if (mmi_ucs2strlen((S8*) email_p->inbox_info.from_info.from_name))
    {
        mmi_ucs2cpy(
            (S8*) email_p->inbox_info.read_info.from_addr,
            (S8*) email_p->inbox_info.from_info.from_name);
        mmi_ucs2cat((S8*) email_p->inbox_info.read_info.from_addr, (S8*) g_email_subj_left_op);
        mmi_ucs2cat(
            (S8*) email_p->inbox_info.read_info.from_addr,
            (S8*) email_p->inbox_info.from_info.from_addr);
        mmi_ucs2cat((S8*) email_p->inbox_info.read_info.from_addr, (S8*) g_email_subj_right_op);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->inbox_info.read_info.from_addr,
            (S8*) email_p->inbox_info.from_info.from_addr);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_reply_to
 * DESCRIPTION
 *  Retrieve reply-to address data of a mail.
 * PARAMETERS
 *  senderAddr      [IN]        Data of reply-to address
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_fldr_get_msg_reply_to(email_address_list *reply_to)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* convert address */
    memset(email_p->inbox_info.reply_to_addr, 0, (MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1));
    if (reply_to->email_addr_len != 0)
    {
        mmi_asc_n_to_ucs2(
            (S8*) email_p->inbox_info.reply_to_addr,
            (S8*) reply_to->email_address,
            reply_to->email_addr_len);
    }
    email_p->inbox_info.reply_to_addr[reply_to->email_addr_len] = 0x0000;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_prot
 * DESCRIPTION
 *  Retrieve priority of the mail
 * PARAMETERS
 *  priority        [IN]        Priority of the mail
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_prot(U8 priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (priority == MMI_EMAIL_NORMAL_PRIORITY)
    {
        email_p->inbox_info.read_info.priority_indx = 0;
    }
    else if (priority < MMI_EMAIL_NORMAL_PRIORITY)
    {
        email_p->inbox_info.read_info.priority_indx = 2;
    }
    else
    {
        email_p->inbox_info.read_info.priority_indx = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_part_mask
 * DESCRIPTION
 *  Retrieve part mask information of the mail
 * PARAMETERS
 *  part_mask       [IN]        Part mask of the mail
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_part_mask(kal_uint8 *part_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EMAIL_PART_MASK_SIZE; i++)
    {
        email_p->fldr_info.curr_part_mask[i] |= part_mask[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_msg_attch
 * DESCRIPTION
 *  Retrieve attachment information from email_msg_info_struct.
 * PARAMETERS
 *  totalAttach     [IN]        Total number of attachment.
 *  attachList      [IN]        List of attachment information.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_get_msg_attch(U8 totalAttach, email_attach_struct *attachList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index, i;
    U8 *tempPtr;
    U16 outLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, index = 0; i < totalAttach; i++)
    {
        email_p->inbox_info.read_info.attch_list[i].size = attachList[i].size;
        tempPtr = mmi_email_util_chset_to_ucs2(
                    (U8*) attachList[i].attach_file_name,
                    (U16) attachList[i].attach_path_len,
                    attachList[i].charset_attach,
                    &outLen);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_FLDR_GET_MSG_ATTACH_DRM,
            attachList[i].drm.is_valid,
            attachList[i].drm.mime_type,
            attachList[i].drm.mime_subtype);
        memcpy(&email_p->inbox_info.read_info.attch_list[index].drm, &attachList[i].drm, sizeof(email_drm_struct));
#endif

        /* if encounter bad attachment, neglect it */
        if (tempPtr)
        {
            email_p->inbox_info.read_info.attch_list[index].ch_set = attachList[i].charset_attach;
            email_p->inbox_info.read_info.attch_list[index].attch_type = attachList[i].mime_type;
            email_p->inbox_info.read_info.attch_list[index].attch_subtype = attachList[i].mime_subtype;

            if (outLen > FMGR_MAX_FILE_LEN * ENCODING_LENGTH)
            {
                S8 *file_ext;
                S32 ext_len, name_len, file_len, new_len;
#ifndef __MMI_SHOW_DAF_FILE_EXT__
                UI_character_type mp3_str[8];
                UI_character_type mp2_str[8];
#endif

                kal_mem_set(&email_p->inbox_info.read_info.attch_list[index].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
                file_len = mmi_ucs2strlen((S8*) tempPtr);
                file_ext = mmi_email_get_file_ext((S8*) tempPtr);
                if (file_ext)
                {
                    ext_len = mmi_ucs2strlen(file_ext);
                    name_len = file_len - ext_len;
                    new_len = name_len - (file_len - FMGR_MAX_FILE_LEN);
                    mmi_ucs2ncpy(
                        (S8*) email_p->inbox_info.read_info.attch_list[index].file_name,
                        (S8*) tempPtr,
                        new_len);
#ifndef __MMI_SHOW_DAF_FILE_EXT__
                    mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
                    mmi_asc_to_ucs2((S8*) mp2_str, ".mp2");
                    if ((mmi_ucs2icmp(file_ext, (S8*)mp3_str) != 0) &&
                        (mmi_ucs2icmp(file_ext, (S8*)mp2_str) != 0))
#endif
                    {
                        mmi_ucs2cat((S8*) email_p->inbox_info.read_info.attch_list[index].file_name, file_ext);
                    }
#ifndef __MMI_SHOW_DAF_FILE_EXT__
                    else
                    {
                        if (mmi_ucs2icmp(file_ext, (S8*)mp3_str) == 0)
                        {
                            email_p->inbox_info.read_info.attch_list[index].attch_type = MIME_TYPE_AUDIO;
                            email_p->inbox_info.read_info.attch_list[index].attch_subtype = MIME_SUBTYPE_AUDIO_MP3;
                        }
                        else
                        {
                            email_p->inbox_info.read_info.attch_list[index].attch_type = MIME_TYPE_AUDIO;
                            email_p->inbox_info.read_info.attch_list[index].attch_subtype = MIME_SUBTYPE_AUDIO_MP2;
                        }
                    }
#endif
                }
                else
                {
                    mmi_ucs2ncpy(
                        (S8*) email_p->inbox_info.read_info.attch_list[index].file_name,
                        (S8*) tempPtr,
                        FMGR_MAX_FILE_LEN);
                }
            }
            else if (outLen == 0)
            {
                mmi_ucs2ncpy(
                    (S8*) email_p->inbox_info.read_info.attch_list[index].file_name, 
                    (S8*) attachList[i].attach_file_name, 
                    FMGR_MAX_FILE_LEN);
            }
            else
            {
#ifndef __MMI_SHOW_DAF_FILE_EXT__
                S8 *file_ext;
                S32 ext_len, name_len, file_len;
                UI_character_type mp3_str[8];
                UI_character_type mp2_str[8];

                mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
                mmi_asc_to_ucs2((S8*) mp2_str, ".mp2");
                kal_mem_set(&email_p->inbox_info.read_info.attch_list[index].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
                file_len = mmi_ucs2strlen((S8*) tempPtr);
                file_ext = mmi_email_get_file_ext((S8*) tempPtr);
                if (file_ext)
                {
                    ext_len = mmi_ucs2strlen(file_ext);
                    name_len = file_len - ext_len;
                    mmi_ucs2ncpy(
                        (S8*) email_p->inbox_info.read_info.attch_list[index].file_name,
                        (S8*) tempPtr,
                        name_len);
                    if ((mmi_ucs2icmp(file_ext, (S8*)mp3_str) != 0) &&
                        (mmi_ucs2icmp(file_ext, (S8*)mp2_str) != 0))
                    {
                        mmi_ucs2cat((S8*) email_p->inbox_info.read_info.attch_list[index].file_name, file_ext);
                    }
                    else
                    {
                        if (mmi_ucs2icmp(file_ext, (S8*)mp3_str) == 0)
                        {
                            email_p->inbox_info.read_info.attch_list[index].attch_type = MIME_TYPE_AUDIO;
                            email_p->inbox_info.read_info.attch_list[index].attch_subtype = MIME_SUBTYPE_AUDIO_MP3;
                        }
                        else
                        {
                            email_p->inbox_info.read_info.attch_list[index].attch_type = MIME_TYPE_AUDIO;
                            email_p->inbox_info.read_info.attch_list[index].attch_subtype = MIME_SUBTYPE_AUDIO_MP2;
                        }
                    }
                }
                else
#endif
                {
                    memcpy(email_p->inbox_info.read_info.attch_list[index].file_name, tempPtr, outLen);
                }
            }
            OslMfree(tempPtr);

            if (ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, EMAIL_PART_MASK_ATTACH(index)))
            {
                email_p->inbox_info.read_info.attch_list[index].attch_cached = EMAIL_ATT_CACHED;
                email_p->inbox_info.read_info.attch_list[index].attch_present = MMI_TRUE;
            }
            else
            {
                email_p->inbox_info.read_info.attch_list[index].attch_cached = EMAIL_ATT_NOT_CACHED;
                email_p->inbox_info.read_info.attch_list[index].attch_present = MMI_FALSE;
            }
            index++;
        }
    }

    email_p->inbox_info.read_info.total_attch = index;

    for (; index < MMI_EMAIL_MAX_NUM_ATTACH; index++)
    {
        mmi_ucs2cpy(
            (S8*) email_p->inbox_info.read_info.attch_list[index].file_name,
            (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        email_p->inbox_info.read_info.attch_list[index].attch_cached = EMAIL_ATT_NOT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_fill_data
 * DESCRIPTION
 *  Fill profile data to Profile context
 * PARAMETERS
 *  msgRsp      [?]     [?]
 * RETURNS
 *  msgRsp      IN    address stored the profile data(?)(?)
 *****************************************************************************/
void mmi_email_prof_fill_data(mmi_list_acct_struct *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (msgRsp->acct_name_len[i] == 0)
        {
            mmi_ucs2cpy(
                (S8*) email_p->prof_info.prof_misc.acct_names[i],
                (S8*) GetString((U16) (STR_EMAIL_PROFILE_NAME_1 + i)));
        }
        else
        {
            memset(&email_p->prof_info.prof_misc.acct_names[i], 0, sizeof(email_p->prof_info.prof_misc.acct_names[i]));
            mmi_ucs2ncpy(
                (S8*) email_p->prof_info.prof_misc.acct_names[i],
                (S8*) msgRsp->acct_names[i],
                (msgRsp->acct_name_len[i]) / 2);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_fill_addr_buff
 * DESCRIPTION
 *  Fill address buffer to display in each folder
 * PARAMETERS
 *  appMailAddr                 [OUT]       Address buffer to fill.
 *  psMailAddrInfoStruct        [IN]        Address info to be retrieved
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_fill_addr_buff(U8 *appMailAddr, email_address_list *psMailAddrInfoStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(appMailAddr, 0, sizeof(S8) * ((MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1) * ENCODING_LENGTH));
    if (psMailAddrInfoStruct->email_addr_len != 0)
    {
        mmi_asc_n_to_ucs2(
            (S8*) appMailAddr,
            (S8*) psMailAddrInfoStruct->email_address,
            psMailAddrInfoStruct->email_addr_len);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_fill_act_info
 * DESCRIPTION
 *  Filll account data for activated account
 * PARAMETERS
 *  LocalData       [?]     [?]
 * RETURNS
 *  LocalData      IN    address stored the profile data(?)(?)
 *****************************************************************************/
void mmi_email_prof_fill_act_info(mmi_acct_profile_struct *LocalData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *tempPtr;
    U16 outLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /* protocol */
    email_p->prof_info.act_prof.in_prot = LocalData->imap_pop3_info.in_protocol;
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    /* email address */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.act_prof.email_addr,
        (S8*) LocalData->smtp_info.email_address,
        LocalData->smtp_info.email_addr_len);
    email_p->prof_info.act_prof.email_addr[LocalData->smtp_info.email_addr_len * ENCODING_LENGTH] = 0;
    email_p->prof_info.act_prof.email_addr[LocalData->smtp_info.email_addr_len * ENCODING_LENGTH + 1] = 0;

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /* draft folder name */
    if (LocalData->imap_pop3_info.draft_name_len)
    {
        tempPtr = mmi_email_util_chset_to_ucs2(
                    (U8*) & LocalData->imap_pop3_info.draft_name,
                    LocalData->imap_pop3_info.draft_name_len,
                    MMI_CHSET_UTF8,
                    &outLen);
        if (tempPtr != NULL)
        {
            mmi_ucs2cpy((S8*) email_p->prof_info.act_prof.draft_name, (S8*) tempPtr);
            OslMfree(tempPtr);
        }
    }
    else
    {
        email_p->prof_info.act_prof.draft_name[0] = 0;
        email_p->prof_info.act_prof.draft_name[1] = 0;
    }

    /* sent folder name */
    if (LocalData->imap_pop3_info.sent_name_len)
    {
        tempPtr = mmi_email_util_chset_to_ucs2(
                    (U8*) & LocalData->imap_pop3_info.sent_name,
                    LocalData->imap_pop3_info.sent_name_len,
                    MMI_CHSET_UTF8,
                    &outLen);

        if (tempPtr != NULL)
        {
            mmi_ucs2cpy((S8*) email_p->prof_info.act_prof.sent_name, (S8*) tempPtr);
            OslMfree(tempPtr);
        }
    }
    else
    {
        email_p->prof_info.act_prof.sent_name[0] = 0;
        email_p->prof_info.act_prof.sent_name[1] = 0;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

    /* signature */
    email_p->prof_info.act_prof.sig_status = LocalData->smtp_info.signature.on_off;

    /* signature text */
    /* first reset data */
    email_p->prof_info.act_prof.sig_buff[0] = 0;
    /* check if test signature is here */
    if (LocalData->smtp_info.signature.signature_type & MMI_EMAIL_SIG_IS_TEXT)
    {
        if (LocalData->smtp_info.signature.text_len)
        {
            tempPtr = mmi_email_util_chset_to_ucs2(
                        (U8*) & LocalData->smtp_info.signature.text,
                        LocalData->smtp_info.signature.text_len,
                        MMI_CHSET_UTF8,
                        &outLen);
            if (tempPtr != NULL)
            {
                mmi_ucs2cpy((S8*) email_p->prof_info.act_prof.sig_buff, (S8*) tempPtr);
                OslMfree(tempPtr);
            }
        }
    }

    /* signature attachment */
    email_p->prof_info.act_prof.sig_img[0] = 0;
    if (LocalData->smtp_info.signature.signature_type & MMI_EMAIL_SIG_IS_ATTACH)
    {
        mmi_ucs2cpy(
            (S8*) email_p->prof_info.act_prof.sig_img,
            (S8*) LocalData->smtp_info.signature.attach.attach_file_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_update_act_info
 * DESCRIPTION
 *  Update current editing data to active account
 * PARAMETERS
 *  void
 * RETURNS
 *  LocalData      IN    address stored the profile data(?)(?)
 *****************************************************************************/
void mmi_email_prof_update_act_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_p->prof_info.prof_misc.curr_scr)
    {
        case SCR_ID_EMAIL_PROF_SETTING:
        {
        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            /* protocol */
            email_p->prof_info.act_prof.in_prot = email_p->prof_info.editing_prof.setting_info.in_prot;
            if (email_p->prof_info.prof_misc.curr_prot != email_p->prof_info.editing_prof.setting_info.in_prot)
            {
                mmi_email_prof_update_hint();
            }
        #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            break;
        }
        case SCR_ID_EMAIL_PROF_SMTP:
        {
            /* email address */
            mmi_ucs2cpy(
                (S8*) email_p->prof_info.act_prof.email_addr,
                (S8*) email_p->prof_info.editing_prof.smtp_info.email_addr);
            break;
        }
        case SCR_ID_EMAIL_PROF_POP3_IMAP4:
        {
        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)

            if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
            {
                /* sent and draft folder name */
                BOOL critical_changed = FALSE;

                if (mmi_ucs2cmp
                    ((S8*) (S8*) email_p->prof_info.act_prof.sent_name,
                     (S8*) email_p->prof_info.editing_prof.pop_imap_info.sent_name) ||
                    mmi_ucs2cmp(
                        (S8*) email_p->prof_info.act_prof.draft_name,
                        (S8*) email_p->prof_info.editing_prof.pop_imap_info.draft_name))
                {
                    critical_changed = TRUE;
                }

                mmi_ucs2cpy(
                    (S8*) email_p->prof_info.act_prof.sent_name,
                    (S8*) email_p->prof_info.editing_prof.pop_imap_info.sent_name);
                mmi_ucs2cpy(
                    (S8*) email_p->prof_info.act_prof.draft_name,
                    (S8*) email_p->prof_info.editing_prof.pop_imap_info.draft_name);

                if (critical_changed)   /* folder name changed */
                {
                    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
                }
            }
        #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            break;
        }
        case SCR_ID_EMAIL_PROF_SIG:
        {
            /* signature */
            email_p->prof_info.act_prof.sig_status = email_p->prof_info.editing_prof.sig_info.sig_status;
            mmi_ucs2cpy(
                (S8*) email_p->prof_info.act_prof.sig_buff,
                (S8*) email_p->prof_info.editing_prof.sig_info.sig_buff);
            mmi_ucs2cpy(
                (S8*) email_p->prof_info.act_prof.sig_img,
                (S8*) email_p->prof_info.editing_prof.sig_info.img_name);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_get_acct_data
 * DESCRIPTION
 *  Filll account data to global context
 * PARAMETERS
 *  LocalData       [?]     [?]
 * RETURNS
 *  LocalData      IN    address stored the profile data(?)(?)
 *****************************************************************************/
void mmi_email_prof_get_acct_data(mmi_acct_profile_struct *LocalData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 port_num;
    S32 dwnl_size;

#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
    S32 n_of_days;
#endif 
    U8 *tempPtr;
    U16 outLen;
    U8 index = email_p->prof_info.prof_misc.curr_sel_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&email_p->prof_info.editing_prof, 0, sizeof(mmi_email_prof_struct));

    /* account name */
    if (LocalData->acct_name_len)
    {
        memcpy(email_p->prof_info.editing_prof.setting_info.prof_name, LocalData->acct_name, LocalData->acct_name_len);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->prof_info.editing_prof.setting_info.prof_name,
            (S8*) email_p->prof_info.prof_misc.acct_names[index]);
    }

    /* data account */
    email_p->prof_info.editing_prof.setting_info.data_acct = (U32)LocalData->imap_pop3_info.service_type;
    mmi_dtcnt_get_account_name(
        (U32) email_p->prof_info.editing_prof.setting_info.data_acct,
        (S8*) email_p->prof_info.prof_misc.data_acct_name,
        MAX_DATA_ACCOUNT_NAME_LEN);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /* in protocol ...pop3/imap4 */
    email_p->prof_info.editing_prof.setting_info.in_prot = LocalData->imap_pop3_info.in_protocol;
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

    /* max download size */
    if (LocalData->imap_pop3_info.max_download_size < MMI_EMAIL_MIN_MSG_SIZE ||
        LocalData->imap_pop3_info.max_download_size > MMI_EMAIL_MAX_MSG_SIZE)
    {
        dwnl_size = MMI_EMAIL_MAX_MSG_SIZE;
    }
    else
    {
        dwnl_size = (S32) LocalData->imap_pop3_info.max_download_size;
    }
    gui_itoa(dwnl_size, (UI_string_type) email_p->prof_info.editing_prof.setting_info.dwnl_size, 10);

#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    /* check interval */
    switch (LocalData->imap_pop3_info.check_interval)
    {
        case 5:
            email_p->prof_info.editing_prof.setting_info.chk_interval = 1;
            break;
        case 30:
            email_p->prof_info.editing_prof.setting_info.chk_interval = 2;
            break;
        case 60:
            email_p->prof_info.editing_prof.setting_info.chk_interval = 3;
            break;
        case 120:
            email_p->prof_info.editing_prof.setting_info.chk_interval = 4;
            break;
        default:    /* case 0 */
            email_p->prof_info.editing_prof.setting_info.chk_interval = 0;
            break;
    };
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 

    /* Reply-To address */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.editing_prof.setting_info.reply_to,
        (S8*) LocalData->smtp_info.reply_to_addr,
        LocalData->smtp_info.reply_to_addr_len);

    /* outgoing port number */
    if (LocalData->out_address.port_number == 0)
    {
        port_num = EMAIL_DEFAULT_SMTP_PORT;
    }
    else
    {
        port_num = (S32) LocalData->out_address.port_number;
    }
    gui_itoa(port_num, (UI_string_type) email_p->prof_info.editing_prof.smtp_info.out_port, 10);

    /* outgoing server name */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.editing_prof.smtp_info.out_server,
        (S8*) LocalData->out_address.server_name,
        LocalData->out_address.server_name_len);

    /* display name */
    if (LocalData->smtp_info.disp_name_len)
    {
        tempPtr = mmi_email_util_chset_to_ucs2(
                    (U8*) LocalData->smtp_info.display_name,
                    LocalData->smtp_info.disp_name_len,
                    LocalData->smtp_info.charset_disp_name,
                    &outLen);

        if (tempPtr != NULL)
        {
            mmi_ucs2cpy((S8*) email_p->prof_info.editing_prof.smtp_info.disp_name, (S8*) tempPtr);
            OslMfree(tempPtr);
        }
    }

    /* email address */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.editing_prof.smtp_info.email_addr,
        (S8*) LocalData->smtp_info.email_address,
        LocalData->smtp_info.email_addr_len);

    /*Authentication*/
    email_p->prof_info.editing_prof.smtp_info.auth_flag = (S32) LocalData->smtp_info.smtp_auth;

    /*Authentication same flag*/
    email_p->prof_info.editing_prof.smtp_info.auth_same_flag = (S32)LocalData->smtp_info.smtp_auth_same;
        
    /* SMTP username */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.editing_prof.smtp_info.user_name,
        (S8*) LocalData->smtp_info.login_info.user_name,
        LocalData->smtp_info.login_info.user_name_length);

    /* SMTP password */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.editing_prof.smtp_info.passwd,
        (S8*) LocalData->smtp_info.login_info.pass_word,
        LocalData->smtp_info.login_info.pass_word_length);

    /* incoming port number */
    if (LocalData->in_address.port_number == 0)
    {
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        if (email_p->prof_info.editing_prof.setting_info.in_prot == EMAIL_PROT_IMAP4)
        {
            port_num = EMAIL_DEFAULT_IMAP4_PORT;
        }
        else
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            port_num = EMAIL_DEFAULT_POP3_PORT;
    }
    else
    {
        port_num = (S32) LocalData->in_address.port_number;
    }
    gui_itoa(port_num, (UI_string_type) email_p->prof_info.editing_prof.pop_imap_info.in_port, 10);

    /* incoming server name */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.editing_prof.pop_imap_info.in_server,
        (S8*) LocalData->in_address.server_name,
        LocalData->in_address.server_name_len);

    /* username */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.editing_prof.pop_imap_info.user_name,
        (S8*) LocalData->login_info.user_name,
        LocalData->login_info.user_name_length);

    /* password */
    mmi_asc_n_to_ucs2(
        (S8*) email_p->prof_info.editing_prof.pop_imap_info.passwd,
        (S8*) LocalData->login_info.pass_word,
        LocalData->login_info.pass_word_length);

    /* copy on server */
    email_p->prof_info.editing_prof.pop_imap_info.copy_on_server = (S32) LocalData->imap_pop3_info.leave_copy_on_server;

#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
    /* incoming port number */
    if (LocalData->imap_pop3_info.del_after_n_days > EMAIL_MAX_DEL_AFTER_N_DAYS)
    {
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        if (email_p->prof_info.editing_prof.setting_info.in_prot == EMAIL_PROT_IMAP4)
        {
            n_of_days = 0;
        }
        else
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            n_of_days = EMAIL_DEFAULT_N_DAYS;
    }
    else
    {
        n_of_days = (S32) LocalData->imap_pop3_info.del_after_n_days;
    }
    gui_itoa(n_of_days, (UI_string_type) email_p->prof_info.editing_prof.pop_imap_info.del_after_n_days, 10);

#endif /* __MMI_EMAIL_DEL_AFTER_N_DAYS__ */ 

    email_p->prof_info.editing_prof.pop_imap_info.del_server_mails = (S32) LocalData->imap_pop3_info.del_server_mails;

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.editing_prof.setting_info.in_prot == MMI_EMAIL_PROTOCOL_IMAP4)
    {
        email_p->prof_info.editing_prof.pop_imap_info.download_opt =
            (S32) LocalData->imap_pop3_info.download_option_imap4;
    }
    else
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    {
        email_p->prof_info.editing_prof.pop_imap_info.download_opt =
            (S32) LocalData->imap_pop3_info.download_option_pop3;
    }

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /* draft folder name */
    if (LocalData->imap_pop3_info.draft_name_len)
    {
        tempPtr = mmi_email_util_chset_to_ucs2(
                    (U8*) & LocalData->imap_pop3_info.draft_name,
                    LocalData->imap_pop3_info.draft_name_len,
                    MMI_CHSET_UTF8,
                    &outLen);

        if (tempPtr != NULL)
        {
            mmi_ucs2cpy((S8*) email_p->prof_info.editing_prof.pop_imap_info.draft_name, (S8*) tempPtr);
            OslMfree(tempPtr);
        }
    }

    /* sent folder name */
    if (LocalData->imap_pop3_info.sent_name_len)
    {
        tempPtr = mmi_email_util_chset_to_ucs2(
                    (U8*) & LocalData->imap_pop3_info.sent_name,
                    LocalData->imap_pop3_info.sent_name_len,
                    MMI_CHSET_UTF8,
                    &outLen);
        if (tempPtr != NULL)
        {
            mmi_ucs2cpy((S8*) email_p->prof_info.editing_prof.pop_imap_info.sent_name, (S8*) tempPtr);
            OslMfree(tempPtr);
        }
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

    /* signature text */
    memset(&email_p->prof_info.editing_prof.sig_info, 0, sizeof(email_p->prof_info.editing_prof.sig_info));
    email_p->prof_info.editing_prof.sig_info.sig_status = (S32) LocalData->smtp_info.signature.on_off;
    if (LocalData->smtp_info.signature.signature_type & MMI_EMAIL_SIG_IS_TEXT)
    {
        if (LocalData->smtp_info.signature.text_len)
        {
            tempPtr = mmi_email_util_chset_to_ucs2(
                        (U8*) & LocalData->smtp_info.signature.text,
                        LocalData->smtp_info.signature.text_len,
                        MMI_CHSET_UTF8,
                        &outLen);

            if (tempPtr != NULL)
            {
                mmi_ucs2cpy((S8*) email_p->prof_info.editing_prof.sig_info.sig_buff, (S8*) tempPtr);
                OslMfree(tempPtr);
            }
        }
    }

    /* signature attachment */
    if (LocalData->smtp_info.signature.signature_type & MMI_EMAIL_SIG_IS_ATTACH)
    {
        if (mmi_ucs2strlen((S8*) LocalData->smtp_info.signature.attach.attach_file_name))
        {
            S8 *fileExt = mmi_email_get_file_ext((S8*) email_p->prof_info.editing_prof.sig_info.img_name);

            mmi_ucs2cpy(
                (S8*) email_p->prof_info.editing_prof.sig_info.img_name,
                (S8*) LocalData->smtp_info.signature.attach.attach_file_name);
            fileExt = mmi_email_get_file_ext((S8*) email_p->prof_info.editing_prof.sig_info.img_name);

            mmi_ucs2cpy(
                (S8*) email_p->prof_info.editing_prof.sig_info.file_name,
                (S8*) email_p->prof_info.editing_prof.sig_info.img_name);
            mmi_email_util_get_sig_name(
                (U8) (email_p->prof_info.prof_misc.curr_sel_prof + 1),
                (S8*) email_p->prof_info.editing_prof.sig_info.file_path);
            mmi_ucs2cat((S8*) email_p->prof_info.editing_prof.sig_info.file_path, (S8*) fileExt);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_set_acct_data
 * DESCRIPTION
 *  Fill account data to to message struct for protocol
 * PARAMETERS
 *  msgReq      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_set_acct_data(mmi_email_set_acct_profile_req_struct *msgReq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set active profile index */
    msgReq->acct_index = email_p->prof_info.prof_misc.curr_sel_prof + 1;
    memset(&msgReq->acct, 0, sizeof(mmi_acct_profile_struct));

    switch (email_p->prof_info.prof_misc.curr_scr)
    {
        case SCR_ID_EMAIL_PROF_SETTING:
        {
            /* account name info */
            msgReq->acct.acct_name_len =
                ENCODING_LENGTH * (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.setting_info.prof_name);
            if (msgReq->acct.acct_name_len != 0)
            {
                memcpy(
                    (void*)msgReq->acct.acct_name,
                    (void*)email_p->prof_info.editing_prof.setting_info.prof_name,
                    msgReq->acct.acct_name_len);
            }
            msgReq->acct.bit_flag |= EMAIL_ACCT_NAME_LEN_FLAG;
            msgReq->acct.bit_flag |= EMAIL_ACCT_NAME_FLAG;

            /* service type */
            msgReq->acct.imap_pop3_info.service_type = (U32) email_p->prof_info.editing_prof.setting_info.data_acct;
            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_SERVICE_TYPE_FLAG;

        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            /* in protocol */
            msgReq->acct.imap_pop3_info.in_protocol = (U8) email_p->prof_info.editing_prof.setting_info.in_prot;
            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_PROTO_FLAG;
            /* update port information */
            if (email_p->prof_info.prof_misc.curr_prot != email_p->prof_info.editing_prof.setting_info.in_prot)
            {
                if (email_p->prof_info.editing_prof.setting_info.in_prot == EMAIL_PROT_POP3)
                {
                    msgReq->acct.in_address.port_number = EMAIL_DEFAULT_POP3_PORT;
                }
                else
                {
                    msgReq->acct.in_address.port_number = EMAIL_DEFAULT_IMAP4_PORT;
                }
                msgReq->acct.in_address.bit_flag |= EMAIL_ADDR_PORT_FLAG;
                msgReq->acct.bit_flag |= EMAIL_ACCT_IN_ADDR_FLAG;
            }
        #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

        #if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
            /* set check interval */
            switch (email_p->prof_info.editing_prof.setting_info.chk_interval)
            {
                case 1:
                    msgReq->acct.imap_pop3_info.check_interval = 5;
                    break;
                case 2:
                    msgReq->acct.imap_pop3_info.check_interval = 30;
                    break;
                case 3:
                    msgReq->acct.imap_pop3_info.check_interval = 60;
                    break;
                case 4:
                    msgReq->acct.imap_pop3_info.check_interval = 120;
                    break;
                default:
                    msgReq->acct.imap_pop3_info.check_interval = 0;
                    break;  /* case 0 */
            };
            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_CHECK_INTERVAL_FLAG;
        #endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
            /* set download size */
            msgReq->acct.imap_pop3_info.max_download_size =
                (U32) gui_atoi((UI_string_type) email_p->prof_info.editing_prof.setting_info.dwnl_size);
            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_MAX_SIZE_FLAG;

            /* bit flag POP3 */
            msgReq->acct.bit_flag |= EMAIL_ACCT_IN_FLAG;

            /* reply-to */
            msgReq->acct.smtp_info.reply_to_addr_len =
                (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.setting_info.reply_to);
            if (msgReq->acct.smtp_info.reply_to_addr_len)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.smtp_info.reply_to_addr,
                    (S8*) email_p->prof_info.editing_prof.setting_info.reply_to);
            }
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_REPLY_TO_ADDR_LEN_FLAG;
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_REPLY_TO_ADDR_FLAG;

            msgReq->acct.bit_flag |= EMAIL_ACCT_OUT_FLAG;
        }
        break;

        case SCR_ID_EMAIL_PROF_SMTP:
        {
            /* outgoing server */
            msgReq->acct.out_address.server_name_len =
                (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.smtp_info.out_server);
            if (msgReq->acct.out_address.server_name_len > 0)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.out_address.server_name,
                    (S8*) email_p->prof_info.editing_prof.smtp_info.out_server);
            }
            msgReq->acct.out_address.bit_flag |= EMAIL_ADDR_SERVER_FLAG;
            msgReq->acct.out_address.bit_flag |= EMAIL_ADDR_SERVER_LEN_FLAG;
            /* outgoing port */
            msgReq->acct.out_address.port_number =
                (U16) gui_atoi((UI_string_type) email_p->prof_info.editing_prof.smtp_info.out_port);
            msgReq->acct.out_address.bit_flag |= EMAIL_ADDR_PORT_FLAG;

            msgReq->acct.bit_flag |= EMAIL_ACCT_OUT_ADDR_FLAG;

            /* email address */
            msgReq->acct.smtp_info.email_addr_len =
                (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.smtp_info.email_addr);
            if (msgReq->acct.smtp_info.email_addr_len)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.smtp_info.email_address,
                    (S8*) email_p->prof_info.editing_prof.smtp_info.email_addr);
            }
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_EMAIL_ADDR_LEN_FLAG;
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_EMAIL_ADDR_FLAG;

            /* display name */
            msgReq->acct.smtp_info.charset_disp_name = MMI_CHSET_UTF8;
            msgReq->acct.smtp_info.disp_name_len =
                (U16) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.smtp_info.disp_name) * ENCODING_LENGTH;
            if (msgReq->acct.smtp_info.disp_name_len)
            {
                U8 *tempPtr;
                U16 outLen;

                tempPtr = mmi_email_util_ucs2_to_chset(
                            (U8*) email_p->prof_info.editing_prof.smtp_info.disp_name,
                            msgReq->acct.smtp_info.disp_name_len,
                            (U8) msgReq->acct.smtp_info.charset_disp_name,
                            &outLen);
                if (tempPtr != NULL)
                {
                    --outLen;
                    msgReq->acct.smtp_info.disp_name_len = (U8) outLen;
                    memcpy(msgReq->acct.smtp_info.display_name, tempPtr, msgReq->acct.smtp_info.disp_name_len);
                    /* not required to set null terminate because whole structure is already set to 0 */
                    OslMfree(tempPtr);
                }
            }

            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_DISP_NAME_CHARSET_FLAG;
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_DISP_NAME_LEN_FLAG;
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_DISP_NAME_FLAG;

            /*SMTP authentication*/
            msgReq->acct.smtp_info.smtp_auth =
                (MMI_BOOL) email_p->prof_info.editing_prof.smtp_info.auth_flag;
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_AUTH_FLAG;

            /*flag of whether SMTP authentication is same to incoming server*/
            msgReq->acct.smtp_info.smtp_auth_same =
                (MMI_BOOL) email_p->prof_info.editing_prof.smtp_info.auth_same_flag;
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_AUTH_SAME_FLAG;

            /* SMTP username */
            msgReq->acct.smtp_info.login_info.user_name_length =
                (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.smtp_info.user_name);
            if (msgReq->acct.smtp_info.login_info.user_name_length)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.smtp_info.login_info.user_name,
                    (S8*) email_p->prof_info.editing_prof.smtp_info.user_name);
            }

            /* SMTP password */
            msgReq->acct.smtp_info.login_info.pass_word_length =
                (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.smtp_info.passwd);
            if (msgReq->acct.smtp_info.login_info.pass_word_length)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.smtp_info.login_info.pass_word,
                    (S8*) email_p->prof_info.editing_prof.smtp_info.passwd);
            }

            msgReq->acct.smtp_info.login_info.bit_flag |= EMAIL_LOGIN_USER_LEN_FLAG;
            msgReq->acct.smtp_info.login_info.bit_flag |= EMAIL_LOGIN_USER_FLAG;
            msgReq->acct.smtp_info.login_info.bit_flag |= EMAIL_LOGIN_PASS_LEN_FLAG;
            msgReq->acct.smtp_info.login_info.bit_flag |= EMAIL_LOGIN_PASS_FLAG;
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_LOGIN_FLAG;
            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_AUTH_FLAG;

            msgReq->acct.bit_flag |= EMAIL_ACCT_OUT_FLAG;

            /* always set profile name */
            msgReq->acct.acct_name_len =
                ENCODING_LENGTH * (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.setting_info.prof_name);
            if (msgReq->acct.acct_name_len != 0)
            {
                memcpy(
                    (S8*) msgReq->acct.acct_name,
                    (void*)email_p->prof_info.editing_prof.setting_info.prof_name,
                    msgReq->acct.acct_name_len);
            }
            msgReq->acct.bit_flag |= EMAIL_ACCT_NAME_LEN_FLAG;
            msgReq->acct.bit_flag |= EMAIL_ACCT_NAME_FLAG;
        }
            break;
        case SCR_ID_EMAIL_PROF_POP3_IMAP4:
        {
            /* Incoming port */
            msgReq->acct.in_address.port_number =
                (U16) gui_atoi((UI_string_type) email_p->prof_info.editing_prof.pop_imap_info.in_port);;
            msgReq->acct.in_address.bit_flag |= EMAIL_ADDR_PORT_FLAG;

            /* Incoming server name */
            msgReq->acct.in_address.server_name_len =
                (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.pop_imap_info.in_server);
            if (msgReq->acct.in_address.server_name_len)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.in_address.server_name,
                    (S8*) email_p->prof_info.editing_prof.pop_imap_info.in_server);
            }
            msgReq->acct.in_address.bit_flag |= EMAIL_ADDR_SERVER_FLAG;
            msgReq->acct.in_address.bit_flag |= EMAIL_ADDR_SERVER_LEN_FLAG;
            msgReq->acct.bit_flag |= EMAIL_ACCT_IN_ADDR_FLAG;

        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            /* draft folder name */
            msgReq->acct.imap_pop3_info.draft_name_len = mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.pop_imap_info.draft_name);
            if (msgReq->acct.imap_pop3_info.draft_name_len)
            {
                msgReq->acct.imap_pop3_info.draft_name_len = mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)email_p->prof_info.editing_prof.pop_imap_info.draft_name, (char*)msgReq->acct.imap_pop3_info.draft_name, (S32) (MMI_EMAIL_MAX_FOLDER_NAME + 1)) - 1;    /* neglect null terminate */
            }

            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_DRAFT_NAME_FLAG;
            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_DRAFT_NAME_LEN_FLAG;

            /* sent folder name */
            msgReq->acct.imap_pop3_info.sent_name_len = mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.pop_imap_info.sent_name);
            if (msgReq->acct.imap_pop3_info.sent_name_len)
            {
                msgReq->acct.imap_pop3_info.sent_name_len = mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)email_p->prof_info.editing_prof.pop_imap_info.sent_name, (char*)msgReq->acct.imap_pop3_info.sent_name, (S32) (MMI_EMAIL_MAX_FOLDER_NAME + 1)) - 1;       /* neglect null terminate */
            }
            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_SENT_NAME_FLAG;
            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_SENT_NAME_LEN_FLAG;
            msgReq->acct.bit_flag |= EMAIL_ACCT_IN_FLAG;
        #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            /* user name */
            msgReq->acct.login_info.user_name_length =
                (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.pop_imap_info.user_name);
            if (msgReq->acct.login_info.user_name_length)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.login_info.user_name,
                    (S8*) email_p->prof_info.editing_prof.pop_imap_info.user_name);
            }
            msgReq->acct.login_info.bit_flag |= EMAIL_LOGIN_USER_LEN_FLAG;
            msgReq->acct.login_info.bit_flag |= EMAIL_LOGIN_USER_FLAG;
            /* password */
            msgReq->acct.login_info.pass_word_length =
                (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.pop_imap_info.passwd);
            if (msgReq->acct.login_info.pass_word_length)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.login_info.pass_word,
                    (S8*) email_p->prof_info.editing_prof.pop_imap_info.passwd);
            }
            msgReq->acct.login_info.bit_flag |= EMAIL_LOGIN_PASS_LEN_FLAG;
            msgReq->acct.login_info.bit_flag |= EMAIL_LOGIN_PASS_FLAG;

            msgReq->acct.bit_flag |= EMAIL_ACCT_LOGIN_FLAG;

            msgReq->acct.imap_pop3_info.leave_copy_on_server =
                (MMI_BOOL) email_p->prof_info.editing_prof.pop_imap_info.copy_on_server;
            msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_LEAVE_COPY_FLAG;

            msgReq->acct.bit_flag |= EMAIL_ACCT_IN_FLAG;

        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            if (email_p->prof_info.editing_prof.setting_info.in_prot == EMAIL_PROT_POP3)
        #endif 
            {
                if (msgReq->acct.imap_pop3_info.leave_copy_on_server == MMI_TRUE)
                {
                #ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
                    /* delete after n days */
                    msgReq->acct.imap_pop3_info.del_after_n_days =
                        (U16) gui_atoi((UI_string_type) email_p->prof_info.editing_prof.pop_imap_info.del_after_n_days);
                    msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_DEL_AFTER_N_DAYS_FLAG;
                #endif /* __MMI_EMAIL_DEL_AFTER_N_DAYS__ */ 

                    msgReq->acct.imap_pop3_info.del_server_mails =
                        (MMI_BOOL) email_p->prof_info.editing_prof.pop_imap_info.del_server_mails;
                    msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_DEL_SERVER_MAILS_FLAG;
                }
            }

        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            if (email_p->prof_info.editing_prof.setting_info.in_prot == EMAIL_PROT_IMAP4)
            {
                msgReq->acct.imap_pop3_info.download_option_imap4 =
                    email_p->prof_info.editing_prof.pop_imap_info.download_opt;
                msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_DOWNLOAD_OPTION_IMAP4_FLAG;
            }
            else
        #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            {
                msgReq->acct.imap_pop3_info.download_option_pop3 =
                    email_p->prof_info.editing_prof.pop_imap_info.download_opt;
                msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_DOWNLOAD_OPTION_POP3_FLAG;
            }
            msgReq->acct.bit_flag |= EMAIL_ACCT_IN_FLAG;

            /* always set profile name */
            msgReq->acct.acct_name_len =
                ENCODING_LENGTH * (U8) mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.setting_info.prof_name);
            if (msgReq->acct.acct_name_len)
            {
                memcpy(
                    (S8*) msgReq->acct.acct_name,
                    (void*)email_p->prof_info.editing_prof.setting_info.prof_name,
                    msgReq->acct.acct_name_len);
            }
            msgReq->acct.bit_flag |= EMAIL_ACCT_NAME_LEN_FLAG;
            msgReq->acct.bit_flag |= EMAIL_ACCT_NAME_FLAG;
        }
            break;
        case SCR_ID_EMAIL_PROF_SIG:
        {
            /* status ON/OFF info */
            msgReq->acct.smtp_info.signature.on_off = (MMI_BOOL) email_p->prof_info.editing_prof.sig_info.sig_status;

            /* TEXT data info */
            msgReq->acct.smtp_info.signature.charset_text = MMI_CHSET_UTF8;
            msgReq->acct.smtp_info.signature.text_len = mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.sig_buff);
            if (msgReq->acct.smtp_info.signature.text_len)
            {
                msgReq->acct.smtp_info.signature.text_len
                    = mmi_chset_convert(
                        MMI_CHSET_UCS2,
                        MMI_CHSET_UTF8,
                        (char*)email_p->prof_info.editing_prof.sig_info.sig_buff,
                        (char*)msgReq->acct.smtp_info.signature.text,
                        (S32) (MMI_EMAIL_MAX_SIG_TEXT + 1));

                if (msgReq->acct.smtp_info.signature.text_len != 0)
                {
                    msgReq->acct.smtp_info.signature.text_len--;
                }

                msgReq->acct.smtp_info.signature.signature_type |= MMI_EMAIL_SIG_IS_TEXT;
            }

            /* image */
            msgReq->acct.smtp_info.signature.attach.attach_path_len = mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.img_name) * ENCODING_LENGTH;
            if (msgReq->acct.smtp_info.signature.attach.attach_path_len)
            {
                mmi_email_util_get_mine_type(
                    (S8*) email_p->prof_info.editing_prof.sig_info.file_name,
                    &msgReq->acct.smtp_info.signature.attach.mime_type,
                    &msgReq->acct.smtp_info.signature.attach.mime_subtype);
                mmi_ucs2cpy(
                    (S8*) msgReq->acct.smtp_info.signature.attach.attach_file_name,
                    (S8*) email_p->prof_info.editing_prof.sig_info.img_name);
                msgReq->acct.smtp_info.signature.attach.charset_attach = MMI_CHSET_UCS2;

                msgReq->acct.smtp_info.signature.signature_type |= MMI_EMAIL_SIG_IS_ATTACH;
            }

            msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_SIG_FLAG;
            msgReq->acct.bit_flag |= EMAIL_ACCT_OUT_FLAG;
        }
            break;
    }
}

#endif /* __MMI_EMAIL__ */
#endif /* _MMI_EMAILAPPPSINTERFACE_C */

