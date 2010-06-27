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
 *  JMMSUCInterfaceProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * MMSTemplates.c
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_UC_JMMS_XML_H
#define __MMI_UC_JMMS_XML_H

#if defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__)

#include "mmsadp.h"

#define MMI_JMMS_UC_FOLDER_PATH "@mms\\temp\\xml\\"
#define MMI_JMMS_UC_GET_CONTENT_XML_FILE_PATH "@mms\\temp\\xml\\temp.xml"
#define MMI_JMMS_UC_AUTO_SIGNATURE_FILE_PATH TEMP_ATTACH_FOLDER_PATH##"\\auto.txt"
typedef void (*post_parse_mms_callback) (JC_RETCODE);

typedef enum
{
    JMMS_UC_FOREGROUND_SAVING = 0,
    JMMS_UC_BACKGROUND_SAVING
} mmi_jmms_uc_create_req_state_enum;

extern void mmi_jmms_uc_handle_start_rsp(mmi_jmms_uc_start_comm_struct *);
extern void mmi_jmms_uc_handle_progress_ind(mmi_jmms_comm_progress_struct *);
extern void mmi_jmms_uc_handle_sending_complete_rsp(mmi_jmms_uc_sending_complete_struct *);
extern void mmi_jmms_uc_handle_error_ind(mmi_jmms_uc_error_struct *);
extern void mmi_jmms_uc_handle_stop_ind(mmi_jmms_communication_stop_struct *);
extern mmi_jmms_communication_state_node_struct *mmi_jmms_uc_get_communication_handle(JC_UINT32 msgid);
extern void mmi_jmms_uc_send_mode_start_uc_req(JC_UINT32 msg_id, mma_app_mode_enum mode);
extern void mmi_jmms_uc_wap_mma_save_rsp(mma_result_enum result, kal_uint32 msg_id);
extern void mmi_jmms_uc_wap_mma_create_mms_rsp(mma_result_enum result, U32 msg_id);
extern void mmi_jmms_uc_wap_mma_send_progress_ind(U32 msgid, U32 percentage_of_progress, U8 retry);
extern void mmi_jmms_uc_wap_mma_send_rsp(U32 msg_id, mma_result_enum result, JC_CHAR *response_text_p);
extern void mmi_jmms_uc_sending_complete_rsp_for_cancel_send(U32 msg_id, JC_BOOLEAN result, JC_CHAR *response_text_p);

#ifdef __USB_IN_NORMAL_MODE__
extern void mmi_jmms_uc_cancel_mms_sending_for_usb(void);
#endif /* __USB_IN_NORMAL_MODE__ */

extern void mmi_jmms_uc_send_progress_ind(U32 msgid, U32 percentage_of_progress, U8 retry);
extern void mmi_jmms_uc_sending_complete(U32 msg_id, mma_result_enum result, JC_CHAR *response_text_p);
extern JC_RETCODE mmi_jmms_uc_send_mms(MSG_HANDLE msg_handle, JC_UINT32 msg_id);
extern void mmi_jmms_uc_cancel_mms_sending(JC_UINT32 msg_id);
extern void mmi_jmms_uc_remove_send_node(JC_UINT32 msgid);
extern void mmi_jmms_uc_send_stop_ind(kal_uint8 result, U32 msg_id);
extern void mmi_jmms_uc_add_send_node(MSG_HANDLE msg_handle, JC_UINT32 uimsdID);
extern JC_UINT32 mmi_jmms_uc_get_msgid(mmi_jmms_communication_state_node_struct *communication_handle_p);
extern JC_RETCODE mmi_jmms_uc_make_address_list(S8 *address_str_p, mmi_uc_address_group_type_enum type);
extern S32 mmi_jmms_uc_create_mms_xml_description_file(U8 *file_path);
typedef void (*post_parse_mms_callback) (JC_RETCODE);
extern void mmi_jmms_uc_fill_mms_sending_settings(void);
extern void mmi_jmms_uc_add_subject_string(JC_CHAR *subject_string_p, S32 length);
extern void mmi_jmms_uc_create_text_object_list(
                mmi_uc_text_object_info_struct *text_info_object_p,
                U32 jmms_media_id,
                U8 page_index);
extern JC_RETCODE mmi_jmms_uc_create_object_list(void);
extern void mmi_jmms_uc_create_media_object_list(
                mmi_uc_object_info_struct *media_info_object_p,
                U32 jmms_media_id,
                U8 page_index);
extern void mmi_jmms_uc_parsed_end_callback(JC_RETCODE ret_code);
extern void mmi_jmms_uc_wap_send_failure_msg_rsp(JC_UINT32 msg_id);

extern void mmi_jmms_uc_create_msg_rsp(JC_RETCODE ret_code, U32 msg_id);

extern void mmi_jmms_uc_send_wap_mma_get_setting_rsp(wap_mma_get_setting_req_struct *);
extern void mmi_jmms_uc_wap_mma_create_req_handler(wap_mma_create_req_struct *local_data);
extern void mmi_jmms_uc_wap_mma_delete_req_handler(wap_mma_delete_req_struct *local_data);
extern void mmi_jmms_uc_wap_mma_preview_req_handler(wap_mma_preview_req_struct *local_data);
extern void mmi_jmms_uc_send_wap_mma_get_setting_rsp(wap_mma_get_setting_req_struct *local_data);
extern void mmi_jmms_uc_wap_mma_get_content_req_handler(wap_mma_get_content_req_struct *local_data);
extern void mmi_jmms_uc_wap_mma_send_req_handler(wap_mma_send_req_struct *);
extern void mmi_jmms_uc_wap_mma_cancel_send_req_handler(wap_mma_cancel_send_req_struct *local_data);
extern void mmi_jmms_uc_wap_mma_save_req_handler(wap_mma_save_req_struct *local_data);
extern void mmi_jmms_uc_edit_message_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_uc_send_message_async_callback(JC_RETCODE eRet);
extern void mmi_jmms_uc_distroy_xml_struct(void);
extern void mmi_jmms_uc_send_wap_mma_get_content_rsp(mma_result_enum result);
extern void mmi_jmms_uc_delete_screen_from_history_after_rsp(void);
extern void mmi_jmms_uc_create_message_handle_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_uc_compose_edit_send_request(JC_UINT32 msg_index, S8 *folder_name_p);
extern void mmi_jmms_uc_compose_edit_request(JC_UINT32 msg_index, S8 *folder_name_p);
extern JC_RETCODE mmi_jmms_uc_create_msg_req(void *local_para, mmi_jmms_uc_xml_decoder_result_hdlr result_hdlr);
extern void mmi_jmms_uc_add_preview_rsp_screen(void);
extern void mmi_uc_jmms_edit_message_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_uc_get_content_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_uc_create_parsed_mms_data_common_fun(
                JC_UINT32 ui_msg_id,
                JC_INT32 mode,
                post_parse_mms_callback mmi_jmms_uc_parsed_end_callback);
extern void mmi_jmms_uc_wap_mma_preview_rsp(mma_result_enum result);
extern mma_result_enum mmi_jmms_uc_provide_mma_error_code(JC_RETCODE ret_code);
extern void mmi_jmms_uc_compose_edit_fw_request(JC_UINT32 msg_index, S8 *folder_name_p);
extern void mmi_jmms_uc_delete_message(kal_uint32 req_id, kal_uint16 msg_box_type, JC_UINT32 msg_id);
extern void mmi_jmms_uc_preview_mms_from_msg_id(U32 msg_id);
extern void mmi_jmms_uc_cancel_mms_sending_from_id(U32 req_id, U32 msg_id);
extern void mmi_jmms_uc_start_save_mms(kal_uint32 req_id, kal_uint16 msg_box_type, JC_UINT32 msg_id);
extern kal_bool mmi_jmms_uc_get_mma_content_rsp(
                    JC_CHAR *src_fname_p,
                    kal_uint8 *buffer_p,
                    U32 buffer_index,
                    U32 xml_size);
extern void mmi_jmms_uc_wap_mma_cancel_send_rsp(kal_uint8 result, kal_uint32 msg_id);
extern void mmi_jmms_uc_reply_message(JC_BOOLEAN reply_status, JC_UINT32 msg_index);
extern void mmi_jmms_uc_wap_send_wap_mma_delete_rsp(kal_uint32 req_id, mma_result_enum result, kal_uint32 msg_id);
extern void mmi_jmms_uc_edit_content_restricted_mode_query(void);
extern void mmi_jmms_delete_uc_compose_files(void);
extern JC_CHAR *mmi_jmms_uc_create_auto_signature_file(void);
extern void *mmi_jmms_alloc_buffer(U32 buffer_size);
extern void mmi_jmms_free_buffer(void *buffer_p);

#endif /* defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__) */ 
#endif /* __MMI_UC_JMMS_XML_H */ 

