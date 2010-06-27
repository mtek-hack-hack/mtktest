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
 *   isp_cct_if.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   These are interface with FT for CCT
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
 ****************************************************************************/
#include "kal_release.h" 
#include "drv_features.h"
#if ((defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))&&defined(ISP_SUPPORT))
#include "drv_comm.h"
#include "stdio.h"
#include "string.h"
#include "IntrCtrl.h"
#include "jpeg.h"
#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "visual_comm.h"
#include "img_comm.h"
#include "visualhisr.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "ae_awb.h"
#include "resizer.h"
#include "camera_para.h"
#include "isp_cct_if.h"
#include "isp_device_if.h"
#include "med_api.h"
#include "af.h"

extern camera_preview_process_struct isp_preview_config_data;
extern kal_eventgrpid camera_isp_event_id;
extern ISP_OPERATION_STATE_ENUM isp_operation_state;
extern image_sensor_exposure_window_struct exposure_window;
extern kal_uint16 image_sensor_width,image_sensor_height;
extern kal_bool wait_first_frame_flag;
extern kal_bool isp_first_preview_frame;
extern kal_uint8 isp_preview_frame;
extern kal_uint8	camera_system_operation_mode;

#if (!defined(DRV_ISP_6219_SERIES))
extern void (*cam_preview_cb) (kal_uint8 return_code);
extern void (*cam_focus_cb) (kal_uint8 return_code);
#endif

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
camera_preview_data_path_struct			ipp_cct_preview_data;
#endif
#if (defined(DRV_ISP_6227_SERIES))
kal_uint32 test_loop=0x500000;//6227 loop count for memory output delay
#else
kal_uint32 test_loop=0x0;
#endif
kal_uint16 cct_auto_defect_count;
kal_bool	switch_cap_en = 0;
/* camera_horizontal_flag for CCT */
#if (defined(HORIZONTAL_CAMERA))
kal_uint8	camera_horizontal_flag=1;
#else
kal_uint8	camera_horizontal_flag=0;
#endif
/* backup pre_adjust before defect table calibration */
#if (!defined(DRV_ISP_6219_SERIES))
	kal_uint32 cct_ob_backup;
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))	
	kal_uint32 cct_raw_backup1;
	kal_uint32 cct_raw_backup2;
#endif
	kal_uint32 cct_pregain_backup;
	kal_uint32 cct_shading_backup;
	kal_uint32 cct_sensor_gamma_backup;
#endif
/* end backup pre_adjust before defect table calibration */
// preview rotation flag 
#if defined(SENSOR_ON_COVER)
	// if sensor is on cover 
	#if defined(SENSOR_ROTATE_0)
		// normal 
		kal_uint8   g_CCT_PreviewImageMirror=IMAGE_NORMAL;
	#elif defined(SENSOR_ROTATE_180)
		// rotate 180 
		kal_uint8   g_CCT_PreviewImageMirror=IMAGE_HV_MIRROR;
	#else
		// rotate 90, 270 not used yet 
		kal_uint8   g_CCT_PreviewImageMirror=IMAGE_NORMAL;
	#endif
#else
	// if sensor is on body 
	#if defined(SENSOR_ROTATE_0)
		// normal 
		kal_uint8   g_CCT_PreviewImageMirror=IMAGE_NORMAL;
	#elif defined(SENSOR_ROTATE_180)
		// rotate 180 
		kal_uint8   g_CCT_PreviewImageMirror=IMAGE_HV_MIRROR;
	#else
		// rotate 90, 270 not used yet 
		kal_uint8   g_CCT_PreviewImageMirror=IMAGE_NORMAL;
	#endif
#endif

void init_camera_cct(kal_uint32 cct_lcd_layer0_buffer)
{
	lcd_layer_struct layer_data;
	kal_uint16 lcd_width,lcd_height;
	/* exchange order for HORIZONTAL_CAMERA */
	camera_system_operation_mode=CAMERA_SYSTEM_META_MODE;
	init_isp_if();
//	lcd_init(MAIN_LCD,0xFFFF);
	layer_data.source_key=0xFFFF;
	layer_data.source_key_enable=KAL_FALSE;
	layer_data.color_palette_enable=KAL_FALSE;
	layer_data.color_palette_select=0;
	layer_data.source_color_format=1;//6228 new config
	layer_data.opacity_enable=KAL_FALSE;
	layer_data.opacity_value=20;
	layer_data.rotate_value=LCD_LAYER_ROTATE_NORMAL;
	layer_data.x_offset=0;
	layer_data.y_offset=0;
	layer_data.frame_buffer_address=(kal_uint32)cct_lcd_layer0_buffer;
	lcd_get_size(MAIN_LCD, &lcd_width, &lcd_height);
	if (camera_horizontal_flag==1)
	{
	  	layer_data.rotate_value=LCD_LAYER_ROTATE_270;
		layer_data.row_number=lcd_width;
		layer_data.column_number=lcd_height;
	}
	else
	{
	   	layer_data.rotate_value=LCD_LAYER_ROTATE_NORMAL;
		layer_data.row_number=lcd_height;
		layer_data.column_number=lcd_width;
	}
	config_lcd_layer_window(0,&layer_data);
	/* PLEASE CALL read_camera_para_from_nvram() AFTER init_isp_if() to load calibration data */
	/* following list with related setting for CCT */
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))// save step for normal search
	AF_Backup_Normal_Step();
#endif
#if (!defined(DRV_ISP_6219_SERIES))
	Set_camera_shading_mode(CAMERA_SHADING_NORMAL_SET);//set shading LUT to default
#endif	
}

void camera_preview_cct(camera_preview_process_struct *isp_cct_data)
{
	MMDI_SCENERIO_ID scenerio_id=SCENARIO_CAMERA_PREVIEW_ID;
	kal_uint16 grab_width,grab_height;
	kal_uint16 grab_start_x,grab_start_y;
	lcd_frame_update_struct lcd_data;
	kal_uint32 event_group;
#if (defined(DRV_ISP_6219_SERIES))	
	kal_uint8 sub_sample_mode=0;
#endif	
	
	if (isp_operation_state!=ISP_STANDBY_STATE)
	ASSERT(0);

	memset(&lcd_data, 0, sizeof(lcd_frame_update_struct));	//initial lcd_data
	
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	if (af_operation_state != AF_STANDBY_STATE)//prevent scenario error
	{
  		cct_camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	}
	else
	{
		lens_func->lens_af_move_to((kal_int32)camera_lens.INFO.af_hyper_pos);
		dsc_status.af.index=0xFF;
	}
#endif

	ENABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;

#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
   // Disable AE Count before Start Preview
	DISABLE_AE_COUNT;
	REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
#endif

#if (defined(DRV_ISP_6219_SERIES))
	DISABLE_GMC_DEBUG_OUTPUT;
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))//Prevent error when back to preview
	DISABLE_CAMERA_OUTPUT_TO_MEM;
	ENABLE_REZ_LPF;
	DISABLE_REZ_DISCONN;
#endif
#if (defined(DRV_ISP_6227_SERIES))/* disable result window */
	DISABLE_RESULT_WINDOW;
#endif
	
	sensor_config_data.image_mirror=isp_cct_data->image_mirror;
	sensor_config_data.frame_rate=0xFF;
	exposure_window.digital_zoom_factor=10;
	/* LCM rotation */
	if (camera_horizontal_flag==1)
	{
		isp_preview_config_data.target_width=isp_cct_data->target_height;
		isp_preview_config_data.target_height=isp_cct_data->target_width;
	}
	else
	{
		isp_preview_config_data.target_width=isp_cct_data->target_width;
		isp_preview_config_data.target_height=isp_cct_data->target_height;
	}
	/* change order */
	isp_cct_data->target_width=isp_preview_config_data.target_width;
	isp_cct_data->target_height=isp_preview_config_data.target_height;
	/* set to prevent seneor check error */
	exposure_window.image_target_width=isp_cct_data->target_width;
	exposure_window.image_target_height=isp_cct_data->target_height;	
	/* set sensor preview */
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);

	grab_width= exposure_window.exposure_window_width &0xFFFC ;
	grab_height= exposure_window.exposure_window_height &0xFFFC ;
	grab_start_x=exposure_window.grab_start_x+ (((exposure_window.exposure_window_width-grab_width)>>1)&0xFFFE);
	grab_start_y=exposure_window.grab_start_y+ (((exposure_window.exposure_window_height-grab_height)>>1)&0xFFFE);

	/* accorind the zoom factor to calculate the grab window area */
	isp_grab_width = grab_width;
	isp_grab_height = grab_height;

	SET_TG_GRAB_PIXEL(grab_start_x,grab_width);
	SET_TG_GRAB_LINE(grab_start_y,grab_height);
	ae_config(grab_width,grab_height);

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
	DISABLE_1024_GAMMA_TABLE;
#endif
	
	isp_preview_config_data.lcd_id=isp_cct_data->lcd_id;
	isp_preview_config_data.lcm_start_x=isp_cct_data->lcm_start_x;
	isp_preview_config_data.lcm_start_y=isp_cct_data->lcm_start_y;
	isp_preview_config_data.lcm_end_x=isp_cct_data->lcm_end_x;
	isp_preview_config_data.lcm_end_y=isp_cct_data->lcm_end_y;
	isp_preview_config_data.roi_offset_x=isp_cct_data->roi_offset_x;
	isp_preview_config_data.roi_offset_y=isp_cct_data->roi_offset_y;
	isp_preview_config_data.update_layer=isp_cct_data->update_layer;
	isp_preview_config_data.hw_update_layer=isp_cct_data->hw_update_layer;
	isp_preview_config_data.intmem_start_address=isp_cct_data->intmem_start_address;
	isp_preview_config_data.intmem_size=isp_cct_data->intmem_size;
	isp_preview_config_data.extmem_start_address=isp_cct_data->extmem_start_address;
	isp_preview_config_data.extmem_size=isp_cct_data->extmem_size;
	isp_preview_config_data.zoom_factor=isp_cct_data->zoom_factor;
	isp_preview_config_data.frame_buffer_address=isp_cct_data->frame_buffer_address;
	isp_preview_config_data.frame_buffer_size=isp_cct_data->frame_buffer_size;
	isp_preview_config_data.frame_buffer_address1=isp_cct_data->frame_buffer_address1;
	isp_preview_config_data.frame_buffer_size1=isp_cct_data->frame_buffer_size1;
 	isp_preview_config_data.cam_preview_cb=isp_cct_data->cam_preview_cb;
#if (!defined(DRV_ISP_6219_SERIES))
	cam_preview_cb=isp_cct_data->cam_preview_cb;

#endif

	isp_preview_config_data.preview_offset_x=isp_cct_data->preview_offset_x;
	isp_preview_config_data.preview_offset_y=isp_cct_data->preview_offset_y;

	isp_preview_config_data.camera_offset_x=isp_cct_data->camera_offset_x;
	isp_preview_config_data.camera_offset_y=isp_cct_data->camera_offset_y;

	isp_preview_config_data.contrast_level=isp_cct_data->contrast_level;
	isp_preview_config_data.brightness_level=isp_cct_data->brightness_level;
	isp_preview_config_data.hue_value=isp_cct_data->hue_value;
	isp_preview_config_data.saturation_value=isp_cct_data->saturation_value;
	isp_preview_config_data.wb_mode=isp_cct_data->wb_mode;
	isp_preview_config_data.ev_value=isp_cct_data->ev_value;
	isp_preview_config_data.banding_freq=isp_cct_data->banding_freq;
	isp_preview_config_data.image_effect=isp_cct_data->image_effect;
	isp_preview_config_data.night_mode=isp_cct_data->night_mode;
	
#if (!defined(DRV_ISP_6219_SERIES))
	/* ISP Setting */
	isp_preview_config_data.dsc_mode      				= isp_cct_data->dsc_mode;
	isp_preview_config_data.ae_metering_mode 		= isp_cct_data->ae_metering_mode;
	isp_preview_config_data.af_mode      				= isp_cct_data->af_mode;
	isp_preview_config_data.af_metering_mode 			= isp_cct_data->af_metering_mode;
	isp_preview_config_data.tv_setting      				= isp_cct_data->tv_setting;
	isp_preview_config_data.av_setting      				= isp_cct_data->av_setting;
	isp_preview_config_data.iso_setting      			= isp_cct_data->iso_setting;
	isp_preview_config_data.flash_mode      			= isp_cct_data->flash_mode;
	if (camera_horizontal_flag==1)
	{	
		isp_preview_config_data.af_zone0_x      			= isp_cct_data->af_zone0_y;
		isp_preview_config_data.af_zone0_y      			= isp_cct_data->af_zone0_x;
		isp_preview_config_data.af_zone1_x      			= isp_cct_data->af_zone1_y;
		isp_preview_config_data.af_zone1_y      			= isp_cct_data->af_zone1_x;
		isp_preview_config_data.af_zone2_x      			= isp_cct_data->af_zone2_y;
		isp_preview_config_data.af_zone2_y      			= isp_cct_data->af_zone2_x;
		isp_preview_config_data.af_zone3_x      			= isp_cct_data->af_zone3_y;
		isp_preview_config_data.af_zone3_y      			= isp_cct_data->af_zone3_x;
		isp_preview_config_data.af_zone4_x      			= isp_cct_data->af_zone4_y;
		isp_preview_config_data.af_zone4_y      			= isp_cct_data->af_zone4_x;
	}
	else
	{
		isp_preview_config_data.af_zone0_x      			= isp_cct_data->af_zone0_x;
		isp_preview_config_data.af_zone0_y      			= isp_cct_data->af_zone0_y;
		isp_preview_config_data.af_zone1_x      			= isp_cct_data->af_zone1_x;
		isp_preview_config_data.af_zone1_y      			= isp_cct_data->af_zone1_y;
		isp_preview_config_data.af_zone2_x      			= isp_cct_data->af_zone2_x;
		isp_preview_config_data.af_zone2_y      			= isp_cct_data->af_zone2_y;
		isp_preview_config_data.af_zone3_x      			= isp_cct_data->af_zone3_x;
		isp_preview_config_data.af_zone3_y      			= isp_cct_data->af_zone3_y;
		isp_preview_config_data.af_zone4_x      			= isp_cct_data->af_zone4_x;
		isp_preview_config_data.af_zone4_y      			= isp_cct_data->af_zone4_y;
	}
	isp_preview_config_data.cam_focus_cb				= isp_cct_data->cam_focus_cb;
	cam_focus_cb= isp_cct_data->cam_focus_cb;	
#endif

#if (defined(DRV_ISP_6219_SERIES))
	/* according the maximum size of resizer input we define to calculate the the image size
	   of resizer input */
	if ((grab_width<=MAX_RESIZER_INPUT_WIDTH) && (grab_height<=MAX_RESIZER_INPUT_HEIGHT))
	{
		sub_sample_mode=CAMERA_SUB_SAMPLE_1_1;
		isp_preview_config_data.source_width=grab_width;
		isp_preview_config_data.source_height=grab_height;
	}
	else if ((grab_width<=(MAX_RESIZER_INPUT_WIDTH<<1)) && (grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<1)))
	{
		sub_sample_mode=CAMERA_SUB_SAMPLE_1_2;
		isp_preview_config_data.source_width=grab_width>>1;
		isp_preview_config_data.source_height=grab_height>>1;
	}
	else if ((grab_width<=(MAX_RESIZER_INPUT_WIDTH<<2)) && (grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<2)))
	{
		sub_sample_mode=CAMERA_SUB_SAMPLE_1_4;
		isp_preview_config_data.source_width=grab_width>>2;
		isp_preview_config_data.source_height=grab_height>>2;
	}
	else if ((grab_width<=(MAX_RESIZER_INPUT_WIDTH<<3)) && (grab_height<=(MAX_RESIZER_INPUT_HEIGHT<<3)))
	{
		sub_sample_mode=CAMERA_SUB_SAMPLE_1_8;
		isp_preview_config_data.source_width=grab_width>>3;
		isp_preview_config_data.source_height=grab_height>>3;
	}
	SET_SUB_SAMPLE_MODE(sub_sample_mode);
#else
	ENABLE_VERTICAL_SUB_SAMPLE;
	ENABLE_HORIZONTAL_SUB_SAMPLE;
	SET_HSUB_SRC_SIZE(grab_width);	
	SET_VSUB_SRC_SIZE(grab_height);
	if((grab_width>=(isp_preview_config_data.target_width<<2)) ||
		(grab_height>=(isp_preview_config_data.target_height<<2)))
	{
		SET_HSUB_DST_SIZE(isp_preview_config_data.target_width<<1);				  
		SET_VSUB_DST_SIZE(isp_preview_config_data.target_height<<1);
		isp_preview_config_data.source_width=isp_preview_config_data.target_width<<1;
		isp_preview_config_data.source_height=isp_preview_config_data.target_height<<1;
	}
	else
	{
		SET_HSUB_DST_SIZE(grab_width);				  
		SET_VSUB_DST_SIZE(grab_height);
		isp_preview_config_data.source_width=grab_width;
		isp_preview_config_data.source_height=grab_height;
	}
#endif

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))	
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

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	isp_preview_config_data.ae_metering_mode 			= isp_cct_data->ae_metering_mode;	
	isp_preview_config_data.iso_setting      			= isp_cct_data->iso_setting;	

	/* Prepare IPP Data */
	ipp_cct_preview_data.intmem_start_address 				= isp_cct_data->intmem_start_address;
	ipp_cct_preview_data.intmem_size          				= isp_cct_data->intmem_size;         	
	ipp_cct_preview_data.extmem_start_address 				= isp_cct_data->extmem_start_address;	
	ipp_cct_preview_data.extmem_size          				= isp_cct_data->extmem_size;         	
	                                       			
	ipp_cct_preview_data.image_src_width		 				= isp_preview_config_data.source_width;
	ipp_cct_preview_data.image_src_height	 				= isp_preview_config_data.source_height;
	ipp_cct_preview_data.preview_width		 				= isp_preview_config_data.target_width;
	ipp_cct_preview_data.preview_height	 					= isp_preview_config_data.target_height;
                                          			
	ipp_cct_preview_data.image_pitch_mode  					= isp_cct_data->image_pitch_mode;	
	ipp_cct_preview_data.image_data_format 					= isp_cct_data->image_data_format;	
	ipp_cct_preview_data.image_pitch_bytes 					= isp_cct_data->image_pitch_bytes;	
	
	ipp_cct_preview_data.overlay_frame_mode			= KAL_FALSE;			
	
	ipp_cct_preview_data.frame_buffer_address			= isp_cct_data->frame_buffer_address;	
	ipp_cct_preview_data.frame_buffer_size				= isp_cct_data->frame_buffer_size;	
	ipp_cct_preview_data.frame_buffer_address1		= isp_cct_data->frame_buffer_address;
	ipp_cct_preview_data.frame_buffer_size1			= isp_cct_data->frame_buffer_size;
	ipp_cct_preview_data.tv_output                  = KAL_FALSE;                       
	
	/* Prepare LCD Data */
	lcd_data.roi_background_color 						= isp_cct_data->roi_background_color;	
	lcd_data.hw_trigger_src 								= LCD_HW_TRIGGER_IBW2;	
   lcd_data.tv_output										= KAL_FALSE;      			      	
   lcd_data.memory_output									= KAL_FALSE;
   lcd_data.block_mode_flag								= KAL_TRUE;
#endif

	lcd_fb_update(&lcd_data);

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))	
	config_image_dma(scenerio_id,isp_cct_data->target_width,isp_cct_data->target_height);
	config_image_processor(scenerio_id);
	config_pixel_resizer(scenerio_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES)) 
	open_image_data_path(scenerio_id);
	config_camera_preview_data_path(scenerio_id,&ipp_cct_preview_data);
#endif	

	isp_operation_state=ISP_PREVIEW_STATE;

#if (!defined(DRV_ISP_6219_SERIES))	
	/* camera operation setting */
	camera_operation_setting(CAM_DSC_MODE,isp_preview_config_data.dsc_mode);
	camera_operation_setting(CAM_AE_METERING,isp_preview_config_data.ae_metering_mode);
	camera_operation_setting(CAM_AF_MODE,isp_preview_config_data.af_mode);
	camera_operation_setting(CAM_AF_METERING,isp_preview_config_data.af_metering_mode);
	camera_operation_setting(CAM_SHUTTER_PRIORITY,isp_preview_config_data.tv_setting);
	camera_operation_setting(CAM_APERTURE_PRIORITY,isp_preview_config_data.av_setting);
	camera_operation_setting(CAM_ISO,isp_preview_config_data.iso_setting);
	camera_operation_setting(CAM_FLASH_MODE,isp_preview_config_data.flash_mode);
#endif

/* disable gamma 1024 */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	DISABLE_1024_GAMMA_TABLE
#endif

	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
	wait_first_frame_flag=KAL_TRUE;
	isp_preview_frame=0;
	SET_CAMERA_PREVIEW_MODE;
	SET_CAMERA_FRAME_RATE(0);
#if  (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES)||defined(DRV_ISP_6228_SERIES))
   // Enable AE Count before Start Preview
	REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
	ENABLE_AE_COUNT;
#endif
#if  (defined(DRV_ISP_6228_SERIES))
	RESET_ISP;
	CLEAR_RESET_ISP;
#endif
	ENABLE_VIEW_FINDER_MODE;
	
	
	/* wait sensor first frame coming */
#if (defined(DRV_ISP_6219_SERIES))
  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_FRAME_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);
#else
  	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
     	                    &event_group,KAL_SUSPEND);
#endif
     	                    
   isp_first_preview_frame=KAL_FALSE;
	switch_cap_en = KAL_TRUE;   
}

kal_uint8 camera_capture_cct(camera_capture_cct_struct *isp_cct_data)
{
	kal_uint32 event_group;
	kal_int16 isp_grab_start_x,isp_grab_start_y;
	kal_uint32 isp_capture_shutter;
	kal_uint16 isp_capture_pregain;
	kal_uint32 i;
	kal_uint8 ret_code = KAL_TRUE;	
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
	kal_uint8 sub_sample=0;
#endif	
	
	if (isp_operation_state!=ISP_STANDBY_STATE)
	ASSERT(0);

	ENABLE_CMOS_SESNOR;

#if (!defined(DRV_ISP_6219_SERIES))		
	if(isp_cct_data->flash_mode!=CAM_FLASH_OFF)
	{
        isp_device_flashligh_enable(KAL_TRUE);
	    isp_device_flashligh_prestrobe(isp_cct_data);
    }
#endif

	exposure_window.image_target_width=isp_cct_data->grab_width;
	exposure_window.image_target_height=isp_cct_data->grab_height;
	exposure_window.digital_zoom_factor=10;
	
	if(switch_cap_en == KAL_TRUE)
	{
	if(camera_oper_data.enable_cap_shutter_compensate==KAL_TRUE)
	{
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
	}
	else
		sensor_config_data.enable_shutter_tansfer=KAL_FALSE;
    	// meta mode capture		
    	if((isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_8BIT)||   // EXT Capture
    	   (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_10BIT)||
           (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_YUV)||
           (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB888)||
    	   (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB565)) 
    		sensor_config_data.meta_mode = CAPTURE_MODE_META_EXT;	
    	else		
    		sensor_config_data.meta_mode = CAPTURE_MODE_META;	
#if (!defined(DRV_ISP_6219_SERIES))
        if(isp_cct_data->flash_mode!=CAM_FLASH_OFF)
        {
            ret_code = isp_device_flashligh_aeawb(isp_cct_data);
            sensor_config_data.enable_flashlight_tansfer = KAL_TRUE;
    		sensor_config_data.meta_mode = CAPTURE_MODE_META;	
        }
#endif
	image_sensor_func->sensor_capture_setting(&exposure_window,&sensor_config_data);
	}

	isp_grab_start_x=exposure_window.grab_start_x;
	isp_grab_start_y=exposure_window.grab_start_y;

#if (defined(DRV_ISP_6219_SERIES))
	SET_TG_GRAB_PIXEL(isp_grab_start_x+(isp_cct_data->grab_start_x),isp_cct_data->grab_width);
	SET_TG_GRAB_LINE(isp_grab_start_y+(isp_cct_data->grab_start_y),isp_cct_data->grab_height);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	if((isp_cct_data->debug_mode == CAPTRUE_MODE_YUV)||   // YUV Capture
       (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_YUV))
	{
		SET_TG_GRAB_PIXEL(isp_grab_start_x+(isp_cct_data->grab_start_x),isp_cct_data->grab_width);
		SET_TG_GRAB_LINE(isp_grab_start_y+(isp_cct_data->grab_start_y),isp_cct_data->grab_height);
	}
	else if((isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_8BIT)|| // RAW/RGB output
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_10BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_8BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_10BIT)||
            (isp_cct_data->debug_mode == CAPTRUE_MODE_RGB888)||
            (isp_cct_data->debug_mode == CAPTRUE_MODE_RGB565)||            	        
            (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB888)||
     	    (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB565)) 
	{
		SET_TG_GRAB_PIXEL(isp_grab_start_x+(isp_cct_data->grab_start_x),(isp_cct_data->grab_width)+4-6);
		SET_TG_GRAB_LINE(isp_grab_start_y+(isp_cct_data->grab_start_y),(isp_cct_data->grab_height)+2-6);		
	}
#elif (defined(DRV_ISP_6227_SERIES))
	if((isp_cct_data->debug_mode == CAPTRUE_MODE_YUV)||   // YUV Capture
       (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_YUV))
	{
		/* set grab window with full size for shading work around */
		SET_TG_GRAB_PIXEL(isp_grab_start_x,exposure_window.exposure_window_width);
		SET_TG_GRAB_LINE(isp_grab_start_y,exposure_window.exposure_window_height);
	}
	else if((isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_8BIT)|| // RAW/RGB output
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_10BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_8BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_10BIT)||
            (isp_cct_data->debug_mode == CAPTRUE_MODE_RGB888)||
            (isp_cct_data->debug_mode == CAPTRUE_MODE_RGB565)||            	        
            (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB888)||
     	    (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB565)) 
	{
		SET_TG_GRAB_PIXEL(isp_grab_start_x+(isp_cct_data->grab_start_x),isp_cct_data->grab_width);
		SET_TG_GRAB_LINE(isp_grab_start_y+(isp_cct_data->grab_start_y),isp_cct_data->grab_height+2-4);
	}
#endif
/* set gamma 1024 */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	apply_take_image_with_gamma_1024_by_flag();
#endif

#if (defined(DRV_ISP_6219_SERIES))	
	SET_SUB_SAMPLE_MODE(isp_cct_data->sub_sample_mode);
	
	if((isp_cct_data->debug_mode == CAPTRUE_MODE_YUV)||   // YUV Capture
       (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_YUV))	
	{
		/* YUV ouput */
		SET_GMC_RGB565_MODE;	
	}
	else if((isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_8BIT)|| // RAW/RGB output
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_10BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_8BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_10BIT)||
            (isp_cct_data->debug_mode == CAPTRUE_MODE_RGB888)||
            (isp_cct_data->debug_mode == CAPTRUE_MODE_RGB565)||            	        
            (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB888)||
     	    (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB565)) 
	{
		/* Bayer output */
		SET_GMC_RAW_RGB_MODE;	
	}
	REG_ISP_DEBUG_WRITE_OUT_ADDR=(kal_uint32) (isp_cct_data->isp_debug_buffer);
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))	
	ENABLE_REZ_DISCONN;
	DISABLE_REZ_LPF;
	if((isp_cct_data->debug_mode == CAPTRUE_MODE_YUV)||   // YUV Capture
       (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_YUV))	
	{
		/* YUV ouput */
    	SET_OUTPUT_PATH_TYPE(1);	/* 0:bayer, 1:ISP output, 2:RGB888, 3:RGB565 */
	}
	else if((isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_8BIT)|| // RAW/RGB output
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_8BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_10BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_10BIT))
	{
		/* Bayer output */
    	SET_OUTPUT_PATH_TYPE(0);	/* 0:bayer, 1:ISP output, 2:RGB888, 3:RGB565 */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))	    			
    	if(	(isp_cct_data->debug_mode == CAPTRUE_MODE_RAW_10BIT)||
	        (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RAW_10BIT))
        {	        
    	    ENABLE_BAYER10_OUT;	        /* Bayer 10bit output */        
        }
        else    	    
	{
        	DISABLE_BAYER10_OUT;
        }
#endif    	    	
	}	
	else if((isp_cct_data->debug_mode == CAPTRUE_MODE_RGB888)||
            (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB888))
    {
    	SET_OUTPUT_PATH_TYPE(2);	/* 0:bayer, 1:ISP output, 2:RGB888, 3:RGB565 */        
    }	
    else if((isp_cct_data->debug_mode == CAPTRUE_MODE_RGB565)||            	                    
     	    (isp_cct_data->debug_mode == CAPTRUE_MODE_EXT_RGB565))         
    {            
    	SET_OUTPUT_PATH_TYPE(3);	/* 0:bayer, 1:ISP output, 2:RGB888, 3:RGB565 */                    
    }
	REG_ISP_OUTPUT_ADDR=(kal_uint32)(isp_cct_data->isp_debug_buffer);
    if( (isp_cct_data->debug_mode != CAPTRUE_MODE_RAW_8BIT)&& // RAW/RGB output
	    (isp_cct_data->debug_mode != CAPTRUE_MODE_EXT_RAW_8BIT)&&
	    (isp_cct_data->debug_mode != CAPTRUE_MODE_RAW_10BIT)&&
	    (isp_cct_data->debug_mode != CAPTRUE_MODE_EXT_RAW_10BIT))
	{
		if(isp_cct_data->sub_sample_mode==4)
			sub_sample=3;
		else
			sub_sample=isp_cct_data->sub_sample_mode;
		ENABLE_VERTICAL_SUB_SAMPLE;
		ENABLE_HORIZONTAL_SUB_SAMPLE;
		SET_HSUB_SRC_SIZE(isp_cct_data->grab_width);
		SET_VSUB_SRC_SIZE(isp_cct_data->grab_height);
		SET_HSUB_DST_SIZE((isp_cct_data->grab_width)>>sub_sample);
		SET_VSUB_DST_SIZE((isp_cct_data->grab_height)>>sub_sample);
#if (defined(DRV_ISP_6227_SERIES))
		/* enable result window for shading work around */
		SET_RESULT_WINDOW_VERTICAL_SIZE((kal_uint16)((isp_cct_data->grab_start_y)>>sub_sample),
			(kal_uint16)((isp_cct_data->grab_height)>>sub_sample));
		SET_RESULT_WINDOW_HORIZONTAL_SIZE((kal_uint16)((isp_cct_data->grab_start_x)>>sub_sample), 
			(kal_uint16)((isp_cct_data->grab_width)>>sub_sample));
		ENABLE_RESULT_WINDOW;
#endif
	}
#endif

	// skip unstable frames 
	ENABLE_CAMERA_IDLE_INT;
	SET_CAMERA_CAPTURE_MODE;
	SET_CAMERA_FRAME_RATE(0);

	if(switch_cap_en == KAL_TRUE)
	{
	for(i=0;i<camera_oper_data.capture_delay_frame;i++)
	{
		DISABLE_VIEW_FINDER_MODE;
		kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;
	
		kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
	                          &event_group,KAL_SUSPEND);
	}
		switch_cap_en = KAL_FALSE;
	}
	DISABLE_VIEW_FINDER_MODE;
	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);

	// start capture 
#if (defined(DRV_ISP_6219_SERIES))	
	ENABLE_GMC_DEBUG_OUTPUT;
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
	for(i=0;i<test_loop;i++);//delay to prevent memory corrupted
	if (test_loop>0)
		test_loop = 0;

	if(isp_cct_data->flash_mode!=CAM_FLASH_OFF)
    {
	    ret_code = isp_device_flashligh_mainstrobe(isp_cct_data);
    }
	ENABLE_CAMERA_OUTPUT_TO_MEM;
#endif
	ENABLE_VIEW_FINDER_MODE;
	
	isp_operation_state=ISP_CAPTURE_JPEG_STATE;
	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);
	/* add read auto defect count */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))	
	cct_auto_defect_count = REG_ISP_HISTOGRAM_BOUNDARY_CTRL5&0x0000FFFF;
#endif		
	DISABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;
	isp_operation_state=ISP_STANDBY_STATE;

/* disable gamma 1024 */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	DISABLE_1024_GAMMA_TABLE
#endif

#if (!defined(DRV_ISP_6219_SERIES))	
    if(isp_cct_data->flash_mode == CAM_FLASH_ON)
    {
        isp_device_flashligh_enable(KAL_FALSE);
    }
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
    return ret_code;
}

void exit_camera_preview_cct(void)
{
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_PREVIEW_ID;
	kal_uint32 j=0;;

	if (isp_operation_state!=ISP_PREVIEW_STATE)
	ASSERT(0);

#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))//prevent scenario error
	if ((af_operation_state == AF_COLLECT_STATE) || (af_operation_state == AF_SEARCH_STATE))
	{
	   	cct_camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	}
#endif

	ENABLE_CAMERA_IDLE_INT;
	DISABLE_VIEW_FINDER_MODE;

	isp_idle_done_flag=KAL_FALSE;
	while(isp_idle_done_flag==KAL_FALSE)
	{
		j++;
		kal_sleep_task(10);
		if(j>5) break;
	}

	DISABLE_CMOS_SESNOR;
	lcd_stop_hw_update(isp_preview_config_data.lcd_id);

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))	
	RESZ_Stop(scene_id);
	RESZ_Close(scene_id);

	IMGPROC_Stop(scene_id);
	IMGPROC_Close(scene_id);

	stop_image_dma(scene_id);
	IMGDMA_Close(scene_id);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	close_image_data_path(scene_id);
#endif

	isp_operation_state=ISP_STANDBY_STATE;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))	
	intmem_deinit();
	extmem_deinit();
#endif	
}

void recover_sensor_setting(void)
{
//	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);
}

void get_banding_factor(kal_uint8 *baseshutter_60hz,kal_uint8 *baseshutter_50hz)
{
	kal_uint32 pixelclk;
	kal_uint16 max_expo_width, max_expo_line;
	
#if (defined(MCU_52M)||defined(MCU_104M))
	pixelclk=((kal_uint32)(52000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));
#elif (defined(MCU_26M))
	pixelclk=((kal_uint32)(26000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));
#endif

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))	
	if((REG_ISP_TG_PHASE_COUNTER & REG_TGPC_PIXEL_CLK_SELECT_BIT)!= 0)
		pixelclk=((kal_uint32)(48000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));
#endif

	image_sensor_func->get_sensor_period(&max_expo_width, &max_expo_line);	
	*baseshutter_60hz=(kal_uint8)(pixelclk/(120*max_expo_width));
	*baseshutter_50hz=(kal_uint8)(pixelclk/(100*max_expo_width));
}

kal_uint32  isp_cct_get_isp_id(void)
{

#if defined(DRV_ISP_6219_SERIES)
	return 0x62198A01;
#elif defined(DRV_ISP_6228_SERIES)
	 // new isp function, assign a new unique id 
	 return 0x62288A00;
#elif (defined(DRV_ISP_6227_SERIES))
	 // different baseband chip but isp functionality is the same, just apply the same id
	 return 0x62278A00;
#elif(defined(DRV_ISP_6229_SERIES)) 
	return 0x62298A00;
#else
	 return 0x00000000;
#endif	
}

kal_bool  isp_cct_is_gamma_table_supported(void) {
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))//only 6226 & 6227 & 6229 can support gamma 1024
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}


void isp_cct_set_gamma_table(const kal_uint8 gamma_table[1024])
{
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	kal_uint16 i;
	kal_uint32 temp1, temp2;
	//bypass gamma
	temp1 = REG_ISP_COLOR_PROCESS_STAGE_CTRL2;//by gamma
	temp2 = REG_ISP_GAMMA_OPERATION3;//output to memory
	ENABLE_GAMMA_FUNCTION_BYPASS//disable gamma
	DISABLE_1024_GAMMA_TABLE//disable output to memory
	for(i=0;i<256;i++)//1000h~13FCh gamma table 1024
		INTMEM_GAMMA_1024(i) =
			(unsigned int)(gamma_table[i*4]|(gamma_table[i*4+1]<<8)|(gamma_table[i*4+2]<<16)|
			(gamma_table[i*4+3]<<24));
	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 = temp1;//recover gamma
	REG_ISP_GAMMA_OPERATION3 = temp2;//recover output to memory
#endif
}

void isp_cct_get_gamma_table(kal_uint8 gamma_table[1024])
{
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	kal_uint16 i;
	kal_uint32 temp1, temp2;
	//bypass gamma	
	temp1 = REG_ISP_COLOR_PROCESS_STAGE_CTRL2;//by gamma
	temp2 = REG_ISP_GAMMA_OPERATION3;//output to memory
	ENABLE_GAMMA_FUNCTION_BYPASS//disable gamma
	DISABLE_1024_GAMMA_TABLE//disable output to memory
	for(i=0;i<256;i++)//1000h~13FCh gamma table 1024
	{
		gamma_table[i*4]=INTMEM_GAMMA_1024(i)&INTMEM_GAMMA_1024_BYTE4_MASK;
		gamma_table[i*4+1]=(INTMEM_GAMMA_1024(i)&INTMEM_GAMMA_1024_BYTE3_MASK)>>8;
		gamma_table[i*4+2]=(INTMEM_GAMMA_1024(i)&INTMEM_GAMMA_1024_BYTE2_MASK)>>16;
		gamma_table[i*4+3]=(INTMEM_GAMMA_1024(i)&INTMEM_GAMMA_1024_BYTE1_MASK)>>24;			
	}
	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 = temp1;//recover gamma
	REG_ISP_GAMMA_OPERATION3 = temp2;//recover output to memory
#endif
}

kal_bool  isp_cct_is_shading_supported(void)
{
#if (!defined(DRV_ISP_6219_SERIES))
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

kal_bool  isp_cct_is_capmode_supported(kal_uint8 mode)
{
    kal_bool ret = KAL_FALSE;
    switch (mode)
	{
   		case CAPTRUE_MODE_RAW_8BIT:		        // RAW, 8Bit, capture to internal ram
           	ret = KAL_TRUE;
            break;            	   		
		case CAPTRUE_MODE_YUV:				    // YUV, capture to internal ram
           	ret = KAL_TRUE;		
            break;            			
		case CAPTRUE_MODE_EXT_RAW_8BIT:         // RAW, 8Bit, capture to external ram
            #if (defined(DRV_ISP_6219_SERIES))
            	ret = KAL_FALSE;
            #else
            	ret = KAL_TRUE;
            #endif			
            break;            			
		case CAPTRUE_MODE_EXT_YUV:			    // YUV, capture to external ram
            #if (defined(DRV_ISP_6219_SERIES))
            	ret = KAL_FALSE;
            #else
            	ret = KAL_TRUE;
            #endif			
            break;            			            
		case CAPTRUE_MODE_RAW_10BIT:			// RAW, 10Bit, capture to internal ram            
		case CAPTRUE_MODE_EXT_RAW_10BIT:		// RAW, 10Bit, capture to external ram	
            #if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES))
            	ret = KAL_FALSE;
            #else
            	ret = KAL_TRUE;
            #endif	
            break;            	
		case CAPTRUE_MODE_RGB888:			    // RGB888, capture to internal ram
		case CAPTRUE_MODE_RGB565:			    // RGB565, capture to internal ram
		case CAPTRUE_MODE_EXT_RGB888:		    // RGB888, capture to external ram
		case CAPTRUE_MODE_EXT_RGB565:			// RGB565, capture to external ram
           	ret = KAL_FALSE;
            break;          
        case CAPTRUE_MODE_JPEG:
            #if (defined(DRV_ISP_6219_SERIES))
            	ret = KAL_FALSE;
            #else
            	ret = KAL_TRUE;
            #endif	
            break;            	        
    }
    return ret;
}

/* read from global variable */
void get_camera_shading_set(cct_shading_comp_struct *p_cam_addr,	camera_comp_set_num p_set_mode)
{
#if (!defined(DRV_ISP_6219_SERIES))
	if ((p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET) ||
		(p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET))
	{
		p_cam_addr->SHADING_RANGE_EN = (camera_para.ISP.reg[Shading_Reg1_ID]&
			REG_SHADING_RANGE_ENABLE_BIT)>>29;
		p_cam_addr->SHADING_EN= (camera_para.ISP.reg[Shading_Reg1_ID]&
			REG_SHADING_ENABLE_BIT)>>28;	
		p_cam_addr->K_FACTOR= (camera_para.ISP.reg[Shading_Reg1_ID]&
			REG_SHADING_K_FACTOR_MASK)>>14;
		p_cam_addr->RADIUS_FACTOR= (camera_para.ISP.reg[Shading_Reg1_ID]&
			REG_SHADING_RADIUS_FACTOR_MASK)>>12;
		p_cam_addr->SHADING_CENTERY= (camera_para.ISP.reg[Shading_Reg1_ID]&
			REG_SHADING_CENTERY_MASK)>>16;
		p_cam_addr->SHADING_CENTERX= camera_para.ISP.reg[Shading_Reg1_ID]&
			REG_SHADING_CENTERX_MASK;		
		p_cam_addr->SHADING_RANGE_HI= (camera_para.ISP.reg[Shading_Reg1_ID]&
			0x40000000)>>30;
		p_cam_addr->SHADING_KR= (camera_para.ISP.reg[Shading_Reg1_ID+1]&
			REG_SHADING_KR_MASK)>>24;
		p_cam_addr->SHADING_KG= (camera_para.ISP.reg[Shading_Reg1_ID+1]&
			REG_SHADING_KG_MASK)>>16;
		p_cam_addr->SHADING_KB= (camera_para.ISP.reg[Shading_Reg1_ID+1]&
			REG_SHADING_KB_MASK)>>8;
		p_cam_addr->SHADING_RANGE_LO= camera_para.ISP.reg[Shading_Reg1_ID+1]&
			REG_SHADING_RANGE_MASK;		
		p_cam_addr->SHADING_CURVE_EN= (camera_para.ISP.reg[Shading_Reg1_ID+2]&
			REG_SHADING_CURVE_ENABLE_BIT)>>28;
		p_cam_addr->SHADING_CURVE_SEL= (camera_para.ISP.reg[Shading_Reg1_ID+2]&
			REG_SHADING_CURVE_SEL_MASK)>>24;		
		p_cam_addr->SHADING_GAMMA[0][0]= (camera_para.ISP.reg[Shading_Reg1_ID+2]&
			REG_SHADING_CURVE_R_B1_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[0][1]= (camera_para.ISP.reg[Shading_Reg1_ID+2]&
			REG_SHADING_CURVE_R_B2_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[0][2]= camera_para.ISP.reg[Shading_Reg1_ID+2]&
			REG_SHADING_CURVE_R_B3_MASK;
		p_cam_addr->SHADING_GAMMA[0][3]= (camera_para.ISP.reg[Shading_Reg1_ID+3]&
			REG_SHADING_CURVE_R_B4_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[0][4]= (camera_para.ISP.reg[Shading_Reg1_ID+3]&
			REG_SHADING_CURVE_R_B5_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[0][5]= (camera_para.ISP.reg[Shading_Reg1_ID+3]&
			REG_SHADING_CURVE_R_B6_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[0][6]= camera_para.ISP.reg[Shading_Reg1_ID+3]&
			REG_SHADING_CURVE_R_B7_MASK;
		p_cam_addr->SHADING_GAMMA[0][7]= (camera_para.ISP.reg[Shading_Reg1_ID+4]&
			REG_SHADING_CURVE_R_B8_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[0][8]= (camera_para.ISP.reg[Shading_Reg1_ID+4]&
			REG_SHADING_CURVE_R_B9_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[0][9]= (camera_para.ISP.reg[Shading_Reg1_ID+4]&
			REG_SHADING_CURVE_R_B10_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[0][10]= camera_para.ISP.reg[Shading_Reg1_ID+4]&
			REG_SHADING_CURVE_R_B11_MASK;
		p_cam_addr->SHADING_GAMMA[1][0]= (camera_para.ISP.reg[Shading_Reg1_ID+5]&
			REG_SHADING_CURVE_G_B1_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[1][1]= (camera_para.ISP.reg[Shading_Reg1_ID+5]&
			REG_SHADING_CURVE_G_B2_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[1][2]= (camera_para.ISP.reg[Shading_Reg1_ID+5]&
			REG_SHADING_CURVE_G_B3_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[1][3]= camera_para.ISP.reg[Shading_Reg1_ID+5]&
			REG_SHADING_CURVE_G_B4_MASK;	
		p_cam_addr->SHADING_GAMMA[1][4]= (camera_para.ISP.reg[Shading_Reg1_ID+6]&
			REG_SHADING_CURVE_G_B5_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[1][5]= (camera_para.ISP.reg[Shading_Reg1_ID+6]&
			REG_SHADING_CURVE_G_B6_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[1][6]= (camera_para.ISP.reg[Shading_Reg1_ID+6]&
			REG_SHADING_CURVE_G_B7_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[1][7]= camera_para.ISP.reg[Shading_Reg1_ID+6]&
			REG_SHADING_CURVE_G_B8_MASK;	
		p_cam_addr->SHADING_GAMMA[1][8]= (camera_para.ISP.reg[Shading_Reg1_ID+7]&
			REG_SHADING_CURVE_G_B9_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[1][9]= (camera_para.ISP.reg[Shading_Reg1_ID+7]&
			REG_SHADING_CURVE_G_B10_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[1][10]= (camera_para.ISP.reg[Shading_Reg1_ID+7]&
			REG_SHADING_CURVE_G_B11_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[2][0]= (camera_para.ISP.reg[Shading_Reg1_ID+8]&
			REG_SHADING_CURVE_B_B1_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[2][1]= (camera_para.ISP.reg[Shading_Reg1_ID+8]&
			REG_SHADING_CURVE_B_B2_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[2][2]= (camera_para.ISP.reg[Shading_Reg1_ID+8]&
			REG_SHADING_CURVE_B_B3_MASK)>>8;
		p_cam_addr->SHADING_GAMMA[2][3]= camera_para.ISP.reg[Shading_Reg1_ID+8]&
			REG_SHADING_CURVE_B_B4_MASK;
		p_cam_addr->SHADING_GAMMA[2][4]= (camera_para.ISP.reg[Shading_Reg1_ID+9]&
			REG_SHADING_CURVE_B_B5_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[2][5]= (camera_para.ISP.reg[Shading_Reg1_ID+9]&
			REG_SHADING_CURVE_B_B6_MASK)>>16;		
		p_cam_addr->SHADING_GAMMA[2][6]= (camera_para.ISP.reg[Shading_Reg1_ID+9]&
			REG_SHADING_CURVE_B_B7_MASK)>>8;
		p_cam_addr->SHADING_GAMMA[2][7]= camera_para.ISP.reg[Shading_Reg1_ID+9]&
			REG_SHADING_CURVE_B_B8_MASK;
		p_cam_addr->SHADING_GAMMA[2][8]= (camera_para.ISP.reg[Shading_Reg1_ID+10]&
			REG_SHADING_CURVE_B_B9_MASK)>>24;		
		p_cam_addr->SHADING_GAMMA[2][9]= (camera_para.ISP.reg[Shading_Reg1_ID+10]&
			REG_SHADING_CURVE_B_B10_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[2][10]= (camera_para.ISP.reg[Shading_Reg1_ID+10]&
			REG_SHADING_CURVE_B_B11_MASK)>>8;
	}
	else if ((p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET) ||
			(p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET))
	{
		p_cam_addr->SHADING_RANGE_EN = (camera_para.COMP.shading_cap[0]&
			REG_SHADING_RANGE_ENABLE_BIT)>>29;
		p_cam_addr->SHADING_EN= (camera_para.COMP.shading_cap[0]&
			REG_SHADING_ENABLE_BIT)>>28;	
		p_cam_addr->K_FACTOR= (camera_para.COMP.shading_cap[0]&
			REG_SHADING_K_FACTOR_MASK)>>14;
		p_cam_addr->RADIUS_FACTOR= (camera_para.COMP.shading_cap[0]&
			REG_SHADING_RADIUS_FACTOR_MASK)>>12;
		p_cam_addr->SHADING_CENTERY= (camera_para.COMP.shading_cap[0]&
			REG_SHADING_CENTERY_MASK)>>16;
		p_cam_addr->SHADING_CENTERX= camera_para.COMP.shading_cap[0]&
			REG_SHADING_CENTERX_MASK;		
		p_cam_addr->SHADING_RANGE_HI= (camera_para.COMP.shading_cap[0]&
			0x40000000)>>30;
		p_cam_addr->SHADING_KR= (camera_para.COMP.shading_cap[1]&
			REG_SHADING_KR_MASK)>>24;
		p_cam_addr->SHADING_KG= (camera_para.COMP.shading_cap[1]&
			REG_SHADING_KG_MASK)>>16;
		p_cam_addr->SHADING_KB= (camera_para.COMP.shading_cap[1]&
			REG_SHADING_KB_MASK)>>8;
		p_cam_addr->SHADING_RANGE_LO= camera_para.COMP.shading_cap[1]&
			REG_SHADING_RANGE_MASK;		
		p_cam_addr->SHADING_CURVE_EN= (camera_para.COMP.shading_cap[2]&
			REG_SHADING_CURVE_ENABLE_BIT)>>28;
		p_cam_addr->SHADING_CURVE_SEL= (camera_para.COMP.shading_cap[2]&
			REG_SHADING_CURVE_SEL_MASK)>>24;		
		p_cam_addr->SHADING_GAMMA[0][0]= (camera_para.COMP.shading_cap[2]&
			REG_SHADING_CURVE_R_B1_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[0][1]= (camera_para.COMP.shading_cap[2]&
			REG_SHADING_CURVE_R_B2_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[0][2]= camera_para.COMP.shading_cap[2]&
			REG_SHADING_CURVE_R_B3_MASK;
		p_cam_addr->SHADING_GAMMA[0][3]= (camera_para.COMP.shading_cap[3]&
			REG_SHADING_CURVE_R_B4_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[0][4]= (camera_para.COMP.shading_cap[3]&
			REG_SHADING_CURVE_R_B5_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[0][5]= (camera_para.COMP.shading_cap[3]&
			REG_SHADING_CURVE_R_B6_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[0][6]= camera_para.COMP.shading_cap[3]&
			REG_SHADING_CURVE_R_B7_MASK;
		p_cam_addr->SHADING_GAMMA[0][7]= (camera_para.COMP.shading_cap[4]&
			REG_SHADING_CURVE_R_B8_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[0][8]= (camera_para.COMP.shading_cap[4]&
			REG_SHADING_CURVE_R_B9_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[0][9]= (camera_para.COMP.shading_cap[4]&
			REG_SHADING_CURVE_R_B10_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[0][10]= camera_para.COMP.shading_cap[4]&
			REG_SHADING_CURVE_R_B11_MASK;
		p_cam_addr->SHADING_GAMMA[1][0]= (camera_para.COMP.shading_cap[5]&
			REG_SHADING_CURVE_G_B1_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[1][1]= (camera_para.COMP.shading_cap[5]&
			REG_SHADING_CURVE_G_B2_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[1][2]= (camera_para.COMP.shading_cap[5]&
			REG_SHADING_CURVE_G_B3_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[1][3]= camera_para.COMP.shading_cap[5]&
			REG_SHADING_CURVE_G_B4_MASK;	
		p_cam_addr->SHADING_GAMMA[1][4]= (camera_para.COMP.shading_cap[6]&
			REG_SHADING_CURVE_G_B5_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[1][5]= (camera_para.COMP.shading_cap[6]&
			REG_SHADING_CURVE_G_B6_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[1][6]= (camera_para.COMP.shading_cap[6]&
			REG_SHADING_CURVE_G_B7_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[1][7]= camera_para.COMP.shading_cap[6]&
			REG_SHADING_CURVE_G_B8_MASK;	
		p_cam_addr->SHADING_GAMMA[1][8]= (camera_para.COMP.shading_cap[7]&
			REG_SHADING_CURVE_G_B9_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[1][9]= (camera_para.COMP.shading_cap[7]&
			REG_SHADING_CURVE_G_B10_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[1][10]= (camera_para.COMP.shading_cap[7]&
			REG_SHADING_CURVE_G_B11_MASK)>>8;		
		p_cam_addr->SHADING_GAMMA[2][0]= (camera_para.COMP.shading_cap[8]&
			REG_SHADING_CURVE_B_B1_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[2][1]= (camera_para.COMP.shading_cap[8]&
			REG_SHADING_CURVE_B_B2_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[2][2]= (camera_para.COMP.shading_cap[8]&
			REG_SHADING_CURVE_B_B3_MASK)>>8;
		p_cam_addr->SHADING_GAMMA[2][3]= camera_para.COMP.shading_cap[8]&
			REG_SHADING_CURVE_B_B4_MASK;
		p_cam_addr->SHADING_GAMMA[2][4]= (camera_para.COMP.shading_cap[9]&
			REG_SHADING_CURVE_B_B5_MASK)>>24;
		p_cam_addr->SHADING_GAMMA[2][5]= (camera_para.COMP.shading_cap[9]&
			REG_SHADING_CURVE_B_B6_MASK)>>16;		
		p_cam_addr->SHADING_GAMMA[2][6]= (camera_para.COMP.shading_cap[9]&
			REG_SHADING_CURVE_B_B7_MASK)>>8;
		p_cam_addr->SHADING_GAMMA[2][7]= camera_para.COMP.shading_cap[9]&
			REG_SHADING_CURVE_B_B8_MASK;
		p_cam_addr->SHADING_GAMMA[2][8]= (camera_para.COMP.shading_cap[10]&
			REG_SHADING_CURVE_B_B9_MASK)>>24;		
		p_cam_addr->SHADING_GAMMA[2][9]= (camera_para.COMP.shading_cap[10]&
			REG_SHADING_CURVE_B_B10_MASK)>>16;
		p_cam_addr->SHADING_GAMMA[2][10]= (camera_para.COMP.shading_cap[10]&
			REG_SHADING_CURVE_B_B11_MASK)>>8;
	}
#endif
}

/* write to global variable */
void set_camera_shading_set(const cct_shading_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode)
{
#if (!defined(DRV_ISP_6219_SERIES))
	if ((p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)||
		(p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET))
	{
		camera_para.ISP.reg[Shading_Reg1_ID] &= ~(REG_SHADING_RANGE_ENABLE_BIT|REG_SHADING_ENABLE_BIT|
			REG_SHADING_K_FACTOR_MASK|REG_SHADING_RADIUS_FACTOR_MASK|
			REG_SHADING_CENTERY_MASK|REG_SHADING_CENTERX_MASK|0x40000000);
		camera_para.ISP.reg[Shading_Reg1_ID] |= (p_cam_addr->SHADING_RANGE_EN<<29)&
			REG_SHADING_RANGE_ENABLE_BIT;
		camera_para.ISP.reg[Shading_Reg1_ID] |= (p_cam_addr->SHADING_EN<<28)&
			REG_SHADING_ENABLE_BIT;	
		camera_para.ISP.reg[Shading_Reg1_ID] |= (p_cam_addr->K_FACTOR<<14)&
			REG_SHADING_K_FACTOR_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID] |= (p_cam_addr->RADIUS_FACTOR<<12)&
			REG_SHADING_RADIUS_FACTOR_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID] |= (p_cam_addr->SHADING_CENTERY<<16)&
			REG_SHADING_CENTERY_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID] |= p_cam_addr->SHADING_CENTERX &
			REG_SHADING_CENTERX_MASK;		
		camera_para.ISP.reg[Shading_Reg1_ID] |= (p_cam_addr->SHADING_RANGE_HI<<30)&
			0x40000000;
		camera_para.ISP.reg[Shading_Reg1_ID+1] &= ~(REG_SHADING_KR_MASK|REG_SHADING_KG_MASK|
			REG_SHADING_KB_MASK|REG_SHADING_RANGE_MASK);		
		camera_para.ISP.reg[Shading_Reg1_ID+1] |= (p_cam_addr->SHADING_KR<<24)&
			REG_SHADING_KR_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+1] |= (p_cam_addr->SHADING_KG<<16)&
			REG_SHADING_KG_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+1] |= (p_cam_addr->SHADING_KB<<8)&
			REG_SHADING_KB_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+1] |= p_cam_addr->SHADING_RANGE_LO&
			REG_SHADING_RANGE_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+2] &= ~(REG_SHADING_CURVE_ENABLE_BIT|REG_SHADING_CURVE_SEL_MASK|
			REG_SHADING_CURVE_R_B1_MASK|REG_SHADING_CURVE_R_B2_MASK|
			REG_SHADING_CURVE_R_B3_MASK);
		camera_para.ISP.reg[Shading_Reg1_ID+2] |= (p_cam_addr->SHADING_CURVE_EN<<28)&
			REG_SHADING_CURVE_ENABLE_BIT;
		camera_para.ISP.reg[Shading_Reg1_ID+2] |= (p_cam_addr->SHADING_CURVE_SEL<<24)&
			REG_SHADING_CURVE_SEL_MASK;		
		camera_para.ISP.reg[Shading_Reg1_ID+2] |= (p_cam_addr->SHADING_GAMMA[0][0]<<16)&
			REG_SHADING_CURVE_R_B1_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+2] |= (p_cam_addr->SHADING_GAMMA[0][1]<<8)&
			REG_SHADING_CURVE_R_B2_MASK;		
		camera_para.ISP.reg[Shading_Reg1_ID+2] |= p_cam_addr->SHADING_GAMMA[0][2]&
			REG_SHADING_CURVE_R_B3_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+3] &= ~(REG_SHADING_CURVE_R_B4_MASK|REG_SHADING_CURVE_R_B5_MASK|
			REG_SHADING_CURVE_R_B6_MASK|REG_SHADING_CURVE_R_B7_MASK);
		camera_para.ISP.reg[Shading_Reg1_ID+3] |= (p_cam_addr->SHADING_GAMMA[0][3]<<24)&
			REG_SHADING_CURVE_R_B4_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+3] |= (p_cam_addr->SHADING_GAMMA[0][4]<<16)&
			REG_SHADING_CURVE_R_B5_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+3] |= (p_cam_addr->SHADING_GAMMA[0][5]<<8)&
			REG_SHADING_CURVE_R_B6_MASK;		
		camera_para.ISP.reg[Shading_Reg1_ID+3] |= p_cam_addr->SHADING_GAMMA[0][6]&
			REG_SHADING_CURVE_R_B7_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+4] &= ~(REG_SHADING_CURVE_R_B8_MASK|REG_SHADING_CURVE_R_B9_MASK|
			REG_SHADING_CURVE_R_B10_MASK|REG_SHADING_CURVE_R_B11_MASK);
		camera_para.ISP.reg[Shading_Reg1_ID+4] |= (p_cam_addr->SHADING_GAMMA[0][7]<<24)&
			REG_SHADING_CURVE_R_B8_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+4] |= (p_cam_addr->SHADING_GAMMA[0][8]<<16)&
			REG_SHADING_CURVE_R_B9_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+4] |= (p_cam_addr->SHADING_GAMMA[0][9]<<8)&
			REG_SHADING_CURVE_R_B10_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+4] |= p_cam_addr->SHADING_GAMMA[0][10]&
			REG_SHADING_CURVE_R_B11_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+5] &= ~(REG_SHADING_CURVE_G_B1_MASK|REG_SHADING_CURVE_G_B2_MASK|
			REG_SHADING_CURVE_G_B3_MASK|REG_SHADING_CURVE_G_B4_MASK);
		camera_para.ISP.reg[Shading_Reg1_ID+5] |= (p_cam_addr->SHADING_GAMMA[1][0]<<24)&
			REG_SHADING_CURVE_G_B1_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+5] |= (p_cam_addr->SHADING_GAMMA[1][1]<<16)&
			REG_SHADING_CURVE_G_B2_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+5] |= (p_cam_addr->SHADING_GAMMA[1][2]<<8)&
			REG_SHADING_CURVE_G_B3_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+5] |= p_cam_addr->SHADING_GAMMA[1][3]&
			REG_SHADING_CURVE_G_B4_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+6] &= ~(REG_SHADING_CURVE_G_B5_MASK|REG_SHADING_CURVE_G_B6_MASK|
			REG_SHADING_CURVE_G_B7_MASK|REG_SHADING_CURVE_G_B8_MASK);	
		camera_para.ISP.reg[Shading_Reg1_ID+6] |= (p_cam_addr->SHADING_GAMMA[1][4]<<24)&
			REG_SHADING_CURVE_G_B5_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+6] |= (p_cam_addr->SHADING_GAMMA[1][5]<<16)&
			REG_SHADING_CURVE_G_B6_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+6] |= (p_cam_addr->SHADING_GAMMA[1][6]<<8)&
			REG_SHADING_CURVE_G_B7_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+6] |= p_cam_addr->SHADING_GAMMA[1][7]&
			REG_SHADING_CURVE_G_B8_MASK;	
		camera_para.ISP.reg[Shading_Reg1_ID+7] &= ~(REG_SHADING_CURVE_G_B9_MASK|REG_SHADING_CURVE_G_B10_MASK|
			REG_SHADING_CURVE_G_B11_MASK);	
		camera_para.ISP.reg[Shading_Reg1_ID+7] |= (p_cam_addr->SHADING_GAMMA[1][8]<<24)&
			REG_SHADING_CURVE_G_B9_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+7] |= (p_cam_addr->SHADING_GAMMA[1][9]<<16)&
			REG_SHADING_CURVE_G_B10_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+7] |= (p_cam_addr->SHADING_GAMMA[1][10]<<8)&			
			REG_SHADING_CURVE_G_B11_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+8] &= ~(REG_SHADING_CURVE_B_B1_MASK|REG_SHADING_CURVE_B_B2_MASK|
			REG_SHADING_CURVE_B_B3_MASK|REG_SHADING_CURVE_B_B4_MASK);			
		camera_para.ISP.reg[Shading_Reg1_ID+8] |= (p_cam_addr->SHADING_GAMMA[2][0]<<24)&
			REG_SHADING_CURVE_B_B1_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+8] |= (p_cam_addr->SHADING_GAMMA[2][1]<<16)&
			REG_SHADING_CURVE_B_B2_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+8] |= (p_cam_addr->SHADING_GAMMA[2][2]<<8)&
			REG_SHADING_CURVE_B_B3_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+8] |= p_cam_addr->SHADING_GAMMA[2][3]&
			REG_SHADING_CURVE_B_B4_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+9] &= ~(REG_SHADING_CURVE_B_B5_MASK|REG_SHADING_CURVE_B_B6_MASK|
			REG_SHADING_CURVE_B_B7_MASK|REG_SHADING_CURVE_B_B8_MASK);	
		camera_para.ISP.reg[Shading_Reg1_ID+9] |= (p_cam_addr->SHADING_GAMMA[2][4]<<24)&
			REG_SHADING_CURVE_B_B5_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+9] |= (p_cam_addr->SHADING_GAMMA[2][5]<<16)&
			REG_SHADING_CURVE_B_B6_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+9] |= (p_cam_addr->SHADING_GAMMA[2][6]<<8)&
			REG_SHADING_CURVE_B_B7_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+9] |= p_cam_addr->SHADING_GAMMA[2][7]&
			REG_SHADING_CURVE_B_B8_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+10] &= ~(REG_SHADING_CURVE_B_B9_MASK|REG_SHADING_CURVE_B_B10_MASK|
			REG_SHADING_CURVE_B_B11_MASK);			
		camera_para.ISP.reg[Shading_Reg1_ID+10] |= (p_cam_addr->SHADING_GAMMA[2][8]<<24)&
			REG_SHADING_CURVE_B_B9_MASK;		
		camera_para.ISP.reg[Shading_Reg1_ID+10] |= (p_cam_addr->SHADING_GAMMA[2][9]<<16)&
			REG_SHADING_CURVE_B_B10_MASK;
		camera_para.ISP.reg[Shading_Reg1_ID+10] |= (p_cam_addr->SHADING_GAMMA[2][10]<<8)&
			REG_SHADING_CURVE_B_B11_MASK;			
	}
	else if ((p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)||
			(p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET))
	{
		camera_para.COMP.shading_cap[0] &= ~(REG_SHADING_RANGE_ENABLE_BIT|REG_SHADING_ENABLE_BIT|
			REG_SHADING_K_FACTOR_MASK|REG_SHADING_RADIUS_FACTOR_MASK|
			REG_SHADING_CENTERY_MASK|REG_SHADING_CENTERX_MASK|0x40000000);
		camera_para.COMP.shading_cap[0] |= (p_cam_addr->SHADING_RANGE_EN<<29)&
			REG_SHADING_RANGE_ENABLE_BIT;
		camera_para.COMP.shading_cap[0] |= (p_cam_addr->SHADING_EN<<28)&
			REG_SHADING_ENABLE_BIT;	
		camera_para.COMP.shading_cap[0] |= (p_cam_addr->K_FACTOR<<14)&
			REG_SHADING_K_FACTOR_MASK;
		camera_para.COMP.shading_cap[0] |= (p_cam_addr->RADIUS_FACTOR<<12)&
			REG_SHADING_RADIUS_FACTOR_MASK;
		camera_para.COMP.shading_cap[0] |= (p_cam_addr->SHADING_CENTERY<<16)&
			REG_SHADING_CENTERY_MASK;
		camera_para.COMP.shading_cap[0] |= p_cam_addr->SHADING_CENTERX &
			REG_SHADING_CENTERX_MASK;		
		camera_para.COMP.shading_cap[0] |= (p_cam_addr->SHADING_RANGE_HI<<30)&
			0x40000000;
		camera_para.COMP.shading_cap[1] &= ~(REG_SHADING_KR_MASK|REG_SHADING_KG_MASK|
			REG_SHADING_KB_MASK|REG_SHADING_RANGE_MASK);		
		camera_para.COMP.shading_cap[1] |= (p_cam_addr->SHADING_KR<<24)&
			REG_SHADING_KR_MASK;
		camera_para.COMP.shading_cap[1] |= (p_cam_addr->SHADING_KG<<16)&
			REG_SHADING_KG_MASK;
		camera_para.COMP.shading_cap[1] |= (p_cam_addr->SHADING_KB<<8)&
			REG_SHADING_KB_MASK;
		camera_para.COMP.shading_cap[1] |= p_cam_addr->SHADING_RANGE_LO&
			REG_SHADING_RANGE_MASK;
		camera_para.COMP.shading_cap[2] &= ~(REG_SHADING_CURVE_ENABLE_BIT|REG_SHADING_CURVE_SEL_MASK|
			REG_SHADING_CURVE_R_B1_MASK|REG_SHADING_CURVE_R_B2_MASK|
			REG_SHADING_CURVE_R_B3_MASK);
		camera_para.COMP.shading_cap[2] |= (p_cam_addr->SHADING_CURVE_EN<<28)&
			REG_SHADING_CURVE_ENABLE_BIT;
		camera_para.COMP.shading_cap[2] |= (p_cam_addr->SHADING_CURVE_SEL<<24)&
			REG_SHADING_CURVE_SEL_MASK;		
		camera_para.COMP.shading_cap[2] |= (p_cam_addr->SHADING_GAMMA[0][0]<<16)&
			REG_SHADING_CURVE_R_B1_MASK;
		camera_para.COMP.shading_cap[2] |= (p_cam_addr->SHADING_GAMMA[0][1]<<8)&
			REG_SHADING_CURVE_R_B2_MASK;		
		camera_para.COMP.shading_cap[2] |= p_cam_addr->SHADING_GAMMA[0][2]&
			REG_SHADING_CURVE_R_B3_MASK;
		camera_para.COMP.shading_cap[3] &= ~(REG_SHADING_CURVE_R_B4_MASK|REG_SHADING_CURVE_R_B5_MASK|
			REG_SHADING_CURVE_R_B6_MASK|REG_SHADING_CURVE_R_B7_MASK);
		camera_para.COMP.shading_cap[3] |= (p_cam_addr->SHADING_GAMMA[0][3]<<24)&
			REG_SHADING_CURVE_R_B4_MASK;
		camera_para.COMP.shading_cap[3] |= (p_cam_addr->SHADING_GAMMA[0][4]<<16)&
			REG_SHADING_CURVE_R_B5_MASK;
		camera_para.COMP.shading_cap[3] |= (p_cam_addr->SHADING_GAMMA[0][5]<<8)&
			REG_SHADING_CURVE_R_B6_MASK;		
		camera_para.COMP.shading_cap[3] |= p_cam_addr->SHADING_GAMMA[0][6]&
			REG_SHADING_CURVE_R_B7_MASK;
		camera_para.COMP.shading_cap[4] &= ~(REG_SHADING_CURVE_R_B8_MASK|REG_SHADING_CURVE_R_B9_MASK|
			REG_SHADING_CURVE_R_B10_MASK|REG_SHADING_CURVE_R_B11_MASK);
		camera_para.COMP.shading_cap[4] |= (p_cam_addr->SHADING_GAMMA[0][7]<<24)&
			REG_SHADING_CURVE_R_B8_MASK;
		camera_para.COMP.shading_cap[4] |= (p_cam_addr->SHADING_GAMMA[0][8]<<16)&
			REG_SHADING_CURVE_R_B9_MASK;
		camera_para.COMP.shading_cap[4] |= (p_cam_addr->SHADING_GAMMA[0][9]<<8)&
			REG_SHADING_CURVE_R_B10_MASK;
		camera_para.COMP.shading_cap[4] |= p_cam_addr->SHADING_GAMMA[0][10]&
			REG_SHADING_CURVE_R_B11_MASK;
		camera_para.COMP.shading_cap[5] &= ~(REG_SHADING_CURVE_G_B1_MASK|REG_SHADING_CURVE_G_B2_MASK|
			REG_SHADING_CURVE_G_B3_MASK|REG_SHADING_CURVE_G_B4_MASK);
		camera_para.COMP.shading_cap[5] |= (p_cam_addr->SHADING_GAMMA[1][0]<<24)&
			REG_SHADING_CURVE_G_B1_MASK;
		camera_para.COMP.shading_cap[5] |= (p_cam_addr->SHADING_GAMMA[1][1]<<16)&
			REG_SHADING_CURVE_G_B2_MASK;
		camera_para.COMP.shading_cap[5] |= (p_cam_addr->SHADING_GAMMA[1][2]<<8)&
			REG_SHADING_CURVE_G_B3_MASK;
		camera_para.COMP.shading_cap[5] |= p_cam_addr->SHADING_GAMMA[1][3]&
			REG_SHADING_CURVE_G_B4_MASK;
		camera_para.COMP.shading_cap[6] &= ~(REG_SHADING_CURVE_G_B5_MASK|REG_SHADING_CURVE_G_B6_MASK|
			REG_SHADING_CURVE_G_B7_MASK|REG_SHADING_CURVE_G_B8_MASK);	
		camera_para.COMP.shading_cap[6] |= (p_cam_addr->SHADING_GAMMA[1][4]<<24)&
			REG_SHADING_CURVE_G_B5_MASK;
		camera_para.COMP.shading_cap[6] |= (p_cam_addr->SHADING_GAMMA[1][5]<<16)&
			REG_SHADING_CURVE_G_B6_MASK;
		camera_para.COMP.shading_cap[6] |= (p_cam_addr->SHADING_GAMMA[1][6]<<8)&
			REG_SHADING_CURVE_G_B7_MASK;
		camera_para.COMP.shading_cap[6] |= p_cam_addr->SHADING_GAMMA[1][7]&
			REG_SHADING_CURVE_G_B8_MASK;	
		camera_para.COMP.shading_cap[7] &= ~(REG_SHADING_CURVE_G_B9_MASK|REG_SHADING_CURVE_G_B10_MASK|
			REG_SHADING_CURVE_G_B11_MASK);	
		camera_para.COMP.shading_cap[7] |= (p_cam_addr->SHADING_GAMMA[1][8]<<24)&
			REG_SHADING_CURVE_G_B9_MASK;
		camera_para.COMP.shading_cap[7] |= (p_cam_addr->SHADING_GAMMA[1][9]<<16)&
			REG_SHADING_CURVE_G_B10_MASK;
		camera_para.COMP.shading_cap[7] |= (p_cam_addr->SHADING_GAMMA[1][10]<<8)&			
			REG_SHADING_CURVE_G_B11_MASK;
		camera_para.COMP.shading_cap[8] &= ~(REG_SHADING_CURVE_B_B1_MASK|REG_SHADING_CURVE_B_B2_MASK|
			REG_SHADING_CURVE_B_B3_MASK|REG_SHADING_CURVE_B_B4_MASK);			
		camera_para.COMP.shading_cap[8] |= (p_cam_addr->SHADING_GAMMA[2][0]<<24)&
			REG_SHADING_CURVE_B_B1_MASK;
		camera_para.COMP.shading_cap[8] |= (p_cam_addr->SHADING_GAMMA[2][1]<<16)&
			REG_SHADING_CURVE_B_B2_MASK;
		camera_para.COMP.shading_cap[8] |= (p_cam_addr->SHADING_GAMMA[2][2]<<8)&
			REG_SHADING_CURVE_B_B3_MASK;
		camera_para.COMP.shading_cap[8] |= p_cam_addr->SHADING_GAMMA[2][3]&
			REG_SHADING_CURVE_B_B4_MASK;
		camera_para.COMP.shading_cap[9] &= ~(REG_SHADING_CURVE_B_B5_MASK|REG_SHADING_CURVE_B_B6_MASK|
			REG_SHADING_CURVE_B_B7_MASK|REG_SHADING_CURVE_B_B8_MASK);	
		camera_para.COMP.shading_cap[9] |= (p_cam_addr->SHADING_GAMMA[2][4]<<24)&
			REG_SHADING_CURVE_B_B5_MASK;
		camera_para.COMP.shading_cap[9] |= (p_cam_addr->SHADING_GAMMA[2][5]<<16)&
			REG_SHADING_CURVE_B_B6_MASK;
		camera_para.COMP.shading_cap[9] |= (p_cam_addr->SHADING_GAMMA[2][6]<<8)&
			REG_SHADING_CURVE_B_B7_MASK;
		camera_para.COMP.shading_cap[9] |= p_cam_addr->SHADING_GAMMA[2][7]&
			REG_SHADING_CURVE_B_B8_MASK;
		camera_para.COMP.shading_cap[10] &= ~(REG_SHADING_CURVE_B_B9_MASK|REG_SHADING_CURVE_B_B10_MASK|
			REG_SHADING_CURVE_B_B11_MASK);			
		camera_para.COMP.shading_cap[10] |= (p_cam_addr->SHADING_GAMMA[2][8]<<24)&
			REG_SHADING_CURVE_B_B9_MASK;		
		camera_para.COMP.shading_cap[10] |= (p_cam_addr->SHADING_GAMMA[2][9]<<16)&
			REG_SHADING_CURVE_B_B10_MASK;
		camera_para.COMP.shading_cap[10] |= (p_cam_addr->SHADING_GAMMA[2][10]<<8)&
			REG_SHADING_CURVE_B_B11_MASK;	
	}
#endif		
}

/* read from global variable */
void get_camera_autodefect_set(cct_autodefect_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode)
{
#if (!defined(DRV_ISP_6219_SERIES))
	if (p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)
	{
		p_cam_addr->ADC_EN = (camera_para.ISP.reg[AutoDefect_Reg1_ID]&REG_AUTO_DEFECT_ADC_EN_BIT)>>31;//0x1CC
		p_cam_addr->ADL_EN = (camera_para.ISP.reg[AutoDefect_Reg1_ID]&REG_AUTO_DEFECT_ADL_EN_BIT)>>30;
		p_cam_addr->ADR_EN = (camera_para.ISP.reg[AutoDefect_Reg1_ID]&REG_AUTO_DEFECT_ADR_EN_BIT)>>29;
		p_cam_addr->ADU_EN = (camera_para.ISP.reg[AutoDefect_Reg1_ID]&REG_AUTO_DEFECT_ADU_EN_BIT)>>28;
		p_cam_addr->ADD_EN = (camera_para.ISP.reg[AutoDefect_Reg1_ID]&REG_AUTO_DEFECT_ADD_EN_BIT)>>27;
		p_cam_addr->DEADCHECK = (camera_para.ISP.reg[AutoDefect_Reg1_ID]&REG_AUTO_DEFECT_DEADCHECK_BIT)>>26;
		p_cam_addr->BRIGHTTHD= (camera_para.ISP.reg[AutoDefect_Reg1_ID]&REG_AUTO_DEFECT_BRIGHTTHD_MASK)>>19;
		p_cam_addr->BLACKTHD= (camera_para.ISP.reg[AutoDefect_Reg1_ID]&REG_AUTO_DEFECT_BLACKTHD_MASK)>>16;
		p_cam_addr->GCHECKTHD = (camera_para.ISP.reg[AutoDefect_Reg1_ID+1]&REG_AUTO_DEFECT_GCHECKTHD_MASK)>>24;//0x1D0
		p_cam_addr->RBCHECKTHD = (camera_para.ISP.reg[AutoDefect_Reg1_ID+1]&REG_AUTO_DEFECT_RBCHECKTHD_MASK)>>16;
		p_cam_addr->GCORRECTTHD= (camera_para.ISP.reg[AutoDefect_Reg1_ID+1]&REG_AUTO_DEFECT_GCORRECTTHD_MASK)>>8;//0x1D0
		p_cam_addr->RBCORRECTTHD= camera_para.ISP.reg[AutoDefect_Reg1_ID+1]&REG_AUTO_DEFECT_RBCORRECTTHD_MASK;
	}
	else if (p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET)
	{
		p_cam_addr->ADC_EN = (camera_para.COMP.autodefect_pre_low[0]&REG_AUTO_DEFECT_ADC_EN_BIT)>>31;//0x1CC
		p_cam_addr->ADL_EN = (camera_para.COMP.autodefect_pre_low[0]&REG_AUTO_DEFECT_ADL_EN_BIT)>>30;
		p_cam_addr->ADR_EN = (camera_para.COMP.autodefect_pre_low[0]&REG_AUTO_DEFECT_ADR_EN_BIT)>>29;
		p_cam_addr->ADU_EN = (camera_para.COMP.autodefect_pre_low[0]&REG_AUTO_DEFECT_ADU_EN_BIT)>>28;
		p_cam_addr->ADD_EN = (camera_para.COMP.autodefect_pre_low[0]&REG_AUTO_DEFECT_ADD_EN_BIT)>>27;
		p_cam_addr->DEADCHECK = (camera_para.COMP.autodefect_pre_low[0]&REG_AUTO_DEFECT_DEADCHECK_BIT)>>26;
		p_cam_addr->BRIGHTTHD = (camera_para.COMP.autodefect_pre_low[0]&REG_AUTO_DEFECT_BRIGHTTHD_MASK)>>19;
		p_cam_addr->BLACKTHD = (camera_para.COMP.autodefect_pre_low[0]&REG_AUTO_DEFECT_BLACKTHD_MASK)>>16;
		p_cam_addr->GCHECKTHD = (camera_para.COMP.autodefect_pre_low[1]&REG_AUTO_DEFECT_GCHECKTHD_MASK)>>24;//0x1D0
		p_cam_addr->RBCHECKTHD = (camera_para.COMP.autodefect_pre_low[1]&REG_AUTO_DEFECT_RBCHECKTHD_MASK)>>16;
		p_cam_addr->GCORRECTTHD= (camera_para.COMP.autodefect_pre_low[1]&REG_AUTO_DEFECT_GCORRECTTHD_MASK)>>8;//0x1D0
		p_cam_addr->RBCORRECTTHD= camera_para.COMP.autodefect_pre_low[1]&REG_AUTO_DEFECT_RBCORRECTTHD_MASK;
	}	
	else if (p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)
	{
		p_cam_addr->ADC_EN = (camera_para.COMP.autodefect_cap_nor[0]&REG_AUTO_DEFECT_ADC_EN_BIT)>>31;//0x1CC
		p_cam_addr->ADL_EN = (camera_para.COMP.autodefect_cap_nor[0]&REG_AUTO_DEFECT_ADL_EN_BIT)>>30;
		p_cam_addr->ADR_EN = (camera_para.COMP.autodefect_cap_nor[0]&REG_AUTO_DEFECT_ADR_EN_BIT)>>29;
		p_cam_addr->ADU_EN = (camera_para.COMP.autodefect_cap_nor[0]&REG_AUTO_DEFECT_ADU_EN_BIT)>>28;
		p_cam_addr->ADD_EN = (camera_para.COMP.autodefect_cap_nor[0]&REG_AUTO_DEFECT_ADD_EN_BIT)>>27;
		p_cam_addr->DEADCHECK = (camera_para.COMP.autodefect_cap_nor[0]&REG_AUTO_DEFECT_DEADCHECK_BIT)>>26;
		p_cam_addr->BRIGHTTHD = (camera_para.COMP.autodefect_cap_nor[0]&REG_AUTO_DEFECT_BRIGHTTHD_MASK)>>19;
		p_cam_addr->BLACKTHD = (camera_para.COMP.autodefect_cap_nor[0]&REG_AUTO_DEFECT_BLACKTHD_MASK)>>16;
		p_cam_addr->GCHECKTHD = (camera_para.COMP.autodefect_cap_nor[1]&REG_AUTO_DEFECT_GCHECKTHD_MASK)>>24;//0x1D0
		p_cam_addr->RBCHECKTHD = (camera_para.COMP.autodefect_cap_nor[1]&REG_AUTO_DEFECT_RBCHECKTHD_MASK)>>16;
		p_cam_addr->GCORRECTTHD= (camera_para.COMP.autodefect_cap_nor[1]&REG_AUTO_DEFECT_GCORRECTTHD_MASK)>>8;//0x1D0
		p_cam_addr->RBCORRECTTHD= camera_para.COMP.autodefect_cap_nor[1]&REG_AUTO_DEFECT_RBCORRECTTHD_MASK;
	}
	else if (p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET)
	{
		p_cam_addr->ADC_EN = (camera_para.COMP.autodefect_cap_low[0]&REG_AUTO_DEFECT_ADC_EN_BIT)>>31;//0x1CC
		p_cam_addr->ADL_EN = (camera_para.COMP.autodefect_cap_low[0]&REG_AUTO_DEFECT_ADL_EN_BIT)>>30;
		p_cam_addr->ADR_EN = (camera_para.COMP.autodefect_cap_low[0]&REG_AUTO_DEFECT_ADR_EN_BIT)>>29;
		p_cam_addr->ADU_EN = (camera_para.COMP.autodefect_cap_low[0]&REG_AUTO_DEFECT_ADU_EN_BIT)>>28;
		p_cam_addr->ADD_EN = (camera_para.COMP.autodefect_cap_low[0]&REG_AUTO_DEFECT_ADD_EN_BIT)>>27;
		p_cam_addr->DEADCHECK = (camera_para.COMP.autodefect_cap_low[0]&REG_AUTO_DEFECT_DEADCHECK_BIT)>>26;
		p_cam_addr->BRIGHTTHD = (camera_para.COMP.autodefect_cap_low[0]&REG_AUTO_DEFECT_BRIGHTTHD_MASK)>>19;
		p_cam_addr->BLACKTHD = (camera_para.COMP.autodefect_cap_low[0]&REG_AUTO_DEFECT_BLACKTHD_MASK)>>16;
		p_cam_addr->GCHECKTHD = (camera_para.COMP.autodefect_cap_low[1]&REG_AUTO_DEFECT_GCHECKTHD_MASK)>>24;//0x1D0
		p_cam_addr->RBCHECKTHD = (camera_para.COMP.autodefect_cap_low[1]&REG_AUTO_DEFECT_RBCHECKTHD_MASK)>>16;
		p_cam_addr->GCORRECTTHD= (camera_para.COMP.autodefect_cap_low[1]&REG_AUTO_DEFECT_GCORRECTTHD_MASK)>>8;//0x1D0
		p_cam_addr->RBCORRECTTHD= camera_para.COMP.autodefect_cap_low[1]&REG_AUTO_DEFECT_RBCORRECTTHD_MASK;
	}
#endif	
}

/* write to global variable */
void set_camera_autodefect_set(const cct_autodefect_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode)
{
#if (!defined(DRV_ISP_6219_SERIES))
	if (p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)
	{
		camera_para.ISP.reg[AutoDefect_Reg1_ID] &= ~(REG_AUTO_DEFECT_ADC_EN_BIT|
			REG_AUTO_DEFECT_ADL_EN_BIT|REG_AUTO_DEFECT_ADR_EN_BIT|
			REG_AUTO_DEFECT_ADU_EN_BIT|REG_AUTO_DEFECT_ADD_EN_BIT|
			REG_AUTO_DEFECT_DEADCHECK_BIT|REG_AUTO_DEFECT_BRIGHTTHD_MASK|
			REG_AUTO_DEFECT_BLACKTHD_MASK);
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= (p_cam_addr->ADC_EN<<31)&
			REG_AUTO_DEFECT_ADC_EN_BIT;//0x1CC
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= (p_cam_addr->ADL_EN<<30)&
			REG_AUTO_DEFECT_ADL_EN_BIT;
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= (p_cam_addr->ADR_EN<<29)&
			REG_AUTO_DEFECT_ADR_EN_BIT;
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= (p_cam_addr->ADU_EN<<28)&
			REG_AUTO_DEFECT_ADU_EN_BIT;
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= (p_cam_addr->ADD_EN<<27)&
			REG_AUTO_DEFECT_ADD_EN_BIT;
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= (p_cam_addr->DEADCHECK<<26)&
			REG_AUTO_DEFECT_DEADCHECK_BIT;
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= (p_cam_addr->BRIGHTTHD<<19)&
			REG_AUTO_DEFECT_BRIGHTTHD_MASK;
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= (p_cam_addr->BLACKTHD<<16)&
			REG_AUTO_DEFECT_BLACKTHD_MASK;
		camera_para.ISP.reg[AutoDefect_Reg1_ID+1] &= ~(REG_AUTO_DEFECT_GCHECKTHD_MASK|
			REG_AUTO_DEFECT_RBCHECKTHD_MASK|REG_AUTO_DEFECT_GCORRECTTHD_MASK|
			REG_AUTO_DEFECT_RBCORRECTTHD_MASK);
		camera_para.ISP.reg[AutoDefect_Reg1_ID+1] |= (p_cam_addr->GCHECKTHD<<24)&
			REG_AUTO_DEFECT_GCHECKTHD_MASK;//0x1D0
		camera_para.ISP.reg[AutoDefect_Reg1_ID+1] |= (p_cam_addr->RBCHECKTHD<<16)&
			REG_AUTO_DEFECT_RBCHECKTHD_MASK;
		camera_para.ISP.reg[AutoDefect_Reg1_ID+1] |= (p_cam_addr->GCORRECTTHD<<8)&
			REG_AUTO_DEFECT_GCORRECTTHD_MASK;//0x1D0
		camera_para.ISP.reg[AutoDefect_Reg1_ID+1] |= p_cam_addr->RBCORRECTTHD &
			REG_AUTO_DEFECT_RBCORRECTTHD_MASK;		
	}
	else if (p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET)
	{
		camera_para.COMP.autodefect_pre_low[0] &= ~(REG_AUTO_DEFECT_ADC_EN_BIT|
			REG_AUTO_DEFECT_ADL_EN_BIT|REG_AUTO_DEFECT_ADR_EN_BIT|
			REG_AUTO_DEFECT_ADU_EN_BIT|REG_AUTO_DEFECT_ADD_EN_BIT|
			REG_AUTO_DEFECT_DEADCHECK_BIT|REG_AUTO_DEFECT_BRIGHTTHD_MASK|
			REG_AUTO_DEFECT_BLACKTHD_MASK);
		camera_para.COMP.autodefect_pre_low[0] |= (p_cam_addr->ADC_EN<<31)&
			REG_AUTO_DEFECT_ADC_EN_BIT;//0x1CC
		camera_para.COMP.autodefect_pre_low[0] |= (p_cam_addr->ADL_EN<<30)&
			REG_AUTO_DEFECT_ADL_EN_BIT;
		camera_para.COMP.autodefect_pre_low[0] |= (p_cam_addr->ADR_EN<<29)&
			REG_AUTO_DEFECT_ADR_EN_BIT;
		camera_para.COMP.autodefect_pre_low[0] |= (p_cam_addr->ADU_EN<<28)&
			REG_AUTO_DEFECT_ADU_EN_BIT;
		camera_para.COMP.autodefect_pre_low[0] |= (p_cam_addr->ADD_EN<<27)&
			REG_AUTO_DEFECT_ADD_EN_BIT;
		camera_para.COMP.autodefect_pre_low[0] |= (p_cam_addr->DEADCHECK<<26)&
			REG_AUTO_DEFECT_DEADCHECK_BIT;
		camera_para.COMP.autodefect_pre_low[0] |= (p_cam_addr->BRIGHTTHD<<19)&
			REG_AUTO_DEFECT_BRIGHTTHD_MASK;
		camera_para.COMP.autodefect_pre_low[0] |= (p_cam_addr->BLACKTHD<<16)&
			REG_AUTO_DEFECT_BLACKTHD_MASK;
		camera_para.COMP.autodefect_pre_low[1] &= ~(REG_AUTO_DEFECT_GCHECKTHD_MASK|
			REG_AUTO_DEFECT_RBCHECKTHD_MASK|REG_AUTO_DEFECT_GCORRECTTHD_MASK|
			REG_AUTO_DEFECT_RBCORRECTTHD_MASK);
		camera_para.COMP.autodefect_pre_low[1] |= (p_cam_addr->GCHECKTHD<<24)&
			REG_AUTO_DEFECT_GCHECKTHD_MASK;//0x1D0
		camera_para.COMP.autodefect_pre_low[1] |= (p_cam_addr->RBCHECKTHD<<16)&
			REG_AUTO_DEFECT_RBCHECKTHD_MASK;
		camera_para.COMP.autodefect_pre_low[1] |= (p_cam_addr->GCORRECTTHD<<8)&
			REG_AUTO_DEFECT_GCORRECTTHD_MASK;//0x1D0
		camera_para.COMP.autodefect_pre_low[1] |= p_cam_addr->RBCORRECTTHD &
			REG_AUTO_DEFECT_RBCORRECTTHD_MASK;		
	}	
	else if (p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)
	{
		camera_para.COMP.autodefect_cap_nor[0] &= ~(REG_AUTO_DEFECT_ADC_EN_BIT|
			REG_AUTO_DEFECT_ADL_EN_BIT|REG_AUTO_DEFECT_ADR_EN_BIT|
			REG_AUTO_DEFECT_ADU_EN_BIT|REG_AUTO_DEFECT_ADD_EN_BIT|
			REG_AUTO_DEFECT_DEADCHECK_BIT|REG_AUTO_DEFECT_BRIGHTTHD_MASK|
			REG_AUTO_DEFECT_BLACKTHD_MASK);
		camera_para.COMP.autodefect_cap_nor[0] |= (p_cam_addr->ADC_EN<<31)&
			REG_AUTO_DEFECT_ADC_EN_BIT;//0x1CC
		camera_para.COMP.autodefect_cap_nor[0] |= (p_cam_addr->ADL_EN<<30)&
			REG_AUTO_DEFECT_ADL_EN_BIT;
		camera_para.COMP.autodefect_cap_nor[0] |= (p_cam_addr->ADR_EN<<29)&
			REG_AUTO_DEFECT_ADR_EN_BIT;
		camera_para.COMP.autodefect_cap_nor[0] |= (p_cam_addr->ADU_EN<<28)&
			REG_AUTO_DEFECT_ADU_EN_BIT;
		camera_para.COMP.autodefect_cap_nor[0] |= (p_cam_addr->ADD_EN<<27)&
			REG_AUTO_DEFECT_ADD_EN_BIT;
		camera_para.COMP.autodefect_cap_nor[0] |= (p_cam_addr->DEADCHECK<<26)&
			REG_AUTO_DEFECT_DEADCHECK_BIT;
		camera_para.COMP.autodefect_cap_nor[0] |= (p_cam_addr->BRIGHTTHD<<19)&
			REG_AUTO_DEFECT_BRIGHTTHD_MASK;
		camera_para.COMP.autodefect_cap_nor[0] |= (p_cam_addr->BLACKTHD<<16)&
			REG_AUTO_DEFECT_BLACKTHD_MASK;
		camera_para.COMP.autodefect_cap_nor[1] &= ~(REG_AUTO_DEFECT_GCHECKTHD_MASK|
			REG_AUTO_DEFECT_RBCHECKTHD_MASK|REG_AUTO_DEFECT_GCORRECTTHD_MASK|
			REG_AUTO_DEFECT_RBCORRECTTHD_MASK);
		camera_para.COMP.autodefect_cap_nor[1] |= (p_cam_addr->GCHECKTHD<<24)&
			REG_AUTO_DEFECT_GCHECKTHD_MASK;//0x1D0
		camera_para.COMP.autodefect_cap_nor[1] |= (p_cam_addr->RBCHECKTHD<<16)&
			REG_AUTO_DEFECT_RBCHECKTHD_MASK;
		camera_para.COMP.autodefect_cap_nor[1] |= (p_cam_addr->GCORRECTTHD<<8)&
			REG_AUTO_DEFECT_GCORRECTTHD_MASK;//0x1D0
		camera_para.COMP.autodefect_cap_nor[1] |= p_cam_addr->RBCORRECTTHD &
			REG_AUTO_DEFECT_RBCORRECTTHD_MASK;		
	}
	else if (p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET)
	{
		camera_para.COMP.autodefect_cap_low[0] &= ~(REG_AUTO_DEFECT_ADC_EN_BIT|
			REG_AUTO_DEFECT_ADL_EN_BIT|REG_AUTO_DEFECT_ADR_EN_BIT|
			REG_AUTO_DEFECT_ADU_EN_BIT|REG_AUTO_DEFECT_ADD_EN_BIT|
			REG_AUTO_DEFECT_DEADCHECK_BIT|REG_AUTO_DEFECT_BRIGHTTHD_MASK|
			REG_AUTO_DEFECT_BLACKTHD_MASK);
		camera_para.COMP.autodefect_cap_low[0] |= (p_cam_addr->ADC_EN<<31)&
			REG_AUTO_DEFECT_ADC_EN_BIT;//0x1CC
		camera_para.COMP.autodefect_cap_low[0] |= (p_cam_addr->ADL_EN<<30)&
			REG_AUTO_DEFECT_ADL_EN_BIT;
		camera_para.COMP.autodefect_cap_low[0] |= (p_cam_addr->ADR_EN<<29)&
			REG_AUTO_DEFECT_ADR_EN_BIT;
		camera_para.COMP.autodefect_cap_low[0] |= (p_cam_addr->ADU_EN<<28)&
			REG_AUTO_DEFECT_ADU_EN_BIT;
		camera_para.COMP.autodefect_cap_low[0] |= (p_cam_addr->ADD_EN<<27)&
			REG_AUTO_DEFECT_ADD_EN_BIT;
		camera_para.COMP.autodefect_cap_low[0] |= (p_cam_addr->DEADCHECK<<26)&
			REG_AUTO_DEFECT_DEADCHECK_BIT;
		camera_para.COMP.autodefect_cap_low[0] |= (p_cam_addr->BRIGHTTHD<<19)&
			REG_AUTO_DEFECT_BRIGHTTHD_MASK;
		camera_para.COMP.autodefect_cap_low[0] |= (p_cam_addr->BLACKTHD<<16)&
			REG_AUTO_DEFECT_BLACKTHD_MASK;
		camera_para.COMP.autodefect_cap_low[1] &= ~(REG_AUTO_DEFECT_GCHECKTHD_MASK|
			REG_AUTO_DEFECT_RBCHECKTHD_MASK|REG_AUTO_DEFECT_GCORRECTTHD_MASK|
			REG_AUTO_DEFECT_RBCORRECTTHD_MASK);
		camera_para.COMP.autodefect_cap_low[1] |= (p_cam_addr->GCHECKTHD<<24)&
			REG_AUTO_DEFECT_GCHECKTHD_MASK;//0x1D0
		camera_para.COMP.autodefect_cap_low[1] |= (p_cam_addr->RBCHECKTHD<<16)&
			REG_AUTO_DEFECT_RBCHECKTHD_MASK;
		camera_para.COMP.autodefect_cap_low[1] |= (p_cam_addr->GCORRECTTHD<<8)&
			REG_AUTO_DEFECT_GCORRECTTHD_MASK;//0x1D0
		camera_para.COMP.autodefect_cap_low[1] |= p_cam_addr->RBCORRECTTHD &
			REG_AUTO_DEFECT_RBCORRECTTHD_MASK;		
	}
#endif
}

kal_bool  isp_cct_is_autodefect_supported(void)
{
#if (!defined(DRV_ISP_6219_SERIES))
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

/* apply global variable to reg */
void cct_apply_camera_shading_to_reg(camera_comp_set_num p_set_mode)
{
#if (!defined(DRV_ISP_6219_SERIES))
	kal_uint32	i;
	if ((p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)||
		(p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET))
		for(i=0;i<11;i++)//0214h~023Ch
			*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.ISP.reg[Shading_Reg1_ID+i];
	else if ((p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)||
			(p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET))
		for (i=0;i<11;i++)
			*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.COMP.shading_cap[i];
#endif
}

/* apply reg to global variable */
void cct_update_camera_shading_from_reg(camera_comp_set_num p_set_mode)
{
#if (!defined(DRV_ISP_6219_SERIES))
	kal_uint32	i;
	if ((p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)||
		(p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET))
		for(i=0;i<11;i++)//0214h~023Ch
			camera_para.ISP.reg[i+Shading_Reg1_ID] = *((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4));
	else if ((p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)||
			(p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET))
		for (i=0;i<11;i++)
			camera_para.COMP.shading_cap[i] = *((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4 ));
#endif
}

/* apply global variable to reg */
void cct_apply_camera_autodefect_to_reg(camera_comp_set_num p_set_mode)
{
#if (!defined(DRV_ISP_6219_SERIES))
	REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
	if (p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)
	{
		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK&camera_para.ISP.reg[AutoDefect_Reg1_ID]; //0x1CC
		REG_ISP_AUTO_DEFECT_CTRL2 = camera_para.ISP.reg[AutoDefect_Reg1_ID+1]; //0x1D0
	}
	else if (p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET)
	{
		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK&camera_para.COMP.autodefect_pre_low[0]; //0x1CC
		REG_ISP_AUTO_DEFECT_CTRL2 = camera_para.COMP.autodefect_pre_low[1]; //0x1D0		
	}	
	else if (p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)
	{
		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK&camera_para.COMP.autodefect_cap_nor[0]; //0x1CC
		REG_ISP_AUTO_DEFECT_CTRL2 = camera_para.COMP.autodefect_cap_nor[1]; //0x1D0		
	}
	else if (p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET)
	{
		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK&camera_para.COMP.autodefect_cap_low[0]; //0x1CC
		REG_ISP_AUTO_DEFECT_CTRL2 = camera_para.COMP.autodefect_cap_low[1]; //0x1D0		
	}
#endif
}

/* apply reg to global variable */
void cct_update_camera_autodefect_from_reg(camera_comp_set_num p_set_mode)
{
#if (!defined(DRV_ISP_6219_SERIES))
	if (p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)
	{
		camera_para.ISP.reg[AutoDefect_Reg1_ID] &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= REG_ISP_AUTO_DEFECT_CTRL1&REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK; //0x1CC
		camera_para.ISP.reg[AutoDefect_Reg1_ID+1] = REG_ISP_AUTO_DEFECT_CTRL2; //0x1D0
	}
	else if (p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET)
	{
		camera_para.COMP.autodefect_pre_low[0] &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
		camera_para.COMP.autodefect_pre_low[0] |= REG_ISP_AUTO_DEFECT_CTRL1&REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK; //0x1CC
		camera_para.COMP.autodefect_pre_low[1] = REG_ISP_AUTO_DEFECT_CTRL2; //0x1D0		
	}	
	else if (p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)
	{
		camera_para.COMP.autodefect_cap_nor[0] &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
		camera_para.COMP.autodefect_cap_nor[0] |= REG_ISP_AUTO_DEFECT_CTRL1&REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK; //0x1CC
		camera_para.COMP.autodefect_cap_nor[1] = REG_ISP_AUTO_DEFECT_CTRL2; //0x1D0		
	}
	else if (p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET)
	{
		camera_para.COMP.autodefect_cap_low[0] &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
		camera_para.COMP.autodefect_cap_low[0] |= REG_ISP_AUTO_DEFECT_CTRL1&REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK; //0x1CC
		camera_para.COMP.autodefect_cap_low[1] = REG_ISP_AUTO_DEFECT_CTRL2; //0x1D0		
	}
#endif
}

kal_bool  isp_cct_is_autodefct_count_supported(void) {
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))//only 6226 & 6227 & 6229 can auto defect count
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

kal_uint16  cct_read_autodefct_count(void) {
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))//only 6226 & 6227 & 6229 can auto defect count
	return cct_auto_defect_count;
#else
	return 0xFFFF;
#endif
}

kal_bool  isp_cct_is_defect_table_supported(void) {
#if (!defined(DRV_ISP_6219_SERIES))
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

kal_bool cct_defect_table_on_off(kal_bool set_flag)
{
#if (!defined(DRV_ISP_6219_SERIES))
	if (set_flag == KAL_TRUE)
		ENABLE_DEFECT_CORRECTION
	else
		DISABLE_DEFECT_CORRECTION
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

kal_uint16  isp_cct_is_cct_af_support(void) {
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

/*  AF operation must call this function to prevent status modified by offset calibration */
void cct_camera_operation_setting(kal_uint8 func_sel, kal_uint16 para)
{
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	if ((CAM_AF_KEY == func_sel) && (CAM_AF_RELEASE == para))
	{
		AF_Recover_Min_Step();
	}
#endif
	camera_operation_setting(func_sel, para);
}


kal_bool cct_backup_bypass_pre_adjust(void)
{
	/* backup */
#if (!defined(DRV_ISP_6219_SERIES))	
	cct_ob_backup = REG_ISP_RGB_OFFSET_ADJUS;
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))	
	cct_raw_backup1 = *((volatile unsigned int *) (CAMERA_base + 0x016C));
	cct_raw_backup2 = *((volatile unsigned int *) (CAMERA_base + 0x0170));
#endif
	cct_pregain_backup = REG_ISP_PREPROCESS_CTRL1;
	cct_sensor_gamma_backup = REG_ISP_SNR_GAMMA_R0;
	/* reset */
	REG_ISP_RGB_OFFSET_ADJUS = 0x80808080;
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))	
	*((volatile unsigned int *) (CAMERA_base + 0x016C)) = 0x00800080;
	*((volatile unsigned int *) (CAMERA_base + 0x0170)) = 0x00800080;
#endif
	DISABLE_BYPASS_PRE_GAIN_MOD;
	DISABLE_SHADING_COMPENSATION;
	DISABLE_SENSOR_GAMMA;
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif


}
kal_bool cct_recover_pre_adjust(void)
{
#if (!defined(DRV_ISP_6219_SERIES))
	 REG_ISP_RGB_OFFSET_ADJUS = cct_ob_backup;
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))	
	*((volatile unsigned int *) (CAMERA_base + 0x016C)) = cct_raw_backup1;
	*((volatile unsigned int *) (CAMERA_base + 0x0170)) = cct_raw_backup2;
#endif
	REG_ISP_PREPROCESS_CTRL1 = cct_pregain_backup;
	REG_ISP_SHADING_CTRL1 = cct_shading_backup;
	REG_ISP_SNR_GAMMA_R0 = cct_sensor_gamma_backup;
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

kal_bool  cct_get_isp_gamma1024_ONOFF(void)
{
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	return (kal_bool)(camera_para.ISP.reg[gamma_global_1024_no] & REG_GAMMA_OPERATION_1024_ENABLE_BIT);
#else
	return KAL_FALSE;
#endif
}

kal_bool  cct_set_isp_gamma1024_ONOFF(kal_bool gamma_flag)
{
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	if (KAL_TRUE == gamma_flag)
	{
		camera_para.ISP.reg[gamma_global_1024_no] |= REG_GAMMA_OPERATION_1024_ENABLE_BIT;
	}
	else
	{
		camera_para.ISP.reg[gamma_global_1024_no] &= ~REG_GAMMA_OPERATION_1024_ENABLE_BIT;	
	}
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

kal_bool  cct_get_isp_gamma_ONOFF(void)
{
	if ((REG_ISP_COLOR_PROCESS_STAGE_CTRL2 & REG_CPS2_BYPASS_GAMMA_BIT) == 0)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
}

void  cct_set_isp_gamma_ONOFF(kal_bool gamma_flag)
{
	if (KAL_TRUE == gamma_flag)
	{
		DISABLE_GAMMA_FUNCTION_BYPASS;
	}
	else
	{
		ENABLE_GAMMA_FUNCTION_BYPASS;
	}	
}

kal_bool  isp_cct_is_iso_priority_supported(void)
{
#if (!defined(DRV_ISP_6219_SERIES))
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

kal_bool cct_iso_set_gain(const kal_uint16 gain[3])
{
#if (!defined(DRV_ISP_6219_SERIES))	
	camera_para.ISO_PRIORITY_INFO.ISO_Gain[0] = gain[0];
	camera_para.ISO_PRIORITY_INFO.ISO_Gain[1] = gain[1];
	camera_para.ISO_PRIORITY_INFO.ISO_Gain[2] = gain[2];
#endif
	return KAL_TRUE;
}

kal_bool cct_iso_get_gain(kal_uint16 gain[3]) 
{
#if (!defined(DRV_ISP_6219_SERIES))	
	gain[0] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[0];
	gain[1] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[1];
	gain[2] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[2];
#endif
	return KAL_TRUE;
}

kal_bool cct_iso_set_value(const kal_uint16 value[3])
{
#if (!defined(DRV_ISP_6219_SERIES))	
	camera_para.ISO_PRIORITY_INFO.ISO_Value[0] = value[0];
	camera_para.ISO_PRIORITY_INFO.ISO_Value[1] = value[1];
	camera_para.ISO_PRIORITY_INFO.ISO_Value[2] = value[2];	
#endif
	return KAL_TRUE;
}

kal_bool cct_iso_get_value(kal_uint16 value[3]) 
{
#if (!defined(DRV_ISP_6219_SERIES))	
	value[0] = camera_para.ISO_PRIORITY_INFO.ISO_Value[0];
	value[1] = camera_para.ISO_PRIORITY_INFO.ISO_Value[1];
	value[2] = camera_para.ISO_PRIORITY_INFO.ISO_Value[2];
#endif
	return KAL_TRUE;
}


#endif /* MT6219||MT6228||MT6226||MT6227||MT6229 */
