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
 * mmiapi_func.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines message structures of MMI.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMIAPI_FUNC_H
#define _MMIAPI_FUNC_H

#include "mmiapi_struct.h"

extern void mmiapi_fullscreen_editor_set_number(S8* name, S8* number);
/* MMI services for WAP */
extern void mmiapi_message_action_register_ind(void *msg);
extern void mmiapi_unread_push_icon_ind(void *msg);
extern void mmiapi_mms_icon_ind(void *msg);

extern U8 mmiapi_get_num_message_action(void);
extern void MMIProcessActionMsg(void);

/* Remote procedure call */
extern BOOL mmiapi_is_MMI_task(void);
extern void mmiapi_remote_proc_call_req(mmiapi_remote_proc_call_struct *msg, module_type mod_src);

/* short message service */
#ifdef MMIAPI_USING_SMS
extern void mmiapi_sms_send_req(mmiapi_sms_send_req_struct *msg, module_type mod_src);
extern void mmiapimsg_sms_send_rsp(module_type mod_dest, kal_bool result);
extern void mmiapi_sms_send_rsp(void *msg, module_type mod_src, U16 result);

extern void mmiapi_sms_register_port_req(mmiapi_sms_register_port_req_struct *msg, module_type mod_src);
extern void mmiapi_sms_register_port_rsp(void *msg, module_type mod_src, U16 result);
extern void mmiapimsg_sms_register_port_rsp(module_type mod_dest, kal_bool result);

extern void mmiapi_sms_app_data_ind(mmi_sms_app_data_ind_struct *msg, module_type mod_src);
extern void mmiapi_sms_verify_pool_expire(void *);
extern void mmiapi_sms_remove_pool_data_by_port(int port_number);

extern void mmiapi_sms_check_incoming_msg_req(mmiapi_sms_check_incoming_msg_req_struct *msg, module_type mod_src);
extern void mmiapimsg_sms_check_incoming_msg_rsp(module_type mod_dest, int result);

extern void mmiapi_sms_get_incoming_msg_timestamp_req(
                mmiapi_sms_get_incoming_msg_timestamp_req_struct *msg,
                module_type mod_src);
extern void mmiapimsg_sms_get_incoming_msg_timestamp_rsp(module_type mod_dest, kal_uint8 *scts);

extern void mmiapi_sms_get_incoming_msg_address_req(
                mmiapi_sms_get_incoming_msg_address_req_struct *msg,
                module_type mod_src);
extern void mmiapimsg_sms_get_incoming_msg_address_rsp(module_type mod_dest, l4_addr_bcd_struct *oa);

extern void mmiapi_sms_get_incoming_msg_req(mmiapi_sms_get_incoming_msg_req_struct *msg, module_type mod_src);
extern void mmiapi_sms_get_incoming_msg_rsp(module_type mod_dest, kal_uint8 *msg, int msg_len);

extern void mmiapimsg_sms_ind(void *msg, module_type mod_dest, kal_uint16 serial);

#endif /* MMIAPI_USING_SMS */ 

#ifdef MMIAPI_USING_UI
extern void mmiapi_ui_enter_fullscreen_editor_req(
                mmiapi_ui_enter_fullscreen_editor_req_struct *msg,
                module_type mod_src);
extern void mmiapi_ui_enter_idle_screen_req(mmiapi_ui_enter_idle_screen_req_struct *msg, module_type mod_src);
#endif /* MMIAPI_USING_UI */ 

/* blocking macro */
extern mmiapi_blocking_data_struct mmiapi_blocking_data[];

#define BLOCKING_INIT(MOD,X)                                                                                   \
   {                                                                                                           \
      ASSERT(X->blocking_data == NULL || &(mmiapi_blocking_data[mmiapi_mod_index(MOD)]) == X->blocking_data);  \
      if(X->blocking_data == NULL)                                                                             \
         mmiapi_blocking_data[mmiapi_mod_index(MOD)].is_blocking = KAL_FALSE;                                  \
   }                                                                                                           \

#define BLOCKING_BOOLEAN_RETURN_VALUE(MOD,x)                                                       \
      mmiapi_blocking_data[mmiapi_mod_index(MOD)].result = x                                       \

#define BLOCKING_INT_RETURN_VALUE(MOD,x)                                                              \
      mmiapi_blocking_data[mmiapi_mod_index(MOD)].result_int = x                                      \

#define BLOCKING_PTR_RETURN_VALUE(MOD)                                           \
      mmiapi_blocking_data[mmiapi_mod_index(MOD)].result_ptr

#define BLOCKING_FINISH(MOD)                                                                                \
      if(mmiapi_blocking_data[mmiapi_mod_index(MOD)].is_blocking)                                           \
      {                                                                                                     \
         mmiapi_unlock(MOD);                                                                                \
         mmiapi_blocking_data[mmiapi_mod_index(MOD)].is_blocking=KAL_FALSE;                                 \
      }                                                                                                     \

#define IS_BLOCKING(MOD)                                                                                 \
   (mmiapi_blocking_data[mmiapi_mod_index(MOD)].is_blocking==KAL_TRUE)                                   \

#endif /* _MMIAPI_FUNC_H */ 

