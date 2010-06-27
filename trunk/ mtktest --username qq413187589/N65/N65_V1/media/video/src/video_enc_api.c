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
 *   video_enc_api.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   This file defines encode APIs for media task
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
#include "dma_hw.h"
#include "dma_sw.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "cache_sw.h"

#ifdef MP4_MOVE_LISR_TO_HISR 
extern void video_enc_dma_first_HISR(void);
#endif

extern void MPEG4_ENC_HISR(void);

extern void MPEG4_ENC_LISR(void);

extern kal_uint8 video_isr_count;

extern kal_uint32 video_enc_trigger_limit;

extern kal_uint32 video_toal_save_bytes;

extern kal_bool video_enc_proc_race_check;

extern VIDEO_ENC_START_RECORD_STATE video_is_start_record;
#ifdef DRV_MP4_V2
static kal_uint32 SavedCacheCtrl;
#endif /*DRV_MP4_V2*/

Media_Format video_enc_audio_format;
kal_uint32 pause_current_time_stamp;
/*resume start or normal start*/
kal_bool video_enc_start_by_resume;

void (*audio_record_callback)(Media_Event event);
void video_encode_drv_pause_info_restore(void);
VIDEO_ENC_PAUSE_INFO video_enc_pause_info;

kal_uint32 video_enc_prev_time_value;
static kal_mutexid  g_video_enc_time_mutex;

MEDIA_STATUS_CODE video_enc_open(kal_uint32 frame_width, kal_uint32 frame_height, kal_uint32 frame_count,
                                 kal_bool resume)
{
    kal_uint32 savedMask;

    MEDIA_STATUS_CODE result;

    video_toal_save_bytes = 0;
    video_enc_trigger_limit = 0;
    video_enc_proc_race_check = KAL_FALSE;
    video_is_start_record = VIDEO_ENC_START_RECORD_STATE_STOP;
#ifdef DRV_MP4_V2
    SavedCacheCtrl = Lock2WaysForMPEG4();
#endif /*DRV_MP4_V2*/

    savedMask = SaveAndSetIRQMask();
    //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);

    RestoreIRQMask(savedMask);
#ifdef __VIDEO_GET_YUV_DATA__
    {
        kal_wchar out_name[16] = L"x:\\isp.yuv";

        /*out_name[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);*/
        out_name[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if ((frame_width * frame_height) > (176 * 144))
        {
            video_yuv.cif_size = 1;
            video_yuv.yuv_max_buffer_count = VIDEO_YUV_MAX_BUFFER;
        }
        else
        {
            video_yuv.cif_size = 0;
            video_yuv.yuv_max_buffer_count = VIDEO_YUV_MAX_BUFFER * 4;
        }

        g_video_enc_status.FSAL_STATUS = FSAL_Open(&video_yuv.MEDIA_YUV_FILE, out_name, FSAL_WRITE);
        ASSERT(g_video_enc_status.FSAL_STATUS == FSAL_OK);
    }
#endif /*__VIDEO_GET_YUV_DATA__*/

    mpeg4_enc_reset();
#ifdef MP4_MOVE_LISR_TO_HISR     
    VISUAL_Register_HISR(VISUAL_MPEG4_ENC_FIRST_DMA_HISR_ID, video_enc_dma_first_HISR);
#endif    
    VISUAL_Register_HISR(VISUAL_MPEG4_ENC_HISR_ID, MPEG4_ENC_HISR);
#ifdef DRV_MP4_V1
    g_video_dec_info_ptr = NULL;
#else /*!DRV_MP4_V1*/
    if (g_video_dec_status.running == KAL_FALSE)
        mpeg4_core_reset();
#endif /*DRV_MP4_V1*/

    g_video_enc_status.running = KAL_TRUE;

    if (resume == KAL_FALSE)
    {
        kal_uint32 index;
        {
#if defined(__VIDEO_EDITOR__)
            if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
            	if (VIDEO_EDITOR_DATA.is_new_video == KAL_TRUE)
            	{
            		g_video_enc_info_ptr = (VIDEO_ENC_STRUCT *)extmem_get_buffer(sizeof(VIDEO_ENC_STRUCT));
	               for (index = 0; index < VIDEO_ENC_MAX_BUFFER_COUNT; index++)
	               {
	                   g_video_enc_info_ptr->VIDEO_ENC_BUFFER[index].buffer = (kal_uint8 *)extmem_get_buffer(
	                                                                              VIDEO_EDITOR_ENC_BUFFER_SIZE);
	                   g_video_enc_info_ptr->VIDEO_ENC_BUFFER[index].buffer_length = VIDEO_EDITOR_ENC_BUFFER_SIZE;
	               }
						video_enc_resource_init(frame_width, frame_height);
               }
            }
            else
#endif /*__VIDEO_EDITOR__*/
            {
            	 g_video_enc_info_ptr = (VIDEO_ENC_STRUCT *)extmem_get_buffer(sizeof(VIDEO_ENC_STRUCT));
                for (index = 0; index < VIDEO_ENC_MAX_BUFFER_COUNT; index++)
                {
                    g_video_enc_info_ptr->VIDEO_ENC_BUFFER[index].buffer = (kal_uint8 *)
                                                                               extmem_get_buffer(VIDEO_ENC_BUFFER_SIZE);
                    g_video_enc_info_ptr->VIDEO_ENC_BUFFER[index].buffer_length = VIDEO_ENC_BUFFER_SIZE;
                }
					 video_enc_resource_init(frame_width, frame_height);
            }
        }
    }

    result = mp4_enc_struct_init(g_video_enc_info_ptr, MMFILE_MP4, frame_count);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    video_isr_count = 0;
    savedMask = SaveAndSetIRQMask();
#ifdef DRV_MP4_V1
    IRQ_Register_LISR(IRQ_MPEG4_CODE, MPEG4_ENC_LISR, "MPEG4");
    IRQSensitivity(IRQ_MPEG4_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_MPEG4_CODE);
#else /*!DRV_MP4_V1*/
    IRQ_Register_LISR(IRQ_MPEG4_ENC_CODE, MPEG4_ENC_LISR, "MPEG4");
    IRQSensitivity(IRQ_MPEG4_ENC_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/
    RestoreIRQMask(savedMask);
    g_video_enc_info_ptr->stage = VIDEO_ENC_STAGE_OPEN;
    return MEDIA_STATUS_OK;
}

void video_enc_stop_record(void)
{
    g_video_enc_info_ptr->encode_stop = KAL_TRUE;
}

void video_enc_close(void)
{
    kal_uint32 savedMask;

    kal_uint8 check_count;
    /*To guarantee at least one frame*/
    for (check_count = 0; check_count < 15; check_count++)
    {
        if (g_video_enc_info_ptr->hisr_total_frames > 1)
            break;
        else
            kal_sleep_task(6);
    }

    g_video_enc_info_ptr->encode_stop = KAL_TRUE;
    mpeg4_enc_wait_done();
#ifdef DRV_MP4_V1
    IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
    IRQMask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/

    mpeg4_enc_reset();
#ifdef DRV_MP4_V2
    if (g_video_dec_status.running == KAL_FALSE)
        mpeg4_core_reset();
#endif /*DRV_MP4_V2*/

    savedMask = SaveAndSetIRQMask();
    //DRV_Reg(DRVPDN_CON3) |= (DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    *PDN_SET3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);

    RestoreIRQMask(savedMask);
    video_enc_audio_format = 0;
    g_video_enc_info_ptr->stage = VIDEO_ENC_STAGE_CLOSE;
#ifdef DRV_MP4_V2
    Unlock2WaysForMPEG4(SavedCacheCtrl);
#endif /*DRV_MP4_V2*/

    g_video_enc_status.running = KAL_FALSE;
}

MEDIA_STATUS_CODE video_enc_init(MP4ENC_SETUP_STRUCT *setup_input, kal_bool resume_enable)
{
    MEDIA_STATUS_CODE result;

    if (g_video_enc_time_mutex == 0)
        g_video_enc_time_mutex = kal_create_mutex("VIDEO_ENC_TIME_MUTEX");

    video_enc_prev_time_value = 0;
    g_video_enc_info_ptr->bit_rate = setup_input->bit_rate;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (g_video_enc_info_ptr->skip_frame_count == 0)
    {
        g_video_enc_info_ptr->FRAME_RATE = 15;
    }
    else
    {
        g_video_enc_info_ptr->FRAME_RATE = 15 / (g_video_enc_info_ptr->skip_frame_count + 1);
        if (g_video_enc_info_ptr->FRAME_RATE == 0)
            g_video_enc_info_ptr->FRAME_RATE = 1;
    }

    if (g_video_enc_info_ptr->FRAME_RATE > Video_Enc_Max_FrameRate)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FRAME_RATE_ERROR;
        return VIDEO_ERROR;
    }

    if (resume_enable == KAL_FALSE)
    {
        video_enc_start_by_resume = KAL_FALSE;

        video_enc_pause_info.pause_already = KAL_FALSE;
        result = video_enc_initialize(setup_input, &g_video_enc_info_ptr->im);
        g_video_enc_info_ptr->prev_time_stamp = 0;
        g_video_enc_info_ptr->current_time_duration = 0;
        video_enc_pause_info.current_time_duration = 0;
        video_enc_pause_info.time_scale = 0;
    }
    else
    {
        video_enc_start_by_resume = KAL_TRUE;

        video_encode_drv_pause_info_restore();
        result = video_enc_resume_init(setup_input, &g_video_enc_info_ptr->im);
    }

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_encode_comm_setup(MP4ENC_SETUP_STRUCT *setup_input)
{
    MEDIA_STATUS_CODE result;

    pause_current_time_stamp = 0;
    //video encode driver initialize
    result = video_enc_open(setup_input->frame_width, setup_input->frame_height, 0, KAL_FALSE);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    //Total bitsteam buffers, as .mp4 file
    /*Jensen: camera dynamic frame rate, so this mechanism should be disable*/
    //g_video_enc_info_ptr->skip_frame_count = skip_frame_count;
    g_video_enc_info_ptr->skip_frame_count = 0;
    g_video_enc_info_ptr->total_file_size = 0;

    result = video_enc_init(setup_input, KAL_FALSE);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    g_video_enc_info_ptr->large_quant_count = 0;
    g_video_enc_info_ptr->video_enc_callback = setup_input->call_back;
    g_video_enc_info_ptr->stage = VIDEO_ENC_STAGE_INIT;
    video_is_start_record = VIDEO_ENC_START_RECORD_STATE_START;
    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_encode_setup(MP4ENC_SETUP_STRUCT *setup_input)
{
    MEDIA_STATUS_CODE result;

    g_video_enc_status.scenario = VIDEO_SCENARIO_ENCODE;
    result = video_encode_comm_setup(setup_input);
    return result;
}

MEDIA_STATUS_CODE video_encode_resume_setup(MP4ENC_SETUP_STRUCT *setup_input)
{
    MEDIA_STATUS_CODE result;

    g_video_enc_status.scenario = VIDEO_SCENARIO_ENCODE;

    //video encode driver initialize
    result = video_enc_open(setup_input->frame_width, setup_input->frame_height, 0, KAL_TRUE);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    //Total bitsteam buffers, as .mp4 file
    /*Jensen: camera dynamic frame rate, so this mechanism should be disable*/
    //g_video_enc_info_ptr->skip_frame_count = skip_frame_count;
    g_video_enc_info_ptr->skip_frame_count = 0;

    result = video_enc_init(setup_input, KAL_TRUE);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    g_video_enc_info_ptr->force_I_frame = KAL_TRUE;
#if defined(DRV_MP4_ENC_MODIFY_SPECIAL_Q_FOR_IFRAME)
    { // To ensure not specific q
        extern void video_modify_q_for_IFrame(kal_int32 *quant, kal_uint32 total_frames, kal_bool b_force_I_frame);
        video_modify_q_for_IFrame(&(g_video_enc_info_ptr->im.quantizer), g_video_enc_info_ptr->total_frames, g_video_enc_info_ptr->force_I_frame);
    }	
#endif
    g_video_enc_info_ptr->video_enc_callback = setup_input->call_back;
    g_video_enc_info_ptr->stage = VIDEO_ENC_STAGE_INIT;
    video_is_start_record = VIDEO_ENC_START_RECORD_STATE_RESUME_START;
    return MEDIA_STATUS_OK;
}

void video_encode_drv_pause(void)
{
#if defined(__VIDEO_EDITOR__)
    if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        ASSERT(0);
    //pause_current_time_stamp = video_editor_get_current_time_stamp();
    }
    else
#endif /*__VIDEO_EDITOR__*/

    {
        pause_current_time_stamp = video_enc_get_timestamp();
    }

    kal_mem_cpy(&video_enc_pause_info.im, &g_video_enc_info_ptr->im, sizeof(m4v_enc_im));
    kal_mem_cpy(&video_enc_pause_info.rc_data, video_enc_get_rc_data(), sizeof(RC_STRUCT));
    video_enc_pause_info.current_time_duration = g_video_enc_info_ptr->current_time_duration;
    video_enc_pause_info.prev_time_stamp = g_video_enc_info_ptr->prev_time_stamp;
    video_enc_pause_info.total_frames = g_video_enc_info_ptr->total_frames;
    video_enc_pause_info.hisr_total_frames = g_video_enc_info_ptr->hisr_total_frames;
    video_enc_pause_info.bit_rate = g_video_enc_info_ptr->bit_rate;
    video_enc_pause_info.FRAME_RATE = g_video_enc_info_ptr->FRAME_RATE;
    video_enc_pause_info.video_enc_audio_format = video_enc_audio_format;
#if defined(__VIDEO_EDITOR__)
    if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        //video_enc_pause_info.time_scale = 32768;
        ASSERT(0);
    }
    else
#endif /*__VIDEO_EDITOR__*/

    {
        video_enc_pause_info.time_scale = Media_A2V_GetRecInterruptTimeScale(video_enc_audio_format, 0x0b);
    }

    video_enc_pause_info.total_file_size = g_video_enc_info_ptr->total_file_size;
    video_enc_pause_info.pause_already = KAL_TRUE;
}

void video_encode_drv_pause_info_restore(void)
{
    ASSERT(video_enc_pause_info.pause_already == KAL_TRUE);

    video_enc_set_rc_data(&video_enc_pause_info.rc_data);
    kal_mem_cpy(&g_video_enc_info_ptr->im, &video_enc_pause_info.im, sizeof(m4v_enc_im));
    g_video_enc_info_ptr->current_time_duration = video_enc_pause_info.current_time_duration;
    g_video_enc_info_ptr->prev_time_stamp = video_enc_pause_info.prev_time_stamp;
    g_video_enc_info_ptr->total_frames = video_enc_pause_info.hisr_total_frames;
    g_video_enc_info_ptr->hisr_total_frames = video_enc_pause_info.hisr_total_frames;
    g_video_enc_info_ptr->bit_rate = video_enc_pause_info.bit_rate;
    g_video_enc_info_ptr->FRAME_RATE = video_enc_pause_info.FRAME_RATE;
    g_video_enc_info_ptr->total_file_size = video_enc_pause_info.total_file_size;
    video_enc_audio_format = video_enc_pause_info.video_enc_audio_format;
    video_enc_pause_info.pause_already = KAL_FALSE;
}

kal_uint32 video_enc_get_prev_time_stamp(void)
{
    return pause_current_time_stamp;
}

/*Unit: ms*/
kal_uint64 video_enc_get_current_time(void)
{
    kal_uint64 timescale;

    kal_uint64 result;
    kal_uint32 current_ticks;
    kal_uint32 savedMask;
    Media_Format audio_format;
    static kal_uint64 current_time_duration = 0;
    static kal_uint32 prev_time_stamp = 0;	

    kal_take_mutex(g_video_enc_time_mutex);

    savedMask = SaveAndSetIRQMask();
    
    audio_format = video_enc_audio_format;

    if (video_enc_pause_info.pause_already == KAL_TRUE)
    {
        if (video_enc_pause_info.time_scale == 0)
            result = 0;
        else
            result = VIDEO_ANYBASE_TO_MS(video_enc_pause_info.current_time_duration, video_enc_pause_info.time_scale);
        RestoreIRQMask(savedMask);       
    }
    else if (audio_format == 0)
    {
        if (video_is_start_record != VIDEO_ENC_START_RECORD_STATE_STOP)
        {
            if (g_video_enc_info_ptr->encode_stop != KAL_TRUE)
            {
                if (video_enc_pause_info.time_scale == 0)
                {
                    result = 0;
                }
                else
                {
                    result = VIDEO_ANYBASE_TO_MS(video_enc_pause_info.current_time_duration,
                                                 video_enc_pause_info.time_scale);
                }
            }
            else
            {
                result = video_enc_prev_time_value;
            }
        }
        else
        {
            result = 0;
        }
        RestoreIRQMask(savedMask);
    }
    else if ((video_enc_start_by_resume == KAL_TRUE)
                 && (video_is_start_record
                         != VIDEO_ENC_START_RECORD_STATE_RUNING)) /*MMI/MED will block during pause/resume/restart*/
    {
        if (video_enc_pause_info.time_scale == 0)
            result = 0;
        else
        {
            result = VIDEO_ANYBASE_TO_MS(video_enc_pause_info.current_time_duration, video_enc_pause_info.time_scale);
        }
        RestoreIRQMask(savedMask);
    }
    else
    {
        RestoreIRQMask(savedMask);
    
        timescale = Media_A2V_GetRecInterruptTimeScale(audio_format, 0x0b);
        if (timescale == 0)
            result = 0;
        else
        {
            current_ticks = video_enc_get_timestamp();

            if(g_video_enc_info_ptr!=NULL)
            {
                if (current_ticks >= g_video_enc_info_ptr->prev_time_stamp)
                    g_video_enc_info_ptr->current_time_duration += (current_ticks - g_video_enc_info_ptr->prev_time_stamp);
                else
                    g_video_enc_info_ptr->current_time_duration += (0xffffffff - g_video_enc_info_ptr->prev_time_stamp
                                                                        + current_ticks);

                g_video_enc_info_ptr->prev_time_stamp = current_ticks;

                result = VIDEO_ANYBASE_TO_MS(g_video_enc_info_ptr->current_time_duration, timescale);
            }
            else
            {
                if (current_ticks >= prev_time_stamp)
                    current_time_duration += (current_ticks - prev_time_stamp);
                else
                    current_time_duration += (0xffffffff - prev_time_stamp
                                                                        + current_ticks);

                prev_time_stamp = current_ticks;

                result = VIDEO_ANYBASE_TO_MS(current_time_duration, timescale); 
            }
        }
    }

    video_enc_prev_time_value = result;
    //RestoreIRQMask(savedMask);
    kal_give_mutex(g_video_enc_time_mutex);	
    return result;
}

void video_enc_audiocallback(void (*audio_rec_callback)(Media_Event event))
{
    audio_record_callback = audio_rec_callback;
}

void video_enc_set_audioformat(Media_Format audio_format)
{
    video_enc_audio_format = audio_format;
}

kal_uint32 video_enc_get_bitstream_file_size(void)
{
    return g_video_enc_info_ptr->total_file_size;
}
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
