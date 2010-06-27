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
 *
 * Filename:
 * ---------
 * video_dec_glb.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   video decode specific definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/



#ifndef __VIDEO_DEC_GLB_H__
#define __VIDEO_DEC_GLB_H__

/*For decoder*/

#ifndef __DRV_COMM_H__
#error "Please include drv_comm.h before video_dec_glb.h"
#endif
#ifndef _VISUAL_COMM_H
#error "Please include visual_comm.h before video_dec_glb.h"
#endif
#ifndef __FSAL_BUFFER_H__
#error "Please include fsal.h before video_dec_glb.h"
#endif
#ifndef __MP4_PARSER_H__
#error "Please include mp4_parser.h before video_dec_glb.h"
#endif
#ifndef L1AUDIO_H
#error "Please include l1audio.h before video_dec_glb.h"
#endif
#ifndef __LCD_IF_H__
#error "Please include lcd_if.h before video_dec_glb.h"
#endif
#ifndef VIDEO_FILE_CREATOR_H
#error "Please include video_file_creator.h before video_dec_glb.h"
#endif
#ifndef __MED_STATUS_H__
#error "Please include med_status.h before video_dec_glb.h"
#endif
#include "video_comm.h"
#include "video_dec_frame_buffer_manager.h"
#include "video_decore.h"
#include "video_dec_hwcofig_buffer.h"
#include "video_dec_isr.h"
#include "video_dec_mp4_isr.h"

#ifdef STREAM_SUPPORT
#include "video_rtp_reorder_buffer.h"
#include "video_rtp_h264_interleaved_buffer.h"
#endif

///////////////////////////////////////////////////////////////////////////////////
//                                     Internal definition                                                                  //
///////////////////////////////////////////////////////////////////////////////////

/*  Decode bitstream buffer size per decode buffer */
#define VIDEO_DEC_BUFFER_SIZE                (DEC_MAX_FRAME_WIDTH*DEC_MAX_FRAME_HEIGHT*3)
#define VIDEO_DEC_BUFFER_COUNT             3

#ifdef PGDL_SUPPORT
/*  Decode bitstream buffer size per decode buffer => progressive dl case */
#define VIDEO_DEC_PREGRESSIVE_DL_BUFFER_SIZE                (DEC_MAX_FRAME_WIDTH*DEC_MAX_FRAME_HEIGHT*3/2)
#define VIDEO_DEC_PREGRESSIVE_DL_BUFFER_COUNT             6
#endif

#ifdef STREAM_SUPPORT
/*  Decode bitstream buffer size per decode buffer => progressive dl case */
#define VIDEO_DEC_STREAM_BUFFER_SIZE             (STREAM_MAX_FRAME_WIDTH*STREAM_MAX_FRAME_HEIGHT*3/8)
#define VIDEO_DEC_STREAM_BUFFER_COUNT          ((VIDEO_DEC_BUFFER_SIZE*VIDEO_DEC_BUFFER_COUNT -VIDEO_RTP_REORDER_BUFFER_SIZE - H264_RTP_INTERLEAVED_BUFFER_SIZE - 1024 - VIDEO_DEC_MAX_BUFFER_COUNT*sizeof(VIDEO_DEC_BUFFER_MGR_STRUCT))/VIDEO_DEC_STREAM_BUFFER_SIZE)
#endif

/* Maximum LCD display size, and it will decide the memory resource for resizer */
#define LCD_DISP_MAX_SIZE              320

/* Maximum VIDEO GPT re-flash time, Unit: ms */
#define VIDEO_MAX_GPT_REFRESH_TIME_DEF     140

/* Maximum VIDEO GPT re-flash guard time, Unit: ms */
#define VIDEO_MAX_GPT_REFRESH_GAURD_TIME  50

/* Video decode status */
typedef enum
{
    // Video decode ok
    VIDEO_DEC_OK = MED_STAT_VIDEO_DEC_START,
    // This video decode frame size in file exceed our maximum size.
    VIDEO_DEC_FRAME_SIZE_ERROR,
    // This video bitstream is error.
    VIDEO_DEC_BITSTREAM_ERROR,
    // Some functions in this file are not supported.
    VIDEO_DEC_NOT_SUPPORT,
    // This function can't be called in this state.
    VIDEO_DEC_FUNC_STATE_ERROR,
    // The resource is not enough
    VIDEO_DEC_RESOURCE_NOT_AVAIL,
    // Function parameter error
    VIDEO_DEC_FUNC_PARAMETER_ERROR,
    // The error that is the bug of the driver
    VIDEO_DEC_FATAL_ERROR,
    // Video duration exceed the max duration.
    VIDEO_DEC_LONG_DURATION,
    // The warning show the end of audio when video seek
    VIDEO_DEC_SEEK_AUDIO_END,
    // Total Video decode status
    MAX_VIDEO_DEC_STATUS
}VIDEO_DEC_STATUS;

/* Video function stage */
typedef enum
{
    VIDEO_DEC_STAGE_UNKOWN = 0,
    VIDEO_DEC_STAGE_OPEN,
    VIDEO_DEC_STAGE_SEEK,
    VIDEO_DEC_STAGE_PLAY,
    VIDEO_DEC_STAGE_STOP,
    VIDEO_DEC_STAGE_CLOSE,
    VIDEO_DEC_MAX_STAGE
}VIDEO_DEC_STAGE;

/* Video image path state */
typedef enum
{
    VIDEO_DEC_IMG_PATH_NONE = 0,
    VIDEO_DEC_IMG_PATH_HW,
    VIDEO_DEC_IMG_PATH_SW,
    VIDEO_DEC_MAX_IMG_PATH
}VIDEO_DEC_IMG_PATH_TYPE;

typedef enum
{
    VIDEO_DEC_PARAM_WIDTH,
    VIDEO_DEC_PARAM_HEIGHT,
    VIDEO_DEC_PARAM_REAL_WIDTH,
    VIDEO_DEC_PARAM_REAL_HEIGHT,
    VIDEO_DEC_PARAM_TOTAL_FRAME_NUMER,
    VIDEO_DEC_PARAM_DEC_FRAME_NUMER,
    VIDEO_DEC_PARAM_HDR_PARSE_FRAME_NUMER,
    VIDEO_DEC_PARAM_SEEK_FRAME_NUMBER,
    VIDEO_DEC_PARAM_STOP_FRAME_NUMBER,
    VIDEO_DEC_PARAM_RESTART_FRAME_NUMER,
    VIDEO_DEC_PARAM_RESTART_STATUS,
    VIDEO_DEC_PARAM_CUR_FRAME_CODED,
    VIDEO_DEC_PARAM_MAX_WIDTH,
    VIDEO_DEC_PARAM_MAX_HEIGHT,
    VIDEO_DEC_PARAM_CUR_FRAME_DURATION,
    VIDEO_DEC_PARAM_FORCE_FAST_DECODE,
    VIDEO_DEC_PARAM_PLAY_TIME,
    VIDEO_DEC_PARAM_IS_DECODING,
    VIDEO_DEC_PARAM_B_PARSED_VOL,
    VIDEO_DEC_PARAM_B_H263,
    VIDEO_DEC_PARAM_TMP_PLAY_TIME,
    VIDEO_DEC_PARAM_DUMMY_ISR,
    VIDEO_DEC_PARAM_DUMMY_END,
}VIDEO_DEC_PARAM_TYPE;

typedef void (*video_dec_callback_type)(void);

typedef struct
{
    lcd_frame_update_struct *lcd_data;
    kal_uint32 lcd_buf_addr;
    kal_uint16 disp_width;
    kal_uint16 disp_height;
    kal_uint16 video_display_offset_x;
    kal_uint16 video_display_offset_y;
    kal_uint8 contrast_level;   /* IPP contrast gain level */
    kal_uint8 brightness_level; /* IPP brightness level */
    kal_bool force_lcd_hw_trigger;
#ifdef DRV_MP4_V2
    kal_bool image_pitch_mode;    /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;  /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes; /* pitch width */
    kal_bool tv_output;
    kal_uint32 tv_output_frame_buffer1_address;
    kal_uint32 tv_output_frame_buffer2_address;
    kal_uint32 tv_output_frame_buffer_size;
#endif

} MP4DEC_IMGPATH_STRUCT;

#ifdef STREAM_SUPPORT
#include "video_rtp_if.h"
#endif
#include "video_dec_buffer_manager.h"
#include "video_fileparse_adap.h"

typedef struct
{
    void (*video_dec_open)(kal_uint32 max_width, kal_uint32 max_height, kal_bool work_mem_ext);
    void (*video_dec_close)(void);
    MEDIA_STATUS_CODE (*video_dec_init)(void * config_param);
    MEDIA_STATUS_CODE (*video_dec_parse_data)(kal_uint8 * frame_addr, kal_uint32 frame_length, kal_uint32 prev_frame_duration, kal_bool b_first);
    void (*video_dec_start)(void);
    void (*video_dec_wait_done)(void);
    void (*video_dec_reset)(kal_bool b_enc_running);
    kal_uint64 (*video_get_param)(VIDEO_DEC_PARAM_TYPE type);
    void (*video_set_param)(VIDEO_DEC_PARAM_TYPE type, kal_uint64 value);
} Video_Decoder_Driver;


/* main video decoder information*/
typedef struct
{
    /* control param */
    // Decode type = DECODE_TYPE_MPEG4 or DECODE_TYPE_H263
    DECODE_TYPE decode_type;
    // decode state
    VIDEO_DEC_STAGE stage;
    // Mp4 video parser
    STMp4Parser *pMp4Parser;
    // file system abstration layer
    STFSAL *pstFSAL;

    Video_Decoder_Driver *p_driver;

    /* image path related  param */
    // image path type
    VIDEO_DEC_IMG_PATH_TYPE path_type;
    // LCD id
    kal_uint8 lcd_id;
    // The address of resizer working memory
    kal_uint32 resz_work_memory;
    // snapshot resize memory
    kal_uint32 snapshot_resize_memory;
    // snapshot imgdma memory
    kal_uint32 snapshot_imgdma_memory;
    // The max frame width and height that decoder support
    kal_uint16 max_width, max_height;
    // The frame width and height in bitstream
    kal_uint16 real_width, real_height;
    // The frame width and height in bitstream
    kal_uint16 width, height;
    // The display width and height
    kal_uint16 disp_width, disp_height;
    // display to LCD or not
    kal_bool display_enable;
    // display previous frame or not
    kal_bool prev_display_enable;
    // total lost display frames, exception recover
    kal_uint32 disp_lost_frames;
    // this frame is display fail, used for previous display check
    kal_bool b_display_fail;


    /* status */
    // This variable will be KAL_TRUE, when video is end.
    kal_bool video_end;
    // The incoming-call state or not
    //kal_bool incall;
    // audio enable or not when incoming-call
    kal_bool audio_enable;
    // play speed, unit = x/100; for example play_speed = 50
    // ==> The result speed will be(50/100 = 0.5)*normal speed.
    kal_uint16 play_speed;
    // Video callback function, which is register by MED task.
    void (*video_dec_callback)(kal_uint8 event);


    /* frame numbers */
    // total frames in media file
    kal_uint32 total_frames_in_file;
    // Stop frame no, when error detected!
    kal_uint32 stop_frame_no;
    // The seek frame number(used by lower layer)
    kal_uint32 seek_frame_number;
    // The seek frame number(used by higher layer).
    // When video bitstream is error, seek_frame_number != seek_result_frame_number
    kal_uint32 seek_result_frame_number;


    /* seek control param */
    // seek_by_time(KAL_TRUE) or seek_by_frame(KAL_FALSE)
    kal_bool seek_by_time;
    // seek_by_time(KAL_TRUE) or seek_by_frame(KAL_FALSE)
    kal_uint64 seek_time;
    // The time for the next frame of seeked frame.
    kal_uint64 seek_next_frame_time;


    /* time information */
    // current play time, Unit: ms
    kal_uint64 current_play_time;
    // video average frame duration
    kal_uint32 video_avg_frame_duration;
    // video time scale
    kal_uint32 video_time_scale;
    // Audio time scale
    kal_uint32 audio_time_scale;
    // This variable store the AV condition for media file. Unit: ms
    kal_uint64 audio_duration;
    // This variable store the AV condition for media file. Unit: ms
    kal_uint64 video_duration;
    // total play time
    //kal_uint64 play_time;
    // previous frame duration
    //kal_uint32 pre_frame_duration;
    kal_bool b_dummy_isr;
    kal_bool b_dummy_end;


    /* record information*/
    // performance evaluation, lost frame information
    kal_uint32 check_error_recover_count;  // Error recovery, user may feel not smooth 
    kal_uint32 check_display_loss_count;  //lcd display state busy when video want to display
    kal_bool b_check_log;  // check whether to print log or not, LISR can not pront log

#ifdef STREAM_SUPPORT
    kal_uint16 skip_err_chk_times;
    kal_bool is_stream_overflow;
    kal_uint8 display_mode;
    kal_uint16 sdp_width, sdp_height;
#endif
} VIDEO_DEC_STRUCT;

typedef struct
{
    kal_bool b_mp4;
    kal_bool b_file;
    kal_uint16 play_speed;
    kal_uint32 total_frame;
    kal_uint32 start_frame;
    kal_bool b_from_last_frame;
    void (*dec_callback)(kal_uint8 event);
}MP4_CONFIG_PARAM;

/* video decoder status */
typedef struct
{
    // Decoder is running or not
    kal_bool running;
    // video scenario
    VIDEO_SCENARIO_ENUM scenario;
    // Video decode status
    VIDEO_DEC_STATUS VIDEO_STATUS;
    // The status of file system abstration layer
    FSAL_Status FSAL_STATUS;
    // Store the file that result FSAL_Status
    STFSAL *FSAL_ERROR_FILE;
    // The status of Mp4 parser
    MP4_Parser_Status PARSE_STATUS;
    kal_bool noVideoTrack;
    kal_bool noAudioTrack;
} VIDEO_DEC_STATUS_STRUCT;

/*Input struct: Start*/
typedef struct
{
    STMp4Parser *pstMp4Parser;
    STFSAL *pstFSAL;
    //kal_uint32 start_frame_no;
    void (*video_dec_callback)(kal_uint8 event);
    kal_uint16 max_width;
    kal_uint16 max_height;
    //kal_bool incall;
    kal_bool audio_enable;
} MP4DEC_COMM_INIT_STRUCT;
/*Input struct: for function input ==END*/


///////////////////////////////////////////////////////////////////////////////////
//                                     upper layer interface  definition                                                //
///////////////////////////////////////////////////////////////////////////////////

/* Video Event for upper layer */
typedef enum
{
    // Buffer empty event, upper layer should fill up the buffer
    VIDEO_DEC_EVENT_BUFFER_EMPTY = 0,
    // Decode complete event
    VIDEO_DEC_EVENT_COMPLETE,
    // Partial Seek ready event, because long file seek
    VIDEO_DEC_EVENT_SEEK_PARTIAL_DONE,
    // Seek ready event
    VIDEO_DEC_EVENT_SEEK_DONE,
    // No Video track event
    VIDEO_DEC_EVENT_NO_TRACK,
    // Someting wrong in video driver, upper layer should call function
    // to obtain error casue.
    VIDEO_DEC_EVENT_FAIL,
    // MCU is too busy to run this video.
    // When upper layer receive this event, call video_dec_recover to pause/resume/recover this video.
    VIDEO_DEC_RECOVER,
    // audio complete event for seek
    VIDEO_DEC_SEEK_AUDIO_EVENT_COMPLETE,
    // video seek handler.
    VIDEO_DEC_DRV_SEEK_ACTION,
    // Total Events
    VIDEO_DEC_MAX_EVENT
}VIDEO_DEC_EVENT;

/*Input struct: Start*/
typedef struct
{
    STMp4Parser *pstMp4Parser;
    STFSAL *pstFSAL;
    //kal_uint32 start_frame_no;
    void (*video_dec_callback)(kal_uint8 event);
    kal_uint16 max_width;
    kal_uint16 max_height;
    kal_bool audio_enable;
} MP4DEC_INIT_STRUCT;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
    kal_uint32 disp_width;
    kal_uint32 disp_height;
    kal_uint32 lcd_buf_addr;
    kal_uint8 contrast_level;   /* IPP contrast gain level */
    kal_uint8 brightness_level; /* IPP brightness level */
#ifdef DRV_MP4_V2
    kal_bool image_pitch_mode;    /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;  /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes; /* pitch width */
    kal_bool tv_output;
#endif
} MP4DEC_MEMMODE_STRUCT;
/*Input struct: for function input ==END*/

/// Maximum VIDEO GPT re-flash time, Unit: ms
///
extern kal_uint16 VIDEO_MAX_GPT_REFRESH_TIME;

extern Video_Decoder_Driver g_video_dec_mp4_driver;

///////////////////////////////////////////////////////////////////////////////////
//                                     Internal functions                                                                  //
///////////////////////////////////////////////////////////////////////////////////

/* Start refresh function.
* @param None
* @return None
*/
extern void video_dec_start_refresh(void);

/* Stop refresh function.
* @param None
* @return None
*/
extern void video_dec_stop_refresh(void);

/* Check whether it needs to be refresh. If yes, it will refresh automatically in this function
* @param None
* @return None
*/
extern void video_dec_check_refresh(kal_uint32 frame_time);

/* This function initialize the video decode module.
 * @param init_input MP4DEC_INIT_STRUCT
 * @param max_width maximum width that application wishes ti support
 * @param max_height maximum height that application wishes ti support
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_editor_initialize(MP4DEC_INIT_STRUCT * init_input);

/* Open the video decode process.
* When call "video_dec_initialize" API, this function is also called.
* @param  pstMp4Parser The handle of mp4 parser
* @param  pstFSAL The handle of file abstract layer
* @return Media status, which is based MEDIA_STATUS_CODE structure.
*/
extern MEDIA_STATUS_CODE video_dec_open(STMp4Parser * pstMp4Parser, STFSAL * pstFSAL, kal_uint32 max_width, kal_uint32 max_height);

/* Initialize the video decode av process
* When call "video_dec_initialize" API, this function is also called.
* @param b_audio_enable enable audio or not
* @return Media status, which is based MEDIA_STATUS_CODE structure.
*/
extern MEDIA_STATUS_CODE video_dec_init_av(kal_bool b_audio_enable);

/* Decode process is done. Notify upper layer and refresh when needed.
* @param  frame_no the frame that should be seek
* @param callback video callback function when driver want to notify MED or upper layer.
* @param seek_from_current_frame_mode. application can decide whether to seek from current frame or not
* @return  None
*/
extern MEDIA_STATUS_CODE video_dec_seek_by_frame(kal_uint32 frame_no, void (*callback)(kal_uint8 event),
                                          kal_bool seek_from_current_frame_mode);

/* Decode process is done. Notify upper layer and refresh when needed.
* @param  None
* @return  None
*/
extern void video_dec_complete(void);

/* Set stop frame
 * @param  disp_width   video display width in LCD
 * @param  disp_height  video LCD display height in LCD.
 * @return None.
 *
 */
extern void video_dec_set_stop_frame(kal_uint32 frame_number);


///////////////////////////////////////////////////////////////////////////////////
//                                     upper layer interface  functions                                                //
///////////////////////////////////////////////////////////////////////////////////

/* Open the image path(Resizer+LCD+ImageDMA+ImgProc), then this path will be conrolled by driver.
 * @param  data_input   MP4DEC_IMGPATH_STRUCT parameter should be prepared by MMI
 * @return None.
 */
extern void video_image_path_open(MP4DEC_IMGPATH_STRUCT * data_input);

/* Close the image path(Resizer+LCD+ImageDMA+ImgProc)
 * @param None
 * @return None.
 */
extern void video_image_path_close(void);

/* Display the current frame that is decoded done.
* @param None
* @return None
*/
extern void video_dec_display(void);

/* Display the previous frame.
* @param None
* @return None
*/
extern void video_dec_prev_display(void);

/* Open the image path(Resizer+ImageDMA+ImgProc), then this path will be conrolled by MED/MMI.
 * @param  data_input   MP4DEC_MEMMODE_STRUCT be prepared by MMI
 * @return None.
 */
extern void video_memorymode_open(MP4DEC_MEMMODE_STRUCT * data_input);

/* Close the image data path
 * @param None
 * @return None.
 */
extern void video_memorymode_close(void);

/* This function should be called after video_swmode_open is called.
 * This function will copy the last decoded frame to another memory buffer.
 * @param None
 * @return None.
 */
extern void video_dec_frame_to_memory(void);

/* This function should be called after video_swmode_open is called.
 * This function will disaply the previous frame.
 * @param None
 * @return None.
 */
extern void video_dec_prev_frame_to_memory(void);

/* This function is used to obtain the play time according to frame number
 * @param  frame frame number
 * @param  time  time ptr. (Unit: ms)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_frame2time(kal_uint32 frame, kal_uint32 * time);

/* This function is used to obtain the frame number according to the play time.
 * @param  time   play time(Unit: ms)
 * @param  frame  Frame number.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_time2frame(kal_uint32 time, kal_uint32 * frame);

/*This function is for snapshot scenario when video play
 * @param memory_addr      resizer working memory addr;
 * @return NULL
 */
extern void video_dec_set_snapshot_resize_mem(kal_uint32 memory_addr);

/* This function is for snapshot scenario when video play
 * @param None
 * @return resizer working memory addr;
 */
extern kal_uint32 video_dec_get_snapshot_resize_mem(void);

/* This function is for snapshot scenario when video play
 * @param memory_addr      imgdma working memory addr;
 * @return NULL
 */
extern void video_dec_set_snapshot_imgdma_mem(kal_uint32 memory_addr);

/* This function is for snapshot scenario when video play
 * @param None
 * @return imgdma working memory addr;
 */
extern kal_uint32 video_dec_get_snapshot_imgdma_mem(void);

/* This function can set different speed for video
 * final play speed = normal play speed * (play_speed/100)
 * @param play_speed   play speed ratio.
 * @return NULL
 */
extern void video_dec_set_play_speed(kal_uint16 play_speed);

/* Get total video frames
 * @param None
 * @return total video frames
 */
extern kal_uint32 video_dec_get_total_frame(void);

/* Get the last decoded frame number.
 * @param None
 * @return the last decoded frame number.
 */
extern kal_uint32 video_dec_get_current_frame_no(void);

/* Get current total play time in video
 * @param total_play_time obtain the current total play time. (Unit: ms)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_get_total_play_time(kal_uint64 * total_play_time);

/* This function will obtain audio and video total duration.
 * @param  audio_time audio total duration
 * @param  video_time video total duration.
 * @return  None
 */
extern void video_dec_get_total_time(kal_uint64 * audio_time, kal_uint64 * video_time);

/* Get current play time
 * @param  current_time  current play time(Unit: ms)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_get_play_time(kal_uint64 * current_time);

/* This function can obtain the total duration from 1 to frame_no-1.
 * @param frame_no      frame number.
 * @param decode_time   the decode time
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE Video_GetDecodeTime(kal_uint32 frame_no, kal_uint64 * decode_time);

/* This function is used to set the stop frame that video will auto-stop at this frame.
 * @param  play_stop_time   stop time, (unit: ms)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_set_stop_time(kal_uint32 play_stop_time);

/* This function can obtain the original frame widht/height.
 * @param width   original video frame width
 * @param height  original video frame height
 * @return None
 */
extern void video_dec_get_frame_size(kal_uint16 * width, kal_uint16 * height);

/* This function is enable audio play or not, when video decode.
 * @param  enable enable or not
 * @return None
 */
extern void video_dec_set_audio(kal_bool enable);

/* This function is enable LCD display or not, when video decode.
 * @param  enable enable or not
 * @return None
 */
extern void video_dec_set_display(kal_bool enable);

/* This function is get whether current video file is finised or not
 * @param  None
 * @return finished status
 */
extern kal_bool video_dec_is_play_finished(void);

/* This function initialize the video decode module.
 * @init_input  MP4DEC_INIT_STRUCT prepared by upper layer
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
//extern MEDIA_STATUS_CODE video_dec_initialize(MP4DEC_INIT_STRUCT * init_input);

/* This function will open the video decode initialize
 * @param  clip_input MP4DEC_INIT_STRUCT prepared by upper layer
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_initialize(MP4DEC_INIT_STRUCT * clip_input);

/* This function should be called after video_dec_seek.
 * This function can play video sequently.
 * @param audio_frame_no The related audio frame that related to seek video frame.
 * @param video_dec_callback video callback function when driver want to notify MED or upper layer.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_play(kal_uint32 * audio_frame_no, void (*video_dec_callback)(kal_uint8 event), kal_bool b_from_start);

/* This function should be called after video_dec_clip_initialize.
 * This function can play video clip sequently.
 * @param audio_frame_no The related audio frame that related to seek video frame. If audio is not enable, don't care "audio_frame_no" parameter!!
 * @param video_dec_callback video callback function when driver want to notify MED or upper layer.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
//extern MEDIA_STATUS_CODE video_dec_clip_play(kal_uint32 * audio_frame_no, void (*video_dec_callback)(kal_uint8 event));

/* This function can recover when error happens
 * @param audio_frame_no   the related audio frame that is related recovered video frame number.
 * @param callback  video callback function when driver want to notify MED or upper layer.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_recover(kal_uint32 * audio_frame_no, void (*callback)(kal_uint8 event));

/* This function will seek to the request frame time.
 * @param seek_time seek time
 * @param callback it is callback function when video driver want to notify upper layer.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_seek(kal_uint64 seek_time, void (*callback)(kal_uint8 event));

/* Seek action during seek procedure
 * This function is to replace the HISR action.
 * @param None
 * @return None
 */
extern void video_seek_action(void);

/* This function stop the video driver, but not release the resource.
 * @param None
 * @return None
 */
extern void video_dec_stop(void);

/* Close the video decode process.
 * @param None
 * @return None
 */
extern void video_dec_close(void);

/* This function will open the video progressive-download decode initialize
 * @param  clip_input MP4DEC_CLIP_INIT_STRUCT prepared by upper layer
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_PDL_initialize(MP4DEC_INIT_STRUCT * clip_input);

extern void video_stream_memorymode_close(void);		/*Jensen, 2/6, temp solution. Need to discuss it with Jerry*/

#endif /* __VIDEO_DEC_GLB_H__ */
