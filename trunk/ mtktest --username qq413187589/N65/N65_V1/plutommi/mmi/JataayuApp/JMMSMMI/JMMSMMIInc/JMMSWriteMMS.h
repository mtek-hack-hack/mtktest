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
 *  JMMSWriteMMS.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_write_mms_ui.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSWRITEMMSSECMMI_H
#define __MMI_JMMSWRITEMMSSECMMI_H

#include "MMI_features.h"
#include "MMIDataType.h"
// #include "MessagingDataTypes.h"

/* 
 * Define
 */
#ifndef CAST_PU8
#define CAST_PU8(RAW)   ((U8*)(RAW))
#endif 

#ifndef CAST_CPS8
#define CAST_CPS8(RAW)  ((const S8*)(RAW))
#endif 

#ifndef CAST_CPU8
#define CAST_CPU8(RAW)  ((const U8*)(RAW))
#endif 

#ifndef GET_U8_BYTE_TO_U16
#define GET_U8_BYTE_TO_U16(RAW, i)  ((U16)(CAST_CPU8(RAW)[i]))
#endif 

#ifndef STR_SIZE
#define STR_SIZE(len) ((len)<<1)
#endif 

#ifndef STR_AT
#define STR_AT(RAW, n) ((void*)(CAST_PU8(RAW)+STR_SIZE(n)))
#endif 

#ifndef CHR_AT
#define CHR_AT(RAW, n) ((U16)(GET_U8_BYTE_TO_U16(RAW, STR_SIZE(n))+(GET_U8_BYTE_TO_U16(RAW, STR_SIZE(n)+1)<<8)))
#endif 

#ifndef STR_LEN
#define STR_LEN(RAW)  mmi_ucs2strlen(CAST_CPS8(RAW))
#endif 
/* /#define CHR(x)                ((U16)(x)) */

/* 
 * Typedef 
 */

typedef enum
{
    E_WRITE_MMS_TO,
    E_WRITE_MMS_CC,
    E_WRITE_MMS_BCC,
    E_WRITE_MMS_SUBJECT,
    E_WRITE_MMS_ATTACHMENT_CAPTION,
    E_WRITE_MMS_ATTACHMENT,
    E_WRITE_MMS_EDIT_CONTENT_CAPTION,
    E_WRITE_MMS_EDIT_CONTENT,
    WRITE_MMS_INLINE_TOTAL
} jmms_write_mms_inline_items_enum;

typedef enum
{
    E_TO_ADDRESSES,
    E_CC_ADDRESSES,
    E_BCC_ADDRESSES,
    E_NONE_ADDRESSES    /* COMPILER WARNING REMOVAL */
} jmms_write_mms_addresses_options;

typedef enum
{
    E_ADD_NUMBER,
    E_ADD_EMAIL,
    E_EDIT_ADDRESS,
#ifdef __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__
    E_ADD_NUMBER_GROUP,
    E_ADD_EMAIL_GROUP,
#endif /* __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__ */ 
    E_ADD_TOTAL_ADDRESS
} jmms_address_option_enum;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

extern void mmi_jmms_entry_write_message(void);

#ifndef __MMI_UNIFIED_COMPOSER__
extern void mmi_jmms_write_mms_fill_inline_struct(void);

/* void mmi_jmms_write_mms_custom_func(void); */
extern void mmi_jmms_write_mms_subject_custom_func(void);

extern void mmi_jmms_write_mms_highlight_hdlr(S32 index);
extern void mmi_jmms_exit_write_message(void);
extern void mmi_jmms_entry_address_option(void);
extern void mmi_jmms_done_write_mms(void);
extern void mmi_jmms_entry_addresses_option_screen(void);
extern void mmi_jmms_highlight_write_mms_add_number(void);
extern void mmi_jmms_highlight_write_mms_add_email(void);

#ifdef __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__
extern void mmi_jmms_highlight_write_mms_add_number_by_group(void);
extern void mmi_jmms_highlight_write_mms_add_email_addr_by_group(void);
extern void mmi_jmms_entry_write_message_add_group_screen(void);
extern void mmi_jmms_get_group_address_callback(U16 count, U16 *PhbIndex);
#endif /* __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__ */ 
extern void mmi_jmms_highlight_write_mms_edit(void);
extern void mmi_jmms_highlight_write_mms_delete(void);
extern void mmi_jmms_highlight_write_mms_delete_all(void);
extern void mmi_jmms_entry_addresses_list_screen(void);
extern void mmi_jmms_entry_write_message_add_number(void);
extern void mmi_jmms_entry_write_message_add_number_screen(void);
extern void mmi_jmms_address_fullscreen_editor_on_empty(void);
extern void mmi_jmms_address_fullscreen_editor_on_not_empty(void);
extern void mmi_jmms_address_search_phonebook_or_ok(void);
extern void mmi_jmms_address_editor_insert_character_plus(void);
extern void mmi_jmms_entry_write_message_screen(void);
extern void mmi_jmms_entry_write_message_add_email(void);
extern void mmi_jmms_entry_write_message_edit(void);
extern void mmi_jmms_entry_write_message_delete(void);
extern void mmi_jmms_entry_write_message_delete_all(void);

extern void mmi_jmms_entry_write_message_add_email_screen(void);
extern void mmi_jmms_address_list_highlight_hdlr(S32 index);
extern void mmi_jmms_back_to_write_mms(void);
extern U8 mmi_jmms_replace_address_in_addresse_list(S8 *address_p);
extern void mmi_jmms_highlight_write_mms_done_send_only(void);
extern void mmi_jmms_highlight_write_mms_done_save_and_send(void);
extern void mmi_jmms_highlight_write_mms_done_save_to_drafts(void);
extern void mmi_jmms_highlight_write_mms_done_send_options(void);
extern void mmi_jmms_highlight_write_mms_done_exit(void);
extern void mmi_jmms_done_exit_confirm_screen(void);

extern void mmi_jmms_pre_entry_write_mms_done_send_only(void);
extern void mmi_jmms_entry_write_mms_done_send_only(void);
extern void mmi_jmms_entry_write_mms_done_save_and_send(void);
extern void mmi_jmms_entry_write_mms_done_save_to_drafts(void);
extern void mmi_jmms_entry_write_mms_done_replace_save_to_drafts(void);
extern void mmi_jmms_entry_write_mms_done_new_save_to_drafts(void);
extern void mmi_jmms_entry_write_mms_done_send_options(void);
extern void mmi_jmms_entry_write_mms_done_exit(void);
extern void mmi_jmms_done_exit_confirm_screen(void);

extern void mmi_jmms_write_message_init(void);

extern void mmi_jmms_entry_write_message_delete_all_confirm(void);

/* PMT VIKAS START 20060325 */
extern void update_mms_number_from_phonebook(S8 *number_p);
extern void update_mms_email_from_phonebook(S8 *email_p);

/* PMT VIKAS END 20060325 */

extern void mmi_jmms_entry_msg_saving_screen(void);
extern void mmi_jmms_entry_msg_saving_status_screen(void);
extern void mmi_jmms_back_from_save_msg_status_screen(void);

extern void mmi_jmms_new_save_to_drafts_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_replace_save_to_drafts_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_replace_save_to_drafts_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_abort_saving_progress(void);
extern void mmi_jmms_entry_write_message_screen_in_history(void);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

extern void mmi_jmms_init_msg_context_struct(void);
extern U8 mmi_jmms_add_address_in_addresse_list(S8 *address);
extern U8 mmi_jmms_add_from_address_in_addresse_list(S8 *address);
extern MMI_BOOL mmi_jmms_check_address_input_format(U8 *email_address_p);
extern MMI_BOOL mmi_jmms_check_number_input_format(U8 *number_p);
extern MMI_BOOL mmi_jmms_check_duplicate_address(
                    U8 *address,
                    jmms_write_mms_addresses_options ignore_address_field,
                    S32 ignore_address_id);
extern MMI_BOOL mmi_jmms_addrss_is_domain_name(U16 *str_p);
extern MMI_BOOL mmi_jmms_is_email_local_part(U16 *str_p, S32 cnt);
extern void mmi_jmms_go_back_from_rc_screen(void);

/* Deepali Added for Reply Charging handling. */
extern JC_RETCODE mmi_jmms_reply_charging_ind_cb(
                    MSG_HANDLE h_msg,
                    void *callback_arg_p,
                    REPLY_CHARGE_LIMITS *rc_limit_p);
extern JC_BOOLEAN mmi_jmms_check_valid_rc_size_limits(void);
extern JC_BOOLEAN mmi_jmms_check_valid_rc_type(void);
extern JC_BOOLEAN mmi_jmms_check_valid_rc_send_time(void);
extern JC_BOOLEAN mmi_jmms_is_rc_info_present(void);
extern void mmi_jmms_clear_rc_info_before_send(void);
extern void mmi_jmms_edit_content_restricted_mode_query(void);
extern void mmi_jmms_add_blank_slide_before_send_callback(void);
extern void mmi_jmms_proceed_edit_content_after_media_removal(void);
extern MMI_BOOL mmi_jmms_compair_string(S8 *string1_p, S8 *string2_p);

extern S8 *mmi_jmms_get_to_addresses(void);
extern S8 *mmi_jmms_get_cc_addresses(void);
extern S8 *mmi_jmms_get_bcc_addresses(void);

#endif /* __MMI_JMMSWRITEMMSSECMMI_H */ 

