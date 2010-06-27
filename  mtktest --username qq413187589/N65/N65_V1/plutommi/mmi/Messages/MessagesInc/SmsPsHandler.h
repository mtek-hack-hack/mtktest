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
 * SmsPsHandler.H
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

   FILENAME : SmsPsHandler.h

   PURPOSE     : ---

   REMARKS     : ---

   AUTHOR      : Magesh k, Hiran

   DATE     : ---

**************************************************************/

#ifndef _PIXCOM_SMS_PRT_MSG_HANDLER_H
#define _PIXCOM_SMS_PRT_MSG_HANDLER_H

#include "MMIDataType.h"
#include "MessagesL4Def.h"
#include "MessagesMiscell.h"
#include "EmsMiscell.h"
/*  */
#define MSG_INVALID_TIMER                 0xff
#define MSG_MAX_TIMER                     12

/*  */
typedef enum
{
    MSG_LIST_AWAITED,
    MSG_LIST_INBOX,
    MSG_LIST_OUTBOX,
    MSG_LIST_DRAFTBOX
} msgbox_list_type_enum;

/*******************************************

         new functions

*******************************************/
extern void mmi_msg_handle_ready_ind(void *dummy, module_type mod, U16 result);
extern void mmi_msg_handle_ready_ind_after_init(void *dummy);
extern void mmi_msg_callback_init_msg_process(void *dummy);
extern void mmi_msg_sync_msgbox_with_at(void *dummy, module_type mod, U16 result);
extern void mmi_msg_handle_msg_waiting_ind(void *inMsg, module_type mod, U16 result);
extern void mmi_msg_handle_deliver_report_ind(void *inMsg, module_type mod, U16 result);
extern void mmi_msg_handle_mem_full_ind(void *dummy, module_type mod, U16 result);
extern void mmi_msg_handle_mem_exceed_ind(void *dummy, module_type mod, U16 result);
extern void mmi_msg_handle_mem_avail_ind(void *dummy, module_type mod, U16 result);
extern U8 mmi_msg_handle_class0_msg_ind(void *inMsg, void *content);
extern void mmi_msg_handle_new_msg_ind(void *data, module_type mod, U16 index);
extern U8 mmi_msg_check_new_msg_ind(
            U8 type,
            U8 len,
            U8 *number,
            U8 *timestamp,
            U16 ref,
            U8 totalseg,
            U8 currseg,
            U16 l4index,
            U8 mti);
#ifdef __MMI_MESSAGES_CHAT__
extern void mmi_msg_check_chat_msg(U16 index);
#endif 
extern void mmi_msg_get_msg_new(void);

extern void mmi_msg_check_fdn_req(void);
extern void mmi_msg_check_fdn_rsp(void *inMsg);
extern void mmi_msg_send_msg_req(U8 *number, U16 replyindex, U8 hidenumscreen);
extern void mmi_msg_send_and_save_msg_req(U8 *number, U16 replyindex);
extern void mmi_msg_save_msg_after_send_req(U8 status, void *number);
extern void mmi_msg_save_msg_after_send_with_flag_req(U8 status, void *number, U16 flag);
extern void mmi_msg_send_msg_to_many_req(U8 *number);

extern void mmi_msg_abort_msg_req(void);
extern void mmi_msg_abort_msg_rsp(void *inMsg);

extern U8 mmi_msg_pack_msg(void);
extern void mmi_msg_send_msg(void);
extern void mmi_msg_save_msg(U8 status);
extern void mmi_msg_abort_msg(void);
extern void mmi_msg_search_phb(void);
extern void mmi_msg_send_msg_to_entry(void);
extern void mmi_msg_send_msg_to_entry_next(void);

#ifdef __MMI_MESSAGES_SEND_TO_MANY__
extern void mmi_msg_send_msg_to_many(void);
#endif 
#ifdef __MMI_MESSAGES_SEND_BY_GROUP__
extern void mmi_msg_send_msg_to_group_entry(U16 index, U8 isfirst);
extern void mmi_msg_send_msg_to_group(U16 cnt, U16 *PhbIndex);
extern void mmi_msg_send_msg_by_group(void);
#endif /* __MMI_MESSAGES_SEND_BY_GROUP__ */ 
extern void mmi_msg_send_msg_to_only_entry(void);

#ifdef __MMI_SEND_BY_SEARCH_NAME__
extern void mmi_msg_send_msg_to_only_name_entry(void);
#endif 
extern void mmi_msg_save_msg_req(void);
extern void mmi_msg_save_msg_with_flag_req(U16 flag);
extern void mmi_msg_save_msg_to_entry(void);
extern void mmi_msg_send_and_save_to_entry(void);
extern void mmi_msg_reply_msg(void);
extern void mmi_msg_reply_msg_to_entry(void);
extern void mmi_msg_get_number_from_phb(U8 name[], U8 number[]);
extern void mmi_msg_get_number_from_phb_ext(S8* name, S8* number);
extern void mmi_msg_edit_msg_from_view(void);
extern void mmi_msg_delete_msg(void);
extern void mmi_msg_pre_delete_msg_all_inbox(void);
extern void mmi_msg_delete_msg_all_inbox(void);
extern void mmi_msg_pre_delete_msg_all_outbox(void);
extern void mmi_msg_delete_msg_all_outbox(void);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern void mmi_msg_pre_move_msg_to_archive(void);
extern void mmi_msg_move_msg_to_archive(void); 
extern void mmi_msg_pre_delete_msg_all_archive(void);
extern void mmi_msg_delete_msg_all_archive(void);
extern void mmi_msg_get_msg_archive(void);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

#ifdef __MMI_MESSAGES_COPY__
extern void mmi_msg_copy_msg(void);
extern void mmi_msg_copy_msg_all_abort(void);

extern void mmi_msg_move_msg(void);
extern void mmi_msg_move_msg_all_abort(void);

#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_msg_copy_msg_all_from_sim_inbox(void);
extern void mmi_msg_copy_msg_all_from_phone_inbox(void);
extern void mmi_msg_copy_msg_all_from_sim_outbox(void);
extern void mmi_msg_copy_msg_all_from_phone_outbox(void);

extern void mmi_msg_move_msg_all_from_sim_inbox(void);
extern void mmi_msg_move_msg_all_from_phone_inbox(void);
extern void mmi_msg_move_msg_all_from_sim_outbox(void);
extern void mmi_msg_move_msg_all_from_phone_outbox(void);

#ifdef __MMI_MESSAGES_DRAFT_BOX__
extern void mmi_msg_copy_msg_all_from_sim_draftbox(void);
extern void mmi_msg_copy_msg_all_from_phone_draftbox(void);
extern void mmi_msg_move_msg_all_from_sim_draftbox(void);
extern void mmi_msg_move_msg_all_from_phone_draftbox(void);
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_msg_copy_msg_all_from_sim_unsentbox(void);
extern void mmi_msg_copy_msg_all_from_phone_unsentbox(void);
extern void mmi_msg_move_msg_all_from_sim_unsentbox(void);
extern void mmi_msg_move_msg_all_from_phone_unsentbox(void);
#endif /* __MMI_UNIFIED_MESSAGE__ */
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif /* __MMI_MESSAGES_COPY__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_msg_pre_delete_msg_all_unsentbox(void);
extern void mmi_msg_delete_msg_all_unsentbox(void);
extern void mmi_msg_get_msg_unsentbox(void);
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
extern void mmi_msg_pre_delete_msg_all_draftbox(void);
extern void mmi_msg_delete_msg_all_draftbox(void);
extern void mmi_msg_delete_msg_rsp_draftbox(void *inMsg);
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
#ifdef __MMI_MESSAGES_DELETE_ALL_MENU__
extern void mmi_msg_delete_msg_all(void);
extern void mmi_msg_pre_delete_msg_all(void);
#endif /* __MMI_MESSAGES_DELETE_ALL_MENU__ */ 

extern U16 mmi_msg_get_msg_list_avai_index(U8 list);
extern U16 mmi_msg_get_msg_list_start_index(U8 list);
extern U16 mmi_msg_get_msg_list_end_index(U8 list);
extern void mmi_msg_add_msg_new_entry(
                U8 status,
                U8 type,
                U8 len,
                U8 *number,
                U8 *timestamp,
                U16 ref,
                U8 totalseg,
                U8 currseg,
                U16 l4index,
                U8 mti);
extern void mmi_msg_add_msg_list_entry(
                U16 index,
                U8 status,
                U8 type,
                U8 len,
                U8 *number,
                U8 *timestamp,
                U16 ref,
                U8 totalseg,
                U8 currseg,
                U16 l4index,
                U8 mti);
extern void mmi_msg_change_msg_list_entry_status(U16 index, U8 status);
extern void mmi_msg_remove_msg_list_entry(U8 list, U16 index);
extern void mmi_msg_copy_msg_list_entry(U16 toindex, U16 fromindex);
extern void mmi_msg_add_msg_list_entry_seg(U16 index, U8 seg, U16 l4index);
extern U16 mmi_msg_search_msg_list_entry(
            U8 list,
            U8 type,
            U8 len,
            U8 *number,
            U16 ref,
            U8 totalseg,
            U8 currseg,
            U16 l4index);
extern U8 mmi_msg_check_msg_complete(U16 index);
extern void mmi_msg_start_msg_timer(U16 index);
extern void mmi_msg_stop_msg_timer(U16 index);
extern void mmi_msg_callback_msg_timer(void);

extern void mmi_msg_get_msg_list_req(smsal_status_enum status, U16 startindex, U8 msgnum);
extern void mmi_msg_get_msg_list_rsp_inbox(void *inMsg);
extern void mmi_msg_get_msg_list_rsp_outbox(void *inMsg);

#ifdef __MMI_MESSAGES_DRAFT_BOX__
extern void mmi_msg_get_msg_list_rsp_draftbox(void *inMsg);
#endif 
extern void mmi_msg_reset_msg_list(U8 list);

extern void mmi_msg_get_msg_num_rsp_inbox(void *inMsg);
extern void mmi_msg_get_msg_num_rsp_outbox(void *inMsg);

#ifdef __MMI_MESSAGES_DRAFT_BOX__
extern void mmi_msg_get_msg_num_rsp_draftbox(void *inMsg);
#endif 
extern void mmi_msg_reget_msg_list_inbox(void *dummy);

extern void mmi_msg_get_msg_list_inbox(void);
extern void mmi_msg_get_msg_list_outbox(void);

#ifdef __MMI_MESSAGES_DRAFT_BOX__
extern void mmi_msg_get_msg_list_draftbox(void);
#endif 
extern void mmi_msg_get_msg_num_rsp_unread(void *inMsg);
extern void mmi_msg_get_msg_req(U16 type, U16 index);
extern void mmi_msg_get_msg_rsp_inbox(void *inMsg);
extern void mmi_msg_get_msg_rsp_outbox(void *inMsg);
extern void mmi_msg_get_msg(U16 index);
extern void mmi_msg_get_msg_inbox(void);
extern void mmi_msg_get_msg_outbox(void);

#ifdef __MMI_MESSAGES_DRAFT_BOX__
extern void mmi_msg_get_msg_draftbox(void);
#endif 
#ifdef __MMI_MESSAGES_CHAT__
extern void mmi_msg_get_msg_chat(void);
#endif 
extern void mmi_msg_reset_msg(void);
extern void mmi_msg_unpack_msg(U8 dcs, U8 fo);
extern void mmi_msg_unpack_class0_msg(void);

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_msg_delete_all_msg_by_um(U8 um_folder_type);
extern void mmi_msg_handle_delete_all_msg_by_um_rsp(void *inMsg);
extern void mmi_msg_handle_get_num_req(void *inMsg);
extern void mmi_msg_send_new_msg_ind(U8 msg_box_type, U16 list_index, U32 timestamp);
extern void mmi_msg_send_ready_ind(kal_bool result);
extern void mmi_msg_send_refresh_ind(U8 msg_box_type);
extern void mmi_msg_send_highlight_decided_by_um_ind(U8 msg_box_type, U16 msg_index);
extern void mmi_msg_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

extern void mmi_msg_set_protocol_event_handler(void);
extern void mmi_msg_set_protocol_event_handler_after_init(void);

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
extern void mmi_msg_pre_entry_list_option_req(U16 msg_box_type);
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_msg_highlight_delete_all_simbox(void);
extern void mmi_msg_pre_delete_msg_all_simbox(void);
extern void mmi_msg_delete_msg_all_simbox(void);
extern void mmi_msg_copy_msg_all_simbox(void);
extern void mmi_msg_move_msg_all_simbox(void);
extern void mmi_msg_get_msg_simbox(void);
extern void mmi_msg_get_sim_msg_new(void);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

extern MMI_BOOL mmi_msg_check_interrupt_in_sending(void);
extern void mmi_msg_replace_sending_to_processing(void);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
extern void mmi_msg_handle_sms_set_status_rsp(void *data, module_type mod, U16 result);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

extern void mmi_msg_ascii_to_usc2(S8* out_usc2, const S8* in_ascii, U16 ascci_len);

#endif /* _PIXCOM_SMS_PRT_MSG_HANDLER_H */ 

