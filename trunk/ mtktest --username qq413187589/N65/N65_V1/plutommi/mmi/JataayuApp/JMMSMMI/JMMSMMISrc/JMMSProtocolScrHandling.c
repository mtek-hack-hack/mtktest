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
 *  JMMSProtocolScrHandling.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for screen flow for protocol layer.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __MMI_JMMSPROTSCRHANDLING_C
#define __MMI_JMMSPROTSCRHANDLING_C

/***************************************************************************
* System Include Files
**************************************************************************/

/***************************************************************************
* User Include Files
**************************************************************************/
#ifdef __MMI_UNIFIED_COMPOSER__
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))


#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
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

#include "SmsGuiInterfaceType.h"

#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"
#include "JProfileHandlerResDef.h"

#include "JsrTypes.h"
#include "JMMSJSRHandler.h"

#include <PrvMessagingDataTypes.h>

#include "JMMSInbox.h"

#include"JMMSCompose.h"
#include "MessagesResourceData.h"
#include "JBrowserResDef.h"
#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSCoreAPI.h"
#include "JMMSDrafts.h"
#include "JMMSExdcl.h"
#include "JMMSCompose.h"
#include "JMMSGprot.h"
#include "JMMSInbox.h"
#include "JMMSJSRHandler.h"
#include "JMMSMainMMS.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSOutbox.h"
#include "JMMSProtocols.h"
#include "JMMSPushHandling.h"
#include "JMMSResDef.h"
#include "JMMSSent.h"
#include "JMMSStoreHandling.h"
#include "JMMSStructs.h"
#include "JMMSTemplates.h"
#include "JMMSUseDetails.h"
#include "JMMSView.h"
#include "JMMSWriteMMS.h"

#include "miscutils.h"
#include "CallManagementGprot.h"
#include "AlarmFrameworkProt.h"
#include "SmsGuiInterfaceProt.h"
#include "JSRProts.h"
#include "JMMSMainMMS.h"
#include "wapadp.h"
#include "JPushInboxCommonUI.h"
#include "PhoneBookGprot.h"

#include "MMI_features_camera.h"
#include "CameraResDef.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageProt.h"
#include "JMMSUMHandling.h"
#include "FileManagerDef.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
/* ... Add More MMI header */
#include "gpioInc.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "JMMSUCInterfaceProt.h"
#include "UnifiedComposerResDef.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

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

static FuncPtr g_end_key_processing_handler;
static void mmi_jmms_end_key_progressing(void);
static void mmi_jmms_set_end_key_progressing_handler(void);
void mmi_jmms_handle_progress_ind(
        COMM_PROGRESS_IND *progress_ind_p,
        mmi_jmms_communication_state_node_struct *communication_handle_p);
void mmi_jmms_handle_stop_communication(mmi_jmms_communication_state_node_struct *comm_node_p, JC_RETCODE error_code);

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_screen_flow_callback
 * DESCRIPTION
 *  This function is the callback function that will be called while sending and downloading mms.
 * PARAMETERS
 *  cb_type     [IN]        
 *  data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_screen_flow_callback(mmi_jmms_communication_callback_enumm cb_type, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_handle_screen_flow_callback: %d [%d]", cb_type, data);

    /* data can't be NULL. */
    ASSERT(data);

    switch (cb_type)
    {
        case MMS_COMMUNICATION_PROGRESS_CALLBACK:
        {
            mmi_jmms_comm_progress_struct *progress_ind_data_p = (mmi_jmms_comm_progress_struct*) data;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "MMS_SEND_PROGRESS_IND_CALLBACK");
            mmi_jmms_handle_progress_ind(
                progress_ind_data_p->progress_ind_p,
                progress_ind_data_p->communication_handle_p);
        }
            break;
        case MMS_COMMUNICATION_STOP_CALLBACK:
        {
            mmi_jmms_communication_stop_struct *sending_stop_data = (mmi_jmms_communication_stop_struct*) data;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "MMS_SENDING_STOP_CALLBACK");
            mmi_jmms_handle_stop_communication(sending_stop_data->communication_handle_p, sending_stop_data->retCode);
        }
            break;
        default:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_handle_screen_flow_callback: default");
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_error_in_communication
 * DESCRIPTION
 *  This function will be used to handle any error while sending/receving/downloading
 * PARAMETERS
 *  jmms_context_p          [IN]        
 *  calling_function        [IN]        
 *  comm_node_p             [IN]        
 *  error_code              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_error_in_communication(
        mmi_jmms_context_struct *jmms_context_p,
        U16 calling_function,
        mmi_jmms_communication_state_node_struct *comm_node_p,
        JC_RETCODE error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_error_in_communication");

    switch (comm_node_p->mms_communication_state)
    {
        case E_TYPE_NEW_MMS:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Communication state: NEW MMS");

            if (calling_function == E_FROM_ERROR_CALLBACK)
            {

            #ifdef __MMI_UNIFIED_MESSAGE__
                if (!IsScreenPresent(SCR_ID_JMMS_OUTBOX_OPTIONS))
            #else 
                if (g_jmms_context->last_scr_id != SCR_ID_JMMS_OUTBOX_OPTIONS)
            #endif 
                {
                #ifndef __MMI_UNIFIED_MESSAGE__
                    if (g_jmms_context->save_mms == MMI_TRUE)
                    {
                #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                                             "JMMS, MMS not from Outbox, so Sending and storing the MMS in Outbox");

                        if (comm_node_p->reference_id != 0)
                        {
                            jdi_CommunicationFreeReference(g_jmms_context->comm_handle, comm_node_p->reference_id);
                        }
                        ret_code = mmi_jmms_send_and_store_mms(MMI_JMMS_OUTBOX, jmms_context_p->msg_handle, comm_node_p);

                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "JMMS, mmi_jmms_send_and_store_mms returned:",
                                             ret_code);

                        if (ret_code == JC_OK)
                        {
                        #ifdef __MMI_UNIFIED_MESSAGE__
                            if (IsScreenPresent(SCR_ID_JMMS_DRAFTS_OPTIONS))
                        #else 
                            if (g_jmms_context->last_scr_id == SCR_ID_JMMS_DRAFTS_OPTIONS)
                        #endif 
                            {
                                /* /it means mmms was sent using "Sent" Option in Drafts */

                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_AND_STORED);

                                mmi_jmms_drafts_delete_on_sent();
                            }
                            else
                            {

                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_AND_STORED);
                            #ifdef __MMI_UNIFIED_MESSAGE__
                                if (IsScreenPresent(SCR_ID_JMMS_PREVIEW))
                                {
                                    DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 5);
                                }
                                else if (!IsScreenPresent(SCR_ID_UM_MAIN))
                                {
                                    DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 3);
                                }
                                else
                                {
                                    DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 4);
                                }
                            #else /* __MMI_UNIFIED_MESSAGE__ */ 

                                DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 3);      /* sachin */
                            #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                            }
                        }
                        else
                        {
                            if (ret_code == E_MEMORY_FULL_ERROR)
                            {
                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_AND_FAIL_STORE_MEMORY);
                            }
                            else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                            {
                                if (g_jmms_context->save_mms == MMI_TRUE)
                                {
                                    mmi_jmms_handle_pop_up_for_interupt
                                        (STR_ID_JMMS_ERROR_MMS_SENT_AND_FAIL_STORE_MEM_FULL);
                                }
                                else
                                {
                                    mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MEMORY_FULL_REACH);
                                }
                            }
                            else
                            {
                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_AND_FAIL_STORE);
                            }

                            /* /called from 'Sent" option in Drafts folder */
                        #ifdef __MMI_UNIFIED_MESSAGE__
                            if (IsScreenPresent(SCR_ID_JMMS_PREVIEW))
                            {
                                DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 5);
                            }
                            else if (IsScreenPresent(SCR_ID_JMMS_DRAFTS_OPTIONS))
                            {
                                DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_DRAFT);
                            }
                            else if (!IsScreenPresent(SCR_ID_UM_MAIN))
                            {
                                DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 3);
                            }
                            else
                            {
                                DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 4);
                            }
                        #else /* __MMI_UNIFIED_MESSAGE__ */ 
                            if (g_jmms_context->last_scr_id == SCR_ID_JMMS_DRAFTS_OPTIONS)
                            {
                                DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);
                            }
                            else
                            {
                                DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 3);
                            }
                        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                        }
                    #ifndef __MMI_UNIFIED_MESSAGE__
                    }
                    else
                    {
                        /* /it means called from "Send Only" option */
                        ret_code = mmi_jmms_send_and_store_mms(MMI_JMMS_OUTBOX, jmms_context_p->msg_handle, comm_node_p);
                        if (ret_code == JC_OK)
                        {
                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_AND_STORED);
                        }
                        else
                        {
                            if (ret_code == E_MEMORY_FULL_ERROR)
                            {
                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEMORY);
                            }
                            else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                            {
                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEM_FULL);
                            }
                            else
                            {
                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
                            }
                        }
                        /* mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT); */

                        DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 3);
                    }
                    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                }
                else
                {
                    //it meas user selects "Resent" from Outbox.
                    ///in this case update the MMS into the outbox
                    ret_code = mmi_jmms_send_and_store_mms(MMI_JMMS_OUTBOX, jmms_context_p->msg_handle, comm_node_p);
                    if (JC_OK == ret_code)
                    {
                        ret_code = mmi_jmms_delete_message(
                                    MMI_JMMS_OUTBOX,
                                    g_jmms_context->store_context->num_msg_in_curr_folder - (g_jmms_context->curr_scr_hilited_index));
                    }
                    else if (E_MEMORY_FULL_ERROR == ret_code)
                    {
                        mmi_jmms_add_memory_full_node_if_not_already();
                    }
                    mmi_jmms_handle_error_string(error_code, E_TYPE_NEW_MMS);
                #ifdef __MMI_UNIFIED_MESSAGE__
                    if (IsScreenPresent(SCR_ID_UM_UNSENT))
                    {
                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_UNSENT);
                    }
                    else
                    {
                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, IDLE_SCREEN_ID);
                    }
                #else /* __MMI_UNIFIED_MESSAGE__ */ 
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);
                #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                }
                mmi_jmms_deinit_mms_context(jmms_context_p);

            }
            else
            {
                mmi_jmms_handle_error_string(error_code, E_TYPE_NEW_MMS);

                if (g_jmms_context->last_scr_id == SCR_ID_JMMS_OUTBOX_OPTIONS
                    || g_jmms_context->last_scr_id == SCR_ID_JMMS_DRAFTS_OPTIONS)
                {
                    ///it means mms sent from "ReSent" in Outbox or "Sent" in Drafts
                    ///for these deinit the complete mms context
                    mmi_jmms_deinit_mms_context(jmms_context_p);
                }
                else
                {
                    mmi_jmms_free_message_header();

                }
                DeleteScreenIfPresent(SCR_ID_JMMS_PROGRESS);
                DeleteScreenIfPresent(SCR_ID_JMMS_SENT_OPTIONS);
                DeleteScreenIfPresent(SCR_ID_JMMS_DRAFTS_OPTIONS);
                DeleteScreenIfPresent(SCR_ID_JMMS_OUTBOX_OPTIONS);
                DeleteScreenIfPresent(SCR_ID_WRITE_MMS_DONE_OPTIONS);
            }

            break;

        #ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
        case E_TYPE_NEW_JAVA_MMS_SEND:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Communication state: NEW JAVA MMS");

            mmi_jmms_deinit_mms_context(jmms_context_p);

            (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);
            break;
        #endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 
        case E_TYPE_ACK_RESPONSE:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Communication state: MMS ACK Response");
            break;
        case E_TYPE_NOTIFICATION_RESPONSE:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Communication state: MMS Notification response");

            break;
        case E_TYPE_READ_REPORT_PDU:
        case E_TYPE_READ_REPORT_MMS:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Communication state: MMS Read Report");

            if (ret_code == E_JMMS_STORAGE_FULL)
            {
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_STORAGE_ERROR_READ_REPORT_SENT,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
            }
            else
            {
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_ERROR_READ_REPORT_SENT,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
            }

            if (ret_code == JC_OK)
            {
                mmi_jmms_check_for_idle_screen();
            }

            break;
        case E_TYPE_IMMEDIATE_RETRIEVAL_FETCH:
        case E_TYPE_DEFFERED_RETRIEVAL_FETCH:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Communication state: MMS Download");
            jdi_CommunicationFreeReference(g_jmms_context->comm_handle, comm_node_p->reference_id);
            mmi_jmms_update_status_icon_indicator();
            if (comm_node_p->mms_communication_state == E_TYPE_DEFFERED_RETRIEVAL_FETCH)
            {

                if (calling_function == E_FROM_ERROR_CALLBACK)
                {
                    mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_DOWNLAOD);
                }
                else
                {
                    mmi_jmms_handle_error_string(error_code, E_TYPE_DEFFERED_RETRIEVAL_FETCH);
                }

            #ifdef __MMI_UNIFIED_MESSAGE__
                if (IsScreenPresent(SCR_ID_UM_INBOX))
                {
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_INBOX);        /* sachin */
                }
                else
                {
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, IDLE_SCREEN_ID); /* sachin */
                }
            #else /* __MMI_UNIFIED_MESSAGE__ */ 
                DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);
            #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            }
            else if (comm_node_p->mms_communication_state == E_TYPE_IMMEDIATE_RETRIEVAL_FETCH)
            {
                U16 screen_id = GetActiveScreenId();

            #if defined (__MMI_UNIFIED_MESSAGE__)
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) comm_node_p->msg_index,   /* sandeep pass message index in case of UM */
                            (U8) E_MSG_TYPE_RECEIVE,
                            NULL);
                if ((screen_id == IDLE_SCREEN_ID) || (screen_id == SCR_ID_UM_NEW_MSG_IND) ||
                    (screen_id == SCR_ID_UM_NEW_MSG_DUMMY_IND))
                {
                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_check_for_idle_screen();
                        if (mmi_jmms_need_mms_ind())
                        {
                            PlayMessageArrivalTone();
                        }
                    }
                }
            #else /* defined (__MMI_UNIFIED_MESSAGE__) */ 
                if (screen_id == IDLE_SCREEN_ID)
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_NEW_MMS_NOTIFICATION,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_check_for_idle_screen();
                        if (mmi_jmms_need_mms_ind())
                        {
                            PlayMessageArrivalTone();
                        }
                    }
                }
            #endif /* defined (__MMI_UNIFIED_MESSAGE__) */ 
                else
                {
                    mmi_jmms_show_new_mms_pop_up();
                }
            }
    }
#ifndef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_del_inserted_auto_signature_slide();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_error_string
 * DESCRIPTION
 *  This function displays appropriate popup according to the error code supplied
 * PARAMETERS
 *  error_code              [IN]        
 *  communication_state     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_error_string(JC_RETCODE error_code, U16 communication_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "mmi_jmms_handle_error_string, Error Code:", error_code);

    if (communication_state == E_TYPE_NEW_MMS)
    {
        /* /These are error code for Send Conf. Pdu reposne */
        switch (error_code)
        {
            case E_RESP_ERR_SENDING_ADDR_UNRESOLVED:
            case E_RESP_TRANSIENT_SENDING_ADDR_UNRESOLVED:
            case E_RESP_PERMANENT_SENDING_ADDRESS_UNRESOLVED:
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_ADDR_UNRESOLVED);
                return;
            case E_RESP_ERR_NETWORK_PROBLEM:
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_NETWORK_PROBLEM);
                return;
            case E_RESP_ERR_CONTENT_NOT_ACCEPTED:
            case E_RESP_ERR_UNSUPPORTED_MSG:
            case E_RESP_PERMANENT_MSG_FORMAT_CORRUPT:
            case E_RESP_PERMANENT_MSG_NOT_FOUND:
            case E_RESP_PERMANENT_CONTENT_NOT_ACCEPTED:
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_INVALID_MSG);
                return;

            case E_RESP_PERMANENT_REPLY_CHARGING_NOT_ACCEPTED:
            case E_RESP_PERMANENT_REPLY_CHARGING_FORWARD_DENIED:
            case E_RESP_PERMANET_REPLY_CHARGING_NOT_SUPPORTED:
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_REPLY_CHARGING);
                return;
            case E_RESP_PERMANENT_ADDRESS_HIDING_NOT_SUPPORTED:
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_ADDR_HIDING);
                return;

            case E_RESP_ERR_SERVICE_DENIED:
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_SERVER_DENIED);
                return;

        }

    }

    switch (error_code)
    {
        case JMMS_WRONG_CONTENT_TYPE_ERROR:
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_WRONG_CONTENT_TYPE);
            return;
        case 300:
        case 301:
        case 302:
        case 303:
        case 304:
        case 305:
        case 306:
        case 307:
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_REDIRECTION);
            return;
        case 400:
        case 401:
        case 402:
        case 403:
        case 404:
        case 405:
        case 406:
        case 407:
        case 408:
        case 409:
        case 410:
        case 411:
        case 412:
        case 413:
        case 414:
        case 415:
        case 416:
        case 417:
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_CLIENT);
            return;
        case 500:
        case 501:
        case 502:
        case 503:
        case 504:
        case 505:
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_SERVER);
            return;

        case JC_ERR_FILE_FULL:
            if (communication_state == E_TYPE_NEW_MMS)
            {
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_AND_FAIL_STORE_MEM_FULL);
            }
            else
            {
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_DOWNLAOD_STORE_FUL);
            }
            return;

        default:
            if (communication_state == E_TYPE_NEW_MMS)
            {
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
                return;
            }
            else if (communication_state == E_TYPE_DEFFERED_RETRIEVAL_FETCH)
            {
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_DOWNLAOD);
                return;
            }
    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_new_mms_pop_up
 * DESCRIPTION
 *  This function is used to show new MMS pop up when a new message has arrived and successfully saved.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_new_mms_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_show_new_mms_pop_up");

    /* added to suppress popup */
    if (KAL_FALSE == wap_is_new_msg_popup_handled())
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_show_new_mms_pop_up: Pop not supressed");

        screen_id = GetActiveScreenId();
    #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
        if ((screen_id == SCR_ID_JMMS_PROGRESS)
    #ifdef __MMI_UNIFIED_COMPOSER__
            || (screen_id == SCR_ID_UC_PROCESSING) || (screen_id == SCR_ID_UC_SENDING)
    #endif 
            )
        {
            playRequestedTone(SMS_IN_CALL_TONE);
            return;
        }
    #endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 

    #if defined (__USB_IN_NORMAL_MODE__) && !defined (__MMI_UNIFIED_MESSAGE__)
        if (mmi_jmms_check_usb_mode() == 0)
    #endif 
        {
        #if defined (__MMI_UNIFIED_MESSAGE__)
            if ((screen_id == IDLE_SCREEN_ID) || IsMMIInIdleState() || (screen_id == SCR_ID_UM_NEW_MSG_IND) ||
                (screen_id == SCR_ID_UM_NEW_MSG_DUMMY_IND))
        #else /* defined (__MMI_UNIFIED_MESSAGE__) */ 
            if (screen_id == IDLE_SCREEN_ID || IsMMIInIdleState())
        #endif /* defined (__MMI_UNIFIED_MESSAGE__) */ 
            {
                if (mmi_jmms_need_mms_ind())
                {
                    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
                    mmi_jmms_entry_new_mms_ind();
                    PlayMessageArrivalTone();
                }
            }
            else
            {
                if (!mmi_jmms_is_call_active() && (!AlmIsTonePlaying()))        /* if no call is there only then show it */
                {
                    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
                    mmi_msg_entry_new_msg_popup(MSG_NEW_JMMS_MMS);
                }
                else if (mmi_jmms_is_call_active())
                {
                    playRequestedTone(SMS_IN_CALL_TONE);
                }
            }
        }
    }
#ifndef __MMI_UNIFIED_MESSAGE__
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_show_new_mms_pop_up: Pop supressed");
        mmi_jmms_add_pending_mms_info_node((U16) STR_ID_JMMS_NEW_MMS, (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP, NULL);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_communication_progress_screen
 * DESCRIPTION
 *  Entry function for communication progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_UNIFIED_COMPOSER__
extern void mmi_jmms_cancel_mms_downloading(void);
#endif 
void mmi_jmms_entry_communication_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 len = 0;
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_entry_communication_progress_screen");

    EntryNewScreen(SCR_ID_JMMS_PROGRESS, NULL, mmi_jmms_entry_communication_progress_screen, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_PROGRESS);

    if (gui_buffer_p == NULL)
    {
        g_jmms_context->current_title_id = STR_MMS_MENUENTRY;
    }

    if (g_jmms_context->g_jmms_progress_str[0] == 0x00)
    {
        len = mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_PLEASE_WAIT));
        if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
        {
            mmi_ucs2ncpy(
                g_jmms_context->g_jmms_progress_str,
                GetString(STR_ID_JMMS_PLEASE_WAIT),
                (MAX_PROGRESS_SCREEN_HINT_LEN - 1));
        }
        else
        {
            mmi_ucs2cpy(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_JMMS_PLEASE_WAIT));

            if ((len + 1) < (MAX_PROGRESS_SCREEN_HINT_LEN))
            {
                mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, "\n");
            }
        }
    }
    gui_lock_double_buffer();
    ShowCategory66Screen(
        g_jmms_context->current_title_id,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_BACK,
        (U8*) (g_jmms_context->g_jmms_progress_str),
        IMG_ID_JMMS_PROGRESS,
        NULL);
#ifdef __MMI_JMMS_SEND_RETRIES__
    if (g_jmms_context->comm_state_p != NULL)
    {
        mmi_jmms_change_title_string(g_jmms_context->current_title_id, g_jmms_context->comm_state_p->retry_counter);
    }
    else
    {
        mmi_jmms_change_title_string(g_jmms_context->current_title_id, 1);
    }
#endif /* __MMI_JMMS_SEND_RETRIES__ */ 
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    ClearAllKeyHandler();
#ifdef __MMI_UNIFIED_COMPOSER__
    SetRightSoftkeyFunction(mmi_jmms_cancel_mms_downloading, KEY_EVENT_UP);
#else 
    SetRightSoftkeyFunction(mmi_jmms_cancel_mms_sending, KEY_EVENT_UP);
#endif 
    mmi_jmms_set_end_key_progressing_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_general_pop_screen_in_case_interupt
 * DESCRIPTION
 *  Entry function to show general pop up screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_general_pop_screen_in_case_interupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "mmi_jmms_entry_general_pop_screen_in_case_interupt: Pop not supressed");
    EntryNewScreen(SCR_ID_JMMS_POP_SCREEN, NULL, mmi_jmms_entry_general_pop_screen_in_case_interupt, NULL);
    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
    ShowCategory2Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_jmms_context->interupt_screen_title,
        NULL);

    if (g_jmms_context->interupt_screen_title == STR_ID_JMMS_MMS_DOWNLAOD_SUCCESS)
    {
        SetRightSoftkeyFunction(mmi_jmms_back_msg_download_sucess, KEY_EVENT_UP);
        if (!mmi_jmms_is_call_active())
        {
            SetKeyHandler(mmi_jmms_end_key_downlaod_sucess_pop_screen, KEY_END, KEY_EVENT_DOWN);        /* /delete the link list */
        }
    }
    else
    {
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_pop_up_for_interupt
 * DESCRIPTION
 *  This function is used to display error string
 * PARAMETERS
 *  strid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_pop_up_for_interupt(U16 strid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 k;
    MMI_BOOL ret;
    history hist;
    historyNode *saved_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_pop_up_for_interupt");

    if (GetActiveScreenId() != SCR_ID_JMMS_PROGRESS)
    {
        g_jmms_context->interupt_screen_title = strid;
        memset(&hist, 0, sizeof(history));

        if (GetCurrScrnId() == SCR_ID_JMMS_PROGRESS)
        {
            hist.scrnID = SCR_ID_JMMS_POP_SCREEN;
            hist.entryFuncPtr = mmi_jmms_entry_general_pop_screen_in_case_interupt;
            AddHistory(hist);
            /* This is a workaround to make sure that if small screen is the current screen on MMI.
               Its state is not changed and SCR_ID_JMMS_POP_SCREEN is not saved as small screen */
            GetHistoryPointer(SCR_ID_JMMS_POP_SCREEN, &saved_history);
            if (saved_history->isSmallScreen == 1)
            {
                saved_history->isSmallScreen = 0;
                set_small_screen();
            }
        }
        else
        {
            /* for test */
            ret = GetNextScrnIdOf(SCR_ID_JMMS_PROGRESS, &k);
            if (ret == MMI_TRUE)
            {
                hist.scrnID = SCR_ID_JMMS_POP_SCREEN;
                hist.entryFuncPtr = mmi_jmms_entry_general_pop_screen_in_case_interupt;
                InsertHistoryBeforeThisScrnReference(k, &hist);
            }

        }

    }
    else
    {
        if (strid == STR_ID_JMMS_SUCCESS_MMS_SENT || strid == STR_ID_JMMS_SUCCESS_MMS_SENT_ONLY)
        {
            DisplayPopup((U8*) GetString(strid), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        }
        else
        {
            DisplayPopup((U8*) GetString(strid), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_stop_communication
 * DESCRIPTION
 *  screen flow handling for stop communication
 * PARAMETERS
 *  comm_node_p     [IN]        
 *  error_code      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_stop_communication(mmi_jmms_communication_state_node_struct *comm_node_p, JC_RETCODE error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

#ifndef __MMI_UNIFIED_COMPOSER__
    JC_CHAR *folder_name_p = NULL;
    JC_CHAR out_box[7 * ENCODING_LENGTH];
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    JC_UINT32 reference_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d %s%d", "mmi_jmms_comm_stop_callback, Reference id: ", reference_id,
                         "Error code: ", error_code);

    if (NULL == comm_node_p)
    {
        return;
    }

    reference_id = comm_node_p->reference_id;
    if (error_code == JC_ERR_USER_CANCELLED)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS User Cancelled the Comunication Request");

        if (comm_node_p == NULL)
        {
            return;
        }

        if (comm_node_p->mms_communication_state == E_TYPE_NEW_JAVA_MMS_SEND)
        {
            if (g_jmms_context->jsr_mms_send_cancel_callback != NULL)
            {
                (*(g_jmms_context->jsr_mms_send_cancel_callback)) (JSR_RESULT_OK);
            }
            return;
        }
    #ifdef __MMI_UNIFIED_MESSAGE__
        if (mmi_um_get_current_msg_box_type() != UM_MSG_BOX_TYPE_UNSENT
            && g_jmms_context->save_mms == TRUE && g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
        {
            ret_code = mmi_jmms_send_and_store_mms(MMI_JMMS_OUTBOX, g_jmms_context->msg_handle, comm_node_p);
            if (ret_code == JC_OK)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_COMM_ABORTED_MMS_STORED),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
            }
            else
            {
                if (ret_code == E_MEMORY_FULL_ERROR)
                {
                    mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEMORY);
                }
                else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                {
                    mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEM_FULL);
                }
                else
                {
                    mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
                }
            }
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_COMM_ABORTED),
                IMG_GLOBAL_INFO,
                1,
                JMMS_POPUP_TIME,
                (U8) SUCCESS_TONE);
        }
        if (IsScreenPresent(SCR_ID_JMMS_WRITE_MMS))
        {
            DeleteUptoScrID(g_jmms_context->last_scr_id);
        }
        else if (IsScreenPresent(SCR_ID_UM_UNSENT))
        {
            DeleteUptoScrID(SCR_ID_UM_UNSENT);
        }
        else if (IsScreenPresent(SCR_ID_UM_DRAFT))
        {
            DeleteUptoScrID(SCR_ID_UM_DRAFT);
        }
        else if (IsScreenPresent(SCR_ID_UM_INBOX))
        {
            DeleteUptoScrID(SCR_ID_UM_INBOX);
        }
        else if (IsScreenPresent(SCR_ID_UM_SENT))
        {
            DeleteUptoScrID(SCR_ID_UM_SENT);
        }
        else if (g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
        {
            if (g_end_key_processing_handler)
            {
                g_end_key_processing_handler();
            }
        }

    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        ret_code = mmi_jmms_jdi_get_active_folder(g_jmms_context->hStoreHandle, &(folder_name_p), NULL);
        if (ret_code == JC_OK)
        {
            mmi_asc_to_ucs2((PS8) out_box, (PS8) MMI_JMMS_OUTBOX);
            if ((jc_tcscmp(out_box, folder_name_p) != 0)
                && (g_jmms_context->save_mms == TRUE) && (g_jmms_context->last_scr_id == IDLE_SCREEN_ID))
            {
                ret_code = mmi_jmms_send_and_store_mms(MMI_JMMS_OUTBOX, g_jmms_context->msg_handle, comm_node_p);
                if (ret_code == JC_OK)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_JMMS_COMM_ABORTED_MMS_STORED),
                        IMG_GLOBAL_INFO,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                }
                else
                {
                    if (ret_code == E_MEMORY_FULL_ERROR)
                    {
                        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEMORY);
                    }
                    else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                    {
                        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEM_FULL);
                    }
                    else
                    {
                        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
                    }
                }
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_COMM_ABORTED),
                    IMG_GLOBAL_INFO,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) SUCCESS_TONE);
            }
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_COMM_ABORTED),
                IMG_GLOBAL_INFO,
                1,
                JMMS_POPUP_TIME,
                (U8) SUCCESS_TONE);
        }

        DeleteUptoScrID(g_jmms_context->last_scr_id);
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }
    else
    {
    #ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
        if ((comm_node_p->mms_communication_state == E_TYPE_NEW_JAVA_MMS_SEND) &&
            (g_jmms_context->jsr_mms_send_cancel_callback != NULL))
        {
            (*(g_jmms_context->jsr_mms_send_cancel_callback)) (JSR_RESULT_ERROR);
            return;
        }
    #endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_end_key_progressing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_jmms_end_key_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_end_comm();
    g_end_key_processing_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_end_key_progressing_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_jmms_set_end_key_progressing_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_set_end_key_progressing_handler");
    if (!mmi_jmms_is_call_active())
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "End Key is Set for Communication");
        g_end_key_processing_handler = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_jmms_end_key_progressing, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_progress_ind
 * DESCRIPTION
 *  This function is used to show to the user the percentage of MMS sent.
 * PARAMETERS
 *  progress_ind_p              [IN]        
 *  communication_handle_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_progress_ind(
        COMM_PROGRESS_IND *progress_ind_p,
        mmi_jmms_communication_state_node_struct *communication_handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 percentage_of_progress = 0;
    S8 tmp_str_ascii[24] = {0, };
    S8 tmp_str_ucs2[48] = {0};
    S8 tmp_buff_ucs2[8] = {0};

    U32 len = 0, temp_len = 0;
    S32 size_kb = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->reference_id == communication_handle_p->reference_id)
    {
        if (g_jmms_context->progress_screen_title == STR_ID_PROGRESS_SENDING)
        {

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Screen ID: STR_ID_PROGRESS_SENDING");
            if (progress_ind_p->eStackStatus == E_COMM_STACK_CONNECTING)
            {

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Connecting Screen");

                len = mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_CONNECTING));
                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    len = (MAX_PROGRESS_SCREEN_HINT_LEN - 1);
                }

                memset(g_jmms_context->g_jmms_progress_str, 0, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);

                mmi_ucs2ncpy(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_JMMS_CONNECTING), len);
                mmi_asc_to_ucs2((S8*) tmp_buff_ucs2, (S8*) "\n");
                if ((S32) len < (MAX_PROGRESS_SCREEN_HINT_LEN - 1) - (mmi_ucs2strlen((S8*) tmp_buff_ucs2)))
                {
                    len = len + mmi_ucs2strlen((S8*) tmp_buff_ucs2);
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, (S8*) tmp_buff_ucs2);
                }
            }
            else if (progress_ind_p->eStackStatus == E_COMM_STACK_CONNECTED)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Connected for sending");
                if (!mmi_jmms_is_call_active() && (GetActiveScreenId() == SCR_ID_JMMS_PROGRESS))
                {
                    SetKeyHandler(mmi_jmms_end_comm, KEY_END, KEY_EVENT_DOWN);
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "End Key Not set in Progress_ind");
                }
                sprintf(tmp_str_ascii, "%d %%", percentage_of_progress);
                mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);

                len = mmi_ucs2strlen((S8*) GetString(STR_ID_PROGRESS_SENDING));
                mmi_asc_to_ucs2((S8*) tmp_buff_ucs2, (S8*) "\n");
                len = len + mmi_ucs2strlen((S8*) tmp_buff_ucs2);
                len = len + mmi_ucs2strlen(tmp_str_ucs2);

                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    len = 0;
                }

                memset(g_jmms_context->g_jmms_progress_str, 0, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);

                if (len != 0)
                {
                    mmi_ucs2cpy(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_PROGRESS_SENDING));
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, (S8*) tmp_buff_ucs2);
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, tmp_str_ucs2);
                }
                else
                {
                    mmi_ucs2cpy(g_jmms_context->g_jmms_progress_str, tmp_str_ucs2);
                }

            }
            else if (progress_ind_p->eStackStatus == E_COMM_STACK_SENDING)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS E_COMM_STACK_SENDING");

            #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
                mmi_jmms_stop_timeout_timer();
                StartTimer(JMMS_SEND_TIMEOUT_TIMER, MMI_JMMS_SEND_TIMEOUT_TIME, mmi_jmms_send_timeout_timer_hdlr);
                g_jmms_context->g_reference_id = communication_handle_p->reference_id;
            #endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 

                if (!mmi_jmms_is_call_active() && (GetActiveScreenId() == SCR_ID_JMMS_PROGRESS))
                {
                    SetKeyHandler(mmi_jmms_end_comm, KEY_END, KEY_EVENT_DOWN);
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "End Key Not set in Progress_ind");
                }
                if ((progress_ind_p->uiTotalBytesToSend) != 0)
                {
                    percentage_of_progress = (progress_ind_p->uiBytesSent) * 100;
                    percentage_of_progress = percentage_of_progress / (progress_ind_p->uiTotalBytesToSend);

                }

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "JMMS Sending Progress Percentage = ",
                                     percentage_of_progress);

                sprintf(tmp_str_ascii, "%d %%", percentage_of_progress);
                mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);

                len = mmi_ucs2strlen((S8*) GetString(STR_ID_PROGRESS_SENDING));
                mmi_asc_to_ucs2((S8*) tmp_buff_ucs2, (S8*) "\n");
                len = len + mmi_ucs2strlen((S8*) tmp_buff_ucs2);
                len = len + mmi_ucs2strlen(tmp_str_ucs2);

                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    len = 0;
                }

                memset(g_jmms_context->g_jmms_progress_str, 0, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);

                if (len != 0)
                {
                    mmi_ucs2cpy(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_PROGRESS_SENDING));
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, (S8*) tmp_buff_ucs2);
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, tmp_str_ucs2);
                }
                else
                {
                    mmi_ucs2cpy(g_jmms_context->g_jmms_progress_str, tmp_str_ucs2);
                }

            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Stack Status=%d Connect=%d Sent=%d",
                                     progress_ind_p->eStackStatus, progress_ind_p->eDataConnectionStatus,
                                     progress_ind_p->uiBytesSent);

            }

        }
        else if (g_jmms_context->progress_screen_title == STR_ID_JMMS_MMS_DOWNLOADING)
        {

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Screen ID: STR_ID_PROGRESS_DOWNLOADING");
            if (progress_ind_p->eStackStatus == E_COMM_STACK_CONNECTING)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Connecting Screen");

                memset(g_jmms_context->g_jmms_progress_str, 0, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);

                len = mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_MMS_RECEIVED));
                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    mmi_ucs2ncpy(
                        g_jmms_context->g_jmms_progress_str,
                        GetString(STR_ID_JMMS_CONNECTING),
                        (MAX_PROGRESS_SCREEN_HINT_LEN - 1));
                }
                else
                {
                    mmi_ucs2cpy(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_JMMS_CONNECTING));
                    mmi_asc_to_ucs2((S8*) tmp_buff_ucs2, (S8*) "\n");
                    len = len + mmi_ucs2strlen((S8*) tmp_buff_ucs2);
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, (S8*) tmp_buff_ucs2);
                }
            }
            else if (progress_ind_p->eStackStatus == E_COMM_STACK_RECEIVING)
            {
                if (progress_ind_p->uiBytesRecvd > mmi_jmms_retrieval_settings_msg_size_filter())
                {
                    mmi_jmms_cancel_mms_downloading();
                    DisplayPopup(
                        (U8*) GetString(STR_ID_JMMS_OPTIONS_MSG_SIZE_EXCEED),
                        IMG_GLOBAL_INFO,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) SUCCESS_TONE);
                    return;
                }
                memset(g_jmms_context->g_jmms_progress_str, 0, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);

                if ((progress_ind_p->uiBytesRecvd) != 0)
                {
                    percentage_of_progress = (progress_ind_p->uiBytesRecvd);

                }

                size_kb = progress_ind_p->uiBytesRecvd / 1024;
                if (size_kb >= 1)
                {
                    size_kb++;
                    sprintf(tmp_str_ascii, "%d", size_kb);
                }
                else
                {
                    sprintf(tmp_str_ascii, "%d", percentage_of_progress);
                }

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Downloading Bytes = ", percentage_of_progress);

                mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);

                len = mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_MMS_RECEIVED));
                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    mmi_ucs2ncpy(
                        g_jmms_context->g_jmms_progress_str,
                        GetString(STR_ID_JMMS_MMS_RECEIVED),
                        (MAX_PROGRESS_SCREEN_HINT_LEN - 1));
                    goto END;
                }

                mmi_ucs2cpy(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_JMMS_MMS_RECEIVED));
                temp_len = len;
                mmi_asc_to_ucs2((S8*) tmp_buff_ucs2, (S8*) "\n");
                len = len + mmi_ucs2strlen((S8*) tmp_buff_ucs2);
                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    mmi_ucs2ncat(
                        g_jmms_context->g_jmms_progress_str,
                        (S8*) tmp_buff_ucs2,
                        ((MAX_PROGRESS_SCREEN_HINT_LEN - 1) - temp_len));
                    goto END;
                }

                mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, (S8*) tmp_buff_ucs2);
                temp_len = len;
                len = len + mmi_ucs2strlen(tmp_str_ucs2);
                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    mmi_ucs2ncat(
                        g_jmms_context->g_jmms_progress_str,
                        tmp_str_ucs2,
                        ((MAX_PROGRESS_SCREEN_HINT_LEN - 1) - temp_len));
                    goto END;
                }

                mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, tmp_str_ucs2);
                temp_len = len;
                mmi_asc_to_ucs2((S8*) tmp_buff_ucs2, (S8*) " ");
                len = len + mmi_ucs2strlen((S8*) tmp_buff_ucs2);
                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    mmi_ucs2ncat(
                        g_jmms_context->g_jmms_progress_str,
                        (S8*) tmp_buff_ucs2,
                        ((MAX_PROGRESS_SCREEN_HINT_LEN - 1) - temp_len));
                    goto END;
                }

                mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, (S8*) tmp_buff_ucs2);
                temp_len = len;
                if (size_kb >= 1)
                {
                    len = len + mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_KILO_BYTES));
                    if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                    {
                        mmi_ucs2ncat(
                            g_jmms_context->g_jmms_progress_str,
                            GetString(STR_ID_JMMS_KILO_BYTES),
                            ((MAX_PROGRESS_SCREEN_HINT_LEN - 1) - temp_len));
                        goto END;
                    }
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_JMMS_KILO_BYTES));
                }
                else
                {
                    len = len + mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_BYTES));
                    if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                    {
                        mmi_ucs2ncat(
                            g_jmms_context->g_jmms_progress_str,
                            GetString(STR_ID_JMMS_BYTES),
                            ((MAX_PROGRESS_SCREEN_HINT_LEN - 1) - temp_len));
                        goto END;
                    }
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_JMMS_BYTES));
                }
                temp_len = len;
                mmi_asc_to_ucs2((S8*) tmp_buff_ucs2, (S8*) " ");
                len = len + mmi_ucs2strlen((S8*) tmp_buff_ucs2);
                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    mmi_ucs2ncat(
                        g_jmms_context->g_jmms_progress_str,
                        (S8*) tmp_buff_ucs2,
                        ((MAX_PROGRESS_SCREEN_HINT_LEN - 1) - temp_len));
                    goto END;
                }
                mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, (S8*) tmp_buff_ucs2);

                len = len + mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_KILO_BYTES));
                if (len > (MAX_PROGRESS_SCREEN_HINT_LEN - 1))
                {
                    mmi_ucs2ncat(
                        g_jmms_context->g_jmms_progress_str,
                        GetString(STR_ID_JMMS_KILO_BYTES),
                        ((MAX_PROGRESS_SCREEN_HINT_LEN - 1) - temp_len));
                    goto END;
                }
            }
        }
        else
        {
            return;
        }

      END:
        if (GetActiveScreenId() == SCR_ID_JMMS_PROGRESS)
        {
        #ifdef __MMI_JMMS_SEND_RETRIES__
            mmi_jmms_change_title_string(g_jmms_context->current_title_id, communication_handle_p->retry_counter);
        #endif 
            cat66_update_progress_string();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_and_send_new_mms_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_and_send_new_mms_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "mmi_jmms_create_and_send_new_mms_async_callback, Ret Code:",
                         ret_code);
    if (JC_OK != ret_code)
    {
    #ifndef __MMI_UNIFIED_COMPOSER__
        mmi_jmms_del_inserted_auto_signature_slide();
    #endif 
        if (ret_code == E_JMMS_STORAGE_FULL)
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_STORE_FUL);
        }
        /* Added by - Raj Kumar Gupta on 31 August, 2006 */
        else if (ret_code == E_COMMUNICATION_ABORTED)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_COMM_ABORTED),
                IMG_GLOBAL_INFO,
                1,
                JMMS_POPUP_TIME,
                (U8) SUCCESS_TONE);
        }
        else
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
        }
        mmi_jmms_free_message_header();
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_new_mms_send_response_asynch_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_new_mms_send_response_asynch_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_new_mms_send_response_asynch_callback");

    if (JC_OK != ret_code)
    {
        mmi_jmms_free_message_header();
        if (ret_code == E_JMMS_STORAGE_FULL)
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_STORE_FUL);
        }
        /* Added by - Raj Kumar Gupta on 31 August, 2006 */
        else if (ret_code == E_COMMUNICATION_ABORTED)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_COMM_ABORTED),
                IMG_GLOBAL_INFO,
                1,
                JMMS_POPUP_TIME,
                (U8) SUCCESS_TONE);
        }
        else
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
        }
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);
    }
}

#ifdef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_handle_new_mms_send_response_asynch_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_handle_new_mms_send_response_asynch_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s[%d]", "mmi_jmms_uc_handle_new_mms_send_response_asynch_callback: ",
                         ret_code);

    if (JC_OK != ret_code)
    {
        mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;
        mmi_jmms_uc_sending_complete_struct sending_complete_data = {0, };

        communication_handle_p = mmi_jmms_get_comm_state(g_jmms_context, g_jmms_context->reference_id);
        sending_complete_data.result = MMI_FALSE;
        sending_complete_data.communication_handle_p = communication_handle_p;
        communication_handle_p->callback(MMS_SENDING_COMPELETE_CALLBACK, (void*)&sending_complete_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_handle_new_mms_send_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_p           [IN]        
 *  content_data        [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_handle_new_mms_send_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_p,
            CONTENT_DATA *content_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_HEADERS *msg_header_p = NULL;
    EMM1MessageType e_msg;
    U8 num_retries = 0;
    S8 temp_version[MAX_VERSION_LENGTH + 1];
    JC_RETCODE ret_code = JC_OK;
    MSG_HANDLE temp_msg_handle = NULL;
    mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;
    mmi_jmms_uc_sending_complete_struct sending_complete_data = {0, };
    MESSAGE_SEND_RESPONSE *send_header_p = NULL;
    JC_UINT32 msg_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_uc_handle_new_mms_send_response");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&temp_msg_handle, content_data, E_TYPE_MMS, E_FALSE);

    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(temp_msg_handle);
    }

    if (ret_code != JC_OK)
    {
        goto END;
    }
    ret_code = mmi_jmms_jdi_get_msg_headers(temp_msg_handle, &msg_header_p);
    if (ret_code != JC_OK)
    {
        goto END;
    }
    e_msg = msg_header_p->eMsgType;

    switch (msg_header_p->eMsgType)
    {
        case E_MSG_TYPE_SEND_RESPONSE:
        {
            U8 *temp_uniocde_url = NULL;

            send_header_p = (MESSAGE_SEND_RESPONSE*) msg_header_p->pHeaders;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "JMMS_UC send response, Status:", send_header_p->eStatus);

        #ifdef __MMI_JMMS_TEST_RESPONSE_TIMEOUT__
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "No Response from Server......");
            return -1;
        #endif /* __MMI_JMMS_TEST_RESPONSE_TIMEOUT__ */ 

        #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
            if (g_jmms_context->send_status & TIMER_RESPONSE_BIT)
            {
                g_jmms_context->send_status &= ~TIMER_RESPONSE_BIT;     /* reset first bit set by timer */
                goto END2;
            }
            mmi_jmms_stop_timeout_timer();
        #endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 

            if (E_RESP_OK == send_header_p->eStatus)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS_UC send response: OK");

            #ifdef __MMI_JMMS_SEND_RETRIES__
                mmi_jmms_set_progress_screen_title(0);
            #endif 

                num_retries = jmms_context_p->sent_retry_counter;

                temp_uniocde_url = mmi_jmms_get_activated_mmsc_url(jmms_context_p);
                jmms_context_p->last_mmsc_url = (S8*) temp_uniocde_url;

                strcpy((PS8) jmms_context_p->last_version, (PS8) send_header_p->pVersion);

                if (num_retries >= 1)   /* /MMS was sent in 2 retries due to version problem */
                {                       /* store such mmsc urls in a file */
                    /* /wrie/update the MMSC URL and version into file */
                    mmi_jmms_update_mmsc_url_version(jmms_context_p->last_mmsc_url, jmms_context_p->last_version);

                }
                ret_code = JC_OK;
                mmi_jmms_deinit_mms_context(jmms_context_p);
                goto END;
            }
            else
            {
                if (send_header_p->eStatus == E_RESP_ERR_UNSUPPORTED_MSG
                    || send_header_p->eStatus == E_RESP_ERR_MESG_NOT_FOUND
                    || send_header_p->eStatus == E_RESP_ERR_MSG_FORMAT_CORRUPT)
                {
                    jmms_context_p->sent_retry_counter++;

                    if (jmms_context_p->sent_retry_counter >= 3)
                    {
                        ret_code = -1;
                        goto END;
                    }
                    else
                    {
                        strcpy((PS8) temp_version, (PS8) "1.0");

                        if (strcmp((S8*) jmms_context_p->version, (S8*) temp_version) == 0)
                        {
                            strcpy((PS8) jmms_context_p->version, (PS8) "1.1");
                        }
                        else
                        {
                            strcpy((PS8) temp_version, (PS8) "1.1");
                            if (strcmp((S8*) jmms_context_p->version, (S8*) temp_version) == 0)
                            {
                                strcpy((PS8) jmms_context_p->version, (PS8) "1.2");
                            }
                            else
                            {
                                strcpy((PS8) temp_version, (PS8) "1.2");
                                if (strcmp((S8*) jmms_context_p->version, (S8*) temp_version) == 0)
                                {
                                    strcpy((PS8) jmms_context_p->version, (PS8) "1.0");
                                }
                                else
                                {
                                    ret_code = -1;
                                    goto END;
                                }
                            }
                        }
                    }

                    if (NULL != temp_msg_handle)
                    {
                        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
                        temp_msg_handle = NULL;
                    }
                    // remove the respective message ID from the list as resend ing of MMS will be
                    // like sending a new MMS.
                    communication_handle_p = mmi_jmms_get_comm_state(g_jmms_context, url_ind_p->uiRequestID);
                    msg_id = mmi_jmms_uc_get_msgid(communication_handle_p);
                    mmi_jmms_uc_remove_send_node(msg_id);

                    mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);

                    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_p->uiRequestID);
                    if (JC_OK != ret_code)
                    {
                        url_ind_p->uiRequestID = 0;

                        mmi_jmms_free_message_header();
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d",
                                             "mmi_jmms_uc_handle_new_mms_send_response returns with:%d (version problem)",
                                             ret_code);
                        return ret_code;
                    }
                    url_ind_p->uiRequestID = 0;

                    /* Register the function that to be execute after the completion of the 
                       encapsulation */
                    mmi_jmms_add_send_callback_node(mmi_jmms_uc_handle_new_mms_send_response_asynch_callback);
                    mmi_jmms_uc_send_mms(jmms_context_p->msg_handle, msg_id);
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d",
                                         "mmi_jmms_uc_handle_new_mms_send_response returns with:%d (version problem)",
                                         ret_code);
                    return JC_OK;
                }

                else if (send_header_p->eStatus == E_RESP_ERR_NETWORK_PROBLEM ||
                         send_header_p->eStatus == E_RESP_ERR_SERVICE_DENIED)
                {
                    /* /added for retry mechanism */
                    if (url_ind_p->uiRequestID)
                    {
                        ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_p->uiRequestID);
                        if (JC_OK != ret_code)
                        {
                            url_ind_p->uiRequestID = 0;
                            ret_code = -1;
                            goto END;
                        }
                    }

                    ret_code = mmi_jmms_retry_communication(
                                jmms_context_p,
                                E_FROM_URL_CALLBACK,
                                url_ind_p->uiRequestID,
                                send_header_p->eStatus);

                    if (ret_code != JC_OK)
                    {
                        goto END;
                    }
                    mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);
                    url_ind_p->uiRequestID = 0;
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d",
                                         "mmi_jmms_uc_handle_new_mms_send_response returns with:%d (network problem[%d])",
                                         ret_code, send_header_p->eStatus);
                    return ret_code;
                }
                else
                {
                    ret_code = -1;
                    goto END;
                }
            }
        }
    }

  END:

    communication_handle_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_p->uiRequestID);
    if (ret_code != JC_OK)
    {
        sending_complete_data.result = MMI_FALSE;
        sending_complete_data.error_code = send_header_p->eStatus;
    #ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
        if (send_header_p->pStatusText)
        {
            mmi_ucs2ncpy(
                (S8*) sending_complete_data.response_text,
                (S8*) send_header_p->pStatusText,
                MAX_RESPONSE_TEXT_LENGTH);
        }
    #endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
    }
    else
    {
        sending_complete_data.result = MMI_TRUE;
        sending_complete_data.error_code = JC_OK;
    }
    sending_complete_data.communication_handle_p = communication_handle_p;
    ASSERT(communication_handle_p);
    communication_handle_p->callback(MMS_SENDING_COMPELETE_CALLBACK, (void*)&sending_complete_data);

    mmi_jmms_free_message_header();
    mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);
    if (NULL != temp_msg_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
    }

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_p->uiRequestID);
#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
  END2:
#endif 
    url_ind_p->uiRequestID = 0;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "mmi_jmms_uc_handle_new_mms_send_response returns with:%d", ret_code);
    return ret_code;
}

#else /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_new_mms_send_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_p           [IN]        
 *  content_data        [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_new_mms_send_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_p,
            CONTENT_DATA *content_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MESSAGE_HEADERS *msg_header_p = NULL;
    EMM1MessageType e_msg;

    U8 num_retries = 0;
    S8 temp_version[MAX_VERSION_LENGTH + 1];
    JC_RETCODE ret_code = JC_OK;
    MSG_HANDLE temp_msg_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_new_mms_send_response");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&temp_msg_handle, content_data, E_TYPE_MMS, E_FALSE);

    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(temp_msg_handle);
    }

    if (ret_code != JC_OK)
    {
        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
        goto END;
    }
    ret_code = mmi_jmms_jdi_get_msg_headers(temp_msg_handle, &msg_header_p);
    if (ret_code != JC_OK)
    {
        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
        goto END;
    }
    e_msg = msg_header_p->eMsgType;

    switch (msg_header_p->eMsgType)
    {
        case E_MSG_TYPE_SEND_RESPONSE:
        {
            MESSAGE_SEND_RESPONSE *send_header_p = (MESSAGE_SEND_RESPONSE*) msg_header_p->pHeaders;
            U8 *temp_uniocde_url = NULL;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "JMMS send response, Status:", send_header_p->eStatus);

            /* if first bit is set it means timer has processed the response */
        #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
            if (g_jmms_context->send_status & TIMER_RESPONSE_BIT)
            {
                g_jmms_context->send_status &= ~TIMER_RESPONSE_BIT;     /* reset first bit set by timer */
                goto END2;
            }
            mmi_jmms_stop_timeout_timer();
        #endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 

            if (E_RESP_OK == send_header_p->eStatus)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS send response: OK");

            #ifdef __MMI_JMMS_SEND_RETRIES__
                mmi_jmms_set_progress_screen_title(0);
            #endif 

                num_retries = jmms_context_p->sent_retry_counter;

                temp_uniocde_url = (U8*) mmi_jmms_get_activated_mmsc_url(jmms_context_p);

                /* / replace temp_uniocde_url by url set in message settings */
                jmms_context_p->last_mmsc_url = (S8*) temp_uniocde_url;

                strcpy((PS8) jmms_context_p->last_version, (PS8) send_header_p->pVersion);

                if (num_retries >= 1)   /* /MMS was sent in 2 retries due to version problem */
                {                       /* store such mmsc urls in a file */
                    /* /wrie/update the MMSC URL and version into file */
                    mmi_jmms_update_mmsc_url_version(jmms_context_p->last_mmsc_url, jmms_context_p->last_version);
                }

                if (g_jmms_context->save_mms == MMI_TRUE)
                {
                    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS send response: Save MMS True");

                    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_p->uiRequestID);

                    if (comm_node_p == NULL)
                    {
                        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MMS_SENT_NOT_SAVE);
                    }
                    else
                    {
                        ret_code = mmi_jmms_send_and_store_mms("Sent", jmms_context_p->msg_handle, comm_node_p);

                        if (ret_code == JC_OK)
                        {
                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_SUCCESS_MMS_SENT);
                        }
                        else
                        {

                            if (ret_code == E_MEMORY_FULL_ERROR)
                            {
                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MMS_SENT_NOT_SAVE_MEMORY);
                            }
                            else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                            {
                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MMS_SENT_NOT_SAVE_MEMORY_FULL);
                            }
                            else
                            {
                                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MMS_SENT_NOT_SAVE);
                            }
                        }

                    }

                }
                else
                {

                    mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_SUCCESS_MMS_SENT_ONLY);
                }

            #ifdef __MMI_UNIFIED_MESSAGE__
                if (IsScreenPresent(SCR_ID_JMMS_OUTBOX_OPTIONS))
                {
                    mmi_jmms_outbox_delete_on_sent();
                }
                else if (IsScreenPresent(SCR_ID_JMMS_DRAFTS_OPTIONS))
                {
                    mmi_jmms_drafts_delete_on_sent();
                }
                else if (IsScreenPresent(SCR_ID_JMMS_PREVIEW))
                {
                    DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 5);
                }
                else if (!IsScreenPresent(SCR_ID_UM_MAIN))
                {
                    DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 3);
                }
                else
                {
                    DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 4);
                }

            #else /* __MMI_UNIFIED_MESSAGE__ */ 
                if (IsScreenPresent(SCR_ID_JMMS_INBOX))
                {
                    DeleteUptoScrID(SCR_ID_JMMS_INBOX);
                }
                else if (IsScreenPresent(SCR_ID_JMMS_OUTBOX))
                {
                    DeleteUptoScrID(SCR_ID_JMMS_OUTBOX);
                }
                if (g_jmms_context->last_scr_id == SCR_ID_JMMS_OUTBOX_OPTIONS)
                {
                    mmi_jmms_outbox_delete_on_sent();

                }
                else if (g_jmms_context->last_scr_id == SCR_ID_JMMS_DRAFTS_OPTIONS)
                {
                    mmi_jmms_drafts_delete_on_sent();
                }
                else
                {
                    DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 3);

                }
            #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                mmi_jmms_deinit_mms_context(jmms_context_p);

                mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);

                goto END1;
            }
            else
            {
                if (send_header_p->eStatus == E_RESP_ERR_UNSUPPORTED_MSG
                    || send_header_p->eStatus == E_RESP_ERR_MESG_NOT_FOUND
                    || send_header_p->eStatus == E_RESP_ERR_MSG_FORMAT_CORRUPT)

                {
                    jmms_context_p->sent_retry_counter++;

                    if (jmms_context_p->sent_retry_counter >= 3)        /* /TODO:: may need to change to 3 i.e. also for 1.1 */
                    {
                        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
                        goto END;
                    }
                    else
                    {
                        if (GetActiveScreenId() == SCR_ID_JMMS_PROGRESS)
                        {
                            g_jmms_context->current_title_id = STR_ID_JMMS_RETRY;
                        #ifdef __MMI_JMMS_SEND_RETRIES__
                            mmi_jmms_change_title_string(STR_ID_JMMS_RETRY, jmms_context_p->sent_retry_counter);
                        #else /* __MMI_JMMS_SEND_RETRIES__ */ 
                            ChangeTitleString((U8*) GetString(STR_ID_JMMS_RETRY));
                            draw_title();
                        #endif /* __MMI_JMMS_SEND_RETRIES__ */ 
                            cat66_update_progress_string();
                        }
                        /* Sandeep Start 16 Nov to fix MAUI00226856 */
                        strcpy((PS8) temp_version, (PS8) "1.0");

                        if (strcmp((S8*) jmms_context_p->version, (S8*) temp_version) == 0)
                        {
                            strcpy((PS8) jmms_context_p->version, (PS8) "1.1");
                        }
                        else
                        {
                            strcpy((PS8) temp_version, (PS8) "1.1");
                            if (strcmp((S8*) jmms_context_p->version, (S8*) temp_version) == 0)
                            {
                                strcpy((PS8) jmms_context_p->version, (PS8) "1.2");
                            }
                            else
                            {
                                strcpy((PS8) temp_version, (PS8) "1.2");
                                if (strcmp((S8*) jmms_context_p->version, (S8*) temp_version) == 0)
                                {
                                    strcpy((PS8) jmms_context_p->version, (PS8) "1.0");
                                }
                                else
                                {
                                    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

                                    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_p->uiRequestID);
                                    ret_code = mmi_jmms_send_and_store_mms("Outbox", jmms_context_p->msg_handle, comm_node_p);
                                    if (ret_code == JC_OK)
                                    {

                                    #ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
                                        if (send_header_p->pStatusText)
                                        {
                                            mmi_ucs2ncpy(
                                                (S8*) g_jmms_context->response_text,
                                                (S8*) send_header_p->pStatusText,
                                                MAX_RESPONSE_TEXT_LENGTH);
                                            mmi_jmms_handle_pop_up_for_interupt_string((JC_CHAR*) g_jmms_context->
                                                                                       response_text);
                                        }
                                        else
                                    #endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
                                        {
                                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_AND_STORED);
                                        }
                                        goto END;
                                    }
                                    else
                                    {
                                        if (ret_code == E_MEMORY_FULL_ERROR)
                                        {
                                            mmi_jmms_handle_pop_up_for_interupt
                                                (STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEMORY);
                                            goto END;
                                        }
                                        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                                        {
                                            mmi_jmms_handle_pop_up_for_interupt
                                                (STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEM_FULL);
                                            goto END;
                                        }
                                        else
                                        {
                                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
                                            goto END;
                                        }
                                    }
                                }
                            }
                        }

                        /* Sandeep end 16 Nov to fix MAUI00226856 */

                        if (NULL != temp_msg_handle)
                        {
                            mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
                            temp_msg_handle = NULL;
                        }

                        mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);

                        ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_p->uiRequestID);
                        if (JC_OK != ret_code)
                        {
                            url_ind_p->uiRequestID = 0;

                            mmi_jmms_free_message_header();
                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);

                            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);

                            return ret_code;
                        }
                        url_ind_p->uiRequestID = 0;

                        /* Register the function that to be execute after the completion of the 
                           encapsulation */
                        mmi_jmms_add_send_callback_node(mmi_jmms_handle_new_mms_send_response_asynch_callback);
                        mmi_jmms_send_mms(jmms_context_p->msg_handle, E_TYPE_NEW_MMS, E_TRUE, 1, E_TRUE
                    #ifdef __MMI_UNIFIED_COMPOSER__
                                          , mmi_jmms_handle_screen_flow_callback
                    #endif 
                            );
                        return JC_OK;
                    }
                }
                else if (send_header_p->eStatus == E_RESP_ERR_NETWORK_PROBLEM ||        // TODO:: need to check right status
                         send_header_p->eStatus == E_RESP_ERR_SERVICE_DENIED)
                {

                    /* /added for retry mechanism */
                    if (url_ind_p->uiRequestID)
                    {

                        ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_p->uiRequestID);
                        if (JC_OK != ret_code)
                        {

                            /* 2 March -- need care */
                            mmi_jmms_free_message_header();

                            mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);
                            url_ind_p->uiRequestID = 0;
                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);

                            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);

                            return ret_code;
                        }

                    }

                    ret_code = mmi_jmms_retry_communication(
                                jmms_context_p,
                                E_FROM_URL_CALLBACK,
                                url_ind_p->uiRequestID,
                                send_header_p->eStatus);
                    if (JC_OK != ret_code && ret_code != E_JMMS_RETRY_COMPLETE) /* /if ret_code=E_JMMS_RETRY_COMPLETE then it means error already handled */
                    {
                        mmi_jmms_free_message_header();
                        mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);
                        url_ind_p->uiRequestID = 0;

                    #ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
                        if (send_header_p->pStatusText)
                        {
                            mmi_ucs2ncpy(
                                (S8*) g_jmms_context->response_text,
                                (S8*) send_header_p->pStatusText,
                                MAX_RESPONSE_TEXT_LENGTH);
                            mmi_jmms_handle_pop_up_for_interupt_string((JC_CHAR*) g_jmms_context->response_text);
                        }
                        else
                    #endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
                        {
                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
                        }

                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);

                        return ret_code;

                    }

                    mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);

                    url_ind_p->uiRequestID = 0;

                    return ret_code;
                }
                else
                {
                    /* Dilip Start 24 Aug 2006 */
                #ifdef __MMI_UNIFIED_MESSAGE__
                    if (IsScreenPresent(SCR_ID_UM_UNSENT))
                    {
                        DeleteUptoScrID(SCR_ID_UM_UNSENT);
                    }
                    else if (IsScreenPresent(SCR_ID_UM_DRAFT))
                    {
                        DeleteUptoScrID(SCR_ID_UM_DRAFT);
                    }
                    else if (IsScreenPresent(SCR_ID_UM_INBOX))
                    {
                        DeleteUptoScrID(SCR_ID_UM_INBOX);
                    }
                    else if (IsScreenPresent(SCR_ID_UM_SENT))
                    {
                        DeleteUptoScrID(SCR_ID_UM_SENT);
                    }
                #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                    mmi_jmms_handle_error_string(send_header_p->eStatus, E_TYPE_NEW_MMS);
                }
            }
        }
            break;

        default:
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_UNABLE_PARSE_SENT_RESPONSE);

    }   /* /end of  switch(msg_header_p->eMsgType) */

  END:
#ifndef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_del_inserted_auto_signature_slide();
#endif 
    DeleteScreenIfPresent(SCR_ID_JMMS_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_JMMS_SENT_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_JMMS_DRAFTS_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_JMMS_OUTBOX_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_WRITE_MMS_DONE_OPTIONS);
    mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);

  END1:

    mmi_jmms_free_message_header();

    if (NULL != temp_msg_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
    }

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_p->uiRequestID);

  END2:
    url_ind_p->uiRequestID = 0;
    return ret_code;
}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_deffered_downlaod_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_p           [IN]        
 *  content_data        [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_deffered_downlaod_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_p,
            CONTENT_DATA *content_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
    MMI_BOOL flag = MMI_FALSE;
#endif 
    JC_RETCODE ret_code = JC_OK;
    MSG_HANDLE temp_msg_handle = NULL;
    MESSAGE_HEADERS *msg_header_p = NULL;
    JC_INT8 *content_type = NULL;
    MMI_BOOL intterupt_handling = MMI_FALSE;

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    MESSAGE_RETRIEVAL *receive_msg_headers_p = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_deffered_downlaod_response");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&temp_msg_handle, content_data, E_TYPE_MMS, E_FALSE);

    /* Async changes start */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(temp_msg_handle);
    }
    /* Async changes end */

    if (JC_OK != ret_code)
    {
        goto EndofDeferredcase;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(temp_msg_handle, &msg_header_p);
    if (ret_code != JC_OK || msg_header_p == NULL)
    {
        goto EndofDeferredcase;
    }

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    receive_msg_headers_p = (MESSAGE_RETRIEVAL*) msg_header_p->pHeaders;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: (%d)", "receive_msg_headers_p->eStatus", receive_msg_headers_p->eStatus);
    if (E_RESP_OK != receive_msg_headers_p->eStatus && receive_msg_headers_p->pStatusText)
    {
        mmi_ucs2ncpy(
            (S8*) g_jmms_context->response_text,
            (S8*) receive_msg_headers_p->pStatusText,
            MAX_RESPONSE_TEXT_LENGTH);
        mmi_jmms_handle_pop_up_for_interupt_string((JC_CHAR*) g_jmms_context->response_text);
    #ifdef __MMI_UNIFIED_MESSAGE__
        HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_INBOX);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        goto EndofDeferredcase;
    }
#endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
    mmi_jmms_update_status_icon_indicator();
#ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
    ret_code = mmi_jmms_get_content_type(content_data, &content_type);
    if (ret_code == JC_OK)
    {
        flag = mmi_jsr_check_recv_mms_for_java(content_type);

        if (flag == MMI_TRUE)
        {
            mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

            comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_p->uiRequestID);
            if (comm_node_p == NULL)
            {
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SAVING);

                if (g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
                {
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, IDLE_SCREEN_ID);
                }
                else
                {
                #ifdef __MMI_UNIFIED_MESSAGE__
                    HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_INBOX);
                #else /* __MMI_UNIFIED_MESSAGE__ */ 
                    HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
                #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                }

            }
            else
            {

                ///putting here the ACK.as found that stroe_update change the file name
                ///so require to use before that
                jmms_mmi_ack_for_deffered_retrieval(*content_data);
                ret_code = mmi_jmms_store_update_message(
                            "Inbox",
                            &(comm_node_p->msg_index),
                            msg_header_p,
                            content_data,
                            0x20000000);
                if (ret_code != JC_OK)
                {
                    mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SAVING);

                    if (g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
                    {
                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, IDLE_SCREEN_ID);
                    }
                    else
                    {
                    #ifdef __MMI_UNIFIED_MESSAGE__
                        HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_INBOX);
                    #else /* __MMI_UNIFIED_MESSAGE__ */ 
                        HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
                    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                    }
                }
                else
                {
                #ifdef __MMI_UNIFIED_MESSAGE__
                    mmi_jmms_set_msg_type(
                        (U8) (g_jmms_context->store_context->num_msg_in_curr_folder - comm_node_p->msg_index),
                        E_MSG_JAVA_MESSAGE);
                #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                    if (GetActiveScreenId() != SCR_ID_JMMS_PROGRESS)
                    {
                        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_NEW_JAVA_MMS);
                    }
                    else
                    {
                        mmi_jmms_update_status_icon_indicator();
                        mmi_msg_entry_new_msg_popup(MSG_NEW_JMMS_JAVA_MMS);
                    }

                    if (g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
                    {
                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, IDLE_SCREEN_ID);
                    }
                    else
                    {
                    #ifdef __MMI_UNIFIED_MESSAGE__
                        HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_INBOX);
                    #else /* __MMI_UNIFIED_MESSAGE__ */ 
                        HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
                        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
                    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                    }
                }

            }

            ret_code = JC_OK;
            if (content_type != NULL)
            {
                jdd_MemFree(content_type);
                content_type = NULL;
            }

            goto EndofDeferredcase;
        }
    }
    if (content_type != NULL)
    {
        jdd_MemFree(content_type);
        content_type = NULL;
    }

#endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 

    ret_code = mmi_jmms_handle_deffered_retrieved_mms((*content_data));

    if (ret_code == JC_OK)
    {
        if (GetActiveScreenId() != SCR_ID_JMMS_PROGRESS)
        {
            intterupt_handling = MMI_TRUE;
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MMS_DOWNLAOD_SUCCESS);
        }

        if (g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
        {
            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, IDLE_SCREEN_ID);
        }
        else
        {
        #ifdef __MMI_UNIFIED_MESSAGE__
            HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_INBOX);
        #else /* __MMI_UNIFIED_MESSAGE__ */ 
            HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        }
    }

    if (ret_code != E_UNKNOWN_MSG)
    {
        JC_RETCODE error_code = JC_OK;
        mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

        comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_p->uiRequestID);
        if (comm_node_p == NULL)
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SAVING);

            if (g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
            {
                DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, IDLE_SCREEN_ID);
            }
            else
            {
            #ifdef __MMI_UNIFIED_MESSAGE__
                HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
                DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
            #else /* __MMI_UNIFIED_MESSAGE__ */ 
                HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
                DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
            #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            }

        }
        else
        {
            ///putting here the ACK.as found that stroe_update change the file name
            ///so require to use before that
            jmms_mmi_ack_for_deffered_retrieval(*content_data);

            error_code = mmi_jmms_store_update_message("Inbox", &(comm_node_p->msg_index), msg_header_p, content_data, 0);
            if (error_code != JC_OK)
            {
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SAVING);

                if (g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
                {
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, IDLE_SCREEN_ID);
                }
                else
                {
                #ifdef __MMI_UNIFIED_MESSAGE__
                    HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
                #else /* __MMI_UNIFIED_MESSAGE__ */ 
                    HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
                #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                }

            }
            else
            {
            #ifdef __MMI_UNIFIED_MESSAGE__
                mmi_jmms_set_msg_type(
                    (U8) (g_jmms_context->store_context->num_msg_in_curr_folder - comm_node_p->msg_index),
                    E_MSG_RECEIVE);
            #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                if (intterupt_handling == MMI_FALSE)
                {
                    g_jmms_context->is_unread_msg_deleted = 0;
                    mmi_jmms_set_msg_as_read((U8) ((comm_node_p->msg_index) - 1));

                #ifdef __MMI_UNIFIED_MESSAGE__
                    g_jmms_context->show_property_screen = MMI_TRUE;
                #endif 
                    mmi_jmms_handle_read_report(g_jmms_context->msg_header_type_p);
                }
                else
                {
                    mmi_jmms_set_progress_screen_title((U16) (comm_node_p->msg_index));
                }

                jmms_context_p->mms_index = comm_node_p->msg_index;
            }
        }
    }

  EndofDeferredcase:

    if (content_type != NULL)
    {
        jdd_MemFree(content_type);
        content_type = NULL;
    }

    mmi_jmms_free_comm_node(jmms_context_p, url_ind_p->uiRequestID);

    if (NULL != temp_msg_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
        temp_msg_handle = NULL;
    }

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_p->uiRequestID);

    url_ind_p->uiRequestID = 0;

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_error_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  error string           on success
 *****************************************************************************/
mma_result_enum mmi_jmms_get_error_type(JC_RETCODE error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_code)
    {
        case JC_OK:
            return MMA_RESULT_OK;
        case E_RESP_ERR_SENDING_ADDR_UNRESOLVED:
        case E_RESP_TRANSIENT_SENDING_ADDR_UNRESOLVED:
        case E_RESP_PERMANENT_SENDING_ADDRESS_UNRESOLVED:
            return MMA_RESULT_FAIL_COMM_CONNECT_ERROR;
        case E_RESP_ERR_NETWORK_PROBLEM:
            return MMA_RESULT_FAIL_COMM_CONNECT_ERROR;
        case E_RESP_ERR_CONTENT_NOT_ACCEPTED:
        case E_RESP_ERR_UNSUPPORTED_MSG:
        case E_RESP_PERMANENT_MSG_FORMAT_CORRUPT:
        case E_RESP_PERMANENT_MSG_NOT_FOUND:
        case E_RESP_PERMANENT_CONTENT_NOT_ACCEPTED:
            return MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;
        case E_RESP_PERMANENT_REPLY_CHARGING_NOT_ACCEPTED:
        case E_RESP_PERMANENT_REPLY_CHARGING_FORWARD_DENIED:
        case E_RESP_PERMANET_REPLY_CHARGING_NOT_SUPPORTED:
            return MMA_RESULT_FAIL;
        case E_RESP_PERMANENT_ADDRESS_HIDING_NOT_SUPPORTED:
            return MMA_RESULT_FAIL;
        case E_RESP_ERR_SERVICE_DENIED:
            return MMA_RESULT_FAIL_COMM_SERVICE_DENIED;
        case JMMS_WRONG_CONTENT_TYPE_ERROR:
            return MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
        case 300:
        case 301:
        case 302:
        case 303:
        case 304:
        case 305:
        case 306:
        case 307:
            return MMA_RESULT_FAIL;
        case 400:
        case 401:
        case 402:
        case 403:
        case 404:
        case 405:
        case 406:
        case 407:
        case 408:
        case 409:
        case 410:
        case 411:
        case 412:
        case 413:
        case 414:
        case 415:
        case 416:
        case 417:
            return MMA_RESULT_FAIL;
        case 500:
        case 501:
        case 502:
        case 503:
        case 504:
        case 505:
            return MMA_RESULT_FAIL;
        case JC_ERR_FILE_FULL:
            return MMA_RESULT_FAIL_INSUFFICIENT_STORAGE;
        case JC_ERR_DATA_CONN_TIMEOUT:
            return MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT;
        default:
            return MMA_RESULT_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_error_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  error string           on success
 *****************************************************************************/
U8 *mmi_jmms_get_error_string(JC_RETCODE error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_code)
    {
        case JC_OK:
            if (g_jmms_context->save_mms == MMI_TRUE)
            {
                return ((U8*) GetString(STR_ID_JMMS_SUCCESS_MMS_SENT));
            }
            else
            {
                return ((U8*) GetString(STR_ID_JMMS_SUCCESS_MMS_SENT_ONLY));
            }
        case E_RESP_ERR_SENDING_ADDR_UNRESOLVED:
        case E_RESP_TRANSIENT_SENDING_ADDR_UNRESOLVED:
        case E_RESP_PERMANENT_SENDING_ADDRESS_UNRESOLVED:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_ADDR_UNRESOLVED));
        case E_RESP_ERR_NETWORK_PROBLEM:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_NETWORK_PROBLEM));
        case E_RESP_ERR_CONTENT_NOT_ACCEPTED:
        case E_RESP_ERR_UNSUPPORTED_MSG:
        case E_RESP_PERMANENT_MSG_FORMAT_CORRUPT:
        case E_RESP_PERMANENT_MSG_NOT_FOUND:
        case E_RESP_PERMANENT_CONTENT_NOT_ACCEPTED:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_INVALID_MSG));
        case E_RESP_PERMANENT_REPLY_CHARGING_NOT_ACCEPTED:
        case E_RESP_PERMANENT_REPLY_CHARGING_FORWARD_DENIED:
        case E_RESP_PERMANET_REPLY_CHARGING_NOT_SUPPORTED:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_REPLY_CHARGING));
        case E_RESP_PERMANENT_ADDRESS_HIDING_NOT_SUPPORTED:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_ADDR_HIDING));
        case E_RESP_ERR_SERVICE_DENIED:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_SERVER_DENIED));
        case JMMS_WRONG_CONTENT_TYPE_ERROR:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_WRONG_CONTENT_TYPE));
        case 300:
        case 301:
        case 302:
        case 303:
        case 304:
        case 305:
        case 306:
        case 307:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_REDIRECTION));
        case 400:
        case 401:
        case 402:
        case 403:
        case 404:
        case 405:
        case 406:
        case 407:
        case 408:
        case 409:
        case 410:
        case 411:
        case 412:
        case 413:
        case 414:
        case 415:
        case 416:
        case 417:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_CLIENT));
        case 500:
        case 501:
        case 502:
        case 503:
        case 504:
        case 505:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_SERVER));
        case JC_ERR_FILE_FULL:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_MMS_SENT_AND_FAIL_STORE_MEM_FULL));
        default:
            return ((U8*) GetString(STR_ID_JMMS_ERROR_MMS_SENT));
    }
}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
#else /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_jmmsprotocolscrhandling_fun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_jmmsprotocolscrhandling_fun(void)
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
#endif /* __MMI_JMMSPROTSCRHANDLING_C */ 

