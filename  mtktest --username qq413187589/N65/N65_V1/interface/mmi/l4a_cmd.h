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
 *
 * Filename:
 * ---------
 *	l4a_cmd.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for l4a_cmd header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifdef __MOD_L4A__
#ifndef __L4A_CMD_H__
#define __L4A_CMD_H__

typedef struct lmmi_string_struct
{
   kal_uint8   index;
   kal_uint8   string_ptr[50];
} lmmi_string_struct;

extern kal_bool l4a_ss_string_req (kal_uint8 src_id,
	kal_uint8	input[MAX_DIGITS_USSD],
	kal_uint8	dcs,
	kal_uint8	length,
	kal_uint8 ip_string[21],
	kal_uint8	source_id,
        kal_uint8 call_type,
        kal_bool is_sim_operation); 

extern kal_bool l4a_cc_exe_ata_req (kal_uint8 src_id,kal_uint8 source_id);

extern kal_bool l4a_cc_exe_ath_req (kal_uint8 src_id,l4c_ath_req_enum op_code,kal_uint8 source_id);

extern kal_bool l4a_cc_exe_chld_req (kal_uint8 src_id,
                                 kal_uint8 opcode,   /* csmcc_crss_req_enum */
                                 kal_uint8 call_id,
                                 kal_uint8 source_id);


//mtk01616_070521
extern kal_bool l4a_sat_send_ss_req (kal_uint8 src_id,
	kal_uint8	input[MAX_DIGITS_USSD],
	kal_uint8	dcs,
	kal_uint8	length,
	kal_uint8 type_of_modification);


extern kal_bool l4a_eq_get_audio_profile_req(kal_uint8 src_id,
										audio_profile_struct* audio_prof_in);

extern void l4a_eq_get_audio_param_lrsp(kal_bool result, audio_param_struct* audio_para);

extern kal_bool l4a_set_timer_req(void* timeout_hdlr, kal_uint16 time, void* param,eventid *id,void** ret_param);
extern void l4a_eq_read_nvram_lrsp (l4c_result_struct result, kal_uint8 file_idx, kal_uint16 length, kal_uint8 *data);
extern void l4a_sms_deliver_msg_ind(kal_uint8 fo, 
										kal_uint8 scts[7],
								 l4c_number_struct sca_number,
								 l4c_number_struct oa_number,
								 kal_uint8 pid,
								 kal_uint8 dcs,
								 kal_uint8 ori_dcs,
								kal_uint16 index,
								kal_uint16 dest_port,
								kal_uint16 src_port,
								kal_uint8 mti,
								kal_uint8 display_type,
								kal_uint8 storage_type,
								kal_uint32 concat_info,
								kal_uint16	no_msg_data,
								kal_uint8	msg_data[1]);
extern void l4a_sms_status_report_ind(
									kal_uint8 fo,
									kal_uint8 scts[7],
									kal_uint8 dt[7],
									l4c_number_struct ra_number,
									kal_uint8 st,
									kal_uint8 pid,
									kal_uint8 dcs,
									kal_uint8 mr,
									kal_uint16 no_msg_data,
									kal_uint8 msg_data[1] );

extern void l4a_sms_startup_read_msg_lind(kal_uint8 startup_seq_num,
										kal_uint8 mti,
										kal_uint8 status,
										kal_uint8 storage_type,
										kal_uint8 fo,
										kal_uint16 index,
										kal_uint8 scts[7],
										l4c_number_struct addr_number,
										kal_uint8 pid,
										kal_uint8 dcs,
										kal_uint8 ori_dcs,
										kal_uint8 vp,
										kal_uint8 mr,
										kal_uint8 dt[7],
										kal_uint8 st,
										kal_uint16 dest_port,
										kal_uint16 src_port,
										kal_uint32 concat_info,
										kal_uint16 no_msg_data,
										kal_uint8 msg_data[1]);

extern void l4a_eq_power_on_lind(kal_uint8  poweron_mode,kal_uint8  battery_level,kal_uint8  build_label,rtc_format_struct *rtc_time, kal_uint8 flightmode_state, kal_uint8 dual_sim_mode_setting, kal_uint8 dual_sim_uart_setting);
extern kal_bool l4a_eq_write_nvram_req(
								kal_uint8 src_id,
                                 kal_uint8 file_idx,
                                 kal_uint16 para,
                                 kal_uint16 length,
								 kal_uint8 *data);
extern kal_bool l4a_smu_get_preferred_oper_list_req(kal_uint8 src_id, kal_uint8 index, kal_uint16 num, kal_uint16 file_idx_req, kal_uint16* retnum, kal_uint8* oper_list, kal_uint8* rat_list, kal_uint16* file_idx_rsp);
extern void l4a_sms_exe_read_msg_lrsp(kal_bool  result,
	kal_uint16 cause,
	smsal_concat_struct concat_info,
	kal_uint8  mti,
	kal_uint8  status,
	kal_uint8 storage_type,
	kal_uint8	fo,
	kal_uint8	scts[7],
	l4c_number_struct	sca_number,
	l4c_number_struct	addr_number,
	kal_uint8	pid,
	kal_uint8	dcs,
	kal_uint8	ori_dcs,
	kal_uint8	vp,
	kal_uint8   mr,
	kal_uint8   dt[7],
	kal_uint8   st,
	kal_uint16 dest_port,
	kal_uint16 src_port,
	kal_uint16	no_msg_data,
	kal_uint8	msg_data[1]);

#ifdef __SAT__

extern void l4a_sat_dspl_text_lind(
	kal_uint8 cmd_detail[5],
    kal_uint8 priority,
    kal_uint8 clear_text_type,
    kal_uint8 immediate_res,
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,

    kal_uint16 no_text_string,
    kal_uint8 *text_string,
    kal_uint8 dcs_of_text_string);

extern void l4a_sat_get_inkey_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_help_info_available,
    kal_uint8 type_of_input,
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,
    kal_uint16 no_text_string,
    kal_uint8 *text_string,
    kal_uint8 dcs_of_text_string
		);
extern void l4a_sat_get_input_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_help_info_available,
    kal_uint8 type_of_input,
    kal_uint8 is_input_revealed_to_user,
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,
    kal_uint8 len_of_min_input,
    kal_uint8 len_of_max_input,
    kal_uint16 no_text_string,
    kal_uint8 *text_string,
    kal_uint8 dcs_of_text_string,
    kal_uint16 no_default_text,
    kal_uint8 *default_text,
    kal_uint8 dcs_of_default_text
		);
extern void l4a_sat_setup_menu_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_help_info_available,
    kal_uint8 is_softkey_preferred,
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,
    kal_uint8 num_of_item,

    kal_uint8 no_alpha_id,
    kal_uint8 *alpha_id,
    kal_uint8 dcs_of_alpha_id,
    kal_uint16 no_item_data,
    kal_uint8 *item_data,
    kal_uint8 no_item_icon_id_list,
    kal_uint8 *item_icon_id_list,
    kal_uint8 item_icon_list_attr,
    kal_uint8 no_next_action_ind_list,
    kal_uint8 *next_action_ind_list
		);
extern void l4a_sat_select_item_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_help_info_available,
    kal_uint8 is_softkey_preferred,
    kal_uint8 type_of_presentation,
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,
    kal_uint8 is_item_id_available,
    kal_uint8 item_id,
    kal_uint8 num_of_item,

    kal_uint8 no_alpha_id,
    kal_uint8 *alpha_id,
    kal_uint8 dcs_of_alpha_id,
    kal_uint16 no_item_data,
    kal_uint8 *item_data,
    kal_uint8 item_icon_list_attr,
    kal_uint8 no_item_icon_id_list,
    kal_uint8 *item_icon_id_list,
    kal_uint8 no_next_action_ind_list,
    kal_uint8 *next_action_ind_list
		);
extern void l4a_sat_play_tone_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 tone_id,
    kal_uint32 duration,
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,
	
    kal_uint8 no_alpha_id,
    kal_uint8 *alpha_id,
    kal_uint8 dcs_of_alpha_id,
	kal_uint8 is_alpha_id_present
		);

//mtk01616_070521
extern void l4a_sat_setup_call_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 condition,
    kal_uint32 duration,
   ///// kal_uint8 is_changed_from_ss,
    kal_uint8 type_of_modification,    
    kal_uint8 is_icon1_available,
    sat_icon_struct icon_info1,
    kal_uint8 is_icon2_available,
    sat_icon_struct icon_info2,
    kal_uint8 size_of_ccp,
    kal_uint8 ccp[13],
    kal_uint8 size_of_subaddr,
    kal_uint8 subaddr[21],

	kal_uint8 is_alpha_id1_present,
    kal_uint8 no_alpha_id1,
    kal_uint8 *alpha_id1,
    kal_uint8 dcs_of_alpha_id1,
    kal_uint8 no_addr,
    kal_uint8 *addr,
	kal_uint8 is_alpha_id2_present,
    kal_uint8 no_alpha_id2,
    kal_uint8 *alpha_id2,
    kal_uint8 dcs_of_alpha_id2
		);

extern void l4a_sat_send_sms_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,
    kal_uint8 is_sms_packed_required,
    kal_uint8 size_of_addr,
    kal_uint8 addr[41],

	kal_uint8 is_alpha_id_present,
    kal_uint8 no_alpha_id,
    kal_uint8 *alpha_id,
    kal_uint8 dcs_of_alpha_id,
    kal_uint8 no_sms_tpdu,
    kal_uint8 *sms_tpdu
		);

//mtk01616_070521
extern void l4a_sat_send_ss_lind(
    kal_uint8 cmd_detail[5],
////    kal_uint8 is_changed_from_setupcall,    
    kal_uint8 type_of_modification,    
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,

	kal_uint8 is_alpha_id_present,
    kal_uint8 no_alpha_id,
    kal_uint8 *alpha_id,
    kal_uint8 dcs_of_alpha_id,
    kal_uint8 no_ss_string,
    kal_uint8 *ss_string
		);

//mtk01616_070521
extern void l4a_sat_send_ussd_lind(
    kal_uint8 cmd_detail[5],
    ////    kal_uint8 is_changed_from_setupcall,    
    kal_uint8 type_of_modification,    
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,
	kal_uint8 is_alpha_id_present,
    kal_uint8 no_alpha_id,
    kal_uint8 *alpha_id,
    kal_uint8 dcs_of_alpha_id,
    kal_uint8 no_ussd_string,
    kal_uint8 *ussd_string,
	kal_uint8 dcs_of_ussd_string
		);
extern void l4a_sat_mmi_info_lind(
    kal_uint8 mmi_info_type,

	kal_uint8 is_alpha_id_present,
    kal_uint8 no_alpha_id,
    kal_uint8 *alpha_id,
    kal_uint8 dcs_of_alpha_id,
    kal_uint8 len_of_address,
    kal_uint8 address[41],
    kal_uint8 ton
		);
extern void l4a_sat_setup_idle_dspl_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,

	kal_uint16 no_text_string,
	kal_uint8 *text_string,
	kal_uint8 dcs_of_text_string
		);
extern void l4a_sat_run_at_command_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,

	kal_uint8 no_alpha_id,
	kal_uint8 *alpha_id,
	kal_uint8 is_alpha_id_present,
	kal_uint8 dcs_of_alpha_id,
	kal_uint8 no_at_command,
	kal_uint8 *at_command
		);
extern void l4a_sat_send_dtmf_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,

	kal_uint8 no_alpha_id,
	kal_uint8 *alpha_id,
	kal_uint8 is_alpha_id_present,
	kal_uint8 dcs_of_alpha_id,

	kal_uint8 no_dtmf,
	kal_uint8 *dtmf
	);		
extern void l4a_sat_lang_notify_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_language_specified,
    kal_uint8 iso639_language[2]
		);

extern void l4a_sat_launch_browser_lind(
    kal_uint8 cmd_detail[5],
    kal_uint8 is_icon_available,
    sat_icon_struct icon_info,
    kal_uint8 browser_mode,
    kal_uint8 browser_identity,
    kal_uint8 provision_file_id[10],

	kal_uint8 no_alpha_id,
	kal_uint8 *alpha_id,
	kal_uint8 is_alpha_id_present,
	kal_uint8 dcs_of_alpha_id,

	kal_uint8 no_url,
	kal_uint8 *url,

	kal_uint8 no_bearer,
	kal_uint8 *bearer,

	kal_uint16 no_gateway,
	kal_uint8 *gateway,
	kal_uint8 dcs_of_gateway
		);

extern void l4a_sat_no_other_cmd_lind(void);

extern void l4a_sat_open_channel_lind(
    kal_uint8 cmd_detail[5],
    kal_bool is_icon_available,
    sat_icon_struct icon_info,
    kal_uint8	bearer_type,

	kal_uint8 no_alpha_id,
	kal_uint8 *alpha_id,
	kal_uint8 is_alpha_id_present,
	kal_uint8 dcs_of_alpha_id
		);

extern void l4a_sat_close_channel_lind(
    kal_uint8 cmd_detail[5],
    kal_bool is_icon_available,
    sat_icon_struct icon_info,
////    kal_uint8	state,
	kal_uint8 no_alpha_id,
	kal_uint8 *alpha_id,
	kal_uint8 is_alpha_id_present,
	kal_uint8 dcs_of_alpha_id
		);

extern void l4a_sat_send_data_lind(
    kal_uint8 cmd_detail[5],
    kal_bool is_icon_available,
    sat_icon_struct icon_info,    
	kal_uint8 no_alpha_id,
	kal_uint8 *alpha_id,
	kal_uint8 is_alpha_id_present,
	kal_uint8 dcs_of_alpha_id
		);

extern void l4a_sat_recv_data_lind(
    kal_uint8 cmd_detail[5],    
    kal_bool is_icon_available,
    sat_icon_struct icon_info,
	kal_uint8 no_alpha_id,
	kal_uint8 *alpha_id,
	kal_uint8 is_alpha_id_present,
	kal_uint8 dcs_of_alpha_id
		);

extern kal_bool l4a_sat_dspl_text_res(
								kal_uint8 cmd_detail[5],
								kal_uint8 res,
								kal_uint8 additional_info);
extern kal_bool l4a_sat_get_inkey_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,
									kal_uint8 is_yes_selected,

									kal_uint8 dcs_of_text_string,
									kal_uint8 no_text_string,
									kal_uint8 text_string[1]
									);
extern kal_bool l4a_sat_get_input_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,

									kal_uint8 dcs_of_text_string,
									kal_uint8 no_text_string,
									kal_uint8 text_string[1]
									);
extern kal_bool l4a_sat_setup_menu_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res

								);
extern kal_bool l4a_sat_select_item_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,
									kal_uint8 item_id
								 );
extern kal_bool l4a_sat_play_tone_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res
								);
extern kal_bool l4a_sat_exe_menu_select_req(
									 kal_uint8 item_id,
									 kal_uint8 is_help_info_requested
									 );
//mtk01616_070521
extern kal_bool l4a_sat_call_setup_req(
								kal_uint8 sat_call_type,
								kal_uint8 no_addr,
								kal_uint8 addr[41],
								kal_uint8 no_sub_addr,
								kal_uint8 sub_addr[21],
								kal_uint8 no_ccp,
								kal_uint8 ccp[15],
								kal_uint8 type_of_modification
								);
extern kal_bool l4a_sat_setup_call_res(
								kal_uint8 cmd_detail[5],
								kal_uint8 res,
								kal_uint8 cause
								);
extern kal_bool l4a_sat_send_sms_req(
								kal_uint8 is_sms_packed_required,
								kal_uint8 no_addr,
								kal_uint8 addr[41],
								kal_uint8 tpdu_length,
								kal_uint8 tpdu[175]
							  );
extern kal_bool l4a_sat_send_sms_res(
							  kal_uint8 cmd_detail[5],
							  kal_uint8 res,
							  kal_uint8 cause
							  );
extern kal_bool l4a_sat_send_ss_res(
							 kal_uint8 cmd_detail[5],
							 kal_uint8 res,
							 kal_uint8 size_of_additional_info,
							 kal_uint8 additional_info[255]
							 );
//paul, ussd
//mtk01616_070521
extern kal_bool l4a_sat_send_ussd_req(
	kal_uint8	input[MAX_DIGITS_USSD],
	kal_uint8	dcs,
	kal_uint8	length,
	kal_uint8 type_of_modification);
//paul, ussd
extern kal_bool l4a_sat_send_ussd_res(
							  kal_uint8 cmd_detail[5],
							  kal_uint8 res,
							 kal_uint8 size_of_additional_info,
							 kal_uint8 additional_info[255]
							   );
extern kal_bool l4a_sat_setup_idle_dspl_res(
							 kal_uint8 cmd_detail[5],
							 kal_uint8 res
					  		);
extern kal_bool l4a_sat_run_at_command_res(
								kal_uint8 cmd_detail[5],
								kal_uint8 res,
								kal_uint8 size_of_at_response,
								kal_uint8 at_response[240]
								);
extern kal_bool l4a_sat_lang_notify_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res
								);

#endif // __SAT__


/////////////////////////////////////
// the follow codes will be removed
// BEGIN:REMOVE
kal_bool l4a_eq_set_gpio_level_req (kal_uint8 src_id, kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);
void l4a_eq_set_gpio_level_req_ind (kal_uint8 gpio_dev_type,   kal_uint8 gpio_dev_level);
void l4a_eq_exe_rtc_delete_req_ind (kal_uint8 rtc_type,kal_uint8 rtc_index);
// END:REMOVE
/////////////////////////////////////
kal_bool l4a_eq_exe_volume_req(kal_uint8 src_id,
                                kal_uint8 volume_type,
                                kal_uint8 volume_level,
								kal_uint8 *ret_volume_type);

kal_bool l4a_eq_exe_mute_mode_req(kal_uint8 src_id, kal_uint8 audio_device, kal_bool mute_onoff,kal_uint8 *ret_audio_device);
void l4a_eq_volume_change_ind( kal_uint8 volume_type, kal_uint8 volume_level);
void l4a_eq_mute_change_ind(kal_uint8  audio_device,kal_bool  mute_onoff);
void l4a_cb_msg_lind(kal_uint16 sn, kal_uint16 mi,kal_uint8 dcs,kal_uint8 page, kal_uint8 pages, kal_uint16 msg_length,kal_uint8 *msg_data);
extern void l4a_phb_exe_read_ln_entry_lrsp (l4c_result_struct result,
                                    kal_uint8 no_list,
                                    kal_uint8 type,
                                    kal_uint8 more_data,
                                    l4c_phb_ln_entry_struct *list);

extern void l4a_phb_exe_write_ln_entry_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list
                                    /*l4c_phb_ln_entry_struct *list*/,kal_uint8 type);

extern void l4a_phb_exe_delete_ln_entry_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list
                                    /*l4c_phb_ln_entry_struct *list*/);

extern kal_bool l4a_wap_cc_send_dtmf_req(kal_uint8 src_id, kal_uint8 digit);
extern kal_bool l4a_wap_cc_stop_dtmf_req(kal_uint8 src_id);
extern kal_bool l4a_wap_cc_call_setup_req(kal_uint8 src_id, l4c_number_struct dest, kal_uint8 redial_count, kal_uint8 call_type, kal_uint8 clir_flag, kal_bool cug_option);
extern kal_bool l4a_wap_phb_exe_write_entry_req(kal_uint8 src_id, kal_uint8 type, kal_uint16 no_data, l4c_phb_entry_struct* list);

#ifdef VM_SUPPORT
#ifndef __FS_ON__
extern kal_bool l4a_eq_vm_get_info_nofs_req (kal_uint8 src_id);
extern kal_bool l4a_eq_vm_record_nofs_req (kal_uint8 src_id,kal_uint8 dir);
extern kal_bool l4a_eq_vm_stop_nofs_req (kal_uint8 src_id);
extern kal_bool l4a_eq_vm_abort_nofs_req (kal_uint8 src_id);
extern kal_bool l4a_eq_vm_pause_nofs_req (kal_uint8 src_id);
extern kal_bool l4a_eq_vm_resume_nofs_req (kal_uint8 src_id);
extern kal_bool l4a_eq_vm_play_nofs_req (kal_uint8 src_id, kal_uint8 fileid);
extern kal_bool l4a_eq_vm_delete_nofs_req (kal_uint8 src_id,
                                      kal_uint8 fileid,
                                      kal_bool delete_all);
extern kal_bool l4a_eq_vm_append_nofs_req (kal_uint8 src_id, kal_uint8 fileid);

extern void l4a_eq_vm_record_nofs_lrsp(kal_bool result, kal_uint16 cause);
extern void l4a_eq_vm_play_nofs_lrsp(kal_bool result, kal_uint16 cause);
extern void l4a_eq_vm_delete_nofs_lrsp(kal_bool result, kal_uint16 cause);
extern void l4a_eq_vm_abort_nofs_lrsp(kal_bool result, kal_uint16 cause);
extern void l4a_eq_vm_resume_nofs_lrsp(kal_bool result, kal_uint16 cause);
extern void l4a_eq_vm_append_nofs_lrsp(kal_bool result, kal_uint16 cause);
extern void l4a_eq_vm_rename_nofs_lrsp(kal_bool result, kal_uint16 cause);
extern void l4a_eq_vm_get_info_nofs_lrsp(kal_uint32 index, kal_uint32 time);
extern void l4a_eq_vm_stop_nofs_lrsp(l4c_result_struct result, kal_uint8 file_id);
extern void l4a_eq_vm_pause_nofs_lrsp(l4c_result_struct result, kal_uint8 file_id);

extern void l4a_eq_vm_record_finish_nofs_lind (kal_uint8 result, kal_uint8 file_id);
extern void l4a_eq_vm_play_finish_nofs_lind (kal_uint8 result);
#endif //!__FS_ON__
#endif //VM_SUPPORT

extern void l4a_cphs_mmi_info_lind(kal_uint8 is_spn_valid,     // SPN
                               kal_uint8 is_spn_RPLMN_required,
							   kal_uint8 *spn,
							   kal_uint8 is_opname_valid,  // OPN
							   kal_uint8 *opname,
							   kal_uint8 is_sopname_valid, // sOPN
							   kal_uint8 *sopname,
							   kal_uint8 no_msisdn,        // MSISDN
							   l4csmu_addr_struct msisdn[2],
	                                             kal_uint8 no_info_num,
	                                             l4csmu_info_num_struct *info_num,						   
							   kal_uint8 is_valid_csp,
							   kal_uint8 *csp,
							   kal_uint8 is_puct_valid,
							   kal_uint8 *ef_puct,
							   kal_uint8 is_autolock_enable,
							   kal_uint8 autolock_result,
							   kal_uint8 autolock_remain
		);

typedef kal_bool (*drv_get_key_func)(kbd_data *);
typedef drv_get_key_func drv_get_key_func;
extern void l4a_eq_keypad_detect_lind(drv_get_key_func func);
extern void l4a_cc_set_csd_profile_lrsp(kal_uint8 src_id,kal_bool result, kal_uint16 cause);
extern void l4a_ps_set_gprs_data_account_lrsp(kal_bool result, kal_uint16 cause);
//mtk01616_070504: add fake function for wap mms
extern void l4c_mms_read_folder_status_wind(kal_uint8  folderId,kal_uint8  retrievalMode);
extern void l4c_mms_upload_msg_wind(kal_uint8*  filePath);
extern void l4c_mms_delete_msg_wind(kal_uint32  msgId,kal_uint8  folderId);

#endif //__L4A_CMD_H__
#endif //__MOD_L4A__


