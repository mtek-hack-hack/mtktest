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
 * Filename:
 * ---------
 *  vid_api.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Media Task Video Interface
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
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

#ifdef ISP_SUPPORT
#include "isp_if.h"
#endif 

#ifdef MP4_CODEC
#include  "drv_comm.h"
#include  "visual_comm.h"
#include  "fsal.h"
#include  "mp4_parser.h"
#include  "lcd_if.h"
#include  "rtc_sw.h"
#include  "video_file_creator.h"
#include  "bmd.h"
#include  "video_enc_glb.h"
#include  "video_dec_glb.h"
#include  "video_glb.h"
#endif /* MP4_CODEC */ 

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "vid_main.h"

#ifdef __VID_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __SF_MP4_SUPPORT__
#include "fmt_def.h"
#endif //__SF_MP4_SUPPORT__

#if defined(__MED_MJPG_MOD__)
#include "vid_avi.h"
#endif 

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)

static kal_int32 vid_result;
static kal_int32 vid_pdl_result;
static kal_uint16 vid_image_x;
static kal_uint16 vid_image_y;
static kal_uint64 vid_total_time;
static kal_uint64 vid_video_total_time;
static kal_uint64 vid_audio_total_time;
static kal_int32 vid_handle;


#define VID_SEND_REQ_MSG_MACRO(__req_struct__,__msg_id__)                           \
do {                                                                                \
    __req_struct__ *msg_p = NULL;                                                   \
    ilm_struct *ilm_ptr = NULL;                                                     \
    msg_p = (__req_struct__*)construct_local_para(sizeof(__req_struct__), TD_CTRL); \
    kal_mem_cpy(                                                                    \
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),                           \
        ((kal_uint8*) data) + sizeof(local_para_struct),                            \
        sizeof(__req_struct__) - sizeof(local_para_struct));                        \
    ilm_ptr = allocate_ilm(src_mod_id);                                             \
    ilm_ptr->src_mod_id = src_mod_id;                                               \
    ilm_ptr->dest_mod_id = MOD_MED;                                                 \
    ilm_ptr->sap_id = MED_SAP;                                                      \
    ilm_ptr->msg_id = (msg_type) __msg_id__;                                        \
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;                           \
    ilm_ptr->peer_buff_ptr = NULL;                                                  \
    msg_send_ext_queue(ilm_ptr);                                                    \
} while(0);                                                                         \


#define VID_SEND_NULL_REQ_MSG_MACRO(__req_struct__,__msg_id__)                      \
do {                                                                                \
    __req_struct__ *msg_p = NULL;                                                   \
    ilm_struct *ilm_ptr = NULL;                                                     \
    msg_p = (__req_struct__*)construct_local_para(sizeof(__req_struct__), TD_CTRL); \
    ilm_ptr = allocate_ilm(src_mod_id);                                             \
    ilm_ptr->src_mod_id = src_mod_id;                                               \
    ilm_ptr->dest_mod_id = MOD_MED;                                                 \
    ilm_ptr->sap_id = MED_SAP;                                                      \
    ilm_ptr->msg_id = (msg_type) __msg_id__;                                        \
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;                           \
    ilm_ptr->peer_buff_ptr = NULL;                                                  \
    msg_send_ext_queue(ilm_ptr);                                                    \
} while(0);                                                                         \


/*****************************************************************************
 * FUNCTION
 *  vid_debug_print_cur_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void vid_debug_print_cur_state(kal_uint32 line)
{
    switch(vid_context_p->state)
    {
        case VID_IDLE:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_IDLE, line);
            break;

        case VID_PREVIEW:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_PREVIEW, line);
            break;

        case VID_RECORD:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_RECORD, line);
            break;

        case VID_RECORD_FINISH:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_RECORD_FINISH, line);
            break;

        case VID_RECORD_PAUSED:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_RECORD_PAUSED, line);
            break;
                
        case VID_OPEN_FILE:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_OPEN_FILE, line);
            break;
        
        case VID_FILE_READY:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_FILE_READY, line);
            break;

        case VID_PLAY_INIT:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_PLAY_INIT, line);
            break;

        case VID_PLAY:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_PLAY, line);
            break;

        case VID_AUDIO_PLAY_FINISH:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUDIO_PLAY_FINISH, line);
            break;

        case VID_AUDIO_PLAY_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUDIO_PLAY_ERROR, line);
            break;

        case VID_VISUAL_PLAY_FINISH:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_VISUAL_PLAY_FINISH, line);
            break;

        case VID_PLAY_PAUSED:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_PLAY_PAUSED, line);
            break;

        case VID_FILE_MERGE:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_FILE_MERGE, line);
            break;

        case VID_SEEK:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_SEEK, line);
            break;

        case VID_PLAY_STOP_VISUAL:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_PLAY_STOP_VISUAL, line);
            break;            

        case VID_RECORD_STOP_VISUAL:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_RECORD_STOP_VISUAL, line);
            break;         
            
        case VID_DELAY_OPEN:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_DELAY_OPEN, line);
            break;         

        case VID_RECORD_ABORTING:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_RECORD_ABORTING, line);
            break;         

        case VID_PLAY_ABORTING:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_PLAY_ABORTING, line);
            break;         

        case VID_START_PREVIEW:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_START_PREVIEW, line);
            break;         

        case VID_FILE_MERGE_STOPPING:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_FILE_MERGE_STOPPING, line);
            break;         

        case VID_PDL_META_BUFFERING:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_PDL_META_BUFFERING, line);
            break;                     

        case VID_VIDEO_PLAY_UNDERFLOW:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_VIDEO_PLAY_UNDERFLOW, line);
            break;      
            
       case VID_PLAY_REACH_STOP_TIME:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_REACH_STOP_TIME, line);
            break;           

        case VID_EDITOR_FILE_MERGE:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_EDITOR_FILE_MERGE, line);
            break;                     

        case VID_EDITOR_MERGE_STOPPING:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_EDITOR_MERGE_STOPPING, line);
            break;   

        case VID_RECORD_UPDATE_BLT_PAUSED:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_RECORD_UPDATE_BLT_PAUSED, line);
            break;   

            
        default:
            /* un-handle state, add it to trace */
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_UNKNOW, line);
            break;
    }

    
    switch(vid_context_p->aud_state)
    {
        case VID_AUD_IDLE:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUD_IDEL, line);
            break;    

        case VID_AUD_PLAY_NORMAL:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUD_PLAY_NORMAL, line);
            break;    

        case VID_AUD_PLAY_HIGH_SPEED:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUD_PLAY_HIGH_SPEED, line);
            break;    

        case VID_AUD_PLAY_DUMMY:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUD_PLAY_DUMMY, line);
            break;    

        case VID_AUD_RECORD:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUD_RECORD, line);
            break;    

        case VID_AUD_RECORD_PAUSED:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUD_RECORD_PAUSED, line);
            break;

        case VID_AUD_PLAY_UNDERFLOW:
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUD_PLAY_UNDERFLOW, line);
            break;
            
        default:
            /* un-handle state, add it to trace */
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_STATE_AUD_UNKNOW, line);
            break;
    }
    
}


#if defined(__MED_VID_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vid_debug_print_mp4_parser_return
 * DESCRIPTION
 *  Print mp4 parser's return cause
 * PARAMETERS
 *  mp4_ret             [IN]        MP4_Parser_Status
 *  line                [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vid_debug_print_mp4_parser_return(kal_int32 mp4_ret, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mp4_ret)
    {
        case MP4_PARSER_OK:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_OK, line);
            break;

        case MP4_PARSER_FILE_READ_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_FILE_READ_ERROR, line);
            break;

        case MP4_PARSER_FILE_SEEK_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_FILE_SEEK_ERROR, line);
            break;

        case MP4_PARSER_FILE_ACCESS_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_FILE_ACCESS_ERROR, line);
            break;

        case MP4_PARSER_PARSE_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_PARSE_ERROR, line);
            break;

        case MP4_PARSER_PARSE_TRAK_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_PARSE_TRAK_ERROR, line);
            break;

        case MP4_PARSER_ATOM_NOT_FOUND:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_ATOM_NOT_FOUND, line);
            break;

        case MP4_PARSER_ES_DESCR_TAG_EXPECTED:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_ES_DESCR_TAG_EXPECTED, line);
            break;

        case MP4_PARSER_BITR_BOX_EXPECTED:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_BITR_BOX_EXPECTED, line);
            break;

        case MP4_PARSER_D263_BOX_EXPECTED:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_D263_BOX_EXPECTED, line);
            break;

        case MP4_PARSER_DAMR_BOX_EXPECTED:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_DAMR_BOX_EXPECTED, line);
            break;

        case MP4_PARSER_64BIT_NOT_SUPPORT:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_64BIT_NOT_SUPPORT, line);
            break;

        case MP4_PARSER_LARGER_31BIT_NOT_SUPPORT:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_LARGER_31BIT_NOT_SUPPORT, line);
            break;

        case MP4_PARSER_TOO_MANY_TRACKS:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_TOO_MANY_TRACKS, line);
            break;

        case MP4_PARSER_EXTERNAL_DATA_REFERENCE:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_EXTERNAL_DATA_REFERENCE, line);
            break;
            
        case MP4_PARSER_AUDIO_TOO_MANY_CHANNEL:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_AUDIO_TOO_MANY_CHANNEL, line);
            break;

        case MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT, line);
            break;
            
        case MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT, line);
            break;

        case MP4_PARSER_960_120_IMDCT_NOT_SUPPORT:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_960_120_IMDCT_NOT_SUPPORT, line);
            break;
            
        case MP4_PARSER_NO_MOOV:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_MOOV, line);
            break;
            
        case MP4_PARSER_NO_MVHD:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_MVHD, line);
            break;

        case MP4_PARSER_NO_TRAK:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_TRAK, line);
            break;

        case MP4_PARSER_NO_TKHD:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_TKHD, line);
            break;
            
        case MP4_PARSER_NO_MDIA:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_MDIA, line);
            break;

        case MP4_PARSER_NO_MDHD:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_MDHD, line);
            break;

        case MP4_PARSER_NO_HDLR:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_HDLR, line);
            break;

        case MP4_PARSER_NO_MINF:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_MINF, line);
            break;

        case MP4_PARSER_NO_STBL:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_STBL, line);
            break;          

        case MP4_PARSER_NO_STSD:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_STSD, line);
            break;        

        case MP4_PARSER_NO_STTS:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_STTS, line);
            break;        

        case MP4_PARSER_NO_STSC:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_STSC, line);
            break;        

        case MP4_PARSER_NO_STCO:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_STCO, line);
            break;     

        case MP4_PARSER_WARNING_TRAILING_GARBAGE:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_WARNING_TRAILING_GARBAGE, line);
            break;     

        case MP4_PARSER_READ_EOF:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_READ_EOF, line);
            break;     

        case MP4_PARSER_NO_SUCH_TRACK:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_SUCH_TRACK, line);
            break;     
            
        case MP4_PARSER_INVALID_ARGUMENT:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_INVALID_ARGUMENT, line);
            break;     

        case MP4_PARSER_INTERNAL_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_INTERNAL_ERROR, line);
            break;     

        case MP4_PARSER_NO_SUCH_SAMPLE:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_NO_SUCH_SAMPLE, line);
            break;     

        default:
            kal_trace(TRACE_GROUP_4, VID_TRC_MP4_UNKNOWN_ENUM, mp4_ret, line);
            break;              
           
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_debug_print_vid_drv_return
 * DESCRIPTION
 *  Print video driver's return cause.
 * PARAMETERS
 *  vid_ret             [IN]        MEDIA_STATUS_CODE
 *  line                [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void vid_debug_print_vid_drv_return(kal_int32 vid_ret, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(vid_ret)
    {
        case MEDIA_STATUS_OK:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_MEDIA_STATUS_OK, line);
            break;               

        case MP4_PARSER_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_MP4_PARSER_ERROR, line);
            break;                  

        case VIDEO_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_VIDEO_ERROR, line);
            break;               

        case AUDIO_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_AUDIO_ERROR, line);
            break;                         

        case FSAL_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_FSAL_ERROR, line);
            break;     
            
        case FSAL_READ_EOF:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_FSAL_READ_EOF, line);
            break;     

        case FSAL_SEEK_EOF:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_FSAL_SEEK_EOF, line);
            break;     

        case FS_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_FS_ERROR, line);
            break;

        case MP4_PRODUCER_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_MP4_PRODUCER_ERROR, line);
            break;
            
        case MP4_SAMPLEDATA_ERROR:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_MP4_SAMPLEDATA_ERROR, line);
            break;
            
        case NO_VISUAL_TRACK:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_NO_VISUAL_TRACK, line);
            break;
            
       default:
            kal_trace(TRACE_GROUP_4, VID_TRC_DRV_UNKNOWN_ENUM, vid_ret, line);
            break;      
    }

    

}
#endif /* __MED_VID_MOD__ */


/*****************************************************************************
 * FUNCTION
 *  vid_set_result
 * DESCRIPTION
 *  This function is to set the result.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_result(kal_int32 result, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_RESULT);    
    vid_debug_print_cur_state(__LINE__);
    med_debug_print_result(result, line);
    vid_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  vid_set_pdl_result
 * DESCRIPTION
 *  This function is to set the result.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_pdl_result(kal_int32 result, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_RESULT);    
    vid_debug_print_cur_state(__LINE__);
    med_debug_print_result(result, line);
    vid_pdl_result = result;
}



/*****************************************************************************
 * FUNCTION
 *  vid_set_image_size
 * DESCRIPTION
 *  This function is to set the decoded image size.
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_image_size(kal_uint16 x, kal_uint16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_image_x = x;
    vid_image_y = y;
}


/*****************************************************************************
 * FUNCTION
 *  vid_set_total_time
 * DESCRIPTION
 *  This function is to set the total time.
 * PARAMETERS
 *  total_time      [IN]        
 *  x(?)
 *  y(?)
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_total_time(kal_uint64 total_time, kal_uint64 video_total_time, kal_uint64 audio_total_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_total_time = total_time;
    vid_video_total_time = video_total_time;
    vid_audio_total_time = audio_total_time;    
}

/*****************************************************************************
 * FUNCTION
 *  vid_set_handle
 * DESCRIPTION
 *  This function is to set the handle.
 * PARAMETERS
 *  total_time      [IN]        
 *  x(?)
 *  y(?)
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_handle = handle;
}



/*****************************************************************************
 * FUNCTION
 *  media_vid_preview
 * DESCRIPTION
 *  This function is to start video preview.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 *  vid_record_struct* record(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_preview(module_type src_mod_id, media_vid_preview_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_preview_req_struct, MSG_ID_MEDIA_VID_PREVIEW_REQ); 
    VID_WAIT_EVENT(VID_EVT_PREVIEW);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_record
 * DESCRIPTION
 *  This function is to start video recording.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  record          [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_record(module_type src_mod_id, media_vid_record_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_record_req_struct, MSG_ID_MEDIA_VID_RECORD_REQ);         
    VID_WAIT_EVENT(VID_EVT_RECORD);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_stop
 * DESCRIPTION
 *  This function is to stop video recording/playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VID_SEND_NULL_REQ_MSG_MACRO(media_vid_stop_req_struct, MSG_ID_MEDIA_VID_STOP_REQ);         
    VID_WAIT_EVENT(VID_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_file_merge
 * DESCRIPTION
 *  This function is to merge temp files to a video file.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  path            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_file_merge(module_type src_mod_id, media_vid_file_merge_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VID_SEND_REQ_MSG_MACRO(media_vid_file_merge_req_struct, MSG_ID_MEDIA_VID_FILE_MERGE_REQ);       
    VID_WAIT_EVENT(VID_EVT_FILE_MERGE);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_open
 * DESCRIPTION
 *  This function is to open a video file/array/stream.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  open            [?]         
 *  vid_open_file_struct* open_file(?)
 *  kal_uint16 seq_num(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_open(module_type src_mod_id, media_vid_open_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_image_x = 0;
    vid_image_y = 0;
    vid_total_time = 0;
    vid_handle = 0;
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_open_req_struct, MSG_ID_MEDIA_VID_OPEN_REQ);    
    VID_WAIT_EVENT(VID_EVT_OPEN);
    
    if (data->image_width)
    {
        *data->image_width = vid_image_x;
    }
    if (data->image_height)
    {
        *data->image_height = vid_image_y;
    }
    if (data->total_time)
    {
        *data->total_time = vid_total_time;
    }
    if (data->handle)
    {
        *data->handle = vid_handle;
    }
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_close
 * DESCRIPTION
 *  This function is to close a video file/array/stream.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_close(module_type src_mod_id, media_vid_close_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VID_SEND_REQ_MSG_MACRO(media_vid_close_req_struct, MSG_ID_MEDIA_VID_CLOSE_REQ);     
    VID_WAIT_EVENT(VID_EVT_CLOSE);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_play
 * DESCRIPTION
 *  This function is to start video playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  play            [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_play(module_type src_mod_id, media_vid_play_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_play_req_struct, MSG_ID_MEDIA_VID_PLAY_REQ);      
    VID_WAIT_EVENT(VID_EVT_PLAY);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_seek
 * DESCRIPTION
 *  This function is to seek to the given position.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  seek            [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_seek(module_type src_mod_id, media_vid_seek_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_seek_req_struct, MSG_ID_MEDIA_VID_SEEK_REQ);       
    VID_WAIT_EVENT(VID_EVT_SEEK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_pause
 * DESCRIPTION
 *  This function is to pause the video playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [IN]
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_pause(module_type src_mod_id,  media_vid_pause_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_pause_req_struct, MSG_ID_MEDIA_VID_PAUSE_REQ);        
    VID_WAIT_EVENT(VID_EVT_PAUSE);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_resume
 * DESCRIPTION
 *  This function is to resume the video playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_resume(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_NULL_REQ_MSG_MACRO(media_vid_resume_req_struct, MSG_ID_MEDIA_VID_RESUME_REQ);         
    VID_WAIT_EVENT(VID_EVT_RESUME);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_stop_time
 * DESCRIPTION
 *  This function is to set stop time for video play.
 * PARAMETERS
 *  src_mod_id      [IN]        source module  
 *  stop_time       [IN]        stop_time
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_set_stop_time(module_type src_mod_id, media_vid_set_stop_time_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_set_stop_time_req_struct, MSG_ID_MEDIA_VID_SET_STOP_TIME);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_set_active
 * DESCRIPTION
 *  This function is to set a video handle to active, this is used for
 *  editor's multi opening
 * PARAMETERS
 *  src_mod_id               [IN]        
 *  vid_set_active_struct    [IN]          active handle
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_set_active(module_type src_mod_id, media_vid_edt_set_active_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_set_active_req_struct, MSG_ID_MEDIA_VID_EDT_SET_ACTIVE_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_enc_open
 * DESCRIPTION
 *  open a video encode session
 *  caller should following calling sequence
 *  (1) media_vid_edt_enc_open
 *  (2) media_vid_edt_enc_append
 *  (3) media_vid_edt_enc_append 
 *  (4) media_vid_edt_enc_append  
 *  (5) more append if needed...
 *  (6) media_vid_edt_enc_merge   
 *  (7) media_vid_edt_enc_close 
 * PARAMETERS
 *  src_mod_id                           [IN]           source mod id
 *  media_vid_edt_enc_open_req_struct    [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_enc_open(module_type src_mod_id, media_vid_edt_enc_open_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_enc_open_req_struct, MSG_ID_MEDIA_VID_EDT_ENC_OPEN_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_enc_close
 * DESCRIPTION
 *  close video encode session
 * PARAMETERS
 *  src_mod_id                           [IN]           source mod id
 *  media_vid_edt_enc_close_req_struct   [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_enc_close(module_type src_mod_id, media_vid_edt_enc_close_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_enc_close_req_struct, MSG_ID_MEDIA_VID_EDT_ENC_CLOSE_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_enc_append
 * DESCRIPTION
*   append video for encoding
 * PARAMETERS
 *  src_mod_id                           [IN]           source mod id
 *  media_vid_edt_enc_append_req_struct  [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_enc_append(module_type src_mod_id, media_vid_edt_enc_append_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_enc_append_req_struct, MSG_ID_MEDIA_VID_EDT_ENC_APPEND_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_enc_merge
 * DESCRIPTION
 *  merge appended video
 * PARAMETERS
 *  src_mod_id                           [IN]           source mod id
 *  media_vid_edt_enc_merge_req_struct   [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_enc_merge(module_type src_mod_id, media_vid_edt_enc_merge_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_enc_merge_req_struct, MSG_ID_MEDIA_VID_EDT_ENC_MERGE_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}



/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_enc_stop_merge
 * DESCRIPTION
 *  merge appended video
 * PARAMETERS
 *  src_mod_id                               [IN]           source mod id
 *  media_vid_edt_enc_stop_merge_req_struct  [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_enc_stop_merge(module_type src_mod_id, media_vid_edt_enc_stop_merge_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_enc_stop_merge_req_struct, MSG_ID_MEDIA_VID_EDT_ENC_STOP_MERGE_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_open_bgm
 * DESCRIPTION
 *  open bgm
 * PARAMETERS
 *  src_mod_id                           [IN]           source mod id
 *  media_vid_edt_open_bgm_req_struct    [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_open_bgm(module_type src_mod_id, media_vid_edt_open_bgm_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_open_bgm_req_struct, MSG_ID_MEDIA_VID_EDT_OPEN_BGM_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_close_bgm
 * DESCRIPTION
 *  open bgm
 * PARAMETERS
 *  src_mod_id                           [IN]           source mod id
 *  media_vid_edt_close_bgm_req_struct   [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_close_bgm(module_type src_mod_id, media_vid_edt_close_bgm_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_close_bgm_req_struct, MSG_ID_MEDIA_VID_EDT_CLOSE_BGM_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_open_silence
 * DESCRIPTION
 *  open bgm
 * PARAMETERS
 *  src_mod_id                               [IN]           source mod id
 *  media_vid_edt_open_silence_req_struct    [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_open_silence(module_type src_mod_id, media_vid_edt_open_silence_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_open_silence_req_struct, MSG_ID_MEDIA_VID_EDT_OPEN_SILENCE_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_close_silence
 * DESCRIPTION
 *  open bgm
 * PARAMETERS
 *  src_mod_id                               [IN]           source mod id
 *  media_vid_edt_close_silence_req_struct   [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_close_silence(module_type src_mod_id, media_vid_edt_close_silence_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_close_silence_req_struct, MSG_ID_MEDIA_VID_EDT_CLOSE_SILENCE_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_edt_init
 * DESCRIPTION
 *  open bgm
 * PARAMETERS
 *  src_mod_id                               [IN]           source mod id
 *  media_vid_edt_init_request_struct        [IN]           data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_edt_init(module_type src_mod_id, media_vid_edt_init_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_edt_init_req_struct, MSG_ID_MEDIA_VID_EDT_INIT_REQ);         
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;    
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_iframe
 * DESCRIPTION
 *  This function is to get iframe when the video file.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  iframe          [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_get_iframe(module_type src_mod_id, media_vid_get_iframe_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_get_iframe_req_struct, MSG_ID_MEDIA_VID_GET_IFRAME_REQ);     
    VID_WAIT_EVENT(VID_EVT_GET_IFRAME);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_display
 * DESCRIPTION
 *  This function is to set display device for video play.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  device          [IN]        
 *  vid_get_iframe_struct* iframe(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_set_display(module_type src_mod_id, media_vid_set_display_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_set_display_req_struct, MSG_ID_MEDIA_VID_SET_DISPLAY_REQ);        
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}



/*****************************************************************************
 * FUNCTION
 *  media_vid_update_blt_pause
 * DESCRIPTION
 *  Pause for update blt parameters 
 * PARAMETERS
 *  src_mod_id                                  [IN]        
 *  media_vid_update_blt_pause_req_struct       [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_update_blt_pause(module_type src_mod_id, media_vid_update_blt_pause_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_update_blt_pause_req_struct, MSG_ID_MEDIA_VID_UPDATE_BLT_PAUSE_REQ);        
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_vid_update_blt_resume
 * DESCRIPTION
 *  Resume for update blt parameters 
 * PARAMETERS
 *  src_mod_id                                  [IN]        
 *  media_vid_update_blt_resume_req_struct      [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_update_blt_resume(module_type src_mod_id, media_vid_update_blt_resume_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_update_blt_resume_req_struct, MSG_ID_MEDIA_VID_UPDATE_BLT_RESUME_REQ);        
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}




/*****************************************************************************
 * FUNCTION
 *  media_vid_set_param
 * DESCRIPTION
 *  This function is to set video parameters.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param           [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_set_param(module_type src_mod_id, media_vid_set_param_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_set_param_req_struct, MSG_ID_MEDIA_VID_SET_PARAM_REQ);    
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_em_mode
 * DESCRIPTION
 *  This function is to set engineer mode of video function.
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_set_em_mode(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->em_mode = mode;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_em_mode
 * DESCRIPTION
 *  This function is to get engineer mode of video function.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8 mode
 *****************************************************************************/
kal_uint8 media_vid_get_em_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vid_context_p->em_mode;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_audio_profile
 * DESCRIPTION
 *  get audio profile
 * PARAMETERS
 *  channel_no        [IN]        
 *  sampling_rate       [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
void media_vid_get_audio_profile(module_type src_mod_id, kal_uint8 *channel_no_p, kal_uint16 *sampling_rate_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* function called, src_mod_id not used */
    
	*channel_no_p = vid_context_p->audio_channel_no;
    *sampling_rate_p = vid_context_p->audio_sample_rate;  
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_max_digital_zoom_factor
 * DESCRIPTION
 *  This function is to get max digital zoom factor with given width and heigh.
 * PARAMETERS
 *  target_width        [IN]        
 *  target_height       [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 media_vid_get_max_digital_zoom_factor(module_type src_mod_id, kal_uint16 target_width, kal_uint16 target_height)
{
#ifdef ISP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* function called, src_mod_id not used */

    return get_max_digital_zoom_factor(target_width, target_height);
#else /* ISP_SUPPORT */ 
    return 0;
#endif /* ISP_SUPPORT */ 
}


#if defined (__MED_VID_MOD__)
/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_play_time
 * DESCRIPTION
 *  This function is to get current time when video playing. 
 *  This function will be call under MMI context
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_play_time(module_type src_mod_id, kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(vid_context_p->vid_get_time_mutex);
    video_dec_get_play_time(time);
    kal_give_mutex(vid_context_p->vid_get_time_mutex);    
    
    vid_context_p->current_time = *time;
    
    /* avoid cur time > total time */
    if (vid_context_p->current_time > vid_context_p->total_time)
    {
        vid_context_p->current_time = vid_context_p->total_time;
    }
    
    /* kal_uint64 cant print trace correctly, we need assign to kal_uint32 first */
    cur_time = vid_context_p->current_time;
    kal_trace(TRACE_GROUP_4, VID_MMI_TRC_CUR_TIME, cur_time, __LINE__);

    /* TRICKY!!, this is called under MMI task ? */
    if ((*time) >= vid_context_p->total_time &&
        VID_IN_STATE(VID_VISUAL_PLAY_FINISH) && VID_AUD_IN_STATE(VID_AUD_PLAY_HIGH_SPEED))
    {
        vid_send_audio_play_finish_ind(MED_RES_END_OF_FILE);
    }

}



/*****************************************************************************
 * FUNCTION
 *  media_vid_get_decode_time
 * DESCRIPTION
 *  This function is to get current time by the given frame index.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  frame_no        [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_get_decode_time(module_type src_mod_id, kal_uint32 frame_no, kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Video_GetDecodeTime(frame_no, time) == MEDIA_STATUS_OK)
    {
        return MED_RES_OK;
    }
    else
    {
        return MED_RES_ERROR;
    }
}



/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_frame_num
 * DESCRIPTION
 *  This function is to get current frame number when video playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  frame_num       [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_frame_num(module_type src_mod_id, kal_uint32 *frame_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *frame_num = video_dec_get_current_frame_no();
}



/*****************************************************************************
 * FUNCTION
 *  media_vid_frame_to_time
 * DESCRIPTION
 *  This function is to map given frame number to the time.
 * PARAMETERS
 *  frame       [IN]        
 *  time        [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_frame_to_time(kal_uint32 frame, kal_uint32 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((video_dec_frame2time(frame, time)) == MEDIA_STATUS_OK)
    {
        return MED_RES_OK;
    }
    else
    {
        return MED_RES_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_time_to_frame
 * DESCRIPTION
 *  This function is to map given time to the frame number.
 * PARAMETERS
 *  time        [IN]        
 *  frame       [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_time_to_frame(kal_uint32 time, kal_uint32 *frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (time > vid_video_total_time)
    {
        time = (kal_uint32)vid_video_total_time;
    }
    
    if ((video_dec_time2frame(time, frame)) == MEDIA_STATUS_OK)
    {
        return MED_RES_OK;
    }
    else
    {
        return MED_RES_ERROR;
    }
}



#if defined(__MED_VID_PDL_MOD__)
/*****************************************************************************
 * FUNCTION
 *  media_vid_get_pdl_percent
 * DESCRIPTION
 *  get progressive download's buffer percentage
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [IN]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
kal_int32 media_vid_get_pdl_percent(module_type src_mod_id, media_vid_get_pdl_percent_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_get_pdl_percent_req_struct, MSG_ID_MEDIA_VID_GET_PDL_PRECENT_REQ);
    VID_WAIT_EVENT(VID_EVT_GET_INFO);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_pdl_max_play_time
 * DESCRIPTION
 *  get progressive download's max play time
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [IN]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
kal_int32 media_vid_get_pdl_max_time(module_type src_mod_id, media_vid_get_pdl_max_time_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_pdl_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_get_pdl_max_time_req_struct, MSG_ID_MEDIA_VID_GET_PDL_MAX_TIME_REQ);    
    VID_WAIT_EVENT(VID_EVT_GET_INFO);
    return vid_pdl_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_check_is_pdl_file
 * DESCRIPTION
 *  get progressive download's max play time
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [IN]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
kal_int32 media_vid_check_is_pdl_file(module_type src_mod_id, media_vid_check_is_pdl_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    VID_SEND_REQ_MSG_MACRO(media_vid_check_is_pdl_req_struct, MSG_ID_MEDIA_VID_CHECK_IS_PDL_REQ);    
    VID_WAIT_EVENT(VID_EVT_GET_INFO);
    return vid_result;
}
#endif /* defined(__MED_VID_PDL_MOD__) */


#if defined(__MED_VID_ENC_MOD__)
/*****************************************************************************
 * FUNCTION
 *  media_vid_check_unfinished_file
 * DESCRIPTION
 *  This function is to check unfinished video recording file.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  True/False
 *****************************************************************************/
kal_bool media_vid_check_unfinished_file(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vid_check_unfinished_file();
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_clean_temp_files
 * DESCRIPTION
 *  This function is to clean temp files.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_clean_temp_files(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_clean_temp_files();
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_record_size
 * DESCRIPTION
 *  This function is to get current record file size
 * PARAMETERS
 *  src_mod_id          [IN]            source module
 *  file_size           [OUT]           file size
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_get_current_record_size(module_type src_mod_id, kal_uint64 *file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VID_IN_STATE(VID_RECORD) || 
        VID_IN_STATE(VID_RECORD_FINISH) ||
        VID_IN_STATE(VID_RECORD_PAUSED) ||
        VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        *file_size = vid_get_current_file_size();
    }
    else
    {
        *file_size = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_record_time
 * DESCRIPTION
 *  This function is to get current time when video recording.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_record_time(module_type src_mod_id, kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *time = video_enc_get_current_time();

    cur_time = *time;
    kal_trace(TRACE_GROUP_4, VID_MMI_TRC_CUR_TIME, cur_time, __LINE__);        
}
#endif /* defined(__MED_VID_ENC_MOD__) */

#endif /* defined(__MED_VID_MOD__) */ 






#if defined(__MED_MJPG_MOD__)
/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_play_time
 * DESCRIPTION
 *  This function is to get current time when video playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_play_time(module_type src_mod_id, kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SF_MP4_SUPPORT__
    if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
    {
    #ifndef WIN32
//Huyanwei Add Macro Control
    	  vdo_get_play_time(time);
	#endif
    }
    else
#endif //__SF_MP4_SUPPORT__
    *time = vid_context_p->time_played;

    /* kal_uint64 cant print trace correctly, we need assign to kal_uint32 first */
    cur_time = vid_context_p->time_played;
    kal_trace(TRACE_GROUP_4, VID_MMI_TRC_CUR_TIME, cur_time, __LINE__);    
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_record_size
 * DESCRIPTION
 *  This function is to get current record file size
 * PARAMETERS
 *  src_mod_id          [IN]            source module
 *  file_size           [OUT]           file size
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_get_current_record_size(module_type src_mod_id, kal_uint64 *file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VID_IN_STATE(VID_RECORD) || 
        VID_IN_STATE(VID_RECORD_FINISH) ||
        VID_IN_STATE(VID_RECORD_PAUSED) ||
        VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        *file_size = med_avi_get_cur_file_size();
    }
    else
    {
        *file_size = 0;
    }
}



/*****************************************************************************
 * FUNCTION
 *  media_vid_get_decode_time
 * DESCRIPTION
 *  This function is to get current time by the given frame index.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  frame_no        [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_get_decode_time(module_type src_mod_id, kal_uint32 frame_no, kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *time = 0;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_record_time
 * DESCRIPTION
 *  This function is to get current time when video recording.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_record_time(module_type src_mod_id, kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_avi_get_cur_record_time(time);
    
    cur_time = *time;
    kal_trace(TRACE_GROUP_4, VID_MMI_TRC_CUR_TIME, cur_time, __LINE__);       
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_frame_num
 * DESCRIPTION
 *  This function is to get current frame number when video playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  frame_num       [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_frame_num(module_type src_mod_id, kal_uint32 *frame_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *frame_num = (kal_uint32) MAX(vid_context_p->current_frame_num, 0);
}

/* dummy code */


/*****************************************************************************
 * FUNCTION
 *  media_vid_frame_to_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  frame       [IN]        
 *  time        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_vid_frame_to_time(kal_uint32 frame, kal_uint32 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MED_RES_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_time_to_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time        [IN]        
 *  frame       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_vid_time_to_frame(kal_uint32 time, kal_uint32 *frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MED_RES_ERROR;
}


#if defined(__MED_MJPG_ENC_MOD__)
/*****************************************************************************
 * FUNCTION
 *  media_vid_check_unfinished_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool media_vid_check_unfinished_file(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vid_check_unfinished_file();
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_clean_temp_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_clean_temp_files(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_clean_temp_files();
}
#endif /* defined(__MED_MJPG_ENC_MOD__) */
#endif /* defined(__MED_MJPG_MOD__) */ 


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_overlay_palette
 * DESCRIPTION
 *  This function is to set the overlay palette for camera.
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  palette_size            [IN]        
 *  palette_addr_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_set_overlay_palette(module_type src_mod_id, kal_uint8 palette_size, kal_uint32 *palette_addr_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_send_set_overlay_palette_req(src_mod_id, palette_size, palette_addr_ptr);
    VID_WAIT_EVENT(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_volume_level
 * DESCRIPTION
 *  This function is to set volume
 * PARAMETERS
 *  src_mod_id      [IN]    module id
 *  volume_level    [IN]    volume level (From 0~100)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_vid_set_volume_level(module_type src_mod_id, kal_uint8 volume_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(volume_level > 100)
    {
        return MED_RES_FAIL;
    }

    vid_set_vol_level(volume_level);
    return MED_RES_OK;
}


#endif /* defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 

#ifdef __SF_MP4_SUPPORT__ //tylerWang
typedef struct _SFMp4Info
{
	kal_uint32 avg_fps;
	kal_uint16 video_width;
	kal_uint16 video_height;
	kal_uint32 video_datarate;
	kal_uint32 total_datarate;
} SFMp4Info;

typedef int (*sfmp4_info_hook)(const SFMp4Info* info);

#ifndef WIN32
//Huyanwei Add Macro Control
extern void vdo_set_info_hook(sfmp4_info_hook hook);
#endif
 
static int test_mp4_hook(const SFMp4Info* info)
{
      return MED_RES_OK;
}

void initializeSFMP4()
{
  static int iii=0;
  if(iii==0)
  {
  #ifndef WIN32
//Huyanwei Add Macro Control
   vdo_set_info_hook(test_mp4_hook);
  #endif
   iii++;
  } 	
}	

#endif   //__SF_MP4_SUPPORT__

#endif /* MED_NOT_PRESENT */ 

