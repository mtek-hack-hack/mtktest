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
 *  UCMCallProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_CALL_PROT_H
#define UCM_CALL_PROT_H

/*
#ifndef _FILE_MGR_H_
#error "Please include FileMgr.h first"
#endif
*/

#include "custom_mmi_default_value.h" /* for MAX_PB_NAME_LENGTH */
#include "FileMgr.h"   /* for FMGR_MAX_PATH_LEN */
#include "GlobalConstants.h" /* for MAX_SUB_MENU_SIZE */
#include "PhoneBookTypes.h" /* for mmi_phb_caller_image_input_struct */

#define MMI_UCM_MAX_NUM_CALL                    (8)

#define MMI_UCM_MAX_DISP_NAME_LEN               (MAX_SUBMENU_CHARACTERS)
#define MMI_UCM_MAX_NUM_URI_LEN                 (65)
#define MMI_UCM_MAX_AUTO_REDIAL_MSG_LEN         (100)

#define MMI_UCM_INVALID_ID                      (255)
#define MMI_UCM_MAX_IP_NUMBER_LEN               (10)

typedef enum
{
    MMI_UCM_IDLE_STATE = 0,
    MMI_UCM_OUTGOING_STATE,
    MMI_UCM_INCOMING_STATE,
    MMI_UCM_ACTIVE_STATE,
    MMI_UCM_HOLD_STATE,
    MMI_UCM_CALL_STATE_TOTAL
} mmi_ucm_call_state_enum;

typedef enum
{
    MMI_UCM_DISP_OUTGOING = 0x01,
    MMI_UCM_DISP_INCOMING = 0x02,
    MMI_UCM_DISP_CONDITION_TOTAL
} mmi_ucm_disp_condition_enum;

typedef enum
{
    MMI_UCM_IDLE = 0,
    MMI_UCM_DIAL,
    MMI_UCM_HOLD_AND_DIAL,
    MMI_UCM_ACCEPT,
    MMI_UCM_HOLD_AND_ACCEPT,
    MMI_UCM_HOLD,
    MMI_UCM_RETRIEVE,
    MMI_UCM_SWAP,
    MMI_UCM_CONFERENCE,
    MMI_UCM_SPLIT,
    MMI_UCM_DEFLECT,
    MMI_UCM_TRANSFER,
    MMI_UCM_END_SINGLE,
    MMI_UCM_END_CONFERENCE,
    MMI_UCM_END_ALL,
    MMI_UCM_FORCE_RELEASE,
    MMI_UCM_AUTO_REJECT,
    MMI_UCM_EXPLICT_CALL_TRANSFER,
    MMI_UCM_END_ACTIVE_AND_RETRIEVE,
    MMI_UCM_END_ACTIVE_AND_ACCEPT,
    MMI_UCM_PROCESSING,
    MMI_UCM_START_DTMF,
    MMI_UCM_STOP_DTMF,
    MMI_UCM_ACT_OPCODE_TOTAL
} mmi_ucm_act_opcode_enum;

typedef enum
{
    MMI_UCM_SYNC_CALL_LIST = 0,
    MMI_UCM_ALERT_IND,
    MMI_UCM_CONNECT_IND,
    MMI_UCM_NOTIFY_IND,
    MMI_UCM_SESSION_IND,
    MMI_UCM_SPEECH_IND,
    MMI_UCM_DIAL_REQ_IND,
    MMI_UCM_RING_IND,
    MMI_UCM_RELEASE_IND,
    MMI_UCM_CALL_COST_IND,
    MMI_UCM_AUTO_REDIAL_IND,
    MMI_UCM_START_PROCESSING_IND,
    MMI_UCM_STOP_PROCESSING_IND,
    MMI_UCM_ANSWER_REQ_IND,
    MMI_UCM_IND_OPCODE_TOTAL
} mmi_ucm_ind_opcode_enum;

typedef enum
{
    MMI_UCM_DISPLAY_CNF = 0,
    MMI_UCM_CANCEL_CNF,
    MMI_UCM_CNF_OPCODE_TOTAL
} mmi_ucm_cnf_opcode_enum;

typedef struct
{
    mmi_ucm_call_type_enum call_type;
    S16 group_id;
    S16 call_id;
} mmi_ucm_id_info_struct;

typedef struct
{
    U16 log_name[MAX_PB_NAME_LENGTH + 1];
    U16 disp_name[MMI_UCM_MAX_DISP_NAME_LEN];
    U8 num_uri[MMI_UCM_MAX_NUM_URI_LEN];
    U16 active_icon;
} mmi_ucm_remote_info_struct;

typedef struct
{
    U8 dial_pad_buffer[MMI_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH];
    mmi_ucm_module_origin_enum module_id;
    mmi_ucm_call_type_enum dial_type;
    mmi_ucm_remote_info_struct dial_num;
    MMI_BOOL is_wait_dial;
    mmi_ucm_callback_func_ptr callback;
    void* callback_para;
} mmi_ucm_dial_info_struct;

typedef struct
{
    U16 tone_path[FMGR_MAX_PATH_LEN + 1];
    U16 image_path[FMGR_MAX_PATH_LEN + 1];
    U16 ip_num[MMI_UCM_MAX_IP_NUMBER_LEN + 1];
    U16 tone_id; /* 0 if tone is from file */
    mmi_phb_caller_image_input_struct image_info;
    U16 line_icon; /* line icon image id or 0 */ 
    U8 alert_type;
    U16 light_id;
} mmi_ucm_ring_info_struct;

typedef struct
{
    l4c_source_id_enum l4c_source;
    U8 l4c_type;
    l4c_number_struct l4c_number;
} mmi_ucm_l4c_info_struct;

typedef struct
{
    mmi_ucm_id_info_struct uid_info;
    mmi_ucm_remote_info_struct remote_info;
    mmi_ucm_call_state_enum call_state;
} mmi_ucm_call_info_struct;

typedef struct
{
    U8 result;
    U8 *error_msg;
} mmi_ucm_result_info_struct;

typedef struct
{
    l4c_source_id_enum source_id;
    mmi_ucm_id_info_struct action_uid;
} mmi_ucm_single_call_struct;

typedef struct
{
    l4c_source_id_enum source_id;
    mmi_ucm_id_info_struct active_uid;
    mmi_ucm_id_info_struct other_uid;
} mmi_ucm_multiple_call_struct;

typedef struct
{
    l4c_source_id_enum source_id; /*bypass to L4C*/
    mmi_ucm_module_origin_enum module_id; /*action initiate module*/
    U8 num_uri[MMI_UCM_MAX_NUM_URI_LEN];
} mmi_ucm_dial_req_struct;

typedef struct
{
    l4c_source_id_enum source_id; /*bypass to L4C*/
    mmi_ucm_module_origin_enum module_id; /*action initiate module*/
    mmi_ucm_id_info_struct held_uid;
    U8 num_uri[MMI_UCM_MAX_NUM_URI_LEN];
} mmi_ucm_hold_n_dial_req_struct;

typedef struct
{
    l4c_source_id_enum source_id;
    S16 active_group;
    S16 held_group;
} mmi_ucm_conf_req_struct;

typedef struct
{
    l4c_source_id_enum source_id;
    S16 active_group;
    S16 split_call;
} mmi_ucm_split_req_struct;

typedef struct
{
    l4c_source_id_enum source_id;
    mmi_ucm_id_info_struct action_uid;
    U8 num_uri[MMI_UCM_MAX_NUM_URI_LEN];
} mmi_ucm_cd_or_ct_req_struct;

typedef struct
{
    l4c_source_id_enum source_id;
    S16 action_group;
} mmi_ucm_end_conf_req_struct;

typedef struct
{
    l4c_source_id_enum source_id;
} mmi_ucm_end_all_req_struct;

typedef struct
{
    mmi_ucm_call_info_struct call_info[MMI_UCM_MAX_NUM_CALL];    
    mmi_ucm_call_type_enum call_type;
    U8 total_num;
} mmi_ucm_sync_call_list_struct;

typedef struct
{
    mmi_ucm_result_info_struct result_info;
    mmi_ucm_remote_info_struct remote_info;
    mmi_ucm_ring_info_struct alert_info;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_dial_act_rsp_struct;

typedef struct
{
    mmi_ucm_result_info_struct result_info;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_act_rsp_struct;

typedef struct
{
    mmi_ucm_call_type_enum call_type;
    U8 local_gen;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_alert_ind_struct;

typedef struct
{
    mmi_ucm_id_info_struct uid_info;
    mmi_ucm_remote_info_struct remote_info;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_connect_ind_struct;

typedef struct
{
    mmi_ucm_call_type_enum call_type;
    U8 *disp_msg;
    U16 image_id;
    U16 tone_id;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_notify_ind_struct;

typedef struct
{
    U8 session_type; /* 2G or 3G voice call handover */
    U8 session_switch;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_session_ind_struct;

typedef struct
{
    mmi_ucm_call_type_enum call_type;
    U8 session_type; /* 2G or 3G voice call handover */
    U8 rtp_handle;
    U8 local_switch;
    U8 remote_switch;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_speech_ind_struct;

typedef struct
{
    mmi_ucm_id_info_struct uid_info;
    mmi_ucm_remote_info_struct display_info;
    mmi_ucm_ring_info_struct alert_info;
    mmi_ucm_l4c_info_struct l4c_info;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_ring_ind_struct;

typedef struct
{
    mmi_ucm_id_info_struct uid_info;
    U8 *disp_msg;
    U16 image_id;
    U16 tone_id;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_release_ind_struct;

typedef struct
{
    mmi_ucm_id_info_struct uid_info;
    mmi_ucm_sync_call_list_struct *call_list;
} mmi_ucm_answer_req_ind_struct;

typedef struct
{
    mmi_ucm_id_info_struct uid_info;
    PU8 symbol;
    PU8 cost;
} mmi_ucm_call_cost_struct;

typedef struct
{
    mmi_ucm_call_type_enum call_type;
    U16 display_msg[MMI_UCM_MAX_AUTO_REDIAL_MSG_LEN]; /* UCS2 */
    U8 num_uri[MMI_UCM_MAX_NUM_URI_LEN];
    U8 attempt;
    U8 time; /* in seconds */
    FuncPtr abort_hdlr;
} mmi_ucm_auto_redial_struct;

typedef struct
{
    mmi_ucm_id_info_struct uid_info;
    U8 *content;
} mmi_ucm_start_processing_struct;

typedef struct
{
    U8 *disp_msg;
    U16 image_id;
    U16 tone_id;
} mmi_ucm_stop_processing_struct;

typedef struct
{
    mmi_ucm_disp_condition_enum disp_condition;
    U8 *content;
    U16 lsk_str;
    U16 rsk_str;
    FuncPtr lsk_hdlr;
    FuncPtr rsk_hdlr;
    FuncPtr send_hdlr;
    FuncPtr end_hdlr;
    FuncPtr cancel_hdlr; /* callback while the confirm screen is deleted in history. */
} mmi_ucm_display_cnf_struct;

typedef struct
{
    U16 digit;
    mmi_ucm_call_type_enum call_type;
} mmi_ucm_dtmf_struct;


/* UCMActHdlr.c */
extern void mmi_ucm_pre_send_req(mmi_ucm_act_opcode_enum op_code, mmi_ucm_id_info_struct *first_ptr, mmi_ucm_id_info_struct *other_ptr, mmi_ucm_dial_info_struct *dial_ptr);
extern void mmi_ucm_send_req(mmi_ucm_act_opcode_enum op_code, mmi_ucm_call_type_enum call_type, void *act_struct);

extern void mmi_ucm_dispatch_rsp(mmi_ucm_act_opcode_enum op_code, mmi_ucm_call_type_enum call_type, void *act_struct);
extern void mmi_ucm_dial_act_rsp(void *act_struct);
extern void mmi_ucm_accept_act_rsp(void *act_struct);
extern void mmi_ucm_end_act_rsp(void *act_struct);
extern void mmi_ucm_act_rsp(void *act_struct);

extern void mmi_ucm_dispatch_ind(mmi_ucm_ind_opcode_enum op_code, void *act_struct);
extern void mmi_ucm_sync_call_list(void *act_struct);
extern void mmi_ucm_alert_ind(void *act_struct);
extern void mmi_ucm_connect_ind(void *act_struct);
extern void mmi_ucm_notify_ind(void *act_struct);
extern void mmi_ucm_session_ind(void *act_struct);
extern void mmi_ucm_speech_ind(void *act_struct);
extern void mmi_ucm_dial_req_ind(void *act_struct);
extern void mmi_ucm_ring_ind(void *act_struct);
extern void mmi_ucm_release_ind(void *act_struct);
extern void mmi_ucm_call_cost_ind(void *act_struct);
extern void mmi_ucm_auto_redial_ind(void *act_struct);
extern void mmi_ucm_start_processing_ind(void *act_struct);
extern void mmi_ucm_stop_processing_ind(void *act_struct);
extern void mmi_ucm_answer_req_ind(void *act_struct);

extern MMI_BOOL mmi_ucm_dispatch_cnf(mmi_ucm_cnf_opcode_enum op_code, void *act_struct);
extern void mmi_ucm_display_cnf(void *act_struct);
extern void mmi_ucm_cancel_cnf(void *act_struct);
extern void mmi_ucm_master_at_req_ind(void *inMsg);
extern void mmi_ucm_slave_at_req_ind(void *inMsg);
extern void mmi_ucm_at_req_ind(mmi_ucm_module_origin_enum moduleId, void *inMsg);
extern void mmi_ucm_at_res_req(mmi_ucm_module_origin_enum moduleId, U8 source, U8 result, U8 cause);
extern void mmi_ucm_at_general_req(mmi_ucm_module_origin_enum moduleId, U8 type, U8 callId, mmi_ucm_l4c_info_struct *l4c_info);
extern void mmi_ucm_bt_handfree_ciev_req(mmi_ucm_module_origin_enum moduleId, U8 type, U8 event);
extern void mmi_ucm_master_service_ind_hdlr(void *inMsg);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_ucm_slave_service_ind_hdlr(void *inMsg);
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* UCM_CALL_PROT_H */

