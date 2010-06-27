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
 * BrowserSettings.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *	This file contains declaration of all the functions that are being used in the 
 *  implementation of browser settings.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSERSETTINGS_H
#define BROWSERSETTINGS_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "ProfileHandlerTypes.h"

/*Highlight Handlers*/
extern void mmi_brw_settings_highlight_handlers_init(void);
extern void mmi_brw_settings_highlight_hdlr(void);
extern void mmi_brw_ren_page_settings_highlight_hdlr(void);
extern void mmi_brw_settings_browser_options_highlight_handlers_init(void);
extern void mmi_brw_settings_edit_profile_highlight_hdlr(void);
extern void mmi_brw_settings_homepage_settings_highlight_hdlr(void);
extern void mmi_brw_settings_browser_options_highlight_hdlr(void);
extern void mmi_brw_settings_browser_preferences_highlight_hdlr(void);
extern void mmi_brw_settings_push_settings_highlight_hdlr(void);
extern void mmi_brw_settings_restore_browser_settings_highlight_hdlr(void);
extern void mmi_brw_settings_user_defined_hmpage_highlight_hdlr(void);
extern void mmi_brw_settings_user_defined_hmpage_activate_highlight_hdlr(void);
extern void mmi_brw_settings_user_defined_hmpage_modify_highlight_hdlr(void);
extern void mmi_brw_settings_user_defined_hmpage_view_highlight_hdlr(void);
extern void mmi_brw_settings_user_defined_hmpage_use_current_page_highlight_hdlr(void);
extern void mmi_brw_settings_user_defined_hmpage_use_blank_highlight_hdlr(void);
extern void mmi_brw_settings_user_defined_hmpage_edit_highlight_hdlr(void);
extern void mmi_brw_settings_active_profile_hmpage_highlight_hdlr(void);
extern void mmi_brw_settings_active_profile_hmpage_activate_highlight_hdlr(void);
extern void mmi_brw_settings_active_profile_hmpage_view_highlight_hdlr(void);
extern void mmi_brw_settings_rendering_modes_highlight_hdlr(void);
extern void mmi_brw_settings_navigation_modes_highlight_hdlr(void);
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
extern void mmi_brw_settings_font_size_highlight_hdlr(void);
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
extern void mmi_brw_settings_thumbnail_highlight_hdlr(void);
extern void mmi_brw_settings_screen_size_highlight_hdlr(void);
extern void mmi_brw_settings_encoding_highlight_hdlr(void);
extern void mmi_brw_settings_clear_cache_highlight_hdlr(void);
extern void mmi_brw_settings_clear_cookie_highlight_hdlr(void);
extern void mmi_brw_settings_browser_preferences_items_highlight_hdlr(S32);
extern void mmi_brw_settings_clear_auth_info_highlight_hdlr(void);
extern void mmi_brw_settings_rendering_modes_standard_highlight_hdlr(void);
extern void mmi_brw_settings_rendering_modes_text_wrap_highlight_hdlr(void);
extern void mmi_brw_settings_rendering_modes_screen_optimized_highlight_hdlr(void);
extern void mmi_brw_settings_rendering_modes_text_only_highlight_hdlr(void);
extern void mmi_brw_settings_navigation_modes_four_way_highlight_hdlr(void);
extern void mmi_brw_settings_navigation_modes_two_way_highlight_hdlr(void);
extern void mmi_brw_settings_navigation_modes_scrolling_highlight_hdlr(void);
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
extern void mmi_brw_settings_font_size_small_highlight_hdlr(void);
extern void mmi_brw_settings_font_size_medium_highlight_hdlr(void);
extern void mmi_brw_settings_font_size_large_highlight_hdlr(void);
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
extern void mmi_brw_settings_active_profile_hmpage_edit_highlight_hdlr(void);
extern void mmi_brw_settings_active_profile_hmpage_editor_done_option_highlight_hdlr(void);
extern void mmi_brw_settings_user_defined_hmpage_editor_done_option_highlight_hdlr(void);
#if defined (WAP_SEC_SUPPORT)
extern void mmi_brw_settings_security_setting_highlight_handlers_init(void);
extern void mmi_brw_settings_security_settings_highlight_hdlr(void);
extern void mmi_brw_security_settings_trusted_certificates_highlight_hdlr(void);
extern void mmi_brw_security_settings_session_info_highlight_hdlr(void);
extern void mmi_brw_security_settings_trusted_certificates_view_highlight_hdlr(void);
extern void mmi_brw_security_settings_trusted_certificates_delete_highlight_hdlr(void);
extern void mmi_brw_security_settings_current_certificate_highlight_hdlr(void);
#endif /*WAP_SEC_SUPPORT*/
/*Highlight Handlers*/

/*Hint Handlers*/
extern void mmi_brw_settings_rendering_modes_hint_hdlr(U16);
extern void mmi_brw_settings_navigation_modes_hint_hdlr(U16);
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
extern void mmi_brw_settings_font_size_hint_hdlr(U16);
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
extern void mmi_brw_settings_thumbnail_hint_hdlr(U16);
extern void mmi_brw_settings_screen_size_hint_hdlr(U16);
extern void mmi_brw_settings_encoding_hint_hdlr(U16);
/*Hint Handlers*/

extern void mmi_brw_entry_settings(void);
extern void mmi_brw_settings_entry_ren_page_settings(void);
extern void mmi_brw_settings_entry_homepage_settings(void);
extern void mmi_brw_settings_entry_user_defined_homepage(void);
extern void mmi_brw_settings_entry_active_profile_homepage(void);
extern void mmi_brw_settings_entry_browser_options(void);
extern void mmi_brw_settings_entry_browser_preferences(void);
extern void mmi_brw_settings_user_defined_hmpage_entry_modify(void);
extern void mmi_brw_settings_entry_rendering_modes(void);
extern void mmi_brw_settings_entry_navigation_modes(void);
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
extern void mmi_brw_settings_entry_font_size(void);
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
extern void mmi_brw_settings_entry_encoding_methods(void);
extern void mmi_brw_settings_active_profile_hmpage_entry_edit(void);
#if defined (WAP_SEC_SUPPORT)
extern void mmi_brw_settings_entry_security_settings(void);
extern void mmi_brw_security_settings_entry_trusted_certificates(void);
extern void mmi_brw_security_settings_trusted_certificates_entry_options(void);
extern void mmi_brw_security_settings_entry_session_info(void);
extern void mmi_brw_security_settings_trusted_certificates_entry_view(void);
extern void mmi_brw_security_settings_trusted_certificates_pre_entry_options(void);
extern pBOOL mmi_brw_security_settings_trusted_certificates_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_brw_security_settings_trusted_certificates_delete(void);
extern void mmi_brw_security_settings_get_session_info_req(void);
extern void mmi_brw_security_settings_get_session_info_str(U8* msg_str);
extern void mmi_brw_security_settings_get_trusted_certificate_ids_req(void);
extern void mmi_brw_security_settings_copy_trusted_certificate(wps_sec_cert_content_struct*, wps_sec_cert_content_struct*);
extern void mmi_brw_security_settings_trusted_certificates_delete_req(U32);
extern void mmi_brw_security_settings_get_current_certificate_req(void);
extern void mmi_brw_security_settings_get_current_cert_str(U8* msg_str);
extern void mmi_brw_security_settings_get_trusted_certificate_req(U32 cert_id);
extern void mmi_brw_security_settings_trusted_certificates_list_free_memory(void);
extern void mmi_brw_security_settings_get_trusted_certificate_str(U32, U8*);
#endif /*WAP_SEC_SUPPORT*/
extern void mmi_brw_settings_update_thumbnail_status(void);
extern void mmi_brw_settings_update_screen_size(void);
extern void mmi_brw_settings_clear_cache(void);
extern void mmi_brw_settings_clear_cookie(void);
extern void mmi_brw_settings_clear_cache_confirm(void);
extern void mmi_brw_settings_clear_cache(void);
extern void mmi_brw_settings_clear_cookie_confirm(void);
extern void mmi_brw_settings_clear_cookie(void);
extern void mmi_brw_settings_read_browser_options(void);
extern void mmi_brw_settings_write_browser_options(void);
extern void mmi_brw_settings_user_defined_hmpage_activate(void);
extern void mmi_brw_settings_active_profile_hmpage_activate(void);
extern void mmi_brw_settings_set_current_page_as_user_defined_homepage(void);
extern void mmi_brw_settings_set_blank_as_user_defined_homepage(void);
extern void mmi_brw_settings_user_defined_hmpage_entry_edit(void);
extern void mmi_brw_settings_user_defined_hmpage_entry_view(void);
extern void mmi_brw_settings_restore_browser_settings(void);
extern void mmi_brw_settings_push_settings(void);
extern void mmi_brw_settings_update_rendering_mode(void);
extern void mmi_brw_settings_update_navigation_mode(void);
extern void mmi_brw_settings_update_encoding_method(void);
extern void mmi_brw_settings_update_navigation_mode(void);
extern void mmi_brw_settings_active_profile_hmpage_view(void);
extern void mmi_brw_settings_clear_auth_info_confirm(void);
extern void mmi_brw_settings_clear_auth_info(void);
extern void mmi_brw_settings_rendering_modes_standard(void);
extern void mmi_brw_settings_rendering_modes_text_wrap(void);
extern void mmi_brw_settings_rendering_modes_screen_optimized(void);
extern void mmi_brw_settings_rendering_modes_text_only(void);
extern void mmi_brw_settings_navigation_modes_four_way(void);
extern void mmi_brw_settings_navigation_modes_two_way(void);
extern void mmi_brw_settings_navigation_modes_scrolling(void);
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
extern void mmi_brw_settings_font_size_small(void);
extern void mmi_brw_settings_font_size_medium(void);
extern void mmi_brw_settings_font_size_large(void);
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
extern void mmi_brw_settings_active_profile_hmpage_save(void);
extern void mmi_brw_settings_exit_browser_preferences(void);
extern void mmi_brw_settings_fill_inline_struct_for_browser_preferences(void);
extern void mmi_brw_settings_active_profile_hmpage_entry_view(void);
extern void mmi_brw_settings_browser_preferences_confirm_save(void);
extern void mmi_brw_settings_browser_preferences_save(void);
extern void mmi_brw_settings_browser_preferences_cancel(void);
extern void mmi_brw_settings_nvram_data_init(void);
extern void mmi_brw_settings_show_profile_list(void);
extern void mmi_brw_settings_read_homepage_settings(void);
extern void mmi_brw_settings_read_browser_preferences(void);
extern void mmi_brw_settings_write_homepage_settings(void);
extern void mmi_brw_settings_write_rendering_mode_value(void);
extern void mmi_brw_settings_write_navigation_mode_value(void);
extern void mmi_brw_settings_write_thumbnail_status(void);
extern void mmi_brw_settings_write_screen_size_status(void);
extern void mmi_brw_settings_write_encoding_method_index(void);
extern void mmi_brw_settings_get_user_defined_homepage(U8* strHomepage);
extern void mmi_brw_settings_set_user_defined_homepage(U8* strHomepage);
extern void mmi_brw_settings_get_active_profile_homepage(U8* strHomepage);
extern void mmi_brw_settings_set_active_profile_homepage(U8* strHomepage);
extern void mmi_brw_settings_user_defined_hmpage_save(void);
extern void mmi_brw_settings_browser_preferences_set_default(void);
extern void mmi_brw_settings_browser_options_set_default(void);
extern void mmi_brw_settings_restore_browser_settings_confirm(void);
extern void mmi_brw_settings_resize_screen_req(void);
extern void mmi_brw_settings_set_profile_req(void);
extern void mmi_brw_settings_browser_preferences_write_inline_struct(void);
extern void mmi_brw_settings_browser_preferences_read_inline_struct(void);
extern void mmi_brw_settings_rendering_modes_set_hilite_index(void);
extern void mmi_brw_settings_navigation_modes_set_hilite_index(void);
extern void mmi_brw_settings_change_setting_value_req(U8 data_type, U32 setting_id, U32 value_i, U8* value_bv);
extern void mmi_brw_settings_read_user_defined_homepage(void);
extern void mmi_brw_settings_write_user_defined_homepage(void);
extern void mmi_brw_settings_user_defined_hmpage_activate_confirm(void);
extern void mmi_brw_settings_active_profile_hmpage_activate_confirm(void);
extern void mmi_brw_settings_clear_data_req(U8 operation);
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
extern void mmi_brw_settings_font_size_set_hilite_index(void);
extern void mmi_brw_settings_write_font_size_value(void);
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
extern void mmi_brw_settings_encoding_methods_free_memory(void);
extern void mmi_brw_settings_encoding_methods_initialize_list(void);
extern void mmi_brw_security_settings_copy_current_certificate(wps_sec_get_current_cert_rsp_struct* dest_p, 
														wps_sec_get_current_cert_rsp_struct* src_p);

/*Interfaces of other internal modules*/
extern void mmi_brw_prof_pre_entry_show_profile_list_menu(prof_profile_enum profile);
#if defined (WAP_SEC_SUPPORT)
extern void mmi_brw_security_settings_get_session_info_rsp(void*);
extern void mmi_brw_security_settings_get_current_certificate_rsp(void*);
#endif /*WAP_SEC_SUPPORT*/
/*Interfaces of other internal modules*/

/******************************************************************************/
/*  Profile List */
extern void mmi_brw_entry_profile_list(void);
/* Browser Options */
extern void mmi_brw_setting_browser_option_highlight_hdlr(void);
extern void mmi_brw_setting_entry_browser_option(void);
extern void mmi_brw_setting_exit_browser_option(void);
extern void mmi_brw_setting_fill_inline_struct_browser_option(void);
extern void mmi_brw_setting_highlight_browser_option_edit_inline_item(S32 index);
extern void mmi_brw_setting_browser_option_confirm_save(void);
extern void mmi_brw_setting_browser_option_save(void);
//extern void mmi_brw_time_out_get_string_value(U8 *StringVal, U16 value);
extern void mmi_brw_set_timeout_value(void);
extern void mmi_brw_setting_browser_option_cancel_save(void);   
/******************************************************************************/

#endif /* __MMI_BROWSER_2__ */ 
#endif /* BROWSERSETTINGS_H */ 

