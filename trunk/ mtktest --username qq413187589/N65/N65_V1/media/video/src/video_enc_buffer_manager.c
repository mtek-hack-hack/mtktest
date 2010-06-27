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
 *   video_enc_buffer_manager.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   This file defines the buffer manager APIs when mpeg4 encode
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

static kal_bool video_push_reentry;

static kal_bool video_pop_reentry;

extern MP4_FILELIST_STRUCT mp4_files;

void video_enc_switch_buffer_err_callback(void)
{
    ASSERT(0);
}

void video_enc_buffer_init(VIDEO_ENC_BUFFER_STRUCT *buffer)
{
    buffer->buffer_index = 0;

    buffer->is_read_done = KAL_TRUE;
}

MEDIA_STATUS_CODE mp4_enc_struct_init(VIDEO_ENC_STRUCT *enc_struct, MMFILE_TYPE file_type, kal_uint32 frame_count)
{
    kal_uint32 index;

    for (index = 0; index < VIDEO_ENC_MAX_BUFFER_COUNT; index++)
        video_enc_buffer_init(&enc_struct->VIDEO_ENC_BUFFER[index]);

    Buf_init(&enc_struct->META_ENC_BUFFER, (kal_uint8 *)enc_struct->meta_enc_buffer, META_ENC_BUFFER_SIZE);
#ifdef __VIDEO_GET_YUV_DATA__
    video_yuv.read_index = 0;
    video_yuv.write_index = 0;
    video_yuv.send_ilm = KAL_TRUE;
    video_yuv.enable_log = KAL_TRUE;
#endif /*__VIDEO_GET_YUV_DATA__*/

    if ((file_type != MMFILE_MP4) && (file_type == MMFILE_3GP))
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_NOT_SUPPORT;
        return VIDEO_ERROR;
    }

#if defined(__VIDEO_EDITOR__)
	if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
	{
		if (VIDEO_EDITOR_DATA.call_by_next == KAL_FALSE)
		{
			enc_struct->total_frames = frame_count;
	    	enc_struct->hisr_total_frames = frame_count;
		}
	}
	else
#endif	/*__VIDEO_EDITOR__*/
	{
	    enc_struct->total_frames = frame_count;
	    enc_struct->hisr_total_frames = frame_count;
   }
    enc_struct->file_type = file_type;
    enc_struct->is_send_ilm = KAL_FALSE;
    enc_struct->video_enc_callback = NULL;
    enc_struct->read_enc_buffer_id = 0;
    enc_struct->write_enc_buffer_id = 0;
    enc_struct->is_need_to_check_buffer = KAL_FALSE;
    enc_struct->chk_buffer_status_count = 0;
    enc_struct->safty_check_count = 0;
    enc_struct->lost_frames = 0;
    enc_struct->check_camera_miss_count = 0;
    enc_struct->check_buffer_miss_count = 0;	
    enc_struct->b_check_log = KAL_FALSE;
    enc_struct->const_delay = 0;
    enc_struct->force_I_frame = KAL_FALSE;
    enc_struct->is_task_prepare_video_data = KAL_FALSE;
    enc_struct->is_task_prepare_meta_data = KAL_FALSE;
    g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_OK;
    g_video_enc_status.FSAL_STATUS = FSAL_OK;
    g_video_enc_status.FS_STATUS = 0;
    enc_struct->encode_stop = KAL_FALSE;
    enc_struct->is_reach_file_size_limit = KAL_FALSE;
    enc_struct->drop_bitstream = KAL_FALSE;
    enc_struct->switch_buffer_callback = video_enc_switch_buffer_err_callback;
    return MEDIA_STATUS_OK;
}

/*This function is called in ISR*/
kal_uint32 video_enc_buffer_get_roomleft(VIDEO_ENC_STRUCT *enc_struct)
{
    kal_uint32 length;

    VIDEO_ENC_BUFFER_STRUCT *
        curr_buffer = (VIDEO_ENC_BUFFER_STRUCT *)&enc_struct->VIDEO_ENC_BUFFER[enc_struct->write_enc_buffer_id];
    length = curr_buffer->buffer_length - curr_buffer->buffer_index;

    if (length > 30) /*30:maximum header offset*/
        return (length - 30);
    else
        return 0;
}
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
#endif

/*This function is called in ISR*/

kal_uint32 video_enc_buffer_get_memaddr(VIDEO_ENC_STRUCT *enc_struct)
{
    VIDEO_ENC_BUFFER_STRUCT *
        curr_buffer = (VIDEO_ENC_BUFFER_STRUCT *)&enc_struct->VIDEO_ENC_BUFFER[enc_struct->write_enc_buffer_id];

    kal_uint32 addr = (kal_uint32)&curr_buffer->buffer[curr_buffer->buffer_index];
    return addr;
}

/*This function is called in ISR*/
void video_enc_buffer_update_offset(kal_uint32 length)
{
    VIDEO_ENC_STRUCT *enc_struct = g_video_enc_info_ptr;

    VIDEO_ENC_BUFFER_STRUCT *
        curr_buffer = (VIDEO_ENC_BUFFER_STRUCT *)&enc_struct->VIDEO_ENC_BUFFER[enc_struct->write_enc_buffer_id];
    ASSERT((length + curr_buffer->buffer_index) <= curr_buffer->buffer_length);
    curr_buffer->buffer_index += length;
}

/*store to Video file*/

// This function is only called when encode is end!!
MEDIA_STATUS_CODE video_enc_buffer_dump_to_file(kal_uint32 max_size, kal_uint32 *real_store_size)
{
    VIDEO_ENC_STRUCT *enc_struct = (VIDEO_ENC_STRUCT *)g_video_enc_info_ptr;

    VIDEO_ENC_BUFFER_STRUCT *curr_buffer;
    kal_uint32 store_size;
    kal_uint32 savedMask;
#ifdef __VIDEO_GET_YUV_DATA__
    *real_store_size = 1;

    while (1)
    {
        if (video_yuv.cif_size == 1)
        {
            g_video_enc_status.FSAL_STATUS = FSAL_Write(&video_yuv.MEDIA_YUV_FILE,
                                                        (void *)video_yuv.yuvdata.yuvCIF[video_yuv.read_index],
                                                        (g_video_enc_info_ptr->im.width
                                                             * g_video_enc_info_ptr->im.height * 3 / 2));
        }
        else
        {
            g_video_enc_status.FSAL_STATUS = FSAL_Write(&video_yuv.MEDIA_YUV_FILE,
                                                        (void *)video_yuv.yuvdata.yuvQCIF[video_yuv.read_index],
                                                        (g_video_enc_info_ptr->im.width
                                                             * g_video_enc_info_ptr->im.height * 3 / 2));
        }

        ASSERT(g_video_enc_status.FSAL_STATUS == FSAL_OK);
        video_yuv.read_index++;
        video_yuv.read_index = video_yuv.read_index % video_yuv.yuv_max_buffer_count;
        if (video_yuv.write_index == video_yuv.read_index)
            break;
    }

    video_yuv.send_ilm = KAL_TRUE;
    video_yuv.enable_log = KAL_TRUE;

    g_video_enc_status.FSAL_STATUS = FSAL_Close(&video_yuv.MEDIA_YUV_FILE);
    ASSERT(g_video_enc_status.FSAL_STATUS == FSAL_OK);

    return VIDEO_ERROR;
#else /*__VIDEO_GET_YUV_DATA__*/

    g_video_enc_info_ptr->is_task_prepare_video_data = KAL_FALSE;
    *real_store_size = 0;

    while (1)
    {
        curr_buffer = (VIDEO_ENC_BUFFER_STRUCT *)&enc_struct->VIDEO_ENC_BUFFER[enc_struct->read_enc_buffer_id];

        if ((curr_buffer->buffer_index == 0) || (g_video_enc_info_ptr->is_reach_file_size_limit))
        {
            break;
        }

        savedMask = SaveAndSetIRQMask();

        if (max_size == 0)
        {
            RestoreIRQMask(savedMask);
            return MEDIA_STATUS_OK;
        }

        store_size = (max_size > curr_buffer->buffer_index) ? curr_buffer->buffer_index : max_size;
        *real_store_size = ( *real_store_size)+store_size;

        RestoreIRQMask(savedMask);

        g_video_enc_status.FSAL_STATUS = FSAL_Write(&mp4_files.MEDIA_VIDEO_FILE, curr_buffer->buffer, store_size);

        if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);

            g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_VIDEO_FILE;
            return FSAL_ERROR;
        }
#ifndef __L1_STANDALONE__
        g_video_enc_status.FS_STATUS = FS_Commit(mp4_files.MEDIA_VIDEO_FILE.hFile);

        if (g_video_enc_status.FS_STATUS < 0)
        {
            VIDEO_ASSERT(0);
            return FS_ERROR;
        }
#endif /*__L1_STANDALONE__*/

        if (store_size != curr_buffer->buffer_index)
        {
            g_video_enc_info_ptr->is_reach_file_size_limit = KAL_TRUE;
            return MEDIA_STATUS_OK;
        }

        curr_buffer->buffer_index = 0;
        curr_buffer->is_read_done = KAL_TRUE;
        enc_struct->read_enc_buffer_id++;
        enc_struct->read_enc_buffer_id %= VIDEO_ENC_MAX_BUFFER_COUNT;
    }

    return MEDIA_STATUS_OK;
#endif /*__VIDEO_GET_YUV_DATA__*/
}

MEDIA_STATUS_CODE video_enc_buffer_store_file(kal_uint32 max_size, kal_uint32 *real_store_size)
{
    VIDEO_ENC_STRUCT *enc_struct = (VIDEO_ENC_STRUCT *)g_video_enc_info_ptr;
    VIDEO_ENC_BUFFER_STRUCT *curr_buffer;
    kal_uint32 store_size;
    kal_uint32 savedMask;
    kal_uint64 prev_time;
    kal_uint64 curr_time;
    static kal_bool b_fs_extend_fail = KAL_FALSE;   /* for FS_Extend check */
    kal_int32 i_fs_error_code;
    
#ifdef __VIDEO_GET_YUV_DATA__
    *real_store_size = 1;

    while (1)
    {
        if (video_yuv.cif_size == 1)
        {
            g_video_enc_status.FSAL_STATUS = FSAL_Write(&video_yuv.MEDIA_YUV_FILE, (void *)video_yuv.yuvdata.yuvCIF[video_yuv.read_index], (g_video_enc_info_ptr->im.width * g_video_enc_info_ptr->im.height * 3 / 2));
        }
        else
        {
            g_video_enc_status.FSAL_STATUS = FSAL_Write(&video_yuv.MEDIA_YUV_FILE, (void *)video_yuv.yuvdata.yuvQCIF[video_yuv.read_index], (g_video_enc_info_ptr->im.width * g_video_enc_info_ptr->im.height * 3 / 2));
        }

        ASSERT(g_video_enc_status.FSAL_STATUS == FSAL_OK);
        video_yuv.read_index++;
        video_yuv.read_index = video_yuv.read_index % video_yuv.yuv_max_buffer_count;
        if (video_yuv.write_index == video_yuv.read_index)
            break;
    }

    video_yuv.send_ilm = KAL_TRUE;
    video_yuv.enable_log = KAL_TRUE;
    return MEDIA_STATUS_OK;
#else /*__VIDEO_GET_YUV_DATA__*/

    video_dbg_trace(MP4_ENC_TASK_IND_BITS_START, video_get_current_time());
    g_video_enc_info_ptr->is_task_prepare_video_data = KAL_FALSE;
    *real_store_size = 0;

    prev_time = video_enc_get_current_time();

    while (1)
    {
        curr_time = video_enc_get_current_time();

        curr_buffer = (VIDEO_ENC_BUFFER_STRUCT *)&enc_struct->VIDEO_ENC_BUFFER[enc_struct->read_enc_buffer_id];

        if ((curr_buffer->is_read_done == KAL_TRUE) || (g_video_enc_info_ptr->encode_stop == KAL_TRUE) || ((curr_time - prev_time) > 300) || (g_video_enc_info_ptr->is_reach_file_size_limit))
        {
            break;
        }

        if ((curr_time-prev_time) > 300) 
        {
            return MEDIA_STATUS_OK;
        }

        savedMask = SaveAndSetIRQMask();

        if (max_size == 0)
        {
            RestoreIRQMask(savedMask);
            return MEDIA_STATUS_OK;
        }

        store_size = (max_size > curr_buffer->buffer_index) ? curr_buffer->buffer_index : max_size;
        *real_store_size = ( *real_store_size)+store_size;
        RestoreIRQMask(savedMask);

        if(b_fs_extend_fail == KAL_FALSE)
        {
            i_fs_error_code = FS_Extend(mp4_files.MEDIA_VIDEO_FILE.hFile, store_size);
            if(i_fs_error_code < 0)
            {
                b_fs_extend_fail = KAL_TRUE;	
                VIDEO_ASSERT(0);
#if ( (!defined(__L1_STANDALONE__)) && (!defined(__MAUI_BASIC__)) )
                kal_prompt_trace(MOD_MED_V, "[Video] FS_Extend error %d\n", i_fs_error_code);
#endif   /*__L1_STANDALONE__, __MAUI_BASIC__ */
            }
        }    

        g_video_enc_status.FSAL_STATUS = FSAL_Write(&mp4_files.MEDIA_VIDEO_FILE, curr_buffer->buffer,store_size);
        if (g_video_enc_status.FSAL_STATUS!=FSAL_OK)
        {
            VIDEO_ASSERT(0);
            g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_VIDEO_FILE;
            return FSAL_ERROR;
        }

        if (store_size != curr_buffer->buffer_index)
        {
            g_video_enc_info_ptr->is_reach_file_size_limit = KAL_TRUE;
            return MEDIA_STATUS_OK;
        }

        curr_buffer->buffer_index = 0;
        curr_buffer->is_read_done = KAL_TRUE;
        enc_struct->read_enc_buffer_id++;
        enc_struct->read_enc_buffer_id %= VIDEO_ENC_MAX_BUFFER_COUNT;
    }

#ifndef  __L1_STANDALONE__
    g_video_enc_status.FS_STATUS = FS_Commit(mp4_files.MEDIA_VIDEO_FILE.hFile);
    if (g_video_enc_status.FS_STATUS<0)
    {
        VIDEO_ASSERT(0);
        return FS_ERROR;
    }
#endif /*__L1_STANDALONE__*/

    video_dbg_trace(MP4_ENC_TASK_IND_BITS_END, video_get_current_time());
    return MEDIA_STATUS_OK;
#endif /*__VIDEO_GET_YUV_DATA__*/
}

kal_bool video_enc_get_buffer_status(VIDEO_ENC_STRUCT *enc_struct)
{
    if (enc_struct->VIDEO_ENC_BUFFER[enc_struct->write_enc_buffer_id].is_read_done == KAL_TRUE)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}

kal_bool video_enc_switch_buffer(VIDEO_ENC_STRUCT *enc_struct)
{
    enc_struct->VIDEO_ENC_BUFFER[enc_struct->write_enc_buffer_id].is_read_done = KAL_FALSE;

    enc_struct->write_enc_buffer_id++;
    enc_struct->write_enc_buffer_id %= VIDEO_ENC_MAX_BUFFER_COUNT;

    if (enc_struct->VIDEO_ENC_BUFFER[enc_struct->write_enc_buffer_id].is_read_done == KAL_TRUE)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}

/*driver will call this function*/
void meta_enc_buffer_get_roomleft(VIDEO_BUF_DESC *mem_left)
{
    BUFFER_INFO *buffer_struct = &g_video_enc_info_ptr->META_ENC_BUFFER;

    if (buffer_struct->Write >= buffer_struct->Read)
    {
        mem_left->mem_block_no = 2;

        mem_left->start_addr[0] = (kal_uint32)(buffer_struct->CharBuffer + buffer_struct->Write);

        if (buffer_struct->Write)
            mem_left->length[0] = buffer_struct->Length - buffer_struct->Write;
        else
            mem_left->length[0] = buffer_struct->Length - buffer_struct->Write - 1;

        mem_left->start_addr[1] = (kal_uint32)(buffer_struct->CharBuffer);
        if (buffer_struct->Read)
            mem_left->length[1] = buffer_struct->Read - 1;
        else
            mem_left->length[1] = 0;
    }
    else
    {
        mem_left->mem_block_no = 1;

        mem_left->start_addr[0] = (kal_uint32)(buffer_struct->CharBuffer + buffer_struct->Write);
        mem_left->length[0] = buffer_struct->Read - buffer_struct->Write - 1;
    }
}

/*task will call this function*/
void meta_enc_buffer_get_roomavail(VIDEO_BUF_DESC *mem_avail)
{
    BUFFER_INFO *buffer_struct = &g_video_enc_info_ptr->META_ENC_BUFFER;

    if (buffer_struct->Write >= buffer_struct->Read)
    {
        if (buffer_struct->Write == buffer_struct->Read)
            mem_avail->mem_block_no = 0;
        else
            mem_avail->mem_block_no = 1;

        mem_avail->start_addr[0] = (kal_uint32)(buffer_struct->CharBuffer + buffer_struct->Read);
        mem_avail->length[0] = buffer_struct->Write - buffer_struct->Read;
    }
    else
    {
        mem_avail->mem_block_no = 2;

        mem_avail->start_addr[0] = (kal_uint32)(buffer_struct->CharBuffer + buffer_struct->Read);
        mem_avail->length[0] = buffer_struct->Length - buffer_struct->Read;
        mem_avail->start_addr[1] = (kal_uint32)(buffer_struct->CharBuffer);
        mem_avail->length[1] = buffer_struct->Write;
    }
}

MEDIA_STATUS_CODE meta_enc_buffer_update_push_length(kal_uint32 length)
{
    kal_uint16 avail;

    BUFFER_INFO *buffer_struct = &g_video_enc_info_ptr->META_ENC_BUFFER;

    if (video_push_reentry != KAL_FALSE)
    {
        VIDEO_ASSERT(0);

        video_push_reentry = KAL_FALSE;
        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
        return VIDEO_ERROR;
    }

    video_push_reentry = KAL_TRUE;
    buffer_struct->Write += length;

    if (buffer_struct->Write >= buffer_struct->Length)
        buffer_struct->Write -= buffer_struct->Length;

    video_push_reentry = KAL_FALSE;

    if (buffer_struct->Read == buffer_struct->Write)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
        return VIDEO_ERROR;
    }

    Buf_GetBytesAvail(buffer_struct, avail);

    if ((avail >= META_ENC_BUFFER_TRIGGER_POINT) && (g_video_enc_info_ptr->is_task_prepare_meta_data == KAL_FALSE))
    {
        ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);
#if defined(__VIDEO_EDITOR__)
        if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
        {
            g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_ENC_EVENT_META_BUFFER_AVAIL);
        }
        else
#endif /*__VIDEO_EDITOR__*/

        {
            g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_META_BUFFER_AVAIL);
            g_video_enc_info_ptr->is_task_prepare_meta_data = KAL_TRUE;
        }
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE meta_enc_buffer_drv_store_file(kal_uint32 length, kal_uint32 max_size, kal_uint32 *real_store_size)
{
    BUFFER_INFO *buffer_struct = &g_video_enc_info_ptr->META_ENC_BUFFER;

    kal_uint32 store_size;
    kal_uint32 savedMask;

    if ((buffer_struct->Read + length) > buffer_struct->Length)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
        return VIDEO_ERROR;
    }

    savedMask = SaveAndSetIRQMask();

    if (max_size == 0)
    {
        RestoreIRQMask(savedMask);
        return MEDIA_STATUS_OK;
    }

    store_size = (max_size > length) ? length : max_size;
    *real_store_size = store_size;
    RestoreIRQMask(savedMask);

    g_video_enc_status.FSAL_STATUS = FSAL_Write(&mp4_files.MEDIA_META_FILE, (buffer_struct->CharBuffer + buffer_struct->Read), store_size);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
        return FSAL_ERROR;
    }

    if (store_size != length)
    {
        g_video_enc_info_ptr->is_reach_file_size_limit = KAL_TRUE;
        return MEDIA_STATUS_OK;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE meta_enc_buffer_update_pop_length(kal_uint32 length)
{
    BUFFER_INFO *buffer_struct = &g_video_enc_info_ptr->META_ENC_BUFFER;

    if (video_pop_reentry != KAL_FALSE)
    {
        VIDEO_ASSERT(0);

        video_pop_reentry = KAL_FALSE;
        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
        return VIDEO_ERROR;
    }

    video_pop_reentry = KAL_TRUE;
    buffer_struct->Read += length;

    if (buffer_struct->Read >= buffer_struct->Length)
        buffer_struct->Read -= buffer_struct->Length;

    video_pop_reentry = KAL_FALSE;
    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE mp4_video_enc_push_tableinfo_to_buffer(kal_uint32 time_stamp, kal_uint32 length)
{
    VIDEO_BUF_DESC table_buffer_mem_desc;

    MEDIA_STATUS_CODE result;

    meta_enc_buffer_get_roomleft(&table_buffer_mem_desc);

    if ((table_buffer_mem_desc.length[0] + table_buffer_mem_desc.length[1]) < 8)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
        return VIDEO_ERROR;
    }

    if (table_buffer_mem_desc.length[0] >= 8)
    {
        kal_mem_cpy((kal_uint8 *)table_buffer_mem_desc.start_addr[0], (kal_uint8 *)&time_stamp, 4);
        kal_mem_cpy((kal_uint8 *)(table_buffer_mem_desc.start_addr[0] + 4), (kal_uint8 *)&length, 4);
    }
    else if (table_buffer_mem_desc.length[0] == 4)
    {
        kal_mem_cpy((kal_uint8 *)table_buffer_mem_desc.start_addr[0], (kal_uint8 *)&time_stamp, 4);
        kal_mem_cpy((kal_uint8 *)table_buffer_mem_desc.start_addr[1], (kal_uint8 *)&length, 4);
    }
    else
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FATAL_ERROR;
        return VIDEO_ERROR;
    }

    result = meta_enc_buffer_update_push_length(8);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    return MEDIA_STATUS_OK;
}

void video_enc_done_send_ilm(VIDEO_ENC_STRUCT *enc_struct)
{
    enc_struct->VIDEO_ENC_BUFFER[enc_struct->write_enc_buffer_id].is_read_done = KAL_FALSE;

    enc_struct->write_enc_buffer_id++;
    enc_struct->write_enc_buffer_id %= VIDEO_ENC_MAX_BUFFER_COUNT;
    video_enc_stop_record();
    ASSERT(g_video_enc_info_ptr->video_enc_callback != NULL);
#if defined(__VIDEO_EDITOR__)
    if (g_video_enc_status.scenario == VIDEO_SCENARIO_EDITOR)
    {
        g_video_enc_info_ptr->video_enc_callback(VIDEO_EDITOR_EVENT_COMPLETE);
    }
    else
#endif /*__VIDEO_EDITOR__*/

    {
        g_video_enc_info_ptr->video_enc_callback(VIDEO_ENC_EVENT_COMPLETE);
    }
}

MEDIA_STATUS_CODE meta_enc_buffer_store_file(kal_uint32 org_max_size, kal_uint32 *real_store_size)
{
    kal_uint32 index;

    VIDEO_BUF_DESC enc_buffer_mem_desc;
    MEDIA_STATUS_CODE result;
    kal_uint32 store_size;

    *real_store_size = 0;
    video_dbg_trace(MP4_ENC_TASK_IND_META_START, video_get_current_time());
    g_video_enc_info_ptr->is_task_prepare_meta_data = KAL_FALSE;
    meta_enc_buffer_get_roomavail(&enc_buffer_mem_desc);

    for (index = 0; index < enc_buffer_mem_desc.mem_block_no; index++)
    {
        ASSERT((enc_buffer_mem_desc.length[index] & 0x07) == 0);
        /*result = meta_enc_buffer_drv_store_file(enc_buffer_mem_desc.length[index], org_max_size, &store_size);*/
        result = meta_enc_buffer_drv_store_file(enc_buffer_mem_desc.length[index], 0x7fffffff, &store_size);
        *real_store_size = ( *real_store_size)+store_size;
        org_max_size -= *real_store_size;

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        result = meta_enc_buffer_update_pop_length(enc_buffer_mem_desc.length[index]);
        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
    }

    video_dbg_trace(MP4_ENC_TASK_IND_META_END, video_get_current_time());
    return MEDIA_STATUS_OK;
}
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
