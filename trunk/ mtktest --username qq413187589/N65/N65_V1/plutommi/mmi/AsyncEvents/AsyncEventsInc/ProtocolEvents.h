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
 * ProtocolEvents.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends forContains Protocol Events, Failure causes and structures
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : ProtocolEvents.h

   PURPOSE     : Contains Protocol Events, Failure causes and 
              structures

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : sep' 03, 2002

**************************************************************/
#ifndef _PIXCOM_PROTOCOL_EVENT_H
#define _PIXCOM_PROTOCOL_EVENT_H
#include "MMI_features.h"

#ifdef MMI_ON_HARDWARE_P

#include "L4Dr.h"

/******************** E-mail ************************/
/******************** E-mail ************************/

#ifdef __MMI_EMAIL__    /* Changes for email */

#define PRT_MMI_EMAIL_INIT_REQ               MSG_ID_MMI_EMAIL_INIT_REQ
#define PRT_MMI_EMAIL_INIT_RSP               MSG_ID_MMI_EMAIL_INIT_RSP
#define PRT_MMI_EMAIL_DEINIT_REQ          MSG_ID_MMI_EMAIL_DEINIT_REQ
#define PRT_MMI_EMAIL_DEINIT_RSP          MSG_ID_MMI_EMAIL_DEINIT_RSP

#define  PRT_MMI_EMAIL_LIST_ACCT_PROFILE_REQ    MSG_ID_MMI_EMAIL_LIST_ACCT_PROFILE_REQ
#define  PRT_MMI_EMAIL_LIST_ACCT_PROFILE_RSP    MSG_ID_MMI_EMAIL_LIST_ACCT_PROFILE_RSP
#define  PRT_MMI_EMAIL_SET_ACCT_PROFILE_REQ     MSG_ID_MMI_EMAIL_SET_ACCT_PROFILE_REQ
#define  PRT_MMI_EMAIL_SET_ACCT_PROFILE_RSP     MSG_ID_MMI_EMAIL_SET_ACCT_PROFILE_RSP
#define  PRT_MMI_EMAIL_GET_ACCT_PROFILE_REQ     MSG_ID_MMI_EMAIL_GET_ACCT_PROFILE_REQ
#define  PRT_MMI_EMAIL_GET_ACCT_PROFILE_RSP     MSG_ID_MMI_EMAIL_GET_ACCT_PROFILE_RSP
#define  PRT_MMI_EMAIL_ACTIVATE_ACCT_REQ           MSG_ID_MMI_EMAIL_ACTIVATE_ACCT_REQ
#define  PRT_MMI_EMAIL_ACTIVATE_ACCT_RSP        MSG_ID_MMI_EMAIL_ACTIVATE_ACCT_RSP
#define  PRT_MMI_EMAIL_DELETE_ACCT_REQ          MSG_ID_MMI_EMAIL_DELETE_ACCT_REQ
#define  PRT_MMI_EMAIL_DELETE_ACCT_RSP          MSG_ID_MMI_EMAIL_DELETE_ACCT_RSP

#define  PRT_MMI_EMAIL_LIST_FOLDERS_REQ            MSG_ID_MMI_EMAIL_LIST_FOLDERS_REQ
#define  PRT_MMI_EMAIL_LIST_FOLDERS_RSP         MSG_ID_MMI_EMAIL_LIST_FOLDERS_RSP

#define  PRT_MMI_EMAIL_SEND_RECV_REQ            MSG_ID_MMI_EMAIL_SEND_RECV_REQ
#define  PRT_MMI_EMAIL_SEND_RECV_RSP            MSG_ID_MMI_EMAIL_SEND_RECV_RSP

#define  PRT_MMI_EMAIL_NUM_MSGS_SENT_IND        MSG_ID_MMI_EMAIL_NUM_MSGS_SENT_IND
#define PRT_MMI_EMAIL_SERVER_CONNECT_IND        MSG_ID_MMI_EMAIL_SERVER_CONNECT_IND
#define PRT_MMI_EMAIL_AUTHVERIFY_IND            MSG_ID_MMI_EMAIL_AUTHVERIFY_IND
#define PRT_MMI_EMAIL_RECV_MAILS_IND            MSG_ID_MMI_EMAIL_RECV_MAILS_IND
#define PRT_MMI_EMAIL_NEW_MSGS_IND           MSG_ID_MMI_EMAIL_NEW_MSGS_IND

#define  PRT_MMI_EMAIL_FOLDER_SELECT_REQ           MSG_ID_MMI_EMAIL_FOLDER_SELECT_REQ
#define  PRT_MMI_EMAIL_FOLDER_SELECT_RSP           MSG_ID_MMI_EMAIL_FOLDER_SELECT_RSP

#define  PRT_MMI_EMAIL_FOLDER_MSG_SELECT_REQ    MSG_ID_MMI_EMAIL_FOLDER_MSG_SELECT_REQ
#define  PRT_MMI_EMAIL_FOLDER_MSG_SELECT_RSP    MSG_ID_MMI_EMAIL_FOLDER_MSG_SELECT_RSP

#define  PRT_MMI_EMAIL_FOLDER_MSG_DELETE_REQ    MSG_ID_MMI_EMAIL_FOLDER_MSG_DELETE_REQ
#define  PRT_MMI_EMAIL_FOLDER_MSG_DELETE_RSP    MSG_ID_MMI_EMAIL_FOLDER_MSG_DELETE_RSP

#define  PRT_MMI_EMAIL_MSG_MOVE_REQ          MSG_ID_MMI_EMAIL_MSG_MOVE_REQ
#define  PRT_MMI_EMAIL_MSG_MOVE_RSP          MSG_ID_MMI_EMAIL_MSG_MOVE_RSP
#define  PRT_MMI_EMAIL_PARTIAL_FETCH_REQ        MSG_ID_MMI_EMAIL_PARTIAL_FETCH_REQ
#define  PRT_MMI_EMAIL_PARTIAL_FETCH_RSP        MSG_ID_MMI_EMAIL_PARTIAL_FETCH_RSP
#define  PRT_MMI_EMAIL_SEARCH_REQ                  MSG_ID_MMI_EMAIL_SEARCH_REQ
#define  PRT_MMI_EMAIL_SEARCH_RSP               MSG_ID_MMI_EMAIL_SEARCH_RSP
#define  PRT_MMI_EMAIL_SEARCH_LIST_REQ          MSG_ID_MMI_EMAIL_SEARCH_LIST_REQ
#define  PRT_MMI_EMAIL_SEARCH_LIST_RSP          MSG_ID_MMI_EMAIL_SEARCH_LIST_RSP
#define  PRT_MMI_EMAIL_SEND_REQ                    MSG_ID_MMI_EMAIL_SEND_REQ
#define PRT_MMI_EMAIL_SEND_RSP               MSG_ID_MMI_EMAIL_SEND_RSP
#define PRT_MMI_EMAIL_SEND_NOW_REQ           MSG_ID_MMI_EMAIL_SEND_NOW_REQ
#define PRT_MMI_EMAIL_SEND_NOW_RSP           MSG_ID_MMI_EMAIL_SEND_NOW_RSP
#define PRT_MMI_EMAIL_SEND_ONLY_REQ          MSG_ID_MMI_EMAIL_SEND_ONLY_REQ
#define PRT_MMI_EMAIL_SEND_ONLY_RSP          MSG_ID_MMI_EMAIL_SEND_ONLY_RSP
#define PRT_MMI_EMAIL_SAVE_DRAFTS_REQ           MSG_ID_MMI_EMAIL_SAVE_DRAFTS_REQ
#define PRT_MMI_EMAIL_SAVE_DRAFTS_RSP           MSG_ID_MMI_EMAIL_SAVE_DRAFTS_RSP
#define PRT_MMI_EMAIL_COMPOSE_SIZE_REQ          MSG_ID_MMI_EMAIL_COMPOSE_SIZE_REQ
#define PRT_MMI_EMAIL_COMPOSE_SIZE_RSP          MSG_ID_MMI_EMAIL_COMPOSE_SIZE_RSP
#define PRT_MMI_EMAIL_SET_MODE_REQ              MSG_ID_MMI_EMAIL_SET_MODE_REQ
#define PRT_MMI_EMAIL_SET_MODE_RSP              MSG_ID_MMI_EMAIL_SET_MODE_RSP

#define  PRT_MMI_EMAIL_ABORT_REQ                MSG_ID_MMI_EMAIL_ABORT_REQ
#define  PRT_MMI_EMAIL_ABORT_RSP                MSG_ID_MMI_EMAIL_ABORT_RSP

#define PRT_MMI_EMAIL_UIDL_FULL_IND          MSG_ID_MMI_EMAIL_UIDL_FULL_IND
#define PRT_MMI_EMAIL_ERR_IND                MSG_ID_MMI_EMAIL_ERR_IND
#define PRT_MMI_EMAIL_START_REQ              MSG_ID_MMI_EMAIL_START_REQ
#define PRT_MMI_EMAIL_START_RSP              MSG_ID_MMI_EMAIL_START_RSP
#define PRT_MMI_EMAIL_STOP_REQ               MSG_ID_MMI_EMAIL_STOP_REQ
#define PRT_MMI_EMAIL_STOP_RSP               MSG_ID_MMI_EMAIL_STOP_RSP
#define PRT_MMI_EMAIL_MSG_SENT_IND           MSG_ID_MMI_EMAIL_MSG_SENT_IND
#define PRT_MMI_EMAIL_AUTOCHECK_EXPIRY_IND      MSG_ID_MMI_EMAIL_AUTOCHECK_EXPIRY_IND
#define PRT_MMI_EMAIL_RECV_MSGS_IND          MSG_ID_MMI_EMAIL_RECV_MSGS_IND

#define PRT_MMI_EMAIL_BEARER_INFO_IND           MSG_ID_MMI_EMAIL_BEARER_INFO_IN
#define PRT_MMI_EMAIL_DEACTIVATE_REQ            MSG_ID_MMI_EMAIL_DEACTIVATE_REQ
#define PRT_MMI_EMAIL_DEACTIVATE_RSP            MSG_ID_MMI_EMAIL_DEACTIVATE_RSP

#define PRT_MMI_EMAIL_MSG_FULL_IND           MSG_ID_MMI_EMAIL_MSG_FULL_IND
#define PRT_MMI_EMAIL_MSG_AVAILABLE_IND         MSG_ID_MMI_EMAIL_MSG_AVAILABLE_IND

#define PRT_MMI_EMAIL_SEND_FROM_MAILBOX_REQ     MSG_ID_MMI_EMAIL_SEND_FROM_MAILBOX_REQ
#define PRT_MMI_EMAIL_SEND_FROM_MAILBOX_RSP     MSG_ID_MMI_EMAIL_SEND_FROM_MAILBOX_RSP

#define PRT_MMI_EMAIL_FOLDER_MSG_SET_FLAG_REQ	MSG_ID_MMI_EMAIL_FOLDER_MSG_SET_FLAG_REQ
#define PRT_MMI_EMAIL_FOLDER_MSG_SET_FLAG_RSP   MSG_ID_MMI_EMAIL_FOLDER_MSG_SET_FLAG_RSP

#endif /* __MMI_EMAIL__ */ /* def __MMI_EMAIL__      // Changes for email */

/******************** E-mail ************************/
/******************** E-mail ************************/

#define MMI_EQ_POWER_ON_IND                  MSG_ID_MMI_EQ_POWER_ON_IND /* power on */
/* sms start -> */
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
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* AT */
#define MSG_ID_SMS_SYNC_MSG_IND           MSG_ID_MMI_SMS_SYNC_MSG_IND

//MTK Joy added for FDN check, 1120
//#define MSG_ID_PHB_SMS_FDN_CHECK_REQ                          MSG_ID_MMI_PHB_SMS_FDN_CHECK_REQ
//#define MSG_ID_PHB_SMS_FDN_CHECK_RSP                          MSG_ID_MMI_PHB_SMS_FDN_CHECK_RSP
//MTK end

/* micha0601 begin */
#define  PRT_MMI_SAT_DISPLAY_TEXT_IND                 MSG_ID_MMI_SAT_DISPLAY_TEXT_IND
#define  PRT_MMI_SAT_DISPLAY_TEXT_RES_REQ          MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_REQ
#define  PRT_MMI_SAT_DISPLAY_TEXT_RES_RSP          MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_RSP
#define  PRT_MMI_SAT_GET_INKEY_IND                    MSG_ID_MMI_SAT_GET_INKEY_IND
#define  PRT_MMI_SAT_GET_INKEY_RES_REQ             MSG_ID_MMI_SAT_GET_INKEY_RES_REQ
#define  PRT_MMI_SAT_GET_INKEY_RES_RSP             MSG_ID_MMI_SAT_GET_INKEY_RES_RSP
#define  PRT_MMI_SAT_GET_INPUT_IND                    MSG_ID_MMI_SAT_GET_INPUT_IND
#define  PRT_MMI_SAT_GET_INPUT_RES_REQ             MSG_ID_MMI_SAT_GET_INPUT_RES_REQ
#define  PRT_MMI_SAT_GET_INPUT_RES_RSP             MSG_ID_MMI_SAT_GET_INPUT_RES_RSP
#define  PRT_MMI_SAT_SETUP_MENU_IND                MSG_ID_MMI_SAT_SETUP_MENU_IND
#define  PRT_MMI_SAT_SETUP_MENU_RES_REQ               MSG_ID_MMI_SAT_SETUP_MENU_RES_REQ
#define  PRT_MMI_SAT_SETUP_MENU_RES_RSP               MSG_ID_MMI_SAT_SETUP_MENU_RES_RSP
#define  PRT_MMI_SAT_SELECT_ITEM_IND                  MSG_ID_MMI_SAT_SELECT_ITEM_IND
#define  PRT_MMI_SAT_SELECT_ITEM_RES_REQ              MSG_ID_MMI_SAT_SELECT_ITEM_RES_REQ
#define  PRT_MMI_SAT_SELECT_ITEM_RES_RSP              MSG_ID_MMI_SAT_SELECT_ITEM_RES_RSP
#define  PRT_MMI_SAT_PLAY_TONE_IND                    MSG_ID_MMI_SAT_PLAY_TONE_IND
#define  PRT_MMI_SAT_PLAY_TONE_RES_REQ             MSG_ID_MMI_SAT_PLAY_TONE_RES_REQ
#define  PRT_MMI_SAT_PLAY_TONE_RES_RSP             MSG_ID_MMI_SAT_PLAY_TONE_RES_RSP
#define  PRT_MMI_SAT_MENU_SELECT_REQ                  MSG_ID_MMI_SAT_MENU_SELECT_REQ
#define  PRT_MMI_SAT_MENU_SELECT_RSP                  MSG_ID_MMI_SAT_MENU_SELECT_RSP
#define  PRT_MMI_SAT_CALL_SETUP_IND                MSG_ID_MMI_SAT_CALL_SETUP_IND
#define  PRT_MMI_SAT_CALL_SETUP_STAGE1_REQ            MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_REQ
#define  PRT_MMI_SAT_CALL_SETUP_STAGE1_RSP            MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_RSP
#define  PRT_MMI_SAT_CALL_SETUP_STAGE2_REQ            MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_REQ
#define  PRT_MMI_SAT_CALL_SETUP_STAGE2_RSP            MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_RSP
#define  PRT_MMI_SAT_SEND_SMS_IND                     MSG_ID_MMI_SAT_SEND_SMS_IND
#define  PRT_MMI_SAT_SEND_SMS_STAGE1_REQ           MSG_ID_MMI_SAT_SEND_SMS_STAGE1_REQ
#define  PRT_MMI_SAT_SEND_SMS_STAGE1_RSP           MSG_ID_MMI_SAT_SEND_SMS_STAGE1_RSP
#define  PRT_MMI_SAT_SEND_SMS_STAGE2_REQ           MSG_ID_MMI_SAT_SEND_SMS_STAGE2_REQ
#define  PRT_MMI_SAT_SEND_SMS_STAGE2_RSP           MSG_ID_MMI_SAT_SEND_SMS_STAGE2_RSP
#define  PRT_MMI_SAT_SEND_SS_IND                   MSG_ID_MMI_SAT_SEND_SS_IND
#define  PRT_MMI_SAT_SEND_SS_STAGE1_REQ               MSG_ID_MMI_SAT_SEND_SS_STAGE1_REQ
#define  PRT_MMI_SAT_SEND_SS_STAGE1_RSP               MSG_ID_MMI_SAT_SEND_SS_STAGE1_RSP
#define  PRT_MMI_SAT_SEND_SS_STAGE2_REQ               MSG_ID_MMI_SAT_SEND_SS_STAGE2_REQ
#define  PRT_MMI_SAT_SEND_SS_STAGE2_RSP               MSG_ID_MMI_SAT_SEND_SS_STAGE2_RSP
#define  PRT_MMI_SAT_SEND_USSD_IND                    MSG_ID_MMI_SAT_SEND_USSD_IND
#define  PRT_MMI_SAT_SEND_USSD_STAGE1_REQ          MSG_ID_MMI_SAT_SEND_USSD_STAGE1_REQ
#define  PRT_MMI_SAT_SEND_USSD_STAGE1_RSP          MSG_ID_MMI_SAT_SEND_USSD_STAGE1_RSP
#define  PRT_MMI_SAT_SEND_USSD_STAGE2_REQ          MSG_ID_MMI_SAT_SEND_USSD_STAGE2_REQ
#define  PRT_MMI_SAT_SEND_USSD_STAGE2_RSP          MSG_ID_MMI_SAT_SEND_USSD_STAGE2_RSP
#define  PRT_MMI_SAT_MMI_INFO_IND                     MSG_ID_MMI_SAT_MMI_INFO_IND
#define  PRT_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ    MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ
#define  PRT_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP    MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP
#define  PRT_MMI_SAT_SETUP_IDLE_DISPLAY_IND        MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_IND
#define  PRT_MMI_SAT_RUN_AT_COMMAND_RES_REQ        MSG_ID_MMI_SAT_RUN_AT_COMMAND_RES_REQ
#define  PRT_MMI_SAT_RUN_AT_COMMAND_RES_RSP        MSG_ID_MMI_SAT_RUN_AT_COMMAND_RES_RSP
#define  PRT_MMI_SAT_RUN_AT_COMMAND_IND            MSG_ID_MMI_SAT_RUN_AT_COMMAND_IND
#define  PRT_MMI_SAT_SEND_DTMF_RES_REQ             MSG_ID_MMI_SAT_SEND_DTMF_RES_REQ
#define  PRT_MMI_SAT_SEND_DTMF_RES_RSP             MSG_ID_MMI_SAT_SEND_DTMF_RES_RSP
#define  PRT_MMI_SAT_SEND_DTMF_IND                    MSG_ID_MMI_SAT_SEND_DTMF_IND
#define  PRT_MMI_SAT_LANG_NOTIFY_RES_REQ           MSG_ID_MMI_SAT_LANG_NOTIFY_RES_REQ
#define  PRT_MMI_SAT_LANG_NOTIFY_RES_RSP           MSG_ID_MMI_SAT_LANG_NOTIFY_RES_RSP
#define  PRT_MMI_SAT_LANG_NOTIFY_IND                  MSG_ID_MMI_SAT_LANG_NOTIFY_IND
#define  PRT_MMI_SAT_LAUNCH_BROWSER_RES_REQ        MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_REQ
#define  PRT_MMI_SAT_LAUNCH_BROWSER_RES_RSP        MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_RSP
#define  PRT_MMI_SAT_LAUNCH_BROWSER_IND               MSG_ID_MMI_SAT_LAUNCH_BROWSER_IND
#define  PRT_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ   MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ
#define  PRT_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP   MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP
#define  PRT_MMI_SAT_LANGUAGE_SELECTION_REQ           MSG_ID_MMI_SAT_LANGUAGE_SELECTION_REQ
#define  PRT_MMI_SAT_LANGUAGE_SELECTION_RSP           MSG_ID_MMI_SAT_LANGUAGE_SELECTION_RSP
#define  PRT_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ     MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ
#define  PRT_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP     MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP
#define  PRT_WAP_MMI_BROWSER_TERMINATION_IND       MSG_ID_WAP_MMI_BROWSER_TERMINATION_IND
#define  PRT_WAP_MMI_LAUNCH_BROWSER_REQ               MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ
#define  PRT_WAP_MMI_LAUNCH_BROWSER_RSP               MSG_ID_WAP_MMI_LAUNCH_BROWSER_RSP
#define  PRT_MMI_SAT_SEND_DTMF_STAGE1_REQ             MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_REQ
#define  PRT_MMI_SAT_SEND_DTMF_STAGE1_RSP             MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_RSP
#define  PRT_MMI_SAT_SEND_DTMF_STAGE2_REQ             MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_REQ
#define  PRT_MMI_SAT_SEND_DTMF_STAGE2_RSP             MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_RSP
#define  PRT_MMI_SAT_ABORT_DTMF_REQ                   MSG_ID_MMI_SAT_ABORT_DTMF_REQ
#define  PRT_MMI_SMU_READ_SIM_REQ                        MSG_ID_MMI_SMU_READ_SIM_REQ
#define  PRT_MMI_SMU_READ_SIM_RSP                        MSG_ID_MMI_SMU_READ_SIM_RSP
/* micha0714 */
#define  PRT_MMI_SAT_NO_OTHER_CMD_IND              MSG_ID_MMI_SAT_NO_OTHER_CMD_IND

/* micha0601 end */

#define  PRT_MSG_ID_MMI_SMS_FDN_CHECK_REQ MSG_ID_MMI_PHB_SMS_FDN_CHECK_REQ
#define  PRT_MSG_ID_MMI_SMS_FDN_CHECK_RSP MSG_ID_MMI_PHB_SMS_FDN_CHECK_RSP

#define  PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ
#define  PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP
#define  PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ
#define  PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP
#define  PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ  MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ
#define  PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP  MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP
#define  PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ  MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ
#define  PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP  MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP
#define  PRT_MSG_ID_MMI_SMS_SEND_COMMAND_REQ       MSG_ID_MMI_SMS_SEND_COMMAND_REQ
#define  PRT_MSG_ID_MMI_SMS_SEND_COMMAND_RSP       MSG_ID_MMI_SMS_SEND_COMMAND_RSP
#define  PRT_MSG_ID_MMI_SMS_DEL_MSG_REQ               MSG_ID_MMI_SMS_DEL_MSG_REQ
#define  PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP               MSG_ID_MMI_SMS_DEL_MSG_RSP
#define  PRT_MSG_ID_MMI_SMS_GET_MSG_REQ               MSG_ID_MMI_SMS_GET_MSG_REQ
#define  PRT_MSG_ID_MMI_SMS_GET_MSG_RSP               MSG_ID_MMI_SMS_GET_MSG_RSP
#define  PRT_MSG_ID_MMI_SMS_SEND_MSG_REQ           MSG_ID_MMI_SMS_SEND_MSG_REQ
#define  PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP           MSG_ID_MMI_SMS_SEND_MSG_RSP
#define  PRT_MSG_ID_MMI_SMS_SET_MSG_REQ               MSG_ID_MMI_SMS_SET_MSG_REQ
#define  PRT_MSG_ID_MMI_SMS_SET_MSG_RSP               MSG_ID_MMI_SMS_SET_MSG_RSP
#define  PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ    MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ
#define  PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP    MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP
#define  PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ
#define  PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP    MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP
#define  PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_REQ       MSG_ID_MMI_SMS_REG_PORT_NUM_REQ
#define  PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_RSP       MSG_ID_MMI_SMS_REG_PORT_NUM_RSP
#define  PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND           MSG_ID_MMI_SMS_DELIVER_MSG_IND
#define  PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND         MSG_ID_MMI_SMS_STATUS_REPORT_IND
#define  PRT_MSG_ID_MMI_SMS_MEM_AVAILABLE_IND         MSG_ID_MMI_SMS_MEM_AVAILABLE_IND
#define  PRT_MSG_ID_MMI_SMS_MEM_EXCEED_IND            MSG_ID_MMI_SMS_MEM_EXCEED_IND
#define  PRT_MSG_ID_MMI_SMS_MEM_FULL_IND           MSG_ID_MMI_SMS_MEM_FULL_IND
#define  PRT_MSG_ID_MMI_SMS_READY_IND              MSG_ID_MMI_SMS_READY_IND
#define  PRT_MSG_ID_MMI_SMS_APP_DATA_IND           MSG_ID_MMI_SMS_APP_DATA_IND
#define  PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ        MSG_ID_MMI_SMS_GET_MSG_NUM_REQ
#define  PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP        MSG_ID_MMI_SMS_GET_MSG_NUM_RSP
#define  PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ    MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ
#define  PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP    MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP
#define  PRT_MSG_ID_MMI_SMS_ABORT_REQ              MSG_ID_MMI_SMS_ABORT_REQ
#define  PRT_MSG_ID_MMI_SMS_ABORT_RSP              MSG_ID_MMI_SMS_ABORT_RSP
#define  PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND      MSG_ID_MMI_SMS_SEND_ABORT_START_IND
#define  PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND     MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND
#define  PRT_MSG_ID_MMI_SMS_COPY_MSG_REQ           MSG_ID_MMI_SMS_COPY_MSG_REQ
#define  PRT_MSG_ID_MMI_SMS_COPY_MSG_RSP           MSG_ID_MMI_SMS_COPY_MSG_RSP
#define PRT_MSG_ID_MMI_SEND_SMS_FROM_STORAGE_REQ    MSG_ID_MMI_SMS_SEND_FROM_STORAGE_REQ
#define PRT_MSG_ID_MMI_SEND_SMS_FROM_STORAGE_RSP    MSG_ID_MMI_SMS_SEND_FROM_STORAGE_RSP
#define PRT_MSG_ID_MMI_SMS_SET_STATUS_REQ           MSG_ID_MMI_SMS_SET_STATUS_REQ
#define PRT_MSG_ID_MMI_SMS_SET_STATUS_RSP           MSG_ID_MMI_SMS_SET_STATUS_RSP

#define  PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND        MSG_ID_MMI_SMS_MSG_WAITING_IND
#define  PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ   MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ
#define  PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP   MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP
#define  PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ   MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ
#define  PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP   MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP
#define  PRT_MSG_ID_MMI_SMS_SYNC_MSG_IND           MSG_ID_MMI_SMS_SYNC_MSG_IND
#define  PRT_MSG_ID_MMI_SMS_STARTUP_BEGIN_IND         MSG_ID_MMI_SMS_STARTUP_BEGIN_IND
#define  PRT_MSG_ID_MMI_SMS_STARTUP_FINISH_IND        MSG_ID_MMI_SMS_STARTUP_FINISH_IND
#define  PRT_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ     MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ
#define  PRT_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP     MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP
#define  PRT_MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND      MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND
/* micha0201 */
#define  PRT_MMI_SAT_SIM_FILE_CHANGE_IND              MSG_ID_MMI_SAT_SIM_FILE_CHANGE_IND

#define  PRT_MSG_ID_MMI_CB_DOWNLOAD_IND      MSG_ID_MMI_CB_DOWNLOAD_IND
#define  PRT_MSG_ID_MMI_CB_MSG_IND           MSG_ID_MMI_CB_MSG_IND
#define  PRT_MSG_ID_MMI_CB_SUBSCRIBE_REQ     MSG_ID_MMI_CB_SUBSCRIBE_REQ
#define  PRT_MSG_ID_MMI_CB_SUBSCRIBE_RSP        MSG_ID_MMI_CB_SUBSCRIBE_RSP
#define  PRT_MSG_ID_MMI_SMS_SET_CB_MODE_REQ  MSG_ID_MMI_SMS_SET_CB_MODE_REQ
#define  PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP  MSG_ID_MMI_SMS_SET_CB_MODE_RSP
#define  PRT_MSG_ID_MMI_SMS_GET_CB_MODE_REQ  MSG_ID_MMI_SMS_GET_CB_MODE_REQ
#define  PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP  MSG_ID_MMI_SMS_GET_CB_MODE_RSP

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#ifdef __MMI_UNIFIED_MESSAGE__
#define  PRT_MSG_ID_MMI_UM_READY_IND         MSG_ID_MMI_UM_READY_IND
#define  PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ   MSG_ID_MMI_UM_GET_MSG_NUM_REQ
#define  PRT_MSG_ID_MMI_UM_GET_MSG_NUM_RSP      MSG_ID_MMI_UM_GET_MSG_NUM_RSP
#define  PRT_MSG_ID_MMI_UM_GET_LIST_REQ         MSG_ID_MMI_UM_GET_LIST_REQ
#define  PRT_MSG_ID_MMI_UM_GET_LIST_RSP         MSG_ID_MMI_UM_GET_LIST_RSP
#define  PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ  MSG_ID_MMI_UM_GET_MSG_INFO_REQ
#define  PRT_MSG_ID_MMI_UM_GET_MSG_INFO_RSP  MSG_ID_MMI_UM_GET_MSG_INFO_RSP
#define  PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ MSG_ID_MMI_UM_DELETE_FOLDER_REQ
#define  PRT_MSG_ID_MMI_UM_DELETE_FOLDER_RSP MSG_ID_MMI_UM_DELETE_FOLDER_RSP
#define  PRT_MSG_ID_MMI_UM_NEW_MSG_IND          MSG_ID_MMI_UM_NEW_MSG_IND
#define  PRT_MSG_ID_MMI_UM_DELETE_ALL_IND    MSG_ID_MMI_UM_DELETE_ALL_IND
#define  PRT_MSG_ID_MMI_UM_DELETE_ALL_RES    MSG_ID_MMI_UM_DELETE_ALL_RES
#define  PRT_MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND
#define  PRT_MSG_ID_MMI_UM_REFRESH_IND       MSG_ID_MMI_UM_REFRESH_IND
#define  PRT_MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND       MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND
#define  PRT_MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND       MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#define  PRT_MMI_MAKE_CALL_REQ_IND       MSG_ID_MMI_MAKE_CALL_REQ_IND

/* XXX - Call management Start of Events */
#define PRT_INCOMINGCALL_EVENT            MSG_ID_MMI_CC_CALL_RING_IND
#define PRT_INCOMINGCALL_ACCEPT_EVENT     MSG_ID_MMI_CC_ATA_REQ
#define PRT_INCOMINGCALL_ACCEPT_FAILURE      3
#define PRT_INCOMINGCALL_ACCEPT_SUCCESS      MSG_ID_MMI_CC_ATA_RSP
#define PRT_INCOMINGCALL_REJECT_EVENT     MSG_ID_MMI_CC_ATH_REQ
#define PRT_WAITINGCALL_REJECT_EVENT      MSG_ID_MMI_CC_CHLD_REQ
#define PRT_WAITINGCALL_REJECT_RSP        MSG_ID_MMI_CC_CHLD_RSP
#define PRT_INCOMINGCALL_REJECTED         MSG_ID_MMI_CC_ATH_RSP
#define PRT_INCOMINGCALL_DROPPED       MSG_ID_MMI_CC_CALL_DISCONNECT_IND
#define PRT_HELDCALL_DISCONNECTED         MSG_ID_MMI_CC_CALL_RELEASE_IND
#define PRT_INCOMINGCALL_FORWARD_EVENT    8
#define PRT_INCOMINGCALL_FORWARD_SUCCESS  9
#define PRT_INCOMINGCALL_FORWARD_FAILURE  10

#define PRT_CALLHOLD_EVENT             MSG_ID_MMI_CC_CHLD_REQ
#define PRT_CALLHOLD_SUCCESS           MSG_ID_MMI_CC_CHLD_RSP
#define PRT_CALLHOLD_FAILURE           13

#define PRT_CALLENDALLHOLD_EVENT       MSG_ID_MMI_CC_CHLD_REQ
#define PRT_HELDCALLS_END_SUCCESS         MSG_ID_MMI_CC_CALL_RELEASE_IND
#define PRT_HELDCALLS_END_FAILURE         16

#define PRT_CALLENDSPECIFIC_EVENT         MSG_ID_MMI_CC_CHLD_REQ
#define PRT_CALLENDSPECIFIC_SUCCESS       MSG_ID_MMI_CC_CALL_RELEASE_IND
#define PRT_CALLENDSPECIFIC_FAILURE       65

#define PRT_ENDALLCALL_EVENT           MSG_ID_MMI_CC_CHLD_REQ
#define PRT_ENDALLCALLREQ_SUCCESS         MSG_ID_MMI_CC_CALL_RELEASE_IND
#define PRT_ENDALLCALLREQ_FAILURE         38

#define PRT_ENDALLACTIVE_EVENT            MSG_ID_MMI_CC_CHLD_REQ
#define PRT_ENDALLACTIVEREQ_SUCCESS       MSG_ID_MMI_CC_CALL_RELEASE_IND
#define PRT_ENDALLACTIVEREQ_FAILURE       41

/* Start by Julia: Drop call refinement */
#define PRT_RELCOMP_EVENT              MSG_ID_MMI_CC_REL_COMP_REQ
/* End by Julia */
#define PRT_NETWORK_ERROR              20

#define PRT_OUTGOINGCALL_EVENT            MSG_ID_MMI_CC_DIAL_REQ
#define PRT_OUTGOINGCALL_EVENT_RSP        MSG_ID_MMI_CC_DIAL_IND
#define PRT_OUTGOINGCALL_CONNECTED        MSG_ID_MMI_CC_CALL_CONNECT_IND
#define PRT_OUTGOINGCALL_FAILURE       23

#define PRT_RETRIEVECALL_EVENT            MSG_ID_MMI_CC_CHLD_REQ
#define PRT_RETRIEVECALLREQ_SUCCESS       MSG_ID_MMI_CC_CHLD_RSP
#define PRT_RETRIEVECALLREQ_FAILURE       26

#define PRT_SWAPCALL_EVENT             MSG_ID_MMI_CC_CHLD_REQ
#define PRT_SWAPCALLREQ_SUCCESS           MSG_ID_MMI_CC_CHLD_RSP
#define PRT_SWAPCALLREQ_FAILURE           29

#define PRT_ACCEPTINCOMING_EVENT       MSG_ID_MMI_CC_CHLD_REQ
#define PRT_ACCEPTINCOMING_SUCCESS        MSG_ID_MMI_CC_CHLD_RSP

#define PRT_CCBS_ACTIVATE_REQ          MSG_ID_MMI_CC_CHLD_REQ
#define PRT_CCBS_ACTIVATE_RSP          MSG_ID_MMI_CC_CHLD_RSP
#define PRT_CCBS_NOTIFY_IND               MSG_ID_MMI_CC_NOTIFY_SS_CCBS_IND
#define PRT_DTMF_CONFIRM_IND           MSG_ID_MMI_CC_START_AUTO_DTMF_IND
#define PRT_DTMF_CONFIRM_REQ           MSG_ID_MMI_CC_START_AUTO_DTMF_REQ

#define PRT_CCBS_DIAL_EVENT               MSG_ID_MMI_CC_CHLD_REQ
#define PRT_CCBS_DIAL_RSP              MSG_ID_MMI_CC_CHLD_RSP

#define PRT_CONFCALL_EVENT             MSG_ID_MMI_CC_CHLD_REQ
#define PRT_CONFCALLREQ_SUCCESS           MSG_ID_MMI_CC_CHLD_RSP
#define PRT_CONFCALLREQ_FAILURE           32

#define PRT_SPLITCALL_EVENT               MSG_ID_MMI_CC_CHLD_REQ
#define PRT_SPLITCALLREQ_SUCCESS       MSG_ID_MMI_CC_CHLD_RSP
#define PRT_SPLITCALLREQ_FAILURE       35

#define PRT_DTMF_START_REQ             MSG_ID_MMI_CC_START_DTMF_REQ
#define PRT_DTMF_START_RES             MSG_ID_MMI_CC_START_DTMF_RSP
#define PRT_DTMF_STOP_REQ              MSG_ID_MMI_CC_STOP_DTMF_REQ
#define PRT_DTMF_STOP_RES              MSG_ID_MMI_CC_STOP_DTMF_RSP

#define PRT_USSD_REQ                MSG_ID_MMI_SS_USSD_REQ
#define PRT_USSD_RES_SUCCESS           MSG_ID_MMI_SS_USSD_RSP
#define PRT_USSD_RES_FAILURE           48

#define PRT_UDUB_REQ                MSG_ID_MMI_CC_CHLD_REQ
#define PRT_UDUB_RES_SUCCESS           MSG_ID_MMI_CC_CALL_RELEASE_IND
#define PRT_UDUB_RES_FAILURE           51

#define PRT_ECT_REQ                    MSG_ID_MMI_CC_CHLD_REQ
#define PRT_ECT_REQ_SUCCESS               MSG_ID_MMI_CC_CHLD_RSP
#define PRT_ECT_REQ_FAILURE               54

#define PRT_SPEECH_IND_EVENT           MSG_ID_MMI_CC_SPEECH_IND
#define PTR_TURN_SPEECH_AROUND            MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ
#define PRT_TURN_SPEECH_AROUND_SUCCESS    MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP
#define  PRT_TURN_SPEECH_AROUND_FAILURE      58
#define PTR_GET_CALL_LIST_REQ          MSG_ID_MMI_CC_GET_CALL_LIST_REQ
#define PTR_GET_CALL_LIST_RSP          MSG_ID_MMI_CC_GET_CALL_LIST_RSP
#define PRT_NWRK_CALL_RELEASE          MSG_ID_MMI_CC_CALL_RELEASE_IND
#define PRT_END_CHLD_RSP               MSG_ID_MMI_CC_CHLD_RSP
#define PRT_AOC_EVENT_IND              MSG_ID_MMI_CC_CCM_IND
#define PRT_USSDVSS_REQ                MSG_ID_MMI_SS_PARSING_STRING_REQ
#define PRT_USSDVSS_RSP                MSG_ID_MMI_SS_PARSING_STRING_RSP
#define PRT_INCOMING_CALL_WAIT            MSG_ID_MMI_CC_CALL_WAIT_IND

#ifdef  __UCM_SUPPORT__
#define PRT_CSD_CALL_APPROVE_REQ            MSG_ID_MMI_ABM_CSD_CALL_APPROVE_REQ
#define PRT_CSD_CALL_APPROVE_CNF            MSG_ID_MMI_ABM_CSD_CALL_APPROVE_CNF
#endif /* __UCM_SUPPORT__ */

#define PRT_NOTIFY_SS_CNAP_EVENT             MSG_ID_MMI_CC_NOTIFY_SS_CNAP_IND

#define PRT_NOTIFY_SS_EVENT               MSG_ID_MMI_CC_NOTIFY_SS_IND
#define  PRT_USSN_IND                  MSG_ID_MMI_SS_USSN_IND
#define  PRT_USSR_IND                  MSG_ID_MMI_SS_USSR_IND
#define PRT_PLAY_GSM_TONE              MSG_ID_MMI_CC_INTERNAL_ALERT_IND
#define PRT_ATH_REQ                    MSG_ID_MMI_CC_ATH_REQ
#define PRT_ATH_REQ_SUCCESS               MSG_ID_MMI_CC_ATH_RSP

#define PRT_CALL_DEFLECT_REQ           MSG_ID_MMI_CC_CALL_DEFLECT_REQ
#define PRT_CALL_DEFLECT_RSP           MSG_ID_MMI_CC_CALL_DEFLECT_RSP

/* MTK Brian added for wrap VM, 2003/10/14 */
#ifdef __MMI_VOICE_MEMO__
#define PRT_START_VOICERECORD_REQ         MSG_ID_VM_RECORD_REQ
#define PRT_START_VOICERECORD_RSP         MSG_ID_VM_RECORD_RSP
#define PRT_STOP_VOICERECORD_REQ       MSG_ID_VM_STOP_REQ
#define PRT_STOP_VOICERECORD_RSP       MSG_ID_VM_STOP_RSP
/* MTK Brian added to handling abnormal cases, 2003/11/17 */
#define PRT_VOICERECORD_FINISH_IND   MSG_ID_VM_RECORD_FINISH_IND
#endif /* __MMI_VOICE_MEMO__ */ 
/* MTK end */

/* End XXX - Call Management */
#define  PRT_GET_ALL_CALL_COSTS_REQ_FAILURE        256
#define  PRT_SET_CALL_TIMER_REQ                 260
#define  PRT_SET_CALL_TIMER_REQ_SUCCESS            261
#define  PRT_SET_CALL_TIMER_REQ_FAILURE            262

//#define PRT_CC_GET_MAX_ACT_REQ                                MSG_ID_MMI_CC_GET_MAX_ACM_REQ
//#define PRT_CC_GET_MAX_ACT_RES                                MSG_ID_MMI_CC_GET_MAX_ACM_RSP
#define  PRT_MMI_CC_GET_ACM_REQ              MSG_ID_MMI_CC_GET_ACM_REQ
#define  PRT_MMI_CC_GET_ACM_RES              MSG_ID_MMI_CC_GET_ACM_RSP
#define  PRT_MMI_CC_GET_CCM_REQ              MSG_ID_MMI_CC_GET_CCM_REQ
#define  PRT_MMI_CC_GET_CCM_RES              MSG_ID_MMI_CC_GET_CCM_RSP
#define  PRT_MMI_CC_RESET_ACM_REQ               MSG_ID_MMI_CC_RESET_ACM_REQ
#define  PRT_MMI_CC_RESET_ACM_RES               MSG_ID_MMI_CC_RESET_ACM_RSP
#define PRT_MMI_CC_GET_MAX_ACM_REQ           MSG_ID_MMI_CC_GET_MAX_ACM_REQ
#define PRT_MMI_CC_GET_MAX_ACM_RES           MSG_ID_MMI_CC_GET_MAX_ACM_RSP

#define PRT_MMI_CC_SET_MAX_ACM_REQ              MSG_ID_MMI_CC_SET_MAX_ACM_REQ
#define PRT_MMI_CC_SET_MAX_ACM_RSP              MSG_ID_MMI_CC_SET_MAX_ACM_RSP

#define  PRT_SET_MYCALLERID_REQ                 269
#define  PRT_SET_MYCALLERID_RES                 270

#define  PRT_SET_PHONE_LINE_REQ                 272
#define  PRT_SET_PHONE_LINE_RES                 273

#define  PRT_SET_NEXT_INCOMING_REQ              275
#define  PRT_SET_NEXT_INCOMING_REQ_SUCCESS         276

#define PRT_UPDATE_ALL_CALL_COST_REQ            277
#define PRT_UPDATE_ALL_CALL_COST_REQ_SUCCESS    278
#define PRT_UPDATE_ALL_CALL_COST_REQ_FAILURE    279

#define PRT_NW_GET_PLMN_LIST_REQ    MSG_ID_MMI_NW_GET_PLMN_LIST_REQ
#define PRT_NW_GET_PLMN_LIST_RSP    MSG_ID_MMI_NW_GET_PLMN_LIST_RSP

#define PRT_NW_SET_PLMN_REQ         MSG_ID_MMI_NW_SET_PLMN_REQ
#define PRT_NW_SET_PLMN_RSP         MSG_ID_MMI_NW_SET_PLMN_RSP

#define PRT_NW_SET_PLMN_SELECT_MODE_REQ      MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ
#define PRT_NW_SET_PLMN_SELECT_MODE_RSP      MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_RSP
/* MTK added, for L4 message change the behavior */
#define PRT_NW_SET_BAND_REQ         MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ        /* MSG_ID_MMI_NW_SET_BAND_REQ */
#define  PRT_NW_SET_BAND_RSP        MSG_ID_MMI_NW_SET_PREFERRED_BAND_RSP        /* MSG_ID_MMI_NW_SET_BAND_RSP */
/* MTK end */
#define PRT_NW_GET_BAND_REQ         MSG_ID_MMI_NW_GET_BAND_REQ
#define  PRT_NW_GET_BAND_RSP        MSG_ID_MMI_NW_GET_BAND_RSP

#define PRT_NW_GET_PLMN_SELECT_MODE_REQ      MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_REQ
#define PRT_NW_GET_PLMN_SELECT_MODE_RES      MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP

#define PRT_PREFERRED_NETWORKS_REQ        MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ
#define PRT_PREFERRED_NETWORKS_REQ_SUCCESS   MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP
#define PRT_PREFERRED_NETWORKS_REQ_FAILURE   MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP

/* micha0202 */
#define PRT_SET_PREFERRED_NETWORKS_REQ       MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ
#define PRT_SET_PREFERRED_NETWORKS_RSP    MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_RSP

#define PRT_NW_ABORT_PLMN_LIST_REQ     MSG_ID_MMI_NW_ABORT_PLMN_LIST_REQ
#define PRT_NW_ABORT_PLMN_LIST_RSP     MSG_ID_MMI_NW_ABORT_PLMN_LIST_RSP

#define PRT_ADD_NEW_REQ                212
#define PRT_ADD_NEW_REQ_SUCCESS           213
#define PRT_ADD_NEW_REQ_FAILURE           214
#define PRT_CHANGE_PRIORITY_REQ           215
#define PRT_CHANGE_PRIORITY_REQ_SUCCESS      216
#define PRT_CHANGE_PRIORITY_REQ_FAILURE      217
#define PRT_FULL_NAME_REQ              218
#define PRT_FULL_NAME_REQ_SUCCESS         219
#define  PRT_FULL_NAME_REQ_FAILURE        220
#define PRT_DELETE_PLMN_REQ               221
#define PRT_DELETE_PLMN_REQ_SUCCESS       222
#define PRT_DELETE_PLMN_REQ_FAILURE       223

#define HW_SET_TIME_REQ                   MSG_ID_MMI_EQ_SET_RTC_TIME_REQ
#define HW_SET_TIME_REQ_SUCCESS              MSG_ID_MMI_EQ_SET_RTC_TIME_RSP
#define HW_SET_TIME_REQ_FAILURE              553

/************************************************/
/* Robin 0602, Remove set AT command profile functions */
/* AT command will query MMI when needed                   */
/************************************************/
//#define HW_SET_TIME_FORMAT_REQ                                        MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ
//#define HW_SET_TIME_FORMAT_REQ_SUCCESS                        MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP
//#define HW_SET_TIME_FORMAT_REQ_FAILURE                        556

#define HW_SET_DATE_REQ                   MSG_ID_MMI_EQ_SET_RTC_TIME_REQ
#define HW_SET_DATE_REQ_SUCCESS              MSG_ID_MMI_EQ_SET_RTC_TIME_RSP
#define HW_SET_DATE_REQ_FAILURE              562

#define HW_SET_DATE_FORMAT_REQ               MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ
#define HW_SET_DATE_FORMAT_REQ_SUCCESS       MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP
#define HW_SET_DATE_FORMAT_REQ_FAILURE       565

/* micha0420 */
#define PRT_MMI_SMU_SET_DIAL_MODE_REQ        MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ
#define PRT_MMI_SMU_SET_DIAL_MODE_RSP        MSG_ID_MMI_SMU_SET_DIAL_MODE_RSP

//#define HW_SET_BARRED_DIAL_REQ                                        MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ 
//#define HW_SET_BARRED_DIAL_RES                                        MSG_ID_MMI_SMU_SET_DIAL_MODE_RSP

/* micha0420 */
#define PRT_MMI_SMU_LOCK_REQ                 MSG_ID_MMI_SMU_LOCK_REQ
#define PRT_MMI_SMU_LOCK_RSP                 MSG_ID_MMI_SMU_LOCK_RSP
#define PRT_MMI_SMU_CHECK_PIN_STATUS_REQ     MSG_ID_MMI_SMU_CHECK_PIN_STATUS_REQ
#define PRT_MMI_SMU_CHECK_PIN_STATUS_RSP     MSG_ID_MMI_SMU_CHECK_PIN_STATUS_RSP

/* micha0420 */
#define PRT_MMI_SMU_GET_DIAL_MODE_REQ        MSG_ID_MMI_SMU_GET_DIAL_MODE_REQ
#define PRT_MMI_SMU_GET_DIAL_MODE_RSP        MSG_ID_MMI_SMU_GET_DIAL_MODE_RSP

#define PRT_MMI_SMU_READ_FILE_INFO_REQ       MSG_ID_MMI_SMU_READ_FILE_INFO_REQ
#define PRT_MMI_SMU_READ_FILE_INFO_RSP       MSG_ID_MMI_SMU_READ_FILE_INFO_RSP

#define PRT_MMI_SMU_CHANGE_PASSWORD_REQ      MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ
#define PRT_MMI_SMU_CHANGE_PASSWORD_RSP      MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP
//micha0420
//#define HW_SET_PHONE_LOCK_REQ                                 MSG_ID_MMI_SMU_LOCK_REQ
//#define HW_SET_PHONE_LOCK_RES                                 MSG_ID_MMI_SMU_LOCK_RSP

#define PRT_EQ_SET_VOLUME_REQ          MSG_ID_MMI_EQ_SET_VOLUME_REQ
#define PRT_EQ_SET_VOLUME_RSP          MSG_ID_MMI_EQ_SET_VOLUME_RSP
#define PRT_EQ_VOLUME_CHANGE_IND       MSG_ID_MMI_EQ_VOLUME_CHANGE_IND
#define PRT_EQ_SET_MUTE_REQ               MSG_ID_MMI_EQ_SET_MUTE_REQ
#define PRT_EQ_SET_MUTE_RSP               MSG_ID_MMI_EQ_SET_MUTE_RSP
#define PRT_EQ_MUTE_CHANGE_IND            MSG_ID_MMI_EQ_MUTE_CHANGE_IND

/************************************************/
/* Robin 0602, Remove set AT command profile functions */
/* AT command will query MMI when needed                   */
/************************************************/
//#define PRT_EQ_SET_SILENT_MODE_REQ                    MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ       
//#define PRT_EQ_SET_SILENT_MODE_RSP                    MSG_ID_MMI_EQ_SET_SILENT_MODE_RSP

#define PRT_EQ_GET_SILENT_MODE_REQ        MSG_ID_MMI_EQ_GET_SILENT_MODE_REQ
#define PRT_EQ_GET_SILENT_MODE_RSP        MSG_ID_MMI_EQ_GET_SILENT_MODE_RSP

/************************************************/
/* Robin 0602, Remove set AT command profile functions */
/* AT command will query MMI when needed                   */
/************************************************/
//#define PRT_EQ_SET_GPIO_LEVEL_REQ                     MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ
//#define PRT_EQ_SET_GPIO_LEVEL_RSP                     MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_RSP

#define PRT_EQ_EXE_GPIO_LEVEL_REQ         MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ
#define PRT_EQ_PLAY_AUDIO_REQ          MSG_ID_MMI_EQ_PLAY_AUDIO_REQ
#define PRT_EQ_STOP_AUDIO_REQ          MSG_ID_MMI_EQ_STOP_AUDIO_REQ
#define PRT_EQ_PLAY_EXT_IMELODY_REQ       MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_REQ
#define PRT_EQ_PLAY_EXT_IMELODY_RSP       MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_RSP

#define PRT_EQ_PLAY_AUDIO_BY_NAME_REQ  MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_REQ
#define PRT_EQ_PLAY_AUDIO_BY_NAME_RSP  MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_RSP
#define PRT_EQ_STOP_AUDIO_BY_NAME_REQ  MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_REQ
#define PRT_EQ_STOP_AUDIO_BY_NAME_RSP  MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_RSP

#define PRT_EQ_PLAY_AUDIO_FINISH_IND   MSG_ID_MMI_EQ_PLAY_AUDIO_FINISH_IND
#define PRT_L4AUD_AUDIO_PLAY_FINISH_IND   MSG_ID_L4AUD_AUDIO_PLAY_FINISH_IND

#define PRT_EQ_GPIO_DETECT_IND            MSG_ID_MMI_EQ_GPIO_DETECT_IND
#define PRT_EQ_SET_SPEECH_MODE_REQ        MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ
#define PRT_EQ_SET_SPEECH_MODE_RSP        MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP

#define  PRT_PHB_STARTUP_FINISH_IND       MSG_ID_MMI_PHB_STARTUP_FINISH_IND
#define  PRT_PHB_STARTUP_READ_IND         MSG_ID_MMI_PHB_STARTUP_READ_IND
#define  PRT_PHB_STARTUP_BEGIN_IND        MSG_ID_MMI_PHB_STARTUP_BEGIN_IND
#define PRT_PHB_STARTUP_READ_NEXT_REQ     MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ
#define PRT_PHB_SET_ENTRY_REQ          MSG_ID_MMI_PHB_SET_ENTRY_REQ
#define PRT_PHB_SET_ENTRY_RSP          MSG_ID_MMI_PHB_SET_ENTRY_RSP
#define PRT_PHB_GET_ENTRY_BY_INDEX_REQ    MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ
#define PRT_PHB_GET_ENTRY_BY_INDEX_RSP    MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_RSP
#define PRT_PHB_DEL_ENTRY_REQ          MSG_ID_MMI_PHB_DEL_ENTRY_REQ
#define PRT_PHB_DEL_ENTRY_RSP          MSG_ID_MMI_PHB_DEL_ENTRY_RSP
#define PRT_PHB_GET_ENTRY_BY_NAME_REQ     MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_REQ
#define PRT_PHB_GET_ENTRY_BY_NAME_RSP     MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_RSP
#define  PRT_PHB_GET_PREFERRED_STORAGE_REQ   MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_REQ
#define  PRT_PHB_GET_PREFERRED_STORAGE_RSP   MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_RSP
#define  PRT_PHB_SET_PREFERRED_STORAGE_REQ   MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_REQ
#define  PRT_PHB_SET_PREFERRED_STORAGE_RSP   MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_RSP
#define  PRT_PHB_GET_ALPHA_LIST_REQ       MSG_ID_MMI_PHB_GET_ALPHA_LIST_REQ
#define  PRT_PHB_GET_ALPHA_LIST_RSP       MSG_ID_MMI_PHB_GET_ALPHA_LIST_RSP
#define  PRT_PHB_UPDATE_IND               MSG_ID_MMI_PHB_UPDATE_IND
#define  PRT_PHB_VCARD_REQ_IND            MSG_ID_MMI_EQ_VCARD_REQ_IND

#define PRT_PHB_STARTUP_PHASE1_FINISH_IND       MSG_ID_MMI_PHB_STARTUP_PHASE1_IND
#define PRT_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ      MSG_ID_MMI_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ
#define  PRT_PHB_STARTUP_READ_ANR_IND        MSG_ID_MMI_PHB_STARTUP_READ_ANR_IND
#define  PRT_PHB_STARTUP_READ_EMAIL_IND         MSG_ID_MMI_PHB_STARTUP_READ_EMAIL_IND
#define  PRT_PHB_STARTUP_READ_GAS_IND        MSG_ID_MMI_PHB_STARTUP_READ_GAS_IND
#define  PRT_PHB_STARTUP_READ_GRP_IND        MSG_ID_MMI_PHB_STARTUP_READ_GRP_IND
#define PRT_PHB_READ_EMAIL_REQ      MSG_ID_MMI_PHB_READ_EMAIL_REQ
#define PRT_PHB_READ_EMAIL_RSP      MSG_ID_MMI_PHB_READ_EMAIL_RSP
#define PRT_PHB_SET_GRP_REQ      MSG_ID_MMI_PHB_SET_GRP_REQ
#define PRT_PHB_SET_GRP_RSP      MSG_ID_MMI_PHB_SET_GRP_RSP
#define PRT_PHB_WRITE_USIM_REQ      MSG_ID_MMI_PHB_WRITE_USIM_REQ
#define PRT_PHB_WRITE_USIM_RSP      MSG_ID_MMI_PHB_WRITE_USIM_RSP

#define PRT_PHB_MEA_ADDR_INPUT_IND     MSG_ID_MEA_PHB_ADDR_INPUT_IND    /* MTK 2003-12-5 Wilson,For MMS */

/* Sim Detection events */
#define PRT_SIM_DETECTION_BASE               400
#define MSG_ID_QUERY_SIM_CARD_REQ            PRT_SIM_DETECTION_BASE+1
#define MSG_ID_QUERY_SIM_CARD_FAILURE        PRT_SIM_DETECTION_BASE+2
#define MSG_ID_QUERY_SIM_CARD_SUCCESS        PRT_SIM_DETECTION_BASE+3
#define  MSG_ID_GET_PIN_REQ                  PRT_SIM_DETECTION_BASE+4

#define  MSG_ID_GET_PIN_RES                  MSG_ID_MMI_SMU_PASSWORD_REQUIRED_IND
/* micha0420 */
#define PRT_MMI_SMU_VERIFY_PIN_REQ              MSG_ID_MMI_SMU_VERIFY_PIN_REQ
#define PRT_MMI_SMU_VERIFY_PIN_RSP              MSG_ID_MMI_SMU_VERIFY_PIN_RSP
#define MSG_ID_SIM_CARD_FAILURE              MSG_ID_MMI_SMU_FAIL_IND
#define PRT_SMU_STARTUP_INFO_IND          MSG_ID_MMI_SMU_STARTUP_INFO_IND

#define PRT_NW_SET_ATTACH_REQ             MSG_ID_MMI_NW_SET_ATTACH_REQ
#define PRT_NW_SET_ATTACH_RSP             MSG_ID_MMI_NW_SET_ATTACH_RSP
#define PRT_POWER_OFF_REQ                 MSG_ID_MMI_EQ_POWER_OFF_REQ
#define PRT_POWER_OFF_RSP                 MSG_ID_MMI_EQ_POWER_OFF_RSP
#define PRT_EQ_POWER_ON_REQ                  MSG_ID_MMI_EQ_POWER_ON_REQ
#ifdef __MMI_USB_SUPPORT__
#define PRT_EQ_USB_DETECT_IND                 MSG_ID_MMI_EQ_USBDETECT_IND
#define PRT_EQ_USB_POWER_ON_FINISH_IND       MSG_ID_DRVMMI_MS_INIT_DONE
#define PRT_EQ_USBCONFIG_RSP              MSG_ID_MMI_EQ_USBCONFIG_RSP
#define PRT_EQ_USBUART_SWITCH_PORT_REQ     MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ
#define PRT_EQ_USBUART_SWITCH_PORT_RSP     MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_RSP
#endif /* __MMI_USB_SUPPORT__ */ 

#define  PRT_NW_ATTACH_IND                MSG_ID_MMI_NW_ATTACH_IND
#define PRT_NW_RX_LEVEL_IND                  MSG_ID_MMI_NW_RX_LEVEL_IND
#define PRT_SERVICE_TYPE_IND              MSG_ID_MMI_NW_REG_STATE_IND
#define PRT_PLMN_LIST_IND                 MSG_ID_MMI_SMU_SUPPORT_PLMN_LIST_IND
#define PRT_GET_IMSI_RSP                  MSG_ID_MMI_SMU_GET_IMSI_RSP
#define PRT_GET_IMSI_REQ                  MSG_ID_MMI_SMU_GET_IMSI_REQ

#define PRT_BATTERY_STATUS_IND               MSG_ID_MMI_EQ_BATTERY_STATUS_IND

//micha0309
//#define PRT_CALL_WAITING_ON_REQ                                               MSG_ID_MMI_SS_CALL_WAIT_REQ
//#define PRT_CALL_WAITING_ON_RSP                                               MSG_ID_MMI_SS_CALL_WAIT_RSP
//#define PRT_CALL_WAITING_OFF_REQ                                      MSG_ID_MMI_SS_CALL_WAIT_REQ
//#define PRT_CALL_WAITING_OFF_RSP                                      MSG_ID_MMI_SS_CALL_WAIT_RSP
//#define PRT_CALL_WAITING_QUERY_REQ                                    MSG_ID_MMI_SS_CALL_WAIT_REQ
#define PRT_MMI_SS_CALL_WAIT_RSP             MSG_ID_MMI_SS_CALL_WAIT_RSP

//micha0309
//#define PRT_CALL_FWD_ON_REQ                                           MSG_ID_MMI_SS_CALL_FORWARD_REQ
#define PRT_MMI_SS_CALL_FORWARD_RSP          MSG_ID_MMI_SS_CALL_FORWARD_RSP
//#define PRT_CALL_FWD_OFF_REQ                                          MSG_ID_MMI_SS_CALL_FORWARD_REQ
//#define PRT_CALL_FWD_OFF_RSP                                          MSG_ID_MMI_SS_CALL_FORWARD_RSP
//#define PRT_CALL_FWD_QUERY_REQ                                        MSG_ID_MMI_SS_CALL_FORWARD_REQ
//#define PRT_CALL_FWD_QUERY_RSP                                        MSG_ID_MMI_SS_CALL_FORWARD_RSP
/** Vandana Manage Call */
/* MTK micha6 duplicated */
/*
 * #define PRT_CALL_WAITING_ON_REQ                 MSG_ID_MMI_SS_CALL_WAIT_REQ
 * #define PRT_CALL_WAITING_ON_RSP                 MSG_ID_MMI_SS_CALL_WAIT_RSP
 * #define PRT_CALL_WAITING_OFF_REQ             MSG_ID_MMI_SS_CALL_WAIT_REQ
 * #define PRT_CALL_WAITING_OFF_RSP             MSG_ID_MMI_SS_CALL_WAIT_RSP
 * #define PRT_CALL_WAITING_QUERY_REQ              MSG_ID_MMI_SS_CALL_WAIT_REQ
 * #define PRT_CALL_WAITING_QUERY_RSP              MSG_ID_MMI_SS_CALL_WAIT_RSP
 */

/* MTK micha6 duplicated */
/*
 * #define PRT_CALL_FWD_ON_REQ                     MSG_ID_MMI_SS_CALL_FORWARD_REQ
 * #define PRT_CALL_FWD_ON_RSP                     MSG_ID_MMI_SS_CALL_FORWARD_RSP
 * #define PRT_CALL_FWD_OFF_REQ                 MSG_ID_MMI_SS_CALL_FORWARD_REQ
 * #define PRT_CALL_FWD_OFF_RSP                 MSG_ID_MMI_SS_CALL_FORWARD_RSP
 * #define PRT_CALL_FWD_QUERY_REQ                  MSG_ID_MMI_SS_CALL_FORWARD_REQ
 * #define PRT_CALL_FWD_QUERY_RSP                  MSG_ID_MMI_SS_CALL_FORWARD_RSP
 */

/** Call Reset */

#define PRT_CALL_RESET_PIN2_REQ                 MSG_ID_MMI_SMU_VERIFY_PIN_REQ
#define PRT_CALL_RESET_PIN2_RSP                 MSG_ID_MMI_SMU_VERIFY_PIN_RSP

#define PRT_MMI_CALL_COST_PRICEUNIT_GET_REQ           MSG_ID_MMI_SMU_GET_PUC_REQ
#define PRT_MMI_CALL_COST_PRICEUNIT_GET_RSP           MSG_ID_MMI_SMU_GET_PUC_RSP
#define PRT_MMI_CALL_COST_PRICEUNIT_SET_REQ           MSG_ID_MMI_SMU_SET_PUC_REQ
#define PRT_MMI_CALL_COST_PRICEUNIT_SET_RSP           MSG_ID_MMI_SMU_SET_PUC_RSP

#define  PRT_MMI_SS_SET_CLIR_FLAG_RSP     MSG_ID_MMI_SS_SET_CLIR_FLAG_RSP
#define  PRT_MMI_SS_SET_CLIR_FLAG_REQ     MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ

/* micha0309 */
#define PRT_MMI_SS_CALL_BARRING_RSP             MSG_ID_MMI_SS_CALL_BARRING_RSP
//#define PRT_CALL_BARRING_ON_RSP                                               MSG_ID_MMI_SS_CALL_BARRING_RSP
//#define PRT_CALL_BARRING_OFF_RSP                                              MSG_ID_MMI_SS_CALL_BARRING_RSP
//#define PRT_CALL_BARRING_QUERY_RSP                                    MSG_ID_MMI_SS_CALL_BARRING_RSP
//#define PRT_CALL_BARRING_CANCEL_ALL                                   MSG_ID_MMI_SS_CALL_BARRING_RSP
#define PRT_MMI_SS_CHANGE_PASSWORD_RSP          MSG_ID_MMI_SS_CHANGE_PASSWORD_RSP
#define PRT_MMI_SS_CLIP_INTERROGATE_IND            MSG_ID_MMI_SS_CLIP_INTERROGATE_IND
#define PRT_MMI_SS_CLIR_INTERROGATE_IND            MSG_ID_MMI_SS_CLIR_INTERROGATE_IND
#define PRT_MMI_SS_COLP_INTERROGATE_IND            MSG_ID_MMI_SS_COLP_INTERROGATE_IND
#define PRT_MMI_SS_COLR_INTERROGATE_IND            MSG_ID_MMI_SS_COLR_INTERROGATE_IND
#define PRT_OUTGOING_DISCONNECT_IND             MSG_ID_MMI_CC_CALL_DISCONNECT_IND

/* micha0309 */
#define PRT_MMI_SS_CNAP_INTERROGATE_IND            MSG_ID_MMI_SS_CNAP_INTERROGATE_IND
#define PRT_MMI_SS_CCBS_RSP                     MSG_ID_MMI_SS_CCBS_RSP

/* micha1228 */
#define PRT_MMI_SS_EMLPP_RSP  MSG_ID_MMI_SS_EMLPP_RSP

/* micha0309 */
#define PRT_LINE_SET_REQ                     MSG_ID_MMI_CPHS_UPDATE_ALS_REQ
#define PRT_MMI_CPHS_UPDATE_ALS_RSP                   MSG_ID_MMI_CPHS_UPDATE_ALS_RSP

#define PRT_SS_STRING_ABORT_REQ                 MSG_ID_MMI_SS_ABORT_REQ
#define PRT_SS_STRING_ABORT_RSP                 MSG_ID_MMI_SS_ABORT_RSP

/* MTK: Brian added, for voice memo, engineer mode */
#ifdef __MMI_VOICE_MEMO__

#define MSG_ID_VM_GET_INFO_REQ                MSG_ID_MMI_VM_GET_INFO_REQ
#define MSG_ID_VM_GET_INFO_RSP                MSG_ID_MMI_VM_GET_INFO_RSP
#define MSG_ID_VM_RECORD_REQ                MSG_ID_MMI_VM_RECORD_REQ
#define MSG_ID_VM_RECORD_RSP                MSG_ID_MMI_VM_RECORD_RSP
#define MSG_ID_VM_PLAY_REQ                MSG_ID_MMI_VM_PLAY_REQ
#define MSG_ID_VM_PLAY_RSP                MSG_ID_MMI_VM_PLAY_RSP
#define MSG_ID_VM_STOP_REQ                MSG_ID_MMI_VM_STOP_REQ
#define MSG_ID_VM_STOP_RSP                MSG_ID_MMI_VM_STOP_RSP
#define MSG_ID_VM_DEL_REQ                MSG_ID_MMI_VM_DEL_REQ
#define MSG_ID_VM_DEL_RSP                MSG_ID_MMI_VM_DEL_RSP
#define MSG_ID_VM_ABORT_REQ                MSG_ID_MMI_VM_ABORT_REQ
#define MSG_ID_VM_ABORT_RSP                MSG_ID_MMI_VM_ABORT_RSP
#define MSG_ID_VM_PAUSE_REQ                MSG_ID_MMI_VM_PAUSE_REQ
#define MSG_ID_VM_PAUSE_RSP                MSG_ID_MMI_VM_PAUSE_RSP
#define MSG_ID_VM_RESUME_REQ                MSG_ID_MMI_VM_RESUME_REQ
#define MSG_ID_VM_RESUME_RSP                MSG_ID_MMI_VM_RESUME_RSP
#define MSG_ID_VM_RENAME_REQ                MSG_ID_MMI_VM_RENAME_REQ
#define MSG_ID_VM_RENAME_RSP                MSG_ID_MMI_VM_RENAME_RSP
#define MSG_ID_VM_APPEND_REQ                MSG_ID_MMI_VM_APPEND_REQ
#define MSG_ID_VM_APPEND_RSP                MSG_ID_MMI_VM_APPEND_RSP
#define MSG_ID_VM_RECORD_FINISH_IND           MSG_ID_MMI_VM_RECORD_FINISH_IND
#define MSG_ID_VM_PLAY_FINISH_IND              MSG_ID_MMI_VM_PLAY_FINISH_IND
#endif /* __MMI_VOICE_MEMO__ */ 

#ifdef __MMI_ENGINEER_MODE__    /* MTK Add Robin 1001 for saperate MMI feature by project */
#define MSG_ID_EM_START_REQ               MSG_ID_MMI_EM_START_REQ
#define MSG_ID_EM_START_RSP               MSG_ID_MMI_EM_START_RSP
#define MSG_ID_EM_STOP_REQ                MSG_ID_MMI_EM_STOP_REQ
#define MSG_ID_EM_STOP_RSP                MSG_ID_MMI_EM_STOP_RSP
#define MSG_ID_EM_SET_GAIN_REQ            MSG_ID_MMI_EM_SET_GAIN_REQ
#define MSG_ID_EM_SET_GAIN_RSP            MSG_ID_MMI_EM_SET_GAIN_RSP
#define MSG_ID_EM_STATUS_IND              MSG_ID_MMI_EM_STATUS_IND
#define MSG_ID_EM_GET_UART_RSP              MSG_ID_MMI_EQ_GET_UART_RSP
#define MSG_ID_EM_SET_UART_RSP              MSG_ID_MMI_EQ_SET_UART_RSP
#define MSG_ID_EQ_SET_AUDIO_PROFILE_REQ   MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ
#define MSG_ID_EQ_SET_AUDIO_PROFILE_RSP   MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP
#define MSG_ID_EQ_GET_AUDIO_PROFILE_REQ   MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ
#define MSG_ID_EQ_GET_AUDIO_PROFILE_RSP   MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP

#endif /* __MMI_ENGINEER_MODE__ */ 
/* MTK:Brian end */

#define PRT_SMS_BASE                   150
#define MSG_ID_SMS_DEL_MSG_BY_REF_REQ        PRT_SMS_BASE+26
#define MSG_ID_SMS_GET_MSG_STATUS_LIST_RSP      PRT_SMS_BASE+29
#define MSG_ID_SMS_GET_MSG_STATUS_LIST_REQ      PRT_SMS_BASE+27
#define MSG_ID_SMS_GET_MSG_BY_REF_RSP        PRT_SMS_BASE+30
#define MSG_ID_SMS_GET_MSG_BY_REF_REQ        PRT_SMS_BASE+28

/* micha0601 begin */
#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 
/* micha0601 end */

#ifdef __MOD_SMSAL__
#define PRT_CELLBROADCAST_BASE               190        /* possibe error ...serious */
#define PRT_ACTIVATE_CELL_BROADCAST_REQ         PRT_CELLBROADCAST_BASE+1
#define PRT_DEACTIVATE_CELL_BROADCAST_REQ    PRT_CELLBROADCAST_BASE+2
#define PRT_ACTIVATE_CELL_BROADCAST_LANG_REQ PRT_CELLBROADCAST_BASE+3
#define PRT_DEACTIVATE_CELL_BROADCAST_LANG_REQ  PRT_CELLBROADCAST_BASE+4
#define PRT_GET_CB_CHANNEL_LIST_REQ          PRT_CELLBROADCAST_BASE+5
#define PRT_ENABLE_CB_CHANNEL_REQ            PRT_CELLBROADCAST_BASE+6
#define PRT_DISABLE_CB_CHANNEL_REQ           PRT_CELLBROADCAST_BASE+7
#define PRT_STORE_CB_CHANNEL_REQ          PRT_CELLBROADCAST_BASE+8
#define PRT_DELETE_CB_CHANNEL_REQ            PRT_CELLBROADCAST_BASE+9
#define PRT_GET_LIST_CB_LANG_REQ          PRT_CELLBROADCAST_BASE+10

#define PRT_DEACTIVATE_CELL_BROADCAST_RSP    PRT_CELLBROADCAST_BASE+1
#define PRT_ACTIVATE_CELL_BROADCAST_RSP         PRT_CELLBROADCAST_BASE+2
#define PRT_ACTIVATE_CELL_BROADCAST_LANG_RSP PRT_CELLBROADCAST_BASE+3
#define PRT_DEACTIVATE_CELL_BROADCAST_LANG_RSP  PRT_CELLBROADCAST_BASE+4
#define PRT_GET_CB_CHANNEL_LIST_RSP          PRT_CELLBROADCAST_BASE+5
#define PRT_ENABLE_CB_CHANNEL_RSP            PRT_CELLBROADCAST_BASE+6
#define PRT_DISABLE_CB_CHANNEL_RSP           PRT_CELLBROADCAST_BASE+7
#define PRT_STORE_CB_CHANNEL_RSP          PRT_CELLBROADCAST_BASE+8
#define PRT_DELETE_CB_CHANNEL_RSP            PRT_CELLBROADCAST_BASE+9
#define PRT_GET_LIST_CB_LANG_RSP          PRT_CELLBROADCAST_BASE+10
#define PRT_CELL_BROADCAST_MSG_IND           PRT_CELLBROADCAST_BASE+11

#endif /* __MOD_SMSAL__ */ 

#define     PRT_MMI_PHB_LAST_NUMBER_READY_IND   MSG_ID_MMI_PHB_LAST_NUMBER_READY_IND
#define     PRT_MMI_PHB_SET_LAST_NUMBER_REQ     MSG_ID_MMI_PHB_SET_LAST_NUMBER_REQ
#define     PRT_MMI_PHB_SET_LAST_NUMBER_RSP     MSG_ID_MMI_PHB_SET_LAST_NUMBER_RSP
#define     PRT_MMI_PHB_GET_LAST_NUMBER_REQ     MSG_ID_MMI_PHB_GET_LAST_NUMBER_REQ
#define     PRT_MMI_PHB_GET_LAST_NUMBER_RSP     MSG_ID_MMI_PHB_GET_LAST_NUMBER_RSP
#define     PRT_MMI_PHB_DEL_LAST_NUMBER_REQ     MSG_ID_MMI_PHB_DEL_LAST_NUMBER_REQ
#define     PRT_MMI_PHB_DEL_LAST_NUMBER_RSP     MSG_ID_MMI_PHB_DEL_LAST_NUMBER_RSP
#define PRT_MMI_CC_SET_CUG_REQ   MSG_ID_MMI_CC_SET_CUG_REQ
#define PRT_MMI_CC_SET_CUG_RSP   MSG_ID_MMI_CC_SET_CUG_RSP
#define  PRT_MSG_ID_MMI_NW_TIME_ZONE_IND           MSG_ID_MMI_NW_TIME_ZONE_IND
/* MTK amanda change 1102 */
#define  PRT_MSG_ID_MMI_EQ_VOLUME_CHANGE_IND       MSG_ID_MMI_EQ_EXE_VOLUME_REQ_IND
#define  PRT_MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND       MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND
#define  PRT_MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND                  MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND
#define  PRT_MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND         MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND
#define  PRT_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND       MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND
#define  PRT_MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_IND         MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_IND

/************************************************/
/* Robin 0602, Remove set AT command profile functions */
/* AT command will query MMI when needed                   */
/************************************************/
#define  PRT_MMI_EQ_SET_GREETING_TEXT_REQ_IND      MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_IND
#define  PRT_MMI_EQ_SET_LANGUAGE_REQ_IND            MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_IND
#define  PRT_MMI_EQ_SET_SILENT_MODE_REQ_IND        MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_IND
#define PRT_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND    MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND
#define  PRT_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND       MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND
#define  PRT_MMI_EQ_MUTE_CHANGE_IND               MSG_ID_MMI_EQ_EXE_MUTE_REQ_IND
#define PRT_MMI_EQ_EQ_GET_GPIO_LEVEL_REQ        MSG_ID_MMI_EQ_GET_GPIO_LEVEL_REQ
#define PRT_MMI_EQ_EQ_GET_GPIO_LEVEL_RSP        MSG_ID_MMI_EQ_GET_GPIO_LEVEL_RSP
#define  PRT_MMI_EQ_SET_LANGUAGE_REQ                 MSG_ID_MMI_EQ_SET_LANGUAGE_REQ

#define PRT_MMI_EQ_QUERY_GREETING_TEXT_REQ_IND      MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_REQ_IND
#define PRT_MMI_EQ_QUERY_LANGUAGE_REQ_IND           MSG_ID_MMI_EQ_QUERY_LANGUAGE_REQ_IND
#define PRT_MMI_EQ_QUERY_SILENT_MODE_REQ_IND        MSG_ID_MMI_EQ_QUERY_SILENT_MODE_REQ_IND
#define PRT_MMI_EQ_QUERY_VIBRATOR_MODE_REQ_IND      MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_REQ_IND
#define PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND   MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND
#define PRT_MMI_EQ_QUERY_MUTE_MODE_REQ_IND          MSG_ID_MMI_EQ_QUERY_MUTE_MODE_REQ_IND

#define PRT_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ      MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ
#define PRT_MMI_EQ_QUERY_LANGUAGE_RES_REQ           MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_REQ
#define PRT_MMI_EQ_QUERY_SILENT_MODE_RES_REQ        MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_REQ
#define PRT_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ      MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ
#define PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ   MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ
#define PRT_MMI_EQ_QUERY_MUTE_MODE_RES_REQ          MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_REQ

#define  PRT_MSG_ID_MMI_CC_DIAL_REQ_IND            MSG_ID_MMI_CC_DIAL_REQ_IND
#define  PRT_MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND        MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND
#define  PRT_MSG_ID_MMI_CC_CALL_ABORT_REQ_IND         MSG_ID_MMI_CC_CALL_ABORT_REQ_IND
/* MTK robin 1119, AT command set wallpaper and profile */
#define PRT_MMI_SET_MMI_DEFAULT_PROF_IND  MSG_ID_MMI_SET_MMI_DEFAULT_PROF_IND

/* MTK amanda change 1102 */
#define  PRT_MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ         MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_IND
#define     PRT_MSG_ID_MMI_CPHS_MMI_INFO_IND MSG_ID_MMI_CPHS_MMI_INFO_IND
#define     PRT_MSG_ID_MMI_CPHS_DISPLAY_CFU_IND MSG_ID_MMI_CPHS_DISPLAY_CFU_IND
/* micha0309 */
#define     PRT_MMI_CPHS_DISPLAY_ALS_IND  MSG_ID_MMI_CPHS_DISPLAY_ALS_IND
/* MTK amanda add 1102 */
#define PRT_MSG_ID_MMI_CC_SYNC_TABLE_REQ_IND MSG_ID_MMI_CC_CALL_SYNC_REQ_IND
#ifdef __TCPIP__
#define PRT_MMI_CC_SET_CSD_PROFILE_REQ   MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ
#define PRT_MMI_CC_SET_CSD_PROFILE_RSP   MSG_ID_MMI_CC_SET_CSD_PROFILE_RSP
#define PRT_MMI_CC_GET_CSD_PROFILE_REQ   MSG_ID_MMI_CC_GET_CSD_PROFILE_REQ
#define PRT_MMI_CC_GET_CSD_PROFILE_RSP   MSG_ID_MMI_CC_GET_CSD_PROFILE_RSP
/* micha0308 */
#ifdef __MMI_GPRS_FEATURES__
#define PRT_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ
#define PRT_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP
#define PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ
#define PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP
#endif /* __MMI_GPRS_FEATURES__ */ 
#endif /* __TCPIP__ */ 

/* micha0308 */
#ifdef __MMI_GPRS_FEATURES__
#define PRT_NW_GET_GPRS_CONNECT_TYPE_REQ  MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ
#define PRT_NW_GET_GPRS_CONNECT_TYPE_RSP  MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP
#define PRT_NW_SET_GPRS_CONNECT_TYPE_REQ  MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ
#define PRT_NW_SET_GPRS_CONNECT_TYPE_RSP  MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_RSP
/* micha1020 */
#define PRT_MMI_PS_GPRS_STATUS_UPDATE_IND MSG_ID_MMI_PS_GPRS_STATUS_UPDATE_IND
#define PRT_MMI_PS_GET_GPRS_DATA_COUNTER_REQ MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ
#define PRT_MMI_PS_GET_GPRS_DATA_COUNTER_RSP MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_RSP
#define PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ  MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ
#define PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP  MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP
#endif /* __MMI_GPRS_FEATURES__ */ 

/************************************************/
/* Robin 0602, Remove set AT command profile functions */
/* AT command will query MMI when needed                   */
/************************************************/
// MTK amanda change 1102
//#define PRT_MMI_EQ_SET_DATE_TIME_FORMAT_REQ MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ
//#define PRT_MMI_EQ_SET_DATE_TIME_FORMAT_RSP MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP

#define PRT_MMI_FMGR_CARD_PLUG_IN_IND  MSG_ID_FMT_MMI_CARD_PLUG_IN_IND
#define PRT_MMI_FMGR_CARD_PLUG_OUT_IND MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND
#define PRT_MMI_FMGR_OTG_DISPLAY_IND      MSG_ID_FMT_MMI_OTG_DISPLAY_IND
#define PRT_MMI_FMGR_COPY_REQ MSG_ID_MMI_FMT_COPY_REQ
#define PRT_MMI_FMGR_COPY_RSP MSG_ID_MMI_FMT_COPY_RSP
#define PRT_MMI_FMGR_FORMAT_REQ MSG_ID_MMI_FMT_FORMAT_REQ
#define PRT_MMI_FMGR_FORMAT_RSP MSG_ID_MMI_FMT_FORMAT_RSP
#define PRT_MMI_FMGR_CHECK_DRIVE_REQ MSG_ID_MMI_FMT_CHECK_DRIVE_REQ
#define PRT_MMI_FMGR_CHECK_DRIVE_RSP MSG_ID_MMI_FMT_CHECK_DRIVE_RSP
#define PRT_MMI_FMGR_UNMOUNT_REQ MSG_ID_MMI_FMT_UNMOUNT_REQ
#define PRT_MMI_FMGR_UNMOUNT_RSP MSG_ID_MMI_FMT_UNMOUNT_RSP
#define PRT_MMI_FMGR_DELETE_REQ MSG_ID_MMI_FMT_DELETE_REQ
#define PRT_MMI_FMGR_DELETE_RSP MSG_ID_MMI_FMT_DELETE_RSP

/* Cylen: add for AT command restore Factory default */
#define PRT_MMI_FACTORY_RESTORE_REQ_IND   MSG_ID_MMI_FACTORY_RESTORE_REQ_IND
#ifdef _NETWORK_CIPHER_SUPPORT_ /* Cylen: add for GSM/GPRS ciphering indication */
#define PRT_MMI_SMU_CIPHER_IND   MSG_ID_MMI_SMU_CIPHER_IND
#endif 
   /************************************************/
   /* message for MMI VRSI                            */
   /************************************************/
#if defined(__MMI_VRSI__)
#define PRT_MMI_VRSI_ADD_CENTRAL_REQ      MSG_ID_MMI_VRSI_ADD_CENTRAL_REQ

#if defined(__MMI_BT_SUPPORT__)
#define PRT_MMI_L4_BT_SET_VR_REQ_IND      MSG_ID_MMI_L4_BT_SET_VR_REQ_IND
#define PRT_MMI_L4_BT_SET_VR_REQ       MSG_ID_MMI_L4_BT_SET_VR_REQ
#define PRT_MMI_L4_BT_SET_VR_RSP       MSG_ID_MMI_L4_BT_SET_VR_RSP
#endif /* defined(__MMI_BT_SUPPORT__) */ 
#endif /* defined(__MMI_VRSI__) */ 

/* micha_POC */
#ifdef __MMI_POC__
#define PRT_POC_REGISTER_REQ                    MSG_ID_POC_REGISTER_REQ
#define PRT_POC_REGISTER_RSP                    MSG_ID_POC_REGISTER_RSP
#define PRT_POC_REGISTER_IND                    MSG_ID_POC_REGISTER_IND
#define PRT_POC_SETTING_REQ                     MSG_ID_POC_SETTING_REQ
#define PRT_POC_SETTING_RSP                     MSG_ID_POC_SETTING_RSP
#define PRT_POC_TALK_INVITE_REQ              MSG_ID_POC_TALK_INVITE_REQ
#define PRT_POC_TALK_INVITE_RSP                 MSG_ID_POC_TALK_INVITE_RSP
#define PRT_POC_TALK_PROGRESS_IND               MSG_ID_POC_TALK_PROGRESS_IND
#define PRT_POC_TALK_DISCONNECT_REQ          MSG_ID_POC_TALK_DISCONNECT_REQ
#define PRT_POC_TALK_DISCONNECT_RSP          MSG_ID_POC_TALK_DISCONNECT_RSP
#define PRT_POC_TALK_CONNECT_IND             MSG_ID_POC_TALK_CONNECT_IND
#define PRT_POC_TALK_RING_IND                MSG_ID_POC_TALK_RING_IND
#define PRT_POC_TALK_ANSWER_REQ              MSG_ID_POC_TALK_ANSWER_REQ
#define PRT_POC_TALK_ANSWER_RSP              MSG_ID_POC_TALK_ANSWER_RSP
#define PRT_POC_TALK_DISCONNECT_IND          MSG_ID_POC_TALK_DISCONNECT_IND
#define PRT_POC_FLOOR_GRANT_IND              MSG_ID_POC_FLOOR_GRANT_IND
#define PRT_POC_FLOOR_DENY_IND                  MSG_ID_POC_FLOOR_DENY_IND
#define PRT_POC_FLOOR_TAKEN_IND              MSG_ID_POC_FLOOR_TAKEN_IND
#define PRT_POC_FLOOR_TAKE_REQ                  MSG_ID_POC_FLOOR_TAKE_REQ
#define PRT_POC_FLOOR_RELEASE_REQ               MSG_ID_POC_FLOOR_RELEASE_REQ
#define PRT_POC_FLOOR_IDLE_IND                  MSG_ID_POC_FLOOR_IDLE_IND
#define PRT_POC_FLOOR_REVOKE_IND             MSG_ID_POC_FLOOR_REVOKE_IND
#define PRT_POC_MEDIA_START_ENCODE_REQ    MSG_ID_POC_MEDIA_START_ENCODE_REQ
#define PRT_POC_MEDIA_START_ENCODE_RSP    MSG_ID_POC_MEDIA_START_ENCODE_RSP
#define PRT_POC_MEDIA_STOP_ENCODE_REQ        MSG_ID_POC_MEDIA_STOP_ENCODE_REQ
#define PRT_POC_MEDIA_STOP_ENCODE_RSP        MSG_ID_POC_MEDIA_STOP_ENCODE_RSP
#define PRT_POC_MEDIA_START_DECODE_REQ    MSG_ID_POC_MEDIA_START_DECODE_REQ
#define PRT_POC_MEDIA_START_DECODE_RSP    MSG_ID_POC_MEDIA_START_DECODE_RSP
#define PRT_POC_MEDIA_STOP_DECODE_REQ        MSG_ID_POC_MEDIA_STOP_DECODE_REQ
#define PRT_POC_MEDIA_STOP_DECODE_RSP        MSG_ID_POC_MEDIA_STOP_DECODE_RSP
#endif /* __MMI_POC__ */ 

#ifdef __FLIGHT_MODE_SUPPORT__
#define PRT_NW_CFUN_STATE_REQ       MSG_ID_MMI_NW_CFUN_STATE_REQ
#define PRT_NW_CFUN_STATE_RSP       MSG_ID_MMI_NW_CFUN_STATE_RSP
#endif /* __FLIGHT_MODE_SUPPORT__ */ 

#ifdef __HOMEZONE_SUPPORT__
#define PRT_MMI_HZ_TAG_IND          MSG_ID_MMI_HZ_TAG_IND
#endif 

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define  MSG_ID_MMI_THM_CONTENT_RCVD      MSG_ID_MMI_THM_CONTENT_RCVD
#define MSG_ID_DA_GET_CONTENT_REQ      MSG_ID_DA_GET_CONTENT_REQ
#define MSG_ID_DA_CONTINUE_DOWNLOAD    MSG_ID_DA_CONTINUE_DOWNLOAD
#define MSG_ID_MMI_DOWNLOAD_RES        MSG_ID_MMI_DOWNLOAD_RES
#define  MSG_ID_MMI_DOWNLOAD_COMPLETE_NOTIFY MSG_ID_MMI_DOWNLOAD_COMPLETE_NOTIFY
#define  MSG_ID_DA_ABORT_REQ           MSG_ID_DA_ABORT_REQ
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__) */ 

#ifdef __MMI_SML_MENU__
#define PRT_MMI_SMU_SET_PERSONALIZATION_REQ MSG_ID_MMI_SMU_SET_PERSONALIZATION_REQ
#define PRT_MMI_SMU_SET_PERSONALIZATION_RSP MSG_ID_MMI_SMU_SET_PERSONALIZATION_RSP
#define PRT_MMI_SMU_SML_STATUS_REQ MSG_ID_MMI_SMU_SML_STATUS_REQ
#define PRT_MMI_SMU_SML_STATUS_RSP MSG_ID_MMI_SMU_SML_STATUS_RSP
#endif /* __MMI_SML_MENU__ */

/* CCA events */
#ifdef __MMI_CCA_SUPPORT__
#define PRT_MMI_CCA_APP_CONFIGURE_IND               MSG_ID_MMI_CCA_APP_CONFIGURE_IND
#define PRT_MMI_CCA_APP_CONFIGURE_RSP               MSG_ID_MMI_CCA_APP_CONFIGURE_RSP
#define PRT_MMI_CCA_SOURCE_NEW_DOC_IND              MSG_ID_MMI_CCA_SOURCE_NEW_DOC_IND
#define PRT_MMI_CCA_SOURCE_NEW_DOC_RSP              MSG_ID_MMI_CCA_SOURCE_NEW_DOC_RSP
#define PRT_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND   MSG_ID_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND
#define PRT_MMI_CCA_SOURCE_UI_NEW_SETTING_IND       MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND
#define PRT_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP       MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP
#define PRT_MMI_CCA_SOURCE_UI_AUTH_IND              MSG_ID_MMI_CCA_SOURCE_UI_AUTH_IND
#define PRT_MMI_CCA_SOURCE_UI_AUTH_RSP              MSG_ID_MMI_CCA_SOURCE_UI_AUTH_RSP
#define PRT_MMI_CCA_NEW_DOC_CONTINUE_IND            MSG_ID_MMI_CCA_NEW_DOC_CONTINUE_IND
#define PRT_MMI_CCA_GET_PROF_IND                    MSG_ID_MMI_CCA_GET_PROF_IND
#define PRT_MMI_CCA_GET_PROF_RSP                    MSG_ID_MMI_CCA_GET_PROF_RSP
#define PRT_MMI_CCA_APP_GET_PROF_IND                MSG_ID_MMI_CCA_APP_GET_PROF_IND
#define PRT_MMI_CCA_APP_GET_PROF_RSP                MSG_ID_MMI_CCA_APP_GET_PROF_RSP
#define PRT_MMI_CCA_UPDATE_PROF_IND                 MSG_ID_MMI_CCA_UPDATE_PROF_IND
#define PRT_MMI_CCA_UPDATE_PROF_RSP                 MSG_ID_MMI_CCA_UPDATE_PROF_RSP
#define PRT_MMI_CCA_APP_UPDATE_PROF_IND             MSG_ID_MMI_CCA_APP_UPDATE_PROF_IND
#define PRT_MMI_CCA_APP_UPDATE_PROF_RSP             MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP
#endif

#endif /* MMI_ON_HARDWARE_P */ 

#ifdef MMI_ON_WIN32
/* Timer */
#define	PRT_MMI_TIMER_IND			         100

//////Messages with values in L4
//#if defined(__MOD_CSM__) 
#define  PRT_MMI_CC_RESET_ACM_REQ         1201
#define PRT_MMI_CC_RESET_ACM_RES          1202
#define PRT_MMI_CC_GET_ACM_REQ            1203
#define PRT_MMI_CC_GET_ACM_RES            1204
#define PRT_MMI_CC_SET_MAX_ACM_REQ           1205
#define PRT_MMI_CC_SET_MAX_ACM_RSP           1206
#define PRT_MMI_CC_GET_MAX_ACM_REQ        1207
#define PRT_MMI_CC_GET_MAX_ACM_RES        1208

#define PRT_MMI_CC_GET_CCM_REQ            1209
#define PRT_MMI_CC_GET_CCM_RES            1210
#define PRT_MMI_CC_SET_CUG_REQ           1211
#define PRT_MMI_CC_SET_CUG_RSP           1212
//#define //MSG_ID_MMI_CC_GET_CUG_REQ           1213 
//#define //MSG_ID_MMI_CC_GET_CUG_RSP           1214 
//#define // TODO MSG_ID_MMI_CC_CHLD_REQ              1215 
//#define // TODO PRT_WAITINGCALL_REJECT_RSP            1216 
//#define //MSG_ID_MMI_CC_HANGUP_REQ            1217 
//#define //MSG_ID_MMI_CC_HANGUP_RSP            1218 
#define PRT_ATH_REQ                 1219
#define PRT_ATH_REQ_SUCCESS            1220
#define PTR_GET_CALL_LIST_REQ       1221
#define PTR_GET_CALL_LIST_RSP       1222
#define PRT_CALL_DEFLECT_REQ        1223
#define PRT_CALL_DEFLECT_RSP        1224
#define PRT_DTMF_START_REQ          1225
#define PRT_DTMF_START_RES          1226
#define PRT_DTMF_STOP_REQ           1227
#define PRT_DTMF_STOP_RES           1228
#define PRT_START_VOICERECORD_REQ      1696
#define PRT_START_VOICERECORD_RSP      1697
#define PRT_STOP_VOICERECORD_REQ    1698
#define PRT_STOP_VOICERECORD_RSP    1699

#define PRT_VOICERECORD_FINISH_IND      1218

//#define //MSG_ID_MMI_CC_START_AUTO_DTMF_REQ                  1229 
//#define //MSG_ID_MMI_CC_START_AUTO_DTMF_RSP                  1230 
//#define //MSG_ID_MMI_CC_START_AUTO_DTMF_IND                  1231 
//#define //MSG_ID_MMI_CC_START_AUTO_DTMF_FINISH_IND           1232 
#define PRT_INCOMINGCALL_ACCEPT_EVENT  1233
#define PRT_INCOMINGCALL_ACCEPT_SUCCESS   1234
//#define //MSG_ID_MMI_CC_DISCONNECT_AUX_REQ                           1235 
//#define //MSG_ID_MMI_CC_DISCONNECT_AUX_RSP                           1236 
#define PRT_LINE_SET_REQ                  1237
/* micha0309 */
#define PRT_MMI_CPHS_UPDATE_ALS_RSP                1238
#define PRT_OUTGOINGCALL_EVENT         1239
//#define //MSG_ID_MMI_CC_DIAL_RSP                           1240 
//#define //MSG_ID_MMI_CC_DIAL_REQ_IND                           1241 
#define PRT_OUTGOINGCALL_EVENT_RSP     1242
//#define //MSG_ID_MMI_CC_CALL_MODIFY_REQ                           1243 
//#define //MSG_ID_MMI_CC_CALL_MODIFY_RSP                           1244 
//#define //MSG_ID_MMI_CC_SET_SINGLE_NUM_REQ                           1245 
//#define //MSG_ID_MMI_CC_SET_SINGLE_NUM_RSP                           1246 
//#define //MSG_ID_MMI_CC_GET_SINGLE_NUM_REQ                           1247 
//#define //MSG_ID_MMI_CC_GET_SINGLE_NUM_RSP                           1248 
#define PRT_AOC_EVENT_IND           1249
#define PRT_PLAY_GSM_TONE           1250
#define PRT_INCOMING_CALL_WAIT         1251
#define PRT_INCOMINGCALL_EVENT         1252
#define PRT_OUTGOINGCALL_CONNECTED     1253
#define PRT_OUTGOING_DISCONNECT_IND          1254
#define PRT_HELDCALL_DISCONNECTED      1255
#define PRT_SPEECH_IND_EVENT        1256
#define PRT_INCOMINGCALL_FORWARD_SUCCESS  9
#define PRT_CALLHOLD_SUCCESS        1216
#define PRT_NETWORK_ERROR           20
#define  PRT_GET_ALL_CALL_COSTS_REQ_FAILURE        256
#define  PRT_SET_CALL_TIMER_REQ                 260
#define  PRT_SET_CALL_TIMER_REQ_SUCCESS            261
#define  PRT_SET_CALL_TIMER_REQ_FAILURE            262
#define  PRT_SET_MYCALLERID_REQ                 269
#define  PRT_SET_MYCALLERID_RES                 270

#define  PRT_SET_PHONE_LINE_REQ                 272
#define  PRT_SET_PHONE_LINE_RES                 273

#define  PRT_SET_NEXT_INCOMING_REQ              275
#define  PRT_SET_NEXT_INCOMING_REQ_SUCCESS         276

#define PRT_UPDATE_ALL_CALL_COST_REQ            277
#define PRT_UPDATE_ALL_CALL_COST_REQ_SUCCESS    278
#define PRT_UPDATE_ALL_CALL_COST_REQ_FAILURE    279
#define PRT_CCBS_ACTIVATE_REQ                1215
#define PRT_CCBS_ACTIVATE_RSP                1216
#define PRT_ECT_REQ                          1216
#define PRT_ECT_REQ_SUCCESS                     1216
#define PRT_SWAPCALL_EVENT                   1215
#define PRT_SWAPCALLREQ_SUCCESS                 1216
#define PRT_CONFCALL_EVENT                   1215
#define PRT_CONFCALLREQ_SUCCESS                 1216
#define PRT_ENDALLCALL_EVENT                 1215
#define PRT_ENDALLCALLREQ_SUCCESS               1255
/* Start by Julia: Drop call refinement */
#define PRT_RELCOMP_EVENT                    1215
/* End by Julia */
#define PRT_END_CHLD_RSP                     1216
#define PRT_ENDALLACTIVE_EVENT                  1215
#define PRT_ENDALLACTIVEREQ_SUCCESS             1255
#define PRT_SPLITCALL_EVENT                     1215
#define PRT_SPLITCALLREQ_SUCCESS             1216
#define PRT_UDUB_REQ                      1215
#define PRT_UDUB_RES_SUCCESS                 1255
#define PRT_HELDCALLS_END_SUCCESS               1255
#define PRT_CALLENDALLHOLD_EVENT             1215
#define PRT_RETRIEVECALL_EVENT                  1215
#define PRT_RETRIEVECALLREQ_SUCCESS             1216
#define PRT_CALLHOLD_EVENT                   1215
#define PRT_ACCEPTINCOMING_EVENT             1215
#define PRT_ACCEPTINCOMING_SUCCESS              1216
#define PRT_CCBS_DIAL_EVENT                     1215
#define PRT_CCBS_DIAL_RSP                    1216

#define PRT_ADD_NEW_REQ                212
#define PRT_ADD_NEW_REQ_SUCCESS           213
#define PRT_ADD_NEW_REQ_FAILURE           214
#define PRT_CHANGE_PRIORITY_REQ           215
#define PRT_CHANGE_PRIORITY_REQ_SUCCESS      216
#define PRT_CHANGE_PRIORITY_REQ_FAILURE      217
#define PRT_FULL_NAME_REQ              218
#define PRT_FULL_NAME_REQ_SUCCESS         219
#define  PRT_FULL_NAME_REQ_FAILURE        220
#define PRT_DELETE_PLMN_REQ               221
#define PRT_DELETE_PLMN_REQ_SUCCESS       222
#define PRT_DELETE_PLMN_REQ_FAILURE       223
#define PRT_MMI_SS_CALL_WAIT_RSP          1276
//#define PRT_CALL_FWD_QUERY_RSP                                1274
//micha0309
//#define PRT_CALL_BARRING_QUERY_RSP                    1286
#define PRT_NWRK_CALL_RELEASE          1255
#define PRT_INCOMINGCALL_REJECT_EVENT     1219
#define PRT_INCOMINGCALL_REJECTED         1220
#define PRT_CALLENDSPECIFIC_EVENT         1215
#define PRT_CALLENDSPECIFIC_SUCCESS       1255
#define PTR_TURN_SPEECH_AROUND            1327

// #define //MSG_ID_MMI_CC_NAME_IND                           1257
#define PRT_NOTIFY_SS_EVENT            1258
//#define //MSG_ID_MMI_CC_NOTIFY_SS_CUG_IND                           1259 
//#define //MSG_ID_MMI_CC_NOTIFY_SS_ECT_IND                           1260 
////////////////////////////#define //MSG_ID_MMI_CC_NOTIFY_SS_CNAP_IND                           1261 
#define PRT_CCBS_NOTIFY_IND            1262
#define PRT_DTMF_CONFIRM_IND        1263
#define PRT_DTMF_CONFIRM_REQ        1264
//#define //MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND                                      1263 
//#define //MSG_ID_MMI_CC_CALL_ABORT_REQ_IND                                      1264 
//#define //#endif(__MOD_CSM__) 
//#define 
//#define //MSG_ID_MMI_CC_SET_BEARER_SERVICE_REQ                                 1265 
//#define //MSG_ID_MMI_CC_SET_BEARER_SERVICE_RSP                                 1266 
//#define //MSG_ID_MMI_CC_GET_BEARER_SERVICE_REQ                                 1267 
//#define //MSG_ID_MMI_CC_GET_BEARER_SERVICE_RSP                                 1268 
//#define //#endif (__TCPIP__) 
//#define 
//#define //MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_REQ                                 1269 
//#define //MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_RSP                                 1270 
//#define //MSG_ID_MMI_SS_EMLPP_REQ                                 8154216 
//#define //MSG_ID_MMI_SS_EMLPP_RSP                                 1272 

//micha0309
//#define PRT_CALL_FWD_OFF_RSP                                  1274 
#define PRT_MMI_SS_CALL_FORWARD_RSP                1274
//#define // TODO PRT_CALL_WAITING_ON_REQ                                       1275 
//#define // TODO PRT_CALL_WAITING_ON_RSP                                       1276 
//#define //MSG_ID_MMI_SS_INTERROGATE_REQ                                 1277 
//#define //MSG_ID_MMI_SS_INTERROGATE_RSP                                 1278 
//#define //MSG_ID_MMI_SS_CDIP_INTERROGATE_IND                                 1279 

/* micha0309 */
#define PRT_MMI_SS_CLIP_INTERROGATE_IND      1280
#define PRT_MMI_SS_CLIR_INTERROGATE_IND      1281
#define PRT_MMI_SS_CNAP_INTERROGATE_IND      1282
#define PRT_MMI_SS_COLP_INTERROGATE_IND      1283
#define PRT_MMI_SS_COLR_INTERROGATE_IND      1284

/* micha0309 */
#define PRT_MMI_SS_CALL_BARRING_RSP       1286
#define PRT_CALL_BARRING_CANCEL_ALL          1286
#define PRT_USSD_REQ             1287
#define PRT_USSD_RES_SUCCESS        1288
#define PRT_USSR_IND             1289
#define PRT_USSN_IND             1290
#define PRT_MMI_SS_CHANGE_PASSWORD_RSP          1292
#define PRT_USSDVSS_REQ             1293
#define PRT_USSDVSS_RSP             1294
/* micha0309 */
#define PRT_MMI_SS_CCBS_RSP            1297

#define PRT_SS_STRING_ABORT_REQ              1298
#define PRT_SS_STRING_ABORT_RSP              1299
#define PRT_MMI_SS_SET_CLIR_FLAG_REQ                         1300
#define PRT_MMI_SS_SET_CLIR_FLAG_RSP                         1301
// #define //#if defined(__MOD_UEM__)

#define PRT_EQ_SET_VOLUME_REQ       1302
#define PRT_EQ_SET_VOLUME_RSP       1303
#define PRT_EQ_VOLUME_CHANGE_IND    1304
#define PRT_EQ_SET_MUTE_REQ            1305
#define PRT_EQ_SET_MUTE_RSP            1306
#define PRT_EQ_MUTE_CHANGE_IND         1307

/************************************************/
/* Robin 0602, Remove set AT command profile functions */
/* AT command will query MMI when needed                   */
/************************************************/
//#define PRT_EQ_SET_SILENT_MODE_REQ            1308 
//#define PRT_EQ_SET_SILENT_MODE_RSP            1309 

#define PRT_MMI_EQ_SET_SILENT_MODE_REQ_IND   1310
#define PRT_EQ_GET_SILENT_MODE_REQ     1311
#define PRT_EQ_GET_SILENT_MODE_RSP     1312

/************************************************/
/* Robin 0602, Remove set AT command profile functions */
/* AT command will query MMI when needed                   */
/************************************************/
//#define PRT_EQ_SET_GPIO_LEVEL_REQ             1313 
//#define PRT_EQ_SET_GPIO_LEVEL_RSP             1314 

#define PRT_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND 1315
#define PRT_EQ_GET_GPIO_LEVEL_REQ      1316
#define PRT_EQ_GET_GPIO_LEVEL_RSP      1317
#define PRT_EQ_EXE_GPIO_LEVEL_REQ      1318
#define PRT_EQ_EXE_GPIO_LEVEL_RSP      1319
#define PRT_EQ_PLAY_AUDIO_REQ       1320
#define PRT_EQ_STOP_AUDIO_REQ       1322
#define PRT_EQ_PLAY_EXT_IMELODY_REQ    1324
#define PRT_EQ_PLAY_EXT_IMELODY_RSP    1325
#define PRT_EQ_GPIO_DETECT_IND         1326
#define PRT_EQ_SET_SPEECH_MODE_REQ     1327
#define PRT_EQ_SET_SPEECH_MODE_RSP     1328

#define PRT_EQ_PLAY_AUDIO_BY_NAME_REQ                         1329
#define PRT_EQ_PLAY_AUDIO_BY_NAME_RSP                         1330
#define PRT_EQ_STOP_AUDIO_BY_NAME_REQ                         1331
#define PRT_EQ_STOP_AUDIO_BY_NAME_RSP                         1332

#define MSG_ID_EQ_SET_AUDIO_PROFILE_REQ  1333
#define MSG_ID_EQ_SET_AUDIO_PROFILE_RSP  1334
#define MSG_ID_EQ_GET_AUDIO_PROFILE_REQ  1335
#define MSG_ID_EQ_GET_AUDIO_PROFILE_RSP  1336

#define PRT_EQ_PLAY_AUDIO_FINISH_IND  1337
#define PRT_L4AUD_AUDIO_PLAY_FINISH_IND   1338

//#define //MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ                            1337 
//#define //MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_RSP                            1338 
//#define //MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ                            1339 
//#define //MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_RSP                            1340 
//#define //MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND                            1342 
//#define //MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ                            1342 
//#define //MSG_ID_MMI_EQ_SET_AUDIO_MODE_RSP                            1343 
 //#endif (__MOD_UEM__) 

// #if defined(__MOD_UEM__)

#define HW_SET_TIME_REQ                1344
#define HW_SET_TIME_REQ_SUCCESS           1345
//#define //MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND                            1346 
//#define //MSG_ID_MMI_EQ_GET_RTC_TIME_REQ                            1347 
//#define //MSG_ID_MMI_EQ_GET_RTC_TIME_RSP                            1348 
//#define //MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ                            1349 
//#define //MSG_ID_MMI_EQ_DEL_RTC_TIMER_RSP                            1350 
//#define //MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_IND                            1351 
//#define // TODO HW_SET_TIME_FORMAT_REQ                                1352 
#define HW_SET_TIME_FORMAT_REQ_SUCCESS    1353
//#define //MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND                            1354 
///#define //MSG_ID_MMI_EQ_GET_DATE_TIME_FORMAT_REQ                            1355 
//#define //MSG_ID_MMI_EQ_GET_DATE_TIME_FORMAT_RSP                            1356 
//#define //MSG_ID_MMI_EQ_START_TIMER_REQ                            1357 
//#define //MSG_ID_MMI_EQ_START_TIMER_RSP                             1358 
//#define //MSG_ID_MMI_EQ_STOP_TIMER_REQ                             1359 
//#define //MSG_ID_MMI_EQ_STOP_TIMER_RSP                             1360 
//#define //MSG_ID_MMI_EQ_CLOCK_TICK_IND                             1361 
//#define //MSG_ID_MMI_EQ_ALARM_IND                             1362 
 //#endif (__MOD_UEM__) 

// #if defined(__MOD_UEM__)

//#define //MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ                             1363 
//MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_RSP                             1364 
//MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND                             1365 
//MSG_ID_MMI_EQ_SET_INDICATOR_REQ                             1366 
//MSG_ID_MMI_EQ_SET_INDICATOR_RSP                             1367 
//MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND                             1368 
//MSG_ID_MMI_EQ_GET_INDICATOR_REQ                             1369 
//MSG_ID_MMI_EQ_GET_INDICATOR_RSP                             1370 
//MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ                             1371 
//MSG_ID_MMI_EQ_DISPLAY_TEXT_RSP                             1372 
//MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND                             1373 
//MSG_ID_MMI_EQ_KEYPAD_DETECT_IND                             1374 
//#endif(__MOD_UEM__) 

// #if defined(__MOD_UEM__)

//MSG_ID_MMI_EQ_SET_LANGUAGE_REQ                             1375 
//MSG_ID_MMI_EQ_SET_LANGUAGE_RSP                             1376 
//MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_IND                             1377 
//MSG_ID_MMI_EQ_GET_LANGUAGE_REQ                             1378 
//MSG_ID_MMI_EQ_GET_LANGUAGE_RSP                             1379 
//MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ                        1380 
//MSG_ID_MMI_EQ_SET_GREETING_TEXT_RSP                   1381 
//MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_IND                   1382 
//MSG_ID_MMI_EQ_GET_GREETING_TEXT_REQ                   1383 
//MSG_ID_MMI_EQ_GET_GREETING_TEXT_RSP                   1384 
//MSG_ID_MMI_EQ_SET_COUNTRY_CODE_REQ                   1385 
//MSG_ID_MMI_EQ_SET_COUNTRY_CODE_RSP                   1386 
//MSG_ID_MMI_EQ_GET_COUNTRY_CODE_REQ                   1387 
//MSG_ID_MMI_EQ_GET_COUNTRY_CODE_RSP                   1388 
//MSG_ID_MMI_EQ_GET_BATTERY_STATUS_REQ                   1389 
//MSG_ID_MMI_EQ_GET_BATTERY_STATUS_RSP                   1390 
//MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ                                     1391 
//MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP                                     1392 
//MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_REQ                                     1393 
//MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_RSP                                     1394 
//MSG_ID_MMI_EQ_POWER_ON_REQ                                     1395 
//MSG_ID_MMI_EQ_POWER_ON_RSP                                     1396 
//MSG_ID_MMI_EQ_POWER_OFF_REQ                                     1397 
//MSG_ID_MMI_EQ_POWER_OFF_RSP                                     1398 
#define MMI_EQ_POWER_ON_IND               1399
#define PRT_BATTERY_STATUS_IND            1400
// #endif(__MOD_UEM__)

// #ifdef(__MOD_NVRAM__)

//#define //MSG_ID_MMI_EQ_NVRAM_READ_REQ                                     1401 
//#define //MSG_ID_MMI_EQ_NVRAM_READ_RSP                                     1402 
//#define //MSG_ID_MMI_EQ_NVRAM_WRITE_REQ                                     1403 
//#define //MSG_ID_MMI_EQ_NVRAM_WRITE_RSP                                     1404 
//#define //MSG_ID_MMI_EQ_SET_UART_REQ                                     1405 
#define MSG_ID_EM_SET_UART_RSP             1406
// #define //MSG_ID_MMI_EQ_GET_UART_REQ                                     1407
#define MSG_ID_EM_GET_UART_RSP             1408
//#define //MSG_ID_MMI_EQ_NVRAM_READY_IND                                     1409 
 //#endif(__MOD_NVRAM__) 

// #ifdef(__MOD_RAC__)

#define MSG_ID_MMI_NW_GET_IMEI_REQ             2524
#define MSG_ID_MMI_NW_GET_IMEI_RSP             2525
#define PRT_NW_ABORT_PLMN_LIST_REQ  1412
#define PRT_NW_ABORT_PLMN_LIST_RSP  1413
//#define //MSG_ID_MMI_NW_SET_ATTACH_REQ             1414 
//#define //MSG_ID_MMI_NW_SET_ATTACH_RSP             1415 
//#define //MSG_ID_MMI_NW_GET_ATTACH_REQ             1416 
//#define //MSG_ID_MMI_NW_GET_ATTACH_RSP             1417 
//#define //MSG_ID_MMI_NW_SET_MOBILE_CLASS_REQ             1418 
//#define //MSG_ID_MMI_NW_SET_MOBILE_CLASS_RSP             1419 
//#define //MSG_ID_MMI_NW_GET_MOBILE_CLASS_REQ             1420 
//#define //MSG_ID_MMI_NW_GET_MOBILE_CLASS_RSP             1421 
#define PRT_NW_SET_PLMN_SELECT_MODE_REQ   1422
#define PRT_NW_SET_PLMN_SELECT_MODE_RSP   1423
#define PRT_NW_GET_PLMN_SELECT_MODE_REQ   1424
#define PRT_NW_GET_PLMN_SELECT_MODE_RES   1425
#define PRT_NW_SET_PLMN_REQ      1426
#define PRT_NW_SET_PLMN_RSP      1427
#define PRT_NW_GET_PLMN_LIST_REQ 1428
#define PRT_NW_GET_PLMN_LIST_RSP 1429
//#define //MSG_ID_MMI_NW_GET_CURRENT_PLMN_REQ             1430 
//#define //MSG_ID_MMI_NW_GET_CURRENT_PLMN_RSP             1431 
///#define //MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_REQ             1432 
//#define //MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_RSP             1433 
#define PRT_NW_GET_BAND_REQ      1434
#define PRT_NW_GET_BAND_RSP      1435
#define PRT_NW_ATTACH_IND              1436
#define PRT_SERVICE_TYPE_IND           1437
#define PRT_NW_RX_LEVEL_IND               1438
// #define //MSG_ID_MMI_NW_TIME_ZONE_IND                    1439
#define PRT_NW_SET_BAND_REQ      1440
#define PRT_NW_SET_BAND_RSP      1441
/* endif(__MOD_RAC__) */

/* ifdef(__MOD_SMU__) */

#define PRT_GET_IMSI_REQ               1442
#define PRT_GET_IMSI_RSP               1443
/* micha0420 */
#define PRT_MMI_SMU_LOCK_REQ              1444
#define PRT_MMI_SMU_LOCK_RSP              1445
//#define //MSG_ID_MMI_SMU_RESET_DATA_REQ                    1446 
//#define //MSG_ID_MMI_SMU_RESET_DATA_RSP                    1447 
#define PRT_CALL_RESET_PIN2_REQ           1448
#define PRT_CALL_RESET_PIN2_RSP           1449
/* micha0420 */
#define PRT_MMI_SMU_VERIFY_PIN_REQ           1448
#define PRT_MMI_SMU_VERIFY_PIN_RSP           1449
#define MSG_ID_MMI_SMU_GET_REQUIRED_PIN_TYPE_REQ                    1450
#define MSG_ID_MMI_SMU_GET_REQUIRED_PIN_TYPE_RSP                    1451
/* micha0202 */
#define PRT_SET_PREFERRED_NETWORKS_REQ    1452
#define PRT_SET_PREFERRED_NETWORKS_RSP 1453
#define PRT_PREFERRED_NETWORKS_REQ     1454
#define PRT_PREFERRED_NETWORKS_REQ_SUCCESS   1455
#define PRT_MMI_CALL_COST_PRICEUNIT_SET_REQ        1456
#define PRT_MMI_CALL_COST_PRICEUNIT_SET_RSP        1457
#define PRT_MMI_CALL_COST_PRICEUNIT_GET_REQ        1458
#define PRT_MMI_CALL_COST_PRICEUNIT_GET_RSP        1459
#define PRT_MMI_SMU_CHANGE_PASSWORD_REQ            1460
#define PRT_MMI_SMU_CHANGE_PASSWORD_RSP            1461
//#define //MSG_ID_MMI_SMU_RESTRICTED_ACCESS_REQ                       1462 
//#define //MSG_ID_MMI_SMU_RESTRICTED_ACCESS_RSP                       1463 
// TODO HW_SET_BARRED_DIAL_REQ                          1464 
// TODO HW_SET_BARRED_DIAL_RES                          1465 
#define MSG_ID_MMI_SMU_WRITE_SIM_REQ                       16044
#define MSG_ID_MMI_SMU_WRITE_SIM_RSP                       16045

/* micha0601 begin */
#define PRT_MMI_SMU_READ_SIM_REQ                       16042
#define PRT_MMI_SMU_READ_SIM_RSP                       16043
/* micha0601 end */

//#define //MSG_ID_MMI_SMU_POWER_OFF_REQ                       1470 
//#define //MSG_ID_MMI_SMU_POWER_OFF_RSP                       1471 
//#define //MSG_ID_MMI_SMU_REMOVE_REQ                       1472 
//#define //MSG_ID_MMI_SMU_REMOVE_RSP                       1473 
#define MSG_ID_GET_PIN_RES             1474
#define PRT_PLMN_LIST_IND              1475
#define MSG_ID_SIM_CARD_FAILURE           1476
/* micha0420 */
#define PRT_MMI_SMU_READ_FILE_INFO_REQ    1477
#define PRT_MMI_SMU_READ_FILE_INFO_RSP    1478
#define PRT_MMI_SMU_CHECK_PIN_STATUS_REQ  1479
#define PRT_MMI_SMU_CHECK_PIN_STATUS_RSP  1480
#define PRT_MMI_SMU_GET_DIAL_MODE_REQ        1381
#define PRT_MMI_SMU_GET_DIAL_MODE_RSP     1382
//#define HW_SET_PHONE_LOCK_RES                         1445
//#define HW_SET_PHONE_LOCK_REQ                         1444
#define PRT_MMI_SMU_SET_DIAL_MODE_REQ     1464
#define PRT_MMI_SMU_SET_DIAL_MODE_RSP     1465
//#define HW_SET_BARRED_DIAL_RES                                1465
//#define HW_SET_BARRED_DIAL_REQ                                1464
#define HW_SET_TIME_FORMAT_REQ            1352
#define HW_SET_DATE_FORMAT_REQ_SUCCESS    1353
#define HW_SET_DATE_FORMAT_REQ            1352

///#define //MSG_ID_MMI_SMU_STARTUP_INFO_IND                       1481 
 //endif(__MOD_SMU__) 

/* ifdef(__MOD_PHB__) */
#define PRT_PHB_STARTUP_PHASE1_FINISH_IND       1481
#define PRT_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ      1494
#define PRT_PHB_STARTUP_READ_ANR_IND        1495
#define PRT_PHB_STARTUP_READ_EMAIL_IND         1496
#define PRT_PHB_STARTUP_READ_GAS_IND        1496
#define PRT_PHB_STARTUP_READ_GRP_IND        1496
#define PRT_PHB_READ_EMAIL_REQ      1496
#define PRT_PHB_READ_EMAIL_RSP      1496
#define PRT_PHB_SET_GRP_REQ      1496
#define PRT_PHB_SET_GRP_RSP      1496
#define PRT_PHB_WRITE_USIM_REQ      1496
#define PRT_PHB_WRITE_USIM_RSP      1496

#define PRT_PHB_GET_ENTRY_BY_NAME_REQ  1482
#define PRT_PHB_GET_ENTRY_BY_NAME_RSP  1483
#define PRT_PHB_GET_ENTRY_BY_INDEX_REQ 1484
#define PRT_PHB_GET_ENTRY_BY_INDEX_RSP 1485
#define PRT_PHB_SET_PREFERRED_STORAGE_REQ 1486
#define PRT_PHB_SET_PREFERRED_STORAGE_RSP 1487
#define PRT_PHB_GET_PREFERRED_STORAGE_REQ 1488
#define PRT_PHB_GET_PREFERRED_STORAGE_RSP 1489
#define PRT_PHB_SET_ENTRY_REQ       1490
#define PRT_PHB_SET_ENTRY_RSP       1491
#define PRT_PHB_DEL_ENTRY_REQ       1492
#define PRT_PHB_DEL_ENTRY_RSP       1493
//#define //MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_REQ                    1494 
//#define //MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_RSP                    1495 
//#define //MSG_ID_MMI_PHB_GET_TYPE_STATUS_REQ                    1496 
//#define //MSG_ID_MMI_PHB_GET_TYPE_STATUS_RSP                    1497 
#define PRT_MMI_PHB_LAST_NUMBER_READY_IND 1497
#define  PRT_MMI_PHB_GET_LAST_NUMBER_REQ     1498
#define  PRT_MMI_PHB_GET_LAST_NUMBER_RSP     1499
#define  PRT_MMI_PHB_SET_LAST_NUMBER_REQ     1500
#define  PRT_MMI_PHB_SET_LAST_NUMBER_RSP     1501
#define  PRT_MMI_PHB_DEL_LAST_NUMBER_REQ     1502
#define  PRT_MMI_PHB_DEL_LAST_NUMBER_RSP     1503
#define  PRT_PHB_GET_ALPHA_LIST_REQ       1506
#define  PRT_PHB_GET_ALPHA_LIST_RSP       1507
#define  PRT_PHB_UPDATE_IND               1508
#define  PRT_PHB_VCARD_REQ_IND            1496
#define PRT_PHB_MEA_ADDR_INPUT_IND     1509     /* For MMS */

#define PRT_PHB_STARTUP_FINISH_IND     1504
//#define //MSG_ID_MMI_PHB_MEM_FULL_IND                    1505 
//endif(__MOD_PHB__) 

/* ifdef(__MOD_SMSAL__) */
#define  PRT_MSG_ID_MMI_SMS_FDN_CHECK_REQ 1505
#define  PRT_MSG_ID_MMI_SMS_FDN_CHECK_RSP 1506

#define  PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ 1507
#define  PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP 1508
#define  PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ 1509
#define  PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP 1510
#define  PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ  1511
#define  PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP  1512
#define  PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ  1513
#define  PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP  1514
#define  PRT_MSG_ID_MMI_SMS_SEND_COMMAND_REQ       1515
#define  PRT_MSG_ID_MMI_SMS_SEND_COMMAND_RSP       1516
#define  PRT_MSG_ID_MMI_SMS_DEL_MSG_REQ               1517
#define  PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP               1518
#define  PRT_MSG_ID_MMI_SMS_GET_MSG_REQ               1519
#define  PRT_MSG_ID_MMI_SMS_GET_MSG_RSP               1520
#define  PRT_MSG_ID_MMI_SMS_SEND_MSG_REQ           1521
#define  PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP           1522
#define  PRT_MSG_ID_MMI_SMS_SET_MSG_REQ               1523
#define  PRT_MSG_ID_MMI_SMS_SET_MSG_RSP               1524
#define  PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ    1525
#define  PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP    1526
#define  PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ 1527
#define  PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP    1528
#define  PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_REQ       1529
#define  PRT_MSG_ID_MMI_SMS_REG_PORT_NUM_RSP       1530
#define  PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND           1531
#define  PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND         1532
#define  PRT_MSG_ID_MMI_SMS_MEM_AVAILABLE_IND         1533
#define  PRT_MSG_ID_MMI_SMS_MEM_EXCEED_IND            1534
#define  PRT_MSG_ID_MMI_SMS_MEM_FULL_IND           1535
#define  PRT_MSG_ID_MMI_SMS_READY_IND              1536
#define  PRT_MSG_ID_MMI_SMS_APP_DATA_IND           1537
#define  PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ        1538
#define  PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP        1539
#define  PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ    1540
#define  PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP    1541
#define  PRT_MSG_ID_MMI_SMS_ABORT_REQ              1542
#define  PRT_MSG_ID_MMI_SMS_ABORT_RSP              1543
#define  PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND      1544
#define  PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND     1545

#define  PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND        1546
#define  PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ   1547
#define  PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP   1548
#define  PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ   1549
#define  PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP   1550
#define  PRT_MSG_ID_MMI_SMS_SYNC_MSG_IND           1551
#define  PRT_MSG_ID_MMI_SMS_STARTUP_BEGIN_IND         1552
#define  PRT_MSG_ID_MMI_SMS_STARTUP_FINISH_IND        1553
#define  PRT_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ     1554
#define  PRT_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP     1555
#define  PRT_MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND      1556

#define  PRT_MSG_ID_MMI_CB_DOWNLOAD_IND      1557
#define  PRT_MSG_ID_MMI_CB_MSG_IND           1558
#define  PRT_MSG_ID_MMI_CB_SUBSCRIBE_REQ     1559
#define  PRT_MSG_ID_MMI_CB_SUBSCRIBE_RSP        1560
#define  PRT_MSG_ID_MMI_SMS_SET_CB_MODE_REQ  1561
#define  PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP  1562
#define  PRT_MSG_ID_MMI_SMS_GET_CB_MODE_REQ  1563
#define  PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP  1564

#define  PRT_MSG_ID_MMI_SMS_COPY_MSG_REQ  1565
#define  PRT_MSG_ID_MMI_SMS_COPY_MSG_RSP  1566

#define PRT_MSG_ID_MMI_SEND_SMS_FROM_STORAGE_REQ    1567
#define PRT_MSG_ID_MMI_SEND_SMS_FROM_STORAGE_RSP    1568
#define PRT_MSG_ID_MMI_SMS_SET_STATUS_REQ           1569
#define PRT_MSG_ID_MMI_SMS_SET_STATUS_RSP           1570

/* endif(__MOD_SMSAL__) */

//MSG_ID_MMI_DF_BACK_DATA_STATE_REQ                    1573 
//MSG_ID_MMI_DF_BACK_DATA_STATE_RSP                    1574 
///ifdef(__SAT__) 

/* micha0601, copy this part to fix indention */
#define PRT_MMI_SAT_DISPLAY_TEXT_IND               1575
#define PRT_MMI_SAT_DISPLAY_TEXT_RES_REQ           1576
#define PRT_MMI_SAT_DISPLAY_TEXT_RES_RSP           1577
#define PRT_MMI_SAT_GET_INKEY_IND                     1578
#define PRT_MMI_SAT_GET_INKEY_RES_REQ              1579
#define PRT_MMI_SAT_GET_INKEY_RES_RSP              1580
#define PRT_MMI_SAT_GET_INPUT_IND                  1581
#define PRT_MMI_SAT_GET_INPUT_RES_REQ              1582
#define PRT_MMI_SAT_GET_INPUT_RES_RSP              1583
#define PRT_MMI_SAT_SETUP_MENU_IND                 1584
#define PRT_MMI_SAT_SETUP_MENU_RES_REQ          1585
#define PRT_MMI_SAT_SETUP_MENU_RES_RSP          1586
#define PRT_MMI_SAT_SELECT_ITEM_IND                1587
#define PRT_MMI_SAT_SELECT_ITEM_RES_REQ            1588
#define PRT_MMI_SAT_SELECT_ITEM_RES_RSP            1589
#define PRT_MMI_SAT_PLAY_TONE_IND                  1590
#define PRT_MMI_SAT_PLAY_TONE_RES_REQ              1591
#define PRT_MMI_SAT_PLAY_TONE_RES_RSP              1592
#define PRT_MMI_SAT_MENU_SELECT_REQ                1593
#define PRT_MMI_SAT_MENU_SELECT_RSP                1594
#define PRT_MMI_SAT_CALL_SETUP_IND                 1595
#define PRT_MMI_SAT_CALL_SETUP_STAGE1_REQ       1596
#define PRT_MMI_SAT_CALL_SETUP_STAGE1_RSP       1597
#define PRT_MMI_SAT_CALL_SETUP_STAGE2_REQ       1598
#define PRT_MMI_SAT_CALL_SETUP_STAGE2_RSP       1599
#define PRT_MMI_SAT_SEND_SMS_IND                   1600
#define PRT_MMI_SAT_SEND_SMS_STAGE1_REQ            1601
#define PRT_MMI_SAT_SEND_SMS_STAGE1_RSP            1602
#define PRT_MMI_SAT_SEND_SMS_STAGE2_REQ            1603
#define PRT_MMI_SAT_SEND_SMS_STAGE2_RSP            1604
#define PRT_MMI_SAT_SEND_SS_IND                    1605
#define PRT_MMI_SAT_SEND_SS_STAGE1_REQ          1606
#define PRT_MMI_SAT_SEND_SS_STAGE1_RSP          1607
#define PRT_MMI_SAT_SEND_SS_STAGE2_REQ          1608
#define PRT_MMI_SAT_SEND_SS_STAGE2_RSP             1609
#define PRT_MMI_SAT_SEND_USSD_IND                  1610
#define PRT_MMI_SAT_SEND_USSD_STAGE1_REQ           1611
#define PRT_MMI_SAT_SEND_USSD_STAGE1_RSP           1612
#define PRT_MMI_SAT_SEND_USSD_STAGE2_REQ           1613
#define PRT_MMI_SAT_SEND_USSD_STAGE2_RSP           1614
#define PRT_MMI_SAT_MMI_INFO_IND                   1615
#define PRT_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ     1616
#define PRT_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP     1617
#define PRT_MMI_SAT_SETUP_IDLE_DISPLAY_IND         1618
#define PRT_MMI_SAT_RUN_AT_COMMAND_RES_REQ         1619
#define PRT_MMI_SAT_RUN_AT_COMMAND_RES_RSP         1620
#define PRT_MMI_SAT_RUN_AT_COMMAND_IND          1621
#define PRT_MMI_SAT_SEND_DTMF_RES_REQ              1622
#define PRT_MMI_SAT_SEND_DTMF_RES_RSP              1623
#define PRT_MMI_SAT_SEND_DTMF_IND                  1624
#define PRT_MMI_SAT_LANG_NOTIFY_RES_REQ            1625
#define PRT_MMI_SAT_LANG_NOTIFY_RES_RSP            1626
#define PRT_MMI_SAT_LANG_NOTIFY_IND                1627
#define PRT_MMI_SAT_LAUNCH_BROWSER_RES_REQ         1628
#define PRT_MMI_SAT_LAUNCH_BROWSER_RES_RSP         1629
#define PRT_MMI_SAT_LAUNCH_BROWSER_IND          1630
#define PRT_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ    7001
#define PRT_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP    7002
#define PRT_MMI_SAT_LANGUAGE_SELECTION_REQ               7003
#define PRT_MMI_SAT_LANGUAGE_SELECTION_RSP               7004
#define PRT_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ      7005
#define PRT_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP      7006
#define PRT_WAP_MMI_BROWSER_TERMINATION_IND           7007
#define PRT_WAP_MMI_LAUNCH_BROWSER_REQ                7008
#define PRT_WAP_MMI_LAUNCH_BROWSER_RSP                7009
#define PRT_MMI_SAT_SEND_DTMF_STAGE1_REQ              7010
#define PRT_MMI_SAT_SEND_DTMF_STAGE1_RSP                 7011
#define PRT_MMI_SAT_SEND_DTMF_STAGE2_REQ              7012
#define PRT_MMI_SAT_SEND_DTMF_STAGE2_RSP                 7013
#define PRT_MMI_SAT_ABORT_DTMF_REQ                       7014

#ifdef __SATCE__
#define MSG_ID_MMI_SAT_OPEN_CHANNEL_IND               7015
#define MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ               7016
#define MSG_ID_MMI_SAT_OPEN_CHANNEL_RSP               7017
#define MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND           7018
#define MSG_ID_MMI_SAT_SEND_DATA_IND               7019
#define MSG_ID_MMI_SAT_SEND_DATA_REQ               7020
#define MSG_ID_MMI_SAT_SEND_DATA_RSP               7021
#define MSG_ID_MMI_SAT_RECV_DATA_IND               7022
#define MSG_ID_MMI_SAT_RECV_DATA_REQ               7023
#define MSG_ID_MMI_SAT_RECV_DATA_RSP               7024
#endif /* __SATCE__ */ 

/* micha0714 */
#define  PRT_MMI_SAT_NO_OTHER_CMD_IND              7025

/* micha0201 */
#define  PRT_MMI_SAT_SIM_FILE_CHANGE_IND           7026

// #endif(__SAT__)

/* ifdef(__MOD_UEM__) */

#define MSG_ID_EM_SET_GAIN_REQ           1639
#define MSG_ID_EM_SET_GAIN_RSP           1640
/* endif(__MOD_UEM__) */

// #ifdef __MMI_ENGINEER_MODE__

#define MSG_ID_EM_STATUS_IND             1641
#define MSG_ID_EM_START_REQ              1642
#define MSG_ID_EM_START_RSP              1643
#define MSG_ID_EM_STOP_REQ               1644
#define MSG_ID_EM_STOP_RSP               1645
/* endif(__MMI_ENGINEER_MODE__) */

// #ifdef(__FS_ON__)

#define MSG_ID_VM_RECORD_REQ               1646
#define MSG_ID_VM_RECORD_RSP               1647
#define MSG_ID_VM_PLAY_REQ               1648
#define MSG_ID_VM_PLAY_RSP               1649
#define MSG_ID_VM_STOP_REQ               1650
#define MSG_ID_VM_STOP_RSP               1651
#define MSG_ID_VM_DEL_REQ               1652
#define MSG_ID_VM_DEL_RSP               1653
#define MSG_ID_VM_ABORT_REQ               1654
#define MSG_ID_VM_ABORT_RSP               1655
#define MSG_ID_VM_PAUSE_REQ               1656
#define MSG_ID_VM_PAUSE_RSP               1657
#define MSG_ID_VM_RESUME_REQ               1658
#define MSG_ID_VM_RESUME_RSP               1659
#define MSG_ID_VM_APPEND_REQ               1660
#define MSG_ID_VM_APPEND_RSP               1661
#define MSG_ID_VM_GET_INFO_REQ               1662
#define MSG_ID_VM_GET_INFO_RSP               1663
#define MSG_ID_VM_RECORD_FINISH_IND          1664
#define MSG_ID_VM_PLAY_FINISH_IND             1665
// #endif(__CB__)

#define PRT_MSG_ID_MMI_CPHS_DISPLAY_CFU_IND          1675
#define PRT_MSG_ID_MMI_CPHS_MMI_INFO_IND          1676
/* micha0309 */
#define PRT_MMI_CPHS_DISPLAY_ALS_IND 1677
#define PRT_MSG_ID_MMI_CC_SYNC_TABLE_REQ_IND 1678
//MSG_ID_WAP_START_DTMF_REQ                1677 
//MSG_ID_WAP_START_DTMF_RSP                1678 
//MSG_ID_WAP_STOP_DTMF_REQ                 1679 
//MSG_ID_WAP_STOP_DTMF_RSP                 1680 
//MSG_ID_WAP_DIAL_REQ                      1681 
//MSG_ID_WAP_DIAL_RSP                      1682 
//MSG_ID_WAP_SET_ENTRY_REQ                 1683 
//MSG_ID_WAP_SET_ENTRY_RSP                 1684 
//MSG_ID_L4A_CODE_END                      1685 
#define PRT_MSG_ID_MMI_NW_TIME_ZONE_IND 1439
#define  PRT_MSG_ID_MMI_EQ_VOLUME_CHANGE_IND 1700
#define  PRT_MMI_EQ_MUTE_CHANGE_IND   1701
/* duplicated!!! #define        PRT_MMI_EQ_SET_SILENT_MODE_REQ_IND 1702 */
#define  PRT_MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND 1703
#define  PRT_MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND 1704
#define  PRT_MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND 1705
#define  PRT_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND 1706
#define  PRT_MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_IND 1707
#define  PRT_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND 1708
#define  PRT_MMI_EQ_SET_GREETING_TEXT_REQ_IND 1709
#define  PRT_MSG_ID_MMI_CC_DIAL_REQ_IND 1710
#define  PRT_MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND 1711
#define  PRT_MSG_ID_MMI_CC_CALL_ABORT_REQ_IND 1712
#define  PRT_MMI_EQ_SET_LANGUAGE_REQ_IND 1713
#define  PRT_MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ 1714
#define PRT_MMI_EQ_SET_DATE_TIME_FORMAT_RSP 1722
#define PRT_MMI_EQ_SET_DATE_TIME_FORMAT_REQ 1723

#define PRT_MMI_SET_MMI_DEFAULT_PROF_IND 1724

#define PRT_SMU_STARTUP_INFO_IND          1715
#define PRT_MSG_ID_MMI_EQ_SET_LANGUAGE_REQ      1716
#define PRT_NW_SET_ATTACH_RSP             1717
#define PRT_POWER_OFF_RSP                 1718
#define PRT_POWER_OFF_REQ                 1719
#define PRT_NW_SET_ATTACH_REQ             1720
#define PRT_EQ_POWER_ON_REQ                  1721
#ifdef __MMI_USB_SUPPORT__
#define PRT_EQ_USB_DETECT_IND                 1725
#define PRT_EQ_USBCONFIG_RSP              1726
#define PRT_EQ_USBUART_SWITCH_PORT_REQ     1727
#define PRT_EQ_USBUART_SWITCH_PORT_RSP     1728
#define PRT_EQ_USB_POWER_ON_FINISH_IND    3300
#endif /* __MMI_USB_SUPPORT__ */ 

#define PRT_MMI_EQ_QUERY_GREETING_TEXT_REQ_IND      1729
#define PRT_MMI_EQ_QUERY_LANGUAGE_REQ_IND           1730
#define PRT_MMI_EQ_QUERY_SILENT_MODE_REQ_IND        1731
#define PRT_MMI_EQ_QUERY_VIBRATOR_MODE_REQ_IND      1732
#define PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND   1733
#define PRT_MMI_EQ_QUERY_MUTE_MODE_REQ_IND          1734

#define PRT_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ      1735
#define PRT_MMI_EQ_QUERY_LANGUAGE_RES_REQ           1736
#define PRT_MMI_EQ_QUERY_SILENT_MODE_RES_REQ        1737
#define PRT_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ      1738
#define PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ   1739
#define PRT_MMI_EQ_QUERY_MUTE_MODE_RES_REQ          1740

/******************** E-mail ************************/
/******************** E-mail ************************/

#ifdef __MMI_EMAIL__    /* Changes for email */

#define PRT_MMI_EMAIL_LIST_FOLDERS_REQ 1741
#define PRT_MMI_EMAIL_LIST_FOLDERS_RSP 1742

#define PRT_MMI_EMAIL_SEND_RECV_REQ    1743
#define PRT_MMI_EMAIL_SEND_RECV_RSP    1744
#define PRT_MMI_EMAIL_SERVER_CONNECT_IND  1745
#define PRT_MMI_EMAIL_MSG_SENT_IND     1746
#define PRT_MMI_EMAIL_NUM_MSGS_SENT_IND   1747
#define PRT_MMI_EMAIL_AUTHVERIFY_IND      1748
#define PRT_MMI_EMAIL_RECV_MSGS_IND    1749
#define PRT_MMI_EMAIL_NEW_MSGS_IND     1750

#define PRT_MMI_EMAIL_ABORT_REQ        1751
#define PRT_MMI_EMAIL_ABORT_RSP        1752

#define PRT_MMI_EMAIL_SEND_ONLY_REQ    1753
#define PRT_MMI_EMAIL_SEND_ONLY_RSP    1754

#define PRT_MMI_EMAIL_SAVE_DRAFTS_REQ     1755
#define PRT_MMI_EMAIL_SAVE_DRAFTS_RSP     1756

#define PRT_MMI_EMAIL_SEND_NOW_REQ     1757
#define PRT_MMI_EMAIL_SEND_NOW_RSP     1758

#define PRT_MMI_EMAIL_LIST_ACCT_PROFILE_REQ  1759
#define PRT_MMI_EMAIL_LIST_ACCT_PROFILE_RSP  1760
#define PRT_MMI_EMAIL_SET_ACCT_PROFILE_REQ   1761
#define PRT_MMI_EMAIL_SET_ACCT_PROFILE_RSP   1762
#define PRT_MMI_EMAIL_GET_ACCT_PROFILE_REQ   1763
#define PRT_MMI_EMAIL_GET_ACCT_PROFILE_RSP   1764
#define PRT_MMI_EMAIL_ACTIVATE_ACCT_REQ      1765
#define PRT_MMI_EMAIL_ACTIVATE_ACCT_RSP      1766
#define PRT_MMI_EMAIL_DELETE_ACCT_REQ        1767
#define PRT_MMI_EMAIL_DELETE_ACCT_RSP        1768

#define PRT_MMI_EMAIL_RECV_MAILS_IND         1769

#define PRT_MMI_EMAIL_FOLDER_SELECT_REQ      1770
#define PRT_MMI_EMAIL_FOLDER_SELECT_RSP      1771

#define PRT_MMI_EMAIL_FOLDER_MSG_SELECT_REQ  1772
#define PRT_MMI_EMAIL_FOLDER_MSG_SELECT_RSP  1773

#define PRT_MMI_EMAIL_FOLDER_MSG_DELETE_REQ  1774
#define PRT_MMI_EMAIL_FOLDER_MSG_DELETE_RSP  1775

#define PRT_MMI_EMAIL_MSG_MOVE_REQ        1776
#define PRT_MMI_EMAIL_MSG_MOVE_RSP        1777
#define PRT_MMI_EMAIL_PARTIAL_FETCH_REQ      1778
#define PRT_MMI_EMAIL_PARTIAL_FETCH_RSP      1779
#define PRT_MMI_EMAIL_SEARCH_REQ          1780
#define PRT_MMI_EMAIL_SEARCH_RSP          1781
#define PRT_MMI_EMAIL_SEARCH_LIST_REQ        1782
#define PRT_MMI_EMAIL_SEARCH_LIST_RSP        1783
#define PRT_MMI_EMAIL_SEND_REQ            1784
#define PRT_MMI_EMAIL_SEND_RSP            1785

#define PRT_MMI_EMAIL_ERR_IND             1786
#define PRT_MMI_EMAIL_START_REQ           1787
#define PRT_MMI_EMAIL_START_RSP           1788
#define PRT_MMI_EMAIL_STOP_REQ            1789
#define PRT_MMI_EMAIL_STOP_RSP            1790
#define PRT_MMI_EMAIL_AUTOCHECK_EXPIRY_IND   1791

#define PRT_MMI_EMAIL_INIT_REQ            1792
#define PRT_MMI_EMAIL_INIT_RSP            1793
/* __USB_IN_NORMAL_MODE__ */
#define PRT_MMI_EMAIL_DEINIT_REQ       1801
#define PRT_MMI_EMAIL_DEINIT_RSP       1802

#define PRT_MMI_EMAIL_BEARER_INFO_IND        1794
#define PRT_MMI_EMAIL_DEACTIVATE_REQ         1795
#define PRT_MMI_EMAIL_DEACTIVATE_RSP         1796

#define PRT_MMI_EMAIL_MSG_FULL_IND        1797
#define PRT_MMI_EMAIL_MSG_AVAILABLE_IND      1798

#define PRT_MMI_EMAIL_SEND_FROM_MAILBOX_REQ  1799
#define PRT_MMI_EMAIL_SEND_FROM_MAILBOX_RSP  1800

#define PRT_MMI_EMAIL_COMPOSE_SIZE_REQ       1803
#define PRT_MMI_EMAIL_COMPOSE_SIZE_RSP       1804

#define PRT_MMI_EMAIL_SET_MODE_REQ           1807
#define PRT_MMI_EMAIL_SET_MODE_RSP           1808
#define PRT_MMI_EMAIL_UIDL_FULL_IND          1809
#define PRT_MMI_EMAIL_FOLDER_MSG_SET_FLAG_REQ  1810
#define PRT_MMI_EMAIL_FOLDER_MSG_SET_FLAG_RSP  1811

#endif /* __MMI_EMAIL__ */ /* def __MMI_EMAIL__      // Changes for email */

 /******************** E-mail ************************/
 /******************** E-mail ************************/

#define  PRT_MMI_EQ_SET_LANGUAGE_REQ               1801 /* Send to AT when language change */

#ifdef __TCPIP__
#define PRT_MMI_CC_SET_CSD_PROFILE_REQ   3001
#define PRT_MMI_CC_SET_CSD_PROFILE_RSP   3002
#define PRT_MMI_CC_GET_CSD_PROFILE_REQ   3003
#define PRT_MMI_CC_GET_CSD_PROFILE_RSP   3004
/* micha0308 */
#ifdef __MMI_GPRS_FEATURES__
#define PRT_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ 3005
#define PRT_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP 3006
#define PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ 3007
#define PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP 3008
#endif /* __MMI_GPRS_FEATURES__ */ 
#endif /* __TCPIP__ */ 

/* micha0308 */
#ifdef __MMI_GPRS_FEATURES__
#define PRT_NW_GET_GPRS_CONNECT_TYPE_REQ  3009
#define PRT_NW_GET_GPRS_CONNECT_TYPE_RSP  3010
#define PRT_NW_SET_GPRS_CONNECT_TYPE_REQ  3011
#define PRT_NW_SET_GPRS_CONNECT_TYPE_RSP  3012
#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef __PS_SERVICE__
#define PRT_EVENT_CC_GET_GPRS_PROFILE_REQ   3013
#define PRT_EVENT_CC_GET_GPRS_PROFILE_RSP   3014
#endif /* __PS_SERVICE__ */ 

#ifdef __MMI_FILE_MANAGER__
#define PRT_MMI_FMGR_COPY_REQ 3015
#define PRT_MMI_FMGR_COPY_RSP 3016
#define PRT_MMI_FMGR_FORMAT_REQ 3017
#define PRT_MMI_FMGR_FORMAT_RSP 3018
#define PRT_MMI_FMGR_UNMOUNT_REQ 3019
#define PRT_MMI_FMGR_UNMOUNT_RSP 3020
#define PRT_MMI_FMGR_DELETE_REQ 3021
#define PRT_MMI_FMGR_DELETE_RSP 3022
#define PRT_MMI_FMGR_CARD_PLUG_IN_IND  3023
#define PRT_MMI_FMGR_CARD_PLUG_OUT_IND 3024
#define PRT_MMI_FMGR_CHECK_DRIVE_REQ 3025
#define PRT_MMI_FMGR_CHECK_DRIVE_RSP 3026
#define PRT_MMI_FMGR_OTG_DISPLAY_IND      3035
#endif /* __MMI_FILE_MANAGER__ */ 

/* micha1020 */
#ifdef __MMI_GPRS_FEATURES__
#define PRT_MMI_PS_GPRS_STATUS_UPDATE_IND 3027
#define PRT_MMI_PS_GET_GPRS_DATA_COUNTER_REQ 3028
#define PRT_MMI_PS_GET_GPRS_DATA_COUNTER_RSP 3029
#define PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ  3030
#define PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP  3031
#endif /* __MMI_GPRS_FEATURES__ */ 

/* micha1228 */
#define PRT_MMI_SS_EMLPP_RSP  3032

#ifdef WIN_SOC
#define MSG_ID_APP_SOC_NOTIFY_IND           3200
#define MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND 3201
#define MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND 3202
#define MSG_ID_APP_SOC_BEARER_INFO_IND      3203
#define MSG_ID_APP_SOC_DEACTIVATE_CNF       3204
#define MSG_ID_APP_SOC_DEACTIVATE_REQ       3205
#endif /* WIN_SOC */ 

/* Cylen: add for AT command restore Factory default */
#define PRT_MMI_FACTORY_RESTORE_REQ_IND   4000

#ifdef _NETWORK_CIPHER_SUPPORT_ /* Cylen: add for GSM/GPRS ciphering indication */
#define PRT_MMI_SMU_CIPHER_IND   4001
#endif 

/* micha_POC */
#define PRT_POC_REGISTER_REQ     5001
#define PRT_POC_REGISTER_RSP     5002
#define PRT_POC_REGISTER_IND     5003   /* Always */
#define PRT_POC_SETTING_REQ      5004
#define PRT_POC_SETTING_RSP      5005
#define PRT_POC_TALK_INVITE_REQ     5006
#define PRT_POC_TALK_INVITE_RSP        5007
#define PRT_POC_TALK_PROGRESS_IND      5008
#define PRT_POC_TALK_DISCONNECT_REQ 5009
#define PRT_POC_TALK_DISCONNECT_RSP 5010
#define PRT_POC_TALK_CONNECT_IND    5011        /* Always */
#define PRT_POC_TALK_RING_IND       5012
#define PRT_POC_TALK_ANSWER_REQ     5013
#define PRT_POC_TALK_ANSWER_RSP     5014
#define PRT_POC_TALK_DISCONNECT_IND 5015        /* Always */
#define PRT_POC_FLOOR_GRANT_IND     5016
#define PRT_POC_FLOOR_DENY_IND         5017
#define PRT_POC_FLOOR_TAKEN_IND     5018
#define PRT_POC_FLOOR_TAKE_REQ         5019
#define PRT_POC_FLOOR_RELEASE_REQ      5020
#define PRT_POC_FLOOR_IDLE_IND         5021
#define PRT_POC_FLOOR_REVOKE_IND    5022
#define PRT_POC_MEDIA_START_ENCODE_REQ 5023
#define PRT_POC_MEDIA_START_ENCODE_RSP 5024
#define PRT_POC_MEDIA_STOP_ENCODE_REQ     5025
#define PRT_POC_MEDIA_STOP_ENCODE_RSP     5026
#define PRT_POC_MEDIA_START_DECODE_REQ 5027
#define PRT_POC_MEDIA_START_DECODE_RSP 5028
#define PRT_POC_MEDIA_STOP_DECODE_REQ     5029
#define PRT_POC_MEDIA_STOP_DECODE_RSP     5030

#ifdef __FLIGHT_MODE_SUPPORT__
#define PRT_NW_CFUN_STATE_REQ       5201
#define PRT_NW_CFUN_STATE_RSP       5202
#endif /* __FLIGHT_MODE_SUPPORT__ */ 

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 

#ifdef __HOMEZONE_SUPPORT__
#define PRT_MMI_HZ_TAG_IND       5207
#endif 

#ifdef __MMI_SML_MENU__
#define PRT_MMI_SMU_SET_PERSONALIZATION_REQ 5211
#define PRT_MMI_SMU_SET_PERSONALIZATION_RSP 5212
#define PRT_MMI_SMU_SML_STATUS_REQ 5213
#define PRT_MMI_SMU_SML_STATUS_RSP 5214
#endif /* __MMI_SML_MENU__ */

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define  MSG_ID_MMI_THM_CONTENT_RCVD            5051
#define MSG_ID_DA_GET_CONTENT_REQ            5052
#define MSG_ID_DA_CONTINUE_DOWNLOAD          5053
#define MSG_ID_MMI_DOWNLOAD_RES              5054
#define  MSG_ID_MMI_DOWNLOAD_COMPLETE_NOTIFY    5055
#define  MSG_ID_DA_ABORT_REQ                 5056
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
#define  PRT_MSG_ID_MMI_UM_READY_IND         2001
#define  PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ   2002
#define  PRT_MSG_ID_MMI_UM_GET_MSG_NUM_RSP      2003
#define  PRT_MSG_ID_MMI_UM_GET_LIST_REQ         2004
#define  PRT_MSG_ID_MMI_UM_GET_LIST_RSP         2005
#define  PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ  2006
#define  PRT_MSG_ID_MMI_UM_GET_MSG_INFO_RSP  2007
#define  PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ 2008
#define  PRT_MSG_ID_MMI_UM_DELETE_FOLDER_RSP 2009
#define  PRT_MSG_ID_MMI_UM_NEW_MSG_IND          2010
#define  PRT_MSG_ID_MMI_UM_DELETE_ALL_IND    2011
#define  PRT_MSG_ID_MMI_UM_DELETE_ALL_RES    2012
#define  PRT_MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND 2013
#define  PRT_MSG_ID_MMI_UM_REFRESH_IND       2014
#define  PRT_MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND       2015
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#define  PRT_MMI_MAKE_CALL_REQ_IND	2501

#endif /* MMI_ON_WIN32 */ 

#endif /* _PIXCOM_PROTOCOL_EVENT_H */ 

