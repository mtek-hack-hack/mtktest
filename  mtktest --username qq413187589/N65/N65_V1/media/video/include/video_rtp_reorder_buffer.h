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
 *   video_rtp_reorder_buffer.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 #ifndef VIDEO_RTP_REORDER_BUFFER_H
#define VIDEO_RTP_REORDER_BUFFER_H

#ifdef STREAM_SUPPORT

#define VIDEO_RTP_MAX_REORDER_NUM  20
#define VIDEO_RTP_REORDER_BUFFER_SIZE  15*1024

typedef struct
{
    kal_uint8 *p_free_addr;
    kal_uint32 total_pkt;
    kal_uint32 sequence[VIDEO_RTP_MAX_REORDER_NUM];
    kal_uint32 start_addr[VIDEO_RTP_MAX_REORDER_NUM];
    kal_uint32 buffer_size[VIDEO_RTP_MAX_REORDER_NUM];
    KAL_ADM_ID  adm_id;
    kal_bool b_init_adm;
    kal_uint8 *p_buffer;
    kal_bool b_buffer_full;
    kal_bool b_init_done;	// For protocol side to finish the checking of that a new session starts.
}VIDEO_RTP_REORDER_BUFF_INFO;

extern void video_rtp_reorder_init_buffer(void);
extern void video_rtp_reorder_put_pkt(kal_uint8 *data, kal_uint32 size, kal_uint32 sequence);
extern kal_uint8* video_rtp_reorder_get_pkt(kal_uint32 sequence, kal_uint32 *p_size, kal_uint32 *p_sequnce);
extern kal_uint32 video_rtp_reorder_check_pkt(kal_uint32 start_seq, kal_uint32 thre);

#endif /* STREAM_SUPPORT */
#endif /*VIDEO_RTP_REORDER_BUFFER_H*/
 
