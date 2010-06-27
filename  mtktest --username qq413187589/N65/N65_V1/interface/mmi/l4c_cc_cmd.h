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
 *	l4c_cc_cmd.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _L4C_CC_CMD_H
#define _L4C_CC_CMD_H

extern kal_bool l4c_cc_exe_reset_acm_req (kal_uint8 src_id,
                                      kal_uint8 *pin);

extern kal_bool l4c_cc_get_acm_value_req (kal_uint8 src_id,
                                          kal_uint32 *acm);

extern kal_bool l4c_cc_set_acm_max_req (kal_uint8 src_id,
                                    kal_uint8 *pin,
                                    kal_uint32 val);

extern kal_bool l4c_cc_get_acm_max_req (kal_uint8 src_id,
                                        kal_uint32 *acm_max);

extern kal_bool l4c_cc_get_ccm_value_req (kal_uint8 src_id,
                                          kal_uint32 *ccm);

extern kal_bool l4c_cc_set_bearer_service_req (kal_uint8 src_id,
                                               kal_uint8 speed,
                                               kal_uint8 name,
                                               kal_uint8 ce);

extern kal_bool l4c_cc_get_bearer_service_req (kal_uint8 src_id,
                                               kal_uint8 *speed,
                                               kal_uint8 *name,
                                               kal_uint8 *ce);

extern kal_bool l4c_cc_set_line_req (kal_uint8 src_id, kal_uint8 line);

extern kal_bool l4c_cc_set_cug_params_req (kal_uint8 src_id,
                                           kal_uint8 index,
                                           kal_uint8 mode,
                                           kal_uint8 info);

extern kal_bool l4c_cc_get_cug_params_req (kal_uint8 src_id,
                                           kal_uint8 *index,
                                           kal_uint8 *mode,
                                           kal_uint8 *info);

extern kal_bool l4c_cc_exe_chld_req (kal_uint8 src_id,
                                 kal_uint8 opcode,   /* csmcc_crss_req_enum */
                                 kal_uint8 call_id);

extern kal_bool l4c_cc_exe_hangup_active_call_req (kal_uint8 src_id);

extern kal_bool l4c_cc_get_call_list_req (kal_uint8 src_id,
                                          l4c_call_list_struct *call_list);

extern kal_bool l4c_cc_set_call_mode_req (kal_uint8 src_id,
                                          kal_uint8 mode);

extern kal_bool l4c_cc_get_call_mode_req (kal_uint8 src_id,
                                          kal_uint8 *mode);

extern kal_bool l4c_cc_get_phone_activity_req (kal_uint8 src_id,
                                               kal_uint8 *act);

extern kal_bool l4c_cc_set_single_num_req (kal_uint8 src_id,
                                           kal_uint8 mode);

extern kal_bool l4c_cc_get_single_num_req (kal_uint8 src_id,
                                           kal_uint8 *mode);

extern kal_bool l4c_cc_exe_call_deflect_req (kal_uint8 src_id,
                                         l4c_number_struct dest,
                                         kal_bool sub_addr_flag,
                                         l4c_sub_addr_struct sub_dest);

extern kal_bool l4c_cc_exe_send_dtmf_req (kal_uint8 src_id,
                                      kal_uint8 digit);

extern kal_bool l4c_cc_exe_stop_dtmf_req (kal_uint8 src_id);

extern kal_bool l4c_cc_exe_start_auto_dtmf_req (kal_uint8 src_id,
                               kal_uint8 *digit);

extern kal_bool l4c_cc_exe_ata_req (kal_uint8 src_id);
#ifdef __SATCE__
extern kal_bool l4c_sat_csd_call_setup_req (kal_uint8 src_id,
                                kal_uint8 size_of_addr,
                                kal_uint8 *addr,
                                kal_uint8 size_of_subaddr,
                                kal_uint8 *subaddr,
                                kal_uint8 call_type,
                                sat_csd_bearer_para_struct bearer_para
                                );
#endif /* __SATCE__ */
extern kal_bool l4c_cc_exe_call_setup_req (kal_uint8 src_id,
                                       l4c_number_struct dest,
                                       kal_uint8 redial_count,
                                       kal_uint8 call_type,
                                       kal_uint8 clir_flag,
                                       /* csmcc_clir_info_enum */
                                       kal_bool cug_option);

extern kal_bool l4c_cc_exe_call_modify_req (kal_uint8 src_id);

extern kal_bool l4c_cc_exe_ath_req (kal_uint8 src_id,l4c_ath_req_enum op_code);

extern kal_bool l4c_cc_set_csd_profile_req (kal_uint8 src_id,
				     				 kal_uint8 prof_id,
				     				 kal_bool dns_addr_present,
                                     l4c_number_struct dest,
                                     kal_uint8 rate,
                                     kal_uint8 type,
                                     kal_uint8 csd_module,
                                     kal_uint8 auth_type,
                                     kal_uint8 *user_id,
                                     kal_uint8 *passwd,
                                     kal_uint8 *dns,
                                     l4_name_struct *name);

extern kal_bool l4c_cc_get_csd_profile_req (kal_uint8 src_id,
                                     kal_uint8 prof_id,
                                     l4c_number_struct *dest,
                                     kal_uint8 *rate,
                                     kal_uint8 *type,
                                     kal_uint8 *csd_module,
                                     kal_uint8 *auth_type,
                                     kal_uint8 *user_id,
                                     kal_uint8 *passwd,
                                     kal_uint8 *dns,
                                     l4_name_struct *name);

extern kal_bool l4c_cc_get_no_free_csd_profile_req (kal_uint8 src_id,
                                             kal_uint8 *no_entry);

extern void append_short_list (l4c_call_list_struct *output,
                        kal_uint8 index,
                        kal_uint8 call_id,
                        kal_uint8 call_state,
                        kal_uint8 mpty,
                        kal_uint8 *number);

extern kal_bool l4c_cc_exe_disc_aux_req (kal_uint8 src_id);

extern kal_bool l4c_cc_rel_comp_req(kal_uint8 src_id, kal_uint8 call_id);

extern kal_bool l4c_cc_get_inter_working_func_req(kal_uint8 src_id, kal_uint8 *iwf);

extern kal_bool l4c_cc_set_inter_working_func_req(kal_uint8 src_id, kal_uint8 iwf);

//#ifdef __VOIP__
extern void l4c_mmi_voip_at_call_ctrl_approve_req(kal_uint8 result, 
													kal_uint8 action, 
													void* string_ptr,
													void* node_ptr, 
													void* err_id);

//#endif

extern void l4c_mmi_ucm_at_res_req(kal_uint8 source_id,kal_uint8 result, kal_uint8 cause);

extern void l4c_mmi_ucm_rcode_req(kal_uint8 source_id, kal_uint8 type, kal_uint8 call_id ,kal_uint8 call_type,l4c_number_struct number);

extern void l4c_mmi_ucm_hf_ciev_req(kal_uint8 ind_type, kal_uint8 event);

#endif /* l4c_cc.h */


