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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * bra_env.c
 *
 * Created by Mats Tedenvall	20020710	13:04
 *
 * Revision history:
 *
 */
#include "bra_cfg.h"
#include "bra_if.h"
#include "bra_main.h"
#include "bra_sig.h"
#include "bra_view.h"
#include "bra_prs.h"
#include "bra_rpl.h"
#include "bra_psl.h"
#include "bra_act.h"
#include "bra_dlg.h"
#include "bra_bkm.h"
#include "bra_set.h" 
#ifdef BRA_CFG_OFFLINE_PAGES
#include "bra_ofln.h"
#endif

#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_file.h"
#include "msf_wid.h"
#include "msf_errc.h"
#include "msf_act.h"

#include "bra_sif.h"
#include "brs_if.h"

#ifdef BRA_CONFIG_UIS_PUSH_SL
#include "uis_if.h"
#endif
#ifdef BRA_CONFIG_SECURITY
#include "sec_if.h"
#endif
#ifdef BRA_CONFIG_PROVISIONING
#include "prs_if.h"
#endif


#ifdef BRA_CFG_CCA
#include "bra_cca.h"
#endif


#include "bra_cbm.h"

#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif



extern int     bra_browser_entry_from_menu;


/**********************************************************************
 * Function declarations
 **********************************************************************/

static void
bra_receive (MSF_UINT8 src_module, MSF_UINT16 signal, void* p);
#ifdef MMS_SUPPORT
 extern void MMSa_start(void);
#endif

/**********************************************************************
 * Function definitions
 **********************************************************************/

void
BRAc_start (void) 
{
  MSF_LOG_FC_BEGIN(BRAc_start)
  MSF_LOG_FC_PRE_IMPL

  MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_LOW, MSF_MODID_BRA, BRA_ENV_669A79351E9FCA96532CB17C61493DD6, "BRA: BRAc_start\n"));
  bra_init ();
  MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_LOW, MSF_MODID_BRA, BRA_ENV_C48251C74F892F5C3415CC61528E9372, "BRA: Initialised\n"));

  MSF_LOG_FC_END
#ifdef MMS_SUPPORT
  MMSa_start();
#endif
}

void
BRAc_kill (void)
{
    MSF_FILE_CLOSE_ALL (MSF_MODID_BRA);         /* Only if the module use files. */
    MSF_WIDGET_RELEASE_ALL (MSF_MODID_BRA);     /* Only if the module use widgets. */
    MSF_MEM_FREE_ALL (MSF_MODID_BRA);
    MSF_KILL_TASK (MSF_MODID_BRA);
}
void
BRAc_run (void)
{
  MSF_LOG_FC_BEGIN(BRAc_run)
    MSF_LOG_FC_PRE_IMPL
    
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_ENV_950B2B4B52FD35CF317711C4C9D412AE, "BRA: BRAc_run\n"));
  /* Set the global variable, the module is now inside the Run function. */
  bra_inside_run = 1;
  
  /* Make a setjmp, so the module can jump back to this point if the memory runs
     out. */
  if (setjmp (bra_jmpbuf) == 0) {
   /*
    * Get external signals and process one internal signal.
    */
    while (MSF_SIGNAL_RETRIEVE (MSF_MODID_BRA, bra_receive));
    bra_signal_process ();
  }
  else {
   /*
    * A longjmp from xxx_exception_handler. If we are here there is no more
    * memory, and the situation could not be worse.
    * Send out an error and terminate as the figure above.
    */
    MSF_ERROR (MSF_MODID_BRA, MSF_ERR_MODULE_OUT_OF_MEMORY);
    MSF_FILE_CLOSE_ALL (MSF_MODID_BRA);         /* Only if the module use files. */
    MSF_WIDGET_RELEASE_ALL (MSF_MODID_BRA);     /* Only if the module use widgets. */
    MSF_MEM_FREE_ALL (MSF_MODID_BRA);
    MSF_MODULE_IS_TERMINATED (MSF_MODID_BRA);
    MSF_SIGNAL_DEREGISTER_QUEUE (MSF_MODID_BRA);
    MSF_KILL_TASK (MSF_MODID_BRA);
  }
  
  /* Clear the global variable, the module is now outside the Run function. */
  bra_inside_run = 0;
  
  MSF_LOG_FC_END
}

int
BRAc_wantsToRun (void)
{
  int returnVal = 0;
  MSF_LOG_FC_BEGIN(BRAc_wantsToRun)
  MSF_LOG_FC_PRE_IMPL

  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_ENV_649B55B5C3CB24968858B5CFDE5B3D21, "BRA: BRAc_wantsToRun\n"));
  if ((MSF_SIGNAL_QUEUE_LENGTH (MSF_MODID_BRA) > 0) || !bra_signal_queue_is_empty ())
  {
    returnVal = 1;
  }

  MSF_LOG_FC_INT32(returnVal, NULL);
  MSF_LOG_FC_END
  return returnVal;
}

/*
 * Place a received external signal in the internal queue
 * of the appropriate module.
 */
static void
bra_receive (MSF_UINT8 src_module, MSF_UINT16 signal, void* p)
{
  MSF_INT32 id;

  src_module = src_module;

  /*************************************************************
   * Act package Q03C1
   *************************************************************/
  switch (msf_act_handle_signal (bra_act_get_handle(), signal, p, &id)) {
  case MSF_PACKAGE_SIGNAL_HANDLED:
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_1655ED7BE2CB1DE74F2C6A7778AFED11, "BRA: Received MSF_PACKAGE_SIGNAL_HANDLED from Act package\n"));
    /* The signal was handled by the act package. */
    return;
  case MSF_PACKAGE_SIGNAL_NOT_HANDLED:
    /* The signal must be proccessed by the module itself.*/
    break;
  case MSF_PACKAGE_OPERATION_COMPLETE:
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_D8A03CF2C96AC2FA477FDD693454B27F, "BRA: Received MSF_PACKAGE_OPERATION_COMPLETE from Act package\n"));
    BRA_SIGNAL_SENDTO_I (W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_ACT_FINISHED, id);
    BRA_FREE (p);
    return;
  }
    
  switch (signal) {
    case BRA_SIG_CREATE_UI:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
            BRA_ENV_RECEIVE_SIG_CREATE_UI, "BRA: Received BRA_SIG_CREATE_UI\n"));
      bra_handle_create_ui(p);
      break;
    case BRA_SIG_DESTROY_UI:
      bra_handle_destroy_ui();
      break;
    case BRA_SIG_SHOW_AUTH_DIALOG:
      bra_show_auth_dialog(p);
      BRA_FREE (p);
      break;      
    case BRA_SIG_SHOW_DIALOG:
      bra_show_dialog(p);
      BRA_FREE (p);
      break;
    case BRA_SIG_SHOW_DIALOG_EXT:
      bra_show_dialog_ext(p);
      BRA_FREE (p);
      break;
    case BRA_SIG_WTAI_MAKE_CALL:
      bra_make_call(p);
      BRA_FREE (p);
      break;
    case BRA_SIG_WTAI_SEND_DTMF:
      bra_send_dtmf(p);
      BRA_FREE (p);
      break;
    case BRA_SIG_WTAI_PB_ADD_ENTRY:
      bra_pb_add_entry(p);
      BRA_FREE (p);
      break;
    case BRA_SIG_HANDLE_EXTSCHEME:
      bra_handle_extscheme(p);
      BRA_FREE (p);
      break;
    case BRA_SIG_BEARER_STATUS:
      bra_sif_handle_bearer_status(((bra_handle_bearer_status_t*)p)->bearerType, ((bra_handle_bearer_status_t*)p)->status);
      BRA_FREE(p);
      break;
    case BRA_SIG_DOWNLOAD_COMPLETE:
      bra_view_download_complete(((bra_download_complete_t*)p)->status);
      BRA_FREE(p);
      break;
    case BRA_SIG_NOTIFY_BEARER_INFO:
      bra_sif_handle_notify_bearer_info(((bra_notify_bearer_info_t*)p)->bearer, ((bra_notify_bearer_info_t*)p)->status);
      BRA_FREE(p);
      break;
#ifdef __SAT__
    case BRA_SIG_SAT_LAUCH_REQUEST:
      bra_sat_lauch_request(p);
      BRA_FREE (p);
      break;
#endif /*__SAT__*/
    case BRA_SIG_NOTIFY_PINNED_PROV:
      bra_prs_notify_pinned_prov(p);
      BRA_FREE(p);
      break;
    case BRA_SIG_INVALID_PROV_RECV:
      bra_prs_handle_invalid_prov(1);
      BRA_FREE(p);
      break;
    case BRA_SIG_PROV_AUTH_FAILED:
      bra_prs_handle_invalid_prov(2);
      BRA_FREE(p);
      break;
    case BRA_SIG_REGISTER_PROV_AUTH:
      bra_prs_register_prov_auth(p);
      BRA_FREE(p);
      break;
    case BRA_SIG_CANCEL_PROV_CONF:
      bra_prs_cancel_prov_conf();
      BRA_FREE(p);
      break;
    case BRA_SIG_SELECT_BOOKMARK:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_ENV_E4702147D4E7D5075D713DDE24675AD0, "BRA: Received BRA_SIG_SELECT_BOOKMARK\n"));
      bra_bkm_create_select_bookmark(p);
      BRA_FREE(p);
      break;
#ifdef __UNIFIED_MSG_SUPPORT__
    case BRA_SIG_GET_PUSH_MSG_NUM:
      bra_psl_get_push_msg_num();
      break;
    case BRA_SIG_GET_PUSH_MSG_LIST:
      bra_psl_get_push_msg_list(p);
      BRA_FREE (p);
      break;
    case BRA_SIG_GET_PUSH_MSG_INFO:
      bra_psl_get_push_msg_info(p);
      BRA_FREE (p);
      break;
    case BRA_SIG_DEL_PUSH_MSG_INBOX:
      bra_psl_del_push_msg_inbox();
      break;
    case BRA_SIG_VIEW_PUSH_MSG:
      bra_psl_view_push_msg(p);
      BRA_FREE (p);
      break;
#endif
    case MSF_SIG_MODULE_TERMINATE:
		BRA_SIGNAL_SENDTO (W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_TERMINATE);
		BRA_FREE (p);
		break;
    case MSF_SIG_MODULE_STATUS:
      BRA_SIGNAL_SENDTO_IU (W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_STATUS,
        ((msf_module_status_t *)p)->status,((msf_module_status_t *)p)->modId);
      BRA_FREE (((msf_module_status_t *)p)->modVersion);
      BRA_FREE (p);
      break;
    case MSF_SIG_WIDGET_ACTION:
      BRA_SIGNAL_SENDTO_UU (W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_WIDGET_ACTION,
        ((msf_widget_action_t *)p)->action,((msf_widget_action_t *)p)->handle);
      BRA_FREE (p);
      break;
    case MSF_SIG_MODULE_EXECUTE_COMMAND:
      BRA_SIGNAL_SENDTO_P (W_SIG_DST_BRA_MAIN,
        BRA_MAIN_SIG_EXECUTE_COMMAND, p);
      break;
    case MSF_SIG_WIDGET_NOTIFY:
      BRA_SIGNAL_SENDTO_UU (W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_WIDGET_NOTIFY,
        ((msf_widget_notify_t *)p)->handle,((msf_widget_notify_t *)p)->notificationType);
      BRA_FREE (p);
      break;
#ifdef __DRM_SUPPORT__      
    case MSF_SIG_PIPE_NOTIFY:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                    BRA_ENV_9D2C1E43C118C2E8994E7261D9E85A44, "BRA: Received MSF_SIG_PIPE_NOTIFY\n"));
      BRA_SIGNAL_SENDTO_IU(W_SIG_DST_BRA_MAIN, 
                           BRA_MAIN_SIG_PIPE_NOTIFY, 
                           ((msf_pipe_notify_t *)p)->handle,
                           ((msf_pipe_notify_t *)p)->eventType);
      BRA_FREE (p);
      break;      
#endif      
    case MSF_SIG_FILE_NOTIFY:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                    BRA_ENV_49EE90FF9CE4D8FE4BCFC9258C7C9FA3, "BRA: Received MSF_SIG_FILE_NOTIFY\n"));
      BRA_SIGNAL_SENDTO_IU(W_SIG_DST_BRA_MAIN, 
                           BRA_MAIN_SIG_FILE_NOTIFY, 
                           ((msf_file_notify_t *)p)->fileHandle,
                           ((msf_file_notify_t *)p)->eventType);
      BRA_FREE (p);
      break;
    case MSF_SIG_REG_RESPONSE:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_8757905174AEE243DFBE20026D7F950D, "BRA: Received MSF_SIG_REG_RESPONSE\n"));
      bra_main_reg_responce(p);
      break;
    case MSF_SIG_WIDGET_USEREVT:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_7B47348C22201E3A89D1B472E56D29DF, "BRA: Received MSF_SIG_WIDGET_USEREVT\n"));
      //bra_rpl_handle_user_evt (((msf_widget_userevt_t*)p)->handle,  ((msf_widget_userevt_t*)p)->event);
      BRA_FREE (p);
      break;
   case MSF_SIG_TIMER_EXPIRED:
        switch (((msf_timer_expired_t*)p)->timerID) {
          case BRA_RQEUEST_TIMER_ID:
          case BRA_SPLASH_TIMER_ID:
            bra_wiew_timer_expired (p);
            break;
          case BRA_INBOX_REFRESH_TIMER_ID:
            bra_psl_timer_expired (p);
            break;
        }
        MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;

/**********************************************/
/* BRS Signals                                */
/**********************************************/
    case BRS_SIG_CREATED:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                    BRA_ENV_5A61674BC388EB572819D32E947D89D4, "BRA: Received BRS_SIG_CREATED\n"));
      BRA_SIGNAL_SENDTO_P (W_SIG_DST_BRA_MAIN, 
                            BRA_MAIN_SIG_BRS_CREATE_RESPONSE,
                            p);
      break;
    case BRS_SIG_STATUS:
      MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,
                  BRA_ENV_C998A00F3A4F44AFAC4969EBC00F1B5D, "BRA: Received BRS_SIG_STATUS\n"));
      bra_sif_handle_brs_status(p);
      BRA_FREE (p);
      break;
    case BRS_SIG_ERROR:
      MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_7C4AB36C14A2AFA78DCCDE2EEB8731A4, "BRA: Received BRS_SIG_ERROR id = %i, error = %i\n",((brs_error_t *)p)->instanceId, ((brs_error_t *)p)->errorCode));
      /* force to convert BRS_ERROR_REQUEST_TIMED_OUT to BRS_ERROR_COMMUNICATION because we have a user level request timer */                  
      if(((brs_error_t *)p)->errorCode == BRS_ERROR_REQUEST_TIMED_OUT)
        ((brs_error_t *)p)->errorCode = BRS_ERROR_COMMUNICATION;
      bra_sif_handle_brs_error(((brs_error_t *)p)->instanceId, ((brs_error_t *)p)->errorCode);
      BRA_FREE (p);
      break;
    case BRS_SIG_DOCUMENT_INFO:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_17D7EB5C60B34E9799CCC2C99B2FB99A, "BRA: Received BRS_SIG_DOCUMENT_INFO\n"));
      bra_sif_handle_brs_doc_info(((brs_document_info_t *)p));
      BRA_FREE (p);
      break;
    case BRS_SIG_DO_ELEMENTS:    
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_1B658584FBB3195CA03AC4E7817ECB97, "BRA: Received BRS_SIG_DO_ELEMENTS\n"));
      bra_sif_handle_brs_do_element(p);
      /*Do not free p here*/
      break;
    case BRS_SIG_ELEMENT_FOCUSED:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_8A86CB6964DD7560C9DDF71E0FE9C2BA, "BRA: Received BRS_SIG_ELEMENT_SELECTED\n"));
      brs_sif_element_focused (p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;
#ifdef BRA_CFG_OFFLINE_PAGES
    case BRS_SIG_PAGE_NOT_FOUND_OFFLINE:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_9051914FCE968CFD662E1D8E4777B7DA, "BRA: Received BRS_SIG_PAGE_NOT_FOUND_OFFLINE\n"));
      brs_sif_page_not_found_offline (p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;
#endif/*BRA_CFG_OFFLINE_PAGES*/

/**********************************************/
/* UIS Signals                                */
/**********************************************/
#ifdef BRA_CONFIG_UIS_PUSH_SL
    case UIS_SIG_NOTIFY_NEW_MSG:    
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_73F86194FF8D2E00D96A87544954B4FC, "BRA: Received UIS_SIG_NEW_MESSAGE\n"));
      bra_psl_new_msg_notification (p);
      break;
    case UIS_SIG_REPLY_MSG:    
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_73F86194FF8D2E00D96A87544954B4FC, "BRA: Received UIS_SIG_NEW_MESSAGE\n"));
      BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_REPLY_MSG, p);
      break;
    case UIS_SIG_REPLY_REGISTER:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_1A66C526EC4D2BC04D2B730E2D6AD646, "BRA: Received UIS_SIG_REPLY_REGISTER\n"));
      bra_psl_register_reply (p);
      BRA_FREE (p);
      break;
    case UIS_SIG_REPLY_MSG_LIST:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_C59EA9C04C6F21402412FD37B7A1E594, "BRA: Received UIS_SIG_REPLY_MSG_LIST\n"));
      bra_psl_msg_list_reply (p);
      BRA_FREE (p);
      break;
    case UIS_SIG_REPLY_FULL_MSG:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_0267D7C7564025EF76C5EBE616269C6D, "BRA: Received UIS_SIG_REPLY_FULL_MSG\n"));
      bra_psl_reply_full_msg (p);
      BRA_FREE (p);
      break;
    case UIS_SIG_REPLY_DELETE_MSG:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_B8AB5271C699EA3AD2E7BB894BC39215, "BRA: Received UIS_SIG_REPLY_DELETE_MSG\n"));
      bra_psl_reply_delete_msg (p);
      BRA_FREE (p);
      break;
    case UIS_SIG_REPLY_CHANGE_MSG:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_8BB789A333AD791C9228433727004992, "BRA: Received UIS_SIG_REPLY_CHANGE_MSG\n"));
      bra_psl_reply_change_msg (p);
      BRA_FREE (p);
      break;
    case UIS_SIG_REPLY_NBR_OF_MSGS:  //Jo
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_D78E2AB03937F655864C432C143902BC, "BRA: Received UIS_SIG_REPLY_NBR_OF_MSGS\n"));
      bra_psl_reply_nbr_of_msg (p);
      BRA_FREE (p);
      break;
    case UIS_SIG_NOTIFY_MSG_DELETED:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_EE1C76C9D7DE4D957C1F933A3CA93C32, "BRA: Received UIS_SIG_NOTIFY_MSG_DELETED\n"));
      bra_psl_notify_msg_deleted (p);
      BRA_FREE (p);
      break;
#endif
/**********************************************/
/* Security                                   */
/**********************************************/
#ifdef BRA_CONFIG_SECURITY
    case SEC_SIG_GET_CURRENT_SEC_CLASS_RESPONSE:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_0326E3FAF53D640DB4FE1CBB5968EADA, "BRA: Received SEC_SIG_GET_CURRENT_SEC_CLASS_RESPONSE\n"));
      bra_sif_set_security_class (((sec_get_current_sec_class_response_t*)p)->sec_class,
                                  ((sec_get_current_sec_class_response_t*)p)->info_available,
                                  ((sec_get_current_sec_class_response_t*)p)->cert_available);      
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;
    /*case SEC_SIG_GET_SESSION_INFO_RESPONSE:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_01A0EBD5AF24730A5E2D8B927231B56B, "BRA: Received SEC_SIG_GET_SESSION_INFO_RESPONSE\n"));
      if(((sec_get_session_info_response_t*)p)->result == SEC_ERR_OK)
        bra_view_set_secure_icon (1);
      else
        bra_view_set_secure_icon (0);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;      */
    case SEC_SIG_CHANGE_PIN_RESPONSE:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_ENV_076F7DE137D443463D39033014171A20, "BRA: Received SEC_SIG_CHANGE_PIN_RESPONSE\n"));
      break;
    case SEC_SIG_SESSION_CLEAR_RESPONSE:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_ENV_D30EE7C4CD2A329F3A7BEBA457985C37, "BRA: Received SEC_SIG_SESSION_CLEAR_RESPONSE\n"));
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);      
      break;
    case SEC_SIG_VIEW_CURRENT_CERT_RESPONSE:
      MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
        BRA_ENV_BED95BEA2DEAA4463DB9CFCB3103C569, "BRA: Received SEC_SIG_VIEW_CURRENT_CERT_RESPONSE, result=%d\n", ((sec_view_current_cert_response_t*)p)->result));
      if(((sec_view_current_cert_response_t*)p)->result != SEC_ERR_OK)
      {
        bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_NOCERT, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
      }
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;
#endif
/**********************************************/
/* Provisioning Signals                       */
/**********************************************/
#ifdef BRA_CONFIG_PROVISIONING
    case PRS_SIG_PROVISIONING_OUTPUT:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_EBA3B71F6E25666C7ADD3E3673FD8906, "BRA: Received PRS_SIG_PROVISIONING_OUTPUT\n"));
      bra_prs_handle_provisining_data (p);
      break;
#endif


/**********************************************/
/* BRA CCA handler                            */
/**********************************************/

#ifdef BRA_CFG_CCA

    case BRA_SIG_CCA_APP_CONFIGURE_IND:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_843129549584B403A469C28823F92FF4, "BRA: Received BRA_SIG_CCA_APP_CONFIGURE_IND\n"));
      bra_cca_handle_app_configure((bra_cca_app_configure_ind_t *)p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;

    case BRA_SIG_CCA_GET_PROF_IND:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_01D0E5F1A8ECB05085191DBF1D555B85, "BRA: Received BRA_SIG_CCA_GET_PROF_IND\n"));
      bra_cca_handle_get_profile((bra_cca_get_prof_ind_t *)p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;

    case BRA_SIG_CCA_UPDATE_PROF_IND:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_6F90FE7961A27107A102529A8FA6F2FF, "BRA: Received BRA_SIG_CCA_UPDATE_PROF_IND\n"));
      bra_cca_handle_update_profile((bra_cca_update_prof_ind_t *)p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;

#endif /*BRA_CFG_CCA*/

    case BRA_SIG_DA_DOWNLOAD_INFO_IND:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                  BRA_ENV_E475526D3904395BB4817D22AEAA13F8, "BRA: Received BRA_SIG_DA_DOWNLOAD_INFO_IND\n"));
      bra_da_download_info(((bra_da_download_info_t*)p)->jobCount, 
                           ((bra_da_download_info_t*)p)->activeJobCount);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;


#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN

    case BRA_SIG_NET_ID_SELECT_RSP:
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                    BRA_ENV_CA0DB08278583AE30B0BF891C7A7462D, "BRA: Received BRA_SIG_NET_ID_SELECT_RSP\n"));
      bra_set_handle_net_id_select_response(p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;

#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/


    case  BRA_SIG_CBM_SELECT_ACCOUNT_RESULT_IND:
      bra_cbm_handle_ask_select_result(p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;
      
    case  BRA_SIG_CBM_ADD_BEARER_STATUS_NOTIFY_CNF:
      bra_cbm_handle_add_bearer_status_notify(p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;
      
    case  BRA_SIG_CBM_DEL_BEARER_STATUS_NOTIFY_CNF:
      bra_cbm_handle_del_bearer_status_notify(p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;
      
    case  BRA_SIG_CBM_BEARER_STATUS_NOTIFY_IND:
      bra_cbm_handle_bearer_status_notify(p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;

#ifdef BRA_CFG_DUAL_SIM
     
    case BRA_SIG_SIM_INFO_NOTIFY_IND:
      bra_sim_handle_sim_info_notify(p);
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;

#endif /* BRA_CFG_DUAL_SIM */

    default:
      /* This was not a signal that we are interested in */
      MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, signal, p);
      break;
  }
}


#ifdef MSF_LOG_FC
MSF_LOG_FC_DISPATCH_MAP_BEGIN(BRA)

MSF_LOG_FC_DISPATCH_MAP_ENTRY_BEGIN(BRAc_start)
  BRAc_start();
MSF_LOG_FC_DISPATCH_MAP_ENTRY_END

MSF_LOG_FC_DISPATCH_MAP_ENTRY_BEGIN(BRAc_wantsToRun)
  BRAc_wantsToRun();
MSF_LOG_FC_DISPATCH_MAP_ENTRY_END

MSF_LOG_FC_DISPATCH_MAP_ENTRY_BEGIN(BRAc_run)
  BRAc_run();
MSF_LOG_FC_DISPATCH_MAP_ENTRY_END

MSF_LOG_FC_DISPATCH_MAP_END
#endif 


