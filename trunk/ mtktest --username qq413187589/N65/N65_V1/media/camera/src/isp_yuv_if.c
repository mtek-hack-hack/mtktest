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
 *   isp_device_if.c
 *
 * Project:
 * --------
 *   MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   These are interface with ISP for YUV sensor
 *
 * Author:
 * -------
 *
 *   Jeff Yang (mtk00747)
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

#include "kal_release.h"
#include "drv_features.h"

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
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
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
#if (defined(YUV_SENSOR_SUPPORT))
#include "isp_yuv_if.h"
#endif

#include "med_status.h"
#include "rtc_sw.h"
#include "bmd.h"

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
extern camera_preview_data_path_struct			ipp_preview_data;
extern camera_capture_jpeg_data_path_struct 	ipp_capture_jpeg_data;
extern camera_capture_mem_data_path_struct   ipp_capture_mem_data;
extern video_encode_data_path_struct			ipp_video_encode_data;
#endif
extern kal_eventgrpid camera_isp_event_id;
extern kal_bool wait_first_frame_flag;
extern kal_uint8 isp_preview_frame;
#if (defined(AF_SUPPORT))
extern kal_uint8 yuv_af_check_count;
#endif
#if (defined(DRV_ISP_6225_SERIES)&&defined(YUV_SENSOR_SUPPORT))
	jpeg_encode_process_struct sw_jpeg_encode_config_data;
#endif

/*************************************************************************
* FUNCTION
*	camera_yuv_preview_process
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
kal_uint8 camera_yuv_preview_process(void)
{
#if (defined(YUV_SENSOR_SUPPORT))
	kal_uint16 temp_grab_size;
	lcd_frame_update_struct lcd_data;
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_PREVIEW_ID;
	kal_uint32 event_group;

	if (sensor_err_check<0)
		return KAL_FALSE;

	if (isp_operation_state!=ISP_STANDBY_STATE)
		ASSERT(0);
		
	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
	
#if (defined(AF_SUPPORT))
	if(isp_preview_config_data.continue_capture==0)
		camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
#endif

	DISABLE_AE_COUNT;
	DISABLE_CAMERA_IDLE_INT;
	ENABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;

	sensor_config_data.isp_op_mode=ISP_PREVIEW_MODE;
	sensor_config_data.image_mirror		= isp_preview_config_data.image_mirror;
	sensor_config_data.frame_rate			= isp_preview_config_data.frame_rate;
	exposure_window.image_target_width	= isp_preview_config_data.target_width;
	exposure_window.image_target_height	= isp_preview_config_data.target_height;
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);

	/* accorind the zoom factor to calculate the grab window area */
	isp_digital_zoom_factor=isp_preview_config_data.zoom_factor;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;

	/* start x should align 4X */
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((isp_preview_config_data.target_width * exposure_window.exposure_window_height) >=
		 (isp_preview_config_data.target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * isp_preview_config_data.target_height/isp_preview_config_data.target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * isp_preview_config_data.target_width/isp_preview_config_data.target_height)&0xFFFE;
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
	isp_preview_config_data.source_width=isp_grab_width;
	isp_preview_config_data.source_height=isp_grab_height;

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ipp_preview_data.image_src_width		= isp_preview_config_data.source_width;
	ipp_preview_data.image_src_height	= isp_preview_config_data.source_height;
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
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
	lcd_data.roi_background_color=isp_preview_config_data.roi_background_color;
#endif

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	lcd_data.memory_output=KAL_FALSE;
#endif

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	/* Prepare LCD Data */
	lcd_data.hw_trigger_src = LCD_HW_TRIGGER_IBW2;
	lcd_data.memory_output=KAL_FALSE;

#if (defined(TV_OUT_SUPPORT))
	if ((isp_preview_config_data.tv_output==KAL_TRUE)&&
		 ((tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE1)||
		  (tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE4)))
	{
		lcd_data.tv_output=KAL_TRUE;
		lcd_data.tv_output_width=isp_preview_config_data.tv_output_width;
		lcd_data.tv_output_height=isp_preview_config_data.tv_output_height;
		lcd_data.tv_output_offset_x=isp_preview_config_data.tv_output_offset_x;
		lcd_data.tv_output_offset_y=isp_preview_config_data.tv_output_offset_y;
		lcd_data.tv_output_frame_buffer1_address=isp_preview_config_data.tv_output_buffer1_address;
		lcd_data.tv_output_frame_buffer2_address=isp_preview_config_data.tv_output_buffer2_address;
		lcd_data.tv_output_frame_buffer_size=isp_preview_config_data.tv_output_buffer_size;

		ipp_preview_data.tv_output=KAL_FALSE;
	}
	else
	{
		lcd_data.tv_output=KAL_FALSE;
	}
#endif	/* TV_OUT_SUPPORT */
#endif

#if (defined(DRV_ISP_6227_SERIES))
	config_image_dma(scene_id,isp_preview_config_data.target_width,isp_preview_config_data.target_height);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	open_image_data_path(scene_id);
	config_camera_preview_data_path(scene_id,&ipp_preview_data);
#elif (defined(DRV_ISP_6225_SERIES))

	config_pixel_resizer(scene_id);
#endif

	isp_operation_state=ISP_PREVIEW_STATE;

	/* camera operation setting */
	if(isp_preview_config_data.continue_capture==0)
	{
		camera_yuv_operation_setting(CAM_DSC_MODE,isp_preview_config_data.dsc_mode);
		camera_yuv_operation_setting(CAM_AE_METERING,isp_preview_config_data.ae_metering_mode);
		camera_yuv_operation_setting(CAM_AF_MODE,isp_preview_config_data.af_mode);
		camera_yuv_operation_setting(CAM_AF_METERING,isp_preview_config_data.af_metering_mode);
		camera_yuv_operation_setting(CAM_FLASH_MODE,isp_preview_config_data.flash_mode);
	}

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
	camera_image_setting(CAM_PARAM_NIGHT_MODE,isp_preview_config_data.night_mode);

	// Wait first frame for preview stable
	wait_first_frame_flag = KAL_TRUE;
	isp_preview_frame = 0;

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	SET_CAMERA_PREVIEW_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;

  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
    	                    &event_group,KAL_SUSPEND);

	if(isp_preview_config_data.lcd_update==KAL_TRUE)
		lcd_fb_update(&lcd_data);
#endif
	return KAL_TRUE;
}	/* camera_yuv_preview_process() */

/*************************************************************************
* FUNCTION
*	camera_yuv_capture_jpeg_process
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
kal_uint32 camera_yuv_capture_jpeg_process(void)
{
	kal_uint32 jpeg_file_size = 1;
#if (defined(YUV_SENSOR_SUPPORT))
	volatile kal_uint8 i;
	kal_uint8 capture_retry_flag=0;
	kal_uint16 temp_grab_size;
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_JPEG_ID;
	kal_uint32 event_group;

#if (defined(EXIF_SUPPORT))
	exif_cam_para_struct* exif_cam_para_ptr;
 	exif_MTK_para_struct* exif_MTK_para_ptr;
#if (defined(DRV_ISP_6227_SERIES))
 	kal_uint16	exif_header_length;
 	kal_uint16	exif_padding_length=0;
#endif
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	lcd_frame_update_struct lcd_data;
	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
#endif

	ENABLE_CMOS_SESNOR;
   DISABLE_VIEW_FINDER_MODE;
   DISABLE_CAMERA_IDLE_INT;

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	intmem_init((kal_uint32 *) isp_capture_jpeg_data.intmem_start_address,
					isp_capture_jpeg_data.intmem_size);
	extmem_init((kal_uint32 *) isp_capture_jpeg_data.extmem_start_address,
					isp_capture_jpeg_data.extmem_size);
#endif

	/* accoring the zoom factor to calculate the grab window area */
	exposure_window.image_target_width=isp_capture_jpeg_data.target_width;
	exposure_window.image_target_height=isp_capture_jpeg_data.target_height;
	exposure_window.digital_zoom_factor=isp_digital_zoom_factor;

	sensor_config_data.enable_shutter_tansfer=KAL_FALSE;
	sensor_config_data.meta_mode=KAL_FALSE;
	sensor_config_data.enable_flashlight_tansfer=KAL_FALSE;

	image_sensor_func->sensor_capture_setting(&exposure_window,&sensor_config_data);

	/* accoring the zoom factor to calculate the grab window area */
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((isp_capture_jpeg_data.target_width * exposure_window.exposure_window_height) >=
		 (isp_capture_jpeg_data.target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * isp_capture_jpeg_data.target_height/isp_capture_jpeg_data.target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * isp_capture_jpeg_data.target_width/isp_capture_jpeg_data.target_height)&0xFFFE;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
	}

	SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
	SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
	isp_capture_jpeg_data.source_width=isp_grab_width;
	isp_capture_jpeg_data.source_height=isp_grab_height;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ipp_capture_jpeg_data.image_src_width	=	isp_capture_jpeg_data.source_width;
	ipp_capture_jpeg_data.image_src_height	=	isp_capture_jpeg_data.source_height;
#endif

	DISABLE_VERTICAL_SUB_SAMPLE;
	DISABLE_HORIZONTAL_SUB_SAMPLE;
#if (defined(DRV_ISP_6227_SERIES))
	jpeg_codec_power_up();
#endif

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	ENABLE_CAMERA_IDLE_INT;
	SET_CAMERA_CAPTURE_MODE;
	SET_CAMERA_FRAME_RATE(0);
	for(i=0;i<camera_oper_data.capture_delay_frame;i++)
	{
	   DISABLE_VIEW_FINDER_MODE;
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;

   	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
      	                    &event_group,KAL_SUSPEND);
   }
   DISABLE_VIEW_FINDER_MODE;
   DISABLE_CAMERA_IDLE_INT;

#if (defined(EXIF_SUPPORT))
   /* config exif header */
   exif_cam_para_ptr=exif_get_cam_para_struct();
   exif_MTK_para_ptr=exif_get_MTK_para_struct();
#endif

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	open_image_data_path(scene_id);
	config_camera_capture_jpeg_data_path(scene_id,&ipp_capture_jpeg_data);

	if (isp_capture_jpeg_data.display==KAL_TRUE)
	{
		lcd_data.module_id			=	LCD_UPDATE_MODULE_MEDIA;
		lcd_data.lcd_id				=	isp_capture_jpeg_data.lcd_id;
		lcd_data.block_mode_flag	=	KAL_TRUE;
		lcd_data.fb_update_mode		=	LCD_HW_TRIGGER_MODE;
		lcd_data.lcm_start_x			=	isp_capture_jpeg_data.lcm_start_x;
		lcd_data.lcm_start_y			=	isp_capture_jpeg_data.lcm_start_y;
		lcd_data.lcm_end_x			=	isp_capture_jpeg_data.lcm_end_x;
		lcd_data.lcm_end_y			=	isp_capture_jpeg_data.lcm_end_y;
		lcd_data.roi_offset_x		=	isp_capture_jpeg_data.roi_offset_x;
		lcd_data.roi_offset_y		=	isp_capture_jpeg_data.roi_offset_y;
		lcd_data.update_layer		=	isp_capture_jpeg_data.update_layer;
		lcd_data.hw_update_layer	=	isp_capture_jpeg_data.hw_update_layer;
		lcd_data.hw_trigger_src		=	LCD_HW_TRIGGER_IBW2;

		isp_capture_jpeg_data.display=KAL_TRUE;

		lcd_data.roi_background_color	=	0xFFFFFF;
		lcd_data.memory_output			=	KAL_FALSE;
		lcd_data.block_mode_flag		=	KAL_TRUE;
		lcd_data.lcd_block_mode_cb		=	NULL;
#if (defined(TV_OUT_SUPPORT))
		if (isp_capture_jpeg_data.tv_output==KAL_TRUE)
		{
			lcd_data.tv_output								=	KAL_TRUE;
			lcd_data.tv_output_width						=	isp_capture_jpeg_data.tv_output_width;
			lcd_data.tv_output_height						=	isp_capture_jpeg_data.tv_output_height;
			lcd_data.tv_output_offset_x					=	isp_capture_jpeg_data.tv_output_offset_x;
			lcd_data.tv_output_offset_y					=	isp_capture_jpeg_data.tv_output_offset_y;
			lcd_data.tv_output_frame_buffer1_address	=	isp_capture_jpeg_data.tv_output_buffer1_address;
			lcd_data.tv_output_frame_buffer2_address	=	isp_capture_jpeg_data.tv_output_buffer2_address;
			lcd_data.tv_output_frame_buffer_size		=	isp_capture_jpeg_data.tv_output_buffer_size;
		}
		else
		{
			lcd_data.tv_output=KAL_FALSE;
		}
#endif	/* TV_OUT_SUPPORT */
		lcd_fb_update(&lcd_data);
	}

	isp_operation_state=ISP_CAPTURE_JPEG_STATE;

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
	camera_image_setting(CAM_PARAM_NIGHT_MODE,isp_preview_config_data.night_mode);

        // Support burst capture function for MT6228+YUV
	if (isp_capture_jpeg_data.snapshot_number==1)
	{
		SET_CAMERA_CAPTURE_MODE;
	}
	else if (isp_capture_jpeg_data.snapshot_number>1)
	{
		SET_CAMERA_PREVIEW_MODE;
	}
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;
	//return;

#elif (defined(DRV_ISP_6227_SERIES))
#if (defined(EXIF_SUPPORT))
/* calculating exif header size and shift the start addres of jpeg encoder*/
	exif_header_length=exif_get_custom_IFD_and_buffer_size(2);

	if(exif_header_length>0)
	{
		jpeg_encode_config_data.jpeg_file_start_address+=exif_header_length;

		if(jpeg_encode_config_data.jpeg_file_start_address % 4 !=0)
		{
			jpeg_encode_config_data.jpeg_file_start_address=((jpeg_encode_config_data.jpeg_file_start_address+4)>>2)<<2;
		}

		exif_padding_length=jpeg_encode_config_data.jpeg_file_start_address-
									(isp_capture_jpeg_data.target_buffer_start_address+exif_header_length);
		jpeg_encode_config_data.jpeg_file_buffer_size-=(jpeg_encode_config_data.jpeg_file_start_address-
																		isp_capture_jpeg_data.target_buffer_start_address);
	}
#endif
   do
   {
	   if(capture_retry_flag==1)
	   {
	   	ENABLE_CMOS_SESNOR;
	   	jpeg_encode_config_data.image_quality=JPEG_ENCODER_POOR_QUALITY;
	  		intmem_init((kal_uint32 *) isp_capture_jpeg_data.intmem_start_address,
						isp_capture_jpeg_data.intmem_size);
			extmem_init((kal_uint32 *) isp_capture_jpeg_data.extmem_start_address,
						isp_capture_jpeg_data.extmem_size);
	   	capture_retry_flag++;
	   }

		mp4_reset();
		config_image_dma(scene_id,jpeg_encode_config_data.image_width,jpeg_encode_config_data.image_height);
		config_jpeg_encoder(&jpeg_encode_config_data);
		config_image_processor(scene_id);
		config_pixel_resizer(scene_id);

		isp_operation_state=ISP_CAPTURE_JPEG_STATE;

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
		camera_image_setting(CAM_PARAM_NIGHT_MODE,isp_preview_config_data.night_mode);

		jpeg_encoder_encode_result=0;
		SET_CAMERA_CAPTURE_MODE;
		SET_CAMERA_FRAME_RATE(0);
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
					*((volatile unsigned int *) 0x80610004) = 0x60000;
					*((volatile unsigned int *) 0x80610004) = 0x6;
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
		*((kal_uint8 *)jpeg_encode_config_data.jpeg_file_start_address)=0xFF;
		*((kal_uint8 *)jpeg_encode_config_data.jpeg_file_start_address+1)=0xD8;
		exif_Fillin_Header((kal_uint8 *)jpeg_encode_config_data.jpeg_file_start_address,2);

		/* padding bytes to cover SOI marker generated by JPEG encoder */
		for(i=0;i<exif_padding_length;i++)
			*((kal_uint8 *)(jpeg_encode_config_data.jpeg_file_start_address+1-i))=0x00;

		jpeg_file_size+=(jpeg_encode_config_data.jpeg_file_start_address-jpeg_encode_config_data.jpeg_file_start_address);
	}
#endif

	jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;
	isp_operation_state=ISP_STANDBY_STATE;

	jpeg_codec_power_down();

#elif (defined(DRV_ISP_6225_SERIES))
	sw_jpeg_encode_config_data.image_width=isp_capture_jpeg_data.target_width;
	sw_jpeg_encode_config_data.image_height=isp_capture_jpeg_data.target_height;
	sw_jpeg_encode_config_data.image_quality=isp_capture_jpeg_data.image_quality;
	sw_jpeg_encode_config_data.jpeg_file_start_address=isp_capture_jpeg_data.target_buffer_start_address;
	sw_jpeg_encode_config_data.jpeg_file_buffer_size=isp_capture_jpeg_data.target_buffer_size;
	sw_jpeg_encode_config_data.intmem_start_address=isp_capture_jpeg_data.intmem_start_address;
	sw_jpeg_encode_config_data.intmem_size=isp_capture_jpeg_data.intmem_size;

	sw_jpeg_encode_config_data.input_type=IMAGE_FORMAT_YUV420;
	if(isp_capture_jpeg_data.jpeg_gray_mode==0)
		sw_jpeg_encode_config_data.output_type=IMAGE_FORMAT_YUV420;
	else
		sw_jpeg_encode_config_data.output_type=IMAGE_FORMAT_GRAY;
	sw_jpeg_encode_config_data.jpeg_yuv_data[0]=(kal_uint8 *)isp_capture_jpeg_data.y_address;
	sw_jpeg_encode_config_data.jpeg_yuv_data[1]=(kal_uint8 *)isp_capture_jpeg_data.u_address;
	sw_jpeg_encode_config_data.jpeg_yuv_data[2]=(kal_uint8 *)isp_capture_jpeg_data.v_address;
	sw_jpeg_encode_config_data.jpeg_yuv_size[0]=isp_capture_jpeg_data.y_size;
	sw_jpeg_encode_config_data.jpeg_yuv_size[1]=isp_capture_jpeg_data.u_size;
	sw_jpeg_encode_config_data.jpeg_yuv_size[2]=isp_capture_jpeg_data.v_size;

	#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
	sw_jpeg_encode_config_data.memory_output=isp_capture_jpeg_data.memory_output;						/* output another image for LCD output */
	sw_jpeg_encode_config_data.memory_output_type=isp_capture_jpeg_data.memory_output_type;
	sw_jpeg_encode_config_data.memory_output_width=isp_capture_jpeg_data.memory_output_width;				/* image width for LCD output */
	sw_jpeg_encode_config_data.memory_output_height=isp_capture_jpeg_data.memory_output_height;			/* image height for LCD output */
	sw_jpeg_encode_config_data.memory_output_buffer_address=isp_capture_jpeg_data.memory_output_buffer_address;
	sw_jpeg_encode_config_data.memory_output_buffer_size=isp_capture_jpeg_data.memory_output_buffer_size;
	#endif
	
	config_pixel_resizer(scene_id);
	isp_operation_state=ISP_CAPTURE_JPEG_STATE;

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
	camera_image_setting(CAM_PARAM_NIGHT_MODE,isp_preview_config_data.night_mode);

	SET_CAMERA_CAPTURE_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;

	while(RESZ_CheckBusy());

	intmem_deinit();
	extmem_deinit();

	jpeg_file_size=jpeg_encode_process(&sw_jpeg_encode_config_data);

	DISABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;

	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);

	isp_operation_state=ISP_STANDBY_STATE;
#endif	/* (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES)) */
#endif	/* (defined(YUV_SENSOR_SUPPORT)) */
	return jpeg_file_size;
}

/*************************************************************************
* FUNCTION
*	camera_yuv_captuer_mem_process
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
kal_uint8 camera_yuv_capture_mem_process(void)
{
#if (defined(YUV_SENSOR_SUPPORT))
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_MEM_ID;
	lcd_frame_update_to_mem_struct lcd_data;
	kal_uint32 event_group;
	kal_uint16 temp_grab_size;
	kal_uint8 i;
#if (defined(EXIF_SUPPORT))
	exif_cam_para_struct* exif_cam_para_ptr;
 	exif_MTK_para_struct* exif_MTK_para_ptr;
#endif
	
	memset(&lcd_data, 0, sizeof(lcd_frame_update_to_mem_struct));	//initial lcd_data
	
	ENABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;

	exposure_window.image_target_width=isp_capture_mem_data.target_width;
	exposure_window.image_target_height=isp_capture_mem_data.target_height;
	exposure_window.digital_zoom_factor=isp_digital_zoom_factor;

	sensor_config_data.enable_shutter_tansfer=KAL_FALSE;
	sensor_config_data.meta_mode=KAL_FALSE;
	sensor_config_data.enable_flashlight_tansfer=KAL_FALSE;

	image_sensor_func->sensor_capture_setting(&exposure_window,&sensor_config_data);

	/* accoring the zoom factor to calculate the grab window area */
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((isp_capture_mem_data.target_width * exposure_window.exposure_window_height) >=
		 (isp_capture_mem_data.target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * isp_capture_mem_data.target_height/isp_capture_mem_data.target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * isp_capture_mem_data.target_width/isp_capture_mem_data.target_height)&0xFFFE;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
	}

	SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
	SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
	isp_capture_mem_data.source_width=isp_grab_width;
	isp_capture_mem_data.source_height=isp_grab_height;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ipp_capture_mem_data.image_src_width	=	isp_capture_mem_data.source_width;
	ipp_capture_mem_data.image_src_height	=	isp_capture_mem_data.source_height;
#endif
	DISABLE_VERTICAL_SUB_SAMPLE;
	DISABLE_HORIZONTAL_SUB_SAMPLE;

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	ENABLE_CAMERA_IDLE_INT;
	SET_CAMERA_CAPTURE_MODE;
	SET_CAMERA_FRAME_RATE(0);
	for(i=0;i<camera_oper_data.capture_delay_frame;i++)
	{
	   DISABLE_VIEW_FINDER_MODE;
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;

	   kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
	                          &event_group,KAL_SUSPEND);
	}
	DISABLE_VIEW_FINDER_MODE;
	DISABLE_CAMERA_IDLE_INT;

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	intmem_init((kal_uint32 *) isp_capture_mem_data.intmem_start_address,
					isp_capture_mem_data.intmem_size);
	extmem_init((kal_uint32 *) isp_capture_mem_data.extmem_start_address,
					isp_capture_mem_data.extmem_size);
#endif

	lcd_data.fb_update_mode			=	LCD_HW_TRIGGER_MODE;
	lcd_data.block_mode				=	isp_capture_mem_data.block_mode;
	lcd_data.dest_block_width		=	isp_capture_mem_data.dest_block_width;
	lcd_data.dest_buffer_address	=	isp_capture_mem_data.dest_buffer_address;
	lcd_data.dest_buffer_size		=	isp_capture_mem_data.dest_buffer_size;
	lcd_data.roi_offset_x			=	isp_capture_mem_data.roi_offset_x;
	lcd_data.roi_offset_y			=	isp_capture_mem_data.roi_offset_y;
	lcd_data.roi_width				=	isp_capture_mem_data.roi_width;
	lcd_data.roi_height				=	isp_capture_mem_data.roi_height;
	lcd_data.update_layer			=	isp_capture_mem_data.update_layer;
	lcd_data.hw_update_layer		=	isp_capture_mem_data.hw_update_layer;
	lcd_data.roi_background_color	=	isp_capture_mem_data.roi_background_color;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	lcd_data.hw_trigger_src			=	LCD_HW_TRIGGER_IBW2;
	lcd_data.memory_data_format	=	isp_capture_mem_data.memory_data_format;
#endif
   #if (!defined(DRV_ISP_6225_SERIES))
	lcd_fb_update_to_memory(&lcd_data);
	#endif

#if (defined(EXIF_SUPPORT))
   /* config exif header */
   exif_cam_para_ptr=exif_get_cam_para_struct();
   exif_MTK_para_ptr=exif_get_MTK_para_struct();
   exif_update_cam_para_struct(exif_cam_para_ptr);
#endif

#if (defined(DRV_ISP_6227_SERIES))
	config_image_dma(scene_id,isp_capture_mem_data.target_width,isp_capture_mem_data.target_height);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	open_image_data_path(scene_id);
	config_camera_capture_mem_data_path(scene_id,&ipp_capture_mem_data);
#elif (defined(DRV_ISP_6225_SERIES))
	config_pixel_resizer(scene_id);
#endif

	isp_operation_state=ISP_CAPTURE_MEM_STATE;

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
	camera_image_setting(CAM_PARAM_NIGHT_MODE,isp_preview_config_data.night_mode);

	ENABLE_VIEW_FINDER_MODE;

#if (defined(DRV_ISP_6225_SERIES))
	   /*check resizer is busy*/
   while(RESZ_CheckBusy());
   /*use LCD to output to memory*/
   lcd_data.fb_update_mode =LCD_HW_TRIGGER_MODE;
   LCD_config_fw_layer_address(isp_capture_mem_data.imgdma_buffer_address);
   lcd_fb_update_to_memory(&lcd_data);
#else
   kal_retrieve_eg_events(lcd_event_id,LCD_TRANSFER_COMPLETE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);
#endif

	kal_sleep_task(15);
	DISABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;
	lcd_stop_hw_update(current_update_lcd);
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
#elif (defined(DRV_ISP_6225_SERIES))
	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);
#endif

	isp_operation_state=ISP_STANDBY_STATE;

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	intmem_deinit();
	extmem_deinit();
#endif

#endif
	return KAL_TRUE;
}	/* camera_yuv_capture_mem_process() */

/*************************************************************************
* FUNCTION
*	mpeg4_encode_yuv_process
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
extern void video_enc_dma_lisr(void);
#endif
kal_uint8 mpeg4_encode_yuv_process(void)
{
#if (defined(YUV_SENSOR_SUPPORT)&&!defined(DRV_ISP_6225_SERIES))
	kal_uint16 temp_grab_size;
	MMDI_SCENERIO_ID scene_id=SCENARIO_MPEG_ENCODE_ID;
	lcd_frame_update_struct lcd_data;
	kal_uint32 video_buffer_size;
	volatile kal_uint8 i;

	isp_enter_exit_process_flag=KAL_FALSE;

	if (sensor_err_check<0)
		return (kal_uint8)SENSOR_ERROR;
	
	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
	
	DISABLE_CAMERA_IDLE_INT;
	ENABLE_CMOS_SESNOR;

	sensor_config_data.isp_op_mode=ISP_MPEG4_PREVIEW_MODE;
	sensor_config_data.image_mirror=mpeg4_encode_data.image_mirror;
	sensor_config_data.frame_rate=mpeg4_encode_data.frame_rate;
	exposure_window.image_target_width	= mpeg4_encode_data.mpeg4_image_width;
	exposure_window.image_target_height	= mpeg4_encode_data.mpeg4_image_height;
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);
       #if defined(ANALOG_TV_SUPPORT)&&defined(__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__)
         if(mmi_get_analog_tv_current_state()==KAL_TRUE)
         {
             if((mmi_analog_tv_is_full_screen()==1)&&(mmi_analog_tv_is_320_240_screen()==0)) //400*420
             {
             isp_grab_start_x=exposure_window.grab_start_x;  
	     isp_grab_start_y=exposure_window.grab_start_y;
	     isp_grab_width=exposure_window.exposure_window_width;
	     isp_grab_height=exposure_window.exposure_window_height;
             }
	     else
	     {
	/* accorind the zoom factor to calculate the grab window area */
	isp_digital_zoom_factor=isp_preview_config_data.zoom_factor;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	
	/* start x should align 4X */
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

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
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
	}
        }
          }
	 else
        {
        #endif /*__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__*/	 	

	/* accorind the zoom factor to calculate the grab window area */
	isp_digital_zoom_factor=isp_preview_config_data.zoom_factor;
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;

	/* start x should align 4X */
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

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
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
	}
#if defined(ANALOG_TV_SUPPORT)&&defined(__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__)
}
#endif

	SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
	SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);

	/* Disable ISP Down Sample */
	DISABLE_VERTICAL_SUB_SAMPLE;
	DISABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE(isp_grab_width);
	SET_VSUB_SRC_SIZE(isp_grab_height);
	SET_HSUB_DST_SIZE(isp_grab_width);
	SET_VSUB_DST_SIZE(isp_grab_height);
	mpeg4_encode_data.image_source_width=isp_grab_width;
	mpeg4_encode_data.image_source_height=isp_grab_height;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ipp_video_encode_data.image_src_width	=	mpeg4_encode_data.image_source_width;
	ipp_video_encode_data.image_src_height	=	mpeg4_encode_data.image_source_height;
#endif

#if (defined(DRV_ISP_6227_SERIES))
	intmem_init((kal_uint32 *) mpeg4_encode_data.intmem_start_address,
					mpeg4_encode_data.intmem_size);
	extmem_init((kal_uint32 *) mpeg4_encode_data.extmem_start_address,
					mpeg4_encode_data.extmem_size);
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

	lcd_data.lcm_start_x				=	mpeg4_encode_data.lcm_start_x;
	lcd_data.lcm_start_y				=	mpeg4_encode_data.lcm_start_y;
	lcd_data.lcm_end_x				=	mpeg4_encode_data.lcm_end_x;
	lcd_data.lcm_end_y				=	mpeg4_encode_data.lcm_end_y;
	lcd_data.roi_offset_x			=	mpeg4_encode_data.roi_offset_x;
	lcd_data.roi_offset_y			=	mpeg4_encode_data.roi_offset_y;
	lcd_data.update_layer			=	mpeg4_encode_data.update_layer;
	lcd_data.hw_update_layer		=	mpeg4_encode_data.hw_update_layer;
	lcd_data.roi_background_color	=	mpeg4_encode_data.roi_background_color;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	lcd_data.hw_trigger_src 		= 	LCD_HW_TRIGGER_IBW2;
	lcd_data.memory_output			=	KAL_FALSE;
	lcd_data.block_mode_flag		=	KAL_TRUE;
	lcd_data.lcd_block_mode_cb		=	NULL;

#if (defined(TV_OUT_SUPPORT))
	if ((mpeg4_encode_data.tv_output==KAL_TRUE)&&(tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE1))
	{
		lcd_data.tv_output								=	KAL_TRUE;
		lcd_data.tv_output_width						=	mpeg4_encode_data.tv_output_width;
		lcd_data.tv_output_height						=	mpeg4_encode_data.tv_output_height;
		lcd_data.tv_output_offset_x					=	mpeg4_encode_data.tv_output_offset_x;
		lcd_data.tv_output_offset_y					=	mpeg4_encode_data.tv_output_offset_y;
		lcd_data.tv_output_frame_buffer1_address	=	mpeg4_encode_data.tv_output_buffer1_address;
		lcd_data.tv_output_frame_buffer2_address	=	mpeg4_encode_data.tv_output_buffer2_address;
		lcd_data.tv_output_frame_buffer_size		=	mpeg4_encode_data.tv_output_buffer_size;

		ipp_video_encode_data.tv_output=KAL_FALSE;
	}
	else
	{
		lcd_data.tv_output=KAL_FALSE;
	}
#endif	/* TV_OUT_SUPPORT */
#endif

	isp_operation_state=ISP_MPEG4_ENCODE_STATE;

	SET_CAMERA_PREVIEW_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;


	ENABLE_CAMERA_IDLE_INT;
	isp_idle_done_flag=KAL_FALSE;
	DISABLE_VIEW_FINDER_MODE;
	i=0;
	kal_sleep_task(25);
	while(isp_idle_done_flag==KAL_FALSE)
	{
		i++;
		kal_sleep_task(10);
		if(i>5) break;
	}
	DISABLE_CAMERA_IDLE_INT;

	if(mpeg4_encode_data.lcd_update==KAL_TRUE)
		lcd_fb_update(&lcd_data);

#if (defined(DRV_ISP_6227_SERIES))
	video_buffer_size=mpeg4_encode_data.mpeg4_image_width * mpeg4_encode_data.mpeg4_image_height * 3;
	video_buffer_size>>=1;
	mpeg4_encode_data.video_buffer1_address=(kal_uint32) intmem_get_buffer(video_buffer_size);
	mpeg4_encode_data.video_buffer2_address=(kal_uint32) intmem_get_buffer(video_buffer_size);

	config_image_dma(scene_id,mpeg4_encode_data.image_target_width,mpeg4_encode_data.image_target_height);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	open_image_data_path(scene_id);
	config_video_encode_data_path(scene_id,&ipp_video_encode_data);
#endif

	camera_image_setting(CAM_PARAM_EFFECT,isp_preview_config_data.image_effect);
	if(isp_preview_config_data.image_effect==0)
	{
		camera_image_setting(CAM_PARAM_CONTRAST,isp_preview_config_data.contrast_level);
		camera_image_setting(CAM_PARAM_BRIGHTNESS,isp_preview_config_data.brightness_level);
		camera_image_setting(CAM_PARAM_SATURATION,isp_preview_config_data.saturation_value);
	}
	camera_image_setting(CAM_PARAM_WB,isp_preview_config_data.wb_mode);
	camera_image_setting(CAM_PARAM_EXPOSURE,isp_preview_config_data.ev_value);
	camera_image_setting(CAM_PARAM_BANDING,isp_preview_config_data.banding_freq);
	camera_image_setting(CAM_PARAM_NIGHT_MODE,isp_preview_config_data.night_mode);

	ENABLE_VIEW_FINDER_MODE;

#endif
	return (kal_uint8)MEDIA_STATUS_OK;
}	/* mpeg4_encode_yuv_process */

/*************************************************************************
* FUNCTION
*	isp_yuv_digital_zoom
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
void isp_yuv_digital_zoom(kal_uint8 zoom_factor)
{
#if (defined(YUV_SENSOR_SUPPORT))
	kal_uint16 temp_grab_size;

	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR)/isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR)/isp_digital_zoom_factor)&0xFFFC ;

	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
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
			isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
		}
	}
	else if (isp_operation_state==ISP_MPEG4_ENCODE_STATE)
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
			isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
		}
	}
	else if (isp_operation_state==ISP_MJPEG_ENCODE_STATE)
	{
		if ((mjpeg_encode_data.target_width * exposure_window.exposure_window_height) >=
			 (mjpeg_encode_data.target_height * exposure_window.exposure_window_width))
		{	/* x limit */
			temp_grab_size=isp_grab_height;
			isp_grab_height=(isp_grab_width * mjpeg_encode_data.target_height/
								 mjpeg_encode_data.target_width)&0xFFFE;
			isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
		}
		else
		{	/* y limit */
			temp_grab_size=isp_grab_width;
			isp_grab_width=(isp_grab_height * mjpeg_encode_data.target_width/
								mjpeg_encode_data.target_height)&0xFFFE;
			isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
		}
	}
#if(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	/* Disable ISP Down Sample */
	DISABLE_VERTICAL_SUB_SAMPLE;
	DISABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE(isp_grab_width);
	SET_VSUB_SRC_SIZE(isp_grab_height);
	SET_HSUB_DST_SIZE(isp_grab_width);
	SET_VSUB_DST_SIZE(isp_grab_height);
	isp_preview_config_data.source_width=isp_grab_width;
	isp_preview_config_data.source_height=isp_grab_height;
	mpeg4_encode_data.image_source_width=isp_grab_width;
	mpeg4_encode_data.image_source_height=isp_grab_height;
	mjpeg_encode_data.source_width=isp_grab_width;
	mjpeg_encode_data.source_height=isp_grab_height;

#if(defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ipp_preview_data.image_src_width=isp_preview_config_data.source_width;
	ipp_preview_data.image_src_height=isp_preview_config_data.source_height;
	ipp_video_encode_data.image_src_width=mpeg4_encode_data.image_source_width;
	ipp_video_encode_data.image_src_height=mpeg4_encode_data.image_source_height;
#endif
#endif
#endif /* YUV_SENSOR_SUPPORT */
}

/*************************************************************************
* FUNCTION
*	camera_yuv_image_setting
*
* DESCRIPTION
*	This function set yuv sensor image parameter
*
* PARAMETERS
*	type_sel:	image type
*	para	  :	parameter
*
* RETURNS
*	TRUE or FALSE
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 camera_yuv_image_setting(kal_uint8 type_sel, kal_uint16 para)
{
#if (defined(YUV_SENSOR_SUPPORT))
	switch (type_sel)
	{
		case CAM_PARAM_ZOOM_FACTOR:
			isp_digital_zoom(para);
		break;
		case CAM_PARAM_CONTRAST:
      	image_sensor_func->yuv_sensor_setting(CAM_PARAM_CONTRAST,para);
		break;
		case CAM_PARAM_BRIGHTNESS:
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_BRIGHTNESS,para);
		break;
		case CAM_PARAM_HUE:
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_HUE,para);
		break;
		case CAM_PARAM_WB:
      	image_sensor_func->yuv_sensor_setting(CAM_PARAM_WB,para);
		break;
		case CAM_PARAM_EXPOSURE:
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_EXPOSURE,para);
		break;
		case CAM_PARAM_EFFECT:
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_EFFECT,para);
		break;
		case CAM_PARAM_BANDING:
         image_sensor_func->yuv_sensor_setting(CAM_PARAM_BANDING,para);
		break;
		case CAM_PARAM_SATURATION:
	      image_sensor_func->yuv_sensor_setting(CAM_PARAM_SATURATION,para);
		break;
		case CAM_PARAM_NIGHT_MODE:
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_NIGHT_MODE,para);
		break;
	}
#endif
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	background_yuv_image_setting
*
* DESCRIPTION
*	This function set yuv sensor image parameter
*
* PARAMETERS
*	NONE
*
* RETURNS
*	TRUE or FALSE
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 background_yuv_image_setting(void)
{
#if (defined(YUV_SENSOR_SUPPORT))
	kal_uint8 i;

	for (i=0;i<CAM_NO_OF_PARAM;i++)
	{
		if (image_setting_index & (1<<i))
		{
			switch (i)
			{
				case CAM_PARAM_EFFECT:
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_EFFECT,isp_preview_config_data.image_effect);
				break;
				case CAM_PARAM_CONTRAST:
		      	image_sensor_func->yuv_sensor_setting(CAM_PARAM_CONTRAST,isp_preview_config_data.contrast_level);
				break;
				case CAM_PARAM_BRIGHTNESS:
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_BRIGHTNESS,isp_preview_config_data.brightness_level);
				break;
				case CAM_PARAM_HUE:
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_HUE,isp_preview_config_data.hue_value);
				break;
				case CAM_PARAM_WB:
		      	image_sensor_func->yuv_sensor_setting(CAM_PARAM_WB,isp_preview_config_data.wb_mode);
				break;
				case CAM_PARAM_EXPOSURE:
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_EXPOSURE,isp_preview_config_data.ev_value);
				break;
				case CAM_PARAM_BANDING:
		         image_sensor_func->yuv_sensor_setting(CAM_PARAM_BANDING,isp_preview_config_data.banding_freq);
				break;
				case CAM_PARAM_SATURATION:
			      image_sensor_func->yuv_sensor_setting(CAM_PARAM_SATURATION,isp_preview_config_data.saturation_value);
				break;
				case CAM_PARAM_NIGHT_MODE:
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_NIGHT_MODE,isp_preview_config_data.night_mode);
				break;
			}
			image_setting_index &=~(1<<i);
		}
	}
#endif
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	camera_yuv_operation_setting
*
* DESCRIPTION
*	This function set yuv sensor AE/AF/Flash parameter
*
* PARAMETERS
*	NONE
*
* RETURNS
*	TRUE or FALSE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void camera_yuv_operation_setting(kal_uint8 func_sel, kal_uint16 para)
{
#if (defined(YUV_SENSOR_SUPPORT))
	switch(func_sel)
	{
		case CAM_DSC_MODE:
			dsc_status.dscmode=para;
			if(dsc_status.dscmode==CAM_NIGHTSCENE)
				camera_image_setting(CAM_PARAM_NIGHT_MODE,1);
			else
				camera_image_setting(CAM_PARAM_NIGHT_MODE,0);
#if (defined(AF_SUPPORT))
			if(dsc_status.dscmode==CAM_FLOWER)
			{
				dsc_status.af.mode=CAM_AF_MACRO_MODE;
				image_sensor_func->yuv_sensor_setting(CAM_PARAM_AF_MODE,CAM_AF_MACRO_MODE);
			}
			else if(dsc_status.dscmode==CAM_LANDSCAPE)
			{
				dsc_status.af.mode=CAM_AF_INFINITE_MODE;
				image_sensor_func->yuv_sensor_setting(CAM_PARAM_AF_MODE,CAM_AF_INFINITE_MODE);
			}
			else
			{
				dsc_status.af.mode=CAM_AF_AUTO_MODE;
				image_sensor_func->yuv_sensor_setting(CAM_PARAM_AF_MODE,CAM_AF_AUTO_MODE);
			}
#endif
		break;
		case CAM_AE_METERING:
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_AE_METERING,para);
		break;
#if (defined(AF_SUPPORT))
		case CAM_AF_KEY:
			if(para==CAM_AF_RELEASE)
				af_operation_state=AF_STANDBY_STATE;
			else
			{
				af_operation_state=AF_SEARCH_STATE;
				yuv_af_check_count=0;
			}
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_AF_KEY,para);
		break;
		case CAM_AF_METERING:
			dsc_status.af.metering=para;
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_AF_METERING,para);
		break;
		case CAM_AF_MODE:
			if(isp_preview_config_data.dsc_mode==CAM_FLOWER)//scenario modified
				dsc_status.af.mode=CAM_AF_MACRO_MODE;
			else
				dsc_status.af.mode=para;
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_AF_MODE,para);
		break;
		case CAM_MANUAL_FOCUS_DIR:
			dsc_status.af.mfdir=para;
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_MANUAL_FOCUS_DIR,para);
		break;
#endif
		case CAM_FLASH_MODE:
			image_sensor_func->yuv_sensor_setting(CAM_PARAM_FLASH,para);
		break;
	}
#endif
}

#endif /* ! MT6219 */
