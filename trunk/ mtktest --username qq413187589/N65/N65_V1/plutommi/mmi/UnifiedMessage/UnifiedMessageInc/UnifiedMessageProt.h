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
*  Copyright Statement: *  -------------------- *  This software is protected by 
Copyright and the information contained *  herein is confidential. The software 
may not be copied and the information *  contained herein may not be used or 
disclosed except with the written *  permission of MediaTek Inc. (C) 2002 * 
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * UnifiedMessageProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines local enum, constant and prototypes for Unified Message
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
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_UNIFIED_MESSAGE_PROT_H
#define _MMI_UNIFIED_MESSAGE_PROT_H

#include "MemPoolContainerProt.h"
#include "customer_ps_inc.h"
#include "custom_wap_config.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "mmi_msg_context.h"

#define MMI_UM_MAX_SUPPORT_MSG_TYPE    (8)
#define MMI_UM_INPROGRESS_TIME_OUT        (1000*120)
#define MMI_UM_MAX_GET_STRING_LEN   (16)

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#define MMI_UM_MAX_MSG_AND_ARMSG_NUM ((MMI_SMS_MAX_MSG_NUM) > (CM_SMS_MAX_ARMSG_NUM) ? (MMI_SMS_MAX_MSG_NUM) : (CM_SMS_MAX_ARMSG_NUM) )
#define MMI_UM_MAX_MSG_NUM ((MMI_UM_MAX_MSG_AND_ARMSG_NUM)  + (WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG-1) + (WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG))  
#else
#define MMI_UM_MAX_MSG_NUM ((MMI_SMS_MAX_MSG_NUM)  + (WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG-1) + (WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG) )
#endif

#define MMI_UM_MAX_MSG_PER_PAGE          (5)    /* Max number of messages */
#define MMI_UM_TOTAL_POOL           ((MAX_ASYNCDYNAMIC_ITEMS_BUFF + MMI_UM_MAX_MSG_PER_PAGE -1)/MMI_UM_MAX_MSG_PER_PAGE)
#define MMI_UM_MAX_MSG_DETAIL_NUM   ((MMI_UM_TOTAL_POOL+1)*MMI_UM_MAX_MSG_PER_PAGE)

#define MMI_UM_MAX_LEN_TIME_STR  (15 + 1 + 10 + 1) /* Date string + 1 space + Time string + NULL terminator*/

typedef enum
{
    UM_ACTION_GET_MSG_NUM,
    UM_ACTION_GET_LIST_INFO,
    UM_ACTION_GET_MSG_INFO,
    UM_ACTION_DELETE_FOLDER,
    UM_ACTION_TOTAL_NUMBER
} um_action_type_enum;

typedef struct
{
    S32 main_index;
    UmMsgType support_type;     /* bitwise OR by UmMsgType */
    UmMsgType ready_type;       /* bitwise OR by UmMsgType */
    UmMsgType pending_req_type; /* bitwise OR by UmMsgType */
    um_state_type_enum state;
    um_action_type_enum current_action;
    kal_bool is_skip_write_menu;
    kal_bool is_new_msg;
    kal_bool is_ready_for_new_msg;
    kal_bool is_new_msg_comes_in_idle; 
    kal_bool is_reset_folder_info;
    kal_bool is_refresh;
} mmi_um_main_info_struct;

typedef struct
{
    S16 caption_str_id;
    S16 body_str_id;
    U16 animation_image_id;
    U16 RSK_str_id;
} mmi_um_processing_info_struct;

typedef struct
{
    U16 inbox_msg_number;
    U16 inbox_unread_msg_number;
    U16 unsent_msg_number;
    U16 sent_msg_number;
    U16 draft_msg_number;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    U16 archive_msg_number;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    U16 sim_msg_number;
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
} mmi_um_msg_number_info_struct;

typedef struct
{    
    U16 folders_to_delete;
    U8 folder_type; /* Used by highlight index */
    U8 result;
} mmi_um_delete_folder_info_struct;

typedef struct
{
    mem_pool_container_struct mem_container;
    S32 start_index;
    S32 end_index;
    S16 not_avail_pool; /* current pool index which data is not available */
} mmi_um_mem_pool_info_struct;

typedef struct
{
    mmi_um_list_info_struct list_info;
    UmMsgType msg_type;
} mmi_um_msg_box_info_struct;

typedef struct
{
    UmMsgType msg_type;
    mmi_um_msg_info_struct msg_detail;
} mmi_um_msg_detail_struct;

typedef struct
{
    UmMsgType msg_type;
    U16 msg_index;  /* the index, msg type, and msg box type could be able to uniquely identify a message */
} mmi_um_highlight_msg_struct;

typedef struct
{
    mmi_um_msg_box_info_struct msg_list[MMI_UM_MAX_MSG_NUM];
    mmi_um_msg_detail_struct msg_detail_list[MMI_UM_MAX_MSG_DETAIL_NUM];
    UI_character_type msg_time[MMI_UM_MAX_LEN_TIME_STR];    /* buffer for time string */
    U16 current_msg_index;
    UmMsgBoxType current_msg_box;
    U16 msg_number_in_list;
    BOOL is_list_displayed; /* is list is already displayed */

    BOOL is_highlight_change_needed;
    mmi_um_highlight_msg_struct msg_to_highlight;
} mmi_um_folder_info_struct;

typedef struct
{
    U16 start_index_sms;
    U16 start_index_mms;
    U16 start_index_wap_push;

    U16 msg_num_to_get_sms;
    U16 msg_num_to_get_mms;
    U16 msg_num_to_get_wap_push;

    U8 num_in_temp_buffer;

    mmi_um_msg_detail_struct temp_buffer[MMI_UM_MAX_MSG_PER_PAGE];
} mmi_um_get_msg_detail_struct;

typedef struct
{
    mmi_um_main_info_struct main;
    mmi_um_processing_info_struct processing;
    mmi_um_msg_number_info_struct msg_number;
    mmi_um_delete_folder_info_struct delete_folder;
    mmi_um_mem_pool_info_struct mem_pool_info;  /* Memory pool */
    mmi_um_folder_info_struct folder;
    mmi_um_get_msg_detail_struct get_msg_detail;
} mmi_um_context_struct;

extern mmi_um_context_struct g_um_cntx; /* global context of um */
extern mmi_um_context_struct *g_um_p;

extern void mmi_um_init_context(void);
extern void mmi_um_pre_entry_main(void);
extern void mmi_um_set_protocol_event_handler(void);
extern void mmi_um_handle_ready_ind(void *inMsg);
extern void mmi_um_handle_new_msg_ind(void *inMsg);
extern void mmi_um_handle_delete_all_ind(void *inMsg);
extern void mmi_um_handle_highlight_msg_ind(void *inMsg);
void mmi_um_handle_highlight_decided_by_UM_ind(void *inMsg);
extern void mmi_um_handle_refresh_ind(void *inMsg);
extern void mmi_um_change_highlight(void);
extern void mmi_um_get_msg_num_rsp(void *inMsg);
extern kal_bool mmi_um_check_support_type(UmMsgType type);
extern void mmi_um_set_processing_screen(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId);
extern void mmi_um_exit_processing_generic(void);
extern void mmi_um_time_out_processing_generic(void);
extern void mmi_um_entry_processing_generic(void);
extern void mmi_um_handle_screen_for_ready_ind(void);
extern void mmi_um_get_msg_num_req(void);
extern void mmi_um_set_state(U8 state);
extern void mmi_um_entry_main(void);
extern void mmi_um_exit_generic(void);
extern void mmi_um_exit_folder(void);
extern void mmi_um_set_main_menu_highlight_handler(void);
extern void mmi_um_highlight_write_msg(void);
extern void mmi_um_highlight_inbox(void);
extern void mmi_um_highlight_unsent(void);
extern void mmi_um_highlight_sent(void);
extern void mmi_um_highlight_draft(void);
extern void mmi_um_highlight_delete_folder(void);
extern void mmi_um_highlight_template(void);
extern void mmi_um_highlight_setting(void);
extern void mmi_um_hint_inbox(U16 index);
extern void mmi_um_hint_unsent(U16 index);
extern void mmi_um_hint_sent(U16 index);
extern void mmi_um_hint_draft(U16 index);
extern void mmi_um_entry_write_msg(void);
extern void mmi_um_pre_entry_inbox(void);
extern void mmi_um_pre_entry_unsent(void);
extern void mmi_um_pre_entry_sent(void);
extern void mmi_um_pre_entry_draft(void);
extern void mmi_um_pre_entry_delete_folder(void);
extern void mmi_um_entry_delete_folder(void);
extern void mmi_um_entry_template(void);
extern void mmi_um_entry_setting(void);
extern void mmi_um_highlight_write_msg_sms(void);
extern void mmi_um_highlight_write_msg_mms(void);
extern void mmi_um_highlight_setting_sms(void);
extern void mmi_um_highlight_setting_mms(void);
extern void mmi_um_highlight_template_sms(void);
extern void mmi_um_highlight_template_mms(void);
extern void mmi_um_set_delete_folder_highlight_handler(void);
extern void mmi_um_pre_delete_folder(void);
extern void mmi_um_delete_folder_highlight_handler(S32 index);
extern void mmi_um_main_highlight_handler(S32 index);
extern void mmi_um_delete_folder_req(void);
extern void mmi_um_delete_folder_rsp(void *inMsg);
extern void mmi_um_process_delete_folder(void);
extern void mmi_um_get_list_info_req(void);
extern void mmi_um_insert_list_info(UmMsgType msg_type, kal_uint16 msg_number, mmi_um_list_info_struct *list_info);
extern void mmi_um_entry_folder(void);
extern void mmi_um_reset_folder_info(void);
extern void mmi_um_free_container_pool(void);
extern void mmi_um_hilite_folder_item(S32 index);
extern S32 mmi_um_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
extern void mmi_um_entry_get_msg_info(void);
extern void mmi_um_get_msg_info_req(void);
extern void mmi_um_get_msg_info_rsp(void *inMsg);
extern void mmi_um_insert_msg_info(
                UmMsgType UM_MSG_TYPE_SMS,
                kal_uint16 msg_number,
                mmi_um_msg_info_struct *temp_list);
extern BOOL mmi_um_is_list_ready(void);
extern void mmi_um_enter_curr_folder(void);
extern void mmi_um_handle_get_msg_num_rsp(void);
extern void mmi_um_handle_get_list_info_rsp(void);
extern void mmi_um_handle_get_msg_info_rsp(void);
extern void mmi_um_entry_msg(void);
extern void mmi_um_exit_new_msg_ind(void);
extern void mmi_um_handle_delete_folder_rsp(UmMsgType type, kal_bool result);
extern void mmi_um_get_list_info_rsp(void *inMsg);
extern void mmi_um_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);
extern void mmi_um_entry_new_msg_ind(kal_bool ready);
extern U8 mmi_frm_sms_get_sms_bitmap(U16 type, U16 index, U8 *l4_index);
extern void mmi_um_go_back_from_new_msg_ind(void);
extern kal_bool mmi_um_reset_folder_history_guibuffer(U16 screen_id);
extern kal_bool mmi_um_check_interrupt(void);

extern void mmi_um_handle_cancel_new_msg_ind(void *inMsg);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern void mmi_um_highlight_archive(void);
extern void mmi_um_pre_entry_archive(void);
extern void mmi_um_hint_archive(U16 index);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_um_pre_entry_simbox(void);
extern void mmi_um_highlight_simbox(void);
extern void mmi_um_hint_simbox(U16 index);

#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#endif /* _MMI_UNIFIED_MESSAGE_PROT_H */ 

