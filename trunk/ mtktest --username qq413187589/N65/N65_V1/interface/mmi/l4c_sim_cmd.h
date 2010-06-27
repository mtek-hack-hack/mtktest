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
 *	l4c_sim_cmd.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#ifndef _L4C_SIM_CMD_H
#define _L4C_SIM_CMD_H


enum
{
  NONE_TYPE,
  PHONELOCK_TYPE,
  PIN1_TYPE
};

extern kal_bool l4c_smu_get_imsi_req (kal_uint8 src_id,
                                      kal_uint8 *imsi);

extern kal_bool l4c_smu_exe_lock_req (kal_uint8 src_id,
                                  kal_uint8 opcode, /* smu_lock_opcode_enum */
                                  kal_uint8 type,  /* smu_security_type_enum */
                                  kal_uint8 *passwd);

extern kal_bool l4c_smu_exe_master_reset_req (kal_uint8 src_id,
                                          kal_uint8 *pin);

extern kal_bool l4c_smu_get_dial_mode_req(/* sim_dn_enum */ kal_uint8 *dial_mode);

extern kal_bool l4c_smu_exe_verify_pin_req (kal_uint8 src_id,
                                            kal_uint8 pin_type,
                                            kal_uint8 *pin,
                                            kal_uint8 *new_pin);

extern kal_bool l4c_smu_get_pin_type_req (kal_uint8 src_id,
                                                   /* smu_security_type_enum */
                                                   kal_uint8 *name);

extern kal_uint16 file_idx_for_preferred_oper_list(void);

extern kal_bool l4c_smu_set_preferred_oper_list_req (kal_uint8 src_id,
                                                 kal_uint8 index,
                                                 kal_uint8 opcode,
                                                 kal_uint8 *oper,
                                                 kal_uint8 rat);

extern kal_bool l4c_smu_get_preferred_oper_list_req (kal_uint8 src_id,
                                                     kal_uint8 index,
                                                     kal_uint16 file_idx_req,
                                                     kal_uint16 *num,
                                                     kal_uint8 *oper_list,
                                                     kal_uint8 *rat_list,
                                                     kal_uint16 *file_idx_rsp);

extern kal_bool l4c_smu_set_puc_params_req (kal_uint8 src_id,
                                        kal_uint8 *pin,
                                        kal_uint8 *currency,
                                        kal_uint8 *ppu);

extern kal_bool l4c_smu_get_puc_params_req (kal_uint8 src_id,
                                            kal_uint8 *currency,
                                            kal_uint8 *ppu);

extern kal_bool l4c_smu_exe_change_password_req (kal_uint8 src_id,
                                             /* smu_security_type_enum */
                                             kal_uint8 type,
                                             kal_uint8 *old,
                                             kal_uint8 *new1,
                                             kal_uint8 *new2);

extern kal_bool l4c_smu_exe_restricted_access_req (kal_uint8 src_id,
                                               kal_uint8 cmd,
                                               kal_uint16 file_id,
                                               kal_uint8 p1,
                                               kal_uint8 p2,
                                               kal_uint8 p3,
                                               kal_uint8 *data);

extern kal_bool l4c_smu_exe_dial_mode_req (kal_uint8 src_id,
                                    kal_uint8 type,
                                    kal_uint8 on_off,
                                    kal_uint8 *pin);

extern kal_bool l4c_smu_write_sim_req (kal_uint8 src_id,
                                kal_uint8 file_idx,
                                 kal_uint8 para,
                                 kal_uint8 *data,
                                 kal_uint16 length,
                                 kal_uint8 *path);

extern kal_bool l4c_smu_read_sim_req (kal_uint8 src_id,
                               kal_uint8 file_idx,
                               kal_uint16 para,
                               kal_uint16 length,
                               kal_uint8 *path);

extern kal_bool l4c_smu_read_file_info_req (kal_uint8 src_id,
                               kal_uint8 file_idx,
                               kal_uint8 *path);

extern kal_bool l4c_smu_set_personalization_req(kal_uint8 src_id,
                                                kal_uint8 category,
                                                kal_uint8 op,
                                                kal_uint8 key[8],
                                                kal_uint8 len,
                                                kal_uint8 data[10]);

extern kal_bool l4c_smu_sml_status_req(kal_uint8 src_id);

extern kal_bool l4c_sim_power_off_req (kal_uint8 src_id);

extern kal_bool l4c_sim_remove_req (kal_uint8 src_id, kal_uint8 mode);

extern kal_bool l4c_sim_check_pin_status_req (sim_chv_info_struct *chv_info,
                                       sim_chv_status_struct *chv_status);

extern kal_bool l4c_cphs_update_als_req (kal_uint8 src_id,
                                     kal_uint8 line_id);

extern void l4c_sim_pin_convert(kal_uint8 *dest, kal_uint8 *src);
#ifdef __SAT__
extern kal_bool l4c_sat_dspl_text_res (sat_dspl_text_res_struct *local_ptr);

extern kal_bool l4c_sat_get_inkey_res (sat_get_inkey_res_struct *local_ptr,
                                sat_get_inkey_res_peer_struct *peer_ptr);

extern kal_bool l4c_sat_get_input_res (sat_get_input_res_struct *local_ptr,
                                sat_get_input_res_peer_struct *peer_ptr);

extern kal_bool l4c_sat_setup_menu_res (sat_setup_menu_res_struct *local_ptr);

extern kal_bool l4c_sat_select_item_res
                                 (sat_select_item_res_struct *local_ptr);

extern kal_bool l4c_sat_play_tone_res (sat_play_tone_res_struct *local_ptr);

extern kal_bool l4c_sat_setup_call_res (sat_setup_call_res_struct *local_ptr);

extern kal_bool l4c_sat_send_sms_res
                                 (sat_send_sms_res_struct *local_ptr);

extern kal_bool l4c_sat_send_ss_res (sat_send_ss_res_struct *local_ptr);

extern kal_bool l4c_sat_send_ussd_res (sat_send_ussd_res_struct *local_ptr);

extern kal_bool l4c_sat_setup_idle_dspl_res (sat_setup_idle_dspl_res_struct *local_ptr);

extern kal_bool l4c_sat_run_at_command_res (sat_run_at_command_res_struct *local_ptr);

extern kal_bool l4c_sat_send_dtmf_res (kal_uint8 cmd_detail[5],kal_uint8 res, kal_uint8 additional_info);

extern kal_bool l4c_sat_lang_notify_res (sat_lang_notify_res_struct *local_ptr);

extern kal_bool l4c_sat_launch_browser_res (kal_uint8 cmd_detail[5],
											    kal_uint8 res,
											    kal_uint8 size_of_additional_info,
											    kal_uint8 additional_info[255]);

extern kal_bool l4c_sat_exe_menu_select_req(sat_menu_select_req_struct *local_ptr);

extern kal_bool l4c_sat_evdl_idle_screen_available_req (void);

extern kal_bool l4c_sat_evdl_language_selection_req(kal_uint8 iso639_language[2]);

extern kal_bool l4c_sat_evdl_browser_termination_req(kal_uint8 browser_termination_cause);

extern kal_bool l4c_sat_open_channel_req (kal_uint8 cmd_detail[5],
					  kal_uint8  res,
					  kal_uint8 additional_info);

extern kal_bool l4c_sat_close_channel_req (kal_uint8 cmd_detail[5],
										kal_uint8 res);

extern kal_bool l4c_sat_send_data_req (kal_uint8 cmd_detail[5],kal_uint8 res);

extern kal_bool l4c_sat_recv_data_req (kal_uint8 cmd_detail[5],kal_uint8 res);

extern kal_bool l4c_sat_call_setup_req (
                        l4ccsm_cc_sat_setup_req_struct *local_ptr,
                        kal_uint8 *peer_ptr, kal_uint16 length);

extern kal_bool l4c_sat_send_dtmf_req (kal_uint8 src_id, kal_uint8 *dtmf_digit, kal_uint8 no_digit);

extern kal_bool l4c_sat_abort_dtmf_req (kal_uint8 src_id);

//mtk01616  070410 : sat_ussd use l4ccsm_ciss_ss_parse_req instead of l4ccsm_ciss_pussr_begin_req
extern kal_bool l4c_sat_send_ussd_req
                     (l4ccsm_ciss_ss_parse_req_struct  *local_ptr);


extern kal_bool l4c_sat_send_sms_req (l4csmsal_sat_send_req_struct *local_ptr);

#ifdef __RSAT__
extern kal_bool l4c_sat_profile_download_req(kal_uint8 length, kal_uint8 *profile);
extern kal_bool l4c_sat_terminal_rsp(kal_uint8 length, kal_uint8 *terminal_rsp);
extern kal_bool l4c_sat_envelope_req(kal_uint8 length, kal_uint8 *envelope);
extern kal_bool l4c_sat_setup_sms();
extern kal_bool l4c_sat_setup_ss();
extern kal_bool l4c_sat_setup_ussd();
extern kal_bool l4c_sat_setup_call();
extern kal_bool l4c_sat_dtmf();
#endif /* __RSAT__ */

#endif /* __SAT__ */

extern void l4c_smu_sim_status_update_req (kal_uint8 new_sim_config);
extern void l4c_smu_dual_sim_to_flight_mode_req (void);
#endif


