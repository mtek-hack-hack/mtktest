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
 * JsrProts.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _JSR_PROTS_H
#define _JSR_PROTS_H

#include "wap_ps_struct.h"

/* if some header should be include before this one */
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/* JSR module prototypes */
extern void mmi_jsr_clean_context(void);

extern void mmi_jsr_read_folder_status_req_hldr(void *msg);
extern void mmi_jsr_read_folder_status_output_req_hldr(
                mmi_jsr_result_enum result,
                mmi_jsr_folder_info_struct *folder_info_p);

extern void mmi_jsr_upload_msg_req_hldr(void *msg);
extern void mmi_jsr_upload_msg_output_req_hldr(mmi_jsr_result_enum result, U32 msg_id);

extern void mmi_jsr_delete_msg_req_hldr(void *msg);
extern void mmi_jsr_delete_msg_output_req_hldr(mmi_jsr_result_enum result);

extern void mmi_jsr_send_appmms_req_hldr(void *msg, int mod_src, void *peer_buf);
extern void mmi_jsr_send_post_appmms_msg_part_ind(mmi_jsr_result_enum result);
extern void mmi_jsr_send_post_appmms_msg_part_rsp(void *msg);
extern void mmi_jsr_send_appmms_rsp(mmi_jsr_result_enum result);

extern MMI_BOOL mmi_jsr_check_recv_mms_for_java(S8 *content_type_p);
extern MMI_BOOL mmi_jsr_add_recv_java_mms_content(U32 msg_id, S8 *content_type_p);

extern void mmi_jsr_send_appmms_new_mms_ind(char *app_id, U32 length);
extern MMI_BOOL mmi_jsr_insert_msgId_to_appId_list(U32 msg_id, char *app_id, BOOL is_checked);

extern U32 mmi_jsr_generate_recv_msg_rsp(
            S8 *app_id,
            wap_mmc_recv_appmms_rsp_struct *resp,
            mmi_jsr_result_enum *result,
            S8 **buffer,
            U16 *buffer_size);
extern void mmi_jsr_receive_appmms_req_hldr(void *msg);
extern void mmi_jsr_receive_appmms_post_req_hldr(void *resp, S8 *buffer, U16 buffer_size);
extern void mmi_jsr_receive_appmms_rsp(wap_mmc_recv_appmms_rsp_struct *response_struct, S8 *buffer, U16 buffer_size);
extern void mmi_jsr_read_appmms_msg_part_req(void);
extern void mmi_jsr_read_appmms_msg_part_rsp(wap_mmc_read_appmms_msg_part_rsp_struct *response);

extern void mmi_jsr_cfg_appmms_appid_req(void *msg);
extern void mmi_jsr_cfg_appmms_appid_rsp(mmi_jsr_result_enum result);
extern mmi_jsr_result_enum mmi_jsr_cfg_app_id(U8 *app_id, U8 app_id_length, U8 is_remove);

extern void mmi_jsr_check_appmms_coming_req(void *msg);
extern void mmi_jsr_check_appmms_coming_rsp(MMI_BOOL result);
extern MMI_BOOL mmi_jsr_check_appid_msgs(U8 *app_id, U8 app_id_length, U8 is_new);

extern void mmi_jsr_abort_appmms_req(void *msg);
extern void mmi_jsr_abort_appmms_rsp(mmi_jsr_result_enum result);

extern void mmi_jsr_get_mms_profile_req(void *msg);
extern void mmi_jsr_get_mms_profile_rsp(U8 result, U8 *value, U8 value_length);
extern void mmi_jsr_get_mms_user_agent_rsp(void);

extern MMI_BOOL mmi_jsr_is_java_msg(U32 msg_id);

#endif /* _JSR_PROTS_H */ 

