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
 * vBookmark.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sending and receving vbookmark object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VBOOKMARK_H
#define _MMI_VBOOKMARK_H

#if defined(__MMI_VBOOKMARK__)

/* if some header should be include before this one */
#include "fs_type.h"
#include "vObjects.h"

/* 
 * Typedef 
 */
typedef enum
{
    VBKM_FIELD_BEGIN,
    VBKM_FIELD_VERSION,
    VBKM_FIELD_TITLE,
    VBKM_FIELD_URL,
    VBKM_FIELD_XIRMC,
    VBKM_FIELD_IS,
    VBKM_FIELD_END,
    VBKM_FIELD_TOTAL
} vbkm_field_enum;

typedef enum
{
    VBKM_SUB_FIELD_VBKM,
    VBKM_SUB_FIELD_ENV,
    VBKM_SUB_FIELD_CHARSET,
    VBKM_SUB_FIELD_ENCODING,
    VBKM_SUB_FIELD_TOTAL
} vbkm_sub_field_enum;

typedef enum
{
    VBKM_PARSE_NO_ERROR=0,
    VBKM_BEGIN_ERROR,
    VBKM_URL_ERROR,
    VBKM_END_ERROR,
    VBKM_PARSE_UNKNOWN_ERROR
} vbkm_parse_enum;

typedef enum
{
    VBKM_RECV_VIA_SMS,
    VBKM_RECV_VIA_BT,
    VBKM_RECV_VIA_IRDA
} vbkm_recv_medium_type_enum;

/* 
 * Define
 */
#define VBKM_VERSION_1_0			"1.0"
#define VBKM_VERSION				VBKM_VERSION_1_0
#define VBKM_CHAR_SET				"UTF-8"
#define VBKM_ENCODING				"QUOTED-PRINTABLE"

#define VBKM_MAX_FILENAME_LENGTH	VOBJ_MAX_FILENAME_LENGTH/ENCODING_LENGTH
#define VBKM_MAX_PATH_LENGTH		VOBJ_MAX_PATH_LENGTH/ENCODING_LENGTH
#define VBKM_MAX_FILE_EXT_LEN		VOBJ_MAX_FILE_EXT_LEN/ENCODING_LENGTH
#define VBKM_MAX_URL_LENGTH			255
#define VBKM_WRITER_FIELD_BUFFER	1024
#define VBKM_READER_FIELD_BUFFER	1024
#define VBKM_DEFAULT_FILE_EXTN		L"url"
#define VBKM_UTF8_ENCODING_LENGTH	3

#define  VBKM_COLON_SEP				":"
#define  VBKM_SEMI_COLON_SEP		";"
#define  VBKM_EQUALITY_SEP			"="
#define  VBKM_LINE_BREAK			"\r\n"

#define  VBKM_TEMP_FILE_NAME		L"temp"

/* 
 * Extern Global Variable
 */
typedef struct
{
	U8 file_path[(VBKM_MAX_PATH_LENGTH+1) * ENCODING_LENGTH];
}vbkm_context_struct;

typedef struct
{
	U8 file_name[(VBKM_MAX_FILENAME_LENGTH) * ENCODING_LENGTH];
	U8 file_extn[(VBKM_MAX_FILE_EXT_LEN) * ENCODING_LENGTH];
}vbkm_recv_file_info_struct;

//struct tag_vbkm_recv_file_info_list_struct;

typedef struct 
{
	vbkm_recv_file_info_struct file_info;
	struct vbkm_recv_file_info_list_struct* nextNode;
}vbkm_recv_file_info_list_struct;

/* 
 * Extern Global Function
 */

#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */ 

#if defined(__MMI_MMS__)
#endif /* defined(__MMI_MMS__) */ 

#if defined(__MMI_IRDA_SUPPORT__)
#endif /* defined(__MMI_IRDA_SUPPORT__) */ 

#if defined(__MMI_OPP_SUPPORT__)
#endif /* defined(__MMI_OPP_SUPPORT__) */ 

#if defined(__MMI_EMAIL__)
#endif /* defined(__MMI_EMAIL__) */ 


/* 
 * Parsing Function
 */
extern MMI_BOOL mmi_vbkm_reader_validate_file(FS_HANDLE fh);
extern void mmi_vbkm_reader_extract_url(FS_HANDLE fh, U8* url);
extern void mmi_vbkm_reader_extract_title(FS_HANDLE fh, U8* title);
extern MMI_BOOL mmi_vbkm_writer_convert_file_to_internal_format(FS_HANDLE fh, U8* url);
extern MMI_BOOL mmi_vbkm_writer_convert_file_to_standard_format(FS_HANDLE fh, U8* title, U8* url);
extern U8 mmi_vbkm_reader_get_field(S8 *String);
extern U8 mmi_vbkm_reader_check_header(S8 *String);
extern MMI_BOOL mmi_vbkm_reader_get_single_line(S8 *strOutput, FS_HANDLE fh);
extern S32 mmi_vbkm_reader_get_line(S8 *strOutput, FS_HANDLE fh);
extern MMI_BOOL mmi_vbkm_reader_check_URL(S8 *string);
extern void mmi_vbkm_reader_get_title_string(S8 *inBuff, U8* title);

/* 
 * Forward Function
 */
/*extern void mmi_vbookmark_entry_forward_option(void);
extern void mmi_vbookmark_exit_forward_option(void);
extern void mmi_vbookmark_highlight_forward_sms(void);
extern void mmi_vbookmark_forward_sms(void);
extern void mmi_vbookmark_forward_sms_call_back(void *flag);
extern void mmi_vbookmark_highlight_forward_mms(void);
extern void mmi_vbookmark_forward_mms(void);
extern void mmi_vbookmark_highlight_forward_irda(void);
extern void mmi_vbookmark_forward_irda(void);
extern void mmi_vbookmark_forward_irda_callback(void *buf_p, U32 result);
extern void mmi_vbookmark_highlight_forward_bt(void);
extern void mmi_vbookmark_forward_bt(void);
extern void mmi_vbookmark_forward_bt_callback(void *buf_p, U32 result);
extern void mmi_vbookmark_highlight_forward_email(void);
extern void mmi_vbookmark_forward_email(void);
extern void mmi_vbookmark_highlight_forward_fmgr(void);
extern void mmi_vbookmark_forward_fmgr(void);
extern void mmi_vbookmark_pre_entry_forward_option(U8* file_path);*/
extern void mmi_vbkm_fmgr_sms_forward(S8 *path);
extern U8 mmi_vbkm_reader_check_file_syntax(FS_HANDLE fh);
extern void mmi_vbkm_reader_get_URL_string(S8 *inBuff, U8* url);

/* 
 * Receive Function
 */
#if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)
extern void mmi_vbkm_recv_file_save_to_fmgr_highlight_hdlr(void);
extern void mmi_vbkm_recv_file_save_to_fmgr(void);
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__) */
extern void mmi_vbkm_recv_file_view_highlight_hdlr(void);
extern void mmi_vbkm_recv_file_save_to_bookmark_highlight_hdlr(void);
extern void mmi_vbkm_recv_file_view(void);
extern void mmi_vbkm_recv_file_save_to_bookmark(void);
extern void mmi_vbkm_recv_file_pre_entry_options(void);
extern void mmi_vbkm_recv_file_entry_options(void);
extern void mmi_vbkm_recv_file_save_to_fmgr_callback(void *fullname, int is_short);
extern void mmi_vbkm_recv_file_view_copy_rsp(void *info);

/* 
 * Other Function
 */
extern void mmi_vbkm_init(void);
extern void mmi_vbkm_deinit(void);
extern U8 mmi_vbkm_util_convert_to_system_encoding(S8 *dst, S8 *src);
extern void mmi_vbkm_util_convert_to_ucs2(S8 *dst, U8 dst_size, S8 *src, U8 encode);
extern void mmi_vbkm_util_replace_filename_in_filepath(U8* file_path, U8* filename);
extern void mmi_vbkm_clean_one_file_buffer(void);
extern void mmi_vbkm_util_get_filename_and_extn(U8* file_path, U8* filename, U8* file_extn);
extern void mmi_vbkm_recv_file_save_file_info(U8* file_path, vbkm_recv_medium_type_enum med_type);
extern void mmi_vbkm_util_convert_str_to_printable_form(S8* printable_str, S8* actual_str);

/*Exported APTs*/
extern MMI_BOOL mmi_vbkm_reader_is_vbookmark_file(S8* file_path);
/*Exported APTs*/

/*Imported APTs*/
extern void mmi_brw_bookmarks_recv_file_save_to_fmgr(U8* file_path, U8* file_name, U8* file_extn);
extern void mmi_brw_bookmarks_recv_file_view(U8* file_path, U8* file_name);
extern void mmi_brw_bookmarks_recv_file_save_to_bookmark(U8* file_path, U8* file_name, U8* file_extn);
extern MMI_BOOL mmi_brw_bookmarks_check_available_memory(void);
/*Imported APTs*/

#endif /* defined(__MMI_VBOOKMARK__) */ /* END #if defined(__MMI_VBOOKMARK__) */
#endif /* _MMI_VBOOKMARK_H */

