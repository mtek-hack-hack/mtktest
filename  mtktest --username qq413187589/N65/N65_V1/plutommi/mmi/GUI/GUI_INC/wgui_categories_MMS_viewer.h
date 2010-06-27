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
 *   wgui_categories_MMS_viewer.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header File for the MMS Viewer Category
 *
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __WGUI_CATEGORIES_MMS_VIEWER_H__
#define __WGUI_CATEGORIES_MMS_VIEWER_H__

#include "MMI_features.h"
#ifdef __UI_MMS_VIEWER_CATEGORY__

#include "wgui_draw_manager.h"
#include "wgui_inputs.h"

/* Slide Related Data structures */

typedef enum
{
    WGUI_MV_STYLE_NORMAL,
    WGUI_MV_STYLE_ITALIC,
    WGUI_MV_STYLE_BOLD,
    WGUI_MV_STYLE_MAX
} wgui_mv_font_style_enum;

typedef enum
{
    WGUI_MV_DRAWABLE_MEDIA_ON_TOP,
    WGUI_MV_DRAWABLE_MEDIA_ON_BOTTOM,
    WGUI_MV_DRAWABLE_MEDIA_LAYOUT_MAX
} wgui_mv_slide_layout_enum;

/* 
 * Extern Global Variable
 */

typedef struct
{
    PU16 alt_str;
    U32 id;
    U16 begin;
    U16 end;
} wgui_mv_object_info_struct;

typedef struct
{
    U32 id; /* fill zero */
    U32 background_color;
    U32 foreground_color;
    PU16 alt_str;

    U16 str_id;
    
    U16 begin;
    U16 end;
    wgui_mv_font_style_enum txtStyle;
    WGUI_FONT_SIZE txtSize;
} wgui_mv_text_object_info_struct;

typedef struct wgui_mv_slide_struct_t
{
/* WARNING:: sizeof(wgui_mv_slide_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
    struct wgui_mv_slide_struct_t *next;
    struct wgui_mv_slide_struct_t *previous;

    wgui_mv_text_object_info_struct text;
    wgui_mv_object_info_struct image;
    wgui_mv_object_info_struct audio;
    wgui_mv_object_info_struct video;
    U16 duration;
    U16 slide_num;
} wgui_mv_slide_struct;

typedef struct
{
    wgui_mv_slide_struct *slide_head;
    wgui_mv_slide_struct *current_slide;

    U32 background_color;
    U32 foreground_color;

    U16 slide_timing;

    U16 current_slide_num;
    U16 total_slide_num;
    MMI_BOOL show_attachment_icon;

    wgui_mv_slide_layout_enum layout;
} wgui_mv_xml_msg_struct;

/* Internal Category Data Structures */
/* Layout Related */
/* Both ProgressBar and Infobar need to be of same height as they may overlap */

#if defined(__MMI_MAINLCD_320X240__)
#define CAT630_MIN_LINE_HEIGHT 26
#define CAT630_ARROW_GAP 6
#define CAT630_HMARGIN 6
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 10
#define CAT630_FONT        (&MMI_medium_font)

#elif defined(__MMI_MAINLCD_240X320__)
#define CAT630_MIN_LINE_HEIGHT 26
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 6
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 6
#define CAT630_FONT        (&MMI_medium_font)

#elif defined(__MMI_MAINLCD_176X220__)
#define CAT630_MIN_LINE_HEIGHT 20
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 6
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 6
#define CAT630_FONT        (&MMI_medium_font)

#elif defined(__MMI_MAINLCD_128X160__)
#define CAT630_MIN_LINE_HEIGHT 19
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 3
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 6
#define CAT630_FONT        (&MMI_medium_font)

#else /* 128x128 display */
#define CAT630_MIN_LINE_HEIGHT 19
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 3
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 6
#define CAT630_FONT        (&MMI_medium_font)

#endif 

#define CAT630_ERROR_TEXT_HEIGHT (MMI_MENUITEM_HEIGHT * 3)

#define CAT630_PBAR_BG_COLOR    UI_COLOR_GREY
#define CAT630_PBAR_FONT_COLOR  UI_COLOR_BLACK
#define CAT630_IBAR_FONT_COLOR  UI_COLOR_WHITE
#define CAT630_SLIDE_TIME_UNIT (1000)
#define CAT630_SLIDE_SWITCH_GAP_TIME (200)
/* num of characters supplied directly to multiline */

/* WARNING:: MMI_MV_TXT_INPUTBOX_BUFFER_SIZE is affected by CAT630_MAIN_TXT_BUFFER_SIZE */
#define CAT630_MAIN_TXT_BUFFER_SIZE (GUI_PAGE_SIZE * PAGE_MAX + (GUI_SHARED_BYTES))

#define WGUI_MV_REDRAW_NEEDED 1
#define WGUI_MV_REDRAW_NOT_NEEDED 0
#define WGUI_MV_BUTTON_PRESSED_STATE 1
#define WGUI_MV_BUTTON_RELEASED_STATE 0
#define WGUI_MV_VFN_LEN (FS_GenVFN_SIZE+12) /* FMGR_MAX_EXT_LEN =5 plus one for '.' dot */

/* Enumerations */
typedef enum 
{
    WGUI_MV_LAYOUT_TYPE_INDEPENDENT_PROGRESS_BAR,
    WGUI_MV_LAYOUT_TYPE_OVERLAPPING_PROGRESS_BAR,
    WGUI_MV_LAYOUT_MAX
} wgui_mv_layout_type_enum;

typedef enum 
{
    WGUI_MV_EVENT_SHOW_START,
    WGUI_MV_EVENT_SHOW_NEXT_SLIDE,
    WGUI_MV_EVENT_SHOW_PREVIOUS_SLIDE,
    WGUI_MV_EVENT_PLAY_START,
    WGUI_MV_EVENT_PLAY_PREVIOUS_SLIDE,
    WGUI_MV_EVENT_PLAY_NEXT_SLIDE,
    WGUI_MV_EVENT_STOP_PLAY_START_SHOW,
    WGUI_MV_EVENT_STOP_EVENT,
    WGUI_MV_EVENT_MAX
} wgui_mv_event_enum;

typedef enum 
{
    WGUI_MV_STATE_INIT_SLIDE,
    WGUI_MV_STATE_DEINIT_SLIDE,
    WGUI_MV_STATE_PLAYING,
    WGUI_MV_STATE_SHOWING,
    WGUI_MV_STATE_ERROR,
    WGUI_MV_STATE_MAX
} wgui_mv_state_enum;

typedef enum 
{
    WGUI_MV_DRAWABLE_MEDIA_EVENT_HIDE,
    WGUI_MV_DRAWABLE_MEDIA_EVENT_PLAY,
    WGUI_MV_DRAWABLE_MEDIA_EVENT_SHOW_STOPPED,
    WGUI_MV_DRAWABLE_MEDIA_EVENT_SCROLL,
    WGUI_MV_DRAWABLE_MEDIA_EVENT_REDRAW,
    /*
     * The media's draw function maybe called by multiline incase it is redrawing the text control
     * * at which time no of the other events would be cause of the redraw. The category can decide based on
     * * current state if redraw needs to be handled or not. 
     */
    WGUI_MV_DRAWABLE_MEDIA_EVENT_MAX
} wgui_mv_drawable_media_event_enum;

typedef enum 
{
    WGUI_MV_DRAWABLE_MEDIA_STATE_HIDDEN,
    WGUI_MV_DRAWABLE_MEDIA_STATE_PLAYING,
    WGUI_MV_DRAWABLE_MEDIA_STATE_SHOWING,
    WGUI_MV_DRAWABLE_MEDIA_STATE_SROLLING,
    WGUI_MV_DRAWABLE_MEDIA_STATE_MAX
} wgui_mv_drawable_media_state_enum;

typedef enum 
{
    WGUI_MV_CAT_PEN_INFOBAR_EVENT,
    WGUI_MV_CAT_PEN_VIEW_EVENT,
    WGUI_MV_CAT_PEN_IGNORE_EVENT
} wgui_mv_cat_pen_event_enum;

/* Function Pointers */
typedef void (*wgui_mv_drawable_media_cb) (MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1,
                                              S32 clip_x2, S32 clip_y2);
typedef void (*softkey_fn) (void);

/* Callbacks to APP */
typedef MMI_BOOL (*wgui_mv_get_filename_by_id)(U32 id, PU16 vf, PU16* file_path, PS32 vf_parent_file_handle);
typedef MMI_BOOL (*wgui_mv_load_ucs2_txt_to_buffer)(PU8 dest_buffer, U32 dest_buffer_size, U32 object_id);
typedef MMI_BOOL (*wgui_mv_check_rights_by_id)(U32 object_id);
typedef MMI_BOOL (*wgui_mv_start_consume_rights)(U32 object_id, PU16 file_path);
typedef MMI_BOOL (*wgui_mv_allow_audio) (void);
typedef void (*wgui_mv_stop_consume_rights)(U32 object_id);
typedef void (*wgui_mv_update_rights_by_id)(U32 object_id, MMI_BOOL rights_expired);
typedef void (*wgui_mv_stop_application) (void);


/* Structures */
typedef struct
{
    dm_coordinates infobar;
    dm_coordinates viewarea;
    dm_coordinates pbar_area;
    dm_coordinates larrow;
    dm_coordinates rarrow;
    PU8 pbar_img;
    S32 pbar_img_width;
    S32 pbar_img_height;
#ifdef __MMI_VIDEO_PLAYER__
    gdi_handle baselayer;
    gdi_handle vlayer;
    gdi_handle tlayer;
    gdi_handle blayer;
#endif /* __MMI_VIDEO_PLAYER__ */ 

    S32 resized_xoffset;
    S32 resized_yoffset;
    S32 resized_width;
    S32 resized_height;
    
    wgui_mv_cat_pen_event_enum cat_pen_event;
    wgui_mv_layout_type_enum type;
} wgui_mv_layout_struct;

typedef struct
{
    U32 page_id;
    S32 text_offset;
    S32 last_text_offset_y;
} wgui_mv_paging_context;

typedef struct
{
    UI_filled_area bgfiller;
    wgui_mv_stop_application stop_app_cb;
    wgui_mv_get_filename_by_id get_filename_by_id;
    wgui_mv_load_ucs2_txt_to_buffer load_paging_txt;
    wgui_mv_check_rights_by_id is_drm_locked;
    wgui_mv_update_rights_by_id update_rights;
    wgui_mv_start_consume_rights start_consume_rights;
    wgui_mv_stop_consume_rights stop_consume_rights;
    wgui_mv_allow_audio allow_audio_play;

    softkey_fn lsk_fn;  /* Store APP supplied lsk fn */
    softkey_fn rsk_fn;  /* Store APP supplied rsk fn */
    /* whole slide txt in UCS2 stored in this buffer */
    PU8 ptxtbuffer; 
    /* txt buffer size */
    U32 ptxtbuffersize; 
    /* Buffer supplied to multiline inputbox, always CAT630_MAIN_TXT_BUFFER_SIZE */
    PU8 pinputboxbuffer; 
    
    PU16 drawable_media_file_path;
    PU16 audio_file_path;
    wgui_mv_xml_msg_struct *current_msg;

    U32 ucs2_txt_len;
    GDI_HANDLE image_handle;

    U16 lsk_str_id;

    wgui_mv_drawable_media_event_enum drawable_media_event;
    wgui_mv_drawable_media_state_enum drawable_media_state;
    wgui_mv_state_enum current_state;
    U16 slide_time;

    MMI_BOOL is_media_valid;
    MMI_BOOL is_audio_start_play;
#ifdef __MMI_VIDEO_PLAYER__
    MMI_BOOL is_video_open;
    MMI_BOOL is_video_play;
#ifdef __DRM_SUPPORT__
    MMI_BOOL is_video_playing;      /* for DRM to cosume right, this flag will set true after start playing for each slide */
#endif /* __DRM_SUPPORT__ */
    MMI_BOOL is_video_start_play;
#endif /* __MMI_VIDEO_PLAYER__ */
    MMI_BOOL is_audio_play;
} wgui_mv_context_struct;

typedef struct
{
    /* Callbacks to APP */
    wgui_mv_get_filename_by_id get_filename_by_id_cb;
    wgui_mv_load_ucs2_txt_to_buffer load_slide_txt_cb;
    wgui_mv_check_rights_by_id check_rights_cb;
    wgui_mv_start_consume_rights consume_rights_cb;
    wgui_mv_stop_consume_rights stop_consume_rights_cb;
    wgui_mv_update_rights_by_id update_rights_cb;
    wgui_mv_stop_application stop_app_cb;
    wgui_mv_allow_audio allow_audio_cb;
 
    /* Data Members */
    wgui_mv_xml_msg_struct *current_msg;
    PU8 ptxtbuffer;
    U32 ptxtbuffersize;
    PU8 pinputboxbuffer;
}wgui_mv_initialize_struct;

/* Should Initialize to Dummy CBs Incase of NULL */
void Category630Initialize (wgui_mv_initialize_struct *init);
void Category630ImageRightExpiredNotify (void);
void ShowCategory630Screen (BOOL startshowing, softkey_fn lsk_function, U16 lsk_str_id, softkey_fn rsk_function, PU8 guibuffer);

#endif /* __UI_MMS_VIEWER_CATEGORY__ */

#endif /* __WGUI_CATEGORIES_MMS_VIEWER_H__ */