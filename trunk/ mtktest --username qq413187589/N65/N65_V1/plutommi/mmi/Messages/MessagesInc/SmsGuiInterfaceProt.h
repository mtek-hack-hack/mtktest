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
 * SmsGuiInterfaceProt.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : SmsGuiInterfaceProt.h

   PURPOSE     : ???

   REMARKS     : nil

   AUTHOR      : Manu Vikram and Magesh k, Hiran

   DATE     : ???

**************************************************************/

#ifndef _PIXCOM_SMS_GUI_INTERFACE_PROT_H
#define _PIXCOM_SMS_GUI_INTERFACE_PROT_H

#include "l4dr.h"

#include  "MMIDataType.h"
#include "MessagesL4Def.h"
#include "MessagesMiscell.h"
#include "Gui_data_types.h"
#include "ems.h"

extern void InitMessagesApp(void);
extern void DeInitMessagesApp(void);
extern void HighlightVoiceMailHandler(void);
extern void HighlightCBHandler(void);
extern void HighlightWMessageHandler(void);
extern void HighlightInboxHandler(void);

#if defined(__MMI_MESSAGES_TEMPLATE__)
extern void HighlightTemplatesHandler(void);
#endif 

extern void HighlightOutboxHandler(void);
extern void HintInboxHandler(U16 index);
extern void HintOutboxHandler(U16 index);
extern void EntryScrMessagesMenuList(void);
extern void ExitScrnMessagesMenuList(void);

#ifdef __MMI_MESSAGES_MULTI_APP__
extern void EntrySMSMainMenuList(void);
extern void ExitScrSMSMainMenuList(void);
#endif /* __MMI_MESSAGES_MULTI_APP__ */ 
extern void mmi_msg_set_highlight_handler(void);
extern void mmi_msg_set_msg_menu_highlight_handler(void);

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
extern void mmi_msg_refresh_memory_status(void);
#endif 
extern void RefreshMessagesMenuList(void);

extern void GetHiliteIndex(S32 nIndex);
extern void GetMsgIndex(S32 nIndex);
extern void GetTemplateIndex(S32 nIndex);
extern void GetSendNumIndex(S32 nIndex);

extern int IsAPhoneNumber(S8 *number);

/********************************************************

               new functions

********************************************************/
extern void mmi_msg_get_mailbox_address_req(void);
extern void mmi_msg_get_mailbox_address_rsp_display(void *inMsg);
extern void mmi_msg_get_mailbox_address_rsp_dial(void *inMsg);
extern void mmi_msg_set_mailbox_address_req(U8 mailboxNum, U8 *number);
extern void mmi_msg_set_mailbox_address_rsp(void *inMsg);

extern void mmi_msg_save_sc_address_for_send(void);
extern void mmi_msg_save_sc_address(void);
extern void mmi_msg_save_profile_itmes(void);
extern void mmi_msg_save_common_settings(void);
extern void mmi_msg_save_mailbox_address(void);
extern void mmi_msg_erase_mailbox_address(void);
extern void mmi_msg_dial_mailbox_address(void);
extern void mmi_msg_highlight_dial_mailbox_address(void);

extern void mmi_msg_get_profile_num_req(void);
extern void mmi_msg_get_profile_highlight_index(S32 nIndex);
extern void mmi_msg_entry_msg_settings(void);
extern void mmi_msg_pre_entry_msg_settings(void);
extern void mmi_msg_entry_profile_edit(void);
extern void mmi_msg_exit_profile_edit(void);
extern void mmi_msg_entry_profile_settings(void);
extern void mmi_msg_entry_common_settings(void);

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
extern void mmi_msg_entry_memory_status(void);
#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_msg_entry_preferred_storage(void);
#endif
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
extern void mmi_msg_entry_bearer_settings(void);
#endif 
extern void mmi_msg_go_back_from_voice_mail_server(void);
extern void mmi_msg_end_key_from_voice_mail_server(void);
extern void mmi_msg_pre_entry_voice_mail_server(void);
extern void mmi_msg_entry_voice_mail_server(void);
extern pBOOL mmi_msg_voice_mail_server_get_item(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
extern S32 mmi_msg_voice_mail_server_get_hint(S32 item_index, UI_string_type *hint_array);
extern void mmi_msg_entry_voice_mail_server_option(void);
extern void mmi_msg_entry_voice_mail_server_edit(void);

extern void mmi_msg_highlight_msg_settings(void);
extern void mmi_msg_highlight_profile_settings(void);
extern void mmi_msg_highlight_common_settings(void);

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
extern void mmi_msg_highlight_memory_status(void);
#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_msg_highlight_preferred_storage(void);
extern void mmi_msg_hint_preferred_storage(U16 index);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
extern void mmi_msg_highlight_bearer_settings(void);
extern void mmi_msg_hint_bearer_settings(U16 index);
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 
extern void mmi_msg_highlight_voice_mail_server_edit(void);
extern void mmi_msg_highlight_voice_mail_server_erase(void);
extern void mmi_msg_highlight_voice_mail_server_dial(void);
extern U8 *ConvertL4NumberStructToDisplay(U8 *number, U8 length, U8 type);
extern void DialVoiceMail(void);
extern void FreeVoiceMailData(void);
extern void DeInitVoiceMailApp(void);

/*******************************************

         smsmomtguiinterface.c

********************************************/
extern void mmi_msg_set_msg_icon(U8 blink, U8 unblink);
extern void mmi_msg_set_msg_waiting_icon(U8 line, U8 type, U8 set);
extern void mmi_msg_set_funcptr(FuncPtr funcptr);
extern void mmi_msg_exec_funcptr(void);
extern void mmi_msg_highlight_generic(U16 lskstr, U16 lskimg, U16 rskstr, U16 rskimg, FuncPtr lskfunc, FuncPtr rskfunc);
extern void mmi_msg_exit_generic(void);
extern void mmi_msg_set_confirm_screen(U16 id, FuncPtr lskfunc, FuncPtr rskfunc);
extern void mmi_msg_entry_confirm_generic(void);
extern void mmi_msg_exit_confirm_generic(void);
extern void mmi_msg_set_processing_screen(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId);
extern void mmi_msg_set_processing_screen_ext(
            U16 captionStrId,
            U16 bodyStrId, 
            U16 animationImageId, 
            U16 rskStrId, 
            FuncPtr leftKeyFunc, 
            FuncPtr rightKeyFunc);
extern void mmi_msg_entry_processing_generic(void);
extern void mmi_msg_exit_processing_generic(void);
extern void mmi_msg_time_out_processing_generic(void);
extern void mmi_msg_set_popup_generic(U16 strID, U16 imgID, U8 toneID);
extern void mmi_msg_display_popup_generic(void);
extern void mmi_msg_entry_popup_generic(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId);
extern void mmi_msg_exit_popup_generic(void);
extern void mmi_msg_inline_generic_custom_function(void);
extern void mmi_msg_popup_timeout(void);
extern void mmi_msg_highlight_inline_generic_done(void);
extern void mmi_msg_entry_new_msg_popup(U8 type);
extern void mmi_msg_exit_new_msg_popup(void);

extern void mmi_msg_entry_sending(void);
extern void mmi_msg_set_msg_num_hint(U16 totalInbox, U16 totalOutbox, U16 totalDraftbox);

extern void mmi_msg_entry_write_msg(void);
extern void mmi_msg_entry_option_write(void);

extern void mmi_msg_phone_number_empty(void);
extern void mmi_msg_phone_number_not_empty(void);
extern void mmi_msg_entry_phone_number(void);
extern void mmi_msg_sc_number_not_empty(void);
extern void mmi_msg_entry_sc_number(void);

extern void mmi_msg_entry_send_option(void);
extern void mmi_msg_entry_option_inbox(void);
extern void mmi_msg_entry_option_outbox(void);
extern void mmi_msg_entry_option_default(void);
extern void mmi_msg_entry_send_option_outbox(void);
extern void mmi_msg_entry_forward_option_inbox(void);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
extern void mmi_msg_pre_entry_option_unsent(void);
extern void mmi_msg_entry_option_unsent(void);
extern void mmi_msg_highlight_unsent_opt_send(void);
extern void mmi_msg_highlight_unsent_opt_cancel_send(void);
extern void mmi_msg_highlight_unsent_opt_delete(void);
extern void mmi_msg_highlight_unsent_opt_delete_all(void);
extern void mmi_msg_highlight_unsent_opt_move_to_draft(void);
extern void mmi_msg_unsent_send(void);
extern void mmi_msg_unsent_cancel_send(void);
extern void mmi_msg_unsent_delete(void);
extern void mmi_msg_unsent_delete_all(void);
extern void mmi_msg_unsent_move_to_draft(void);
extern void mmi_msg_unsent_msg_move_to_draft(void);
extern void mmi_msg_update_unsent_icon(void);
extern U8 mmi_msg_get_unsent_operate_state(void);
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/

#ifdef __MMI_SEND_BY_SEARCH_NAME__
extern void mmi_msg_entry_send_only(void);
#endif 
#ifdef __MMI_MESSAGES_SEND_TO_MANY__
extern void mmi_msg_entry_send_to_many(void);
extern void mmi_msg_entry_send_to_many_list(void);
extern pBOOL mmi_msg_send_to_many_list_get_item(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
extern S32 mmi_msg_send_to_many_list_get_hint(S32 item_index, UI_string_type *hint_array);
extern void mmi_msg_entry_phone_number_from_send_to_many(void);
extern void mmi_msg_save_phone_number(void);
#endif /* __MMI_MESSAGES_SEND_TO_MANY__ */ 
extern void mmi_msg_get_msg_date_time(S8 *dateStr, S8 *timeStr, U8 scts[]);
extern U8 mmi_msg_handle_ready_ind_inbox(void *dummy);
extern void mmi_msg_pre_entry_inbox_list(void);
extern void mmi_msg_go_back_to_inbox_list(void);
extern void mmi_msg_entry_inbox_list(void);
extern pBOOL mmi_msg_inbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_msg_inbox_list_get_hint(S32 item_index, UI_string_type *hint_array);
extern U8 mmi_msg_handle_ready_ind_outbox(void *dummy);
extern void mmi_msg_pre_entry_outbox_list(void);
extern void mmi_msg_entry_outbox_list(void);
extern pBOOL mmi_msg_outbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

#ifdef __MMI_MESSAGES_DRAFT_BOX__
extern U8 mmi_msg_handle_ready_ind_draftbox(void *dummy);
extern void mmi_msg_pre_entry_draftbox_list(void);
extern void mmi_msg_entry_draftbox_list(void);
extern pBOOL mmi_msg_draftbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
extern void mmi_msg_entry_inbox_msg(void);
extern void mmi_msg_entry_outbox_msg(void);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern void mmi_msg_entry_archive_msg_inbox(void);
extern void mmi_msg_entry_archive_msg_outbox(void);
#endif
extern void mmi_msg_entry_default_msg(void);
extern void mmi_msg_msg_waiting_ind(U8 type);
extern U8 *mmi_msg_get_msg_waiting_msg(void);
extern void mmi_msg_entry_msg_waiting_ind(void);
extern void mmi_msg_deliver_report_ind(void);
extern void mmi_msg_go_back_from_deliver_report_ind(void);
extern void mmi_msg_end_key_from_deliver_report_ind(void);
extern void mmi_msg_get_deliver_report_status(U32 *status, U16 *imgID, U16 *strID);
extern U8 *mmi_msg_get_deliver_report_msg(void);
extern void mmi_msg_entry_deliver_report_ind(void);
extern void mmi_msg_mem_exceed_ind(void);
extern void mmi_msg_go_back_from_mem_exceed_ind(void);
extern void mmi_msg_end_key_from_mem_exceed_ind(void);
extern void mmi_msg_entry_mem_exceed_ind(void);
extern void mmi_msg_class0_msg_ind(void);
extern void mmi_msg_entry_class0_msg_ind(void);
extern EMSData *mmi_msg_get_class0_msg(void);
extern U8 *mmi_msg_get_class0_header(void);

extern void mmi_msg_new_msg_ind(U16 index);
extern U8 *mmi_msg_get_new_msg_ind_string(void);
extern void mmi_msg_go_back_from_new_msg_ind(void);
extern void mmi_msg_end_key_from_new_msg_ind(void);
extern void mmi_msg_entry_new_msg_ind(void);
extern void mmi_msg_stop_msg_sub_anm(void);
extern void mmi_msg_exit_inbox_list_dummy(void);

extern void mmi_msg_start_msg_sub_anm(void);
extern void mmi_msg_stop_msg_sub_anm(void);
extern void mmi_msg_callback_msg_sub_anm(void);

extern void mmi_msg_highlight_done(void);
extern void mmi_msg_highlight_send_only(void);

#ifdef __MMI_SEND_BY_SEARCH_NAME__
extern void mmi_msg_highlight_send_only_number(void);
extern void mmi_msg_highlight_send_only_name(void);
#endif /* __MMI_SEND_BY_SEARCH_NAME__ */ 
extern void mmi_msg_highlight_send_and_save(void);
extern void mmi_msg_highlight_save(void);
extern void mmi_msg_highlight_send_to_many(void);

#ifdef __MMI_MESSAGES_SEND_TO_MANY__
extern void mmi_msg_highlight_send_to_many_list(void);
extern void mmi_msg_highlight_send_to_many_now(void);
#endif /* __MMI_MESSAGES_SEND_TO_MANY__ */ 
#ifdef __MMI_MESSAGES_SEND_BY_GROUP__
extern void mmi_msg_highlight_send_by_group(void);
#endif 
extern void mmi_msg_highlight_reply(void);
extern void mmi_msg_highlight_send_outbox(void);

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_msg_pre_resend_msg_to_only_entry(void);
#endif 
extern void mmi_msg_highlight_edit(void);
extern void mmi_msg_highlight_forward(void);
extern void mmi_msg_highlight_delete(void);
extern void mmi_msg_highlight_delete_all_inbox(void);
extern void mmi_msg_highlight_delete_all_outbox(void);

#ifdef __MMI_MESSAGES_COPY__
extern void mmi_msg_highlight_copy(void);
extern void mmi_msg_highlight_copy_all_inbox(void);
extern void mmi_msg_highlight_copy_all_from_sim_inbox(void);
extern void mmi_msg_highlight_copy_all_from_phone_inbox(void);
extern void mmi_msg_highlight_copy_all_outbox(void);
extern void mmi_msg_highlight_copy_all_from_sim_outbox(void);
extern void mmi_msg_highlight_copy_all_from_phone_outbox(void);
extern void mmi_msg_entry_copy_all_inbox(void);
extern void mmi_msg_entry_copy_all_outbox(void);

extern void mmi_msg_highlight_move(void);
extern void mmi_msg_highlight_move_all_inbox(void);
extern void mmi_msg_highlight_move_all_from_sim_inbox(void);
extern void mmi_msg_highlight_move_all_from_phone_inbox(void);
extern void mmi_msg_highlight_move_all_outbox(void);
extern void mmi_msg_highlight_move_all_from_sim_outbox(void);
extern void mmi_msg_highlight_move_all_from_phone_outbox(void);
extern void mmi_msg_entry_move_all_inbox(void);
extern void mmi_msg_entry_move_all_outbox(void);
#endif /* __MMI_MESSAGES_COPY__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
#ifdef __MMI_MESSAGES_COPY__
extern void mmi_msg_highlight_advanced(void);
extern void mmi_msg_entry_advanced(void);
#endif /* __MMI_MESSAGES_COPY__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ /* __MMI_UNIFIED_MESSAGE_ */

extern void mmi_msg_save_use_number(void);
extern void mmi_msg_dial_use_number(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_msg_dial_use_number_dial(void);
extern void mmi_msg_dial_use_number_ext(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */
extern void mmi_msg_entry_use_number(void);
extern void mmi_msg_send_sms_use_number(void);
extern void mmi_msg_entry_use_number_option(void);
extern void mmi_msg_highlight_save_use_number(void);
extern void mmi_msg_highlight_dial_use_number(void);
extern void mmi_msg_highlight_use_number(void);
extern void mmi_msg_highlight_send_sms_use_number(void);

#if defined(__MMI_MESSAGES_USE_URL__)
extern void mmi_msg_highlight_use_url(void);
extern void mmi_msg_entry_use_url(void);
extern void mmi_msg_entry_use_url_option(void);
extern void HighlightUseURLOptConnectHandler(void);
extern void mmi_msg_highlight_use_url_add_to_bookmark(void);
extern void mmi_msg_entry_open_url(void);
extern void mmi_msg_entry_add_url(void);
extern void mmi_msg_end_key_from_use_url(void);
extern void mmi_msg_go_back_use_url_list(void);

extern U8 mmi_msg_get_url_list_from_msgtxt(S8 *pText, U16 txtLen);
extern void mmi_msg_free_url_list(void);
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 
extern U16 mmi_msg_skip_end_char(S8 *pOut, S8 *pIn, U16 length);

#ifdef __MMI_EMAIL__
extern void mmi_msg_highlight_use_email_address(void);
extern void mmi_msg_entry_email_address_list(void);
extern void mmi_msg_entry_use_email_address_option(void);
extern void mmi_msg_highlight_use_email_addr_opt_send(void);
extern void mmi_msg_highlight_use_email_addr_opt_save(void);
#endif /* __MMI_EMAIL__ */

#if defined(__MMI_MESSAGES_TEMPLATE__)
extern void mmi_msg_insert_template(void);
extern void mmi_msg_save_template(void);
extern void mmi_msg_erase_template(void);
extern void mmi_msg_pre_erase_template(void);
extern void mmi_msg_entry_template_list(void);
extern pBOOL mmi_msg_template_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_msg_entry_template_option(void);
extern void mmi_msg_entry_template_edit(void);
extern void mmi_msg_entry_template_write_msg(void);
extern void mmi_msg_entry_template_edit_option(void);
extern void mmi_msg_highlight_save_template(void);
extern void mmi_msg_highlight_erase_template(void);
extern void mmi_msg_highlight_edit_template(void);
extern void mmi_msg_highlight_template_write_msg(void);
#endif /* defined(__MMI_MESSAGES_TEMPLATE__) */ 

#ifdef __MMI_MESSAGES_DELETE_ALL_MENU__
extern void HighlightSMSDeleteHandler(void);
extern void mmi_msg_entry_delete(void);
extern void mmi_msg_highlight_delete_all(void);

#ifdef __MMI_MESSAGES_DRAFT_BOX__
extern void mmi_msg_highlight_delete_all_draftbox(void);
#endif 
#endif /* __MMI_MESSAGES_DELETE_ALL_MENU__ */ 

#ifdef __MMI_UNIFIED_COMPOSER__
/* type:mmi_uc_done_type_enum, caller_msg_type:mmi_uc_msg_type_enum */
extern void mmi_msg_entry_uc(U8* ascii_num, U16 type, U16 msg_index, U16 caller_msg_type);
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __MMI_VOIP__
extern void mmi_msg_dial_use_voip_number(void);
#endif

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern void mmi_msg_entry_archive_list_inbox_opt(void);
extern void mmi_msg_entry_archive_list_outbox_opt(void);
#endif
extern void mmi_msg_entry_inbox_list_opt(void);
extern void mmi_msg_entry_outbox_list_opt(void);
extern void mmi_msg_entry_default_list_opt(void);
extern void mmi_msg_highlight_view(void);
extern void mmi_msg_entry_view_msg(void);

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_msg_entry_sim_list_opt(void);
#endif

#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_msg_entry_option_simbox(void);
extern void mmi_msg_entry_simbox_msg(void);
extern void mmi_msg_highlight_copy_all_simbox(void);
extern void mmi_msg_highlight_move_all_simbox(void);
extern void mmi_msg_highlight_delete_all_simbox(void);
extern void mmi_msg_entry_new_sim_msg_ind(void);

#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


extern void mmi_msg_entry_set_voicemail_number_confirm(U8 mailboxIndex, U8 mailboxNameDcs);
extern void mmi_msg_pre_entry_edit_voicemail_num_from_idle(void);

#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_msg_set_msg_type_as_slave(void);
extern void mmi_msg_entry_master_send_option(void);
extern void mmi_msg_entry_slave_send_option(void);
#endif

#endif /* _PIXCOM_SMS_GUI_INTERFACE_PROT_H */ 

