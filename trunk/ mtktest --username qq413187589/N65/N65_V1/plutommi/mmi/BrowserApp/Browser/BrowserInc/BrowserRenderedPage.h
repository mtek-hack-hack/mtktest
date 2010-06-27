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
 * BrowserRenderedPage.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *	This file contains declaration of all the functions that are being used in the 
 *  implementation of Rendered Page.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSERRENDEREDPAGE_H
#define BROWSERRENDEREDPAGE_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "DLAgentDef.h"

/*Highlight Handlers*/
extern void mmi_brw_ren_page_this_link_highlight_hdlr(void);
extern void mmi_brw_ren_page_edit_highlight_hdlr(void);
extern void mmi_brw_ren_page_reset_highlight_hdlr(void);
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
extern void mmi_brw_ren_page_bkgrd_downloads_highlight_hdlr(void);
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/
extern void mmi_brw_ren_page_navigate_highlight_hdlr(void);
extern void mmi_brw_ren_page_this_page_highlight_hdlr(void);
extern void mmi_brw_ren_page_select_mode_highlight_hdlr(void);
extern void mmi_brw_ren_page_exit_highlight_hdlr(void);

extern void mmi_brw_this_link_goto_highlight_hdlr(void);
extern void mmi_brw_this_link_set_as_hmpage_highlight_hdlr(void);
#ifdef __MMI_VBOOKMARK__
extern void mmi_brw_this_link_add_to_bookmark_highlight_hdlr(void);
extern void mmi_brw_this_page_add_to_bookmark_highlight_hdlr(void);
#endif /*__MMI_VBOOKMARK__*/
extern void mmi_brw_this_link_send_address_highlight_hdlr(void);

extern void mmi_brw_this_page_set_as_hmpage_highlight_hdlr(void);
extern void mmi_brw_this_page_send_address_highlight_hdlr(void);
extern void mmi_brw_this_page_store_offline_highlight_hdlr(void);
extern void mmi_brw_this_page_objects_highlight_hdlr(void);
extern void mmi_brw_this_page_properties_highlight_hdlr(void);
extern void mmi_brw_page_objects_save_as_highlight_hdlr(void);
extern void mmi_brw_page_objects_properties_highlight_hdlr(void);

extern void mmi_brw_select_mode_save_as_highlight_hdlr(void);
extern void mmi_brw_select_mode_properties_highlight_hdlr(void);
extern void mmi_brw_select_mode_exit_highlight_hdlr(void);

extern void mmi_brw_ren_page_auth_dlg_items_highlight_hdlr(S32 index);

extern void mmi_brw_ren_page_navigate_highlight_handlers_init(void);
extern void mmi_brw_ren_page_navigate_refresh_highlight_hdlr(void);
extern void mmi_brw_ren_page_navigate_forward_highlight_hdlr(void);
extern void mmi_brw_ren_page_navigate_backward_highlight_hdlr(void);
extern void mmi_brw_ren_page_navigate_page_actions_highlight_hdlr(void);

extern void mmi_brw_ren_page_store_offline_editor_done_option_highlight_hdlr(void);
/*Highlight Handlers*/

extern void mmi_brw_ren_page_pre_exit(void);
extern void mmi_brw_this_page_pre_entry_store_offline(void);
extern void mmi_brw_this_page_entry_page_object_types(void);
extern void mmi_brw_this_page_pre_entry_page_object_types(void);
extern void mmi_brw_ren_page_entry_options(void);
extern void mmi_brw_ren_page_entry_this_link(void);
extern void mmi_brw_ren_page_entry_this_page(void);
extern void mmi_brw_entry_ren_page_navigate(void);
extern void mmi_brw_this_link_pre_entry_send_address(void);
extern void mmi_brw_this_page_pre_entry_send_address(void);
extern void mmi_brw_ren_page_navigate_entry_page_actions(void);
extern void mmi_brw_ren_page_entry_navigate(void);
extern void mmi_brw_this_page_entry_store_offline(void);
extern void mmi_brw_this_page_pre_entry_page_properties(void);
extern void mmi_brw_select_mode_pre_entry_image_properties(void);
extern void mmi_brw_page_objects_entry_options(void);
extern void mmi_brw_page_objects_pre_entry_options(void);
extern void mmi_brw_page_objects_pre_entry_object_properties(void);
extern void mmi_brw_ren_page_entry_auth_dialog(void);
extern void mmi_brw_ren_page_exit_auth_dialog(void);
extern void mmi_brw_ren_page_entry_sec_confirm_dialog(void);
extern void mmi_brw_ren_page_auth_dlg_entry_options(void);

extern void mmi_brw_ren_page_select_mode_activate(void);
extern void mmi_brw_ren_page_select_mode_exit(void);
extern void mmi_brw_ren_page_select_mode_save_as(void);
extern void mmi_brw_this_page_entry_page_properties(void);
extern void mmi_brw_this_page_store_offline(void);
extern void mmi_brw_this_link_set_as_homepage(void);
#ifdef __MMI_VBOOKMARK__
extern void mmi_brw_this_link_add_to_bookmark(void);
extern void mmi_brw_this_page_add_to_bookmark(void);
#endif /*__MMI_VBOOKMARK__*/
extern void mmi_brw_this_page_set_as_homepage(void);
extern pBOOL mmi_brw_ren_page_navigate_page_actions_list_get_item(S32 item_index, UI_string_type str_buff, 
												 PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_brw_ren_page_navigate_page_actions_ok(void);
extern void mmi_brw_ren_page_navigate_backward(void);
extern void mmi_brw_ren_page_navigate_forward(void);
extern void mmi_brw_ren_page_navigate_refresh(void);
extern void mmi_brw_ren_page_navigate_get_total_item_count(PU8);

extern void mmi_brw_ren_page_options(void);
extern void mmi_brw_ren_page_setting_highlight_hdlr(void);
extern void mmi_brw_ren_page_entry_setting(void);
extern void mmi_brw_download_menu_highlight_hdlr(void);
extern void mmi_brw_ren_page_goto_homepage_highlight_hdlr(void);
extern void mmi_brw_ren_page_goto_highlight_hdlr(void);
extern void mmi_brw_refresh_menu_highlight_hdlr(void);
extern void mmi_brw_exit_menu_highlight_hdlr(void);
extern void mmi_brw_ren_page_goto_homepage(void);
extern void mmi_brw_entry_ren_page_exit(void);
extern void mmi_brw_ren_page_set_as_homepage_menu_highlight_hdlr(void);
extern void mmi_brw_this_page_exit_page_properties(void);
extern void mmi_brw_this_link_goto(void);
extern void mmi_brw_ren_page_select_mode_confirm(void);
extern void mmi_brw_ren_page_select_mode_rsk_exit(void);
extern void mmi_brw_ren_page_left_arrow_key_hdlr(void);
extern void mmi_brw_ren_page_right_arrow_key_hdlr(void);
extern void mmi_brw_ren_page_up_arrow_key_hdlr(void);
extern void mmi_brw_ren_page_down_arrow_key_hdlr(void);
extern void mmi_brw_ren_page_set_title_string(void);
extern void mmi_brw_ren_page_set_title_icon(void);
extern void mmi_brw_ren_page_show_animated_title_icon(void);
extern void mmi_brw_ren_page_show_non_animated_title_icon(void);
extern void mmi_brw_ren_page_set_LSK(void);
extern void mmi_brw_ren_page_set_RSK(void);
extern void mmi_brw_this_page_get_page_object_types_count(U8* count_p);
extern pBOOL mmi_brw_page_object_types_get_item(S32 item_index, UI_string_type str_buff, 
												 PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_this_page_objects_get_item(S32 item_index, UI_string_type str_buff, 
												 PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_brw_this_page_object_types_ok(void);
extern void mmi_brw_this_page_get_page_objects_count(U8* count_p);
extern void mmi_brw_page_objects_save_as(void);
extern U32 mmi_brw_page_objects_get_object_res_list_index(void);
extern void mmi_brw_page_objects_read_resources(void);
extern void mmi_brw_page_objects_read_resources(void);
extern void mmi_brw_ren_page_show_auth_dialog_ind(void);
extern void mmi_brw_ren_page_fill_inline_struct_for_auth(void);
extern void mmi_brw_ren_page_auth_dlg_full_screen_editor_options(void);
extern void mmi_brw_http_auth_open_full_screen_editor(void);
extern void mmi_brw_ren_page_sec_confirm_dialog_res(S8);
extern void mmi_brw_ren_page_activate_do_element_req(void);
extern void mmi_brw_ren_page_navigate_req(U8, U8);
extern void mmi_brw_ren_page_reload_req(void);
extern void mmi_brw_ren_page_stop_page_fetching_req(void);
extern void mmi_brw_ren_page_navigation_change_req(U16);
extern void mmi_brw_this_page_save_page_req(U8*);
extern MMI_BOOL mmi_brw_ren_page_pen_handler(mmi_pen_point_struct, mmi_pen_event_type_enum);
extern void mmi_brw_this_page_get_resource_list_start_req(void);
extern void mmi_brw_this_page_get_resource_req(void);
extern void mmi_brw_this_page_get_resource_list_continue_req(U32);
extern void mmi_brw_this_page_get_resource_list_end_req(void);
extern MMI_BOOL mmi_brw_ren_page_is_backward_navigation(void);
extern MMI_BOOL mmi_brw_ren_page_is_forward_navigation(void);
extern void mmi_brw_ren_page_handle_pen_event_req(mmi_pen_point_struct, mmi_pen_event_type_enum);
extern void mmi_brw_ren_page_suspend_owl_rendering_req(void);
extern void mmi_brw_ren_page_resume_owl_rendering_req(void);
extern void mmi_brw_ren_page_notify_screen_info_req(MMI_BOOL refresh);
extern void mmi_brw_ren_page_activate_resource_req(U32);
extern void mmi_brw_ren_page_navigate_to_hotspot_req(U32);
extern void mmi_brw_ren_page_stop_page_fetching(void);
extern void mmi_brw_ren_page_edit_req(void);
extern void mmi_brw_ren_page_reset_req(void);
extern void mmi_brw_this_page_store_offline_confirm(void);
extern void mmi_brw_ren_page_object_action_req(U16);
extern void mmi_brw_ren_page_show_auth_dialog_res(U16);
extern void mmi_brw_ren_page_auth_dlg_save_options_done(void);
extern void mmi_brw_ren_page_auth_dlg_save_options_save_both(void);
extern void mmi_brw_ren_page_auth_dlg_save_options_save_only_username(void);
extern void mmi_brw_ren_page_auth_dlg_cancel(void);
extern void mmi_brw_ren_page_auth_dlg_ok(void);
extern void mmi_brw_ren_page_sec_confirm_dialog_positive_res(void);
extern void mmi_brw_ren_page_sec_confirm_dialog_negative_res(void);
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
extern void mmi_brw_ren_page_bkgrd_downloads_req(mmi_da_wap_notify_enum);
extern void mmi_brw_ren_page_suspend_bkgrd_downloads_confirm(void);
extern void mmi_brw_ren_page_suspend_bkgrd_downloads_accepted(void);
extern void mmi_brw_ren_page_suspend_bkgrd_downloads_rejected(void);
extern void mmi_brw_ren_page_bkgrd_downloads_display_list(void);
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/
extern void mmi_brw_ren_page_backward(void);
extern U16 mmi_brw_ren_page_get_title_icon(void);
extern U8* mmi_brw_ren_page_get_title_string(void);

/*Interfaces of other internal modules*/
#ifdef __MMI_VBOOKMARK__
extern void mmi_brw_bookmarks_entry_add_bookmark(void);
#endif /*__MMI_VBOOKMARK__*/
extern void mmi_brw_this_page_entry_page_objects(void);
extern void mmi_brw_recent_pages_get_recent_pages_list_end_req(void);
extern void mmi_brw_stored_pages_get_saved_pages_list_end_req(void);
/*Interfaces of other internal modules*/

#endif /* __MMI_BROWSER_2__ */ 
#endif /* BROWSERRENDEREDPAGE_H */ 

