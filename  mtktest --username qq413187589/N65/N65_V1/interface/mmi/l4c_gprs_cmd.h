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
 *	l4c_gprs_cmd.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _L4C_GPRS_CMD_H
#define _L4C_GPRS_CMD_H

extern kal_bool l4c_ps_exe_act_req (kal_uint8 src_id,
                                kal_uint8 opcode,
                                kal_uint8 cid);

extern kal_bool l4c_ps_exe_act_test_req (kal_uint8 src_id,
                             kal_uint8 opcode,
                             kal_uint8 cid);

extern kal_bool l4c_ps_get_context_state_req (kal_uint8 src_id,
                                              kal_uint8 *num,
                                              kal_uint8 *state_list);

extern kal_bool l4c_ps_exe_answer_req (kal_uint8 src_id,
                                   kal_uint8 ans,
                                   kal_uint8 l2p,
                                   kal_uint8 cid);

extern kal_bool l4c_ps_set_auto_answer_req (kal_uint8 src_id,
                                        kal_uint8 mode);

extern kal_bool l4c_ps_get_auto_answer_req (kal_uint8 src_id,
                                            kal_uint8 *mode);

extern kal_bool l4c_ps_exe_modify_req (kal_uint8 src_id, kal_uint8 cid);

extern kal_bool l4c_ps_exe_enter_data_state_req (kal_uint8 src_id,
                                             kal_uint8 l2p,
                                             kal_uint8 cid);

extern kal_bool l4c_ps_get_gprs_data_counter_req(l4c_gprs_statistics_info_struct *counter_info);

extern kal_bool l4c_ps_reset_gprs_data_counter_req(kal_uint8 src_id);

extern kal_bool l4c_ps_set_gprs_data_account_req(kal_uint8 src_id,
											l4c_gprs_account_info_struct *gprs_account);

extern kal_bool l4c_ps_get_gprs_data_account_req(kal_uint8 src_id, kal_uint8 profile_id);

extern kal_bool l4c_ps_set_definition_req (kal_uint8 src_id,
                                           l4c_prim_pdp_info_struct *pdp);

extern kal_bool l4c_ps_get_definition_list_req (kal_uint8 src_id,
                                         l4c_prim_pdp_info_list_struct *info);

extern kal_bool l4c_ps_set_sec_definition_req (kal_uint8 src_id,
                                               l4c_sec_pdp_info_struct *pdp);

extern kal_bool l4c_ps_get_sec_definition_list_req (kal_uint8 src_id,
                                         l4c_sec_pdp_info_list_struct *info);

extern kal_bool l4c_ps_get_pdp_addr_req (kal_uint8 src_id,
                                         kal_uint8 cid,
                                         kal_uint8 *addr);

extern kal_bool l4c_ps_set_qos_req (kal_uint8 src_id,
                                    kal_uint8 qos_type,
                                        l4c_qos_struct *min);

extern kal_bool l4c_ps_get_qos_req (kal_uint8 src_id, kal_uint8 qos_type,
                                 l4c_qos_list_struct *info);

extern kal_bool l4c_ps_set_tft_req (kal_uint8 src_id,
                                    l4c_tft_struct *tft);

extern kal_bool l4c_ps_get_tft_req (kal_uint8 src_id,
                             l4c_tft_struct *info);

extern kal_bool l4c_ps_exe_send_data_req (kal_uint8 src_id,
					kal_uint8 cid,
                                   kal_uint32 size);

extern kal_bool l4c_tcm_get_empty_gprs_prof_req (kal_uint8 src_id,
                                             kal_uint8 *entry_num);

extern kal_bool l4c_tcm_set_ppp_auth_info_req (kal_uint8 src_id,
													kal_uint8 context_id,
											        kal_uint8 is_chap);

extern kal_bool l4c_ppp_deactivate_req (kal_uint8 nsapi);

extern kal_bool l4c_ps_gprs_resume_req (kal_uint8 src_id);


extern kal_bool l4c_ps_set_eqos_req (kal_uint8 src_id,
                                    kal_uint8 qos_type,
                                        l4c_eqos_struct *min);

extern kal_bool l4c_ps_get_eqos_req (kal_uint8 src_id, kal_uint8 qos_type,
                                 l4c_eqos_list_struct *info);
                           
extern kal_bool l4c_ps_exe_undefine_req(kal_uint8 src_id, 
									kal_uint8 cid, 
									kal_uint16 undef_action);  

#endif


