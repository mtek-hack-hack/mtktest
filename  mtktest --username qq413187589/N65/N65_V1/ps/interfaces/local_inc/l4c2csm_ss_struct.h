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
 *   l4c2csm_ss_struct.h
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
 *  FILENAME : l4c2csm_ss_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L4C2CSM_SS_STRUCT_H
#define _L4C2CSM_SS_STRUCT_H

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
} l4ccsm_ciss_startup_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 op_code;
   kal_uint8 ss_code;
   kal_uint8 bs_code;
   kal_uint8 no_reply_timer;
   kal_uint8 subaddress_flag;
   l4_addr_bcd_struct address;
   l4_addr_bcd_struct subaddress;
} l4ccsm_ciss_cf_begin_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 op_code;
   kal_uint8 bs_code;
} l4ccsm_ciss_cw_begin_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 op_code;
   kal_uint8 ss_code;
   kal_uint8 bs_code;
   kal_uint8 old_pw[4];
   kal_uint8 new_pw1[4];
   kal_uint8 new_pw2[4];
} l4ccsm_ciss_cb_begin_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 op_code;
   kal_uint8 ss_code;
   kal_uint8 default_priority_level;
} l4ccsm_ciss_emlpp_begin_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 ss_code;
} l4ccsm_ciss_cli_begin_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 op_code;
   kal_uint8 ccbs_index;
} l4ccsm_ciss_ccbs_begin_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 ussd_dcs;
   kal_uint8 ussd_string[MAX_DIGITS_USSD];
   kal_uint8 ussd_string_length;
   kal_bool change_phase_req;   
} l4ccsm_ciss_pussr_begin_req_struct;

typedef l4ccsm_ciss_pussr_begin_req_struct l4ccsm_ciss_ussr_begin_ind_struct;
typedef l4ccsm_ciss_pussr_begin_req_struct l4ccsm_ciss_ussn_begin_ind_struct;
typedef l4ccsm_ciss_pussr_begin_req_struct l4ccsm_ciss_ussr_fac_res_struct;
typedef l4ccsm_ciss_pussr_begin_req_struct l4ccsm_ciss_ussr_fac_ind_struct;
typedef l4ccsm_ciss_pussr_begin_req_struct l4ccsm_ciss_ussn_fac_ind_struct;

typedef struct {
   kal_uint8 bs_code;
   kal_uint8 ss_status;
   kal_uint8 no_reply_timer;
   kal_uint8 subaddress_flag;
   kal_char address[MAX_CC_ADDR_LEN];
   kal_char subaddress[MAX_CC_SUB_ADDR_LEN];
} forwarding_list_struct;

typedef struct {
   kal_uint8 cause_present;
   kal_uint16 cause_value;
   kal_uint8 para_present;
#ifdef __SAT__
   kal_uint8 res;
   kal_uint8 size_of_additional_info;
   kal_uint8 additional_info[255];
#endif
} ss_return_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   kal_uint8 op_code;
   kal_uint8 ss_code;
   kal_uint8 bs_count;
   forwarding_list_struct forwarding_list[13];
   ss_return_struct ss_return;
} l4ccsm_ciss_cf_end_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   kal_uint8 op_code;
   kal_uint8 bs_count;
   kal_uint8 bs_code[13];
   kal_uint8 ss_status;
   ss_return_struct ss_return;
} l4ccsm_ciss_cw_end_cnf_struct;

typedef struct {
   kal_uint8 bs_code;
   kal_uint8 ss_status;
} barring_list_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   kal_uint8 op_code;
   kal_uint8 ss_code;
   kal_uint8 bs_count;
   barring_list_struct barring_list[13];
   ss_return_struct ss_return;
} l4ccsm_ciss_cb_end_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   kal_uint8 op_code;
   kal_uint8 ss_status;
   kal_uint8 default_priority_level;
   kal_uint8 maximum_priority_level;
   ss_return_struct ss_return;
} l4ccsm_ciss_emlpp_end_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   kal_uint8 ss_code;
   kal_uint8 ss_status;
   kal_uint8 clir_option;
   ss_return_struct ss_return;
} l4ccsm_ciss_cli_end_cnf_struct;

typedef struct {
   kal_uint8 ss_status;
   kal_uint8 subaddress_flag;
   l4_addr_bcd_struct address;
   l4_addr_bcd_struct subaddress;
   kal_uint8 bs_code;
} ccbs_list_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   kal_uint8 op_code;
   kal_uint8 ccbs_count;
   ccbs_list_struct ccbs_list[5];
   ss_return_struct ss_return;
} l4ccsm_ciss_ccbs_end_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   kal_uint8 op_code;
   kal_uint8 ussd_dcs;
   kal_uint8 ussd_string[MAX_DIGITS_USSD];
   kal_uint8 ussd_string_length;
   ss_return_struct ss_return;
   kal_bool change_phase_ind;
} l4ccsm_ciss_pussr_end_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   ss_return_struct ss_return;
} l4ccsm_ciss_ussd_end_cnf_struct;

typedef l4ccsm_ciss_ussd_end_cnf_struct l4ccsm_ciss_ussr_end_cnf_struct;
typedef l4ccsm_ciss_ussd_end_cnf_struct l4ccsm_ciss_ussn_end_cnf_struct;
#ifdef __SAT__
typedef l4ccsm_ciss_ussd_end_cnf_struct l4ccsm_ciss_sim_end_cnf_struct;
#endif

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 guidance_info;
} l4ccsm_ciss_cb_fac_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 password[4];
} l4ccsm_ciss_cb_fac_res_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 cause_value;
} l4ccsm_ciss_end_res_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 ton_npi;
   kal_uint8 length;
   kal_uint8 ss_dcs;
   kal_uint8 ss_string[MAX_DIGITS_USSD];
   kal_bool change_phase_req;
   kal_uint8 type_of_modification;
} l4ccsm_ciss_ss_parse_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 opcode;
   kal_uint8 ss_dcs;
   kal_uint8 ss_string[MAX_DIGITS_USSD];
   kal_uint8 type_of_modification;
} l4ccsm_ciss_ss_parse_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 action;
   kal_uint8 line_num;
} l4ccsm_cphs_display_cfu_ind_struct;

#endif


