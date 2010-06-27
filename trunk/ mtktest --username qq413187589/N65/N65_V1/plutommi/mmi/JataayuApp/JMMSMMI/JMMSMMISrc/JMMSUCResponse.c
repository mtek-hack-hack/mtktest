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
 *  JMMSUCResponse.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for handling unified composer responses for protocol layer.
 *
 * Author:
 * ------------
 * -------
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_JMMSUCRESPONSE_C
#define _MMI_JMMSUCRESPONSE_C

/***************************************************************************
* System Include Files
**************************************************************************/

/***************************************************************************
* User Include Files
**************************************************************************/


#ifdef __MMI_UNIFIED_COMPOSER__
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))


#include "MainMenuDef.h"
#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
#include <jdi_communicator.h>

#include <MessagingDatatypes.h>
#include <MessagingAPI.h>
#include "JMMSExdcl.h"

#include "FileMgr.h"    /* Should include FileMgr.h before ProfileMgrGprot.h */
#include "FileManagerGProt.h"

#include "JsrTypes.h"
#include "JMMSJSRHandler.h"
#include <PrvMessagingDataTypes.h>
#include"JMMSCompose.h"
#include "MessagesResourceData.h"
#include "JBrowserResDef.h"
#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSCoreAPI.h"
#include "JMMSExdcl.h"
#include "JMMSGprot.h"
#include "JMMSJSRHandler.h"
#include "JMMSProtocols.h"
#include "JMMSPushHandling.h"
#include "JMMSResDef.h"
#include "miscutils.h"
#include "JSRProts.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
#include "FileManagerDef.h"
#endif 
/* ... Add More MMI header */
#include "gpioInc.h"
#include "JMMSUCInterfaceProt.h"

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

JC_UINT32 mmi_jmms_uc_get_msgid(mmi_jmms_communication_state_node_struct *communication_handle_p);
JC_UINT32 mmi_jmms_uc_get_msg_id_from_msg_handle(MSG_HANDLE msg_handle);

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_response_callback
 * DESCRIPTION
 *  Callback to handle response from protocol layer
 * PARAMETERS
 *  cb_type     [IN]        
 *  data_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_response_callback(mmi_jmms_communication_callback_enumm cb_type, void *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_response_callback: %d", cb_type);
    /* data cant be NULL. */
    ASSERT(data_p);

    switch (cb_type)
    {
        case MMS_SENDING_START_CALLBACK:
        {
            mmi_jmms_uc_start_comm_struct *comm_start_data_p = (mmi_jmms_uc_start_comm_struct*) data_p;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "MMS_SENDING_START_CALLBACK");
            mmi_jmms_uc_handle_start_rsp(comm_start_data_p);
        }
            break;
        case MMS_COMMUNICATION_PROGRESS_CALLBACK:
        {
            mmi_jmms_comm_progress_struct *progress_ind_data_p = (mmi_jmms_comm_progress_struct*) data_p;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "MMS_SEND_PROGRESS_IND_CALLBACK");
            mmi_jmms_uc_handle_progress_ind(progress_ind_data_p);
        }
            break;
        case MMS_SENDING_COMPELETE_CALLBACK:
        {
            mmi_jmms_uc_sending_complete_struct *sending_complete_data_p =
                (mmi_jmms_uc_sending_complete_struct*) data_p;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "MMS_SENDING_COMPELETE_CALLBACK");
            mmi_jmms_uc_handle_sending_complete_rsp(sending_complete_data_p);
        }
            break;
        case MMS_SENDING_ERROR_CALLBACK:
        {
            mmi_jmms_uc_error_struct *error_data_p = (mmi_jmms_uc_error_struct*) data_p;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "MMS_SENDING_ERROR_CALLBACK");
            mmi_jmms_uc_handle_error_ind(error_data_p);
        }
            break;
        case MMS_COMMUNICATION_STOP_CALLBACK:
        {
            mmi_jmms_communication_stop_struct *sending_stop_data_p = (mmi_jmms_communication_stop_struct*) data_p;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "MMS_SENDING_STOP_CALLBACK");
            mmi_jmms_uc_handle_stop_ind(sending_stop_data_p);
        }
            break;
        default:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "default");
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_handle_start_rsp
 * DESCRIPTION
 *  Function to handle sending start response
 * PARAMETERS
 *  send_start_rsp_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_handle_start_rsp(mmi_jmms_uc_start_comm_struct *send_start_rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_HANDLE msg_handle = NULL;
    mmi_jmms_sending_list_struct *send_node_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_handle_start_rsp: %d",
                         send_start_rsp_p->communication_handle_p->reference_id);

    /* add communication handle information in send node list */
    send_node_list_p = g_jmms_context->send_node_list;
    msg_handle = send_start_rsp_p->msg_handle;
    while (send_node_list_p)
    {
        if (send_node_list_p->msg_handle == msg_handle)
        {
            send_node_list_p->communication_handle_p = send_start_rsp_p->communication_handle_p;
            break;
        }
        send_node_list_p = send_node_list_p->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_handle_progress_ind
 * DESCRIPTION
 *  Function to handle progress indication
 * PARAMETERS
 *  progress_ind_data_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_handle_progress_ind(mmi_jmms_comm_progress_struct *progress_ind_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    COMM_PROGRESS_IND *progress_ind_p = NULL;
    JC_UINT32 percentage_of_progress = 0;
    JC_UINT32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_handle_progress_ind: %d",
                         progress_ind_data_p->communication_handle_p->reference_id);

    ASSERT(progress_ind_data_p);
    if (progress_ind_data_p->progress_ind_p != NULL)
    {
        progress_ind_p = progress_ind_data_p->progress_ind_p;
    }
    msg_id = mmi_jmms_uc_get_msgid(progress_ind_data_p->communication_handle_p);
    if (msg_id == -1)
    {
        ASSERT(0);
    }

    if (progress_ind_p)
    {
        if (progress_ind_p->eStackStatus == E_COMM_STACK_SENDING)
        {
            percentage_of_progress = (progress_ind_p->uiBytesSent) * 100;
            percentage_of_progress = percentage_of_progress / (progress_ind_p->uiTotalBytesToSend);
        }
    }

    // if progress_ind_p is NULL then we will send
    // indication to UC for retry mechanism
    if ((percentage_of_progress > 0) || (progress_ind_p == NULL))
    {
        mmi_jmms_uc_send_progress_ind(
            msg_id,
            percentage_of_progress,
            (U8) (progress_ind_data_p->communication_handle_p->retry_counter - 1));
        progress_ind_data_p->communication_handle_p->percent_sent = percentage_of_progress;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_handle_sending_complete_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sending_complete_data_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_handle_sending_complete_rsp(mmi_jmms_uc_sending_complete_struct *sending_complete_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 msg_id = 0;
    JC_CHAR *response_text_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_handle_sending_complete_rsp: %d",
                         sending_complete_data_p->communication_handle_p->reference_id);

#ifdef __MMI_JMMS_SEND_RETRIES__
    mmi_jmms_set_progress_screen_title(0);
#endif 

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
    mmi_jmms_stop_timeout_timer();
#endif 

    /* get message ID of the message whose sending was successful. */
    msg_id = mmi_jmms_uc_get_msgid(sending_complete_data_p->communication_handle_p);
    ASSERT(msg_id > 0);

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    if (sending_complete_data_p->response_text != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "__MMI_JMMS_TEST_REQUEST_STATUS_TEXT_DISPLAY__");
        response_text_p = (JC_CHAR*) sending_complete_data_p->response_text;
    }
#endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
    mmi_jmms_uc_remove_send_node(msg_id);
    /* call UC API for this to send sending complete response */
    mmi_jmms_uc_sending_complete(msg_id, mmi_jmms_get_error_type(sending_complete_data_p->error_code), response_text_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_handle_error_ind
 * DESCRIPTION
 *  Function to handle error indication from protocol layer
 * PARAMETERS
 *  error_data_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_handle_error_ind(mmi_jmms_uc_error_struct *error_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 msg_id = 0;
    JC_CHAR *response_text_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_data_p->communication_handle_p)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_handle_error_ind: %d",
                             error_data_p->communication_handle_p->reference_id);
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_handle_error_ind: encap fail");
    }

#ifdef __MMI_JMMS_SEND_RETRIES__
    mmi_jmms_set_progress_screen_title(0);
#endif 

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
    mmi_jmms_stop_timeout_timer();
#endif 

    msg_id = mmi_jmms_uc_get_msg_id_from_msg_handle(g_jmms_context->msg_handle);
    ASSERT(msg_id > 0);

    /* remove send node from the sending list */
    mmi_jmms_uc_remove_send_node(msg_id);

    /* call UC API to indicate sending has completed */
    mmi_jmms_uc_sending_complete(msg_id, mmi_jmms_get_error_type(error_data_p->error_code), response_text_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_handle_stop_ind
 * DESCRIPTION
 *  Function to handle stop communication indication.
 * PARAMETERS
 *  sending_stop_data_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_handle_stop_ind(mmi_jmms_communication_stop_struct *sending_stop_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_handle_stop_ind");

#ifdef __MMI_JMMS_SEND_RETRIES__
    mmi_jmms_set_progress_screen_title(0);
#endif 

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
    mmi_jmms_stop_timeout_timer();
#endif 
    if (sending_stop_data_p->communication_handle_p)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_handle_stop_ind: %d",
                             sending_stop_data_p->communication_handle_p->reference_id);
        msg_id = mmi_jmms_uc_get_msgid(sending_stop_data_p->communication_handle_p);
        ASSERT(msg_id > 0);
    }

    else
    {
        msg_id = sending_stop_data_p->msg_id;
        ASSERT(msg_id > 0);
    }

    /* remove node from send list */
    mmi_jmms_uc_remove_send_node(msg_id);
    /* send stop response to UC */
    if (g_jmms_context->uc_cancel_req_id && g_jmms_context->msg_id)
    {
        mmi_jmms_uc_send_stop_ind(E_TRUE, msg_id);
        /* call UC API to indicate sending has completed */
        mmi_jmms_uc_sending_complete_rsp_for_cancel_send(msg_id, E_TRUE, NULL); /* True for cancel success */
    }
    else if (g_jmms_context->msg_id)
    {
        mmi_jmms_uc_sending_complete(msg_id, MMA_RESULT_FAIL_USER_CANCEL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_send_mms
 * DESCRIPTION
 *  Function send MMS
 * PARAMETERS
 *  msg_handle      [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  JC_OK or JC_ERR_MMS_ENCODE_PENDING  on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_send_mms(MSG_HANDLE msg_handle, JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_send_mms: %d", msg_id);

    ASSERT((msg_handle != NULL) || (msg_id > 0));
    if (NULL == msg_handle || 0 == msg_id)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_send_mms PARAMS not OK");
        return JC_ERR_INVALID_PARAMETER;
    }
    mmi_jmms_uc_add_send_node(msg_handle, msg_id);

#ifdef __MMI_JMMS_SEND_RETRIES__
    mmi_jmms_set_progress_screen_title(STR_ID_PROGRESS_SENDING);
#endif 

    /* send request for sending */
    ret_code = mmi_jmms_send_mms(
                msg_handle,                     /* message handle */
                E_TYPE_NEW_MMS,                 /* comm_state */
                E_TRUE,                         /* bIsStream */
                1,                              /* retry */
                E_TRUE,                         /* bIsAsync */
                mmi_jmms_uc_response_callback); /* callback */

    /* if sending has failed remove send node from send list */
    if (ret_code != JC_OK && ret_code != JC_ERR_MMS_ENCODE_PENDING)
    {
        mmi_jmms_uc_remove_send_node(msg_id);
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_cancel_mms_sending
 * DESCRIPTION
 *  Function to cancel MMS sending
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_cancel_mms_sending(JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;
    mmi_jmms_communication_stop_struct sending_stop_data = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_cancel_mms_sending: %x", msg_id);

    ASSERT(msg_id);
    if (0xFFFFFF == msg_id)
    {
        mmi_jmms_cancel_all_mms_sending();
    }
    else
    {
        communication_handle_p = mmi_jmms_uc_get_communication_handle(msg_id);
        mmi_jmms_cancel_mms_sending(NULL, communication_handle_p);
        if (!communication_handle_p)
        {
            sending_stop_data.communication_handle_p = NULL;
            sending_stop_data.retCode = MMI_TRUE;
            sending_stop_data.msg_id = msg_id;
            mmi_jmms_uc_response_callback(MMS_COMMUNICATION_STOP_CALLBACK, (void*)&sending_stop_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_msgid
 * DESCRIPTION
 *  Function to get message ID from communication handle.
 * PARAMETERS
 *  communication_handle_p      [IN]        
 * RETURNS
 *  message ID of the corresponding communication handle
 *****************************************************************************/
JC_UINT32 mmi_jmms_uc_get_msgid(mmi_jmms_communication_state_node_struct *communication_handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_sending_list_struct *send_node_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_get_msgid");

    send_node_list_p = g_jmms_context->send_node_list;
    while (send_node_list_p)
    {
        if (send_node_list_p->communication_handle_p == communication_handle_p)
        {
            return send_node_list_p->msg_id;
        }
        send_node_list_p = send_node_list_p->next;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_communication_handle
 * DESCRIPTION
 *  Function to get communication handle from message ID
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  communication state node of the desired message ID
 *****************************************************************************/
mmi_jmms_communication_state_node_struct *mmi_jmms_uc_get_communication_handle(JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_sending_list_struct *send_node_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_uc_get_communication_handle:%x", msg_id);

    send_node_list_p = g_jmms_context->send_node_list;
    while (send_node_list_p)
    {
        if (send_node_list_p->msg_id == msg_id)
        {
            return send_node_list_p->communication_handle_p;
        }
        send_node_list_p = send_node_list_p->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_add_send_node
 * DESCRIPTION
 *  Function to add send node
 * PARAMETERS
 *  msg_handle      [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_add_send_node(MSG_HANDLE msg_handle, JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_sending_list_struct *send_node_list_p = NULL;
    mmi_jmms_sending_list_struct *new_send_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_node_list_p = g_jmms_context->send_node_list;

    new_send_node_p = (mmi_jmms_sending_list_struct*) jdd_MemAlloc(sizeof(mmi_jmms_sending_list_struct), 1);
    new_send_node_p->msg_id = msg_id;
    new_send_node_p->msg_handle = msg_handle;
    new_send_node_p->communication_handle_p = NULL;

    if (NULL == g_jmms_context->send_node_list)
    {
        new_send_node_p->next = NULL;
    }
    else
    {
        new_send_node_p->next = g_jmms_context->send_node_list;
    }
    g_jmms_context->send_node_list = new_send_node_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_remove_send_node
 * DESCRIPTION
 *  Function remove send node
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_remove_send_node(JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_sending_list_struct *send_node_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_node_list_p = g_jmms_context->send_node_list;
    while (send_node_list_p)
    {
        if (send_node_list_p->msg_id == msg_id)
        {
            g_jmms_context->send_node_list = send_node_list_p->next;
            jdd_MemFree(send_node_list_p);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_msg_id_from_msg_handle
 * DESCRIPTION
 *  Function to get msg_id from message handle
 * PARAMETERS
 *  msg_handle      [IN]        
 * RETURNS
 *  msg_id
 *****************************************************************************/
JC_UINT32 mmi_jmms_uc_get_msg_id_from_msg_handle(MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_sending_list_struct *send_node_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_node_list_p = g_jmms_context->send_node_list;
    while (send_node_list_p)
    {
        if (send_node_list_p->msg_handle == msg_handle)
        {
            return send_node_list_p->msg_id;
        }
    }
    return -1;
}

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_cancel_mms_sending_for_usb
 * DESCRIPTION
 *  Function is used to cancel mms sending
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_cancel_mms_sending_for_usb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_uc_cancel_mms_sending_for_usb");
    msg_id = mmi_jmms_uc_get_msg_id_from_msg_handle(g_jmms_context->msg_handle);

    /* it means mms encapsulation or sending has sarted */
    if (msg_id > 0)
    {
        mmi_jmms_uc_error_struct error_data = {0, };

        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Stop MMS Sending");
        if (g_jmms_context->reference_id)
        {
            mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Stoping MMS Sending: ", g_jmms_context->reference_id);

            comm_node_p = mmi_jmms_get_comm_state(g_jmms_context, g_jmms_context->reference_id);

            if (comm_node_p && comm_node_p->callback)
            {
                error_data.error_code = -1;
                error_data.communication_handle_p = comm_node_p;
                comm_node_p->callback(MMS_SENDING_ERROR_CALLBACK, (void*)&error_data);
                /* this is done to stop MMS_COMMUNICATION_STOP_CALLBACK from being executed */
                comm_node_p->callback = NULL;
                mmi_jmms_free_message_header();
                mmi_jmms_free_comm_node(g_jmms_context, g_jmms_context->reference_id);
            }

            jdi_CommunicationStopReq(g_jmms_context->comm_handle, g_jmms_context->reference_id);
            jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
        }
        else if (g_jmms_context->msg_handle)
        {
            msg_id = mmi_jmms_uc_get_msg_id_from_msg_handle(g_jmms_context->msg_handle);
            if (msg_id > 0)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Stoping MMS Encapsulation: ");
                StopTimer(JMMS_ASYNC_SEND_TIMER);
                if (g_jmms_context->ext_cb)
                {
                    error_data.error_code = -1;
                    error_data.communication_handle_p = NULL;
                    g_jmms_context->ext_cb(MMS_SENDING_ERROR_CALLBACK, (void*)&error_data);
                }
            }
        }
    }
}
#endif /* __USB_IN_NORMAL_MODE__ */ /* #ifdef __USB_IN_NORMAL_MODE__ */
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
#else /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_jmmsucresponse_fun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_jmmsucresponse_fun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy */
}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#endif /* _MMI_JMMSUCRESPONSE_C */ 

