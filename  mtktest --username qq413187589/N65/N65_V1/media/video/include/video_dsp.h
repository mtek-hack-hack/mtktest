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
 *   video_dsp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video decode dsp definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VIDEO_DSP_H
#define VIDEO_DSP_H

/* AV sync type */
typedef enum
{
    VIDEO_DEC_AV_AUDIO,
    VIDEO_DEC_AV_GPT,
    VIDEO_DEC_AV_COMMON
}VIDEO_DEC_AV_TYPE;

typedef void (*video_dec_av_callback)(void);

/* AV control strcuture */
typedef struct
{
    VIDEO_DEC_AV_TYPE av_type;
    video_dec_av_callback av_callback;
    kal_uint8 gpt_audintr_handle;
    kal_uint64 video_timebase;
    kal_uint64 audio_timebase;
    kal_uint32 audio_playback_delay;
    kal_uint32 video_frame_duration_tick;
    kal_uint16 video_time_offset;
    kal_uint16 speed_offset;
    kal_uint32 pre_frame_duration;	
} VIDEO_DEC_AV_STRUCT;

/* This function will obtain the timestamp from DSP.
 * @param None
 * @return DSP time stamp. (audio interrupt count)
 */
extern kal_uint32 video_enc_get_timestamp(void);


/* Set AV sync callback function and enable AV intr 
 * @param av_callback AV sync intr callback function
 * @return None.
 */
extern void video_dec_set_enable_av_callback(video_dec_av_callback av_callback);


/* Set AV sync callback function (not enable or disable interrupt) 
 * @param av_callback AV sync intr callback function
 * @return None.
 */
extern void video_dec_set_av_callback(video_dec_av_callback av_callback);


/* Stop AV sync 
 * @param None.
 * @return None.
 */
extern void video_dec_stop_av(void);


/* Set AV time base according to differnet scenario
 * @param av_type.  VIDEO_DEC_AV_TYPE 
 * @param video_timebase. 
 * @param audio_timebase.  
 * @param audio_playback_delay.  
 * @return None.
 */
extern void video_dec_set_av_timebase(VIDEO_DEC_AV_TYPE av_type, kal_uint64 video_timebase, kal_uint64 audio_timebase, kal_uint32 audio_playback_delay);


/* Reset AV time offset. The time calculation has some moduler offset. Reset the offset before a new play time 
 * @param None.  
 * @return None.
 */
extern void video_dec_rst_av_timeoffset(void);

/* This function will tranlate video count based on video time unit to av interrupt count
 * @param  video_count video count based on video time unit.
 * @param  av_intr_count The av interrupt count number.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_translate_av_time(kal_uint64 video_count, kal_uint64 * av_intr_count);


/* This function set frame duration to DSP or GPT. DSP/GPT will trigger MCU, if the duration is reached.
 * @param  delay frame duration.
 * @param  add_dsp_delay is add dsp const delay.
 * @return None
 */
extern void video_dec_set_frametime(kal_uint32 duration, kal_bool add_dsp_delay);

extern kal_uint32 video_dec_get_prev_frametime(void);

#endif /*VIDEO_DSP_H*/
