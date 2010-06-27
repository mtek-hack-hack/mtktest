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
 * BrowserMain.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains declaration of all the functions implemented in BrowserMain.c file
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSERMAIN_H
#define BROWSERMAIN_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "wap_ps_struct.h"
#include "DebugInitDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGProt.h"
#include "wapadp.h"
#include "oppmmigprots.h"
#include "extdevicedefs.h"


/*temp code for implementing ASM support in brw app*/
#define APPMEM_SUPPORT
/*temp code for implementing ASM support in brw app*/

/*Highlight Handlers*/
extern void mmi_brw_homepage_highlight_hdlr(void);
extern void mmi_brw_push_inbox_menu_highlight_hdlr(void);
extern void mmi_brw_open_file_highlight_hdlr(void);
extern void mmi_brw_last_web_address_highlight_hdlr(void);
extern void mmi_brw_send_addr_text_msg_highlight_hdlr(void);
extern void mmi_brw_send_addr_multimedia_msg_highlight_hdlr(void);
extern void mmi_brw_send_addr_via_infrared_highlight_hdlr(void);
extern void mmi_brw_send_addr_via_bluetooth_highlight_hdlr(void);
extern void mmi_brw_send_addr_via_email_highlight_hdlr(void);
extern void mmi_brw_editor_cancel_highlight_hdlr(void);
extern void mmi_brw_editor_input_method_highlight_hdlr(void);
extern void mmi_brw_editor_done_highlight_hdlr(void);
/*Highlight Handlers*/

extern void mmi_brw_entry_internet_services(void);
extern void mmi_brw_entry_homepage(void);
extern void mmi_brw_pre_entry_goto_url(void);
extern void mmi_brw_pre_entry_open_file(void);
extern void mmi_brw_entry_render_page(void);
extern void mmi_brw_exit_render_page(void);
extern void mmi_brw_editor_entry_option(void);
extern void mmi_brw_entry_dummy_screen(void);
extern void mmi_brw_entry_temp_busy_screen(void);
extern void mmi_brw_delete_busy_screen(void);

extern void mmi_brw_GoBackServicesMenu(void);
extern S16 mmi_brw_validate_url(U8 *url_p);
extern void mmi_brw_entry_send_address(void);
extern void mmi_brw_send_addr_text_msg_highlight_hdlr(void);
extern void mmi_brw_send_addr_multimedia_msg_highlight_hdlr(void);
extern void mmi_brw_send_addr_via_infrared_highlight_hdlr(void);
extern void mmi_brw_send_addr_via_bluetooth_highlight_hdlr(void);
extern void mmi_brw_send_addr_via_email_highlight_hdlr(void);
extern void mmi_brw_global_context_init(void);
extern void mmi_brw_dummy_func(void);
extern void mmi_brw_set_as_homepage(U8 *url_p);
extern void mmi_brw_convert_int_to_unicode_string(U8 *StringVal, U32 value);
extern void mmi_brw_exit_internet_services(void);
extern void mmi_brw_entry_memory_status(void);
extern void mmi_brw_open_file_highlight_hdlr(void);
extern void mmi_brw_last_web_address_highlight_hdlr(void);
extern void mmi_brw_open_file(void);
extern void mmi_brw_last_web_address(void);
extern void mmi_brw_entry_view_url(void);
extern U16 mmi_brw_convert_unicode_string_to_int(U8 *StringVal);
extern void mmi_brw_entry_ren_page_options(void);
extern void mmi_brw_ren_page_navigate_backward(void);
extern void mmi_brw_send_addr_text_msg(void);
extern void mmi_brw_send_addr_multimedia_msg(void);
extern void mmi_brw_send_addr_via_infrared(void);
extern void mmi_brw_send_addr_via_bluetooth(void);
extern void mmi_brw_send_addr_via_email(void);
extern void mmi_brw_ren_page_select_mode_rsk_exit(void);
extern void mmi_brw_entry_object_properties(void);
extern void mmi_brw_inline_struct_for_object_properties(void);
extern void mmi_brw_exit_object_properties(void);
extern void mmi_brw_object_properties_reset(void);
extern void mmi_brw_app_init(void);
extern void mmi_brw_app_deinit(void);
extern void mmi_brw_splash_screen_timer_callback(void);
extern void mmi_brw_start_animated_splash_screen(void);
extern void mmi_brw_stop_animated_splash_screen(void);
extern void mmi_brw_highlight_handlers_init(void);
extern void mmi_brw_nvram_data_init(void);
extern void mmi_brw_create_instance_req(void);
extern void mmi_brw_delete_instance_req(void);
extern void mmi_brw_load_url_req(U8*);
extern void mmi_brw_load_data_req(void);
extern MMI_BOOL mmi_brw_is_browser_first_page(void);
extern void mmi_brw_dynamic_list_free_memory(void);
extern void mmi_brw_watai_tel_rsp(U16);
extern void mmi_brw_watai_pb_rsp(U16);
extern void mmi_brw_uri_request_rsp(U16);
extern void mmi_brw_register_keypad_handler_req(void);
extern void mmi_brw_watai_tel_make_call_confirm(void);
extern void mmi_brw_watai_tel_send_dtmf_confirm(void);
extern void mmi_brw_watai_tel_make_call(void);
extern void mmi_brw_watai_tel_send_dtmf(void);
extern void mmi_brw_watai_pb_add_new_entry_confirm(void);
extern void mmi_brw_watai_pb_add_new_entry(void);
extern void mmi_brw_process_uri_request_confirm(void);
extern void mmi_brw_process_uri_request(void);
extern void mmi_brw_splash_screen_set_title_string_and_icon(void);
extern U8 mmi_brw_is_active_profile_editable(void);
extern void mmi_brw_splash_screen_stop_timer(void);
extern void mmi_brw_dynamic_list_delete_item(U16 item_index);
extern void mmi_brw_wait_user_action_positive_key_hdlr(void);
extern void mmi_brw_wait_user_action_negative_key_hdlr(void);
extern void mmi_brw_wait_user_action_rsp(MMI_BOOL);
extern void mmi_brw_entry_browser_busy_screen(void);
extern void mmi_brw_watai_pb_add_new_entry_callback(mmi_phb_add_from_others_error_enum error_result, U16 store_index);
extern void mmi_brw_entry_irda_processing_screen(void);
extern U8 mmi_brw_irda_progress_scr_del_callback(void *ptr);
extern void mmi_brw_UCS2Strtolower(S8* str);
extern S8 mmi_brw_stricmp(S8* string1, S8* string2);
extern void* mmi_brw_malloc(U32 mem_size);
extern void mmi_brw_mfree(void* pMemory);
extern MMI_BOOL mmi_brw_is_memory_available(U32 mem_size);
extern void mmi_brw_start_browser_action_goto_main_menu(void);
extern void mmi_brw_start_browser_action_goto_homepage(void);
extern void mmi_brw_start_browser_action_goto_url(U8 *url);
extern void mmi_brw_start_browser_action_add_to_bookmark(U8 *url);
extern void mmi_brw_start_browser_action_goto_url_bkgrd(U8 *url);
extern void mmi_brw_start_browser_action_view_push_msg(void);
extern void mmi_brw_load_url(U8 *url_p);
#ifdef APPMEM_SUPPORT
extern void mmi_brw_asm_stop_app_callback(void);
extern void mmi_brw_asm_memory_pool_request_success_callback(void);
#endif /*APPMEM_SUPPORT*/
extern S16 mmi_brw_bookmarks_add_to_bookmark_silently(void);
extern void mmi_brw_busy_screen_set_title_string_id(U16 id);
extern void mmi_brw_display_info_go_back_history(void);
extern void mmi_brw_set_as_homepage_confirm(void);
extern void mmi_brw_set_as_homepage_ok(void);
extern void mmi_brw_full_screen_editor_entry_option(void);
extern void mmi_brw_return_to_editor(void);
extern void mmi_brw_editor_cancel(void);
extern void mmi_brw_editor_pre_entry_input_method(void);
extern void mmi_brw_send_addr_via_bluetooth_callback(void *buf_p, U32 result);
extern void mmi_brw_send_addr_via_infrared_callback(void *buf_p, U32 result);
extern void mmi_brw_delete_all_browser_screens(void);
extern void mmi_brw_global_context_deinit(void);
extern MMI_BOOL mmi_brw_is_browser_screen(U16 screen_id);
extern void mmi_brw_set_top_screen_id(void);
extern void mmi_brw_set_status_icon(S16 icon_id, MMI_BOOL show_icon);
extern void mmi_brw_trim_left_white_spaces(S8 *string);
extern void mmi_brw_trim_right_white_spaces(S8 *string);
extern void mmi_brw_common_gateway(void);
extern MMI_BOOL mmi_brw_is_browser_launched_from_main_menu(void);
extern void mmi_brw_app_exit(void);
extern void mmi_brw_redirection_delete_brw_screens_upto_rend_page(void);
extern U16 mmi_brw_get_top_screen_id(void);
extern MMI_BOOL mmi_brw_check_white_spaces(S8 *string);
extern U16 mmi_brw_ren_page_get_title_icon(void);
extern U8* mmi_brw_ren_page_get_title_string(void);
extern MMI_BOOL mmi_brw_is_browser_active(void);
extern void mmi_brw_uri_request_activate_java_confirm(void);
extern void mmi_brw_uri_request_activate_java(void);
extern void mmi_brw_uri_request_send_sms_confirm(void);
extern void mmi_brw_uri_request_send_sms(void);
extern void mmi_brw_uri_request_send_mms_confirm(void);
extern void mmi_brw_uri_request_send_mms(void);

/*Interfaces of other internal modules*/
extern void mmi_brw_address_list_highlight_handlers_init(void);
extern void mmi_brw_recent_pages_highlight_handlers_init(void);
extern void mmi_brw_stored_pages_highlight_handlers_init(void);
extern void mmi_brw_settings_highlight_handlers_init(void);
extern void mmi_brw_ren_page_highlight_handlers_init(void);
extern pBOOL GetUCS2Flag(PS8 buffer);
extern void mmi_brw_ren_page_set_title_string(void);
extern void mmi_brw_ren_page_set_title_icon(void);
extern void mmi_brw_ren_page_set_LSK(void);
extern void mmi_brw_ren_page_set_RSK(void);
extern void mmi_brw_settings_nvram_data_init(void);
extern void mmi_brw_settings_set_profile_req(void);
extern void mmi_brw_prof_init(void);
#ifdef __MMI_VBOOKMARK__
extern void mmi_brw_bookmarks_highlight_handlers_init(void);
extern void mmi_brw_bookmarks_entry_add_bookmark(void);
extern void mmi_brw_bookmarks_free_memory(void);
#endif /*__MMI_VBOOKMARK__*/
extern void mmi_brw_settings_highlight_handlers_init(void);
extern void mmi_brw_recent_pages_read_sorting_method(void);
extern void mmi_brw_event_hdlr_send_ilm(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void mmi_brw_event_hdlr_send_ilm_to_mmi(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void mmi_brw_event_hdlr_send_ilm_to_wps(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void mmi_brw_ren_page_show_animated_title_icon(void);
extern void mmi_brw_ren_page_show_non_animated_title_icon(void);
extern MMI_BOOL mmi_brw_ren_page_pen_handler(mmi_pen_point_struct, mmi_pen_event_type_enum);
extern void mmi_brw_read_last_web_address(void);
extern void mmi_brw_write_last_web_address(void);
extern void mmi_brw_settings_read_user_defined_homepage(void);
extern void mmi_brw_bearer_info_confirm(void);
extern void mmi_brw_switch_bearer(void);
extern void mmi_brw_ren_page_resume_owl_rendering_req(void);
extern void mmi_brw_ren_page_suspend_owl_rendering_req(void);
extern void mmi_brw_settings_set_user_defined_homepage(U8* strHomepage);
extern void mmi_brw_event_hdlr_register_all_ilm_handlers(void);
extern void mmi_brw_ren_page_notify_screen_info_req(MMI_BOOL refresh);
extern void mmi_brw_recent_pages_get_recent_pages_list_end_req(void);
extern void mmi_brw_stored_pages_get_saved_pages_list_end_req(void);
extern void mmi_brw_this_page_get_resource_list_end_req(void);
extern void mmi_brw_bookmarks_context_init(void);
extern void mmi_brw_bookmarks_add_to_bookmark(void);
#if defined (WAP_SEC_SUPPORT)
extern void mmi_brw_security_settings_trusted_certificates_list_free_memory(void);
#endif /*WAP_SEC_SUPPORT*/
extern void mmi_brw_recent_pages_free_memory(void);
extern void mmi_brw_address_list_free_memory(void);
extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);
extern void mmi_brw_settings_encoding_methods_free_memory(void);
extern S32 mmi_brw_bookmarks_get_available_memory(void);
extern void mmi_brw_settings_encoding_methods_initialize_list(void);
extern MMI_BOOL mmi_brw_bookmarks_create_standard_vbookmark_file(U8* file_path, U8* url);
extern void mmi_brw_bookmarks_create_default_bkms(void);
extern void mmi_brw_ren_page_suspend_bkgrd_downloads_confirm(void);
extern void mmi_brw_ren_page_sec_confirm_dialog_positive_res(void);
extern void mmi_brw_ren_page_sec_confirm_dialog_negative_res(void);
/*Interfaces of other internal modules*/

#endif /* __MMI_BROWSER_2__ */
#endif /* BROWSERMAIN_H */

