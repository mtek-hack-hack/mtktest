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
 * vCard.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sending and receving vcard object.
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
#ifndef _MMI_VCARD_H
#define _MMI_VCARD_H

/* if some header should be include before this one */
#include "PhoneBookTypes.h"
#include "Conversions.h"

/* 
 * Typedef 
 */
typedef enum
{
    VCARD_FIELD_BEGIN,
    VCARD_FIELD_VERSION,
    VCARD_FIELD_FN,
    VCARD_FIELD_N,
    VCARD_FIELD_TEL,
    VCARD_FIELD_EMAIL,
    VCARD_FIELD_ORG,
    VCARD_FIELD_BDAY,
    VCARD_FIELD_TITLE,
    VCARD_FIELD_URL,
    VCARD_FIELD_NOTE,
    VCARD_FIELD_ADR,
    VCARD_FIELD_PHOTO,
    VCARD_FIELD_REV,
    VCARD_FIELD_LABEL,
    VCARD_FIELD_NICKNAME,
    VCARD_FIELD_MAILER,
    VCARD_FIELD_TZ,
    VCARD_FIELD_GEO,
    VCARD_FIELD_ROLE,
    VCARD_FIELD_LOGO,
    VCARD_FIELD_AGENT,
    VCARD_FIELD_CATEGORIES,
    VCARD_FIELD_PRODID,
    VCARD_FIELD_SORT_STRING,
    VCARD_FIELD_SOUND,
    VCARD_FIELD_UID,
    VCARD_FIELD_CLASS,
    VCARD_FIELD_KEY, 
    VCARD_FIELD_X,
    VCARD_FIELD_END,
    VCARD_FIELD_TOTAL
} vcard_filed_enum;

typedef enum
{
    VCARD_PARSE_NO_ERROR,
    VCARD_BEGIN_ERROR,
    VCARD_VERSION_ERROR,
    MMI_PHB_VCARD_OPEN_FILE_ERROR,
    MMI_PHB_VCARD_READ_FILE_ERROR,
    VCARD_PARSE_UNKNOW_ERROR
} vcard_parse_enum;

typedef enum
{
    MMI_VCARD_NO_TYPE,
    MMI_VCARD_SEND_MY_CARD,
    MMI_VCARD_SEND_SELECT_CARD
} vcard_card_type_enum;

typedef enum
{
    MMI_VCARD_PARSE_FROM_FILE_MANAGER,
    MMI_VCARD_PARSE_FROM_VOBJ_BUFFER
} vcard_parse_location_enum;

typedef enum
{
    MMI_VCARD_SAVE_TO_FILE_FROM_PHB,
    MMI_VCARD_SAVE_TO_FILE_FROM_RECV
} vcard_file_location_enum;

typedef struct
{
    S8 *FileNamePtr;
    S8 *FilePathPtr;
    U8 StorageLoc;
    U8 FileLoc;     /* vcard_file_location_enum */
    U8 ParseLoc;    /* vcard_parse_location_enum */
    U8 CardType;    /* vcard_card_type_enum */
    mmi_chset_enum CharSet;    
	/* char set used to decode when there is no encoding type in vcard file 
	   assign before mmi_vcard_reader_parse_line() */
} vcard_context_struct;

/* 
 * Define
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
extern void mmi_vcard_init(void);
extern void mmi_vcard_deinit(void);
extern void mmi_vcard_free_path_buffer(void);
extern void mmi_vcard_forward_option_my_card(void);
extern void mmi_vcard_forward_option_select_card(void);
extern void mmi_vcard_entry_forward_option(void);
extern void mmi_vcard_exit_forward_option(void);
extern U8 mmi_vcard_forward_option_delete_cb(void);

#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
extern void mmi_vcard_highlight_forward_sms(void);
extern void mmi_vcard_forward_sms(void);
extern void mmi_vcard_forward_sms_call_back(void *flag);
#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */ 

#if defined(__MMI_MMS__)
extern void mmi_vcard_highlight_forward_mms(void);
extern void mmi_vcard_forward_mms(void);
extern void mmi_vcard_forward_mms_call_back(void *param);
#endif /* defined(__MMI_MMS__) */ 

#if defined(__MMI_IRDA_SUPPORT__)
extern void mmi_vcard_highlight_forward_irda(void);
extern void mmi_vcard_forward_irda(void);
extern void mmi_vcard_forward_irda_callback(void *buf_p, U32 result);
#endif /* defined(__MMI_IRDA_SUPPORT__) */ 

#if defined(EMAIL_APP_SUPPORT)
extern void mmi_vcard_highlight_forward_email(void);
extern void mmi_vcard_forward_email(void);
#endif /* defined(EMAIL_APP_SUPPORT) */ 

#if defined(__MMI_FILE_MANAGER__)
extern void mmi_vcard_highlight_forward_fmgr(void);
extern void mmi_vcard_highlight_enter_filename_done(void);
extern void mmi_vcard_highlight_enter_filename_input_method(void);
extern void mmi_vcard_entry_enter_filename(void);
extern void mmi_vcard_exit_enter_filename(void);
extern void mmi_vcard_entry_enter_filename_option(void);
extern void mmi_vcard_exit_enter_filename_option(void);
extern void mmi_vcard_forward_fmgr(void);
extern void mmi_vcard_forward_fmgr_select_path_done(void *path, int is_short);
extern void mmi_vcard_forward_fmgr_pre_enter_filename(void);
extern void mmi_vcard_forward_fmgr_enter_filename_done(void);
extern S32 mmi_vcard_forward_fmgr_save_file(void);
extern void mmi_vcard_forward_fmgr_save_file_done(S32 result);
extern void mmi_vcard_fmgr_sms_forward(S8 *path);
#endif /* defined(__MMI_FILE_MANAGER__) */ 

extern void mmi_vcard_highlight_recv_save_to_sim(void);
extern void mmi_vcard_highlight_recv_save_to_phone(void);
extern void mmi_vcard_entry_recv_option(void);
extern void mmi_vcard_recv_from_idle_screen(void);

#if defined(__MMI_FILE_MANAGER__)
extern void mmi_vcard_highlight_recv_save_to_fmgr(void);
extern void mmi_vcard_recv_from_file_mgr(S8 *path);
#endif 
extern S32 mmi_vcard_writer_v21_mycard_to_file(S8 *path);
extern S32 mmi_vcard_writer_v21_select_card_to_file(S8 *path);
extern S32 mmi_vcard_writer_v21_to_file(
            S8 *path,
            S8 *ucs2_name,
            S8 *number,
            S8 *home_num,
            S8 *office_num,
            S8 *fax_num,
            S8 *email_addr,
            S8 *ucs2_company,
            S8 *b_day,
            PHB_INFO_FIELDS_STRUCT *info_fields,
            S8 *nick_name);
extern void mmi_vcard_writer_v21_append_name(S8 *object, S8 *temp_buf, S8 *field_name, S8 *field_value);
extern S32 mmi_vcard_writer_to_file(
            S8 *path,
            S8 *ucs2_name,
            S8 *number,
            S8 *home_num,
            S8 *office_num,
            S8 *fax_num,
            S8 *email_addr,
            S8 *ucs2_company,
            S8 *b_day,
            PHB_INFO_FIELDS_STRUCT *info_fields,
            S8 *nick_name);
#if defined(__MMI_VCARD_V30__)
extern S32 mmi_vcard_writer_v30_to_file(
            S8 *path,
            S8 *ucs2_name,
            S8 *number,
            S8 *home_num,
            S8 *office_num,
            S8 *fax_num,
            S8 *email_addr,
            S8 *ucs2_company,
            S8 *b_day,
            PHB_INFO_FIELDS_STRUCT *info_fields,
            S8 *nick_name);
extern void mmi_vcard_writer_v30_append_name(S8 *object, S8 *temp_buf, S8 *field_name, S8 *field_value);
#endif /* defined(__MMI_VCARD_V30__) */
extern void mmi_vcard_entry_recv_view_detail(void);
extern void mmi_vcard_recv_view_detail_pre_entry(void);
extern void mmi_vcard_recv_abort_vcard(void);
extern BOOL mmi_vcard_recv_parse_file(void);
extern void mmi_vcard_recv_save_obj_to_phb(void);
extern S32 mmi_vcard_recv_move_obj_to_file(void);
extern void mmi_vcard_recv_move_obj_to_file_callback(void *info);

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
extern void mmi_vcard_get_bday_to_buff(U16 store_index, S8 *b_day);
extern U8 mmi_vcard_reader_retrive_bday(S8 *String, S8 *pb_year, S8 *pb_mon, S8 *pb_day, BOOL change_flag);
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
extern S32 mmi_vcard_uti_get_line(S8 *strOutput, FS_HANDLE fh);
extern S32 mmi_vcard_uti_get_single_line(S8 *strOutput, FS_HANDLE fh);
extern U8 mmi_vcard_reader_parse_line(FS_HANDLE fh);
extern U8 mmi_vcard_reader_get_field(S8 *String);
extern U8 mmi_vcard_reader_from_file_path(S8 *path);
extern BOOL mmi_vcard_reader_check_header(S8 *String);
extern BOOL mmi_vcard_reader_check_version(S8 *String);
extern U8 mmi_vcard_reader_retrive_name(S8 *String);
extern U8 mmi_vcard_reader_retrive_number(
            S8 *String,
            S8 *number,
            S8 *home_number,
            S8 *office_number,
            S8 *fax_number);
extern U8 mmi_vcard_reader_retrive_email(S8 *String, S8 *email_address);
extern U8 mmi_vcard_reader_retrive_org(S8 *String, S8 *company_name);
#if defined(__MMI_PHB_INFO_FIELD__)
extern U8 mmi_vcard_reader_retrive_title(S8 *String, S8 *title);
extern U8 mmi_vcard_reader_retrive_url(S8 *String, S8 *url);
extern U8 mmi_vcard_reader_retrive_address(S8 *String, S8 *address);
extern U8 mmi_vcard_reader_retrive_note(S8 *String, S8 *note);
#endif /* defined(__MMI_PHB_INFO_FIELD__) */
extern U8 mmi_vcard_reader_get_para_value(S8 *String, const S8 *para, U8 para_enum, U8 *value);
extern U8 mmi_vcard_reader_get_para_number(S8 *String, U8 *type, U8 *pref);
extern void mmi_vcard_util_remove_field_delimiter(S8 *str, U16 length);

extern void mmi_vcard_util_get_default_file(S8 *path);
extern void mmi_vcard_util_get_default_file_name(S8 *path);
extern void mmi_vcard_util_del_default_file(void);
extern U8 mmi_vcard_util_convert_to_system_encoding(S8 *dest, S8 *src);
extern void mmi_vcard_util_convert_to_ucs2(S8 *dst, U8 dst_size, S8 *src, U8 encode);

#endif /* _MMI_VCARD_H */

