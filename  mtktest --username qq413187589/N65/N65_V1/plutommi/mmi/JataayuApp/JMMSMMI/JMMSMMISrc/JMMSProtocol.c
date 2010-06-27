/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  JMMSProtocol.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for handling the send and recieve  PDUs for MMS
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/*  Include: MMI header file */
#include "MMI_include.h"
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
#include "gpioInc.h"
#include "Msg_MMSDecoder.h"
#include "wgui_status_icons.h"
#ifdef __MMI_UNIFIED_COMPOSER__
#include "MMSAdp.h"
#endif 
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
#ifndef __MMI_UNIFIED_COMPOSER__
static void mmi_jmms_end_key_progressing(void);
static void mmi_jmms_set_end_key_progressing_handler(void);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* have to declare it here as its decalartion is not present in any .h */
extern em_wap_user_agent_brand_enum wap_get_user_agent_brand(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_init_protocol
 * DESCRIPTION
 *  Inits protocol by registering functions for communication.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_init_protocol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    JC_TASK_INFO app_task_info = {0, };
    JC_TASK_INFO transport_task_info = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_init_protocol");

    app_task_info.iTaskID = (JC_INT32) E_TASK_MMS_UI;
    app_task_info.iAppID = (JC_INT32) E_TASK_MMS_UI;
    transport_task_info.iTaskID = (JC_INT32) E_TASK_TRANSPORT;
    transport_task_info.iAppID = (JC_INT32) E_TASK_TRANSPORT;

    ret_code = jdi_CommunicationInitialize(&app_task_info, &transport_task_info, g_jmms_context, &g_jmms_context->comm_handle);
    if (JC_OK != ret_code)
    {
        goto error;
    }

    ret_code = jdi_CommunicationRegisterHeaderCallback(
                g_jmms_context->comm_handle,
                (COMM_URL_IND_HEADER_FNC) mmi_jmms_header_ind_callback);
    if (JC_OK != ret_code)
    {
        goto error;
    }

    ret_code = jdi_CommunicationRegisterURLIndCallback(
                g_jmms_context->comm_handle,
                (COMM_URL_IND_RESPONSE_FNC) mmi_jmms_url_ind_callback);
    if (JC_OK != ret_code)
    {
        goto error;
    }

    ret_code = jdi_CommunicationRegisterStopIndCallback(
                g_jmms_context->comm_handle,
                (COMM_STOP_IND_FNC) mmi_jmms_comm_stop_callback);
    if (JC_OK != ret_code)
    {
        goto error;
    }

    ret_code = jdi_CommunicationRegisterPushIndCallback(
                g_jmms_context->comm_handle,
                (COMM_PUSH_IND_FNC) mmi_jmms_push_ind_callback);
    if (JC_OK != ret_code)
    {
        goto error;
    }

    ret_code = jdi_CommunicationRegisterErrIndCallback(
                g_jmms_context->comm_handle,
                (COMM_ERR_IND_FNC) mmi_jmms_error_ind_callback);
    if (JC_OK != ret_code)
    {
        goto error;
    }

    ret_code = jdi_CommunicationRegisterProgressIndCallback(
                g_jmms_context->comm_handle,
                (COMM_PROGRESS_IND_FNC) mmi_jmms_progress_ind_callback);
    if (JC_OK != ret_code)
    {
        goto error;
    }

    ret_code = mmi_jmms_set_profile();

  error:
    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_progress_ind_callback
 * DESCRIPTION
 *  Used to show the user the number of bytes send/downloaded.
 * PARAMETERS
 *  jmms_context_p          [IN]        
 *  reference_id            [IN]        
 *  progress_ind_data_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_progress_ind_callback(
        mmi_jmms_context_struct *jmms_context_p,
        JC_UINT32 reference_id,
        COMM_PROGRESS_IND *progress_ind_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;
    mmi_jmms_comm_progress_struct progress_ind_data = {0, };
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    JC_UINT32 percentage_of_progress = 0;
    S8 tmp_str_ascii[20] = {0, };
    S8 tmp_str_ucs2[40] = {0};
    S8 tmp_buff_ucs2[5] = {0};

    U32 len = 0, temp_len = 0;
    S32 size_kb = 0;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* /update only for Deffered Downlaod/New MMS Send */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS mmi_jmms_progress_ind_callback, with reference_id",
                         reference_id);

#ifdef __MMI_UNIFIED_COMPOSER__
    communication_handle_p = mmi_jmms_get_comm_state(jmms_context_p, reference_id);

    if (communication_handle_p && communication_handle_p->callback)
    {
        progress_ind_data.progress_ind_p = progress_ind_data_p;
        progress_ind_data.communication_handle_p = communication_handle_p;
        communication_handle_p->callback(MMS_COMMUNICATION_PROGRESS_CALLBACK, (void*)&progress_ind_data);

    #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
        if (communication_handle_p->mms_communication_state == E_TYPE_NEW_MMS
            && communication_handle_p->percent_sent > 0)
        {
            mmi_jmms_stop_timeout_timer();
            StartTimer(JMMS_SEND_TIMEOUT_TIMER, MMI_JMMS_SEND_TIMEOUT_TIME, mmi_jmms_send_timeout_timer_hdlr);
            g_jmms_context->g_reference_id = reference_id;
        }
    #endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 
    }
    else if (communication_handle_p &&
             (communication_handle_p->mms_communication_state == E_TYPE_IMMEDIATE_RETRIEVAL_FETCH))
    {
        if (progress_ind_data_p->uiBytesRecvd > mmi_jmms_retrieval_settings_msg_size_filter())
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Stopping Immediate Retrival due to over size");
            jdi_CommunicationStopReq(g_jmms_context->comm_handle, communication_handle_p->reference_id);
            mmi_jmms_add_pending_mms_info_node((U16) communication_handle_p->msg_index, (U8) E_MSG_TYPE_RECEIVE, NULL);
            mmi_jmms_show_new_mms_pop_up();
            mmi_jmms_free_comm_node(g_jmms_context, communication_handle_p->reference_id);
        }
    }
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    if (g_jmms_context->reference_id == reference_id)
    {

        if (g_jmms_context->progress_screen_title == STR_ID_PROGRESS_SENDING)
        {

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Screen ID: STR_ID_PROGRESS_SENDING");
            if (progress_ind_data_p->eStackStatus == E_COMM_STACK_CONNECTING)
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
            else if (progress_ind_data_p->eStackStatus == E_COMM_STACK_CONNECTED)
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
            else if (progress_ind_data_p->eStackStatus == E_COMM_STACK_SENDING)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS E_COMM_STACK_SENDING");

            #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
                mmi_jmms_stop_timeout_timer();
                StartTimer(JMMS_SEND_TIMEOUT_TIMER, MMI_JMMS_SEND_TIMEOUT_TIME, mmi_jmms_send_timeout_timer_hdlr);
                g_jmms_context->g_reference_id = reference_id;
            #endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 

                if (!mmi_jmms_is_call_active() && (GetActiveScreenId() == SCR_ID_JMMS_PROGRESS))
                {
                    SetKeyHandler(mmi_jmms_end_comm, KEY_END, KEY_EVENT_DOWN);
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "End Key Not set in Progress_ind");
                }
                if ((progress_ind_data_p->uiTotalBytesToSend) != 0)
                {
                    percentage_of_progress = (progress_ind_data_p->uiBytesSent) * 100;
                    percentage_of_progress = percentage_of_progress / (progress_ind_data_p->uiTotalBytesToSend);

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
                                     progress_ind_data_p->eStackStatus, progress_ind_data_p->eDataConnectionStatus,
                                     progress_ind_data_p->uiBytesSent);

            }

        }
        else if (g_jmms_context->progress_screen_title == STR_ID_JMMS_MMS_DOWNLOADING)
        {

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Screen ID: STR_ID_PROGRESS_DOWNLOADING");
            if (progress_ind_data_p->eStackStatus == E_COMM_STACK_CONNECTING)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Connecting Screen");

                memset(g_jmms_context->g_jmms_progress_str, 0, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);

                len = mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_MMS_DOWNLOADING));
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
            else if (progress_ind_data_p->eStackStatus == E_COMM_STACK_RECEIVING)
            {
                memset(g_jmms_context->g_jmms_progress_str, 0, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);

                if ((progress_ind_data_p->uiBytesRecvd) != 0)
                {
                    percentage_of_progress = (progress_ind_data_p->uiBytesRecvd);

                }

                size_kb = progress_ind_data_p->uiBytesRecvd / 1024;
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
                    mmi_ucs2cat(g_jmms_context->g_jmms_progress_str, GetString(STR_ID_JMMS_KB));
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
            cat66_update_progress_string();
        }

    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_profile
 * DESCRIPTION
 *  Sets profile for MMS sending
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    COMM_PROFILE profile = {0, };
    JC_RETCODE ret_code = JC_OK;
    U8 connect_type;
    GENERIC_DATA_CONN data_conn;
    U8 ip_address[16] = {0x00};

    nvram_mms_profile_content_struct *activated_mms_profile_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_set_profile");

    activated_mms_profile_p = mmi_ph_get_activated_mms_profile();

    connect_type = activated_mms_profile_p->conn_type;

    jc_memset(&profile, 0, sizeof(COMM_PROFILE));

    mmi_jmms_get_ip_address(ip_address, activated_mms_profile_p->proxy_ip);

    if (connect_type == PH_CONN_TYPE_HTTP)
    {

        if (activated_mms_profile_p->proxy_port == 0)
        {
            profile.eConnMode = E_COMM_WPHTTP_DIRECT;
            jc_strcpy(profile.szHostName, (JC_INT8*) ip_address);
            profile.uiPortNumber = activated_mms_profile_p->proxy_port;
        }
        else
        {
            profile.eConnMode = E_COMM_WPHTTP_PROXY;
            jc_strcpy(profile.szHostName, (JC_INT8*) ip_address);
            profile.uiPortNumber = activated_mms_profile_p->proxy_port;
        }

    }
    else if (connect_type == PH_CONN_TYPE_CONNECTION_OREINTED)
    {
        profile.eConnMode = E_COMM_WSP_CONNECTION_ORIENTED;
        jc_strcpy(profile.szHostName, (JC_INT8*) ip_address);
        profile.uiPortNumber = 0;
    }
    else
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    ret_code = jdi_CommunicationProfile(g_jmms_context->comm_handle, &profile);
    if (ret_code != JC_OK)
    {
        goto ERROR_HANDLE;
    }

    data_conn.account_id = activated_mms_profile_p->data_account;
    ret_code = jdi_CommunicationDataConnection(g_jmms_context->comm_handle, (const GENERIC_DATA_CONN*)&data_conn);

  ERROR_HANDLE:

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "mmi_jmms_set_profile return:", ret_code);

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_ip_address
 * DESCRIPTION
 *  Used to get the IP address
 * PARAMETERS
 *  ip_address_p        [OUT]       
 *  proxy_ip_p          [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_get_ip_address(U8 *ip_address_p, U8 *proxy_ip_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[4] = {0x00};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((S8*) ip_address_p, "%d", proxy_ip_p[0]);
    strcat((S8*) ip_address_p, ".");
    sprintf((S8*) temp, "%d", proxy_ip_p[1]);
    strcat((S8*) ip_address_p, (S8*) temp);
    strcat((S8*) ip_address_p, ".");
    memset(temp, 0x00, 4);
    sprintf((S8*) temp, "%d", proxy_ip_p[2]);
    strcat((S8*) ip_address_p, (S8*) temp);
    strcat((S8*) ip_address_p, ".");
    memset(temp, 0x00, 4);
    sprintf((S8*) temp, "%d", proxy_ip_p[3]);
    strcat((S8*) ip_address_p, (S8*) temp);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_activated_mmsc_url
 * DESCRIPTION
 *  Used to get the MMSC URL
 * PARAMETERS
 *  jmms_context_p      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_jmms_get_activated_mmsc_url(mmi_jmms_context_struct *jmms_context_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *mmsc_url_p = NULL;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_get_activated_mmsc_url");
    mmsc_url_p = mmi_ph_mms_get_activated_profile_mmsc_url();   /* //for getting the mmsc url */
    if (mmsc_url_p == NULL)
    {
        return NULL;
    }
    len = (strlen((S8*) mmsc_url_p) + 1) * ENCODING_LENGTH;

    if (jmms_context_p->activated_mmsc_url_p != NULL)
    {
        jdd_MemFree(jmms_context_p->activated_mmsc_url_p);
    }
    jmms_context_p->activated_mmsc_url_p = (U8*) jdd_MemAlloc(sizeof(U8), len);
    if (jmms_context_p->activated_mmsc_url_p == NULL)
    {
        return NULL;
    }

    mmi_asc_to_ucs2((PS8) (jmms_context_p->activated_mmsc_url_p), (PS8) mmsc_url_p);

    return (jmms_context_p->activated_mmsc_url_p);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_push_ind_callback
 * DESCRIPTION
 *  used to process push message.
 * PARAMETERS
 *  comm_arg_p              [IN]        
 *  push_content_ind_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_push_ind_callback(void *comm_arg_p, COMM_PUSH_IND *push_content_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    CONTENT_DATA view_content_data = {0, };

    MSG_HANDLE msg_handle = NULL;
    MESSAGE_HEADERS *msg_headers = NULL;
    MESSAGE_NOTIFICATION *notify_ind_headers_p;
    JC_UINT32 screen_id = 0;
    JC_UINT32 msg_index = 0;

    /* JC_UINT32 msgid = 0; */
    U8 number_mms = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_push_ind_callback");
    if (!wap_is_ready())
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS: WAP is not ready");
        return;
    }
    if (mmi_jmms_is_ready_without_store(0))
    {
        g_jmms_context->interupt_screen_title = STR_ID_JMMS_MEMORY_ERROR_NEW_MMS_NOTIF_SAVING;
        screen_id = GetActiveScreenId();
        ret_code = mmi_jmms_add_pending_mms_info_node(
                    (U16) STR_ID_JMMS_MEMORY_ERROR_NEW_MMS_NOTIF_SAVING,
                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                    NULL);
        if (ret_code == JC_OK)
        {
            mmi_jmms_check_for_idle_screen();
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS: Store is not ready");
        return;
    }
    ret_code = mmi_jmms_get_total_number_of_messages(&number_mms);
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "JMMS Bad Store Module, Return Code: ", ret_code);
        ASSERT(0) return;
    }

    if (number_mms >= MAX_POSSIBLE_MESSAGES_THRESHOLD)
    {
        mmi_jmms_update_status_icon_indicator();
    }

    if (number_mms >= MAX_POSSIBLE_MESSAGES)
    {
        mmi_jmms_add_memory_full_node_if_not_already();
        return;
    }

    if (NULL != push_content_ind_p->pszContentType)
    {
        if (0 == jc_strcmp(push_content_ind_p->pszContentType, "application/vnd.wap.mms-message"))
        {

            view_content_data.uiCurSize = view_content_data.uiTotalSize = push_content_ind_p->uiLength;
            /* view_content_data.VIEW_MODE.contentInline.buffer_p = (JC_INT8 *)push_content_ind_p->buffer_p  ; */
            view_content_data.pBuffer = (JC_UINT8*) push_content_ind_p->pBuffer;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS: Message parsing for Message header starts");
            ret_code = mmi_jmms_jdi_parse_msg_buffer(&msg_handle, &view_content_data, E_TYPE_MMS, E_FALSE);

            /* Async changes start */
            while (ret_code == JC_ERR_MMS_PARSE_PENDING)
            {
                ret_code = mmi_jmms_jdi_msg_parse_continue(msg_handle);
            };
            /* Async changes end */

            if (JC_OK != ret_code)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS, Error in parsing message headers, Error code: ",
                                     ret_code);
                if (msg_handle != NULL)
                {
                    mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
                    msg_handle = NULL;
                }

                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_UNABLE_PARSE_PUSH,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
                if (ret_code == JC_OK)
                {
                    mmi_jmms_check_for_idle_screen();
                }
                return;
            }
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS: Message parsing for Message header SUCCESSFUL!!!");
            ret_code = mmi_jmms_jdi_get_msg_headers(msg_handle, &msg_headers);
            if (JC_OK != ret_code)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS, Error in getting message headers, Error code",
                                     ret_code);
                mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
                msg_handle = NULL;

                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_UNABLE_PARSE_PUSH,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
                if (ret_code == JC_OK)
                {
                    mmi_jmms_check_for_idle_screen();
                }
                return;
            }

            if (msg_headers->eMsgType == E_MSG_TYPE_DELIVERY_REPORT)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Push Indication for JMMS Delivery Report Received");
                /* save the delivery report in inbox */
                {
                    JC_UINT32 temp_extra_byte = 0x20000000;

                    ret_code = mmi_jmms_save_message_buffer_in_Store(
                                "Inbox",
                                &msg_index,
                                msg_headers,
                                &view_content_data,
                                &temp_extra_byte);
                }
                if (ret_code == JC_OK)
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) msg_index,
                                (U8) E_MSG_TYPE_DELIVERY_REPORT,
                                NULL);

                    if (JC_OK == ret_code)
                    {
                        ret_code = mmi_jmms_add_pending_mms_delivery_report_node(
                                    (U8) (((DELIVERY_REPORT*) msg_headers->pHeaders)->eDeliveryStatus),
                                    (S8 *) (((DELIVERY_REPORT*) msg_headers->pHeaders)->pTo),
                                    ((DELIVERY_REPORT*) msg_headers->pHeaders)->uiDate);
                    }
                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_show_new_mms_pop_up();
                        mmi_jmms_update_status_icon_indicator();
                    #ifndef __MMI_UNIFIED_MESSAGE__
                        mmi_jmms_refresh_inbox_no_screen_update();
                    #endif 
                    }
                }
                if (ret_code != JC_OK)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)",
                                         "JMMS, Error in saving Delivery Report, Error code: ", ret_code);
                    if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_MEMORY_ERROR_DELIVERY_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    }
                    else
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_ERROR_DELIVERY_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    }

                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }
                mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
                msg_handle = NULL;
                return;
            }
            else if (msg_headers->eMsgType == E_MSG_TYPE_READ_REPORT_RESPONSE)
            {
                // TODO:::need to test the read report PDU
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Push Indication for JMMS Read Report received");

                ret_code = mmi_jmms_add_pending_mms_info_node((U16) msg_index, (U8) E_MSG_TYPE_READ_REPORT_RESPONSE, NULL);
                if (ret_code == JC_OK)
                {
                    ret_code = mmi_jmms_add_pending_mms_read_report_node(
                                (U8) (((READ_REPORT_RESPONSE*) msg_headers->pHeaders)->eReadStatus),
                                (S8 *) (((READ_REPORT_RESPONSE*) msg_headers->pHeaders)->pFrom),
                                ((READ_REPORT_RESPONSE*) msg_headers->pHeaders)->uiReceivedTime);

                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_show_new_mms_pop_up();
                        mmi_jmms_update_status_icon_indicator();
                    }
                }
                /* /save the read report in inbox. */
                {
                    JC_UINT32 temp_extra_byte = 0x20000000;

                    ret_code = mmi_jmms_save_message_buffer_in_Store(
                                "Inbox",
                                &msg_index,
                                msg_headers,
                                &view_content_data,
                                &temp_extra_byte);
                }
                if (ret_code != JC_OK)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS, Error in saving Read Report, Error code",
                                         ret_code);
                    if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_MEMORY_ERROR_READ_REPORT_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    }
                    else
                    {
                        ret_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_ERROR_READ_REPORT_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    }
                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }

                mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
                msg_handle = NULL;
                return;
            }
            else if (msg_headers->eMsgType != E_MSG_TYPE_NOTIFICATION)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS, Invalid Message Type", msg_headers->eMsgType);
                mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
                msg_handle = NULL;
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_UNABLE_PARSE_PUSH,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
                if (ret_code == JC_OK)
                {
                    mmi_jmms_check_for_idle_screen();
                }
                return;
            }

            ///Transaction ID should be in ASCII
            //otherwise need changes

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS: Push Indication for JMMS Notification received");

            notify_ind_headers_p = (MESSAGE_NOTIFICATION*) msg_headers->pHeaders;

            if (g_jmms_context->transaction_id_p != NULL)
            {
                if (strcmp(notify_ind_headers_p->pTransactionID, g_jmms_context->transaction_id_p) == 0)
                {
                    mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
                    msg_handle = NULL;
                    return;
                }
                jdd_MemFree(g_jmms_context->transaction_id_p);
            }
            g_jmms_context->transaction_id_p =
                (JC_INT8*) jdd_MemAlloc(sizeof(JC_INT8), strlen(notify_ind_headers_p->pTransactionID) + 1);
            if (g_jmms_context->transaction_id_p != NULL)
            {
                strcpy(g_jmms_context->transaction_id_p, notify_ind_headers_p->pTransactionID);
            }

            mmi_jmms_handle_new_mms_notification(&view_content_data, msg_handle, notify_ind_headers_p);

            if (NULL != msg_handle)
            {
                ret_code = mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
                if (JC_OK != ret_code)
                {
                    return;
                }
                msg_handle = NULL;
            }

        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_add_pending_mms_delivery_report_node
 * DESCRIPTION
 *  Adds pending mms delivery report node
 * PARAMETERS
 *  status              [IN]        
 *  to_address_p        [IN]        
 *  date                [IN]        
 * RETURNS
 *  JC_OK           on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_add_pending_mms_delivery_report_node(U8 status, S8 *to_address_p, JC_UINT32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_pending_mms_delivery_reports_struct *node_p;
    U16 screen_id;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_add_pending_mms_delivery_report_node");
    screen_id = GetActiveScreenId();

    node_p =
        (mmi_jmms_pending_mms_delivery_reports_struct*)
        jdd_MemAlloc(sizeof(mmi_jmms_pending_mms_delivery_reports_struct), 1);
    if (node_p == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    node_p->status = status;
    node_p->date = date;

    if (to_address_p != NULL)
    {
        len = (mmi_ucs2strlen((S8*) to_address_p) + 1) * ENCODING_LENGTH;
        node_p->to_p = (S8*) jdd_MemAlloc(sizeof(S8), len);
        if (node_p->to_p == NULL)
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }

        memcpy(node_p->to_p, to_address_p, len);
    }
    else
    {
        node_p->to_p = NULL;
    }

    if (screen_id == SCR_ID_JMMS_NEW_MMS_IND &&
        (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_DELIVERY_REPORT))
    {   /* /add as second node of link list */
        if (g_jmms_context->pending_delivery_reports == NULL)   /* /not possible */
        {
            return E_JMMS_GENERAL_ERROR;
        }
        else
        {
            node_p->next_p = g_jmms_context->pending_delivery_reports->next_p;
            g_jmms_context->pending_delivery_reports->next_p = node_p;
        }

    }
    else    /* /add as first node of link list */
    {
        node_p->next_p = g_jmms_context->pending_delivery_reports;
        g_jmms_context->pending_delivery_reports = node_p;
    }
    return JC_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_add_pending_mms_read_report_node
 * DESCRIPTION
 *  Adds pending mms read report node
 * PARAMETERS
 *  status              [IN]        
 *  from_address_p      [IN]        
 *  date                [IN]        
 * RETURNS
 *  JC_OK on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_add_pending_mms_read_report_node(U8 status, S8 *from_address_p, JC_UINT32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_pending_mms_read_reports_struct *node_p;
    U16 screen_id;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    screen_id = GetActiveScreenId();

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_add_pending_mms_read_report_node");

    node_p =
        (mmi_jmms_pending_mms_read_reports_struct*) jdd_MemAlloc(sizeof(mmi_jmms_pending_mms_read_reports_struct), 1);
    if (node_p == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    node_p->status = status;
    node_p->date = date;

    if (from_address_p != NULL)
    {
        len = (mmi_ucs2strlen((S8*) from_address_p) + 1) * ENCODING_LENGTH;
        node_p->from_p = (S8*) jdd_MemAlloc(sizeof(S8), len);
        if (node_p->from_p == NULL)
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }

        memcpy(node_p->from_p, from_address_p, len);
    }
    else
    {
        node_p->from_p = NULL;
    }

    if (screen_id == SCR_ID_JMMS_NEW_MMS_IND &&
        (g_jmms_context->pending_mms_info_list->type == E_MSG_TYPE_READ_REPORT_RESPONSE))
    {                                                       /* /add as second node of link list */
        if (g_jmms_context->pending_read_reports == NULL)   /* /not possible */
        {
            return E_JMMS_GENERAL_ERROR;
        }
        else
        {
            node_p->next_p = g_jmms_context->pending_read_reports->next_p;
            g_jmms_context->pending_read_reports->next_p = node_p;
        }

    }
    else    /* /add as first node of link list */
    {

        node_p->next_p = g_jmms_context->pending_read_reports;
        g_jmms_context->pending_read_reports = node_p;
    }
    return JC_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_add_pending_mms_info_node
 * DESCRIPTION
 *  Adds pending MMS node
 * PARAMETERS
 *  msg_index               [IN]        
 *  msg_type                [IN]        
 *  content_location_p      [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_add_pending_mms_info_node(U16 msg_index, U8 msg_type, S8 *content_location_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_jmms_pending_mms_info_struct *node_p;
    U16 screen_id;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_add_pending_mms_info_node");

#ifdef __MMI_UNIFIED_MESSAGE__
    if (msg_type != E_MSG_TYPE_IDLE_SCREEN_POP_UP
#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
        && msg_type != E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER
#endif 
        )
    {
        TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
        mmi_um_jmms_new_mms_message_ind(msg_index);
        return JC_OK;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    screen_id = GetActiveScreenId();

    node_p = (mmi_jmms_pending_mms_info_struct*) jdd_MemAlloc(sizeof(mmi_jmms_pending_mms_info_struct), 1);
    if (node_p == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    node_p->index = msg_index;
    node_p->type = msg_type;

    if (content_location_p != NULL)
    {
    #ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
        if (msg_type == E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER)
        {
            len = mmi_ucs2strlen((S8*) content_location_p) + 1;
            node_p->mms_url_p = (S8*) jdd_MemAlloc(sizeof(JC_CHAR), len);
            if (node_p->mms_url_p == NULL)
            {
                return JC_ERR_MEMORY_ALLOCATION;
            }
            mmi_ucs2cpy(node_p->mms_url_p, content_location_p);
        }
        else
    #endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
        {
            len = strlen((S8*) content_location_p) + 1;
            node_p->mms_url_p = (S8*) jdd_MemAlloc(sizeof(S8), len);
            if (node_p->mms_url_p == NULL)
            {
                return JC_ERR_MEMORY_ALLOCATION;
            }
            memcpy(node_p->mms_url_p, content_location_p, len);
        }
    }
    else
    {
        node_p->mms_url_p = NULL;
    }

    if (screen_id == SCR_ID_JMMS_NEW_MMS_IND)
    {                                                       /* /add as second node of link list */
        if (g_jmms_context->pending_mms_info_list == NULL)  /* /not possible */
        {
            return E_JMMS_GENERAL_ERROR;
        }
        else
        {
            node_p->next_p = g_jmms_context->pending_mms_info_list->next_p;
            g_jmms_context->pending_mms_info_list->next_p = node_p;
        }

    }
    else    /* /add as first node of link list */
    {
        node_p->next_p = g_jmms_context->pending_mms_info_list;
        g_jmms_context->pending_mms_info_list = node_p;
    }
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_header_ind_callback
 * DESCRIPTION
 *  Used to handle header indication
 * PARAMETERS
 *  jmms_context_p              [IN]        
 *  comm_header_ind_data_p      [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_header_ind_callback(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_HEADER_INDICATION *comm_header_ind_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_uc_sending_complete_struct sending_complete_data = {0, };
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Header Ind Callback, Request Id:",
                         comm_header_ind_data_p->uiRequestID);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Header Ind HTTP Status:", comm_header_ind_data_p->eStatus);

    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, comm_header_ind_data_p->uiRequestID);
    if (comm_node_p == NULL)
    {
        if (comm_header_ind_data_p->uiRequestID)
        {
            jdi_CommunicationFreeReference(jmms_context_p->comm_handle, comm_header_ind_data_p->uiRequestID);

        }
        comm_header_ind_data_p->uiRequestID = 0;

        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)",
                             "JMMS: No commn node for this Header Indication, so free communication reference for request id:",
                             comm_header_ind_data_p->uiRequestID);

        return E_JMMS_GENERAL_ERROR;    /* error type doesn't matter */

    }

    if (comm_header_ind_data_p->eStatus != 200) /* /200 is HTTP OK */
    {
        if (comm_header_ind_data_p->uiRequestID)
        {
            ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, comm_header_ind_data_p->uiRequestID);
            if (JC_OK != ret_code)
            {
            #ifdef __MMI_UNIFIED_COMPOSER__
                if (comm_node_p->mms_communication_state != E_TYPE_NEW_MMS)
            #endif 
                {
                    mmi_jmms_handle_error_in_communication(
                        jmms_context_p,
                        E_FROM_URL_CALLBACK,
                        comm_node_p,
                        comm_header_ind_data_p->eStatus);
                }

            #ifdef __MMI_UNIFIED_COMPOSER__
                if (comm_node_p->mms_communication_state == E_TYPE_NEW_MMS)
                {
                    sending_complete_data.result = MMI_FALSE;
                    sending_complete_data.error_code = E_JMMS_DEAFULT_COMM_ERROR_CODE;
                    sending_complete_data.communication_handle_p = comm_node_p;
                    comm_node_p->callback(MMS_SENDING_COMPELETE_CALLBACK, (void*)&sending_complete_data);
                }
            #endif /* __MMI_UNIFIED_COMPOSER__ */ 
                mmi_jmms_free_comm_node(jmms_context_p, comm_header_ind_data_p->uiRequestID);
                comm_header_ind_data_p->uiRequestID = 0;
                return JC_ERR_MEMORY_ALLOCATION;    /* error type doesn't matter */
            }
        }

        ret_code = mmi_jmms_retry_communication(
                    jmms_context_p,
                    E_FROM_URL_CALLBACK,
                    comm_header_ind_data_p->uiRequestID,
                    comm_header_ind_data_p->eStatus);
        if (JC_OK != ret_code)
        {
        #ifdef __MMI_UNIFIED_COMPOSER__
            if (comm_node_p->mms_communication_state == E_TYPE_NEW_MMS)
            {
                sending_complete_data.result = MMI_FALSE;
                sending_complete_data.error_code = E_JMMS_DEAFULT_COMM_ERROR_CODE;
                sending_complete_data.communication_handle_p = comm_node_p;
                comm_node_p->callback(MMS_SENDING_COMPELETE_CALLBACK, (void*)&sending_complete_data);
            }
        #endif /* __MMI_UNIFIED_COMPOSER__ */ 
            mmi_jmms_free_comm_node(jmms_context_p, comm_header_ind_data_p->uiRequestID);
            comm_header_ind_data_p->uiRequestID = 0;
            /* sandeep start to fix PMTSW00006618 */
        #ifdef __MMI_UNIFIED_MESSAGE__
            if ((comm_node_p->mms_communication_state == E_TYPE_NOTIFICATION_RESPONSE) &&
                IsScreenPresent(SCR_ID_UM_UNSENT))
            {
                DeleteUptoScrID(SCR_ID_UM_UNSENT);
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            /* sandeep end to fix PMTSW00006618 */
            return JC_ERR_MEMORY_ALLOCATION;    /* error type doesn't matter */
        }

        mmi_jmms_free_comm_node(jmms_context_p, comm_header_ind_data_p->uiRequestID);

        return E_JMMS_GENERAL_ERROR;    /* error type doesn't matter. By virtue of !=JC_OK value communicator will delete */
        /* /this request so that url Indication Callback will not be further called */

    }

    comm_node_p->content_type_p = (JC_INT8*) jdi_UtilsStrdup(comm_header_ind_data_p->pszContentType);

    if (comm_node_p->mms_communication_state == E_TYPE_NOTIFICATION_RESPONSE ||
        comm_node_p->mms_communication_state == E_TYPE_READ_REPORT_PDU ||
        comm_node_p->mms_communication_state == E_TYPE_ACK_RESPONSE)
    {
        mmi_jmms_free_comm_node(g_jmms_context, comm_header_ind_data_p->uiRequestID);
    }
    return JC_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_url_ind_callback
 * DESCRIPTION
 *  Usde to handle URL indication
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 * RETURNS
 *  JC_OK                    on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_url_ind_callback(mmi_jmms_context_struct *jmms_context_p, COMM_FETCH_URL_IND_RESP *url_ind_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    CONTENT_DATA content_data = {0, };
    JC_RETCODE error_code = JC_OK;

#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_uc_sending_complete_struct sending_complete_data = {0, };
#endif 

    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_url_ind_callback");

    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_data_p->uiRequestID);
    if (comm_node_p == NULL)
    {
        if (url_ind_data_p->uiRequestID)
        {
            ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

        }
        url_ind_data_p->uiRequestID = 0;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)",
                             "JMMS: No commn node for this id, call jdi_CommunicationFreeReference",
                             url_ind_data_p->uiRequestID);
        return E_JMMS_GENERAL_ERROR;

    }

    if (url_ind_data_p->uiCurrentLength > 0)
    {
        if (comm_node_p->file_handle == NULL)
        {

            JC_INT8 temp[50] = {0, };

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Handle Url First Chunk, Request id",
                                 url_ind_data_p->uiRequestID);

            if (comm_node_p->fs_handle == NULL)
            {
                if (jdd_FSInitialize(&comm_node_p->fs_handle) != JC_OK)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Error In Init File");
                    ret_code = JC_ERR_FILE_OPEN;
                #ifdef __MMI_UNIFIED_COMPOSER__
                    if (comm_node_p->mms_communication_state != E_TYPE_NEW_MMS)
                #endif 
                    {
                        mmi_jmms_handle_error_in_communication(
                            jmms_context_p,
                            E_FROM_URL_CALLBACK,
                            comm_node_p,
                            E_JMMS_DEAFULT_COMM_ERROR_CODE);
                    }
                    jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);
                #ifdef __MMI_UNIFIED_COMPOSER__
                    if (comm_node_p->mms_communication_state == E_TYPE_NEW_MMS)
                    {
                        sending_complete_data.result = MMI_FALSE;
                        sending_complete_data.error_code = E_JMMS_DEAFULT_COMM_ERROR_CODE;
                        sending_complete_data.communication_handle_p = comm_node_p;
                        comm_node_p->callback(MMS_SENDING_COMPELETE_CALLBACK, (void*)&sending_complete_data);
                    }
                #endif /* __MMI_UNIFIED_COMPOSER__ */ 
                    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);
                    url_ind_data_p->uiRequestID = 0;

                    return ret_code;
                }
            }

            /* manish for file path change */
            jc_sprintf(temp, "%s%d", "@mms\\temp\\jmms_temp", url_ind_data_p->uiRequestID);

            jdi_UtilsCharToTchar(&(comm_node_p->file_name_p), temp);
            comm_node_p->file_handle = jdd_FSOpen(comm_node_p->fs_handle, comm_node_p->file_name_p, E_CREATE_WRITE_MODE);

        }

        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Handle other Url Chunks, Request Id:",
                             url_ind_data_p->uiRequestID);
    #if defined (__USB_IN_NORMAL_MODE__)
        if (mmi_jmms_check_usb_mode())
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "USB Mode: Write To File");
        }
    #endif /* defined (__USB_IN_NORMAL_MODE__) */ 

        error_code = jdd_FSWrite(url_ind_data_p->pucBuffer, url_ind_data_p->uiCurrentLength, 1, comm_node_p->file_handle);
    #if defined (__USB_IN_NORMAL_MODE__)
        if (mmi_jmms_check_usb_mode())
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "USB Mode: Write To File return=%d", error_code);
        }

    #endif /* defined (__USB_IN_NORMAL_MODE__) */ 

        if (error_code != 1)
        {
        #ifdef __MMI_UNIFIED_COMPOSER__
            if (comm_node_p->mms_communication_state != E_TYPE_NEW_MMS)
        #endif 
            {
                if (error_code == JC_ERR_FILE_FULL || error_code == JC_ERR_FILE_WRITE)
                {
                    mmi_jmms_handle_error_in_communication(
                        jmms_context_p,
                        E_FROM_URL_CALLBACK,
                        comm_node_p,
                        JC_ERR_FILE_FULL);
                }
                else
                {
                    mmi_jmms_handle_error_in_communication(
                        jmms_context_p,
                        E_FROM_URL_CALLBACK,
                        comm_node_p,
                        E_JMMS_DEAFULT_COMM_ERROR_CODE);
                }
            }

            if (comm_node_p->file_handle != NULL)
            {
                jdd_FSClose(comm_node_p->file_handle);
            }

            jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);
        #ifdef __MMI_UNIFIED_COMPOSER__
            if (comm_node_p->mms_communication_state == E_TYPE_NEW_MMS)
            {
                sending_complete_data.result = MMI_FALSE;
                sending_complete_data.error_code = E_JMMS_DEAFULT_COMM_ERROR_CODE;
                sending_complete_data.communication_handle_p = comm_node_p;
                comm_node_p->callback(MMS_SENDING_COMPELETE_CALLBACK, (void*)&sending_complete_data);
            }
        #endif /* __MMI_UNIFIED_COMPOSER__ */ 
            mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);
            url_ind_data_p->uiRequestID = 0;

            return JC_ERR_FILE_OPEN;
        }

        comm_node_p->reponse_size += url_ind_data_p->uiCurrentLength;
    }

    if (url_ind_data_p->bHasMoreData == E_FALSE)
    {
        if (comm_node_p->file_handle)
        {
            if (comm_node_p->reponse_size > 0)
            {
                jdd_FSClose(comm_node_p->file_handle);

                /* /7 March */
                if (g_jmms_context->jmms_fs_handle != NULL)
                {
                    jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                    g_jmms_context->jmms_fs_handle = NULL;
                }

                content_data.bIsStream = E_TRUE;
                content_data.cbReadCallback = mmi_jmms_read_callback;
                content_data.uiTotalSize = comm_node_p->reponse_size;
                content_data.uiCurSize = 0;
                content_data.pStream = comm_node_p->file_name_p;
                content_data.pFileName = comm_node_p->file_name_p;

            }
        }

        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS URL Chunks Finished. Request id:",
                             url_ind_data_p->uiRequestID);
        /* /When control is here then no problem with return ret_code because after that */
        ret_code = mmi_jmms_handle_url_repsonse(jmms_context_p, url_ind_data_p, content_data);
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "mmi_jmms_url_ind_callback return:", ret_code);

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_url_repsonse
 * DESCRIPTION
 *  Used to handle URl response
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 *  content_data        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_url_repsonse(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_data_p,
            CONTENT_DATA content_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;
    JC_RETCODE ret_code = JC_OK;

#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_uc_sending_complete_struct sending_complete_data = {0, };
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_url_repsonse");
    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_data_p->uiRequestID);
    if (comm_node_p == NULL)
    {
        if (url_ind_data_p->uiRequestID)
        {
            jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

        }
        url_ind_data_p->uiRequestID = 0;

        return JC_ERR_MEMORY_ALLOCATION;
    }

    if (content_data.uiTotalSize != 0)  /* for notification response/ack response this value will be 0 and content type will return */
    {
        if (comm_node_p->content_type_p == NULL ||
            jc_strcmp(comm_node_p->content_type_p, "application/vnd.wap.mms-message") != 0)
        {

            if (url_ind_data_p->uiRequestID)
            {
                jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

            }
        #ifndef __MMI_UNIFIED_COMPOSER__
            if (comm_node_p->mms_communication_state != E_TYPE_NEW_MMS)
        #endif 
            {
                /* Todo: Need to pass approraite error code- last  parameter */
                mmi_jmms_handle_error_in_communication(
                    jmms_context_p,
                    E_FROM_URL_CALLBACK,
                    comm_node_p,
                    JMMS_WRONG_CONTENT_TYPE_ERROR);
            }
        #ifdef __MMI_UNIFIED_COMPOSER__
            if (comm_node_p->mms_communication_state == E_TYPE_NEW_MMS)
            {
                sending_complete_data.result = MMI_FALSE;
                sending_complete_data.error_code = JMMS_WRONG_CONTENT_TYPE_ERROR;
                sending_complete_data.communication_handle_p = comm_node_p;
                comm_node_p->callback(MMS_SENDING_COMPELETE_CALLBACK, (void*)&sending_complete_data);
            }
        #endif /* __MMI_UNIFIED_COMPOSER__ */ 
            mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

            url_ind_data_p->uiRequestID = 0;

            return JC_ERR_MEMORY_ALLOCATION;    /* error type does not matter */

        }
    }

    switch (comm_node_p->mms_communication_state)
    {

        case E_TYPE_ACK_RESPONSE:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS ACK Response, Request ID: ",
                                 url_ind_data_p->uiRequestID);
            ret_code = mmi_jmms_handle_notification_ack_response(jmms_context_p, url_ind_data_p, &content_data);
            break;
        case E_TYPE_NOTIFICATION_RESPONSE:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Notification Response, Request ID: ",
                                 url_ind_data_p->uiRequestID);
            ret_code = mmi_jmms_handle_notification_ack_response(jmms_context_p, url_ind_data_p, &content_data);
            break;
        case E_TYPE_READ_REPORT_PDU:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS READ Report PDU Response, Request ID: ",
                                 url_ind_data_p->uiRequestID);
            ret_code = mmi_jmms_handle_read_report_pdu_response(jmms_context_p, url_ind_data_p, &content_data);
            break;

        case E_TYPE_READ_REPORT_MMS:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Read Report MMS Response, Request ID: ",
                                 url_ind_data_p->uiRequestID);
            ret_code = mmi_jmms_handle_read_report_mms_response(jmms_context_p, url_ind_data_p, &content_data);
            break;

        case E_TYPE_IMMEDIATE_RETRIEVAL_FETCH:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Immdiate Download Response, Request ID: ",
                                 url_ind_data_p->uiRequestID);
            ret_code = mmi_jmms_handle_immediate_downlaod_response(jmms_context_p, url_ind_data_p, &content_data);
            break;

        case E_TYPE_DEFFERED_RETRIEVAL_FETCH:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Deferred Download Response, Request ID: ",
                                 url_ind_data_p->uiRequestID);
            ret_code = mmi_jmms_handle_deffered_downlaod_response(jmms_context_p, url_ind_data_p, &content_data);
            break;

    #ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
        case E_TYPE_NEW_JAVA_MMS_SEND:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS JSR New MMS Response, Request ID: ",
                                 url_ind_data_p->uiRequestID);
            ret_code = mmi_jmms_jsr_mms_send_response(jmms_context_p, url_ind_data_p, content_data);
            break;
    #endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 

        case E_TYPE_NEW_MMS:

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS New MMS Send Response, Request ID: ",
                                 url_ind_data_p->uiRequestID);
    #ifdef __MMI_UNIFIED_COMPOSER__
            ret_code = mmi_jmms_uc_handle_new_mms_send_response(jmms_context_p, url_ind_data_p, &content_data);
    #else 
            ret_code = mmi_jmms_handle_new_mms_send_response(jmms_context_p, url_ind_data_p, &content_data);
    #endif 
            break;

        default:
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Undefined Communication State, Request ID: ",
                                 url_ind_data_p->uiRequestID);
            mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

    }   /* /end of switch switch(jmms_context_p->mms_communication_state) */

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "mmi_jmms_handle_url_repsonse return:", ret_code);

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_comm_node
 * DESCRIPTION
 *  Used to free communication node
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  reference_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_comm_node(mmi_jmms_context_struct *jmms_context_p, JC_UINT32 reference_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL, *previous_node_p = NULL;
    mmi_jmms_communication_state_node_struct *temp_comp_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comm_node_p = jmms_context_p->comm_state_p;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_free_comm_node");
    /* / 7 March */
    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            return;
        }
    }

    while (comm_node_p != NULL)
    {
        if (comm_node_p->reference_id == reference_id)
        {
            if (comm_node_p->file_handle)
            {
                jdd_FSClose(comm_node_p->file_handle);
                jdd_FSDelete(g_jmms_context->jmms_fs_handle, comm_node_p->file_name_p);
                comm_node_p->file_handle = NULL;
            }
            if ((comm_node_p->file_name_p) != NULL)
            {
                jdd_MemFree(comm_node_p->file_name_p);
                comm_node_p->file_name_p = NULL;
            }

            if ((comm_node_p->fs_handle) != NULL)
            {
                jdd_FSDeinitialize(comm_node_p->fs_handle);
            }

            if ((comm_node_p->send_file_name_p) != NULL)
            {
                jdd_FSDelete(g_jmms_context->jmms_fs_handle, comm_node_p->send_file_name_p);
                jdd_MemFree(comm_node_p->send_file_name_p);
                comm_node_p->send_file_name_p = NULL;
            }

            if ((comm_node_p->content_type_p) != NULL)
            {
                jdd_MemFree(comm_node_p->content_type_p);
                comm_node_p->content_type_p = NULL;
            }

            if ((comm_node_p->mms_content_location_p) != NULL)
            {
                jdd_MemFree(comm_node_p->mms_content_location_p);
                comm_node_p->mms_content_location_p = NULL;
            }

            if ((comm_node_p->mms_communication_state != E_TYPE_NOTIFICATION_RESPONSE) &&
                (comm_node_p->mms_communication_state != E_TYPE_READ_REPORT_PDU) &&
                (comm_node_p->mms_communication_state != E_TYPE_READ_REPORT_MMS) &&
                (comm_node_p->mms_communication_state != E_TYPE_ACK_RESPONSE))
            {
                mmi_jmms_reset_mms_downloading_busy();
                mmi_jmms_update_status_icon_indicator();
            }

            if (previous_node_p == NULL)
            {
                /* Vikram: The target is to set the g_jmms_context->reference_id value. For the case, MMS Send->Notification
                   MMS Send Retry, g_jmms_context->reference_id will get 0 after Notification */
                jmms_context_p->comm_state_p = comm_node_p->next_p;
            }
            else
            {
                previous_node_p->next_p = comm_node_p->next_p;
            }
            /* Cannot set the reference_id as 0. The reason is that incase of MMS download retry, the new MMS retry is being done and after that
               the previous comm node is freed. So if we set the reference_id as 0 here, the download abort will stop working. Also may other things
               will misbehave */
            /* g_jmms_context->reference_id  = 0; */

            temp_comp_node_p = jmms_context_p->comm_state_p;
            while (temp_comp_node_p &&
                   !((temp_comp_node_p->mms_communication_state == E_TYPE_NEW_MMS) ||
                     (temp_comp_node_p->mms_communication_state == E_TYPE_DEFFERED_RETRIEVAL_FETCH) ||
                     (temp_comp_node_p->mms_communication_state == E_TYPE_NEW_JAVA_MMS_SEND)))
            {
                temp_comp_node_p = temp_comp_node_p->next_p;
            }
            if (temp_comp_node_p)
            {
                g_jmms_context->reference_id = temp_comp_node_p->reference_id;
            }
            else
            {
                g_jmms_context->reference_id = 0;
            }

            temp_comp_node_p = jmms_context_p->comm_state_p;
            while (temp_comp_node_p)
            {

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "\n%s%d", "g_jmms_context->reference_id = ",
                                     g_jmms_context->reference_id);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "\n%s%d", "Communication State = ",
                                     temp_comp_node_p->mms_communication_state);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "\n%s%d", "Reference Id = ", temp_comp_node_p->reference_id);
                temp_comp_node_p = temp_comp_node_p->next_p;

            }

            jdd_MemFree(comm_node_p);

            break;
        }
        previous_node_p = comm_node_p;
        comm_node_p = comm_node_p->next_p;

    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    /* /added for disappearing the G icon */
    if (g_jmms_context->comm_state_p == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Timer for Disconnect ");
        StartTimer(JMMS_NO_COMM_TIMER_CHECK, 10000, mmi_jmms_comm_time_hdlr);
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS Comm Node Free for Request ID", reference_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_immediate_retrival_underway
 * DESCRIPTION
 *  Returns whether any immediate retrival is underway
 * PARAMETERS
 *  void
 * RETURNS
 *  E_TRUE        if immediate retrival is underway
 *  E_FALSE       if immediate retrival is not underway
 *****************************************************************************/
S32 mmi_jmms_is_immediate_retrival_underway(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT32 retrival_underway = E_FALSE;
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comm_node_p = g_jmms_context->comm_state_p;

    while (comm_node_p != NULL)
    {
        if (comm_node_p->mms_communication_state == E_TYPE_IMMEDIATE_RETRIEVAL_FETCH)
        {
            retrival_underway = E_TRUE;
            break;
        }
        comm_node_p = comm_node_p->next_p;
    }
    return retrival_underway;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_comm_node_list
 * DESCRIPTION
 *  Frees communication node list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_comm_node_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;
    mmi_jmms_communication_state_node_struct *previous_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comm_node_p = g_jmms_context->comm_state_p;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_free_comm_node");

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            return;
        }
    }

    while (comm_node_p != NULL)
    {
        if (comm_node_p->reference_id != 0)
        {
            jdi_CommunicationFreeReference(g_jmms_context->comm_handle, comm_node_p->reference_id);
        }

        if (comm_node_p->file_handle)
        {
            jdd_FSClose(comm_node_p->file_handle);
            jdd_FSDelete(g_jmms_context->jmms_fs_handle, comm_node_p->file_name_p);
            comm_node_p->file_handle = NULL;
        }
        if ((comm_node_p->file_name_p) != NULL)
        {
            jdd_MemFree(comm_node_p->file_name_p);
            comm_node_p->file_name_p = NULL;
        }

        if ((comm_node_p->send_file_name_p) != NULL)
        {
            jdd_FSDelete(g_jmms_context->jmms_fs_handle, comm_node_p->send_file_name_p);
            jdd_MemFree(comm_node_p->send_file_name_p);
            comm_node_p->send_file_name_p = NULL;
        }

        if ((comm_node_p->content_type_p) != NULL)
        {
            jdd_MemFree(comm_node_p->content_type_p);
            comm_node_p->content_type_p = NULL;
        }

        if ((comm_node_p->mms_content_location_p) != NULL)
        {
            jdd_MemFree(comm_node_p->mms_content_location_p);
            comm_node_p->mms_content_location_p = NULL;
        }

        comm_node_p->mms_communication_state = E_TYPE_NULL;

        if (previous_node_p == NULL)
        {
            g_jmms_context->comm_state_p = comm_node_p->next_p;
        }
        else
        {
            previous_node_p->next_p = comm_node_p->next_p;
        }

        jdd_MemFree(comm_node_p);

        comm_node_p = comm_node_p->next_p;
        mmi_jmms_stop_download_busy();
        mmi_jmms_update_status_icon_indicator();

    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    if (g_jmms_context->comm_state_p == NULL)
    {
        jdi_CommunicationDisconnect(g_jmms_context->comm_handle);
        g_jmms_context->g_mms_downloading_busy = 0;
        mmi_jmms_update_status_icon_indicator();
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Comm list for File Format Issue");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_comm_time_hdlr
 * DESCRIPTION
 *  Stops communication timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_comm_time_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_comm_time_hdlr");
    if (g_jmms_context->comm_state_p == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_comm_time_hdlr : Disconnect");
        jdi_CommunicationDisconnect(g_jmms_context->comm_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_add_comm_node
 * DESCRIPTION
 *  Used to add communication node
 * PARAMETERS
 *  jmms_context_p          [IN]        
 *  reference_id            [IN]        
 *  comm_state              [IN]        
 *  send_file_name_p        [IN]        
 *  msg_index               [IN]        
 *  retry_counter           [IN]        
 *  content_location_p      [IN]        
 *  communication_cb        [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_add_comm_node(mmi_jmms_context_struct *jmms_context_p,
                                  JC_UINT32 reference_id,
                                  U16 comm_state,
                                  JC_CHAR *send_file_name_p,
                                  JC_UINT32 msg_index, U8 retry_counter, S8 *content_location_p
#ifdef __MMI_UNIFIED_COMPOSER__
                                  , MMS_COMMUNICATION_CALLBACK communication_cb
#endif 
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;
    mmi_jmms_communication_state_node_struct *temp_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comm_node_p =
        (mmi_jmms_communication_state_node_struct*) jdd_MemAlloc(1, sizeof(mmi_jmms_communication_state_node_struct));
    if (comm_node_p == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }
#ifdef __MMI_UNIFIED_COMPOSER__
    comm_node_p->callback = communication_cb;
#endif 
    comm_node_p->file_handle = NULL;
    comm_node_p->mms_communication_state = comm_state;
    comm_node_p->next_p = NULL;
    comm_node_p->file_name_p = NULL;
    comm_node_p->reponse_size = 0;
    comm_node_p->reference_id = reference_id;
    comm_node_p->send_file_name_p = send_file_name_p;
    comm_node_p->msg_index = msg_index;
    comm_node_p->retry_counter = retry_counter;
    comm_node_p->mms_content_location_p = content_location_p;
    comm_node_p->fs_handle = NULL;
    if (jmms_context_p->comm_state_p == NULL)
    {
        jmms_context_p->comm_state_p = comm_node_p;
    }
    else
    {
        temp_node_p = jmms_context_p->comm_state_p;
        while (temp_node_p->next_p != NULL)
        {
            temp_node_p = temp_node_p->next_p;
        }
        temp_node_p->next_p = comm_node_p;
    }

    if ((comm_node_p->mms_communication_state != E_TYPE_NOTIFICATION_RESPONSE) &&
        (comm_node_p->mms_communication_state != E_TYPE_READ_REPORT_PDU) &&
        (comm_node_p->mms_communication_state != E_TYPE_READ_REPORT_MMS) &&
        (comm_node_p->mms_communication_state != E_TYPE_ACK_RESPONSE))
    {
        mmi_jmms_set_mms_downloading_busy();
        mmi_jmms_update_status_icon_indicator();
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS New Comm Node Added for Request ID", reference_id);

    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_comm_state
 * DESCRIPTION
 *  Used to get the communication node for the required reference ID.
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  reference_id        [IN]        
 * RETURNS
 *  communicaton        node on success
 *****************************************************************************/
mmi_jmms_communication_state_node_struct *mmi_jmms_get_comm_state(
                                            mmi_jmms_context_struct *jmms_context_p,
                                            JC_UINT32 reference_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL, *temp_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node_p = jmms_context_p->comm_state_p;
    while (temp_node_p != NULL)
    {
        if (temp_node_p->reference_id == reference_id)
        {
            comm_node_p = temp_node_p;
            break;
        }
        temp_node_p = temp_node_p->next_p;
    }

    return comm_node_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_update_comm_node
 * DESCRIPTION
 *  used to update communication node for retry
 * PARAMETERS
 *  jmms_context_p          [IN]        
 *  new_reference_id        [IN]        
 *  old_reference_id        [IN]        
 *  retry_counter           [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_update_comm_node(
            mmi_jmms_context_struct *jmms_context_p,
            JC_UINT32 new_reference_id,
            JC_UINT32 old_reference_id,
            U8 retry_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *temp_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node_p = jmms_context_p->comm_state_p;
    while (temp_node_p != NULL)
    {
        if (temp_node_p->reference_id == old_reference_id)
        {
            temp_node_p->reference_id = new_reference_id;

            if (g_jmms_context->jmms_fs_handle == NULL)
            {
                if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
                {
                    return JC_ERR_MEMORY_ALLOCATION;
                }
            }

            if (temp_node_p->file_handle)
            {
                jdd_FSClose(temp_node_p->file_handle);
                jdd_FSDelete(g_jmms_context->jmms_fs_handle, temp_node_p->file_name_p);
                temp_node_p->file_handle = NULL;
            }
            if ((temp_node_p->fs_handle) != NULL)
            {
                jdd_FSDeinitialize(temp_node_p->fs_handle);
                temp_node_p->fs_handle = NULL;
            }

            if ((temp_node_p->file_name_p) != NULL)
            {
                jdd_MemFree(temp_node_p->file_name_p);
                temp_node_p->file_name_p = NULL;
            }

            if ((temp_node_p->content_type_p) != NULL)
            {
                jdd_MemFree(temp_node_p->content_type_p);
                temp_node_p->content_type_p = NULL;
            }

            temp_node_p->reponse_size = 0;

            temp_node_p->retry_counter = retry_counter;

            if (g_jmms_context->jmms_fs_handle != NULL)
            {
                jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                g_jmms_context->jmms_fs_handle = NULL;
            }

            break;
        }
        temp_node_p = temp_node_p->next_p;
    }

    if (temp_node_p == NULL)
    {
        return E_JMMS_GENERAL_ERROR;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS Comm Node Updated Old Request Id", old_reference_id);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS New Request Id", new_reference_id);

    return JC_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_update_mmsc_url_version
 * DESCRIPTION
 *  Used to update MMSC URL version.
 * PARAMETERS
 *  mmsc_url_used       [IN]        
 *  mmsc_version        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_update_mmsc_url_version(S8 *mmsc_url_used, S8 *mmsc_version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JDD_FILE file_handle = NULL;

    JC_UINT32 read_len = 0, index, len, temp_len = 0;
    S8 *file_buffer_p = NULL;
    S8 file_name[(MAX_FILE_LENGTH + 1) * ENCODING_LENGTH];

    JC_INT32 write_len = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_update_mmsc_url_version");

    mmi_asc_to_ucs2((PS8) file_name, (PS8) MMS_MMSC_URLS_FILE_NAME);

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            return;
        }
    }

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (JC_CHAR*) file_name, E_CREATE_APPEND_WRITE_READ_MODE);   /* /E_CREATE_APPEND_WRITE_READ_MODE) ; */

    if (file_handle != NULL)
    {

        ret_code = jdd_FSGetSize(file_handle, &len);
        if (JC_OK != ret_code)
        {
            goto END;
        }

        file_buffer_p = (S8*) jdd_MemAlloc(sizeof(S8), len);

        if ((NULL == file_buffer_p) && (len != 0))
        {
            goto END;
        }

        if (len > 0)
        {

            ret_code = jdd_FSSeek(file_handle, 0, E_FILE_SEEK_SET);
            if (ret_code != JC_OK)
            {
                goto END;
            }
            /* /read_len = jdd_FSRead (file_buffer_p, sizeof(JC_INT8), len, file_handle) ; */
            read_len = jdd_FSRead(file_buffer_p, len, 1, file_handle);
            if (read_len != 1)
            {
                goto END;
            }

            read_len = len;
        }

        len = 0;
        index = 0;
        temp_len = 0;
        /* while(read_len!=0) */
        while (read_len != index)
        {
            len = (mmi_ucs2strlen(file_buffer_p + index) + 1) * ENCODING_LENGTH;

            if (mmi_ucs2cmp((S8*) (file_buffer_p + index), (S8*) mmsc_url_used) == 0)
            {
                index = index + len;
                mmi_asc_to_ucs2((S8*) (file_buffer_p + index), (S8*) (mmsc_version));

                if (file_handle != NULL)
                {
                    jdd_FSClose(file_handle);
                }

                ret_code = jdd_FSDelete(g_jmms_context->jmms_fs_handle, (const JC_CHAR*)file_name);
                if (ret_code != JC_OK)
                {
                    goto END;
                }

                file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (JC_CHAR*) file_name, E_CREATE_APPEND_WRITE_READ_MODE);
                if (file_handle == NULL)
                {
                    goto END;
                }

                write_len = jdd_FSWrite(file_buffer_p, 1, read_len, file_handle);
                if (write_len != read_len)
                {
                    goto END;
                }

                break;
            }
            else
            {
                index = index + len;
                len = (mmi_ucs2strlen(file_buffer_p + index) + 1) * ENCODING_LENGTH;
                index = index + len;
                temp_len = temp_len + index;
            }
        }

        if (file_buffer_p)
        {
            jdd_MemFree(file_buffer_p);
            file_buffer_p = NULL;
        }

        if (read_len == index)  /* /entry not found */
        {
            S8 *temp_buffer = NULL;

            write_len = 0;

            len = (mmi_ucs2strlen(mmsc_url_used) + 1) * ENCODING_LENGTH;
            len = len + (strlen(mmsc_version) + 1) * ENCODING_LENGTH;

            temp_buffer = (S8*) jdd_MemAlloc(sizeof(S8), len);
            if (NULL == temp_buffer)
            {
                return;
            }

            mmi_ucs2cpy((S8*) temp_buffer, (S8*) (mmsc_url_used));
            len = (mmi_ucs2strlen(mmsc_url_used) + 1) * ENCODING_LENGTH;    /* null char also need to be write into file */
            mmi_asc_to_ucs2((S8*) (temp_buffer + len), (S8*) (mmsc_version));

            len = len + (strlen(mmsc_version) + 1) * ENCODING_LENGTH;
            write_len = 0;

            ret_code = jdd_FSSeek(file_handle, 0, E_FILE_SEEK_END);
            if (ret_code != JC_OK)
            {
                goto END;
            }

            write_len = jdd_FSWrite(temp_buffer, 1, len, file_handle);

            if (temp_buffer)
            {
                jdd_MemFree(temp_buffer);
                temp_buffer = NULL;
            }

            if (len != write_len)
            {
                goto END;
            }
        }

        if (file_handle != NULL)
        {
            jdd_FSClose(file_handle);
        }

        if (file_buffer_p)
        {
            jdd_MemFree(file_buffer_p);
            file_buffer_p = NULL;
        }

    }

  END:

    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    if (file_buffer_p)
    {
        jdd_MemFree(file_buffer_p);
        file_buffer_p = NULL;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_message_header
 * DESCRIPTION
 *  Used to free message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_message_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_free_message_header");

    if (g_jmms_context->last_scr_id == SCR_ID_JMMS_OUTBOX_OPTIONS
        || g_jmms_context->last_scr_id == SCR_ID_JMMS_DRAFTS_OPTIONS)
    {
        ///it menas MMS Sent was from "Sent" in Drafts or 
        //"Resent" in Outbox
        mmi_jmms_deinit_mms_context(g_jmms_context);

        g_jmms_context->sent_retry_counter = 0;
        return;
    }
    else
    {
        if (g_jmms_context->msg_handle != NULL)
        {
            MESSAGING_HANDLER *pMessagingHandler = NULL;

            pMessagingHandler = (MESSAGING_HANDLER*) (g_jmms_context->msg_handle);
            if (pMessagingHandler->pMessageHeaders != NULL)
            {
                FreeMessageHeaders(&(pMessagingHandler->pMessageHeaders));
                pMessagingHandler->pMessageHeaders = NULL;

                g_jmms_context->to_p = NULL;
                g_jmms_context->cc_p = NULL;
                g_jmms_context->bcc_p = NULL;
                g_jmms_context->msg_header_type_p = NULL;
                g_jmms_context->msg_headers_p = NULL;
                g_jmms_context->subject_p = NULL;
                g_jmms_context->version = NULL;

                /* / 7 March */
                if (g_jmms_context->jmms_fs_handle != NULL)
                {
                    jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                    g_jmms_context->jmms_fs_handle = NULL;
                }

                g_jmms_context->sent_retry_counter = 0;
            }

        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_mms_pdu_memory
 * DESCRIPTION
 *  Frees MMS PDU memory
 * PARAMETERS
 *  jmms_context_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_mms_pdu_memory(mmi_jmms_context_struct *jmms_context_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_free_mms_pdu_memory");

    if (jmms_context_p->to_p != NULL)
    {
        jdd_MemFree(jmms_context_p->to_p);
        jmms_context_p->to_p = NULL;
    }

    if (jmms_context_p->cc_p != NULL)
    {
        jdd_MemFree(jmms_context_p->cc_p);
        jmms_context_p->cc_p = NULL;
    }

    if (jmms_context_p->bcc_p != NULL)
    {
        jdd_MemFree(jmms_context_p->bcc_p);
        jmms_context_p->bcc_p = NULL;
    }

    if (jmms_context_p->msg_header_type_p != NULL)
    {
        jdd_MemFree(jmms_context_p->msg_header_type_p);
        jmms_context_p->msg_header_type_p = NULL;
    }

    if (jmms_context_p->msg_headers_p != NULL)
    {
        jdd_MemFree(jmms_context_p->msg_headers_p);
        jmms_context_p->msg_headers_p = NULL;
    }

    if (g_jmms_context->subject_p != NULL)
    {
        jdd_MemFree(g_jmms_context->subject_p);
        g_jmms_context->subject_p = NULL;
    }

    if (jmms_context_p->version != NULL)
    {
        jdd_MemFree(jmms_context_p->version);
        jmms_context_p->version = NULL;
    }

    if (jmms_context_p->activated_mmsc_url_p != NULL)
    {
        jdd_MemFree(jmms_context_p->activated_mmsc_url_p);
        jmms_context_p->activated_mmsc_url_p = NULL;
    }

    if (jmms_context_p->from_p != NULL)
    {
        jdd_MemFree(jmms_context_p->from_p);
        jmms_context_p->from_p = NULL;
    }

    jmms_context_p->sent_retry_counter = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_comm_stop_callback
 * DESCRIPTION
 *  Called when the communication for a MMS is stopped.
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  reference_id        [IN]        
 *  ret_code            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_comm_stop_callback(mmi_jmms_context_struct *jmms_context_p, JC_UINT32 reference_id, JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;
    JC_RETCODE error_code = JC_OK;

#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_communication_stop_struct comm_stop_data = {0, };
#endif 
#ifndef __MMI_UNIFIED_MESSAGE__
    JC_CHAR *folder_name_p = NULL;
    JC_CHAR out_box[7 * ENCODING_LENGTH];
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d %s%d", "mmi_jmms_comm_stop_callback, Reference id: ", reference_id,
                         "Error code: ", ret_code);

#ifdef __MMI_UNIFIED_COMPOSER__
    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, reference_id);

    if (NULL == comm_node_p)
    {
        return;
    }

    if (comm_node_p->callback)
    {
        comm_stop_data.communication_handle_p = comm_node_p;
        comm_stop_data.retCode = error_code;
        comm_stop_data.msg_id = 0;
        comm_node_p->callback(MMS_COMMUNICATION_STOP_CALLBACK, (void*)&comm_stop_data);
    }
    mmi_jmms_free_message_header();
    mmi_jmms_free_comm_node(g_jmms_context, reference_id);
#else /* __MMI_UNIFIED_COMPOSER__ */ 
#ifdef __MMI_UNIFIED_MESSAGE__
    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, reference_id);
#endif 
    if (ret_code == JC_ERR_USER_CANCELLED)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS User Cancelled the Comunication Request");

    #ifdef __MMI_JMMS_SEND_RETRIES__
        mmi_jmms_set_progress_screen_title(0);
    #endif 

    #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
        mmi_jmms_stop_timeout_timer();
    #endif 

    #ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
    #ifndef __MMI_UNIFIED_MESSAGE__
        comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, reference_id);
    #endif 
        if (comm_node_p == NULL)
        {
            return;
        }

        if (comm_node_p->mms_communication_state == E_TYPE_NEW_JAVA_MMS_SEND)
        {
            mmi_jmms_free_comm_node(jmms_context_p, reference_id);
            if (jmms_context_p->jsr_mms_send_cancel_callback != NULL)
            {
                (*(jmms_context_p->jsr_mms_send_cancel_callback)) (JSR_RESULT_OK);
            }
            return;
        }
    #endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 
        /* 2 March- need care */
    #ifdef __MMI_UNIFIED_MESSAGE__
        if (mmi_um_get_current_msg_box_type() != UM_MSG_BOX_TYPE_UNSENT
            && g_jmms_context->save_mms == TRUE && g_jmms_context->last_scr_id == IDLE_SCREEN_ID)
        {
            error_code = mmi_jmms_send_and_store_mms("Outbox", jmms_context_p->msg_handle, comm_node_p);
            if (error_code == JC_OK)
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
                if (error_code == E_MEMORY_FULL_ERROR)
                {
                    mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEMORY);
                }
                else if (error_code == JC_ERR_MEMORY_ALLOCATION || error_code == JC_ERR_FILE_WRITE)
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

            if (g_jmms_context->end_key_processing_handler)
            {
                g_jmms_context->end_key_processing_handler();
            }
        }

        mmi_jmms_free_message_header();
        mmi_jmms_free_comm_node(jmms_context_p, reference_id);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        error_code = mmi_jmms_jdi_get_active_folder(g_jmms_context->store_handle, &(folder_name_p), NULL);
        if (error_code == JC_OK)
        {
            mmi_asc_to_ucs2((PS8) out_box, (PS8) MMI_JMMS_OUTBOX);
            if ((jc_tcscmp(out_box, folder_name_p) != 0)
                && (g_jmms_context->save_mms == TRUE) && (g_jmms_context->last_scr_id == IDLE_SCREEN_ID))
            {
                error_code = mmi_jmms_send_and_store_mms("Outbox", g_jmms_context->msg_handle, comm_node_p);
                if (error_code == JC_OK)
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
                    if (error_code == E_MEMORY_FULL_ERROR)
                    {
                        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEMORY);
                    }
                    else if (error_code == JC_ERR_MEMORY_ALLOCATION || error_code == JC_ERR_FILE_WRITE)
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

        mmi_jmms_free_message_header();
        mmi_jmms_free_comm_node(jmms_context_p, reference_id);
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

    }
    else
    {
    #ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
        comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, reference_id);

        if (comm_node_p == NULL)
        {
            return;
        }

        if ((comm_node_p->mms_communication_state == E_TYPE_NEW_JAVA_MMS_SEND) &&
            (jmms_context_p->jsr_mms_send_cancel_callback != NULL))
        {
            mmi_jmms_free_comm_node(jmms_context_p, reference_id);
            (*(jmms_context_p->jsr_mms_send_cancel_callback)) (JSR_RESULT_ERROR);
            return;
        }
    #endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_error_ind_callback
 * DESCRIPTION
 *  Called when error occurs in MMS sending/downloading
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  reference_id        [IN]        
 *  ret_code            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_error_ind_callback(mmi_jmms_context_struct *jmms_context_p, JC_UINT32 reference_id, JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE error_code = JC_OK;

    JC_EVENT_DATA event_data_p = {0, };
    mmi_jmms_temp_event_struct info = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "mmi_jmms_error_ind_callback, Reference ID: ", reference_id);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Error Ind Error Code:", ret_code);

    event_data_p.destTaskInfo.iAppID = E_TASK_MMS_UI;
    event_data_p.destTaskInfo.iTaskID = E_TASK_MMS_UI;

    event_data_p.srcTaskInfo.iAppID = E_TASK_MMS_UI;
    event_data_p.srcTaskInfo.iTaskID = E_TASK_MMS_UI;

    event_data_p.uiEventInfoSize = sizeof(mmi_jmms_temp_event_struct);
    event_data_p.iEventType = E_COMM_ERROR_INDICATION_EVENT;

    error_code = jdd_QueueAlloc(&event_data_p);
    if (JC_OK != error_code)
    {
        return;
    }

    info.jmms_context_p = jmms_context_p;
    info.reference_id = reference_id;
    info.ret_code = ret_code;

    jc_memcpy(event_data_p.pEventInfo, &info, sizeof(mmi_jmms_temp_event_struct));

    jdd_QueueSend(&event_data_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retry_for_error_in_comm
 * DESCRIPTION
 *  Called to retry MMS sending/downloading
 * PARAMETERS
 *  event_data_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_retry_for_error_in_comm(mmi_jmms_temp_event_struct *event_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_jmms_temp_event_struct *info = {0, };
    mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;

#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_uc_error_struct error_data = {0, };
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = (mmi_jmms_temp_event_struct*) (event_data_p);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_retry_for_error_in_comm ReferenceID: %d ", info->reference_id);
    communication_handle_p = mmi_jmms_get_comm_state(info->jmms_context_p, info->reference_id);
    if (communication_handle_p
#ifdef __MMI_UNIFIED_COMPOSER__
        && (communication_handle_p->mms_communication_state == E_TYPE_NEW_MMS) && communication_handle_p->callback
#endif 
        )
    {
        /* free reference from the transport layer */
        if (communication_handle_p->reference_id != 0)
        {
            jdi_CommunicationFreeReference(info->jmms_context_p->comm_handle, info->reference_id);
        }

    }
    if (mmi_jmms_retry_communication(info->jmms_context_p, E_FROM_ERROR_CALLBACK, info->reference_id, info->ret_code) ==
        JC_OK)
    {
        return;
    }
#ifdef __MMI_UNIFIED_COMPOSER__
    if (communication_handle_p && (communication_handle_p->mms_communication_state == E_TYPE_NEW_MMS) &&
        communication_handle_p->callback)
    {
        error_data.error_code = info->ret_code;
        error_data.communication_handle_p = communication_handle_p;
        communication_handle_p->callback(MMS_SENDING_ERROR_CALLBACK, (void*)&error_data);
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    mmi_jmms_free_comm_node(info->jmms_context_p, info->reference_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_and_send_new_mms
 * DESCRIPTION
 *  Used to create and send new MMS
 * PARAMETERS
 *  message_setting         [IN]        
 *  jmms_context_p          [IN]        
 *  is_create_for_send      [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_create_and_send_new_mms(
            U16 message_setting,
            mmi_jmms_context_struct *jmms_context_p,
            MMI_BOOL is_create_for_send)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    MESSAGE_SEND *message_send_p = NULL;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    U8 ret = 0;
    S32 len = 0;
    MSG_HANDLE msg_handle = jmms_context_p->msg_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free any allocated memory */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_create_and_send_new_mms");

    mmi_jmms_free_mms_pdu_memory(g_jmms_context);

    g_jmms_context->msg_headers_p = (MESSAGE_HEADERS*) jdd_MemAlloc(sizeof(MESSAGE_HEADERS), 1);

    if (NULL == g_jmms_context->msg_headers_p)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);

        return JC_ERR_MEMORY_ALLOCATION;
    }

    g_jmms_context->msg_header_type_p = (MESSAGE_SEND*) jdd_MemAlloc(sizeof(MESSAGE_SEND), 1);
    if (NULL == g_jmms_context->msg_header_type_p)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);

        return JC_ERR_MEMORY_ALLOCATION;
    }

    msg_headers_p = g_jmms_context->msg_headers_p;
    message_send_p = g_jmms_context->msg_header_type_p;

    ret_code = mmi_jmms_set_mmsc_version();
    if (ret_code != JC_OK)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        return ret_code;
    }

    message_send_p->pVersion = (JC_INT8*) g_jmms_context->version;

    if (wap_get_user_agent_brand() == EM_WAP_USERAGENT_BRAND_SE)
    {
        message_send_p->uiDate = get_current_utc_time();
    }

    message_send_p->bDeliveryReport = (g_jmms_context->sending_settings.delivery_report == 1) ? E_TRUE : E_FALSE;
    message_send_p->bReadReport = (g_jmms_context->sending_settings.read_report == 1) ? E_TRUE : E_FALSE;
    message_send_p->bHideSender = (g_jmms_context->sending_settings.hide_sender == 1) ? E_TRUE : E_FALSE;

    message_send_p->uiExpiryTime = 0;

    switch (g_jmms_context->sending_settings.validity_period)
    {
        case E_VALIDITY_PERIOD_MAX:
            if (wap_get_user_agent_brand() != EM_WAP_USERAGENT_BRAND_SE)
            {
                message_send_p->uiExpiryTime = MAX_VALIDITY_PERIOD_VALUE;
            }
            break;
        case E_VALIDITY_PERIOD_1HR:
            message_send_p->uiExpiryTime = 3600;
            break;
        case E_VALIDITY_PERIOD_12HRS:
            message_send_p->uiExpiryTime = 12 * 3600;
            break;
        case E_VALIDITY_PERIOD_1DAY:
            message_send_p->uiExpiryTime = 1 * 24 * 3600;
            break;
        case E_VALIDITY_PERIOD_1WEEK:
            message_send_p->uiExpiryTime = 1 * 7 * 24 * 3600;
            break;
        default:
            if (wap_get_user_agent_brand() != EM_WAP_USERAGENT_BRAND_SE)
            {
                message_send_p->uiExpiryTime = MAX_VALIDITY_PERIOD_VALUE;
            }
            break;
    }

    switch (g_jmms_context->sending_settings.delivery_time)
    {
        case E_IMMEDIATE:
            message_send_p->uiDeliveryTime = 0;
            break;
        case E_1_HR:
            message_send_p->uiDeliveryTime = 3600;
            break;
        case E_12_HRS:
            message_send_p->uiDeliveryTime = 12 * 3600;
            break;
        case E_24_HRS:
            message_send_p->uiDeliveryTime = 24 * 3600;
            break;
        default:
            message_send_p->uiDeliveryTime = 0;
            break;
    }

    message_send_p->eMsgPriority = (g_jmms_context->sending_settings.priority);

    if (g_jmms_context->sending_settings.reply_charging == E_ON)
    {

        message_send_p->pReplyChargingInfo = (REPLY_CHARGING*) jdd_MemAlloc(sizeof(REPLY_CHARGING), 1);

        if (message_send_p->pReplyChargingInfo == NULL)
        {
            mmi_jmms_free_mms_pdu_memory(g_jmms_context);

            return JC_ERR_MEMORY_ALLOCATION;
        }

        switch (g_jmms_context->sending_settings.request_type)
        {
            case E_FULL_MMS:
                message_send_p->pReplyChargingInfo->eReplyCharging = E_REQUEST_REPLY_CHARGING;
                break;
            case E_TEXT_ONLY:
                message_send_p->pReplyChargingInfo->eReplyCharging = E_REQUEST_TEXT_ONLY_REPLY_CHARGING;
                break;
            default:
                message_send_p->pReplyChargingInfo->eReplyCharging = E_REQUEST_REPLY_CHARGING;
                break;
        }

        message_send_p->pReplyChargingInfo->uiRelativeTime =
            (JC_UINT32) (gui_atoi((UI_string_type) g_jmms_context->sending_settings.deadline_for_reply_buffer) * 3600);

        message_send_p->pReplyChargingInfo->uiSize =
            ((JC_UINT32) gui_atoi((UI_string_type) g_jmms_context->sending_settings.reply_msg_size_buffer)) * 1000;

    }

    /* Added by Deepali for reply charging. */
    if (g_jmms_context->rc_info != NULL)
    {
        message_send_p->pReplyChargingInfo->pszReplyId =
            (JC_INT8*) jdi_UtilsStrdup(g_jmms_context->rc_info->pReplyMsgID);
        if (g_jmms_context->rc_info != NULL)
        {
            if (g_jmms_context->rc_info->pReplyMsgID != NULL)
            {
                jdd_MemFree(g_jmms_context->rc_info->pReplyMsgID);
            }
            jdd_MemFree(g_jmms_context->rc_info);
            g_jmms_context->rc_info = NULL;
        }
    }

    message_send_p->bExpiryAbs = E_FALSE;
    message_send_p->bDeliveryAbs = E_FALSE;

    if (g_jmms_context->num_to_addresses > 0)
    {
        g_jmms_context->to_p = mmi_jmms_get_to_addresses();

        if (g_jmms_context->to_p == NULL)
        {
            mmi_jmms_free_mms_pdu_memory(g_jmms_context);
            return JC_ERR_MEMORY_ALLOCATION;
        }

        message_send_p->pTo = (JC_CHAR*) g_jmms_context->to_p;
    }

    if (g_jmms_context->num_cc_addresses > 0)
    {

        g_jmms_context->cc_p = mmi_jmms_get_cc_addresses();

        if (JC_OK != ret)
        {
            mmi_jmms_free_mms_pdu_memory(g_jmms_context);
            return JC_ERR_MEMORY_ALLOCATION;
        }

        message_send_p->pCc = (JC_CHAR*) g_jmms_context->cc_p;
    }

    if (g_jmms_context->num_bcc_addresses > 0)
    {
        g_jmms_context->bcc_p = mmi_jmms_get_bcc_addresses();

        if (JC_OK != ret)
        {
            mmi_jmms_free_mms_pdu_memory(g_jmms_context);
            return JC_ERR_MEMORY_ALLOCATION;
        }

        message_send_p->pBcc = (JC_CHAR*) g_jmms_context->bcc_p;

    }

    len = mmi_ucs2strlen((S8*) g_jmms_context->subject_input_buffer);

    g_jmms_context->subject_p = (S8*) jdd_MemAlloc(sizeof(S8), (len + 1) * ENCODING_LENGTH);

    if ((g_jmms_context->subject_p == NULL) && (len != 0))
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);

        return JC_ERR_MEMORY_ALLOCATION;
    }

    if (g_jmms_context->subject_p)
    {
        if (GetUCS2Flag((S8*) g_jmms_context->subject_input_buffer) == FALSE)
        {
            U8 count = 0;
            U32 str_len = 0;
            S8 temp[MAX_SUBJECT_LENGTH + 1];

            mmi_ucs2_to_asc(temp, (S8*) g_jmms_context->subject_input_buffer);
            str_len = strlen(temp);
            for (count = 0; count < (str_len); count++)
            {
                if (temp[count] == 0x0D && temp[count + 1] == 0x0A)
                {
                    temp[count] = 0x20;
                    strcpy((S8*) (temp + count + 1), (S8*) (temp + count + 2));
                    str_len--;
                }

            }
            mmi_asc_to_ucs2(g_jmms_context->subject_p, temp);
        }
        else
        {
            mmi_ucs2cpy((S8*) g_jmms_context->subject_p, (S8*) g_jmms_context->subject_input_buffer);
        }
        message_send_p->pSubject = (JC_CHAR*) g_jmms_context->subject_p;
    }

    msg_headers_p->eMsgType = E_MSG_TYPE_SEND;

    msg_headers_p->pHeaders = message_send_p;
#ifdef META_HANDLING_SUPPORT
    if (mmi_jmms_is_message_to_fwd() != MMI_TRUE)
    {
        mmi_jmms_jdi_reset_smil_meta_info(g_jmms_context->msg_handle);
    }
#endif /* META_HANDLING_SUPPORT */ 
    if (is_create_for_send == MMI_TRUE)
    {
        mmi_jmms_set_progress_screen_title(STR_ID_PROGRESS_SENDING);
        memset(g_jmms_context->g_jmms_progress_str, 0x00, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);
        mmi_jmms_entry_communication_progress_screen();
    #ifndef __MMI_UNIFIED_COMPOSER__
        mmi_jmms_insert_auto_signature();
    #endif /* #ifndef __MMI_UNIFIED_COMPOSER__ */
        ret_code = mmi_jmms_jdi_set_msg_headers(msg_handle, msg_headers_p);
        if (JC_OK != ret_code)
        {
            mmi_jmms_free_mms_pdu_memory(g_jmms_context);
            return ret_code;
        }

        /* Register the function that to be execute after the completion of the 
           encapsulation */
        mmi_jmms_add_send_callback_node(mmi_jmms_create_and_send_new_mms_async_callback);
        mmi_jmms_send_mms(msg_handle, E_TYPE_NEW_MMS, E_TRUE, 1, E_TRUE
    #ifdef __MMI_UNIFIED_COMPOSER__
                          , mmi_jmms_handle_screen_flow_callback
    #endif 
            );
    }
    else
    {
        ret_code = mmi_jmms_jdi_set_msg_headers(msg_handle, msg_headers_p);
        if (JC_OK != ret_code)
        {
            mmi_jmms_free_mms_pdu_memory(g_jmms_context);
            return ret_code;
        }
    }
    return JC_OK;
}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_and_send_new_mms_async_callback
 * DESCRIPTION
 *  Asynchronous function to create and send new MMS.
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
        // #ifdef __MMI_MMS_SIGNATURE__
        mmi_jmms_del_inserted_auto_signature_slide();
        // #endif
    #endif /* __MMI_UNIFIED_COMPOSER__ */ 
        if (ret_code == E_JMMS_STORAGE_FULL)
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_STORE_FUL);
        }
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
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_send_mms
 * DESCRIPTION
 *  Used to send MMS
 * PARAMETERS
 *  msg_handle              [IN]        
 *  comm_state              [IN]        
 *  is_stream               [IN]        
 *  retry_counter           [IN]        
 *  is_asynch               [IN]        
 *  communication_cb        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_send_mms(MSG_HANDLE msg_handle,
                             U16 comm_state, JC_BOOLEAN is_stream, U8 retry_counter, JC_BOOLEAN is_asynch
#ifdef __MMI_UNIFIED_COMPOSER__
                             , MMS_COMMUNICATION_CALLBACK communication_cb
#endif 
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    static U32 unique_value = 0;
    mmi_jmms_async_send_params_struct *param_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT VIKAS START 20060401 */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_send_mms");

#ifdef __MMI_UNIFIED_COMPOSER__
    if (communication_cb)
    {
        g_jmms_context->ext_cb = communication_cb;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    if ((comm_state == E_TYPE_NOTIFICATION_RESPONSE) ||
        (comm_state == E_TYPE_READ_REPORT_PDU) ||
        (comm_state == E_TYPE_READ_REPORT_MMS) || (comm_state == E_TYPE_ACK_RESPONSE))
    {
        ret_code = mmi_jmms_send_synchronous_mms(
                    msg_handle,
                    comm_state,
                    is_stream,
                    retry_counter,
                    is_asynch,
                    &unique_value);
        return ret_code;

    }

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
    mmi_jmms_stop_timeout_timer();
    g_jmms_context->send_status = 0;
#endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 

    /* PMT VIKAS END 20060401 */
    if (is_stream == E_TRUE)
    {
        JC_INT8 temp[50] = {0, };

        unique_value++;
        if (unique_value > 200000)
        {
            unique_value = 0;
        }

        jc_sprintf(temp, "%s%d", "@mms\\temp\\jmms_tempSendBuff", unique_value);

        if (g_jmms_context->send_content_p != NULL)
        {
            jdd_MemFree(g_jmms_context->send_content_p);
        }
        g_jmms_context->send_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
        jdi_UtilsCharToTchar(&(g_jmms_context->send_content_p->pFileName), temp);
        g_jmms_context->send_content_p->pStream = (void*)g_jmms_context->send_content_p->pFileName;
        g_jmms_context->send_content_p->bIsStream = E_TRUE;
        g_jmms_context->send_content_p->cbWriteCallback = mmi_jmms_write_callback;
    }

/******************************************************************************
 This modification is made to make the send MMS process async.

 Modified By          : Raj Kumar Gupta
 Date of Modification : 08 June 2006

 *****************************************************************************/

    if (g_jmms_context->async_send_context.params != NULL)
    {
        jdd_MemFree(g_jmms_context->async_send_context.params);
    }
    param_list = (mmi_jmms_async_send_params_struct*) jdd_MemAlloc(sizeof(mmi_jmms_async_send_params_struct), 1);
    param_list->is_stream = is_stream;
    param_list->comm_state = comm_state;
    param_list->msg_handle = msg_handle;
    param_list->retry_counter = retry_counter;

    g_jmms_context->async_send_context.params = param_list;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS ENCAPSULATION START");
    ret_code = mmi_jmms_jdi_encapsulate_buffer(msg_handle, g_jmms_context->send_content_p);

    /* Register the function that to be execute after the completion of the 
       encapsulation */
    mmi_jmms_add_send_callback_node(mmi_jmms_send_mms_async_callback);

    /* Check whether Encapsulation is completed or not */
    if (ret_code == JC_ERR_MMS_ENCODE_PENDING)
    {
        if (is_asynch == E_TRUE)
        {
            /* Start the Timer */
            mmi_jmms_send_continue_start_timer(msg_handle);
        }
        else
        {
            while (ret_code == JC_ERR_MMS_ENCODE_PENDING)
            {
                ret_code = mmi_jmms_jdi_msg_encapsulate_continue(msg_handle);
            }
            /* To execute the function that to be called after the completion of 
               the encapsulation */
            mmi_jmms_decrement_send_callback_node(ret_code);
        }
    }
    else
    {
        /* To execute the function that to be called after the completion of 
           the encapsulation */
        mmi_jmms_decrement_send_callback_node(ret_code);
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_send_synchronous_mms
 * DESCRIPTION
 *  used to send synchronous MMS
 * PARAMETERS
 *  msg_handle          [IN]        
 *  comm_state          [IN]        
 *  is_stream           [IN]        
 *  retry_counter       [IN]        
 *  is_asynch           [IN]        
 *  unique_id_p         [IN]        
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_jmms_send_synchronous_mms(
            MSG_HANDLE msg_handle,
            U16 comm_state,
            JC_BOOLEAN is_stream,
            U8 retry_counter,
            JC_BOOLEAN is_asynch,
            U32 *unique_id_p)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    CONTENT_DATA *content_data_p = NULL;
    JC_UINT32 reference_id = 1;
    COMM_FETCH_URL fertch_url_info = {0, };
    U32 fs_not_init = 0;
    JC_CHAR *file_name_p = NULL;
    U8 *temp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_send_synchronous_mms");

    if (is_stream == E_TRUE)
    {
        JC_INT8 temp[50] = {0, };

        (*unique_id_p)++;
        if ((*unique_id_p) > 200000)
        {
            (*unique_id_p) = 0;
        }

        jc_sprintf(temp, "%s%d", "@mms\\temp\\jmms_tempSendBuff", (*unique_id_p));

        content_data_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
        jdi_UtilsCharToTchar(&(content_data_p->pFileName), temp);
        content_data_p->pStream = (void*)content_data_p->pFileName;
        content_data_p->bIsStream = E_TRUE;
        content_data_p->cbWriteCallback = mmi_jmms_write_callback;
    }
    else
    {
        ASSERT(0);
    }

    ret_code = mmi_jmms_jdi_encapsulate_buffer(msg_handle, content_data_p);

    while (ret_code == JC_ERR_MMS_ENCODE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_encapsulate_continue(msg_handle);
    }

    if (JC_OK != ret_code)
    {
        if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            ret_code = E_JMMS_STORAGE_FULL;
        }

    }
    else
    {
        fertch_url_info.eContentMode = E_COMM_BUFFER;
        temp_p = mmi_jmms_get_activated_mmsc_url(g_jmms_context);
        fertch_url_info.pszURL = (JC_CHAR*) temp_p;
        fertch_url_info.pszContentType = "application/vnd.wap.mms-message";

        fertch_url_info.bIsFile = E_TRUE;
        fertch_url_info.uUserDataMode.pmFileName = content_data_p->pFileName;

        fertch_url_info.uiPostLen = content_data_p->uiTotalSize;
        fertch_url_info.pHeadersInfo = (COMM_HEADERS*) jdd_MemAlloc(sizeof(COMM_HEADERS), 1);
        fertch_url_info.pHeadersInfo->pszName = "Accept";
        fertch_url_info.pHeadersInfo->psValue = "*/*";
        fertch_url_info.pHeadersInfo->uiValueSize = 3;
        fertch_url_info.pHeadersInfo->pszCharset = "utf-8";
        fertch_url_info.pHeadersInfo->pNext = NULL;
        fertch_url_info.eCommFetchType = E_COMM_FETCH_POST;
        ret_code = jdi_CommunicationFetchURL(g_jmms_context->comm_handle, &fertch_url_info, &reference_id);
        if (ret_code == JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Synch Send , Request id", reference_id);

            file_name_p = jdi_UtilsTcsDup(content_data_p->pFileName);
            ret_code = mmi_jmms_add_comm_node(g_jmms_context,
                                              reference_id, comm_state, file_name_p, 0, retry_counter, NULL
        #ifdef __MMI_UNIFIED_COMPOSER__
                                              , NULL
        #endif 
                );
            if (ret_code != JC_OK)
            {
                jdi_CommunicationFreeReference(g_jmms_context->comm_handle, reference_id);
                ret_code = E_JMMS_GENERAL_ERROR;
            }
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d %s %d",
                                 "mmi_jmms_send_synchronous_mms with request Id",
                                 g_jmms_context->reference_id, "Returned error code: ", ret_code);
        }
        if (ret_code == JC_OK)
        {
            switch (comm_state)
            {
                case E_TYPE_NOTIFICATION_RESPONSE:
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Synch Send Request for Notf-Response",
                                         reference_id);
                    break;
                case E_TYPE_ACK_RESPONSE:
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Synch Send Request for Ack-Response",
                                         reference_id);
                    break;
                case E_TYPE_READ_REPORT_PDU:
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Synch Send Request for Read Report PDU",
                                         reference_id);
                    break;
                case E_TYPE_READ_REPORT_MMS:
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Synch Send Request for Read Report MMS",
                                         reference_id);
                    break;

            }
        }

        if (ret_code != JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "Sync Sending returns, Error Code:", ret_code);

            if (content_data_p != NULL && content_data_p->pStream != NULL)
            {
                if (g_jmms_context->jmms_fs_handle == NULL)
                {
                    if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
                    {
                        fs_not_init = 1;
                    }
                }

                if (!fs_not_init)
                {
                    jdd_FSDelete(g_jmms_context->jmms_fs_handle, content_data_p->pStream);

                    if (g_jmms_context->jmms_fs_handle != NULL)
                    {
                        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                        g_jmms_context->jmms_fs_handle = NULL;
                    }
                }
            }
            if (file_name_p != NULL)
            {
                jdd_MemFree(file_name_p);
            }

        }

        if (content_data_p != NULL)
        {
            if (content_data_p->pStream != NULL)
            {
                jdd_MemFree(content_data_p->pStream);
            }
            if (content_data_p->pBuffer != NULL)
            {
                jdd_MemFree(content_data_p->pBuffer);
            }
            jdd_MemFree(content_data_p);
        }
        if (fertch_url_info.pHeadersInfo != NULL)
        {
            jdd_MemFree(fertch_url_info.pHeadersInfo);
        }

        if (g_jmms_context->activated_mmsc_url_p != NULL)
        {
            jdd_MemFree(g_jmms_context->activated_mmsc_url_p);
            g_jmms_context->activated_mmsc_url_p = NULL;
        }

    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_send_mms_async_callback
 * DESCRIPTION
 *  Function for asynchronous MMS sending
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_send_mms_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_p = NULL;
    JC_UINT32 reference_id = 1;
    COMM_FETCH_URL fertch_url_info = {0, };
    mmi_jmms_async_send_params_struct *param_list = NULL;
    JC_CHAR *file_name_p = NULL;

#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_uc_start_comm_struct start_comm_data = {0, 0};
    mmi_jmms_uc_error_struct error_data = {0, NULL};
    mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "mmi_jmms_send_mms_async_callback, Return Code:", ret_code);

    if (g_jmms_context->async_send_context.params == NULL)
    {
        return;
    }
    param_list = g_jmms_context->async_send_context.params;

    if (JC_OK != ret_code)
    {
        if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            ret_code = E_JMMS_STORAGE_FULL;
        }
        goto END;
    }
    fertch_url_info.eContentMode = E_COMM_BUFFER;
    temp_p = mmi_jmms_get_activated_mmsc_url(g_jmms_context);
    fertch_url_info.pszURL = (JC_CHAR*) temp_p;
    fertch_url_info.pszContentType = "application/vnd.wap.mms-message";
    if (g_jmms_context->send_content_p->bIsStream == E_FALSE)
    {
        fertch_url_info.bIsFile = E_FALSE;
        fertch_url_info.uUserDataMode.pucPostData = g_jmms_context->send_content_p->pBuffer;
    }
    else
    {
        fertch_url_info.bIsFile = E_TRUE;
        fertch_url_info.uUserDataMode.pmFileName = g_jmms_context->send_content_p->pFileName;
    }
    fertch_url_info.uiPostLen = g_jmms_context->send_content_p->uiTotalSize;
    fertch_url_info.eCommFetchType = E_COMM_FETCH_POST;
    fertch_url_info.pHeadersInfo = (COMM_HEADERS*) jdd_MemAlloc(sizeof(COMM_HEADERS), 1);
    if (fertch_url_info.pHeadersInfo == NULL)
    {
        return;
    }
    fertch_url_info.pHeadersInfo->pszName = "Accept";
    fertch_url_info.pHeadersInfo->psValue = "*/*";
    fertch_url_info.pHeadersInfo->uiValueSize = 3;
    fertch_url_info.pHeadersInfo->pszCharset = "utf-8";
    fertch_url_info.pHeadersInfo->pNext = NULL;
    if (strlen(mmi_jmms_get_mms_profile_user_name()) || strlen(mmi_jmms_get_mms_profile_password()))
    {
        fertch_url_info.pProxyAuthHeaders = (COMM_AUTH_HEADERS*) jdd_MemAlloc(1, sizeof(COMM_AUTH_HEADERS));
        if (NULL == fertch_url_info.pProxyAuthHeaders)
        {
            return;
        }
        fertch_url_info.pProxyAuthHeaders->eAuthType = E_COMM_AUTHORIZATION_BASIC;
        mmi_asc_to_ucs2((S8*) fertch_url_info.pProxyAuthHeaders->szName, mmi_jmms_get_mms_profile_user_name());
        mmi_asc_to_ucs2((S8*) fertch_url_info.pProxyAuthHeaders->szPassword, mmi_jmms_get_mms_profile_password());
    }
    if (param_list->comm_state == E_TYPE_NEW_MMS || param_list->comm_state == E_TYPE_NEW_JAVA_MMS_SEND) /* both java mms and normal mms should not */
    {
        g_jmms_context->reference_id = 0;
        ret_code = jdi_CommunicationFetchURL(g_jmms_context->comm_handle, &fertch_url_info, &(g_jmms_context->reference_id));
        if (ret_code == JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Comm Fetch URL for New MMS SEND, Request Id: ",
                                 g_jmms_context->reference_id);

            file_name_p = jdi_UtilsTcsDup(g_jmms_context->send_content_p->pFileName);
            ret_code = mmi_jmms_add_comm_node(g_jmms_context,
                                              g_jmms_context->reference_id,
                                              param_list->comm_state, file_name_p, 0, param_list->retry_counter, NULL
        #ifdef __MMI_UNIFIED_COMPOSER__
                                              , g_jmms_context->ext_cb
        #endif 
                );
        #ifdef __MMI_UNIFIED_COMPOSER__
            g_jmms_context->ext_cb = NULL;
        #endif 
            if (ret_code != JC_OK)
            {
                jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
                g_jmms_context->reference_id = 0;
                ret_code = E_JMMS_GENERAL_ERROR;
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "mmi_jmms_send_mms_async_callback, Error Code:",
                                     ret_code);
                goto END;
            }
        #ifdef __MMI_UNIFIED_COMPOSER__
            g_jmms_context->ext_cb = NULL;
            communication_handle_p = mmi_jmms_get_comm_state(g_jmms_context, g_jmms_context->reference_id);
        #endif /* __MMI_UNIFIED_COMPOSER__ */ 
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d %s %d",
                                 "JMMS jdi_CommunicationFetchURL for NEW MMS Send with request Id",
                                 g_jmms_context->reference_id, "Returned error code: ", ret_code);

        }
    }
    else
    {
        ret_code = jdi_CommunicationFetchURL(g_jmms_context->comm_handle, &fertch_url_info, &reference_id);
        if (ret_code == JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Comm Fetch URL for MMS Send, Request id",
                                 reference_id);

            file_name_p = jdi_UtilsTcsDup(g_jmms_context->send_content_p->pFileName);
            ret_code = mmi_jmms_add_comm_node(g_jmms_context,
                                              reference_id,
                                              param_list->comm_state, file_name_p, 0, param_list->retry_counter, NULL
        #ifdef __MMI_UNIFIED_COMPOSER__
                                              , g_jmms_context->ext_cb
        #endif 
                );
            if (ret_code != JC_OK)
            {
                jdi_CommunicationFreeReference(g_jmms_context->comm_handle, reference_id);
                ret_code = E_JMMS_GENERAL_ERROR;
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "mmi_jmms_send_mms_async_callback, Error Code:",
                                     ret_code);
                goto END;
            }
        #ifdef __MMI_UNIFIED_COMPOSER__
            g_jmms_context->ext_cb = NULL;
            communication_handle_p = mmi_jmms_get_comm_state(g_jmms_context, reference_id);
        #endif /* __MMI_UNIFIED_COMPOSER__ */ 
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d %s %d",
                                 "JMMS jdi_CommunicationFetchURL for Send MMS with request Id",
                                 g_jmms_context->reference_id, "Returned error code: ", ret_code);
        }
    }

    if (ret_code == JC_OK)
    {
        switch (param_list->comm_state)
        {
            case E_TYPE_NEW_MMS:
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Send Request for New MMS",
                                     g_jmms_context->reference_id);
                break;
            case E_TYPE_NEW_JAVA_MMS_SEND:
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Send Request for New Java MMS",
                                     g_jmms_context->reference_id);
                break;
            case E_TYPE_NOTIFICATION_RESPONSE:
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Send Request for Notf-Response", reference_id);
                break;
            case E_TYPE_ACK_RESPONSE:
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Send Request for Ack-Response", reference_id);
                break;
            case E_TYPE_READ_REPORT_PDU:
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Send Request for Read Report PDU", reference_id);
                break;
            case E_TYPE_READ_REPORT_MMS:
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Send Request for Read Report MMS", reference_id);
                break;

        }
    }

  END:

    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "mmi_jmms_send_mms_async_callback, Error Code:", ret_code);

        if (g_jmms_context->send_content_p != NULL && g_jmms_context->send_content_p->pStream != NULL)
        {
            if (g_jmms_context->jmms_fs_handle == NULL)
            {
                if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "jdd_FSInitialize Failed");
                    jdd_MemFree(g_jmms_context->async_send_context.params);
                    g_jmms_context->async_send_context.params = NULL;
                #ifdef __MMI_UNIFIED_COMPOSER__
                    if (E_TYPE_NEW_MMS == param_list->comm_state)
                    {
                        error_data.error_code = ret_code;
                        error_data.communication_handle_p = NULL;
                        /* call callback to tell external layer about the error */
                        if (NULL != g_jmms_context->ext_cb)
                        {
                            g_jmms_context->ext_cb(MMS_SENDING_ERROR_CALLBACK, (void*)&error_data);
                        }
                    }
                #else /* __MMI_UNIFIED_COMPOSER__ */ 
                    mmi_jmms_decrement_send_callback_node(JC_ERR_FILE_SYS_INIT);
                #endif /* __MMI_UNIFIED_COMPOSER__ */ 
                    return;
                }
            }

            jdd_FSDelete(g_jmms_context->jmms_fs_handle, g_jmms_context->send_content_p->pStream);

            if (g_jmms_context->jmms_fs_handle != NULL)
            {
                jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                g_jmms_context->jmms_fs_handle = NULL;
            }
        }

        if (file_name_p != NULL)
        {
            jdd_MemFree(file_name_p);
        }
    #ifdef __MMI_UNIFIED_COMPOSER__
        if (E_TYPE_NEW_MMS == param_list->comm_state)
        {
            error_data.error_code = ret_code;
            error_data.communication_handle_p = NULL;
            /* call callback to tell external layer about the error */
            if (NULL != g_jmms_context->ext_cb)
            {
                g_jmms_context->ext_cb(MMS_SENDING_ERROR_CALLBACK, (void*)&error_data);
            }
        }
    #endif /* __MMI_UNIFIED_COMPOSER__ */ 
    }
    if (g_jmms_context->send_content_p != NULL)
    {
        if (g_jmms_context->send_content_p->pStream != NULL)
        {
            jdd_MemFree(g_jmms_context->send_content_p->pStream);
        }
        if (g_jmms_context->send_content_p->pBuffer != NULL)
        {
            jdd_MemFree(g_jmms_context->send_content_p->pBuffer);
        }
        jdd_MemFree(g_jmms_context->send_content_p);
        g_jmms_context->send_content_p = NULL;
    }
    if (fertch_url_info.pHeadersInfo != NULL)
    {
        jdd_MemFree(fertch_url_info.pHeadersInfo);
    }
    if (fertch_url_info.pProxyAuthHeaders)
    {
        jdd_MemFree(fertch_url_info.pProxyAuthHeaders);
    }

    if (g_jmms_context->activated_mmsc_url_p != NULL)
    {
        jdd_MemFree(g_jmms_context->activated_mmsc_url_p);
        g_jmms_context->activated_mmsc_url_p = NULL;
    }

    jdd_MemFree(g_jmms_context->async_send_context.params);
    g_jmms_context->async_send_context.params = NULL;
#ifdef __MMI_UNIFIED_COMPOSER__
    if (E_TYPE_NEW_MMS == param_list->comm_state && communication_handle_p)
    {
        start_comm_data.msg_handle = g_jmms_context->msg_handle;
        start_comm_data.communication_handle_p = communication_handle_p;

        /* call callback to indicate external layer that the sending has started. */
        /* this will help external layer to map communication handle with message handle */
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Sent start indication to external interface");
        communication_handle_p->callback(MMS_SENDING_START_CALLBACK, (void*)&start_comm_data);
    }
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    mmi_jmms_decrement_send_callback_node(ret_code);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_resend_mms
 * DESCRIPTION
 *  Used to resend MMS
 * PARAMETERS
 *  comm_node_p         [IN]        
 *  retry_counter       [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_resend_mms(mmi_jmms_communication_state_node_struct *comm_node_p, U8 retry_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    COMM_FETCH_URL fertch_url_info = {0, };
    JC_UINT32 reference_id = 1;
    JC_RETCODE ret_code = JC_OK;
    CONTENT_DATA encapsulated_content = {0, };
    U8 *temp_p = NULL;
    JC_UINT32 file_length = 0;
    JDD_FILE file_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT VIKAS START 20060401 */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_resend_mms");

    /* PMT VIKAS END 20060401 */
    if (comm_node_p->send_file_name_p == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto END;
    }

    encapsulated_content.pStream = comm_node_p->send_file_name_p;
    encapsulated_content.pFileName = encapsulated_content.pStream;
    encapsulated_content.bIsStream = E_TRUE;
    encapsulated_content.cbWriteCallback = mmi_jmms_write_callback;

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            ret_code = JC_ERR_FILE_OPEN;
            goto END;
        }
    }

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (JC_CHAR*) encapsulated_content.pStream, E_OPEN_READ_MODE);
    if (file_handle == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto END;
    }

    ret_code = jdd_FSGetSize(file_handle, &file_length);
    if (JC_OK != ret_code)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto END;
    }

    encapsulated_content.uiTotalSize = file_length;

    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
        file_handle = NULL;
    }

    /* / 7 March */
    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    fertch_url_info.eContentMode = E_COMM_BUFFER;

    temp_p = mmi_jmms_get_activated_mmsc_url(g_jmms_context);
    fertch_url_info.pszURL = (JC_CHAR*) temp_p;
    /* if(encapsulated_content.VIEW_MODE.contentInline.pBuffer!=NULL) */
    fertch_url_info.pszContentType = "application/vnd.wap.mms-message";
    fertch_url_info.bIsFile = E_TRUE;
    fertch_url_info.uUserDataMode.pmFileName = encapsulated_content.pFileName;
    fertch_url_info.uiPostLen = encapsulated_content.uiTotalSize;
    fertch_url_info.eCommFetchType = E_COMM_FETCH_POST;
    fertch_url_info.pHeadersInfo = (COMM_HEADERS*) jdd_MemAlloc(sizeof(COMM_HEADERS), 1);
    if (fertch_url_info.pHeadersInfo == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }
    fertch_url_info.pHeadersInfo->pszName = "Accept";
    fertch_url_info.pHeadersInfo->psValue = "*/*";
    fertch_url_info.pHeadersInfo->uiValueSize = 3;
    fertch_url_info.pHeadersInfo->pszCharset = "utf-8";
    fertch_url_info.pHeadersInfo->pNext = NULL;
    if (strlen(mmi_jmms_get_mms_profile_user_name()) || strlen(mmi_jmms_get_mms_profile_password()))
    {
        fertch_url_info.pProxyAuthHeaders = (COMM_AUTH_HEADERS*) jdd_MemAlloc(sizeof(COMM_AUTH_HEADERS), 1);
        if (fertch_url_info.pProxyAuthHeaders == NULL)
        {
            return JC_ERR_MEMORY_ALLOCATION;
        }
        fertch_url_info.pProxyAuthHeaders->eAuthType = E_COMM_AUTHORIZATION_BASIC;
        mmi_asc_to_ucs2((S8*) fertch_url_info.pProxyAuthHeaders->szName, mmi_jmms_get_mms_profile_user_name());
        mmi_asc_to_ucs2((S8*) fertch_url_info.pProxyAuthHeaders->szPassword, mmi_jmms_get_mms_profile_password());
    }
    if (comm_node_p->mms_communication_state == E_TYPE_NEW_MMS
        || comm_node_p->mms_communication_state == E_TYPE_NEW_JAVA_MMS_SEND)
    {
        g_jmms_context->reference_id = 0;

        ret_code = jdi_CommunicationFetchURL(g_jmms_context->comm_handle, &fertch_url_info, &(g_jmms_context->reference_id));
        if (ret_code == JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Comm Fetch Resend MMS", g_jmms_context->reference_id);
        #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
            g_jmms_context->g_reference_id = g_jmms_context->reference_id;
        #endif 
            ret_code = mmi_jmms_update_comm_node(
                        g_jmms_context,
                        g_jmms_context->reference_id,
                        comm_node_p->reference_id,
                        retry_counter);
            if (ret_code != JC_OK)
            {
                jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
                g_jmms_context->reference_id = 0;
                ret_code = JC_ERR_MEMORY_ALLOCATION;
            }
        }

    }
    else
    {
        ret_code = jdi_CommunicationFetchURL(g_jmms_context->comm_handle, &fertch_url_info, &(reference_id));
        if (ret_code == JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "JMMS Comm Fetch Resend", reference_id);

            ret_code = mmi_jmms_update_comm_node(g_jmms_context, reference_id, comm_node_p->reference_id, retry_counter);
            if (ret_code != JC_OK)
            {
                jdi_CommunicationFreeReference(g_jmms_context->comm_handle, reference_id);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
            }

            /* PRINT_INFORMATION_2( MMI_TRACE_INFO, "%s(%d)","JMMS Comm Node Updated",reference_id); */
        }
    }

  END:
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "mmi_jmms_resend_mms Returns with:", ret_code);
    if (fertch_url_info.pHeadersInfo != NULL)
    {
        jdd_MemFree(fertch_url_info.pHeadersInfo);
    }
    if (fertch_url_info.pProxyAuthHeaders)
    {
        jdd_MemFree(fertch_url_info.pProxyAuthHeaders);
    }
    return ret_code;
}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_communication_progress_screen
 * DESCRIPTION
 *  Used to show communication progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
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
    SetRightSoftkeyFunction(mmi_jmms_cancel_mms_sending, KEY_EVENT_UP);
    mmi_jmms_set_end_key_progressing_handler();
}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_end_comm
 * DESCRIPTION
 *  used to end communication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_end_comm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_end_comm");
#if defined (__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_jmms_cancel_comm_in_usb_mode();
        return;
    }

#endif /* defined (__USB_IN_NORMAL_MODE__) */ 
    if (g_jmms_context->reference_id != 0)
    {

    #ifndef __MMI_UNIFIED_COMPOSER__
        mmi_jmms_del_inserted_auto_signature_slide();
    #endif /* #ifndef __MMI_UNIFIED_COMPOSER__ */
        jdi_CommunicationStopReq(g_jmms_context->comm_handle, g_jmms_context->reference_id);
        jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
        comm_node_p = mmi_jmms_get_comm_state(g_jmms_context, g_jmms_context->reference_id);
        if (comm_node_p)    /* Vikram : This is required to stop retry incase of user abort */
        {
            comm_node_p->retry_counter = STOP_RETRY_COUNTER;
        }

        g_jmms_context->reference_id = 0;
        if (g_jmms_context->last_scr_id != SCR_ID_JMMS_OUTBOX_OPTIONS)
        {
            g_jmms_context->save_mms = MMI_TRUE;
        }
        g_jmms_context->last_scr_id = IDLE_SCREEN_ID;
    }
    else if (GetActiveScreenId() == SCR_ID_JMMS_PROGRESS)
    {
        mmi_jmms_decrement_send_callback_node(E_COMMUNICATION_ABORTED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_cancel_comm_in_usb_mode
 * DESCRIPTION
 *  Used to cancel communication on USB plug in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_cancel_comm_in_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "USB Mode: Stop All Comm");
    comm_node_p = g_jmms_context->comm_state_p;
    while (comm_node_p)
    {
        if (comm_node_p->mms_communication_state != E_TYPE_NOTIFICATION_RESPONSE &&
            comm_node_p->mms_communication_state != E_TYPE_READ_REPORT_PDU &&
            comm_node_p->mms_communication_state != E_TYPE_ACK_RESPONSE &&
            comm_node_p->mms_communication_state != E_TYPE_READ_REPORT_MMS)
        {
            jdi_CommunicationStopReq(g_jmms_context->comm_handle, g_jmms_context->reference_id);
            mmi_jmms_free_comm_node(g_jmms_context, comm_node_p->reference_id);
            comm_node_p = g_jmms_context->comm_state_p;
        }
        else
        {
            comm_node_p = comm_node_p->next_p;
        }

    }
    mmi_jmms_stop_download_busy();  /* Added incase the download blinking is started but the comm node is not added to the list */
    mmi_jmms_update_status_icon_indicator();
}

#ifdef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_cancel_mms_sending
 * DESCRIPTION
 *  This function is called by middle layer to cancel MMS Sending/Downloading
 * PARAMETERS
 *  msg_handle                  [IN]        
 *  communication_handle_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_cancel_mms_sending(
            MSG_HANDLE msg_handle,
            mmi_jmms_communication_state_node_struct *communication_handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Enter mmi_jmms_uc_cancel_mms_sending");

    if (communication_handle_p)
    {
        if (communication_handle_p->callback)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Sending stop request to transport.");
            /* send stop request to transport layer */
            jdi_CommunicationStopReq(g_jmms_context->comm_handle, communication_handle_p->reference_id);
            jdi_CommunicationFreeReference(g_jmms_context->comm_handle, communication_handle_p->reference_id);
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO,
                                 "communication_handle was not NULL but communication_handle->callback was NULL");
            ASSERT(0);
        }
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Stop Message Encapsulation");
        /* if communication is not yet started stop the encapsulation */
        StopTimer(JMMS_ASYNC_SEND_TIMER);
        g_jmms_context->ext_cb = NULL;
    }
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_cancel_mms_downloading
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_cancel_mms_downloading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Enter mmi_jmms_cancel_mms_downloading");

    /* cancel all request for sending */
    if (g_jmms_context->reference_id != 0)
    {
        communication_handle_p = g_jmms_context->comm_state_p;
        while (communication_handle_p)
        {
            if (E_TYPE_NEW_MMS == communication_handle_p->mms_communication_state ||
                E_TYPE_DEFFERED_RETRIEVAL_FETCH == communication_handle_p->mms_communication_state)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "Cancel MMS sending for:%d",
                                     communication_handle_p->reference_id);
                jdi_CommunicationStopReq(g_jmms_context->comm_handle, communication_handle_p->reference_id);
                mmi_jmms_free_comm_node(g_jmms_context, communication_handle_p->reference_id);
            }
            communication_handle_p = communication_handle_p->next_p;
        }
    }
    /* stop timer for encapsulation */
    StopTimer(JMMS_ASYNC_SEND_TIMER);
    g_jmms_context->ext_cb = NULL;
    if (IsScreenPresent(SCR_ID_UM_INBOX))
    {
        DeleteUptoScrID(SCR_ID_UM_INBOX);
        GoBackHistory();
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Leave mmi_jmms_cancel_mms_downloading");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_cancel_all_mms_sending
 * DESCRIPTION
 *  This function cancel sending of all the MMSs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_cancel_all_mms_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Enter mmi_jmms_cancel_all_mms_sending");

    /* cancel all request for sending */
    if (g_jmms_context->reference_id != 0)
    {
        communication_handle_p = g_jmms_context->comm_state_p;
        while (communication_handle_p)
        {
            if (E_TYPE_NEW_MMS == communication_handle_p->mms_communication_state ||
                E_TYPE_DEFFERED_RETRIEVAL_FETCH == communication_handle_p->mms_communication_state)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "Cancel MMS sending for:%d",
                                     communication_handle_p->reference_id);
                jdi_CommunicationStopReq(g_jmms_context->comm_handle, communication_handle_p->reference_id);
                mmi_jmms_free_comm_node(g_jmms_context, communication_handle_p->reference_id);
            }
            communication_handle_p = communication_handle_p->next_p;
        }
    }
    /* stop timer for encapsulation */
    StopTimer(JMMS_ASYNC_SEND_TIMER);
    g_jmms_context->ext_cb = NULL;
    if (IsScreenPresent(SCR_ID_UM_INBOX))
    {
        DeleteUptoScrID(SCR_ID_UM_INBOX);
        GoBackHistory();
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Leave mmi_jmms_cancel_all_mms_sending");
}
#else /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_cancel_mms_sending
 * DESCRIPTION
 *  used to cancel MMS sending / downloading
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_cancel_mms_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_del_inserted_auto_signature_slide();
#endif /* #ifndef __MMI_UNIFIED_COMPOSER__ */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s (%d)", "mmi_jmms_cancel_mms_sending, Reference id",
                         g_jmms_context->reference_id);

#ifdef __MMI_JMMS_SEND_RETRIES__
    mmi_jmms_set_progress_screen_title(0);
#endif 

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
    mmi_jmms_stop_timeout_timer();
#endif 

    if (g_jmms_context->reference_id != 0)
    {
        jdi_CommunicationStopReq(g_jmms_context->comm_handle, g_jmms_context->reference_id);
        jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
        comm_node_p = mmi_jmms_get_comm_state(g_jmms_context, g_jmms_context->reference_id);
        if (comm_node_p)    /* Vikram : This is required to stop retry incase of user abort */
        {
            comm_node_p->retry_counter = STOP_RETRY_COUNTER;
        }
    }
    else
    {
        StopTimer(JMMS_ASYNC_SEND_TIMER);
        mmi_jmms_decrement_send_callback_node(E_COMMUNICATION_ABORTED);
        goto END;
    }
    g_jmms_context->reference_id = 0;

    mmi_jmms_update_status_icon_indicator();
  END:
    /* Dilip Start 4 sept 2006 */
#ifdef __MMI_UNIFIED_MESSAGE__
    if (IsScreenPresent(SCR_ID_JMMS_WRITE_MMS))
    {
        DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
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
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    return;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    /* Dilip End 4 sept 2006 */
}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_for_idle_screen
 * DESCRIPTION
 *  Used to show full screen pop up on idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_check_for_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    screen_id = GetActiveScreenId();

    if (screen_id == IDLE_SCREEN_ID)
    {
        if (g_jmms_context->store_context)
        {
            g_jmms_context->store_context->current_folder_name = 0;
        }
        if (mmi_jmms_need_mms_ind())
        {
            TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
            mmi_jmms_entry_new_mms_ind();
            DisplayIdleScreen();
        }
    }
}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_new_mms_pop_up
 * DESCRIPTION
 *  Used to show new MMS pop up
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
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retry_communication
 * DESCRIPTION
 *  Used to retry communication
 * PARAMETERS
 *  jmms_context_p          [IN]        
 *  calling_function        [IN]        
 *  reference_id            [IN]        
 *  error_code              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_retry_communication(
            mmi_jmms_context_struct *jmms_context_p,
            U16 calling_function,
            JC_UINT32 reference_id,
            JC_RETCODE error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;

#ifdef __MMI_UNIFIED_COMPOSER__ /* Add on 03102007 */
    mmi_jmms_comm_progress_struct progress_ind_data = {0, };
#endif 

    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "mmi_jmms_retry_communication, Reference Id:", reference_id);
    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, reference_id);
    /* To avoid crash incase comm_node_p is NULL */
    if (comm_node_p == NULL)
    {
        return E_UNKNOWN_MSG;
    }

    if (comm_node_p->retry_counter == STOP_RETRY_COUNTER)
    {
        return ret_code;
    }
    switch (comm_node_p->mms_communication_state)
    {
        case E_TYPE_NEW_MMS:
    #ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
        case E_TYPE_NEW_JAVA_MMS_SEND:
    #endif 
    #ifdef __MMI_JMMS_SEND_RETRIES__
            mmi_jmms_set_progress_screen_title(0);
    #endif 

    #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
            mmi_jmms_stop_timeout_timer();
    #endif 
            if (comm_node_p->retry_counter < MAX_MMS_SEND_TRY_COUNTER)
            {
                comm_node_p->retry_counter++;
            #ifdef __MMI_UNIFIED_COMPOSER__ /* Add on 03102007 */
                if ((comm_node_p->mms_communication_state == E_TYPE_NEW_MMS) && comm_node_p->callback)
                {
                    progress_ind_data.progress_ind_p = NULL;
                    progress_ind_data.communication_handle_p = comm_node_p;
                    comm_node_p->callback(MMS_COMMUNICATION_PROGRESS_CALLBACK, (void*)&progress_ind_data);
                }
            #endif /* __MMI_UNIFIED_COMPOSER__ */ 

                ret_code = mmi_jmms_resend_mms(comm_node_p, comm_node_p->retry_counter);

                if (JC_OK != ret_code)
                {

                    goto END;
                }

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS Resending New MMS Try No",
                                     comm_node_p->retry_counter);

            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Resending New MMS Try Complete");
                ret_code = E_JMMS_RETRY_COMPLETE;
                goto END;
            }
            break;
        case E_TYPE_READ_REPORT_PDU:
        case E_TYPE_READ_REPORT_MMS:
            if (comm_node_p->retry_counter < MAX_MMS_SIGNAL_TRY_COUNTER)
            {
                comm_node_p->retry_counter++;

                ret_code = mmi_jmms_resend_mms(comm_node_p, comm_node_p->retry_counter);

                if (JC_OK != ret_code)
                {

                    goto END;
                }

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS Resending Read Report Try No",
                                     comm_node_p->retry_counter);

            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Resending Read Report Try Complete");
                ret_code = E_JMMS_RETRY_COMPLETE;   /* /no try counter left */
                goto END;
            }
            break;

        case E_TYPE_ACK_RESPONSE:
        case E_TYPE_NOTIFICATION_RESPONSE:
            if (comm_node_p->retry_counter < MAX_MMS_SIGNAL_TRY_COUNTER)
            {

                comm_node_p->retry_counter++;
                ret_code = mmi_jmms_resend_mms(comm_node_p, comm_node_p->retry_counter);

                if (JC_OK != ret_code)
                {

                    goto END;
                }

                if (comm_node_p->mms_communication_state == E_TYPE_ACK_RESPONSE)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS Resending ACK Try No",
                                         comm_node_p->retry_counter);
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS Resending Notify-Response Try No",
                                         comm_node_p->retry_counter);
                }

            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Resending ACK Try Complete");
                ret_code = E_JMMS_RETRY_COMPLETE;   /* /no try counter left */
                goto END;
            }
            break;
        case E_TYPE_IMMEDIATE_RETRIEVAL_FETCH:
        case E_TYPE_DEFFERED_RETRIEVAL_FETCH:
            if (comm_node_p->retry_counter < MAX_MMS_DOWNLOAD_TRY_COUNTER)
            {
                if (comm_node_p->mms_content_location_p != NULL)
                {
                    comm_node_p->retry_counter++;
                    if (E_TYPE_DEFFERED_RETRIEVAL_FETCH == comm_node_p->mms_communication_state)
                    {
                        ret_code = mmi_jmms_download_mms(comm_node_p->mms_content_location_p,
                                                         comm_node_p->mms_communication_state,
                                                         comm_node_p->msg_index, comm_node_p->retry_counter
                    #ifdef __MMI_UNIFIED_COMPOSER__
                                                         , mmi_jmms_handle_screen_flow_callback
                    #endif 
                            );
                        if (JC_OK == ret_code)
                        {
                            mmi_jmms_free_comm_node(jmms_context_p, reference_id);
                        }

                    #if defined(__MMI_JMMS_EXPIRY_HANDLING__) || defined(__MMI_JMMS_NO_OMA_CONF_273__)
                        if (ret_code == E_MESSAGE_EXPIRED || ret_code == E_MEMORY_FULL_ERROR)
                        {
                            error_code = ret_code;
                        }
                    #endif /* defined(__MMI_JMMS_EXPIRY_HANDLING__) || defined(__MMI_JMMS_NO_OMA_CONF_273__) */ 
                    }
                    else
                    {
                        ret_code = mmi_jmms_download_mms(comm_node_p->mms_content_location_p,
                                                         comm_node_p->mms_communication_state,
                                                         comm_node_p->msg_index, comm_node_p->retry_counter
                    #ifdef __MMI_UNIFIED_COMPOSER__
                                                         , NULL
                    #endif 
                            );
                        if (JC_OK == ret_code)
                        {
                            mmi_jmms_free_comm_node(jmms_context_p, reference_id);
                        }

                    #if defined(__MMI_JMMS_EXPIRY_HANDLING__) || defined(__MMI_JMMS_NO_OMA_CONF_273__)
                        if (ret_code == E_MESSAGE_EXPIRED || ret_code == E_MEMORY_FULL_ERROR)
                        {
                            error_code = ret_code;
                        }
                    #endif /* defined(__MMI_JMMS_EXPIRY_HANDLING__) || defined(__MMI_JMMS_NO_OMA_CONF_273__) */ 
                    }

                    if (JC_OK != ret_code)
                    {

                        goto END;
                    }

                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "JMMS Redownlaoding MMS Try No:",
                                         comm_node_p->retry_counter);

                }
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Redownloading MMS Try Complete");
                ret_code = E_JMMS_RETRY_COMPLETE;   /* /no try counter left */
                goto END;
            }

            break;

    }

    if (ret_code == JC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_JMMS_PROGRESS)
        {
            g_jmms_context->current_title_id = STR_ID_JMMS_RETRY;
        #ifdef __MMI_JMMS_SEND_RETRIES__
            mmi_jmms_change_title_string(STR_ID_JMMS_RETRY, comm_node_p->retry_counter);
        #else /* __MMI_JMMS_SEND_RETRIES__ */ 
            ChangeTitleString((U8*) GetString(STR_ID_JMMS_RETRY));
            draw_title();
        #endif /* __MMI_JMMS_SEND_RETRIES__ */ 
            cat66_update_progress_string();
        }
    }

  END:
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "Error in mmi_jmms_retry_communication, Error Code: ", ret_code);
    #ifdef __MMI_UNIFIED_COMPOSER__
        if (comm_node_p->mms_communication_state != E_TYPE_NEW_MMS)
    #endif 
        {
            mmi_jmms_handle_error_in_communication(jmms_context_p, calling_function, comm_node_p, error_code);
            mmi_jmms_free_comm_node(jmms_context_p, comm_node_p->reference_id);
        }
    }
    return ret_code;
}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_error_in_communication
 * DESCRIPTION
 *  Used to handle error in communication.
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

    #ifdef __MMI_JMMS_SEND_RETRIES__
            mmi_jmms_set_progress_screen_title(0);
    #endif 

    #ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
            mmi_jmms_stop_timeout_timer();
    #endif 
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
                        ret_code = mmi_jmms_send_and_store_mms("Outbox", jmms_context_p->msg_handle, comm_node_p);

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
                        ret_code = mmi_jmms_send_and_store_mms("Outbox", jmms_context_p->msg_handle, comm_node_p);
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

                        DeleteScreenFromToNnodes(SCR_ID_JMMS_PROGRESS, 3);
                    }
                    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                }
                else
                {
                    //it meas user selects "Resent" from Outbox.
                    ///in this case update the MMS into the outbox
                    ret_code = mmi_jmms_send_and_store_mms("Outbox", jmms_context_p->msg_handle, comm_node_p);
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
                // TODO:: need to display string accordinbg to error_code
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

                /* sandeep starts */
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
                /* sandeep ends */

                else
                {
                    mmi_jmms_show_new_mms_pop_up();
                }
            }
    }
#ifndef __MMI_UNIFIED_COMPOSER__
    // #ifdef __MMI_MMS_SIGNATURE__
    mmi_jmms_del_inserted_auto_signature_slide();
    // #endif
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_error_string
 * DESCRIPTION
 *  Used to show the desired error string
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

        case E_MEMORY_FULL_ERROR:
            if (communication_state == E_TYPE_DEFFERED_RETRIEVAL_FETCH)
            {
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MMS_SIZE_EXCEEDS);
            }
            return;
        case E_MESSAGE_EXPIRED:
            if (communication_state == E_TYPE_DEFFERED_RETRIEVAL_FETCH)
            {
                mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MMS_MSG_EXPIRED);
            }
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
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_em_mms_version
 * DESCRIPTION
 *  Used to get MMS version string
 * PARAMETERS
 *  void
 * RETURNS
 *  MMS version string
 *****************************************************************************/
S8 *mmi_jmms_get_em_mms_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (wap_custom_get_mms_version())
    {
        case EM_MMS_VERSION_10:
            /* Change MMS agent to version 1.0 no matter MMSC */
            return "1.0";
        case EM_MMS_VERSION_11:
            /* Change MMS agent to version 1.1 no matter MMSC */
            return "1.1";
        case EM_MMS_VERSION_12:
            /* Change MMS agent to version 1.2 no matter MMSC */
            return "1.2";
        default:
            return "1.0";
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_mmsc_version
 * DESCRIPTION
 *  Used to set MMS version string
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_OK                   on sucsess
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_mmsc_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE fh = 0;
    S32 error_code, len = 0;
    U32 read_len = 0, index;
    S8 *file_buffer_p = NULL;
    S8 file_name[(MAX_FILE_LENGTH + 1) * ENCODING_LENGTH];

    U8 *temp_uniocde_url = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_set_mmsc_version");

    g_jmms_context->version = jdd_MemAlloc(sizeof(S8), (MAX_VERSION_LENGTH + 1) * ENCODING_LENGTH);
    if (g_jmms_context->version == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;

        goto END;
    }

    /* /mmsc_url is mmsc url set in message settings */

    temp_uniocde_url = mmi_jmms_get_activated_mmsc_url(g_jmms_context);
    if (temp_uniocde_url == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }
    if (wap_custom_get_mms_version() == EM_MMS_VERSION_DEFAULT)
    {
        if ((g_jmms_context->last_mmsc_url != NULL)
            && (strcmp((S8*) (g_jmms_context->last_mmsc_url), (S8*) temp_uniocde_url) == 0))
        {
            strcpy((S8*) g_jmms_context->version, (S8*) g_jmms_context->last_version);
        }
        else
        {
            mmi_asc_to_ucs2((PS8) file_name, (PS8) MMS_MMSC_URLS_FILE_NAME);

            fh = FS_Open((const WCHAR*)file_name, FS_READ_ONLY);

            if (fh > 0) /* /file exists */
            {
                FS_GetFileSize(fh, (U32*) & len);
                file_buffer_p = (S8*) jdd_MemAlloc(sizeof(S8), len);

                if ((NULL == file_buffer_p) && (len > 0))
                {
                    ret_code = JC_ERR_MEMORY_ALLOCATION;
                    goto END;

                }

                if (len > 0)
                {
                    error_code = FS_Read(fh, file_buffer_p, len, &read_len);
                    if (error_code < 0)
                    {
                        ret_code = error_code;
                        goto END;

                    }
                }

                if (fh > 0)
                {
                    FS_Close(fh);
                }

                len = 0;
                index = 0;
                while ((read_len - index) != 0)
                {
                    len = (mmi_ucs2strlen(file_buffer_p + index) + 1) * ENCODING_LENGTH;

                    if (mmi_ucs2cmp((S8*) (file_buffer_p + index), (S8*) temp_uniocde_url) == 0)
                    {
                        index = index + len;
                        mmi_ucs2_to_asc((S8*) g_jmms_context->version, (S8*) (file_buffer_p + index));
                        break;
                    }
                    else
                    {
                        index = index + len;
                        len = (mmi_ucs2strlen(file_buffer_p + index) + 1) * ENCODING_LENGTH;
                        index = index + len;
                    }
                }

                read_len = read_len - index;

                if (read_len == 0)  /* /entry not found */
                {
                    /* /set the defualt version for MMS */
                    strcpy((PS8) g_jmms_context->version, (PS8) (mmi_jmms_get_em_mms_version()));
                }

                if (file_buffer_p)
                {
                    jdd_MemFree(file_buffer_p);
                    file_buffer_p = NULL;
                }

            }
            else
            {
                /* set the defualt version for MMS */
                strcpy((PS8) g_jmms_context->version, (PS8) (mmi_jmms_get_em_mms_version()));
            }
        }
    }
    else
    {
        strcpy((PS8) g_jmms_context->version, (PS8) (mmi_jmms_get_em_mms_version()));
    }

  END:

    if (file_buffer_p)
    {
        jdd_MemFree(file_buffer_p);
        file_buffer_p = NULL;
    }

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_notification_ack_response
 * DESCRIPTION
 *  Used to handle MMS notification acknowledgement response
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 *  content_data_p      [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_notification_ack_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_data_p,
            CONTENT_DATA *content_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_notification_ack_response");

    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

    url_ind_data_p->uiRequestID = 0;

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_read_report_pdu_response
 * DESCRIPTION
 *  Used to handle read report PDU response
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 *  content_data_p      [IN]        
 * RETURNS
 *  JC_ok                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_read_report_pdu_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_data_p,
            CONTENT_DATA *content_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_read_report_pdu_response");

    ret_code = mmi_jmms_add_pending_mms_info_node(
                (U16) STR_ID_JMMS_SUCCESS_READ_REPORT_SENT,
                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                NULL);
    if (ret_code == JC_OK)
    {
        mmi_jmms_check_for_idle_screen();
    }

    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

    url_ind_data_p->uiRequestID = 0;

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_read_report_mms_response
 * DESCRIPTION
 *  Used to handle read report MMS response
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 *  content_data_p      [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_read_report_mms_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_data_p,
            CONTENT_DATA *content_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    MSG_HANDLE temp_msg_handle = NULL;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    EMM1MessageType e_message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_read_report_mms_response");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&temp_msg_handle, content_data_p, E_TYPE_MMS, E_FALSE);

    /* Async changes start */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(temp_msg_handle);
    };
    /* Async changes end */

    if (ret_code != JC_OK)
    {
        ret_code = mmi_jmms_add_pending_mms_info_node(
                    (U16) STR_ID_JMMS_ERROR_READ_REPORT_SENT,
                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                    NULL);
        if (ret_code == JC_OK)
        {
            mmi_jmms_check_for_idle_screen();
        }
        goto CaseEnd;
    }
    ret_code = mmi_jmms_jdi_get_msg_headers(temp_msg_handle, &msg_headers_p);
    if (ret_code != JC_OK)
    {
        ret_code = mmi_jmms_add_pending_mms_info_node(
                    (U16) STR_ID_JMMS_ERROR_READ_REPORT_SENT,
                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                    NULL);
        if (ret_code == JC_OK)
        {
            mmi_jmms_check_for_idle_screen();
        }
        goto CaseEnd;
    }
    e_message = msg_headers_p->eMsgType;

    switch (msg_headers_p->eMsgType)
    {
        case E_MSG_TYPE_SEND_RESPONSE:
        {
            MESSAGE_SEND_RESPONSE *send_header_p = (MESSAGE_SEND_RESPONSE*) msg_headers_p->pHeaders;

            if (E_RESP_OK == send_header_p->eStatus)
            {
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_SUCCESS_READ_REPORT_SENT,
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

        }
            break;
    }

  CaseEnd:
    /* /added for retry mechanism */

    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

    if (NULL != temp_msg_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
        temp_msg_handle = NULL;
    }

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

    url_ind_data_p->uiRequestID = 0;

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_immediate_downlaod_response
 * DESCRIPTION
 *  Used to handle immediate download response
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 *  content_data_p      [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_immediate_downlaod_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_data_p,
            CONTENT_DATA *content_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* JC_UINT32 msgid = 0; */
    JC_RETCODE ret_code = JC_OK;
    MSG_HANDLE temp_msg_handle = NULL;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    JC_INT8 *content_type_p = NULL;
    JC_UINT32 msg_index;
    JC_RETCODE ret_val = JC_OK;

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    MESSAGE_RETRIEVAL *recv_headers_p = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_immediate_downlaod_response");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&temp_msg_handle, content_data_p, E_TYPE_MMS, E_FALSE);

    /* Async changes start */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(temp_msg_handle);
    }
    /* Async changes end */

    if (JC_OK != ret_code)
    {
        goto Endcase;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(temp_msg_handle, &msg_headers_p);
    if (ret_code != JC_OK || msg_headers_p == NULL)
    {
        goto Endcase;
    }

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    recv_headers_p = (MESSAGE_RETRIEVAL*) msg_headers_p->pHeaders;
    if (recv_headers_p->eStatus != E_RESP_OK && recv_headers_p->pStatusText)
    {
        ret_code = mmi_jmms_add_pending_mms_info_node(
                    (U16) 0,
                    E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER,
                    (S8*) recv_headers_p->pStatusText);
        if (JC_OK == ret_code)
        {
            mmi_jmms_check_for_idle_screen();
        }
        goto Endcase;
    }
#endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
    ///putting here as found that stroe_update change the file name
    ///so require to use before that
    ret_code = jmms_mmi_notification_response_for_immediate_retrieval(*content_data_p);

    if (msg_headers_p->eMsgType == E_MSG_TYPE_RECEIVE)
    {
        mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

        comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_data_p->uiRequestID);
        if (comm_node_p == NULL)
        {
            ret_code = mmi_jmms_add_pending_mms_info_node(
                        (U16) STR_ID_JMMS_NEW_MMS_NOT_SAVED,
                        (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                        NULL);
            if (ret_code == JC_OK)
            {
                mmi_jmms_check_for_idle_screen();
            }
            goto Endcase;
        }

        PRINT_INFORMATION_2(MMI_TRACE_INFO, "(%d) Comm Node index = %d", __LINE__, comm_node_p->msg_index);

        if (comm_node_p->msg_index == 0)    /* /it means notification didn't save successfully */
        {
            mmi_jmms_get_content_type(content_data_p, &content_type_p);
            if (MMI_TRUE == mmi_jsr_check_recv_mms_for_java(content_type_p))
            {
                JC_UINT32 temp_extrabyte = 0x20000000;

                ret_code = mmi_jmms_save_message_buffer_in_Store(
                            "Inbox",
                            &msg_index,
                            msg_headers_p,
                            content_data_p,
                            &temp_extrabyte);
            }
            else
            {
                ret_code = mmi_jmms_save_message_buffer_in_Store("Inbox", &msg_index, msg_headers_p, content_data_p, NULL);
            }
            if (ret_code != JC_OK)
            {
                if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_NEW_MMS_MEMORY_NOT_SAVED,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                }
                else
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_NEW_MMS_NOT_SAVED,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                }
                if (ret_code == JC_OK)
                {
                    mmi_jmms_check_for_idle_screen();
                }
                goto Endcase;
            }
        }
        else    /* /update the notification */
        {
            msg_index = (comm_node_p->msg_index);
            ret_val = mmi_jmms_get_content_type(content_data_p, &content_type_p);
            if (MMI_TRUE == mmi_jsr_check_recv_mms_for_java(content_type_p))
            {
                ret_code = mmi_jmms_store_update_message("Inbox", &(msg_index), msg_headers_p, content_data_p, 0x20000000);
            }
            else
            {
                ret_code = mmi_jmms_store_update_message("Inbox", &(msg_index), msg_headers_p, content_data_p, 0);
            }
            if (ret_code != JC_OK)
            {
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_NEW_MMS_NOT_SAVED,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
                if (ret_code == JC_OK)
                {
                    mmi_jmms_check_for_idle_screen();
                }
                goto Endcase;
            }

        #ifdef __MMI_UNIFIED_MESSAGE__
            if ((IsScreenPresent(SCR_ID_UM_INBOX)) || (GetActiveScreenId() == SCR_ID_UM_INBOX))
        #else 
            if ((IsScreenPresent(SCR_ID_JMMS_INBOX)) || (GetActiveScreenId() == SCR_ID_JMMS_INBOX))
        #endif 
            {
                g_jmms_context->store_context->update_nmsgs_in_current_folder = 1;
            }
        }

    #ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
        if (ret_val == JC_OK)
        {
            if (mmi_jsr_check_recv_mms_for_java(content_type_p))
            {
                if (!(mmi_jmms_is_call_active()) && (!AlmIsTonePlaying()))      /* if no call is there only then show it */
                {
                    mmi_jmms_update_status_icon_indicator();
                    mmi_msg_entry_new_msg_popup(MSG_NEW_JMMS_JAVA_MMS);
                }
                else
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_NEW_JAVA_MMS,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                    if (ret_code == JC_OK)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }

                goto Endcase;
            }
            /* } */
        }
        if (content_type_p != NULL)
        {
            jdd_MemFree(content_type_p);
            content_type_p = NULL;
        }

    #endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 
        ret_code = mmi_jmms_add_pending_mms_info_node((U16) msg_index, (U8) E_MSG_TYPE_RECEIVE, NULL);
        if (ret_code == JC_OK)
        {
            mmi_jmms_update_status_icon_indicator();
            mmi_jmms_show_new_mms_pop_up();
        }
    }

  Endcase:

    if (content_type_p != NULL)
    {
        jdd_MemFree(content_type_p);
        content_type_p = NULL;
    }

    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

    if (NULL != temp_msg_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
        temp_msg_handle = NULL;
    }

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

    url_ind_data_p->uiRequestID = 0;

    return ret_code;

}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_deffered_downlaod_response
 * DESCRIPTION
 *  Used to handle deffered download response
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 *  content_data_p      [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_deffered_downlaod_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_data_p,
            CONTENT_DATA *content_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
    MMI_BOOL flag = MMI_FALSE;
#endif 
    JC_RETCODE ret_code = JC_OK;
    MSG_HANDLE temp_msg_handle = NULL;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    JC_INT8 *content_type_p = NULL;
    MMI_BOOL intterupt_handling = MMI_FALSE;

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    MESSAGE_RETRIEVAL *receive_msg_headers_p = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_deffered_downlaod_response");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&temp_msg_handle, content_data_p, E_TYPE_MMS, E_FALSE);

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

    ret_code = mmi_jmms_jdi_get_msg_headers(temp_msg_handle, &msg_headers_p);
    if (ret_code != JC_OK || msg_headers_p == NULL)
    {
        goto EndofDeferredcase;
    }
#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    receive_msg_headers_p = (MESSAGE_RETRIEVAL*) msg_headers_p->pHeaders;
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
    ret_code = mmi_jmms_get_content_type(content_data_p, &content_type_p);
    if (ret_code == JC_OK)
    {
        flag = mmi_jsr_check_recv_mms_for_java(content_type_p);

        if (flag == MMI_TRUE)
        {
            mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

            comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_data_p->uiRequestID);
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
                    /* /Todo: tets it. */
                    HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
                    DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_INBOX);
                #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                }

            }
            else
            {
                jmms_mmi_ack_for_deffered_retrieval(*content_data_p);
                ret_code = mmi_jmms_store_update_message(
                            "Inbox",
                            &(comm_node_p->msg_index),
                            msg_headers_p,
                            content_data_p,
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
                        /* /Todo: tets it. */
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
            if (content_type_p != NULL)
            {
                jdd_MemFree(content_type_p);
                content_type_p = NULL;
            }

            goto EndofDeferredcase;
        }
    }
    if (content_type_p != NULL)
    {
        jdd_MemFree(content_type_p);
        content_type_p = NULL;
    }

#endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 

    ret_code = mmi_jmms_handle_deffered_retrieved_mms((*content_data_p));

    if (ret_code == JC_OK)
    {

        if (GetActiveScreenId() != SCR_ID_JMMS_PROGRESS)
        {
            intterupt_handling = MMI_TRUE;
            /* /Todo: need to test it */

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

        comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_data_p->uiRequestID);
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
            jmms_mmi_ack_for_deffered_retrieval(*content_data_p);

            error_code = mmi_jmms_store_update_message("Inbox", &(comm_node_p->msg_index), msg_headers_p, content_data_p, 0);
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
                    /* /Todo: tets it. */
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

    if (content_type_p != NULL)
    {
        jdd_MemFree(content_type_p);
        content_type_p = NULL;
    }

    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

    if (NULL != temp_msg_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
        temp_msg_handle = NULL;
    }

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

    url_ind_data_p->uiRequestID = 0;

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_new_mms_send_response
 * DESCRIPTION
 *  Usde to handle new MMS send response.
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 *  content_data_p      [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_handle_new_mms_send_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_data_p,
            CONTENT_DATA *content_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MESSAGE_HEADERS *msg_headers_p = NULL;
    EMM1MessageType e_message;

    U8 num_retries = 0;
    S8 temp_version[MAX_VERSION_LENGTH + 1];
    JC_RETCODE ret_code = JC_OK;
    MSG_HANDLE temp_msg_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_new_mms_send_response");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&temp_msg_handle, content_data_p, E_TYPE_MMS, E_FALSE);

    /* Async changes begin */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(temp_msg_handle);
    }
    /* Async changes end */

    if (ret_code != JC_OK)
    {
        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
        goto END;
    }
    ret_code = mmi_jmms_jdi_get_msg_headers(temp_msg_handle, &msg_headers_p);
    if (ret_code != JC_OK)
    {
        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
        goto END;
    }
    e_message = msg_headers_p->eMsgType;

    switch (msg_headers_p->eMsgType)
    {
        case E_MSG_TYPE_SEND_RESPONSE:
        {
            MESSAGE_SEND_RESPONSE *send_header_p = (MESSAGE_SEND_RESPONSE*) msg_headers_p->pHeaders;
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

                temp_uniocde_url = mmi_jmms_get_activated_mmsc_url(jmms_context_p);

                /* / replace temp_uniocde_url by url set in message settings */
                jmms_context_p->last_mmsc_url = (S8*) temp_uniocde_url;
                strcpy((PS8) jmms_context_p->last_version, (PS8) send_header_p->pVersion);

                if (num_retries >= 1)
                {
                    mmi_jmms_update_mmsc_url_version(jmms_context_p->last_mmsc_url, jmms_context_p->last_version);

                }

                mmi_jmms_show_mms_send_response(url_ind_data_p->uiRequestID);

                mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

                goto END1;

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
                        mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
                        goto END;
                    }
                    else
                    {
                        if (GetActiveScreenId() == SCR_ID_JMMS_PROGRESS)
                        {

                        #ifdef __MMI_JMMS_SEND_RETRIES__
                            mmi_jmms_change_title_string(STR_ID_JMMS_RETRY, jmms_context_p->sent_retry_counter);
                            g_jmms_context->current_title_id = STR_ID_JMMS_RETRY;
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

                                    comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_data_p->uiRequestID);
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

                        mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

                        ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);
                        if (JC_OK != ret_code)
                        {
                            url_ind_data_p->uiRequestID = 0;

                            mmi_jmms_free_message_header();
                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);

                            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);

                            return ret_code;
                        }
                        url_ind_data_p->uiRequestID = 0;

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
                    if (url_ind_data_p->uiRequestID)
                    {

                        ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);
                        if (JC_OK != ret_code)
                        {

                            /* 2 March -- need care */
                            mmi_jmms_free_message_header();

                            mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);
                            url_ind_data_p->uiRequestID = 0;
                            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);

                            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);

                            return ret_code;
                        }

                    }

                    ret_code = mmi_jmms_retry_communication(
                                jmms_context_p,
                                E_FROM_URL_CALLBACK,
                                url_ind_data_p->uiRequestID,
                                send_header_p->eStatus);
                    if (JC_OK != ret_code && ret_code != E_JMMS_RETRY_COMPLETE) /* /if ret_code=E_JMMS_RETRY_COMPLETE then it means error already handled */
                    {
                        mmi_jmms_free_message_header();
                        mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);
                        url_ind_data_p->uiRequestID = 0;

                    #ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
                        if (send_header_p->pStatusText)
                        {
                            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                                                 "__MMI_JMMS_TEST_REQUEST_STATUS_TEXT_DISPLAY__");
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

                    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

                    url_ind_data_p->uiRequestID = 0;

                    return ret_code;
                }
                else
                {
                    /* Dilip Start 24 Aug 2006 */
                #ifdef __MMI_UNIFIED_MESSAGE__
                    if (IsScreenPresent(SCR_ID_JMMS_WRITE_MMS))
                    {
                        /* Do Nothing */
                    }
                    else if (IsScreenPresent(SCR_ID_UM_UNSENT))
                    {
                        DeleteUptoScrID(SCR_ID_UM_UNSENT);
                        mmi_jmms_deinit_mms_context(jmms_context_p);
                    }
                    else if (IsScreenPresent(SCR_ID_UM_DRAFT))
                    {
                        DeleteUptoScrID(SCR_ID_UM_DRAFT);
                        mmi_jmms_deinit_mms_context(jmms_context_p);
                    }
                    else if (IsScreenPresent(SCR_ID_UM_INBOX))
                    {
                        DeleteUptoScrID(SCR_ID_UM_INBOX);
                        mmi_jmms_deinit_mms_context(jmms_context_p);
                    }
                    else if (IsScreenPresent(SCR_ID_UM_SENT))
                    {
                        DeleteUptoScrID(SCR_ID_UM_SENT);
                        mmi_jmms_deinit_mms_context(jmms_context_p);
                    }
                #else /* __MMI_UNIFIED_MESSAGE__ */ 
                    if (!IsScreenPresent(SCR_ID_JMMS_WRITE_MMS))
                    {
                        mmi_jmms_deinit_mms_context(jmms_context_p);
                    }
                #endif /* __MMI_UNIFIED_MESSAGE__ */ 

                    mmi_jmms_handle_error_string(send_header_p->eStatus, E_TYPE_NEW_MMS);
                }
            }
        }
            break;

        default:
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_UNABLE_PARSE_SENT_RESPONSE);

    }   /* /end of  switch(msg_headers_p->eMsgType) */

  END:
#ifndef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_del_inserted_auto_signature_slide();
#endif /* #ifndef __MMI_UNIFIED_COMPOSER__ */

    DeleteScreenIfPresent(SCR_ID_JMMS_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_JMMS_SENT_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_JMMS_DRAFTS_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_JMMS_OUTBOX_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_WRITE_MMS_DONE_OPTIONS);
    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

  END1:

    mmi_jmms_free_message_header();

    if (NULL != temp_msg_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
    }

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
  END2:
#endif 
    url_ind_data_p->uiRequestID = 0;

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_new_mms_send_response_asynch_callback
 * DESCRIPTION
 *  Async impelementation for new MMS send response
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
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_mms_send_response
 * DESCRIPTION
 *  Used to send the response of the MMS send
 * PARAMETERS
 *  jmms_context_p      [IN]        
 *  url_ind_data_p      [IN]        
 *  content_data_p      [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_jsr_mms_send_response(
            mmi_jmms_context_struct *jmms_context_p,
            COMM_FETCH_URL_IND_RESP *url_ind_data_p,
            CONTENT_DATA content_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    MSG_HANDLE temp_msg_handle = NULL;

    MESSAGE_HEADERS *msg_headers_p = NULL;
    EMM1MessageType e_message;

    U8 num_retries = 0;
    S8 temp_version[MAX_VERSION_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_jsr_mms_send_response");

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&temp_msg_handle, &content_data_p, E_TYPE_MMS, E_FALSE);

    /* Async changes begin */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(temp_msg_handle);
    };
    /* Async changes end */

    if (ret_code != JC_OK)
    {
        (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);
        goto END;

    }
    ret_code = mmi_jmms_jdi_get_msg_headers(temp_msg_handle, &msg_headers_p);
    if (ret_code != JC_OK)
    {
        (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);
        goto END;
    }
    e_message = msg_headers_p->eMsgType;

    switch (msg_headers_p->eMsgType)
    {
        case E_MSG_TYPE_SEND_RESPONSE:
        {
            MESSAGE_SEND_RESPONSE *send_header_p = (MESSAGE_SEND_RESPONSE*) msg_headers_p->pHeaders;
            U8 *temp_uniocde_url = NULL;

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "JMMS JSR send response, Status:", send_header_p->eStatus);

            if (E_RESP_OK == send_header_p->eStatus)
            {

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "JMMS JSR send response, OK");

                num_retries = jmms_context_p->sent_retry_counter;

                temp_uniocde_url = mmi_jmms_get_activated_mmsc_url(jmms_context_p);

                jmms_context_p->last_mmsc_url = (S8*) temp_uniocde_url;
                strcpy((PS8) jmms_context_p->last_version, (PS8) send_header_p->pVersion);

                if (num_retries >= 1)
                {
                    mmi_jmms_update_mmsc_url_version(jmms_context_p->last_mmsc_url, jmms_context_p->last_version);

                }

                (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_OK);

                goto END;

            }
            else
            {
                if (send_header_p->eStatus == E_RESP_ERR_UNSUPPORTED_MSG
                    || send_header_p->eStatus == E_RESP_ERR_MESG_NOT_FOUND
                    || send_header_p->eStatus == E_RESP_ERR_MSG_FORMAT_CORRUPT)

                {
                    jmms_context_p->sent_retry_counter++;

                    if (jmms_context_p->sent_retry_counter >= 2)
                    {
                        (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);
                        goto END;
                    }
                    else
                    {
                        strcpy((PS8) temp_version, (PS8) "1.0");

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
                                (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);
                                goto END;
                            }
                        }

                        if (NULL != temp_msg_handle)
                        {
                            mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
                            temp_msg_handle = NULL;
                        }
                        ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);
                        if (JC_OK != ret_code)
                        {
                            url_ind_data_p->uiRequestID = 0;

                            (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);

                            return ret_code;
                        }
                        url_ind_data_p->uiRequestID = 0;

                        {
                            mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

                            comm_node_p = mmi_jmms_get_comm_state(jmms_context_p, url_ind_data_p->uiRequestID);
                            if (comm_node_p == NULL)
                            {
                                url_ind_data_p->uiRequestID = 0;

                                (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);

                                return ret_code;
                            }
                            ret_code = mmi_jmms_resend_mms(comm_node_p, 1);
                            if (JC_OK != ret_code)
                            {
                                url_ind_data_p->uiRequestID = 0;

                                (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);

                                return ret_code;
                            }
                        }

                        if (JC_OK != ret_code)
                        {

                            (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);

                        }

                        return ret_code;

                    }
                }
                else if (send_header_p->eStatus == E_RESP_ERR_NETWORK_PROBLEM ||        // TODO:: need to check right status
                         send_header_p->eStatus == E_RESP_ERR_SERVICE_DENIED)
                {
                    /* /added for retry mechanism */
                    if (url_ind_data_p->uiRequestID)
                    {
                        ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);
                        if (JC_OK != ret_code)
                        {
                            mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);
                            url_ind_data_p->uiRequestID = 0;

                            (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);

                            return ret_code;
                        }

                    }

                    ret_code = mmi_jmms_retry_communication(
                                jmms_context_p,
                                E_FROM_URL_CALLBACK,
                                url_ind_data_p->uiRequestID,
                                send_header_p->eStatus);
                    if (JC_OK != ret_code && ret_code != E_JMMS_RETRY_COMPLETE)
                    {

                        mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);
                        url_ind_data_p->uiRequestID = 0;

                        (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);

                        return ret_code;
                    }

                    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

                    url_ind_data_p->uiRequestID = 0;

                    return ret_code;
                }
                else
                {
                    (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);

                }

            }
        }
            break;

        default:
            (*(jmms_context_p->jsr_mms_send_callback)) (JSR_RESULT_ERROR);

    }   /* /end of switch switch(msg_headers_p->eMsgType) */

  END:

    mmi_jmms_free_comm_node(jmms_context_p, url_ind_data_p->uiRequestID);

    if (NULL != temp_msg_handle)
    {
        mmi_jmms_jdi_msg_deinit_without_header(temp_msg_handle);
    }

    ret_code = jdi_CommunicationFreeReference(jmms_context_p->comm_handle, url_ind_data_p->uiRequestID);
    url_ind_data_p->uiRequestID = 0;

    return ret_code;

}
#endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_pop_up_for_interupt
 * DESCRIPTION
 *  Used to display desired pop up
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_pop_up_for_interupt");

    if (GetActiveScreenId() != SCR_ID_JMMS_PROGRESS)
    {
        U16 k;
        MMI_BOOL ret;
        history hist;
        historyNode *saved_history;

        g_jmms_context->interupt_screen_title = strid;
        memset(&hist, 0, sizeof(history));

        if (GetCurrScrnId() == SCR_ID_JMMS_PROGRESS)
        {
            hist.scrnID = SCR_ID_JMMS_POP_SCREEN;
            hist.entryFuncPtr = mmi_jmms_entry_general_pop_screen_in_case_interupt;
            AddHistory(hist);
            GetHistoryPointer(SCR_ID_JMMS_POP_SCREEN, &saved_history);
            if (saved_history->isSmallScreen == 1)
            {
                saved_history->isSmallScreen = 0;
                set_small_screen();
            }
        }
        else
        {
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
 *  mmi_jmms_entry_general_pop_screen_in_case_interupt
 * DESCRIPTION
 *  Used to show full screen pop up
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
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_end_key_downlaod_sucess_pop_screen
 * DESCRIPTION
 *  Called after successfull download of the MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_end_key_downlaod_sucess_pop_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_deinit_mms_context(g_jmms_context);
    GoBackToHistory(IDLE_SCREEN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_back_msg_download_sucess
 * DESCRIPTION
 *  Called after the MMS is downloaded successfully
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_back_msg_download_sucess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->is_unread_msg_deleted = 0;
    mmi_jmms_set_msg_as_read((U8) g_jmms_context->mms_index);

#ifdef __MMI_UNIFIED_MESSAGE__
    g_jmms_context->show_property_screen = MMI_TRUE;
#endif 
    mmi_jmms_handle_read_report(g_jmms_context->msg_header_type_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_mms_status_icon
 * DESCRIPTION
 *  To show MMS indicator icon
 * PARAMETERS
 *  status      [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_mms_status_icon(mmi_jmms_status_icon_type_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "mmi_jmms_show_mms_status_icon:", status);
    switch (status)
    {
        case MMS_STATUS_OFF:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
        case MMS_STATUS_NEW_MESSAGE:
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            ShowStatusIcon(STATUS_ICON_MMS_UNREAD);
            break;
        case MMS_STATUS_BUSY:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            BlinkStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
        case MMS_STATUS_FULL:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            BlinkStatusIcon(STATUS_ICON_MMS_UNREAD);
            break;
        default:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
    }
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_mms_downloading_busy
 * DESCRIPTION
 *  To handle MMS downloading indicator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_mms_downloading_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_mms_downloading_busy++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_reset_mms_downloading_busy
 * DESCRIPTION
 *  Used to reset the counter for the MMS downloading
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_reset_mms_downloading_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d ", "mmi_jmms_reset_mms_downloading_busy Val=",
                         g_jmms_context->g_mms_downloading_busy);
    if (g_jmms_context->g_mms_downloading_busy != 0)
    {
        g_jmms_context->g_mms_downloading_busy--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_download_busy
 * DESCRIPTION
 *  Used to see if any sending/receving is going on
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_jmms_is_download_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Download Busy=", g_jmms_context->g_mms_downloading_busy);
    return g_jmms_context->g_mms_downloading_busy;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_stop_download_busy
 * DESCRIPTION
 *  Used to stop MMS downloading
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_stop_download_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Download Busy=", g_jmms_context->g_mms_downloading_busy);

    g_jmms_context->g_mms_downloading_busy = 0;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_update_status_icon_indicator
 * DESCRIPTION
 *  To set indicator icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_update_status_icon_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 unread_msgs = 0;
    U8 total_num_messages;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_update_status_icon_indicator");

    if (mmi_jmms_is_download_busy() > 0)
    {
        mmi_jmms_show_mms_status_icon(MMS_STATUS_BUSY);
    }
    else
    {
        ret_code = mmi_jmms_get_total_number_of_messages(&total_num_messages);
        if (ret_code != JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "No Update, ret_code = ", ret_code);
            return;
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Total Messages=", total_num_messages);
        if (total_num_messages >= (MAX_POSSIBLE_MESSAGES_THRESHOLD))
        {
            mmi_jmms_show_mms_status_icon(MMS_STATUS_FULL);
        }
        else
        {
            mmi_jmms_get_number_of_unread_messages_in_inbox(&unread_msgs);
            if (unread_msgs > 0)
            {
                mmi_jmms_show_mms_status_icon(MMS_STATUS_NEW_MESSAGE);
            }
            else
            {
                mmi_jmms_show_mms_status_icon(MMS_STATUS_OFF);
            }
        }
    }
}

/* PMT VIKAS END 20060401 */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_add_memory_full_node_if_not_already
 * DESCRIPTION
 *  Used to add memory full node if MMS count is greater than threshhold.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_add_memory_full_node_if_not_already(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    MMI_BOOL found = MMI_FALSE;
    mmi_jmms_pending_mms_info_struct *node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = g_jmms_context->pending_mms_info_list;

    while (node_p != NULL)
    {
        if (node_p->index == STR_ID_JMMS_ERROR_MMS_MEMORY_FULL)
        {
            found = MMI_TRUE;
            break;
        }
        node_p = node_p->next_p;

    }

    if (found == MMI_FALSE)
    {
        ret_code = mmi_jmms_add_pending_mms_info_node(
                    (U16) STR_ID_JMMS_ERROR_MMS_MEMORY_FULL,
                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                    NULL);
        if (ret_code == JC_OK)
        {
            mmi_jmms_check_for_idle_screen();
        }
    }
    mmi_jmms_update_status_icon_indicator();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_remove_memory_full_node_if_present
 * DESCRIPTION
 *  Used to remove memory full node
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_remove_memory_full_node_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_pending_mms_info_struct *node1_p = NULL;
    mmi_jmms_pending_mms_info_struct *node2_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node1_p = g_jmms_context->pending_mms_info_list;
    node2_p = g_jmms_context->pending_mms_info_list;

    while (node1_p != NULL)
    {
        if (node1_p->index == STR_ID_JMMS_ERROR_MMS_MEMORY_FULL)
        {
            node2_p->next_p = node1_p->next_p;

            if (node1_p->mms_url_p != NULL)
            {
                jdd_MemFree(node1_p->mms_url_p);
            }
            if (node1_p == g_jmms_context->pending_mms_info_list)
            {
                g_jmms_context->pending_mms_info_list = node1_p->next_p;
            }
            jdd_MemFree(node1_p);
            node1_p = NULL;
            break;
        }
        node2_p = node1_p;
        node1_p = node1_p->next_p;
    }
}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_end_key_progressing
 * DESCRIPTION
 *  Used to handle end key
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
    g_jmms_context->end_key_processing_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_end_key_progressing_handler
 * DESCRIPTION
 *  Used to set end key
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
        g_jmms_context->end_key_processing_handler = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_jmms_end_key_progressing, KEY_END, KEY_EVENT_DOWN);
    }
}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_update_pending_downloads
 * DESCRIPTION
 *  This function updates the message index of notifications pending for download
 * PARAMETERS
 *  msg_index       [IN]        
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_jmms_update_pending_downloads(JC_UINT32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "mmi_jmms_update_pending_downloads:", msg_index);

    comm_node_p = g_jmms_context->comm_state_p;
    ASSERT(msg_index);
    while (comm_node_p != NULL)
    {
        if ((comm_node_p->mms_communication_state == E_TYPE_IMMEDIATE_RETRIEVAL_FETCH) ||
            (comm_node_p->mms_communication_state == E_TYPE_DEFFERED_RETRIEVAL_FETCH))
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Notofication found. Msg Id:", comm_node_p->msg_index);

            if (comm_node_p->msg_index > msg_index)
            {
                --comm_node_p->msg_index;
            }
            else if (comm_node_p->msg_index == msg_index)
            {
                ASSERT(0);
            }
        }
        comm_node_p = comm_node_p->next_p;
    }

    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_call_active
 * DESCRIPTION
 *  This function checks if there exists an active call and it is not a WAP call
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_call_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!isInCall()) || (isInCall() && (GetWapCallPresent())))
    {
        return E_FALSE;
    }

    return E_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_mms_profile_user_name
 * DESCRIPTION
 *  This function is used to get the user name from MMS profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8 *mmi_jmms_get_mms_profile_user_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_mms_profile_content_struct *activated_mms_profile_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activated_mms_profile_p = mmi_ph_get_activated_mms_profile();
    return (S8*) activated_mms_profile_p->username;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_mms_profile_password
 * DESCRIPTION
 *  This function is used to get the password from MMS profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8 *mmi_jmms_get_mms_profile_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_mms_profile_content_struct *activated_mms_profile_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activated_mms_profile_p = mmi_ph_get_activated_mms_profile();
    return ((S8*) activated_mms_profile_p->password);
}

#ifdef __MMI_JMMS_SEND_RETRIES__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_change_title_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_id              [IN]        
 *  retry_counter       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_change_title_string(U16 str_id, U8 retry_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR title[MAX_TITLE_LENGTH] = {0};
    JC_CHAR count[MAX_TITLE_LENGTH] = {0};
    S8 temp[MAX_TITLE_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp, "%d", retry_counter);
    mmi_asc_to_ucs2((S8*) count, (S8*) temp);

    mmi_ucs2cpy((S8*) title, (S8*) GetString(g_jmms_context->current_title_id));

    mmi_asc_to_ucs2((S8*) temp, ": (");
    mmi_ucs2cat((S8*) title, temp);

    mmi_ucs2cat((S8*) title, (S8*) count);

    mmi_asc_to_ucs2((S8*) temp, ")");
    mmi_ucs2cat((S8*) title, (S8*) temp);

    ChangeTitleString((U8*) title);
    draw_title();
}
#endif /* __MMI_JMMS_SEND_RETRIES__ */ 

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_send_timeout_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_send_timeout_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_uc_sending_complete_struct sending_complete_data = {0, };
#endif 
    mmi_jmms_communication_state_node_struct *communication_handle_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_send_timeout_timer_hdlr");
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "__MMI_JMMS_RESPONSE_TIMEOUT__");

#ifdef __MMI_UNIFIED_COMPOSER__
    sending_complete_data.result = MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT;
    sending_complete_data.error_code = JC_ERR_DATA_CONN_TIMEOUT;

    communication_handle_p = mmi_jmms_get_comm_state(g_jmms_context, g_jmms_context->g_reference_id);
    sending_complete_data.communication_handle_p = communication_handle_p;
    ASSERT(communication_handle_p);
    communication_handle_p->callback(MMS_SENDING_COMPELETE_CALLBACK, (void*)&sending_complete_data);
    g_jmms_context->send_status |= TIMER_RESPONSE_BIT;  /* set first bit response function */

#else /* __MMI_UNIFIED_COMPOSER__ */ 
    mmi_jmms_show_mms_send_response(g_jmms_context->g_reference_id);
    g_jmms_context->send_status |= TIMER_RESPONSE_BIT;  /* set first bit response function */
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    mmi_jmms_free_message_header();
    mmi_jmms_free_comm_node(g_jmms_context, g_jmms_context->g_reference_id);

#ifdef __MMI_JMMS_SEND_RETRIES__
    mmi_jmms_set_progress_screen_title(0);
#endif 

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_send_timeout_timer_hdlr returns");
    return;
}
#endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_mms_send_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  reference_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_mms_send_response(JC_UINT32 reference_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    mmi_jmms_communication_state_node_struct *comm_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->save_mms == MMI_TRUE)
    {

        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS send response: Save MMS True");

        comm_node_p = mmi_jmms_get_comm_state(g_jmms_context, reference_id);

        if (comm_node_p == NULL)
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_MMS_SENT_NOT_SAVE);
        }
        else
        {
            ret_code = mmi_jmms_send_and_store_mms("Sent", g_jmms_context->msg_handle, comm_node_p);

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
    mmi_jmms_deinit_mms_context(g_jmms_context);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_mms_profile_in_use
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_mms_profile_in_use(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->comm_state_p)
    {
        return E_TRUE;
    }
    return E_FALSE;
}

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_pop_up_for_interupt_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer_string       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_pop_up_for_interupt_string(JC_CHAR *buffer_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_handle_pop_up_for_interupt");

    if (GetActiveScreenId() != SCR_ID_JMMS_PROGRESS)
    {
        U16 k;
        MMI_BOOL ret;
        history hist;
        historyNode *saved_history;

        memset(&hist, 0, sizeof(history));

        mmi_ucs2ncpy((S8*) g_jmms_context->response_text, (S8*) buffer_string, MAX_RESPONSE_TEXT_LENGTH);
        if (GetCurrScrnId() == SCR_ID_JMMS_PROGRESS)
        {
            hist.scrnID = SCR_ID_JMMS_POP_SCREEN;
            hist.entryFuncPtr = mmi_jmms_entry_general_pop_string_in_case_interupt;
            AddHistory(hist);
            GetHistoryPointer(SCR_ID_JMMS_POP_SCREEN, &saved_history);
            if (saved_history->isSmallScreen == 1)
            {
                saved_history->isSmallScreen = 0;
                set_small_screen();
            }
        }
        else
        {
            ret = GetNextScrnIdOf(SCR_ID_JMMS_PROGRESS, &k);
            if (ret == MMI_TRUE)
            {
                hist.scrnID = SCR_ID_JMMS_POP_SCREEN;
                hist.entryFuncPtr = mmi_jmms_entry_general_pop_string_in_case_interupt;
                InsertHistoryBeforeThisScrnReference(k, &hist);
            }
        }
    }
    else
    {
        DisplayPopup((U8*) buffer_string, IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_general_pop_string_in_case_interupt
 * DESCRIPTION
 *  Used to show full screen pop up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_general_pop_string_in_case_interupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "mmi_jmms_entry_general_pop_string_in_case_interupt: Pop not supressed");
    EntryNewScreen(SCR_ID_JMMS_POP_SCREEN, NULL, mmi_jmms_entry_general_pop_string_in_case_interupt, NULL);
    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
    ShowCategory7Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_jmms_context->response_text,
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
#endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_stop_timeout_timer
 * DESCRIPTION
 *  Used to stop timout timer for sending
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_stop_timeout_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_stop_timeout_timer");
    StopTimer(JMMS_SEND_TIMEOUT_TIMER);
}
#endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_progress_screen_title
 * DESCRIPTION
 *  Used to set progress screen title
 * PARAMETERS
 *  strid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_progress_screen_title(U16 strid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_set_progress_screen_title: %d", strid);
    g_jmms_context->progress_screen_title = strid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_notifiction_in_use
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_jmms_is_notifiction_in_use(U16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_communication_state_node_struct *temp_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node_p = g_jmms_context->comm_state_p;
    while (temp_node_p != NULL)
    {
        if (temp_node_p->msg_index == msg_index)
        {
            return MMI_TRUE;
        }

        temp_node_p = temp_node_p->next_p;
    }

    return MMI_FALSE;

}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

