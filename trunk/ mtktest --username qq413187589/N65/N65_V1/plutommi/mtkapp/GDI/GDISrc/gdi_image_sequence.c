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
 *	 gdi_image.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sequence image
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"

GDI_RESULT gdi_image_sequence_draw_handler(U32 flag,U32 frame_pos,S32 x,S32 y,S32 w,S32 h,U8* data_ptr,U32 img_size)
{
	U8 img_type = GDI_IMAGE_TYPE_INVALID;
	U8* header;
	int frame_sum;
	int index = frame_pos;
	int offset;
	int size;
	
    data_ptr-=8;
	header = data_ptr;
    frame_sum = header[1];
	if(index <0 ||	index >= frame_sum)
		return GDI_FAILED;
	
	header +=8 + index*12;
	offset = (header[3]<<24) | (header[2]<<16) |(header[1]<<8)|(header[0]);
	header+=4;
	size   = (header[3]<<24) | (header[2]<<16) |(header[1]<<8)|(header[0]);
	header+=4;
	gdi_anim_set_delay((header[3]<<24) | (header[2]<<16) |(header[1]<<8)|(header[0]));
	
	offset += 12 * frame_sum;

	switch(data_ptr[0])
	{
	case GDI_IMAGE_TYPE_BMP_SEQUENCE:
		img_type = GDI_IMAGE_TYPE_BMP;
		break;
	case GDI_IMAGE_TYPE_JPG_SEQUENCE:
		img_type = GDI_IMAGE_TYPE_JPG;
		break;
	case GDI_IMAGE_TYPE_PNG_SEQUENCE:
		img_type = GDI_IMAGE_TYPE_PNG;
		break;
	case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
		img_type = GDI_IMAGE_TYPE_DEVICE_BITMAP;
		break;
    case GDI_IMAGE_TYPE_ABM_SEQUENCE:        
        img_type = GDI_IMAGE_TYPE_ABM;
        break;
	}

	return gdi_image_codec_draw(
				GDI_IMAGE_SRC_FROM_RESOURCE_WITHOUT_HEADER,
				(U8*)data_ptr+offset,img_type,size,
				x,y,w,h,flag,frame_pos);
}

GDI_RESULT gdi_image_sequence_get_dimension_handler(U32 flag,U8* data_ptr,U32 img_size,S32 *width,S32 *height)
{
	U8 img_type=GDI_IMAGE_TYPE_INVALID;
	U8* header;
	int frame_sum;
	int index = 0;
	int offset;
	int size;
	
    data_ptr-=8;
	header = data_ptr;
    frame_sum = header[1];
	if(index <0 ||	index >= frame_sum)
		return GDI_FAILED;
	
	header +=8 + index*12;
	offset = (header[3]<<24) | (header[2]<<16) |(header[1]<<8)|(header[0]);
	header+=4;
	size   = (header[3]<<24) | (header[2]<<16) |(header[1]<<8)|(header[0]);
	header+=4;
	gdi_anim_set_delay((header[3]<<24) | (header[2]<<16) |(header[1]<<8)|(header[0]));
	
	offset += 12 * frame_sum;

	switch(data_ptr[0])
	{
	case GDI_IMAGE_TYPE_BMP_SEQUENCE:
		img_type = GDI_IMAGE_TYPE_BMP;
		break;
	case GDI_IMAGE_TYPE_JPG_SEQUENCE:
		img_type = GDI_IMAGE_TYPE_JPG;
		break;
	case GDI_IMAGE_TYPE_PNG_SEQUENCE:
		img_type = GDI_IMAGE_TYPE_PNG;
		break;
	case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
		img_type = GDI_IMAGE_TYPE_DEVICE_BITMAP;
		break;
    case GDI_IMAGE_TYPE_ABM_SEQUENCE:        
        img_type = GDI_IMAGE_TYPE_ABM;
        break;        
	}

	return gdi_image_codec_get_dimension(
				GDI_IMAGE_SRC_FROM_RESOURCE_WITHOUT_HEADER,
				(U8*)data_ptr+offset,img_type,size,
				width,height,flag);
}
GDI_RESULT gdi_image_sequence_get_frame_count_handler(U32 flag,U8* data_ptr,U32 img_size,S32 *frame_count)
{
	gdi_anim_pos_type_enum temp;
	return gdi_image_sequence_get_pos_info_handler(flag,data_ptr,img_size,FALSE, frame_count,&temp);
}
GDI_RESULT gdi_image_sequence_get_pos_info_handler(U32 flag,U8* data_ptr,U32 img_size,BOOL quick_mode, S32 *total_pos,gdi_anim_pos_type_enum *pos_type)
{
	*total_pos = (data_ptr[-7]);
	*pos_type = GDI_ANIM_POS_TYPE_INDEX;
	return GDI_SUCCEED;
}
