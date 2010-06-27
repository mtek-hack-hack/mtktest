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
 * PushInboxResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This defines the String ,screen,& Image ID for push inbox module
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
/*
 * #ifndef _JPROFILEHANDLERDEFS_H
 * #define _JPROFILEHANDLERDEFS_H
 */
#define __NEWSIMULATOR

#include "MMI_features.h"
#include "MMIDataType.h"
#include "pmg_struct.h"
#include "PushInboxTypes.h"
#include "custom_nvram_editor_data_item.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "UnifiedMessageGprot.h"
#undef __NEWSIMULATOR
#ifdef __MMI_BROWSER_2__

void mmi_brw_push_enable_highlight_hdlr(void);
void mmi_brw_push_trust_setting_highlight_hdlr(void);
void mmi_brw_push_sl_setting_highlight_hdlr(void);
void mmi_brw_push_trust_list_highlight_hdlr(void);
void mmi_brw_push_modify_trust_addr_highlight_hdlr(void);
void mmi_brw_push_delete_trust_addr_highlight_hdlr(void);
void mmi_brw_push_delete_all_trust_addr_highlight_hdlr(void);
void mmi_brw_push_entry_select_editable_addr(void);
void mmi_brw_push_trust_add_new_phone_highlight_hdlr(void);
void mmi_brw_push_trust_add_new_ip_highlight_hdlr(void);
void mmi_brw_push_trust_add_new_domain_highlight_hdlr(void);

void HintPushEnable(U16 Index);
void HintPushTrustSetting(U16 Index);
void HintPushSlSetting(U16 Index);

void mmi_brw_push_pre_entry_edit_addr(void);
void mmi_brw_phs_pre_entry_push_setting(void);

void mmi_brw_phs_entry_push_setting(void);
void mmi_brw_psh_entry_push_enable(void);
void mmi_brw_psh_entry_trust_setting(void);
void mmi_brw_psh_entry_sl_setting(void);
void mmi_brw_psh_entry_trust_list(void);
void mmi_brw_psh_entry_by_phone_no(void);
void mmi_brw_psh_entry_by_domain_name(void);
void mmi_brw_psh_entry_by_ip_address(void);
void mmi_brw_psh_entry_modify_trust_addr(void);
void mmi_brw_psh_entry_delete_trust_addr(void);
void mmi_brw_psh_entry_delete_all_trust_addr(void);
void mmi_brw_psh_delete_trust_addr(void);
void mmi_brw_psh_delete_all_trust_addr(void);
void mmi_brw_psh_restore_default_setting(void *msg);
void mmi_brw_psh_set_default_setting(void);
void mmi_brw_init_push(void);

void mmi_brw_psh_highlight_trust_list_addr(S32 index);
void mmi_brw_push_sl_setting_index(S32 index);
void mmi_brw_push_trust_setting_index(S32 index);
void mmi_brw_push_enable_index(S32 index);

void mmi_brw_phs_get_setting_from_nvram(void);

void mmi_brw_push_entry_add_new_addr(void);

void mmi_brw_psh_get_trust_list(void);
void mmi_brw_psh_get_trust_list_count(void);
void mmi_brw_psh_free_mem_back_history(void);
void mmi_brw_psh_phone_no_rsk_handling(void);
void mmi_brw_psh_domain_rsk_handling(void);
void mmi_brw_psh_ip_rsk_handling(void);
void mmi_brw_psh_show_save_confirmation_scr(void);

void mmi_brw_psh_validate_phone_no(void);
void mmi_brw_psh_go_to_trust_screen(void);
void mmi_brw_psh_save_trust_entry_phone_no(void);
void mmi_brw_psh_validate_domain_name(void);
void mmi_brw_psh_save_trust_entry_domain_name(void);
void mmi_brw_push_exit_add_new_by_ip_address(void);
void mmi_brw_psh_save_trust_entry_ip_address(void);
void mmi_brw_push_edit_ip_fill_inline_struct(void);
U8 mmi_brw_get_trust_addr_index(void);
void mmi_brw_push_setting_update_hint_status(void);

void mmi_brw_push_save_push_enable_status(void);
void mmi_brw_push_save_trust_setting_status(void);
void mmi_brw_push_save_sl_setting_status(void);
void mmi_brw_validate_push_si_msg(void);
void mmi_brw_push_handle_new_msg_display(void);

extern void PreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);

void mmi_brw_push_new_msg_ind(void *local_param, int mod_id, void *ilm);

void mmi_brw_push_msg_delete_ind(void *msg);
void mmi_brw_push_replace_msg_ind(void *local_param, int mod_id, void *ilm);
void mmi_brw_push_storage_full_ind(void *msg);

void mmi_brw_push_send_delete_msg_req(wap_pmg_delete_msg_req_struct *delete_msg);
void mmi_brw_push_delete_msg_rsp(void *msg);

void mmi_brw_push_get_pmg_count_req(wap_pmg_msg_count_req_struct *local_data);
void mmi_brw_push_msg_count_rsp(void *msg);

void mmi_brw_push_msg_list_req(S32 start_index, S32 num_item);
void mmi_brw_push_msg_list_rsp(void *msg);
void mmi_brw_push_handle_pshmsg_get_msg_list_rsp(void);

void mmi_brw_push_msg_list_rsp(void *msg);

void mmi_brw_push_get_msg_rsp(void *local_param, int mod_id, void *ilm);
void mmi_brw_push_handle_get_msg_rsp(void);

void mmi_brw_push_delete_all_msg_req(void);
void mmi_brw_push_delete_all_msg_rsp(void *msg);

void mmi_brw_push_update_msg_req(wap_pmg_update_msg_req_struct *local_data);
void mmi_brw_push_update_msg_rsp(void *msg);

void mmi_brw_push_config_msg_cnf(void *msg);
void mmi_brw_push_send_msg_req_by_index(void);

void mmi_brw_push_validate_service_msg(void);
void mmi_brw_push_delete_invalid_msg(void);
pBOOL mmi_brw_push_validate_trust_list(push_msg_ind_queue_struct *pushMsg);

void mmi_brw_push_inbox_init(void);
S16 mmi_brw_push_new_queue_entry(pmg_detailed_msg_struct *data);
pBOOL mmi_brw_push_check_duplicate_msg(push_msg_ind_queue_struct *push_msg);

S16 mmi_brw_push_push_entry(push_msg_ind_queue_struct *new_push_msg);
push_msg_ind_queue_struct *mmi_brw_push_get_last_item(void);
push_msg_ind_queue_struct *mmi_brw_push_pop_entry(void);
void mmi_brw_push_free_queue_entry(push_msg_ind_queue_struct *the_item);
void mmi_brw_push_free_sl_from_queue(void);

void mmi_brw_push_new_push_msg_popup(void);
void mmi_brw_push_entry_new_push_msg_ind(void);

U8 mmi_brw_push_new_push_msg_ind(void);
void mmi_brw_push_new_push_msg_ind_on_idlescreen(void);

void mmi_brw_push_validate_msg_on_other_screen(void);
void mmi_brw_push_validate_msg_on_push_inbox_screen(void);
void mmi_brw_push_entry_invalid_service_msg_on_pushinbox(void);

void mmi_brw_push_delete_last_msg(void);
void mmi_brw_delete_last_msg_from_queue(void);

void mmi_brw_push_get_msg_from_service_layer(S16 msgID, push_transID_enum trans_id);

void mmi_brw_push_entry_display_service_message(void);
void mmi_brw_push_read_arrived_service_message(void);

void mmi_brw_push_entry_invalid_service_msg(void);

void mmi_brw_push_entry_new_service_msg(void);
void mmi_brw_push_rsk_handling(void);

PS8 mmi_brw_push_create_display_format(void);
void mmi_brw_push_entry_display_service_message_option(void);

void mmi_brw_push_pre_entry_push_inbox(void);

pBOOL mmi_brw_push_check_buffer_list(S32 start_indx, S32 end_indx);
pBOOL mmi_brw_check_index_in_buffer(S32 index);
void mmi_brw_push_entry_processing_generic(void);
S32 mmi_brw_push_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);

void mmi_brw_push_pre_entry_inbox(void);

void mmi_brw_push_entry_inbox(void);
void mmi_brw_push_hilite_msg_index(S32 index);

U32 push_get_current_utc_time(void);
void mmi_brw_push_pre_entry_inbox_validation(void);

void display_service_msg_rsk_handling(void);
void dispaly_service_msg_option_rsk_handling(void);

void mmi_brw_push_free_msg_buffer(void);

void mmi_brw_push_accept_msg_push_inbox(void);
void mmi_brw_push_delete_msg_push_inbox(void);

void mmi_brw_push_entry_msg(void);

void mmi_brw_push_create_ucs2_time_format_string(MYTIME *time, PS8 ucs2_time_string);

void mmi_brw_push_delete_msg_from_inbox(void);
void mmi_brw_push_delete_all_msg_from_inbox(void);

void mmi_brw_push_add_to_bookmark(void);
void mmi_brw_push_set_as_homepage(void);
void mmi_brw_push_goto_url(void);
void mmi_brw_send_by_email(void);
void mmi_brw_send_by_sms(void);
void mmi_brw_send_by_mms(void);
void mmi_brw_push_add_to_trust_list(void);
void mmi_brw_push_send_by_highlight_hdlr(void);

void mmi_brw_psh_entry_send_by_option(void);
void rsk_handling_push_inbox_list(void);

void *mmi_push_malloc(U32 size);
void mmi_push_mfree(void *ptr);

void mmi_brw_push_free_memory(void);    /* called when brwoser is exited */
void mmi_brw_push_end_key_handling(void);

pBOOL mmi_brw_push_inbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

void mmi_brw_push_goto_highlight_hdlr(void);
void mmi_brw_push_add_to_trust_list_highlight_hdlr(void);
void mmi_brw_push_add_homepage_highlight_hdlr(void);
void mmi_brw_push_delete_highlight_hdlr(void);
void mmi_brw_push_delete_all_highlight_hdlr(void);
void mmi_brw_push_send_by_email_highlight_hdlr(void);
void mmi_brw_push_send_by_sms_highlight_hdlr(void);
void mmi_brw_push_send_by_mms_highlight_hdlr(void);

void DeleteAllPushMsg(void);
void DeletePushMsg(void);

pBOOL mmi_brw_push_add_new_msg_at_front_inbox_buffer(void);
pBOOL mmi_brw_push_replace_msg_from_inbox_buffer(wap_pmg_replace_ind_struct *replace_msg_ind, U8 *href);
pBOOL mmi_brw_push_delete_msg_from_queue(S32 msgID);
pBOOL mmi_brw_push_replace_msg_from_queue(wap_pmg_replace_ind_struct *replace_msg_ind);
void mmi_brw_push_process_new_msg(void);

void mmi_brw_phs_get_unread_msg_count(void);
void mmi_brw_psh_entry_idle_screen(void);
void mmi_brw_push_pre_entry_display_service_message(void);
void mmi_brw_push_exit_display_service_message(void);
void mmi_brw_push_load_sl_high(void);
extern int wap_is_ready(void);
extern void mmi_brw_push_stop_timer(void);
U32 mmi_brw_push_get_utc_local_time(U32 timeSecs);
void mmi_brw_push_count_req_during_new_msg_ind(void);
S8	*mmi_brw_push_construct_send_by_data(void);
extern void LoadPushUrl(void);
void mmi_brw_push_handle_status_icons(S32 unread_count);
pBOOL mmi_brw_push_handle_replace_ind_as_new_msg (wap_pmg_replace_ind_struct *replace_msg_ind,
											U8 *href);
void mmi_brw_push_add_msg_to_queue (wap_pmg_replace_ind_struct *replace_msg_ind,
							  U8 *href);
void mmi_brw_push_send_trust_list(U8 index, U8 count);
void mmi_brw_push_send_config_ind(void);
#ifdef __MMI_VBOOKMARK__
void mmi_brw_push_add_bookmark_highlight_hdlr(void);
#endif
pBOOL mmi_brw_push_construct_msg_for_validation(void);
/***** for UT purpose *****/
/*
 * void mmi_brw_push_send_msg_ind_UT(void);
 * void mmi_brw_push_msg_send_count_response(void);
 * void mmi_brw_send_msg_rsp(S16 msgID);
 * void mmi_brw_push_send_msg_list_response(S32 start_index, S32 num_item);
 * void mmi_brw_push_send_update_msg_response(void);
 * void mmi_brw_push_send_delete_msg_rsp(S8 transID);
 */

/**** for UM API's ****/
#ifdef __MMI_UNIFIED_MESSAGE__
void mmi_push_um_new_msg_ind(mmi_um_new_msg_ind_struct *um_msg_data);
void mmi_push_um_delete_all_ind(void);
void mmi_brw_um_push_msg_entry(kal_uint16 msg_box_type, kal_uint16 msg_index);
void mmi_push_um_delete_all_res(void *msg);
void mmi_brw_um_disp_push_msg(void);
void mmi_brw_um_push_read_highlight_hdlr(void);
void mmi_brw_um_pre_entry_message_display(void);
void mmi_brw_um_message_display_option(void);
void mmi_brw_um_push_process_new_msg_ind(wap_pmg_new_msg_ind_struct *data);
void mmi_um_refresh_msg_ind(void);
void mmi_brw_um_compile_option_delete_highlight_hdlr(void);
void mmi_brw_push_um_inbox_option_delete_msg(void);
void DeleteUMMsg(void);
void mmi_brw_push_um_handle_replace_ind(wap_pmg_replace_ind_struct *replace_msg_ind,
											U8 *href);
void mmi_brw_um_sisl_high_handling (wap_pmg_replace_ind_struct *replace_msg_ind,
											U8 *href);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

/**** for service layer dialogue *****/

S16 mmi_brw_push_service_dlg_entry(push_service_dlg_struct *data);
S16 mmi_brw_push_push_service_dlg(push_dlg_queue_struct *new_dlg_msg);
push_dlg_queue_struct *mmi_brw_push_get_last_service_dlg(void);
push_dlg_queue_struct *mmi_brw_push_pop_service_dlg(void);
void mmi_brw_push_free_service_dlg(push_dlg_queue_struct *the_item);
void mmi_brw_push_service_dlg_confirm_req(void *msg);
void mmi_brw_push_service_dlg_unknown_addr_req(void *msg);
void display_service_cnf_lsk_handler(void);
void display_service_cnf_rsk_handler(void);
void display_service_cnf_endkey_handler(void);
void mmi_brw_push_entry_display_service_msg_cnf(void);
void service_unknown_addr_lsk_handler(void);
void service_unknown_addr_rsk_handler(void);
void service_unknown_addr_endkey_handler(void);
void mmi_brw_push_entry_service_unknown_addr(void);
void mmi_push_service_unknown_addr_higlight_hldr(S32 index);
U8 mmi_brw_push_service_dlg_idle_scr_cb(void);
void mmi_brw_push_fetch_dlg_from_queue(void);


/*
 * #define MAX_IP_ADDRES_LEN                    (4)
 * 
 * typedef enum
 * {
 * PUSH_ENABLE_ON =0,
 * PUSH_ENABLE_OFF
 * }push_enable_enum;
 * 
 * typedef enum
 * {
 * PUSH_SL_SETTING_NEVER =0,
 * PUSH_SL_SETTING_CONFIRM,
 * PUSH_SL_SETTING_WITHOUT_CONFIRM,
 * }push_sl_setting_enum;
 * 
 * typedef enum
 * {
 * PUSH_TRUST_SETTING_DISABLE =0,
 * PUSH_TRUST_SETTING_ALWAYS,
 * PUSH_TRUST_SETTING_ALWAYS_ASK,
 * }push_trust_setting_enum;
 * 
 * typedef enum
 * {
 * PUSH_ADD_NEW_TRUST_ENTRY =1,
 * PUSH_MODIFY_TRUST_ENTRY,
 * }push_add_modify_trust_entry_enum;
 * 
 * typedef struct
 * {
 * pBOOL push_msg_recv_flag;
 * U16   enable_push_strid;
 * U16   sl_setting_strid;
 * U16   trust_setting_strid;
 * U8   trust_addr_index;
 * U8   trust_addr_count;
 * U8   trust_address[(NVRAM_PUSH_ADDR_LEN_MAX+1)*ENCODING_LENGTH];
 * U8   trust_addr_type;
 * U8   IP1[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
 * U8    IP2[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
 * U8    IP3[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
 * U8    IP4[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
 * U8   add_entry_flag;
 * }global_push_cntx;
 * 
 * extern nvram_push_setting_struct *push_setting_data;
 */

#endif
