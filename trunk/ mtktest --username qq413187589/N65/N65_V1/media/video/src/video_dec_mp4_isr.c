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
 *   video_dec_mp4_isr.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   This file defines the isr handler when mpeg4 decode.
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

#include "video_hw.h"
#include "intrCtrl.h"
#include "visualhisr.h"
#include "gpt_sw.h"

static void mpeg4_av_error_hdlr(void);
static void mpeg4_dec_isr_error_report_hdlr(void);
static void mpeg4_exception_handler(void * parameter);
//static void mpeg4_dec_set_error_recover_process(void);
static void mpeg4_dec_lisr_process(void);
#ifdef MP4_MOVE_LISR_TO_HISR 
static void mpeg4_dec_recover_first_HISR(void);
#endif
static void mpeg4_dec_recover_LISR(void);
static void mpeg4_dec_recover_LISR_Func(void);
static void mpeg4_dec_LISR_Func(void);
static void mpeg4_dec_seek_done_process(void);
static void mpeg4_dec_seek_LISR_Func(void);


MPEG4_DEC_ISR_PARAM  g_mpeg4_dec_isr_param;

///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Parameter setting functions                                 //
//////////////////////////////////////////////////////////////////

/* Init ISR self parameter
 * @param None
 * @return None                                                        
 */
void mpeg4_dec_init_isr_param(void)
{
    if (g_mpeg4_dec_isr_param.gpt_exception_protect_handle == 0)
        GPTI_GetHandle(&g_mpeg4_dec_isr_param.gpt_exception_protect_handle);
    g_mpeg4_dec_isr_param.b_gpt_active = KAL_FALSE;
    g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
    g_mpeg4_dec_isr_param.b_check_exception = KAL_FALSE;
    g_mpeg4_dec_isr_param.b_check_av_error = KAL_FALSE;
    g_mpeg4_dec_isr_param.check_vlc_addr = KAL_FALSE;
    g_mpeg4_dec_isr_param.speed_recover_count = 0;
    g_mpeg4_dec_isr_param.vlc_addr = 0;    
}


/* Set VLC check parameters. 
 *  Set this before decode, and ISR check this parameter to see whether the VLC interrupt is legal or not.
 * @param b_check. Check VLC or not.   
 * @param addr. Decode atsrt addr. 
 * @return None                                                        
 */
void mpeg4_dec_set_isr_vlc_param(kal_bool b_check, kal_uint32 addr)
{
	g_mpeg4_dec_isr_param.check_vlc_addr = b_check;
	g_mpeg4_dec_isr_param.vlc_addr = addr;
}


///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Error handler functions                                        //
//////////////////////////////////////////////////////////////////


/* AV error hander function. Used when miss AV sync. 
 * @param None   
 * @return None                                                        
 */
static void mpeg4_av_error_hdlr(void)
{
    g_mpeg4_dec_isr_param.b_check_av_error = KAL_TRUE;

    VIDEO_ASSERT(0);
}


/* Report the error status from ISR to MED task
 * @param None   
 * @return None                                                        
 */
static void mpeg4_dec_isr_error_report_hdlr(void)
{
    if(g_mpeg4_dec_info_ptr->b_h263==KAL_FALSE)
        video_dec_disable_irq(DECODE_TYPE_MPEG4);
    else
        video_dec_disable_irq(DECODE_TYPE_H263);		
    
    ASSERT(g_mpeg4_dec_info_ptr->dec_callback != NULL);
#if defined(__VIDEO_EDITOR__)
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        g_mpeg4_dec_info_ptr->dec_callback(VIDEO_EDITOR_EVENT_FAIL);
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
        g_mpeg4_dec_info_ptr->dec_callback(VIDEO_DEC_EVENT_FAIL);
    }

    if (g_mpeg4_dec_info_ptr->dec_state == MPEG4_DEC_STATE_NORMAL)
    {
        video_dec_start_refresh();
    }
}


/* Decode can not longer than N ms, thif function is the handler when it exceeds the time limit
 * @param None   
 * @return None                                                        
 */
static void mpeg4_exception_handler(void * parameter)
{
    kal_uint32 savedMask;
    /* race condition protect*/
    savedMask = SaveAndSetIRQMask();
    if ((g_mpeg4_dec_isr_param.b_check_exception == KAL_FALSE) ||
        (g_mpeg4_dec_isr_param.b_gpt_active == KAL_FALSE))
    {
        /* mp4 or AV intr has process done before this exception handler*/
        RestoreIRQMask(savedMask);
        return;
    }

    /* mp4 or AV intr not done before this exception handler*/
#if 0    
/* under construction !*/
/* under construction !*/
#else
    /*Disable GPT ISR*/
    GPTI_StopItem(g_mpeg4_dec_isr_param.gpt_exception_protect_handle);
    g_mpeg4_dec_isr_param.b_gpt_active = KAL_FALSE;

    /*Redirect DSP ISR*/
    //video_dec_set_av_callback(mpeg4_av_error_hdlr); 	 
			 
    /*Disable Mpeg4 ISR*/
#ifdef DRV_MP4_V1
    IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
    IRQMask(IRQ_MPEG4_DEC_CODE);
#endif /*DRV_MP4_V1*/         
#endif
    
    //video_dec_stop_av();
    video_dec_set_av_callback(NULL);
    RestoreIRQMask(savedMask);

    VIDEO_ASSERT(0);

    /*Auto pause/resume, Jensen*/
    g_mpeg4_dec_info_ptr->recover_start = KAL_TRUE;
    g_mpeg4_dec_info_ptr->recover_start_frame = g_mpeg4_dec_info_ptr->dec_frames_no;

#if defined(__VIDEO_EDITOR__)
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        ASSERT(0);
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
        video_dec_cancel_put_buffer(); 
        g_mpeg4_dec_info_ptr->dec_callback(VIDEO_DEC_RECOVER);
    }

    g_mpeg4_dec_isr_param.b_check_exception = KAL_FALSE;

    video_dec_start_refresh();
}


///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Decode ISR  functions                                        //
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
/* under construction !*/
#ifdef DRV_MP4_V1
/* under construction !*/
#else  /*!DRV_MP4_V1*/
/* under construction !*/
#endif /*DRV_MP4_V1*/ 
/* under construction !*/
#endif


/* Decode HISR function. Parse the next frame.
 * @param None   
 * @return None                                                        
 */
void mpeg4_dec_HISR(void)
{
    kal_uint32 frame_length;

    kal_uint32 prev_frame_duration;
    kal_uint8 *frame_addr;
    MEDIA_STATUS_CODE result;

#if defined(STREAM_SUPPORT)
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_STREAM) {
        if (g_video_dec_info_ptr->is_stream_overflow == KAL_TRUE) {
            g_video_dec_info_ptr->is_stream_overflow = KAL_FALSE;
            g_mpeg4_dec_info_ptr->dec_callback(VIDEO_RTP_EVENT_OVERFLOW);	
        }
    }
#endif

#ifdef VIDEO_DEBUG_MODE
    if(g_video_dec_info_ptr->b_check_log == KAL_TRUE)
    {
        g_video_dec_info_ptr->b_check_log = KAL_FALSE;    
        kal_prompt_trace(MOD_MED, "Check err: display loss %d\n", g_video_dec_info_ptr->check_display_loss_count);			
    }

    if(g_mpeg4_dec_info_ptr->b_check_log == KAL_TRUE)
    {
        g_mpeg4_dec_info_ptr->b_check_log = KAL_FALSE;
        kal_prompt_trace(MOD_MED, "Check err: data empty %d\n", g_mpeg4_dec_info_ptr->check_data_empty_count);		
        kal_prompt_trace(MOD_MED, "Check err: av error %d\n", g_mpeg4_dec_info_ptr->check_error_count);		
    }
#endif	

    if (g_mpeg4_dec_info_ptr->isr_error_event_happen == KAL_TRUE)
    {
        /* This error may happens when lisr re-entry happens*/
        VIDEO_ASSERT(0);

        //g_mpeg4_dec_info_ptr->isr_error_event_happen = KAL_FALSE;
        mpeg4_dec_isr_error_report_hdlr();
        return;
    }

    if (g_mpeg4_dec_info_ptr->recover_start == KAL_TRUE)
    {
#if defined(__VIDEO_EDITOR__)
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            ASSERT(0);
        }
        else
#endif /*__VIDEO_EDITOR__*/
        {
#if defined(STREAM_SUPPORT)
	        if (g_video_dec_status.scenario == VIDEO_SCENARIO_STREAM) {
	            g_mpeg4_dec_info_ptr->skip_frames = 0;
	            g_mpeg4_dec_info_ptr->dec_callback(VIDEO_RTP_EVENT_UNDERFLOW);
	        } else 
#endif
	        {
	            /* reset skip frame as 0 */
	            g_mpeg4_dec_info_ptr->skip_frames = 0;
	            video_dec_cancel_put_buffer();  
	            g_mpeg4_dec_info_ptr->dec_callback(VIDEO_DEC_RECOVER);
	        }
        }
        return;
    }

    //if (g_mpeg4_dec_info_ptr->dec_frames_no == g_mpeg4_dec_info_ptr->total_frames_in_file)
    if(g_mpeg4_dec_info_ptr->b_dec_complete == KAL_TRUE) 		
    {
        /* all decode done */
        video_dbg_trace(MP4_DEC_HISR_LAST_ONE, video_get_current_time());

        ASSERT(g_mpeg4_dec_info_ptr->dec_callback != NULL);
#if defined(__VIDEO_EDITOR__)
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            ASSERT(0);
        }
        else
#endif /*__VIDEO_EDITOR__*/
        {
            /* all decode done */
            video_dec_complete();
        }
        return;
    }
    else if (g_mpeg4_dec_info_ptr->hdr_parse_frames_no == g_mpeg4_dec_info_ptr->total_frames_in_file)
    {
        /* all parse done */
        result = video_dec_get_end_frame_time(&prev_frame_duration);

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            prev_frame_duration = mpeg4_dec_get_curr_frame_duration();
        }
        Buffer_WRITE(BUFFER_MP4_FRAME_DURATION, prev_frame_duration);
        return;
    }

    video_dbg_trace(MP4_DEC_HISR_ENTRY, video_get_current_time());
    /* get next frame for parsing */
    result = video_dec_get_next_frame(&frame_addr, &frame_length, &prev_frame_duration);

    if (result != MEDIA_STATUS_OK)
    {
         /* Exception cases: Task can't prepare the enough buffer */
        g_mpeg4_dec_info_ptr->skip_frames++;

        Buffer_WRITE(BUFFER_MP4_FRAME_DURATION, prev_frame_duration);
        g_mpeg4_dec_info_ptr->hdr_parse_frames_no++;
        g_mpeg4_dec_info_ptr->lost_frames++;
        g_mpeg4_dec_info_ptr->check_data_empty_count++;
        g_mpeg4_dec_info_ptr->b_check_log = KAL_TRUE;
        return;
    }
    else
    {
        /* Skip frame only increment in previous HISR, shoule be clear to 0 before next time comes here */
        if (g_mpeg4_dec_info_ptr->skip_frames)
            EXT_ASSERT(0, g_mpeg4_dec_info_ptr->skip_frames, 0, 0);
    }

    if (prev_frame_duration == 0)
    {
        VIDEO_ASSERT(0);

        mpeg4_dec_isr_error_report_hdlr();
        return;
    }

    /* parse next frame */
    result = mpeg4_decode_main((kal_uint8 *)frame_addr, frame_length, prev_frame_duration, KAL_FALSE);

    if (result != MEDIA_STATUS_OK)
    {
        /* This frame is non-coded */
        VIDEO_ASSERT(0);
        g_mpeg4_dec_info_ptr->is_non_coded = KAL_TRUE;
    }

    video_dbg_trace(MP4_DEC_HISR_END, video_get_current_time());
}


/* Decode lisr process function. Check interrupt status and do corresponding handling
 * @param None   
 * @return None                                                        
 */
static void mpeg4_dec_lisr_process(void)
{
    kal_uint32 status;
    kal_uint32 lost_display;
    kal_uint32 prev_frame_duration;	
    
    video_dbg_trace(MP4_DEC_LISR_ENTRY, video_get_current_time());

#ifdef DRV_MP4_V1
    IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
    IRQMask(IRQ_MPEG4_DEC_CODE);
#endif /*DRV_MP4_V1*/

    /* check state */
    if (g_mpeg4_dec_info_ptr->dec_state != MPEG4_DEC_STATE_NORMAL)
    {
        VIDEO_ASSERT(0);

        g_mpeg4_dec_info_ptr->isr_error_event_happen = KAL_TRUE;
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FUNC_STATE_ERROR;
        visual_active_hisr(VISUAL_MPEG4_DEC_HISR_ID);
        return;
    }

    //Jensen's tricky
    if((g_mpeg4_dec_info_ptr->b_dummy_isr == KAL_TRUE) && (g_mpeg4_dec_info_ptr->b_dummy_end == KAL_FALSE))
    {
        // skip check end
    }
    else
    {
        if ((g_mpeg4_dec_info_ptr->dec_frames_no == g_mpeg4_dec_info_ptr->total_frames_in_file)
                || (g_mpeg4_dec_info_ptr->dec_frames_no == g_mpeg4_dec_info_ptr->stop_frame_no))
        {
            
            if((g_mpeg4_dec_info_ptr->b_dec_complete == KAL_FALSE) || (g_mpeg4_dec_info_ptr->b_dummy_end == KAL_TRUE))
            {
                g_mpeg4_dec_info_ptr->b_dummy_end = KAL_FALSE;
                g_mpeg4_dec_info_ptr->b_dec_complete = KAL_TRUE;  
                visual_active_hisr(VISUAL_MPEG4_DEC_HISR_ID);
            }
            g_mpeg4_dec_info_ptr->b_dummy_isr = KAL_FALSE;
            return;
        }
    }

    /* check re-entry */
    if(g_mpeg4_dec_isr_param.b_check_reentry !=  KAL_FALSE)
    {
        VIDEO_ASSERT(0);

        g_mpeg4_dec_info_ptr->isr_error_event_happen = KAL_TRUE;
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
        visual_active_hisr(VISUAL_MPEG4_DEC_HISR_ID);
        g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
        return;
    }

    g_mpeg4_dec_isr_param.b_check_reentry = KAL_TRUE;

    /* skip frame != 0 means task can't prepare enough buffer, should stop decode and activate recover mechanism */
    if ((g_mpeg4_dec_info_ptr->skip_frames == 0) && (g_mpeg4_dec_info_ptr->prepare_recover==KAL_FALSE))
    {
        /* Previous HISR has parsed frame successfully, decode it ! */
#ifdef DRV_MP4_V1
        status = DRV_Reg32(MP4_IRQ_STS);
#else /* !DRV_MP4_V1 */
        status = DRV_Reg32(MP4_DEC_IRQ_STS);
#endif /* DRV_MP4_V1 */

        /* Skip check isr status happens when the previous decoded frame is on-coded. 
             so dose not really write register to decode it */
        if ((g_mpeg4_dec_info_ptr->skip_check_isr_status == KAL_FALSE) &&  (g_mpeg4_dec_info_ptr->b_dummy_isr == KAL_FALSE))
        {
        #ifdef DRV_MP4_V1
            if (status & MP4_IRQ_STS_DEC)
            {
                /* decode done */
                 g_mpeg4_dec_isr_param.speed_recover_count = 0;
                 
                DRV_WriteReg32(MP4_IRQ_ACK, MP4_IRQ_STS_DEC);

                DRV_WriteReg32(MP4_VLC_COMD, MP4_VLC_COMD_STOP);

                if (g_mpeg4_dec_info_ptr->play_speed > 100)
                {
                    g_mpeg4_dec_info_ptr->decode_error_frame_count_in_high_speed = 0;
                }
                mpeg4_dec_set_display_frame_addr(DRV_Reg32(MP4_REC_ADDR));
                video_dec_display();
            }
            else if ((status == 0)
                         && (((g_mpeg4_dec_info_ptr->play_speed % 100) != 0)
                                 || (g_mpeg4_dec_info_ptr->play_speed <= 100)) 
                         && (g_mpeg4_dec_isr_param.speed_recover_count < 3))
            {
                /* Audio support time stretch in this case. error recover for this case */
                VIDEO_ASSERT(0);
                video_dbg_trace(MP4_MAY_ISR_ERROR, video_get_current_time());
                
                g_mpeg4_dec_isr_param.speed_recover_count++;
				
#if defined(STREAM_SUPPORT)
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_STREAM) {
	     	        ASSERT(0);
                } else 
#endif                
                {
                    g_mpeg4_dec_isr_param.b_check_exception = KAL_TRUE;
                    video_dec_set_frametime(mpeg4_dec_get_curr_frame_duration(), KAL_FALSE);
                    g_mpeg4_dec_isr_param.b_gpt_active = KAL_TRUE;
                    GPTI_StartItem(g_mpeg4_dec_isr_param.gpt_exception_protect_handle, 2, /*20ms*/
                                        mpeg4_exception_handler, NULL);
                    g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
#ifdef MP4_MOVE_LISR_TO_HISR
                    VISUAL_Register_HISR(VISUAL_MPEG4_DEC_FIRST_HISR_ID, mpeg4_dec_recover_first_HISR);
#endif
                    IRQ_Register_LISR(IRQ_MPEG4_CODE, mpeg4_dec_recover_LISR, "MPEG4");
                    IRQSensitivity(IRQ_MPEG4_CODE, LEVEL_SENSITIVE);
                    IRQUnmask(IRQ_MPEG4_CODE);
                    return;
                }
            }
            else
            {
                /* not decode done, something error */
                video_dbg_trace(MP4_MAY_ISR_ERROR, video_get_current_time());

                if (g_mpeg4_dec_info_ptr->play_speed > 100)
                {
                    g_mpeg4_dec_info_ptr->decode_error_frame_count_in_high_speed++;
                    if (g_mpeg4_dec_info_ptr->decode_error_frame_count_in_high_speed
                            <= (g_mpeg4_dec_info_ptr->play_speed / 100))
                    {
                        /*Tricky for high speed*/
                        /* In this case, audio mute. No AV sync issue. So just set one more frame time to decode this frame */
                        /* It may decode done in next AV sync interrupt handler */
                        video_dec_set_frametime(mpeg4_dec_get_curr_frame_duration(), KAL_FALSE);
                        g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
                        VIDEO_ASSERT(0);
                        return;
                    }
                    else
                    {
                        /* High speed, but decode too long (more than N frames). So reset it */
                        mpeg4_dec_reset();
                        VIDEO_ASSERT(0);
                    }
                }
                else
                {
                    /* Normal/Slow speed can not decode more than one frame time */
                    mpeg4_dec_reset();
                    g_mpeg4_dec_info_ptr->check_error_count++;
                    g_mpeg4_dec_info_ptr->b_check_log = KAL_TRUE;
                    VIDEO_ASSERT(0);
                }

                DRV_WriteReg32(MP4_IRQ_ACK, status);

#if defined(STREAM_SUPPORT)
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_STREAM) {
		            ASSERT(0);
                }else 
#endif                
                {
                    /* Use the current ref frame as the next ref frame, since the rec frame data is not correct*/
                    Buffer_WRITE(BUFFER_MP4_REC_ADDR, DRV_Reg32(MP4_REC_ADDR));
                    Buffer_WRITE(BUFFER_MP4_REF_ADDR, DRV_Reg32(MP4_REF_ADDR));

                    video_dec_prev_display();
                }
            }
        #else /* !DRV_MP4_V1 */

            if (status & MP4_DEC_IRQ_STS_DEC)
            {
                /* decode done */
                
                g_mpeg4_dec_isr_param.speed_recover_count = 0;

                DRV_WriteReg32(MP4_DEC_IRQ_ACK, MP4_DEC_IRQ_STS_DEC);
                DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_STOP);

                if (g_mpeg4_dec_info_ptr->play_speed > 100)
                {
                    g_mpeg4_dec_info_ptr->decode_error_frame_count_in_high_speed = 0;
                }
                
                video_dec_display();
            }
            else if (status & MP4_DEC_IRQ_STS_DMA)
            {
#if defined(STREAM_SUPPORT)
                    if (g_video_dec_status.scenario == VIDEO_SCENARIO_STREAM) {
                        g_video_dec_info_ptr->skip_err_chk_times++;
                        mpeg4_dec_reset();
                        mpeg4_core_reset();
                        VIDEO_ASSERT(0);
                        DRV_WriteReg32(MP4_DEC_IRQ_ACK, status);
                        if (g_video_dec_info_ptr->display_mode==0) {
                            video_dec_display();	  // Todo: Need to display current or previous frame according to how many MBs are decoded.
                        } else if (g_video_dec_info_ptr->display_mode==1) {
                            /* Use the current ref frame as the next ref frame, since the rec frame data is not correct*/
                            MPEG4_FRAME_BUFFER_ADDR frame_buffer_addr;

                            mpeg4_dec_sort_frame_buffer(DRV_Reg32(MP4_DEC_REC_ADDR), &frame_buffer_addr);
                            Buffer_WRITE(BUFFER_MP4_REC_ADDR, frame_buffer_addr.rec_addr);
                            Buffer_WRITE(BUFFER_MP4_REF_ADDR, frame_buffer_addr.ref_addr);
                            Buffer_WRITE(BUFFER_MP4_DEBLOCK_ADDR, frame_buffer_addr.deblock_addr);
                            video_dec_prev_display();
                        } else {	// original mechanism
                        }
                    } else
#endif                
                {
                    if (g_mpeg4_dec_isr_param.check_vlc_addr == KAL_TRUE)
                    {
                        /* frame length is larger than 0xffff */
                        VIDEO_ASSERT(0);

                        /* Reload VLC DMA */
                        DRV_WriteReg32(MP4_CORE_VLC_LIMIT, 0xffff);
                        DRV_WriteReg32(MP4_CORE_VLC_ADDR, (g_mpeg4_dec_isr_param.vlc_addr + 0xffff));
                        g_mpeg4_dec_isr_param.vlc_addr = (g_mpeg4_dec_isr_param.vlc_addr + 0xffff);
                        DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);

                        /* Start error check mechanism */
                        {					
                            g_mpeg4_dec_isr_param.b_check_exception = KAL_TRUE;
                            video_dec_set_frametime(mpeg4_dec_get_curr_frame_duration(), KAL_FALSE);
                            g_mpeg4_dec_isr_param.b_gpt_active = KAL_TRUE;
                            GPTI_StartItem(g_mpeg4_dec_isr_param.gpt_exception_protect_handle, 3, /*20~30ms*/
                                                mpeg4_exception_handler, NULL);
                            g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
#ifdef MP4_MOVE_LISR_TO_HISR
                            VISUAL_Register_HISR(VISUAL_MPEG4_DEC_FIRST_HISR_ID, mpeg4_dec_recover_first_HISR);
#endif                            
                            IRQ_Register_LISR(IRQ_MPEG4_DEC_CODE, mpeg4_dec_recover_LISR, "MPEG4");
                            IRQSensitivity(IRQ_MPEG4_DEC_CODE, LEVEL_SENSITIVE);
                            IRQUnmask(IRQ_MPEG4_DEC_CODE);
                            return;
                        }
                    }
                    else
                    {
                        // should not assert, if frame data is not correct, DMA limit may be triggered
                        //EXT_ASSERT(0, g_mpeg4_dec_info_ptr->dec_frames_no, g_mpeg4_dec_info_ptr->total_frames_in_file, 
                        //         g_mpeg4_dec_info_ptr->hdr_parse_frames_no);

                        mpeg4_dec_reset();
                        mpeg4_core_reset();
                        VIDEO_ASSERT(0);
                        DRV_WriteReg32(MP4_DEC_IRQ_ACK, status);
						
                        {
                            /* Use the current ref frame as the next ref frame, since the rec frame data is not correct*/
                            MPEG4_FRAME_BUFFER_ADDR frame_buffer_addr;

                            mpeg4_dec_sort_frame_buffer(DRV_Reg32(MP4_DEC_REC_ADDR), &frame_buffer_addr);
                            Buffer_WRITE(BUFFER_MP4_REC_ADDR, frame_buffer_addr.rec_addr);
                            Buffer_WRITE(BUFFER_MP4_REF_ADDR, frame_buffer_addr.ref_addr);
                            Buffer_WRITE(BUFFER_MP4_DEBLOCK_ADDR, frame_buffer_addr.deblock_addr);
                        }  
                        video_dec_prev_display();						
                    }
                }
            }
            else if ((status == 0)
                         && (((g_mpeg4_dec_info_ptr->play_speed % 100) != 0)
                                 || (g_mpeg4_dec_info_ptr->play_speed <= 100)) 
                         && (g_mpeg4_dec_isr_param.speed_recover_count < 3))
            {
                /* Audio support time stretch in this case. error recover for this case */
                VIDEO_ASSERT(0);
                video_dbg_trace(MP4_MAY_ISR_ERROR, video_get_current_time());
                
                g_mpeg4_dec_isr_param.speed_recover_count++;
#if defined(STREAM_SUPPORT)
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_STREAM) {
                    g_video_dec_info_ptr->skip_err_chk_times++;
                    mpeg4_dec_reset();
                    mpeg4_core_reset();
                    VIDEO_ASSERT(0);
                    DRV_WriteReg32(MP4_DEC_IRQ_ACK, status);
                    if (g_video_dec_info_ptr->display_mode==0) {
                        video_dec_display();	  // Todo: Need to display current or previous frame according to how many MBs are decoded.
                    } else if (g_video_dec_info_ptr->display_mode==1) {
                        /* Use the current ref frame as the next ref frame, since the rec frame data is not correct*/
                        MPEG4_FRAME_BUFFER_ADDR frame_buffer_addr;

                        mpeg4_dec_sort_frame_buffer(DRV_Reg32(MP4_DEC_REC_ADDR), &frame_buffer_addr);
                        Buffer_WRITE(BUFFER_MP4_REC_ADDR, frame_buffer_addr.rec_addr);
                        Buffer_WRITE(BUFFER_MP4_REF_ADDR, frame_buffer_addr.ref_addr);
                        Buffer_WRITE(BUFFER_MP4_DEBLOCK_ADDR, frame_buffer_addr.deblock_addr);
                        video_dec_prev_display();
                    } else {	// original mechanism
                        g_mpeg4_dec_isr_param.b_check_exception = KAL_TRUE;
                        video_dec_set_frametime(mpeg4_dec_get_curr_frame_duration(), KAL_FALSE);
                        g_mpeg4_dec_isr_param.b_gpt_active = KAL_TRUE;
                        GPTI_StartItem(g_mpeg4_dec_isr_param.gpt_exception_protect_handle, 2, /*20ms*/
                                                mpeg4_exception_handler, NULL);
                        g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
#ifdef MP4_MOVE_LISR_TO_HISR
                        VISUAL_Register_HISR(VISUAL_MPEG4_DEC_FIRST_HISR_ID, mpeg4_dec_recover_first_HISR);
#endif                        
                        IRQ_Register_LISR(IRQ_MPEG4_DEC_CODE, mpeg4_dec_recover_LISR, "MPEG4");
                        IRQSensitivity(IRQ_MPEG4_DEC_CODE, LEVEL_SENSITIVE);
                        IRQUnmask(IRQ_MPEG4_DEC_CODE);
                        return;
                    }
                } else 
#endif
                {
                    g_mpeg4_dec_isr_param.b_check_exception = KAL_TRUE;
                    video_dec_set_frametime(mpeg4_dec_get_curr_frame_duration(), KAL_FALSE);
                    g_mpeg4_dec_isr_param.b_gpt_active = KAL_TRUE;
                    GPTI_StartItem(g_mpeg4_dec_isr_param.gpt_exception_protect_handle, 2, /*20ms*/
                                        mpeg4_exception_handler, NULL);
                    g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
#ifdef MP4_MOVE_LISR_TO_HISR
                    VISUAL_Register_HISR(VISUAL_MPEG4_DEC_FIRST_HISR_ID, mpeg4_dec_recover_first_HISR);
#endif                    
                    IRQ_Register_LISR(IRQ_MPEG4_DEC_CODE, mpeg4_dec_recover_LISR, "MPEG4");
                    IRQSensitivity(IRQ_MPEG4_DEC_CODE, LEVEL_SENSITIVE);
                    IRQUnmask(IRQ_MPEG4_DEC_CODE);
                    return;					
                }
            }
            else
            {
                video_dbg_trace(MP4_MAY_ISR_ERROR, video_get_current_time());

                if (g_mpeg4_dec_info_ptr->play_speed > 100)
                {
                    /* Audio mute in this case */
                    g_mpeg4_dec_info_ptr->decode_error_frame_count_in_high_speed++;
                    if (g_mpeg4_dec_info_ptr->decode_error_frame_count_in_high_speed
                            <= (g_mpeg4_dec_info_ptr->play_speed / 100))
                    {
                        /* Tricky for high speed */
                        /* In this case, audio mute. No AV sync issue. So just set one more frame time to decode this frame */
                        /* It may decode done in next AV sync interrupt handler */
                        video_dec_set_frametime(mpeg4_dec_get_curr_frame_duration(), KAL_FALSE);
                        g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
                        VIDEO_ASSERT(0);
                        return;
                    }
                    else
                    {
                        /* High speed, but decode too long (more than N frames). So reset it */
                        mpeg4_dec_reset();
                        mpeg4_core_reset();
                        VIDEO_ASSERT(0);
                    }
                }
                else
                {
                    /* Normal/Slow speed can not decode more than one frame time */
                    mpeg4_dec_reset();
                    mpeg4_core_reset();
                    g_mpeg4_dec_info_ptr->check_error_count++;
                    g_mpeg4_dec_info_ptr->b_check_log = KAL_TRUE;				
                    VIDEO_ASSERT(0);
                }

                DRV_WriteReg32(MP4_DEC_IRQ_ACK, status);

#if defined(STREAM_SUPPORT)
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_STREAM) {
                    g_video_dec_info_ptr->skip_err_chk_times++;
                    if (g_video_dec_info_ptr->display_mode==0) {
                        video_dec_display();	  // Todo: Need to display current or previous frame according to how many MBs are decoded.
                    } else if (g_video_dec_info_ptr->display_mode==1) {
                        /* Use the current ref frame as the next ref frame, since the rec frame data is not correct*/
                        MPEG4_FRAME_BUFFER_ADDR frame_buffer_addr;

                        mpeg4_dec_sort_frame_buffer(DRV_Reg32(MP4_DEC_REC_ADDR), &frame_buffer_addr);
                        Buffer_WRITE(BUFFER_MP4_REC_ADDR, frame_buffer_addr.rec_addr);
                        Buffer_WRITE(BUFFER_MP4_REF_ADDR, frame_buffer_addr.ref_addr);
                        Buffer_WRITE(BUFFER_MP4_DEBLOCK_ADDR, frame_buffer_addr.deblock_addr);
                        video_dec_prev_display();
                    } else {                
                        /* Use the current ref frame as the next ref frame, since the rec frame data is not correct*/
                        MPEG4_FRAME_BUFFER_ADDR frame_buffer_addr;

                        mpeg4_dec_sort_frame_buffer(DRV_Reg32(MP4_DEC_REC_ADDR), &frame_buffer_addr);
                        Buffer_WRITE(BUFFER_MP4_REC_ADDR, frame_buffer_addr.rec_addr);
                        Buffer_WRITE(BUFFER_MP4_REF_ADDR, frame_buffer_addr.ref_addr);
                        Buffer_WRITE(BUFFER_MP4_DEBLOCK_ADDR, frame_buffer_addr.deblock_addr);
                        video_dec_prev_display();
                    }
                }else {
#endif
                  {
                    /* Use the current ref frame as the next ref frame, since the rec frame data is not correct*/
                    MPEG4_FRAME_BUFFER_ADDR frame_buffer_addr;

                    mpeg4_dec_sort_frame_buffer(DRV_Reg32(MP4_DEC_REC_ADDR), &frame_buffer_addr);
                    Buffer_WRITE(BUFFER_MP4_REC_ADDR, frame_buffer_addr.rec_addr);
                    Buffer_WRITE(BUFFER_MP4_REF_ADDR, frame_buffer_addr.ref_addr);
                    Buffer_WRITE(BUFFER_MP4_DEBLOCK_ADDR, frame_buffer_addr.deblock_addr);
                  }

                  video_dec_prev_display();
#if defined(STREAM_SUPPORT)				  
                }
#endif
            }
        #endif /* DRV_MP4_V1 */

        }
        else /* !if (g_mpeg4_dec_info_ptr->skip_check_isr_status == KAL_FALSE) */
        {
             /* Skip check isr status happens when the previous decoded frame is on-coded. 
             so dose not really write register to decode it */
        #ifdef DRV_MP4_V1
            DRV_WriteReg32(MP4_IRQ_ACK, status);
        #else  /* !DRV_MP4_V1 */
            DRV_WriteReg32(MP4_DEC_IRQ_ACK, status);
        #endif /* DRV_MP4_V1 */
        
            g_mpeg4_dec_info_ptr->skip_check_isr_status = KAL_FALSE;
            video_dec_display();
        }

        if(g_mpeg4_dec_info_ptr->b_dummy_isr == KAL_FALSE)
        {
            g_mpeg4_dec_info_ptr->dec_frames_no++;
        }

        prev_frame_duration = video_dec_get_prev_frametime();
        if(prev_frame_duration==0)
        	VIDEO_ASSERT(0);

        /* update play time, upper layer may use this as play time */
        g_mpeg4_dec_info_ptr->play_time += prev_frame_duration;
	    g_mpeg4_dec_info_ptr->tmp_play_time = 0;

        /* set next frame time */
        video_dec_set_frametime(mpeg4_dec_get_curr_frame_duration(), KAL_FALSE);
        //g_mpeg4_dec_info_ptr->pre_frame_duration = mpeg4_dec_get_curr_frame_duration();

        /* decode next frame when needed */
        if (g_mpeg4_dec_info_ptr->dec_frames_no < g_mpeg4_dec_info_ptr->total_frames_in_file)
        {
            if ((g_mpeg4_dec_info_ptr->stop_frame_no != g_mpeg4_dec_info_ptr->total_frames_in_file)
                    && (g_mpeg4_dec_info_ptr->dec_frames_no == g_mpeg4_dec_info_ptr->stop_frame_no))
            {
                g_mpeg4_dec_info_ptr->isr_error_event_happen = KAL_TRUE;
                g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
            }
            else
            {
                mpeg4_decode_write_register();
            }
        }
    }
    else /*if (g_mpeg4_dec_info_ptr->skip_frames == 0)*/
    {
        /* Exception cases: Task can't prepare the enough buffer */
        if (g_mpeg4_dec_info_ptr->play_speed >= 200)
        {
            lost_display = g_video_dec_info_ptr->disp_lost_frames;
            video_dec_display();
            if(lost_display!=g_video_dec_info_ptr->disp_lost_frames)  
            {
                // fail display
                g_mpeg4_dec_info_ptr->prepare_recover = KAL_TRUE;
                video_dec_set_frametime(mpeg4_dec_get_curr_frame_duration(), KAL_FALSE);
                g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
                return;
            }
        }

        g_mpeg4_dec_info_ptr->dec_frames_no++;
        g_mpeg4_dec_info_ptr->prepare_recover = KAL_FALSE;
        g_mpeg4_dec_info_ptr->recover_start = KAL_TRUE;
        g_mpeg4_dec_info_ptr->recover_start_frame = g_mpeg4_dec_info_ptr->dec_frames_no;
        if(g_mpeg4_dec_info_ptr->b_h263==KAL_FALSE)
            video_dec_disable_irq(DECODE_TYPE_MPEG4);
        else
            video_dec_disable_irq(DECODE_TYPE_H263);	
        video_dec_start_refresh();
        // Rey's A2V
        //video_dec_stop_av();
    }

    g_mpeg4_dec_info_ptr->b_dummy_isr = KAL_FALSE;
    visual_active_hisr(VISUAL_MPEG4_DEC_HISR_ID);
    g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
    video_dbg_trace(MP4_DEC_LISR_END, video_get_current_time());
}


#ifdef MP4_MOVE_LISR_TO_HISR 

/* Decode error recover LISR  function. Activate HISR
 *  It is used when decode can not be done in normal AV sync LISR 
 * @param None   
 * @return None                                                        
 */
static void mpeg4_dec_recover_LISR(void)
{
#ifdef DRV_MP4_V1
    IRQMask(IRQ_MPEG4_CODE);
#else  /* !DRV_MP4_V1 */
    IRQMask(IRQ_MPEG4_DEC_CODE);
#endif /* DRV_MP4_V1 */

    visual_active_hisr(VISUAL_MPEG4_DEC_FIRST_HISR_ID);
}


/* Decode error recover LISR  function. Act in MPEG4 HISR context
 *  It is used when decode can not be done in normal AV sync LISR 
 * @param None   
 * @return None                                                        
 */
static void mpeg4_dec_recover_first_HISR(void)
{
    mpeg4_dec_recover_LISR_Func();
}

#else

/* Decode error recover LISR  function. Act in MPEG4 LISR context
 *  It is used when decode can not be done in normal AV sync LISR 
 * @param None   
 * @return None                                                        
 */
static void mpeg4_dec_recover_LISR(void)
{
    mpeg4_dec_recover_LISR_Func();
}
#endif


/* Decode error recover LISR/HISR  function. Act in MPEG4 LISR/HISR context
 *  It is used when decode can not be done in normal AV sync LISR 
 * @param None   
 * @return None                                                        
 */
static void mpeg4_dec_recover_LISR_Func(void) /*Mpeg4 ISR*/
{
#ifdef __VIDEO_EDITOR__

    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        ASSERT(0);
    }
    else
#endif /*__VIDEO_EDITOR__*/

    {
        kal_uint32 savedMask;

        GPTI_StopItem(g_mpeg4_dec_isr_param.gpt_exception_protect_handle);
        g_mpeg4_dec_isr_param.b_gpt_active = KAL_FALSE;
        
        /* race condition protect*/
        savedMask = SaveAndSetIRQMask();
        /* set AV callback function to error report function */
#if 0    
/* under construction !*/
/* under construction !*/
#else        
	   /*Redirect DSP ISR*/
	   video_dec_set_av_callback(mpeg4_av_error_hdlr);	  
				  
	   /*Disable Mpeg4 ISR*/
#ifdef DRV_MP4_V1
	   IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
	   IRQMask(IRQ_MPEG4_DEC_CODE);
#endif /*DRV_MP4_V1*/         
#endif
        RestoreIRQMask(savedMask);

        /* AV has process done*/
        if (g_mpeg4_dec_isr_param.b_check_exception == KAL_FALSE)
            return;

        VIDEO_ASSERT(0);
        /* deblock will waste time, disable it */
        g_mpeg4_dec_info_ptr->force_deblock_disable = KAL_TRUE;
        g_mpeg4_dec_isr_param.b_check_exception = KAL_FALSE;
        mpeg4_dec_lisr_process();

        savedMask = SaveAndSetIRQMask();
        if (g_mpeg4_dec_isr_param.b_check_av_error == KAL_TRUE)
        {
            /* av intr comes before the recovery. AV will not sync after it. Start recover mechanism */
            //video_dec_stop_av();
            video_dec_set_av_callback(NULL);

            VIDEO_ASSERT(0);
            RestoreIRQMask(savedMask);

            g_mpeg4_dec_isr_param.b_check_av_error = KAL_FALSE;
            /*Auto Pause/resume*/
            g_mpeg4_dec_info_ptr->recover_start = KAL_TRUE;
            g_mpeg4_dec_info_ptr->recover_start_frame = g_mpeg4_dec_info_ptr->dec_frames_no;
            video_dec_start_refresh();
            visual_active_hisr(VISUAL_MPEG4_DEC_HISR_ID);
        }
        else
        {
            /* check AV intr not come before this error recovery */
#ifdef MP4_MOVE_LISR_TO_HISR
            VISUAL_Register_HISR(VISUAL_MPEG4_DEC_FIRST_HISR_ID, mpeg4_dec_first_HISR);
#endif            
            video_dec_set_av_callback(mpeg4_dec_LISR);  /*Avoid race condition*/
            RestoreIRQMask(savedMask);
        }
    }
}


#ifdef MP4_MOVE_LISR_TO_HISR 
/* Decode LISR  function. Activate HISR function.
 *  It should check whether next AV intr comes before error recover MP4 intr.
 * @param None   
 * @return None                                                        
 */
void mpeg4_dec_LISR(void)
{
#ifdef DRV_MP4_V1
    IRQMask(IRQ_MPEG4_CODE);
#else  /* !DRV_MP4_V1 */
    IRQMask(IRQ_MPEG4_DEC_CODE);
#endif /* DRV_MP4_V1 */

    visual_active_hisr(VISUAL_MPEG4_DEC_FIRST_HISR_ID);
}


/* Decode HISR  function. Act in AV sync HISR context. 
 *  It should check whether next AV intr comes before error recover MP4 intr.
 * @param None   
 * @return None                                                        
 */
void mpeg4_dec_first_HISR(void)
{
    mpeg4_dec_LISR_Func();
}

#else

/* Decode LISR  function. Act in AV sync LISR context. 
 *  It should check whether next AV intr comes before error recover MP4 intr.
 * @param None   
 * @return None                                                        
 */
void mpeg4_dec_LISR(void)
{
    mpeg4_dec_LISR_Func();
}

#endif



/* Decode LISR/HISR  function. Act in AV sync LISR/HISR context. 
 *  It should check whether next AV intr comes before error recover MP4 intr.
 * @param None   
 * @return None                                                        
 */
static void mpeg4_dec_LISR_Func(void) /*AV sync intr.*/
{
    kal_uint32 savedMask;
        
#ifdef __VIDEO_EDITOR__
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }
#endif /*__VIDEO_EDITOR__*/

    if ((g_mpeg4_dec_info_ptr->isr_error_event_happen == KAL_TRUE) || 
    	(g_mpeg4_dec_info_ptr->recover_start == KAL_TRUE))
    {
        return;
    }

    GPTI_StopItem(g_mpeg4_dec_isr_param.gpt_exception_protect_handle);
    g_mpeg4_dec_isr_param.b_gpt_active = KAL_FALSE;
    	
    /* race condition protect*/
    savedMask = SaveAndSetIRQMask();
    if (g_mpeg4_dec_isr_param.b_check_exception == KAL_TRUE)
    {
#if 0    
/* under construction !*/
/* under construction !*/
#else        
        /*Redirect DSP ISR*/
        video_dec_set_av_callback(mpeg4_av_error_hdlr);		
		
        /*Disable Mpeg4 ISR*/
#ifdef DRV_MP4_V1
        IRQMask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/
        IRQMask(IRQ_MPEG4_DEC_CODE);
#endif /*DRV_MP4_V1*/         
#endif
    }
    RestoreIRQMask(savedMask);

    if ((g_mpeg4_dec_isr_param.b_check_exception == KAL_FALSE)
            && (g_mpeg4_dec_info_ptr->hdr_parse_frames_no >= g_mpeg4_dec_info_ptr->dec_frames_no))
    {
        mpeg4_dec_lisr_process();
    }
    else
    {
        /*Auto pause/resume, 
           1. next AV sync comes before previous error handling (g_mpeg4_dec_isr_param.b_check_exception == KAL_TRUE
           2. header parse slower than decode (g_mpeg4_dec_info_ptr->hdr_parse_frames_no <= g_mpeg4_dec_info_ptr->dec_frames_no)*/
        VIDEO_ASSERT(0);

        /* audio interrupt should continue to count (in order to get time information) */
        video_dec_set_av_callback(NULL);
        g_mpeg4_dec_info_ptr->recover_start = KAL_TRUE;
        g_mpeg4_dec_info_ptr->recover_start_frame = g_mpeg4_dec_info_ptr->dec_frames_no;
        visual_active_hisr(VISUAL_MPEG4_DEC_HISR_ID);
        g_mpeg4_dec_isr_param.b_check_exception = KAL_FALSE;
        return;
    }
}


///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Seek ISR  functions                                           //
//////////////////////////////////////////////////////////////////

/* Seek done process function. 
 * @param None   
 * @return None                                                        
 */
static void mpeg4_dec_seek_done_process(void)
{
    ASSERT(g_mpeg4_dec_info_ptr->dec_callback != NULL);

    g_mpeg4_dec_info_ptr->dec_state = MPEG4_DEC_STATE_UNKOWN;
#if defined(__VIDEO_EDITOR__)
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        g_mpeg4_dec_info_ptr->dec_callback(VIDEO_EDITOR_DEC_EVENT_SEEK_DONE);
    }
    else
#endif /*__VIDEO_EDITOR__*/
    {
        g_mpeg4_dec_info_ptr->dec_callback(VIDEO_DEC_EVENT_SEEK_DONE);
    }

    if ((g_mpeg4_dec_info_ptr->seek_frame_no == g_mpeg4_dec_info_ptr->total_frames_in_file) || (g_mpeg4_dec_info_ptr->seek_frame_no == g_mpeg4_dec_info_ptr->stop_frame_no))
    {
#if defined(__VIDEO_EDITOR__)

        if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            VIDEO_ASSERT(0);
        }
        else
#endif /*__VIDEO_EDITOR__*/

        {
            video_dec_complete();
        }
    }
}


/* Seek HISR function. Check whether seek done or not in this function.
 * @param None   
 * @return None                                                        
 */
void mpeg4_dec_seek_HISR(void)
{
    if (g_mpeg4_dec_info_ptr->isr_error_event_happen == KAL_TRUE)
    {
        VIDEO_ASSERT(0);

        //g_mpeg4_dec_info_ptr->isr_error_event_happen = KAL_FALSE;
        mpeg4_dec_isr_error_report_hdlr();
        return;
    }

     if (g_mpeg4_dec_info_ptr->dec_frames_no == g_mpeg4_dec_info_ptr->seek_frame_no)
     {
         /* Seek done */
    #if defined(__VIDEO_EDITOR__)
        if (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_START)
        {
            if (VIDEO_EDITOR_DATA.is_force_end == KAL_TRUE)
            {
                extern void video_enc_done_send_ilm(VIDEO_ENC_STRUCT *enc_struct);
                video_dbg_trace(MP4_EDT_FORCE_END, video_get_current_time());
                VIDEO_EDITOR_DATA.is_force_end = KAL_FALSE;
                video_enc_done_send_ilm(g_video_enc_info_ptr);
            }
            VIDEO_EDITOR_DEC_DONE_HISR();
        }
        else 
    #endif /*__VIDEO_EDITOR__*/
        {
        #if defined(__VIDEO_EDITOR__)	/*Jensen add for video editor, 95/10/11*/
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
            {
                kal_uint32                      prev_frame_duration;
                kal_uint32                      temp_length_data;
                kal_uint8                       *temp_addr_data;
                MEDIA_STATUS_CODE      result;

                result = video_dec_get_next_frame(&temp_addr_data, &temp_length_data, &prev_frame_duration);
                if (result != MEDIA_STATUS_OK)
                {
                    VIDEO_ASSERT(0);
                }
                Buffer_WRITE(BUFFER_MP4_FRAME_DURATION, prev_frame_duration);
            }
        #endif /*__VIDEO_EDITOR__*/
            mpeg4_dec_seek_done_process();
        }         
    }
    else
    {
    #if defined(__VIDEO_EDITOR__)
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            g_mpeg4_dec_info_ptr->dec_callback(VIDEO_EDITOR_DEC_DRV_SEEK_ACTION);
        }
        else
    #endif /*__VIDEO_EDITOR__*/
        {
            g_mpeg4_dec_info_ptr->dec_callback(VIDEO_DEC_DRV_SEEK_ACTION);
        }
    }
}


/* Seek LISR process function. Check exception(ex. re-entry). Check decode status.
 * @param None.   
 * @return None                                                        
 */
void mpeg4_dec_seek_lisr_process(kal_uint32 status)
{
#ifdef DRV_MP4_V1

    IRQMask(IRQ_MPEG4_CODE);
#else  /* !DRV_MP4_V1 */

    IRQMask(IRQ_MPEG4_DEC_CODE);
#endif /* DRV_MP4_V1 */

    if (g_mpeg4_dec_info_ptr->dec_state != MPEG4_DEC_STATE_SEEK)
    {
        return;
    }

    if ( g_mpeg4_dec_isr_param.b_check_reentry != KAL_FALSE)
    {
        VIDEO_ASSERT(0);

        g_mpeg4_dec_info_ptr->isr_error_event_happen = KAL_TRUE;
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
        visual_active_hisr(VISUAL_MP4_SEEK_HISR_ID);
        g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
        return;
    }

    g_mpeg4_dec_isr_param.b_check_reentry = KAL_TRUE;

    video_dbg_trace(MP4_DEC_SEEK_LISR_START, video_get_current_time());
#ifdef DRV_MP4_V1

    if (status & MP4_IRQ_STS_DEC)
    {
        DRV_WriteReg32(MP4_IRQ_ACK, MP4_IRQ_STS_DEC);

        DRV_WriteReg32(MP4_VLC_COMD, MP4_VLC_COMD_STOP);
    #ifdef VIDEO_DEC_YUV_MODE

        if (g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_HW)
            video_dec_display();
    #endif /*VIDEO_DEC_YUV_MODE*/

    }
    else
    {
        mpeg4_dec_reset();

        DRV_WriteReg32(MP4_IRQ_ACK, status);
        
        VIDEO_ASSERT(0);
        video_dbg_trace(MP4_MAY_ISR_ERROR, video_get_current_time());
    }
#else /* !DRV_MP4_V1 */

    if (status & MP4_DEC_IRQ_STS_DEC)
    {
        DRV_WriteReg32(MP4_DEC_IRQ_ACK, MP4_DEC_IRQ_STS_DEC);

        DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_STOP);
    #ifdef VIDEO_DEC_YUV_MODE

        if (g_video_dec_info_ptr->path_type == VIDEO_DEC_IMG_PATH_HW)
            video_dec_display();
    #endif /*VIDEO_DEC_YUV_MODE*/

    }
    else if (status & MP4_DEC_IRQ_STS_DMA)
    {
        if (g_mpeg4_dec_isr_param.check_vlc_addr == KAL_TRUE)
        {
            VIDEO_ASSERT(0);

            DRV_WriteReg32(MP4_CORE_VLC_LIMIT, 0xffff);
            DRV_WriteReg32(MP4_CORE_VLC_ADDR, (g_mpeg4_dec_isr_param.vlc_addr + 0xffff));
            g_mpeg4_dec_isr_param.vlc_addr = (g_mpeg4_dec_isr_param.vlc_addr + 0xffff);
            DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);
            g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
            return;
        }
        else
        {
            VIDEO_ASSERT(0);

            g_mpeg4_dec_info_ptr->isr_error_event_happen = KAL_TRUE;
            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
            visual_active_hisr(VISUAL_MP4_SEEK_HISR_ID);
            g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
            return;
        }
    }
    else
    {
        mpeg4_dec_reset();
        mpeg4_core_reset();
        
        DRV_WriteReg32(MP4_DEC_IRQ_ACK, status);
        VIDEO_ASSERT(0);
        video_dbg_trace(MP4_MAY_ISR_ERROR, video_get_current_time());
    }
#endif /* DRV_MP4_V1 */

    g_mpeg4_dec_info_ptr->dec_frames_no++;

    /* Rita */
    if (g_mpeg4_dec_info_ptr->dec_frames_no == g_mpeg4_dec_info_ptr->seek_frame_no)
    {
        video_dbg_trace(MP4_DEC_SEEK_HISR_DONE, video_get_current_time());
#if defined(__VIDEO_EDITOR__)
        if ( (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR) && (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_START) )
        {
           VIDEO_EDITOR_DEC_DONE_HISR();
           g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;
           return;
        }
#endif /*__VIDEO_EDITOR__*/
    }   
    
    visual_active_hisr(VISUAL_MP4_SEEK_HISR_ID);

    g_mpeg4_dec_isr_param.b_check_reentry = KAL_FALSE;

    video_dbg_trace(MP4_DEC_SEEK_LISR_END, video_get_current_time());
#ifdef DRV_MP4_V1

    IRQUnmask(IRQ_MPEG4_CODE);
#else  /*!DRV_MP4_V1*/

    IRQUnmask(IRQ_MPEG4_DEC_CODE);
#endif /*DRV_MP4_V1*/

}


#ifdef MP4_MOVE_LISR_TO_HISR 
/* Seek LISR function. 
 * @param None.   
 * @return None                                                        
 */
void mpeg4_dec_seek_LISR(void)
{
#ifdef DRV_MP4_V1
    IRQMask(IRQ_MPEG4_CODE);
#else  /* !DRV_MP4_V1 */
    IRQMask(IRQ_MPEG4_DEC_CODE);
#endif /* DRV_MP4_V1 */

    visual_active_hisr(VISUAL_MPEG4_SEEK_FIRST_HISR_ID);
}

/* Seek HISR function. 
 * @param None.   
 * @return None                                                        
 */
void mpeg4_dec_seek_first_HISR(void)
{
    mpeg4_dec_seek_LISR_Func();
}

#else

/* Seek LISR function. 
 * @param None.   
 * @return None                                                        
 */
void mpeg4_dec_seek_LISR(void)
{
    mpeg4_dec_seek_LISR_Func();
}

#endif


/* Seek LISR/HISR function. 
 * @param None.   
 * @return None                                                        
 */
static void mpeg4_dec_seek_LISR_Func(void)
{
    kal_uint32 status;
    
#ifdef __VIDEO_EDITOR__
    if ((g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR) && (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_START))
    {
        //MPEG4_EDITOR_LISR(); //Not here, we should enable image data path, and run it at image data path isr.
        EXT_ASSERT(0, 0, 0, 0);
    }
#endif /*__VIDEO_EDITOR__*/
   
#ifdef DRV_MP4_V1
    status = DRV_Reg32(MP4_IRQ_STS);
#else  /* !DRV_MP4_V1 */
    status = DRV_Reg32(MP4_DEC_IRQ_STS); 
#endif /* DRV_MP4_V1 */
    
    mpeg4_dec_seek_lisr_process(status);

}

#else  /*MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
