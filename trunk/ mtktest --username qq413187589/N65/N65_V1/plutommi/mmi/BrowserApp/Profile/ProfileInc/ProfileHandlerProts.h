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
 * JProfileHandlerProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This declares the function prototypes for the profile handler module
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

#ifndef _PROFILEHANDLERPROTS_H
#define _PROFILEHANDLERPROTS_H

#define __NEWSIMULATOR
#include "MMI_features.h"
#include "MMIDataType.h"
#include "Wapadp.h"
#undef __NEWSIMULATOR

#ifdef __MMI_BROWSER_2__

extern void mmi_brw_prof_init(void);
extern void mmi_brw_prof_deinit_profiles(void);

/* nvram related functions */
extern void mmi_brw_prof_get_brw_profile_name_list(void);
extern void mmi_brw_prof_get_mms_profile_name_list(void);

extern void mmi_brw_prof_get_selected_profile_content_data(U8 g_profile_index);
extern void mmi_brw_prof_get_profile_nvram_content_data(U8 index);

extern void mmi_brw_prof_update_nvram_profile(void);
extern void mmi_brw_prof_update_nvram_mms_profile(void);

extern void mmi_brw_prof_update_nvram_activated_wap_profile(void);

/* provisioing related API */
extern void mmi_brw_prof_update_prov_nvram_wap_profile(void);
extern void mmi_brw_prof_update_prov_nvram_mms_profile(void);

extern U8 mmi_brw_prof_get_activated_profile_index(void);

/* general profile edit related API's */
extern void mmi_brw_prof_activate_profile_highlight_hdlr(void);
extern void mmi_brw_prof_edit_profile_highlight_hdlr(void);
extern void mmi_brw_prof_pre_entry_edit_selected_profile(void);

/**** temp function start ****/
extern void mmi_brw_prof_show_browser_list(void);
extern void mmi_brw_prof_show_mms_list(void);

/**** temp function end ****/
extern void mmi_brw_prof_pre_entry_show_profile_list_menu(prof_profile_enum profile);
extern void mmi_brw_prof_entry_show_profile_list_menu(void);
extern void mmi_brw_prof_entry_select_editable_profile(void);
extern void mmi_brw_prof_entry_edit_selected_profile(void);
extern void mmi_brw_prof_activate_selected_profile(void);
extern void mmi_brw_prof_entry_activate_selected_profile(void);
extern void mmi_brw_prof_selected_profile_fill_inline_struct(void);
extern void mmi_brw_prof_save_selected_profile_changes(void);
extern void mmi_brw_prof_editable_profile_save_changes(void);
extern void mmi_brw_prof_editable_profile_full_screen_edit(void);
extern void mmi_brw_prof_highlight_select_profile(S32 nIndex);
extern void mmi_brw_prof_exit_edit_selected_profile(void);
extern void mmi_brw_prof_editable_profile_reject_changes(void);
extern void mmi_brw_prof_update_profile_inline_values(void);

extern void mmi_brw_prof_highlight_inline_item(S32 index);
extern void mmi_brw_prof_entry_add_new_profile(void);

/* connection type related API */
extern void mmi_brw_prof_show_connection_type_options(void);
extern void mmi_brw_prof_entry_edit_connection_type_details(void);
extern void mmi_brw_prof_exit_edit_connection_type_details(void);
extern void mmi_brw_prof_conn_type_highlight_hdlr(S32 index);
extern void mmi_brw_prof_highlight_inline_item_conn_type(S32 index);
extern void mmi_brw_prof_edit_conn_type_fill_inline_struct(void);
extern void mmi_brw_prof_save_connection_type_changes(void);
extern void mmi_brw_prof_update_connection_type(void);

/* data account related functions */
extern void mmi_brw_prof_pre_entry_data_account(void);
extern void mmi_brw_prof_get_data_account_name(void);
extern void mmi_brw_prof_callback(U32 index);
extern void mmi_brw_prof_concatenate_primary_secondary_data_account(void);
extern void mmi_brw_prof_list_data_acct(void);

extern void mmi_brw_prof_get_csd_account_name_req(U8 ItemNum);
extern void mmi_brw_prof_get_csd_account_name_rsp(void *info);
extern void mmi_brw_prof_get_gprs_account_name_req(U8 ItemNum);
extern void mmi_brw_prof_get_gprs_account_name_rsp(void *info);

extern void mmi_brw_prof_entry_data_account_main(void);
extern void mmi_brw_prof_change_data_account_name(void);

/* extern ph_data_account_enum mmi_brw_prof_check_data_account_type(U8 accountIndex); */

extern U8 mmi_brw_prof_get_highlighted_menu_item(void);

/* general interfaces */

extern nvram_profile_content_struct *mmi_brw_prof_get_activated_wap_profile(void);
extern nvram_profile_content_struct *mmi_brw_prof_get_activated_mms_profile(void);

/* interface for browser */
extern void mmi_brw_prof_get_activated_profile_data(prof_profile_enum profile, U8 index);
extern U8 *mmi_brw_prof_brw_get_activated_profile_homepage(void);
extern void mmi_brw_prof_brw_set_activated_profile_homepage(U8 *homepage_url);

/* interface for MMS */
extern U8 *mmi_brw_prof_mms_get_activated_profile_mmsc_url(void);
extern void mmi_brw_prof_update_nvram_activated_mms_profile(void);

extern U8 mmi_brw_prof_get_profile_name_list(void);

//interface for java task
//void mmi_brw_prof_get_prof_list_req_hdlr(void);
//void mmi_brw_prof_get_prof_content_req_hdlr(void* msg);
extern void mmi_brw_prof_get_prof_list_req_hdlr(module_type req_src_id);
extern void mmi_brw_prof_get_prof_content_req_hdlr(module_type req_src_id, void *msg);
extern void mmi_brw_prof_get_activated_prof_id_req_hdlr(void);

extern void mmi_brw_prof_pre_entry_edit_profile(void);
extern U8 mmi_brw_prof_update_profile_index(void);
extern U8 mmi_brw_prof_update_profile_index(void);
extern void mmi_brw_prof_nvram_add_new_profile(void);
extern void mmi_brw_prof_entry_delete_selected_profile(void);
extern U8 mmi_brw_prof_check_free_content_index(U8 index);
extern void mmi_brw_prof_delete_profile_highlight_hdlr(void);
extern void mmi_brw_prof_pre_entry_delete_selected_profile(void);
extern void mmi_brw_prof_entry_data_account_type(void);
extern void mmi_brw_prof_data_account_type_highlight_hdlr(S32 index);
extern void mmi_brw_prof_entry_data_account_type_bearers(void);
extern void mmi_brw_prof_data_account_type_highlight_hdlr(S32 index);
extern void mmi_brw_prof_data_account_type_bearers_highlight_hdlr(S32 index);
extern void mmi_brw_prof_show_data_account_bearer_list(void);
extern void mmi_brw_prof_pre_entry_edit_get_primary_data_account(void);
extern void mmi_brw_prof_reset_profile_content(U8 index);

extern void mmi_brw_prof_entry_view_selected_profile(void);
extern void mmi_brw_prof_selected_profile_default_fill_inline_struct(void);
extern void mmi_brw_prof_exit_view_selected_profile(void);

extern void mmi_brw_prof_set_default_setting(U8 profile_type);
extern void mmi_brw_prof_set_wap_default_profile_list(void);
extern void mmi_brw_prof_set_mms_default_profile_list(void);
extern void mmi_brw_prof_set_default_setting_temp(void);
extern void mmi_brw_prof_restore_default_setting(void *msg);

extern void mmi_brw_prov_save_profile(void);
extern void mmi_brw_prov_update_selected_profile(void);

extern void mmi_prov_install_setting(void);

extern pBOOL mmi_brw_prof_wap_set_homepage(S8 *homepage_url);
extern void mmi_brw_prof_update_activated_profile_data(void);

extern void PreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);

/* Interfaces of other modules */
extern pBOOL GetUCS2Flag(S8 *);
extern void ReturnThreeDigitString(PU8 StringVal, U8 DigitVal);
//extern pBOOL mmi_brw_validate_url(PU8);
extern nvram_profile_content_struct * mmi_prof_get_content(prof_profile_enum profile_type,U16 index);
extern void mmi_brw_dm_prov_update_profile (nvram_profile_content_struct *profile_content, 
									 S32 index, prof_profile_enum profile_type);
extern nvram_profile_content_struct * mmi_prov_dm_create_default_profile(prof_profile_enum profile_type);

extern void mmi_brw_prov_get_content_from_setting(void);
extern void mmi_brw_prov_update_remaining_profile_count(void);

extern void mmi_prov_commit_setting(void);
void mmi_brw_prof_activated_profile_id_req(void *msg);
//void mmi_brw_prof_profile_content_req(void *msg);
void mmi_brw_prof_profile_content_req(void *local_param, int mod_id, void *ilm);
void mmi_brw_prof_profile_list_req(void *local_param, int mod_id, void *ilm);
wap_prof_conn_type_enum mmi_brw_prof_wap_conn_type(prof_conn_type_enum conn_type);
void mmi_brw_prof_display_activation_popup(void);
void jam_get_user_agent_req(void *msg);
/* Interfaces of other modules */

#endif /* __MMI_BROWSER_2__ */ 

#endif /* _PROFILEHANDLERPROTS_H */ 

