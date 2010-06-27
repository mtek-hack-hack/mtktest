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
 *   video_enc_isr.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   This file defines the isr handler of mpeg4 encode
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
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
#include "video_hw.h"
#include "intrCtrl.h"
#include "visualhisr.h"

//extern MP4_FILELIST_STRUCT mp4_files;

const kal_uint8 mp4_vop_non_coded_frame[6] =
{
    0x00, 0x00, 0x01, 0xb6, 0x50, 0xcf
};

extern kal_uint32 TOTAL_frame_num;

extern kal_uint32 pause_current_time_stamp;

kal_uint32 video_enc_trigger_limit = 0;
kal_uint32 video_toal_save_bytes = 0;
kal_uint8 video_isr_count;
VIDEO_ENC_START_RECORD_STATE video_is_start_record;

static void video_enc_dma_lisr_func(kal_uint32 encode_work_yuv);

extern void putbits(kal_uint8 *in,kal_int32 *bitcnt, kal_int32 data, kal_int32 data_length);

extern kal_uint16 get_camera_frame_period(void);

extern void Media_A2V_SetInterruptCount(kal_uint32 uInterruptCount);

#if defined(DRV_MP4_ENC_MODIFY_SPECIAL_Q_FOR_IFRAME)
extern void video_modify_q_for_IFrame(kal_int32 *quant, kal_uint32 total_frames, kal_bool b_force_I_frame);
#endif

kal_uint32 resume_buffer_temp[512 / 4];
kal_bool video_assert_check = KAL_TRUE;

#ifdef __L1_STANDALONE__
kal_bool video_next;
#endif

#if defined(__VIDEO_EDITOR__)
extern void video_enc_done_send_ilm(VIDEO_ENC_STRUCT *enc_struct);
#endif

void MPEG4ENC_ISR_ERROR_REPORT_HANDLER(void)
{
#ifdef DRV_MP4_V1
   IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
   IRQMask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/

   video_enc_stop_record();
    //Stop ImageDMA isr
    ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);
#if defined(__VIDEO_EDITOR__)
    if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_EVENT_FAIL);
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
        g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_FAIL);
    }
}

void MPEG4ENC_ISR_ERROR_STATUS_REPORT_HANDLER(VIDEO_ENC_STATUS video_status)
{
#ifdef DRV_MP4_V1
   IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
   IRQMask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/

   video_enc_stop_record();
    //Stop ImageDMA isr
    g_video_enc_status.VIDEO_STATUS = video_status;
    ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);
#if defined(__VIDEO_EDITOR__)
    if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_EVENT_FAIL);
    }
    else
#endif /*__VIDEO_EDITOR__*/

    {
        g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_FAIL);
    }
}

void video_enc_error_hisr(void)
{
    ASSERT(0);
}

void video_enc_switch_buffer_encdone_hisr(void)
{
    g_video_enc_info_ptr->is_need_to_check_buffer = KAL_FALSE;

    VISUAL_Register_HISR(VISUAL_MP4_ENC_RECOVERY1_HISR_ID, video_enc_error_hisr);
    //sendilm & switch buffer
    ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);

    if (g_video_enc_info_ptr->is_task_prepare_video_data == KAL_FALSE)
    {
#if defined(__VIDEO_EDITOR__)
        if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_ENC_EVENT_VIDEO_BUFFER_AVAIL);
        }
        else
#endif /*__VIDEO_EDITOR__*/

        {
            g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_VIDEO_BUFFER_AVAIL);
        }
        g_video_enc_info_ptr->is_task_prepare_video_data = KAL_TRUE;
    }
}

void video_enc_switch_buffer_encdone_callback(void)
{
    VISUAL_Register_HISR(VISUAL_MP4_ENC_RECOVERY1_HISR_ID, video_enc_switch_buffer_encdone_hisr);

    visual_active_hisr(VISUAL_MP4_ENC_RECOVERY1_HISR_ID);
}

void video_enc_switch_buffer_dma_hisr(void)
{
    kal_uint32 length;

    VISUAL_Register_HISR(VISUAL_MP4_ENC_RECOVERY2_HISR_ID, video_enc_error_hisr);
    ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);

    if (g_video_enc_info_ptr->is_task_prepare_video_data == KAL_FALSE)
    {
#if defined(__VIDEO_EDITOR__)
        if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_ENC_EVENT_VIDEO_BUFFER_AVAIL);
        }
        else
#endif /*__VIDEO_EDITOR__*/

        {
            g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_VIDEO_BUFFER_AVAIL);
        }
        g_video_enc_info_ptr->is_task_prepare_video_data = KAL_TRUE;
    }

    //Restart this transation by assigning another buffer
    length = video_enc_buffer_get_roomleft(g_video_enc_info_ptr);
    g_video_enc_info_ptr->current_bitstream_addr = video_enc_buffer_get_memaddr(g_video_enc_info_ptr);

    //VIDEO_ENC_WRITE_VLCLIMIT_REG(length/4);
#ifdef DRV_MP4_V1
   DRV_WriteReg32(MP4_VLC_LIMIT, (length / 4));
    video_enc_trigger_limit = ((length / 4) * 4);
    DRV_WriteReg32(MP4_VLC_ADDR, g_video_enc_info_ptr->current_bitstream_addr);
    DRV_WriteReg32(MP4_VLC_COMD, MP4_VLC_COMD_RELOAD);
#else /*!DRV_MP4_V1*/
   DRV_WriteReg32(MP4_CORE_VLC_LIMIT, (length / 4));
    video_enc_trigger_limit = ((length / 4) * 4);
    DRV_WriteReg32(MP4_CORE_VLC_ADDR, g_video_enc_info_ptr->current_bitstream_addr);
    DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);
#endif /*DRV_MP4_V1*/

}

void video_enc_switch_buffer_dma_callback(void)
{
    VISUAL_Register_HISR(VISUAL_MP4_ENC_RECOVERY2_HISR_ID, video_enc_switch_buffer_dma_hisr);

    visual_active_hisr(VISUAL_MP4_ENC_RECOVERY2_HISR_ID);
}

void MPEG4_ENC_ERROR_REPORT_HISR(void)
{
    video_dbg_trace(MP4_ENC_ERR_REPT_HISR, video_get_current_time());

    MPEG4ENC_ISR_ERROR_REPORT_HANDLER();
}

void video_enc_hisr_send_avail_ilm(void)
{
    VISUAL_Register_HISR(VISUAL_MP4_ENC_RECOVERY2_HISR_ID, video_enc_error_hisr);

    ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);
#if defined(__VIDEO_EDITOR__)
    if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_ENC_EVENT_VIDEO_BUFFER_AVAIL);
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
        g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_VIDEO_BUFFER_AVAIL);
    }

    g_video_enc_info_ptr->is_task_prepare_video_data = KAL_TRUE;
}

void video_enc_isr_send_avail_ilm(void)
{
    VISUAL_Register_HISR(VISUAL_MP4_ENC_RECOVERY2_HISR_ID, video_enc_hisr_send_avail_ilm);

    visual_active_hisr(VISUAL_MP4_ENC_RECOVERY2_HISR_ID);
}

kal_bool video_enc_check_buffer(void)
{
    if (g_video_enc_info_ptr->is_need_to_check_buffer)
    {
        g_video_enc_info_ptr->lost_frames++;
        g_video_enc_info_ptr->check_camera_miss_count++;	
        g_video_enc_info_ptr->b_check_log = KAL_TRUE;		

        if (video_enc_get_buffer_status(g_video_enc_info_ptr))
        {
            g_video_enc_info_ptr->is_need_to_check_buffer = KAL_FALSE;

            g_video_enc_info_ptr->force_I_frame = KAL_TRUE;
            g_video_enc_info_ptr->chk_buffer_status_count = 0;
            if (g_video_enc_info_ptr->switch_buffer_callback)
                g_video_enc_info_ptr->switch_buffer_callback();
        }
        else
        {
            g_video_enc_info_ptr->chk_buffer_status_count++;
            if (g_video_enc_info_ptr->chk_buffer_status_count > 50)
            {
                VIDEO_ASSERT(0);

                g_video_enc_info_ptr->encode_stop = KAL_TRUE;
                g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
#ifdef DRV_MP4_V1
            IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
            IRQMask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/

            VISUAL_Register_HISR(VISUAL_MPEG4_ENC_HISR_ID, MPEG4_ENC_ERROR_REPORT_HISR);
                visual_active_hisr(VISUAL_MPEG4_ENC_HISR_ID);
                return KAL_FALSE;
            }
        }
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

kal_bool video_enc_check_frame_with_cam_video(void)
{
    if (g_video_enc_info_ptr->total_frames != g_video_enc_info_ptr->hisr_total_frames)
    {
        video_dbg_trace(MP4_ENC_DMA_LISR_FRAMEQUICK, video_get_current_time());

        g_video_enc_info_ptr->safty_check_count++;
        g_video_enc_info_ptr->check_buffer_miss_count++;	
        g_video_enc_info_ptr->b_check_log = KAL_TRUE;				

        if (g_video_enc_info_ptr->safty_check_count >= 3)
        {
            VIDEO_ASSERT(0);

            g_video_enc_info_ptr->encode_stop = KAL_TRUE;
            g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
#ifdef DRV_MP4_V1
         IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
         IRQMask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/

         VISUAL_Register_HISR(VISUAL_MPEG4_ENC_HISR_ID, MPEG4_ENC_ERROR_REPORT_HISR);
            visual_active_hisr(VISUAL_MPEG4_ENC_HISR_ID);
            return KAL_FALSE;
        }
        //      g_video_enc_info_ptr->lost_frames++;                                                                  
        return KAL_FALSE;
    }

    g_video_enc_info_ptr->safty_check_count = 0;
    return KAL_TRUE;
}

kal_bool video_enc_check_encode_state(void)
{
    if (g_video_enc_info_ptr->encode_stop == KAL_TRUE)
        return KAL_FALSE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (g_video_enc_info_ptr->large_quant_count != 0)
    {
        g_video_enc_info_ptr->large_quant_count = 0;
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

void video_enc_lisr_process(kal_uint32 encode_work_yuv, kal_uint32 time_stamp, kal_uint32 delay_offset)
{
    kal_uint32 length;

    MEDIA_STATUS_CODE result;
    MP4ENC_PROC_STRUCT mp4enc_proc_input;

    video_dbg_trace(MP4_ENC_DMA_LISR_ENTRY1, video_get_current_time());

    if (video_enc_check_encode_state() == KAL_FALSE)
    {
    	  #if defined(__VIDEO_EDITOR__)
			if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
         {
             VIDEO_ASSERT(0);
         }
        #endif /*__VIDEO_EDITOR__*/
        return;
    }

    if (video_enc_check_buffer() == KAL_FALSE)
    {
    		#if defined(__VIDEO_EDITOR__)
			if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
         {
             VIDEO_ASSERT(0);
         }
        	#endif /*__VIDEO_EDITOR__*/
        return;
    }

    if (video_enc_check_frame_with_cam_video() == KAL_FALSE)
    {
    		#if defined(__VIDEO_EDITOR__)
			if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
         {
             VIDEO_ASSERT(0);
         }
        	#endif /*__VIDEO_EDITOR__*/
        return;
    }
#if defined(__VIDEO_EDITOR__)
    if ((video_is_start_record != VIDEO_ENC_START_RECORD_STATE_RESUME_START)
            || (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR))
#else  /*!__VIDEO_EDITOR__*/
    if (video_is_start_record != VIDEO_ENC_START_RECORD_STATE_RESUME_START)
#endif /*__VIDEO_EDITOR__*/
    {
        video_is_start_record = VIDEO_ENC_START_RECORD_STATE_RUNING;
        if (g_video_enc_info_ptr->total_frames != 0)
        {
            VIDEO_ASSERT(time_stamp >= delay_offset);
            g_video_enc_info_ptr->time_stamp = time_stamp - delay_offset;
        }
        else
        {
#ifdef __VIDEO_EDITOR__
            if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                VIDEO_ASSERT(time_stamp >= delay_offset);
                g_video_enc_info_ptr->time_stamp = time_stamp - delay_offset;
            }
            else
#endif /*__VIDEO_EDITOR__*/
            {
                g_video_enc_info_ptr->time_stamp = 0;
                g_video_enc_info_ptr->const_delay = Media_A2V_GetAudioRecordDelay(video_enc_audio_format);
            }
        }
    }
    else
    {
        video_is_start_record = VIDEO_ENC_START_RECORD_STATE_START;
        return;
    }

    video_dbg_trace(MP4_ENC_DMA_LISR_ENTRY, video_get_current_time());
#ifdef __L1_STANDALONE__
#ifndef __VIDEO_EDITOR__
    if (((g_video_enc_info_ptr->total_frames != TOTAL_frame_num) && (video_next == KAL_FALSE))
            || ((video_next == KAL_TRUE) && (g_video_enc_info_ptr->total_frames != (TOTAL_frame_num * 2)))) //Jensen
#endif                                                                                                      /*__VIDEO_EDITOR__*/
#endif                                                                                                      /*__L1_STANDALONE__*/
    {
        g_video_enc_info_ptr->current_bitstream_addr = video_enc_buffer_get_memaddr(g_video_enc_info_ptr);

        length = video_enc_buffer_get_roomleft(g_video_enc_info_ptr);

        if (length == 0)
        {
            if (video_enc_switch_buffer(g_video_enc_info_ptr))
            {
                ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);

                if (g_video_enc_info_ptr->is_task_prepare_video_data == KAL_FALSE)
                {
                    video_enc_isr_send_avail_ilm();
                }

                g_video_enc_info_ptr->current_bitstream_addr = video_enc_buffer_get_memaddr(g_video_enc_info_ptr);
                length = video_enc_buffer_get_roomleft(g_video_enc_info_ptr);
            }
            else
            {
                g_video_enc_info_ptr->is_need_to_check_buffer = KAL_TRUE;

                g_video_enc_info_ptr->switch_buffer_callback = NULL;
                g_video_enc_info_ptr->lost_frames++;
                return;
            }
        }

#if defined(__VIDEO_EDITOR__)        
        if (g_video_dec_status.scenario != VIDEO_SCENARIO_EDITOR)
#endif   /*__VIDEO_EDITOR__*/
        {
            video_enc_fr_evalutaion(15);
        }
        mp4enc_proc_input.frame = g_video_enc_info_ptr->total_frames;
        mp4enc_proc_input.input_yuv_data = (kal_uint8 *)encode_work_yuv;
        mp4enc_proc_input.bitstreams_ptr = (kal_uint8 *)g_video_enc_info_ptr->current_bitstream_addr;
        mp4enc_proc_input.buffer_length = length;
        mp4enc_proc_input.im = &g_video_enc_info_ptr->im;
        mp4enc_proc_input.b_force_I_frame = g_video_enc_info_ptr->force_I_frame;
        mp4enc_proc_input.pkt_size_limit = 0;
        result = video_enc_proc(&mp4enc_proc_input);
        g_video_enc_info_ptr->force_I_frame = KAL_FALSE;

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);

            g_video_enc_info_ptr->encode_stop = KAL_TRUE;
            g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
#ifdef DRV_MP4_V1
            IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
            IRQMask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/
            VISUAL_Register_HISR(VISUAL_MPEG4_ENC_HISR_ID, MPEG4_ENC_ERROR_REPORT_HISR);
            visual_active_hisr(VISUAL_MPEG4_ENC_HISR_ID);
            return;
        }

        g_video_enc_info_ptr->total_frames++;
        video_dbg_trace(MP4_ENC_DMA_LISR_END, video_get_current_time());
    }
}


#ifdef MP4_MOVE_LISR_TO_HISR 

static kal_uint32 g_mpeg4_enc_dma_addr;

void video_enc_dma_lisr(kal_uint32 encode_yuv)
{
    g_mpeg4_enc_dma_addr = encode_yuv;
    visual_active_hisr(VISUAL_MPEG4_ENC_FIRST_DMA_HISR_ID);
}

void video_enc_dma_first_HISR(void)
{
    video_enc_dma_lisr_func(g_mpeg4_enc_dma_addr);
}

#else
void video_enc_dma_lisr(kal_uint32 encode_yuv)
{
    video_enc_dma_lisr_func(encode_yuv);
}
#endif


static void video_enc_dma_lisr_func(kal_uint32 encode_work_yuv)
{
    kal_uint32 time_stamp;

    kal_uint32 delay_offset;

    if (g_video_enc_info_ptr->encode_stop == KAL_TRUE)
        return;
#ifdef __VIDEO_GET_YUV_DATA__
    if ((((video_yuv.write_index + 1) & 7) != video_yuv.read_index) && (video_yuv.enable_log == KAL_TRUE))
    {
        if (video_yuv.cif_size == 1)
        {
            kal_mem_cpy(video_yuv.yuvdata.yuvCIF[video_yuv.write_index], (void *)encode_work_yuv,
                        (g_video_enc_info_ptr->im.width * g_video_enc_info_ptr->im.height * 3 / 2));
        }
        else
        {
            kal_mem_cpy(video_yuv.yuvdata.yuvQCIF[video_yuv.write_index], (void *)encode_work_yuv,
                        (g_video_enc_info_ptr->im.width * g_video_enc_info_ptr->im.height * 3 / 2));
        }

        video_yuv.write_index++;
        video_yuv.write_index = video_yuv.write_index % video_yuv.yuv_max_buffer_count;
        visual_active_hisr(VISUAL_MPEG4_ENC_HISR_ID);
    }
    else
    {
        video_yuv.enable_log = KAL_FALSE;
        return;
    }

    return;
#else /*__VIDEO_GET_YUV_DATA__*/

   video_enc_fr_evalutaion_init(15);

    time_stamp = video_enc_get_timestamp();
    delay_offset = g_video_enc_info_ptr->const_delay + VIDEO_ANYBASE_TO_ANYBASE(
                                                           get_camera_frame_period(),
                                                           1000,
                                                           Media_A2V_GetRecInterruptTimeScale(
                                                               video_enc_audio_format, 0x0b));

    video_enc_lisr_process(encode_work_yuv, time_stamp, delay_offset);
#endif /*__VIDEO_GET_YUV_DATA__*/

}

void MPEG4_ENC_LISR(void)
{
#ifdef DRV_MP4_V1
   IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
   IRQMask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/

    visual_active_hisr(VISUAL_MPEG4_ENC_HISR_ID);
    video_dbg_trace(MP4_ENC_MP4LISR_ENTRY, video_get_current_time());
}

void MPEG4_ENC_HISR(void)
{
#ifdef __VIDEO_GET_YUV_DATA__
    ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);

    if (video_yuv.send_ilm)
    {
#if defined(__VIDEO_EDITOR__)
        if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_ENC_EVENT_VIDEO_BUFFER_AVAIL);
        }
        else
#endif /*__VIDEO_EDITOR__*/
        {
            g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_VIDEO_BUFFER_AVAIL);
        }
        video_yuv.send_ilm = KAL_FALSE;
    }

    return;
#else /*__VIDEO_GET_YUV_DATA__*/

    kal_uint32 temp_ptr;
    kal_uint32 temp_int;
    kal_uint32 bitcnt;
    kal_uint32 frame_length;
    kal_uint32 length;
    kal_uint32 status;
    kal_bool isr_error = KAL_TRUE;
    MEDIA_STATUS_CODE result;
#ifdef DRV_MP4_V1
    status = DRV_Reg32(MP4_IRQ_STS);
    DRV_WriteReg32(MP4_IRQ_ACK, status);
#else /*!DRV_MP4_V1*/
    status = DRV_Reg32(MP4_ENC_IRQ_STS);
    DRV_WriteReg32(MP4_ENC_IRQ_ACK, status);
#endif /*DRV_MP4_V1*/

#ifdef VIDEO_DEBUG_MODE		
    if(g_video_enc_info_ptr->b_check_log == KAL_TRUE)
    {
        g_video_enc_info_ptr->b_check_log = KAL_FALSE;
        kal_prompt_trace(MOD_MED, "Check err: buffer miss %d\n", g_video_enc_info_ptr->check_buffer_miss_count);
        kal_prompt_trace(MOD_MED, "Check err: camera miss %d\n", g_video_enc_info_ptr->check_camera_miss_count);				
    }
#endif

    if (status == 0)
    {
        VIDEO_ASSERT(0);

        video_dbg_trace(MP4_MAY_ISR_ERROR, video_get_current_time());
        return;
    }

    if (g_video_enc_info_ptr->is_send_ilm)
    {
        ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);

        if (g_video_enc_info_ptr->is_task_prepare_video_data == KAL_FALSE)
        {
#if defined(__VIDEO_EDITOR__)
            if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_ENC_EVENT_VIDEO_BUFFER_AVAIL);
            }
            else
#endif /*__VIDEO_EDITOR__*/
            {
                g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_VIDEO_BUFFER_AVAIL);
            }
            g_video_enc_info_ptr->is_task_prepare_video_data = KAL_TRUE;
        }
        g_video_enc_info_ptr->is_send_ilm = KAL_FALSE;
    }
#ifdef DRV_MP4_V1
    if (status & MP4_IRQ_STS_ENC)
#else  /*!DRV_MP4_V1*/
    if (status & MP4_ENC_IRQ_STS_ENC)
#endif /*DRV_MP4_V1*/

    {
        video_dbg_trace(MP4_ENC_HISR_OK, video_get_current_time());

        isr_error = KAL_FALSE;
#ifdef DRV_MP4_V1
        DRV_WriteReg32(MP4_CODEC_COMD, 0x04); // Video Object Plane Level start
        temp_ptr = DRV_Reg32(MP4_VLC_WORD);
        temp_int = DRV_Reg32(MP4_VLC_BITCNT);
        bitcnt = (temp_ptr - (kal_int32)g_video_enc_info_ptr->current_bitstream_addr) * 8 + temp_int;
        DRV_WriteReg32(MP4_VLC_COMD, MP4_VLC_COMD_STOP);
#else /*!DRV_MP4_V1*/
        temp_ptr = DRV_Reg32(MP4_ENC_VLC_WORD);
        temp_int = DRV_Reg32(MP4_ENC_VLC_BITCNT);
        bitcnt = (temp_ptr - (kal_int32)g_video_enc_info_ptr->current_bitstream_addr) * 8 + temp_int;
#endif /*DRV_MP4_V1*/

        if (g_video_enc_info_ptr->drop_bitstream == KAL_TRUE)
        {
            g_video_enc_info_ptr->force_I_frame = KAL_TRUE;

            g_video_enc_info_ptr->drop_bitstream = KAL_FALSE;
            g_video_enc_info_ptr->total_frames--;
        }
        else
        {
            g_video_enc_info_ptr->im.quantizer = RC_UPdated(g_video_enc_info_ptr->bit_rate,
                                                            g_video_enc_info_ptr->im.frame_rate,
                                                            g_video_enc_info_ptr->im.quantizer,
                                                            g_video_enc_info_ptr->im.width,
                                                            g_video_enc_info_ptr->im.height,
                                                            (kal_int32)(bitcnt + (video_toal_save_bytes * 8)),
                                                            (kal_int32)g_video_enc_info_ptr->im.predition_type,
                                                            g_video_enc_info_ptr->total_frames, 
                                                            g_video_enc_info_ptr->force_I_frame,
                                                            1);

            if (g_video_enc_info_ptr->im.quantizer > 31)
                g_video_enc_info_ptr->large_quant_count++;

#if 1
            // stuffing bits to byte-aligned
            if (g_video_enc_info_ptr->im.short_header == 0) 
            {	
                // stuffing bits: one zero and followed by 1 to 7 ones
                putbits((kal_uint8 *)g_video_enc_info_ptr->current_bitstream_addr, (kal_int32 *)&bitcnt,0,1);
                while ((bitcnt & 7) != 0)
                    putbits((kal_uint8 *)g_video_enc_info_ptr->current_bitstream_addr, (kal_int32 *)&bitcnt,1,1);
            } 
            else 
            {	
                // short-header mode: stuffing bits all zeros
                while ((bitcnt & 7) != 0)
                   putbits((kal_uint8 *)g_video_enc_info_ptr->current_bitstream_addr, (kal_int32 *)&bitcnt,0,1);
            }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

            frame_length = (bitcnt / 8) + (((bitcnt & 7) == 0) ? 0 : 1);

            video_enc_buffer_update_offset(frame_length);

            /*Set total file size, for size limit*/
            g_video_enc_info_ptr->total_file_size += frame_length;
#if defined(__VIDEO_EDITOR__)
            if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_ENC_EVENT_COUNT_FILE_SIZE);
            }
            else
#endif /*__VIDEO_EDITOR__*/
            {
                g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_COUNT_FILE_SIZE);
            }

            //time_stamp = video_enc_get_timestamp();
            result = mp4_video_enc_push_tableinfo_to_buffer(g_video_enc_info_ptr->time_stamp,
                                                            (frame_length
                                                             + video_toal_save_bytes)); //store to another buffer

            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);

                MPEG4ENC_ISR_ERROR_REPORT_HANDLER();
                return;
            }

            video_enc_trigger_limit = 0;
            video_toal_save_bytes = 0;
            //address exchange
#ifdef DRV_MP4_V1
            temp_int = DRV_Reg32(MP4_REF_ADDR);
            DRV_WriteReg32(MP4_REF_ADDR, DRV_Reg32(MP4_REC_ADDR));
            DRV_WriteReg32(MP4_REC_ADDR, temp_int);
#else /*!DRV_MP4_V1*/
            temp_int = DRV_Reg32(MP4_ENC_REF_ADDR);
            DRV_WriteReg32(MP4_ENC_REF_ADDR, DRV_Reg32(MP4_ENC_REC_ADDR));
            DRV_WriteReg32(MP4_ENC_REC_ADDR, temp_int);
#endif /*DRV_MP4_V1*/
            g_video_enc_info_ptr->hisr_total_frames++;
        }
#if defined(__VIDEO_EDITOR__)
        if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            VIDEO_EDITOR_DATA.encode_complete_call_back();
            if (VIDEO_EDITOR_DATA.check_end_call_back() == KAL_TRUE)
            {
                extern void video_enc_done_send_ilm(VIDEO_ENC_STRUCT *enc_struct);
                video_enc_done_send_ilm(g_video_enc_info_ptr);
            }
        }
#endif /*__VIDEO_EDITOR__*/
#ifdef __L1_STANDALONE__
#ifndef __VIDEO_EDITOR__
        if (((g_video_enc_info_ptr->hisr_total_frames == TOTAL_frame_num) && (video_next == KAL_FALSE))
                || ((video_next == KAL_TRUE) && (g_video_enc_info_ptr->hisr_total_frames == (TOTAL_frame_num * 2))))
        {
            video_enc_done_send_ilm(g_video_enc_info_ptr);
        }
#endif
#endif /*__L1_STANDALONE__*/

    }
#ifdef DRV_MP4_V1
    else if (status & MP4_IRQ_STS_DMA)
#else /*!DRV_MP4_V1*/
   else if(status&MP4_ENC_IRQ_STS_DMA)
#endif   /*DRV_MP4_V1*/    
    {
        video_dbg_trace(MP4_ENC_HISR_DMA, video_get_current_time());

        isr_error = KAL_FALSE;

#ifdef DRV_MP4_V1_ENC_PAUSE_P_NOT_SUPPORT
        if (g_video_enc_info_ptr->im.predition_type == I_VOP)
#else  /*!DRV_MP4_V1_ENC_PAUSE_P_NOT_SUPPORT*/
        if (1)
#endif /*DRV_MP4_V1_ENC_PAUSE_P_NOT_SUPPORT*/
            {
                video_toal_save_bytes += video_enc_trigger_limit;

                video_enc_buffer_update_offset(video_enc_trigger_limit);
                //sendilm & switch buffer
                if (video_enc_switch_buffer(g_video_enc_info_ptr))
                {
                    ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);

                    if (g_video_enc_info_ptr->is_task_prepare_video_data == KAL_FALSE)
                    {

#if defined(__VIDEO_EDITOR__)
                        if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
                        {
                            g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_ENC_EVENT_VIDEO_BUFFER_AVAIL);
                        }
                        else
#endif /*__VIDEO_EDITOR__*/
                        {
                            g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_VIDEO_BUFFER_AVAIL);
                        }
                        g_video_enc_info_ptr->is_task_prepare_video_data = KAL_TRUE;
                    }

                    //Restart this transation by assigning another buffer
                    length = video_enc_buffer_get_roomleft(g_video_enc_info_ptr);
                    g_video_enc_info_ptr->current_bitstream_addr = video_enc_buffer_get_memaddr(g_video_enc_info_ptr);

#ifdef DRV_MP4_V1
                    //VIDEO_ENC_WRITE_VLCLIMIT_REG(length/4);

                    DRV_WriteReg32(MP4_VLC_LIMIT, (length / 4));

                    video_enc_trigger_limit = ((length / 4) * 4);

                    DRV_WriteReg32(MP4_VLC_ADDR, g_video_enc_info_ptr->current_bitstream_addr);
                    DRV_WriteReg32(MP4_VLC_COMD, MP4_VLC_COMD_RELOAD);
#else /*!DRV_MP4_V1*/
                    DRV_WriteReg32(MP4_CORE_VLC_LIMIT, (length / 4));
                    video_enc_trigger_limit = ((length / 4) * 4);
                    DRV_WriteReg32(MP4_CORE_VLC_ADDR, g_video_enc_info_ptr->current_bitstream_addr);
                    DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);
#endif /*DRV_MP4_V1*/
                }
                else
                {
                    g_video_enc_info_ptr->is_need_to_check_buffer = KAL_TRUE;
                    g_video_enc_info_ptr->switch_buffer_callback = video_enc_switch_buffer_dma_callback;
                }
            }
            else /*if (g_video_enc_info_ptr->im.predition_type == I_VOP)*/
            {
                g_video_enc_info_ptr->force_I_frame = KAL_TRUE;

                g_video_enc_info_ptr->drop_bitstream = KAL_TRUE;

#ifdef DRV_MP4_V1
                DRV_WriteReg32(MP4_VLC_LIMIT, (512 / 4));
                DRV_WriteReg32(MP4_VLC_ADDR, (kal_uint32)resume_buffer_temp);
                DRV_WriteReg32(MP4_VLC_COMD, MP4_VLC_COMD_RELOAD);
#else /*!DRV_MP4_V1*/
                DRV_WriteReg32(MP4_CORE_VLC_LIMIT, (512 / 4));
                DRV_WriteReg32(MP4_CORE_VLC_ADDR, (kal_uint32)resume_buffer_temp);
                DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);
#endif /*DRV_MP4_V1*/
            }
    }

    if (isr_error)
    {
        VIDEO_ASSERT(0);

        g_video_enc_info_ptr->encode_stop = KAL_TRUE;
        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_NOT_SUPPORT;
#ifdef DRV_MP4_V1
        IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
        IRQMask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/
        VISUAL_Register_HISR(VISUAL_MPEG4_ENC_HISR_ID, MPEG4_ENC_ERROR_REPORT_HISR);
        visual_active_hisr(VISUAL_MPEG4_ENC_HISR_ID);
        return;
    }

#if defined(DRV_MP4_ENC_MODIFY_SPECIAL_Q_FOR_IFRAME)
    {
        video_modify_q_for_IFrame(&(g_video_enc_info_ptr->im.quantizer), g_video_enc_info_ptr->total_frames, g_video_enc_info_ptr->force_I_frame);
    }
#endif

    video_dbg_trace(MP4_ENC_HISR_END, video_get_current_time());
#ifdef DRV_MP4_V1
   IRQUnmask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
   IRQUnmask(IRQ_MPEG4_ENC_CODE);
#endif /*DRV_MP4_V1*/
#endif /*__VIDEO_GET_YUV_DATA__*/
}
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
