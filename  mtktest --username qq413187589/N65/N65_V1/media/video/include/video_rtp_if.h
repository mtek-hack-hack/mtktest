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
 *   video_rtp_if.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   RTP transfer layer interfeace
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VIDEO_RTP_IF_H
#define VIDEO_RTP_IF_H

#ifdef STREAM_SUPPORT

//////////////////////////////////////////////////////////////////
//     Interface for application 
/////////////////////////////////////////////////////////////////

/* supported rtp types */
typedef enum
{
    VIDEO_DEC_STREAM_NONE,
    VIDEO_DEC_STREAM_MPEG4,
    VIDEO_DEC_STREAM_H263,
    VIDEO_DEC_STREAM_H264,
    VIDEO_DEC_STREAM_VC1
}VIDEO_DEC_STREAM_TYPE;

//////////////////////////////////////////////////////////////////
//     Interface for different parser
/////////////////////////////////////////////////////////////////

#define VIDEO_RTP_MAX_PARSE_ITEM  20
#define VIDEO_RTP_HEADER_SIZE  12
#define VIDEO_RTP_HEADER_CSRC_SIZE 4

/* parsing information */
typedef struct
{
    kal_uint32 buffer_addr[VIDEO_RTP_MAX_PARSE_ITEM];
    kal_uint32 buffer_size[VIDEO_RTP_MAX_PARSE_ITEM];
    kal_uint32 time[VIDEO_RTP_MAX_PARSE_ITEM];
    kal_uint32 don_number[VIDEO_RTP_MAX_PARSE_ITEM];
    kal_bool b_add_length[VIDEO_RTP_MAX_PARSE_ITEM];
}VIDEO_RTP_PARSE_INFO;

/* RTP parser driver */
typedef struct
{
	void (* rst_time)(void);
	kal_uint32 (* get_timescale)(void);
	void (* set_timescale)(kal_uint32 time_scale);
	void (* set_mode)(kal_uint32 mode);
	MEDIA_STATUS_CODE (* parse_config)(kal_uint8 *data, kal_uint32 size);
	MEDIA_STATUS_CODE (* parse_first_frame)(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_frame_size, kal_uint32 *p_rtp_header_size);
	MEDIA_STATUS_CODE (* parse_time_size)(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info);
}VIDEO_RTP_Driver;

/* Mapping between codec type and driver*/
typedef struct  
{
    VIDEO_DEC_STREAM_TYPE 	type;
    VIDEO_RTP_Driver           *p_Driver;
}VIDEO_RTP_Device;

extern VIDEO_RTP_Driver* video_rtp_get_driver(void);

/* different codec types */
typedef enum
{
    video_rtp_codec_mp4 = 1,
    video_rtp_codec_h263 = 2,
    video_rtp_codec_h264 = 4,
    video_rtp_codec_vc1 = 8
} video_rtp_codec_type; 

/* RTP status */
typedef enum
{
    VIDEO_RTP_OK=0,
    VIDEO_RTP_UNDERFLOW,
    VIDEO_RTP_OVERFLOW,
    VIDEO_RTP_PACKET_LOST,
    VIDEO_RTP_PACKET_ERROR,
    VIDEO_RTP_ERROR,
    VIDEO_RTP_RESOLUTION_ERR
} VIDEO_RTP_STATUS; 

/* RTP callback events */
typedef enum
{
    VIDEO_RTP_EVENT_OVERFLOW=10,
    VIDEO_RTP_EVENT_UNDERFLOW,
    VIDEO_RTP_EVENT_PACKET_LOSS,
    VIDEO_RTP_EVENT_RESOLUTION_ERR
} VIDEO_RTP_EVENT;

/* Different decoder capability */
typedef struct
{
    kal_uint32  timescale;
    kal_uint8    profile_level;
    kal_uint8   *pconfig;			// store VOS 
}video_rtp_mp4_cap;

typedef struct
{
    kal_uint32  timescale;
    kal_uint8    profile;
    kal_uint8    level;
}video_rtp_h263_cap;

typedef struct
{
    kal_uint32  timescale;	// Sampling rate 

    // Declaring actual configuration or properties for receiving.
    kal_uint32   profile_level_id;		// Three bytes specify (1) profile_idc, (2) profile-iop (constraint_set0_flag, constraint_set1_flag, constraint_set2_flag, 5 zero bits), (3) level_idc. Ex: 42E015 denote Baseline profile, and 15 the level 2.1.
    kal_uint8    packetization_mode;	// 0: single NAL mode. 1: Non-interleaved mode. 2: Interleaved mode. Default 0 if not present.

    // Declaring actual properties of the stream to be sent.
    kal_uint32    sprop_deint_buf_req;		// The deinterleaved buffer size is at least the value of sprop_deint_buf_req in terms of bytes. Range: 0 ~ 2^32-1.
    kal_uint16    sprop_interleaving_depth;	// The de-interleaved buffer size is at least (sprop_interleaving_depth +1) in terms of VCL NAL units. Range: 0~32767.
    kal_uint8     *sprop_parameter_sets;    	// Initial parameter sets that attach with sprop-parameter-sets MIME parameter.
    kal_uint16    sprop_max_don_diff;		// Used to trigger which NAL units can be passed to the decoder. Range: 0 ~ 32767
    kal_uint32    sprop_init_buf_time;		// The initial buffering time that a receiver MUST buffer before starting decoding.

    // Declaring receiver implementation capabilities.
    kal_uint32	max_mbps; 		// Maximum macroblock processing rate. Ex: 176x144 size, 15fps => (176/16)*(144/16)*15 = 1485
    kal_uint16	max_fs;			// Maximum frame size in units of macroblocks. Ex: 176x144 => (176/16)*(144/16) =  99
    kal_uint16	max_cpb;		// Maximum coded picture buffer size in units of 1000 bits
    kal_uint16	max_dpb;		// Maximum decoded picture buffer size in units of 1024 bytes
    kal_uint16	max_br;			// Maximum video bit rate in units of 1000 bits per second for VCL and in units of 1200 bits for NAL
    kal_uint8	redundant_pic_cap;	// Denote the receiver's ability to handle redundant coded pictures. 0/1: not capable/capable. Default is 0 if not present.
    kal_uint32  deint_buf_cap;		// Maximal de-interleaved buffer space in units of bytes. Range: 0 ~ 2^32-1. Default 0 if no present.
    kal_uint32	max_rcmd_nalu_size;	// Denote the largest NALU size in byets that the receiver can handle efficiently. Range: 0 ~ 2^32-1

    // Declaring how Offer/Answer negotiation shall be performed
    kal_uint8	parameter_add;    	// Allowed to add parameter sets in sprop-parameter-sets MIME parameter? 0/1: Not allowed/Allowed. Default 1 if not present.
} video_rtp_h264_cap;

/* MPEG-4 payload related */
#define MPEG4_RTP_VOP_HEADER_SIZE 4
 
typedef struct
{
    kal_uint32 time_scale;                            /* time information set by application*/
    kal_uint32 time_offset;                           
    kal_uint16 time_increment_resolution;    /* time resolution in vop header */
    kal_uint16 time_increment_length;
}MPEG4_RTP_CTRL_INFO;

/* H.264 related */
#define H264_RTP_HEADER_SIZE 2
#define H264_RTP_AGGREGATE_LENGTH_SIZE 2

typedef enum
{
	H264_RTP_SINGLE_NALU_MODE = 0,
	H264_RTP_NON_INTERLEAVED_MODE = 1,
	H264_RTP_INTERLEAVED_MODE = 2
}H264_RTP_PACKETIZATION_MODE;

typedef struct
{
    H264_RTP_PACKETIZATION_MODE packetization_mode;
    kal_uint32 time_scale;    /* time information set by application*/
    kal_uint32 time_offset;                            
}H264_RTP_CTRL_INFO;

/* H.263 related */
#define H263_RTP_HEADER_SIZE 2
#define H263_RTP_VRC_HEADER_SIZE 1
 
typedef struct
{
    kal_uint32 time_scale;      /* time information set by application*/
    kal_uint32 time_offset;         
}H263_RTP_CTRL_INFO;

/* RTP callback */
typedef void (*video_rtp_callback)(VIDEO_RTP_EVENT event);

typedef struct Video_Rtp_Handle_Struct_t Video_Rtp_Handle_Struct;


/* RTP handle structure */
struct Video_Rtp_Handle_Struct_t
{
   video_rtp_codec_type    (*GetAvailableCodecs)( void );
   VIDEO_RTP_STATUS      (*SetActiveCodec)(Video_Rtp_Handle_Struct *p_handle, video_rtp_codec_type type);
   VIDEO_RTP_STATUS      (*GetCapability)(Video_Rtp_Handle_Struct *p_handle, void *p_codec_cap);
   VIDEO_RTP_STATUS      (*Config)(Video_Rtp_Handle_Struct *p_handle, void *p_codec_cap, rtp_audio_codec_type audio_type, kal_uint32 uSampleRate, void (*video_rtp_callback)(VIDEO_RTP_EVENT event));
   VIDEO_RTP_STATUS      (*ImagePathOpen)(Video_Rtp_Handle_Struct *p_handle, MP4DEC_IMGPATH_STRUCT *p_data_input );
   VIDEO_RTP_STATUS      (*ImagePathClose)(Video_Rtp_Handle_Struct *p_handle);
   VIDEO_RTP_STATUS      (*GetImageResolution)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_width, kal_uint32 *p_height,void (*video_rtp_callback)(VIDEO_RTP_EVENT event));
   VIDEO_RTP_STATUS      (*Start)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 start_time,void (*video_rtp_callback)(VIDEO_RTP_EVENT event));
   VIDEO_RTP_STATUS      (*Stop) (Video_Rtp_Handle_Struct *p_handle);
   VIDEO_RTP_STATUS      (*Close)(Video_Rtp_Handle_Struct *p_handle);
   VIDEO_RTP_STATUS      (*PutPacket) (Video_Rtp_Handle_Struct *p_handle, kal_uint8 *p_buffer, kal_uint32 buffer_size);
   VIDEO_RTP_STATUS      (*GetPlayTime)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_current_time);
   VIDEO_RTP_STATUS      (*GetBufferDuration)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_buffer_duration);
   VIDEO_RTP_STATUS      (*GetBufferStatus)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_percentge_used, kal_uint32 *p_free_space);
   VIDEO_RTP_STATUS      (*SwitchScreen_VideoStop)(Video_Rtp_Handle_Struct *p_handle);
   VIDEO_RTP_STATUS      (*SwitchScreen_VideoStart)(Video_Rtp_Handle_Struct *p_handle, MP4DEC_IMGPATH_STRUCT *p_data_input);
   VIDEO_RTP_STATUS      (*CheckPkts)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 start_seq, kal_uint32 diff_thre);

   // internal use
   void                            (*callback)(VIDEO_RTP_EVENT event);
   video_rtp_mp4_cap       *p_mp4_cap;
   video_rtp_h263_cap      *p_h263_cap;
   video_rtp_h264_cap      *p_h264_cap;
   kal_bool                      g_b_video_stream_config;
   kal_uint32                   g_stream_timebase;
   VIDEO_DEC_STREAM_TYPE g_stream_type;
   kal_bool                      is_SwitchScreen_VideoStop;
   H264_RTP_PACKETIZATION_MODE g_stream_packetization_mode;
};

extern void video_rtp_set_format(VIDEO_DEC_STREAM_TYPE type);
extern VIDEO_DEC_STREAM_TYPE video_rtp_get_format(void);
extern DECODE_TYPE video_rtp_get_decode_format(void);
extern void video_rtp_set_timescale(kal_uint32 time_scale);
extern kal_uint32 video_rtp_get_timescale(void);
extern void video_rtp_set_mode(kal_uint32 mode);
extern MEDIA_STATUS_CODE video_rtp_config(kal_uint8* p_data);
extern void video_rtp_init(void);
extern MEDIA_STATUS_CODE video_rtp_put_frame(kal_uint8* p_data, kal_uint32 size);
extern VIDEO_RTP_Driver MPEG4_RTP_Driver;
extern VIDEO_RTP_Driver H264_RTP_Driver;
extern VIDEO_RTP_Driver H263_RTP_Driver;

Video_Rtp_Handle_Struct* Video_Rtp_Get_Handle(void);

#endif /* STREAM_SUPPORT */
#endif /*VIDEO_RTP_IF_H*/
 
