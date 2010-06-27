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
 *	 gdi_image_virtualfile.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Virtual file image
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
#include "ucs2prot.h"
S32 gdi_image_get_virtual_filename(S8* image_buffer, S8* virtual_fname)
{
	#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
	S32	fs_result;
	U32 image_file_size=0;
	U32 image_offset=0;
	S32	theme_file_handle;
	
	image_file_size = (U8)image_buffer[4];
	image_file_size = (image_file_size << 8) | (U8)image_buffer[3];
	image_file_size = (image_file_size << 8) | (U8)image_buffer[2];

	image_offset = (U8)image_buffer[11];
	image_offset = (image_offset << 8) | (U8)image_buffer[10];
	image_offset = (image_offset << 8) | (U8)image_buffer[9];
	image_offset = (image_offset << 8) | (U8)image_buffer[8];
	
	theme_file_handle = image_buffer[15];
	theme_file_handle = (theme_file_handle << 8) | image_buffer[14];
	theme_file_handle = (theme_file_handle << 8) | image_buffer[13];
	theme_file_handle = (theme_file_handle << 8) | image_buffer[12];

	fs_result = FS_GenVirtualFileName( theme_file_handle, (U16*)virtual_fname, 
		(unsigned int)FS_GenVFN_SIZE, image_offset+8, image_file_size);

	mmi_ucs2cat((S8*)virtual_fname,(const S8*)gdi_image_ext_name[image_buffer[0]]);
	
	return fs_result;
	#else
	return -1;
	#endif
}

GDI_RESULT gdi_image_virtualfile_draw_handler(U32 flag,U32 frame_pos,S32 x,S32 y,S32 w,S32 h,U8* data_ptr,U32 img_size)
{
	U16 fname[FS_GenVFN_SIZE+8];//extra 8 bytes for file extension
	S32 fs_result;
	U8 img_type = GDI_IMAGE_TYPE_INVALID;
	memset(fname, 0, sizeof(fname));
	fs_result = gdi_image_get_virtual_filename((S8*)data_ptr,(S8*)fname);
	if(fs_result<0) return GDI_IMAGE_ERR_OPEN_FILE_FAILED;

	switch(data_ptr[0])
	{
	case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_BMP_FILE;
		break;
	case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_GIF_FILE;
		break;
    case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_JPG_FILE;
		break;
    case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_PNG_FILE;
		break;
    case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_BMP_FILE;
		break;
    case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_WBMP_FILE;
		break;
    case GDI_IMAGE_TYPE_M3D_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_M3D_FILE;
		break;
    case GDI_IMAGE_TYPE_SVG_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_SVG_FILE;
		break;
    case GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_SWFLASH_FILE;
		break;
    case GDI_IMAGE_TYPE_ABM_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_ABM_FILE;
        break;
    default:
        return GDI_FAILED;
	}
    
	return gdi_image_codec_draw(
				GDI_IMAGE_SRC_FROM_FILE,
				(U8*)fname,img_type,0,
				x,y,w,h,flag,frame_pos);
}

GDI_RESULT gdi_image_virtualfile_get_dimension_handler(U32 flag,U8* data_ptr,U32 img_size,S32 *width,S32 *height)
{
    *width 		  = (S32)(( ((U32)data_ptr[7])     <<4) | (((U32)data_ptr[6]&0xF0)>>4));
	*height		  = (S32)(((((U32)data_ptr[6])&0xF)<<8) |  ((U32)data_ptr[5]         ));

	//*width =  ((data_ptr[6] & 0x00F0)>>4) | ((data_ptr[5])<<4);
	//*height = ((data_ptr[6] & 0x000F)<<8) | (data_ptr[7]);
	return GDI_SUCCEED;
}
GDI_RESULT gdi_image_virtualfile_get_frame_count_handler(U32 flag,U8* data_ptr,U32 img_size,S32 *frame_count)
{
	gdi_anim_pos_type_enum temp;
	return gdi_image_virtualfile_get_pos_info_handler(flag,data_ptr,img_size,FALSE, frame_count,&temp);
}

GDI_RESULT gdi_image_virtualfile_get_pos_info_handler(U32 flag,U8* data_ptr,U32 img_size,BOOL quick_mode, S32 *total_pos,gdi_anim_pos_type_enum *pos_type)
{
	//*total_pos = (data_ptr[1]);
	//*pos_type = GDI_ANIM_POS_TYPE_INDEX;
	//return GDI_SUCCEED;

	U16 fname[FS_GenVFN_SIZE+8];//extra 8 bytes for file extension
	S32 fs_result;
	U8 img_type = GDI_IMAGE_TYPE_INVALID;
	memset(fname, 0, sizeof(fname));
	fs_result = gdi_image_get_virtual_filename((S8*)data_ptr,(S8*)fname);
	if(fs_result<0) return GDI_IMAGE_ERR_OPEN_FILE_FAILED;

	switch(data_ptr[0])
	{
	case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_BMP_FILE;
		break;
	case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_GIF_FILE;
		break;
    case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_JPG_FILE;
        break;
    case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_PNG_FILE;
        break;
    case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_BMP_FILE;
        break;
    case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_WBMP_FILE;
        break;
    case GDI_IMAGE_TYPE_M3D_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_M3D_FILE;
        break;
    case GDI_IMAGE_TYPE_SVG_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_SVG_FILE;
        break;
    case GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_SWFLASH_FILE;
        break;
    case GDI_IMAGE_TYPE_ABM_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_ABM_FILE;
        break;        
    default:
        return GDI_FAILED;
	}

	*pos_type = GDI_ANIM_POS_TYPE_INDEX;

	return gdi_image_codec_get_frame_count(
				GDI_IMAGE_SRC_FROM_FILE,
				(U8*)fname,img_type,0,
				total_pos,flag);
}


