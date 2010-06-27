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
 *  JMMSStoreHandling.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_store_handling.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSSTOREHANDLING_H
#define __MMI_JMMSSTOREHANDLING_H

#include "MMI_features.h"
#include "MMIDataType.h"
// #include "MessagingDataTypes.h"

#include "ddl.h"
#include "jcal.h"
#include "jcalnet.h"
#include "jdi_wspdatatype.h"
#include "MessagingDataTypes.h"
#include "JMMSStructs.h"
#include "USBDeviceGprot.h"
/* 
 * Define
 */
#define MMI_JMMS_INBOX "Inbox"
#define MMI_JMMS_OUTBOX "Outbox"
#define MMI_JMMS_SENT "Sent"
#define MMI_JMMS_DRAFTS "Drafts"
#define MMI_JMMS_TEMPLATES "Templates"
#define MMI_JMMS_NO_OF_SYSTEM_FOLDERS 5
#define MMI_JMMS_MAX_JAVA_MSG_ID 10000
#define MMI_JMMS_MAX_NORMAL_MSG_ID  0x00FFFFFF
#define MAX_FILE_NAME_LENGTH 256

/* 
 * Typedef 
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
extern JC_RETCODE mmi_jmms_get_folder_list(FOLDER_INFO **folder_list_p);

extern JC_RETCODE mmi_jmms_get_messages_list(
                    S8 *folder_name_p,
                    MESSAGE_LIST **msg_list_p,
                    RETRIEVE_FILTERS *retrieve_filters_p);

extern JC_RETCODE mmi_mms_get_number_of_messages(S8 *folder_name_p, U8 *total_num_messages_p);
extern void mmi_jmms_init_store(void);
extern void mmi_jmms_create_templates_in_store(void);
extern void mmi_jmms_de_init_store(void);
extern JC_RETCODE mmi_jmms_restore_folder_info(void);
extern JC_RETCODE mmi_jmms_delete_message(S8 *folder_name_p, JC_UINT32 ui_msg_index);
extern void mmi_jmms_delete_message_as_per_id(U32 msgId);

extern JC_RETCODE mmi_jmms_save_message_buffer_in_Store(
                    S8 *folder_name_p,
                    JC_UINT32 *ui_msg_index_p,
                    MESSAGE_HEADERS *msg_headers_p,
                    CONTENT_DATA *content_p,
                    JC_UINT32 *extra_bytes_p);
extern JC_RETCODE mmi_jmms_get_message(S8 *folder_name_p, CONTENT_DATA *content_p, JC_INT32 index);

extern JC_RETCODE mmi_jmms_store_move_message(
                    S8 *src_folder_name_p,
                    S8 *dest_folder_name_p,
                    JC_UINT32 *ui_msg_index_p);

extern JC_RETCODE mmi_jmms_store_update_message(
                    S8 *folder_name_p,
                    JC_UINT32 *ui_msg_index_p,
                    MESSAGE_HEADERS *msg_headers_p,
                    CONTENT_DATA *content_p,
                    JC_UINT32 extra_bytes);

extern JC_RETCODE mmi_jmms_delete_all_message(S8 *folder_name_p);

#if (defined (__MMI_MMS_DELETE_ALL_DELIVERY_REPORT__) || defined(__MMI_MMS_DELETE_ALL_READ_REPORT__))
extern JC_RETCODE mmi_jmms_delete_all_message_by_type(S8 *folder_name_p, EMsgType msg_type);
#endif 

extern JC_UINT32 mmi_jmms_get_message_id(S8 *folder_name_p, JC_UINT32 ui_msg_index);
extern void mmi_jmms_free_messages_list(void);

//PMT VIKAS END 20060325
//PMT VIKAS START 20060401
extern JC_RETCODE mmi_jmms_get_number_of_unread_messages_in_inbox(U8 *total_num_unread_messages_p);
extern void mmi_jmms_get_free_size_for_mms(U64 *free_size_p);

/* PMT VIKAS END 20060401 */

extern JC_RETCODE mmi_jmms_get_total_number_of_messages(U8 *total_num_messages_p);
extern JC_RETCODE mmi_jmms_set_active_folder(S8 *folder_name_p);

extern JC_RETCODE mmi_jmms_store_update_message_extrabyte(
                    S8 *folder_name_p,
                    JC_UINT32 ui_msg_index,
                    JC_UINT32 extra_bytes);

extern void mmi_jmms_delete_progresing_screen(U16 title_str_id, U16 image_id);

extern JC_UINT32 mmi_jmms_get_message_folder_type_from_id(JC_UINT32 msgid);
extern JC_UINT32 mmi_jmms_get_message_folder_type_for_extra_bytes(JC_INT8 *folder_name_p);
extern JC_RETCODE mmi_jmms_get_message_index(STORE_HANDLE hStore, JC_UINT32 msgid, JC_UINT32 *msg_index_p);
extern JC_UINT32 mmi_jmms_get_message_extra_bytes(S8 *pFolderName, JC_UINT32 uiMsgIndex);

extern JC_RETCODE mmi_jmms_recreate_sys_folders(void);
extern S32 mmi_jmms_sys_folders_exist(void);

extern JC_RETCODE mmi_jmms_save_message_buffer_in_Store_ext(
                    S8 *folder_name_p,
                    JC_UINT32 *msg_index_p,
                    MESSAGE_HEADERS *msg_headers_p,
                    CONTENT_DATA *content_p,
                    JC_UINT32 *extra_bytes_p,
                    S8 show_pop_up);

extern JC_UINT32 mmi_jmms_get_valid_msg_id(S8 *folder_name_p);
extern JC_RETCODE mmi_jmms_check_folder_attribute(JC_CHAR *folderpath, JC_INT8 reset_flag, JC_INT32 attribute);
extern JC_RETCODE mmi_jmms_reset_attribute(JC_CHAR *folderpath, JC_INT32 attribute);

extern JC_RETCODE mmi_jmms_get_file_path(JC_CHAR *folder_path, JC_CHAR *filename, JC_CHAR **path);

extern JC_RETCODE mmi_jmms_set_attribute(JC_CHAR *folderpath, JC_INT32 attribute);

extern JC_RETCODE mmi_jmms_set_folder_attribute(
                    JC_CHAR *folderpath,
                    JC_INT8 set_flag,
                    JC_INT32 attribute,
                    JC_CHAR *filename_buffer);
extern U32 get_current_utc_time(void);
extern JC_RETCODE mmi_jmms_read_callback(
                    void *pStream,
                    JC_INT32 ui_offset,
                    JC_UINT32 ui_size,
                    JC_UINT8 *buffer_p,
                    JC_UINT32 *size_read_p);
extern JC_RETCODE mmi_jmms_write_callback(void *stream_p, JC_UINT8 *buffer_p, JC_UINT32 uiSize);
extern JC_RETCODE mmi_jmms_save_mms(
                    S8 *folder_name_p,
                    MSG_HANDLE h_msg_handle,
                    MMI_BOOL is_store_update,
                    JC_UINT32 msg_index,
                    error_callback err_cb);

extern void mmi_jmms_save_mms_async_callback(JC_RETCODE ret_code);
extern JC_RETCODE mmi_jmms_send_and_store_mms(
                    S8 *folder_name_p,
                    MSG_HANDLE h_msg_handle,
                    mmi_jmms_communication_state_node_struct *comm_node_p);
#ifdef __USB_IN_NORMAL_MODE__
extern void mmi_jmms_cached_pending_mms(void);
extern U8 mmi_jmms_check_usb_mode(void);
extern void mmi_jmms_handle_usb_exit_req(void);
extern void mmi_jmms_handle_usb_enter_req(void);
extern void mmi_jmms_usb_create_mms_system_folder(void);
extern void mmi_jmms_usb_delete_mms_system_folder(void);

#endif /* __USB_IN_NORMAL_MODE__ */ 
#ifdef __UNIFIED_COMPOSER_SUPPORT__
extern void mmi_jmms_uc_wap_send_failure_msg_rsp(JC_UINT32 msg_id);
#endif 
extern void mmi_jmms_set_msg_as_read(U8 index);
extern void mmi_jmms_set_msg_as_unread(U8 index);
extern void mmi_jmms_delete_msg_status(U8 index);
extern void mmi_jmms_delete_all_msgs_status(void);

extern void mmi_jmms_delete_all_message_inbox(void);
extern void mmi_jmms_sd_plug_out_hdlr(void);
extern JC_UINT32 mmi_jmms_get_free_space(void);
//extern void mmi_jmms_delete_mms_screens(void);
//extern JC_BOOLEAN mmi_jmms_is_call_active(void);
#endif /* __MMI_JMMSSTOREHANDLING_H */ 

