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
 *   video_rtp_h264_interleaved_buffer.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 #ifndef VIDEO_DEC_RTP_H264_INTERLEAVED_BUFFER_H
#define VIDEO_DEC_RTP_H264_INTERLEAVED_BUFFER_H

#ifdef STREAM_SUPPORT

#define H264_RTP_INTERLEAVED_BUFFER_SIZE   20*1024

typedef struct _H264_RTP_DON_CTRL_BLOCK_
{
    kal_uint32 start_addr;
    kal_uint32 size;
    kal_uint32 don;
    kal_uint32 time;
    kal_bool   b_first;
    kal_bool   b_last;
    struct _H264_RTP_DON_CTRL_BLOCK_  *next;
}H264_RTP_DON_CTRL_BLOCK;


typedef struct
{
    kal_uint32 deinterleave_buffer_depth;  /* set by application*/
    kal_uint32 total_NAUL;                        /* run time calcaulation */
    kal_uint32 max_don_diff;                     /* set by application*/
    kal_uint32 max_don;                           /* run time calcaulation */ 
    kal_uint32 time_offset;
    kal_bool b_init_adm;
    KAL_ADM_ID  adm_id;
    kal_uint8 *p_buffer;
    H264_RTP_DON_CTRL_BLOCK *p_don_list_head;             /* All complete packet list */
    H264_RTP_DON_CTRL_BLOCK *p_fragment_list_head;     /* Fragment packet list */
    H264_RTP_DON_CTRL_BLOCK *p_retrive_don_list_head; /* Retrive list that store the packets appication already get */    
}H264_RTP_INTERLEAVED_INFO;

#endif /* STREAM_SUPPORT */
#endif /*VIDEO_DEC_RTP_H264_INTERLEAVED_BUFFER_H*/
 
