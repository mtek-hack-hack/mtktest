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
 *    video_enc_glb.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines the encode related information.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
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
 *******************************************************************************/



#ifndef __VIDEO_ENC_GLB_H__
#define __VIDEO_ENC_GLB_H__

//#define __VIDEO_GET_YUV_DATA__

#ifndef __DRV_COMM_H__
#error "Please include drv_comm.h before video_enc_glb.h"
#endif

#ifndef BMD_H
#error "Please include bmd.h before video_enc_glb.h"
#endif

#ifndef _VISUAL_COMM_H
#error "Please include visual_comm.h before video_enc_glb.h"
#endif
#ifndef __FSAL_BUFFER_H__
#error "Please include fsal.h before video_enc_glb.h"
#endif
#ifndef __MP4_PARSER_H__
#error "Please include mp4_parser.h before video_enc_glb.h"
#endif
#ifndef L1AUDIO_H
#error "Please include l1audio.h before video_enc_glb.h"
#endif

#ifndef VIDEO_FILE_CREATOR_H
#error "Please include video_file_creator.h before video_enc_glb.h"
#endif

#ifndef __MED_STATUS_H__
#error "Please include med_status.h before video_enc_glb.h"
#endif

#include "l1audio.h"

#include "video_comm.h"

#ifdef DRV_MP4_V1
   /*QCIF*/
   /// Maximum encode frame width
   ///
   #define ENC_MAX_FRAME_WIDTH                           176
   /// Maximum encode frame height
   ///
   #define ENC_MAX_FRAME_HEIGHT                          144
   /// Maximum Chip encode frame width
   ///
   #define CHIP_ENC_MAX_FRAME_WIDTH                      352
   /// Maximum Chip encode frame height
   ///
   #define CHIP_ENC_MAX_FRAME_HEIGHT                     288
#ifdef DRV_MP4_V1_ENC_PARAM_TYPE_1
   /// bitstream buffer size per encode buffer
   ///
   #define VIDEO_ENC_BUFFER_SIZE                         (150*1024)
   /// Maximum encode bitstream buffer count
   ///
   #define VIDEO_ENC_MAX_BUFFER_COUNT                    3
#else /*!DRV_MP4_V1_ENC_PARAM_TYPE_1*/
   /// bitstream buffer size per encode buffer
   ///
   #define VIDEO_ENC_BUFFER_SIZE                         (ENC_MAX_FRAME_WIDTH*ENC_MAX_FRAME_HEIGHT+128)
   /// Maximum encode bitstream buffer count
   ///
   #define VIDEO_ENC_MAX_BUFFER_COUNT                    7
#endif
   /// Maximum encode meta buffer count
   ///
   #define META_ENC_BUFFER_SIZE                          (16*1024)
   /// The trigger pointer of encode meta buffer
   ///
   #define META_ENC_BUFFER_TRIGGER_POINT                 512
   /// Maximum working memory
   ///
   #define ENC_MAX_WORK_MEMORY            ((ENC_MAX_FRAME_WIDTH*ENC_MAX_FRAME_HEIGHT*3)+3072+512)
   /// Maximum encode frame rate
   ///
   #define Video_Enc_Max_FrameRate                       15
   /// Maximum encode bit rate
   ///
   #define Video_Enc_Max_BitRate                         480000
   /// Encode intra period
   ///
#ifdef DRV_MP4_V1_ENC_PARAM_TYPE_1
   #define Video_Enc_IntraPeriod                         128
#else /*!DRV_MP4_V1_ENC_PARAM_TYPE_1*/
   #define Video_Enc_IntraPeriod                         32
#endif /*DRV_MP4_V1_ENC_PARAM_TYPE_1*/

#else /*!DRV_MP4_V1*/
   /*VGA*/
   /// Maximum encode frame width
   ///
   #define ENC_MAX_FRAME_WIDTH                           352
   /// Maximum encode frame height
   ///
   #define ENC_MAX_FRAME_HEIGHT                          288
   /// Maximum Chip encode frame width
   ///
   #define CHIP_ENC_MAX_FRAME_WIDTH                      640
   /// Maximum Chip encode frame height
   ///
   #define CHIP_ENC_MAX_FRAME_HEIGHT                     480
   /// bitstream buffer size per encode buffer
   ///
   //#define VIDEO_ENC_BUFFER_SIZE                         (450*1024+128)
   #define VIDEO_ENC_BUFFER_SIZE                         (ENC_MAX_FRAME_WIDTH*ENC_MAX_FRAME_HEIGHT+128)
   /// Maximum encode bitstream buffer count
   ///
   #define VIDEO_ENC_MAX_BUFFER_COUNT                    7
   /// Maximum encode meta buffer count
   ///
   #define META_ENC_BUFFER_SIZE                          (16*1024)
   /// The trigger pointer of encode meta buffer
   ///
   #define META_ENC_BUFFER_TRIGGER_POINT                 512
   /// Maximum working memory
   ///
#ifdef DRV_MP4_V2_ENHANCE
   #define ENC_MAX_WORK_MEMORY                           (3072+1024+328 + (ENC_MAX_FRAME_WIDTH*56*3/2) + (3*16*16))
#else
   #define ENC_MAX_WORK_MEMORY                           (3072+1024+328)
#endif
   /// Maximum encode frame rate
   ///
   #define Video_Enc_Max_FrameRate                       30
   /// Maximum encode bit rate
   ///
   #define Video_Enc_Max_BitRate                         1920000
   /// Encode intra period
   ///
   #define Video_Enc_IntraPeriod                         128
#endif /* DRV_MP4_V1 */

typedef enum
{
   /// Video encode ok
   ///
   VIDEO_ENC_OK = MED_STAT_VIDEO_ENC_START,
   /// This video encode frame size exceed our maximum size.
   ///
   VIDEO_ENC_FRAME_SIZE_ERROR,
   /// The bitrate too large.
   ///
   VIDEO_ENC_BITRATE_ERROR,
   /// The frame rate too large.
   ///
   VIDEO_ENC_FRAME_RATE_ERROR,
   /// This function can't be called in this state.
   ///
   VIDEO_ENC_FUNC_STATE_ERROR,
   /// The resource is not enough
   ///
   VIDEO_ENC_RESOURCE_NOT_AVAIL,
   /// The bitstream file and meta file can't merge a media file.
   ///
   VIDEO_ENC_FILE_CANT_MERGE,
   /// Some functions in this file are not supported.
   ///
   VIDEO_ENC_NOT_SUPPORT,
   /// The error that is the bug of the driver
   ///
   VIDEO_ENC_FATAL_ERROR,
   /// The total encode status
   ///
   MAX_VIDEO_ENC_STATUS
} VIDEO_ENC_STATUS;

typedef enum {
   VIDEO_ENC_STAGE_UNKOWN=0,
   VIDEO_ENC_STAGE_INIT,
   VIDEO_ENC_STAGE_OPEN,
   VIDEO_ENC_STAGE_CLOSE,
   VIDEO_ENC_MAX_STAGE
} VIDEO_ENC_STAGE;      /// Video encode function stage.


typedef enum {
   VIDEO_ENC_START_RECORD_STATE_STOP=0,
   VIDEO_ENC_START_RECORD_STATE_START,
   VIDEO_ENC_START_RECORD_STATE_RESUME_START,
   VIDEO_ENC_START_RECORD_STATE_RUNING,
   VIDEO_ENC_START_RECORD_MAX_STATE
} VIDEO_ENC_START_RECORD_STATE;      /// Video encode start record state

typedef enum
{
   MMFILE_MP4=0x40,
   MMFILE_3GP,
   MMFILE_AVI,
   MMFILE_UNKOWN
} MMFILE_TYPE;          /// Media file type

typedef enum   {
   /// VIDEO bitstream buffer is available, and wait MED task move these data
   /// to video bitstream file
   VIDEO_ENC_EVENT_VIDEO_BUFFER_AVAIL=50,
   /// VIDEO meta buffer is available, and wait MED task move these data to video meta file
   ///
   VIDEO_ENC_EVENT_META_BUFFER_AVAIL,
   /// VIDEO encode complete.
   ///
   VIDEO_ENC_EVENT_COMPLETE,
   /// VIDEO encode fail.
   ///
   VIDEO_ENC_EVENT_FAIL,
   /// Count file size for file size limit
   ///
   VIDEO_ENC_EVENT_COUNT_FILE_SIZE,
   VIDEO_ENC_MAX_EVENT
} VIDEO_ENC_EVENT;


/// RingBuffer description for meta buffer
///
typedef struct {
   kal_uint8 mem_block_no; /*1 or 2*/
   kal_uint32 start_addr[2];
   kal_uint16 length[2];
}VIDEO_BUF_DESC;

typedef struct
{
	kal_uint8                     *buffer;
	kal_uint32                    buffer_length;
	kal_uint32                    buffer_index;
	kal_bool                      is_read_done;     //for task read, and write to flash
}VIDEO_ENC_BUFFER_STRUCT;

///Rate control information
///
typedef struct
{
   kal_uint32     time_stamp[4];
   kal_uint8      time_stamp_index;
   kal_uint32     buffer_frame_num;
   kal_uint32     avg_frame_duration;
   kal_uint32     frame_rate;
   kal_bool       run_done;
}FR_STRUCT;

typedef struct
{
   kal_int32   buffer_bits;
   kal_int32   buffer_frame_num;
   kal_int32   quant_temp;
   FR_STRUCT   fr_rate;
   kal_int32	intra_mb_evaluation_count;
   kal_int32	same_quant_count;
}RC_STRUCT;

/// Bitstream header information
///
typedef struct  {
   /// frame rate. for exampe : 15 fps.
   ///
	kal_int32   frame_rate;
	/// encoded frame width
	///
	kal_int32   width;
	/// encoded frame height
	///
	kal_int32   height;
	/// store the intra frame number.
	///
	kal_int32   intra_num;
	/// short header mode(H.263) or not(Mpeg4).
	///
	kal_bool    short_header;
	/// I_VOP or P_VOP
	///
	kal_int32   predition_type;
	/// This value represents the absolute vop_time_increment from the
	/// synchronization point marked by the modulo_time_base measured
	/// in the number of clock ticks. It can take a value in the range
	/// of [0,vop_time_increment_resolution)
	kal_int32   vop_time_increment;
	///
	///
	kal_int32   fixed_vop_time_increment;
	/// vop_time_increment_resolution, indicates the number of evenly spaced subintervals,
	/// called ticks, within one modulo time. One modulo time represents the fixed interval
	/// of one second. The value zero is forbidden.
	kal_int32   time_increment;
	///
	///
	kal_uint32 old_time;
	/// quantizer value
	///
	kal_int32   quantizer;
	/// vop_fcode_forward, values from 1 to 7; the value of zero is forbidden.
	/// It is used in decoding of motion vectors.
	kal_int32   fcode;
	///
	///
	kal_int32   time_base;
	///
	///
	kal_bool  b_resync_marker;
	///
	///
	kal_int32   prev_vop_time_increment;
	///
	///
	kal_int32   prev_old_time;
}m4v_enc_im;

typedef struct {
   /// Video encode bitstream buffer
   ///
   VIDEO_ENC_BUFFER_STRUCT       VIDEO_ENC_BUFFER[VIDEO_ENC_MAX_BUFFER_COUNT];
   /// Current write encode bitstream id
   ///
   kal_uint8                     write_enc_buffer_id;
   /// Current read encode bitstream id
   ///
   kal_uint8                     read_enc_buffer_id;
   /// Video encode meta buffer(ringbuffer) information
   ///
   BUFFER_INFO                   META_ENC_BUFFER;   /*stsz+stts*/
   /// RingBuffer description for meta buffer
   ///
   VIDEO_BUF_DESC                meta_mem_desc;
   /// Physical meta buffer
   ///
   kal_uint32                    meta_enc_buffer[(META_ENC_BUFFER_SIZE+3)/4];
   /// encode bit rate
   /// good: 384K, normal: 128K, soso:64K
   kal_uint32                    bit_rate;
   /// time stamp for current encoded frame
   ///
   kal_uint32                    time_stamp;
   /// const delay for time stamp(AV sync)
   ///
   kal_uint32                    const_delay;
   /// bitstream buffer handling. If this variable is true, driver can send ilm to MED task.
   ///
   kal_bool                      is_send_ilm;   // just for bitstream buffer
   /// average frame rate.
   ///
   kal_uint16                    FRAME_RATE;
   /// encode file type
   ///
   MMFILE_TYPE                   file_type;      /*.3gp, .mp4*/
   /// reach file size limit or not
	///
	kal_bool                      is_reach_file_size_limit;
   /// bitstream header information
   ///
   m4v_enc_im                    im;
   /// VOS information
   ///
   MP4VIDEO_VOS_STRUCT           VOS;
   /// safty check for imgdma isr reentry count.
   ///
   kal_uint8                     safty_check_count;
   /// Current recode time duration
   ///
   kal_uint64                    current_time_duration;
   /// Previous time stamp, this value is used to caluate the current_time_duration.
   ///
   kal_uint32                    prev_time_stamp;
   /// this variable will stop the software encode process. But HW is not stop.
   ///
   kal_bool                      encode_stop;
   /// total lost frames from camera
   ///
   kal_uint32                    lost_frames;
   /// This variable will force to drop the bitstream from video buffer.
   ///
   kal_bool                      drop_bitstream;
   /// This variable can force the mpeg4 software engine to encode as I frame.
   ///
   kal_bool                      force_I_frame;
   /// Large quant count
   ///
   kal_bool                      large_quant_count;
   /// This variable is used for error recovery, when mcu loading is not enough.
   /// Then, Driver will always check the buffer status, and run the recovery action.
   kal_bool                      is_need_to_check_buffer;
   /// Maximum check count when buffer status should be checked.
   /// Before this check count, our system must recover.
   /// Otherwise, driver will threat it as crach.
   kal_uint8                     chk_buffer_status_count;
   /// switch buffer callback function. for error recovery.
   ///
   void                          (*switch_buffer_callback)(void);
   /// audio recode callback function from MED task, and register to audio driver.
   ///
   void                          (*audio_record_callback)(Media_Event event);
   /// video encode callback function from MED task. Driver can notify MED its
   /// events through this function.
	void                          (*video_enc_callback)(kal_uint8 event);
	/// This variabe indicated if task is preparing bitstream data to driver.
	///
   kal_bool                      is_task_prepare_video_data;
   /// This variabe indicated if task is preparing meta data to driver.
   ///
   kal_bool                      is_task_prepare_meta_data;
   ///   How many frames to skip
   ///
   kal_uint8                     skip_frame_count;
   /// video encode function stage
   ///
   VIDEO_ENC_STAGE               stage;
	/// Store the current bitstream addr in buffer.
	///
   kal_uint32                    current_bitstream_addr;
   /// Total file size
	///
   kal_uint32                     total_file_size;
   /// ISR(ImgDMA) encode total frames
   ///
   kal_uint32                    total_frames;
   /// HISR executed total frames
   ///
   kal_uint32                    hisr_total_frames;

   /* record information*/
   // performance evaluation, lost frame information
   kal_uint32                  check_camera_miss_count;
   kal_uint32                  check_buffer_miss_count;	
   kal_bool                     b_check_log;   // check whether to print log or not, LISR can not pront log                 	
}VIDEO_ENC_STRUCT;

typedef struct {
   /// Encoder is running or not
	///
	kal_bool                      running;
	/// video scenario
	///
	VIDEO_SCENARIO_ENUM           scenario;
	/// Video encode status
   ///
	VIDEO_ENC_STATUS	            VIDEO_STATUS;
	/// The status of file system
	///
	kal_int32                     FS_STATUS;
	/// Store the file that result FSAL_Status
	///
	STFSAL                        *FSAL_ERROR_FILE;
	/// The status of file system abstration layer
	///
	FSAL_Status                   FSAL_STATUS;
}VIDEO_ENC_STATUS_STRUCT;

typedef struct {
   RC_STRUCT                     rc_data;
   m4v_enc_im                    im;
   kal_bool                      pause_already;
   kal_uint32                    total_frames;
   kal_uint32                    hisr_total_frames;
   kal_uint32                    bit_rate;
   kal_uint32                    current_time_duration;
   kal_uint32                    prev_time_stamp;
   kal_uint16                    FRAME_RATE;
   kal_uint32                    time_scale;
   Media_Format                  video_enc_audio_format;
   kal_uint32                    total_file_size;
} VIDEO_ENC_PAUSE_INFO;

#ifdef __VIDEO_GET_YUV_DATA__
   #define VIDEO_YUV_MAX_BUFFER  16
   typedef struct {
      union{
      		kal_uint32 yuvCIF[VIDEO_YUV_MAX_BUFFER][352*288*3/8];
            kal_uint32 yuvQCIF[VIDEO_YUV_MAX_BUFFER*4][176*144*3/8];
      	}yuvdata;
      kal_uint32 read_index;
      kal_uint32 write_index;
      STFSAL     MEDIA_YUV_FILE;
      kal_bool   send_ilm;
      kal_bool   enable_log;
      kal_uint32 yuv_max_buffer_count;
      kal_bool   cif_size;
   } VIDEO_YUV_DATA_STRUCT;
   extern VIDEO_YUV_DATA_STRUCT video_yuv;
#endif   /*__VIDEO_GET_YUV_DATA__*/

typedef struct
{
    kal_uint8 *frame_buffer_addr;
    kal_uint8 *working_memory;
} MPEG4_ENCODE_STRUCT;

/*Input struct: Jensen ==Start*/
typedef struct {
   kal_bool    short_header;
   kal_uint32  bit_rate;
   kal_uint16  frame_width;
   kal_uint16  frame_height;
   void        (*call_back)(kal_uint8 event);
} MP4ENC_SETUP_STRUCT;

typedef struct {
   kal_uint32  frame;
   kal_uint8   *input_yuv_data;
   kal_uint8   *bitstreams_ptr;
   kal_uint32  buffer_length;
   m4v_enc_im  *im;
   kal_bool     b_force_I_frame;
   kal_uint32  pkt_size_limit;
} MP4ENC_PROC_STRUCT;

/*Input struct: Jensen, for function input ==END*/

extern void (*audio_record_callback)(Media_Event event);
extern Media_Format   video_enc_audio_format;

extern kal_uint32 video_enc_get_bitstream_file_size(void);

/*encode*/

/**
 * This function will store the audio callback function to "audio_record_callback" variable,
 * and register it to audio driver at the proper time.
 * @param  audio_rec_callback audio callback function
 * @return None
 *
 */
extern void video_enc_audiocallback(void (*audio_rec_callback)(Media_Event event));

/**
 * This function will store the video bitstream from bistream buffer to bitstream file.
 * This function only used when encode complete.
 * @param  max_size This variable threated as the max size that med task can offer.
 * @param  real_store_size The real size to store to FS.
 * When driver store its bitstream, driver can't exceed this value.
 * Besides, driver will notify the med task the space driver have used through this variable, too.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_buffer_dump_to_file(kal_uint32 max_size, kal_uint32 *real_store_size);

/**
 * This function will store the meta information from meta buffer to meta file.
 *
 * @param  max_size This variable threated as the max size that med task can offer.
 * @param  real_store_size The real size to store to FS.
 * When driver store its bitstream, driver can't exceed this value.
 * Besides, driver will notify the med task the space driver have used through this variable, too.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE meta_enc_buffer_store_file(kal_uint32 org_max_size, kal_uint32 *real_store_size);

/**
 * This function will store the video bitstream from bistream buffer to bitstream file.
 * This function only used when driver notify med task "buffer is available".
 * @param  max_size This variable threated as the max size that med task can offer.
 * @param  real_store_size The real size to store to FS.
 * When driver store its bitstream, driver can't exceed this value.
 * Besides, driver will notify the med task the space driver have used through this variable, too.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_buffer_store_file(kal_uint32 max_size, kal_uint32 *real_store_size);

/**
 * This function will initialize the VIDEO_ENC_STRUCT as default value.
 * @param  enc_struct VIDEO_ENC_STRUCT structure.
 * @param  file_type Media file type, based on MMFILE_TYPE structure.
 * @param  frame_count initial frame count. This value is always 0, except video editor scenario.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE mp4_enc_struct_init(VIDEO_ENC_STRUCT *enc_struct, MMFILE_TYPE file_type, kal_uint32 frame_count);

/**
 * This function will obtain the current bitstream address from bitstream buffer.
 * @param  enc_struct VIDEO_ENC_STRUCT structure.
 * @return current bitstream address.
 *
 */
extern kal_uint32 video_enc_buffer_get_memaddr(VIDEO_ENC_STRUCT *enc_struct);

extern void video_enc_reverse_prev_time(m4v_enc_im * header);

/**
 * This function will obtain the room left value from bitstream buffer.
 * @param  enc_struct VIDEO_ENC_STRUCT structure.
 * @return the room left value of bitstream buffer.
 *
 */
extern kal_uint32 video_enc_buffer_get_roomleft(VIDEO_ENC_STRUCT *enc_struct);

/**
 * This function will execute and trigger HW to run the encode process.
 * @param  frame frame number.
 * @param  input_yuv_data  input image yuv420 source.
 * @param  bitstreams_ptr current bistream address in bitstream buffer.
 * @param  buffer_length the room left in bitstream buffer
 * @param  im mpeg4 bitstream information.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_proc(MP4ENC_PROC_STRUCT *proc_data);

/**
 * This function update the bistream length to bistream buffer structure.
 * @param  length bitstream length
 * @return None
 *
 */
extern void video_enc_buffer_update_offset(kal_uint32 length);

/**
 * This function obtain intra marco block number from current encode done frame.
 * @return intra macro block number.
 *
 */
extern kal_uint16 video_enc_get_intra_mb_num(void);

/**
 * This function update time_stamp and length of frame to meta buffer.
 * @param  time_stamp time stamp of the frame.
 * @param  length encoded frame bitstream length
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE mp4_video_enc_push_tableinfo_to_buffer(kal_uint32 time_stamp, kal_uint32 length);

#ifdef __L1_STANDALONE__
   /**
    * This function send the ilm to notify med task "Encode process is done".
    * @param  enc_struct VIDEO_ENC_STRUCT structure.
    * @return None
    *
    */
   extern void video_enc_done_send_ilm(VIDEO_ENC_STRUCT *enc_struct);
#endif   /*__L1_STANDALONE__*/

/**
 * This function send the ilm to notify med task to read out the bistream buffer.
 * @param  enc_struct VIDEO_ENC_STRUCT structure.
 * @return None
 *
 */
extern void video_enc_buffer_send_ilm(VIDEO_ENC_STRUCT *enc_struct);

/**
 * This function will open the video encode process.
 * When calling "video_encode_setup" function, this function is also called.
 *
 * @param  frame_width frame width
 * @param  frame_height frame height.
 * @param  frame_count frame initial count! always is 0, execpt video editor scenario.
 *
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_open(kal_uint32 frame_width,
                                 kal_uint32 frame_height,
                                 kal_uint32 frame_count,
                                 kal_bool   resume);

/**
 * This function will close the video encode process.
 *
 * @return None
 *
 */
extern void video_enc_close(void);

/**
 * This function will initialize the VIDEO_ENC_STRUCT structure as default value.
 * When calling "video_encode_setup" function, this function is also called.
 *
 * @param  short_header short header mode(H.263) or not(mpeg4).
 * @param  bit_rate average bitrate
 * @param  frame_rate average frame rate
 * @param  frame_width the width of frame
 * @param  frame_height the height of frame
 * @param  resume_enable  resume feature or not.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_init(MP4ENC_SETUP_STRUCT *setup_input, kal_bool resume_enable);

/**
 * This function will initialize the encode process for normal case.
 *
 * @param  short_header short header mode(H.263) or not(mpeg4).
 * @param  bit_rate average bitrate
 * @param  frame_rate average frame rate
 * @param  frame_width the width of frame
 * @param  frame_height the height of frame
 * @param  skip_frame_count the skip frame count for recode.
 * @param  call_back video encode callback function which is used when driver want to notify med its status.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_encode_setup(MP4ENC_SETUP_STRUCT *setup_input);

/**
 * This function will initialize the encode process for resume function.
 *
 * @param  short_header short header mode(H.263) or not(mpeg4).
 * @param  bit_rate average bitrate
 * @param  frame_rate average frame rate
 * @param  frame_width the width of frame
 * @param  frame_height the height of frame
 * @param  skip_frame_count the skip frame count for recode.
 * @param  call_back video encode callback function which is used when driver want to notify med its status.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_encode_resume_setup(MP4ENC_SETUP_STRUCT *setup_input);

/**
 * This function will notify driver the audio format.
 *
 * @param  audio_format audio format based on Media_Format
 * @return None.
 *
 */
extern void video_enc_set_audioformat(Media_Format audio_format);

extern void video_enc_resource_init(kal_uint16 frame_width, kal_uint16 frame_height);

/**
 * This function will initialize the VIDEO_ENC_STRUCT structure as default value.
 * When calling "video_enc_init" function, this function is also called.
 *
 * @param  is_short_header_mode short header mode(H.263) or not(mpeg4).
 * @param  work_memory  the working memeory for mpeg4 encode HW engine.
 * @param  frame_buffer_memory   frame buffer memory. (V2 should set this memory. Other chip can set NULL)
 * @param  bitrate average bitrate
 * @param  im bistream information structure.
 * @param  frame_width the width of frame
 * @param  frame_height the height of frame
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_initialize(MP4ENC_SETUP_STRUCT *setup_inpt, m4v_enc_im *im);
/**
 * This function will initialize the VIDEO_ENC_STRUCT structure as default value. Only for resume function.
 * When calling "video_enc_init" function, this function is also called.
 *
 * @param  is_short_header_mode short header mode(H.263) or not(mpeg4).
 * @param  work_memory  the working memeory for mpeg4 encode HW engine.
 * @param  frame_buffer_memory   frame buffer memory. (V2 should set this memory. Other chip can set NULL)
 * @param  bitrate average bitrate
 * @param  im bistream information structure.
 * @param  frame_width the width of frame
 * @param  frame_height the height of frame
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_resume_init(MP4ENC_SETUP_STRUCT *setup_inpt, m4v_enc_im *im);

/**
 * This function will switch the encode bitstream buffer to available(empty) buffer.(Driver internal use)
 *
 * @param  enc_struct VIDEO_ENC_STRUCT structure.
 * @return KAL_TURE: swicth successul.
 *         KAL_FALSE: No available buffer now.
 *
 */
extern kal_bool video_enc_switch_buffer(VIDEO_ENC_STRUCT *enc_struct);

/**
 * This function will obtain the status of encode bitstream buffer. (Driver internal use)
 *
 * @param  enc_struct VIDEO_ENC_STRUCT structure.
 * @return KAL_TURE: at least one available buffer can be used.
 *         KAL_FALSE: No available buffer now.
 *
 */
extern kal_bool video_enc_get_buffer_status(VIDEO_ENC_STRUCT *enc_struct);

/**
 * This function will save the driver necessary information when resume.
 *
 * @return None
 *
 */
extern void video_encode_pause(void);

/**
 * This function will stop recoding process, but HW is not stop.
 *
 * @return None
 *
 */
extern void video_enc_stop_record(void);

/**
 * This function will evaluate the size of the video header file.
 *
 * @param  short_header_mode short header mode(H.263) or not(mpeg4).
 * @return the size of the video header file.
 *
 */
extern kal_uint32 video_evaluate_real_meta_file_size(kal_bool short_header_mode);

/**
 * This function will obtain the current time when encoding.
 *
 * @return the current time(Unit:ms)
 *
 */
extern kal_uint64 video_enc_get_current_time(void);

/**
 * This function will store the necessary information when pause.
 *
 * @return NULL
 *
 */
extern void video_encode_drv_pause(void);

/**
 * This function will restore the pause information.
 *
 * @return NULL
 *
 */
extern void video_encode_drv_pause_info_restore(void);

/**
 * This function will obtain the previous time stamp (when paused).
 *
 * @return paused time stamp
 *
 */
extern kal_uint32 video_enc_get_prev_time_stamp(void);

extern RC_STRUCT* video_enc_get_rc_data(void);
extern void video_enc_set_rc_data(RC_STRUCT *p_rc_data);
extern void video_enc_fr_evalutaion_init(kal_int32 frame_rate);
extern void video_enc_fr_evalutaion(kal_int32 frame_rate);

#endif   /* __VIDEO_ENC_GLB_H__ */


