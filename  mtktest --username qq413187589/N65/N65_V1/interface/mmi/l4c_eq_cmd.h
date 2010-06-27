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
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (kal_uint8 src_id, C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	l4c_eq_cmd.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#ifndef _L4C_EQ_CMD_H
#define _L4C_EQ_CMD_H


extern kal_bool l4c_eq_gpio_detect_res_req(kal_uint8 ext_gpio_device);

/* audio related */
extern kal_bool l4c_eq_audio_play_req (kal_uint8 src_id,
                                   kal_uint8 sound_id,
                                   kal_uint8 style,
                                   kal_uint16  identifier);

extern kal_bool l4c_eq_audio_play_by_name_req (kal_uint8 src_id,
                            kal_wchar *file_name,
                            kal_uint8 style,
                            kal_uint16  identifier);

extern kal_bool l4c_eq_audio_stop_by_name_req (kal_uint8 src_id,
                            kal_wchar *file_name
                            );

extern kal_bool l4c_eq_audio_stop_req (kal_uint8 src_id, kal_uint8 sound_id);

extern kal_bool l4c_eq_audio_play_by_string_req (kal_uint8   src_id,
   									kal_uint8 *melody,
   									kal_uint32  len,
   									kal_uint8   format,
   									kal_uint8   play_style,
   									kal_uint16  identifier);

extern kal_bool l4c_eq_audio_stop_by_string_req (kal_uint8   src_id);

extern kal_bool l4c_eq_demo_ext_midi_ring_req (kal_uint8 src_id,
                                           kal_uint8 *imelody,
                                           kal_uint16 len,
                                           kal_uint8 play_style,
                                           kal_uint16  identifier);
extern kal_bool l4c_eq_fs_read_req(void);

extern void l4c_eq_fs_efsl_next(void);

extern kal_bool l4c_eq_fs_access_req(kal_uint8 src_id,
                                 rmmi_fs_opcode_enum action,
                                 l4c_app_type_enum app_type,
                                 kal_wchar *file_name,
                                 kal_uint8 *data,
                                 kal_uint8 data_len);

extern kal_bool l4c_eq_general_fs_access_req(kal_uint8 src_id,
                                 rmmi_fs_opcode_enum action,
                                 l4c_app_type_enum app_type,
                                 kal_wchar *file_name,
                                 kal_uint8 *data,
                                 kal_uint8 data_len);

extern kal_bool l4c_eq_exe_volume_req (kal_uint8 src_id,
                                kal_uint8 volume_type,
                                kal_uint8 volume_level);


extern kal_bool l4c_eq_set_audio_profile_req (kal_uint8 src_id, 
										  audio_profile_struct *audio_prof);

extern kal_bool l4c_eq_set_audio_param_req (kal_uint8 src_id,
										  audio_param_struct *audio_para);

extern kal_bool l4c_eq_get_audio_profile_req (kal_uint8 src_id, 
									                   kal_uint8 mode);

extern kal_bool l4c_eq_get_audio_param_req (kal_uint8 src_id);

extern kal_bool l4c_eq_get_volume_req (kal_uint8 src_id,
                                              kal_uint8 volume_type);

extern kal_bool l4c_eq_set_gain_req (kal_uint8 src_id,
                                kal_uint8 volume_type,
                                kal_uint8 volume_level,
                                kal_uint8 gain);

extern kal_bool l4c_eq_get_gain_req (kal_uint8 src_id,
                                kal_uint8 volume_type,
                                kal_uint8 volume_level);

extern kal_bool l4c_eq_exe_mute_req (kal_uint8 src_id,
                                kal_uint8 audio_device,
                                kal_bool mute_onoff);


extern kal_bool l4c_eq_get_mute_mode_req (kal_uint8 src_id,
                                     kal_uint8 audio_device,
                                     kal_bool *mute_onoff);

extern kal_bool l4c_eq_set_silent_mode_req (kal_uint8 src_id, kal_bool mode);
extern kal_bool l4c_eq_get_silent_mode_req (kal_uint8 src_id, kal_bool *mode);
extern kal_bool l4c_eq_set_speech_mode_req (kal_bool on_off);

extern kal_bool l4c_eq_set_audio_mode_req (kal_uint8 mode);/*audio_mode_enum */

extern kal_bool l4c_eq_get_adc_all_channel_start_req(void);

extern kal_bool  l4c_eq_get_adc_all_channel_stop_req(void);

extern kal_bool l4c_eq_set_vibrator_mode_req (kal_uint8 src_id,
                                    kal_uint8 mode);

extern kal_bool l4c_eq_exe_gpio_level_req (kal_uint8 src_id,
                                kal_uint8 gpio_dev_type,
                                kal_uint8 gpio_dev_level);


extern kal_bool l4c_eq_get_gpio_level_req (kal_uint8 src_id,
                                            kal_uint8 gpio_dev_type,
                                            kal_uint8 *gpio_dev_level);

/* voice memo */
#ifdef VM_SUPPORT
extern kal_bool l4c_eq_vm_get_info_req (kal_uint8 src_id);
extern kal_bool l4c_eq_vm_record_req (kal_uint8 src_id,kal_uint8 dir);
extern kal_bool l4c_eq_vm_stop_req (kal_uint8 src_id);
extern kal_bool l4c_eq_vm_abort_req (kal_uint8 src_id);
extern kal_bool l4c_eq_vm_pause_req (kal_uint8 src_id);
extern kal_bool l4c_eq_vm_resume_req (kal_uint8 src_id);
#ifdef __FS_ON__
extern kal_bool l4c_eq_vm_play_req (kal_uint8 src_id, kal_wchar *file_name);
extern kal_bool l4c_eq_vm_delete_req (kal_uint8 src_id,
                                      kal_wchar *file_name,
                                      kal_bool delete_all);
extern kal_bool l4c_eq_vm_append_req (kal_uint8 src_id, kal_wchar *file_name);
extern kal_bool l4c_eq_vm_rename_req (kal_uint8 src_id, kal_wchar *old_name,
                                       kal_wchar *new_name);
#else
extern kal_bool l4c_eq_vm_play_req (kal_uint8 src_id, kal_uint8 fileid);
extern kal_bool l4c_eq_vm_delete_req (kal_uint8 src_id,
                                      kal_uint8 fileid,
                                      kal_bool delete_all);
extern kal_bool l4c_eq_vm_append_req (kal_uint8 src_id, kal_uint8 fileid);
#endif
#endif


/* simulate keypad, indicator, lcd */

extern kal_bool l4c_eq_set_keypad_input_req (kal_uint8 src_id,
                              kal_uint8 *keycode,
                              kal_uint8 time,
                              kal_uint8 pause);

extern kal_bool l4c_eq_set_dspl_text_req (kal_uint8 src_id,
                                          kal_uint8 *text_string);

extern kal_bool l4c_eq_set_indicator_req (kal_uint8 src_id,
                                           kal_uint8 icon_id,
                                           kal_uint8 value);

extern kal_bool l4c_eq_get_indicator_req (kal_uint8 src_id,
                                           kal_uint8 icon_id,
                                           kal_uint8 *value);


/* rtc related, clock, alarm */

extern kal_bool l4c_eq_exe_rtc_time_req (kal_uint8 src_id,
                                          kal_uint8 rtc_type,
                                          kal_uint8 set_type,
                                          rtc_alarm_info_struct info);

extern kal_bool l4c_eq_set_rtc_time_req (kal_uint8 src_id,
                                          kal_uint8 rtc_type,
                                          kal_uint8 set_type,
                                          rtc_alarm_info_struct info);

extern kal_bool l4c_eq_get_rtc_time_req (kal_uint8 src_id,
                                          kal_uint8 rtc_type,
                                          kal_uint8 *num,
                                          rtc_alarm_info_struct *rtctime);

extern kal_bool l4c_eq_exe_rtc_delete_req (kal_uint8 src_id,
                                   kal_uint8 rtc_type,
                                   kal_uint8 rtc_index);

extern kal_bool l4c_eq_rtc_delete_req (kal_uint8 src_id,
                                   kal_uint8 rtc_type,
                                   kal_uint8 rtc_index);


extern kal_bool l4c_eq_set_date_time_format_req (kal_uint8 src_id,
                                             kal_bool is_date_set,
                                             kal_uint8 mode);

extern kal_bool l4c_eq_get_date_time_format_req (kal_uint8 src_id,
                                                  kal_bool is_date_set,
                                                  kal_uint8 *mode);

/* misc */

//extern kal_bool l4c_eq_set_language_req (kal_uint8 src_id, kal_uint8 *lang_code);
extern kal_bool l4c_eq_set_language_req (kal_uint8 src_id, kal_uint8 lang_code);

extern kal_bool l4c_eq_get_language_req (kal_uint8 src_id,
                                     kal_uint8 *lang_code);

/*
extern kal_bool l4c_eq_set_greeting_text_req (kal_uint8 src_id,
                                          kal_bool mode,
                                          kal_uint8 size,
                                          kal_uint8 *greeting_text);

extern kal_bool l4c_eq_get_greeting_text_req (kal_uint8 src_id,
                                               kal_bool *mode,
                                               kal_uint8 *greeting_text);
*/
extern kal_bool l4c_eq_set_greeting_text_req (kal_uint8 src_id,
                                   kal_bool mode,
                                   kal_uint8 dcs,
                                   kal_uint8 text[62],
                                   kal_uint8 length );

extern kal_bool l4c_eq_get_greeting_text_req (kal_uint8 src_id,
                                        kal_bool *mode,
                                        kal_uint8 *dcs,
                                        kal_uint8 *text,
                                        kal_uint8 *length
                                        );

extern kal_bool l4c_eq_set_country_code_req (kal_uint8 src_id,
                                     kal_uint8 country_code);

extern kal_bool l4c_eq_get_country_code_req (kal_uint8 src_id,
                                          kal_uint8 *country_code);





extern kal_bool l4c_eq_get_battery_status_req (kal_uint8 src_id,
                                           kal_uint8 *battery_status,
                                           kal_uint8 *battery_vol);

extern kal_bool l4c_eq_get_battery_capacity_status_req (kal_uint8 src_id,
                                    kal_uint8 *battery_status,
                                    kal_uint32 *battery_cap);

extern kal_bool l4c_eq_get_equip_id_req (kal_uint8 src_id,
                                     kal_uint8 equip_type,
                                     kal_uint8 *equip_id);

extern kal_bool l4c_eq_load_default_config_req (kal_uint8 src_id);

extern kal_bool l4c_eq_load_power_on_data_req (kal_uint8 src_id,
                                    kal_bool read_flag,
                                    kal_uint8 file_idx);

extern kal_bool l4c_eq_set_uart_port_req (kal_uint8 src_id,
                                   kal_uint8 func_id,
                                   kal_uint8 ps_port,
                                   kal_uint8 tst_port_ps,
                                   kal_uint32 ps_baud_rate,
                                   kal_uint32 tst_baud_rate_ps,
                                   kal_bool High_Speed_SIM_Enabled,
                                   kal_uint8 swdbg,
                                   kal_uint8 uart_power_setting,
                                   kal_uint8 cti_uart_port,
                                   kal_uint32 cti_baud_rate,
					kal_uint8 tst_port_l1,
					kal_uint32 tst_baud_rate_l1);

extern kal_bool l4c_eq_get_uart_port_req (kal_uint8 src_id);

extern kal_bool l4c_eq_read_nvram_req (kal_uint8 src_id,
                                kal_uint8 file_idx,
                                kal_uint16 para,
                                kal_uint16 rec_amount);

extern kal_bool l4c_eq_write_nvram_req (kal_uint8 src_id,
                                 kal_uint8 file_idx,
                                 kal_uint16 para,
                                 kal_uint8 *data,
                                 kal_uint16 length);

extern kal_bool l4c_eq_reset_nvram_req  (kal_uint8 src_id,
                                 kal_uint8 reset_category,
                                 kal_uint8 lid);

extern kal_bool l4c_eq_power_off_req (kal_uint8 src_id);

extern eventid l4c_set_timer_req (void *timeout_hdlr,
                             kal_uint16 time,
                             void *param);

extern kal_bool l4c_stop_timer_req (eventid event_id);

/*
extern kal_bool l4c_test_te_data_rate (kal_uint8 const  **buffer);

extern kal_bool l4c_test_char_set (kal_uint8 const  **buffer);
*/

extern kal_bool l4c_test_functionality_mode (kal_uint8 const  **buffer);

extern kal_bool l4c_exe_functionality_req (kal_uint8 src_id,
                                    kal_uint8 fun,
                                    kal_uint8 rst);

extern kal_bool l4c_em_keypad_event_output_req(kal_uint8 src_id,
									kal_uint8 keypad_status,
                               		kal_uint8 keypad_code);

extern kal_bool l4c_em_lcm_test_ind(kal_uint8 src_id,
									kal_uint8 color_type);

extern kal_bool l4c_update_mmi_default_prof_value_req (kal_uint8 category,
													kal_uint8 param1,
													kal_uint8 param2,
                                    				kal_uint8 param3);

extern kal_bool l4c_em_set_mmi_default_prof_ind(kal_uint8 src_id,
									kal_uint8 op,
									kal_uint8 category,
									kal_uint8 param1,
									kal_uint8 param2,
									kal_uint8 param3,
									kal_uint8 *param4);

extern kal_bool l4c_em_keypad_event_act_ind(kal_uint8 src_id,
												kal_bool on_off);

extern kal_bool l4c_em_lcm_sleep_mode_req_ind(kal_uint8 src_id,
									kal_uint8 on_off);

extern kal_bool l4c_eq_pattern_play_req (kal_uint8 src_id,
                                    kal_uint8 pattern,
                                    kal_uint8 action);

extern kal_bool l4c_eq_set_hw_level_req(kal_uint8 src_id,
									l4c_hw_profile_struct *hw_profile);

extern kal_bool l4c_eq_get_hw_level_req (kal_uint8 src_id, 
									  l4c_hw_profile_struct *hw_profile);

extern kal_bool l4c_eq_read_ms_sn_req (kal_uint8 src_id,
                                kal_uint8 file_idx,
                                kal_uint8 para);

extern kal_bool l4c_eq_read_ms_imei_req (kal_uint8 src_id,
                                kal_uint8 file_idx,
                                kal_uint8 para);

extern kal_bool l4c_eq_read_autotest_report_req (kal_uint8 src_id,
                                kal_uint8 file_idx,
                                kal_uint8 para);

extern kal_bool l4c_eq_read_prefer_band_req (kal_uint8 src_id, kal_uint16 action);

extern kal_bool l4c_eq_set_prefer_band_req (kal_uint8 src_id,
									kal_uint8 *data,
									kal_uint16 length );


#ifdef __IRDA_SUPPORT__
extern kal_bool l4c_eq_irda_open_req(kal_uint16 wait_duration);

extern kal_bool l4c_eq_irda_close_req(void);
#endif

#ifdef __USB_ENABLE__

extern kal_bool l4c_eq_usbconfig_req(kal_uint8 src_id, kal_uint8 mode, kal_uint32 reserved);
extern kal_bool l4c_eq_usbuart_switch_port_req(kal_uint8 src_id, kal_uint8 app, UART_PORT new_port);
	
#endif /* __USB_ENABLE__ */
extern kal_bool l4c_eq_set_ms_sn_req (kal_uint8 src_id,
									kal_uint8 *data,
									kal_uint8 length );

extern kal_bool l4c_eq_set_ms_imei_req (kal_uint8 src_id,
									kal_uint8 *data,
									kal_uint8 length );

extern kal_bool l4c_eq_set_attach_default_req (kal_uint8 src_id,
									kal_uint8 mode);

extern kal_bool l4c_eq_lock_nvram_req (kal_uint8 src_id,
									kal_uint8 mode );/*nvram_lock_state_enum*/

extern kal_bool l4c_em_sleep_mode_req(kal_bool on_off);

extern kal_bool l4c_eq_rtc_poweron_state_req(void);


extern kal_bool l4c_eq_data_dl_filelist_report_req(kal_uint8 src_id,
	                                    kal_uint8 dload_folder,
					    				void  *file_list,
					    				kal_uint8 total_files );

extern kal_bool l4c_eq_data_dl_file_modify_req(kal_bool result);

extern kal_bool l4c_eq_data_dl_execute_req(kal_bool result);

extern kal_bool l4c_eq_fs_av_disk_size_req(kal_uint8 src_id,kal_uint32 *av_size, char disk);

extern kal_bool l4c_eq_fs_filelist_req(kal_uint8 src_id, kal_wchar *foldername);

extern kal_bool l4c_eq_fs_folder_action_req(kal_uint8 src_id,
                                 rmmi_fs_opcode_enum action,
                                 kal_wchar *foldername);

extern void l4c_mms_folder_status_output_req(kal_uint8 result,
                                    kal_uint32 numOfMsg,
                                    kal_uint32 numOfUnreadMsg,
                                    kal_uint8* mmsHomeDirectory,
                                    kal_uint8* infoFilePath);
extern void l4c_mms_upload_msg_output_req(kal_uint8 result,
                                    kal_uint32 msgId);
extern void l4c_mms_delete_msg_output_req(kal_uint8 result);

extern void l4c_eq_at_alarm_set_res_req(kal_bool result);
extern void l4c_eq_at_alarm_delete_res_req(kal_bool result);
extern void l4c_eq_at_alarm_query_res_req(kal_uint8 totalAlarm, kal_uint8 activeAlarm, mmi_at_alarm_info_struct* alarmList);

extern void l4c_eq_query_vibrator_mode_res_req(kal_bool mode);
extern void l4c_eq_query_silent_mode_res_req(kal_bool mode);
extern void l4c_eq_query_mute_mode_res_req(kal_bool mode);
extern void l4c_eq_query_greeting_text_res_req( kal_bool mode, kal_uint8 dcs, kal_uint8 *text,  kal_uint8 length);
extern void l4c_eq_query_language_res_req( kal_uint8 lang_code);
extern void l4c_eq_query_datetime_format_res_req(kal_bool  is_date,kal_uint8  mode);
extern void l4c_mmi_java_local_install_res_req(kal_uint32 error_code);

extern void l4c_eq_pmic_config_req(kal_uint8 src_id, kal_uint8 request_type, pmic_config_param_struct request);
extern void l4c_eq_usbdetect_res_req(kal_uint8 src_id, kal_uint8 action);
extern void l4c_eq_battery_status_res_req(kal_uint8 src_id, kal_uint8 status_type);
extern kal_bool l4c_bt_set_vr_req(kal_uint8 src_id, kal_bool on_off);
extern void l4c_eq_vcard_res_req(kal_uint8 mode, kal_bool result, kal_uint8 *file_path);
extern void l4c_eq_vcalendar_res_req(kal_uint8 mode, kal_bool result, kal_uint8 cause, kal_uint8 number, kal_uint8 *file_path);
extern void l4c_eq_str_res_req(kal_uint16 length, kal_uint8 *data_string);

//#if defined(DCM_ENABLE)
extern void l4c_eq_dcm_enable_req(kal_uint8 src_id, kal_bool enable);
//#endif

extern void l4c_eq_rf_test_gsm_req(kal_uint8 src_id, kal_uint8 request_type, rf_test_gsm_param_struct request);
extern void l4c_eq_fm_radio_config_req(kal_uint8 src_id, kal_uint8 request_type, fm_radio_config_param_struct request);
extern void l4c_eq_rf_test_wifi_req(kal_uint8 src_id, kal_uint8 request_type, rf_test_wifi_param_struct request);
extern void l4c_mmi_eq_call_status_req(kal_uint8 src_id, kal_uint8 call_status);

#endif /* l4c_eq_cmd.h */


