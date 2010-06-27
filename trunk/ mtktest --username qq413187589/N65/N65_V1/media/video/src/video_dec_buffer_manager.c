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
 *   video_dec_buffer_manager.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   This file defines buffer management APIs of mpeg4 decode.
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
#include "app_ltlcom.h"      /* Task message communiction */
#include "stacklib.h"          /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"     /*Timer*/
#include "app_buff_alloc.h" /*buffer*/
#include "task_config.h"     /* Task creation */
#include "stack_ltlcom.h"   /*msg_send_ext_queue.....definitions*/
#include "intrCtrl.h"
#include "video_hw.h"
#include "med_global.h"
#ifdef __STREAM_TRACE_ON__
#include "med_trc.h"
#endif 

//#define STREM_DEC_BUFFER_DBG_TRACE

/* mutex can not be dynamic allocated */
static kal_mutexid  g_video_dec_buffer_mutex;
/* frame buffer manager uses array, so alloacte it only when used */
VIDEO_DEC_BUFFER_MGR_STRUCT *g_video_dec_buffer_mgr_ptr;
static MEDIA_STATUS_CODE video_dec_put_frame_to_buffer_from_file(void);

#ifdef STREAM_SUPPORT
static VIDEO_RTP_PARSE_INFO g_video_rtp_info;
static kal_uint8* video_dec_stream_check_sequence_pkt(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_size);
static kal_uint8* video_dec_stream_get_sequence_pkt(kal_uint32 *p_size);

#ifdef __VIDEO_STREAM_STORE_BUFFER__
static STFSAL FSAL_VIDEO_STREAM_FILE;
static STFSAL FSAL_VIDEO_STREAM_BUFFER_FILE;
static void video_dec_open_stream_file(void);
static void video_dec_store_stream_file(kal_uint8* mem_addr, kal_uint32 size);
static void video_dec_store_stream_buffer_file(kal_uint8* mem_addr, kal_uint32 size);
static void video_dec_unstore_stream_buffer_file(kal_uint32 size);
static void video_dec_close_stream_file(void);
#endif /*__VIDEO_STREAM_STORE_BUFFER__*/
extern void video_rtp_reorder_put_pkt(kal_uint8 *data, kal_uint32 size, kal_uint32 sequence);
extern kal_uint8* video_rtp_reorder_get_pkt(kal_uint32 sequence, kal_uint32 *p_size, kal_uint32 *p_sequnce);
#endif


/* Config and init buffer management.
*   It should be executed in task level. It may be configured according to differnet application
* @param cb_info buffer senario and callback function information
* @return None
*/
void video_dec_config_buffer(VIDEO_DEC_BUFFER_CB_STRUCT cb_info)
{
    kal_uint32 index;

    kal_uint8 *buffer_addr;
    kal_uint32 buffer_count = 0;
    kal_uint32 buffer_size = 0;
    kal_uint8 *current_buffer_addr;
    kal_uint32 buffer_addr_offset;

    if (kal_if_hisr() == KAL_TRUE)
        EXT_ASSERT(0, 0, 0, 0);

    /* Get control variable memory */
    g_video_dec_buffer_mgr_ptr = (VIDEO_DEC_BUFFER_MGR_STRUCT *)extmem_get_buffer(sizeof(VIDEO_DEC_BUFFER_MGR_STRUCT));

    /* Get real buffer memory */
    if(cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_EDITOR)
    {
    #if defined(__VIDEO_EDITOR__)
        buffer_size = VIDEO_EDITOR_DEC_BUFFER_SIZE * VIDEO_EDITOR_DEC_BUFFER_COUNT;
        buffer_count = VIDEO_EDITOR_DEC_BUFFER_COUNT;
    #else
        ASSERT(0);
    #endif
    }
    else if( cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_FILE)
    {
        buffer_size = VIDEO_DEC_BUFFER_SIZE * VIDEO_DEC_BUFFER_COUNT;
        buffer_count = VIDEO_DEC_BUFFER_COUNT;
    }    
    else if(cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE)
    {
    #ifdef PGDL_SUPPORT
        buffer_size = VIDEO_DEC_PREGRESSIVE_DL_BUFFER_SIZE * VIDEO_DEC_PREGRESSIVE_DL_BUFFER_COUNT;
        buffer_count = VIDEO_DEC_PREGRESSIVE_DL_BUFFER_COUNT;
    #else
        ASSERT(0);
    #endif
    }
    else if(cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_STREAM)
    {
    #ifdef STREAM_SUPPORT
        buffer_size = VIDEO_DEC_STREAM_BUFFER_SIZE * VIDEO_DEC_STREAM_BUFFER_COUNT;
        buffer_count = VIDEO_DEC_STREAM_BUFFER_COUNT;
        if (buffer_count > VIDEO_DEC_MAX_BUFFER_COUNT)
	 	   buffer_count = VIDEO_DEC_MAX_BUFFER_COUNT;
        g_video_dec_buffer_mgr_ptr->sequnce_no = 0xffffffff;
        g_video_dec_buffer_mgr_ptr->init_buffer_pkts = 0;
        g_video_dec_buffer_mgr_ptr->p_rtp_driver = video_rtp_get_driver();
        if(g_video_dec_buffer_mgr_ptr->p_rtp_driver == NULL)
        {
            ASSERT(0);
        }
    #else
        ASSERT(0);
    #endif
    }
    else
    {
        /* Not support */
        EXT_ASSERT(0, (kal_uint32)cb_info.scenario, 0, 0);
    }
    buffer_addr = (kal_uint8 *)extmem_get_buffer(buffer_size);
    if ((buffer_count > VIDEO_DEC_MAX_BUFFER_COUNT) || (buffer_addr == NULL))
            EXT_ASSERT(0, buffer_count, (kal_uint32)buffer_addr, (kal_uint32)cb_info.scenario);

    /* Init mutex */
    if (g_video_dec_buffer_mutex == 0)
        g_video_dec_buffer_mutex = kal_create_mutex("VIDEO_DEC_BUFFER_MUTEX");

    kal_take_mutex(g_video_dec_buffer_mutex);

    /* Init parameters */	
#if defined(STREAM_SUPPORT)|| defined(PGDL_SUPPORT)
    if ((cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_STREAM)||(cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE)) {
        g_video_dec_buffer_mgr_ptr->b_send_ilm = KAL_TRUE;
        g_video_dec_buffer_mgr_ptr->b_first_data = KAL_TRUE;	
    } else 
#endif    
    {
        g_video_dec_buffer_mgr_ptr->send_ilm = KAL_TRUE;
        g_video_dec_buffer_mgr_ptr->b_data_empty = KAL_FALSE;
    }
    g_video_dec_buffer_mgr_ptr->cb_info.scenario = cb_info.scenario;
    g_video_dec_buffer_mgr_ptr->cb_info.callback = cb_info.callback;
    g_video_dec_buffer_mgr_ptr->cb_info.event_id = cb_info.event_id;
    g_video_dec_buffer_mgr_ptr->buffer_count = buffer_count;
    g_video_dec_buffer_mgr_ptr->buffer_start_addr = buffer_addr;
    current_buffer_addr = buffer_addr;
    buffer_addr_offset = buffer_size / buffer_count;

    for (index = 0; index < g_video_dec_buffer_mgr_ptr->buffer_count; index++)
    {
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index] = (VIDEO_DEC_BUFFER_STRUCT*)extmem_get_buffer(sizeof(VIDEO_DEC_BUFFER_STRUCT));
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->buffer = current_buffer_addr;
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->buffer_length = buffer_addr_offset;
        current_buffer_addr += buffer_addr_offset;
    }

    if(g_video_dec_buffer_mgr_ptr->buffer_count < VIDEO_DEC_MAX_BUFFER_COUNT)
    {
        for (index = g_video_dec_buffer_mgr_ptr->buffer_count; index < VIDEO_DEC_MAX_BUFFER_COUNT; index++)
        {
            g_video_dec_buffer_mgr_ptr->p_dec_buffer[index] = NULL;
        }
    }
    
    kal_give_mutex(g_video_dec_buffer_mutex);
}


/* Cancel the current put buffer action. If driver decides to stop, but task is still get data from file system to buffer.
*   It can stop put buffer as quickly as possible
* @param None
* @return None
*/
void video_dec_cancel_put_buffer(void)
{
    	g_video_dec_buffer_mgr_ptr->cancel_put_buffer = KAL_TRUE;
}


/* Clear all the buffers. Only clear the control parameter is enough.
*   It should be executed in task level.
* @param start_frame_no. the start frame that shuld be prepared
* @param end_frame_no. the end frame that shuld be prepared 
* @return None
*/
void video_dec_clr_buffer(kal_uint32 start_frame_no, kal_uint32 end_frame_no)
{
    kal_uint32 index;
    MEDIA_STATUS_CODE result;

    if (kal_if_hisr() == KAL_TRUE)
        EXT_ASSERT(0, 0, 0, 0);

#ifdef STREAM_SUPPORT
    if( (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_FILE)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_EDITOR)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_STREAM))
    {
        EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->cb_info.scenario, 0, 0);
    }
 
#else /* STREAM_SUPPORT */
#ifdef PGDL_SUPPORT
    if( (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_FILE)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_EDITOR)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE))
    {
        EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->cb_info.scenario, 0, 0);
    }
#else    
    /* Only support these two scenario */
    if( (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_FILE)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_EDITOR))
    {
        EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->cb_info.scenario, 0, 0);
    }
#endif    
#endif /* STREAM_SUPPORT */    

    /* set cancel buffer as true first, so that if another task is putting frame to buffer at the same time and task the mutex, 
        it will stop put frame and give mutex */
    g_video_dec_buffer_mgr_ptr->cancel_put_buffer = KAL_TRUE;

    kal_take_mutex(g_video_dec_buffer_mutex);

    /* should call config first */
    if (g_video_dec_buffer_mgr_ptr->buffer_count == 0)
        EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->buffer_count, 0, 0);

    /* control parameter */
    g_video_dec_buffer_mgr_ptr->start_frame_no = start_frame_no;
    g_video_dec_buffer_mgr_ptr->end_frame_no = end_frame_no;

    g_video_dec_buffer_mgr_ptr->b_data_empty = KAL_FALSE;
    g_video_dec_buffer_mgr_ptr->write_buffer_id = 0;
    g_video_dec_buffer_mgr_ptr->read_buffer_id = 0;
    g_video_dec_buffer_mgr_ptr->cancel_put_buffer = KAL_FALSE;
#if defined(STREAM_SUPPORT) || defined(PGDL_SUPPORT)
    g_video_dec_buffer_mgr_ptr->b_first_data = KAL_TRUE;
    g_video_dec_buffer_mgr_ptr->total_frame_no = 0;
    g_video_dec_buffer_mgr_ptr->packet_in_frame_count = 0;
    g_video_dec_buffer_mgr_ptr->rtp_header_size = 0;
    g_video_dec_buffer_mgr_ptr->b_switch_copy_packet = KAL_FALSE;
    g_video_dec_buffer_mgr_ptr->n_prev_frame_time = 0;
    g_video_dec_buffer_mgr_ptr->sequnce_no = 0xffffffff;
    g_video_dec_buffer_mgr_ptr->init_buffer_pkts = 0;    
#endif    

    /* each buffer parameter */
    for (index = 0; index < g_video_dec_buffer_mgr_ptr->buffer_count; index++)
    {
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->total_frames_in_buffers = 0;
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->frame_read_index = 0;
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->frame_write_index = 0;
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->frame_start_id = 0;
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->prev_duration = 0;
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->is_write_done = KAL_FALSE;
#if defined(STREAM_SUPPORT) || defined(PGDL_SUPPORT)		
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->is_read_done = KAL_FALSE;
#endif
        g_video_dec_buffer_mgr_ptr->p_dec_buffer[index]->size_usage = 0;
    }

#if defined(STREAM_SUPPORT)
    if(g_video_dec_buffer_mgr_ptr->cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_STREAM)	
    {
        g_video_dec_buffer_mgr_ptr->b_got_end_frame_duration = KAL_FALSE;		   
    }
    else
#endif 	
    {
        g_video_dec_buffer_mgr_ptr->b_got_end_frame_duration = KAL_TRUE;
        //result = video_file_get_frametime(g_video_dec_buffer_mgr_ptr->end_frame_no, 1, &g_video_dec_buffer_mgr_ptr->end_frame_duration);
        result = video_file_get_frametime(g_video_dec_info_ptr->total_frames_in_file-1, 1, &g_video_dec_buffer_mgr_ptr->end_frame_duration);        
        if (result != MEDIA_STATUS_OK)
        {
            g_video_dec_buffer_mgr_ptr->b_got_end_frame_duration = KAL_FALSE;
            VIDEO_ASSERT(0);
        }
    }     

    kal_give_mutex(g_video_dec_buffer_mutex);
}


/* get end frame duration, and this function is called in ISR.
 * @param  prev_frame_duration the duration of the previous frame(unit: auido interrupt count)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_get_end_frame_time(kal_uint32 *prev_frame_duration)
{
    *prev_frame_duration = g_video_dec_buffer_mgr_ptr->end_frame_duration;

    if(g_video_dec_buffer_mgr_ptr->b_got_end_frame_duration == KAL_TRUE)
        return MEDIA_STATUS_OK;
    else
        return VIDEO_ERROR;
}


/* get next frame address, and this function is called in ISR.
 * @param  addr frame memory addrsss
 * @param  length frame size(bytes)
 * @param  prev_frame_duration the duration of the previous frame(unit: auido interrupt count)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_get_next_frame(kal_uint8 **addr, kal_uint32 *length, kal_uint32 *prev_frame_duration)
{
    VIDEO_DEC_BUFFER_STRUCT *buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->read_buffer_id];
    
#if defined(STREAM_SUPPORT)|| defined(PGDL_SUPPORT)
    kal_uint16 prev_buffer_id = (g_video_dec_buffer_mgr_ptr->read_buffer_id+ g_video_dec_buffer_mgr_ptr->buffer_count -1) %
                    	                  g_video_dec_buffer_mgr_ptr->buffer_count;
    VIDEO_DEC_BUFFER_STRUCT *prev_buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[prev_buffer_id];

    if ( (g_video_dec_buffer_mgr_ptr->cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE) ||
	   (g_video_dec_buffer_mgr_ptr->cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_STREAM) )
    {
        if(prev_buffer_ptr->is_read_done == KAL_TRUE)
        {
            prev_buffer_ptr->is_write_done = KAL_FALSE;
            prev_buffer_ptr->is_read_done = KAL_FALSE;
            prev_buffer_ptr->total_frames_in_buffers = 0;
            prev_buffer_ptr->frame_read_index = 0;
            prev_buffer_ptr->frame_write_index = 0;
            prev_buffer_ptr->prev_duration = 0;
            prev_buffer_ptr->size_usage = 0;  

            if ((g_video_dec_buffer_mgr_ptr->end_frame_no != g_video_dec_buffer_mgr_ptr->start_frame_no) && (g_video_dec_buffer_mgr_ptr->b_send_ilm == KAL_TRUE))
            {
                /* send ilm to task, in order to prepare data */
                video_dbg_trace(MP4_DEC_HISR_SEND_ILM, video_get_current_time());

                if ((g_video_dec_buffer_mgr_ptr->cb_info.callback!=NULL) && ((*g_video_dec_buffer_mgr_ptr->cb_info.callback) != NULL))
                {
                   if (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_STREAM) {
                    (*g_video_dec_buffer_mgr_ptr->cb_info.callback)(g_video_dec_buffer_mgr_ptr->cb_info.event_id);
                   }
                }

                g_video_dec_buffer_mgr_ptr->b_send_ilm = KAL_FALSE;
            }
        }     

        if (buffer_ptr->frame_read_index == buffer_ptr->frame_write_index)
        {
            if (buffer_ptr->is_write_done == KAL_TRUE)
            {
                /* buffer is read empty */
                buffer_ptr->is_read_done = KAL_TRUE;
                buffer_ptr->buffer_consume_end_time = video_get_duration_ms(buffer_ptr->buffer_consume_start_time);
#if defined(STREAM_SUPPORT)
                video_dbg_trace(STREAM_DEC_BUFFER_CONSUME_INDEX, g_video_dec_buffer_mgr_ptr->read_buffer_id);
                video_dbg_trace(STREAM_DEC_BUFFER_CONSUME_DURATION, buffer_ptr->buffer_consume_end_time);
                if (buffer_ptr->buffer_consume_end_time==0)
					video_dbg_trace(STREAM_DEC_BUFFER_CONSUME_FPS, buffer_ptr->frame_write_index);
				else
	                video_dbg_trace(STREAM_DEC_BUFFER_CONSUME_FPS, (buffer_ptr->frame_write_index*1000)/buffer_ptr->buffer_consume_end_time);
#endif
                g_video_dec_buffer_mgr_ptr->read_buffer_id++;
                g_video_dec_buffer_mgr_ptr->read_buffer_id %= g_video_dec_buffer_mgr_ptr->buffer_count;
                buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->read_buffer_id];
 		        buffer_ptr->buffer_consume_start_time = video_get_current_time();
            }
        /* If already false, it means all buufer empty. Do nothing */
        }
    
        if (buffer_ptr->is_write_done == KAL_FALSE)
        {
            if (buffer_ptr->frame_read_index == buffer_ptr->frame_write_index) {
                /* All buffer are empty */
                /* No frame length information, only provide previous frame time information*/
                *prev_frame_duration = buffer_ptr->prev_duration;
                return VIDEO_ERROR;
            }
        }
    
        /* Error check */
        if ((buffer_ptr->is_write_done == KAL_FALSE) || (g_video_dec_buffer_mgr_ptr->end_frame_no < g_video_dec_buffer_mgr_ptr->start_frame_no))
        {
            if (buffer_ptr->frame_read_index == buffer_ptr->frame_write_index) {
                EXT_ASSERT(0, (kal_uint32)buffer_ptr->is_write_done, (kal_uint32)g_video_dec_buffer_mgr_ptr->end_frame_no,
                    (kal_uint32)g_video_dec_buffer_mgr_ptr->start_frame_no);
            }
        }
    } else 
#endif    
    {
        if(g_video_dec_buffer_mgr_ptr->b_data_empty == KAL_TRUE)
        {
            /* send ilm to task, in order to prepare data */
            video_dbg_trace(MP4_DEC_HISR_SEND_ILM, video_get_current_time());

            if ((*g_video_dec_buffer_mgr_ptr->cb_info.callback) != NULL)
            {
                (*g_video_dec_buffer_mgr_ptr->cb_info.callback)(g_video_dec_buffer_mgr_ptr->cb_info.event_id);
            }

            g_video_dec_buffer_mgr_ptr->b_data_empty = KAL_FALSE;
            g_video_dec_buffer_mgr_ptr->send_ilm = KAL_FALSE;
        }           

        if (buffer_ptr->frame_read_index == buffer_ptr->frame_write_index)
        {
            if (buffer_ptr->is_write_done == KAL_TRUE)
            {
                /* buffer is read empty */
                buffer_ptr->is_write_done = KAL_FALSE;

                if ((g_video_dec_buffer_mgr_ptr->end_frame_no != g_video_dec_buffer_mgr_ptr->start_frame_no) && (g_video_dec_buffer_mgr_ptr->send_ilm == KAL_TRUE))
                {
                    g_video_dec_buffer_mgr_ptr->b_data_empty = KAL_TRUE;
                }

                g_video_dec_buffer_mgr_ptr->read_buffer_id++;
                g_video_dec_buffer_mgr_ptr->read_buffer_id %= g_video_dec_buffer_mgr_ptr->buffer_count;
                buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->read_buffer_id];
            }
        /* If already false, it means all buufer empty. Do nothing */
        }
        else
        {
            if (buffer_ptr->is_write_done != KAL_TRUE)
            {
                ASSERT(0);
            }
        }

        if (buffer_ptr->is_write_done == KAL_FALSE)
        {
            /* All buffer are empty */
            /* No frame length information, only provide previous frame time information*/
            *prev_frame_duration = buffer_ptr->prev_duration;
            return VIDEO_ERROR;
        }

        /* Error check */
        if ((buffer_ptr->is_write_done == KAL_FALSE) || (g_video_dec_buffer_mgr_ptr->end_frame_no < g_video_dec_buffer_mgr_ptr->start_frame_no))
        {
            EXT_ASSERT(0, (kal_uint32)buffer_ptr->is_write_done, (kal_uint32)g_video_dec_buffer_mgr_ptr->end_frame_no,
                          (kal_uint32)g_video_dec_buffer_mgr_ptr->start_frame_no);
        }
    }

    /* Get information*/
    *addr = (kal_uint8 *)buffer_ptr->frame_buffer_addr[buffer_ptr->frame_read_index];
    *length = buffer_ptr->frame_length[buffer_ptr->frame_read_index];
    
#if defined(__VIDEO_EDITOR__)    
    if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
      if (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_START)
         *prev_frame_duration = buffer_ptr->prev_frame_duration[buffer_ptr->frame_read_index+1];
      else
         *prev_frame_duration = buffer_ptr->prev_frame_duration[buffer_ptr->frame_read_index];
    }
    else
#endif   /*__VIDEO_EDITOR__*/
    {
      *prev_frame_duration = buffer_ptr->prev_frame_duration[buffer_ptr->frame_read_index];
    }

    buffer_ptr->prev_duration = buffer_ptr->prev_frame_duration[buffer_ptr->frame_read_index];
    buffer_ptr->frame_read_index++;

    return MEDIA_STATUS_OK;
}


/* Put bitstream data from file to double buffer, and this function should be  called in TASK.
 * @param None
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
static MEDIA_STATUS_CODE video_dec_put_frame_to_buffer_from_file(void)
{
    kal_uint32 total_frames;
    MEDIA_STATUS_CODE result;
    kal_uint32 			Max_Frame_In_Buffer;
    VIDEO_DEC_BUFFER_STRUCT *buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->write_buffer_id];

    if ((buffer_ptr == NULL) || (buffer_ptr->buffer_length == 0))
        EXT_ASSERT(0, (kal_uint32)buffer_ptr, 0, 0);

    /* task is getting data, driver can send ilm again */
#if defined(STREAM_SUPPORT)|| defined(PGDL_SUPPORT)    
    if ( (g_video_dec_buffer_mgr_ptr->cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE) ||
	   (g_video_dec_buffer_mgr_ptr->cb_info.scenario == VIDEO_DEC_BUFFER_SCENARIO_STREAM) )
    {
        g_video_dec_buffer_mgr_ptr->b_send_ilm = KAL_TRUE;
    } else 
#endif
    {	
        g_video_dec_buffer_mgr_ptr->send_ilm = KAL_TRUE;
    }

    while (buffer_ptr->is_write_done == KAL_FALSE)
    {
        if (g_video_dec_buffer_mgr_ptr->cancel_put_buffer == KAL_TRUE)
        {
            /* another task may want to re-start*/
            //g_video_dec_buffer_mgr_ptr->cancel_put_buffer = KAL_FALSE;

            return MEDIA_STATUS_OK;
        }

        /* Check illegal frame conditions */
        if ((g_video_dec_buffer_mgr_ptr->end_frame_no == 0) || (g_video_dec_buffer_mgr_ptr->start_frame_no > g_video_dec_buffer_mgr_ptr->end_frame_no))
        {
            VIDEO_ASSERT(0);
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
               kal_prompt_trace(MOD_MED, "Illegal frame condition: %d, %d\n", g_video_dec_buffer_mgr_ptr->start_frame_no, g_video_dec_buffer_mgr_ptr->end_frame_no);
            }
#endif
            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FUNC_PARAMETER_ERROR;
            return VIDEO_ERROR;
        }

        /* All data are ready */
        if (g_video_dec_buffer_mgr_ptr->start_frame_no == g_video_dec_buffer_mgr_ptr->end_frame_no)
        {
            return MEDIA_STATUS_OK;
        }

        /* Determine total frame number that will be put in  this buffer */
        Max_Frame_In_Buffer = DEC_MAX_FRMAE_IN_BUFFER;
#if defined(__VIDEO_EDITOR__)    
    	   if (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR)
    	   	{
    	   		Max_Frame_In_Buffer--;
    	   	}
#endif
    		
        if ((g_video_dec_buffer_mgr_ptr->start_frame_no + Max_Frame_In_Buffer) <= g_video_dec_buffer_mgr_ptr->end_frame_no)
            total_frames = Max_Frame_In_Buffer;
        else
            total_frames = g_video_dec_buffer_mgr_ptr->end_frame_no - g_video_dec_buffer_mgr_ptr->start_frame_no;

        if (total_frames == 0)
        {
            VIDEO_ASSERT(0);

            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FUNC_PARAMETER_ERROR;
            return VIDEO_ERROR;
        }

        buffer_ptr->frame_start_id = g_video_dec_buffer_mgr_ptr->start_frame_no;

#if defined(__VIDEO_EDITOR__)    
    		if ( (g_video_dec_status.scenario == VIDEO_SCENARIO_EDITOR) && (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_START)  )
    		{
    			   if (buffer_ptr->frame_start_id == 0)
		        {
		            /* frame 0 dose not have previous frame duration */
		            result = video_file_get_frametime(buffer_ptr->frame_start_id, total_frames, &buffer_ptr->prev_frame_duration[1]);
		        }
		        else
		        {
		            result = video_file_get_frametime(buffer_ptr->frame_start_id - 1, (total_frames+1), &buffer_ptr->prev_frame_duration[0]);
		        }	
    		}
    		else
#endif	/*__VIDEO_EDITOR__*/
		{
	        /* Get previous frame duration */
	        if (buffer_ptr->frame_start_id == 0)
	        {
	            /* frame 0 dose not have previous frame duration */
	            result = video_file_get_frametime(buffer_ptr->frame_start_id, (total_frames - 1), &buffer_ptr->prev_frame_duration[1]);
	        }
	        else
	        {
	            result = video_file_get_frametime(buffer_ptr->frame_start_id - 1, total_frames, &buffer_ptr->prev_frame_duration[0]);
	        }	
		}

        if (result != MEDIA_STATUS_OK)
        {
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
               kal_prompt_trace(MOD_MED, "video_file_get_frametime: %d, %d\n", buffer_ptr->frame_start_id, total_frames);
            }
#endif
            VIDEO_ASSERT(0);

            return result;
        }

        /* Get frame length and bitstream from file */
        
        buffer_ptr->file_read_info.result_frame_no = 0;
        buffer_ptr->file_read_info.start_frame_no = buffer_ptr->frame_start_id;
        buffer_ptr->file_read_info.total_frame_no = total_frames;
        buffer_ptr->file_read_info.max_size = buffer_ptr->buffer_length;
        buffer_ptr->frame_buffer_addr[0] = (kal_uint32)buffer_ptr->buffer;
        buffer_ptr->file_read_info.p_frame_buffer_addr = buffer_ptr->frame_buffer_addr;
        buffer_ptr->file_read_info.p_frame_length = buffer_ptr->frame_length;
        result = video_file_get_sample_data(&buffer_ptr->file_read_info);
        if (result != MEDIA_STATUS_OK)
        {
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
               kal_prompt_trace(MOD_MED, "video_file_get_sample_data: %d\n", result);
            }
#endif        
            VIDEO_ASSERT(0);
            return result;
        }

        /* update buffer parameter */
        buffer_ptr->total_frames_in_buffers = buffer_ptr->file_read_info.result_frame_no;
        buffer_ptr->frame_write_index = buffer_ptr->file_read_info.result_frame_no;
        g_video_dec_buffer_mgr_ptr->start_frame_no += buffer_ptr->file_read_info.result_frame_no;
        buffer_ptr->frame_read_index = 0;
        buffer_ptr->prev_duration = 0;
        buffer_ptr->size_usage = buffer_ptr->file_read_info.result_size;     

        if (g_video_dec_buffer_mgr_ptr->start_frame_no > g_video_dec_buffer_mgr_ptr->end_frame_no)
            EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->start_frame_no, (kal_uint32)g_video_dec_buffer_mgr_ptr->end_frame_no, 0);

        if(buffer_ptr->total_frames_in_buffers > 0)
        {
            /* get next buffer */
            buffer_ptr->is_write_done = KAL_TRUE;
            g_video_dec_buffer_mgr_ptr->write_buffer_id++;
            g_video_dec_buffer_mgr_ptr->write_buffer_id %= g_video_dec_buffer_mgr_ptr->buffer_count;
            buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->write_buffer_id];
        }
        else
        {
            break;	
        }

        /* berak if all data are available */
        if (g_video_dec_buffer_mgr_ptr->start_frame_no == g_video_dec_buffer_mgr_ptr->end_frame_no)
            break;
    }

    return MEDIA_STATUS_OK;
}

#if (defined(STREAM_SUPPORT) || defined(PGDL_SUPPORT)) && defined(__STREAM_TRACE_ON__)
kal_int32 video_dec_show_buffer_trace(kal_int32 mode)
{
	 extern VIDEO_DEC_AV_TYPE video_dec_get_av_type(void);
	 extern kal_uint64 video_dec_get_audio_timebase(void);
	 
	 VIDEO_DEC_BUFFER_STRUCT *buffer_ptr1;
	 kal_uint32 bsize=0, duration=0, percentage, i, j, framecnt=0, temp_framecnt, temp_dur, temp_size;

	 if (mode)
	 	kal_prompt_trace(MOD_MED_V, "[VIDEO_PDL_BUFFER] (#Buffers:%d, read_id:%d, write_id:%d)\n", g_video_dec_buffer_mgr_ptr->buffer_count, g_video_dec_buffer_mgr_ptr->read_buffer_id, g_video_dec_buffer_mgr_ptr->write_buffer_id);
	 else
              STREAM_INFO_LOG4(VIDEO_STREAM_DECODE_BUFFER_STATUS3, g_video_dec_buffer_mgr_ptr->buffer_count, g_video_dec_buffer_mgr_ptr->read_buffer_id, g_video_dec_buffer_mgr_ptr->write_buffer_id);
	 for (i=g_video_dec_buffer_mgr_ptr->read_buffer_id;;i++) {
	 	 i %= g_video_dec_buffer_mgr_ptr->buffer_count;
		 buffer_ptr1 = g_video_dec_buffer_mgr_ptr->p_dec_buffer[i];
		 if (buffer_ptr1->frame_write_index > buffer_ptr1->frame_read_index) {
		 	 temp_framecnt = buffer_ptr1->frame_write_index - buffer_ptr1->frame_read_index;
			 framecnt += temp_framecnt;
			 temp_dur = 0;
			 for (j=buffer_ptr1->frame_read_index; j<=buffer_ptr1->frame_write_index-1; j++) {
			 	 temp_dur += buffer_ptr1->prev_frame_duration[j];				 
			 }
			 temp_size = buffer_ptr1->size_usage;
			 if (buffer_ptr1->frame_read_index != 0) {			 
				 for (j=0; j<buffer_ptr1->frame_read_index; j++)
					 temp_size -= buffer_ptr1->frame_length[j];
			 }
			 if (mode)
			 	kal_prompt_trace(MOD_MED_V, "[VIDEO_PDL_BUFFER] Decode Buffer Entry Status: index (%d), first frame# (%d), frames_to_decode (%d), duration_to_decode (%d ms), used_percentage (%d)\n", i, buffer_ptr1->frame_start_id, temp_framecnt, VIDEO_ANYBASE_TO_MS(temp_dur*1024, video_dec_get_audio_timebase()), (temp_size*100)/buffer_ptr1->buffer_length);
			 else
			 	STREAM_INFO_LOG6(VIDEO_STREAM_DECODE_BUFFER_STATUS, i, buffer_ptr1->frame_start_id, temp_framecnt, VIDEO_ANYBASE_TO_MS(temp_dur*1024, video_dec_get_audio_timebase()), (temp_size*100)/buffer_ptr1->buffer_length);
			 bsize += temp_size;
			 duration += temp_dur;
		 }
		 if (i==g_video_dec_buffer_mgr_ptr->write_buffer_id)
		 	break;
	 }
	 if (video_dec_get_av_type() == VIDEO_DEC_AV_AUDIO)
	 {
		 duration = VIDEO_ANYBASE_TO_MS(duration*1024, video_dec_get_audio_timebase());
	 }
	 else
	 {
		 EXT_ASSERT(0, video_dec_get_av_type(), 0, 0);
	 }
	 percentage = (100*bsize)/(VIDEO_DEC_BUFFER_SIZE*VIDEO_DEC_BUFFER_COUNT);

	 if ((bsize > 0) && (percentage==0))
	 	percentage = 1;

	if (mode) 
		kal_prompt_trace(MOD_MED_V, "[VIDEO_PDL_BUFFER] Decode Buffer Status: frames_to_decode (%d), duration_to_decode (%d ms), used_percentage (%d)\n", framecnt, duration, percentage);
	else
		STREAM_INFO_LOG4(VIDEO_STREAM_DECODE_BUFFER_STATUS2, framecnt, duration, percentage);
	return framecnt;
}
#endif


/* Put bitstream data from file to double buffer, and this function should be  called in TASK.
 * @param None
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_dec_put_frame_to_buffer(void)
{
    MEDIA_STATUS_CODE result;
 #ifdef PGDL_SUPPORT    
    kal_bool b_get_data = KAL_FALSE;
#endif

    if (kal_if_hisr() == KAL_TRUE)
        EXT_ASSERT(0, 0, 0, 0);

 #ifdef PGDL_SUPPORT
    if( (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_FILE)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_EDITOR)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE))
    {
        EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->cb_info.scenario, 0, 0);
    }
 #else
    /* Only support these two scenario */
    if( (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_FILE)
    	&& (g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_EDITOR))
    {
        EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->cb_info.scenario, 0, 0);
    }
#endif

    kal_take_mutex(g_video_dec_buffer_mutex);
    video_dbg_trace(MP4_DEC_TASK_IND_START, video_get_current_time());

    result = video_dec_put_frame_to_buffer_from_file();

#ifdef PGDL_SUPPORT
    if(result==MEDIA_STATUS_OK)
    {
        if((g_video_dec_buffer_mgr_ptr->b_first_data == KAL_TRUE) && 
           (g_video_dec_buffer_mgr_ptr->cb_info.scenario==VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE))
        {
            b_get_data = KAL_TRUE;
            if(g_video_dec_buffer_mgr_ptr->read_buffer_id != 0)
            {
                /* It should be in initial state, so read id should be zero */
                EXT_ASSERT(0, g_video_dec_buffer_mgr_ptr->read_buffer_id, g_video_dec_buffer_mgr_ptr->write_buffer_id, 
                                    g_video_dec_buffer_mgr_ptr->b_first_data);
            }
            g_video_dec_buffer_mgr_ptr->p_dec_buffer[0]->is_write_done = KAL_TRUE;
#ifdef __STREAM_TRACE_ON__
            video_dec_show_buffer_trace(1);	// 1 for PDL
#endif


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#endif 
        }/* g_video_dec_buffer_mgr_ptr->b_first_data == KAL_TRUE */
    } /* result==MEDIA_STATUS_OK */
    else {
        if (g_video_dec_buffer_mgr_ptr->cb_info.scenario==VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE)
        {
            VIDEO_DEC_BUFFER_STRUCT *buffer = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->read_buffer_id];
            kal_uint8 total_frames = buffer->frame_write_index - buffer->frame_read_index; 
			
            // If total_frames > 0 (means that at least 1 frame is loaded into decode buffer), return OK to MED. Then MED can start video playing. 
            if (buffer->frame_write_index < buffer->frame_read_index) {
               total_frames = DEC_MAX_FRMAE_IN_BUFFER - buffer->frame_read_index;
            } else if (buffer->frame_read_index < buffer->frame_write_index) {
               total_frames = buffer->frame_write_index - buffer->frame_read_index;
            } else {
               total_frames = 0;
            }

            if (g_video_dec_status.FSAL_STATUS == FSAL_READ_OVER_EOF)
            {
                if (total_frames == 0)
                {
                    result = FSAL_READ_EOF;
                    video_dbg_trace(PDL_FSAL_READ_EOF, video_get_current_time());
                }
                else
                {
                    if (g_video_dec_buffer_mgr_ptr->b_first_data == KAL_TRUE)
                        b_get_data = KAL_TRUE;
                
                    result = MEDIA_STATUS_OK;
                }
            }
            else if (g_video_dec_status.FSAL_STATUS == FSAL_SEEK_OVER_EOF)
            {
                if (total_frames == 0)
                {
                    result = FSAL_SEEK_EOF;
                    video_dbg_trace(PDL_FSAL_SEEK_EOF, video_get_current_time());
                }
                else
                {
                    if (g_video_dec_buffer_mgr_ptr->b_first_data == KAL_TRUE)
                        b_get_data = KAL_TRUE;
                
                    result = MEDIA_STATUS_OK;
                }
            }
	        if (result == MEDIA_STATUS_OK) 
	        {
#ifdef __STREAM_TRACE_ON__	     
                video_dec_show_buffer_trace(1);	// 1 for PDL
#endif		 	
                video_dbg_trace(PDL_PUT_FRAME_TO_BUFFER_OK, video_get_current_time());
	        } else {
                kal_prompt_trace(MOD_MED, "[VIDEO_PDL_BUFFER_ERR] MED_status=%d, FSAL_status=%d\n", result, g_video_dec_status.FSAL_STATUS);
	        }
        }
    }

     if(b_get_data==KAL_TRUE)
    {
        /* get data of this buffer, all the later are not the first data */
        g_video_dec_buffer_mgr_ptr->b_first_data = KAL_FALSE;
    } 
#endif

    video_dbg_trace(MP4_DEC_TASK_IND_END, video_get_current_time());
    kal_give_mutex(g_video_dec_buffer_mutex);
    
    return result;
}

#ifdef STREAM_SUPPORT
MEDIA_STATUS_CODE video_dec_stream_put_pkt_to_buffer_loop(kal_uint8* p_next_data, kal_uint32 next_size);
extern VIDEO_RTP_REORDER_BUFF_INFO g_video_rtp_reorder_buff_info;

/* check current input rtp packet sequence. Input one received packet, and return really in-order packet */
/* If current packet is out of sequence, queue to re-order buffer and try to return packet from re-order buffer */
/* param data: input packet start addr, size: input packet size, *p_size: output packet size*/
/* retrun value : output packet start addr */
/* If return value is NULL, it means no packet needs to be processed at current time */
static kal_uint8* video_dec_stream_check_sequence_pkt(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_size)
{
    kal_uint32 n_sequence;
    kal_uint8 *p_next_data = NULL;
    kal_uint32 next_size;
    kal_uint32 next_sequence;

    /* input data sequece */
    n_sequence = (data[2]<<8) + data[3];
    /* check whether the rtp packet sequnce is in right order*/
    if(g_video_dec_buffer_mgr_ptr->sequnce_no != 0xffffffff)
    {
        /* not the first packet */
        if(((n_sequence - g_video_dec_buffer_mgr_ptr->sequnce_no)==1) ||
            ((g_video_dec_buffer_mgr_ptr->sequnce_no==0xffff) && (n_sequence==0)))
        {
#ifdef STREAM_REORDER_BUFFER_DBG_TRACE
            video_dbg_trace(STREAM_REORDER_BUFFER_IN_SEQ, n_sequence);
#endif
#ifdef __STREAM_TRACE_ON__			
            STREAM_INFO_LOG3(VIDEO_STREAM_PUTPACKET_STATUS_1, n_sequence, g_video_dec_buffer_mgr_ptr->sequnce_no);
#endif
            /* in sequence order */
            g_video_dec_buffer_mgr_ptr->sequnce_no = n_sequence;
            *p_size = size;	     
            return data;
        }
        else
        {
            /* not in sequnce order */
            //VIDEO_ASSERT(0);
            if( (n_sequence<=g_video_dec_buffer_mgr_ptr->sequnce_no) ||
                ((n_sequence>g_video_dec_buffer_mgr_ptr->sequnce_no) && ((n_sequence-g_video_dec_buffer_mgr_ptr->sequnce_no) > 0xf000))	)
            {
#ifdef STREAM_REORDER_BUFFER_DBG_TRACE            
            	    video_dbg_trace(STREAM_REORDER_BUFFER_DROP_SEQ, n_sequence);
#endif
#ifdef __STREAM_TRACE_ON__					
            	    STREAM_INFO_LOG3(VIDEO_STREAM_PUTPACKET_STATUS_2, n_sequence, g_video_dec_buffer_mgr_ptr->sequnce_no);
#endif
            	    /* receive the packet that older than already decode frame, drop it */
            	    *p_size = 0;
            	    return NULL;
            }
            else
            {
#ifdef STREAM_REORDER_BUFFER_DBG_TRACE
            	  video_dbg_trace(STREAM_REORDER_BUFFER_OUT_SEQ, n_sequence);
#endif
#ifdef __STREAM_TRACE_ON__				  
            	  STREAM_INFO_LOG3(VIDEO_STREAM_PUTPACKET_STATUS_3, n_sequence, g_video_dec_buffer_mgr_ptr->sequnce_no);
#endif
            	  /* queue to out of sequence buffer */
            	  {            	      
            	      if (g_video_rtp_reorder_buff_info.total_pkt == VIDEO_RTP_MAX_REORDER_NUM) {	/* Trick to add the packet if g_video_rtp_reorder_buff_info.total_pkt == VIDEO_RTP_MAX_REORDER_NUM*/
            	          g_video_rtp_reorder_buff_info.b_buffer_full = KAL_TRUE;
            	          p_next_data = video_rtp_reorder_get_pkt(0, &next_size, &next_sequence);
            	          g_video_rtp_reorder_buff_info.b_buffer_full = KAL_FALSE;			   
			   			  if(p_next_data!=NULL) {
			   	  			MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;
	   				        g_video_dec_buffer_mgr_ptr->sequnce_no = next_sequence;
			   				result = video_dec_stream_put_pkt_to_buffer_loop(p_next_data, next_size);
				  			if (result != MEDIA_STATUS_OK) {
				  				VIDEO_ASSERT(0);
				  			}
						      p_next_data = NULL;
			   			  }
            	      }
            	  }
		          video_rtp_reorder_put_pkt(data, size, n_sequence);
		  		  {
		  		     if (g_video_rtp_reorder_buff_info.b_buffer_full == KAL_TRUE) {
		  		        p_next_data = video_rtp_reorder_get_pkt(0, &next_size, &next_sequence);
		  		        if(p_next_data!=NULL) {
			   	  		   MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;
		  		           g_video_dec_buffer_mgr_ptr->sequnce_no = next_sequence;
		              	   result = video_dec_stream_put_pkt_to_buffer_loop(p_next_data, next_size);
		              	   if (result != MEDIA_STATUS_OK) {
		              		   VIDEO_ASSERT(0);
		              	   }
		  		           p_next_data = NULL;
		  		        }
	  		            video_rtp_reorder_put_pkt(data, size, n_sequence);
  		             }
                  }

#ifdef __STREAM_TRACE_ON__
            	  {            	      
            	      kal_uint32 bsize=0, index;
            	      for (index=0; index<g_video_rtp_reorder_buff_info.total_pkt; index++) {
            	          STREAM_INFO_LOG4(VIDEO_STREAM_PUTPACKET_STATUS2, index, g_video_rtp_reorder_buff_info.sequence[index], g_video_rtp_reorder_buff_info.buffer_size[index]);
            	          bsize += g_video_rtp_reorder_buff_info.buffer_size[index];
            	      }
            	      STREAM_INFO_LOG5(VIDEO_STREAM_REORDER_BUFFER_STATUS, g_video_dec_buffer_mgr_ptr->sequnce_no, g_video_rtp_reorder_buff_info.total_pkt, VIDEO_RTP_REORDER_BUFFER_SIZE, bsize);
            	  }
#endif

                /* try to get from out of sequence buffer and parse it */
                if (p_next_data == NULL) {
                	if ( (g_video_rtp_reorder_buff_info.total_pkt>0)&&(g_video_rtp_reorder_buff_info.total_pkt<=VIDEO_RTP_MAX_REORDER_NUM) ) {
	                if(g_video_dec_buffer_mgr_ptr->sequnce_no!=0xffff)
       	                p_next_data = video_rtp_reorder_get_pkt((g_video_dec_buffer_mgr_ptr->sequnce_no+1), &next_size, &next_sequence);
	                else
	                    p_next_data = video_rtp_reorder_get_pkt(0, &next_size, &next_sequence);	
                	} else 
                		VIDEO_ASSERT(0);	// no adm buffer anymore?
                }
                if(p_next_data!=NULL)
                {
                    g_video_dec_buffer_mgr_ptr->sequnce_no = next_sequence;
                    *p_size = next_size;
                    return p_next_data;
                }
                else
                {
                    *p_size = 0;
                    return NULL;
                }
            }
        }
    }
    else
    {
        //if (g_video_dec_buffer_mgr_ptr->init_buffer_pkts>=(VIDEO_RTP_MAX_REORDER_NUM/2)) {
        if ( ((g_video_rtp_reorder_buff_info.b_buffer_full==KAL_TRUE)||(g_video_dec_buffer_mgr_ptr->init_buffer_pkts>=(VIDEO_RTP_MAX_REORDER_NUM/2)))
			&&(g_video_rtp_reorder_buff_info.b_init_done==KAL_TRUE) ) {
#ifdef STREAM_REORDER_BUFFER_DBG_TRACE
	     video_dbg_trace(STREAM_REORDER_BUFFER_FIRST_SEQS, n_sequence);
#endif
#ifdef __STREAM_TRACE_ON__		 
	     STREAM_INFO_LOG3(VIDEO_STREAM_PUTPACKET_STATUS_4, n_sequence, g_video_dec_buffer_mgr_ptr->sequnce_no);
#endif
	     video_rtp_reorder_put_pkt(data, size, n_sequence);
#ifdef __STREAM_TRACE_ON__
	     {	         
	         kal_uint32 bsize=0, index;
	         for (index=0; index<g_video_rtp_reorder_buff_info.total_pkt; index++) {
	             STREAM_INFO_LOG4(VIDEO_STREAM_PUTPACKET_STATUS2, index, g_video_rtp_reorder_buff_info.sequence[index], g_video_rtp_reorder_buff_info.buffer_size[index]);
	             bsize += g_video_rtp_reorder_buff_info.buffer_size[index];
	         }
	         STREAM_INFO_LOG5(VIDEO_STREAM_REORDER_BUFFER_STATUS, g_video_dec_buffer_mgr_ptr->sequnce_no, g_video_rtp_reorder_buff_info.total_pkt, VIDEO_RTP_REORDER_BUFFER_SIZE, bsize);
	     }
#endif

            p_next_data = video_rtp_reorder_get_pkt(0xffffffff, &next_size, &next_sequence);
            if(p_next_data!=NULL)
            {
                g_video_dec_buffer_mgr_ptr->sequnce_no = next_sequence;
                *p_size = next_size;
                return p_next_data;
            }
            else
            {
                *p_size = 0;
                return NULL;
            }
        } else {
#ifdef STREAM_REORDER_BUFFER_DBG_TRACE
            video_dbg_trace(STREAM_REORDER_BUFFER_FIRST_SEQS, n_sequence);
#endif
#ifdef __STREAM_TRACE_ON__			
            STREAM_INFO_LOG3(VIDEO_STREAM_PUTPACKET_STATUS_5, n_sequence, g_video_dec_buffer_mgr_ptr->sequnce_no);
#endif
            video_rtp_reorder_put_pkt(data, size, n_sequence);
#ifdef __STREAM_TRACE_ON__
            {                
                kal_uint32 bsize=0, index;
                for (index=0; index<g_video_rtp_reorder_buff_info.total_pkt; index++) {
                    STREAM_INFO_LOG4(VIDEO_STREAM_PUTPACKET_STATUS2, index, g_video_rtp_reorder_buff_info.sequence[index], g_video_rtp_reorder_buff_info.buffer_size[index]);
                    bsize += g_video_rtp_reorder_buff_info.buffer_size[index];
                }
                STREAM_INFO_LOG5(VIDEO_STREAM_REORDER_BUFFER_STATUS, g_video_dec_buffer_mgr_ptr->sequnce_no, g_video_rtp_reorder_buff_info.total_pkt, VIDEO_RTP_REORDER_BUFFER_SIZE, bsize);
            }
#endif
            g_video_dec_buffer_mgr_ptr->init_buffer_pkts++;
            *p_size = 0;
            return NULL;
        }
     }
}

kal_uint64 video_dec_stream_get_first_frame_duration(void)
{
	return g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->read_buffer_id]->prev_duration;
}

/* return the packet in re-order buffer, *p_size is the packet size  */
/* If return value is NULL, it means no packet needs to be processed at current time */
static kal_uint8* video_dec_stream_get_sequence_pkt(kal_uint32 *p_size)
{
    kal_uint8 *p_next_data = NULL;
    kal_uint32 next_size;
    kal_uint32 next_sequence;

    /* check whether any rtp packet sequnce is in right order*/
    if(g_video_dec_buffer_mgr_ptr->sequnce_no!= 0xffffffff)
    {
        /* try to get from out of sequence buffer and parse it */
        if(g_video_dec_buffer_mgr_ptr->sequnce_no != 0xffff)		
            p_next_data = video_rtp_reorder_get_pkt((g_video_dec_buffer_mgr_ptr->sequnce_no+1), &next_size, &next_sequence);
        else
            p_next_data = video_rtp_reorder_get_pkt(0, &next_size, &next_sequence);	
        if(p_next_data!=NULL)
        {
            g_video_dec_buffer_mgr_ptr->sequnce_no = next_sequence;
            *p_size = next_size;
            return p_next_data;
        }
        else
        {
            *p_size = 0;
            return NULL;
        }
    }
    else
    {
        /* no paclets*/
        *p_size = 0;
        return NULL;
    }
}

/* Put the config data (only mp4 VOS that received by RTSP but not RTP packet uses this)*/
MEDIA_STATUS_CODE video_dec_stream_put_config_to_buffer(kal_uint8* p_data, kal_uint32 size)
{
    MEDIA_STATUS_CODE result= MEDIA_STATUS_OK; 
    	
    if (kal_if_hisr() == KAL_TRUE)
        EXT_ASSERT(0, 0, 0, 0);

    if( g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_STREAM )
    {
        EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->cb_info.scenario, 0, 0);
    }

    kal_take_mutex(g_video_dec_buffer_mutex);
    video_dbg_trace(MP4_DEC_TASK_IND_START, video_get_current_time());

#ifdef __VIDEO_STREAM_STORE_BUFFER__
    video_dec_open_stream_file();
    video_dec_store_stream_buffer_file(p_data, size);
    video_dec_close_stream_file();
#endif

    result = g_video_dec_buffer_mgr_ptr->p_rtp_driver->parse_config(p_data, size);
    if(result == MEDIA_STATUS_OK)
    {
        //g_video_dec_buffer_mgr_ptr->b_first_data = KAL_FALSE;
    }

    video_dbg_trace(MP4_DEC_TASK_IND_END, video_get_current_time());
    kal_give_mutex(g_video_dec_buffer_mutex);
    return result;
}

MEDIA_STATUS_CODE video_dec_stream_put_pkt_to_buffer(kal_uint8* p_parse_data, kal_uint32 parse_size)
{
	MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;
	kal_uint32 index, pind;
	kal_uint32 *n_prev_frame_time = &(g_video_dec_buffer_mgr_ptr->n_prev_frame_time);
	VIDEO_DEC_BUFFER_STRUCT *buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->write_buffer_id];

		/* parse rtp packets  */
		result = g_video_dec_buffer_mgr_ptr->p_rtp_driver->parse_time_size(p_parse_data, parse_size, &g_video_rtp_info);
		for (pind=0; pind < VIDEO_RTP_MAX_PARSE_ITEM; pind++) {
			if (g_video_rtp_info.buffer_size[pind] > VIDEO_DEC_STREAM_BUFFER_SIZE)
				g_video_rtp_info.buffer_size[pind] = VIDEO_DEC_STREAM_BUFFER_SIZE*3/4;			
		}
						
		if(result != MEDIA_STATUS_OK)
		{
#ifdef __VIDEO_STREAM_STORE_BUFFER__
			 video_dec_unstore_stream_buffer_file(parse_size);
#endif               
			 VIDEO_ASSERT(0);
			 //video_dbg_trace(MP4_DEC_TASK_IND_END, video_get_current_time());
			 //kal_give_mutex(g_video_dec_buffer_mutex);
			 kal_prompt_trace(MOD_MED, "VIDEO_RTP_PUT_PKT_TO_BUF_PARSE_TIME_SIZE_ERR: (result:%d)\n", result);
			 return result;
		}
		
		/* copy rtp packet to buffer and time/length information */
		index = 0;
		while((index < VIDEO_RTP_MAX_PARSE_ITEM) && (g_video_rtp_info.buffer_size[index] > 0))
		{
			 /* error check */
			 //if ((buffer_ptr->is_write_done == KAL_TRUE) || (buffer_ptr->is_read_done==KAL_TRUE))
			 if (buffer_ptr->is_write_done == KAL_TRUE)
			 {
				  /* no avilable buffer */
				  VIDEO_ASSERT(0);
#ifdef __VIDEO_STREAM_STORE_BUFFER__
				  video_dec_unstore_stream_buffer_file(parse_size);
#endif               
				  //(*g_video_dec_buffer_mgr_ptr->cb_info.callback)(VIDEO_RTP_EVENT_OVERFLOW);
				  g_video_dec_info_ptr->is_stream_overflow = KAL_TRUE;
				  //video_dbg_trace(MP4_DEC_TASK_IND_END, video_get_current_time());
				  //kal_give_mutex(g_video_dec_buffer_mutex);
				  kal_prompt_trace(MOD_MED, "VIDEO_RTP_PUT_PKT_TO_BUF_WRITE_DONE_ERR1_OVERFLOW\n");
				  return VIDEO_ERROR;
			 }
			 /* check which buffer shoud be copied to */
			 if((buffer_ptr->buffer_length - buffer_ptr->size_usage) < g_video_rtp_info.buffer_size[index])
			 {
				  /* size in current buffer is not enough, switch to next buffer */
				  buffer_ptr->is_write_done = KAL_TRUE;
				  buffer_ptr->buffer_fill_end_time = video_get_duration_ms(buffer_ptr->buffer_fill_start_time);
				  video_dbg_trace(STREAM_DEC_BUFFER_FILL_INDEX, g_video_dec_buffer_mgr_ptr->write_buffer_id);
				  video_dbg_trace(STREAM_DEC_BUFFER_FILL_DURATION, buffer_ptr->buffer_fill_end_time);
				  video_dbg_trace(STREAM_DEC_BUFFER_FILL_FPS, (buffer_ptr->frame_write_index*1000)/buffer_ptr->buffer_fill_end_time);
#ifdef __STREAM_TRACE_ON__			
				  STREAM_INFO_LOG3(VIDEO_STREAM_DECODE_BUFFER_STATUS5, g_video_dec_buffer_mgr_ptr->write_buffer_id, (buffer_ptr->frame_write_index*1000)/buffer_ptr->buffer_fill_end_time);
#endif
				  g_video_dec_buffer_mgr_ptr->write_buffer_id++;
				  g_video_dec_buffer_mgr_ptr->write_buffer_id %= g_video_dec_buffer_mgr_ptr->buffer_count;
				  buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->write_buffer_id];
				  //if ((buffer_ptr->is_write_done == KAL_TRUE) || (buffer_ptr->is_read_done==KAL_TRUE))
				  if (buffer_ptr->is_write_done == KAL_TRUE)
				  {
					 VIDEO_ASSERT(0);
#ifdef __VIDEO_STREAM_STORE_BUFFER__
					 video_dec_unstore_stream_buffer_file(parse_size);
#endif               
					//(*g_video_dec_buffer_mgr_ptr->cb_info.callback)(VIDEO_RTP_EVENT_OVERFLOW);
					g_video_dec_info_ptr->is_stream_overflow = KAL_TRUE;
					//video_dbg_trace(MP4_DEC_TASK_IND_END, video_get_current_time());
					//kal_give_mutex(g_video_dec_buffer_mutex);
					kal_prompt_trace(MOD_MED, "VIDEO_RTP_PUT_PKT_TO_BUF_WRITE_DONE_ERR2_OVERFLOW\n");
					return VIDEO_ERROR;
				  } else {
					buffer_ptr->frame_start_id = g_video_dec_buffer_mgr_ptr->total_frame_no;
					buffer_ptr->buffer_fill_start_time = video_get_current_time();
				  }
	
				  if(g_video_dec_buffer_mgr_ptr->packet_in_frame_count > 0)
				  {
						/* the current frame is divide into multiple packets, 
						 should copy the previous ones to next buffer in the later */
						g_video_dec_buffer_mgr_ptr->b_switch_copy_packet = KAL_TRUE;
				  }
			 } 					 
		
			 /* update the header if needed */
			 if(video_rtp_get_format()==VIDEO_DEC_STREAM_H264)
			 {
				  VIDEO_DEC_BUFFER_STRUCT *update_buffer_ptr = buffer_ptr;
				  if(g_video_rtp_info.b_add_length[index] == KAL_TRUE)
				  {
						buffer_ptr->header_pos = buffer_ptr->size_usage;
						g_video_dec_buffer_mgr_ptr->total_data_size = 0;
						buffer_ptr->size_usage+=4;
				  }
				  else if(g_video_dec_buffer_mgr_ptr->b_switch_copy_packet == KAL_TRUE)
				  {
						 kal_uint16 prev_buffer_id = (g_video_dec_buffer_mgr_ptr->write_buffer_id + g_video_dec_buffer_mgr_ptr->buffer_count -1) %
															  g_video_dec_buffer_mgr_ptr->buffer_count;
						 update_buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[prev_buffer_id];
				  }
				  g_video_dec_buffer_mgr_ptr->total_data_size+=g_video_rtp_info.buffer_size[index];
				  update_buffer_ptr->buffer[update_buffer_ptr->header_pos] = (g_video_dec_buffer_mgr_ptr->total_data_size>>24)&0xff; 	  
				  update_buffer_ptr->buffer[update_buffer_ptr->header_pos+1] = (g_video_dec_buffer_mgr_ptr->total_data_size>>16)&0xff;
				  update_buffer_ptr->buffer[update_buffer_ptr->header_pos+2] = (g_video_dec_buffer_mgr_ptr->total_data_size>>8)&0xff;
				  update_buffer_ptr->buffer[update_buffer_ptr->header_pos+3] = (g_video_dec_buffer_mgr_ptr->total_data_size>>0)&0xff;
			 }
				
			 /* 1. copy data to buffer  2.update frame length and frame addr infomration*/
			 if(g_video_dec_buffer_mgr_ptr->packet_in_frame_count==0)
			 { 			 
				  kal_mem_cpy(&buffer_ptr->buffer[buffer_ptr->size_usage], (kal_uint8*)g_video_rtp_info.buffer_addr[index], g_video_rtp_info.buffer_size[index]);
				  if((video_rtp_get_format()==VIDEO_DEC_STREAM_H264) && 
					(g_video_rtp_info.b_add_length[index] == KAL_TRUE))
				  {
					buffer_ptr->frame_buffer_addr[buffer_ptr->frame_write_index] = ((kal_uint32)buffer_ptr->buffer) + buffer_ptr->size_usage - 4;
					buffer_ptr->frame_length[buffer_ptr->frame_write_index] = g_video_rtp_info.buffer_size[index] + 4;
					if (buffer_ptr->frame_length[buffer_ptr->frame_write_index] > 100000)
						 VIDEO_ASSERT(0);
				  }
				  else
				  {
					buffer_ptr->frame_buffer_addr[buffer_ptr->frame_write_index] = ((kal_uint32)buffer_ptr->buffer) + buffer_ptr->size_usage;
					buffer_ptr->frame_length[buffer_ptr->frame_write_index] = g_video_rtp_info.buffer_size[index];
					if (buffer_ptr->frame_length[buffer_ptr->frame_write_index] > 100000)
						 VIDEO_ASSERT(0);
				  }
				  buffer_ptr->size_usage += g_video_rtp_info.buffer_size[index];
			 }
			 else
			 {
				  if( g_video_dec_buffer_mgr_ptr->b_switch_copy_packet == KAL_TRUE)
				  {
						/* This is the first frame in the current buffer but
							 some previous pkt data full in the previous buffer */
						kal_uint16 prev_buffer_id = (g_video_dec_buffer_mgr_ptr->write_buffer_id + g_video_dec_buffer_mgr_ptr->buffer_count -1) %
															 g_video_dec_buffer_mgr_ptr->buffer_count;
						VIDEO_DEC_BUFFER_STRUCT *prev_buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[prev_buffer_id];
						kal_uint32 prev_size =	prev_buffer_ptr->frame_length[prev_buffer_ptr->frame_write_index];
						/* copy data from previous buffer */
						kal_mem_cpy(buffer_ptr->buffer, (kal_uint8*)prev_buffer_ptr->frame_buffer_addr[prev_buffer_ptr->frame_write_index], prev_size);
						prev_buffer_ptr->size_usage -= prev_size;
						/* copy this frame */
						if(video_rtp_get_format()==VIDEO_DEC_STREAM_H264) 
						{
							if(g_video_rtp_info.b_add_length[index] == KAL_TRUE)
							 {
								  buffer_ptr->header_pos = prev_size;
								  buffer_ptr->buffer[buffer_ptr->header_pos] = (g_video_dec_buffer_mgr_ptr->total_data_size>>24)&0xff;		
								  buffer_ptr->buffer[buffer_ptr->header_pos+1] = (g_video_dec_buffer_mgr_ptr->total_data_size>>16)&0xff;
								  buffer_ptr->buffer[buffer_ptr->header_pos+2] = (g_video_dec_buffer_mgr_ptr->total_data_size>>8)&0xff;
								  buffer_ptr->buffer[buffer_ptr->header_pos+3] = (g_video_dec_buffer_mgr_ptr->total_data_size>>0)&0xff;
								  prev_size+=4;
								  buffer_ptr->size_usage-=4;	/* add in previous code */
							 }
							 else
							 {
								buffer_ptr->header_pos = prev_buffer_ptr->header_pos - prev_buffer_ptr->size_usage;
							 }
						}
						kal_mem_cpy(&buffer_ptr->buffer[prev_size], (kal_uint8*)g_video_rtp_info.buffer_addr[index], g_video_rtp_info.buffer_size[index]);
						buffer_ptr->frame_buffer_addr[buffer_ptr->frame_write_index] = (kal_uint32)buffer_ptr->buffer;
						buffer_ptr->frame_length[buffer_ptr->frame_write_index] = g_video_rtp_info.buffer_size[index] + prev_size;
						buffer_ptr->size_usage += buffer_ptr->frame_length[buffer_ptr->frame_write_index];
						if (buffer_ptr->frame_length[buffer_ptr->frame_write_index] > 100000)
							 VIDEO_ASSERT(0);
					
						g_video_dec_buffer_mgr_ptr->b_switch_copy_packet = KAL_FALSE;
				  }
				  else
				  {
						/* not the first packet in the current frame, only update length information */
						kal_mem_cpy(&buffer_ptr->buffer[buffer_ptr->size_usage], (kal_uint8*)g_video_rtp_info.buffer_addr[index], g_video_rtp_info.buffer_size[index]);
						buffer_ptr->frame_length[buffer_ptr->frame_write_index] += g_video_rtp_info.buffer_size[index];
						if((video_rtp_get_format()==VIDEO_DEC_STREAM_H264) && 
							 (g_video_rtp_info.b_add_length[index] == KAL_TRUE))
						{
							 buffer_ptr->frame_length[buffer_ptr->frame_write_index] += 4;
						}
						buffer_ptr->size_usage += g_video_rtp_info.buffer_size[index];
						if (buffer_ptr->frame_length[buffer_ptr->frame_write_index] > 100000)
							 VIDEO_ASSERT(0);
				  }
			 }
			 kal_prompt_trace(MOD_MED, "VIDEO_RTP_PUT_PKT_TO_BUF_Update_FRM_LEN_ADDR: OK\n");
		
			 /* update time infomration. 
				  note that time is >0 when mark bit is set (the last one packet in the current frame ) */
			 if(g_video_rtp_info.time[index] > 0)
			 {
				  buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index] = g_video_rtp_info.time[index];
				  /* In case time error in VOP header so that frame time is not reasonable . Tricky to fix it */
				  if((buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index]&0xf0000000)!=0)
				  {
						if((*n_prev_frame_time)!=0)
						{
							 buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index] = (*n_prev_frame_time)/2;
							 if(buffer_ptr->frame_write_index != 0)
							 {
								  buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index-1] = (*n_prev_frame_time)/2;
							 }
						}
						else
						{
							 kal_uint32 fixed_frame_time = VIDEO_ANYBASE_TO_ANYBASE(
															 VIDEO_FILE_MIN_FRAME_DURATION, 1000, 
															 g_video_dec_buffer_mgr_ptr->p_rtp_driver->get_timescale());
							 buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index] = fixed_frame_time;
							 /* translate to av time base */ 
							 result = video_dec_translate_av_time(buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index], &buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index]);
							 if (result != MEDIA_STATUS_OK)
							 {
								  VIDEO_ASSERT(0);
								  break;
							 }
						}							
				  } 
				  else
				  {
						// Trick to avoid large frame time. Use previous frames' time to compare and set.
						if (buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index] > VIDEO_ANYBASE_TO_ANYBASE(
							10000, 1000, g_video_dec_buffer_mgr_ptr->p_rtp_driver->get_timescale()))
						{
							if (buffer_ptr->frame_write_index == 0) {
								buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index] = VIDEO_ANYBASE_TO_ANYBASE(
									3000, 1000, g_video_dec_buffer_mgr_ptr->p_rtp_driver->get_timescale());
								video_dec_translate_av_time(buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index], &buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index]);
							} else {
								buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index] = buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index-1]*2;
							}
						} else { // normal case
							/* translate to av time base */ 
							result = video_dec_translate_av_time(buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index], &buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index]);
							if (result != MEDIA_STATUS_OK)
							{
							 	VIDEO_ASSERT(0);
							 	break;
							}
						}
				  }	 
				  *n_prev_frame_time = buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index];
#ifdef __STREAM_TRACE_ON__					
				  STREAM_INFO_LOG4(VIDEO_STREAM_DECODE_BUFFER_STATUS4, g_video_dec_buffer_mgr_ptr->total_frame_no, *n_prev_frame_time, buffer_ptr->frame_length[buffer_ptr->frame_write_index]);
#endif
		
#ifdef STREM_DEC_BUFFER_DBG_TRACE
				  video_dbg_trace(STREAM_FRAME_LENGTH, buffer_ptr->frame_length[buffer_ptr->frame_write_index] );
				  video_dbg_trace(STREAM_FRAME_DURATION, buffer_ptr->prev_frame_duration[buffer_ptr->frame_write_index] );
#endif
				
				  /* complete the current frame, update buffer index*/	 
				  buffer_ptr->frame_write_index++;
				  buffer_ptr->total_frames_in_buffers++;
				  g_video_dec_buffer_mgr_ptr->total_frame_no++;
		
				  /* check frame number reach limit */
				  if(buffer_ptr->total_frames_in_buffers == DEC_MAX_FRMAE_IN_BUFFER)
				  {
					/* reach item limit, switch buffer */
					buffer_ptr->is_write_done = KAL_TRUE;
					buffer_ptr->buffer_fill_end_time = video_get_duration_ms(buffer_ptr->buffer_fill_start_time);
					video_dbg_trace(STREAM_DEC_BUFFER_FILL_INDEX, g_video_dec_buffer_mgr_ptr->write_buffer_id);
					video_dbg_trace(STREAM_DEC_BUFFER_FILL_DURATION, buffer_ptr->buffer_fill_end_time);
					video_dbg_trace(STREAM_DEC_BUFFER_FILL_FPS, (buffer_ptr->frame_write_index*1000)/buffer_ptr->buffer_fill_end_time);
#ifdef __STREAM_TRACE_ON__			
					STREAM_INFO_LOG3(VIDEO_STREAM_DECODE_BUFFER_STATUS5, g_video_dec_buffer_mgr_ptr->write_buffer_id, (buffer_ptr->frame_write_index*1000)/buffer_ptr->buffer_fill_end_time);
#endif
					g_video_dec_buffer_mgr_ptr->write_buffer_id++;
					g_video_dec_buffer_mgr_ptr->write_buffer_id %= g_video_dec_buffer_mgr_ptr->buffer_count;
					buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->write_buffer_id];
					buffer_ptr->frame_start_id = g_video_dec_buffer_mgr_ptr->total_frame_no;
					buffer_ptr->buffer_fill_start_time = video_get_current_time();
				  }
		
				  /* next pkt is the first pkt*/
				  g_video_dec_buffer_mgr_ptr->packet_in_frame_count = 0;
			 }
			 else /* g_video_rtp_info.time[index] > 0 */
			 {
				  /* divide as multiple pkts, this is not the last packet in current frame  */
				  g_video_dec_buffer_mgr_ptr->packet_in_frame_count++;
				  kal_prompt_trace(MOD_MED, "VIDEO_RTP_PUT_PKT_TO_BUF_PKT_IN_FRM_CNT: (%d)\n", g_video_dec_buffer_mgr_ptr->packet_in_frame_count);
			 }
		
			 //total_size+=g_video_rtp_info.buffer_size[index];
			 index++;
		}
		return result;
}

MEDIA_STATUS_CODE video_dec_stream_put_pkt_to_buffer_loop(kal_uint8* p_next_data, kal_uint32 next_size) //, kal_bool b_parse_last_pkt)
{
	MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;
	kal_uint8 *p_parse_data;
	kal_uint32 parse_size;
	VIDEO_DEC_BUFFER_STRUCT *buffer_ptr;

	//while((p_next_data != NULL) || (b_parse_last_pkt==KAL_TRUE))
	while (p_next_data != NULL) 
	{
#ifdef STREM_DEC_BUFFER_DBG_TRACE
	  video_dbg_trace(STREAM_HANDLE_SEQ, g_video_dec_buffer_mgr_ptr->sequnce_no);
#endif
	
	  if(g_video_dec_buffer_mgr_ptr->b_first_data == KAL_TRUE)
	 {
		 kal_uint32 vos_size=0;
		 /* Try to find VOS*/
		 result = g_video_dec_buffer_mgr_ptr->p_rtp_driver->parse_first_frame(p_next_data, next_size, &vos_size, &g_video_dec_buffer_mgr_ptr->rtp_header_size);
		 if (g_video_dec_buffer_mgr_ptr->rtp_header_size > VIDEO_DEC_STREAM_BUFFER_SIZE)
			  g_video_dec_buffer_mgr_ptr->rtp_header_size = VIDEO_DEC_STREAM_BUFFER_SIZE*3/4;
	
		 if(result == MEDIA_STATUS_OK)
		 {
			  /* Find VOS */
			  p_parse_data = p_next_data + vos_size;
			  parse_size = next_size - vos_size;
			  g_video_dec_buffer_mgr_ptr->b_first_data = KAL_FALSE;
			  if(parse_size==0)
			  {			  
					/* No VOP in this packet */
					VIDEO_ASSERT(0);
					//video_dbg_trace(MP4_DEC_TASK_IND_END, video_get_current_time());
					//kal_give_mutex(g_video_dec_buffer_mutex);
					kal_prompt_trace(MOD_MED, "VIDEO_RTP_put_pkt_to_buffer_loop_err: parse_size=0\n");
					return VIDEO_ERROR;
			  }
			  else
			  {
					if(vos_size!=0)
					{
						 /* add header for rtp parse */
						 p_parse_data = p_parse_data - g_video_dec_buffer_mgr_ptr->rtp_header_size;
						 kal_mem_cpy(p_parse_data, p_next_data, g_video_dec_buffer_mgr_ptr->rtp_header_size);
						 parse_size+=g_video_dec_buffer_mgr_ptr->rtp_header_size;
					}
			  }
		 }
		 else
		 { 	
			  p_parse_data = p_next_data;
			  parse_size = next_size;
			  g_video_dec_buffer_mgr_ptr->b_first_data = KAL_FALSE;
		 }
	 } 
	 else {
		 p_parse_data = p_next_data;
		 parse_size = next_size;
	 }
#ifdef __VIDEO_STREAM_STORE_BUFFER2__
	 {
		 video_dec_store_stream_buffer_file(p_parse_data, parse_size);
		 return result;	 
	 }
#endif
	
	 result = video_dec_stream_put_pkt_to_buffer(p_parse_data, parse_size);
	 if (result != MEDIA_STATUS_OK) {
	 	VIDEO_ASSERT(0);
		kal_prompt_trace(MOD_MED, "VIDEO_RTP_put_pkt_to_buffer error: %d\n", result);
		return result;
	 }

	 p_next_data = video_dec_stream_get_sequence_pkt(&next_size);
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
#endif	 
	}

	buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->write_buffer_id];
     //if (((buffer_ptr->total_frames_in_buffers>(DEC_MAX_FRMAE_IN_BUFFER>>1))&&((g_video_dec_buffer_mgr_ptr->read_buffer_id!=0)&&(buffer_ptr->frame_read_index!=0)))|| // Not initial putpacket, to prevent buffer overflow case
	// 	(buffer_ptr->size_usage > (buffer_ptr->buffer_length>>1))||
	// 	((g_video_dec_buffer_mgr_ptr->read_buffer_id==0)&&(g_video_dec_buffer_mgr_ptr->write_buffer_id==0)&&(buffer_ptr->total_frames_in_buffers>0)))
	if ((g_video_dec_buffer_mgr_ptr->read_buffer_id==0)&&(g_video_dec_buffer_mgr_ptr->write_buffer_id==0)&&(buffer_ptr->total_frames_in_buffers>0))
	{
	   buffer_ptr->is_write_done = KAL_TRUE;
	   buffer_ptr->buffer_fill_end_time = video_get_duration_ms(buffer_ptr->buffer_fill_start_time);
	   video_dbg_trace(STREAM_DEC_BUFFER_FILL_INDEX, g_video_dec_buffer_mgr_ptr->write_buffer_id);
	   video_dbg_trace(STREAM_DEC_BUFFER_FILL_DURATION, buffer_ptr->buffer_fill_end_time);
	   video_dbg_trace(STREAM_DEC_BUFFER_FILL_FPS, (buffer_ptr->frame_write_index*1000)/buffer_ptr->buffer_fill_end_time);
#ifdef __STREAM_TRACE_ON__			
	   STREAM_INFO_LOG3(VIDEO_STREAM_DECODE_BUFFER_STATUS5, g_video_dec_buffer_mgr_ptr->write_buffer_id, (buffer_ptr->frame_write_index*1000)/buffer_ptr->buffer_fill_end_time);
#endif
	   g_video_dec_buffer_mgr_ptr->write_buffer_id++;
	   g_video_dec_buffer_mgr_ptr->write_buffer_id %= g_video_dec_buffer_mgr_ptr->buffer_count;
	   buffer_ptr = g_video_dec_buffer_mgr_ptr->p_dec_buffer[g_video_dec_buffer_mgr_ptr->write_buffer_id];
	   if (buffer_ptr->is_write_done == KAL_TRUE)
	   {
		   	VIDEO_ASSERT(0);
#ifdef __VIDEO_STREAM_STORE_BUFFER__
	   		video_dec_unstore_stream_buffer_file(parse_size);
#endif               
		   	g_video_dec_info_ptr->is_stream_overflow = KAL_TRUE;
	   		//video_dbg_trace(MP4_DEC_TASK_IND_END, video_get_current_time());
		   	//kal_give_mutex(g_video_dec_buffer_mutex);
	   		return VIDEO_ERROR;
	   } else {
	   		buffer_ptr->frame_start_id = g_video_dec_buffer_mgr_ptr->total_frame_no;
	   		buffer_ptr->buffer_fill_start_time = video_get_current_time();
	   }
	 
	   if(g_video_dec_buffer_mgr_ptr->packet_in_frame_count > 0)
	   {
	   		g_video_dec_buffer_mgr_ptr->b_switch_copy_packet = KAL_TRUE;
	   }
					
	}
	return result;
}

/* application put packet to decoder by this function */
MEDIA_STATUS_CODE video_dec_stream_put_frame_to_buffer(kal_uint8* p_data, kal_uint32 size)
{
    MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;
    kal_uint32 index;
    kal_uint8 *p_next_data = NULL;
    kal_uint32 next_size;
    //kal_bool b_parse_last_pkt = KAL_FALSE;

    if (kal_if_hisr() == KAL_TRUE)
        EXT_ASSERT(0, 0, 0, 0);

    if( g_video_dec_buffer_mgr_ptr->cb_info.scenario != VIDEO_DEC_BUFFER_SCENARIO_STREAM )
    {
        EXT_ASSERT(0, (kal_uint32)g_video_dec_buffer_mgr_ptr->cb_info.scenario, 0, 0);
    }

    kal_take_mutex(g_video_dec_buffer_mutex);
    //video_dbg_trace(MP4_DEC_TASK_IND_START, video_get_current_time());

#ifdef __VIDEO_STREAM_STORE_BUFFER__
    video_dec_open_stream_file();
    video_dec_store_stream_file(p_data, size);
#endif

        // check rtp packet sequence first 
        if(size!=0)
        {
            p_next_data = video_dec_stream_check_sequence_pkt(p_data, size, &next_size);
        }
        else
        {  
            p_next_data = video_dec_stream_get_sequence_pkt(&next_size);
        }

#ifdef __STREAM_TRACE_ON__
        {            
            kal_uint32 bsize=0;
            for (index=0; index<g_video_rtp_reorder_buff_info.total_pkt; index++) {
                bsize += g_video_rtp_reorder_buff_info.buffer_size[index];
            }
            STREAM_INFO_LOG5(VIDEO_STREAM_REORDER_BUFFER_STATUS2, g_video_dec_buffer_mgr_ptr->sequnce_no, g_video_rtp_reorder_buff_info.total_pkt, VIDEO_RTP_REORDER_BUFFER_SIZE, bsize);
        }
#endif

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
#endif
    result = video_dec_stream_put_pkt_to_buffer_loop(p_next_data, next_size);
    if (result != MEDIA_STATUS_OK) {
	    VIDEO_ASSERT(0);
		kal_prompt_trace(MOD_MED, "VIDEO_RTP_put_pkt_to_buffer_loop error: %d\n", result);
    }

#ifdef __VIDEO_STREAM_STORE_BUFFER__
        video_dec_close_stream_file();
#endif

#ifdef __STREAM_TRACE_ON__
    {
    	video_dec_show_buffer_trace(0); // 0 for streaming
    }
#endif
    //video_dbg_trace(MP4_DEC_TASK_IND_END, video_get_current_time());
    kal_give_mutex(g_video_dec_buffer_mutex);
    
    return result;

}

// After 5 seconds of initial buffering time, if audio buffer is enough and no frames in video buffer, MED will still call video_rtp_start. At the moment, the pkts in reorder buffer should be put_to_buffer.
MEDIA_STATUS_CODE video_dec_stream_flush_reorder_buffer()
{
	kal_uint8 *p_next_data = NULL;
	kal_uint32 next_size;
	kal_uint32 next_sequence;

#ifdef __STREAM_TRACE_ON__
  {	
	kal_uint32 bsize=0, index;
	for (index=0; index<g_video_rtp_reorder_buff_info.total_pkt; index++) {
		 STREAM_INFO_LOG4(VIDEO_STREAM_PUTPACKET_STATUS2, index, g_video_rtp_reorder_buff_info.sequence[index], g_video_rtp_reorder_buff_info.buffer_size[index]);
		 bsize += g_video_rtp_reorder_buff_info.buffer_size[index];
	}
	STREAM_INFO_LOG5(VIDEO_STREAM_REORDER_BUFFER_STATUS, g_video_dec_buffer_mgr_ptr->sequnce_no, g_video_rtp_reorder_buff_info.total_pkt, VIDEO_RTP_REORDER_BUFFER_SIZE, bsize);
  }
#endif

  kal_take_mutex(g_video_dec_buffer_mutex);
  p_next_data = video_rtp_reorder_get_pkt(0xffffffff, &next_size, &next_sequence);
  if(p_next_data!=NULL)
  {
     g_video_dec_buffer_mgr_ptr->sequnce_no = next_sequence;
     video_dec_stream_put_pkt_to_buffer_loop(p_next_data, next_size);
  } else {
     kal_give_mutex(g_video_dec_buffer_mutex);
     return VIDEO_ERROR;
  }
  kal_give_mutex(g_video_dec_buffer_mutex);
  return MEDIA_STATUS_OK;
}

#ifdef __VIDEO_STREAM_STORE_BUFFER__   /* debug mode, store the received packet to file */
/* open stored files */
static void video_dec_open_stream_file(void)
{
	static kal_uint32 open_cnt = 0;
    /* open file to store buffer data */
    FSAL_Status FSAL_STATUS;
    kal_wchar   store_name[30]=L"x:\\video_stream.bin";
    kal_wchar   store_name2[30]=L"x:\\video_buffer.bin";
    store_name[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    store_name2[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    
    if (open_cnt == 0) {
    	FS_Delete(store_name);
    	FS_Delete(store_name2);
    }    
    
    FSAL_STATUS = FSAL_Open(&FSAL_VIDEO_STREAM_FILE, store_name, FSAL_APPEND);
    if (FSAL_STATUS != FSAL_OK)
    {
        ASSERT(0);
    }
    
    FSAL_STATUS = FSAL_Open(&FSAL_VIDEO_STREAM_BUFFER_FILE, store_name2, FSAL_APPEND);
    if (FSAL_STATUS != FSAL_OK)
    {
        ASSERT(0);
    }
    open_cnt++;
}

/* stored received data */
static void video_dec_store_stream_file(kal_uint8* mem_addr, kal_uint32 size)
{
    FSAL_Status tmp_status;
    kal_uint8 a_size[4];

    a_size[0] = ((size+4) >> 24) & 0xff;
    a_size[1] = ((size+4) >> 16) & 0xff;
    a_size[2] = ((size+4) >> 8) & 0xff;
    a_size[3] = ((size+4) >> 0) & 0xff;
    
    tmp_status = FSAL_Write(&FSAL_VIDEO_STREAM_FILE, a_size, 4);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }   

    tmp_status = FSAL_Write(&FSAL_VIDEO_STREAM_FILE, (kal_uint8 *)mem_addr, size);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }   
}

/* stored buffer data */
static void video_dec_store_stream_buffer_file(kal_uint8* mem_addr, kal_uint32 size)
{
    FSAL_Status tmp_status;
    kal_uint8 a_size[4];

    a_size[0] = ((size+4) >> 24) & 0xff;
    a_size[1] = ((size+4) >> 16) & 0xff;
    a_size[2] = ((size+4) >> 8) & 0xff;
    a_size[3] = ((size+4) >> 0) & 0xff;
    
    tmp_status = FSAL_Write(&FSAL_VIDEO_STREAM_BUFFER_FILE, a_size, 4);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }   

    tmp_status = FSAL_Write(&FSAL_VIDEO_STREAM_BUFFER_FILE, (kal_uint8 *)mem_addr, size);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }   
}

/* unstored buffer data */
static void video_dec_unstore_stream_buffer_file(kal_uint32 size)
{
    FSAL_Status tmp_status;
    kal_uint32 u_position;

    tmp_status = FSAL_GetCurPos(&FSAL_VIDEO_STREAM_BUFFER_FILE, &u_position);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }  

    tmp_status = FSAL_Seek(&FSAL_VIDEO_STREAM_BUFFER_FILE, u_position-size-4);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
        return;
    }  
}

/* close files */
static void video_dec_close_stream_file(void)
{
    FSAL_Status tmp_status;
    kal_uint32 u_position;
    kal_int32 fs_status;
    
    FSAL_Close(&FSAL_VIDEO_STREAM_FILE);

    tmp_status = FSAL_GetCurPos(&FSAL_VIDEO_STREAM_BUFFER_FILE, &u_position);
    if (tmp_status != FSAL_OK)
    {
        VIDEO_ASSERT(0);
    }  
    fs_status = FS_Seek(FSAL_VIDEO_STREAM_BUFFER_FILE.hFile, u_position, FS_FILE_BEGIN);
    if(fs_status<0)
    {
        VIDEO_ASSERT(0);
    }  
    fs_status = FS_Truncate(FSAL_VIDEO_STREAM_BUFFER_FILE.hFile);
    if(fs_status<0)
    {
        VIDEO_ASSERT(0);
    } 
    FSAL_Close(&FSAL_VIDEO_STREAM_BUFFER_FILE);
}

#endif /*__VIDEO_STREAM_STORE_BUFFER__*/
#endif /* #ifdef STREAM_SUPPORT */

#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
