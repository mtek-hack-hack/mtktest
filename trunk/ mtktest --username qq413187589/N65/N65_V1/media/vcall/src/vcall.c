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
 *  vcall.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains most logic codes for vcall
 *
 * Author:
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

#include "vcall.h"
#include "med_vt_struct.h"
#include "vcall_api.h"

#include "vt_common_enum.h"
#include "vt_med_downlink_video_Q.h"

#include "cam_main.h"
#include "img_comm.h"
#include "visual_comm.h"
#include "med_trc.h"


/* 
 * External variables and functions
 */
extern vt_downlink_video_Q_struct MED_VT_DL_video_Q;
extern kal_bool vt_video_put_outgoing_data(kal_uint8* data, kal_uint32 size);
extern void config_RGB2YUV420_data_path(MMDI_SCENERIO_ID scenario_id, RGB2YUV420_struct  *rgb2yuv420_struct);


/*****************************************************************************
 * FUNCTION
 *  vcall_debug_print_codec_state
 * DESCRIPTION
 *  Print vcall decoder / encoder state
 * PARAMETERS
 *  line        [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_debug_print_codec_state(kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* vid deccoder state */
    switch(vcall_ctx.video_decoder.state)
    {   
        case VCALL_CODEC_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_CLOSED, line);  
            break;

        case VCALL_CODEC_STATE_PENDING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_PENDING, line);            
            break;

        case VCALL_CODEC_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_OPEN, line);           
            break;

        case VCALL_CODEC_STATE_DECODING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_DECODING, line);          
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_UNKNOWN, vcall_ctx.video_decoder.state, line);           
            break;
     }

    /* vid encoder state */
    switch(vcall_ctx.video_encoder.state)
    {   
        case VCALL_CODEC_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_ENCODER_STATE_CLOSED, line);          
            break;

        case VCALL_CODEC_STATE_PENDING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_ENCODER_STATE_PENDING, line);            
            break;

        case VCALL_CODEC_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_ENCODER_STATE_OPEN, line);           
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_ENCODER_STATE_UNKNOWN, vcall_ctx.video_encoder.state, line);            
            break;
     }


    /* aud deccoder state */
    switch(vcall_ctx.speech_decoder.state)
    {   
        case VCALL_CODEC_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_DECODER_STATE_CLOSED, line);  
            break;

        case VCALL_CODEC_STATE_PENDING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_DECODER_STATE_PENDING, line);            
            break;

        case VCALL_CODEC_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_DECODER_STATE_OPEN, line);           
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_DECODER_STATE_UNKNOWN, vcall_ctx.speech_decoder.state, line);           
            break;
     }

    /* aud encoder state */
    switch(vcall_ctx.speech_encoder.state)
    {   
        case VCALL_CODEC_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_ENCODER_STATE_CLOSED, line);          
            break;

        case VCALL_CODEC_STATE_PENDING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_ENCODER_STATE_PENDING, line);            
            break;

        case VCALL_CODEC_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_ENCODER_STATE_OPEN, line);           
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_ENCODER_STATE_UNKNOWN, vcall_ctx.speech_encoder.state, line);            
            break;
     }
    
}


/*****************************************************************************
 * FUNCTION
 *  vcall_debug_print_channel_state
 * DESCRIPTION
 *  Print vcall incoming / outgoing channel state
 * PARAMETERS
 *  line        [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_debug_print_channel_state(kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* in video channel */
    switch(vcall_ctx.in_video_channel.state)
    {
        case VCALL_CHANNEL_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_IN_VID_CHANNEL_CLOSED, line);              
            break;
            
        case VCALL_CHANNEL_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_IN_VID_CHANNEL_OPEN, line);               
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_IN_VID_CHANNEL_UNKNOWN, line);               
            break;
    }

    /* out video channel */
    switch(vcall_ctx.out_video_channel.state)
    {
        case VCALL_CHANNEL_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_OUT_VID_CHANNEL_CLOSED, line);              
            break;
            
        case VCALL_CHANNEL_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_OUT_VID_CHANNEL_OPEN, line);               
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_OUT_VID_CHANNEL_UNKNOWN, line);               
            break;
    }

    /* in audio channel */
    switch(vcall_ctx.in_audio_channel.state)
    {
        case VCALL_CHANNEL_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_IN_AUD_CHANNEL_CLOSED, line);              
            break;
            
        case VCALL_CHANNEL_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_IN_AUD_CHANNEL_OPEN, line);               
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_IN_AUD_CHANNEL_UNKNOWN, line);               
            break;
    }

    /* out audio channel */
    switch(vcall_ctx.out_audio_channel.state)
    {
        case VCALL_CHANNEL_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_OUT_AUD_CHANNEL_CLOSED, line);              
            break;
            
        case VCALL_CHANNEL_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_OUT_AUD_CHANNEL_OPEN, line);               
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_OUT_AUD_CHANNEL_UNKNOWN, line);               
            break;
    }
   
}



/*****************************************************************************
 * FUNCTION
 *  vcall_debug_print_view_type
 * DESCRIPTION
 *  Print local / peer view type
 * PARAMETERS
 *  line        [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_debug_print_view_type(kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Peer view type */
    switch(vcall_ctx.peer_view.type)
    {   
        case VCALL_VIEW_HIDE:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_PEER_VIEW_TYPE_HIDE, line);
            break;

        case VCALL_VIEW_SHOW_IMAGE:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_PEER_VIEW_TYPE_SHOW_IMAGE, line);          
            break;

        case VCALL_VIEW_SHOW_VIDEO:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_PEER_VIEW_TYPE_SHOW_VIDEO, line);          
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_PEER_VIEW_TYPE_UNKNOWN, vcall_ctx.peer_view.type, line);            
            break;
     }

    /* Local view type */
    switch(vcall_ctx.local_view.type)
    {   
        case VCALL_VIEW_HIDE:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_LOCAL_VIEW_TYPE_HIDE, line);
            break;

        case VCALL_VIEW_SHOW_IMAGE:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_LOCAL_VIEW_TYPE_SHOW_IMAGE, line);           
            break;

        case VCALL_VIEW_SHOW_VIDEO:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_LOCAL_VIEW_TYPE_SHOW_VIDEO, line);           
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_LOCAL_VIEW_TYPE_UNKNOWN, vcall_ctx.local_view.type, line);         
            break;
     }
    
}


/*****************************************************************************
 * FUNCTION
 *  vcall_debug_print_vt_data_state
 * DESCRIPTION
 *  Print vt task's data state
 * PARAMETERS
 *  data_state      [IN]        Data state
 *  line            [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
static void vcall_debug_print_vt_data_state(kal_int32 data_state, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(data_state)
    {
        case VCALL_DATA_INIT:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VT_DATA_STATE_INIT, line);      
            break;

        case VCALL_DATA_STARVATION:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VT_DATA_STATE_STARVATION, line);                        
            break;

        case VCALL_DATA_REPLENISH:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VT_DATA_STATE_REPLENISH, line);                      
            break;

        case VCALL_DATA_CONSUMING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VT_DATA_STATE_CONSUMING, line);                       
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VT_DATA_STATE_UNKNOWN, data_state, line);                   
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  vcall_debug_print_idp_decode_data
 * DESCRIPTION
 *  Print image datapath decode data
 * PARAMETERS
 *  data            [IN]        data
 *  line            [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
static void vcall_debug_print_idp_decode_data(
                fullvideo_video_decode_data_path_struct *data,
                kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_VIDEO_SRC_WIDTH, data->video_src_width, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_VIDEO_SRC_HEIGHT, data->video_src_height, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_DISPLAY_WIDTH, data->display_width, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_DISPLAY_HEIGHT, data->display_height, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_PAN, data->pan, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_RESIZE_TAR_WIDTH, data->resize_tar_width, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_RESIZE_TAR_HEIGHT, data->resize_tar_height, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_VIDEO_Y_BUFFER_ADDRESS, data->video_yuv_buffer_address, line);
//  kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_VIDEO_U_BUFFER_ADDRESS, data->video_u_buffer_address, line);
//  kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_VIDEO_V_BUFFER_ADDRESS, data->video_v_buffer_address, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_CONTRAST_LEVEL, data->contrast_level, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_BRIGHTNESS_LEVEL, data->brightness_level, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_FORCE_LCD_HW_TRIGGER, data->force_lcd_hw_trigger, line);  
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_IS_UPDATE, data->is_update, line);  
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_IMAGE_PITCH_MODE, data->image_pitch_mode, line);  
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_IMAGE_DATA_FORMAT, data->image_data_format, line);   
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_IMAGE_PITCH_BYTES, data->image_pitch_bytes, line);  
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_FRAME_BUFFER_ADDRESS, data->frame_buffer_address, line);  
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_FRAME_BUFFER_SIZE, data->frame_buffer_size, line);   
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_DECODE_DECODE_UPDATE_LAYER, data->decode_update_layer, line);

}

/*****************************************************************************
 * FUNCTION
 *  vcall_debug_print_idp_encode_data
 * DESCRIPTION
 *  Print image datapath encode data
 * PARAMETERS
 *  data            [IN]        data
 *  line            [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
static void vcall_debug_print_idp_encode_data(
                fullvideo_encode_process_struct *data,
                kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_INTMEM_START_ADDRESS, data->intmem_start_address, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_INTMEM_SIZE, data->intmem_size, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_EXTMEM_START_ADDRESS, data->extmem_start_address, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_EXTMEM_SIZE, data->extmem_size, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_VIDEO_BUFFER1_ADDRESS, data->video_buffer1_address, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_VIDEO_BUFFER2_ADDRESS, data->video_buffer2_address, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_INT_MEM, data->intmem_size, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_SOURCE_WIDTH, data->image_source_width, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_SOURCE_HEIGHT, data->image_source_height, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_IMAGE_WIDTH, data->viedo_encode_image_width, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_IMAGE_HEIGHT, data->viedo_encode_image_height, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_TARGET_WIDTH, data->image_target_width, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_TARGET_HEIGHT, data->image_target_height, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_ENCODE_BIT_RATE, data->encode_bit_rate, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_SHORT_HEADER_MODE, data->short_header_mode, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_RESUME_ENABLE, data->resume_enable, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_LCD_ID, data->lcd_id, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_LCM_START_X, data->lcm_start_x, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_LCM_START_Y, data->lcm_start_y, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_LCM_END_X, data->lcm_end_x, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_LCM_END_Y, data->lcm_end_y, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_ROI_OFFSET_X, data->roi_offset_x, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_ROI_OFFSET_Y, data->roi_offset_y, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_UPDATE_LAYER, data->update_layer, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_HW_UPDATE_LAYER, data->hw_update_layer, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_ROTATE_VALUE, data->rotate_value, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_MIRROR, data->image_mirror, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_SKIP_FRAME_COUNT, data->skip_frame_count, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_FRAME_RATE, data->frame_rate, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_FRAME_BUFFER_ADDRESS, data->frame_buffer_address, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_FRAME_BUFFER_SIZE, data->frame_buffer_size, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_OFFSET_X, data->viedo_encode_offset_x, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_OFFSET_Y, data->viedo_encode_offset_y, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_ROI_BACKGROUND_COLOR, data->roi_background_color, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_LCD_UPDATE, data->lcd_update, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_ZOOM_FACTOR, data->zoom_factor, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_CONTRAST_LEVEL, data->contrast_level, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_BRIGHTNESS_LEVEL, data->brightness_level, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_SATURATION_VALUE, data->saturation_value, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_WB_MODE, data->wb_mode, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_EV_VALUE, data->ev_value, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_BANDING_FREQ, data->banding_freq, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_EFFECT, data->image_effect, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_NIGHT_MODE, data->night_mode, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_MODE, data->overlay_frame_mode, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_OVERLAY_COLOR_DEPTH, data->overlay_color_depth, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_SOURCE_KEY, data->overlay_frame_source_key, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_WIDTH, data->overlay_frame_width, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_HEIGHT, data->overlay_frame_height, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_BUFFER_ADDRESS, data->overlay_frame_buffer_address, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_PITCH_MODE, data->image_pitch_mode, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_DATA_FORMAT, data->image_data_format, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_IMAGE_PITCH_BYTES, data->image_pitch_bytes, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_TV_OUTPUT, data->tv_output, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_TV_OUTPUT_WIDTH, data->tv_output_width, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_TV_OUTPUT_HEIGHT, data->tv_output_height, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_TV_OUTPUT_OFFSET_X, data->tv_output_offset_x, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_TV_OUTPUT_OFFSET_Y, data->tv_output_offset_y, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_TV_OUTPUT_BUFFER1_ADDRESS, data->tv_output_buffer1_address, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_TV_OUTPUT_BUFFER2_ADDRESS, data->tv_output_buffer2_address, line);    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_INTMEM_START_ADDRESS, data->tv_output_buffer_size, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_CB, data->video_encode_cb, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_ENCODE_EVENT_CB, data->encode_event_cb, line);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_IDP_ENCODE_CAM_ENCODE_CB, data->cam_encode_cb, line);

}


/*****************************************************************************
 * FUNCTION
 *  vcall_video_decoder_enter_state
 * DESCRIPTION
 *  Video decoder enter state
 * PARAMETERS
 *  state       [IN]        state 
 *  line        [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_decoder_enter_state(kal_uint32 state, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcall_ctx.video_decoder.state = state;
    kal_trace(TRACE_GROUP_4, VCALL_TRC_VIDEO_DECODER_ENTER_STATE, state, line); 
     
    /* vid deccoder state */
    switch(vcall_ctx.video_decoder.state)
    {   
        case VCALL_CODEC_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_CLOSED, line);  
            break;

        case VCALL_CODEC_STATE_PENDING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_PENDING, line);            
            break;

        case VCALL_CODEC_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_OPEN, line);           
            break;

        case VCALL_CODEC_STATE_DECODING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_DECODING, line);          
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_DECODER_STATE_UNKNOWN, vcall_ctx.video_decoder.state, line);           
            break;
     }
     
}


/*****************************************************************************
 * FUNCTION
 *  vcall_video_encoder_enter_state
 * DESCRIPTION
 *  Video encoder enter state
 * PARAMETERS
 *  state       [IN]        state
 *  line        [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_video_encoder_enter_state(kal_uint32 state, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcall_ctx.video_encoder.state = state;
    kal_trace(TRACE_GROUP_4, VCALL_TRC_VIDEO_ENCODER_ENTER_STATE, state, line); 

    /* vid encoder state */
    switch(vcall_ctx.video_encoder.state)
    {   
        case VCALL_CODEC_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_ENCODER_STATE_CLOSED, line);          
            break;

        case VCALL_CODEC_STATE_PENDING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_ENCODER_STATE_PENDING, line);            
            break;

        case VCALL_CODEC_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_ENCODER_STATE_OPEN, line);           
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_VID_ENCODER_STATE_UNKNOWN, vcall_ctx.video_encoder.state, line);            
            break;
     }
   
}


/*****************************************************************************
 * FUNCTION
 *  vcall_speech_decoder_enter_state
 * DESCRIPTION
 *  Speech decoder enter state
 * PARAMETERS
 *  state       [IN]        state 
 *  line        [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_speech_decoder_enter_state(kal_uint32 state, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcall_ctx.speech_decoder.state = state;
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SPEECH_DECODER_ENTER_STATE, state, line); 
     
     /* aud deccoder state */
    switch(vcall_ctx.speech_decoder.state)
    {   
        case VCALL_CODEC_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_DECODER_STATE_CLOSED, line);  
            break;

        case VCALL_CODEC_STATE_PENDING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_DECODER_STATE_PENDING, line);            
            break;

        case VCALL_CODEC_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_DECODER_STATE_OPEN, line);           
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_DECODER_STATE_UNKNOWN, vcall_ctx.speech_decoder.state, line);           
            break;
     }
      
}


/*****************************************************************************
 * FUNCTION
 *  vcall_speech_encoder_enter_state
 * DESCRIPTION
 *  Video encoder enter state
 * PARAMETERS
 *  state       [IN]        state 
 *  line        [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_speech_encoder_enter_state(kal_uint32 state, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcall_ctx.speech_encoder.state = state;
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SPEECH_ENCODER_ENTER_STATE, state, line); 
     
    /* aud encoder state */
    switch(vcall_ctx.speech_encoder.state)
    {   
        case VCALL_CODEC_STATE_CLOSED:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_ENCODER_STATE_CLOSED, line);          
            break;

        case VCALL_CODEC_STATE_PENDING:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_ENCODER_STATE_PENDING, line);            
            break;

        case VCALL_CODEC_STATE_OPEN:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_ENCODER_STATE_OPEN, line);           
            break;

        default:
            kal_trace(TRACE_GROUP_4, VCALL_TRC_AUD_ENCODER_STATE_UNKNOWN, vcall_ctx.speech_encoder.state, line);            
            break;
     }
      
}
    
/*****************************************************************************
 * FUNCTION
 *  vcall_peer_video_frame_timeout_callback
 * DESCRIPTION
 *  vcall video frame duration timeout callback function
 * PARAMETERS
 *  arg     [IN]        callback arg
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_peer_video_frame_timeout_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_PEER_VIDEO_FRAME_TIMEOUT_CALLBACK);     
    vcall_debug_print_codec_state(__LINE__);

    if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_DECODING)
    {
        vcall_ctx.video_decoder.frame_expired = KAL_TRUE;
    }
    else if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_OPEN)
    {
        /* update decode video frame image */
        vcall_update_peer_view();
        
        /* decode next frame */
        vcall_decode_next_video_frame();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vcall_decode_recover_timeout_callback
 * DESCRIPTION
 *  when decode error, will start a timer to decode next frame
 * PARAMETERS
 *  arg     [IN]        callback arg
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_decode_recover_timeout_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: add trace */
//  kal_trace(TRACE_GROUP_4, VCALL_TRC_PEER_VIDEO_FRAME_TIMEOUT_CALLBACK);     
    vcall_debug_print_codec_state(__LINE__);

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
 *  vcall_local_image_update_timeout_callback
 * DESCRIPTION
 *  callback function to update local image
 * PARAMETERS
 *  arg     [IN]        callback arg
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_local_image_update_timeout_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 cur_tick;
    kal_uint32 diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: add trace */
//  kal_trace(TRACE_GROUP_4, VCALL_TRC_PEER_VIDEO_FRAME_TIMEOUT_CALLBACK);     
    vcall_debug_print_codec_state(__LINE__);
    
    kal_get_time(&cur_tick);

    if (cur_tick < vcall_ctx.video_decoder.frame_display_tick)
    {
        /* wrap around, do nothing */
        return;
    }

    diff = cur_tick - vcall_ctx.video_decoder.frame_display_tick;
    diff <<= 2; /* diff x 4 (4.615), not so accurate , but nevermind */

    if(diff > VCALL_IMAGE_UPDATE_DURATION)
    {
        /*
         * has elapsed VCALL_IMAGE_UPDATE_DURATION amound of time,
         * but not update, need update once 
         */
        vcall_update_peer_view();
    }

    med_start_timer(
        VCALL_IMAGE_UPDATE_TIMER, 
        VCALL_IMAGE_UPDATE_DURATION, 
        vcall_local_image_update_timeout_callback, 
        NULL);    

}


/*****************************************************************************
 * FUNCTION
 *  vcall_init_video_yuv_buffer
 * DESCRIPTION
 *  init yuv buffer struct
 * PARAMETERS
 *  yuv_buf         [IN]
 *  yuv_buf_size    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_init_video_yuv_buffer(vcall_video_yuv_buffer_struct *yuv_buf, kal_int32 yuv_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_INIT_VIDEO_YUV_BUFFER, yuv_buf_size);      

    yuv_buf->data = NULL;
    yuv_buf->data_size = 0;
    yuv_buf->buf_size = yuv_buf_size;
    
    if (yuv_buf_size)
    {
        yuv_buf->data = med_alloc_ext_mem(yuv_buf_size);
        memset(yuv_buf->data, 0, yuv_buf_size);
        ASSERT(yuv_buf->data != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vcall_deinit_video_yuv_buffer
 * DESCRIPTION
 *  deinit yuv buffer struct
 * PARAMETERS
 *  yuv_buf         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_deinit_video_yuv_buffer(vcall_video_yuv_buffer_struct *yuv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_DEINIT_VIDEO_YUV_BUFFER);      
    
    if (yuv_buf->data)
    {
        med_free_ext_mem((void**)&yuv_buf->data);
    }
    
    yuv_buf->data_size = 0;
    yuv_buf->buf_size = 0;
}


/*****************************************************************************
 * FUNCTION
 *  vcall_alloc_video_codec_buffer
 * DESCRIPTION
 *  allocate codec buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_alloc_video_codec_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//  kal_trace(TRACE_GROUP_4, VCALL_TRC_INIT_VIDEO_YUV_BUFFER, yuv_buf_size);      

    ASSERT(vcall_ctx.video_encoder.cfg.p_int_mem_addr == NULL);
    ASSERT(vcall_ctx.video_encoder.cfg.p_ext_mem_addr == NULL);
    ASSERT(vcall_ctx.video_decoder.cfg.p_int_mem_addr == NULL);
    ASSERT(vcall_ctx.video_decoder.cfg.p_ext_mem_addr == NULL);

    /* encoder memory */
    vcall_ctx.video_encoder.cfg.p_int_mem_addr = (kal_uint8*)med_alloc_int_mem(VCALL_VIDEO_ENCODE_INT_MEM_SIZE);
    vcall_ctx.video_encoder.cfg.int_mem_size = VCALL_VIDEO_ENCODE_INT_MEM_SIZE;

    vcall_ctx.video_encoder.cfg.p_ext_mem_addr = (kal_uint8*)med_alloc_ext_mem(VCALL_VIDEO_ENCODE_EXT_MEM_SIZE);
    vcall_ctx.video_encoder.cfg.ext_mem_size = VCALL_VIDEO_ENCODE_EXT_MEM_SIZE;

    /* decoder memory */
    vcall_ctx.video_decoder.cfg.p_int_mem_addr = (kal_uint8*)med_alloc_int_mem(VCALL_VIDEO_DECODE_INT_MEM_SIZE);
    vcall_ctx.video_decoder.cfg.int_mem_size = VCALL_VIDEO_DECODE_INT_MEM_SIZE;

    vcall_ctx.video_decoder.cfg.p_ext_mem_addr = (kal_uint8*)med_alloc_ext_mem(VCALL_VIDEO_DECODE_EXT_MEM_SIZE);
    vcall_ctx.video_decoder.cfg.ext_mem_size = VCALL_VIDEO_DECODE_EXT_MEM_SIZE;

}


/*****************************************************************************
 * FUNCTION
 *  vcall_free_video_codec_buffer
 * DESCRIPTION
 *  free codec buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_free_video_codec_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//  kal_trace(TRACE_GROUP_4, VCALL_TRC_INIT_VIDEO_YUV_BUFFER, yuv_buf_size);      

    /* free encoder memory */
    med_free_int_mem((void**)&vcall_ctx.video_encoder.cfg.p_int_mem_addr);
    med_free_ext_mem((void**)&vcall_ctx.video_encoder.cfg.p_ext_mem_addr);
    
    vcall_ctx.video_encoder.cfg.p_int_mem_addr = NULL;
    vcall_ctx.video_encoder.cfg.p_ext_mem_addr = NULL;    

    /* free decoder memory */
    med_free_int_mem((void**)&vcall_ctx.video_decoder.cfg.p_int_mem_addr);
    med_free_ext_mem((void**)&vcall_ctx.video_decoder.cfg.p_ext_mem_addr);
    
    vcall_ctx.video_decoder.cfg.p_int_mem_addr = NULL;
    vcall_ctx.video_decoder.cfg.p_ext_mem_addr = NULL;    

}



/*****************************************************************************
 * FUNCTION
 *  vcall_get_in_video_data_state
 * DESCRIPTION
 *  get incoming video data state (owned by VT task)
 * PARAMETERS
 *  void
 * RETURNS
 *  vt_downlink_video_Q_state_enum
 *****************************************************************************/
vt_downlink_video_Q_state_enum vcall_get_in_video_data_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vt_downlink_video_Q_state_enum data_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_GET_IN_VIDEO_DATA_STATE);      

    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_MED_VT_Q_QUERY, __LINE__);   
    data_state = vt_med_query_downlink_video_Q_state(&MED_VT_DL_video_Q);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, data_state, __LINE__);       
    
    /* print debug info */
    vcall_debug_print_vt_data_state(data_state, __LINE__);
    return data_state;
}

/*****************************************************************************
 * FUNCTION
 *  vcall_video_set_decode_data_para
 * DESCRIPTION
 *  set decode data para
 * PARAMETERS
 *  video_decode_para   [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool vcall_video_set_decode_data_para(fullvideo_video_decode_data_path_struct *video_decode_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool pan;
    kal_uint32 resize_tar_width;
    kal_uint32 resize_tar_height;
    vcall_video_yuv_buffer_struct *yuv_buf;
    kal_uint32 next_output_yuv_buf_index = vcall_ctx.video_decoder.next_output_yuv_buf_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* NOTE!!: This function might be called under HISR */
//    kal_trace(TRACE_GROUP_4, VCALL_TRC_VIDEO_SET_DECODE_DATA_PARA);          
//    vcall_debug_print_codec_state(__LINE__);
//    vcall_debug_print_view_type(__LINE__);

    ASSERT(vcall_ctx.video_decoder.frame_width != 0);
    ASSERT(vcall_ctx.video_decoder.frame_height != 0);
    ASSERT(vcall_ctx.video_decoder.frame_real_width != 0);
    ASSERT(vcall_ctx.video_decoder.frame_real_height != 0);    

    ASSERT(vcall_ctx.video_decoder.frame_width <= 176);
    ASSERT(vcall_ctx.video_decoder.frame_height <= 144);
    ASSERT(vcall_ctx.video_decoder.frame_real_width <= 176);
    ASSERT(vcall_ctx.video_decoder.frame_real_height <= 144);    
    
    video_decode_para->is_update = KAL_FALSE;

    if (vcall_ctx.peer_view.type == VCALL_VIEW_SHOW_VIDEO)
    {
        /* check if yuv data ready */
        if ((vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_OPEN) || 
            (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_DECODING) ||
            (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_PENDING))
        {
            video_decode_para->is_update = KAL_TRUE;  
        }
    }
    else if (vcall_ctx.peer_view.type == VCALL_VIEW_SHOW_IMAGE)
    {
        video_decode_para->is_update = KAL_TRUE;  
    }

    if (video_decode_para->is_update)
    {
        yuv_buf = &vcall_ctx.video_decoder.yuv_buf[next_output_yuv_buf_index];

        if(yuv_buf->data_size != 0)
        {
            /* update output yuv buf status */
            vcall_ctx.video_decoder.output_yuv_buf_index = next_output_yuv_buf_index;

            video_decode_para->is_update = KAL_TRUE;

            /* when pan is enable, we use resize_width and resize_height as resizer target size */
            pan = KAL_FALSE;
            if (vcall_ctx.video_decoder.frame_width != vcall_ctx.video_decoder.frame_real_width)
            {
                pan = KAL_TRUE;
                resize_tar_width = vcall_ctx.peer_view.width * vcall_ctx.video_decoder.frame_width 
                    / vcall_ctx.video_decoder.frame_real_width; 

                /* resize to larger size, we need to cut some dirty bit's due to resizer's blending */
                if (vcall_ctx.peer_view.width != vcall_ctx.video_decoder.frame_real_width)
                {
                    resize_tar_width += 16;
                }
            }
            else
            {
                resize_tar_width = vcall_ctx.peer_view.width;
            }
            
            if (vcall_ctx.video_decoder.frame_height != vcall_ctx.video_decoder.frame_real_height)
            {
                pan = KAL_TRUE;
                resize_tar_height = vcall_ctx.peer_view.height * vcall_ctx.video_decoder.frame_height
                    / vcall_ctx.video_decoder.frame_real_height; 

                /* resize to larger size, we need to cut some dirty bit's due to resizer's blending */
                if (vcall_ctx.peer_view.height != vcall_ctx.video_decoder.frame_real_height)
                {
                    resize_tar_height += 16;
                }                    
            }
            else
            {
                resize_tar_height = vcall_ctx.peer_view.height;
            }

            /* output by img data path */
            video_decode_para->pan = pan;
            video_decode_para->resize_tar_width = (kal_uint16)resize_tar_width;
            video_decode_para->resize_tar_height = (kal_uint16)resize_tar_height;

            /* source, after padding to 16x */
            video_decode_para->video_src_width = vcall_ctx.video_decoder.frame_width;
            video_decode_para->video_src_height = vcall_ctx.video_decoder.frame_height;

            /* preview size */
            video_decode_para->display_width = vcall_ctx.peer_view.width;
            video_decode_para->display_height = vcall_ctx.peer_view.height;
            
            video_decode_para->video_yuv_buffer_address = (kal_uint32)yuv_buf->data;
            video_decode_para->contrast_level = vcall_ctx.peer_view.contrast;
            video_decode_para->brightness_level = vcall_ctx.peer_view.brightness;
            video_decode_para->force_lcd_hw_trigger = KAL_FALSE;
            video_decode_para->image_pitch_mode = KAL_FALSE;
            video_decode_para->image_pitch_bytes = 0;
            video_decode_para->image_data_format = vcall_ctx.peer_view.image_data_format;
            video_decode_para->frame_buffer_address = vcall_ctx.peer_view.frame_buffer_address;
            video_decode_para->frame_buffer_size = vcall_ctx.peer_view.frame_buffer_size;
            video_decode_para->decode_update_layer = vcall_ctx.peer_view.layer;
        }
    }

    /* print debug info */
    /* TODO: this is called under HISR? */
//  vcall_debug_print_idp_decode_data(video_decode_para, __LINE__);
    
    return video_decode_para->is_update;
}


/*****************************************************************************
 * FUNCTION
 *  vcall_display_callback
 * DESCRIPTION
 *  image data path callback for update LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  fullvideo_video_decode_data_path_struct
 *****************************************************************************/
fullvideo_video_decode_data_path_struct vcall_display_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fullvideo_video_decode_data_path_struct video_decode_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: this is called under HISR? */    
//  kal_trace(TRACE_GROUP_4, VCALL_TRC_DISPLAY_CALLBACK);     
        
    vcall_video_set_decode_data_para(&video_decode_para);
    
    return video_decode_para;
}

/*****************************************************************************
 * FUNCTION
 *  vcall_config_image_data_path
 * DESCRIPTION
 *  config image data path
 * PARAMETERS
 *  recorder                    [IN]
 *  player                      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_config_image_data_path(media_video_record_struct *recorder, media_video_playback_struct *player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result;
    IDP_FULLVIDEO_PATH_enum path;
    fullvideo_video_decode_data_path_struct video_decode_para;
    fullvideo_encode_process_struct video_encode_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CONFIG_IMAGE_DATA_PATH);         
    
    if (vcall_ctx.local_view.type == VCALL_VIEW_SHOW_VIDEO)
    {
        path = IDP_FULLVIDEO_PATH_FULLDUPLEX;
    }
    else
    {
        path = IDP_FULLVIDEO_PATH_DECODEONLY;
    }

    memset(&video_decode_para, 0, sizeof(fullvideo_video_decode_data_path_struct));
    memset(&video_encode_data, 0, sizeof(fullvideo_encode_process_struct));

    /* DECODE PART */
    video_decode_para.display_width = player->display_width;
    video_decode_para.display_height = player->display_height;
    video_decode_para.contrast_level = player->contrast;
    video_decode_para.brightness_level = player->brightness;
    video_decode_para.force_lcd_hw_trigger = KAL_FALSE;
    video_decode_para.image_pitch_mode = KAL_FALSE;
    video_decode_para.image_pitch_bytes = 0;
    video_decode_para.image_data_format = player->image_data_format;
    video_decode_para.frame_buffer_address = (kal_uint32) player->display_buffer_p;
    video_decode_para.frame_buffer_size = player->display_buffer_size;
    video_decode_para.decode_update_layer = player->hw_update_layer;
    /* resize_tar_width, resize_tar_height and pan do not need to pass right now */


    /* ENCODE PART */
    ASSERT(vcall_ctx.video_idp.intmem_start_address == NULL);
    ASSERT(vcall_ctx.video_idp.extmem_start_address == NULL);

    video_encode_data.video_buffer1_address = NULL;     /* not used */
    video_encode_data.video_buffer2_address = NULL;     /* not used */ 
    video_encode_data.init_mem = KAL_TRUE;
    video_encode_data.image_source_width = 0;           /* not used now, will config later */
    video_encode_data.image_source_height = 0;          /* not used now, will config later */
    video_encode_data.viedo_encode_image_width = recorder->encode_width;
    video_encode_data.viedo_encode_image_height = recorder->encode_height;
    video_encode_data.image_target_width = recorder->preview_width;
    video_encode_data.image_target_height = recorder->preview_height;
    video_encode_data.encode_bit_rate = 0;              /* not used now, will config later */
    video_encode_data.short_header_mode = KAL_FALSE;    /* not used now, will config later */
    video_encode_data.resume_enable = KAL_FALSE;
    video_encode_data.lcd_id = recorder->lcd_id;
    video_encode_data.lcm_start_x = recorder->lcd_start_x;
    video_encode_data.lcm_start_y = recorder->lcd_start_y;
    video_encode_data.lcm_end_x = recorder->lcd_end_x;
    video_encode_data.lcm_end_y = recorder->lcd_end_y;
    video_encode_data.roi_offset_x = recorder->roi_offset_x;
    video_encode_data.roi_offset_y = recorder->roi_offset_y;
    video_encode_data.update_layer = recorder->update_layer;
    video_encode_data.hw_update_layer = recorder->hw_update_layer;
    video_encode_data.rotate_value = recorder->lcd_rotate;
    video_encode_data.image_mirror = recorder->camera_rotate;
    video_encode_data.frame_buffer_address = (kal_uint32) recorder->preview_buffer_p;
    video_encode_data.frame_buffer_size = recorder->preview_buffer_size;
    video_encode_data.viedo_encode_offset_x = 0;        /* not used */
    video_encode_data.viedo_encode_offset_y = 0;        /* not used */
    video_encode_data.lcd_update = recorder->lcd_update;
    video_encode_data.zoom_factor = recorder->zoom_factor;
    video_encode_data.contrast_level = recorder->contrast;
    video_encode_data.brightness_level = recorder->brightness;
    video_encode_data.saturation_value = recorder->saturation;
    video_encode_data.wb_mode = recorder->WB;
    video_encode_data.ev_value = recorder->exposure;
    video_encode_data.banding_freq = recorder->banding_freq;
    video_encode_data.image_effect = recorder->effect;
    video_encode_data.night_mode = recorder->night_mode;
    video_encode_data.overlay_frame_mode = 0;
    video_encode_data.overlay_color_depth = 0;
    video_encode_data.overlay_frame_source_key = 0;
    video_encode_data.overlay_frame_width = 0;
    video_encode_data.overlay_frame_height = 0;
    video_encode_data.overlay_frame_buffer_address = 0;
    video_encode_data.image_pitch_mode = KAL_FALSE;
    video_encode_data.image_data_format = recorder->image_data_format;
    video_encode_data.image_pitch_bytes = 0;
    video_encode_data.tv_output = recorder->tv_output;
    video_encode_data.tv_output_width = recorder->tv_output_width;
    video_encode_data.tv_output_height = recorder->tv_output_height;
    video_encode_data.tv_output_offset_x = recorder->tv_output_offset_x;
    video_encode_data.tv_output_offset_y = recorder->tv_output_offset_y;
    video_encode_data.tv_output_buffer1_address = recorder->tv_output_buffer1_address;
    video_encode_data.tv_output_buffer2_address = recorder->tv_output_buffer2_address;
    video_encode_data.tv_output_buffer_size = recorder->tv_output_buffer_size;
    video_encode_data.video_encode_cb = NULL;
    video_encode_data.encode_event_cb = NULL;
    video_encode_data.cam_encode_cb = cam_preview_callback;
    video_encode_data.frame_rate = 15;  /* 15 fps for video */

    if (path == IDP_FULLVIDEO_PATH_FULLDUPLEX)
    {
        /* int memory for image data path */
        video_encode_data.intmem_start_address = 
            vcall_ctx.video_idp.intmem_start_address =
            (kal_uint32)med_alloc_int_mem(VCALL_IMG_DATA_PATH_INT_MEM_SIZE);

        video_encode_data.intmem_size = VCALL_IMG_DATA_PATH_INT_MEM_SIZE;

        /* ext memory for image data path */
        video_encode_data.extmem_start_address = 
            vcall_ctx.video_idp.extmem_start_address =
            (kal_uint32)med_alloc_ext_mem(VCALL_IMG_DATA_PATH_EXT_MEM_SIZE);

        video_encode_data.extmem_size = VCALL_IMG_DATA_PATH_EXT_MEM_SIZE;

        video_encode_data.lcd_id = recorder->lcd_id;
        video_encode_data.lcm_start_x = recorder->lcd_start_x;
        video_encode_data.lcm_start_y = recorder->lcd_start_y;
        video_encode_data.lcm_end_x = recorder->lcd_end_x;
        video_encode_data.lcm_end_y = recorder->lcd_end_y;
        video_encode_data.roi_offset_x = recorder->roi_offset_x;
        video_encode_data.roi_offset_y = recorder->roi_offset_y;
        video_encode_data.update_layer = recorder->update_layer;
        video_encode_data.hw_update_layer = recorder->hw_update_layer;
        video_encode_data.rotate_value = recorder->lcd_rotate;
        video_encode_data.roi_background_color = recorder->roi_background_color;

        /* combine lcd region */
        if (vcall_ctx.peer_view.type == VCALL_VIEW_SHOW_VIDEO ||
            vcall_ctx.peer_view.type == VCALL_VIEW_SHOW_IMAGE)
        {
            if (video_encode_data.lcm_start_x > player->lcd_start_x)
            {
                video_encode_data.lcm_start_x = player->lcd_start_x;
                video_encode_data.roi_offset_x = player->roi_offset_x;
            }
            
            if (video_encode_data.lcm_start_y > player->lcd_start_y)
            {
                video_encode_data.lcm_start_y = player->lcd_start_y;
                video_encode_data.roi_offset_y = player->roi_offset_y;
            }

            if (video_encode_data.lcm_end_x < player->lcd_end_x)
            {
                video_encode_data.lcm_end_x = player->lcd_end_x;
            }
            
            if (video_encode_data.lcm_end_y < player->lcd_end_y)
            {
                video_encode_data.lcm_end_y = player->lcd_end_y;
            }
        }

        
    }
    else if (path == IDP_FULLVIDEO_PATH_DECODEONLY)
    {
        /* int memory for image data path */
        video_decode_para.intmem_start_address = 
            vcall_ctx.video_idp.intmem_start_address =
            (kal_uint32)med_alloc_int_mem(VCALL_IMG_DATA_PATH_INT_MEM_SIZE);

        video_decode_para.intmem_size = VCALL_IMG_DATA_PATH_INT_MEM_SIZE;

        /* ext memory for image data path */
        video_decode_para.extmem_start_address = 
            vcall_ctx.video_idp.extmem_start_address =
            (kal_uint32)med_alloc_ext_mem(VCALL_IMG_DATA_PATH_EXT_MEM_SIZE);

        video_decode_para.extmem_size = VCALL_IMG_DATA_PATH_EXT_MEM_SIZE;

        video_decode_para.lcd_id = player->lcd_id;
        video_decode_para.lcm_start_x = player->lcd_start_x;
        video_decode_para.lcm_start_y = player->lcd_start_y;
        video_decode_para.lcm_end_x = player->lcd_end_x;
        video_decode_para.lcm_end_y = player->lcd_end_y;
        video_decode_para.roi_offset_x = player->roi_offset_x;
        video_decode_para.roi_offset_y = player->roi_offset_y;
        video_decode_para.update_layer = player->update_layer;
        video_decode_para.hw_update_layer = player->hw_update_layer;
        video_decode_para.rotate_value = player->lcd_rotate;
        video_decode_para.roi_background_color = player->roi_background_color;
        
    }

    vcall_debug_print_idp_decode_data(&video_decode_para, __LINE__);    
    vcall_debug_print_idp_encode_data(&video_encode_data, __LINE__);

    /* TODO: add trace */
    init_isp_if();

    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_FULLVIDEO_PROCESS, __LINE__);   
    result = fullvideo_process(path, &video_encode_data, &video_decode_para, vcall_display_callback);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, result, __LINE__);   
    
    /* TODO: result handling */
}

/*****************************************************************************
 * FUNCTION
 *  vcall_close_image_data_path
 * DESCRIPTION
 *  close image data path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_close_image_data_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CLOSE_IMAGE_DATA_PATH);       
    
    ASSERT(vcall_ctx.video_idp.intmem_start_address != NULL);
    ASSERT(vcall_ctx.video_idp.extmem_start_address != NULL);
    
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_EXIT_FULLVIDEO_PROCESS, __LINE__);           
    exit_fullvideo_process();
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, 0, __LINE__);
    
    med_free_int_mem((void**)&vcall_ctx.video_idp.intmem_start_address);
    med_free_ext_mem((void**)&vcall_ctx.video_idp.extmem_start_address);
    
}


/*****************************************************************************
 * FUNCTION
 *  vcall_update_peer_view
 * DESCRIPTION
 *  update peer view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_update_peer_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fullvideo_video_decode_data_path_struct video_decode_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_UPDATE_PEER_VIEW);        
        
    /* check if no camera preview */
    if (vcall_ctx.local_view.type != VCALL_VIEW_SHOW_VIDEO)
    {
        if (vcall_video_set_decode_data_para(&video_decode_para))
        {
            kal_get_time(&vcall_ctx.video_decoder.frame_display_tick);
            
            /* update image to LCD */
            kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_IDP_FULLVIDEO_DECODE_DISPLAY, __LINE__);               
            idp_fullvideo_decode_display(IDP_FULLVIDEO_PATH_DECODEONLY, &video_decode_para);
            kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, 0, __LINE__);            
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vcall_decode_next_video_frame
 * DESCRIPTION
 *  get and decode next video frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_decode_next_video_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vt_downlink_video_Q_meta_struct *frame_meta;
    kal_int32 ret;
    kal_uint8 q_used;
    kal_uint8 q_size;
    kal_uint16 q_percent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_DECODE_NEXT_VIDEO_FRAME);    

    /* get next frame data */
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_MED_VT_GET_FRAME, __LINE__);  
    ret = vt_med_get_downlink_video_Q_frame(&MED_VT_DL_video_Q, &frame_meta, &q_used, &q_size);
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, ret, __LINE__);     
    
    if (ret)
    {
        ASSERT(frame_meta->size < VCALL_VIDEO_DECODE_MAX_FRAME_SIZE);

        memcpy(vcall_ctx.video_decoder.frame_data, frame_meta->data, frame_meta->size);
        vcall_ctx.video_decoder.frame_size = frame_meta->size;
        vcall_ctx.video_decoder.frame_duration = frame_meta->duration;
        vcall_ctx.video_decoder.frame_width = frame_meta->width;
        vcall_ctx.video_decoder.frame_height = frame_meta->height;
        vcall_ctx.video_decoder.frame_real_width = frame_meta->real_width;
        vcall_ctx.video_decoder.frame_real_height = frame_meta->real_height;

        kal_prompt_trace(
            MOD_MED, 
            "[FRAME_INFO]: size:%d, dur:%d, width:%d, height:%d, real_width:%d, real_height:%d", 
            frame_meta->size, 
            frame_meta->duration, 
            frame_meta->width,
            frame_meta->height, 
            frame_meta->real_width,
            frame_meta->real_height);

        /* support up to 176x144 */
        ASSERT(frame_meta->width <= VCALL_VIDEO_DEC_MAX_WIDTH);
        ASSERT(frame_meta->height <= VCALL_VIDEO_DEC_MAX_HEIGHT);
        ASSERT(frame_meta->size != 0);

        /* consume it from buffer */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_MED_VT_BUFF_CONSUME, __LINE__);          
        vt_med_consume_downlink_video_Q_buff(&MED_VT_DL_video_Q, &frame_meta);
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, 0, __LINE__);   

        /* frame duration adjustment - our goal is to consume asap */
        /* 
         * (1) avoid corrupted duration, which might too long 
         * (2) when there are many frame in q, accelerate the consuming 
         */

        /* protect frame duration too long */
        /* it is ok if the timer expire earlier, vt will send repenlish ind to us */
        if (vcall_ctx.video_decoder.frame_duration > VCALL_VIDEO_MAX_FRAME_DURATION)
        {
            vcall_ctx.video_decoder.frame_duration = VCALL_VIDEO_MAX_FRAME_DURATION;
        }

        ASSERT(q_size != 0);
        q_percent = (q_used * 100) / q_size;

        if (q_percent < 20)
        {
            /* no need adjust */
        }
        else if (q_percent < 40)
        {
            /* shorten timer to 80% */
            vcall_ctx.video_decoder.frame_duration *= 80;
            vcall_ctx.video_decoder.frame_duration /= 100;
        }
        else if (q_percent < 60)
        {
            /* shorten timer to 60% */
            vcall_ctx.video_decoder.frame_duration *= 60;
            vcall_ctx.video_decoder.frame_duration /= 100;
        }
        else if (q_percent < 40)
        {
            /* shorten timer to 40% */
            vcall_ctx.video_decoder.frame_duration *= 40;
            vcall_ctx.video_decoder.frame_duration /= 100;
        }
        else
        {
            /* 20ms, consume ASAP */
            vcall_ctx.video_decoder.frame_duration = 20;
        }

        /* avoid timer too short */
        if (vcall_ctx.video_decoder.frame_duration < 20)
        {
            vcall_ctx.video_decoder.frame_duration = 20;
        }

        /* avoid timer too long */
        if (vcall_ctx.video_decoder.frame_duration > 500)
        {
            vcall_ctx.video_decoder.frame_duration = 20;
        }

        kal_prompt_trace(
            MOD_MED, 
            "[DECODE_DUR]: q_used:%d, q_size:%d, q_percent:%d, ori_dur:%d, adj_dur:%d", 
            q_used, 
            q_size, 
            q_percent,
            frame_meta->duration, 
            vcall_ctx.video_decoder.frame_duration);

        /* start timer */
        med_start_timer(
            VCALL_PEER_VIDEO_TIMER, 
            vcall_ctx.video_decoder.frame_duration, 
            vcall_peer_video_frame_timeout_callback, 
            NULL);

        /* start video decoding */
        vcall_start_video_decoder();
    }
}

/*****************************************************************************
 * FUNCTION
 *  vcall_consume_video_encoder
 * DESCRIPTION
 *  consume the rest data in video encoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_consume_video_encoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 packet_size = 0;
    VIDEO_CALL_STATUS status;
    kal_bool put_result;
    kal_uint8 ret_enum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CONSUME_VIDEO_ENCODER);    
   
    if (vcall_ctx.video_encoder.notify_count == 0)
    {
        return;
    }

    vcall_debug_print_codec_state(__LINE__);
  
    if (vcall_ctx.video_encoder.state == VCALL_CODEC_STATE_OPEN)
    {
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_GETNEXTPACKET, __LINE__);         
        status = VideoCall_GetNextPacket(
                    vcall_ctx.video_encoder.packet_data, 
                    VCALL_VIDEO_ENCODE_MAX_PACKET_SIZE, 
                    &packet_size,
                    &ret_enum);
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__);   
        
        while(status  == VIDEO_CALL_STATUS_OK)
        {
            ASSERT(packet_size <= VCALL_VIDEO_ENCODE_MAX_PACKET_SIZE);

            if (packet_size == 0)
            {
                break;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VT_VIDEO_PUT_OUTGOING_DATA, __LINE__);                  
                put_result = vt_video_put_outgoing_data_ex(vcall_ctx.video_encoder.packet_data, packet_size, ret_enum);
                kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, put_result, __LINE__); 

                /* TODO: add error handling */
                ASSERT(put_result == KAL_TRUE);
            }

            kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_GETNEXTPACKET, __LINE__);         
            status = VideoCall_GetNextPacket(
                        vcall_ctx.video_encoder.packet_data, 
                        VCALL_VIDEO_ENCODE_MAX_PACKET_SIZE, 
                        &packet_size,
                        &ret_enum);
            kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__);               
        }
    }

    vcall_ctx.video_encoder.notify_count--;

    //ASSERT(vcall_ctx.video_encoder.notify_count >= 1);
    //vcall_ctx.video_encoder.notify_count--;
}


/*****************************************************************************
 * FUNCTION
 *  vcall_open_video_encoder
 * DESCRIPTION
 *  open and start video encoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_open_video_encoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_CALL_STATUS status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_OPEN_VIDEO_ENCODER);      
    vcall_debug_print_codec_state(__LINE__);
    vcall_debug_print_view_type(__LINE__);    
    vcall_debug_print_channel_state(__LINE__);

    if (vcall_ctx.local_view.type != VCALL_VIEW_SHOW_VIDEO &&
        vcall_ctx.local_view.type != VCALL_VIEW_SHOW_IMAGE)
    {
        return;
    }

    ASSERT(vcall_ctx.video_encoder.state != VCALL_CODEC_STATE_OPEN);
    
    if (vcall_ctx.out_video_channel.state == VCALL_CHANNEL_STATE_OPEN)
    {
        /* open it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_CFGENC, __LINE__);           
        status = VideoCall_CfgEnc(&vcall_ctx.video_encoder.cfg);
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__);  

        /* TODO: error handling */
        ASSERT(VIDEO_CALL_STATUS_OK == status);
        
        /* start it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_STARTENC, __LINE__);                   
        status = VideoCall_StartEnc();
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__); 

        /* TODO: error handling */
        ASSERT(VIDEO_CALL_STATUS_OK == status);

        VCALL_VIDEO_ENCODER_ENTER_STATE(VCALL_CODEC_STATE_OPEN);
    }
    else
    {
        VCALL_VIDEO_ENCODER_ENTER_STATE(VCALL_CODEC_STATE_PENDING);        
    }
}

/*****************************************************************************
 * FUNCTION
 *  vcall_close_video_encoder
 * DESCRIPTION
 *  stop and close video encoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_close_video_encoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_CALL_STATUS status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CLOSE_VIDEO_ENCODER);  
    vcall_debug_print_codec_state(__LINE__);

    if (vcall_ctx.video_encoder.state == VCALL_CODEC_STATE_OPEN)
    {
        /* stop it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_STOPENC, __LINE__);          
        status = VideoCall_StopEnc();
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__); 

        /* TODO: error handling */
        ASSERT(VIDEO_CALL_STATUS_OK == status);
        
        /* consume it if has data */
        vcall_consume_video_encoder();

        /* close it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_CLOSEENC, __LINE__);          
        status = VideoCall_CloseEnc();
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__); 

        /* TODO: error handling */
        ASSERT(VIDEO_CALL_STATUS_OK == status);

        vcall_ctx.video_encoder.event_seq_no++;
        vcall_ctx.video_encoder.notify_count = 0;

    }
    /* update state */

    VCALL_VIDEO_ENCODER_ENTER_STATE(VCALL_CODEC_STATE_CLOSED);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_open_video_decoder
 * DESCRIPTION
 *  open video decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_open_video_decoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_CALL_STATUS status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_OPEN_VIDEO_DECODER);      
    vcall_debug_print_codec_state(__LINE__);
    vcall_debug_print_view_type(__LINE__);    
    vcall_debug_print_channel_state(__LINE__);

    if (vcall_ctx.peer_view.type != VCALL_VIEW_SHOW_VIDEO)
    {
        return;
    }
    
    ASSERT(vcall_ctx.video_decoder.state != VCALL_CODEC_STATE_OPEN);

    if (vcall_ctx.in_video_channel.state == VCALL_CHANNEL_STATE_OPEN)
    {
        /* open it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_CFGDEC, __LINE__);        
        status = VideoCall_CfgDec(&vcall_ctx.video_decoder.cfg);
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__); 

        /* TODO: error handling */
        ASSERT(VIDEO_CALL_STATUS_OK == status);

        /* update state */
        VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_OPEN);
    }
    else if (vcall_ctx.in_video_channel.state == VCALL_CHANNEL_STATE_PAUSE)
    {
        /* set active codec */
        ASSERT(vcall_ctx.video_decoder.codec_type != VIDEO_CALL_CODEC_NONE);
        VideoCall_SetDecActiveCodec(vcall_ctx.video_decoder.codec_type);
        VideoCall_SetEncActiveCodec(vcall_ctx.video_decoder.codec_type); /* TODO: correct?? */
        
        /* notify VT to resume */
        vcall_send_vt_resume_in_video_channel_req();
        
        /* open it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_CFGDEC, __LINE__);        
        status = VideoCall_CfgDec(&vcall_ctx.video_decoder.cfg);
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__); 

        /* TODO: error handling */
        ASSERT(VIDEO_CALL_STATUS_OK == status);

        /* update state */
        vcall_ctx.in_video_channel.state = VCALL_CHANNEL_STATE_OPEN;        
        
        VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_OPEN);
    }
    else
    {
        /* update state */
        VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_PENDING);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  vcall_close_video_decoder
 * DESCRIPTION
 *  close video decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_close_video_decoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_CALL_STATUS status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CLOSE_VIDEO_DECODER);  
    vcall_debug_print_codec_state(__LINE__);

    if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_OPEN)
    {
        /* close it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_CLOSEDEC, __LINE__);  
        status = VideoCall_CloseDec();
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__); 

        /* TODO: error handling */
        ASSERT(VIDEO_CALL_STATUS_OK == status);

        vcall_ctx.video_decoder.frame_expired = KAL_FALSE;

        if (vcall_ctx.in_video_channel.state == VCALL_CHANNEL_STATE_OPEN)
        {
            /* channel still open, notify vt to pause it */
            vcall_send_vt_pause_in_video_channel_req();
            
            vcall_ctx.in_video_channel.state = VCALL_CHANNEL_STATE_PAUSE;
        }
    }

	/* update state */
    VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_CLOSED);
 }


/*****************************************************************************
 * FUNCTION
 *  vcall_start_video_decoder
 * DESCRIPTION
 *  start video decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_start_video_decoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_CALL_STATUS status;
    kal_bool need_toggle;
    kal_uint32 decode_yuv_buf_index = vcall_ctx.video_decoder.decode_yuv_buf_index;
    kal_uint32 output_yuv_buf_index = vcall_ctx.video_decoder.output_yuv_buf_index;
    kal_uint32 next_output_yuv_buf_index = vcall_ctx.video_decoder.next_output_yuv_buf_index;
    kal_bool idp_ret;
       

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_START_VIDEO_DECODER);      
    vcall_debug_print_codec_state(__LINE__);
    
    if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_OPEN)
    {
        /* check yuv buf output status */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_IDP_YUV_MOVE_DONE, __LINE__);  
        idp_ret = idp_fullvideo_yuv_move_done();
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, idp_ret, __LINE__); 
        
        if (idp_ret)
        {
            /* not outputing */
            need_toggle = (next_output_yuv_buf_index == decode_yuv_buf_index);
        }
        else
        {
            /* the yuv buf is outputing */
            need_toggle = (output_yuv_buf_index == decode_yuv_buf_index);
        }

        if (need_toggle)
        {
            decode_yuv_buf_index = 1 - decode_yuv_buf_index;
            vcall_ctx.video_decoder.decode_yuv_buf_index = decode_yuv_buf_index;
        }

        /* reset buf data size */
        vcall_ctx.video_decoder.yuv_buf[decode_yuv_buf_index].data_size = 0;


        if (vcall_ctx.video_decoder.frame_width == 0 ||
            vcall_ctx.video_decoder.frame_height == 0 || 
            vcall_ctx.video_decoder.frame_real_width == 0 ||
            vcall_ctx.video_decoder.frame_real_height == 0)
        {
            /* error, start recover timer */
            med_start_timer(
                VCALL_DECODE_RECOVER_TIMER, 
                20, /* start a short timer */
                vcall_decode_recover_timeout_callback, 
                NULL);
            return;
        }
 
        /* start it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_STARTDEC, __LINE__);         
        status = VideoCall_StartDec(
            vcall_ctx.video_decoder.frame_data, 
            vcall_ctx.video_decoder.frame_size, 
            vcall_ctx.video_decoder.yuv_buf[decode_yuv_buf_index].data);
        
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__); 

        if (status != VIDEO_CALL_STATUS_OK)
        {
            /* error, start revoder timer */
            med_start_timer(
                VCALL_DECODE_RECOVER_TIMER, 
                20, /* start a short timer */
                vcall_decode_recover_timeout_callback, 
                NULL);
            return;
        }
        else
        {
            /* update state */
            VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_DECODING); 
            return;            
        }
       
    }
}


/*****************************************************************************
 * FUNCTION
 *  vcall_stop_video_decoder
 * DESCRIPTION
 *  stop video decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_stop_video_decoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_CALL_STATUS status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_STOP_VIDEO_DECODER);      
    vcall_debug_print_codec_state(__LINE__);    

    if (vcall_ctx.video_decoder.state == VCALL_CODEC_STATE_DECODING)
    {
        /* stop it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_VIDEOCALL_STOPDEC, __LINE__);          
        status = VideoCall_StopDec();
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, status, __LINE__); 

        /* TODO: error handling */
        ASSERT(VIDEO_CALL_STATUS_OK == status);

        /* update state */
        VCALL_VIDEO_DECODER_ENTER_STATE(VCALL_CODEC_STATE_OPEN);        
        
        vcall_ctx.video_decoder.event_seq_no++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vcall_open_speech_codec
 * DESCRIPTION
 *  open speech codec
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_open_speech_codec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_OPEN_SPEECH_CODEC);      
    vcall_debug_print_codec_state(__LINE__);        
    vcall_debug_print_channel_state(__LINE__);      

    /* TODO: ASK JY to split this into decode encode */

    ASSERT(vcall_ctx.speech_encoder.state != VCALL_CODEC_STATE_OPEN &&
           vcall_ctx.speech_decoder.state != VCALL_CODEC_STATE_OPEN)

    if (vcall_ctx.in_audio_channel.state == VCALL_CHANNEL_STATE_OPEN ||
        vcall_ctx.out_audio_channel.state == VCALL_CHANNEL_STATE_OPEN)
    {
        /* open it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_L1_SPEECH_ON, __LINE__);          
        L1SP_Speech_On(RAT_3G324M_MODE);
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, 0, __LINE__); 

        /* update state */
        VCALL_SPEECH_ENCODER_ENTER_STATE(VCALL_CODEC_STATE_OPEN);
        VCALL_SPEECH_DECODER_ENTER_STATE(VCALL_CODEC_STATE_OPEN);        
    }
    else
    {
        /* update state */
        VCALL_SPEECH_ENCODER_ENTER_STATE(VCALL_CODEC_STATE_PENDING);
        VCALL_SPEECH_DECODER_ENTER_STATE(VCALL_CODEC_STATE_PENDING);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  vcall_close_speech_codec
 * DESCRIPTION
 *  close speech codec
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_close_speech_codec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_CLOSE_SPEECH_CODEC);      
    vcall_debug_print_codec_state(__LINE__);        
    vcall_debug_print_channel_state(__LINE__);    

   /* TODO: ASK JY to split this into decode encode */

    if (vcall_ctx.speech_encoder.state == VCALL_CODEC_STATE_OPEN &&
        vcall_ctx.speech_decoder.state == VCALL_CODEC_STATE_OPEN)
    {
         /* close it */
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_L1_SPEECH_OFF, __LINE__);          
        L1SP_Speech_Off();
        kal_trace(TRACE_GROUP_4, VCALL_TRC_CALLING_RESULT, 0, __LINE__); 
    }
    
    /* update state */
    VCALL_SPEECH_ENCODER_ENTER_STATE(VCALL_CODEC_STATE_CLOSED);
    VCALL_SPEECH_DECODER_ENTER_STATE(VCALL_CODEC_STATE_CLOSED);        
    
   
}


#endif /* __MED_VCALL_MOD__ */

