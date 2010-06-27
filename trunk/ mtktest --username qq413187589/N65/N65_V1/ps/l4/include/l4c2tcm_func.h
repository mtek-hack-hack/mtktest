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
 * L4C2TCM_FUNC.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file handles AT get and query command.
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


#ifndef _L4C2TCM_FUNC_H
#define _L4C2TCM_FUNC_H

#ifndef _TCM_COMMON_H
   #error include tcm_common.h before l4c2tcm_func.h
#endif /* ~_TCM_COMMON_H */

typedef struct
{
    kal_uint8               context_id;
    kal_uint8               apn_length;
    kal_uint8               apn [ MAX_APN_LEN ];
    snd_dcomp_algo_enum     dcomp_algo;      /*atci_dcomp_algo_enum*/
    snd_pcomp_algo_enum     hcomp_algo;      /*atci_hcomp_algo_enum*/
    pdp_addr_type_enum      pdp_type;        /*pdp_type_enum*/
    pdp_addr_len_enum       pdp_addr_len;
    kal_uint8               addr_val[ MAX_PDP_ADDR_LEN ];
} l4c_prim_pdp_info_struct;

typedef struct
{
   kal_uint32	total_rx_data;
   kal_uint32	total_tx_data;
   kal_uint32	last_rx_data;
   kal_uint32	last_tx_data;
} l4c_gprs_statistics_info_struct;

typedef struct
{
   kal_uint8                   length;
   l4c_prim_pdp_info_struct    prim_pdp_info[ MMI_TOT_CONTEXT ];
} l4c_prim_pdp_info_list_struct;


typedef struct
{
    kal_uint8               context_id;      /* child context */
    kal_uint8               prim_context_id;  /* parent context */
    snd_dcomp_algo_enum     dcomp_algo;     /* atci_dcomp_algo_enum */
    snd_pcomp_algo_enum     hcomp_algo;     /* atci_hcomp_algo_enum */
} l4c_sec_pdp_info_struct;

typedef struct
{
   kal_uint8                   length;
   l4c_sec_pdp_info_struct     sec_pdp_info[ MMI_TOT_CONTEXT ];
} l4c_sec_pdp_info_list_struct;

typedef struct
{
    atci_qos_enum            qos_type;          /*atci_qos_enum*/
    kal_uint8                context_id;
    delay_class_enum         delay_class;       /*delay_class_enum*/
    reliability_class_enum   reliability_class; /*reliability_class_enum*/
    peak_throughput_class    peak_throughput;   /*peak_throughput_class*/
    precedence_class_enum    precedence_class;  /*precedence_class_enum*/
    mean_throughput_enum     mean_throughput;   /*mean_throughput_enum*/
} l4c_qos_struct;

typedef struct
{
    atci_qos_enum            qos_type;          /*atci_qos_enum*/
    kal_uint8                context_id;
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
} l4c_eqos_struct;

typedef struct
{
   kal_uint8          length;
   l4c_qos_struct     qos_info[ MMI_TOT_CONTEXT ];
} l4c_qos_list_struct;

typedef struct
{
   kal_uint8          length;
   l4c_eqos_struct     qos_info[ MMI_TOT_CONTEXT ];
} l4c_eqos_list_struct;

typedef struct
{
   kal_uint8 context_id;
   kal_uint8 tot_pf_count;
   l4c_pf_struct pf[8];
} l4c_tft_struct;

/* +CGDCONT */
kal_bool l4ctcm_get_pri_pdp_info(l4c_prim_pdp_info_list_struct *info);

#if 0
/* under construction !*/
#endif

/* +CGDSCONT */
kal_bool l4ctcm_get_sec_pdp_info(l4c_sec_pdp_info_list_struct *info);

kal_bool l4ctcm_test_sec_pdp_info(kal_uint8 **rsp_str);

/* +CGTFT */
kal_bool l4ctcm_set_tft_info(l4c_tft_struct *info);

kal_bool l4ctcm_get_tft_info(l4c_tft_struct *info);

kal_bool l4ctcm_test_tft_info(kal_uint8 const **rsp_str);

/* +CGQREQ / +CGQMIN */
kal_bool l4ctcm_get_qos_info(atci_qos_enum type, l4c_qos_list_struct *info);

#if 0
/* under construction !*/
#endif

/* +CGQREQ / +CGQMIN */
#ifdef __R99__
kal_bool l4ctcm_get_eqos_info(atci_qos_enum type, l4c_eqos_list_struct *info);

kal_bool l4ctcm_test_eqos_info(atci_qos_enum type, kal_uint8 const **rsp_str);

kal_bool l4ctcm_encode_sdu_size(kal_uint16 size, kal_uint16 *val_ptr);

kal_bool l4ctcm_decode_sdu_size(kal_uint16 val, kal_uint16 *size_ptr);

kal_bool l4ctcm_encode_bit_rate(kal_uint16 rate, kal_uint16 *val_ptr);

kal_bool l4ctcm_decode_bit_rate(kal_uint16 val, kal_uint16 *rate_ptr);

kal_bool l4ctcm_encode_transfer_delay(kal_uint16 delay, kal_uint16 *val_ptr);

kal_bool l4ctcm_decode_transfer_delay(kal_uint16 val, kal_uint16 *delay_ptr);

kal_bool l4ctcm_encode_func(kal_uint16 val, kal_uint16 offset, kal_uint16 min, kal_uint16 step, kal_uint16 *result_ptr);
#endif

/* erica: new EM */
kal_uint8 l4ctcm_get_pdp_type(kal_uint8 context_id);

/* +CGPADDR (No set) */
kal_bool l4ctcm_get_pdp_addr(kal_uint8 cid, kal_uint8 *length, kal_uint8 *addr);

/* +EGPPPAUTH */
kal_bool l4ctcm_get_ppp_auth(kal_uint8 context_id, kal_bool *is_chap);

#if 0
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
#endif

kal_bool l4ctcm_test_answer_mode(kal_uint8 const **rsp_str);

kal_bool l4ctcm_test_auto_answer_mode(kal_uint8 const **rsp_str);

kal_bool l4ctcm_test_modify_info(kal_uint8 const **rsp_str);

kal_bool l4ctcm_test_l2p(kal_uint8 const **rsp_str);

kal_bool l4ctcm_get_context_state(kal_uint8 *total_context, kal_uint8 *state_list);

kal_bool l4ctcm_get_empty_gprs_prof(kal_uint8 *empty_gprs_prof_entry);

kal_bool l4ctcm_get_gprs_statistics_info(l4c_gprs_statistics_info_struct *info);

kal_bool check_pdp_context_exist_func(void);

kal_bool check_remote_pdp_context_exist_func(void);

kal_bool l4ctcm_pid_to_cid(kal_uint8 profile_id, kal_uint8 *context_id);

#ifdef __R99__
kal_bool tcm_set_tft_info(kal_uint8 sib_id, l4c_tft_struct *tft);

kal_bool tcm_set_tft_info_peer(kal_uint8 sib_id, l4c_tft_struct *tft, tft_opcode_enum tft_opcode, kal_bool replace_in_use);

kal_bool tcm_set_tft_info_local(kal_uint8 sib_id, l4c_tft_struct *tft, tft_opcode_enum tft_opcode);

kal_bool tcm_check_epi_exist(kal_uint8 epi, mmi_packet_filter_struct *tft_ptr, kal_uint8 *pfi);

kal_bool tcm_check_pfi_exist(kal_uint8 pfi, mmi_packet_filter_struct *tft_ptr);

kal_uint8 tcm_get_primary_context_id(SESSION_INFO_PTR sib_ptr);

tft_opcode_enum tcm_get_tft_opcode(SESSION_INFO_PTR sib_ptr, l4c_tft_struct *tft, kal_bool *replace_in_use);

void tcm_free_tft(void);

void tcm_set_tft_mod(SESSION_INFO_PTR sib_ptr);

void tcm_replace_packet_filter (mmi_packet_filter_struct **sib_tft_ptr, l4c_tft_struct *tft);

void tcm_add_packet_filter (mmi_packet_filter_struct **sib_tft_ptr, l4c_tft_struct *tft);

void tcm_delete_packet_filter(mmi_packet_filter_struct **sib_tft_ptr, kal_uint8 pfi);

mmi_packet_filter_struct* tcm_create_packet_filter(l4c_tft_struct *tft);

void tcm_get_tft_info(SESSION_INFO_PTR sib_ptr, l4c_tft_struct *tft);

void tcm_fill_tft(mmi_packet_filter_struct *tft_ptr, l4c_tft_struct *tft);

void tcm_fill_tft_replace(mmi_packet_filter_struct *use_ptr, mmi_packet_filter_struct *mod_ptr, l4c_tft_struct *tft);

void tcm_fill_packet_filter(mmi_packet_filter_struct *tft_ptr, l4c_tft_struct *tft, kal_uint8 index);
#endif

#endif /* ~_L4C2TCM_FUNC_H */

