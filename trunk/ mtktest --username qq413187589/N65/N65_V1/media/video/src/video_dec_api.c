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
 *    video_dec_api.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines video api for media task
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
 ****************************************************************************/
#ifdef MP4_CODEC
#include "drv_comm.h"
#include "med_status.h"
#include "visual_comm.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "lcd_if.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#include "visualhisr.h"
#include "intrCtrl.h"
#include "video_hw.h"
#include "imgproc.h"
#include "resizer.h"
#include "imgdma.h"
#include "imgproc.h"
#include "stack_common.h"
#include "syscomp_config.h" /*MOD_BMT*/
#include "stack_msgs.h"
#include "app_ltlcom.h"     /* Task message communiction */
#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"    /*Timer*/
#include "app_buff_alloc.h" /*buffer*/
#include "task_config.h"    /* Task creation */
#include "stack_ltlcom.h"   /*msg_send_ext_queue.....definitions*/
#include "reg_base.h"
#include "drvpdn.h"
#include "gpt_sw.h"
#include "isp_if.h"
#include "img_comm.h"

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
   #include "SST_sla.h"
#endif

/* functions used from other modules */
extern STMp4Parser * vid_get_audio_parser(void);
#ifdef DRV_MP4_V1
extern kal_bool IMGDMA_CheckBusy(IMGDMA_CHANNEL_ENUM ch, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_VdoSetBS1(kal_uint32 bs, MMDI_SCENERIO_ID owner);
extern void clean_imgprc_coefficient(MMDI_SCENERIO_ID owner_id);
#else
extern kal_uint64 video_dec_get_audio_timebase(void);
extern kal_uint32 mpeg4_dec_get_ref_frame_addr(void);
#endif /*DRV_MP4_V1*/

static void video_dec_refresh_callback(void * parameter);
static MEDIA_STATUS_CODE video_dec_struct_init(VIDEO_DEC_STRUCT * dec_struct, DECODE_TYPE dec_type, kal_uint32 total_frame, kal_uint32 start_frame, kal_bool b_from_last_frame);
MEDIA_STATUS_CODE video_dec_initialize_play_time(void);
static MEDIA_STATUS_CODE video_dec_comm_initialize(MP4DEC_INIT_STRUCT * comm_init_input);
static MEDIA_STATUS_CODE video_dec_comm_play(kal_uint32 * audio_frame_no, void (*video_dec_callback)(kal_uint8 event));
static MEDIA_STATUS_CODE video_dec_clip_check_media_file(STMp4Parser * pstMp4Parser, STFSAL * pstFSAL, kal_uint32 max_duration_ms);
static MEDIA_STATUS_CODE video_dec_get_frame_with_time(kal_uint32 * curr_frame, kal_uint64 seek_time, kal_uint64 * next_frame_time);
static void video_dec_internal_stop(void);
static void video_set_disp_size(kal_uint16 disp_width, kal_uint16 disp_height);
kal_uint16 VIDEO_MAX_GPT_REFRESH_TIME = VIDEO_MAX_GPT_REFRESH_TIME_DEF;

#ifdef STREAM_SUPPORT
extern kal_uint64 video_dec_stream_get_first_frame_duration(void);
#endif

#ifdef DRV_MP4_V2
video_decode_data_path_struct vid_dec_para;
#endif

#ifdef VIDEO_DEC_YUV_MODE
static STFSAL FSAL_VIDEO_YUV_FILE;
static void video_dec_store_yuv_file(kal_uint32 yuv_mem_addr, kal_uint32 size);
#endif /*VIDEO_DEC_YUV_MODE*/

kal_uint8  g_video_dec_gpt_refresh_handle;
static kal_uint32 g_video_dec_gpt_refresh_count = 0;

#ifdef __SYNC_LCM_SW_SUPPORT__
extern kal_uint32 video_frame_buffer_address;
#endif
//////////////////////////////////////////////////////////////////////////////////////
//                                                ****************                                                      //
//                                           Internal use                                                             //
//                                                 ****************                                                     //
//////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Refresh functions                                               //
//////////////////////////////////////////////////////////////////

/* The refresh gpt timer callback function
* @param None
* @return None
*/
static void video_dec_refresh_callback(void * parameter)
{
    /*Like video_dec_prev_display*/
    GPTI_StopItem(g_video_dec_gpt_refresh_handle);

    if (g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_HW)
    {
#ifdef DRV_MP4_V1
        if (IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID) == KAL_FALSE)
        {
            video_dec_prev_display();
        }
#else /*!DRV_MP4_V1*/
        if (!IMGDMA_IBW2_IS_BUSY)
        {
            video_dec_prev_display();
        }
#endif /*DRV_MP4_V1*/
    }

    if(g_video_dec_gpt_refresh_count > 0)
    {
        GPTI_StartItem(g_video_dec_gpt_refresh_handle, (VIDEO_MAX_GPT_REFRESH_TIME / 10), video_dec_refresh_callback, NULL);
        g_video_dec_gpt_refresh_count--;
    }
}


/* Start refresh function.
* @param None
* @return None
*/
void video_dec_start_refresh(void)
{
    GPTI_StartItem(g_video_dec_gpt_refresh_handle, (VIDEO_MAX_GPT_REFRESH_TIME / 10), video_dec_refresh_callback, NULL);
    g_video_dec_gpt_refresh_count = 0x0fffffff;
}


/* Stop refresh function.
* @param None
* @return None
*/
void video_dec_stop_refresh(void)
{
    GPTI_StopItem(g_video_dec_gpt_refresh_handle);
}


/* Check whether it needs to be refresh. If yes, it will refresh automatically in this function
* @param None
* @return None
*/
void video_dec_check_refresh(kal_uint32 frame_time)
{
    kal_uint32 refresh_count;
    refresh_count = frame_time / VIDEO_MAX_GPT_REFRESH_TIME;
    if((refresh_count>0) && (frame_time%VIDEO_MAX_GPT_REFRESH_TIME) <= VIDEO_MAX_GPT_REFRESH_GAURD_TIME)
        refresh_count--;

    if (refresh_count>0)
    {
        video_dec_start_refresh();
        g_video_dec_gpt_refresh_count = refresh_count;
    }
    else
    {
        video_dec_stop_refresh();
    }
}



///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Control functions                                               //
//////////////////////////////////////////////////////////////////


/* In YUV mode. Store the decoded frame to file
 * @param  yuv_mem_addr  decoded frame start address
 * @param  size data size
 * @return None
 */
#ifdef VIDEO_DEC_YUV_MODE
static void video_dec_store_yuv_file(kal_uint32 yuv_mem_addr, kal_uint32 size)
{
    FSAL_Status tmp_status;

    tmp_status = FSAL_Write(&FSAL_VIDEO_YUV_FILE, (kal_uint8 *)yuv_mem_addr, size);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }
}
#endif /*VIDEO_DEC_YUV_MODE*/


/* Initialize the VIDEO_DEC_STRUCT.
 * @param  dec_struct VIDEO_DEC_STRUCT structure
 * @param  dec_type DECODE_TYPE_MPEG4 or DECODE_TYPE_H263
 * @param  VOS  the VOS data
 * @param  total_frame
 * @return None
 */
static MEDIA_STATUS_CODE video_dec_struct_init(VIDEO_DEC_STRUCT * dec_struct, DECODE_TYPE dec_type, kal_uint32 total_frame, 
                                                          kal_uint32 start_frame, kal_bool b_from_last_frame)
{
    MEDIA_STATUS_CODE status = MEDIA_STATUS_OK;
    DECODE_TYPE decode_type = video_file_get_decode_type();

    /*Initialize the frame info structure*/
    dec_struct->decode_type = dec_type;
    dec_struct->total_frames_in_file = total_frame;
    dec_struct->stop_frame_no = total_frame;
    dec_struct->disp_lost_frames = 0;
    dec_struct->video_end = KAL_FALSE;

    if((decode_type==DECODE_TYPE_MPEG4) || (decode_type==DECODE_TYPE_H263))
    {
        if(g_video_dec_info_ptr->p_driver!=NULL)
        {
            MP4_CONFIG_PARAM mp4_config_param;
            if(decode_type==DECODE_TYPE_MPEG4)		
                mp4_config_param.b_mp4 = KAL_TRUE;
            else
                mp4_config_param.b_mp4 = KAL_FALSE;
            mp4_config_param.b_file = KAL_TRUE;
            mp4_config_param.play_speed = g_video_dec_info_ptr->play_speed;
            mp4_config_param.total_frame = total_frame;
            mp4_config_param.start_frame = start_frame;
            mp4_config_param.b_from_last_frame = b_from_last_frame;
            mp4_config_param.dec_callback = g_video_dec_info_ptr->video_dec_callback; 			
            status =  g_video_dec_info_ptr->p_driver->video_dec_init(&mp4_config_param);
        }
        else
        {
            EXT_ASSERT(0, 0, 0, 0);
        }
    }
    else
    {
        VIDEO_ASSERT(0);
    }

    return status;
}


/* Initialize get play time and set time parameter in video fiel
 * @param None
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_initialize_play_time(void)
{
    kal_uint32 video_time_scale;
    kal_uint32 audio_time_scale;
    kal_uint32 video_duration;
    kal_uint32 audio_duratoin;

    /* Video time */
    g_video_dec_status.PARSE_STATUS = MP4_GetMediaTimeScale(g_video_dec_info_ptr->pMp4Parser, &video_time_scale,
                                                            MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_TRACK)
    {
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }

        g_video_dec_status.PARSE_STATUS =
            MP4_GetMediaDuration(g_video_dec_info_ptr->pMp4Parser, &video_duration, MP4_TRACK_VIDEO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_TRACK)
        {
            if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
            {
                VIDEO_ASSERT(0);
                return MP4_PARSER_ERROR;
            }
        }
        else
        {
            video_time_scale = 1;
            video_duration = 0;
        }
    }
    else
    {
        video_time_scale = 1;
        video_duration = 0;
    }

    /* Audio time */
    g_video_dec_status.PARSE_STATUS = MP4_GetMediaTimeScale(g_video_dec_info_ptr->pMp4Parser, &audio_time_scale,
                                                            MP4_TRACK_AUDIO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_TRACK)
    {
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }

        g_video_dec_status.PARSE_STATUS =
            MP4_GetMediaDuration(g_video_dec_info_ptr->pMp4Parser, &audio_duratoin, MP4_TRACK_AUDIO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_TRACK)
        {
            if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
            {
                VIDEO_ASSERT(0);
                return MP4_PARSER_ERROR;
            }
        }
        else
        {
            audio_duratoin = 0;
            /*When no audio track, media task will insert mute in AMR fomat.The AMR time scale is 8000*/
            audio_time_scale = Media_A2V_GetPlaybackInterruptTimeScale(
                     MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(g_video_dec_info_ptr->pMp4Parser)),
                     MP4_Audio_GetFreqIndex(g_video_dec_info_ptr->pMp4Parser));
        }
    }
    else
    {
        audio_duratoin = 0;
        /*When no audio track, media task will insert mute in AMR fomat.The AMR time scale is 8000*/
        audio_time_scale = Media_A2V_GetPlaybackInterruptTimeScale(
                    MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(g_video_dec_info_ptr->pMp4Parser)),
                    MP4_Audio_GetFreqIndex(g_video_dec_info_ptr->pMp4Parser));
    }

    /* set tp video and audio parameters */
    g_video_dec_info_ptr->video_time_scale = video_time_scale;
    g_video_dec_info_ptr->audio_time_scale = audio_time_scale;
    g_video_dec_info_ptr->audio_duration = VIDEO_ANYBASE_TO_MS(audio_duratoin, audio_time_scale);
    g_video_dec_info_ptr->video_duration = VIDEO_ANYBASE_TO_MS(video_duration, video_time_scale);

    /* translate to common base */
    g_video_dec_info_ptr->audio_duration = VIDEO_ANYBASE_TO_COMMBASE(audio_duratoin, audio_time_scale);
    g_video_dec_info_ptr->video_duration = VIDEO_ANYBASE_TO_COMMBASE(video_duration, video_time_scale);

    if (g_video_dec_info_ptr->total_frames_in_file > 0)
    {
        g_video_dec_info_ptr->video_avg_frame_duration =
            g_video_dec_info_ptr->video_duration / g_video_dec_info_ptr->total_frames_in_file;
    }
    else
    {
        g_video_dec_info_ptr->video_avg_frame_duration = 0;
    }
    return MEDIA_STATUS_OK;
}

/* Common initialize function for play and clip play
 *  Please run Mp4 parser first
 * @param comm_init_input.  MP4DEC_INIT_STRUCT type
 * @return None    
 */
static MEDIA_STATUS_CODE video_dec_comm_initialize(MP4DEC_INIT_STRUCT * comm_init_input)
{
    kal_uint32 total_frames  = 0;
    MEDIA_STATUS_CODE result;
   
    /*Tricky to avoid Video display issue*/
    VIDEO_MAX_GPT_REFRESH_TIME = VIDEO_MAX_GPT_REFRESH_TIME_DEF;
    
    /* open and init resource first */
    result = video_dec_open(comm_init_input->pstMp4Parser, 
                            comm_init_input->pstFSAL, 
                            comm_init_input->max_width,
                            comm_init_input->max_height);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }
     
    if (video_file_get_decode_type() != DECODE_TYPE_UNKNOW)
    {
        /* init av setting */
        result = video_dec_init_av(comm_init_input->audio_enable);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
        
        /* Get total frame no information from file and check it*/
        g_video_dec_status.PARSE_STATUS = MP4_GetSampleCount(g_video_dec_info_ptr->pMp4Parser, MP4_TRACK_VIDEO,
                                                             &total_frames);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }

        #if defined(__VIDEO_EDITOR__)
        if (total_frames == 0)
        {
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                ASSERT(0);
            }
        }
        #endif /*__VIDEO_EDITOR__*/
    }

    if ((video_file_get_decode_type() != DECODE_TYPE_UNKNOW) && (total_frames > 0))
    {
        /* initailie decode globale variable parameters */
        video_dec_disable_irq(video_file_get_decode_type());
        video_dec_stop_av();
        result = video_dec_struct_init(g_video_dec_info_ptr, video_file_get_decode_type(), total_frames, 0, KAL_FALSE);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
        g_video_dec_info_ptr->video_end = KAL_FALSE;
        g_video_dec_info_ptr->resz_work_memory = 0;
        g_video_dec_info_ptr->snapshot_resize_memory = 0;
        g_video_dec_info_ptr->snapshot_imgdma_memory = 0;
        //g_video_dec_info_ptr->incall = comm_init_input->incall;
        g_video_dec_info_ptr->audio_enable = comm_init_input->audio_enable;
        g_video_dec_info_ptr->check_error_recover_count = 0;
        g_video_dec_info_ptr->check_display_loss_count = 0;
        g_video_dec_info_ptr->b_check_log = KAL_FALSE;

        /* initialize play time information */
        result = video_dec_initialize_play_time();
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        /* decode initialize */ 
#if defined(PGDL_SUPPORT)
			  // Trick: For PGDL H.263 to get width & height for Java streaming player.
	  		if ( (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL)&&(g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_B_H263)==1) )
	  		{
		 			/* check whether media file is legal or not */
		 			result = video_dec_clip_check_media_file(g_video_dec_info_ptr->pMp4Parser,
												g_video_dec_info_ptr->pstFSAL, 0xffffffff);
		 			if (result != MEDIA_STATUS_OK)
		 			{
			  		VIDEO_ASSERT(0);
			  		return FSAL_READ_EOF;
		 			}
		  	} else 
#endif /*PGDL_SUPPORT*/
                   
#if defined(__VIDEO_EDITOR__)
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_DECODE)
#endif /*__VIDEO_EDITOR__*/
        {
            kal_uint32 frame_length;
            kal_uint32 prev_frame_duration;
            kal_uint8 *frame_addr;

            /* check whether media file is legal or not */
            result = video_dec_clip_check_media_file(g_video_dec_info_ptr->pMp4Parser,
                                                     g_video_dec_info_ptr->pstFSAL, 0xffffffff);
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }

            /* direcly decode here, but not seek like normal decode initailize */
            /* prepare parameter and buffer */
            g_video_dec_info_ptr->seek_frame_number = 1;
            g_video_dec_info_ptr->seek_result_frame_number = 1;
            video_dec_clr_buffer(0, 1);
            result = video_dec_put_frame_to_buffer();
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }

            /* get frame and start to decode */
            result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }
            /* decode the first frame and write to register */		
            result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_TRUE);
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }
            g_video_dec_info_ptr->p_driver->video_dec_start();
        }
#if defined(__VIDEO_EDITOR__)
        else if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            kal_uint32 frame_length;
            kal_uint32 prev_frame_duration;
            kal_uint8 *frame_addr;
            /* direcly decode here, but not seek like normal decode initailize */
            /* check whether media file is legal or not */
            result = video_dec_clip_check_media_file(g_video_dec_info_ptr->pMp4Parser,
                                                 g_video_dec_info_ptr->pstFSAL, 0xffffffff);
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }
            	
            /* prepare parameter and buffer */
            g_video_dec_info_ptr->seek_frame_number = 1;
            g_video_dec_info_ptr->seek_result_frame_number = 1;
            video_dec_clr_buffer(0, 1);
            result = video_dec_put_frame_to_buffer();
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }
            /* get frame and start to decode */
            result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }
            /* decode the first frame and write to register */		
            result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_TRUE);
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }
        }
#endif /*__VIDEO_EDITOR__*/
    }
    else  /* video_file_get_decode_type() == DECODE_TYPE_UNKNOW || total_frames == 0 */
    {
        //g_video_dec_info_ptr->incall = comm_init_input->incall;
        g_video_dec_info_ptr->audio_enable = comm_init_input->audio_enable;
        result = video_dec_struct_init(g_video_dec_info_ptr, DECODE_TYPE_UNKNOW, 0, 0, KAL_FALSE);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
        
        video_dec_disable_irq(video_file_get_decode_type());
        video_dec_stop_av();

        /* initialize play time information */
        result = video_dec_initialize_play_time();
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        if(total_frames == 0)
        {
            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_NOT_SUPPORT;
            VIDEO_ASSERT(0);
            return NO_VISUAL_TRACK;
        }

        ASSERT(comm_init_input->video_dec_callback != NULL);
    #if defined(__VIDEO_EDITOR__)
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            comm_init_input->video_dec_callback(VIDEO_EDITOR_DEC_EVENT_NO_TRACK);
        }
        else
    #endif /*__VIDEO_EDITOR__*/
        {
            /* response not support to clip initailize */
            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_NOT_SUPPORT;
            VIDEO_ASSERT(0);
            return VIDEO_ERROR;
        }
    }

    return MEDIA_STATUS_OK;
}


/* This function initialize the video decode module.
 * @param init_input MP4DEC_INIT_STRUCT
 * @param max_width maximum width that application wishes ti support
 * @param max_height maximum height that application wishes ti support
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_editor_initialize(MP4DEC_INIT_STRUCT * init_input)
{
    MEDIA_STATUS_CODE result;

    /* prepare parameter and calls common initialize */
    result = video_dec_comm_initialize(init_input);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    /* set play back time base as 0 */
    MP4_SetPlaybackTimerBase(vid_get_audio_parser(), 0, KAL_TRUE);

#ifdef VIDEO_DEC_YUV_MODE
    {
        /* open file for YUV mode */
        FSAL_Status FSAL_STATUS;
        kal_wchar   store_name[20]=L"x:\\dec_out.yuv";
        store_name[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
        /*store_name[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);*/
        FSAL_STATUS = FSAL_Open(&FSAL_VIDEO_YUV_FILE, store_name, FSAL_WRITE);
        if (FSAL_STATUS != FSAL_OK)
        {
            ASSERT(0);
        }
    }
#endif /*VIDEO_DEC_YUV_MODE*/

    return MEDIA_STATUS_OK;
}


/* Open the video decode process.
* When call "video_dec_initialize" API, this function is also called.
* @param  pstMp4Parser The handle of mp4 parser
* @param  pstFSAL The handle of file abstract layer
* @return Media status, which is based MEDIA_STATUS_CODE structure.
*/
MEDIA_STATUS_CODE video_dec_open(STMp4Parser * pstMp4Parser,
                                 STFSAL * pstFSAL,
                                 kal_uint32 max_width,
                                 kal_uint32 max_height)
{
    VIDEO_DEC_BUFFER_CB_STRUCT cb_info;
    DECODE_TYPE decode_type;

    g_video_dec_status.running = KAL_TRUE;

#ifdef DRV_MP4_V1
    g_video_enc_info_ptr = NULL;
#endif /*DRV_MP4_V1*/

    /* get decoder information memory */
#if defined(__VIDEO_EDITOR__)
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
         if (VIDEO_EDITOR_DATA.is_new_video == KAL_TRUE)
         {
            g_video_dec_info_ptr = (VIDEO_DEC_STRUCT *)extmem_get_buffer(sizeof(VIDEO_DEC_STRUCT));
         }
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
         g_video_dec_info_ptr = (VIDEO_DEC_STRUCT *)extmem_get_buffer(sizeof(VIDEO_DEC_STRUCT));
    }

    /* Initialize buffer and AV setting according to different scenario */
#if defined(__VIDEO_EDITOR__)
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        cb_info.scenario = VIDEO_DEC_BUFFER_SCENARIO_EDITOR;
        cb_info.callback = &g_video_dec_info_ptr->video_dec_callback;
        cb_info.event_id = VIDEO_EDITOR_DEC_EVENT_BUFFER_EMPTY;
        video_dec_config_buffer(cb_info);
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
#ifdef PGDL_SUPPORT
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL)
        {
            cb_info.scenario = VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE;
            cb_info.callback = &g_video_dec_info_ptr->video_dec_callback;
            cb_info.event_id = VIDEO_DEC_EVENT_BUFFER_EMPTY;
        }
        else
#endif
        {
        cb_info.scenario = VIDEO_DEC_BUFFER_SCENARIO_FILE;
        cb_info.callback = &g_video_dec_info_ptr->video_dec_callback;
        cb_info.event_id = VIDEO_DEC_EVENT_BUFFER_EMPTY;
        }
        video_dec_config_buffer(cb_info);
    }

    /* store the max width and height for the current application. (clip play has this input)*/
    g_video_dec_info_ptr->max_width = max_width;
    g_video_dec_info_ptr->max_height = max_height;
    g_video_dec_info_ptr->play_speed = 100;
    g_video_dec_info_ptr->pMp4Parser = pstMp4Parser;
    g_video_dec_info_ptr->pstFSAL = pstFSAL;
    g_video_dec_info_ptr->seek_by_time = KAL_FALSE;
    g_video_dec_info_ptr->seek_time = 0;
    g_video_dec_info_ptr->current_play_time = 0;
    g_video_dec_info_ptr->display_enable = KAL_TRUE;
    g_video_dec_info_ptr->prev_display_enable = KAL_FALSE;
    g_video_dec_info_ptr->b_display_fail = KAL_FALSE;	
    g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_OK;
    g_video_dec_status.FSAL_STATUS = FSAL_OK;
    g_video_dec_status.PARSE_STATUS = MP4_PARSER_OK;
    g_video_dec_status.noVideoTrack = KAL_FALSE;
    g_video_dec_status.noAudioTrack = KAL_FALSE;

    if (g_video_dec_gpt_refresh_handle== 0)
        GPTI_GetHandle(&g_video_dec_gpt_refresh_handle);

    decode_type = video_file_get_decode_type();
    switch(decode_type)
    {
    case DECODE_TYPE_MPEG4:
    case DECODE_TYPE_H263:
        g_video_dec_info_ptr->p_driver = &g_video_dec_mp4_driver;
        break;	
    default:
        g_video_dec_info_ptr->p_driver = NULL;
        //EXT_ASSERT(0, decode_type, 0, 0);		
        break;		
    }

    if(g_video_dec_info_ptr->p_driver != NULL)
    {
        /* Initialize video decode memory (hardware, frame buffer ...)*/
        #ifdef __TEARING_REDUCTION_FB_IN_INTSRAM__
            g_video_dec_info_ptr->p_driver->video_dec_open(max_width, max_height, KAL_TRUE);	
        #else
            g_video_dec_info_ptr->p_driver->video_dec_open(max_width, max_height, KAL_FALSE);	
        #endif   	 
    }

    g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_OPEN;

    return MEDIA_STATUS_OK;
}

/* Init the video decode av information.
* When call "video_dec_initialize" API, this function is also called.
* @param b_audio_enable enable audio or not
* @return Media status, which is based MEDIA_STATUS_CODE structure.
*/
MEDIA_STATUS_CODE video_dec_init_av(kal_bool b_audio_enable)
{
    kal_uint32 video_timebase;
    kal_uint32 dsp_timescale;
    kal_uint32 audio_playback_delay;

    /* Get video and audio(DSP) time base */
    g_video_dec_status.PARSE_STATUS = MP4_GetMediaTimeScale(g_video_dec_info_ptr->pMp4Parser, &video_timebase, MP4_TRACK_VIDEO);
    if ((g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK) && (g_video_dec_status.PARSE_STATUS!=MP4_PARSER_NO_SUCH_TRACK))
    {
        VIDEO_ASSERT(0);
        g_video_dec_info_ptr = NULL;
        return MP4_PARSER_ERROR;
    }

    dsp_timescale = Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(
                     MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(g_video_dec_info_ptr->pMp4Parser)), MP4_Audio_GetFreqIndex(g_video_dec_info_ptr->pMp4Parser));
    audio_playback_delay = Media_A2V_GetAudioPlaybackDelay(
                     MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(g_video_dec_info_ptr->pMp4Parser)));

    /* Initialize buffer and AV setting according to different scenario */
#if defined(__VIDEO_EDITOR__)
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        video_dec_set_av_timebase(VIDEO_DEC_AV_COMMON, video_timebase, dsp_timescale, audio_playback_delay);
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
        if (b_audio_enable == KAL_TRUE)
        {
            video_dec_set_av_timebase(VIDEO_DEC_AV_AUDIO, video_timebase, dsp_timescale, audio_playback_delay);
        }
        else
        {
            video_dec_set_av_timebase(VIDEO_DEC_AV_GPT, video_timebase, dsp_timescale, audio_playback_delay);
        }
    }

    return MEDIA_STATUS_OK;
}


/* Check stop + play conditions
 * @param None 
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
static MEDIA_STATUS_CODE video_dec_resume_check(void)
{
    MEDIA_STATUS_CODE result;
    kal_uint64 seek_frame_time; 
    kal_uint64 seek_frame_time_comm_base;
    kal_uint64 curr_play_time_comm_base;
    kal_uint64 gaurd_time_common_base;
    kal_uint64 play_time;
    kal_uint32 dec_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
    
    g_video_dec_info_ptr->seek_frame_number = dec_frame_no;
    g_video_dec_info_ptr->seek_result_frame_number = dec_frame_no;
    /* get seek time from video frame number */
    g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser,
                                                        (g_video_dec_info_ptr->seek_result_frame_number - 1), //id = 1~, reviewed
                                                        &seek_frame_time,
                                                        MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        VIDEO_ASSERT(0);
#ifdef PGDL_SUPPORT
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
            kal_prompt_trace(MOD_MED, "MP4_GetDecodeTime Error: %d, %d\n", g_video_dec_status.PARSE_STATUS, g_video_dec_info_ptr->seek_result_frame_number);
        }
#endif
        return MP4_PARSER_ERROR;
    }

    // im mp4 case, force it to disaply the reconstruct address instead of deblock address, so that the later refresh one will be correct
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_FORCE_FAST_DECODE, KAL_TRUE);
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_FORCE_FAST_DECODE, KAL_FALSE);	
    seek_frame_time_comm_base = VIDEO_ANYBASE_TO_COMMBASE(seek_frame_time, g_video_dec_info_ptr->video_time_scale);
    curr_play_time_comm_base = VIDEO_ANYBASE_TO_COMMBASE(g_video_dec_info_ptr->current_play_time, 1000);
    gaurd_time_common_base = VIDEO_ANYBASE_TO_COMMBASE(1000, 1000);

    //check play and seek time first
    if(seek_frame_time_comm_base < curr_play_time_comm_base)
    {
        if(dec_frame_no != g_video_dec_info_ptr->total_frames_in_file)
        {
            if((curr_play_time_comm_base - seek_frame_time_comm_base) > gaurd_time_common_base)	
            {
                EXT_ASSERT(0, dec_frame_no, g_video_dec_info_ptr->total_frames_in_file, g_video_dec_info_ptr->current_play_time);
            }
            else
            {
                // the curernt play time may be a little shift (really start time is align to audio frame)
                curr_play_time_comm_base = seek_frame_time_comm_base;	   
            }
        }
    }

    if(curr_play_time_comm_base >= g_video_dec_info_ptr->video_duration)
    {
        g_video_dec_info_ptr->b_dummy_isr = KAL_FALSE;
        g_video_dec_info_ptr->video_end = KAL_TRUE;
        video_dec_display();
        return MEDIA_STATUS_OK;
    }
        
    if((seek_frame_time_comm_base > curr_play_time_comm_base) && 
       ( (seek_frame_time_comm_base - curr_play_time_comm_base) > gaurd_time_common_base))
    {
        /* do not adjust time, and do not decode the current frame */
         g_video_dec_info_ptr->seek_time = curr_play_time_comm_base;
         g_video_dec_info_ptr->b_dummy_isr = KAL_TRUE;
         g_video_dec_info_ptr->prev_display_enable = KAL_TRUE;
         video_dec_prev_display();
    }
    else if(seek_frame_time_comm_base >= curr_play_time_comm_base)
    {
        /* adjust time and play the current frame */
        g_video_dec_info_ptr->seek_time = seek_frame_time_comm_base;
        /* set play back time base, if audio enable, play time is got from this time base */
        MP4_SetPlaybackTimerBase(vid_get_audio_parser(),
                                                  (kal_uint32)VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->seek_time, 1000),
                                                 KAL_TRUE);
        /*obtain Video play_time, if audio is not enable, play time is got from this time base */
        result = video_dec_translate_av_time((kal_uint32)VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->seek_time, 
                                                                        g_video_dec_info_ptr->video_time_scale),
                                             &play_time); 
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_PLAY_TIME, play_time);
        g_video_dec_info_ptr->b_dummy_isr = KAL_FALSE;
        video_dec_display();
    }
    else
    {
        /* seek_frame_time_comm_base < curr_play_time_comm_base */
         /* do not adjust time and play the current frame */
         g_video_dec_info_ptr->seek_time = curr_play_time_comm_base;
         g_video_dec_info_ptr->b_dummy_isr = KAL_TRUE;
         g_video_dec_info_ptr->prev_display_enable = KAL_TRUE;
         video_dec_prev_display();
         g_video_dec_info_ptr->b_dummy_end = KAL_TRUE;
    }

    if(dec_frame_no == g_video_dec_info_ptr->total_frames_in_file )
    {
        g_video_dec_info_ptr->video_end = KAL_TRUE;
    }
    else
    {
        g_video_dec_info_ptr->video_end = KAL_FALSE;
    }
    
    if (g_video_dec_info_ptr->seek_result_frame_number < g_video_dec_info_ptr->total_frames_in_file)
    {
        /* still has next frame, not the last frame */
        g_video_dec_status.PARSE_STATUS =
            MP4_GetDecodeTime_Next(g_video_dec_info_ptr->pMp4Parser,
                                   &g_video_dec_info_ptr->seek_next_frame_time,
                                   MP4_TRACK_VIDEO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                kal_prompt_trace(MOD_MED, "MP4_GetDecodeTime_Next Err: %d, %d\n", g_video_dec_status.PARSE_STATUS, g_video_dec_info_ptr->seek_next_frame_time);
            }
#endif
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }

        /* also translate seek_next_frame_time to common base */
        g_video_dec_info_ptr->seek_next_frame_time =
            VIDEO_ANYBASE_TO_COMMBASE(g_video_dec_info_ptr->seek_next_frame_time,
                                      g_video_dec_info_ptr->video_time_scale);
    }
    else
    {
        /* the last frame */
        g_video_dec_info_ptr->seek_next_frame_time = g_video_dec_info_ptr->video_duration;
    }
    
    if(g_video_dec_info_ptr->b_dummy_end == KAL_FALSE)
    {
        g_video_dec_info_ptr->seek_next_frame_time = seek_frame_time_comm_base;    
    }

    return MEDIA_STATUS_OK;
}


/* Common play function for play and clip play
 * @param audio_frame_no The related audio frame that related to seek video frame. If audio is not enable, don't care "audio_frame_no" parameter!!
 * @param video_dec_callback video callback function when driver want to notify MED or upper layer.
 * @param incall it is incall(clip_play) or not(play)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
static MEDIA_STATUS_CODE video_dec_comm_play(kal_uint32 * audio_frame_no, void (*video_dec_callback)(kal_uint8 event))
{
    kal_uint32 frame_length;
    kal_uint32 prev_frame_duration;
    kal_uint8 *frame_addr;
    kal_uint32 frame_duration = 0;
    MEDIA_STATUS_CODE result;
    kal_uint64 seek_time_video_scale_based;    //Should change as kal_uint64
    kal_uint64 audio_decode_time;                     //Should change as kal_uint64
    kal_uint32 audio_frame_number;
    kal_uint64 decode_time;
    kal_uint64 current_play_time;
    kal_uint8 recheck_count;
    kal_bool audio_exist = KAL_TRUE;
    kal_bool video_play = KAL_TRUE;
    kal_bool audio_end = KAL_FALSE;
    kal_uint32 dec_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
    kal_uint32 hdr_parse_frames_no;	

    /* The time is already set by seek function */
    current_play_time = g_video_dec_info_ptr->current_play_time;
    g_video_dec_info_ptr->video_dec_callback = video_dec_callback;

    /*To guarantee all decode process is done*/
    video_dec_internal_stop();

    g_video_dec_info_ptr->b_dummy_isr = KAL_FALSE;
    g_video_dec_info_ptr->b_dummy_end = KAL_FALSE;
    if (g_video_dec_info_ptr->stage == VIDEO_DEC_STAGE_STOP)
    {
         result = video_dec_resume_check();
         if(result != MEDIA_STATUS_OK)
             return result;
    }
    else
    {
        /* display the first initialize frame for play */
        video_dec_display();
    }


    /* seek done always set video end as false, so this is not called just after seek done */
    if ((g_video_dec_info_ptr->video_end == KAL_TRUE) ||
    	  (dec_frame_no == g_video_dec_info_ptr->total_frames_in_file))
    {
        /*Video end, only audio*/
        g_video_dec_info_ptr->seek_by_time = KAL_TRUE;
        g_video_dec_info_ptr->video_end = KAL_TRUE;

        /* seek time is got from current time. seek time is in common base */
        g_video_dec_info_ptr->seek_time = VIDEO_ANYBASE_TO_COMMBASE(current_play_time, 1000);
    }

    /* seek_by_time is true when 1. previous seek to video end. 2. previous check video end set it as true */
    if ((g_video_dec_info_ptr->seek_by_time == KAL_TRUE) && (g_video_dec_info_ptr->b_dummy_isr == KAL_FALSE))
    {
        /* seek_by_time is happened when video end */
        g_video_dec_info_ptr->video_end = KAL_TRUE;

        /* both seek time and audio time in common base */
        if (g_video_dec_info_ptr->seek_time < g_video_dec_info_ptr->audio_duration)
        {
            /* seek time is longer than video duration , but shorter than audio duration */
            /*Pure audio seek, get audio frame no according to seek time */
            kal_uint64 seek_time_ms;
            seek_time_ms = VIDEO_ANYBASE_TO_MS(g_video_dec_info_ptr->seek_time, VIDEO_COMMON_TIME_BASE);
            g_video_dec_info_ptr->seek_by_time = KAL_FALSE;
            g_video_dec_status.PARSE_STATUS =
                    MP4_Audio_TimeToSampleNo(g_video_dec_info_ptr->pMp4Parser, seek_time_ms, /*Unit: ms*/
                                         audio_frame_no);
            if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
            {
                VIDEO_ASSERT(0);
#ifdef PGDL_SUPPORT
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                    kal_prompt_trace(MOD_MED, "MP4_Audio_TimeToSampleNo Err: %d, %d\n", g_video_dec_status.PARSE_STATUS, seek_time_ms);
                }
#endif
                return MP4_PARSER_ERROR;
            }

        #if defined(__VIDEO_EDITOR__)
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                ASSERT(0);
            }
            else
        #endif /*__VIDEO_EDITOR__*/
            {
                video_dec_complete();
            }

            /* audio interrupt should count (in order to get time information) */
            video_dec_set_enable_av_callback(NULL);

            return MEDIA_STATUS_OK;
        }
        else   /* g_video_dec_info_ptr->seek_time < g_video_dec_info_ptr->audio_duration */
        {
            /* seek time is longer than both video duration and audio duration */
        #if defined(__VIDEO_EDITOR__)
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                ASSERT(0);
            }
            else
        #endif /*__VIDEO_EDITOR__*/
            {
                video_dec_complete();
            }

            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_SEEK_AUDIO_END;
#ifdef PGDL_SUPPORT
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                    kal_prompt_trace(MOD_MED, "SeekTime > AudioDuration\n");
                }
#endif
            return VIDEO_ERROR;
        }
    }

    if((g_video_dec_info_ptr->stage != VIDEO_DEC_STAGE_SEEK) && (g_video_dec_info_ptr->stage != VIDEO_DEC_STAGE_STOP))
    {
        VIDEO_ASSERT(0);
#ifdef PGDL_SUPPORT
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
            kal_prompt_trace(MOD_MED, "VIDEO_DEC_FUNC_STATE_ERROR: %d\n", g_video_dec_info_ptr->stage);
        }
#endif
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FUNC_STATE_ERROR;
        return VIDEO_ERROR;
    }

    if (g_video_dec_info_ptr->seek_result_frame_number < g_video_dec_info_ptr->total_frames_in_file)
    {
        /* reset other parameters also */
        result = video_dec_struct_init(g_video_dec_info_ptr, g_video_dec_info_ptr->decode_type,
                                         g_video_dec_info_ptr->total_frames_in_file, g_video_dec_info_ptr->seek_result_frame_number, KAL_TRUE);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        /* prepare bitstream buffer */
        video_dec_clr_buffer(g_video_dec_info_ptr->seek_result_frame_number, g_video_dec_info_ptr->total_frames_in_file+1);
        result = video_dec_put_frame_to_buffer();
        if (result != MEDIA_STATUS_OK)
        {
#ifdef PGDL_SUPPORT
           if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
               kal_prompt_trace(MOD_MED, "video_dec_put_frame_to_buffer Err: %d\n", result);
           }
#endif
            VIDEO_ASSERT(0);
            return result;
        }

        if(g_video_dec_info_ptr->b_dummy_isr == KAL_FALSE)
        {
            //error handling, for frame that parse fail  
            //Prepare the HW register and bistream of current frame
            for (recheck_count = 0; recheck_count < 50; recheck_count++)
            {
                /* try to parse one success frame */
                result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
                frame_duration = prev_frame_duration;
                if (result != MEDIA_STATUS_OK)
                {
#ifdef PGDL_SUPPORT
                    if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                        kal_prompt_trace(MOD_MED, "video_dec_get_next_frame Err: %d\n", result);
                    }
#endif
                    VIDEO_ASSERT(0);
                    return result;
                }
        
                result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);
                if (result == MEDIA_STATUS_OK)
                {
                    break;
                }
                else
                {
#ifdef PGDL_SUPPORT
                    if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                        kal_prompt_trace(MOD_MED, "mpeg4_decode_main Err: %d\n", result);
                    }
#endif
                    /* parse next frame */
                    VIDEO_ASSERT(0);
                }
            }
            if (result != MEDIA_STATUS_OK)
            {
#ifdef PGDL_SUPPORT
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                    kal_prompt_trace(MOD_MED, "All recheck fail: %d\n", result);
                }
#endif
                /* all recheck fail */
                VIDEO_ASSERT(0);
                return result;
            }
        
            if (recheck_count != 0)
            {
                //force decoder ignore the error frame
                g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER, 
                                                                                     g_video_dec_info_ptr->seek_result_frame_number+recheck_count);	
                /* Get real next frame time */
                g_video_dec_status.PARSE_STATUS =
                    MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser,
                                                    g_video_dec_info_ptr->seek_result_frame_number+recheck_count, //id = 1~, reviewed
                                      &g_video_dec_info_ptr->seek_next_frame_time,
                                      MP4_TRACK_VIDEO);
    
                if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
                {
#ifdef PGDL_SUPPORT
                    if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                        kal_prompt_trace(MOD_MED, "MP4_GetDecodeTime after recheck Error: %d, %d\n", 
                                                 g_video_dec_status.PARSE_STATUS, 
                                                 g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER));
                    }
#endif
                    VIDEO_ASSERT(0);
                    return MP4_PARSER_ERROR;
                }
    
                /* also translate seek_next_frame_time to common base */
                g_video_dec_info_ptr->seek_next_frame_time =
                    VIDEO_ANYBASE_TO_COMMBASE(g_video_dec_info_ptr->seek_next_frame_time,
                                              g_video_dec_info_ptr->video_time_scale);
            }
            /* write register to decode the parsed frame */
            g_video_dec_info_ptr->p_driver->video_dec_start();
        }

        /* Pre-parse the next frame */
        hdr_parse_frames_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HDR_PARSE_FRAME_NUMER);
        dec_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
        if (hdr_parse_frames_no < g_video_dec_info_ptr->total_frames_in_file)
        {
            /* Not the last frame */
            result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
            if (result != MEDIA_STATUS_OK)
            {
#ifdef PGDL_SUPPORT
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                    kal_prompt_trace(MOD_MED, "video_dec_get_next_frame after recheck Err: %d, %d\n", g_video_dec_status.PARSE_STATUS, result);
                }
#endif
                VIDEO_ASSERT(0);
                return result;
            }

            /* pre-parse the next frame */
            result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);			
            if (result != MEDIA_STATUS_OK)
            {
#ifdef PGDL_SUPPORT
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                    kal_prompt_trace(MOD_MED, "mpeg4_decode_main after recheck Err2: %d, %d\n", g_video_dec_status.PARSE_STATUS, result);
                }
#endif
                /* treat the error frame as non-coded */
                VIDEO_ASSERT(0);
            }
        }
        else if((dec_frame_no == g_video_dec_info_ptr->total_frames_in_file) && (g_video_dec_info_ptr->b_dummy_isr == KAL_FALSE))
        {
            /* previous decode one is the last frame. Treat this case as play done */
            video_play = KAL_FALSE;

            ASSERT(g_video_dec_info_ptr->video_dec_callback != NULL);
            g_video_dec_info_ptr->video_end = KAL_TRUE;
        #if defined(__VIDEO_EDITOR__)
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                ASSERT(0);
            }
            else
        #endif /*__VIDEO_EDITOR__*/
            {
                video_dec_complete();
            }
        }
        /*else hdr_parse_frames_no == total_frames_in_file
        /  but dec_frames_no < total_frames_in_file, just let it play*/
    }
    else if(g_video_dec_info_ptr->b_dummy_isr == KAL_FALSE) /*(g_video_dec_info_ptr->seek_result_frame_number < g_video_dec_info_ptr->total_frames_in_file)*/
    {
        video_dbg_trace(MP4_DEC_SEEK_END_FRAME, video_get_current_time());

        video_play = KAL_FALSE;
        /*send complete message!! */
        ASSERT(g_video_dec_info_ptr->video_dec_callback != NULL);
        g_video_dec_info_ptr->video_end = KAL_TRUE;
    #if defined(__VIDEO_EDITOR__)
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            ASSERT(0);
        }
        else
    #endif /*__VIDEO_EDITOR__*/
        {
            video_dec_complete();
        }
    }

    if (g_video_dec_info_ptr->audio_enable == KAL_TRUE)
    {
        /* should align time to audio frame number */
        dec_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
        if (dec_frame_no < g_video_dec_info_ptr->total_frames_in_file)
        {
           
            seek_time_video_scale_based = VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->seek_time,
                                                                                                         g_video_dec_info_ptr->video_time_scale);
                   
            /* video not end. use video time to seek to audio frame no */
            g_video_dec_status.PARSE_STATUS =
                MP4_Audio_Seek_To_Video(g_video_dec_info_ptr->pMp4Parser, seek_time_video_scale_based,
                                        &audio_frame_number);
        }
        else
        {
            /* video end, use seek time to seek audio frame directly */
            kal_uint64 seek_time_ms;
            seek_time_ms = VIDEO_ANYBASE_TO_MS(g_video_dec_info_ptr->seek_time, VIDEO_COMMON_TIME_BASE);
            g_video_dec_status.PARSE_STATUS =
                MP4_Audio_TimeToSampleNo(g_video_dec_info_ptr->pMp4Parser, seek_time_ms, &audio_frame_number);
        }

        if (g_video_dec_status.PARSE_STATUS == MP4_PARSER_NO_SUCH_TRACK)
        {
            /*No audio track*/
            audio_frame_number = 0;
            *audio_frame_no = 0;
            audio_decode_time = 0;
            audio_exist = KAL_FALSE;
        }
        else if (g_video_dec_status.PARSE_STATUS == MP4_PARSER_NO_SUCH_SAMPLE)
        {
            /* audio end */
            audio_frame_number = 0;
            *audio_frame_no = 0;
            audio_decode_time = 0;
            audio_end = KAL_TRUE;
            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_SEEK_AUDIO_END;
        }
        else
        {
            *audio_frame_no = audio_frame_number;
            if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
            {
#ifdef PGDL_SUPPORT
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                    kal_prompt_trace(MOD_MED, "Err after g_video_dec_info_ptr->audio_enable == KAL_TRUE: %d, %d, %d\n", 
                                             g_video_dec_status.PARSE_STATUS, 
                                             g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER),
                                             g_video_dec_info_ptr->total_frames_in_file);
                }
#endif
                VIDEO_ASSERT(0);
                return MP4_PARSER_ERROR;
            }

            /*Get Audio duration from the seeked audio frame no */
            g_video_dec_status.PARSE_STATUS =
                MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser, audio_frame_number, &audio_decode_time,
                                  MP4_TRACK_AUDIO);
            if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
            {
#ifdef PGDL_SUPPORT
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                    kal_prompt_trace(MOD_MED, "MP4_GetDecodeTime Err after audio_enable==TRUE: %d, %d, %d\n", 
                                             g_video_dec_status.PARSE_STATUS, 
                                             g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER),
                                             g_video_dec_info_ptr->total_frames_in_file);
                }
#endif
                VIDEO_ASSERT(0);
                return MP4_PARSER_ERROR;
            }
            audio_decode_time = VIDEO_ANYBASE_TO_COMMBASE(audio_decode_time,
                                                          g_video_dec_info_ptr->audio_time_scale);
        }

        
        //Get (Next Video - audio time) duration
        if ((audio_exist) && (audio_end == KAL_FALSE) && (video_play == KAL_TRUE))
        {
            /* with audio */
            ASSERT(g_video_dec_info_ptr->seek_next_frame_time >= audio_decode_time);

            /* translate time to av ticks */
            decode_time = VIDEO_COMMBASE_TO_ANYBASE(
            (g_video_dec_info_ptr->seek_next_frame_time - audio_decode_time),
            g_video_dec_info_ptr->video_time_scale);
            video_dec_translate_av_time(decode_time, &decode_time);
            /* Rita add,
                1. audio frame and seek time may be not the same
                2. seek and play may re-check several frames  */
            MP4_SetPlaybackTimerBase(vid_get_audio_parser(),
                                                      (kal_uint32)VIDEO_COMMBASE_TO_ANYBASE(audio_decode_time, 1000),
                                                      KAL_TRUE);
        }
        else if (video_play == KAL_TRUE)
        {
            /* with no audio. audio duration < video duration. and play beyond audio duration */
            ASSERT(g_video_dec_info_ptr->seek_next_frame_time >= g_video_dec_info_ptr->seek_time);
            decode_time = VIDEO_COMMBASE_TO_ANYBASE(
                    (g_video_dec_info_ptr->seek_next_frame_time - g_video_dec_info_ptr->seek_time),
                    g_video_dec_info_ptr->video_time_scale);
            video_dec_translate_av_time(decode_time, &decode_time);
           
            /* Rita add,
                1. audio frame and seek time may be not the same
                2. seek and play may re-check several frames  */
            MP4_SetPlaybackTimerBase(vid_get_audio_parser(),
                                                      (kal_uint32) VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->seek_time, 1000),
                                                      KAL_TRUE);
        }
        else
        {
            /* not play video. audio also end */
            decode_time = 0;
        }

        /* set dsp according to different audio and video condition */
        if (video_play)
        {
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
            video_set_dec_isr(video_file_get_decode_type());
            video_dec_set_frametime((kal_uint32)decode_time, KAL_TRUE);
            g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_DUMMY_ISR, g_video_dec_info_ptr->b_dummy_isr);
            g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_DUMMY_END, g_video_dec_info_ptr->b_dummy_end);
            video_enable_dec_isr(video_file_get_decode_type());
#endif
            g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_PLAY;
        }
        if (audio_end == KAL_FALSE)
        {
            if (!video_play)
            {
                // video end. audio not end
                video_dec_disable_irq(video_file_get_decode_type());
                video_dec_set_enable_av_callback(NULL);
            }
            return MEDIA_STATUS_OK;
        }
        else
        {
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
               kal_prompt_trace(MOD_MED, "Audio & Video Both End\n");
            }
#endif
            /* audio and video both end */
            VIDEO_ASSERT(0);
            return VIDEO_ERROR;
        }
    }    /*AUDIO ENABLE*/
    else /*g_video_dec_info_ptr->audio_enable == KAL_TRUE*/
    {
        /*audio not enable */
        /* do not need to align audio frame time. use video frame time directly */
        decode_time = VIDEO_COMMBASE_TO_ANYBASE(
                  (g_video_dec_info_ptr->seek_next_frame_time - g_video_dec_info_ptr->seek_time),
                   g_video_dec_info_ptr->video_time_scale);

        /* translate and set sync time*/
        video_dec_translate_av_time(decode_time, &decode_time);
         /* Rita add,
                1. audio frame and seek time may be not the same
                2. seek and play may re-check several frames  */
         MP4_SetPlaybackTimerBase(vid_get_audio_parser(),
                                                   (kal_uint32) VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->seek_time, 1000),
                                                   KAL_TRUE);
#if 0                                                   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        video_set_dec_isr(video_file_get_decode_type());
        video_dec_set_frametime((kal_uint32)decode_time, KAL_FALSE);
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_DUMMY_ISR, g_video_dec_info_ptr->b_dummy_isr);
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_DUMMY_END, g_video_dec_info_ptr->b_dummy_end);
        video_enable_dec_isr(video_file_get_decode_type());
#endif
        g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_PLAY;
        return MEDIA_STATUS_OK;
    }
}


/* This function is used to check video file is qualified or not.
 * @param  pstMp4Parser mp4 parser handle
 * @param  pstFSAL FSAL handle
 * @param max_duration Allowed maximum video duration! If the video duration in this video file > input "max_duration", this function will VIDEO_DEC_LONG_DURATION.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
static MEDIA_STATUS_CODE video_dec_clip_check_media_file(STMp4Parser * pstMp4Parser, STFSAL * pstFSAL,
                                                  kal_uint32 max_duration_ms)
{
    MEDIA_STATUS_CODE result;

    kal_uint8 *frame_addr;
    kal_uint32 frame_length;
    kal_uint32 prev_frame_duration;
    kal_uint64 max_duration;

    /* check video duration */
    max_duration = VIDEO_ANYBASE_TO_COMMBASE((kal_uint64)max_duration_ms, 1000);
    if (g_video_dec_info_ptr->video_duration > max_duration)
    {
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_LONG_DURATION;

        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    /* prepare bitstream frame to buffer */
    g_video_dec_info_ptr->seek_frame_number = 1;
    g_video_dec_info_ptr->seek_result_frame_number = 1;
    result = video_dec_struct_init(g_video_dec_info_ptr, g_video_dec_info_ptr->decode_type, 
                                     g_video_dec_info_ptr->total_frames_in_file, 0, KAL_FALSE);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    /* prepare bitstream buffer */
    video_dec_clr_buffer(0, 1);
    result = video_dec_put_frame_to_buffer();
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    /* get and decode the first frame */
    result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }
    result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_TRUE);	
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    g_video_dec_info_ptr->width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH);
    g_video_dec_info_ptr->height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT);
    g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH);
    g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT);	
    /* check video size is allowed */
    if (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height
            > (g_video_dec_info_ptr->max_width * g_video_dec_info_ptr->max_height))
    {
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FRAME_SIZE_ERROR;

        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    return MEDIA_STATUS_OK;
}


/* Use seek time to get seeked frame no and its next frame time
 * @param curr_frame      input: current_frame, output: adjusted frame from curr_frame to the frame found in seek_time.
 * @param org_seek_time seek time. (Unit: comm time scale)
 * @param next_frame_time next frame start time (Unit: comm time scale)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
/*Unit: comm time scale*/
static MEDIA_STATUS_CODE video_dec_get_frame_with_time(kal_uint32 * curr_frame, kal_uint64 seek_time,
                                                kal_uint64 * next_frame_time)
{
    kal_uint64 next_video_time;

    kal_uint64 current_seek_time = seek_time;
    MEDIA_STATUS_CODE result;
    kal_uint64 frame_time;
    kal_uint32 dec_frame_no=0;	
    kal_uint64 play_time;	

    /* seek time = 0 maps to the first frame */
    if (current_seek_time == 0)
    {
        *curr_frame = 1;
        g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser, 1, &next_video_time,
                                                            MP4_TRACK_VIDEO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
            return MP4_PARSER_ERROR;

        /* translate next frame time to common base */
        *next_frame_time = VIDEO_ANYBASE_TO_COMMBASE(next_video_time, g_video_dec_info_ptr->video_time_scale);
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_PLAY_TIME, 0);;
        return MEDIA_STATUS_OK;
    }

    /* translate seek time from common base to video base */
    current_seek_time = VIDEO_COMMBASE_TO_ANYBASE(seek_time, g_video_dec_info_ptr->video_time_scale);
    g_video_dec_status.PARSE_STATUS = MP4_GetSampleNumber(g_video_dec_info_ptr->pMp4Parser, curr_frame, current_seek_time,
                                                          MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        if (g_video_dec_status.PARSE_STATUS == MP4_PARSER_NO_SUCH_SAMPLE)
        {
            /* seek time larger than video duration. Set the seeked frame no to the last one */
            g_video_dec_status.PARSE_STATUS = MP4_PARSER_OK;
            *curr_frame = g_video_dec_info_ptr->total_frames_in_file - 1;
        }
        else
        {
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }
    }

    /* get current frame decode time */
    g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser, *curr_frame, &frame_time,
                                                        MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        VIDEO_ASSERT(0);
        return MP4_PARSER_ERROR;
    }

    dec_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
    if ((*curr_frame<dec_frame_no)
            && (*curr_frame>(dec_frame_no - 10))
            && ((dec_frame_no + 1) < g_video_dec_info_ptr->total_frames_in_file))
    {
        /*Tricky to short the seek time*/
        /* If the seek frame is very close to the current decode frame. use current decode frame instead */
        kal_uint32 index;
        kal_uint64 frame_time_next;

        for (index = *curr_frame; index < (dec_frame_no - 1); index++)
        {
            g_video_dec_status.PARSE_STATUS =
                MP4_GetDecodeTime_Next(g_video_dec_info_ptr->pMp4Parser, &frame_time_next, MP4_TRACK_VIDEO);
            if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
            {
                VIDEO_ASSERT(0);
                return MP4_PARSER_ERROR;
            }
        }
        if (VIDEO_ANYBASE_TO_ANYBASE((frame_time_next - frame_time), g_video_dec_info_ptr->video_time_scale,
                                     1000) < 1000)
        {
            /* check the [decode frame time] - [seek frame time ] < 1sec */
            *curr_frame = dec_frame_no - 1;
            frame_time = frame_time_next;
        }
    }

    *curr_frame = ( *curr_frame)+1;
    next_video_time = frame_time;

    if (*curr_frame<g_video_dec_info_ptr->total_frames_in_file)
    {
       /* get next frame time when current frame is not the last frame */
        g_video_dec_status.PARSE_STATUS =
            MP4_GetDecodeTime_Next(g_video_dec_info_ptr->pMp4Parser, &next_video_time, MP4_TRACK_VIDEO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }
    }

    /*translate to common base */
    *next_frame_time = VIDEO_ANYBASE_TO_COMMBASE(next_video_time, g_video_dec_info_ptr->video_time_scale);

    /*Obtain Video play_time*/
    result = video_dec_translate_av_time(frame_time, &play_time);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_PLAY_TIME, play_time);

    return MEDIA_STATUS_OK;
}


/* Decode process is done. Notify upper layer and refresh when needed.
* @param  frame_no the frame that should be seek
* @param callback video callback function when driver want to notify MED or upper layer.
* @param seek_from_current_frame_mode. application can decide whether to seek from current frame or not
* @return  None
*/
MEDIA_STATUS_CODE video_dec_seek_by_frame(kal_uint32 frame_no, void (*callback)(kal_uint8 event),
                                          kal_bool seek_from_current_frame_mode)
{
    kal_uint32 frame_length;
    kal_uint8 *frame_addr;
    kal_uint32 first_frame_no;
    kal_uint32 prev_frame_duration;
    kal_uint32 dec_frame_number;
    kal_bool b_from_last_frame = KAL_FALSE;
    MEDIA_STATUS_CODE result;

    if (g_video_dec_info_ptr->stage == VIDEO_DEC_STAGE_CLOSE)
        return MEDIA_STATUS_OK;

    video_dbg_trace(MP4_DEC_TASK_SEEK, video_get_current_time());

    /*To guarantee all decode process is done*/
    video_dec_internal_stop();

    /* check seek frame is available */
    if (frame_no > g_video_dec_info_ptr->total_frames_in_file)
    {
        video_dbg_trace(MP4_DEC_SEEK_ERROR_PARAMETER, video_get_current_time());
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FUNC_PARAMETER_ERROR;
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }
    /*1~frame_no*/
    if ((frame_no > g_video_dec_info_ptr->total_frames_in_file) || (frame_no == 0))
    {
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FUNC_PARAMETER_ERROR;
        return VIDEO_ERROR;
    }

    dec_frame_number = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
    //video_dec_struct_init(g_video_dec_info_ptr, g_video_dec_info_ptr->decode_type, g_video_dec_info_ptr->total_frames_in_file, 0);
    g_video_dec_info_ptr->video_dec_callback = callback;
    g_video_dec_info_ptr->video_end = KAL_FALSE;

    /* Seek action should be from previous sync sample */
    g_video_dec_status.PARSE_STATUS =
        MP4_GetPrevSyncSampleNo(g_video_dec_info_ptr->pMp4Parser, (frame_no - 1), &first_frame_no, MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        VIDEO_ASSERT(0);
        return MP4_PARSER_ERROR;
    }
    if ((frame_no - 1) < first_frame_no)
    {
        /* no sync frame before seek frame */
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FUNC_PARAMETER_ERROR;
        return VIDEO_ERROR;
    }

#if defined(__VIDEO_EDITOR__)
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        if ((frame_no > dec_frame_number) && (dec_frame_number > first_frame_no)
             && (seek_from_current_frame_mode == KAL_TRUE))
        {
            /* sync frame -- dec_frame -- seek frame*/
            /* devode from dec_frame but not sync frame */
            first_frame_no = dec_frame_number;
            b_from_last_frame = KAL_TRUE;
        }
        else if (frame_no == dec_frame_number)
        {
            g_video_dec_info_ptr->video_dec_callback(VIDEO_EDITOR_DEC_EVENT_SEEK_DONE);
            g_video_dec_info_ptr->seek_frame_number = frame_no;
            g_video_dec_info_ptr->seek_result_frame_number = frame_no;
            //g_video_dec_info_ptr->prepare_frames_no = frame_no;
            //g_video_dec_info_ptr->hdr_parse_frames_no = frame_no;
            //g_video_dec_info_ptr->dec_frames_no = frame_no;
            //g_video_dec_info_ptr->dec_state = VIDEO_DEC_STATE_SEEK;
            result = video_dec_struct_init(g_video_dec_info_ptr, g_video_dec_info_ptr->decode_type, g_video_dec_info_ptr->total_frames_in_file, 
		                        dec_frame_number, b_from_last_frame);	
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }	                        
            g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_SEEK_FRAME_NUMBER, frame_no);
            return MEDIA_STATUS_OK;
        }
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
       if ((frame_no > dec_frame_number) && (dec_frame_number > first_frame_no)
               && (seek_from_current_frame_mode == KAL_TRUE))
       {
           /* sync frame -- dec_frame -- seek frame*/
            /* decode from dec_frame but not sync frame */
           first_frame_no = dec_frame_number;
            b_from_last_frame = KAL_TRUE;
       }
    }

#ifdef VIDEO_DEC_YUV_MODE
    first_frame_no = 0;
#endif /*VIDEO_DEC_YUV_MODE*/

    g_video_dec_info_ptr->seek_frame_number = frame_no;
    g_video_dec_info_ptr->seek_result_frame_number = frame_no;
    result = video_dec_struct_init(g_video_dec_info_ptr, g_video_dec_info_ptr->decode_type, g_video_dec_info_ptr->total_frames_in_file, 
		                        first_frame_no, b_from_last_frame);	
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }			                        
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_SEEK_FRAME_NUMBER, frame_no);
    //video_dec_info_ptr->dec_state = VIDEO_DEC_STATE_SEEK;

#if defined(__VIDEO_EDITOR__)
    /* prepare buffer */
    if (g_video_dec_info_ptr->seek_frame_number < g_video_dec_info_ptr->total_frames_in_file)   /*Jensen add for video editor, 95/10/11*/
    {
        video_dec_clr_buffer(first_frame_no, (g_video_dec_info_ptr->seek_frame_number+1));
    }
    else
    {
        video_dec_clr_buffer(first_frame_no, g_video_dec_info_ptr->seek_frame_number);
    }
#else /*!__VIDEO_EDITOR__*/
    /* prepare buffer */
    video_dec_clr_buffer(first_frame_no, g_video_dec_info_ptr->seek_frame_number);
#endif   /*__VIDEO_EDITOR__*/
    result = video_dec_put_frame_to_buffer();
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    /* get frame and start to decode */
    result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_FORCE_FAST_DECODE, KAL_TRUE);
    result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_TRUE);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }
    g_video_dec_info_ptr->p_driver->video_dec_start();

    /* set seek isr */
    video_set_seek_isr(video_file_get_decode_type());
    g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_SEEK;
    return MEDIA_STATUS_OK;
}


/* Guarantee all decode process is done
 * @param None
 * @return None
 */
static void video_dec_internal_stop(void)
{
    kal_uint32 dec_frame_no=0;
	
    video_dec_disable_irq(video_file_get_decode_type());
    video_dec_stop_av();
    video_dec_stop_refresh();

    if(g_video_dec_info_ptr->p_driver != NULL)
    {
        g_video_dec_info_ptr->p_driver->video_dec_wait_done();

        if ((g_video_dec_info_ptr->stage != VIDEO_DEC_STAGE_SEEK)
                && (g_video_dec_info_ptr->stage != VIDEO_DEC_STAGE_STOP)
                && (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_IS_DECODING) !=0))
                // (g_video_dec_info_ptr->dec_state != VIDEO_DEC_STATE_UNKOWN))
        {
            dec_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
            if(dec_frame_no != g_video_dec_info_ptr->total_frames_in_file)    
            {
                g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER, dec_frame_no+1);
            }

        }
    }
}


/* Decode process is done. Notify upper layer and refresh when needed.
* @param  None
* @return  None
*/
void video_dec_complete(void)
{
    if (g_video_dec_info_ptr->video_dec_callback != NULL)
    {
        g_video_dec_info_ptr->video_dec_callback(VIDEO_DEC_EVENT_COMPLETE);
    }
    /*For A>V, and TV out case*/
    video_dec_start_refresh();
}


///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Parameter functions                                           //
//////////////////////////////////////////////////////////////////

/* Setup the display width/height to driver
 * @param  disp_width   video display width in LCD
 * @param  disp_height  video LCD display height in LCD.
 * @return None.
 *
 */
static void video_set_disp_size(kal_uint16 disp_width, kal_uint16 disp_height)
{
    g_video_dec_info_ptr->disp_width = disp_width;
    g_video_dec_info_ptr->disp_height = disp_height;
}


/* Set stop frame
 * @param  disp_width   video display width in LCD
 * @param  disp_height  video LCD display height in LCD.
 * @return None.
 *
 */

void video_dec_set_seek_frame(kal_uint32 frame_number)
{
    /* for vdieo editor */
    g_video_dec_info_ptr->seek_frame_number = frame_number;
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_SEEK_FRAME_NUMBER, frame_number);	
}

void video_dec_set_stop_frame(kal_uint32 frame_number)
{
    g_video_dec_info_ptr->stop_frame_no = frame_number;
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_STOP_FRAME_NUMBER, frame_number);		
}




//////////////////////////////////////////////////////////////////////////////////////
//                                                ****************                                                      //
//                                                  API                                                                 //
//                                                 ****************                                                     //
//////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                                Display  functions                                            //
//////////////////////////////////////////////////////////////////

/* Open the image path(Resizer+LCD+ImageDMA+ImgProc), then this path will be conrolled by driver.
 * @param  data_input   MP4DEC_IMGPATH_STRUCT parameter should be prepared by MMI
 * @return None.
 */
void video_image_path_open(MP4DEC_IMGPATH_STRUCT * data_input)
{
#ifdef DRV_MP4_V1

    RESZ_CFG_STRUCT resizer_config;

    RESZ_PXL_CFG_STRUCT resizer_cfg;
    IMGDMA_IBW2_STRUCT idma2_para;
    IMGDMA_VDO_STRUCT video_dma_para;
    IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;
    kal_uint16 disp_width;
    kal_uint16 disp_height;
    kal_uint32 savedMask;
    kal_uint32 temp_height = 0;
    kal_uint32 temp_width = 0;
    kal_bool pan_en = 0;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    video_dbg_trace(MP4_DEC_TASK_IMG_HWPATH_OPEN, video_get_current_time());

    g_video_dec_info_ptr->width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH);
    g_video_dec_info_ptr->height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT);	
    g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH);
    g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT);		
    if (g_video_dec_info_ptr->real_width == 0) {
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_WIDTH, g_video_dec_info_ptr->width);
        g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->width;
    }
    if (g_video_dec_info_ptr->real_height == 0) {
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_HEIGHT, g_video_dec_info_ptr->height);
        g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->height;
    }

    savedMask = SaveAndSetIRQMask();
    //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    RestoreIRQMask(savedMask);

    /* Open ImageDMA */
    disp_width = data_input->disp_width;
    disp_height = data_input->disp_height;
    video_set_disp_size(data_input->disp_width, data_input->disp_height);
    /*VDO IMGDMA*/
    IMGDMA_Open(SCENARIO_MPEG_DECODE_ID);
    video_dma_para.dir = 0;
    video_dma_para.twice = 0;
    video_dma_para.restart = 0;
    video_dma_para.bs1 = 0;
    video_dma_para.bs2 = 0;
    video_dma_para.width = g_video_dec_info_ptr->width;
    video_dma_para.height = g_video_dec_info_ptr->height;
    video_dma_para.cb1 = NULL;
    video_dma_para.cb2 = NULL;
    g_video_dec_info_ptr->prev_display_enable = KAL_FALSE;
    IMGDMA_VdoConfig(&video_dma_para, 0, SCENARIO_MPEG_DECODE_ID);

    /* Init LCD */
    g_video_dec_info_ptr->lcd_id = data_input->lcd_data->lcd_id;

    if (data_input->force_lcd_hw_trigger == KAL_TRUE)
    {
        data_input->lcd_data->fb_update_mode = LCD_HW_TRIGGER_MODE;
    }
    else
    {
        if (get_lcd_hw_layer_rotate_value(data_input->lcd_data->hw_update_layer) == LCD_LAYER_ROTATE_NORMAL)
            data_input->lcd_data->fb_update_mode = LCD_DIRECT_COUPLE_MODE;
        else
            data_input->lcd_data->fb_update_mode = LCD_HW_TRIGGER_MODE;
    }
    config_lcd_hw_layer(data_input->lcd_data->hw_update_layer,
                        data_input->lcd_data->roi_offset_x + data_input->video_display_offset_x,
                        data_input->lcd_data->roi_offset_y + data_input->video_display_offset_y,
                        disp_width,
                        disp_height);
    //set_lcd_layer_roate(data_input->lcd_data->hw_update_layer,data_input->lcd_data->rotate_value);
#ifdef __SYNC_LCM_SW_SUPPORT__
    sync_lcm_enable_mode=KAL_TRUE;
#endif
    lcd_fb_update(data_input->lcd_data);

    /* Open IMGPROC*/
    IMGPROC_Open(SCENARIO_MPEG_DECODE_ID);
    IMGPROC_SelectMode(IMGPROC_DECODE, SCENARIO_MPEG_DECODE_ID);
    pixel_effect_para.hsa = 0;
    pixel_effect_para.cba = 1;
    pixel_effect_para.inv = 0;
    pixel_effect_para.clr = 0;
    pixel_effect_para.gma = 0;
    IMGPROC_SetPixelEffect(&pixel_effect_para, SCENARIO_MPEG_DECODE_ID);
    /*HW bug fix*/
    clean_imgprc_coefficient(SCENARIO_MPEG_DECODE_ID);
    /*brightness, contrast*/
    adjustment_contrast_video_decode(data_input->contrast_level);
    adjustment_brightness_video_decode(data_input->brightness_level);
    IMGPROC_Start(SCENARIO_MPEG_DECODE_ID);

    /*Open Resizer*/
    resizer_config.src1 = SRC_MPEG4;
    resizer_config.pcontinue = 1;
    resizer_config.pixel_sel = 1;
    resizer_config.run2 = 0;
    ASSERT(disp_width <= LCD_DISP_MAX_SIZE);
    resizer_cfg.wmsize = 4;
    if (g_video_dec_info_ptr->resz_work_memory == 0)
    {
        resizer_cfg.wmbase = (kal_uint32)intmem_get_buffer((LCD_DISP_MAX_SIZE * resizer_cfg.wmsize * 3));
        g_video_dec_info_ptr->resz_work_memory = resizer_cfg.wmbase;
    }
    else
    {
        resizer_cfg.wmbase = g_video_dec_info_ptr->resz_work_memory;
    }

    RESZ_Open(SCENARIO_MPEG_DECODE_ID);
    RESZ_Config((RESZ_CFG_STRUCT *)&resizer_config, &resizer_cfg, SCENARIO_MPEG_DECODE_ID);

    if (g_video_dec_info_ptr->height == g_video_dec_info_ptr->real_height)
        temp_height = disp_height;
    else
    {
        temp_height

        = ( (kal_uint32)disp_height*(kal_uint32)g_video_dec_info_ptr->height )/(kal_uint32)g_video_dec_info_ptr->real_height;

        temp_height += 16;
        pan_en = 1;
    }

    if (g_video_dec_info_ptr->width == g_video_dec_info_ptr->real_width)
        temp_width = disp_width;
    else
    {
        temp_width

        = ( (kal_uint32)disp_width*(kal_uint32)g_video_dec_info_ptr->width )/(kal_uint32)g_video_dec_info_ptr->real_width;

        temp_width += 16;
        pan_en = 1;
    }

    RESZ_SetSize(g_video_dec_info_ptr->width, g_video_dec_info_ptr->height, temp_width, temp_height,
                 SCENARIO_MPEG_DECODE_ID);

    RESZ_Start(SCENARIO_MPEG_DECODE_ID);

    /*Config IMGDMA*/
    idma2_para.twice = 0;
    idma2_para.restart = 0;
    idma2_para.lcd_hk = 1;

    if (data_input->force_lcd_hw_trigger == KAL_TRUE)
    {
        idma2_para.couple = 0;
    }
    else
    {
        if (get_lcd_hw_layer_rotate_value(data_input->lcd_data->hw_update_layer) == LCD_LAYER_ROTATE_NORMAL)
            idma2_para.couple = 1;
        else
            idma2_para.couple = 0;
    }

    if (pan_en == 0)
    {
        idma2_para.pan = 0;
    }
    else
    {
        idma2_para.pan = 1;

        idma2_para.hpitch1 = 0;
        idma2_para.hpitch2 = disp_width - 1;
        idma2_para.vpitch1 = 0;
        idma2_para.vpitch2 = disp_height - 1;
    }

    idma2_para.bs1 = data_input->lcd_buf_addr;
    idma2_para.bs2 = data_input->lcd_buf_addr;

    idma2_para.width = temp_width;
    idma2_para.height = temp_height;

    idma2_para.cb = NULL;
#ifdef __SYNC_LCM_SW_SUPPORT__
    sync_lcm_enable_mode=KAL_TRUE;
    EINT_UnMask(sync_lcm_channel_number);
    if (idma2_para.couple == 0)
    {   /* direct couple mode */
        video_decode_direct_couple=KAL_FALSE;
        idma2_para.lcd_hk = 0;
        idma2_para.cb=video_decode_ibw2_cb;
    }
    else
    {   /* hardware trigger mode */
        video_decode_direct_couple=KAL_TRUE;
    }
    video_decode_update_flag=KAL_FALSE;
    sync_lcm_update_cb=sync_lcm_video_decode_update_cb;
#endif
    IMGDMA_IBW2Config(&idma2_para, 0, SCENARIO_MPEG_DECODE_ID);
    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_HW;

    mpeg4_dec_config_frame_buffer_mode(MPEG4_FRAME_BUFFER_NORMAL_MODE, 0);  
#else /*!DRV_MP4_V1*/
    kal_uint32 temp_height = 0;
    kal_uint32 temp_width = 0;
    kal_bool pan_en = KAL_FALSE;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    video_dbg_trace(MP4_DEC_TASK_IMG_HWPATH_OPEN,video_get_current_time());

    g_video_dec_info_ptr->width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH);
    g_video_dec_info_ptr->height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT);	
    g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH);
    g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT);
    if (g_video_dec_info_ptr->real_width == 0) {
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_WIDTH, g_video_dec_info_ptr->width);
        g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->width;
    }
    if (g_video_dec_info_ptr->real_height == 0) {
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_HEIGHT, g_video_dec_info_ptr->height);
        g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->height;
    }

    g_video_dec_info_ptr->prev_display_enable = KAL_FALSE;
    open_image_data_path(SCENARIO_MPEG_DECODE_ID);

    if (g_video_dec_info_ptr->height == g_video_dec_info_ptr->real_height)
        temp_height = data_input->disp_height;
    else
    {
        temp_height

        = ( (kal_uint32)data_input->disp_height*(kal_uint32)g_video_dec_info_ptr->height )/(kal_uint32)g_video_dec_info_ptr->real_height;

        temp_height += 16;
        pan_en = KAL_TRUE;
    }

    if (g_video_dec_info_ptr->width == g_video_dec_info_ptr->real_width)
        temp_width = data_input->disp_width;
    else
    {
        temp_width

        = ( (kal_uint32)data_input->disp_width*(kal_uint32)g_video_dec_info_ptr->width )/(kal_uint32)g_video_dec_info_ptr->real_width;

        temp_width += 16;
        pan_en = KAL_TRUE;
    }

    vid_dec_para.force_lcd_hw_trigger = data_input->force_lcd_hw_trigger;
    vid_dec_para.video_src_width = g_video_dec_info_ptr->width;
    vid_dec_para.video_src_height = g_video_dec_info_ptr->height;
    vid_dec_para.pan = pan_en;
    vid_dec_para.resize_tar_width = temp_width;
    vid_dec_para.resize_tar_height = temp_height;
    vid_dec_para.display_width = data_input->disp_width;
    vid_dec_para.display_height = data_input->disp_height;
    video_set_disp_size(vid_dec_para.display_width, vid_dec_para.display_height);
    /*constract, brightness*/
    vid_dec_para.contrast_level = data_input->contrast_level;
    vid_dec_para.brightness_level = data_input->brightness_level;
    vid_dec_para.video_y_buffer_address = mpeg4_dec_get_prev_display_frame_addr();
    vid_dec_para.video_u_buffer_address = vid_dec_para.video_y_buffer_address + g_video_dec_info_ptr->width
                                                      * g_video_dec_info_ptr->height;
    vid_dec_para.video_v_buffer_address = vid_dec_para.video_y_buffer_address + g_video_dec_info_ptr->width
                                                      * g_video_dec_info_ptr->height * 5 / 4;
    vid_dec_para.image_pitch_mode = data_input->image_pitch_mode;
    vid_dec_para.image_data_format = data_input->image_data_format;
    vid_dec_para.image_pitch_bytes = data_input->image_pitch_bytes;
    vid_dec_para.frame_buffer_address = (kal_uint32)data_input->lcd_buf_addr;
    vid_dec_para.frame_buffer_size = vid_dec_para.display_width * vid_dec_para.display_height * 2;
    vid_dec_para.display = KAL_TRUE;
    #ifdef TV_OUT_SUPPORT
    vid_dec_para.tv_output = data_input->tv_output;
    vid_dec_para.tv_output_width = data_input->lcd_data->tv_output_width;
    vid_dec_para.tv_output_height = data_input->lcd_data->tv_output_height;
    vid_dec_para.tv_output_offset_x = data_input->lcd_data->tv_output_offset_x;
    vid_dec_para.tv_output_offset_y = data_input->lcd_data->tv_output_offset_y;
    vid_dec_para.tv_output_display_width = g_video_dec_info_ptr->real_width;
    vid_dec_para.tv_output_display_height = g_video_dec_info_ptr->real_height;
    vid_dec_para.video_display_offset_x = data_input->video_display_offset_x;
    vid_dec_para.video_display_offset_y = data_input->video_display_offset_y;
    data_input->lcd_data->tv_output_frame_buffer1_address = (kal_uint32)data_input->tv_output_frame_buffer1_address;
    data_input->lcd_data->tv_output_frame_buffer2_address = (kal_uint32)data_input->tv_output_frame_buffer2_address;
    data_input->lcd_data->tv_output_frame_buffer_size = data_input->tv_output_frame_buffer_size;
    #endif //TV_OUT_SUPPORT   

    config_video_decode_data_path(SCENARIO_MPEG_DECODE_ID, &vid_dec_para, data_input->lcd_data);
    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_HW;

    mpeg4_dec_config_frame_buffer_mode(MPEG4_FRAME_BUFFER_NORMAL_MODE, 0);  
#endif /*DRV_MP4_V1*/

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
    ENABLE_LCD_TRANSFER_COMPLETE_INT
#endif
}


/* Close the image path(Resizer+LCD+ImageDMA+ImgProc)
 * @param None
 * @return None.
 */
void video_image_path_close(void)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    ASSERT(g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_HW);
    video_dbg_trace(MP4_DEC_TASK_IMG_HWPATH_CLOSE, video_get_current_time());

#ifdef DRV_MP4_V1

    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_NONE; /*avoid race condition when refresh*/

    while ((IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID) == KAL_TRUE) || (mpeg4_dec_check_complete()==KAL_FALSE))
    {
        kal_sleep_task(1);
    }

    IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGPROC_Stop(SCENARIO_MPEG_DECODE_ID);
    RESZ_Stop(SCENARIO_MPEG_DECODE_ID);

    /*HW bug fix*/
    clean_imgprc_coefficient(SCENARIO_MPEG_DECODE_ID);

    IMGPROC_Close(SCENARIO_MPEG_DECODE_ID);
    RESZ_Close(SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Close(SCENARIO_MPEG_DECODE_ID);

    lcd_stop_hw_update(g_video_dec_info_ptr->lcd_id);
    //resume_lcd_layer_rotate();

#ifdef __SYNC_LCM_SW_SUPPORT__
    sync_lcm_enable_mode=KAL_FALSE;
    EINT_Mask(sync_lcm_channel_number);
#endif
#else /*!DRV_MP4_V1*/

    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_NONE; /*avoid race condition when refresh*/

/* Jerry, IBW2 check is moved to close_image_data_path */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    close_image_data_path(SCENARIO_MPEG_DECODE_ID);
#endif /*DRV_MP4_V1*/

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
    DISABLE_LCD_TRANSFER_COMPLETE_INT
#endif
}


/* Display the current frame that is decoded done.
* @param None
* @return None
*/
void video_dec_display(void)
{
    static kal_uint32 check_reentry = 0;

    if(check_reentry==1)
        return;

    check_reentry = 1;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    video_dec_stop_refresh();

#ifdef DRV_MP4_V1
    if (g_video_dec_info_ptr->display_enable)
    {
        kal_uint32     savedMask;
        if (g_video_dec_info_ptr->path_type != VIDEO_DEC_IMG_PATH_HW)
        {
            video_dbg_trace(MP4_DEC_DISPLAY_FAIL, video_get_current_time());
            VIDEO_ASSERT(0);
            check_reentry = 0;
            return;
        }

        if ((IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID) == KAL_TRUE) || (lcd_is_busy()))
        {
            video_dbg_trace(MP4_DEC_DISPLAY_FAIL, video_get_current_time());
            g_video_dec_info_ptr->disp_lost_frames++;
            g_video_dec_info_ptr->check_display_loss_count++;
            g_video_dec_info_ptr->b_check_log = KAL_TRUE;		
            check_reentry = 0;
            return;
        }
    #ifdef __SYNC_LCM_SW_SUPPORT__
        if ((sync_lcm_enable_mode==KAL_TRUE)&&(video_decode_direct_couple==KAL_TRUE))
        {
            video_decode_update_flag=KAL_TRUE;
            video_frame_buffer_address=mpeg4_dec_get_display_frame_addr();
        }
        else
        {
            savedMask = SaveAndSetIRQMask();
            IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_VdoSetBS1(mpeg4_dec_get_display_frame_addr(), SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Start(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Start(IMGDMA_VDO_CH, SCENARIO_MPEG_DECODE_ID);
            RestoreIRQMask(savedMask);
        }
    #else
        savedMask = SaveAndSetIRQMask();
        IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
        IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
        IMGDMA_VdoSetBS1(mpeg4_dec_get_display_frame_addr(), SCENARIO_MPEG_DECODE_ID);
        IMGDMA_Start(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID);
        IMGDMA_Start(IMGDMA_VDO_CH, SCENARIO_MPEG_DECODE_ID);
        RestoreIRQMask(savedMask);
    #endif
        video_dbg_trace(MP4_DEC_DISPLAY_OK, video_get_current_time());
    }
#else /*!DRV_MP4_V1*/

    if (g_video_dec_info_ptr->display_enable)
    {
        /*DRV_MP4_V2*/
        if (g_video_dec_info_ptr->path_type != VIDEO_DEC_IMG_PATH_HW)
        {
            video_dbg_trace(MP4_DEC_DISPLAY_FAIL, video_get_current_time());
            VIDEO_ASSERT(0);
            check_reentry = 0;
            return;
        }

        if ((IMGDMA_IBW2_IS_BUSY) || (lcd_is_busy()))
        {
            video_dbg_trace(MP4_DEC_DISPLAY_FAIL, video_get_current_time());
            g_video_dec_info_ptr->disp_lost_frames++;
            g_video_dec_info_ptr->check_display_loss_count++;
            g_video_dec_info_ptr->b_check_log = KAL_TRUE;
            vid_dec_para.drop_lcm_frame = KAL_TRUE;
            g_video_dec_info_ptr->b_display_fail = KAL_TRUE;	
        }
        else
        {
            video_dbg_trace(MP4_DEC_DISPLAY_OK, video_get_current_time());
            vid_dec_para.drop_lcm_frame = KAL_FALSE;
            g_video_dec_info_ptr->b_display_fail = KAL_FALSE;  
        }
        vid_dec_para.video_y_buffer_address = mpeg4_dec_get_display_frame_addr();
        vid_dec_para.video_u_buffer_address = vid_dec_para.video_y_buffer_address + g_video_dec_info_ptr->width
                                                      * g_video_dec_info_ptr->height;
        vid_dec_para.video_v_buffer_address = vid_dec_para.video_y_buffer_address + g_video_dec_info_ptr->width
                                                      * g_video_dec_info_ptr->height * 5 / 4;

        vid_dec_para.discard_frame_address = KAL_FALSE;

        video_decode_display(&vid_dec_para);

    }
#endif /*DRV_MP4_V1*/

    if (g_video_dec_info_ptr->display_enable)
         g_video_dec_info_ptr->prev_display_enable = KAL_TRUE;

    check_reentry = 0;
}


/* Display the previous frame.
* @param None
* @return None
*/
void video_dec_prev_display(void)
{
    static kal_uint32 prev_check_reentry = 0;
    kal_uint32 dec_frame_no=0;
    kal_uint32 restart_frame_no=0;

    if(prev_check_reentry==1)
        return;

    prev_check_reentry = 1;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    video_dec_stop_refresh();

#ifdef DRV_MP4_V1

    if (g_video_dec_info_ptr->display_enable)
    {
        if (g_video_dec_info_ptr->path_type != VIDEO_DEC_IMG_PATH_HW)
        {
            video_dbg_trace(MP4_DEC_PREV_DISPLAY_FAIL, video_get_current_time());
            VIDEO_ASSERT(0);
            prev_check_reentry = 0;
            return;
        }

        if ((IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID) == KAL_TRUE) || (lcd_is_busy()))
        {
            video_dbg_trace(MP4_DEC_PREV_DISPLAY_FAIL, video_get_current_time());
            prev_check_reentry = 0;
            return;
        }
        if ( g_video_dec_info_ptr->prev_display_enable == KAL_TRUE)
        {
        #ifdef __SYNC_LCM_SW_SUPPORT__
            if (video_decode_direct_couple==KAL_TRUE)
            {
                video_decode_update_flag=KAL_TRUE;
            }
            else
            {
                kal_uint32 savedMask;
                savedMask = SaveAndSetIRQMask();
                IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
                IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
                IMGDMA_VdoSetBS1(mpeg4_dec_get_prev_display_frame_addr(), SCENARIO_MPEG_DECODE_ID);
                IMGDMA_Start(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID);
                IMGDMA_Start(IMGDMA_VDO_CH, SCENARIO_MPEG_DECODE_ID);
                RestoreIRQMask(savedMask);
            }
        #else
            kal_uint32 savedMask;
            savedMask = SaveAndSetIRQMask();
            IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_VdoSetBS1(mpeg4_dec_get_prev_display_frame_addr(), SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Start(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Start(IMGDMA_VDO_CH, SCENARIO_MPEG_DECODE_ID);
            RestoreIRQMask(savedMask);
        #endif
            video_dbg_trace(MP4_DEC_PREV_DISPLAY_OK, video_get_current_time());
        }
    }
#else /*!DRV_MP4_V1*/

    if (g_video_dec_info_ptr->display_enable)
    {
        if (g_video_dec_info_ptr->path_type != VIDEO_DEC_IMG_PATH_HW)
        {
            video_dbg_trace(MP4_DEC_PREV_DISPLAY_FAIL, video_get_current_time());
            VIDEO_ASSERT(0);
            prev_check_reentry = 0;
            return;
        }

        dec_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
        restart_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_RESTART_FRAME_NUMER);
        if ( (dec_frame_no <= 1)||(dec_frame_no == restart_frame_no) )
			g_video_dec_info_ptr->prev_display_enable = KAL_TRUE;
			
        if ((IMGDMA_IBW2_IS_BUSY) || (lcd_is_busy()) || ( g_video_dec_info_ptr->prev_display_enable == KAL_FALSE))
        {
            video_dbg_trace(MP4_DEC_PREV_DISPLAY_FAIL, video_get_current_time());
            vid_dec_para.drop_lcm_frame = KAL_TRUE;
        }
        else
        {
            video_dbg_trace(MP4_DEC_PREV_DISPLAY_OK, video_get_current_time());
            vid_dec_para.drop_lcm_frame = KAL_FALSE;
        }
        
        if((g_video_dec_info_ptr->b_display_fail == KAL_TRUE) && (vid_dec_para.drop_lcm_frame == KAL_FALSE))
        {
            // previous time display fail, so the address is already stored in vid_dec_para.video_y_buffer_address
            // but image path register is not updated yet
            g_video_dec_info_ptr->b_display_fail = KAL_FALSE;
            vid_dec_para.discard_frame_address = KAL_FALSE;	     		
        }
        else
        {
            vid_dec_para.discard_frame_address = KAL_TRUE;
        }
        video_decode_display(&vid_dec_para);
    }
#endif /*DRV_MP4_V1*/


    // For long duration frames, the play_time won't be updated since no AV sync.
    {
        kal_uint64 gpt_time = 0, tmp_time = 0;
        kal_uint64 tmp_time_chk = 0;
        if (g_video_dec_info_ptr->audio_enable == KAL_TRUE)
        {
            kal_uint64 AvTimeScale = video_dec_get_audio_timebase()/1024;     
            gpt_time = VIDEO_ANYBASE_TO_ANYBASE(VIDEO_MAX_GPT_REFRESH_TIME, 1000, AvTimeScale);
        } else {
            gpt_time = VIDEO_ANYBASE_TO_ANYBASE(VIDEO_MAX_GPT_REFRESH_TIME, 1000, 100);
        }
        tmp_time = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_TMP_PLAY_TIME);
        
        if (tmp_time == 0) {
            tmp_time = gpt_time + g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_PLAY_TIME);
        } else {
            tmp_time += gpt_time;
        }
        tmp_time_chk = tmp_time - g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_PLAY_TIME);
        if(tmp_time_chk <= video_dec_get_prev_frametime())
        {
            g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_TMP_PLAY_TIME, tmp_time);
        }
    }
    
    prev_check_reentry = 0;
}


/* Open the image path(Resizer+ImageDMA+ImgProc), then this path will be conrolled by MED/MMI.
 * @param  data_input   MP4DEC_MEMMODE_STRUCT be prepared by MMI
 * @return None.
 */
void video_memorymode_open(MP4DEC_MEMMODE_STRUCT * data_input)
{
#ifdef DRV_MP4_V1

    RESZ_CFG_STRUCT resizer_config;

    RESZ_PXL_CFG_STRUCT resizer_cfg;
    IMGDMA_IBW2_STRUCT idma2_para;
    IMGDMA_VDO_STRUCT video_dma_para;
    IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;
    kal_uint32 temp_height = 0;
    kal_uint32 temp_width = 0;
    kal_bool pan_en = 0;
    kal_uint16 disp_width;
    kal_uint16 disp_height;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    video_dbg_trace(MP4_DEC_TASK_IMG_SWPATH_OPEN, video_get_current_time());

    g_video_dec_info_ptr->width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH);
    g_video_dec_info_ptr->height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT);	
    g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH);
    g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT);			
    if (g_video_dec_info_ptr->real_width == 0) {
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_WIDTH, g_video_dec_info_ptr->width);
        g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->width;
    }
    if (g_video_dec_info_ptr->real_height == 0) {
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_HEIGHT, g_video_dec_info_ptr->height);
        g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->height;
    }
    
    disp_width = data_input->disp_width;
    disp_height = data_input->disp_height;

    /*VDO IMGDMA*/
    IMGDMA_Open(SCENARIO_MPEG_DECODE_ID);
    video_dma_para.dir = 0;
    video_dma_para.twice = 0;
    video_dma_para.restart = 0;
    video_dma_para.bs1 = 0;
    video_dma_para.bs2 = 0;
    video_dma_para.width = g_video_dec_info_ptr->width;
    video_dma_para.height = g_video_dec_info_ptr->height;
    video_dma_para.cb1 = NULL;
    video_dma_para.cb2 = NULL;
    g_video_dec_info_ptr->prev_display_enable = KAL_FALSE;
    IMGDMA_VdoConfig(&video_dma_para, 0, SCENARIO_MPEG_DECODE_ID);

    /*IMGPROC*/
    IMGPROC_Open(SCENARIO_MPEG_DECODE_ID);
    IMGPROC_SelectMode(IMGPROC_DECODE, SCENARIO_MPEG_DECODE_ID);
    pixel_effect_para.hsa = 0;
    pixel_effect_para.cba = 1;
    pixel_effect_para.inv = 0;
    pixel_effect_para.clr = 0;
    pixel_effect_para.gma = 0;
    IMGPROC_SetPixelEffect(&pixel_effect_para, SCENARIO_MPEG_DECODE_ID);
    /*HW bug fix*/
    clean_imgprc_coefficient(SCENARIO_MPEG_DECODE_ID);
    /*brightness, contrast*/
    adjustment_contrast_video_decode(data_input->contrast_level);
    adjustment_brightness_video_decode(data_input->brightness_level);
    IMGPROC_Start(SCENARIO_MPEG_DECODE_ID);

    /*Resizer*/
    resizer_config.src1 = SRC_MPEG4;
    resizer_config.pcontinue = 1;
    resizer_config.pixel_sel = 1;
    resizer_config.run2 = 0;

    ASSERT(data_input->disp_width <= LCD_DISP_MAX_SIZE);
    resizer_cfg.wmsize = 4;

    if (g_video_dec_info_ptr->resz_work_memory == 0)
    {
        resizer_cfg.wmbase = (kal_uint32)intmem_get_buffer((LCD_DISP_MAX_SIZE * resizer_cfg.wmsize * 3));
        g_video_dec_info_ptr->resz_work_memory = resizer_cfg.wmbase;
    }
    else
    {
        resizer_cfg.wmbase = g_video_dec_info_ptr->resz_work_memory;
    }

    RESZ_Open(SCENARIO_MPEG_DECODE_ID);
    RESZ_Config((RESZ_CFG_STRUCT *)&resizer_config, &resizer_cfg, SCENARIO_MPEG_DECODE_ID);

    if (g_video_dec_info_ptr->height == g_video_dec_info_ptr->real_height)
        temp_height = disp_height;
    else
    {
        temp_height

        = ( (kal_uint32)disp_height*(kal_uint32)g_video_dec_info_ptr->height )/(kal_uint32)g_video_dec_info_ptr->real_height;

        temp_height += 16;
        pan_en = 1;
    }

    if (g_video_dec_info_ptr->width == g_video_dec_info_ptr->real_width)
        temp_width = disp_width;
    else
    {
        temp_width

        = ( (kal_uint32)disp_width*(kal_uint32)g_video_dec_info_ptr->width )/(kal_uint32)g_video_dec_info_ptr->real_width;

        temp_width += 16;
        pan_en = 1;
    }

    RESZ_SetSize(g_video_dec_info_ptr->width, g_video_dec_info_ptr->height, temp_width, temp_height,
                 SCENARIO_MPEG_DECODE_ID);

    RESZ_Start(SCENARIO_MPEG_DECODE_ID);

    /*IMGDMA*/
    idma2_para.twice = 0;
    idma2_para.restart = 0;
    idma2_para.lcd_hk = 0;
    idma2_para.couple = 0;

    if (pan_en == 0)
    {
        idma2_para.pan = 0;
    }
    else
    {
        idma2_para.pan = 1;

        idma2_para.hpitch1 = 0;
        idma2_para.hpitch2 = disp_width - 1;
        idma2_para.vpitch1 = 0;
        idma2_para.vpitch2 = disp_height - 1;
    }

    idma2_para.bs1 = data_input->lcd_buf_addr;
    idma2_para.bs2 = data_input->lcd_buf_addr;

    idma2_para.width = temp_width;
    idma2_para.height = temp_height;
    idma2_para.cb = NULL;
    IMGDMA_IBW2Config(&idma2_para, 0, SCENARIO_MPEG_DECODE_ID);
    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_SW;

     mpeg4_dec_config_frame_buffer_mode(MPEG4_FRAME_BUFFER_MEMORY_MODE, 0);  
#else /*!DRV_MP4_V1*/
    kal_bool pan_en = KAL_FALSE;
    kal_uint32 temp_width = 0;
    kal_uint32 temp_height = 0;
    kal_uint32 prev_y_addr;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    video_dbg_trace(MP4_DEC_TASK_IMG_SWPATH_OPEN,video_get_current_time());

    g_video_dec_info_ptr->width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH);
    g_video_dec_info_ptr->height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT);	
    g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH);
    g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT);		
    if (g_video_dec_info_ptr->real_width == 0) {
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_WIDTH, g_video_dec_info_ptr->width);
        g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->width;
    }
    if (g_video_dec_info_ptr->real_height == 0) {
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_REAL_HEIGHT, g_video_dec_info_ptr->height);
        g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->height;
    }
    	
    g_video_dec_info_ptr->prev_display_enable = KAL_FALSE;
    open_image_data_path(SCENARIO_MPEG_DECODE_ID);

    if (g_video_dec_info_ptr->height == g_video_dec_info_ptr->real_height)
        temp_height = data_input->disp_height;
    else
    {
        temp_height

        = ( (kal_uint32)data_input->disp_height*(kal_uint32)g_video_dec_info_ptr->height )/(kal_uint32)g_video_dec_info_ptr->real_height;

        temp_height += 16;
        pan_en = KAL_TRUE;
    }

    if (g_video_dec_info_ptr->width == g_video_dec_info_ptr->real_width)
        temp_width = data_input->disp_width;
    else
    {
        temp_width

        = ( (kal_uint32)data_input->disp_width*(kal_uint32)g_video_dec_info_ptr->width )/(kal_uint32)g_video_dec_info_ptr->real_width;

        temp_width += 16;
        pan_en = KAL_TRUE;
    }

    vid_dec_para.video_src_width = g_video_dec_info_ptr->width;
    vid_dec_para.video_src_height = g_video_dec_info_ptr->height;
    vid_dec_para.pan = pan_en;
    vid_dec_para.resize_tar_width = temp_width;
    vid_dec_para.resize_tar_height = temp_height;
    vid_dec_para.display_width = data_input->disp_width;
    vid_dec_para.display_height = data_input->disp_height;
    /*constract, brightness*/
    vid_dec_para.contrast_level = data_input->contrast_level;
    vid_dec_para.brightness_level = data_input->brightness_level;
    prev_y_addr = vid_dec_para.video_y_buffer_address;
    vid_dec_para.video_y_buffer_address = 0;
    vid_dec_para.video_u_buffer_address = 0;
    vid_dec_para.video_v_buffer_address = 0;
    vid_dec_para.image_pitch_mode = KAL_FALSE;
    vid_dec_para.image_data_format = data_input->image_data_format;
    vid_dec_para.image_pitch_bytes = data_input->image_pitch_bytes;
    vid_dec_para.frame_buffer_address = (kal_uint32)data_input->lcd_buf_addr;
    vid_dec_para.frame_buffer_size = vid_dec_para.display_width * vid_dec_para.display_height * 2;
    vid_dec_para.display = KAL_FALSE;
    vid_dec_para.tv_output = data_input->tv_output;
    vid_dec_para.tv_output_display_width = g_video_dec_info_ptr->real_width;
    vid_dec_para.tv_output_display_height = g_video_dec_info_ptr->real_height;
    config_video_decode_data_path(SCENARIO_MPEG_DECODE_ID, &vid_dec_para, NULL);
    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_SW;

    mpeg4_dec_config_frame_buffer_mode(MPEG4_FRAME_BUFFER_MEMORY_MODE, prev_y_addr);
#endif /*DRV_MP4_V1*/

}

void video_stream_memorymode_close(void)     /*Jensen, 2/6, temp solution. Need to discuss it with Jerry*/
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    ASSERT(g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_SW);
    video_dbg_trace(MP4_DEC_TASK_IMG_SWPATH_CLOSE, video_get_current_time());

    //video_dec_disable_irq(video_file_get_decode_type());
    //video_dec_stop_av();
#ifdef DRV_MP4_V1

    while (IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID) == KAL_TRUE)
    {
        kal_sleep_task(1);
    }

    IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGPROC_Stop(SCENARIO_MPEG_DECODE_ID);
    RESZ_Stop(SCENARIO_MPEG_DECODE_ID);

    IMGPROC_Close(SCENARIO_MPEG_DECODE_ID);
    RESZ_Close(SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Close(SCENARIO_MPEG_DECODE_ID);
    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_NONE;
#else /*!DRV_MP4_V1*/

    while (IMGDMA_IBW2_IS_BUSY)
    {
        kal_sleep_task(1);
    }

    close_image_data_path(SCENARIO_MPEG_DECODE_ID);
    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_NONE;
#endif /*DRV_MP4_V1*/
}

/* Close the image data path
 * @param None
 * @return None.
 */
void video_memorymode_close(void)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    ASSERT(g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_SW);
    video_dbg_trace(MP4_DEC_TASK_IMG_SWPATH_CLOSE, video_get_current_time());

    video_dec_disable_irq(video_file_get_decode_type());
    video_dec_stop_av();
#ifdef DRV_MP4_V1

    while (IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID) == KAL_TRUE)
    {
        kal_sleep_task(1);
    }

    IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGPROC_Stop(SCENARIO_MPEG_DECODE_ID);
    RESZ_Stop(SCENARIO_MPEG_DECODE_ID);

    IMGPROC_Close(SCENARIO_MPEG_DECODE_ID);
    RESZ_Close(SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Close(SCENARIO_MPEG_DECODE_ID);
    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_NONE;
#else /*!DRV_MP4_V1*/

    while (IMGDMA_IBW2_IS_BUSY)
    {
        kal_sleep_task(1);
    }

    close_image_data_path(SCENARIO_MPEG_DECODE_ID);
    g_video_dec_info_ptr->path_type = VIDEO_DEC_IMG_PATH_NONE;
#endif /*DRV_MP4_V1*/

}


/* This function should be called after video_swmode_open is called.
 * This function will copy the last decoded frame to another memory buffer.
 * @param None
 * @return None.
 */
void video_dec_frame_to_memory(void)
{
#ifdef DRV_MP4_V1

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    ASSERT(g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_SW);

    video_dbg_trace(MP4_DEC_TASK_IMG_SWPATH_DISP, video_get_current_time());
    //kal_sleep_task(3);
    IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_VdoSetBS1(mpeg4_dec_get_display_frame_addr(), SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Start(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Start(IMGDMA_VDO_CH, SCENARIO_MPEG_DECODE_ID);

    while (IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID) == KAL_TRUE)
    {
        kal_sleep_task(1);
    }
#else /*!DRV_MP4_V1*/

    kal_uint32 tv_display_frame_buffer;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    ASSERT(g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_SW);
    video_dbg_trace(MP4_DEC_TASK_IMG_SWPATH_DISP, video_get_current_time());

    tv_display_frame_buffer = mpeg4_dec_get_display_frame_addr();

    vid_dec_para.video_y_buffer_address = tv_display_frame_buffer;
    vid_dec_para.video_u_buffer_address =
        tv_display_frame_buffer + g_video_dec_info_ptr->width * g_video_dec_info_ptr->height;
    vid_dec_para.video_v_buffer_address =
        tv_display_frame_buffer + g_video_dec_info_ptr->width * g_video_dec_info_ptr->height * 5 / 4;
    vid_dec_para.drop_lcm_frame = KAL_FALSE;
    vid_dec_para.discard_frame_address = KAL_FALSE;
    video_decode_display(&vid_dec_para);
#endif /*DRV_MP4_V1*/

    if (g_video_dec_info_ptr->display_enable)
        g_video_dec_info_ptr->prev_display_enable = KAL_TRUE;
}


/* This function should be called after video_swmode_open is called. 
 * This function will disaply the previous frame.
 * @param None
 * @return None.
 */
void video_dec_prev_frame_to_memory(void)
{
#ifdef DRV_MP4_V1

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
     
    ASSERT(g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_SW);

    video_dbg_trace(MP4_DEC_TASK_IMG_SWPATH_DISP, video_get_current_time());
    //kal_sleep_task(3);
    IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_VdoSetBS1(mpeg4_dec_get_prev_display_frame_addr(), SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Start(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID);
    IMGDMA_Start(IMGDMA_VDO_CH, SCENARIO_MPEG_DECODE_ID);

    while (IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID) == KAL_TRUE)
    {
        kal_sleep_task(1);
    }
#else /*!DRV_MP4_V1*/

    kal_uint32 tv_display_frame_buffer;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    ASSERT(g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_SW);
    video_dbg_trace(MP4_DEC_TASK_IMG_SWPATH_DISP, video_get_current_time());

    tv_display_frame_buffer = mpeg4_dec_get_prev_display_frame_addr();

    vid_dec_para.video_y_buffer_address = tv_display_frame_buffer;
    vid_dec_para.video_u_buffer_address =
        tv_display_frame_buffer + g_video_dec_info_ptr->width * g_video_dec_info_ptr->height;
    vid_dec_para.video_v_buffer_address =
        tv_display_frame_buffer + g_video_dec_info_ptr->width * g_video_dec_info_ptr->height * 5 / 4;
    vid_dec_para.drop_lcm_frame = KAL_FALSE;
    vid_dec_para.discard_frame_address = KAL_FALSE;
    video_decode_display(&vid_dec_para);
#endif /*DRV_MP4_V1*/

    if (g_video_dec_info_ptr->display_enable)
        g_video_dec_info_ptr->prev_display_enable = KAL_TRUE;
}



///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Parameter functions                                           //
//////////////////////////////////////////////////////////////////


/* This function is used to obtain the play time according to frame number
 * @param  frame frame number
 * @param  time  time ptr. (Unit: ms)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_frame2time(kal_uint32 frame, kal_uint32 * time)
{
    kal_uint64 video_time;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser, frame, //id = 0~, reviewed
                                                        &video_time, MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        VIDEO_ASSERT(0);
        return MP4_PARSER_ERROR;
    }

    /* translate to ms */
    *time = VIDEO_ANYBASE_TO_ANYBASE(video_time, g_video_dec_info_ptr->video_time_scale, 1000);
    return MEDIA_STATUS_OK;
}


/* This function is used to obtain the frame number according to the play time.
 * @param  time   play time(Unit: ms)
 * @param  frame  Frame number.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_time2frame(kal_uint32 time, kal_uint32 * frame)
{
    kal_uint64 video_time;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    /* translate to video time base */
    video_time = VIDEO_ANYBASE_TO_ANYBASE(time, 1000, g_video_dec_info_ptr->video_time_scale);

    g_video_dec_status.PARSE_STATUS = MP4_GetSampleNumber(g_video_dec_info_ptr->pMp4Parser, frame, video_time,
                                                          MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        VIDEO_ASSERT(0);
        return MP4_PARSER_ERROR;
    }

    return MEDIA_STATUS_OK;
}


/*This function is for snapshot scenario when video play
 * @param memory_addr      resizer working memory addr;
 * @return NULL
 */
void video_dec_set_snapshot_resize_mem(kal_uint32 memory_addr)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
    g_video_dec_info_ptr->snapshot_resize_memory = memory_addr;
}


/* This function is for snapshot scenario when video play
 * @param None
 * @return resizer working memory addr;
 */
kal_uint32 video_dec_get_snapshot_resize_mem(void)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
    return g_video_dec_info_ptr->snapshot_resize_memory;
}


/* This function is for snapshot scenario when video play
 * @param memory_addr      imgdma working memory addr;
 * @return NULL
 */
void video_dec_set_snapshot_imgdma_mem(kal_uint32 memory_addr)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
    g_video_dec_info_ptr->snapshot_imgdma_memory = memory_addr;
}


/* This function is for snapshot scenario when video play
 * @param None
 * @return imgdma working memory addr;
 */
kal_uint32 video_dec_get_snapshot_imgdma_mem(void)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
    return g_video_dec_info_ptr->snapshot_imgdma_memory;
}


/* This function can set different speed for video
 * final play speed = normal play speed * (play_speed/100)
 * @param play_speed   play speed ratio.
 * @return NULL
 */
void video_dec_set_play_speed(kal_uint16 play_speed)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
    g_video_dec_info_ptr->play_speed = play_speed;
}


/* Get total video frames
 * @param None
 * @return total video frames
 */
kal_uint32 video_dec_get_total_frame(void)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
    return g_video_dec_info_ptr->total_frames_in_file;
}


/* Get the last decoded frame number.
 * @param None
 * @return the last decoded frame number.
 */
kal_uint32 video_dec_get_current_frame_no(void)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
    return g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
}


/* Get current total play time in video
 * @param total_play_time obtain the current total play time. (Unit: ms)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_get_total_play_time(kal_uint64 * total_play_time)
{
    kal_uint64 video_duration;
    kal_uint64 audio_duration;

//    if(g_video_dec_status.running == KAL_FALSE)
//    {
//        VIDEO_ASSERT(0);
//        return VIDEO_ERROR;
//    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   video_dec_get_total_time(&audio_duration, &video_duration);
#endif
     if (audio_duration < video_duration)
        *total_play_time = video_duration;
    else
        *total_play_time = audio_duration;

    return MEDIA_STATUS_OK;
}


/* This function will obtain audio and video total duration.
 * @param  audio_time audio total duration
 * @param  video_time video total duration.
 * @return  None
 */
void video_dec_get_total_time(kal_uint64 * audio_time, kal_uint64 * video_time)
{
    kal_uint32 aud_duration;
    kal_uint32 vid_duration;
   MP4_Parser_Status ret;
   kal_uint32 uVideoTimeScale, uAudioTimeScale;

//    if(g_video_dec_status.running == KAL_FALSE)
//    {
//        ASSERT(0);
//    }
#if 0
/* under construction !*/
/* under construction !*/
#else
    if (g_video_dec_status.noVideoTrack == KAL_TRUE)
    {
        if ( ((ret=MP4_GetMediaDuration(g_video_dec_info_ptr->pMp4Parser, &aud_duration, MP4_TRACK_AUDIO))!=MP4_PARSER_OK) ||
             ((ret=MP4_GetMediaTimeScale(g_video_dec_info_ptr->pMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK) )
        {
            *audio_time = VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->audio_duration, 1000);
        } 
        else 
        {
            *audio_time = VIDEO_ANYBASE_TO_ANYBASE(aud_duration,uAudioTimeScale,1000);        	
        }
        *video_time = *audio_time;
    }
    else if (g_video_dec_status.noAudioTrack == KAL_TRUE)
    {
        if ( ((ret=MP4_GetMediaDuration(g_video_dec_info_ptr->pMp4Parser, &vid_duration, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) ||
             ((ret=MP4_GetMediaTimeScale(g_video_dec_info_ptr->pMp4Parser, &uVideoTimeScale, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) )
        {
            *video_time = VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->video_duration, 1000);
        } 
        else 
        {
            *video_time = VIDEO_ANYBASE_TO_ANYBASE(vid_duration,uVideoTimeScale,1000);        	
        }
        *audio_time = *video_time;
    } 
    else 
    {
        if ( ((ret=MP4_GetMediaDuration(g_video_dec_info_ptr->pMp4Parser, &aud_duration, MP4_TRACK_AUDIO))!=MP4_PARSER_OK) || 
             ((ret=MP4_GetMediaTimeScale(g_video_dec_info_ptr->pMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK) )
        {
            *audio_time = VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->audio_duration, 1000);
        } 
        else 
        {
            *audio_time = VIDEO_ANYBASE_TO_ANYBASE(aud_duration,uAudioTimeScale,1000);
        }
        if ( ((ret=MP4_GetMediaDuration(g_video_dec_info_ptr->pMp4Parser, &vid_duration, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) ||
             ((ret=MP4_GetMediaTimeScale(g_video_dec_info_ptr->pMp4Parser, &uVideoTimeScale, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) )
        {
            *video_time = VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->video_duration, 1000);    	
        } 
        else 
        {
            *video_time = VIDEO_ANYBASE_TO_ANYBASE(vid_duration,uVideoTimeScale,1000);
        }
    }
#endif
}


/* Get current play time
 * @param  current_time  current play time(Unit: ms)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_get_play_time(kal_uint64 * current_time)
{
    kal_uint32 savedMask;
    kal_uint64 AvTimeScale;
    kal_uint64 cal_time, tmp_cal_time;
    MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    savedMask = SaveAndSetIRQMask();
    if (g_video_dec_info_ptr->pMp4Parser == NULL)
    {
        RestoreIRQMask(savedMask);
        return 0;
    }
    RestoreIRQMask(savedMask);


    if (g_video_dec_info_ptr->audio_enable == KAL_TRUE)
    {
        /*Audio is enabled. The timing information get from audio ticks */
        g_video_dec_status.PARSE_STATUS = MP4_GetPlayTime(vid_get_audio_parser(), current_time,
                                                              g_video_dec_info_ptr->play_speed);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            VIDEO_ASSERT(0);
            result = MP4_PARSER_ERROR;
            return result;
        }
             
    	if ( ((g_video_dec_info_ptr->play_speed > 100)&& (g_video_dec_info_ptr->video_end != KAL_TRUE)&& (g_video_dec_info_ptr->stage == VIDEO_DEC_STAGE_PLAY))
#ifdef PGDL_SUPPORT
    	      || (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) // add PGDL case since PGDL will reload many time and MP4_GetPlayTime will be wrong.
#endif    	      
   	      ) 
        {
            /* timing should be adjust for fast play
                (use video maintained play time instead of audio maintained interrupt count )
                => fast play has trick for play time (audio mute case) */
            AvTimeScale = video_dec_get_audio_timebase()/1024;

            if (g_video_dec_info_ptr->p_driver == NULL) {	// For PDL and audio-only case.
                cal_time = tmp_cal_time = *current_time;
            } 
            else 
            {
                cal_time = VIDEO_ANYBASE_TO_ANYBASE(
                                    g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_PLAY_TIME),AvTimeScale,1000);
                tmp_cal_time = VIDEO_ANYBASE_TO_ANYBASE(
                                    g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_TMP_PLAY_TIME),AvTimeScale,1000);
            }


            if (tmp_cal_time > cal_time) 
                cal_time = tmp_cal_time;
		  
            if( ((*current_time) > cal_time) 
#ifdef PGDL_SUPPORT				
			|| (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) 
#endif			
			)
            {
                *current_time = cal_time;
       
                /* set back to audio time. otherwise when stop play the time will not correct */
                savedMask = SaveAndSetIRQMask();
                MP4_SetPlaybackTimerBase(vid_get_audio_parser(), (kal_uint32)*current_time, KAL_FALSE);
                RestoreIRQMask(savedMask);
            }
        }
        
        g_video_dec_info_ptr->current_play_time = *current_time;     
    }
    else
    {
        /* If audio is not enable. get time from gpt */
        cal_time = VIDEO_ANYBASE_TO_ANYBASE(
                                   g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_PLAY_TIME), 100, 1000);
        tmp_cal_time = VIDEO_ANYBASE_TO_ANYBASE(
                                   g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_TMP_PLAY_TIME), 100, 1000);

	   if (tmp_cal_time > cal_time) 
		  	cal_time = tmp_cal_time;

	   *current_time = cal_time;
    }

    return result;
}


/* This function can obtain the total duration from 1 to frame_no-1.
 * @param frame_no      frame number.
 * @param decode_time   the decode time
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE Video_GetDecodeTime(kal_uint32 frame_no, kal_uint64 * decode_time)
{
    kal_uint32 video_time_scale;

    kal_uint64 video_time;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    /* Video time scale */
    g_video_dec_status.PARSE_STATUS = MP4_GetMediaTimeScale(g_video_dec_info_ptr->pMp4Parser, &video_time_scale,
                                                            MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_TRACK)
    {
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }

        /* time from 1 ~ frame_no - 1*/
        g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser,
                                                            (frame_no - 1), //id = 1~, reviewed
                                                            &video_time,
                                                            MP4_TRACK_VIDEO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_TRACK)
        {
            if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
            {
                VIDEO_ASSERT(0);
                return MP4_PARSER_ERROR;
            }
        }
        else
        {
            /* No track return 0 */
            video_time_scale = 1;
            video_time = 0;
        }
    }
    else
    {
        video_time_scale = 1;
        video_time = 0;
    }

    /* translate to ms */
    *decode_time = VIDEO_ANYBASE_TO_MS(video_time, video_time_scale);

    return MEDIA_STATUS_OK;
}


/* This function is used to set the stop frame that video will auto-stop at this frame.
 * @param  play_stop_time   stop time, (unit: ms)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_set_stop_time(kal_uint32 play_stop_time)
{
    MEDIA_STATUS_CODE result;
    kal_uint64 stop_time;
    kal_uint64 next_stop_time;
    kal_uint32 frame_no;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    /* get frame number */
    stop_time = VIDEO_ANYBASE_TO_COMMBASE(play_stop_time, 1000);
    result = video_dec_get_frame_with_time(&frame_no, stop_time, &next_stop_time);
    ASSERT(frame_no > 0);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    /* set stop time */
    video_dec_set_stop_frame(frame_no);
    return MEDIA_STATUS_OK;
}


/* This function can obtain the original frame widht/height.
 * @param width   original video frame width
 * @param height  original video frame height
 * @return None
 */
void video_dec_get_frame_size(kal_uint16 * width, kal_uint16 * height)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }
    g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH);
    g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT);

    *width = g_video_dec_info_ptr->real_width;
    *height = g_video_dec_info_ptr->real_height;
}

/* This function is enable audio play or not, when video decode.
 * @param  enable enable or not
 * @return None
 */
void video_dec_set_audio(kal_bool enable)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    g_video_dec_info_ptr->audio_enable = enable;

    video_dec_init_av(enable);
}

/* This function is enable LCD display or not, when video decode.
 * @param  enable enable or not
 * @return None
 */
void video_dec_set_display(kal_bool enable)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    g_video_dec_info_ptr->display_enable = enable;
}


/* This function is get whether current video file is finised or not
 * @param  None
 * @return finished status
 */
kal_bool video_dec_is_play_finished(void)
{
    if ((g_video_dec_info_ptr->video_end == KAL_TRUE) ||
    	  (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER) 
    	    == g_video_dec_info_ptr->total_frames_in_file))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}



///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Control  functions                                              //
//////////////////////////////////////////////////////////////////

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
#endif

#ifdef PGDL_SUPPORT
MEDIA_STATUS_CODE MP4_Video_FrameAvailable(STMp4Parser * pstMp4Parser)
{
   kal_uint32 decoded_frames = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
   kal_uint32 uVideoSampleNo = pstMp4Parser->stMp4Track[pstMp4Parser->bVideoTrack].uGetAvaDurCurSampleCnt;

   if (uVideoSampleNo < g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER)) {
      //ASSERT(0); 	// for seek to near the end of video, and auto-replay case. The dec_frame_no is bigger.
      decoded_frames = 0;
   }
   
   if ((decoded_frames == g_video_dec_info_ptr->total_frames_in_file)||(uVideoSampleNo == g_video_dec_info_ptr->total_frames_in_file)) {
      video_dbg_trace(PDL_FrameAvail_VideoEnd, decoded_frames);
      kal_prompt_trace(MOD_MED, "PDL_FrameAvail_VideoEnd: %d, %d\n", uVideoSampleNo, decoded_frames);
      return MEDIA_STATUS_OK;
   }

   if (decoded_frames == 0)
      decoded_frames = 1; // Handle the case after PDL_initialize and before play, since dec_frames_no++ in mpeg4_dec_lisr_process.
   if (uVideoSampleNo > (decoded_frames+49)) {  // 49 is to meet put_frame_to_buffer constraints. At less 50 frames to fill a buffer.
      video_dbg_trace(PDL_FrameAvail_OK, uVideoSampleNo*1000000 + decoded_frames);
      kal_prompt_trace(MOD_MED, "PDL_FrameAvail_OK: %d, %d\n", uVideoSampleNo, decoded_frames);
      return MEDIA_STATUS_OK;
   } else {
      video_dbg_trace(PDL_FrameAvail_READ_EOF, video_get_current_time());
      kal_prompt_trace(MOD_MED, "PDL_FrameAvail_READ_EOF: %d, %d\n", uVideoSampleNo, decoded_frames);
      return FSAL_READ_EOF;
   }
}

/* This function will open the video progressive-download decode initialize
 * @param  clip_input MP4DEC_CLIP_INIT_STRUCT prepared by upper layer
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_PDL_initialize(MP4DEC_INIT_STRUCT * init_input)
{
    MEDIA_STATUS_CODE result;

    /* clip initailize */
    g_video_dec_status.scenario = VIDEO_SCENARIO_PGDL;

    result = video_dec_comm_initialize(init_input);

    if (init_input->pstMp4Parser->bAudioTrack == MP4_RESERVED_TRACK_NO)
    {
        // This line must after video_dec_comm_initialize()
       g_video_dec_status.noAudioTrack = KAL_TRUE;
    }
    if (init_input->pstMp4Parser->bVideoTrack == MP4_RESERVED_TRACK_NO)
    {
        // This line must after video_dec_comm_initialize()
        g_video_dec_status.noVideoTrack = KAL_TRUE;
        return NO_VISUAL_TRACK;
    }
    if(result == NO_VISUAL_TRACK)
    {
        g_video_dec_status.noVideoTrack = KAL_TRUE;
        return result;
    }

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

     /* set play back time base as 0 */
    MP4_SetPlaybackTimerBase(vid_get_audio_parser(), 0, KAL_TRUE);
    return MEDIA_STATUS_OK;
}
#endif

/* This function will open the video clip decode initialize
 * @param  clip_input MP4DEC_INIT_STRUCT prepared by upper layer
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_initialize(MP4DEC_INIT_STRUCT * init_input)
{
    MEDIA_STATUS_CODE result;

    /* clip initailize */
    g_video_dec_status.scenario = VIDEO_SCENARIO_DECODE;

    result = video_dec_comm_initialize(init_input);

    if (init_input->pstMp4Parser->bAudioTrack == MP4_RESERVED_TRACK_NO) 
    {
        // This line must after video_dec_comm_initialize()
        g_video_dec_status.noAudioTrack = KAL_TRUE;
    }
    if (init_input->pstMp4Parser->bVideoTrack == MP4_RESERVED_TRACK_NO) 
    {
        // This line must after video_dec_comm_initialize()
        g_video_dec_status.noVideoTrack = KAL_TRUE;
        return NO_VISUAL_TRACK;
    }
    if(result == NO_VISUAL_TRACK)
    {
        g_video_dec_status.noVideoTrack = KAL_TRUE;
        return result;
    }

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

     /* set play back time base as 0 */
    MP4_SetPlaybackTimerBase(vid_get_audio_parser(), 0, KAL_TRUE);

#ifdef VIDEO_DEC_YUV_MODE
    {
        /* open file for YUV mode */
        FSAL_Status FSAL_STATUS;
        kal_wchar   store_name[20]=L"x:\\dec_out.yuv";
        //store_name[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
        store_name[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        FSAL_STATUS = FSAL_Open(&FSAL_VIDEO_YUV_FILE, store_name, FSAL_WRITE);
        if (FSAL_STATUS != FSAL_OK)
        {
            ASSERT(0);
        }
    }
#endif /*VIDEO_DEC_YUV_MODE*/

    return MEDIA_STATUS_OK;
}


/* This function should be called after video_dec_seek.
 * This function can play video sequently.
 * @param audio_frame_no The related audio frame that related to seek video frame.
 * @param video_dec_callback video callback function when driver want to notify MED or upper layer.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_play(kal_uint32 * audio_frame_no, void (*video_dec_callback)(kal_uint8 event), kal_bool b_from_start)
{
    MEDIA_STATUS_CODE result;
    kal_uint32 frame_no;	

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    /* reset av time offsets. If previous play has offest, reset it */
    video_dec_rst_av_timeoffset();

    if(b_from_start==KAL_TRUE)
    {
        /* In clip play case, application may not seek first before play. 
        But common play only handle the seek done case. 
        So set to seek state first. (clip initailize already decode the first frame similar to seek action) */
        g_video_dec_info_ptr->seek_time = 0;
        g_video_dec_info_ptr->seek_by_time = KAL_FALSE;
        g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_SEEK;
        /* Get seek_next_frame_time first because common play will use it */
        result = video_dec_get_frame_with_time(&frame_no, g_video_dec_info_ptr->seek_time,
                                               &g_video_dec_info_ptr->seek_next_frame_time);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
        /* display the first initialize frame for play */
        video_dec_display();
    }

#ifdef VIDEO_DEC_YUV_MODE
    result = video_dec_seek_by_frame(g_video_dec_info_ptr->total_frames_in_file, video_dec_callback, KAL_TRUE);
#else  /*VIDEO_DEC_YUV_MODE*/
    result = video_dec_comm_play(audio_frame_no, video_dec_callback);
#endif /*VIDEO_DEC_YUV_MODE*/	
	
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    return MEDIA_STATUS_OK;
}


#ifdef STREAM_SUPPORT
/* This function should be called after p_rtp_handle->Start().
 * This function can play video streaming sequently.
 * @param audio_frame_no The related audio frame that related to seek video frame. If audio is not enable, don't care "audio_frame_no" parameter!!
 * @param video_dec_callback video callback function when driver want to notify MED or upper layer.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_stream_play(kal_uint32 * audio_frame_no, void (*video_dec_callback)(kal_uint8 event))
{
    MEDIA_STATUS_CODE result;
    kal_uint8 *frame_addr;
    kal_uint32 frame_length;
    kal_uint32 prev_frame_duration;
    kal_uint64 decode_time;
//    kal_uint32 savedMask;

    g_video_dec_info_ptr->video_dec_callback = video_dec_callback;

    /* set as 1st frame duration */
    decode_time = video_dec_stream_get_first_frame_duration();

    /* Decode the frame */
    result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        kal_prompt_trace(MOD_MED, "VIDEO_STREAM_PLAY_Get_Next_Frame_Err: %d\n", result);
        return result;
    }
    result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);
    if (result != MEDIA_STATUS_OK)
    {
        kal_prompt_trace(MOD_MED, "VIDEO_STREAM_PLAY_Decode_Main_Err: %d\n", result);
        VIDEO_ASSERT(0);
        return result;
    }

    /* write register to decode the parsed frame */
     g_video_dec_info_ptr->p_driver->video_dec_start();

    /* Pre-parse the next frame */
    if (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HDR_PARSE_FRAME_NUMER)
         <  g_video_dec_info_ptr->total_frames_in_file)
    {
        /* Not the last frame */
        result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
        if (result != MEDIA_STATUS_OK)
        {
            kal_prompt_trace(MOD_MED, "VIDEO_STREAM_PLAY_2_Get_Next_Frame_Err: %d\n", result);
            VIDEO_ASSERT(0);
            return result;
        }

        /* pre-parse the next frame */
        result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);
        if (result != MEDIA_STATUS_OK)
        {
            /* treat the error frame as non-coded */
            kal_prompt_trace(MOD_MED, "VIDEO_STREAM_PLAY_2_Decode_Main_Err: %d\n", result);
            VIDEO_ASSERT(0);
        }
    }
    else
    {
        /* simply test */
        VIDEO_ASSERT(0);
        kal_prompt_trace(MOD_MED, "VIDEO_STREAM_PLAY_Hdr_Parse_Frames_Err\n");
        result = VIDEO_ERROR;
    }

    // AV sync control
     if (g_video_dec_info_ptr->audio_enable == KAL_TRUE)
    {
        /* should align time to audio frame number */
        if (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER)
             < g_video_dec_info_ptr->total_frames_in_file)
        {
            /* simply for test, audio always start from frame number 0 */
            *audio_frame_no = 0;
            //video_dec_translate_av_time(decode_time, &decode_time); // already done in stream_put_frame_to_buffer
            //MP4_SetPlaybackTimerBase((STMp4Parser*)vid_get_audio_parser(), *audio_frame_no, KAL_TRUE);
            //g_video_dec_info_ptr->pre_frame_duration = decode_time;

            /* set dsp according to different audio and video condition */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
            video_set_dec_isr(video_rtp_get_decode_format());
            video_dec_set_frametime((kal_uint32)decode_time, KAL_TRUE);
            video_enable_dec_isr(video_rtp_get_decode_format());
#endif
            g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_PLAY;
        }
        else
        {
            /* simply test */
            kal_prompt_trace(MOD_MED, "VIDEO_STREAM_PLAY_Decode_Frames_Err\n");
            VIDEO_ASSERT(0);
            return VIDEO_ERROR;
        }
    }    /*AUDIO ENABLE*/
    else /*g_video_dec_info_ptr->audio_enable == KAL_TRUE*/
    {
        /* simply test */
        kal_prompt_trace(MOD_MED, "VIDEO_STREAM_PLAY_Audio_Disable_Err\n");
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    return MEDIA_STATUS_OK;
}
#endif

/* This function can recover when error happens
 * @param audio_frame_no   the related audio frame that is related recovered video frame number.
 * @param callback  video callback function when driver want to notify MED or upper layer.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_recover(kal_uint32 * audio_frame_no, void (*callback)(kal_uint8 event))
{
    MEDIA_STATUS_CODE result;
    kal_uint8 *frame_addr;
    kal_uint32 frame_length;
    kal_uint32 audio_frame_number;
    kal_uint32 prev_frame_duration;
    kal_uint32 frame_duration = 0;
    kal_uint32 recheck_count;
//    kal_uint32 savedMask;
    kal_uint64 video_decode_time;   //Should change as kal_uint64
    kal_uint64 audio_decode_time;   //Should change as kal_uint64
    kal_uint64 decode_time;
    kal_bool audio_exist = KAL_TRUE;
    kal_bool audio_end = KAL_FALSE;
    kal_uint32 recover_frame_number;	
    kal_uint32 hdr_parse_frames_no;
    kal_uint32 dec_frames_no;	
    kal_uint64 play_time;	
    static kal_uint32 video_dec_recover_count = 0;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    if ((g_video_dec_info_ptr->stage == VIDEO_DEC_STAGE_STOP)
            || (g_video_dec_info_ptr->stage == VIDEO_DEC_STAGE_CLOSE))
    {
        return MEDIA_STATUS_OK;
    }
    else
    {
        if (g_video_dec_info_ptr->stage != VIDEO_DEC_STAGE_PLAY)
        {
            /* recover should only be happened at play stage */
            VIDEO_ASSERT(0);
            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FUNC_STATE_ERROR;
            return VIDEO_ERROR;
        }
    }

    if(g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_RESTART_STATUS)==KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return MEDIA_STATUS_OK;
    }

    video_dec_disable_irq(video_file_get_decode_type());
    video_dec_stop_av();
    /* reset av time offsets. If previous play has offest, reset it */
    video_dec_rst_av_timeoffset();
    g_video_dec_info_ptr->video_dec_callback = callback;

    /* check video end state */
    recover_frame_number = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_RESTART_FRAME_NUMER);
    if(recover_frame_number == g_video_dec_info_ptr->total_frames_in_file)	
    {
        g_video_dec_info_ptr->video_end = KAL_TRUE;
    #if defined(__VIDEO_EDITOR__)
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            ASSERT(0);
        }
        else
    #endif /*__VIDEO_EDITOR__*/
        {
            video_dec_complete();
        }
        return MEDIA_STATUS_OK;
    }

    video_dec_recover_count++;
    g_video_dec_info_ptr->check_error_recover_count++;
#ifdef VIDEO_DEBUG_MODE	
    kal_prompt_trace(MOD_MED, "Check err: error recover %d\n", g_video_dec_info_ptr->check_error_recover_count);		
#endif

    /* reset other parameters also */
    result = video_dec_struct_init(g_video_dec_info_ptr, g_video_dec_info_ptr->decode_type, g_video_dec_info_ptr->total_frames_in_file, 
                                     recover_frame_number, KAL_TRUE);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }	

    /* prepare bitstream buffer */
    video_dec_clr_buffer(recover_frame_number, g_video_dec_info_ptr->total_frames_in_file+1);
    result = video_dec_put_frame_to_buffer();
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    //Prepare the HW register and bistream of next frame
    hdr_parse_frames_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HDR_PARSE_FRAME_NUMER);
    if (hdr_parse_frames_no < g_video_dec_info_ptr->total_frames_in_file)
    {
        for (recheck_count = 0; recheck_count < 50; recheck_count++)
        {
            /* try to decode until a valid frame */
            if ((recover_frame_number + recheck_count)
                    == g_video_dec_info_ptr->total_frames_in_file)
            {
                g_video_dec_info_ptr->video_end = KAL_TRUE;
#if defined(__VIDEO_EDITOR__)
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
                {
                    ASSERT(0);
                }
                else
#endif /*__VIDEO_EDITOR__*/
                {
                    video_dec_complete();
                }
                break;
            }

            result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
            frame_duration = prev_frame_duration;
            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }

            result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);
            if (result == MEDIA_STATUS_OK)
            {
                /* break when decode valid frame */
                break;
            }
        }
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        /* update decode frame number and write to register */
        if(recheck_count > 0)
        {
            dec_frames_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
            g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER, 
                                                                                     dec_frames_no+recheck_count);	
        }
        g_video_dec_info_ptr->p_driver->video_dec_start();
    }

    hdr_parse_frames_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HDR_PARSE_FRAME_NUMER);
    if (hdr_parse_frames_no < g_video_dec_info_ptr->total_frames_in_file)
    {
        /* get next frame when not last frame */
        result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);
        if (result != MEDIA_STATUS_OK)
        {
            /* treat the error frame as non-coded */
            VIDEO_ASSERT(0);
        }
    }

    /* get video duration*/
    g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser,
                                                        (recover_frame_number - 1), //id = 1~, reviewed
                                                        &video_decode_time,
                                                        MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        VIDEO_ASSERT(0);
        return MP4_PARSER_ERROR;
    }
     /*obtain video play_time, if audio is not enable, play time is got from this time base */
    video_dec_translate_av_time(video_decode_time, &play_time);
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }
    g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_PLAY_TIME, play_time);

    /* get audio frame number */
    g_video_dec_status.PARSE_STATUS = MP4_Audio_Seek_To_Video(g_video_dec_info_ptr->pMp4Parser, video_decode_time,
                                                              &audio_frame_number);
    if (g_video_dec_status.PARSE_STATUS == MP4_PARSER_NO_SUCH_TRACK)
    {
        /*No audio track*/
        audio_frame_number = 0;
        *audio_frame_no = 0;
        audio_decode_time = 0;
        audio_exist = KAL_FALSE;
    }
    else if (g_video_dec_status.PARSE_STATUS == MP4_PARSER_NO_SUCH_SAMPLE)
    {
        audio_frame_number = 0;
        *audio_frame_no = 0;
        audio_decode_time = 0;
        audio_end = KAL_TRUE;
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_SEEK_AUDIO_END;
    }
    else
    {
        *audio_frame_no = audio_frame_number;
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }
        /* get audio duration from frame number */
        g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(g_video_dec_info_ptr->pMp4Parser, audio_frame_number,
                                                            &audio_decode_time,  MP4_TRACK_AUDIO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            VIDEO_ASSERT(0);
            return MP4_PARSER_ERROR;
        }
    }

    /* calculate av time and prepare  set to av */
    audio_decode_time = VIDEO_ANYBASE_TO_ANYBASE(audio_decode_time, g_video_dec_info_ptr->audio_time_scale,
                                                 g_video_dec_info_ptr->video_time_scale);
    if ((audio_exist) && (audio_end == KAL_FALSE))
    {
        /* calculate video and audio offset*/
        result = video_dec_translate_av_time((kal_uint64)(video_decode_time - audio_decode_time), &decode_time);
        /* Rita add,
            1. audio frame and the previous play time may be not the same*/
         MP4_SetPlaybackTimerBase(vid_get_audio_parser(),
                                                   (kal_uint32) VIDEO_ANYBASE_TO_MS(audio_decode_time, g_video_dec_info_ptr->video_time_scale),
                                                   KAL_TRUE);
    }
    else
    {
        decode_time = 0;
        /* Rita add,
            1. frame start time and the previous play time may be not the same*/
         MP4_SetPlaybackTimerBase(vid_get_audio_parser(),
                                                   (kal_uint32) VIDEO_ANYBASE_TO_MS(video_decode_time, g_video_dec_info_ptr->video_time_scale),
                                                   KAL_TRUE);
    }
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

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

    if (audio_end == KAL_FALSE)
        return MEDIA_STATUS_OK;
    else
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }
}


/* This function will seek to the request frame time.
 * @param seek_time seek time
 * @param callback it is callback function when video driver want to notify upper layer.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_seek(kal_uint64 seek_time, void (*callback)(kal_uint8 event))
{
    kal_uint32 frame_no;

    kal_uint8 recheck_count;
    kal_bool seek_from_current_frame_mode;
    MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;

    if(g_video_dec_status.running == KAL_FALSE)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

     ASSERT(callback != NULL);

    g_video_dec_info_ptr->seek_time = VIDEO_ANYBASE_TO_COMMBASE(seek_time, 1000);

    /*obtain video play_time, if audio is not enable, play time is got from this time base */
    g_video_dec_info_ptr->current_play_time = seek_time;
   /* set play back time base, if audio enable, play time is got from this time base */
    MP4_SetPlaybackTimerBase(vid_get_audio_parser(), (kal_uint32)seek_time, KAL_TRUE);

    if ((g_video_dec_info_ptr->seek_time <= g_video_dec_info_ptr->video_duration)
            && (g_video_dec_info_ptr->total_frames_in_file != 0))
    {
        video_dbg_trace(MP4_DEC_VIDEO_SEEK, video_get_current_time());

        /* not video end ==> seek by time = false*/
        g_video_dec_info_ptr->seek_by_time = KAL_FALSE;

        /* find frame no from seek time */
        result = video_dec_get_frame_with_time(&frame_no, g_video_dec_info_ptr->seek_time,
                                               &g_video_dec_info_ptr->seek_next_frame_time);
        ASSERT(frame_no > 0);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        if (frame_no >= g_video_dec_info_ptr->total_frames_in_file)
        {
            g_video_dec_info_ptr->seek_by_time = KAL_TRUE;
        }
     }
     else
     {
        video_dbg_trace(MP4_DEC_AUDIO_SEEK, video_get_current_time());

        /* video end ==> seek by time = true*/
        g_video_dec_info_ptr->seek_by_time = KAL_TRUE;
     }

     if(g_video_dec_info_ptr->seek_by_time==KAL_FALSE)
     {
        for (recheck_count = 0; recheck_count < 50; recheck_count++)
        {
            if ((frame_no - recheck_count) < 1)
                break;

            /* try to seek until a valid frame */
            /* In order to solve one speicial case. add the seek from current frame check */
            /* The case is one video fail has many non-codede frame, so do not use current frame to search when fail one time
                 false means use sync frame as the start seek frame.
                 For this kind of file, first frame -> fail because non-coded. Second-> success from sync .
                 Let the third frame seek from current frame incase it is a normal bitstream fail file */
            seek_from_current_frame_mode = ((recheck_count & 0xf) == 1) ? KAL_FALSE : KAL_TRUE;

            result = video_dec_seek_by_frame(frame_no - recheck_count, callback, seek_from_current_frame_mode);
            if (result == MEDIA_STATUS_OK)
            {
                break;
            }
            else if (VIDEO_GetLastError() == VIDEO_DEC_BITSTREAM_ERROR)
            {
                /* bitstream error, try to seek next */
                continue;
               }
            else
            {
                VIDEO_ASSERT(0);
                break;
            }
        }
    }
    else  /* seek time <= video duration. frame no!=0 */
    {
        if ((g_video_dec_info_ptr->total_frames_in_file != 0) && (g_video_dec_info_ptr->video_duration != 0))
        {
            for (recheck_count = 0; recheck_count < 50; recheck_count++)
            {
                /* video end, so seek to the last frame */
                if ((g_video_dec_info_ptr->total_frames_in_file - recheck_count) < 1)
                    break;

                seek_from_current_frame_mode = ((recheck_count & 0xf) == 1) ? KAL_FALSE : KAL_TRUE;

                result = video_dec_seek_by_frame(g_video_dec_info_ptr->total_frames_in_file - recheck_count,
                                                          callback, seek_from_current_frame_mode);
                if (result == MEDIA_STATUS_OK)
                {
                    break;
                }
                else if (VIDEO_GetLastError() == VIDEO_DEC_BITSTREAM_ERROR)
                {
                    /* bitstream error, try to seek next */
                    continue;
                }
                else
                {
                    VIDEO_ASSERT(0);
                    break;
                }
            }
        }
        else
        {
            /* total frame = 0 */
            g_video_dec_info_ptr->video_dec_callback = callback;
#if defined(__VIDEO_EDITOR__)

            if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                g_video_dec_info_ptr->video_dec_callback(VIDEO_EDITOR_DEC_EVENT_SEEK_DONE);
            }
            else
#endif /*__VIDEO_EDITOR__*/
            {
                g_video_dec_info_ptr->video_dec_callback(VIDEO_DEC_EVENT_SEEK_DONE);
            }
        }
    }

    return result;
}


/* Seek action during seek procedure
 * This function is to replace the HISR action.
 * @param None
 * @return None
 */
void video_seek_action(void)
{
    kal_uint32 frame_length;
    kal_uint32 prev_frame_duration;
    kal_uint32 prev_frame_duration_temp;
    kal_uint32 dec_frame_no=0;	
    kal_uint8 *frame_addr;
    MEDIA_STATUS_CODE result;
    static kal_uint32 veditor_prev_frame_duration = 0;       /* for video editor */

    /* This function acts task level seek action (parse from sync frame to the seek time)*/
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    if (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER) 
         == g_video_dec_info_ptr->total_frames_in_file)
    {
        /* the last one frame */
        VIDEO_ASSERT(0);

#if defined(__VIDEO_EDITOR__)
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            g_video_dec_info_ptr->video_dec_callback(VIDEO_EDITOR_EVENT_FAIL);
        }
        else
#endif /*__VIDEO_EDITOR__*/
        {
            g_video_dec_info_ptr->video_dec_callback(VIDEO_DEC_EVENT_FAIL);
        }
        return;
    }

    video_dbg_trace(MP4_DEC_SEEK_HISR_START, video_get_current_time());
#ifdef VIDEO_DEC_YUV_MODE
    g_video_dec_info_ptr->width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_WIDTH);
    g_video_dec_info_ptr->height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HEIGHT);	
    g_video_dec_info_ptr->real_width = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_WIDTH);
    g_video_dec_info_ptr->real_height = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_REAL_HEIGHT);		
    video_dec_store_yuv_file(mpeg4_dec_get_display_frame_addr(), (g_video_dec_info_ptr->width * g_video_dec_info_ptr->height * 3 / 2));
#endif /*VIDEO_DEC_YUV_MODE*/

    while (1)
    {
        if (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_HDR_PARSE_FRAME_NUMER)  
             == g_video_dec_info_ptr->total_frames_in_file)
        {
            /* seek to end of file */
            g_video_dec_info_ptr->seek_frame_number = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
#if defined(__VIDEO_EDITOR__)
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                g_video_dec_info_ptr->video_dec_callback(VIDEO_EDITOR_DEC_EVENT_SEEK_DONE);
            }
            else
#endif /*__VIDEO_EDITOR__*/

            {
                g_video_dec_info_ptr->video_dec_callback(VIDEO_DEC_EVENT_SEEK_DONE);
            }
            break;
        }

        /* get frame from bitstream buffer and decode */
        result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration_temp);
        veditor_prev_frame_duration += prev_frame_duration_temp;
        if (result != MEDIA_STATUS_OK)
        {
            /* task can not prepare enough data*/
            /* in new architecture, this can not happen. It may only fill one buffer (no buffer empty case) */
            /* prepare the maximum re-check frame at initial */
            VIDEO_ASSERT(0);

        #if defined(__VIDEO_EDITOR__)
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                g_video_dec_info_ptr->video_dec_callback(VIDEO_EDITOR_EVENT_FAIL);
            }
            else
        #endif /*__VIDEO_EDITOR__*/
            {
                g_video_dec_info_ptr->video_dec_callback(VIDEO_DEC_EVENT_FAIL);
            }
            return;
        }
        else
        {
            prev_frame_duration = veditor_prev_frame_duration;
            veditor_prev_frame_duration = 0;
        }

        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_FORCE_FAST_DECODE, KAL_TRUE);
        result = g_video_dec_info_ptr->p_driver->video_dec_parse_data(frame_addr, frame_length, prev_frame_duration, KAL_FALSE);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            veditor_prev_frame_duration = prev_frame_duration;
        }

        if (g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_CUR_FRAME_CODED) == KAL_TRUE)
        {
            /* decode the coded frame */
            g_video_dec_info_ptr->p_driver->video_dec_start();
            break;
        }
        else
        {
            /* non-coded frame */
            /* skip the non-coded frame directly, and parse next frame directly */
#if defined(__VIDEO_EDITOR__)
			if ( (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR) && (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_START) )
			{
			 	visual_active_hisr(VISUAL_MP4_EDITOR_LISR_HISR_ID);
			 	break;
			}
			else
#else
			{
	         dec_frame_no = g_video_dec_info_ptr->p_driver->video_get_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER);
            dec_frame_no++;
            g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_DEC_FRAME_NUMER, dec_frame_no);	
			}
#endif
            if ((dec_frame_no == g_video_dec_info_ptr->seek_frame_number) || (dec_frame_no == g_video_dec_info_ptr->stop_frame_no))
            {
            #if defined(__VIDEO_EDITOR__)
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
                {
		            if (VIDEO_EDITOR_DATA.veditor_state != VIEDO_EDITOR_STATE_START)
		            {
	                	g_video_dec_info_ptr->video_dec_callback(VIDEO_EDITOR_DEC_EVENT_SEEK_DONE);
		            }
                }
                else
            #endif /*__VIDEO_EDITOR__*/
                {
                    g_video_dec_info_ptr->video_dec_callback(VIDEO_DEC_EVENT_SEEK_DONE);
                }
                break;
            }
        }
    }

    video_dbg_trace(MP4_DEC_SEEK_HISR_END, video_get_current_time());
}


/* This function stop the video driver, but not release the resource.
 * @param None
 * @return None
 */
void video_dec_stop(void)
{
    if(g_video_dec_status.running == KAL_FALSE)
    {
        ASSERT(0);
    }

    video_dec_internal_stop();
    if(g_video_dec_info_ptr->p_driver !=NULL)
    {
        g_video_dec_info_ptr->p_driver->video_dec_reset(g_video_enc_status.running);
        g_video_dec_info_ptr->p_driver->video_set_param(VIDEO_DEC_PARAM_TMP_PLAY_TIME, 0);	// to avoid tmp_play_time error.
    }

    g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_STOP;
}


/* Close the video decode process.
 * @param None
 * @return None
 */
void video_dec_close(void)
{
    kal_uint32 savedMask;

    if (g_video_dec_status.running == KAL_TRUE)
    {
        /* If g_video_dec_info_ptr==NULL, it means video_dec_open not success */
        if(g_video_dec_info_ptr!=NULL)
        {
            /*stop  */
            video_dec_internal_stop();
            g_video_dec_info_ptr->pMp4Parser = NULL;
            g_video_dec_info_ptr->video_end = KAL_TRUE;
            if(g_video_dec_info_ptr->p_driver !=NULL)
            {
                g_video_dec_info_ptr->p_driver->video_dec_reset(g_video_enc_status.running);
            }

            savedMask = SaveAndSetIRQMask();
            //DRV_Reg(DRVPDN_CON3) |= (DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
           *PDN_SET3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
            RestoreIRQMask(savedMask);

            g_video_dec_info_ptr->stage = VIDEO_DEC_STAGE_CLOSE;
            g_video_dec_info_ptr = NULL;

#ifdef VIDEO_DEC_YUV_MODE
            FSAL_Close(&FSAL_VIDEO_YUV_FILE);
#endif /*VIDEO_DEC_YUV_MODE*/
        }

        g_video_dec_status.running = KAL_FALSE;
    }
}

#ifdef PGDL_SUPPORT
MP4_Parser_Status MP4_Video_GetAvailableDur(STMp4Parser *pstMp4Parser, kal_uint32 *puVideoDuration)
{
	   MP4_Parser_Status ret;
	   kal_uint32 uVidDuration, uVideoSampleNo, uSampleOffset, start_index=0, end_index=0, uVideoLastSampleNo;
	   kal_uint32 file_size, uVideoTimeScale, uVidDurationMs, uStep;
	
	   FSAL_GetFileSize(pstMp4Parser->pstFSAL, &file_size);	
	  
	    //*puVideoDuration = 216576;
	    //return MP4_PARSER_OK;
	    
	   *puVideoDuration = 0;
	   // duration in sample count
	   if ((ret=MP4_GetMediaDuration(pstMp4Parser, &uVidDuration, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) {
			video_dbg_trace(PDL_VidDuration_Error, uVidDuration);
		  return ret;
	   	}
	   if (uVidDuration==0) {
	      video_dbg_trace(PDL_VidDuration_Error, uVidDuration);
	      return MP4_PARSER_PARSE_ERROR;
	   }
	
	   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uVideoTimeScale, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) {
		  video_dbg_trace(PDL_VidTimeScale_Error, uVideoTimeScale);
		  return ret;
	   }
#if 0	
/* under construction !*/
/* under construction !*/
#endif	     
	   uVideoLastSampleNo = pstMp4Parser->stMp4Track[pstMp4Parser->bVideoTrack].uSampleCount;

       uStep = uVideoLastSampleNo/16;
       uVidDurationMs = (kal_uint64)uVidDuration * (kal_uint64)1000 / (kal_uint64)uVideoTimeScale;

	   uVideoSampleNo = pstMp4Parser->stMp4Track[pstMp4Parser->bVideoTrack].uGetAvaDurCurSampleCnt;
	   if(uVideoSampleNo > 0)
		  uVideoSampleNo -= 1;

       if (uStep==0)  // Some file may contain less than 16 samples.
	       uStep = 1;
	   
	   while(1) // For coarse search.
	   {
	
		  if ((ret=MP4_GetSampleOffset(pstMp4Parser, uVideoSampleNo, &uSampleOffset, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) {
		  	video_dbg_trace(PDL_GetSampleOffset_Error1, uSampleOffset*10000+uVideoSampleNo);
			 return ret;
		  }
	
		  if((kal_int32)file_size <= (kal_int32)uSampleOffset){
			 break;
		  }else{
			 if( (uVideoSampleNo + uStep) < uVideoLastSampleNo ) {
				uVideoSampleNo += uStep;
			 } else {
				uVideoSampleNo = uVideoLastSampleNo;
				break;
			 }
		  }
	
	   }

	   if (uStep == 1) {
           end_index = uVideoSampleNo;
	   } else {	      
		if(end_index < start_index){
		    end_index = start_index;
		} else {
		    start_index = pstMp4Parser->stMp4Track[pstMp4Parser->bVideoTrack].uGetAvaDurCurSampleCnt;
		    end_index = uVideoSampleNo;
		    // Binary Search
		    while ((kal_int32)(end_index-start_index)>1) { // For finer search
		         kal_uint32 middle_index = (start_index + end_index) / 2;
	
		         if ((ret=MP4_GetSampleOffset(pstMp4Parser, middle_index, &uSampleOffset, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) {
			        video_dbg_trace(PDL_GetSampleOffset_Error2, uSampleOffset*10000+uVideoSampleNo);
			        return ret;
		         }
	
		         if ((kal_int32)file_size > (kal_int32)uSampleOffset)
			        start_index = middle_index;
		         else
			        end_index = middle_index;
		    }
		    if ((end_index > start_index) && (end_index < uVideoLastSampleNo))	 // Set to the smaller one to avoid the sample offset of end_index > real file_size except for end_index = the last sample case.
		        end_index = start_index;
		}
	   }
	   pstMp4Parser->stMp4Track[pstMp4Parser->bVideoTrack].uGetAvaDurCurSampleCnt = end_index;
       if ((end_index==1)&&((kal_int32)file_size < (kal_int32)uSampleOffset)) // for the case that downloads partial the first 1 sample
         *puVideoDuration = 0;
       else
	     *puVideoDuration = (kal_uint64)end_index * (kal_uint64)uVidDurationMs / (kal_uint64)uVideoLastSampleNo;

	   if (*puVideoDuration != 0) {
		video_dbg_trace(PDL_GetAvailDur_GT_0, end_index*100000 + (kal_int32)file_size);
	   } else {
		video_dbg_trace(PDL_GetAvailDur_EQ_0, video_get_current_time());
	   }
	   return MP4_PARSER_OK;
}
#endif

MP4_Parser_Status MP4_Meta_Estimate_FPS(STMp4Parser *pstMp4Parser, kal_uint32 *uFPS)
{
   STMp4Track *p_track;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

	p_track = &(pstMp4Parser->stMp4Track[pstMp4Parser->bVideoTrack]);
	if (p_track == NULL)
	{
      		return MP4_PARSER_PARSE_TRAK_ERROR;
	} else {
      		kal_uint32 uMediaTimeScale = p_track->uMediaTimeScale;
		kal_uint32 uMediaDuration = p_track->uMediaDuration;
		kal_uint32 uSampleCount = p_track->uSampleCount;

		if ( (uMediaTimeScale==0)||(uMediaDuration==0)||(uSampleCount==0) )
		{
			return MP4_PARSER_PARSE_ERROR;
		} else {
			kal_uint32 duration_ms = VIDEO_ANYBASE_TO_ANYBASE(uMediaDuration, uMediaTimeScale, 1000);
			if ( (uSampleCount == 0)||(duration_ms < 1000)||(duration_ms > (1000*uSampleCount)) )
				*uFPS = 10;
			else
			  *uFPS = uSampleCount / (duration_ms/1000);
		}
	}

	return MP4_PARSER_OK;
}

#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
