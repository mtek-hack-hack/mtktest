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
 *	l4c_sms_cmd.h
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


#ifndef _L4C_SMS_CMD_H
#define _L4C_SMS_CMD_H

extern kal_bool l4c_sms_set_profile_params_req(kal_uint8 src_id,
												kal_uint16 para_ind,
												kal_uint8 profile_no,
												kal_uint8 pid,
												kal_uint8 dcs,
												kal_uint8 vp,
												l4c_number_struct sc_addr,
												l4_name_struct profile_name);

extern kal_bool l4c_sms_get_profile_params_req(kal_uint8 src_id,
												kal_uint8 profile_no,
												kal_uint8 *pid,
												kal_uint8 *dcs,
												kal_uint8 *vp,
												l4c_number_struct *sc_addr,
												l4_name_struct *profile_name);


extern kal_bool l4c_sms_set_common_params_req(kal_uint8 src_id,
												kal_uint16 para_ind,
												kal_uint8 fo,
												kal_uint8 bearer_service,
												kal_uint8 status_report,
												kal_uint8 reply_path);


extern kal_bool l4c_sms_get_common_params_req(kal_uint8 src_id,
												kal_uint8 *fo,
												kal_uint8 *bearer_service,
												kal_uint8 *status_report,
												kal_uint8 *reply_path);
												
extern kal_bool l4c_sms_startup_read_next_req(kal_uint8 src_id);												


extern kal_bool l4c_sms_set_bearer_service_req (kal_uint8 src_id,
                                         kal_uint8 bearer);

extern kal_bool l4c_sms_get_bearer_service_req (kal_uint8 src_id,
                                         kal_uint8 *bearer);


extern kal_bool l4c_sms_exe_post_command_req (kal_uint8 src_id,
                                   kal_uint8 fo,
                                   kal_uint8 ct,
                                   kal_uint8 mn,
                                   kal_uint8 pid,
                                   l4c_number_struct dest,
                                   kal_uint8 length,
                                   kal_uint8 *cmd);

extern kal_bool l4c_sms_exe_post_command_pdu_req (kal_uint8 src_id,
                                                  kal_uint16 data_len,
                                                  kal_uint16 length,
                                                  kal_uint8 *pdu);

extern kal_bool l4c_sms_exe_delete_msg_req (kal_uint8 src_id,
                                 kal_uint8 del_flag,
                                 kal_uint16 index,
                                 kal_uint8 *del_bitmap,
                                 kal_bool is_background_action);

extern kal_bool l4c_sms_set_msg_format_req (kal_uint8 src_id,
                                     kal_uint8 format);

extern kal_bool l4c_sms_get_msg_format_req (kal_uint8 src_id,
                                     kal_uint8 *format);

extern kal_bool l4c_sms_exe_read_msg_list_req (kal_uint8 src_id,
					 kal_uint8 change_status,
                                    kal_uint8 status,
                                    kal_uint16 start_index,
                                    kal_uint8 no_msg);

extern kal_bool l4c_sms_send_from_storage_req(kal_uint8 src_id,
					kal_uint16 index ,
					kal_bool addr_present,
					l4c_number_struct da,
					kal_bool need_delete);

extern kal_bool l4c_sms_set_status_req(kal_uint8 src_id,
					kal_uint8 new_status , 
					kal_uint16 index,
					kal_bool is_background_action);

extern kal_bool l4c_sms_exe_read_msg_req (kal_uint8 src_id,
                               kal_uint16 index,
                               kal_bool change_status);

extern kal_bool l4c_sms_exe_post_msg_req (kal_uint8 src_id,
                               kal_uint8 profile,
                               kal_uint16 reply_index,
                               l4c_number_struct dest,
                               kal_uint8 para,
                               l4c_number_struct sc_addr,
                               kal_uint8 vp,
                               smsal_pid_enum pid,
                               kal_uint8 udhi,
                               smsal_dcs_enum dcs,
                               kal_uint16 length,
                               kal_uint8 *msg,
                               kal_uint8 seq_num,
                               kal_uint8 mms_mode);

extern kal_bool l4c_sms_exe_post_pdu_req (kal_uint8 src_id,
                                          kal_uint16 reply_index,
                                          kal_uint16 data_len,
                                          kal_uint16 length,
                                          kal_uint8 *pdu);

extern kal_bool l4c_sms_exe_write_msg_req (kal_uint8 src_id,
                                kal_uint8 profile,
                                kal_uint8 status,
                                l4c_number_struct dest,
                                kal_uint8 para,
                                l4c_number_struct sc_addr,
                                kal_uint8 *scts,
                                kal_uint8 vp,
                                kal_uint8 pid,
                                kal_uint8 udhi,
                                kal_uint8 dcs,
                                kal_uint16 index,
                                kal_uint16 length,
                                kal_uint8 *msg);

extern kal_bool l4c_sms_exe_write_pdu_req (kal_uint8 src_id,
                                           kal_uint8 status,
                                           kal_uint16 data_len,
                                           kal_uint16 length,
                                           kal_uint8 *pdu);

extern kal_bool l4c_sms_set_more_req (kal_uint8 src_id,
                               kal_uint8 mode);

extern kal_bool l4c_sms_get_more_req (kal_uint8 src_id,
                               kal_uint8 *mode);

extern kal_bool l4c_sms_exe_storage_post_req (kal_uint8 src_id,
                                   //kal_uint8 concat_flag,
                                   kal_uint16 index,
                                   kal_uint16 reply_index,
                                   kal_bool addr_present,
                                   l4c_number_struct dest);

extern kal_bool l4c_sms_set_msg_ind_mode_req (kal_uint8 src_id,
                                              kal_uint8 mode,
                                              kal_uint8 mt,
                                              kal_uint8 bm,
                                              kal_uint8 ds);

extern kal_bool l4c_sms_get_msg_ind_mode_req (kal_uint8 src_id,
                                              kal_uint8 *mode,
                                              kal_uint8 *mt,
                                              kal_uint8 *bm,
                                              kal_uint8 *ds);

extern kal_bool l4c_sms_exe_send_ack_req (kal_uint8 src_id,
                                         kal_uint8 mode,
                                         kal_uint16 length,
                                         kal_uint8 *ack);

extern kal_bool l4c_sms_set_preferred_mem_req (kal_uint8 src_id,
                                        kal_uint8 mem1,
                                        kal_uint8 mem2,
                                        kal_uint8 mem3);

extern kal_bool l4c_sms_get_preferred_mem_req (kal_uint8 src_id,
                                    smsal_prefer_storage_struct *info);

extern kal_bool l4c_sms_set_service_mode_req (kal_uint8 src_id,
                                       kal_uint8 mode);

extern kal_bool l4c_sms_get_service_mode_req (kal_uint8 src_id,
                                       kal_uint8 *mode,
                                       smsal_service_mode_struct *info);

extern kal_bool l4c_sms_get_no_msgs_req (kal_uint8 src_id,
                                         //kal_bool  *is_sms_ready,
                                         kal_bool  *is_sim_card_change,
                                         kal_uint16 *in_sim_no,
                                         kal_uint16 *in_me_no,
                                         kal_uint16 *out_sim_no,
                                         kal_uint16 *out_me_no,
                                         kal_uint16 *unread_msg_num,
                                         kal_uint16 *total_sim_num,
                                         kal_uint16 *total_me_num);

extern kal_bool l4c_sms_get_no_profiles_req (kal_uint8 src_id,
                                         kal_uint8 *profile_no,
                                         kal_uint8 *name_len);

extern kal_bool l4c_sms_set_sc_addr_req (kal_uint8 src_id,
                                  kal_uint8 profile_no,
                                  l4c_number_struct sc_addr);

extern kal_bool l4c_sms_get_sc_addr_req (kal_uint8 src_id,
                                  kal_uint8 profile_no,
                                  l4c_number_struct *sc_addr);

extern kal_bool l4c_sms_set_post_params_req (kal_uint8 src_id,
                                      kal_uint8 profile_no,
                                      kal_uint16 para_ind,
                                      kal_uint8 fo,
                                      kal_uint8 pid,
                                      kal_uint8 dcs,
                                      kal_uint8 vp,
                                      kal_bool is_all_language_on,
                                      l4_name_struct *profile_name);

extern kal_bool l4c_sms_get_post_params_req (kal_uint8 src_id,
                                      kal_uint8 profile_no,
                                      kal_uint8 *fo,
                                      kal_uint8 *pid,
                                      kal_uint8 *dcs,
                                      kal_uint8 *vp,
                                      l4_name_struct *profile_name);
/*
extern kal_bool l4c_sms_exe_load_profile_req (kal_uint8 src_id,
                                   kal_uint8 index);

extern kal_bool l4c_sms_exe_save_profile_req (kal_uint8 src_id,
                                   kal_uint8 index);
*/
extern kal_bool l4c_sms_get_profile_name_req (kal_uint8 src_id,
                                         kal_uint8 profile_id,
                                         l4_name_struct *alpha_id);


extern kal_bool l4c_cb_subscribe_req (kal_uint8 src_id, kal_uint8 on_off);

extern kal_bool l4c_sms_set_cb_mode_req (kal_uint8 src_id,
                                  l4c_cb_info_struct *info);

extern kal_bool l4c_sms_get_cb_mode_req (kal_uint8 src_id,
                                  kal_uint8 *mode,
                                  kal_uint8 *total_mid_num,
                                  kal_uint8 *total_mir_num,
                                  kal_uint8 *total_dcs_num,
                                  l4c_cb_info_struct *info);

extern kal_bool l4c_sms_exe_abort_req (kal_uint8 src_id);

//mtk01616_070910
////extern kal_bool l4c_sms_mtcall_abort_req (kal_uint8 src_id);

extern kal_bool l4c_sms_get_mailbox_addr_req (kal_uint8 src_id,
											kal_uint8 *mailbox_num,
											kal_uint8 *alpha_length,
                                       		l4c_sms_mailbox_info_struct *mailbox_info);	

extern kal_bool l4c_sms_set_mailbox_addr_req (kal_uint8 src_id,
											kal_uint8 mailbox_num,
											l4c_number_struct num_addr,
											l4_name_struct name
                                            );	

extern kal_bool l4c_sms_reg_port_num_req (kal_uint8 src_id,
											kal_bool enable,
                                       		kal_uint32 port_num, 
                                       		kal_uint16 mod_id,
                                       		kal_uint16 *cause,
                                       		kal_uint32 *ret_port_num,
                                       		kal_uint16 *ret_mod_id
                                            );			

extern kal_bool l4c_sms_set_rmmi_sc_addr_req (kal_uint8 src_id,                                  
                                  			l4c_number_struct sc_addr);

extern kal_bool l4c_sms_set_rmmi_post_params_req (kal_uint8 src_id,
                                      kal_uint8 profile_no, //dummy
                                      kal_uint16 para_ind,
                                      kal_uint8 fo,
                                      kal_uint8 pid,
                                      kal_uint8 dcs,
                                      kal_uint8 vp);

extern kal_bool l4c_sms_exe_save_settings_req (kal_uint8 src_id,
                                         kal_uint8 profile_id);

extern kal_bool l4c_sms_exe_restore_settings_req (kal_uint8 src_id,
                                         kal_uint8 profile_id);

extern void l4c_smsal_fdn_check_rsp(kal_uint8 result, kal_uint16 cause);

extern kal_bool l4c_sms_copy_msg_req (kal_uint8 src_id,
				kal_uint8 action,
				kal_uint8 dst_storage,
				kal_uint16 src_index);

extern void l4c_sms_sync_msg_res_req(kal_bool result);


#endif


