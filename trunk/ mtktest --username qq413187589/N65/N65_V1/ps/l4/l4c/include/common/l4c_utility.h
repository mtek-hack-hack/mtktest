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
 *	l4c_utility.h
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


#ifndef _L4C_UTILITY_H
#define _L4C_UTILITY_H

typedef enum
{
   L4C_BASEBAND_CODE,
   L4C_DSP_CODE,
   L4C_DSP_PATCH,
   L4C_SW_CODE,
   L4C_HW_CODE
   
} l4c_ms_revision_enum;

typedef struct _CREE_MAP_ENTRY {
   unsigned int index;
   unsigned char *cree_str;
} CREE_MAP_ENTRY;

extern kal_bool is_proper_owner (kal_uint8 src_id);

extern kal_uint8 convert_to_bcd (kal_uint8 *source, kal_uint8 *dest, kal_uint8 max_dest_len);


extern kal_uint8 convert_to_digit (kal_uint8 *source, kal_uint8 *dest);

extern kal_uint8 convert_to_digit_ext (kal_uint8 *source, kal_uint8 *dest);

extern kal_uint8 convert_to_digit_24008 (kal_uint8 *source,
                       kal_uint8 *dest);

extern kal_uint8 plmn_convert_to_bcd (kal_uint8 *source, kal_uint8 *dest);

extern kal_uint8 plmn_convert_to_struct (kal_uint8 *source,
                               plmn_id_rat_struct *dest);

extern kal_uint8 plmn_convert_to_digit (plmn_id_rat_struct *source,
                                        kal_uint8 *dest);

extern kal_bool ss_string_skip_plus(kal_uint8 *source, kal_uint8 *dest);

extern kal_uint8 get_bcd_byte(kal_uint8 digit);

extern kal_uint8 get_ch_byte (kal_uint8 bcd);

extern kal_uint8 get_ch_byte_24008 (kal_uint8 bcd);

extern kal_bool is_cmd_conflict (kal_uint8 src_id, kal_uint8 action);

extern kal_bool is_phb_cmd_conflict(kal_uint8 src_id, kal_uint8 action);

extern kal_bool is_sms_cmd_conflict (kal_uint8 src_id, kal_uint8 action);

extern kal_bool is_ss_cmd_conflict(kal_uint8 src_id, kal_uint8 action);

//mtk01616_070707
extern kal_bool is_rac_cmd_conflict(kal_uint8 src_id, kal_uint8 action);

extern kal_bool is_tcm_cmd_conflict(kal_uint8 src_id, kal_uint8 action);

#ifdef __CTM_SUPPORT__
extern kal_bool is_ctm_cmd_conflict(kal_uint8 src_id, kal_uint8 action);
#endif

extern kal_uint8 l4c_conflict_search (kal_uint16 val);

extern kal_bool l4c_open_uart_port (void);

extern void l4c_obtain_uart_control(kal_uint8 port);

extern void l4c_cmux_startup_req(kal_uint8 port);

extern void l4c_cmux_closedown_req(void);

extern void l4c_set_uart_for_data (void);

extern void l4c_start_retry_timer_hdlr (kal_uint8 src_id);
//mtk01616_070515 : start 1 sec retry timer fro ss change phase request
extern void l4c_start_change_phase_retry_timer_hdlr(kal_uint8 src_id);

extern void l4c_get_downloadFullpath(kal_wchar * file_name);
extern void l4c_pause_download(void);
extern void l4c_resume_download(void);
extern void l4c_clear_download_timer(void);
extern void l4c_clear_rename_path(void);

extern void l4c_start_data_download_timer_hdlr (void);

extern kal_bool l4c_need_retry (kal_uint16 cause);

extern void l4c_retry_hdlr (void);

extern void l4c_send_msg_hdlr (kal_uint8 src_id);

extern void l4c_data_download_error_hdlr (void);

extern void fill_data (kal_uint8 *buff_ptr, kal_uint16 length);

extern kal_bool check_multi_command(kal_uint8 result);

extern void l4c_gprs_send_data_timer_hdlr (void);

extern void l4c_gprs_data_timeout_hdlr (void);

//mtk01616_070707
extern void l4c_gprs_connection_timer_hdlr(void);

extern void l4c_gprs_connection_timerout_hdlr (void);

extern void l4c_sim_poweroff_timer_hdlr(void);
extern void l4c_sim_poweroff_timerout_hdlr(void);
//extern kal_bool check_pdp_context_exist_func(void);

extern kal_bool get_ms_revision( kal_uint8 equip_type,
                   kal_uint8 *equip_id);

extern void l4c_convert_result(kal_uint8 l4c_result, kal_uint16 l4c_cause, kal_bool *result, kal_uint16 *cause);

extern kal_uint8 l4c_check_port_owner_source(kal_uint8 port);

extern void l4c_set_user_action(kal_uint8 mod, kal_uint8 user, kal_uint16 action);

extern kal_bool l4c_check_user_action(kal_uint8 mod, kal_uint8 user, kal_uint16 action);

extern kal_bool l4c_find_free_pdp_context(kal_uint8 *cid, kal_uint8 pid);

extern void l4c_find_pdp_pid2cid(kal_uint8 *cid, kal_uint8 pid);

extern void l4c_free_pdp_context(kal_uint8 cid, kal_uint8 *pid);

extern void l4c_ConvertGSM7BitDefaultEncodingToAscii (kal_uint8* message, kal_uint8* msg, kal_uint16 length, kal_uint16 *outLen);

extern kal_bool l4c_uart_setowner_to_dt(kal_uint8 src_id);
extern void l4c_set_download_path(kal_wchar *downlaod_path);

extern kal_bool has_any_current_action(kal_uint8 src_id);

extern kal_bool l4c_check_online_state(kal_uint8 *online_src_id);

extern kal_bool l4c_is_src_from_rmmi(kal_uint8 src_id);

//mtk01616_070601
extern void l4c_previous_rac_action_rsp(void);
//mtk01616_070910
//extern void l4c_clear_concat_sms_array (void);
extern kal_bool l4c_mmi_result(kal_uint8 result);

extern void l4c_check_dual_sim_insert_status(kal_uint8 sim1_inserted_status, kal_uint8 sim2_inserted_status);
extern void l4c_power_on_dual_sim(kal_uint8 power_on_state, kal_uint8 response, kal_uint8 type, kal_bool casue_present, kal_uint16 cause);
extern void l4c_get_dual_sim_info(kal_uint8 *dual_sim_mode_setting, kal_uint8 *dual_sim_inserted_status, kal_uint8 *dual_sim_uart_setting);
extern void l4c_send_dual_sim_power_on_ind(void);
extern void l4c_context_selection(kal_uint8 sim_interface);
extern kal_bool l4c_get_last_dialed_number(kal_uint8 *number,kal_uint8 *action_type);
extern void l4c_unified_ciev_staus(kal_uint8 *service,kal_uint8 *signal,kal_uint8 *roam);
extern kal_bool l4c_is_test_sim(void);
extern kal_bool l4c_is_sim_replaced(void);
extern kal_uint8 l4c_get_cfun_state(void);
extern kal_uint8 l4c_cc_ss_string_parsing(kal_uint8 *string_ptr, kal_uint8 length);

#endif /* l4c_utility.h */


