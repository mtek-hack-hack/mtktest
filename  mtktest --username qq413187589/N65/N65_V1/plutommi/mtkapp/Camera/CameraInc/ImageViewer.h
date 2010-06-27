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
 *  ImageViewer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer's header file
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
#ifndef _IMAGE_VIEWER_H_
#define _IMAGE_VIEWER_H_

#include "MMI_features.h"
#include "mmi_features_camera.h"
#include "L4Dr.h"
#include "FileManagerGprot.h"

#if defined(__MMI_NONBLOCKING_DECODE__)
#define __MMI_IMGADV_NONBLOCKING_DECODE__
#endif


#ifndef __FILE_MANAGER_GPROT_H_
#error "Please include FileManagerGprot.h before imageviewer.h"
#endif 

#ifdef __MMI_IMAGEVIEWER_ADV__
    #ifndef _FILE_MGR_H_
    #error "Please include FileMgr.h before imageviewer.h"
    #endif 
#endif

#include "gui_windows.h"

#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)
/************************************************************************/
/* Define, Struct, Enum                                                 */
/************************************************************************/

#define MMI_IMGVIEW_OK                0
#define MMI_IMGVIEW_ERROR -1
#define MMI_IMGVIEW_ERRTYPE_DRM_INVALID      -2
#define MMI_IMGVIEW_ERRTYPE_DRM_MULTIPART    -3

#define MMI_IMGVIEW_STORAGE_FILEPATH_PHONE            FMGR_DEFAULT_FOLDER_PHOTOS
#define MMI_IMGVIEW_STORAGE_FILEPATH_MEMORY_CARD      FMGR_DEFAULT_FOLDER_PHOTOS

#ifdef __DRM_SUPPORT__
extern void mmi_imgview_start_consume(void);
extern S32 mmi_imgview_get_drm_result(void);
extern void mmi_imgview_pause_drm_consume_if_need(void);
typedef enum
{
    IMGVIEW_DRM_STATE_EXIT = 0,
    IMGVIEW_DRM_STATE_CONSUME,    
    IMGVIEW_DRM_STATE_PAUSE,

    IMGVIEW_DRM_STATE_TOTAL_COUNT
}imgview_drm_state_enum;

typedef enum
{
    IMGVIEW_DRM_NOT_DRM_FILE = 0,
    IMGVIEW_DRM_DRM_FILE = 0x00000001,
    IMGVIEW_DRM_DISPLAY_VALID = 0x00000010,
    IMGVIEW_DRM_PRINT_VALID   = 0x00000100,
    IMGVIEW_DRM_MULTI_PART   = 0x00001000,
    IMGVIEW_DRM_MIMETYPE_NON_IMAGE= 0x00010000
  
}imgview_drm_ret_enum;

#endif



typedef struct
{
    S8 *filepath;
    S8 *count_str;
    U16 storage;
    BOOL is_storage_path_changed;
    BOOL is_storage_ready;
    BOOL imgview_rotate;
    U32 drv_inline_list_p;
    #if defined(__MMI_BPP_SUPPORT__)
    U8                          *bpp_caption;
    U8                          *bpp_filepath;
    U32                         file_size;
    #endif
    FMGR_FILTER file_type;
    BOOL is_short;
    U16 image_type;
    U16 title_icon;
    BOOL is_printing;

    U16                         err_str_ptr;
    GDI_RESULT                         result;
#ifdef __DRM_SUPPORT__
    imgview_drm_state_enum       drm_state;
    U32                          drm_id;
    imgview_drm_ret_enum         drm_valid;
    FS_HANDLE                    drm_handle;
#endif

} imgview_context_struct;

typedef enum
{
    IMGVIEW_VIEW_STYLE_LIST,
    IMGVIEW_VIEW_STYLE_MATRIX
} imgview_view_style_enum;

/*********** Storage ***********/
typedef enum
{
    MMI_IMGVIEW_STORAGE_PHONE,
    MMI_IMGVIEW_STORAGE_MEMORY_CARD,
    MMI_IMGVIEW_STORAGE_TOTAL
} mmi_imgview_storage;

typedef enum _cat226_layout_enum
{
    IMGVIEW_VERTICAL_NORMAL,
    IMGVIEW_VERTICAL_FULLSCREEN,
    IMGVIEW_HORIZONTAL_NORMAL,
    IMGVIEW_HORIZONTAL_FULLSCREEN
} cat226_layout_enum;

/************************************************************************/
/* Extern Variable                                                      */
/************************************************************************/
extern imgview_context_struct g_imgview_context;


/************************************************************************/
/* Extern Functions                                                     */
/************************************************************************/
extern void mmi_imgview_init_app(void);
extern void mmi_imgview_entry_app(void);
extern void mmi_imgview_entry_option_screen(void);
extern void mmi_imgview_exit_from_fmgr(void *filename, int is_shot);
extern void mmi_imgview_exit_from_fmgr_emptry_folder(void);
extern void mmi_imgview_entry_view_detail_screen(void);
extern void mmi_imgview_load_setting(void);
extern void mmi_imgview_restore_setting(void);
extern BOOL mmi_imgview_get_storage_file_path(PS8 filepath);
extern U16  mmi_imgview_get_view_style(void);
extern S32  mmi_imgview_create_file_dir(PS8 filepath);
extern void mmi_imgview_remove_screen_if_present(U8 app_id);
extern void mmi_imgview_get_drive_callback( S8 drv_letter );
extern U8 mmi_imgview_del_scr_callback(void* ptr);
extern U8 mmi_imgview_view_from_fmgr_del_scr_callback(void* ptr);
extern void mmi_imgview_view_image_hdlr(PS8 file_path,BOOL is_short,FMGR_FILTER file_type, U16 title_icon);

#if defined(__MMI_BPP_SUPPORT__)
extern BOOL mmi_imgview_is_printing(void);
extern void mmi_imgview_cancel_printing(void);
extern void mmi_imgview_deinitial_printing(void);
extern void mmi_imgview_bpp_print(void);
extern void mmi_imgview_bpp_print_file(PS8 filepath,BOOL is_short);
extern void mmi_imgview_bpp_print(void);
#endif

#ifdef __MMI_IMAGEVIEWER_ADV__
/************************************************************************/
/* Imagviewer ADV                                                       */
/************************************************************************/
#ifdef __DRM_SUPPORT__
typedef enum
{
    IMGADV_DRM_STATE_EXIT = 0,
    IMGADV_DRM_STATE_CONSUME,
    IMGADV_DRM_STATE_PAUSE,
    IMGADV_DRM_STATE_DECODING,

    IMGADV_DRM_STATE_TOTAL_COUNT
}imgadv_drm_state_enum;

typedef enum
{
    IMGADV_DRM_NOT_DRM_FILE = 0,
    IMGADV_DRM_DRM_FILE = 0x00000001,
    IMGADV_DRM_DISPLAY_VALID = 0x00000010,
    IMGADV_DRM_PRINT_VALID   = 0x00000100,
    IMGADV_DRM_MULTI_PART   = 0x00001000,
    IMGADV_DRM_MIMETYPE_NON_IMAGE= 0x00010000
  
}imgadv_drm_ret_enum;

#endif

typedef struct
{
	BOOL is_show;
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    BOOL is_press;
} imgadv_osd_icon_struct;

typedef struct 
{
	U8		r;
	U8		g;	
	U8		b;		
	U8		style_r;
	U8		style_g;	
	U8		style_b;
	U16	    style;	
} imgadv_style_text_struct;

typedef struct
{
	BOOL	is_show;
	S32 	offset_x;
	S32 	offset_y;
	S32	    width;
	S32 	height;

} imgadv_osd_title_struct;


typedef struct 
{
    imgadv_osd_title_struct title;
    imgadv_osd_title_struct num_count;

    imgadv_osd_icon_struct  larrow;
    imgadv_osd_icon_struct  rarrow;
    imgadv_osd_icon_struct  zoomin;    
    imgadv_osd_icon_struct  zoomout;    
    imgadv_osd_icon_struct  rotate;    

    
}imgadv_osd_layout_struct;

typedef struct
{
    S32     map_offset_x;
    S32     map_offset_y;
    S32     width;
    S32     height;
    S32     wnd_offset_x;
    S32     wnd_offset_y;
    S32     wnd_width;
    S32     wnd_height;
    float   ratio_map_to_image;
    float   ratio_map_to_thumbnail;
    float   ratio_map_to_resized_image;
    float   ratio_width_to_height;
    pBOOL   is_zoomin_able;
    U16     zoom_factor_cnt;
    U16     max_zoom_factor;
    float   zoom_factor;
    
}imgadv_map_struct;

typedef struct 
{
    S8                          *filepath;
    S8                          *count_str;
    S8                          *buf_filename_no_ext;
    U8                          imgview_rotate;
    PU8                         thumbnail_buf_ptr;
    PU8                         cache_buf_ptr;

#ifdef __DRM_SUPPORT__
    imgadv_drm_state_enum       drm_state;
    U32                         drm_id;
    imgadv_drm_ret_enum         drm_valid;
    FS_HANDLE                   drm_handle;
#endif
    U16                         image_type;
    S32                         image_width;
    S32                         image_height;
    U32                         file_size;    
    S32                         resized_img_width;
    S32                         resized_img_height;
    S32                         cache_layer_width;
    S32                         cache_layer_height;
    S32                         thumbnail_layer_width;
    S32                         thumbnail_layer_height;    
    S32                         total_count;
#ifdef __MMI_TVOUT__
    S32                         tvout_width;
#endif
    pBOOL                       is_short;
    pBOOL                       is_width_dominate;
    pBOOL                       is_permitted;
    pBOOL                       is_resume;
    pBOOL                       is_gif_file;
    pBOOL                       is_initialized;
    pBOOL                       is_trigger_by_keypad;
    pBOOL                       is_reset_application;
    pBOOL                       is_err_displayed;

    GDI_RESULT                  result;
    PS8                         err_str_ptr;

    scrolling_text              scrolling_title;
    pBOOL                       is_scrolling_title;
        
    gdi_handle                  base_layer_handle;
    gdi_handle                  thumbnail_layer_handle;
    gdi_handle                  cache_layer_handle;
    gdi_handle                  animation_on_tv;
    gdi_handle                  nb_handle;
    
    imgadv_map_struct           map;
    imgadv_osd_layout_struct    *active_osd_layout_ptr;
    imgadv_osd_icon_struct      lsk;
    imgadv_osd_icon_struct      rsk;
    U16                         touch_object;
#ifdef __MMI_TOUCH_SCREEN__
    S32                         pen_down_x;
    S32                         pen_down_y;
    pBOOL                       is_pen_down;
#endif /* __MMI_TOUCH_SCREEN__ */ 

}imgadv_context_struct;

#define MMI_IMGADV_OK                0
#define MMI_IMGADV_ERROR            -1
#define MMI_IMGADV_DRM_INVALID      -2
#define MMI_IMGADV_INVALID_FORMAT   -3
#define MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR -4
#define MMI_IMGADV_FIRST_TIME_DECODE_ERR -5

#define MMI_IMGADV_LAYER_SIZE (((LCD_WIDTH*LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))

#define MMI_IMGADV_TOTAL_MEMORY_SIZE (MMI_IMGADV_LAYER_SIZE*2 + FMGR_PATH_BUFFER_SIZE*2 + 60)

extern void mmi_imgadv_entry_app_screen(void);
extern void mmi_imgadv_exit_app_screen(void);
extern void mmi_imgadv_reset_app(void);

#else
#define MMI_IMGADV_TOTAL_MEMORY_SIZE (0)
#endif /* __MMI_IMAGEVIEWER_ADV__ */

#endif /* __MMI_IMAGE_VIEWER__ */ 
#endif /* _IMAGE_VIEWER_H_ */ 

