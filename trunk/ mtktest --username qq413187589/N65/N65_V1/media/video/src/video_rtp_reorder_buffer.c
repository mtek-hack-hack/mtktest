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
 *   video_rtp_reorder_buffer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   RTP out of sequence buffer control 
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
//#define STREAM_REORDER_BUFFER_DBG_TRACE
VIDEO_RTP_REORDER_BUFF_INFO g_video_rtp_reorder_buff_info;

//static kal_uint8  g_video_rtp_reoder_buffer[VIDEO_RTP_REORDER_BUFFER_SIZE]; /* ADM memory */

/* initilaize reorder buffer */
void video_rtp_reorder_init_buffer(void)
{
    g_video_rtp_reorder_buff_info.total_pkt = 0;
    g_video_rtp_reorder_buff_info.p_free_addr = NULL;
    g_video_rtp_reorder_buff_info.p_buffer = (kal_uint8*)extmem_get_buffer(VIDEO_RTP_REORDER_BUFFER_SIZE);
    /* init adm buffer */
    if(g_video_rtp_reorder_buff_info.b_init_adm==KAL_FALSE)
    {
        g_video_rtp_reorder_buff_info.adm_id = kal_adm_create(g_video_rtp_reorder_buff_info.p_buffer, VIDEO_RTP_REORDER_BUFFER_SIZE, NULL,KAL_FALSE);
    }
    g_video_rtp_reorder_buff_info.b_buffer_full = KAL_FALSE;
    g_video_rtp_reorder_buff_info.b_init_done= KAL_FALSE;
}

/* put packet into reorder buffer, sequence is the packet's sequnce number */
void video_rtp_reorder_put_pkt(kal_uint8 *data, kal_uint32 size, kal_uint32 sequence)
{
    kal_uint32 index;
    kal_uint32 match_index;
    kal_uint8 *p_buffer = NULL;

    /* free previous got buffer memory */
    if(g_video_rtp_reorder_buff_info.p_free_addr !=NULL)
    {
        kal_adm_free(g_video_rtp_reorder_buff_info.adm_id, g_video_rtp_reorder_buff_info.p_free_addr);
        g_video_rtp_reorder_buff_info.p_free_addr = NULL;
    }

    if(g_video_rtp_reorder_buff_info.total_pkt >= VIDEO_RTP_MAX_REORDER_NUM)
    {
#ifdef STREAM_REORDER_BUFFER_DBG_TRACE
	    video_dbg_trace(STREAM_REORDER_BUFFER_DROP_SEQ, sequence);
#endif
        /* re-order buffer is full, drop the packet */
        VIDEO_ASSERT(0);
        return;
    }

    p_buffer = kal_adm_internal_alloc(g_video_rtp_reorder_buff_info.adm_id, size, __FILE__, __LINE__);
    if(p_buffer==NULL)
    {
#ifdef STREAM_REORDER_BUFFER_DBG_TRACE
    	video_dbg_trace(STREAM_REORDER_BUFFER_DROP_SEQ, sequence);
#endif
        /* re-order buffer is full, drop the packet */
        VIDEO_ASSERT(0);
        g_video_rtp_reorder_buff_info.b_buffer_full = KAL_TRUE;
        return;
    }

    /* search for the matched sequnce index*/
    for(index=0; index<g_video_rtp_reorder_buff_info.total_pkt; index++)
    {
        if(g_video_rtp_reorder_buff_info.sequence[index] > sequence)
        {
            break;
        }
    }

    /* shift the items that has larger sequnce than the input item */
    match_index = index;
    for(index = 0; index < (g_video_rtp_reorder_buff_info.total_pkt-match_index); index++)
    {
        g_video_rtp_reorder_buff_info.sequence[g_video_rtp_reorder_buff_info.total_pkt - index] = g_video_rtp_reorder_buff_info.sequence[g_video_rtp_reorder_buff_info.total_pkt - index - 1];
        g_video_rtp_reorder_buff_info.start_addr[g_video_rtp_reorder_buff_info.total_pkt - index] = g_video_rtp_reorder_buff_info.start_addr[g_video_rtp_reorder_buff_info.total_pkt - index - 1];
        g_video_rtp_reorder_buff_info.buffer_size[g_video_rtp_reorder_buff_info.total_pkt - index] = g_video_rtp_reorder_buff_info.buffer_size[g_video_rtp_reorder_buff_info.total_pkt - index - 1];
    }

    /* add the input  packet */
    g_video_rtp_reorder_buff_info.sequence[match_index] = sequence;
    g_video_rtp_reorder_buff_info.start_addr[match_index] = (kal_uint32)p_buffer;
    g_video_rtp_reorder_buff_info.buffer_size[match_index] = size;
    kal_mem_cpy(p_buffer, data, size);
    g_video_rtp_reorder_buff_info.total_pkt++;
}

/* if the first packet sequnce matches the parameter sequence, get it from buffer */
/* if buffer is full, also pop up the first packet */
kal_uint8* video_rtp_reorder_get_pkt(kal_uint32 sequence, kal_uint32 *p_size, kal_uint32 *p_sequnce)
{
    kal_uint8 *p_data; 
    kal_uint32 index;

    /* free previous got buffer memory */
    if(g_video_rtp_reorder_buff_info.p_free_addr !=NULL)
    {
         kal_adm_free(g_video_rtp_reorder_buff_info.adm_id, g_video_rtp_reorder_buff_info.p_free_addr);
         g_video_rtp_reorder_buff_info.p_free_addr = NULL;
    }

    kal_prompt_trace(MOD_MED, "video_rtp_reorder_get_pkt: totalPkt(%d), seq(%d), seq[0](%d), bufferFull(%d)\n", 
    		g_video_rtp_reorder_buff_info.total_pkt, sequence, g_video_rtp_reorder_buff_info.sequence[0], g_video_rtp_reorder_buff_info.b_buffer_full);

    /* check whether it is needed to dequeue the first item from re-order buffer */
    if((g_video_rtp_reorder_buff_info.total_pkt == VIDEO_RTP_MAX_REORDER_NUM) 
    	  || ((g_video_rtp_reorder_buff_info.total_pkt > 0 ) && ((g_video_rtp_reorder_buff_info.sequence[0] == sequence)||(sequence == 0xffffffff)||(g_video_rtp_reorder_buff_info.b_buffer_full == KAL_TRUE)))
    	  )
    {
        /* retrun the first packet from queue */
        g_video_rtp_reorder_buff_info.p_free_addr = (kal_uint8*)g_video_rtp_reorder_buff_info.start_addr[0];
        p_data = (kal_uint8*)g_video_rtp_reorder_buff_info.start_addr[0];        
        *p_size = g_video_rtp_reorder_buff_info.buffer_size[0];
        *p_sequnce = g_video_rtp_reorder_buff_info.sequence[0];
        g_video_rtp_reorder_buff_info.total_pkt--;
        
        if(g_video_rtp_reorder_buff_info.total_pkt >= VIDEO_RTP_MAX_REORDER_NUM)
        	ASSERT(0);
        
        g_video_rtp_reorder_buff_info.b_buffer_full = KAL_FALSE;

        for(index = 0; index < g_video_rtp_reorder_buff_info.total_pkt; index++)
        {
            g_video_rtp_reorder_buff_info.sequence[index] = g_video_rtp_reorder_buff_info.sequence[index+1];
            g_video_rtp_reorder_buff_info.start_addr[index] = g_video_rtp_reorder_buff_info.start_addr[index+1];
            g_video_rtp_reorder_buff_info.buffer_size[index] = g_video_rtp_reorder_buff_info.buffer_size[index+1];
        }
        return g_video_rtp_reorder_buff_info.p_free_addr;
    }
    else
    {
        /* no packet is dequeded */
        *p_size = 0;
        *p_sequnce = 0;
        return NULL;
    }
}

/* MED send start_seq (obtained from rtsp) of the first pkt so that the driver can check that        */
/* the pkts in reorder buffer is valid or not. (invalid pkts are from previous sessions                    */
kal_uint32 video_rtp_reorder_check_pkt(kal_uint32 start_seq, kal_uint32 thre)
{
   kal_uint32 i,j,diff, framecnt=0;

   kal_prompt_trace(MOD_MED, "video_rtp_reorder_check_pkts: %d, %d\n", start_seq, thre);
   
#ifdef __STREAM_TRACE_ON__
   {
     extern kal_int32 video_dec_show_buffer_trace(kal_int32 mode);
	framecnt = video_dec_show_buffer_trace(0); // 0 for streaming
	//if (framecnt !=0) {
	//	kal_prompt_trace(MOD_MED, "video_rtp_clr_buffer_before_chk_pkts: %d\n", framecnt);
	//	video_dec_clr_buffer(0, 0xffff);
	//}
   }
#endif
   
   for (i = 0; i < g_video_rtp_reorder_buff_info.total_pkt; i++)
   {
      if (start_seq > g_video_rtp_reorder_buff_info.sequence[i])
         diff = start_seq - g_video_rtp_reorder_buff_info.sequence[i];
      else
         diff = g_video_rtp_reorder_buff_info.sequence[i] - start_seq;

      if (diff > thre) {
         kal_prompt_trace(MOD_MED, "video_rtp_reorder_check_pkts: Beyond Thre %d\n", g_video_rtp_reorder_buff_info.sequence[i]);
         g_video_rtp_reorder_buff_info.sequence[i] = 0xfffffffe;
      } else {
	  	 kal_prompt_trace(MOD_MED, "video_rtp_reorder_check_pkts: Within Thre %d\n", g_video_rtp_reorder_buff_info.sequence[i]);
      }
   }
   i = 0;
   while (i<g_video_rtp_reorder_buff_info.total_pkt)
   {
       if (g_video_rtp_reorder_buff_info.sequence[i] == 0xfffffffe)
       {
           kal_uint8 *p = (kal_uint8*)g_video_rtp_reorder_buff_info.start_addr[i];
           
		 if(p !=NULL)
		 {
			kal_adm_free(g_video_rtp_reorder_buff_info.adm_id, p);
		 }
       
           for (j = i+1; j < g_video_rtp_reorder_buff_info.total_pkt; j++)
           {
              if (g_video_rtp_reorder_buff_info.sequence[i] != 0xfffffffe)
			     break;
           }
		 if (j<g_video_rtp_reorder_buff_info.total_pkt)
		 {
			 g_video_rtp_reorder_buff_info.sequence[i] = g_video_rtp_reorder_buff_info.sequence[j];
			 g_video_rtp_reorder_buff_info.start_addr[i] = g_video_rtp_reorder_buff_info.start_addr[j];
			 g_video_rtp_reorder_buff_info.buffer_size[i] = g_video_rtp_reorder_buff_info.buffer_size[j];
			 g_video_rtp_reorder_buff_info.sequence[j] = 0xfffffffe;
			 g_video_rtp_reorder_buff_info.start_addr[j] = 0;
			 g_video_rtp_reorder_buff_info.buffer_size[j] = 0;
		 } else {
			 g_video_rtp_reorder_buff_info.total_pkt = i;
			 break;
		 }
       }
	   i++;
   }
   g_video_rtp_reorder_buff_info.b_init_done = KAL_TRUE;
   return i;
}

#endif /* STREAM_SUPPORT*/
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
 
