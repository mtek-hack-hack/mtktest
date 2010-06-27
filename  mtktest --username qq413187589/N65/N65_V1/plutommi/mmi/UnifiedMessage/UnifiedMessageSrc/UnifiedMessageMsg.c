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
 * UnifiedMessageMsg.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements handlers to process primitives.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_UNIFIED_MESSAGE_MSG_C
#define _MMI_UNIFIED_MESSAGE_MSG_C

#ifdef __MMI_UNIFIED_MESSAGE__

#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "mdi_datatype.h"

/* micha1230 */
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "MessagesResourceData.h"

/* other files */
#include "ProtocolEvents.h"
#include "SettingProfile.h"
#include "IdleAppProt.h"

#include "AlarmFrameWorkProt.h"

#include "Conversions.h"

#include "DataAccountResDef.h"
#include "PhoneBookGprot.h"

#include "GpioInc.h"
#include "ProfileGprots.h"

#include "MemPoolContainerProt.h"
#include "CommonScreens.h"

#include "MessagesMiscell.h"
#include "SmsPsHandler.h"


#include "UnifiedMessageResDef.h"
#include "UnifiedMessageGProt.h"
#include "UnifiedMessageProt.h"

#ifdef __MMI_MMS_2__
#include "MMSAppGprot.h"
extern void mmi_umms_boot_up_file_format_generate_template(void);
extern void mmi_umms_message_settings_init(void);
extern void mmi_umms_set_current_mms_profile(BOOL boot_up);
extern void mmi_umms_templates_init(void);
#endif /* __MMI_MMS_2__ */

extern void mmi_umms_init_dispatch_functions(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_um_set_protocol_event_handler
 * DESCRIPTION
 *  Set protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_um_handle_ready_ind, PRT_MSG_ID_MMI_UM_READY_IND);
    SetProtocolEventHandler(mmi_um_handle_new_msg_ind, PRT_MSG_ID_MMI_UM_NEW_MSG_IND);
    SetProtocolEventHandler(mmi_um_handle_highlight_msg_ind, PRT_MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND);
    SetProtocolEventHandler(mmi_um_handle_refresh_ind, PRT_MSG_ID_MMI_UM_REFRESH_IND);
    SetProtocolEventHandler(mmi_um_handle_highlight_decided_by_UM_ind, PRT_MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND);
    SetProtocolEventHandler(mmi_um_handle_cancel_new_msg_ind, PRT_MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND);    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_ready_ind
 * DESCRIPTION
 *  Handle msg ready indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_ready_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ready_ind_struct *msg = (mmi_um_ready_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ready_ind(msg->result, msg->msg_type);
    mmi_umms_init_dispatch_functions();         
#ifdef __MMI_MMS_2__
    if(msg->msg_type == UM_MSG_TYPE_MMS)
    {
/*            mmi_umms_init_dispatch_functions();*/
	    mmi_umms_set_current_mms_profile(TRUE);
            mmi_umms_message_settings_init();    
	    mmi_umms_templates_init();
       /* mmi_umms_boot_up_file_format_generate_template();*/
        mmi_umms_set_status_icon_at_boot_up();
    }
#endif /* __MMI_MMS_2__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_new_msg_ind
 * DESCRIPTION
 *  Handle new msg indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_new_msg_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_new_msg_ind_struct *msg = (mmi_um_new_msg_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_new_msg_ind(msg->msg_type, msg->msg_box_type, msg->msg_index, msg->timestamp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_cancel_new_msg_ind
 * DESCRIPTION
 *  Handle cancel new msg indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_cancel_new_msg_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_cancel_new_msg_ind_struct *msg = (mmi_um_cancel_new_msg_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->msg_box_type == UM_MSG_BOX_TYPE_INBOX)
    {
        g_um_p->main.is_new_msg &= ~(msg->msg_type);
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_highlight_decided_by_UM_ind
 * DESCRIPTION
 *  Handle highlight msg indication, UM should process the algo to decide the highlight's postion 
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_highlight_decided_by_UM_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_highlight_decided_by_UM_struct *msg = (mmi_um_highlight_decided_by_UM_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_highlight_decided_by_um_ind(msg->msg_type, msg->msg_box_type, msg->msg_index);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_highlight_msg_ind
 * DESCRIPTION
 *  Handle highlight msg indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_highlight_msg_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_highlight_msg_ind_struct *msg = (mmi_um_highlight_msg_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_highlight_msg_ind(msg->msg_type, msg->msg_box_type, msg->msg_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_refresh_ind
 * DESCRIPTION
 *  Handle refresh indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_refresh_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_refresh_ind_struct *msg = (mmi_um_refresh_ind_struct*) inMsg;
    U16 current_screen_id = GetExitScrnID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (current_screen_id)
    {
        case (SCR_ID_UM_MAIN):
        {
            g_um_p->main.is_refresh = KAL_TRUE;
            mmi_um_pre_entry_main();
            g_um_p->main.is_refresh = KAL_FALSE;
            break;
        }
        case (SCR_ID_UM_INBOX):
        {
            if (msg->msg_box_type & UM_MSG_BOX_TYPE_INBOX)
            {
                g_um_p->main.is_refresh = KAL_TRUE;
                g_um_p->main.is_reset_folder_info = KAL_TRUE;
                mmi_um_pre_entry_inbox();
                DeleteScreenIfPresent(SCR_ID_UM_INBOX);
                g_um_p->main.is_refresh = KAL_FALSE;
            }
            break;
        }
        case (SCR_ID_UM_UNSENT):
        {
            if (msg->msg_box_type & UM_MSG_BOX_TYPE_UNSENT)
            {
                g_um_p->main.is_refresh = KAL_TRUE;
                g_um_p->main.is_reset_folder_info = KAL_TRUE;
                mmi_um_pre_entry_unsent();
                DeleteScreenIfPresent(SCR_ID_UM_UNSENT);
                g_um_p->main.is_refresh = KAL_FALSE;
            }
            break;
        }
        case (SCR_ID_UM_SENT):
        {
            if (msg->msg_box_type & UM_MSG_BOX_TYPE_SENT)
            {
                g_um_p->main.is_refresh = KAL_TRUE;
                g_um_p->main.is_reset_folder_info = KAL_TRUE;
                mmi_um_pre_entry_sent();
                DeleteScreenIfPresent(SCR_ID_UM_SENT);
                g_um_p->main.is_refresh = KAL_FALSE;
            }
            break;
        }
        case (SCR_ID_UM_DRAFT):
        {
            if (msg->msg_box_type & UM_MSG_BOX_TYPE_DRAFT)
            {
                g_um_p->main.is_refresh = KAL_TRUE;
                g_um_p->main.is_reset_folder_info = KAL_TRUE;
                mmi_um_pre_entry_draft();
                DeleteScreenIfPresent(SCR_ID_UM_DRAFT);
                g_um_p->main.is_refresh = KAL_FALSE;
            }
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case (SCR_ID_UM_ARCHIVE):
        {
            if (msg->msg_box_type & UM_MSG_BOX_TYPE_ARCHIVE)
            {
                g_um_p->main.is_refresh = KAL_TRUE;
                g_um_p->main.is_reset_folder_info = KAL_TRUE;
                mmi_um_pre_entry_archive();
                DeleteScreenIfPresent(SCR_ID_UM_ARCHIVE);
                g_um_p->main.is_refresh = KAL_FALSE;
            }
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case (SCR_ID_UM_SIM):
        {
            if (msg->msg_box_type & UM_MSG_BOX_TYPE_SIM)
            {
                g_um_p->main.is_refresh = KAL_TRUE;
                g_um_p->main.is_reset_folder_info = KAL_TRUE;
                mmi_um_pre_entry_simbox();
                DeleteScreenIfPresent(SCR_ID_UM_SIM);
                g_um_p->main.is_refresh = KAL_FALSE;
            }
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    
        case (SCR_ID_UM_DELETE_FOLDER):
        {
            g_um_p->main.is_refresh = KAL_TRUE;
            mmi_um_pre_entry_delete_folder();
            g_um_p->main.is_refresh = KAL_FALSE;
            break;
        }
        case (SCR_ID_UM_NEW_MSG_IND):
        {
            /* If the new msg is deleted by AT, the new msg indication screen should not be displayed. */
            EntryIdleScreen();
            break;
        }
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_delete_all_ind
 * DESCRIPTION
 *  Handle delete all indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_delete_all_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_delete_all_ind_struct *msg = (mmi_um_delete_all_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->delete_folder.folders_to_delete = (UmMsgBoxType)msg->msg_box_type;

    switch (msg->msg_box_type)
    {
        case UM_MSG_BOX_TYPE_INBOX:
        {
            mmi_um_set_processing_screen(STR_UM_INBOX_ID, STR_UM_DELETING_ID, IMG_GLOBAL_PROGRESS, 0);
            break;
        }
        case UM_MSG_BOX_TYPE_UNSENT:
        {
            mmi_um_set_processing_screen(STR_UM_UNSENT_ID, STR_UM_DELETING_ID, IMG_GLOBAL_PROGRESS, 0);
            break;
        }
        case UM_MSG_BOX_TYPE_SENT:
        {
            mmi_um_set_processing_screen(STR_UM_SENT_ID, STR_UM_DELETING_ID, IMG_GLOBAL_PROGRESS, 0);
            break;
        }
        case UM_MSG_BOX_TYPE_DRAFT:
        {
            mmi_um_set_processing_screen(STR_UM_DRAFT_ID, STR_UM_DELETING_ID, IMG_GLOBAL_PROGRESS, 0);
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case UM_MSG_BOX_TYPE_ARCHIVE:
        {
            mmi_um_set_processing_screen(STR_UM_ARCHIVE_ID, STR_UM_DELETING_ID, IMG_GLOBAL_PROGRESS, 0);
            break;
        }    
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case UM_MSG_BOX_TYPE_SIM:
        {
            mmi_um_set_processing_screen(STR_UM_SIM_ID, STR_UM_DELETING_ID, IMG_GLOBAL_PROGRESS, 0);
            break;
        }
    #endif  /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__*/
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    mmi_um_entry_processing_generic();

    switch (msg->msg_type)
    {
        case UM_MSG_TYPE_SMS:
        {
            mmi_um_delete_all_res_struct *msgRes;

            msgRes = (mmi_um_delete_all_res_struct*) construct_local_para(sizeof(*msgRes), TD_CTRL | TD_RESET);
            msgRes->result = KAL_TRUE;
            msgRes->msg_type = UM_MSG_TYPE_SMS;
            mmi_um_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_DELETE_ALL_RES, (oslParaType*) msgRes, NULL);
            break;
        }
        case UM_MSG_TYPE_MMS:
        {
            mmi_um_delete_all_res_struct *msgRes;

            msgRes = (mmi_um_delete_all_res_struct*) construct_local_para(sizeof(*msgRes), TD_CTRL | TD_RESET);
            msgRes->result = KAL_TRUE;
            msgRes->msg_type = UM_MSG_TYPE_MMS;
        #ifndef __MMI_MMS_2__
            mmi_um_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_DELETE_ALL_RES, (oslParaType*) msgRes, NULL);
        #else /* __MMI_MMS_2__ */
            mmi_um_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_DELETE_ALL_RES, (oslParaType*) msgRes, NULL);
        #endif /* __MMI_MMS_2__ */
            break;
        }

        case UM_MSG_TYPE_WAP_PUSH:
        {
            mmi_um_delete_all_res_struct *msgRes;

            msgRes = (mmi_um_delete_all_res_struct*) construct_local_para(sizeof(*msgRes), TD_CTRL | TD_RESET);
            msgRes->result = KAL_TRUE;
            msgRes->msg_type = UM_MSG_TYPE_WAP_PUSH;
            mmi_um_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_DELETE_ALL_RES, (oslParaType*) msgRes, NULL);
            break;
        }

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
    mmi_um_delete_folder_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_msg_num_req
 * DESCRIPTION
 *  get number of msg for each msg type
 * PARAMETERS
 *  void
 *  inMsg(?)        [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_get_msg_num_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 type = 0x01;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.pending_req_type = g_um_p->main.support_type;
    g_um_p->main.current_action = UM_ACTION_GET_MSG_NUM;

    g_um_p->msg_number.inbox_msg_number = 0;
    g_um_p->msg_number.inbox_unread_msg_number = 0;
    g_um_p->msg_number.unsent_msg_number = 0;
    g_um_p->msg_number.sent_msg_number = 0;
    g_um_p->msg_number.draft_msg_number = 0;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    g_um_p->msg_number.archive_msg_number = 0;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    g_um_p->msg_number.sim_msg_number = 0;
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    for (; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, type <<= 1)
    {
        if (mmi_um_check_support_type(type))
        {
            switch (type)
            {
                case UM_MSG_TYPE_SMS:
                {

                    mmi_um_get_msg_num_req_struct *msgReq;

                    msgReq = (mmi_um_get_msg_num_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_SMS;
                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_MMI,
                        0,
                        PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                    return;
                }
                case UM_MSG_TYPE_MMS:
                {
                    mmi_um_get_msg_num_req_struct *msgReq;

                    msgReq = (mmi_um_get_msg_num_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_MMS;
                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_WAP,
                        0,
                        PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                    return;
                }
                case UM_MSG_TYPE_WAP_PUSH:
                {
                    mmi_um_get_msg_num_req_struct *msgReq;

                    msgReq = (mmi_um_get_msg_num_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_WAP,
                        0,
                        PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                    return;
                }

                default:
                    MMI_ASSERT(0);
                    return;
            }

        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_msg_num_rsp
 * DESCRIPTION
 *  get number of msg for each msg type
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_get_msg_num_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_rsp_struct *msg = (mmi_um_get_msg_num_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_um_p->main.current_action != UM_ACTION_GET_MSG_NUM)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_get_msg_num_rsp Ignore obsolete response *\n");
        return;
    }

    MMI_ASSERT(msg->result);
    MMI_ASSERT(mmi_um_check_support_type(msg->msg_type));

    if (!(g_um_p->main.pending_req_type & msg->msg_type))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_get_msg_num_rsp Unexpected message type *\n");
        return;
    }

    if (g_um_p->main.state == UM_STATE_IDLE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_get_msg_num_rsp UM_STATE_IDLE *\n");
        return;
    }

    g_um_p->main.pending_req_type &= ~(msg->msg_type);

    g_um_p->msg_number.inbox_msg_number += msg->inbox_unread_msg_number + msg->inbox_read_msg_number;
    g_um_p->msg_number.inbox_unread_msg_number += msg->inbox_unread_msg_number;
    g_um_p->msg_number.unsent_msg_number += msg->unsent_msg_number;
    g_um_p->msg_number.sent_msg_number += msg->sent_msg_number;
    g_um_p->msg_number.draft_msg_number += msg->draft_msg_number;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    g_um_p->msg_number.archive_msg_number += msg->archive_msg_number;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (msg->msg_type == UM_MSG_TYPE_SMS)
    {
        g_um_p->msg_number.sim_msg_number += msg->sim_msg_number;
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    mmi_um_handle_get_msg_num_rsp();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_list_info_req
 * DESCRIPTION
 *  get list info request funtion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_get_list_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 type = 0x01;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.pending_req_type = g_um_p->main.support_type;
    g_um_p->folder.msg_number_in_list = 0;
    g_um_p->main.current_action = UM_ACTION_GET_LIST_INFO;

    memset(g_um_p->folder.msg_list, 0, sizeof(mmi_um_msg_box_info_struct) * MMI_UM_MAX_MSG_NUM);

    for (; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, type <<= 1)
    {
        if (mmi_um_check_support_type(type))
        {
            switch (type)
            {
                case UM_MSG_TYPE_SMS:
                {
                    mmi_um_get_list_req_struct *msgReq;

                    msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_SMS;
                    msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                    msgReq->start_entry = 0;

                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_MMI,
                        0,
                        PRT_MSG_ID_MMI_UM_GET_LIST_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                    if (msgReq->msg_box_type == UM_MSG_BOX_TYPE_SIM)
                    {
                        g_um_p->main.pending_req_type = UM_MSG_TYPE_SMS;
                    }
                #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
                    return;
                }
                case UM_MSG_TYPE_MMS:
                {
                    mmi_um_get_list_req_struct *msgReq;

                    msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_MMS;
                    msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                    msgReq->start_entry = 0;

                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_WAP,
                        0,
                        PRT_MSG_ID_MMI_UM_GET_LIST_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                    return;
                }
                case UM_MSG_TYPE_WAP_PUSH:
                {
                    mmi_um_get_list_req_struct *msgReq;

                    msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                    msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                    msgReq->start_entry = 0;

                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_WAP,
                        0,
                        PRT_MSG_ID_MMI_UM_GET_LIST_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                    return;
                }

                default:
                    MMI_ASSERT(0);
                    return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_list_info_rsp
 * DESCRIPTION
 *  get number of msg for each msg type
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_get_list_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_list_rsp_struct *msg = (mmi_um_get_list_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_um_p->main.current_action != UM_ACTION_GET_LIST_INFO)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_get_list_info_rsp Ignore obsolete response *\n");
        return;
    }

    if (g_um_p->main.state == UM_STATE_IDLE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_get_list_info_rsp UM_STATE_IDLE *\n");
        return;
    }

    MMI_ASSERT(msg->result);
    MMI_ASSERT(mmi_um_check_support_type(msg->msg_type));

    mmi_um_insert_list_info(msg->msg_type, msg->msg_number, msg->list_info);

    if (msg->more)
    {
        switch (msg->msg_type)
        {
            case UM_MSG_TYPE_SMS:
            {
                mmi_um_get_list_req_struct *msgReq;

                msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                msgReq->msg_type = UM_MSG_TYPE_SMS;
                msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                msgReq->start_entry = msg->start_entry + msg->msg_number;

                mmi_um_send_message(MOD_MMI, MOD_MMI, 0, PRT_MSG_ID_MMI_UM_GET_LIST_REQ, (oslParaType*) msgReq, NULL);
                return;
            }
            case UM_MSG_TYPE_MMS:
            {
                mmi_um_get_list_req_struct *msgReq;

                msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                msgReq->msg_type = UM_MSG_TYPE_MMS;
                msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                msgReq->start_entry = msg->start_entry + msg->msg_number;

                mmi_um_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_GET_LIST_REQ, (oslParaType*) msgReq, NULL);
                return;
            }
            case UM_MSG_TYPE_WAP_PUSH:
            {
                mmi_um_get_list_req_struct *msgReq;

                msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                msgReq->start_entry = msg->start_entry + msg->msg_number;

                mmi_um_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_GET_LIST_REQ, (oslParaType*) msgReq, NULL);
                return;
            }

            default:
                MMI_ASSERT(0);
        }
    }

    g_um_p->main.pending_req_type &= ~(msg->msg_type);

    mmi_um_handle_get_list_info_rsp();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_msg_info_req
 * DESCRIPTION
 *  get msg detail information
 * PARAMETERS
 *  void
 *  inMsg(?)        [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_get_msg_info_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 start_index = g_um_p->mem_pool_info.not_avail_pool * MMI_UM_MAX_MSG_PER_PAGE;
    U16 end_index = ((g_um_p->mem_pool_info.not_avail_pool + 1) * MMI_UM_MAX_MSG_PER_PAGE) - 1;
    U16 msg_num = 0;
    UmMsgType type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->get_msg_detail.start_index_sms = 0;
    g_um_p->get_msg_detail.msg_num_to_get_sms = 0;
    g_um_p->get_msg_detail.start_index_mms = 0;
    g_um_p->get_msg_detail.msg_num_to_get_mms = 0;
    g_um_p->get_msg_detail.start_index_wap_push = 0;
    g_um_p->get_msg_detail.msg_num_to_get_wap_push = 0;

    g_um_p->get_msg_detail.num_in_temp_buffer = 0;

    g_um_p->main.pending_req_type = 0;
    g_um_p->main.current_action = UM_ACTION_GET_MSG_INFO;

    memset(&g_um_p->get_msg_detail.temp_buffer, 0, sizeof(mmi_um_msg_detail_struct) * MMI_UM_MAX_MSG_PER_PAGE);

    for (i = start_index; (i <= end_index) && (i < g_um_p->folder.msg_number_in_list); i++)
    {
        type = g_um_p->folder.msg_list[i].msg_type;

        switch (type)
        {
            case UM_MSG_TYPE_SMS:
            {
                if (g_um_p->get_msg_detail.msg_num_to_get_sms == 0)
                {
                    g_um_p->main.pending_req_type |= UM_MSG_TYPE_SMS;
                    g_um_p->get_msg_detail.start_index_sms = g_um_p->folder.msg_list[i].list_info.msg_index;
                }
                g_um_p->get_msg_detail.msg_num_to_get_sms++;
                g_um_p->get_msg_detail.temp_buffer[msg_num].msg_type = UM_MSG_TYPE_SMS;
                break;
            }
            case UM_MSG_TYPE_MMS:
            {
                if (g_um_p->get_msg_detail.msg_num_to_get_mms == 0)
                {
                    g_um_p->main.pending_req_type |= UM_MSG_TYPE_MMS;
                    g_um_p->get_msg_detail.start_index_mms = g_um_p->folder.msg_list[i].list_info.msg_index;
                }
                g_um_p->get_msg_detail.msg_num_to_get_mms++;
                g_um_p->get_msg_detail.temp_buffer[msg_num].msg_type = UM_MSG_TYPE_MMS;
                break;
            }
            case UM_MSG_TYPE_WAP_PUSH:
            {
                if (g_um_p->get_msg_detail.msg_num_to_get_wap_push == 0)
                {
                    g_um_p->main.pending_req_type |= UM_MSG_TYPE_WAP_PUSH;
                    g_um_p->get_msg_detail.start_index_wap_push = g_um_p->folder.msg_list[i].list_info.msg_index;
                }
                g_um_p->get_msg_detail.msg_num_to_get_wap_push++;
                g_um_p->get_msg_detail.temp_buffer[msg_num].msg_type = UM_MSG_TYPE_WAP_PUSH;
                break;
            }
            default:
                MMI_ASSERT(0);
                break;
        }

        msg_num++;
    }

    /* If no message needed to get, enter current folder */
    if (g_um_p->get_msg_detail.msg_num_to_get_sms == 0 && 
        g_um_p->get_msg_detail.msg_num_to_get_mms == 0 &&
        g_um_p->get_msg_detail.msg_num_to_get_wap_push == 0)
    {
        mmi_um_enter_curr_folder();
        return;
    }

    type = 0x01;

    for (i = 0; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, type <<= 1)
    {
        if (mmi_um_check_support_type(type))
        {
            switch (type)
            {
                case UM_MSG_TYPE_SMS:
                {
                    if (g_um_p->get_msg_detail.msg_num_to_get_sms > 0)
                    {
                        mmi_um_get_msg_info_req_struct *msgReq;

                        msgReq = (mmi_um_get_msg_info_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_SMS;
                        msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                        msgReq->start_entry = g_um_p->get_msg_detail.start_index_sms;
                        msgReq->msg_number = g_um_p->get_msg_detail.msg_num_to_get_sms;

                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_MMI,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    break;
                }
                case UM_MSG_TYPE_MMS:
                {
                    if (g_um_p->get_msg_detail.msg_num_to_get_mms > 0)
                    {
                        mmi_um_get_msg_info_req_struct *msgReq;

                        msgReq = (mmi_um_get_msg_info_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_MMS;
                        msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                        msgReq->start_entry = g_um_p->get_msg_detail.start_index_mms;
                        msgReq->msg_number = g_um_p->get_msg_detail.msg_num_to_get_mms;

                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    break;
                }
                case UM_MSG_TYPE_WAP_PUSH:
                {
                    mmi_um_get_msg_info_req_struct *msgReq;

                    if (g_um_p->get_msg_detail.msg_num_to_get_wap_push > 0)
                    {
                        msgReq = (mmi_um_get_msg_info_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                        msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                        msgReq->start_entry = g_um_p->get_msg_detail.start_index_wap_push;
                        msgReq->msg_number = g_um_p->get_msg_detail.msg_num_to_get_wap_push;

                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    break;
                }

                default:
                    MMI_ASSERT(0);
                    return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_msg_info_rsp
 * DESCRIPTION
 *  get number of msg for each msg type
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_get_msg_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_info_rsp_struct *msg = (mmi_um_get_msg_info_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_um_p->main.current_action != UM_ACTION_GET_MSG_INFO)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_get_msg_info_rsp Ignore obsolete response *\n");
        return;
    }

    if (g_um_p->main.state == UM_STATE_IDLE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_get_msg_info_rsp UM_STATE_IDLE *\n");
        return;
    }

    MMI_ASSERT(msg->result);
    MMI_ASSERT(mmi_um_check_support_type(msg->msg_type));

    g_um_p->main.pending_req_type &= ~(msg->msg_type);

    mmi_um_insert_msg_info(msg->msg_type, msg->msg_number, msg->msg_info);

    mmi_um_handle_get_msg_info_rsp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_delete_folder_req
 * DESCRIPTION
 *  Delete function of delete folder for unified message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_delete_folder_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 type = 0x01;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.pending_req_type = 0;
    g_um_p->main.pending_req_type = g_um_p->main.support_type;
    g_um_p->delete_folder.result = KAL_TRUE;
    g_um_p->main.current_action = UM_ACTION_DELETE_FOLDER;

    for (; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, type <<= 1)
    {
        if (mmi_um_check_support_type(type))
        {
            switch (type)
            {
                case UM_MSG_TYPE_SMS:
                {
                    mmi_um_delete_folder_req_struct *msgReq;

                    msgReq = (mmi_um_delete_folder_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_SMS;
                    msgReq->msg_box_type = (UmMsgBoxType)g_um_p->delete_folder.folders_to_delete;
                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_MMI,
                        0,
                        PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                    if (msgReq->msg_box_type == UM_MSG_BOX_TYPE_SIM)
                    {
                        g_um_p->main.pending_req_type = UM_MSG_TYPE_SMS;
                    }
                #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
                    return;
                }
                case UM_MSG_TYPE_MMS:
                {
                    mmi_um_delete_folder_req_struct *msgReq;

                    msgReq = (mmi_um_delete_folder_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_MMS;
                    msgReq->msg_box_type = (UmMsgBoxType)g_um_p->delete_folder.folders_to_delete;
                #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                    msgReq->msg_box_type &= ~UM_MSG_BOX_TYPE_SIM;                    
                #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_WAP,
                        0,
                        PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                    return;
                }
                case UM_MSG_TYPE_WAP_PUSH:
                {
                    mmi_um_delete_folder_req_struct *msgReq;

                    msgReq = (mmi_um_delete_folder_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                    msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                    msgReq->msg_box_type = (UmMsgBoxType)g_um_p->delete_folder.folders_to_delete;
                #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                    msgReq->msg_box_type &= ~UM_MSG_BOX_TYPE_SIM;                    
                #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
                    mmi_um_send_message(
                        MOD_MMI,
                        MOD_WAP,
                        0,
                        PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
                        (oslParaType*) msgReq,
                        NULL);
                    return;
                }

                default:
                    MMI_ASSERT(0);
                    return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_delete_folder_rsp
 * DESCRIPTION
 *  Delete function of delete folder for unified message.
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_delete_folder_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_delete_folder_rsp_struct *msg = (mmi_um_delete_folder_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_um_p->main.current_action != UM_ACTION_DELETE_FOLDER)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_delete_folder_rsp Ignore obsolete response *\n");
        return;
    }

    if (g_um_p->main.state == UM_STATE_IDLE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_delete_folder_rsp UM_STATE_IDLE *\n");
        return;
    }

    MMI_ASSERT(mmi_um_check_support_type(msg->msg_type));

    mmi_um_handle_delete_folder_rsp(msg->msg_type, msg->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_get_msg_num_rsp
 * DESCRIPTION
 *  handle screen flow after getting msg number rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_get_msg_num_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_um_p->main.pending_req_type == 0)
    {
        switch (g_um_p->main.state)
        {
            case UM_STATE_ENTRY_MAIN_MENU:
            {
                mmi_um_entry_main();
                break;
            }

            case UM_STATE_ENTRY_INBOX:
            {
                if (g_um_p->msg_number.inbox_msg_number == 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) EMPTY_LIST_TONE);

                    /* If the new msg is deleted by AT, is_new_msg should be reset. */
                    g_um_p->main.is_new_msg = KAL_FALSE;
                    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                }
                else
                {
                    mmi_um_get_list_info_req();
                }
                break;
            }

            case UM_STATE_ENTRY_UNSENT:
            {
                if (g_um_p->msg_number.unsent_msg_number == 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) EMPTY_LIST_TONE);
                    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                }
                else
                {
                    mmi_um_get_list_info_req();
                }
                break;
            }

            case UM_STATE_ENTRY_SENT:
            {
                if (g_um_p->msg_number.sent_msg_number == 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) EMPTY_LIST_TONE);
                    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                }
                else
                {
                    mmi_um_get_list_info_req();
                }
                break;
            }

            case UM_STATE_ENTRY_DRAFT:
            {
                if (g_um_p->msg_number.draft_msg_number == 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) EMPTY_LIST_TONE);
                    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                }
                else
                {
                    mmi_um_get_list_info_req();
                }
                break;
            }
            
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case UM_STATE_ENTRY_ARCHIVE:
            {
                if (g_um_p->msg_number.archive_msg_number == 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) EMPTY_LIST_TONE);
                    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                }
                else
                {
                    mmi_um_get_list_info_req();
                }
                break;
            }
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            case UM_STATE_ENTRY_SIM:
            {
                if (g_um_p->msg_number.sim_msg_number == 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) EMPTY_LIST_TONE);
                    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                }
                else
                {
                    mmi_um_get_list_info_req();
                }
                break;
            }       
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

            case UM_STATE_ENTRY_DELETE_FOLDER:
            {
                mmi_um_entry_delete_folder();
                break;
            }

            case UM_STATE_ENTRY_NEW_MSG_IND:
            {
                /* If not on new msg dummy screen, do nothing. */
                if (GetExitScrnID() != SCR_ID_UM_NEW_MSG_DUMMY_IND)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMsg.c] mmi_um_handle_get_msg_num_rsp NOT on new msg dummy screen *\n");

                    return;
                }

                if (g_um_p->msg_number.inbox_unread_msg_number == 0)
                {
                    /* If the msg is deleted, ex. by AT, change design to not display new msg screen */
                    g_um_p->main.is_new_msg = KAL_FALSE;
                }
                else
                {
                    /* After the msg number is ready, enter idle screen again. */
                    g_um_p->main.is_ready_for_new_msg = KAL_TRUE;
                }
                
                EntryIdleScreen();
                break;
            }
            default:
            {
                MMI_ASSERT(0);
            }
        }
    }
    else    /* if(g_um_p->main.pending_req_type != 0) */
    {
        U8 i = 0;
        U8 type = 0x01;

        for (; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, type <<= 1)
        {
            if (mmi_um_check_support_type(type) && (type & (g_um_p->main.pending_req_type)))
            {
                switch (type)
                {
                    case UM_MSG_TYPE_SMS:
                    {

                        mmi_um_get_msg_num_req_struct *msgReq;

                        msgReq = (mmi_um_get_msg_num_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_SMS;
                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_MMI,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    case UM_MSG_TYPE_MMS:
                    {
                        mmi_um_get_msg_num_req_struct *msgReq;

                        msgReq = (mmi_um_get_msg_num_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_MMS;
                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    case UM_MSG_TYPE_WAP_PUSH:
                    {
                        mmi_um_get_msg_num_req_struct *msgReq;

                        msgReq = (mmi_um_get_msg_num_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }

                    default:
                        MMI_ASSERT(0);
                        return;
                }
            }
        }
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_get_list_info_rsp
 * DESCRIPTION
 *  handle screen flow after getting list info rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_get_list_info_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_um_p->main.pending_req_type == 0)
    {
        switch (g_um_p->main.state)
        {
            case UM_STATE_ENTRY_INBOX:
            {
                if (IsScreenPresent(SCR_ID_UM_INBOX))
                {
                    if (g_um_p->folder.msg_number_in_list == 0)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_EMPTY),
                            IMG_GLOBAL_EMPTY,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) EMPTY_LIST_TONE);

                        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                        DeleteScreenIfPresent(SCR_ID_UM_INBOX);
                        g_um_p->main.is_reset_folder_info = KAL_TRUE;
                        return;
                    }
                    mmi_um_get_msg_info_req();                    
                }
                else
                {
                    mmi_um_entry_folder();
                }
                break;
            }
            case UM_STATE_ENTRY_UNSENT:
            {
                if (IsScreenPresent(SCR_ID_UM_UNSENT))
                {
                    if (g_um_p->folder.msg_number_in_list == 0)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_EMPTY),
                            IMG_GLOBAL_EMPTY,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) EMPTY_LIST_TONE);

                        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                        DeleteScreenIfPresent(SCR_ID_UM_UNSENT);
                        g_um_p->main.is_reset_folder_info = KAL_TRUE;
                        return;
                    }
                    mmi_um_get_msg_info_req();  
                }
                else
                {
                    mmi_um_entry_folder();
                }
                break;
            }
            case UM_STATE_ENTRY_SENT:
            {
                if (IsScreenPresent(SCR_ID_UM_SENT))
                {
                    if (g_um_p->folder.msg_number_in_list == 0)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_EMPTY),
                            IMG_GLOBAL_EMPTY,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) EMPTY_LIST_TONE);

                        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                        DeleteScreenIfPresent(SCR_ID_UM_SENT);
                        g_um_p->main.is_reset_folder_info = KAL_TRUE;
                        return;
                    }
                    mmi_um_get_msg_info_req();  
                }
                else
                {
                    mmi_um_entry_folder();
                }
                break;
            }
            case UM_STATE_ENTRY_DRAFT:
            {
                if (IsScreenPresent(SCR_ID_UM_DRAFT))
                {
                    if (g_um_p->folder.msg_number_in_list == 0)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_EMPTY),
                            IMG_GLOBAL_EMPTY,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) EMPTY_LIST_TONE);

                        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                        DeleteScreenIfPresent(SCR_ID_UM_DRAFT);
                        g_um_p->main.is_reset_folder_info = KAL_TRUE;
                        return;
                    }
                    mmi_um_get_msg_info_req();  
                }
                else
                {
                    mmi_um_entry_folder();
                }
                break;
            }            
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case UM_STATE_ENTRY_ARCHIVE:
            {
                if (IsScreenPresent(SCR_ID_UM_ARCHIVE))
                {
                    if (g_um_p->folder.msg_number_in_list == 0)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_EMPTY),
                            IMG_GLOBAL_EMPTY,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) EMPTY_LIST_TONE);

                        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                        DeleteScreenIfPresent(SCR_ID_UM_ARCHIVE);
                        g_um_p->main.is_reset_folder_info = KAL_TRUE;
                        return;
                    }
                    mmi_um_get_msg_info_req();  
                }
                else
                {
                    mmi_um_entry_folder();
                }
                break;
            }            
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
            
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            case UM_STATE_ENTRY_SIM:
            {
                if (IsScreenPresent(SCR_ID_UM_SIM))
                {
                    if (g_um_p->folder.msg_number_in_list == 0)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_EMPTY),
                            IMG_GLOBAL_EMPTY,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) EMPTY_LIST_TONE);

                        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
                        DeleteScreenIfPresent(SCR_ID_UM_SIM);
                        g_um_p->main.is_reset_folder_info = KAL_TRUE;
                        return;
                    }
                    mmi_um_get_msg_info_req();  
                }
                else
                {
                    mmi_um_entry_folder();
                }
                break;
            }                   
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        
            /* If user selects RSK back in progressing screen, reset the list info */
            default:
            {
                mmi_um_reset_folder_info();
                return;
            }
        }
    }
    else
    {
        U8 i = 0;
        U8 type = 0x01;

        for (; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, type <<= 1)
        {
            if (mmi_um_check_support_type(type) && (type & (g_um_p->main.pending_req_type)))
            {
                switch (type)
                {
                    case UM_MSG_TYPE_SMS:
                    {
                        mmi_um_get_list_req_struct *msgReq;

                        msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_SMS;
                        msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                        msgReq->start_entry = 0;

                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_MMI,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_LIST_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    case UM_MSG_TYPE_MMS:
                    {
                        mmi_um_get_list_req_struct *msgReq;

                        msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_MMS;
                        msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                        msgReq->start_entry = 0;

                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_LIST_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    case UM_MSG_TYPE_WAP_PUSH:
                    {
                        mmi_um_get_list_req_struct *msgReq;

                        msgReq = (mmi_um_get_list_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                        msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                        msgReq->start_entry = 0;

                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_GET_LIST_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }

                    default:
                        MMI_ASSERT(0);
                        return;
                }
            }
        }
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_get_msg_info_rsp
 * DESCRIPTION
 *  handle screen flow after getting list info rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_get_msg_info_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_um_p->main.pending_req_type == 0)
    {
        if (mmi_um_is_list_ready())
        {
            mmi_um_enter_curr_folder();
        }
        else
        {
            mmi_um_get_msg_info_req();
        }
    }
    else
    {
        U16 i = 0;
        UmMsgType type = 0x01;

        for (i = 0; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, type <<= 1)
        {
            if (mmi_um_check_support_type(type) && (type & (g_um_p->main.pending_req_type)))
            {
                switch (type)
                {
                    case UM_MSG_TYPE_SMS:
                    {
                        if (g_um_p->get_msg_detail.msg_num_to_get_sms > 0)
                        {
                            mmi_um_get_msg_info_req_struct *msgReq;

                            msgReq = (mmi_um_get_msg_info_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                            msgReq->msg_type = UM_MSG_TYPE_SMS;
                            msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                            msgReq->start_entry = g_um_p->get_msg_detail.start_index_sms;
                            msgReq->msg_number = g_um_p->get_msg_detail.msg_num_to_get_sms;

                            mmi_um_send_message(
                                MOD_MMI,
                                MOD_MMI,
                                0,
                                PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
                                (oslParaType*) msgReq,
                                NULL);
                        }
                        return;
                    }
                    case UM_MSG_TYPE_MMS:
                    {
                        if (g_um_p->get_msg_detail.msg_num_to_get_mms > 0)
                        {
                            mmi_um_get_msg_info_req_struct *msgReq;

                            msgReq = (mmi_um_get_msg_info_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                            msgReq->msg_type = UM_MSG_TYPE_MMS;
                            msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                            msgReq->start_entry = g_um_p->get_msg_detail.start_index_mms;
                            msgReq->msg_number = g_um_p->get_msg_detail.msg_num_to_get_mms;

                            mmi_um_send_message(
                                MOD_MMI,
                                MOD_WAP,
                                0,
                                PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
                                (oslParaType*) msgReq,
                                NULL);
                        }
                        return;
                    }
                    case UM_MSG_TYPE_WAP_PUSH:
                    {
                        mmi_um_get_msg_info_req_struct *msgReq;

                        if (g_um_p->get_msg_detail.msg_num_to_get_wap_push > 0)
                        {
                            msgReq = (mmi_um_get_msg_info_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                            msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                            msgReq->msg_box_type = g_um_p->folder.current_msg_box;
                            msgReq->start_entry = g_um_p->get_msg_detail.start_index_wap_push;
                            msgReq->msg_number = g_um_p->get_msg_detail.msg_num_to_get_wap_push;

                            mmi_um_send_message(
                                MOD_MMI,
                                MOD_WAP,
                                0,
                                PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
                                (oslParaType*) msgReq,
                                NULL);
                        }
                        return;
                    }

                    default:
                        MMI_ASSERT(0);
                        return;
                }
            }
        }
        MMI_ASSERT(0);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_delete_folder_rsp
 * DESCRIPTION
 *  Delete function of delete folder for unified message.
 * PARAMETERS
 *  type        [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_delete_folder_rsp(UmMsgType type, kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.pending_req_type &= ~(type);

    if (!result)
    {
        g_um_p->delete_folder.result = KAL_FALSE;
    }

    if (g_um_p->main.pending_req_type == 0)
    {
        if (g_um_p->delete_folder.result)
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
            
    #ifdef __MMI_MMS_2__
        mmi_umms_handle_delete_all_mms();
    #endif /* __MMI_MMS_2__ */

        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        }

        /* Reset the new msg flag if the inbox messages are all deleted. */ 
        if (g_um_p->delete_folder.folders_to_delete == UM_MSG_BOX_TYPE_INBOX)
        {
            g_um_p->main.is_new_msg = KAL_FALSE;
        }
        
        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
    }
    else    /* g_um_p->main.pending_req_type != 0 */
    {
        U8 i = 0;
        U8 type = 0x01;

        for (; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, type <<= 1)
        {
            if (mmi_um_check_support_type(type) && (type & (g_um_p->main.pending_req_type)))
            {
                switch (type)
                {
                    case UM_MSG_TYPE_SMS:
                    {
                        mmi_um_delete_folder_req_struct *msgReq;

                        msgReq = (mmi_um_delete_folder_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_SMS;
                        msgReq->msg_box_type = (UmMsgBoxType)g_um_p->delete_folder.folders_to_delete;
                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    case UM_MSG_TYPE_MMS:
                    {
                        mmi_um_delete_folder_req_struct *msgReq;

                        msgReq = (mmi_um_delete_folder_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_MMS;
                        msgReq->msg_box_type = (UmMsgBoxType)g_um_p->delete_folder.folders_to_delete;
                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    case UM_MSG_TYPE_WAP_PUSH:
                    {
                        mmi_um_delete_folder_req_struct *msgReq;

                        msgReq = (mmi_um_delete_folder_req_struct*) construct_local_para(sizeof(*msgReq), TD_CTRL | TD_RESET);
                        msgReq->msg_type = UM_MSG_TYPE_WAP_PUSH;
                        msgReq->msg_box_type = (UmMsgBoxType)g_um_p->delete_folder.folders_to_delete;
                        mmi_um_send_message(
                            MOD_MMI,
                            MOD_WAP,
                            0,
                            PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
                            (oslParaType*) msgReq,
                            NULL);
                        return;
                    }
                    default:
                        MMI_ASSERT(0);
                        return;
                }
            }
        }
        MMI_ASSERT(0);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_send_message
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
void mmi_um_send_message(
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

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* _MMI_UNIFIED_MESSAGE_MSG_C */ 

