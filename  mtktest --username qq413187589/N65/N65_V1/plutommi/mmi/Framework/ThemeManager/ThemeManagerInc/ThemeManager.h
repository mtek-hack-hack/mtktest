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
 * ThemeManager.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the header file for Theme Manager
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _THEME_MANAGER_H
#define _THEME_MANAGER_H

#include "MMI_features.h"
#include "CustThemesRes.h"
#include "FileMgr.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define     THEME_IMAGE_INFO_HEADER       (8)
#define     THEME_IMAGE_OFFSET            (4)
#define     THEME_FILE_HANDLE          (4)

#define     MAX_MMI_IMAGEID_IMAGES        (1393)        /* temp */

#define     MAX_SYSTEM_THEMES          (3)
#define     MAX_DOWNLOADED_THEMES         (20)
#define     TOTAL_THEMES_COUNT            (MAX_SYSTEM_THEMES+MAX_DOWNLOADED_THEMES)
#define     MAX_THEME_NAME_LENGTH         (FMGR_MAX_FILE_LEN)
#define     MAX_THEME_IMAGE_HEADER_LENGTH (THEME_IMAGE_INFO_HEADER+THEME_IMAGE_OFFSET+THEME_FILE_HANDLE)
#define     MAX_THEME_IMAGEID_IMAGES      (150)
#define     MAX_THEME_NON_IMAGEID_IMAGES  (50)
#define     MAX_DWNL_THM_PATH_LEN         (30)
#define     MAX_THEME_SEARCH_STR_LEN      (10)

#define     DOWNLOADED_THEMES_PATH        ":\\Themes\\"
#define     THEME_SEARCH_STR           "*.med"
#define     THEME_AUDIO_FILE           "ThemeAud.wav"
#define     THEME_AUDIO_MID_FILE       "ThemeAud.mid"
#define     THEME_AUDIO_MP3_FILE       "ThemeAud.mp3"
#define     THEME_AUDIO_FILE_PATH         "c:\\Audio\\"
#define     THEME_CHECKSUM_HEADER_SIZE    (4)
#define THEME_FILE_SIZE_HEADER (4)
#define THEME_NO_OF_BYTE_TO_CHECK_FOR_CRC (512000)      /* 0x80000 Bytes => 512 * 1024 = 524288 Bytes */
/* Added by TK on 20060325 */
#define     THEME_AUDIO_FOLDER_PATH       "c:\\Audio"
/* End */
#define THEME_AUDIO                    0        /* ritesh */
#define THEME_MIDI                     1        /* ritesh */
#define THEME_MP3                      2

#define THEME_ID                    U32
#define MAX_SUPPORTED_VERSION_NUM         1

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    THEME_TYPE_SYSTEM = 1,
    THEME_TYPE_DOWNLOADED_PHONE,
    THEME_TYPE_DOWNLOADED_CARD
} tm_theme_type_enum;

typedef enum
{
    THEME_ERROR_SUCCESS,
    THEME_ERROR_SPACE_NOT_AVAILABLE,
    THEME_ERROR_THEME_NOT_AVAILABLE,
    THEME_ERROR_FILE_FORMAT_BAD,
    THEME_ERROR_DELETE_FAILURE,
    THEME_ERROR_FAILURE,
    THEME_ERROR_ALREADY_ACTIVATED,
    THEME_ERROR_MAX_COUNT_REACHED,
    THEME_ERROR_INCOMING_CALL,
    THEME_ERROR_PROCESS_QUEUE_SUCESS,
    THEME_ERROR_VERSION_FAILURE,
    THEME_ERROR_LCD_SIZE_MISMATCH,
    THEME_ERROR_FILENAME_INCORRECT,
    THEME_ERROR_USB_MODE_ON,
    THEME_ERROR_PHONE_MODEL_MISMATCH
} tm_theme_error_enum;

typedef enum
{
    CHECKSUM_NOT_VERIFIED,
    CHECKSUM_VERIFIED_OK,
    CHECKSUM_VERIFIED_BAD
} tm_theme_checksum_enum;

typedef struct
{
    U8 theme_name[MAX_THEME_NAME_LENGTH *ENCODING_LENGTH];
    U32 theme_id;
    U8 theme_checksum_verified;
    U8 theme_type;
} tm_theme_list_struct;

typedef enum
{
    THEME_IMG_LOAD_NEVER,
    THEME_IMG_LOAD_ALWAYS,
    THEME_IMG_LOAD_ONDEMAND,
    THEME_IMG_LOAD_END
} tm_image_load_type_enum;

/*
 * typedef struct 
 * {
 * U16   image_id;
 * U32 image_offset;
 * } theme_image_detail_struct;
 * 
 * typedef struct 
 * {
 * MMI_theme*              theme;
 * theme_image_detail_struct* theme_image_details_list;
 * U8**                 system_image_list;
 * } theme_details_struct;
 */

typedef struct
{
    U8 *mempool_p;
    U32 current_offset;
    U32 total_pool_size;
    U16 unit_size;
} tm_theme_image_header_struct;

typedef struct
{
    S16 nOffset;
} tm_theme_image_cache_struct;

typedef struct
{
    U8 imageid_images_headers_pool[MAX_THEME_IMAGE_HEADER_LENGTH *MAX_THEME_IMAGEID_IMAGES];
    U8 non_imageid_images_headers_pool[MAX_THEME_IMAGE_HEADER_LENGTH *MAX_THEME_NON_IMAGEID_IMAGES];
    U8 theme_imageid_image_count;
    U8 total_thm_cnt;
    U8 sys_thm_cnt;
    U32 curr_activated_theme_id;
    U8 curr_activated_theme_type;
    U8 theme_has_wallpaper;
    U8 theme_has_screensaver;
    U8 theme_has_ringtone;
    U8 theme_has_alternate_image;
    S32 theme_file_handle;
    tm_theme_image_header_struct imageid_images_headers;
    tm_theme_image_header_struct non_imageid_images_headers;
    theme_image_detail_struct theme_image_list[MAX_THEME_IMAGEID_IMAGES];       /* theme_image_detail defined in custThemeRes.c */
    tm_theme_image_cache_struct image_cache[MAX_THEME_IMAGEID_IMAGES];
} tm_context_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#ifdef __MMI_DLT_CACHE_SUPPORT__
extern void mmi_tm_clear_ondemand_cache(void);
extern tm_image_load_type_enum mmi_tm_get_image_load_type(U32 img_list_index);
extern PU8 mmi_tm_find_img_in_cache(U32 img_list_index, tm_image_load_type_enum type);
extern PU8 mmi_tm_add_img_id_to_cache(U32 img_list_index, U32 image_offset, tm_image_load_type_enum type);
extern PU8 mmi_tm_add_to_DLT_img_cache(U32 image_offset, tm_image_load_type_enum type);
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 

extern void mmi_tm_handle_file_access_failed(void);
extern U8 mmi_tm_get_downloaded_themes(tm_theme_type_enum theme_type);
extern void mmi_tm_set_imageid(U16 image_id, U32 image_offset, tm_image_load_type_enum type);
extern PU8 mmi_tm_create_non_imageid_image(U32 image_offset, tm_image_load_type_enum type);
extern tm_theme_error_enum mmi_tm_activate_theme(THEME_ID theme_id);
extern tm_theme_error_enum mmi_tm_activate_downloaded_theme(tm_theme_list_struct *theme_struct_p);
extern tm_theme_error_enum mmi_tm_activate_theme_from_fmgr(tm_theme_type_enum theme_type, U8 *theme_name_p, MMI_BOOL is_short);
extern tm_theme_error_enum mmi_tm_delete_theme(THEME_ID theme_id, PS32 error_type);
extern void mmi_tm_reset_imageid_image_header_pool(void);
extern void mmi_tm_reset_non_imageid_image_header_pool(void);
extern void mmi_tm_create_image_header_pool(
                tm_theme_image_header_struct *ds_p,
                void *mempool_p,
                U16 unit_size,
                U32 total_pool_size);
extern void *mmi_tm_add_image_header_to_pool(tm_theme_image_header_struct *ds_p, void *buff_p);
extern void mmi_tm_reset_image_header_pool(tm_theme_image_header_struct *ds_p);
extern void *mmi_tm_get_downloaded_theme_image(U32 image_offset, S32);
extern BOOL mmi_tm_get_usb_mode(void);
extern tm_theme_error_enum mmi_tm_delete_theme_from_fmgr(
                            tm_theme_type_enum theme_type,
                            U8 *theme_name_p,
                            PS32 error_type);
extern U8 mmi_tm_is_theme_dirty_bit_set(U16 image_index);
extern U32 mmi_tm_get_theme_image_offset_or_index(U16 image_id, S32 *nArrayIndex_p);
extern const FLOAT *mmi_tm_get_theme_version_table(void);
extern void mmi_tm_handle_theme_activation_error_status(U16 status);
extern pBOOL mmi_tm_get_current_theme_ringtone(void);
extern MMI_BOOL mmi_tm_checkfile_exists(PS16);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

extern void mmi_theme_manager_init(void);   /* Theme Manager intialization */
extern void *mmi_tm_get_system_theme_image(U32 image_index);
extern void mmi_tm_handle_audio(U32 audio_offset, U32 audio_size);
extern void mmi_tm_sort_theme_image_table(void);
extern void mmi_tm_image_table_quick_sort(U16, U16);
extern void mmi_tm_image_table_insertion_sort(U16, U16);
extern void mmi_tm_image_table_swap_node(U16, U16);
extern U8 mmi_tm_get_themes(tm_theme_list_struct **theme_list_p);
extern tm_theme_error_enum mmi_tm_verify_theme_checksum(U8 *file_name_p);      /* temp */
extern U32 mmi_tm_get_current_theme_id(void);
extern U8 mmi_tm_get_curr_theme_type(void);
extern U8 mmi_tm_get_total_themes_count(void);
extern void mmi_tm_activate_theme_at_bootup(void);
extern pBOOL mmi_tm_get_current_theme_wallapaper(void);
extern pBOOL mmi_tm_get_current_theme_screensaver(void);
extern U8 mmi_tm_does_theme_have_alt_image(void);
extern tm_theme_error_enum mmi_tm_activate_system_theme(tm_theme_list_struct *theme_struct_p);
extern S8 *mmi_tm_get_audio_filename(U8 index);
extern void mmi_tm_set_was_theme_alarm_cb(void);

#ifdef __DLT_ENABLE_PROCESS_QUEUE__
extern theme_error_enum mmi_tm_theme_process_queue(void);
#endif 

extern BOOL mmi_tm_theme_version_and_deviceinfo_check(tm_theme_list_struct *theme_struct_p);

#endif /* _THEME_MANAGER_H */ 

