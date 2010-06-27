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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/
 /*****************************************************************************
 *
 * Filename:
 * ---------
 *  CertManMMIProts.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 * This file contains declaration of all the functions
 *
 * Author:
 * ------------
 * -------
 *
************************************************************************************/
#ifndef MMI_CERTMAN_PROTS_H
#define MMI_CERTMAN_PROTS_H

#ifdef __CERTMAN_SUPPORT__

extern mmi_certman_context g_mmi_certman_context;

/**************************************************************************/
/*****************************IMPORT CERTIFICATES**************************/
/**************************************************************************/
extern void mmi_certman_import_init(void *msg);
extern void mmi_certman_start_import(void *filename);
extern void mmi_certman_import_state(void *);
extern void mmi_certman_handle_error(certman_error_enum error);
extern void mmi_certman_pre_entry_get_decryption_password(void);
extern void mmi_certman_decryption_pwd_lsk(void);
extern void mmi_certman_get_decryption_password(void);
extern void mmi_certman_check_decryption_pwd(U8 *pwd);
extern void mmi_certman_decr_pwd_length_validation(U8 *text_p, U8 *cursor_p, S32 length);
extern void mmi_certman_display_file_info(void);
extern void mmi_certman_pre_entry_display_file_info(void);
extern void mmi_certman_certificates_detail(void);
extern void mmi_certman_save_certificate(void);
extern void mmi_certman_display_certificate_contents(void);
extern void mmi_certman_display_certificate_rsk(void);
extern void mmi_certman_save_file(void);
extern void mmi_certman_get_certificate_inputs(void);
extern void mmi_certman_exit_certificate_inputs(void);
extern void mmi_certman_highlight_certificate_input_inline_item(S32 index);
extern void mmi_certman_certificate_input_inline_struct(void);
extern void mmi_certman_entry_select_key_usage_screen(void);
extern void mmi_certman_show_password_editer(void);
extern U16 mmi_certman_get_item_img_hdlr(S32 item_index, U8 state, PU8 *img_buff_p);
extern void mmi_certman_import_deinit(void);
extern void mmi_certman_exit_pwd_screen(void);
extern void mmi_certman_discard_file(void);
extern void mmi_certman_discard_certificate(void);
extern void mmi_certman_check_label(void);
extern void mmi_certman_import_insecure_root_certificate(void);
extern void mmi_certman_check_certificate_expiry(void);
extern void mmi_certman_exit_from_import(void);
extern void mmi_certman_display_file_info_lsk(void);
extern void mmi_certman_certificate_inputs_rsk(void);
extern void mmi_certman_cert_strncpy(U8 *Destination, U8 *Source, certman_dcs_enum dcs_type, U32 dest_size);
extern void mmi_certman_import_key_purpose_request(void);
extern void mmi_certman_import_error(void);
extern void mmi_certman_certificate_inputs_exit(void);
extern void mmi_certman_exit_from_import_with_gobackhistory(void);
extern void mmi_certman_pre_enter_install(void);
extern U16 mmi_certman_get_no_of_private_keys(void);

/**************************************************************************/
/*****************************lAUNCH /SELECT CERTIFICATES******************/
/**************************************************************************/

extern void mmi_certman_launch_select_state(void *msg);
extern void mmi_certman_launch_init(void *msg);
extern void mmi_certman_launch_certficate_manager(void);
extern void mmi_certman_highlight_authority_certificates(void);
extern void mmi_certman_highlight_user_certificates(void);
extern void mmi_certman_highlight_view_certificates(void);
extern void mmi_certman_highlight_delete_certificates(void);
extern void mmi_certman_highlight_delete_all_certificates(void);
extern void mmi_certman_highlight_key_usage_certificates(void);
extern void mmi_certman_entry_launch_certificate_manager(void);
extern void mmi_certman_display_authority_certificates(void);
extern void mmi_certman_display_user_certificates(void);
extern void mmi_certman_view_certificates(void);
extern void mmi_certman_delete_certificates(void);
extern void mmi_certman_delete_all_certificates(void);
extern void mmi_certman_exit_from_select_launch(void);
extern void mmi_certman_key_usages_certificates(void);
extern void mmi_certman_import_set_selected_listbox_and_goback(void);
extern void mmi_certman_update_certificate_list(certman_get_cert_list_by_group_cnf_struct *group_cnf);
extern void mmi_certman_display_certificate_list(void);
extern void mmi_certman_certificate_list_highlight_handler(S32 index);
extern pBOOL mmi_certman_get_certificates(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_certman_launch_options(void);
extern void mmi_certman_pre_delete_certificates(void);
extern void mmi_certman_pre_delete_all_certificates(void);
extern void mmi_certman_view_certificate_content(void);
extern void mmi_certman_exit_view(void);
extern void mmi_certman_launch_set_selected_listbox_and_goback(void);
extern void mmi_certman_set_key_purpose(U32 keypurpose);
extern U16 mmi_certman_get_item_hdlr(S32 item_index, UI_string_type str_buff);
extern void mmi_certman_exit_certificate_manager(void);
extern void mmi_certman_launch_deinit(void);

extern void mmi_certman_certificates_selection_list(void);
extern void mmi_certman_select_init(void *msg);
extern pBOOL mmi_certman_select_mem_init(void);
extern U16 mmi_certman_input_cert_label(S32 item_index, UI_string_type str_buff);
extern void mmi_certman_select_single_certificate(void);
extern void mmi_certman_select_multiple_certificate(void);
extern void mmi_certman_exit_select_certificate(void);

extern void mmi_certman_pre_entry_get_priv_key_password(void);
extern void mmi_certman_get_priv_key_password(void);
extern void mmi_certman_privkey_usage_password_ind(void *msg);
extern void mmi_certman_check_priv_key_pwd(void);
extern void mmi_certman_exit_priv_key_pwd_screen(void);
extern void mmi_certman_get_priv_key_password_ok(void);
extern void mmi_certman_pwd_length_validation(U8 *text_p, U8 *cursor_p, S32 length);
extern void mmi_certman_priv_key_confirmation(void);
extern void mmi_certman_priv_key_confirmation_yes(void);
extern void mmi_certman_priv_key_confirmation_no(void);
extern void mmi_certman_send_privkey_usage_confirm_ind(void *msg);
extern void mmi_certman_view_certificate_content_only(certman_cert_display_struct *cert_contents);
extern void mmi_certman_fill_certificate_contents_only(U8 *cert_info, certman_cert_display_struct *display_cert);

extern void mmi_certman_progress_screen(void);

extern void mmi_certman_mem_init(void);
extern void mmi_certman_entry_new_screen(U16 newscrnID, FuncPtr handler);
extern void mmi_certman_generic_exit_handler(void);
extern void mmi_certman_handle_responses(U32 SCREEN_ID, FuncPtr func);
extern pBOOL mmi_certman_check_screen_in_history(void);
extern pBOOL mmi_certman_check_detail_history(void);
extern void mmi_certman_state_handle(void);
extern void mmi_certman_handle_progress_response_entry(void);
extern void mmi_certman_pre_entry_display_certificate_list(void);
extern void mmi_certman_pre_entry_certificates_selection_list(void);
extern void mmi_certman_category57_entry_new_screen(U16 newscrnID, FuncPtr handler);
extern void mmi_certman_category57_exit_handler(void);
extern void mmi_certman_set_protocol_events(void);
extern void mmi_certman_display_message(U16 message);
extern void mmi_certman_full_screen_continue(void);
extern void mmi_certman_full_screen_popup(void);

/***************************************************************************/
/*****************************View / Invalid Certificate********************/
/***************************************************************************/
extern void mmi_certman_view_init(void *msg);
extern void mmi_certman_view_invalid_state(void *msg);
extern void mmi_certman_pre_entry_view_certificate_content(void);
extern void mmi_certman_pre_entry_view_certificate_contents_only(void);
extern void mmi_certman_entry_view_certificate_contents_only(void);
extern void mmi_certman_exit_view_invalid_certificate_contents_only(void);
extern void mmi_certman_back_view_invalid_certificate_contents_only(void);
extern void mmi_certman_view_invalid_deinit(void);
extern void mmi_certman_invalid_certificate_option(void);
extern void mmi_certman_invalid_cert_check_label(void);
extern void mmi_certman_highlight_invalid_cert_install(void);
extern void mmi_certman_highlight_invalid_cert_continue(void);
extern void mmi_certman_highlight_invalid_cert_cancel(void);
extern void mmi_certman_invalid_cert_install(void);
extern void mmi_certman_invalid_cert_continue(void);
extern void mmi_certman_invalid_cert_cancel(void);
extern void mmi_certman_input_invalid_cert_label(void);
extern U32 mmi_certman_error_string_id(void);
extern void mmi_certman_back_view_invalid_certificate_contents(void);

extern void mmi_certman_pre_entry_invalid_cert_label(void);
extern void mmi_certman_select_user_certificate_state(void *msg);
extern void mmi_certman_select_user_certificates_init(void *msg);
extern void mmi_certman_user_certificates_list_deinit(void);
extern void mmi_certman_select_user_certificate_lsk(void);
extern void mmi_certman_select_user_certificate_rsk(void);
extern void mmi_certman_pre_entry_display_user_certificate_list_by_issuer(void);
extern void mmi_certman_display_user_certificate_list_by_issuer(void);
extern void mmi_certman_exit_user_certificates_list(void);
extern void certman_update_issuer_cert_list(certman_get_cert_list_by_issuers_data_ind_struct *issuer_data);
extern void mmi_certman_exit_user_certificates_list_with_goback_history(void);
extern void mmi_certman_user_certificate_list_highlight_handler(S32 index);
extern pBOOL mmi_certman_get_personal_certificates(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);

extern void mmi_certman_refresh_display_list(void);
extern void mmi_certman_invalid_certificate_init(void *msg);
extern void mmi_certman_invalid_certificate_start(U8 *filename);
extern void mmi_certman_exit_view_invalid_certificate_contents_only_with_gobackhistory(void);
extern void mmi_certman_display_message_with_callback(U16 message, FuncPtr callback);
extern void mmi_certman_history_replace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func);
extern void mmi_certman_general_error_handler_if_screen_in_history(void);
extern void mmi_certman_handle_error_with_callback(certman_error_enum error, FuncPtr callback);
extern void mmi_certman_pre_entry_display_certificate_contents(void);
extern pBOOL mmi_certman_check_is_progress_screen_present(void);
extern void mmi_certman_displaypop_with_calback(
                U8 *string,
                U16 imageId,
                U8 imageOnBottom,
                U32 popupDuration,
                U8 toneId,
                FuncPtr f);
extern void mmi_certman_send_msg_on_queue(module_type src_mod, module_type dest_mod, void *data, U16 msg_id);

   /* Memory API's */

extern void *mmi_certman_malloc(kal_uint32 size);
extern void mmi_certman_free(void *p);
#endif /* __CERTMAN_SUPPORT__ */ 
#endif /* MMI_CERTMAN_PROTS_H */ 

