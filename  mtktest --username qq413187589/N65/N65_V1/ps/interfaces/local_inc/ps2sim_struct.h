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
 * PS2SIM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for SIM's message
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
 *  FILENAME : ps2sim_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _PS2SIM_STRUCT_H
#define _PS2SIM_STRUCT_H

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mode;
    kal_uint8 access_id;
    kal_uint8 pin1[8];
} sim_start_req_struct;

typedef struct {
    kal_uint8 chv1_count;
    kal_uint8 chv2_count;
    kal_uint8 ubchv1_count;
    kal_uint8 ubchv2_count;
    kal_uint8 is_chv1_enabled;
    kal_uint8 is_chv1_verified;
    kal_uint8 is_chv2_enabled;
    kal_uint8 is_chv2_verified;
    kal_uint8 chv1_key_ref;
    kal_uint8 chv2_key_ref;
} sim_chv_info_struct;

typedef struct {
    kal_uint8 chv1_status;
    kal_uint8 chv2_status;
    kal_uint8 ubchv1_status;
    kal_uint8 ubchv2_status;
} sim_chv_status_struct;

typedef struct {
    kal_uint8 num_lp;
    kal_uint8 lp_file_type;
    kal_uint8 lp[10];
} sim_lp_struct;

typedef struct {
    kal_uint8 num_ecc;
    kal_uint8 ecc[15];
    kal_uint8 ecc_rec_len;
    kal_uint8 *ecc_ptr;
} sim_ecc_struct;

typedef struct {
    unsigned int no_plmn_data;
    unsigned int plmn_data_size;
    kal_uint8 *plmn_data;
} sim_plmn_sel_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    sim_chv_info_struct chv_info;
    sim_lp_struct lp;
    sim_ecc_struct ecc;
    kal_uint8 iccid[10];
    kal_uint8 access_id;
} sim_start_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cause;
} sim_error_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint8 ef_imsi[9];
    kal_uint8 is_valid_gid1;
    kal_uint8 gid1[20];
    kal_uint8 is_valid_gid2;
    kal_uint8 gid2[20];
/* moved from mmi_ready_ind */
    kal_uint16 num_plmnsel_data; /* zero means invalid! */
    kal_uint8 *plmnsel_data;
    kal_uint16 num_uplmnwact_data; /* zero means invalid! */
    kal_uint8 *uplmnwact_data;
    kal_uint16 num_oplmnwact_data; /* zero means invalid! */
    kal_uint8 *oplmnwact_data;
    kal_uint8 is_valid_dck;
    kal_uint8 dck[16];
    kal_uint8 ef_acc[2];				/* JRDC required [Nick 2006-08-17] */
    kal_uint8 is_sopname_valid;   	/* JRDC required [Nick 2006-08-17] */
    kal_uint8 sopname[10]; 			/* JRDC required [Nick 2006-08-17] */
    kal_uint8 sopname_len;	              /* JRDC required [Nick 2006-08-22] */
    kal_uint8 is_opname_valid;		/* JRDC required [Nick 2006-12-07] */
    kal_uint8 opname[20];			/* JRDC required [Nick 2006-12-07] */
    kal_uint8 opname_len;	              /* JRDC required [Nick 2006-12-07] */

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
#endif /* 0 */
} sim_mmi_security_ind_struct;

typedef struct {
   kal_uint8 alpha_id_size;
   kal_uint8 alpha_id[32];
   kal_uint8 bcd_len;
   kal_uint8 bcd_digit[41];
} sim_addr_struct;

typedef struct {
   kal_uint8 alpha_id_size;
   kal_uint8 alpha_id[21];
   kal_uint8 ton_npi;
   kal_uint8 digit_size;
   kal_uint8 digit[4];//[41];
   kal_uint8 index_level;
   kal_bool network_specific;
   kal_bool premium_rate;
} sim_info_num_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint8 dn_type;
    kal_uint8 phase;
    kal_uint8 is_valid_puct;
    kal_uint8 ef_puct[5];
    kal_uint8 is_spn_valid;
    kal_uint8 spn[17];
    kal_uint8 is_opname_valid;
    kal_uint8 opname[20];
    kal_uint8 is_sopname_valid;
    kal_uint8 sopname[10]; 
   kal_uint8 no_msisdn;        // MSISDN
   sim_addr_struct msisdn[2];
   kal_uint8 no_info_num;      // Information Numbers
   sim_info_num_struct *info_num;
   kal_bool is_valid_csp;
   kal_uint8 csp[22];          // Custom Service Profile
} sim_mmi_ready_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ef_imsi[9];
    kal_uint8 is_valid_ef_kc;
    kal_uint8 ef_kc[9];
    kal_uint8 ef_acc[2];
    kal_uint8 is_valid_ef_loci;
    kal_uint8 ef_loci[11];
    kal_uint8 is_valid_ef_gkc;
    kal_uint8 ef_gkc[9];
    kal_uint8 is_valid_ef_gloci;
    kal_uint8 ef_gloci[14];
    /* Below is adding for 3G */
    kal_uint8 ef_keys[33];      /* Always valid in USIM */
    kal_uint8 ef_keysps[33];  /* Always valid in USIM */
    kal_uint8 ef_hplmn_time;
    /* forbidden plmn */
    kal_uint8 is_valid_ef_fplmn;	 /* Keep for backward compatible */
    kal_uint8 num_of_fplmn; /* Extened to 10 sets of FPLMN for USIM */	
    kal_uint8 ef_fplmn[30];
    /* prefer plmn */
    kal_uint16 no_plmnsel_data;
    kal_uint8 *plmnsel_data;         /* Please don't free this pointer in MM. Keep by SMU! */
    /* user plmn */
    kal_uint16 no_uplmn_data;
    kal_uint8 *uplmn_data;           /* Please don't free this pointer in MM. Keep by SMU! */
    /* operator plmn */
    kal_uint16 no_oplmn_data;
    kal_uint8 *oplmn_data;           /* Please don't free this pointer in MM. Keep by SMU! */
    /* HPLMN */
    kal_uint16 no_hplmn_data;
    kal_uint8 *hplmn_data;           /* Please don't free this pointer in MM. Keep by SMU! */
    kal_bool is_usim;
    kal_bool is_service_27_support;
    kal_bool is_service_38_support;
} sim_mm_ready_ind_struct;
/* GAS: MOD_SIM -> MOD_RRM */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_valid_ms_op_mode; /* !!!Remove for MONZA!!! */
    kal_uint8 ms_op_mode; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_imsi[9];
    kal_uint8 is_valid_hplmn_time; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_hplmn_time; /* !!!Remove for MONZA!!! */
    kal_uint8 is_valid_ef_bcch; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_bcch[16];  /* ONLY for SIM card */
    kal_uint8 ef_acc[2];
    kal_uint8 is_valid_ef_fplmn; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_fplmn[12]; /* !!!Remove for MONZA!!! */
    kal_uint8 is_valid_ef_loci; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_loci[11];
    kal_uint8 is_valid_ef_gloci; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_gloci[14]; /* !!!Remove for MONZA!!! */
    kal_uint16 num_plmnsel_data; /* zero means invalid! *//* !!!Remove for MONZA!!! */
    kal_uint8 *plmnsel_data; /* !!!Remove for MONZA!!! */
    kal_uint16 num_uplmnwact_data; /* zero means invalid! *//* !!!Remove for MONZA!!! */
    kal_uint8 *uplmnwact_data; /* Remove for MONZA */
    kal_uint16 num_oplmnwact_data; /* zero means invalid! */ /* !!!Remove for MONZA!!! */
    kal_uint8 *oplmnwact_data; /* !!!Remove for MONZA!!! */
    /* For MONZA only */	
    kal_bool is_usim;
    kal_bool is_test_sim;
    kal_bool is_gsm_access_allowed; /* for USIM; If SIM inserted, always set to TRUE */
    kal_bool is_valid_ef_psloci; /* If USIM inserted, this is EF-PSLOCI; if SIM inserted, this is EF_LOCIGPRS */
    kal_uint8 ef_psloci[14]; /* If USIM inserted, this is EF-PSLOCI; if SIM inserted, this is EF_LOCIGPRS */
} sim_rr_ready_ind_struct;

/* UAS: MOD_SIM -> MOD_USIME */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool  is_usim;
    kal_bool is_test_sim;
    kal_bool is_gsm_access_allowed;
    kal_uint8 ef_acc[2];
    kal_uint8 ef_imsi[9];
    kal_uint8 ef_start_hfn[6];
    kal_uint8 ef_threshold[3];
    kal_uint8 ef_loci[11];
    kal_bool is_valid_ef_psloci; /* If USIM inserted, this is EF-PSLOCI; if SIM inserted, this is EF_LOCIGPRS */
    kal_uint8 ef_psloci[14]; /* If USIM inserted, this is EF-PSLOCI; if SIM inserted, this is EF_LOCIGPRS */
    kal_uint16 size_ef_netpar;
    kal_uint8 ef_netpar[512];
} usim_urr_ready_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 size_ef_netpar;
    kal_uint8 ef_netpar[512];
} usim_urr_update_netpar_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint16 status_word;
} usim_urr_update_netpar_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 size_ef_netpar;
    kal_uint8 ef_netpar[512];
} usim_urr_write_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint16 status_word;
} usim_urr_write_cnf_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool    cipher_ind;   // 20050202 Benson add for display cipher indication
} sim_mmrr_ready_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sim_cc_ready_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sim_sms_ready_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 random_val[16];
} sim_run_algo_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cipher_key[8];
    kal_uint8 sres[4];
} sim_run_algo_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint8 access_id;
    kal_uint8 path[6];
} sim_read_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint8 data[258]; // 256 + 2 for driver usage in T=1
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 access_id;
    kal_uint8 path[6];
} sim_read_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint8 data[260]; // 255 + 5 for command header space
    kal_uint8 access_id;
    kal_uint8 path[6];
} sim_write_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 access_id;
    kal_uint8 path[6];
} sim_write_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 data[127];
    kal_uint8 data_len;
    kal_uint8 access_id;
    kal_uint8 path[6];
} sim_increase_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 data[258]; // 256 +2 for driver usage in T=1
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint16 length;
    kal_uint8 access_id;    
    kal_uint8 path[6];
} sim_increase_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 op;
    kal_uint8 which_chv;
    kal_uint8 old_value[8];
    kal_uint8 new_value[8];
    kal_uint8 access_id;
} sim_security_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 op;
    kal_uint8 which_chv;
    kal_uint8 access_id;
    sim_chv_info_struct chv_info;
} sim_security_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint16 file_idx;
    kal_uint8 path[6];
    kal_uint8 info_type;
} sim_file_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint16 file_idx;
    kal_uint8 path[6];
    kal_uint8 info_type;
    kal_uint16 length;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint16 file_size;
    kal_uint8 num_of_rec;
    kal_uint8 res_data[15];
} sim_file_info_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 pattern[16];
    kal_uint8 length;
    kal_uint8 mode;
} sim_seek_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 length;
    kal_uint16 result;
    kal_uint8 data[258]; //  256 + 2 for driver usage in T=1
} sim_seek_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 dn_type;
    kal_uint8 switch_on;
    
} sim_dial_mode_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint16 result;
    kal_uint8 dn_type;
    kal_uint8 switch_on;    
} sim_dial_mode_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 opt;
    kal_uint8 access_id;
} sim_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 data[258]; // 256 + 2 for driver usage in T=1
    kal_uint16 length;
} sim_status_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 switch_mode;
} sim_error_test_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 file_idx;
    kal_uint8 access_id;
    kal_uint8 state;		/* 1: read after update */
} sim_read_plmn_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 file_idx;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint16 file_size;
    kal_uint8 file[500]; /* depends on the maximum supported file size of plmn type files */
    kal_uint8 access_id;
    kal_uint8 state;		/* 1: read after update */
} sim_read_plmn_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 file_idx;
    kal_uint16 file_size;
    kal_uint8 file[500];  /* depends on the maximum supported file size of plmn type files */
    kal_uint8 access_id;
} sim_write_plmn_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 file_idx;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 access_id;
} sim_write_plmn_cnf_struct;

/* USIM new interface */
typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8   abs_path[6];
    kal_uint8   pattern[20];
    kal_uint8   p_len;
    kal_uint8   mode;
    kal_uint16 rsp_len;
    kal_uint8   access_id;
} sim_search_rec_req_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8   abs_path[6];
    kal_uint16  result;
    kal_uint16  status_word;
    kal_uint8    rec_list[258]; // 256 + 2 for driver usage in T=1
    kal_uint16  rec_len;
    kal_uint8    access_id;
} sim_search_rec_cnf_struct;

typedef struct {
    kal_uint8    ref_count;
    kal_uint16  msg_len;
    kal_uint16  file_idx;
    kal_uint8   abs_path[6];
    kal_uint8   access_id;
} sim_deactivate_file_req_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8   abs_path[6];
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8   access_id;
} sim_deactivate_file_cnf_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8   abs_path[6];
    kal_uint8   access_id;
} sim_activate_file_req_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint16  file_idx;
    kal_uint8   abs_path[6];
    kal_uint8   access_id;
    kal_uint8   result;
    kal_uint16 status_word;
} sim_activate_file_cnf_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint8   rand[16];
    kal_bool    is_auth_present;
    kal_uint8   auth[16];
} sim_authenticate_req_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8   kc[8];
    kal_uint8   sres[4];
    kal_uint8   ck[16];
    kal_uint8   ik[16];
    kal_uint8   res[16];
    kal_uint8   res_len;
    kal_uint8   auts[16];
    kal_uint8   auts_len;
} sim_authenticate_cnf_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint8   access_id;
    kal_uint8   length;
} sim_get_challenge_req_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint8   access_id;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8   challenge[130]; // 256 +2 for driver usage in T=1
    kal_uint16 length;
} sim_get_challenge_cnf_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint8   access_id;
    kal_uint8   ch_op;
    kal_uint8   ch_id;
} sim_manage_channel_req_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint8   access_id;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8   ch_op;
    kal_uint8   ch_id;
} sim_manage_channel_cnf_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint8	next_type;
    sim_chv_info_struct	chv_info;
} sim_l4c_verify_pin_result_ind_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  ef_imsi[9];
} sim_supc_ready_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool is_sim_inserted;
} sim_status_update_ind_struct;

#endif 


