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
 * PoCCallManagement.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements poc management functions
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/* micha_PoC */

#ifdef __MMI_POC__

#ifndef __MTK_TARGET__
#include <Windows.h>
#endif
#include "MMI_include.h"
#include "mdi_datatype.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "wgui_status_icons.h"  /* for STATUS_ICON */
#include "mdi_include.h"
#include "mdi_audio.h"
#include "CallmanagementIdDef.h"
#include "custom_data_account.h"
#include "DataAccountGProt.h"
#include "gpioInc.h"
#include "AudioInc.h"
#include "ProfileGprots.h"
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

#include "wap_ps_struct.h"
#include "CallManagementGprot.h"

#define WT_SERVER "http://xdm-devel.wt.fi"
// #define WT_SERVER "http://xdm.wt.fi"



/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_cm_add_user
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_cm_add_user(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_cm_add_user, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_cm_add_user, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_cm_subscribe
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_cm_subscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_status_subscribe, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_cm_unsubscribe
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_cm_unsubscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_status_unsubscribe, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_cm_talk_group
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_cm_talk_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_status
 * DESCRIPTION
 *  Entry function when user select Status in PoC Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_STATUS);

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

    ClearInputEventHandler(MMI_DEVICE_ALL);

    switch (g_poc_cntx_p->curr_reg_state)
    {
        case POC_REG_NONE:
            g_poc_cntx_p->curr_reg_state = POC_REG_REGING;
            mmi_poc_entry_registering();
            mmi_poc_wps_query_req();
            break;
        case POC_REG_REGED:
            g_poc_cntx_p->curr_reg_state = POC_REG_DEREGING;
            mmi_poc_entry_registering();
            if (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE)
            {
                mmi_poc_dereg_pres_unsubscribe_req();
            }
            else
            {
                mmi_poc_deregister_req();
            }
            break;
        case POC_REG_REGING:
        case POC_REG_DEREGING:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_PROCESSING),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_poweron_reg
 * DESCRIPTION
 *  Power on registration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_poweron_reg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_init_prof_setting_check(NULL);

    if (mmi_dtcnt_get_bearer_type(g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].data_account) != DATA_ACCOUNT_BEARER_GPRS)
    {
        return;
    }

    if ((g_poc_cntx_p->power_on_reg_sent == POC_BOOTREG_NONE) && (g_poc_cntx_p->curr_boot_start_mode == MMI_TRUE) &&
        (g_poc_cntx_p->curr_reg_state == POC_REG_NONE))
    {
        g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_SENT;
        g_poc_cntx_p->curr_reg_state = POC_REG_REGING;

        mmi_poc_wps_query_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_poweron_reg_wifi
 * DESCRIPTION
 *  Power on registration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_poweron_reg_wifi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_init_prof_setting_check(NULL);

    if (mmi_dtcnt_get_bearer_type(g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].data_account) != DATA_ACCOUNT_BEARER_WIFI)
    {
        return;
    }

    if ((g_poc_cntx_p->power_on_reg_sent == POC_BOOTREG_NONE) && (g_poc_cntx_p->curr_boot_start_mode == MMI_TRUE) &&
        (g_poc_cntx_p->curr_reg_state == POC_REG_NONE))
    {
        g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_SENT;
        g_poc_cntx_p->curr_reg_state = POC_REG_REGING;

        mmi_poc_wps_query_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_poweroff_dereg
 * DESCRIPTION
 *  Power off deregistration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_poweroff_dereg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_reg_state == POC_REG_REGED)
    {
        g_poc_cntx_p->curr_reg_state = POC_REG_DEREGING;
        mmi_poc_register_req();
        ClearProtocolEventHandler(PRT_POC_REGISTER_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_wps_query_req
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_wps_query_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_poc_cntx_p->progressing, 0, sizeof(g_poc_cntx_p->progressing));
    memset(g_poc_cntx_p->contact_list, 0, sizeof(g_poc_cntx_p->contact_list));
    memset(g_poc_cntx_p->talk_group_list, 0, sizeof(g_poc_cntx_p->talk_group_list));
    g_poc_cntx_p->contact_local_updated = MMI_FALSE;
    g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;

    SetProtocolEventHandler(mmi_poc_wps_query_rsp, MSG_ID_WPS_STATUS_QUERY_RSP);
    SetProtocolEventHandler(mmi_poc_wps_ready_ind, MSG_ID_WPS_READY_IND);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WPS;
    Message.oslMsgId = MSG_ID_WPS_STATUS_QUERY_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_wps_query_rsp
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_wps_query_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_status_query_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (wps_status_query_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_WPS_STATUS_QUERY_RSP);

    if (msgRsp->status == KAL_TRUE)
    {
        ClearProtocolEventHandler(MSG_ID_WPS_READY_IND);
        if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
        {
            mmi_poc_group_init_req();
        }
        else
        {
            mmi_poc_register_req();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_wps_ready_ind
 * DESCRIPTION
 *  wps ready indication
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_wps_ready_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_WPS_STATUS_QUERY_RSP);
    ClearProtocolEventHandler(MSG_ID_WPS_READY_IND);

    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        mmi_poc_group_init_req();
    }
    else
    {
        mmi_poc_register_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_group_init_req
 * DESCRIPTION
 *  PoC group init request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_group_init_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_group_init_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_group_init_req_struct*) OslConstructDataPtr(sizeof(poc_group_init_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_group_init_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->net_id = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].data_account;
    memcpy(
        myMsgPtr->root_uri,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].xdm_addr,
        XDM_ROOT_URI_LEN * sizeof(U8));
    memcpy(myMsgPtr->xui, g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].uri, XDM_XUI_LEN * sizeof(U8));
    memcpy(
        myMsgPtr->password,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].password,
        XDM_PASSWD_LEN * sizeof(U8));
    myMsgPtr->use_proxy = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].use_proxy;
    memcpy(
        myMsgPtr->prx_ip,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].proxy_ip,
        XDM_MAX_IP_LEN * sizeof(U8));
    myMsgPtr->prx_port = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].proxy_port;

    memcpy(
        myMsgPtr->proxy_username,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].proxy_username,
        XDM_MAX_PROXY_USERNAME_LEN * sizeof(U8));
    memcpy(
        myMsgPtr->proxy_pass,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].proxy_password,
        XDM_MAX_PROXY_PASS_LEN * sizeof(U8));

    SetProtocolEventHandler(mmi_poc_group_init_rsp, MSG_ID_POC_GROUP_INIT_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_GROUP_INIT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_group_init_rsp
 * DESCRIPTION
 *  PoC group init response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_group_init_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_init_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_group_init_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_GROUP_INIT_RSP);

    if (msgRsp->result == POC_OK)
    {
        g_poc_cntx_p->curr_group_id = 0;
        g_poc_cntx_p->curr_entry_id = 0;
        memset(
            g_poc_cntx_p->contact_list,
            0,
            sizeof(mmi_poc_contact_struct) * MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM);
        mmi_poc_get_group_list_req();
    }
    else
    {
        if (g_poc_cntx_p->power_on_reg_sent == POC_BOOTREG_SENT)
        {
            g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_NONE;
        }
        else
        {
            g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_FINISH;
        }
        if (((GetActiveScreenId() == SCR_ID_POC_REG) || (GetActiveScreenId() == SCR_ID_POC_MAIN)))
        {
            mmi_poc_show_error_cause(POC_XDM_ERROR, 0);
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);
        g_poc_cntx_p->curr_reg_state = POC_REG_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_get_group_list_req
 * DESCRIPTION
 *  Get contact list request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_get_group_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_get_group_list_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_get_group_list_req_struct*) OslConstructDataPtr(sizeof(poc_get_group_list_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_get_group_list_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->request_id = POC_REQUEST_ID;
    myMsgPtr->start_group = g_poc_cntx_p->curr_group_id;
    myMsgPtr->start_entry = g_poc_cntx_p->curr_entry_id;

    if (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE)
    {
        myMsgPtr->xdm_item = POC_XDM_GL_PRESENT | POC_XDM_AL_PRESENT | POC_XDM_AR_PRESENT | POC_XDM_RLS_PRESENT;
    }
    else
    {
        myMsgPtr->xdm_item = POC_XDM_GL_PRESENT | POC_XDM_AL_PRESENT;
    }

    g_poc_cntx_p->contact_local_updated = MMI_FALSE;

    SetProtocolEventHandler(mmi_poc_get_group_list_rsp, MSG_ID_POC_GET_GROUP_LIST_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_GET_GROUP_LIST_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_get_group_list_rsp
 * DESCRIPTION
 *  Get contact list response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_get_group_list_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, temp_idx;
    poc_get_group_list_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_get_group_list_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_GET_GROUP_LIST_RSP);

    if (msgRsp->result == POC_OK)
    {
        if (g_poc_cntx_p->curr_entry_id == 0)
        {
            g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].valid = MMI_TRUE;
            memcpy(
                g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].list_name,
                msgRsp->list_name,
                POC_MAX_DISP_LEN * sizeof(U8));
        }

        for (i = 0; i < msgRsp->no_entries; i++)
        {
            if (g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].no_entries < POC_GROUP_LOCAL_MAX_ENTRIES_NUM)
            {
                temp_idx = g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].no_entries;
                g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].entries[temp_idx].allow_invite =
                    msgRsp->entries[i].allow_invite;
                g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].entries[temp_idx].sub_pres =
                    msgRsp->entries[i].sub_pres;
                memcpy(
                    &g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].entries[temp_idx].auth_rule,
                    &(msgRsp->entries[i].auth_rule),
                    sizeof(poc_pres_authrule_struct));
                switch (g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].entries[temp_idx].auth_rule.
                        sub_handling)
                {
                    case POC_PRES_ACTION_BLOCK:
                    case POC_PRES_ACTION_POLITE_BLOCK:
                    case POC_PRES_ACTION_ALLOW:
                        g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].entries[temp_idx].auth_rule.
                            sub_handling++;
                        break;
                    default:
                        g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].entries[temp_idx].auth_rule.
                            sub_handling = POC_MMI_SUB_EMPTY;
                        break;
                }
                memcpy(
                    g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].entries[temp_idx].uri,
                    msgRsp->entries[i].uri,
                    sizeof(U8) * POC_MAX_URI_LEN);
                memcpy(
                    g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].entries[temp_idx].display_name,
                    msgRsp->entries[i].disp_name,
                    sizeof(U8) * POC_MAX_DISP_LEN);

                g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].no_entries++;
            }
        }

        g_poc_cntx_p->curr_entry_id = g_poc_cntx_p->contact_list[g_poc_cntx_p->curr_group_id].no_entries;

        if (msgRsp->more_data == KAL_TRUE)
        {
            mmi_poc_get_group_list_req();
        }
        else if ((msgRsp->more_list == KAL_TRUE)
                 && (g_poc_cntx_p->curr_group_id < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM))
        {
            g_poc_cntx_p->curr_group_id++;
            g_poc_cntx_p->curr_entry_id = 0;
            mmi_poc_get_group_list_req();
        }
        else
        {
            g_poc_cntx_p->curr_group_id = 0;
            g_poc_cntx_p->curr_entry_id = 0;
            memset(
                g_poc_cntx_p->talk_group_list,
                0,
                sizeof(poc_talk_group_struct) * MAX_POC_TALK_GROUP_FILE_NUM * MAX_POC_TALK_GROUPS_PER_FILE_NUM);
            mmi_poc_get_talk_group_list_req();
        }
    }
    else if ((msgRsp->result == POC_XDM_ERROR) && (msgRsp->cause == POC_GRP_CAUSE_EMPTY_DIR))
    {
        mmi_poc_get_talk_group_list_req();
    }
    else
    {
        if (g_poc_cntx_p->power_on_reg_sent == POC_BOOTREG_SENT)
        {
            g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_NONE;
        }
        else
        {
            g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_FINISH;
        }
        if (((GetActiveScreenId() == SCR_ID_POC_REG) || (GetActiveScreenId() == SCR_ID_POC_MAIN)))
        {
            mmi_poc_show_error_cause(POC_XDM_ERROR, 0);
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);
        g_poc_cntx_p->curr_reg_state = POC_REG_NONE;
        mmi_poc_group_deinit_req();
        ClearProtocolEventHandler(MSG_ID_POC_GROUP_DEINIT_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_get_talk_group_list_req
 * DESCRIPTION
 *  Get talk group list request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_get_talk_group_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_get_talk_group_list_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_get_talk_group_list_req_struct*) OslConstructDataPtr(sizeof(poc_get_talk_group_list_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_get_talk_group_list_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->request_id = POC_REQUEST_ID;
    myMsgPtr->start_group = g_poc_cntx_p->curr_group_id;
    myMsgPtr->start_entry = g_poc_cntx_p->curr_entry_id;

    SetProtocolEventHandler(mmi_poc_get_talk_group_list_rsp, MSG_ID_POC_GET_TALK_GROUP_LIST_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_GET_TALK_GROUP_LIST_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_get_talk_group_list_rsp
 * DESCRIPTION
 *  Get talk group list response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_get_talk_group_list_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, temp_idx;
    poc_get_talk_group_list_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_get_talk_group_list_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_GET_TALK_GROUP_LIST_RSP);

    if (msgRsp->result == POC_OK)
    {
        if (g_poc_cntx_p->curr_entry_id == 0)
        {
            g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].valid = MMI_TRUE;
            memcpy(
                g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].list_uri,
                msgRsp->list_uri,
                POC_MAX_URI_LEN * sizeof(U8));
            g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].display_name_lang = msgRsp->display_name_lang;
            memcpy(
                g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].display_name,
                msgRsp->display_name,
                POC_MAX_DISP_LEN * sizeof(U8));
            g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].max_participant_count =
                msgRsp->max_participant_count;
            g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].invite_member = msgRsp->invite_member;
            memcpy(
                &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].default_rule,
                &msgRsp->default_rule,
                sizeof(poc_group_param_struct));
        }

        for (i = 0; i < msgRsp->no_entries; i++)
        {
            if (g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].no_entries <
                POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM)
            {
                temp_idx = g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].no_entries;
                memcpy(
                    &(g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].entries[temp_idx]),
                    &(msgRsp->entries[i]),
                    sizeof(poc_talk_group_entry_struct));
                g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].no_entries++;
            }
        }

        g_poc_cntx_p->curr_entry_id = g_poc_cntx_p->talk_group_list[g_poc_cntx_p->curr_group_id].no_entries;

        if (msgRsp->more_data == KAL_TRUE)
        {
            mmi_poc_get_talk_group_list_req();
        }
        else if ((msgRsp->more_group == KAL_TRUE)
                 && (g_poc_cntx_p->curr_group_id < MAX_POC_TALK_GROUP_FILE_NUM * MAX_POC_TALK_GROUPS_PER_FILE_NUM))
        {
            g_poc_cntx_p->curr_group_id++;
            g_poc_cntx_p->curr_entry_id = 0;
            mmi_poc_get_talk_group_list_req();
        }
        else
        {
            mmi_poc_register_req();
        }
    }
    else if (msgRsp->result == POC_XDM_ERROR && msgRsp->cause == POC_GRP_CAUSE_EMPTY_DIR)
    {
        mmi_poc_register_req();
    }
    else
    {
        if (g_poc_cntx_p->power_on_reg_sent == POC_BOOTREG_SENT)
        {
            g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_NONE;
        }
        else
        {
            g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_FINISH;
        }
        if (((GetActiveScreenId() == SCR_ID_POC_REG) || (GetActiveScreenId() == SCR_ID_POC_MAIN)))
        {
            mmi_poc_show_error_cause(POC_XDM_ERROR, 0);
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);
        g_poc_cntx_p->curr_reg_state = POC_REG_NONE;
        mmi_poc_group_deinit_req();
        ClearProtocolEventHandler(MSG_ID_POC_GROUP_DEINIT_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_register_req
 * DESCRIPTION
 *  PoC register request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_register_req(void)
{
#ifdef __POC_MMI_TEST_XDM_ONLY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_POC_REG)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else if (GetActiveScreenId() == SCR_ID_POC_MAIN)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_REGISTERED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    DeleteScreenIfPresent(SCR_ID_POC_REG);
    g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_FINISH;
    g_poc_cntx_p->curr_reg_state = POC_REG_REGED;
    ShowStatusIcon(STATUS_ICON_POC);
    UpdateStatusIcons();
#else /* __POC_MMI_TEST_XDM_ONLY__ */ 
    MYQUEUE Message;
    poc_register_req_struct *myMsgPtr;

    myMsgPtr = (poc_register_req_struct*) OslConstructDataPtr(sizeof(poc_register_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_register_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    ASSERT(g_poc_cntx_p->curr_reg_state == POC_REG_REGING || g_poc_cntx_p->curr_reg_state == POC_REG_DEREGING);

    myMsgPtr->action = POC_REGISTER_ACTION;
    memcpy(
        myMsgPtr->contact.disp_name,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].disp_name,
        POC_MAX_DISP_LEN * sizeof(U8));
    memcpy(
        myMsgPtr->contact.uri,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].uri,
        POC_MAX_URI_LEN * sizeof(U8));
    myMsgPtr->contact.disp_charset = 0;
    myMsgPtr->data_account = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].data_account;
    memcpy(
        myMsgPtr->proxy_addr,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].poc_addr,
        POC_PROXY_ADDR_LEN * sizeof(U8));
    myMsgPtr->proxy_port = g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].poc_port;
    memcpy(
        myMsgPtr->password,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].password,
        POC_MAX_PASSWORD_LEN * sizeof(U8));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_REGISTER_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_register_rsp, PRT_POC_REGISTER_RSP);
#endif /* __POC_MMI_TEST_XDM_ONLY__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_register_rsp
 * DESCRIPTION
 *  PoC register response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_register_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_register_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_register_rsp_struct*) info;

    ASSERT(g_poc_cntx_p->curr_reg_state == POC_REG_REGING || g_poc_cntx_p->curr_reg_state == POC_REG_DEREGING);

    ClearProtocolEventHandler(PRT_POC_REGISTER_RSP);

    if (msgRsp->result == POC_OK)
    {
        mmi_poc_reg_send_setting_req();
    }
    else
    {
        g_poc_cntx_p->curr_reg_state = POC_REG_NONE;
        if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
        {
            mmi_poc_group_deinit_req();
            ClearProtocolEventHandler(MSG_ID_POC_GROUP_DEINIT_RSP);
        }

        if (g_poc_cntx_p->power_on_reg_sent == POC_BOOTREG_SENT)
        {
            g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_NONE;
        }
        else
        {
            g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_FINISH;
        }

        if (((GetActiveScreenId() == SCR_ID_POC_REG) || (GetActiveScreenId() == SCR_ID_POC_MAIN)))
        {
            mmi_poc_show_error_cause(msgRsp->result, msgRsp->cause);
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);

        g_poc_cntx_p->curr_reg_state = POC_REG_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_register_ind
 * DESCRIPTION
 *  PoC periodically registration info update indication
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_register_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_register_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_register_ind_struct*) info;

    if (msgRsp->result != POC_OK)
    {
        ClearProtocolEventHandler(PRT_POC_REGISTER_RSP);
        ClearProtocolEventHandler(MSG_ID_POC_SETTING_RSP);
        ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
        ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_PUBLISH_RSP);

        if ((GetActiveScreenId() >= SCR_ID_POC_MAIN) && (GetActiveScreenId() < SCR_ID_POC_TOTAL))
        {
            TurnOnBacklight(1);
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }

        DeleteScreenIfPresent(SCR_ID_POC_INCOMING_ALERT);
        DeleteScreenIfPresent(SCR_ID_POC_HISTORY_INFO);
        DeleteScreenIfPresent(SCR_ID_POC_CM);
        mmi_poc_remove_cm_screens();
        if (IsScreenPresent(SCR_ID_POC_MAIN))
        {
            DeleteUptoScrID(SCR_ID_POC_MAIN);
        }

        /* Reset reg status */
        g_poc_cntx_p->curr_reg_state = POC_REG_NONE;
        HideStatusIcon(STATUS_ICON_POC);
        UpdateStatusIcons();
        if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
        {
            mmi_poc_group_deinit_req();
            ClearProtocolEventHandler(MSG_ID_POC_GROUP_DEINIT_RSP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_registering
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_registering(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 caption;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_REGISTERING);

    EntryNewScreen(SCR_ID_POC_REG, NULL, mmi_poc_entry_registering, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_REG);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_REG);

    if (g_poc_cntx_p->curr_reg_state == POC_REG_REGING)
    {
        caption = STR_ID_POC_REGISTERING;
    }
    else
    {
        caption = STR_ID_POC_DEREGISTERING;
    }

    ShowCategory141Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(caption),
        IMG_GLOBAL_PROGRESS,
        NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reg_send_setting_req
 * DESCRIPTION
 *  Send poc setting when registration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reg_send_setting_req(void)
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

    g_poc_cntx_p->reg_error = MMI_FALSE;

    myMsgPtr->data.auto_answer = g_poc_cntx_p->curr_ans_mode;
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

    SetProtocolEventHandler(mmi_poc_reg_send_setting_rsp, PRT_POC_SETTING_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reg_send_setting_rsp
 * DESCRIPTION
 *  Response for send PoC settings
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reg_send_setting_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_setting_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_setting_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_SETTING_RSP);

    if (msgRsp->result != POC_OK)
    {
        g_poc_cntx_p->reg_error = MMI_TRUE;
    }

    if (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE)
    {
        if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
        {
            mmi_poc_reg_pres_subscribe_req();
        }
        else
        {
            mmi_poc_reg_pres_publish_req();
        }
    }
    else
    {
        if (g_poc_cntx_p->reg_error == MMI_TRUE)
        {
            if (GetActiveScreenId() == SCR_ID_POC_REG)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
            else if (GetActiveScreenId() == SCR_ID_POC_MAIN)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
        }
        else
        {
            if (GetActiveScreenId() == SCR_ID_POC_REG)
            {
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
            else if (GetActiveScreenId() == SCR_ID_POC_MAIN)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_REGISTERED),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);
        g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_FINISH;
        g_poc_cntx_p->curr_reg_state = POC_REG_REGED;
        ShowStatusIcon(STATUS_ICON_POC);
        UpdateStatusIcons();
    }
}

#ifndef __POC_NON_RLS__


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reg_pres_subscribe_req
 * DESCRIPTION
 *  presence subscribe request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reg_pres_subscribe_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_subscribe_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_presence_subscribe_req_struct*) OslConstructDataPtr(sizeof(poc_presence_subscribe_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_presence_subscribe_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->action = POC_SUBSCRIBE_ACTION;
    myMsgPtr->use_presence_list = MMI_TRUE;

    memcpy(myMsgPtr->uri, POC_MMI_MTK_RLS_URI, POC_MAX_URI_LEN * sizeof(U8));
    strncat(
        (S8*) myMsgPtr->uri,
        (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].uri,
        POC_MAX_URI_LEN - sizeof(POC_MMI_MTK_RLS_URI) - 1);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_PRESENCE_SUBSCRIBE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_reg_pres_subscribe_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reg_pres_subscribe_rsp
 * DESCRIPTION
 *  presense subscribe response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reg_pres_subscribe_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_presence_subscribe_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_subscribe_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);

    if (msgRsp->result != POC_OK)
    {
        g_poc_cntx_p->reg_error = MMI_TRUE;
    }
    mmi_poc_reg_pres_publish_req();
}

#else /* __POC_NON_RLS__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reg_pres_subscribe_req
 * DESCRIPTION
 *  presence subscribe request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reg_pres_subscribe_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_subscribe_req_struct *myMsgPtr;
    static U8 curr_group = 0, curr_entry = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; (g_poc_cntx_p->contact_list[curr_group].valid == MMI_TRUE) &&
         (curr_group < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM); curr_group++)
    {
        for (; curr_entry < g_poc_cntx_p->contact_list[curr_group].no_entries; curr_entry++)
        {

            if (g_poc_cntx_p->contact_list[curr_group].entries[curr_entry].sub_pres == MMI_TRUE)
            {

                myMsgPtr =
                    (poc_presence_subscribe_req_struct*)
                    OslConstructDataPtr(sizeof(poc_presence_subscribe_req_struct));
                memset(
                    (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
                    0,
                    sizeof(poc_presence_subscribe_req_struct) - sizeof(mmi_poc_dummy_req_struct));

                myMsgPtr->action = POC_SUBSCRIBE_ACTION;
                myMsgPtr->use_presence_list = MMI_FALSE;

                memcpy(
                    myMsgPtr->uri,
                    g_poc_cntx_p->contact_list[curr_group].entries[curr_entry].uri,
                    POC_MAX_URI_LEN * sizeof(U8));

                Message.oslSrcId = MOD_MMI;
                Message.oslDestId = MOD_POC;
                Message.oslMsgId = MSG_ID_POC_PRESENCE_SUBSCRIBE_REQ;
                Message.oslDataPtr = (oslParaType*) myMsgPtr;
                Message.oslPeerBuffPtr = NULL;
                OslMsgSendExtQueue(&Message);

                SetProtocolEventHandler(mmi_poc_reg_pres_subscribe_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                curr_entry++;
                return;
            }
        }
        curr_entry = 0;
    }

    curr_group = 0;
    curr_entry = 0;
    mmi_poc_reg_pres_publish_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reg_pres_subscribe_rsp
 * DESCRIPTION
 *  presence subscribe response
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reg_pres_subscribe_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_presence_subscribe_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_subscribe_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);

    if (msgRsp->result != POC_OK)
    {
        g_poc_cntx_p->reg_error = MMI_TRUE;
    }
    mmi_poc_reg_pres_subscribe_req();
}

#endif /* __POC_NON_RLS__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reg_pres_publish_req
 * DESCRIPTION
 *  presence publish request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reg_pres_publish_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_publish_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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

    myMsgPtr->pinfo.person.activity_present = g_poc_cntx_p->person_pres.activity_present;
    myMsgPtr->pinfo.person.activity = g_poc_cntx_p->person_pres.activity;
    myMsgPtr->pinfo.person.mood_present = g_poc_cntx_p->person_pres.mood_present;
    myMsgPtr->pinfo.person.mood = g_poc_cntx_p->person_pres.mood;

    myMsgPtr->pinfo.num_service = 0;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_PRESENCE_PUBLISH_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_reg_pres_publish_rsp, MSG_ID_POC_PRESENCE_PUBLISH_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reg_pres_publish_rsp
 * DESCRIPTION
 *  presence publish response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reg_pres_publish_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_presence_publish_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_publish_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_PUBLISH_RSP);

    g_poc_cntx_p->power_on_reg_sent = POC_BOOTREG_FINISH;
    g_poc_cntx_p->curr_reg_state = POC_REG_REGED;
    ShowStatusIcon(STATUS_ICON_POC);
    UpdateStatusIcons();

    mdi_audio_set_background_handler(MDI_BACKGROUND_APP_POC, mmi_poc_mdi_background_handler);

    if (msgRsp->result != POC_OK)
    {
        g_poc_cntx_p->reg_error = MMI_TRUE;
    }

    if (g_poc_cntx_p->reg_error == MMI_TRUE)
    {
        if (GetActiveScreenId() == SCR_ID_POC_REG)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        else if (GetActiveScreenId() == SCR_ID_POC_MAIN)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_REG)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        else if (GetActiveScreenId() == SCR_ID_POC_MAIN)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_REGISTERED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
    }
    DeleteScreenIfPresent(SCR_ID_POC_REG);
}

#ifndef __POC_NON_RLS__


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_dereg_pres_unsubscribe_req
 * DESCRIPTION
 *  presence unsubscribe request for deregistration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_dereg_pres_unsubscribe_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_subscribe_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_presence_subscribe_req_struct*) OslConstructDataPtr(sizeof(poc_presence_subscribe_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_presence_subscribe_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    g_poc_cntx_p->reg_error = MMI_FALSE;

    myMsgPtr->action = POC_UNSUBSCRIBE_ACTION;
    myMsgPtr->use_presence_list = MMI_TRUE;

    memcpy(myMsgPtr->uri, POC_MMI_MTK_RLS_URI, POC_MAX_URI_LEN * sizeof(U8));
    strncat(
        (S8*) myMsgPtr->uri,
        (S8*) g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].uri,
        POC_MAX_URI_LEN - sizeof(POC_MMI_MTK_RLS_URI) - 1);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_PRESENCE_SUBSCRIBE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_dereg_pres_unsubscribe_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_dereg_pres_unsubscribe_rsp
 * DESCRIPTION
 *  response for presence unsubscribe when deregistering
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_dereg_pres_unsubscribe_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_presence_subscribe_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_subscribe_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);

#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 

    mmi_poc_dereg_pres_unpublish_req();
}

#else /* __POC_NON_RLS__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_dereg_pres_unsubscribe_req
 * DESCRIPTION
 *  Presence unscribe when deregistration
 * PARAMETERS
 *  void
 *  info(?)     [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_dereg_pres_unsubscribe_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_subscribe_req_struct *myMsgPtr;
    static U8 curr_group = 0, curr_entry = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; (g_poc_cntx_p->contact_list[curr_group].valid == MMI_TRUE) &&
         (curr_group < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM); curr_group++)
    {
        for (; curr_entry < g_poc_cntx_p->contact_list[curr_group].no_entries; curr_entry++)
        {

            if (g_poc_cntx_p->contact_list[curr_group].entries[curr_entry].sub_pres == MMI_TRUE)
            {

                myMsgPtr =
                    (poc_presence_subscribe_req_struct*)
                    OslConstructDataPtr(sizeof(poc_presence_subscribe_req_struct));
                memset(
                    (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
                    0,
                    sizeof(poc_presence_subscribe_req_struct) - sizeof(mmi_poc_dummy_req_struct));

                myMsgPtr->action = POC_UNSUBSCRIBE_ACTION;
                myMsgPtr->use_presence_list = MMI_FALSE;

                memcpy(
                    myMsgPtr->uri,
                    g_poc_cntx_p->contact_list[curr_group].entries[curr_entry].uri,
                    POC_MAX_URI_LEN * sizeof(U8));

                Message.oslSrcId = MOD_MMI;
                Message.oslDestId = MOD_POC;
                Message.oslMsgId = MSG_ID_POC_PRESENCE_SUBSCRIBE_REQ;
                Message.oslDataPtr = (oslParaType*) myMsgPtr;
                Message.oslPeerBuffPtr = NULL;
                OslMsgSendExtQueue(&Message);

                SetProtocolEventHandler(mmi_poc_dereg_pres_unsubscribe_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                curr_entry++;
                return;
            }
        }
        curr_entry = 0;
    }

    curr_group = 0;
    curr_entry = 0;
    mmi_poc_dereg_pres_unpublish_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_dereg_pres_unsubscribe_rsp
 * DESCRIPTION
 *  Presence unsubscribe response when deregistering
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_dereg_pres_unsubscribe_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_presence_subscribe_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_subscribe_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 
    mmi_poc_dereg_pres_unsubscribe_req();
}

#endif /* __POC_NON_RLS__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_dereg_pres_unpublish_req
 * DESCRIPTION
 *  presence unpublish request for deregistering
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_dereg_pres_unpublish_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_publish_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_presence_publish_req_struct*) OslConstructDataPtr(sizeof(poc_presence_publish_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_presence_publish_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->remove = MMI_TRUE;

    memcpy(
        myMsgPtr->pinfo.entity,
        g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].uri,
        POC_MAX_URI_LEN * sizeof(U8));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_PRESENCE_PUBLISH_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_dereg_pres_unpublish_rsp, MSG_ID_POC_PRESENCE_PUBLISH_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_dereg_pres_unpublish_rsp
 * DESCRIPTION
 *  presence unpublish response when deregistering
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_dereg_pres_unpublish_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_presence_publish_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_publish_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_PUBLISH_RSP);
    mmi_poc_deregister_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_deregister_req
 * DESCRIPTION
 *  poc deregister request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_deregister_req(void)
{
#ifdef __POC_MMI_TEST_XDM_ONLY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->curr_reg_state = POC_REG_NONE;
    HideStatusIcon(STATUS_ICON_POC);

    UpdateStatusIcons();
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        mmi_poc_group_deinit_req();
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_REG)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        else if (GetActiveScreenId() == SCR_ID_POC_MAIN)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_DEREGISTERED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);
    }
#else /* __POC_MMI_TEST_XDM_ONLY__ */ 
    MYQUEUE Message;
    poc_register_req_struct *myMsgPtr;

    myMsgPtr = (poc_register_req_struct*) OslConstructDataPtr(sizeof(poc_register_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_register_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->action = POC_DEREGISTER_ACTION;
    memset(&myMsgPtr->contact, 0, sizeof(poc_addr_struct));
    myMsgPtr->data_account = 0;
    memset(myMsgPtr->proxy_addr, 0, POC_PROXY_ADDR_LEN * sizeof(U8));
    myMsgPtr->proxy_port = 0;
    memset(myMsgPtr->password, 0, POC_MAX_PASSWORD_LEN * sizeof(U8));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_REGISTER_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_deregister_rsp, PRT_POC_REGISTER_RSP);
#endif /* __POC_MMI_TEST_XDM_ONLY__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_deregister_rsp
 * DESCRIPTION
 *  poc deregister response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_deregister_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_register_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_register_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_REGISTER_RSP);

    if (msgRsp->result != POC_OK)
    {
        g_poc_cntx_p->reg_error = MMI_TRUE;
    }

    g_poc_cntx_p->curr_reg_state = POC_REG_NONE;
    HideStatusIcon(STATUS_ICON_POC);

    UpdateStatusIcons();
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        mmi_poc_group_deinit_req();
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_REG)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        else if (GetActiveScreenId() == SCR_ID_POC_MAIN)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_DEREGISTERED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_group_deinit_req
 * DESCRIPTION
 *  poc group de-init request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_group_deinit_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_poc_group_deinit_rsp, MSG_ID_POC_GROUP_DEINIT_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_GROUP_DEINIT_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_group_deinit_rsp
 * DESCRIPTION
 *  poc group deinit response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_group_deinit_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_deinit_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_group_deinit_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_GROUP_DEINIT_RSP);

    memset(&g_poc_cntx_p->progressing, 0, sizeof(g_poc_cntx_p->progressing));

    if (msgRsp->result != POC_OK)
    {
        g_poc_cntx_p->reg_error = MMI_TRUE;
    }

    if (g_poc_cntx_p->reg_error != MMI_TRUE)
    {
        if (GetActiveScreenId() == SCR_ID_POC_REG)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        else if (GetActiveScreenId() == SCR_ID_POC_MAIN)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_DEREGISTERED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);
    }
    else
    {
        if (((GetActiveScreenId() == SCR_ID_POC_REG) || (GetActiveScreenId() == SCR_ID_POC_MAIN)))
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_REG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_1_to_1_invite
 * DESCRIPTION
 *  1 to 1 invitation through contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_1_to_1_invite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_addr_struct callee[POC_MAX_ADDR_NUM];
    mmi_poc_contact_list_disp *cont;

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

    g_poc_cntx_p->ptt_button_status = POC_PTT_DOWN;

    cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];

    memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
    g_poc_cntx_p->cm_talk_list_num = 0;

    strncpy(
        (S8*) g_poc_cntx_p->calling_disp.name,
        (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
        POC_MAX_DISP_LEN - 1);
    strncpy(
        (S8*) g_poc_cntx_p->calling_disp.uri,
        (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
        POC_MAX_URI_LEN - 1);

    memset(callee, 0, sizeof(callee));
    memcpy(
        callee[0].disp_name,
        g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
        sizeof(callee[0].disp_name));
    memcpy(
        callee[0].uri,
        g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
        sizeof(callee[0].uri));

    memset(g_poc_cntx_p->cm_talk_group_name, 0, sizeof(g_poc_cntx_p->cm_talk_group_name));

    mmi_poc_entry_inviting();
    mmi_poc_talk_invite_req(POC_1_TO_1_TALK, 1, callee, 0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_invite
 * DESCRIPTION
 *  poc talk group invite
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_invite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_addr_struct callee[POC_MAX_ADDR_NUM];

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

    g_poc_cntx_p->ptt_button_status = POC_PTT_DOWN;

    memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
    g_poc_cntx_p->cm_talk_list_num = 0;

    strncpy(
        (S8*) g_poc_cntx_p->calling_disp.name,
        (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].display_name,
        POC_MAX_DISP_LEN - 1);
    strncpy(
        (S8*) g_poc_cntx_p->calling_disp.uri,
        (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].list_uri,
        POC_MAX_URI_LEN - 1);

    memset(callee, 0, sizeof(callee));
    memcpy(
        callee[0].disp_name,
        g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].display_name,
        sizeof(callee[0].disp_name));
    memcpy(
        callee[0].uri,
        g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].list_uri,
        sizeof(callee[0].uri));

    memset(g_poc_cntx_p->cm_talk_group_name, 0, sizeof(g_poc_cntx_p->cm_talk_group_name));
    if (strlen((S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].display_name))
    {
        strncpy(
            (S8*) g_poc_cntx_p->cm_talk_group_name,
            (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].display_name,
            POC_MAX_DISP_LEN - 1);
    }
    else
    {
        strncpy(
            (S8*) g_poc_cntx_p->cm_talk_group_name,
            (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].list_uri,
            POC_MAX_DISP_LEN - 1);
    }

    mmi_poc_entry_inviting();

    if (g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].invite_member == MMI_TRUE)
    {
        mmi_poc_talk_invite_req(POC_PRE_ARRANGED_GROUP_TALK, 1, callee, 0, 0, 0);
    }
    else
    {
        mmi_poc_talk_invite_req(POC_CHAT_GROUP_TALK, 1, callee, 0, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_invite_req
 * DESCRIPTION
 *  poc talk group invite request
 * PARAMETERS
 *  talk_type       [IN]        Talk type
 *  no_callee       [IN]        Number of callees
 *  callee          [IN]        Callee address structure
 *  talk_id         [IN]        Talk id
 *  refer           [IN]        Refer flag
 *  rejoin          [IN]        Rejoin flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_invite_req(U8 talk_type, U8 no_callee, poc_addr_struct *callee, U32 talk_id, U8 refer, U8 rejoin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_talk_invite_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_talk_invite_req_struct*) OslConstructDataPtr(sizeof(poc_talk_invite_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_talk_invite_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->request_id = POC_REQUEST_ID;

    myMsgPtr->talk_type = talk_type;
    myMsgPtr->num_addr = no_callee;
    memcpy(myMsgPtr->callee, callee, sizeof(myMsgPtr->callee));

    myMsgPtr->talk_id = talk_id;
    myMsgPtr->refer = refer;
    myMsgPtr->mao = g_poc_cntx_p->curr_mao_mode;
    myMsgPtr->rejoin = rejoin;

    if (refer == 0)
    {
        g_poc_cntx_p->talk_pres_ind_recved = POC_TALK_STATUS_NOT_READY;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_TALK_INVITE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    g_poc_cntx_p->floor_idle_recved = MMI_FALSE;
    g_poc_cntx_p->call_status = POC_CALL_ACTIVE;
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);

    SetProtocolEventHandler(mmi_poc_invite_rsp, PRT_POC_TALK_INVITE_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_invite_rsp
 * DESCRIPTION
 *  poc invite response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_invite_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_talk_invite_rsp_struct *msgRsp;
    U8 list_name[POC_MAX_DISP_LEN];
    U8 uri[POC_MAX_URI_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_talk_invite_rsp_struct*) info;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_INVITE_RSP, (S32) g_poc_cntx_p->ptt_button_status);

    ClearProtocolEventHandler(PRT_POC_TALK_INVITE_RSP);

    if (msgRsp->result == POC_OK)
    {
        g_poc_cntx_p->active_talk_id = msgRsp->talk_id;
        g_poc_cntx_p->call_status = POC_CALL_ACTIVE;
        if (IsScreenPresent(SCR_ID_POC_CM))
        {
            HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_connected_idle);
        }
        else if (GetActiveScreenId() == SCR_ID_POC_CM)
        {
            mmi_poc_entry_connected_idle();
        }
    }
    else
    {
        g_poc_cntx_p->call_status = POC_CALL_NONE;
        if (g_poc_cntx_p->mo_inviting == MMI_TRUE)
        {
            mmi_poc_show_error_cause(msgRsp->result, msgRsp->cause);
            DeleteScreenIfPresent(SCR_ID_POC_CM);
            mmi_poc_remove_cm_screens();
        }
    }
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);

    if (strlen((S8*) g_poc_cntx_p->cm_talk_group_name))
    {
        strncpy((S8*) list_name, (S8*) g_poc_cntx_p->cm_talk_group_name, POC_MAX_DISP_LEN - 1);
    }
    else if (strlen((S8*) g_poc_cntx_p->calling_disp.name))
    {
        strncpy((S8*) list_name, (S8*) g_poc_cntx_p->calling_disp.name, POC_MAX_DISP_LEN - 1);
    }
    else
    {
        strncpy((S8*) list_name, (S8*) g_poc_cntx_p->calling_disp.uri, POC_MAX_DISP_LEN - 1);
    }
    strncpy((S8*) uri, (S8*) msgRsp->session_id, POC_MAX_URI_LEN - 1);

    if (strlen((S8*) list_name))
    {
        if (strlen((S8*) uri))
        {
            mmi_poc_history_add(POC_OUTGOING_CALL, MMI_TRUE, list_name, uri, NULL);
        }
        else
        {
            mmi_poc_history_add(POC_OUTGOING_CALL, MMI_FALSE, list_name, g_poc_cntx_p->calling_disp.uri, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_inviting
 * DESCRIPTION
 *  poc inviting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_inviting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 temp_disp[POC_MAX_DISP_LEN * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_INVITING);

    EntryNewScreen(SCR_ID_POC_CM, mmi_poc_exit_release_ptt, mmi_poc_entry_inviting, NULL);
    DeleteUptoScrID(SCR_ID_POC_MAIN);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CM);

    g_poc_cntx_p->mo_inviting = MMI_TRUE;

    memset(g_poc_cntx_p->cm_disp, 0, sizeof(g_poc_cntx_p->cm_disp));
    mmi_ucs2cpy((S8*) g_poc_cntx_p->cm_disp, (S8*) GetString(STR_ID_POC_CM_INVITING));

    if (strlen((S8*) g_poc_cntx_p->calling_disp.name))
    {
        mmi_poc_util_copy_with_dot((S8*) g_poc_cntx_p->calling_disp.name, (S8*) temp_disp, POC_MAX_DISP_LEN - 1);
    }
    else
    {
        mmi_poc_util_copy_with_dot((S8*) g_poc_cntx_p->calling_disp.uri, (S8*) temp_disp, POC_MAX_DISP_LEN - 1);
    }

    mmi_ucs2cat((S8*) g_poc_cntx_p->cm_disp, (S8*) temp_disp);

    ShowCategory141Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_BACK,
        (U8*) g_poc_cntx_p->cm_disp,
        IMG_ID_POC_CM_INVITING,
        NULL);

    SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_poc_ptt_release, KEY_SEND, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_ptt_press, KEY_SEND, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_release_ptt
 * DESCRIPTION
 *  release ptt key when exiting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_release_ptt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_EXIT_RELEASE_PTT);
    g_poc_cntx_p->mo_inviting = MMI_FALSE;
    if (GetActiveScreenId() != SCR_ID_POC_CM)
    {
        mmi_poc_ptt_release();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_ptt_press
 * DESCRIPTION
 *  ptt key press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_ptt_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_PTT_PRESS);
    g_poc_cntx_p->ptt_button_status = POC_PTT_DOWN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_ptt_release
 * DESCRIPTION
 *  ptt key release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_ptt_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_PTT_RELEASE);
    g_poc_cntx_p->ptt_button_status = POC_PTT_UP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_progress_ind
 * DESCRIPTION
 *  process indication handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_progress_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_talk_progress_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_talk_progress_ind_struct*) info;

    if (msgRsp->status_code == 180)
    {   /* 180 = ringing */
        if (IsScreenPresent(SCR_ID_POC_CM))
        {
            HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_mo_ringing);
        }
        else
        {
            mmi_poc_entry_mo_ringing();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_mo_ringing
 * DESCRIPTION
 *  mo ringing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_mo_ringing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 temp_disp[POC_MAX_DISP_LEN * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_MO_RINGING);

    EntryNewScreen(SCR_ID_POC_CM, mmi_poc_exit_mo_ringing, mmi_poc_entry_mo_ringing, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    AudioPlayReq(POC_MO_RING_TONE, DEVICE_AUDIO_PLAY_INFINITE);
   

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    g_poc_cntx_p->mo_inviting = MMI_TRUE;

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CM);

    memset(g_poc_cntx_p->cm_disp, 0, sizeof(g_poc_cntx_p->cm_disp));
    mmi_ucs2cpy((S8*) g_poc_cntx_p->cm_disp, (S8*) GetString(STR_ID_POC_CM_MO_RINGING));

    if (strlen((S8*) g_poc_cntx_p->calling_disp.name))
    {
        mmi_poc_util_copy_with_dot((S8*) g_poc_cntx_p->calling_disp.name, (S8*) temp_disp, POC_MAX_DISP_LEN - 1);
    }
    else
    {
        mmi_poc_util_copy_with_dot((S8*) g_poc_cntx_p->calling_disp.uri, (S8*) temp_disp, POC_MAX_DISP_LEN - 1);
    }
    mmi_ucs2cat((S8*) g_poc_cntx_p->cm_disp, (S8*) temp_disp);

    ShowCategory141Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_BACK,
        (U8*) g_poc_cntx_p->cm_disp,
        IMG_ID_POC_CM_MO_RINGING,
        NULL);
    SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_poc_ptt_release, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_mo_ringing
 * DESCRIPTION
 *  exit function for mo ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_mo_ringing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_EXIT_MO_RINGING);
    g_poc_cntx_p->mo_inviting = MMI_FALSE;
    AudioStopReq(POC_MO_RING_TONE);
    mmi_poc_exit_release_ptt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_disconnect_back
 * DESCRIPTION
 *  disconnect go back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_disconnect_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_DISCONNECT_BACK);
    g_poc_cntx_p->abort_type = POC_ABORT_BACK;
    mmi_poc_entry_media_processing();

    switch (g_poc_cntx_p->audio_status)
    {
        case POC_AUDIO_NONE:
            mmi_poc_talk_disconnect_req();
            break;
        case POC_AUDIO_ENCODING:
            mmi_poc_audio_encode_stop(mmi_poc_talk_disconnect_req);
            break;
        case POC_AUDIO_DECODING:
            mmi_poc_audio_decode_stop(mmi_poc_talk_disconnect_req);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_disconnect_end
 * DESCRIPTION
 *  disconnect and go back to idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_disconnect_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_DISCONNECT_END);
    g_poc_cntx_p->abort_type = POC_ABORT_END;
    mmi_poc_entry_media_processing();

    switch (g_poc_cntx_p->audio_status)
    {
        case POC_AUDIO_NONE:
            mmi_poc_talk_disconnect_req();
            break;
        case POC_AUDIO_ENCODING:
            mmi_poc_audio_encode_stop(mmi_poc_talk_disconnect_req);
            break;
        case POC_AUDIO_DECODING:
            mmi_poc_audio_decode_stop(mmi_poc_talk_disconnect_req);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_disconnect_req
 * DESCRIPTION
 *  talk disconnect request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_disconnect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_talk_disconnect_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->call_status = POC_CALL_PROGRESSING;

    myMsgPtr = (poc_talk_disconnect_req_struct*) OslConstructDataPtr(sizeof(poc_talk_disconnect_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_talk_disconnect_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->request_id = POC_REQUEST_ID;
    myMsgPtr->talk_id = g_poc_cntx_p->active_talk_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_TALK_DISCONNECT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_talk_disconnect_rsp, PRT_POC_TALK_DISCONNECT_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_disconnect_rsp
 * DESCRIPTION
 *  poc talk disconnect response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_disconnect_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_talk_disconnect_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_talk_disconnect_rsp_struct*) info;

    g_poc_cntx_p->call_status = POC_CALL_NONE;
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);

    ClearProtocolEventHandler(PRT_POC_TALK_DISCONNECT_RSP);

    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    if (GetActiveScreenId() == SCR_ID_POC_CM)
    {
        if (g_poc_cntx_p->abort_type == POC_ABORT_BACK)
        {
            mmi_poc_reset_all_audio();
        }
        else if (g_poc_cntx_p->abort_type == POC_ABORT_END)
        {
            DisplayIdleScreen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_connect_ind
 * DESCRIPTION
 *  connect indication handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_connect_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 list_name[POC_MAX_DISP_LEN];
    U8 uri[POC_MAX_URI_LEN];
    poc_talk_connect_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && (g_poc_cntx_p->call_status != POC_CALL_PROGRESSING))
    {
        switch (g_poc_cntx_p->audio_status)
        {
            case POC_AUDIO_NONE:
                mmi_poc_talk_disconnect_req();
                break;
            case POC_AUDIO_ENCODING:
                mmi_poc_audio_encode_stop(mmi_poc_talk_disconnect_req);
                break;
            case POC_AUDIO_DECODING:
                mmi_poc_audio_decode_stop(mmi_poc_talk_disconnect_req);
                break;
            default:
                break;
        }
        return;
    }


    msgRsp = (poc_talk_connect_ind_struct*) info;

    g_poc_cntx_p->active_talk_id = msgRsp->talk_id;

    memset(g_poc_cntx_p->cm_talk_group_name, 0, sizeof(g_poc_cntx_p->cm_talk_group_name));
    memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
    g_poc_cntx_p->cm_talk_list_num = 0;

    switch (msgRsp->talk_type)
    {
        case POC_1_TO_1_TALK:
        case POC_UNKNOWN_TALK_TYPE:
        case POC_AD_HOC_GROUP_TALK:
            break;

        case POC_CHAT_GROUP_TALK:
        case POC_PRE_ARRANGED_GROUP_TALK:
            if (strlen((S8*) msgRsp->group_addr.disp_name))
            {
                strncpy(
                    (S8*) g_poc_cntx_p->cm_talk_group_name,
                    (S8*) msgRsp->group_addr.disp_name,
                    POC_MAX_DISP_LEN - 1);
            }
            else
            {
                strncpy((S8*) g_poc_cntx_p->cm_talk_group_name, (S8*) msgRsp->group_addr.uri, POC_MAX_DISP_LEN - 1);
            }
            break;

        default:
            ASSERT(0);
            break;
    }

    if (msgRsp->caller_privacy == MMI_TRUE)
    {
        g_poc_cntx_p->calling_disp.name[0] = 0xFF;
        g_poc_cntx_p->calling_disp.name[1] = 0;
    }
    else
    {
        strncpy((S8*) g_poc_cntx_p->calling_disp.name, (S8*) msgRsp->caller.disp_name, POC_MAX_DISP_LEN - 1);
        strncpy((S8*) g_poc_cntx_p->calling_disp.uri, (S8*) msgRsp->caller.uri, POC_MAX_URI_LEN - 1);
    }

    g_poc_cntx_p->call_status = POC_CALL_ACTIVE;
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);

    if (strlen((S8*) g_poc_cntx_p->cm_talk_group_name))
    {
        strncpy((S8*) list_name, (S8*) g_poc_cntx_p->cm_talk_group_name, POC_MAX_DISP_LEN - 1);
    }
    else if (strlen((S8*) msgRsp->caller.disp_name))
    {
        strncpy((S8*) list_name, (S8*) msgRsp->caller.disp_name, POC_MAX_DISP_LEN - 1);
    }
    else
    {
        strncpy((S8*) list_name, (S8*) msgRsp->caller.uri, POC_MAX_DISP_LEN - 1);
    }
    strncpy((S8*) uri, (S8*) msgRsp->session_id, POC_MAX_URI_LEN - 1);

    mmi_poc_history_add(POC_INCOMING_CALL, MMI_TRUE, list_name, uri, NULL);

    g_poc_cntx_p->floor_idle_recved = MMI_TRUE;

    if (IsScreenPresent(SCR_ID_POC_CM))
    {
        HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_connected_idle);
    }
    else
    {
        mmi_poc_entry_connected_idle();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_ring_ind
 * DESCRIPTION
 *  ringing indication handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_ring_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_talk_ring_ind_struct *msgRsp;
    U8 list_name[POC_MAX_DISP_LEN];
    U8 uri[POC_MAX_URI_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && (g_poc_cntx_p->call_status != POC_CALL_PROGRESSING))
    {
        mmi_poc_talk_answer_req(MMI_FALSE);
        ClearProtocolEventHandler(PRT_POC_TALK_ANSWER_RSP);
        return;
    }

    msgRsp = (poc_talk_ring_ind_struct*) info;

    if (g_poc_cntx_p->curr_reg_state == POC_REG_DEREGING)
    {
        mmi_poc_talk_answer_req(MMI_FALSE);
        ClearProtocolEventHandler(PRT_POC_TALK_ANSWER_RSP);
        return;
    }

    g_poc_cntx_p->active_talk_id = msgRsp->talk_id;

    memset(g_poc_cntx_p->cm_talk_group_name, 0, sizeof(g_poc_cntx_p->cm_talk_group_name));
    memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
    g_poc_cntx_p->cm_talk_list_num = 0;

    switch (msgRsp->talk_type)
    {
        case POC_1_TO_1_TALK:
        case POC_UNKNOWN_TALK_TYPE:
        case POC_AD_HOC_GROUP_TALK:
            break;

        case POC_CHAT_GROUP_TALK:
        case POC_PRE_ARRANGED_GROUP_TALK:
            if (strlen((S8*) msgRsp->group_addr.disp_name))
            {
                strncpy(
                    (S8*) g_poc_cntx_p->cm_talk_group_name,
                    (S8*) msgRsp->group_addr.disp_name,
                    POC_MAX_DISP_LEN - 1);
            }
            else
            {
                strncpy((S8*) g_poc_cntx_p->cm_talk_group_name, (S8*) msgRsp->group_addr.uri, POC_MAX_DISP_LEN - 1);
            }
            break;

        default:
            ASSERT(0);
            break;
    }

    g_poc_cntx_p->call_status = POC_CALL_ACTIVE;
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);

    if (msgRsp->caller_privacy == MMI_TRUE)
    {
        g_poc_cntx_p->calling_disp.name[0] = 0xFF;
        g_poc_cntx_p->calling_disp.name[1] = 0;
    }
    else
    {
        strncpy((S8*) g_poc_cntx_p->calling_disp.name, (S8*) msgRsp->caller.disp_name, POC_MAX_DISP_LEN - 1);
        strncpy((S8*) g_poc_cntx_p->calling_disp.uri, (S8*) msgRsp->caller.uri, POC_MAX_URI_LEN - 1);
    }

    if (strlen((S8*) g_poc_cntx_p->cm_talk_group_name))
    {
        strncpy((S8*) list_name, (S8*) g_poc_cntx_p->cm_talk_group_name, POC_MAX_DISP_LEN - 1);
    }
    else if (strlen((S8*) msgRsp->caller.disp_name))
    {
        strncpy((S8*) list_name, (S8*) msgRsp->caller.disp_name, POC_MAX_DISP_LEN - 1);
    }
    else
    {
        strncpy((S8*) list_name, (S8*) msgRsp->caller.uri, POC_MAX_DISP_LEN - 1);
    }
    strncpy((S8*) uri, (S8*) msgRsp->session_id, POC_MAX_URI_LEN - 1);

    mmi_poc_history_add(POC_INCOMING_CALL, MMI_TRUE, list_name, uri, NULL);

    if (IsScreenPresent(SCR_ID_POC_CM))
    {
        HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_mt_ringing);
    }
    else
    {
        mmi_poc_entry_mt_ringing();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_start_mt_ringing
 * DESCRIPTION
 *  start mt call ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_start_mt_ringing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsSilentModeActivated() != TRUE)
    {
        switch (GetMtCallAlertTypeEnum())
        {
            case MMI_RING:
                AudioPlayToneWithCallBack(GetRingToneID(), GetRingTypeEnum(), INCOMING_CALL_TONE);
                break;
            case MMI_VIBRATION_ONLY:
                VibratorOn();
                break;
            case MMI_VIBRATION_AND_RING:
            case MMI_VIBRATION_THEN_RING:
                VibratorOn();
                AudioPlayToneWithCallBack(GetRingToneID(), GetRingTypeEnum(), INCOMING_CALL_TONE);
                break;
            case MMI_SILENT:
                break;
            case MMI_ALERT_NONE:
                break;
            default:
                AudioPlayToneWithCallBack(GetRingToneID(), GetRingTypeEnum(), INCOMING_CALL_TONE);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_stop_mt_ringing
 * DESCRIPTION
 *  stop mt call ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_stop_mt_ringing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetMtCallAlertTypeEnum())
    {
        case MMI_RING:
            mdi_audio_stop_all();
            break;
        case MMI_VIBRATION_ONLY:
            VibratorOff();
            break;
        case MMI_VIBRATION_AND_RING:
        case MMI_VIBRATION_THEN_RING:
            mdi_audio_stop_all();
            VibratorOff();
            break;
        case MMI_SILENT:
            break;
        case MMI_ALERT_NONE:
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_mt_ringing
 * DESCRIPTION
 *  mt ringing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_mt_ringing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 cm_len_remain = 0;
    U8 temp_buf[POC_MAX_URI_LEN * ENCODING_LENGTH];
    S8 short_string[10], ucs2_short_string[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_MT_RINGING);

    memset(g_poc_cntx_p->cm_disp, 0, sizeof(g_poc_cntx_p->cm_disp));
    if (strlen((S8*) g_poc_cntx_p->cm_talk_group_name))
    {
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->cm_disp,
            (S8*) g_poc_cntx_p->cm_talk_group_name,
            POC_MAX_DISP_LEN - 1);
    }

    cm_len_remain = POC_MAX_DISP_LEN * 3 / 2 - 1 - strlen((S8*) g_poc_cntx_p->cm_talk_group_name);

    memset(short_string, 0, sizeof(short_string));
    memset(ucs2_short_string, 0, sizeof(ucs2_short_string));
    sprintf(short_string, ", ");
    mmi_asc_to_ucs2((PS8) ucs2_short_string, (PS8) short_string);

    if (cm_len_remain > 0)
    {
        if (strlen((S8*) g_poc_cntx_p->calling_disp.name))
        {
            if (g_poc_cntx_p->calling_disp.name[0] == 0xFF)
            {
                if (!mmi_ucs2strlen(ucs2_short_string))
                {
                    mmi_ucs2ncat((S8*) g_poc_cntx_p->cm_disp, (S8*) ucs2_short_string, cm_len_remain - 1);
                    cm_len_remain -= mmi_ucs2strlen(ucs2_short_string);
                }
                mmi_ucs2ncat((S8*) g_poc_cntx_p->cm_disp, (S8*) GetString(STR_ID_POC_CM_ANONYMOUS), cm_len_remain - 1);
            }
            else
            {
                if (!mmi_ucs2strlen(ucs2_short_string))
                {
                    mmi_ucs2ncat((S8*) g_poc_cntx_p->cm_disp, (S8*) ucs2_short_string, cm_len_remain - 1);
                    cm_len_remain -= mmi_ucs2strlen(ucs2_short_string);
                }
                memset(temp_buf, 0, sizeof(temp_buf));
                mmi_asc_n_to_ucs2((S8*) temp_buf, (S8*) g_poc_cntx_p->calling_disp.name, POC_MAX_DISP_LEN - 1);
                mmi_ucs2ncat((S8*) g_poc_cntx_p->cm_disp, (S8*) temp_buf, cm_len_remain - 1);
            }
        }
        else
        {
            if (!mmi_ucs2strlen(ucs2_short_string))
            {
                mmi_ucs2ncat((S8*) g_poc_cntx_p->cm_disp, (S8*) ucs2_short_string, cm_len_remain - 1);
                cm_len_remain -= mmi_ucs2strlen(ucs2_short_string);
            }
            memset(temp_buf, 0, sizeof(temp_buf));
            mmi_asc_n_to_ucs2((S8*) temp_buf, (S8*) g_poc_cntx_p->calling_disp.uri, POC_MAX_DISP_LEN - 1);
            mmi_ucs2ncat((S8*) g_poc_cntx_p->cm_disp, (S8*) temp_buf, cm_len_remain - 1);
        }
    }

    EntryNewScreen(SCR_ID_POC_CM, mmi_poc_exit_mt_ringing, mmi_poc_entry_mt_ringing, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    mmi_poc_start_mt_ringing();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CM);

    ShowCategory141Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*) g_poc_cntx_p->cm_disp,
        IMG_ID_POC_CM_MT_RINGING,
        NULL);

    mmi_poc_enter_cm_key_light();

    SetLeftSoftkeyFunction(mmi_poc_mt_ringing_yes, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_mt_ringing_yes, KEY_SEND, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_poc_mt_ringin_no, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_mt_ringing_end, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_mt_ringing
 * DESCRIPTION
 *  exit function for mt ringing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_mt_ringing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_EXIT_MT_RINGING);
    mmi_poc_exit_cm_key_light();
    mmi_poc_stop_mt_ringing();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_mt_ringing_yes
 * DESCRIPTION
 *  yes handler for mt ringing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_mt_ringing_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_MT_RINGING_YES);
    g_poc_cntx_p->abort_type = POC_ABORT_NONE;
    g_poc_cntx_p->call_status = POC_CALL_ACTIVE;
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);

    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_poc_stop_alert_ringing();
    mmi_poc_entry_mt_ringing_answered();
    mmi_poc_talk_answer_req(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_mt_ringin_no
 * DESCRIPTION
 *  no handler for mt ringing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_mt_ringin_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_MT_RINGIN_NO);
    g_poc_cntx_p->abort_type = POC_ABORT_BACK;
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_poc_stop_alert_ringing();
    mmi_poc_talk_answer_req(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_mt_ringing_end
 * DESCRIPTION
 *  end handler for mt ringing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_mt_ringing_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_MT_RINGING_END);
    g_poc_cntx_p->abort_type = POC_ABORT_END;
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_poc_talk_answer_req(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_mt_ringing_answered
 * DESCRIPTION
 *  answered process screen for mt ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_mt_ringing_answered(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_MT_RINGING_ANSWERED);

    EntryNewScreen(SCR_ID_POC_CM, mmi_poc_exit_mt_ringing_answered, mmi_poc_entry_mt_ringing_answered, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CM);

    ShowCategory141Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_BACK,
        (U8*) g_poc_cntx_p->cm_disp,
        IMG_ID_POC_CM_MT_RINGING,
        NULL);

    mmi_poc_enter_cm_key_light();

    SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_mt_ringing_answered
 * DESCRIPTION
 *  exit function for mt ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_mt_ringing_answered(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_EXIT_MT_RINGING_ANSWERED);
    mmi_poc_exit_cm_key_light();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_answer_req
 * DESCRIPTION
 *  talk answer request
 * PARAMETERS
 *  accept      [IN]        If user choose yes or no
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_answer_req(U8 accept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_talk_answer_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_talk_answer_req_struct*) OslConstructDataPtr(sizeof(poc_talk_answer_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_talk_answer_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->talk_id = g_poc_cntx_p->active_talk_id;
    myMsgPtr->accept = (kal_bool) accept;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_TALK_ANSWER_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_talk_answer_rsp, PRT_POC_TALK_ANSWER_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_answer_rsp
 * DESCRIPTION
 *  response for talk answer request
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_answer_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_talk_answer_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_talk_answer_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_POC_TALK_ANSWER_RSP);

    g_poc_cntx_p->floor_idle_recved = MMI_TRUE;

    if (g_poc_cntx_p->abort_type == POC_ABORT_BACK)
    {
        g_poc_cntx_p->call_status = POC_CALL_NONE;
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DeleteScreenIfPresent(SCR_ID_POC_CM);
        mmi_poc_remove_cm_screens();
        if (GetActiveScreenId() == SCR_ID_POC_CM)
        {
            GoBackHistory();
        }
    }
    else if (g_poc_cntx_p->abort_type == POC_ABORT_END)
    {
        g_poc_cntx_p->call_status = POC_CALL_NONE;
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DeleteScreenIfPresent(SCR_ID_POC_CM);
        mmi_poc_remove_cm_screens();
        if (GetActiveScreenId() == SCR_ID_POC_CM)
        {
            DisplayIdleScreen();
        }
    }
    else if (msgRsp->result == POC_OK)
    {
        mmi_poc_entry_connected_idle();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_disconnect_ind
 * DESCRIPTION
 *  disconnect indication handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_disconnect_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_talk_disconnect_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_talk_disconnect_ind_struct*) info;

    /* Clear all dynamic protocol handler */
    if(GetActiveScreenId() != SCR_ID_POC_REG)
    {
        ClearProtocolEventHandler(PRT_POC_REGISTER_RSP);
    }

    g_poc_cntx_p->call_status = POC_CALL_NONE;
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);

    /* Reset status only, poc task would stop encoding / decoding */
    mmi_poc_reset_all_audio();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_disconnect_callback
 * DESCRIPTION
 *  disconnect call back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_disconnect_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GetActiveScreenId() >= SCR_ID_POC_MAIN) && (GetActiveScreenId() < SCR_ID_POC_TOTAL))
    {
        DisplayPopup((U8*) GetString(STR_CALL_ENDED), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) NULL);
    }

    /* Clear all dynamic PoC screen */
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_connected_idle
 * DESCRIPTION
 *  Connect idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_connected_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 i;
    U8 *listItemsIcons[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_CONNECTED_IDLE);

    EntryNewScreen(SCR_ID_POC_CM, mmi_poc_exit_connected_idle, mmi_poc_entry_connected_idle, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    memset(g_poc_cntx_p->cm_disp, 0, sizeof(g_poc_cntx_p->cm_disp));
    if (strlen((S8*) g_poc_cntx_p->cm_talk_group_name))
    {
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->cm_disp,
            (S8*) g_poc_cntx_p->cm_talk_group_name,
            POC_MAX_DISP_LEN);
    }
    else
    {
        mmi_ucs2cpy((S8*) g_poc_cntx_p->cm_disp, (S8*) GetString(STR_ID_POC_CM_CONNECTED_IDLE));
    }

    for (i = 0; i < g_poc_cntx_p->cm_talk_list_num; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        if (strlen((S8*) g_poc_cntx_p->cm_talk_list[i].name))
        {
            if (g_poc_cntx_p->cm_talk_list[i].name[0] == 0xFF)
            {
                mmi_ucs2cpy((S8*) subMenuDataPtrs[0], (S8*) GetString(STR_ID_POC_CM_ANONYMOUS));
            }
            else
            {
                mmi_poc_util_copy_with_dot(
                    (S8*) g_poc_cntx_p->cm_talk_list[i].name,
                    (S8*) subMenuDataPtrs[i],
                    MAX_SUBMENU_CHARACTERS - 1);
            }
        }
        else
        {
            mmi_poc_util_copy_with_dot(
                (S8*) g_poc_cntx_p->cm_talk_list[i].uri,
                (S8*) subMenuDataPtrs[i],
                MAX_SUBMENU_CHARACTERS - 1);
        }
    }

    for (i = 0; i < g_poc_cntx_p->cm_talk_list_num; i++)
    {
        listItemsIcons[i] = (U8*) GetImage(gIndexIconsImageList[i]);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CM);
    /* RegisterHighlightHandler( ExecuteCurrHiliteHandler); */

    ShowCategory174Screen(
        g_poc_cntx_p->cm_disp,
        (PU8) GetImage(GetRootTitleIcon(MENU_ID_POC_MAIN)),
        (PU8) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_ABORT),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        g_poc_cntx_p->cm_talk_list_num,
        subMenuDataPtrs,
        listItemsIcons,
        NULL,
        0,
        0,
        guiBuffer);

    mmi_poc_enter_cm_key_light();
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_options, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_poc_disconnect_end,KEY_END,KEY_EVENT_DOWN); */
    SetKeyHandler(mmi_poc_disconnect_back, KEY_END, KEY_EVENT_DOWN);

    if (g_poc_cntx_p->floor_idle_recved == MMI_TRUE)
    {
        SetKeyHandler(mmi_poc_floor_take_key, KEY_SEND, KEY_EVENT_DOWN);
    }

    SetKeyHandler(mmi_poc_ptt_release, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_connected_idle
 * DESCRIPTION
 *  exit function for connected idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_connected_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_EXIT_CONNECTED_IDLE);
    mmi_poc_exit_cm_key_light();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_options
 * DESCRIPTION
 *  talk options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem = 0;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_TALK_OPTIONS);

    EntryNewScreen(SCR_ID_POC_TALK_OPTION, NULL, mmi_poc_entry_talk_options, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_OPTION);

    if (g_poc_cntx_p->talk_pres_ind_recved == POC_TALK_STATUS_NOT_READY)
    {
        nNumofItem = GetNumOfChild(MENU_ID_POC_CM_OPTION_PRES_NOT_READY);
        GetSequenceStringIds(MENU_ID_POC_CM_OPTION_PRES_NOT_READY, nStrItemList);
        SetParentHandler(MENU_ID_POC_CM_OPTION_PRES_NOT_READY);
    }
    else if (g_poc_cntx_p->talk_pres_ind_recved == POC_TALK_STATUS_ON)
    {
        nNumofItem = GetNumOfChild(MENU_ID_POC_CM_OPTION_PRES_UNSUBSCRIBE);
        GetSequenceStringIds(MENU_ID_POC_CM_OPTION_PRES_UNSUBSCRIBE, nStrItemList);
        SetParentHandler(MENU_ID_POC_CM_OPTION_PRES_UNSUBSCRIBE);
    }
    else if (g_poc_cntx_p->talk_pres_ind_recved == POC_TALK_STATUS_OFF)
    {
        nNumofItem = GetNumOfChild(MENU_ID_POC_CM_OPTION_PRES_SUBSCRIBE);
        GetSequenceStringIds(MENU_ID_POC_CM_OPTION_PRES_SUBSCRIBE, nStrItemList);
        SetParentHandler(MENU_ID_POC_CM_OPTION_PRES_SUBSCRIBE);
    }
    else
    {
        ASSERT(0);
    }

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
 *  mmi_poc_entry_cm_add_user
 * DESCRIPTION
 *  add user screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_cm_add_user(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;
    U8 i = 0;
    U8 *guiBuffer;
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_CM_ADD_USER);

    mmi_poc_check_and_update_contact();

    if (g_poc_cntx_p->contact_num == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    if (g_poc_cntx_p->in_call_inviting == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_POC_TALK_OPTION_ADD_USER, NULL, mmi_poc_entry_cm_add_user, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_OPTION_ADD_USER);

    nNumofItem = g_poc_cntx_p->contact_num;

    if (nNumofItem > POC_MAX_CONTACT_DISPLAY_NUM)
    {
        nNumofItem = POC_MAX_CONTACT_DISPLAY_NUM;
    }

    for (i = 0; i < nNumofItem; i++)
    {
        cont = &g_poc_cntx_p->contact_list_disp[i];
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        if (strlen((S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name))
        {
            mmi_asc_n_to_ucs2(
                (S8*) subMenuDataPtrs[i],
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id]. display_name,
                MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*) subMenuDataPtrs[i],
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                MAX_SUBMENU_CHARACTERS - 1);
        }
    }

    SetParentHandler(MENU_ID_POC_CM_ADD_USER);
    /* RegisterHighlightHandler(ExecuteCurrHiliteHandler); */

    if (guiBuffer == NULL)
    {
        memset(g_poc_cntx_p->adhoc_sel_disp, 0, sizeof(U8) * POC_MAX_CONTACT_DISPLAY_NUM);
    }

    SetCheckboxToggleRightSoftkeyFunctions(mmi_poc_entry_cm_add_user_cfrm, GoBackHistory);

    ShowCategory140Screen(
        STR_ID_POC_CONTACTS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        nNumofItem,
        (U8 **) subMenuDataPtrs,
        g_poc_cntx_p->adhoc_sel_disp,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_cm_add_user_cfrm
 * DESCRIPTION
 *  add user confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_cm_add_user_cfrm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_CM_ADD_USER_CFRM);

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DIAL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_poc_cm_add_user, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_cm_add_user_back, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_cm_add_user_back
 * DESCRIPTION
 *  add user back key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_cm_add_user_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteScreenIfPresent(SCR_ID_POC_TALK_OPTION_ADD_USER);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_cm_add_user
 * DESCRIPTION
 *  add user request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_cm_add_user(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_addr_struct callee[POC_MAX_ADDR_NUM];
    U8 i, total_adhoc_num = 0;
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(callee, 0, sizeof(callee));

    for (i = 0; i < POC_MAX_CONTACT_DISPLAY_NUM; i++)
    {
        cont = &g_poc_cntx_p->contact_list_disp[i];
        if (g_poc_cntx_p->adhoc_sel_disp[i] == MMI_TRUE)
        {
            if (total_adhoc_num >= POC_MAX_ADDR_NUM)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_MAXIMUM_REACHED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_POC_TALK_OPTION_ADD_USER);
                return;
            }
            memcpy(
                &callee[total_adhoc_num].uri,
                &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                sizeof(U8) * POC_MAX_URI_LEN);
            total_adhoc_num++;
        }
    }

    g_poc_cntx_p->in_call_inviting = MMI_TRUE;
    mmi_poc_talk_invite_req(POC_AD_HOC_GROUP_TALK, total_adhoc_num, callee, g_poc_cntx_p->active_talk_id, MMI_TRUE, 0);
    g_poc_cntx_p->floor_idle_recved = MMI_TRUE;
    SetProtocolEventHandler(mmi_poc_in_call_invite_rsp, PRT_POC_TALK_INVITE_RSP);
    DeleteUptoScrID(SCR_ID_POC_CM);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_in_call_invite_rsp
 * DESCRIPTION
 *  response for call invite
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_in_call_invite_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_talk_invite_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_talk_invite_rsp_struct*) info;

    g_poc_cntx_p->in_call_inviting = MMI_FALSE;

    ClearProtocolEventHandler(PRT_POC_TALK_INVITE_RSP);

    if (msgRsp->result == POC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_POC_CM)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_INVITING_SUCCESS),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_CM)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_INVITING_FAIL),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_floor_take_key
 * DESCRIPTION
 *  floor take key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_floor_take_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->ptt_button_status != POC_PTT_DOWN)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_FLOOR_TAKE_KEY);
        ClearInputEventHandler(MMI_DEVICE_ALL);
        SetKeyHandler(mmi_poc_ptt_release, KEY_SEND, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
        SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
        mmi_poc_floor_take_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_floor_grant_ind
 * DESCRIPTION
 *  floor grant indication
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_floor_grant_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_floor_grant_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && (g_poc_cntx_p->call_status != POC_CALL_PROGRESSING))
    {
        switch (g_poc_cntx_p->audio_status)
        {
            case POC_AUDIO_NONE:
                mmi_poc_talk_disconnect_req();
                break;
            case POC_AUDIO_ENCODING:
                mmi_poc_audio_encode_stop(mmi_poc_talk_disconnect_req);
                break;
            case POC_AUDIO_DECODING:
                mmi_poc_audio_decode_stop(mmi_poc_talk_disconnect_req);
                break;
            default:
                break;
        }
        return;
    }

    msgRsp = (poc_floor_grant_ind_struct*) info;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
    if (g_poc_cntx_p->call_status != POC_CALL_ACTIVE)
    {
        return;
    }

    g_poc_cntx_p->active_talk_id = msgRsp->talk_id;

    if (g_poc_cntx_p->ptt_button_status != POC_PTT_DOWN)
    {
        SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
        SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
        mmi_poc_floor_release_req();
        return;
    }
    switch (g_poc_cntx_p->audio_status)
    {
        case POC_AUDIO_NONE:
            mmi_poc_audio_encode_start();
            break;
        case POC_AUDIO_ENCODING:
            break;
        case POC_AUDIO_DECODING:
            mmi_poc_audio_decode_stop(mmi_poc_audio_encode_start);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_floor_deny_ind
 * DESCRIPTION
 *  floor deny indication
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_floor_deny_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_floor_deny_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && (g_poc_cntx_p->call_status != POC_CALL_PROGRESSING))
    {
        switch (g_poc_cntx_p->audio_status)
        {
            case POC_AUDIO_NONE:
                mmi_poc_talk_disconnect_req();
                break;
            case POC_AUDIO_ENCODING:
                mmi_poc_audio_encode_stop(mmi_poc_talk_disconnect_req);
                break;
            case POC_AUDIO_DECODING:
                mmi_poc_audio_decode_stop(mmi_poc_talk_disconnect_req);
                break;
            default:
                break;
        }
        return;
    }

    msgRsp = (poc_floor_deny_ind_struct*) info;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
    if (g_poc_cntx_p->call_status != POC_CALL_ACTIVE)
    {
        return;
    }

    g_poc_cntx_p->active_talk_id = msgRsp->talk_id;

    switch (g_poc_cntx_p->audio_status)
    {
        case POC_AUDIO_NONE:
            if (GetActiveScreenId() == SCR_ID_POC_CM)
            {
                mmi_poc_show_error_cause((kal_int32) msgRsp->cause, 0);
            }

            if (IsScreenPresent(SCR_ID_POC_CM))
            {
                HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_connected_idle);
            }
            else
            {
                mmi_poc_entry_connected_idle();
            }
            break;
        case POC_AUDIO_ENCODING:
            mmi_poc_audio_encode_stop(NULL);
            break;
        case POC_AUDIO_DECODING:
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_floor_taken_ind
 * DESCRIPTION
 *  floor take indication
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_floor_taken_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_floor_taken_ind_struct *msgRsp;
    U8 temp_buf[POC_MAX_DISP_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && (g_poc_cntx_p->call_status != POC_CALL_PROGRESSING))
    {
        switch (g_poc_cntx_p->audio_status)
        {
            case POC_AUDIO_NONE:
                mmi_poc_talk_disconnect_req();
                break;
            case POC_AUDIO_ENCODING:
                mmi_poc_audio_encode_stop(mmi_poc_talk_disconnect_req);
                break;
            case POC_AUDIO_DECODING:
                mmi_poc_audio_decode_stop(mmi_poc_talk_disconnect_req);
                break;
            default:
                break;
        }
        return;
    }

    msgRsp = (poc_floor_taken_ind_struct*) info;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
    if (g_poc_cntx_p->call_status != POC_CALL_ACTIVE)
    {
        return;
    }

    g_poc_cntx_p->active_talk_id = msgRsp->talk_id;

    memset(g_poc_cntx_p->cm_disp, 0, sizeof(g_poc_cntx_p->cm_disp));
    mmi_ucs2cpy((S8*) g_poc_cntx_p->cm_disp, (S8*) GetString(STR_ID_POC_CM_LISTENING));
    if (msgRsp->talker_present == KAL_TRUE)
    {
        if (msgRsp->talker.disp_charset == 4)
        {
            msgRsp->talker.disp_name[POC_MAX_DISP_LEN - 1] = 0;
            msgRsp->talker.disp_name[POC_MAX_DISP_LEN - 2] = 0;
            msgRsp->talker.disp_name[POC_MAX_DISP_LEN - 3] = 0;
            mmi_ucs2cat((S8*) g_poc_cntx_p->cm_disp, (S8*) msgRsp->talker.disp_name);
        }
        else
        {
            msgRsp->talker.disp_name[POC_MAX_DISP_LEN / 2] = 0;
            mmi_asc_n_to_ucs2((S8*) temp_buf, (S8*) msgRsp->talker.disp_name, POC_MAX_DISP_LEN - 1);
            mmi_ucs2cat((S8*) g_poc_cntx_p->cm_disp, (S8*) temp_buf);
        }
    }

    switch (g_poc_cntx_p->audio_status)
    {
        case POC_AUDIO_NONE:
            mmi_poc_audio_decode_start();
            break;
        case POC_AUDIO_ENCODING:
            mmi_poc_audio_encode_stop(mmi_poc_audio_decode_start);
            break;
        case POC_AUDIO_DECODING:
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_floor_idle_ind
 * DESCRIPTION
 *  floor idle indication
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_floor_idle_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_floor_idle_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && (g_poc_cntx_p->call_status != POC_CALL_PROGRESSING))
    {
        switch (g_poc_cntx_p->audio_status)
        {
            case POC_AUDIO_NONE:
                mmi_poc_talk_disconnect_req();
                break;
            case POC_AUDIO_ENCODING:
                mmi_poc_audio_encode_stop(mmi_poc_talk_disconnect_req);
                break;
            case POC_AUDIO_DECODING:
                mmi_poc_audio_decode_stop(mmi_poc_talk_disconnect_req);
                break;
            default:
                break;
        }
        return;
    }

    msgRsp = (poc_floor_idle_ind_struct*) info;

    g_poc_cntx_p->floor_idle_recved = MMI_TRUE;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
    if (g_poc_cntx_p->call_status != POC_CALL_ACTIVE)
    {
        return;
    }

    g_poc_cntx_p->active_talk_id = msgRsp->talk_id;

    switch (g_poc_cntx_p->audio_status)
    {
        case POC_AUDIO_NONE:
            if (IsScreenPresent(SCR_ID_POC_CM))
            {
                HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_connected_idle);
            }
            else
            {
                mmi_poc_entry_connected_idle();
            }
            break;
        case POC_AUDIO_ENCODING:
            mmi_poc_audio_encode_stop(NULL);
            break;
        case POC_AUDIO_DECODING:
            mmi_poc_audio_decode_stop(NULL);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_floor_revoke_ind
 * DESCRIPTION
 *  floor revoke indication
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_floor_revoke_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_floor_revoke_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && (g_poc_cntx_p->call_status != POC_CALL_PROGRESSING))
    {
        switch (g_poc_cntx_p->audio_status)
        {
            case POC_AUDIO_NONE:
                mmi_poc_talk_disconnect_req();
                break;
            case POC_AUDIO_ENCODING:
                mmi_poc_audio_encode_stop(mmi_poc_talk_disconnect_req);
                break;
            case POC_AUDIO_DECODING:
                mmi_poc_audio_decode_stop(mmi_poc_talk_disconnect_req);
                break;
            default:
                break;
        }
        return;
    }

    msgRsp = (poc_floor_revoke_ind_struct*) info;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
    if (g_poc_cntx_p->call_status != POC_CALL_ACTIVE)
    {
        return;
    }
    g_poc_cntx_p->active_talk_id = msgRsp->talk_id;
    g_poc_cntx_p->general_err_cause = (S32) msgRsp->cause;
    mmi_poc_entry_revoke();
    mmi_poc_audio_encode_stop(mmi_poc_floor_release_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_revoke
 * DESCRIPTION
 *  handler for floor revoke
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_revoke(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_REVOKE);

    EntryNewScreen(SCR_ID_POC_CM, NULL, mmi_poc_entry_revoke, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    switch (g_poc_cntx_p->general_err_cause)
    {
        case POC_FLOOR_ALREADY_IN_USE:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_FLOOR_ALREADY_IN_USE), IMG_GLOBAL_ERROR, NULL);
            break;
        case POC_SERVER_INT_ERROR:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_SERVER_INT_ERROR), IMG_GLOBAL_ERROR, NULL);
            break;
        case POC_ONLY_ONE_USER:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_ONLY_ONE_USER), IMG_GLOBAL_ERROR, NULL);
            break;
        case POC_FLOOR_RETRY_AFTER:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_FLOOR_RETRY_AFTER), IMG_GLOBAL_ERROR, NULL);
            break;
        case POC_LISTEN_ONLY:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_LISTEN_ONLY), IMG_GLOBAL_ERROR, NULL);
            break;
        case POC_TALK_TOO_LONG:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_TALK_TOO_LONG), IMG_GLOBAL_ERROR, NULL);
            break;
        case POC_NO_FLOOR_PERMISSION:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_NO_FLOOR_PERMISSION), IMG_GLOBAL_ERROR, NULL);
            break;
        case POC_FLOOR_PREEMPTED:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_FLOOR_PREEMPTED), IMG_GLOBAL_ERROR, NULL);
            break;
        default:
            ShowCategory65Screen((U8*) GetString(STR_ID_POC_ERR_FLOOR_LOST), IMG_GLOBAL_ERROR, NULL);
            break;
    }
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyHandler(0, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_floor_take_req
 * DESCRIPTION
 *  floor take request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_floor_take_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_floor_take_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->ptt_button_status = POC_PTT_DOWN;

    myMsgPtr = (poc_floor_take_req_struct*) OslConstructDataPtr(sizeof(poc_floor_take_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_floor_take_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->talk_id = g_poc_cntx_p->active_talk_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_FLOOR_TAKE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_floor_release_req
 * DESCRIPTION
 *  floor release request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_floor_release_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_floor_release_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL); /* Assumption: There must be indications coming back. */

    g_poc_cntx_p->ptt_button_status = POC_PTT_UP;

    myMsgPtr = (poc_floor_release_req_struct*) OslConstructDataPtr(sizeof(poc_floor_release_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_floor_release_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->talk_id = g_poc_cntx_p->active_talk_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_FLOOR_RELEASE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_audio_encode_start
 * DESCRIPTION
 *  audio encode start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_audio_encode_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioPlayReq(POC_TALK_TONE, DEVICE_AUDIO_PLAY_ONCE);
    StartTimer(POC_IND_TIMER, 300, mmi_poc_media_start_encode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_audio_encode_stop
 * DESCRIPTION
 *  audio encode stop
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_audio_encode_stop(FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->media_stop_encode_callback = callback;
    mmi_poc_media_stop_encode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_audio_decode_start
 * DESCRIPTION
 *  audio decode start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_audio_decode_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
    mmi_poc_media_start_decode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_audio_decode_stop
 * DESCRIPTION
 *  audio decode stop
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_audio_decode_stop(FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->media_stop_decode_callback = callback;
    mmi_poc_media_stop_decode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_media_start_encode
 * DESCRIPTION
 *  media start encode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_media_start_encode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result mdi_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioStopReq(POC_TALK_TONE);

    if (g_poc_cntx_p->ptt_button_status != POC_PTT_DOWN)
    {
        SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
        SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
        mmi_poc_floor_release_req();
        return;
    }

    g_poc_cntx_p->audio_status = POC_AUDIO_ENCODING;

    mdi_res = mdi_audio_poc_start_encode(mmi_poc_mdi_start_encode_callback);

    if (mdi_res == MDI_AUDIO_SUCCESS)
    {
        if (g_poc_cntx_p->ptt_button_status == POC_PTT_UP)
        {
            SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
            SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
            mmi_poc_audio_encode_stop(mmi_poc_floor_release_req);
        }
        else
        {
            if (IsScreenPresent(SCR_ID_POC_CM))
            {
                HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_talking);
            }
            else
            {
                mmi_poc_entry_talking();
            }
        }
    }
    else
    {
        g_poc_cntx_p->audio_status = POC_AUDIO_NONE;
        if (GetActiveScreenId() == SCR_ID_POC_CM)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_mdi_start_encode_callback
 * DESCRIPTION
 *  mdi start encode callback
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_mdi_start_encode_callback(mdi_result result)
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
 *  mmi_poc_media_stop_encode
 * DESCRIPTION
 *  media stop encode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_media_stop_encode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result mdi_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->audio_status = POC_AUDIO_NONE;

    mdi_res = mdi_audio_poc_stop_encode();

    if (mdi_res == MDI_AUDIO_SUCCESS)
    {
        if (g_poc_cntx_p->media_stop_encode_callback)
        {
            g_poc_cntx_p->media_stop_encode_callback();
            g_poc_cntx_p->media_stop_encode_callback = NULL;
        }
        else
        {
            if (IsScreenPresent(SCR_ID_POC_CM))
            {
                HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_connected_idle);
            }
            else
            {
                mmi_poc_entry_connected_idle();
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_media_start_decode
 * DESCRIPTION
 *  medie start decode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_media_start_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result mdi_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->audio_status = POC_AUDIO_DECODING;

    mdi_res = mdi_audio_poc_start_decode(mmi_poc_mdi_start_decode_callback);

    if (mdi_res == MDI_AUDIO_SUCCESS)
    {
        if (IsScreenPresent(SCR_ID_POC_CM))
        {
            HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_listening);
        }
        else
        {
            mmi_poc_entry_listening();
        }
    }
    else
    {
        g_poc_cntx_p->audio_status = POC_AUDIO_NONE;
        if (GetActiveScreenId() == SCR_ID_POC_CM)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_mdi_start_decode_callback
 * DESCRIPTION
 *  start decode callback
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_mdi_start_decode_callback(mdi_result result)
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
 *  mmi_poc_media_stop_decode
 * DESCRIPTION
 *  media stop decode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_media_stop_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result mdi_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->audio_status = POC_AUDIO_NONE;

    mdi_res = mdi_audio_poc_stop_decode();

    if (mdi_res == MDI_AUDIO_SUCCESS)
    {
        if (g_poc_cntx_p->media_stop_decode_callback)
        {
            g_poc_cntx_p->media_stop_decode_callback();
            g_poc_cntx_p->media_stop_decode_callback = NULL;
        }
        else
        {
            if (IsScreenPresent(SCR_ID_POC_CM))
            {
                HistoryReplace(SCR_ID_POC_CM, SCR_ID_POC_CM, mmi_poc_entry_connected_idle);
            }
            else
            {
                mmi_poc_entry_connected_idle();
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talking
 * DESCRIPTION
 *  talking entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_TALKING);

    EntryNewScreen(SCR_ID_POC_CM, mmi_poc_exit_talking, mmi_poc_entry_media_processing, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CM);

    if (g_poc_cntx_p->ptt_button_status == POC_PTT_UP)
    {
        mmi_poc_talking_release_ptt();
    }

    memset(g_poc_cntx_p->cm_disp, 0, sizeof(g_poc_cntx_p->cm_disp));
    mmi_ucs2cpy((S8*) g_poc_cntx_p->cm_disp, (S8*) GetString(STR_ID_POC_CM_TALKING));

    ShowCategory141Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        0,
        0,
        0,
        0,
        (U8*) g_poc_cntx_p->cm_disp,
        IMG_ID_POC_CM_TALKING,
        NULL);

    mmi_poc_enter_cm_key_light();
    SetKeyHandler(mmi_poc_talking_release_ptt, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_talking
 * DESCRIPTION
 *  exit screen for talking screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_talking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_EXIT_TALKING);
    mmi_poc_exit_cm_key_light();
    mmi_poc_talking_release_ptt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_media_processing
 * DESCRIPTION
 *  media processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_media_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_MEDIA_PROCESSING);
    EntryNewScreen(SCR_ID_POC_CM, NULL, mmi_poc_entry_media_processing, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    ShowCategory65Screen((U8*) GetString(STR_ID_POC_PROCESSING), IMG_GLOBAL_WARNING, NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talking_release_ptt
 * DESCRIPTION
 *  talking release ptt key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talking_release_ptt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->audio_status != POC_AUDIO_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_TALKING_RELEASE_PTT);
        ClearInputEventHandler(MMI_DEVICE_ALL);
        SetKeyHandler(0, KEY_END, KEY_EVENT_DOWN);
        mmi_poc_audio_encode_stop(mmi_poc_floor_release_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_listening
 * DESCRIPTION
 *  listening entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_listening(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_LISTENING);

    EntryNewScreen(SCR_ID_POC_CM, mmi_poc_exit_listening, mmi_poc_entry_listening, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_CM);
    mmi_poc_remove_cm_screens();

    SetDelScrnIDCallbackHandler(SCR_ID_POC_CM, (HistoryDelCBPtr) mmi_poc_cm_history_del_handler);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CM);

    ShowCategory141Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_BACK,
        (U8*) g_poc_cntx_p->cm_disp,
        IMG_ID_POC_CM_LISTENING,
        NULL);

    mmi_poc_enter_cm_key_light();
    SetRightSoftkeyFunction(mmi_poc_disconnect_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_disconnect_end, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_listening
 * DESCRIPTION
 *  exit screen for listen screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_listening(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_EXIT_LISTENING);
    mmi_poc_exit_cm_key_light();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_reset_all_audio
 * DESCRIPTION
 *  reset all audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_reset_all_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_RESET_ALL_AUDIO);

    g_poc_cntx_p->audio_status = POC_AUDIO_NONE;

    mmi_poc_disconnect_callback();

    //poc task would reset audio status
    //mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO|MDI_DEVICE_CAMER|MDI_DEVICE_VIDEO);
    mdi_audio_start_background_timer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_show_error_cause
 * DESCRIPTION
 *  show error cause
 * PARAMETERS
 *  result      [IN]        
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_show_error_cause(kal_int32 result, kal_int32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
            /* FS error */
        case POC_FS_ERROR:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_FS_ERROR),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
            /* Floor Error */
        case POC_FLOOR_ALREADY_IN_USE:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_FLOOR_ALREADY_IN_USE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_SERVER_INT_ERROR:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_SERVER_INT_ERROR),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_ONLY_ONE_USER:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_ONLY_ONE_USER),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_FLOOR_RETRY_AFTER:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_FLOOR_RETRY_AFTER),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_LISTEN_ONLY:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_LISTEN_ONLY),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_TALK_TOO_LONG:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_TALK_TOO_LONG),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_NO_FLOOR_PERMISSION:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_NO_FLOOR_PERMISSION),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_FLOOR_PREEMPTED:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_FLOOR_PREEMPTED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
            /* Misc */
        case POC_INVALID_SETTING:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_INVALID_SETTING),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_NOT_REGISTER:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_NOT_REGISTERED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_NO_RESOURCE:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_NO_RESOURCE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_INVALID_URI:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_INVALID_URI),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_TIMEOUT_ERROR:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_TIMEOUT_ERROR),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
            /* SIP error */
        case POC_SIP_ERROR:
            switch (cause)
            {
                case 408:   /* request time out */
                    DisplayPopup(
                        (U8*) GetString(STR_ID_POC_ERR_TIMEOUT_ERROR),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    break;
                case 404:   /* not found */
                    DisplayPopup(
                        (U8*) GetString(STR_ID_POC_ERR_NOT_FOUND),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    break;
                case 486:   /* busy here */
                    DisplayPopup(
                        (U8*) GetString(STR_ID_POC_ERR_BUSY),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    break;
                case 480:   /* busy here */
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_NOT_AVAILABLE),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    break;
                case 401:
                case 407:
                    DisplayPopup(
                        (U8*) GetString(STR_ID_POC_ERR_AUTH_REQ),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    break;
                case 403:
                    DisplayPopup(
                        (U8*) GetString(STR_ID_POC_ERR_FORBIDDEN),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    break;
                default:
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_NOT_DONE),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    break;
            }
            break;
        case POC_RECV_SIP_BYE:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_RECV_SIP_BYE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case POC_TALK_ABORTED:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_TALK_ABORTED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
            /* XDM error */
        case POC_XDM_ERROR:
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_ERR_XDM_ERROR),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        default:
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_enter_cm_key_light
 * DESCRIPTION
 *  call management key light enabler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_enter_cm_key_light(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    TurnOnBacklight(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_cm_key_light
 * DESCRIPTION
 *  call management key light disable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_cm_key_light(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
    TurnOffBacklight();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_remove_cm_screens
 * DESCRIPTION
 *  remove poc call management screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_remove_cm_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_POC_TALK_OPTION);
    DeleteScreenIfPresent(SCR_ID_POC_TALK_OPTION_ADD_USER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_status_notify_ind
 * DESCRIPTION
 *  talk status notify indication handler
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_status_notify_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    poc_talk_status_notify_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_talk_status_notify_ind_struct*) info;

    if (msgRsp->result == POC_OK)
    {
        g_poc_cntx_p->talk_pres_ind_recved = POC_TALK_STATUS_ON;
        if (msgRsp->full_state == MMI_TRUE)
        {
            memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
            g_poc_cntx_p->cm_talk_list_num = 0;
        }
        for (i = 0; i < msgRsp->num_status; i++)
        {
            if ((msgRsp->status[i].status == POC_TS_DELETED) || (msgRsp->status[i].status == POC_TS_DISCONNECTED))
            {
                for (j = 0; j < g_poc_cntx_p->cm_talk_list_num; j++)
                {
                    if (!strncmp
                        ((S8*) msgRsp->status[i].user.uri, (S8*) g_poc_cntx_p->cm_talk_list[j].uri,
                         POC_MAX_URI_LEN - 1))
                    {
                        memcpy(
                            &g_poc_cntx_p->cm_talk_list[j],
                            &g_poc_cntx_p->cm_talk_list[g_poc_cntx_p->cm_talk_list_num - 1],
                            sizeof(mmi_poc_talk_list_struct));
                        memset(
                            &g_poc_cntx_p->cm_talk_list[g_poc_cntx_p->cm_talk_list_num - 1],
                            0,
                            sizeof(mmi_poc_talk_list_struct));
                        g_poc_cntx_p->cm_talk_list_num--;
                        break;
                    }
                }
            }
            else
            {
                for (j = 0; j < g_poc_cntx_p->cm_talk_list_num; j++)
                {
                    if (!strncmp
                        ((S8*) msgRsp->status[i].user.uri, (S8*) g_poc_cntx_p->cm_talk_list[j].uri,
                         POC_MAX_URI_LEN - 1))
                    {
                        g_poc_cntx_p->cm_talk_list[j].status = msgRsp->status[i].status;
                        strncpy(
                            (S8*) g_poc_cntx_p->cm_talk_list[j].name,
                            (S8*) msgRsp->status[i].user.disp_name,
                            POC_MAX_DISP_LEN - 1);
                        break;
                    }
                }
                if ((j == g_poc_cntx_p->cm_talk_list_num) && (j < POC_MAX_TALK_STATUS_ENTRY_NUM))
                {
                    memset(&g_poc_cntx_p->cm_talk_list[j], 0, sizeof(mmi_poc_talk_list_struct));
                    g_poc_cntx_p->cm_talk_list[j].status = msgRsp->status[i].status;
                    strncpy(
                        (S8*) g_poc_cntx_p->cm_talk_list[j].name,
                        (S8*) msgRsp->status[i].user.disp_name,
                        POC_MAX_DISP_LEN - 1);
                    strncpy(
                        (S8*) g_poc_cntx_p->cm_talk_list[j].uri,
                        (S8*) msgRsp->status[i].user.uri,
                        POC_MAX_URI_LEN - 1);
                    g_poc_cntx_p->cm_talk_list_num++;
                }
            }
        }
        if (msgRsp->more_data == MMI_FALSE)
        {
            if (((GetActiveScreenId() == SCR_ID_POC_CM) || (GetActiveScreenId() == SCR_ID_POC_TALK_OPTION)) &&
                (g_poc_cntx_p->audio_status == POC_AUDIO_NONE))
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_PRESENCE_UPDATED),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
        }
    }
    else
    {
        g_poc_cntx_p->talk_pres_ind_recved = POC_TALK_STATUS_OFF;
    }
    mmi_poc_talk_status_notify_res();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_status_notify_res
 * DESCRIPTION
 *  res send to protocol for talk status notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_status_notify_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_talk_status_notify_res_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_talk_status_notify_res_struct*) OslConstructDataPtr(sizeof(poc_talk_status_notify_res_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_talk_status_notify_res_struct) - sizeof(mmi_poc_dummy_req_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_TALK_STATUS_NOTIFY_RES;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_status_subscribe
 * DESCRIPTION
 *  talk status subscribe
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_status_subscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->curr_talk_staus_subscribe = MMI_TRUE;
    mmi_poc_talk_status_subscribe_req(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_status_unsubscribe
 * DESCRIPTION
 *  talk status unsubscribe
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_status_unsubscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->curr_talk_staus_subscribe = MMI_FALSE;
    mmi_poc_talk_status_subscribe_req(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_status_subscribe_req
 * DESCRIPTION
 *  talk status subscribe request
 * PARAMETERS
 *  subscribe       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_status_subscribe_req(U8 subscribe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_talk_status_subscribe_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (poc_talk_status_subscribe_req_struct*) OslConstructDataPtr(sizeof(poc_talk_status_subscribe_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_talk_status_subscribe_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    g_poc_cntx_p->talk_pres_ind_recved = POC_TALK_STATUS_NOT_READY;

    myMsgPtr->talk_id = g_poc_cntx_p->active_talk_id;

    myMsgPtr->subscribe = subscribe;

    SetProtocolEventHandler(mmi_poc_talk_status_subscribe_rsp, MSG_ID_POC_TALK_STATUS_SUBSCRIBE_RSP);

    DeleteUptoScrID(SCR_ID_POC_CM);
    GoBackHistory();

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_TALK_STATUS_SUBSCRIBE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_status_subscribe_rsp
 * DESCRIPTION
 *  response handler for talk status subscribe
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_status_subscribe_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_talk_invite_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_talk_invite_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_TALK_STATUS_SUBSCRIBE_RSP);

    if (msgRsp->result == POC_OK)
    {
        if (g_poc_cntx_p->curr_talk_staus_subscribe)
        {
            g_poc_cntx_p->talk_pres_ind_recved = POC_TALK_STATUS_ON;
        }
        else
        {
            g_poc_cntx_p->talk_pres_ind_recved = POC_TALK_STATUS_OFF;
        }
        if ((GetActiveScreenId() == SCR_ID_POC_CM) || (GetActiveScreenId() == SCR_ID_POC_TALK_OPTION))
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_STATUS_MODE_MODIFIED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
    }
    else
    {
        if ((GetActiveScreenId() == SCR_ID_POC_CM) || (GetActiveScreenId() == SCR_ID_POC_TALK_OPTION))
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_POC_STATUS_MODE_NOT_MODIFIED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_mdi_background_handler
 * DESCRIPTION
 *  mdi background handler
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_poc_mdi_background_handler(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->audio_status)
    {
        case POC_AUDIO_NONE:
            return (MMI_FALSE);
        case POC_AUDIO_ENCODING:
            mmi_poc_audio_encode_start();
            return (MMI_TRUE);
        case POC_AUDIO_DECODING:
            mmi_poc_audio_decode_start();
            return (MMI_TRUE);
        default:
            return (MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_new_personal_alert_ind
 * DESCRIPTION
 *  handler for new personal alert indication
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_new_personal_alert_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 message[MMI_POC_MAX_MSG_LEN];
    U8 message_ucs2[MMI_POC_MAX_MSG_LEN * ENCODING_LENGTH];
    poc_new_personal_alert_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_new_personal_alert_ind_struct*) info;

    msgRsp->content[MMI_POC_MAX_MSG_LEN] = 0;
    strncpy((S8*) message, (S8*) msgRsp->content, MMI_POC_MAX_MSG_LEN - 1);
    mmi_poc_history_add(
        POC_INCOMING_ALERT,
        MMI_FALSE,
        (U8*) msgRsp->sender.disp_name,
        (U8*) msgRsp->sender.uri,
        message);

    if (isInCall())
    {
        return;
    }

    memset(g_poc_cntx_p->cm_disp, 0, sizeof(g_poc_cntx_p->cm_disp));

    mmi_ucs2cpy((S8*) g_poc_cntx_p->cm_disp, (S8*) GetString(STR_ID_POC_ALERT_FROM));

    if (strlen((S8*) msgRsp->sender.disp_name))
    {
        mmi_poc_util_copy_with_dot((S8*) msgRsp->sender.disp_name, (S8*) message_ucs2, POC_MAX_DISP_LEN - 1);
    }
    else
    {
        mmi_poc_util_copy_with_dot((S8*) msgRsp->sender.uri, (S8*) message_ucs2, POC_MAX_DISP_LEN - 1);
    }

    mmi_ucs2cat((S8*) g_poc_cntx_p->cm_disp, (S8*) message_ucs2);

    mmi_poc_entry_personal_alert();
    
    mmi_poc_start_alert_ringing();
    StartTimer(POC_IND_TIMER, 5000, mmi_poc_exit_personal_alert);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_personal_alert
 * DESCRIPTION
 *  entry screen for poc personal alert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_personal_alert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_ENTRY_PERSONAL_ALERT);

    EntryNewScreen(SCR_ID_POC_INCOMING_ALERT, mmi_poc_exit_personal_alert, mmi_poc_entry_personal_alert, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_INCOMING_ALERT);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_INCOMING_ALERT);

    ShowCategory141Screen(
        STR_ID_POC_ALERT,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_VIEW,
        IMG_GLOBAL_YES,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_NO,
        (U8*) g_poc_cntx_p->cm_disp,
        IMG_ID_POC_CM_MT_RINGING,
        NULL);

    mmi_poc_enter_cm_key_light();

    SetLeftSoftkeyFunction(mmi_poc_alert_ringing_view, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_alert_ringing_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_alert_ringing_end, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_personal_alert
 * DESCRIPTION
 *  exit function for poc personal alert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_personal_alert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_EXIT_PERSONAL_ALERT);
    StopTimer(POC_IND_TIMER);
    if ((GetActiveScreenId() == SCR_ID_POC_INCOMING_ALERT) ||(IsScreenPresent(SCR_ID_POC_INCOMING_ALERT)))
    {
        mmi_poc_exit_cm_key_light();
    }
    mmi_poc_stop_alert_ringing();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_alert_ringing_view
 * DESCRIPTION
 *  view poc alert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_alert_ringing_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_exit_personal_alert();
    g_poc_cntx_p->call_history_selected = 0;
    mmi_poc_entry_call_history_info();
    DeleteScreenIfPresent(SCR_ID_POC_INCOMING_ALERT);
    DeleteScreenIfPresent(SCR_ID_POC_HISTORY_INFO);
    DeleteScreenIfPresent(SCR_ID_POC_HISTORY_OPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_alert_ringing_back
 * DESCRIPTION
 *  back from alert ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_alert_ringing_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_exit_personal_alert();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_alert_ringing_end
 * DESCRIPTION
 *  end from alert ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_alert_ringing_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_exit_personal_alert();
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_start_alert_ringing
 * DESCRIPTION
 *  start alert ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_start_alert_ringing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsSilentModeActivated() != TRUE)
    {
        switch (GetMtCallAlertTypeEnum())
        {
            case MMI_RING:
                AudioPlayToneWithCallBack(GetRingToneID(), GetRingTypeEnum(), MESSAGE_TONE);
                break;
            case MMI_VIBRATION_ONLY:
                VibratorOn();
                break;
            case MMI_VIBRATION_AND_RING:
            case MMI_VIBRATION_THEN_RING:
                VibratorOn();
                AudioPlayToneWithCallBack(GetRingToneID(), GetRingTypeEnum(), MESSAGE_TONE);
                break;
            case MMI_SILENT:
                break;
            case MMI_ALERT_NONE:
                break;
            default:
                AudioPlayToneWithCallBack(GetRingToneID(), GetRingTypeEnum(), MESSAGE_TONE);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_stop_alert_ringing
 * DESCRIPTION
 *  stop alert ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_stop_alert_ringing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetMtCallAlertTypeEnum())
    {
        case MMI_RING:
            mdi_audio_stop_all();
            break;
        case MMI_VIBRATION_ONLY:
            VibratorOff();
            break;
        case MMI_VIBRATION_AND_RING:
        case MMI_VIBRATION_THEN_RING:
            mdi_audio_stop_all();
            VibratorOff();
            break;
        case MMI_SILENT:
            break;
        case MMI_ALERT_NONE:
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_cm_history_del_handler
 * DESCRIPTION
 *  poc call management screen delete handler
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_poc_cm_history_del_handler(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
    if ((GetActiveScreenId() != SCR_ID_POC_CM) && (g_poc_cntx_p->call_status == POC_CALL_ACTIVE))
    {
        mmi_poc_disconnect_end();
    }
    return FALSE;
}

#endif /* __MMI_POC__ */ 

