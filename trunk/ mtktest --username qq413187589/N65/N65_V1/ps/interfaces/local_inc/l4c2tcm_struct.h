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
 * L4C2TCM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of TCM and L4C.
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

#ifndef _L4C2ABM_STRUCT_H
#error pls include l4c2abm_struct.h before l4c2tcm_struct.h
#endif

#ifndef _L4C2TCM_STRUCT_H
#define _L4C2TCM_STRUCT_H

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 app_src;
    kal_uint8 profile_id;
    l4c_gprs_account_info_struct account_info;
} tcm_pdp_activate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_activate_rej_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_modify_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_deactivate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 apn_length;
    kal_uint8 apn[100];
    kal_uint8 dcomp_algo;
    kal_uint8 hcomp_algo;
    kal_uint8 pdp_type;
    kal_uint8 pdp_addr_len;
    kal_uint8 addr_val[16];
} l4ctcm_set_pri_pdp_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 prim_context_id;
    kal_uint8 dcomp_algo;
    kal_uint8 hcomp_algo;
} l4ctcm_set_sec_pdp_info_req_struct;

typedef struct {
    kal_uint8 pfi;
    kal_uint8 epi;
    kal_uint8 src_addr_sb_net_mask_len;
    kal_uint8 src_addr_sb_net_mask[8];
    kal_bool   prot_number_present;
    kal_uint8  prot_number_next_hdr;
    kal_uint8 dst_port_len;
    kal_uint16 dst_port_range[2];
    kal_uint8 src_port_len;
    kal_uint16 src_port_range[2];
    kal_bool   ipsec_spi_present;
    kal_uint32 ipsec_spi;
    kal_uint8 tos_len;
    kal_uint8 tos_traffic_class_mask[2];
    kal_bool   flow_label_present;
    kal_uint32 flow_label;
} l4c_pf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 tot_pf_count;
    l4c_pf_struct pf[8];
} l4ctcm_set_tft_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 qos_type;
    kal_uint8 delay_class;
    kal_uint8 reliability_class;
    kal_uint8 peak_throughput;
    kal_uint8 precedence_class;
    kal_uint8 mean_throughput;
} l4ctcm_set_qos_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 qos_type;
    kal_uint8 traffic_class;
    kal_uint8 delivery_order;
    kal_uint8 delivery_of_err_sdu;
    kal_uint8 max_sdu_size;
    kal_uint8 max_bitrate_up_lnk;
    kal_uint8 max_bitrate_down_lnk;
    kal_uint8 residual_bit_err_rate;
    kal_uint8 sdu_err_ratio;
    kal_uint8 transfer_delay;
    kal_uint8 traffic_hndl_priority;
    kal_uint8 guarntd_bit_rate_up_lnk;
    kal_uint8 guarntd_bit_rate_down_lnk;
} l4ctcm_set_eqos_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
} l4ctcm_start_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;    
    kal_uint8 src_id;
    kal_uint8 is_chap;
} l4ctcm_set_ppp_auth_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8               context_id;
    kal_uint8               src_id;
    kal_uint8 			  name_length;
    kal_uint8 			  name_dcs;
    kal_uint8 			  name[32];
    kal_uint8               apn_length;
    kal_uint8               apn [ 100 ];
    kal_uint8         authentication_type;
    kal_uint8               user_name[16];
    kal_uint8               password[16];
    kal_uint8               dns[4];
} l4ctcm_set_gprs_account_info_req_struct;

/* mtk00714 w0637: AT definition */
typedef struct {
    kal_uint8 		ref_count;
    kal_uint16 		msg_len;
    kal_uint8		src_id;
    kal_uint8           context_id;
    kal_uint16 		undefine_action; //l4c_action_enum
} l4ctcm_undefine_pdp_info_req_struct;

#endif 


