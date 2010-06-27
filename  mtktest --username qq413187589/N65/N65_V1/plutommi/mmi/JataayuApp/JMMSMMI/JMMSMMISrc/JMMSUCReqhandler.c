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
 *  JMMSUCReqhandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for handling all request and responces for Jataayu UC integration.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef __MMI_JMMSUCREQRSPHANDLER_C
#define __MMI_JMMSUCREQRSPHANDLER_C
/***************************************************************************
* System Include Files
**************************************************************************/

/***************************************************************************
* User Include Files
**************************************************************************/
#if defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__)

#include "gui_data_types.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "JMMSGprot.h"
#include "JMMSMainMMS.h"
#include "JMMSJSRHandler.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JMMSExdcl.h"
#include "JsrTypes.h"
#include "JsrProts.h"
#include "ddl.h"
#include "jcevent.h"
#include "jcerror.h"
#include "wap_ps_struct.h"
#include "JPushInboxUM.h"
#include "fmt_struct.h"
#include "wapadp.h"
#include "jdd_configapi.h"
#include "jdd_memapi.h"
#include "JMMSUCWrappersProt.h"
#include "JMMSExdcl.h"
#include "JMMSMessageSettingsUtils.h"
#include "mmsadp.h"
#include "JMMSUCInterfaceProt.h"
#include "JMMSUCHandlingGProt.h"
#include "JMMSUCXMLProt.h"
#include "UnifiedComposerResDef.h"
#include "jdd_MessagingConfig.h"
#include "JMMSProtocols.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_send_failure_msg_rsp
 * DESCRIPTION
 *  Wap msg handle for UC in jataayu
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_send_failure_msg_rsp(JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "mmi_jmms_uc_wap_send_failure_msg_rsp", msg_id);

    switch (msg_id)
    {
        case MSG_ID_WAP_MMA_GET_CONTENT_REQ:
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "MSG_ID_WAP_MMA_GET_CONTENT_REQ");
            mmi_jmms_parse_call_error_callback(JC_ERR_GENERAL_FAILURE);
            break;
        }
        case MSG_ID_WAP_MMA_CREATE_REQ:
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "MSG_ID_WAP_MMA_CREATE_REQ");
            if (g_jmms_context->async_parse_context.callback)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Stopping Parsing");
                mmi_jmms_parse_call_error_callback(JC_ERR_GENERAL_FAILURE);
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Simply sending response");
                mmi_jmms_uc_create_msg_rsp(-1, g_jmms_context->saved_mms_id);
            }
            StopTimer(JMMS_ASYNC_SAVE_TIMER);
            mmi_jmms_parse_continue_stop_timer();
            g_jmms_context->uc_creation_req = JMMS_UC_FOREGROUND_SAVING;
            break;
        }
        case MSG_ID_WAP_MMA_PREVIEW_REQ:
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "MSG_ID_WAP_MMA_PREVIEW_REQ");
            mmi_jmms_uc_wap_mma_preview_rsp(MMA_RESULT_FAIL);
            break;
        }
        case MSG_ID_WAP_MMA_SEND_REQ:
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "MSG_ID_WAP_MMA_SEND_REQ");
        #ifdef __USB_IN_NORMAL_MODE__
            mmi_jmms_uc_cancel_mms_sending_for_usb();
        #endif 
            break;
        }
        case MSG_ID_WAP_MMA_CANCEL_SEND_REQ:
        {
            /* this will cancel mms sending for all mms */
            mmi_jmms_uc_cancel_mms_sending(0xFFFFFFFF);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "MSG_ID_WAP_MMA_CANCEL_SEND_REQ");
            break;
        }
        default:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "default");
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_handle_msg
 * DESCRIPTION
 *  Wap msg handle for UC in jataayu
 * PARAMETERS
 *  msg_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_handle_msg(void *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *message_p = (MYQUEUE*) msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_id = message_p->msg_id;
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    switch (message_p->msg_id)
    {
        case MSG_ID_WAP_MMA_UC_START_RSP:
        {
            /* wap_mma_uc_start_rsp_struct *local_data = (wap_mma_uc_start_rsp_struct *)(message_p->oslDataPtr->local_para_ptr); */
            break;
        }
        case MSG_ID_WAP_MMA_GET_SETTING_REQ:
        {
            mmi_jmms_uc_send_wap_mma_get_setting_rsp((wap_mma_get_setting_req_struct*) message_p->oslDataPtr);
            break;
        }

        case MSG_ID_WAP_MMA_GET_CONTENT_REQ:
        {
            mmi_jmms_uc_wap_mma_get_content_req_handler((wap_mma_get_content_req_struct*) message_p->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMA_CREATE_REQ:
        {
            mmi_jmms_uc_wap_mma_create_req_handler((wap_mma_create_req_struct*) message_p->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMA_PREVIEW_REQ:
        {
            mmi_jmms_uc_wap_mma_preview_req_handler((wap_mma_preview_req_struct*) message_p->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMA_SAVE_REQ:
        {
            mmi_jmms_uc_wap_mma_save_req_handler((wap_mma_save_req_struct*) message_p->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMA_SEND_REQ:
        {
            mmi_jmms_uc_wap_mma_send_req_handler((wap_mma_send_req_struct*) message_p->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMA_CANCEL_SEND_REQ:
        {
            mmi_jmms_uc_wap_mma_cancel_send_req_handler((wap_mma_cancel_send_req_struct*) message_p->oslDataPtr);
            break;
        }
        case MSG_ID_WAP_MMA_DELETE_REQ:
        {
            mmi_jmms_uc_wap_mma_delete_req_handler((wap_mma_delete_req_struct*) message_p->oslDataPtr);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_send_mode_start_uc_req
 * DESCRIPTION
 *  Send composer open request for perticular mode to UC
 * PARAMETERS
 *  msg_id      [IN]        
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_send_mode_start_uc_req(JC_UINT32 msg_id, mma_app_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_uc_start_req_struct *req_p = NULL;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (wap_mma_uc_start_req_struct*) OslConstructDataPtr(sizeof(wap_mma_uc_start_req_struct));
    req_p->mode = mode;
    req_p->msg_id = msg_id;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMA_UC_START_REQ;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) req_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_get_content_req_handler
 * DESCRIPTION
 *  Get contennt req handle for UC in jataayu
 * PARAMETERS
 *  local_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_get_content_req_handler(wap_mma_get_content_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_req_struct *req_info_p = NULL;
    JC_UINT32 free_mem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_info_p = (wap_mma_get_content_req_struct*) jdd_MemAlloc(1, sizeof(wap_mma_get_content_req_struct));
    memcpy(req_info_p, local_data, sizeof(wap_mma_get_content_req_struct));

    g_jmms_context->uc_req_rsp_info_holder_p = (void*)req_info_p;

    free_mem = jdd_FSGetMMSFolderFreeSpace();

    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "JMMS UC : wap_mma_get_content_req_handler(bi:%d fm:%d)", local_data->buffer_index, free_mem);

    if ((!mmi_jmms_is_ready_without_store(0)) && free_mem)
    {
        if (local_data->buffer_index == 0)
        {
            JC_CHAR *file_name_p = NULL;

            mmi_jmms_delete_uc_compose_files();
            if ((kal_bool) mmi_jmms_compose_settings_auto_sign_status() == KAL_TRUE)
            {
                file_name_p = mmi_jmms_uc_create_auto_signature_file();
                if (file_name_p != NULL)
                {
                    jdd_MemFree(file_name_p);
                }
            }

            jdd_SetWithoutVirtualFileParsingStatus();
            mmi_jmms_uc_create_parsed_mms_data_common_fun(
                local_data->msg_id,
                local_data->mode,
                mmi_jmms_uc_get_content_async_callback);
        }
        else
        {
            mmi_jmms_uc_send_wap_mma_get_content_rsp(MMA_RESULT_OK);
        }
        mmi_jmms_uc_delete_screen_from_history_after_rsp();
    }
    else
    {
        mmi_jmms_uc_send_wap_mma_get_content_rsp(MMA_RESULT_FAIL_INSUFFICIENT_STORAGE);
        mmi_jmms_uc_delete_screen_from_history_after_rsp();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_create_req_handler
 * DESCRIPTION
 *  Create req handle for UC in jataayu
 * PARAMETERS
 *  local_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_create_req_handler(wap_mma_create_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *req_info_p = NULL;
    JC_UINT32 free_mem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsScreenPresent(SCR_ID_UC_PROCESSING) && GetActiveScreenId() != SCR_ID_UC_PROCESSING)
    {
        g_jmms_context->uc_creation_req = JMMS_UC_BACKGROUND_SAVING;
    }
    else
    {
        g_jmms_context->uc_creation_req = JMMS_UC_FOREGROUND_SAVING;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "JMMS UC : wap_mma_create_req_handler(state:%d)", g_jmms_context->uc_creation_req);

    req_info_p = (wap_mma_create_req_struct*) jdd_MemAlloc(1, sizeof(wap_mma_create_req_struct));
    memcpy(req_info_p, local_data, sizeof(wap_mma_create_req_struct));

    g_jmms_context->uc_req_rsp_info_holder_p = (void*)req_info_p;

    free_mem = jdd_FSGetMMSFolderFreeSpace();
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: mmi_jmms_uc_wap_mma_create_req_handler: %d", free_mem);

    /* check for memory full */
    if ((!mmi_jmms_is_ready_without_store(0)) && free_mem)
    {
        if (local_data->mode == MMA_MODE_FORWARD || local_data->mode == MMA_MODE_SEND)
        {
            mmi_jmms_uc_create_parsed_mms_data_common_fun(
                local_data->msg_id,
                local_data->mode,
                mmi_jmms_uc_create_message_handle_async_callback);
            mmi_jmms_set_fw_flag_of_message();
        }
        else
        {
            mmi_jmms_uc_create_msg_req(local_data, mmi_jmms_uc_create_msg_rsp);
            mmi_jmms_reset_fw_flag_of_message();
        }
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: mmi_jmms_uc_wap_mma_create_req_handler: force rsp fail");

        mmi_jmms_uc_wap_mma_create_mms_rsp(MMA_RESULT_FAIL_INSUFFICIENT_MEMORY, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_delete_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_delete_req_handler(wap_mma_delete_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_uc_delete_message(local_data->req_id, local_data->box, local_data->msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_preview_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_preview_req_handler(wap_mma_preview_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_preview_req_struct *req_info_p = NULL;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_info_p = (wap_mma_preview_req_struct*) jdd_MemAlloc(1, sizeof(wap_mma_preview_req_struct));
    memcpy(req_info_p, local_data, sizeof(wap_mma_preview_req_struct));

    g_jmms_context->uc_req_rsp_info_holder_p = (void*)req_info_p;

    mmi_jmms_uc_preview_mms_from_msg_id(req_info_p->msg_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_send_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_send_req_handler(wap_mma_send_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *req_info_p = NULL;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_info_p = (wap_mma_send_req_struct*) jdd_MemAlloc(1, sizeof(wap_mma_send_req_struct));
    memcpy(req_info_p, local_data, sizeof(wap_mma_send_req_struct));

    g_jmms_context->uc_req_rsp_info_holder_p = (void*)req_info_p;
    mmi_jmms_uc_create_parsed_mms_data_common_fun(
        local_data->msg_id,
        MMI_UC_STATE_SEND,
        mmi_jmms_uc_send_message_async_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_cancel_send_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_cancel_send_req_handler(wap_mma_cancel_send_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_uc_cancel_mms_sending_from_id(local_data->req_id, local_data->msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_save_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_save_req_handler(wap_mma_save_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_req_struct *req_info_p = NULL;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_info_p = (wap_mma_save_req_struct*) jdd_MemAlloc(1, sizeof(wap_mma_save_req_struct));
    memcpy(req_info_p, local_data, sizeof(wap_mma_save_req_struct));

    g_jmms_context->uc_req_rsp_info_holder_p = (void*)req_info_p;

    mmi_jmms_uc_start_save_mms(local_data->req_id, local_data->box, local_data->msg_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_send_wap_mma_get_setting_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_send_wap_mma_get_setting_rsp(wap_mma_get_setting_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_setting_rsp_struct *rsp_p = NULL;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_id = 0;
    rsp_p = (wap_mma_get_setting_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_get_setting_rsp_struct));

    rsp_p->req_id = local_data->req_id;
    rsp_p->result = MMA_RESULT_OK;
    rsp_p->creation_mode = mmi_jmms_uc_get_creation_mode();
    rsp_p->priority = mmi_jmms_uc_conf_get_priority();
    rsp_p->validity_period = mmi_jmms_uc_conf_get_expiry_time();
    rsp_p->delivery_time = mmi_jmms_uc_conf_get_delivery_time();
    rsp_p->delivery_report = mmi_jmms_uc_conf_get_delivery_report();
    rsp_p->read_report = mmi_jmms_uc_conf_get_read_report();
    rsp_p->max_mms_size = mmi_jmms_uc_conf_get_max_mms_size();
    memset(&rsp_p->image_resize, 0x0, sizeof(mma_image_resizing_struct));
    mmi_jmms_uc_conf_get_image_resizing(&rsp_p->image_resize);
    memset(&rsp_p->signature, 0x0, sizeof(mma_signature_struct));
    mmi_jmms_uc_conf_get_signature(&rsp_p->signature);
    memset(&rsp_p->sliding_time, 0x0, sizeof(mma_setting_struct));
    mmi_jmms_uc_conf_get_sliding_time(&rsp_p->sliding_time);

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMA_GET_SETTING_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_send_wap_mma_get_content_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_send_wap_mma_get_content_rsp(mma_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    JC_CHAR file_name[FMGR_MAX_PATH_LEN] = {0, };
    JC_CHAR *file_name_p = NULL;
    JC_CHAR dest_fname[FMGR_MAX_PATH_LEN] = {0, };
    kal_uint16 len = 0;
    U32 xml_size = 0;
    kal_bool more = FALSE;
    wap_mma_get_content_req_struct *req_info_p =
        (wap_mma_get_content_req_struct*) g_jmms_context->uc_req_rsp_info_holder_p;
    wap_mma_get_content_rsp_struct *rsp_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_id = 0;
    if (result == MMA_RESULT_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : send_wap_mma_get_content_rsp() Parsing Success");

        if (g_jmms_context->jmms_fs_handle == NULL)
        {
            if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
            {
                /* ret_code = JC_ERR_FILE_SYS_INIT; */
                goto END;
            }
        }

        memset(file_name, 0, FMGR_MAX_PATH_LEN);
        mmi_asc_to_ucs2((S8*) file_name, MMI_JMMS_UC_GET_CONTENT_XML_FILE_PATH);
        file_name_p = jdd_FSFileNameTranslate(g_jmms_context->jmms_fs_handle, file_name);
        memcpy((S8*) dest_fname, (const S8*)file_name_p, mmi_ucs2strlen((S8*) file_name_p) * ENCODING_LENGTH);
        if (g_jmms_context->jmms_fs_handle != NULL)
        {
            jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
            g_jmms_context->jmms_fs_handle = NULL;
        }
        if (file_name_p != NULL)
        {
            jdd_MemFree(file_name_p);
            file_name_p = NULL;
        }
        xml_size = mma_get_mmi_file_size(dest_fname);
        message.peer_buff_ptr =
            (peer_buff_struct*) construct_peer_buff(MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER, 0, 0, TD_CTRL);
        more = mmi_jmms_uc_get_mma_content_rsp(
                dest_fname,
                (kal_uint8*) get_pdu_ptr(message.peer_buff_ptr, &len),
                req_info_p->buffer_index,
                xml_size);

        rsp_info_p = (wap_mma_get_content_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_rsp_struct));
        rsp_info_p->buffer_index = req_info_p->buffer_index;
        rsp_info_p->more = more;
        memset(rsp_info_p->xml_filepath, 0, sizeof(rsp_info_p->xml_filepath));
        if (dest_fname != NULL)
        {
            mmi_ucs2ncpy((S8*) & rsp_info_p->xml_filepath, (S8*) dest_fname, 100);
        }

        rsp_info_p->req_id = req_info_p->req_id;
        rsp_info_p->result = result;
        rsp_info_p->msg_id = req_info_p->msg_id;
        rsp_info_p->mms_header_size = g_jmms_context->mms_header_size;
        rsp_info_p->mms_body_size = g_jmms_context->mms_body_size;
        rsp_info_p->xml_size = xml_size;
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : send_wap_mma_get_content_rsp() Fail Parsing");

        rsp_info_p = (wap_mma_get_content_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_rsp_struct));
        rsp_info_p->buffer_index = req_info_p->buffer_index;
        rsp_info_p->more = 0;
        memset(rsp_info_p->xml_filepath, 0, sizeof(rsp_info_p->xml_filepath));
        rsp_info_p->req_id = req_info_p->req_id;
        rsp_info_p->result = result;
        rsp_info_p->msg_id = req_info_p->msg_id;
        rsp_info_p->mms_header_size = 0;
        rsp_info_p->mms_body_size = 0;
        rsp_info_p->xml_size = 0;
        message.peer_buff_ptr =
            (peer_buff_struct*) construct_peer_buff(MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER, 0, 0, TD_CTRL);
        memset((kal_uint8*) get_pdu_ptr(message.peer_buff_ptr, &len), 0, MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER);
    }

    jdd_MemFree(req_info_p);
    g_jmms_context->uc_req_rsp_info_holder_p = NULL;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMA_GET_CONTENT_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) rsp_info_p;
    OslMsgSendExtQueue(&message);
  END:
    jdd_ResetWithoutVirtualFileParsingStatus();
    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
    mmi_jmms_deinit_mms_context(g_jmms_context);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_create_mms_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_create_mms_rsp(mma_result_enum result, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *rsp_info_p = NULL;
    MYQUEUE message;
    wap_mma_create_req_struct *req_info_p = (wap_mma_create_req_struct*) g_jmms_context->uc_req_rsp_info_holder_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_id = 0;
    g_jmms_context->uc_creation_req = JMMS_UC_FOREGROUND_SAVING;
    rsp_info_p = (wap_mma_create_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_create_rsp_struct));
    rsp_info_p->req_id = req_info_p->req_id;
    rsp_info_p->result = result;
    rsp_info_p->msg_id = msg_id;
    rsp_info_p->buffer_index = req_info_p->buffer_index + 1;

    jdd_MemFree(req_info_p);
    g_jmms_context->uc_req_rsp_info_holder_p = NULL;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMA_CREATE_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) rsp_info_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_preview_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_preview_rsp(mma_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *rsp_p = NULL;
    MYQUEUE message;
    wap_mma_preview_req_struct *req_info_p = (wap_mma_preview_req_struct*) g_jmms_context->uc_req_rsp_info_holder_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_id = 0;
    rsp_p = (wap_mma_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_rsp_struct));

    rsp_p->req_id = req_info_p->req_id;
    rsp_p->result = result;
    rsp_p->msg_id = req_info_p->msg_id;

    jdd_MemFree(req_info_p);
    g_jmms_context->uc_req_rsp_info_holder_p = NULL;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMA_PREVIEW_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_send_progress_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgid                       [IN]        
 *  percentage_of_progress      [IN]        
 *  retry                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_send_progress_ind(U32 msgid, U32 percentage_of_progress, U8 retry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_ind_struct *rsp_p = NULL;
    MYQUEUE message;
    wap_mma_send_req_struct *req_info_p = (wap_mma_send_req_struct*) g_jmms_context->uc_req_rsp_info_holder_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_p = (wap_mma_send_ind_struct*) OslConstructDataPtr(sizeof(wap_mma_send_ind_struct));

    rsp_p->req_id = req_info_p->req_id;
    rsp_p->msg_id = req_info_p->msg_id;
    rsp_p->retry = retry;
    rsp_p->percent = percentage_of_progress;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMA_SEND_IND;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  result              [IN]        
 *  response_text_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_send_rsp(U32 msg_id, mma_result_enum result, JC_CHAR *response_text_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *rsp_p = NULL;
    MYQUEUE message;
    wap_mma_send_req_struct *req_info_p = (wap_mma_send_req_struct*) g_jmms_context->uc_req_rsp_info_holder_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_id = 0;

    rsp_p = (wap_mma_send_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_send_rsp_struct));
    if (result == MMA_RESULT_OK)
    {
        mmi_jmms_delete_uc_compose_files();
    }
    rsp_p->req_id = req_info_p->req_id;
    rsp_p->msg_id = msg_id;
    rsp_p->result = result;
    rsp_p->box = req_info_p->box;
    rsp_p->send_and_save = req_info_p->send_and_save;
    if (response_text_p != NULL)
    {
        mmi_ucs2ncpy((S8*) rsp_p->response_text, (S8*) response_text_p, 256 * sizeof(kal_wchar));
    }
    else
    {
        rsp_p->response_text[0] = 0;
    }

    jdd_MemFree(req_info_p);
    g_jmms_context->uc_req_rsp_info_holder_p = NULL;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMA_SEND_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_send_wap_mma_delete_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_send_wap_mma_delete_rsp(kal_uint32 req_id, mma_result_enum result, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *rsp_p = NULL;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_id = 0;

    rsp_p = (wap_mma_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_rsp_struct));

    rsp_p->req_id = req_id;
    rsp_p->result = result;
    rsp_p->msg_id = msg_id;

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_WAP_MMA_DELETE_RSP;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) rsp_p;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_save_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_save_rsp(mma_result_enum result, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *rsp_p = NULL;
    MYQUEUE Message;
    wap_mma_save_req_struct *req_info_p = (wap_mma_save_req_struct*) g_jmms_context->uc_req_rsp_info_holder_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMA_RESULT_OK && mms_is_re_entrant() != FALSE)
    {
        mmi_jmms_delete_uc_compose_files();
    }
    g_jmms_context->msg_id = 0;

    rsp_p = (wap_mma_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_rsp_struct));
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : wap_mma_save_rsp(rt:%d md:%d)", result, msg_id);
    rsp_p->req_id = req_info_p->req_id;
    rsp_p->result = result;
    rsp_p->msg_id = msg_id;

    jdd_MemFree(req_info_p);
    g_jmms_context->uc_req_rsp_info_holder_p = NULL;

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_WAP_MMA_SAVE_RSP;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) rsp_p;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_wap_mma_cancel_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_wap_mma_cancel_send_rsp(kal_uint8 result, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *rsp_p = NULL;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->msg_id = 0;

    rsp_p = (wap_mma_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_rsp_struct));

    rsp_p->req_id = g_jmms_context->uc_cancel_req_id;
    rsp_p->result = result;
    rsp_p->msg_id = msg_id;

    /* Prepare response structure */
    message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_WAP_MMA_CANCEL_SEND_RSP;

    /* Send Response to MMI Queue */
    message.oslDataPtr = (oslParaType*) rsp_p;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);

    g_jmms_context->uc_cancel_req_id = 0;
}

#else /* defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_uc_req_handler_fun
 * DESCRIPTION
 *  Just to remove warning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_uc_req_handler_fun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy */
}
#endif /* defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__) */ 
#endif /* __MMI_JMMSUCREQRSPHANDLER_C */ 

