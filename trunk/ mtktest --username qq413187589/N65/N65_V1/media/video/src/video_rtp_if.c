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
 *   video_rtp_if.c
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef MP4_CODEC
/*==== INCLUDES =========*/
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"

/* global includes */
#include "l1audio.h"

#include "rtc_sw.h"
#include "lcd_if.h"

#include "FSAL.h"
#include "MP4_Parser.h"
#include "video_file_creator.h"
#include "drv_comm.h"
#include "visual_comm.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#include "img_comm.h"

/* local includes */
#include "med_status.h"

#include "video_hw.h"

#ifdef STREAM_SUPPORT
#include "video_rtp_reorder_buffer.h"
#include "video_rtp_h264_interleaved_buffer.h"
#include "video_dec_buffer_manager.h"

video_rtp_h263_cap platform_h263_cap = {90000,0,10};	// baseline profile level 10
video_rtp_mp4_cap platform_mp4_cap = {90000,3,NULL};	// 3: simple profile level 3 from Table G-1, 14496-2
video_rtp_h264_cap platform_h264_cap = {90000,H264_RTP_INTERLEAVED_MODE,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

extern Media_Format MP4_Audio_Type_To_Media_Format(MP4_Audio_Type eAudioType);
extern MP4_Audio_Type MP4_GetAudioType(STMp4Parser *pstMp4Parser);
extern kal_uint8 MP4_Audio_GetFreqIndex(STMp4Parser *pstMp4Parser);
extern void video_dec_set_av_timebase(VIDEO_DEC_AV_TYPE av_type, kal_uint64 video_timebase, kal_uint64 audio_timebase, kal_uint32 audio_playback_delay);
extern kal_uint8 GPTI_GetHandle(kal_uint8 *handle);
extern STMp4Parser stMp4Parser_v;
extern void video_dec_rst_av_timeoffset(void);
extern MEDIA_STATUS_CODE video_dec_stream_play(kal_uint32 * audio_frame_no, void (*video_dec_callback)(kal_uint8 event));
extern kal_uint8  g_video_dec_gpt_refresh_handle;
extern VIDEO_DEC_BUFFER_MGR_STRUCT *g_video_dec_buffer_mgr_ptr;
extern kal_uint32 convertSamplingFreqToIndex(kal_uint32 uSamplingFreq);
extern kal_uint64 video_dec_get_audio_timebase(void);
extern kal_uint64 video_dec_get_video_timebase(void);
extern VIDEO_DEC_AV_TYPE video_dec_get_av_type(void);
extern void mpeg4_dec_frame_buffer_init_value(void);
extern kal_uint32 mpeg4_dec_get_ref_frame_addr(void);
extern void mpeg4_dec_clear_frame_buffer(kal_int32 width, kal_int32 height);
extern MEDIA_STATUS_CODE video_dec_stream_flush_reorder_buffer(void);
typedef void (*video_dec_callback)(kal_uint8 event);
	
static VIDEO_RTP_Device g_video_cur_stream_device;

/* All supported parser */
static VIDEO_RTP_Device g_video_stream_devices[] =
{
    	{VIDEO_DEC_STREAM_MPEG4, &MPEG4_RTP_Driver},
    	{VIDEO_DEC_STREAM_H263, &H263_RTP_Driver},
    	{VIDEO_DEC_STREAM_H264, &H264_RTP_Driver}
};

/* Set active format */
void video_rtp_set_format(VIDEO_DEC_STREAM_TYPE type)
{
    kal_uint32 index;
    kal_uint32 total_device = sizeof(g_video_stream_devices)/sizeof(VIDEO_RTP_Device);

    g_video_cur_stream_device.type = VIDEO_DEC_STREAM_NONE;
    g_video_cur_stream_device.p_Driver = NULL;
    
    for(index = 0; index < total_device; index++)
    {
        if(g_video_stream_devices[index].type == type)
        {
            g_video_cur_stream_device.type = type;
            g_video_cur_stream_device.p_Driver = g_video_stream_devices[index].p_Driver;
            break;
        }
    }
}

/* Get current active format */
VIDEO_DEC_STREAM_TYPE video_rtp_get_format(void)
{
    return g_video_cur_stream_device.type;
}

/* Get current active format */
DECODE_TYPE video_rtp_get_decode_format(void)
{
    DECODE_TYPE decode_type;
    
    if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_MPEG4)
        decode_type = DECODE_TYPE_MPEG4;
    else if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_H263)
        decode_type = DECODE_TYPE_H263;
    else if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_H264)
        decode_type = DECODE_TYPE_H264;
    else if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_VC1)
        decode_type = DECODE_TYPE_VC1;
    else
        decode_type = DECODE_TYPE_UNKNOW;

    return decode_type;
}

/* get current active driver */
VIDEO_RTP_Driver* video_rtp_get_driver(void)
{
    return g_video_cur_stream_device.p_Driver;
}

/* set timescale for current active codec */
void video_rtp_set_timescale(kal_uint32 time_scale)
{
    if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_NONE)
    {
        ASSERT(0);
    }

    g_video_cur_stream_device.p_Driver->set_timescale(time_scale);
}

/* get timescale for current active codec */
kal_uint32 video_rtp_get_timescale(void)
{
    if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_NONE)
    {
        ASSERT(0);
    }

    return g_video_cur_stream_device.p_Driver->get_timescale();
}

/* For H.264, it needs the mode infomration(non-interleaved or interleaved) */
void  video_rtp_set_mode(kal_uint32 mode)
{
    if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_NONE)
    {
        ASSERT(0);
    }
    
    g_video_cur_stream_device.p_Driver->set_mode(mode);
}

/* config to mp4 parse (VOS data)*/
MEDIA_STATUS_CODE video_rtp_config(kal_uint8* p_data) 
{
    kal_uint32 size=0;
    kal_uint8 *pd = p_data;

    while (*pd != '\0') {
		pd++;
		size++;
		if (size > 1000) {	// A suitable threshold for check
			VIDEO_ASSERT(0);
			kal_prompt_trace(MOD_MED, "VIDEO_RTP_CONFIG_ERR: SDP config data no delimiter.\n");
			break;
		}
    }
	
    return video_dec_stream_put_config_to_buffer(p_data, size);
}


/* Initialize RTP parameters, application should call this before start parsing  */
void video_rtp_init(void)
{
    if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_NONE)
    {
        ASSERT(0);
    }

    g_video_cur_stream_device.p_Driver->rst_time();
    video_rtp_reorder_init_buffer();
}

/* Put frames to decoder */
MEDIA_STATUS_CODE video_rtp_put_frame(kal_uint8* p_data, kal_uint32 size)
{
    return video_dec_stream_put_frame_to_buffer(p_data, size);  
}

video_rtp_codec_type video_rtp_GetAvailableCodecs(void)
{
	kal_uint32 i;
	kal_uint32 total_device = sizeof(g_video_stream_devices)/sizeof(VIDEO_RTP_Device);
	video_rtp_codec_type video_rtp_codec;
	
	video_rtp_codec = 0;
	for (i=0; i<total_device; i++) 
	{
		if (g_video_stream_devices[i].type == VIDEO_DEC_STREAM_MPEG4) 
		{
			video_rtp_codec |= video_rtp_codec_mp4;
		} else if (g_video_stream_devices[i].type == VIDEO_DEC_STREAM_H263) {
			video_rtp_codec |= video_rtp_codec_h263;
		} else if (g_video_stream_devices[i].type == VIDEO_DEC_STREAM_H264) {
			video_rtp_codec |= video_rtp_codec_h264;
		} else if (g_video_stream_devices[i].type == VIDEO_DEC_STREAM_VC1) {
			video_rtp_codec |= video_rtp_codec_vc1;
		}
	}
	return video_rtp_codec;
}

VIDEO_RTP_STATUS video_rtp_SetActiveCodec(Video_Rtp_Handle_Struct *p_handle, video_rtp_codec_type type)
{
       if (p_handle == NULL)
	   	ASSERT(0);
	   
	switch (type)
	{
		case video_rtp_codec_mp4:
			p_handle->g_stream_type = VIDEO_DEC_STREAM_MPEG4;
			return VIDEO_RTP_OK;
		case video_rtp_codec_h263:
			p_handle->g_stream_type = VIDEO_DEC_STREAM_H263;
			return VIDEO_RTP_OK;
		case video_rtp_codec_h264:
			p_handle->g_stream_type = VIDEO_DEC_STREAM_H264;
			return VIDEO_RTP_OK;
		case video_rtp_codec_vc1:
			p_handle->g_stream_type = VIDEO_DEC_STREAM_VC1;
			return VIDEO_RTP_OK;
		default:
			return VIDEO_RTP_ERROR;
	}	
}

VIDEO_RTP_STATUS video_rtp_GetCapability(Video_Rtp_Handle_Struct *p_handle, void *p_codec_cap)
{	
    video_rtp_mp4_cap *mp4_cap;
    video_rtp_h263_cap *h263_cap;
    video_rtp_h264_cap *h264_cap;

    if ((p_handle == NULL)||(p_codec_cap==NULL))
	 ASSERT(0);
	
    switch (p_handle->g_stream_type)
    {
    	case (VIDEO_DEC_STREAM_MPEG4):
		mp4_cap = (video_rtp_mp4_cap*)p_codec_cap;
		kal_mem_cpy(mp4_cap,&platform_mp4_cap,sizeof(platform_mp4_cap));
		return VIDEO_RTP_OK;
	case (VIDEO_DEC_STREAM_H263):
		h263_cap = (video_rtp_h263_cap*)p_codec_cap;
		kal_mem_cpy(h263_cap,&platform_h263_cap,sizeof(platform_h263_cap));
		return VIDEO_RTP_OK;
	case (VIDEO_DEC_STREAM_H264):
		h264_cap = (video_rtp_h264_cap*)p_codec_cap;
		kal_mem_cpy(h264_cap,&platform_h264_cap,sizeof(platform_h264_cap));
		return VIDEO_RTP_OK;
	default:
		video_assert(0);
		return VIDEO_RTP_ERROR;
    }
}

MEDIA_STATUS_CODE video_dec_first_frame(Video_Rtp_Handle_Struct *p_handle, void (*video_rtp_callback)(VIDEO_RTP_EVENT event))
{
    MEDIA_STATUS_CODE result;
    kal_uint8 *frame_addr;
    kal_uint32 frame_length;
    kal_uint32 prev_frame_duration;

    if ((video_rtp_callback == NULL)||(p_handle==NULL))
    	ASSERT(0);

    /* initailize parameter */
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_PLAY_TIME, 0);

    /* Decode the frame */
    result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
	    kal_prompt_trace(MOD_MED, "VIDEO_RTP_video_dec_get_next_frame Err: %d\n", result);
        return result;
    }
    
    result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HDR_PARSE_FRAME_NUMER)==0));
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
	    kal_prompt_trace(MOD_MED, "VIDEO_RTP_dec_parse_data_Err: %d\n", g_video_dec_status.VIDEO_STATUS);
        return result;
    }
	
    g_video_dec_info_ptr->width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH);
    g_video_dec_info_ptr->height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT);	
    g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH);
    g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT);		
	
    if (((g_video_dec_info_ptr->width * g_video_dec_info_ptr->height) > (STREAM_MAX_FRAME_WIDTH * STREAM_MAX_FRAME_HEIGHT))
        || (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height == 0))
    {
        kal_prompt_trace(MOD_MED, "VIDEO_RTP_DEC_FIRST_FRM_RES_ERR: (w:%d, h:%d)\n", g_video_dec_info_ptr->width, g_video_dec_info_ptr->height);
        return VIDEO_ERROR;
    } else {
        // Clear the first frame buffer to let the first decoded frame display in a better way (not that much demosaic).
        mpeg4_dec_clear_frame_buffer(g_video_dec_info_ptr->width, g_video_dec_info_ptr->height);
#if 0		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif		
    }
	   
    /* write register to decode the parsed frame */
    g_video_dec_info_ptr->p_driver->video_dec_start();	
    
    return MEDIA_STATUS_OK;
}

DECODE_TYPE video_rtp_get_decode_type(Video_Rtp_Handle_Struct *p_handle)
{
    DECODE_TYPE type;

    if (p_handle == NULL)
	 ASSERT(0);

    switch (p_handle->g_stream_type)
    {
    case VIDEO_DEC_STREAM_MPEG4:
        type = DECODE_TYPE_MPEG4;
        break;
    case VIDEO_DEC_STREAM_H263:
        type = DECODE_TYPE_H263;
        break;
    case VIDEO_DEC_STREAM_H264:
	 type = DECODE_TYPE_H264;
	 break;
    case VIDEO_DEC_STREAM_VC1:
	 type = DECODE_TYPE_VC1;
	 break;
    default:
        type = DECODE_TYPE_UNKNOW;
        break;
    }

    return type;
}

VIDEO_RTP_STATUS video_rtp_Initialization(Video_Rtp_Handle_Struct *p_handle, rtp_audio_codec_type audio_type, kal_uint32 uSampleRate)
{
    VIDEO_DEC_BUFFER_CB_STRUCT cb_info;
    kal_uint32 dsp_timescale;
    kal_uint32 audio_playback_delay;
    kal_uint32 savedMask;
    kal_uint32 total_frames;
    Media_Format eAudioFormat = MEDIA_FORMAT_AMR;

    if (p_handle == NULL)
        ASSERT(0);

    kal_prompt_trace(MOD_MED, "Drv: VIDEO_RTP_Init\n");

    // The following is from video_dec_comm_initialize()
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_STREAM)
    {
        cb_info.scenario = VIDEO_DEC_BUFFER_SCENARIO_STREAM;
        cb_info.callback = (video_dec_buffer_callback*)(&(p_handle->callback));
        cb_info.event_id = VIDEO_DEC_EVENT_BUFFER_EMPTY;
    } else {
        ASSERT(0);
    }
	
     /* get decoder information memory */
    g_video_dec_info_ptr = (VIDEO_DEC_STRUCT *)extmem_get_buffer(sizeof(VIDEO_DEC_STRUCT));
    
    video_rtp_init();
    video_dec_config_buffer(cb_info);
		
    /* Initailize buffer */
    video_dec_clr_buffer(0, 0xffff);

    switch(audio_type) {
        case(RTP_AUDIO_NONE):
        case(RTP_AUDIO_AMR):
            eAudioFormat = MEDIA_FORMAT_AMR;
            break;
        case(RTP_AUDIO_MP4A_LATM_AAC):
        case(RTP_AUDIO_MPEG4_GENERIC_AAC):
            eAudioFormat = MEDIA_FORMAT_AAC;
            break;
        case(RTP_AUDIO_AWB):
            eAudioFormat = MEDIA_FORMAT_AMR_WB;   
            break;
        default:
            eAudioFormat = MEDIA_FORMAT_AMR;
            break;
    }
	
    dsp_timescale = Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(eAudioFormat, convertSamplingFreqToIndex(uSampleRate));
    audio_playback_delay = Media_A2V_GetAudioPlaybackDelay(eAudioFormat);

    if (audio_type != RTP_AUDIO_NONE)
    {
        video_dec_set_av_timebase(VIDEO_DEC_AV_AUDIO, p_handle->g_stream_timebase, dsp_timescale, audio_playback_delay);
    }
    else
    {
        video_dec_set_av_timebase(VIDEO_DEC_AV_GPT, p_handle->g_stream_timebase, dsp_timescale, audio_playback_delay);
    }
    
    savedMask = SaveAndSetIRQMask();
    //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    RestoreIRQMask(savedMask);

    if (g_video_cur_stream_device.type != VIDEO_DEC_STREAM_NONE)
    {
        total_frames = 0xffffffff;

        /* initailie decode globale variable parameters */
        video_dec_disable_irq(video_rtp_get_decode_format());
        video_dec_stop_av();

        /* store the max width and height for the current application. (clip play has this input)*/
        g_video_dec_info_ptr->display_mode = 0;
        g_video_dec_info_ptr->skip_err_chk_times = 0;
        g_video_dec_info_ptr->video_time_scale = p_handle->g_stream_timebase;
        g_video_dec_info_ptr->audio_time_scale = dsp_timescale;
        g_video_dec_info_ptr->max_width = 0;		 // Todo: Need to set
        g_video_dec_info_ptr->max_height = 0;		 // Todo: Need to set
        g_video_dec_info_ptr->play_speed = 100;
        g_video_dec_info_ptr->pMp4Parser = NULL;
        g_video_dec_info_ptr->pstFSAL = NULL;
        g_video_dec_info_ptr->seek_by_time = KAL_FALSE;
        g_video_dec_info_ptr->seek_time = 0;
        g_video_dec_info_ptr->current_play_time = 0;
        g_video_dec_info_ptr->display_enable = KAL_TRUE;
        g_video_dec_info_ptr->prev_display_enable = KAL_FALSE;
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_OK;
        g_video_dec_status.FSAL_STATUS = FSAL_OK;
        g_video_dec_status.PARSE_STATUS = MP4_PARSER_OK;
	 
        /*Initialize the frame info structure*/
        g_video_dec_info_ptr->decode_type = DECODE_TYPE_UNKNOW;
        //if (p_handle->g_stream_type != VIDEO_DEC_STREAM_MPEG4)
        //    g_video_dec_info_ptr->VOS = NULL; // VOS has been obtained at config parsing for MPEG-4 payload
        g_video_dec_info_ptr->decode_type = video_rtp_get_decode_type(p_handle);
        g_video_dec_info_ptr->total_frames_in_file = total_frames;
        g_video_dec_info_ptr->stop_frame_no = total_frames;
        g_video_dec_info_ptr->disp_lost_frames = 0;
        g_video_dec_info_ptr->video_end = KAL_FALSE;

        g_video_dec_info_ptr->video_end = KAL_FALSE;
        g_video_dec_info_ptr->resz_work_memory = 0;
        g_video_dec_info_ptr->snapshot_resize_memory = 0;
        g_video_dec_info_ptr->snapshot_imgdma_memory = 0;
        g_video_dec_info_ptr->audio_enable = KAL_TRUE;	 
        g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_STOP;
        g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_NONE;

	    // streaming related initialization
	    g_video_dec_info_ptr->sdp_width = 0;
	    g_video_dec_info_ptr->sdp_height = 0;
    } 
    else 
    {
        video_dec_disable_irq(DECODE_TYPE_UNKNOW);
        video_dec_stop_av();
        ASSERT(p_handle->callback != NULL);
        p_handle->callback(VIDEO_DEC_EVENT_FAIL);	//  Todo: VIDEO_DEC_EVENT_FAIL => VIDEO_DEC_EVENT_NO_CODEC
    }

	return VIDEO_RTP_OK;
}

VIDEO_RTP_STATUS video_rtp_Config(Video_Rtp_Handle_Struct *p_handle, void *p_codec_cap, rtp_audio_codec_type audio_type, kal_uint32 uSampleRate, void (*video_rtp_callback)(VIDEO_RTP_EVENT event))
{	
    video_rtp_mp4_cap *mp4_cap=NULL;
    video_rtp_h263_cap *h263_cap=NULL;
    video_rtp_h264_cap *h264_cap=NULL;
    MEDIA_STATUS_CODE result=MEDIA_STATUS_OK;
    VIDEO_RTP_STATUS rtp_res;    
    MP4_CONFIG_PARAM mp4_config_param;

    if ((video_rtp_callback == NULL)||(p_handle == NULL)||(p_codec_cap==NULL))
	ASSERT(0);

    kal_prompt_trace(MOD_MED, "Drv: VIDEO_RTP_Cfg\n");

    p_handle->callback = video_rtp_callback;

    switch (p_handle->g_stream_type)
    {
    	case (VIDEO_DEC_STREAM_MPEG4):
		mp4_cap = (video_rtp_mp4_cap*)p_codec_cap;		
		if ((mp4_cap->timescale < 1000)||(mp4_cap->timescale > 999999))
			p_handle->g_stream_timebase = 90000;
		else
			p_handle->g_stream_timebase = mp4_cap->timescale;
		p_handle->g_b_video_stream_config = KAL_TRUE;				
   		video_rtp_set_format(p_handle->g_stream_type);
   		video_rtp_set_timescale(p_handle->g_stream_timebase);
		// Todo: other capability?
		break;
	case (VIDEO_DEC_STREAM_H263):
		h263_cap = (video_rtp_h263_cap*)p_codec_cap;		
		p_handle->g_stream_timebase = h263_cap->timescale;
		p_handle->g_b_video_stream_config = KAL_FALSE;		
   		video_rtp_set_format(p_handle->g_stream_type);
    		video_rtp_set_timescale(p_handle->g_stream_timebase);
		// Todo: other capability?
		break;		
	case (VIDEO_DEC_STREAM_H264):
		h264_cap = (video_rtp_h264_cap*)p_codec_cap;
		p_handle->g_stream_timebase = h264_cap->timescale;
		p_handle->g_stream_type = VIDEO_DEC_STREAM_H264;
		p_handle->g_b_video_stream_config = KAL_FALSE;		
		p_handle->g_stream_packetization_mode = h264_cap->packetization_mode; // Todo: set by 
   		video_rtp_set_format(p_handle->g_stream_type);
    		video_rtp_set_timescale(p_handle->g_stream_timebase);
    		video_rtp_set_mode(p_handle->g_stream_packetization_mode);
		// Todo: other capability?
		break;
	default:
		video_assert(0);
		return VIDEO_RTP_ERROR;
    }
	
    g_video_dec_status.scenario = VIDEO_SCENARIO_STREAM;
    g_video_dec_status.running = KAL_TRUE;
    if ((rtp_res=video_rtp_Initialization(p_handle,audio_type,uSampleRate))!=VIDEO_RTP_OK)
    {
    	return rtp_res;
    }
	
    switch(g_video_cur_stream_device.type)
    {
    case VIDEO_DEC_STREAM_MPEG4:
    case VIDEO_DEC_STREAM_H263:
        {
            g_video_dec_info_ptr->p_driver = &g_video_dec_mp4_driver;
    #ifdef __TEARING_REDUCTION_FB_IN_INTSRAM__    	
            g_video_dec_info_ptr->p_driver->video_dec_open(STREAM_MAX_FRAME_WIDTH, STREAM_MAX_FRAME_HEIGHT, KAL_TRUE);
    #else
            g_video_dec_info_ptr->p_driver->video_dec_open(STREAM_MAX_FRAME_WIDTH, STREAM_MAX_FRAME_HEIGHT, KAL_FALSE);
    #endif	
            if(g_video_cur_stream_device.type == VIDEO_DEC_STREAM_MPEG4)
                mp4_config_param.b_mp4 = KAL_TRUE;
            else
                mp4_config_param.b_mp4 = KAL_FALSE;
            mp4_config_param.b_file = KAL_FALSE;    
            mp4_config_param.play_speed = 100;
            mp4_config_param.total_frame = 0xffffffff;
            mp4_config_param.start_frame = 0;   
            mp4_config_param.b_from_last_frame = KAL_FALSE;
            mp4_config_param.dec_callback = (video_dec_callback)video_rtp_callback;
            //g_video_dec_info_ptr->p_driver->video_dec_init(&mp4_config_param);      
        }       
        break;  
    default:
        g_video_dec_info_ptr->p_driver = NULL;
        EXT_ASSERT(0, g_video_cur_stream_device.type, 0, 0);        
        break;      
    } 
	
    if (p_handle->g_stream_type==VIDEO_DEC_STREAM_MPEG4)
    { // For MPEG-4 payload, the config data in sdp must be parsed to obtain some header information, including frame width & height.
    	result = video_rtp_config(mp4_cap->pconfig);
     	kal_prompt_trace(MOD_MED, "VIDEO_RTP_Resolution_From_Config: (w:%d,h:%d)\n", g_video_dec_info_ptr->width, g_video_dec_info_ptr->height);
    	if (result != MEDIA_STATUS_OK) {
		    if (((g_video_dec_info_ptr->width * g_video_dec_info_ptr->height) > (STREAM_MAX_FRAME_WIDTH * STREAM_MAX_FRAME_HEIGHT))
			    || (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height == 0))
		    {
			    VIDEO_ASSERT(0);
			    kal_prompt_trace(MOD_MED, "VIDEO_RTP_RESOLUTION_ERR: (w:%d,h:%d)\n", g_video_dec_info_ptr->width, g_video_dec_info_ptr->height);
			    //video_rtp_callback(VIDEO_RTP_EVENT_RESOLUTION_ERR);
			    return VIDEO_RTP_RESOLUTION_ERR;
		    }
    		return VIDEO_RTP_ERROR;
    	}
    }

    g_video_dec_info_ptr->p_driver->video_dec_init(&mp4_config_param);  
    
    return VIDEO_RTP_OK;
}

VIDEO_RTP_STATUS video_rtp_ImagePathOpen(Video_Rtp_Handle_Struct *p_handle, MP4DEC_IMGPATH_STRUCT *p_ip)
{
   VIDEO_RTP_STATUS rtp_status = VIDEO_RTP_OK;

   if (((g_video_dec_info_ptr->width * g_video_dec_info_ptr->height) > (STREAM_MAX_FRAME_WIDTH * STREAM_MAX_FRAME_HEIGHT))
		   || (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height == 0))
   {
   	ASSERT(0);
   }
   if (g_video_dec_status.scenario != VIDEO_SCENARIO_STREAM)
   	ASSERT(0);

   if ((p_handle == NULL)||(p_ip==NULL))
   	ASSERT(0);

   kal_prompt_trace(MOD_MED, "Drv: VIDEO_RTP_ImgPthOpn\n");
   
   if (p_handle->is_SwitchScreen_VideoStop != KAL_TRUE) {
      video_image_path_open(p_ip);
      video_dec_set_display(KAL_TRUE);
   }
   //video_dec_display();

   return rtp_status;
}

VIDEO_RTP_STATUS video_rtp_ImagePathClose(Video_Rtp_Handle_Struct *p_handle)
{
	if (g_video_dec_status.scenario != VIDEO_SCENARIO_STREAM)
		ASSERT(0);
	if (p_handle == NULL)
	 	ASSERT(0);
	if (g_video_dec_info_ptr->stage != VIDEO_DEC_STAGE_STOP)
		ASSERT(0);

	kal_prompt_trace(MOD_MED, "Drv: VIDEO_RTP_ImgPthCls\n");

    video_dec_set_display(KAL_TRUE);
	   
	// If error occurs, auto refresh will start. So stop refresh GPT here.
	video_dec_stop_refresh();
	   
	if (p_handle->is_SwitchScreen_VideoStop != KAL_TRUE)
	    video_image_path_close();

	{ // Refer to vid_update_frame_to_buffer
		extern video_decode_data_path_struct vid_dec_para;
		MP4DEC_MEMMODE_STRUCT memmode;

		memmode.disp_width = vid_dec_para.display_width;
		memmode.disp_height = vid_dec_para.display_height;
		memmode.lcd_buf_addr = vid_dec_para.frame_buffer_address;
		memmode.brightness_level = vid_dec_para.brightness_level;
		memmode.contrast_level = vid_dec_para.contrast_level;
		memmode.image_data_format = vid_dec_para.image_data_format;
		memmode.image_pitch_bytes = vid_dec_para.image_pitch_bytes;
		memmode.image_pitch_mode = vid_dec_para.image_pitch_mode;
		memmode.tv_output = vid_dec_para.tv_output;
		video_memorymode_open(&memmode);
		video_dec_frame_to_memory();
		video_memorymode_close();
	}
	return VIDEO_RTP_OK;	
}

VIDEO_RTP_STATUS video_rtp_GetImageResolution(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_width, kal_uint32 *p_height, void (*video_rtp_callback)(VIDEO_RTP_EVENT event))
{
    kal_int32 i=0, test_cnt=0, framecnt=0;
    kal_uint32 hw_status;
    MEDIA_STATUS_CODE status;
    VIDEO_RTP_STATUS rtp_status = VIDEO_RTP_OK;

    if (g_video_dec_status.scenario != VIDEO_SCENARIO_STREAM)
	   ASSERT(0);
    if ((p_handle == NULL)||(p_width==NULL)||(p_height==NULL))//||(video_rtp_callback==NULL))
	   ASSERT(0);

    kal_prompt_trace(MOD_MED, "Drv: VIDEO_RTP_GetImgRes\n");

    while (g_video_dec_buffer_mgr_ptr->total_frame_no < 2)	{ // To prevent video_rtp_start error. Make sure at least two frames.
    	status = video_dec_stream_flush_reorder_buffer();
	if (status != MEDIA_STATUS_OK)
		break;
    }

    framecnt = g_video_dec_buffer_mgr_ptr->total_frame_no;
    while (test_cnt <= framecnt)
    {
       test_cnt++;
	   
       status = video_dec_first_frame(p_handle, p_handle->callback);   
       if (status != MEDIA_STATUS_OK) {
		  if (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_B_H263))
          	g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_B_PARSED_VOL, KAL_FALSE);
          rtp_status = VIDEO_RTP_PACKET_ERROR;
	      if (test_cnt == 1) {
              if (g_video_dec_buffer_mgr_ptr->total_frame_no==0) {
		 	    if (((g_video_dec_info_ptr->width * g_video_dec_info_ptr->height) < (STREAM_MAX_FRAME_WIDTH * STREAM_MAX_FRAME_HEIGHT))
					  && (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height != 0))
		 	    {
				   *p_width = g_video_dec_info_ptr->width;
				   *p_height = g_video_dec_info_ptr->height;
		 	    } else {				 
			       *p_width = 176;	// Trick: Don't skip the following four lines althought this is only for MED to simply check the seek_to_end case.
			       *p_height = 144;	
			       g_video_dec_info_ptr->width = 176;
			       g_video_dec_info_ptr->height = 144;
		 	    }
			    g_video_dec_info_ptr->real_width = *p_width;
			    g_video_dec_info_ptr->real_height = *p_height;

			    //mpeg4_dec_clear_last_frame(*p_width, *p_height);
			    mpeg4_dec_clear_frame_buffer(*p_width, *p_height);
			    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_WIDTH, *p_width);
			    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_HEIGHT, *p_height);
			    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_WIDTH, *p_width);
			    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_HEIGHT, *p_height);
			    kal_prompt_trace(MOD_MED, "VIDEO_RTP_DEC_FIRST_FRM_ERR: (status:%d, test_cnt:%d) (No Frames in buffer!) \n", status, test_cnt);
			    kal_prompt_trace(MOD_MED, "width, height, real_width, real_height: :%d, %d, %d, %d)\n", g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH), g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT), g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH), g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT));
			    return VIDEO_RTP_OK;	// Trick: For seek to the end and no packet coming.
	         } 
	         kal_prompt_trace(MOD_MED, "VIDEO_RTP_DEC_FIRST_FRM_ERR: (status:%d, test_cnt:%d) (Try next frame!) \n", status, test_cnt);
	         continue;
          } else if (test_cnt < framecnt) {
             kal_prompt_trace(MOD_MED, "VIDEO_RTP_DEC_FIRST_FRM_ERR: (status:%d, test_cnt:%d) (Try next frame!) \n", status, test_cnt);
             continue;	// Try 5 times to get right width and height
          } else {
             *p_width = 176;
             *p_height = 144;	
             g_video_dec_info_ptr->width = 176;
             g_video_dec_info_ptr->height = 144;
             g_video_dec_info_ptr->real_width = *p_width;
             g_video_dec_info_ptr->real_height = *p_height;

             //mpeg4_dec_clear_last_frame(*p_width, *p_height);
             mpeg4_dec_clear_frame_buffer(*p_width, *p_height);
             g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_WIDTH, *p_width);
             g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_HEIGHT, *p_height);
             g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_WIDTH, *p_width);
             g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_HEIGHT, *p_height);
             kal_prompt_trace(MOD_MED, "VIDEO_RTP_DEC_FIRST_FRM_ERR: (status:%d, test_cnt:%d) (No More Frames!)\n", status, test_cnt);
             kal_prompt_trace(MOD_MED, "width, height, real_width, real_height: :%d, %d, %d, %d)\n", g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH), g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT), g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH), g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT));
             return VIDEO_RTP_RESOLUTION_ERR;	// Trick: for MED to replace image resolution and follow the process of underflow.
          }
       }else {
          //mpeg4_dec_clear_last_frame(g_video_dec_info_ptr->width, g_video_dec_info_ptr->height);
       }
	   kal_prompt_trace(MOD_MED, "VIDEO_RTP_DEC_FIRST_FRM_OK: (test_cnt:%d)\n", test_cnt);
       if (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_CUR_FRAME_CODED))	// Not non_coded
       {
       	i = 0;
       	while (1) {
#ifdef DRV_MP4_V1
       		ASSERT(0);
#endif // DRV_MP4_V1

       		hw_status = DRV_Reg32(MP4_DEC_IRQ_STS);
       		if (hw_status & MP4_DEC_IRQ_STS_DEC) {
            		/* decode done */
				DRV_WriteReg32(MP4_DEC_IRQ_ACK, MP4_DEC_IRQ_STS_DEC);
				DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_STOP);
				break;
          	} else {
				kal_sleep_task(10);
				i++;
				if (i>=3) {
					kal_uint32 y_addr = mpeg4_dec_get_display_frame_addr();
					ASSERT(y_addr != 0);

					kal_mem_set((void*)y_addr, 0, g_video_dec_info_ptr->width*g_video_dec_info_ptr->height);
					kal_mem_set((void*)(y_addr+g_video_dec_info_ptr->width*g_video_dec_info_ptr->height), 128, (g_video_dec_info_ptr->width*g_video_dec_info_ptr->height)>>1);
					VIDEO_ASSERT(0);
					rtp_status = VIDEO_RTP_PACKET_ERROR;
					g_video_dec_info_ptr->p_driver->video_dec_reset(KAL_FALSE);
					DRV_WriteReg32(MP4_DEC_IRQ_ACK, status);
					kal_prompt_trace(MOD_MED, "VIDEO_RTP_HW_STS_ERR: (status:%d)\n", hw_status);
					break;
				}
			}
          }
       }

	   if ((i>=3)&&(test_cnt <= framecnt)) continue;	// Continue if it is not complete to try 5 times.
	
       if (((g_video_dec_info_ptr->width * g_video_dec_info_ptr->height) > (STREAM_MAX_FRAME_WIDTH * STREAM_MAX_FRAME_HEIGHT))
          || (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height == 0))
       {
            /* width*height is the memory usage. should not exceeds software prepared memory size*/
            VIDEO_ASSERT(0);
            kal_prompt_trace(MOD_MED, "VIDEO_RTP_RESOLUTION_ERR: (w:%d,h:%d)\n", g_video_dec_info_ptr->width, g_video_dec_info_ptr->height);
            //video_rtp_callback(VIDEO_RTP_EVENT_RESOLUTION_ERR);
            return VIDEO_RTP_RESOLUTION_ERR;
       } else {
            kal_prompt_trace(MOD_MED, "VIDEO_RTP_RESOLUTION_OK: (w:%d,h:%d)\n", g_video_dec_info_ptr->width, g_video_dec_info_ptr->height);
            break;
       }
    }
	   
    *p_width = g_video_dec_info_ptr->width;
    *p_height = g_video_dec_info_ptr->height;

    rtp_status = VIDEO_RTP_OK;
    return VIDEO_RTP_OK;	
}

VIDEO_RTP_STATUS video_rtp_Start(Video_Rtp_Handle_Struct *p_handle, kal_uint32 start_time, void (*video_rtp_callback)(VIDEO_RTP_EVENT event))
{
    kal_uint32 rand_time, audio_frame_no;
    VIDEO_RTP_STATUS rtp_status=VIDEO_RTP_OK;
    MEDIA_STATUS_CODE status;
    kal_uint64 play_time;

    if (g_video_dec_status.scenario != VIDEO_SCENARIO_STREAM)
	   ASSERT(0);
    if ((video_rtp_callback == NULL)||(p_handle == NULL))
    	ASSERT(0);
    if (((g_video_dec_info_ptr->width * g_video_dec_info_ptr->height) > (STREAM_MAX_FRAME_WIDTH * STREAM_MAX_FRAME_HEIGHT))
		|| (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height == 0))
    {
        ASSERT(0);
    }
    // Set video's start play time from sdp (MED).
    play_time = VIDEO_ANYBASE_TO_ANYBASE(start_time, 1000, video_dec_get_audio_timebase()/1024);
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_PLAY_TIME, play_time);
    kal_prompt_trace(MOD_MED, "Drv: VIDEO_RTP_Start: %d\n", start_time);

    // The following is from video_dec_comm_initialize()
    /*Tricky to avoid Video display issue*/
    VIDEO_MAX_GPT_REFRESH_TIME = VIDEO_MAX_GPT_REFRESH_TIME_DEF;
    rand_time = (video_get_current_time()%64);
    VIDEO_MAX_GPT_REFRESH_TIME += (kal_uint16)rand_time;
    VIDEO_MAX_GPT_REFRESH_TIME = ((VIDEO_MAX_GPT_REFRESH_TIME/10)*10);

    if (g_video_dec_gpt_refresh_handle== 0)
        GPTI_GetHandle(&g_video_dec_gpt_refresh_handle);

    // Move to ImagePathOpen() since ImagePathOpen will open image data path and start display. 
    // So the first image must be decoded there. Thus ImagePathOpen must be called after PutPackets.
    //status = video_dec_first_frame(p_handle, video_rtp_callback);

    video_dec_rst_av_timeoffset();

#ifndef __VIDEO_STREAM_STORE_BUFFER__
    if ((status = video_dec_stream_play(&audio_frame_no, (video_dec_callback)video_rtp_callback)) != MEDIA_STATUS_OK)
    {
    	kal_prompt_trace(MOD_MED, "VIDEO_STREAM_PLAY_ERROR: %d\n", status);
		return VIDEO_RTP_ERROR;
    }
#endif

    return rtp_status;
}

VIDEO_RTP_STATUS video_rtp_Stop(Video_Rtp_Handle_Struct *p_handle)
{
    if (g_video_dec_status.scenario != VIDEO_SCENARIO_STREAM)
        ASSERT(0);
    if (p_handle == NULL)
        ASSERT(0);

    video_dec_stop_refresh();

    // The following is from vid_stop_req_hdlr
    /* stop visual */
    video_dec_stop();
    return VIDEO_RTP_OK;
}

VIDEO_RTP_STATUS video_rtp_SwitchScreen_VideoStop(Video_Rtp_Handle_Struct *p_handle)
{
   if (g_video_dec_status.scenario != VIDEO_SCENARIO_STREAM)
      ASSERT(0);
   if (p_handle == NULL)
        ASSERT(0);

   video_dec_set_display(KAL_FALSE);
   // If error occurs, auto refresh will start. So stop refresh GPT here.
   video_dec_stop_refresh();
	   
   video_image_path_close();

   p_handle->is_SwitchScreen_VideoStop = KAL_TRUE;	// Set as true to avoid doing video_image_path_close twice when MMI SwitchScreen and then buffer underflow.
   kal_prompt_trace(MOD_MED, "Drv: SwitchScreen_VideoStop\n");
   return VIDEO_RTP_OK;
}

VIDEO_RTP_STATUS video_rtp_SwitchScreen_VideoStart(Video_Rtp_Handle_Struct *p_handle, MP4DEC_IMGPATH_STRUCT *p_ip)
{
   VIDEO_RTP_STATUS rtp_status = VIDEO_RTP_OK;
 
   if (((g_video_dec_info_ptr->width * g_video_dec_info_ptr->height) > (STREAM_MAX_FRAME_WIDTH * STREAM_MAX_FRAME_HEIGHT))
		 || (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height == 0))
   {
      ASSERT(0);
   }
   if (g_video_dec_status.scenario != VIDEO_SCENARIO_STREAM)
      ASSERT(0);
 
   if ((p_handle == NULL)||(p_ip==NULL))
      ASSERT(0);
 
   video_image_path_open(p_ip);
   video_dec_set_display(KAL_TRUE);

   p_handle->is_SwitchScreen_VideoStop = KAL_FALSE;	// MMI complete SwitchScreen
   kal_prompt_trace(MOD_MED, "Drv: SwitchScreen_VideoStart\n");
   return rtp_status;
}

VIDEO_RTP_STATUS video_rtp_CheckPkts(Video_Rtp_Handle_Struct *p_handle, kal_uint32 start_seq, kal_uint32 thre)
{
	kal_uint32 pktcnt;
	
     if (p_handle == NULL)
         ASSERT(0);
     pktcnt = video_rtp_reorder_check_pkt(start_seq, thre);

     return VIDEO_RTP_OK;
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

VIDEO_RTP_STATUS video_rtp_Close(Video_Rtp_Handle_Struct *p_handle)
{
    if (p_handle == NULL)
        ASSERT(0);
    if (g_video_dec_info_ptr !=NULL) {
        if (g_video_dec_info_ptr->path_type != VIDEO_DEC_IMG_PATH_NONE)
            ASSERT(0);
    }

    kal_prompt_trace(MOD_MED, "Drv: VIDEO_RTP_Cls\n");

    // The following is from vid_close_req_hdlr
#ifdef __MTK_TARGET__
    video_dec_close();
#endif 
    return VIDEO_RTP_OK;	
}

VIDEO_RTP_STATUS video_rtp_PutPacket(Video_Rtp_Handle_Struct *p_handle, kal_uint8 *p_buffer, kal_uint32 buffer_size)
{
	MEDIA_STATUS_CODE result;

	if ((p_handle == NULL)||(p_buffer==NULL)||(buffer_size==0))
		ASSERT(0);

	result = video_dec_stream_put_frame_to_buffer(p_buffer, buffer_size);
	if (result != MEDIA_STATUS_OK)
		return VIDEO_RTP_ERROR;
	else
		return VIDEO_RTP_OK;
}

VIDEO_RTP_STATUS video_rtp_GetBufferDuration(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_buffer_duration)
{
    VIDEO_DEC_BUFFER_STRUCT *buffer_ptr;
    kal_uint32 i,j,duration=0;
    VIDEO_DEC_AV_TYPE av_type;

    if ((p_handle == NULL)||(p_buffer_duration==NULL))
	   ASSERT(0);

    for (i=g_video_dec_buffer_mgr_ptr->read_buffer_id;;i++) {
        i %= g_video_dec_buffer_mgr_ptr->buffer_count;
        buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[i];
        if (buffer_ptr->frame_write_index > buffer_ptr->frame_read_index) {
            for (j=buffer_ptr->frame_read_index; j<=buffer_ptr->frame_write_index-1; j++) {
                duration += buffer_ptr->prev_frame_duration[j];
            }
        }
        if (i==g_video_dec_buffer_mgr_ptr->write_buffer_id)
            break;
    }

    av_type = video_dec_get_av_type();
    if (av_type == VIDEO_DEC_AV_AUDIO)
    {
        *p_buffer_duration = (kal_uint32)VIDEO_ANYBASE_TO_MS(duration*1024, video_dec_get_audio_timebase());
    }
    else if (av_type == VIDEO_DEC_AV_GPT)
    {
        *p_buffer_duration = VIDEO_ANYBASE_TO_MS(duration, VIDEO_GPT_TIME_BASE);
    }
    else if (av_type == VIDEO_DEC_AV_COMMON)
    {
        *p_buffer_duration = VIDEO_COMMBASE_TO_ANYBASE(duration, 1000);
    }
    else
    {
        EXT_ASSERT(0, av_type, 0, 0);
    }

    return VIDEO_RTP_OK;    
}

VIDEO_RTP_STATUS video_rtp_GetBufferStatus(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_percentge_used, kal_uint32 *p_free_space)
{
    VIDEO_DEC_BUFFER_STRUCT *buffer_ptr;
    kal_uint32 size=0, i, j;

    if ((p_handle == NULL)||(p_percentge_used==NULL)||(p_free_space==NULL))
	   ASSERT(0);

    for (i=g_video_dec_buffer_mgr_ptr->read_buffer_id;;i++) {
        i %= g_video_dec_buffer_mgr_ptr->buffer_count;
        buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[i];
        if (buffer_ptr->frame_write_index > buffer_ptr->frame_read_index) {
            size += buffer_ptr->size_usage;
            if (buffer_ptr->frame_read_index != 0) {			
                for (j=0; j<buffer_ptr->frame_read_index; j++)
                    size -= buffer_ptr->frame_length[j];
            }
        }
        if (i==g_video_dec_buffer_mgr_ptr->write_buffer_id)
            break;
    }
	
    *p_percentge_used = 100*size/(VIDEO_DEC_BUFFER_SIZE*VIDEO_DEC_BUFFER_COUNT);
    *p_free_space = (VIDEO_DEC_BUFFER_SIZE*VIDEO_DEC_BUFFER_COUNT) - size;
    return VIDEO_RTP_OK;
}

VIDEO_RTP_STATUS video_rtp_GetPlayTime(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_current_time)
{
    if ((p_handle == NULL)||(p_current_time==NULL))
	   ASSERT(0);

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_RTP_ERROR;
    }
	
    *p_current_time = (kal_uint32)VIDEO_ANYBASE_TO_ANYBASE(g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_PLAY_TIME), 
	 					video_dec_get_audio_timebase()*1024, 1000);
	 
    return VIDEO_RTP_OK;
}

Video_Rtp_Handle_Struct* Video_Rtp_Get_Handle(void)
{
	Video_Rtp_Handle_Struct *p_handle;

#ifdef DRV_MP4_V1
       ASSERT(0);
#endif
	p_handle = (Video_Rtp_Handle_Struct*)extmem_get_buffer(sizeof(Video_Rtp_Handle_Struct));
	if (p_handle == NULL)
		ASSERT(0);

	p_handle->GetAvailableCodecs = video_rtp_GetAvailableCodecs;
	p_handle->SetActiveCodec = video_rtp_SetActiveCodec;
	p_handle->GetCapability = video_rtp_GetCapability;
	p_handle->Config = video_rtp_Config;
	p_handle->ImagePathOpen = video_rtp_ImagePathOpen;
	p_handle->ImagePathClose = video_rtp_ImagePathClose;
	p_handle->GetImageResolution = video_rtp_GetImageResolution;
	p_handle->Start = video_rtp_Start;
	p_handle->Stop = video_rtp_Stop;
	p_handle->Close = video_rtp_Close;
	p_handle->PutPacket = video_rtp_PutPacket;
	p_handle->GetPlayTime = video_rtp_GetPlayTime;
	p_handle->GetBufferDuration = video_rtp_GetBufferDuration;
	p_handle->GetBufferStatus = video_rtp_GetBufferStatus;
	//p_handle->SwitchScreen = video_rtp_SwitchScreen;
	p_handle->SwitchScreen_VideoStop = video_rtp_SwitchScreen_VideoStop;
	p_handle->SwitchScreen_VideoStart = video_rtp_SwitchScreen_VideoStart;	
	p_handle->CheckPkts = video_rtp_CheckPkts;

	p_handle->is_SwitchScreen_VideoStop = KAL_FALSE;
	return p_handle;
}

#ifdef __VIDEO_STREAM_UNIT_TEST__
/////////////////////////////////////////////////////////////////////
//			H.264 UT application
//////////////////////////////////////////////////////////////////////
static STFSAL FSAL_VIDEO_H264_DATA_FILE;    /* store parsed data(mdat) */
static STFSAL FSAL_VIDEO_H264_SIZE_FILE;     /* store frame size */
static STFSAL FSAL_VIDEO_H264_TIME_FILE;    /* store frame time */


/* open file to store buffer data */
static void video_stream_open_h264_file(void)
{
    FSAL_Status FSAL_STATUS;
    kal_wchar   store_name[30]=L"x:\\h264_data.bin";
    kal_wchar   store_name2[30]=L"x:\\h264_size.bin";
    kal_wchar   store_name3[30]=L"x:\\h264_time.bin";    
    store_name[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    store_name2[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    store_name3[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    FSAL_STATUS = FSAL_Open(&FSAL_VIDEO_H264_DATA_FILE, store_name, FSAL_WRITE);
    if (FSAL_STATUS != FSAL_OK)
    {
        ASSERT(0);
    }
    
    FSAL_STATUS = FSAL_Open(&FSAL_VIDEO_H264_SIZE_FILE, store_name2, FSAL_WRITE);
    if (FSAL_STATUS != FSAL_OK)
    {
        ASSERT(0);
    }

    FSAL_STATUS = FSAL_Open(&FSAL_VIDEO_H264_TIME_FILE, store_name3, FSAL_WRITE);
    if (FSAL_STATUS != FSAL_OK)
    {
        ASSERT(0);
    }
}

/* write bitstream data to data file */
static void video_stream_write_h264_data_file(kal_uint8* mem_addr, kal_uint32 size)
{
    FSAL_Status tmp_status;

    tmp_status = FSAL_Write(&FSAL_VIDEO_H264_DATA_FILE, (kal_uint8 *)mem_addr, size);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }   
}

/* write frame size information to size file */
static void video_stream_write_h264_size_file(kal_uint8* mem_addr, kal_uint32 size)
{
    FSAL_Status tmp_status;

    tmp_status = FSAL_Write(&FSAL_VIDEO_H264_SIZE_FILE, (kal_uint8 *)mem_addr, size);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }   
}

/* write frame time information to time file */
static void video_stream_write_h264_time_file(kal_uint8* mem_addr, kal_uint32 size)
{
    FSAL_Status tmp_status;

    tmp_status = FSAL_Write(&FSAL_VIDEO_H264_TIME_FILE, (kal_uint8 *)mem_addr, size);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }   
}

/* close data files */
static void video_stream_close_h264_file(void)
{
    FS_Commit(FSAL_VIDEO_H264_DATA_FILE.hFile);
    FS_Commit(FSAL_VIDEO_H264_SIZE_FILE.hFile);
    FS_Commit(FSAL_VIDEO_H264_TIME_FILE.hFile);
    
    FSAL_Close(&FSAL_VIDEO_H264_DATA_FILE);
    FSAL_Close(&FSAL_VIDEO_H264_SIZE_FILE);
    FSAL_Close(&FSAL_VIDEO_H264_TIME_FILE); 
}

/* UT seek function, original player seek function will call this UT function */
/* In this function, all data will be parsed and write to data, size, and time files */
MEDIA_STATUS_CODE video_dec_stream_seek_h264(kal_uint64 seek_time, void (*callback)(kal_uint8 event))
{
    MEDIA_STATUS_CODE result;
    kal_uint8 *frame_addr;
    kal_uint32 frame_length;
    kal_uint32 prev_frame_duration;
    kal_uint32 index;
    

    if(seek_time!=0)
    {
        /* Not support */
        ASSERT(0);
    }

    if(callback == NULL)
    	ASSERT(0);


    /* initailize parameter */
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_PLAY_TIME, 0);
    g_video_dec_stream_dummy_api_info.data_offset= 0;
    g_video_dec_stream_dummy_api_info.b_recover= KAL_FALSE;

    /* open file to store parsed data */
    video_stream_open_h264_file();

    /* Initailize buffer */
    video_dec_clr_buffer(0, 0xffff);
    
    /* put frames */
    while( g_video_dec_stream_dummy_api_info.data_offset!= g_video_dec_stream_dummy_api_info.size)
    {
        /* Put frames */
        kal_uint32 frame_size = 0;
        frame_size = (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset] << 24) + 
            	            (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+1] << 16) +
         	            (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+2] << 8) +
                         (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+3] << 0);
        if(video_rtp_put_frame(&g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+4], frame_size-4) != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
        }
        else
        {
            g_video_dec_stream_dummy_api_info.data_offset+=frame_size;
        }
        
        /* get from frame buffer and write to file */
        result = MEDIA_STATUS_OK;
        while(result == MEDIA_STATUS_OK)
        {
            result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
            if(result==MEDIA_STATUS_OK)
            {
                /* write the frame infomration to file */
                video_stream_write_h264_data_file(frame_addr, frame_length);
                video_stream_write_h264_size_file((kal_uint8*)(&frame_length), 4);
                video_stream_write_h264_time_file((kal_uint8*)(&prev_frame_duration), 4);
            }
        }
    }

     /* end of stream. size 0 */
    video_rtp_put_frame(&g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset], 0);  

    for(index = 0; index < 50; index++)
    {
        /* get from frame buffer and write to file */
        result = MEDIA_STATUS_OK;
        while(result == MEDIA_STATUS_OK)
        {
            result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
            if(result==MEDIA_STATUS_OK)
            {
                /* write to file */
                video_stream_write_h264_data_file(frame_addr, frame_length);
                video_stream_write_h264_size_file((kal_uint8*)(&frame_length), 4);
                video_stream_write_h264_time_file((kal_uint8*)(&prev_frame_duration), 4);
            }
        }
    }

    /* close file */
    video_stream_close_h264_file();

    /* callback to notify complete */
    callback(VIDEO_DEC_EVENT_SEEK_DONE);

    return MEDIA_STATUS_OK;
}

extern Video_Rtp_Handle_Struct *p_video_rtp_handle; 
void video_dec_stream_init(void)
{
     if (g_video_dec_stream_dummy_api_info.gpt_handle== 0)
        GPTI_GetHandle(&g_video_dec_stream_dummy_api_info.gpt_handle);
     g_video_dec_stream_dummy_api_info.gpt_time_count = 50;
     g_video_dec_stream_dummy_api_info.pkt_num = 30;
     g_video_dec_stream_dummy_api_info.first_pkt_num = 80;
     if (p_video_rtp_handle->g_stream_type==VIDEO_DEC_STREAM_MPEG4)
	  g_video_dec_stream_dummy_api_info.size = 0x59f62;
     else if (p_video_rtp_handle->g_stream_type==VIDEO_DEC_STREAM_H263)
	  g_video_dec_stream_dummy_api_info.size = 0x5cff3;
     else if (p_video_rtp_handle->g_stream_type==VIDEO_DEC_STREAM_H264) {
	  if (p_video_rtp_handle->g_stream_packetization_mode ==H264_RTP_INTERLEAVED_MODE)
	  	g_video_dec_stream_dummy_api_info.size = 1459643;
	  else
	  	g_video_dec_stream_dummy_api_info.size = 0x163356;
     }
     g_video_dec_stream_dummy_api_info.config_size = 0x40;
     g_video_dec_stream_dummy_api_info.data_offset = 0;
     g_video_dec_stream_dummy_api_info.b_recover = KAL_FALSE;
     g_video_dec_stream_dummy_api_info.data =  (kal_uint8*)g_video_stream_data_start_addr;
     g_video_dec_stream_dummy_api_info.p_config = (kal_uint8*)g_video_stream_config_start_addr;

     //video_rtp_set_format(g_stream_type);
     //video_rtp_set_timescale(g_stream_timebase);
     //video_rtp_set_mode(g_stream_packetization_mode);
     //video_rtp_init();
}

/* GPT callback function */
extern void GPTI_StopItem(kal_uint8 module);
void video_dec_stream_test_callback(void * parameter)
{
    ilm_struct       *ilm_ptr = NULL;

    GPTI_StopItem(g_video_dec_stream_dummy_api_info.gpt_handle);

    // send message to custom task, let it put frames to decoder  
    DRV_BuildPrimitive(ilm_ptr, MOD_DRV_HISR,
	 					MOD_CUSTOM1, MSG_ID_VIDEO_STREAM_TEST, NULL);
    msg_send_ext_queue(ilm_ptr);
}

VIDEO_RTP_STATUS video_rtp_PutFirstPackets(Video_Rtp_Handle_Struct *p_handle)
{
	kal_uint32 index;

	/* for Darwin test, VOS data of MPEG-4 payload in RTSP packet  */
	if (p_handle->g_b_video_stream_config==KAL_TRUE)
	{
		MEDIA_STATUS_CODE result = video_rtp_config(g_video_dec_stream_dummy_api_info.p_config);
		if (result != MEDIA_STATUS_OK)
		{
				VIDEO_ASSERT(0);
				return result;
	   }
	}		

	/* put frames */
	 for(index = 0; index < g_video_dec_stream_dummy_api_info.first_pkt_num; index++)
	 {
		 if( g_video_dec_stream_dummy_api_info.data_offset!= g_video_dec_stream_dummy_api_info.size)
		 {
			 /* Put the first frame and decode it */
			 kal_uint32 frame_size = 0;
			 frame_size = (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset] << 24) + 
							 (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+1] << 16) +
							 (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+2] << 8) +
								   (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+3] << 0);
			 if(video_rtp_put_frame(&g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+4], frame_size-4) != MEDIA_STATUS_OK)
			 {
				 VIDEO_ASSERT(0);
			 }
			 else
			 {
				 g_video_dec_stream_dummy_api_info.data_offset+=frame_size;
			 }
	
			 if(g_video_dec_stream_dummy_api_info.data_offset == g_video_dec_stream_dummy_api_info.size)
			 {
				 /* end of stream. size 0 */
				 video_rtp_put_frame(&g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset], 0);   
				 break;
			 }
		 }
	 }
	 return VIDEO_RTP_OK;	 
}

MEDIA_STATUS_CODE video_dec_stream_recover(kal_uint32 * audio_frame_no, void (*video_dec_callback)(kal_uint8 event))
{
    MEDIA_STATUS_CODE result;
    kal_uint32 index;
    kal_uint8 *frame_addr;
    kal_uint32 frame_length;
    kal_uint32 prev_frame_duration;
    kal_uint64 decode_time;
    kal_uint32 savedMask;
    kal_uint64 video_time = 0;
    kal_uint64 audio_decode_time;
    kal_uint32 frame_duration;
    kal_uint32 DspTimeScale;

    g_video_dec_stream_dummy_api_info.b_recover = KAL_TRUE;
    
    g_video_dec_info_ptr->video_dec_callback = video_dec_callback;

    /* put frames */
    for(index = 0; index < g_video_dec_stream_dummy_api_info.pkt_num; index++)
    {
        if( g_video_dec_stream_dummy_api_info.data_offset!= g_video_dec_stream_dummy_api_info.size)
        {
            /* Put the  frame and decode it */
            kal_uint32 frame_size = 0;
            frame_size = (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset] << 24) + 
              	            (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+1] << 16) +
             	            (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+2] << 8) +
            	                  (g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+3] << 0);
            if(video_rtp_put_frame(&g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset+4], frame_size-4) != MEDIA_STATUS_OK)
            {
                // nothing  
                static kal_bool b_stream_test_error = KAL_FALSE;
                b_stream_test_error = KAL_TRUE;
            }
            else
            {
                g_video_dec_stream_dummy_api_info.data_offset+=frame_size;
            }

            if(g_video_dec_stream_dummy_api_info.data_offset == g_video_dec_stream_dummy_api_info.size)
            {
                /* end of stream. size 0 */
                video_rtp_put_frame(&g_video_dec_stream_dummy_api_info.data[g_video_dec_stream_dummy_api_info.data_offset], 0);   
                break;
            }
        }
    }

    /* re-initialize parameters */
    //g_video_dec_info_ptr->skip_frames = 0;      
    //g_video_dec_info_ptr->recover_start = KAL_FALSE;
    //g_video_dec_info_ptr->is_non_coded = KAL_FALSE;
    //g_video_dec_info_ptr->skip_check_isr_status = KAL_FALSE;
    //g_video_dec_info_ptr->isr_error_event_happen = KAL_FALSE;
    //g_video_dec_info_ptr->decode_error_frame_count_in_high_speed = 0;

    /* Decode the frame */
    result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    frame_duration = prev_frame_duration;

    result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);
    //result = mpeg4_decode_main(frame_addr, frame_length, prev_frame_duration);
    if (result != MEDIA_STATUS_OK)
    {
        /* parse next frame */
        VIDEO_ASSERT(0);
        return result;
    }

    /* write register to decode the parsed frame */
    //mpeg4_decode_write_register();
    g_video_dec_info_ptr->p_driver->video_dec_start();

    /* Pre-parse the next frame */
    if (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HDR_PARSE_FRAME_NUMER)
		< g_video_dec_info_ptr->total_frames_in_file)
    {
        /* Not the last frame */
        result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        /* pre-parse the next frame */
        //result = mpeg4_decode_main(frame_addr, frame_length, prev_frame_duration);
        result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);
        if (result != MEDIA_STATUS_OK)
        {
            /* treat the error frame as non-coded */
            VIDEO_ASSERT(0);
            //g_video_dec_info_ptr->is_non_coded = KAL_TRUE;
        }
    }
    else
    {
        /* simply test */
        VIDEO_ASSERT(0);
        result = VIDEO_ERROR;
    }

#if 1
    //video_time = VIDEO_ANYBASE_TO_ANYBASE(g_video_dec_info_ptr->play_time, g_stream_timebase, g_video_dec_info_ptr->video_time_scale);
    DspTimeScale = Media_A2V_GetPlaybackInterruptTimeScale(
             	                              MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(g_video_dec_info_ptr->pMp4Parser)),
                                                 MP4_Audio_GetFreqIndex(g_video_dec_info_ptr->pMp4Parser));
    video_time = VIDEO_ANYBASE_TO_ANYBASE(g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_PLAY_TIME),
                                                  DspTimeScale,g_video_dec_info_ptr->video_time_scale);
            
    /* get audio frame number */
    g_video_dec_status.PARSE_STATUS = MP4_Audio_Seek_To_Video(g_video_dec_info_ptr->pMp4Parser, video_time,
                                                              audio_frame_no);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    { 
        ASSERT(0);
    }
    else
    {
        /* get audio duration from frame number */
        g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser, *audio_frame_no,
                                                            &audio_decode_time,  MP4_TRACK_AUDIO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            ASSERT(0);
        }
    }

    /* calculate av time and prepare  set to av */
    audio_decode_time = VIDEO_ANYBASE_TO_ANYBASE(audio_decode_time, g_video_dec_info_ptr->audio_time_scale,
                                                 g_video_dec_info_ptr->video_time_scale);
    
    /* calculate video and audio offset*/
    result = video_dec_translate_av_time((kal_uint64)(video_time - audio_decode_time), &decode_time);
    /* Rita add, 
        1. audio frame and the previous play time may be not the same*/
     MP4_SetPlaybackTimerBase((STMp4Parser*)vid_get_audio_parser(),
                                               (kal_uint32) VIDEO_ANYBASE_TO_MS(audio_decode_time, g_video_dec_info_ptr->video_time_scale),
                                               KAL_TRUE);
    

    /* add video frame duration to offset */
    if (frame_duration == 0)
        decode_time += g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_CUR_FRAME_DURATION);
    else
        decode_time += frame_duration;
    //g_video_dec_info_ptr->pre_frame_duration = decode_time;

    /* Set DSP */
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    video_set_dec_isr(video_file_get_decode_type());
    video_dec_set_frametime((kal_uint32)decode_time, KAL_TRUE);
    video_enable_dec_isr(video_file_get_decode_type());
#endif

    g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_PLAY;
#endif


     if(g_video_dec_stream_dummy_api_info.data_offset!=g_video_dec_stream_dummy_api_info.size)
    {
        // start gpt timer (simulate application put packets)
        GPTI_StartItem(g_video_dec_stream_dummy_api_info.gpt_handle, g_video_dec_stream_dummy_api_info.gpt_time_count, video_dec_stream_test_callback, NULL);
    }
    
    return MEDIA_STATUS_OK;
}

#endif
#endif /* STREAM_SUPPORT*/

#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
 
