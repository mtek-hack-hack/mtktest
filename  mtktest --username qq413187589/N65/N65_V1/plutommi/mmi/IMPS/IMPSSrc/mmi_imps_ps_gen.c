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
 * mmi_imps_ps_gen.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements protocol general feature related function/interface for IMPS application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_IMPS__
/*  Include: MMI header file */

#include "CommonScreens.h"


#include "IMPSResDef.h"
#include "mmi_imps_prot.h"
#include "Mmi_imps_gprot.h"

#include "wap_ps_struct.h"
#include "App_datetime.h"
#include "App_mine.h"

#include "FileManagerGProt.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif
/* ... Add More MMI header */

/*  Include: PS header file */
/* ... Add More PS header */

typedef struct
{
    U8 ref_count;
    U16 msg_len;
} imps_local_para_hdr;

/***************************************************************************** 
* Define
*****************************************************************************/
#define IMPS_MEMSET(addr, value, structure) memset(((U8*)addr)+sizeof(imps_local_para_hdr), value, (S32)(sizeof(structure) - sizeof(imps_local_para_hdr)))
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_imps_ps_get_reject_group_user_rsp(void *msg);

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_ps_before_idle
 * DESCRIPTION
 *  Initialize protocol event handlers when MMI power on.
 *  This is to prevent ready indication comes too early
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_ps_before_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_imps_ps_ready_ind, MSG_ID_MMI_IMPS_READY_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_ps_gen_hdlr
 * DESCRIPTION
 *  Initialize all protocol general event handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_ps_gen_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_imps_ps_login_rsp, MSG_ID_MMI_IMPS_LOGIN_RSP);
    SetProtocolEventHandler(mmi_imps_ps_abort_login_rsp, MSG_ID_MMI_IMPS_ABORT_LOGIN_RSP);
    SetProtocolEventHandler(mmi_imps_ps_logout_rsp, MSG_ID_MMI_IMPS_LOGOUT_RSP);
    
	SetProtocolEventHandler(mmi_imps_ps_newmsg_ind, MSG_ID_MMI_IMPS_NEWMESSAGE_IND);
    
	SetProtocolEventHandler(mmi_imps_ps_create_group_rsp, MSG_ID_MMI_IMPS_CREATE_GROUP_RSP);
    SetProtocolEventHandler(mmi_imps_ps_block_entity_rsp, MSG_ID_MMI_IMPS_BLOCK_ENTITY_RSP);
    SetProtocolEventHandler(mmi_imps_ps_join_group_rsp, MSG_ID_MMI_IMPS_JOIN_GROUP_RSP);
    
	SetProtocolEventHandler(mmi_imps_ps_abort_search_rsp, MSG_ID_MMI_IMPS_ABORT_SEARCH_RSP);
    SetProtocolEventHandler(mmi_imps_ps_send_msg_rsp, MSG_ID_MMI_IMPS_SEND_MESSAGE_RSP);
    SetProtocolEventHandler(mmi_imps_ps_del_group_rsp, MSG_ID_MMI_IMPS_DELETE_GROUP_RSP);
    
    SetProtocolEventHandler(mmi_imps_ps_leave_group_rsp, MSG_ID_MMI_IMPS_LEAVE_GROUP_RSP);
    SetProtocolEventHandler(mmi_imps_ps_leave_group_ind, MSG_ID_MMI_IMPS_LEAVE_GROUP_IND);
    SetProtocolEventHandler(mmi_imps_ps_invite_rsp, MSG_ID_MMI_IMPS_INVITE_RSP);
    SetProtocolEventHandler(mmi_imps_ps_invite_response_ind, MSG_ID_MMI_IMPS_INVITE_RESPONSE_IND);
    SetProtocolEventHandler(mmi_imps_ps_server_disconn_ind, MSG_ID_MMI_IMPS_DISCONNECT_IND);
    SetProtocolEventHandler(mmi_imps_ps_group_change_ind, MSG_ID_MMI_IMPS_GROUP_CHANGE_NOTIFY_IND);
    SetProtocolEventHandler(mmi_imps_ps_invite_ind, MSG_ID_MMI_IMPS_INVITE_IND);
    
    SetProtocolEventHandler(mmi_imps_ps_get_group_member_rsp, MSG_ID_MMI_IMPS_GET_GROUP_MEMBER_RSP);
    SetProtocolEventHandler(mmi_imps_ps_get_joined_user_rsp, MSG_ID_MMI_IMPS_GET_JOINED_USER_RSP);
    SetProtocolEventHandler(mmi_imps_ps_add_group_member_rsp, MSG_ID_MMI_IMPS_ADD_GROUP_MEMBER_RSP);
    SetProtocolEventHandler(mmi_imps_ps_remove_group_member_rsp, MSG_ID_MMI_IMPS_REMOVE_GROUP_MEMBER_RSP);
    SetProtocolEventHandler(mmi_imps_ps_member_access_rsp, MSG_ID_MMI_IMPS_MEMBER_ACCESS_RSP);
    SetProtocolEventHandler(mmi_imps_ps_abort_get_joined_user_rsp, MSG_ID_MMI_IMPS_ABORT_GET_JOINED_USER_RSP);
    SetProtocolEventHandler(mmi_imps_ps_abort_get_joined_user_rsp, MSG_ID_MMI_IMPS_ABORT_GET_GROUP_MEMBER_RSP);
    SetProtocolEventHandler(mmi_imps_ps_abort_get_joined_user_rsp, MSG_ID_MMI_IMPS_ABORT_GET_REJECTED_USER_RSP);

    SetProtocolEventHandler(mmi_imps_ps_subs_notify_rsp, MSG_ID_MMI_IMPS_SUBS_NOTIFY_RSP);
    SetProtocolEventHandler(mmi_imps_ps_unsubs_notify_rsp, MSG_ID_MMI_IMPS_UNSUBS_NOTIFY_RSP);
    SetProtocolEventHandler(mmi_imps_ps_notify_request_ind, MSG_ID_MMI_IMPS_NOTIFY_REQUEST_IND);

    SetProtocolEventHandler(mmi_imps_ps_system_message_ind, MSG_ID_MMI_IMPS_SYSTEM_MSG_IND);
    SetProtocolEventHandler(mmi_imps_ps_system_message_user_rsp, MSG_ID_MMI_IMPS_SYSTEM_MSG_USER_RSP);
    SetProtocolEventHandler(mmi_imps_ps_dl_large_file_rsp, MSG_ID_MMI_IMPS_DL_FILE_RSP);    
    
    SetProtocolEventHandler(mmi_imps_ps_http_auth_ind, MSG_ID_MMI_IMPS_HTTP_AUTH_IND);
    

#ifndef __MTK_TARGET__
    imps_p->gen_info.ps_ready_state |= IMPS_LOGIN_PS_READY;
    imps_p->gen_info.ps_ready_state |= IMPS_LOGIN_RAC_READY;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_send_msg
 * DESCRIPTION
 *  Wrapper function to send message to IMPS module
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         [?]         [?]         [?]
 *  peer_buf_ptr        [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store the index of request */
    imps_p->gen_info.curr_action = msg_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_IMPS;
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = (oslParaType*) local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_login_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_LOGIN_REQ to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_login_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* send login request to PS */
    mmi_imps_login_req_struct *req;
    mmi_imps_prof_struct *act_prof = &imps_p->act_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGIN_REQ || imps_p->gen_info.is_login)
    {
        return;
    }

    req = (mmi_imps_login_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_login_req_struct));

    IMPS_MEMSET(req, 0, mmi_imps_login_req_struct);

    /* connection type, shall be set according to the enum value of PS */
    if (act_prof->conn_type == 0)
    {
        req->conn_type = IMPS_CONN_TYPE_HTTP;
    }
    else
    {
        req->conn_type = IMPS_CONN_TYPE_WSP_CO;
    }

    /* data account */
    req->net_id = act_prof->dt_acct;

    /* user proxy */
    req->use_proxy = act_prof->use_proxy;

    /* proxy info */
    if (act_prof->use_proxy)
    {
        req->prx_port = act_prof->proxy_port;
        req->prx_ip[0] = act_prof->proxy_ip[0];
        req->prx_ip[1] = act_prof->proxy_ip[1];
        req->prx_ip[2] = act_prof->proxy_ip[2];
        req->prx_ip[3] = act_prof->proxy_ip[3];
        strncpy((S8*) req->prx_usrn, (S8*) act_prof->proxy_username, IMPS_MAX_PROXY_USERNAME_LEN - 1);
        strncpy((S8*) req->prx_pwd, (S8*) act_prof->proxy_passwd, IMPS_MAX_PROXY_PASSWORD_LEN - 1);
    }

    if (strlen((S8*) act_prof->auth_usrn) > 0)
    {
        strcpy((S8*) req->auth_usrn, (S8*) act_prof->auth_usrn);
        strncpy((S8*) req->auth_pwd, (S8*) act_prof->auth_pwd, IMPS_MAX_HTTP_AUTH_PASSWORD_LEN - 1);        
    }

    /* user name */
    strcpy((S8*) req->imps_usrn, (S8*) act_prof->username);

    /* password */
    strcpy((S8*) req->imps_pwd, (S8*) act_prof->passwd);

    /* server */
    strcpy((S8*) req->imps_server, (S8*) act_prof->server);

    /* currently no usage */
    req->imps_service_set = 0xff;

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_LOGIN_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_login_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_LOGIN_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_login_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_login_rsp_struct *rsp = (mmi_imps_login_rsp_struct*) msg;
	mmi_imps_nvram_struct *prof_buff = NULL;
	mmi_imps_prof_struct *prof = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_ABORT_LOGIN_REQ)
    {
        return;
    }

    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        imps_p->gen_info.is_login = TRUE;

        /* maintain the csp version */
        imps_p->gen_info.imps_version = rsp->imps_version;

        /* not agreed service */
        imps_p->gen_info.not_agreed_serv = rsp->not_agreed_serv;

        /* not agreed all content type, it means there is a list indicate the accepted content types by server */
        imps_p->gen_info.not_agreed_all = rsp->not_agreed_all;

        /* reload contact list from cache */
        mmi_imps_util_init_list();

        /* login with empty username case */
        if (strlen((S8*) rsp->imps_usrn) != 0 && strlen((S8*) imps_p->act_prof.username) == 0)
        {
            U16 disp_buff[IMPS_MAX_CONTENT_LEN];
            U16 temp_buff[IMPS_MAX_CONTENT_LEN];
            
            /* save username and password to current active profile */
            strcpy((S8*) imps_p->act_prof.username, (S8*) rsp->imps_usrn);
            strcpy((S8*) imps_p->act_prof.passwd, (S8*) rsp->imps_pwd);

            /* save username and password to nvram */
            prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);

            memset(prof_buff, 0, NVRAM_EF_IMPS_SIZE);

            mmi_imps_util_read_nvram((void*)prof_buff);

            /* retrieve the address of active profile */
            prof = &prof_buff->prof[prof_buff->act_prof_indx - 1];

            strcpy((S8*) prof->username, (S8*) imps_p->act_prof.username);
            strcpy((S8*) prof->passwd, (S8*) imps_p->act_prof.passwd);

            mmi_imps_util_write_nvram((void*)prof_buff);

            OslMfree(prof_buff); 
            
            strcpy((S8*) imps_p->cont_info.cont_list[0].id, (S8*) imps_p->act_prof.username); 

            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_ACCOUNT_INFO));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":\n");
            
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_PASSWD));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");  
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) imps_p->act_prof.passwd);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);                       

            DisplayConfirm(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                0,
                0,
                (UI_string_type) disp_buff,
                0,
                SUCCESS_TONE);
            
            SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        }        
        

        /* update status icon */
        mmi_imps_util_update_login_icon();

        /* entry contact list screen */
        imps_p->gen_info.no_tab = 1;

        if (imps_p->gen_info.is_reentry)
        {
            mmi_imps_re_entry_app();
        }
        else
        {
            if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
            {
                mmi_imps_pre_entry_cont();
                DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
            }
            else
            {
                /* in other screen, replace progress screen by the result screen */
                HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_CONT, mmi_imps_pre_entry_cont);
            }

            DeleteScreenIfPresent(SCR_ID_IMPS_MAIN);
        }

        /* send request to get latest contact list */
        mmi_imps_ps_get_contact_list_req();

        if (imps_p->gen_info.not_agreed_serv.not_agreed == TRUE)
        {
            mmi_imps_check_not_agreed_service();
        }
    }
    else
    {
        /* for non auto-login case */
        if (IsScreenPresent(SCR_ID_IMPS_PROGRESS) || GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
        {
            mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(rsp->result));
            /* if it's re_entry from other application */
            if (imps_p->gen_info.is_reentry)
            {
                HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_MAIN, mmi_imps_entry_main);
            }
            else
            {
                DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
            }
        }

        imps_p->gen_info.is_reentry = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_login_req
 * DESCRIPTION
 *  Abort login process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_login_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ABORT_LOGIN_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_login_rsp
 * DESCRIPTION
 *  Abort login process
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_login_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
    }
    else
    {
        mmi_imps_login_abort_finish();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_logout_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_LOGOUT_REQ to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_logout_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send login request to PS */
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_LOGOUT_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_logout_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_LOGOUT_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_logout_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    /* because logout will be always success, no checking procedure required */
    imps_p->gen_info.is_login = FALSE;

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
    }
    else
    {
        mmi_imps_logout_complete();
    }

    mmi_imps_util_update_login_icon();
}


#define ADD_SEARCH_PS_PROT


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_search_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_SEARCH_REQ to PS.
 * PARAMETERS
 *  type        [IN]        Flag to indicate it's to search user or group
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_search_req(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_search_req_struct *req =
        (mmi_imps_search_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_search_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_search_req_struct);

    imps_p->search_result.count = 0;

    req->search_type = type;

    req->search_limit = IMPS_MAX_SEARCH_RESULT;

    if (type == IMPS_SEARCH_USER)
    {
        mmi_imps_search_cont_struct *search_p = imps_p->search_cont;
        mmi_imps_search_user_criteria_struct *user_criteria = &req->search_element.user_criteria;

        /* gender */
        user_criteria->gender = (U8) search_p->gender;

        /* online status */
        user_criteria->user_onlinestatus = (U8) search_p->user_onlinestatus;

        /* marital status */
        user_criteria->marital_status = (U16) search_p->marital_status;

        /* user alias */
        if (mmi_ucs2strlen((S8*) search_p->user_alias) > 0)
        {
            mmi_ucs2cpy((S8*) user_criteria->user_alias, (S8*) search_p->user_alias);
        }

        /* email address */
        if (mmi_ucs2strlen((S8*) search_p->user_emailaddr) > 0)
        {
            mmi_ucs2_to_asc((S8*) user_criteria->user_emailaddr, (S8*) search_p->user_emailaddr);
        }        

        /* first name */
        if (mmi_ucs2strlen((S8*) search_p->user_firstname) > 0)
        {
            mmi_ucs2cpy((S8*) user_criteria->user_firstname, (S8*) search_p->user_firstname);
        }        

        /* user id */
        if (mmi_ucs2strlen((S8*) search_p->user_id) > 0)
        {
            mmi_ucs2_to_asc((S8*) user_criteria->user_id, (S8*) search_p->user_id);
        }       

        /* last name */
        if (mmi_ucs2strlen((S8*) search_p->user_lastname) > 0)
        {
            mmi_ucs2cpy((S8*) user_criteria->user_lastname, (S8*) search_p->user_lastname);
        }         

        /* mobile number */
        if (mmi_ucs2strlen((S8*) search_p->user_mobile_number) > 0)
        {
            mmi_ucs2_to_asc((S8*) user_criteria->user_mobile_number, (S8*) search_p->user_mobile_number);
        }        

        /* max age */
        if (mmi_ucs2strlen((S8*) search_p->user_max_age) == 1)
        {
            user_criteria->user_max_age = search_p->user_max_age[0] - 0x30;
            if (user_criteria->user_max_age == 0)
            {                
                user_criteria->user_max_age = 0xff;        
            }            
        }
        else if (mmi_ucs2strlen((S8*) search_p->user_max_age) == 2)
        {
            user_criteria->user_max_age = (search_p->user_max_age[0] - 0x30) * 10 + search_p->user_max_age[1] - 0x30;
        }
        else
        {
            user_criteria->user_max_age = 0xff;  
        }

        /* min age */
        if (mmi_ucs2strlen((S8*) search_p->user_min_age) == 1)
        {
            user_criteria->user_min_age = search_p->user_min_age[0] - 0x30;
            if (user_criteria->user_min_age == 0)
            {                
                user_criteria->user_min_age = 0xff;        
            }
        }
        else if (mmi_ucs2strlen((S8*) search_p->user_min_age) == 2)
        {
            user_criteria->user_min_age = (search_p->user_min_age[0] - 0x30) * 10 + search_p->user_min_age[1] - 0x30;
        }    
        else
        {
            user_criteria->user_min_age = 0xff;  
        }
        
        /* friendly name */
        if (mmi_ucs2strlen((S8*) search_p->fname) > 0)
        {
            mmi_ucs2cpy((S8*) user_criteria->fname, (S8*) search_p->fname);
        }        

        /* city */
        if (mmi_ucs2strlen((S8*) search_p->city) > 0)
        {
            mmi_ucs2cpy((S8*) user_criteria->city, (S8*) search_p->city);
        }        

        /* free text */
        /*if (mmi_ucs2strlen(search_p->free_text) > 0)
        {
            mmi_ucs2cpy((S8*) user_criteria->, (S8*) search_p->free_text);
        }*/

        /* intention */
        if (mmi_ucs2strlen((S8*) search_p->intention) > 0)
        {
            mmi_ucs2cpy((S8*) user_criteria->Intention, (S8*) search_p->intention);
        }       

        /* hobbies */
        if (mmi_ucs2strlen((S8*) search_p->hobbies) > 0)
        {
            mmi_ucs2cpy((S8*) user_criteria->hobbies, (S8*) search_p->hobbies);
        }
        
    }
    else    /* group */
    {
        mmi_imps_search_room_struct *search_p = imps_p->search_room;
        mmi_imps_search_group_criteria_struct *group_criteria = &req->search_element.group_criteria;

        /* group id */
        if (mmi_ucs2strlen((S8*) search_p->room_id) > 0)
        {
            mmi_ucs2_to_asc((S8*) group_criteria->group_id, (S8*) search_p->room_id);
        }

        /* group name */
        if (mmi_ucs2strlen((S8*) search_p->room_name) > 0)
        {
            mmi_ucs2cpy((S8*) group_criteria->group_name, (S8*) search_p->room_name);
        }

        /* owner id */
        if (mmi_ucs2strlen((S8*) search_p->room_owner) > 0)
        {
            mmi_ucs2_to_asc((S8*) group_criteria->group_user_id_owner, (S8*) search_p->room_owner);
        }

        /* topic */
        if (mmi_ucs2strlen((S8*) search_p->room_topic) > 0)
        {
            mmi_ucs2cpy((S8*) group_criteria->group_topic, (S8*) search_p->room_topic);
        }        
        

        /* joined user */
        if (mmi_ucs2strlen((S8*) search_p->room_joined_user) > 0)
        {
            mmi_ucs2_to_asc((S8*) group_criteria->group_user_id_joined, (S8*) search_p->room_joined_user);
        }        

        /* autojoin user */
        if (mmi_ucs2strlen((S8*) search_p->room_autojoin_user) > 0)
        {
            mmi_ucs2_to_asc((S8*) group_criteria->group_user_id_autojoin, (S8*) search_p->room_autojoin_user);
        }
    }

    SetProtocolEventHandler(mmi_imps_ps_search_rsp, MSG_ID_MMI_IMPS_SEARCH_RSP);
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_SEARCH_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_search_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_SEARCH_RSP. This handler is for searching contacts
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_search_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_search_rsp_struct *rsp = (mmi_imps_search_rsp_struct*) msg;
    U16 active_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        S32 i, j;
        S32 count = (S32) rsp->search_result.entity_count;

        /* copy data to local buffer */
        for (i = 0, j = (S32) imps_p->search_result.count; i < count && j < IMPS_MAX_SEARCH_RESULT; i++, j++)
        {
            mmi_imps_entity_struct *local_entity = &imps_p->search_result.entity[j];
            imps_entity_struct *ps_entity = &rsp->search_result.entity[i];

            strncpy((S8*) local_entity->id, (S8*) ps_entity->id, (IMPS_MAX_ID_LEN - 1));
            mmi_ucs2ncpy((S8*) local_entity->sname, (S8*) ps_entity->sname, IMPS_MAX_NAME_LEN);
        }

        imps_p->search_result.count = (U8) j;

        if (rsp->completion_flag)
        {
            if (active_scr == SCR_ID_IMPS_PROGRESS)
            {
                mmi_imps_entry_search_result(); /* display list of user */
            }
            else
            {
                HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_SEARCH_RESULT, mmi_imps_entry_search_result);
                return;
            }
        }
        else
        {
            return; /* do nothing */
        }
    }
    else
    {
        if (imps_p->search_result.count == 0)
        {
            mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(rsp->result));
            if (active_scr == SCR_ID_IMPS_PROGRESS)
            {
                DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
            }
            else
            {
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_SEARCH_OPT);
            }

            return;
        }
        else
        {
            if (active_scr == SCR_ID_IMPS_PROGRESS)
            {
                mmi_imps_entry_search_result(); /* display list of user */
            }
            else
            {
                HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_SEARCH_RESULT, mmi_imps_entry_search_result);
                DeleteScreenIfPresent(SCR_ID_IMPS_SEARCH_OPT);
                if (imps_p->search_result.search_cause == IMPS_SEARCH_CONT)
                {
                    DeleteScreenIfPresent(SCR_ID_IMPS_CONT_SEARCH);
                }
                else
                {
                    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_ROOM_SEARCH);
                }
                return;
            }
        }
    }

    /* determine the screen to go back */
    if (imps_p->search_result.search_cause == IMPS_SEARCH_CONT)
    {
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_ADD_CONT);
    }
    else
    {
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT_ROOM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_search_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_ABORT_SEARCH_REQ to PS
 * PARAMETERS
 *  void
 *  msg(?)      [IN]        Result of response(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_search_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ABORT_SEARCH_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_search_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_ABORT_SEARCH_RSP. This handler is for searching contacts
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_search_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_abort_search_finish();

    /* restore current action */
    imps_p->gen_info.curr_action = 0;
}


#define BLOCK_PS_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_block_entity_req
 * DESCRIPTION
 *  Send request to block/grant a contact
 * PARAMETERS
 *  type        [IN]        Type of request -- block user or grant user
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_block_entity_req(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_block_entity_req_struct *req =
        (mmi_imps_block_entity_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_block_entity_req_struct));
    imps_entity_struct *entity;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_block_entity_req_struct);

    req->block_in_use = TRUE;
    req->grant_in_use = FALSE;

    if (type == IMPS_BLOCK)
    {
        entity = &req->add_block_user;
    }
    else
    {
        entity = &req->remove_block_user;
    }
    entity->entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy((S8*) entity->id, (S8*) imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_BLOCK_ENTITY_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_block_entity_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_BLOCK_ENTITY_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_block_entity_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_block_entity_rsp_struct *rsp = (mmi_imps_block_entity_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_block_grant_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_block_list_req
 * DESCRIPTION
 *  Send request to get block list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_block_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_BLOCK_LIST_REQ, NULL, NULL);

    /* restore current action -- won't store state for background update */
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_block_list_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_IMPS_GET_BLOCK_LIST_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_block_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_block_list_rsp_struct *rsp = (mmi_imps_get_block_list_rsp_struct*) msg;
    S32 i;
    S32 block_count;
    U32 len;
    S32 result;
    mmi_imps_cont_struct *cont;
    FS_HANDLE fileHandle;
    imps_entity_struct *entity;
    imps_entity_list_struct *id_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    block_count = (S32) rsp->block_list.entity_num;

    /* block list exists */
    if ( /* rsp->block_in_use && */ block_count > 0)
    {
        S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);        
        mmi_imps_util_get_filename_from_fileindex(rsp->block_list.entity_list_file_index, IMPS_LIST_FILE_BLOCKED, (S8*) ucs2_folder);
        fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);
        if (fileHandle > 0)
        {
            entity = (imps_entity_struct*) OslMalloc(sizeof(imps_entity_struct));

            for (i = 0; i < block_count; i++)
            {
                result = FS_Read(fileHandle, (void*)entity, sizeof(imps_entity_struct), &len);
                if (result == FS_NO_ERROR)
                {
                    /* search if the user is in contact list */
                    cont = mmi_imps_util_search_cont((S8*) entity->id);
                    if (cont != NULL)
                    {
                        cont->comm_state |= IMPS_CONT_BLOCK;
                    }
                }
                else
                {
                    break;
                }
            }
            FS_Close(fileHandle);
            FS_Delete((U16*) ucs2_folder);
            OslMfree(entity);
        }
        OslMfree(ucs2_folder);
    }

    /* redraw context list */

    if (imps_p->gen_info.auto_update_done == FALSE)
    {
		if (imps_p->group_info.no_group > 0)
		{
			/* subscribe contacts' pa during login */
			id_list = OslMalloc(sizeof(imps_entity_list_struct));
			memset(id_list, 0, sizeof(imps_entity_list_struct));
			id_list->entity_count = 0;
			imps_p->gen_info.curr_subs = 0;
			for(i = 0; i < IMPS_MAX_ENTITY_NUMBER && i < imps_p->group_info.no_group; i++)
			{           
				id_list->entity[id_list->entity_count].entity_type = IMPS_ENTITY_TYPE_CONTACT_LIST;
				strcpy((S8*) id_list->entity[id_list->entity_count++].id, (S8*) imps_p->group_info.group_list[i + imps_p->gen_info.curr_subs].group_id);
				if ((imps_p->group_info.no_group - i == 1) || (IMPS_MAX_ENTITY_NUMBER - i == 1)) 
				{
					imps_p->gen_info.curr_subs += (i + 1);
					/* send request to PS to subscribe contacts' pa */
					mmi_imps_ps_subs_pa_req((void*) id_list);                 
				}
			}
			
			OslMfree(id_list);
		}
		else
		{
			mmi_imps_sync_cont_list();
			imps_p->gen_info.auto_update_done = TRUE;
		}        
    }
    else
    {
		mmi_imps_cont_redraw_list();
        
    }
}


#define MSG_PS_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_newmsg_ind
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_NEWMSG_IND
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_newmsg_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count;
    BOOL is_in_room = FALSE;
    imps_entity_struct *entity;
    mmi_imps_newmessage_ind_struct *ind = (mmi_imps_newmessage_ind_struct*) msg;
    S32 unused_room = IMPS_MAX_NO_ROOM;
    U16 active_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* logout or during logout period */
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    /* no message, to prevent abnormal cases */
    if (ind->msg_len == 0)
    {
        return;
    }

    /* check if there is a chat room for the recipient */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        mmi_imps_room_struct *room = &imps_p->room_info.room_list[i];

        if (room->is_used)
        {
            if (room->type == IMPS_ROOM_TYPE_SINGLE &&
                (ind->recipient.entity_type == IMPS_ENTITY_TYPE_USER ||
                ind->recipient.entity_type == IMPS_ENTITY_TYPE_USER_FRIENDLY_NAME))
            {
                /* single talk */
                entity = &ind->sender;
            }
            else
            {
                /* chat rooms */
                entity = &ind->recipient;

                /* if the sender is the receiver himself */
                if (ind->sender.entity_type == IMPS_ENTITY_TYPE_SCREEN_NAME)    /* screen name only */
                {                    
                    /* compare screen name */
                    if (mmi_ucs2cmp((S8*) ind->sender.sname, (S8*) room->sname) == 0)
                    {
                        return;
                    }
                }
                else
                {
                    /* compare screen name */
                    if (mmi_imps_util_is_id_same((S8*) ind->sender.id, (S8*) imps_p->cont_info.cont_list[0].id))
                    {
                        return;
                    }
                }
            }

            if (mmi_imps_util_is_id_same((S8*) room->room_id, (S8*) entity->id))      /* chat room exists */
            {
		        mmi_imps_util_play_tone(IMPS_MSG_TONE);

                mmi_imps_chat_recv_msg((mmi_imps_newmessage_ind_struct*) ind, (U8) i);

                mmi_imps_tab_update_event(room, entity);

                /* stop searching */
                is_in_room = TRUE;
                break;
            }
        }
        else
        {
            unused_room = i;    /* pre-record unused room */
        }
    }

    /* if no check room found, check if the receipient is in contact list */
    if (is_in_room == FALSE && unused_room != IMPS_MAX_NO_ROOM) /* there still some chat room to store message */
    {
        count = (S32) imps_p->cont_info.no_cont;
        entity = &ind->sender;
        if (entity->entity_type == IMPS_ENTITY_TYPE_USER ||
            entity->entity_type == IMPS_ENTITY_TYPE_USER_FRIENDLY_NAME)
        {
            mmi_imps_room_struct *room = &imps_p->room_info.room_list[unused_room];

            /* create a new tab */
            memset(room, 0, sizeof(mmi_imps_room_struct));
            room->is_used = TRUE;
            room->type = IMPS_ROOM_TYPE_SINGLE;
            room->tab_index = imps_p->gen_info.no_tab;
            imps_p->gen_info.no_tab++;

            strcpy((S8*) room->room_id, (S8*) entity->id);

            /* display be screen name if the user's alias is not empty */
            if (mmi_ucs2strlen((S8*) entity->sname))
            {
                mmi_ucs2cpy((S8*) room->room_name, (S8*) entity->sname);
                mmi_ucs2cpy((S8*) room->sname, (S8*) entity->sname);
            }
            else
            {
                mmi_asc_to_ucs2((S8*) room->room_name, (S8*) entity->id);
                room->sname[0] = 0;
            }

            imps_p->room_info.no_rooms++;

	        mmi_imps_util_play_tone(IMPS_MSG_TONE);

            /* update display buffer */
            mmi_imps_new_room_string((S8*) room->chat_buff, (S8*) room->room_name);
            mmi_imps_chat_recv_msg((mmi_imps_newmessage_ind_struct*) ind, (U8) unused_room);

            /* redraw tab becuase new tab created */
            mmi_imps_tab_redraw(active_scr);

            /* update tab when event comes event */
            mmi_imps_tab_update_event(room, entity);
        }
    }
    /*
     * else
     * {
     * neglect the message because of buffer full
     * }
     */
}


#define CHAT_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_send_msg_req
 * DESCRIPTION
 *  Send request to protocol
 * PARAMETERS
 *  msg_id          [IN]        Index of session
 *  msg             [IN]        String message to be sent
 *  recv_id         [IN]        Id of recipient
 *  recv_type       [IN]        Type of recipient
 *  screen_name     [IN]        Screen name if exists
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_send_msg_req(S32 msg_id, S16 *msg, U8 *recv_id, U8 recv_type, S8 *screen_name, BOOL is_text_plain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_send_message_req_struct *req =
        (mmi_imps_send_message_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_send_message_req_struct));
	U16 ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_send_message_req_struct);
    
    req->message_id = msg_id;

    mmi_ucs2cpy((S8*) req->message_content, (S8*) msg);

    req->content_length = mmi_ucs2strlen((S8*) msg);

    req->recipients.entity_count = 1;

    req->recipients.entity[0].entity_type = recv_type;

    strcpy((S8*) req->recipients.entity[0].id, (S8*) recv_id);

    req->is_group_message = TRUE;
    if (recv_type == IMPS_ENTITY_TYPE_USER)
    {
        req->is_group_message = FALSE;
    }
    else
    {
        mmi_ucs2cpy((S8*) req->sender_sname, (S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].sname);        
    }

    if (screen_name)
    {
        mmi_ucs2cpy((S8*) req->recipients.entity[0].sname, screen_name);
    }    

    /* text format */
    req->is_font_p = FALSE;
	req->font.style = 0;
    req->font.size = 0;
	req->font.color = 0;

    req->use_file = FALSE;
    if (is_text_plain == TRUE)  /* send text plain */
    {
        strcpy((S8*) req->content_type, (S8*) "text/plain");

        /* style */
        ch = 0;
        ch = imps_p->chat_info.sel_style;
        if (ch != 0)
        {
            req->is_font_p = TRUE;
            req->font.style = ch;
        }

        /* size */
        ch = 0;
        ch = imps_p->chat_info.sel_size;
        if (ch != 0)
        {
            req->is_font_p = TRUE;
            req->font.size = ch;
        }

        /* color */
        ch = 0;
        ch = imps_p->chat_info.sel_color;
        
        if (ch != 0)
        {
            req->is_font_p = TRUE;
            req->font.color = ch;
        }        
    }
    else
    {
        applib_mime_type_struct *mime_type;        
        S8 *mime_string = NULL;
        
#ifdef __DRM_SUPPORT__
        mime_string = (S8*) DRM_get_content_type(0, (U16*) msg);
#endif /* __DRM_SUPPORT__ */  

        if (mime_string == NULL)
        {
            mime_type = mime_get_file_type((U16*) msg); 
            if (mime_type != NULL)
            {
                mime_string = mime_type->mime_string;
            }
        }

        if (mime_string != NULL)
        {
            strcpy((S8*) req->content_type, mime_string);
            if (mmi_imps_util_stricmp((S8*) mime_string, (S8*) "text/plain") == FALSE)
            {
                FS_HANDLE handle;
                if ((handle = FS_Open((PU16) msg, FS_READ_ONLY)) >= FS_NO_ERROR)
                {
                    S8 temp_buff[4];
                    U32 read_size;
                    FS_Read(handle, temp_buff, 3, &read_size);
                    if (temp_buff[0] == (S8) 0xEF && temp_buff[1] == (S8) 0xBB && temp_buff[2] == (S8) 0xBF)
                    {
                        //return MMI_CHSET_UTF8;
                        strcat((S8*) req->content_type, ";charset=utf-8");
                    }
                    else if (temp_buff[0] == (S8) 0xFE && temp_buff[1] == (S8) 0xFF)
                    {
                        //return MMI_CHSET_UCS2;
                        strcat((S8*) req->content_type, ";charset=utf-16");
                    }
                    else if (temp_buff[0] == (S8) 0xFF && temp_buff[1] == (S8) 0xFE)
                    {
                        //return MMI_CHSET_UCS2;
                        strcat((S8*) req->content_type, ";charset=utf-16");
                    }
                    else
                    {
                        strcat((S8*) req->content_type, ";charset=?");
                    }
                }
                FS_Close(handle);                
            }
            req->use_file = TRUE;
        }
    }

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_SEND_MESSAGE_REQ, req, NULL);

    /* restore current action */
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_send_msg_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_SEND_MESSAGE_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_send_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_send_message_rsp_struct *rsp = (mmi_imps_send_message_rsp_struct*) msg;
    S32 i;
    mmi_imps_chat_session_struct *session = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* logout or during logout period */
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    /* find session index of the message */
    for (i = 0; i < IMPS_MAX_CHAT_MSG_COUNT; i++)
    {
        if (imps_p->chat_info.chat_session[i].session_id == rsp->message_id)
        {
            session = &imps_p->chat_info.chat_session[i];
            break;
        }
    }

    if (session)
    {
        if (rsp->result != IMPS_OK)
        {
            S32 room_index;
            imps_entity_struct *entity = OslMalloc(sizeof(imps_entity_struct));
            mmi_imps_room_struct *room;

	    mmi_imps_util_play_tone(IMPS_ERR_TONE);

            room_index = mmi_imps_util_find_room((S8*) session->room_id);
            room = &imps_p->room_info.room_list[room_index];

            mmi_imps_chat_display_send_failed((U8) room_index, session->input_buff);
            if (room->type == IMPS_ROOM_TYPE_SINGLE)    /* only single talk required */
            {
                strcpy((S8*) entity->id, (S8*) imps_p->cont_info.cont_list[0].id);
                mmi_imps_tab_update_event(room, entity);
            }
            else
            {
                mmi_imps_tab_update_event(room, NULL);
            }

            OslMfree(entity);
        }

        /* reset session */
        session->room_id[0] = 0;
        session->session_id = 0;
        session->input_buff[0] = 0;
    }
}

#define GROUP_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_create_group_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_CREATE_GROUP_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_create_group_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_create_group_req_struct *req =
        (mmi_imps_create_group_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_create_group_req_struct));
    mmi_imps_room_inline_struct *inline_open_room = imps_p->room_info.inline_open_room;
    U32 len, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_create_group_req_struct);

    req->join_grouop = TRUE;

    /* IMPS_ACCESS_TYPE_OPEN == 0 */
    /* req->group_access_type = IMPS_ACCESS_TYPE_OPEN; */
    mmi_ucs2_to_asc((S8*) req->group_id, (S8*) inline_open_room->room_name);
    len = strlen((S8*) imps_p->act_prof.username);
    while (imps_p->act_prof.username[i] != '@' && i < len) i++;
    strncpy((S8*) inline_open_room->room_id, (S8*) imps_p->act_prof.username, i);
    sprintf((S8*) ((S8*)inline_open_room->room_id + i), "/%s%s", req->group_id, &imps_p->act_prof.username[i]);

    memcpy(req->group_id, inline_open_room->room_id, IMPS_MAX_ID_LEN);

    mmi_ucs2cpy((S8*) req->group_name, (S8*) inline_open_room->room_name);

    if (mmi_ucs2strlen((S8*) inline_open_room->topic))
    {
        mmi_ucs2cpy((S8*) req->group_topic, (S8*) inline_open_room->topic);
    }

    if (mmi_ucs2strlen((S8*) inline_open_room->welcome))
    {
        mmi_ucs2cpy((S8*) req->welcome_note, (S8*) inline_open_room->welcome);
    }

    if (mmi_ucs2strlen((S8*) inline_open_room->sname))
    {
        mmi_ucs2cpy((S8*) req->sname, (S8*) inline_open_room->sname);
    }

    /* keneng : access type */
    req->group_access_type = (U8) inline_open_room->access_type;

    if (inline_open_room->subscribe_notify == 0)
    {
        req->subscribe_notif = TRUE;
    }
    else
    {
        req->subscribe_notif = FALSE;        
    }

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_CREATE_GROUP_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_create_group_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_CREATE_GROUP_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_create_group_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_create_group_rsp_struct *rsp = (mmi_imps_create_group_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_room_create_finish(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_join_group_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_JOIN_GROUP_REQ to PS
 * PARAMETERS
 *  id      [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_join_group_req(S8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_join_group_req_struct *req =
        (mmi_imps_join_group_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_join_group_req_struct));

    mmi_imps_join_inline_struct *inline_join = imps_p->room_info.inline_join;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_join_group_req_struct);
    
    req->user_auto_join_group = TRUE;

    mmi_ucs2cpy((S8*) req->sname, (S8*) inline_join->sname);

    strcpy((S8*) req->group_id, id);

    if (inline_join->disclose_id == 0)
    {
        req->user_show_id = TRUE;
    }
    else
    {
        req->user_show_id = FALSE;
    }

    if (inline_join->subscribe_notify == 0)
    {
        req->subscribe_notif = TRUE;
    }
    else
    {
        req->subscribe_notif = FALSE;
    }

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_JOIN_GROUP_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_join_group_rsp
 * DESCRIPTION
 *  Response handler for MSG_ID_MMI_IMPS_JOIN_GROUP_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_join_group_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_join_room_finished(msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_del_group_req
 * DESCRIPTION
 *  Send request to delete a group
 * PARAMETERS
 *  room_id     [IN]        Id of the room
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_del_group_req(U8 *room_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_delete_group_req_struct *req =
        (mmi_imps_delete_group_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_delete_group_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_delete_group_req_struct);
    
    strcpy((S8*) req->group_id, (S8*) room_id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_DELETE_GROUP_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_del_group_rsp
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_IMPS_DELETE_GROUP_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_del_group_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_delete_group_rsp_struct *rsp = (mmi_imps_delete_group_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_close_chat_room_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_leave_group_req
 * DESCRIPTION
 *  Send request to leave a group
 * PARAMETERS
 *  room_id     [IN]        Id of the room
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_leave_group_req(U8 *room_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_leave_group_req_struct *req =
        (mmi_imps_leave_group_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_leave_group_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_leave_group_req_struct);
    
    strcpy((S8*) req->group_id, (S8*) room_id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_LEAVE_GROUP_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_leave_group_rsp
 * DESCRIPTION
 *  Response handler for MSG_ID_MMI_IMPS_LEAVE_GROUP_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_leave_group_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_leave_group_rsp_struct *rsp = (mmi_imps_leave_group_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_close_chat_room_done((S32) rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_leave_group_ind
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_LEAVE_GROUP_IND
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_leave_group_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_leave_group_ind_struct *ind = (mmi_imps_leave_group_ind_struct*) msg;
    mmi_imps_room_struct *room;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the chat room */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        room = &imps_p->room_info.room_list[i];
        if (room->is_used)
        {
            if (room->type == IMPS_ROOM_TYPE_GROUP_CREATE || room->type == IMPS_ROOM_TYPE_GROUP_JOIN)
            {
                if (mmi_imps_util_is_id_same((S8*) room->room_id, (S8*) ind->group_id))       /* chat room exists */
                {
                    break;
                }
            }
        }
    }

    if (i < IMPS_MAX_NO_ROOM)   /* room exists */
    {
        U16 scr_id = GetActiveScreenId();	

        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_CHAT_ROOM_CLOSE);

        if (scr_id == SCR_ID_IMPS_CHAT) /* in chatting screen */
        {
            /* if the room is current chatting room -- go to contact list screen */
            if (room->tab_index == imps_p->gen_info.curr_tab)
            {
                HistoryReplace(SCR_ID_IMPS_CHAT, SCR_ID_IMPS_CONT, mmi_imps_pre_entry_cont);
            }
            /* else do nothing */
        }
        else if (scr_id == SCR_ID_IMPS_CONT)
        {
            /* do nothing */
        }
        else if (IsScreenPresent(SCR_ID_IMPS_CHAT)) /* chat screen is in history */
        {
            /* if the room is current chatting room -- go to contact list screen */
            if (room->tab_index == imps_p->gen_info.curr_tab)
            {
                HistoryReplace(SCR_ID_IMPS_CHAT, SCR_ID_IMPS_CONT, mmi_imps_pre_entry_cont);
                mmi_imps_util_del_up_to_screen(SCR_ID_IMPS_CONT);
            }
            /* else do nothing */
        }

        /* remove the tab of the chat room */
        if (room->tab_index == imps_p->gen_info.curr_tab)
        {
            mmi_imps_tab_del(room->tab_index, 0);
        }
        else
        {
            mmi_imps_tab_del(room->tab_index, imps_p->gen_info.curr_tab);
        }

        /* clear chat room */
        mmi_imps_room_reset_cntx(room);

        imps_p->room_info.no_rooms--;

        mmi_imps_util_update_status_icon();
    }
    else
    {
        /* do nothing */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_group_change_ind
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_GROUP_CHANGE_NOTIFY_IND
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_group_change_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_group_change_notify_ind_struct *ind = (mmi_imps_group_change_notify_ind_struct*) msg;
    mmi_imps_room_struct *room;
    imps_entity_struct *entity;
    S32 i, room_id;
    FS_HANDLE fileHandle = 0;
    S16 *ucs2_folder = NULL;
    U32 len;
    MMI_BOOL bChange = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* finding the chat room */
    for (room_id = 0; room_id < IMPS_MAX_NO_ROOM; room_id++)
    {
        room = &imps_p->room_info.room_list[room_id];

        /* if the room is an opened group chat room */
        if (room->is_used && (room->type == IMPS_ROOM_TYPE_GROUP_CREATE || room->type == IMPS_ROOM_TYPE_GROUP_JOIN))
        {
            if (mmi_imps_util_is_id_same((S8*) room->room_id, (S8*) ind->group_id))   /* chat room exists */
            {
                break;
            }
        }
    }

    /* the group is not in the list */
    if (room_id == IMPS_MAX_NO_ROOM)
    {
        return;
    }    

    /* change of name */
    if (ind->changed_props & IMPS_GROUP_NAME_CHANGED)
    {
        mmi_ucs2cpy((S8*) room->room_name, (S8*) ind->group_name);
    }

    if (ind->changed_props & IMPS_GROUP_TOPIC_CHANGED)
    {
        mmi_ucs2cpy((S8*) room->room_topic, (S8*) ind->group_topic);
    }

    /* change of access type */
    if (ind->changed_props & IMPS_GROUP_ACCESS_TYPE_CHANGED)
    {
        room->access_type = (U8) ind->group_access_type;
    }

    /* change privilege level */
    if (ind->changed_props & IMPS_USER_PRIVILEGE_LEVEL_CHANGED)
    {
        room->pri_level = (U8) ind->pri_level;
    }

    ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    entity = (imps_entity_struct*) OslMalloc(sizeof(imps_entity_struct));
    
    /* process left users */
    if (ind->left_user_list.entity_num != 0)
    {
        mmi_imps_util_get_filename_from_fileindex(ind->left_user_list.entity_list_file_index, IMPS_LIST_FILE_LEFT, (S8*) ucs2_folder);
        fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);
        if (fileHandle > 0)
        {                
            bChange = MMI_TRUE;
            for (i = 0; i < (S32) ind->left_user_list.entity_num; i++)
            {
                FS_Read(fileHandle, (void*)entity, sizeof(imps_entity_struct), &len);        
               
                /* display left user */
                mmi_imps_chat_disp_user_change_msg(room_id, entity, IMPS_ROOM_MEMBER_LEFT);  
            }        

          FS_Close(fileHandle);
          FS_Delete((U16*) ucs2_folder);
        }
    }

    /* process joined users */
    if (ind->joined_user_list.entity_num != 0)
    {
        mmi_imps_util_get_filename_from_fileindex(ind->joined_user_list.entity_list_file_index, IMPS_LIST_FILE_JOINED, (S8*) ucs2_folder);
        fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);
        if (fileHandle > 0)
        {                        
            bChange = MMI_TRUE;
            for (i = 0; i < (S32) ind->joined_user_list.entity_num; i++)
            {
                FS_Read(fileHandle, (void*)entity, sizeof(imps_entity_struct), &len); 
                
    		    /* display joined user */
    			mmi_imps_chat_disp_user_change_msg(room_id, entity, IMPS_ROOM_MEMBER_JOINED);
            }
  
            FS_Close(fileHandle);
            FS_Delete((U16*) ucs2_folder);
        }   
    }

    OslMfree(ucs2_folder);
    OslMfree(entity);

    /* refresh screen */
    if (bChange)
    {
        mmi_imps_util_play_tone(IMPS_MSG_TONE);
        mmi_imps_tab_update_event(room, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_invite_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_INVITE_REQ to PS
 * PARAMETERS
 *  id      [IN]        Index of session
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_invite_req(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_req_struct *req;
    mmi_imps_room_struct *room;
    mmi_imps_cont_struct *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmi_imps_invite_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_invite_req_struct));
    IMPS_MEMSET(req, 0, mmi_imps_invite_req_struct);

    room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    cont = &imps_p->cont_info.cont_list[imps_p->invite_info.invite_cand_list[imps_p->invite_info.curr_sel_cont]];

    req->invite_type = IMPS_INVITE_TYPE_GROUP;

    strcpy((S8*) req->group_id, (S8*) room->room_id);
    strcpy((S8*) req->recipient_id, (S8*) cont->id);

    if (mmi_ucs2strlen((S8*) imps_p->path_buff))
    {
        mmi_ucs2cpy((S8*) req->invite_note, (S8*) imps_p->path_buff);
    }

    if (mmi_ucs2strlen((S8*) room->sname))
    {
        mmi_ucs2cpy((S8*) req->self_sname, (S8*) room->sname);
    }

    req->invite_id = id;

    /* use protocol default timeout */
    req->invite_timeout = 0;

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_INVITE_REQ, req, NULL);

    /* restore current action */
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_invite_rsp
 * DESCRIPTION
 *  Response handler for MSG_ID_MMI_IMPS_INVITE_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_invite_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_rsp_struct *rsp = (mmi_imps_invite_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_start(rsp->result, rsp->invite_id);

    /* restore current action */
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_invite_reply_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_INVITE_RES to remote server.
 * PARAMETERS
 *  accept      [IN]        Accept or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_invite_reply_req(BOOL accept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_reply_req_struct *req = OslConstructDataPtr(sizeof(mmi_imps_invite_reply_req_struct));
    mmi_imps_invite_ind_struct *invitation =
        imps_p->invite_info.invite_pending_list[imps_p->invite_info.curr_pend_invite].node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_invite_reply_req_struct);
    req->invite_type = invitation->invite_type;
    strcpy((S8*) req->invite_id, (S8*) invitation->invite_id);
    req->acceptance = accept;
    req->self_sname[0] = 0; /* set to NULL first */
    req->response_note[0] = 0;

    strcpy((S8*) req->recipient.id, (S8*) invitation->sender.id);
    req->recipient.entity_type = invitation->sender.entity_type;
    mmi_ucs2cpy((S8*) req->recipient.sname, (S8*) invitation->sender.sname);
    strcpy((S8*) req->group_id, (S8*) invitation->group_id);

    if (accept)
    {
        mmi_imps_join_inline_struct *inline_join = imps_p->room_info.inline_join;

        mmi_ucs2cpy((S8*) req->self_sname, (S8*) inline_join->sname);
        req->user_auto_join_group = TRUE;
        req->user_show_id = (MMI_BOOL) inline_join->disclose_id;
        SetProtocolEventHandler(mmi_imps_ps_invite_reply_rsp, MSG_ID_MMI_IMPS_INVITE_REPLY_RSP);
    }
    else
    {
        SetProtocolEventHandler(mmi_imps_ps_reject_invite_reply_rsp, MSG_ID_MMI_IMPS_INVITE_REPLY_RSP);
    }

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_INVITE_REPLY_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_invite_reply_rsp
 * DESCRIPTION
 *  Response handler for MSG_ID_MMI_IMPS_INVITE_REPLY_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_invite_reply_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* logout or during logout period */
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_join_room_finished(msg);

    /* release the holding local parameter */
    mmi_imps_invite_ind_release_node();

    /* check pending invitation */
    if (mmi_imps_util_is_in_imps() && !IsScreenPresent(SCR_ID_IMPS_INVITATION_IND))
    {
        mmi_imps_check_pending_invite();
    }      

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_reject_invite_reply_rsp
 * DESCRIPTION
 *  Response handler for MSG_ID_MMI_IMPS_INVITE_REPLY_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_reject_invite_reply_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_disp_popup_done();
    
    /* restore current action */
    imps_p->gen_info.curr_action = 0;    

    if (IsScreenPresent(SCR_ID_IMPS_CHAT))
    {
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT);
    }
    else
    {
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
    }

    /* release the holding local parameter */
    mmi_imps_invite_ind_release_node();

    /* check pending invitation */
    if (mmi_imps_util_is_in_imps() && !IsScreenPresent(SCR_ID_IMPS_INVITATION_IND))
    {
        mmi_imps_check_pending_invite();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_invite_response_ind
 * DESCRIPTION
 *  Response handler for MSG_ID_MMI_IMPS_INVITE_RESPONSE_IND
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_invite_response_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_response_ind_struct *rsp = (mmi_imps_invite_response_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* logout or during logout period */
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    /* call response handler for the user */
    mmi_imps_invite_finish((BOOL) rsp->acceptance, (S32) rsp->invite_id, &rsp->sender, (U16*) rsp->response_note);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_invite_ind
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_INVITE_IND
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_invite_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_info_struct *invite = &imps_p->invite_info;
    mmi_imps_invite_ind_struct *invite_ind = (mmi_imps_invite_ind_struct*) msg;
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* logout or during logout period */
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    /* check if the user has joined the room of invitation */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        /* if the user has already joined the chat room */
        if (mmi_imps_util_is_id_same((S8*) invite_ind->group_id, (S8*) imps_p->room_info.room_list[i].room_id))
        {
            return;
        }
    }

    i = (S32) invite->curr_pend_invite;

    /* store the invitation */
    for (j = 0; j < IMPS_MAX_PEND_INVITATION; j++, i++)
    {
        if (invite->invite_pending_list[i].node == NULL)    /* empty slot */
        {
            invite->invite_pending_list[i].node = msg;
            hold_local_para((local_para_struct*) msg);
            DTGetRTCTime(&invite->invite_pending_list[i].time_stamp);
            break;
        }

        /* to maintain circular queue */
        if (i == IMPS_MAX_PEND_INVITATION)
        {
            i = 0;
        }
    }

    if (j < IMPS_MAX_PEND_INVITATION)   /* some empty slot here */
    {
        U16 curr_scr = GetActiveScreenId();

        if (mmi_imps_util_is_in_imps() && !IsScreenPresent(SCR_ID_IMPS_INVITATION_IND))
        {
            mmi_imps_check_pending_invite();
        }
        else
        {
            invite->reminder_flag = TRUE;
            if (mmi_imps_util_is_on_idle())
            {
                mmi_imps_entry_invite_reminder();
            }
            else if (curr_scr != SCR_ID_IMPS_INVITATION_IND)    /* to prevent unnecessary popup */
            {
                mmi_imps_util_disp_warning_popup(STR_ID_IMPS_NEW_INVITATION);
            }
        }
    }
}

/* added by keneng start */


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_group_member_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_GET_GROUP_MEMBER_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_group_member_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_group_member_req_struct *req =
        (mmi_imps_get_group_member_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_get_group_member_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_get_group_member_req_struct);

    strcpy((S8*) req->group_id, (S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].room_id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_GROUP_MEMBER_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_group_member_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_GET_GROUP_MEMBER_RSP
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_group_member_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_group_member_rsp_struct *rsp = (mmi_imps_get_group_member_rsp_struct*) msg;
    imps_entity_list_struct *member = NULL;
    U8 count;
	S16 *ucs2_folder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        imps_p->room_info.member = OslMalloc(sizeof(imps_entity_list_struct));        
        member = imps_p->room_info.member;
        memset(member, 0, sizeof(imps_entity_list_struct));
        ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        
        /* keneng : update member list */
        member->entity_count = 0;
        if (member->entity_count < IMPS_MAX_ENTITY_NUMBER && rsp->adm_list.entity_num > 0)
        {            
            mmi_imps_util_get_filename_from_fileindex(rsp->adm_list.entity_list_file_index, IMPS_LIST_FILE_ADM, (S8*) ucs2_folder);
            count = IMPS_MAX_ENTITY_NUMBER > rsp->adm_list.entity_num 
                        ? rsp->adm_list.entity_num 
                        : IMPS_MAX_ENTITY_NUMBER;
            mmi_imps_get_member_from_file(
                        (S16*) ucs2_folder,
                        (U8) count,
                        IMPS_PRI_LEVEL_ADM);
        }

        if (member->entity_count < IMPS_MAX_ENTITY_NUMBER && rsp->mod_list.entity_num > 0)
        {
            mmi_imps_util_get_filename_from_fileindex(rsp->mod_list.entity_list_file_index, IMPS_LIST_FILE_MOD, (S8*) ucs2_folder);
            count = IMPS_MAX_ENTITY_NUMBER > (rsp->adm_list.entity_num + rsp->mod_list.entity_num)
                        ? rsp->mod_list.entity_num 
                        : (IMPS_MAX_ENTITY_NUMBER - rsp->adm_list.entity_num);
            mmi_imps_get_member_from_file(
                        (S16*) ucs2_folder,
                        (U8) count,
                        IMPS_PRI_LEVEL_MOD);
        }

        if (member->entity_count < IMPS_MAX_ENTITY_NUMBER && rsp->user_list.entity_num > 0)
        {
            mmi_imps_util_get_filename_from_fileindex(rsp->user_list.entity_list_file_index, IMPS_LIST_FILE_USER, (S8*) ucs2_folder);
            count = IMPS_MAX_ENTITY_NUMBER > (rsp->adm_list.entity_num + rsp->mod_list.entity_num + rsp->user_list.entity_num) 
                        ? rsp->user_list.entity_num 
                        : (IMPS_MAX_ENTITY_NUMBER - rsp->adm_list.entity_num - rsp->mod_list.entity_num);
            mmi_imps_get_member_from_file(
                        (S16*) ucs2_folder,
                        (U8) count,
                        IMPS_PRI_LEVEL_USER);
        }

        OslMfree(ucs2_folder);
    }
    mmi_imps_get_member_done(rsp->result);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_get_group_member_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_ABORT_GET_GROUP_MEMBER_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_get_group_member_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ABORT_GET_GROUP_MEMBER_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_add_group_member_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_ADD_GROUP_MEMBER_REQ to PS
 * PARAMETERS
 *  user_list       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_add_group_member_req(void *user_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_add_group_member_req_struct *req =
        (mmi_imps_add_group_member_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_add_group_member_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_add_group_member_req_struct);

    strcpy((S8*) req->group_id, (S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].room_id);
    memcpy(&req->user_list, user_list, sizeof(imps_entity_list_struct));

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ADD_GROUP_MEMBER_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_add_group_member_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_ADD_GROUP_MEMBER_RSP
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_add_group_member_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_add_group_member_rsp_struct *rsp = (mmi_imps_add_group_member_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_add_member_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_remove_group_member_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_REMOVE_GROUP_MEMBER_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_remove_group_member_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_remove_group_member_req_struct *req =
        (mmi_imps_remove_group_member_req_struct*)
        OslConstructDataPtr(sizeof(mmi_imps_remove_group_member_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_remove_group_member_req_struct);
    
    strcpy((S8*) req->group_id, (S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].room_id);
    req->user_list.entity_count = 1;
    req->user_list.entity[0].entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy((S8*) req->user_list.entity[0].id, (S8*) imps_p->room_info.member->entity[imps_p->room_info.curr_sel_user].id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_REMOVE_GROUP_MEMBER_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_remove_group_member_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_REMOVE_GROUP_MEMBER_RSP
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_remove_group_member_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_remove_group_member_rsp_struct *rsp = (mmi_imps_remove_group_member_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_del_member_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_joined_user_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_GET_JOINED_USER_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_joined_user_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_joined_user_req_struct *req =
        (mmi_imps_get_joined_user_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_get_joined_user_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_get_joined_user_req_struct);

    strcpy((S8*) req->group_id, (S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].room_id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_JOINED_USER_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_joined_user_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_GET_JOINED_USER_RSP
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_joined_user_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_joined_user_rsp_struct *rsp = (mmi_imps_get_joined_user_rsp_struct*) msg;
    imps_entity_list_struct *joined_user = NULL;
    U8 count = 0;
	S16 *ucs2_folder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        imps_p->room_info.joined_user = OslMalloc(sizeof(imps_entity_list_struct));
        joined_user = imps_p->room_info.joined_user;
        memset(joined_user, 0, sizeof(imps_entity_list_struct));
            
        /* parse the data */
        joined_user->entity_count = 0;

        ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

        if (joined_user->entity_count < IMPS_MAX_ENTITY_NUMBER && rsp->adm_map_list.entity_num > 0)
        {
            mmi_imps_util_get_filename_from_fileindex(rsp->adm_map_list.entity_list_file_index, IMPS_LIST_FILE_ADM, (S8*) ucs2_folder);
            count = IMPS_MAX_ENTITY_NUMBER > rsp->adm_map_list.entity_num
                    ? rsp->adm_map_list.entity_num : IMPS_MAX_ENTITY_NUMBER;
            mmi_imps_get_joined_from_file((S16*) ucs2_folder, (U8) count);
        }

        if (joined_user->entity_count < IMPS_MAX_ENTITY_NUMBER && rsp->mod_map_list.entity_num > 0)
        {
            mmi_imps_util_get_filename_from_fileindex(rsp->adm_map_list.entity_list_file_index, IMPS_LIST_FILE_MOD, (S8*) ucs2_folder);
            count = IMPS_MAX_ENTITY_NUMBER > (rsp->adm_map_list.entity_num + rsp->mod_map_list.entity_num)
                    ? rsp->mod_map_list.entity_num : (IMPS_MAX_ENTITY_NUMBER - rsp->adm_map_list.entity_num);
            mmi_imps_get_joined_from_file((S16*) ucs2_folder, (U8) count);
        }

        if (joined_user->entity_count < IMPS_MAX_ENTITY_NUMBER && rsp->user_map_list.entity_num > 0)
        {
            mmi_imps_util_get_filename_from_fileindex(rsp->adm_map_list.entity_list_file_index, IMPS_LIST_FILE_USER, (S8*) ucs2_folder);
            count =
                IMPS_MAX_ENTITY_NUMBER >
                    (rsp->adm_map_list.entity_num + rsp->mod_map_list.entity_num +
                     rsp->user_map_list.entity_num) ? rsp->user_map_list.entity_num : (IMPS_MAX_ENTITY_NUMBER -
                                                                                       rsp->adm_map_list.entity_num -
                                                                                       rsp->mod_map_list.entity_num);
            mmi_imps_get_joined_from_file((S16*) ucs2_folder, (U8) count);
        }

        OslMfree(ucs2_folder);

        if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)        /* current is progressing screen */
        {
            mmi_imps_entry_chat_list_joined();
        }
        else
        {
            if (IsScreenPresent(SCR_ID_IMPS_PROGRESS))
            {
                HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_CHAT_JOINED, mmi_imps_entry_chat_list_joined);
            }
            else
            {
                mmi_imps_free_list_joined_buff();
            }
        }
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(rsp->result));
    }

    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_get_joined_user_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_ABORT_GET_JOINED_USER_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_get_joined_user_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ABORT_GET_JOINED_USER_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_get_joined_user_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_ABORT_GET_JOINED_USER_RSP
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_get_joined_user_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_get_joined_user_abort_finish();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_member_access_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_MEMBER_ACCESS_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_member_access_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_member_access_req_struct *req =
        (mmi_imps_member_access_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_member_access_req_struct));
    imps_entity_list_struct *member = imps_p->room_info.member;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_member_access_req_struct);

    strcpy((S8*) req->group_id, (S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].room_id);
    if (member->entity[imps_p->room_info.curr_sel_user].entity_type == IMPS_PRI_LEVEL_MOD)
    {
        req->pri_level = IMPS_PRI_LEVEL_USER;
    }
    else if (member->entity[imps_p->room_info.curr_sel_user].entity_type == IMPS_PRI_LEVEL_USER)
    {
        req->pri_level = IMPS_PRI_LEVEL_MOD;
    }

    req->user_list.entity_count = 1;
    req->user_list.entity[0].entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy((S8*) req->user_list.entity[0].id, (S8*) member->entity[imps_p->room_info.curr_sel_user].id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_MEMBER_ACCESS_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_member_access_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_MEMBER_ACCESS_RSP
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_member_access_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_member_access_rsp_struct *rsp = (mmi_imps_member_access_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_chat_set_mod_user_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_reject_group_user_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_REJECT_GROUP_USER_REQ to PS
 * PARAMETERS
 *  is_add          [IN]        
 *  user_list       [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_reject_group_user_req(BOOL is_add, void *user_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_reject_group_user_req_struct *req =
        (mmi_imps_reject_group_user_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_reject_group_user_req_struct));
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_reject_group_user_req_struct);

    strcpy((S8*) req->group_id, (S8*) room->room_id);
    req->is_add = is_add;
    memcpy(&req->user_list, user_list, sizeof(imps_entity_list_struct));

    /* get rejected user list */
    if (req->user_list.entity_count == 0)
    {
        SetProtocolEventHandler(mmi_imps_ps_get_reject_group_user_rsp, MSG_ID_MMI_IMPS_REJECT_GROUP_USER_RSP);
    }
    else if(is_add)
    {
        SetProtocolEventHandler(mmi_imps_ps_add_reject_group_user_rsp, MSG_ID_MMI_IMPS_REJECT_GROUP_USER_RSP);
    }
    else
    {
        SetProtocolEventHandler(mmi_imps_ps_delete_reject_group_user_rsp, MSG_ID_MMI_IMPS_REJECT_GROUP_USER_RSP);
    }

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_REJECT_GROUP_USER_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_add_reject_group_user_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_REJECT_GROUP_USER_RSP (add)
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_add_reject_group_user_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_reject_group_user_rsp_struct *rsp = (mmi_imps_reject_group_user_rsp_struct*) msg;
    imps_entity_struct *entity = NULL;

  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        if (imps_p->room_info.joined_user != NULL)
        {
            entity = &imps_p->room_info.joined_user->entity[imps_p->room_info.curr_sel_user];
        /* update joined list */
        entity->id[0] = 0;
        entity->sname[0] = 0;
        }
    }

    mmi_imps_add_reject_user_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_delete_reject_group_user_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_REJECT_GROUP_USER_RSP (delete)
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_delete_reject_group_user_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_reject_group_user_rsp_struct *rsp = (mmi_imps_reject_group_user_rsp_struct*) msg;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;
    mmi_imps_delete_reject_user_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_reject_group_user_rsp
 * DESCRIPTION
 *  handler of MSG_ID_MMI_IMPS_REJECT_GROUP_USER_RSP (get)
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ps_get_reject_group_user_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_reject_group_user_rsp_struct *rsp = (mmi_imps_reject_group_user_rsp_struct*) msg;
	S16 *oldname = NULL;
	S16 *newname = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        S32 ret;

        oldname = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        newname = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_imps_util_file_path((S8*) newname, (S8*) IMPS_REJECTED_USER, imps_p->chat_info.curr_room);
        mmi_imps_util_get_filename_from_fileindex(rsp->user_list.entity_list_file_index, IMPS_LIST_FILE_USER, (S8*) oldname);

        FS_Delete((U16*) newname);
        ret = FS_Move((U16*) oldname, (U16*) newname, FS_MOVE_KILL, NULL, NULL, 0); 

        OslMfree(oldname);
        OslMfree(newname); 
        
        if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)        /* current is progressing screen */
        {
            mmi_imps_entry_chat_list_rejected();
        }
        else
        {
            if (IsScreenPresent(SCR_ID_IMPS_PROGRESS))
            {
                HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_CHAT_JOINED, mmi_imps_entry_chat_list_rejected);
            }
            else
            {
                mmi_imps_free_list_rejected_buff();
            }
        }
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(rsp->result));
    }

    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_get_rejected_user_req
 * DESCRIPTION
 *  send MSG_ID_MMI_IMPS_ABORT_GET_REJECTED_USER_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_get_rejected_user_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ABORT_GET_REJECTED_USER_REQ, NULL, NULL);
}

/* added by keneng end */




#define MISC_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_server_disconn_ind
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_DISCONNECT_IND
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_server_disconn_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL cont_scr;
    BOOL chat_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset action_id */
    imps_p->gen_info.curr_action = 0;

    if (imps_p->gen_info.is_login == TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_IMPS_SERVER_DISCONNECT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);

        cont_scr = IsScreenPresent(SCR_ID_IMPS_CONT);
        chat_scr = IsScreenPresent(SCR_ID_IMPS_CHAT);

        if (cont_scr)   /* contact list screen */
        {
            HistoryReplace(SCR_ID_IMPS_CONT, SCR_ID_IMPS_MAIN, mmi_imps_entry_main);
            mmi_imps_util_del_up_to_screen(SCR_ID_IMPS_MAIN);
        }
        else if (chat_scr)  /* chat screen */
        {
            HistoryReplace(SCR_ID_IMPS_CHAT, SCR_ID_IMPS_MAIN, mmi_imps_entry_main);
            mmi_imps_util_del_up_to_screen(SCR_ID_IMPS_MAIN);
        }
        else
        {
            /* not in IMPS applpication, do nothing */
        }
    }
    mmi_imps_util_free_buff_when_logout();
    mmi_imps_reset_cntx();
    mmi_imps_util_update_login_icon();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_ready_ind
 * DESCRIPTION
 *  Handler of IMPS task ready indication
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_ready_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.ps_ready_state |= IMPS_LOGIN_PS_READY;
    /* because WiFi does not have and indication for now, we can not prevent 
       the user to use IMPS without RAC ready, because WiFi can be used. 
       A termporary solution would be add the RAC ready when PS ready.
    */
/* #ifndef __MTK_TARGET__ */
    imps_p->gen_info.ps_ready_state |= IMPS_LOGIN_RAC_READY;
/* #endif  */
    mmi_imps_auto_login();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_subs_notify_req
 * DESCRIPTION
 *  Subscribe notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_subs_notify_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_subs_notify_req_struct *req =
        (mmi_imps_subs_notify_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_subs_notify_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_subs_notify_req_struct);

    req->subscribe_notif = 0;  /* subscribe all */

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_SUBS_NOTIFY_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_subs_notify_rsp
 * DESCRIPTION
 *  Response handler of subscribe notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_subs_notify_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_subs_notify_rsp_struct *rsp = (mmi_imps_subs_notify_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.curr_action = 0;
    mmi_imps_subs_notify_finished(rsp->result);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_unsubs_notify_req
 * DESCRIPTION
 *  Unsubscribe notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_unsubs_notify_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_unsubs_notify_req_struct *req =
        (mmi_imps_unsubs_notify_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_unsubs_notify_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_unsubs_notify_req_struct);

    req->unsubscribe_notif = 0;  /* unsubscribe all */

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_UNSUBS_NOTIFY_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_unsubs_notify_rsp
 * DESCRIPTION
 *  Response handler of unsubscribe notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_imps_ps_unsubs_notify_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_unsubs_notify_rsp_struct *rsp = (mmi_imps_unsubs_notify_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.curr_action = 0;      
    mmi_imps_unsubs_notify_finished(rsp->result);       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_notify_request_ind
 * DESCRIPTION
 *  Indication handler of notify request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_notify_request_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_notify_ind_struct *ind = (mmi_imps_notify_ind_struct*) msg;
    U16 disp_buff[IMPS_MAX_CONTENT_LEN], temp_buff[IMPS_MAX_CONTENT_LEN];
    mmi_imps_presence_auth_ind_struct *auth_ind = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    disp_buff[0] = 0;
    switch(ind->notif_type)
    {
        case IMPS_NOTIFICATION_TYPE_ATCL:
            /* mmi_imps_entry_notify_ATCL((void*) ind->notif_element.user_list); */
            if (ind->notif_element.user_list.entity[0].entity_type == IMPS_ENTITY_TYPE_SCREEN_NAME)  /* screen name present */
            {
                mmi_ucs2cpy((S8*) disp_buff, (S8*) ind->notif_element.user_list.entity[0].sname);
            }
            else
            {
                mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.user_list.entity[0].id);
                mmi_ucs2cpy((S8*) disp_buff, (S8*) temp_buff);
            }
            mmi_ucs2cat((S8*) disp_buff, (S8*) L" ");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_ADD_TO_ANOTHER_LIST));            
            break;
            
        case IMPS_NOTIFICATION_TYPE_AC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_AUTHORIZATION_CHANGED));
            break;
            
        case IMPS_NOTIFICATION_TYPE_ANC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_AUTHORIZATION_NEEDED_CONTACTLIST));
            break;
            
        case IMPS_NOTIFICATION_TYPE_AND:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_AUTHORIZATION_NEEDED_DEFAULTLIST));
            break;

        case IMPS_NOTIFICATION_TYPE_ANU:
            /* mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_AUTHORIZATION_NEEDED_USER)); */
            auth_ind = OslMalloc(sizeof(mmi_imps_presence_auth_ind_struct));
            memset(auth_ind, 0, sizeof(mmi_imps_presence_auth_ind_struct));
            auth_ind->attr_list = ind->notif_element.pa_notif.pa_value;
            memcpy((void*) &auth_ind->auth_user, (void*) &ind->notif_element.pa_notif.pa_subscriber_list.entity[0], sizeof(imps_entity_struct));
            
            mmi_imps_ps_pa_auth_ind((void*) auth_ind);
            
            OslMfree(auth_ind);
            break;

        case IMPS_NOTIFICATION_TYPE_BLC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_BLOCK_LIST_CHANGED));
            mmi_imps_ps_get_block_list_req();
            break;

        case IMPS_NOTIFICATION_TYPE_BLUC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_BLOCK_LIST_USAGECHANGE));
            break;

        case IMPS_NOTIFICATION_TYPE_CLCR:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_CONTACT_LIST_CREATED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.contact_list_id_list.entity[0].id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);            
            break;

        case IMPS_NOTIFICATION_TYPE_CLC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_CONTACT_LIST_CHANGED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.contact_list_id_list.entity[0].id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);
            break;

        case IMPS_NOTIFICATION_TYPE_CLD:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_CONTACT_LIST_DELETED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.contact_list_id_list.entity[0].id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);          
            break;

        case IMPS_NOTIFICATION_TYPE_GLC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GRANT_LIST_CHANGED));
            mmi_imps_ps_get_block_list_req();
            break;

        case IMPS_NOTIFICATION_TYPE_GLUC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GRANT_LIST_USAGECHANGE));
            break;

        case IMPS_NOTIFICATION_TYPE_GC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GROUP_CREATED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.group_id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);              
            break;

        case IMPS_NOTIFICATION_TYPE_GD:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GROUP_DELETED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.group_id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);            
            break;

        case IMPS_NOTIFICATION_TYPE_GMAU:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GROUP_MEMBERACCESS_UPDATED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.group_id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);                
            break;

        case IMPS_NOTIFICATION_TYPE_GMG:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GROUP_MEMBERSHIP_GRANTED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.group_id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);                
            break;

        case IMPS_NOTIFICATION_TYPE_GMR:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GROUP_MEMBERSHIP_REVOKED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.group_id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);                
            break;

        case IMPS_NOTIFICATION_TYPE_GMU:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GROUP_MEMBER_UPDATED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.group_id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);                      
            break;

        case IMPS_NOTIFICATION_TYPE_GR:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_GROUP_REMOVED));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L"\n");
            mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NAME));
            mmi_ucs2cat((S8*) disp_buff, (S8*) L":");
            mmi_asc_to_ucs2((S8*) temp_buff, (S8*) ind->notif_element.group_id);
            mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff);            
            break;

        case IMPS_NOTIFICATION_TYPE_IA:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_INVITATION_ACCEPTED));
            break;

        case IMPS_NOTIFICATION_TYPE_IC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_INVITATION_CANCELLED));
            break;

        case IMPS_NOTIFICATION_TYPE_IR:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_INVITATION_REJECTED));
            break;

        case IMPS_NOTIFICATION_TYPE_OEU:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_ONLINEETEMHANDLING_UPDATED));
            break;

        case IMPS_NOTIFICATION_TYPE_PPU:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_PUBLIC_PROFILE_UPDATED));
            break;

        case IMPS_NOTIFICATION_TYPE_SPA:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_SESSION_PRIORITY_ADJUSTED));
            break;

        case IMPS_NOTIFICATION_TYPE_UIC:
            mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_USER_ID_CHANGED));
            break;

        default:
            break;

    }
    DisplayPopup((U8*) disp_buff, 0, 1, UI_POPUP_NOTIFYDURATION_TIME * 10, (U8) GENERAL_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_system_message_ind
 * DESCRIPTION
 *  Indication handler of system message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_ps_system_message_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_system_message_ind_struct *ind = (mmi_imps_system_message_ind_struct*) msg;
	S16 *ucs2_folder = NULL;       
    FS_HANDLE fileHandle0 = 0;
    FS_HANDLE fileHandle1 = 0;
	U32 len;
	void *messages = NULL;
    U32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_ABORT_LOGIN_REQ)
    {
        return;
    }
    
    /* check if system message empty */
    if (ind->sm_count > 0)
    {
        if (imps_p->system_message == NULL)
        {
            imps_p->system_message = (mmi_imps_system_message_struct*) OslMalloc(sizeof(mmi_imps_system_message_struct));
            imps_p->system_message->curr_index = 0;
            imps_p->system_message->total = ind->sm_count;
            imps_p->system_message->sel_option = 0;
            imps_p->system_message->curr_sm_id[0]= 0;
            imps_p->system_message->verification_key[0]= 0;
            imps_p->system_message->is_give_up = FALSE;
            imps_p->system_message->buff = NULL;
            mmi_imps_util_get_filename_from_fileindex(ind->sm_list_file_index, IMPS_LIST_FILE_SYSTEM_MESSAGE, (S8*) imps_p->system_message->sm_path); 
        }
        else
        {
            /* save system message info to current process struct */
            ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
            messages = OslMalloc(sizeof(imps_system_message_struct));        
            mmi_imps_util_get_filename_from_fileindex(ind->sm_list_file_index, IMPS_LIST_FILE_SYSTEM_MESSAGE, (S8*) ucs2_folder);        
            fileHandle0 = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);
            fileHandle1 = FS_Open((U16*) imps_p->system_message->sm_path, FS_READ_WRITE | FS_CREATE);     
            
            if (fileHandle0 > 0 && fileHandle1 > 0)
            {
                FS_Seek(fileHandle1, 0, FS_FILE_END);
                for (i = 0; i < ind->sm_count; i++)
                {
                    FS_Read(fileHandle0, (void*) messages, sizeof(imps_system_message_struct), &len);
                    FS_Write(fileHandle1, (void*) messages, sizeof(imps_system_message_struct), &len);
                    imps_p->system_message->total++;
                }
            }
            FS_Close(fileHandle0);     
            FS_Delete((U16*) ucs2_folder);   
            OslMfree(ucs2_folder);
            FS_Close(fileHandle1);
            OslMfree(messages);  
        }

        mmi_imps_check_system_message();        
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_system_message_user_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_SYSTEM_MSG_RES to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_ps_system_message_user_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_system_message_user_req_struct *req =
        (mmi_imps_system_message_user_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_system_message_user_req_struct));        

    mmi_imps_system_message_struct *sm_info = imps_p->system_message;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_system_message_user_req_struct);
    
    strcpy((S8*) req->sm_id, (S8*) sm_info->curr_sm_id);
    req->need_rsp = sm_info->need_rsp;
    if (sm_info->option_count > 0)
    {
        req->chosen_option_p = TRUE;
        req->chosen_option = sm_info->sel_option;
    }

    if (mmi_ucs2strlen((S8*) sm_info->verification) > 0 && sm_info->verification_type == 0)
    {
        mmi_ucs2cpy((S8*) req->verification_key, (S8*) sm_info->verification_key);
    }

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_SYSTEM_MSG_USER_REQ, req, NULL);
    if (imps_p->gen_info.is_login == FALSE)
    {
        imps_p->gen_info.curr_action = MSG_ID_MMI_IMPS_LOGIN_REQ;  
    }
    else
    {
        imps_p->gen_info.curr_action = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_system_message_user_rsp
 * DESCRIPTION
 *  Response handler of system message user request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_ps_system_message_user_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_system_message_user_rsp_struct *rsp = (mmi_imps_system_message_user_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result == IMPS_OK)
    {
        mmi_imps_util_disp_popup_done();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_dl_large_file_req
 * DESCRIPTION
 *  Send download large file request to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_ps_dl_large_file_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_dl_file_req_struct *req =
        (mmi_imps_dl_file_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_dl_file_req_struct));        
    
    S8 *temp_buff = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_dl_file_req_struct);
    
    temp_buff = OslMalloc(FMGR_MAX_PATH_LEN + 1);
    mmi_ucs2_to_asc((S8*) req->store_path, (S8*) IMPS_DEFAULT_FILE_PATH);
    sprintf(temp_buff, "%c:\\%s%s%d.", IMPS_PUBLIC_DRV, (S8*) req->store_path, "temp", imps_p->gen_info.seq_no);
    mmi_asc_to_ucs2((S8*) req->store_path, (S8*) temp_buff);
    mmi_ucs2cat((S8*) req->store_path, (S8*) mmi_fmgr_extract_file_name((S8*) imps_p->path_buff));
    OslMfree(temp_buff);

    strcpy((S8*) req->content_url, (S8*) imps_p->path_buff);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_DL_FILE_REQ, req, NULL);
    imps_p->gen_info.curr_action = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_dl_large_file_rsp
 * DESCRIPTION
 *  Response handler of download large file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_ps_dl_large_file_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_dl_file_rsp_struct *rsp = (mmi_imps_dl_file_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result == IMPS_OK)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_RECEIVE_NEW_FILE);
    } 
}



/*****************************************************************************
* FUNCTION
*   mmi_imps_ps_http_auth_ind
* DESCRIPTION
*   Handler to get user agent from WAP
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
void mmi_imps_ps_http_auth_ind(void *Msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_ind_struct * p = (wps_http_auth_ind_struct*) Msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->http_auth == NULL)
    {
        imps_p->http_auth = (mmi_imps_http_auth_struct*) OslMalloc(sizeof(mmi_imps_http_auth_struct));
        memset(imps_p->http_auth, 0, sizeof(mmi_imps_http_auth_struct));
    }
    imps_p->http_auth->request_id = p->request_id;
    imps_p->http_auth->channel_id = p->channel_id;    
    mmi_imps_entry_http_auth();
}


/*****************************************************************************
* FUNCTION
*   mmi_imps_ps_send_http_auth_res
* DESCRIPTION
*   get User Agent
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
void mmi_imps_ps_send_http_auth_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct *req =
        (wps_http_auth_res_struct*) OslConstructDataPtr(sizeof(wps_http_auth_res_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, wps_http_auth_res_struct);    

    req->channel_id = imps_p->http_auth->channel_id;
    req->request_id = imps_p->http_auth->request_id;
    mmi_ucs2_to_asc((S8*)req->username, (S8*)imps_p->http_auth->username);
    mmi_ucs2_to_asc((S8*)req->password, (S8*)imps_p->http_auth->password);  
    
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_HTTP_AUTH_RES, req, NULL);
    if (imps_p->gen_info.is_login == FALSE)
    {
        imps_p->gen_info.curr_action = MSG_ID_MMI_IMPS_LOGIN_REQ;  
    }   
    else
    {
        imps_p->gen_info.curr_action = 0;
    }    
}


#ifdef IMPS_FOR_OMA_ONLY


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_broadcast_msg_req
 * DESCRIPTION
 *  Braodcast message to a group
 * PARAMETERS
 *  group_index     [IN]        Index of group
 *  msg             [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_broadcast_msg_req(S32 group_index, S8 *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_send_message_req_struct *req =
        (mmi_imps_send_message_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_send_message_req_struct));
    S32 i, count;
    S32 no_cont = (S32) imps_p->cont_info.no_cont;
    U8 *group_id = &imps_p->group_info.group_list[group_index].group_id[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_send_message_req_struct);
    
    req->message_id = 0;

    mmi_ucs2cpy((S8*) req->message_content, msg);

    for (i = 0, count = 0; i < no_cont; i++)
    {
        mmi_imps_cont_struct *cont = &imps_p->cont_info.cont_list[i];

        if (mmi_imps_util_is_id_same((S8*) cont->group_id, (S8*) group_id))
        {
            req->recipients.entity[count].entity_type = IMPS_ENTITY_TYPE_USER;
            strcpy((S8*) req->recipients.entity[count].id, (S8*) cont->id);
            count++;
        }
    }

    req->recipients.entity_count = (U8) count;

    SetProtocolEventHandler(mmi_imps_ps_broadcast_msg_rsp, MSG_ID_MMI_IMPS_SEND_MESSAGE_RSP);
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_SEND_MESSAGE_REQ, req, NULL);
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_broadcast_msg_rsp
 * DESCRIPTION
 *  Response handler of braodcasting message to a group
 * PARAMETERS
 *  msg     [IN]        Message of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_broadcast_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_imps_ps_send_msg_rsp, MSG_ID_MMI_IMPS_SEND_MESSAGE_RSP);
    mmi_imps_group_broadcast_finished();
}



#endif /* IMPS_FOR_OMA_ONLY */ 

#endif /* __MMI_IMPS__ */


