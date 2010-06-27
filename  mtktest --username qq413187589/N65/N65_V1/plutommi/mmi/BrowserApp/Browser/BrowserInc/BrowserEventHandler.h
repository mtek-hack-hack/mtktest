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
 * BrowserEventHandler.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *	This file contains declaration of all the ilm message handlers like indication(ind),
 *  response(rsp) and cnf messages getting from Browser Adaptation Module(BAM).
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSEREVENTHANDLER_H
#define BROWSEREVENTHANDLER_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"

extern void mmi_brw_event_hdlr_send_ilm(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void mmi_brw_event_hdlr_send_ilm_to_wps(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void mmi_brw_event_hdlr_register_all_ilm_handlers(void);
extern void mmi_brw_ren_page_show_auth_dialog_ind(void*);
extern void mmi_brw_sec_confirm_dialog_ind(void*);
extern void mmi_brw_create_instance_cnf(void*);
extern void mmi_brw_delete_instance_cnf(void*);
extern void mmi_brw_ren_page_do_element_ind(void *msg, int mod_src, void *ilm_p);
extern void mmi_brw_this_page_save_page_cnf(void *msg, int mod_src, void *ilm_p);
extern void mmi_brw_status_ind(void*);
extern void mmi_brw_settings_set_profile_cnf(void*);
extern void mmi_brw_stored_pages_get_saved_pages_list_start_cnf(void*);
extern void mmi_brw_stored_pages_get_saved_pages_list_continue_cnf(void *msg, int mod_src, void *ilm_p);
extern void mmi_brw_this_page_get_resource_list_start_cnf(void*);
extern void mmi_brw_this_page_get_resource_list_continue_cnf(void *msg, int mod_src, void *ilm_p);
extern void mmi_brw_this_page_get_resource_cnf(void *msg, int mod_src, void *ilm_p);
extern void mmi_brw_error_ind(void*);
extern void mmi_brw_document_info_ind(void*);
extern void mmi_brw_page_element_focused_ind(void*);
extern void mmi_brw_set_security_class_ind(void*);
extern void mmi_brw_recent_pages_get_recent_pages_list_start_cnf(void*);
extern void mmi_brw_recent_pages_get_recent_pages_list_continue_cnf(void *msg, int mod_src, void *ilm_p);
extern void mmi_brw_recent_page_cnf(void *msg, int mod_src, void *ilm_p);
extern void mmi_brw_watai_tel_ind(void*);
extern void mmi_brw_watai_pb_ind(void*);
extern void mmi_brw_uri_request_ind(void*);
extern void mmi_brw_bearer_info_ind(void*);
extern void mmi_brw_settings_clear_data_rsp(void* msg);
extern void mmi_brw_wait_user_action_ind(void* msg);
extern void mmi_brw_bam_ready_ind(void* msg);
extern void mmi_brw_bam_error_handler(U16 error_code);
extern void mmi_brw_wps_error_handler(U16 error_code);
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
extern void mmi_brw_bkgrd_downloads_ind(void* msg);
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/
#ifdef __MMI_VBOOKMARK__
extern void mmi_brw_select_bookmark_req(void*);
extern void mmi_brw_bookmarks_pre_entry_select_bookmark(void);
#endif /*__MMI_VBOOKMARK__*/
#if defined (WAP_SEC_SUPPORT)
extern void mmi_brw_security_settings_trusted_certificate_list_ind(void*);
extern void mmi_brw_security_settings_get_session_info_rsp(void*);
extern void mmi_brw_security_settings_get_trusted_certificate_ids_rsp(void*);
extern void mmi_brw_security_settings_get_current_certificate_rsp(void*);
extern void mmi_brw_trusted_certificates_delete_rsp(void*);
extern void mmi_brw_security_settings_get_trusted_certificate_rsp(void*);
#endif /*WAP_SEC_SUPPORT*/
extern void mmi_brw_wap_browser_startup_req(void *msg);
extern MMI_BOOL mmi_brw_is_browser_active(void);

/*Interfaces of other internal modules*/
#if defined (WAP_SEC_SUPPORT)
extern void mmi_brw_security_settings_entry_trusted_certificates(void);
extern void mmi_brw_security_settings_entry_session_info(void);
extern void mmi_brw_security_settings_entry_current_cert(void);
extern void mmi_brw_security_settings_copy_trusted_certificate(wps_sec_cert_content_struct*, wps_sec_cert_content_struct*);
extern void mmi_brw_security_settings_get_trusted_certificate_req(U32 cert_id);
#endif /*WAP_SEC_SUPPORT*/
extern void mmi_brw_ren_page_entry_show_auth_dialog(void);
extern void mmi_brw_sec_entry_confirm_dialog(void);
extern void mmi_brw_stored_page_pre_entry_page_properties(wap_bam_saved_page_struct*);
extern void mmi_brw_stored_pages_get_saved_pages_list_continue_req(U32);
extern void mmi_brw_stored_pages_get_saved_pages_list_end_req(void);
extern void mmi_brw_entry_stored_page_list(void);
extern void mmi_brw_this_page_get_resource_list_continue_req(U32);
extern void mmi_brw_this_page_get_resource_list_end_req(void);
extern void mmi_brw_this_page_pre_entry_page_object_types(void);
extern void mmi_brw_page_objects_entry_options(void);
extern void mmi_brw_ren_page_set_title_string(void);
extern void mmi_brw_ren_page_set_title_icon(void);
extern void mmi_brw_ren_page_set_LSK(void);
extern void mmi_brw_ren_page_set_RSK(void);
extern void mmi_brw_recent_pages_get_recent_pages_list_continue_req(U32);
extern void mmi_brw_watai_tel_make_call_confirm(void);
extern void mmi_brw_watai_tel_send_dtmf_confirm(void);
extern void mmi_brw_watai_pb_add_new_entry_confirm(void);
extern void mmi_brw_process_uri_request_confirm(void);
extern void mmi_brw_bearer_info_confirm(void);
extern void mmi_brw_address_list_update_title_to_nvram(U8 *);
extern void mmi_brw_stored_page_entry_options(void);
extern void mmi_brw_recent_page_entry_options(void);
extern void mmi_brw_recent_pages_get_recent_pages_list_end_req(void);
extern void mmi_brw_pre_entry_recent_page_list(void);
extern void mmi_brw_recent_pages_delete_recent_page_req(U32);
extern void mmi_brw_splash_screen_timer_callback(void);
extern void mmi_brw_splash_screen_stop_timer(void);
extern void mmi_brw_recent_pages_free_memory(void);
extern void mmi_brw_dynamic_list_delete_item(U16 item_index);
extern void mmi_brw_recent_pages_host_list_delete_item(U8* host_name);
extern void mmi_brw_ren_page_entry_sec_confirm_dialog(void);
extern void mmi_brw_ren_page_entry_auth_dialog(void);
extern void mmi_brw_settings_encoding_methods_initialize_list(void);
extern void mmi_brw_security_settings_get_trusted_certificate_ids_req(void);
extern void mmi_brw_security_settings_copy_current_certificate(wps_sec_get_current_cert_rsp_struct* dest_p,
														wps_sec_get_current_cert_rsp_struct* src_p);
extern void mmi_brw_set_status_icon(S16 icon_id, MMI_BOOL show_icon);
extern void mmi_brw_app_init(void);
extern void mmi_brw_redirection_delete_brw_screens_upto_rend_page(void);
extern void mmi_brw_start_browser_action(U8 option, U8* url);
/*Interfaces of other internal modules*/

#endif /* __MMI_BROWSER_2__ */ 

#endif /* BROWSEREVENTHANDLER_H */ 

