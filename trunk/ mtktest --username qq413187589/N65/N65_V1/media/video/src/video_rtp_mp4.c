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
 *   video_rtp_mp4.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG4 RTP parser
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

static MPEG4_RTP_CTRL_INFO g_mpeg4_rtp_ctrl_info;

static void mpeg4_rtp_rst_time(void);
static kal_uint32 mpeg4_rtp_get_timescale(void);
static void mpeg4_rtp_set_timescale(kal_uint32 time_scale);
static void mpeg4_rtp_set_mode(kal_uint32 mode);
static MEDIA_STATUS_CODE mpeg4_rtp_parse_config(kal_uint8 *data, kal_uint32 size);
static MEDIA_STATUS_CODE mpeg4_rtp_parse_vos(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_vos_size, kal_uint32 *p_rtp_header_size);
static kal_uint32 mpeg4_rtp_parse_frame(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_time_offset);
static MEDIA_STATUS_CODE mpeg4_rtp_parse_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info);

extern kal_int32 mpeg4_read_header_imformation(m4v_dec_im * hdr, kal_uint8 * data, kal_int32 bitcnt, kal_uint32 max_parse_data_size);
extern kal_int32 mpeg4_util_show_bits(kal_uint8 * data, kal_int32 bitcnt, kal_int32 num);
extern kal_int32 mpeg4_util_get_bits(kal_uint8 * data, kal_int32 *bitcnt, kal_int32 num);
extern kal_int32 mpeg4_util_show_word(kal_uint8 * a);


/* reset parameters */
static void mpeg4_rtp_rst_time(void)
{
    g_mpeg4_rtp_ctrl_info.time_offset= 0xffffffff;  
}

/* get time scale used in rtp header */
static kal_uint32 mpeg4_rtp_get_timescale(void)
{
    return g_mpeg4_rtp_ctrl_info.time_scale;
}

/* set time scale used in rtp header */
static void mpeg4_rtp_set_timescale(kal_uint32 time_scale)
{
    g_mpeg4_rtp_ctrl_info.time_scale = time_scale;
}

/* no diffrent mode */
static void mpeg4_rtp_set_mode(kal_uint32 mode)
{
    return;
}

/* parse vos information from config data */
static MEDIA_STATUS_CODE mpeg4_rtp_parse_config(kal_uint8 *data, kal_uint32 size)
{
    m4v_dec_im hdr;
    kal_int32 bitcnt = 0;
    kal_uint32 vos_size = 0;
    kal_uint32 index;
    kal_uint32 data0, data1;
    kal_uint8 real_data;

    /* translate from ascii to binary and store to vos buffer */
     if(size > MAX_VOS_LENGTH)
    {   
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
        return VIDEO_ERROR;
    } 

    /* 2 ascii code translate to one byte*/
    if((size&0x1)!=0)
    {
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
        return VIDEO_ERROR;
    }
    
    for(index = 0; index < (size/2); index++)
    {
        real_data = data[index*2]; 
        if((real_data >= '0') && (real_data <= '9'))
        {
            data0 = real_data - '0';
        }
        else if((real_data >= 'a') && (real_data <= 'f'))
        {
            data0 = real_data - 'a' + 10;
        }
        else if((real_data >= 'A') && (real_data <= 'F'))
        {
            data0 = real_data - 'A' + 10;
        }
        else
        {
            VIDEO_ASSERT(0);
            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
            return VIDEO_ERROR;
        }
        
        real_data = data[(index*2) + 1]; 
        if((real_data >= '0') && (real_data <= '9'))
        {
            data1 = real_data - '0';
        }
        else if((real_data >= 'a') && (real_data <= 'f'))
        {
            data1 = real_data - 'a' + 10;
        }
         else if((real_data >= 'A') && (real_data <= 'F'))
        {
            data1 = real_data - 'A' + 10;
        }
        else
        {
            VIDEO_ASSERT(0);
            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
            return VIDEO_ERROR;
        }
        
        g_mpeg4_dec_info_ptr->VOS_DATA.vos_data[index] = (data0<<4) + data1;
    }
    //g_mpeg4_dec_info_ptr->VOS = &g_mpeg4_dec_info_ptr->VOS_DATA;
     

    /* parse vos information */
    bitcnt = mpeg4_read_header_imformation(&hdr, g_mpeg4_dec_info_ptr->VOS_DATA.vos_data, bitcnt, (size/2)*8);
    if (bitcnt == -1)
    {
        /* parse error */
        VIDEO_ASSERT(0);		
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_BITSTREAM_ERROR;
        if (((hdr.width * hdr.height) > (DEC_MAX_FRAME_WIDTH * DEC_MAX_FRAME_HEIGHT))
                || (hdr.width * hdr.height == 0)) {
		    g_mpeg4_dec_info_ptr->width = hdr.width;
		    g_mpeg4_dec_info_ptr->height = hdr.height;
        }
        return VIDEO_ERROR;
    }
    else if (bitcnt == -2)
    {
        /* No VOL */
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_BITSTREAM_ERROR;
        return VIDEO_ERROR;
    }

    /* store the time resolution infomration needed for later parsing */
    g_mpeg4_rtp_ctrl_info.time_increment_length = hdr.time_increment_length;
    g_mpeg4_rtp_ctrl_info.time_increment_resolution = hdr.time_increment;

    /* calculate anc check vos size*/
    vos_size = bitcnt>>3;
    if((bitcnt&0x7) !=0)
    {
        vos_size++;
    }

    if(vos_size > MAX_VOS_LENGTH)
    {   
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
        return VIDEO_ERROR;
    } 

    g_mpeg4_dec_info_ptr->VOS_DATA.size = vos_size;
    g_mpeg4_dec_info_ptr->real_width = hdr.width;
    g_mpeg4_dec_info_ptr->real_height = hdr.height;
    hdr.width = (hdr.width + 0xf) & (~0xf);
    hdr.height = (hdr.height + 0xf) & (~0xf);
    g_mpeg4_dec_info_ptr->width = hdr.width;
    g_mpeg4_dec_info_ptr->height = hdr.height;
    
    return MEDIA_STATUS_OK;
}


/* parse vos information */
static MEDIA_STATUS_CODE mpeg4_rtp_parse_vos(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_vos_size, kal_uint32 *p_rtp_header_size)
{
    m4v_dec_im hdr;
    kal_int32 bitcnt = 0;
    kal_uint32 vos_size = 0;
    kal_uint32 n_csrc_num;

    /* parse rtp header */
    n_csrc_num = data[0]&0x0f;
    if ((VIDEO_RTP_HEADER_SIZE + (n_csrc_num*VIDEO_RTP_HEADER_CSRC_SIZE))>=size) {
        *p_rtp_header_size = 1;
        return VIDEO_ERROR;		
    }

    *p_rtp_header_size = VIDEO_RTP_HEADER_SIZE + (n_csrc_num*VIDEO_RTP_HEADER_CSRC_SIZE);

    /* parse vos information */
    bitcnt = mpeg4_read_header_imformation(&hdr, &data[*p_rtp_header_size], bitcnt, (size-(*p_rtp_header_size))*8);
    if (bitcnt == -1)
    {
        /* parse error */
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_BITSTREAM_ERROR;
        return VIDEO_ERROR;
    }
    else if (bitcnt == -2)
    {
        /* No VOL */
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_BITSTREAM_ERROR;
        return VIDEO_ERROR;
    }

    /* store the time resolution infomration needed for later parsing */
    g_mpeg4_rtp_ctrl_info.time_increment_length = hdr.time_increment_length;
    g_mpeg4_rtp_ctrl_info.time_increment_resolution = hdr.time_increment;

    /* calculate anc check vos size*/
    vos_size = bitcnt>>3;
    if((bitcnt&0x7) !=0)
    {
        vos_size++;
    }

    if(vos_size > MAX_VOS_LENGTH)
    {   
        VIDEO_ASSERT(0);
        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
        return VIDEO_ERROR;
    } 

    kal_mem_cpy(g_mpeg4_dec_info_ptr->VOS_DATA.vos_data, &data[*p_rtp_header_size], vos_size);
    g_mpeg4_dec_info_ptr->VOS_DATA.size = vos_size;
    //g_mpeg4_dec_info_ptr->VOS = &g_mpeg4_dec_info_ptr->VOS_DATA;
    
    /* the parsed size is vos size (in bytes) plus rtp header size*/
    *p_vos_size = vos_size + (*p_rtp_header_size);

    return MEDIA_STATUS_OK;
}

/* return real VOP length, p_time_offset if another VOP exist.
    (*p_time_offset) is the time between the current VOP and the next VOP*/
static kal_uint32 mpeg4_rtp_parse_frame(kal_uint8 *data, kal_uint32 size, kal_uint32 *p_time_offset)
{
    kal_uint32 index;
    kal_uint32 vop_size;
    kal_uint16 prev_rtp_time_increment;
    kal_uint16 cur_rtp_time_increment;
    kal_uint16 time_base = 0;
    kal_int32 bitcnt = 0;
    kal_uint32 vop_coding_type;
    kal_uint32 count;
    kal_uint32 vop_start_pos;

    /* Group_of_VideoObjectPlane() */
    if (mpeg4_util_show_word(data + (bitcnt >> 3)) == GOP_START_CODE)
    {
        bitcnt += 32;
        count = 0;
        while (mpeg4_util_show_word(data + (bitcnt >> 3)) != VOP_START_CODE && count < 50)
        {
            bitcnt += 8;
            count++;
        }
    }

    /* If GOP is present, the follwing should be VideoObjectPlane() */
    /* Note that GOP is not present, the following may not be VOP (one VOP may divide as multiple packet)*/
    if ((bitcnt!=0) && (mpeg4_util_show_word(data + (bitcnt >> 3)) != VOP_START_CODE))
    {
        ASSERT(0);
        VIDEO_ASSERT(0);
        *p_time_offset = 0;
        return 0;
    }

    vop_start_pos = bitcnt >> 3;
    vop_size = size;
    
    /* Parse whether there is another VOP in the same packet */    
    if(size > (MPEG4_RTP_VOP_HEADER_SIZE+MPEG4_RTP_VOP_HEADER_SIZE+1))
    {
        /* scan VOP_START_CODE through the whole packet*/
        for(index = (vop_start_pos + MPEG4_RTP_VOP_HEADER_SIZE); index < (size-(MPEG4_RTP_VOP_HEADER_SIZE-1)); index++)
        {
            if((data[index] == 0x00) && (data[index+1]==0x00) && (data[index+2]==0x01) && (data[index+3]==0xb6))
            {
                /* from index is another VOP */
                vop_size = index;

                /* calculate time during the two VOP */
                /* time information is the first VOP */
                bitcnt = 0;
                vop_coding_type = mpeg4_util_get_bits(&data[vop_start_pos + MPEG4_RTP_VOP_HEADER_SIZE], &bitcnt, 2); /*0: I frame, 1: P frame*/
                while (mpeg4_util_show_bits(&data[vop_start_pos + MPEG4_RTP_VOP_HEADER_SIZE], bitcnt, 1) != 0)
                {
                    bitcnt++;
                }
                bitcnt += 2; // time_mod + marker
                prev_rtp_time_increment = mpeg4_util_get_bits(&data[vop_start_pos + MPEG4_RTP_VOP_HEADER_SIZE], &bitcnt, g_mpeg4_rtp_ctrl_info.time_increment_length);

                /* time information is the second VOP */
                bitcnt = 0;
                vop_coding_type = mpeg4_util_get_bits(&data[index + MPEG4_RTP_VOP_HEADER_SIZE], &bitcnt, 2); /*0: I frame, 1: P frame*/
                while (mpeg4_util_show_bits(&data[index + MPEG4_RTP_VOP_HEADER_SIZE], bitcnt, 1) != 0)
                {
                    bitcnt++;
                    time_base++;
                }
                bitcnt += 2; // time_mod + marker
                cur_rtp_time_increment = mpeg4_util_get_bits(&data[index + MPEG4_RTP_VOP_HEADER_SIZE], &bitcnt, g_mpeg4_rtp_ctrl_info.time_increment_length);

                /* difference time */
                if(cur_rtp_time_increment > prev_rtp_time_increment)
                {
                    if (g_mpeg4_rtp_ctrl_info.time_increment_resolution == 0) {	// Trick to recover.
                        if (g_mpeg4_rtp_ctrl_info.time_scale != 0) {
                             g_mpeg4_rtp_ctrl_info.time_increment_resolution = g_mpeg4_rtp_ctrl_info.time_scale;
                         } else if (g_mpeg4_rtp_ctrl_info.time_increment_length != 0) {
                              g_mpeg4_rtp_ctrl_info.time_increment_resolution = 1<<g_mpeg4_rtp_ctrl_info.time_increment_length;
                         } else {	// Error: Seems impossible.
                              g_mpeg4_rtp_ctrl_info.time_increment_resolution = 1000;
                              g_mpeg4_rtp_ctrl_info.time_scale = g_mpeg4_rtp_ctrl_info.time_increment_resolution;
                         }
                    }
                    *p_time_offset = time_base*1000 + (((cur_rtp_time_increment-prev_rtp_time_increment)*1000)/g_mpeg4_rtp_ctrl_info.time_increment_resolution); /* ms */
                    *p_time_offset = VIDEO_ANYBASE_TO_ANYBASE(*p_time_offset, 1000, g_mpeg4_rtp_ctrl_info.time_scale);
                }
                else
                {
                    if(time_base==0)
                    {
                        /* the time will be negative */
                        VIDEO_ASSERT(0);
                        // tricky to add 1
                        time_base = 1;
                    }
                    *p_time_offset = (((time_base * g_mpeg4_rtp_ctrl_info.time_increment_resolution-  prev_rtp_time_increment)+cur_rtp_time_increment)*1000)/g_mpeg4_rtp_ctrl_info.time_increment_resolution; /* ms */
                    *p_time_offset = VIDEO_ANYBASE_TO_ANYBASE(*p_time_offset, 1000, g_mpeg4_rtp_ctrl_info.time_scale);
                }
                
                break;
            }
        }
    }

    return vop_size;
}


/* p_time 0 when divide to multiple pkt (not the last pkts)*/
static MEDIA_STATUS_CODE mpeg4_rtp_parse_time_size(kal_uint8 *data, kal_uint32 size, VIDEO_RTP_PARSE_INFO *p_parse_info)
{
    kal_bool b_mark;
    kal_uint32 n_timestamp;
    kal_uint16 n_sequence;
    kal_uint32 index = 0;
    kal_uint32 n_time_offset;
    kal_uint32 n_vop_size;
    kal_uint32 n_remain_size;
    kal_uint32 n_csrc_num;
    kal_uint32 n_rtp_header_size;

    if(size==0)
    {
        /* the last one packet */
        p_parse_info->buffer_size[0] = 0;
        return MEDIA_STATUS_OK;
    }    

    /* parse rtp header */
    n_csrc_num = data[0]&0x0f;
    n_rtp_header_size = VIDEO_RTP_HEADER_SIZE + (n_csrc_num*VIDEO_RTP_HEADER_CSRC_SIZE);
    if (n_rtp_header_size >= size) {
        p_parse_info->buffer_size[index] = 1;
        p_parse_info->buffer_addr[index] = (kal_uint32)&data[1];
        p_parse_info->b_add_length[index] = KAL_FALSE;
        p_parse_info->buffer_size[index+1] = 0;  /* the last one should be 0 */
        return MEDIA_STATUS_OK;
    }
    b_mark = (data[1]&0x80) ? KAL_TRUE: KAL_FALSE;
    n_sequence = (data[2]<<8) + data[3];
    n_timestamp = (data[4]<<24) + (data[5]<<16) + (data[6]<<8) + data[7];
    
    /* start to parse */
    if(b_mark == KAL_TRUE)
    {
        if(g_mpeg4_rtp_ctrl_info.time_offset == 0xffffffff)
        {
            /* the first VOP*/
            p_parse_info->time[index] = 0xffffffff;
        }
        else
        {
            p_parse_info->time[index] = n_timestamp - g_mpeg4_rtp_ctrl_info.time_offset;
        }
        g_mpeg4_rtp_ctrl_info.time_offset = n_timestamp;

        /* parse rtp data, check another VOP exsit or not  */
        n_remain_size = size - n_rtp_header_size;
        n_vop_size = 0;
        n_vop_size = mpeg4_rtp_parse_frame(&data[size-n_remain_size], n_remain_size, &n_time_offset);
        while((index < (VIDEO_RTP_MAX_PARSE_ITEM-2)) && (n_vop_size != n_remain_size))
        {
            /* another VOP */
            if (n_vop_size>=size) {
               p_parse_info->buffer_size[index] = 1;
               p_parse_info->buffer_addr[index] = (kal_uint32)&data[size-1];
               p_parse_info->b_add_length[index] = KAL_FALSE;
               p_parse_info->buffer_size[index+1] = 0;  /* the last one should be 0 */
               return MEDIA_STATUS_OK;
            }
            p_parse_info->buffer_size[index] = n_vop_size;
            p_parse_info->buffer_addr[index] = (kal_uint32)&data[size-n_remain_size];
            p_parse_info->b_add_length[index] = KAL_FALSE;
            p_parse_info->time[index+1] = n_time_offset;  /* time between the first and the second VOP */
            n_remain_size -= n_vop_size;
            index++;
            if (size<n_remain_size) {
               p_parse_info->buffer_size[index] = 1;
               p_parse_info->buffer_addr[index] = (kal_uint32)&data[size-1];
               p_parse_info->b_add_length[index] = KAL_FALSE;
               p_parse_info->buffer_size[index+1] = 0;  /* the last one should be 0 */
               return MEDIA_STATUS_OK;
            }			
            n_vop_size = mpeg4_rtp_parse_frame(&data[size-n_remain_size], n_remain_size, &n_time_offset);
        }
        p_parse_info->buffer_size[index] = n_remain_size; /* in case index > max check */
        p_parse_info->buffer_addr[index] = (kal_uint32)&data[size-n_remain_size];
        p_parse_info->b_add_length[index] = KAL_FALSE;
        p_parse_info->buffer_size[index+1] = 0;  /* the last one should be 0 */
    }
    else
    {
        p_parse_info->time[index] = 0;  /* time = 0 means not the last packet for the current VOP(marker = 0)*/
        p_parse_info->buffer_size[index] = size - n_rtp_header_size; 
        p_parse_info->buffer_addr[index] = (kal_uint32)&data[n_rtp_header_size];
        p_parse_info->b_add_length[index] = KAL_FALSE;
        p_parse_info->buffer_size[index+1] = 0;  /* the last one should be 0 */
    }
    
    return MEDIA_STATUS_OK;
}


VIDEO_RTP_Driver MPEG4_RTP_Driver = {
   mpeg4_rtp_rst_time,
   mpeg4_rtp_get_timescale,
   mpeg4_rtp_set_timescale,
   mpeg4_rtp_set_mode,
   mpeg4_rtp_parse_config,
   mpeg4_rtp_parse_vos,
   mpeg4_rtp_parse_time_size,
};
	
#endif /* STREAM_SUPPORT*/
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/

