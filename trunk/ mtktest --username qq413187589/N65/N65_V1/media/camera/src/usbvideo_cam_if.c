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
 *   usbvideo_camera_if.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements web camera module interface function (API)
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
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "drv_features.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "data_buff_pool.h"
#include "stack_config.h"
#include "syscomp_config.h"
#include "app_buff_alloc.h"
#include "IntrCtrl.h"
#include "gpio_sw.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "drv_comm.h"
#include "img_comm.h"

#include "gpt_sw.h"
#include "med_api.h"

#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"

#if (defined(ISP_SUPPORT))
#include "sccb.h"
#include "isp_if.h"
#include "image_effect.h"
#include "image_sensor.h"
#include "camera_para.h"
#include "isp_device_if.h"
#include "ae_awb.h"
#include "imgproc.h"
#include "resizer.h"
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

/* State Machine */
USBVIDEO_CAM_OPERATION_STATE_ENUM usbvideo_cam_operation_state = USBVIDEO_CAM_OFF_STATE;
MMDI_SCENERIO_ID scene_id=SCENARIO_USBVIDEO_CAPTURE_JPEG_ID;

extern kal_eventgrpid camera_isp_event_id;
usbvideo_camera_process_struct g_usbvideo_camera_data;
USBVIDEO_VIDEO_SIZE_TYPE g_usbvideo_cam_size;
kal_uint8 *g_usbvideo_cam_buff;
extern kal_uint8 ae_count;
extern kal_bool wait_first_frame_flag;
extern kal_uint8 isp_preview_frame;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
extern camera_capture_jpeg_data_path_struct 	ipp_capture_jpeg_data;
#endif
#if (defined(DRV_ISP_6225_SERIES))
extern jpeg_encode_process_struct sw_jpeg_encode_config_data;
#endif
/* function/attribute map */
usbvideo_sensor_func_struct *usbvideo_image_sensor_func;
kal_uint8 usbvideo_cam_command_CT_map[GET_ATTR_CT_IDX(USBVIDEO_ATTRIBUTE_CT_MAX)];
kal_uint8 usbvideo_cam_command_PU_map[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX)];
kal_uint32 usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX)];
kal_uint32 usbvideo_attr_setting_CT_index=0;
kal_uint32 usbvideo_attr_setting_PU_index=0;

void usbvideo_camera_init_attr(void);
kal_uint8 usbvideo_camera_update_attr(void);
kal_uint8 usbvideo_camera_effect_setting_attr(USBVideo_Attr_Value *attr);
kal_uint8 usbvideo_camera_effect_getting_attr(USBVideo_Attr_Value *attr);
void config_usbvideo_preview_jpeg(usbvideo_camera_process_struct* usbvideo_param);

kal_bool 	usbvideo_complete_flag = KAL_FALSE;
kal_uint8	usbvideo_camera_jpeg_timer_handle; 
kal_uint32	usbvideo_camera_jpeg_timer = 0; 
kal_uint32 	jpeg_file_size=0;

/* For WEBCAM MT6228+TG sync AE/AWB frame ready and jpeg encode interrupt sync */
extern kal_bool tg_interrupt_flag;
kal_bool usbvideo_camera_fr_flag=KAL_TRUE, usbvideo_camera_jpeg_flag=KAL_TRUE;

const usbvideo_attr_struct USBVIDEO_ATTR_PARA=
{/* min,	max,	res,	def */
	{
	{0,	3,		1,		0	},	/*0  USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION*/
	{0,	255,	1,		127},	/*1  USBVIDEO_ATTRIBUTE_BRIGHTNESS*/
	{0,	255,	1,		127}, /*2  USBVIDEO_ATTRIBUTE_CONTRAST*/
	{0,	255,	1,		127}, /*3  USBVIDEO_ATTRIBUTE_GAIN*/
	{0,	2,		1,		1	},	/*4  USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY, 0:Disable, 1:50, 2:60*/
	{0,	360,	  1 ,	0	},	/*5  USBVIDEO_ATTRIBUTE_HUE*/
	{0,	255,	1,		127},	/*6  USBVIDEO_ATTRIBUTE_SATURATION*/
	{0,	15,	1,		0	},	/*7  USBVIDEO_ATTRIBUTE_SHARPNESS*/
	{100,	220,	60,	160},	/*8  USBVIDEO_ATTRIBUTE_GAMMA*/
	{2500, 6500,	500,	5500},/*9 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP*/
	{0,	1,		1,		1	},	/*10 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO*/
	{0,	0,		0,		0	},	/*11 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP, NOT SUPPORT*/
	{0,	1,		1,		1	},	/*12 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP_AUTO*/									
	{0,	0,		1,		0	}, /*13 USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER, NOT SUPPORT*/									
	{0,	0,		1,		0	},	/*14 USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER_LIMIT, NOT SUPPORT*/									
	{100,	100,	1,		0	},	/*15 USBVIDEO_ATTRIBUTE_HUE_AUTO*/									
	{0,	0,		0,		0	}	/*16 USBVIDEO_ATTRIBUTE_MAX_MULTIPLIER, NOT SUPPORT*/									
	}
};

const kal_uint8 USBVIDEO_GAMMA_ATTR[3][11]=
{        
    {16, 32, 48, 64, 96, 128, 160, 192, 208, 224, 240},    
    {48, 73, 93, 111, 141, 169, 192, 215, 225, 235, 245},        
    {73, 100, 120, 136, 164, 186, 206, 224, 232, 240, 248}        
};
    
/*************************************************************************
* FUNCTION
*	usbvideo_camera_init
*
* DESCRIPTION
*	This function init web camera module status.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void usbvideo_camera_init(void)
{
	usbvideo_cam_operation_state=USBVIDEO_CAM_OFF_STATE;

	usbvideo_camera_init_attr();

	/* device function mapping */
	usbvideo_camera_func_config();
	usbvideo_image_sensor_func->usbvideo_cmd_mapping();
#if (defined(YUV_SENSOR_SUPPORT))		
    image_sensor_func_config();
#endif    
#if  (!defined(DRV_ISP_6225_SERIES))
	GPTI_GetHandle(&usbvideo_camera_jpeg_timer_handle);   
#endif	
}	/* usbvideo_camera_init() */

/*************************************************************************
* FUNCTION
*	usbvideo_camera_power_on
*
* DESCRIPTION
*	This function turn the power of web camera module on.
*
* PARAMETERS
*	None
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool usbvideo_camera_power_on(void)
{
	if (usbvideo_cam_operation_state==USBVIDEO_CAM_OFF_STATE)
	{
		usbvideo_cam_operation_state=USBVIDEO_CAM_STANDBY_STATE;
		if (camera_isp_event_id==NULL)
			camera_isp_event_id=kal_create_event_group("ISP_EVT");
		init_isp_if();
		if (sensor_err_check<0)
			return KAL_FALSE;
		else
			return KAL_TRUE;			
	}
	else
		ASSERT(0);
	return KAL_FALSE;		
}	/* usbvideo_camera_power_on() */


/*************************************************************************
* FUNCTION
*	usbvideo_camera_power_off
*
* DESCRIPTION
*	This function turn off the power of web camera module.
*  complete or not.
*
* PARAMETERS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void usbvideo_camera_power_off(void)
{
	usbvideo_cam_operation_state=USBVIDEO_CAM_OFF_STATE;
	power_off_isp();
}	/* usbvideo_camera_power_off() */

void init_working_mem(void)
{
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))	
	intmem_init((kal_uint32 *) g_usbvideo_camera_data.intmem_start_address,
					g_usbvideo_camera_data.intmem_size);
	extmem_init((kal_uint32 *) g_usbvideo_camera_data.extmem_start_address,
					g_usbvideo_camera_data.extmem_size);
#endif					
}

void deinit_working_mem(void)
{
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))		
	intmem_deinit();
	extmem_deinit();
#endif	
}

void config_usbvideo_preview_jpeg(usbvideo_camera_process_struct* usbvideo_param)
{
   kal_uint32 event_group;
	volatile kal_uint8 i;
	kal_uint16 temp_grab_size;
	kal_uint8 usbvideo_sub_sample_mode;

	scene_id=SCENARIO_USBVIDEO_CAPTURE_JPEG_ID;
	usbvideo_complete_flag = KAL_FALSE;

	if((usbvideo_param->target_comp_enum)<1)
		usbvideo_param->target_comp_enum = 1;		
	g_usbvideo_camera_data.image_quality=STILL_COMPRESSION[usbvideo_param->target_comp_enum-1].compression;	

	g_usbvideo_camera_data.target_buffer_start_address = (kal_uint32)g_usbvideo_cam_buff;
	g_usbvideo_camera_data.target_size_enum = g_usbvideo_cam_size;	
	g_usbvideo_camera_data.intmem_start_address = usbvideo_param->intmem_start_address;
	g_usbvideo_camera_data.intmem_size = usbvideo_param->intmem_size;
	g_usbvideo_camera_data.extmem_start_address = usbvideo_param->extmem_start_address;
	g_usbvideo_camera_data.extmem_size = usbvideo_param->extmem_size;
	g_usbvideo_camera_data.usbvideo_cam_preview_cb = usbvideo_param->usbvideo_cam_preview_cb;				
#if (defined(DRV_ISP_6225_SERIES))
    g_usbvideo_camera_data.usbvideo_encode_cb = usbvideo_param->usbvideo_encode_cb;					
#endif
	g_usbvideo_camera_data.jpeg_gray_mode=0;

	/* configure sensor */
	exposure_window.image_target_width=g_usbvideo_camera_data.target_width;
	exposure_window.image_target_height=g_usbvideo_camera_data.target_height;
	exposure_window.digital_zoom_factor=isp_digital_zoom_factor;

	// Disable AE Count before Start Preview	
	#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	DISABLE_VIEW_FINDER_MODE;   	
	DISABLE_AE_COUNT;
	#endif

	sensor_config_data.image_mirror=usbvideo_param->image_mirror;
	sensor_config_data.frame_rate=0xF0;		// webcam mode
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);

#if (!defined(YUV_SENSOR_SUPPORT))	
	/* accoring the zoom factor to calculate the grab window area */
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFE);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	isp_horizontal_subsample=exposure_window.isp_hsub_factor;
   isp_vertical_subsample=exposure_window.isp_vsub_factor;

	if ((exposure_window.image_target_width * exposure_window.exposure_window_height) >=
		 (exposure_window.image_target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=isp_grab_width * exposure_window.image_target_height/exposure_window.image_target_width;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=isp_grab_height * exposure_window.image_target_width/exposure_window.image_target_height;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
	}

	isp_grab_start_x-=(((isp_grab_width*(isp_horizontal_subsample-1))>>1)&0xFFFE);
	isp_grab_start_y-=((isp_grab_height*(isp_vertical_subsample-1))>>1);

	SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
	SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
#else   // YUV_SENSOR_SUPPORT
	/* accoring the zoom factor to calculate the grab window area */
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((exposure_window.image_target_width * exposure_window.exposure_window_height) >=
		 (exposure_window.image_target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * exposure_window.image_target_height/exposure_window.image_target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * exposure_window.image_target_width/exposure_window.image_target_height)&0xFFFC;;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
	}

	SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
	SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
#endif  /* YUV_SENSOR_SUPPORT */

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
	DISABLE_CMOS_SESNOR;
#endif
	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	ENABLE_CAMERA_IDLE_INT;
	SET_CAMERA_CAPTURE_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
	ENABLE_CMOS_SESNOR;
#endif
   kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);
	sensor_config_data.enable_shutter_tansfer=KAL_FALSE;
#if (!defined(YUV_SENSOR_SUPPORT))	
	image_sensor_func->set_sensor_eshutter(eShutter);
#endif
	image_sensor_func->sensor_capture_setting(&exposure_window,&sensor_config_data);

#if (!defined(YUV_SENSOR_SUPPORT))
	/* accoring the zoom factor to calculate the grab window area */
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFE);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	isp_horizontal_subsample=exposure_window.isp_hsub_factor;
   isp_vertical_subsample=exposure_window.isp_vsub_factor;

	if ((exposure_window.image_target_width * exposure_window.exposure_window_height) >=
		 (exposure_window.image_target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=isp_grab_width * exposure_window.image_target_height/exposure_window.image_target_width;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=isp_grab_height * exposure_window.image_target_width/exposure_window.image_target_height;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFE);
	}

	isp_grab_start_x-=(((isp_grab_width*(isp_horizontal_subsample-1))>>1)&0xFFFE);
	isp_grab_start_y-=((isp_grab_height*(isp_vertical_subsample-1))>>1);

	SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
	SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));

	ae_config((isp_grab_width*isp_horizontal_subsample),(isp_grab_height*isp_vertical_subsample));
	
	/* Init Banding Flicker Setting */
	if(usbvideo_param->banding_freq == CAM_BANDING_50HZ)
	{   /* 50Hz */
        usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY)] = 1;
    }
    else
    {   /* 60Hz or Disable */
        usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY)] = 2;
    }        	
    ae_select_band(usbvideo_param->banding_freq);                	
    
#if (!defined(DRV_ISP_6219_SERIES))			
	apply_camera_shading_to_reg(CAMERA_COMP_PREVIEW_NORMAL_SET);
	if(camera_oper_data.preview_defect_table_enable==KAL_TRUE)
	{
		load_defect_table_para(DEFECT_MODE_PREVIEW);
		ENABLE_DEFECT_CORRECTION;
	}
	else
		DISABLE_DEFECT_CORRECTION;
#endif			
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
	SET_AE_FRAME_INTERVAL(1);
	REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;		
	if(camera_oper_data.ae_awb_cal_period<4)
	    camera_oper_data.ae_awb_cal_period = 4;
#endif
	
#if (defined(DRV_ISP_6219_SERIES))	
	if ((isp_grab_width<=g_usbvideo_camera_data.target_width) && (isp_grab_height<=g_usbvideo_camera_data.target_height))
	{
		usbvideo_sub_sample_mode=CAMERA_SUB_SAMPLE_1_1;
		g_usbvideo_camera_data.source_width = isp_grab_width;
		g_usbvideo_camera_data.source_height=isp_grab_height;
	}
	else if ((isp_grab_width<=(g_usbvideo_camera_data.target_width<<1)) && (isp_grab_height<=(g_usbvideo_camera_data.target_height<<1)))
	{
		usbvideo_sub_sample_mode=CAMERA_SUB_SAMPLE_1_2;
		g_usbvideo_camera_data.source_width=isp_grab_width>>1;
		g_usbvideo_camera_data.source_height=isp_grab_height>>1;
	}
	else if ((isp_grab_width<=(g_usbvideo_camera_data.target_width<<2)) && (isp_grab_height<=(g_usbvideo_camera_data.target_height<<2)))
	{
		usbvideo_sub_sample_mode=CAMERA_SUB_SAMPLE_1_4;
		g_usbvideo_camera_data.source_width=isp_grab_width>>2;
		g_usbvideo_camera_data.source_height=isp_grab_height>>2;
	}
	else // if ((isp_grab_width<=(g_usbvideo_camera_data.target_width<<3)) && (isp_grab_height<=(g_usbvideo_camera_data.target_height<<3)))
	{
		usbvideo_sub_sample_mode=CAMERA_SUB_SAMPLE_1_8;
		g_usbvideo_camera_data.source_width=isp_grab_width>>3;
		g_usbvideo_camera_data.source_height=isp_grab_height>>3;
	}
	SET_SUB_SAMPLE_MODE(usbvideo_sub_sample_mode);
#elif  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ENABLE_VERTICAL_SUB_SAMPLE;
	ENABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));	
	SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
	if((isp_grab_width>(g_usbvideo_camera_data.target_width<<2)) || (isp_grab_height>(g_usbvideo_camera_data.target_height<<2)))
	{ /* grab size > taget size *4 => ISP subsample 4x */
		SET_HSUB_DST_SIZE((isp_grab_width>>2)&0xFFFE);
		SET_VSUB_DST_SIZE((isp_grab_height>>2)&0xFFFE);
		g_usbvideo_camera_data.source_width=(isp_grab_width>>2)&0xFFFE;
		g_usbvideo_camera_data.source_height=(isp_grab_height>>2)&0xFFFE;
	}
	else if((isp_grab_width>(g_usbvideo_camera_data.target_width<<1)) || (isp_grab_height>(g_usbvideo_camera_data.target_height<<1)))
	{ /* grab size > taget size *2 => ISP subsample 2x */
		SET_HSUB_DST_SIZE((isp_grab_width>>1)&0xFFFE);
		SET_VSUB_DST_SIZE((isp_grab_height>>1)&0xFFFE);
		g_usbvideo_camera_data.source_width=(isp_grab_width>>1)&0xFFFE;
		g_usbvideo_camera_data.source_height=(isp_grab_height>>1)&0xFFFE;
	}
	else if((isp_grab_width>g_usbvideo_camera_data.target_width) || (isp_grab_height>g_usbvideo_camera_data.target_height))	
	{
		SET_HSUB_DST_SIZE((g_usbvideo_camera_data.target_width)&0xFFFE);
		SET_VSUB_DST_SIZE((g_usbvideo_camera_data.target_height)&0xFFFE);
		g_usbvideo_camera_data.source_width=(g_usbvideo_camera_data.target_width)&0xFFFE;
		g_usbvideo_camera_data.source_height=(g_usbvideo_camera_data.target_height)&0xFFFE;
	}
	else
	{
		SET_HSUB_DST_SIZE((isp_grab_width)&0xFFFE);				  
		SET_VSUB_DST_SIZE((isp_grab_height)&0xFFFE);
		g_usbvideo_camera_data.source_width=(isp_grab_width)&0xFFFE;
		g_usbvideo_camera_data.source_height=(isp_grab_height)&0xFFFE;
	}
#endif

	/* Wait stable frame */
	ae_on_off(KAL_TRUE);
	awb_on_off(KAL_TRUE);   	

#else   // YUV_SENSOR_SUPPORT
#if (!defined(DRV_ISP_6225_SERIES))
	/* accoring the zoom factor to calculate the grab window area */
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((exposure_window.image_target_width * exposure_window.exposure_window_height) >=
		 (exposure_window.image_target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * exposure_window.image_target_height/exposure_window.image_target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * exposure_window.image_target_width/exposure_window.image_target_height)&0xFFFC;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
	}
	SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
	SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
	
    /* (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES)) */
	ENABLE_VERTICAL_SUB_SAMPLE;
	ENABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE(isp_grab_width);	
	SET_VSUB_SRC_SIZE(isp_grab_height);
	if((isp_grab_width>(g_usbvideo_camera_data.target_width<<2)) || (isp_grab_height>(g_usbvideo_camera_data.target_height<<2)))
	{ /* grab size > taget size *4 => ISP subsample 4x */
		SET_HSUB_DST_SIZE((isp_grab_width>>2)&0xFFFC);
		SET_VSUB_DST_SIZE((isp_grab_height>>2)&0xFFFE);
		g_usbvideo_camera_data.source_width=(isp_grab_width>>2)&0xFFFC;
		g_usbvideo_camera_data.source_height=(isp_grab_height>>2)&0xFFFE;
	}
	else if((isp_grab_width>(g_usbvideo_camera_data.target_width<<1)) || (isp_grab_height>(g_usbvideo_camera_data.target_height<<1)))
	{ /* grab size > taget size *2 => ISP subsample 2x */
		SET_HSUB_DST_SIZE((isp_grab_width>>1)&0xFFFC);
		SET_VSUB_DST_SIZE((isp_grab_height>>1)&0xFFFE);
		g_usbvideo_camera_data.source_width=(isp_grab_width>>1)&0xFFFC;
		g_usbvideo_camera_data.source_height=(isp_grab_height>>1)&0xFFFE;
	}
	else if((isp_grab_width>g_usbvideo_camera_data.target_width) || (isp_grab_height>g_usbvideo_camera_data.target_height))	
	{
		SET_HSUB_DST_SIZE((g_usbvideo_camera_data.target_width)&0xFFFC);
		SET_VSUB_DST_SIZE((g_usbvideo_camera_data.target_height)&0xFFFE);
		g_usbvideo_camera_data.source_width=(g_usbvideo_camera_data.target_width)&0xFFFC;
		g_usbvideo_camera_data.source_height=(g_usbvideo_camera_data.target_height)&0xFFFE;
	}
	else
	{
		SET_HSUB_DST_SIZE((isp_grab_width)&0xFFFC);				  
		SET_VSUB_DST_SIZE((isp_grab_height)&0xFFFE);
		g_usbvideo_camera_data.source_width=(isp_grab_width)&0xFFFC;
		g_usbvideo_camera_data.source_height=(isp_grab_height)&0xFFFE;
	}		
#else   // MT6225
	/* accoring the zoom factor to calculate the grab window area */
	isp_grab_width= ((exposure_window.exposure_window_width * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_height=((exposure_window.exposure_window_height * ISP_MIN_DIGITAL_ZOOM_FACTOR) / isp_digital_zoom_factor)&0xFFFC ;
	isp_grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-isp_grab_width)>>1)&0xFFFC);
	isp_grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-isp_grab_height)>>1)&0xFFFE);

	if ((exposure_window.image_target_width * exposure_window.exposure_window_height) >=
		 (exposure_window.image_target_height * exposure_window.exposure_window_width))
	{	/* x limit */
		temp_grab_size=isp_grab_height;
		isp_grab_height=(isp_grab_width * exposure_window.image_target_height/exposure_window.image_target_width)&0xFFFE;
		isp_grab_start_y+=(((temp_grab_size-isp_grab_height)>>1)&0xFFFE);
	}
	else
	{	/* y limit */
		temp_grab_size=isp_grab_width;
		isp_grab_width=(isp_grab_height * exposure_window.image_target_width/exposure_window.image_target_height)&0xFFFC;
		isp_grab_start_x+=(((temp_grab_size-isp_grab_width)>>1)&0xFFFC);
	}
	SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
	SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
	
	DISABLE_VERTICAL_SUB_SAMPLE;
	DISABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE(isp_grab_width);	
	SET_VSUB_SRC_SIZE(isp_grab_height);
	SET_HSUB_DST_SIZE(isp_grab_width);				  
	SET_VSUB_DST_SIZE(isp_grab_height);
	g_usbvideo_camera_data.source_width=isp_grab_width;
	g_usbvideo_camera_data.source_height=isp_grab_height;
#endif  // !MT6225
#endif  /* YUV_SENSOR_SUPPORT */   

	wait_first_frame_flag = KAL_TRUE;
	isp_preview_frame = 0;
	for(i=0;i<camera_oper_data.capture_delay_frame;i++)
	{
	   DISABLE_VIEW_FINDER_MODE;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
		DISABLE_CMOS_SESNOR;
#endif
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
		ENABLE_CMOS_SESNOR;
#endif
   	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
      	                    &event_group,KAL_SUSPEND);
   }

	// Enable AE Count before Start Preview
	#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	ENABLE_AE_COUNT;
	#endif			
   
   DISABLE_VIEW_FINDER_MODE;
   DISABLE_CAMERA_IDLE_INT;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	init_working_mem();

	jpeg_encode_config_data.image_width=g_usbvideo_camera_data.target_width;
	jpeg_encode_config_data.image_height=g_usbvideo_camera_data.target_height;
	jpeg_encode_config_data.image_quality=g_usbvideo_camera_data.image_quality;
	jpeg_encode_config_data.jpeg_gray_mode=g_usbvideo_camera_data.jpeg_gray_mode;
	jpeg_encode_config_data.jpeg_file_start_address=g_usbvideo_camera_data.target_buffer_start_address;
	jpeg_encode_config_data.jpeg_file_buffer_size=g_usbvideo_camera_data.target_buffer_size;

	jpeg_codec_power_up();

	mp4_reset();
	config_image_dma(scene_id,g_usbvideo_camera_data.target_width,g_usbvideo_camera_data.target_height);
	config_jpeg_encoder(&jpeg_encode_config_data);
	config_image_processor(scene_id);
	config_pixel_resizer(scene_id);
	jpeg_encoder_encode_result=0;		
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	/* Prepare IPP Data */
	ipp_capture_jpeg_data.intmem_start_address			=	g_usbvideo_camera_data.intmem_start_address;
	ipp_capture_jpeg_data.intmem_size						=	g_usbvideo_camera_data.intmem_size;
	ipp_capture_jpeg_data.extmem_start_address			=	g_usbvideo_camera_data.extmem_start_address;
	ipp_capture_jpeg_data.extmem_size						=	g_usbvideo_camera_data.extmem_size;

	ipp_capture_jpeg_data.image_src_width					=	g_usbvideo_camera_data.source_width;
	ipp_capture_jpeg_data.image_src_height					=	g_usbvideo_camera_data.source_height;
	ipp_capture_jpeg_data.image_capture_width				=	g_usbvideo_camera_data.target_width;
	ipp_capture_jpeg_data.image_capture_height			=	g_usbvideo_camera_data.target_height;
	
	ipp_capture_jpeg_data.image_quality						=	g_usbvideo_camera_data.image_quality;
	ipp_capture_jpeg_data.jpeg_yuv_mode						=	JPEG_FORMAT_YUV420;

	ipp_capture_jpeg_data.jpeg_file_start_address1		=	g_usbvideo_camera_data.target_buffer_start_address;
	ipp_capture_jpeg_data.jpeg_file_buffer_size1			=	g_usbvideo_camera_data.target_buffer_size;

	ipp_capture_jpeg_data.cam_capture_jpeg_cb				=	0;

	open_image_data_path(scene_id);
	config_camera_usbvideo_jpeg_data_path(scene_id,&ipp_capture_jpeg_data);
	jpeg_encoder_encode_result=0;
#elif (defined(DRV_ISP_6225_SERIES))
	g_usbvideo_camera_data.y_address = usbvideo_param->y_address;
	g_usbvideo_camera_data.u_address = usbvideo_param->u_address;
	g_usbvideo_camera_data.v_address = usbvideo_param->v_address;
	g_usbvideo_camera_data.y_size = usbvideo_param->y_size;
	g_usbvideo_camera_data.u_size = usbvideo_param->u_size;
	g_usbvideo_camera_data.v_size = usbvideo_param->v_size;
    
	init_working_mem();
	// For Image Data Path Use
	isp_capture_jpeg_data.intmem_start_address=g_usbvideo_camera_data.intmem_start_address;
	isp_capture_jpeg_data.intmem_size=g_usbvideo_camera_data.intmem_size;
	isp_capture_jpeg_data.extmem_start_address=g_usbvideo_camera_data.extmem_start_address;
	isp_capture_jpeg_data.extmem_size=g_usbvideo_camera_data.extmem_size;
	isp_capture_jpeg_data.target_width=g_usbvideo_camera_data.target_width;
	isp_capture_jpeg_data.target_height=g_usbvideo_camera_data.target_height;
	isp_capture_jpeg_data.source_width=g_usbvideo_camera_data.source_width;
	isp_capture_jpeg_data.source_height=g_usbvideo_camera_data.source_height;	
    
	isp_capture_jpeg_data.image_quality=g_usbvideo_camera_data.image_quality;
	isp_capture_jpeg_data.jpeg_gray_mode=g_usbvideo_camera_data.jpeg_gray_mode;
	isp_capture_jpeg_data.target_buffer_start_address=g_usbvideo_camera_data.target_buffer_start_address;
	isp_capture_jpeg_data.target_buffer_size=g_usbvideo_camera_data.target_buffer_size;
	
	isp_capture_jpeg_data.y_address=g_usbvideo_camera_data.y_address;
	isp_capture_jpeg_data.u_address=g_usbvideo_camera_data.u_address;
	isp_capture_jpeg_data.v_address=g_usbvideo_camera_data.v_address;
	isp_capture_jpeg_data.y_size = g_usbvideo_camera_data.y_size;
	isp_capture_jpeg_data.u_size = g_usbvideo_camera_data.u_size;
	isp_capture_jpeg_data.v_size = g_usbvideo_camera_data.v_size;
	isp_capture_jpeg_data.cam_capture_jpeg_cb = g_usbvideo_camera_data.usbvideo_encode_cb;	
	// For SW JPEG Encode
	sw_jpeg_encode_config_data.image_width              =isp_capture_jpeg_data.target_width;
	sw_jpeg_encode_config_data.image_height             =isp_capture_jpeg_data.target_height;
	sw_jpeg_encode_config_data.image_quality            =isp_capture_jpeg_data.image_quality;
	sw_jpeg_encode_config_data.image_buffer_address	    =isp_capture_jpeg_data.target_buffer_start_address; 
	sw_jpeg_encode_config_data.jpeg_file_start_address  =isp_capture_jpeg_data.target_buffer_start_address;
	sw_jpeg_encode_config_data.jpeg_file_buffer_size    =isp_capture_jpeg_data.target_buffer_size;
	sw_jpeg_encode_config_data.intmem_start_address     =isp_capture_jpeg_data.intmem_start_address;	
	sw_jpeg_encode_config_data.intmem_size              =isp_capture_jpeg_data.intmem_size;			
	sw_jpeg_encode_config_data.input_type               =IMAGE_FORMAT_YUV420;
	if(isp_capture_jpeg_data.jpeg_gray_mode==0)
		sw_jpeg_encode_config_data.output_type=IMAGE_FORMAT_YUV420;
	else
		sw_jpeg_encode_config_data.output_type=IMAGE_FORMAT_GRAY;
					
	sw_jpeg_encode_config_data.jpeg_yuv_data[0]         =(kal_uint8 *)g_usbvideo_camera_data.y_address;
	sw_jpeg_encode_config_data.jpeg_yuv_data[1]         =(kal_uint8 *)g_usbvideo_camera_data.u_address;
	sw_jpeg_encode_config_data.jpeg_yuv_data[2]         =(kal_uint8 *)g_usbvideo_camera_data.v_address;
	sw_jpeg_encode_config_data.jpeg_yuv_size[0]         =g_usbvideo_camera_data.y_size;
	sw_jpeg_encode_config_data.jpeg_yuv_size[1]         =g_usbvideo_camera_data.u_size;
	sw_jpeg_encode_config_data.jpeg_yuv_size[2]         =g_usbvideo_camera_data.v_size;
	
	config_pixel_resizer(scene_id);	
#endif
}	/* config_usbvideo_preview_jpeg() */

/*************************************************************************
* FUNCTION
*	usbvideo_camera_preview
*
* DESCRIPTION
*	This function starts camera preview
*
* PARAMETERS
*	usbvideo_data : the parameters for camera preview process
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool usbvideo_camera_preview(usbvideo_camera_process_struct* usbvideo_param)
{
	if (sensor_err_check<0)
		return KAL_FALSE;

	if (usbvideo_cam_operation_state != USBVIDEO_CAM_STANDBY_STATE)
		ASSERT(0);

	g_usbvideo_cam_buff = USBVideo_Get_Video_Buffer();	
	if(g_usbvideo_cam_buff!=NULL)
	{
		g_usbvideo_cam_size = usbvideo_param->target_size_enum;
		g_usbvideo_camera_data.target_width = VIDEO_SIZE[g_usbvideo_cam_size-1].width;
		g_usbvideo_camera_data.target_height = VIDEO_SIZE[g_usbvideo_cam_size-1].height;
		g_usbvideo_camera_data.target_buffer_size = VIDEO_SIZE[g_usbvideo_cam_size-1].max_frame_size;
	
	   ENABLE_CMOS_SESNOR;	
           usbvideo_camera_fr_flag=KAL_FALSE; 
           usbvideo_camera_jpeg_flag = KAL_FALSE; 
		config_usbvideo_preview_jpeg(usbvideo_param);
		usbvideo_cam_operation_state = USBVIDEO_CAM_PREVIEW_CHECK_STATE;
		/* Start Sensor Interrupt */
		SET_CAMERA_CAPTURE_MODE;
		SET_CAMERA_FRAME_RATE(0);
		ENABLE_VIEW_FINDER_MODE;
		return KAL_TRUE;						
	}
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	exit_usbvideo_camera_preview
*
* DESCRIPTION
*	This function exit camera preview
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
void exit_usbvideo_camera_preview(void)
{
	if (sensor_err_check<0)
		return ;
	
	if (usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
	{
   	kal_uint32 save_irq_mask;

     	save_irq_mask=SaveAndSetIRQMask();
   	usbvideo_cam_operation_state=USBVIDEO_CAM_STANDBY_STATE;
  	   RestoreIRQMask(save_irq_mask);
#if (!defined(YUV_SENSOR_SUPPORT))	
   	ae_on_off(KAL_FALSE);
   	awb_on_off(KAL_FALSE);
#endif   	
#if  (!defined(DRV_ISP_6225_SERIES))
      if(jpeg_encoder_operation_state==JPEG_ENCODER_ENCODING_STATE)
      {
   		kal_uint32 i;      	
   		/* wait until JPEG encode completely */
   		for (i=0;i<20;i++)
   		{
   			kal_sleep_task(20);
				if ((jpeg_encoder_encode_result & JPEG_ENCODE_STALL)||
					 (jpeg_encoder_encode_result & JPEG_ENCODE_DONE))
   				i=100;
   		}
   		DISABLE_CMOS_SESNOR;
   		DISABLE_VIEW_FINDER_MODE;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
   		RESZ_Stop(scene_id);
   		RESZ_Close(scene_id);

   		clean_imgprc_coefficient(scene_id);
   		IMGPROC_Stop(scene_id);
   		IMGPROC_Close(scene_id);

   		stop_image_dma(scene_id);
   		IMGDMA_Close(scene_id);

   		intmem_deinit();
   		extmem_deinit();
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))      
			close_image_data_path(scene_id);
#endif      
      }
#elif (defined(DRV_ISP_6225_SERIES))	
       		DISABLE_CMOS_SESNOR;
       		DISABLE_VIEW_FINDER_MODE;		           
            RESZ_Stop(scene_id); 
            RESZ_Close(scene_id);
            
            intmem_deinit();
            extmem_deinit();
#endif      
      
   }
   else if (usbvideo_cam_operation_state!=USBVIDEO_CAM_STANDBY_STATE)
      ASSERT(0);
#if (!defined(DRV_ISP_6225_SERIES))			                 
   jpeg_codec_power_down();
#endif
}	/* exit_usbvideo_camera_preview() */

/*************************************************************************
* FUNCTION
*	usbvideo_camera_capture
*
* DESCRIPTION
*	This function start camera capture
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
kal_bool usbvideo_camera_capture(usbvideo_camera_process_struct *usbvideo_param)
{
	if (sensor_err_check<0)
		return KAL_FALSE;
	
	if (usbvideo_cam_operation_state != USBVIDEO_CAM_STANDBY_STATE)
		ASSERT(0);

	g_usbvideo_cam_buff = USBVideo_Get_Still_Buffer();		
	if(g_usbvideo_cam_buff!=NULL)
	{	
   	g_usbvideo_cam_size = usbvideo_param->target_size_enum;
   	g_usbvideo_camera_data.target_width = STILL_SIZE[g_usbvideo_cam_size-1].width;
   	g_usbvideo_camera_data.target_height = STILL_SIZE[g_usbvideo_cam_size-1].height;
   	g_usbvideo_camera_data.target_buffer_size = STILL_SIZE[g_usbvideo_cam_size-1].max_frame_size;

		ENABLE_CMOS_SESNOR;
		config_usbvideo_preview_jpeg(usbvideo_param);
		usbvideo_cam_operation_state=USBVIDEO_CAM_CAPTURE_STATE;
		// Update attr
		usbvideo_camera_update_attr();	
		SET_CAMERA_CAPTURE_MODE;
		SET_CAMERA_FRAME_RATE(0);
		ENABLE_VIEW_FINDER_MODE;
		return KAL_TRUE;		
	}
	return KAL_TRUE;			
}	/* usbvideo_camera_capture() */

/*************************************************************************
* FUNCTION
*	exit_usbvideo_camera_capture
*
* DESCRIPTION
*	This function exit camera capture
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
void exit_usbvideo_camera_capture(void)
{
	if (sensor_err_check<0)
		return ;
	
	if (usbvideo_cam_operation_state==USBVIDEO_CAM_CAPTURE_STATE)
	{
   	kal_uint32 save_irq_mask;

     	save_irq_mask=SaveAndSetIRQMask();
   	usbvideo_cam_operation_state=USBVIDEO_CAM_STANDBY_STATE;
  	   RestoreIRQMask(save_irq_mask);

#if (!defined(YUV_SENSOR_SUPPORT))	
   	ae_on_off(KAL_FALSE);
   	awb_on_off(KAL_FALSE);
#endif
#if  (!defined(DRV_ISP_6225_SERIES))
      if(jpeg_encoder_operation_state==JPEG_ENCODER_ENCODING_STATE)
      {
   		kal_uint32 i;      	
   		/* wait until JPEG encode completely */
   		for (i=0;i<20;i++)
   		{
   			kal_sleep_task(20);
				if ((jpeg_encoder_encode_result & JPEG_ENCODE_STALL)||
					 (jpeg_encoder_encode_result & JPEG_ENCODE_DONE))
   				i=100;
   		}
   		DISABLE_CMOS_SESNOR;
   		DISABLE_VIEW_FINDER_MODE;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))   	
   		RESZ_Stop(scene_id);
   		RESZ_Close(scene_id);

   		clean_imgprc_coefficient(scene_id);
   		IMGPROC_Stop(scene_id);
   		IMGPROC_Close(scene_id);

   		stop_image_dma(scene_id);
   		IMGDMA_Close(scene_id);

   		intmem_deinit();
   		extmem_deinit();
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
			close_image_data_path(scene_id);
			jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;
#endif            
      }
#elif (defined(DRV_ISP_6225_SERIES))			           
            RESZ_Stop(scene_id); 
            RESZ_Close(scene_id);
            
            intmem_deinit();
            extmem_deinit();
#endif            
      
	}
	else if (usbvideo_cam_operation_state!=USBVIDEO_CAM_STANDBY_STATE)
		ASSERT(0);
#if (!defined(DRV_ISP_6225_SERIES))			                 		
   jpeg_codec_power_down();		
#endif      
}	/* usbvideo_camera_capture() */

#if  (!defined(DRV_ISP_6225_SERIES))
static void usbvideo_camera_frame_timeout(void *parameter)
{
	GPTI_StopItem(usbvideo_camera_jpeg_timer_handle);	
	
	if((usbvideo_cam_operation_state==USBVIDEO_CAM_OFF_STATE) ||
		(usbvideo_cam_operation_state==USBVIDEO_CAM_STANDBY_STATE))
		return;
	
	if ((*(volatile unsigned int *) 0x80690000) & 0x10000)
	{
		DISABLE_VIEW_FINDER_MODE;
#if  (defined(DRV_ISP_6219_SERIES))
		*((volatile unsigned int *) 0x80610004) = 0x600000;
		*((volatile unsigned int *) 0x80610004) = 0x60;
#elif  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
		*((volatile unsigned int *) 0x80610004) = 0x60000;
		*((volatile unsigned int *) 0x80610004) = 0x6;
#endif		
		RESET_JPEG_ENCODER;
		ENABLE_JPEG_ENCODER;
		ENABLE_VIEW_FINDER_MODE;
		usbvideo_camera_jpeg_timer++;
		GPTI_StartItem(usbvideo_camera_jpeg_timer_handle, 73, usbvideo_camera_frame_timeout, NULL);								
	}		
	else
	{
	   jpeg_encode_config_data.image_quality=JPEG_ENCODER_POOR_QUALITY;		
		usbvideo_camera_frame_ready();
	}		
	// If retry too many times, ASSERT
	if(usbvideo_camera_jpeg_timer>50)
		ASSERT(0);
}

/*************************************************************************
* FUNCTION
*	usbvideo_camera_frame_ready
*
* DESCRIPTION
*	This function complete frame(HISR) and get next video buffer
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
void usbvideo_camera_frame_ready(void)
{
	kal_uint32 time=0;
#if (defined(DRV_ISP_6228_SERIES))
/* For WEBCAM MT6228+TG sync AE/AWB frame ready and jpeg encode interrupt sync */
   if(tg_interrupt_flag==KAL_TRUE)
   {
      if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
      {  // Check only with WEBCAM preview mode
      if((usbvideo_camera_fr_flag!=KAL_TRUE)||(usbvideo_camera_jpeg_flag!=KAL_TRUE))
         return;
      else
      {  // clean flags and start toggle next frame
         usbvideo_camera_fr_flag=KAL_FALSE;
         usbvideo_camera_jpeg_flag = KAL_FALSE;
      }
   }
   }
#endif
	// JPEG Encode Done
	if(usbvideo_camera_jpeg_timer>0)
	{
		usbvideo_camera_jpeg_timer = 0;						
		jpeg_encoder_encode_result = 0;
		jpeg_file_size = 0;		
		usbvideo_complete_flag = KAL_FALSE;
	}		
	else if(jpeg_encoder_encode_result&JPEG_ENCODE_DONE)
	{
		time = GPT_return_current_count();
		jpeg_file_size = DRV_Reg32(JPEG_ENCODER_DMA_ADDR_REG)-DRV_Reg32(JPEG_ENCODER_DEST_ADDR_REG);
		usbvideo_complete_flag = KAL_TRUE;
	}
	else if(jpeg_encoder_encode_result&JPEG_ENCODE_STALL)
	{
		jpeg_encoder_encode_result = 0;
		jpeg_file_size = 0;		
		usbvideo_complete_flag = KAL_FALSE;
		usbvideo_camera_jpeg_timer = 0;		
		GPTI_StartItem(usbvideo_camera_jpeg_timer_handle, 100, usbvideo_camera_frame_timeout, NULL);
		return;
	}

	DISABLE_VIEW_FINDER_MODE;
	SET_CAMERA_PREVIEW_MODE;
#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	if((REG_ISP_INT_ENABLE & REG_CAMERA_INT_FLASH_DONE_ENABLE_BIT)== 0)
	{
    	if( ae_count==camera_oper_data.ae_setting_cal_delay_frame ) 
    		DISABLE_AE_COUNT;
    }    		
#elif (defined(DRV_ISP_6228_SERIES))
	if((REG_ISP_INT_ENABLE & REG_CAMERA_INT_VSYNC_ENABLE_BIT)== 0)
	{
    	if( ae_count==camera_oper_data.ae_setting_cal_delay_frame ) 
    		DISABLE_AE_COUNT;
    }    				
#endif		
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
	DISABLE_CMOS_SESNOR;
#endif

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);

	//clean_imgprc_coefficient(scene_id);
	IMGPROC_Stop(scene_id);
	IMGPROC_Close(scene_id);

	stop_image_dma(scene_id);
	IMGDMA_Close(scene_id);

	deinit_working_mem();
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	close_image_data_path(scene_id);
#endif

	jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;

	if((usbvideo_cam_operation_state==USBVIDEO_CAM_OFF_STATE) ||
		(usbvideo_cam_operation_state==USBVIDEO_CAM_STANDBY_STATE))
		return;

	if(usbvideo_complete_flag==KAL_TRUE)
	{
		if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
			USBVideo_Complete_Video_Buffer(g_usbvideo_cam_buff, jpeg_file_size, time, g_usbvideo_cam_size);
		else if(usbvideo_cam_operation_state==USBVIDEO_CAM_CAPTURE_STATE)
			USBVideo_Complete_Still_Buffer(g_usbvideo_cam_buff, jpeg_file_size, time, g_usbvideo_cam_size);			
	}

	// GetNext?
	if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
	{
		/* Get Next USB Video Buffer */
		g_usbvideo_cam_buff = USBVideo_Get_Video_Buffer();
		if(g_usbvideo_cam_buff!=NULL)
		{
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
#if (defined(DRV_ISP_6219_SERIES))	    
			if(ae_count==camera_oper_data.ae_setting_gain_delay_frame)
				ENABLE_AE_COUNT;	
#else
			if((REG_ISP_INT_ENABLE & REG_CAMERA_INT_FLASH_DONE_ENABLE_BIT)== 0)
			{    // For use Frame Ready interrupt sensor modules
				if(ae_count==camera_oper_data.ae_setting_gain_delay_frame)
					ENABLE_AE_COUNT;	
			}    		
#endif            
			/* Update desc buff addr */
			init_working_mem();

			g_usbvideo_camera_data.target_buffer_start_address = (kal_uint32) g_usbvideo_cam_buff;
			jpeg_encode_config_data.jpeg_file_start_address=g_usbvideo_camera_data.target_buffer_start_address;

			mp4_reset();
			config_image_dma(scene_id,g_usbvideo_camera_data.target_width,g_usbvideo_camera_data.target_height);
			config_jpeg_encoder(&jpeg_encode_config_data);
			config_image_processor(scene_id);
			config_pixel_resizer(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
			ENABLE_CMOS_SESNOR;
#if (defined(DRV_ISP_6228_SERIES))			
			if((REG_ISP_INT_ENABLE & REG_CAMERA_INT_VSYNC_ENABLE_BIT)== 0)
			{    // For use Frame Ready interrupt sensor modules
			if(ae_count==camera_oper_data.ae_setting_gain_delay_frame)
				ENABLE_AE_COUNT;	
			}    		
#else
			if((REG_ISP_INT_ENABLE & REG_CAMERA_INT_FLASH_DONE_ENABLE_BIT)== 0)
			{    // For use Frame Ready interrupt sensor modules
				if(ae_count==camera_oper_data.ae_setting_gain_delay_frame)
					ENABLE_AE_COUNT;	
			}    		
#endif	
			g_usbvideo_camera_data.target_buffer_start_address = (kal_uint32) g_usbvideo_cam_buff;
			ipp_capture_jpeg_data.jpeg_file_start_address1=g_usbvideo_camera_data.target_buffer_start_address;			

			open_image_data_path(scene_id);
			config_camera_usbvideo_jpeg_data_path(scene_id,&ipp_capture_jpeg_data);
#endif
			// Update effect
			usbvideo_camera_update_attr();

			usbvideo_cam_operation_state = USBVIDEO_CAM_PREVIEW_CHECK_STATE;
			jpeg_encoder_encode_result=0;

			SET_CAMERA_CAPTURE_MODE;
			ENABLE_VIEW_FINDER_MODE;
		}
		else	// Exit USB or Stop Preview
			usbvideo_cam_operation_state = USBVIDEO_CAM_STANDBY_STATE;
	}
	else
	{
		usbvideo_cam_operation_state = USBVIDEO_CAM_STANDBY_STATE;
	}
}

#elif (defined(DRV_ISP_6225_SERIES))
void usbvideo_camera_frame_ready(void)
{
	kal_uint32 time=0;
	// JPEG Encode Done
	time = GPT_return_current_count();
	jpeg_file_size=jpeg_encode_process(&sw_jpeg_encode_config_data);
	if(jpeg_file_size>0)
	    usbvideo_complete_flag = KAL_TRUE;
	else
	    usbvideo_complete_flag = KAL_FALSE;

	DISABLE_VIEW_FINDER_MODE;
	SET_CAMERA_PREVIEW_MODE;

	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);
	deinit_working_mem();

	if((usbvideo_cam_operation_state==USBVIDEO_CAM_OFF_STATE) ||
		(usbvideo_cam_operation_state==USBVIDEO_CAM_STANDBY_STATE))
		return;

	if(usbvideo_complete_flag==KAL_TRUE)
	{
		if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
			USBVideo_Complete_Video_Buffer(g_usbvideo_cam_buff, jpeg_file_size, time, g_usbvideo_cam_size);
		else if(usbvideo_cam_operation_state==USBVIDEO_CAM_CAPTURE_STATE)
			USBVideo_Complete_Still_Buffer(g_usbvideo_cam_buff, jpeg_file_size, time, g_usbvideo_cam_size);			
	}

	// GetNext?
	if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
	{
		/* Get Next USB Video Buffer */
		g_usbvideo_cam_buff = USBVideo_Get_Video_Buffer();
		if(g_usbvideo_cam_buff!=NULL)
		{
			// Update desc buff addr 
			init_working_mem();
			g_usbvideo_camera_data.target_buffer_start_address = (kal_uint32) g_usbvideo_cam_buff;
			//jpeg_encode_config_data.jpeg_file_start_address=g_usbvideo_camera_data.target_buffer_start_address;
	        sw_jpeg_encode_config_data.jpeg_file_start_address=g_usbvideo_camera_data.target_buffer_start_address;
			config_pixel_resizer(scene_id);
			// Update effect
			usbvideo_camera_update_attr();
			usbvideo_cam_operation_state = USBVIDEO_CAM_PREVIEW_CHECK_STATE;

			SET_CAMERA_CAPTURE_MODE;
			ENABLE_VIEW_FINDER_MODE;
		}
		else	// Exit USB or Stop Preview
			usbvideo_cam_operation_state = USBVIDEO_CAM_STANDBY_STATE;
	}
	else
	{
		usbvideo_cam_operation_state = USBVIDEO_CAM_STANDBY_STATE;
	}
}
#endif  // MT6225 usbvideo_camera_frame_ready
    
/*************************************************************************
 * Init / Update Attribute for ISP
 *************************************************************************/
void usbvideo_camera_init_attr(void)
{
	kal_uint32 i;
	for (i=0;i<GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX);i++)		
	{
		usbvideo_attr_PU_value_list[i] = USBVIDEO_ATTR_PARA.attr_info[i].def;
	}
	/* CT Part , Fix(Default) Attributes */
	usbvideo_cam_command_CT_map[GET_ATTR_CT_IDX(USBVIDEO_ATTRIBUTE_FOCAL_MIN)] = USBVIDEO_CAM_ATTR_FIX;
	usbvideo_cam_command_CT_map[GET_ATTR_CT_IDX(USBVIDEO_ATTRIBUTE_FOCAL_MAX)] = USBVIDEO_CAM_ATTR_FIX;
	usbvideo_cam_command_CT_map[GET_ATTR_CT_IDX(USBVIDEO_ATTRIBUTE_FOCAL_LENGTH)] = USBVIDEO_CAM_ATTR_FIX;
}

kal_uint8 usbvideo_camera_update_attr(void)
{
	kal_uint32 i;
	for (i=0;i<GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX);i++)		
	{
		if(usbvideo_cam_command_PU_map[i]==USBVIDEO_CAM_ATTR_ISP)
			usbvideo_attr_setting_PU_index |= (1<<i); 	
	}
	usbvideo_camera_effect_background_setting_attr();
	return KAL_TRUE;
}

/*************************************************************************
 * Set / Get Attribute for ISP
 *************************************************************************/
void usbvideo_camera_effect_background_setting_attr(void)
{
	kal_uint32 i;
	kal_uint32 attr_value;
	for (i=0;i<GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX);i++)
	{
		if (usbvideo_attr_setting_PU_index & (1<<i))
		{
			attr_value = usbvideo_attr_PU_value_list[i];
			if(usbvideo_cam_command_PU_map[i] == USBVIDEO_CAM_ATTR_ISP)
			{
			switch (i)
			{
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_CONTRAST):
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))			
					adjustment_brightness_contrast_para(scene_id,
						usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_BRIGHTNESS)],
						attr_value);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))					
					//isp_contrast_setting(attr_value+1);	/*ISP Range: 0~127, WEBCAM Range 0~255*/
					if(attr_value==255)
						isp_contrast_setting(255);	/*ISP Range: 0~127, WEBCAM Range 0~255*/					
					else						
						isp_contrast_setting(attr_value+1);	/*ISP Range: 0~127, WEBCAM Range 0~255*/
#endif						
				break;
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_BRIGHTNESS):
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))							
					adjustment_brightness_contrast_para(scene_id,
						attr_value,
						usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_CONTRAST)]);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))					
					isp_bright_setting(attr_value);		/*ISP Range: 0~255, WEBCAM Range 0~255*/
#endif						
				break;
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_SATURATION):
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))											
					adjustment_saturation_para(scene_id,attr_value);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))					
					SET_HUE_U_GAIN((attr_value+1)>>2);					/*ISP Default: 0x20*/
					SET_HUE_V_GAIN((attr_value+1)>>2);						
#endif					
				break;					
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_HUE_AUTO):
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))															
					if(attr_value>0)
						adjustment_hue_para(scene_id, 0);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))					
					if(attr_value>0)
						disable_adjustment_isp_hue_para();
#endif												
				break;
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_HUE):				
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))																			
					if(usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_HUE_AUTO)]==0)
					adjustment_hue_para(scene_id, attr_value);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))					
					if(usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_HUE_AUTO)]==0)
						adjustment_isp_hue_para(attr_value);						
#endif						
				break;	
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY):
#if (!defined(YUV_SENSOR_SUPPORT))					
					if(attr_value==1)	/* 50Hz */
						ae_select_band(CAM_BANDING_50HZ);
					else					/* 60Hz or Disable */
						ae_select_band(CAM_BANDING_60HZ);
#endif						
				break;													
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_SHARPNESS):
					if(attr_value==0)
					{
						DISABLE_Y_EDGE;
					}
					else
					{
						ENABLE_Y_EDGE;
						SET_Y_EDGE_GAIN(attr_value);
					}
				break;
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_GAMMA):
					if(attr_value==100)
					{
					    SET_GAMMA_B1(USBVIDEO_GAMMA_ATTR[0][0]);
					    SET_GAMMA_B2(USBVIDEO_GAMMA_ATTR[0][1]);
					    SET_GAMMA_B3(USBVIDEO_GAMMA_ATTR[0][2]);
					    SET_GAMMA_B4(USBVIDEO_GAMMA_ATTR[0][3]);					    					    
					    SET_GAMMA_B5(USBVIDEO_GAMMA_ATTR[0][4]);
					    SET_GAMMA_B6(USBVIDEO_GAMMA_ATTR[0][5]);
					    SET_GAMMA_B7(USBVIDEO_GAMMA_ATTR[0][6]);
					    SET_GAMMA_B8(USBVIDEO_GAMMA_ATTR[0][7]);					    					    
					    SET_GAMMA_B9(USBVIDEO_GAMMA_ATTR[0][8]);
					    SET_GAMMA_B10(USBVIDEO_GAMMA_ATTR[0][9]);
					    SET_GAMMA_B11(USBVIDEO_GAMMA_ATTR[0][10]);				    
					}
					else if(attr_value==160)	
					{
					    SET_GAMMA_B1(USBVIDEO_GAMMA_ATTR[1][0]);
					    SET_GAMMA_B2(USBVIDEO_GAMMA_ATTR[1][1]);
					    SET_GAMMA_B3(USBVIDEO_GAMMA_ATTR[1][2]);
					    SET_GAMMA_B4(USBVIDEO_GAMMA_ATTR[1][3]);					    					    
					    SET_GAMMA_B5(USBVIDEO_GAMMA_ATTR[1][4]);
					    SET_GAMMA_B6(USBVIDEO_GAMMA_ATTR[1][5]);
					    SET_GAMMA_B7(USBVIDEO_GAMMA_ATTR[1][6]);
					    SET_GAMMA_B8(USBVIDEO_GAMMA_ATTR[1][7]);					    					    
					    SET_GAMMA_B9(USBVIDEO_GAMMA_ATTR[1][8]);
					    SET_GAMMA_B10(USBVIDEO_GAMMA_ATTR[1][9]);
					    SET_GAMMA_B11(USBVIDEO_GAMMA_ATTR[1][10]);				    					
					}						
					else if(attr_value==220)	
					{
					    SET_GAMMA_B1(USBVIDEO_GAMMA_ATTR[2][0]);
					    SET_GAMMA_B2(USBVIDEO_GAMMA_ATTR[2][1]);
					    SET_GAMMA_B3(USBVIDEO_GAMMA_ATTR[2][2]);
					    SET_GAMMA_B4(USBVIDEO_GAMMA_ATTR[2][3]);					    					    
					    SET_GAMMA_B5(USBVIDEO_GAMMA_ATTR[2][4]);
					    SET_GAMMA_B6(USBVIDEO_GAMMA_ATTR[2][5]);
					    SET_GAMMA_B7(USBVIDEO_GAMMA_ATTR[2][6]);
					    SET_GAMMA_B8(USBVIDEO_GAMMA_ATTR[2][7]);					    					    
					    SET_GAMMA_B9(USBVIDEO_GAMMA_ATTR[2][8]);
					    SET_GAMMA_B10(USBVIDEO_GAMMA_ATTR[2][9]);
					    SET_GAMMA_B11(USBVIDEO_GAMMA_ATTR[2][10]);				    										    
					}											
				break;																						
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION):
#if (!defined(YUV_SENSOR_SUPPORT))									
					ae_set_ev(attr_value);
#endif					
				break;			
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO):
#if (!defined(YUV_SENSOR_SUPPORT))									
					if(attr_value>0)
						awb_on_off(KAL_TRUE);
					else
						awb_on_off(KAL_FALSE);											
#endif														
				break;													
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP):
#if (!defined(YUV_SENSOR_SUPPORT))									
					if(usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO)] == 0 )
					{
						if(attr_value>5800)
							awb_set_manual_gain(CAM_WB_DAYLIGHT);
						else if(attr_value>=4800)					
							awb_set_manual_gain(CAM_WB_INCANDESCENCE);											
						else if(attr_value>=3800)											
							awb_set_manual_gain(CAM_WB_FLUORESCENT);																
						else// if(attr_value>=2800)					
							awb_set_manual_gain(CAM_WB_TUNGSTEN);						
						awb_set_gain();					
					}
#endif					
				break;									
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP_AUTO):
#if (!defined(YUV_SENSOR_SUPPORT))									
					if(attr_value>0)
						awb_on_off(KAL_TRUE);
					else
						awb_on_off(KAL_FALSE);															
#endif																		
				break;													
									
				/* May Not Support*/
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP):
				break;													
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_GAIN):
				break;													
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER):
				break;									
				case GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER_LIMIT):
				break;									
				default:
				break;
			}
    		}
			usbvideo_attr_setting_PU_index &=~(1<<i);
		}
	}
}

kal_uint8 usbvideo_camera_effect_setting_attr(USBVideo_Attr_Value *attr)
{
	USBVIDEO_ATTRIBUTE_TYPE attr_type = attr->type;
	kal_uint32 attr_value = attr->value;

	// update attr PU current value
	if(attr_type>USBVIDEO_ATTRIBUTE_CT_MAX)
	{
		usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(attr_type)] = attr_value;
		usbvideo_attr_setting_PU_index |= 1<<GET_ATTR_PU_IDX(attr_type);
	}
	return KAL_TRUE;
}

kal_uint8 usbvideo_camera_effect_getting_attr(USBVideo_Attr_Value *attr)
{
	USBVIDEO_ATTRIBUTE_TYPE attr_type = attr->type;
	if(attr_type>USBVIDEO_ATTRIBUTE_CT_MAX)
	{
		switch(attr->req_type)
		{
			case USBVIDEO_REQUEST_GET_CUR:
				attr->value = usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(attr_type)];
				break;
			case USBVIDEO_REQUEST_GET_MIN:
				attr->value = USBVIDEO_ATTR_PARA.attr_info[GET_ATTR_PU_IDX(attr->type)].min;
				break;
			case USBVIDEO_REQUEST_GET_MAX:
				attr->value = USBVIDEO_ATTR_PARA.attr_info[GET_ATTR_PU_IDX(attr->type)].max;
				break;
			case USBVIDEO_REQUEST_GET_DEF:
				attr->value = USBVIDEO_ATTR_PARA.attr_info[GET_ATTR_PU_IDX(attr->type)].def;
				break;
			case USBVIDEO_REQUEST_GET_RES:
				attr->value = USBVIDEO_ATTR_PARA.attr_info[GET_ATTR_PU_IDX(attr->type)].res;
				break;
			default:
				EXT_ASSERT(0, (kal_uint32)attr->req_type, 0, 0);
				break;
		}
		return KAL_TRUE;		
	}
	else	// CT Part
	{	
		return KAL_FALSE;		
	}
}

#endif  // END_OF_WEBCAM_SUPPORT
#endif  // END_OF_ISP_SUPPORT

