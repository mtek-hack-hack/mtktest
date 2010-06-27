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
 *  JMMSMainMMS.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_main_mms_ui.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSSECONDARYMMI_H
#define __MMI_JMMSSECONDARYMMI_H

#include "JMMSStructs.h"

/* 
 * Define
 */

#define NUM_MSGS_IN_ONE_UNIT    5
#define JMMS_ASYNC_EVENT_TIME 100
#ifdef META_HANDLING_SUPPORT
#define MAX_BUFFER_SIZE_FOR_PROPERTY (500 + (MAX_NO_OF_META_TAG_SUPPORTED* (MAX_META_NAME_LENGTH + MAX_META_CONTENT_LENGTH)))
#else 
#define MAX_BUFFER_SIZE_FOR_PROPERTY 420
#endif 

/* 
 * Typedef 
 */

/* PMT VIKAS END 20060325 */
/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
extern void mmi_jmms_highlight_main_mms(void);

extern void mmi_jmms_entry_main_menu(void);
extern void mmi_jmms_exit_main_menu(void);

extern void mmi_jmms_hint_inbox(U16 index);
extern void mmi_jmms_hint_outbox(U16 index);
extern void mmi_jmms_hint_sent(U16 index);
extern void mmi_jmms_hint_drafts(U16 index);

extern void mmi_jmms_folder_list_highlight_hdlr(S32 index);

extern void mmi_jmms_highlight_write_message(void);
extern void mmi_jmms_highlight_messages_settings(void);
extern void mmi_jmms_highlight_templates(void);
extern void mmi_jmms_highlight_drafts(void);
extern void mmi_jmms_highlight_sent(void);
extern void mmi_jmms_highlight_outbox(void);
extern void mmi_jmms_highlight_inbox(void);

extern void mmi_jmms_entry_outbox(void);
extern void mmi_jmms_entry_sent(void);
extern void mmi_jmms_entry_drafts(void);
extern void mmi_jmms_entry_templates(void);
extern void mmi_jmms_entry_messages_settings(void);

extern void mmi_jmms_main_mms_init(void);

extern U16 mmi_jmms_get_msg_type(U8 index);
extern void mmi_jmms_back_from_msgs_list_screen(void);

/* void mmi_jmms_handle_end_on_folder_screen(void); */

extern void mmi_jmms_deinit(void);
extern void mmi_jmms_entry_get_msgs_progress_screen(void);

extern void mmi_jmms_entry_msgs_get_error_screen(void);

extern void mmi_jmms_entry_view_read_report(void);
extern void mmi_jmms_entry_view_delivery_report(void);
extern void mmi_jmms_entry_new_mms_sent_properties(void);

extern void mmi_jmms_entry_wap_not_ready(void);
extern void mmi_jmms_exit_wap_not_ready(void);
extern void mmi_jmms_wait_and_go_back(void);
extern void mmi_jmms_entry_java_mms_properties(void);

extern void mmi_jmms_free_notification_header(void);
extern void mmi_jmms_free_recieved_msg_header(void);
extern void mm_jmms_end_from_notification_properties(void);
extern void mm_jmms_back_from_noification_properties(void);
extern void mm_jmms_back_from_recive_msg_properties(void);
extern void mm_jmms_end_from_recive_msg_properties(void);
extern void mm_jmms_back_from_java_msg_properties(void);
extern void mm_jmms_end_from_java_msg_properties(void);
extern void mmi_jmms_free_delivery_report_header(void);
extern void mm_jmms_end_from_delivery_report_properties(void);
extern void mm_jmms_back_from_delivery_report_properties(void);
extern void mm_jmms_back_from_read_report_properties(void);
extern void mm_jmms_end_from_read_report_properties(void);
extern void mmi_jmms_free_report_report_header(void);
extern void mmi_jmms_free_new_mms_sent_header(void);
extern void mm_jmms_back_from_sent_msg_properties(void);
extern void mm_jmms_end_from_sent_msg_properties(void);

extern JC_RETCODE mmi_jmms_get_folder_msg_list(
                    mmi_jmms_folder_msgs_list_struct **msgs_list_p,
                    S8 *foldername_p,
                    U8 total_num_msgs);
extern void mmi_jmms_free_msgs_list(mmi_jmms_folder_msgs_list_struct **msgs_list);

extern JC_RETCODE mmi_jmms_send_get_msg_list_event(S8 *foldername_p, U8 total_num_msgs);
extern void mmi_jmms_show_mms_properties(U16 msg_type, S8 *folder_name_p);
extern void mmi_jmms_show_notification_properties(void);
extern void mmi_jmms_show_retrieved_mms_properties(void);
extern void mmi_jmms_create_new_mms_hint(
                mmi_jmms_folder_msgs_list_struct **node_p,
                JC_CHAR *to_p,
                JC_CHAR *cc_p,
                JC_CHAR *bcc_p);
extern JC_RETCODE mmi_jmms_create_notification_header(MESSAGE_NOTIFICATION *notf_header_p);
extern JC_RETCODE mmi_jmms_create_recieved_msg_header(MESSAGE_RETRIEVAL *recieve_header_p);
extern JC_RETCODE mmi_jmms_create_delivery_report_header(DELIVERY_REPORT *delivery_header_p);

extern JC_RETCODE mmi_jmms_create_read_report_header(READ_REPORT_RESPONSE *read_report_header_p);
extern JC_RETCODE mmi_jmms_create_new_mms_sent_header(MESSAGE_SEND *send_msg_header_p);
extern void mmi_jmms_error_handler(JC_RETCODE error_code);

extern void mmi_jmms_parse_continue_start_timer(MSG_HANDLE hMsg, error_callback err_cb, abort_callback abort_cb);
extern void mmi_jmms_parse_continue_stop_timer(void);
extern void mmi_jmms_parse_call_error_callback(JC_RETCODE ret_code);
extern void mmi_jmms_parse_continue_callback(void);
extern void mmi_jmms_send_continue_start_timer(MSG_HANDLE h_msg);
extern void mmi_jmms_send_continue_callback(void);
extern void mmi_jmms_clean_send_callback_list(void);
extern void mmi_jmms_add_send_callback_node(error_callback new_err_cb);
extern void mmi_jmms_decrement_send_callback_node(JC_RETCODE ret_code);

extern void mmi_jmms_save_continue_start_timer(MSG_HANDLE h_msg);
extern void mmi_jmms_save_continue_callback(void);
extern void mmi_jmms_clean_save_callback_list(void);
extern void mmi_jmms_add_save_callback_node(error_callback new_err_cb);
extern void mmi_jmms_decrement_save_callback_node(JC_RETCODE ret_code);

extern void mmi_jmms_entry_parse_result_fail(void);
extern void mmi_jmms_entry_parse_result_pass(void);
extern void mmi_jmms_entry_parse_result_pass_lsk(void);
extern U16 mmi_jmms_set_msg_type(U8, U16);
extern void mmi_jmms_reset_fw_flag_of_message(void);
extern MMI_BOOL mmi_jmms_is_message_to_fwd(void);
extern void mmi_jmms_set_fw_flag_of_message(void);
extern void mmi_jmms_common_exit_property_screen(void);
extern void mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
                PS8 dest_buffer_p,
                PS8 source_address_buffer_p,
                U32 max_limit_number,
                U32 max_limit_email);
 /* __USB_IN_NORMAL_MODE__ */
#ifdef META_HANDLING_SUPPORT
extern JC_RETCODE mmi_jmms_get_meta_info(mmi_jmms_context_struct *jmms_context_p);
extern void mmi_jmms_show_mms_properties_asyn_callback(JC_RETCODE ret_code);
#endif /* META_HANDLING_SUPPORT */ 
extern void mmi_jmms_pre_entry_properties_screen(void);
extern void mmi_jmms_deinit_mms_context(mmi_jmms_context_struct *jmms_context_p);
extern void mmi_jmms_parsing_progressing_screen(void);
extern void mmi_jmms_only_abort_parsing_progress(void);
extern void mmi_jmms_abort_parsing_progress(void);
extern void mmi_jmms_delete_mms_screens(void);
extern JC_RETCODE mmi_jmms_jdi_msg_deinit(MSG_HANDLE msg_handle);
extern JC_RETCODE mmi_jmms_jdi_msg_deinit_without_header(MSG_HANDLE msg_handle);
extern void mmi_jmms_save_size_of_mms(S32 *temp_size_p, S32 type);
#endif /* __MMI_JMMSSECONDARYMMI_H */ 

