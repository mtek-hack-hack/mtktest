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
 *  MMSBGSRMsg.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the message Handlings.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_MMS_BGSR_SUPPORT__

#include "ProtocolEvents.h"
#include "wap_ps_struct.h"
#include "custom_wap_config.h"
#include "xml_def.h"
#include "MMSBGSRProt.h"
#include "mmsadp.h"
#include "MMSMsgCommonProt.h"

/* TRACE */


/*******************************************************************************
 * Static Declaration
 *******************************************************************************/
/*static kal_uint32 req_id = 0;*/
/*******************************************************************************
 * Global Variable
 *******************************************************************************/

/*******************************************************************************
 * Local Function
 *******************************************************************************/
static void mmi_mms_bgsr_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);
static kal_uint32 mmi_mms_bgsr_get_request_id(void);
/*******************************************************************************
 * Global Function
 *******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_set_protocol_event_handler [NOT USED]
 * DESCRIPTION
 *  Set protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
    SetProtocolEventHandler(mmi_mms_bgsr_send_mms_ind_hdlr,
                            MSG_ID_WAP_MMA_SEND_IND);
    SetProtocolEventHandler(mmi_mms_bgsr_send_mms_rsp,
                            MSG_ID_WAP_MMA_SEND_RSP);
    SetProtocolEventHandler(mmi_mms_bgsr_abort_send_mms_rsp,
                            MSG_ID_WAP_MMA_CANCEL_SEND_RSP);
    SetProtocolEventHandler(mmi_mms_bgsr_download_mms_rsp,
                            MSG_ID_WAP_MMA_DOWNLOAD_RSP);
    SetProtocolEventHandler(mmi_mms_bgsr_download_mms_ind_hdlr,
                            MSG_ID_WAP_MMA_DOWNLOAD_IND);
    SetProtocolEventHandler(mmi_mms_bgsr_abort_download_mms_rsp,
                            MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP);
    SetProtocolEventHandler(mmi_mms_bgsr_delete_mms_rsp, 
                            MSG_ID_WAP_MMA_DELETE_RSP);
    SetProtocolEventHandler(mmi_mms_bgsr_save_mms_rsp, 
                            MSG_ID_WAP_MMA_SAVE_RSP);
*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_mem_status_req
 * DESCRIPTION
 *  Get memory status request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_get_mem_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mem_status_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_GET_MEM_STATUS_REQ ,__LINE__);

    request_id = mmi_mms_bgsr_get_request_id();

    msg_req = (wap_mma_get_mem_status_req_struct*) construct_local_para(
                    sizeof(wap_mma_get_mem_status_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;    
    msg_req->req_id = request_id;
        
    mmi_mms_bgsr_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_mem_status_rsp
 * DESCRIPTION
 *  Get memory status rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_get_mem_status_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mem_status_rsp_struct *msg_rsp = (wap_mma_get_mem_status_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(inMsg == NULL)
    {
        return;
    }

    mmi_mms_bgsr_action_fsm(MMI_MMS_BGSR_ACTION_GET_MEM_STATUS_RSP, msg_rsp, NULL);    

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_sync
 * DESCRIPTION
 *  To check whether the message is valid
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    int i;
    wap_mma_msg_is_valid_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    /* init */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_SYNC,__LINE__);

    request_id = mmi_mms_bgsr_get_request_id();
    
    msg_req = (wap_mma_msg_is_valid_req_struct*) construct_local_para(
                            sizeof(wap_mma_msg_is_valid_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;

    for( i = 0 ; i < MMI_MMS_BGSR_MAX_MSG_NUM ; i ++)
    {
        msg_req->msg_id_list[i] = mmi_mms_bgsr_msg_struct_array[i].msg_id;
    }

    mmi_mms_bgsr_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_MSG_IS_VALID_REQ,
        (oslParaType*) msg_req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_send_mms_req
 * DESCRIPTION
 *  Send MMS msg request
 * PARAMETERS
 *  msg     [IN]    the message to send
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_send_mms_req( mmi_mms_bgsr_msg_struct *msg )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_TRY_TO_SEND, __LINE__);    

    /* sanity check */
    if(msg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SEND_MMS_REQ, 0,__LINE__);    
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_SEND_MMS_REQ,msg->msg_id,__LINE__);    


    /* init */
    msg->status = MMI_MMS_BGSR_STATUS_SENDING;
    g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id = msg->msg_id;
    mmi_mms_bgsr_show_mms_status_icon(MMI_MMS_BGSR_INDICATOR_BUSY);

    request_id = mmi_mms_bgsr_get_request_id();
    
    msg_req = (wap_mma_send_req_struct*) construct_local_para(
                            sizeof(wap_mma_send_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id = msg->msg_id;
    msg_req->is_read_report = msg->is_rr;

    if ( msg->send_setting == MMI_MMS_BGSR_SETTING_SAVE_AND_SEND )
    {
        msg_req->send_and_save = KAL_TRUE;
        msg_req->box = MMA_FOLDER_OUTBOX;
    }
    else
    {
        msg_req->send_and_save = KAL_FALSE;
        msg_req->box = 0;
    }

    mmi_mms_bgsr_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_SEND_REQ,
        (oslParaType*) msg_req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_send_mms_ind_hdlr
 * DESCRIPTION
 *  Send MMS message indication handler
 * PARAMETERS
 *  inMsg       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_send_mms_ind_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_ind_struct *msg_ind = (wap_mma_send_ind_struct*) inMsg;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sanity check */
    if(inMsg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SEND_MMS_IND_HDLR, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_SEND_MMS_IND_HDLR,msg_ind->msg_id,__LINE__);

    if ( g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id != msg_ind->msg_id )
    {
        MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        mmi_mms_bgsr_echo_current_info();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_send_mms_rsp
 * DESCRIPTION
 *  Send MMS msg response
 * PARAMETERS
 *  inMsg       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_send_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *msg_rsp = (wap_mma_send_rsp_struct*) inMsg;
    U16* fail_cause = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* sanity check */
    if(inMsg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SEND_MMS_RSP, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_SEND_MMS_RSP, msg_rsp->msg_id,__LINE__);    
    
    /* if the message id is not consistent, ignore it */

    if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id != msg_rsp->msg_id)
    {
        MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        mmi_mms_bgsr_echo_current_info();
        return;
    }
    
    if (msg_rsp->result != MMA_RESULT_OK && mmi_ucs2strlen((S8*)msg_rsp->response_text))
    {
        U32 str_len = mmi_ucs2strlen((S8*)msg_rsp->response_text);

        fail_cause = kal_adm_alloc(g_mmi_mms_bgsr_context.mem_pool_id,
                                   (str_len + 1) * ENCODING_LENGTH);
        if (fail_cause != NULL)
        {
            memset(fail_cause , 0, (str_len + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy((S8*)fail_cause,  (S8*)msg_rsp->response_text, str_len);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MEMORY_NOT_ALLOCATED,__LINE__);
        }
    }
    mmi_mms_bgsr_show_mms_status_icon(MMI_MMS_BGSR_INDICATOR_IDLE);
    mmi_mms_bgsr_action_fsm(MMI_MMS_BGSR_ACTION_SEND_RSP, msg_rsp, fail_cause );    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_abort_send_mms_req
 * DESCRIPTION
 *  Abort sending MMS msg request
 * PARAMETERS
 *  msg_id          [IN]    the message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_abort_send_mms_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_send_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* sanity check */
    if(msg_id == 0)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ABORT_SEND_MMS_REQ, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_ABORT_SEND_MMS_REQ,msg_id,__LINE__);
    
    mmi_mms_bgsr_show_mms_status_icon(MMI_MMS_BGSR_INDICATOR_IDLE);    
    request_id = mmi_mms_bgsr_get_request_id();


    msg_req = (wap_mma_cancel_send_req_struct*) construct_local_para(
                    sizeof(wap_mma_cancel_send_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;    
    msg_req->req_id = request_id;
    msg_req->msg_id = msg_id;
    
    mmi_mms_bgsr_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_CANCEL_SEND_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_abort_send_mms_rsp
 * DESCRIPTION
 *  Abort MMS msg response
 * PARAMETERS   
 *  in_msg          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_abort_send_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* sanity check */
    if(in_msg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    mmi_mms_bgsr_action_fsm(MMI_MMS_BGSR_ACTION_CANCEL_SEND_RSP, msg_rsp, NULL );    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_delete_mms_req
 * DESCRIPTION
 *  Delete MMS msg request
 * PARAMETERS
 *  msg_id          [IN]    message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_delete_mms_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    request_id = mmi_mms_bgsr_get_request_id();

    if( msg_id == 0)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_DELETE_MMS_REQ, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_DELETE_MMS_REQ,msg_id,__LINE__);
    
    msg_req = (wap_mma_delete_req_struct*) construct_local_para(
                        sizeof(wap_mma_delete_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;    
    msg_req->req_id = request_id;
    msg_req->msg_id = msg_id;
    
    mmi_mms_bgsr_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_DELETE_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_delete_mms_rsp
 * DESCRIPTION
 *  Delete MMS msg response
 * PARAMETERS
 *  in_msg          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_delete_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* sanity check */
    if(in_msg == NULL)
    {
        return;
    }

    mmi_mms_bgsr_action_fsm(MMI_MMS_BGSR_ACTION_DELETE_RSP, msg_rsp, NULL);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_save_mms_req
 * DESCRIPTION
 *  Save MMS msg request
 * PARAMETERS
 *  msg_id      [IN]    message id
 *  msg_box     [IN]    message box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_save_mms_req(U32 msg_id, U16 folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(msg_id == 0)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SAVE_MMS_REQ, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_SAVE_MMS_REQ,msg_id,__LINE__);
    
    request_id = mmi_mms_bgsr_get_request_id();
    
    msg_req = (wap_mma_save_req_struct*) construct_local_para(
                            sizeof(wap_mma_save_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;    
    msg_req->req_id = request_id;
    msg_req->msg_id = msg_id;
    msg_req->box = folder;
    
    mmi_mms_bgsr_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_SAVE_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_save_mms_rsp
 * DESCRIPTION
 *  Save MMS msg response
 * PARAMETERS
 *  in_msg
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_save_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(in_msg == NULL)
    {
        return;
    }
    
    mmi_mms_bgsr_action_fsm(MMI_MMS_BGSR_ACTION_SAVE_RSP, msg_rsp, NULL );    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_download_mms_req
 * DESCRIPTION
 *  Download MMS msg request
 * PARAMETERS
 *  msg     [IN]    the message to send
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_download_mms_req( mmi_mms_bgsr_msg_struct *msg )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_TRY_TO_DOWNLOAD, __LINE__);    

    while(msg != NULL)
    {
        if(msg->size < mmi_mms_bgsr_get_free_space())
        {
            break;
        }
        msg = msg->next;
    }

    /* sanity check */
    if(msg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_DOWNLOAD_MMS_REQ, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_DOWNLOAD_MMS_REQ,msg->msg_id,__LINE__);    
    
    msg->status = MMI_MMS_BGSR_STATUS_DOWNLOADING;
    g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id = msg->msg_id;
    mmi_mms_bgsr_show_mms_status_icon(MMI_MMS_BGSR_INDICATOR_BUSY);    

    request_id = mmi_mms_bgsr_get_request_id();
    
    msg_req = (wap_mma_download_req_struct*) construct_local_para(
                        sizeof(wap_mma_download_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;    
    msg_req->req_id = request_id;
    msg_req->msg_id = msg->msg_id;

    mmi_mms_bgsr_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_DOWNLOAD_REQ,
        (oslParaType*) msg_req,
        NULL);

    return;
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_download_mms_ind_hdlr
 * DESCRIPTION
 *  Download MMS message indication handler
 * PARAMETERS
 *  inMsg           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_download_mms_ind_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_ind_struct *msg_ind = (wap_mma_download_ind_struct*) inMsg;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* sanity check */
    if(inMsg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SEND_MMS_IND_HDLR, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_SEND_MMS_IND_HDLR,msg_ind->msg_id,__LINE__);

    if ( g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id != msg_ind->msg_id )
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }
    else
    {
        wap_mma_download_res_struct *msg_res;

        msg_res = (wap_mma_download_res_struct*) construct_local_para(
                                            sizeof(wap_mma_download_res_struct), TD_CTRL | TD_RESET);
        msg_res->app_id = MMA_APP_ID_BGSR;
        msg_res->result = MMA_RESULT_OK;
        msg_res->req_id = msg_ind->req_id;

        mmi_mms_bgsr_send_message(
            MOD_MMI,
            MOD_WAP,
            0,
            MSG_ID_WAP_MMA_DOWNLOAD_RES,
            (oslParaType*) msg_res,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_download_mms_rsp
 * DESCRIPTION
 *  Download MMS msg response
 * PARAMETERS
 *  inMsg           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_download_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_rsp_struct *msg_rsp = (wap_mma_download_rsp_struct*) inMsg;
    U16* fail_cause = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(inMsg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_DOWNLOAD_MMS_RSP, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_DOWNLOAD_MMS_RSP,msg_rsp->msg_id,__LINE__);    

    mmi_mms_bgsr_show_mms_status_icon(MMI_MMS_BGSR_INDICATOR_IDLE);
    mmi_mms_bgsr_action_fsm(MMI_MMS_BGSR_ACTION_DOWNLOAD_RSP, msg_rsp, fail_cause );    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_abort_download_mms_req
 * DESCRIPTION
 *  Abort sending MMS msg request
 * PARAMETERS
 *  msg_id          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_abort_download_mms_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_download_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(msg_id == 0)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ABORT_DOWNLOAD_MMS_REQ, 0,__LINE__);        
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_ABORT_DOWNLOAD_MMS_REQ,msg_id,__LINE__);
    
    mmi_mms_bgsr_show_mms_status_icon(MMI_MMS_BGSR_INDICATOR_IDLE);    
    request_id = mmi_mms_bgsr_get_request_id();
    
    msg_req = (wap_mma_cancel_download_req_struct*) construct_local_para(
                sizeof(wap_mma_cancel_download_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;    
    msg_req->req_id = request_id;
    msg_req->msg_id = msg_id;
    
    mmi_mms_bgsr_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_abort_download_mms_rsp
 * DESCRIPTION
 *  Abort MMS msg response
 * PARAMETERS
 *  in_msg              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_abort_download_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(in_msg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        mmi_mms_bgsr_echo_current_info();
        return;
    }

    mmi_mms_bgsr_action_fsm(MMI_MMS_BGSR_ACTION_CANCEL_DOWNLOAD_RSP, msg_rsp, NULL );    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_msg_is_valid_rsp
 * DESCRIPTION
 *  Sync MMS msg response
 * PARAMETERS
 *  in_msg              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_msg_is_valid_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_msg_is_valid_rsp_struct *msg_rsp = (wap_mma_msg_is_valid_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(in_msg == NULL)
    {
        return;
    }

    mmi_mms_bgsr_action_fsm(MMI_MMS_BGSR_ACTION_SYNC_MSG_RSP, msg_rsp, NULL );    

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_send_message
 * DESCRIPTION
 *  Common function for sending message
 * PARAMETERS
 *  MOD_SRC         [IN]        Source module
 *  MOD_DEST        [IN]        Destination module
 *  MSG_SAP         [IN]        Message SAP
 *  MSG_ID          [IN]        Message ID
 *  LOCAL           [IN]        Local parameter
 *  PEER            [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_SRC;
    Message.oslDestId = MOD_DEST;
    Message.oslSapId = MSG_SAP;
    Message.oslMsgId = MSG_ID;
    Message.oslDataPtr = LOCAL;
    Message.oslPeerBuffPtr = PEER;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mma_get_request_id
 * DESCRIPTION
 *  Get non-zero request id for issuing a request. 
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mmi_mms_bgsr_get_request_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wap_mma_get_request_id();
}

#endif /*__MMI_MMS_BGSR_SUPPORT__*/
