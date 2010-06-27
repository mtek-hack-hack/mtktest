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
 * JMMSUMHandle.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _JMMSUMHANDLE_H
#define _JMMSUMHANDLE_H

/* vikas start */
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageGProt.h"
#include "JMMSStructs.h"

extern void mmi_um_jataayu_entry_message_mms(UmMsgBoxType msg_box_type, kal_uint16 msg_index);
extern void mmi_um_jataayu_get_message_list(UmMsgBoxType msg_box_type, kal_uint16 msg_index);
extern void mmi_um_jmms_get_fill_list(
                mmi_um_get_list_rsp_struct *mms_list_rsp_p,
                mmi_um_get_list_req_struct *msg_list_req_p);
extern void mmi_um_jmms_get_fill_list_info(
                mmi_um_get_msg_info_rsp_struct *mms_info_rsp_p,
                mmi_um_get_msg_info_req_struct *msg_info_req_p);

extern void mmi_um_jmms_free_msgs_list(void);
extern void mmi_um_jmms_add_mms_sub_for_list_info(
                mmi_um_msg_info_struct **mms_info_rsp_p,
                JC_CHAR *subject_p,
                S32 msg_counter);
extern void mmi_um_jmms_create_new_mms_hint_for_sent(
                mmi_um_msg_info_struct **mms_info_rsp_p,
                JC_CHAR *to_p,
                JC_CHAR *cc_p,
                JC_CHAR *bcc_p,
                S32 msg_counter);
extern void mmi_um_jmms_add_mms_address_for_list_info(
                mmi_um_msg_info_struct **mms_info_p,
                JC_CHAR *from_p,
                S32 msg_counter);
extern void mmi_um_jmms_set_folder_list_callback_function(void (*f) (void));
extern void mmi_um_jmms_dummy_folder_list_callback(void);

extern void mmi_um_jmms_get_push_message_count_req(void);
extern void mmi_um_jmms_get_mms_message_list_req(mmi_um_get_list_req_struct *msg_list_req_p);
extern void mmi_um_jmms_get_mms_message_info_req(mmi_um_get_msg_info_req_struct *msg_info_req_p);
extern void mmi_um_jmms_delete_all_mms_message_req(mmi_um_delete_folder_req_struct *msg_delete_all_req_p);
extern void mmi_um_jmms_delete_all(void);
extern void mmi_um_jmms_ready_ind(void);
extern void mmi_um_delete_highlight_folder(um_msg_delete_folder_enum folder);
extern void mmi_um_jmms_refresh_ind(void);
extern void mmi_um_jmms_highlight_mms_message_ind(void);
extern void mmi_um_jmms_pre_entry_inbox(void);
extern void mmi_um_jmms_pre_entry_outbox(void);
extern void mmi_um_jmms_pre_entry_sent(void);
extern void mmi_um_jmms_pre_entry_draft(void);
extern void mmi_um_jmms_at_delete_pre_set(void);
extern void mmi_jmms_free_attacment_pending_status_list(void);
extern void mmi_um_jmms_add_new_node_attachment_pending_list(
                mmi_jmms_um_jmms_attachment_present_list_struct *temp_pending_list_p);
extern void mmi_um_jmms_parse_mms_for_attachment(void);
extern void mmi_um_jmms_get_message_list_rsp(void);
extern void mmi_um_update_status_attachment(U16 msg_index, mmi_jmms_mms_attachment_status_enum attachment_status);
extern JC_RETCODE mmi_um_jmms_store_update_message(
                    S8 *folder_name_p,
                    JC_UINT32 ui_extra_bytes,
                    U8 media_count,
                    JC_UINT32 ui_msg_index);

extern JC_RETCODE mmi_jmms_delete_all_msgs_list(UmMsgBoxType folder_type_list);
extern U16 mmi_um_get_curr_folder_name(void);
extern void (*mmi_um_jmms_folder_list_callback) (void);
extern void mmi_um_jmms_pre_entry_inbox_including_highlighter(void);
extern void mmi_um_jmms_pre_entry_draft_including_highlighter(void);
extern void mmi_um_jmms_new_mms_message_ind(U16 msg_index);

//vikas end
//extern void 
extern S16 mmi_jmms_get_number_of_messages_from_msg_box_type(UmMsgBoxType msg_box_type);
extern void mmi_um_delete_all_mms_messages_rsp(U16 result); /* Vivek - 8-nov-2006 */
#endif /* _JMMSUMHANDLE_H */ 

