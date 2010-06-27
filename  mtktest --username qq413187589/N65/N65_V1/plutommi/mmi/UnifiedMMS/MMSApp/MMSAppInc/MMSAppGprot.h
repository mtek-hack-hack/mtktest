/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSAppGrot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file global API's Variables  and the context for MMS Application
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#ifndef __MMI_UMMS_APP_GPROT_H_
#define __MMI_UMMS_APP_GPROT_H_
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "custom_wap_config.h"
#include "UnifiedMessageGProt.h"
#include "MessagesResourceData.h"

#include "MMSAppProt.h"
#ifdef __MMI_VBOOKMARK__
#include "BrowserBookmarks.h"
#endif
/* Dummy API's Start */

extern void mmi_umms_init(void);
extern U32 mmi_umms_get_msg_id_dummy_api(kal_uint16 msg_box_type, kal_uint16 msg_index);

/* Dummy Api's End */
extern void mmi_umms_get_header_request(
                const U32 msg_id,
                const umms_state_enum current_state,
                const mma_folder_enum current_folder);
extern void mmi_umms_delete_req(
                const umms_state_enum intermediate_state,
                const umms_state_enum current_state,
                const U32 msg_id,
                const mma_folder_enum folder_id);
extern void mmi_umms_get_msg_delete_req(void *temp_req);
extern void mmi_umms_create_req(
                const U32 msg_id,
                const U32 req_id,
                const U8 *xml_file_path,
                const kal_bool is_more,
                U32 buffer_index);
extern void mmi_umms_forward_mms(U32 msg_id);
extern void mmi_umms_reply_to(U32 msg_id);
extern void mmi_umms_reply_to_all(U32 msg_id);

extern void mmi_umms_show_mms_option_screen(void);

/* extern void mmi_umms_show_mms_option_screen(mma_folder_enum box_type); */
extern void mmi_umms_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);

extern void mmi_umms_get_msg_header(
                /* mms_current_selected_info_struct *msgRsp  Removed for the time being */ void *msgRsp);
extern void mmi_umms_progress_screen(void);
extern void mmi_umms_entry_mms_options(const U32 msg_id);
extern U32 mmi_umms_get_msg_id_dummy_api(kal_uint16 msg_box_type, kal_uint16 msg_index);
extern void mmi_umms_show_viewer_or_properities_screen(void);
extern void mmi_umms_set_key_hanler(void);
extern void mmi_umms_entry_edit(void);
extern void mmi_umms_entry_delete_all(void);
extern void mmi_umms_entry_move_to_archive(void);
extern void mmi_umms_entry_reply_to_all(void);
extern void mmi_umms_entry_reply(void);
extern void mmi_umms_entry_view(void);
extern void mmi_umms_entry_delete_msg(void);
extern void mmi_umms_entry_send_msg(const U32 msg_id);
extern void mmi_umms_entry_message_status(void);
extern void mmi_umms_entry_save_objects(void);
extern void mmi_umms_entry_use_details(void);
extern void mmi_umms_entry_show_properties(void);
extern void mmi_umms_entry_show_properties_dispatcher(void);
extern void mmi_umms_entry_download_msg(void);
extern void mmi_umms_entry_use_call_details(void);
extern void mmi_umms_entry_use_save_to_phbook(void);
extern void mmi_umms_entry_use_email_add_to_contact(void);
extern void mmi_umms_entry_forward(void);
extern void mmi_umms_entry_move_to_drafts(void);
extern void umms_add_to_msg_hndlr_list(const U32 msg_id, const U32 req_id, const umms_state_enum current_state);
extern umms_state_enum mmi_umms_get_current_state(const U32 msg_id, const U32 req_id);
extern void mmi_umms_free_req_node(const U32 msg_id,const  U32 req_id);
extern void mmi_umms_get_download_ind_rsp(void *inMsg);
extern void mmi_umms_get_send_rsp(void *inMsg);
extern void mmi_umms_get_download_rsp(void *inMsg);
extern void mmi_umms_get_msg_delete_rsp(void *inMsg);
extern void mmi_umms_get_msg_delete_all_rsp(void *inMsg);
extern void mmi_umms_get_msg_save_rsp(void *inMsg);
extern void mmi_umms_get_start_immediate_retreival_ind(void *inMsg);
extern void mmi_umms_start_uc_req(const U32 msg_id, const mma_app_mode_enum mode);
extern void mmi_umms_get_stop_immediate_retreival_ind(void *inMsg);
extern void mmi_umms_get_memory_full_ind(void *inMsg);
extern void mmi_umms_get_total_number_of_msgs_rsp(void *inMsg);
extern void mmi_umms_show_message_status_screen(void);

extern void mmi_umms_delete_progress_screen(void);
extern void mmi_umms_show_error_pop_up(const mma_result_enum error_result);
extern void mmi_umms_show_done_pop_up(const umms_state_enum current_state);
extern void mmi_umms_add_to_list(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum current_state,
                const umms_state_enum intermediate_state);
extern kal_bool mmi_umms_show_pop(const umms_state_enum current_state);
extern void mmi_umms_go_to_box_list_screen(void);
extern void mmi_umms_get_message_number_request(void);
extern void mmi_umms_set_msg_numbers_in_global_list(const mmi_um_get_msg_num_rsp_struct *msg);
extern void mmi_umms_get_msg_number_rsp(void *inMsg);
extern void mmi_umms_entry_cancel_req(
                const umms_state_enum current_state,
                const U32 msg_id,
                const mma_folder_enum folder_id);
extern void umms_add_to_send_msg_hndlr_list(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum current_state,
                const umms_state_enum intermediate_state,
                const mma_folder_enum folder_id);
extern umms_state_enum mmi_umms_get_intermediate_state_of_msg_from_send_list(const U32 msg_id);
extern void mmi_umms_entry_delete_req(const U32 msg_id);
extern void mmi_umms_update_intermediate_send_cancel_req(const U32 msg_id,const U32 req_id);
extern void mmi_umms_cancel_req(const U32 msg_id);
extern void mmi_umms_get_delete_all_rsp_from_um(void *inMsg);
extern void mmi_umms_send_delete_all_ind_to_um(const mma_folder_enum folder_id);
extern void mmi_umms_entry_dummy_screen(void);
extern void mmi_umms_send_delete_all_after_cancel_all_req(void);
extern kal_bool mmi_umms_check_if_more_mms_is_in_send_state(void);
extern void mmi_umms_get_save_rsp(void *inMsg);
extern mma_folder_enum mmi_umms_get_folder_id_from_all_msg_handler(const U32 msg_id, const U32 req_id);
extern void mmi_umms_get_download_ind(void *inMsg);
extern void mmi_umms_get_download_rsp(void *inMsg);
extern void mmi_umms_download_req(const U32 msg_id);
extern void mmi_umms_get_download_rsp(void *inMsg);
extern U32 mmi_umms_get_current_selected_msg_id(void);
extern umms_state_enum mmi_umms_get_state_of_msg_from_download_list(const U32 msg_id,const  U32 req_id);
extern void mmi_umms_goto_menu_option(void);
extern void mmi_umms_get_save_rsp_dummy(U32 msg_id, U32 req_id);
extern void mmi_umms_get_download_ind_dummy(U32 msg_id, U32 req_id);
extern void mmi_umms_get_download_rsp_dummy(U32 msg_id, U32 req_id);
extern void mmi_umms_abort_download_mms(const umms_state_enum current_state);
extern void mmi_umms_abort_download_rsp(void *inMsg);
extern void mmi_umms_show_communication_aborted_pop_up(void);
extern void mmi_umms_show_cancel_fail_pop_up(void);
extern void mmi_umms_show_mms_status_icon(const mmi_umms_status_icon_type_enum status);
extern void mmi_umms_set_mms_downloading_busy(void);
extern void mmi_umms_reset_mms_downloading_busy(void);
extern U8 mmi_umms_is_download_busy(void);
extern void mmi_umms_stop_download_busy(void);
extern void mmi_umms_update_status_icon_indicator(void);
extern void mmi_umms_get_total_number_of_messages(U32 *total_num_messages);
extern void mmi_umms_get_number_of_unread_messages_in_inbox(U32 *total_num_unread_messages);
extern void mmi_umms_entry_mms_only_options(const U32 msg_id);
extern void mmi_umms_save_req(
                const umms_state_enum intermediate_state,
                const umms_state_enum current_state,
                const U32 msg_id,
                const mma_folder_enum folder_to_be_moved_to,
                const mma_folder_enum current_folder);
extern kal_bool mmi_umms_get_send_and_save_state(const U32 msg_id);
extern void mmi_umms_stop_immd_retr_ind(void *inMsg);
extern void mmi_umms_start_immd_retr_ind(void *inMsg);
extern void mmi_umms_stop_sending_busy(void);
extern U8 mmi_umms_is_sending_busy(void);
extern void mmi_umms_reset_mms_sending_busy(void);
extern void mmi_umms_set_mms_sending_busy(void);
extern void mmi_umms_get_memory_status_rsp(void *inMsg);
extern void mmi_umms_receive_memory_status_rsp(void *inMsg);
extern void mmi_umms_get_memory_status_req(void);
extern void mmi_umms_get_storage_full_ind(void *inMsg);
extern void mmi_umms_update_storage_state(const kal_bool state);
extern mmi_enum_retry_send_verion_enum mmi_umms_get_send_version_number(const U32 msg_id);
extern void mmi_umms_update_send_msg_handler(
                const umms_state_enum updated_state,
                const U32 msg_id,
                const mmi_enum_retry_send_verion_enum retry_send_version,
				const U32 retry_version_count);
extern void mmi_umms_receive_get_content_rsp(void *inMsg);
extern kal_bool mmi_umms_change_version_number_of_mms(const U8 *xml_file_path);
extern void mmi_umms_get_content_req(const U32 msg_id, mma_app_mode_enum mode, umms_state_enum state);
extern kal_bool mmi_umms_is_space_full(void);

/* Ashwani Starts */
extern void mmi_umms_get_header_use_details(void);
extern void mmi_umms_entry_use_details_options(void);
extern void mmi_umms_entry_use_details_addresses_list(void);
extern void mmi_umms_send_use_details_req(void);
extern void mmi_umms_get_use_details_rsp(void *inmsg);
extern void mmi_umms_entry_use_url_go_to(void);
extern void mmi_umms_entry_use_url_save_bookmark(void);
extern void mmi_umms_use_details_call(void);
extern void mmi_umms_entry_use_details_addresses_options(void);
extern void mmi_umms_use_details_set_app_slide(mmi_mv_get_use_details_enum const app_slide);
extern void mmi_umms_use_details_set_addr_type(const U8 addr_type);

extern void mmi_umms_entry_lock_mode(void);
extern void mmi_umms_send_lock_mode_req(void);
extern void mmi_umms_lock_mode_rsp(void *inmsg);

extern S16 mmi_brw_add_to_bookmark(U8 *title, U8 *url);
extern void mmi_brw_load_url(U8 *url_p);

extern pBOOL mmi_umms_get_address_list(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_mv_deinit_viewer(void);
extern void mmi_umms_set_msg_number_state(const umms_state_enum current_state);
extern umms_state_enum mmi_umms_get_msg_number_state(void);
extern void mmi_umms_entry_save_as_template(void);
extern void mmi_umms_free_download_handler_node(const U32 msg_id, const U32 req_id);
extern void mmi_umms_free_send_handler_node(const U32 msg_id, const U32 req_id);
extern void mmi_umms_free_req_handler_node(const U32 msg_id, const U32 req_id);
extern void mmi_umms_create_rsp(void *inMsg);
extern U8 *mmi_umms_get_xml_file_path_from_send_msg_hndlr(const U32 msg_id);
extern void mmi_umms_update_xml_file_path_in_send_msg_hndlr(const U32 req_id, const U8 *xml_file_path);
extern kal_bool mmi_umms_get_more_flag_from_send_list(const U32 req_id);
extern void mmi_umms_update_more_flag_for_send(const U32 msg_id, const kal_bool is_more);
extern void mmi_umms_de_init_req_handler_list(void);
extern void mmi_umms_de_init_send_handler_list(void);
extern void mmi_umms_de_init_dwnld_handler_list(void);
extern void mmi_umms_de_init_new_msg_handler_list(void);
extern void mmi_umms_update_intermediate_send_req(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum intermediate_state);
extern mma_folder_enum mmi_umms_get_folder_id_from_send_list(const U32 msg_id);
extern void mmi_umms_update_status_icon_on_number_rsp(void);
extern S32 mmi_umms_get_hilite_index(void);
extern void mmi_umms_set_hilite_index(const S32 hilite_index);
extern U16 mmi_umms_get_menu_id(void);
extern void mmi_umms_set_menu_id(const U16 menu_id);
extern void mmi_umms_reset_global(void);
extern void mmi_umms_entry_new_mms_hndlr(const UmMsgBoxType msg_box_type, const kal_uint16 msg_index);
extern void mmi_umms_delete_option_screen(void);
extern void mmi_umms_save_mms_before_sending(const U32 msg_id);
extern void mmi_umms_use_details_progress_screen(void);
extern void mmi_umms_pre_entry_send_msg(void);
extern void mmi_umms_show_error_in_send_pop_up(U32 msg_id,U8 *response_text);
extern void mmi_umms_update_retry_send_req(
                const U32 msg_id,
                const U32 req_id,
                const U32 new_req_id,
                const umms_state_enum intermediate_state);
extern void mmi_umms_update_send_hdnlr_with_new_msg_id(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum intermediate_state);
extern U32 mmi_umms_is_mms_in_open_state(const U32 msg_id);
extern void mmi_umms_update_retry_counter_send_req(const U32 msg_id,const U32 req_id, const U32 send_counter);
extern U32 mmi_umms_get_send_retry_counter(const U32 msg_id,const U32 req_id);
extern void mmi_umms_get_msg_id_from_send_list(void);
extern void mmi_umms_check_send_state_before_delete_folder(const U8 folders_to_delete);
extern void mmi_umms_update_current_msg_id(const U32 msg_id);
extern void umms_add_to_download_msg_hndlr_list(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum current_state,
                const umms_state_enum intermediate_state);
extern umms_state_enum mmi_umms_get_intermediate_state_from_downl_list(const U32 msg_id);
extern kal_bool mmi_umms_is_any_mms_opened_in_box(const mma_folder_enum box_id);
extern void mmi_umms_send_mms_msg(const U32 msg_id);
extern U32 mmi_umms_current_mms_opened_folder_id(void);

/* USB Handling */
extern void mmi_ebook_usb_mode_on(void);
extern void mmi_ebook_usb_mode_off(void);
extern kal_bool mmi_umms_check_is_more_mms_in_send_state(void);
extern BOOL mmi_umms_is_usb_mode(void);
extern void pre_mmi_umms_entry_delete_msg(U32 msg_id);
extern umms_state_enum mmi_umms_get_current_state_from_req_hndlr(U32 msg_id);
extern umms_state_enum mmi_umms_get_intermediate_state_by_old_msg_id(U32 msg_id);
extern U32 mmi_umms_get_send_version_count(U32 msg_id);
extern void mmi_um_entry_msg_options(void);
extern void mmi_umms_set_media_info(mmi_mv_object_struct const * const media_info);
extern mmi_mv_object_struct *mmi_umms_get_media_info(void);
extern void mmi_umms_set_virtual_file_name(U16 const * const virtual_file_name);
extern U16 *mmi_umms_get_virtual_file_name(void);
extern void mmi_umms_set_current_obj_drm_type(U8 drm_type);
extern void mmi_umms_reset_current_obj_drm_type(void);
extern U16 *mmi_umms_get_src_file_name(void);
extern void mmi_umms_set_src_file_name(U16 const *const src_file_name);
extern void mmi_umms_set_media_file_path(U16 const * const media_file_path);
extern U16 *mmi_umms_get_media_file_path(void);
extern void mmi_umms_set_progress_scr_id(umms_progress_screen_enum const scr_id);
extern mmi_enum_retry_send_verion_enum mmi_umms_get_global_mms_version(void);
extern void mmi_umms_show_send_sucess_pop_up(U32 msg_id);
extern void mmi_umms_show_memory_full_pop_up(void);
extern BOOL mmi_umms_is_bearer_type_csd(void);
extern void mmi_umms_view_msg_ind(void *inMsg);
extern void mmi_umms_set_progress_screen(void);
extern void mmi_umms_set_status_icon_at_boot_up(void);
extern void mmi_umms_show_viewer_properties_mms(void);
extern void mmi_umms_entry_download_msg_after_call_end(void);
extern void mmi_umms_close_object_file_handle(void);
extern void mmi_umms_set_object_file_handle(FS_HANDLE file_handle);
extern void mmi_umms_um_refresh_ind(mma_folder_enum folder_id);
extern UmMsgBoxType mmi_umms_convert_mma_folder_to_umbox_type(mma_folder_enum folder_id);
extern mma_folder_enum mmi_umms_convert_umbox_type_to_mma_folder(UmMsgBoxType um_box_id);
extern void mmi_umms_use_email_send_email(void);
extern void mmi_umms_use_details_send_mms(void);
extern void mmi_umms_use_details_send_sms(void);
extern void mmi_umms_use_details_address_insert_hdlr(U8 *address);
extern void mmi_umms_check_new_mms_list_and_show_new_mms_pop_up(void);
extern void mmi_umms_set_readmark_req(U32 msg_id);
extern MMI_BOOL mmi_umms_is_in_call(void);
extern void mmi_umms_entry_cancel_send(void);
extern void mmi_umms_free_send_node_with_msg_id(U32 msg_id);
extern void mmi_umms_show_cancel_send_popup(MMI_BOOL sucess_state);
extern void mmi_umms_usb_mode_on(void);
extern void mmi_umms_usb_mode_off(void);
extern mma_msg_type_enum mmi_umms_get_message_type(void);
extern void mmi_umms_set_read_report_req(U32 msg_id);
extern UmMsgBoxType mmi_umms_get_current_msg_box_type(void);
extern U32 mmi_umms_get_current_highlighted_msg_index(void);
extern U32 mmi_umms_get_old_msg_id_from_send_handler(U32 req_id);
extern void mmi_umms_reset_all(void);
extern void mmi_umms_entry_reply_as_sms(void);
extern void mmi_umms_terminate_indication(void *inMsg);
extern void mmi_umms_free_all_nodes(void);
#ifdef __MMI_VBOOKMARK__
void mmi_umms_show_book_mark_add_result(brw_add_to_bkm_err_enum book_mark_result);
#endif
extern void mmi_umms_set_download_size(U32 size);
extern void mmi_umms_set_reported_msg_id(U32 reported_msg_id);
extern void mmi_umms_get_msg_number_for_globals_update(void);
extern void mmi_umms_update_download_msg_hndlr_with_percent_val(const U32 msg_id, const U32 req_id, const U32 percent_val);
extern umms_state_enum mmi_umms_get_current_state_of_download(U32 msg_id);
#ifdef __CMCC_SEND_COUNT_RETRY_POP_UP__
void mmi_umms_display_retry_send_pop_up(void);
#endif
extern void mmi_umms_delete_umms_screens(void);
extern void mmi_umms_entry_fwd_edit_scr(void);
extern MMI_BOOL mmi_umms_is_get_content_or_header_req_state(void);
extern umms_state_enum mmi_umms_get_state_of_msg_from_req_hndlr_list(const U32 msg_id);
extern U32 mmi_umms_get_percent_val_from_download_list(U32 msg_id);
extern void mmi_umms_handle_delete_all_mms(void);
#endif /* __MMI_MMS_2__ */ 
#endif /* __MMI_UMMS_APP_GPROT_H_ */ 

