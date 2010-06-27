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
 *   video_rtp_h263.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   H263 RTP parser
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

static H263_RTP_CTRL_INFO g_h263_rtp_ctrl_info;

static void h263_rtp_rst_time(void);
static kal_uint32 h263_rtp_get_timescale(void);
static void h263_rtp_set_timescale(kal_uint32 time_scale);
static void h263_rtp_set_mode(kal_uint32 mode);
static MEDIA_STATUS_CODE h263_rtp_parse_config(kal_uint8 *data, kal_uint32 size);
static MEDIA_STATUS_CODE h263_rtp_parse_first_frame(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_vos_size, kal_uint32 *p_rtp_header_size);
static MEDIA_STATUS_CODE h263_rtp_parse_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info);

/* reset parameters */
static void h263_rtp_rst_time(void)
{
    g_h263_rtp_ctrl_info.time_offset= 0xffffffff;
}

/* get time scale used in rtp header */
static kal_uint32 h263_rtp_get_timescale(void)
{
    return g_h263_rtp_ctrl_info.time_scale;
}

/* set time scale used in rtp header */
static void h263_rtp_set_timescale(kal_uint32 time_scale)
{
    g_h263_rtp_ctrl_info.time_scale = time_scale;
}

/* no diffrent mode */
static void h263_rtp_set_mode(kal_uint32 mode)
{
    return;
}

/* parse vos information from config data */
static MEDIA_STATUS_CODE h263_rtp_parse_config(kal_uint8 *data, kal_uint32 size)
{
    /* no VOS data in RTSP config data */
    return MEDIA_STATUS_OK;
}

/* parse first frame information */
static MEDIA_STATUS_CODE h263_rtp_parse_first_frame(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_vos_size, kal_uint32 *p_rtp_header_size)
{
    kal_uint32 n_csrc_num;
    
    /* parse rtp header */
    n_csrc_num = data[0]&0x0f;
    if ((VIDEO_RTP_HEADER_SIZE + (n_csrc_num*VIDEO_RTP_HEADER_CSRC_SIZE))>=size)
        *p_rtp_header_size = 1;
    else 
        *p_rtp_header_size = VIDEO_RTP_HEADER_SIZE + (n_csrc_num*VIDEO_RTP_HEADER_CSRC_SIZE);

    /* no VOS data in the first packet, just return the parsed size as zero */
    *p_vos_size = 0;
    
    return MEDIA_STATUS_OK;
}


/* for h263, one packet contains only one frame, but one frame may contain multiple packets */
static MEDIA_STATUS_CODE h263_rtp_parse_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info)
{
    kal_bool b_mark;
    kal_uint32 n_timestamp;
    kal_uint16 n_sequence;
    kal_uint32 n_csrc_num;
    kal_uint32 n_rtp_header_size;
    kal_bool b_pbit;
    kal_bool b_vbit;
    kal_uint32 n_plen;

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

    if (n_rtp_header_size>=size) {
        p_parse_info->buffer_size[0] = size - 1; 
        p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
        p_parse_info->buffer_addr[0] = (kal_uint32)&data[1];
        p_parse_info->b_add_length[0] = KAL_FALSE;
        return MEDIA_STATUS_OK;
    }

    /* parse time */
    if(b_mark == KAL_TRUE)
    {
        if(g_h263_rtp_ctrl_info.time_offset == 0xffffffff)
        {
            /* the first VOP*/
            p_parse_info->time[0] = 0xffffffff;
        }
        else
        {
            p_parse_info->time[0] = n_timestamp - g_h263_rtp_ctrl_info.time_offset;
        }

        g_h263_rtp_ctrl_info.time_offset = n_timestamp;
    }
    else
    {
        p_parse_info->time[0] = 0;  /* time = 0 means not the last packet for the current VOP(marker = 0)*/    
    }

    /* parse size */
    b_pbit = (data[n_rtp_header_size] & 0x04) ? KAL_TRUE : KAL_FALSE;
    b_vbit = (data[n_rtp_header_size] & 0x02) ? KAL_TRUE : KAL_FALSE;
    n_plen = (data[n_rtp_header_size] & 0x01) << 5;

    if ((n_rtp_header_size+1)>=size) {
	p_parse_info->buffer_size[0] = size - 1; 
	p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
	p_parse_info->buffer_addr[0] = (kal_uint32)&data[1];
	p_parse_info->b_add_length[0] = KAL_FALSE;
	return MEDIA_STATUS_OK;
    }
	
    n_plen += ((data[n_rtp_header_size+1] & 0xf8) >> 3);

    if ((n_rtp_header_size + H263_RTP_HEADER_SIZE)>=size)
    {
	p_parse_info->buffer_size[0] = size - 1; 
	p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
	p_parse_info->buffer_addr[0] = (kal_uint32)&data[1];
	p_parse_info->b_add_length[0] = KAL_FALSE;
	return MEDIA_STATUS_OK;
    }
	
    n_rtp_header_size += H263_RTP_HEADER_SIZE;	
    if(b_vbit == KAL_TRUE)
    {
	if ((n_rtp_header_size + H263_RTP_VRC_HEADER_SIZE)>=size) {
		p_parse_info->buffer_size[0] = size - 1; 
		p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
		p_parse_info->buffer_addr[0] = (kal_uint32)&data[1];
		p_parse_info->b_add_length[0] = KAL_FALSE;
		return MEDIA_STATUS_OK;
	}
    
       n_rtp_header_size += H263_RTP_VRC_HEADER_SIZE;
    }
    if ((n_rtp_header_size + n_plen)>=size) {
	p_parse_info->buffer_size[0] = size - 1; 
	p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
	p_parse_info->buffer_addr[0] = (kal_uint32)&data[1];
	p_parse_info->b_add_length[0] = KAL_FALSE;
	return MEDIA_STATUS_OK;
    }
    n_rtp_header_size+=n_plen;
    /* add the removed two bytes of zero in packet header */
    if(b_pbit == KAL_TRUE)
    {
	 if (n_rtp_header_size<2)
	 {
            p_parse_info->buffer_size[0] = size - 1; 
            p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
            p_parse_info->buffer_addr[0] = (kal_uint32)&data[1];
            p_parse_info->b_add_length[0] = KAL_FALSE;
	     return MEDIA_STATUS_OK;
	 }
    
        n_rtp_header_size-=2;
        data[n_rtp_header_size] = 0x00;
        data[n_rtp_header_size+1] = 0x00;
    }

    p_parse_info->buffer_size[0] = size - n_rtp_header_size; 
    p_parse_info->buffer_size[1] = 0;  /* the last one should be 0 */
    p_parse_info->buffer_addr[0] = (kal_uint32)&data[n_rtp_header_size];
    p_parse_info->b_add_length[0] = KAL_FALSE;

    return MEDIA_STATUS_OK;
}


VIDEO_RTP_Driver H263_RTP_Driver = {
   h263_rtp_rst_time,
   h263_rtp_get_timescale,
   h263_rtp_set_timescale,
   h263_rtp_set_mode,
   h263_rtp_parse_config,
   h263_rtp_parse_first_frame,
   h263_rtp_parse_time_size,
};


#endif /* STREAM_SUPPORT*/
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/

