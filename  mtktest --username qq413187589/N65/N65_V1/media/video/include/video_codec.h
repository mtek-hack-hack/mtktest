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
 * video_codec.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   video codec definitions in ISO14496
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
 /**
 * \file video_codec.h
 *
 * This interface defines video decode core interface.
 * 
 */
#ifndef VIDEO_CODEC_H
#define VIDEO_CODEC_H

#define MAX_MB_PACKET            (99*4)
#define EXTENDED_PAR             0x000f
#define DEC_OK			            0
#define DEC_MEMORY		         1
#define DEC_BAD_FORMAT	         2
#define DEC_INVALID_ARGUMENT     3
#define DEC_NOT_IMPLEMENTED      4

#define VO_START_CODE		      0x8
#define VO_START_CODE_MIN	      0x100
#define VO_START_CODE_MAX	      0x11f

#define VOL_START_CODE		      0x12
#define VOL_START_CODE_MIN	      0x120
#define VOL_START_CODE_MAX	      0x12f

#define VOS_START_CODE           0x1b0
#define USR_START_CODE           0x1b2
#define GOP_START_CODE           0x1b3
#define VSO_START_CODE           0x1b5
#define VOP_START_CODE	         0x1b6
#define STF_START_CODE           0x1c3 // stuffing_start_code
#define SHV_START_CODE           0x020
#define SHV_END_MARKER           0x03f

#define I_VOP		               0
#define P_VOP		               1
#define B_VOP		               2
#define S_VOP		               3

#define RECTANGULAR				   0
#define BINARY					      1
#define BINARY_SHAPE_ONLY		   2 
#define GRAY_SCALE				   3

#define NOTUSE_SPRITE			   0
#define STATIC_SPRITE			   1
#define GMC_SPRITE				   2
#define RESERVED_SPRITE			   3

#define RESYNC_MARKER			   1

#define VIDEO_MAX(a,b)                 ( ((a)>(b))? a : b )
#define VIDEO_MIN(a,b)                 ( ((a)<(b))? a : b )
#define ENFORCE_MINMAX(a,b,c)    VIDEO_MAX(a,(VIDEO_MIN(b,c)))
#define VOS_BIT_RATE             (640000/400)
#define VOS_VBV_BUFFER_SIZE      (1835008/16384)
#define VOS_OCCUPANCY            (1376256/64)

/* ------ public functions ------ */

/**
 * Initialize the rate control mechanism for mpeg4 encoder.
 *
 * @param  bitrate mpeg4 encode bit rate
 * @param  frame_rate the frame rate of camera(image source)
 * @param  pixels_per_frame  how much pixels in a frames
 * @return quantizer value
 * 
 */
extern kal_int32 init_RC(kal_int32 bitrate, kal_int32 frame_rate, kal_int32 pixels_per_frame);
/**
 * Obtain the new quantizer value through rate control from previous frames.
 *
 * @param  bitrate mpeg4 encode bit rate
 * @param  frame_rate the frame rate of camera(image source)
 * @param  quant the previous quantizer value
 * @param  width the width value
 * @param  height the height value
 * @param  bitcount  how much pixels in a frames
 * @param  predition_type  I_FRAME or P_FRAME
 * @param  total_frames  total encode frame number
 * @param  b_force_I_frame  force this frame as I_FRAME
 * @return quantizer value
 * 
 */
extern kal_int32 RC_UPdated(kal_int32 bitrate, kal_int32 frame_rate, kal_int32 quant, kal_uint32 width, kal_uint32 height, 
                                                kal_int32 bitcount, kal_int32 predition_type, kal_uint32 total_frames, kal_bool b_force_I_frame, kal_uint32 mode);


#endif   /*VIDEO_CODEC_H*/


