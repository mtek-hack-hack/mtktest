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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   img_comm_jpeg.c
 *
 * Project:
 * --------
 *		MT6219, MT6226, MT6227, MT6228, MT6229
 *
 * Description:
 * ------------
 *   This function is to control jpeg codec in image data path.
 *
 * Author:
 * -------
 *   
 *   TY Jau (mtk00502)
 *   Scott Hung (mtk01235)
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "reg_base.h"
#include "drv_comm.h"
#if defined(DRV_JPG_DATA_PATH_17_SERIES) || defined(DRV_JPG_DATA_PATH_19_SERIES) || defined(DRV_JPG_DATA_PATH_28_SERIES)
#include "jpeg.h"

#if (defined(EXIF_SUPPORT))
#include "exif.h"
#endif

#include "visual_comm.h"
#include "visualhisr.h"
#include "imgproc.h"
#include "resizer.h"
#include "isp_if.h"
#include "image_effect.h"
#include "lcd_if.h"
#include "2d_engine.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "med_status.h"
#include "video_dec_glb.h"

#if (defined(DRV_JPG_DATA_PATH_28_SERIES))
#include "img_comm.h"
#include "tv_out.h"
#include "upll_ctrl.h"
#endif

#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"
#endif

#if defined(DRV_JPG_DATA_PATH_28_SERIES)
kal_uint16 config_jfif_header(kal_uint8 *jpg_file_ptr, kal_uint16 thumbnail_width,kal_uint16 thumbnail_height)
{
	kal_uint32 jfif_header_length;

	jfif_header_length=thumbnail_width*thumbnail_height*3+16;
	if (jfif_header_length>=0x10000)
		ASSERT(0);

	*(jpg_file_ptr)=0xFF;
	*(jpg_file_ptr+1)=0xD8;
	*(jpg_file_ptr+2)=0xFF;		/* APP0 */
	*(jpg_file_ptr+3)=0xE0;
	*(jpg_file_ptr+4)=(jfif_header_length&0xFF00)>>8;
	*(jpg_file_ptr+5)=(jfif_header_length&0xFF);
	*(jpg_file_ptr+6)='J';
	*(jpg_file_ptr+7)='F';
	*(jpg_file_ptr+8)='I';
	*(jpg_file_ptr+9)='F';
	*(jpg_file_ptr+10)=0;
	*(jpg_file_ptr+11)=0x01;		/* version */
	*(jpg_file_ptr+12)=0x02;
	*(jpg_file_ptr+13)=0;			/* units */
	*(jpg_file_ptr+14)=0;			/* X density */
	*(jpg_file_ptr+15)=1;			/* X density */
	*(jpg_file_ptr+16)=0;			/* Y density */
	*(jpg_file_ptr+17)=1;			/* Y density */
	*(jpg_file_ptr+18)=thumbnail_width;
	*(jpg_file_ptr+19)=thumbnail_height;

	return jfif_header_length;
}	/* config_jfif_header() */


void close_jpeg_module(kal_bool encode, kal_bool decode, kal_bool power_down)
{
   if(decode)
      RESET_JPEG_DECODER;
   if(encode)
      RESET_JPEG_ENCODER;	
	jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;	
	if(power_down)
	   jpeg_codec_power_down();   
}   

void config_jpeg_resize_path(jpeg_file_resize_struct *jpeg_para)
{
   kal_uint16 jfif_header_length=0;
         
   RESET_JPEG_ENCODER;
	REG_JPEG_ENCODER_CTRL=0;

	if (jpeg_para->jpeg_yuv_mode==JPEG_FORMAT_GRAY)
	{
		SET_JPEG_ENCODER_GRAY_MODE;
	}
	else if (jpeg_para->jpeg_yuv_mode==JPEG_FORMAT_YUV420)
	{
		SET_JPEG_ENCODER_FORMAT_YUV420;
	}
	if (jpeg_para->thumbnail_mode==KAL_TRUE)
	{
		ENABLE_JPEG_ENCODER_JFIF_MODE;
		jfif_header_length=config_jfif_header((kal_uint8 *) jpeg_para->target_jpeg_file_address,jpeg_para->thumbnail_width,
														  jpeg_para->thumbnail_height);
		REG_JPEG_ENCODER_DEST_ADDR=jpeg_para->target_jpeg_file_address+jfif_header_length+4;
	}
	else
	{
		REG_JPEG_ENCODER_DEST_ADDR=jpeg_para->target_jpeg_file_address;
	}
	ENABLE_JPEG_ENCODER_INT;
	SET_JPEG_ENCODER_QUALITY(jpeg_para->image_quality);
	REG_JPEG_ENCODER_STOP_ADDR=(jpeg_para->target_jpeg_file_address+jpeg_para->target_jpeg_file_buffer_size-4)&0xFFFFFFFC;

	RELOAD_STALL_ADDRESS;
	ENABLE_JPEG_ENCODER;
	jpeg_encoder_operation_state=JPEG_ENCODER_ENCODING_STATE;
   
}   

void config_jpeg_encode_path(jpeg_encode_process_struct *jpeg_para)
{
   kal_uint16 jfif_header_length=0;
   
		/* config JPEG encoder */
	RESET_JPEG_ENCODER;
	REG_JPEG_ENCODER_CTRL=0;

	if (jpeg_para->jpeg_yuv_mode==JPEG_FORMAT_GRAY)
	{
		SET_JPEG_ENCODER_GRAY_MODE;
	}
	else if (jpeg_para->jpeg_yuv_mode==JPEG_FORMAT_YUV420)
	{
		SET_JPEG_ENCODER_FORMAT_YUV420;
	}
	if (jpeg_para->thumbnail_mode==KAL_TRUE)
	{
		ENABLE_JPEG_ENCODER_JFIF_MODE;
		jfif_header_length=config_jfif_header((kal_uint8 *) jpeg_para->jpeg_file_start_address,jpeg_para->thumbnail_width,
														  jpeg_para->thumbnail_height);		
		REG_JPEG_ENCODER_DEST_ADDR=jpeg_para->jpeg_file_start_address+jfif_header_length+4;
	}
	else
	{
		REG_JPEG_ENCODER_DEST_ADDR=jpeg_para->jpeg_file_start_address;
	}
	ENABLE_JPEG_ENCODER_INT;
	SET_JPEG_ENCODER_QUALITY(jpeg_para->image_quality);
	REG_JPEG_ENCODER_STOP_ADDR=(jpeg_para->jpeg_file_start_address+jpeg_para->jpeg_file_buffer_size-4)&0xFFFFFFFC;

	RELOAD_STALL_ADDRESS;
	ENABLE_JPEG_ENCODER;	

	jpeg_encoder_operation_state=JPEG_ENCODER_ENCODING_STATE;
}	

void config_jpeg_usbvideo_path(camera_capture_jpeg_data_path_struct *capture_para)
{
   kal_uint32 jpeg_encoder_ctrl_reg;
   RESET_JPEG_ENCODER;
	REG_JPEG_ENCODER_CTRL=0;
	jpeg_encoder_ctrl_reg=0;

	if (capture_para->jpeg_yuv_mode==JPEG_FORMAT_GRAY)
	{
		SET_JPEG_ENCODER_GRAY_MODE;
	}
	else if (capture_para->jpeg_yuv_mode==JPEG_FORMAT_YUV420)
	{
		SET_JPEG_ENCODER_FORMAT_YUV420;
	}
	REG_JPEG_ENCODER_DEST_ADDR=capture_para->jpeg_file_start_address1;

/* hardware issue, can not set cont shot then snapshot_number that will result in JPEG encoder start */
	jpeg_encoder_ctrl_reg=REG_JPEG_ENCODER_CTRL;
	REG_JPEG_ENCODER_CONT_SHOT_FRAME_NUM=0;
	
	jpeg_encoder_ctrl_reg |= JPEG_ENCODER_INT_ENABLE_BIT;
	SET_JPEG_ENCODER_QUALITY(capture_para->image_quality);
	REG_JPEG_ENCODER_STOP_ADDR=(capture_para->jpeg_file_start_address1+capture_para->jpeg_file_buffer_size1-4)&0xFFFFFFFC;

	jpeg_encoder_operation_state=JPEG_ENCODER_ENCODING_STATE;
	jpeg_encoder_ctrl_reg|=JPEG_ENCODER_ENABLE_BIT;
	REG_JPEG_ENCODER_CTRL=jpeg_encoder_ctrl_reg;
}   
void config_jpeg_capture_path(camera_capture_jpeg_data_path_struct *capture_para)
{
   kal_uint16 jfif_header_length=0;
	kal_uint32 jpeg_encoder_ctrl_reg;
   #if (defined(EXIF_SUPPORT))
	kal_uint16 exif_header_length=0;
	#endif	
	
	if (capture_para->thumbnail_mode==KAL_TRUE)
	{
	   jfif_header_length=config_jfif_header((kal_uint8 *) capture_para->jpeg_file_start_address1,capture_para->thumbnail_width,
														  capture_para->thumbnail_height);
	}													  
														  
   #if (defined(EXIF_SUPPORT))	
	
	if(jfif_header_length==0)
	{
	   *((kal_uint8 *)capture_para->jpeg_file_start_address1)=0xFF;
	   *((kal_uint8 *)capture_para->jpeg_file_start_address1+1)=0xD8;	
	   exif_header_length=exif_Fillin_Buffer((kal_uint8 *)(capture_para->jpeg_file_start_address1+2),jfif_header_length);
	}
	else
	   exif_header_length=exif_Fillin_Buffer((kal_uint8 *)(capture_para->jpeg_file_start_address1),jfif_header_length+4);

	#endif		
	
	
	camera_capture_jpeg_config_data.jpeg_file_info->jpeg_file_address[current_captured_file_number]=capture_para->jpeg_file_start_address1;
	RESET_JPEG_ENCODER;
	REG_JPEG_ENCODER_CTRL=0;
	jpeg_encoder_ctrl_reg=0;

	if (capture_para->jpeg_yuv_mode==JPEG_FORMAT_GRAY)
	{
		SET_JPEG_ENCODER_GRAY_MODE;
	}
	else if (capture_para->jpeg_yuv_mode==JPEG_FORMAT_YUV420)
	{
		SET_JPEG_ENCODER_FORMAT_YUV420;
	}

	#if (defined(EXIF_SUPPORT))
	ENABLE_JPEG_ENCODER_JFIF_MODE;
	if (capture_para->thumbnail_mode==KAL_TRUE)
	{
		REG_JPEG_ENCODER_DEST_ADDR=capture_para->jpeg_file_start_address1+jfif_header_length+4+exif_header_length;
	}
	else
	{
		REG_JPEG_ENCODER_DEST_ADDR=capture_para->jpeg_file_start_address1+exif_header_length+2;
	}
	#else
	if (capture_para->thumbnail_mode==KAL_TRUE)
	{
		ENABLE_JPEG_ENCODER_JFIF_MODE;
		REG_JPEG_ENCODER_DEST_ADDR=capture_para->jpeg_file_start_address1+jfif_header_length+4;
	}
	else
	{
		REG_JPEG_ENCODER_DEST_ADDR=capture_para->jpeg_file_start_address1;
	}
	#endif

/* hardware issue, can not set cont shot then snapshot_number that will result in JPEG encoder start */
	jpeg_encoder_ctrl_reg=REG_JPEG_ENCODER_CTRL;
	if (capture_para->snapshot_number>1)
	{
		jpeg_encoder_ctrl_reg |= JPEG_ENCODER_CONT_SHOT_BIT;
		REG_JPEG_ENCODER_CONT_SHOT_FRAME_NUM=capture_para->snapshot_number;
	}
	else
	{
		REG_JPEG_ENCODER_CONT_SHOT_FRAME_NUM=0;
	}

	jpeg_encoder_ctrl_reg |= JPEG_ENCODER_INT_ENABLE_BIT;
	SET_JPEG_ENCODER_QUALITY(capture_para->image_quality);
	REG_JPEG_ENCODER_STOP_ADDR=(capture_para->jpeg_file_start_address1+capture_para->jpeg_file_buffer_size1-4)&0xFFFFFFFC;

	jpeg_encoder_operation_state=JPEG_ENCODER_ENCODING_STATE;
	jpeg_encoder_ctrl_reg|=JPEG_ENCODER_ENABLE_BIT;
	REG_JPEG_ENCODER_CTRL=jpeg_encoder_ctrl_reg;												  
			   
}   
#endif   /// DRV_JPG_DATA_PATH_28_SERIES
#endif   /// DRV_JPG_DATA_PATH_17_SERIES, DRV_JPG_DATA_PATH_19_SERIES, DRV_JPG_DATA_PATH_28_SERIES