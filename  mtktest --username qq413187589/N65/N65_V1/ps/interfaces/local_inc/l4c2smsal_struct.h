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
 *   l4c2smsal_struct.h
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
 *  FILENAME : l4c2smsal_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L4C2SMSAL_STRUCT_H
#define _L4C2SMSAL_STRUCT_H

#if 0
#ifndef _L4C_AUX_STRUCT_H /* for l4c_number_struct */
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MCD__
#ifndef _MCD_L4_COMMON_H /* for l4_addr_bcd_struct */
/* under construction !*/
#endif
#else
#ifndef _L4_COMMON_STRUCT_H /* for l4_addr_bcd_struct */
/* under construction !*/
#endif
#endif /* __MCD__ */
#endif

typedef struct 
{
	kal_uint8  fo;
	kal_uint8  pid;
	kal_uint8  dcs;
	kal_uint8  ori_dcs;

	kal_uint8  vp_format;
	kal_uint8  vp;

	kal_uint16 no_msg_data;
	l4_addr_bcd_struct sca;
	l4_addr_bcd_struct da;

} smsal_submit_msg_hdr_struct;
/* to replace smsal_submit_msg_struct */

typedef struct 
{
	kal_uint8 fo;
	kal_uint8 pid;
	kal_uint8 dcs;
	kal_uint8 ori_dcs;

	kal_uint8 pading;
	kal_uint8 scts[7];

	kal_uint16 no_msg_data;
	l4_addr_bcd_struct sca;
	l4_addr_bcd_struct oa;

} smsal_deliver_msg_hdr_struct;
/* to replace smsal_deliver_msg_struct */

typedef struct 
{
	kal_uint8 fo;
	kal_uint8 pid;
	kal_uint8 dcs;
	kal_uint8 ori_dcs;

	kal_uint8 mr;
	kal_uint8 scts[7];

	kal_uint16 no_msg_data;
	l4_addr_bcd_struct ra;
	kal_uint8 dt[7];
	kal_uint8 st;

} smsal_status_report_msg_hdr_struct;
/* to replace smsal_status_report_msg_struct; */

typedef struct 
{
	kal_uint8 fo;
	kal_uint8 ct;
	kal_uint8 mn;
	kal_uint8 pid;
	kal_uint16 no_msg_data;
	l4_addr_bcd_struct da;
} smsal_command_msg_hdr_struct;
/* to replace smsal_command_msg_struct; */

typedef struct 
{
	kal_uint8 profile_no_tag;
	kal_uint8 profile_no;
	kal_uint8 para_ind;
	kal_uint8 pid;
	kal_uint8 dcs;
	kal_uint8 vp;
	kal_uint8 udhi;
	kal_uint8 da_tag;
	l4_addr_bcd_struct da;
	l4_addr_bcd_struct sc_addr;
} smsal_send_msg_req_hdr_struct;
/* to replace smsal_send_msg_req_struct */

typedef union {
   smsal_deliver_msg_hdr_struct       deliver;
   smsal_submit_msg_hdr_struct        submit;
   smsal_status_report_msg_hdr_struct status_rep;
} smsal_header_info_union;

typedef struct {
    kal_uint16 ref; /* concat. message reference*/
    kal_uint8 total_seg; /* total segments*/
    kal_uint8 seg; /* indicate which segment*/
} smsal_concat_struct;

typedef struct {
    kal_uint8  mti; /* smsal_mti_enum */
    kal_uint8  status; /* Status of message*/
    kal_uint8  storage_type;
    kal_uint16 index; /* Index of message*/
} smsal_inbox_struct;

typedef struct {
    kal_uint8  mti; /* smsal_mti_enum */
    kal_uint8  status; /* Status of message*/
    kal_uint8  storage_type;
    kal_uint16 index; /* Index of message*/
} smsal_outbox_struct;

typedef struct {
    kal_uint16 msg_count; /* Message Count*/
    smsal_inbox_struct inbox_list[40];
} smsal_inbox_list_struct;

typedef struct {
    kal_uint16 msg_count; /* Message Count*/
    smsal_outbox_struct outbox_list[40];
} smsal_outbox_list_struct;

typedef struct {
    kal_uint8 mt; /* MT Service Mode*/
    kal_uint8 mo; /* MO Service Mode*/
    kal_uint8 bm; /* Broadcast Message Service Mode*/
} smsal_service_mode_struct;

typedef struct {
    kal_uint8 mode; /* Buffering Mode*/
    kal_uint8 mt; /* MT Message Route Mode*/
    kal_uint8 ds; /* Status Report Route Mode*/
    kal_uint8 bm; /* Broadcast Message Route Mode*/
} smsal_mt_msg_route_struct;

typedef struct {
    kal_uint8 mem1; /* Storage type for Memory1*/
    kal_uint8 mem2; /* Storage type for Memory2*/
    kal_uint8 mem3; /* Storage type for Memory3*/
} smsal_select_mem_struct;

typedef struct {
    kal_uint8 mem1; /* Storage type for Memory1*/
    kal_uint8 mem2; /* Storage type for Memory2*/
    kal_uint8 mem3; /* Storage type for Memory3*/
    kal_uint16 used1;
    kal_uint16 used2;
    kal_uint16 used3;
    kal_uint16 total1;
    kal_uint16 total2;
    kal_uint16 total3;
} smsal_prefer_storage_struct;

typedef struct {
    l4_name_struct name;
    l4_addr_bcd_struct addr;
    kal_uint8 capability_id;
    kal_uint8 extension_id;
} smsal_mailbox_addr_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Source Code*/
    kal_bool is_sim_change; /* TRUE: if last IMSI changed */
    kal_uint8 init_type;
} l4csmsal_init_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} l4csmsal_de_init_req_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint8  src_id; /* Source Code*/
    kal_uint8  req_type; /* Request Type*/
    kal_uint8  status; /* Status*/
    kal_uint8  change_status; /* change status*/
    kal_uint16 index; /* Message Index*/
} l4csmsal_read_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 dest_no; /* Specify set target, profile_no or line_no*/
    kal_uint16 para_ind; /* Specify which parameters shall be set*/
    kal_uint8 fo;
    kal_uint8 support_concat;
    kal_uint8 direct_display;
    kal_uint8 bearer_serivce;
    smsal_select_mem_struct prefer_mem;
    smsal_mailbox_addr_struct mailbox_addr;
    kal_uint8 vp;
    kal_uint8 pid;
    kal_uint8 dcs;
    l4_addr_bcd_struct sca;
    l4_name_struct profile_name;
    kal_uint8 cbch_req;
    kal_bool  is_all_language_on;
} l4csmsal_set_parameter_req_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  src_id;
    kal_uint8  profile_no;        //if para_ind=SMSAL_PARA_SAVE_PROFILE, only this field is available. (For AT only)
    kal_uint16 para_ind;         /* Specify which parameters shall be set*/
    kal_uint8  pid;               //SMSAL_PARA_PID
    kal_uint8  dcs;               //SMSAL_PARA_DCS
    kal_uint8  vp;                //SMSAL_PARA_VP
    l4_addr_bcd_struct sca;       //SMSAL_PARA_SCA
    l4_name_struct profile_name;  //SMSAL_PARA_PROFILE_NAME
} l4csmsal_set_profile_para_req_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  src_id;
    kal_uint8  dest_no;  /* line_no for mailbox_addr */
    kal_uint16 para_ind; /* Specify which parameters shall be set*/
    kal_uint8  fo;                 //SMSAL_COM_PARA_FO
    kal_uint8  bearer_serivce;     //SMSAL_COM_PARA_BEARER
    kal_uint8  status_report;      //SMSAL_COM_STATUS_REP 
    kal_uint8  reply_path;         //SMSAL_COM_REPLY_PATH 
    kal_uint8  cbch_req;           //SMSAL_COM_CBCH_REQ
    kal_uint8  is_all_language_on; //SMSAL_COM_PARA_ALL_CB_LANG
    smsal_select_mem_struct prefer_mem;     //SMSAL_COM_PARA_PREFER_MEM
    smsal_mailbox_addr_struct mailbox_addr; //SMSAL_COM_PARA_MAILBOX_ADDR
} l4csmsal_set_common_para_req_struct;



typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint8  src_id;
    kal_uint8  req_type;
    kal_uint8  seq_num;
    kal_uint8  fdn_check; //true: FDN enable
    kal_uint8  mms_mode; 
    kal_uint16 reply_index;
    kal_uint16 message_len; /* Length of Message*/
    union {
       smsal_send_msg_req_hdr_struct      submit;
       smsal_command_msg_hdr_struct       command;
    } msg_header;  
} l4csmsal_send_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} l4csmsal_send_abort_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint8  src_id;
    kal_uint8  fdn_check; //true: FDN enable
    kal_uint16 index;
    kal_uint16 reply_index;
    kal_uint8  da_tag; /* Indicate whether to use da as destination address*/
    l4_addr_bcd_struct da; /* Destination Address*/
} l4csmsal_send_from_storage_req_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint8  src_id;
    kal_uint8  status;
    kal_uint8 scts[7];
    kal_uint16 replace_index;
    kal_uint16 message_len; /* Length of Message*/
    smsal_send_msg_req_hdr_struct msg_header;
} l4csmsal_write_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8  del_flag;
    kal_uint16 index;
    kal_uint8  msg_bitmap[480]; /* length is not final value */
    
} l4csmsal_delete_req_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  src_id;
    kal_uint8  is_sms_packed_required;
    l4_addr_bcd_struct sc_addr;
    kal_uint8  tpdu_length;
    kal_uint8  tpdu[175];
} l4csmsal_sat_send_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result; /* Result Code*/
} l4csmsal_init_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result; /* Result Code*/
} l4csmsal_de_init_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 line_no; /* Number of Line*/
    kal_uint8 waiting_num;
    kal_uint8 ind_type;
    kal_bool  is_show_num;
    kal_bool  is_clear;
    kal_bool  is_from_storage;
} l4csmsal_msg_waiting_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 dest; /* Destination Code*/
    kal_uint8 storage_type;
    kal_uint16 index; /* Message Index*/
    kal_uint16 dest_port; 
    kal_uint16 src_port;
    smsal_concat_struct concat_info; /* Concat. Info*/
    
    l4_addr_bcd_struct oa; /* Originating Address */
    
    kal_uint8 mti;
    kal_uint8 scts[7];
    
} l4csmsal_new_msg_index_ind_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  id; /* Id for distinguish CNMA*/
    kal_uint8  mti; /* Message Type Identifier*/
    kal_uint16 message_len; /* Length of Message*/
} l4csmsal_new_msg_pdu_ind_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    kal_uint8   dest; /* Destination Code*/
    kal_uint8   id; /* Id for distinguish CNMA*/
    kal_uint16  index;
    kal_uint8   mti; /* Message Type Identifier*/
    kal_uint8   rmi_use_hex;
    kal_uint8   display_type;
    kal_uint8   storage_type;
    kal_uint16  dest_port; 
    kal_uint16  src_port;
    kal_uint16  message_len; /* Length of Message*/
    smsal_concat_struct concat_info; /* Concat. Info*/
    smsal_header_info_union msg_header;
} l4csmsal_new_msg_text_ind_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  src_id;
    kal_uint8  result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
    kal_uint8  status; /* Message Status*/
    kal_uint8  new_status;  /* For +CMGR and sync. to MMI */
    kal_uint8  mti; /* Message Type Identifier*/
    kal_uint8  storage_type;
    kal_uint8  rmi_use_hex;
    kal_uint16 index; /* For +CMGL*/
    kal_uint16 next_index; /* Indicate the next index*/
    kal_uint16  dest_port; 
    kal_uint16  src_port;
    kal_uint8 scts[7];
    kal_uint8 padding;
    kal_uint16 message_len; /* Length of Message*/
    smsal_concat_struct concat_info; /* Concat. Info*/
    smsal_header_info_union msg_header;
} l4csmsal_read_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
} l4csmsal_set_parameter_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
} l4csmsal_set_profile_para_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
} l4csmsal_set_common_para_cnf_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint8  src_id;
    kal_uint8  result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
    kal_uint8  mr; /* Message reference*/    
    kal_uint8  seq_num;
    kal_uint8  scts[7];
    smsal_concat_struct concat_info; /* Concat. Info*/  

} l4csmsal_send_cnf_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint8  src_id;
    kal_uint8  result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
    kal_uint16 index;
    kal_uint8  status; /* status of msg */
    kal_uint8  storage_type;
} l4csmsal_write_cnf_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  src_id;
    kal_uint8  result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
    kal_uint16 index;
    kal_uint8  del_flag;
    kal_uint8  storage_type;
    kal_uint8  msg_bitmap[480]; /* length is not final value */
} l4csmsal_delete_cnf_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
}l4csmsal_send_abort_cnf_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  type;
} l4csmsal_mem_full_ind_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  type;
} l4csmsal_mem_exceed_ind_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  type;
} l4csmsal_mem_available_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 data[88];
} l4csmsal_de_personalization_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 res; /* SAT response code*/
    kal_uint8 cause; /* Error Cause*/
} l4csmsal_sat_send_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cbch_req;
} l4csmsal_cbch_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint16 mi[40];
    kal_uint16 dcs[15];
    kal_bool mi_mask[40];    
    kal_bool dcs_mask[15];

    /* follows added by Kevin */
    kal_bool mir_mask[15]; 
    kal_uint16 mir[30];    
    kal_uint8  is_all_language_on;
    kal_uint8  para_ind;/* smsal_cb_para_enum */
    
} l4csmsal_cb_update_req_struct;

/* CB UPDATE CNF added by Kevin */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result; /* Result Code*/
    kal_uint16 error_cause; /* Error Cause*/
} l4csmsal_cb_update_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 mi;
    kal_uint8 dcs;
    kal_uint16 msg_length; /* max length is 93 x 15 = 1395 */
    kal_uint8 msg_data[1];
} l4csmsal_cb_msg_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8  dest; /* RMMI or LMMI*/
    kal_uint16 sn;
    kal_uint16 mi;
    kal_uint8  dcs;
    kal_uint8  page;
    kal_uint8  pages;
    kal_uint8  rmi_use_hex;
    kal_uint16 msg_length; /* max length is 93 x 15 = 1395 */
    kal_uint8  msg_data[1];
} l4csmsal_cb_msg_text_ind_struct;

#if !defined(__MTK_3G_MRAT_ARCH__)
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 geography_type;
} l4csmsal_cb_gs_change_ind_struct;
#endif

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 msg_length; 
    kal_uint8  msg_data[1];
} l4csmsal_cb_msg_pdu_ind_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
  
   kal_uint16 dest_mod_id;  
   kal_uint16 dest_port; 
   kal_uint16 src_port;
   kal_uint8  dcs;
   kal_uint8  mti; /* Message Type Identifier*/

   kal_uint8 scts[7];
   smsal_concat_struct concat_info; /* Concat. Info*/  
   l4_addr_bcd_struct oa; /* Originating Address */
   kal_uint16 message_len; /* Length of Message*/
 
}l4csmsal_app_data_ind_struct;   


typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint8  dest; /* Destination Code*/
    kal_uint8  startup_seq_num; 
    kal_uint8  mti; /* Message Type Identifier*/
    kal_uint8  status;
    kal_uint8  storage_type;
    kal_uint8  scts[7];
    kal_uint8  padding;
    kal_uint16 index;
    kal_uint16 message_len; /* Length of Message*/
    kal_uint16 dest_port; 
    kal_uint16 src_port;
    smsal_concat_struct concat_info; /* Concat. Info*/
    smsal_header_info_union msg_header;
} l4csmsal_startup_read_msg_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

	 kal_uint8 access_id;    
    l4_addr_bcd_struct	sc_addr;
	 l4_addr_bcd_struct	da;
} l4csmsal_fdn_check_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8  result; //true: in FDN list(send), false: not in FDN list
    kal_uint16 cause; //PHB_L4C_ERROR
} l4csmsal_fdn_check_rsp_struct;

typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;  
  
   kal_uint8  action;
   kal_uint8  dst_storage;
   kal_uint16 src_index;
}l4csmsal_copy_msg_req_struct;   

/* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;  
  
   kal_uint8  new_status;  /*  smsal_status_enum */
   kal_uint16 index;
}l4csmsal_set_status_req_struct; 

typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;  
  
   kal_uint8  result; /* Result Code*/
   kal_uint16 error_cause; /* Error Cause*/
   kal_uint8  action;
   kal_uint8  dst_storage;
   kal_uint16 src_index;
   kal_uint16 dst_index;
}l4csmsal_copy_msg_cnf_struct;   

/* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;  

   kal_uint16 index;  
   kal_uint8  result; /* Result Code*/
   kal_uint16 error_cause; /* Error Cause*/
}l4csmsal_set_status_cnf_struct;  

typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;  
  
   kal_uint8  action;
}l4csmsal_hz_cb_act_req_struct;   


typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;

   kal_uint8  dest; /* not used */
   kal_uint16 sn;
   kal_uint16 mi;
   kal_uint8  dcs;
   kal_uint8  page;
   kal_uint8  pages;
   kal_uint8  rmi_use_hex; /* not used */
   kal_uint16 msg_length; 
   kal_uint8  msg_data[1];
} l4csmsal_hz_cb_msg_ind_struct;

#endif 


