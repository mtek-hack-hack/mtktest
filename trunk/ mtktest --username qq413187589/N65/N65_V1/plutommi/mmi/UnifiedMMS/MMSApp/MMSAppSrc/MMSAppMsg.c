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
 *  MMSAppMsg.C
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_include.h"
#ifdef __MMI_MMS_2__
#include "ProtocolEvents.h"
#include "MMSAppResDef.h"
#include "MMSAppGprot.h"
#include "MMSAppprot.h"
// #include "FileSystemDef.h"
#include "FileManagerGProt.h"
#include "wap_ps_struct.h"
#include "app_asyncfile.h"
#include "custom_wap_config.h"
#include "xml_def.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif 
#include "MMSMsgCommonProt.h"
#include "MMSXMLDef.h"
#include "CallManagementGProt.h"
#include "IdleAppProt.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_header_request
 * DESCRIPTION
 *  Get Header Info Request.
 * PARAMETERS
 *  msg_id              [IN]        
 *  current_state       [IN]        
 *  current_folder      [IN]        
 *  mode(?)             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_header_request(
        const U32 msg_id,
        const umms_state_enum current_state,
        const mma_folder_enum current_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_info_req_struct *msgSet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_header_request \n");

    msgSet = (wap_mma_get_msg_info_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_msg_info_req_struct));

    msgSet->req_id = wap_mma_get_request_id();
    msgSet->app_id = MMA_APP_ID_MMS_APP;
    msgSet->msg_id = msg_id;
    umms_add_to_msg_hndlr_list(msg_id, msgSet->req_id, current_state);
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_MSG_INFO_REQ, (oslParaType*) msgSet, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_header_info_rsp
 * DESCRIPTION
 *  Read the response of Get Header.
 * PARAMETERS
 *  inMsg               [?]         
 *  msg_index(?)        [IN]        
 *  msg_box_type(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_header_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_msg_header_info_rsp \n");
    mmi_umms_get_msg_header(inMsg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_start_uc_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_start_uc_req(const U32 msg_id, const mma_app_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_uc_start_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_start_uc_req \n");
    req = (wap_mma_uc_start_req_struct*) OslConstructDataPtr(sizeof(wap_mma_uc_start_req_struct));
    req->app_id = MMA_APP_ID_MMS_APP;
    req->mode = mode;
    req->msg_id = msg_id;
    mmi_umms_entry_dummy_screen();
    mmi_umms_go_to_box_list_screen();
    mmi_umms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_WAP_MMA_UC_START_REQ, (oslParaType*) req, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_uc_start_rsp
 * DESCRIPTION
 *  Response for Start UC.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_uc_start_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_uc_start_rsp_struct *rsp = (wap_mma_uc_start_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_start_uc_req \n");
    if (rsp->result != MMA_RESULT_OK)
    {
        mmi_umms_show_error_pop_up(rsp->result);
    }
    else
    {
        mmi_umms_go_to_box_list_screen();
        /* GoBackHistory(); */
    }
}

/* Start for Send and Receive Delete All Ind and Res to/from UM */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_delete_all_ind_to_um
 * DESCRIPTION
 *  Send Delete All indication to UM Req.
 * PARAMETERS
 *  folder_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_delete_all_ind_to_um(const mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_delete_all_ind_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_send_delete_all_ind_to_um \n");

    if (mmi_umms_convert_mma_folder_to_umbox_type(folder_id) == UM_MSG_BOX_TYPE_USRDEF_TEMPLATES)
    {
        /* Rajbir */
        mmi_umms_set_progress_screen();
        mmi_umms_delete_all_user_def_template_req();
        return;
    }
    if(GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
    {
    mmi_umms_entry_dummy_screen();
    }
    mmi_umms_delete_progress_screen();
    mmi_umms_go_to_box_list_screen();

    req = (mmi_um_delete_all_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_delete_all_ind_struct));

    req->msg_type = UM_MSG_TYPE_MMS;
    req->msg_box_type = mmi_umms_convert_mma_folder_to_umbox_type(folder_id);

    mmi_umms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_DELETE_ALL_IND, (oslParaType*) req, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_delete_all_rsp_from_um
 * DESCRIPTION
 *  Response of Delete All from Um.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_delete_all_rsp_from_um(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // mmi_um_delete_all_res_struct *rsp = (mmi_um_delete_all_res_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_delete_all_rsp_from_um \n");
    //mmi_umms_set_memory_full(FALSE);
    mmi_umms_update_status_icon_indicator();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_mms_before_sending
 * DESCRIPTION
 *  Save the MMS before Sending in Outbox Folder. A dummy Api.
 * PARAMETERS
 *  msg_id      [IN]        
 *  current_folder(?)               [IN](?)
 *  current_state(?)                [IN](?)
 *  intermediate_state(?)           [IN](?)
 *  folder_to_be_moved_to(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_mms_before_sending(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_save_mms_before_sending \n");
    mmi_umms_save_req(
        E_STATE_SAVE_MMS_FROM_UC,
        E_STATE_SEND_MSG,
        msg_id,
        MMA_FOLDER_DRAFT,   /* Box in which the MMS needs to be moved */
        MMA_FOLDER_DRAFT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_req
 * DESCRIPTION
 *  Save request for MMA.
 * PARAMETERS
 *  intermediate_state          [IN]        
 *  current_state               [IN]        
 *  msg_id                      [IN]        
 *  folder_to_be_moved_to       [IN]        
 *  current_folder              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_req(
        const umms_state_enum intermediate_state,
        const umms_state_enum current_state,
        const U32 msg_id,
        const mma_folder_enum folder_to_be_moved_to,
        const mma_folder_enum current_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_save_req Intr State = %d Current State = %d msg_id = %d folder_to_save = %d current_folder = %d\n",
                         intermediate_state, current_state, msg_id, folder_to_be_moved_to, current_folder);

    msg_req = (wap_mma_save_req_struct*) OslConstructDataPtr(sizeof(wap_mma_save_req_struct));
    msg_req->app_id = MMA_APP_ID_MMS_APP;
    msg_req->req_id = wap_mma_get_request_id();
    msg_req->msg_id = msg_id;
    msg_req->box = folder_to_be_moved_to;
    if ((intermediate_state == E_STATE_SAVE_AFTER_SEND) || (intermediate_state == E_STATE_SAVE_NEW_MMS))
    {
        mmi_umms_update_intermediate_send_req(msg_req->msg_id, msg_req->req_id, intermediate_state);
    }
    else
    {
        mmi_umms_add_to_list(msg_id, msg_req->req_id, current_state, intermediate_state);
    }

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SAVE_REQ, (oslParaType*) msg_req, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_save_rsp
 * DESCRIPTION
 *  Save response from MMA,
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_save_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *rsp = (wap_mma_rsp_struct*) inMsg;
    umms_state_enum current_state = E_STATE_NONE, intermediate_state = E_STATE_NONE;
    mma_folder_enum folder_id = MMA_FOLDER_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_state = mmi_umms_get_state_of_msg_from_all_the_lists(rsp->msg_id, rsp->req_id);
    folder_id = mmi_umms_get_folder_id_from_all_msg_handler(rsp->msg_id, rsp->req_id);

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_get_save_rsp Result = %d current_state = %d Folder_id = %d\n",
                         rsp->result, current_state, folder_id);

    if (rsp->result == MMA_RESULT_OK)
    {
        mmi_umms_update_status_icon_indicator();
        switch (current_state)
        {
            case E_STATE_MOVE_MSG:  /* For Normal Move */
                mmi_umms_free_req_handler_node(rsp->msg_id, rsp->req_id);
                if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
                    mmi_umms_show_done_pop_up(E_STATE_SAVE_MSG);
                }
                else
                {
                    /* mmi_umms_entry_dummy_screen(); */
                }
                mmi_umms_delete_progress_screen();
                mmi_umms_go_to_box_list_screen();
                break;
            case E_STATE_SEND_MSG:  /* For Sending */
                intermediate_state = mmi_umms_get_intermediate_state_of_msg_from_send_list(rsp->msg_id);
                switch (intermediate_state)
                {
                    case E_STATE_SAVE_BEFORE_SEND:
                        mmi_umms_update_retry_counter_send_req(rsp->msg_id, rsp->req_id, 1);
                        if(GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                        {
                        mmi_umms_entry_dummy_screen();
                        }
                        mmi_umms_delete_progress_screen();
                        mmi_umms_go_to_box_list_screen();
                        GoBackHistory();
                        mmi_umms_send_mms_msg(rsp->msg_id);
                        break;
                    case E_STATE_SAVE_AFTER_SEND:
                        mmi_umms_free_send_handler_node(rsp->msg_id, rsp->req_id);
						mmi_um_umms_highlight_mms_message_ind();
                        if(folder_id == 0)
                        {
                            mmi_umms_um_refresh_ind(MMA_FOLDER_OUTBOX);
                            mmi_umms_um_refresh_ind(MMA_FOLDER_SENT);
                        }
                        else
                        {
                        mmi_umms_um_refresh_ind(folder_id);
                        }
                        break;
                    case E_STATE_SAVE_MMS_FROM_UC:
                        mmi_umms_free_send_handler_node(rsp->msg_id, rsp->req_id);
                        mmi_umms_save_req(
                            E_STATE_SAVE_BEFORE_SEND,
                            E_STATE_SEND_MSG,
                            rsp->msg_id,
                            MMA_FOLDER_OUTBOX,
                            MMA_FOLDER_DRAFT);
                        break;
                    case E_STATE_SAVE_NEW_MMS:
                        mmi_umms_update_retry_counter_send_req(rsp->msg_id, rsp->req_id, 1);
                        mmi_umms_send_mms_msg(rsp->msg_id);
                        mmi_umms_um_refresh_ind(folder_id);
                        break;
                    default:
                        /* Do Nothing as this might be a case that the case of End Key press on Call Screen
                           and the Req handler being freed */
                        break;

                }
                break;
            case E_STATE_SAVE_MSG:  /* For Save as Template */
                mmi_umms_free_req_handler_node(rsp->msg_id, rsp->req_id);
                if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
                    mmi_umms_show_done_pop_up(E_STATE_SAVE_MSG);
                }
                else
                {
                    /* mmi_umms_entry_dummy_screen(); */
                }
                mmi_umms_delete_progress_screen();
                mmi_umms_go_to_box_list_screen();
                /* GoBackHistory(); */
                break;
            default:
                /* Do Nothing as this might be a case that the case of End Key press on Call Screen
                   and the Req handler being freed */
                break;
        }
    }
    else
    {   /* Save Failed */
        switch (current_state)
        {
            case E_STATE_MOVE_MSG:
            case E_STATE_SAVE_MSG:
                mmi_umms_free_req_handler_node(rsp->msg_id, rsp->req_id);
                if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
                    mmi_umms_show_error_pop_up(rsp->result);
                }
                mmi_umms_go_to_box_list_screen();
                break;
            case E_STATE_SEND_MSG:
                mmi_umms_reset_mms_sending_busy();
                if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
                    mmi_umms_show_error_in_send_pop_up(rsp->msg_id,NULL);
                }
                mmi_umms_free_send_handler_node(rsp->msg_id, rsp->req_id);
                break;
            default:
                /* Do Nothing as this might be a case that the case of End Key press on Call Screen
                   and the Req handler being freed */
                break;
        }
    }
}

/* End for Send and Receive Delete All Ind and Res to/from UM */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_hndl_save_rsp_to_uc
 * DESCRIPTION
 *  handling of Save response from Uc
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_hndl_save_rsp_to_uc(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result == MMA_RESULT_OK)
    {
        mmi_umms_update_status_icon_indicator();
    }
}

/* Start for Delete Request and Response TO MMA */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_req
 * DESCRIPTION
 *  Delete Req to MMA.
 * PARAMETERS
 *  intermediate_state      [IN]        
 *  current_state           [IN]        
 *  msg_id                  [IN]        
 *  folder_id               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_req(
        const umms_state_enum intermediate_state,
        const umms_state_enum current_state,
        const U32 msg_id,
        const mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_delete_req \n");

    req = (wap_mma_delete_req_struct*) OslConstructDataPtr(sizeof(wap_mma_delete_req_struct));
    req->app_id = MMA_APP_ID_MMS_APP;
    req->req_id = wap_mma_get_request_id();
    req->msg_id = msg_id;
    req->box = folder_id;

    /* Decide upon the state in which list this needs to be added. */
    if (intermediate_state == E_STATE_DELETE_AFTER_SAVE_SEND)
    {
        mmi_umms_update_intermediate_send_req(req->msg_id, req->req_id, intermediate_state);
    }
    else
    {
        mmi_umms_add_to_list(req->msg_id, req->req_id, current_state, E_STATE_NONE);
    }
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_DELETE_REQ, (oslParaType*) req, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_delete_rsp
 * DESCRIPTION
 *  Delete Response from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_delete_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    umms_state_enum current_state = E_STATE_NONE;

    wap_mma_rsp_struct *rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_state = mmi_umms_get_state_of_msg_from_all_the_lists(rsp->msg_id, rsp->req_id);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_get_msg_delete_rsp Result = %d Current State = %d \n",
                         rsp->result, current_state);
    /* Based on the Current State decide wether to Show the Pop Up or not. */

    if (rsp->result == MMA_RESULT_OK)
    {

        if (current_state != E_STATE_SEND_MSG)
        {
            if (current_state == E_STATE_DELETE_AFTER_NEW_MSG_CREATION)
            {
                mmi_umms_free_req_handler_node(rsp->msg_id, rsp->req_id);
            }
            else
            {
                mmi_umms_free_req_handler_node(rsp->msg_id, rsp->req_id);
                if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
                    mmi_umms_show_done_pop_up(current_state);
                }
                else
                {
                    if(!mmi_umms_is_in_call())
                    {
                     mmi_umms_show_done_pop_up(current_state);
                }
                }
                mmi_umms_delete_umms_screens();
                mmi_umms_set_msg_number_state(E_STATE_GET_NUM_REQ_INTERMEDATE_MSG);
                //mmi_umms_set_memory_full(FALSE);
                mmi_umms_update_status_icon_indicator();
            }
        }
        else
        {
            if (current_state == E_STATE_SEND_MSG)
            {
                mmi_umms_free_send_handler_node(rsp->msg_id, rsp->req_id);
                mmi_umms_um_refresh_ind(MMA_FOLDER_OUTBOX);
            }
        }
    }
    else
    {
        if (current_state != E_STATE_SEND_MSG)
        {
            if (current_state == E_STATE_DELETE_AFTER_NEW_MSG_CREATION)
            {
                mmi_umms_free_req_handler_node(rsp->msg_id, rsp->req_id);
                /* To be Decided what do if the Old MMS could not be deleted */
            }
            else
            {
                mmi_umms_free_req_handler_node(rsp->msg_id, rsp->req_id);
                if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
                    mmi_umms_show_error_pop_up(rsp->result);
                }
                else
                {
                    mmi_umms_show_error_pop_up(rsp->result);
                }
                mmi_umms_delete_umms_screens();
            }
        }
        else
        {
            if (current_state == E_STATE_SEND_MSG)
            {
                mmi_umms_free_send_handler_node(rsp->msg_id, rsp->req_id);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_message_number_request
 * DESCRIPTION
 *  Message Number Req to MMA.
 * PARAMETERS
 *  void
 *  current_state(?)        [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_message_number_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_req_struct *msgReq;
    umms_state_enum current_state = E_STATE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_message_number_request \n");

    msgReq = (mmi_um_get_msg_num_req_struct*) OslConstructDataPtr(sizeof(mmi_um_get_msg_num_req_struct));
    msgReq->app_id = MMA_APP_ID_MMS_APP;
    msgReq->msg_type = UM_MSG_TYPE_MMS;
    current_state = mmi_umms_get_msg_number_state();
    mmi_umms_add_to_list(0, 0, current_state, E_STATE_NONE);
 //   mmi_umms_get_memory_status_req();

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (oslParaType*) msgReq, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_number_rsp
 * DESCRIPTION
 *  Mesage Number response from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_number_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_rsp_struct *msg = (mmi_um_get_msg_num_rsp_struct*) inMsg;
    umms_state_enum current_state = E_STATE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_msg_numbers_in_global_list(msg);
    current_state = mmi_umms_get_state_of_msg_from_all_the_lists(0, 0);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_get_msg_number_rsp Current_State = %d \n", current_state);
    mmi_umms_free_req_handler_node(0, 0);
    if (msg->msg_type == UM_MSG_TYPE_MMS)
    {
        if(!mmi_umms_is_usb_mode())
        {
    if (msg->result == KAL_TRUE)
    {

        if (current_state == E_STATE_GET_NUM_REQ_INTERMEDATE_MSG)
        {
            mmi_umms_update_status_icon_on_number_rsp();
            mmi_umms_delete_progress_screen();
        }
        if (current_state == E_STATE_GET_NUM_REQ_AT_START_UP)
        {
            mmi_umms_update_status_icon_on_number_rsp();
        }
        else
        {
            mmi_umms_update_status_icon_on_number_rsp();
        }
    }
    else
    {
        /* Do nothing as this flow should not hamper the flow of MMS Application. */
    }
}
else
	{
		mmi_umms_update_status_icon_on_number_rsp();
	}
}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_memory_status_req
 * DESCRIPTION
 *  Memory Status req to MMA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_memory_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_get_mem_status_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_memory_status_req\n");
    msg_req = (wap_mma_get_mem_status_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_mem_status_req_struct));
    msg_req->req_id = wap_mma_get_request_id();
    msg_req->app_id = MMA_APP_ID_MMS_APP;

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ, (oslParaType*) msg_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_receive_memory_status_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_receive_memory_status_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_get_mem_status_rsp_struct *rsp = (wap_mma_get_mem_status_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_receive_memory_status_rsp\n");
    if (rsp->result == MMA_RESULT_OK)
    {
        if (rsp->free_size > 0)
        {
            mmi_umms_update_storage_state(FALSE);
        }
        else
        {
            mmi_umms_update_storage_state(TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_storage_full_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_storage_full_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_storage_full_ind_struct *ind = (wap_mma_storage_full_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_storage_full_ind\n");
/*    if (ind->is_no_fs_space)
    {
        mmi_umms_update_storage_state(TRUE);
    }
    if (ind->is_max_num_reached)
    {
        mmi_umms_update_storage_state(TRUE);
    }
*/
    mmi_umms_show_memory_full_pop_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_mms_msg
 * DESCRIPTION
 *  Send MMS req to MMA.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_mms_msg(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *msg_req;
    kal_bool send_and_save = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_send_mms_msg Message_id = %d \n", msg_id);
    msg_req = (wap_mma_send_req_struct*) OslConstructDataPtr(sizeof(wap_mma_send_req_struct));
    msg_req->req_id = wap_mma_get_request_id();
    msg_req->app_id = MMA_APP_ID_MMS_APP;
    msg_req->msg_id = msg_id;
    mmi_umms_set_msg_number_state(E_STATE_GET_NUM_REQ_INTERMEDATE_MSG);
    mmi_umms_set_mms_sending_busy();
    mmi_umms_update_intermediate_send_req(msg_req->msg_id, msg_req->req_id, E_STATE_INTR_SEND_MSG);
    send_and_save = mmi_umms_get_send_and_save_state(msg_req->msg_id);

    if (send_and_save)
    {
        msg_req->send_and_save = KAL_TRUE;
        msg_req->box = MMA_FOLDER_SENT;
    }
    else
    {
        msg_req->send_and_save = KAL_FALSE;
        msg_req->box = 0;
    }

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SEND_REQ, (oslParaType*) msg_req, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_read_report_req
 * DESCRIPTION
 *  Send Request for Read Report without Viewing the MMS
 * PARAMETERS
 *  msg_id       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_read_report_req(U32 msg_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (wap_mma_send_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->app_id = MMA_APP_ID_MMS_APP;
    msgReq->msg_id = msg_id;
    msgReq->is_read_report = TRUE;
	mmi_umms_update_intermediate_send_req(msgReq->msg_id, msgReq->req_id, E_STATE_DELETE_WITHOUT_READ);
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SEND_REQ, (oslParaType*) msgReq, NULL);	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_send_ind
 * DESCRIPTION
 *  Get Send Indication from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_send_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    //wap_mma_send_ind_struct *msg_ind = (wap_mma_send_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_send_ind \n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_rsp
 * DESCRIPTION
 *  Get Send Rsp from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_enum_retry_send_verion_enum retry_version = UMMS_SEND_VERSION_NONE;
    wap_mma_send_rsp_struct *msg_rsp = (wap_mma_send_rsp_struct*) inMsg;
    umms_send_counter_enum send_counter = UMMS_SEND_COUNTER_0;
    //U32 retry_version_count = 0;
	U8 *response_text = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* IF message is not in teh Send List then Do nothing Just return; */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_send_rsp Msg_id = %d Req_id = %d result = %d \n",
                         msg_rsp->msg_id, msg_rsp->req_id, msg_rsp->result);

	
    if (!mmi_umms_is_mms_in_send_list(msg_rsp->msg_id))
    {
        return;
    }
	/* Check for State E_STATE_DELETE_WITHOUT_READ */
	if(mmi_umms_get_intermediate_state_of_msg_from_send_list(msg_rsp->msg_id) == E_STATE_DELETE_WITHOUT_READ)
	{
		mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
		mmi_umms_dont_send_read_mark_for_delete_mms();
		return;
	}
	response_text = (U8*) umms_malloc(MMA_MAX_RESPONSE_TEXT_LENGTH);
	mmi_ucs2ncpy((PS8) response_text, (PS8) msg_rsp->response_text, MAX_PROGRESS_STRING_LENGTH);
    if (msg_rsp->result != MMA_RESULT_OK)
    {
        if (mmi_umms_is_bearer_type_csd())
        {
            mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
            mmi_umms_reset_mms_sending_busy();
            mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
            if (mmi_umms_get_current_selected_msg_id() == msg_rsp->msg_id)
            {
                mmi_umms_go_to_box_list_screen();
            }
			umms_free(response_text);
			response_text = NULL;
            return;
        }
    }

    switch (msg_rsp->result)
    {
        case MMA_RESULT_FAIL_USER_CANCEL:
            mmi_umms_reset_mms_sending_busy();
			mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
            mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);

            break;

        case MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT:
            //mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
            mmi_umms_reset_mms_sending_busy();
            mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
            if (mmi_umms_get_current_selected_msg_id() == msg_rsp->msg_id)
            {
                if((GetActiveScreenId() == SCR_ID_UMMS_MMS_OPTIONS) ||
                    (GetActiveScreenId() == SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES) ||
                    (GetActiveScreenId() == SCR_ID_UMMS_MESSAGE_STATUS))
                {
                    mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
                    mmi_umms_go_to_box_list_screen();
                }
                else
                {
                    mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
                    mmi_umms_delete_umms_screens();
                }
            }
            else
            {
                mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
            }
            break;
				case MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE:
						mmi_umms_reset_mms_sending_busy();
            mmi_umms_update_intermediate_send_req(msg_rsp->msg_id, 0, E_STATE_USB_PLUG_IN);
            mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
						break;
        case MMA_RESULT_FAIL_FILE_IO:
            if (mmi_umms_is_usb_mode())
            {
                mmi_umms_reset_mms_sending_busy();
                mmi_umms_update_intermediate_send_req(msg_rsp->msg_id, 0, E_STATE_USB_PLUG_IN);
            }
            else
            {   /* File IO Error Came due to some other reason
                   No need for retry as the MMS may be corrupt */
                mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
                mmi_umms_reset_mms_sending_busy();
                mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
            }
            break;

            /*
             * case MMA_RESULT_VERSION_MISMATCH:
             * retry_version = mmi_umms_get_send_version_number(msg_rsp->msg_id);
             * retry_version_count = mmi_umms_get_send_version_count(msg_rsp->msg_id);
             * if (retry_version_count == 3)
             * {   
             * mmi_umms_reset_mms_sending_busy();
             * if (!isInCall())
             * {
             * mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id);
             * }
             * mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
             * }
             * else
             * {
             * 
             * mmi_umms_reset_mms_sending_busy();
             * mmi_umms_update_send_msg_handler(E_STATE_SEND_MSG, msg_rsp->msg_id, retry_version + 1, retry_version_count+1);
             * mmi_umms_get_content_req(msg_rsp->msg_id);
             * }
             * break;
             */
        case MMA_RESULT_OK:
            mmi_umms_reset_mms_sending_busy();

            if (mmi_umms_get_send_and_save_state(msg_rsp->msg_id))
            {
                //mmi_umms_show_send_sucess_pop_up(msg_rsp->msg_id);
                mmi_umms_update_intermediate_send_req(msg_rsp->msg_id, msg_rsp->req_id, E_STATE_SAVE_AFTER_SEND);
                if (mmi_umms_get_current_selected_msg_id() == msg_rsp->msg_id)
                {
                    mmi_umms_go_to_box_list_screen();
					GoBackHistory();
                }
                mmi_umms_save_req(
                    E_STATE_SAVE_AFTER_SEND,
                    E_STATE_SEND_MSG,
                    msg_rsp->msg_id,
                    MMA_FOLDER_SENT,    /* Box in which the MMS needs to be moved */
                    MMA_FOLDER_OUTBOX); /* Box in which the current MMS is present. */
            }
            else
            {
                mmi_umms_delete_req(
                    E_STATE_DELETE_AFTER_SAVE_SEND,
                    E_STATE_SEND_MSG,
                    msg_rsp->msg_id,
                    MMA_FOLDER_OUTBOX);
               // mmi_umms_show_send_sucess_pop_up(msg_rsp->msg_id);
                if (mmi_umms_get_current_selected_msg_id() == msg_rsp->msg_id)
                {
                    mmi_umms_go_to_box_list_screen();
					GoBackHistory();
                }

            }
            break;

        default:
            send_counter = mmi_umms_get_send_retry_counter(msg_rsp->msg_id, msg_rsp->req_id);
#ifdef __CMCC_SEND_COUNT_RETRY_POP_UP__
            if(send_counter == 1)
            {
                mmi_umms_display_retry_send_pop_up();
            }
#endif
            mmi_umms_reset_mms_sending_busy();
            if (send_counter <= UMMS_SEND_COUNTER_2)
            {   /* Send the MMS once again */
                mmi_umms_update_retry_counter_send_req(msg_rsp->msg_id, msg_rsp->req_id, ++send_counter);
                mmi_umms_send_mms_msg(msg_rsp->msg_id);
            }
            else
            {   /* Send Failed in all counters and retry Versions */
                mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
                mmi_umms_reset_mms_sending_busy();
                if (mmi_umms_get_current_selected_msg_id() == msg_rsp->msg_id)
                {
                    if((GetActiveScreenId() == SCR_ID_UMMS_MMS_OPTIONS) ||
                        (GetActiveScreenId() == SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES) ||
                        (GetActiveScreenId() == SCR_ID_UMMS_MESSAGE_STATUS))
                    {
                        mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
                    mmi_umms_go_to_box_list_screen();
                }
                    else
                    {
                        mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
                        mmi_umms_delete_umms_screens();
                    }
                }
                else
                {
                    mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,response_text);
                }
            }
            break;
    }
	umms_free(response_text);
	response_text = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_content_req
 * DESCRIPTION
 *  Get Content req to MMA
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_content_req(const U32 msg_id, mma_app_mode_enum mode, umms_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_content_req Msg_id = %d \n", msg_id);
    msg_req = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_req_struct));

    msg_req->msg_id = msg_id;
    msg_req->app_id = MMA_APP_ID_MMS_APP;
    msg_req->req_id = wap_mma_get_request_id();
    msg_req->buffer_index = 0;
//MTI SUKRIT START
    msg_req->mode = mode;
//MTI SUKRIT END
    msg_req->creation_mode = MMA_CREATION_MODE_FREE;

    if (state == E_STATE_GET_CONTENT_FOR_MSG_INFO)
    {
        umms_add_to_msg_hndlr_list(msg_req->msg_id, msg_req->req_id, E_STATE_GET_CONTENT_FOR_MSG_INFO);
    }
    else
    {
    mmi_umms_update_retry_send_req(msg_id, msg_req->req_id, 0, E_STATE_GET_CONTENT_MSG);
    }
    /* SetProtocolEventHandler(mmi_umms_receive_get_content_rsp, MSG_ID_WAP_MMA_GET_CONTENT_RSP); */
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_CONTENT_REQ, (oslParaType*) msg_req, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_receive_get_content_rsp
 * DESCRIPTION
 *  Rsp for Get Content.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_receive_get_content_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *msg_rsp = (wap_mma_get_content_rsp_struct*) inMsg;
    kal_bool is_version_changed = FALSE;
    wap_mma_get_content_req_struct *msg_req;
    umms_state_enum current_state = E_STATE_NONE;

    /* pre_mmi_umms_entry_delete_msg(msg_rsp->msg_id); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_receive_get_content_rsp Msg_id = %d Result = %d \n", msg_rsp->msg_id,
                         msg_rsp->result);
    current_state = mmi_umms_get_state_of_msg_from_all_the_lists(msg_rsp->msg_id, msg_rsp->req_id);
    if (current_state == E_STATE_GET_CONTENT_FOR_MSG_INFO)
    {
        mmi_umms_get_content_for_msg_info(inMsg, current_state);
        return;
        /* Rajbir Please Add Here */
    }
    if (msg_rsp->result != MMA_RESULT_OK)
    {
        mmi_umms_reset_mms_sending_busy();
        if (mmi_umms_is_usb_mode())
        {
            mmi_umms_update_intermediate_send_req(msg_rsp->msg_id, 0, E_STATE_USB_PLUG_IN);
        }
        else
        {
            mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,NULL);
            mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
        }
    }
    else
    {
        /* Check for More Data Field. If more is true then send again get Content request */
        if (msg_rsp->more)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_content_req Is More is true\n");
            msg_req = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_req_struct));
            msg_req->req_id = msg_rsp->req_id;
            msg_req->msg_id = msg_rsp->msg_id;
            msg_req->buffer_index = msg_rsp->buffer_index++;
            msg_req->mode = MMA_MODE_EDIT;
            mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_CONTENT_REQ, (oslParaType*) msg_req, NULL);
        }
        else
        {
            /* Whole of the XML file has been received and can be edited now */
            /* Edit the Current MMS with the latest  Version number */
            is_version_changed = mmi_umms_change_version_number_of_mms((U8*) msg_rsp->xml_filepath);
            if (is_version_changed)
            {
                /* Now send Create Req to MMA. */
                mmi_umms_update_xml_file_path_in_send_msg_hndlr(msg_rsp->req_id, (U8*) msg_rsp->xml_filepath);
                mmi_umms_create_req(msg_rsp->msg_id, msg_rsp->req_id, (U8*) msg_rsp->xml_filepath, FALSE, 0);

            }
            else
            {
                mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,NULL);
                mmi_umms_reset_mms_sending_busy();
                mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_req
 * DESCRIPTION
 *  Create Req to MMA.
 * PARAMETERS
 *  msg_id              [IN]        
 *  req_id              [IN]        
 *  xml_file_path       [IN]        [?]         [?]         [?]
 *  is_more             [IN]        
 *  buffer_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_create_req(
        const U32 msg_id,
        const U32 req_id,
        const U8 *xml_file_path,
        const kal_bool is_more,
        U32 buffer_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *msg_req;
    peer_buff_struct *peer_buff_ptr = NULL;
    U32 read_size = 0;
    U16 peer_buff_len = 0;
    FS_HANDLE file_hnd = 0;
    U32 remaining_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_create_req msg_id = %d req_id =%d\n", msg_id, req_id);
    msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));
    msg_req->req_id = wap_mma_get_request_id();
    mmi_umms_update_retry_send_req(msg_id, req_id, msg_req->req_id, E_STATE_CREATE_MSG);
    msg_req->mode = MMA_MODE_EDIT;
    msg_req->msg_id = 0;
    msg_req->app_id = MMA_APP_ID_MMS_APP;
    msg_req->xml_size = applib_get_file_size((kal_wchar*) xml_file_path);
    mmi_ucs2ncpy((PS8) msg_req->xml_filepath, (PS8) xml_file_path, MAX_PROGRESS_STRING_LENGTH);
    if (is_more)
    {
        msg_req->buffer_index = buffer_index++;
    }
    else
    {
        msg_req->buffer_index = 0;
    }

    remaining_size = msg_req->xml_size - (msg_req->buffer_index * MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER);

    if (remaining_size <= MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER)
    {
        msg_req->buffer_size = remaining_size;
        msg_req->more = KAL_FALSE;
    }
    else
    {
        msg_req->buffer_size = MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER;
        msg_req->more = KAL_TRUE;
    }
    mmi_umms_update_more_flag_for_send(msg_req->req_id, msg_req->more);
    peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL);
    file_hnd = FS_Open(msg_req->xml_filepath, FS_READ_ONLY);
    if (FS_Read(file_hnd, get_pdu_ptr(peer_buff_ptr, &peer_buff_len), msg_req->buffer_size, &read_size) != FS_NO_ERROR
        || read_size != msg_req->buffer_size)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSAppMsg.c] mmi_umms_create_req read_size=%d buf_size=%d*\n",
                             read_size, msg_req->buffer_size);
    }

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_CREATE_REQ, (oslParaType*) msg_req, peer_buff_ptr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_rsp
 * DESCRIPTION
 *  Create Rsp from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_create_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *xml_file_path = NULL;
    U32 old_msg_id = 0;
    wap_mma_create_rsp_struct *msg_rsp = (wap_mma_create_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_create_rsp msg_id = %d req_id =%d Result = %d\n",
                         msg_rsp->msg_id, msg_rsp->req_id, msg_rsp->result);

    if (msg_rsp->result == MMA_RESULT_OK)
    {
        if (mmi_umms_get_more_flag_from_send_list(msg_rsp->req_id))
        {
            xml_file_path = mmi_umms_get_xml_file_path_from_send_msg_hndlr(msg_rsp->msg_id);
            mmi_umms_create_req(msg_rsp->msg_id, msg_rsp->req_id, xml_file_path, TRUE, msg_rsp->buffer_index);
        }
        else
        {
            old_msg_id = mmi_umms_get_old_msg_id_from_send_handler(msg_rsp->req_id);
            mmi_umms_update_send_hdnlr_with_new_msg_id(msg_rsp->msg_id, msg_rsp->req_id, E_STATE_SAVE_NEW_MMS);
            if (old_msg_id > 0)
            {
                mmi_umms_delete_req(0, E_STATE_SEND_MSG, old_msg_id, MMA_FOLDER_OUTBOX);
            }

            mmi_umms_save_req(
                E_STATE_SAVE_NEW_MMS,
                E_STATE_SEND_MSG,
                msg_rsp->msg_id,
                MMA_FOLDER_OUTBOX,
                MMA_FOLDER_DRAFT);
        }
    }
    else
    {
        if (mmi_umms_is_usb_mode())
        {
            mmi_umms_reset_mms_sending_busy();
            mmi_umms_update_intermediate_send_req(msg_rsp->msg_id, 0, E_STATE_USB_PLUG_IN);
        }
        else
        {
            mmi_umms_show_error_in_send_pop_up(msg_rsp->msg_id,NULL);
            mmi_umms_reset_mms_sending_busy();
            mmi_umms_free_send_handler_node(msg_rsp->msg_id, msg_rsp->req_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_cancel_req
 * DESCRIPTION
 *  Send Cancel Send Req to MMA.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_cancel_req(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_send_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_cancel_req Msg_id = %d  \n", msg_id);
    msg_req = (wap_mma_cancel_send_req_struct*) OslConstructDataPtr(sizeof(wap_mma_cancel_send_req_struct));
    msg_req->req_id = wap_mma_get_request_id();
    msg_req->msg_id = msg_id;
	msg_req->app_id = MMA_APP_ID_MMS_APP;

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_CANCEL_SEND_REQ, (oslParaType*) msg_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_cancel_rsp
 * DESCRIPTION
 *  Get Cancel Send response from MMA.
 * PARAMETERS
 *  inMsg           [?]         
 *  req_id(?)       [IN]        
 *  msg_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_cancel_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_cancel_rsp Msg_id = %d  \n", msg_rsp->msg_id);
    /* Free the Node from Send req Handler and then Show the PopUp */
    if (msg_rsp->result == MMA_RESULT_OK)
    {
            mmi_umms_free_send_node_with_msg_id(msg_rsp->msg_id);
          mmi_umms_reset_mms_sending_busy();

        if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
            mmi_umms_show_cancel_send_popup(MMI_TRUE);
            mmi_umms_delete_progress_screen();
            mmi_umms_go_to_box_list_screen();
                }
        else
        {
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
            DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
            //mmi_umms_go_to_box_list_screen();
            mmi_umms_reset_global();
        }
                }
                else
                {
        /* Error in cancel Send */
        if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
        {
            mmi_umms_show_cancel_send_popup(MMI_FALSE);
                mmi_umms_delete_progress_screen();
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
            DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
            mmi_umms_reset_global();
        }
    }
}

/* Download Mechanism Started */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_download_req
 * DESCRIPTION
 *  Download req to MMA.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_download_req(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_download_req Msg_id = %d  \n", msg_id);
    mmi_umms_set_mms_downloading_busy();
    msg_req = (wap_mma_download_req_struct*) OslConstructDataPtr(sizeof(wap_mma_download_req_struct));
    msg_req->app_id = MMA_APP_ID_MMS_APP;
    msg_req->req_id = wap_mma_get_request_id();
    msg_req->msg_id = msg_id;
    if(isInCall())
    {
        mmi_umms_add_to_list(msg_req->msg_id, msg_req->req_id, E_STATE_DOWNLOAD_MSG, E_STATE_DOWNLOAD_AFTER_CALL);
    }
    else
    {
        mmi_umms_add_to_list(msg_req->msg_id, msg_req->req_id, E_STATE_DOWNLOAD_MSG, E_SATE_DOWNLOAD_BEFORE_CALL);
    }

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_DOWNLOAD_REQ, (oslParaType*) msg_req, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_download_ind
 * DESCRIPTION
 *  Download Indication from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_download_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_res_struct *msg_req;
    umms_state_enum current_state = E_STATE_NONE;
    wap_mma_download_ind_struct *rsp = (wap_mma_download_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //   Check the state of the Download. it might be that the Download has been canceled. 
    // In this case the progress Scrren Should not be updated and no response must be send

    current_state = mmi_umms_get_state_of_msg_from_download_list(rsp->msg_id, rsp->req_id);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_get_download_ind Msg_id = %d Percent = %d Curent State = %d \n",
                         rsp->msg_id, rsp->percent, current_state);

    if ((current_state == E_STATE_CANCEL_DOWNLOAD_MSG_BY_END_KEY) || (current_state == E_STATE_CANCEL_DOWNLOAD_MSG))
    {
        /* TO DO in Future when Download is in Background. */
    }
    else
    {
        mmi_umms_update_progress_screen(rsp->percent);
        mmi_umms_update_download_msg_hndlr_with_percent_val(rsp->msg_id, rsp->req_id, rsp->percent);
        msg_req = (wap_mma_download_res_struct*) OslConstructDataPtr(sizeof(wap_mma_download_res_struct));
        msg_req->app_id = MMA_APP_ID_MMS_APP;
        msg_req->result = MMA_RESULT_OK;
        msg_req->req_id = rsp->req_id;

        mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_DOWNLOAD_RES, (oslParaType*) msg_req, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_download_rsp
 * DESCRIPTION
 *  Get downlaod response from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [void]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_download_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *rsp = (wap_mma_rsp_struct*) inMsg;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_get_download_rsp Msg_id = %d Req_id= %d Result= %d \n",
                         rsp->msg_id, rsp->req_id, rsp->result);
    
    if (rsp->result == MMA_RESULT_OK)
    {
        mmi_umms_reset_mms_downloading_busy();
        mmi_umms_free_download_handler_node(rsp->msg_id, rsp->req_id);
        if (mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
        {
        if (GetActiveScreenId() != SCR_ID_UMMS_PROGRESS)
        {
                    mmi_umms_delete_progress_screen();
                    mmi_umms_go_to_box_list_screen();
            }
            else
            {
                mmi_umms_show_error_pop_up(rsp->result);
                mmi_umms_go_to_box_list_screen();
            }
        }

    }
    else
    {
        /* Check for CSD and the STATE Of the MSg.
        If profile is CSD then no need for ReDownload else based on the State make Decision
        if intermediate State is E_STATE_DOWNLOAD_AFTER_CALL Don't retry
        else if State is E_SATE_DOWNLOAD_BEFORE_CALL retry based on the result if in Call */
        
        if (mmi_umms_is_bearer_type_csd())
        {
            
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] Bearer type is CSD \n");
            mmi_umms_reset_mms_downloading_busy();
            mmi_umms_free_download_handler_node(rsp->msg_id, rsp->req_id);
            if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] Bearer type is CSD. Active Screen is Progress \n");
            if (mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
            {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] Bearer type is CSD.Msg Id Matches\n");
                    mmi_umms_entry_dummy_screen();
            mmi_umms_delete_progress_screen();
            mmi_umms_go_to_box_list_screen();
                    mmi_umms_show_error_pop_up(rsp->result);
                 }
                 else
                 {
                     PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] Bearer type is CSD.Msg Id Not Matches\n");
        }
        }
        else
        {
                if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] Bearer type is CSD. Active Screen is Not Progress \n");
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] Bearer type is CSD.Msg Id Matches\n");
                    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
                    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
            mmi_umms_show_error_pop_up(rsp->result);
                    mmi_umms_reset_global();
                }
                else
                {
                       PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] Bearer type is CSD.Msg Id Not Matches\n");
                }
        }

    }
    else
    {
            /* Check for Call */
            if(isInCall())
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present\n");
                switch(mmi_umms_get_intermediate_state_from_downl_list(rsp->msg_id))
        {
                    case E_STATE_DOWNLOAD_AFTER_CALL:
                        /* No need for retry */
                        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present. State is E_STATE_DOWNLOAD_AFTER_CALL \n");
                        mmi_umms_reset_mms_downloading_busy();
            mmi_umms_free_download_handler_node(rsp->msg_id, rsp->req_id);
            if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            {
                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present. Progress Screen Active\n");
                            if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                             {
                                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present. Msg_id MAtches\n");
                mmi_umms_entry_dummy_screen();
                mmi_umms_delete_progress_screen();
                mmi_umms_go_to_box_list_screen();
                mmi_umms_show_error_pop_up(rsp->result);
            }
            else
            {
                                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present. Msg_id Not MAtches\n");
                            }
                        }
                        else
                        {
                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present. Progress Screen Not Active\n");
                            if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                            {
                                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present. Msg_id MAtches\n");
                                DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
                                DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
                                mmi_umms_show_error_pop_up(rsp->result);
                                mmi_umms_reset_global();
                            }
                            else
                            {
                                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present. Msg_id Not MAtches\n");
                            }
                        }
                        break;
                    case E_SATE_DOWNLOAD_BEFORE_CALL:
                        mmi_umms_reset_mms_downloading_busy();
                        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call Present. State is E_SATE_DOWNLOAD_BEFORE_CALL \n");
                        mmi_umms_update_download_msg_hndlr(rsp->msg_id, rsp->req_id, E_STATE_DOWNLOAD_FAIL_DUE_TO_CALL);
                        if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                        {
                             if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                             {
                                mmi_umms_entry_dummy_screen();
                mmi_umms_delete_progress_screen();
                mmi_umms_go_to_box_list_screen();
                                mmi_umms_show_error_pop_up(rsp->result);
            }
        }
        else
        {
                            if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                            {
                                DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
                                DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
                                mmi_umms_reset_global();
                            }
                        }
                        break;
                }
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSAppMsg.c] GSM Call not Present\n");
                mmi_umms_reset_mms_downloading_busy();
                mmi_umms_free_download_handler_node(rsp->msg_id, rsp->req_id);
            if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            {
                     if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                     {
                mmi_umms_entry_dummy_screen();
                        mmi_umms_delete_progress_screen();
                        mmi_umms_go_to_box_list_screen();
                        mmi_umms_show_error_pop_up(rsp->result);
                     }
            }
                else
                {
                    if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                    {
			 		DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
          DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
          mmi_umms_reset_global();
        }
    }
            }
        }
     }

    /* After All this Check if The list for new MMS is Empty or not. If not then now Show the New MMS PopUp */
    mmi_umms_check_new_mms_list_and_show_new_mms_pop_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_abort_download_mms
 * DESCRIPTION
 *  Abort Download Req to MMA.
 * PARAMETERS
 *  current_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_abort_download_mms(const umms_state_enum current_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id = 0;
    wap_mma_cancel_download_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = mmi_umms_get_current_selected_msg_id();
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_abort_download_mms Msg_id = %d Curent State= %d \n",
                         msg_id, current_state);

    msg_req = (wap_mma_cancel_download_req_struct*) OslConstructDataPtr(sizeof(wap_mma_cancel_download_req_struct));
    msg_req->app_id = MMA_APP_ID_MMS_APP;
    msg_req->req_id = wap_mma_get_request_id();
    msg_req->msg_id = mmi_umms_get_current_selected_msg_id();

    mmi_umms_update_download_msg_hndlr(msg_req->msg_id, msg_req->req_id, current_state);
    if (current_state == E_STATE_CANCEL_DOWNLOAD_MSG_BY_END_KEY)
    {
        if(isInCall())
		{
			HangupAllCalls();
		}
        EntryIdleScreen();
    }
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ, (oslParaType*) msg_req, NULL);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_abort_download_rsp
 * DESCRIPTION
 *  Abort Download Response from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_abort_download_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_state_enum current_state = E_STATE_NONE;
    wap_mma_rsp_struct *rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_state = mmi_umms_get_state_of_msg_from_download_list(rsp->msg_id, rsp->req_id);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_abort_download_rsp Msg_id = %d Curent State= %d Result = %d \n",
                         rsp->msg_id, current_state, rsp->result);

    if (rsp->result == MMA_RESULT_OK)
    {
        mmi_umms_free_download_handler_node(rsp->msg_id, rsp->req_id);
        mmi_umms_reset_mms_downloading_busy();
        switch (current_state)
        {
            case E_STATE_CANCEL_DOWNLOAD_MSG:
                if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] Dwndl Abort Sucess Abort Case . Msg ID matches\n");
                if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                {
                    mmi_umms_show_communication_aborted_pop_up();
                }
                    mmi_umms_delete_umms_screens();
                }
                /* GoBackHistory(); */
                break;
            case E_STATE_CANCEL_DOWNLOAD_MSG_BY_END_KEY:
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] Dwndl Abort Sucess End Key Case. End Key Result\n");
                /* DisplayIdleScreen(); */
                break;
            default:
                if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] Dwndl Abort Sucess Default Case. Msg ID matches\n");
                    if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                    {
                        mmi_umms_show_communication_aborted_pop_up();
                    }
                    mmi_umms_delete_umms_screens();
                }
                break;
        }
    }
    else
    {
        if (current_state != E_STATE_CANCEL_DOWNLOAD_MSG_BY_END_KEY)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] Dwndl Abort Failure. Not by End Key\n");
            if(mmi_umms_get_current_selected_msg_id() == rsp->msg_id)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] Dwndl Abort Failure. MsgId MAtches\n");

            if(GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] Dwndl Abort Failure. Dummy Screen Inserted\n");
            mmi_umms_entry_dummy_screen();
            }
            mmi_umms_delete_progress_screen();
            mmi_umms_show_cancel_fail_pop_up();
                mmi_umms_delete_umms_screens();
        }
    }
}
}

/* Cancel Download Ended */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_start_immd_retr_ind
 * DESCRIPTION
 *  Start Immediate Retreival Ind from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_start_immd_retr_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // wap_mma_start_immed_retrieval_ind_struct *ind = (wap_mma_start_immed_retrieval_ind_struct*) inMsg;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_start_immd_retr_ind\n");
    mmi_umms_set_mms_downloading_busy();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_stop_immd_retr_ind
 * DESCRIPTION
 *  Stop imediate Download ind from MMA.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_stop_immd_retr_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  wap_mma_stop_immed_retrueval_ind_struct *ind = (wap_mma_stop_immed_retrueval_ind_struct*) inMsg;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_stop_immd_retr_ind\n");
    mmi_umms_reset_mms_downloading_busy();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_view_msg_ind
 * DESCRIPTION
 *  View message Indication from MMA
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_view_msg_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_mma_view_msg_ind_struct *view_msg_ind = (wap_mma_view_msg_ind_struct*) inMsg;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_view_msg_ind Msg_id = %d \n", view_msg_ind->msg_id);
    if(view_msg_ind->msg_id == 0)
    {
        mmi_umms_show_error_pop_up(MMA_RESULT_FAIL_INVALID_MSGID);
        mmi_umms_delete_progress_screen();
        return;
    }
    mmi_umms_update_current_msg_id(view_msg_ind->msg_id);
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    mmi_umms_entry_mms_only_options(view_msg_ind->msg_id);
#else 
    mmi_umms_entry_mms_options(view_msg_ind->msg_id);
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_umms_highlight_mms_message_ind
 * DESCRIPTION
 *  Function to send information to UM about the currently highlighted item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_umms_highlight_mms_message_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_highlight_msg_ind_struct *mms_highlight_ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_highlight_ind_p =
        (mmi_um_highlight_msg_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_highlight_msg_ind_struct));
    mms_highlight_ind_p->msg_type = UM_MSG_TYPE_MMS;
    mms_highlight_ind_p->msg_box_type = mmi_umms_get_current_msg_box_type();
    mms_highlight_ind_p->msg_index = mmi_umms_get_current_highlighted_msg_index();

    mmi_umms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND, (oslParaType*) mms_highlight_ind_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_um_refresh_ind
 * DESCRIPTION
 *  Send UM Refresh Indication
 * PARAMETERS
 *  folder_id       [IN]        
 *  inMsg       [?]     [?]     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_um_refresh_ind(mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_refresh_ind_struct *um_refresh_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_um_refresh_ind Folder_id = %d \n", folder_id);
    um_refresh_ind =
        (mmi_um_refresh_ind_struct*) construct_local_para((kal_uint16) sizeof(mmi_um_refresh_ind_struct), 0);
    um_refresh_ind->msg_type = UM_MSG_TYPE_MMS;
    um_refresh_ind->msg_box_type = mmi_umms_convert_mma_folder_to_umbox_type(folder_id);

    mmi_umms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) um_refresh_ind, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_readmark_req
 * DESCRIPTION
 *  set readmark req
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_readmark_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_readmark_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (wap_mma_set_readmark_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->app_id = MMA_APP_ID_MMS_APP;
    msgReq->msg_id = msg_id;
    msgReq->readmark = MMI_TRUE;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SET_READMARK_REQ, (oslParaType*) msgReq, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_readmark_rsp
 * DESCRIPTION
 *  set readmark rsp
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_readmark_rsp(void *inMsg)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_readmark_rsp_struct *msg = (wap_mma_set_readmark_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->result == MMA_RESULT_OK)
    {
        mmi_umms_update_status_icon_indicator();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_all_user_def_template_req
 * DESCRIPTION
 *  This function send the request to MMA, to delete all MMSs present in User defined folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Rajbir  */
void mmi_umms_delete_all_user_def_template_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_um_delete_folder_req_struct *msgReq = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_um_delete_folder_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->msg_type = UM_MSG_TYPE_MMS;
    msgReq->msg_box_type = UM_MSG_BOX_TYPE_USRDEF_TEMPLATES;    // /*MMA_FOLDER_PREDEF_TEMPLATE*/MMA_FOLDER_TEMPLATE;
    msgReq->app_id = MMA_APP_ID_MMS_APP;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ, (oslParaType*) msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_all_user_def_template_rsp
 * DESCRIPTION
 *  This is the response handler for Delete Request.
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     response structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_all_user_def_template_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_delete_folder_rsp_struct *msg = (mmi_um_delete_folder_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_delete_all_template_rsp result=%d*\n", msg->result);

    mmi_umms_show_um_error_pop_up(msg->result);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_content_for_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg               [IN]        
 *  current_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_content_for_msg_info(void *inMsg, umms_state_enum current_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *contRsp = (wap_mma_get_content_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppMsg.c] mmi_umms_get_content_for_msg_info result=%d *\n", contRsp->result);

    if (contRsp->result != MMA_RESULT_OK)
    {
        mmi_umms_show_error_pop_up(contRsp->result);
        mmi_umms_delete_progress_screen();
        mmi_umms_free_req_handler_node(contRsp->msg_id, contRsp->req_id);
        return;
    }
    if (contRsp->more)
    {
        wap_mma_get_content_req_struct *msg_req;

        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_content_for_msg_info Is More is true\n");
        msg_req = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_req_struct));
        msg_req->req_id = contRsp->req_id;
        msg_req->msg_id = contRsp->msg_id;
        msg_req->app_id = MMA_APP_ID_MMS_APP;
        msg_req->buffer_index = ++contRsp->buffer_index;
        msg_req->mode = MMA_MODE_HEADER;
        mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_CONTENT_REQ, (oslParaType*) msg_req, NULL);
        return;
    }
    else
    {
        umms_state_enum current_state = mmi_umms_get_current_state(contRsp->msg_id, contRsp->req_id);
        mmi_umms_free_req_handler_node(contRsp->msg_id, contRsp->req_id);
        mmi_umms_start_file_parse(contRsp->xml_filepath);
    }
}


/*****************************************************************************
 * FUNCTION
 *  app_decoder_mem_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bytes       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *app_decoder_mem_alloc(U32 bytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)umms_malloc(bytes);
}


/*****************************************************************************
 * FUNCTION
 *  app_decoder_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void app_decoder_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    umms_free(ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_message
 * DESCRIPTION
 *  Send the Message to the Queeue.
 * PARAMETERS
 *  MOD_SRC         [IN]        
 *  MOD_DEST        [IN]        
 *  MSG_SAP         [IN]        
 *  MSG_ID          [IN]        
 *  LOCAL           [?]         [?]         [?]         [?]
 *  PEER            [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_message(
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
 *  mmi_umms_terminate_indication
 * DESCRIPTION
 *  Terminate Event received from MMA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_terminate_indication(void *inMSg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_reset_all();
    mmi_jsr_terminate_req_handler();
}
#endif /* __MMI_MMS_2__ */ 
// #endif /* _MMI_MMSAPPMAIN_C */

