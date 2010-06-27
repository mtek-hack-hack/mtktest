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
 *   video_dec_buffer_manager.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video buffer management
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VIDEO_DEC_BUFFER_MANAGER_H
#define VIDEO_DEC_BUFFER_MANAGER_H

//  Maximum decode frame each buffer
#define DEC_MAX_FRMAE_IN_BUFFER        50

#ifdef STREAM_SUPPORT
//  Maximum buffer count 
#define VIDEO_DEC_MAX_BUFFER_COUNT           20
#else /* STREAM_SUPPORT*/
#ifdef  PGDL_SUPPORT
#define VIDEO_DEC_MAX_BUFFER_COUNT           6
#else
//  Maximum buffer count 
#define VIDEO_DEC_MAX_BUFFER_COUNT           3
#endif  /* VIDEO_DEC_PREGRESSIVE_DL_BUFFER_COUNT */
#endif  /* STREAM_SUPPORT */

/*callback function type definition */
typedef void (*video_dec_buffer_callback)(kal_uint8 event_id);

/* buffer scenario type */
typedef enum
{
    VIDEO_DEC_BUFFER_SCENARIO_FILE,
    VIDEO_DEC_BUFFER_SCENARIO_EDITOR,
    VIDEO_DEC_BUFFER_SCENARIO_PROGRESSIVE,
    VIDEO_DEC_BUFFER_SCENARIO_STREAM
}VIDEO_DEC_BUFFER_SCENARIO;


/* file adap erad parameter */
typedef struct
{
    kal_uint32 start_frame_no;
    kal_uint32 total_frame_no;
    kal_uint32 result_frame_no;
    kal_uint32 max_size;
    kal_uint32 result_size;
    kal_uint32 *p_frame_buffer_addr;
    kal_uint32 *p_frame_length;
    kal_uint32 temp_file_offset[DEC_MAX_FRMAE_IN_BUFFER + 1]; /* temp storage to enhance speed */
} VIDEO_DEC_FILE_READ_STRUCT;

/* each buffer structure */
typedef struct
{
    // Decode physical buffer
    kal_uint8 *buffer;
    // Decode physical buffer length
    kal_uint32 buffer_length;
    // Frame address in double buffer
    kal_uint32 frame_buffer_addr[DEC_MAX_FRMAE_IN_BUFFER];
    // Frame length in double buffer
    kal_uint32 frame_length[DEC_MAX_FRMAE_IN_BUFFER];
    // Frame duration for each frame in buffer
    kal_uint64 prev_frame_duration[DEC_MAX_FRMAE_IN_BUFFER];
    // Total frames number in this buffer
    kal_uint8 total_frames_in_buffers;
    // Total frames number read index
    kal_uint32 frame_read_index;
    // Total frames number write index
    kal_uint32 frame_write_index;
    // The start frame id in this buffer
    kal_uint32 frame_start_id;
    // The previous time in this buffer
    kal_uint64 prev_duration;
    // This buffer is written done by task??
    kal_bool is_write_done;
    // used size
    kal_uint32 size_usage;
#if defined(STREAM_SUPPORT) || defined(PGDL_SUPPORT)
    // This buffer is read done by decoder
    kal_bool is_read_done;
    // H264 NALU header position
    kal_uint32 header_pos;
    kal_uint32 buffer_fill_start_time;		// 32k counter
    kal_uint32 buffer_fill_end_time;			// elapsed mini-seconds
    kal_uint32 buffer_consume_start_time;	// 32k counter
    kal_uint32 buffer_consume_end_time;	// elapsed mini-seconds
#endif        
    // file adap struct
    VIDEO_DEC_FILE_READ_STRUCT file_read_info;
} VIDEO_DEC_BUFFER_STRUCT;

/* initialize function config parameter */
typedef struct
{
    VIDEO_DEC_BUFFER_SCENARIO scenario;
    video_dec_buffer_callback *callback;
    kal_uint8 event_id;
} VIDEO_DEC_BUFFER_CB_STRUCT;

/* decode buffer management structure */
typedef struct
{
    VIDEO_DEC_BUFFER_CB_STRUCT cb_info;
    VIDEO_DEC_BUFFER_STRUCT *p_dec_buffer[VIDEO_DEC_MAX_BUFFER_COUNT];
    kal_uint16 buffer_count;
    kal_uint8 *buffer_start_addr;
    kal_uint16 write_buffer_id;
    kal_uint16 read_buffer_id;
    kal_uint32 start_frame_no;
    kal_uint32 end_frame_no;
    kal_bool send_ilm;
    kal_bool b_data_empty;
    kal_bool cancel_put_buffer;
    kal_bool b_got_end_frame_duration;
    kal_uint64 end_frame_duration;    
#if defined(STREAM_SUPPORT)||defined(PGDL_SUPPORT)
    kal_bool b_first_data; 
    kal_bool b_send_ilm;
    kal_uint32 total_frame_no;

    kal_uint32 packet_in_frame_count;
    kal_uint32 rtp_header_size;
    kal_uint32 total_data_size;
    kal_uint32 sequnce_no;
    kal_bool b_switch_copy_packet;
    kal_uint16 init_buffer_pkts;
    kal_uint32 n_prev_frame_time;
#endif    
#if defined(STREAM_SUPPORT)
    VIDEO_RTP_Driver *p_rtp_driver;
#endif
} VIDEO_DEC_BUFFER_MGR_STRUCT;


/* Config and init buffer management.
*   It should be executed in task level. It may be configured according to differnet application
* @param cb_info buffer senario and callback function information
* @return None
*/
extern void video_dec_config_buffer(VIDEO_DEC_BUFFER_CB_STRUCT cb_info);


/* Clear all the buffers. Only clear the control parameter is enough.
*   It should be executed in task level.
* @param start_frame_no. the start frame that shuld be prepared
* @param end_frame_no. the end frame that shuld be prepared 
* @return None
*/
extern void video_dec_clr_buffer(kal_uint32 start_frame_no, kal_uint32 end_frame_no);


/* Cancel the current put buffer action. If driver decides to stop, but task is still get data from file system to buffer.
*   It can stop put buffer as quickly as possible
* @param None
* @return None
*/
extern void video_dec_cancel_put_buffer(void);


/* get end frame duration, and this function is called in ISR.
 * @param  prev_frame_duration the duration of the previous frame(unit: auido interrupt count)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_get_end_frame_time(kal_uint32 *prev_frame_duration);


/* get next frame address, and this function is called in ISR.
 * @param  addr frame memory addrsss
 * @param  length frame size(bytes)
 * @param  prev_frame_duration the duration of the previous frame(unit: auido interrupt count)
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_get_next_frame(kal_uint8 **addr, kal_uint32 *length, kal_uint32 *prev_frame_duration);


/* Put bitstream data from file to double buffer, and this function should be  called in TASK.
 * @param None
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
extern MEDIA_STATUS_CODE video_dec_put_frame_to_buffer(void);

#ifdef STREAM_SUPPORT
extern MEDIA_STATUS_CODE video_dec_stream_put_config_to_buffer(kal_uint8* p_data, kal_uint32 size);
extern MEDIA_STATUS_CODE video_dec_stream_put_frame_to_buffer(kal_uint8* p_data, kal_uint32 size);
#endif

#endif /*VIDEO_DEC_GLB_H*/
