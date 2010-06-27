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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *    SyncMLProt.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef __SYNCML_PROT_H__
#define __SYNCML_PROT_H__

#ifdef __SYNCML_SUPPORT__

/* SyncMLMain.c */
extern void mmi_syncml_highlight_sync_menu(void);
extern void mmi_syncml_highlight_sync_now(void);
extern void mmi_syncml_highlight_sync_settings(void);
extern void mmi_syncml_highlight_sync_profile(void);
extern void mmi_syncml_highlight_applications_to_sync(void);
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
extern void mmi_syncml_highlight_sync_type(void);
#endif
extern void mmi_syncml_highlight_regular_sync(void);

extern void mmi_syncml_hint_sync_profile(U16 index);
extern void mmi_syncml_hint_applications_to_sync(U16 index);
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
extern void mmi_syncml_hint_sync_type(U16 index);
#endif
extern void mmi_syncml_hint_regular_sync(U16 index);

extern void mmi_syncml_entry_sync_menu(void);
extern void mmi_syncml_entry_sync_now(void);
extern void mmi_syncml_entry_sync_settings(void);
extern void mmi_syncml_entry_sync_profile(void);
extern void mmi_syncml_entry_applications_to_sync(void);
extern void mmi_syncml_entry_regular_sync(void);
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
extern void mmi_syncml_entry_sync_type(void);
#endif

extern void mmi_syncml_abort_sync(void);
extern void mmi_syncml_delete_sync_screen_callback(void);
extern void mmi_syncml_background_sync_query(void);

extern void mmi_syncml_highlight_regular_sync_selection(S32 index);
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
extern void mmi_syncml_highlight_sync_type_selection(S32 index);
#endif

extern void mmi_syncml_update_progress_string(U8 info_number);

extern void mmi_syncml_edit_profile_query(void);

extern void mmi_syncml_perform_delete_phb_one_by_one(void);
extern pBOOL mmi_syncml_is_phb_ready(void);

/* SyncMLProfile.c */
extern void mmi_syncml_init_profile(void);
extern void mmi_syncml_profile_highlight_handler(S32 index);
extern void mmi_syncml_entry_profiles_options(void);

//extern void mmi_syncml_highlight_profile_option(void);
extern void mmi_syncml_highlight_profile_activate(void);
extern void mmi_syncml_highlight_profile_edit(void);
extern void mmi_syncml_highlight_profile_name(void);
extern void mmi_syncml_highlight_profile_server(void);
extern void mmi_syncml_highlight_profile_contact(void);
extern void mmi_syncml_highlight_profile_calendar(void); 
extern void mmi_syncml_highlight_profile_connection(void);

extern void mmi_syncml_highlight_profile_edit_name_done(void);
extern void mmi_syncml_highlight_profile_edit_name_input(void);

extern void mmi_syncml_entry_profile_activate(void);
extern void mmi_syncml_entry_profile_edit(void);
extern void mmi_syncml_entry_profile_name(void);
extern void mmi_syncml_entry_profile_server(void);
extern void mmi_syncml_entry_profile_contact(void);
extern void mmi_syncml_entry_profile_calendar(void); 
extern void mmi_syncml_entry_profile_connection(void);

extern void mmi_syncml_exit_profile_server(void);
extern void mmi_syncml_exit_profile_contact(void);
extern void mmi_syncml_exit_profile_calendar(void);
extern void mmi_syncml_exit_profile_connection(void);

extern void mmi_syncml_set_profile_server_inline_editor(void);
extern void mmi_syncml_set_profile_contact_inline_editor(void);
extern void mmi_syncml_set_profile_calendar_inline_editor(void);
extern void mmi_syncml_set_profile_connection_inline_editor(void);
extern void mmi_syncml_edit_profile_server_save(void);
extern void mmi_syncml_edit_profile_contact_save(void);
extern void mmi_syncml_edit_profile_calendar_save(void);
extern void mmi_syncml_edit_profile_connection_save(void);
extern void mmi_syncml_edit_profile_server_done(void);
extern void mmi_syncml_edit_profile_contact_done(void);
extern void mmi_syncml_edit_profile_calendar_done(void);
extern void mmi_syncml_edit_profile_connection_done(void);

extern void mmi_syncml_entry_profile_edit_name_close_input_method(void);
extern void mmi_syncml_entry_profile_edit_name_save(void);
extern void mmi_syncml_entry_profile_edit_name_done(void);

extern pBOOL mmi_syncml_validate_profile_before_activate(void);
extern void mmi_syncml_entry_profile_name_option(void);
extern void mmi_syncml_abort_profile_edit(void);

extern void mmi_syncml_update_profile_to_nvram(U8 record_id, void *nvram_buf);
extern void mmi_syncml_read_profile_from_nvram(U8 record_id, void *nvram_buf);

extern void mmi_syncml_set_pc_profile_inline_editor(void);
extern void mmi_syncml_edit_pc_profile_save(void);
extern void mmi_syncml_edit_pc_profile_done(void);
extern void mmi_syncml_entry_pc_profile_edit(void);
extern void mmi_syncml_exit_pc_profile_edit(void);

extern void mmi_syncml_read_profile_name_display_strings(void);
extern void mmi_syncml_set_profile_custom_function(void);
#ifdef __MMI_WLAN_FEATURES__
extern U32 mmi_syncml_get_active_profile_bearer(void);
#endif

/* SyncMLChangeLog.c */
extern S32 mmi_syncml_search_duplicate_record(U16 luid, U8 profile_id, U8 application_type);
extern void mmi_syncml_prepare_record_to_save(U8 operation, U16 luid);
extern void mmi_syncml_append_record(U8 profile_id, U8 application_type);
extern void mmi_syncml_merge_record(U8 profile_id, U8 application_type, S32 fs_index);
extern U8 mmi_syncml_operation_update(U8 old_operation, U8 new_operation);

extern U32 mmi_syncml_get_current_time(void);

extern U16 mmi_syncml_query_change_log(U8 operation, U8 database, U16 *luid);
#if 0
/* under construction !*/
#endif
extern void mmi_syncml_clearall_change_log(U8 profile_id, U8 database);

/* SyncMLHandler.c */
extern void mmi_syncml_init_message_handlers(void);

extern void mmi_syncml_set_record_req_ind(void *info);
extern void mmi_syncml_get_record_req_ind(void *info);
extern void mmi_syncml_query_luid_list_req_ind(void *info);
extern void mmi_syncml_clean_luid_list_req_ind(void *info);
extern void mmi_syncml_finish_sync_ind(void *info);
extern void mmi_syncml_progress_info_ind(void *info);

extern void mmi_syncml_set_record_res_req(void);
extern void mmi_syncml_get_record_res_req(void);
extern void mmi_syncml_query_luid_list_res_req(void);
extern void mmi_syncml_clean_luid_list_res_req(void);
extern void mmi_syncml_start_sync_req(U8 *imei);

extern void mmi_syncml_get_imei_req(void);
extern void mmi_syncml_get_imei_rsp(void *info);

/* SyncMLRegularity.c */

/* SyncMLReport.c */
extern void mmi_syncml_init_sync_report(void);
extern void mmi_syncml_set_database_sync_fail(U8 db_type);
extern void mmi_syncml_entry_sync_report(void);
extern void mmi_syncml_highlight_sync_report(void);
extern void mmi_syncml_hint_sync_report(U16 index);

/* SyncMLSAS.c */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
extern void mmi_syncml_wap_push_req(PU16 filepath);
extern void mmi_syncml_wap_push_rsp(void *info);
extern void mmi_syncml_sas_req(U8 cause);
extern void mmi_syncml_sas_rsp(void *info);
extern void mmi_syncml_init_sas(void);
extern void mmi_syncml_sas_finish(void);
extern void mmi_syncml_entry_sas_background_sync(void);
extern MMI_BOOL mmi_syncml_is_sync_started_from_server(void);
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

#ifdef __MMI_SYNCML_CCA_SUPPORT__
extern S32 mmi_syncml_checking_for_dm(void);
#endif
#endif /* __SYNCML_SUPPORT__ */

#endif /* __SYNCML_PROT_H__ */

