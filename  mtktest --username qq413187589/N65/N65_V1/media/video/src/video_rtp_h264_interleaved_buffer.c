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
 *   video_rtp_h264_interleaved_buffer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   H264 RTP interleaved mode buffer control 
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

static H264_RTP_INTERLEAVED_INFO g_h264_interleaved_info;                     /* interleaved mode parameters */

//static kal_uint8  g_h264_interleaved_buffer[H264_RTP_INTERLEAVED_BUFFER_SIZE];  /* ADM memory */

static kal_uint8* h264_rtp_get_interleave_buff(kal_uint32 size);
static H264_RTP_DON_CTRL_BLOCK* h264_rtp_get_don_cb(void);
static H264_RTP_DON_CTRL_BLOCK* h264_rtp_construct_don_node(kal_uint32 start_addr, kal_uint32 size, kal_uint32 time, kal_uint32 don, kal_bool b_first, kal_bool b_last);
static void h264_rtp_init_list(void);
static void h264_rtp_add_fragment_list(H264_RTP_DON_CTRL_BLOCK *p_ctrl_block);
static void h264_rtp_add_don_list(H264_RTP_DON_CTRL_BLOCK *p_ctrl_block);
static H264_RTP_DON_CTRL_BLOCK* h264_rtp_retrive_don_list(void);
static H264_RTP_DON_CTRL_BLOCK* h264_rtp_retrive_all_don_list(void);
static void h264_rtp_free_don_list(void);
extern void h264_rtp_init_interleaved_info(kal_uint32 deinterleave_buffer_depth, kal_uint32 max_don_diff);
extern void h264_rtp_add_fragment_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info, kal_bool b_first, kal_bool b_last);
extern void h264_rtp_add_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info, kal_uint32 size);
extern void h264_rtp_get_available_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info);
extern void h264_rtp_get_all_available_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info);
extern void h264_rtp_free_prev_avalibale_pkt(void);

/////////////////////////////////////////////////////////////
//
//                                 API provides to parser
//
/////////////////////////////////////////////////////////////

/* initialize interleaved mode parameters, the input parameters are set by server */
void h264_rtp_init_interleaved_info(kal_uint32 deinterleave_buffer_depth, kal_uint32 max_don_diff)
{
    g_h264_interleaved_info.deinterleave_buffer_depth = deinterleave_buffer_depth;
    g_h264_interleaved_info.max_don_diff = max_don_diff;
    g_h264_interleaved_info.max_don = 0;
    g_h264_interleaved_info.total_NAUL = 0;
    g_h264_interleaved_info.time_offset = 0xffffffff;
    /* initailize list for de-interleave buffer */
    h264_rtp_init_list();
    g_h264_interleaved_info.p_buffer = (kal_uint8*)extmem_get_buffer(H264_RTP_INTERLEAVED_BUFFER_SIZE);
    if(g_h264_interleaved_info.b_init_adm==KAL_FALSE)
    {
        g_h264_interleaved_info.adm_id = kal_adm_create(g_h264_interleaved_info.p_buffer, H264_RTP_INTERLEAVED_BUFFER_SIZE, NULL,KAL_FALSE);
    }
}

/* Add one fragment packet to de-interleaved buffer, only one fragment packet can be added one time */
void h264_rtp_add_fragment_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info, kal_bool b_first, kal_bool b_last)
{
    H264_RTP_DON_CTRL_BLOCK *p_ctrl_block = NULL;

    /* get resource for the fragment packet */
    p_ctrl_block = h264_rtp_construct_don_node(p_rtp_parse_info->buffer_addr[0], p_rtp_parse_info->buffer_size[0], 
                                                                      p_rtp_parse_info->time[0], p_rtp_parse_info->don_number[0], 
                                                                      b_first, b_last);

    /* add fragment packet to list */		
    h264_rtp_add_fragment_list(p_ctrl_block);
}

/* Add "size" number of packets(not fragment packets) to de-interleaved buffer */
void h264_rtp_add_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info, kal_uint32 size)
{
    H264_RTP_DON_CTRL_BLOCK *p_ctrl_block = NULL;
    kal_uint32 index;

    /* Add all the packets to list, note that since these packets are not fragment, b_first and b_last are true */ 
    for(index = 0; index < size; index++)
    {
        /* get resource for the fragment packet */
        p_ctrl_block = h264_rtp_construct_don_node(p_rtp_parse_info->buffer_addr[index], p_rtp_parse_info->buffer_size[index], 
                                                                          p_rtp_parse_info->time[index], p_rtp_parse_info->don_number[index], 
                                                                          KAL_TRUE, KAL_TRUE);
        /* add packet to list */		
        h264_rtp_add_don_list(p_ctrl_block);
    }
}


/* get available packets from de-interleaved buffer (according to don and buffer depth), 
    all aalibale packet will be filled in the input param */
void h264_rtp_get_available_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info)
{
    kal_uint32 index = 0;
    H264_RTP_DON_CTRL_BLOCK* p_ctrl_block = h264_rtp_retrive_don_list();

    /* translate from list format to packet information*/
    while(p_ctrl_block!=NULL)
    {
        /* reconstruct new list, and return to caller */
        p_rtp_parse_info->b_add_length[index] = p_ctrl_block->b_first;
        p_rtp_parse_info->buffer_addr[index] = p_ctrl_block->start_addr;
        p_rtp_parse_info->buffer_size[index] = p_ctrl_block->size;
        p_rtp_parse_info->time[index] = p_ctrl_block->time;
        p_ctrl_block = p_ctrl_block->next;
        index++;
    }

    /* set the last one as 0 so that application knows the end */
    p_rtp_parse_info->buffer_size[index] = 0;
}


/* get all packets from de-interleaved buffer (maybe application ends, so do not consider don and buffer depth), 
    all aalibale packet will be filled in the input param */
void h264_rtp_get_all_available_pkt(VIDEO_RTP_PARSE_INFO* p_rtp_parse_info)
{
    kal_uint32 index = 0;
    H264_RTP_DON_CTRL_BLOCK* p_ctrl_block = h264_rtp_retrive_all_don_list();

    /* translate from list format to packet information*/
    while(p_ctrl_block!=NULL)
    {
        /* reconstruct new list, and return to caller */
        p_rtp_parse_info->b_add_length[index] = p_ctrl_block->b_first;
        p_rtp_parse_info->buffer_addr[index] = p_ctrl_block->start_addr;
        p_rtp_parse_info->buffer_size[index] = p_ctrl_block->size;
        p_rtp_parse_info->time[index] = p_ctrl_block->time;
        p_ctrl_block = p_ctrl_block->next;
        index++;
    }

    /* set the last one as 0 so that application knows the end */
    p_rtp_parse_info->buffer_size[index] = 0;
}


/* free the previous got avalible packet resource (application has already copied the data out )*/
void h264_rtp_free_prev_avalibale_pkt(void)
{
    /* free don list resource */
    h264_rtp_free_don_list();
}


/////////////////////////////////////////////////////////////
//
//                                 Internal use functions
//
/////////////////////////////////////////////////////////////

/* get interleaved buffer to store packet data */
static kal_uint8* h264_rtp_get_interleave_buff(kal_uint32 size)
{
    /* Get interleaved data buffer from ADM */
    kal_uint8 *p_buff = kal_adm_internal_alloc(g_h264_interleaved_info.adm_id, size, __FILE__, __LINE__);
    if(p_buff==NULL)
    {
        ASSERT(0);
    }
    return p_buff;
}

/* get don list control block */
static H264_RTP_DON_CTRL_BLOCK* h264_rtp_get_don_cb(void)
{
    /* Get control block from ADM */
    H264_RTP_DON_CTRL_BLOCK *p_cb = kal_adm_internal_alloc(g_h264_interleaved_info.adm_id, sizeof(H264_RTP_DON_CTRL_BLOCK), __FILE__, __LINE__);
    if(p_cb==NULL)
    {
        ASSERT(0);
    }
    p_cb->next = NULL;
    return p_cb;
}

/* construct one don node config all requeired information
    It includes get control block, de-interlevaed buffer, and store data to control blcok and de-interleaved buffer  */
static H264_RTP_DON_CTRL_BLOCK* h264_rtp_construct_don_node(kal_uint32 start_addr, kal_uint32 size, kal_uint32 time, kal_uint32 don, kal_bool b_first, kal_bool b_last)
{
    /* Construct DON ctrl block and copy data to interleaved buffer */
    H264_RTP_DON_CTRL_BLOCK* p_ctrl_block = h264_rtp_get_don_cb();
    kal_uint8 *p_buff = h264_rtp_get_interleave_buff(size);
    kal_mem_cpy(p_buff, (void*)start_addr, size);
    p_ctrl_block->start_addr = (kal_uint32)p_buff;
    p_ctrl_block->size = size;
    p_ctrl_block->time = time;
    p_ctrl_block->don = don;
    p_ctrl_block->b_first = b_first;
    p_ctrl_block->b_last = b_last;
    p_ctrl_block->next = NULL;

    return p_ctrl_block;
}

/* Init list */
static void h264_rtp_init_list(void)
{
	/* Initialize parameters */
	g_h264_interleaved_info.p_don_list_head = NULL;
	g_h264_interleaved_info.p_fragment_list_head = NULL;
	g_h264_interleaved_info.p_retrive_don_list_head = NULL;
}

/* Add one control block to fragment list 
    Note that if it is the last fragment, add to don list action will be done in this function */
static void h264_rtp_add_fragment_list(H264_RTP_DON_CTRL_BLOCK *p_ctrl_block)
{
    H264_RTP_DON_CTRL_BLOCK *p_cur_block;

    /* Add ctrl block to fragment list */    
    if(g_h264_interleaved_info.p_fragment_list_head==NULL)
    {
        g_h264_interleaved_info.p_fragment_list_head = p_ctrl_block;
        p_ctrl_block->next = NULL;
    }
    else
    {
        /* Add current packet to the end of list */
        p_cur_block = g_h264_interleaved_info.p_fragment_list_head;
        while(p_cur_block->next!=NULL)
        {
            p_cur_block = p_cur_block->next;
        }
        p_cur_block->next = p_ctrl_block;
        p_ctrl_block->next = NULL;
    }

    /* Add to complete list if current one is the last framgemet*/
    if(p_ctrl_block->b_last==KAL_TRUE)
    {
        h264_rtp_add_don_list(g_h264_interleaved_info.p_fragment_list_head);
        g_h264_interleaved_info.p_fragment_list_head = NULL;
    }
}


/* Add complete control block to don list 
    Note that the control block may link a list of fragment control blocks after it */
static void h264_rtp_add_don_list(H264_RTP_DON_CTRL_BLOCK *p_ctrl_block)
{
    H264_RTP_DON_CTRL_BLOCK *p_cur_block;
    H264_RTP_DON_CTRL_BLOCK *p_next_block;
    H264_RTP_DON_CTRL_BLOCK *p_ctrl_block_end;
    kal_bool b_update = KAL_FALSE;

    /* search for the end of ctrl list first (it may be a fragment list ) */
    p_cur_block = p_ctrl_block;
    while(p_cur_block->next!=NULL)
    {
        p_cur_block = p_cur_block->next;
    }
    p_ctrl_block_end = p_cur_block;

    /* Add ctrl block to don list */
    if(g_h264_interleaved_info.p_don_list_head==NULL)
    {
        g_h264_interleaved_info.p_don_list_head = p_ctrl_block;
        p_ctrl_block_end->next = NULL;
    }
    else
    {
        /* compare DON and add to correct position of list */
        p_cur_block = g_h264_interleaved_info.p_don_list_head;
        if(p_cur_block->don > p_ctrl_block->don)
        {
            /* Add to head */
            p_next_block = g_h264_interleaved_info.p_don_list_head;
            g_h264_interleaved_info.p_don_list_head = p_ctrl_block;
            p_ctrl_block_end->next = p_next_block;
            b_update = KAL_TRUE;
        }
        else
        {
            /* Insert to right position */	
            while(p_cur_block->next!=NULL)
            {
                p_next_block = p_cur_block->next;
                if(p_next_block->don > p_ctrl_block->don)
                {
                    p_cur_block->next = p_ctrl_block;
                    p_ctrl_block_end->next = p_next_block;
                    b_update = KAL_TRUE;
                    break;
                }
                p_cur_block = p_next_block;
            }
        }

        if(b_update==KAL_FALSE)
        {
            /* add to end of list */ 
            p_cur_block->next = p_ctrl_block;
            p_ctrl_block_end->next = NULL;
        }
    }
}


/* retrive NALUs that match the condition to dequeue from interleaved buffer */
//Todo: Must take care of wrapping around case
static H264_RTP_DON_CTRL_BLOCK* h264_rtp_retrive_don_list(void)
{
    H264_RTP_DON_CTRL_BLOCK *retrive_list = NULL;
    kal_uint32 retrive_num = 0;
    kal_uint32 retrive_num_2 = 0;
    kal_uint32 total_NALU;
    kal_uint32 temp_time;
    H264_RTP_DON_CTRL_BLOCK *p_cur_block;

    /* previous list not yet freed, direct return the list */
    if(g_h264_interleaved_info.p_retrive_don_list_head!=NULL)
        return g_h264_interleaved_info.p_retrive_don_list_head;

    /* No any NALU in interleaved buffer */
    if(g_h264_interleaved_info.p_don_list_head==NULL)
        return NULL;

    /* 1. Reaches N NALU limit or not. */
    /* parse the whole list to calculate total NALU number */
    total_NALU = 0;
    p_cur_block = g_h264_interleaved_info.p_don_list_head;
    while(p_cur_block!=NULL)
    {
        if(p_cur_block->b_last==KAL_TRUE)
        {
            total_NALU++;
        }
        g_h264_interleaved_info.max_don = p_cur_block->don;
        p_cur_block = p_cur_block->next;
    }
    g_h264_interleaved_info.total_NAUL = total_NALU;
    if(g_h264_interleaved_info.total_NAUL >= g_h264_interleaved_info.deinterleave_buffer_depth)
    {
        retrive_num = g_h264_interleaved_info.total_NAUL - g_h264_interleaved_info.deinterleave_buffer_depth + 1;
    }

    /* 2. Reach DON limit or not */
    p_cur_block = g_h264_interleaved_info.p_don_list_head;
    while(p_cur_block!=NULL)
    {
        if((g_h264_interleaved_info.max_don - p_cur_block->don) > g_h264_interleaved_info.max_don_diff)
        {
            if(p_cur_block->b_last == KAL_TRUE)
            {
                retrive_num_2++;
            }
            p_cur_block = p_cur_block->next;
        }
        else
        {
            break;
        }
    }

    /* dequeue the larger one */	
    if(retrive_num_2 > retrive_num)
    {
        retrive_num = retrive_num_2;
    }
    if(retrive_num > 0)
    {
        retrive_num_2 = 0;
        retrive_list = g_h264_interleaved_info.p_don_list_head;
        p_cur_block = g_h264_interleaved_info.p_don_list_head;
        while(p_cur_block!=NULL)
        {
            if(p_cur_block->b_last==KAL_TRUE)
            {
                /* Complete NALU */
                if((p_cur_block->next!=NULL) && (p_cur_block->time==p_cur_block->next->time))
                {
                    /* The same frame, set time as 0 */
                    p_cur_block->time = 0;		
                }
                else
                {
                    temp_time = p_cur_block->time;
                    if(g_h264_interleaved_info.time_offset == 0xffffffff)
                    {
                        /* The first packet */
                        p_cur_block->time = 0xffffffff;
                        g_h264_interleaved_info.time_offset = temp_time;
                    }
                    else
                    {
                        /* Not the first frame */
                        p_cur_block->time = temp_time - g_h264_interleaved_info.time_offset;
                        g_h264_interleaved_info.time_offset = temp_time;
                    }
                }
                
                retrive_num_2++;
                if(retrive_num_2==retrive_num)
                {
                    /* all NALUS are retrived */
                    /* update g_h264_interleaved_info.p_don_list_head as the next one of the last retreived block */
                    g_h264_interleaved_info.p_don_list_head = p_cur_block->next;
                    p_cur_block->next = NULL;
                    break;
                }
            }
            else
            {
                /* fragment but bit the last one, time should be 0 */
                p_cur_block->time = 0;
            }
            p_cur_block = p_cur_block->next;
        }
    }

    g_h264_interleaved_info.p_retrive_don_list_head = retrive_list;
    return retrive_list;
}


/* Retrive all NALUs in interleaved buffer. 
    Application knows all packets are received and decide to retrive all packets in interleaved buffer */ 
static H264_RTP_DON_CTRL_BLOCK* h264_rtp_retrive_all_don_list(void)
{
    H264_RTP_DON_CTRL_BLOCK *retrive_list = NULL;
    kal_uint32 temp_time;
    H264_RTP_DON_CTRL_BLOCK *p_cur_block;
    
    /* append all NALUs in buffer to retrive list */	
    retrive_list = g_h264_interleaved_info.p_don_list_head;
    p_cur_block = g_h264_interleaved_info.p_don_list_head;
    while(p_cur_block!=NULL)
    {
        if(p_cur_block->b_last==KAL_TRUE)
        {
            /* Complete NALU */
            if((p_cur_block->next!=NULL) && (p_cur_block->time==p_cur_block->next->time))
            {
                /* The same frame, set time as 0 */
                p_cur_block->time = 0;		
            }
            else
            {
                temp_time = p_cur_block->time;
                if(g_h264_interleaved_info.time_offset == 0xffffffff)
                {
                     /* The first packet */
                     p_cur_block->time = 0xffffffff;
                     g_h264_interleaved_info.time_offset = temp_time;
                }
                else
                {
                    /* Not the first frame */
                    p_cur_block->time = temp_time - g_h264_interleaved_info.time_offset;
                    g_h264_interleaved_info.time_offset = temp_time;
                }
            	}
         }
         else
         {
             /* fragment but bit the last one, time should be 0 */
             p_cur_block->time = 0;
         }

         p_cur_block = p_cur_block->next;
     }

     /* append retrive_list to original g_h264_interleaved_info.p_retrive_don_list_head */
     if(g_h264_interleaved_info.p_retrive_don_list_head==NULL)
     {
         g_h264_interleaved_info.p_retrive_don_list_head = retrive_list;
     }
     else
     {
         /* search the last block of original retrive list and append to it */
         p_cur_block = g_h264_interleaved_info.p_retrive_don_list_head;
         while(p_cur_block->next !=NULL)
         {
             p_cur_block = p_cur_block->next;
         }
         /* append remaining data to original retrive list */
         p_cur_block->next = retrive_list;
     }

     return g_h264_interleaved_info.p_retrive_don_list_head;
}


/* free the previos got don resource (application has complete using of the data)*/
static void h264_rtp_free_don_list(void)
{
	H264_RTP_DON_CTRL_BLOCK *p_curr_block = NULL;
	H264_RTP_DON_CTRL_BLOCK *p_next_block = NULL;
	H264_RTP_DON_CTRL_BLOCK *free_list = g_h264_interleaved_info.p_retrive_don_list_head;

	g_h264_interleaved_info.p_retrive_don_list_head = NULL;

	/* free the memory allocated by the list */
	p_next_block = free_list;
	while(p_next_block!=NULL)
	{
		p_curr_block = p_next_block;
		p_next_block = p_curr_block->next;
		kal_adm_free(g_h264_interleaved_info.adm_id, (void*)p_curr_block->start_addr);
		kal_adm_free(g_h264_interleaved_info.adm_id, p_curr_block);
	}
}

#endif /* STREAM_SUPPORT*/
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
 
