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
 *   camera_process.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6226M,MT6227,MT6228,MT6229,MT6230,MT6225
 *
 * Description:
 * ------------
 *   This file is intends for Camera Application Process.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#include "drv_comm.h"
#include "stdio.h"
#include "string.h"
#include "IntrCtrl.h"
#include "gpio_sw.h"
#include "jpeg.h"
#include "exif.h"
#include "lcd_if.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "img_comm.h"
#include "drv_features.h"
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#include "sccb.h"
#include "isp_if.h"
#include "med_api.h"
#include "image_effect.h"
#if (defined(ISP_SUPPORT))
#include "image_sensor.h"
#include "camera_para.h"
#endif
#include "ae_awb.h"
#include "af.h"
#include "imgproc.h"
#include "resizer.h"
#include "isp_device_if.h"
#if (defined(YUV_SENSOR_SUPPORT))
#include "isp_yuv_if.h"
#endif
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
#include "lens_module.h"
#endif

#include "med_status.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#if (!defined(DRV_ISP_6219_SERIES))
#include "isp_flashlight.h"
#endif

#if (!defined(__MTK_TARGET__))
kal_uint8 current_lcd_rotate_value;
#endif

extern kal_eventgrpid camera_isp_event_id;
#if ((!defined(DRV_ISP_6219_SERIES))&&defined(ISP_SUPPORT))
extern ae_lut_info_struct lut_info;
#endif

kal_uint32 camera_process_stage=0;
camera_preview_process_struct isp_preview_config_data;
camera_capture_jpeg_struct isp_capture_jpeg_data;
camera_capture_barcode_struct isp_capture_barcode_data;
camera_capture_mem_struct isp_capture_mem_data;
mpeg4_encode_process_struct mpeg4_encode_data;
MP4ENC_SETUP_STRUCT mpeg4_encode_config_data;
kal_bool MPEG4_RECODE_START=KAL_FALSE;
mjpeg_encode_process_struct mjpeg_encode_data;
kal_bool mjpeg_encode_enable=KAL_FALSE;
kal_uint16 mjpeg_sensor_frame_rate=0;
kal_bool release_mpeg4_datapath_mem_flag=KAL_TRUE;

#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
#endif

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
camera_preview_data_path_struct			ipp_preview_data;
camera_capture_jpeg_data_path_struct 	ipp_capture_jpeg_data;
camera_capture_barcode_data_path_struct ipp_capture_barcode_data;
camera_capture_mem_data_path_struct    ipp_capture_mem_data;
video_encode_data_path_struct				ipp_video_encode_data;
volatile kal_bool wait_last_capture_frame=KAL_FALSE;
volatile kal_bool sensor_vd_done=KAL_FALSE;
#endif
#if (!defined(DRV_ISP_6219_SERIES))
void (*cam_preview_cb) (kal_uint8 return_code);
void (*cam_focus_cb) (kal_uint8 return_code);
#endif

kal_bool isp_digital_zoom_flag=KAL_FALSE;
volatile kal_uint8 isp_digital_zoom_factor=10;

ISP_OPERATION_STATE_ENUM isp_operation_state=ISP_IDLE_STATE;
kal_uint16 isp_grab_width,isp_grab_height,isp_grab_start_x,isp_grab_start_y;
kal_uint8 isp_sub_sample_mode,isp_horizontal_subsample=1,isp_vertical_subsample=1;
kal_bool isp_enter_exit_process_flag=KAL_FALSE;
volatile kal_bool isp_idle_done_flag=KAL_FALSE;
kal_uint16 exif_isp_target_width=0, exif_isp_target_height=0;

image_sensor_exposure_window_struct exposure_window;
image_sensor_config_struct sensor_config_data;
kal_int8 sensor_err_check=1;
isp_fast_zoom_struct isp_fast_zoom_data={KAL_FALSE,KAL_TRUE,40,2,3};
kal_uint8 fast_zoom_count=0;


/*************************************************************************
* FUNCTION
*	get_max_digital_zoom_factor
*
* DESCRIPTION
*	This function is for getting maximum digital zoom factor
*
* PARAMETERS
*	target size
*
* RETURNS
*	max zoom factor
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 get_max_digital_zoom_factor(kal_uint16 target_width, kal_uint16 target_height)
{
#if (defined(ISP_SUPPORT))
	kal_uint8 max_zf, max_zf_tmp;

#if(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	max_zf=exposure_window.exposure_window_width*10/target_width;
	max_zf_tmp=exposure_window.exposure_window_height*10/target_height;
#elif(defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	max_zf=exposure_window.exposure_window_width*10/(target_width+2);
	max_zf_tmp=exposure_window.exposure_window_height*10/(target_height+2);
#endif

	if(max_zf_tmp < max_zf)
		max_zf = max_zf_tmp;

	if(max_zf < 10)
		max_zf = 10;

	if(max_zf > 40)
		max_zf = 40;

	return max_zf;
#endif
}

void	align_center_point(void)
{
	kal_uint16 isp_org_center_x=0,isp_org_center_y=0, isp_center_x=0,isp_center_y=0;
	kal_int8 delta_center_x=0,delta_center_y=0;

	isp_org_center_x=exposure_window.grab_start_x + (exposure_window.exposure_window_width&0xFFFE)/2;
	isp_org_center_y=exposure_window.grab_start_y + (exposure_window.exposure_window_height&0xFFFE)/2;
	if(isp_digital_zoom_factor!=10)
	{
		isp_center_x=isp_grab_start_x + isp_grab_width/2;
		isp_center_y=isp_grab_start_y + isp_grab_height/2;
		delta_center_x=isp_org_center_x-isp_center_x;
		delta_center_y=isp_org_center_y-isp_center_y;
		if(delta_center_x==1)
			isp_grab_width+=2;
		else if(delta_center_x==2)
			isp_grab_start_x+=2;
		else if(delta_center_x==-1)
			isp_grab_width-=2;
		else if(delta_center_x==-2)
			isp_grab_start_x-=2;

		if(delta_center_y==1)
			isp_grab_height+=2;
		else if(delta_center_y==2)
			isp_grab_start_y+=2;
		else if(delta_center_y==-1)
			isp_grab_height-=2;
		else if(delta_center_y==-2)
			isp_grab_start_y-=2;
	}
}

/*************************************************************************
* FUNCTION
*	isp_digital_zoom
*
* DESCRIPTION
*	This function is for setting the digital zoom factor
*
* PARAMETERS
*	zoom_factor : ISP digital zoom factor
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void isp_digital_zoom(kal_uint8 zoom_factor)
{
#if (defined(ISP_SUPPORT))
	kal_uint32 save_irq_mask;
	kal_uint16 temp_grab_size;

	if ((isp_operation_state!=ISP_PREVIEW_STATE)&&
		 (isp_operation_state!=ISP_MPEG4_ENCODE_STATE)&&
		 (isp_operation_state!=ISP_MJPEG_ENCODE_STATE)&&
		 (isp_operation_state!=ISP_VIDEO_FULLDUPLEX_ENCODE_STATE))
		ASSERT(0);
	isp_digital_zoom_factor=zoom_factor;

	save_irq_mask=SaveAndSetIRQMask();
	if (isp_digital_zoom_flag==KAL_TRUE)
		isp_digital_zoom_flag=KAL_FALSE;
	RestoreIRQMask(save_irq_mask);

#if (!defined(YUV_SENSOR_SUPPORT))
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR)/isp_digital_zoom_factor)&0xFFFE ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR)/isp_digital_zoom_factor)&0xFFFE ;

	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFE);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if (isp_operation_state==ISP_PREVIEW_STATE)
	{
		if ((isp_preview_config_data.target_width * exposure_window.exposure_window_height) >=
			 (isp_preview_config_data.target_height * exposure_window.exposure_window_width))
		{	/* x limit */
			temp_grab_size=isp_grab_height;
			isp_grab_height=(isp_grab_width * isp_preview_config_data.target_height/
								 isp_preview_config_data.target_width)&0xFFFE;
			isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
		}
		else
		{	/* y limit */
			temp_grab_size=isp_grab_width;
			isp_grab_width=(isp_grab_height * isp_preview_config_data.target_width/
								isp_preview_config_data.target_height)&0xFFFE;
			isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
		}
	}
	else if ((isp_operation_state==ISP_MPEG4_ENCODE_STATE) || (isp_operation_state==ISP_VIDEO_FULLDUPLEX_ENCODE_STATE))
	{
		if ((mpeg4_encode_data.mpeg4_image_width * exposure_window.exposure_window_height) >=
			 (mpeg4_encode_data.mpeg4_image_height * exposure_window.exposure_window_width))
		{	/* x limit */
			temp_grab_size=isp_grab_height;
			isp_grab_height=(isp_grab_width * mpeg4_encode_data.mpeg4_image_height/
								 mpeg4_encode_data.mpeg4_image_width)&0xFFFE;
			isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
		}
		else
		{	/* y limit */
			temp_grab_size=isp_grab_width;
			isp_grab_width=(isp_grab_height * mpeg4_encode_data.mpeg4_image_width/
								mpeg4_encode_data.mpeg4_image_height)&0xFFFE;
			isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
		}
	}
	
	isp_grab_start_x-=(((isp_grab_width*(isp_horizontal_subsample-1))>>1)&0xFFFE);
	isp_grab_start_y-=((isp_grab_height*(isp_vertical_subsample-1))>>1);
	
	align_center_point();

#if (defined(DRV_ISP_6219_SERIES))
	if ((isp_grab_width<=MAX_RESIZER_INPUT_WIDTH) && (isp_grab_height<=MAX_RESIZER_INPUT_HEIGHT))
	{
		isp_sub_sample_mode=CAMERA_SUB_SAMPLE_1_1;
		if (isp_operation_state==ISP_PREVIEW_STATE)
		{
		isp_preview_config_data.source_width=isp_grab_width;
		isp_preview_config_data.source_height=isp_grab_height;
	}
		else
		{
			mpeg4_encode_data.image_source_width=isp_grab_width;
			mpeg4_encode_data.image_source_height=isp_grab_height;
		}
	}
	else if ((isp_grab_width<=(MAX_RESIZER_INPUT_WIDTH<<1)) && (isp_grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<1)))
	{
		isp_sub_sample_mode=CAMERA_SUB_SAMPLE_1_2;
		if (isp_operation_state==ISP_PREVIEW_STATE)
		{
		isp_preview_config_data.source_width=isp_grab_width>>1;
		isp_preview_config_data.source_height=isp_grab_height>>1;
	}
		else
		{
			mpeg4_encode_data.image_source_width=isp_grab_width>>1;
			mpeg4_encode_data.image_source_height=isp_grab_height>>1;
		}
	}
	else if ((isp_grab_width<=(MAX_RESIZER_INPUT_WIDTH<<2)) && (isp_grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<2)))
	{
		isp_sub_sample_mode=CAMERA_SUB_SAMPLE_1_4;
		if (isp_operation_state==ISP_PREVIEW_STATE)
		{
		isp_preview_config_data.source_width=isp_grab_width>>2;
		isp_preview_config_data.source_height=isp_grab_height>>2;
		}
		else
		{
			mpeg4_encode_data.image_source_width=isp_grab_width>>2;
			mpeg4_encode_data.image_source_height=isp_grab_height>>2;
		}
	}
	else if ((isp_grab_width<=(MAX_RESIZER_INPUT_WIDTH<<3)) && (isp_grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<3)))
	{
		isp_sub_sample_mode=CAMERA_SUB_SAMPLE_1_8;
		if (isp_operation_state==ISP_PREVIEW_STATE)
		{
		isp_preview_config_data.source_width=isp_grab_width>>3;
		isp_preview_config_data.source_height=isp_grab_height>>3;
	}
		else
		{
			mpeg4_encode_data.image_source_width=isp_grab_width>>3;
			mpeg4_encode_data.image_source_height=isp_grab_height>>3;
		}
	}
#elif(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	//Camera Preview
	if((isp_grab_width>(isp_preview_config_data.target_width<<2)) ||
		(isp_grab_height>(isp_preview_config_data.target_height<<2)))
	{ /* grab size > taget size *4 => ISP subsample 4x */
		isp_preview_config_data.source_width=isp_grab_width>>2;
		isp_preview_config_data.source_height=isp_grab_height>>2;
	}
	else if((isp_grab_width>(isp_preview_config_data.target_width<<1)) ||
		(isp_grab_height>(isp_preview_config_data.target_height<<1)))
	{ /* grab size > taget size *2 => ISP subsample 2x */
		isp_preview_config_data.source_width=isp_grab_width>>1;
		isp_preview_config_data.source_height=isp_grab_height>>1;
	}
	else
	{
		if((isp_grab_width>=isp_preview_config_data.target_width+2)&&
			(isp_grab_height>=isp_preview_config_data.target_height+2))
		{
			isp_preview_config_data.source_width=isp_preview_config_data.target_width+2;
			isp_preview_config_data.source_height=isp_preview_config_data.target_height+2;
		}
		else
		{
			if((isp_grab_width==isp_preview_config_data.target_width)&&
				(isp_grab_height==isp_preview_config_data.target_height))
			{
				isp_preview_config_data.source_width=isp_grab_width-2;
				isp_preview_config_data.source_height=isp_grab_height-2;
			}
			else
			{
				isp_preview_config_data.source_width=isp_grab_width;
				isp_preview_config_data.source_height=isp_grab_height;
			}

		}
	}

	//Video Encode
	if((isp_grab_width>(mpeg4_encode_data.mpeg4_image_width<<2)) ||
		(isp_grab_height>(mpeg4_encode_data.mpeg4_image_height<<2)))
	{	/* grab size > taget size *4 => ISP subsample 4x */
		mpeg4_encode_data.image_source_width=isp_grab_width>>2;
		mpeg4_encode_data.image_source_height=isp_grab_height>>2;
	}
	else if((isp_grab_width>(mpeg4_encode_data.mpeg4_image_width<<1)) ||
		(isp_grab_height>(mpeg4_encode_data.mpeg4_image_height<<1)))
	{	/* grab size > taget size *2 => ISP subsample 2x */
		mpeg4_encode_data.image_source_width=isp_grab_width>>1;
		mpeg4_encode_data.image_source_height=isp_grab_height>>1;
	}
	else
	{
		if((isp_grab_width>=mpeg4_encode_data.mpeg4_image_width+2)&&
			(isp_grab_height>=mpeg4_encode_data.mpeg4_image_height+2))
		{
			mpeg4_encode_data.image_source_width=mpeg4_encode_data.mpeg4_image_width+2;
			mpeg4_encode_data.image_source_height=mpeg4_encode_data.mpeg4_image_height+2;
		}
		else
		{
			if((isp_grab_width==mpeg4_encode_data.mpeg4_image_width)&&
				(isp_grab_height==mpeg4_encode_data.mpeg4_image_height))
			{
				mpeg4_encode_data.image_source_width=isp_grab_width-2;
				mpeg4_encode_data.image_source_height=isp_grab_height-2;
			}
			else
			{
				mpeg4_encode_data.image_source_width=isp_grab_width;
				mpeg4_encode_data.image_source_height=isp_grab_height;
			}
		}
	}
#if(defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ipp_preview_data.image_src_width=isp_preview_config_data.source_width;
	ipp_preview_data.image_src_height=isp_preview_config_data.source_height;
	ipp_video_encode_data.image_src_width=mpeg4_encode_data.image_source_width;
	ipp_video_encode_data.image_src_height=mpeg4_encode_data.image_source_height;
#endif
#endif

#else
	isp_yuv_digital_zoom(zoom_factor);
#endif /* YUV_SENSOR_SUPPORT */

	save_irq_mask=SaveAndSetIRQMask();
	isp_digital_zoom_flag=KAL_TRUE;
	ENABLE_CAMERA_FRAME_READY_INT;
	RestoreIRQMask(save_irq_mask);

	isp_preview_config_data.zoom_factor=isp_digital_zoom_factor;

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
	apply_camera_shading_to_reg(CAMERA_COMP_PREVIEW_NORMAL_SET);
	if(camera_oper_data.preview_defect_table_enable==KAL_TRUE)
	{
		load_defect_table_para(DEFECT_MODE_PREVIEW);
		ENABLE_DEFECT_CORRECTION;
	}
	else
		DISABLE_DEFECT_CORRECTION;
#endif
	camera_process_stage|=LEAVE_ISP_DIGITAL_ZOOM;
#endif
}

/*************************************************************************
* FUNCTION
*	isp_fast_zoom_setting
*
* DESCRIPTION
*	This function start/stop fast zoom function
*
* PARAMETERS
*	zoom_data : the parameters for fast zoom in
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void isp_fast_zoom_setting(isp_fast_zoom_struct zoom_data)
{
#if (defined(ISP_SUPPORT))
	isp_fast_zoom_data.start=zoom_data.start;
	isp_fast_zoom_data.zoom_in=zoom_data.zoom_in;
	isp_fast_zoom_data.zoom_limit=zoom_data.zoom_limit;
	isp_fast_zoom_data.zoom_step=zoom_data.zoom_step;
	isp_fast_zoom_data.zoom_speed=zoom_data.zoom_speed;
	fast_zoom_count=0;
	if(isp_fast_zoom_data.start==KAL_TRUE)
	{
		isp_digital_zoom_flag=KAL_TRUE;
		ENABLE_CAMERA_FRAME_READY_INT;
	}
	else	/* stop fast zoom in */
	{
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
	apply_camera_shading_to_reg(CAMERA_COMP_PREVIEW_NORMAL_SET);
	if(camera_oper_data.preview_defect_table_enable==KAL_TRUE)
	{
		load_defect_table_para(DEFECT_MODE_PREVIEW);
		ENABLE_DEFECT_CORRECTION;
	}
	else
		DISABLE_DEFECT_CORRECTION;
#endif
	}
	camera_process_stage|=LEAVE_ISP_FAST_ZOOM_SETTING;
#endif
}

kal_uint8 get_isp_digital_zoom_factor(void)
{
#if (defined(ISP_SUPPORT))
	return  isp_digital_zoom_factor;
#endif
}

kal_uint8 isp_led_setting(kal_bool light)
{
#if (!defined(DRV_ISP_6219_SERIES))
	if(image_sensor_func->set_flashlight!=0)
	{
		if(light==KAL_TRUE)
			image_sensor_func->set_flashlight(KAL_TRUE);
		else
			image_sensor_func->set_flashlight(KAL_FALSE);

		return KAL_TRUE;
	}
	else
		return KAL_FALSE;
#endif
}

/*************************************************************************
* FUNCTION
*	camera_preview_process
*
* DESCRIPTION
*	This function starts camera preview
*
* PARAMETERS
*	isp_data : the parameters for camera preview process
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 camera_preview_process(camera_preview_process_struct *isp_data)
{
#if (defined(ISP_SUPPORT))
	volatile kal_uint32 *resizer_buf_ptr;
	kal_uint32 event_group;
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_PREVIEW_ID;
	lcd_frame_update_struct lcd_data;
	kal_uint16 temp_grab_size;
	volatile kal_uint16 i=0,j=0;
	volatile kal_uint8 sensor_check_count;
	kal_uint8 sensor_fail_count;

#if (!defined(YUV_SENSOR_SUPPORT))
	if (sensor_err_check<0)
		return KAL_FALSE;

#if defined(ANALOG_TV_SUPPORT)  
       if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif  	
{  //ANALOG_TV_SUPPORT
	if (isp_operation_state!=ISP_STANDBY_STATE)
		ASSERT(0);

	/* the preview image size is great than frame buffer size */
	if ((((isp_data->target_width) * (isp_data->target_height))<<1) > isp_data->frame_buffer_size)
		ASSERT(0);

	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data

#if (defined(AF_SUPPORT))
	if(isp_data->continue_capture==0)
	{
		if (af_operation_state != AF_STANDBY_STATE)//prevent scenario error
		{
   			camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
		}
		else
		{
			lens_func->lens_af_move_to((kal_int32)camera_lens.INFO.af_hyper_pos);
			dsc_status.af.index=0xFF;
		}
	}
#endif

#if (!defined(DRV_ISP_6219_SERIES))
	lut_info.videomode=KAL_FALSE;
#endif
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_on_off(KAL_TRUE);
	awb_on_off(KAL_TRUE);
	awb_set_gain();
#endif
	DISABLE_CAMERA_IDLE_INT;
	ENABLE_AE_COUNT;
	ENABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;

#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
   // Disable AE Count before Start Preview
	DISABLE_AE_COUNT;
	REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	DISABLE_CMOS_SESNOR;
#endif
	sensor_config_data.isp_op_mode=ISP_PREVIEW_MODE;
	sensor_config_data.image_mirror=isp_data->image_mirror;
	sensor_config_data.frame_rate=isp_data->frame_rate;
	exposure_window.image_target_width=isp_data->target_width;
	exposure_window.image_target_height=isp_data->target_height;
	exposure_window.current_exposure_pixel=exposure_window.exposure_pixel=1;
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);

	/* accorind the zoom factor to calculate the grab window area */
	isp_horizontal_subsample=exposure_window.isp_hsub_factor;
   isp_vertical_subsample=exposure_window.isp_vsub_factor;
	isp_digital_zoom_factor=isp_data->zoom_factor;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;

	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFE);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((isp_data->target_width * exposure_window.exposure_window_height) >=
		 (isp_data->target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * isp_data->target_height/isp_data->target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * isp_data->target_width/isp_data->target_height)&0xFFFE;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
	}

	isp_grab_start_x-=(((isp_grab_width*(isp_horizontal_subsample-1))>>1)&0xFFFE);
	isp_grab_start_y-=((isp_grab_height*(isp_vertical_subsample-1))>>1);

	align_center_point();
	SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
	SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_config((isp_grab_width*isp_horizontal_subsample),(isp_grab_height*isp_vertical_subsample));
#endif
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
	DISABLE_1024_GAMMA_TABLE;
#endif

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
	apply_camera_shading_to_reg(CAMERA_COMP_PREVIEW_NORMAL_SET);
	if(camera_oper_data.preview_defect_table_enable==KAL_TRUE)
	{
		load_defect_table_para(DEFECT_MODE_PREVIEW);
		ENABLE_DEFECT_CORRECTION;
	}
	else
		DISABLE_DEFECT_CORRECTION;
#endif

#if (defined(DRV_ISP_6219_SERIES))
	/* according the maximum size of resizer input we define to calculate the the image size
	   of resizer input */
	if ((isp_grab_width<=MAX_RESIZER_INPUT_WIDTH) && (isp_grab_height<=MAX_RESIZER_INPUT_HEIGHT))
	{
		isp_sub_sample_mode=CAMERA_SUB_SAMPLE_1_1;
		isp_preview_config_data.source_width=isp_grab_width;
		isp_preview_config_data.source_height=isp_grab_height;
	}
	else if ((isp_grab_width<=(MAX_RESIZER_INPUT_WIDTH<<1)) && (isp_grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<1)))
	{
		isp_sub_sample_mode=CAMERA_SUB_SAMPLE_1_2;
		isp_preview_config_data.source_width=isp_grab_width>>1;
		isp_preview_config_data.source_height=isp_grab_height>>1;
	}
	else if ((isp_grab_width<=(MAX_RESIZER_INPUT_WIDTH<<2)) && (isp_grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<2)))
	{
		isp_sub_sample_mode=CAMERA_SUB_SAMPLE_1_4;
		isp_preview_config_data.source_width=isp_grab_width>>2;
		isp_preview_config_data.source_height=isp_grab_height>>2;
	}
	else if ((isp_grab_width<=(MAX_RESIZER_INPUT_WIDTH<<3)) && (isp_grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<3)))
	{
		isp_sub_sample_mode=CAMERA_SUB_SAMPLE_1_8;
		isp_preview_config_data.source_width=isp_grab_width>>3;
		isp_preview_config_data.source_height=isp_grab_height>>3;
	}
	SET_SUB_SAMPLE_MODE(isp_sub_sample_mode);
#elif  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ENABLE_VERTICAL_SUB_SAMPLE;
	ENABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));	
	SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
	if((isp_grab_width>(isp_data->target_width<<2)) || (isp_grab_height>(isp_data->target_height<<2)))
	{ /* grab size > taget size *4 => ISP subsample 4x */
		SET_HSUB_DST_SIZE(isp_grab_width>>2);
		SET_VSUB_DST_SIZE(isp_grab_height>>2);
		isp_preview_config_data.source_width=isp_grab_width>>2;
		isp_preview_config_data.source_height=isp_grab_height>>2;
	}
	else if((isp_grab_width>(isp_data->target_width<<1)) || (isp_grab_height>(isp_data->target_height<<1)))
	{ /* grab size > taget size *2 => ISP subsample 2x */
		SET_HSUB_DST_SIZE(isp_grab_width>>1);
		SET_VSUB_DST_SIZE(isp_grab_height>>1);
		isp_preview_config_data.source_width=isp_grab_width>>1;
		isp_preview_config_data.source_height=isp_grab_height>>1;
	}
	else
	{
		if((isp_grab_width>=((isp_data->target_width)+2)) && (isp_grab_height>=((isp_data->target_height)+2)))
		{
			SET_HSUB_DST_SIZE(isp_data->target_width+2);
			SET_VSUB_DST_SIZE(isp_data->target_height+2);
			isp_preview_config_data.source_width=isp_data->target_width+2;
			isp_preview_config_data.source_height=isp_data->target_height+2;
		}
		else
		{
			if((isp_grab_width==(isp_data->target_width)) && (isp_grab_height==(isp_data->target_height)))
			{
				SET_HSUB_DST_SIZE(isp_grab_width-2);
				SET_VSUB_DST_SIZE(isp_grab_height-2);
				isp_preview_config_data.source_width=isp_grab_width-2;
				isp_preview_config_data.source_height=isp_grab_height-2;
			}
			else
			{
				SET_HSUB_DST_SIZE(isp_grab_width);
				SET_VSUB_DST_SIZE(isp_grab_height);
				isp_preview_config_data.source_width=isp_grab_width;
				isp_preview_config_data.source_height=isp_grab_height;
			}
		}
	}
#endif
}  //ANALOG_TV_SUPPORT
#endif /* YUV_SENSOR_SUPPORT */

	isp_preview_config_data.image_mirror=isp_data->image_mirror;
	isp_preview_config_data.frame_rate=isp_data->frame_rate;
	isp_preview_config_data.target_width=isp_data->target_width;
	isp_preview_config_data.target_height=isp_data->target_height;

	isp_preview_config_data.lcd_id=isp_data->lcd_id;
	isp_preview_config_data.lcm_start_x=isp_data->lcm_start_x;
	isp_preview_config_data.lcm_start_y=isp_data->lcm_start_y;
	isp_preview_config_data.lcm_end_x=isp_data->lcm_end_x;
	isp_preview_config_data.lcm_end_y=isp_data->lcm_end_y;
	isp_preview_config_data.roi_offset_x=isp_data->roi_offset_x;
	isp_preview_config_data.roi_offset_y=isp_data->roi_offset_y;
	isp_preview_config_data.update_layer=isp_data->update_layer;
	isp_preview_config_data.hw_update_layer=isp_data->hw_update_layer;
	isp_preview_config_data.rotate_value=isp_data->rotate_value;
	isp_preview_config_data.continue_capture=isp_data->continue_capture;
	isp_preview_config_data.intmem_start_address=isp_data->intmem_start_address;
	isp_preview_config_data.intmem_size=isp_data->intmem_size;
	isp_preview_config_data.extmem_start_address=isp_data->extmem_start_address;
	isp_preview_config_data.extmem_size=isp_data->extmem_size;
	isp_preview_config_data.zoom_factor=isp_data->zoom_factor;
	isp_preview_config_data.target_width=isp_data->target_width;
	isp_preview_config_data.target_height=isp_data->target_height;
	isp_preview_config_data.preview_offset_x=isp_data->preview_offset_x;
	isp_preview_config_data.preview_offset_y=isp_data->preview_offset_y;
	isp_preview_config_data.camera_offset_x=isp_data->camera_offset_x;
	isp_preview_config_data.camera_offset_y=isp_data->camera_offset_y;
	isp_preview_config_data.frame_buffer_address=isp_data->frame_buffer_address;
	isp_preview_config_data.frame_buffer_size=isp_data->frame_buffer_size;
	isp_preview_config_data.frame_buffer_address1=isp_data->frame_buffer_address1;
	isp_preview_config_data.frame_buffer_size1=isp_data->frame_buffer_size1;
	isp_preview_config_data.roi_background_color=isp_data->roi_background_color;
	isp_preview_config_data.lcd_update=isp_data->lcd_update;
	isp_preview_config_data.cam_preview_cb=isp_data->cam_preview_cb;
#if (!defined(DRV_ISP_6219_SERIES))
	cam_preview_cb=isp_data->cam_preview_cb;
#endif
#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)  
   if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif 	
{  //ANALOG_TV_SUPPORT
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	intmem_init((kal_uint32 *) isp_preview_config_data.intmem_start_address,
					isp_preview_config_data.intmem_size);
	extmem_init((kal_uint32 *) isp_preview_config_data.extmem_start_address,
					isp_preview_config_data.extmem_size);
#endif

	lcd_data.module_id=LCD_UPDATE_MODULE_MEDIA;
	lcd_data.lcd_id=isp_preview_config_data.lcd_id;
	lcd_data.fb_update_mode=LCD_HW_TRIGGER_MODE;
	lcd_data.lcm_start_x=isp_preview_config_data.lcm_start_x;
	lcd_data.lcm_start_y=isp_preview_config_data.lcm_start_y;
	lcd_data.lcm_end_x=isp_preview_config_data.lcm_end_x;
	lcd_data.lcm_end_y=isp_preview_config_data.lcm_end_y;
	lcd_data.roi_offset_x=isp_preview_config_data.roi_offset_x;
	lcd_data.roi_offset_y=isp_preview_config_data.roi_offset_y;
	lcd_data.update_layer=isp_preview_config_data.update_layer;
	lcd_data.hw_update_layer=isp_preview_config_data.hw_update_layer;
	lcd_data.block_mode_flag=KAL_TRUE;
	lcd_data.lcd_block_mode_cb=NULL;
#if (!defined(DRV_ISP_6219_SERIES))
	lcd_data.roi_background_color=isp_data->roi_background_color;
#endif

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	lcd_data.memory_output=KAL_FALSE;
#endif
}    //ANALOG_TV_SUPPORT
#endif /* YUV_SENSOR_SUPPORT */

	isp_preview_config_data.contrast_level=isp_data->contrast_level;
	isp_preview_config_data.brightness_level=isp_data->brightness_level;
	isp_preview_config_data.hue_value=isp_data->hue_value;
	isp_preview_config_data.saturation_value=isp_data->saturation_value;
	isp_preview_config_data.wb_mode=isp_data->wb_mode;
	isp_preview_config_data.ev_value=isp_data->ev_value;
	isp_preview_config_data.banding_freq=isp_data->banding_freq;
	isp_preview_config_data.image_effect=isp_data->image_effect;
	isp_preview_config_data.night_mode=isp_data->night_mode;

#if (!defined(DRV_ISP_6219_SERIES))
	/* ISP Setting */
	isp_preview_config_data.dsc_mode      				= isp_data->dsc_mode;
	isp_preview_config_data.ae_metering_mode 			= isp_data->ae_metering_mode;
	isp_preview_config_data.af_mode      				= isp_data->af_mode;
	isp_preview_config_data.af_metering_mode 			= isp_data->af_metering_mode;
	isp_preview_config_data.tv_setting      			= isp_data->tv_setting;
	isp_preview_config_data.av_setting      			= isp_data->av_setting;
	isp_preview_config_data.iso_setting      			= isp_data->iso_setting;
	isp_preview_config_data.flash_mode      			= isp_data->flash_mode;

	isp_preview_config_data.af_zone0_x      			= isp_data->af_zone0_x;
	isp_preview_config_data.af_zone0_y      			= isp_data->af_zone0_y;
	isp_preview_config_data.af_zone1_x      			= isp_data->af_zone1_x;
	isp_preview_config_data.af_zone1_y      			= isp_data->af_zone1_y;
	isp_preview_config_data.af_zone2_x      			= isp_data->af_zone2_x;
	isp_preview_config_data.af_zone2_y      			= isp_data->af_zone2_y;
	isp_preview_config_data.af_zone3_x      			= isp_data->af_zone3_x;
	isp_preview_config_data.af_zone3_y      			= isp_data->af_zone3_y;
	isp_preview_config_data.af_zone4_x      			= isp_data->af_zone4_x;
	isp_preview_config_data.af_zone4_y      			= isp_data->af_zone4_y;
	isp_preview_config_data.cam_focus_cb				= isp_data->cam_focus_cb;
	cam_focus_cb												= isp_data->cam_focus_cb;
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	isp_preview_config_data.tv_output						=	isp_data->tv_output;
	isp_preview_config_data.tv_output_width				=	isp_data->tv_output_width;
	isp_preview_config_data.tv_output_height				=	isp_data->tv_output_height;
	isp_preview_config_data.tv_output_offset_x			=	isp_data->tv_output_offset_x;
	isp_preview_config_data.tv_output_offset_y			=	isp_data->tv_output_offset_y;
	isp_preview_config_data.tv_output_buffer1_address	=	isp_data->tv_output_buffer1_address;
	isp_preview_config_data.tv_output_buffer2_address	=	isp_data->tv_output_buffer2_address;
	isp_preview_config_data.tv_output_buffer_size		=	isp_data->tv_output_buffer_size;

	/* Prepare IPP Data */
	ipp_preview_data.intmem_start_address 				= isp_data->intmem_start_address;
	ipp_preview_data.intmem_size          				= isp_data->intmem_size;
	ipp_preview_data.extmem_start_address 				= isp_data->extmem_start_address;
	ipp_preview_data.extmem_size          				= isp_data->extmem_size;

	ipp_preview_data.image_src_width		 				= isp_preview_config_data.source_width;
	ipp_preview_data.image_src_height	 				= isp_preview_config_data.source_height;
	ipp_preview_data.preview_width		 				= isp_preview_config_data.target_width;
	ipp_preview_data.preview_height	 					= isp_preview_config_data.target_height;

	ipp_preview_data.image_pitch_mode  					= isp_data->image_pitch_mode;
	ipp_preview_data.image_data_format 					= isp_data->image_data_format;
	ipp_preview_data.image_pitch_bytes 					= isp_data->image_pitch_bytes;

	ipp_preview_data.overlay_frame_mode			  		= isp_data->overlay_frame_mode;
	ipp_preview_data.overlay_color_depth				= isp_data->overlay_color_depth;
	ipp_preview_data.overlay_frame_source_key	  		= isp_data->overlay_frame_source_key;
	ipp_preview_data.overlay_frame_width				= isp_data->overlay_frame_width;
	ipp_preview_data.overlay_frame_height				= isp_data->overlay_frame_height;
	ipp_preview_data.overlay_frame_buffer_address	= isp_data->overlay_frame_buffer_address;

	ipp_preview_data.frame_buffer_address				= isp_data->frame_buffer_address;
	ipp_preview_data.frame_buffer_size					= isp_data->frame_buffer_size;
	ipp_preview_data.frame_buffer_address1				= isp_data->frame_buffer_address1;
	ipp_preview_data.frame_buffer_size1					= isp_data->frame_buffer_size1;

	ipp_preview_data.tv_output                      = isp_data->tv_output;
	ipp_preview_data.tv_output_width						= isp_data->tv_output_width;
	ipp_preview_data.tv_output_height					= isp_data->tv_output_height;
	ipp_preview_data.tv_output_offset_x					= isp_data->tv_output_offset_x;
	ipp_preview_data.tv_output_offset_y					= isp_data->tv_output_offset_y;
	ipp_preview_data.tv_output_buffer1_address		= isp_data->tv_output_buffer1_address;
	ipp_preview_data.tv_output_buffer2_address		= isp_data->tv_output_buffer2_address;
	ipp_preview_data.tv_rotate_buffer1_address = isp_data->tv_rotate_buffer1_address;
	ipp_preview_data.tv_rotate_buffer2_address = isp_data->tv_rotate_buffer2_address;
	ipp_preview_data.tv_output_buffer_size				= isp_data->tv_output_buffer_size;

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)  
  if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif 	
{  //ANALOG_TV_SUPPORT
	/* Prepare LCD Data */
	lcd_data.hw_trigger_src 								= LCD_HW_TRIGGER_IBW2;
	lcd_data.memory_output=KAL_FALSE;

#if (defined(TV_OUT_SUPPORT))
	if ((isp_data->tv_output==KAL_TRUE)&&
		 ((tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE1)||
		  (tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE4)))
	{
		lcd_data.tv_output=KAL_TRUE;
		lcd_data.tv_output_width=isp_data->tv_output_width;
		lcd_data.tv_output_height=isp_data->tv_output_height;
		lcd_data.tv_output_offset_x=isp_data->tv_output_offset_x;
		lcd_data.tv_output_offset_y=isp_data->tv_output_offset_y;
		lcd_data.tv_output_frame_buffer1_address=isp_data->tv_output_buffer1_address;
		lcd_data.tv_output_frame_buffer2_address=isp_data->tv_output_buffer2_address;
		lcd_data.tv_output_frame_buffer_size=isp_data->tv_output_buffer_size;

		ipp_preview_data.tv_output=KAL_FALSE;
	}
	else
	{
		lcd_data.tv_output=KAL_FALSE;
	}
#endif /* TV_OUT_SUPPORT */
} //ANALOG_TV_SUPPORT
#endif /* YUV_SENSOR_SUPPORT */
#endif

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)  
  if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif 	
{ //ANALOG_TV_SUPPORT

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	config_image_dma(scene_id,isp_data->target_width,isp_data->target_height);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	open_image_data_path(scene_id);
	config_camera_preview_data_path(scene_id,&ipp_preview_data);
#endif

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	resizer_buf_ptr=(kal_uint32 *) (*((volatile unsigned int *)0x8061005C));		/* resizer working memory */
	*resizer_buf_ptr=0x55AAAA55;
#endif

	isp_operation_state=ISP_PREVIEW_STATE;

#if (!defined(DRV_ISP_6219_SERIES))
	/* camera operation setting */
	if(isp_preview_config_data.continue_capture==0)
	{
		camera_operation_setting(CAM_DSC_MODE,isp_preview_config_data.dsc_mode);
		camera_operation_setting(CAM_AE_METERING,isp_preview_config_data.ae_metering_mode);
		camera_operation_setting(CAM_AF_MODE,isp_preview_config_data.af_mode);
		camera_operation_setting(CAM_AF_METERING,isp_preview_config_data.af_metering_mode);
		camera_operation_setting(CAM_SHUTTER_PRIORITY,isp_preview_config_data.tv_setting);
		camera_operation_setting(CAM_APERTURE_PRIORITY,isp_preview_config_data.av_setting);
		camera_operation_setting(CAM_ISO,isp_preview_config_data.iso_setting);
		camera_operation_setting(CAM_FLASH_MODE,isp_preview_config_data.flash_mode);
	}
#endif

	camera_image_setting(CAM_PARAM_EFFECT,isp_preview_config_data.image_effect);
	set_camera_mode_para(CAMERA_PARA_PREVIEW_MODE);
	if(isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)
	{
		camera_image_setting(CAM_PARAM_CONTRAST,isp_preview_config_data.contrast_level);
		camera_image_setting(CAM_PARAM_BRIGHTNESS,isp_preview_config_data.brightness_level);
		camera_image_setting(CAM_PARAM_HUE,isp_preview_config_data.hue_value);
		camera_image_setting(CAM_PARAM_SATURATION,isp_preview_config_data.saturation_value);
	}
	camera_image_setting(CAM_PARAM_WB,isp_preview_config_data.wb_mode);
	camera_image_setting(CAM_PARAM_EXPOSURE,isp_preview_config_data.ev_value);
	camera_image_setting(CAM_PARAM_BANDING,isp_preview_config_data.banding_freq);
	camera_image_setting(CAM_PARAM_NIGHT_MODE,(kal_uint16)isp_preview_config_data.night_mode);
	if((isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL) && (isp_preview_config_data.night_mode))
		set_camera_mode_para(CAMERA_PARA_NIGHT_MODE);
#if (!defined(DRV_ISP_6219_SERIES))
	if(isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)
		set_anti_low_light_para(AE_INDEX_ENV);
#if (!defined(YUV_SENSOR_SUPPORT))
    /* init AE/AWB setting */
	AE_INDEX = ae_apply_index_update(dsc_status.dscmode, dsc_status.ae.iso, AE_INDEX_ENV);
    AE_INDEX_C = AE_INDEX;
    eShutter=AE_LUT[AE_INDEX].shutter;		        /* Get Shutter */
    	sensor_pregain=ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);     /* Get Gain */	
    isp_pregain=AE_LUT[AE_INDEX].ispgain;
    pregain=sensor_pregain*isp_pregain/BASEGAIN;
    image_sensor_func->set_sensor_eshutter(eShutter);
    image_sensor_func->set_sensor_gain(sensor_pregain);
    ae_set_isp_pregain();
#endif
#endif

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	wait_first_frame_flag=KAL_TRUE;
	isp_preview_frame=0;
	SET_CAMERA_PREVIEW_MODE;
	SET_CAMERA_FRAME_RATE(0);
#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
   // Enable AE Count before Start Preview
	REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
	ENABLE_AE_COUNT;
#endif
#if  (defined(DRV_ISP_6228_SERIES))
	RESET_ISP;
	CLEAR_RESET_ISP;
#endif

   #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
      ENABLE_CAMERA_ISP_DONE_INT
      ENABLE_LCD_TRANSFER_COMPLETE_INT
   #endif

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ENABLE_CMOS_SESNOR;
#endif
	ENABLE_VIEW_FINDER_MODE;

	ae_awb_cal_complete=1;
	isp_preview_2a_enable=0;
	ae_count=0;
	hist_idx=0;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	sensor_check_count=0;
	sensor_fail_count=0;
	kal_sleep_task(10);
	while (sensor_check_count<=25)
	{
		kal_sleep_task(10);
		if ((*resizer_buf_ptr==0x55AAAA55) && (ae_count==0))
		{
			if (sensor_check_count==25)
			{
				sensor_fail_count++;
				if(sensor_fail_count>2)
					return KAL_FALSE;

				ae_on_off(KAL_TRUE);
				awb_on_off(KAL_TRUE);
				awb_set_gain();

				DISABLE_VIEW_FINDER_MODE;

				RESZ_Stop(scene_id);
				RESZ_Close(scene_id);
				clean_imgprc_coefficient(scene_id);
				IMGPROC_Stop(scene_id);
				IMGPROC_Close(scene_id);
				stop_image_dma(scene_id);
				IMGDMA_Close(scene_id);

				intmem_deinit();
				extmem_deinit();

				kal_set_eg_events(camera_isp_event_id,0,KAL_AND);

				ENABLE_CMOS_SESNOR;
				REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;		/* reset CMOS senosr */
				for (i=0;i<0x1000;i++);
				REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;

				image_sensor_func->sensor_init();
				for (i=0;i<0x1000;i++);
				image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);

				intmem_init((kal_uint32 *) isp_preview_config_data.intmem_start_address,
								isp_preview_config_data.intmem_size);
				extmem_init((kal_uint32 *) isp_preview_config_data.extmem_start_address,
								isp_preview_config_data.extmem_size);

				config_image_dma(scene_id,isp_data->target_width,isp_data->target_height);
				config_image_processor(scene_id);
				config_pixel_resizer(scene_id);

				camera_image_setting(CAM_PARAM_EFFECT,isp_preview_config_data.image_effect);
				set_camera_mode_para(CAMERA_PARA_PREVIEW_MODE);
				if(isp_preview_config_data.image_effect==0)
				{
					camera_image_setting(CAM_PARAM_CONTRAST,isp_preview_config_data.contrast_level);
					camera_image_setting(CAM_PARAM_BRIGHTNESS,isp_preview_config_data.brightness_level);
					camera_image_setting(CAM_PARAM_HUE,isp_preview_config_data.hue_value);
					camera_image_setting(CAM_PARAM_SATURATION,isp_preview_config_data.saturation_value);
				}
				camera_image_setting(CAM_PARAM_WB,isp_preview_config_data.wb_mode);
				camera_image_setting(CAM_PARAM_EXPOSURE,isp_preview_config_data.ev_value);
				camera_image_setting(CAM_PARAM_BANDING,isp_preview_config_data.banding_freq);
				camera_image_setting(CAM_PARAM_NIGHT_MODE,(kal_uint16)isp_preview_config_data.night_mode);
				if((isp_preview_config_data.image_effect==0) && (isp_preview_config_data.night_mode))
					set_camera_mode_para(CAMERA_PARA_NIGHT_MODE);

				isp_preview_2a_enable=0;
				ae_count=0;
				hist_idx=0;
				sensor_check_count=0;
				resizer_buf_ptr=(kal_uint32 *) (*((volatile unsigned int *)0x8061005C));		/* resizer working memory */
				*resizer_buf_ptr=0x55AAAA55;

				ENABLE_VIEW_FINDER_MODE;
			}
			else
				sensor_check_count++;
		}
		else
			sensor_check_count=26;
	};
#endif

	/* wait sensor first frame coming */
#if (defined(DRV_ISP_6219_SERIES))
  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_FRAME_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);
#else
  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);
#endif

	/* Wait AE AWB Stable */
	if(isp_first_preview_frame==KAL_TRUE)
	{
		for(i=0;i<camera_oper_data.preview_display_wait_frame;i++)
		{
			j=0;
			while(j<9*camera_oper_data.ae_awb_cal_period)
			{
				if(isp_preview_2a_enable==1)
				{
					ae_awb_main();
					isp_preview_2a_enable=0;
					break;
				}
				else
				{
					kal_sleep_task(2);
					j++;
			}
		}
		}
		isp_first_preview_frame=KAL_FALSE;
	}

	if(isp_preview_config_data.lcd_update==KAL_TRUE)
		lcd_fb_update(&lcd_data);	/* wait first frame ready */
	else
	{
		lcd_data.update_layer&=~lcd_data.hw_update_layer;		
		lcd_fb_update(&lcd_data);		
	}		

  	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
#if (defined(DRV_ISP_6219_SERIES))
  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_FRAME_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);
#else
  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);
#endif

}   //ANALOG_TV_SUPPORT

#endif /* YUV_SENSOR_SUPPORT */

	isp_frame_count=0;
	camera_process_stage|=LEAVE_CAMERA_PREVIEW;

#if (defined(YUV_SENSOR_SUPPORT))
	return camera_yuv_preview_process();
#else
#if defined(ANALOG_TV_SUPPORT)  
 if(mmi_get_analog_tv_current_state()==KAL_TRUE)
 {

    kal_prompt_trace(MOD_MED,"camera_yuv_preview_process");
	return camera_yuv_preview_process();
}
else
#endif 	
{
	return KAL_TRUE;
}
#endif /* YUV_SENSOR_SUPPORT */
#endif
}	/* camera_preview_process() */

/*************************************************************************
* FUNCTION
*	exit_camera_preview_process
*
* DESCRIPTION
*	This function stops the camera preview process
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 exit_camera_preview_process(void)
{
#if (defined(ISP_SUPPORT))
   kal_uint32 i=0;
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_PREVIEW_ID;

	if (isp_operation_state!=ISP_PREVIEW_STATE)
		ASSERT(0);

#if (defined(AF_SUPPORT))//prevent scenario error
#if (!defined(YUV_SENSOR_SUPPORT))
	if ((af_operation_state == AF_COLLECT_STATE) || (af_operation_state == AF_SEARCH_STATE))
	{
	   	camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	}
#else
	camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
#endif
#endif

	isp_idle_done_flag=KAL_FALSE;
	ENABLE_CAMERA_IDLE_INT;
	DISABLE_VIEW_FINDER_MODE;
	i=0;
	while(isp_idle_done_flag==KAL_FALSE)
	{
		i++;
		kal_sleep_task(5);
		if(i>9) break;
	}

	DISABLE_CMOS_SESNOR;
	//if(isp_preview_config_data.lcd_update==KAL_TRUE)
	lcd_stop_hw_update(isp_preview_config_data.lcd_id);

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);

	clean_imgprc_coefficient(scene_id);
	IMGPROC_Stop(scene_id);
	IMGPROC_Close(scene_id);

	stop_image_dma(scene_id);
	IMGDMA_Close(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	close_image_data_path(scene_id);
#elif (defined(DRV_ISP_6225_SERIES))
   RESZ_Stop(scene_id);
   RESZ_Close(scene_id);
#endif
	isp_digital_zoom_flag=KAL_FALSE;
	isp_operation_state=ISP_STANDBY_STATE;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	intmem_deinit();
	extmem_deinit();
#endif
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_on_off(KAL_FALSE);
	awb_on_off(KAL_FALSE);
#endif
	camera_process_stage|=LEAVE_EXIT_CAMERA_PREVIEW;

   #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
      DISABLE_CAMERA_ISP_DONE_INT
      DISABLE_LCD_TRANSFER_COMPLETE_INT
   #endif

	return KAL_TRUE;
#endif
}	/* exit_camera_preview_process() */

/*************************************************************************
* FUNCTION
*	camera_capture_jpeg_process
*
* DESCRIPTION
*	This function capture one picture and encode it as jpeg file
*
* PARAMETERS
*	isp_data : the parameters for camera capture and jpeg encode process
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 camera_capture_jpeg_process(camera_capture_jpeg_struct *isp_data)
{
#if (defined(ISP_SUPPORT))

#if (defined(EXIF_SUPPORT))
	exif_cam_para_struct* exif_cam_para_ptr;
 	exif_MTK_para_struct* exif_MTK_para_ptr;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
 	kal_uint16	exif_header_length;
 	kal_uint16	exif_padding_length=0;
#endif
#endif

	kal_uint32 jpeg_file_size=1;
   kal_uint32 event_group;
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_JPEG_ID;
	kal_uint16 temp_grab_size;
	volatile kal_uint8 i;
	kal_uint8 capture_retry_flag=0;
	kal_uint32 isp_capture_shutter;
	kal_uint16 isp_capture_pregain;
#if (!defined(DRV_ISP_6219_SERIES))
    kal_uint32  defect_reg_backup = REG_ISP_DEFECT_PIXEL_CONFIG;
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	lcd_frame_update_struct lcd_data;
	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
#endif

#if (!defined(YUV_SENSOR_SUPPORT))
	ae_count=0;
	hist_idx=0;
	ENABLE_CMOS_SESNOR;
#if (!defined(DRV_ISP_6219_SERIES))
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
// If Burst Capture, do not enable flash LED
if(isp_data->snapshot_number<=1)
#endif
    flashlight_pre_process();
#endif
	DISABLE_AE_COUNT;
#endif /* YUV_SENSOR_SUPPORT */

	isp_capture_jpeg_data.intmem_start_address=isp_data->intmem_start_address;
	isp_capture_jpeg_data.intmem_size=isp_data->intmem_size;
	isp_capture_jpeg_data.extmem_start_address=isp_data->extmem_start_address;
	isp_capture_jpeg_data.extmem_size=isp_data->extmem_size;
	isp_capture_jpeg_data.target_width=isp_data->target_width;
	isp_capture_jpeg_data.target_height=isp_data->target_height;
	exif_isp_target_width=isp_data->target_width;
	exif_isp_target_height=isp_data->target_height;

	isp_capture_jpeg_data.image_quality=isp_data->image_quality;
	isp_capture_jpeg_data.jpeg_gray_mode=isp_data->jpeg_gray_mode;
	isp_capture_jpeg_data.target_buffer_start_address=isp_data->target_buffer_start_address;
	isp_capture_jpeg_data.target_buffer_size=isp_data->target_buffer_size;
#if (defined(DRV_ISP_6225_SERIES))
	isp_capture_jpeg_data.y_address=isp_data->y_address;
	isp_capture_jpeg_data.u_address=isp_data->u_address;
	isp_capture_jpeg_data.v_address=isp_data->v_address;
	isp_capture_jpeg_data.y_size=isp_data->y_size;
	isp_capture_jpeg_data.u_size=isp_data->u_size;
	isp_capture_jpeg_data.v_size=isp_data->v_size;
#endif
	#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
	isp_capture_jpeg_data.memory_output = isp_data->memory_output;						/* output another image for LCD output */
	isp_capture_jpeg_data.memory_output_type = isp_data->memory_output_type;
	isp_capture_jpeg_data.memory_output_width = isp_data->memory_output_width;				/* image width for LCD output */
	isp_capture_jpeg_data.memory_output_height = isp_data->memory_output_height;			/* image height for LCD output */
	isp_capture_jpeg_data.memory_output_buffer_address = isp_data->memory_output_buffer_address;
	isp_capture_jpeg_data.memory_output_buffer_size = isp_data->memory_output_buffer_size;
	#endif

#if (!defined(YUV_SENSOR_SUPPORT))
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	intmem_init((kal_uint32 *) isp_capture_jpeg_data.intmem_start_address,
					isp_capture_jpeg_data.intmem_size);
	extmem_init((kal_uint32 *) isp_capture_jpeg_data.extmem_start_address,
					isp_capture_jpeg_data.extmem_size);
#endif
#endif /* YUV_SENSOR_SUPPORT */

#if (!defined(DRV_ISP_6225_SERIES))
	jpeg_encode_config_data.image_width=isp_data->target_width;
	jpeg_encode_config_data.image_height=isp_data->target_height;
	jpeg_encode_config_data.image_quality=isp_data->image_quality;
	jpeg_encode_config_data.jpeg_gray_mode=isp_data->jpeg_gray_mode;
	jpeg_encode_config_data.jpeg_file_start_address=isp_data->target_buffer_start_address;
	jpeg_encode_config_data.jpeg_file_buffer_size=isp_data->target_buffer_size;
#endif

#if (!defined(YUV_SENSOR_SUPPORT))
	/* accoring the zoom factor to calculate the grab window area */
	exposure_window.image_target_width=isp_data->target_width;
	exposure_window.image_target_height=isp_data->target_height;
	exposure_window.digital_zoom_factor=isp_digital_zoom_factor;

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	ENABLE_CAMERA_IDLE_INT;
	SET_CAMERA_CAPTURE_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;

   kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);

	if((camera_oper_data.enable_cap_shutter_compensate==KAL_TRUE)&&
#if (!defined(DRV_ISP_6219_SERIES))
		(device_support_info.ae.sensor_basegain==BASEGAIN)&&
#endif
		(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE))
	{
#if (!defined(DRV_ISP_6219_SERIES))		
		if(CAM_ISO_MODE != dsc_status.dscmode)
		{
#endif		
		if((pregain>=camera_oper_data.shutter_compensate_max)&&
		   (eShutter<MAX_EXPOSURE_LINES))
		{
			sensor_config_data.enable_shutter_tansfer=KAL_TRUE;

			isp_capture_shutter=eShutter*pregain/camera_oper_data.shutter_compensate_max;
			if(isp_capture_shutter>MAX_EXPOSURE_LINES)
			   isp_capture_shutter=MAX_EXPOSURE_LINES;
			if(isp_capture_shutter>BaseShutter)
				isp_capture_shutter=(isp_capture_shutter/BaseShutter)*BaseShutter;
			isp_capture_pregain=eShutter*pregain/isp_capture_shutter;
			if(isp_capture_pregain>camera_oper_data.pregain_max)
				isp_capture_pregain=camera_oper_data.pregain_max;

			ae_set_pregain(isp_capture_pregain);
			sensor_config_data.capture_shutter=isp_capture_shutter;
		}
		else
			sensor_config_data.enable_shutter_tansfer=KAL_FALSE;
#if (!defined(DRV_ISP_6219_SERIES))		
		}
		else
		{
			sensor_config_data.enable_shutter_tansfer=KAL_FALSE;		
		}
#endif
	}
	else
		sensor_config_data.enable_shutter_tansfer=KAL_FALSE;
	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
	sensor_config_data.meta_mode = CAPTURE_MODE_NORMAL;	// for normal mode capture
	else
		sensor_config_data.meta_mode = CAPTURE_MODE_META;	// for meta mode capture

	image_sensor_func->sensor_capture_setting(&exposure_window,&sensor_config_data);
#if (!defined(DRV_ISP_6219_SERIES))
    flashlight_post_process();
#endif

	/* accoring the zoom factor to calculate the grab window area */
   isp_horizontal_subsample=exposure_window.isp_hsub_factor;
   isp_vertical_subsample=exposure_window.isp_vsub_factor;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFE);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((isp_data->target_width * exposure_window.exposure_window_height) >=
		 (isp_data->target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * isp_data->target_height/isp_data->target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * isp_data->target_width/isp_data->target_height)&0xFFFE;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
	}

	isp_grab_start_x-=(((isp_grab_width*(isp_horizontal_subsample-1))>>1)&0xFFFE);
	isp_grab_start_y-=((isp_grab_height*(isp_vertical_subsample-1))>>1);

	align_center_point();
	SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
	SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
	isp_capture_jpeg_data.source_width=isp_grab_width;
	isp_capture_jpeg_data.source_height=isp_grab_height;

/* set gamma 1024 */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	apply_take_image_with_gamma_1024_by_flag();
#endif

#if(defined(DRV_ISP_6219_SERIES))
	SET_SUB_SAMPLE_MODE(CAMERA_SUB_SAMPLE_1_1);
	jpeg_codec_power_up();
#else
	ENABLE_VERTICAL_SUB_SAMPLE;
	ENABLE_HORIZONTAL_SUB_SAMPLE;
	
	SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));	
	SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
	SET_HSUB_DST_SIZE(isp_grab_width);
	SET_VSUB_DST_SIZE(isp_grab_height);
	
#if (defined(DRV_ISP_6227_SERIES))
	jpeg_codec_power_up();
#endif
    // Disable Defect Table
    DISABLE_DEFECT_CORRECTION;
#endif
#if (defined(LED_FLASHLIGHT_SUPPORT)||defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
    if(flashlight_redeye_process(camera_oper_data.capture_delay_frame)==KAL_FALSE)
    {
	for(i=0;i<camera_oper_data.capture_delay_frame;i++)
	{
	   DISABLE_VIEW_FINDER_MODE;
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;

   	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
      	                    &event_group,KAL_SUSPEND);
   }
    }   
    // Enable flash trigger before image data path open.
    flashlight_trigger_process();
#else    
	for(i=0;i<camera_oper_data.capture_delay_frame;i++)
	{
	   DISABLE_VIEW_FINDER_MODE;
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;

   	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
      	                    &event_group,KAL_SUSPEND);
   }
#endif

   DISABLE_VIEW_FINDER_MODE;
   DISABLE_CAMERA_IDLE_INT;

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
    /* Restore Defect Table Setting */
    REG_ISP_DEFECT_PIXEL_CONFIG = defect_reg_backup;

	/* Update shading and defect offset */
	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
	{
		apply_camera_shading_to_reg(CAMERA_COMP_CAPTURE_NORMAL_SET);
		if(camera_oper_data.capture_defect_table_enable==KAL_TRUE)
		{
			load_defect_table_para(DEFECT_MODE_CAPTURE);
			ENABLE_DEFECT_CORRECTION;
		}
		else
			DISABLE_DEFECT_CORRECTION;
	}
#endif
#endif /* YUV_SENSOR_SUPPORT */

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	isp_capture_jpeg_data.jpeg_file_info	=	isp_data->jpeg_file_info;
	isp_capture_jpeg_data.snapshot_number	=	isp_data->snapshot_number;
	isp_capture_jpeg_data.flash_mode			=	isp_data->flash_mode;

	isp_capture_jpeg_data.lcd_id								=	isp_data->lcd_id;
	isp_capture_jpeg_data.lcm_start_x						=	isp_data->lcm_start_x;
	isp_capture_jpeg_data.lcm_start_y						=	isp_data->lcm_start_y;
	isp_capture_jpeg_data.lcm_end_x							=	isp_data->lcm_end_x;
	isp_capture_jpeg_data.lcm_end_y							=	isp_data->lcm_end_y;
	isp_capture_jpeg_data.roi_offset_x						=	isp_data->roi_offset_x;
	isp_capture_jpeg_data.roi_offset_y						=	isp_data->roi_offset_y;
	isp_capture_jpeg_data.update_layer						=	isp_data->update_layer;
	isp_capture_jpeg_data.hw_update_layer					=	isp_data->hw_update_layer;

	isp_capture_jpeg_data.tv_output							=	isp_data->tv_output;
	isp_capture_jpeg_data.tv_output_width					=	isp_data->tv_output_width;
	isp_capture_jpeg_data.tv_output_height					=	isp_data->tv_output_height;
	isp_capture_jpeg_data.tv_output_offset_x				=	isp_data->tv_output_offset_x;
	isp_capture_jpeg_data.tv_output_offset_y				=	isp_data->tv_output_offset_y;
	isp_capture_jpeg_data.tv_output_buffer1_address		=	isp_data->tv_output_buffer1_address;
	isp_capture_jpeg_data.tv_output_buffer2_address		=	isp_data->tv_output_buffer2_address;
	isp_capture_jpeg_data.tv_output_buffer_size			=	isp_data->tv_output_buffer_size;

	/* Prepare IPP Data */
	ipp_capture_jpeg_data.jpeg_file_info					=	isp_capture_jpeg_data.jpeg_file_info;
	ipp_capture_jpeg_data.intmem_start_address			=	isp_data->intmem_start_address;
	ipp_capture_jpeg_data.intmem_size						=	isp_data->intmem_size;
	ipp_capture_jpeg_data.extmem_start_address			=	isp_data->extmem_start_address;
	ipp_capture_jpeg_data.extmem_size						=	isp_data->extmem_size;

	ipp_capture_jpeg_data.snapshot_number					=	isp_data->snapshot_number;
	ipp_capture_jpeg_data.image_src_width					=	isp_capture_jpeg_data.source_width;
	ipp_capture_jpeg_data.image_src_height					=	isp_capture_jpeg_data.source_height;
	ipp_capture_jpeg_data.image_capture_width				=	isp_data->target_width;
	ipp_capture_jpeg_data.image_capture_height			=	isp_data->target_height;

	ipp_capture_jpeg_data.thumbnail_mode					=	isp_data->thumbnail_mode;
	ipp_capture_jpeg_data.thumbnail_width					=	isp_data->thumbnail_width;
	ipp_capture_jpeg_data.thumbnail_height					=	isp_data->thumbnail_height;

	ipp_capture_jpeg_data.overlay_frame_mode				=	isp_data->overlay_frame_mode;
	ipp_capture_jpeg_data.overlay_color_depth				=	isp_data->overlay_color_depth;
	ipp_capture_jpeg_data.overlay_frame_source_key		=	isp_data->overlay_frame_source_key;
	ipp_capture_jpeg_data.overlay_frame_width				=	isp_data->overlay_frame_width;
	ipp_capture_jpeg_data.overlay_frame_height			=	isp_data->overlay_frame_height;
	ipp_capture_jpeg_data.overlay_frame_buffer_address	=	isp_data->overlay_frame_buffer_address;

	ipp_capture_jpeg_data.image_quality						=	isp_data->image_quality;
	ipp_capture_jpeg_data.jpeg_yuv_mode						=	isp_data->jpeg_yuv_mode;

	ipp_capture_jpeg_data.jpeg_file_start_address1		=	isp_data->target_buffer_start_address;
	ipp_capture_jpeg_data.jpeg_file_buffer_size1			=	isp_data->target_buffer_size;

	ipp_capture_jpeg_data.image_pitch_mode					=	isp_data->image_pitch_mode;
	ipp_capture_jpeg_data.image_data_format				=	isp_data->image_data_format;
	ipp_capture_jpeg_data.image_pitch_bytes				=	isp_data->image_pitch_bytes;

	ipp_capture_jpeg_data.display								=	isp_data->display;
	if ((get_lcd_hw_layer_rotate_value(isp_data->hw_update_layer)==LCD_LAYER_ROTATE_NORMAL) &&
		 ((current_lcd_rotate_value==LCD_LAYER_ROTATE_NORMAL) ||
		  (current_lcd_rotate_value==LCD_LAYER_ROTATE_180) ||
		  (current_lcd_rotate_value==LCD_LAYER_MIRROR) ||
		  (current_lcd_rotate_value==LCD_LAYER_MIRROR_ROTATE_180)))
	{
		ipp_capture_jpeg_data.display_width						=	isp_data->lcm_end_x-isp_data->lcm_start_x+1;
		ipp_capture_jpeg_data.display_height					=	isp_data->lcm_end_y-isp_data->lcm_start_y+1;
	}
	else
	{
		ipp_capture_jpeg_data.display_height				=	isp_data->lcm_end_x-isp_data->lcm_start_x+1;
		ipp_capture_jpeg_data.display_width					=	isp_data->lcm_end_y-isp_data->lcm_start_y+1;
	}
	ipp_capture_jpeg_data.frame_buffer_address			=	isp_data->frame_buffer_address;
	ipp_capture_jpeg_data.frame_buffer_size				=	isp_data->frame_buffer_size;

	ipp_capture_jpeg_data.cam_capture_jpeg_cb				=	isp_data->cam_capture_jpeg_cb;

#if (!defined(YUV_SENSOR_SUPPORT))
	open_image_data_path(scene_id);
	isp_capture_jpeg_data.display=KAL_FALSE;
	if (isp_data->display==KAL_TRUE)
	{
		lcd_data.module_id=LCD_UPDATE_MODULE_MEDIA;
		lcd_data.lcd_id=isp_data->lcd_id;
		lcd_data.block_mode_flag=KAL_TRUE;
		lcd_data.fb_update_mode=LCD_HW_TRIGGER_MODE;
		lcd_data.lcm_start_x=isp_data->lcm_start_x;
		lcd_data.lcm_start_y=isp_data->lcm_start_y;
		lcd_data.lcm_end_x=isp_data->lcm_end_x;
		lcd_data.lcm_end_y=isp_data->lcm_end_y;
		lcd_data.roi_offset_x=isp_data->roi_offset_x;
		lcd_data.roi_offset_y=isp_data->roi_offset_y;
		lcd_data.update_layer=isp_data->update_layer;
		lcd_data.hw_update_layer=isp_data->hw_update_layer;
		lcd_data.hw_trigger_src	= LCD_HW_TRIGGER_IBW2;

		isp_capture_jpeg_data.display=KAL_TRUE;
		isp_capture_jpeg_data.lcd_id=isp_data->lcd_id;

		lcd_data.roi_background_color=0xFFFFFF;
		lcd_data.memory_output=KAL_FALSE;
		lcd_data.block_mode_flag=KAL_TRUE;
		lcd_data.lcd_block_mode_cb=NULL;
      #if (defined(TV_OUT_SUPPORT))
		if (isp_data->tv_output==KAL_TRUE)
		{
			lcd_data.tv_output=KAL_TRUE;
			lcd_data.tv_output_width=isp_data->tv_output_width;
			lcd_data.tv_output_height=isp_data->tv_output_height;
			lcd_data.tv_output_offset_x=isp_data->tv_output_offset_x;
			lcd_data.tv_output_offset_y=isp_data->tv_output_offset_y;
			lcd_data.tv_output_frame_buffer1_address=isp_data->tv_output_buffer1_address;
			lcd_data.tv_output_frame_buffer2_address=isp_data->tv_output_buffer2_address;
			lcd_data.tv_output_frame_buffer_size=isp_data->tv_output_buffer_size;
		}
		else
		{
			lcd_data.tv_output=KAL_FALSE;
		}
                #else
                    lcd_data.tv_output=KAL_FALSE;
		#endif   
		lcd_fb_update(&lcd_data);
	}

	isp_operation_state=ISP_CAPTURE_JPEG_STATE;
	/* skip setting for cct mode */
	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
	{
	camera_image_setting(CAM_PARAM_EFFECT,isp_preview_config_data.image_effect);
	if(isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)
	{
		camera_image_setting(CAM_PARAM_CONTRAST,isp_preview_config_data.contrast_level);
		camera_image_setting(CAM_PARAM_BRIGHTNESS,isp_preview_config_data.brightness_level);
		camera_image_setting(CAM_PARAM_HUE,isp_preview_config_data.hue_value);
		camera_image_setting(CAM_PARAM_SATURATION,isp_preview_config_data.saturation_value);
	}
	camera_image_setting(CAM_PARAM_WB,isp_preview_config_data.wb_mode);
	camera_image_setting(CAM_PARAM_EXPOSURE,isp_preview_config_data.ev_value);
	camera_image_setting(CAM_PARAM_BANDING,isp_preview_config_data.banding_freq);
	camera_image_setting(CAM_PARAM_NIGHT_MODE,(kal_uint16)isp_preview_config_data.night_mode);
	awb_set_gain();
	if((isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL) && (isp_preview_config_data.night_mode))
		set_camera_mode_para(CAMERA_PARA_NIGHT_MODE);
	if(isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)
	{
		set_camera_mode_para(CAMERA_PARA_CAPTURE_MODE);
#if (!defined(DRV_ISP_6219_SERIES))
		set_anti_low_light_para(AE_INDEX_ENV);
#endif
	}
	}
	if (isp_data->snapshot_number==1)
	{
		SET_CAMERA_CAPTURE_MODE;
	}
	else if (isp_data->snapshot_number>1)
	{
		SET_CAMERA_PREVIEW_MODE;
	}
	//SET_CAMERA_FRAME_RATE(0);

#if (!defined(DRV_ISP_6219_SERIES))
#if (defined(EXIF_SUPPORT))
   /* config exif header */
   exif_cam_para_ptr=exif_get_cam_para_struct();
   exif_MTK_para_ptr=exif_get_MTK_para_struct();
   exif_update_cam_para_struct(exif_cam_para_ptr);
#endif

	config_camera_capture_jpeg_data_path(scene_id,&ipp_capture_jpeg_data);
#endif

	ENABLE_VIEW_FINDER_MODE;

	camera_process_stage|=LEAVE_CAMERA_CAPTURE_JPEG;
	return jpeg_file_size;
#endif /* YUV_SENSOR_SUPPORT */

#elif (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))

#if (!defined(YUV_SENSOR_SUPPORT))
#if (defined(EXIF_SUPPORT))
   /* config exif header */
   exif_cam_para_ptr=exif_get_cam_para_struct();
   exif_MTK_para_ptr=exif_get_MTK_para_struct();
   exif_update_cam_para_struct(exif_cam_para_ptr);
	/* calculating exif header size and shift the start addres of jpeg encoder*/
	exif_header_length=exif_get_custom_IFD_and_buffer_size(2);

	if(exif_header_length>0)
	{
		jpeg_encode_config_data.jpeg_file_start_address+=exif_header_length;

		if(jpeg_encode_config_data.jpeg_file_start_address % 4 !=0)
		{
			jpeg_encode_config_data.jpeg_file_start_address=((jpeg_encode_config_data.jpeg_file_start_address+4)>>2)<<2;
		}

		exif_padding_length=jpeg_encode_config_data.jpeg_file_start_address-(isp_data->target_buffer_start_address+exif_header_length);
		jpeg_encode_config_data.jpeg_file_buffer_size-=(jpeg_encode_config_data.jpeg_file_start_address-isp_data->target_buffer_start_address);
	}
#endif

   do
   {
	   if(capture_retry_flag==1)
	   {
	   	SET_CAMERA_FRAME_RATE(0);
	   	ENABLE_CMOS_SESNOR;
	   	jpeg_encode_config_data.image_quality=JPEG_ENCODER_POOR_QUALITY;
	  		intmem_init((kal_uint32 *) isp_capture_jpeg_data.intmem_start_address,
						isp_capture_jpeg_data.intmem_size);
			extmem_init((kal_uint32 *) isp_capture_jpeg_data.extmem_start_address,
						isp_capture_jpeg_data.extmem_size);
	   	capture_retry_flag++;
	   }

		mp4_reset();
		config_image_dma(scene_id,isp_data->target_width,isp_data->target_height);
		config_jpeg_encoder(&jpeg_encode_config_data);
		config_image_processor(scene_id);
		config_pixel_resizer(scene_id);

		isp_operation_state=ISP_CAPTURE_JPEG_STATE;
	   /* skip setting for cct mode */
		if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
		{
		camera_image_setting(CAM_PARAM_EFFECT,isp_preview_config_data.image_effect);
		if(isp_preview_config_data.image_effect==0)
		{
			camera_image_setting(CAM_PARAM_CONTRAST,isp_preview_config_data.contrast_level);
			camera_image_setting(CAM_PARAM_BRIGHTNESS,isp_preview_config_data.brightness_level);
			camera_image_setting(CAM_PARAM_HUE,isp_preview_config_data.hue_value);
			camera_image_setting(CAM_PARAM_SATURATION,isp_preview_config_data.saturation_value);
		}
		camera_image_setting(CAM_PARAM_WB,isp_preview_config_data.wb_mode);
		camera_image_setting(CAM_PARAM_EXPOSURE,isp_preview_config_data.ev_value);
		camera_image_setting(CAM_PARAM_BANDING,isp_preview_config_data.banding_freq);
		camera_image_setting(CAM_PARAM_NIGHT_MODE,(kal_uint16)isp_preview_config_data.night_mode);
		if((isp_preview_config_data.image_effect==0) && (isp_preview_config_data.night_mode))
			set_camera_mode_para(CAMERA_PARA_NIGHT_MODE);
		awb_set_gain();
		}
		jpeg_encoder_encode_result=0;
		SET_CAMERA_CAPTURE_MODE;
		//SET_CAMERA_FRAME_RATE(0);
	   /* skip setting for cct mode */
		if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
		{
		if(isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)
		{
			set_camera_mode_para(CAMERA_PARA_CAPTURE_MODE);
#if (!defined(DRV_ISP_6219_SERIES))
			set_anti_low_light_para(AE_INDEX_ENV);
#endif
		}
		}
	   /* skip setting for cct mode */
		if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
		{
#if (defined(DRV_ISP_6219_SERIES))
		if((camera_oper_data.flare_camera_enable==KAL_TRUE)&&(isp_preview_config_data.image_effect==0))
		{
			SET_AWB_R_GAIN(flare_gain);
			SET_AWB_G_GAIN(flare_gain);
			SET_AWB_B_GAIN(flare_gain);
			SET_GAMMA_RGB_FLARE_R(flare_offset);
			SET_GAMMA_RGB_FLARE_G(flare_offset);
			SET_GAMMA_RGB_FLARE_B(flare_offset);
			SET_GAMMA_RGB_FLARE_SIGN_R_HIGH;
			SET_GAMMA_RGB_FLARE_SIGN_G_HIGH;
			SET_GAMMA_RGB_FLARE_SIGN_B_HIGH;
		}
#endif
		}
		ENABLE_VIEW_FINDER_MODE;


	/* wait until JPEG encode completely */
		for (i=0;i<20;i++)
		{
			kal_sleep_task(20);

			if (jpeg_encoder_encode_result & JPEG_ENCODE_STALL)
			{
				while ((*(volatile unsigned int *) 0x80690000) & 0x10000)
				{
					DISABLE_VIEW_FINDER_MODE;
#if (defined(DRV_ISP_6219_SERIES))
					*((volatile unsigned int *) 0x80610004) = 0x600000;
					*((volatile unsigned int *) 0x80610004) = 0x60;
#elif (defined(DRV_ISP_6227_SERIES))
					*((volatile unsigned int *) 0x80610004) = 0x60000;
					*((volatile unsigned int *) 0x80610004) = 0x6;
#endif
					RESET_JPEG_ENCODER;
					ENABLE_JPEG_ENCODER;
					ENABLE_VIEW_FINDER_MODE;
					kal_sleep_task(73);

				}
				jpeg_file_size=0;
			}
			else if (jpeg_encoder_encode_result & JPEG_ENCODE_DONE)
			{
				jpeg_file_size=DRV_Reg32(JPEG_ENCODER_DMA_ADDR_REG)-DRV_Reg32(JPEG_ENCODER_DEST_ADDR_REG);
				kal_sleep_task(15);
				i=100;
			}
		}
		if (i==20)
			jpeg_file_size=0;

		DISABLE_CMOS_SESNOR;
		DISABLE_VIEW_FINDER_MODE;
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
		DISABLE_1024_GAMMA_TABLE;
#endif

		RESZ_Stop(scene_id);
		RESZ_Close(scene_id);

		clean_imgprc_coefficient(scene_id);
		IMGPROC_Stop(scene_id);
		IMGPROC_Close(scene_id);

		stop_image_dma(scene_id);
		IMGDMA_Close(scene_id);

		intmem_deinit();
		extmem_deinit();

		if((capture_retry_flag==0)&&(jpeg_file_size==0)&&(jpeg_encode_config_data.image_quality!=JPEG_ENCODER_POOR_QUALITY))
			capture_retry_flag++;
	}while(capture_retry_flag==1);

	#if (defined(EXIF_SUPPORT))
	/* Filling Exif header */
	if(exif_header_length>0)
	{
	*((kal_uint8 *)isp_data->target_buffer_start_address)=0xFF;
	*((kal_uint8 *)isp_data->target_buffer_start_address+1)=0xD8;
	
	exif_set_extra_included_bytes(exif_padding_length);	
	exif_Fillin_Header((kal_uint8 *)isp_data->target_buffer_start_address,2);

	/* padding bytes to cover SOI marker generated by JPEG encoder */
	for(i=0;i<exif_padding_length;i++)
	 *((kal_uint8 *)(jpeg_encode_config_data.jpeg_file_start_address+1-i))=0x00;

	 jpeg_file_size+=(jpeg_encode_config_data.jpeg_file_start_address-
	 		  isp_data->target_buffer_start_address);
	}
	#endif

	jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;
	isp_operation_state=ISP_STANDBY_STATE;

	jpeg_codec_power_down();

	/* Restore pregain of preview mode */
	if(sensor_config_data.enable_shutter_tansfer==KAL_TRUE)
	{
#if (defined(DRV_ISP_6219_SERIES))
		ae_set_pregain(pregain);
#else
		ae_set_lut_gain();
#endif
	}

#if (defined(DRV_ISP_6227_SERIES))
   flashlight_stop_process();
#endif

	camera_process_stage|=LEAVE_CAMERA_CAPTURE_JPEG;
	return jpeg_file_size;
#endif /* YUV_SENSOR_SUPPORT */
#endif

#if (defined(YUV_SENSOR_SUPPORT))
	jpeg_file_size=camera_yuv_capture_jpeg_process();
	camera_process_stage|=LEAVE_CAMERA_CAPTURE_JPEG;
	return jpeg_file_size;
#endif /* YUV_SENSOR_SUPPORT */
#endif /* defined(ISP_SUPPORT) */
}

kal_uint8 stop_camera_capture_process(void)
{
#if (defined(ISP_SUPPORT))
#if (defined(DRV_ISP_6219_SERIES))
	camera_process_stage|=LEAVE_STOP_CAMERA_CAPTURE;
	return 0;
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	camera_process_stage|=LEAVE_STOP_CAMERA_CAPTURE;
	return 0;
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	kal_uint32 save_irq_mask;
	kal_uint8 captured_frame;

  	save_irq_mask=SaveAndSetIRQMask();
  	if (current_captured_file_number==isp_capture_jpeg_data.snapshot_number)
  		wait_last_capture_frame=KAL_FALSE;
  	else
		wait_last_capture_frame=KAL_TRUE;
	captured_frame=current_captured_file_number;
	RestoreIRQMask(save_irq_mask);

	while (wait_last_capture_frame==KAL_TRUE) {};

	if (isp_capture_jpeg_data.snapshot_number>1)
	{
		DISABLE_VIEW_FINDER_MODE;
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
		DISABLE_1024_GAMMA_TABLE;
#endif
		lcd_stop_hw_update(isp_capture_jpeg_data.lcd_id);
	}

	close_image_data_path(SCENARIO_CAMERA_CAPTURE_JPEG_ID);
	if (isp_capture_jpeg_data.display==KAL_TRUE)
		lcd_stop_hw_update(isp_capture_jpeg_data.lcd_id);
	jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;
	isp_operation_state=ISP_STANDBY_STATE;

#if (!defined(DRV_ISP_6219_SERIES))
   flashlight_stop_process();
#endif
	if(sensor_config_data.enable_shutter_tansfer==KAL_TRUE)
	{
		ae_set_lut_gain();
	}

	camera_process_stage|=LEAVE_STOP_CAMERA_CAPTURE;
	if (captured_frame==current_captured_file_number)
		return JPEG_ENCODE_BUFFER_FULL;
	else
		return current_captured_file_number;
#endif
#else
	camera_process_stage|=LEAVE_STOP_CAMERA_CAPTURE;
	return 0;
#endif /* ISP_SUPPORT */
}	/* stop_camera_capture_process() */

/*************************************************************************
* FUNCTION
*	camera_capture_barcode_process
*
* DESCRIPTION
*	This function capture one picture for barcode reader
*
* PARAMETERS
*	isp_data : the parameters for camera capture for barcode image process
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 camera_capture_barcode_process(camera_capture_barcode_struct *isp_data)
{
#if (defined(ISP_SUPPORT)&&(!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES))))
	kal_uint32 event_group;
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_BARCODE_ID;
	lcd_frame_update_struct lcd_data;
	kal_uint16 temp_grab_size;
	volatile kal_uint16 i,j;

	if (sensor_err_check<0)
		return KAL_FALSE;

	if (isp_operation_state!=ISP_STANDBY_STATE)
		ASSERT(0);

	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
	
	lut_info.videomode=KAL_FALSE;

#if (defined(AF_SUPPORT))
	if (af_operation_state != AF_STANDBY_STATE)//prevent scenario error
	{
		camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	}
	else
	{
		lens_func->lens_af_move_to((kal_int32)camera_lens.INFO.af_hyper_pos);
		dsc_status.af.index=0xFF;
	}
#endif
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_on_off(KAL_TRUE);
	awb_on_off(KAL_TRUE);
	awb_set_gain();
#endif
	DISABLE_CAMERA_IDLE_INT;
	ENABLE_AE_COUNT;
	ENABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;

#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
   // Disable AE Count before Start Preview
	DISABLE_AE_COUNT;
	REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	DISABLE_CMOS_SESNOR;
#endif
	sensor_config_data.isp_op_mode=ISP_PREVIEW_MODE;
	sensor_config_data.image_mirror=isp_data->image_mirror;
	sensor_config_data.frame_rate=isp_data->frame_rate;
	exposure_window.image_target_width=isp_data->source_width;
	exposure_window.image_target_height=isp_data->source_height;
	exposure_window.current_exposure_pixel=exposure_window.exposure_pixel=1;
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);

	/* accorind the zoom factor to calculate the grab window area */
	isp_digital_zoom_factor=10;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;

	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFE);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((isp_data->target_width * exposure_window.exposure_window_height) >=
		 (isp_data->target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * isp_data->target_height/isp_data->target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * isp_data->target_width/isp_data->target_height)&0xFFFE;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
	}
	
	isp_grab_start_x-=(((isp_grab_width*(isp_horizontal_subsample-1))>>1)&0xFFFE);
	isp_grab_start_y-=((isp_grab_height*(isp_vertical_subsample-1))>>1);

	align_center_point();
	SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
	SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_config((isp_grab_width*isp_horizontal_subsample),(isp_grab_height*isp_vertical_subsample));
#endif
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
	DISABLE_1024_GAMMA_TABLE;
#endif

	apply_camera_shading_to_reg(CAMERA_COMP_PREVIEW_NORMAL_SET);
	if(camera_oper_data.preview_defect_table_enable==KAL_TRUE)
	{
		load_defect_table_para(DEFECT_MODE_PREVIEW);
		ENABLE_DEFECT_CORRECTION;
	}
	else
		DISABLE_DEFECT_CORRECTION;

	ENABLE_VERTICAL_SUB_SAMPLE;
	ENABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));	
	SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
	if((isp_grab_width>(isp_data->target_width<<2)) || (isp_grab_height>(isp_data->target_height<<2)))
	{ /* grab size > taget size *4 => ISP subsample 4x */
		SET_HSUB_DST_SIZE(isp_grab_width>>2);
		SET_VSUB_DST_SIZE(isp_grab_height>>2);
		isp_preview_config_data.source_width=isp_grab_width>>2;
		isp_preview_config_data.source_height=isp_grab_height>>2;
	}
	else if((isp_grab_width>(isp_data->target_width<<1)) || (isp_grab_height>(isp_data->target_height<<1)))
	{ /* grab size > taget size *2 => ISP subsample 2x */
		SET_HSUB_DST_SIZE(isp_grab_width>>1);
		SET_VSUB_DST_SIZE(isp_grab_height>>1);
		isp_preview_config_data.source_width=isp_grab_width>>1;
		isp_preview_config_data.source_height=isp_grab_height>>1;
	}
	else
	{
		if((isp_grab_width>=((isp_data->target_width)+2)) && (isp_grab_height>=((isp_data->target_height)+2)))
		{
			SET_HSUB_DST_SIZE(isp_data->target_width+2);
			SET_VSUB_DST_SIZE(isp_data->target_height+2);
			isp_preview_config_data.source_width=isp_data->target_width+2;
			isp_preview_config_data.source_height=isp_data->target_height+2;
		}
		else
		{
			if((isp_grab_width==(isp_data->target_width)) && (isp_grab_height==(isp_data->target_height)))
			{
				SET_HSUB_DST_SIZE(isp_grab_width-2);
				SET_VSUB_DST_SIZE(isp_grab_height-2);
				isp_preview_config_data.source_width=isp_grab_width-2;
				isp_preview_config_data.source_height=isp_grab_height-2;
			}
			else
			{
				SET_HSUB_DST_SIZE(isp_grab_width);
				SET_VSUB_DST_SIZE(isp_grab_height);
				isp_preview_config_data.source_width=isp_grab_width;
				isp_preview_config_data.source_height=isp_grab_height;
			}
		}
	}

	isp_capture_barcode_data.lcd_id							= isp_data->lcd_id;
	isp_capture_barcode_data.lcm_start_x					= isp_data->lcm_start_x;
	isp_capture_barcode_data.lcm_start_y					= isp_data->lcm_start_y;
	isp_capture_barcode_data.lcm_end_x						= isp_data->lcm_end_x;

	isp_capture_barcode_data.lcm_end_y						= isp_data->lcm_end_y;
	isp_capture_barcode_data.roi_offset_x					= isp_data->roi_offset_x;
	isp_capture_barcode_data.roi_offset_y					= isp_data->roi_offset_y;
	isp_capture_barcode_data.update_layer					= isp_data->update_layer;
	isp_capture_barcode_data.hw_update_layer				= isp_data->hw_update_layer;

	isp_capture_barcode_data.banding_freq					= isp_data->banding_freq;
	isp_capture_barcode_data.ev_value						= isp_data->ev_value;

	//for AF Zone Setting
	isp_preview_config_data.camera_offset_x            = isp_data->camera_offset_x;
	isp_preview_config_data.camera_offset_y            = isp_data->camera_offset_y;
	isp_preview_config_data.af_zone0_x						= isp_data->af_zone0_x;
	isp_preview_config_data.af_zone0_y						= isp_data->af_zone0_y;
	isp_preview_config_data.af_zone1_x						= isp_data->af_zone1_x;
	isp_preview_config_data.af_zone1_y						= isp_data->af_zone1_y;
	isp_preview_config_data.af_zone2_x						= isp_data->af_zone2_x;
	isp_preview_config_data.af_zone2_y						= isp_data->af_zone2_y;
	isp_preview_config_data.af_zone3_x						= isp_data->af_zone3_x;
	isp_preview_config_data.af_zone3_y						= isp_data->af_zone3_y;
	isp_preview_config_data.af_zone4_x						= isp_data->af_zone4_x;
	isp_preview_config_data.af_zone4_y						= isp_data->af_zone4_y;
	isp_preview_config_data.target_width					= isp_data->source_width;
	isp_preview_config_data.target_height					= isp_data->source_height;

	isp_capture_barcode_data.intmem_start_address		= isp_data->intmem_start_address;
	isp_capture_barcode_data.intmem_size					= isp_data->intmem_size;
	isp_capture_barcode_data.extmem_start_address		= isp_data->extmem_start_address;
	isp_capture_barcode_data.extmem_size					= isp_data->extmem_size;

	isp_capture_barcode_data.source_width					= isp_preview_config_data.source_width;
	isp_capture_barcode_data.source_height					= isp_preview_config_data.source_height;
	isp_capture_barcode_data.target_width					= isp_data->target_width;
	isp_capture_barcode_data.target_height					= isp_data->target_height;

	isp_capture_barcode_data.frame_buffer_address		= isp_data->frame_buffer_address;
	isp_capture_barcode_data.frame_buffer_size			= isp_data->frame_buffer_size;
	isp_capture_barcode_data.frame_buffer_address1		= isp_data->frame_buffer_address1;
	isp_capture_barcode_data.frame_buffer_size1			= isp_data->frame_buffer_size1;

	isp_capture_barcode_data.barcode_buffer_address		= isp_data->barcode_buffer_address;
	isp_capture_barcode_data.barcode_buffer_size			= isp_data->barcode_buffer_size;

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	isp_capture_barcode_data.barcode_image_data_format	= isp_data->barcode_image_data_format;

	isp_capture_barcode_data.image_pitch_mode				= isp_data->image_pitch_mode;
	isp_capture_barcode_data.image_data_format			= isp_data->image_data_format;
	isp_capture_barcode_data.image_pitch_bytes			= isp_data->image_pitch_bytes;
#endif

	cam_preview_cb													= isp_data->cam_preview_cb;
	cam_focus_cb													= isp_data->cam_focus_cb;
	isp_capture_barcode_data.cam_capture_barcode_cb		= isp_data->cam_capture_barcode_cb;

#if (defined(DRV_ISP_6227_SERIES))
	intmem_init((kal_uint32 *) isp_capture_barcode_data.intmem_start_address,
					isp_capture_barcode_data.intmem_size);
	extmem_init((kal_uint32 *) isp_capture_barcode_data.extmem_start_address,
					isp_capture_barcode_data.extmem_size);
#endif

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	if ((get_lcd_hw_layer_rotate_value(isp_data->hw_update_layer)==LCD_LAYER_ROTATE_NORMAL) &&
		 ((current_lcd_rotate_value==LCD_LAYER_ROTATE_NORMAL) ||
		  (current_lcd_rotate_value==LCD_LAYER_ROTATE_180) ||
		  (current_lcd_rotate_value==LCD_LAYER_MIRROR) ||
		  (current_lcd_rotate_value==LCD_LAYER_MIRROR_ROTATE_180)))
	{
		ipp_capture_barcode_data.display_width				=	isp_data->lcm_end_x-isp_data->lcm_start_x+1;
		ipp_capture_barcode_data.display_height			=	isp_data->lcm_end_y-isp_data->lcm_start_y+1;
	}
	else
	{
		ipp_capture_barcode_data.display_height			=	isp_data->lcm_end_x-isp_data->lcm_start_x+1;
		ipp_capture_barcode_data.display_width				=	isp_data->lcm_end_y-isp_data->lcm_start_y+1;
	}
#endif

	lcd_data.module_id			= LCD_UPDATE_MODULE_MEDIA;
	lcd_data.lcd_id				= isp_capture_barcode_data.lcd_id;
	lcd_data.fb_update_mode		= LCD_HW_TRIGGER_MODE;
	lcd_data.lcm_start_x			= isp_capture_barcode_data.lcm_start_x;
	lcd_data.lcm_start_y			= isp_capture_barcode_data.lcm_start_y;
	lcd_data.lcm_end_x			= isp_capture_barcode_data.lcm_end_x;
	lcd_data.lcm_end_y			= isp_capture_barcode_data.lcm_end_y;
	lcd_data.roi_offset_x		= isp_capture_barcode_data.roi_offset_x;
	lcd_data.roi_offset_y		= isp_capture_barcode_data.roi_offset_y;
	lcd_data.update_layer		= isp_capture_barcode_data.update_layer;
	lcd_data.hw_update_layer	= isp_capture_barcode_data.hw_update_layer;
	lcd_data.block_mode_flag	= KAL_TRUE;
	lcd_data.lcd_block_mode_cb	= NULL;

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	isp_capture_barcode_data.tv_output							=	isp_data->tv_output;
	isp_capture_barcode_data.tv_output_width					=	isp_data->tv_output_width;
	isp_capture_barcode_data.tv_output_height					=	isp_data->tv_output_height;
	isp_capture_barcode_data.tv_output_offset_x				=	isp_data->tv_output_offset_x;
	isp_capture_barcode_data.tv_output_offset_y				=	isp_data->tv_output_offset_y;
	isp_capture_barcode_data.tv_output_buffer1_address		=	isp_data->tv_output_buffer1_address;
	isp_capture_barcode_data.tv_output_buffer2_address		=	isp_data->tv_output_buffer2_address;
	isp_capture_barcode_data.tv_output_buffer_size			=	isp_data->tv_output_buffer_size;

	/* Prepare IPP Data */
	ipp_capture_barcode_data.intmem_start_address 		= isp_capture_barcode_data.intmem_start_address;
	ipp_capture_barcode_data.intmem_size          		= isp_capture_barcode_data.intmem_size;
	ipp_capture_barcode_data.extmem_start_address 		= isp_capture_barcode_data.extmem_start_address;
	ipp_capture_barcode_data.extmem_size          		= isp_capture_barcode_data.extmem_size;

	ipp_capture_barcode_data.image_src_width		 		= isp_capture_barcode_data.source_width;
	ipp_capture_barcode_data.image_src_height	 			= isp_capture_barcode_data.source_height;
	ipp_capture_barcode_data.barcode_image_width			= isp_capture_barcode_data.target_width;
	ipp_capture_barcode_data.barcode_image_height		= isp_capture_barcode_data.target_height;

	ipp_capture_barcode_data.frame_buffer_address		= isp_capture_barcode_data.frame_buffer_address;
	ipp_capture_barcode_data.frame_buffer_size			= isp_capture_barcode_data.frame_buffer_size;
	ipp_capture_barcode_data.frame_buffer_address1		= isp_capture_barcode_data.frame_buffer_address1;
	ipp_capture_barcode_data.frame_buffer_size1			= isp_capture_barcode_data.frame_buffer_size1;

	ipp_capture_barcode_data.barcode_buffer_address		= isp_capture_barcode_data.barcode_buffer_address;
	ipp_capture_barcode_data.barcode_buffer_size			= isp_capture_barcode_data.barcode_buffer_size;

	ipp_capture_barcode_data.barcode_image_data_format	= isp_capture_barcode_data.barcode_image_data_format;

	ipp_capture_barcode_data.image_pitch_mode  			= isp_capture_barcode_data.image_pitch_mode;
	ipp_capture_barcode_data.image_data_format 			= isp_capture_barcode_data.image_data_format;
	ipp_capture_barcode_data.image_pitch_bytes 			= isp_capture_barcode_data.image_pitch_bytes;

	/* Prepare LCD Data */
	lcd_data.hw_trigger_src = LCD_HW_TRIGGER_IBW2;
	lcd_data.memory_output	= KAL_FALSE;
	lcd_data.tv_output=KAL_FALSE;

#if (defined(TV_OUT_SUPPORT))
   if ((isp_data->tv_output==KAL_TRUE)&&
		 ((tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE1)||
		  (tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE4)))
	{
		lcd_data.tv_output=KAL_TRUE;
		lcd_data.tv_output_width=isp_data->tv_output_width;
		lcd_data.tv_output_height=isp_data->tv_output_height;
		lcd_data.tv_output_offset_x=isp_data->tv_output_offset_x;
		lcd_data.tv_output_offset_y=isp_data->tv_output_offset_y;
		lcd_data.tv_output_frame_buffer1_address=isp_data->tv_output_buffer1_address;
		lcd_data.tv_output_frame_buffer2_address=isp_data->tv_output_buffer2_address;
		lcd_data.tv_output_frame_buffer_size=isp_data->tv_output_buffer_size;

	}
	else
	{
		lcd_data.tv_output=KAL_FALSE;
	}
#endif	/* TV_OUT_SUPPORT */
#endif
#if (defined(DRV_ISP_6227_SERIES))
	config_image_dma(scene_id,isp_data->target_width,isp_data->target_height);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	open_image_data_path(scene_id);
	config_camera_capture_barcode_data_path(scene_id,&ipp_capture_barcode_data);
#endif

	isp_operation_state=ISP_CAPTURE_BARCODE_STATE;

	set_camera_mode_para(CAMERA_PARA_PREVIEW_MODE);
	camera_image_setting(CAM_PARAM_BANDING,isp_capture_barcode_data.banding_freq);
	camera_image_setting(CAM_PARAM_EXPOSURE,isp_capture_barcode_data.ev_value);
#if (defined(AF_SUPPORT))
	camera_operation_setting(CAM_AF_MODE,CAM_AF_MACRO_MODE);
	camera_operation_setting(CAM_AF_METERING,CAM_AF_SINGLE_ZONE);
#endif
#if (!(defined(DRV_ISP_6219_SERIES)||defined(YUV_SENSOR_SUPPORT)))
    /* init AE/AWB setting */
	AE_INDEX = ae_apply_index_update(dsc_status.dscmode, dsc_status.ae.iso, AE_INDEX_ENV);
    AE_INDEX_C = AE_INDEX;
    eShutter=AE_LUT[AE_INDEX].shutter;		        /* Get Shutter */
    	sensor_pregain=ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);     /* Get Gain */	
    isp_pregain=AE_LUT[AE_INDEX].ispgain;
    pregain=sensor_pregain*isp_pregain/BASEGAIN;
    image_sensor_func->set_sensor_eshutter(eShutter);
    image_sensor_func->set_sensor_gain(sensor_pregain);
    ae_set_isp_pregain();
#endif

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	wait_first_frame_flag=KAL_TRUE;
	isp_preview_frame=0;
	SET_CAMERA_PREVIEW_MODE;
	SET_CAMERA_FRAME_RATE(0);

#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
   // Enable AE Count before Start Preview
	REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
	ENABLE_AE_COUNT;
#endif
#if  (defined(DRV_ISP_6228_SERIES))
	RESET_ISP;
	CLEAR_RESET_ISP;
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ENABLE_CMOS_SESNOR;
#endif
	ENABLE_VIEW_FINDER_MODE;

	ae_awb_cal_complete=1;
	isp_preview_2a_enable=0;
	ae_count=0;
	hist_idx=0;

	/* wait sensor first frame coming */
  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);

	/* Wait AE AWB Stable */
	if(isp_first_preview_frame==KAL_TRUE)
	{
		for(i=0;i<camera_oper_data.preview_display_wait_frame;i++)
		{
			j=0;
			while(j<9*camera_oper_data.ae_awb_cal_period)
			{
				if(isp_preview_2a_enable==1)
				{
					ae_awb_main();
					isp_preview_2a_enable=0;
					break;
				}
				else
				{
					kal_sleep_task(2);
					j++;
			}
		}
		}
		isp_first_preview_frame=KAL_FALSE;
	}

	lcd_fb_update(&lcd_data);	/* wait first frame ready */

  	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);

	isp_frame_count=0;
	camera_process_stage|=LEAVE_CAMERA_CAPTURE_BARCODE;
	return KAL_TRUE;
#endif
}	/* camera_capture_barcode_process() */

kal_uint8 stop_camera_capture_barcode_process(void)
{
#if (defined(ISP_SUPPORT)&&(!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES))))
   kal_uint32 i=0;
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_BARCODE_ID;

	if (isp_operation_state!=ISP_CAPTURE_BARCODE_STATE)
		ASSERT(0);

	isp_idle_done_flag=KAL_FALSE;
	ENABLE_CAMERA_IDLE_INT;
	DISABLE_VIEW_FINDER_MODE;

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
		DISABLE_1024_GAMMA_TABLE;
#endif

	while(isp_idle_done_flag==KAL_FALSE)
	{
		i++;
		kal_sleep_task(5);
		if(i>9) break;
	}

	DISABLE_CMOS_SESNOR;
	lcd_stop_hw_update(isp_capture_barcode_data.lcd_id);

#if (defined(DRV_ISP_6227_SERIES))
	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);

	clean_imgprc_coefficient(scene_id);
	IMGPROC_Stop(scene_id);
	IMGPROC_Close(scene_id);

	stop_image_dma(scene_id);
	IMGDMA_Close(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	close_image_data_path(scene_id);
#endif

#if (defined(AF_SUPPORT))
	if ((af_operation_state == AF_COLLECT_STATE) || (af_operation_state == AF_SEARCH_STATE))
	{
	   	camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	}
#endif

	isp_operation_state=ISP_STANDBY_STATE;

#if (defined(DRV_ISP_6227_SERIES))
	intmem_deinit();
	extmem_deinit();
#endif
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_on_off(KAL_FALSE);
	awb_on_off(KAL_FALSE);
#endif
	camera_process_stage|=LEAVE_STOP_CAMERA_CAPTURE_BARCODE;
	return KAL_TRUE;
#endif
}	/* stop_camera_capture_barcode_process() */

void pause_camera_capture_barcode_process(void)
{
#if (defined(ISP_SUPPORT)&&(defined(DRV_ISP_6227_SERIES)))
	kal_uint32 i=0;
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_BARCODE_ID;

	isp_idle_done_flag=KAL_FALSE;
	ENABLE_CAMERA_IDLE_INT;
	DISABLE_VIEW_FINDER_MODE;

	while(isp_idle_done_flag==KAL_FALSE)
	{
		i++;
		kal_sleep_task(5);
		if(i>9) break;
	}
	DISABLE_CMOS_SESNOR;
	lcd_stop_hw_update(isp_capture_barcode_data.lcd_id);

	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);
	clean_imgprc_coefficient(scene_id);
	IMGPROC_Stop(scene_id);
	IMGPROC_Close(scene_id);
	stop_image_dma(scene_id);
	IMGDMA_Close(scene_id);

	intmem_deinit();
	extmem_deinit();

	camera_process_stage|=LEAVE_PAUSE_CAMERA_CAPTURE_BARCODE;
#endif
}	/* pause_camera_capture_barcode_process() */

void resume_camera_capture_barcode_process(void)
{
#if (defined(ISP_SUPPORT)&&(defined(DRV_ISP_6227_SERIES)))
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_BARCODE_ID;
	kal_uint32 event_group;
	lcd_frame_update_struct lcd_data;

	ENABLE_CMOS_SESNOR;

	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
	lcd_data.module_id			= LCD_UPDATE_MODULE_MEDIA;
	lcd_data.lcd_id				= isp_capture_barcode_data.lcd_id;
	lcd_data.fb_update_mode		= LCD_HW_TRIGGER_MODE;
	lcd_data.lcm_start_x			= isp_capture_barcode_data.lcm_start_x;
	lcd_data.lcm_start_y			= isp_capture_barcode_data.lcm_start_y;
	lcd_data.lcm_end_x			= isp_capture_barcode_data.lcm_end_x;
	lcd_data.lcm_end_y			= isp_capture_barcode_data.lcm_end_y;
	lcd_data.roi_offset_x		= isp_capture_barcode_data.roi_offset_x;
	lcd_data.roi_offset_y		= isp_capture_barcode_data.roi_offset_y;
	lcd_data.update_layer		= isp_capture_barcode_data.update_layer;
	lcd_data.hw_update_layer	= isp_capture_barcode_data.hw_update_layer;
	lcd_data.block_mode_flag	= KAL_TRUE;
	lcd_data.lcd_block_mode_cb	= NULL;

	intmem_init((kal_uint32 *) isp_capture_barcode_data.intmem_start_address,
					isp_capture_barcode_data.intmem_size);
	extmem_init((kal_uint32 *) isp_capture_barcode_data.extmem_start_address,
					isp_capture_barcode_data.extmem_size);

	config_image_dma(scene_id,isp_capture_barcode_data.target_width,isp_capture_barcode_data.target_height);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	wait_first_frame_flag=KAL_TRUE;
	isp_preview_frame=0;
	SET_CAMERA_PREVIEW_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;

  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);

	lcd_fb_update(&lcd_data);

	camera_process_stage|=LEAVE_RESUME_CAMERA_CAPTURE_BARCODE;
#endif
} /* resume_camera_capture_barcode_process() */

/*************************************************************************
* FUNCTION
*	camera_captuer_mem_process
*
* DESCRIPTION
*	This function capture one picture and overlap it with another frame
*
* PARAMETERS
*	isp_data : the parameters for camera capture and frame added process
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 camera_capture_mem_process(camera_capture_mem_struct *isp_data)
{
#if (defined(ISP_SUPPORT))
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_MEM_ID;
	lcd_frame_update_to_mem_struct lcd_data;
	kal_uint32 event_group;
	kal_uint16 temp_grab_size;
	kal_uint32 isp_capture_shutter;
	kal_uint16 isp_capture_pregain;
	volatile kal_uint8 i;
#if (!defined(DRV_ISP_6219_SERIES))
    kal_uint32  defect_reg_backup = REG_ISP_DEFECT_PIXEL_CONFIG;
#endif
#if (defined(EXIF_SUPPORT))
	exif_cam_para_struct* exif_cam_para_ptr;
 	exif_MTK_para_struct* exif_MTK_para_ptr;
#endif

	memset(&lcd_data, 0, sizeof(lcd_frame_update_to_mem_struct));	//initial lcd_data
	
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_count=0;
	hist_idx=0;
	ENABLE_CMOS_SESNOR;
#if (!defined(DRV_ISP_6219_SERIES))
    flashlight_pre_process();
#endif
	DISABLE_AE_COUNT;
#endif /* YUV_SENSOR_SUPPORT */

	isp_capture_mem_data.intmem_start_address=isp_data->intmem_start_address;
	isp_capture_mem_data.intmem_size=isp_data->intmem_size;
	isp_capture_mem_data.extmem_start_address=isp_data->extmem_start_address;
	isp_capture_mem_data.extmem_size=isp_data->extmem_size;
	isp_capture_mem_data.target_width=isp_data->target_width;
	isp_capture_mem_data.target_height=isp_data->target_height;
	isp_capture_mem_data.imgdma_buffer_address=isp_data->imgdma_buffer_address;
	isp_capture_mem_data.imgdma_buffer_size=isp_data->imgdma_buffer_size;
	exif_isp_target_width=isp_data->roi_width;
	exif_isp_target_height=isp_data->roi_height;

	isp_capture_mem_data.block_mode=isp_data->block_mode;
	isp_capture_mem_data.dest_block_width=isp_data->dest_block_width;
	isp_capture_mem_data.dest_buffer_address=isp_data->dest_buffer_address;
	isp_capture_mem_data.dest_buffer_size=isp_data->dest_buffer_size;
	isp_capture_mem_data.roi_offset_x=isp_data->roi_offset_x;
	isp_capture_mem_data.roi_offset_y=isp_data->roi_offset_y;
	isp_capture_mem_data.roi_width=isp_data->roi_width;
	isp_capture_mem_data.roi_height=isp_data->roi_height;
	isp_capture_mem_data.update_layer=isp_data->update_layer;
	isp_capture_mem_data.hw_update_layer=isp_data->hw_update_layer;
	isp_capture_mem_data.roi_background_color=isp_data->roi_background_color;

#if (!defined(YUV_SENSOR_SUPPORT))
	/* accoring the zoom factor to calculate the grab window area */
	exposure_window.image_target_width=isp_data->target_width;
	exposure_window.image_target_height=isp_data->target_height;
	exposure_window.digital_zoom_factor=isp_digital_zoom_factor;

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	ENABLE_CAMERA_IDLE_INT;
	SET_CAMERA_CAPTURE_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;

   kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);

	if((camera_oper_data.enable_cap_shutter_compensate==KAL_TRUE)&&
#if (!defined(DRV_ISP_6219_SERIES))
		(device_support_info.ae.sensor_basegain==BASEGAIN)&&
#endif
		(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE))
	{
#if (!defined(DRV_ISP_6219_SERIES))		
		if(CAM_ISO_MODE != dsc_status.dscmode)
		{
#endif		
		if((pregain>=camera_oper_data.shutter_compensate_max)&&
		   (eShutter<MAX_EXPOSURE_LINES))
		{
			sensor_config_data.enable_shutter_tansfer=KAL_TRUE;

			isp_capture_shutter=eShutter*pregain/camera_oper_data.shutter_compensate_max;
			if(isp_capture_shutter>MAX_EXPOSURE_LINES)
			   isp_capture_shutter=MAX_EXPOSURE_LINES;
			if(isp_capture_shutter>BaseShutter)
				isp_capture_shutter=(isp_capture_shutter/BaseShutter)*BaseShutter;
			isp_capture_pregain=eShutter*pregain/isp_capture_shutter;
			if(isp_capture_pregain>camera_oper_data.pregain_max)
				isp_capture_pregain=camera_oper_data.pregain_max;

			ae_set_pregain(isp_capture_pregain);
			sensor_config_data.capture_shutter=isp_capture_shutter;
		}
		else
			sensor_config_data.enable_shutter_tansfer=KAL_FALSE;
#if (!defined(DRV_ISP_6219_SERIES))		
		}
		else
		{
			sensor_config_data.enable_shutter_tansfer=KAL_FALSE;		
		}		
#endif		
	}
	else
		sensor_config_data.enable_shutter_tansfer=KAL_FALSE;

	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
		sensor_config_data.meta_mode = CAPTURE_MODE_NORMAL;	// for normal mode capture
	else
		sensor_config_data.meta_mode = CAPTURE_MODE_META;		// for META mode capture

	image_sensor_func->sensor_capture_setting(&exposure_window,&sensor_config_data);
#if (!defined(DRV_ISP_6219_SERIES))
    flashlight_post_process();
#endif

	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
	set_camera_mode_para(CAMERA_PARA_CAPTURE_MODE);

	/* accoring the zoom factor to calculate the grab window area */
   isp_horizontal_subsample=exposure_window.isp_hsub_factor;
   isp_vertical_subsample=exposure_window.isp_vsub_factor;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFE);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((isp_data->target_width * exposure_window.exposure_window_height) >=
		 (isp_data->target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * isp_data->target_height/isp_data->target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * isp_data->target_width/isp_data->target_height)&0xFFFE;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
	}

	isp_grab_start_x-=(((isp_grab_width*(isp_horizontal_subsample-1))>>1)&0xFFFE);
	isp_grab_start_y-=((isp_grab_height*(isp_vertical_subsample-1))>>1);

	align_center_point();
	SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
	SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));

/* set gamma 1024 */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	apply_take_image_with_gamma_1024_by_flag();
#endif

#if(defined(DRV_ISP_6219_SERIES))
	SET_SUB_SAMPLE_MODE(CAMERA_SUB_SAMPLE_1_1);
#else
	ENABLE_VERTICAL_SUB_SAMPLE;
	ENABLE_HORIZONTAL_SUB_SAMPLE;
	
	SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));	
	SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
	SET_HSUB_DST_SIZE(isp_grab_width);
	SET_VSUB_DST_SIZE(isp_grab_height);
    // Disable Defect Table
    DISABLE_DEFECT_CORRECTION;
#endif

	isp_capture_mem_data.source_width=isp_grab_width;
	isp_capture_mem_data.source_height=isp_grab_height;

#if (defined(LED_FLASHLIGHT_SUPPORT)||defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
    if(flashlight_redeye_process(camera_oper_data.capture_delay_frame)==KAL_FALSE)
    {
	for(i=0;i<camera_oper_data.capture_delay_frame;i++)
	{
	   DISABLE_VIEW_FINDER_MODE;
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;

	   kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
	                          &event_group,KAL_SUSPEND);
	}
    }   
    // Enable flash trigger before image data path open.
    flashlight_trigger_process();
#else	
	for(i=0;i<camera_oper_data.capture_delay_frame;i++)
	{
	   DISABLE_VIEW_FINDER_MODE;
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;
	
	   kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
	                          &event_group,KAL_SUSPEND);
	}
#endif

	DISABLE_VIEW_FINDER_MODE;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	intmem_init((kal_uint32 *) isp_capture_mem_data.intmem_start_address,
					isp_capture_mem_data.intmem_size);
	extmem_init((kal_uint32 *) isp_capture_mem_data.extmem_start_address,
					isp_capture_mem_data.extmem_size);
#endif

	lcd_data.fb_update_mode=LCD_HW_TRIGGER_MODE;
	lcd_data.block_mode=isp_data->block_mode;
	lcd_data.dest_block_width=isp_data->dest_block_width;
	lcd_data.dest_buffer_address=isp_data->dest_buffer_address;
	lcd_data.dest_buffer_size=isp_data->dest_buffer_size;
	lcd_data.roi_offset_x=isp_data->roi_offset_x;
	lcd_data.roi_offset_y=isp_data->roi_offset_y;
	lcd_data.roi_width=isp_data->roi_width;
	lcd_data.roi_height=isp_data->roi_height;
	lcd_data.update_layer=isp_data->update_layer;
	lcd_data.hw_update_layer=isp_data->hw_update_layer;
#if (!defined(DRV_ISP_6219_SERIES))
	lcd_data.roi_background_color=isp_data->roi_background_color;
#endif
#endif /* YUV_SENSOR_SUPPORT */

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	isp_capture_mem_data.manual_wb        					=	isp_data->manual_wb;
	isp_capture_mem_data.memory_data_format				=	isp_data->memory_data_format;

	/* Prepare IPP Data */
	ipp_capture_mem_data.intmem_start_address				=	isp_data->intmem_start_address;
	ipp_capture_mem_data.intmem_size							=	isp_data->intmem_size;
	ipp_capture_mem_data.extmem_start_address				=	isp_data->extmem_start_address;
	ipp_capture_mem_data.extmem_size							=	isp_data->extmem_size;

	ipp_capture_mem_data.image_src_width					=	isp_capture_mem_data.source_width;
	ipp_capture_mem_data.image_src_height					=	isp_capture_mem_data.source_height;
	ipp_capture_mem_data.image_capture_width				=	isp_data->target_width;
	ipp_capture_mem_data.image_capture_height				=	isp_data->target_height;

	ipp_capture_mem_data.overlay_frame_mode				=	isp_data->overlay_frame_mode;
	ipp_capture_mem_data.overlay_color_depth				=	isp_data->overlay_color_depth;
	ipp_capture_mem_data.overlay_frame_source_key		=	isp_data->overlay_frame_source_key;
	ipp_capture_mem_data.overlay_frame_width				=	isp_data->overlay_frame_width;
	ipp_capture_mem_data.overlay_frame_height				=	isp_data->overlay_frame_height;
	ipp_capture_mem_data.overlay_frame_buffer_address	=	isp_data->overlay_frame_buffer_address;

	ipp_capture_mem_data.image_pitch_mode					=	isp_data->image_pitch_mode;
	ipp_capture_mem_data.image_data_format					=	isp_data->image_data_format;
	ipp_capture_mem_data.image_pitch_bytes					=	isp_data->image_pitch_bytes;

	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
		ipp_capture_mem_data.image_clip_mode				=	KAL_FALSE;
	else
		ipp_capture_mem_data.image_clip_mode				=	isp_data->image_clip_mode;
	ipp_capture_mem_data.image_clip_x1						=	isp_data->image_clip_x1;
	ipp_capture_mem_data.image_clip_x2						=	isp_data->image_clip_x2;
	ipp_capture_mem_data.image_clip_y1						=	isp_data->image_clip_y1;
	ipp_capture_mem_data.image_clip_y2						=	isp_data->image_clip_y2;

	ipp_capture_mem_data.frame_buffer_address				=	isp_data->imgdma_buffer_address;
	ipp_capture_mem_data.frame_buffer_size					=	isp_data->imgdma_buffer_size;

#if (!defined(YUV_SENSOR_SUPPORT))
	/* Prepare LCD Data */
	lcd_data.hw_trigger_src			=	LCD_HW_TRIGGER_IBW2;
	lcd_data.memory_data_format	=	isp_data->memory_data_format;
#endif /* YUV_SENSOR_SUPPORT */

#endif

#if (!defined(YUV_SENSOR_SUPPORT))
	lcd_fb_update_to_memory(&lcd_data);

#if (defined(EXIF_SUPPORT))
   /* config exif header */
   exif_cam_para_ptr=exif_get_cam_para_struct();
   exif_MTK_para_ptr=exif_get_MTK_para_struct();
   exif_update_cam_para_struct(exif_cam_para_ptr);
#endif

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	config_image_dma(scene_id,isp_data->target_width,isp_data->target_height);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	open_image_data_path(scene_id);
	config_camera_capture_mem_data_path(scene_id,&ipp_capture_mem_data);
#endif

	isp_operation_state=ISP_CAPTURE_MEM_STATE;
   /* skip setting for cct mode */
	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
	{
	camera_image_setting(CAM_PARAM_EFFECT,isp_preview_config_data.image_effect);
	if(isp_preview_config_data.image_effect==0)
	{
		camera_image_setting(CAM_PARAM_CONTRAST,isp_preview_config_data.contrast_level);
		camera_image_setting(CAM_PARAM_BRIGHTNESS,isp_preview_config_data.brightness_level);
		camera_image_setting(CAM_PARAM_HUE,isp_preview_config_data.hue_value);
		camera_image_setting(CAM_PARAM_SATURATION,isp_preview_config_data.saturation_value);
	}
	camera_image_setting(CAM_PARAM_WB,isp_preview_config_data.wb_mode);
	camera_image_setting(CAM_PARAM_EXPOSURE,isp_preview_config_data.ev_value);
	camera_image_setting(CAM_PARAM_BANDING,isp_preview_config_data.banding_freq);
	camera_image_setting(CAM_PARAM_NIGHT_MODE,(kal_uint16)isp_preview_config_data.night_mode);
	if((isp_preview_config_data.image_effect==0) && (isp_preview_config_data.night_mode))
		set_camera_mode_para(CAMERA_PARA_NIGHT_MODE);
	awb_set_gain();
	}

	kal_set_eg_events(lcd_event_id,0,KAL_AND);

	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)
	{
	if(isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)
	{
   	set_camera_mode_para(CAMERA_PARA_CAPTURE_MODE);
#if (!defined(DRV_ISP_6219_SERIES))
		set_anti_low_light_para(AE_INDEX_ENV);
#endif
   }
#if (defined(DRV_ISP_6219_SERIES))
	if((camera_oper_data.flare_camera_enable==KAL_TRUE)&&(isp_preview_config_data.image_effect==0))
	{
		SET_AWB_R_GAIN(flare_gain);
		SET_AWB_G_GAIN(flare_gain);
		SET_AWB_B_GAIN(flare_gain);
		SET_GAMMA_RGB_FLARE_R(flare_offset);
		SET_GAMMA_RGB_FLARE_G(flare_offset);
		SET_GAMMA_RGB_FLARE_B(flare_offset);
		SET_GAMMA_RGB_FLARE_SIGN_R_HIGH;
		SET_GAMMA_RGB_FLARE_SIGN_G_HIGH;
		SET_GAMMA_RGB_FLARE_SIGN_B_HIGH;
	}
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	if(isp_capture_mem_data.manual_wb==KAL_TRUE)
		camera_manual_wb_setting();
#endif
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
    /* Restore Defect Table Setting */
    REG_ISP_DEFECT_PIXEL_CONFIG = defect_reg_backup;

	apply_camera_shading_to_reg(CAMERA_COMP_CAPTURE_NORMAL_SET);
	if(camera_oper_data.capture_defect_table_enable==KAL_TRUE)
	{
		load_defect_table_para(DEFECT_MODE_CAPTURE);
		ENABLE_DEFECT_CORRECTION;
	}
	else
		DISABLE_DEFECT_CORRECTION;
#endif
	}

	ENABLE_VIEW_FINDER_MODE;
   kal_retrieve_eg_events(lcd_event_id,LCD_TRANSFER_COMPLETE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);

	kal_sleep_task(15);
	DISABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
	DISABLE_1024_GAMMA_TABLE;
#endif
	lcd_stop_hw_update(current_update_lcd);
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);

	clean_imgprc_coefficient(scene_id);
	IMGPROC_Stop(scene_id);
	IMGPROC_Close(scene_id);

	stop_image_dma(scene_id);
	IMGDMA_Close(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	close_image_data_path(scene_id);
#endif

	isp_operation_state=ISP_STANDBY_STATE;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	intmem_deinit();
	extmem_deinit();
#endif

	/* Restore pregain of preview mode */
	if(sensor_config_data.enable_shutter_tansfer==KAL_TRUE)
	{
#if (defined(DRV_ISP_6219_SERIES))
		ae_set_pregain(pregain);
#else
		ae_set_lut_gain();
#endif
	}

#if (!defined(DRV_ISP_6219_SERIES))
   flashlight_stop_process();
#endif
#endif /* YUV_SENSOR_SUPPORT */

#if (defined(YUV_SENSOR_SUPPORT))
	camera_yuv_capture_mem_process();
#endif /* YUV_SENSOR_SUPPORT */

	camera_process_stage|=LEAVE_CAMERA_CAPTURE_MEM;
	return KAL_TRUE;
#endif
}	/* camera_capture_mem_process() */

/*************************************************************************
* FUNCTION
*	mpeg4_encode_process
*
* DESCRIPTION
*	This function starts mpeg4 encode process
*
* PARAMETERS
*	mpeg4_data : the parameters for mpeg4 encode
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (defined(MP4_CODEC))
void video_enc_dma_lisr(kal_uint32 encode_work_yuv);
#endif
kal_uint8 mpeg4_encode_process(mpeg4_encode_process_struct *mpeg4_data)
{
#if (defined(ISP_SUPPORT)&&!defined(DRV_ISP_6225_SERIES))
#if (defined(MP4_CODEC))
	kal_uint16 temp_grab_size;
	MMDI_SCENERIO_ID scene_id=SCENARIO_MPEG_ENCODE_ID;
	lcd_frame_update_struct lcd_data;
	kal_uint32 video_buffer_size;
	volatile kal_uint8 i=0,j=0;
	kal_uint8 returncode=0;

#if (!defined(YUV_SENSOR_SUPPORT))
	if (sensor_err_check<0)
		return (kal_uint8)SENSOR_ERROR;

#if defined(ANALOG_TV_SUPPORT)
 if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif  /*ANALOG_TV_SUPPORT*/	
{   //ANALOG_TV_SUPPORT

#if (defined(DRV_ISP_6219_SERIES))
	if ((mpeg4_data->mpeg4_image_width!=176) || (mpeg4_data->mpeg4_image_height!=144))
		ASSERT(0);
#endif

	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
	
	isp_enter_exit_process_flag=KAL_FALSE;

}   //ANALOG_TV_SUPPORT
#endif /* YUV_SENSOR_SUPPORT */

	/* for new mpeg4 encode trigger procedure */
	isp_preview_config_data.lcd_id=mpeg4_data->lcd_id;
	isp_preview_config_data.zoom_factor=mpeg4_data->zoom_factor;
	isp_preview_config_data.contrast_level=mpeg4_data->contrast_level;
	isp_preview_config_data.brightness_level=mpeg4_data->brightness_level;
	isp_preview_config_data.saturation_value=mpeg4_data->saturation_value;
	isp_preview_config_data.wb_mode=mpeg4_data->wb_mode;
	isp_preview_config_data.ev_value=mpeg4_data->ev_value;
	isp_preview_config_data.banding_freq=mpeg4_data->banding_freq;
	isp_preview_config_data.image_effect=mpeg4_data->image_effect;
	isp_preview_config_data.night_mode=mpeg4_data->night_mode;

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)
 if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif /*ANALOG_TV_SUPPORT*/	
{  //ANALOG_TV_SUPPORT

#if (!(defined(DRV_ISP_6219_SERIES)||defined(YUV_SENSOR_SUPPORT)))/* AE smooth update custom para & init table */
	init_ae_smooth_custom_para(AE_SMOOTH_VIDEO);
#endif
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_on_off(KAL_TRUE);
	awb_on_off(KAL_TRUE);
#endif
	DISABLE_CAMERA_IDLE_INT;
	ENABLE_AE_COUNT;
	ENABLE_CMOS_SESNOR;

#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
   // Disable AE Count before Start Preview
	DISABLE_AE_COUNT;
	REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	DISABLE_CMOS_SESNOR;
#endif
	sensor_config_data.isp_op_mode=ISP_MPEG4_PREVIEW_MODE;
	sensor_config_data.image_mirror=mpeg4_data->image_mirror;
	sensor_config_data.frame_rate=mpeg4_data->frame_rate;
	exposure_window.image_target_width=mpeg4_data->mpeg4_image_width;
	exposure_window.image_target_height=mpeg4_data->mpeg4_image_height;
	exposure_window.current_exposure_pixel=exposure_window.exposure_pixel=1;
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);
	kal_sleep_task(15);
	
/* sensor preview init at first to update QCIF flag */
#if (!defined(DRV_ISP_6219_SERIES))
	lut_info.band=isp_preview_config_data.banding_freq;
	lut_info.videomode=KAL_TRUE;
	if(isp_preview_config_data.night_mode==KAL_TRUE)
		lut_info.dscmode=CAM_NIGHTSCENE;
	else
		lut_info.dscmode=CAM_AUTO_DSC;
	AE_LUT=get_ae_lut(lut_info);
      if(device_support_info.ae.sensor_basegain==0)
               device_support_info.ae.sensor_basegain = BASEGAIN;
	camera_operation_setting(CAM_AE_METERING,CAM_AE_METER_AVERAGE);
#endif

	/* accorind the zoom factor to calculate the grab window area */
   isp_horizontal_subsample=exposure_window.isp_hsub_factor;
   isp_vertical_subsample=exposure_window.isp_vsub_factor;
	isp_digital_zoom_factor=isp_preview_config_data.zoom_factor;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFE ;

	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFE);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((mpeg4_data->mpeg4_image_width * exposure_window.exposure_window_height) >=
		 (mpeg4_data->mpeg4_image_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * mpeg4_data->mpeg4_image_height/
							 mpeg4_data->mpeg4_image_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * mpeg4_data->mpeg4_image_width/
							mpeg4_data->mpeg4_image_height)&0xFFFE;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
	}

	isp_grab_start_x-=(((isp_grab_width*(isp_horizontal_subsample-1))>>1)&0xFFFE);
	isp_grab_start_y-=((isp_grab_height*(isp_vertical_subsample-1))>>1);

	align_center_point();
	SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
	SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_config((isp_grab_width*isp_horizontal_subsample),(isp_grab_height*isp_vertical_subsample));
#endif
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
	DISABLE_1024_GAMMA_TABLE;
#endif

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
	apply_camera_shading_to_reg(CAMERA_COMP_PREVIEW_NORMAL_SET);
	if(camera_oper_data.preview_defect_table_enable==KAL_TRUE)
	{
		load_defect_table_para(DEFECT_MODE_PREVIEW);
		ENABLE_DEFECT_CORRECTION;
	}
	else
		DISABLE_DEFECT_CORRECTION;
#endif

}  //ANALOG_TV_SUPPORT

#endif /* YUV_SENSOR_SUPPORT */

	mpeg4_encode_data.intmem_start_address=mpeg4_data->intmem_start_address;
	mpeg4_encode_data.intmem_size=mpeg4_data->intmem_size;
	mpeg4_encode_data.extmem_start_address=mpeg4_data->extmem_start_address;
	mpeg4_encode_data.extmem_size=mpeg4_data->extmem_size;

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)     	
 if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif  /*ANALOG_TV_SUPPORT*/	
 {  //ANALOG_TV_SUPPORT

#if(defined(DRV_ISP_6219_SERIES))
	/* accoring the zoom factor to calculate the grab window area */
	if ((isp_grab_width< ((mpeg4_data->mpeg4_image_width)<<1)) &&
		 (isp_grab_height< ((mpeg4_data->mpeg4_image_height)<<1)))
	{
		SET_SUB_SAMPLE_MODE(CAMERA_SUB_SAMPLE_1_1);
		mpeg4_encode_data.image_source_width=isp_grab_width;
		mpeg4_encode_data.image_source_height=isp_grab_height;
	}
	else if ((isp_grab_width< ((mpeg4_data->mpeg4_image_width)<<2)) &&
		 (isp_grab_height< ((mpeg4_data->mpeg4_image_height)<<2)))
	{
		SET_SUB_SAMPLE_MODE(CAMERA_SUB_SAMPLE_1_2);
		mpeg4_encode_data.image_source_width=isp_grab_width>>1;
		mpeg4_encode_data.image_source_height=isp_grab_height>>1;
	}
	else if ((isp_grab_width< ((mpeg4_data->mpeg4_image_width)<<3)) &&
		 (isp_grab_height< ((mpeg4_data->mpeg4_image_height)<<3)))
	{
		SET_SUB_SAMPLE_MODE(CAMERA_SUB_SAMPLE_1_4);
		mpeg4_encode_data.image_source_width=isp_grab_width>>2;
		mpeg4_encode_data.image_source_height=isp_grab_height>>2;
	}
#elif  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ENABLE_VERTICAL_SUB_SAMPLE;
	ENABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));	
	SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
	if((isp_grab_width>(mpeg4_data->mpeg4_image_width<<2)) || (isp_grab_height>(mpeg4_data->mpeg4_image_height<<2)))
	{	/* grab size > taget size *4 => ISP subsample 4x */
		SET_HSUB_DST_SIZE(isp_grab_width>>2);
		SET_VSUB_DST_SIZE(isp_grab_height>>2);
		mpeg4_encode_data.image_source_width=isp_grab_width>>2;
		mpeg4_encode_data.image_source_height=isp_grab_height>>2;
	}
	else if((isp_grab_width>(mpeg4_data->mpeg4_image_width<<1)) || (isp_grab_height>(mpeg4_data->mpeg4_image_height<<1)))
	{	/* grab size > taget size *2 => ISP subsample 2x */
		SET_HSUB_DST_SIZE(isp_grab_width>>1);
		SET_VSUB_DST_SIZE(isp_grab_height>>1);
		mpeg4_encode_data.image_source_width=isp_grab_width>>1;
		mpeg4_encode_data.image_source_height=isp_grab_height>>1;
	}
	else
	{
		if((isp_grab_width>=((mpeg4_data->mpeg4_image_width)+2)) && (isp_grab_height>=((mpeg4_data->mpeg4_image_height)+2)))
		{
			SET_HSUB_DST_SIZE(mpeg4_data->mpeg4_image_width+2);
			SET_VSUB_DST_SIZE(mpeg4_data->mpeg4_image_height+2);
			mpeg4_encode_data.image_source_width=mpeg4_data->mpeg4_image_width+2;
			mpeg4_encode_data.image_source_height=mpeg4_data->mpeg4_image_height+2;
		}
		else
		{
			if((isp_grab_width==mpeg4_data->mpeg4_image_width) && (isp_grab_height==mpeg4_data->mpeg4_image_height))
			{
				SET_HSUB_DST_SIZE(isp_grab_width-2);
				SET_VSUB_DST_SIZE(isp_grab_height-2);
				mpeg4_encode_data.image_source_width=isp_grab_width-2;
				mpeg4_encode_data.image_source_height=isp_grab_height-2;
			}
			else
			{
				SET_HSUB_DST_SIZE(isp_grab_width);
				SET_VSUB_DST_SIZE(isp_grab_height);
				mpeg4_encode_data.image_source_width=isp_grab_width;
				mpeg4_encode_data.image_source_height=isp_grab_height;
			}
		}
	}
#endif

}   //ANALOG_TV_SUPPORT
#endif /* YUV_SENSOR_SUPPORT */

	mpeg4_encode_data.image_mirror=mpeg4_data->image_mirror;
	mpeg4_encode_data.frame_rate=mpeg4_data->frame_rate;
	mpeg4_encode_data.mpeg4_image_width=mpeg4_data->mpeg4_image_width;
	mpeg4_encode_data.mpeg4_image_height=mpeg4_data->mpeg4_image_height;
	mpeg4_encode_data.image_target_width=mpeg4_data->image_target_width;
	mpeg4_encode_data.image_target_height=mpeg4_data->image_target_height;

	mpeg4_encode_data.lcd_id=mpeg4_data->lcd_id;
	mpeg4_encode_data.lcm_start_x=mpeg4_data->lcm_start_x;
	mpeg4_encode_data.lcm_start_y=mpeg4_data->lcm_start_y;
	mpeg4_encode_data.lcm_end_x=mpeg4_data->lcm_end_x;
	mpeg4_encode_data.lcm_end_y=mpeg4_data->lcm_end_y;
	mpeg4_encode_data.roi_offset_x=mpeg4_data->roi_offset_x;
	mpeg4_encode_data.roi_offset_y=mpeg4_data->roi_offset_y;
	mpeg4_encode_data.update_layer=mpeg4_data->update_layer;
	mpeg4_encode_data.hw_update_layer=mpeg4_data->hw_update_layer;
	mpeg4_encode_data.rotate_value=mpeg4_data->rotate_value;
	mpeg4_encode_data.cam_encode_cb=mpeg4_data->cam_encode_cb;
	mpeg4_encode_data.mpeg4_encode_cb=video_enc_dma_lisr;
	mpeg4_encode_data.frame_buffer_address=mpeg4_data->frame_buffer_address;
	mpeg4_encode_data.frame_buffer_size=mpeg4_data->frame_buffer_size;
	mpeg4_encode_data.mpeg4_offset_x=mpeg4_data->mpeg4_offset_x;
	mpeg4_encode_data.mpeg4_offset_y=mpeg4_data->mpeg4_offset_y;
	mpeg4_encode_data.lcd_update=mpeg4_data->lcd_update;
	mpeg4_encode_data.init_mem=mpeg4_data->init_mem;

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)   
 if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
 #endif  /*ANALOG_TV_SUPPORT*/	
 {	//ANALOG_TV_SUPPORT
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	if(mpeg4_encode_data.init_mem == KAL_TRUE)
	{
		intmem_init((kal_uint32 *) mpeg4_encode_data.intmem_start_address,
						mpeg4_encode_data.intmem_size);
		extmem_init((kal_uint32 *) mpeg4_encode_data.extmem_start_address,
						mpeg4_encode_data.extmem_size);
	}
#endif

	lcd_data.module_id=LCD_UPDATE_MODULE_MEDIA;
	lcd_data.lcd_id= mpeg4_encode_data.lcd_id;

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	if (get_lcd_hw_layer_rotate_value(mpeg4_encode_data.hw_update_layer)==LCD_LAYER_ROTATE_NORMAL)
		lcd_data.fb_update_mode=LCD_DIRECT_COUPLE_MODE;
	else
	        lcd_data.fb_update_mode=LCD_HW_TRIGGER_MODE;
#else
	lcd_data.fb_update_mode=LCD_HW_TRIGGER_MODE;
#endif

	lcd_data.lcm_start_x=mpeg4_encode_data.lcm_start_x;
	lcd_data.lcm_start_y=mpeg4_encode_data.lcm_start_y;
	lcd_data.lcm_end_x=mpeg4_encode_data.lcm_end_x;
	lcd_data.lcm_end_y=mpeg4_encode_data.lcm_end_y;
	lcd_data.roi_offset_x=mpeg4_encode_data.roi_offset_x;
	lcd_data.roi_offset_y=mpeg4_encode_data.roi_offset_y;
	lcd_data.update_layer=mpeg4_encode_data.update_layer;
	lcd_data.hw_update_layer=mpeg4_encode_data.hw_update_layer;
#if (!defined(DRV_ISP_6219_SERIES))
	lcd_data.roi_background_color=mpeg4_data->roi_background_color;
#endif

} //ANALOG_TV_SUPPORT

#endif /* YUV_SENSOR_SUPPORT */

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	mpeg4_encode_data.tv_output						=	mpeg4_data->tv_output;
	mpeg4_encode_data.tv_output_width				=	mpeg4_data->tv_output_width;
	mpeg4_encode_data.tv_output_height				=	mpeg4_data->tv_output_height;
	mpeg4_encode_data.tv_output_offset_x			=	mpeg4_data->tv_output_offset_x;
	mpeg4_encode_data.tv_output_offset_y			=	mpeg4_data->tv_output_offset_y;
	mpeg4_encode_data.tv_output_buffer1_address	=	mpeg4_data->tv_output_buffer1_address;
	mpeg4_encode_data.tv_output_buffer2_address	=	mpeg4_data->tv_output_buffer2_address;
	mpeg4_encode_data.tv_output_buffer_size		=	mpeg4_data->tv_output_buffer_size;

	/* Prepare IPP Data */
	ipp_video_encode_data.intmem_start_address				=	mpeg4_data->intmem_start_address;
	ipp_video_encode_data.intmem_size							=	mpeg4_data->intmem_size;
	ipp_video_encode_data.extmem_start_address				=	mpeg4_data->extmem_start_address;
	ipp_video_encode_data.extmem_size							=	mpeg4_data->extmem_size;

	ipp_video_encode_data.image_src_width						=	mpeg4_encode_data.image_source_width;
	ipp_video_encode_data.image_src_height						=	mpeg4_encode_data.image_source_height;
	ipp_video_encode_data.display_width							=	mpeg4_data->image_target_width;
	ipp_video_encode_data.display_height						=	mpeg4_data->image_target_height;
	ipp_video_encode_data.encode_width							=	mpeg4_data->mpeg4_image_width;
	ipp_video_encode_data.encode_height							=	mpeg4_data->mpeg4_image_height;

	ipp_video_encode_data.overlay_frame_mode					=	mpeg4_data->overlay_frame_mode;
	ipp_video_encode_data.overlay_color_depth					=	mpeg4_data->overlay_color_depth;
	ipp_video_encode_data.overlay_frame_source_key			=	mpeg4_data->overlay_frame_source_key;
	ipp_video_encode_data.overlay_frame_width					=	mpeg4_data->overlay_frame_width;
	ipp_video_encode_data.overlay_frame_height				=	mpeg4_data->overlay_frame_height;
	ipp_video_encode_data.overlay_frame_buffer_address		=	mpeg4_data->overlay_frame_buffer_address;

	ipp_video_encode_data.image_pitch_mode						=	mpeg4_data->image_pitch_mode;
	ipp_video_encode_data.image_data_format					=	mpeg4_data->image_data_format;
	ipp_video_encode_data.image_pitch_bytes					=	mpeg4_data->image_pitch_bytes;

	ipp_video_encode_data.frame_buffer_address				=	mpeg4_data->frame_buffer_address;
	ipp_video_encode_data.frame_buffer_size					=	mpeg4_data->frame_buffer_size;

	ipp_video_encode_data.tv_output = mpeg4_data->tv_output;
	ipp_video_encode_data.tv_output_buffer1_address = mpeg4_data->tv_output_buffer1_address;
	ipp_video_encode_data.tv_output_buffer2_address = mpeg4_data->tv_output_buffer2_address;
	ipp_video_encode_data.tv_output_buffer_size = mpeg4_data->tv_output_buffer_size;
	ipp_video_encode_data.init_mem=mpeg4_data->init_mem;

	ipp_video_encode_data.video_encode_cb=mpeg4_encode_data.mpeg4_encode_cb;

#if (!defined(YUV_SENSOR_SUPPORT))

#if defined(ANALOG_TV_SUPPORT)   	
  if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif   /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	
{	//ANALOG_TV_SUPPORT

	/* Prepare LCD Data */
	lcd_data.hw_trigger_src 					= LCD_HW_TRIGGER_IBW2;
	lcd_data.memory_output=KAL_FALSE;
	lcd_data.block_mode_flag=KAL_TRUE;
	lcd_data.lcd_block_mode_cb=NULL;

#if (defined(TV_OUT_SUPPORT))
	if ((mpeg4_data->tv_output==KAL_TRUE)&&(tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE1))
	{
		lcd_data.tv_output=KAL_TRUE;
		lcd_data.tv_output_width=mpeg4_data->tv_output_width;
		lcd_data.tv_output_height=mpeg4_data->tv_output_height;
		lcd_data.tv_output_offset_x=mpeg4_data->tv_output_offset_x;
		lcd_data.tv_output_offset_y=mpeg4_data->tv_output_offset_y;
		lcd_data.tv_output_frame_buffer1_address=mpeg4_data->tv_output_buffer1_address;
		lcd_data.tv_output_frame_buffer2_address=mpeg4_data->tv_output_buffer2_address;
		lcd_data.tv_output_frame_buffer_size=mpeg4_data->tv_output_buffer_size;

		ipp_video_encode_data.tv_output=KAL_FALSE;
	}
	else
	{
		lcd_data.tv_output=KAL_FALSE;
	}
#endif	/* TV_OUT_SUPPORT */

}  //ANALOG_TV_SUPPORT

#endif /* YUV_SENSOR_SUPPORT */
#endif

#if (!defined(YUV_SENSOR_SUPPORT))

#if defined(ANALOG_TV_SUPPORT)   
 if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
#endif  /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/
{  //ANALOG_TV_SUPPORT

	isp_operation_state=ISP_MPEG4_ENCODE_STATE;

	camera_image_setting(CAM_PARAM_NIGHT_MODE,(kal_uint16)isp_preview_config_data.night_mode);
	if((isp_preview_config_data.image_effect==0) && (isp_preview_config_data.night_mode))
		set_camera_mode_para(CAMERA_PARA_NIGHT_MODE);
	awb_set_gain();

#if (!(defined(DRV_ISP_6219_SERIES)||defined(YUV_SENSOR_SUPPORT)))
    /* init AE/AWB setting */
	AE_INDEX = ae_apply_index_update(dsc_status.dscmode, dsc_status.ae.iso, AE_INDEX_ENV);
    AE_INDEX_C = AE_INDEX;
    eShutter=AE_LUT[AE_INDEX].shutter;		        /* Get Shutter */
    	sensor_pregain = ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);     /* Get Gain */	
    isp_pregain=AE_LUT[AE_INDEX].ispgain;
    pregain=sensor_pregain*isp_pregain/BASEGAIN;
    image_sensor_func->set_sensor_eshutter(eShutter);
    image_sensor_func->set_sensor_gain(sensor_pregain);
    ae_set_isp_pregain();
#endif

	wait_first_frame_flag=KAL_TRUE;
	isp_preview_frame=0;
	isp_preview_2a_enable=0;
	SET_CAMERA_PREVIEW_MODE;
	SET_CAMERA_FRAME_RATE(0);
#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
   // Enable AE Count before Start Preview
	REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
	ENABLE_AE_COUNT;
#endif
#if  (defined(DRV_ISP_6228_SERIES))
	RESET_ISP;
	CLEAR_RESET_ISP;
#endif

   #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
      ENABLE_CAMERA_ISP_DONE_INT
      ENABLE_LCD_TRANSFER_COMPLETE_INT
   #endif

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ENABLE_CMOS_SESNOR;
#endif
	ENABLE_VIEW_FINDER_MODE;

	ae_awb_cal_complete=1;
	isp_preview_2a_enable=0;
	ae_count=0;
	hist_idx=0;

	/* Wait AE AWB Stable */
	if(isp_first_preview_frame==KAL_TRUE)
	{
		for(i=0;i<camera_oper_data.preview_display_wait_frame;i++)
		{
			j=0;
			while(j<22*camera_oper_data.ae_awb_cal_period)
			{
				if(isp_preview_2a_enable==1)
				{
					ae_awb_main();
					isp_preview_2a_enable=0;
					break;
				}
				else
				{
					kal_sleep_task(2);
					j++;
				}
			}
		}
		isp_first_preview_frame=KAL_FALSE;
	}

	isp_idle_done_flag=KAL_FALSE;
	ENABLE_CAMERA_IDLE_INT;
	DISABLE_VIEW_FINDER_MODE;
	i=0;
	kal_sleep_task(25);  /* wait valid IDLE interrupt */
	while(isp_idle_done_flag==KAL_FALSE)
	{
		i++;
		kal_sleep_task(5);
		if(i>9) break;
	}
	DISABLE_CAMERA_IDLE_INT;

#ifdef __SYNC_LCM_SW_SUPPORT__
	sync_lcm_enable_mode=KAL_TRUE;
#endif
	if(mpeg4_encode_data.lcd_update==KAL_TRUE)
		lcd_fb_update(&lcd_data);
	else
	{
		lcd_data.update_layer&=~lcd_data.hw_update_layer;		
		lcd_fb_update(&lcd_data);		
	}		

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	if(mpeg4_encode_data.init_mem == KAL_TRUE)
	{
		video_buffer_size=mpeg4_encode_data.mpeg4_image_width * mpeg4_encode_data.mpeg4_image_height * 3;
		video_buffer_size>>=1;
		mpeg4_encode_data.video_buffer1_address=(kal_uint32) intmem_get_buffer(video_buffer_size);
		mpeg4_encode_data.video_buffer2_address=(kal_uint32) intmem_get_buffer(video_buffer_size);
	}

	config_image_dma(scene_id,mpeg4_data->image_target_width,mpeg4_data->image_target_height);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	open_image_data_path(scene_id);
	config_video_encode_data_path(scene_id,&ipp_video_encode_data);
#endif

}  //ANALOG_TV_SUPPORT
#endif /* YUV_SENSOR_SUPPORT */

	mpeg4_encode_config_data.short_header	=	mpeg4_data->short_header_mode;
	mpeg4_encode_config_data.bit_rate		=	mpeg4_data->encode_bit_rate;
	mpeg4_encode_config_data.frame_width	=	mpeg4_data->mpeg4_image_width;
	mpeg4_encode_config_data.frame_height	=	mpeg4_data->mpeg4_image_height;
	mpeg4_encode_config_data.call_back		=	mpeg4_data->encode_event_cb;
	mpeg4_encode_data.resume_enable=mpeg4_data->resume_enable;

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)   
 if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
 #endif /*ANALOG_TV_SUPPORT*/	
{  //ANALOG_TV_SUPPORT

	camera_image_setting(CAM_PARAM_EFFECT,isp_preview_config_data.image_effect);
	set_camera_mode_para(CAMERA_PARA_VIDEO_MODE);
	if(isp_preview_config_data.image_effect==0)
	{
		camera_image_setting(CAM_PARAM_CONTRAST,isp_preview_config_data.contrast_level);
		camera_image_setting(CAM_PARAM_BRIGHTNESS,isp_preview_config_data.brightness_level);
		camera_image_setting(CAM_PARAM_SATURATION,isp_preview_config_data.saturation_value);
	}
	camera_image_setting(CAM_PARAM_WB,isp_preview_config_data.wb_mode);
	camera_image_setting(CAM_PARAM_EXPOSURE,isp_preview_config_data.ev_value);
	camera_image_setting(CAM_PARAM_BANDING,isp_preview_config_data.banding_freq);
	camera_image_setting(CAM_PARAM_NIGHT_MODE,(kal_uint16)isp_preview_config_data.night_mode);

	ENABLE_VIEW_FINDER_MODE;

}  //ANALOG_TV_SUPPORT

#endif /* YUV_SENSOR_SUPPORT */

#if (defined(YUV_SENSOR_SUPPORT))
	#ifdef __SYNC_LCM_SW_SUPPORT__//turn on sync mode if we support it.
	sync_lcm_enable_mode=KAL_TRUE;
	#endif
	returncode=mpeg4_encode_yuv_process();
#else
	returncode=(kal_uint8)MEDIA_STATUS_OK;
#endif /* YUV_SENSOR_SUPPORT */

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)   

 if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
 {
    #ifdef __SYNC_LCM_SUPPORT__//turn on sync mode if we support it.
	sync_lcm_enable_mode=KAL_TRUE;
	#endif
	mpeg4_encode_yuv_process();
}
#endif  /*ANALOG_TV_SUPPORT*/	
#endif /* YUV_SENSOR_SUPPORT */

	isp_frame_count=0;
	camera_process_stage|=LEAVE_MPEG4_ENCODE;
	return returncode;
#endif /* MP4_CODEC */
#endif
}

kal_uint8 mpeg4_encode_start(void)
{
#if (defined(MP4_CODEC))
   MEDIA_STATUS_CODE result;

   mpeg4_encode_data.resume_enable = KAL_FALSE;
	result = video_encode_setup(&mpeg4_encode_config_data);
   if (result != MEDIA_STATUS_OK)
   {
      camera_process_stage|=LEAVE_MPEG4_ENCODE_START;
      return (kal_uint8)result;
	}
	MPEG4_RECODE_START=KAL_TRUE;

	camera_process_stage|=LEAVE_MPEG4_ENCODE_START;
	return (kal_uint8)MEDIA_STATUS_OK;
#endif
}

kal_uint8 mpeg4_encode_pause(void)
{
#if (defined(MP4_CODEC))
	MPEG4_RECODE_START=KAL_FALSE;
	camera_process_stage|=LEAVE_MPEG4_ENCODE_PAUSE;
	return (kal_uint8)MEDIA_STATUS_OK;
#endif
}

kal_uint8 mpeg4_encode_resume(void)
{
#if (defined(MP4_CODEC))
	kal_uint8 result;

	mpeg4_encode_data.resume_enable = KAL_TRUE;
  	result = video_encode_resume_setup(&mpeg4_encode_config_data);
	if (result != MEDIA_STATUS_OK)
	{
		camera_process_stage|=LEAVE_MPEG4_ENCODE_RESUME;
  		return (kal_uint8)result;
  	}

  	MPEG4_RECODE_START=KAL_TRUE;
  	camera_process_stage|=LEAVE_MPEG4_ENCODE_RESUME;
  	return (kal_uint8)MEDIA_STATUS_OK;
#endif
}
/*************************************************************************
* FUNCTION
*	exit_mpeg4_encode_process
*
* DESCRIPTION
*	This function stops mpeg4 encode
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 exit_mpeg4_encode_process(void)
{
#if (defined(ISP_SUPPORT))
#if (defined(MP4_CODEC))
   kal_uint32 i=0;
   kal_uint32 pixel_count,line_count;

	MMDI_SCENERIO_ID scene_id=SCENARIO_MPEG_ENCODE_ID;

	if (isp_operation_state!=ISP_MPEG4_ENCODE_STATE)
		ASSERT(0);

	isp_enter_exit_process_flag=KAL_TRUE;

	kal_sleep_task(45);
	isp_idle_done_flag=KAL_FALSE;
	ENABLE_CAMERA_IDLE_INT;
	DISABLE_VIEW_FINDER_MODE;
	i=0;
	while(isp_idle_done_flag==KAL_FALSE)
	{
		i++;
		kal_sleep_task(5);
		if(i>9) break;
	}

	DISABLE_CMOS_SESNOR;
	MPEG4_RECODE_START=KAL_FALSE;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	do
	{
		pixel_count=*(volatile unsigned int *) 0x80690428;
		line_count=*(volatile unsigned int *) 0x8069042C;
	}	while ((pixel_count!=0)||(line_count!=0));
#endif
  // if(mpeg4_encode_data.lcd_update==KAL_TRUE)
	lcd_stop_hw_update(isp_preview_config_data.lcd_id);
	release_mpeg4_datapath_mem_flag=KAL_TRUE;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);

	clean_imgprc_coefficient(scene_id);
	IMGPROC_Stop(scene_id);
	IMGPROC_Close(scene_id);

	stop_image_dma(scene_id);
	IMGDMA_Close(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	close_image_data_path(scene_id);
#endif

	isp_digital_zoom_flag=KAL_FALSE;
	isp_operation_state=ISP_STANDBY_STATE;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	intmem_deinit();
	extmem_deinit();
#endif
#if (!defined(YUV_SENSOR_SUPPORT))
	ae_on_off(KAL_FALSE);
	awb_on_off(KAL_FALSE);
#endif

	camera_process_stage|=LEAVE_EXIT_MPEG4_ENCODE;
   #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
      DISABLE_CAMERA_ISP_DONE_INT
      DISABLE_LCD_TRANSFER_COMPLETE_INT
   #endif

	return KAL_TRUE;
#endif /* MP4_CODEC */
#endif
}

kal_uint8 exit_mpeg4_datapath_process(void)
{
#if (defined(ISP_SUPPORT))
#if (defined(MP4_CODEC))
   kal_uint32 i=0;
   kal_uint32 pixel_count,line_count;

	MMDI_SCENERIO_ID scene_id=SCENARIO_MPEG_ENCODE_ID;

	if (isp_operation_state!=ISP_MPEG4_ENCODE_STATE)
		ASSERT(0);

	isp_enter_exit_process_flag=KAL_TRUE;

	kal_sleep_task(45);
	isp_idle_done_flag=KAL_FALSE;
	ENABLE_CAMERA_IDLE_INT;
	DISABLE_VIEW_FINDER_MODE;
	i=0;
	while(isp_idle_done_flag==KAL_FALSE)
	{
		i++;
		kal_sleep_task(5);
		if(i>9) break;
	}

	DISABLE_CMOS_SESNOR;
	MPEG4_RECODE_START=KAL_FALSE;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	do
	{
		pixel_count=*(volatile unsigned int *) 0x80690428;
		line_count=*(volatile unsigned int *) 0x8069042C;
	}	while ((pixel_count!=0)||(line_count!=0));
#endif

	lcd_stop_hw_update(isp_preview_config_data.lcd_id);
	release_mpeg4_datapath_mem_flag=KAL_FALSE;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);

	clean_imgprc_coefficient(scene_id);
	IMGPROC_Stop(scene_id);
	IMGPROC_Close(scene_id);

	stop_image_dma(scene_id);
	IMGDMA_Close(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	close_image_data_path(scene_id);
#endif

	isp_digital_zoom_flag=KAL_FALSE;
	isp_operation_state=ISP_STANDBY_STATE;

#if (!defined(YUV_SENSOR_SUPPORT))
	ae_on_off(KAL_FALSE);
	awb_on_off(KAL_FALSE);
#endif

	camera_process_stage|=LEAVE_EXIT_MPEG4_ENCODE;
	return KAL_TRUE;
#endif /* MP4_CODEC */
#endif
}

kal_bool release_mpeg4_mem(void)
{
	return release_mpeg4_datapath_mem_flag;
}

/*************************************************************************
* FUNCTION
*	fullvideo_process
*
* DESCRIPTION
*	This function starts video full duplex encode process
*
* PARAMETERS
*  type : display type
*  *video_encode_data : encode para
*  *video_decode_para : decode para
*  cb : decode
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(ISP_SUPPORT)&& (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES)||defined(DRV_ISP_6238_SERIES)))
#if (defined(MP4_CODEC))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (!defined(YUV_SENSOR_SUPPORT))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if  (defined(DRV_ISP_6229_SERIES))
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(DRV_ISP_6229_SERIES))
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* YUV_SENSOR_SUPPORT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (!defined(YUV_SENSOR_SUPPORT))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(TV_OUT_SUPPORT))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* TV_OUT_SUPPORT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if  (defined(DRV_ISP_6229_SERIES))
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if  (defined(DRV_ISP_6228_SERIES))
/* under construction !*/
/* under construction !*/
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* YUV_SENSOR_SUPPORT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (!defined(YUV_SENSOR_SUPPORT))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* YUV_SENSOR_SUPPORT */
/* under construction !*/
#if (defined(YUV_SENSOR_SUPPORT))
/* under construction !*/
#endif /* YUV_SENSOR_SUPPORT */
/* under construction !*/
/* under construction !*/
#endif /* MP4_CODEC */
#endif
/* under construction !*/
#endif /*__3G_VIDEO_CALL__*/

/*************************************************************************
* FUNCTION
*	exit_fullvideo_process
*
* DESCRIPTION
*	This function stops video full duplex encode
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
#if (defined(ISP_SUPPORT)&&(defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES)||defined(DRV_ISP_6238_SERIES)))
#if (defined(MP4_CODEC))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (!defined(YUV_SENSOR_SUPPORT))	
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif /* MP4_CODEC */
#endif
/* under construction !*/
#endif /*__3G_VIDEO_CALL__*/

/*************************************************************************
* FUNCTION
*	mjpeg_encode_process
*
* DESCRIPTION
*	This function starts motion jpeg encode process
*
* PARAMETERS
*	mjpeg_data : the parameters for mjpeg encode
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 mjpeg_encode_process(mjpeg_encode_process_struct *mjpeg_data)
{
#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6225_SERIES))
	kal_uint16 temp_grab_size;
	lcd_frame_update_struct lcd_data;
	MMDI_SCENERIO_ID scene_id=SCENARIO_MJPEG_ENCODE_ID;
	kal_uint32 event_group;

	if (sensor_err_check<0)
		return KAL_FALSE;

	if (isp_operation_state!=ISP_STANDBY_STATE)
		ASSERT(0);
		
	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
	kal_mem_cpy(&mjpeg_encode_data, mjpeg_data, sizeof(mjpeg_encode_process_struct));
#if (!defined(YUV_SENSOR_SUPPORT))
	DISABLE_AE_COUNT;
	ae_on_off(KAL_FALSE);
	awb_on_off(KAL_FALSE);
#endif
	DISABLE_CAMERA_IDLE_INT;
	ENABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;

	sensor_config_data.isp_op_mode		= ISP_MJPEG_PREVIEW_MODE;
	sensor_config_data.image_mirror		= mjpeg_encode_data.image_mirror;
	exposure_window.image_target_width	= mjpeg_encode_data.target_width;
	exposure_window.image_target_height	= mjpeg_encode_data.target_height;
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);
	mjpeg_sensor_frame_rate=sensor_config_data.sensor_frame_rate;

	/* accorind the zoom factor to calculate the grab window area */
	isp_digital_zoom_factor=mjpeg_encode_data.zoom_factor;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;

	/* start x should align 4X */
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((mjpeg_encode_data.target_width * exposure_window.exposure_window_height) >=
		 (mjpeg_encode_data.target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * mjpeg_encode_data.target_height/mjpeg_encode_data.target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * mjpeg_encode_data.target_width/mjpeg_encode_data.target_height)&0xFFFE;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
	}

	SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
	SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);

	/* Disable ISP Down Sample */
	DISABLE_VERTICAL_SUB_SAMPLE;
	DISABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE(isp_grab_width);
	SET_VSUB_SRC_SIZE(isp_grab_height);
	SET_HSUB_DST_SIZE(isp_grab_width);
	SET_VSUB_DST_SIZE(isp_grab_height);
	mjpeg_encode_data.source_width=isp_grab_width;
	mjpeg_encode_data.source_height=isp_grab_height;

	intmem_init((kal_uint32 *) mjpeg_encode_data.intmem_start_address,
					mjpeg_encode_data.intmem_size);
	extmem_init((kal_uint32 *) mjpeg_encode_data.extmem_start_address,
					mjpeg_encode_data.extmem_size);

	lcd_data.module_id=LCD_UPDATE_MODULE_MEDIA;
	lcd_data.lcd_id=mjpeg_encode_data.lcd_id;
	lcd_data.fb_update_mode=LCD_HW_TRIGGER_MODE;
	lcd_data.lcm_start_x=mjpeg_encode_data.lcm_start_x;
	lcd_data.lcm_start_y=mjpeg_encode_data.lcm_start_y;
	lcd_data.lcm_end_x=mjpeg_encode_data.lcm_end_x;
	lcd_data.lcm_end_y=mjpeg_encode_data.lcm_end_y;
	lcd_data.roi_offset_x=mjpeg_encode_data.roi_offset_x;
	lcd_data.roi_offset_y=mjpeg_encode_data.roi_offset_y;
	lcd_data.update_layer=mjpeg_encode_data.update_layer;
	lcd_data.hw_update_layer=mjpeg_encode_data.hw_update_layer;
	lcd_data.block_mode_flag=KAL_TRUE;
	lcd_data.lcd_block_mode_cb=NULL;
	lcd_data.memory_output=KAL_FALSE;

	config_pixel_resizer(scene_id);

	isp_operation_state=ISP_MJPEG_ENCODE_STATE;

	camera_image_setting(CAM_PARAM_EFFECT,mjpeg_encode_data.image_effect);
	if(mjpeg_encode_data.image_effect==0)
	{
		camera_image_setting(CAM_PARAM_CONTRAST,mjpeg_encode_data.contrast_level);
		camera_image_setting(CAM_PARAM_BRIGHTNESS,mjpeg_encode_data.brightness_level);
		camera_image_setting(CAM_PARAM_HUE,mjpeg_encode_data.hue_value);
		camera_image_setting(CAM_PARAM_SATURATION,mjpeg_encode_data.saturation_value);
	}
	camera_image_setting(CAM_PARAM_WB,mjpeg_encode_data.wb_mode);
	camera_image_setting(CAM_PARAM_EXPOSURE,mjpeg_encode_data.ev_value);
	camera_image_setting(CAM_PARAM_BANDING,mjpeg_encode_data.banding_freq);
	camera_image_setting(CAM_PARAM_NIGHT_MODE,mjpeg_encode_data.night_mode);

	// Wait first frame for preview stable
	wait_first_frame_flag = KAL_TRUE;
	isp_preview_frame = 0;

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	SET_CAMERA_PREVIEW_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;

  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
    	                    &event_group,KAL_SUSPEND);

	if(mjpeg_encode_data.lcd_update==KAL_TRUE)
		lcd_fb_update(&lcd_data);
	else
	{
		lcd_data.update_layer&=~lcd_data.hw_update_layer;		
		lcd_fb_update(&lcd_data);		
	}	
				
#endif /* MT6225 */

	isp_frame_count=0;
	camera_process_stage|=LEAVE_MJPEG_ENCODE;
	return KAL_TRUE;
}	/* mjpeg_encode_process() */

kal_uint8 mjpeg_encode_start(void)
{
#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6225_SERIES))
	kal_int32 frame_rate=0;

	sensor_config_data.isp_op_mode=ISP_MJPEG_ENCODE_MODE;
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);
	//mjpeg_sensor_frame_rate=sensor_config_data.sensor_frame_rate;

	frame_rate=32768*10/(time_tick_buff[(time_tick-2+10)%10]-time_tick_buff[(time_tick-3+10)%10]);
	if(frame_rate<0)
		frame_rate=32768*10/(time_tick_buff[(time_tick-3+10)%10]-time_tick_buff[(time_tick-4+10)%10]);

	mjpeg_sensor_frame_rate=(kal_uint32)frame_rate;
	mjpeg_encode_enable=KAL_TRUE;

	camera_process_stage|=LEAVE_MJPEG_ENCODE_START;
#endif /* MT6225 */
}	/* mjpeg_encode_start() */

kal_uint8 mjpeg_encode_pause(void)
{
#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6225_SERIES))
	mjpeg_encode_enable=KAL_FALSE;
	camera_process_stage|=LEAVE_MJPEG_ENCODE_PAUSE;
#endif /* MT6225 */
}	/* mjpeg_encode_pause() */

kal_uint8 mjpeg_encode_resume(void)
{
#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6225_SERIES))
	mjpeg_encode_enable=KAL_TRUE;
	camera_process_stage|=LEAVE_MJPEG_ENCODE_RESUME;
#endif /* MT6225 */
}	/* mjpeg_encode_resume() */

kal_bool mjpeg_is_encode_enable(void)
{
#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6225_SERIES))
   return mjpeg_encode_enable;
#endif /* MT6225 */
}

kal_uint8 exit_mjpeg_encode_process(void)
{
#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6225_SERIES))
   kal_uint32 i=0;
	MMDI_SCENERIO_ID scene_id=SCENARIO_MJPEG_ENCODE_ID;

	if (isp_operation_state!=ISP_MJPEG_ENCODE_STATE)
		ASSERT(0);

	isp_idle_done_flag=KAL_FALSE;
	ENABLE_CAMERA_IDLE_INT;
	DISABLE_VIEW_FINDER_MODE;
	i=0;
	while(isp_idle_done_flag==KAL_FALSE)
	{
		i++;
		kal_sleep_task(5);
		if(i>9) break;
	}

	DISABLE_CMOS_SESNOR;
	lcd_stop_hw_update(mjpeg_encode_data.lcd_id);
   RESZ_Stop(scene_id);
   RESZ_Close(scene_id);

	mjpeg_encode_enable=KAL_FALSE;
	isp_digital_zoom_flag=KAL_FALSE;
	isp_operation_state=ISP_STANDBY_STATE;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	intmem_deinit();
	extmem_deinit();
#endif

	camera_process_stage|=LEAVE_EXIT_MJPEG_ENCODE;
	return KAL_TRUE;
#endif /* MT6225 */
}	/* exit_mjpeg_encode_process() */

kal_uint8 get_mjpeg_frame_rate(void)
{
#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6225_SERIES))
	return mjpeg_sensor_frame_rate;
#endif /* MT6225 */
}	/* get_mjpeg_frame_rate() */

#endif /* MT6219 */