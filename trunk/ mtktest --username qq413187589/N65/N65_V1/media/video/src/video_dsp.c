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
 *   video_dsp.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   This file defines the interface between video driver and DSP API.
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
#include "intrCtrl.h"
#include "visualhisr.h"
#include "gpt_sw.h"

static VIDEO_DEC_AV_STRUCT g_video_dec_av_info;

static void video_dec_set_dsp_frametime(kal_uint32 duration, kal_bool add_dsp_delay);
static void video_dec_GPT_frame_callback(void * parameter);
static void video_dec_set_GPT_frametime(kal_uint32 duration);
static void VIDEO_AV_DUMMY2_ISR(void);
static void VIDEO_AV_DUMMY_ISR(void);


/* This function will obtain the timestamp from DSP.
 * @param None
 * @return DSP time stamp. (audio interrupt count)
 */
kal_uint32 video_enc_get_timestamp(void)
{
    return Media_A2V_GetInterruptCount();
}


/* Set AV sync callback function and enable AV intr 
 * @param av_callback AV sync intr callback function
 * @return None.
 */
void video_dec_set_enable_av_callback(video_dec_av_callback av_callback)
{
    kal_uint32 savedMask;
    
    savedMask = SaveAndSetIRQMask();
    g_video_dec_av_info.av_callback = av_callback;
    Media_A2V_EnableInterrupt(KAL_FALSE, 0);
    Media_A2V_HookInterrupt(g_video_dec_av_info.av_callback);
    if (g_video_dec_av_info.av_type == VIDEO_DEC_AV_AUDIO)
    {
        Media_A2V_EnableInterrupt(KAL_TRUE, 0);
    }
    RestoreIRQMask(savedMask);
}


/* Set AV sync callback function (not enable or disable interrupt) 
 * @param av_callback AV sync intr callback function
 * @return None.
 */
void video_dec_set_av_callback(video_dec_av_callback av_callback)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();
    g_video_dec_av_info.av_callback = av_callback;
    Media_A2V_HookInterrupt(g_video_dec_av_info.av_callback);
    RestoreIRQMask(savedMask);
}


/* Stop AV sync 
 * @param None.
 * @return None.
 */
void video_dec_stop_av(void)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();
    g_video_dec_av_info.av_callback = NULL;
    Media_A2V_HookInterrupt(g_video_dec_av_info.av_callback);
    RestoreIRQMask(savedMask);

    Media_A2V_EnableInterrupt(KAL_FALSE, 0);
    
    if(g_video_dec_av_info.gpt_audintr_handle!=0)
        GPTI_StopItem(g_video_dec_av_info.gpt_audintr_handle);
}


/* Set AV time base according to differnet scenario
 * @param av_type.  VIDEO_DEC_AV_TYPE 
 * @param video_timebase. 
 * @param audio_timebase.  
 * @param audio_playback_delay.  
 * @return None.
 */
void video_dec_set_av_timebase(VIDEO_DEC_AV_TYPE av_type, kal_uint64 video_timebase, kal_uint64 audio_timebase, kal_uint32 audio_playback_delay)
{
    g_video_dec_av_info.av_type = av_type;

    g_video_dec_av_info.video_timebase = video_timebase;
    g_video_dec_av_info.audio_timebase = audio_timebase;
    g_video_dec_av_info.audio_playback_delay = audio_playback_delay;
    g_video_dec_av_info.video_time_offset = 0;
    g_video_dec_av_info.speed_offset = 0;
    g_video_dec_av_info.pre_frame_duration = 0;	

    if (g_video_dec_av_info.gpt_audintr_handle == 0)
        GPTI_GetHandle(&g_video_dec_av_info.gpt_audintr_handle);
}


/* Reset AV time offset. The time calculation has some moduler offset. Reset the offset before a new play time 
 * @param None.  
 * @return None.
 */
void video_dec_rst_av_timeoffset(void)
{
    g_video_dec_av_info.video_time_offset = 0;
    g_video_dec_av_info.speed_offset = 0;
}


/* This function will tranlate video count based on video time unit to av interrupt count
 * @param  video_count video count based on video time unit.
 * @param  av_intr_count The av interrupt count number.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_translate_av_time(kal_uint64 video_count, kal_uint64 * av_intr_count)
{
    kal_uint64 temp_audio_intr_count;

    if (g_video_dec_av_info.video_timebase == 0)
        EXT_ASSERT(0, 0, 0, 0);

    if (g_video_dec_av_info.av_type == VIDEO_DEC_AV_AUDIO)
    {
        /* Translate to audio interrupt count*/
        temp_audio_intr_count = VIDEO_ANYBASE_TO_ANYBASE(video_count, g_video_dec_av_info.video_timebase, g_video_dec_av_info.audio_timebase);

        *av_intr_count = (temp_audio_intr_count + g_video_dec_av_info.video_time_offset) / 1024;
        g_video_dec_av_info.video_time_offset = (temp_audio_intr_count + g_video_dec_av_info.video_time_offset) % 1024;
    }
    else if (g_video_dec_av_info.av_type == VIDEO_DEC_AV_GPT)
    {
        /* translate to gpt base */
        *av_intr_count = VIDEO_ANYBASE_TO_GPTBASE(video_count, g_video_dec_av_info.video_timebase);
    }
    else if (g_video_dec_av_info.av_type == VIDEO_DEC_AV_COMMON)
    {
        /* translate to common base */
        *av_intr_count = VIDEO_ANYBASE_TO_COMMBASE(video_count, g_video_dec_av_info.video_timebase);
    }
    else
    {
        EXT_ASSERT(0, g_video_dec_av_info.av_type, 0, 0);
    }

    return MEDIA_STATUS_OK;
}


/* This function set frame duration to DSP or GPT. DSP/GPT will trigger MCU, if the duration is reached.
 * @param  delay frame duration.
 * @param  add_dsp_delay is add dsp const delay.
 * @return None
 */
void video_dec_set_frametime(kal_uint32 duration, kal_bool add_dsp_delay)
{
    kal_uint64 video_time;

    g_video_dec_av_info.pre_frame_duration = duration;
		
    if (g_video_dec_info_ptr->play_speed != 100)
    {
       /* calculate time according to speed */
        video_time = (((kal_uint64)duration * 16384 + (kal_uint64)g_video_dec_av_info.speed_offset) * 100) / 
                          (((kal_uint64)g_video_dec_info_ptr->play_speed) * 16384);
        g_video_dec_av_info.speed_offset = (((kal_uint64)duration * 16384 + (kal_uint64)g_video_dec_av_info.speed_offset) * 100 / 
        	                                                ((kal_uint64)g_video_dec_info_ptr->play_speed)) % 16384;
    }
    else
    {
        g_video_dec_av_info.speed_offset = 0;
        video_time = duration;
    }

    /* Set time according to av type */
    if (g_video_dec_av_info.av_type == VIDEO_DEC_AV_AUDIO)
    {
        video_dec_set_dsp_frametime((kal_uint32)video_time, add_dsp_delay);
    }
    else if (g_video_dec_av_info.av_type == VIDEO_DEC_AV_GPT)
    {
        video_dec_set_GPT_frametime((kal_uint32)video_time);
    }
    else
    {
        EXT_ASSERT(0, g_video_dec_av_info.av_type, 0, 0);
    }
}


/* Set time to DSP interrupt 
 * @param  duration. DSP ticks
 * @param  add_dsp_delay is add dsp const delay.
 * @return None
 */
static void video_dec_set_dsp_frametime(kal_uint32 duration, kal_bool add_dsp_delay)
{
    kal_uint64 video_time;
    kal_uint32 audio_time;

    if (add_dsp_delay == KAL_TRUE)
    {
        g_video_dec_av_info.video_frame_duration_tick = duration + g_video_dec_av_info.audio_playback_delay;
    }
    else
    {
        g_video_dec_av_info.video_frame_duration_tick = duration;
    }

    if (g_video_dec_av_info.video_frame_duration_tick <= 32000)
    {
        Media_A2V_SetTimeStamp((kal_uint16)g_video_dec_av_info.video_frame_duration_tick);
        Media_A2V_HookInterrupt(g_video_dec_av_info.av_callback);
    }
    else if (g_video_dec_av_info.video_frame_duration_tick <= 64000)
    {
        Media_A2V_SetTimeStamp((kal_uint16)(g_video_dec_av_info.video_frame_duration_tick / 2));
        Media_A2V_HookInterrupt(VIDEO_AV_DUMMY2_ISR);
    }
    else
    {
        Media_A2V_SetTimeStamp(32000);
        Media_A2V_HookInterrupt(VIDEO_AV_DUMMY_ISR);
    }

    /* For long video duration, should refresh */
     if (g_video_dec_av_info.av_type == VIDEO_DEC_AV_AUDIO)
    {
        audio_time = duration * 1024;
        video_time = VIDEO_ANYBASE_TO_MS(audio_time, g_video_dec_av_info.audio_timebase);
        video_dec_check_refresh(video_time);
    }
    else
    {
        EXT_ASSERT(0, g_video_dec_av_info.av_type, 0, 0);
    } 
}

/* This function is for type conversion. Convert GPT callback function to AV callback function 
 * @param None
 * @return None
 */
static void video_dec_GPT_frame_callback(void * parameter)
{
    GPTI_StopItem(g_video_dec_av_info.gpt_audintr_handle);

    if(g_video_dec_av_info.av_callback!=NULL)
        g_video_dec_av_info.av_callback();
}


/* Set time to GPT interrupt 
 * @param  duration. GPT ticks
 * @return None
 */
static void video_dec_set_GPT_frametime(kal_uint32 duration)
{
    kal_uint32 video_time;

    if (duration > 0xffff)
        duration = 0xffff;

    GPTI_StartItem(g_video_dec_av_info.gpt_audintr_handle, (kal_uint16)duration, video_dec_GPT_frame_callback, NULL);

    /* For long video duration, should refresh */
    video_time = VIDEO_ANYBASE_TO_MS(duration, VIDEO_GPT_TIME_BASE);
    video_dec_check_refresh(video_time);
}

kal_uint64 video_dec_get_audio_timebase()
{
    return g_video_dec_av_info.audio_timebase;
}

kal_uint64 video_dec_get_video_timebase()
{
    return g_video_dec_av_info.video_timebase;
}

VIDEO_DEC_AV_TYPE video_dec_get_av_type()
{
    return g_video_dec_av_info.av_type;
}

kal_uint32 video_dec_get_prev_frametime(void)
{
    return g_video_dec_av_info.pre_frame_duration;
}

/* Dummy AV ISR function. For long duration.
 * @param None
 * @return None
 */
static void VIDEO_AV_DUMMY2_ISR(void)
{
    g_video_dec_av_info.video_frame_duration_tick -= (g_video_dec_av_info.video_frame_duration_tick / 2);

    if (g_video_dec_av_info.video_frame_duration_tick > 32000)
        EXT_ASSERT(0, g_video_dec_av_info.video_frame_duration_tick, 0, 0);

    Media_A2V_SetTimeStamp((kal_uint16)g_video_dec_av_info.video_frame_duration_tick);
    Media_A2V_HookInterrupt(g_video_dec_av_info.av_callback);
}


/* Dummy AV ISR function. For long duration.
 * @param None
 * @return None
 */
static void VIDEO_AV_DUMMY_ISR(void)
{
    if (g_video_dec_av_info.video_frame_duration_tick <= 64000)
        EXT_ASSERT(0, g_video_dec_av_info.video_frame_duration_tick, 0, 0);

    g_video_dec_av_info.video_frame_duration_tick -= 32000;

    if (g_video_dec_av_info.video_frame_duration_tick <= 64000)
    {
        Media_A2V_SetTimeStamp((kal_uint16)(g_video_dec_av_info.video_frame_duration_tick / 2));
        Media_A2V_HookInterrupt(VIDEO_AV_DUMMY2_ISR);
    }
    else
    {
        Media_A2V_SetTimeStamp(32000);
        Media_A2V_HookInterrupt(VIDEO_AV_DUMMY_ISR);
    }
}
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
