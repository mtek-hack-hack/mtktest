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
 * JBrowserMMIProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains declaration of all the functions in Browser scondary MMI.
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
#ifndef _JBROWSERMMIPROTS_H
#define _JBROWSERMMIPROTS_H

#include "MMI_features.h"
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "MMIDataType.h"

#include "ddl.h"
#include "jcal.h"
#include "jcalnet.h"
#include "jdi_urivalidation.h"
#include "jdd_memapi.h"
#include "jdi_transport.h"
#include "jdi_communicator.h"
#include "jdi_browserinterface.h"
#include "jdi_BrowserDatatype.h"
#include "JBrowserMMITypes.h"
#include "cacheapi.h"

extern void mmi_brw_wap_menu_highlight_hdlr(void);
extern void mmi_brw_entry_homepage(void);

/* Main menu Start */
extern void mmi_brw_homepage_highlight_hdlr(void);
extern void mmi_brw_bookmark_menu_highlight_hdlr(void);
extern void mmi_brw_recent_pages_menu_highlight_hdlr(void);
extern void mmi_brw_enter_address_menu_highlight_hdlr(void);
extern void mmi_brw_service_inbox_menu_highlight_hdlr(void);
extern void mmi_brw_setting_highlight_hdlr(void);
extern void mmi_brw_go_back_services_menu(void);
extern void mmi_brw_ren_page_add_to_bmk_highlight_hdlr(void);
extern void mmi_brw_register_key_handler(void);
extern void mmi_brw_clear_brw_soft_keys(void);
extern BOOL mmi_brw_check_http_prefix(PS8 url_string);

/* Main menu End */

/* Bookmark Start */
extern void mmi_brw_goto_bookmark_menu_highlight_hdlr(void);
extern void mmi_brw_add_bookmark_menu_highlight_hdlr(void);
extern void mmi_brw_edit_bookmark_menu_highlight_hdlr(void);
extern void mmi_brw_delete_bookmark_menu_highlight_hdlr(void);
extern void mmi_brw_delete_all_bookmark_menu_highlight_hdlr(void);
extern void mmi_brw_bookmark_set_as_homepage_menu_highlight_hdlr(void);
extern void mmi_brw_entry_bookmark_list(void);
extern void mmi_brw_bmk_list_goback_history(void);
extern void mmi_brw_send_bookmark_details(void);
extern void mmi_brw_pre_entry_bookmark_options(void);
extern void mmi_brw_entry_bookmark_options(void);
extern void mmi_brw_entry_confirmation_hdlr(void);
extern void mmi_brw_full_screen_edit(void);
extern void mmi_brw_change_label_highlight_hdlr(S32 index);
extern void mmi_brw_read_bookmark_from_nvram(void);
extern void mmi_brw_write_bookmark_to_nvram(void);
extern void mmi_brw_calculate_number_of_bookmarks_stored(void);
extern void mmi_brw_save_bookmark(void);
extern void mmi_brw_save_bookmark_item(void);
extern void mmi_brw_go_back_history(void);
extern pBOOL mmi_brw_bookmark_list_get_item(S32, UI_string_type, PU8 *, U8);
extern void mmi_brw_delete_confirm(void);
extern void mmi_brw_delete_bookmark(void);
extern void mmi_brw_confirm_delete_all_bookmark(void);
extern void mmi_brw_delete_all_bookmark(void);
extern void mmi_brw_goto_highlighted_bookmark(void);
extern void mmi_brw_bookmark_set_as_homepage(void);
extern void mmi_brw_entry_add_bookmark_screen_for_all(void);
extern void mmi_brw_pre_entry_add_bookmark(void);
extern void mmi_brw_pre_entry_edit_bookmark(void);
extern void mmi_brw_exit_add_bookmark_screen_for_all(void);
extern void mmi_brw_save_page_url_title_to_bookmark(void);
extern void mmi_brw_save_ren_page_to_bookmark(void);
extern void wap_send_select_bookmark_rsp(MMI_BOOL rsp, U8 bmk_index);
extern void mmi_brw_bkm_check_ucs2_flag_and_copy(S8 *str, U8 index);
extern U8 mmi_brw_bkm_calculate_strlen_ucs2_flag(S8 *str);

/* Bookmark End */

/* Recent Pages Start */
extern void mmi_brw_entry_recent_page_list(void);
extern void mmi_brw_goto_recent_page_menu_highlight_hdlr(void);
extern void mmi_brw_delete_recent_page_menu_highlight_hdlr(void);
extern void mmi_brw_delete_all_recent_pages_menu_highlight_hdlr(void);
extern void mmi_brw_highlighted_recent_page(void);
extern void mmi_brw_entry_recent_page_options(void);
extern pBOOL mmi_brw_recent_pages_list_get_item(S32, UI_string_type, PU8 *, U8);
extern void mmi_brw_confirm_delete_recent_page(void);
extern void mmi_brw_delete_recent_page(void);
extern void mmi_brw_confirm_delete_all_recent_pages(void);
extern void mmi_brw_delete_all_recent_pages(void);
extern void mmi_brw_goto_highlighted_recent_page(void);
extern void mmi_brw_unicode_string_concatenate_dots(UI_string_type str_buff, S8 *str);

/* Recent Pages End */

/* Address History Start */
extern void mmi_brw_entry_enter_address(void);
extern void mmi_brw_calculate_number_of_address_history_items_stored(void);
extern pBOOL mmi_brw_address_history_list_get_item(S32, UI_string_type, PU8 *, U8);
extern void mmi_brw_enter_address_menu_highlight_hdlr(void);
extern void mmi_brw_hist_highlighted_item(void);
extern void mmi_brw_add_address_history_item(void);
extern void mmi_brw_update_address_history_list(void);
extern void mmi_brw_entry_enter_address_options(void);
extern void mmi_brw_enter_address_goto_menu_highlight_hdlr(void);
extern void mmi_brw_enter_address_edit_menu_highlight_hdlr(void);
extern void mmi_brw_enter_address_add_to_bmk_menu_highlight_hdlr(void);
extern void mmi_brw_enter_address_delete_menu_highlight_hdlr(void);
extern void mmi_brw_enter_address_delete_all_menu_highlight_hdlr(void);
extern void mmi_brw_enter_address_delete_confirm(void);
extern void mmi_brw_delete_enter_address(void);
extern void mmi_brw_write_enter_address_to_nvram(void);
extern void mmi_brw_read_enter_address_from_nvram(void);
extern void mmi_brw_enter_address_delete_all_confirm(void);
extern void mmi_brw_enter_address_scr_highlight_hdlr(S32 index);
extern void mmi_brw_pre_entry_add_enter_address_bookmark(void);
extern void mmi_brw_enter_address_edit_menu(void);
extern void mmi_brw_setting_delete_history_all(void);
extern void mmi_brw_ansii_string_concatenate_dots(UI_string_type str_buff, S8 *str);
extern void mmi_brw_check_ucs2_flag(S8 *str);
extern void mmi_brw_check_dcs_flag(S8 *str, U8 index);
extern void mmi_brw_shift_elements(U8 start_pnt);

/* Address History End */

/* Service Inbox Start */
extern void mmi_brw_service_inbox_read_menu_highlight_hdlr(void);
extern void mmi_brw_service_inbox_delete_menu_highlight_hdlr(void);
extern void mmi_brw_service_inbox_delete_all_menu_highlight_hdlr(void);
extern void mmi_brw_service_inbox_read_accept_menu_highlight_hdlr(void);
extern void mmi_brw_service_inbox_read_delete_menu_highlight_hdlr(void);
extern void mmi_brw_entry_service_inbox(void);
extern pBOOL mmi_brw_service_inbox_list_get_item(S32, UI_string_type, PU8 *, U8);
extern void mmi_brw_highlighted_push_msg(void);
extern void mmi_brw_entry_service_inbox_options(void);
extern void mmi_brw_read_arrived_push_message(void);

/* Service Inbox End */

extern void mmi_brw_entry_enter_url(void);
extern void mmi_brw_goto_url(void);

/* Settings Start */
extern void mmi_brw_setting_init(void);
extern void mmi_brw_entry_setting(void);

/*  Profile List */
extern void mmi_brw_setting_select_profile_highlight_hdlr(void);
extern void mmi_brw_entry_profile_list(void);

/* Browser Options */
extern void mmi_brw_setting_browser_option_highlight_hdlr(void);
extern void mmi_brw_setting_entry_browser_option(void);
extern void mmi_brw_setting_exit_browser_option(void);
extern void mmi_brw_setting_fill_inline_struct_browser_option(void);
extern void mmi_brw_setting_highlight_browser_option_edit_inline_item(S32 index);
extern void mmi_brw_read_setting_browser_option(void);
extern void mmi_brw_write_setting_browser_option(void);
extern void mmi_brw_setting_browser_option_confirm_save(void);
extern void mmi_brw_setting_browser_option_save(void);
extern void mmi_brw_time_out_get_string_value(S8 *StringVal, U16 value);
extern void mmi_brw_set_timeout_value(void);
extern void mmi_brw_setting_browser_option_cancel_save(void);   /* added by tk */

#ifdef __MMI_JATAAYU_BRW_SECURITY_SETTING__
/* Function to invoke the security setting screen of Certman. */
extern void mmi_brw_invoke_security_setting(void);  /* Ramneek */

/* Function to handle response of security setting. */
extern void mmi_brw_security_setting_rsp(void *info_p);
#endif /* __MMI_JATAAYU_BRW_SECURITY_SETTING__ */ 

/* Service Messages */
extern void mmi_brw_setting_service_messages_highlight_hdlr(void);
extern void mmi_brw_setting_service_messages_hint_hdlr(U16 index);
extern void mmi_brw_setting_service_messages_toggle(void);

/* Clear Cache */
extern void mmi_brw_setting_clear_cache_highlight_hdlr(void);
extern void mmi_brw_setting_clear_cache_confirm(void);
extern void mmi_brw_setting_clear_cache(void);

/*  Clear Cookies */
extern void mmi_brw_setting_clear_cookies_highlight_hdlr(void);
extern void mmi_brw_setting_clear_cookies_confirm(void);
extern void mmi_brw_setting_clear_cookies(void);

/*  Security Setting */
#ifdef __MMI_JATAAYU_BRW_SECURITY_SETTING__
extern void mmi_brw_setting_security_setting_highlight_hdlr(void);
#endif 
/* Settings End */

/* Rendered Page start */
extern void mmi_brw_rendered_page_init(void);
extern void mmi_brw_rendered_page_options(void);
extern void mmi_brw_ren_page_setting_highlight_hdlr(void);
extern void mmi_brw_ren_page_entry_setting(void);
extern void mmi_brw_ren_page_select(void);
extern void mmi_brw_download_menu_highlight_hdlr(void);
extern void mmi_brw_ren_page_goto_homepage_highlight_hdlr(void);
extern void mmi_brw_ren_page_goto_highlight_hdlr(void);
extern void mmi_brw_refresh_menu_highlight_hdlr(void);
extern void mmi_brw_exit_menu_highlight_hdlr(void);
extern void mmi_brw_ren_page_download_image(void);
extern void mmi_brw_ren_page_goto(void);
extern void mmi_brw_entry_ren_page_goto_homepage(void);
extern void mmi_brw_refresh_page(void);
extern void mmi_brw_entry_exit_menu(void);
extern void mmi_brw_ren_page_set_as_homepage_menu_highlight_hdlr(void);
extern void mmi_brw_ren_page_set_as_hompage(void);
extern BOOL IsRefreshPagePressed(void);

/* Rendered Page End */
extern void mmi_brw_pre_entry_goto_url(void);
extern void mmi_brw_set_current_url(S8 *brw_url_p);
extern void mmi_brw_entry_goto_url(void);
extern void mmi_brw_exit_goto_url(void);
extern void mmi_brw_deinit_jbrowser_ctxt(void);
extern void mmi_brw_deinit_all(void);
extern void mmi_brw_set_as_homepage(U8 *url_p);
extern MMI_BOOL mmi_brw_validate_url(U8 *url_p);
extern U8 mmi_brw_get_ren_page_status(void);
extern U8 mmi_brw_get_ren_page_refersh_display_status(void);
extern void mmi_brw_start_animated_splash_screen(void);
extern void mmi_brw_stop_animated_splash_screen(void);
extern void mmi_brw_show_long_idle_disconnected_notification(void);
extern void mmi_brw_handle_long_idle_disconnected_notification(void);
extern JC_BOOLEAN mmi_brw_check_browser_scr_pre_delte_condition(void);

#ifdef __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__
extern void mmi_brw_ren_page_display_curr_url_highlight_hdlr(void);
extern void mmi_brw_ren_page_display_current_url(void);
extern void mmi_brw_ren_page_send_link_via_sms_highlight_hdlr(void);
extern void mmi_brw_ren_page_send_link_via_sms(void);
#endif /* __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__ */ 

/* Authentication handling Start */
extern void mmi_brw_entry_auth_handler(void);
extern void mmi_brw_auth_full_screen_editor_options(void);
extern void mmi_brw_auth_entry_confirmation_hdlr(void);
extern void mmi_brw_exit_auth_handler(void);
extern void mmi_brw_auth_go_back_history(void);

/* Authentication handling End */

/* PMT DARA  PROFILE HANDLER 020106 */
extern void mmi_brw_show_profile_list(void);
extern void mmi_brw_free_do_list(void);
extern void mmi_brw_rendered_page_highlight_hdlr(S32 index);
extern void mmi_brw_ren_page_handle_do_element(void);
extern void mmi_brw_ren_page_process_do_element(void);
extern void mmi_brw_jbrowser_key_left_arrow_event_hdlr(void);
extern void mmi_brw_jbrowser_key_right_arrow_event_hdlr(void);
extern void mmi_brw_jbrowser_key_up_arrow_event_hdlr(void);
extern void mmi_brw_jbrowser_key_down_arrow_event_hdlr(void);
extern void mmi_brw_jbrowser_key_wap_event_hdlr(void);
extern void mmi_brw_jbrowser_go_event(void);
extern void mmi_brw_jbrowser_refresh_page(void);
extern void mmi_brw_jbrowser_sat_goto_url_event(void);
extern void mmi_brw_stop_fetch(void);
extern void mmi_brw_fill_control_info_and_send_event_to_queue(void);
extern void mmi_brw_goto_idle_screen_event(void);
extern void mmi_brw_jbrowser_refresh_display_hdlr(void);
extern BOOL mmi_brw_is_refresh_page_pressed(void);

/* Added by Shantanu -20060412 */
extern void mmi_brw_fill_accesskey_info_and_send_event_to_queue(void);
extern void mmi_brw_register_accesskey_handler(void);
extern void mmi_brw_clear_accesskey_handler(void);

/* Shantanu End */

/* Added by Shantanu to fetch the prev page in case of memory error-20060528 */
extern void mmi_brw_goto_prev_page(void);
extern void mmi_brw_free_duplicate_do_list(JC_DO_LIST **pTempDoList);
extern void mmi_brw_copy_linked_list(JC_DO_LIST *, JC_DO_LIST **);
extern U16 mmi_brw_get_do_element_count(JC_DO_LIST *);
extern JC_BOOLEAN mmi_brw_is_cancel_flag_set(void); /* Added for notification screen display */
extern JC_BOOLEAN mmi_brw_is_back(void);            /* added for back key handling */
extern void mmi_brw_set_connection_active_flag(JC_BOOLEAN);
extern JC_BOOLEAN mmi_brw_is_rendered_flag(void);
extern JC_BOOLEAN mmi_brw_is_browser_window_active(void);
extern void mmi_brw_delete_brw_screen(void);
extern void mmi_brw_goto_idle_screen(void);
extern void mmi_brw_register_endkey_handler(void);
extern void mmi_jdd_browser_core_events_hdlr(JC_EVENT_DATA *pEventData);
extern void mmi_jdd_browser_ui_events_hdlr(JC_EVENT_DATA *pEventData);
extern void mmi_brw_set_transport_and_data_profile(void);

#ifdef JBROWSER_USE_ASM
extern void mmi_brw_stop_wap_application(void);
extern JC_RETCODE mmi_brw_wap_enter_req_handler(void);
extern void mmi_brw_wap_request_asm_success_callback(void);
#endif /* JBROWSER_USE_ASM */ 

/* PIXTEL_JATAAYU */
extern JC_RETCODE mmi_brw_jbrowser_init_app(void);
extern void mmi_brw_jbrowser_deinit_app(void);
extern void mmi_brw_communication_init(void);

/* WAP PRIMITIVES */
extern void mmi_brw_wap_startup_req_hdlr(void *);
extern void mmi_brw_sat_launch_request(void *);
extern void mmi_brw_sat_lauch_response(U8);
extern void mmi_brw_wap_poweroff_request(void *);
extern void mmi_brw_wap_poweroff_response(void);
extern void mmi_brw_send_termination_to_mmi(U8);
extern void mmi_brw_wap_entry_busy_progressing_screen_in_idle(void);
extern void mmi_brw_wap_restore_factory_setting_req(void *);
extern void mmi_brw_restore_default_profile_settings(void);
extern void mmi_brw_restore_default_browser_settings(void);
extern void mmi_brw_restore_default_bookmarks(void);
extern void mmi_brw_wap_restore_factory_setting_cnf(void);
extern S32 mmi_brw_check_ip(S8 *);

/* Confirmation callback */
extern void mmi_brw_entry_confirm_callback_screen(void);
extern void mmi_brw_confirm_msg_LSK_hdlr(void);
extern void mmi_brw_confirm_msg_RSK_hdlr(void);

/* Alert callback */
extern void mmi_brw_entry_alert_callback_screen(void);
extern void mmi_brw_alert_msg_LSK_hdlr(void);

/* Prompt callback */
extern void mmi_brw_entry_prompt_callback_screen(void);
extern void mmi_brw_pre_entry_prompt_callback_editor_screen(void);
extern void mmi_brw_entry_prompt_callback_editor_screen(void);
extern void mmi_brw_prompt_msg_LSK_hdlr(void);
extern void mmi_brw_prompt_msg_RSK_hdlr(void);

/* WAP not ready screen */
extern void mmi_brw_exit_wap_not_ready(void);
extern void mmi_brw_wap_wait_and_go_back(void);

extern void mmi_brw_show_animated_title(void);
extern void mmi_brw_show_normal_title(void);
extern MMI_BOOL mmi_brw_is_animated_title(void);
extern JC_CHAR *mmi_brw_get_focussed_ctrl_title(void);

#ifdef __JBROWSER_DLS_SUPPORT__
extern JC_RETCODE mmi_brw_dls_header_info_callback_hdlr(
                    void *apparg_p,
                    COMM_HEADER_INDICATION *pBrowserHeaderIndication);
extern JC_RETCODE mmi_brw_dls_fetch_indication_info_callback_hdlr(
                    void *apparg_p,
                    COMM_FETCH_URL_IND_RESP *pBrowserFetchURLIndResp);
extern void mmi_brw_dls_fetch_error_info_callback_hdlr(void *apparg, JC_UINT32 uiReferenceID, JC_RETCODE eRet);
extern void mmi_brw_dls_send_file_dl_ind(void);
extern void mmi_brw_dls_file_dl_res_hdlr(void *Msg);
extern void mmi_brw_dls_send_file_dl_progress_ind(U8 status, U8 cause);
extern void mmi_brw_dls_file_dl_progress_res_hdlr(void *Msg);
extern void mmi_brw_dls_file_dl_stop_req_hdlr(void *Msg);
extern void mmi_brw_dls_send_file_dl_stop_rsp(U8 status, U8 cause);
extern JC_INT8 *mmi_brw_dls_get_content_type_from_file_name(JC_CHAR *file_name);
extern JC_CHAR *mmi_brw_dls_get_file_name_from_header(
                    JC_INT8 *header_p,
                    JC_UINT32 header_len,
                    ECommHeaderType header_type);
extern JC_CHAR *mmi_brw_dls_get_temp_file_name(void);
extern BOOL mmi_brw_dls_is_free_space_available(void *file_path);
extern void mmi_brw_dls_free_dwnld_info(BOOL deleteFile);
extern void mmi_brw_dls_free_cntx_memory(void);
extern void mmi_brw_dls_send_file_err(JC_RETCODE err_code);
extern void mmi_brw_dls_chk_navigation_history(void);

#else /* __JBROWSER_DLS_SUPPORT__ */ 
/* Object download screens */
extern void mmi_brw_start_dwnld(void);
extern void mmi_brw_entry_download_confirm(UI_string_type message, FuncPtr lsk_hdlr, FuncPtr rsk_hdlr);
extern void mmi_brw_exit_download_confirm(void);
extern void mmi_brw_entry_dwnld_progress(void);
extern void mmi_brw_exit_dwnld_progress(void);
extern void mmi_brw_abort_dwnld(void);
extern void mmi_brw_free_dwnld_info_memory(void);
extern void mmi_brw_update_downloading_msg(void);
extern void mmi_brw_cancel_dwnld_and_goback(void);
extern JC_RETCODE mmi_brw_header_info_callback_hdlr(void *app_arg_p, COMM_HEADER_INDICATION *pBrowserHeaderIndication);
extern JC_RETCODE mmi_brw_fetch_indication_info_callback_hdlr(
                    void *app_arg_p,
                    COMM_FETCH_URL_IND_RESP *pBrowserFetchURLIndResp);
extern void mmi_brw_fetch_error_info_callback_hdlr(void *app_arg_p, JC_UINT32 uiReferenceID, JC_RETCODE eRet);

extern JC_RETCODE mmi_brw_drm_rights_header_info_callback_hdlr(
                    void *papp_arg,
                    COMM_HEADER_INDICATION *pBrowserHeaderIndication);
extern JC_RETCODE mmi_brw_drm_rights_fetch_indication_info_callback_hdlr(
                    void *papp_arg,
                    COMM_FETCH_URL_IND_RESP *pBrowserFetchURLIndResp);
extern void mmi_brw_drm_rights_fetch_error_info_callback_hdlr(void *apparg_p, JC_UINT32 uiReferenceID, JC_RETCODE eRet);

extern void mmi_brw_save_mime_content(void);
extern void mmi_brw_cancel_save_mime_content(void);
#endif /* __JBROWSER_DLS_SUPPORT__ */ 

extern JC_CHAR *mmi_brw_get_file_name(S8 *url, U8 delim);
extern JC_CHAR *mmi_brw_get_temp_path_on_ext_mem(JC_CHAR *url);

extern JC_RETCODE mmi_brw_mime_callback_hdlr(
                    void *apparg_p,
                    JC_BROWSER_MIME_INFO *pMimeInfo,
                    JC_BROWSER_FETCH_CALLBACKS *pBrowserFetchCallBacks);
extern void mmi_brw_mime_content_callback_hdlr(void *apparg_p, COMM_URL_IND *pMimeContent);

extern void mmi_brw_jdd_browser_core_events_hdlr(JC_EVENT_DATA *event_data_p);

/* Page Status handler */
extern void mmi_brw_handle_page_request_begin(void);
extern void mmi_brw_handle_page_request_terminated(void);
extern void mmi_brw_handle_page_fetch_begin(void);
extern void mmi_brw_handle_page_fetch_terminated(void);
extern void mmi_brw_handle_page_rendering_begin(void);
extern void mmi_brw_handle_page_rendering_terminated(void);
extern void mmi_brw_handle_page_refresh_begin(void);
extern void mmi_brw_handle_page_refresh_terminated(void);
extern void mmi_brw_suspend_layout_marquee_timer(void);
extern void mmi_brw_resume_layout_marquee_timer(void);
extern void mmi_brw_clear_key_handler(U16 key_code);
extern void mmi_brw_set_data_connection_deactive_flag(JC_BOOLEAN flag);

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_brw_get_stylus_focussed_controlID(JC_UINT32 curr_controlID, JC_UINT32 *focussed_controlID);
extern void mmi_brw_handle_stylus_event(JC_INT32 x, JC_INT32 y, EStylusEvent event);
extern void mmi_brw_handle_stylus_scroll_event(JC_INT32 iPos, EScrollBarType eScrollType);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
extern void mmi_brw_mms_restore_default_profile_settings(void);
#endif 

#ifdef __USB_IN_NORMAL_MODE__
extern void mmi_brw_handle_usb_enter_req(void);
extern void mmi_brw_handle_usb_exit_req(void);
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __MMI_JBROWSER_SCREEN_LOCKING_ENABLED__
extern void mmi_brw_set_screen_visibility(mmi_brw_screen_display_enum status);
#endif 

extern JC_RETCODE mmi_brw_set_proxy_auth_info(void);
extern void mmi_brw_free_proxy_auth_info(void);

#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
/* Start of Prototype declaration for Offline Browsing */
extern void mmi_brw_offline_pages_init(void);
extern void mmi_brw_offline_pages_save_highlight_hdlr(void);
extern void mmi_brw_offline_pages_saved_pages_highlight_hdlr(void);
extern void mmi_brw_offline_pages_add_bkms_highlight_hdlr(void);
extern void mmi_brw_offline_pages_set_hmpage_highlight_hdlr(void);
extern void mmi_brw_entry_offline_pages_enter_name(void);
extern void mmi_brw_entry_offline_pages_saved_pages_list(void);
extern void mmi_brw_pre_entry_offline_pages_enter_name(void);
extern void mmi_brw_offline_pages_save_page(void);
extern void mmi_brw_pre_entry_offline_pages_options(void);
extern void mmi_brw_offline_pages_confirm_save(void);
extern void mmi_brw_offline_pages_options(void);
extern void mmi_brw_offline_pages_set_hmpage(void);
extern void mmi_brw_offline_pages_saved_pages_options_goto(void);
extern void mmi_brw_offline_pages_saved_pages_options_goto_highlight_hdlr(void);
extern void mmi_brw_offline_pages_saved_pages_options_delete_highlight_hdlr(void);
extern void mmi_brw_offline_pages_saved_pages_options_delete_all_highlight_hdlr(void);
extern void mmi_brw_offline_pages_saved_pages_options_rename_highlight_hdlr(void);
extern void mmi_brw_offline_pages_saved_pages_options_delete(void);
extern void mmi_brw_offline_pages_saved_pages_options_delete_all(void);
extern void mmi_brw_offline_pages_saved_pages_options_pre_rename(void);
extern void mmi_brw_offline_pages_saved_pages_confirm_delete(void);
extern void mmi_brw_offline_pages_saved_pages_confirm_delete_all(void);
extern void mmi_brw_offline_pages_page_info_highlight_hdlr(void);
extern void mmi_brw_offline_pages_options_page_info(void);
extern void mmi_brw_create_ucs2_offline_pages_time_format_string(FS_DOSDateTime *, PS8);
extern void mmi_brw_offline_pages_save_page_pre_entry(void);
extern void mmi_brw_saved_pages_get_absolute_path_ucs2(S8 *path);
extern S8 *mmi_brw_saved_pages_validate_name(S8 *name);
extern pBOOL mmi_brw_offline_pages_show_list_category_callback(S32, UI_string_type, PU8 *, U8);
extern void mmi_brw_offline_pages_set_file_index(S32 index);
extern void mmi_brw_delete_extension(S8 *name);
extern S8 *mmi_brw_offline_pages_remove_blank_spaces_from_start(S8 *name);
extern void mmi_print_ansii_for_unicode_string(S8 *ucs2_str);
extern MMI_BOOL mmi_brw_offline_pages_name_exist(S8 *name);
extern void mmi_brw_entry_offline_pages_enter_new_name(void);
extern void mmi_brw_offline_pages_rename(void);
extern void mmi_brw_offline_pages_rename_pre_entry(void);
extern void mmi_brw_offline_pages_delete_and_save(void);
extern void mmi_brw_offline_pages_add_to_bookmark(void);
extern void mmi_brw_offline_pages_edit_screen_option(void);
extern void mmi_brw_offline_pages_edit_done_highlight_hdlr(void);
extern void mmi_brw_offline_edit_input_method_info_highlight_hdlr(void);
extern void mmi_brw_offline_pages_edit_cancel_highlight_hdlr(void);
extern void mmi_brw_go_back_two_history(void);
extern JC_RETCODE mmi_brw_offline_pages_allocate_memory_to_offline_page_struct(JC_OFFLINE_PAGE_INFO *page_info);
extern void mmi_brw_offline_pages_free_memory_to_offline_page_struct(JC_OFFLINE_PAGE_INFO *page_info);
extern void mmi_brw_offline_pages_get_file_name_at_index(S8 *fname, U16 index);
extern void mmi_brw_offline_pages_show_popup(JC_RETCODE eRet);
extern U16 mmi_brw_offline_pages_get_index_at_file_name(S8 *file_name);
extern void mmi_brw_pre_entry_offline_pages_saved_pages_list(void);
extern void mmi_brw_offline_pages_get_title_from_url(S8 *title, S8 *url);
extern JC_RETCODE mmi_brw_offline_pages_allocate_curr_page_info(void);
extern void mmi_brw_offline_pages_go_back_history_with_no_replace(void);
extern void mmi_brw_offline_pages_fill_curr_page_info(void);
extern void mmi_brw_offline_pages_free_curr_page_info(void);
extern MMI_BOOL mmi_brw_offline_pages_is_file_exists(S8 *file_name);
extern void mmi_brw_offline_pages_fill_page_info_buffer(U8 **info_buffer);
extern void mmi_brw_deinit_offline_pages_app(void);
extern void mmi_brw_offline_pages_show_progress_screen(void);
extern JC_RETCODE mmi_brw_offline_status_callback(E_JC_OFFLINE_PAGE_OPER_TYPE eOpType, JC_RETCODE ret_code);
extern void mmi_brw_entry_offline_notification(void);
extern void mmi_brw_offline_pages_cancel_operation(void);
extern JC_OFFLINE_PAGE_FILE_CONTEXT **mmi_brw_init_offline_context(void);
extern void mmi_brw_offline_pages_get_progress_screen_process_string(S8 *string);
extern void mmi_brw_offline_pages_get_number_of_pages_at_location(
                U16 *number_of_pages,
                E_JC_OFFLINE_PAGE_MEM_TYPE location);
extern JC_RETCODE mmi_brw_offline_pages_sync(void);
extern JC_BOOLEAN mmi_brw_offline_pages_need_sync(void);
extern void mmi_brw_offline_pages_reset_sync(void);
extern void mmi_brw_offline_pages_show_progress_screen_exit(void);
extern void mmi_brw_offline_set_operation_type(void);
extern void mmi_brw_offline_pages_init_app(void);
extern S8 *mmi_brw_offline_pages_get_root_dir(void);
extern S32 mmi_brw_offline_pages_get_max_num_of_pages(void);
extern void mmi_brw_offline_pages_resume_auto_refresh_timer(void);
extern void mmi_brw_offline_pages_suspend_auto_refresh_timer(void);
extern void mmi_brw_offline_pages_show_memory_not_enough_notifycation(void);

#ifdef MMI_BRW_OFFLINE_PAGES_SELECT_LOCATION
extern void mmi_brw_offline_pages_set_curr_location(S32 location);
extern S32 mmi_brw_get_offline_pages_location(void);
#endif /* MMI_BRW_OFFLINE_PAGES_SELECT_LOCATION */ 

#endif /* __MMI_JATAAYU_BRW_OFFLINE_PAGES__ */ 

/* De-Init events */
extern void mmi_brw_deinit_event(void);
extern void mmi_brw_wps_deinit_event(void);

/* Security Start */
#if defined WAP_SEC_SUPPORT
extern JC_RETCODE mmi_brw_security_switch_callback_hdlr(
                    void *apparg_p,
                    E_BR_FETCH_MODE br_fetch_mode,
                    JC_BOOLEAN bisappinitiated,
                    CB_BROWSER_REWOKE_SECURITY_HANDLER cbrewokehandler,
                    void *cbarg_p,
                    JC_BOOLEAN is_main_page_content);
extern void mmi_brw_secure_to_nonsecure_mode_switch(void);
extern void mmi_brw_nonsecure_to_secure_mode_switch(void);
extern void mmi_brw_post_data_in_nonsecure_mode(void);
extern void mmi_brw_allow_switching_to_nonsecure_mode(void);
extern void mmi_brw_allow_switching_to_secure_mode(void);
extern void mmi_brw_allow_post_data_in_nonsecure_mode(void);
extern void mmi_brw_cancel_switching(void);
extern void mmi_brw_security_failure_callback_hdlr(
                void *apparg_p,
                COMM_SECURITY_FAILURE_IND *commsecurityfailureind_p,
                JC_BOOLEAN is_main_page_content);
extern void mmi_brw_continue_secure_authentication(void);
extern void mmi_brw_cancel_secure_authentication(void);
extern void mmi_brw_security_indication_callback_hdlr(
                void *apparg_p,
                COMM_SECURITY_IND *commsecurityind_p,
                JC_BOOLEAN is_main_page_content);
extern void mmi_brw_nonsecure_mode_indication_callback_hdlr(void *apparg_p, JC_BOOLEAN is_main_page_content);
extern void mmi_brw_user_certificate_indication_callback_hdlr(
                void *apparg_p,
                COMM_USER_CERT_REQ_IND *user_cert_req_details,
                JC_BOOLEAN is_main_page_content);
extern void mmi_brw_init_security_context(void);
extern void mmi_brw_init_wap_security(void);
extern void mmi_brw_deinit_wap_security(void);
extern void mmi_brw_deinit_wap_secure_mode(void);

extern void mmi_brw_handle_certman_ready_cnf(void *data_buf);
extern void mmi_brw_handle_get_certificate_details_cnf(void *data_buf);
extern void mmi_brw_view_server_certificate_highlight_hdlr(void);
extern void mmi_brw_send_view_certificate_indication(void);
extern void mmi_brw_handle_invalid_cert_resp(void *data_buf);
extern void mmi_brw_send_select_user_certificate_ind(void);
extern void mmi_brw_handle_select_user_cert_resp(void *data_buf);
extern void mmi_brw_handle_view_cert_resp(void *data_buf);
extern void mmi_brw_get_private_key_cnf(void *data_buf);

#ifdef CURRENTLY_NOT_SUPPORTED
extern void mmi_brw_certman_update_action_ind(mmi_certman_update_action_enum action, void *buffer_p);
#endif 
extern void mmi_brw_password_fb_callback_hdlr(
                kal_uint32 trans_id,
                kal_uint32 cert_id,
                const kal_uint8 *pwd,
                kal_uint32 size);
extern JC_RETCODE mmi_brw_create_folder(JC_CHAR *folder_name);
extern void mmi_brw_delete_folder(JC_CHAR *folder_name);
extern JC_RETCODE mmi_brw_create_file(JC_CHAR *file_name, JC_UINT8 *data_buffer, JC_UINT32 data_length);
extern JC_RETCODE mmi_brw_delete_file(JC_CHAR *file_name);
extern void mmi_brw_entry_select_user_certificate(void);
extern JC_RETCODE mmi_brw_compare_certificate_url(JC_CHAR *url);
extern void *mmi_brw_malloc_cb(kal_uint32 size);
extern void mmi_brw_mfree_cb(void *memblock);
extern JC_RETCODE mmi_brw_compare_certificates(JC_UINT8 *server_cert_buf, JC_UINT32 server_cert_buf_size);
extern void mmi_brw_add_url_to_list(JC_CHAR *url);
extern JC_RETCODE mmi_brw_search_url_in_the_list(JC_CHAR *url);
extern void mmi_brw_free_urls_list(void);
extern kal_uint32 mmi_brw_map_ssl_warning_to_certman(JC_UINT32 ssl_warning);

#endif /* defined WAP_SEC_SUPPORT */ 
/* Security End */

#endif /* _JBROWSERMMIPROTS_H */ 

