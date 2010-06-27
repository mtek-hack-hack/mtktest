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
 *	l4a_callback.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4A.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


/*MTK:BEGIN:generate_callback_function_header*/
/* Call Control Related Messages */
#if defined(__MOD_CSM__)
void l4c_cc_exe_reset_acm_lrsp(kal_bool result, kal_uint16 cause);
void l4c_cc_set_acm_max_lrsp(kal_bool result, kal_uint16 cause);
void l4c_cc_exe_chld_lrsp(kal_bool result, kal_uint16 cause,kal_uint8 opcode);
void l4c_cc_exe_hangup_active_call_lrsp(void);
void l4c_cc_exe_ath_lrsp(void);
void l4c_cc_exe_call_deflect_lrsp(kal_bool result, kal_uint16 cause);
void l4c_cc_auto_dtmf_start_lind(kal_uint8 call_id, kal_uint8* digits);
void l4c_cc_auto_dtmf_compl_lind(kal_uint8 call_id);
void l4c_cc_exe_ata_lrsp(l4c_result_struct result, kal_uint8 call_mode);
void l4c_cc_call_setup_req_ind(l4c_number_struct dest, kal_uint8 call_type, kal_uint8 clir_flag, kal_bool cug_option);
void l4c_cc_exe_call_setup_lrsp(l4c_result_struct result, kal_uint8 call_id);
void l4c_cc_exe_call_modify_lrsp(l4c_result_struct result, kal_uint8 call_mode);
void l4c_cc_call_meter_lind(kal_uint8 call_id, kal_uint32 ccm, kal_uint8 warning);
void l4c_cc_call_alert_lind(kal_uint8 alert);
void l4c_cc_call_wait_lind(kal_uint8 call_id, l4c_number_struct* num, kal_uint8 call_mode, kal_uint8 name_present, kal_uint8 cnap_info_exist, kal_uint8 tag, kal_uint8* name, kal_uint8 dcs, kal_uint8 length, kal_uint8 signal);
void l4c_cc_call_ring_lind(kal_uint8 call_id, l4c_number_struct* num, l4c_sub_addr_struct* sub_addr, l4c_number_struct* redirect_num, kal_uint8 name_present, kal_uint8 cnap_info_exist, kal_uint8 tag, kal_uint8* name, kal_uint8 dcs, kal_uint8 length, kal_uint8 auto_answer, kal_uint8 call_type);
void l4c_cc_call_connect_lind(l4c_number_struct* num, l4c_sub_addr_struct* sub_addr, kal_uint8 call_type, kal_uint8 call_id);
void l4c_cc_call_disc_lind(kal_uint8 call_id, kal_bool ccbs);
void l4c_cc_call_release_lind(kal_uint8 call_id, kal_uint16 cause);
void l4c_cc_speech_lind(kal_bool on_off, kal_uint8 rat);
void l4c_cc_name_lind(void);
void l4c_cc_notify_ss_lind(kal_uint8 call_id, kal_uint8 type, kal_bool status_present, kal_uint8 status, kal_bool notification_present, kal_uint8 notification);
void l4c_cc_notify_ss_cug_lind(kal_uint8 call_id, kal_uint16 index);
void l4c_cc_notify_ss_ect_lind(kal_uint8 call_id, kal_bool present, l4c_number_struct* addr, l4c_sub_addr_struct* sub_addr);
void l4c_cc_notify_ss_cnap_lind(kal_uint8 call_id, kal_uint8 name_present, kal_uint8 cnap_info_exist, kal_uint8 tag, kal_uint8* name, kal_uint8 dcs, kal_uint8 length);
void l4c_cc_notify_ss_ccbs_lind(kal_uint8 call_id, kal_bool number_present, l4c_number_struct* addr, kal_bool sub_addr_present, l4c_sub_addr_struct* sub_addr, kal_bool index_present, kal_uint8 index, kal_bool bs_code_present, kal_uint8 bs_code, kal_bool alert_present, kal_uint8 alert_pattern);
void l4c_cc_call_accept_req_ind(kal_uint8 call_id);
void l4c_cc_call_abort_req_ind(void);
void l4c_cc_call_sync_req_ind(void);
void l4c_cc_video_call_status_ind(kal_uint8 call_id, kal_uint8 action, kal_bool result, kal_uint8 cause);
#endif /* defined(__MOD_CSM__) */
void l4a_cc_set_csd_profile_lrsp(kal_uint8 src_id,kal_bool result, kal_uint16 cause);
void l4c_ss_exe_emlpp_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 opcode, kal_uint8 default_pri, kal_uint8 max_pri);
void l4c_ss_exe_call_forward_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 opcode, kal_uint8 type, kal_uint8 count, forwarding_list_struct* list);
void l4c_ss_exe_call_wait_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 opcode, kal_uint8 count, kal_uint8 status, kal_uint8* list);
void l4c_ss_exe_cdip_interrogate_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 status);
void l4c_ss_exe_clip_interrogate_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 status, kal_uint8 clir_option);
void l4c_ss_exe_clir_interrogate_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 status, kal_uint8 clir_option);
void l4c_ss_exe_cnap_interrogate_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 status, kal_uint8 clir_option);
void l4c_ss_exe_colp_interrogate_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 status, kal_uint8 clir_option);
void l4c_ss_exe_colr_interrogate_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 status, kal_uint8 clir_option);
void l4c_ss_exe_call_barring_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 opcode, kal_uint8 type, kal_uint8 count, barring_list_struct* list);
void l4c_ss_exe_ussd_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 op_code, kal_uint8 dcs, kal_uint8* ussd_str, kal_uint8 length);
void l4c_ss_ussr_lind(kal_uint8 dcs, kal_uint8* ussd_string,kal_uint8 length);
void l4c_ss_ussn_lind(kal_uint8 dcs, kal_uint8* ussd_string,kal_uint8 length);
void l4c_ss_exe_change_password_lrsp(l4c_result_struct result);
void l4c_ss_string_parsing_lrsp(l4c_result_struct result, l4c_ss_string_info_struct* info);
void l4c_ss_cb_passwd_lind(kal_uint8 pwd_no);
void l4c_sms_cb_gs_change_lind(kal_uint8 geography_type);
void l4c_ss_exe_ccbs_lrsp(l4c_result_struct result, kal_uint8 para_present, kal_uint8 opcode, kal_uint8 ccbs_count, ccbs_list_struct* list);
/* Hardware - Audio Related Service Messages */
#if defined(__MOD_UEM__)
void l4c_eq_set_volume_req_ind(kal_uint8 volume_type, kal_uint8 volume_level);
void l4a_eq_volume_change_ind( kal_uint8 volume_type, kal_uint8 volume_level);
void l4c_eq_set_mute_mode_req_ind(kal_uint8 audio_device, kal_bool mute_onoff);
void l4a_eq_mute_change_ind(kal_uint8 audio_device,kal_bool mute_onoff);
void l4c_eq_set_silent_mode_req_ind(kal_bool mode);
void l4a_eq_set_gpio_level_req_ind(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);
void l4c_eq_set_gpio_level_req_ind(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);
void l4c_eq_audio_play_finish_lind(kal_uint8 result, kal_uint16 identifier);
void l4c_eq_audio_play_by_string_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_audio_stop_by_string_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_gpio_detect_lind(kal_uint8 gpio_device, kal_bool on_off);
void l4c_eq_gpio_detect_res_lrsp(kal_bool result);
void l4c_eq_audio_play_by_name_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_audio_stop_by_name_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_set_audio_profile_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_get_audio_profile_lrsp(kal_bool result, audio_profile_struct audio_prof_out);
void l4c_eq_set_audio_param_lrsp(kal_bool result, kal_uint16 cause);
void l4a_eq_get_audio_param_lrsp(kal_bool result, audio_param_struct* audio_para);
void l4c_get_adc_all_channel_lind(kal_int32 vbat, kal_int32 bat_temp, kal_int32 vaux, kal_int32 charge_current, kal_int32 vcharge);
void l4c_eq_set_hw_level_lrsp(kal_bool result, kal_uint16 cause);
void l4c_em_lcm_sleep_mode_req_lind(kal_bool on_off);
#endif /* defined(__MOD_UEM__) */
/* Hardware - RTC, Clock, Alarm Related Messages */
#if defined(__MOD_UEM__)
void l4c_eq_set_rtc_time_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_set_rtc_time_req_ind(kal_uint8 rtc_type, kal_uint8 set_type, rtc_alarm_info_struct alarm);
void l4c_eq_rtc_delete_lrsp(kal_bool result, kal_uint16 cause);
void l4a_eq_exe_rtc_delete_req_ind(kal_uint8 rtc_type,kal_uint8 rtc_index);
void l4c_eq_exe_rtc_delete_req_ind(kal_uint8 rtc_type, kal_uint8 rtc_index);
void l4c_eq_set_date_time_format_req_ind(kal_bool is_date_set, kal_uint8 mode);
void l4c_eq_rtc_period_lind(kal_uint8 rtc_type, rtc_format_struct* rtc_time);
void l4c_eq_alarm_detect_lind(rtc_format_struct* rtc_time);
void l4c_eq_at_alarm_query_req_lind(void);
void l4c_eq_at_alarm_set_req_lind(mmi_at_alarm_info_struct alarm);
void l4c_eq_at_alarm_delete_req_lind(kal_uint8 alarm_index);
#endif /* defined(__MOD_UEM__) */
/* Hardware - Keypad, Indicator, LCD Related Messages */
#if defined(__MOD_UEM__)
void l4c_eq_set_keypad_input_req_ind(kal_uint8 keypad_status, kal_uint8 keycode);
void l4c_eq_set_indicator_req_ind(kal_uint8 icon_id, kal_uint8 value);
void l4c_eq_set_dspl_text_req_ind(kal_uint8* text_string);
void l4a_eq_keypad_detect_lind(drv_get_key_func func);
#endif /* defined(__MOD_UEM__) */
/* Hardware - Misc Messages */
#if defined(__MOD_UEM__)
void l4c_eq_set_language_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_set_language_req_ind(kal_uint8 lang_code);
void l4c_eq_set_greeting_text_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_set_greeting_text_req_ind(kal_bool mode, kal_uint8 dcs, kal_uint8* text, kal_uint8 length);
void l4c_eq_set_vibrator_mode_req_ind(kal_bool mode);
void l4c_eq_set_vibrator_mode_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_set_country_code_lrsp(kal_bool result, kal_uint16 cause);
void l4a_eq_power_on_lind(kal_uint8 poweron_mode,kal_uint8 battery_level,kal_uint8 build_label,rtc_format_struct* rtc_time, kal_uint8 flightmode_state, kal_uint8 dual_sim_mode_setting, kal_uint8 dual_sim_uart_setting);
void l4c_eq_battery_status_lind(kal_uint8 battery_status, kal_uint8 battery_voltage);
void l4c_eq_leave_precharge_lind(void);
void l4c_eq_pmic_config_lrsp(kal_uint8 request_type, pmic_config_param_struct request);
void l4c_eq_rf_test_gsm_lrsp(kal_uint8 request_type, rf_test_gsm_param_struct request);
void l4c_eq_fm_radio_config_lrsp(kal_uint8 request_type, fm_radio_config_param_struct request);
void l4c_eq_rf_test_wifi_lrsp(kal_uint8 request_type, rf_test_wifi_param_struct request);
#endif /* defined(__MOD_UEM__) */
/* Hardware - NVRAM messages */
#if defined(__MOD_NVRAM__)
void l4a_eq_read_nvram_lrsp(l4c_result_struct result, kal_uint8 file_idx, kal_uint16 length, kal_uint8* data);
void l4c_eq_write_nvram_lrsp(l4c_result_struct result, kal_uint8 file_idx, kal_uint16 para);
void l4c_eq_reset_nvram_lrsp(l4c_result_struct result);
void l4c_eq_get_uart_port_lrsp(kal_bool result, kal_uint8 ps_uart_port, kal_uint32 ps_baud_rate, kal_uint8 tst_uart_port_ps, kal_uint32 tst_baud_rate_ps, kal_uint8 cti_uart_port, kal_uint32 cti_baud_rate, kal_uint8 tst_uart_port_l1, kal_uint32 tst_baud_rate_l1);
void l4c_attach_uart_port_lrsp(kal_uint8 result);
void l4c_detach_uart_port_lrsp(kal_uint8 result);
void l4c_nvm_ready_lind(void);
void l4c_eq_dcm_enable_lrsp(void);
#endif /* defined(__MOD_NVRAM__) */
/* Network Related Messages */
#if defined(__MOD_RAC__)
void l4c_nw_abort_plmn_list_lrsp(kal_bool result);
void l4c_nw_exe_att_lrsp(kal_bool result);
void l4c_nw_set_class_lrsp(kal_bool result, kal_uint16 cause);
void l4c_nw_exe_cops_lrsp(l4c_result_struct result, kal_uint8 status, kal_uint8* plmn, kal_uint8 rat);
void l4c_nw_get_plmn_list_lrsp(l4c_result_struct result, kal_uint8 length, l4c_rat_plmn_info_struct* list);
void l4c_nw_attach_lind(kal_uint8 status, kal_uint8* plmn, kal_uint8 gsm_state, kal_uint8 gprs_state, l4c_gprs_status_enum gprs_status, kal_uint8 rat, kal_uint8 cell_support_egprs, kal_uint8* lac);
void l4c_nw_reg_state_lind(kal_uint8* lac, kal_uint16 cell_id, kal_uint8 status, kal_uint8 gprs_state, l4c_gprs_status_enum gprs_status);
void l4c_nw_rx_level_lind(kal_uint8 level, kal_uint8 current_band, kal_uint8 rat);
void l4c_nw_time_zone_lind( kal_uint8 full_nw_nameP, kal_uint8 full_nw_name_dcs, kal_bool full_nw_name_add_ci, kal_uint8 full_nw_name_len, kal_uint8* full_nw_name, kal_uint8 short_nw_nameP, kal_uint8 short_nw_name_dcs, kal_bool short_nw_name_add_ci, kal_uint8 short_nw_name_len, kal_uint8* short_nw_name, kal_uint8 nw_time_zoneP, kal_uint8 nw_time_zone, kal_uint8 nw_time_zone_timeP, l4c_nw_time_zone_time_struct nw_time_zone_time, kal_uint8 lsa_idP, kal_uint8 lsa_id_len, kal_uint8* lsa_id, kal_uint8 nw_day_light_saving_timeP, kal_uint8 nw_day_light_saving_time);
void l4c_nw_sel_mode_lind(kal_uint8 network_mode);
void l4c_nw_mmrr_service_status_lind(kal_uint8 service_status);
void l4c_nw_set_preferred_band_lrsp(kal_bool result, kal_uint8 status);
void l4c_nw_powroff_detach_lrsp(l4c_result_struct result);
void l4c_nw_cfun_state_lrsp(kal_bool result);
void l4c_nw_set_rat_mode_lrsp(kal_bool result);
void l4c_nw_set_prefer_rat_lrsp(kal_bool result);
#endif /* defined(__MOD_RAC__) */
/* Security Related Messages */
#if defined(__MOD_SMU__)
void l4c_smu_exe_lock_lrsp(kal_bool result, kal_uint16 cause, sim_chv_info_struct chv_info);
void l4c_smu_exe_master_reset_lrsp(kal_bool result, kal_uint16 cause);
void l4c_smu_exe_verify_pin_lrsp(kal_bool result, kal_uint8 next_type, sim_chv_info_struct chv_info);
void l4c_smu_set_preferred_oper_list_lrsp(kal_bool result, kal_uint16 cause);
void l4c_smu_set_puc_params_lrsp(kal_bool result, kal_uint16 cause);
void l4c_smu_exe_change_password_lrsp(kal_bool result, kal_uint16 cause, sim_chv_info_struct chv_info);
void l4c_smu_exe_restricted_access_lrsp(l4c_result_struct result, kal_uint8 sw1, kal_uint8 sw2, kal_uint16 length, kal_uint8* resp);
void l4c_smu_exe_dial_mode_lrsp(kal_bool result, kal_uint16 cause);
void l4c_smu_write_sim_lrsp(kal_bool result, kal_uint16 cause);
void l4c_smu_read_sim_lrsp(l4c_result_struct result, kal_uint16 length, kal_uint8* data);
void l4c_sim_passwd_required_lind(kal_uint8 type, kal_bool is_sim_change, sim_chv_info_struct chv_info, kal_uint8 cphs_retry_count);
void l4c_sim_support_plmn_list_lind(kal_uint16 length);
void l4c_sim_fail_lind(kal_uint16 cause);
void l4c_smu_read_file_info_lrsp(l4c_result_struct result, kal_uint16 file_size, kal_uint8 num_of_rec);
void l4c_sim_startup_info_lind(kal_uint8 num, kal_uint8* ecc, kal_uint8* language, kal_uint8 alpha_set);
void l4c_sim_cipher_lind(kal_bool cipher_ind, kal_uint8 is_gsm_conn_exist, kal_uint8 gsm_cipher_cond, kal_uint8 gprs_cipher_cond);
void l4c_smu_set_personalization_lrsp(l4c_result_struct result, kal_uint8 category, kal_uint8 op, kal_uint8 state, kal_uint8 retry_count, kal_uint8 num_of_sets, kal_uint8 space_of_sets);
void l4c_smu_sml_status_lrsp(l4c_result_struct result, kal_uint8* state, kal_uint8* retry_count, kal_uint8* autolock_count, kal_uint8* num_of_sets, kal_uint8* total_size_of_cat, kal_uint8* key_state, kal_uint8* imsi, kal_uint8 is_valid_gid1, kal_uint8 ef_gid1, kal_uint8 is_valid_gid2, kal_uint8 ef_gid2, kal_uint8 digits_of_mnc);
void l4c_sim_verify_pin_result_lind(kal_uint8 next_type, sim_chv_info_struct chv_info);
#endif /* defined(__MOD_SMU__) */
/* PhoneBook Related Messages */
#if defined(__MOD_PHB__)
void l4c_phb_get_entry_by_text_lrsp(l4c_result_struct result, kal_uint16 no_list, l4c_phb_entry_struct* list);
void l4c_phb_get_entry_by_index_lrsp(l4c_result_struct result, kal_uint16 no_list, l4c_phb_entry_struct* list);
void l4c_phb_exe_write_entry_lrsp(l4c_result_struct result, kal_uint16 no_list, l4c_phb_entry_struct* list);
void l4c_phb_exe_delete_entry_lrsp(l4c_result_struct result, kal_uint16 no_list, l4c_phb_entry_struct* list);
void l4a_phb_exe_read_ln_entry_lrsp(l4c_result_struct result, kal_uint8 no_list, kal_uint8 type, kal_uint8 more_data, l4c_phb_ln_entry_struct* list);
void l4a_phb_exe_write_ln_entry_lrsp(l4c_result_struct result, kal_uint16 no_list ,kal_uint8 type);
void l4a_phb_exe_delete_ln_entry_lrsp(l4c_result_struct result, kal_uint16 no_list );
void l4c_phb_ln_ready_lind(void);
void l4c_phb_startup_finish_lind(kal_uint16 sim_max_num, kal_uint16 phb_max_num, kal_uint8 phb_len, kal_uint8 fdn_len, kal_uint8 bdn_len, kal_uint8 owner_len);
void l4c_phb_mem_full_lind(void);
void l4c_phb_update_lind(kal_uint8 action, kal_uint16 old_index, kal_uint16 sim_used, kal_uint16 nvram_used, kal_uint16 no_list, l4c_phb_entry_struct* list);
void l4c_phb_startup_read_lind(l4c_phb_entries_struct* phb_entries, kal_uint8 access_id);
void l4c_phb_startup_begin_lind(void);
void l4c_phb_startup_phase1_lind(kal_uint16 sim_max_num, kal_uint16 phb_max_num, kal_uint8 phb_len, kal_uint8 fdn_len, kal_uint8 bdn_len, kal_uint8 owner_len, kal_bool is_usim, kal_bool is_group_support, kal_uint8 anra_support_type, kal_uint8 anrb_support_type, kal_uint8 anrc_support_type, kal_uint8 sne_support_type, kal_uint8 email_support_type, kal_uint8 group_len, kal_uint8 sne_len, kal_uint8 email_len, kal_uint16 anra_max_num, kal_uint16 anrb_max_num, kal_uint16 anrc_max_num, kal_uint16 sne_max_num, kal_uint16 email_max_num, kal_uint16 group_max_num);
void l4c_phb_startup_read_anr_lind(kal_uint8 num_of_entry, l4c_phb_bcd_anr_struct* anr_entry, kal_uint8 access_id);
void l4c_phb_startup_read_email_lind(kal_uint8 num_of_entry, l4c_phb_email_struct* email_entry, kal_uint8 access_id);
void l4c_phb_read_email_lrsp(l4c_result_struct result, kal_uint16 no_list, l4c_phb_email_struct* list);
void l4c_phb_startup_read_gas_lind(kal_uint8 num_of_entry, l4c_phb_entry_struct* gas_entry, kal_uint8 access_id);
void l4c_phb_startup_read_grp_lind(kal_uint8* grp, kal_uint8 access_id);
void l4c_phb_set_grp_lrsp(l4c_result_struct result, kal_uint16 record_index, kal_uint8 group_type);
void l4c_phb_write_usim_lrsp(l4c_result_struct result, kal_uint8 no_data, l4c_phb_entry_struct* list, kal_uint8 update_field, l4c_phb_anr_struct anra, l4c_phb_anr_struct anrb, l4c_phb_anr_struct anrc, l4c_phb_email_struct email, l4_name_struct sne, kal_uint8 group_type, kal_uint8 hidden_info);
#endif /* defined(__MOD_PHB__) */
void l4c_sms_set_profile_params_lrsp(kal_bool result, kal_uint16 cause );
void l4c_sms_set_common_params_lrsp(kal_bool result, kal_uint16 cause);
void l4c_sms_exe_post_command_lrsp(kal_bool result, kal_uint16 cause, kal_uint8 mr, kal_uint8* scts);
void l4c_sms_exe_delete_msg_lrsp(kal_bool result, kal_uint16 cause, smsal_del_flag_enum del_flag, kal_uint16 index, kal_uint8 storage_type, kal_uint8* del_bitmap);
void l4a_sms_exe_read_msg_lrsp(kal_bool result, kal_uint16 cause, smsal_concat_struct concat_info, kal_uint8 mti, kal_uint8 status, kal_uint8 storage_type, kal_uint8 fo, kal_uint8* scts, l4c_number_struct sca_number, l4c_number_struct addr_number, kal_uint8 pid, kal_uint8 dcs, kal_uint8 ori_dcs, kal_uint8 vp, kal_uint8 mr, kal_uint8* dt, kal_uint8 st, kal_uint16 dest_port, kal_uint16 src_port, kal_uint16 no_msg_data, kal_uint8* msg_data);
void l4c_sms_exe_post_msg_lrsp(kal_bool result, kal_uint16 cause, kal_uint8 mr, kal_uint8* scts, kal_uint8 seq_num, smsal_concat_struct concat_info);
void l4c_sms_exe_write_msg_lrsp(kal_bool result, kal_uint16 cause, kal_uint16 index, kal_uint8 status, kal_uint8 storage_type);
void l4c_sms_set_preferred_mem_lrsp(kal_bool result, smsal_prefer_storage_struct* param);
void l4a_sms_deliver_msg_ind(kal_uint8 fo, kal_uint8* scts, l4c_number_struct sca_number, l4c_number_struct oa_number, kal_uint8 pid, kal_uint8 dcs, kal_uint8 ori_dcs, kal_uint16 index, kal_uint16 dest_port, kal_uint16 src_port, kal_uint8 mti, kal_uint8 display_type, kal_uint8 storage_type, kal_uint32 concat_info, kal_uint16 no_msg_data, kal_uint8* msg_data);
void l4a_sms_status_report_ind( kal_uint8 fo, kal_uint8* scts, kal_uint8* dt, l4c_number_struct ra_number, kal_uint8 st, kal_uint8 pid, kal_uint8 dcs, kal_uint8 mr, kal_uint16 no_msg_data, kal_uint8* msg_data );
void l4c_sms_mem_available_lind(kal_uint8 type);
void l4c_sms_mem_exceed_lind(kal_uint8 type);
void l4c_sms_mem_full_lind(kal_uint8 type);
void l4c_sms_ready_lind(kal_bool result);
void l4c_sms_app_data_lind(kal_uint16 dest_mod_id, kal_uint16 dest_port, kal_uint16 src_port, kal_uint8 dcs, kal_uint8 mti, kal_uint16 message_len, void* concat_info, l4c_number_struct* oa, kal_uint8* scts, kal_uint8* msg_data);
void l4c_sms_msg_waiting_lind(kal_uint8 line_no, kal_uint8 waiting_num, kal_uint8 ind_type, kal_bool is_show_num, kal_bool is_clear, kal_bool is_from_storage);
void l4c_sms_set_mailbox_addr_lrsp(kal_bool result, kal_uint16 cause);
void l4c_sms_sync_msg_lind(kal_uint8 action, kal_uint16 index, kal_uint8 status, kal_uint8* del_bitmap);
void l4c_sms_send_abort_start_lind(void);
void l4c_sms_send_abort_finish_lind(kal_bool result, kal_uint16 cause);
void l4c_sms_startup_begin_lind(void);
void l4c_sms_startup_finish_lind(void);
void l4a_sms_startup_read_msg_lind(kal_uint8 startup_seq_num, kal_uint8 mti, kal_uint8 status, kal_uint8 storage_type, kal_uint8 fo, kal_uint16 index, kal_uint8* scts, l4c_number_struct addr_number, kal_uint8 pid, kal_uint8 dcs, kal_uint8 ori_dcs, kal_uint8 vp, kal_uint8 mr, kal_uint8* dt, kal_uint8 st, kal_uint16 dest_port, kal_uint16 src_port, kal_uint32 concat_info, kal_uint16 no_msg_data, kal_uint8* msg_data);
void l4c_sms_copy_msg_lrsp(kal_uint8 result, kal_uint16 cause, kal_uint8 action, kal_uint8 dst_storage, kal_uint16 src_index, kal_uint16 dst_index);
void l4c_sms_exe_read_msg_list_lrsp(smsal_inbox_list_struct inbox, smsal_outbox_list_struct outbox);
void l4c_sms_send_from_storage_lrsp(kal_bool result, kal_uint16 cause, kal_uint8 mr, kal_uint16 index, smsal_concat_struct concat_info);
void l4c_sms_set_status_lrsp(kal_bool result,kal_uint16 error_cause,kal_uint16 index);
/* Data Related Messages */
#if defined(__MOD_DATA__)
#endif /* defined(__MOD_DATA__) */
void l4c_df_exe_back_data_state_lrsp(void);
/* GPRS Related Messages */
#if defined(__MOD_TCM__)
void l4c_ps_exe_act_lrsp(kal_bool result, kal_uint16 cause);
void l4c_ps_exe_act_test_lrsp(kal_bool result, kal_uint16 cause);
void l4c_ps_exe_modify_lrsp(kal_bool result, kal_uint16 cause);
void l4c_ps_set_definition_lrsp(kal_bool result, kal_uint16 cause);
void l4c_ps_set_sec_definition_lrsp( kal_bool result, kal_uint16 cause);
void l4c_ps_set_tft_lrsp(kal_bool result, kal_uint16 cause);
void l4c_ps_set_qos_lrsp(kal_bool result, kal_uint16 cause);
void l4c_ps_set_eqos_lrsp(kal_bool result, kal_uint16 cause);
void l4c_ps_activate_lind(void);
void l4c_ps_gprs_status_update_lind(l4c_gprs_status_enum status , kal_uint8 cell_support_egprs);
void l4a_ps_set_gprs_data_account_lrsp(kal_bool result, kal_uint16 cause);
void l4c_ps_get_gprs_data_account_lrsp(kal_bool result, l4c_gprs_account_info_struct gprs_account);
void l4c_ps_reset_gprs_data_counter_lrsp(kal_bool result, kal_uint16 cause);
#endif /* defined(__MOD_TCM__) */
/* STK/SAT Related Messages */
#if defined(__SAT__)
void l4a_sat_dspl_text_lind( kal_uint8* cmd_detail, kal_uint8 priority, kal_uint8 clear_text_type, kal_uint8 immediate_res, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint16 no_text_string, kal_uint8* text_string, kal_uint8 dcs_of_text_string);
void l4a_sat_get_inkey_lind( kal_uint8* cmd_detail, kal_uint8 is_help_info_available, kal_uint8 type_of_input, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint16 no_text_string, kal_uint8* text_string, kal_uint8 dcs_of_text_string );
void l4a_sat_get_input_lind( kal_uint8* cmd_detail, kal_uint8 is_help_info_available, kal_uint8 type_of_input, kal_uint8 is_input_revealed_to_user, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 len_of_min_input, kal_uint8 len_of_max_input, kal_uint16 no_text_string, kal_uint8* text_string, kal_uint8 dcs_of_text_string, kal_uint16 no_default_text, kal_uint8* default_text, kal_uint8 dcs_of_default_text );
void l4a_sat_setup_menu_lind( kal_uint8* cmd_detail, kal_uint8 is_help_info_available, kal_uint8 is_softkey_preferred, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 num_of_item, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 dcs_of_alpha_id, kal_uint16 no_item_data, kal_uint8* item_data, kal_uint8 no_item_icon_id_list, kal_uint8* item_icon_id_list, kal_uint8 item_icon_list_attr, kal_uint8 no_next_action_ind_list, kal_uint8* next_action_ind_list );
void l4a_sat_select_item_lind( kal_uint8* cmd_detail, kal_uint8 is_help_info_available, kal_uint8 is_softkey_preferred, kal_uint8 type_of_presentation, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 is_item_id_available, kal_uint8 item_id, kal_uint8 num_of_item, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 dcs_of_alpha_id, kal_uint16 no_item_data, kal_uint8* item_data, kal_uint8 item_icon_list_attr, kal_uint8 no_item_icon_id_list, kal_uint8* item_icon_id_list, kal_uint8 no_next_action_ind_list, kal_uint8* next_action_ind_list );
void l4a_sat_play_tone_lind( kal_uint8* cmd_detail, kal_uint8 tone_id, kal_uint32 duration, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 dcs_of_alpha_id, kal_uint8 is_alpha_id_present );
void l4c_sat_exe_menu_select_lrsp(kal_uint8 result);
void l4a_sat_setup_call_lind( kal_uint8* cmd_detail, kal_uint8 condition, kal_uint32 duration, kal_uint8 type_of_modification, kal_uint8 is_icon1_available, sat_icon_struct icon_info1, kal_uint8 is_icon2_available, sat_icon_struct icon_info2, kal_uint8 size_of_ccp, kal_uint8* ccp, kal_uint8 size_of_subaddr, kal_uint8* subaddr, kal_uint8 is_alpha_id1_present, kal_uint8 no_alpha_id1, kal_uint8* alpha_id1, kal_uint8 dcs_of_alpha_id1, kal_uint8 no_addr, kal_uint8* addr, kal_uint8 is_alpha_id2_present, kal_uint8 no_alpha_id2, kal_uint8* alpha_id2, kal_uint8 dcs_of_alpha_id2 );
void l4c_sat_call_setup_lrsp(l4c_result_struct result, kal_uint8 terminal_res, kal_uint8 additional_res);
void l4a_sat_send_sms_lind( kal_uint8* cmd_detail, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 is_sms_packed_required, kal_uint8 size_of_addr, kal_uint8* addr, kal_uint8 is_alpha_id_present, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 dcs_of_alpha_id, kal_uint8 no_sms_tpdu, kal_uint8* sms_tpdu );
void l4c_sat_send_sms_lrsp(kal_uint8 res, kal_uint16 cause);
void l4a_sat_send_ss_lind( kal_uint8* cmd_detail, kal_uint8 type_of_modification, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 is_alpha_id_present, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 dcs_of_alpha_id, kal_uint8 no_ss_string, kal_uint8* ss_string );
void l4c_sat_send_ss_lrsp(kal_uint8 res, kal_uint8 length, kal_uint8* addition_info);
void l4a_sat_send_ussd_lind( kal_uint8* cmd_detail, kal_uint8 type_of_modification, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 is_alpha_id_present, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 dcs_of_alpha_id, kal_uint8 no_ussd_string, kal_uint8* ussd_string, kal_uint8 dcs_of_ussd_string );
void l4c_sat_send_ussd_lrsp(kal_uint8 res, kal_uint8 length, kal_uint8* addition_info);
void l4a_sat_mmi_info_lind( kal_uint8 mmi_info_type, kal_uint8 is_alpha_id_present, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 dcs_of_alpha_id, kal_uint8 len_of_address, kal_uint8* address, kal_uint8 ton );
void l4a_sat_setup_idle_dspl_lind( kal_uint8* cmd_detail, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint16 no_text_string, kal_uint8* text_string, kal_uint8 dcs_of_text_string );
void l4a_sat_run_at_command_lind( kal_uint8* cmd_detail, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 is_alpha_id_present, kal_uint8 dcs_of_alpha_id, kal_uint8 no_at_command, kal_uint8* at_command );
void l4a_sat_send_dtmf_lind( kal_uint8* cmd_detail, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 is_alpha_id_present, kal_uint8 dcs_of_alpha_id, kal_uint8 no_dtmf, kal_uint8* dtmf );
void l4c_sat_send_dtmf_lrsp(kal_uint8 terminal_res, kal_uint8 cause);
void l4a_sat_lang_notify_lind( kal_uint8* cmd_detail, kal_uint8 is_language_specified, kal_uint8* iso639_language );
void l4a_sat_launch_browser_lind( kal_uint8* cmd_detail, kal_uint8 is_icon_available, sat_icon_struct icon_info, kal_uint8 browser_mode, kal_uint8 browser_identity, kal_uint8* provision_file_id, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 is_alpha_id_present, kal_uint8 dcs_of_alpha_id, kal_uint8 no_url, kal_uint8* url, kal_uint8 no_bearer, kal_uint8* bearer, kal_uint16 no_gateway, kal_uint8* gateway, kal_uint8 dcs_of_gateway );
void l4a_sat_no_other_cmd_lind(void);
void l4c_sat_file_change_lind(kal_uint8 is_full_changed, kal_uint8 refresh_type, kal_uint8 num_of_file, kal_uint8* file_list);
#endif /* defined(__SAT__) */
/* STK_CE */
#if defined(__SATCE__)
void l4a_sat_open_channel_lind( kal_uint8* cmd_detail, kal_bool is_icon_available, sat_icon_struct icon_info, kal_uint8 bearer_type, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 is_alpha_id_present, kal_uint8 dcs_of_alpha_id );
void l4c_sat_open_channel_lrsp(kal_uint8 terminal_res);
void l4a_sat_close_channel_lind( kal_uint8* cmd_detail, kal_bool is_icon_available, sat_icon_struct icon_info, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 is_alpha_id_present, kal_uint8 dcs_of_alpha_id );
void l4c_sat_close_channel_lrsp(kal_uint8 terminal_res);
void l4a_sat_send_data_lind( kal_uint8* cmd_detail, kal_bool is_icon_available, sat_icon_struct icon_info, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 is_alpha_id_present, kal_uint8 dcs_of_alpha_id );
void l4c_sat_send_data_lrsp(kal_uint8* cmd_detail, kal_uint8 terminal_res, kal_uint8 cause);
void l4a_sat_recv_data_lind( kal_uint8* cmd_detail, kal_bool is_icon_available, sat_icon_struct icon_info, kal_uint8 no_alpha_id, kal_uint8* alpha_id, kal_uint8 is_alpha_id_present, kal_uint8 dcs_of_alpha_id );
void l4c_sat_recv_data_lrsp(kal_uint8* cmd_detail, kal_uint8 terminal_res, kal_uint8 cause);
void l4c_sat_notify_mmi_lind(kal_uint8 state);
#endif /* defined(__SATCE__) */
void l4c_cb_dl_lind(void);
void l4a_cb_msg_lind(kal_uint16 sn, kal_uint16 mi,kal_uint8 dcs,kal_uint8 page, kal_uint8 pages, kal_uint16 msg_length,kal_uint8* msg_data);
void l4c_sms_set_cb_mode_lrsp(kal_bool result, kal_uint16 cause);
/* Engineer Mode-UEM */
#if defined(__MOD_UEM__)
void l4c_eq_set_gain_lrsp(kal_bool result, kal_uint16 cause);
#endif /* defined(__MOD_UEM__) */
/* Engineer Mode */
#if defined(__EM_MODE__)
void l4c_em_status_ind(kal_uint8 mod_id, kal_uint32 em_info, peer_buff_struct* info);
void l4c_em_start_rsp(kal_bool result, kal_uint8 cause, kal_uint8 mod_id, kal_uint32 info_request);
void l4c_em_stop_rsp(kal_bool result, kal_uint8 cause, kal_uint8 mod_id, kal_uint32 info_request);
void l4c_em_set_cell_id_lock_lrsp(kal_bool result);
#endif /* defined(__EM_MODE__) */
void l4c_em_lcm_test_lind(kal_uint8 color);
void l4c_em_keypad_event_act_lind(kal_bool on_off);
void l4c_factory_test_lind(kal_bool on_off);
void l4c_set_mmi_default_prof_lind(kal_uint8 op, kal_uint8 category, kal_uint8 param1, kal_uint8 param2, kal_uint8 param3, kal_uint8* param4);
void l4c_em_cell_resel_suspend_rsp(kal_bool result, kal_uint8 cause);
void l4c_em_cell_resel_resume_rsp(kal_bool result, kal_uint8 cause);
void l4c_em_get_cell_lock_rsp(kal_bool result, kal_bool turn_on_or_off, kal_bool band_indicator, kal_uint16 lock_arfcn);
void l4c_em_set_cell_lock_rsp(kal_bool result);
void l4c_em_rgb_test_req_lind(kal_uint8 type, kal_uint16 red, kal_uint16 green, kal_uint16 blue);
kal_bool l4c_em_nw_event_notify_rsp(kal_bool result);
void l4c_em_nw_event_notify_lind(kal_uint8 group_id, kal_uint32 event_id);
void l4c_em_feature_command_rsp(kal_bool result, kal_uint8 em_feature);
/* Audio Task - Voice Memo(via FS) */
#if defined(__FS_ON__)
void l4c_eq_vm_play_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_vm_delete_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_vm_append_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_vm_rename_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_vm_play_finish_lind(kal_uint8 result);
void l4c_eq_vm_get_info_lrsp(kal_uint16 no_vm, kal_wchar* file_list, kal_bool more_entry, kal_uint32 free_space);
void l4c_eq_vm_stop_lrsp(l4c_result_struct result, kal_wchar* file_name);
void l4c_eq_vm_abort_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_vm_pause_lrsp(l4c_result_struct result, kal_wchar* file_name);
void l4c_eq_vm_resume_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_vm_record_lrsp(kal_bool result, kal_uint16 cause);
void l4c_eq_vm_record_finish_lind(kal_uint8 result, kal_wchar* file_name);
#endif /* defined(__FS_ON__) */
void l4c_cphs_display_cfu_lind(kal_uint8 action, kal_uint8 line_num);
void l4a_cphs_mmi_info_lind(kal_uint8 is_spn_valid, kal_uint8 is_spn_RPLMN_required, kal_uint8* spn, kal_uint8 is_opname_valid, kal_uint8* opname, kal_uint8 is_sopname_valid, kal_uint8* sopname, kal_uint8 no_msisdn, l4csmu_addr_struct* msisdn, kal_uint8 no_info_num, l4csmu_info_num_struct* info_num, kal_uint8 is_valid_csp, kal_uint8* csp, kal_uint8 is_puct_valid, kal_uint8* ef_puct, kal_uint8 is_autolock_enable, kal_uint8 autolock_result, kal_uint8 autolock_remain );
void l4c_cphs_update_als_lrsp(kal_uint8 res, kal_uint16 cause);
void l4c_cphs_display_als_lind(kal_uint8 line);
void l4c_cc_exe_start_dtmf_wrsp( kal_uint8 call_id, kal_uint8 response, kal_uint8 tone, kal_uint8 cause_present, kal_uint16 cause);
void l4c_cc_exe_stop_dtmf_wrsp(void);
void l4c_cc_exe_call_setup_wrsp(l4c_result_struct result, kal_uint8 call_id);
void l4c_phb_exe_write_entry_wrsp(l4c_result_struct result, kal_uint16 no_list, l4c_phb_entry_struct* list);
void l4c_cc_auto_dtmf_compl_wind(kal_uint8 call_id);
/* IrDA */
#if defined(__IRDA_SUPPORT__)
void l4c_eq_ircomm_connect_lind(void);
void l4c_eq_ircomm_disconnect_lind(void);
#endif /* defined(__IRDA_SUPPORT__) */
/* USB */
#if defined(__USB_ENABLE__)
void l4c_eq_usbconfig_lrsp(kal_bool result, kal_uint8 mode, kal_uint32 reserved);
void l4c_eq_usbdetect_lind(kal_uint8 action);
#endif /* defined(__USB_ENABLE__) */
void l4c_eq_data_dl_filelist_info_req_lind(l4c_data_dl_folder_enum data_folder);
void l4c_eq_data_dl_file_modify_req_lind(l4c_data_dl_folder_enum data_folder, kal_uint8* filename, l4c_data_dl_file_action_enum action);
void l4c_eq_data_dl_execute_req_lind(l4c_data_dl_folder_enum data_folder, kal_uint8* filename, l4c_data_dl_execute_action_enum action);
void l4c_mms_read_folder_status_wind(kal_uint8 folderId, kal_uint8 retrievalMode);
void l4c_mms_upload_msg_wind(kal_uint8* filePath);
void l4c_mms_delete_msg_wind(kal_uint32 msgId, kal_uint8 folderId);
void l4c_eq_query_greeting_text_req_lind(void);
void l4c_eq_query_language_req_lind(void);
void l4c_eq_query_silent_mode_req_lind(void);
void l4c_eq_query_vibrator_mode_req_lind(void);
void l4c_eq_query_datetime_format_req_lind(kal_bool is_date);
void l4c_eq_query_mute_mode_req_lind(void);
void l4c_eq_power_reset_lind(kal_uint8 poweroff, kal_uint8 poweron, kal_uint8 rtc_timer);
void l4c_mmi_factory_restore_req_lind(kal_uint8* pwd);
void l4c_eq_vcard_req_lind(kal_uint8 src_id, kal_uint8 mode, kal_uint16 index, kal_uint8* file_path);
void l4c_eq_vcalendar_req_lind(kal_uint8 mode, kal_uint16 index, kal_uint8* file_path);
void l4c_eq_str_enable_req_lind(kal_bool enable);
void l4c_eq_str_req_lind(kal_uint16 length, kal_uint8* data_string);
void l4c_mmi_ucm_at_req_lind(kal_uint8 action,kal_uint8 source_id,kal_bool cmd_from_bt, kal_uint8 length,kal_uint8* number,kal_uint8 opcode,kal_uint8 call_id);
void l4c_mmi_java_local_install_req_lind(kal_bool is_force, kal_wchar* jad_file_name, kal_wchar* jar_file_name);
/* Bluetooth */
#if defined(__BT_SUPPORT__)
void l4c_bt_fcty_set_param_lind(kal_uint8* name, kal_uint8* bd_addr, kal_uint8 dcs);
void l4c_bt_loopback_test_req_lind(kal_uint8* bd_addr, kal_uint8* pin_code );
void l4c_bt_set_vr_req_ind(kal_bool on_off);
#endif /* defined(__BT_SUPPORT__) */
/* HOMEZONE */
#if defined(__HOMEZONE_SUPPORT__)
void l4c_hz_tag_lind(kal_bool action, kal_bool is_hz, kal_uint8* tag);
#endif /* defined(__HOMEZONE_SUPPORT__) */
/* CTM */
#if defined(__CTM_SUPPORT__)
void l4c_ctm_open_lrsp(kal_bool result, kal_uint8 ctm_interface);
void l4c_ctm_close_lrsp(kal_bool result);
void l4c_ctm_connect_lrsp(kal_bool result);
void l4c_ctm_connected_lind(void);
void l4c_ctm_send_text_lrsp(kal_bool result);
void l4c_ctm_recv_text_lind(kal_uint16 num_of_char, kal_uint16* text);
void l4c_ctm_tty_plug_lind(kal_bool is_plug_in);
void l4c_ctm_set_default_lrsp(kal_bool result);
void l4c_ctm_default_changed_lind(kal_bool result, kal_bool is_turn_on, kal_uint8 ctm_interface);
void l4c_ctm_get_default_lrsp(kal_bool result, kal_bool is_turn_on, kal_uint8 ctm_interface);
#endif /* defined(__CTM_SUPPORT__) */
/* VOIP */
#if defined(__VOIP__)
void l4c_mmi_voip_at_call_ctrl_approve_lrsp(kal_bool result);
void l4c_mmi_voip_at_call_ctrl_approve_lind(kal_uint8 action, void* string_ptr, void* node_ptr, void* err_id);
#endif /* defined(__VOIP__) */
/* GEMINI */
#if defined(__GEMINI__)
void l4c_eq_pwnon_dual_sim_lind(void);
void l4c_sim_status_update_lind(kal_bool is_sim_inserted, kal_uint8 dual_sim_mode_setting);
void l4c_nw_rac_activated_lind(void);
void l4c_nw_search_normal_finish_lind(void);
#endif /* defined(__GEMINI__) */

/*MTK:END*/


