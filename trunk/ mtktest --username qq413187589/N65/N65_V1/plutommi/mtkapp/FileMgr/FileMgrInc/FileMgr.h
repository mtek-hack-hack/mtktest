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
 *  FileMgr.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager Header
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
#ifndef _FILE_MGR_H_
#define _FILE_MGR_H_

#include "gui_data_types.h"
#include "DateTimeType.h"
#include "fmt_def.h"
#include "GlobalConstants.h"
#include "FrameworkStruct.h"
#include "EventsDef.h"

/* Notice - Include "FileSystemDef.h" before this file */
/************************************************************************/
/* Define                                                               */
/************************************************************************/
/* max file size support by file manager */
#define FMGR_MAX_FILE_LEN           (MAX_SUBMENU_CHARACTERS)    /* Same size as menuitem's length */
#define FMGR_MAX_PATH_LEN           (260)
#define FMGR_MAX_EXT_LEN            (5)
#define FMGR_MAX_INPUT_FILE_LEN     (FMGR_MAX_FILE_LEN - FMGR_MAX_EXT_LEN)

/* path buffer size */
#define FMGR_PATH_BUFFER_SIZE       (520)
#define FMGR_PATH_CHAR_COUNT        (259)

/* to keep the parent index for hightlight usage */
#define FMGR_PARENT_INDEX_NUM       (30)

#ifdef __MMI_MAINLCD_128X128__
#define FMGR_MATRIX_COLUMN_NUM      (3)
#define FMGR_MATRIX_ROW_NUM         (2)
#else
#define FMGR_MATRIX_COLUMN_NUM      (3)
#define FMGR_MATRIX_ROW_NUM         (3)
#endif

/* image cache */
/* max number of image cache, actual size is depends on buffer size to cache image */

/* THESE TWO MAX COUNT SHOULD BE FINE TUNE FOR DIFFERENT LCD SIZE */
#define FMGR_THUMB_IMAGE_CACHE_MAX_COUNT        (50)    /* may cache up to 30 images */
#define FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT       (16)    /* may decode up to 12 images on a screen at a time */
#define FMGR_DELAY_DECODER_COUNT                (16)

/* file catch entry */
#ifdef __MMI_SLIM_FILE_MANAGER__
#define FMGR_CACHE_ENTRY_COUNT                  (10)
#else 
#define FMGR_CACHE_ENTRY_COUNT                  (32)
#endif 
#define FMGR_CACHE_SHORT_FILE_LEN               FMGR_MAX_FILE_LEN*ENCODING_LENGTH

typedef enum
{
    FMGR_NAND_STORAGE,
    FMGR_NOR_STORAGE,
#if defined(__DRM_MTK__)
    FMGR_DRM_RO_STORAGE,
#endif 
    FMGR_REMOVABLE_STORAGE,
#ifdef __OTG_ENABLE__
    FMGR_OTG_1_STORAGE,
    FMGR_OTG_2_STORAGE,
    FMGR_OTG_3_STORAGE,
    FMGR_OTG_4_STORAGE,
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
    FMGR_SIM_PLUS_1_STORAGE,
    FMGR_SIM_PLUS_2_STORAGE,
    FMGR_SIM_PLUS_3_STORAGE,
    FMGR_SIM_PLUS_4_STORAGE,
#endif

#ifdef __MSDC2_SD_MMC__
    FMGR_MSDC2_SD_STORAGE,
#endif /* __MSDC2_SD_MMC__ */

    FMGR_TOTAL_STORAGE
} fmgr_drive_enum;

typedef enum
{
    FMGR_NOT_EXIST,
    FMGR_FILENAME_TOO_LONG,
    FMGR_NO_ERROR,
    FMGR_FILE,
    FMGR_FOLDER
} fmgr_attr_enum;

typedef enum
{
    FMGR_DELETE_NONE,
    FMGR_DELETE_SINGLE,
    FMGR_DELETE_FOLDER,
    FMGR_DELETE_ALL,
    FMGR_DELETE_ALL_EXPIRED
} fmgr_delete_enum;

#define FMGR_SELECT_FILE               0x01
#define FMGR_SELECT_FOLDER                   0x02
#define FMGR_SELECT_FILE_OR_FOLDER     0x04
#define FMGR_SELECT_BROWSE             0x08
#define FMGR_SELECT_REPEAT                   0x10
#define FMGR_SELECT_FILE_SET                0x20
#define FMGR_SELECT_ARCHIVE             0x40
#define FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT             0x80

typedef enum
{
    FMGR_ACTION_NONE,
    FMGR_ACTION_FORMAT,
    FMGR_ACTION_CHECK_DRIVE,
    FMGR_ACTION_UNMOUNT,
    FMGR_ACTION_COPY,
    FMGR_ACTION_MOVE,
    FMGR_ACTION_FWD_WALLPAPER,
    FMGR_ACTION_FWD_SUB_WALLPAPER,
    FMGR_ACTION_FWD_SCREENSAVER,
    FMGR_ACTION_FWD_POWER_ON,
    FMGR_ACTION_FWD_POWER_OFF,
    FMGR_ACTION_FWD_PHONEBOOK,
    FMGR_ACTION_FWD_TODOLIST,
    FMGR_ACTION_FWD_PROFILE,
    FMGR_ACTION_FWD_BGSOUND,
    FMGR_ACTION_FWD_SMS,
    FMGR_ACTION_FWD_MMS,
    FMGR_ACTION_FWD_EMS,
    FMGR_ACTION_FWD_EMAIL,
    FMGR_ACTION_FWD_IRDA,
    FMGR_ACTION_FWD_BT,
    FMGR_ACTION_PRINT_TO_PICTBRIGE,
    FMGR_ACTION_PRINT_TO_BLUETOOTH    

} fmgr_tree_action_enum;

typedef enum
{
    FMGR_DRM_GRANT_PERMISSION,
    FMGR_DRM_NO_PERMISSION,
    FMGR_DRM_REQUEST_RIGHTS
} fmgr_drm_status_enum;

typedef enum
{
    FMGR_DRM_NO_FWD_APP_NO_FWD_OUT,
    FMGR_DRM_FWD_APP_NO_FWD_OUT,
    FMGR_DRM_NO_FWD_APP_FWD_OUT,
    FMGR_DRM_FWD_APP_FWD_OUT
} fmgr_drm_forward_enum;

/************************************************************************/
/* Data Structure                                                       */
/************************************************************************/
/* Catch struct */
typedef S16 FMGR_INDEX;

typedef struct
{
    S8 file_name[(FMGR_MAX_FILE_LEN + 1) *ENCODING_LENGTH];
    S8 file_ext[(FMGR_MAX_EXT_LEN + 1) *ENCODING_LENGTH];
    FMGR_FILTER file_type;
    U32 file_size;
    U16 index;
    /* creation date */
    MYTIME time;
    /* file info */
    U8 attribute;
    BOOL is_used;
    BOOL is_short;
    BOOL is_able_display;
} FMGR_FILE_INFO_STRUCT;

/*
 *  Some applcation that wish to access fmgr caching system 
 *  instead of using explorer may directly access these function  
 *  ex: Audio player, Sound Recorder, Image Viewer 
 */

/* callback function for UI Display. For Categories 212, 213, 214 */
extern pBOOL mmi_fmgr_get_drv_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_fmgr_get_drv_hint_callback(S32 item_idx, UI_string_type *hint_array);
extern void mmi_fmgr_draw_drv_info_callback(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_fmgr_hide_drv_info_callback(void);
extern void mmi_fmgr_draw_drv_menuitem_callback(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_fmgr_hide_drv_menuitem_callback(void);

extern pBOOL mmi_fmgr_get_file_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL ebr_get_file_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_fmgr_get_file_hint_callback(S32 item_idx, UI_string_type *hint_array);
extern void mmi_fmgr_draw_file_info_callback(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_fmgr_draw_ebook_file_info_callback(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2);

extern void mmi_fmgr_hide_file_info_callback(void);
extern void mmi_fmgr_draw_file_menuitem_callback(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_fmgr_hide_file_menuitem_callback(void);

extern void mmi_fmgr_draw_file_matrix_callback(
                S32 idx,
                S32 page_start_idx,
                S32 page_end_idx,
                BOOL is_hilighted,
                BOOL is_need_update,
                BOOL is_new_page,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2);
extern void mmi_fmgr_hide_file_matrix_callback(S32 idx);

extern void mmi_fmgr_create_thumb_image_cache(S32 image_size);
extern void mmi_fmgr_free_thumb_image_cache(void);

/* File Manager caching kernal function [Bear] */
extern void mmi_fmgr_kernel_init_by_app(S8 *file_path, FMGR_FILTER filter, U16 *file_count_ptr);
extern void mmi_fmgr_kernel_init(S8 *file_path, FMGR_FILTER filter, U16 *file_count_ptr);
extern void mmi_fmgr_kernel_get_file_info(S32 index, FMGR_FILE_INFO_STRUCT *file_info_ptr);
extern void mmi_fmgr_kernel_get_file_info_ex(S32 index, FMGR_FILE_INFO_STRUCT *file_info_ptr, U8 align_flag);

extern void mmi_fmgr_kernel_get_path_name(S8 *full_path_name);
extern void mmi_fmgr_kernel_hide_ext_name(S8 *str_buf_ptr, FMGR_FILE_INFO_STRUCT *info_ptr);
extern BOOL mmi_fmgr_kernel_delete_all(void);
extern void mmi_fmgr_kernel_load_cache(U16 start_index);
extern U16 mmi_fmgr_kernel_init_continue(
            PS8 path,
            U32 *seq,
            S32 total,
            PU16 cached_num,
            U16 start_index,
            BOOL read_all);
extern U16 mmi_fmgr_kernel_list(S8 *file_path, U16 *cached_num, U16 start_index, BOOL read_all);

extern S32 mmi_fmgr_kernel_get_cur_idx(void);
extern U16 mmi_fmgr_kernel_get_file_count(void);
extern void mmi_fmgr_kernel_move_selection_up(void);
extern void mmi_fmgr_kernel_move_selection_down(void);


#if defined(__DRM_V02__)
extern void mmi_fmgr_mul_odf_kernel_init(S8 *file_path, FMGR_FILTER filter, U16 *file_count_ptr);
extern U16 mmi_fmgr_mul_odf_kernel_list(S8 *file_path, U16 *cached_num, U16 start_index, BOOL read_all);
extern void entry_fmgr_app_browse_multi_odf_menu(void);
extern U16 fmgr_get_app_browse_multi_odf_menu(void);
extern void fmgr_app_mul_odf_goback_history(void);
#endif /* defined(__DRM_V02__) */

/* File Manager Explorer */
extern void mmi_fmgr_init(void);
extern void mmi_fmgr_select_path_and_enter(
                U8 app_id,
                U8 sel_type,
                FMGR_FILTER filter,
                PS8 start_path,
                PsExtFuncPtr callback);
extern void mmi_fmgr_send_copy_req(U8 action, PU8 src_file, PU8 dest_file, PsFuncPtr callback);
extern void mmi_fmgr_send_delete_req(PU8 path, U32 type, PsFuncPtr callback);
extern void mmi_fmgr_send_abort_copy_req(void);

extern void fmgr_delete_rsp_center_hdlr(void *info);
    
/* internal use functions */

extern void fmgr_init_context(void);
extern void fmgr_init_drive(void);
extern void fmgr_launch(void);

extern void highlight_fmgr_drive_list(S32 hiliteID);

extern void highlight_fmgr_drive_open(void);
extern void highlight_fmgr_format(void);
extern void highlight_fmgr_check_drive(void);
extern void highlight_fmgr_unmount(void);
extern void highlight_fmgr_create_folder(void);

extern void highlight_fmgr_app_select(void);
extern void highlight_fmgr_folder_done(void);

extern void highlight_fmgr_node(S32 index);
extern void highlight_fmgr_tree_node(S32 index);

extern void highlight_fmgr_tree_open(void);
extern void highlight_fmgr_view_image(void);
extern void highlight_fmgr_edit_image(void);
extern void highlight_fmgr_play_audio(void);
extern void highlight_fmgr_play_video(void);
extern void highlight_fmgr_execute(void);

extern void highlight_fmgr_open(void);
extern void highlight_fmgr_sort(void);
extern void highlight_fmgr_forward(void);
extern void highlight_fmgr_detail(void);

#if defined(__MMI_EXIF__)
extern void highlight_fmgr_jpg_detail(void);
#endif 
extern void highlight_fmgr_rename(void);
extern void highlight_fmgr_rename_done(void);
extern void highlight_fmgr_delete(void);
extern void highlight_fmgr_delete_all_file(void);
extern void highlight_fmgr_copy(void);
extern void highlight_fmgr_tree_copy(void);
extern void highlight_fmgr_move(void);

extern void highlight_fmgr_sort_by_name(void);
extern void highlight_fmgr_sort_by_type(void);
extern void highlight_fmgr_sort_by_time(void);
extern void highlight_fmgr_sort_by_size(void);
extern void highlight_fmgr_sort_none(void);

extern void highlight_fmgr_to_wallpaper(void);
extern void highlight_fmgr_to_sub_wallpaper(void);
extern void highlight_fmgr_to_screensaver(void);
extern void highlight_fmgr_to_power_on_display(void);
extern void highlight_fmgr_to_power_off_display(void);
extern void highlight_fmgr_to_phb(void);
extern void highlight_fmgr_to_todolist(void);
extern void highlight_fmgr_to_sms(void);
extern void highlight_fmgr_to_ems(void);
extern void highlight_fmgr_to_mms(void);
extern void highlight_fmgr_to_email(void);
extern void highlight_fmgr_to_irda(void);
extern void highlight_fmgr_to_profile(void);
extern void highlight_fmgr_to_bgsound(void);
extern void highlight_fmgr_to_bt(void);

extern void highlight_fmgr_print(void);
extern void entry_fmgr_print_option(void);

extern void highlight_fmgr_print_to_pictbrige(void);
extern void fmgr_print_to_pictbrige(void);
extern void highlight_fmgr_print_to_bluetooth(void);
extern void fmgr_print_to_bluetooth(void);

extern void highlight_fmgr_input_method(void);

extern void entry_fmgr_main(void);
extern void entry_fmgr_explorer(void);
extern void exit_fmgr_explorer(void);

extern void entry_fmgr_drive_option(void);
extern void entry_fmgr_drive_confirm(void);
extern void entry_fmgr_drive_animation(void);
extern void exit_fmgr_drive_animation(void);

extern void entry_fmgr_folder_option(void);
extern void entry_fmgr_file_option(void);
extern void exit_fmgr_file_option(void);

extern void entry_fmgr_tree_option(void);

extern void entry_fmgr_sort_option(void);
extern void exit_fmgr_sort_option(void);
extern void entry_fmgr_forward_option(void);
extern void exit_fmgr_forward_option(void);
extern void fmgr_check_sub_forward_option(FMGR_FILE_INFO_STRUCT *file_info);
extern void exit_fmgr_app_file_option(void);

extern void entry_fmgr_filename_editor(void);
extern void entry_fmgr_editor_option(void);

extern void entry_fmgr_delete_confirm(void);

extern void entry_fmgr_app_drive_option(void);
extern void entry_fmgr_app_folder_option(void);
extern void entry_fmgr_app_file_option(void);
extern void entry_fmgr_app_empty_folder_option(void);

extern void entry_fmgr_tree_explorer(void);
extern void exit_fmgr_tree_explorer(void);

extern void entry_fmgr_detail(void);
#ifdef __DRM_SUPPORT__
extern void entry_fmgr_drm_rights_option(void);
extern void highlight_fmgr_drm_rights_detail(void);
extern void highlight_fmgr_drm_rights_delete_all_expired(void);
extern void fmgr_delete_all_expired_file(void);
extern void mmi_fmgr_send_delete_expired_ro_req(PU8 path, PsFuncPtr callback);
extern void entry_fmgr_rights_detail(void);
#if defined(__DRM_V02__)
extern void highlight_fmgr_open_multi_odf(void);
extern void fmgr_open_mul_odf_hdlr(void);
extern void entry_fmgr_mul_odf_explorer(void);
extern void exit_fmgr_mul_odf_explorer(void);
#endif /* defined(__DRM_V02__) */
#endif /* __DRM_SUPPORT__ */

#if defined(__MMI_EXIF__)
extern void entry_fmgr_jpg_detail(void);
#endif 
extern void entry_fmgr_copy_animation(void);
extern void exit_fmgr_copy_animation(void);
extern void entry_fmgr_delete_animation(void);
extern void exit_fmgr_delete_animation(void);
extern U8 fmgr_delete_animation_callback(void *param);

extern void fmgr_set_curr_path_and_enter(void);
extern void fmgr_set_curr_tree_and_enter(void);
extern void fmgr_back_to_parent(void);
extern void fmgr_back_to_tree_parent(void);

#ifdef __FS_CARD_SUPPORT__
extern void fmgr_msdc_plug_in_hdlr(void *info);
extern void fmgr_msdc_plug_out_hdlr(void *info);
#endif /* __FS_CARD_SUPPORT__ */ 

#ifdef __OTG_ENABLE__
extern void fmgr_otg_display_hdlr(void *info);
#endif 

extern void fmgr_copy_rsp_hdlr(void *info);
extern void fmgr_delete_rsp_hdlr(void *info);
extern void fmgr_send_format_req(U8 drive, U32 level, PsFuncPtr callback);
extern void fmgr_send_check_drive_req(U8 drive, PsFuncPtr callback);
extern void fmgr_send_unmount_req(U8 index, U32 mode, PsFuncPtr callback);
extern void fmgr_drive_rsp_hdlr(void *info);
extern U8 fmgr_drvop_incoming_call_interrupt_hdlr(mmi_frm_int_event_type event_type);

extern void fmgr_view_image_hdlr(void);
extern void fmgr_edit_image_hdlr(void);
extern void fmgr_play_audio_hdlr(void);
extern void fmgr_play_video_hdlr(void);
extern void fmgr_open_ebook_hdlr(void);
extern void fmgr_execute_hdlr(void);
extern void fmgr_create_folder_hdlr(void);
extern void fmgr_rename_hdlr(void);
extern void fmgr_drive_action_hdlr(void);
extern void fmgr_copy_hdlr(void);
extern void fmgr_move_hdlr(void);
extern void fmgr_aux_copy_hdlr(void);

extern void fmgr_sort(void);
extern void fmgr_create_folder(void);
extern void fmgr_rename(void);
extern void fmgr_delete(void);
extern void fmgr_delete_all_file(void);
extern void fmgr_copy(void);
extern void fmgr_move(void);
extern void fmgr_abort_copy_select(void);

extern void fmgr_return_to_app(void);
extern void fmgr_forward_to_app(void);
extern void fmgr_abort_app_select(void);
extern void fmgr_reset_app_select(void);
extern BOOL fmgr_exe_app_call_back(void);   /* used for app that want to exe callback without reset history */
extern void fmgr_add_marker_for_app(U8 app_id);

extern void fmgr_set_sort_option(U16 sort);

extern U16 fmgr_get_app_file_option_menu(FMGR_FILE_INFO_STRUCT *file_info);
extern U16 fmgr_get_file_option_menu(FMGR_FILE_INFO_STRUCT *file_info);
extern U16 fmgr_get_forward_option_menu(FMGR_FILE_INFO_STRUCT *file_info, BOOL *is_drm);

#ifdef __DRM_SUPPORT__
extern S32 fmgr_select_drm_file(void);
extern BOOL fmgr_populate_drm_info(U32 handle, U8 permission, U8 *data);
extern S32 fmgr_check_drm_rights(FMGR_FILE_INFO_STRUCT *file_info, U8 permission);
extern U8 fmgr_get_drm_forward_rule(FMGR_FILE_INFO_STRUCT *file_info, BOOL *is_drm);
extern U8 fmgr_check_drm_forward(PS8 file_path, BOOL *is_drm);
extern void entry_fmgr_request_rights_confirm(void);
extern void entry_fmgr_request_unknown_rights_confirm(void);
extern void fmgr_send_rights_request(void);
extern void fmgr_send_rights_request_ext(void);
#endif /* __DRM_SUPPORT__ */ 

#ifdef __MMI_DOWNLOAD_AGENT__
extern void highlight_fmgr_da_forward(void);
extern void fmgr_receive_da_file(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, PS8 url, PS8 mime_type_string);
extern BOOL fmgr_is_da_file(void);
extern S16 fmgr_get_da_forward_option_menu(S8* filepath);
extern S16 fmgr_get_da_file_option_menu(S8* filepath, FMGR_FILTER *file_type);
extern void entry_fmgr_da_file_option(void);
extern void exit_fmgr_da_file_option(void);
extern void entry_fmgr_da_forward_option(void);
extern S8 delete_fmgr_da_file_option_cb(void *in_param);

#endif /* __MMI_DOWNLOAD_AGENT__ */ 

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#define MMI_THEME_LOCATION  "THEMES\\"

extern void highlight_fmgr_activate_theme(void);
extern void fmgr_Activate_theme(void);
extern void fmgr_move_theme_file(void);
extern U8 mmi_activatetheme_frmfilemanager(PS8 path, PS8 filename, MMI_BOOL is_short);
extern void fmgr_display_themepopUp(void);
extern void fmgr_theme_move_rsp(void *);

extern void fmgr_theme_single_delete(void);
extern void fmgr_display_theme_delte_popUp(void);
extern U16 is_mmi_theme_file_active(PS8 file_name);
extern void fmgr_theme_delete_highlight(void);
extern S16 get_storage_type(PS8 path);
extern U16 check_file_location(PS8 path);

extern void theme_folder_delete_rsp_hdlr(void *info);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#ifdef __MMI_IRDA_SUPPORT__
extern void entry_fmgr_send_irda(void);
extern void fmgr_forward_to_irda_callback(void *buf_p, U32 result);
#endif /* __MMI_IRDA_SUPPORT__ */ 

#ifdef FMGR_USING_CACHE
extern void mmi_fmgr_get_fmgr_cache_struct (void** image_cache_list_buffer_p,
                                     void** image_handle_list_buffer_p,
                                     void** image_cache_p,
                                     void** delay_decoder_p);
#endif
extern void fmgr_hide_fwd_app_menu(FMGR_FILTER *file_type);
extern void fmgr_unhide_fwd_app_menu(void);

extern U16 fmgr_get_app_title_icon_id(void);
extern U8 fmgr_is_msdc_present(void);
extern U8 fmgr_get_msdc_mask(void);
extern pBOOL fmgr_is_parent_present(void);
extern U8 fmgr_check_file_present(void);
extern S8 fmgr_get_drive_index(S32 hiliteID);
extern void fmgr_return_to_editor(void);
extern void fmgr_adjust_history(S32 scrnId);
extern void fmgr_remove_all_screen(void);
extern U8 fmgr_construct_filter_pattern(void);
extern S32 fmgr_get_parent_highlight_id(void);

extern void highlight_fmgr_goto_bookmark(void);
extern void fmgr_goto_bookmark_hdlr(void);

#ifdef __MMI_VBOOKMARK__ 
extern void highlight_fmgr_vbookmark_goto(void);
extern void fmgr_vbookmark_goto_hdlr(void);

extern void highlight_fmgr_vbookmark_open(void);
extern void fmgr_vbookmark_open_hdlr(void);
#endif /* #ifdef __MMI_VBOOKMARK__ */

extern void mmi_fmgr_copy_new_file_path_after_app_move(S8* new_file_path);

extern void mmi_fmgr_kernel_add_hash_item_for_parent_idx_cache(void);
extern S32 mmi_fmgr_kernel_get_hash_item_for_parent_idx_cache(void);
extern S32 mmi_fmgr_kernel_hash_func_for_parent_idx_cache(PS8 data_info, U16 len);
#endif /* _FILE_MGR_H_ */ 

