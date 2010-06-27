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
 * VRSIProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the main header file for vrsi
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VRSIPROT_H
#define _MMI_VRSIPROT_H

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/* 
 * Define
 */

/* 
 * Typedef 
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
#define MMI_VRSI_MAIN_CMD
extern void mmi_vrsi_init(void);
extern void mmi_vrsi_init_central_add_all(void);
extern void mmi_vrsi_init_central_abort(void);
extern void mmi_vrsi_init_central_reset(void);
extern void mmi_vrsi_init_central_add_req(void);
extern void mmi_vrsi_init_central_done(void);
extern void mmi_vrsi_init_central_count_fail(U16 tag_num, U16 *id_list, S32 *long_list);
extern void mmi_vrsi_init_central_sync_tag(void);
extern void mmi_vrsi_entry_init_processing(void);
extern void mmi_vrsi_exit_init_processing(void);

extern void mmi_vrsi_rcg_pre_entry(void);
extern void mmi_vrsi_rcg_init(void (*entry_func) (void));
extern void mmi_vrsi_entry_rcg(void);
extern void mmi_vrsi_exit_rcg(void);
extern void mmi_vrsi_rcg_abort(void);
extern void mmi_vrsi_rcg_close(void);
extern void mmi_vrsi_rcg_start_command(void);
extern void mmi_vrsi_rcg_play_prompt_tone(void);
extern void mmi_vrsi_rcg_play_prompt_callback(mdi_result event);
extern void mmi_vrsi_rcg_read_result(void);
extern void mmi_vrsi_rcg_read_grammar1_result(void);
extern void mmi_vrsi_rcg_read_grammar2_result(void);
extern void mmi_vrsi_rcg_read_grammar3_result(void);
extern void mmi_vrsi_rcg_read_grammar4_result(void);
extern void mmi_vrsi_rcg_read_grammar5_result(void);
extern void mmi_vrsi_entry_help(void);
extern void mmi_vrsi_mdi_callback_hdlr(mdi_result result);
extern void mmi_vrsi_result_error_hdlr(void);
extern void mmi_vrsi_rcg_fail_retry(void (*retry_func) (void), void (*timeout_func) (void));

extern void mmi_vrsi_util_play_tts(U16 *tts_string, void (*tts_callback) (void));
extern S32 mmi_vrsi_util_play_tag(U8 grammar_id, U8 app_id, U16 tag_long, void (*tts_callback) (void));
extern S32 mmi_vrsi_util_play_name_tag(U8 grammar_id, U8 app_id, U16 tag_long, void (*tts_callback) (void));
extern void mmi_vrsi_util_check_legal_central_cmd(media_aud_vrsi_cmd_rcg_result_struct *lpRcg_result);
extern void mmi_vrsi_util_get_curr_language(void);

#if defined(__BT_SUPPORT__)
extern void mmi_vrsi_bt_set_ind_hdlr(void *msg);
extern void mmi_vrsi_bt_set_ind_cnf(BOOL success);
extern void mmi_vrsi_bt_set_req(BOOL is_activate);
extern void mmi_vrsi_bt_set_rsp_hdlr(void *msg);
extern void mmi_vrsi_bt_connect_sco_hdlr(void);
#endif /* defined(__BT_SUPPORT__) */ 

#define MMI_VRSI_GRAMMAR
extern void mmi_vrsi_grammar_init(void);
extern U32 mmi_vrsi_get_prompt_tone_size(void);

#define MMI_VRSI_SETTING
extern void mmi_vrsi_setting_init(void);

extern void mmi_vrsi_entry_setting_menu(void);
extern void mmi_vrsi_highlight_setting_menu(void);
extern void mmi_vrsi_highlight_rcg_enable(void);
extern void mmi_vrsi_hint_rcg_enable(U16 index);
extern void mmi_vrsi_rcg_enable_toggle(void);

#if defined(__MMI_VRSI_TRAIN_TAG__)
extern void mmi_vrsi_highlight_train_tag(void);
extern void mmi_vrsi_highlight_train_name_list(void);
extern void mmi_vrsi_highlight_train_shortcut_list(void);
extern void mmi_vrsi_highlight_train_city_list(void);
extern void mmi_vrsi_highlight_train_delete_all(void);
extern void mmi_vrsi_highlight_train_tag_status(void);
extern void mmi_vrsi_entry_train_tag_main(void);

extern void mmi_vrsi_highlight_train_option_add(void);
extern void mmi_vrsi_highlight_train_option_del(void);
extern void mmi_vrsi_highlight_train_option_playback(void);
extern void mmi_vrsi_entry_train_option_add(void);
extern void mmi_vrsi_entry_train_option_del(void);
extern void mmi_vrsi_entry_train_option(U8 type);
extern void mmi_vrsi_exit_train_option(void);
extern void mmi_vrsi_train_option_pre_add(void);
extern void mmi_vrsi_train_option_add_start(void);
extern void mmi_vrsi_entry_train_option_add_prompt(U8 prompt);
extern void mmi_vrsi_exit_train_option_add_prompt(void);
extern void mmi_vrsi_train_option_add_result(void);
extern void mmi_vrsi_train_option_delete_confirm(void);
extern void mmi_vrsi_train_option_pre_delete_tag(void);
extern void mmi_vrsi_train_option_delete_tag(void);
extern void mmi_vrsi_train_option_pre_playback(void);
extern void mmi_vrsi_train_option_playback(void);
extern void mmi_vrsi_train_option_playback_finish(void);

extern void mmi_vrsi_entry_train_delele_all_confirm(void);
extern void mmi_vrsi_train_pre_del_all_tag(void);
extern void mmi_vrsi_train_del_all_tag(void);

extern void mmi_vrsi_entry_train_status(void);
extern void mmi_vrsi_train_tag_status_print_string(U16 str_id, U16 count, S8 *tag_status);

extern U8 mmi_vrsi_train_util_get_id_and_loc(U8 app_id, U16 tag_long, U16 *tag_id);
extern U8 mmi_vrsi_train_util_get_loc_in_list(U8 app_id, U16 tag_long, vrsi_sd_tag_struct *tag_list);
extern void mmi_vrsi_train_util_del_tag(U8 app_id, U16 tag_long);
extern void mmi_vrsi_train_util_get_tag_count(U16 *count_list);
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

#if defined(__MMI_VRSI_DIGIT_ADAPT__)
extern void mmi_vrsi_highlight_digit_adapt(void);
extern void mmi_vrsi_digit_adapt_init(void);
extern void mmi_vrsi_entry_digit_adapt(void);
extern void mmi_vrsi_exit_digit_adapt(void);
extern void mmi_vrsi_digit_adapt_start(void);
extern void mmi_vrsi_entry_digit_adapt_prompt(void);
extern void mmi_vrsi_exit_digit_adapt_prompt(void);
extern void mmi_vrsi_digit_adapt_result(void);
#endif /* defined(__MMI_VRSI_DIGIT_ADAPT__) */ 

#define MMI_VRSI_NAME_DIAL
extern BOOL mmi_vrsi_ndial_central_phb_ready(void);
extern void mmi_vrsi_ndial_central_add_all(void *msg);
extern void mmi_vrsi_ndial_central_add_done(void);
extern void mmi_vrsi_ndial_central_add_single(U16 store_index);
extern void mmi_vrsi_ndial_central_delete_single(U16 store_index);
extern void mmi_vrsi_ndial_central_change_single(U16 store_index);
extern BOOL mmi_vrsi_ndial_central_check_state_and_start(void);

#if defined(__MMI_VRSI_TRAIN_TAG__)
extern BOOL mmi_vrsi_ndial_central_check_sim_change(void);
extern U16 mmi_vrsi_ndial_central_count_tag_in_sim(void);
extern void mmi_vrsi_ndial_central_delete_sd_tag_in_sim(void);
extern void mmi_vrsi_ndial_central_add_after_check(void);
extern void mmi_vrsi_ndial_central_update_sd_mapping(void);
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

extern void mmi_vrsi_entry_ndial_get_index(S32 nIndex);
extern void mmi_vrsi_ndial_rcg_grammar1_result(U16 tag_num, S32 *long_list);
extern U16 mmi_vrsi_ndial_rcg_grammar1_result_check(U16 tag_num, S32 *long_list);
extern void mmi_vrsi_entry_ndial_multiple_number(void);
extern void mmi_vrsi_exit_ndial_multiple_number(void);
extern void mmi_vrsi_entry_ndial_multiple_number_in_history(void);
extern void mmi_vrsi_ndial_multiple_number_pre_confirm(void);
extern U8 mmi_vrsi_ndial_multiple_number_show_data(S8 *str_prompt);
extern void mmi_vrsi_ndial_multiple_number_prompt(S8 *str_prompt);
extern void mmi_vrsi_ndial_multiple_number_prompt2(void);

extern void mmi_vrsi_entry_ndial_multiple_record(void);
extern void mmi_vrsi_exit_ndial_multiple_record(void);
extern void mmi_vrsi_entry_ndial_multiple_record_in_history(void);
extern void mmi_vrsi_ndial_multiple_record_to_single_record(void);
extern void mmi_vrsi_ndial_multiple_record_show_data(S8 *str_prompt);
extern void mmi_vrsi_ndial_multiple_record_show_hint(U8 **name_ptr);
extern void mmi_vrsi_ndial_multiple_record_prompt2(void);
extern void mmi_vrsi_ndial_multiple_record_prompt3(void);

extern void mmi_vrsi_ndial_pre_confirm_dial(U8 dial_loc);
extern void mmi_vrsi_entry_ndial_confirm_dial(void);
extern void mmi_vrsi_exit_ndial_confirm_dial(void);
extern void mmi_vrsi_entry_ndial_confirm_dial_in_history(void);
extern void mmi_vrsi_ndial_confirm_dial_show_data(S8 *str_prompt);
extern void mmi_vrsi_ndial_confirm_dial_show_data1(S8 *str_prompt);
extern void mmi_vrsi_ndial_confirm_dial_show_data2(S8 *str_prompt);
extern void mmi_vrsi_ndial_confirm_dial_show_data3(S8 *str_prompt);
extern void mmi_vrsi_ndial_confirm_dial_prompt2(void);
extern void mmi_vrsi_ndial_confirm_dial_prompt3(void);

extern void mmi_vrsi_ndial_no_number_show_data(S8 *str_prompt);
extern void mmi_vrsi_ndial_no_number_prompt(void);
extern void mmi_vrsi_ndial_no_number_prompt2(void);
extern void mmi_vrsi_ndial_dial_entry(void);

#if defined(__MMI_VRSI_TRAIN_TAG__)
extern void mmi_vrsi_ndial_train_list_pre_entry(void);
extern void mmi_vrsi_ndial_train_list_callback(U16 store_index);
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

#define MMI_VRSI_DIGITAL_DIAL
extern void mmi_vrsi_entry_ddial_rcg(void);
extern void mmi_vrsi_exit_ddial_rcg(void);
extern void mmi_vrsi_ddial_start_command(void);
extern void mmi_vrsi_ddial_start_command(void);
extern void mmi_vrsi_ddial_read_result(void);
extern void mmi_vrsi_entry_ddial_dial_confirm(void);
extern void mmi_vrsi_exit_ddial_dial_confirm(void);
extern void mmi_vrsi_entry_ddial_dial_confirm_in_history(void);
extern void mmi_vrsi_ddial_dial_number(void);

#define MMI_VRSI_NAME_QUERY
extern void mmi_vrsi_nquery_rcg_grammar1_result(U16 tag_num, S32 *long_list);
extern void mmi_vrsi_nquery_grammar5_prompt(void);

extern void mmi_vrsi_nquery_grammar5_prompt2(void);
extern void mmi_vrsi_nquery_grammar5_prompt3(void);
extern void mmi_vrsi_nquery_get_index(S32 nIndex);
extern void mmi_vrsi_pre_entry_nquery_list(void);
extern void mmi_vrsi_entry_nquery_list1(void);
extern void mmi_vrsi_entry_nquery_image_list1(void);
extern void mmi_vrsi_exit_nquery_list1(void);
extern void mmi_vrsi_entry_nquery_list1_in_history(void);
extern void mmi_vrsi_nquery_pre_entry_option(void);
extern void mmi_vrsi_nquery_pre_dial(void);
extern void mmi_vrsi_nquery_goto_previous(void);
extern void mmi_vrsi_nquery_goto_next(void);

#define MMI_VRSI_REDIAL
extern void mmi_vrsi_redial_rcg_grammar1_result(U16 rcg_result);
extern void mmi_vrsi_redial_read_call_log_num_req(U8 type);
extern void mmi_vrsi_redial_read_call_log_num_rsp(void *info);
extern void mmi_vrsi_redial_dial_prompt_message(S8 *str_prompt);
extern void mmi_vrsi_entry_redial_dial_prompt(void);
extern void mmi_vrsi_exit_redial_dial_prompt(void);
extern void mmi_vrsi_redial_dial_number(void);
extern void mmi_vrsi_redial_no_number(void);
extern void mmi_vrsi_redial_no_entry(void);

#define MMI_VRSI_PROFILE
extern void mmi_vrsi_prf_rcg_grammar1_result(U16 rcg_result);
extern void mmi_vrsi_prf_pre_switch_mode(void);
extern void mmi_vrsi_prf_switch_prompt_message(S8 *str_prompt);
extern void mmi_vrsi_entry_prf_switch_prompt(void);
extern void mmi_vrsi_exit_prf_switch_prompt(void);
extern void mmi_vrsi_prf_switch_mode(void);
extern void mmi_vrsi_prf_no_mode_prompt(void);
extern void mmi_vrsi_prf_cannot_switch_prompt(void);
extern void mmi_vrsi_prf_get_mode_prompt(S8 *str_prompt);

#define MMI_VRSI_SHORTCUT
extern void mmi_vrsi_scut_central_add_all(void *msg);
extern void mmi_vrsi_scut_central_add_done(void);

extern void mmi_vrsi_scut_rcg_grammar1_result(U16 tag_num, S32 *long_list);
extern void mmi_vrsi_entry_scut_open_app(void);
extern void mmi_vrsi_exit_scut_open_app(void);

#if defined(__MMI_VRSI_TRAIN_TAG__)
extern void mmi_vrsi_scut_open_app_play_prompt(S8 *str_prompt);
extern void mmi_vrsi_scut_open_app_play_prompt1(void);
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 
extern void mmi_vrsi_scut_open_app(void);
extern void mmi_vrsi_scut_no_app_prompt(void);

#if defined(__MMI_VRSI_TRAIN_TAG__)
extern void mmi_vrsi_scut_list_highlight_hdlr(S32 index);
extern void mmi_vrsi_entry_scut_list(void);
extern void mmi_vrsi_scut_pre_entry_train_main(void);
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

#define MMI_VRSI_CITY_QUERY
extern void mmi_vrsi_city_central_add_all(void *msg);

extern void mmi_vrsi_city_rcg_grammar1_result(U16 tag_num, S32 *long_list);

extern void mmi_vrsi_city_time_prompt(void);
extern void mmi_vrsi_city_time_prompt1(void);
extern void mmi_vrsi_entry_city_browse(void);
extern void mmi_vrsi_exit_city_browse(void);

extern void mmi_vrsi_city_not_exist_prompt(void);

#if defined(__MMI_VRSI_TRAIN_TAG__)
extern void mmi_vrsi_city_list_highlight_hdlr(S32 index);
extern void mmi_vrsi_entry_city_list(void);
extern void mmi_vrsi_city_pre_entry_train_main(void);

#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

#endif /* _MMI_VRSIPROT_H */ /* #ifndef _MMI_VRSIPROT_H */

