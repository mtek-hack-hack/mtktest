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
 *  SMSFunc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_SMSFUNC_H
#define _MMI_SMSFUNC_H

extern void mmi_frm_sms_new_sms(void);
extern U8 mmi_frm_sms_check_sms_complete(U16 type, U16 index);
extern U8 mmi_frm_sms_set_sms_status(U16 type, U16 index, U8 newtype);
extern U16 mmi_frm_sms_get_sms_status(U16 type, U16 index);
extern U8 mmi_frm_sms_get_sms_dcs(U16 type, U16 index);
extern U8 *mmi_frm_sms_get_sms_address(U16 type, U16 index);
extern U8 *mmi_frm_sms_get_sms_timestamp(U16 type, U16 index);
extern U8 mmi_frm_sms_read_sms_seg(void);
extern void mmi_frm_sms_read_sms_req(void *inMsg);
extern void mmi_frm_sms_get_sms_req(void *inMsg);
extern void mmi_frm_sms_save_sms_seg(void);
extern void mmi_frm_sms_save_sms_req(void *inMsg);
extern void mmi_frm_sms_delete_sms_req(void *inMsg);
extern void mmi_frm_sms_set_bitmap(U16 index, U8 *index_bitmap);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern U8 mmi_frm_sms_get_one_archive_msg(U16 index);
extern U8 mmi_frm_sms_save_one_archive_msg(mmi_frm_sms_msgbox_enum fromboxtype, U16 srcIndex, FS_HANDLE *fsErrCode); 
extern U8 mmi_frm_sms_remove_one_archive_msg(U16 type, U16 index);
extern U8 mmi_frm_sms_remove_all_archive_msg(U16 type);
extern MMI_BOOL mmi_frm_sms_get_archive_del_folder_result(void);
extern void mmi_frm_sms_clear_archive_del_folder_result(void);
extern void mmi_frm_sms_set_archive_del_folder_result(MMI_BOOL result);
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
#ifdef __MMI_MESSAGES_COPY__
extern void mmi_frm_sms_pre_copy_sms_req(void *dummy);
extern void mmi_frm_sms_pre_copy_sms_rsp(void *inMsg);
extern void mmi_frm_sms_copy_sms_seg_req(void);
extern void mmi_frm_sms_copy_sms_seg_rsp(void *inMsg);
extern void mmi_frm_sms_copy_sms_move_rsp(void *inMsg);
extern void mmi_frm_sms_copy_sms_rollback_rsp(void *inMsg);
extern void mmi_frm_sms_copy_sms_callback(U16 result, U8 cause);
extern U8 mmi_frm_sms_get_sms_storage(U16 type, U16 index);
extern void mmi_frm_sms_copy_sms_abort(void);
#endif /* __MMI_MESSAGES_COPY__ */ 

extern void mmi_frm_sms_abort_sms_req(void *inMsg);
extern void mmi_frm_sms_send_sms_seg(void);
extern void mmi_frm_sms_pre_send_sms(void *inMsg);
extern void mmi_frm_sms_send_sms_req(void);
extern void mmi_frm_sms_set_sc_addr_for_send_req(void *inMsg);
extern void mmi_frm_sms_reg_port_req(void *inMsg);
extern void mmi_frm_sms_get_profile_num_req(void *dummy);
extern void mmi_frm_sms_get_profile_name_req(void *inMsg);
extern void mmi_frm_sms_get_sc_addr_req(void *inMsg);
extern void mmi_frm_sms_set_sc_addr_req(void *inMsg);
extern void mmi_frm_sms_get_profile_detail_req(void *inMsg);
extern void mmi_frm_sms_set_profile_detail_req(void *inMsg);
extern void mmi_frm_sms_get_common_settings_req(void *dummy);
extern void mmi_frm_sms_set_common_settings_req(void *inMsg);

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
extern void mmi_frm_sms_get_memory_status_req(void *dummy);
extern void mmi_frm_sms_get_preferred_storage_req(void *dummy);
extern void mmi_frm_sms_set_preferred_storage_req(void *inMsg);
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
extern void mmi_frm_sms_get_preferred_bearer_req(void *dummy);
extern void mmi_frm_sms_set_preferred_bearer_req(void *inMsg);
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 
extern void mmi_frm_sms_get_mailbox_info_req(void *dummy);
extern void mmi_frm_sms_set_mailbox_info_req(void *inMsg);

extern void mmi_frm_sms_entry_abort(void);
extern void mmi_frm_sms_entry_send(void);
extern void mmi_frm_sms_entry_save(void);
extern void mmi_frm_sms_entry_sc(void);
extern void mmi_frm_sms_entry_number(void);
extern void mmi_frm_sms_entry_number_done(void);

extern void mmi_frm_sms_abort_sms(void);
extern void mmi_frm_sms_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);
extern U8 mmi_frm_sms_write_action(PsFuncPtrU16 callback, module_type mod_src, void *data, PsFuncPtr function);
extern U8 mmi_frm_sms_read_action(void);
extern void mmi_frm_sms_callback_action(void *data, U16 result);

extern void mmi_frm_sms_reg_interrupt_handler(module_type mod, U16 msgid, PsFuncPtrU16 callback);
extern void mmi_frm_sms_interrupt_callback(module_type mod, U16 msgid, void *inMsg, U16 result);
extern void mmi_frm_sms_convert_time_stamp(U8 *scts, U8 *timestamp);
extern void mmi_frm_sms_free_awaited(U8 index);
extern void mmi_frm_sms_free_data(U8 index);
extern U8 mmi_frm_sms_add_data_entry(void);
extern void mmi_frm_sms_free_new_data(void);
extern void mmi_frm_sms_new_data(void);
extern void mmi_frm_sms_indicate_sms(U16 index);

extern void mmi_frm_sms_create_sms_list(void);
extern U8 mmi_frm_sms_check_concatenate_sms(U16 *index);
extern U8 mmi_frm_sms_check_data_complete(U8 index);
extern U8 mmi_frm_sms_check_concatenate_data(U8 *index);
extern U8 mmi_frm_sms_get_awaited_sms(U8 index, mmi_frm_sms_deliver_msg_struct *entry, U8 *content);
extern void mmi_frm_sms_add_new_sms(mmi_frm_sms_deliver_msg_struct *entry, U16 length, U8 *data);
extern void mmi_frm_sms_add_new_data(mmi_frm_sms_deliver_data_struct *entry, U16 length, U8 *data);
extern void mmi_frm_sms_free_new_sms(void);
extern void mmi_frm_sms_convert_new_data(
                MMI_FRM_SMS_APP_DATA_IND_STRUCT *data,
                mmi_frm_sms_deliver_data_struct *entry);
extern void mmi_frm_sms_convert_new_sms(
                MMI_FRM_SMS_DELIVER_MSG_IND_STRUCT *data,
                mmi_frm_sms_deliver_msg_struct *entry);
extern void mmi_frm_sms_convert_read_to_entry(
                MMI_FRM_SMS_GET_MSG_RSP_STRUCT *data,
                mmi_frm_sms_msgbox_struct *entry,
                U16 index);
extern void mmi_frm_sms_convert_startup_read_to_entry(
                MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT *data,
                mmi_frm_sms_msgbox_struct *entry);
extern void mmi_frm_sms_convert_mt_to_entry(mmi_frm_sms_deliver_msg_struct *data, mmi_frm_sms_msgbox_struct *entry);
extern void mmi_frm_sms_convert_mo_to_entry(
                mmi_frm_sms_send_struct *data,
                mmi_frm_sms_msgbox_struct *entry,
                U16 index,
                U8 status,
                U8 totalsegment,
                U16 reference,
                U8 storagetype,
                MYTIME *time);
extern U16 mmi_frm_sms_add_sms_to_msgbox(mmi_frm_sms_msgbox_struct *entry, U16 index, U8 thisseg);
extern void mmi_frm_sms_get_sms_list_index(U16 *type, U16 *index, U16 msgbox_index);
extern void mmi_frm_sms_get_sms_index(mmi_frm_sms_msgbox_enum type, U16 index, U16 *l4_index);
extern void mmi_frm_sms_get_sms_msgbox_index(U16 l4_index, U16 *msgbox_index);
extern U8 mmi_frm_sms_get_sms_bitmap(U16 type, U16 index, U8 *l4_index);
extern void mmi_frm_sms_remove_sms_from_msgbox(U8 *data);
extern void mmi_frm_sms_remove_sms_entry(U16 index);
extern void mmi_frm_sms_new_msg_ind(U16 index);
extern void mmi_frm_sms_retry_new_msg_ind(void);
extern U8 mmi_frm_sms_get_data_index(module_type mod, U16 port, U8 startindex);
extern U8 mmi_frm_sms_get_data(U8 index, mmi_frm_sms_deliver_data_struct *data, U8 *content);
extern void mmi_frm_sms_remove_data(module_type mod, U16 port);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern mmi_frm_sms_msgbox_enum mmi_frm_sms_get_archive_src_box_type(U16 type, U16 index);
extern void mmi_frm_sms_archive_change_status_to_read(U16 type, U16 index);
extern void mmi_frm_sms_delete_current_archive_msg(void);
#endif

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
extern void mmi_frm_sms_check_delivery_report_awaited(BOOL result, smsal_concat_struct	concat_info, U8 msg_mr);
extern U16 mmi_frm_sms_get_delivery_report_index_by_mr(U8 msg_ref);
extern U16 mmi_frm_sms_get_delivery_report_index_by_ref(U16 ref);
extern void mmi_frm_sms_remove_delivery_report_awaited(U16 index);
extern void mmi_frm_sms_set_delivery_report_awaited_check(U16 index, U8 msg_ref, U8 status_type);
extern BOOL mmi_frm_sms_check_delivery_report_awaited_complete(U16 index);
extern void mmi_frm_sms_add_delivery_report_awaited(U16 reference_no, U8 total_seg, U8 box_index, U8 msg_ref);
extern void mmi_frm_sms_set_delivery_report_awaited_mr(U16 delivery_report_awaited_index, U8 msg_ref, U8 seq_number);
extern U8 mmi_frm_sms_get_delivery_report_awaited_result(U16 index);
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */ 

extern void mmi_frm_sms_set_protocol_event_handler(void);

extern void mmi_frm_sms_convert_mytime(U8 *scts, MYTIME *time);

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_frm_sms_add_content_to_entry(mmi_frm_sms_msgbox_struct *entry, U8 *content);
extern U8 mmi_frm_sms_get_startup_sms_content(MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT *entry, U8 *content);
extern U8 mmi_frm_sms_get_read_sms_content(MMI_FRM_SMS_GET_MSG_RSP_STRUCT *entry, U8 *content);
extern void mmi_frm_sms_abort_sms_by_end_key(void);
extern void mmi_frm_sms_abort_sms_req_by_end_key(void *inMsg);
extern void mmi_frm_sms_callback_abort_sms_by_end_key(void);
extern void mmi_frm_sms_highlight_ind(U8 msg_box_type, U16 index);

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_frm_sms_get_sim_memory_req(void);
extern void mmi_frm_sms_get_sim_memory_rsp(void *inMsg);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

#endif /* __MMI_UNIFIED_MESSAGE__ */
extern void mmi_frm_sms_send_sms_rsp(void *inMsg);
extern void mmi_frm_sms_abort_sms_ind(void *inMsg);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
extern void mmi_frm_sms_save_sms_to_unsent_seg(void);
extern void mmi_frm_sms_save_sms_to_unsent_rsp(void *inMsg);
extern void mmi_frm_sms_background_send_sms_seg(void);
extern void mmi_frm_sms_background_send_sms_rsp(void *inMsg);
extern BOOL mmi_frm_sms_get_unsent_sms_waitting_index(U16 *msgIndex);
extern void mmi_frm_sms_background_move_to_otherbox_rsp(void *inMsg);
extern void mmi_frm_sms_background_send_refresh_ind(U16 index, U8 send_stauts);
extern void mmi_frm_sms_delete_sms_sent_rsp(void *inMsg);
extern void mmi_frm_sms_background_change_sent_to_unsent_req(void);
extern void mmi_frm_sms_background_change_sent_to_unsent_rsp(void *inMsg);
extern void mmi_frm_sms_move_sms_from_msgbox(U16 type, U16 index);
extern void mmi_frm_sms_background_pre_move_to_otherbox_req(void *dummy);
extern void mmi_frm_sms_get_vp_sc_req(U8 index);
extern void mmi_frm_sms_get_vp_sc_rsp(void *inMsg);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

extern void mmi_frm_sms_abort_sending_sms_req(mmi_frm_sms_abort_enum type);
extern void mmi_frm_sms_entry_write_msg_req(void *data);

extern void mmi_frm_sms_convert_status_report(
	MMI_FRM_SMS_STATUS_REPORT_IND_STRUCT *data, 
	mmi_frm_sms_status_report_ind_struct *entry);

#ifdef __MMI_DUAL_SIM_MASTER__
MMI_BOOL mmi_frm_sms_record_is_slave_sms(U16 box, U16 index);
U8 mmi_frm_sms_get_slave_sms_bitmap(U16 type, U16 index, U8 *l4_index);
U8 mmi_frm_sms_get_master_sms_bitmap(U16 type, U16 index, U8 *l4_index);
void mmi_frm_sms_remove_slave_sms_from_msgbox(U8 *data);
extern U16 mmi_frm_get_sms_action_size(void);
extern void mmi_frm_msg_entry_Select_option_screen(void);
extern void mmi_frm_msg_set_send_data(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData);
extern void mmi_msg_highlight_send_from_SIM1(void);
extern void mmi_msg_highlight_send_from_SIM2(void);
extern void mmi_frm_sms_handle_sms_refresh(U16 index);

extern void mmi_msg_highlight_save_from_SIM1(void);
extern void mmi_msg_highlight_save_from_SIM2(void);
extern void mmi_msg_entry_select_save_option_screen(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
extern void mmi_frm_card2_sms_sync_msg_ind(void *inMsg);
#endif

extern pBOOL ComparePhoneNum(PU8 src, PU8 dst);

#endif /* _MMI_SMSFUNC_H */ 

