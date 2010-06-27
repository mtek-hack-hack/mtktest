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

/*******************************************************************************
 * Filename:
 * ---------
 *	mmi_msg_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI message structures.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef __MMI_MSG_STRUCT_H__
#define __MMI_MSG_STRUCT_H__

/*MTK:BEGIN:generate_message_structure*/
/* Call Control Related Messages */
#if defined(__MOD_CSM__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	pin[MAX_SIM_PASSWD_LEN];
	} mmi_cc_reset_acm_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_cc_reset_acm_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint32	acm;
	} mmi_cc_get_acm_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	pin[MAX_SIM_PASSWD_LEN];
		kal_uint32	val;
	} mmi_cc_set_max_acm_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_cc_set_max_acm_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint32	acm_max;
	} mmi_cc_get_max_acm_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint32	ccm;
	} mmi_cc_get_ccm_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	index; /* csmcc_cug_index_enum */
		kal_uint8	mode; /* csmcc_cug_temporary_mode_enum */
		kal_uint8	info; /* csmcc_cug_suppress_enum */
	} mmi_cc_set_cug_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_set_cug_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	index; /* csmcc_cug_index_enum */
		kal_uint8	mode; /* csmcc_cug_temporary_mode_enum */
		kal_uint8	info; /* csmcc_cug_suppress_enum */
	} mmi_cc_get_cug_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode; /* csmcc_crss_req_enum */
		kal_uint8	call_id;
		kal_uint8	source_id;
	} mmi_cc_chld_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		kal_uint8	opcode; /* csmcc_crss_req_enum */
	} mmi_cc_chld_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	op_code; /* l4c_ath_req_enum */
		kal_uint8	source_id;
	} mmi_cc_ath_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		l4c_call_list_struct	call_list;
	} mmi_cc_get_call_list_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_number_struct	dest;
		kal_bool	sub_addr_flag;
		l4c_sub_addr_struct	sub_dest;
	} mmi_cc_call_deflect_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_cc_call_deflect_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	digit;
	} mmi_cc_start_dtmf_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_start_dtmf_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_stop_dtmf_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	digit[80];
	} mmi_cc_start_auto_dtmf_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_start_auto_dtmf_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_uint8	digits[80];
	} mmi_cc_start_auto_dtmf_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
	} mmi_cc_start_auto_dtmf_finish_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	source_id;
	} mmi_cc_ata_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	call_mode; /* clcc_mode_enum */
	} mmi_cc_ata_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_disconnect_aux_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	line;
	} mmi_cc_set_line_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_set_line_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_number_struct	dest;
		kal_uint8	redial_count;
		kal_uint8	call_type; /* csmcc_call_type_enum */
		kal_uint8	clir_flag; /* csmcc_clir_info_enum */
		kal_bool	cug_option;
	} mmi_cc_dial_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_dial_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_number_struct	dest;
		kal_uint8	call_type; /* csmcc_call_type_enum */
		kal_uint8	clir_flag; /* csmcc_clir_info_enum */
		kal_bool	cug_option;
	} mmi_cc_dial_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	call_id;
	} mmi_cc_dial_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	call_mode; /* csmcc_call_mode_enum */
	} mmi_cc_call_modify_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode; /* csmcc_sns_mode_enum */
	} mmi_cc_set_single_num_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_set_single_num_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	mode; /* csmcc_sns_mode_enum */
	} mmi_cc_get_single_num_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_uint32	ccm;
		kal_uint8	warning;
	} mmi_cc_ccm_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	alert;
	} mmi_cc_internal_alert_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		l4c_number_struct	num;
		kal_uint8	call_mode; /* csmcc_call_mode_enum */
		kal_uint8	name_present;
		kal_uint8	cnap_info_exist;
		kal_uint8	tag;
		kal_uint8	name[30];
		kal_uint8	dcs;
		kal_uint8	length;
		kal_uint8	signal;
	} mmi_cc_call_wait_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		l4c_number_struct	num;
		l4c_sub_addr_struct	sub_addr;
		l4c_number_struct	redirect_num;
		kal_uint8	name_present;
		kal_uint8	cnap_info_exist;
		kal_uint8	tag;
		kal_uint8	name[30];
		kal_uint8	dcs;
		kal_uint8	length;
		kal_uint8	auto_answer;
		kal_uint8	call_type;
	} mmi_cc_call_ring_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_number_struct	num;
		l4c_sub_addr_struct	sub_addr;
		kal_uint8	call_type;
		kal_uint8	call_id;
	} mmi_cc_call_connect_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_bool	ccbs;
	} mmi_cc_call_disconnect_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_uint16	cause;
	} mmi_cc_call_release_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	on_off;
		kal_uint8	rat;
	} mmi_cc_speech_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_uint8	type; /* csmcc_notify_ss_type_enum */
		kal_bool	status_present;
		kal_uint8	status;
		kal_bool	notification_present;
		kal_uint8	notification;
	} mmi_cc_notify_ss_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_uint16	index;
	} mmi_cc_notify_ss_cug_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_bool	present;
		l4c_number_struct	addr;
		l4c_sub_addr_struct	sub_addr;
	} mmi_cc_notify_ss_ect_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_uint8	name_present;
		kal_uint8	cnap_info_exist;
		kal_uint8	tag;
		kal_uint8	name[30];
		kal_uint8	dcs;
		kal_uint8	length;
	} mmi_cc_notify_ss_cnap_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_bool	number_present;
		l4c_number_struct	addr;
		kal_bool	sub_addr_present;
		l4c_sub_addr_struct	sub_addr;
		kal_bool	index_present;
		kal_uint8	index;
		kal_bool	bs_code_present;
		kal_uint8	bs_code;
		kal_bool	alert_present;
		kal_uint8	alert_pattern;
	} mmi_cc_notify_ss_ccbs_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
	} mmi_cc_call_accept_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_uint8	action;
		kal_bool	result;
		kal_uint8	cause;
	} mmi_cc_video_call_status_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
	} mmi_cc_rel_comp_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_rel_comp_rsp_struct;
#endif /* defined(__MOD_CSM__) */
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	speed; /* csmcc_bearer_speed_enum */
		kal_uint8	name; /* csmcc_bearer_name_enum */
		kal_uint8	ce; /* csmcc_bearer_ce_enum */
	} mmi_cc_set_bearer_service_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cc_set_bearer_service_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	speed; /* csmcc_bearer_speed_enum */
		kal_uint8	name; /* csmcc_bearer_name_enum */
		kal_uint8	ce; /* csmcc_bearer_ce_enum */
	} mmi_cc_get_bearer_service_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	prof_id;
		kal_bool	dns_addr_present;
		l4c_number_struct	dest;
		kal_uint8	rate;
		kal_uint8	type;
		kal_uint8	csd_module;
		kal_uint8	auth_type;
		kal_uint8	user_id[32];
		kal_uint8	passwd[32];
		kal_uint8	dns[4];
		l4_name_struct	name;
	} mmi_cc_set_csd_profile_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	src_id;
		kal_bool	result;
		kal_uint16	cause;
	} mmi_cc_set_csd_profile_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	prof_id;
	} mmi_cc_get_csd_profile_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		l4c_number_struct	dest;
		kal_uint8	rate;
		kal_uint8	type;
		kal_uint8	csd_module;
		kal_uint8	auth_type;
		kal_uint8	user_id[32];
		kal_uint8	passwd[32];
		kal_uint8	dns[4];
		l4_name_struct	name;
	} mmi_cc_get_csd_profile_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	no_entry;
	} mmi_cc_get_free_csd_profile_num_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	priority;
	} mmi_ss_get_emlpp_priority_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	priority;
	} mmi_ss_emlpp_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	default_pri;
		kal_uint8	max_pri;
	} mmi_ss_emlpp_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	type; /* l4_ss_code_enum */
		kal_uint8	bs_code; /* l4_bs_code_enum */
		kal_uint8	timer;
		l4c_number_struct	dest;
		kal_bool	sub_addr_flag;
		l4c_sub_addr_struct	sub_dest;
	} mmi_ss_call_forward_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	type; /* l4_ss_code_enum */
		kal_uint8	count;
		forwarding_list_struct	list[13];
	} mmi_ss_call_forward_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	bs_code; /* l4_bs_code_enum */
	} mmi_ss_call_wait_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	count;
		kal_uint8	status;
		kal_uint8	list[13]; /* l4_bs_code_enum */
	} mmi_ss_call_wait_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type; /* l4_ss_code_enum */
	} mmi_ss_interrogate_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ss_interrogate_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	status;
	} mmi_ss_cdip_interrogate_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	status;
		kal_uint8	clir_option;
	} mmi_ss_clip_interrogate_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	status;
		kal_uint8	clir_option;
	} mmi_ss_clir_interrogate_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	status;
		kal_uint8	clir_option;
	} mmi_ss_cnap_interrogate_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	status;
		kal_uint8	clir_option;
	} mmi_ss_colp_interrogate_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	status;
		kal_uint8	clir_option;
	} mmi_ss_colr_interrogate_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	type; /* l4_ss_code_enum */
		kal_uint8	bs_code; /* l4_bs_code_enum */
		kal_uint8	passwd[MAX_SIM_PASSWD_LEN];
	} mmi_ss_call_barring_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	type;
		kal_uint8	count;
		barring_list_struct	list[13];
	} mmi_ss_call_barring_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	str[MAX_DIGITS_USSD];
		kal_uint8	dcs; /* smsal_dcs_enum */
		kal_uint8	length;
	} mmi_ss_ussd_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	op_code;
		kal_uint8	dcs;
		kal_uint8	ussd_str[MAX_DIGITS_USSD];
		kal_uint8	length;
	} mmi_ss_ussd_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	dcs; /* smsal_dcs_enum */
		kal_uint8	ussd_string[MAX_DIGITS_USSD];
		kal_uint8	length;
	} mmi_ss_ussr_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	dcs; /* smsal_dcs_enum */
		kal_uint8	ussd_string[MAX_DIGITS_USSD];
		kal_uint8	length;
	} mmi_ss_ussn_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type; /* l4_ss_code_enum */
		kal_uint8	old[MAX_SIM_PASSWD_LEN];
		kal_uint8	new1[MAX_SIM_PASSWD_LEN];
		kal_uint8	new2[MAX_SIM_PASSWD_LEN];
	} mmi_ss_change_password_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
	} mmi_ss_change_password_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	input[MAX_DIGITS_USSD];
		kal_uint8	dcs;
		kal_uint8	length;
		kal_uint8	ip_string[21];
		kal_uint8	source_id;
		kal_uint8	call_type;
		kal_bool	is_sim_operation;
	} mmi_ss_parsing_string_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		l4c_ss_string_info_struct	info;
	} mmi_ss_parsing_string_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	pwd_no;
	} mmi_ss_cb_password_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	geography_type;
	} mmi_sms_cb_gs_change_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	op_code; /* l4_op_code_enum */
		kal_uint8	index;
	} mmi_ss_ccbs_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	para_present;
		kal_uint8	opcode; /* l4_op_code_enum */
		kal_uint8	ccbs_count;
		ccbs_list_struct	list;
	} mmi_ss_ccbs_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ss_abort_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	clir_flag; /* rmmi_clir_enum */
	} mmi_ss_set_clir_flag_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ss_set_clir_flag_rsp_struct;
/* Hardware - Audio Related Service Messages */
#if defined(__MOD_UEM__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	volume_type; /* volume_type_enum */
		kal_uint8	volume_level;
	} mmi_eq_set_volume_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	ret_volume_type; /* volume_type_enum */
	} mmi_eq_set_volume_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	volume_type; /* volume_type_enum */
		kal_uint8	volume_level;
	} mmi_eq_exe_volume_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	volume_type; /* volume_type_enum */
		kal_uint8	volume_level;
	} mmi_eq_volume_change_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	audio_device;
		kal_bool	mute_onoff;
	} mmi_eq_set_mute_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	ret_audio_device;
	} mmi_eq_set_mute_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	audio_device;
		kal_bool	mute_onoff;
	} mmi_eq_exe_mute_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	audio_device;
		kal_bool	mute_onoff;
	} mmi_eq_mute_change_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
	} mmi_eq_set_silent_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_silent_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
	} mmi_eq_set_silent_mode_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	gpio_dev_type; /* gpio_device_enum */
		kal_uint8	gpio_dev_level;
	} mmi_eq_set_gpio_level_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_gpio_level_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	gpio_dev_type; /* gpio_device_enum */
		kal_uint8	gpio_dev_level;
	} mmi_eq_set_gpio_level_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	gpio_dev_type; /* gpio_device_enum */
	} mmi_eq_get_gpio_level_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	gpio_dev_level;
	} mmi_eq_get_gpio_level_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	gpio_dev_type; /* gpio_device_enum */
		kal_uint8	gpio_dev_level;
	} mmi_eq_exe_gpio_level_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_exe_gpio_level_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	gpio_dev_type; /* gpio_device_enum */
		kal_uint8	gpio_dev_level;
	} mmi_eq_exe_gpio_level_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	sound_id;
		kal_uint8	style; /* audio_play_style_enum */
		kal_uint16	identifier;
	} mmi_eq_play_audio_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_play_audio_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
		kal_uint16	identifier;
	} mmi_eq_play_audio_finish_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	sound_id;
	} mmi_eq_stop_audio_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_stop_audio_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8*	melody;
		kal_uint32	len;
		kal_uint8	format;
		kal_uint8	play_style;
		kal_uint16	identifier;
	} mmi_eq_play_audio_stream_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_play_audio_stream_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_stop_audio_stream_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	imelody[MAX_RING_COMPOSE_LEN];
		kal_uint16	len;
		kal_uint8	play_style;
		kal_uint16	identifier;
	} mmi_eq_play_ext_imelody_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_play_ext_imelody_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	gpio_device; /* ext_device_enum */
		kal_bool	on_off;
	} mmi_eq_gpio_detect_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	ext_gpio_device;
	} mmi_eq_gpio_detect_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_gpio_detect_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	on_off;
	} mmi_eq_set_speech_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_speech_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_wchar	file_name[MAX_MELODY_FILE_NAME];
		kal_uint8	style;
		kal_uint16	identifier;
	} mmi_eq_play_audio_by_name_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_play_audio_by_name_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_wchar	file_name[MAX_MELODY_FILE_NAME];
	} mmi_eq_stop_audio_by_name_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_stop_audio_by_name_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		audio_profile_struct	audio_prof;
	} mmi_eq_set_audio_profile_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_set_audio_profile_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		audio_profile_struct	audio_prof_in;
	} mmi_eq_get_audio_profile_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		audio_profile_struct	audio_prof_out;
	} mmi_eq_get_audio_profile_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		audio_param_struct	audio_para;
	} mmi_eq_set_audio_param_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_set_audio_param_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		audio_param_struct	audio_para;
	} mmi_eq_get_audio_param_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_start_adc_all_channel_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_stop_adc_all_channel_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_int32	vbat;
		kal_int32	bat_temp;
		kal_int32	vaux;
		kal_int32	charge_current;
		kal_int32	vcharge;
	} mmi_eq_adc_all_channel_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode; /* audio_mode_enum */
	} mmi_eq_set_audio_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_audio_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	pattern;
		kal_uint8	action;
	} mmi_eq_play_pattern_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_play_pattern_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_hw_profile_struct	hw_profile;
	} mmi_eq_set_hw_level_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_set_hw_level_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		l4c_hw_profile_struct	hw_profile;
	} mmi_eq_get_hw_level_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	on_off;
	} mmi_eq_set_sleep_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_sleep_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	on_off;
	} mmi_eq_set_sleep_mode_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	file_idx;
		kal_uint8	para;
	} mmi_eq_get_ms_imei_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_get_ms_imei_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	data[10];
		kal_uint8	length;
	} mmi_eq_set_ms_imei_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_ms_imei_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_rtc_poweron_state_rsp_struct;
#endif /* defined(__MOD_UEM__) */
/* Hardware - RTC, Clock, Alarm Related Messages */
#if defined(__MOD_UEM__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
		kal_uint8	set_type;
		rtc_alarm_info_struct	info;
	} mmi_eq_set_rtc_time_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_set_rtc_time_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
		kal_uint8	set_type;
		rtc_alarm_info_struct	alarm;
	} mmi_eq_set_rtc_time_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
		kal_uint8	set_type;
		rtc_alarm_info_struct	info;
	} mmi_eq_exe_rtc_timer_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_exe_rtc_timer_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
	} mmi_eq_get_rtc_time_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	num;
		rtc_alarm_info_struct	rtctime[MAX_ALARM_NUM];
	} mmi_eq_get_rtc_time_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
		kal_uint8	rtc_index;
	} mmi_eq_del_rtc_timer_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_del_rtc_timer_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
		kal_uint8	rtc_index;
	} mmi_eq_del_rtc_timer_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
		kal_uint8	rtc_index;
	} mmi_eq_exe_del_rtc_timer_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_exe_del_rtc_timer_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
		kal_uint8	rtc_index;
	} mmi_eq_exe_del_rtc_timer_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_date_set;
		kal_uint8	mode;
	} mmi_eq_set_date_time_format_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_date_time_format_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_date_set;
		kal_uint8	mode;
	} mmi_eq_set_date_time_format_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		void *	timeout_hdlr;
		kal_uint16	time;
		void*	param;
	} mmi_eq_start_timer_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		eventid	id;
		void*	ret_param;
	} mmi_eq_start_timer_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		eventid	event_id;
	} mmi_eq_stop_timer_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_stop_timer_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rtc_type;
		rtc_format_struct	rtc_time;
	} mmi_eq_clock_tick_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		rtc_format_struct	rtc_time;
	} mmi_eq_alarm_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	totalAlarm;
		kal_uint8	activeAlarm;
		mmi_at_alarm_info_struct*	alarmList;
	} mmi_at_alarm_query_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		mmi_at_alarm_info_struct	alarm;
	} mmi_at_alarm_set_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_at_alarm_set_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	alarm_index;
	} mmi_at_alarm_delete_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_at_alarm_delete_res_req_struct;
#endif /* defined(__MOD_UEM__) */
/* Hardware - Keypad, Indicator, LCD Related Messages */
#if defined(__MOD_UEM__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	keycode[32];
		kal_uint8	time;
		kal_uint8	pause;
	} mmi_eq_simulate_key_press_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_simulate_key_press_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	keypad_status; /* keypad_status_enum */
		kal_uint8	keycode; /* keypad_code_enum */
	} mmi_eq_simulate_key_press_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	icon_id; /* indicator_type_enum */
		kal_uint8	value;
	} mmi_eq_set_indicator_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_indicator_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	icon_id; /* indicator_type_enum */
		kal_uint8	value;
	} mmi_eq_set_indicator_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	icon_id; /* indicator_type_enum */
	} mmi_eq_get_indicator_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	value;
	} mmi_eq_get_indicator_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	text_string[UEM_DISPLAY_TEXT_LEN];
	} mmi_eq_display_text_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_display_text_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	text_string[UEM_DISPLAY_TEXT_LEN];
	} mmi_eq_display_text_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		drv_get_key_func	func;
	} mmi_eq_keypad_detect_ind_struct;
#endif /* defined(__MOD_UEM__) */
/* Hardware - Misc Messages */
#if defined(__MOD_UEM__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	lang_code;
	} mmi_eq_set_language_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_set_language_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	lang_code;
	} mmi_eq_set_language_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
		kal_uint8	dcs;
		kal_uint8	text[UEM_GREETING_LEN];
		kal_uint8	length;
	} mmi_eq_set_greeting_text_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_set_greeting_text_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
		kal_uint8	dcs;
		kal_uint8	text[UEM_GREETING_LEN];
		kal_uint8	length;
	} mmi_eq_set_greeting_text_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
	} mmi_eq_set_vibrator_mode_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
	} mmi_eq_set_vibrator_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_set_vibrator_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	country_code;
	} mmi_eq_set_country_code_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_eq_set_country_code_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	country_code;
	} mmi_eq_get_country_code_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	battery_status; /* battery_status_enum */
		kal_uint8	battery_vol;
	} mmi_eq_get_battery_status_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	equip_type; /* equip_id_enum */
	} mmi_eq_get_equip_id_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	equip_id[UEM_EQUIP_ID_LEN];
	} mmi_eq_get_equip_id_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_load_default_config_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	fun;
		kal_uint8	rst;
	} mmi_eq_power_on_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_power_on_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_power_off_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	poweron_mode;
		kal_uint8	battery_level;
		kal_uint8	build_label;
		rtc_format_struct	rtc_time;
		kal_uint8	flightmode_state;
		kal_uint8	dual_sim_mode_setting;
		kal_uint8	dual_sim_uart_setting;
	} mmi_eq_power_on_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	battery_status; /* battery_status_enum */
		kal_uint8	battery_voltage;
	} mmi_eq_battery_status_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	request_type;
		pmic_config_param_struct	request;
	} mmi_eq_pmic_config_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	request_type;
		pmic_config_param_struct	request;
	} mmi_eq_pmic_config_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	status_type;
	} mmi_eq_battery_status_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	request_type;
		rf_test_gsm_param_struct	request;
	} mmi_eq_rf_test_gsm_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	request_type;
		rf_test_gsm_param_struct	request;
	} mmi_eq_rf_test_gsm_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	request_type;
		fm_radio_config_param_struct	request;
	} mmi_eq_fm_radio_config_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	request_type;
		fm_radio_config_param_struct	request;
	} mmi_eq_fm_radio_config_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	request_type;
		rf_test_wifi_param_struct	request;
	} mmi_eq_rf_test_wifi_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	request_type;
		rf_test_wifi_param_struct	request;
	} mmi_eq_rf_test_wifi_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_status;
	} mmi_eq_call_status_req_struct;
#endif /* defined(__MOD_UEM__) */
/* Hardware - NVRAM messages */
#if defined(__MOD_NVRAM__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	file_idx;
		kal_uint16	para;
		kal_uint16	rec_amount;
	} mmi_eq_nvram_read_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	file_idx;
		kal_uint16	length;
		kal_uint8	data[1];
	} mmi_eq_nvram_read_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	file_idx;
		kal_uint16	para;
		kal_uint16	length;
		kal_uint8	data[1];
	} mmi_eq_nvram_write_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	file_idx;
		kal_uint16	para;
	} mmi_eq_nvram_write_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	reset_category;
		kal_uint8	lid;
	} mmi_eq_nvram_reset_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
	} mmi_eq_nvram_reset_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	func_id;
		kal_uint8	ps_port;
		kal_uint8	tst_port_ps;
		kal_uint32	ps_baud_rate;
		kal_uint32	tst_baud_rate_ps;
		kal_bool	High_Speed_SIM_Enabled;
		kal_uint8	swdbg;
		kal_uint8	uart_power_setting;
		kal_uint8	cti_uart_port;
		kal_uint32	cti_baud_rate;
		kal_uint8	tst_port_l1;
		kal_uint32	tst_baud_rate_l1;
	} mmi_eq_set_uart_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_set_uart_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	ps_uart_port;
		kal_uint32	ps_baud_rate;
		kal_uint8	tst_uart_port_ps;
		kal_uint32	tst_baud_rate_ps;
		kal_uint8	cti_uart_port;
		kal_uint32	cti_baud_rate;
		kal_uint8	tst_uart_port_l1;
		kal_uint32	tst_baud_rate_l1;
	} mmi_eq_get_uart_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		module_type	module_id;
		UART_PORT	port;
		kal_uint32	baud_rate;
	} mmi_attach_uart_port_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
	} mmi_attach_uart_port_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		module_type	module_id;
		UART_PORT	port;
	} mmi_detach_uart_port_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
	} mmi_detach_uart_port_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	enable;
	} mmi_eq_dcm_enable_req_struct;
#endif /* defined(__MOD_NVRAM__) */
/* Network Related Messages */
#if defined(__MOD_RAC__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	imei[16];
		kal_uint8	svn[3];
	} mmi_nw_get_imei_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_nw_abort_plmn_list_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type; /* l4crac_attach_type_enum */
		kal_uint8	opcode; /* l4crac_ps_attach_enum */
		kal_bool	is_poweroff;
	} mmi_nw_set_attach_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_nw_set_attach_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type; /* l4crac_attach_type_enum */
	} mmi_nw_get_attach_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	status; /* l4crac_ps_attach_enum */
	} mmi_nw_get_attach_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
	} mmi_nw_set_mobile_class_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_nw_set_mobile_class_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	type;
	} mmi_nw_get_mobile_class_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
	} mmi_nw_set_plmn_select_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_nw_set_plmn_select_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	mode;
	} mmi_nw_get_plmn_select_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode; /* l4crac_cops_opcode_enum */
		kal_uint8	oper[MAX_PLMN_LEN+1];
		kal_uint8	rat;
	} mmi_nw_set_plmn_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	status;
		kal_uint8	plmn[MAX_PLMN_LEN+1];
		kal_uint8	rat;
	} mmi_nw_set_plmn_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	length;
		l4c_rat_plmn_info_struct	list[MAX_PLMN_LIST_LEN];
	} mmi_nw_get_plmn_list_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	oper[MAX_PLMN_LEN+1];
	} mmi_nw_get_current_plmn_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	rssi;
		kal_uint8	ver;
	} mmi_nw_get_signal_level_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	type; /* band_selection_enum */
	} mmi_nw_get_band_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	status; /* l4c_rac_response_enum */
		kal_uint8	plmn[MAX_PLMN_LEN+1];
		kal_uint8	gsm_state;
		kal_uint8	gprs_state;
		kal_uint8	gprs_status; /* l4c_gprs_status_enum */
		kal_uint8	rat;
		kal_uint8	cell_support_egprs;
		kal_uint8	lac[2];
	} mmi_nw_attach_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	lac;
		kal_uint16	cell_id;
		kal_uint8	status;
		kal_uint8	gprs_state;
		kal_uint8	gprs_status; /* l4c_gprs_status_enum */
	} mmi_nw_reg_state_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	level;
		kal_uint8	current_band;
		kal_uint8	rat;
	} mmi_nw_rx_level_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	full_nw_nameP;
		kal_uint8	full_nw_name_dcs;
		kal_bool	full_nw_name_add_ci;
		kal_uint8	full_nw_name_len;
		kal_uint8	full_nw_name[MAX_NW_NAME_LEN];
		kal_uint8	short_nw_nameP;
		kal_uint8	short_nw_name_dcs;
		kal_bool	short_nw_name_add_ci;
		kal_uint8	short_nw_name_len;
		kal_uint8	short_nw_name[MAX_NW_NAME_LEN];
		kal_uint8	nw_time_zoneP;
		kal_uint8	nw_time_zone;
		kal_uint8	nw_time_zone_timeP;
		l4c_nw_time_zone_time_struct	nw_time_zone_time;
		kal_uint8	lsa_idP;
		kal_uint8	lsa_id_len;
		kal_uint8	lsa_id[3];
		kal_uint8	nw_day_light_saving_timeP;
		kal_uint8	nw_day_light_saving_time;
	} mmi_nw_time_zone_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	network_mode;
	} mmi_nw_sel_mode_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	service_status;
	} mmi_nw_mmrr_service_status_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	band;
	} mmi_nw_set_preferred_band_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	status;
	} mmi_nw_set_preferred_band_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type; /* l4c_gprs_connect_type_enum */
	} mmi_nw_set_gprs_connect_type_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_nw_set_gprs_connect_type_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	type; /* l4c_gprs_connect_type_enum */
	} mmi_nw_get_gprs_connect_type_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
	} mmi_nw_pwroff_detach_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cfun_state;
	} mmi_nw_cfun_state_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_nw_cfun_state_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	rat_mode;
	} mmi_nw_get_rat_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rat_mode;
	} mmi_nw_set_rat_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_nw_set_rat_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	prefer_rat;
	} mmi_nw_get_prefer_rat_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	prefer_rat;
	} mmi_nw_set_prefer_rat_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_nw_set_prefer_rat_rsp_struct;
#endif /* defined(__MOD_RAC__) */
/* Security Related Messages */
#if defined(__MOD_SMU__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	imsi[17];
	} mmi_smu_get_imsi_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode; /* sim_security_operation_enum */
		kal_uint8	type; /* smu_security_type_enum */
		kal_uint8	passwd[MAX_SIM_PASSWD_LEN];
	} mmi_smu_lock_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		sim_chv_info_struct	chv_info;
	} mmi_smu_lock_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	pin[MAX_SIM_PASSWD_LEN];
	} mmi_smu_reset_data_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_smu_reset_data_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	dial_mode; /* sim_dn_enum */
	} mmi_smu_get_dial_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	pin_type; /* smu_security_type_enum */
		kal_uint8	pin[MAX_SIM_PASSWD_LEN];
		kal_uint8	new_pin[MAX_SIM_PASSWD_LEN];
	} mmi_smu_verify_pin_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	next_type; /* smu_security_type_enum */
		sim_chv_info_struct	chv_info;
	} mmi_smu_verify_pin_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	name; /* smu_pending_password_id_enum */
	} mmi_smu_get_pin_type_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	index;
		kal_uint8	opcode;
		kal_uint8	oper[MAX_PLMN_LEN+1];
		kal_uint8	rat;
	} mmi_smu_set_preferred_oper_list_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_smu_set_preferred_oper_list_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	index;
		kal_uint16	num;
		kal_uint16	file_idx_req;
	} mmi_smu_get_preferred_oper_list_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	retnum;
		kal_uint8	oper_list[MAX_SUPPORT_EF_PLMNSEL_REC*7];
		kal_uint8	rat_list[MAX_SUPPORT_EF_PLMNSEL_REC*2];
		kal_uint16	file_idx_rsp;
	} mmi_smu_get_preferred_oper_list_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	pin[MAX_SIM_PASSWD_LEN];
		kal_uint8	currency[3];
		kal_uint8	ppu[18];
	} mmi_smu_set_puc_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_smu_set_puc_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	currency[3];
		kal_uint8	ppu[18];
	} mmi_smu_get_puc_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint8	old[MAX_SIM_PASSWD_LEN];
		kal_uint8	new1[MAX_SIM_PASSWD_LEN];
		kal_uint8	new2[MAX_SIM_PASSWD_LEN];
	} mmi_smu_change_password_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		sim_chv_info_struct	chv_info;
	} mmi_smu_change_password_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd;
		kal_uint16	file_id;
		kal_uint8	p1;
		kal_uint8	p2;
		kal_uint8	p3;
		kal_uint8	data[256];
	} mmi_smu_restricted_access_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	sw1;
		kal_uint8	sw2;
		kal_uint16	length;
		kal_uint8	resp[256];
	} mmi_smu_restricted_access_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint8	on_off;
		kal_uint8	pin[MAX_SIM_PASSWD_LEN];
	} mmi_smu_set_dial_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_smu_set_dial_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	file_idx;
		kal_uint8	para;
		kal_uint8	data[260];
		kal_uint16	length;
		kal_uint8	path[6];
	} mmi_smu_write_sim_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_smu_write_sim_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	file_idx;
		kal_uint16	para;
		kal_uint16	length;
		kal_uint8	path[6];
	} mmi_smu_read_sim_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	length;
		kal_uint8	data[260];
	} mmi_smu_read_sim_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_smu_power_off_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
	} mmi_smu_remove_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_smu_remove_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_bool	is_sim_change;
		sim_chv_info_struct	chv_info;
		kal_uint8	cphs_retry_count;
	} mmi_smu_password_required_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	length;
	} mmi_smu_support_plmn_list_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	cause;
	} mmi_smu_fail_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	file_idx;
		kal_uint8	path[6];
	} mmi_smu_read_file_info_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	file_size;
		kal_uint8	num_of_rec;
	} mmi_smu_read_file_info_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		sim_chv_info_struct	chv_info;
		sim_chv_status_struct	chv_status;
	} mmi_smu_check_pin_status_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	num;
		kal_uint8	ecc[35];
		kal_uint8	language[5];
		kal_uint8	alpha_set;
	} mmi_smu_startup_info_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	cipher_ind;
		kal_uint8	is_gsm_conn_exist;
		kal_uint8	gsm_cipher_cond;
		kal_uint8	gprs_cipher_cond;
	} mmi_smu_cipher_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	category;
		kal_uint8	op;
		kal_uint8	key[8];
		kal_uint8	len;
		kal_uint8	data[10];
	} mmi_smu_set_personalization_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	category;
		kal_uint8	op;
		kal_uint8	state;
		kal_uint8	retry_count;
		kal_uint8	num_of_sets;
		kal_uint8	space_of_sets;
	} mmi_smu_set_personalization_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	state[7];
		kal_uint8	retry_count[7];
		kal_uint8	autolock_count[7];
		kal_uint8	num_of_sets[7];
		kal_uint8	total_size_of_cat[7];
		kal_uint8	key_state[7];
		kal_uint8	imsi[16];
		kal_uint8	is_valid_gid1;
		kal_uint8	ef_gid1;
		kal_uint8	is_valid_gid2;
		kal_uint8	ef_gid2;
		kal_uint8	digits_of_mnc;
	} mmi_smu_sml_status_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	next_type;
		sim_chv_info_struct	chv_info;
	} mmi_smu_verify_pin_result_ind_struct;
#endif /* defined(__MOD_SMU__) */
/* PhoneBook Related Messages */
#if defined(__MOD_PHB__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint16	no_data;
		l4_name_struct	name;
	} mmi_phb_get_entry_by_name_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	no_list;
		l4c_phb_entry_struct	list[PHB_MAX_PHB_ENTRIES];
	} mmi_phb_get_entry_by_name_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint8	storage; /* phb_storage_enum */
		kal_uint16	index;
		kal_uint16	record_index;
		kal_uint16	no_data;
	} mmi_phb_get_entry_by_index_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	no_list;
		l4c_phb_entry_struct	list[PHB_MAX_PHB_ENTRIES];
	} mmi_phb_get_entry_by_index_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	storage; /* phb_storage_enum */
	} mmi_phb_set_preferred_storage_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_phb_set_preferred_storage_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	storage; /* phb_storage_enum */
		kal_uint16	used;
		kal_uint16	total;
	} mmi_phb_get_preferred_storage_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint16	no_data;
		l4c_phb_entry_struct	list;
	} mmi_phb_set_entry_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	no_list;
		l4c_phb_entry_struct	list[PHB_MAX_PHB_ENTRIES];
	} mmi_phb_set_entry_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint16	index;
		kal_uint8	no_data;
		kal_uint8	storage;
		kal_bool	del_all;
	} mmi_phb_del_entry_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	no_list;
		l4c_phb_entry_struct	list[PHB_MAX_PHB_ENTRIES];
	} mmi_phb_del_entry_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_number_struct	number;
	} mmi_phb_set_voice_mail_server_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_phb_set_voice_mail_server_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
	} mmi_phb_get_alpha_list_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	list[26];
	} mmi_phb_get_alpha_list_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
	} mmi_phb_get_type_status_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	used;
		kal_uint16	total;
	} mmi_phb_get_type_status_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint8	seq_id;
	} mmi_phb_get_last_number_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	no_list;
		kal_uint8	type;
		kal_uint8	more_data;
		l4c_phb_ln_entry_struct	list[1];
	} mmi_phb_get_last_number_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint8	no_data;
		kal_uint8	index;
		l4c_phb_ln_entry_struct	entry;
	} mmi_phb_set_last_number_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	no_list;
		kal_uint8	type;
	} mmi_phb_set_last_number_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint8	index;
		kal_uint8	no_data;
	} mmi_phb_del_last_number_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	no_list;
	} mmi_phb_del_last_number_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	sim_max_num;
		kal_uint16	phb_max_num;
		kal_uint8	phb_len;
		kal_uint8	fdn_len;
		kal_uint8	bdn_len;
		kal_uint8	owner_len;
	} mmi_phb_startup_finish_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
		kal_uint16	old_index;
		kal_uint16	sim_used;
		kal_uint16	nvram_used;
		kal_uint16	no_list;
		l4c_phb_entry_struct	list[1];
	} mmi_phb_update_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_phb_entries_struct	phb_entries[1];
		kal_uint8	access_id;
	} mmi_phb_startup_read_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	access_id;
	} mmi_phb_startup_read_next_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_phb_startup_read_next_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	sim_max_num;
		kal_uint16	phb_max_num;
		kal_uint8	phb_len;
		kal_uint8	fdn_len;
		kal_uint8	bdn_len;
		kal_uint8	owner_len;
		kal_bool	is_usim;
		kal_bool	is_group_support;
		kal_uint8	anra_support_type;
		kal_uint8	anrb_support_type;
		kal_uint8	anrc_support_type;
		kal_uint8	sne_support_type;
		kal_uint8	email_support_type;
		kal_uint8	group_len;
		kal_uint8	sne_len;
		kal_uint8	email_len;
		kal_uint16	anra_max_num;
		kal_uint16	anrb_max_num;
		kal_uint16	anrc_max_num;
		kal_uint16	sne_max_num;
		kal_uint16	email_max_num;
		kal_uint16	group_max_num;
	} mmi_phb_startup_phase1_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	access_id;
	} mmi_phb_startup_read_next_usim_field_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	num_of_entry;
		l4c_phb_bcd_anr_struct	anr_entry[2000/PHB_ANR_SIZE];
		kal_uint8	access_id;
	} mmi_phb_startup_read_anr_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	num_of_entry;
		l4c_phb_email_struct	email_entry[2000/PHB_EMAIL_SIZE];
		kal_uint8	access_id;
	} mmi_phb_startup_read_email_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	record_index;
		kal_uint16	no_data;
	} mmi_phb_read_email_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	no_list;
		l4c_phb_email_struct*	list;
	} mmi_phb_read_email_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	num_of_entry;
		l4c_phb_entry_struct	gas_entry[GAS_MAX_ENTRIES_COUNT];
		kal_uint8	access_id;
	} mmi_phb_startup_read_gas_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	grp[1000];
		kal_uint8	access_id;
	} mmi_phb_startup_read_grp_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	record_index;
		kal_uint8	group_type;
	} mmi_phb_set_grp_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	record_index;
		kal_uint8	group_type;
	} mmi_phb_set_grp_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint16	no_data;
		l4c_phb_entry_struct	list;
		kal_uint8	update_field;
		l4c_phb_anr_struct	anra;
		l4c_phb_anr_struct	anrb;
		l4c_phb_anr_struct	anrc;
		l4c_phb_email_struct	email;
		l4_name_struct	sne;
		kal_uint8	group_type;
		kal_uint8	hidden_info;
	} mmi_phb_write_usim_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	no_data;
		l4c_phb_entry_struct	list;
		kal_uint8	update_field;
		l4c_phb_anr_struct	anra;
		l4c_phb_anr_struct	anrb;
		l4c_phb_anr_struct	anrc;
		l4c_phb_email_struct	email;
		l4_name_struct	sne;
		kal_uint8	group_type;
		kal_uint8	hidden_info;
	} mmi_phb_write_usim_rsp_struct;
#endif /* defined(__MOD_PHB__) */
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	para_ind;
		kal_uint8	profile_no;
		kal_uint8	pid;
		kal_uint8	dcs;
		kal_uint8	vp;
		l4c_number_struct	sc_addr;
		l4_name_struct	profile_name;
	} mmi_sms_set_profile_params_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_sms_set_profile_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	profile_no;
	} mmi_sms_get_profile_params_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	pid;
		kal_uint8	dcs;
		kal_uint8	vp;
		l4c_number_struct	sc_addr;
		l4_name_struct	profile_name;
	} mmi_sms_get_profile_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	para_ind;
		kal_uint8	fo;
		kal_uint8	bearer_service;
		kal_uint8	status_report;
		kal_uint8	reply_path;
	} mmi_sms_set_common_params_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_sms_set_common_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	fo;
		kal_uint8	bearer_service;
		kal_uint8	status_report;
		kal_uint8	reply_path;
	} mmi_sms_get_common_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	fo;
		kal_uint8	ct;
		kal_uint8	mn;
		kal_uint8	pid; /* smsal_pid_enum */
		l4c_number_struct	dest;
		kal_uint8	length;
		kal_uint8	cmd[SMSAL_MAX_CMD_LEN];
	} mmi_sms_send_command_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		kal_uint8	mr;
		kal_uint8	scts[7];
	} mmi_sms_send_command_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	del_flag; /* smsal_del_flag_enum */
		kal_uint16	index;
		kal_uint8	del_bitmap[480];
		kal_bool	is_background_action;
	} mmi_sms_del_msg_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		kal_uint8	del_flag; /* smsal_del_flag_enum */
		kal_uint16	index;
		kal_uint8	storage_type;
		kal_uint8	del_bitmap[480];
	} mmi_sms_del_msg_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	index;
		kal_bool	change_status;
	} mmi_sms_get_msg_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		smsal_concat_struct concat_info;
		kal_uint8	mti;
		kal_uint8	status;
		kal_uint8	storage_type;
		kal_uint8	fo;
		kal_uint8	scts[7];
		l4c_number_struct	sca_number;
		l4c_number_struct	addr_number;
		kal_uint8	pid;
		kal_uint8	dcs;
		kal_uint8	ori_dcs;
		kal_uint8	vp;
		kal_uint8	mr;
		kal_uint8	dt[7];
		kal_uint8	st;
		kal_uint16	dest_port;
		kal_uint16	src_port;
		kal_uint16	no_msg_data;
		kal_uint8	msg_data[1];
	} mmi_sms_get_msg_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	profile;
		kal_uint16	reply_index;
		l4c_number_struct	dest;
		kal_uint8	para;
		l4c_number_struct	sc_addr;
		kal_uint8	vp;
		kal_uint8	pid; /* smsal_pid_enum */
		kal_uint8	udhi;
		kal_uint8	dcs; /* smsal_dcs_enum */
		kal_uint16	length;
		kal_uint8	msg[SMSAL_MAX_MSG_LEN];
		kal_uint8	seq_num;
		kal_uint8	mms_mode;
	} mmi_sms_send_msg_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		kal_uint8	mr;
		kal_uint8	scts[7];
		kal_uint8	seq_num;
		smsal_concat_struct	concat_info;
	} mmi_sms_send_msg_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	profile;
		kal_uint8	status;
		l4c_number_struct	dest;
		kal_uint8	para;
		l4c_number_struct	sc_addr;
		kal_uint8	scts[7];
		kal_uint8	vp;
		kal_uint8	pid; /* smsal_pid_enum */
		kal_uint8	udhi;
		kal_uint8	dcs; /* smsal_dcs_enum */
		kal_uint16	index;
		kal_uint16	length;
		kal_uint8	msg[SMSAL_MAX_MSG_LEN];
	} mmi_sms_set_msg_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		kal_uint16	index;
		kal_uint8	status;
		kal_uint8	storage_type;
	} mmi_sms_set_msg_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mem1; /* smsal_storage_enum */
		kal_uint8	mem2; /* smsal_storage_enum */
		kal_uint8	mem3; /* smsal_storage_enum */
	} mmi_sms_set_preferred_storage_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		smsal_prefer_storage_struct	param;
	} mmi_sms_set_preferred_storage_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		smsal_prefer_storage_struct	info;
	} mmi_sms_get_preferred_storage_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	enable;
		kal_uint32	port_num;
		kal_uint16	mod_id;
	} mmi_sms_reg_port_num_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		kal_uint32	ret_port_num;
		kal_uint16	ret_mod_id;
	} mmi_sms_reg_port_num_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	fo;
		kal_uint8	scts[7];
		l4c_number_struct	sca_number;
		l4c_number_struct	oa_number;
		kal_uint8	pid; /* smsal_pid_enum */
		kal_uint8	dcs; /* smsal_dcs_enum */
		kal_uint8	ori_dcs;
		kal_uint16	index;
		kal_uint16	dest_port;
		kal_uint16	src_port;
		kal_uint8	mti;
		kal_uint8	display_type;
		kal_uint8	storage_type;
		kal_uint32	concat_info;
		kal_uint16	no_msg_data;
		kal_uint8	msg_data[1];
	} mmi_sms_deliver_msg_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	fo;
		kal_uint8	scts[7];
		kal_uint8	dt[7];
		l4c_number_struct	ra_number;
		kal_uint8	st; /* smsal_st_enum */
		kal_uint8	pid; /* smsal_pid_enum */
		kal_uint8	dcs; /* smsal_dcs_enum */
		kal_uint8	mr;
		kal_uint16	no_msg_data;
		kal_uint8	msg_data[1];
	} mmi_sms_status_report_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
	} mmi_sms_mem_available_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
	} mmi_sms_mem_exceed_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
	} mmi_sms_mem_full_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sms_ready_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	dest_mod_id;
		kal_uint16	dest_port;
		kal_uint16	src_port;
		kal_uint8	dcs;
		kal_uint8	mti;
		kal_uint16	message_len;
		kal_uint32	concat_info[(sizeof(smsal_concat_struct)+3)/4];
		l4c_number_struct	oa;
		kal_uint8	scts[7];
		kal_uint8	msg_data[SMSAL_MAX_MSG_LEN];
	} mmi_sms_app_data_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_bool	is_sim_card_change;
		kal_uint16	in_sim_no;
		kal_uint16	in_me_no;
		kal_uint16	out_sim_no;
		kal_uint16	out_me_no;
		kal_uint16	unread_msg_num;
		kal_uint16	total_sim_num;
		kal_uint16	total_me_num;
	} mmi_sms_get_msg_num_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	profile_no;
		kal_uint8	name_len;
	} mmi_sms_get_profile_num_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sms_abort_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	line_no;
		kal_uint8	waiting_num;
		kal_uint8	ind_type;
		kal_bool	is_show_num;
		kal_bool	is_clear;
		kal_bool	is_from_storage;
	} mmi_sms_msg_waiting_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mailbox_num;
		l4c_number_struct	num_addr;
		l4_name_struct	name;
	} mmi_sms_set_mailbox_address_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_sms_set_mailbox_address_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	mailbox_num;
		kal_uint8	alpha_length;
		l4c_sms_mailbox_info_struct	mailbox_info[2];
	} mmi_sms_get_mailbox_address_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
		kal_uint16	index;
		kal_uint8	status;
		kal_uint8	del_bitmap[480];
	} mmi_sms_sync_msg_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sms_sync_msg_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_sms_send_abort_finish_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sms_startup_read_next_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	startup_seq_num;
		kal_uint8	mti;
		kal_uint8	status;
		kal_uint8	storage_type;
		kal_uint8	fo;
		kal_uint16	index;
		kal_uint8	scts[7];
		l4c_number_struct	addr_number;
		kal_uint8	pid;
		kal_uint8	dcs;
		kal_uint8	ori_dcs;
		kal_uint8	vp;
		kal_uint8	mr;
		kal_uint8	dt[7];
		kal_uint8	st;
		kal_uint16	dest_port;
		kal_uint16	src_port;
		kal_uint32	concat_info;
		kal_uint16	no_msg_data;
		kal_uint8	msg_data[1];
	} mmi_sms_startup_read_msg_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
		kal_uint8	dst_storage;
		kal_uint16	src_index;
	} mmi_sms_copy_msg_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
		kal_uint16	cause;
		kal_uint8	action;
		kal_uint8	dst_storage;
		kal_uint16	src_index;
		kal_uint16	dst_index;
	} mmi_sms_copy_msg_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	change_status;
		kal_uint8	status;
		kal_uint16	start_index;
		kal_uint8	no_msg;
	} mmi_sms_get_msg_list_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		smsal_inbox_list_struct	inbox;
		smsal_outbox_list_struct	outbox;
	} mmi_sms_get_msg_list_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	index;
		kal_bool	addr_present;
		l4c_number_struct	da;
		kal_bool	need_delete;
	} mmi_sms_send_from_storage_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
		kal_uint8	mr;
		kal_uint16	index;
		smsal_concat_struct	concat_info;
	} mmi_sms_send_from_storage_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	new_status;
		kal_uint16	index;
		kal_bool	is_background_action;
	} mmi_sms_set_status_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	error_cause;
		kal_uint16	index;
	} mmi_sms_set_status_rsp_struct;
/* Data Related Messages */
#if defined(__MOD_DATA__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	iws;
		kal_uint8	mws;
		kal_uint8	t1;
		kal_uint8	n2;
		kal_uint8	ver;
		kal_uint8	t4;
	} mmi_df_set_rlp_params_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_df_set_rlp_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_df_get_rlp_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	rah;
		kal_uint8	mfm;
		kal_uint8	mode;
		kal_uint8	llineg;
		kal_uint8	assign;
		kal_uint8	neg_type;
	} mmi_df_set_v120_params_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_df_set_v120_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	rah;
		kal_uint8	mfm;
		kal_uint8	mode;
		kal_uint8	llineg;
		kal_uint8	assign;
		kal_uint8	neg_type;
	} mmi_df_get_v120_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	dir;
		kal_uint8	comp_neg;
		kal_uint16	max_dict;
		kal_uint8	max_str;
	} mmi_df_set_comp_params_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_df_set_comp_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	dir;
		kal_uint8	comp_neg;
		kal_uint16	max_dict;
		kal_uint8	max_str;
	} mmi_df_get_comp_params_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	bearer;
	} mmi_df_set_bearer_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_df_set_bearer_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	bearer;
	} mmi_df_get_bearer_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	format;
		kal_uint8	parity;
	} mmi_df_set_char_framing_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_df_set_char_framing_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	format;
		kal_uint8	parity;
	} mmi_df_get_char_framing_rsp_struct;
#endif /* defined(__MOD_DATA__) */
/* GPRS Related Messages */
#if defined(__MOD_TCM__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode;
		kal_uint8	cid;
	} mmi_ps_act_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_act_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	opcode;
		kal_uint8	cid;
	} mmi_ps_act_test_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_act_test_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	ans;
		kal_uint8	l2p;
		kal_uint8	cid;
	} mmi_ps_answer_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ps_answer_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
	} mmi_ps_set_auto_answer_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ps_set_auto_answer_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	mode;
	} mmi_ps_get_auto_answer_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cid;
	} mmi_ps_modify_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_modify_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	l2p;
		kal_uint8	cid;
	} mmi_ps_enter_data_state_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ps_enter_data_state_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_prim_pdp_info_struct	pdp;
	} mmi_ps_set_definition_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_set_definition_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		l4c_prim_pdp_info_list_struct	info;
	} mmi_ps_get_definition_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_sec_pdp_info_struct	pdp;
	} mmi_ps_set_sec_definition_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_set_sec_definition_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		l4c_sec_pdp_info_list_struct	info;
	} mmi_ps_get_sec_definition_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cid;
	} mmi_ps_get_pdp_addr_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	addr[128];
	} mmi_ps_get_pdp_addr_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_tft_struct	tft;
	} mmi_ps_set_tft_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_set_tft_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		l4c_tft_struct	info;
	} mmi_ps_get_tft_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	qos_type;
		l4c_qos_struct	min;
	} mmi_ps_set_qos_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_set_qos_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	qos_type;
		l4c_eqos_struct	min;
	} mmi_ps_set_eqos_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_set_eqos_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cid;
		kal_uint32	size;
	} mmi_ps_send_data_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ps_send_data_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	status; /* l4c_gprs_status_enum */
		kal_uint8	cell_support_egprs;
	} mmi_ps_gprs_status_update_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	entry_num;
	} mmi_ps_get_gprs_empty_profile_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		l4c_gprs_statistics_info_struct	counter_info;
	} mmi_ps_get_gprs_data_counter_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_gprs_account_info_struct	gprs_account;
	} mmi_ps_set_gprs_data_account_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_set_gprs_data_account_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	profile_id;
	} mmi_ps_get_gprs_data_account_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		l4c_gprs_account_info_struct	gprs_account;
	} mmi_ps_get_gprs_data_account_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_ps_reset_gprs_data_counter_rsp_struct;
#endif /* defined(__MOD_TCM__) */
 /* STK/SAT Related Messages */
#if defined(__SAT__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	priority;
		kal_uint8	clear_text_type;
		kal_uint8	immediate_res;
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint16	no_text_string;
		kal_uint8*	text_string;
		kal_uint8	dcs_of_text_string;
	} mmi_sat_display_text_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	additional_info;
	} mmi_sat_display_text_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_display_text_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_help_info_available;
		kal_uint8	type_of_input;
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint16	no_text_string;
		kal_uint8*	text_string;
		kal_uint8	dcs_of_text_string;
	} mmi_sat_get_inkey_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	is_yes_selected;
		kal_uint8	dcs_of_text_string;
		kal_uint8	no_text_string;
		kal_uint8	text_string[1];
	} mmi_sat_get_inkey_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_get_inkey_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_help_info_available;
		kal_uint8	type_of_input;
		kal_uint8	is_input_revealed_to_user;
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	len_of_min_input;
		kal_uint8	len_of_max_input;
		kal_uint16	no_text_string;
		kal_uint8*	text_string;
		kal_uint8	dcs_of_text_string;
		kal_uint16	no_default_text;
		kal_uint8*	default_text;
		kal_uint8	dcs_of_default_text;
	} mmi_sat_get_input_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	dcs_of_text_string;
		kal_uint8	no_text_string;
		kal_uint8	text_string[1];
	} mmi_sat_get_input_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_get_input_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_help_info_available;
		kal_uint8	is_softkey_preferred;
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	num_of_item;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	dcs_of_alpha_id;
		kal_uint16	no_item_data;
		kal_uint8*	item_data;
		kal_uint8	no_item_icon_id_list;
		kal_uint8*	item_icon_id_list;
		kal_uint8	item_icon_list_attr;
		kal_uint8	no_next_action_ind_list;
		kal_uint8*	next_action_ind_list;
	} mmi_sat_setup_menu_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
	} mmi_sat_setup_menu_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_setup_menu_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_help_info_available;
		kal_uint8	is_softkey_preferred;
		kal_uint8	type_of_presentation;
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	is_item_id_available;
		kal_uint8	item_id;
		kal_uint8	num_of_item;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	dcs_of_alpha_id;
		kal_uint16	no_item_data;
		kal_uint8*	item_data;
		kal_uint8	item_icon_list_attr;
		kal_uint8	no_item_icon_id_list;
		kal_uint8*	item_icon_id_list;
		kal_uint8	no_next_action_ind_list;
		kal_uint8*	next_action_ind_list;
	} mmi_sat_select_item_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	item_id;
	} mmi_sat_select_item_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_select_item_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	tone_id;
		kal_uint32	duration;
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	dcs_of_alpha_id;
		kal_uint8	is_alpha_id_present;
	} mmi_sat_play_tone_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
	} mmi_sat_play_tone_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_play_tone_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	item_id;
		kal_uint8	is_help_info_requested;
	} mmi_sat_menu_select_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
	} mmi_sat_menu_select_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_evdl_idle_screen_available_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	iso639_language[2];
	} mmi_sat_language_selection_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_language_selection_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	browser_termination_cause;
	} mmi_sat_evdl_browser_termination_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_evdl_browser_termination_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	condition;
		kal_uint32	duration;
		kal_uint8	type_of_modification;
		kal_uint8	is_icon1_available;
		sat_icon_struct	icon_info1;
		kal_uint8	is_icon2_available;
		sat_icon_struct	icon_info2;
		kal_uint8	size_of_ccp;
		kal_uint8	ccp[13];
		kal_uint8	size_of_subaddr;
		kal_uint8	subaddr[21];
		kal_uint8	is_alpha_id1_present;
		kal_uint8	no_alpha_id1;
		kal_uint8*	alpha_id1;
		kal_uint8	dcs_of_alpha_id1;
		kal_uint8	no_addr;
		kal_uint8*	addr;
		kal_uint8	is_alpha_id2_present;
		kal_uint8	no_alpha_id2;
		kal_uint8*	alpha_id2;
		kal_uint8	dcs_of_alpha_id2;
	} mmi_sat_call_setup_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	sat_call_type;
		kal_uint8	no_addr;
		kal_uint8	addr[41];
		kal_uint8	no_sub_addr;
		kal_uint8	sub_addr[21];
		kal_uint8	no_ccp;
		kal_uint8	ccp[15];
		kal_uint8	type_of_modification;
	} mmi_sat_call_setup_stage1_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	terminal_res;
		kal_uint8	additional_res;
	} mmi_sat_call_setup_stage1_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	cause;
	} mmi_sat_call_setup_stage2_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_call_setup_stage2_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	is_sms_packed_required;
		kal_uint8	size_of_addr;
		kal_uint8	addr[41];
		kal_uint8	is_alpha_id_present;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	dcs_of_alpha_id;
		kal_uint8	no_sms_tpdu;
		kal_uint8*	sms_tpdu;
	} mmi_sat_send_sms_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	is_sms_packed_required;
		kal_uint8	no_addr;
		kal_uint8	addr[41];
		kal_uint8	tpdu_length;
		kal_uint8	tpdu[175];
	} mmi_sat_send_sms_stage1_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	res;
		kal_uint16	cause;
	} mmi_sat_send_sms_stage1_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	cause;
	} mmi_sat_send_sms_stage2_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_send_sms_stage2_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	type_of_modification;
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	is_alpha_id_present;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	dcs_of_alpha_id;
		kal_uint8	no_ss_string;
		kal_uint8*	ss_string;
	} mmi_sat_send_ss_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	input[MAX_DIGITS_USSD];
		kal_uint8	dcs;
		kal_uint8	length;
		kal_uint8	type_of_modification;
	} mmi_sat_send_ss_stage1_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	res;
		kal_uint8	length;
		kal_uint8	addition_info[255];
	} mmi_sat_send_ss_stage1_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	size_of_additional_info;
		kal_uint8	additional_info[255];
	} mmi_sat_send_ss_stage2_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_send_ss_stage2_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	type_of_modification;
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	is_alpha_id_present;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	dcs_of_alpha_id;
		kal_uint8	no_ussd_string;
		kal_uint8*	ussd_string;
		kal_uint8	dcs_of_ussd_string;
	} mmi_sat_send_ussd_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	input[MAX_DIGITS_USSD];
		kal_uint8	dcs;
		kal_uint8	length;
		kal_uint8	type_of_modification;
	} mmi_sat_send_ussd_stage1_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	res;
		kal_uint8	length;
		kal_uint8	addition_info[255];
	} mmi_sat_send_ussd_stage1_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	size_of_additional_info;
		kal_uint8	additional_info[255];
	} mmi_sat_send_ussd_stage2_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_send_ussd_stage2_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mmi_info_type;
		kal_uint8	is_alpha_id_present;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	dcs_of_alpha_id;
		kal_uint8	len_of_address;
		kal_uint8	address[41];
		kal_uint8	ton;
	} mmi_sat_mmi_info_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
	} mmi_sat_setup_idle_display_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_setup_idle_display_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint16	no_text_string;
		kal_uint8*	text_string;
		kal_uint8	dcs_of_text_string;
	} mmi_sat_setup_idle_display_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	is_alpha_id_present;
		kal_uint8	dcs_of_alpha_id;
		kal_uint8	no_at_command;
		kal_uint8*	at_command;
	} mmi_sat_run_at_command_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	is_alpha_id_present;
		kal_uint8	dcs_of_alpha_id;
		kal_uint8	no_dtmf;
		kal_uint8*	dtmf;
	} mmi_sat_send_dtmf_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	dtmf_digit[MAX_CC_ADDR_BCD_LEN];
		kal_uint8	no_digit;
	} mmi_sat_send_dtmf_stage1_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	terminal_res;
		kal_uint8	cause;
	} mmi_sat_send_dtmf_stage1_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	additional_info;
	} mmi_sat_send_dtmf_stage2_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_send_dtmf_stage2_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_abort_dtmf_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
	} mmi_sat_lang_notify_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_lang_notify_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_language_specified;
		kal_uint8	iso639_language[2];
	} mmi_sat_lang_notify_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	size_of_additional_info;
		kal_uint8	additional_info[255];
	} mmi_sat_launch_browser_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_sat_launch_browser_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	browser_mode;
		kal_uint8	browser_identity;
		kal_uint8	provision_file_id[10];
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	is_alpha_id_present;
		kal_uint8	dcs_of_alpha_id;
		kal_uint8	no_url;
		kal_uint8*	url;
		kal_uint8	no_bearer;
		kal_uint8*	bearer;
		kal_uint16	no_gateway;
		kal_uint8*	gateway;
		kal_uint8	dcs_of_gateway;
	} mmi_sat_launch_browser_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	is_full_changed;
		kal_uint8	refresh_type;
		kal_uint8	num_of_file;
		kal_uint8	file_list[120];
	} mmi_sat_sim_file_change_ind_struct;
#endif /* defined(__SAT__) */
/* STK_CE */
#if defined(__SATCE__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_bool	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	bearer_type;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	is_alpha_id_present;
		kal_uint8	dcs_of_alpha_id;
	} mmi_sat_open_channel_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
		kal_uint8	additional_info;
	} mmi_sat_open_channel_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	terminal_res;
	} mmi_sat_open_channel_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_bool	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	is_alpha_id_present;
		kal_uint8	dcs_of_alpha_id;
	} mmi_sat_close_channel_ind_struct;
typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
	} mmi_sat_close_channel_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	terminal_res;
	} mmi_sat_close_channel_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_bool	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	is_alpha_id_present;
		kal_uint8	dcs_of_alpha_id;
	} mmi_sat_send_data_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
	} mmi_sat_send_data_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	terminal_res;
		kal_uint8	cause;
	} mmi_sat_send_data_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_bool	is_icon_available;
		sat_icon_struct	icon_info;
		kal_uint8	no_alpha_id;
		kal_uint8*	alpha_id;
		kal_uint8	is_alpha_id_present;
		kal_uint8	dcs_of_alpha_id;
	} mmi_sat_recv_data_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	res;
	} mmi_sat_recv_data_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	cmd_detail[5];
		kal_uint8	terminal_res;
		kal_uint8	cause;
	} mmi_sat_recv_data_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	state;
	} mmi_sat_notify_mmi_ind_struct;
#endif /* defined(__SATCE__) */
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	sn;
		kal_uint16	mi;
		kal_uint8	dcs;
		kal_uint8	page;
		kal_uint8	pages;
		kal_uint16	msg_length;
		kal_uint8	msg_data[1];
	} mmi_cb_msg_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	on_off;
	} mmi_cb_subscribe_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_cb_subscribe_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_cb_info_struct	info;
	} mmi_sms_set_cb_mode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_sms_set_cb_mode_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	mode;
		kal_uint8	total_mid_num;
		kal_uint8	total_mir_num;
		kal_uint8	total_dcs_num;
		l4c_cb_info_struct	info;
	} mmi_sms_get_cb_mode_rsp_struct;
/* Engineer Mode-UEM */
#if defined(__MOD_UEM__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	volume_type;
		kal_uint8	volume_level;
		kal_uint8	gain;
	} mmi_em_set_gain_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_em_set_gain_rsp_struct;
#endif /* defined(__MOD_UEM__) */
/* Engineer Mode */
#if defined(__EM_MODE__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mod_id;
		kal_uint32	em_info;
		peer_buff_struct*	info;
	} mmi_em_status_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		module_type	mod_id;
		request_info_type	info_request;
	} mmi_em_start_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	cause;
		kal_uint8	mod_id;
		kal_uint32	info_request;
	} mmi_em_start_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		module_type	mod_id;
		request_info_type	info_request;
	} mmi_em_stop_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	cause;
		kal_uint8	mod_id;
		kal_uint32	info_request;
	} mmi_em_stop_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	num_of_nc_lai;
		rr_em_lai_info_struct	nc_lai[16];
	} mmi_em_set_cell_id_lock_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_em_set_cell_id_lock_rsp_struct;
#endif /* defined(__EM_MODE__) */
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	keypad_status;
		kal_uint8	keypad_code;
	} mmi_em_keypad_event_output_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_em_keypad_event_output_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	color;
	} mmi_em_lcm_test_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	on_off;
	} mmi_em_keypad_event_act_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	on_off;
	} mmi_factory_test_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	op;
		kal_uint8	category;
		kal_uint8	param1;
		kal_uint8	param2;
		kal_uint8	param3;
		kal_uint8	param4[10];
	} mmi_set_mmi_default_prof_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8 	category;
		kal_uint8	param1;
		kal_uint8	param2;
		kal_uint8	param3;
	} mmi_update_mmi_default_prof_value_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_update_mmi_default_prof_value_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	status;
	} mmi_em_cell_resel_suspend_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	cause;
	} mmi_em_cell_resel_suspend_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	cause;
	} mmi_em_cell_resel_resume_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_bool	turn_on_or_off;
		kal_bool	band_indicator;
		kal_uint16	lock_arfcn;
	} mmi_em_get_cell_lock_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	turn_on_or_off;
		kal_bool	band_indicator;
		kal_uint16	lock_arfcn;
	} mmi_em_set_cell_lock_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_em_set_cell_lock_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint16	red;
		kal_uint16	green;
		kal_uint16	blue;
	} mmi_em_rgb_test_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_on;
		kal_uint8	num_of_mod;
		module_type	mod_list[20];
	} mmi_em_nw_event_notify_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_em_nw_event_notify_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	group_id;
		kal_uint32	event_id;
	} mmi_em_nw_event_notify_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	em_feature;
		kal_uint8	em_feature_state;
	} mmi_em_feature_command_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	em_feature;
	} mmi_em_feature_command_rsp_struct;
/* Audio Task - Voice Memo(via FS) */
#if defined(__FS_ON__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_wchar	file_name[MAX_VM_FILE_NAME];
	} mmi_vm_play_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_vm_play_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_wchar	file_name[MAX_VM_FILE_NAME];
		kal_bool	delete_all;
	} mmi_vm_del_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_vm_del_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_wchar	file_name[MAX_VM_FILE_NAME];
	} mmi_vm_append_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_vm_append_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_wchar	old_name[MAX_VM_FILE_NAME];
		kal_wchar	new_name[MAX_VM_FILE_NAME];
	} mmi_vm_rename_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_vm_rename_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
	} mmi_vm_play_finish_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	no_vm;
		kal_wchar	file_list[MAX_VM_FILE_NAME*MAX_NUM_OF_VM_LIST];
		kal_bool	more_entry;
		kal_uint32	free_space;
	} mmi_vm_get_info_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_wchar	file_name[MAX_VM_FILE_NAME];
	} mmi_vm_stop_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_vm_abort_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_wchar	file_name[MAX_VM_FILE_NAME];
	} mmi_vm_pause_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_vm_resume_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	dir;
	} mmi_vm_record_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint16	cause;
	} mmi_vm_record_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
		kal_wchar	file_name[MAX_VM_FILE_NAME];
	} mmi_vm_record_finish_ind_struct;
#endif /* defined(__FS_ON__) */
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
		kal_uint8	line_num;
	} mmi_cphs_display_cfu_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	is_spn_valid;
		kal_uint8	is_spn_RPLMN_required;
		kal_uint8	spn[17];
		kal_uint8	is_opname_valid;
		kal_uint8	opname[21];
		kal_uint8	is_sopname_valid;
		kal_uint8	sopname[11];
		kal_uint8	no_msisdn;
		l4csmu_addr_struct	msisdn[2];
		kal_uint8	no_info_num;
		l4csmu_info_num_struct	info_num[20];
		kal_uint8	is_valid_csp;
		kal_uint8	csp[22];
		kal_uint8	is_puct_valid;
		kal_uint8	ef_puct[5];
		kal_uint8	is_autolock_enable;
		kal_uint8	autolock_result;
		kal_uint8	autolock_remain;
	} mmi_cphs_mmi_info_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	line_id;
	} mmi_cphs_update_als_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	res;
		kal_uint16	cause;
	} mmi_cphs_update_als_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	line;
	} mmi_cphs_display_als_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	digit;
	} wap_start_dtmf_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
		kal_uint8	response;
		kal_uint8	tone;
		kal_uint8	cause_present;
		kal_uint16	cause;
	} wap_start_dtmf_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_number_struct	dest;
		kal_uint8	redial_count;
		kal_uint8	call_type; /* csmcc_call_type_enum */
		kal_uint8	clir_flag; /* csmcc_clir_info_enum */
		kal_bool	cug_option;
	} wap_dial_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint8	call_id;
	} wap_dial_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	type;
		kal_uint16	no_data;
		l4c_phb_entry_struct	list;
	} wap_set_entry_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		l4c_result_struct	result;
		kal_uint16	no_list;
		l4c_phb_entry_struct	list[PHB_MAX_PHB_ENTRIES];
	} wap_set_entry_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	call_id;
	} wap_auto_dtmf_complete_ind_struct;
/* IrDA */
#if defined(__IRDA_SUPPORT__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	wait_duration;
	} mmi_eq_irda_open_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_irda_open_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_irda_close_rsp_struct;
#endif /* defined(__IRDA_SUPPORT__) */
/* USB */
#if defined(__USB_ENABLE__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
		kal_uint32	reserved;
	} mmi_eq_usbconfig_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	mode;
		kal_uint32	reserved;
	} mmi_eq_usbconfig_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
	} mmi_eq_usbdetect_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	app;
		UART_PORT	new_port;
	} mmi_eq_usbuart_switch_port_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_usbuart_switch_port_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
	} mmi_eq_usbdetect_res_req_struct;
#endif /* defined(__USB_ENABLE__) */
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	data_folder; /* l4c_data_dl_folder_enum */
	} mmi_eq_data_dl_filelist_info_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	dload_folder;
		void*	file_list;
		kal_uint8	total_files;
	} mmi_eq_data_dl_filelist_report_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_data_dl_filelist_report_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	data_folder; /* l4c_data_dl_folder_enum */
		kal_uint8	filename[520];
		kal_uint8	action; /* l4c_data_dl_file_action_enum */
	} mmi_eq_data_dl_file_modify_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_data_dl_file_modify_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_data_dl_file_modify_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	data_folder; /* l4c_data_dl_folder_enum */
		kal_uint8	filename[520];
		kal_uint8	action; /* l4c_data_dl_execute_action_enum */
	} mmi_eq_data_dl_execute_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_data_dl_execute_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_data_dl_execute_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	folderId;
		kal_uint8	retrievalMode;
	} wap_mmc_read_folder_status_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
		kal_uint32 	numOfMsg;
		kal_uint32	numOfUnreadMsg;
		kal_uint8	mmsHomeDirectory[100];
		kal_uint8	infoFilePath[100];
	} wap_mmc_read_folder_status_output_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	filePath[100];
	} wap_mmc_upload_msg_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
		kal_uint32	msgId;
	} wap_mmc_upload_msg_output_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint32	msgId;
		kal_uint8	folderId;
	} wap_mmc_delete_msg_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
	} wap_mmc_delete_msg_output_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
		kal_uint8	dcs;
		kal_uint8	text[UEM_GREETING_LEN];
		kal_uint8	length;
	} mmi_eq_query_greeting_text_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	lang_code;
	} mmi_eq_query_language_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
	} mmi_eq_query_silent_mode_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
	} mmi_eq_query_vibrator_mode_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_date;
	} mmi_eq_query_date_time_format_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_date;
		kal_uint8	mode;
	} mmi_eq_query_date_time_format_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	mode;
	} mmi_eq_query_mute_mode_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	poweroff;
		kal_uint8	poweron;
		kal_uint8	rtc_timer;
	} mmi_power_reset_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_at_general_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	pwd[16];
	} mmi_factory_restore_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	src_id;
		kal_uint8	mode;
		kal_uint16	index;
		kal_uint8	file_path[50];
	} mmi_eq_vcard_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
		kal_bool	result;
		kal_uint8	file_path[50];
	} mmi_eq_vcard_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
		kal_uint16	index;
		kal_uint8	file_path[50];
	} mmi_eq_vcalendar_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
		kal_bool	result;
		kal_uint8	cause;
		kal_uint8	number;
		kal_uint8	file_path[50];
	} mmi_eq_vcalendar_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	enable;
	} mmi_eq_str_enable_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	length;
		kal_uint8	data_string[250];
	} mmi_eq_str_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	length;
		kal_uint8	data_string[250];
	} mmi_eq_str_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
		kal_uint8	source_id;
		kal_bool	cmd_from_bt;
		kal_uint8	length;
		kal_uint8	number[50];
		kal_uint8	opcode;
		kal_uint8	call_id;
	} mmi_ucm_at_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	source_id;
		kal_uint8	result;
		kal_uint8	cause;
	} mmi_ucm_at_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	source_id;
		kal_uint8	type;
		kal_uint8	call_id;
		kal_uint8	call_type;
		l4c_number_struct	number;
	} mmi_ucm_general_rcode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	ind_type;
		kal_uint8	event;
	} mmi_ucm_hf_ciev_rcode_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_force;
		kal_wchar*	jad_file_name;
		kal_wchar*	jar_file_name;
	} mmi_java_local_install_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint32	error_code;
	} mmi_java_local_install_res_req_struct;
/* Bluetooth */
#if defined(__BT_SUPPORT__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	name[32];
		kal_uint8	bd_addr[6];
		kal_uint8	dcs;
	} mmi_l4_bt_fcty_set_param_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	bd_addr[6];
		kal_uint8	pin_code[17];
	} mmi_l4_bt_loopback_test_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	on_off;
	} mmi_l4_bt_set_vr_req_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	on_off;
	} mmi_l4_bt_set_vr_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_l4_bt_set_vr_rsp_struct;
#endif /* defined(__BT_SUPPORT__) */
/* HOMEZONE */
#if defined(__HOMEZONE_SUPPORT__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	action;
		kal_bool	is_hz;
		kal_uint8	tag[12];
	} mmi_hz_tag_ind_struct;
#endif /* defined(__HOMEZONE_SUPPORT__) */
/* CTM */
#if defined(__CTM_SUPPORT__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	ctm_interface;
	} mmi_ctm_open_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8 ctm_interface;
	} mmi_ctm_open_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ctm_close_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ctm_connect_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	num_of_char;
		kal_uint16	text[CTM_SEND_TEXT_CHAR_MAX_NUM+1];
	} mmi_ctm_send_text_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ctm_send_text_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	num_of_char;
		kal_uint16	text[CTM_SEND_TEXT_CHAR_MAX_NUM+1];
	} mmi_ctm_recv_text_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_plug_in;
	} mmi_ctm_tty_plug_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_turn_on;
		kal_uint8	ctm_interface;
	} mmi_ctm_set_default_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_ctm_set_default_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_bool	is_turn_on;
		kal_uint8	ctm_interface;
	} mmi_ctm_default_changed_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_bool	is_turn_on;
		kal_uint8	ctm_interface;
	} mmi_ctm_get_default_rsp_struct;
#endif /* defined(__CTM_SUPPORT__) */
/* VOIP */
#if defined(__VOIP__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	result;
		kal_uint8	action;
		void*	string_ptr;
		void*	node_ptr;
		void*	err_id;
	} mmi_voip_at_call_ctrl_approve_res_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_voip_at_call_ctrl_approve_res_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
		void*	string_ptr;
		void*	node_ptr;
		void*	err_id;
	} mmi_voip_at_call_ctrl_approve_ind_struct;
#endif /* defined(__VOIP__) */
/* GEMINI */
#if defined(__GEMINI__)
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	new_sim_config;
	} mmi_smu_sim_status_update_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	is_sim_inserted;
		kal_uint8	dual_sim_mode_setting;
	} mmi_smu_sim_status_update_ind_struct;
#endif /* defined(__GEMINI__) */

/*MTK:END*/

//mtk01616_070508: this is not code gen struct
    typedef struct
    {
		LOCAL_PARA_HDR
		kal_uint16 scrnid;
    }mmi_inject_string_rsp_struct;

/* for MoDIS only */
#ifndef __MTK_TARGET__
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint16	input[1000];
		kal_int32	editor_style;
	} mmi_direct_input_req_struct;
#endif	/* __MTK_TARGET__ */

/* CBM local parameters */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 acct_id;
    kal_uint8  entry_type;
}mmi_cbm_app_entry_bearer_detail_info_ind_struct;

/* for bearer info */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32    acct_id;          /* acct id */
    module_type    mod_id;           /* mod id */
} mmi_cbm_add_bearer_status_notify_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8     index;          /* index */
    kal_bool   result;         /* result */
} mmi_cbm_add_bearer_status_notify_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32    acct_id;          /* acct id */
    kal_uint32    mod_id;           /* mod id */
    kal_uint8     index;
} mmi_cbm_del_bearer_status_notify_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32    acct_id;        /* acct_id */
    kal_bool   result;         /* result */
} mmi_cbm_del_bearer_status_notify_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32    acct_id;                         /* acct_id */
    kal_uint8   status;     /* result */
} mmi_cbm_bearer_status_notify_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32    acct_id;           /* acct id */
    kal_bool   result;            /* result */
} mmi_cbm_always_ask_select_account_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32    acct_id;           /* acct id */
    kal_bool   result;                 /* result */
} mmi_cbm_always_ask_select_account_result_cnf_struct;

#endif


