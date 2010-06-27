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
 *  mdi_video.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video related functions.
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
#ifndef _MDI_VIDEO_H
#define _MDI_VIDEO_H

#ifndef _MDI_DATATYPE_H_
#error "Please include mdi_datatype.h before mdi_video.h"
#endif 

#include "med_api.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* Parameters settings */
#define MDI_VIDEO_EV_P4                      CAM_EV_POS_4_3
#define MDI_VIDEO_EV_P3                      CAM_EV_POS_3_3
#define MDI_VIDEO_EV_P2                      CAM_EV_POS_2_3
#define MDI_VIDEO_EV_P1                      CAM_EV_POS_1_3
#define MDI_VIDEO_EV_0                       CAM_EV_ZERO
#define MDI_VIDEO_EV_N1                      CAM_EV_NEG_1_3
#define MDI_VIDEO_EV_N2                      CAM_EV_NEG_2_3
#define MDI_VIDEO_EV_N3                      CAM_EV_NEG_3_3
#define MDI_VIDEO_EV_N4                      CAM_EV_NEG_4_3
#define MDI_VIDEO_EV_NIGHT                   CAM_EV_NIGHT_SHOT
#define MDI_VIDEO_EV_COUNT                   CAM_NO_OF_EV

#define MDI_VIDEO_EFFECT_NOMRAL              CAM_EFFECT_ENC_NORMAL
#define MDI_VIDEO_EFFECT_GRAYSCALE           CAM_EFFECT_ENC_GRAYSCALE
#define MDI_VIDEO_EFFECT_SEPIA               CAM_EFFECT_ENC_SEPIA
#define MDI_VIDEO_EFFECT_SEPIA_GREEN         CAM_EFFECT_ENC_SEPIAGREEN
#define MDI_VIDEO_EFFECT_SEPIA_BLUE          CAM_EFFECT_ENC_SEPIABLUE
#define MDI_VIDEO_EFFECT_COLOR_INVERT        CAM_EFFECT_ENC_COLORINV
#define MDI_VIDEO_EFFECT_GRAY_INVERT         CAM_EFFECT_ENC_GRAYINV
#define MDI_VIDEO_EFFECT_BLACKBOARD          CAM_EFFECT_ENC_BLACKBOARD
#define MDI_VIDEO_EFFECT_WHITEBOARD          CAM_EFFECT_ENC_WHITEBOARD
#define MDI_VIDEO_EFFECT_COPPER_CARVING      CAM_EFFECT_ENC_COPPERCARVING
#define MDI_VIDEO_EFFECT_BLUE_CARVING        CAM_EFFECT_ENC_BLUECARVING
#define MDI_VIDEO_EFFECT_EMBOSSMENT          CAM_EFFECT_ENC_EMBOSSMENT
#define MDI_VIDEO_EFFECT_CONTRAST            CAM_EFFECT_ENC_CONTRAST
#define MDI_VIDEO_EFFECT_JEAN                CAM_EFFECT_ENC_JEAN
#define MDI_VIDEO_EFFECT_SKETCH              CAM_EFFECT_ENC_SKETCH
#define MDI_VIDEO_EFFECT_OIL                 CAM_EFFECT_ENC_OIL
#define MDI_VIDEO_EFFECT_COUNT               CAM_NO_OF_EFFECT_ENC

#define MDI_VIDEO_WB_AUTO                    CAM_WB_AUTO
#define MDI_VIDEO_WB_DAYLIGHT                CAM_WB_DAYLIGHT
#define MDI_VIDEO_WB_TUNGSTEN                CAM_WB_TUNGSTEN
#define MDI_VIDEO_WB_FLUORESCENT             CAM_WB_FLUORESCENT
#define MDI_VIDEO_WB_CLOUD                   CAM_WB_CLOUD
#define MDI_VIDEO_WB_INCANDESCENCE           CAM_WB_INCANDESCENCE
#define MDI_VIDEO_WB_COUNT                   CAM_NO_OF_WB

#define MDI_VIDEO_BANDING_50HZ               CAM_BANDING_50HZ
#define MDI_VIDEO_BANDING_60HZ               CAM_BANDING_60HZ
#define MDI_VIDEO_BANDING_COUNT              CAM_NO_OF_BANDING

#define MDI_VIDEO_VIDEO_SIZE_SQCIF           0
#define MDI_VIDEO_VIDEO_SIZE_QQVGA           1
#define MDI_VIDEO_VIDEO_SIZE_QCIF            2
#define MDI_VIDEO_VIDEO_SIZE_CIF             3
#define MDI_VIDEO_VIDEO_SIZE_USER_DEFINE     4

#define MDI_VIDEO_REC_QTY_FINE               VID_REC_QTY_FINE
#define MDI_VIDEO_REC_QTY_HIGH               VID_REC_QTY_HIGH
#define MDI_VIDEO_REC_QTY_NORMAL             VID_REC_QTY_NORMAL
#define MDI_VIDEO_REC_QTY_LOW                VID_REC_QTY_LOW
#define MDI_VIDEO_REC_QTY_COUNT              VID_NO_OF_REC_QTY

#define MDI_VIDEO_TEL_ENC_QTY_FINE           VCALL_ENC_QTY_FINE
#define MDI_VIDEO_TEL_ENC_QTY_NORMAL         VCALL_ENC_QTY_NORMAL
#define MDI_VIDEO_TEL_ENC_QTY_LOW            VCALL_ENC_QTY_LOW
#define MDI_VIDEO_TEL_ENC_QTY_COUNT          VCALL_ENC_QTY_TOTAL

#define MDI_VIDEO_VIDEO_FORMAT_3GP           VID_3GP_BIT_STREAM
#define MDI_VIDEO_VIDEO_FORMAT_MP4           VID_MP4_BIT_STREAM
#define MDI_VIDEO_VIDEO_FORMAT_COUNT         VID_NO_OF_BIT_STREAM

#define MDI_VIDEO_PREVIEW_ROTATE_0           CAM_IMAGE_NORMAL
#define MDI_VIDEO_PREVIEW_ROTATE_90          CAM_IMAGE_ROTATE_90
#define MDI_VIDEO_PREVIEW_ROTATE_180         CAM_IMAGE_ROTATE_180
#define MDI_VIDEO_PREVIEW_ROTATE_270         CAM_IMAGE_ROTATE_270
#define MDI_VIDEO_PREVIEW_ROTATE_0_MIRROR    CAM_IMAGE_MIRROR
#define MDI_VIDEO_PREVIEW_ROTATE_90_MIRROR   CAM_IMAGE_MIRROR_ROTATE_90
#define MDI_VIDEO_PREVIEW_ROTATE_180_MIRROR  CAM_IMAGE_MIRROR_ROTATE_180
#define MDI_VIDEO_PREVIEW_ROTATE_270_MIRROR  CAM_IMAGE_MIRROR_ROTATE_270

#if defined(ISP_SUPPORT)
#define MDI_VIDEO_LCD_ROTATE_0            LCD_LAYER_ROTATE_NORMAL
#define MDI_VIDEO_LCD_ROTATE_90           LCD_LAYER_ROTATE_90
#define MDI_VIDEO_LCD_ROTATE_180          LCD_LAYER_ROTATE_180
#define MDI_VIDEO_LCD_ROTATE_270          LCD_LAYER_ROTATE_270
#define MDI_VIDEO_LCD_ROTATE_0_MIRROR     LCD_LAYER_MIRROR
#define MDI_VIDEO_LCD_ROTATE_90_MIRROR    LCD_LAYER_MIRROR_ROTATE_90
#define MDI_VIDEO_LCD_ROTATE_180_MIRROR   LCD_LAYER_MIRROR_ROTATE_180
#define MDI_VIDEO_LCD_ROTATE_270_MIRROR   LCD_LAYER_MIRROR_ROTATE_270
#else /* defined(ISP_SUPPORT) */ 
#define MDI_VIDEO_LCD_ROTATE_0            0
#define MDI_VIDEO_LCD_ROTATE_90           1
#define MDI_VIDEO_LCD_ROTATE_180          2
#define MDI_VIDEO_LCD_ROTATE_270          3
#define MDI_VIDEO_LCD_ROTATE_0_MIRROR     4
#define MDI_VIDEO_LCD_ROTATE_90_MIRROR    5
#define MDI_VIDEO_LCD_ROTATE_180_MIRROR   6
#define MDI_VIDEO_LCD_ROTATE_270_MIRROR   7
#endif /* defined(ISP_SUPPORT) */ 

#define MDI_VIDEO_BRIGHTNESS_N5              0
#define MDI_VIDEO_BRIGHTNESS_N4              1
#define MDI_VIDEO_BRIGHTNESS_N3              2
#define MDI_VIDEO_BRIGHTNESS_N2              3
#define MDI_VIDEO_BRIGHTNESS_N1              4
#define MDI_VIDEO_BRIGHTNESS_0               5
#define MDI_VIDEO_BRIGHTNESS_P1              6
#define MDI_VIDEO_BRIGHTNESS_P2              7
#define MDI_VIDEO_BRIGHTNESS_P3              8
#define MDI_VIDEO_BRIGHTNESS_P4              9
#define MDI_VIDEO_BRIGHTNESS_P5              10

#define MDI_VIDEO_CONTRAST_N5                0
#define MDI_VIDEO_CONTRAST_N4                1
#define MDI_VIDEO_CONTRAST_N3                2
#define MDI_VIDEO_CONTRAST_N2                3
#define MDI_VIDEO_CONTRAST_N1                4
#define MDI_VIDEO_CONTRAST_0                 5
#define MDI_VIDEO_CONTRAST_P1                6
#define MDI_VIDEO_CONTRAST_P2                7
#define MDI_VIDEO_CONTRAST_P3                8
#define MDI_VIDEO_CONTRAST_P4                9
#define MDI_VIDEO_CONTRAST_P5                10

#define MDI_VIDEO_INFO_TITLE_CHAR_COUNT      32

#if (defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))
    #define MDI_VIDEO_MT6228_SERIES
#endif 

/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef enum
{
    MDI_VIDEO_STREAM_RTSP_URL,
    MDI_VIDEO_STREAM_SDP_FILE
} mdi_video_stream_type_enum;

typedef enum
{
    MDI_VIDEO_TRACK_NONE,
    MDI_VIDEO_TRACK_AV,
    MDI_VIDEO_TRACK_A_ONLY,
    MDI_VIDEO_TRACK_V_ONLY,     
    MDI_VIDEO_TRACK_COUNT
} mdi_video_track_enum;

typedef enum
{
    MDI_VIDEO_DRM_EXIT,
    MDI_VIDEO_DRM_PERMITTED,
    MDI_VIDEO_DRM_CONSUMING,
    MDI_VIDEO_DRM_PLAY_FINISHED,     
    MDI_VIDEO_DRM_PAUSED,

    MDI_VIDEO_DRM_END
} mdi_video_drm_state_enum;
 

typedef struct
{
    U16 width;
    U16 height;
    U32 total_frame_count;
    U64 total_time_duration;
    mdi_video_track_enum track;   
    mdi_handle handle;
    MMI_BOOL is_seekable;
    U8 aud_channel_no;
    U16 aud_sample_rate;
    S8 title_name[MDI_VIDEO_INFO_TITLE_CHAR_COUNT];          /* STREAM_MAX_TITLE_LEN */
} mdi_video_info_struct;


typedef struct
{
    /* preview */
    U16 wb;
    U16 ev;
    U16 banding;
    U16 effect;
    U16 zoom;
    U16 brightness;
    U16 contrast;
    U16 saturation;
    U16 hue;
    U16 preview_rotate;
    U16 lcm_rotate; 
    U16 night;

    /* record */
    U16 video_size;
    U16 video_qty;
    U16 size_limit;
    U16 time_limit;
    U16 record_aud;
    U16 video_format;
    U16 user_def_width;
    U16 user_def_height;

    /* preview & record */
    BOOL overlay_frame_mode;
    U8 overlay_frame_depth;
    U8 overlay_frame_source_key;
    U16 overlay_frame_width;
    U16 overlay_frame_height;
    U32 overlay_frame_buffer_address;

} mdi_video_setting_struct;


typedef struct
{
    mdi_video_setting_struct setting;
    U64 record_time;
    U16 rec_state;
    U16 open_seq_num;
    U16 play_seq_num;
    U16 record_seq_num;
    U16 seek_seq_num;
    U16 connect_seq_num;
    U16 buffering_seq_num;    
    U16 merge_seq_num;
    U16 vt_seq_num;    
    BOOL is_play_audio;
    BOOL is_seeking;
    BOOL is_seek_after_open;
    BOOL is_enable_partial_display;
    BOOL is_consume_drm_count;    
    BOOL is_stream_connected;
    BOOL is_stream_init;
    BOOL is_playing;
    BOOL is_recording;    
    BOOL is_enable_aud_only;
    BOOL is_drm_file;
    U16 tvout_prev_owner;
    mdi_video_info_struct video_info;
    gdi_handle lcd_handle;
    module_type mimic_module_id;

    /* drm */
    mdi_video_drm_state_enum drm_state;
    U32 drm_id;
    FS_HANDLE drm_file_h;
    
    /* stream */
    U8 stream_session_id;

    /* dummy variable for MoDIS */
    U64 dummy_cur_time;
    U64 dummy_max_play_time;        
    S32 dummy_loading_percentage;
    S32 dummy_counter;
} mdi_video_context_struct;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/**** MDI_VIDEO ****/
extern MMI_BOOL mdi_video_message_dispatcher(void *ilm_ptr);           /* used by mdi_common.c only */
extern void     mdi_video_enable_mimic_task(module_type module_id);    /* used by Java only */
extern void     mdi_video_disable_mimic_task(void);                    /* used by Java only */

/**** RECORDER ****/
extern MDI_RESULT mdi_video_rec_init(void);
extern MDI_RESULT mdi_video_rec_power_on(void);
extern MDI_RESULT mdi_video_rec_power_off(void);
extern MDI_RESULT mdi_video_rec_record_start(S8 *filename, void (*record_result_callback) (MDI_RESULT));
extern MDI_RESULT mdi_video_rec_record_stop(void);
extern MDI_RESULT mdi_video_rec_record_pause(MMI_BOOL stop_preview);
extern MDI_RESULT mdi_video_rec_record_resume(void);
extern MDI_RESULT mdi_video_rec_preview_start(
                    gdi_handle preview_layer_handle,
                    U32 blt_layer_flag,                     /* which layer shall be blt by driver */
                    U32 preview_layer_flag,                 /* preview on which layer */
                    MMI_BOOL is_lcd_update,
                    mdi_video_setting_struct *setting_p);   /* video setting */
extern MDI_RESULT mdi_video_rec_preview_stop(void);
extern MDI_RESULT mdi_video_rec_save_file(S8 *filepath, void (*save_result_callback) (MDI_RESULT));
extern MDI_RESULT mdi_video_rec_stop_save(void);
extern BOOL       mdi_video_rec_has_unsaved_file(S8 *filepath);
extern void       mdi_video_rec_delete_unsaved_file(S8 *filepath);
extern void       mdi_video_rec_get_cur_record_time(U64 *cur_record_time);
extern void       mdi_video_rec_update_para_ev(U16 para);
extern void       mdi_video_rec_update_para_zoom(U16 para);
extern void       mdi_video_rec_update_para_effect(U16 para);
extern void       mdi_video_rec_update_para_wb(U16 para);
extern void       mdi_video_rec_update_para_night(U16 para);
extern U16        mdi_video_rec_get_max_zoom_factor(S32 record_width, S32 record_height);
extern U64        mdi_video_rec_get_record_file_size(void);

/* special function for Java, to update blt region while preview / record / record paused */
extern MDI_RESULT mdi_video_rec_update_blt_pause(void);
extern MDI_RESULT mdi_video_rec_update_blt_resume(
                    gdi_handle preview_layer_handle,
                    U32 blt_layer_flag,     
                    U32 preview_layer_flag, 
                    MMI_BOOL is_lcd_update);

/**** PLAYER ****/
extern MDI_RESULT mdi_video_ply_init(void);

/* non blocking open */
extern MDI_RESULT mdi_video_ply_open_file(
                    const S8 *filename,
                    void (*open_result_callback)(MDI_RESULT, mdi_video_info_struct *));
extern MDI_RESULT mdi_video_ply_close_file(void);

extern MDI_RESULT mdi_video_ply_play(
                    gdi_handle player_layer_handle, 
                    U32 blt_layer_flag,                         /* which layer shall be blt by driver */
                    U32 play_layer_flag, 
                    U16 repeat_count, 
                    BOOL is_visual_update, 
                    BOOL is_play_audio,
                    U8 audio_path, 
                    U16 roate, 
                    S16 play_speed, 
                    void (*play_finish_callback) (MDI_RESULT)); /* call back when play finied */

extern MDI_RESULT mdi_video_ply_stop(void);
extern MDI_RESULT mdi_video_ply_seek(U64 time);
extern MDI_RESULT mdi_video_ply_seek_and_get_frame(U64 time, gdi_handle player_layer_handle);
extern MDI_RESULT mdi_video_ply_snapshot(gdi_handle layer_handle, PS8 file_name);
extern void       mdi_video_ply_get_cur_play_time(U64 *cur_play_time);
extern MDI_RESULT mdi_video_ply_set_lcm_update(BOOL is_update);

extern MDI_RESULT mdi_video_ply_non_block_seek(U64 time, void (*seek_result_callback) (MDI_RESULT));
extern MDI_RESULT mdi_video_ply_non_block_seek_and_get_frame(
                    U64 time,
                    gdi_handle player_layer_handle,
                    void (*seek_result_callback) (MDI_RESULT));

extern MDI_RESULT mdi_video_ply_stop_non_block_seek(void);
extern MDI_RESULT mdi_video_ply_set_brightness(U16 brightness);
extern MDI_RESULT mdi_video_ply_set_contrast(U16 contrast);
extern MDI_RESULT mdi_video_ply_enable_partial_display(void);       /* allows to draw partial video out of lcd region */

extern MDI_RESULT mdi_video_ply_set_stop_time(U64 stop_time);       /* used by Java only */
extern MDI_RESULT mdi_video_ply_set_audio_level(U16 aud_level);     /* used by Java only */ 
extern MDI_RESULT mdi_video_ply_drm_disable_consume_count(void);    /* call this before play, will not consume count this time */
extern MMI_BOOL   mdi_video_ply_is_drm_file(void);


/**** Video Clip ****/
/* these interfaces will not opened aud only video */
extern MDI_RESULT mdi_video_ply_open_clip_file(
                    const S8 *filename, 
                    mdi_video_info_struct *info);
extern MDI_RESULT mdi_video_ply_close_clip_file(void);

extern MDI_RESULT mdi_video_ply_open_clip_id(
                    U16 video_id, 
                    mdi_video_info_struct *info);
extern MDI_RESULT mdi_video_ply_close_clip_id(void);

extern MDI_RESULT mdi_video_ply_open_clip_buffer(
                    const U8 *file_buffer,
                    const U32 buffer_len,
                    mdi_video_info_struct *info);
extern MDI_RESULT mdi_video_ply_close_clip_buffer(void);                

extern MDI_RESULT mdi_video_ply_enable_aud_only_video_clip(void);

/* misc */
extern void mdi_video_set_overlay_palette(U8 palette_size, U32 *palette_addr_ptr);
extern void mdi_video_blocked_recovery(void);
extern BOOL mdi_video_is_playing(void);
extern BOOL mdi_video_is_recording(void);


/**** Streaming ****/
#ifdef __MMI_VIDEO_STREAM__
extern MDI_RESULT mdi_video_stream_init(void);
extern MDI_RESULT mdi_video_stream_deinit(void);

extern MDI_RESULT mdi_video_stream_connect(
                    U8 data_account, 
                    mdi_video_stream_type_enum stream_type, 
                    S8 *data_path,
                    MMI_BOOL use_proxy,
                    U8 *proxy,
                    U16 port,
                    MMI_BOOL use_udp_port,
                    U16 highest_udp_port,
                    U16 lowest_udp_port,
                    void (*connect_result_callback)(MDI_RESULT, mdi_video_info_struct*));

extern MDI_RESULT mdi_video_stream_disconnect(void);
extern MMI_BOOL   mdi_video_stream_is_connected(void);

extern MDI_RESULT mdi_video_stream_start_buffering(
                    U64 time, 
                    void (*buffering_result_callback)(MDI_RESULT, mdi_video_info_struct*));
extern MDI_RESULT mdi_video_stream_stop_buffering(void);

extern MDI_RESULT mdi_video_stream_play(
                    gdi_handle player_layer_handle, 
                    U32 blt_layer_flag,
                    U32 play_layer_flag, 
                    MMI_BOOL is_visual_update, 
                    U8 audio_path, 
                    U16 rotate, 
                    void (*play_finish_callback) (MDI_RESULT)); 
extern MDI_RESULT mdi_video_stream_stop(void);

extern MDI_RESULT mdi_video_stream_pause(void);
extern MDI_RESULT mdi_video_stream_resume(
                    gdi_handle player_layer_handle, 
                    U32 blt_layer_flag,
                    U32 play_layer_flag, 
                    MMI_BOOL is_visual_update, 
                    U8 audio_path, 
                    U16 rotate);

extern MDI_RESULT mdi_video_stream_get_buf_percentage(S32 *percentage);
extern void       mdi_video_stream_get_cur_play_time(U64 *cur_play_time);
extern MDI_RESULT mdi_video_stream_set_brightness(U16 brightness);
extern MDI_RESULT mdi_video_stream_set_contrast(U16 contrast);
extern MDI_RESULT mdi_video_stream_get_dimension(S32 *video_width, S32 *video_height);  /* used by Java only */
extern MDI_RESULT mdi_video_stream_enable_partial_display(void);       /* allows to draw partial video out of lcd region */
extern MDI_RESULT mdi_video_stream_set_stop_time(U64 stop_time);       /* used by Java only */ 
extern MDI_RESULT mdi_video_stream_set_audio_level(U16 aud_level);     /* used by Java only */ 

#endif /* __MMI_VIDEO_STREAM__ */


/**** Progressive ****/
#ifdef __MMI_VIDEO_PDL__
extern MDI_RESULT mdi_video_progressive_open_file(
                    const S8 *filename,
                    void (*progressive_result_callback) (MDI_RESULT, mdi_video_info_struct*));
extern MDI_RESULT mdi_video_progressive_close_file(void);                    
extern MDI_RESULT mdi_video_progressive_get_max_play_time(U64 *max_play_time);
extern MDI_RESULT mdi_video_progressive_get_buf_percentage(S32 *buf_percentage);
extern MDI_RESULT mdi_video_progressive_is_pdl_format(U8 *file_buf, S32 buf_size, MMI_BOOL *is_pdl);
#endif /* __MMI_VIDEO_PDL__ */

/**** Video Editor ****/
#ifdef __MMI_VIDEO_EDITOR__
extern MDI_RESULT mdi_video_edt_open_clip_file(const S8 *filename, mdi_video_info_struct *info);
extern MDI_RESULT mdi_video_edt_close_clip_file(mdi_handle v_handle);
extern MDI_RESULT mdi_video_edt_active(mdi_handle v_handle);
extern MDI_RESULT mdi_video_edt_deactive(void);

extern MDI_RESULT mdi_video_edt_encode_open(S32 dest_video_width, S32 dest_video_height, PS8 filename);
extern MDI_RESULT mdi_video_edt_encode_close(void);

extern MDI_RESULT mdi_video_edt_open_bgm_clip_id(U16 audio_id, U64 *duration_p);
extern MDI_RESULT mdi_video_edt_close_bgm_clip_id(void);
extern MDI_RESULT mdi_video_edt_open_bgm_clip_file(const S8 *filename, U64 *duration_p);
extern MDI_RESULT mdi_video_edt_close_bgm_clip_file(void);
extern MDI_RESULT mdi_video_edt_open_silence_clip_id(U16 audio_id, U64 *duration_p);
extern MDI_RESULT mdi_video_edt_close_silence_clip_id(void);
extern MDI_RESULT mdi_video_edt_open_silence_clip_file(const S8 *filename, U64 *duration_p);
extern MDI_RESULT mdi_video_edt_close_silence_clip_file(void);

extern MDI_RESULT mdi_video_edt_encode_append_image(
                    gdi_handle img_layer, 
                    gdi_handle ext_layer_1,
                    gdi_handle ext_layer_2,
                    U32 duration,
                    MMI_BOOL is_use_bgm,
                    U32 bgm_start_time,
                    U32 bgm_end_time);

extern MDI_RESULT mdi_video_edt_encode_append_video(
                    mdi_handle v_handle,
                    gdi_handle ext_layer_1,
                    gdi_handle ext_layer_2,
                    U32 start_time,
                    U32 end_time,
                    MMI_BOOL is_use_bgm,
                    U32 bgm_start_time,
                    U32 bgm_end_time);                

extern MDI_RESULT mdi_video_edt_encode_merge(PS8 filename, void (*merge_result_callback) (MDI_RESULT));
extern MDI_RESULT mdi_video_edt_encode_stop_merge(void);
extern MDI_RESULT mdi_video_edt_init(void);
extern MDI_RESULT mdi_video_edt_deinit(void);
#endif /* __MMI_VIDEO_EDITOR__ */


/**** Video Telephony ****/
#ifdef __MMI_VIDEO_TELEPHONY__
typedef enum {
    MDI_VIDEO_TEL_DISPLAY_HIDE,
    MDI_VIDEO_TEL_DISPLAY_IMAGE,        
    MDI_VIDEO_TEL_DISPLAY_VIDEO
} mdi_video_tel_disp_type_enum;

typedef enum {
    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE,
    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY,
    
} mdi_video_tel_codec_event_enum;

typedef struct
{
    LOCAL_PARA_HDR
} mdi_vt_loopback_active_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} mdi_vt_loopback_deactive_req_struct;


extern MDI_RESULT mdi_video_tel_start(
                    gdi_handle peer_layer_handle,
                    gdi_handle local_layer_handle,    
                    mdi_video_tel_disp_type_enum peer_disp_type,
                    mdi_video_tel_disp_type_enum local_disp_type,          
                    U32 blt_layer_flag,                                 /* which layers will update to LCD */
                    U32 peer_layer_flag,                                /* which layer is peer layer */
                    U32 local_layer_flag,                               /* which layer is local layer */
                    mdi_video_setting_struct *local_preview_setting_p,  /* video setting */
                    void (*event_callback)(mdi_video_tel_codec_event_enum codec_event, S32 para)); 

extern MDI_RESULT mdi_video_tel_stop(void); 

extern void       mdi_video_tel_update_para_ev(U16 para);
extern void       mdi_video_tel_update_para_zoom(U16 para);
extern void       mdi_video_tel_enable_vt_loopback(void);
extern void       mdi_video_tel_disable_vt_loopback(void);

#endif /* __MMI_VIDEO_TELEPHONY__ */




#endif /* _MDI_VIDEO_H */ 

