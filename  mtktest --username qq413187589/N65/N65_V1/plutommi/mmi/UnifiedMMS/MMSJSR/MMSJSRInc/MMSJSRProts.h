/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * MMSJsrProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file intends for handling the JSR messages.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _JSR_PROTS_H
#define _JSR_PROTS_H
#ifdef __MMI_MMS_2__
/* if some header should be include before this one */
/***************************************************************************** 
* Define
*****************************************************************************/
/*
 * MMA and JSR interfaces and call back
 * MSG_ID_WAP_MMA_GET_MSG_LSIT_REQ     -> mmi_jsr_get_message_list_rsp
 * MSG_ID_WAP_MMA_GET_MSG_INFO_REQ     -> mmi_jsr_get_msg_info_rsp
 * PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ   -> mmi_jsr_get_msg_num_rsp
 * MSG_ID_WAP_MMA_CREATE_REQ        -> mmi_jsr_create_message_rsp
 * MSG_ID_MMI_UM_REFRESH_IND
 * MSG_ID_WAP_MMA_DELETE_REQ        -> mmi_jsr_delete_mms_rsp
 * MSG_ID_WAP_MMA_CANCEL_SEND_REQ      -> mmi_jsr_cancel_send_mms_rsp   
 * MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ -> mmi_jsr_get_active_mms_attachment_req
 * MSG_ID_WAP_MMA_SEND_REQ          -> mmi_jsr_send_msg_rsp
 * MSG_ID_WAP_MMA_GET_CONTENT_REQ      -> mmi_jsr_get_msg_content_rsp
 */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#include "wap_ps_struct.h"

extern void mmi_umms_reset_mms_downloading_busy(void);  /* MMS App functions */
extern void mmi_umms_set_mms_downloading_busy(void);    /* MMS App functions */

extern void mmi_umms_set_mms_sending_busy(void);
extern void mmi_umms_reset_mms_sending_busy(void);

extern void mmi_umms_update_status_icon_indicator(void);

extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);

extern void JsrCleanContext(void);
extern KAL_ADM_ID umms_get_kal_mem_id(void);

/* read folder */
extern void mmi_jsr_read_folder_status_req_hldr(void *msg);
extern void mmi_jsr_read_folder_status_output_req_hldr(JsrResult result, JsrFolderInfo *folderInfo);
extern void mmi_jsr_fill_folder_info_output_req(void);

/* upload folder */
extern void mmi_jsr_upload_msg_req_hldr(void *msg);
extern void mmi_jsr_upload_msg_output_req_hldr(JsrResult result, U32 msgId);

/* delete folder */
extern void mmi_jsr_delete_msg_req_hldr(void *msg);
extern void mmi_jsr_delete_msg_output_req_hldr(JsrResult result);

/* send message */
extern void mmi_jsr_send_appmms_req_hldr(void *msg, int not_used, void *peerBuf);
extern void mmi_jsr_send_post_appmms_msg_part_ind(JsrResult result);
extern void mmi_jsr_send_post_appmms_msg_part_rsp(void *msg);
extern void mmi_jsr_send_appmms_rsp(JsrResult result);

/* receive message */
extern void mmi_jsr_receive_appmms_req_hldr(void *msg);
extern void mmi_jsr_receive_appmms_post_req_hldr(void *resp, S8 *buffer, U32 buffer_size);
extern void mmi_jsr_receive_appmms_rsp(wap_mmc_recv_appmms_rsp_struct *response_struct, S8 *buffer, U32 buffer_size);
extern void mmi_jsr_read_appmms_msg_part_req(void *msg);
extern void mmi_jsr_read_appmms_msg_part_rsp(wap_mmc_read_appmms_msg_part_rsp_struct *response);

/* abort reqest */
extern void mmi_jsr_abort_appmms_req(void *msg);
extern void mmi_jsr_abort_appmms_rsp(JsrResult result);

/* profile req */
extern void mmi_jsr_get_mms_profile_req(void *msg);
extern void mmi_jsr_get_mms_profile_rsp(U8 result, U8 *value, U8 value_length);

/* configure app id */
extern void mmi_jsr_cfg_appmms_appid_req(void *msg);
extern void mmi_jsr_cfg_appmms_appid_rsp(JsrResult result);
extern JsrResult mmi_jsr_cfg_app_id(U8 *app_id, U8 app_id_length, U8 is_remove);

/* new message ind */
extern void mmi_jsr_send_appmms_new_mms_ind(U8 *appId, U32 length);

/* check app di message */
extern void mmi_jsr_check_appmms_coming_req(void *msg);
extern void mmi_jsr_check_appmms_coming_rsp(MMI_BOOL result);
extern MMI_BOOL mmi_jsr_check_appid_msgs(U8 *app_id, U8 app_id_length, U8 is_new);

/* add JAVA mms */
extern MMI_BOOL mmi_jsr_add_recv_java_mms_content(U32 msgId, U8 *contentType);
extern MMI_BOOL mmi_jsr_insert_msgId_to_appId_list(U32 msgId, U8 *appId, BOOL is_checked);

extern void mmi_jsr_get_active_mms_attachment_req(void *in_msg);

/* generic functions */

extern void mmi_jsr_get_msg_list_req(void);
extern void mmi_jsr_get_message_list_rsp(void *msgRsp);

extern void mmi_jsr_get_msg_info_req(void);
extern void mmi_jsr_get_msg_info_rsp(void *msgRsp);

extern void mmi_jsr_send_msg_req(U16 msg_id);
extern void mmi_jsr_send_msg_rsp(void *inMsg);

extern void mmi_jsr_create_mms_msg_req(kal_wchar *fname);
extern void mmi_jsr_create_mms_msg_rsp(void *inMsg);

extern void mmi_jsr_um_refresh_ind(U32 folderID);

extern void mmi_jsr_delete_msg_req(U32 folderId, U32 msgId);
extern void mmi_jsr_delete_msg_rsp(void *delmsg);

extern void mmi_jsr_get_msg_num_req(void);
extern void mmi_jsr_get_msg_num_rsp(void *msgRsp);

extern void mmi_jsr_cancel_send_msg_req(void);
extern void mmi_jsr_cancel_send_msg_rsp(void *msgRsp);

extern void mmi_jsr_post_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);

extern void mmi_jsr_init_appid_msgid_list(void);
extern MMI_BOOL mmi_jsr_check_recv_mms_for_java(S8 *contentType);
extern MMI_BOOL mmi_jsr_is_java_msg(U32 msgId);
extern void mmi_jsr_read_object_list_from_file(void);
extern MMI_BOOL mmi_jsr_remove_msgId_from_appId_list(U32 msgId);
extern S32 mmi_jsr_convert_phsuite_folder_to_jsr_folder(S32 folder);

/* testing purpose */
extern void mmi_jsr_testing(void);
extern void mmi_umms_init_jsr_folder(void);
extern void mmi_jsr_terminate_req_handler(void);
extern void mmi_jsr_file_copy_callback(void *msg);
extern MMI_BOOL mmi_jsr_get_file_name(S8 **const file_path, S8 const *const file_name);

#endif /* __MMI_MMS_2__ */
#endif /* _JSR_PROTS_H */ 

