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
 *   l4c2csm_cc_struct.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *  FILENAME : l4c2csm_cc_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L4C2CSM_CC_STRUCT_H
#define _L4C2CSM_CC_STRUCT_H

//#include "l4c_common_enum.h"
//#include "csmcc_enums.h"  /*mtk00924 add 041208 for +ECPI*/
//#include "csmcc_common_enums.h"    /*mtk00924 add 041208 for +ECPI*/
//#include "ps2sat_struct.h"   //mtk01602: add for SATCE 

#if defined (_L4C_COMMON_ENUM_H) || defined (_L4C_COMMON_ENUM_2_H)
#else
#error include "l4c_common_enum.h" before l4c2csm_cc_struct.h
#endif

#if defined (_CSMCC_ENUMS_H) || defined (_CSMCC_ENUMS_2_H)
#else
#error include "csmcc_enums.h" before l4c2csm_cc_struct.h
#endif

#if defined (_CSMCC_COMMON_ENUMS_H) || defined (_CSMCC_COMMON_ENUMS_2_H)
#else
#error include "csmcc_common_enums.h" before l4c2csm_cc_struct.h
#endif

#ifndef _PS2SAT_STRUCT_H
#error include "ps2sat_struct.h" before l4c2csm_cc_struct.h
#endif

typedef enum
{
  RDN_ALLOWED,
  RDN_RESTRICTED,
  RDN_UNAVAILABLE,
  RDN_RESTRICTEDADDR
} l4ccsm_cc_rdn_enum;

typedef enum
{
  CNAP_ALLOWED,
  CNAP_RESTRICTED,
  CNAP_UNAVAILABLE,
  CNAP_RESTRICTEDNAME
} l4ccsm_cc_cnap_enum;

typedef enum
{
  BSC_BS,
  BSC_TS
} l4ccsm_cc_bsc_enum;

typedef enum
{
   CALL_RETRIEVED,
   CALL_ONHOLD
} l4ccsm_cc_hold_ind_enum;

typedef enum
{
   ECT_ALERTING,
   ECT_ACTIVE
} l4ccsm_cc_ect_state_enum;

typedef enum
{
   GEN_UNRECOGNIZED_COMP,
   GEN_MISTYPED_COMP,
   GEN_BAD_STRUCT_COMP
} l4ccsm_cc_ss_gen_prob_enum;

typedef enum
{
   INV_DUP_INV_ID,
   INV_UNRECOGNIZED_OP,
   INV_MISTYPED_PARA,
   INV_RESOURCE_LIMIT,
   INV_INIT_RELEASE,
   INV_UNRECOGNIZED_LINK_ID,
   INV_LINK_ID_RSP_UNEXPECTED,
   INV_UNEXPECTED_LINK_OP
} l4ccsm_cc_ss_inv_prob_enum;

typedef enum
{
   RR_UNRECOGNIZED_INV_ID,
   RR_UNEXPECTED,
   RR_MISTYPED_PARA
} l4ccsm_cc_ss_rr_prob_enum;

typedef enum
{
   RE_UNRECOGNIZED_INV_ID,
   RE_UNEXPECTED,
   RE_UNRECOGNIZED_ERROR,
   RE_UNEXPECTED_ERROR,
   RE_MISTYPED_PARA
} l4ccsm_cc_ss_re_prob_enum;

typedef enum
{
   L4C_MODIFY_CMD_NONE,
   L4C_MODIFY_ATA,
   L4C_MODIFY_ATD
} l4ccsm_cc_modify_cmd_enum;

typedef struct {
    kal_uint8 addr_ind_present;
    kal_uint8 addr_ind;
    l4_addr_bcd_struct addr;
} l4ccsm_cc_peer_addr_struct;

typedef struct {
    kal_uint8 sub_addr_len;
    kal_uint8 sub_addr[21];
} l4ccsm_cc_sub_addr_struct;

typedef struct {
    l4_addr_bcd_struct partyNumber;
    kal_uint8 partyNumberSubaddress_present;
    l4ccsm_cc_sub_addr_struct partyNumberSubaddress;
} l4ccsm_cc_rdn_addr_struct;

typedef struct {
    kal_uint8 ect_rdn_present;
#if defined(__MCD__)
    l4ccsm_cc_rdn_enum rdn_choice_tag;
#else
    RDNChoiceId rdn_choice_tag;
#endif        
    union {
        l4ccsm_cc_rdn_addr_struct presentationAllowedAddress;
        kal_uint8 presentationRestricted;
        kal_uint8 numberNotAvailableDueToInterworking;
        l4ccsm_cc_rdn_addr_struct presentationRestrictedAddress;
    } rdn_choice_value;
} l4ccsm_cc_ect_rdn_struct;

typedef struct {
    kal_uint8 callingName_present;
#if defined(__MCD__)
    l4ccsm_cc_cnap_enum callingName_choice_tag;
#else
    NameChoiceId callingName_choice_tag;
#endif    
    union {
        l4_name_struct namePresentationAllowed;
        kal_uint8 presentationRestricted;
        kal_uint8 nameUnavailable;
        l4_name_struct namePresentationRestricted;
    } callingName_choice_value;
} l4ccsm_cc_name_ind_struct;

typedef struct {
    kal_uint8 ccbs_index_present;
    kal_uint8 ccbs_index;
    kal_uint8 b_subscriberNumber_present;
    l4_addr_bcd_struct b_subscriberNumber;
    kal_uint8 b_subscriberSubaddress_present;
    l4ccsm_cc_sub_addr_struct b_subscriberSubaddress;
    kal_uint8 bs_code_present;
    kal_uint8 bs_code;
} l4ccsm_cc_ccbs_feature_struct;

typedef struct {
    kal_uint8 ccbs_feature_present;
    l4ccsm_cc_ccbs_feature_struct ccbs_feature;
    kal_uint8 alertingPattern_present;
    kal_uint8 altertingPattern;    
} l4ccsm_cc_ccbs_ind_struct;

typedef struct {
    kal_uint8 type;
    kal_bool  status_present;
    kal_uint8 status;
    kal_bool  notification_present;
    kal_uint8 notification;
    kal_uint16 cug_index;
    l4ccsm_cc_ect_rdn_struct ect_rdn;
    l4ccsm_cc_name_ind_struct name_ind;
    l4ccsm_cc_ccbs_ind_struct ccbs_ind;
} l4ccsm_cc_notify_ss_arg_struct;

/*mtk01602, 053007: SATe Open Channel for CSD*/
typedef struct {
	kal_uint8  is_addr_present;
	l4_addr_bcd_struct  addr;
	kal_uint8   is_subaddr_present;
	l4ccsm_cc_sub_addr_struct subaddr;
	kal_uint8   is_user_id_present;
	kal_uint8   user_id[32];
	kal_uint8   is_user_pwd_present;
	kal_uint8   user_pwd[32];
	kal_uint8   is_local_addr_present;
	kal_uint8   local_addr[16]; //To be confirmed, Nick set it as length 16
	sat_csd_bearer_para_struct  sat_cbst; //refer 11.14 6.6.27; mandatory IE, no matter SIM provided or Default case.
}l4ccsm_cc_sat_prof_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} l4ccsm_cc_dummy_local_para_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
} l4ccsm_cc_startup_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint16 cause;
} l4ccsm_cc_startup_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 channel_mode;
    kal_uint8 rat;    	
} l4ccsm_cc_attach_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 rat;
} l4ccsm_cc_detach_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
} l4ccsm_cc_acm_reset_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint16 cause;
} l4ccsm_cc_acm_reset_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint32 acmmax;
} l4ccsm_cc_acmmax_set_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint16 cause;
} l4ccsm_cc_acmmax_set_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 digit_count;
    kal_uint8 dtmf_digit[MAX_CC_ADDR_BCD_LEN];   
} l4ccsm_cc_auto_dtmf_start_ind_struct;
/* no_dtmf shold be less than MAX_CC_ADDR_BCD_LEN. 
   The extra last one entry is for null terminal. */

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
} l4ccsm_cc_auto_dtmf_complete_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    l4_addr_bcd_struct redirect_num;
    kal_uint8 redirect_sub_addr_present;
    l4ccsm_cc_sub_addr_struct redirect_sub_addr;
} l4ccsm_cc_call_deflection_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
} l4ccsm_cc_call_deflection_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id_present;
    kal_uint8 call_id;
    kal_uint8 crss_req;
} l4ccsm_cc_crss_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id_present;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint8  crss_req; //mtk01602, 070718
} l4ccsm_cc_crss_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint32 ccm;
    kal_uint32 acm;
    kal_uint8 ccwv;
} l4ccsm_cc_ccm_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 connected_sub_addr_present;
    l4ccsm_cc_sub_addr_struct connected_sub_addr;
} l4ccsm_cc_call_accept_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
} l4ccsm_cc_call_accept_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 alert;
} l4ccsm_cc_call_alert_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 call_type;
    kal_uint8 connected_number_present;
    l4ccsm_cc_peer_addr_struct connected_number;
    kal_uint8 connected_sub_addr_present;
    l4ccsm_cc_sub_addr_struct connected_sub_addr;
} l4ccsm_cc_call_connect_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
} l4ccsm_cc_call_disc_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_id;
} l4ccsm_cc_rel_comp_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 call_type;
    kal_uint32 ccm;
} l4ccsm_cc_call_disc_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    l4ccsm_cc_modify_cmd_enum modify_cmd;
} l4ccsm_cc_call_modify_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 cur_call_type;
    kal_uint8 cause_present;
    kal_uint16 cause;
} l4ccsm_cc_call_modify_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 cur_call_type;
} l4ccsm_cc_call_modify_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 preempt_type;
} l4ccsm_cc_call_preempt_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint8 call_type;    
    kal_uint32 ccm;
} l4ccsm_cc_call_rel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    l4_addr_bcd_struct called_number;
    kal_uint8 called_sub_addr_present;
    l4ccsm_cc_sub_addr_struct called_sub_addr;
    kal_uint8 cug_info;
    kal_uint8 clir_info_present;
    kal_uint8 clir_info;
    kal_uint8 call_priority_present;
    kal_uint8 call_priority;
    kal_uint8 call_type;
    kal_uint8 redial;
    kal_uint8 csd_prof_id;
    sat_csd_bearer_para_struct sat_cbst;
} l4ccsm_cc_call_setup_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id_present;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint8 call_type;    
    sat_csd_bearer_para_struct sat_cbst;
    kal_uint8 terminal_res;
    kal_uint8 add_res;
} l4ccsm_cc_call_setup_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 signal_value_present;
    kal_uint8 signal_value;
    kal_uint8 alerting_pattern_present;
    kal_uint8 alerting_pattern;
    kal_uint8 cw_flag;
    kal_uint8 auto_answer;
    kal_uint8 call_type;
    kal_uint8 calling_number_present;
    l4ccsm_cc_peer_addr_struct calling_number;
    kal_uint8 calling_sub_addr_present;
    l4ccsm_cc_sub_addr_struct calling_sub_addr;
    kal_uint8 redirecting_number_present;
    l4ccsm_cc_peer_addr_struct redirecting_number;
    kal_uint8 redirecting_sub_addr_present;
    l4ccsm_cc_sub_addr_struct redirecting_sub_addr;
    kal_uint8 no_cli_cause_present;
    kal_uint8 no_cli_cause;
    kal_uint8 call_priority_present;
    kal_uint8 call_priority;
} l4ccsm_cc_call_setup_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 ccbs_possible_present;
    kal_uint8 ccbs_possible;
    kal_uint16 cause;
    kal_uint8 call_type;
} l4ccsm_cc_call_disc_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
} l4ccsm_cc_data_activate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 response;
} l4ccsm_cc_data_activate_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    l4_addr_bcd_struct called_number;
    /*Cosine 070415: R4 new IE, Emergency Call Category*/
    kal_uint8 service_category;
} l4ccsm_cc_emergency_call_setup_req_struct;

typedef l4ccsm_cc_call_setup_cnf_struct l4ccsm_cc_emergency_call_setup_cnf_struct;

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

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    l4ccsm_cc_notify_ss_arg_struct notify_ss_arg;
    kal_uint8 ccbs_recall_numP;
    l4_addr_bcd_struct ccbs_recall_num;	    	
} l4ccsm_cc_notify_ss_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 tone;
} l4ccsm_cc_start_dtmf_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 tone;
    kal_uint8 cause_present;
    kal_uint16 cause;
} l4ccsm_cc_start_dtmf_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 tone;
} l4ccsm_cc_stop_dtmf_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 tone;    
    kal_uint8 cause_present;
    kal_uint16 cause;    
} l4ccsm_cc_stop_dtmf_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 sat_call_type;
    kal_uint8 called_sub_addr_present;
    l4ccsm_cc_sub_addr_struct called_sub_addr;
    kal_uint8 ccp_present;
    kal_uint8 ccp[15];
    kal_uint8 size_of_ccp;
/////    kal_uint8 is_changed_from_ss;    
    kal_uint8 	type_of_modification;//mtk01616_070521
    /*Michael:the following parameter is added for SAT retry*/
    kal_bool l4c_retry;  
    kal_bool is_emergency_call; //Cosine, 070831
} l4ccsm_cc_sat_setup_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id_present;
    kal_uint8 call_id;
    kal_uint8 response;
    kal_uint8 terminal_res;
    kal_uint8 additional_res;
    kal_uint8 connected_number_present;
    l4ccsm_cc_peer_addr_struct connected_number;
    kal_uint8 connected_sub_addr_present;
    l4ccsm_cc_sub_addr_struct connected_sub_addr;
////    kal_uint8 is_changed_from_ss;
    kal_uint8 	type_of_modification;//mtk01616_070523
    /*Michael: following 4 parameters are added for SAT retry*/
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint8 size_of_ccp;
    kal_uint8 ccp[15];   
} l4ccsm_cc_sat_setup_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_esc_off;
    kal_uint8 port;
} l4ccsm_cc_uart_transfer_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 port;
    kal_bool is_esc;
} l4ccsm_cc_uart_transfer_ind_struct; 
/* Ripple: must the same with csm_l2r/tdt_esc_on_ind_struct, becasue CSM uses hold_local_para(). */

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 call_type;
    kal_uint8 csd_prof_id;
    kal_uint32 user_rate;
} l4ccsm_cc_csd_est_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    kal_uint8 digit_count;
    kal_uint8 dtmf_digit[MAX_CC_ADDR_BCD_LEN];    
} l4ccsm_cc_auto_dtmf_start_req_struct;
/* no_dtmf shold be less than MAX_CC_ADDR_BCD_LEN. 
   The extra last one entry is for null terminal. */

#ifdef __TCPIP__
#include "custom_nvram_editor_data_item.h"

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 csd_prof_id;
   kal_bool dns_addr_present;
   nvram_ef_csd_profile_struct csd_prof;
   l4ccsm_cc_sat_prof_struct  sat_prof; //mtk01602, 070530: add for Nick SATe
} l4ccsm_cc_set_csd_prof_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 result;
   kal_uint8 error_cause;   
   sat_csd_bearer_para_struct  sat_cbst; //mtk01602: use to send SIM modify indication
} l4ccsm_cc_set_csd_prof_cnf_struct;
#endif

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 line_id;
} l4ccsm_cphs_display_als_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 line_id;
} l4ccsm_cc_update_als_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 result;
   kal_uint8 error_cause; 
} l4ccsm_cc_update_als_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_bool call_exist;
} l4ccsm_cc_call_info_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 no_dtmf;
    kal_uint8 dtmf[MAX_CC_ADDR_BCD_LEN];
} l4ccsm_cc_sat_send_dtmf_req_struct;
/* no_dtmf shold be less than MAX_CC_ADDR_BCD_LEN. 
   The extra last one entry is for null terminal. */

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
} l4ccsm_cc_sat_abort_dtmf_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8    src_id;
    kal_uint8	res;
    kal_uint8	cause;
} l4ccsm_cc_sat_send_dtmf_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
    csmcc_cpi_msg_type_enum msg_type;
    kal_bool is_ibt;
    kal_bool is_tch;
    clcc_dir_enum dir;
    clcc_mode_enum call_mode;
    kal_bool numberP;
    l4_addr_bcd_struct number;
    kal_uint16 disc_cause; //Add for WM FTA	
} l4ccsm_cc_cpi_ind_struct; /*mtk00924 add 041208 for +ECPI*/

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
} l4ccsm_cc_call_sync_ind_struct; /*mtk00924 add 050727 for indicate MMI to get call info*/

#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif 


