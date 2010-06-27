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
 *  MMSAppMain.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the Event Handlers and Main flow of the MMS Application.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#ifndef _MMI_UMMSAPPMAIN_C
//#define _MMI_UMMSAPPMAIN_C
/***************************************************************************** 
* Include
*****************************************************************************/

#ifdef __MMI_MMS_2__

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "ProtocolEvents.h"
#include "time.h"
#include "DateTimeGprot.h"
#include "AlarmFrameworkProt.h"
#include "SmsGuiInterfaceProt.h"
#include "MMSAppResDef.h"
#include "MMSAppGprot.h"
#include "MMSAppprot.h"
#include "PhoneBookGprot.h"
#include "SmsGuiInterfaceType.h"
#include "FileManagerGProt.h"
#include "CallManagementGprot.h"
/* For Bearer Type */
#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#include "Custom_nvram_editor_data_item.h"
#include "DataAccountGprot.h"

#include "wap_ps_struct.h"
#include "custom_wap_config.h"
#include "mmsadp.h"

/* For reply as SMS */
#include "SMSApi.h"


#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif 
#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "UnifiedComposerGProt.h"
#endif 
#include "MMSViewerAPPDefs.h"
#include "MMSMsgCommonProt.h"
#include "app_datetime.h"
#include "MMSMessageTemplates.h"
#include "MMSMessageSettingsUtils.h"

static umms_current_selected_info_struct current_mms_info_list; /* current selected MMS Info in UM */
static umms_current_selected_info_struct *g_current_mms_info_list = &current_mms_info_list;

static mmi_umms_dwnld_send_list dwnld_send_list;
static mmi_umms_dwnld_send_list *g_dwnld_send_list = &dwnld_send_list;

static mmi_umms_new_mms_list new_mms_list;
static mmi_umms_new_mms_list *g_new_mms_list = &new_mms_list;

static mmi_umms_message_number_struct msg_number_struct;
static mmi_umms_message_number_struct *g_msg_number_struct = &msg_number_struct;

U32 g_msg_index = 0;
UmMsgBoxType g_um_box_selected = 0;
static kal_bool g_is_usb_mode = FALSE;

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_event_handlers
 * DESCRIPTION
 *  Entry Function for Event Handlers and called when the Handset is booted up.
 * CALLS
 *  
 * PARAMETERS
 *  void
 *  msg_index(?)        [IN](?)(?)(?)
 *  msg_box_type(?)     [IN](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_event_handlers(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_umms_get_storage_full_ind, MSG_ID_WAP_MMA_STORAGE_FULL_IND);
//    SetProtocolEventHandler(mmi_umms_get_download_ind, MSG_ID_WAP_MMA_DOWNLOAD_IND);
//    SetProtocolEventHandler(mmi_umms_abort_download_rsp, MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP);
    SetProtocolEventHandler(mmi_umms_start_immd_retr_ind, MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND);
    SetProtocolEventHandler(mmi_umms_stop_immd_retr_ind, MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND);
    SetProtocolEventHandler(mmi_umms_get_use_details_rsp, MSG_ID_MMI_MV_GET_USE_DETAILS_RSP);
    SetProtocolEventHandler(mmi_umms_view_msg_ind, MSG_ID_WAP_MMA_VIEW_MSG_IND);

//    SetProtocolEventHandler(mmi_umms_get_download_rsp, MSG_ID_WAP_MMA_DOWNLOAD_RSP);
    SetProtocolEventHandler(mmi_umms_get_send_ind, MSG_ID_WAP_MMA_SEND_IND);
    SetProtocolEventHandler(mmi_umms_get_delete_all_rsp_from_um, PRT_MSG_ID_MMI_UM_DELETE_ALL_RES);
    SetProtocolEventHandler(mmi_umms_get_uc_start_rsp, MSG_ID_WAP_MMA_UC_START_RSP);
	SetProtocolEventHandler(mmi_umms_terminate_indication, MSG_ID_WAP_MMA_TERMINATE_IND);
    g_new_mms_list = NULL;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_current_msg_id
 * DESCRIPTION
 *  This API is used to set the value of the Current Message ID in the Globals.
 * PARAMETERS
 *  msg_id      [IN]        
 *  msg_index(?)        [IN](?)(?)(?)
 *  msg_box_type(?)     [IN](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_current_msg_id(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_update_current_msg_id Msg_id=%d *\n", msg_id);
    g_current_mms_info_list->current_msg_id = msg_id;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_progress_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_set_progress_screen Msg_id=%d *\n",
                         g_current_mms_info_list->current_msg_id);
    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_PLEASE_WAIT;
    mmi_umms_progress_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_mms_options
 * DESCRIPTION
 *  This Function is used to enter the Option Screen after the MMS has been played.
 * PARAMETERS
 *  msg_id      [IN]        
 *  msg_index(?)        [IN](?)(?)(?)
 *  msg_box_type(?)     [IN](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_mms_options(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_mms_options Msg_id=%d *\n", msg_id);

    mmi_umms_get_header_request(msg_id, E_STATE_NORMAL_MSG, g_current_mms_info_list->folder_id);
    return;

}

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_mms_only_options
 * DESCRIPTION
 *  This API is used to enter the Option Screen Directly.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_mms_only_options(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_mms_only_options Msg_id=%d *\n", msg_id);
    g_current_mms_info_list->key_type_press = OPTION_KEY;

    mmi_umms_get_header_request(msg_id, E_STATE_NORMAL_MSG_OPTION_KEY, g_current_mms_info_list->folder_id);
    return;
}
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_new_mms_hndlr
 * DESCRIPTION
 *  This API is used to Handle the entry Point for NEW MMS.
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 *  msg_id(?)           [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_new_mms_hndlr(const UmMsgBoxType msg_box_type, const kal_uint16 msg_index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_entry_new_mms_hndlr msg_box_type=%d msg_index=%d *\n",
                         msg_box_type, msg_index);
    msg_id = wap_mma_get_msg_id(UM_MSG_BOX_TYPE_INBOX, msg_index);
    /* Check here if Download in in Progress. If yes then Add the New MMS in the New MMS List */
    if (umms_end_call_is_download_in_progress())
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSAppMain.c] mmi_umms_entry_new_mms_hndlr Add to new Msg List Id =%d\n", msg_id);
        mmi_umms_add_to_new_msg_list(msg_id);
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSAppMain.c] mmi_umms_entry_new_mms_hndlr Not Add to new Msg List\n");
        mmi_umms_update_status_icon_indicator();
    mmi_umms_get_header_request(msg_id, E_STATE_NEW_MSG, MMA_FOLDER_INBOX);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_new_mms_list_and_show_new_mms_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_check_new_mms_list_and_show_new_mms_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_new_mms_list *new_msg_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_new_mms_hndlr\n");

    if (g_new_mms_list == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_new_mms_hndlr NULL\n");
        return;
    }
    else
    {
        new_msg_hndlr = g_new_mms_list;
        while (new_msg_hndlr != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_entry_new_mms_hndlr Print List Msg_id = %d\n",
                                 new_msg_hndlr->msg_id);
            mmi_umms_get_header_request(new_msg_hndlr->msg_id, E_STATE_NEW_MSG, MMA_FOLDER_INBOX);
            mmi_umms_free_new_msg_handler_list(new_msg_hndlr->msg_id);
            new_msg_hndlr = new_msg_hndlr->next;
        }
    }
}

//MTI SUKRIT START
void mmi_umms_display_message(void)
{
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
    {
        mmi_umms_entry_dummy_screen();
        mmi_umms_delete_progress_screen();
        g_current_mms_info_list->restricted_option = TRUE;
	    if(g_current_mms_info_list->msg_type == MMA_MSG_TYPE_JAVA)
	    {
		    mmi_umms_entry_java_mms_screen();
	    }
	    else
	    {
            mmi_umms_show_mms_option_screen_according_to_folder_id_and_msg_type();
	    }
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        mmi_umms_reset_global();
    }
#else /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
    {
        if (mmi_umms_is_mms_in_send_list(g_current_mms_info_list->current_msg_id))
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_msg_header mmi_umms_is_mms_in_send_list *\n");
            mmi_umms_entry_dummy_screen();
            mmi_umms_delete_progress_screen();
            mmi_umms_show_mms_option_screen_according_to_folder_id_and_msg_type();
        }
        else
        {
            mmi_umms_show_viewer_or_properities_screen();
        }
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        mmi_umms_reset_global();
    }
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_start_file_parse
 * DESCRIPTION
 *  THe message header part is parsed using XML Parser
 * PARAMETERS
 *  file_path       [IN]     
  * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_start_file_parse(PS16 file_path)
{
    g_current_mms_info_list->umms_mms_xml_msg = (mmi_umms_xml_msg_struct*) umms_malloc(sizeof(mmi_umms_xml_msg_struct));
    memset(g_current_mms_info_list->umms_mms_xml_msg, 0, sizeof(mmi_umms_xml_msg_struct));

    MMI_ASSERT(g_current_mms_info_list->umms_mms_xml_msg != NULL);

    mmi_umms_parse_mms_xml_description_file(
        (PU16)file_path,
        app_decoder_mem_alloc,
        app_decoder_mem_free,
        g_current_mms_info_list->umms_mms_xml_msg,
        (U32) MMI_UMMS_MSG_PARSER_IGNORE_SLIDES);

   // mmi_umms_set_download_size(g_current_mms_info_list->umms_mms_xml_msg->download_size);
   // mmi_umms_set_reported_msg_id(g_current_mms_info_list->umms_mms_xml_msg->reported_msg_id);
   // mmi_umms_set_rr_dr_status(g_current_mms_info_list->umms_mms_xml_msg->status);

    mmi_umms_display_message();

#if 0
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
#endif
}
//MTI SUKRIT END

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_header
 * DESCRIPTION
 *  The Message Header is Parsed in this API and subsequent decision made.
 * PARAMETERS
 *  inMsg       [?]     
 *  msgRsp      [?]     [?]     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_header(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    umms_state_enum current_state = E_STATE_NONE;
    wap_mma_get_msg_info_rsp_struct *msgRsp = (wap_mma_get_msg_info_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_msg_header Msg_id=%d Req_id=%d Msg_Type =%d Msg_result = %d*\n",
                         g_current_mms_info_list->current_msg_id, msgRsp->req_id, msgRsp->msg_type, msgRsp->result);
    if (msgRsp->result == MMA_RESULT_OK)
    {
        current_state = mmi_umms_get_current_state(msgRsp->msg_id, msgRsp->req_id);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_msg_header Current State=%d *\n",
                             current_state);
        mmi_umms_free_req_handler_node(msgRsp->msg_id, msgRsp->req_id);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_msg_header Print Header   *\n");

        if ((current_state == E_STATE_NORMAL_MSG) || (current_state == E_STATE_DOWNLOADED_MSG)
            || (current_state == E_STATE_NORMAL_MSG_OPTION_KEY))
            /*
             * NORMAL - OK PRESS
             * DOWNLOAD - Download MMS State. After downloading it may be JAVA, Read Report
             * OPTION - When user press OPTION Key
             */
        {

            /* g_current_mms_info_list->current_msg_id = msgRsp->msg_id; */
            g_current_mms_info_list->from_address_type = msgRsp->from_address_type;
            g_current_mms_info_list->msg_class = msgRsp->msg_class;
            g_current_mms_info_list->priority = msgRsp->priority;
            g_current_mms_info_list->msg_status = msgRsp->msg_status;
            g_current_mms_info_list->msg_size = msgRsp->msg_size;
            g_current_mms_info_list->date = msgRsp->date;
            g_current_mms_info_list->receive_date = msgRsp->received_date;
            g_current_mms_info_list->expiry_time = msgRsp->expiry_date + msgRsp->received_date;
            g_current_mms_info_list->isRead = msgRsp->isRead;
            g_current_mms_info_list->need_read_report = msgRsp->need_read_report;
            g_current_mms_info_list->isForwardLock = msgRsp->isForwardlock;
            g_current_mms_info_list->isDRM = msgRsp->isDRM;
            g_current_mms_info_list->isFollowPhoneMMSContentClass = msgRsp->isFollowPhoneMMSContentClass;
            g_current_mms_info_list->hasAttachment = msgRsp->hasAttachment;
            g_current_mms_info_list->bcc_address_type = msgRsp->bcc_address_type;
            g_current_mms_info_list->to_address_type = msgRsp->to_address_type;
            g_current_mms_info_list->cc_address_type = msgRsp->cc_address_type;
            g_current_mms_info_list->msg_type = msgRsp->msg_type;

            mmi_ucs2ncpy((PS8) g_current_mms_info_list->from_address, (PS8) msgRsp->from_address, MMA_MAX_ADDR_LEN);
            mmi_ucs2ncpy((PS8) g_current_mms_info_list->to_address, (PS8) msgRsp->to_address, MMA_MAX_ADDR_LEN);
            mmi_ucs2ncpy((PS8) g_current_mms_info_list->cc_address, (PS8) msgRsp->cc_address, MMA_MAX_ADDR_LEN);
            mmi_ucs2ncpy((PS8) g_current_mms_info_list->bcc_address, (PS8) msgRsp->bcc_address, MMA_MAX_ADDR_LEN);
            mmi_ucs2ncpy((PS8) g_current_mms_info_list->subject, (PS8) msgRsp->subject, MMA_MAX_SUBJECT_LEN);
            mmi_ucs2ncpy((PS8) g_current_mms_info_list->app_data, (PS8) msgRsp->app_data, MMA_MAX_APP_DATA_LENGTH);
            mmi_ucs2ncpy((PS8) g_current_mms_info_list->app_id, (PS8) msgRsp->java_app_id, MAX_PROGRESS_STRING_LENGTH);
            mmi_ucs2ncpy(
                (PS8) g_current_mms_info_list->reply_app_id,
                (PS8) msgRsp->java_reply_app_id,
                MAX_PROGRESS_STRING_LENGTH);

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_msg_header From Addr = %s   *\n",
                                 g_current_mms_info_list->from_address);
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_msg_header To Addr = %s   *\n",
                                 g_current_mms_info_list->to_address);
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_msg_header CC Addr = %s   *\n",
                                 g_current_mms_info_list->cc_address);
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_msg_header Subject = %s   *\n",
                                 g_current_mms_info_list->subject);

            if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            {
                //MTI SUKRIT START
                mmi_umms_get_content_req(msgRsp->msg_id, MMA_MODE_HEADER, E_STATE_GET_CONTENT_FOR_MSG_INFO);
                //MTI SUKRIT END
            }
            else
            {
                DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
                mmi_umms_reset_global();
            }
        }
        else
        {
            /* This is a new MMS Indication from UM.  */
            switch (current_state)
            {
                case E_STATE_SEND_MMS_FROM_UC:
                    mmi_umms_reset_global();
                    mmi_ucs2ncpy((PS8) g_current_mms_info_list->to_address, (PS8) msgRsp->to_address, MMA_MAX_ADDR_LEN);
                    mmi_umms_save_req(
                        E_STATE_SAVE_BEFORE_SEND,
                        E_STATE_SEND_MSG,
                        msgRsp->msg_id,
                        MMA_FOLDER_OUTBOX,
                        MMA_FOLDER_DRAFT);
                    break;
                case E_STATE_NEW_MSG:
                    mmi_umms_handle_new_mms(msgRsp, g_current_mms_info_list->current_msg_id);
                    break;
                default:
                    /* Do nothing */
                    break;
            }

        }
    }
    else
    {
        /* Get Info Result NOT OK! */
        current_state = mmi_umms_get_current_state(msgRsp->msg_id, msgRsp->req_id);
        mmi_umms_free_req_handler_node(msgRsp->msg_id, msgRsp->req_id);
        switch (current_state)
        {
            case E_STATE_NEW_MSG:
                mmi_umms_handle_new_mms(msgRsp, msgRsp->msg_id);
                break;
            case E_STATE_NORMAL_MSG_OPTION_KEY:
            case E_STATE_NORMAL_MSG:
            case E_STATE_DOWNLOADED_MSG:
                /* Show an Error PopUp and go back to Message List Screen */
                if (msgRsp->result == MMA_RESULT_FAIL_FILE_CORRUPTED)
                {
                    mmi_umms_show_corrupt_and_delete();
                    mmi_umms_delete_progress_screen();
                }
                else
                {
                    mmi_umms_show_error_pop_up(msgRsp->result);
                    mmi_umms_delete_progress_screen();
                }
                break;
            case E_STATE_SEND_MMS_FROM_UC:
                mmi_umms_error_in_send_from_uc();
                mmi_umms_delete_progress_screen();
                break;
            case E_STATE_NONE:
                if(GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
                mmi_umms_entry_dummy_screen();
                }
                mmi_umms_delete_progress_screen();
                break;
            default:
                /* Do nothing as this may be a case of End Key Press */
                break;
        }
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_delete_corrupt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_delete_corrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_DELETING_MSG;

    mmi_umms_progress_screen();

    mmi_umms_delete_req(
        E_STATE_NONE,
        E_STATE_DELETE_CORRUPT_MSG,
        g_current_mms_info_list->current_msg_id,
        g_current_mms_info_list->folder_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_current_msg_box
 * DESCRIPTION
 *  Dummy API.
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_current_msg_box(kal_uint16 msg_box_type, U32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_set_current_msg_box Msg_box=%d Msg_index = %d*\n",
                         msg_box_type, msg_index);
    g_current_mms_info_list->folder_id = mmi_umms_convert_umbox_type_to_mma_folder((UmMsgBoxType) msg_box_type);

    g_current_mms_info_list->msg_index = msg_index;
g_um_box_selected = msg_box_type;
    g_msg_index = msg_index;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_convert_mma_folder_to_umbox_type
 * DESCRIPTION
 *  Convert MMA Folder Type to UM folder type
 * PARAMETERS
 *  folder_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
UmMsgBoxType mmi_umms_convert_mma_folder_to_umbox_type(mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder_id)
    {
        case MMA_FOLDER_INBOX:
            return UM_MSG_BOX_TYPE_INBOX;
        case MMA_FOLDER_OUTBOX:
            return UM_MSG_BOX_TYPE_UNSENT;
        case MMA_FOLDER_SENT:
            return UM_MSG_BOX_TYPE_SENT;
        case MMA_FOLDER_DRAFT:
            return UM_MSG_BOX_TYPE_DRAFT;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            return UM_MSG_BOX_TYPE_ARCHIVE;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case MMA_FOLDER_TEMPLATE:
            return UM_MSG_BOX_TYPE_PREDEF_TEMPLATES;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            return UM_MSG_BOX_TYPE_USRDEF_TEMPLATES;
    }
	return UM_MSG_BOX_TYPE_END;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_convert_umbox_type_to_mma_folder
 * DESCRIPTION
 *  Convert UM Folder to MMA Folder Type
 * PARAMETERS
 *  um_box_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_folder_enum mmi_umms_convert_umbox_type_to_mma_folder(UmMsgBoxType um_box_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (um_box_id)
    {
        case UM_MSG_BOX_TYPE_INBOX:
            return MMA_FOLDER_INBOX;
        case UM_MSG_BOX_TYPE_UNSENT:
            return MMA_FOLDER_OUTBOX;
        case UM_MSG_BOX_TYPE_SENT:
            return MMA_FOLDER_SENT;
        case UM_MSG_BOX_TYPE_DRAFT:
            return MMA_FOLDER_DRAFT;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case UM_MSG_BOX_TYPE_ARCHIVE:
            return MMA_FOLDER_ARCHIVE;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case UM_MSG_BOX_TYPE_PREDEF_TEMPLATES:
            return MMA_FOLDER_TEMPLATE;
        case UM_MSG_BOX_TYPE_USRDEF_TEMPLATES:
            return MMA_FOLDER_USRDEF_TEMPLATE;
    }
    return MMA_FOLDER_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_key_hanler
 * DESCRIPTION
 *  Dummy API.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_key_hanler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->key_type_press = OPTION_KEY;
    return;

}

/* Dummy API's End Here */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_viewer_or_properities_screen
 * DESCRIPTION
 *  Show the Viewer or Properties Screen acoording to the Message type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_viewer_or_properities_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_show_viewer_or_properities_screen Msg_Id = %d Msg_type =%d \n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->msg_type);

    g_current_mms_info_list->isShowProperties = MMI_FALSE;
    switch (g_current_mms_info_list->msg_type)
    {
        case MMA_MSG_TYPE_READ_REPORT:
        case MMA_MSG_TYPE_DELIVERY_REPORT:
			mmi_umms_show_viewer_properties_mms();
			break;
        case MMA_MSG_TYPE_MMS:
            if (!g_current_mms_info_list->isRead)
            {
                DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
            }
            mmi_mv_view_message(
                g_current_mms_info_list->current_msg_id,
                g_current_mms_info_list->folder_id,
                g_current_mms_info_list->msg_type,                
                (BOOL)g_current_mms_info_list->isRead,
                (BOOL)g_current_mms_info_list->need_read_report,
                SCR_ID_UMMS_PROGRESS,
                mmi_umms_show_mms_option_screen_according_to_folder_id,
                STR_GLOBAL_OPTIONS);

            break;
		case MMA_MSG_TYPE_NOTIFICATION:
			mmi_umms_show_viewer_properties_mms();
			break;
        case MMA_MSG_TYPE_TEMPLATE:
            mmi_umms_entry_templates_options_screen();
            break;
        case MMA_MSG_TYPE_JAVA:
            mmi_umms_entry_java_mms_screen();
            break;
        default:
            MMI_ASSERT(g_current_mms_info_list->msg_type);
            break;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_mms_option_screen_according_to_folder_id_and_msg_type
 * DESCRIPTION
 *  Function to Enter Restricted Option Accoring to Meg Type and Folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_mms_option_screen_according_to_folder_id_and_msg_type(void)
{
    // This screen will be based on the Folder Selected.
    // The same Function will be called always but with different folfer id

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nNumofItem = 0;
    U16 nStrItemList[MAX_SUB_MENUS] = {0, };
    U16 nImgIltemList[MAX_SUB_MENUS] = {0, };
    U8 to_address_buffer[MMA_MAX_ADDR_LEN] = {0x00, };
    U16 parentid = 0;
    kal_bool is_restricted = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_show_mms_option_screen_according_to_folder_id_and_msg_type Msg_Id = %d Msg_type =%d Box_id = %d\n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->msg_type,
                         g_current_mms_info_list->folder_id);
    EntryNewScreen(
        SCR_ID_UMMS_MMS_OPTIONS,
        NULL,
        mmi_umms_show_mms_option_screen_according_to_folder_id_and_msg_type,
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_MMS_OPTIONS);

    mmi_umms_delete_progress_screen();
    is_restricted = mmi_umms_is_creation_mode_restricted();

    switch (g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            switch (g_current_mms_info_list->msg_type)
            {
                case MMA_MSG_TYPE_NOTIFICATION:
                    parentid = MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION_RESTRICTED;
                    if ((g_current_mms_info_list->msg_status == MMA_MSG_STATUS_WAITING_DOWNLOADING)
                        || (g_current_mms_info_list->msg_status == MMA_MSG_STATUS_DOWNLOADING))
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD);
                    }
                    break;
                case MMA_MSG_TYPE_DELIVERY_REPORT:
                case MMA_MSG_TYPE_READ_REPORT:
                    parentid = MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT_RESTRICTED;
                    break;
                case MMA_MSG_TYPE_MMS:
                    parentid = MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS_RESTRICTED;
					if(g_current_mms_info_list->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER)
					{
						mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_REPLY_SMS);
					}
					else
					{
						mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTION_REPLY_SMS);
					}

            #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_NOTIFICATION) ||
                        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
                        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT) ||
                        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_JAVA) || (!g_current_mms_info_list->isRead))
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_MOVE_TO_ARCHIVE);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_MOVE_TO_ARCHIVE);
                    }
            #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
                    if (g_current_mms_info_list->isForwardLock ||
                        (MMI_UMMS_LOCK_MODE_ON == g_current_mms_info_list->app_data[0]) ||
						((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
						&& (mmi_umms_is_creation_mode_restricted())))
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_FORWARD);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_FORWARD);
                    }
					if((g_current_mms_info_list->isForwardLock == KAL_TRUE)||
                        (MMI_UMMS_LOCK_MODE_ON == g_current_mms_info_list->app_data[0]))
					{
						mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_EDIT_MESSAGE);
					}
					else
					{
						mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_EDIT_MESSAGE);
					}
                    if(g_current_mms_info_list->isForwardLock == KAL_TRUE)
					{
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_SAVE_TO_TEMPLATE);
					}
					else
					{
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_SAVE_TO_TEMPLATE);
					}
                    if (!mmi_ucs2ncmp
                        ((S8*) g_current_mms_info_list->from_address, (S8*) to_address_buffer, MMA_MAX_ADDR_LEN))
                    {
                         mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_REPLY);
                         mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_REPLY_ALL);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_REPLY);
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_REPLY_ALL);
                    }
                    if(g_current_mms_info_list->isForwardLock == KAL_TRUE)
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK_MODE);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK_MODE);
                    }
                    break;
                case MMA_MSG_TYPE_JAVA:
                    parentid = MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS;
                    break;
            }
            break;
        case MMA_FOLDER_OUTBOX:
            switch (g_current_mms_info_list->msg_type)
            {
                case MMA_MSG_TYPE_MMS:
                    if ((g_current_mms_info_list->msg_status == MMA_MSG_STATUS_WAITING_SENDING) ||
                        (g_current_mms_info_list->msg_status == MMA_MSG_STATUS_SENDING))
                    {
                        parentid = MENU_ID_UMMS_OUTBOX_RESTRICTED_OPTIONS;
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
                    }
                    else
                    {
                        parentid = MENU_ID_UMMS_OUTBOX_OPTIONS_RESTRICTED;
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
                    }
                    if ((g_current_mms_info_list->isForwardLock)||
						((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
						&& (mmi_umms_is_creation_mode_restricted())))
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_SEND);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_SEND);
                    }
                    if (g_current_mms_info_list->isForwardLock == KAL_TRUE)
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_EDIT_MESSAGE);
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_SAVE_TO_TEMPLATE);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_EDIT_MESSAGE);
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_SAVE_TO_TEMPLATE);
                    }
                    break;
                default:
                    MMI_ASSERT(g_current_mms_info_list->msg_type);
            }
            break;

        case MMA_FOLDER_SENT:
            switch (g_current_mms_info_list->msg_type)
            {
                case MMA_MSG_TYPE_MMS:
                    parentid = MENU_ID_UMMS_SENT_OPTIONS_RESTRICTED;
                    if ((g_current_mms_info_list->isForwardLock) ||
						((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
						&& (mmi_umms_is_creation_mode_restricted())))
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_FORWARD);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_FORWARD);
                    }
                    if (g_current_mms_info_list->isForwardLock == KAL_TRUE) 
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_EDIT_MESSAGE);
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_SENT_SAVE_TO_TEMPLATE);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_EDIT_MESSAGE);
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SENT_SAVE_TO_TEMPLATE);
                    }
                    break;
                default:
                    MMI_ASSERT(g_current_mms_info_list->msg_type);
            }
            break;
        case MMA_FOLDER_DRAFT:
            switch (g_current_mms_info_list->msg_type)
            {
                case MMA_MSG_TYPE_MMS:
                    parentid = MENU_ID_UMMS_DRAFT_OPTIONS_RESTRICTED;
                    if ((g_current_mms_info_list->isForwardLock) ||
						((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
						&& (mmi_umms_is_creation_mode_restricted())))
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_FORWARD);
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFTS_OPTIONS_SENT);
                    }
                    else
                    {
                        if ((g_current_mms_info_list->umms_mms_xml_msg->to_head == NULL) &&
                            (g_current_mms_info_list->umms_mms_xml_msg->cc_head == NULL) &&
                            (g_current_mms_info_list->umms_mms_xml_msg->bcc_head == NULL))
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFTS_OPTIONS_SENT);
						    mmi_frm_unhide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_FORWARD);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_DRAFTS_OPTIONS_SENT);
						    mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_FORWARD);
                    }
                    }
                    if (g_current_mms_info_list->isForwardLock == KAL_TRUE)
                    {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_EDIT_MESSAGE);
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFTS_SAVE_TO_TEMPLATE);
                    }
                    else
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_EDIT_MESSAGE);
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_DRAFTS_SAVE_TO_TEMPLATE);
                    }
                    break;
                default:
                    MMI_ASSERT(g_current_mms_info_list->msg_type);
            }
            break;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            switch (g_current_mms_info_list->msg_type)
            {
                case MMA_MSG_TYPE_MMS:
                    parentid = MENU_ID_UMMS_ARCHIVE_OPTIONS_MMS_RESTRICTED;
					if ((g_current_mms_info_list->isForwardLock == KAL_TRUE)||
						((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
						&& (mmi_umms_is_creation_mode_restricted())))
					{
						mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_FORWARD);
					}
					else
					{
						mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_FORWARD);
					}
					if (g_current_mms_info_list->isForwardLock == KAL_TRUE)
					{
						mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_EDIT_MESSAGE);
                                                mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_SAVE_TO_TEMPLATE);

                        if (!mmi_ucs2ncmp
                            ((S8*) g_current_mms_info_list->from_address, (S8*) to_address_buffer, MMA_MAX_ADDR_LEN))
                        {
                             mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY);
                             mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL);
                        }
                        else
                        {
                            mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY);
                            mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL);
                        }
					}
					else
					{
						mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_EDIT_MESSAGE);
                                                mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_SAVE_TO_TEMPLATE);
                        if (!mmi_ucs2ncmp
                            ((S8*) g_current_mms_info_list->from_address, (S8*) to_address_buffer, MMA_MAX_ADDR_LEN))
                        {
                             mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY);
                             mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL);
                        }
                        else
                        {
                            mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY);
                            mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL);
                        }
					}
                    break;
            }
            break;
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case MMA_FOLDER_TEMPLATE:
            parentid = MENU_ID_UMMS_TEMPLATES_OPTIONS;
            mmi_frm_hide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE_ALL);
			mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
            break;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            parentid = MENU_ID_UMMS_TEMPLATES_OPTIONS;
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE);
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE_ALL);
			mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
            break;
        default:
            MMI_ASSERT(g_current_mms_info_list->folder_id);
            break;
    }

    nNumofItem = GetNumOfChild_Ext(parentid);
    GetSequenceStringIds_Ext(parentid, nStrItemList);
    GetSequenceImageIds_Ext(parentid, nImgIltemList);
    SetParentHandler(parentid);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_umms_deinit_viewer_and_globals_and_go_to_box_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_deinit_viewer_and_globals_and_go_to_box_list, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_edit
 * DESCRIPTION
 *  Entry Function for Edit MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_edit Msg_id = %d\n",
                         g_current_mms_info_list->current_msg_id);
    if (g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE)
    {
        if (mmi_umms_is_creation_mode_restricted())
        {
            g_current_mms_info_list->uc_mode = MMA_MODE_EDIT;
            mmi_umms_show_content_mode_confrm_pop_up();
        }
        else
        {
            mmi_umms_start_uc_req(g_current_mms_info_list->current_msg_id, MMA_MODE_EDIT);
        }
    }
    else
    {
       mmi_umms_start_uc_req(g_current_mms_info_list->current_msg_id, MMA_MODE_EDIT);
    }
}

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_move_to_archive
 * DESCRIPTION
 *  Entry Function for Move MMS to Archive Folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_move_to_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_move_to_archive Msg_id = %d \n",
                         g_current_mms_info_list->current_msg_id);
    
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) GetString(STR_ID_UMMS_OPTIONS_MOVE_TO_ARCHIVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_move_to_archive_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_move_to_archive_confirm
 * DESCRIPTION
 *  Entry function for move to Archive Confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_move_to_archive_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_PLEASE_WAIT;
    mmi_umms_progress_screen();
    mmi_umms_save_req(
        E_STATE_NONE,
        E_STATE_MOVE_MSG,
        g_current_mms_info_list->current_msg_id,
        MMA_FOLDER_ARCHIVE,
        g_current_mms_info_list->folder_id);
}


#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_reply_to_all
 * DESCRIPTION
 *  Entry Function for Reply to All MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_reply_to_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_reply_to_all Msg_id = %d\n",
                         g_current_mms_info_list->current_msg_id);

    mmi_umms_start_uc_req(g_current_mms_info_list->current_msg_id, MMA_MODE_REPLY_ALL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_reply
 * DESCRIPTION
 *  Entry Function for Reply To MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_reply Msg_id = %d\n",
                         g_current_mms_info_list->current_msg_id);
    /*----------------------------------------------------------------*/
    mmi_umms_start_uc_req(g_current_mms_info_list->current_msg_id, MMA_MODE_REPLY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_view
 * DESCRIPTION
 *  Entry Function to Show the Viewer or review the MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check here is the Message is for View or Review */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_entry_view Msg_id = %d Read Report = %d msg_type = %d\n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->need_read_report,
                         g_current_mms_info_list->msg_type);

    g_current_mms_info_list->isShowProperties = MMI_FALSE;
    
    
        switch (g_current_mms_info_list->msg_type)
        {
            case MMA_MSG_TYPE_READ_REPORT:
            case MMA_MSG_TYPE_DELIVERY_REPORT:
            DeleteScreenIfPresent(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
                DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
                mmi_umms_show_viewer_properties_mms();
                break;
            case MMA_MSG_TYPE_MMS:
            if (mmi_mv_is_viewer_in_history() == MMI_FALSE)
            {
        mmi_umms_progress_screen();
        mmi_mv_view_message(
            g_current_mms_info_list->current_msg_id,
            g_current_mms_info_list->folder_id,
                    g_current_mms_info_list->msg_type,
            (BOOL)g_current_mms_info_list->isRead,
            (BOOL)g_current_mms_info_list->need_read_report,
            SCR_ID_UMMS_PROGRESS,
            mmi_umms_show_mms_option_screen_according_to_folder_id,
            STR_GLOBAL_OPTIONS);
    }
    else
            {
        mmi_mv_review_msg();
    }
            break;
    }
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_total_user_defined_template
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_umms_get_total_user_defined_template(void)
{
	return g_msg_number_struct->userdefined_template_msg_number;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_save_as_template
 * DESCRIPTION
 *  Entry Function for Save as template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_save_as_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_save_as_template Msg_id = %d\n",
                         g_current_mms_info_list->current_msg_id);

    if (g_msg_number_struct->userdefined_template_msg_number >= MAX_USERDEF_TEMPLATE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_UMMS_MAX_TEMPLATE_ALREADY_PRESENT),
            IMG_GLOBAL_EMPTY,
            1,
            MMI_UMMS_POPUP_TIME,
            EMPTY_LIST_TONE);
    }
    else
    {
        g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_SAVING;
        mmi_umms_progress_screen();
        mmi_umms_usr_def_templ_get_msg_content_req(g_current_mms_info_list->current_msg_id);
    }

}


/*****************************************************************************
 * FUNCTION
 *  pre_mmi_umms_entry_delete_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void pre_mmi_umms_entry_delete_msg(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] pre_mmi_umms_entry_delete_msg Msg_id = %d\n", msg_id);
    g_current_mms_info_list->current_msg_id = msg_id;
    mmi_umms_entry_delete_msg();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_delete_msg
 * DESCRIPTION
 *  Entry Function for Delete MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_delete_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	umms_read_report_enum rr_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_delete_msg Msg_id = %d Box_id = %d \n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->folder_id);
    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_DELETING_MSG;

	if((g_current_mms_info_list->need_read_report == KAL_TRUE) &&
		(g_current_mms_info_list->folder_id == MMA_FOLDER_INBOX) 
		&& (g_current_mms_info_list->isRead == KAL_FALSE))
	{
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "We are here 1 \n");
		rr_status = mmi_umms_retrieval_settings_read_report();
		if (rr_status  == E_READ_REPORT_SEND_ON_REQUEST)
		{
			mmi_umms_entry_send_rr_confirmation();
			return;
		}
		else
		{
			mmi_umms_send_read_report_for_delete_mms();
		}
	}
	else
	{
		//mmi_umms_progress_screen();
		mmi_umms_dont_send_read_mark_for_delete_mms();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_send_rr_confirmation
 * DESCRIPTION
 *  Send Cancel Request for any MMS that is in Sending State.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_send_rr_confirmation(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "We are here 3 \n");
	EntryNewScreen(SCR_ID_UMMS_READ_REPORT, NULL, NULL, NULL);
    
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) GetString(STR_ID_MMS_VIEWER_SEND_RR_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_send_read_report_for_delete_mms, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_umms_dont_send_read_mark_for_delete_mms, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_read_mark_for_delete_mms
 * DESCRIPTION
 *  Send Cancel Request for any MMS that is in Sending State.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_read_report_for_delete_mms(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Add this is in the Send Handler List. Only after Response is received 
	send the Delete Req */
    mmi_umms_progress_screen();
	mmi_umms_add_to_list(g_current_mms_info_list->current_msg_id, 0, E_STATE_SEND_MSG, E_STATE_DELETE_WITHOUT_READ);
	mmi_umms_set_read_report_req(g_current_mms_info_list->current_msg_id);
	//mmi_umms_dont_send_read_mark_for_delete_mms();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dont_send_read_mark_for_delete_mms
 * DESCRIPTION
 *  Send Cancel Request for any MMS that is in Sending State.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dont_send_read_mark_for_delete_mms(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(GetActiveScreenId() != SCR_ID_UMMS_PROGRESS)
	{
		mmi_umms_delete_progress_screen();
		mmi_umms_progress_screen();
	}
    mmi_umms_delete_req(
        E_STATE_NONE,
        E_STATE_DELETE_MSG,
        g_current_mms_info_list->current_msg_id,
        g_current_mms_info_list->folder_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_sending_state
 * DESCRIPTION
 *  Send Cancel Request for any MMS that is in Sending State.
 * PARAMETERS
 *  msg_id          [IN]        
 *  folder_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_check_sending_state(const U32 msg_id, const mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    umms_state_enum current_state_of_msg_in_queue, intermediate_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_check_if_more_mms_is_in_send_state msg_id = %d Box_id = %d\n",
                         msg_id, folder_id);
    current_state_of_msg_in_queue = mmi_umms_get_state_of_msg_from_send_list(msg_id);
    if (current_state_of_msg_in_queue == E_STATE_NONE)
    {
        /* Check here that the New Msg has been created so check for the old msg_id and get the state */
        intermediate_state = mmi_umms_get_intermediate_state_by_old_msg_id(msg_id);
        if (intermediate_state != E_STATE_NONE)
        {
            current_state_of_msg_in_queue = E_STATE_SEND_MSG;
        }
    }
    else
    {
        intermediate_state = mmi_umms_get_intermediate_state_of_msg_from_send_list(msg_id);
    }

    if (intermediate_state == E_STATE_NONE)
    {
        /* Might be the Message is in the deletion state so check the request Handler */
        current_state_of_msg_in_queue = mmi_umms_get_current_state_from_req_hndlr(msg_id);

    }
    switch (current_state_of_msg_in_queue)
    {
        case E_STATE_SEND_MSG:
            if (intermediate_state == E_STATE_INTR_SEND_MSG)
            {
                mmi_umms_entry_cancel_req(E_STATE_CANCEL_SEND_AND_DELETE_MSG, msg_id, folder_id);
            }
            else
            {
                if ((intermediate_state == E_STATE_GET_CONTENT_MSG) || (intermediate_state == E_STATE_CREATE_MSG)
                    || (intermediate_state == E_STATE_SAVE_NEW_MMS))
                {
                    /* Show here a Customized PopUp and go to Message List Screen */
                    mmi_umms_show_in_creation_process_pop_up();
                }

            }
            break;
        case E_STATE_DELETE_AFTER_NEW_MSG_CREATION:
            /* Show here a Customized PopUp and go to Message List Screen */
            mmi_umms_show_in_creation_process_pop_up();
            break;
        default:
            mmi_umms_delete_req(
                E_STATE_NONE,
                E_STATE_DELETE_MSG,
                g_current_mms_info_list->current_msg_id,
                g_current_mms_info_list->folder_id);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_current_state_from_req_hndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_current_state_from_req_hndlr(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_req_msg_handler_struct *msg_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_current_state_from_req_hndlr Msg_id = %d \n",
                         g_current_mms_info_list->current_msg_id);

    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;

    while (msg_hndlr != NULL)
    {
        if (msg_hndlr->msg_id == msg_id)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_current_state_from_req_hndlr Returned Current State = %d \n",
                                 msg_hndlr->current_state);

            return msg_hndlr->current_state;

        }
        else
        {
            msg_hndlr = msg_hndlr->next;
        }
    }
    return E_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_intermediate_state_by_old_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_intermediate_state_by_old_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_intermediate_state_by_old_msg_id Msg_id= %d \n", msg_id);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->old_msg_id == msg_id)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_intermediate_state_by_old_msg_id Old_Msg_id= %d Intermediate_state = %d \n",
                                 send_msg_handlr->old_msg_id, send_msg_handlr->intermediate_state);
            return send_msg_handlr->intermediate_state;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return E_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_delete_all
 * DESCRIPTION
 *  Entry Function for Delete All MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_delete_all Folder_id = %d\n",
                         g_current_mms_info_list->folder_id);
    mmi_umms_send_delete_all_ind_to_um(g_current_mms_info_list->folder_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_sending_state_of_all_and_update_state
 * DESCRIPTION
 *  Check Sending state of the MMS and then make decision.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_check_sending_state_of_all_and_update_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    umms_send_msg_handler_struct *send_msg_hndlr = NULL;
    umms_state_enum current_state_of_msg_in_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_check_sending_state_of_all_and_update_state\n");
    send_msg_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    if (send_msg_hndlr == NULL)
    {
        /* Send Delete ALL Indication to UM */
        mmi_umms_send_delete_all_ind_to_um(g_current_mms_info_list->folder_id);
    }
    else
    {
        while (send_msg_hndlr != NULL)
        {
            current_state_of_msg_in_queue = mmi_umms_get_state_of_msg_from_send_list(send_msg_hndlr->msg_id);
            if (current_state_of_msg_in_queue == E_STATE_SEND_MSG)
            {
                mmi_umms_entry_cancel_req(
                    E_STATE_CANCEL_SEND_AND_DELETE_ALL_MSG,
                    send_msg_hndlr->msg_id,
                    g_current_mms_info_list->folder_id);
            }
            send_msg_hndlr = send_msg_hndlr->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_if_more_mms_is_in_send_state
 * DESCRIPTION
 *  Check if more MMS are in sending state or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_check_if_more_mms_is_in_send_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_check_if_more_mms_is_in_send_state\n");
    if (g_dwnld_send_list->g_umms_send_msg_hndlr != NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_cancel_req
 * DESCRIPTION
 *  Entry Function for Cancel Send.
 * PARAMETERS
 *  updated_state       [IN]        
 *  msg_id              [IN]        
 *  folder_id           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_cancel_req(const umms_state_enum updated_state, const U32 msg_id, const mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */

    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_entry_cancel_req msg_id = %d Box_id = %d State = %d\n",
                         msg_id, folder_id, updated_state);
    mmi_umms_update_send_msg_handler(updated_state, msg_id, UMMS_SEND_VERSION_NONE, 1);
    mmi_umms_cancel_req(msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_delete_req
 * DESCRIPTION
 *  Entry Function for Delete Req.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_delete_req(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_cancel_req msg_id = %d \n", msg_id);
    mmi_umms_delete_req(
        E_STATE_NONE,
        E_STATE_DELETE_MSG,
        g_current_mms_info_list->current_msg_id,
        g_current_mms_info_list->folder_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_all_req
 * DESCRIPTION
 *  Entry Function For delete All req.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_all_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_delete_all_req Box_id = %d \n", g_current_mms_info_list->folder_id);
    mmi_umms_send_delete_all_ind_to_um(g_current_mms_info_list->folder_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_cancel_send
 * DESCRIPTION
 *  Entry Function Cancel Send Operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_cancel_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_entry_cancel_send Msg_Id = %d \n",
                         g_current_mms_info_list->current_msg_id);

    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_CANCEL_SEND;
    mmi_umms_progress_screen();
    mmi_umms_cancel_req(g_current_mms_info_list->current_msg_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_send_msg
 * DESCRIPTION
 *  Pre Entry Function for Send.
 * PARAMETERS
 *  void
 *  msg_id(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_send_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_pre_entry_send_msg Msg_Id = %d \n",
                         g_current_mms_info_list->current_msg_id);
    mmi_umms_entry_send_msg_from_box(g_current_mms_info_list->current_msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_send_msg_from_box
 * DESCRIPTION
 *  Entry Function for Send.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_send_msg_from_box(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_send_msg_from_box Msg_Id = %d \n", msg_id);
    if (g_current_mms_info_list->folder_id != MMA_FOLDER_OUTBOX)
    {   /* Move the MMS from the cerresponding Folder to the Outbox. */
        g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_SENDING;
        mmi_umms_progress_screen();
        mmi_umms_save_req(
            E_STATE_SAVE_BEFORE_SEND,
            E_STATE_SEND_MSG,
            g_current_mms_info_list->current_msg_id,
            MMA_FOLDER_OUTBOX,
            g_current_mms_info_list->folder_id);
    }
    else
    {   /* Add this in the list first. */
        mmi_umms_add_to_list(g_current_mms_info_list->current_msg_id, 0, E_STATE_SEND_MSG, E_STATE_INTR_SEND_MSG);
        mmi_umms_update_retry_counter_send_req(g_current_mms_info_list->current_msg_id, 0, 1);
        mmi_umms_send_mms_msg(g_current_mms_info_list->current_msg_id);
        mmi_umms_go_to_box_list_screen();
        GoBackHistory();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_send_msg
 * DESCRIPTION
 *  Entry Function for Send.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_send_msg(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_send_msg Msg_Id = %d \n", msg_id);
    /* This is Called after UC creates a MMS and Says Send */
    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_SENDING;
	if(!mmi_umms_is_in_call())
	{
    mmi_umms_progress_screen();
	}

    mmi_umms_get_header_request(msg_id, E_STATE_SEND_MMS_FROM_UC, MMA_FOLDER_DRAFT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_get_message_status
 * DESCRIPTION
 *  Get Message Status from Global Context.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_msg_status_enum mmi_umms_get_get_message_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_get_message_status Msg_Id = %d \n",
                         g_current_mms_info_list->current_msg_id);
    return g_current_mms_info_list->msg_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_show_properties
 * DESCRIPTION
 *  Entry Function for Show Properties
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_show_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->isShowProperties = MMI_TRUE;
    mmi_umms_show_properties_mms();
    //mmi_umms_show_properties_according_to_box_type(g_current_mms_info_list);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_show_properties_dispatcher
 * DESCRIPTION
 *  Entry Function for Show Properties
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_show_properties_dispatcher(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_current_mms_info_list->msg_type == MMA_MSG_TYPE_NOTIFICATION)
	{
		mmi_umms_entry_download_msg();
		return;
	}
    if ( g_current_mms_info_list->isShowProperties == MMI_TRUE)
    {
        mmi_umms_show_properties_mms();        
    }
    else
    {
        mmi_umms_show_viewer_properties_mms();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_download_msg
 * DESCRIPTION
 *  Entry Function for Download.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_download_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_secs_since_1970 = 0;
    U32 size_available = 0;
    U32 used_bytes = 0;
    U32 total_num_messages = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_entry_download_msg MSgId=%d \n",
                         g_current_mms_info_list->current_msg_id);

    current_secs_since_1970 = umms_get_current_utc_time();

	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] Current Time CT=%d \n",
                         current_secs_since_1970);
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] Expirry Time ET=%d \n",
                         g_current_mms_info_list->expiry_time);
    if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
    {
		mmi_umms_entry_dummy_screen();
    }
    
    mmi_umms_delete_progress_screen();
 		mmi_umms_get_total_number_of_messages(&total_num_messages);
    if(total_num_messages >= MAX_POSSIBLE_MESSAGES_MAX)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED),
            IMG_GLOBAL_WARNING,
            1,
            MMI_UMMS_POPUP_TIME,
            WARNING_TONE);
        return;
    }
    if (current_secs_since_1970 > g_current_mms_info_list->expiry_time)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_UMMS_NOTIFICATION_EXPIRED),
            IMG_GLOBAL_ERROR,
            1,
            MMI_UMMS_POPUP_TIME,
            ERROR_TONE);
        return;
    }
    if (g_current_mms_info_list->umms_mms_xml_msg->download_size > wap_custom_get_max_mms_msg_size())
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_UMMS_OPTIONS_MSG_SIZE_EXCEED),
            IMG_GLOBAL_ERROR,
            1,
            MMI_UMMS_POPUP_TIME,
            ERROR_TONE);
        return;
    }
    size_available = mma_get_mms_avaliable_file_space(&used_bytes);

    if (size_available < g_current_mms_info_list->umms_mms_xml_msg->download_size)
    {
        DisplayPopup((PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, MMI_UMMS_POPUP_TIME, ERROR_TONE);
        return;
    }

    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_DOWNLOADING;

    mmi_umms_progress_screen();
    mmi_umms_download_req(g_current_mms_info_list->current_msg_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_download_msg_after_call_end
 * DESCRIPTION
 *  Entry Function for Download After Call End.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_download_msg_after_call_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL progress_scr_present = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_download_msg_after_call_end \n");
    if (umms_end_call_is_download_in_progress())
    {
        /* Check the state of the message. IF the state is E_STATE_DOWNLOAD_FAIL_DUE_TO_CALL then folow the redownload steps 
        else update the category Screen for Download*/
        progress_scr_present = IsScreenPresent(SCR_ID_UMMS_PROGRESS);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] progress_scr_present=%d \n",progress_scr_present);
        if(!(IsScreenPresent(SCR_ID_UMMS_PROGRESS) || (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)))
        {
            if(mmi_umms_get_current_state_of_download(g_dwnld_send_list->g_umms_dwnld_msg_hndlr->msg_id) == E_STATE_DOWNLOAD_FAIL_DUE_TO_CALL)
            {
        g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_DOWNLOADING;
                g_current_mms_info_list->folder_id = MMA_FOLDER_INBOX;
        g_current_mms_info_list->current_msg_id = g_dwnld_send_list->g_umms_dwnld_msg_hndlr->msg_id;
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSAppMain.c] mmi_umms_entry_download_msg_after_call_end MSgId=%d \n",
                             g_current_mms_info_list->current_msg_id);
        mmi_umms_free_download_list_msg_id(g_current_mms_info_list->current_msg_id);
        mmi_umms_progress_screen();
        mmi_umms_download_req(g_current_mms_info_list->current_msg_id);
    }
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_free_download_list_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_free_download_list_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *download_msg_hndlr = NULL;
    umms_download_msg_handler_struct *temp_node_download = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_free_download_list_msg_id Msg_id = %d  \n", msg_id);

    download_msg_hndlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    if (download_msg_hndlr != NULL)
    {
        while (download_msg_hndlr != NULL)
        {

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_free_download_handler_node Print List Msg_id = %d Req_id = %d Download Retry counter = %d current_state = %d \n",
                                 download_msg_hndlr->msg_id, download_msg_hndlr->req_id,
                                 download_msg_hndlr->retry_counter, download_msg_hndlr->current_state);
            download_msg_hndlr = download_msg_hndlr->next;
        }
    }

    download_msg_hndlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;

    if (download_msg_hndlr != NULL)
    {
        if (download_msg_hndlr->msg_id == msg_id)
        {
            if (download_msg_hndlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_dwnld_send_list->g_umms_dwnld_msg_hndlr);
                g_dwnld_send_list->g_umms_dwnld_msg_hndlr = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_dwnld_send_list->g_umms_dwnld_msg_hndlr = download_msg_hndlr->next;
                umms_free(download_msg_hndlr);
                download_msg_hndlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node_download = download_msg_hndlr;
            download_msg_hndlr = download_msg_hndlr->next;
            while (download_msg_hndlr != NULL)
            {
                if (download_msg_hndlr->msg_id == msg_id)
                {
                    break;
                }
                else
                {
                    download_msg_hndlr = download_msg_hndlr->next;
                    temp_node_download = temp_node_download->next;
                }
            }
            /* In between node needs to be deleted */
            if (download_msg_hndlr != NULL)
            {
                if (download_msg_hndlr->msg_id == msg_id)
                {
                    if (download_msg_hndlr->next != NULL)
                    {
                        temp_node_download->next = download_msg_hndlr->next;
                        umms_free(download_msg_hndlr);
                        download_msg_hndlr = NULL;
                    }
                    else
                    {
                        /* The last node is to be deleted. */
                        temp_node_download->next = NULL;
                        umms_free(download_msg_hndlr);
                        download_msg_hndlr = NULL;
                    }
                }
            }
            else
            {
                /* Node doesnot exist in the List */
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_download_mms
 * DESCRIPTION
 *  Pre Entry Function for Download.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_download_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_pre_entry_download_mms Msg_id = %d\n",
                         g_current_mms_info_list->current_msg_id);


	 // Call the Viewer Over here to get the download Size of the MMS
   // mmi_umms_show_viewer_properties_mms();
/*	mmi_umms_set_progress_screen();
	mmi_mv_view_message(
            g_current_mms_info_list->current_msg_id,
            g_current_mms_info_list->folder_id,
            g_current_mms_info_list->msg_type,
            (BOOL)g_current_mms_info_list->isRead,
            (BOOL)g_current_mms_info_list->need_read_report,
            SCR_ID_UMMS_PROGRESS,
            mmi_umms_show_mms_option_screen_according_to_folder_id,
            STR_GLOBAL_OPTIONS);*/
    mmi_umms_entry_download_msg();
}


/*****************************************************************************
 * FUNCTION
 *  umms_end_call_is_download_in_progress
 * DESCRIPTION
 *  
 *  details
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL umms_end_call_is_download_in_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dwnld_send_list->g_umms_dwnld_msg_hndlr != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] umms_end_call_is_download_in_progress TRUE \n");

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_use_details_req
 * DESCRIPTION
 *  Sends Request to MMI to get numbers, emails or url information for use
 *  details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_use_details_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_mv_get_use_details_req_struct *req =
        (mmi_mv_get_use_details_req_struct*) OslConstructDataPtr(sizeof(mmi_mv_get_use_details_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_use_details_progress_screen();
    req->request_type = g_current_mms_info_list->umms_use_details.mms_umms_app_slide;
    req->progress_screen_id = SCR_ID_UMMS_PROGRESS_USE_DETAILS;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;

    Message.oslMsgId = MSG_ID_MMI_MV_GET_USE_DETAILS_REQ;
    Message.oslDataPtr = (oslParaType*) req;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_header_use_details
 * DESCRIPTION
 *  supply header use details to APP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_header_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_current_mms_info_list->umms_use_details.mms_umms_app_slide = MMI_MV_GET_USE_DETAILS_MSG_HEADERS;
    mmi_umms_entry_use_details_options();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_use_details_rsp
 * DESCRIPTION
 *  Response handler for the use details request
 * PARAMETERS
 *  inmsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_use_details_rsp(void *inmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_get_use_details_rsp_struct *rsp = (mmi_mv_get_use_details_rsp_struct*) inmsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->umms_use_details.get_use_details_rsp.num_list = rsp->num_list;
    g_current_mms_info_list->umms_use_details.get_use_details_rsp.email_list = rsp->email_list;
    g_current_mms_info_list->umms_use_details.get_use_details_rsp.url_list = rsp->url_list;
    g_current_mms_info_list->umms_use_details.get_use_details_rsp.header_num_list = rsp->header_num_list;
    g_current_mms_info_list->umms_use_details.get_use_details_rsp.header_email_list = rsp->header_email_list;
    g_current_mms_info_list->umms_use_details.get_use_details_rsp.returned_type = rsp->returned_type;
    g_current_mms_info_list->umms_use_details.get_use_details_rsp.result = rsp->result;

    if (GetActiveScreenId() != SCR_ID_UMMS_PROGRESS_USE_DETAILS)
    {
        if (mmi_umms_is_usb_mode())
        {
            return;
        }
        else if (MMI_MV_GET_USE_DETAILS_RESULT_SUCCESS ==
                 g_current_mms_info_list->umms_use_details.get_use_details_rsp.result)
        {
            HistoryReplace(
                SCR_ID_UMMS_PROGRESS_USE_DETAILS,
                SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS_OPTIONS,
                mmi_umms_entry_use_details_options);
            return;
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS_USE_DETAILS);
            return;
        }
    }

    if (g_current_mms_info_list->umms_use_details.get_use_details_rsp.returned_type ==
        g_current_mms_info_list->umms_use_details.mms_umms_app_slide)
    {
        if (MMI_MV_GET_USE_DETAILS_RESULT_SUCCESS ==
            g_current_mms_info_list->umms_use_details.get_use_details_rsp.result)
        {
            mmi_umms_entry_use_details_options();
        }
        else
        {
            if (MMI_MV_GET_USE_DETAILS_RESULT_OUT_OF_MEM ==
                g_current_mms_info_list->umms_use_details.get_use_details_rsp.result)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UMMS_POPUP_TIME,
                    ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_UMMS_FAILED),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UMMS_POPUP_TIME,
                    ERROR_TONE);
            }
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS_USE_DETAILS);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_UMMS_FAILED), IMG_GLOBAL_ERROR, 1, MMI_UMMS_POPUP_TIME, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS_USE_DETAILS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_use_details_options
 * DESCRIPTION
 *  Entry function to the use details options(number, email and url) screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_details_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nNumofItem = 0;
    U16 nStrItemList[MMI_UMMS_NUM_ADDR_TYPE]={0,};

    U16 parentid = 0;
    U16 scrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrid = SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS_OPTIONS;
    switch (g_current_mms_info_list->umms_use_details.mms_umms_app_slide)
    {
        case MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT:
            parentid = MENU_ID_UMMS_USE_DETAILS_CURRENT_SLIDE;
            break;
        case MMI_MV_GET_USE_DETAILS_SLIDE_ALL:
            parentid = MENU_ID_UMMS_USE_DETAILS_ALL_SLIDES;
            break;
        case MMI_MV_GET_USE_DETAILS_MSG_HEADERS:
            parentid = MENU_ID_UMMS_USE_DETAILS_MESSAGE_HEADER;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    EntryNewScreen(scrid, NULL, mmi_umms_entry_use_details_options, NULL);

    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS_USE_DETAILS);

    guiBuffer = GetCurrGuiBuffer(scrid);
    nNumofItem = GetNumOfChild(parentid);
    GetSequenceStringIds(parentid, nStrItemList);
    SetParentHandler(parentid);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_UMMS_OPTIONS_USE_DETAILS_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
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
 *  mmi_umms_entry_use_details_addresses_list
 * DESCRIPTION
 *  Entry function for the number, email or url list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_details_addresses_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL; 
    U16 strid = 0;
    U16 strid2 = 0;
    U16 num_item = 0;
    U16 scrid = 0;
    U16 menuid = 0;
    applib_address_node_struct *node1 = NULL;



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrid = SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS_ADDRESS_LIST;

    if (APPLIB_ADDR_TYPE_PHONENUMBER == g_current_mms_info_list->umms_use_details.applib_addr_type)
    {
        menuid = MENU_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER;
    }
    else if (APPLIB_ADDR_TYPE_EMAIL == g_current_mms_info_list->umms_use_details.applib_addr_type)
    {
        menuid = MENU_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL;
    }
    else if (APPLIB_ADDR_TYPE_URL == g_current_mms_info_list->umms_use_details.applib_addr_type)
    {
        menuid = MENU_ID_UMMS_OPTION_USE_DETAILS_URL;
    }
    else
    {
        MMI_ASSERT(0);
        return;
    }

    if ((MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT == g_current_mms_info_list->umms_use_details.mms_umms_app_slide) ||
        (MMI_MV_GET_USE_DETAILS_SLIDE_ALL == g_current_mms_info_list->umms_use_details.mms_umms_app_slide))
    {
        switch (g_current_mms_info_list->umms_use_details.applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.num_list;
                strid = STR_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER_LIST;
                strid2 = STR_ID_UMMS_USE_DETAILS_NO_NUMBER;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.email_list;
                strid = STR_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL_LIST;
                strid2 = STR_ID_UMMS_USE_DETAILS_NO_EMAIL_ID;
                break;
            case APPLIB_ADDR_TYPE_URL:
                node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.url_list;
                strid = STR_ID_UMMS_OPTIONS_USE_DETAILS_URL_LIST;
                strid2 = STR_ID_UMMS_USE_DETAILS_NO_URL;
                break;
            default:
                MMI_ASSERT(0);
                break;
        }
        while (node1 != NULL)
        {
            num_item++;
            node1 = node1->next;
        }

    }
    else if (MMI_MV_GET_USE_DETAILS_MSG_HEADERS == g_current_mms_info_list->umms_use_details.mms_umms_app_slide)
    {
        switch (g_current_mms_info_list->umms_use_details.applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                strid = STR_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER_LIST;
                strid2 = STR_ID_UMMS_USE_DETAILS_NO_NUMBER;
                num_item = g_current_mms_info_list->umms_mms_xml_msg->ph_num;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                strid = STR_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL_LIST;
                strid2 = STR_ID_UMMS_USE_DETAILS_NO_EMAIL_ID;
                num_item  = g_current_mms_info_list->umms_mms_xml_msg->email_num;
                break;
            default:
                MMI_ASSERT(0);
                break;
        }

    }
    else
    {
        MMI_ASSERT(0);
        return;
    }
    

    if (0 == num_item)
    {
        DisplayPopup((U8*) GetString(strid2), IMG_GLOBAL_EMPTY, 1, MMI_UMMS_POPUP_TIME, EMPTY_LIST_TONE);
        return;
    }

    EntryNewScreen(scrid, NULL, mmi_umms_entry_use_details_addresses_list, NULL);
    gui_buffer = GetCurrGuiBuffer(scrid);

    SetParentHandler(menuid);
    RegisterHighlightHandler(mmi_umms_use_details_list_highlight_hdlr);

    ShowCategory184Screen(
        strid,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        mmi_umms_get_address_list,
        NULL,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_umms_entry_use_details_addresses_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_details_addresses_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_entry_use_details_addresses_options, KEY_WAP, KEY_EVENT_DOWN);

    if (APPLIB_ADDR_TYPE_PHONENUMBER == g_current_mms_info_list->umms_use_details.applib_addr_type)
    {
        SetKeyHandler(mmi_umms_use_details_call, KEY_SEND, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_address_list
 * DESCRIPTION
 *  Callback function for the Category184Screen in API
 *  mmi_umms_entry_use_details_addresses_list
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_umms_get_address_list(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    S32 len = 0;
    U8 type;
    S8* data = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
           switch (g_current_mms_info_list->umms_use_details.applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                *img_buff_p = get_image(IMG_ID_UMMS_USE_DETAILS_IMAGE_NUMBER);
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                *img_buff_p = get_image(IMG_ID_UMMS_USE_DETAILS_IMAGE_EMAIL);
                break;
            case APPLIB_ADDR_TYPE_URL:
                *img_buff_p = get_image(IMG_ID_UMMS_USE_DETAILS_IMAGE_URL);
                break;
            default:
                MMI_ASSERT(0);
                break;
        }
   
   
    data = mmi_umms_get_addr_content_by_index_for_screen_display((S32)item_index,&type);
    if(type == UMMS_DATA_TYPE_UCS2)
    {
        len = (mmi_ucs2strlen((S8*) data)) * ENCODING_LENGTH;
        if (len <= (MAX_SUB_MENU_SIZE - ENCODING_LENGTH))
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) data);
        }
        else
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) data, (MAX_SUB_MENU_SIZE - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
            mmi_ucs2cat((S8*) str_buff, (S8*) L"...");
        }
    }
    else if(type == UMMS_DATA_TYPE_ANSII)
    {
        len = (strlen((S8*) data)) * ENCODING_LENGTH;
        if (len <= (MAX_SUB_MENU_SIZE - ENCODING_LENGTH))
        {
            mmi_asc_to_ucs2((S8*) str_buff, (S8*) data);
    }
        else
        {
            memset(str_buff, 0, (MAX_SUB_MENU_SIZE - (3 * ENCODING_LENGTH)));
            mmi_asc_n_to_ucs2((S8*) str_buff, (S8*) data, (MAX_SUB_MENU_SIZE - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
            mmi_ucs2cat((S8*) str_buff, (S8*) L"...");
        }
     }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_addr_content_by_index_for_screen_display
 * DESCRIPTION
 *  This API saves the item at the given index to the Global Context
 * PARAMETERS
 *  index
 *  type             
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_umms_get_addr_content_by_index_for_screen_display(S32 index, U8* type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *node1 = NULL;
    mmi_umms_addr_struct *node2 = NULL;
    S32 count = 0;
    U8 parse_list = UMMS_FROM;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT == g_current_mms_info_list->umms_use_details.mms_umms_app_slide) ||
        (MMI_MV_GET_USE_DETAILS_SLIDE_ALL == g_current_mms_info_list->umms_use_details.mms_umms_app_slide))
    {
        switch (g_current_mms_info_list->umms_use_details.applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.num_list;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.email_list;
                break;
            case APPLIB_ADDR_TYPE_URL:
                node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.url_list;
                break;
            default:
                MMI_ASSERT(0);
                break;
        }

        while (count < index)
    {
        node1 = node1->next;
        ++count;
    }
        *type = UMMS_DATA_TYPE_UCS2;
        return (S8*)node1->data;

    }
    else if (MMI_MV_GET_USE_DETAILS_MSG_HEADERS == g_current_mms_info_list->umms_use_details.mms_umms_app_slide)
    {
        --count;
        switch (g_current_mms_info_list->umms_use_details.applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                while((count < index)&&(parse_list < (UMMS_BCC_LIST + 1)))
                {
                    switch (parse_list)
                    {
                        case UMMS_FROM:    node2 = g_current_mms_info_list->umms_mms_xml_msg->from;
                                           if(node2 != NULL) 
                                           {
                                               if(MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                               {
                                                   count++;
                                               }
                                           }
                                           parse_list++;
                                           break;
                        case UMMS_TO_LIST: node2 = g_current_mms_info_list->umms_mms_xml_msg->to_head;
                                           while((node2 != NULL)&&(count < index))
                                           {
                                               if(MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                               {
                                                   count++;
                                               }
                                               if(count < index)
                                               {
                                                   node2 = node2->next;
                                               }
                                           }
                                           parse_list++;
                                           break;
                        case UMMS_CC_LIST: node2 = g_current_mms_info_list->umms_mms_xml_msg->cc_head;
                                           while((node2 != NULL)&&(count < index))
                                           {
                                              if(MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                              {
                                                  count++;
                                              }
                                              if(count < index)
                                              {
                                                  node2 = node2->next;
                                              }
                                           }
                                           parse_list++;
                                           break;
                        case UMMS_BCC_LIST:node2 = g_current_mms_info_list->umms_mms_xml_msg->bcc_head;
                                           while((node2 != NULL)&&(count < index))
                                           {
                                               if(MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                               {
                                                   count++;
                                               }
                                               if(count < index)
                                               {
                                                   node2 = node2->next;
                                               }
                                           }
                                           parse_list++;
                                           break;
                        default:   break;
                    }
                }
                *type = UMMS_DATA_TYPE_ANSII;
                return (S8*) node2->addr;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                while((count < index)&&(parse_list < 4))
                {
                    switch (parse_list)
                    {
                        case UMMS_FROM:     node2 = g_current_mms_info_list->umms_mms_xml_msg->from;
                                            if(node2 != NULL)
                                            {
                                                if(MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                                {
                                                    count++;
                                                }
                                            }
                                            parse_list++;
                                            break;
                        case UMMS_TO_LIST:  node2 = g_current_mms_info_list->umms_mms_xml_msg->to_head;
                                            while((node2 != NULL)&&(count < index))
                                            {
                                                if(MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                                {
                                                    count++;
                                                }
                                                if(count < index)
                                                {
                                                    node2 = node2->next;
                                                }
                                            }
                                            parse_list++;
                                            break;
                        case UMMS_CC_LIST:  node2 = g_current_mms_info_list->umms_mms_xml_msg->cc_head;
                                            while((node2 != NULL)&&(count < index))
                                            {
                                                if(MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                                {
                                                    count++;
                                                }
                                                if(count < index)
                                                {
                                                    node2 = node2->next;
                                                }
                                            }
                                            parse_list++;
                                            break;
                        case UMMS_BCC_LIST: node2 = g_current_mms_info_list->umms_mms_xml_msg->bcc_head;
                                            while((node2 != NULL)&&(count < index))
                                            {
                                                if(MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
    {
                                                    count++;
    }
                                                if(count < index)
    {
                                                    node2 = node2->next;
                                                }
    }
                                            parse_list++;
                                            break;

                        default:            break;
                    }
                }
                *type = UMMS_DATA_TYPE_UCS2;
                return (S8*) node2->addr;
                break;
            default:
                MMI_ASSERT(0);
                return NULL;
                break;
}

    }
    MMI_ASSERT(0);
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_addr_content_by_index
 * DESCRIPTION
 *  This API saves the item at the given index to the Global Context
 * PARAMETERS
 *  index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_addr_content_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *node1 = NULL;
    mmi_umms_addr_struct *node2 = NULL;
    S32 count = 0;
    U8 parse_list = UMMS_FROM;
    U32 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_current_mms_info_list->addr != NULL)
    {
        umms_free(g_current_mms_info_list->addr);
        g_current_mms_info_list->addr = NULL;
    }
    if ((MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT == g_current_mms_info_list->umms_use_details.mms_umms_app_slide) ||
        (MMI_MV_GET_USE_DETAILS_SLIDE_ALL == g_current_mms_info_list->umms_use_details.mms_umms_app_slide))
    {
        switch (g_current_mms_info_list->umms_use_details.applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
        node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.num_list;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.email_list;
                break;
            case APPLIB_ADDR_TYPE_URL:
                node1 = g_current_mms_info_list->umms_use_details.get_use_details_rsp.url_list;
                break;
            default:
                MMI_ASSERT(0);
                break;
        }
        
        while (count < index)
        {
            node1 = node1->next;
            ++count;
        }
        
        if(APPLIB_ADDR_TYPE_PHONENUMBER == g_current_mms_info_list->umms_use_details.applib_addr_type)
        {
            len = mmi_ucs2strlen((S8*)(node1->data2));
            g_current_mms_info_list->addr = (U16*)umms_malloc((len+1)*ENCODING_LENGTH);
            MMI_ASSERT(g_current_mms_info_list->addr);
            memset(g_current_mms_info_list->addr,0,(len+1)*ENCODING_LENGTH);
            mmi_ucs2ncpy((S8*) g_current_mms_info_list->addr, (S8*) node1->data2, len);
        }
        else
        {
            len = mmi_ucs2strlen((S8*)(node1->data));
            g_current_mms_info_list->addr = (U16*)umms_malloc((len+1)*ENCODING_LENGTH);
            MMI_ASSERT(g_current_mms_info_list->addr);
            memset(g_current_mms_info_list->addr,0,(len+1)*ENCODING_LENGTH);
            mmi_ucs2ncpy((S8*) g_current_mms_info_list->addr, (S8*) node1->data, len);
        }
    }
    else if (MMI_MV_GET_USE_DETAILS_MSG_HEADERS == g_current_mms_info_list->umms_use_details.mms_umms_app_slide)
    {
        --count;
        switch (g_current_mms_info_list->umms_use_details.applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                while((count < index)&&(parse_list < (UMMS_BCC_LIST + 1)))
                {
                    switch (parse_list)
                    {
                        case UMMS_FROM:    node2 = g_current_mms_info_list->umms_mms_xml_msg->from;
                                           if(node2 != NULL) 
                                           {
                                               if(MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                               {
                                                   count++;
                                               }
                                           }
                                           parse_list++;
                                           break;
                        case UMMS_TO_LIST: node2 = g_current_mms_info_list->umms_mms_xml_msg->to_head;
                                           while((node2 != NULL)&&(count < index))
                                           {
                                               if(MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                               {
                                                   count++;
                                               }
                                               if(count < index)
                                               {
                                                   node2 = node2->next;
                                               }
                                           }
                                           parse_list++;
                                           break;
                        case UMMS_CC_LIST: node2 = g_current_mms_info_list->umms_mms_xml_msg->cc_head;
                                           while((node2 != NULL)&&(count < index))
                                           {
                                              if(MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                              {
                                                  count++;
                                              }
                                              if(count < index)
                                              {
                                                  node2 = node2->next;
                                              }
                                           }
                                           parse_list++;
                                           break;
                        case UMMS_BCC_LIST:node2 = g_current_mms_info_list->umms_mms_xml_msg->bcc_head;
                                           while((node2 != NULL)&&(count < index))
                                           {
                                               if(MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                               {
                                                   count++;
    }
                                               if(count < index)
                                               {
                                                   node2 = node2->next;
                                               }
                                           }
                                           parse_list++;
                                           break;
                        default:   break;
                    }
                }
                len = strlen((S8*)(node2->addr));
                g_current_mms_info_list->addr = (U16*)umms_malloc((len+1)*ENCODING_LENGTH);
                MMI_ASSERT(g_current_mms_info_list->addr);
                memset(g_current_mms_info_list->addr,0,(len+1)*ENCODING_LENGTH);
                mmi_asc_n_to_ucs2((S8*) g_current_mms_info_list->addr, (S8*) node2->addr, len);
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                while((count < index)&&(parse_list < 4))
                {
                    switch (parse_list)
                    {
                        case UMMS_FROM:     node2 = g_current_mms_info_list->umms_mms_xml_msg->from;
                                            if(node2 != NULL)
                                            {
                                                if(MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                                {
                                                    count++;
                                                }
                                            }
                                            parse_list++;
                                            break;
                        case UMMS_TO_LIST:  node2 = g_current_mms_info_list->umms_mms_xml_msg->to_head;
                                            while((node2 != NULL)&&(count < index))
                                            {
                                                if(MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                                {
                                                    count++;
                                                }
                                                if(count < index)
                                                {
                                                    node2 = node2->next;
                                                }
                                            }
                                            parse_list++;
                                            break;
                        case UMMS_CC_LIST:  node2 = g_current_mms_info_list->umms_mms_xml_msg->cc_head;
                                            while((node2 != NULL)&&(count < index))
                                            {
                                                if(MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                                {
                                                    count++;
                                                }
                                                if(count < index)
    {
                                                    node2 = node2->next;
                                                }
    }
                                            parse_list++;
                                            break;
                        case UMMS_BCC_LIST: node2 = g_current_mms_info_list->umms_mms_xml_msg->bcc_head;
                                            while((node2 != NULL)&&(count < index))
                                            {
                                                if(MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
    {
        count++;
    }
                                                if(count < index)
    {
                                                    node2 = node2->next;
                                                }
    }
                                            parse_list++;
                                            break;

                        default:            break;
                    }
                }
                
                len = mmi_ucs2strlen((S8*)(node2->addr));
                g_current_mms_info_list->addr = (U16*)umms_malloc((len+1)*ENCODING_LENGTH);
                MMI_ASSERT(g_current_mms_info_list->addr);
                memset(g_current_mms_info_list->addr,0,(len+1)*ENCODING_LENGTH);
                mmi_ucs2ncpy((S8*) g_current_mms_info_list->addr, (S8*) node2->addr, len);
                 break;
            default:
                MMI_ASSERT(0);
                break;
        }
     
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_details_call
 * DESCRIPTION
 *  Function to call a number from use details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_details_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_get_addr_content_by_index(g_current_mms_info_list->hilite_index);
    MakeCall((S8*) (g_current_mms_info_list->addr));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_use_details_addresses_options
 * DESCRIPTION
 *  Entry fn for options for use number or use email or use url addresses list
 *  screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_details_addresses_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;                     /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */

    U16 scrid;
    U16 menuid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_get_addr_content_by_index(g_current_mms_info_list->hilite_index);
    scrid = SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS;

    if (APPLIB_ADDR_TYPE_PHONENUMBER == g_current_mms_info_list->umms_use_details.applib_addr_type)
    {
        menuid = MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_NUMBER;
    }
    else if (APPLIB_ADDR_TYPE_EMAIL == g_current_mms_info_list->umms_use_details.applib_addr_type)
    {
        menuid = MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_EMAIL;
    }
    else if (APPLIB_ADDR_TYPE_URL == g_current_mms_info_list->umms_use_details.applib_addr_type)
    {
        menuid = MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_URL;
    }
    else
    {
        MMI_ASSERT(0);
        return;
    }

    EntryNewScreen(scrid, NULL, mmi_umms_entry_use_details_addresses_options, NULL);

    gui_buffer = GetCurrGuiBuffer(scrid);

    num_item = GetNumOfChild(menuid);
    GetSequenceStringIds(menuid, str_item_list);

    SetParentHandler(menuid);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        (U8 **) NULL,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_use_call_details
 * DESCRIPTION
 *  To show the user confirmation screen for calling a number from use details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_call_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 tempstr[(MMA_MAX_ADDR_LEN + 6) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempstr, 0, sizeof(tempstr));
    mmi_ucs2cpy((S8*) tempstr, (S8*) get_string(STR_GLOBAL_DIAL));
    mmi_ucs2cat((S8*) tempstr, " ");
  
   
    mmi_ucs2ncat((S8*) tempstr, (S8*) (g_current_mms_info_list->addr), MMA_MAX_ADDR_LEN);

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) tempstr,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_use_details_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_use_save_to_phbook
 * DESCRIPTION
 *  To save a number to phonebook from use details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_save_to_phbook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
 
    SaveNumberFromIdleScrn((S8*) (g_current_mms_info_list->addr), 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_use_email_add_to_contact
 * DESCRIPTION
 *  To save an email to contact book from use details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_email_add_to_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_email_save_entry_to_phb_from_jmms((S8*) (g_current_mms_info_list->addr));
}

#ifdef __MMI_EMAIL__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_email_send_email
 * DESCRIPTION
 *  To send an email to selected email address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_email_send_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    switch (g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            scrid = SCR_ID_UM_INBOX;
            break;
        case MMA_FOLDER_OUTBOX:
            scrid = SCR_ID_UM_UNSENT;
            break;
        case MMA_FOLDER_SENT:
            scrid = SCR_ID_UM_SENT;
            break;
        case MMA_FOLDER_DRAFT:
            scrid = SCR_ID_UM_DRAFT;
            break;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            scrid = SCR_ID_UM_ARCHIVE;
            break;
#endif
		case MMA_FOLDER_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES;
			break;
		case MMA_FOLDER_USRDEF_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED;
			break;
        default:
            break;
    }
     EntryNewScreen(SCR_ID_UMMS_DUMMY, NULL, NULL, NULL);
        mmi_email_app_send_to((S8*) g_current_mms_info_list->addr);
     DeleteFromScrUptoScr(SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS,scrid);
     mmi_umms_reset_global();
    
   }
#endif /* __MMI_EMAIL__ */ 

#ifdef __UNIFIED_COMPOSER_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_details_send_mms
 * DESCRIPTION
 *  To send an MMS to selected email address or phone number in use details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_details_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    	U16 scrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
      switch (g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            scrid = SCR_ID_UM_INBOX;
            break;
        case MMA_FOLDER_OUTBOX:
            scrid = SCR_ID_UM_UNSENT;
            break;
        case MMA_FOLDER_SENT:
            scrid = SCR_ID_UM_SENT;
            break;
        case MMA_FOLDER_DRAFT:
            scrid = SCR_ID_UM_DRAFT;
            break;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            scrid = SCR_ID_UM_ARCHIVE;
            break;
#endif
		case MMA_FOLDER_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES;
			break;
		case MMA_FOLDER_USRDEF_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED;
			break;
        default:
            break;
    }
    
    
    mms_address_insert_hdlr((S8*) (g_current_mms_info_list->addr));
   DeleteFromScrUptoScr(SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS,scrid);
    mmi_umms_reset_global();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_details_send_sms
 * DESCRIPTION
 *  To send an SMS to selected email address or phone number in use details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_details_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	U16 scrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
       switch (g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            scrid = SCR_ID_UM_INBOX;
            break;
        case MMA_FOLDER_OUTBOX:
            scrid = SCR_ID_UM_UNSENT;
            break;
        case MMA_FOLDER_SENT:
            scrid = SCR_ID_UM_SENT;
            break;
        case MMA_FOLDER_DRAFT:
            scrid = SCR_ID_UM_DRAFT;
            break;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            scrid = SCR_ID_UM_ARCHIVE;
            break;
#endif
		case MMA_FOLDER_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES;
			break;
		case MMA_FOLDER_USRDEF_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED;
			break;
        default:
            break;
    }

   
    mmi_umms_use_details_address_insert_hdlr((U8*) (g_current_mms_info_list->addr));
    DeleteFromScrUptoScr(SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS,scrid);
    mmi_umms_reset_global();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_details_address_insert_hdlr
 * DESCRIPTION
 *  Open editor for sending SMS with address inserted
 * PARAMETERS
 *  address     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_details_address_insert_hdlr(U8 *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_entry_write_struct data;
    mmi_uc_addr_struct addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
    memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));
    data.addr_num = 1;
    addr.addr = (kal_uint8*) address;
    /* if (strchr(address, '@') == NULL) */
    {
        addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
    }
    /* else
       {
       addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
       } */
    addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
    data.addr = &addr;
    data.msg_type = MMI_UC_MSG_TYPE_SMS_ONLY;
    data.info_type = MMI_UC_INFO_TYPE_SMS;
    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
    return;
}
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_use_url_go_to
 * DESCRIPTION
 *  To browse a url from use details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_url_go_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrid = 0;
    U8 tempstr[MMI_UMMS_MAX_URL_LENGTH + 1];
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            scrid = SCR_ID_UM_INBOX;
            break;
        case MMA_FOLDER_OUTBOX:
            scrid = SCR_ID_UM_UNSENT;
            break;
        case MMA_FOLDER_SENT:
            scrid = SCR_ID_UM_SENT;
            break;
        case MMA_FOLDER_DRAFT:
            scrid = SCR_ID_UM_DRAFT;
            break;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            scrid = SCR_ID_UM_ARCHIVE;
            break;
#endif
		case MMA_FOLDER_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES;
			break;
		case MMA_FOLDER_USRDEF_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED;
			break;
        default:
            break;
    }

    len = mmi_ucs2strlen((S8*) (g_current_mms_info_list->addr));
    if (len > MMI_UMMS_MAX_URL_LENGTH)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_UMMS_URL_TOO_LONG),
            IMG_GLOBAL_ERROR,
            FALSE,
            MMI_UMMS_POPUP_TIME,
            ERROR_TONE);
        DeleteUptoScrID(scrid);
        mmi_umms_reset_global();
        return;
    }
    mmi_ucs2_to_asc((S8*) tempstr, (S8*) (g_current_mms_info_list->addr));
    EntryNewScreen(SCR_ID_UMMS_DUMMY, NULL, NULL, NULL);
    DeleteUptoScrID(scrid);
    mmi_umms_reset_global();
	mmi_brw_load_url(tempstr);
    
}

#ifdef __MMI_VBOOKMARK__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_use_url_save_bookmark
 * DESCRIPTION
 *  To save url as bookmark from use datails
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_url_save_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U16 scrid = 0;
    /*U8 tempstr[(MMI_UMMS_MAX_URL_LENGTH + 1)*ENCODING_LENGTH];*/
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            scrid = SCR_ID_UM_INBOX;
            break;
        case MMA_FOLDER_OUTBOX:
            scrid = SCR_ID_UM_UNSENT;
            break;
        case MMA_FOLDER_SENT:
            scrid = SCR_ID_UM_SENT;
            break;
        case MMA_FOLDER_DRAFT:
            scrid = SCR_ID_UM_DRAFT;
            break;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            scrid = SCR_ID_UM_ARCHIVE;
            break;
#endif
		case MMA_FOLDER_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES;
			break;
		case MMA_FOLDER_USRDEF_TEMPLATE:
			scrid = SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED;
			break;
        default:
            break;
    }
    len = mmi_ucs2strlen((S8*) (g_current_mms_info_list->addr));
    if (len > MMI_UMMS_MAX_URL_LENGTH)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_UMMS_URL_TOO_LONG),
            IMG_GLOBAL_ERROR,
            FALSE,
            MMI_UMMS_POPUP_TIME,
            ERROR_TONE);
        /*DeleteUptoScrID(scrid);*/
        return;
    }
    /*memset(tempstr, 0, (MMI_UMMS_MAX_URL_LENGTH + 1)*ENCODING_LENGTH);
    mmi_ucs2ncpy((S8*) tempstr, (S8*) (g_current_mms_info_list->addr),MMI_UMMS_MAX_URL_LENGTH);*/
    wap_start_browser(WAP_BROWSER_ADD_BOOKMARK,(U8*)g_current_mms_info_list->addr);
    /*wap_start_browser(kal_uint8 option, const kal_uint8 *url)*/
    /*add_book_mark_result = mmi_brw_add_to_bookmark(NULL, tempstr);
    mmi_umms_show_book_mark_add_result(add_book_mark_result);*/
    
}
#endif /* __MMI_VBOOKMARK__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_details_set_app_slide
 * DESCRIPTION
 *  Set use details request type
 * PARAMETERS
 *  app_slide       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_details_set_app_slide(mmi_mv_get_use_details_enum const app_slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->umms_use_details.mms_umms_app_slide = (mmi_mv_get_use_details_enum) app_slide;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_details_set_addr_type
 * DESCRIPTION
 *  Set Address type
 * PARAMETERS
 *  addr_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_details_set_addr_type(const U8 addr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->umms_use_details.applib_addr_type = (U8) addr_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_lock_mode
 * DESCRIPTION
 *  Entry function to the Lock Mode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_lock_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MMI_UMMS_NUM_OPTIONS_LOCK_MODE];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;                                     /* Stores no of children in the submenu */
    U16 index;
    U8 *guiBuffer;                                      /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_entry_lock_mode MSgId=%d \n",
                         g_current_mms_info_list->current_msg_id);
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_OPTION_LOCK, NULL, mmi_umms_entry_lock_mode, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_OPTION_LOCK);

    nNumofItem = GetNumOfChild(MENU_ID_UMMS_OPTIONS_LOCK_MODE);

    GetSequenceStringIds(MENU_ID_UMMS_OPTIONS_LOCK_MODE, nStrItemList);

    SetParentHandler(MENU_ID_UMMS_OPTIONS_LOCK_MODE);

    RegisterHighlightHandler(mmi_umms_lock_mode_highlight_hdlr);

    if (MMI_UMMS_LOCK_MODE_ON == g_current_mms_info_list->app_data[0])
    {
        index = 0;
    }
    else
    {
        index = 1;
    }

    ShowCategory11Screen(
        STR_ID_UMMS_LOCK_MODE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16) index,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_umms_send_lock_mode_req, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_lock_mode_req
 * DESCRIPTION
 *  Send req to set the lock mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_lock_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_app_data_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_send_lock_mode_req MSgId=%d \n",
                         g_current_mms_info_list->current_msg_id);

    req = (wap_mma_set_app_data_req_struct*) OslConstructDataPtr(sizeof(wap_mma_set_app_data_req_struct));

    req->req_id = wap_mma_get_request_id();

    req->app_id = MMA_APP_ID_MMS_APP;
    req->msg_id = g_current_mms_info_list->current_msg_id;
    if ((0 == g_current_mms_info_list->hilite_index) &&
        (MMI_UMMS_LOCK_MODE_ON == g_current_mms_info_list->app_data[0]) ||
        (1 == g_current_mms_info_list->hilite_index) && (g_current_mms_info_list->app_data[0] != MMI_UMMS_LOCK_MODE_ON))
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, MMI_UMMS_POPUP_TIME, SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_UM_INBOX);
        /* GoBackHistory(); */
        return;
    }
    else if (0 == g_current_mms_info_list->hilite_index)
    {
        req->app_data[0] = MMI_UMMS_LOCK_MODE_ON;
    }
    else if (1 == g_current_mms_info_list->hilite_index)
    {
        req->app_data[0] = MMI_UMMS_LOCK_MODE_OFF;
    }
    else
    {
        MMI_ASSERT(0);
        return;
    }
    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_PLEASE_WAIT;
    mmi_umms_progress_screen();

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SET_APP_DATA_REQ, (oslParaType*) req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_lock_mode_rsp
 * DESCRIPTION
 *  Handles response of the lock mode request
 * PARAMETERS
 *  inmsg       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_lock_mode_rsp(void *inmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_app_data_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wap_mma_set_app_data_rsp_struct*) inmsg;

    if (GetActiveScreenId() != SCR_ID_UMMS_PROGRESS)
    {
        if (mmi_umms_is_usb_mode())
        {
            return;
        }
        else if (MMA_RESULT_OK == rsp->result)
        {
            DeleteBetweenScreen(SCR_ID_UM_INBOX, SCR_ID_UMMS_PROGRESS);
            return;
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
            return;
        }
    }

    if (MMA_RESULT_OK == rsp->result)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, MMI_UMMS_POPUP_TIME, SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_UM_INBOX);
    }
    else
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, TRUE, MMI_UMMS_POPUP_TIME, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    }
}

/* Ashwani Ends */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_forward
 * DESCRIPTION
 *  Entry Function for Forward MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_entry_forward MSgId=%d \n",
                         g_current_mms_info_list->current_msg_id);
    if (g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE)
    {
        if (mmi_umms_is_creation_mode_restricted())
        {
            g_current_mms_info_list->uc_mode = MMA_MODE_FORWARD;
            mmi_umms_show_content_mode_confrm_pop_up();
        }
        else
        {
            mmi_umms_start_uc_req(g_current_mms_info_list->current_msg_id, MMA_MODE_FORWARD);
        }
    }
    else
    {
		mmi_umms_start_uc_req(g_current_mms_info_list->current_msg_id, MMA_MODE_FORWARD);        
    }
}


#ifdef __CMCC_FWD_EDIT_CLUBBED__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_fwd_edit_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_fwd_edit_scr(void)
{   
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS] = {0, };
    U8 *guiBuffer = NULL;
    U16 nNumofItem = 0;
    U16 parentid = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    EntryNewScreen(SCR_ID_UMMS_FWD_EDIT_CLUBBED, NULL, mmi_umms_entry_fwd_edit_scr, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_FWD_EDIT_CLUBBED);
    switch(g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            parentid = MENU_ID_UMMS_INBOX_OPTIONS_FORWARD;
            break;
        case MMA_FOLDER_DRAFT:
            parentid = MENU_ID_UMMS_DRAFT_OPTIONS_FORWARD;
            break;
        case MMA_FOLDER_SENT:
            parentid = MENU_ID_UMMS_SENT_OPTIONS_FORWARD;
            break;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            parentid = MENU_ID_UMMS_ARCHIVE_OPTIONS_FORWARD;
            break;
#endif
        default :
            MMI_ASSERT(0);
            break;
    }
    nNumofItem = GetNumOfChild(parentid);
    GetSequenceStringIds(MENU_ID_UMMS_OPTIONS_LOCK_MODE, nStrItemList);
    GetSequenceStringIds(parentid, nStrItemList);
    SetParentHandler(parentid);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_UMMS_FWD_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
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
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_move_to_drafts
 * DESCRIPTION
 *  Entry Function for Move to Drafts.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_move_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_entry_move_to_drafts MSgId=%d \n",
                         g_current_mms_info_list->current_msg_id);
    
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) GetString(STR_ID_UMMS_OPTIONS_MOVE_TO_DRAFTS),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_move_to_drafts_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_move_to_drafts_confirm
 * DESCRIPTION
 *  Entry Function for Move to Drafts.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_move_to_drafts_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_PLEASE_WAIT;

    mmi_umms_progress_screen();
    mmi_umms_save_req(
        E_STATE_NONE,
        E_STATE_MOVE_MSG,
        g_current_mms_info_list->current_msg_id,
        MMA_FOLDER_DRAFT,
        g_current_mms_info_list->folder_id);
}


/*****************************************************************************
 * FUNCTION
 *  umms_add_to_msg_hndlr_list
 * DESCRIPTION
 *  Link list prepared for Normal Command
 *  Normal Message - For situation like opening MMS and new message ind comes
 * PARAMETERS
 *  msg_id              [IN]        
 *  req_id              [IN]        
 *  current_state       [IN]        
 *  current_folder(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void umms_add_to_msg_hndlr_list(const U32 msg_id, const U32 req_id, const umms_state_enum current_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_req_msg_handler_struct *msg_hndlr = NULL;
    umms_req_msg_handler_struct *temp_node = NULL;

    /* umms_req_msg_handler_struct *start = NULL; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] umms_add_to_msg_hndlr_list MSgId=%d req_id=%d Current State= %d \n",
                         msg_id, req_id, current_state);
    msg_hndlr = (umms_req_msg_handler_struct*) umms_malloc(sizeof(umms_req_msg_handler_struct));
    MMI_ASSERT(msg_hndlr);
    memset(msg_hndlr,0,sizeof(umms_req_msg_handler_struct));
    msg_hndlr->msg_id = msg_id;
    msg_hndlr->req_id = req_id;
    msg_hndlr->current_state = current_state;
    msg_hndlr->current_folder = g_current_mms_info_list->folder_id;
    msg_hndlr->next = NULL;

    temp_node = g_current_mms_info_list->g_umms_req_msg_hndlr;

    if (g_current_mms_info_list->g_umms_req_msg_hndlr == NULL)
    {
        g_current_mms_info_list->g_umms_req_msg_hndlr = msg_hndlr;
    }
    else
    {
        while (temp_node->next != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] umms_add_to_msg_hndlr_list MSgId in Req Handler=%d Current State = %d\n",
                                 temp_node->msg_id, temp_node->current_state);

            temp_node = temp_node->next;
        }
        temp_node->next = msg_hndlr;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_current_state
 * DESCRIPTION
 *  Get the current state from the Norraml List.
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_current_state(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_req_msg_handler_struct *msg_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_current_state MSgId=%d req_id=%d \n", msg_id, req_id);

    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;

    while (msg_hndlr != NULL)
    {
        if ((msg_hndlr->msg_id == msg_id) && (msg_hndlr->req_id == req_id))
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_current_state Current State=%d \n",
                                 msg_hndlr->current_state);

            return msg_hndlr->current_state;
        }
        else
        {
            msg_hndlr = msg_hndlr->next;
        }
    }
    return E_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_folder_id_from_all_msg_handler
 * DESCRIPTION
 *  Get Folder ID from all the List.(Normal and Send)
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_folder_enum mmi_umms_get_folder_id_from_all_msg_handler(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_req_msg_handler_struct *msg_hndlr = NULL;
    umms_send_msg_handler_struct *send_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;
    while (msg_hndlr != NULL)
    {
        if ((msg_hndlr->msg_id == msg_id) && (msg_hndlr->req_id == req_id))
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_folder_id_from_all_msg_handler Current Folder in Req handler=%d Msg_id = %d Req_id =%d \n",
                                 msg_hndlr->current_folder, msg_id, req_id);
            return msg_hndlr->current_folder;
        }
        else
        {
            msg_hndlr = msg_hndlr->next;
        }
    }

    send_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_hndlr != NULL)
    {
        if ((send_hndlr->msg_id == msg_id) && (send_hndlr->req_id == req_id))
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_folder_id_from_all_msg_handler Current Folder in Send handler=%d Msg_id = %d Req_id = %d\n",
                                 send_hndlr->current_folder, msg_id, req_id);
            return send_hndlr->current_folder;
        }
        else
        {
            send_hndlr = send_hndlr->next;
        }

    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_state_of_msg_from_all_the_lists
 * DESCRIPTION
 *  Get State of the MMS from all the list.
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_state_of_msg_from_all_the_lists(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_req_msg_handler_struct *msg_hndlr = NULL;
    umms_send_msg_handler_struct *send_msg_handlr = NULL;
    umms_download_msg_handler_struct *download_msg_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_all_the_lists  Msg_id = %d Req_id = %d\n",
                         msg_id, req_id);

    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    download_msg_hndlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    if (msg_hndlr != NULL)
    {
        while (msg_hndlr != NULL)
        {
            if ((msg_hndlr->msg_id == msg_id) && (msg_hndlr->req_id == req_id))
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_all_the_lists Current State in Req handler=%d \n",
                                     msg_hndlr->current_state);
                return msg_hndlr->current_state;
            }
            else
            {
                msg_hndlr = msg_hndlr->next;
            }
        }

    }

    if (send_msg_handlr != NULL)
    {
        while (send_msg_handlr != NULL)
        {
            if ((send_msg_handlr->msg_id == msg_id))
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_all_the_lists Current State in Send handler=%d \n",
                                     send_msg_handlr->current_state);

                return send_msg_handlr->current_state;
            }
            else
            {
                send_msg_handlr = send_msg_handlr->next;
            }
        }

    }

    if (download_msg_hndlr != NULL)
    {
        while (download_msg_hndlr != NULL)
        {
            if ((download_msg_hndlr->msg_id == msg_id) && (download_msg_hndlr->req_id == req_id))
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_all_the_lists Current State in Download handler=%d \n",
                                     download_msg_hndlr->current_state);
                return download_msg_hndlr->current_state;
            }
            else
            {
                download_msg_hndlr = download_msg_hndlr->next;
            }
        }
    }

    return E_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  umms_add_to_download_msg_hndlr_list
 * DESCRIPTION
 *  Add node to the Downlaod Message Handler List.
 * PARAMETERS
 *  msg_id              [IN]        
 *  req_id              [IN]        
 *  current_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void umms_add_to_download_msg_hndlr_list(const U32 msg_id, const U32 req_id, const umms_state_enum current_state, const umms_state_enum intermediate_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *msg_hndlr = NULL;
    umms_download_msg_handler_struct *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] umms_add_to_download_msg_hndlr_list Msg_id = %d Req_id =%d Curnt State = %d\n",
                         msg_id, req_id, current_state);
    msg_hndlr = (umms_download_msg_handler_struct*) umms_malloc(sizeof(umms_download_msg_handler_struct));
    MMI_ASSERT(msg_hndlr);
    memset(msg_hndlr,0,sizeof(umms_download_msg_handler_struct));
    msg_hndlr->msg_id = msg_id;
    msg_hndlr->req_id = req_id;
    msg_hndlr->current_state = current_state;
    msg_hndlr->intermediate_state =  intermediate_state;
    msg_hndlr->next = NULL;

    temp_node = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;

    if (g_dwnld_send_list->g_umms_dwnld_msg_hndlr == NULL)
    {
        g_dwnld_send_list->g_umms_dwnld_msg_hndlr = msg_hndlr;
    }
    else
    {
        while (temp_node->next != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] umms_add_to_download_msg_hndlr_list Print List Msg_id = %d Req_id =%d Curnt State = %d\n",
                                 temp_node->msg_id, temp_node->req_id, temp_node->current_state);
            temp_node = temp_node->next;
        }
        temp_node->next = msg_hndlr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_add_to_new_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_add_to_new_msg_list(U32 msg_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_new_mms_list *new_msg_hndlr = NULL;
    mmi_umms_new_mms_list *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_add_to_new_msg_list Msg_id = %d \n", msg_id);
    new_msg_hndlr = (mmi_umms_new_mms_list*) umms_malloc(sizeof(mmi_umms_new_mms_list));
    MMI_ASSERT(new_msg_hndlr);
    memset(new_msg_hndlr,0,sizeof(mmi_umms_new_mms_list));
    new_msg_hndlr->msg_id = msg_id;
    new_msg_hndlr->next = NULL;
    temp_node = g_new_mms_list;

    if (g_new_mms_list == NULL)
    {
        g_new_mms_list = new_msg_hndlr;
    }
    else
    {
        while (temp_node->next != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_add_to_new_msg_list Print List Msg_id = %d \n",
                                 temp_node->msg_id);
            temp_node = temp_node->next;
        }
        temp_node->next = new_msg_hndlr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_free_new_msg_handler_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_free_new_msg_handler_list(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_new_mms_list *temp_node_send = NULL;
    mmi_umms_new_mms_list *new_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_free_new_msg_handler_list Msg_id = %d \n", msg_id);

    new_msg_handlr = g_new_mms_list;
    if (new_msg_handlr != NULL)
    {
        while (new_msg_handlr != NULL)
        {

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_free_new_msg_handler_list Print List Msg_id = %d \n",
                                 new_msg_handlr->msg_id);
            new_msg_handlr = new_msg_handlr->next;
        }
    }

    new_msg_handlr = g_new_mms_list;
    if (new_msg_handlr != NULL)
    {
        if (new_msg_handlr->msg_id == msg_id)
        {
            if (new_msg_handlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_new_mms_list);
                g_new_mms_list = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_new_mms_list = new_msg_handlr->next;
                umms_free(new_msg_handlr);
                new_msg_handlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node_send = new_msg_handlr;
            new_msg_handlr = new_msg_handlr->next;
            while (new_msg_handlr != NULL)
            {
                if (new_msg_handlr->msg_id == msg_id)
                {
                    break;
                }
                else
                {
                    new_msg_handlr = new_msg_handlr->next;
                    temp_node_send = temp_node_send->next;
                }
            }
            if (new_msg_handlr != NULL)
            {
                if (new_msg_handlr->msg_id == msg_id)
                {
                    if (new_msg_handlr->next != NULL)
                    {   /* In between Nodes to be deleted */
                        temp_node_send->next = new_msg_handlr->next;
                        umms_free(new_msg_handlr);
                        new_msg_handlr = NULL;
                    }
                    else
                    {
                        /* The last node is to be deleted. */
                        temp_node_send->next = NULL;
                        umms_free(new_msg_handlr);
                        new_msg_handlr = NULL;
                    }
                }
            }
            else
            {
                /* The Msg id and the Req Id combination doesnot exist in the List */
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_in_download_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_is_in_download_list(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *dwnld_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_is_in_download_list Msg_id = %d \n", msg_id);
    dwnld_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (dwnld_msg_handlr != NULL)
    {
        if (dwnld_msg_handlr->msg_id == msg_id)
        {
            return MMI_TRUE;
        }
        dwnld_msg_handlr = dwnld_msg_handlr->next;
    }
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  umms_add_to_send_msg_hndlr_list
 * DESCRIPTION
 *  Add node to the Send Message HAndler List.
 * PARAMETERS
 *  msg_id                  [IN]        
 *  req_id                  [IN]        
 *  current_state           [IN]        
 *  intermediate_state      [IN]        
 *  folder_id               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void umms_add_to_send_msg_hndlr_list(
        const U32 msg_id,
        const U32 req_id,
        const umms_state_enum current_state,
        const umms_state_enum intermediate_state,
        const mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *msg_hndlr = NULL;
    umms_send_msg_handler_struct *temp_node = NULL;
    mmi_enum_retry_send_verion_enum mms_version = UMMS_SEND_VERSION_NONE;
    U8 is_send_and_save = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] umms_add_to_send_msg_hndlr_list Msg_id = %d Req_id= %d Currt State =%d Inter State = %d Folder_id = %d\n",
                         msg_id, req_id, current_state, intermediate_state, folder_id);
    msg_hndlr = (umms_send_msg_handler_struct*) umms_malloc(sizeof(umms_send_msg_handler_struct));
    MMI_ASSERT(msg_hndlr);
    memset(msg_hndlr,0,sizeof(umms_send_msg_handler_struct));
    msg_hndlr->msg_id = msg_id;
    msg_hndlr->req_id = req_id;
    msg_hndlr->current_state = current_state;
    msg_hndlr->intermediate_state = intermediate_state;
    mms_version = mmi_umms_get_global_mms_version();
    msg_hndlr->retry_version = mms_version;
    msg_hndlr->retry_version_count = 1;
    msg_hndlr->current_folder = folder_id;
    is_send_and_save = mmi_umms_sending_settings_send_and_save();
    if (is_send_and_save > 0)
    {
        msg_hndlr->is_send_save = TRUE;
    }
    else
    {
        msg_hndlr->is_send_save = FALSE;
    }

    mmi_ucs2ncpy((PS8) msg_hndlr->to_address, (PS8) g_current_mms_info_list->to_address, MMA_MAX_ADDR_LEN);
    msg_hndlr->next = NULL;

    temp_node = g_dwnld_send_list->g_umms_send_msg_hndlr;
    if (g_dwnld_send_list->g_umms_send_msg_hndlr == NULL)
    {
        g_dwnld_send_list->g_umms_send_msg_hndlr = msg_hndlr;
    }
    else
    {
        while (temp_node->next != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] umms_add_to_send_msg_hndlr_list Print List Msg_id = %d Req_id= %d Currt State =%d Inter State = %d Folder_id = %d\n",
                                 temp_node->msg_id, temp_node->req_id, temp_node->current_state,
                                 temp_node->intermediate_state, temp_node->current_folder);
            temp_node = temp_node->next;
        }
        temp_node->next = msg_hndlr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_intermediate_send_cancel_req
 * DESCRIPTION
 *  Update the state in case of Cancel Send req.
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_intermediate_send_cancel_req(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {

            send_msg_handlr->req_id = req_id;
            send_msg_handlr->intermediate_state = E_STATE_CANCEL_SEND_MSG;
            break;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_intermediate_send_req
 * DESCRIPTION
 *  Update State in case of Actaul Send Req.
 * PARAMETERS
 *  msg_id                  [IN]        
 *  req_id                  [IN]        
 *  intermediate_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_intermediate_send_req(const U32 msg_id, const U32 req_id, const umms_state_enum intermediate_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_intermediate_send_req Msg_id = %d Req_id = %d Intr State = %d\n",
                         msg_id, req_id, intermediate_state);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            send_msg_handlr->req_id = req_id;
            send_msg_handlr->intermediate_state = intermediate_state;
            break;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_send_hdnlr_with_new_msg_id
 * DESCRIPTION
 *  Updation of the node in the Send List after creation of new MMS in case of Send
 *  failure for Version Mismatch.
 * PARAMETERS
 *  msg_id                  [IN]        
 *  req_id                  [IN]        
 *  intermediate_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_send_hdnlr_with_new_msg_id(
        const U32 msg_id,
        const U32 req_id,
        const umms_state_enum intermediate_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_send_hdnlr_with_new_msg_id Msg_id = %d Req_id = %d Intr State = %d\n",
                         msg_id, req_id, intermediate_state);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->req_id == req_id)
        {
            send_msg_handlr->req_id = req_id;
            send_msg_handlr->old_msg_id = send_msg_handlr->msg_id;
            send_msg_handlr->msg_id = msg_id;
            send_msg_handlr->intermediate_state = intermediate_state;
            break;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_old_msg_id_from_send_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_get_old_msg_id_from_send_handler(U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_old_msg_id_from_send_handler Req_id = %d \n", req_id);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->req_id == req_id)
        {
            return send_msg_handlr->old_msg_id;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_retry_send_req
 * DESCRIPTION
 *  Update send List in case of Retry.
 * PARAMETERS
 *  msg_id                  [IN]        
 *  req_id                  [IN]        
 *  new_req_id              [IN]        
 *  intermediate_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_retry_send_req(
        const U32 msg_id,
        const U32 req_id,
        const U32 new_req_id,
        const umms_state_enum intermediate_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_old_msg_id_from_send_handler Old_Req_id = %d New_req_id = %d intr State = %d\n",
                         req_id, new_req_id, intermediate_state);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (intermediate_state == E_STATE_GET_CONTENT_MSG)
        {
            if (send_msg_handlr->msg_id == msg_id)
            {
                send_msg_handlr->req_id = req_id;
                send_msg_handlr->msg_id = msg_id;
                send_msg_handlr->intermediate_state = intermediate_state;
                break;
            }
            else
            {
                send_msg_handlr = send_msg_handlr->next;
            }
        }
        else
        {
            if (send_msg_handlr->req_id == req_id)
            {
                send_msg_handlr->req_id = new_req_id;
                send_msg_handlr->msg_id = 0;
                send_msg_handlr->intermediate_state = intermediate_state;
                break;
            }
            else
            {
                send_msg_handlr = send_msg_handlr->next;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_intermediate_state_of_msg_from_send_list
 * DESCRIPTION
 *  Get the Intermediate State of MMS from Send List.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_intermediate_state_of_msg_from_send_list(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for Printing all the messge in Send Handler */
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_msg_handlr != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSAppMain.c] mmi_umms_get_intermediate_state_of_msg_from_send_list Print List Msg_id = %d Req_id = %d Send counter = %d Old Message_id = %d retry_version Count = %d current_state = %d intr State = %d current_folder = %d retry_version = %d\n",
                             send_msg_handlr->msg_id, send_msg_handlr->req_id, send_msg_handlr->send_counter,
                             send_msg_handlr->old_msg_id, send_msg_handlr->retry_version_count,
                             send_msg_handlr->current_state, send_msg_handlr->intermediate_state,
                             send_msg_handlr->current_folder, send_msg_handlr->retry_version);
        send_msg_handlr = send_msg_handlr->next;
    }

    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_intermediate_state_of_msg_from_send_list Msg_id = %d intr State = %d \n",
                                 send_msg_handlr->msg_id, send_msg_handlr->intermediate_state);
            return send_msg_handlr->intermediate_state;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return E_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_state_of_msg_from_send_list
 * DESCRIPTION
 *  Get Currwent State of MMS from Send List.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_state_of_msg_from_send_list(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_send_list Print List Msg_id = %d Req_id = %d Send counter = %d Old Message_id = %d retry_version Count = %d current_state = %d intr State = %d current_folder = %d retry_version = %d\n",
                             send_msg_handlr->msg_id, send_msg_handlr->req_id, send_msg_handlr->send_counter,
                             send_msg_handlr->old_msg_id, send_msg_handlr->retry_version_count,
                             send_msg_handlr->current_state, send_msg_handlr->intermediate_state,
                             send_msg_handlr->current_folder, send_msg_handlr->retry_version);
        send_msg_handlr = send_msg_handlr->next;
    }
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_send_list Msg_id = %d Current State = %d \n",
                                 send_msg_handlr->msg_id, send_msg_handlr->current_state);
            return send_msg_handlr->current_state;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return E_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_state_of_msg_from_download_list
 * DESCRIPTION
 *  Get Current State of MMS from Download List
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_state_of_msg_from_download_list(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *dwnld_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dwnld_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (dwnld_msg_handlr != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_download_list Print List Msg_id = %d Req_id = %d Retry_counter= %d current_state = %d \n",
                             dwnld_msg_handlr->msg_id, dwnld_msg_handlr->req_id, dwnld_msg_handlr->retry_counter,
                             dwnld_msg_handlr->current_state);
        dwnld_msg_handlr = dwnld_msg_handlr->next;
    }
    dwnld_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (dwnld_msg_handlr != NULL)
    {
        if (dwnld_msg_handlr->msg_id == msg_id)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_download_list Msg_id = %d Current State = %d \n",
                                 dwnld_msg_handlr->msg_id, dwnld_msg_handlr->current_state);
            return dwnld_msg_handlr->current_state;
        }
        else
        {
            dwnld_msg_handlr = dwnld_msg_handlr->next;
        }
    }
    return E_STATE_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_intermediate_state_from_downl_list
 * DESCRIPTION
 *  Get Intermediate State of MMS from Download List
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_intermediate_state_from_downl_list(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *dwnld_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dwnld_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (dwnld_msg_handlr != NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_download_list Print List Msg_id = %d Req_id = %d Retry_counter= %d current_state = %d \n",
                             dwnld_msg_handlr->msg_id, dwnld_msg_handlr->req_id, dwnld_msg_handlr->retry_counter,
                             dwnld_msg_handlr->current_state);
        dwnld_msg_handlr = dwnld_msg_handlr->next;
    }
    dwnld_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (dwnld_msg_handlr != NULL)
    {
        if (dwnld_msg_handlr->msg_id == msg_id)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_download_list Msg_id = %d Current State = %d \n",
                                 dwnld_msg_handlr->msg_id, dwnld_msg_handlr->current_state);
            return dwnld_msg_handlr->intermediate_state;
        }
        else
        {
            dwnld_msg_handlr = dwnld_msg_handlr->next;
        }
    }
    return E_STATE_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_send_msg_handler
 * DESCRIPTION
 *  Update Send Node with retry verion Number.
 * PARAMETERS
 *  updated_state           [IN]        
 *  msg_id                  [IN]        
 *  retry_send_version      [IN]        
 *  retry_version_count     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_send_msg_handler(
        const umms_state_enum updated_state,
        const U32 msg_id,
        const mmi_enum_retry_send_verion_enum retry_send_version,
        const U32 retry_version_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_send_msg_handler Msg_id = %d Updated State = %d Retry Send version= %d Retry Version Count = %d\n",
                         msg_id, updated_state, retry_send_version, retry_version_count);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            send_msg_handlr->current_state = updated_state;
            send_msg_handlr->retry_version = retry_send_version;
            send_msg_handlr->retry_version_count = retry_version_count;
            break;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_send_version_number
 * DESCRIPTION
 *  Get the Verion Number from the Send List.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_enum_retry_send_verion_enum mmi_umms_get_send_version_number(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_send_version_number Msg_id = %d  \n", msg_id);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_send_version_number Msg_id = %d  Retry Send version= %d \n",
                                 send_msg_handlr->msg_id, send_msg_handlr->retry_version);
            return send_msg_handlr->retry_version;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return UMMS_SEND_VERSION_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_send_version_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_get_send_version_count(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_send_version_count Msg_id = %d  \n", msg_id);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_get_send_version_count Msg_id = %d  Retry Send version Count= %d \n",
                                 send_msg_handlr->msg_id, send_msg_handlr->retry_version_count);
            return send_msg_handlr->retry_version_count;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_download_msg_hndlr
 * DESCRIPTION
 *  Update Download Message Handler with the Latest State.
 * PARAMETERS
 *  msg_id              [IN]        
 *  req_id              [IN]        
 *  updated_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_download_msg_hndlr(const U32 msg_id, const U32 req_id, const umms_state_enum updated_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *download_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_download_msg_hndlr Msg_id = %d Req_id = %d State = %d \n",
                         msg_id, req_id, updated_state);
    download_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (download_msg_handlr != NULL)
    {
        if (download_msg_handlr->msg_id == msg_id)
        {
            download_msg_handlr->current_state = updated_state;
            break;
        }
        else
        {
            download_msg_handlr = download_msg_handlr->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_current_state_of_download
 * DESCRIPTION
 *  Update Download Message Handler with the Latest State.
 * PARAMETERS
 *  msg_id              [IN]        
 *  req_id              [IN]        
 *  updated_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
umms_state_enum mmi_umms_get_current_state_of_download(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *download_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_current_state_of_download Msg_id = %d  \n",
                         msg_id);
    download_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (download_msg_handlr != NULL)
    {
        if (download_msg_handlr->msg_id == msg_id)
        {
            return download_msg_handlr->current_state;
        }
        else
        {
            download_msg_handlr = download_msg_handlr->next;
        }
    }
    return E_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_download_msg_hndlr
 * DESCRIPTION
 *  Update Download Message Handler with the Latest State.
 * PARAMETERS
 *  msg_id              [IN]        
 *  req_id              [IN]        
 *  updated_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_download_msg_hndlr_with_percent_val(const U32 msg_id, const U32 req_id, const U32 percent_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *download_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_download_msg_hndlr Msg_id = %d Req_id = %d\n",
                         msg_id, req_id);
    download_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (download_msg_handlr != NULL)
    {
        if (download_msg_handlr->msg_id == msg_id)
        {
            download_msg_handlr->percent_val = percent_val;
            break;
        }
        else
        {
            download_msg_handlr = download_msg_handlr->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_percent_val_from_download_list
 * DESCRIPTION
 *  Get the percent val from download List
 * PARAMETERS
 *  msg_id              [IN]        
 *  req_id              [IN]        
 *  updated_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_umms_get_percent_val_from_download_list(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *download_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_percent_val_from_download_list Msg_id = %d\n",
                         msg_id);
    download_msg_handlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    while (download_msg_handlr != NULL)
    {
        if (download_msg_handlr->msg_id == msg_id)
        {
            return download_msg_handlr->percent_val;
        }
        else
        {
            download_msg_handlr = download_msg_handlr->next;
        }
    }
    return 0;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_add_to_list
 * DESCRIPTION
 *  Add to List Based on teh Current State.
 * PARAMETERS
 *  msg_id                  [IN]        
 *  req_id                  [IN]        
 *  current_state           [IN]        
 *  intermediate_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_add_to_list(
        const U32 msg_id,
        const U32 req_id,
        const umms_state_enum current_state,
        const umms_state_enum intermediate_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (current_state)
    {
        case E_STATE_GET_NUM_REQ_AT_START_UP:
        case E_STATE_NONE:
        case E_STATE_DOWNLOADED_MSG:
        case E_STATE_DELETE_MSG:
        case E_STATE_MOVE_MSG:
        case E_STATE_GET_NUM_REQ_INTERMEDATE_MSG:
        case E_STATE_SAVE_MSG:
        case E_STATE_SEND_MMS_FROM_UC:
        case E_STATE_DELETE_CORRUPT_MSG:
        case E_STATE_DD_RR_MSG_STATUS_VIEW:
        case E_STATE_DD_RR_MSG_STATUS_PROPERTIES:
        case E_STATE_GET_NUM_REQ_FOR_GLOBAL_UPDATE:
            umms_add_to_msg_hndlr_list(msg_id, req_id, current_state);
            break;
        case E_STATE_DOWNLOAD_MSG:
		case E_STATE_DOWNLOAD_IN_CALL_MSG:
            umms_add_to_download_msg_hndlr_list(msg_id, req_id, current_state,intermediate_state);
            break;
        case E_STATE_SEND_MSG:
            if (intermediate_state == E_STATE_SAVE_MMS_FROM_UC)
            {
                g_current_mms_info_list->folder_id = MMA_FOLDER_DRAFT;
            }
            umms_add_to_send_msg_hndlr_list(
                msg_id,
                req_id,
                current_state,
                intermediate_state,
                g_current_mms_info_list->folder_id);
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_free_req_node
 * DESCRIPTION
 *  Free Req Handler Node. Dummy API
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_free_req_node(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_req_msg_handler_struct *temp_node = NULL;
    umms_send_msg_handler_struct *temp_node_send = NULL;
    umms_download_msg_handler_struct *temp_node_download = NULL;

    umms_req_msg_handler_struct *msg_hndlr = NULL;
    umms_send_msg_handler_struct *send_msg_handlr = NULL;
    umms_download_msg_handler_struct *download_msg_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    download_msg_hndlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;

    if (msg_hndlr != NULL)
    {
        if ((msg_hndlr->msg_id == msg_id) && (msg_hndlr->req_id == req_id))
        {
            if (msg_hndlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_current_mms_info_list->g_umms_req_msg_hndlr);
                g_current_mms_info_list->g_umms_req_msg_hndlr = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_current_mms_info_list->g_umms_req_msg_hndlr = msg_hndlr->next;
                umms_free(msg_hndlr);
                msg_hndlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node = msg_hndlr;
            msg_hndlr = msg_hndlr->next;
            while ((msg_hndlr->msg_id != msg_id) && (msg_hndlr->req_id != req_id))
            {
                if (msg_hndlr->next != NULL)
                {
                    msg_hndlr = msg_hndlr->next;
                }
                temp_node = temp_node->next;
            }
            /* In between node needs to be deleted */
            if (msg_hndlr->next != NULL)
            {
                temp_node->next = msg_hndlr->next;
                umms_free(msg_hndlr);
                msg_hndlr = NULL;
            }
            else
            {
                /* The last node is to be deleted. */
                temp_node->next = NULL;
                umms_free(msg_hndlr);
                msg_hndlr = NULL;
            }
        }
    }

    if (send_msg_handlr != NULL)
    {
        if ((send_msg_handlr->msg_id == msg_id) && (send_msg_handlr->req_id == req_id))
        {
            if (send_msg_handlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_dwnld_send_list->g_umms_send_msg_hndlr);
                g_dwnld_send_list->g_umms_send_msg_hndlr = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_dwnld_send_list->g_umms_send_msg_hndlr = send_msg_handlr->next;
                umms_free(send_msg_handlr);
                send_msg_handlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node_send = send_msg_handlr;
            send_msg_handlr = send_msg_handlr->next;
            while ((send_msg_handlr->msg_id != msg_id) && (send_msg_handlr->req_id != req_id))
            {
                if (send_msg_handlr->next != NULL)
                {
                    send_msg_handlr = send_msg_handlr->next;
                }
                temp_node_send = temp_node_send->next;
            }
            /* In between node needs to be deleted */
            if (send_msg_handlr->next != NULL)
            {
                temp_node_send->next = send_msg_handlr->next;
                umms_free(send_msg_handlr);
                send_msg_handlr = NULL;
            }
            else
            {
                /* The last node is to be deleted. */
                temp_node_send->next = NULL;
                umms_free(send_msg_handlr);
                send_msg_handlr = NULL;
            }
        }
    }

    if (download_msg_hndlr != NULL)
    {
        if ((download_msg_hndlr->msg_id == msg_id) && (download_msg_hndlr->req_id == req_id))
        {
            if (download_msg_hndlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_dwnld_send_list->g_umms_dwnld_msg_hndlr);
                g_dwnld_send_list->g_umms_dwnld_msg_hndlr = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_dwnld_send_list->g_umms_dwnld_msg_hndlr = download_msg_hndlr->next;
                umms_free(download_msg_hndlr);
                download_msg_hndlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node_download = download_msg_hndlr;
            download_msg_hndlr = download_msg_hndlr->next;
            while ((download_msg_hndlr->msg_id != msg_id) && (download_msg_hndlr->req_id != req_id))
            {
                if (download_msg_hndlr->next != NULL)
                {
                    download_msg_hndlr = download_msg_hndlr->next;
                }
                temp_node_download = temp_node_download->next;
            }
            /* In between node needs to be deleted */
            if (download_msg_hndlr->next != NULL)
            {
                temp_node_download->next = download_msg_hndlr->next;
                umms_free(download_msg_hndlr);
                download_msg_hndlr = NULL;
            }
            else
            {
                /* The last node is to be deleted. */
                temp_node_download->next = NULL;
                umms_free(download_msg_hndlr);
                download_msg_hndlr = NULL;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_viewer_properties_mms
 * DESCRIPTION
 *  Show MMS properties according to the MEssge Type.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_viewer_properties_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer = NULL;  /* Buffer holding history data */
    S8 temp[TEMP_BUFFER_SIZE] = {0, };
	S8 str_cmp_temp[MMA_MAX_ADDR_LEN] = {0x00, };
    S8 str_cmp_temp_1[MAX_SUB_MENU_SIZE] = {0x00,};
	S8 str_sub_cmp_temp[MMA_MAX_SUBJECT_LEN] = {0x00, };
    S8 str_sub_cmp_rpt_msg[MMI_UMMS_XML_MAX_SUBJECT_LEN + 1] = {0x00,};
	S8 str_app_cmp_temp[MAX_PROGRESS_STRING_LENGTH] = {0x00, };
    MYTIME time, time1;
    U16 status_str_id = 0;
    U32 len = 0;
    S32 size = 0, size_kb = 0, size_bytes = 0;
    mmi_umms_addr_struct *temp_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_show_viewer_properties_mms Msg_id = %d message Type = %d   \n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->msg_type);
    EntryNewScreen(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES, NULL, mmi_umms_show_viewer_properties_mms, NULL);
    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {
        DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);
    }   
    if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_JAVA)
    {
        DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_UMMS_JAVA_OPTIONS);
    }
    mmi_umms_delete_progress_screen();
    gui_buffer = GetCurrGuiBuffer(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
    memset(subMenuData, 0, sizeof(subMenuData));
    /* read Mark Set For RR And DR*/
    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {
        if(g_current_mms_info_list->isRead == KAL_FALSE)
        {
            mmi_umms_set_readmark_req(g_current_mms_info_list->current_msg_id);
        }
    }
    /* Status */
    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {
        if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
        {
            switch (g_current_mms_info_list->umms_mms_xml_msg->status)
            {
                case MMA_DR_STATUS_EXPIRED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_EXPIRED;
                    break;
                case MMA_DR_STATUS_RETRIEVED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_RETRIEVED;
                    break;
                case MMA_DR_STATUS_REJECTED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_REJECTED;
                    break;
                case MMA_DR_STATUS_DEFERRED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_DEFERRED;
                    break;
                case MMA_DR_STATUS_UNRECOGNISED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_UNRECOGNISED;
                    break;
                case MMA_DR_STATUS_INDETERMINATE:
                    status_str_id = STR_ID_UMMS_DR_STATUS_INDETERMINATE;
                    break;
                case MMA_DR_STATUS_FORWARDED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_FORWARDED;
                    break;
                case MMA_DR_STATUS_UNREACHABLE:
                    status_str_id = STR_ID_UMMS_DR_STATUS_UNREACHABLE;
                    break;
                default:
                    status_str_id = 0;
                    break;
            }
        }

        if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT)
        {
            switch (g_current_mms_info_list->umms_mms_xml_msg->status)
            {
                case MMA_RR_STATUS_READ:
                    status_str_id = STR_ID_UMMS_DR_STATUS_READ;
                    break;
                case MMA_RR_STATUS_DELETED_NO_READ:
                    status_str_id = STR_ID_UMMS_DR_STATUS_NO_READ;
                    break;
                default:
                    status_str_id = 0;
                    break;
            }
        }

        if (status_str_id != 0)
        {
            memset(subMenuData, 0, sizeof(subMenuData));
        mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_STATUS));
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");

            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_ucs2cpy((S8*) temp, (S8*) GetString(status_str_id));
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
			memset(temp, 0x00, TEMP_BUFFER_SIZE);
			mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
			mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }

    }
    /* From Field */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_show_viewer_properties_mms Msg_id = %d message Type = %d   \n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->msg_type);

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_show_viewer_properties_mms From Field = %s   \n",
                         g_current_mms_info_list->from_address);

    if (((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_NOTIFICATION) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_MMS) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_TEMPLATE) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_JAVA))
        && ((g_current_mms_info_list->folder_id == MMA_FOLDER_INBOX)
            /* ||(g_current_mms_info_list->folder_id == MMA_FOLDER_ARCHIVE) */
        ))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_FROM));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
		if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->from_address,(S8*)str_cmp_temp,MMA_MAX_ADDR_LEN))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) g_current_mms_info_list->from_address);
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }

    /* To field */

    if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_NOTIFICATION) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_TO));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        if(g_current_mms_info_list->umms_mms_xml_msg->to_head == NULL)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            temp_addr = g_current_mms_info_list->umms_mms_xml_msg->to_head; 
            while(temp_addr != NULL)
            {
                 memset(str_cmp_temp_1,0,MMA_MAX_ADDR_LEN);
                if(temp_addr->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                { // Convert To number from ASCII to UCS2.
                    len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                    if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                    {
                        mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                    }
                    else
                    {
                        memset(str_cmp_temp_1, 0, (MMA_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                        mmi_asc_n_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                        mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                    }
                    //mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr);
                    mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                }
                else
                {   
                    len = mmi_ucs2strlen((S8*) temp_addr->addr);
                    if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                    {
                        mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                }
                else
                {
                        mmi_ucs2ncpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                        mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                    }
                    mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                }
                temp_addr = temp_addr->next;
                if(temp_addr != NULL)
                {
                    memset(temp, 0x00, TEMP_BUFFER_SIZE);
                    mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                }
                
            }
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* CC field */

    if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_NOTIFICATION))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_CC));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        
        if(g_current_mms_info_list->umms_mms_xml_msg->cc_head == NULL)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            temp_addr = g_current_mms_info_list->umms_mms_xml_msg->cc_head ;
            while(temp_addr != NULL)
            {
                memset(str_cmp_temp_1,0,MMA_MAX_ADDR_LEN);
                if(temp_addr ->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                { // Convert To number from ASCII to UCS2.
                    len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                    if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                    {
                        mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
        }
                else
                {
                        memset(str_cmp_temp_1, 0, (MMA_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                        mmi_asc_n_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                        mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                    }
                    //mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr);
                    mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                }
                else
                {   
                    len = mmi_ucs2strlen((S8*) temp_addr->addr);
                    if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                    {
                        mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                    }
                    else
                    {
                        mmi_ucs2ncpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                        mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                    }
                    mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                }
                temp_addr  = temp_addr ->next;
                if(temp_addr != NULL)
        {
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
                    mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                }
                
            }
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        /* /BCC */
        if (g_current_mms_info_list->folder_id != MMA_FOLDER_INBOX)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BCC));
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

			if(g_current_mms_info_list->umms_mms_xml_msg->bcc_head == NULL)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
            }
            else
            {
                temp_addr = g_current_mms_info_list->umms_mms_xml_msg->bcc_head ;
                while(temp_addr != NULL)
                {
                    memset(str_cmp_temp_1,0,MMA_MAX_ADDR_LEN);
                    if(temp_addr ->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                    { // Convert To number from ASCII to UCS2.
                        len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                        if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                        {
                            mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                    }
                    else
                    {
                            memset(str_cmp_temp_1, 0, (MMA_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                            mmi_asc_n_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                            mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                        }
                        //mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr);
                        mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                    }
                    else
                    {   
                        len = mmi_ucs2strlen((S8*) temp_addr->addr);
                        if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                        {
                            mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                        }
                        else
                        {
                            mmi_ucs2ncpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                            mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                        }
                        mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                    }
                    temp_addr  = temp_addr ->next;
                    if(temp_addr != NULL)
                    {
                        memset(temp, 0x00, TEMP_BUFFER_SIZE);
                        mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                    }
            }
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }
    }

    /* Message Id for Read and Delivery Report */

    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MESSAGE_ID));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        if (g_current_mms_info_list->umms_mms_xml_msg->reported_msg_id == 0)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            gui_itoa((S32) g_current_mms_info_list->umms_mms_xml_msg->reported_msg_id, (UI_string_type) temp, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, UMMS_MEMSET_BUFFER_2);
            /* mmi_ucs2cat((S8*) subMenuData, (S8*) g_current_mms_info_list->current_msg_id); */
        }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }

    /* /Subject */
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SUBJECT));

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
       (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {
        if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->umms_mms_xml_msg->reported_subject,(S8*)str_sub_cmp_rpt_msg,MMI_UMMS_XML_MAX_SUBJECT_LEN))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) g_current_mms_info_list->umms_mms_xml_msg->reported_subject);
        }
    }
    else
    {
	if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->subject,(S8*)str_sub_cmp_temp,MMA_MAX_ADDR_LEN))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) g_current_mms_info_list->subject);
    }
    }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    /* Expiration Time only For Notification */
    if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_EXPIRE_TIME));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        if (g_current_mms_info_list->expiry_time == 0)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            U8 dttemp[TEMP_BUFFER_SIZE];
            FLOAT timezone;

            timezone = (FLOAT) mmi_dt_get_tz();
            mmi_dt_utc_sec_2_mytime((U32) g_current_mms_info_list->expiry_time, &time1, MMI_TRUE);
            mmi_dt_utc_to_rtc(timezone, time1, time);

            memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
            date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
            mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

            memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            /* Time */
            memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
            time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
            mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* /Priority */
	/* CR ID MAUI_00404706 */
	if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_NOTIFICATION))
	{

    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_OPTIONS_PROPERTIES_PRIORITY));

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    switch (g_current_mms_info_list->priority)
    {
        case MMA_PRIORITY_LOW:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_LOW));
            break;
        case MMA_PRIORITY_MEDIUM:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_NORMAL));
            break;
        case MMA_PRIORITY_HIGH:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_HIGH));
            break;
        default:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_UNKNOWN));
            break;
    }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

	}
	/* CR ID MAUI_00404706 */

    /* Application Id and Reply by Application Id for Java MMS */

    if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_JAVA)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_APPLICATION_ID));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
		if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->app_id,(S8*)str_app_cmp_temp,MAX_PROGRESS_STRING_LENGTH))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            S8 app_id[(MAX_PROGRESS_STRING_LENGTH + 1) * ENCODING_LENGTH];

            mmi_asc_to_ucs2((PS8) app_id, (PS8) g_current_mms_info_list->app_id);

            mmi_ucs2cat((S8*) subMenuData, (S8*) (app_id));

        }

        /* Reply by Application ID */
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_REPLY_TO_APPLICATION_ID));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
		if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->reply_app_id,(S8*)str_app_cmp_temp,MAX_PROGRESS_STRING_LENGTH))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            S8 reply_app_id[(MAX_PROGRESS_STRING_LENGTH + 1) * ENCODING_LENGTH];

            mmi_asc_to_ucs2((PS8) reply_app_id, (PS8) g_current_mms_info_list->reply_app_id);

            mmi_ucs2cat((S8*) subMenuData, (S8*) (reply_app_id));

        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);


    }

    /* //message class */
    if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MSG_CLASS));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        switch (g_current_mms_info_list->msg_class)
        {
            case MMA_MSG_CLASS_PERSONAL:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_PERSONEL_MSG_CLASS));
                break;
            case MMA_MSG_CLASS_ADVERTISEMENT:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_ADVERTISMENT));
                break;
            case MMA_MSG_CLASS_INFORMATIONAL:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_INFORMATIONAL_MSG_CLASS));
                break;
            case MMA_MSG_CLASS_AUTO:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_AUTO_MSG_CLASS));
                break;
            default:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_UNKNOWN));
                break;
        }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* /Creation Date */
	/* CR ID MAUI_00404735 */
	if(g_current_mms_info_list->folder_id != MMA_FOLDER_INBOX)
	{
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_CREATION_DATE));

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
/*
    if (g_current_mms_info_list->date == 0)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
*/
    {
        U8 dttemp[TEMP_BUFFER_SIZE];
        FLOAT timezone;

        timezone = (FLOAT) mmi_dt_get_tz();
        mmi_dt_utc_sec_2_mytime((U32) g_current_mms_info_list->date, &time1, MMI_TRUE);
        mmi_dt_utc_to_rtc(timezone, time1, time);

        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        /* Time */
        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

    }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

	}
	/* CR ID MAUI_00404735 */

    /* Receive Date */
    if(g_current_mms_info_list->folder_id == MMA_FOLDER_INBOX)
    {
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_RECEIVE_DATE));

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    if (g_current_mms_info_list->receive_date == 0)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        U8 dttemp[TEMP_BUFFER_SIZE];
        FLOAT timezone;

        timezone = (FLOAT) mmi_dt_get_tz();
        mmi_dt_utc_sec_2_mytime((U32) g_current_mms_info_list->receive_date, &time1, MMI_TRUE);
        mmi_dt_utc_to_rtc(timezone, time1, time);

        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        /* Time */
        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

    }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }

    /* /MMS Size */
    if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SIZE));
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        size = g_current_mms_info_list->msg_size;
        size_kb = size / 1024;
        size_bytes = size % 1024;

        if (size_kb >= 1)
        {
            size_kb++;
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            gui_itoa((S32) size_kb, (UI_string_type) temp, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, UMMS_MEMSET_BUFFER_2);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));

        }
        else
        {
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            gui_itoa((S32) size_bytes, (UI_string_type) temp, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, UMMS_MEMSET_BUFFER_2);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BYTES));
        }
    }

    ShowCategory78Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) subMenuData,
        mmi_ucs2strlen((S8*) subMenuData),
        gui_buffer);


    switch (g_current_mms_info_list->msg_type)
    {
        case MMA_MSG_TYPE_NOTIFICATION:
            SetLeftSoftkeyFunction(mmi_umms_entry_notification_option_screen, KEY_EVENT_UP);
            SetKeyHandler(mmi_umms_entry_notification_option_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            break;
        case MMA_MSG_TYPE_JAVA:
            SetLeftSoftkeyFunction(mmi_umms_enter_java_mms_options, KEY_EVENT_UP);
            SetKeyHandler(mmi_umms_enter_java_mms_options, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
 SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            break;
        case MMA_MSG_TYPE_DELIVERY_REPORT:
        case MMA_MSG_TYPE_READ_REPORT:
            SetLeftSoftkeyFunction(mmi_umms_entry_report_screen, KEY_EVENT_UP);
            SetKeyHandler(mmi_umms_entry_report_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(mmi_umms_deinit_viewer_and_go_to_box_list, KEY_EVENT_UP);
            SetKeyHandler(mmi_umms_deinit_viewer_and_go_to_box_list, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            break;
        default:
            /* MMI_ASSERT(0); */
            break;

    }


    return;
}

void mmi_umms_deinit_viewer_and_go_to_box_list(void)
{
    mmi_mv_deinit_viewer();
    GoBackHistory();
}


void mmi_umms_deinit_viewer_and_globals_and_go_to_box_list(void)
{
	    mmi_umms_reset_global();
	    mmi_mv_deinit_viewer();
      GoBackHistory();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_properties_mms
 * DESCRIPTION
 *  Show MMS properties according to the MEssge Type.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_properties_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer = NULL;  /* Buffer holding history data */
    S8 temp[TEMP_BUFFER_SIZE] = {0, };
	S8 str_cmp_temp[MMA_MAX_ADDR_LEN] = {0x00, };
	S8 str_sub_cmp_temp[MMA_MAX_SUBJECT_LEN] = {0x00, };
    S8 str_sub_cmp_rpt_msg[MMI_UMMS_XML_MAX_SUBJECT_LEN + 1] = {0x00,};
    S8 str_cmp_temp_1[MMA_MAX_ADDR_LEN] = {0x00,};
    U32 len = 0;
	S8 str_app_cmp_temp[MAX_PROGRESS_STRING_LENGTH] = {0x00, };
    MYTIME time, time1;
    U16 status_str_id = 0;
    S32 size = 0, size_kb = 0, size_bytes = 0;
    mmi_umms_addr_struct *temp_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_show_properties_mms Msg_id = %d message Type = %d   \n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->msg_type);

    EntryNewScreen(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES, NULL, mmi_umms_show_properties_mms, NULL);
    mmi_umms_delete_progress_screen();
    gui_buffer = GetCurrGuiBuffer(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
    memset(subMenuData, 0, sizeof(subMenuData));
    /* Status */
    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {
        if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] Status Delivery=%d \n", mmi_umms_get_rr_dr_status);
            switch (g_current_mms_info_list->umms_mms_xml_msg->status)
            {
                case MMA_DR_STATUS_EXPIRED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_EXPIRED;
                    break;
                case MMA_DR_STATUS_RETRIEVED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_RETRIEVED;
                    break;
                case MMA_DR_STATUS_REJECTED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_REJECTED;
                    break;
                case MMA_DR_STATUS_DEFERRED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_DEFERRED;
                    break;
                case MMA_DR_STATUS_UNRECOGNISED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_UNRECOGNISED;
                    break;
                case MMA_DR_STATUS_INDETERMINATE:
                    status_str_id = STR_ID_UMMS_DR_STATUS_INDETERMINATE;
                    break;
                case MMA_DR_STATUS_FORWARDED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_FORWARDED;
                    break;
                case MMA_DR_STATUS_UNREACHABLE:
                    status_str_id = STR_ID_UMMS_DR_STATUS_UNREACHABLE;
                    break;
                default:
                    status_str_id = 0;
                    break;
            }
        }

        if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] Status Read=%d \n", mmi_umms_get_rr_dr_status);
            switch (g_current_mms_info_list->umms_mms_xml_msg->status)
            {
                case MMA_RR_STATUS_READ:
                    status_str_id = STR_ID_UMMS_DR_STATUS_READ;
                    break;
                case MMA_RR_STATUS_DELETED_NO_READ:
                    status_str_id = STR_ID_UMMS_DR_STATUS_NO_READ;
                    break;
                default:
                    status_str_id = 0;
                    break;
            }
        }

        if (status_str_id != 0)
        {
            memset(subMenuData, 0, sizeof(subMenuData));
        mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_STATUS));
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");

            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_ucs2cpy((S8*) temp, (S8*) GetString(status_str_id));
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);


        }

    }

    /* From Field */
    if (((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_NOTIFICATION) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_MMS) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_TEMPLATE) ||
         (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_JAVA))
        && ((g_current_mms_info_list->folder_id == MMA_FOLDER_INBOX)
            /* ||(g_current_mms_info_list->folder_id == MMA_FOLDER_ARCHIVE) */
        ))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_FROM));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
		if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->from_address,(S8*)str_cmp_temp,MMA_MAX_ADDR_LEN))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) g_current_mms_info_list->from_address);
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp); 
    }

    /* To field */

    if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_NOTIFICATION) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT))
    {
        
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_TO));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        if(g_current_mms_info_list->umms_mms_xml_msg->to_head == NULL)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            temp_addr = g_current_mms_info_list->umms_mms_xml_msg->to_head; 
            while(temp_addr != NULL)
            {
                if(temp_addr->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                { // Convert To number from ASCII to UCS2.
                    len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                    if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                    {
                        mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                }
                else
                {
                        memset(str_cmp_temp_1, 0, (MMA_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                        mmi_asc_n_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                        mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                    }
                    //mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr);
                    mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                }
                else
                {   
                    len = mmi_ucs2strlen((S8*) temp_addr->addr);
                    if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                    {
                        mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                }
                else
                {
                        mmi_ucs2ncpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                        mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                    }
                    mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                }
                temp_addr = temp_addr->next;
                if(temp_addr != NULL)
                {
                    memset(temp, 0x00, TEMP_BUFFER_SIZE);
                    mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                }
                
            }
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* CC field */

    if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_NOTIFICATION))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_CC));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        
        if(g_current_mms_info_list->umms_mms_xml_msg->cc_head == NULL)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            temp_addr = g_current_mms_info_list->umms_mms_xml_msg->cc_head ;
            while(temp_addr != NULL)
            {
                memset(str_cmp_temp_1,0,MMA_MAX_ADDR_LEN);
                if(temp_addr ->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                { // Convert To number from ASCII to UCS2.
                    len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                    if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                    {
                        mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                }
                else
                {
                        memset(str_cmp_temp_1, 0, (MMA_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                        mmi_asc_n_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                        mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                    }
                    //mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr);
                    mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                }
                else
                {   
                    len = mmi_ucs2strlen((S8*) temp_addr->addr);
                    if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                    {
                        mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                }
                else
                {
                        mmi_ucs2ncpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                        mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                    }
                    mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                }
                temp_addr  = temp_addr ->next;
                if(temp_addr != NULL)
                {
                    memset(temp, 0x00, TEMP_BUFFER_SIZE);
                    mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                }
                
            }
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        /* /BCC */
        if (g_current_mms_info_list->folder_id != MMA_FOLDER_INBOX)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BCC));

            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

			if(g_current_mms_info_list->umms_mms_xml_msg->bcc_head == NULL)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
            }
            else
            {
                temp_addr = g_current_mms_info_list->umms_mms_xml_msg->bcc_head ;
                while(temp_addr != NULL)
                {
                    memset(str_cmp_temp_1,0,MMA_MAX_ADDR_LEN);
                    if(temp_addr ->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                    { // Convert To number from ASCII to UCS2.
                        len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                        if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                        {
                            mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                        }
                        else
                        {
                            memset(str_cmp_temp_1, 0, (MMA_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                            mmi_asc_n_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                            mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                        }
                        //mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr);
                        mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                    }
                    else
                    {   
                        len = mmi_ucs2strlen((S8*) temp_addr->addr);
                        if (len <= (MMA_MAX_ADDR_LEN - ENCODING_LENGTH- ENCODING_LENGTH))
                        {
                            mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                    }
                    else
                    {
                            mmi_ucs2ncpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr, (MMA_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                            mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                        }
                        mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                    }
                    temp_addr  = temp_addr ->next;
                    if(temp_addr != NULL)
                    {
                        memset(temp, 0x00, TEMP_BUFFER_SIZE);
                        mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                    }
                }
            }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        }
    }

    /* Message Id for Read and Delivery Report */

    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MESSAGE_ID));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        if (g_current_mms_info_list->umms_mms_xml_msg->reported_msg_id == 0)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            gui_itoa((S32) g_current_mms_info_list->umms_mms_xml_msg->reported_msg_id, (UI_string_type) temp, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, UMMS_MEMSET_BUFFER_2);
            /* mmi_ucs2cat((S8*) subMenuData, (S8*) g_current_mms_info_list->current_msg_id); */
        }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* /Subject */

    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SUBJECT));

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
       (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {
        if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->umms_mms_xml_msg->reported_subject,(S8*)str_sub_cmp_rpt_msg,MMI_UMMS_XML_MAX_SUBJECT_LEN))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) g_current_mms_info_list->umms_mms_xml_msg->reported_subject);
        }
    }
    else
    {
	if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->subject,(S8*)str_sub_cmp_temp,MMA_MAX_ADDR_LEN))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) g_current_mms_info_list->subject);
    }
    }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    /* Expiration Time only For Notification */
    if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_EXPIRE_TIME));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        if (g_current_mms_info_list->expiry_time == 0)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            U8 dttemp[TEMP_BUFFER_SIZE];
            FLOAT timezone;

            timezone = (FLOAT) mmi_dt_get_tz();
            mmi_dt_utc_sec_2_mytime((U32) g_current_mms_info_list->expiry_time, &time1, MMI_TRUE);
            mmi_dt_utc_to_rtc(timezone, time1, time);

            memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
            date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
            mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

            memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            /* Time */
            memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
            time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
            mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* /Priority */
	/* CR ID MAUI_00404706 */
	if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_NOTIFICATION))
	{

    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_OPTIONS_PROPERTIES_PRIORITY));

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    switch (g_current_mms_info_list->priority)
    {
        case MMA_PRIORITY_LOW:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_LOW));
            break;
        case MMA_PRIORITY_MEDIUM:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_NORMAL));
            break;
        case MMA_PRIORITY_HIGH:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_HIGH));
            break;
        default:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_UNKNOWN));
            break;
    }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

	}
	/* CR ID MAUI_00404706 */
    /* Application Id and Reply by Application Id for Java MMS */

    if (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_JAVA)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_APPLICATION_ID));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
		if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->app_id,(S8*)str_app_cmp_temp,MAX_PROGRESS_STRING_LENGTH))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            S8 app_id[(MAX_PROGRESS_STRING_LENGTH + 1) * ENCODING_LENGTH];

            mmi_asc_to_ucs2((PS8) app_id, (PS8) g_current_mms_info_list->app_id);

            mmi_ucs2cat((S8*) subMenuData, (S8*) (app_id));

        }

        /* Reply by Application ID */
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_REPLY_TO_APPLICATION_ID));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
		if (!mmi_ucs2ncmp((S8*)g_current_mms_info_list->reply_app_id,(S8*)str_app_cmp_temp,MAX_PROGRESS_STRING_LENGTH))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            S8 reply_app_id[(MAX_PROGRESS_STRING_LENGTH + 1) * ENCODING_LENGTH];

            mmi_asc_to_ucs2((PS8) reply_app_id, (PS8) g_current_mms_info_list->reply_app_id);

            mmi_ucs2cat((S8*) subMenuData, (S8*) (reply_app_id));

        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);


    }

    /* //message class */
    if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MSG_CLASS));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        switch (g_current_mms_info_list->msg_class)
        {
            case MMA_MSG_CLASS_PERSONAL:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_PERSONEL_MSG_CLASS));
                break;
            case MMA_MSG_CLASS_ADVERTISEMENT:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_ADVERTISMENT));
                break;
            case MMA_MSG_CLASS_INFORMATIONAL:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_INFORMATIONAL_MSG_CLASS));
                break;
            case MMA_MSG_CLASS_AUTO:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_AUTO_MSG_CLASS));
                break;
            default:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_UNKNOWN));
                break;
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* /Creation Date */
	/* CR ID MAUI_00404735 */
	if(g_current_mms_info_list->folder_id != MMA_FOLDER_INBOX)
	{
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_CREATION_DATE));

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
/*
    if (g_current_mms_info_list->date == 0)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
*/
    {
        U8 dttemp[TEMP_BUFFER_SIZE];
        FLOAT timezone;

        timezone = (FLOAT) mmi_dt_get_tz();
        mmi_dt_utc_sec_2_mytime((U32) g_current_mms_info_list->date, &time1, MMI_TRUE);
        mmi_dt_utc_to_rtc(timezone, time1, time);

        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        /* Time */
        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);
    }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

	}
	/* CR ID MAUI_00404735 */
    /* Receive Date */
    if(g_current_mms_info_list->folder_id == MMA_FOLDER_INBOX)
    {
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_RECEIVE_DATE));

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    if (g_current_mms_info_list->receive_date == 0)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        U8 dttemp[TEMP_BUFFER_SIZE];
        FLOAT timezone;

        timezone = (FLOAT) mmi_dt_get_tz();
        mmi_dt_utc_sec_2_mytime((U32) g_current_mms_info_list->receive_date, &time1, MMI_TRUE);
        mmi_dt_utc_to_rtc(timezone, time1, time);

        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        /* Time */
        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

    }
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }

    /* /MMS Size */
    if ((g_current_mms_info_list->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (g_current_mms_info_list->msg_type != MMA_MSG_TYPE_READ_REPORT))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SIZE));
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        size = g_current_mms_info_list->msg_size;
        size_kb = size / 1024;
        size_bytes = size % 1024;

        if (size_kb >= 1)
        {
            size_kb++;
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            gui_itoa((S32) size_kb, (UI_string_type) temp, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, UMMS_MEMSET_BUFFER_2);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));

        }
        else
        {
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            gui_itoa((S32) size_bytes, (UI_string_type) temp, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, UMMS_MEMSET_BUFFER_2);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BYTES));
        }
    }

    ShowCategory78Screen(
        STR_ID_UMMS_OPTIONS_PROPERTIES,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) subMenuData,
        mmi_ucs2strlen((S8*) subMenuData),
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_message_status_screen
 * DESCRIPTION
 *  Show Message Status Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_message_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer = NULL;  /* Buffer holding history data */
    S8 temp[TEMP_BUFFER_SIZE] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_show_message_status_screen Msg_id = %d Message Status = %d   \n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->msg_status);

    EntryNewScreen(SCR_ID_UMMS_MESSAGE_STATUS, NULL, mmi_umms_show_message_status_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_UMMS_MESSAGE_STATUS);

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    /* mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n"); */
    memset(subMenuData, 0, sizeof(subMenuData));
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    switch (g_current_mms_info_list->msg_status)
    {
        case MMA_MSG_STATUS_NORMAL:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_NORMAL));
            break;
        case MMA_MSG_STATUS_WAITING_SENDING:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_WAITING_SENDING));
            break;
        case MMA_MSG_STATUS_SENDING:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SENDING));
            break;
        case MMA_MSG_STATUS_WAITING_DOWNLOADING:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_WAITING_DWNLOADING));
            break;
        case MMA_MSG_STATUS_DOWNLOADING:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_DWNLOADING));
            break;
        case MMA_MSG_STATUS_FAILED:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_FAILED));
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    ShowCategory78Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) subMenuData,
        mmi_ucs2strlen((S8*) subMenuData),
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_mms_option_screen_according_to_folder_id
 * DESCRIPTION
 *  Show Option Screen according to the Box type selected.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_mms_option_screen_according_to_folder_id(void)
{
    // This screen will be based on the Folder Selected.
    // The same Function will be called always but with different folfer id

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nNumofItem = 0;
    U16 nStrItemList[MAX_SUB_MENUS] = {0, };
    U16 nImgIltemList[MAX_SUB_MENUS] = {0, };
    U8 to_address_buffer[MMA_MAX_ADDR_LEN] = {0x00, };
    U16 parentid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_show_mms_option_screen_according_to_folder_id Msg_id = %d Message Type = %d Folder = %d\n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->msg_type,
                         g_current_mms_info_list->folder_id);
    EntryNewScreen(SCR_ID_UMMS_MMS_OPTIONS, NULL, mmi_umms_show_mms_option_screen_according_to_folder_id, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_MMS_OPTIONS);

    mmi_umms_delete_progress_screen();
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
    switch (g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            parentid = MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS;
            if (g_current_mms_info_list->isForwardLock ||
                (MMI_UMMS_LOCK_MODE_ON == g_current_mms_info_list->app_data[0])||
				((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
				&& (mmi_umms_is_creation_mode_restricted())))
            {
                mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_FORWARD);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_FORWARD);
            }
			if((g_current_mms_info_list->isForwardLock == KAL_TRUE)||
                        (MMI_UMMS_LOCK_MODE_ON == g_current_mms_info_list->app_data[0]))
			{
				mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_EDIT_MESSAGE);
                mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_SAVE_TO_TEMPLATE);
			}
			else
			{
				mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_EDIT_MESSAGE);
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_SAVE_TO_TEMPLATE);
			}
			if(g_current_mms_info_list->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER)
			{
				mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_REPLY_SMS);
			}
			else
			{
				mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTION_REPLY_SMS);
			}
            if(g_current_mms_info_list->isForwardLock == KAL_TRUE)
            {
                mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK_MODE);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK_MODE);
            }
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            if ((g_current_mms_info_list->msg_type == MMA_MSG_TYPE_NOTIFICATION) ||
                (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
                (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_READ_REPORT) ||
                (g_current_mms_info_list->msg_type == MMA_MSG_TYPE_JAVA))
            {
                mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_MOVE_TO_ARCHIVE);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_MOVE_TO_ARCHIVE);
            }
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
            if (!mmi_ucs2ncmp
                ((S8*) g_current_mms_info_list->from_address, (S8*) to_address_buffer, MMA_MAX_ADDR_LEN))
            {
                 mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_REPLY);
                 mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_REPLY_ALL);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_REPLY);
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_REPLY_ALL);
            }
            break;
        case MMA_FOLDER_OUTBOX:

            if ((g_current_mms_info_list->msg_status == MMA_MSG_STATUS_WAITING_SENDING) ||
                (g_current_mms_info_list->msg_status == MMA_MSG_STATUS_SENDING) ||
                mmi_umms_is_mms_in_send_list(g_current_mms_info_list->current_msg_id))
            {
                parentid = MENU_ID_UMMS_OUTBOX_RESTRICTED_OPTIONS;
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
            }
            else
            {
                parentid = MENU_ID_UMMS_OUTBOX_OPTIONS;
                mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
            }
            if ((g_current_mms_info_list->isForwardLock == KAL_TRUE)||
						((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
						&& (mmi_umms_is_creation_mode_restricted())))
            {
                mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_SEND);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_SEND);
            }
            if (g_current_mms_info_list->isForwardLock == KAL_TRUE)
            {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_EDIT_MESSAGE);
                mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_SAVE_TO_TEMPLATE);
            }
            else
            {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_EDIT_MESSAGE);
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_SAVE_TO_TEMPLATE);
            }
            break;
        case MMA_FOLDER_SENT:
            parentid = MENU_ID_UMMS_SENT_OPTIONS;
            if ((g_current_mms_info_list->isForwardLock == KAL_TRUE)||
				((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
				&& (mmi_umms_is_creation_mode_restricted())))
            {
                mmi_frm_hide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_FORWARD);
				mmi_frm_hide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_EDIT_MESSAGE);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_FORWARD);
				mmi_frm_unhide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_EDIT_MESSAGE);
            }
            if (g_current_mms_info_list->isForwardLock == KAL_TRUE)
            {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_EDIT_MESSAGE);
                mmi_frm_hide_menu_item(MENU_ID_UMMS_SENT_SAVE_TO_TEMPLATE);
            }
            else
            {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SENT_OPTIONS_EDIT_MESSAGE);
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_SENT_SAVE_TO_TEMPLATE);
            }
            break;
        case MMA_FOLDER_DRAFT:
            parentid = MENU_ID_UMMS_DRAFT_OPTIONS;
			if ((g_current_mms_info_list->isForwardLock == KAL_TRUE)||
				((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
				&& (mmi_umms_is_creation_mode_restricted())))
            {
                mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_FORWARD);
                mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFTS_OPTIONS_SENT);
            }
            else
            {
                if ((g_current_mms_info_list->umms_mms_xml_msg->to_head == NULL) &&
                    (g_current_mms_info_list->umms_mms_xml_msg->cc_head == NULL) &&
                    (g_current_mms_info_list->umms_mms_xml_msg->bcc_head == NULL))
            {
                mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFTS_OPTIONS_SENT);
				mmi_frm_unhide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_FORWARD);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_DRAFTS_OPTIONS_SENT);
		mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_FORWARD);
            }
            }
            if (g_current_mms_info_list->isForwardLock == KAL_TRUE)
            {
                        mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_EDIT_MESSAGE);
                mmi_frm_hide_menu_item(MENU_ID_UMMS_DRAFTS_SAVE_TO_TEMPLATE);
            }
            else
            {
                        mmi_frm_unhide_menu_item(MENU_ID_UMMS_DRAFT_OPTIONS_EDIT_MESSAGE);
                mmi_frm_unhide_menu_item(MENU_ID_UMMS_DRAFTS_SAVE_TO_TEMPLATE);
            }
            break;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            parentid = MENU_ID_UMMS_ARCHIVE_OPTIONS_MMS;
			if ((g_current_mms_info_list->isForwardLock == KAL_TRUE)||
				((g_current_mms_info_list->isFollowPhoneMMSContentClass == KAL_FALSE) 
				&& (mmi_umms_is_creation_mode_restricted())))
			{
				mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_FORWARD);
			}
			else
			{
				mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_FORWARD);
			}
			if (g_current_mms_info_list->isForwardLock == KAL_TRUE)
			{
				mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_EDIT_MESSAGE);
                                mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_SAVE_TO_TEMPLATE);
                if (!mmi_ucs2ncmp
                    ((S8*) g_current_mms_info_list->from_address, (S8*) to_address_buffer, MMA_MAX_ADDR_LEN))
                {
                     mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY);
                     mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL);
                }
                else
                {
                    mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY);
                    mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL);
                }
			}
			else
			{
				mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_EDIT_MESSAGE);
                                mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_SAVE_TO_TEMPLATE);
                if (!mmi_ucs2ncmp
                    ((S8*) g_current_mms_info_list->from_address, (S8*) to_address_buffer, MMA_MAX_ADDR_LEN))
                {
                     mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY);
                     mmi_frm_hide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL);
                }
                else
                {
                    mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY);
                    mmi_frm_unhide_menu_item(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL);
                }
			}
            break;
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case MMA_FOLDER_USRDEF_TEMPLATE:
            parentid = MENU_ID_UMMS_TEMPLATES_OPTIONS;
	    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE);
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE_ALL);
            break;
        case /* MMA_FOLDER_PREDEF_TEMPLATE */ MMA_FOLDER_TEMPLATE:
            parentid = MENU_ID_UMMS_TEMPLATES_OPTIONS;
            mmi_frm_hide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE_ALL);

			mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
            break;
        default:
            MMI_ASSERT(g_current_mms_info_list->folder_id);
            break;
    }

    nNumofItem = GetNumOfChild_Ext(parentid);
    GetSequenceStringIds_Ext(parentid, nStrItemList);
    GetSequenceImageIds_Ext(parentid, nImgIltemList);
    SetParentHandler(parentid);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
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
 *  mmi_umms_progress_screen
 * DESCRIPTION
 *  Entry Function for Progress Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 string[MAX_PROGRESS_STRING_LENGTH * ENCODING_LENGTH] = {0, };
    U8 *guiBuffer = NULL;
    U32 percent_val = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_umms_progress_screen");

    EntryNewScreen(SCR_ID_UMMS_PROGRESS, NULL, mmi_umms_progress_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_PROGRESS);

    switch (g_current_mms_info_list->progres_screen_id)
    {
        case UMMS_SCR_ID_PLEASE_WAIT:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_PLEASE_WAIT), MAX_PROGRESS_STRING_LENGTH);
            break;
        case UMMS_SCR_ID_SENDING:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_SENDING), MAX_PROGRESS_STRING_LENGTH);
            break;
        case UMMS_SCR_ID_DOWNLOADING:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_DWNLOADING), MAX_PROGRESS_STRING_LENGTH);
            break;
        case UMMS_SCR_ID_DELETING_MSG:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_DELETING_MMS), MAX_PROGRESS_STRING_LENGTH);
            break;
        case UMMS_SCR_ID_CANCEL_DOWNLOAD_MMS:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_CANCELLING_MMS), MAX_PROGRESS_STRING_LENGTH);
            break;
        case UMMS_SCR_ID_SAVING:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_SAVING), MAX_PROGRESS_STRING_LENGTH);
            break;
        case UMMS_SCR_ID_CANCEL_SEND:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_CANCELLING_SEND), MAX_PROGRESS_STRING_LENGTH);
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    if (g_current_mms_info_list->progres_screen_id == UMMS_SCR_ID_DOWNLOADING)
    {
        if(guiBuffer != NULL)
        {
            percent_val = mmi_umms_get_percent_val_from_download_list(g_current_mms_info_list->current_msg_id);
        }
        else
        {
            percent_val = 0;
        }
        ShowCategory402Screen(
            (U8*) string,
            0,
            0,
            0,
            STR_GLOBAL_ABORT,
            IMG_GLOBAL_BACK,
            (U8*) GetString(STR_ID_UMMS_PLEASE_WAIT),
            (U16)percent_val,
            NULL);

        GetCurrEndKeyDownHandler();

        /* ClearInputEventHandler(MMI_DEVICE_ALL); */

        SetKeyHandler(mmi_uc_cancel_download_mms_by_end_key, KEY_END, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_umms_cancel_download_mms, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory66Screen(
            STR_MMS_MENUENTRY,
            GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
            0,
            0,
            0,
            0,
            (U8*) string,
            IMG_GLOBAL_PROGRESS,
            NULL);

        /* GetCurrEndKeyDownHandler(); */
        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearAllKeyHandler();
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_cancel_download_mms_by_end_key
 * DESCRIPTION
 *  Cancel Download by End Key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_cancel_download_mms_by_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_uc_cancel_download_mms_by_end_key Msg_id = %d \n",
                         g_current_mms_info_list->current_msg_id);
    mmi_umms_abort_download_mms(E_STATE_CANCEL_DOWNLOAD_MSG_BY_END_KEY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_cancel_download_mms
 * DESCRIPTION
 *  Cacel Download Req,
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_cancel_download_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_cancel_download_mms Msg_id = %d \n",
                         g_current_mms_info_list->current_msg_id);
    g_current_mms_info_list->progres_screen_id = UMMS_SCR_ID_CANCEL_DOWNLOAD_MMS;
    if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
    {
        mmi_umms_entry_dummy_screen();
        mmi_umms_delete_progress_screen();
    }
    mmi_umms_progress_screen();
    mmi_umms_abort_download_mms(E_STATE_CANCEL_DOWNLOAD_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_current_selected_msg_id
 * DESCRIPTION
 *  Get the current Msg Id from the Global.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_get_current_selected_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_current_selected_msg_id Msg_id = %d \n",
                         g_current_mms_info_list->current_msg_id);
    return g_current_mms_info_list->current_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_go_to_box_list_screen
 * DESCRIPTION
 *  GO to the MEssage List Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_go_to_box_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Get the Total Number of Message present in the box selected
    // If total number in the box is 0 then go to the Message Centre Screen
    // Else got to the file List Screen.
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_go_to_box_list_screen \n");
    if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
    {
        mmi_umms_entry_dummy_screen();
    }
    switch (g_current_mms_info_list->folder_id)
    {
        case MMA_FOLDER_INBOX:
            if (IsScreenPresent(SCR_ID_UM_INBOX))
            {
                DeleteUptoScrID(SCR_ID_UM_INBOX);
                mmi_umms_reset_global();
            }
            break;
        case MMA_FOLDER_OUTBOX:
            if (IsScreenPresent(SCR_ID_UM_UNSENT))
            {
                DeleteUptoScrID(SCR_ID_UM_UNSENT);
                mmi_umms_reset_global();
            }
            break;
        case MMA_FOLDER_SENT:
            if (IsScreenPresent(SCR_ID_UM_SENT))
            {
                DeleteUptoScrID(SCR_ID_UM_SENT);
                mmi_umms_reset_global();
            }
            break;
        case MMA_FOLDER_DRAFT:
            if (IsScreenPresent(SCR_ID_UM_DRAFT))
            {
                DeleteUptoScrID(SCR_ID_UM_DRAFT);
                mmi_umms_reset_global();
            }
            break;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            if (IsScreenPresent(SCR_ID_UM_ARCHIVE))
            {
                DeleteUptoScrID(SCR_ID_UM_ARCHIVE);
                mmi_umms_reset_global();
            }
            break;
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case MMA_FOLDER_TEMPLATE:
            if (IsScreenPresent( /* SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED */ SCR_ID_UMMS_TEMPLATES))
            {
                DeleteUptoScrID( /* SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED */ SCR_ID_UMMS_TEMPLATES);
                mmi_umms_reset_global();
            }
            break;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            if (IsScreenPresent( /* SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED */ SCR_ID_UMMS_TEMPLATES))
            {
                DeleteUptoScrID( /* SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED */ SCR_ID_UMMS_TEMPLATES);
                mmi_umms_reset_global();
            }
            break;
        default:
            if (IsScreenPresent(SCR_ID_UM_DELETE_FOLDER))
            {
                DeleteUptoScrID(SCR_ID_UM_DELETE_FOLDER);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_msg_numbers_in_global_list
 * DESCRIPTION
 *  Function to set the vakue of total number of MMS in diifernt boxes.
 * PARAMETERS
 *  msg     [IN]        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_msg_numbers_in_global_list(const mmi_um_get_msg_num_rsp_struct *msg)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_set_msg_numbers_in_global_list Msg_id = %d \n",
                         g_current_mms_info_list->current_msg_id);

    g_msg_number_struct->msg_number_inbox = msg->inbox_unread_msg_number + msg->inbox_read_msg_number;
    g_msg_number_struct->total_number_of_unread_msgs = msg->inbox_unread_msg_number;
    g_msg_number_struct->msg_number_outbox = msg->unsent_msg_number;
    g_msg_number_struct->msg_number_sent = msg->sent_msg_number;
    g_msg_number_struct->msg_number_drafts = msg->draft_msg_number;
    g_msg_number_struct->predefined_template_msg_number = msg->predefined_template_msg_number;
    g_msg_number_struct->userdefined_template_msg_number = msg->userdefined_template_msg_number;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    g_msg_number_struct->archive_msg_number = msg->archive_msg_number;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_total_number_of_messages
 * DESCRIPTION
 *  Get total number of MEssagess.
 * PARAMETERS
 *  total_num_messages      [?]     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_total_number_of_messages(U32 *total_num_messages)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_total_number_of_messages Msg_id = %d \n",
                         g_current_mms_info_list->current_msg_id);
    *total_num_messages =
        g_msg_number_struct->msg_number_inbox + g_msg_number_struct->msg_number_outbox +
        g_msg_number_struct->msg_number_sent + g_msg_number_struct->msg_number_drafts +
        g_msg_number_struct->userdefined_template_msg_number + g_msg_number_struct->predefined_template_msg_number  ;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    *total_num_messages = *total_num_messages + g_msg_number_struct->archive_msg_number;
#endif 
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_total_number_of_messages Total Message = %d Unread = %d \n",
                         *total_num_messages, g_msg_number_struct->total_number_of_unread_msgs);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_number_of_unread_messages_in_inbox
 * DESCRIPTION
 *  Get total number of Unread MMS.
 * PARAMETERS
 *  total_num_unread_messages       [?]     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_number_of_unread_messages_in_inbox(U32 *total_num_unread_messages)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_total_number_of_messages Unread = %d \n",
                         g_msg_number_struct->total_number_of_unread_msgs);
    *total_num_unread_messages = g_msg_number_struct->total_number_of_unread_msgs;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_handle_new_mms
 * DESCRIPTION
 *  Handling of NEw MMS PoPUp.
 * PARAMETERS
 *  msgRsp      [IN]        [?]         [?]         [?]
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_handle_new_mms(const wap_mma_get_msg_info_rsp_struct *msgRsp, const U32 msg_id)
{
    // Get the Active Screen ID and see that it is not in call.
    // IF in call then insert the new MMS PopUp just below the Call Screen.
    // Also check for the type of MMS . Notification Java and based on this show the PopUp.

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 currScrenID = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_handle_new_mms Msg_id = %d Msg_type = %d\n",
                         msgRsp->msg_id, msgRsp->msg_type);

    mmi_umms_set_msg_number_state(E_STATE_GET_NUM_REQ_AT_START_UP);
    mmi_umms_update_status_icon_indicator();
    currScrenID = GetActiveScreenId();
    if ((currScrenID == IDLE_SCREEN_ID) || (currScrenID == SCR_ID_UM_NEW_MSG_IND)
        || (currScrenID == SCR_ID_UM_NEW_MSG_DUMMY_IND))
    {
        /* Do Nothing The Screen will be shown by UM. */
        if (msgRsp->msg_type == MMA_MSG_TYPE_JAVA)
        {
            mmi_jsr_add_recv_java_mms_content(msgRsp->msg_id, msgRsp->java_app_id);
        }
    }
    else
    {
#ifndef __CMMCC_SHOW_NEW_MSG_POP_UP__        
        mmi_umms_um_refresh_ind(MMA_FOLDER_INBOX);
        if ((!mmi_umms_is_in_call()) && (!AlmIsTonePlaying()))      /* if no call is there only then show it */
        {
            if (msgRsp->msg_type == MMA_MSG_TYPE_JAVA)
            {
                mmi_jsr_add_recv_java_mms_content(msgRsp->msg_id, msgRsp->java_app_id);
                mmi_msg_entry_new_msg_popup(MSG_UMMS_NEW_JAVA_MMS);
            }
            else
            {
                mmi_msg_entry_new_msg_popup(MSG_UMMS_NEW_MMS);
            }
        }
        else if (isInCall() == MMI_TRUE)
        {
            playRequestedTone(SMS_IN_CALL_TONE);
        }
#else
        mmi_umms_um_refresh_ind(MMA_FOLDER_INBOX);
        if ((!mmi_umms_is_in_call()) && (!AlmIsTonePlaying()))      /* if no call is there only then show it */
        {
            if (msgRsp->msg_type == MMA_MSG_TYPE_JAVA)
            {
                mmi_jsr_add_recv_java_mms_content(msgRsp->msg_id, msgRsp->java_app_id);
                if(wap_is_new_msg_popup_handled() == KAL_FALSE)
                {
                    mmi_msg_entry_new_msg_popup(MSG_UMMS_NEW_JAVA_MMS);
                }
            }
            else
            {
                if(wap_is_new_msg_popup_handled() == KAL_FALSE)
                {
                    mmi_msg_entry_new_msg_popup(MSG_UMMS_NEW_MMS);
                }
            }
        }
        else if (isInCall() == MMI_TRUE)
        {
            playRequestedTone(SMS_IN_CALL_TONE);
        }
#endif /* __CMMCC_SHOW_NEW_MSG_POP_UP__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_send_and_save_state
 * DESCRIPTION
 *  Get whether the MMS Is Send and Save.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_get_send_and_save_state(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_send_and_save_state Msg_id = %d \n", msg_id);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            return send_msg_handlr->is_send_save;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }

    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_folder_id_from_send_list
 * DESCRIPTION
 *  Get folder ID from the Send List.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_folder_enum mmi_umms_get_folder_id_from_send_list(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_folder_id_from_send_list Msg_id = %d \n", msg_id);
    send_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_hndlr != NULL)
    {
        if (send_hndlr->msg_id == msg_id)
        {
            return send_hndlr->current_folder;
        }
        else
        {
            send_hndlr = send_hndlr->next;
        }
    }
    return MMA_FOLDER_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_change_version_number_of_mms
 * DESCRIPTION
 *  Change Version number of the MMS.
 * PARAMETERS
 *  xml_file_path       [IN]        [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_change_version_number_of_mms(const U8 *xml_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Open the XML file and find the xml version tag and change the xml version. */
    FS_HANDLE xml_file_hnd = 0;
    U8 buffer[MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER] = {0, };
    U8 buffer_version[2] = {0, };
    S8 *str_pos = NULL;
    U32 result, size, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_change_version_number_of_mms\n");
    xml_file_hnd = FS_Open((const WCHAR*)xml_file_path, FS_READ_WRITE);

    if (!xml_file_hnd)
    {
        return FALSE;
    }
    else
    {
        if (FS_Read(xml_file_hnd, &buffer, MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER, &size) == FS_NO_ERROR)
        {
            /* Search for the xml Version tag and change the Verison number. */
            str_pos = strstr((S8*) buffer, XML_VERSION_TAG);
            if (str_pos != NULL)
            {
                len = strlen((PS8) buffer) - strlen((PS8) str_pos);
                result = (U32) (len + 1);
                FS_Seek(xml_file_hnd, result - 3, FS_FILE_BEGIN);
                FS_Read(xml_file_hnd, buffer_version, 2, &size);
                FS_Seek(xml_file_hnd, result - 3, FS_FILE_BEGIN);
                /* buffer_version[3]="\0"; */
                if ((buffer_version[0] == 49) && (buffer_version[1] == 54))
                {
                    FS_Write(xml_file_hnd, "17", 2, &size);
                    FS_Close(xml_file_hnd);
                    return TRUE;
                }
                if ((buffer_version[0] == 49) && (buffer_version[1] == 55))
                {
                    FS_Write(xml_file_hnd, "18", 2, &size);
                    FS_Close(xml_file_hnd);
                    return TRUE;
                }
                if ((buffer_version[0] == 49) && (buffer_version[1] == 56))
                {
                    FS_Write(xml_file_hnd, "16", 2, &size);
                    FS_Close(xml_file_hnd);
                    return TRUE;
                }

            }
            else
            {
                /* <mms_version>1.1</mms_version>; */
                FS_Close(xml_file_hnd);
                return FALSE;
            }

        }
        else
        {
            FS_Close(xml_file_hnd);
            return FALSE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_msg_number_state
 * DESCRIPTION
 *  Set the State of the MMS.
 * PARAMETERS
 *  current_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_msg_number_state(const umms_state_enum current_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_set_msg_number_state Msg_id = %d Curren State= %d\n",
                         g_current_mms_info_list->current_msg_id, current_state);
    g_current_mms_info_list->msg_num_state = current_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_number_state
 * DESCRIPTION
 *  Get the Message Number State.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
umms_state_enum mmi_umms_get_msg_number_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_msg_number_state Msg_id = %d Curren State= %d\n",
                         g_current_mms_info_list->current_msg_id, g_current_mms_info_list->msg_num_state);
    return g_current_mms_info_list->msg_num_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_free_req_handler_node
 * DESCRIPTION
 *  Free the Request Handler Node
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_free_req_handler_node(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_req_msg_handler_struct *temp_node = NULL;
    umms_req_msg_handler_struct *msg_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_free_req_handler_node Msg_id = %d Req_id = %d \n", msg_id, req_id);

    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;
    if (msg_hndlr != NULL)
    {
        while (msg_hndlr != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_free_req_handler_node Print List Msg_id = %d Req_id = %d Curren State= %d Current_folder = %d\n",
                                 msg_hndlr->msg_id, msg_hndlr->req_id, msg_hndlr->current_state,
                                 msg_hndlr->current_folder);

            msg_hndlr = msg_hndlr->next;
        }
    }
    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;

    if (msg_hndlr != NULL)
    {
        if ((msg_hndlr->msg_id == msg_id) && (msg_hndlr->req_id == req_id))
        {
            if (msg_hndlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_current_mms_info_list->g_umms_req_msg_hndlr);
                g_current_mms_info_list->g_umms_req_msg_hndlr = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_current_mms_info_list->g_umms_req_msg_hndlr = msg_hndlr->next;
                umms_free(msg_hndlr);
                msg_hndlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node = msg_hndlr;
            msg_hndlr = msg_hndlr->next;
            while (msg_hndlr != NULL)
            {
                if ((msg_hndlr->msg_id == msg_id) && (msg_hndlr->req_id == req_id))
                {
                    break;
                }
                else
                {
                    msg_hndlr = msg_hndlr->next;
                    temp_node = temp_node->next;
                }
            }
            if (msg_hndlr != NULL)
            {
                if ((msg_hndlr->msg_id == msg_id) && (msg_hndlr->req_id == req_id))
                {
                    if (msg_hndlr->next != NULL)
                    {
                        temp_node->next = msg_hndlr->next;
                        umms_free(msg_hndlr);
                        msg_hndlr = NULL;
                    }
                    else
                    {
                        /* The last node is to be deleted. */
                        temp_node->next = NULL;
                        umms_free(msg_hndlr);
                        msg_hndlr = NULL;
                    }
                }
            }
            else
            {
                /* The Msg id and the Req Id combination doesnot exist in the List */
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_free_send_handler_node
 * DESCRIPTION
 *  Free the send Handler Node.
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_free_send_handler_node(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *temp_node_send = NULL;
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_free_send_handler_node Msg_id = %d Req_id = %d \n", msg_id, req_id);

    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    if (send_msg_handlr != NULL)
    {
        while (send_msg_handlr != NULL)
        {

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_free_send_handler_node Print List Msg_id = %d Req_id = %d Send counter = %d Old Message_id = %d retry_version Count = %d current_state = %d intr State = %d current_folder = %d retry_version = %d\n",
                                 send_msg_handlr->msg_id, send_msg_handlr->req_id, send_msg_handlr->send_counter,
                                 send_msg_handlr->old_msg_id, send_msg_handlr->retry_version_count,
                                 send_msg_handlr->current_state, send_msg_handlr->intermediate_state,
                                 send_msg_handlr->current_folder, send_msg_handlr->retry_version);
            send_msg_handlr = send_msg_handlr->next;
        }
    }

    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    if (send_msg_handlr != NULL)
    {
        if ((send_msg_handlr->msg_id == msg_id) && (send_msg_handlr->req_id == req_id))
        {
            if (send_msg_handlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_dwnld_send_list->g_umms_send_msg_hndlr);
                g_dwnld_send_list->g_umms_send_msg_hndlr = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_dwnld_send_list->g_umms_send_msg_hndlr = send_msg_handlr->next;
                umms_free(send_msg_handlr);
                send_msg_handlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node_send = send_msg_handlr;
            send_msg_handlr = send_msg_handlr->next;
            while (send_msg_handlr != NULL)
            {
                if ((send_msg_handlr->msg_id == msg_id) && (send_msg_handlr->req_id == req_id))
                {
                    break;
                }
                else
                {
                    send_msg_handlr = send_msg_handlr->next;
                    temp_node_send = temp_node_send->next;
                }
            }
            if (send_msg_handlr != NULL)
            {
                if ((send_msg_handlr->msg_id == msg_id) && (send_msg_handlr->req_id == req_id))
                {
                    if (send_msg_handlr->next != NULL)
                    {   /* In between Nodes to be deleted */
                        temp_node_send->next = send_msg_handlr->next;
                        umms_free(send_msg_handlr);
                        send_msg_handlr = NULL;
                    }
                    else
                    {
                        /* The last node is to be deleted. */
                        temp_node_send->next = NULL;
                        umms_free(send_msg_handlr);
                        send_msg_handlr = NULL;
                    }
                }
            }
            else
            {
                /* The Msg id and the Req Id combination doesnot exist in the List */
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_free_send_node_with_msg_id
 * DESCRIPTION
 *  Free the send Handler Node.
 * PARAMETERS
 *  msg_id          [IN]        
 *  req_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_free_send_node_with_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *temp_node_send = NULL;
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_free_send_node_with_msg_id Msg_id = %d \n", msg_id);

    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    if (send_msg_handlr != NULL)
    {
        while (send_msg_handlr != NULL)
        {

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_free_send_node_with_msg_id Print List Msg_id = %d Req_id = %d Send counter = %d Old Message_id = %d retry_version Count = %d current_state = %d intr State = %d current_folder = %d retry_version = %d\n",
                                 send_msg_handlr->msg_id, send_msg_handlr->req_id, send_msg_handlr->send_counter,
                                 send_msg_handlr->old_msg_id, send_msg_handlr->retry_version_count,
                                 send_msg_handlr->current_state, send_msg_handlr->intermediate_state,
                                 send_msg_handlr->current_folder, send_msg_handlr->retry_version);
            send_msg_handlr = send_msg_handlr->next;
        }
    }

    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    if (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            if (send_msg_handlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_dwnld_send_list->g_umms_send_msg_hndlr);
                g_dwnld_send_list->g_umms_send_msg_hndlr = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_dwnld_send_list->g_umms_send_msg_hndlr = send_msg_handlr->next;
                umms_free(send_msg_handlr);
                send_msg_handlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node_send = send_msg_handlr;
            send_msg_handlr = send_msg_handlr->next;
            while (send_msg_handlr != NULL)
            {
                if (send_msg_handlr->msg_id == msg_id)
                {
                    break;
                }
                else
                {
                    send_msg_handlr = send_msg_handlr->next;
                    temp_node_send = temp_node_send->next;
                }
            }
            if (send_msg_handlr != NULL)
            {
                if (send_msg_handlr->msg_id == msg_id)
                {
                    if (send_msg_handlr->next != NULL)
                    {   /* In between Nodes to be deleted */
                        temp_node_send->next = send_msg_handlr->next;
                        umms_free(send_msg_handlr);
                        send_msg_handlr = NULL;
                    }
                    else
                    {
                        /* The last node is to be deleted. */
                        temp_node_send->next = NULL;
                        umms_free(send_msg_handlr);
                        send_msg_handlr = NULL;
                    }
                }
            }
            else
            {
                /* The Msg id and the Req Id combination doesnot exist in the List */
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_free_download_handler_node
 * DESCRIPTION
 *  Free the Downlaod Handler Node.
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_free_download_handler_node(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_download_msg_handler_struct *download_msg_hndlr = NULL;
    umms_download_msg_handler_struct *temp_node_download = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_free_download_handler_node Msg_id = %d Req_id = %d \n",
                         msg_id, req_id);

    download_msg_hndlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    if (download_msg_hndlr != NULL)
    {
        while (download_msg_hndlr != NULL)
        {

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[MMSAppMain.c] mmi_umms_free_download_handler_node Print List Msg_id = %d Req_id = %d Download Retry counter = %d current_state = %d \n",
                                 download_msg_hndlr->msg_id, download_msg_hndlr->req_id,
                                 download_msg_hndlr->retry_counter, download_msg_hndlr->current_state);
            download_msg_hndlr = download_msg_hndlr->next;
        }
    }

    download_msg_hndlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;

    if (download_msg_hndlr != NULL)
    {
        if (download_msg_hndlr->msg_id == msg_id)
        {
            if (download_msg_hndlr->next == NULL)
            {
                /* Means there is a single node and the first node matches */
                umms_free(g_dwnld_send_list->g_umms_dwnld_msg_hndlr);
                g_dwnld_send_list->g_umms_dwnld_msg_hndlr = NULL;
            }
            else
            {
                /* Means there are other nodes but the first node matches */
                g_dwnld_send_list->g_umms_dwnld_msg_hndlr = download_msg_hndlr->next;
                umms_free(download_msg_hndlr);
                download_msg_hndlr = NULL;
            }
        }
        else
        {
            /* Means the node is not the first One. Search for the node in the Linked List */
            temp_node_download = download_msg_hndlr;
            download_msg_hndlr = download_msg_hndlr->next;
            while (download_msg_hndlr != NULL)
            {
                if (download_msg_hndlr->msg_id == msg_id)
                {
                    break;
                }
                else
                {
                    download_msg_hndlr = download_msg_hndlr->next;
                    temp_node_download = temp_node_download->next;
                }
            }
            /* In between node needs to be deleted */
            if (download_msg_hndlr != NULL)
            {
                if (download_msg_hndlr->msg_id == msg_id)
                {
                    if (download_msg_hndlr->next != NULL)
                    {
                        temp_node_download->next = download_msg_hndlr->next;
                        umms_free(download_msg_hndlr);
                        download_msg_hndlr = NULL;
                    }
                    else
                    {
                        /* The last node is to be deleted. */
                        temp_node_download->next = NULL;
                        umms_free(download_msg_hndlr);
                        download_msg_hndlr = NULL;
                    }
                }
            }
            else
            {
                /* Node doesnot exist in the List */
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_more_flag_for_send
 * DESCRIPTION
 *  Update More Flag in Case of Send in Send Node.
 * PARAMETERS
 *  req_id      [IN]        
 *  is_more     [IN]        
 *  msg_id(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_more_flag_for_send(const U32 req_id, const kal_bool is_more)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_more_flag_for_send Req_id = %d \n", req_id);
    send_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_hndlr != NULL)
    {
        if (send_hndlr->req_id == req_id)
        {
            send_hndlr->more_data = is_more;
            break;
        }
        else
        {
            send_hndlr = send_hndlr->next;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_more_flag_from_send_list
 * DESCRIPTION
 *  Get more Flag from Send Handler Node.
 * PARAMETERS
 *  req_id      [IN]        
 *  msg_id(?)       [IN](?)
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_get_more_flag_from_send_list(const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_more_flag_from_send_list Req_id = %d \n", req_id);
    send_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_hndlr != NULL)
    {
        if (send_hndlr->req_id == req_id)
        {
            return send_hndlr->more_data;
        }
        else
        {
            send_hndlr = send_hndlr->next;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_xml_file_path_in_send_msg_hndlr
 * DESCRIPTION
 *  Update the XML file Path in the Send hanlder node.
 * PARAMETERS
 *  req_id              [IN]        
 *  xml_file_path       [IN]        [?]         [?]
 *  msg_id(?)           [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_xml_file_path_in_send_msg_hndlr(const U32 req_id, const U8 *xml_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_xml_file_path_in_send_msg_hndlr Req_id = %d \n", req_id);

    send_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_hndlr != NULL)
    {
        if (send_hndlr->req_id == req_id)
        {
            mmi_ucs2ncpy((PS8) send_hndlr->xml_file_path, (PS8) xml_file_path, 200);
            break;
        }
        else
        {
            send_hndlr = send_hndlr->next;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_xml_file_path_from_send_msg_hndlr
 * DESCRIPTION
 *  Get the XML file Path from the Send Handler Node.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_umms_get_xml_file_path_from_send_msg_hndlr(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_hndlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_xml_file_path_from_send_msg_hndlr Msg_id = %d \n", msg_id);
    send_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_hndlr != NULL)
    {
        if (send_hndlr->msg_id == msg_id)
        {
            return send_hndlr->xml_file_path;
        }
        else
        {
            send_hndlr = send_hndlr->next;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_de_init_req_handler_list
 * DESCRIPTION
 *  Deinit the Req uest Handler List.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_de_init_req_handler_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Free all the nodes from the Req handler List. */
    /* this API will be called on entering Idle Screen */

    umms_req_msg_handler_struct *msg_hndlr = NULL;
    umms_req_msg_handler_struct *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_de_init_req_handler_list\n");
    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;
    if (msg_hndlr == NULL)
    {
       return;
    }
	else
	{
		while (msg_hndlr->next != NULL)
		{
			temp_node = msg_hndlr;
			msg_hndlr = msg_hndlr->next;
			umms_free(temp_node);
		}
		if (msg_hndlr != NULL)
		{
			umms_free(msg_hndlr);
		}
	}
	g_current_mms_info_list->g_umms_req_msg_hndlr = NULL;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_de_init_send_handler_list
 * DESCRIPTION
 *  Deinit the Send Request Handler List.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_de_init_send_handler_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Free all the nodes from the Req handler List. */
    /* this API will be called on entering Idle Screen */

    umms_send_msg_handler_struct *msg_hndlr = NULL;
    umms_send_msg_handler_struct *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_de_init_send_handler_list\n");
    msg_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    if (msg_hndlr == NULL)
    {
       return;
    }
	else
	{
		while (msg_hndlr->next != NULL)
		{
			temp_node = msg_hndlr;
			msg_hndlr = msg_hndlr->next;
			umms_free(temp_node);
		}
		if (msg_hndlr != NULL)
		{
        umms_free(msg_hndlr);
    }
	}
	g_dwnld_send_list->g_umms_send_msg_hndlr = NULL;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_de_init_dwnld_handler_list
 * DESCRIPTION
 *  Deinit the Download uest Handler List.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_de_init_dwnld_handler_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Free all the nodes from the Req handler List. */
    /* this API will be called on entering Idle Screen */

    umms_download_msg_handler_struct *msg_hndlr = NULL;
    umms_download_msg_handler_struct *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_de_init_dwnld_handler_list\n");
    msg_hndlr = g_dwnld_send_list->g_umms_dwnld_msg_hndlr;
    if (msg_hndlr == NULL)
    {
       return;
    }
	else
	{
    while (msg_hndlr->next != NULL)
    {
        temp_node = msg_hndlr;
        msg_hndlr = msg_hndlr->next;
        umms_free(temp_node);
    }
    if (msg_hndlr != NULL)
    {
        umms_free(msg_hndlr);
    }
	}
	g_dwnld_send_list->g_umms_dwnld_msg_hndlr = NULL;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_de_init_new_msg_handler_list
 * DESCRIPTION
 *  Deinit the Download uest Handler List.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_de_init_new_msg_handler_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Free all the nodes from the Req handler List. */
    /* this API will be called on entering Idle Screen */

    mmi_umms_new_mms_list *msg_hndlr = NULL;
    mmi_umms_new_mms_list *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_de_init_new_msg_handler_list\n");
    msg_hndlr = g_new_mms_list;
    if (msg_hndlr == NULL)
    {
       return;
    }
	else
	{
		while (msg_hndlr->next != NULL)
		{
			temp_node = msg_hndlr;
			msg_hndlr = msg_hndlr->next;
			umms_free(temp_node);
		}
		if (msg_hndlr != NULL)
		{
			umms_free(msg_hndlr);
		}
	}
	g_new_mms_list = NULL;	
}

/* Ashwani Starts */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_hilite_index
 * DESCRIPTION
 *  Set the Hilighted Index
 * PARAMETERS
 *  hilite_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_hilite_index(const S32 hilite_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->hilite_index = (S32) hilite_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_hilite_index
 * DESCRIPTION
 *  Get the Hilighted Index
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_get_hilite_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_mms_info_list->hilite_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_menu_id
 * DESCRIPTION
 *  Set the Menu ID
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_get_menu_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_mms_info_list->menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_menu_id
 * DESCRIPTION
 *  Get the Menu ID
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_menu_id(const U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->menu_id = (U16) menu_id;
}

/* Ashwani Ends */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_global
 * DESCRIPTION
 *  Reset all the Global List.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_reset_global(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_reset_global\n");
	mmi_umms_de_init_req_handler_list();
    /* free full structure here */
    //MTI SUKRIT START
    if (g_current_mms_info_list->umms_mms_xml_msg != NULL)
    {
        mmi_umms_reset_xml_struct_msg(g_current_mms_info_list->umms_mms_xml_msg);
        umms_free(g_current_mms_info_list->umms_mms_xml_msg);
        g_current_mms_info_list->umms_mms_xml_msg = NULL;
    }
    //MTI SUKRIT END
    //MTI ASHWANI START
    if(g_current_mms_info_list->addr != NULL)
    {
        umms_free(g_current_mms_info_list->addr);
        g_current_mms_info_list->addr = NULL;
    }
    //MTI ASHWANI END
    memset(g_current_mms_info_list, 0, sizeof(umms_current_selected_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_all_status_icons
 * DESCRIPTION
 *  Reset all the Stats Icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_reset_all_status_icons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_reset_all_status_icons \n");
    if ((g_current_mms_info_list->folder_id == MMA_FOLDER_INBOX) ||
        (g_current_mms_info_list->folder_id == MMA_FOLDER_OUTBOX))
    {
        mmi_umms_show_mms_status_icon(UMMS_STATUS_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_handle_delete_all_mms
 * DESCRIPTION
 *  Handle Delete ALL from UM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_handle_delete_all_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_go_to_box_list_screen(); */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_handle_delete_all_mms FolderId = %d \n",
                         g_current_mms_info_list->folder_id);
    if (g_current_mms_info_list->folder_id == MMA_FOLDER_INBOX)
    {
        mmi_umms_stop_download_busy();
    }
    if (g_current_mms_info_list->folder_id == MMA_FOLDER_OUTBOX)
    {
        mmi_umms_stop_sending_busy();
    }
   // mmi_umms_update_storage_state(FALSE);
    mmi_umms_update_status_icon_indicator();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_mms_in_send_list
 * DESCRIPTION
 *  Check if the MMS is in the Send List.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_is_mms_in_send_list(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_is_mms_in_send_list Msg_id = %d \n", msg_id);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            return TRUE;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_creation_mode_restricted
 * DESCRIPTION
 *  Chekxc the creation mode of the MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_is_creation_mode_restricted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_creation_mode_enum creation_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_is_creation_mode_restricted \n");
    creation_mode = mmi_umms_compose_settings_creation_mode();
    if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_edit_fwd_mode
 * DESCRIPTION
 *  Entry Function for Edit and Forward.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_edit_fwd_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_entry_edit_fwd_mode \n");

    if (g_current_mms_info_list->uc_mode == MMA_MODE_FORWARD)
    {
        mmi_umms_start_uc_req(g_current_mms_info_list->current_msg_id, MMA_MODE_FORWARD);
    }
    else if (g_current_mms_info_list->uc_mode == MMA_MODE_EDIT)
    {
        mmi_umms_start_uc_req(g_current_mms_info_list->current_msg_id, MMA_MODE_EDIT);
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_mms_in_open_state
 * DESCRIPTION
 *  Check whethere MS Is in Opened State or not.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_is_mms_in_open_state(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_is_mms_in_open_state \n");

    if (g_current_mms_info_list->current_msg_id == msg_id)
    {
        return TRUE;
    }
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_any_mms_opened_in_box
 * DESCRIPTION
 *  Chekc if any MMS is opened in a Folder or Not.Required by JSR and AT.
 * PARAMETERS
 *  box_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_is_any_mms_opened_in_box(const mma_folder_enum box_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_is_any_mms_opened_in_box \n");
    if (g_current_mms_info_list->folder_id == box_id)
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_current_mms_opened_folder_id
 * DESCRIPTION
 *  Chekc if any MMS is opened in a Folder or Not.Required by JSR and AT.
 * PARAMETERS
 *  void
 *  box_id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_current_mms_opened_folder_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_current_mms_opened_folder_id \n");
    return g_current_mms_info_list->folder_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_retry_counter_send_req
 * DESCRIPTION
 *  Update the send counter..
 * PARAMETERS
 *  msg_id              [IN]        
 *  req_id              [IN]        
 *  send_counter        [IN]        
 *  box_id(?)           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_retry_counter_send_req(const U32 msg_id, const U32 req_id, const U32 send_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_retry_counter_send_req Msg_id = %d Req_id = %d send_counter = %d \n",
                         msg_id, req_id, send_counter);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            send_msg_handlr->send_counter = send_counter;
            break;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_send_retry_counter
 * DESCRIPTION
 *  Get the send counter..
 * PARAMETERS
 *  msg_id          [IN]        
 *  req_id          [IN]        
 *  box_id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_get_send_retry_counter(const U32 msg_id, const U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_update_retry_counter_send_req Msg_id = %d Req_id = %d \n",
                         msg_id, req_id);
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            return send_msg_handlr->send_counter;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_id_from_send_list
 * DESCRIPTION
 *  Get Msg Id from Send list
 * PARAMETERS
 *  void
 *  box_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_id_from_send_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    if (send_msg_handlr != NULL)
    {
        while (send_msg_handlr != NULL)
        {
            if (send_msg_handlr->send_counter <= UMMS_SEND_COUNTER_3)
            {

                mmi_umms_send_mms_msg(send_msg_handlr->msg_id);
            }
            send_msg_handlr = send_msg_handlr->next;
        }
    }

    if (send_msg_handlr == NULL)
    {
        //StopTimer(UMMS_SEND_TIMER);
        //   StartTimer(UMMS_SEND_TIMER, 60*1000, mmi_umms_get_msg_id_from_send_list);
    }
    return;
}

/* USB Handling needed for Sending */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_usb_mode_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_usb_mode_on(void)
{
    /* If USB is Plugged in Send a Cancel Send request for all MMS and change the state to E_STATE_USB_PLUG_IN */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_usb_mode_on  \n");
    g_is_usb_mode = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_usb_mode_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_usb_mode_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* As soon as the USB is plugged out check for all the MMS that has state== E_STATE_USB_PLUG_IN and resend the MMS */

    umms_send_msg_handler_struct *send_msg_hndlr = NULL;
    umms_state_enum current_state_of_msg_in_queue = E_STATE_NONE, intermediate_state_of_msg_in_queue = E_STATE_NONE;

    g_is_usb_mode = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_usb_mode_off  \n");
	  if(mms_is_ready())
    {
	    mmi_umms_get_msg_number_for_globals_update();
	
	    /*send_msg_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
	    while (send_msg_hndlr != NULL)
	    {
	        current_state_of_msg_in_queue = mmi_umms_get_state_of_msg_from_send_list(send_msg_hndlr->msg_id);
	        if (current_state_of_msg_in_queue == E_STATE_SEND_MSG)
	        {
	            intermediate_state_of_msg_in_queue = mmi_umms_get_intermediate_state_of_msg_from_send_list(send_msg_hndlr->msg_id);
	            if (intermediate_state_of_msg_in_queue == E_STATE_USB_PLUG_IN)
	            {
	                mmi_umms_send_mms_msg(send_msg_hndlr->msg_id);
	            }
	
	        }
	        send_msg_hndlr = send_msg_hndlr->next;
	    }*/
	  }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_is_more_mms_in_send_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_check_is_more_mms_in_send_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    umms_send_msg_handler_struct *send_msg_hndlr = NULL;
    umms_state_enum  intermediate_state_of_msg_in_queue = E_STATE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_msg_hndlr = g_dwnld_send_list->g_umms_send_msg_hndlr;
    while (send_msg_hndlr != NULL)
    {
        intermediate_state_of_msg_in_queue = mmi_umms_get_intermediate_state_of_msg_from_send_list(send_msg_hndlr->msg_id);
        if (intermediate_state_of_msg_in_queue != E_STATE_USB_PLUG_IN)
        {
            return KAL_TRUE;
        }
        send_msg_hndlr = send_msg_hndlr->next;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_umms_is_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_usb_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_global_mms_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_enum_retry_send_verion_enum mmi_umms_get_global_mms_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 mms_version = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_version = wap_custom_get_mms_version();

    switch (mms_version)
    {
        case 0:
            return UMMS_SEND_VERSION_NONE;
            break;
        case 1:
            return UMMS_SEND_VESRION_1_1;
            break;
        case 2:
            return UMMS_SEND_VESRION_1_2;
            break;
        case 3:
            return UMMS_SEND_VESRION_1_0;
            break;
        default:
            MMI_ASSERT(0);
            break;

    }
    return UMMS_SEND_VERSION_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_media_info
 * DESCRIPTION
 *  Sets the pointer of Media Info object in Save Object
 * PARAMETERS
 *  media_info      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_media_info(mmi_mv_object_struct const *const media_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->media_info = (mmi_mv_object_struct*) media_info;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_media_info
 * DESCRIPTION
 *  Gets the pointer of Media Info object in Save Object
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_mv_object_struct *mmi_umms_get_media_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_mms_info_list->media_info;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_src_file_name
 * DESCRIPTION
 *  Gets the pointer of Virtual File Name in Save Object
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_get_src_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_mms_info_list->src_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_src_file_name
 * DESCRIPTION
 *  Sets the pointer of Virtual File Name in Save Object
 * PARAMETERS
 *  src_file_name               [IN]        
 *  virtual_file_name(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_src_file_name(U16 const *const src_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->src_file_name = (U16*) src_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_virtual_file_name
 * DESCRIPTION
 *  Sets the pointer of Virtual File Name in Save Object
 * PARAMETERS
 *  virtual_file_name       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_virtual_file_name(U16 const *const virtual_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->virtual_file_name = (U16*) virtual_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_current_obj_drm_type
 * DESCRIPTION
 *  Reset current object DRM Type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_umms_reset_current_obj_drm_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->obj_drm_type = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_current_obj_drm_type
 * DESCRIPTION
 *  Set Current Object's DRM Type
 * PARAMETERS
 *  drm_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_umms_set_current_obj_drm_type(U8 drm_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->obj_drm_type = drm_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_current_obj_drm_type
 * DESCRIPTION
 *  Get Current Object's DRM Type
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
 U8 mmi_umms_get_current_obj_drm_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_mms_info_list->obj_drm_type;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_virtual_file_name
 * DESCRIPTION
 *  Gets the pointer of Virtual File Name in Save Object
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_get_virtual_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_mms_info_list->virtual_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_media_file_path
 * DESCRIPTION
 *  Sets the pointer of Object File Path in Save Object
 * PARAMETERS
 *  media_file_path     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_media_file_path(U16 const *const media_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->media_file_path = (U16*) media_file_path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_media_file_path
 * DESCRIPTION
 *  Gets the pointer of Object File Path in Save Object
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_get_media_file_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_mms_info_list->media_file_path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_progress_scr_id
 * DESCRIPTION
 *  Sets the Progress Screen ID
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_progress_scr_id(umms_progress_screen_enum const scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->progres_screen_id = (umms_progress_screen_enum) scr_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_to_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_umms_get_to_number(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_send_msg_handler_struct *send_msg_handlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_get_to_number Msg_id= %d  \n", msg_id);

    send_msg_handlr = g_dwnld_send_list->g_umms_send_msg_hndlr;

    while (send_msg_handlr != NULL)
    {
        if (send_msg_handlr->msg_id == msg_id)
        {
            return (U8*)send_msg_handlr->to_address;
            break;
        }
        else
        {
            send_msg_handlr = send_msg_handlr->next;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_bearer_type_csd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_umms_is_bearer_type_csd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    nvram_profile_content_struct *activeProfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_is_bearer_type_csd  \n");
    activeProfile = mmi_brw_prof_get_activated_mms_profile();
    if (mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_CSD)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_is_bearer_type_csd  TRUE \n");
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_status_icon_at_boot_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_status_icon_at_boot_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMain.c] mmi_umms_set_status_icon_at_boot_up \n");
    mmi_umms_set_msg_number_state(E_STATE_GET_NUM_REQ_AT_START_UP);
    mmi_umms_update_status_icon_indicator();
}


/*****************************************************************************
 * FUNCTION
 *  umms_get_current_utc_time
 * DESCRIPTION
 *  returns current time
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 umms_get_current_utc_time(void)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 timeSecs;
    FLOAT tz;
    U32 tzdiff = 0;
    MYTIME t;
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dt_get_secure_time(&t);
    timeSecs = mmi_dt_mytime_2_utc_sec(&t, TRUE);
    tz = mmi_dt_get_tz();
    if (tz < 0)
    {
        time = applib_conv_tz_to_mytime(tz * (-1));
    }
    else
    {
        time = applib_conv_tz_to_mytime(tz);
    }
    tzdiff = time.nHour * 3600 + time.nMin * 60 + time.nSec;
    if (tz > 0)
    {
        return (U32)(timeSecs - tzdiff);
    }
    else
    {
        return (U32)(timeSecs + tzdiff);
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MTK_TARGET__ */ 
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
#endif /* __MTK_TARGET__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_object_file_handle
 * DESCRIPTION
 *  Sets Object File Handle in Save Object
 * PARAMETERS
 *  file_handle     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_object_file_handle(FS_HANDLE file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->file_handle = file_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_close_object_file_handle
 * DESCRIPTION
 *  Closes Object File Handle in Save Object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_close_object_file_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_mms_info_list->file_handle > FS_NO_ERROR)
    {
        FS_Close(g_current_mms_info_list->file_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_rr_dr_status
 * DESCRIPTION
 *  Set the read report/delivery report status
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_rr_dr_status(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_mms_info_list->rr_dr_status = status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_rr_dr_status
 * DESCRIPTION
 *  Get the read report/delivery report status
 * PARAMETERS
 *  void
 *  status(?)       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_umms_get_rr_dr_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_mms_info_list->rr_dr_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_downloading_state
 * DESCRIPTION
 *  Check Downloading State
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_check_downloading_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_current_mms_info_list->msg_status == MMA_MSG_STATUS_WAITING_DOWNLOADING)
        || (g_current_mms_info_list->msg_status == MMA_MSG_STATUS_DOWNLOADING))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_xml_struct_msg
 * DESCRIPTION
 *  This functions reset the resourses held by xml generation process.
 * PARAMETERS
 *  mms_xml_msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_reset_xml_struct_msg(mmi_umms_xml_msg_struct *mms_xml_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_slide_struct *slide, *curr_slide;
    mmi_umms_addr_struct *to, *curr_to;
    mmi_umms_addr_struct *cc, *curr_cc;
    mmi_umms_addr_struct *bcc, *curr_bcc;
    mmi_umms_addr_struct *from;
    mmi_umms_attachment_info_struct *attachment, *curr_attachment;
    //U8 xml_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide = mms_xml_msg->slide_head;
    to = mms_xml_msg->to_head;
    cc = mms_xml_msg->cc_head;
    bcc = mms_xml_msg->bcc_head;
    from = mms_xml_msg->from;
    attachment = mms_xml_msg->attachment_head;

    while (slide)
    {
        ASSERT(0);
        if (slide->text.object)
        {
            if (slide->text.object->file_path)
            {
                FS_Delete(slide->text.object->file_path);
                umms_free(slide->text.object->file_path);
                /* slide->text.object->file_path = NULL; */
            }
            if (slide->text.object->file_name)
            {
                umms_free(slide->text.object->file_name);
                /* slide->text.object->file_name = NULL; */
            }
            if (slide->text.object->content_id)
            {
                umms_free(slide->text.object->content_id);
                /* slide->text.object->content_id = NULL; */
            }
            if (slide->text.object->content_location)
            {
                umms_free(slide->text.object->content_location);
                /* slide->text.object->content_location = NULL; */
            }
            if (slide->text.object->mime_type)
            {
                umms_free(slide->text.object->mime_type);
                /* slide->text.object->mime_type = NULL; */
            }
            umms_free(slide->text.object);

            //                      slide->text.object->next = NULL;
            //                      slide->text.object->previous = NULL;
        }
        if (slide->text.alt_str)
        {
            umms_free(slide->text.alt_str);
        }

        if (slide->image.object)
        {
            if (slide->image.object->file_path)
            {
                FS_Delete(slide->image.object->file_path);
                umms_free(slide->image.object->file_path);
                /* slide->image.object->file_path = NULL; */
            }
            if (slide->image.object->file_name)
            {
                umms_free(slide->image.object->file_name);
                /* slide->image.object->file_name = NULL; */
            }
            if (slide->image.object->content_id)
            {
                umms_free(slide->image.object->content_id);
                /* slide->image.object->content_id = NULL; */
            }
            if (slide->image.object->content_location)
            {
                umms_free(slide->image.object->content_location);
                /* slide->image.object->content_location = NULL; */
            }
            if (slide->image.object->mime_type)
            {
                umms_free(slide->image.object->mime_type);
                /* slide->image.object->mime_type = NULL; */
            }
            umms_free(slide->image.object);

            //                      slide->image.object->next = NULL;
            //                      slide->image.object->previous = NULL;
        }
        if (slide->image.alt_str)
        {
            umms_free(slide->image.alt_str);
        }

        if (slide->audio.object)
        {
            if (slide->audio.object->file_path)
            {
                FS_Delete(slide->audio.object->file_path);
                umms_free(slide->audio.object->file_path);
                /* slide->audio.object->file_path = NULL; */
            }
            if (slide->audio.object->file_name)
            {
                umms_free(slide->audio.object->file_name);
                /* slide->audio.object->file_name = NULL; */
            }
            if (slide->audio.object->content_id)
            {
                umms_free(slide->audio.object->content_id);
                /* slide->audio.object->content_id = NULL; */
            }
            if (slide->audio.object->content_location)
            {
                umms_free(slide->audio.object->content_location);
                /* slide->audio.object->content_location = NULL; */
            }
            if (slide->audio.object->mime_type)
            {
                umms_free(slide->audio.object->mime_type);
                /* slide->audio.object->mime_type = NULL; */
            }
            umms_free(slide->audio.object);
            //                      slide->audio.object->next = NULL;
            //                      slide->audio.object->previous = NULL;

        }
        if (slide->audio.alt_str)
        {
            umms_free(slide->audio.alt_str);
        }

        if (slide->video.object)
        {
            if (slide->video.object->file_path)
            {
                FS_Delete(slide->video.object->file_path);
                umms_free(slide->video.object->file_path);
                /* slide->video.object->file_path = NULL; */
            }
            if (slide->video.object->file_name)
            {
                umms_free(slide->video.object->file_name);
                /* slide->video.object->file_name = NULL; */
            }
            if (slide->video.object->content_id)
            {
                umms_free(slide->video.object->content_id);
                /* slide->video.object->content_id = NULL; */
            }
            if (slide->video.object->content_location)
            {
                umms_free(slide->video.object->content_location);
                /* slide->video.object->content_location = NULL; */
            }
            if (slide->video.object->mime_type)
            {
                umms_free(slide->video.object->mime_type);
                /* slide->video.object->mime_type = NULL; */
            }
            umms_free(slide->video.object);
            //                      slide->video.object->next = NULL;
            //                      slide->video.object->previous = NULL;

        }

        if (slide->video.alt_str)
        {
            umms_free(slide->video.alt_str);
        }

        curr_slide = slide;
        slide = slide->next;
        umms_free(curr_slide);
        //              curr_slide->next = NULL;
        //              curr_slide->previous = NULL;
    }
    while (to)
    {
        if (to->addr)
        {
            umms_free(to->addr);
        }
        curr_to = to;
        to = to->next;
        umms_free(curr_to);
    }
    while (cc)
    {
        if (cc->addr)
        {
            umms_free(cc->addr);
        }
        curr_cc = cc;
        cc = cc->next;
        umms_free(curr_cc);
    }
    while (bcc)
    {
        if (bcc->addr)
        {
            umms_free(bcc->addr);
        }
        curr_bcc = bcc;
        bcc = bcc->next;
        umms_free(curr_bcc);
    }
    while (from)
    {
        mmi_umms_addr_struct *t;
        if (from->addr)
        {
            umms_free(from->addr);
        }
        t = from;
        from = from->next;
        umms_free(t);
    }
    while (attachment)
    {
        ASSERT(0);
        if (attachment->object)
        {
            if (attachment->object->file_path)
            {
                //FS_Delete(attachment->object->file_path);
                umms_free(attachment->object->file_path);
                /* attachment->object->file_path = NULL; */
            }
            if (attachment->object->file_name)
            {
                umms_free(attachment->object->file_name);
                /* attachment->object->file_name = NULL; */
            }
            if (attachment->object->content_id)
            {
                umms_free(attachment->object->content_id);
                /* attachment->object->content_id = NULL; */
            }
            if (attachment->object->content_location)
            {
                umms_free(attachment->object->content_location);
                /* attachment->object->content_location = NULL; */
            }
            if (attachment->object->mime_type)
            {
                umms_free(attachment->object->mime_type);
                /* attachment->object->mime_type = NULL; */
            }
            umms_free(attachment->object);
        }

        curr_attachment = attachment;
        attachment = attachment->next;
        umms_free(curr_attachment);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_message_type
 * DESCRIPTION
 *  return current msg type
 * PARAMETERS
 *  void    
 * RETURNS
 *  mma_msg_type_enum
 *****************************************************************************/

mma_msg_type_enum mmi_umms_get_message_type(void)
{

    return (mma_msg_type_enum)g_current_mms_info_list->msg_type;
}
UmMsgBoxType mmi_umms_get_current_msg_box_type(void)
{
	return g_um_box_selected;
}

U32 mmi_umms_get_current_highlighted_msg_index(void)
{
	return g_msg_index;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_all
 * DESCRIPTION
 *  reset All list
 * PARAMETERS
 *  void    
 * RETURNS
 *  mma_msg_type_enum
 *****************************************************************************/
void mmi_umms_reset_all(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Show a PopUp for Terminate Event and Go back to Idle Screen.*/

	if(!mmi_umms_is_in_call())
	{
			if (IsScreenPresent(SCR_ID_UM_MAIN))
	    {
          DisplayPopup(
              (PU8) GetString(STR_ID_UMMS_TERMINATED),
              IMG_GLOBAL_WARNING,
              1,
              MMI_UMMS_POPUP_TIME,
              WARNING_TONE);
      }
      else
      {
          // Do Nothing
      }
	}
	
	if (IsScreenPresent(SCR_ID_UM_MAIN))
	{
		DeleteNScrId(SCR_ID_UM_MAIN);
		/* EntryIdleScreen Shall Not be a good Option over Here */
	}

	
	mmi_umms_free_all_nodes();
	mmi_umms_stop_download_busy();
	mmi_umms_stop_sending_busy();
	mmi_umms_update_status_icon_on_number_rsp();
	mmi_umms_reset_global();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_free_all_nodes
 * DESCRIPTION
 *  reset All list
 * PARAMETERS
 *  void    
 * RETURNS
 *  mma_msg_type_enum
 *****************************************************************************/
void mmi_umms_free_all_nodes(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* 1. Free the Send handler Node */
	/*   2. Free the Download List */
	/*   3. Free the New Message Handler List */
	/*   4. Free the Request Handler List */
	
	mmi_umms_de_init_req_handler_list();
	mmi_umms_de_init_send_handler_list();
	mmi_umms_de_init_dwnld_handler_list();
	mmi_umms_de_init_new_msg_handler_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_reply_as_sms
 * DESCRIPTION
 *  Entry for reply by SMS
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_reply_as_sms(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_entry_write_struct *sendData = (mmi_frm_sms_api_entry_write_struct *)umms_malloc(sizeof(mmi_frm_sms_api_entry_write_struct));
	  U8 from_str_ascii[MMA_MAX_ADDR_LEN]={0,};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

    sendData->string = NULL;
    sendData->stringlength = 0;
    sendData->dcs = SMSAL_UCS2_DCS;
    sendData->flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
    /* Get the from Address from the Global struct and Convert it in Ascii */
    mmi_ucs2_to_asc((S8*)from_str_ascii,(S8*)g_current_mms_info_list->from_address);
    mmi_umms_entry_dummy_screen();
    mmi_umms_go_to_box_list_screen();
    sendData->ascii_addr = (U8 *)from_str_ascii;
    mmi_frm_sms_api_entry_write_msg(sendData);
		umms_free(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_download_size
 * DESCRIPTION
 *  Set the download size for Notification
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_download_size(U32 size)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_current_mms_info_list->dwnld_size = size;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_reported_msg_id
 * DESCRIPTION
 *  Get the reported Message Id from XML
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_reported_msg_id(U32 reported_msg_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_current_mms_info_list->reported_message_id = reported_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_number_for_globals_update
 * DESCRIPTION
 *  Update the gloabals for Message Number.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_number_for_globals_update(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_msg_number_state(E_STATE_GET_NUM_REQ_FOR_GLOBAL_UPDATE);
    mmi_umms_get_message_number_request();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_umms_screens
 * DESCRIPTION
 *  Delete MMS Screens (general API anyone can use).
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_umms_screens(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_VIEWER_PROGRESS_SCREEN);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_VIEWER);
    DeleteScreenIfPresent(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
    DeleteScreenIfPresent(SCR_ID_UMMS_NOTIFICATION);
    DeleteScreenIfPresent(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_UMMS_MESSAGE_STATUS);
    DeleteScreenIfPresent(SCR_ID_UMMS_JAVA_OPTIONS);
    mmi_umms_reset_global();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_get_content_or_header_req_state
 * DESCRIPTION
 *  Check state of the Current Message.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_is_get_content_or_header_req_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_state_enum current_state = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    current_state = mmi_umms_get_state_of_msg_from_req_hndlr_list(g_current_mms_info_list->current_msg_id);
    if((current_state == E_STATE_GET_CONTENT_FOR_MSG_INFO)||
       (current_state == E_STATE_NORMAL_MSG_OPTION_KEY) ||
       (current_state == E_STATE_NORMAL_MSG))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_state_of_msg_from_req_hndlr_list
 * DESCRIPTION
 *  Get Current State of the MSg from req handler list.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
umms_state_enum mmi_umms_get_state_of_msg_from_req_hndlr_list(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_req_msg_handler_struct *msg_hndlr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_req_hndlr_list  Msg_id = %d \n",
                         msg_id);

    msg_hndlr = g_current_mms_info_list->g_umms_req_msg_hndlr;
    if (msg_hndlr != NULL)
    {
        while (msg_hndlr != NULL)
        {
            if (msg_hndlr->msg_id == msg_id) 
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[MMSAppMain.c] mmi_umms_get_state_of_msg_from_req_hndlr_list Current State in Req handler=%d \n",
                                     msg_hndlr->current_state);
                return msg_hndlr->current_state;
            }
            else
            {
                msg_hndlr = msg_hndlr->next;
            }
        }

    }
    return E_STATE_NONE;
}

#endif /* __MMI_MMS_2__ */ 
// #endif

