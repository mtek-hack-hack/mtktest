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
 *   l4c2smu_struct.h
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
 *  FILENAME : l4c2smu_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L4C2SMU_STRUCT_H
#define _L4C2SMU_STRUCT_H

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 poweron_mode;//add for system error with exception handle
} l4csmu_start_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint8 chv1_phonelock_status;
    sim_lp_struct lp;
    kal_uint16 rmmi_error_cause;
    sim_chv_info_struct chv_info;
} l4csmu_start_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 type;
    kal_uint8 op;
    kal_uint8 key1[8];
    kal_uint8 key2[8];
} l4csmu_security_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 type;
    kal_uint8 cphs_retry_count; /* Only for CPHS Locks */
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint16 rmmi_error_cause;
    sim_chv_info_struct chv_info;
} l4csmu_security_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 type;
    kal_uint8 remaining_count;
} l4csmu_security_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 category;     /* sml_cat_enum */
    kal_uint8 op;           /* sml_op_enum */
    kal_uint8 key[8];
    kal_uint8 len;          /* valid bytes in data[] */
    kal_uint8 data[10];     /* the data for add command */
} l4csmu_set_personalization_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 category;     /* sml_cat_enum */
    kal_uint8 op;           /* sml_op_enum */
    kal_uint8 result;
    kal_uint8 state;        /* sml_state_enum */
    kal_uint8 retry_count;
    kal_uint8 num_of_sets;  /* number of sets in this category */
    kal_uint8 space_of_sets;/* number of empty sets in this category */
} l4csmu_set_personalization_cnf_struct;
 
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 cmd;
    kal_uint16 fileid;
    kal_uint8 p1;
    kal_uint8 p2;
    kal_uint8 p3;
    kal_uint8 data[256];
} l4csmu_sim_access_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 sw1;
    kal_uint8 sw2;
    kal_uint16 length;
    kal_uint8 res_data[256];
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
} l4csmu_sim_access_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 src_id;
    kal_uint8 idx;
    kal_uint8 op;
    kal_uint8 plmn_data[5];
} l4csmu_plmn_sel_write_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
} l4csmu_plmn_sel_write_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 currency_code[3];
    kal_uint8 puct_data[18];
} l4csmu_puct_write_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
} l4csmu_puct_write_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
} l4csmu_puct_read_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint8 currency_code[3];
    kal_uint8 puct_data[18];
} l4csmu_puct_read_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
}l4csmu_csp_read_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint8 data[18];
}l4csmu_csp_read_cnf_struct;

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
#endif
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 dn_type;
    kal_uint8 switch_on;
} l4csmu_dial_mode_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause_present;
    kal_uint16 cause;
} l4csmu_dial_mode_cnf_struct;

typedef struct {
   kal_uint8 alpha_id_dcs;
   kal_uint8 alpha_id_size;
   kal_uint8 alpha_id[32];
   kal_uint8 ton_npi;
   kal_uint8 digit_size;
   kal_uint8 digit[41];
} l4csmu_addr_struct;

typedef struct {
   kal_uint8 alpha_id_size;
   kal_uint8 alpha_id[21];
   kal_uint8 ton_npi;
   kal_uint8 digit_size;
   kal_uint8 digit[4];//[41];
   kal_uint8 index_level;
   kal_bool network_specific;
   kal_bool premium_rate;
} l4csmu_info_num_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 is_spn_valid;     // SPN
   kal_uint8 is_spn_RPLMN_required;
   kal_uint8 spn[17];
   kal_uint8 is_opname_valid;  // OPN
   kal_uint8 opname[21];
   kal_uint8 is_sopname_valid; // sOPN
   kal_uint8 sopname[11];
   kal_uint8 no_msisdn;        // MSISDN
   l4csmu_addr_struct msisdn[2];
   kal_uint8 no_info_num;      // Information Numbers
   l4csmu_info_num_struct *info_num;
   kal_uint8 is_valid_csp;
   kal_uint8 csp[22];          // Custom Service Profile
   kal_uint8 is_puct_valid;
   kal_uint8 ef_puct[5];
   kal_uint8 is_autolock_enable; /* SML */
   kal_uint8 autolock_result;    /* SML */
   kal_uint8 autolock_remain;    /* SML */
} l4csmu_mmi_info_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
} l4csmu_sml_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 state[7];
    kal_uint8 retry_count[7];
    kal_uint8 autolock_count[7];
    kal_uint8 num_of_sets[7];
    kal_uint8 total_size_of_cat[7];
    kal_uint8 key_state[7];
    kal_uint8 ef_imsi[8];
    kal_uint8 is_valid_gid1;
    kal_uint8 ef_gid1;
    kal_uint8 is_valid_gid2;
    kal_uint8 ef_gid2;
    kal_uint8 digits_of_mnc;
} l4csmu_sml_status_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool   cipher_ind;    //20050202 Benson add for MMI cipher indication display
   /* Johnny: cipher_ind is useless now, L4C will use l4csmu_get_cipher_ind_status() to get cipher_ind status from SMU */
} l4csmu_mmrr_ready_ind_struct;

#ifdef __SAT__

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
   kal_bool is_icon_available;
   sat_icon_struct icon_info;
   kal_uint8 bearer_type;
} l4csat_open_channel_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
   kal_bool res;
} l4csat_open_channel_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 res;  		/* sat_terminal_res_enum */
   kal_uint8 cause;		/* sat_additional_info_for_res_enum */
} l4csmu_sat_open_channel_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 state;    
} l4csmu_sat_notify_mmi_ind_struct;

typedef struct {
   kal_uint8   	context_id;
   kal_uint8 	name_length;
   kal_uint8 	name_dcs;
   kal_uint8     authentication_type;
   kal_uint8 	name[32];      
   kal_uint8     user_name[16];
   kal_uint8    	password[16];
   kal_uint8  	dns[4];
   kal_uint8  	apn [100];
   kal_uint8  	apn_length;
   sat_gprs_qos_struct     req_qos;
} gprs_data_account_struct;

typedef struct {
   kal_uint8 	ref_count;
   kal_uint16 	msg_len;
   gprs_data_account_struct gprs_data_account;
} l4csat_set_gprs_data_account_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint8 cause;
} l4csat_set_gprs_data_account_res_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;	
   sat_csd_bearer_para_struct bearer_para;
   kal_uint8 size_of_address;
   kal_uint8 addr[MAX_SIM_ADDR_BCD_LEN];
   kal_uint8 size_of_subaddr;
   kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
   kal_uint32 duration1;
   kal_uint32 duration2;
} l4csat_csm_open_csd_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   sat_csd_bearer_para_struct bearer_para;
} l4csat_csm_bearer_info_ind_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint16 cause;   /* cm_enum_cause */
} l4csat_csm_open_csd_res_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
} l4csat_cc_call_disc_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint16 cause;  /* cm_enum_cause */
} l4csat_cc_call_disc_res_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint16 cause;  /* cm_enum_cause */
} l4csat_cc_call_disc_ind_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 res;
} l4csmu_sat_send_data_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 res;  		/* sat_terminal_res_enum */
   kal_uint8 cause; 	/* sat_additional_info_for_res_enum */
} l4csmu_sat_send_data_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 res;
} l4csmu_sat_recv_data_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 res;  		/* sat_terminal_res_enum */
   kal_uint8 cause; 	/* sat_additional_info_for_res_enum */
} l4csmu_sat_recv_data_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 res;
} l4csmu_sat_close_data_req_struct;

// Nick start
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 nw_acct_id;
    kal_bool is_addr_valid;
    kal_uint8 size_of_address;
    kal_uint8 addr[MAX_SIM_ADDR_BCD_LEN];
    kal_bool is_subaddr_valid;
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    kal_bool is_username_valid;
    kal_uint8 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_bool is_passwd_valid;
    kal_uint8 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_bool is_local_addr_valid;
    kal_uint8 no_local_addr;
    kal_uint8 local_addr[16];
    kal_bool is_dest_addr_valid;
    kal_uint8 no_dest_addr;
    kal_uint8 dest_addr[16];
    sat_csd_bearer_para_struct csd_bearer;
} l4csmu_sat_set_csd_prof_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 res;
//    sat_csd_bearer_para_struct csd_bearer;
} l4csmu_sat_set_csd_prof_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 nw_acct_id;    
    kal_bool is_apn_valid;
    kal_uint8 apn_length;
    kal_uint8 apn[50];
    kal_bool is_username_valid;
    kal_uint8 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_bool is_passwd_valid;
    kal_uint8 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_bool is_local_addr_valid;
    kal_uint8 no_local_addr;
    kal_uint8 local_addr[16];
    kal_bool is_dest_addr_valid;
    kal_uint8 no_dest_addr;
    kal_uint8 dest_addr[16];
    sat_gprs_bearer_para_struct gprs_bearer;
} l4csmu_sat_set_gprs_prof_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 res;
//    sat_gprs_bearer_para_struct gprs_bearer;
} l4csmu_sat_set_gprs_prof_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 bearer_type;
    sat_gprs_bearer_para_struct gprs_bearer;
    sat_csd_bearer_para_struct csd_bearer;
} l4csmu_sat_bearer_para_req_struct ;

typedef struct {
  kal_uint8 ref_count;
  kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
   kal_bool is_icon_available;
   sat_icon_struct icon_info;
  kal_uint8 bearer_type;
} l4csmu_sat_open_channel_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
  kal_uint8 res;
  kal_uint8 additional_info;
} l4csmu_sat_open_channel_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
  kal_uint8 state;
  kal_bool is_icon_available;
  sat_icon_struct icon_info;
} l4csmu_sat_close_channel_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
  kal_uint8 state;
   kal_bool is_icon_available;
   sat_icon_struct icon_info;
} l4csmu_sat_send_data_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
  kal_uint8 state;
  kal_bool is_icon_available;
  sat_icon_struct icon_info;
} l4csmu_sat_recv_data_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 state;
} l4csmu_sat_channel_disc_evdl_ind_struct;



#endif // __SAT__

#endif 


