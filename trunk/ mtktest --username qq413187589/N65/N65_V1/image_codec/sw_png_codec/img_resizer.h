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
 * Filename:
 * ---------
 *	 img_resizer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Header file of software png resizer.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef IMG_RESIZER_H
#define IMG_RESIZER_H
#include "kal_release.h"

#define PNG_NEW_BUFFER_INTERFACE
#define IMG_MAX_WIDTH		2048
#define IMG_MAX_HEIGHT		2048


#define IMG_CLIP_RECT_TEST(X1, Y1, X2, Y2,NULL_ACTION)\
{\
	if(X1 > X2)	{ NULL_ACTION; }\
	else if(Y1 > Y2)	{ NULL_ACTION; }\
	else if(X2 < IMG_RESIZER.clipx1) { return -1; }\
	else if(Y2 < IMG_RESIZER.clipy1) { return -1; }\
	else if(X1 > IMG_RESIZER.clipx2) { return -1; }\
	else if(Y1 > IMG_RESIZER.clipy2) { return -1; }\
	else											\
	{											\
		if(X1 < IMG_RESIZER.clipx1) { X1 = IMG_RESIZER.clipx1; }\
		if(Y1 < IMG_RESIZER.clipy1) { Y1 = IMG_RESIZER.clipy1; }\
		if(X2 > IMG_RESIZER.clipx2) { X2 = IMG_RESIZER.clipx2; }\
		if(Y2 > IMG_RESIZER.clipy2) { Y2 = IMG_RESIZER.clipy2; }\
	}\
}

typedef struct
{
	kal_uint8* dest;
	kal_uint32 bytesperpixel;
	kal_int32 offset_dx;
	kal_int32 offset_dy;
	kal_int32 want_dx1,want_dx2; // wanted rendering area
	kal_int32 want_dy1,want_dy2;
	kal_int32 dir_x;
	kal_int32 dir_y;
	
	// for non resize used
	kal_int32 want_start_sx,want_start_sy;
	kal_int32 want_end_sx,want_end_sy;

	kal_uint8* out_buf;
	kal_uint32 out_buf_w;	
	kal_int16 clipx1,clipy1,clipx2,clipy2; // clipping window of the display buffer
	kal_bool resize; // 0: non resize, 1: resize
	kal_bool interlaced; // 0: non-interlace, 1: interlaced
	kal_uint32 src_key; // MMI's source key color, need to be replaced with another color;
} img_resizer_struct;


#define SWAP(t,a,b) do {t tmp=a;a=b;b=tmp;} while(0)

extern img_resizer_struct IMG_RESIZER;
#ifdef PNG_NEW_BUFFER_INTERFACE
kal_int32 png_img_resizer_init(  
				kal_int32 src_width,kal_int32 src_height, 
				kal_int32 dest_x1,kal_int32 dest_y1,kal_int32 dest_x2,kal_int32 dest_y2, 
				kal_uint8 *upper_buffer, kal_uint32 upper_buffer_size);

#else
kal_int32 png_img_resizer_init(  
				kal_int32 src_width,kal_int32 src_height, 
				kal_int32 dest_x1,kal_int32 dest_y1,kal_int32 dest_x2,kal_int32 dest_y2);
#endif

void img_resizer_put_row(kal_uint8 *src, kal_uint32 width, kal_uint32 row_num, kal_uint32 step);
void img_resizer_put_pixel(kal_uint32 x, kal_uint32 y, kal_uint8 *src);


#endif
