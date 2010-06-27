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
 *   video_rtp_h264.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   H264 RTP parser
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

#ifdef STREAM_SUPPORT

H264_RTP_CTRL_INFO g_h264_rtp_ctrl_info;

static void h264_rtp_rst_time(void);
static kal_uint32 h264_rtp_get_timescale(void);
static void h264_rtp_set_timescale(kal_uint32 time_scale);
static MEDIA_STATUS_CODE h264_rtp_parse_config(kal_uint8 *data, kal_uint32 size);
static MEDIA_STATUS_CODE h264_rtp_parse_first_frame(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_vos_size, kal_uint32 *p_rtp_header_size);
static MEDIA_STATUS_CODE h264_rtp_parse_non_interleaved_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info);
static MEDIA_STATUS_CODE h264_rtp_parse_interleaved_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info);
static MEDIA_STATUS_CODE h264_rtp_parse_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info);
extern void h264_rtp_init_interleaved_info(kal_uint32 deinterleave_buffer_depth, kal_uint32 max_don_diff);
extern void h264_rtp_free_prev_avalibale_pkt(void);
extern void h264_rtp_get_all_available_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info);
extern void h264_rtp_add_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info, kal_uint32 size);
extern void h264_rtp_get_available_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info);
extern void h264_rtp_add_fragment_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info, kal_bool b_first, kal_bool b_last);

/* reset parameters */
static void h264_rtp_rst_time(void)
{
    g_h264_rtp_ctrl_info.time_offset= 0xffffffff;
}

/* get time scale used in rtp header */
static kal_uint32 h264_rtp_get_timescale(void)
{
    return g_h264_rtp_ctrl_info.time_scale;
}

/* set time scale used in rtp header */
static void h264_rtp_set_timescale(kal_uint32 time_scale)
{
    g_h264_rtp_ctrl_info.time_scale = time_scale;
}

static void h264_rtp_set_mode(kal_uint32 mode)
{
    g_h264_rtp_ctrl_info.packetization_mode = mode;

#ifdef __VIDEO_STREAM_UNIT_TEST__    
    /* Note that this should be modified !!!!! should be set by application!!!!!*/
    if(g_h264_rtp_ctrl_info.packetization_mode == H264_RTP_INTERLEAVED_MODE)
    {
        h264_rtp_init_interleaved_info(5, 5);
    }
#else
    /* !! This should be set by application */
    ASSERT(0);
#endif
}

/* parse vos information from config data */
static MEDIA_STATUS_CODE h264_rtp_parse_config(kal_uint8 *data, kal_uint32 size)
{
    /* no VOS data in RTSP config data */
    return MEDIA_STATUS_OK;
}

/* parse first frame information */
static MEDIA_STATUS_CODE h264_rtp_parse_first_frame(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_vos_size, kal_uint32 *p_rtp_header_size)
{
    kal_uint32 n_csrc_num;
    
    /* parse rtp header */
    n_csrc_num = data[0]&0x0f;
    *p_rtp_header_size = VIDEO_RTP_HEADER_SIZE + (n_csrc_num*VIDEO_RTP_HEADER_CSRC_SIZE);
    
    /* no VOS data in the first packet, just return the parsed size as zero */
    *p_vos_size = 0;
    
    return MEDIA_STATUS_OK;
}


static MEDIA_STATUS_CODE h264_rtp_parse_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info)
{
    MEDIA_STATUS_CODE status;
    if(g_h264_rtp_ctrl_info.packetization_mode == H264_RTP_INTERLEAVED_MODE)
    {
        status = h264_rtp_parse_interleaved_time_size(data, size, p_parse_info);
    }
    else
    {
        status = h264_rtp_parse_non_interleaved_time_size(data, size, p_parse_info);
    }

    return status;
}

static MEDIA_STATUS_CODE h264_rtp_parse_non_interleaved_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info)
{
    kal_bool b_mark;
    kal_uint32 n_timestamp;
    kal_uint16 n_sequence;
    kal_uint32 n_csrc_num;
    kal_uint32 n_rtp_header_size;
    kal_uint8 n_Fbit;
    kal_uint8 n_NRI;
    kal_uint8 n_Type;
    kal_uint8 n_fragment_Sbit;
    kal_uint8 n_fragment_Ebit;
    kal_uint8 n_fragment_Rbit;
    kal_uint8 n_fragment_Type;
    kal_uint32 n_size;

    if(size==0)
    {
        /* the last one packet */
        p_parse_info->buffer_size[0] = 0;
        return MEDIA_STATUS_OK;
    }    
    
    /* parse rtp header */
    n_csrc_num = data[0]&0x0f;
    n_rtp_header_size = VIDEO_RTP_HEADER_SIZE + (n_csrc_num*VIDEO_RTP_HEADER_CSRC_SIZE);
    b_mark = (data[1]&0x80) ? KAL_TRUE: KAL_FALSE;
    n_sequence = (data[2]<<8) + data[3];
    n_timestamp = (data[4]<<24) + (data[5]<<16) + (data[6]<<8) + data[7];

    /* parse time */
    if(b_mark == KAL_TRUE)
    {
        if(g_h264_rtp_ctrl_info.time_offset == 0xffffffff)
        {
            /* the first VOP*/
            p_parse_info->time[0] = 0xffffffff;
        }
        else
        {
            p_parse_info->time[0] = n_timestamp - g_h264_rtp_ctrl_info.time_offset;
        }
        g_h264_rtp_ctrl_info.time_offset = n_timestamp;
    }
    else
    {
        p_parse_info->time[0] = 0;  /* time = 0 means not the last packet for the current VOP(marker = 0)*/    
    }

    /* parse size */
    n_Fbit = (data[n_rtp_header_size] >> 7) & 0x1;
    n_NRI = (data[n_rtp_header_size] >> 5) & 0x3;
    n_Type = (data[n_rtp_header_size] >> 0) & 0x1f;
    if(n_Type <= 23)
    {
        /* single NAL unit */
        /* append NAL size header */
        p_parse_info->b_add_length[0] = KAL_TRUE;
        p_parse_info->buffer_size[0] = size - n_rtp_header_size; 
        p_parse_info->buffer_addr[0] = (kal_uint32)&data[n_rtp_header_size];
        p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
    }
    else if(n_Type == 24)
    {
        /* STAP-A aggregation*/
        kal_uint32 index = 0;
        kal_uint32 offset = 0;
        n_rtp_header_size++;
        offset = n_rtp_header_size;
        while(offset!=size)
        {
            n_size = (data[offset] << 8) + data[offset+1];
            p_parse_info->buffer_size[index] = 	n_size;
            p_parse_info->buffer_addr[index] = (kal_uint32)&data[offset + H264_RTP_AGGREGATE_LENGTH_SIZE]; 
            p_parse_info->b_add_length[index] = KAL_TRUE;	// ToDo: only the first NALU is needed?
            offset+=(n_size+H264_RTP_AGGREGATE_LENGTH_SIZE);
            index++;
        }

        /* set the time informatino to the last aggregate NALU*/	
        p_parse_info->time[index-1] = p_parse_info->time[0];
        p_parse_info->time[0] = 0;
        p_parse_info->buffer_size[index] = 0;
    }
    else if(n_Type == 28)
    {
        /* FU-A fragmentation */

        // get information from header
        n_fragment_Sbit = (data[n_rtp_header_size+1] >> 7) & 0x1;
        n_fragment_Ebit = (data[n_rtp_header_size+1] >> 6) & 0x1; // Ebit is useless because of market bit
        n_fragment_Rbit = (data[n_rtp_header_size+1] >> 5) & 0x1;
        n_fragment_Type = (data[n_rtp_header_size+1] >> 0) & 0x1f;

        // update real NALU header from the indicator 
        data[n_rtp_header_size+1] = data[n_rtp_header_size+1] & 0x1f; // get type
        data[n_rtp_header_size+1] |= ((n_Fbit<<7) & 0x80); // get F bit
        data[n_rtp_header_size+1] |= ((n_NRI<<5) & 0x60); // get NRI bit
        if(n_fragment_Sbit == 1)
        {
            // start of fragment
            /* append NAL size header */
            p_parse_info->b_add_length[0] = KAL_TRUE;
            n_rtp_header_size+=1; // indicator
        }
        else
        {
            // not start of fragment
            // remove the NAL header
            p_parse_info->b_add_length[0] = KAL_FALSE;
            n_rtp_header_size+=2; // remove both indicator and FU header
        }

        p_parse_info->buffer_size[0] = size - n_rtp_header_size; 
        p_parse_info->buffer_addr[0] = (kal_uint32)&data[n_rtp_header_size];
        p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
    }
    else
    {
        /* reserved */
        /* drop this frame */
        VIDEO_ASSERT(0);
        p_parse_info->buffer_size[0] = 0;
    }

    return MEDIA_STATUS_OK;
}

static MEDIA_STATUS_CODE h264_rtp_parse_interleaved_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info)
{
    kal_bool b_mark;
    kal_uint32 n_timestamp;
    kal_uint16 n_sequence;
    kal_uint32 n_csrc_num;
    kal_uint32 n_rtp_header_size;
    kal_uint8 n_Fbit;
    kal_uint8 n_NRI;
    kal_uint8 n_Type;
    kal_uint8 n_fragment_Sbit;
    kal_uint8 n_fragment_Ebit;
    kal_uint8 n_fragment_Rbit;
    kal_uint8 n_fragment_Type;
    kal_uint32 n_size;
    kal_uint32 index = 0;
    kal_uint32 offset;
    static kal_uint32 n_prev_don;

    h264_rtp_free_prev_avalibale_pkt();
    
    if(size==0)
    {
        /* the last one packet */
        h264_rtp_get_all_available_pkt(p_parse_info);
        return MEDIA_STATUS_OK;
    }    

    /* parse rtp header */
    n_csrc_num = data[0]&0x0f;
    n_rtp_header_size = VIDEO_RTP_HEADER_SIZE + (n_csrc_num*VIDEO_RTP_HEADER_CSRC_SIZE);
    b_mark = (data[1]&0x80) ? KAL_TRUE: KAL_FALSE;
    n_sequence = (data[2]<<8) + data[3];
    n_timestamp = (data[4]<<24) + (data[5]<<16) + (data[6]<<8) + data[7];


    /* parse size */
    n_Fbit = (data[n_rtp_header_size] >> 7) & 0x1;
    n_NRI = (data[n_rtp_header_size] >> 5) & 0x3;
    n_Type = (data[n_rtp_header_size] >> 0) & 0x1f;
    if(n_Type == 25)
    {
        /* STAP-B aggregation*/
        offset = n_rtp_header_size;
        offset++;  /* NALU header */
        n_prev_don = (data[offset] << 8) + data[offset+1];
        offset+=2; /* DON */
        while(offset!=size)
        {
            n_size = (data[offset] << 8) + data[offset+1];
            p_parse_info->b_add_length[index] = KAL_TRUE;
            p_parse_info->buffer_size[index] = 	n_size;
            p_parse_info->buffer_addr[index] = (kal_uint32)data + offset + H264_RTP_AGGREGATE_LENGTH_SIZE;  
            p_parse_info->don_number[index] = n_prev_don + index;
            p_parse_info->time[index] = n_timestamp;	// Todo: the time is set only for the last NALU? Ans: No, time info must be kept for each NALU since a frame may divide into two STAP-Bs.
            offset+=(n_size+H264_RTP_AGGREGATE_LENGTH_SIZE);
            index++;
        }

        /* add and then retrive from interleaved buffer */
        h264_rtp_add_pkt(p_parse_info, index);
        h264_rtp_get_available_pkt(p_parse_info);
    }
    else if(n_Type == 28)
    {
        /* FU-A fragmentation */
        /* get information from header */
        n_fragment_Sbit = (data[n_rtp_header_size+1] >> 7) & 0x1;
        n_fragment_Ebit = (data[n_rtp_header_size+1] >> 6) & 0x1;
        n_fragment_Rbit = (data[n_rtp_header_size+1] >> 5) & 0x1;
        n_fragment_Type = (data[n_rtp_header_size+1] >> 0) & 0x1f;

        /* update real NALU header from the indicator  */
        data[n_rtp_header_size+1] = data[n_rtp_header_size+1] & 0x1f; // get type
        data[n_rtp_header_size+1] |= ((n_Fbit<<7) & 0x80); // get F bit
        data[n_rtp_header_size+1] |= ((n_NRI<<5) & 0x60); // get NRI bit
        if(n_fragment_Sbit == 1)
        {
            /*  start of fragment */
            /* append NAL size header */
            p_parse_info->b_add_length[0] = KAL_TRUE;
            n_rtp_header_size+=1; // indicator
        }
        else
        {
            /* not start of fragment */
            /* remove the NAL header */
            p_parse_info->b_add_length[0] = KAL_FALSE;
            n_rtp_header_size+=2; // remove both indicator and FU header
        }

        /* don got from previous FU-B packet */
        p_parse_info->don_number[0] = n_prev_don;
        p_parse_info->buffer_size[0] = size - n_rtp_header_size; 
        p_parse_info->buffer_addr[0] = (kal_uint32)data + n_rtp_header_size; 
        p_parse_info->time[0] = n_timestamp;

        /* add and then retrive from interleaved buffer */
        h264_rtp_add_fragment_pkt(p_parse_info, p_parse_info->b_add_length[0], ((n_fragment_Ebit!=0)?KAL_TRUE:KAL_FALSE));
        h264_rtp_get_available_pkt(p_parse_info);
    }
    else if(n_Type == 29)
    {
        /* FU-B fragmentation */
        /* get information from header */
        n_fragment_Sbit = (data[n_rtp_header_size+1] >> 7) & 0x1;
        n_fragment_Ebit = (data[n_rtp_header_size+1] >> 6) & 0x1;
        n_fragment_Rbit = (data[n_rtp_header_size+1] >> 5) & 0x1;
        n_fragment_Type = (data[n_rtp_header_size+1] >> 0) & 0x1f;

        n_prev_don = (data[n_rtp_header_size+2] << 8) + data[n_rtp_header_size+3];

        /* update real NALU header from the indicator  */
        data[n_rtp_header_size+3] = data[n_rtp_header_size+1] & 0x1f; // get type
        data[n_rtp_header_size+3] |= ((n_Fbit<<7) & 0x80); // get F bit
        data[n_rtp_header_size+3] |= ((n_NRI<<5) & 0x60); // get NRI bit
        if(n_fragment_Sbit == 1)
        {
            /* start of fragment */
            /* append NAL size header */
            p_parse_info->b_add_length[0] = KAL_TRUE;
            n_rtp_header_size+=3; // indicator, DON
        }
        else
        {
            /*  not start of fragment */
            VIDEO_ASSERT(0);  /* should not have FU-B but not the first one */
            /*  remove the NAL header */
            p_parse_info->b_add_length[0] = KAL_FALSE;
            n_rtp_header_size+=4; // remove both indicator and FU header, DON
        }

        p_parse_info->don_number[0] = n_prev_don;
        p_parse_info->buffer_size[0] = size - n_rtp_header_size; 
        p_parse_info->buffer_addr[0] = (kal_uint32)data + n_rtp_header_size;  
        p_parse_info->time[0] = n_timestamp;

        /* add and then retrive from interleaved buffer */
        h264_rtp_add_fragment_pkt(p_parse_info, p_parse_info->b_add_length[0], ((n_fragment_Ebit!=0)?KAL_TRUE:KAL_FALSE));
        h264_rtp_get_available_pkt(p_parse_info);
    }
    else if((n_Type == 26) || (n_Type == 27))
    {
        /* MTAP16/MTAP24 aggregation */
        kal_uint32 ts_byte = 2;
        kal_uint32 time_offset = 0;
        if(n_Type == 27)
        {
            ts_byte = 3;
        }
        offset = n_rtp_header_size;
        offset++;
        n_prev_don = (data[offset] << 8) + data[offset+1];
        offset+=2; /* DON */
        while(offset!=size)
        {
            n_size = (data[offset] << 8) + data[offset+1];
            p_parse_info->b_add_length[index] = KAL_TRUE; /* this is only for reference, for interleaved mode*/
            p_parse_info->buffer_size[index] = 	n_size - 1 - ts_byte; /* remove DOND and TS offset */
            p_parse_info->buffer_addr[index] = (kal_uint32)data + offset + H264_RTP_AGGREGATE_LENGTH_SIZE + 1 +ts_byte; /* DOND and TS offset*/  
            p_parse_info->don_number[index] = data[offset+H264_RTP_AGGREGATE_LENGTH_SIZE] + n_prev_don;
            if(ts_byte==2)
            {
            	    time_offset = data[offset+H264_RTP_AGGREGATE_LENGTH_SIZE+1+0] << 8;
            	    time_offset += (data[offset+H264_RTP_AGGREGATE_LENGTH_SIZE+1+1] << 0);
            }
            else
            {
                time_offset = data[offset+H264_RTP_AGGREGATE_LENGTH_SIZE+1+0] << 16;
                time_offset += (data[offset+H264_RTP_AGGREGATE_LENGTH_SIZE+1+1] << 8);
                time_offset += (data[offset+H264_RTP_AGGREGATE_LENGTH_SIZE+1+2] << 0);
            }
            p_parse_info->time[index] = n_timestamp + time_offset;
            offset+=(n_size+H264_RTP_AGGREGATE_LENGTH_SIZE);
            index++;
        }

        /* add and then retrive from interleaved buffer */
        h264_rtp_add_pkt(p_parse_info, index);
        h264_rtp_get_available_pkt(p_parse_info);
    }
    else
    {
        /* reserved */
        /* drop this frame */
        VIDEO_ASSERT(0);
        p_parse_info->buffer_size[0] = 0;
    }

    return MEDIA_STATUS_OK;
}


VIDEO_RTP_Driver H264_RTP_Driver = {
   h264_rtp_rst_time,
   h264_rtp_get_timescale,
   h264_rtp_set_timescale,
   h264_rtp_set_mode,
   h264_rtp_parse_config,
   h264_rtp_parse_first_frame,
   h264_rtp_parse_time_size,
};


#endif /* STREAM_SUPPORT*/
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/

