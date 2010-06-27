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
 *  FileManagerGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager exposed functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __FILE_MANAGER_GPROT_H_
#define __FILE_MANAGER_GPROT_H_

#include "wgui.h"
#include "fmt_def.h"
#include "filemgr.h"

extern kal_wchar CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME[];
extern kal_wchar CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME[];
/****************************************************************************
* Define                                                            
*****************************************************************************/
/*
 * NOR flash:  Small size (e.g. 512K, 2Mb). 
 * Reliable.
 * NAND flash: Large size (e.g 128Mb).
 * Unreliable. (It might read incorrect data from bad blocks without returning error code) 
 * I/O operations might be blocked for a longer period (10~20 seconds) in garbage collection.
 * User applications need to handle FS_BAD_SECTOR on writing a file.
 * It might contain bad blocks in FAT table and need to be low-level formated in worst case.
 */

/************* Drive names on phone ***************/
/* 
 * Note: the following MACRO need not necessarily map to distinct actual drive names.
 * For example, MMI_SYSTEM_DRV might be equal to MMI_PRIVATE_DRV
 */

/*
 * Invisble in USB mode, NOR flash, fast but (possibly) smaller.
 *
 * Typically used to store important system internal data
 */
#define MMI_SYSTEM_DRV  FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE )

/*
 * Invisible in USB mode
 * NAND flash or NOR flash
 * Large size if it is on NAND flash.
 *
 * Typically used to store data that should be invisible in USB mode. 
 * (e.g. DRM files, thumbnail image cache)
 */
#define MMI_PRIVATE_DRV  FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_ONLY_ALT_SERIAL )

/*
 * Visible in USB mode if the phone has visible partitions.
 * NAND flash or NOR flash
 * Large size if it is on NAND flash.
 *
 * Typically used to store large data such as Camera pictures, voice memo, ...
 */
#define MMI_PUBLIC_DRV  FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)

/***************** Drive names on card ***************/
/* 
 * Memory Card 
 * Visible in USB mode
 * NAND flash
 *
 * MMI_CARD_DRV < 0 if the configuration does not contain any memory card.
 */
#define MMI_CARD_DRV    FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)

#define MMI_CARD2_DRV    FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)

#define WAP_SYSTEM_DRV  MMI_SYSTEM_DRV  /* drive name for wap */

#define FMGR_MAX_DRIVE_NAME_LEN  16

/* default path */
#define FMGR_DEFAULT_FOLDER_IMAGES     CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME
#define FMGR_DEFAULT_FOLDER_AUDIO      CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME

#ifdef __MMI_EBOOK_READER__
#ifdef __MMI_MY_FAVORITE__
#define FMGR_DEFAULT_FOLDER_EBOOKS     L"Others\\Ebook\\"
#else
#define FMGR_DEFAULT_FOLDER_EBOOKS     L"Ebook\\"
#endif /* #ifdef __MMI_MY_FAVORITE__ */
#endif  /* __MMI_EBOOK_READER__ */

#ifdef __MMI_MY_FAVORITE__
#define FMGR_DEFAULT_FOLDER_PHOTOS     L"Images\\Photos\\"
#else
#define FMGR_DEFAULT_FOLDER_PHOTOS     L"Photos\\"
#endif /* __MMI_MY_FAVORITE__ */

#ifdef __MMI_MY_FAVORITE__
#define FMGR_DEFAULT_FOLDER_RECEIVED     L"Others\\"
#else
#define FMGR_DEFAULT_FOLDER_RECEIVED   L"Received\\"
#endif /* __MMI_MY_FAVORITE__ */

#define FMGR_DEFAULT_FOLDER_VIDEO      L"Videos\\"  

#define FMGR_DEFAULT_FOLDER_SWFLASH    L"SWFlash\\"

#define FMGR_DEFAULT_FOLDER_LANGLN    L"Englishto\\"

/* would be hidden, and created by download agent */
#define FMGR_DEFAULT_FOLDER_TEMP       L"Download\\"
/* Leo add for DLT */
#define FMGR_DEFAULT_FOLDER_THEMES     L"Themes\\"
#define FMGR_DEFAULT_FOLDER_BARCODE    L"DATA\\"
/* Leo end */
#define FMGR_DEFAULT_FOLDER_PHBIMAGES  "Phbimage"
#define FMGR_DEFAULT_FILE_PHBVIDEO     L"phb_video.dat"

/* temp filename */
#define FMGR_TEMP_FILE_IRDA                  L"~received.tmp"
#define FMGR_TEMP_FILE_JAVA                  L"~java.tmp"
#define FMGR_TEMP_FILE_VCARD                 L"~vcard.tmp"
#define FMGR_TEMP_FILE_VCALENDAR             L"~vcalendar.tmp"
#define FMGR_TEMP_FILE_CAMERA                L"~camera.jpg"
#define FMGR_TEMP_FILE_MELODY                L"~rngc.imy"
#define FMGR_TEMP_FILE_EMAIL_NEW             L"~email.tmp"
#define FMGR_TEMP_FILE_EMAIL_SMTP            L"~smtp.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD             L"~video_aud.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD_SAMPLE      L"~video_aud_sample.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD_REAL        L"~video_aud_real.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL          L"~video_aud.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL_SAMPLE   L"~video_aud_sample.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL_REAL     L"~video_aud_real.tmp"
#define FMGR_TEMP_FILE_SWFLASH               L"~swflash.tmp"

/* file limit */
#define FMGR_LIMIT_IMAGE_VIEWER        g_fmgr_image_viewer_limit_arry
#define FMGR_LIMIT_SCREEN_SAVER        g_fmgr_screensaver_limit_arry
#define FMGR_LIMIT_WALLPAPER           g_fmgr_wallpaper_limit_arry
#ifdef __MMI_SUB_WALLPAPER__
#define FMGR_LIMIT_SUB_WALLPAPER       g_fmgr_sub_wallpaper_limit_arry
#endif 
#define FMGR_LIMIT_POWER_ON_OFF_DSPL   g_fmgr_power_on_off_disp_limit_arry
#define FMGR_LIMIT_CALLER_PICTURE         g_fmgr_caller_picture_limit_arry
#define FMGR_LIMIT_CALLER_VIDEO        g_fmgr_caller_video_limit_arry
#define FMGR_LIMIT_MMS_CATEGORY        g_fmgr_mms_category_limit_arry

#if defined(JPG_DECODE) && !defined(__MMI_SLIM_FILE_MANAGER__) && !defined(MT6223P) && !defined(MT6223) && !defined(MT6223P_S00)
#define FMGR_USING_CACHE
#endif 

#ifdef __MMI_MAINLCD_240X320__
#define FMGR_THUMB_IMAGE_BUFFER_SIZE         (100*1024)  /* 100 k */    /* this buffer imporve viewing performace alot !! */
#else 
#define FMGR_THUMB_IMAGE_BUFFER_SIZE         (60*1024)   /* 60 k */     /* this buffer imporve viewing performace alot !! */
#endif 

/****************************************************************************
* Typedef                                                            
*****************************************************************************/
typedef void (*FmgrGetDrvfp) (S8 drv);

/*
 * Notice. This enum must be sync with the size with the LID size in nvram_common_defs.h.
 * They must be wrapped with same compile options.
 *
 * "\mcu\custom\common\PLUTO_MMI\nvram_common_defs.h"
 */

typedef enum
{
#ifdef __MMI_CAMERA__
    FMGR_PATH_ID_CAMERA,
#endif

#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)
    FMGR_PATH_ID_VIDEO,
#endif 

#ifdef __MMI_PHOTOEDITOR__
    FMGR_PATH_ID_PHOTO_EDITOR,
#endif /* __MMI_PHOTOEDITOR__ */

#ifdef __MMI_SLIDESHOW__
    FMGR_PATH_ID_SLIDE_SHOW_AUDIO,
    FMGR_PATH_ID_SLIDE_SHOW_PLAY,
#endif

#ifdef __MMI_VIDEO_STREAM__
    FMGR_PATH_ID_VIDEO_STREAM,
#endif 

#ifdef __MMI_VIDEO_EDITOR__
    FMGR_PATH_ID_VIDEO_EDITOR,
#endif

    /* number of id */
    FMGR_PATH_ID_COUNT
} FMGR_PATH_ID_ENUM;
typedef struct
{
    S32 errorNo;
    MMI_ID_TYPE stringId;
}
FsErrorEntryStruct;

/****************************************************************************
* Extern Global Variable
*****************************************************************************/
extern const S32 g_fmgr_image_viewer_limit_arry[];
extern const S32 g_fmgr_wallpaper_limit_arry[];
extern const S32 g_fmgr_sub_wallpaper_limit_arry[];
extern const S32 g_fmgr_screensaver_limit_arry[];
extern const S32 g_fmgr_power_on_off_disp_limit_arry[];
extern const S32 g_fmgr_caller_picture_limit_arry[];
extern const S32 g_fmgr_caller_video_limit_arry[];
extern const S32 g_fmgr_mms_category_limit_arry[];

/****************************************************************************
* Extern Global Function
*****************************************************************************/
extern MMI_ID_TYPE GetFileSystemErrorString(S32 error);

extern S16 mmi_fmgr_get_last_dir_index(PS8 path);
extern BOOL mmi_fmgr_append_file_name(PS8 str1, PS8 str2);
extern void mmi_fmgr_remove_last_dir(PS8 path);
extern void mmi_fmgr_hide_ext_name(S8 *file_name);
extern PS8 mmi_fmgr_extract_file_name(S8 *path);
extern PS8 mmi_fmgr_extract_ext_file_name(S8 *path);

extern BOOL mmi_fmgr_convert_curr_file_name(PS8 src, PS8 dest, S16 length);
extern BOOL mmi_fmgr_get_default_folder_path(S8 *folder, S8 *path, U16 length, U8 drive);
extern BOOL mmi_fmgr_check_file_present(S8 *path);
extern S32 mmi_fmgr_create_full_path_folder(S8 *filepath);
extern S32 mmi_fmgr_get_file_type(S8 *path, FMGR_FILTER *file_type);
extern U8 mmi_fmgr_get_file_group(S8 *path);
extern PS8 mmi_fmgr_skip_space(S8 *line);
extern BOOL mmi_fmgr_check_drm_right(PU16 file_path, U8 permission, BOOL consume);
extern void mmi_fmgr_sel_drv_and_enter(U8 app_id, FmgrGetDrvfp callback, S8 highlight_storage);
extern void mmi_fmgr_select_path_and_enter(
                U8 app_id,
                U8 sel_type,
                FMGR_FILTER filter,
                PS8 start_path,
                PsExtFuncPtr callback);
extern BOOL mmi_fmgr_forwardable_path(PS8 path);
extern BOOL mmi_fmgr_is_busy (void);
/* fmgr util function */

/* load/store file path */
extern void mmi_fmgr_util_load_filepath(PS8 path_ptr, FMGR_PATH_ID_ENUM id);
extern void mmi_fmgr_util_store_filepath(PS8 path_ptr, FMGR_PATH_ID_ENUM id);

/* file limit checking */
extern BOOL mmi_fmgr_util_file_limit_check(const S32 *array_ptr, PS8 filename, PS8 *error_str_pp);
extern MMI_BOOL mmi_fmgr_is_filename_valid(S8 *path);

extern S32 mmi_fmgr_get_file_type_by_filename(S8* filename);

extern void mmi_fmgr_get_full_storage_inline_list(S8 drv_letter, U8 *total_num, U32 *inline_list_p, U8 *highlight_item);
extern void mmi_fmgr_get_exist_storage_inline_list(S8 drv_letter, U8 *total_num, U32 *inline_list_p, U8 *highlight_item);
extern void mmi_fmgr_get_drive_name(S8 drv_letter, S8* drv_name, U8 len);
extern void mmi_fmgr_get_drive_enum_by_letter(S8 drv_letter, S8* drv_enum);
extern void mmi_fmgr_get_drive_letter_by_inline_index(U8 index, S8* drv_letter);
extern MMI_BOOL mmi_fmgr_is_drive_letter_valid(S8 drv_letter);
extern void mmi_fmgr_get_exist_drive_letter(S8* drv_array, U8* num);

#if defined(__DRM_SUPPORT__)
extern S32 mmi_fmgr_get_drm_file_type_by_path(S8* file_path, FMGR_FILTER *file_type);
#endif 

extern S32 mmi_fmgr_get_file_info_by_path(S8* filepath, FMGR_FILE_INFO_STRUCT *info);

#endif /* __FILE_MANAGER_GPROT_H_ */ 

