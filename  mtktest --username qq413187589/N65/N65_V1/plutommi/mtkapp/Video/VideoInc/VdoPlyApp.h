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
 *   VdoPlyApp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Expose function and variable.
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
#ifndef _VDOPLYAPP_H
#define _VDOPLYAPP_H

#include "MMI_features.h"
#ifdef __MMI_VIDEO_PLAYER__

/***************************************************************************** 
* Define
*****************************************************************************/
#define VDOPLY_STORAGE_FILEPATH_PHONE              FMGR_DEFAULT_FOLDER_VIDEO
#define VDOPLY_STORAGE_FILEPATH_MEMORY_CARD        FMGR_DEFAULT_FOLDER_VIDEO

#define VDOPLY_PLAYBACK_ROTATE_0             MDI_VIDEO_LCD_ROTATE_0
#define VDOPLY_PLAYBACK_ROTATE_90            MDI_VIDEO_LCD_ROTATE_90
#define VDOPLY_PLAYBACK_ROTATE_180           MDI_VIDEO_LCD_ROTATE_180
#define VDOPLY_PLAYBACK_ROTATE_270           MDI_VIDEO_LCD_ROTATE_270
#define VDOPLY_PLAYBACK_ROTATE_0_MIRROR      MDI_VIDEO_LCD_ROTATE_0_MIRROR
#define VDOPLY_PLAYBACK_ROTATE_90_MIRROR     MDI_VIDEO_LCD_ROTATE_90_MIRROR
#define VDOPLY_PLAYBACK_ROTATE_180_MIRROR    MDI_VIDEO_LCD_ROTATE_180_MIRROR
#define VDOPLY_PLAYBACK_ROTATE_270_MIRROR    MDI_VIDEO_LCD_ROTATE_270_MIRROR

#define VDOPLY_BRIGHTNESS_ADJ_LEVEL_COUNT    (11)       /* -5, -4, ...0 , +4, +5 */
#define VDOPLY_CONTRAST_ADJ_LEVEL_COUNT      (11)       /* -5, -4, ...0 , +4, +5 */
#define VDOPLY_REPEAT_ADJ_COUNT              (2)        /* on/off */
#define VDOPLY_MAX_PORT_LEN                  (6)        /* 0 - 65535 */
#define VDOPLY_MAX_IP_LEN                    (3)        /* xxx */
#define VDOPLY_MAX_IP_COUNT                  (4)
#define VDOPLY_MAX_URL_CHAR_COUNT            (FMGR_PATH_CHAR_COUNT)
#define VDOPLY_MAX_STREAM_LINK_CHAR_COUNT    (36)       /* stream ram filename can be 35 char */
/* hongzhe.liu add start */
#define MAX_DATA_ACCOUNT_NAME_LEN   31
/* hongzhe.liu add end */
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    VDOPLY_STATE_EXIT,
    VDOPLY_STATE_OPENING,
    VDOPLY_STATE_IDLE,
    VDOPLY_STATE_PAUSE,
    VDOPLY_STATE_PLAY,
    VDOPLY_STATE_BT_CONNECTING,    
    VDOPLY_STATE_SEEKING,
    VDOPLY_STATE_PLAY_SEEKING,
    VDOPLY_STATE_INTERRUPTED_OPENING,
    VDOPLY_STATE_INTERRUPTED_PAUSE,
    VDOPLY_STATE_INTERRUPTED_SEEKING, /* 10 */
    
    VDOPLY_STATE_FULLSCR_IDLE,  
    VDOPLY_STATE_FULLSCR_PAUSE,
    VDOPLY_STATE_FULLSCR_PLAY,
    VDOPLY_STATE_FULLSCR_BT_CONNECTING,        
    VDOPLY_STATE_FULLSCR_SEEKING,
    VDOPLY_STATE_FULLSCR_PLAY_SEEKING,
        
    VDOPLY_STATE_STREAM_DISCONNECT, /* 17 */
    VDOPLY_STATE_STREAM_CONNECTING,
    VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING,
    VDOPLY_STATE_STREAM_CONNECTED,  
    VDOPLY_STATE_STREAM_BUFFERING,    
    VDOPLY_STATE_STREAM_PLAY,    
    VDOPLY_STATE_STREAM_BT_CONNECTING,

    VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT,  /* 24 */
    VDOPLY_STATE_STREAM_FULLSCR_CONNECTING,  
    VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING,      
    VDOPLY_STATE_STREAM_FULLSCR_CONNECTED,    
    VDOPLY_STATE_STREAM_FULLSCR_BUFFERING,    
    VDOPLY_STATE_STREAM_FULLSCR_PLAY,   
    VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING,

    VDOPLY_STATE_PROGRESSIVE_OPENING,   /* 31 */
    VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING, 
    VDOPLY_STATE_PROGRESSIVE_BUFFERING,    
    VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING,
    VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING,        
    VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING,

    /* state only for drawing */
    VDOPLY_STATE_SNAPSHOT
    
} vdoply_state_neum;

typedef enum
{
    VDOPLY_PDL_DL_STATE_EXIT,
    VDOPLY_PDL_DL_STATE_DOWNLOADING,
    VDOPLY_PDL_DL_STATE_FINISHED
} vdoply_pdl_dl_state_neum;

typedef enum
{
    VDOPLY_UI_TYPE_NORMAL,
    VDOPLY_UI_TYPE_FULLSCR    
} vdoply_ui_type_neum;



typedef struct
{
    LOCAL_PARA_HDR 
    S8 rtsp_url[FMGR_PATH_BUFFER_SIZE];
} mmi_vdoply_rtsp_url_data_struct;

typedef struct
{
    S32 offset_y;
    S32 hr_0_offset_x;
    S32 hr_1_offset_x;
    S32 col_0_offset_x;
    S32 min_0_offset_x;
    S32 min_1_offset_x;
    S32 col_1_offset_x;
    S32 sec_0_offset_x;
    S32 sec_1_offset_x;
    U16 prev_hr;
    U16 prev_min;
    U16 prev_sec;
} vdoply_timer_struct;

typedef struct
{
    S32 fill_width;
    S32 fill_height;
} vdoply_progress_struct;

typedef struct
{
    U16 width;
    U16 height;
    U64 total_time_duration;
    U8 aud_channel_no;
    U16 aud_sample_rate;

    /* for streaming */
    MMI_BOOL is_pausable;    
    MMI_BOOL is_seekable;
    mdi_video_track_enum track;       
    S8 title_name[(MDI_VIDEO_INFO_TITLE_CHAR_COUNT+1)*ENCODING_LENGTH]; /* unicode */          /* STREAM_MAX_TITLE_LEN */    
} vdoply_video_info_struct;

typedef struct
{
    U64 play_time;
    U64 start_play_time;    /* start play time - this is used to fix driver seek not accurate problem */
    U64 max_play_time;    
    U32 play_ratio;
    U32 buff_ratio;
    U8 speed;
    U8 volume;
} vdoply_status_struct;

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    BOOL is_press;
    BOOL is_usable;
} vdoply_ui_touch_struct;

typedef enum
{
    VDOPLY_TOUCH_SPEED_INC,
    VDOPLY_TOUCH_SPEED_DEC,
    VDOPLY_TOUCH_VOLUME_INC,
    VDOPLY_TOUCH_VOLUME_DEC,
    VDOPLY_TOUCH_PROGRESS_INC,
    VDOPLY_TOUCH_PROGRESS_DEC,
    VDOPLY_TOUCH_PROGRESS_BAR,
    VDOPLY_TOUCH_SNAPSHOT,
    VDOPLY_TOUCH_FULLSCREEN,
    VDOPLY_TOUCH_RSK,
    VDOPLY_TOUCH_LSK,
    VDOPLY_TOUCH_CK,
    VDOPLY_TOUCH_NONE
} vdoply_touch_object_enum;

/* inline data */
typedef struct
{

    /* strings for inline selection display */
    UI_string_type brightness_str[VDOPLY_BRIGHTNESS_ADJ_LEVEL_COUNT];
    UI_string_type contrast_str[VDOPLY_BRIGHTNESS_ADJ_LEVEL_COUNT];
    UI_string_type repeat_str[VDOPLY_REPEAT_ADJ_COUNT];

    /* selected item */
    S32 brightness;
    S32 contrast;
    S32 repeat;
} vdoplay_adjust_data_struct;

/* context */
typedef struct
{
    gdi_handle bg_layer_handle;
    gdi_handle bg_region_0_layer_handle;
    gdi_handle bg_region_1_layer_handle;
    gdi_handle process_layer_handle;
    gdi_handle play_wnd_layer_handle;
    gdi_handle osd_layer_handle;
    gdi_handle fullscr_play_layer_handle;

    gdi_handle speed_draw_layer;
    gdi_handle volume_draw_layer;    
    gdi_handle progress_draw_layer;    
    gdi_handle snapshot_draw_layer; 
    gdi_handle fullscreen_draw_layer;
    gdi_handle rsk_draw_layer;
    gdi_handle lsk_draw_layer;
    gdi_handle ck_draw_layer;
    gdi_handle title_draw_layer;   
    gdi_handle timer_draw_layer;    

    gdi_handle bt_connecting_anim;
    gdi_handle connecting_anim;
    gdi_handle opening_anim;
    gdi_handle aud_only_anim;

    PU8 osd_layer_buf_ptr;
    PU8 bg_region_0_buf_ptr;
    PU8 bg_region_1_buf_ptr;    

    /* setting */
    U16 storage;
    U16 brightness;
    U16 contrast;
    U16 repeat;

    /* misc */
    U16 state;
    U16 play_source;
    U16 video_id;
    U16 video_name_id;
    PS8 lsk_str_ptr;
    PS8 rsk_str_ptr;
    U16 lsk_img_id;
    U16 rsk_img_id;
    U16 ck_img_id;
    S8  source_path[FMGR_PATH_BUFFER_SIZE];

    S32 highlight_idx;

    BOOL is_seeking;
    BOOL is_sub_display;
    BOOL is_short_filename;
    BOOL is_tvout_fullscreen;
    BOOL is_mute;
    BOOL is_load_setting;
    BOOL is_source_opened;
    BOOL is_stream_seekable;
    BOOL is_progress_seekable;
    BOOL prev_rotate_by_layer;
    BOOL is_toggle_fullscr_osd;
    BOOL is_stream_init;
    BOOL is_pdl_debug;
    BOOL is_stream_opened;
    BOOL is_bt_opened;
    BOOL is_playing; 
    BOOL is_stream_buffering;
    BOOL is_da_spd_file;
    BOOL is_change_storage;
    BOOL is_option_storage;
    BOOL is_from_history;
    BOOL is_use_upd_port;
    BOOL is_consume_drm_count;
    
    vdoply_ui_type_neum ui_type;

    U16 fullscr_osd_opacity;
    U8 normal_style_rotate;
    S32 normal_style_lcd_width;
    S32 normal_style_lcd_height;

    /* streaming */
    UI_string_type proxy_on_off_str[2];
    S32 inline_proxy_on_off;
    U8 proxy_on_off;
    
    U8 proxy_addr[VDOPLY_MAX_IP_COUNT];
    U8 inline_proxy_addr[VDOPLY_MAX_IP_COUNT][(VDOPLY_MAX_IP_LEN+1)*ENCODING_LENGTH];
    
    S32 proxy_port;
    U8 inline_proxy_port[(VDOPLY_MAX_PORT_LEN)*ENCODING_LENGTH];

    S32 highest_udp_port;
    U8 inline_highest_udp_port[(VDOPLY_MAX_PORT_LEN)*ENCODING_LENGTH]; 

    S32 lowest_udp_port;
    U8 inline_lowest_udp_port[(VDOPLY_MAX_PORT_LEN)*ENCODING_LENGTH]; 
    
    U8 data_account_id;
    S8 data_account_name[(MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH];   
    S8 edit_buf[(VDOPLY_MAX_URL_CHAR_COUNT+1)*ENCODING_LENGTH];

    S8 history_title_name[(MDI_VIDEO_INFO_TITLE_CHAR_COUNT+1)*ENCODING_LENGTH]; /* unicode */ 

    /* pdl */
    S32 pdl_dl_session_id;
    vdoply_pdl_dl_state_neum pdl_dl_state;
    S32 pdl_buf_percent;

    /* display */
    vdoply_timer_struct timer;
    vdoply_progress_struct progress;

    vdoply_timer_struct fullscr_timer;
    vdoply_progress_struct fullscr_progress;

    /* video clip */
    vdoply_video_info_struct video_info;
    vdoply_status_struct cur_status;

    U16 touch_object;
    U8  *vdo_frame_buf_ptr;

    vdoply_ui_touch_struct touch_speed_inc;
    vdoply_ui_touch_struct touch_speed_dec;
    vdoply_ui_touch_struct touch_volume_inc;
    vdoply_ui_touch_struct touch_volume_dec;
    vdoply_ui_touch_struct touch_progress_inc;
    vdoply_ui_touch_struct touch_progress_dec;
    vdoply_ui_touch_struct touch_progress_bar;
    vdoply_ui_touch_struct touch_snapshot;
    vdoply_ui_touch_struct touch_fullscreen;
    vdoply_ui_touch_struct touch_rsk;
    vdoply_ui_touch_struct touch_lsk;
    vdoply_ui_touch_struct touch_ck;

    vdoply_ui_touch_struct full_touch_speed_inc;
    vdoply_ui_touch_struct full_touch_speed_dec;
    vdoply_ui_touch_struct full_touch_volume_inc;
    vdoply_ui_touch_struct full_touch_volume_dec;
    vdoply_ui_touch_struct full_touch_progress_inc;
    vdoply_ui_touch_struct full_touch_progress_dec;
    vdoply_ui_touch_struct full_touch_progress_bar;
    vdoply_ui_touch_struct full_touch_rsk;
    vdoply_ui_touch_struct full_touch_lsk;
    vdoply_ui_touch_struct full_touch_ck;

#ifdef __VDOPLY_FEATURE_LSK_OPTION__
    vdoplay_adjust_data_struct adjust_data;
#endif 

} vdoply_context_struct;

/****************************************************************************
* Skin                                                            
*****************************************************************************/
typedef struct
{
    /* image size */
    U8 digit_image_width;
    U8 digit_image_height;
    U8 colon_image_width;
    U8 colon_image_height;
    U8 spacing;

    /* offset */
    S16 digit_start_offset_x;
    S16 digit_start_offset_y;

    /* back ground */
    U8 bg_r;
    U8 bg_g;
    U8 bg_b;

    /* timer */
    S16 offset_x;
    S16 offset_y;
    U16 width;
    U16 height;

    /* flag */
    BOOL draw_bg_image;
    BOOL draw_bg_color;
    BOOL draw_hour;
    BOOL draw_min;
} multimedia_timer_struct;

typedef struct
{
    S16 offset_x;
    S16 offset_y;
    U16 width;
    U16 height;
} multimedia_display_wnd_struct;

typedef struct
{
    S16 offset_x;
    S16 offset_y;
    U16 width;
    U16 height;
} multimedia_slidebar_struct;

#endif /* __MMI_VIDEO_PLAYER__ */ 
#endif /* _VDOPLYAPP_H */ 

