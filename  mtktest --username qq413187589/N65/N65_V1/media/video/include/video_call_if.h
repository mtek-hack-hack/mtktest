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
 *   video_call_if.h
 *
 * Project:
 * --------
 *		MTK
 *
 * Description:
 * ------------
 *   This file defines the video call interface
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
 * removed!
 ****************************************************************************/
#ifndef VIDEO_CALL_IF_H
#define VIDEO_CALL_IF_H

/****************** external structures ************************/
typedef enum
{
    VIDEO_CALL_CODEC_NONE,
    VIDEO_CALL_CODEC_MPEG4 = 1,
    VIDEO_CALL_CODEC_H263 = 2,
    VIDEO_CALL_CODEC_H264 = 4,	
    VIDEO_CALL_CODEC_VC1 = 8
}VIDEO_CALL_CODEC_TYPE;

typedef enum
{
	VIDEO_CALL_STATUS_OK = 0,
	VIDEO_CALL_STATUS_CODEC_UNSUPPORT,
	VIDEO_CALL_STATUS_NOT_CODED,
	VIDEO_CALL_STATUS_BUFFER_UNAVIL,
	VIDEO_CALL_STATUS_ERROR,
	VIDEO_CALL_STATUS_ENCODER_CLOSED,
	VIDEO_CALL_STATUS_MAX
}VIDEO_CALL_STATUS;

typedef enum
{
    VIDEO_CALL_EVENT_DEC_DONE,	
    VIDEO_CALL_EVENT_DEC_ERROR,
    VIDEO_CALL_EVENT_ENC_DONE,
    VIDEO_CALL_EVENT_ENC_ERROR
}VIDEO_CALL_EVENT;

typedef enum
{
    VIDEO_CALL_QUALITY_LOW = 2,
    VIDEO_CALL_QUALITY_NORMAL,
    VIDEO_CALL_QUALITY_HIGH,
    VIDEO_CALL_QUALITY_FINE,
    VIDEO_CALL_MAX_QUALITY_LEVEL
}VIDEO_CALL_QUALITY;

typedef void (*video_call_callback)(VIDEO_CALL_EVENT event);
typedef void (*video_call_dma_callback)(kal_uint32 encode_yuv);

typedef struct
{
    video_call_callback  callback; 
    kal_uint8 *p_ext_mem_addr;
    kal_uint32 ext_mem_size;
    kal_uint8 *p_int_mem_addr;
    kal_uint32 int_mem_size;
}Video_Call_Dec_Info;

typedef struct
{
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 bitrate;
    kal_uint32 yuv_skip_count;
    VIDEO_CALL_QUALITY quality_mode;
    Media_Format audio_format;
    kal_uint32 max_packet_size;   
    video_call_callback  callback;  
    kal_uint8 *p_ext_mem_addr;
    kal_uint32 ext_mem_size;
    kal_uint8 *p_int_mem_addr;
    kal_uint32 int_mem_size;

    // advance feature
    kal_bool b_yuv_source;
    kal_uint32 yuv_duration;
    kal_uint32 yuv_addr;
}Video_Call_Enc_Info;


typedef struct
{
    kal_bool b_new_session;
    kal_bool b_new_frame;	
    kal_bool b_header_not_complete;
    kal_bool b_sync_frame;	
    kal_uint32 width;	 
    kal_uint32 height;
    kal_uint32 real_width;	 
    kal_uint32 real_height;
    kal_uint32 prev_frame_duration;
    kal_uint32 length;	
}Video_Call_Parse_Info;
	
/*************** internal structures *******************/

#define VIDEO_CALL_ENC_META_BUFFER_SIZE  (256*8)
#define VIDEO_CALL_ENC_QUEUE_BUFFER_SIZE 8192
//#define VIDEO_CALL_ENC_DATA_BUFFER_SIZE  (ENC_MAX_FRAME_WIDTH*ENC_MAX_FRAME_HEIGHT*7)
#define VIDEO_CALL_ENC_DATA_BUFFER_SIZE  (ENC_MAX_FRAME_WIDTH*ENC_MAX_FRAME_HEIGHT*2 - VIDEO_CALL_ENC_QUEUE_BUFFER_SIZE)
#define VIDEO_CALL_ENC_DATA_RESERVE_SIZE  30

//#define VIDEO_CALL_ENC_PKT_BUFFER_SIZE	(16*16)  // one macroblock is 16*16*1.5

typedef void (*video_call_isr)(void);
typedef enum
{
    VIDEO_CALL_PARAM_ENC_QUANTIZER,
    VIDEO_CALL_PARAM_ENC_VOP_TYPE,
    VIDEO_CALL_PARAM_MAX
}VIDEO_CALL_PARAM_TYPE;

typedef enum
{
    VIDEO_CALL_CODEC_STATE_NONE,	
    VIDEO_CALL_CODEC_STATE_DEC,	
    VIDEO_CALL_CODEC_STATE_ENC
}VIDEO_CALL_CODEC_STATE;

typedef enum
{
    VIDEO_CALL_CODEC_STATUS_CLOSE,
    VIDEO_CALL_CODEC_STATUS_INIT,		
    VIDEO_CALL_CODEC_STATUS_RUN,
    VIDEO_CALL_CODEC_STATUS_STOP
}VIDEO_CALL_CODEC_STATUS;

typedef enum
{
    VIDEO_CALL_DEC_PARSE_STATUS_OK,
    VIDEO_CALL_DEC_PARSE_STATUS_NOT_CODED,
    VIDEO_CALL_DEC_PARSE_STATUS_ERROR
}VIDEO_CALL_DEC_PARSE_STATUS;

typedef struct 
{
    kal_uint8    *p_buffer;
    kal_uint32   buffer_length;
    kal_uint32   buffer_limit;
    kal_uint32   read;
    kal_uint32   write;
}Video_Call_Buffer_Struct;

typedef struct
{
    BUFFER_INFO                 meta_buffer_info;
    kal_uint32                     meta_buffer_addr;
    Video_Call_Buffer_Struct  data_buffer_info;
    kal_uint32                     data_buffer_addr;		
}Video_Call_Buffer_Info;

typedef struct
{
    video_call_callback callback;
    video_call_isr         lisr;	
#ifdef MP4_MOVE_LISR_TO_HISR 
    video_call_isr         first_hisr;
#endif
    video_call_isr         hisr;

    kal_uint8 *p_ext_mem_addr;
    kal_uint32 ext_mem_size;
    kal_uint8 *p_int_mem_addr;
    kal_uint32 int_mem_size;

    kal_uint8 *p_vos;	
    kal_uint32 vos_length;
}VideoCall_Codec_Dec_Input;

typedef struct
{
    video_call_callback callback;
    video_call_isr         lisr;	
#ifdef MP4_MOVE_LISR_TO_HISR 
    video_call_isr         first_hisr;
    video_call_isr         dma_hisr;
#endif    
    video_call_isr         hisr;

    kal_uint8 *p_ext_mem_addr;
    kal_uint32 ext_mem_size;
    kal_uint8 *p_int_mem_addr;
    kal_uint32 int_mem_size;
    
    kal_uint32 width;
    kal_uint32 height;		
    //kal_uint32 skip_frame_count;	
    VIDEO_CALL_QUALITY quality_mode;
    kal_uint32 bitrate;	
    kal_uint32 max_pkt_size;	
    Media_Format audio_format;	

    // advance feature
    kal_bool b_yuv_source;
    kal_uint32 yuv_duration;	
}VideoCall_Codec_Enc_Input;

typedef struct
{
    /* for parse functions (VT task) */
    void (*dec_parse_open)(void);
    kal_bool (*dec_parse_packet)(kal_uint8 *p_data, kal_uint32 length, Video_Call_Parse_Info *p_info);

    /* for decode functions (MED task) */
    void (*dec_open)(void);
    kal_bool (*dec_init)(VideoCall_Codec_Dec_Input *p_input);
    VIDEO_CALL_DEC_PARSE_STATUS (*dec_parse_info)(kal_uint8 *p_data, kal_uint32 length, kal_uint8 *p_dec_addr);	
    void (*dec_start)();
    kal_bool (*dec_success)(void);	
    void (*dec_stop)(void);
    void (*dec_close)(void);		
    void (*dec_mask_intr)(void);	

    /* for encode functions (MED task) */
    void (*enc_open)(void);
    void (*enc_init)(VideoCall_Codec_Enc_Input *p_input);	
    void (*enc_config_start)(void);		
    void (*enc_parse_info)(kal_uint32 yuv_data);	
    void (*enc_start)(kal_uint32 start_addr, kal_uint32 size);	
    kal_bool (*enc_complete)(kal_uint32 *p_size);
    void (*enc_resume)(kal_uint32 start_addr, kal_uint32 size);	
    void (*enc_update_info)(void);
    void (*enc_update_I)(void);
    void (*enc_drop_prev_frame)(void);	
    kal_bool (*enc_find_pkt_boundary)(kal_uint8 *p_addr, kal_uint32 length, kal_uint32 *p_index);
    kal_uint32 (*enc_max_pkt_size)(void);	
    kal_uint8* (*enc_get_header)(kal_uint32 *p_size);	
    void (*enc_stop)(void);	
    kal_bool (*enc_check_running)(void);	
    void (*enc_close)(void);	
    void (*enc_mask_intr)(void);
    void (*get_param)(VIDEO_CALL_PARAM_TYPE type, kal_uint32 *value);
    void (*set_param)(VIDEO_CALL_PARAM_TYPE type, kal_uint32 value);
}VideoCall_Codec_Driver;

typedef struct
{
    VIDEO_CALL_CODEC_TYPE   dec_parse_codec_type;	
    VIDEO_CALL_CODEC_TYPE   dec_codec_type;	
    VIDEO_CALL_CODEC_TYPE   enc_codec_type;	
    VideoCall_Codec_Driver  *p_dec_parse_driver;
    VideoCall_Codec_Driver  *p_dec_driver;
    VideoCall_Codec_Driver  *p_enc_driver;
    
    VIDEO_CALL_CODEC_STATE  codec_status;
    VIDEO_CALL_CODEC_STATE  wait_status;	

    VIDEO_CALL_CODEC_STATUS enc_status;	
    kal_bool b_drop_enc_frame;
    kal_uint32 enc_in_total_frame;
    kal_uint32 enc_out_total_frame;
    kal_uint32 enc_lost_frame;	
    kal_bool b_enc_first_pkt;	
	
    kal_uint32 total_enc_length;
    kal_uint8 *p_pkt_buffer;	
    kal_uint32 enc_pkt_buf_length;
    kal_uint32 enc_left_frame_length;	
    video_call_callback enc_callback;

    kal_bool b_enc_yuv_source;
    kal_uint32 enc_yuv_duration;
    kal_uint32 enc_yuv_addr;	
    kal_uint8 enc_gpt_handle;	

    VIDEO_CALL_CODEC_STATUS dec_status;
    video_call_callback dec_callback;
    kal_bool dec_result;		
    kal_uint32 yuv_frame_cnt;
    kal_uint8 drop_frame_cnt;
    kal_uint8 b_rc_drop_frame;
    kal_uint8 drop_more_frame;
    kal_uint32 encoded_I_frame_cnt;
    kal_uint32 encoded_P_frame_cnt;
    kal_uint32 frame_start_time;
    kal_uint32 elapsed_time_ms;
    kal_uint32 big_encode_q_cnt;
}VideoCall_Codec_Status;


/* Mapping between codec type and driver*/
typedef struct  
{
    VIDEO_CALL_CODEC_TYPE   type;
    VideoCall_Codec_Driver  *p_driver;
}Video_Call_Device;

extern VideoCall_Codec_Status g_videocall_status;
extern VideoCall_Codec_Driver g_videocall_mp4_driver;
extern VideoCall_Codec_Driver g_videocall_h263_driver;

/* video_call_api.c */
extern VIDEO_CALL_CODEC_TYPE VideoCall_GetAvailableCodecs(void);
extern VIDEO_CALL_STATUS VideoCall_GetCap(void *p_codec_cap);
extern VIDEO_CALL_STATUS VideoCall_SetDecParseCodec(VIDEO_CALL_CODEC_TYPE type);
extern VIDEO_CALL_STATUS VideoCall_ParsePacket(kal_uint8 *p_data, kal_uint32 length, Video_Call_Parse_Info *p_info);
extern VIDEO_CALL_STATUS VideoCall_SetDecActiveCodec(VIDEO_CALL_CODEC_TYPE type);
extern VIDEO_CALL_STATUS VideoCall_CfgDec(Video_Call_Dec_Info *p_input);
//extern VIDEO_CALL_STATUS VideoCall_GetDecFrameAddr(kal_uint8 **p_frame_addr, kal_uint32 *p_length);
extern VIDEO_CALL_STATUS VideoCall_CloseDec(void);
extern VIDEO_CALL_STATUS VideoCall_StartDec(kal_uint8* p_frame_addr, kal_uint32 frame_length, kal_uint8 *p_dec_addr);
extern VIDEO_CALL_STATUS VideoCall_StopDec(void);
extern VIDEO_CALL_STATUS VideoCall_SetEncActiveCodec(VIDEO_CALL_CODEC_TYPE type);
extern VIDEO_CALL_STATUS VideoCall_CfgEnc(Video_Call_Enc_Info *p_input);
extern VIDEO_CALL_STATUS VideoCall_StartEnc(void);
extern VIDEO_CALL_STATUS VideoCall_Enc_UpdateI(void);
extern kal_bool VideoCall_Check_Enc_Start(void);
extern VIDEO_CALL_STATUS VideoCall_StopEnc(void);
extern VIDEO_CALL_STATUS VideoCall_CloseEnc(void);
//extern VIDEO_CALL_STATUS VideoCall_GetNextPacket(kal_uint8 *buf_addr, kal_uint32 buf_size, kal_uint32 *p_size);
extern VIDEO_CALL_STATUS VideoCall_GetNextPacket(kal_uint8 *buf_addr, kal_uint32 buf_size, kal_uint32 *p_size, kal_uint8 *ret_enum);
extern kal_uint32 VideoCall_GetMaxPktSize(void);

/* video_call_dec_isr.c */
extern void VideoCall_Dec_Lisr(void);
#ifdef MP4_MOVE_LISR_TO_HISR 
extern void VideoCall_Dec_First_HISR(void);
#endif

extern void VideoCall_Dec_Hisr(void);

/* video_call_enc_isr.c */
extern void VideoCall_EncDMA_Lisr(kal_uint32 encode_yuv);
#ifdef MP4_MOVE_LISR_TO_HISR 
extern void VideoCall_EncDMA_First_HISR(void);
#endif
extern void VideoCall_Enc_Lisr(void);
#ifdef MP4_MOVE_LISR_TO_HISR 
extern void VideoCall_Enc_First_HISR(void);
#endif
extern void VideoCall_Enc_Hisr(void);

/* video_call_buffer.c */
extern void VideoCall_Enc_Buffer_Init(kal_uint8 *p_ext_mem_addr, kal_uint32 ext_mem_size, kal_uint32 *p_mem_size);
extern void VideoCall_Enc_Buffer_Reset(void);
extern kal_bool VideoCall_Enc_Write_Meta(kal_uint32 length, kal_uint32 time, kal_uint32 predition_type, kal_uint32 quantizer);
extern kal_bool VideoCall_Enc_Read_Meta(kal_uint32 *p_length, kal_uint32 *p_time, kal_uint32 *p_type, kal_uint32 *p_quantizer);
extern kal_uint32 VideoCall_Enc_Get_Data_Roomleft(void);
extern kal_uint32 VideoCall_Enc_Get_Data_Available(void);
extern kal_uint32 VideoCall_Enc_Get_Data_Addr(kal_uint32 *p_size);
extern kal_bool VideoCall_Enc_Update_Data_Offset(kal_uint32 offset);
extern kal_bool VideoCall_Enc_Drawback_Data_Offset(kal_uint32 offset);
extern kal_bool VideoCall_Enc_Read_Data(kal_uint8 *p_addr, kal_uint32 length);


/*************** mmtf structures *******************/

//////////encode param
#define MMTK_VIDEOCALL_ENC_MIN_BUFF_SIZE  1024
//#define MMTK_VIDEOCALL_ENC_MIN_BUFF_SIZE  2048
#define MMTK_VIDEOCALL_ENC_BUFFER_SIZE  1024*10
#define MMTK_VIDEOCALL_ENC_BUFFER_NUMBER 3

typedef struct
{
   kal_uint32 read_index;
   kal_uint32 write_index;
   kal_uint32 write_buff_offset[MMTK_VIDEOCALL_ENC_BUFFER_NUMBER];	
   kal_bool b_buff_full[MMTK_VIDEOCALL_ENC_BUFFER_NUMBER];
}MMTK_Videocall_Enc_Buffer_Struct;

extern kal_uint8 mmtk_videocall_enc_buffer[MMTK_VIDEOCALL_ENC_BUFFER_NUMBER][MMTK_VIDEOCALL_ENC_BUFFER_SIZE];
extern MMTK_Videocall_Enc_Buffer_Struct mmtk_videocall_buff;
extern STFSAL MMTF_VIDEOCALL_ENC_FILE;


///////////decode param
#define MMTK_VIDEOCALL_DEC_MAX_FILE_SIZE  0x40000
#define MMTK_VIDEOCALL_DEC_MAX_PKT_SIZE  (1024 + 1024)
extern kal_uint8 mmtf_videocall_dec_stream[MMTK_VIDEOCALL_DEC_MAX_PKT_SIZE];
extern kal_uint32 mmtk_videocall_dec_stream_length;
extern kal_uint32 mmtk_videocall_dec_stream_offset;
extern kal_uint8 mmtf_videocall_dec_frame[176*144*3/2];
extern kal_uint32 mmtk_videocall_dec_frame_length;
extern kal_uint8 mmtf_videocall_dec_yuv[176*144*3/2];
extern STFSAL MMTF_VIDEOCALL_DEC_FILE;
extern STFSAL MMTF_VIDEOCALL_DEC_YUV_FILE;

#define VIDEO_CALL_ENC_UNIT_TEST
#define VIDEO_CALL_DEC_UNIT_TEST

#define _VIDEOCALL_SUPPORT_PHASE2_

#define Video_Call_Frame_Rate 15
#endif /*VIDEO_CALL_IF_H*/
