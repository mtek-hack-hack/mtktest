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
 * vcall_msg_hdlr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains message handlers for vcall
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef WIN32
#include <stdio.h>
#endif 

/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

/* Task Management */
#include "syscomp_config.h"
#include "task_config.h"

/* Timer Management  */
#include "stacklib.h"
#include "event_shed.h" /* event schedulet */
#include "stack_timer.h"

#include "app_buff_alloc.h"     /* buffer management API */
#include "lcd_cqueue.h" /* circular queue */
#include "app2soc_struct.h"     /* interface with Applications */

#include <setjmp.h>

#include "soc_api.h"
#include "fat_fs.h"
#include "rtc_sw.h"

#include "stack_utils.h"

#include <time.h>
#include "l1audio.h"
#include "med_struct.h"
#include "med_utility.h"
#include "med_global.h"
#include "med_main.h"
#include "med_api.h"
#include "kal_trace.h"

#ifdef __MED_VCALL_MOD__
#include "img_comm.h"

#include "vcall.h"
#include "med_vt_struct.h"
#include "vcall_api.h"

#include "vt_common_enum.h"
#include "vt_med_downlink_video_Q.h"

#ifdef __VCALL_TRACE_ON__
#include "med_trc.h"
#endif 

/*----------------------------------------------------------------*/
/* External functions                                             */
/*----------------------------------------------------------------*/
extern kal_bool idp_fullvideo_yuv_move_done(void);
extern vt_downlink_video_Q_state_enum vcall_get_in_video_data_state(void);

/*----------------------------------------------------------------*/
/* Callback functions                                             */
/*----------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  vcall_video_decoder_event_callback
 * DESCRIPTION
 *  vcall video decoder callback function
 * PARAMETERS
 *  event     [IN]        video decoder event
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_decoder_event_callback(VIDEO_CALL_EVENT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcall_send_video_decode_data_ready_ind(vcall_ctx.video_decoder.event_seq_no);
}

/*****************************************************************************
 * FUNCTION
 *  vcall_video_encoder_event_callback
 * DESCRIPTION
 *  vcall video encoder callback functions
 * PARAMETERS
 *  event     [IN]        video encoder event
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_encoder_event_callback(VIDEO_CALL_EVENT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //if (vcall_ctx.video_encoder.notify_count < 2)
	if (vcall_ctx.video_encoder.notify_count == 0)    
    {
        vcall_send_video_encode_data_ready_ind(vcall_ctx.video_encoder.event_seq_no);
        vcall_ctx.video_encoder.notify_count++;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vcall_video_codec_open_req_hdlr
 * DESCRIPTION
 *  vcall video codec open req message handler
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_codec_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_codec_open_req_struct *msg_p = 
        (media_vcall_video_codec_open_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 width;
    kal_int32 height;
    kal_uint32 buf_size;
    RGB2YUV420_struct rgb2yuv;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_VIDEO_CODEC_OPEN_REQ_HDLR);       
    vcall_debug_print_codec_state(__LINE__);    
    vcall_debug_print_channel_state(__LINE__);    

    /* allocate video decode buffer */
    vcall_alloc_video_codec_buffer();
    
    vcall_ctx.seq_num = msg_p->player.seq_num;
    
    vcall_ctx.local_view.type = msg_p->recorder_view_type;
    vcall_ctx.local_view.contrast = (kal_uint8) msg_p->recorder.contrast;
    vcall_ctx.local_view.brightness = (kal_uint8) msg_p->recorder.brightness;
    vcall_ctx.local_view.image_data_format = msg_p->recorder.image_data_format;
    vcall_ctx.local_view.width = msg_p->recorder.preview_width;
    vcall_ctx.local_view.height = msg_p->recorder.preview_height;
    vcall_ctx.local_view.frame_buffer_address = (kal_uint32) msg_p->recorder.preview_buffer_p;
    vcall_ctx.local_view.frame_buffer_size = msg_p->recorder.preview_buffer_size;
    vcall_ctx.local_view.layer = msg_p->recorder.hw_update_layer;
    
    vcall_ctx.peer_view.type = msg_p->player_view_type;
    vcall_ctx.peer_view.contrast = (kal_uint8) msg_p->player.contrast;
    vcall_ctx.peer_view.brightness = (kal_uint8) msg_p->player.brightness;
    vcall_ctx.peer_view.image_data_format = msg_p->player.image_data_format;
    vcall_ctx.peer_view.width = msg_p->player.display_width;
    vcall_ctx.peer_view.height = msg_p->player.display_height;
    vcall_ctx.peer_view.frame_buffer_address = (kal_uint32) msg_p->player.display_buffer_p;
    vcall_ctx.peer_view.frame_buffer_size = msg_p->player.display_buffer_size;
    vcall_ctx.peer_view.layer = msg_p->player.hw_update_layer;

    /* prepare decoder yuv buffer */
    vcall_ctx.video_decoder.next_output_yuv_buf_index = 0;
    vcall_ctx.video_decoder.output_yuv_buf_index = 0;
    vcall_ctx.video_decoder.decode_yuv_buf_index = 0;
    vcall_init_video_yuv_buffer(&vcall_ctx.video_decoder.yuv_buf[0], VCALL_VIDEO_YUV_BUFFER_SIZE);
    vcall_init_video_yuv_buffer(&vcall_ctx.video_decoder.yuv_buf[1], VCALL_VIDEO_YUV_BUFFER_SIZE);

    /* real is original size */
    vcall_ctx.video_decoder.frame_real_width = msg_p->player.display_width;
    vcall_ctx.video_decoder.frame_real_height = msg_p->player.display_height;        

    vcall_ctx.video_decoder.frame_width = vcall_ctx.video_decoder.frame_real_width;
    vcall_ctx.video_decoder.frame_height = vcall_ctx.video_decoder.frame_real_height;

    vcall_ctx.video_decoder.yuv_buf[0].data_size 
        = vcall_ctx.video_decoder.frame_real_width * vcall_ctx.video_decoder.frame_real_height * 3 / 2;

    /* convert peer image from RGB565 to YUV420 */
    rgb2yuv.src_address = vcall_ctx.peer_view.frame_buffer_address;
    rgb2yuv.src_width = (kal_uint32) vcall_ctx.peer_view.width;
    rgb2yuv.src_height = (kal_uint32) vcall_ctx.peer_view.height;
    rgb2yuv.type = IBR1_TYPE_RGB565;
    rgb2yuv.order = IBR1_ORDER_RGB888; 
    rgb2yuv.tar_address = (kal_uint32)vcall_ctx.video_decoder.yuv_buf[0].data;

    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_CONFIG_RGB2YUV420_DATA_PATH, __LINE__);   
    open_image_data_path(SCENARIO_RGB2YUV420_ID);
    config_RGB2YUV420_data_path(SCENARIO_RGB2YUV420_ID, &rgb2yuv);
    close_image_data_path(SCENARIO_RGB2YUV420_ID);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, 0, __LINE__);     

    /* prepare encoder yuv buffer */
    if(vcall_ctx.local_view.type == VCALL_VIEW_SHOW_IMAGE ||
       vcall_ctx.local_view.type == VCALL_VIEW_HIDE)
    {
        vcall_ctx.video_encoder.cfg.width = vcall_ctx.local_view.width;
        vcall_ctx.video_encoder.cfg.height = vcall_ctx.local_view.height;
        vcall_ctx.video_encoder.cfg.yuv_addr 
            = (kal_uint32)med_alloc_ext_mem(vcall_ctx.local_view.width*vcall_ctx.local_view.height*3/2);

        /* convert image from RGB565 to YUV420 */
        rgb2yuv.src_address = vcall_ctx.local_view.frame_buffer_address;
        rgb2yuv.src_width = (kal_uint32) vcall_ctx.local_view.width;
        rgb2yuv.src_height = (kal_uint32) vcall_ctx.local_view.height;
        rgb2yuv.type = IBR1_TYPE_RGB565;
        rgb2yuv.order = IBR1_ORDER_RGB888; 
        rgb2yuv.tar_address = vcall_ctx.video_encoder.cfg.yuv_addr;

        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_CONFIG_RGB2YUV420_DATA_PATH, __LINE__);   
        open_image_data_path(SCENARIO_RGB2YUV420_ID);
        config_RGB2YUV420_data_path(SCENARIO_RGB2YUV420_ID, &rgb2yuv);
        close_image_data_path(SCENARIO_RGB2YUV420_ID);
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, 0, __LINE__);  

        vcall_ctx.video_encoder.cfg.b_yuv_source = KAL_TRUE;
        
        /* driver will encode image every 500 ms */
        vcall_ctx.video_encoder.cfg.yuv_duration = 500; /* ms */

    }
    else if (vcall_ctx.local_view.type == VCALL_VIEW_SHOW_VIDEO)
    {
        /* enocode 176x144 to peer */
        vcall_ctx.video_encoder.cfg.width = msg_p->recorder.encode_width;
        vcall_ctx.video_encoder.cfg.height = msg_p->recorder.encode_height;
        vcall_ctx.video_encoder.cfg.yuv_addr = NULL;
        vcall_ctx.video_encoder.cfg.b_yuv_source = KAL_FALSE;
        vcall_ctx.video_encoder.cfg.yuv_skip_count = 0;         
    }
    else
    {
        ASSERT(0);
    }

    /* encode frame rate and bit rate */
    switch (msg_p->recorder.encode_quality)
    {
        case VCALL_ENC_QTY_LOW:
            vcall_ctx.video_encoder.cfg.bitrate = 50 * 1024;    /* bit rate */            
            vcall_ctx.video_encoder.cfg.quality_mode = VIDEO_CALL_QUALITY_LOW;
            break;

        case VCALL_ENC_QTY_NORMAL:
            vcall_ctx.video_encoder.cfg.bitrate = 50 * 1024;    /* bit rate */                  
            vcall_ctx.video_encoder.cfg.quality_mode = VIDEO_CALL_QUALITY_NORMAL;            
            break;

        case VCALL_ENC_QTY_FINE:
            vcall_ctx.video_encoder.cfg.bitrate = 50 * 1024;    /* bit rate */                  
            vcall_ctx.video_encoder.cfg.quality_mode = VIDEO_CALL_QUALITY_FINE;                        
            break;

        default:
            /* shall not enter here */
            ASSERT(0);
            break;
    }
    
    /* config image data path */
    vcall_config_image_data_path(&msg_p->recorder, &msg_p->player);

    vcall_open_video_decoder();

    /* check if it's not pending */
    if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_OPEN)
    {
        /* check if first data come and process it */
        if (vcall_get_in_video_data_state() == VCALL_DATA_REPLENISH)
        {
            /* decode next frame */
            vcall_decode_next_video_frame();
        }
    }
 
    /* open video encoder */
    vcall_open_video_encoder();

    if (vcall_ctx.local_view.type == VCALL_VIEW_SHOW_IMAGE &&
        vcall_ctx.peer_view.type == VCALL_VIEW_SHOW_VIDEO)
    {
        /* 
         *  in this case, we need start a freq timer to call idp to update , 
         *  otherwise if peer video has ultra long duration, MMI will be blocked 
         *  by LCD event
         */

        kal_get_time(&vcall_ctx.video_decoder.frame_display_tick);        
            
        med_start_timer(
            VCALL_IMAGE_UPDATE_TIMER, 
            VCALL_IMAGE_UPDATE_DURATION, 
            vcall_local_image_update_timeout_callback, 
            NULL);
    }
    
	/* notify MMI */
	media_vcall_set_result(MED_RES_OK, __LINE__);
	VCALL_SET_EVENT(VCALL_EVT_WAIT);
}

/*****************************************************************************
 * FUNCTION
 *  vcall_video_codec_close_req_hdlr
 * DESCRIPTION
 *  vcall video codec close req message handler
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_codec_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/*
    media_vcall_video_codec_close_req_struct *msg_p = 
        (media_vcall_video_codec_close_req_struct*) ilm_ptr->local_para_ptr;
*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_VIDEO_CODEC_CLOSE_REQ_HDLR);       
    vcall_debug_print_codec_state(__LINE__);    
    vcall_debug_print_channel_state(__LINE__);    
    
	/* close video encoder */
	vcall_close_video_encoder();
	
	/* stop video decoder */
    vcall_stop_video_decoder();
    
    /* close video decoder */
	vcall_close_video_decoder();

	/* close image data path */
	vcall_close_image_data_path();

    /* free video codec buffer */
    vcall_free_video_codec_buffer();

    /* release yuv buffer */
    vcall_deinit_video_yuv_buffer(&vcall_ctx.video_decoder.yuv_buf[0]);
    vcall_deinit_video_yuv_buffer(&vcall_ctx.video_decoder.yuv_buf[1]);
    med_free_ext_mem((void**)&vcall_ctx.video_encoder.cfg.yuv_addr);
    
    med_stop_timer(VCALL_IMAGE_UPDATE_TIMER);
    med_stop_timer(VCALL_PEER_VIDEO_TIMER);
	
    /* notify MMI */
    media_vcall_set_result(MED_RES_OK, __LINE__);
    VCALL_SET_EVENT(VCALL_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_channel_status_ind_hdlr
 * DESCRIPTION
 *  vcall channel status ind message handler
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_channel_status_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_channel_status_ind_struct *msg_p =
        (media_vcall_channel_status_ind_struct*) ilm_ptr->local_para_ptr;
    VIDEO_CALL_CODEC_TYPE video_decoder_type;
    vcall_channel_state_enum in_audio_channel_state;
    vcall_channel_state_enum out_audio_channel_state;
    vcall_channel_state_enum in_video_channel_state;
    vcall_channel_state_enum out_video_channel_state;
    vcall_channel_state_enum prev_in_audio_channel_state;
    vcall_channel_state_enum prev_out_audio_channel_state;
    vcall_channel_state_enum prev_in_video_channel_state;
    vcall_channel_state_enum prev_out_video_channel_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CHANNEL_STATUS_IND_HDLR);       
    vcall_debug_print_codec_state(__LINE__);    
    vcall_debug_print_channel_state(__LINE__);    
    
    if (msg_p->input_audio_chl.channel_num == 0)
    {
        in_audio_channel_state = VCALL_CHANNEL_STATE_CLOSED;
    }
    else
    {
        in_audio_channel_state = VCALL_CHANNEL_STATE_OPEN;
    }
    
    if (msg_p->output_audio_chl.channel_num == 0)
    {
        out_audio_channel_state = VCALL_CHANNEL_STATE_CLOSED;
    }
    else
    {
        out_audio_channel_state = VCALL_CHANNEL_STATE_OPEN;
    }
    
    if (msg_p->input_video_chl.channel_num == 0)
    {
        in_video_channel_state = VCALL_CHANNEL_STATE_CLOSED;
    }
    else
    {
        in_video_channel_state = VCALL_CHANNEL_STATE_OPEN;
        
        /* convert decoder type enum */
        switch(msg_p->input_video_chl.video_type)
        {
        case VT_VIDEO_CAP_H263:
            video_decoder_type = VIDEO_CALL_CODEC_H263;
            break;
        case VT_VIDEO_CAP_H264:
            video_decoder_type = VIDEO_CALL_CODEC_H264;
            break;
        case VT_VIDEO_CAP_MPEG4:
            video_decoder_type = VIDEO_CALL_CODEC_MPEG4;
            break;
        default:
            video_decoder_type = VIDEO_CALL_CODEC_NONE;
            break;
        }
        
        vcall_ctx.video_decoder.codec_type = video_decoder_type;
    }
    
    if (msg_p->output_video_chl.channel_num == 0)
    {
        out_video_channel_state = VCALL_CHANNEL_STATE_CLOSED;
    }
    else
    {
        out_video_channel_state = VCALL_CHANNEL_STATE_OPEN;
        vcall_ctx.video_encoder.cfg.max_packet_size = msg_p->output_video_chl.max_packet_size;
    }
    
    /* update channel states */
    prev_in_audio_channel_state = vcall_ctx.in_audio_channel.state;
    prev_out_audio_channel_state = vcall_ctx.out_audio_channel.state;
    prev_in_video_channel_state = vcall_ctx.in_video_channel.state;
    prev_out_video_channel_state = vcall_ctx.out_video_channel.state;

    vcall_ctx.in_audio_channel.state = in_audio_channel_state;
    vcall_ctx.out_audio_channel.state = out_audio_channel_state;
    vcall_ctx.in_video_channel.state = in_video_channel_state;
    vcall_ctx.out_video_channel.state = out_video_channel_state;
    
    /* in & out audio channels */
    if (prev_in_audio_channel_state == VCALL_CHANNEL_STATE_CLOSED &&
        in_audio_channel_state == VCALL_CHANNEL_STATE_OPEN) /* closed to open */
    {
        if (vcall_ctx.speech_decoder.state == VCALL_CODEC_STATE_PENDING)
        {
            /* open speech codec */
            vcall_open_speech_codec();
        }
        else        
        {
            /* ingore, since it might not in pending state */    
              
        }
    }
    else if (prev_in_audio_channel_state == VCALL_CHANNEL_STATE_OPEN &&
             in_audio_channel_state == VCALL_CHANNEL_STATE_CLOSED) /* open to closed */
    {
        if (vcall_ctx.speech_decoder.state == VCALL_CODEC_STATE_OPEN)
        {
            /* close speech codec */
            vcall_close_speech_codec();

            /* let it be pending */
            VCALL_SPEECH_DECODER_ENTER_STATE(VCALL_CODEC_STATE_PENDING);
        }
        else
        {
            /* ignore, since it might not open state */
        }
    }
    else
    {
        /* igonre */
        /* close -> close */
    }


    /* in video channel */
    if (prev_in_video_channel_state == VCALL_CHANNEL_STATE_CLOSED &&
        in_video_channel_state == VCALL_CHANNEL_STATE_OPEN) /* closed to open */
    {
        if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_PENDING)
    	{
    	    /* open video decoder */
    	    vcall_open_video_decoder();
     
            if (vcall_get_in_video_data_state() == VCALL_DATA_REPLENISH)
        	{
        	    /* decode next frame */
        	    vcall_decode_next_video_frame();
             }
        }
        else if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_CLOSED)
        {
            /* decoder not opened, we shall paused vt */
            vcall_send_vt_pause_in_video_channel_req();
            vcall_ctx.in_video_channel.state = VCALL_CHANNEL_STATE_PAUSE;
        }
    }
    else if (prev_in_video_channel_state == VCALL_CHANNEL_STATE_OPEN &&
             in_video_channel_state == VCALL_CHANNEL_STATE_CLOSED) /* open to closed */
    {
        /* stop video decoder */
    	vcall_stop_video_decoder();
    	
    	if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_OPEN)
    	{
    	    /* close video decoder */
            vcall_close_video_decoder();

            /* let it be pending */
            VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_PENDING);
    	}
    	
    	med_stop_timer(VCALL_PEER_VIDEO_TIMER);
    }
    else if (prev_in_video_channel_state == VCALL_CHANNEL_STATE_PAUSE &&
             in_video_channel_state == VCALL_CHANNEL_STATE_CLOSED) /* pause to closed */
    {
        /* stop video decoder */
    	vcall_stop_video_decoder();
    	
    	if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_OPEN)
    	{
    	    /* close video decoder */
            vcall_close_video_decoder();

            /* let it be pending */
            VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_PENDING);
    	}
    	
    	med_stop_timer(VCALL_PEER_VIDEO_TIMER);
    }
    
    else
    {
        /* igonre */
        /* close -> close */
    }

    
    /* out video channel */
    if (prev_out_video_channel_state == VCALL_CHANNEL_STATE_CLOSED &&
        out_video_channel_state == VCALL_CHANNEL_STATE_OPEN) /* closed to open */
    {
        if (vcall_ctx.video_encoder.state == VCALL_CODEC_STATE_PENDING)
    	{
            kal_bool need_restart = KAL_FALSE;
            media_vcall_video_size_enum video_size;
            
            if(msg_p->output_video_chl.video_type == VT_VIDEO_CAP_H263)
            {
                if (msg_p->output_video_chl.h263_cap.vt_video_size == VT_VIDEO_SIZE_QCIF)
                {
                    if (vcall_ctx.video_encoder.cfg.width != 176 ||
                        vcall_ctx.video_encoder.cfg.height != 144)
                    {
                        need_restart = KAL_TRUE;
                        video_size = VCALL_VIDEO_SIZE_QCIF;
                    }
                }
                else if (msg_p->output_video_chl.h263_cap.vt_video_size == VT_VIDEO_SIZE_SQCIF)
                {
                    if (vcall_ctx.video_encoder.cfg.width != 128 ||
                        vcall_ctx.video_encoder.cfg.height != 96)
                    {
                        need_restart = KAL_TRUE;
                        video_size = VCALL_VIDEO_SIZE_SQCIF;                        
                    }
                }
            }

            if (need_restart)
            {
                vcall_send_video_codec_report_ind(VCALL_EVENT_CHANGE_ENCODE_SIZE, video_size);
            }
            else
            {
        	    /* open video encoder */
        	    vcall_open_video_encoder();
            }
    	}
    }
    else if (prev_out_video_channel_state == VCALL_CHANNEL_STATE_OPEN &&
             out_video_channel_state == VCALL_CHANNEL_STATE_CLOSED) /* open to closed */
    {
        if (vcall_ctx.video_encoder.state == VCALL_CODEC_STATE_OPEN)
    	{
    	    /* close video encoder */
    		vcall_close_video_encoder();
            
            /* let it be pending */
            VCALL_VIDEO_ENCODER_ENTER_STATE(VCALL_CODEC_STATE_PENDING);
    	}
    }
    else
    {
        /* igonre */
        /* close -> close */
    }    
}


/*****************************************************************************
 * FUNCTION
 *  vcall_adjust_quality_ind_hdlr
 * DESCRIPTION
 *  vcall adjust quality indication handler
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_adjust_quality_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vt_adjust_video_quality_ind_struct *msg_p =
        (media_vt_adjust_video_quality_ind_struct*) ilm_ptr->local_para_ptr;

    kal_int32 qty;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->vt_video_quality)
    {
        case VT_VIDEO_QUALITY_FINE:
            qty = VCALL_ENC_QTY_FINE;
            break;

        case VT_VIDEO_QUALITY_NORMAL:
            qty = VCALL_ENC_QTY_NORMAL;
            break;

        case VT_VIDEO_QUALITY_LOW:
            qty = VCALL_ENC_QTY_LOW;
            break;            

        default:
            ASSERT(0);
            break;
    }
    
    vcall_send_video_codec_report_ind(VCALL_EVENT_CHANGE_ENCODE_QUALITY, qty);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_adjust_size_ind_hdlr
 * DESCRIPTION
 *  vcall adjust size indication handler
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_adjust_size_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vt_switch_video_size_ind_struct *msg_p =
        (media_vt_switch_video_size_ind_struct*) ilm_ptr->local_para_ptr;

    kal_int32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->vt_video_size)
    {
        case VT_VIDEO_SIZE_SQCIF:
            size = VCALL_VIDEO_SIZE_SQCIF;
            break;

        case VT_VIDEO_SIZE_QCIF:
            size = VCALL_VIDEO_SIZE_QCIF;
            break;
            
        default:
            ASSERT(0);
            break;
    }
    
    vcall_send_video_codec_report_ind(VCALL_EVENT_CHANGE_ENCODE_SIZE, size);
}

/*****************************************************************************
 * FUNCTION
 *  vcall_video_replenish_data_ready_ind_hdlr
 * DESCRIPTION
 *  vcall video replenish data ind message handler
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_replenish_data_ready_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/*
    media_vcall_video_replenish_data_ready_ind_struct *msg_p = 
        (media_vcall_video_replenish_data_ready_ind_struct*) ilm_ptr->local_para_ptr;
*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_VIDEO_REPLENISH_DATA_READY_IND_HDLR);  
    vcall_debug_print_codec_state(__LINE__);    
    vcall_debug_print_channel_state(__LINE__);
    
    if (vcall_ctx.in_video_channel.state == VCALL_CHANNEL_STATE_OPEN &&
        vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_OPEN)
    {
        /* decode next frame */
        vcall_decode_next_video_frame();
    }
    else
    {
        /* TODO: do nothing ? */
    }
}


/*****************************************************************************
 * FUNCTION
 *  vcall_video_decode_data_ready_ind_hdlr
 * DESCRIPTION
 *  vcall video decode data ready ind message handler
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_decode_data_ready_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_decode_data_ready_ind_struct *msg_p = 
        (media_vcall_video_decode_data_ready_ind_struct*) ilm_ptr->local_para_ptr;
    kal_uint32 decode_yuv_buf_index = vcall_ctx.video_decoder.decode_yuv_buf_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_VIDEO_DECODE_DATA_READY_IND_HDLR);  
    vcall_debug_print_codec_state(__LINE__);    
    vcall_debug_print_channel_state(__LINE__);    

    if (vcall_ctx.video_decoder.event_seq_no != msg_p->event_seq_no)
    {
        return;
    }

    ASSERT(vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_DECODING);

    VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_OPEN);

    /* update next output yuv buf index to decode buf result */
    vcall_ctx.video_decoder.next_output_yuv_buf_index = decode_yuv_buf_index;

    /* set yuv data size to indicate its validity */
    vcall_ctx.video_decoder.yuv_buf[decode_yuv_buf_index].data_size = 
        vcall_ctx.video_decoder.frame_width * vcall_ctx.video_decoder.frame_height * 3 / 2;

    if (vcall_ctx.video_decoder.frame_expired)
    {
        vcall_ctx.video_decoder.frame_expired = KAL_FALSE;

        /* update decode video frame image */
        vcall_update_peer_view();
        
        /* decode next frame */
        vcall_decode_next_video_frame();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vcall_video_encode_data_ready_ind_hdlr
 * DESCRIPTION
 *  vcall video encode data ready ind message handler
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_encode_data_ready_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_encode_data_ready_ind_struct *msg_p = 
        (media_vcall_video_encode_data_ready_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_VIDEO_ENCODE_DATA_READY_IND_HDLR);  
    vcall_debug_print_codec_state(__LINE__);    
    vcall_debug_print_channel_state(__LINE__);        

    if (vcall_ctx.video_encoder.event_seq_no != msg_p->event_seq_no)
    {
        return;
    }

    vcall_consume_video_encoder();
}

#endif /* __MED_VCALL_MOD__ */

