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
 *   mncc_Struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : mncc_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _MNCC_STRUCT_H
#define _MNCC_STRUCT_H

#if defined(__MCD__)

typedef enum
{
  SS_COMP_INV,
  SS_COMP_RR,
  SS_COMP_RE,
  SS_COMP_REJ
} mncc_ss_comp_type_enum;

typedef enum
{
  SS_REJ_GEN_PROBLEM,
  SS_REJ_INV_PROBLEM,  
  SS_REJ_RR_PROBLEM,
  SS_REJ_RE_PROBLEM,
  SS_REJ_INVALID_PROBLEM = 255    /*mtk00924: remove warning C2874W may be used before being set*/
} mncc_ss_rej_prob_type_enum;

#endif

typedef struct {
    kal_uint8 hold_aux_state;
    kal_uint8 mpty_aux_state;
} mncc_aux_state_struct;

typedef struct {
    kal_uint8 no_value;
    kal_uint8 value_size;
    kal_uint8 value[13];
} mncc_bc_struct;

typedef struct {
    kal_uint8 call_state_value;
} mncc_call_state_struct;

typedef struct {
    kal_uint8 location;
    kal_uint16 cause_value;
    kal_uint8 diagnostics_length;
    kal_uint8 diagnostics[28];
} mncc_cause_struct;

typedef struct {
    kal_uint8 CLIR_suppression;
} mncc_clir_suppression_struct;

typedef struct {
    kal_uint8 CLIR_invocation;
} mncc_clir_invocation_struct;

typedef struct {
    kal_uint8 congestion_level;
} mncc_congestion_level_struct;

typedef struct {
    kal_uint8 num_of_components;
#if defined(__MCD__)
    Component *component[1];
#else
    Component component[1];
#endif    
} mncc_facility_struct;

typedef struct {
    kal_uint8 location;
    kal_uint8 prog_desc;
} mncc_progress_indicator_struct;

typedef struct {
    kal_uint8 no_value;
    kal_uint8 value_size;
    kal_uint8 value[3];
} mncc_hlc_struct;

typedef struct {
    kal_uint8 keypad_info;
} mncc_keypad_facility_struct;

typedef struct {
    kal_uint8 no_value;
    kal_uint8 value_size;
    kal_uint8 value[16];
} mncc_llc_struct;

typedef struct {
    kal_uint8 more_data;
} mncc_more_data_struct;

typedef struct {
    kal_uint8 notification_description;
} mncc_notification_ind_struct;

typedef struct {
    kal_uint8 recall_type;
} mncc_recall_type_struct;

typedef struct {
    kal_uint8 repeat_indication;
} mncc_repeat_ind_struct;

typedef struct {
    kal_uint8 signal_value;
} mncc_signal_struct;

typedef struct {
    kal_uint8 pd;
    kal_uint8 user2user_info_length;
    kal_uint8 user2user_info[131];
} mncc_user2user_struct;

typedef struct {
    kal_uint8 pattern;
} mncc_alerting_pattern_struct;

typedef struct {
    kal_uint8 CCBS_possible;
} mncc_ccbs_status_struct;

typedef struct {
    kal_uint8 cause_of_no_CLI;
} mncc_cause_of_no_cli_struct;

typedef struct {
    kal_uint8 immediate_modification_ind;
} mncc_immediate_modification_ind_struct;

typedef struct {
    kal_uint8 call_priority;
} mncc_priority_level_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} mncc_dummy_local_para_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ti;
    kal_uint8 bc_repeat_indP;
    mncc_repeat_ind_struct bc_repeat_ind;
    kal_uint8 bc1P;
    mncc_bc_struct bc1;
    kal_uint8 bc2P;
    mncc_bc_struct bc2;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 progress_indP;
    mncc_progress_indicator_struct progress_ind;
    kal_uint8 signalP;
    mncc_signal_struct signal;
    kal_uint8 calling_numP;
    l4ccsm_cc_peer_addr_struct calling_num;
    kal_uint8 calling_sub_addrP;
    l4ccsm_cc_sub_addr_struct calling_sub_addr;
    kal_uint8 called_numP;
    l4_addr_bcd_struct called_num;
    kal_uint8 called_sub_addrP;
    l4ccsm_cc_sub_addr_struct called_sub_addr;
    kal_uint8 redirecting_numP;
    l4ccsm_cc_peer_addr_struct redirecting_num;
    kal_uint8 redirecting_sub_addrP;
    l4ccsm_cc_sub_addr_struct redirecting_sub_addr;
    kal_uint8 llc_repeat_indP;
    mncc_repeat_ind_struct llc_repeat_ind;
    kal_uint8 llc1P;
    mncc_llc_struct llc1;
    kal_uint8 llc2P;
    mncc_llc_struct llc2;
    kal_uint8 hlc_repeat_indP;
    mncc_repeat_ind_struct hlc_repeat_ind;
    kal_uint8 hlc1P;
    mncc_hlc_struct hlc1;
    kal_uint8 hlc2P;
    mncc_hlc_struct hlc2;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
    kal_uint8 priorityP;
    mncc_priority_level_struct priority;
    kal_uint8 alertP;
    mncc_alerting_pattern_struct alert;
    kal_uint8 cause_of_no_cliP;
    mncc_cause_of_no_cli_struct cause_of_no_cli;
    kal_uint8 backup_bcP;
    mncc_bc_struct backup_bc;
} mncc_setup_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 progress_indP;
    mncc_progress_indicator_struct progress_ind;
    kal_uint8 connected_numP;
    l4ccsm_cc_peer_addr_struct connected_num;
    kal_uint8 connected_sub_addrP;
    l4ccsm_cc_sub_addr_struct connected_sub_addr;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_setup_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
} mncc_setup_compl_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 is_cc_setup_sent; //mtk01602, 071022
    kal_uint8 causeP;
    mncc_cause_struct cause;
    kal_uint8 facilityP;
    mncc_facility_struct facility;    
} mncc_rej_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 bc_repeat_indP;
    mncc_repeat_ind_struct bc_repeat_ind;
    kal_uint8 bc1P;
    mncc_bc_struct bc1;
    kal_uint8 bc2P;
    mncc_bc_struct bc2;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 progress_indP;
    mncc_progress_indicator_struct progress_ind;
    kal_uint8 priorityP;
    mncc_priority_level_struct priority;
} mncc_call_proc_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_progress_indicator_struct progress_ind;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_progress_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 progress_indP;
    mncc_progress_indicator_struct progress_ind;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_alert_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_notification_ind_struct notification_ind;
} mncc_notify_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_cause_struct cause;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 progress_indP;
    mncc_progress_indicator_struct progress_ind;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
    kal_uint8 ccbs_allowedP;
    mncc_ccbs_status_struct ccbs_allowed;
} mncc_disc_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 causeP;
    mncc_cause_struct cause;
    kal_uint8 second_causeP;
    mncc_cause_struct second_cause;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_rel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 causeP;
    mncc_cause_struct cause;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_rel_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
} mncc_facility_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 response;
    kal_uint8 digit;
    kal_uint8 causeP;
    mncc_cause_struct cause;
} mncc_start_dtmf_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 response;
    kal_uint8 digit;
    kal_uint8 causeP;
    mncc_cause_struct cause;
} mncc_stop_dtmf_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_bc_struct bc;
    kal_uint8 llcP;
    mncc_llc_struct llc;
    kal_uint8 hlcP;
    mncc_hlc_struct hlc;
    kal_uint8 rscd_P;
} mncc_modify_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 response;
    mncc_bc_struct bc;
    kal_uint8 llcP;
    mncc_llc_struct llc;
    kal_uint8 hlcP;
    mncc_hlc_struct hlc;
    kal_uint8 causeP;
    mncc_cause_struct cause;
} mncc_modify_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cause;
    kal_uint8 channel_type;
    kal_uint8 channel_mode;
} mncc_sync_ind_struct;

#ifdef __MTK_3G_MRAT_ARCH__
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 rat;          /* rat_enum */
} mncc_rat_ind_struct;
#endif

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 response;
    kal_uint8 causeP;
    mncc_cause_struct cause;
} mncc_hold_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 response;
    kal_uint8 causeP;
    mncc_cause_struct cause;
} mncc_retrieve_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_user2user_struct uui;
    kal_uint8 more_dataP;
    mncc_more_data_struct more_data;
} mncc_user_info_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_congestion_level_struct congestion_level;
    kal_uint8 causeP;
    mncc_cause_struct cause;
} mncc_congestion_ctrl_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ti;
    kal_uint8 bc_repeat_indP;
    mncc_repeat_ind_struct bc_repeat_ind;
    kal_uint8 bc1P;
    mncc_bc_struct bc1;
    kal_uint8 bc2P;
    mncc_bc_struct bc2;
    kal_uint8 llc_repeat_indP;
    mncc_repeat_ind_struct llc_repeat_ind;
    kal_uint8 llc1P;
    mncc_llc_struct llc1;
    kal_uint8 llc2P;
    mncc_llc_struct llc2;
    kal_uint8 hlc_repeat_indP;
    mncc_repeat_ind_struct hlc_repeat_ind;
    kal_uint8 hlc1P;
    mncc_hlc_struct hlc1;
    kal_uint8 hlc2P;
    mncc_hlc_struct hlc2;
} mncc_ccbs_est_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_recall_type_struct recall_type;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 ccbs_recall_numP;
    l4_addr_bcd_struct ccbs_recall_num;	
} mncc_ccbs_recall_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint32 ccm;
    kal_uint32 acm;
    kal_bool update_cdur;
    kal_uint32 cdur;	
} mncc_aoc_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} mncc_sig_con_re_est_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} mncc_sig_con_re_est_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 call_priority;
    kal_uint8 clir_suppression;
    kal_uint8 clir_invocation;
    kal_uint8 bc_repeat_indP;
    mncc_repeat_ind_struct bc_repeat_ind;
    kal_uint8 bc1P;
    mncc_bc_struct bc1;
    kal_uint8 bc2P;
    mncc_bc_struct bc2;
    kal_uint8 simple_recall_alignmentP;
    mncc_facility_struct simple_recall_alignment;
    kal_uint8 calling_sub_addrP;
    l4ccsm_cc_sub_addr_struct calling_sub_addr;
    kal_uint8 called_numP;
    l4_addr_bcd_struct called_num;
    kal_uint8 called_sub_addrP;
    l4ccsm_cc_sub_addr_struct called_sub_addr;
    kal_uint8 llc_repeat_indP;
    mncc_repeat_ind_struct llc_repeat_ind;
    kal_uint8 llc1P;
    mncc_llc_struct llc1;
    kal_uint8 llc2P;
    mncc_llc_struct llc2;
    kal_uint8 hlc_repeat_indP;
    mncc_repeat_ind_struct hlc_repeat_ind;
    kal_uint8 hlc1P;
    mncc_hlc_struct hlc1;
    kal_uint8 hlc2P;
    mncc_hlc_struct hlc2;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
    kal_uint8 advanced_recall_alignmentP;
    mncc_facility_struct advanced_recall_alignment;
    kal_uint8 recall_alignment_not_essentialP;
    mncc_facility_struct recall_alignment_not_essential;
    kal_uint8 service_categoryP;
    kal_uint8 service_category;	
} mncc_setup_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 connected_sub_addrP;
    l4ccsm_cc_sub_addr_struct connected_sub_addr;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_setup_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_cause_struct cause;
} mncc_rej_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 bc_repeat_indP;
    mncc_repeat_ind_struct bc_repeat_ind;
    kal_uint8 bc1P;
    mncc_bc_struct bc1;
    kal_uint8 bc2P;
    mncc_bc_struct bc2;
    kal_uint8 causeP;
    mncc_cause_struct cause;
} mncc_call_conf_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_alert_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_notification_ind_struct notification_ind;
} mncc_notify_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_cause_struct cause;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_disc_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 causeP;
    mncc_cause_struct cause;
    kal_uint8 facilityP;
    mncc_facility_struct facility;
    kal_uint8 uuiP;
    mncc_user2user_struct uui;
} mncc_rel_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_cause_struct cause;
} mncc_rel_comp_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_facility_struct facility;
} mncc_facility_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 digit;
} mncc_start_dtmf_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 digit;
} mncc_stop_dtmf_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_bc_struct bc;
    kal_uint8 llcP;
    mncc_llc_struct llc;
    kal_uint8 hlcP;
    mncc_hlc_struct hlc;
   kal_uint8 rscd_P; /*RSCD present*/
} mncc_modify_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 response;
    mncc_bc_struct bc;
    kal_uint8 llcP;
    mncc_llc_struct llc;
    kal_uint8 hlcP;
    mncc_hlc_struct hlc;
    kal_uint8 causeP;
    mncc_cause_struct cause;
    kal_uint8 rscd_P; 
} mncc_modify_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
} mncc_hold_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
} mncc_retrieve_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_user2user_struct uui;
    kal_uint8 more_dataP;
    mncc_more_data_struct more_data;
} mncc_user_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    kal_uint8 bc_repeat_indP;
    mncc_repeat_ind_struct bc_repeat_ind;
    kal_uint8 bc1P;
    mncc_bc_struct bc1;
    kal_uint8 bc2P;
    mncc_bc_struct bc2;
    kal_uint8 llc_repeat_indP;
    mncc_repeat_ind_struct llc_repeat_ind;
    kal_uint8 llc1P;
    mncc_llc_struct llc1;
    kal_uint8 llc2P;
    mncc_llc_struct llc2;
    kal_uint8 hlc_repeat_indP;
    mncc_repeat_ind_struct hlc_repeat_ind;
    kal_uint8 hlc1P;
    mncc_hlc_struct hlc1;
    kal_uint8 hlc2P;
    mncc_hlc_struct hlc2;
    kal_uint8 causeP;
    mncc_cause_struct cause;
} mncc_ccbs_est_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
} mncc_ccbs_setup_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
    kal_uint8 ti;
    mncc_cause_struct cause;
} mncc_ccbs_rej_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 acmmax;
    kal_uint32 acm;
} mncc_acm_update_req_struct;
#endif 


