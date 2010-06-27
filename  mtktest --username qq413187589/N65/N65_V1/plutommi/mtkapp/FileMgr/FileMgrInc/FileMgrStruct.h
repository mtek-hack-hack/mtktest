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
 *  FileMgrStruct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _FILE_MGR_STRUCT_H_
#define _FILE_MGR_STRUCT_H_

#ifndef __FILE_MANAGER_GPROT_H_
#error "Please include FileManagerGProt.h first"
#endif 

#if defined(FMGR_USING_CACHE)

typedef struct
{
    BOOL is_used;
    U16 unused_duration;    /* unused counter larger means has not been used for longer time */
    U16 seq_number;
    U16 menuitem_idx;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    gdi_image_cache_bmp_struct bmp;
} fmgr_thumb_image_cache_struct;

typedef struct
{
    BOOL is_used;
    gdi_handle handle;  /* decoder handle */
    U16 menuitem_idx;
    S32 draw_pos_x;
    S32 draw_pos_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 icon_offset_x;
    S32 icon_offset_y;
    S32 icon_width;
    S32 icon_height;
    PU8 icon_ptr;
    BOOL is_hilighted;
    U16 ui_style;
} fmgr_thumb_image_handle_struct;

typedef struct
{
    fmgr_thumb_image_cache_struct *image_cache_list[FMGR_THUMB_IMAGE_CACHE_MAX_COUNT];
    fmgr_thumb_image_handle_struct *image_handle_list[FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT];

    S32 image_size;             /* image widht, image height */
    U32 image_decode_seq_num;
    U16 image_cache_item_count; /* may cache how many images */
} fmgr_image_cache_struct;

typedef struct
{
    S32 item_idx;
    S32 menuitem_offset_x;
    S32 menuitem_offset_y;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 icon_offset_x;
    S32 icon_offset_y;
    S32 icon_width;
    S32 icon_height;
    PU8 icon_ptr;
    BOOL is_hilighted;
    U16 ui_style;
} fmgr_delay_decode_struct;

#endif /* defined(FMGR_USING_CACHE) */ 

typedef struct
{
    S32 key;
    S32 index;
} fmgr_parent_idx_cache_struct;

/* file manager's context structure */
typedef struct
{
#if defined(FMGR_USING_CACHE)
    fmgr_image_cache_struct image_cache;
    fmgr_delay_decode_struct delay_decoder[FMGR_DELAY_DECODER_COUNT];
    BOOL is_decoder_create;
    U16 decoding_count;
#endif /* defined(FMGR_USING_CACHE) */ 
    FS_Pattern_Struct filter_pattern[FMGR_MAX_FILTER_COUNT];
    FMGR_FILE_INFO_STRUCT file_cache[FMGR_CACHE_ENTRY_COUNT];
    S8 file_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];
    S8 old_file_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];
    S8 new_file_name[(FMGR_MAX_FILE_LEN + 1) *ENCODING_LENGTH];
    S8 parent_name[(FMGR_MAX_FILE_LEN + 1) *ENCODING_LENGTH];
    PS8 ext_name;
#ifdef __DRM_SUPPORT__
    S8 rights_issuer[MAX_LINE_LENGTH];
#endif 
#ifdef __MMI_DOWNLOAD_AGENT__
    S8 da_file_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];
#endif 
    S8 drv_list[FMGR_TOTAL_STORAGE][12];    /* in ascii format */
    U8 drv_count;
    U8 src_application; /* idle screen and the menu one
                           level upper than FMGR need to
                           reset fmgr_p->src_application */
    U8 sel_type;
    U8 tree_action;
    U8 drive_action;
    U8 delete_all;
    U16 file_count;
    U16 cache_start_idx;
    U16 cache_end_idx;
    U16 sort_option /*= FS_SORT_BY_NAME */ ;
    FMGR_FILTER filter_type;
    FMGR_FILTER delete_filter_type;
    S32 cur_index;

    pBOOL enter_folder;
    pBOOL audio_state;
    PsExtFuncPtr app_callback;
    U16 active_explorer_screen;
    scrolling_text scroll_text;

    /* UI use */
    U16 delay_decode_index;

    pBOOL is_fmgr_busy;

    U16 app_icon;

    U8 app_inline_storage_list[FMGR_TOTAL_STORAGE];    
    U8 *app_inline_storage_str_p[FMGR_TOTAL_STORAGE];

    U8 cur_parent_hilite_layer;

//#if defined(MT6223P)
    fmgr_parent_idx_cache_struct parent_idx_hash_table[FMGR_PARENT_INDEX_NUM];
    U8 cur_hash_index;
//#endif /* MT6223P */

    BOOL kernel_init_include_dir;

    
} fmgr_context_struct;

#endif /* _FILE_MGR_STRUCT_H_ */ 

