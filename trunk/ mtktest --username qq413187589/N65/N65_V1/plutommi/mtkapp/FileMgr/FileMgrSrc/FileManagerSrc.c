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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   FileManagerSrc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   File Manager Utility 
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add FS_CARD_BATCHCOUNT_STATE_ENUM check in sel_drv_and_enter to sync with FMGR
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add a new api:mmi_fmgr_get_file_info_by_path
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * add check memory not enough case and add a new string: STR_ID_FMGR_MEMORY_NOT_ENOUGH
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * DRM_close_file in mmi_fmgr_util_file_limit_check()
 *
 * removed!
 * removed!
 * check width and height of image and file is existed or not.
 *
 * removed!
 * removed!
 * check !(file_info.attribute & FS_ATTR_DIR) to append \ for multi part odf in mmi_fmgr_append_file_name()
 *
 * removed!
 * removed!
 * check both the ".odf" & ."ODF".
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * check drive_count==0 then display empty and return to ap in mmi_fmgr_disp_sel_drv_scr()
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add __MMI_PURE_AUDIO__ support
 *
 * removed!
 * removed!
 * #include "ProfilesEnum.h" -> #include "UserProfilesResDef.h"
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add DRM related error code's strings.
 *
 * removed!
 * removed!
 * Add DRM related error code's strings.
 *
 * removed!
 * removed!
 * add jump=5 in mmi_fmgr_util_file_limit_check() for video file.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add fmgr_p->app_icon to keep application's icon.
 *
 * removed!
 * removed!
 * use the macr: FS_MINIMUM_ERROR_CODE to check the fs error code.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix compile warning
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Rollback set scr_ap_id when sel_drv_and_enter
 *
 * removed!
 * removed!
 * Add fmgr_reset_app_select() in sel_drv_and_enter() this way.
 *
 * removed!
 * removed!
 * replace the string of FS_ERROR_RESERVED to STR_GLOBAL_DRM_PROHIBITED
 *
 * removed!
 * removed!
 * Modify mmi_fmgr_util_limit_check.
 *
 * removed!
 * removed!
 * set app id in  mmi_fmgr_sel_drv_and_enter()
 *
 * removed!
 * removed!
 * Add string id to mapping DRM Error code.
 *
 * removed!
 * removed!
 * Mflash support.
 *
 * removed!
 * removed!
 * Add a new string for DRM process error.
 *
 * removed!
 * removed!
 * modify mmi_fmgr_get_file_group to meet DRM2.0
 *
 * removed!
 * removed!
 * Add icon id in select drive screen.
 *
 * removed!
 * removed!
 * Add trace of error code in FS, and return a default error string.
 *
 * removed!
 * removed!
 * Fix compile error.
 *
 * removed!
 * removed!
 * drm 2.0 support
 *
 * removed!
 * removed!
 * Support DRM2.0
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * DRM 2.0 support
 *
 * removed!
 * removed!
 * DRM 2.0 support
 *
 * removed!
 * removed!
 * Add compile option for fix compile error.
 *
 * removed!
 * removed!
 * Add DRM error code's global string in FsErrorTable
 *
 * removed!
 * removed!
 * rollback mmi_fmgr_disp_sel_drv_scr() to solve DRM2.0 check-in side effect.
 *
 * removed!
 * removed!
 * DRM2.0 support.
 *
 * removed!
 * removed!
 * Modify the compile option: MUSICAM_DECODE
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * Check FS_FILE_NOT_FOUND in mmi_fmgr_get_file_group()
 *
 * removed!
 * removed!
 * add check the extent file name len > 0 in mmi_fmgr_get_file_type().
 *
 * removed!
 * removed!
 * Remove #include "FileSystemDef.h".
 *
 * removed!
 * removed!
 * Remove compile option: MMI_ON_HARDWARE_P & MMI_ON_WIN32
 *
 * removed!
 * removed!
 * Add new invalid check ".aa" in mmi_fmgr_is_filename_valid()
 *
 * removed!
 * removed!
 * Add new invalid check ".aa" in mmi_fmgr_is_filename_valid()
 *
 * removed!
 * removed!
 * add 2 more video file check in mmi_fmgr_util_file_limit_check() <MPG & 3G2>
 *
 * removed!
 * removed!
 * Add MP2 file type support.
 *
 * removed!
 * removed!
 * Modify the compile option of M4A file type.
 *
 * removed!
 * removed!
 * Modify the check of highlight in mmi_fmgr_disp_sel_drv_scr()
 *
 * removed!
 * removed!
 * Modify the policy of mmi_fmgr_get_file_type().
 *
 * removed!
 * removed!
 * modify the policy of checking highlight in mmi_fmgr_disp_sel_drv_scr().
 *
 * removed!
 * removed!
 * Modify the parameter of mmi_ucs2ncpy().
 *
 * removed!
 * removed!
 * Add New API: mmi_fmgr_is_filename_valid()
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix Compile warnning in W07.05
 *
 * removed!
 * removed!
 * Check the highlight index!=DRM_OBJ when sel_drv_and_enter.
 *
 * removed!
 * removed!
 * Modify the sub wallpaper limitation size from 150K to 10K.
 *
 * removed!
 * removed!
 * Add SIM+ Prefer storage Support.
 *
 * removed!
 * removed!
 * Add new API: mmi_fmgr_get_file_type_by_filename().
 *
 * removed!
 * removed!
 * Move entrynewscreen after some check(return) in mmi_fmgr_disp_sel_drv_scr()
 *
 * removed!
 * removed!
 * When abort app select in mmi_fmgr_disp_sel_drv_scr(), adjust history: delete unused screen.
 *
 * removed!
 * removed!
 * Streaming & PDL Support.
 *
 * removed!
 * removed!
 * check file handler is valid in mmi_fmgr_get_file_type().
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * SIM+ Support.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add compile option __MMI_FILE_MANAGER__ for some functions. Such as: select drv.
 *
 * removed!
 * removed!
 * Add fs_close , when file size = 0 in mmi_fmgr_util_file_limit_check().
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Use new field to check if fmgr is busy.
 *
 * removed!
 * removed!
 * Change the png limit for dispchar
 *
 * removed!
 * removed!
 * Add PNG limit to dispchar
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add file type -- 3G2.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add GIF limit of wallpaper
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Change the limit of Screen saver/Power on off disp file
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Correct the limitation of Screensaver and Power on/off disp: 240<->320
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *******************************************************************************/

#include "MMI_include.h"

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif

#include "HardwareEvents.h"
#include "CallSetupEnum.h"      /* STR_SECONDS */


#include "SettingProfile.h"
#include "PhoneSetupGprots.h"
#include "Conversions.h"
#include "lcd_sw_inc.h"

#include "drm_def.h"
#include "drm_gprot.h"

#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "FileMgrStruct.h"

#ifdef __MMI_VIDEO_PLAYER__
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"
#endif /* __MMI_VIDEO_PLAYER__ */ 

#ifdef __USB_IN_NORMAL_MODE__
#include "ExtDeviceDefs.h"
#include "USBDeviceGprot.h"
#endif 

#ifdef __DRM_SUPPORT__
#include "RightsMgrGProt.h"
#endif

/*=============  Constants & Global Variables  ================ */
extern fmgr_filter_struct fmgr_filter[];
extern fmgr_context_struct *fmgr_p;

/*****************************************************************************
* Define                                                              
*****************************************************************************/
#define NO_FS_ERROR 55

#define FILE_LIMIT_ERROR_STR_LEN    (100)
#define FILE_LIMIT_ERROR_BUF_SIZE   ((FILE_LIMIT_ERROR_STR_LEN+1)*ENCODING_LENGTH)

#define FILE_LIMIT_FALSE_RETURN(_str_id_)                       \
do{                                                             \
   mmi_ucs2ncpy(g_fmgr_file_limit_error_str,               \
                     (PS8)(GetString(_str_id_)),                \
                     FILE_LIMIT_ERROR_STR_LEN);                 \
   g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE-1] = 0;\
   g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE-2] = 0;\
   return FALSE;                                                \
} while(0);

/* 
 * size     : Kbyte
 * width    : pixel  
 * height   : pixel     
 */
#define IMG_BMP_LIMIT_ITEM(size,width,height)   GDI_IMAGE_TYPE_BMP_FILE,size,width,height
#define IMG_JPG_LIMIT_ITEM(size,width,height)   GDI_IMAGE_TYPE_JPG_FILE,size,width,height
#define IMG_GIF_LIMIT_ITEM(size,width,height)   GDI_IMAGE_TYPE_GIF_FILE,size,width,height
#define IMG_WBMP_LIMIT_ITEM(size,width,height)  GDI_IMAGE_TYPE_WBMP_FILE,size,width,height
#define IMG_PNG_LIMIT_ITEM(size,width,height)  GDI_IMAGE_TYPE_PNG_FILE,size,width,height
#define IMG_M3D_LIMIT_ITEM(size,width,height)  GDI_IMAGE_TYPE_M3D_FILE,size,width,height
#define IMG_SVG_LIMIT_ITEM(size,width,height)  GDI_IMAGE_TYPE_SVG_FILE,size,width,height

/* 
 * size     : Kbyte
 * duration : sec       
 * width    : pixel  
 * height   : pixel     
 */
#define VDO_3GP_LIMIT_ITEM(size,duration,width,height)   GDI_IMAGE_TYPE_3GP_FILE,size,duration,width,height
#define VDO_MP4_LIMIT_ITEM(size,duration,width,height)   GDI_IMAGE_TYPE_MP4_FILE,size,duration,width,height
#define VDO_AVI_LIMIT_ITEM(size,duration,width,height)   GDI_IMAGE_TYPE_AVI_FILE,size,duration,width,height
#define VDO_SWFLASH_LIMIT_ITEM(size,duration,width,height)   GDI_IMAGE_TYPE_SWFLASH_FILE,size,duration,width,height

#define END_LIMIT_ITEM     GDI_IMAGE_TYPE_INVALID

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef struct
{
    fmgr_drive_enum drv_enum;
    U16  drv_string_id;
}FmgrDriveInfoStruct;

/*****************************************************************************
* Global Variable                                                    
*****************************************************************************/

/*****************************************************************************
* Global Function                                                           
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
const FsErrorEntryStruct FsErrorTable[] = 
{
    {FS_ERROR_RESERVED, STR_GLOBAL_DRM_PROHIBITED},
    {FS_PARAM_ERROR, FMGR_FS_PARAM_ERROR_TEXT},
    {FS_INVALID_FILENAME, FMGR_FS_INVALID_FILENAME_TEXT},
    {FS_DRIVE_NOT_FOUND, FMGR_FS_DRIVE_NOT_FOUND_TEXT},
    {FS_TOO_MANY_FILES, FMGR_FS_TOO_MANY_FILES_TEXT},
    {FS_NO_MORE_FILES, FMGR_FS_NO_MORE_FILES_TEXT},
    {FS_WRONG_MEDIA, FMGR_FS_WRONG_MEDIA_TEXT},
    {FS_INVALID_FILE_SYSTEM, FMGR_FS_INVALID_FILE_SYSTEM_TEXT},
    {FS_FILE_NOT_FOUND, FMGR_FS_FILE_NOT_FOUND_TEXT},
    {FS_INVALID_FILE_HANDLE, FMGR_FS_INVALID_FILE_HANDLE_TEXT},
    {FS_UNSUPPORTED_DEVICE, FMGR_FS_UNSUPPORTED_DEVICE_TEXT},
    {FS_UNSUPPORTED_DRIVER_FUNCTION, FMGR_FS_UNSUPPORTED_DRIVER_FUNCTION_TEXT},
    {FS_CORRUPTED_PARTITION_TABLE, FMGR_FS_CORRUPTED_PARTITION_TABLE_TEXT},
    {FS_TOO_MANY_DRIVES, FMGR_FS_TOO_MANY_DRIVES_TEXT},
    {FS_INVALID_FILE_POS, FMGR_FS_INVALID_FILE_POS_TEXT},
    {FS_ACCESS_DENIED, FMGR_FS_ACCESS_DENIED_TEXT},
    {FS_STRING_BUFFER_TOO_SMALL, FMGR_FS_STRING_BUFFER_TOO_SMALL_TEXT},
    {FS_GENERAL_FAILURE, FMGR_FS_GENERAL_FAILURE_TEXT},
    {FS_PATH_NOT_FOUND, FMGR_FS_PATH_NOT_FOUND_TEXT},
    {FS_FAT_ALLOC_ERROR, FMGR_FS_FAT_ALLOC_ERROR_TEXT},
    {FS_ROOT_DIR_FULL, FMGR_FS_ROOT_DIR_FULL_TEXT},
    {FS_DISK_FULL, FMGR_FS_DISK_FULL_TEXT},
    {FS_TIMEOUT, FMGR_FS_TIMEOUT_TEXT},
    {FS_BAD_SECTOR, FMGR_FS_BAD_SECTOR_TEXT},
    {FS_DATA_ERROR, FMGR_FS_DATA_ERROR_TEXT},
    {FS_MEDIA_CHANGED, FMGR_FS_MEDIA_CHANGED_TEXT},
    {FS_SECTOR_NOT_FOUND, FMGR_FS_SECTOR_NOT_FOUND_TEXT},
    {FS_ADDRESS_MARK_NOT_FOUND, FMGR_FS_ADDRESS_MARK_NOT_FOUND_TEXT},
    {FS_DRIVE_NOT_READY, FMGR_FS_DRIVE_NOT_READY_TEXT},
    {FS_WRITE_PROTECTION, FMGR_FS_WRITE_PROTECTION_TEXT},
    {FS_DMA_OVERRUN, FMGR_FS_DMA_OVERRUN_TEXT},
    {FS_CRC_ERROR, FMGR_FS_CRC_ERROR_TEXT},
    {FS_DEVICE_RESOURCE_ERROR, FMGR_FS_DEVICE_RESOURCE_ERROR_TEXT},
    {FS_INVALID_SECTOR_SIZE, FMGR_FS_INVALID_SECTOR_SIZE_TEXT},
    {FS_OUT_OF_BUFFERS, FMGR_FS_OUT_OF_BUFFERS_TEXT},
    {FS_FILE_EXISTS, FMGR_FS_FILE_EXISTS_TEXT},
    {FS_LONG_FILE_POS, FMGR_FS_LONG_FILE_POS_TEXT},
    {FS_FILE_TOO_LARGE, FMGR_FS_FILE_TOO_LARGE_TEXT},
    {FS_BAD_DIR_ENTRY, FMGR_FS_BAD_DIR_ENTRY_TEXT},
    //{FS_ATTR_CONFLICT                                  ,FMGR_FS_ATTR_CONFLICT_TEXT                                     },
    //{FS_CHECKDISK_RETRY                                ,FMGR_FS_CHECKDISK_RETRY_TEXT                                   },
    //{FS_LACK_OF_PROTECTION_SPACE       ,FMGR_FS_LACK_OF_PROTECTION_SPACE_TEXT          },
    {FS_READ_ONLY_ERROR, FMGR_FS_READ_ONLY_ERROR_TEXT},
    {FS_SYSTEM_CRASH, FMGR_FS_SYSTEM_CRASH_TEXT},
    {FS_FAIL_GET_MEM, FMGR_FS_FAIL_GET_MEM_TEXT},
    {FS_DEVICE_BUSY, FMGR_FS_DEVICE_BUSY_TEXT},
    {FS_ABORTED_ERROR, FMGR_FS_ABORTED_ERROR_TEXT},
    {FS_FLASH_MOUNT_ERROR, FMGR_FS_FLASH_MOUNT_ERROR_TEXT},
    {FS_PATH_OVER_LEN_ERROR, FMGR_FS_PATH_OVER_LEN_ERROR_TEXT},
    {FS_APP_QUOTA_FULL, FMGR_FS_APP_QUOTA_FULL_TEXT},
    {FS_DEVICE_EXPORTED_ERROR, FMGR_FS_DEVICE_EXPORTED_ERROR_TEXT},
    {FS_MSDC_MOUNT_ERROR, FMGR_FS_MSDC_MOUNT_ERROR_TEXT},
    {FS_MSDC_READ_SECTOR_ERROR, FMGR_FS_MSDC_READ_SECTOR_ERROR_TEXT},
    {FS_MSDC_WRITE_SECTOR_ERROR, FMGR_FS_MSDC_WRITE_SECTOR_ERROR_TEXT},
    {FS_MSDC_DISCARD_SECTOR_ERROR, FMGR_FS_MSDC_DISCARD_SECTOR_ERROR_TEXT},
    {FS_MSDC_PRESNET_NOT_READY, FMGR_FS_MSDC_PRESENT_NOT_READY_TEXT},
    {FS_MSDC_NOT_PRESENT, FMGR_FS_MSDC_NOT_PRESENT_TEXT},
    {FS_FLASH_ERASE_BUSY, FMGR_FS_FLASH_ERASE_BUSY_TEXT},
    {FS_LOCK_MUTEX_FAIL, FMGR_FS_LOCK_MUTEX_FAIL_TEXT},


    {0, 0}
};

/* add short tern solution for MT6223P to limit decoder capbility */
/* removed this limitation since W07.49 due to non_blocking_decode enable on MT6223P
#if defined(MT6223P)
const S32 g_fmgr_image_viewer_limit_arry[] = 
{
    IMG_JPG_LIMIT_ITEM(0, 176, 220),
    IMG_WBMP_LIMIT_ITEM(512, 176, 220),
    IMG_BMP_LIMIT_ITEM(512, 176, 220),
    IMG_GIF_LIMIT_ITEM(150, 176, 220),
    IMG_PNG_LIMIT_ITEM(0, 0, 0),
    IMG_SVG_LIMIT_ITEM(200, 0, 0),
    IMG_M3D_LIMIT_ITEM(200, 0, 0),
    END_LIMIT_ITEM
};
*/
#if defined(MT6225)
const S32 g_fmgr_image_viewer_limit_arry[] = 
{
    IMG_JPG_LIMIT_ITEM(1230, 0, 0),
    IMG_WBMP_LIMIT_ITEM(1536, 2048, 2048),
    IMG_BMP_LIMIT_ITEM(6656, 0, 0),
    IMG_GIF_LIMIT_ITEM(0, 1280, 1280),
    IMG_PNG_LIMIT_ITEM(0, 640, 480),
    IMG_SVG_LIMIT_ITEM(0, 0, 0),
    IMG_M3D_LIMIT_ITEM(200, 0, 0),
    END_LIMIT_ITEM
};
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
const S32 g_fmgr_image_viewer_limit_arry[] = 
{
    IMG_JPG_LIMIT_ITEM(2253, 0, 0),
    IMG_WBMP_LIMIT_ITEM(1536, 2048, 2048),
    IMG_BMP_LIMIT_ITEM(1230, 0, 0),
    IMG_GIF_LIMIT_ITEM(0, 640, 640),
    IMG_PNG_LIMIT_ITEM(0, 480, 320),
    IMG_SVG_LIMIT_ITEM(0, 0, 0),
    IMG_M3D_LIMIT_ITEM(200, 0, 0),
    END_LIMIT_ITEM
};
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6238)
const S32 g_fmgr_image_viewer_limit_arry[] = 
{
    IMG_JPG_LIMIT_ITEM(3175, 0, 0),
    IMG_WBMP_LIMIT_ITEM(1536, 2048, 2048),
    IMG_BMP_LIMIT_ITEM(16384, 0, 0),
    IMG_GIF_LIMIT_ITEM(0, 1280, 1280),
    IMG_PNG_LIMIT_ITEM(0, 1024, 768),
    IMG_SVG_LIMIT_ITEM(125, 0, 0),
    IMG_M3D_LIMIT_ITEM(200, 0, 0),
    END_LIMIT_ITEM
};
#else
const S32 g_fmgr_image_viewer_limit_arry[] = 
{
    IMG_JPG_LIMIT_ITEM(0, 0, 0),
    IMG_WBMP_LIMIT_ITEM(512, 1536, 1536),
    IMG_BMP_LIMIT_ITEM(512, 1536, 1536),
    IMG_GIF_LIMIT_ITEM(0, 640, 640),
    IMG_PNG_LIMIT_ITEM(0, 0, 0),
    IMG_SVG_LIMIT_ITEM(200,0,0),
    IMG_M3D_LIMIT_ITEM(200,0,0),
    END_LIMIT_ITEM
};
#endif

const S32 g_fmgr_wallpaper_limit_arry[] = 
{
    IMG_BMP_LIMIT_ITEM(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_JPG_LIMIT_ITEM(256, 0, 0),
    IMG_GIF_LIMIT_ITEM(150, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_PNG_LIMIT_ITEM(20, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_SVG_LIMIT_ITEM(200,0,0),
    IMG_M3D_LIMIT_ITEM(200,0,0),
    END_LIMIT_ITEM
};

#ifdef __MMI_SUB_WALLPAPER__
const S32 g_fmgr_sub_wallpaper_limit_arry[] = 
{
    IMG_BMP_LIMIT_ITEM(0, SUBLCD_WIDTH, SUBLCD_HEIGHT),
    IMG_JPG_LIMIT_ITEM(20, 0, 0),
    IMG_GIF_LIMIT_ITEM(10, SUBLCD_WIDTH, SUBLCD_HEIGHT),
    IMG_PNG_LIMIT_ITEM(10, SUBLCD_WIDTH, SUBLCD_HEIGHT),
    IMG_SVG_LIMIT_ITEM(0,0,0),
    IMG_M3D_LIMIT_ITEM(0,0,0),
    END_LIMIT_ITEM
};
#endif /* __MMI_SUB_WALLPAPER__ */ 
const S32 g_fmgr_screensaver_limit_arry[] = 
{
    IMG_BMP_LIMIT_ITEM(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_JPG_LIMIT_ITEM(256, 0, 0),
    IMG_GIF_LIMIT_ITEM(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_PNG_LIMIT_ITEM(20, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_SVG_LIMIT_ITEM(200,0,0),
    IMG_M3D_LIMIT_ITEM(200,0,0),
    END_LIMIT_ITEM
};

const S32 g_fmgr_power_on_off_disp_limit_arry[] = 
{
    IMG_BMP_LIMIT_ITEM(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_JPG_LIMIT_ITEM(256, 0, 0),
    IMG_GIF_LIMIT_ITEM(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_PNG_LIMIT_ITEM(20, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    IMG_SVG_LIMIT_ITEM(200,0,0),
    IMG_M3D_LIMIT_ITEM(200,0,0),
    END_LIMIT_ITEM
};

const S32 g_fmgr_caller_picture_limit_arry[] = 
{
    IMG_BMP_LIMIT_ITEM(20, 0, 0),
    IMG_JPG_LIMIT_ITEM(20, 0, 0),
    IMG_GIF_LIMIT_ITEM(20, 0, 0),
    IMG_PNG_LIMIT_ITEM(20, 0, 0),
    IMG_PNG_LIMIT_ITEM(20, 0, 0),    
    IMG_M3D_LIMIT_ITEM(100, 0, 0),
    IMG_SVG_LIMIT_ITEM(20, 0, 0),
    END_LIMIT_ITEM
};

const S32 g_fmgr_caller_video_limit_arry[] = 
{
    VDO_3GP_LIMIT_ITEM(50000, 0, 0, 0),
    VDO_MP4_LIMIT_ITEM(50000, 0, 0, 0),
    VDO_AVI_LIMIT_ITEM(50000, 0, 0, 0),
    VDO_SWFLASH_LIMIT_ITEM(50000, 0, 0, 0),
    END_LIMIT_ITEM
};

const S32 g_fmgr_mms_category_limit_arry[] = 
{
    IMG_JPG_LIMIT_ITEM(0, 2048, 2048),
    IMG_WBMP_LIMIT_ITEM(512, 1536, 1536),
    IMG_BMP_LIMIT_ITEM(512, 1536, 1536),
    IMG_GIF_LIMIT_ITEM(0, 640, 640),
    IMG_PNG_LIMIT_ITEM(0, 640, 640),
    IMG_SVG_LIMIT_ITEM(20,0,0),
    IMG_M3D_LIMIT_ITEM(200,0,0),
    END_LIMIT_ITEM
};

static S8 g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE];


FmgrDriveInfoStruct Fmgr_Drive_Info_Table[] = 
{
    {FMGR_NAND_STORAGE,      STR_FMGR_NAND_FLASH},
    {FMGR_NOR_STORAGE,       STR_FMGR_NOR_FLASH},
#if defined(__DRM_MTK__)
    {FMGR_DRM_RO_STORAGE,    STR_FMGR_DRM_RIGHTS},
#endif    
    {FMGR_REMOVABLE_STORAGE, STR_FMGR_REM_DEVICE},
#ifdef __OTG_ENABLE__
    {FMGR_OTG_1_STORAGE,     STR_FMGR_REM_DEVICE},
    {FMGR_OTG_2_STORAGE,     STR_FMGR_REM_DEVICE},
    {FMGR_OTG_3_STORAGE,     STR_FMGR_REM_DEVICE},
    {FMGR_OTG_4_STORAGE,     STR_FMGR_REM_DEVICE},    
#endif
#ifdef __SIM_PLUS__
    {FMGR_SIM_PLUS_1_STORAGE, STR_FMGR_SIM_PLUS},
    {FMGR_SIM_PLUS_2_STORAGE, STR_FMGR_SIM_PLUS2},
    {FMGR_SIM_PLUS_3_STORAGE, STR_FMGR_SIM_PLUS3},
    {FMGR_SIM_PLUS_4_STORAGE, STR_FMGR_SIM_PLUS4},    
#endif    
#ifdef __MSDC2_SD_MMC__
    {FMGR_MSDC2_SD_STORAGE, STR_FMGR_REM_DEVICE2},    
#endif 
    {0, 0}
};

/*****************************************************************************
* Local Function 
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  GetFileSystemErrorString
 * DESCRIPTION
 *  map file system return error cause to error string id
 * PARAMETERS
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID_TYPE GetFileSystemErrorString(S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FMGR] GetFileSystemErrorString: error = %d", error);

    for (i = 0; FsErrorTable[i].errorNo != 0; i++)
    {
        if (FsErrorTable[i].errorNo == error)
        {
            return FsErrorTable[i].stringId;
        }
    }
#ifdef __DRM_SUPPORT__    
    if (error < FS_MINIMUM_ERROR_CODE)  /* The max of File System error code */
    {
        return mmi_rmgr_get_err_string(error);
    }
#endif
    return STR_GLOBAL_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_set_audio_filter
 * DESCRIPTION
 *  set the file type belongs to audio group
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_set_audio_filter(FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_SET(file_type, FMGR_TYPE_MID);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_MIDI);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AMR);
#ifdef AAC_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AAC);
#endif 
#ifdef DAF_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_DAF);
#ifdef MUSICAM_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_MP2);
#endif
#endif 
    FMGR_FILTER_SET(file_type, FMGR_TYPE_VM);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_IMY);
#ifdef AMRWB_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AWB);
#endif 
#ifdef AIFF_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AIF);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AIFF);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AIFC);
#endif
#ifdef AU_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AU);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_SND);
#endif    
#ifdef AAC_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_M4A);
#endif 
#if defined(YAMAHA_MA3)
    FMGR_FILTER_SET(file_type, FMGR_TYPE_MMF);
#endif 
#ifdef WMA_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_WMA);
#endif 

/* note FION */
#if !defined(MP4_CODEC) &&(defined(__MMI_PURE_AUDIO__))
    FMGR_FILTER_SET(file_type, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_3GP);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_check_audio_filter
 * DESCRIPTION
 *  check if the file type belongs to audio group
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_check_audio_filter(FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MID) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MIDI) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_VM) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_WAV) || 
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AMR) ||
#ifdef AAC_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AAC) ||
#endif 
#ifdef DAF_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_DAF) ||
#ifdef MUSICAM_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MP2) ||
#endif
#endif 
#ifdef AMRWB_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AWB) ||
#endif 
#ifdef AIFF_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AIF) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AIFF) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AIFC) || 
#endif
#ifdef AU_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AU) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_SND) ||        
#endif        

#ifdef AAC_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_M4A) ||
#endif 
#if defined(YAMAHA_MA3)
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MMF) ||
#endif 
#ifdef WMA_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_WMA) ||
#endif 

/* note FION */
#if !defined(MP4_CODEC) &&(defined(__MMI_PURE_AUDIO__))
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MP4) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_3GP) ||
#endif

        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_IMY))

        return TRUE;
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_set_image_filter
 * DESCRIPTION
 *  set the file type belongs to image group
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_set_image_filter(FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_SET(file_type, FMGR_TYPE_BMP);
#ifdef JPG_DECODE
    FMGR_FILTER_SET(file_type, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_JPEG);
#endif /* JPG_DECODE */ 
    FMGR_FILTER_SET(file_type, FMGR_TYPE_GIF);
#ifdef GDI_USING_PNG	
    FMGR_FILTER_SET(file_type, FMGR_TYPE_PNG);
#endif /* GDI_USING_PNG */
    FMGR_FILTER_SET(file_type, FMGR_TYPE_WBMP);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_WBM);
#ifdef M3D_MMI_SUPPORT
    FMGR_FILTER_SET(file_type, FMGR_TYPE_M3D);
#endif 
#ifdef __MMI_SVG__
/* under construction !*/
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_check_image_filter
 * DESCRIPTION
 *  check if the file type belongs to image group
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_check_image_filter(FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_BMP) ||
#ifdef JPG_DECODE
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_JPG) || FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_JPEG) ||
#endif 
#ifdef __MMI_SVG__
/* under construction !*/
#endif 
#ifdef M3D_MMI_SUPPORT
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_M3D) ||
#endif 
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_GIF) ||
#ifdef GDI_USING_PNG
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_PNG) ||
#endif /* GDI_USING_PNG */
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_WBMP) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_WBM) ||
        FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_EMS) || FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_ANM))
        return TRUE;
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_check_video_filter
 * DESCRIPTION
 *  check if the file type belongs to video group
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_check_video_filter(FMGR_FILTER *file_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(MP4_CODEC)
    if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_3GP) || 
    	FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MP4) ||
    	FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MPG) ||
    	FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_3G2))    	
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
#elif defined(__SF_MP4_SUPPORT__)
	if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_3GP) || 
            FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MP4) ||
            FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_3G2) ||
            FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AVI))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
#elif defined(MJPG_SUPPORT)
    if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_AVI))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
#else 
    return FALSE;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_set_video_filter
 * DESCRIPTION
 *  set filter to all video types
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_set_video_filter(FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(MP4_CODEC)    
    FMGR_FILTER_SET(file_type, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_MPG);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_3G2);
#elif defined(__SF_MP4_SUPPORT__)
    FMGR_FILTER_SET(file_type, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_3G2);
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AVI);
#elif defined(MJPG_SUPPORT)
    FMGR_FILTER_SET(file_type, FMGR_TYPE_AVI);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_check_swflash_filter
 * DESCRIPTION
 *  check if the file type belongs to swflash group
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/

BOOL mmi_fmgr_check_swflash_filter(FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SWFLASH__
    if ((FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_CMP))||
        (FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_VIS))||
        (FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_ZDD))||
        (FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_IVIS))||
        (FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_KVIS))||
        (FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_MVIS)))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
#else
    return FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_set_swflash_filter
 * DESCRIPTION
 *  set filter to all swflash types
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_set_swflash_filter (FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SWFLASH__
    FMGR_FILTER_SET(file_type,FMGR_TYPE_CMP);
    FMGR_FILTER_SET(file_type,FMGR_TYPE_VIS);
    FMGR_FILTER_SET(file_type,FMGR_TYPE_ZDD);
    FMGR_FILTER_SET(file_type,FMGR_TYPE_IVIS);
    FMGR_FILTER_SET(file_type,FMGR_TYPE_KVIS);
    FMGR_FILTER_SET(file_type,FMGR_TYPE_MVIS);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_append_file_name
 * DESCRIPTION
 *  append file name to file path, i.e. go down one level
 * PARAMETERS
 *  str1        [IN]        
 *  str2        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_append_file_name(PS8 str1, PS8 str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__DRM_V02__)  
    FMGR_FILE_INFO_STRUCT file_info;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(str1) + mmi_ucs2strlen(str2) > FMGR_MAX_PATH_LEN)
    {
        PRINT_INFORMATION("append file name too long\n");

        DisplayPopup((PU8) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);

        return FALSE;
    }

#if defined(__DRM_V02__)  
    if ( (mmi_ucs2ncmp((PS8)fmgr_p->file_path+ ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".odf", 4) == 0) ||
         (mmi_ucs2ncmp((PS8)fmgr_p->file_path+ ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".ODF", 4) == 0))
    {
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (!(file_info.attribute & FS_ATTR_DIR))
        {
            mmi_ucs2cat(str1, (PS8)L"\\");
        }
        mmi_ucs2cat(str1, str2);
    }
    else
    {
#endif /* #if defined(__DRM_V02__) */
        mmi_ucs2cat(str1, str2);
#if defined(__DRM_V02__)
    }
#endif /* #if defined(__DRM_V02__) */
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_last_dir_index
 * DESCRIPTION
 *  get pointer to the last directory in the file path
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_fmgr_get_last_dir_index(PS8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = (S16) mmi_ucs2strlen(path);
    i = length - 1;

    while (i >= 0)
    {
        if (path[i << 1] == '\\' && path[(i << 1) + 1] == 0 && (i != length - 1))
        {
            break;
        }
        i--;
    }

#if defined(__DRM_V02__)
    if (i>5)
    {
        if ( (mmi_ucs2ncmp((PS8)path+((i-4)<<1), (PS8)L".odf\\", 5) == 0) ||
             (mmi_ucs2ncmp((PS8)path+((i-4)<<1), (PS8)L".ODF\\", 5) == 0) )
        {
            i--;
        }
    }
#endif

    return (i + 1) << 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_remove_last_dir
 * DESCRIPTION
 *  remove the last directory in the file path, i.e. go up one level
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_remove_last_dir(PS8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_fmgr_get_last_dir_index(path);
    /* terminate the string from the point of back slash */

    if (index == 0)
    {
        /* can't delete over drive, always keep X:\ */
        path[6] = 0;
        path[7] = 0;
    }
    else
    {
        path[index] = 0;
        path[index + 1] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_convert_curr_file_name
 * DESCRIPTION
 *  convert file name encoding for display
 * PARAMETERS
 *  src         [IN]        
 *  dest        [IN]        
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_convert_curr_file_name(PS8 src, PS8 dest, S16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_fmgr_kernel_get_cur_idx();

    if (fmgr_p->file_cache[index].is_short == MMI_TRUE)
    {
        mmi_chset_mixed_text_to_ucs2_str((U8*) dest, length, (U8*) src, (mmi_chset_enum) PhnsetGetDefEncodingType());
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_hide_ext_name
 * DESCRIPTION
 *  hide extension file name
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_hide_ext_name(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find ext name - by finding "." */
#ifndef __MMI_SHOW_FILE_EXT__
    S32 str_len;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_ucs2strlen(file_name);
    index = (str_len - 1) * ENCODING_LENGTH;

    while (index > 0)
    {
        if (mmi_ucs2ncmp((PS8) & file_name[index], (PS8) L".", 1) == 0)
        {
            file_name[index] = '\0';
            file_name[index + 1] = '\0';
            break;
        }

        file_name[index] = '\0';
        file_name[index + 1] = '\0';
        index -= 2;
    }
#endif /* __MMI_SHOW_FILE_EXT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_default_folder_path
 * DESCRIPTION
 *  make default folder path
 * PARAMETERS
 *  folder      [?]         
 *  path        [?]         
 *  length      [IN]        
 *  drive       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_get_default_folder_path(S8 *folder, S8 *path, U16 length, U8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length < (mmi_ucs2strlen((S8*) folder) + 4) * ENCODING_LENGTH)
    {
        return FALSE;
    }

    if (path != NULL)
    {
        memset(path, 0, 8);
        path[0] = drive;
        path[2] = ':';
        path[4] = '\\';
        mmi_ucs2cat(path, folder);
    }

    if ((handle = FS_Open((PU16) path, FS_READ_ONLY)) >= 0)
    {
        FS_Close(handle);
    }
    else if (handle == FS_PATH_NOT_FOUND || handle == FS_FILE_NOT_FOUND)
    {
        if (FS_CreateDir((PU16) path) < 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_create_full_path_folder
 * DESCRIPTION
 *  create folder recursively
 * PARAMETERS
 *  filepath        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmgr_create_full_path_folder(S8 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_createpath[128];
    S8 buf_filepath[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    S32 fs_ret = 0;
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return FS_NO_ERROR;
    }

    /* create directory if it is not there */
    mmi_ucs2cpy((PS8) buf_filepath, (PS8) filepath);

    str_len = mmi_ucs2strlen((PS8) buf_filepath);
    str_len *= ENCODING_LENGTH;

    /* skip drive. "C:\" */
    for (i = 3 * ENCODING_LENGTH; i < str_len; i += 2)
    {
        cmp_ret = mmi_ucs2ncmp((PS8) & buf_filepath[i], (PS8) L"\\", 1);
        if (cmp_ret == 0)
        {
            /* create dir */

            mmi_ucs2ncpy((PS8) buf_createpath, (PS8) buf_filepath, i / ENCODING_LENGTH);
            buf_createpath[i] = '\0';
            buf_createpath[i + 1] = '\0';

            fs_ret = FS_CreateDir((PU16) buf_createpath);

        }
    }
    return fs_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_extract_file_name
 * DESCRIPTION
 *  get pointer to the file name in the file path
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
PS8 mmi_fmgr_extract_file_name(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = (S16) mmi_ucs2strlen(path);
    i = length - 1;

    while (i >= 0)
    {
        if (path[i << 1] == '\\' && path[(i << 1) + 1] == 0 && (i != length - 1))
        {
            break;
        }
        i--;
    }

    if (i < 0)
    {
        return NULL;
    }

    return &path[(i + 1) << 1];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_extract_ext_file_name
 * DESCRIPTION
 *  get pointer to the extension file name in the file path
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
PS8 mmi_fmgr_extract_ext_file_name(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = (S16) mmi_ucs2strlen(path);
    i = length - 1;

    while (i >= 0)
    {
        if (path[i << 1] == '\\' && path[(i << 1) + 1] == 0)
        {
            return NULL;
        }
        if (path[i << 1] == '.' && path[(i << 1) + 1] == 0 && (i != length - 1))
        {
            break;
        }
        i--;
    }

    if (i < 0)
    {
        return NULL;
    }

    return &path[(i + 1) << 1];
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_is_busy
 * DESCRIPTION
 *  map extension file name to file type
 * PARAMETERS
 *  path            [?]     
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_is_busy (void)
{
	 return fmgr_p->is_fmgr_busy;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_file_type
 * DESCRIPTION
 *  map extension file name to file type
 * PARAMETERS
 *  path            [?]     
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmgr_get_file_type(S8 *path, FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_file_ext[(FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH];
    S32 i;
    FS_HANDLE handle;
    S8 ext_name_len;
    PS8 ext_file_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buf_file_ext, 0 , sizeof(buf_file_ext));
#if defined(__DRM_SUPPORT__)
    handle = DRM_open_file((PU16) path, FS_READ_ONLY, DRM_PERMISSION_NONE);
#else
    handle = FS_Open((PU16) path, FS_READ_ONLY);
#endif /* #if defined(__DRM_SUPPORT__) */

    if (handle >= FS_NO_ERROR)
    {
        FMGR_FILTER_INIT(file_type);
        FMGR_FILTER_SET(file_type, FMGR_TYPE_UNKNOW);

        ext_file_p = mmi_fmgr_extract_ext_file_name((PS8)path);
        ext_name_len = mmi_ucs2strlen((PS8) ext_file_p);

        if (ext_name_len > FMGR_MAX_EXT_LEN )
        {
            ext_name_len = FMGR_MAX_EXT_LEN;
        }

        mmi_ucs2_n_to_asc((PS8) buf_file_ext, (PS8) ext_file_p, ext_name_len*ENCODING_LENGTH);
           
        /* get file extension - and make it upper case */
        for (i = 0; i < ext_name_len; i++)
        {
            if (buf_file_ext[i] >= 'a')
            {
                buf_file_ext[i] += 'A' - 'a';
            }
        }
        if (ext_name_len>0)
        {
            /* use extension to check filter */
            for (i = 0; i < FMGR_MAX_FILTER_COUNT; i++)
            {
                S8 j=0;
                MMI_BOOL match=MMI_TRUE;
        
                for (j=0;j<ext_name_len;j++)
                {
                    if (buf_file_ext[j] != fmgr_filter[i].ext[j])
                    {
                        match = MMI_FALSE;
                        break;
                    }
                }
                
                if (match == MMI_TRUE)
                {
                    FMGR_FILTER_SET(file_type, fmgr_filter[i].type);
                    FMGR_FILTER_CLEAR(file_type, FMGR_TYPE_UNKNOW);
                    break;
                }
            }
        }

    #if defined(__DRM_V02__)
        if (FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_ODF))
        {
        	if (DRM_is_archive(handle, (PU16)path ) == MMI_FALSE)
            {	
            	S32 type;
                PU8 ext_name = NULL;
                FMGR_FILE_INFO_STRUCT file_info;
                S8 ptr[(FMGR_MAX_EXT_LEN +  1) *ENCODING_LENGTH]={0};
                    
                /* Single part ODF , get single part ODF content extension name */
                ext_name = (PU8)DRM_get_content_ext(handle, NULL);
        
                mmi_ucs2cpy((PS8) file_info.file_name, (PS8) L".");
    
                if (ext_name != NULL)
    			{
                    mmi_asc_n_to_ucs2(ptr, (PS8)ext_name, strlen((const char *)ext_name));
                }
                else
                {
                    memset(ptr, 0, sizeof(ptr));
                }
                mmi_ucs2cat((PS8) file_info.file_name, (PS8) ptr);
    
                /* get file type */
                type = (S32)mmi_fmgr_get_file_type_by_filename(file_info.file_name);

                FMGR_FILTER_SET(file_type, type);
            }
        }
    #endif /* __DRM_V02__ */

#if defined(__DRM_SUPPORT__)
        DRM_close_file(handle);
#else
        FS_Close(handle);
#endif /* #if defined(__DRM_SUPPORT__) */
        
        return FS_NO_ERROR;        
    }
    else
    {
        return FS_FILE_NOT_FOUND;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_file_group
 * DESCRIPTION
 *  check file type belongs to which file group
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_fmgr_get_file_group(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER file_type;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_fmgr_get_file_type(path, &file_type);

    if (result == FS_FILE_NOT_FOUND)
    {
        return FMGR_GROUP_UNKNOWN;
    }
    
    if (FMGR_FILTER_IS_SET_AUDIO(&file_type))
    {
        return FMGR_GROUP_AUDIO;
    }
    else if (FMGR_FILTER_IS_SET_IMAGE(&file_type))
    {
        return FMGR_GROUP_IMAGE;
    }
    else if (FMGR_FILTER_IS_SET_VIDEO(&file_type))
    {
        return FMGR_GROUP_VIDEO;
    }
    else if (FMGR_FILTER_IS_SET_SWFLASH(&file_type))
    {
        return FMGR_GROUP_SWFLASH;
    }
    else
    {
        return FMGR_GROUP_UNKNOWN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_forwardable_path
 * DESCRIPTION
 *  check the file path is on forwardable device or not
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_forwardable_path(PS8 path)
{
#if defined(__OTG_ENABLE__) || defined(__SIM_PLUS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = FMGR_REMOVABLE_STORAGE+1 ; i < FMGR_TOTAL_STORAGE; i++)
    {
        if (fmgr_p->drv_list[i][0] == path[0])
        {
            return MMI_TRUE;
        }
    }
#endif /* #if defined(__OTG_ENABLE__) || defined(__SIM_PLUS__) */    

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_skip_space
 * DESCRIPTION
 *  skip space in a string
 * PARAMETERS
 *  line        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
PS8 mmi_fmgr_skip_space(S8 *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ptr;
    S32 i = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = line;

    len = (mmi_ucs2strlen(line)) << 1;

    while (ptr[i] == ' ' && ptr[i + 1] == 0)
    {
        ptr += 2;
        if (i >= len)
        {
            break;
        }
    }
    return ptr;
}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_check_drm_right
 * DESCRIPTION
 *  check drm right for app
 * PARAMETERS
 *  file_path       [IN]        
 *  permission      [IN]        
 *  consume         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_check_drm_right(PU16 file_path, U8 permission, BOOL consume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file(file_path, FS_READ_ONLY, permission);
    if (handle >= FS_NO_ERROR)
    {
        /* DRM file */
        if (DRM_validate_permission(handle, NULL, permission) == FALSE)
        {
            DRM_close_file(handle);
            return FALSE;
        }
        if (consume)
        {
            DRM_consume_rights(handle, permission, NULL);
    }
        DRM_close_file(handle);
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_drm_file_type_by_path
 * DESCRIPTION
 *  get drm file type (single part file type)
 * PARAMETERS
 *  file_path       [IN]        
 *  permission      [IN]        
 *  consume         [IN]        
 * RETURNS
 *  ODF means multi part; otherwise means content file type
 *****************************************************************************/
S32 mmi_fmgr_get_drm_file_type_by_path(S8* file_path, FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__DRM_V02__)
    FS_HANDLE handle;
    PU8 ext_name = NULL;
    S8 ptr[(FMGR_MAX_EXT_LEN +  1) *ENCODING_LENGTH]={0};
    FMGR_FILE_INFO_STRUCT file_info;
#endif /* #if defined(__DRM_V02__) */
    S32 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(file_type);

#if defined(__DRM_V02__)
    if ( (mmi_ucs2ncmp((PS8)file_path + ((mmi_ucs2strlen((PS8)file_path)-4)<<1), (PS8)L".odf", 4) == 0) ||
         (mmi_ucs2ncmp((PS8)file_path + ((mmi_ucs2strlen((PS8)file_path)-4)<<1), (PS8)L".ODF", 4) == 0) )
    {
        handle = DRM_open_file((PU16) file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
    
        if (handle > FS_NO_ERROR)
        {
            if (DRM_is_archive(handle, (PU16)file_path ) == MMI_TRUE)
            {	
                /* multi part ODF */
                FMGR_FILTER_SET(file_type, FMGR_TYPE_ODF);
                type = FMGR_TYPE_ODF;
            }
            else
            {
                /* Single part ODF , get single part ODF content extension name */
                ext_name = (PU8)DRM_get_content_ext(handle, NULL);
        
                mmi_ucs2cpy((PS8) file_info.file_name, (PS8) L".");
    
                if (ext_name != NULL)
    			{
                    mmi_asc_n_to_ucs2(ptr, (PS8)ext_name, strlen((const char *)ext_name));
                }
                else
                {
                    memset(ptr, 0, sizeof(ptr));
                }
                mmi_ucs2cat((PS8) file_info.file_name, (PS8) ptr);
    
                /* get file type */
                type = (S32)mmi_fmgr_get_file_type_by_filename(file_info.file_name);
                
                FMGR_FILTER_SET(file_type, type);
                /* a single part odf is also a odf file */
                FMGR_FILTER_SET(file_type, FMGR_TYPE_ODF);
            }
    
            DRM_close_file(handle);
            return type;
        }
        else
        {
            return FS_FILE_NOT_FOUND;
        }
    }
    else
    {
        type = mmi_fmgr_get_file_type_by_filename((PS8)file_path);
        FMGR_FILTER_SET(file_type, type);
        return type;
    }
#else /* #if defined(__DRM_V02__) */
    {
        type = mmi_fmgr_get_file_type_by_filename((PS8)file_path);
        FMGR_FILTER_SET(file_type, type);
        return type;
}
#endif
}

#endif /* __DRM_SUPPORT__ */ 

#ifdef __MMI_FILE_MANAGER__

/******************************************************************************
 * Select drv
 ******************************************************************************/
static U8 fmgr_drv_hilite_id = 0;
static FmgrGetDrvfp g_fmgr_sel_drv_fp;
static U32 g_fmgr_sel_drv_highlight_storage;

#include "UserProfilesResDef.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_sel_drv_app_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_fmgr_sel_drv_app_cb(S8 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmgr_sel_drv_fp)
    {
        (*g_fmgr_sel_drv_fp) (drv);
    }
    g_fmgr_sel_drv_fp = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_sel_drv_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_sel_drv_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = fmgr_get_drive_index(fmgr_drv_hilite_id);
    S8 drv = fmgr_p->drv_list[index][0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_sel_drv_app_cb(drv);
    if( GetActiveScreenId() == SCR_FMGR_SEL_DRV)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_FMGR_SEL_DRV);
    }
//    fmgr_reset_app_select();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_sel_drv_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_sel_drv_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ClearAllKeyHandler(); */
    mmi_fmgr_sel_drv_app_cb(0);
    if( GetActiveScreenId() == SCR_FMGR_SEL_DRV)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_FMGR_SEL_DRV);
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_sel_drv
 * DESCRIPTION
 *  highlight handler for drive
 * PARAMETERS
 *  hiliteID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_sel_drv(S32 hiliteID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_drv_hilite_id = hiliteID;
    index = fmgr_get_drive_index(hiliteID);

#if defined(__DRM_MTK__)
    if (index == FMGR_DRM_RO_STORAGE)
    {
        /* not FMGR, can't enter DRM drive */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_fmgr_sel_drv_rsk_hdlr, KEY_EVENT_UP);
        /* Leo start 20050808 */
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_reset_list_item_selected_callback();
    #endif 
        /* Leo end 20050808 */
        return;
    }
#endif /* defined(__DRM_MTK__) */ 
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(mmi_fmgr_sel_drv_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_fmgr_sel_drv_rsk_hdlr, KEY_EVENT_UP);
    /* Leo start 20050808 */
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(mmi_fmgr_sel_drv_lsk_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_disp_sel_drv_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_disp_sel_drv_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 drive_count=0;
    U8 i;    
    S8 drv_idx;
    U32 highlight_item=0;
//    U16 iconId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (fmgr_p->drv_count == 0)
    {
    #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            DisplayPopup((PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        }
        else
    #endif /* __USB_IN_NORMAL_MODE__ */ 
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
        }

        mmi_fmgr_sel_drv_app_cb(0);
        if( GetActiveScreenId() == SCR_FMGR_SEL_DRV)
        {
            GoBackHistory();
        }
        else
        {
            DeleteScreenIfPresent(SCR_FMGR_SEL_DRV);
        }
        return;
    }

    /* get actual drive count */
    for (i = 0; i < fmgr_p->drv_count; i++)
    {
        drv_idx = fmgr_get_drive_index(i);

        if (g_fmgr_sel_drv_highlight_storage == 0)
        {
            /* it means the input high storage is 0; that is no default highlight */
            highlight_item = 0;
        }
        else
        {
            if (g_fmgr_sel_drv_highlight_storage == fmgr_p->drv_list[drv_idx][0])
            {
            #ifdef __DRM_MTK__
                if (drv_idx != FMGR_DRM_RO_STORAGE)
            #endif
                {
                    highlight_item = drive_count;
                }                    
            }                    
        }
        if (drv_idx >= FMGR_REMOVABLE_STORAGE)
        {
            /* test if card is actually present */
            if (FS_GetDevStatus(fmgr_p->drv_list[drv_idx][0], FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
            {
            #if defined(MT6223P)
                if (FS_GetDevStatus(fmgr_p->drv_list[drv_idx][0], FS_CARD_BATCHCOUNT_STATE_ENUM)==FS_NO_ERROR)
            #endif
                {
                    drive_count++;
                }
            }
        }
        else
        {
            drive_count++;
        }
    }

    if (drive_count==0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);

        mmi_fmgr_sel_drv_app_cb(0);
        if( GetActiveScreenId() == SCR_FMGR_SEL_DRV)
        {
            GoBackHistory();
        }
        else
        {
            DeleteScreenIfPresent(SCR_FMGR_SEL_DRV);
        }
        return;
    }

    EntryNewScreen(SCR_FMGR_SEL_DRV, NULL, mmi_fmgr_disp_sel_drv_scr, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_SEL_DRV);
    RegisterHighlightHandler(highlight_fmgr_sel_drv);

//    iconId = fmgr_get_app_title_icon_id();

    ShowCategory212Screen(
        STR_FMGR_SEL_DRV_TITLE,
        fmgr_p->app_icon, //0,//iconId,      
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,      /* lsk */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,    /* rsk */
        drive_count,
        mmi_fmgr_get_drv_item_callback,
        mmi_fmgr_get_drv_hint_callback,
        mmi_fmgr_draw_drv_info_callback,
        mmi_fmgr_hide_drv_info_callback,
        2,                  /* info box row count */
        0,                  /* info bg img id */
        highlight_item,
        (U8*) guiBuffer);

    if (drive_count == 0)
    {
        SetRightSoftkeyFunction(mmi_fmgr_sel_drv_rsk_hdlr, KEY_EVENT_UP);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_sel_drv_and_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id          [IN]        
 *  callback        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 void mmi_fmgr_sel_drv_and_enter(U8 app_id, FmgrGetDrvfp callback, S8 highlight_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* keep the application's callback */
    temp_id = fmgr_p->src_application;
    fmgr_p->src_application = app_id;
    fmgr_p->app_icon = fmgr_get_app_title_icon_id();
    fmgr_p->src_application = temp_id;

    g_fmgr_sel_drv_fp = callback;
    g_fmgr_sel_drv_highlight_storage = highlight_storage;

    mmi_fmgr_disp_sel_drv_scr();

}
 #endif /* #ifdef __MMI_FILE_MANAGER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_util_load_filepath
 * DESCRIPTION
 *  load file path from nvram path pool
 * PARAMETERS
 *  path_ptr        [IN]        Filepath buffer pointer. [NOTIC! size must be FMGR_PATH_BUFFER_SIZE]
 *  id              [IN]        Storage id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_util_load_filepath(PS8 path_ptr, FMGR_PATH_ID_ENUM id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg check */
    MMI_ASSERT(path_ptr != NULL);
    MMI_ASSERT(id < FMGR_PATH_ID_COUNT);

    /* if it is first time loaded form NVRAM, buffer will be all zero */

    /* load first 510 byte */
    ReadRecord(
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID,
        (U16) (id + 1),
        (void*)path_ptr,
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_SIZE,
        &error);

    /* load tail 10 byte */
    path_ptr += NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_SIZE;

    ReadRecord(
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID,
        (U16) (id + 1),
        (void*)path_ptr,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_SIZE,
        &error);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_util_store_filepath
 * DESCRIPTION
 *  store file path to nvram path pool
 * PARAMETERS
 *  path_ptr        [IN]        Filepath buffer pointer. [NOTIC! size must be FMGR_PATH_BUFFER_SIZE]
 *  id              [IN]        Storage id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_util_store_filepath(PS8 path_ptr, FMGR_PATH_ID_ENUM id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg check */
    MMI_ASSERT(path_ptr != NULL);
    MMI_ASSERT(id < FMGR_PATH_ID_COUNT);

    /* write first 510 byte */
    WriteRecord(
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID,
        (U16) (id + 1),
        (void*)path_ptr,
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_SIZE,
        &error);

    /* write tail 10 byte */
    path_ptr += NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_SIZE;

    WriteRecord(
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID,
        (U16) (id + 1),
        (void*)path_ptr,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_SIZE,
        &error);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_util_file_limit_check
 * DESCRIPTION
 *  util function for some api to check file's limit
 *  to gather all api's file decode limit here
 * PARAMETERS
 *  array_ptr           [IN]        Array pointer
 *  filename            [IN]        Filename
 *  error_str_pp        [OUT]       Error string pointer's ptr
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_fmgr_util_file_limit_check(const S32 *array_ptr, PS8 filename, PS8 *error_str_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_size;
    S32 image_width;
    S32 image_height;
    S32 result;
    U8 res_group_type;
    FS_HANDLE fs_handle;

    S8 str_buf[50];
    S8 unicode_buf[100];
    S32 *check_start_ptr;
    U16 resource_type;
    S16 jump;    

    S32 check_file_size;
    S32 check_image_width;
    S32 check_image_height;

#ifdef __MMI_VIDEO_PLAYER__
    mdi_video_info_struct vdo_info;
    S32 check_duration;
    PS8 ext_ptr;
#endif /* __MMI_VIDEO_PLAYER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    check_start_ptr = (PS32) array_ptr;

    /* assign buffer */
    *error_str_pp = g_fmgr_file_limit_error_str;
    memset(g_fmgr_file_limit_error_str, 0, FILE_LIMIT_ERROR_BUF_SIZE);

    if (filename == NULL)
    {
        FILE_LIMIT_FALSE_RETURN(FMGR_FS_INVALID_FILENAME_TEXT);
    }

    fs_handle = DRM_open_file((PU16) filename, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);

    if (fs_handle < 0)
    {
        FILE_LIMIT_FALSE_RETURN(FMGR_FS_FILE_NOT_FOUND_TEXT);
    }

    DRM_close_file(fs_handle);

    /* source from file */
    res_group_type = mmi_fmgr_get_file_group(filename);

    if (res_group_type == FMGR_GROUP_IMAGE)
    {
        /* images */
        jump = 4;
        resource_type = gdi_image_get_type_from_file(filename);

    }
    else if (res_group_type == FMGR_GROUP_VIDEO)
    {
        /* video */
    #ifdef __MMI_VIDEO_PLAYER__

	FMGR_FILTER file_type;
        jump = 5;

	mmi_fmgr_get_file_type((PS8) filename, &file_type);

	if (FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_3GP))
        {
            resource_type = GDI_IMAGE_TYPE_3GP_FILE;
        }
        else if (FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_MP4))
        {
            resource_type = GDI_IMAGE_TYPE_MP4_FILE;
        }
	else if (FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_AVI))
        {
            resource_type = GDI_IMAGE_TYPE_AVI_FILE;
        }
	else if (FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_MPG))
        {
            resource_type = GDI_IMAGE_TYPE_MPG_FILE;
        }
	else if (FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_3G2))
        {
            resource_type = GDI_IMAGE_TYPE_3G2_FILE;
        }    
        else
        {
            FILE_LIMIT_FALSE_RETURN(STR_FMGR_INVALID_FORMAT);
        }

    #endif /* __MMI_VIDEO_PLAYER__ */ 

    }
    else
    {
        /* do not have limit */
        return TRUE;
    }

    /* check if has limit */
    while (1)
    {
        if (*check_start_ptr == resource_type)
        {
            /* find limit */
            break;
        }

        check_start_ptr += jump;
        if (*check_start_ptr == END_LIMIT_ITEM)
        {
            /* all checked, no limitation */
            return TRUE;
        }
    };

    if (res_group_type == FMGR_GROUP_IMAGE)
    {
        check_start_ptr++;
        check_file_size = *check_start_ptr++;
        check_image_width = *check_start_ptr++;
        check_image_height = *check_start_ptr;

      /*******************************************/
        /* Image size checking                     */
      /*******************************************/
        if (check_image_width!=0 || check_image_height!=0)
        {
            result = gdi_image_get_dimension_file(filename, &image_width, &image_height);

            if ((result < 0) ||
                ( image_width == 0 || image_height == 0))
            {
                if (result == GDI_IMAGE_ENCODER_ERR_MEMORY_NOT_ENOUGH)
                {
                    FILE_LIMIT_FALSE_RETURN(STR_ID_FMGR_MEMORY_NOT_ENOUGH);
                }
                else
                {
                    FILE_LIMIT_FALSE_RETURN(STR_FMGR_INVALID_FORMAT);
                }
            }

            /* checking */
            if (((check_image_width != 0) && (image_width > check_image_width)) ||
                ((check_image_height != 0) && (image_height > check_image_height)))
            {
                mmi_ucs2ncpy(
                    g_fmgr_file_limit_error_str,
                    (PS8) (GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE)),
                    FILE_LIMIT_ERROR_STR_LEN);

                sprintf(str_buf, " %dx%d", (U16) check_image_width, (U16) check_image_height);
                mmi_asc_to_ucs2(unicode_buf, str_buf);

                mmi_ucs2cat(g_fmgr_file_limit_error_str, unicode_buf);

                /* avoid overflow - force have EOS */
                g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 1] = 0;
                g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 2] = 0;

                return FALSE;
            }
        }

      /*******************************************/
        /* Image file size checking (width/height) */
      /*******************************************/
        fs_handle = DRM_open_file((PU16) filename, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);

        if (fs_handle < 0)
        {
            FILE_LIMIT_FALSE_RETURN(FMGR_FS_FILE_NOT_FOUND_TEXT);
        }
        else
        {
            DRM_file_size(fs_handle, (PU32) & file_size );

            if (file_size == 0)
            {
                DRM_close_file(fs_handle);
                FILE_LIMIT_FALSE_RETURN(STR_FMGR_INVALID_FORMAT);
            }

            DRM_close_file(fs_handle);
        }


        if ((check_file_size != 0) && (file_size > (check_file_size * 1024)))
        {

            mmi_ucs2ncpy(
                g_fmgr_file_limit_error_str,
                (PS8) (GetString(STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE)),
                FILE_LIMIT_ERROR_STR_LEN);

            sprintf(str_buf, " %dk", (U16) check_file_size);
            mmi_asc_to_ucs2(unicode_buf, str_buf);

            mmi_ucs2cat(g_fmgr_file_limit_error_str, unicode_buf);

            /* avoid overflow - force have EOS */
            g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 1] = 0;
            g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 2] = 0;

            return FALSE;
        }

        /* all pass */
        return TRUE;

    }
    else if (res_group_type == FMGR_GROUP_VIDEO)
    {
        /* video */
    #ifdef __MMI_VIDEO_PLAYER__

        check_start_ptr++;
        check_file_size = *check_start_ptr++;
        check_duration = *check_start_ptr++;
        check_image_width = *check_start_ptr++;
        check_image_height = *check_start_ptr;

        ext_ptr = mmi_fmgr_extract_ext_file_name(filename);

         /*******************************************/
        /* Video file size checking                */
         /*******************************************/
        fs_handle = DRM_open_file((PU16) filename, FS_READ_ONLY, DRM_PERMISSION_PLAY);

        if (fs_handle < 0)
        {
            FILE_LIMIT_FALSE_RETURN(FMGR_FS_FILE_NOT_FOUND_TEXT);
        }
        else
        {
            DRM_file_size(fs_handle, (PU32) & file_size );

            if (file_size == 0)
            {
                DRM_close_file(fs_handle);

                FILE_LIMIT_FALSE_RETURN(STR_FMGR_INVALID_FORMAT);
            }

            DRM_close_file(fs_handle);
        }

        if ((check_file_size != 0) && (file_size > (check_file_size * 1024)))
        {
            mmi_ucs2ncpy(
                g_fmgr_file_limit_error_str,
                (PS8) (GetString(STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE)),
                FILE_LIMIT_ERROR_STR_LEN);

            sprintf(str_buf, " %dk", (U16) check_file_size);
            mmi_asc_to_ucs2(unicode_buf, str_buf);

            mmi_ucs2cat(g_fmgr_file_limit_error_str, unicode_buf);

            /* avoid overflow - force have EOS */
            g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 1] = 0;
            g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 2] = 0;

            return FALSE;
        }

         /*******************************************/
        /* Vdieo info checking  (width/height/dur) */
         /*******************************************/
        result = mdi_video_ply_open_clip_file(filename, &vdo_info);

        if (result < 0)
        {
            FILE_LIMIT_FALSE_RETURN(STR_FMGR_INVALID_FORMAT);
        }
        else
        {
            mdi_video_ply_close_clip_file();
        }

        if ((check_duration != 0) && (vdo_info.total_time_duration / 1000 > check_duration))
        {
            mmi_ucs2ncpy(
                g_fmgr_file_limit_error_str,
                (PS8) (GetString(STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LONG)),
                FILE_LIMIT_ERROR_STR_LEN);

            sprintf(str_buf, " %d", (U16) check_duration);
            mmi_asc_to_ucs2(unicode_buf, str_buf);

            mmi_ucs2cat(g_fmgr_file_limit_error_str, unicode_buf);
            mmi_ucs2cat(g_fmgr_file_limit_error_str, (PS8) (GetString(STR_SECONDS)));

            /* avoid overflow - force have EOS */
            g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 1] = 0;
            g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 2] = 0;

            return FALSE;
        }

        if (((check_image_width != 0) && (vdo_info.width > check_image_width)) ||
            ((check_image_height != 0) && (vdo_info.height > check_image_height)))
        {
            mmi_ucs2ncpy(
                g_fmgr_file_limit_error_str,
                (PS8) (GetString(STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LARGE)),
                FILE_LIMIT_ERROR_STR_LEN);

            sprintf(str_buf, " %dx%d", (U16) check_image_width, (U16) check_image_height);
            mmi_asc_to_ucs2(unicode_buf, str_buf);

            mmi_ucs2cat(g_fmgr_file_limit_error_str, unicode_buf);

            /* avoid overflow - force have EOS */
            g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 1] = 0;
            g_fmgr_file_limit_error_str[FILE_LIMIT_ERROR_BUF_SIZE - 2] = 0;

            return FALSE;
        }

        /* pass all */
        return TRUE;

    #else /* __MMI_VIDEO_PLAYER__ */ 
        FILE_LIMIT_FALSE_RETURN(STR_FMGR_INVALID_FORMAT);
        return FALSE;
    #endif /* __MMI_VIDEO_PLAYER__ */ 

    }

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_file_type_by_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmgr_get_file_type_by_filename(S8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 ext_ptr;
    S8 ext_name[20] = {0};
	U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext_ptr = mmi_fmgr_extract_ext_file_name(filename);

    memset(ext_name, 0, sizeof(ext_name));

    if (ext_ptr!=NULL)
    {
        mmi_ucs2_n_to_asc(ext_name, ext_ptr, 5 * ENCODING_LENGTH);
    }

    /* make upper */
    for (i = 0; i < 12; i++)
    {
        if (ext_name[i] != 0)
        {
            if (ext_name[i] >= 'a')
            {
                ext_name[i] -= 'a' - 'A';
            }
        }
    }

    for (i = 0; i < FMGR_MAX_FILTER_COUNT; i++)
    {
    	if (strcmp(ext_name, fmgr_filter[i].ext) == 0)
    	{
    		return fmgr_filter[i].type;
    	}
    }

	return FMGR_TYPE_UNKNOW;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_is_filename_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmgr_is_filename_valid(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ptr;
    S32 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = mmi_fmgr_skip_space((PS8) path);
    len = mmi_ucs2strlen(ptr);
    if (len == 0)
    {
        return MMI_FALSE;
    }
       
    if ((ptr[0] == '.') && (ptr[1] == 0))
    {
        return MMI_FALSE;
    }

    /* new file name can't contain: /, \, :, *, ?, ", <, >, |, or \n */
    while (len > 0)
    {
        len--;
        if ((ptr[len << 1] == '/' && ptr[(len << 1) + 1] == 0) 
            || (ptr[len << 1] == '\\' && ptr[(len << 1) + 1] == 0) 
            || (ptr[len << 1] == ':' && ptr[(len << 1) + 1] == 0)
            || (ptr[len << 1] == '*' && ptr[(len << 1) + 1] == 0) 
            || (ptr[len << 1] == '?' && ptr[(len << 1) + 1] == 0) 
            || (ptr[len << 1] == '"' && ptr[(len << 1) + 1] == 0)
            || (ptr[len << 1] == '<' && ptr[(len << 1) + 1] == 0) 
            || (ptr[len << 1] == '>' && ptr[(len << 1) + 1] == 0) 
            || (ptr[len << 1] == '|' && ptr[(len << 1) + 1] == 0)
            || (ptr[len << 1] == '\n' && ptr[(len << 1) + 1] == 0))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_full_storage_inline_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_get_full_storage_inline_list(S8 drv_letter, U8 *total_num, U32 *inline_list_p, U8 *highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nItems=0, i=0, index=0;
    S8 drv;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (highlight_item)
    {
        *highlight_item = 0;
    }
    if (total_num)
    {
        *total_num = 0;
    }
    
    /* phone 1*/
    if ((drv = fmgr_p->drv_list[FMGR_NAND_STORAGE][0]) != 0)
    {
        if (drv_letter == drv)
        {
            index = nItems;
        }
        fmgr_p->app_inline_storage_str_p[nItems]=(U8*)GetString(Fmgr_Drive_Info_Table[FMGR_NAND_STORAGE].drv_string_id);
        fmgr_p->app_inline_storage_list[nItems]=FMGR_NAND_STORAGE;
        nItems++;    
        }

    /* phone 2*/
    if ((drv=fmgr_p->drv_list[FMGR_NOR_STORAGE][0]) != 0)
    {
        if (drv_letter == drv)
        {
            index = nItems;
        }            
        fmgr_p->app_inline_storage_str_p[nItems]=(U8*)GetString(Fmgr_Drive_Info_Table[FMGR_NOR_STORAGE].drv_string_id);
        fmgr_p->app_inline_storage_list[nItems]=FMGR_NOR_STORAGE;
        nItems++;  
        }
 
#if defined(__FS_CARD_SUPPORT__)
    /* memory card */
    if ((drv=fmgr_p->drv_list[FMGR_REMOVABLE_STORAGE][0]) != 0)
    {
        if (drv_letter == drv)
        {
            index = nItems;
            }        
        fmgr_p->app_inline_storage_str_p[nItems]=(U8*)GetString(Fmgr_Drive_Info_Table[FMGR_REMOVABLE_STORAGE].drv_string_id);
        fmgr_p->app_inline_storage_list[nItems]=FMGR_REMOVABLE_STORAGE;
        nItems++;  
        }
#endif 

    for (i=FMGR_REMOVABLE_STORAGE+1;i<FMGR_TOTAL_STORAGE;i++)
    {
        if ((drv=fmgr_p->drv_list[i][0]) != 0)
        {
            if (drv_letter == drv)
            {
                index = nItems;
            }        
            fmgr_p->app_inline_storage_str_p[nItems]=(U8*)GetString(Fmgr_Drive_Info_Table[i].drv_string_id);
            fmgr_p->app_inline_storage_list[nItems]=i;
            nItems++;            
        }
    }

    /* set total num of list */
    if (total_num)    
    {
        *total_num = nItems;
    }

    if (inline_list_p)
    {
        *inline_list_p = (U32)fmgr_p->app_inline_storage_str_p;
    }
    
    if (highlight_item)
    {
        *highlight_item = index;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_exist_storage_inline_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_get_exist_storage_inline_list(S8 drv_letter, U8 *total_num, U32 *inline_list_p, U8 *highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nItems=0, i, index=0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (highlight_item)
    {
        *highlight_item = 0;
    }
    if (total_num)
    {
        *total_num = 0;
    }
    
    for (i=0;i<FMGR_TOTAL_STORAGE;i++)
    {
    #ifdef __DRM_MTK__
        if (i != FMGR_DRM_RO_STORAGE)
    #endif 
        {
            if (FS_GetDevStatus(fmgr_p->drv_list[i][0], FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
            {
                fmgr_p->app_inline_storage_str_p[nItems]=(U8*)GetString(Fmgr_Drive_Info_Table[i].drv_string_id);
                fmgr_p->app_inline_storage_list[nItems]=i;
                if (drv_letter == fmgr_p->drv_list[i][0])
                {
                    index = nItems;
                }
                nItems++;            
            }
        }
    }

    /* set total num of list */
    if (total_num)
    {
        *total_num = (U8)nItems;
    }

    if (inline_list_p)
    {
        *inline_list_p = (U32)fmgr_p->app_inline_storage_str_p;
    }
    
    if (highlight_item)
    {
        *highlight_item = index;
    }    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_drive_letter_by_inline_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_get_drive_letter_by_inline_index(U8 index, S8* drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 drv_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(drv_letter!=NULL);        
    
    drv_idx = fmgr_p->app_inline_storage_list[index];
    
    if (fmgr_p->drv_list[drv_idx][0] != 0)
    {
        *drv_letter = fmgr_p->drv_list[drv_idx][0];
    }
    else
    {
        *drv_letter = 0;
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_drive_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_get_drive_name(S8 drv_letter, S8* drv_name, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 length = len<(FMGR_MAX_DRIVE_NAME_LEN + 1) * ENCODING_LENGTH ? len : (FMGR_MAX_DRIVE_NAME_LEN + 1) * ENCODING_LENGTH;
    U8 i;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(drv_name!=NULL);    

    for (i=0;i<FMGR_TOTAL_STORAGE;i++)
    {
        if (drv_letter == fmgr_p->drv_list[i][0])    
        {
            mmi_ucs2ncpy(drv_name, (PS8)GetString(Fmgr_Drive_Info_Table[i].drv_string_id), length/ENCODING_LENGTH);  
            return;
        }
    }
    memset(drv_name, 0, length);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_drive_enum_by_letter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_get_drive_enum_by_letter(S8 drv_letter, S8* drv_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(drv_enum!=NULL);

    for (i=0;i<FMGR_TOTAL_STORAGE;i++)
    {
        if (drv_letter == fmgr_p->drv_list[i][0])
        {
            *drv_enum = i;
			return;
        }
    }

    /* it means no mapping drive enum */
    *drv_enum = FMGR_TOTAL_STORAGE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_is_drive_letter_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmgr_is_drive_letter_valid(S8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR unicode_buf[5] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((drv_letter>='A') && (drv_letter<='Z')) || ((drv_letter>='a') && (drv_letter<='z')))
	{
        kal_wsprintf(unicode_buf, "%c:\\", drv_letter);

        if (FS_GetDevType((PU16) unicode_buf) != FS_DRIVE_NOT_FOUND)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_exist_drive_letter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_get_exist_drive_letter(S8* drv_array, U8* num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nItems=0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(drv_array!=NULL);
    MMI_ASSERT(num!=NULL);    
    
    for (i=0;i<FMGR_TOTAL_STORAGE;i++)
    {
    #if defined(__DRM_MTK__)
        if (i != FMGR_DRM_RO_STORAGE)
    #endif 
        {
            if (FS_GetDevStatus(fmgr_p->drv_list[i][0], FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
            {
                drv_array[nItems++] =fmgr_p->drv_list[i][0];
            }
        }
    }
    
    *num = nItems;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_file_info_by_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmgr_get_file_info_by_path(S8* filepath, FMGR_FILE_INFO_STRUCT *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DOSDirEntry  file_info;
    S8              buf_file_name[FMGR_MAX_FILE_LEN * ENCODING_LENGTH];
    S8              buf_file_ext[FMGR_MAX_EXT_LEN * ENCODING_LENGTH];
    int             fh, i;
    U16             type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    memset(info, 0, sizeof(FMGR_FILE_INFO_STRUCT));
    FMGR_FILTER_INIT(&(info->file_type));

    /* the filepath must not end with '\\' */
    i = mmi_ucs2strlen(filepath);
    if(!i)
        return FS_FILE_NOT_FOUND;

    /* remove last '\\' if there is*/
    i--;
    if(((WCHAR*)filepath)[i] == '\\')
    {
        ((WCHAR*)filepath)[i] = 0;
    }
    else
        i = -1;

    fh = FS_FindFirst((WCHAR*)filepath, 0, 0, &file_info, (WCHAR*)buf_file_name, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);

    /* restore '\\' */
    if(i >= 0)
        ((WCHAR*)filepath)[i] = '\\';
    
    if(fh < 0)
        return fh;
    
    FS_FindClose(fh);

    info->is_short = file_info.NTReserved == FS_SFN_MATCH ? TRUE : FALSE;

    /* filename */
#ifndef __MMI_SHOW_FILE_EXT__
    /* remove extension */
    if (!(file_info.Attributes & FS_ATTR_DIR))
    {
        U16* ext;
        ext = (U16*)mmi_fmgr_extract_ext_file_name((PS8)buf_file_name);
        if(ext)
            *(ext-1) = 0;
    }
#endif 
    mmi_ucs2cpy(info->file_name, buf_file_name);

    /* extension */
    memset(buf_file_ext, 0, FMGR_MAX_EXT_LEN * ENCODING_LENGTH);
    mmi_asc_n_to_ucs2(buf_file_ext, (PS8) file_info.Extension, FMGR_MAX_EXT_LEN-1);
    for(i=0;i<FMGR_MAX_EXT_LEN;i++)
    {
        if(buf_file_ext[i*ENCODING_LENGTH] == ' ')
            buf_file_ext[i*ENCODING_LENGTH] = 0;
    }

#ifndef __MMI_SHOW_FILE_EXT__
    if(buf_file_ext[0])
    {
        /* add '.' to extension */
        info->file_ext[0] = '.';
        mmi_ucs2cpy(info->file_ext+2, buf_file_ext);
    }
#else 
    mmi_ucs2cpy(info->file_ext, buf_file_ext);
#endif 

    type = mmi_fmgr_get_file_type_by_filename(info->file_name);
    FMGR_FILTER_SET(&(info->file_type), type);

    info->index = 0;
    info->attribute = file_info.Attributes;
    info->time.nYear = file_info.DateTime.Year1980 + 1980;
    info->time.nMonth = file_info.DateTime.Month;
    info->time.nDay = file_info.DateTime.Day;
    info->time.nHour = file_info.DateTime.Hour;
    info->time.nMin = file_info.DateTime.Minute;
    info->time.nSec = file_info.DateTime.Second2;
    info->file_size = file_info.FileSize;
        
    return 0;
}

