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
 * BrowserBookmarks.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *	This file contains declaration of all the functions that are being used in the 
 *  implementation of Bookmarks.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSERBOOKMARKS_H
#define BROWSERBOOKMARKS_H

#include "MMI_features.h"

#if defined(__MMI_BROWSER_2__) && defined(__MMI_VBOOKMARK__)
#include "MMIDataType.h"
#include "FileMgr.h"
#include "BrowserTypes.h"
#include "FileManagerGProt.h"
#include "RtFiles.h"
#include "Fs_internal.h"


#define BRW_DEFAULT_BKM_SUPPORT

#define BRW_BKM_DEFAULT_DRIVE						MMI_SYSTEM_DRV
#define BRW_BKM_DEFAULT_FOLDER_NAME					L"vbookmarks"
#define BRW_BKM_FILE_EXTN_MAX_COUNT					3
#define BRW_BKM_FILE_EXTN_DFT_STRING				L"dft"
#define BRW_BKM_FILE_EXTN_URL_STRING				L"url"
#define BRW_BKM_FILE_EXTN_VBM_STRING				L"vbm"
#define BRW_BKM_FILE_SEARCH_PATTERN_DFT				L"*.dft"
#define BRW_BKM_FILE_SEARCH_PATTERN_URL				L"*.url"
#define BRW_BKM_FILE_SEARCH_PATTERN_VBM				L"*.vbm"
#define BRW_BKM_USER_CREATED_FILE_DEFAULT_EXTN		BRW_BKM_FILE_EXTN_URL_STRING
#define BRW_BKM_MAX_FILE_NAME_LEN					FMGR_MAX_FILE_LEN - 1 /*subtracting 1 to sync it with file manager*/
#define BRW_BKM_MAX_PATH_LEN						FMGR_MAX_PATH_LEN + BRW_BKM_MAX_FILE_NAME_LEN + 1
#define BRW_BKM_MAX_INPUT_FILE_NAME_LEN				FMGR_MAX_INPUT_FILE_LEN - 1 /*subtracting 1 to sync it with file manager*/
#define BRW_BKM_MAX_FILE_EXTN_LEN					FMGR_MAX_EXT_LEN
#define BRW_BKM_VIEW_BOOKMARK_ITEM_COUNT			2
#define BRW_BKM_DEFAULT_FILE_NAME					L"default"
#define BRW_BKM_DEFAULT_FILE_EXTN					BRW_BKM_USER_CREATED_FILE_DEFAULT_EXTN
#define BRW_BKM_AVERAGE_FILENAME_LENGTH				11
#define BRW_BKM_DRIVE_NAME_LENGTH					5

#define BRW_BKM_ADD_BOOKMARK_ITEM_COUNT				2
#define BRW_BKM_EDIT_BOOKMARK_ITEM_COUNT			2
#define BRW_BKM_FOLDER_QUOTA					    100*1024
#define BRW_BKM_FILE_SIZE                           2*1024
#define BRW_BKM_MAX_DIR_DEPTH						(RECCONF_DIRSTACK_SIZE / sizeof(RTFDirEntry))

typedef enum
{
	BRW_BKM_FOLDER = 0,
	BRW_BKM_RO_FOLDER,
	BRW_BKM_DEFAULT_FILE,
	BRW_BKM_USER_CREATED_FILE
} brw_bkm_file_types_enum;

typedef enum
{
	BRW_BKM_FILE_EXTN_NONE = 0,
	BRW_BKM_FILE_EXTN_DFT,
	BRW_BKM_FILE_EXTN_URL,
	BRW_BKM_FILE_EXTN_VBM,
	BRW_BKM_FILE_EXTN_TOTAL
} brw_bkm_file_extension_types_enum;

typedef enum
{
	BRW_BKM_BROWSE_PATH_NONE = 0,
	BRW_BKM_BROWSE_PATH_COPY_TO,
	BRW_BKM_BROWSE_PATH_MOVE_TO
} brw_bkm_browse_path_enum;

typedef enum
{
	BRW_BKM_FROM_NONE = 0,
	BRW_BKM_FROM_FILE_MANAGER,
	BRW_BKM_FROM_VBOOKMARK
} brw_bkm_calling_module_type_enum;

typedef enum
{
	BRW_BKM_ADD_BOOKMARK = 0,
	BRW_BKM_ADD_TO_BOOKMARK
} brw_bkm_add_bookmark_enum;

typedef enum
{
    BRW_ADD_TO_BKM_SUCCESS = 0,
    BRW_ADD_TO_BKM_INVALID_URL,
    BRW_ADD_TO_BKM_INVALID_TITLE,
    BRW_ADD_TO_BKM_FILE_SYSTEM_ERROR,
    BRW_ADD_TO_BKM_MEMORY_FULL
} brw_add_to_bkm_err_enum;

typedef struct
{
	U8	file_extn;
}brw_bkm_file_info_struct;

typedef struct
{
	U8 default_drive_name[BRW_BKM_DRIVE_NAME_LENGTH * ENCODING_LENGTH];
	U8 default_folder_path[(BRW_BKM_MAX_PATH_LEN+1) * ENCODING_LENGTH];
	U8 sel_folder_path[(BRW_BKM_MAX_PATH_LEN+1) * ENCODING_LENGTH];
	U8 sel_file_path[(BRW_BKM_MAX_PATH_LEN+1) * ENCODING_LENGTH];
	U8 sel_file_name[(BRW_BKM_MAX_FILE_NAME_LEN+1) * ENCODING_LENGTH];
	U8 sel_file_extn[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
	U8 sel_file_url[(BRW_MAX_URL_LENGTH+1) * ENCODING_LENGTH];
	S32 sel_file_index;
	U32 index_highlighted_item;
	brw_bkm_file_info_struct *file_info_list;
	U32 total_file_count;
}brw_bkm_context_struct;

typedef struct
{
	U8 sel_folder_path[(BRW_BKM_MAX_PATH_LEN+1) * ENCODING_LENGTH];
	U8 sel_folder_name[(BRW_BKM_MAX_FILE_NAME_LEN+1) * ENCODING_LENGTH];
	S32 sel_folder_index;
	U32 total_folder_count;
	U32 index_highlighted_item;
}brw_bkm_browse_path_context_struct;

extern brw_bkm_context_struct g_brw_bkm_cntx;
extern brw_bkm_browse_path_context_struct g_brw_bkm_browse_path_cntx;
extern brw_bkm_browse_path_enum g_brw_bkm_browse_path_event;
extern brw_bkm_add_bookmark_enum g_brw_bkm_add_type; 
extern MMI_BOOL g_brw_bkm_sel_bkm_pool;

/*Highlight Handlers*/
extern void mmi_brw_bookmarks_highlight_handlers_init(void);
extern void mmi_brw_bookmarks_send_bookmark_highlight_handlers_init(void);
extern void mmi_brw_bookmarks_highlight_hdlr(void);
extern void mmi_brw_bookmarks_open_folder_highlight_hdlr(void);
extern void mmi_brw_bookmarks_delete_folder_highlight_hdlr(void);
extern void mmi_brw_bookmarks_goto_highlight_hdlr(void);
extern void mmi_brw_bookmarks_view_highlight_hdlr(void);
extern void mmi_brw_bookmarks_edit_highlight_hdlr(void);
extern void mmi_brw_bookmarks_delete_highlight_hdlr(void);
extern void mmi_brw_bookmarks_delete_all_user_files_highlight_hdlr(void);
extern void mmi_brw_bookmarks_add_bookmark_highlight_hdlr(void);
extern void mmi_brw_bookmarks_set_as_homepage_highlight_hdlr(void);
extern void mmi_brw_bookmarks_send_bookmark_highlight_hdlr(void);
extern void mmi_brw_bookmarks_create_folder_highlight_hdlr(void);
extern void mmi_brw_bookmarks_copy_to_highlight_hdlr(void);
extern void mmi_brw_bookmarks_move_to_highlight_hdlr(void);
extern void mmi_brw_bookmarks_memory_status_highlight_hdlr(void);
extern void mmi_brw_bookmarks_add_bookmark_items_highlight_hdlr(S32 index);
extern void mmi_brw_bookmarks_edit_bookmark_items_highlight_hdlr(S32 index);
extern void mmi_brw_bookmarks_view_bookmark_items_highlight_hdlr(S32 index);
extern void mmi_brw_bookmarks_browse_path_select_folder_highlight_hdlr(void);
extern void mmi_brw_bookmarks_browse_path_open_folder_highlight_hdlr(void);
extern void mmi_brw_bookmarks_browse_path_create_folder_highlight_hdlr(void);
extern void mmi_brw_bookmarks_send_bookmark_as_sms_highlight_hdlr(void);
extern void mmi_brw_bookmarks_send_bookmark_as_mms_highlight_hdlr(void);
extern void mmi_brw_bookmarks_send_bookmark_via_infrared_highlight_hdlr(void);
extern void mmi_brw_bookmarks_send_bookmark_via_bluetooth_highlight_hdlr(void);
extern void mmi_brw_bookmarks_send_bookmark_via_email_highlight_hdlr(void);
extern void mmi_brw_bookmarks_save_to_bookmark_items_highlight_hdlr(S32 item_index);
extern void mmi_brw_bookmarks_open_goto_from_fmgr_highlight_hdlr(void);
extern void mmi_brw_bookmarks_open_edit_from_fmgr_highlight_hdlr(void);
extern void mmi_brw_bookmarks_open_save_to_bookmark_from_fmgr_highlight_hdlr(void);
extern void mmi_brw_bookmarks_select_bookmark_highlight_hdlr(S32 item_index);
extern void mmi_brw_bookmarks_create_folder_editor_done_option_highlight_hdlr(void);
/*Highlight Handlers*/

extern void mmi_brw_bookmarks_pre_entry_edit(void);
extern void mmi_brw_bookmarks_entry_options(void);
extern void mmi_brw_bookmarks_pre_entry_add_bookmark(void);
extern void mmi_brw_bookmarks_entry_add_bookmark(void);
extern void mmi_brw_bookmarks_entry_create_folder(void);
extern void mmi_brw_bookmarks_exit_add_bookmark(void);
extern void mmi_brw_bookmarks_entry_edit(void);
extern void mmi_brw_bookmarks_exit_edit(void);
extern void mmi_brw_bookmarks_entry_view(void);
extern void mmi_brw_bookmarks_exit_view(void);
extern void mmi_brw_bookmarks_entry_browse_path(void);
extern void mmi_brw_bookmarks_browse_path_entry_options(void);
extern void mmi_brw_bookmarks_entry_save_to_bookmark(void);
extern void mmi_brw_bookmarks_exit_save_to_bookmark(void);
extern void mmi_brw_bookmarks_entry_open_from_fmgr(void);
extern void mmi_brw_bookmarks_pre_entry_save_to_bookmark(void);
extern void mmi_brw_bookmarks_entry_select_bookmark(void);
extern void mmi_brw_bookmarks_entry_send_bookmark(void);
extern void mmi_brw_bookmarks_entry_show_list(void);
extern void mmi_brw_bookmarks_pre_entry_show_list(void);
extern void mmi_brw_pre_entry_edit_bookmark(void);
extern void mmi_brw_exit_add_bookmark_screen_for_all(void);
extern void mmi_brw_bookmarks_pre_entry_options(void);
extern void mmi_brw_bookmarks_browse_path_pre_entry_options(void);
extern void mmi_brw_bookmarks_pre_entry_create_folder(void);
extern void mmi_brw_bookmarks_pre_entry_edit_from_fmgr(void);
extern void mmi_brw_bookmarks_entry_edit_from_fmgr(void);
extern void mmi_brw_bookmarks_exit_edit_from_fmgr(void);

extern void mmi_brw_bookmarks_context_init(void);
extern void mmi_brw_bookmarks_goto(void);
extern void mmi_brw_bookmarks_delete_file_confirm(void);
extern void mmi_brw_bookmarks_delete_all_user_files_confirm(void);
extern void mmi_brw_bookmarks_set_as_homepage(void);
extern void mmi_brw_bookmarks_copy_to(void);
extern void mmi_brw_bookmarks_move_to(void);
extern void mmi_brw_bookmarks_delete_file(void);
extern void mmi_brw_bookmarks_delete_all_user_files_confirm(void);
extern void mmi_brw_bookmarks_delete_all_user_files(void);
extern void mmi_brw_bookmarks_create_folder(void);
extern void mmi_brw_bookmarks_memory_status(void);
extern void mmi_brw_bookmarks_fill_inline_struct_for_add_bookmark(void);
extern void mmi_brw_bookmarks_fill_inline_struct_for_view_bookmark(void);
extern void mmi_brw_bookmarks_add_bookmark_confirm(void);
extern void mmi_brw_bookmarks_add_bookmark(void);
extern void mmi_brw_bookmarks_edit_bookmark_confirm(void);
extern void mmi_brw_bookmarks_edit_bookmark(void);
extern void mmi_brw_bookmarks_copy_to_callback(void*, int);
extern void mmi_brw_bookmarks_move_to_callback(void*, int);

extern void mmi_brw_bookmarks_full_screen_edit(void);
extern void mmi_brw_change_label_highlight_hdlr(S32 index);
extern void mmi_brw_read_bookmark_from_nvram(void);
extern void mmi_brw_write_bookmark_to_nvram(void);
extern void mmi_brw_calculate_number_of_bookmarks_stored(void);
extern void mmi_brw_bookmarks_add_bookmark_save(void);
extern void mmi_brw_bookmarks_confirm_dialog_GoBackHistory(void);
extern pBOOL mmi_brw_bookmark_list_get_item(S32, UI_string_type, PU8 *, U8);
extern void mmi_brw_goto_highlighted_bookmark(void);

extern U32 mmi_brw_bookmarks_get_file_and_folder_count(U8* bkm_folder_path);
extern U32 mmi_brw_bookmarks_get_only_folder_count(U8* bkm_folder_path);
extern pBOOL mmi_brw_bookmarks_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_bookmarks_folder_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern brw_bkm_file_extension_types_enum mmi_brw_bookmarks_get_file_extn(U8* filename);
extern void mmi_brw_bookmarks_allocate_file_info_list(void);
extern void mmi_brw_bookmarks_file_list_go_back_history(void);
extern void mmi_brw_bookmarks_open_folder(void);
extern void mmi_brw_bookmarks_delete_folder(void);
extern void mmi_brw_bookmarks_get_file_extn_string(U8 file_extn, U8* file_extn_string);
extern void mmi_brw_bookmarks_delete_folder_confirm(void);
extern void mmi_brw_bookmarks_file_system_error_handler(S32 error_code);
extern void mmi_brw_bookmarks_replace_file_confirm(void);
extern void mmi_brw_bookmarks_add_bookmark_replace_file(void);
extern void mmi_brw_bookmarks_edit_bookmark_replace_file(void);
extern void mmi_brw_bookmarks_browse_path_go_back_history(void);
extern void mmi_brw_bookmarks_browse_path_select_folder(void);
extern void mmi_brw_bookmarks_browse_path_open_folder(void);
extern void mmi_brw_bookmarks_copy_bookmark_file_rsp(void *info);
extern void mmi_brw_bookmarks_move_bookmark_file_rsp(void *info);
extern void mmi_brw_bookmarks_browse_path_replace_file(void);
extern void mmi_brw_bookmarks_send_bookmark_as_sms(void);
extern void mmi_brw_bookmarks_send_bookmark_as_mms(void);
extern void mmi_brw_bookmarks_send_bookmark_via_infrared(void);
extern void mmi_brw_bookmarks_send_bookmark_via_bluetooth(void);
extern void mmi_brw_bookmarks_send_bookmark_via_email(void);
extern MMI_BOOL mmi_brw_bookmarks_standardize_file_before_sending(void);
extern void mmi_brw_bookmarks_send_bookmark_as_sms_callback(void*);
extern void mmi_brw_bookmarks_send_bookmark_as_mms_callback(void);
extern void mmi_brw_bookmarks_send_bookmark_via_infrared_callback(void*, U32);
extern void mmi_brw_bookmarks_send_bookmark_via_bluetooth_callback(void *, U32);
extern void mmi_brw_bookmarks_send_bookmark_via_email_callback(void);
extern MMI_BOOL mmi_brw_bookmarks_extract_filename_without_extn_from_filepath(U8* file_path, U8* file_name);
extern MMI_BOOL mmi_brw_bookmarks_extract_filename_with_extn_from_filepath(U8* file_path, U8* file_name);
extern MMI_BOOL mmi_brw_bookmarks_extract_file_extn_from_filepath(U8* file_path, U8* file_extn);
extern MMI_BOOL mmi_brw_bookmarks_extract_file_directory_from_filepath(U8* file_path, U8* file_dir);
extern void mmi_brw_bookmarks_copy_recv_file_to_dest_rsp(void *info);
extern void mmi_brw_bookmarks_copy_recv_file_to_dest(U8* src_file_path, U8* dest_file_path);
extern void mmi_brw_bookmarks_recv_file_save_to_fmgr_callback(void *fullname, int is_short);
extern MMI_BOOL mmi_brw_bookmarks_validate_filename(U8* filename);
extern void mmi_brw_bookmarks_open_goto_from_fmgr(void);
extern void mmi_brw_bookmarks_open_save_to_bookmark_from_fmgr(void);
extern void mmi_brw_bookmarks_save_to_bookmark(void);
extern void mmi_brw_bookmarks_add_to_bookmark(void);
extern void mmi_brw_bookmarks_GoBackHistory(void);
extern void mmi_brw_bookmarks_free_memory(void);
extern void mmi_brw_bookmarks_pre_entry_select_bookmark(void);
extern void mmi_brw_bookmarks_select_bookmark_open_folder(void);
extern void mmi_brw_bookmarks_select_bookmark_done(void);
extern void mmi_brw_select_bookmark_rsp(U8);
extern void mmi_brw_bookmarks_select_bookmark_go_back_history(void);
extern S16 mmi_brw_bookmarks_add_to_bookmark_silently(void);
extern S32 mmi_brw_bookmarks_get_available_memory(void);
extern void mmi_brw_bookmarks_select_bookmark_asm_memory_pool_request_success_callback(void);
extern void mmi_brw_bookmarks_create_default_bkms(void);
extern void mmi_brw_bookmarks_open_folder_or_show_options(void);
extern void mmi_brw_bookmarks_browse_path_open_folder_directly(void);
extern S16 mmi_brw_bookmarks_get_folder_depth(U8* folder_path);
extern MMI_BOOL mmi_brw_bookmarks_check_available_memory(void);
extern U32 mmi_brw_bookmarks_get_highlight_item(U8* sel_folder_path, U8* sel_file_name);
extern void mmi_brw_bookmarks_edit_bookmark_from_fmgr_confirm(void);
extern void mmi_brw_bookmarks_edit_bookmark_from_fmgr_confirm_dialog_GoBackHistory(void);
extern void mmi_brw_bookmarks_use_now_save_to_bookmark(void *fullname, int is_short);
extern void mmi_brw_bookmarks_edit_bookmark_from_fmgr(void);
extern void mmi_brw_bookmarks_edit_bookmark_from_fmgr_replace_file_confirm(void);
extern void mmi_brw_bookmarks_edit_bookmark_from_fmgr_replace_file(void);

/*Interfaces of other external modules*/
extern void mmi_ems_vobject_send_by_ems(U16 scrport, U16 dstport, S8 *filepath, PsFuncPtr callback);
extern MMI_BOOL mmi_vbkm_writer_convert_file_to_internal_format(FS_HANDLE file_handle, U8* url);
extern MMI_BOOL mmi_vbkm_writer_convert_file_to_standard_format(FS_HANDLE file_handle, U8* title, U8* url);
extern MMI_BOOL mmi_vbkm_reader_validate_file(FS_HANDLE fh);
extern void mmi_vbkm_reader_extract_url(FS_HANDLE fh, U8* url);
extern void mmi_vbkm_clean_one_file_buffer(void);
extern void mmi_brw_entry_dummy_screen(void);
/*Interfaces of other external modules*/

#endif /* __MMI_BROWSER_2__ */ 
#endif /* BROWSERBOOKMARKS_H */ 

