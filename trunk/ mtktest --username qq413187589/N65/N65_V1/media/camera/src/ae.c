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
 *   ae.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   Auto Exposure Algorithm
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h"

#if ((defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))&&defined(ISP_SUPPORT))
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "ae_awb.h"
#include "af.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "sccb.h"
#include "camera_para.h"
#include "med_api.h"
#include "gpio_sw.h"
#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"
#endif

#if (!defined(DRV_ISP_6219_SERIES))
#include "isp_flashlight.h"
#endif

camera_operation_para_struct camera_oper_data;
#if (!defined(DRV_ISP_6219_SERIES))
dsc_operation_struct dsc_status;
#endif

#if (!defined(DRV_ISP_6225_SERIES))
kal_bool ae_enable_flag,awb_enable_flag;
kal_bool ae_bypass_enable_flag = KAL_FALSE;		// AE byapss mode: bypass ae cal
kal_uint8 AE_BYPASS_INDEX = 0;

kal_uint8	ae_awb_cal_complete=1;

#if (!defined(DRV_ISP_6219_SERIES))
/* SHUTTER APERTURE PRIORITY ARRAY */
kal_bool shutter_pri_60hz_info[TV_NO];
kal_bool shutter_pri_50hz_info[TV_NO];
kal_bool	aperture_pri_info[AV_NO];
kal_bool	iso_pri_info[ISO_NO];
kal_uint16 iso_gain_info[ISO_NO];
const tv_av_info_struct	tv_av_info={
	/* Shutter Priority Info */
{	{50000,20},{40000,25},{33000,30},{28000,35},{25000,40},{22000,45},{20000,50},{18000,55},
	{16000,60},{14000,70},{12000,80},{11000,90},{10000,100},{9000,110},{8300,120},{8000,130},
	{7000,140},{6700,150},{6000,170},{5000,200},{4200,240},{4000,250},{3300,300},{3000,330},
	{2500,400},{2000,500},{1700,600},{1000,1000},{833,1200},{800,1250},{710,1400},{630,1600},
	{570,1750},{500,2000},{400,2500},{310,3200},{250,4000},{200,5000},{160,6400},{130,8000},
	{100,10000},{83,12000},{71,14000},{63,16000},{56,18000},{50,20000}},
	/* Aperture Priority Info */
{	{20,20},{28,28},{40,40},{56,56},{80,80},{110,110},{160,160}}};
#endif
#if ((!defined(DRV_ISP_6219_SERIES))&&defined(EXIF_SUPPORT))
const kal_uint8 exif_iso_count = 22;
const kal_uint16 exif_iso_speed[22]=
{50, 60, 80,
100,125, 160,
200,250, 320,
400,500, 640,
800, 1000, 1200,
1600,2000, 2500,
3200,4000, 5000,
6400};
#endif
/**************   AE DECLARATION    ****************************************/
kal_int8		ev_level=0;
kal_uint8	expo_level=110,high_expo_level,low_expo_level;
kal_uint8	totalevstep=9;
kal_uint8	light_band;		
kal_uint32	lum[9],eShutter=300;
kal_uint8	isp_pregain=0x40; 
kal_uint16	sensor_pregain=0x40; 
kal_uint8	ae_range=8;
kal_uint32	histogram[5],Rhist[5],Ghist[5],Bhist[5];
kal_uint8	histogram_b1=3,histogram_b2=7,histogram_b3=11,histogram_b4=248,histogram_b5=255;

#if (!defined(DRV_ISP_6219_SERIES))
const exposure_lut_struct *AE_LUT;
const kal_uint8 *IRIS_LUT;
ae_lut_info_struct lut_info={CAM_BANDING_60HZ,KAL_FALSE,CAM_AUTO_DSC};
kal_uint8 iris_no;
#endif

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#if (defined(__MTK_TARGET__))
#pragma arm section rwdata = "INTERNRW1", zidata = "INTERNZI1"
#endif
kal_uint32	ae_result[7][9];	/* recommand to set in SRAM */
#if (defined(__MTK_TARGET__))
#pragma arm section rwdata , zidata
#endif
#endif
/****************************************************************************
 *          AE  Main
 ****************************************************************************/
void init_ae(void)
{
	DISABLE_ATF_EDGE;
	DISABLE_ATF_AREA_ALL;
	DISABLE_AE_AREA_ALL;			
	ENABLE_AE_COUNT;				
	SET_AE_GM_SEL(0);				
	SET_AE_PATH_SEL_HIGH;		
	DISABLE_AE_ONLY_G_COLOR;	

	ae_enable_flag=ISP_ON;
	ae_select_band(CAM_BANDING_60HZ);
#if (!defined(DRV_ISP_6219_SERIES))	
	AE_LUT=get_ae_lut(lut_info);
	dsc_status.dscmode = lut_info.dscmode;
	dsc_status.ae.iso = CAM_ISO_AUTO;
      	if(device_support_info.ae.sensor_basegain==0)
      		device_support_info.ae.sensor_basegain = BASEGAIN;
	/* update AE_INDEX_ENV with table offset */
	AE_INDEX_ENV = ae_env_index_offset(AE_INDEX);
	AE_INDEX = ae_apply_index_update(lut_info.dscmode, dsc_status.ae.iso, AE_INDEX_ENV);
    	AE_INDEX_C = AE_INDEX;
#endif
}

/* Suggest put this function in HISR */
void ae_awb_main(void)
{
	if(ae_enable_flag == ISP_ON)
	{	
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
		//Avoid ae get accumulation frame
#if (defined(WEBCAM_SUPPORT))		
			if((AE_FRAME_COUNT==1)||(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)) 
#else		
			if(AE_FRAME_COUNT==1) 
#endif				
#endif
#if (defined(WEBCAM_SUPPORT))		
			if((ae_hw_frame_count_backup[1]!=0)||(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)) 
#else
			if(ae_hw_frame_count_backup[1]!=0)
#endif
				ae_proc();

#if (!defined(DRV_ISP_6219_SERIES))			
		if(ae_bypass_enable_flag==KAL_TRUE)
		{
			/* Replace AE Index */
			AE_INDEX = AE_BYPASS_INDEX;
			/* Get Shutter */
			eShutter=AE_LUT[AE_BYPASS_INDEX].shutter;		
			/* Get Gain */	
			sensor_pregain=ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);
			isp_pregain=AE_LUT[AE_BYPASS_INDEX].ispgain;		
			pregain=sensor_pregain*isp_pregain/BASEGAIN;		
		}			
#endif			
	}
	if(awb_enable_flag == ISP_ON)
	{
		awb_proc();
	}
	IRQMask(IRQ_CAMERA_CODE);
	ae_awb_cal_complete=1;
	IRQUnmask(IRQ_CAMERA_CODE);
}
	
extern kal_bool ae_enable_flag_backup;
void ae_on_off(kal_bool flag)
{
	ae_enable_flag=flag;
	ae_enable_flag_backup=flag;
}

void ae_select_band(kal_uint8 band)
{
	switch(band)
	{
		case CAM_BANDING_60HZ :
			light_band = CAM_BANDING_60HZ;
			break;
		case CAM_BANDING_50HZ :
			light_band = CAM_BANDING_50HZ;
			break;
		default :
			light_band = CAM_BANDING_60HZ;
			break;
	}
#if (!defined(DRV_ISP_6219_SERIES))
	lut_info.band=light_band;
	AE_LUT=get_ae_lut(lut_info);
#endif
}

/* This function must put in LISR */
void get_ae_awb_info(void)
{
	/* Luminance for AE */
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	lum[0]=REG_ISP_AE_WINDOW1_RESULT;
	lum[1]=REG_ISP_AE_WINDOW2_RESULT;
	lum[2]=REG_ISP_AE_WINDOW3_RESULT;
	lum[3]=REG_ISP_AE_WINDOW4_RESULT;
	lum[4]=REG_ISP_AE_WINDOW5_RESULT;
	lum[5]=REG_ISP_AE_WINDOW6_RESULT;
	lum[6]=REG_ISP_AE_WINDOW7_RESULT;
	lum[7]=REG_ISP_AE_WINDOW8_RESULT;
	lum[8]=REG_ISP_AE_WINDOW9_RESULT;
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* No Need to Copy Register Value to AE Result */
#endif
	/* Accumulation for AWB */
//	Acc_R=REG_ISP_OPD_Y_RESULT;
//	Acc_G=REG_ISP_OPD_MG_RESULT;
//	Acc_B=REG_ISP_OPD_RB_RESULT;
}

void init_histogram_setting (void)
{

	SET_HISTOGRAM_BOUNDARY1(histogram_b1);
	SET_HISTOGRAM_BOUNDARY2(histogram_b2);
	SET_HISTOGRAM_BOUNDARY3(histogram_b3);
	SET_HISTOGRAM_BOUNDARY4(histogram_b4);
	SET_HISTOGRAM_BOUNDARY5(histogram_b5);

	DISABLE_HISTOGRAM_RLEN;
	SET_AE_GID_POLARITY_LOW;
	SET_AE_PID_POLARITY_HIGH;
}

void get_histogram_info(kal_uint8 color)
{
	kal_uint8 i;
	
	switch(color)
	{
		case 0:
			for(i=0;i<5;i++)
				Rhist[i]=histogram[i];
		break;
		case 1:
			for(i=0;i<5;i++)
				Ghist[i]=histogram[i];
		break;
		case 2:
			for(i=0;i<5;i++)
				Bhist[i]=histogram[i];
		break;
	}
	
	/* Set Next Histogram Color */
	if(hist_idx==0)		//Set G
	{
		ENABLE_HISTOGRAM_RLEN;
	}
	else if(hist_idx==1)	//Set B
	{
		DISABLE_HISTOGRAM_RLEN;
		SET_AE_GID_POLARITY_HIGH;
		SET_AE_PID_POLARITY_LOW;
	}
	else if(hist_idx==2)	//Set R
	{
		DISABLE_HISTOGRAM_RLEN;
		SET_AE_GID_POLARITY_LOW;
		SET_AE_PID_POLARITY_HIGH;
	}

}

/****************************************************************************
 *          Auto Exposure 																	 *
 ****************************************************************************/
void ae_config(kal_uint16 Hsize,kal_uint16 Vsize)
{
	kal_uint16	windowH, windowV, startH, startV;
#if (defined(DRV_ISP_6219_SERIES))
	/* offset (1,1) is to avoid hardware bug */
	if(Hsize<64)
		Hsize=64;
	if(Vsize<64)
		Vsize=64;
	/* offset (1,1) is to avoid hardware bug */
	windowH = ((Hsize>>4)-1)/3;		
	windowV = ((Vsize>>4)-1)/3;
	startH = exposure_window.exposure_window_width/32-((windowH*3)>>1)+exposure_window.grab_start_x/16;
	startV = exposure_window.exposure_window_height/32-((windowV*3)>>1)+exposure_window.grab_start_y/16;

	/* window setting is (No., left, top, right, bottom) */
	SET_AE_WINDOW(1, startH,      	  startV,           startH+windowH,   startV+windowV);
	SET_AE_WINDOW(2, startH+windowH,   startV,           startH+windowH*2, startV+windowV);
	SET_AE_WINDOW(3, startH+windowH*2, startV,           startH+windowH*3, startV+windowV);
	SET_AE_WINDOW(4, startH,           startV+windowV,   startH+windowH,   startV+windowV*2);
	SET_AE_WINDOW(5, startH+windowH,   startV+windowV,   startH+windowH*2, startV+windowV*2);
	SET_AE_WINDOW(6, startH+windowH*2, startV+windowV,   startH+windowH*3, startV+windowV*2);
	SET_AE_WINDOW(7, startH,           startV+windowV*2, startH+windowH,   startV+windowV*3);
	SET_AE_WINDOW(8, startH+windowH,   startV+windowV*2, startH+windowH*2, startV+windowV*3);
	SET_AE_WINDOW(9, startH+windowH*2, startV+windowV*2, startH+windowH*3, startV+windowV*3);
#elif (defined(DRV_ISP_6227_SERIES))	
	/* offset (1,1) is to avoid hardware bug */
	if(Hsize<64)
		Hsize=64;
	if(Vsize<64)
		Vsize=64;
	/* offset (1,1) is to avoid hardware bug */
	windowH = ((Hsize>>4)-1)/3;		
	windowV = ((Vsize>>4)-1)/3;
	startH = 0;
	startV = 0;

	/* window setting is (No., left, top, right, bottom) */
	SET_AE_WINDOW(1, startH,      	  startV,           startH+windowH,   startV+windowV);
	SET_AE_WINDOW(2, startH+windowH,   startV,           startH+windowH*2, startV+windowV);
	SET_AE_WINDOW(3, startH+windowH*2, startV,           startH+windowH*3, startV+windowV);
	SET_AE_WINDOW(4, startH,           startV+windowV,   startH+windowH,   startV+windowV*2);
	SET_AE_WINDOW(5, startH+windowH,   startV+windowV,   startH+windowH*2, startV+windowV*2);
	SET_AE_WINDOW(6, startH+windowH*2, startV+windowV,   startH+windowH*3, startV+windowV*2);
	SET_AE_WINDOW(7, startH,           startV+windowV*2, startH+windowH,   startV+windowV*3);
	SET_AE_WINDOW(8, startH+windowH,   startV+windowV*2, startH+windowH*2, startV+windowV*3);
	SET_AE_WINDOW(9, startH+windowH*2, startV+windowV*2, startH+windowH*3, startV+windowV*3);
	SET_AE_FRAME_INTERVAL(camera_oper_data.ae_awb_cal_period-1);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	/* use 8x7 window, total 9X7 window */
	windowH=(((Hsize-8)/8)*2+1)/2;	//add rounding for small target size
	windowV=(Vsize/7)+1;
	startH=0;
	startV=0;
	SET_AE_WINDOW_HSIZE(windowH);
	SET_AE_WINDOW_VSIZE(windowV);
	SET_AE_H_OFFSET(startH);				
	SET_AE_V_OFFSET(startV);

	REG_ISP_AE_ADDRESS=(kal_uint32)ae_result;
	SET_AE_FRAME_INTERVAL(camera_oper_data.ae_awb_cal_period-1);
#endif	
}

void ae_set_pregain(kal_uint16 pre_gain)
{
#if (defined(DRV_ISP_6219_SERIES))
	switch(camera_oper_data.pregain_mode)
	{
		case ISP_ONLY:
			if(pre_gain>=camera_oper_data.isp_pregain_max)
				isp_pregain=camera_oper_data.isp_pregain_max;
			else if(pre_gain<PREGAIN_MIN_LIMIT)
				isp_pregain=PREGAIN_MIN_LIMIT;
			else
				isp_pregain=pre_gain;
				
			ae_set_isp_pregain();
		break;
		case SENSOR_ONLY:
			if(pre_gain>=camera_oper_data.sensor_pregain_max)
				sensor_pregain=camera_oper_data.sensor_pregain_max;
			else if(pre_gain<camera_oper_data.sensor_pregain_min)
				sensor_pregain=camera_oper_data.sensor_pregain_min;
			else
				sensor_pregain=pre_gain;
				
			image_sensor_func->set_sensor_gain(sensor_pregain);
		break;
		case ISP_SENSOR_BOTH:
			if(camera_oper_data.gain_priority==ISP_GAIN_PRIORITY)
			{
				if(pre_gain>=camera_oper_data.isp_pregain_max)
				{
					isp_pregain=camera_oper_data.isp_pregain_max;
					sensor_pregain=(pre_gain<<6)/camera_oper_data.isp_pregain_max;
					if(sensor_pregain>=camera_oper_data.sensor_pregain_max)
						sensor_pregain=camera_oper_data.sensor_pregain_max;
					else if(sensor_pregain<camera_oper_data.sensor_pregain_min)
						sensor_pregain=camera_oper_data.sensor_pregain_min;
				}
				else if(pre_gain<camera_oper_data.isp_pregain_min)
				{
					isp_pregain=camera_oper_data.isp_pregain_min;
					sensor_pregain=0x40;
				}
				else
				{
					isp_pregain=pre_gain;
					sensor_pregain=0x40;
				}
				ae_set_isp_pregain();
				image_sensor_func->set_sensor_gain(sensor_pregain);
			}
			else if(camera_oper_data.gain_priority==SENSOR_GAIN_PRIORITY)
			{
				if(pre_gain>camera_oper_data.sensor_pregain_max)
				{
					sensor_pregain = image_sensor_func->set_sensor_gain(camera_oper_data.sensor_pregain_max);
					
					if(sensor_pregain<BASEGAIN)
						sensor_pregain = BASEGAIN;
					isp_pregain=(pre_gain<<6)/sensor_pregain;
					if(isp_pregain>=camera_oper_data.isp_pregain_max)
						isp_pregain=camera_oper_data.isp_pregain_max;
					else if(isp_pregain<camera_oper_data.isp_pregain_min)
						isp_pregain=camera_oper_data.isp_pregain_min;

					ae_set_isp_pregain();
				}
				else if(pre_gain<camera_oper_data.sensor_pregain_min)
				{
					sensor_pregain=image_sensor_func->set_sensor_gain(camera_oper_data.sensor_pregain_min);

					isp_pregain=0x40;
					ae_set_isp_pregain();
				}
				else
				{
					sensor_pregain=image_sensor_func->set_sensor_gain(pre_gain);

					if(sensor_pregain<BASEGAIN)
						sensor_pregain = BASEGAIN;
					isp_pregain=(pre_gain<<6)/sensor_pregain;

					ae_set_isp_pregain();
				}
			}
			else
			 	ASSERT(0);
		break;
	}
#endif
}

void ae_set_lut_gain(void)
{
#if (!defined(DRV_ISP_6219_SERIES))
	switch(camera_oper_data.pregain_mode)
	{
		case ISP_ONLY:
			ae_set_isp_pregain();
		break;
		case SENSOR_ONLY:
			image_sensor_func->set_sensor_gain(sensor_pregain);
		break;
		case ISP_SENSOR_BOTH:
			image_sensor_func->set_sensor_gain(sensor_pregain);
			ae_set_isp_pregain();
		break;
	}
#endif
}

void ae_set_isp_pregain(void)
{
		SET_PRE_GAIN_INTEGER_PART(isp_pregain>>6);	
		SET_PRE_GAIN_FRAC_PART((0xFC & (isp_pregain << 2)));	/* LSB is not used bit */
}

void ae_set_ini_shutter(kal_uint16 shutter)
{
	if(ae_enable_flag == ISP_OFF)
	{
		camera_para.AE.iniShutter=shutter;
		eShutter=camera_para.AE.iniShutter;
		image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
	}
}

kal_uint16 ae_get_ini_shutter(void)
{
	return camera_para.AE.iniShutter;
}

void ae_select_stepperev(kal_uint8 step)
{
	switch(step)
	{
		case ONE_STEP:
			camera_para.AE.StepperEV=step;
			/* -3EV ~ +3EV */
			totalevstep=7;		
			break;
		case TWO_STEP:
			camera_para.AE.StepperEV=step;
			/* -2EV ~ +2EV */
			totalevstep=9;		
			break;
		case THREE_STEP:
			camera_para.AE.StepperEV=step;
			/* -2EV ~ +2EV */
			totalevstep=13;	
			break;
		case FOUR_STEP:
			camera_para.AE.StepperEV=step;
			/* -1EV ~ +1EV */
			totalevstep=9;		
			break;
		default:
			camera_para.AE.StepperEV=TWO_STEP;
			/* -2EV ~ +2EV */
			totalevstep=9;		
			break;
	}
}

kal_uint8 ae_get_totalevlevel(void)
{
	return totalevstep;
}

kal_uint8 ae_get_stepperev(void)
{
	return camera_para.AE.StepperEV;
}

kal_uint8 ae_set_ev(kal_int8 level)
{
	kal_uint8 ampstep;
	kal_int16 expovalue=(kal_int16)(camera_para.AE.TargetLum);
	
	ampstep=(totalevstep-1)>>1;
	if((level>ampstep)||(level<-ampstep))
	{
		return KAL_FALSE;
	}
	else
	{
		ev_level=level;

		switch(ev_level)
		{
			case 4:
				expovalue=(kal_int16)(camera_para.AE.TargetLum*2.07);
				break;
			case 3:
#if(defined(AF_Debug_Function))
				expovalue=(kal_int16)(camera_para.AE.TargetLum);
				AF_Debug_Flag_Update(AF_Debug_Flag_Normal);
#else
				expovalue=(kal_int16)(camera_para.AE.TargetLum*1.73);
#endif
				break;
			case 2:
#if(defined(AF_Debug_Function))
				expovalue=(kal_int16)(camera_para.AE.TargetLum);
				AF_Debug_Flag_Update(AF_Debug_Flag_Continue);
#else				
				expovalue=(kal_int16)(camera_para.AE.TargetLum*1.44);
#endif
				break;
			case 1:
#if(defined(AF_Debug_Function))
				expovalue=(kal_int16)(camera_para.AE.TargetLum);
				AF_Debug_Flag_Update(AF_Debug_Flag_FullScan);
#else				
				expovalue=(kal_int16)(camera_para.AE.TargetLum*1.2);
#endif
				break;
			case 0:
#if(defined(AF_Debug_Function))
				expovalue=(kal_int16)(camera_para.AE.TargetLum);
				AF_Debug_Flag_Update(AF_Debug_Flag_Normal);
#else							
				expovalue=(kal_int16)(camera_para.AE.TargetLum);
#endif
				break;
			case -1:
				expovalue=(kal_int16)(camera_para.AE.TargetLum/1.2);
				break;
			case -2:
				expovalue=(kal_int16)(camera_para.AE.TargetLum/1.44);
				break;
			case -3:
				expovalue=(kal_int16)(camera_para.AE.TargetLum/1.73);
				break;
			case -4:
				expovalue=(kal_int16)(camera_para.AE.TargetLum/2.07);
				break;
			default:
				ASSERT(0);
				break;
		}		

		if(expovalue>255)
		{
			expovalue=255;
		}
		if(expovalue<0)
		{
			expovalue=0;
		}
		expo_level = expovalue;
		high_expo_level=expovalue*(100+ae_range)/100;
		low_expo_level=expovalue*(100-ae_range)/100;		

		return KAL_TRUE;
	}
}

kal_int8 ae_get_ev_level(void)
{
	return ev_level;
}

void ae_set_expovalue(kal_uint8 target)
{
	expo_level = target;
	camera_para.AE.TargetLum = target;
	high_expo_level=target*(100+ae_range)/100;
	low_expo_level=target*(100-ae_range)/100;		
}

kal_uint8 ae_get_expovalue(void)
{
	return expo_level;
}

void ae_set_shutter(kal_uint16 lines)
{
	eShutter=lines;
	image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
}

kal_uint16 ae_get_current_shutter(void)
{
	return (kal_uint16)eShutter;
}

kal_uint32 get_shutter_from_time(kal_uint32 time, kal_uint16 pixel_width)
{
	kal_uint32 pixelclk, line;
	
#if (defined(MCU_52M)||defined(MCU_104M))
	pixelclk=((kal_uint32)(52000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));
#elif (defined(MCU_26M))
	pixelclk=((kal_uint32)(26000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));
#endif

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))	
	if((REG_ISP_TG_PHASE_COUNTER & REG_TGPC_PIXEL_CLK_SELECT_BIT)!= 0)
		pixelclk=((kal_uint32)(48000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));
#endif
	
	line=pixelclk*time/pixel_width;

	return line;	
}

#if (!defined(DRV_ISP_6219_SERIES))
void ae_set_ini_expo_idx(kal_uint8 idx)
{
	camera_para.AE.iniExpoIdx = idx;
}

kal_uint8 ae_get_ini_expo_idx(void)
{
	return camera_para.AE.iniExpoIdx;
}
#endif
/****************************************************************************
 *          SHUTTER APERTURE PRIORITY													*
 ****************************************************************************/
#if (!defined(DRV_ISP_6219_SERIES))
void get_shutter_priority_info(kal_uint8 tv_index, shutter_info_struct *tv_data)
{
	tv_data->value=tv_av_info.tv[tv_index].value;
	tv_data->prtinfo=tv_av_info.tv[tv_index].prtinfo;
}

void get_aperture_priority_info(kal_uint8 av_index, aperture_info_struct *av_data)
{
	av_data->value=tv_av_info.av[av_index].value;
	av_data->prtinfo=tv_av_info.av[av_index].prtinfo;
}
#endif

/****************************************************************************
 *          EXIF																				 *
 ****************************************************************************/
#if ((!defined(DRV_ISP_6219_SERIES))&&defined(EXIF_SUPPORT))
kal_uint16 exif_ISO_speed_cal(void)
{
	kal_int32 i, iso_val;
	if (ae_iso_sensor_gain_info.ISO_sensor_gain == 0)
	{
		return 100;/* sensor gain array of camera_info.c not allocated */		
	}
	if (ae_iso_sensor_gain_info.ISO_sensor_gain_no == 0)
	{
		return 100;/* sensor gain array of camera_info.c not allocated */		
	}
	if (camera_oper_data.AE_ISO_EXIF_Report_Standard_Enable == KAL_TRUE)
	{
		if ((dsc_status.dscmode == CAM_ISO_MODE) && (dsc_status.ae.iso != CAM_ISO_AUTO))
		{
			if (dsc_status.ae.iso == CAM_ISO_100)
			{
				return 100;	
			}
			if (dsc_status.ae.iso == CAM_ISO_200)
			{
				return 200;	
			}
			if (dsc_status.ae.iso == CAM_ISO_400)
			{
				return 400;	
			}
		}
	}
	if (sensor_pregain <= camera_para.ISO_PRIORITY_INFO.ISO_Gain[0])/* G <= G_low */
	{	
		if (camera_para.ISO_PRIORITY_INFO.ISO_Gain[0] == sensor_pregain)/* G = G_low */
		{
			iso_val = camera_para.ISO_PRIORITY_INFO.ISO_Value[0];
		}	
		else
		{
			iso_val = sensor_pregain*camera_para.ISO_PRIORITY_INFO.ISO_Value[0]/camera_para.ISO_PRIORITY_INFO.ISO_Gain[0];	
		}
	}
	else/* G > G_low */
	{
		if (sensor_pregain < camera_para.ISO_PRIORITY_INFO.ISO_Gain[1])/* G < G_mid */
		{
			iso_val = camera_para.ISO_PRIORITY_INFO.ISO_Value[1] -
				(camera_para.ISO_PRIORITY_INFO.ISO_Gain[1] - sensor_pregain)*
				(camera_para.ISO_PRIORITY_INFO.ISO_Value[1] - camera_para.ISO_PRIORITY_INFO.ISO_Value[0])/
				(camera_para.ISO_PRIORITY_INFO.ISO_Gain[1] - camera_para.ISO_PRIORITY_INFO.ISO_Gain[0]);
		}
		else if (sensor_pregain < camera_para.ISO_PRIORITY_INFO.ISO_Gain[2])/* G >= G_mid & G < G_high */
		{		
			if (camera_para.ISO_PRIORITY_INFO.ISO_Gain[1] == sensor_pregain)/* G = G_mid */
			{
				iso_val = camera_para.ISO_PRIORITY_INFO.ISO_Value[1];
			}	
			else/* G != G_mid */
			{
				iso_val = camera_para.ISO_PRIORITY_INFO.ISO_Value[2] -
					(camera_para.ISO_PRIORITY_INFO.ISO_Gain[2] - sensor_pregain)*
					(camera_para.ISO_PRIORITY_INFO.ISO_Value[2] - camera_para.ISO_PRIORITY_INFO.ISO_Value[1])/
					(camera_para.ISO_PRIORITY_INFO.ISO_Gain[2] - camera_para.ISO_PRIORITY_INFO.ISO_Gain[1]);
			}
		}
		else/* G >= G_high */
		{
			if (camera_para.ISO_PRIORITY_INFO.ISO_Gain[2] == sensor_pregain)/* G = G_high */
			{
				iso_val = camera_para.ISO_PRIORITY_INFO.ISO_Value[2];
			}	
			else
			{
				iso_val = sensor_pregain*camera_para.ISO_PRIORITY_INFO.ISO_Value[2]/camera_para.ISO_PRIORITY_INFO.ISO_Gain[2];
			}
		}	
	}
	if (camera_oper_data.AE_ISO_EXIF_Report_Standard_Enable == KAL_TRUE)
	{	
		if (iso_val >= 400)
		{
			iso_val = 400;
		}
		else if (iso_val <= 100)
		{
			iso_val = 100;		
		}
	}
	for (i=exif_iso_count-1;i>=0;i--)
	{
		if (exif_iso_speed[i] <= iso_val)
		{
			return exif_iso_speed[i];
		}
	}
	return exif_iso_speed[0];	
}

void exif_update_cam_para_struct(exif_cam_para_struct *exif_para)
{
	kal_uint8 meteringmode=0,lightsource=0,scenetype=0;
	
	if(dsc_status.ae.metering==CAM_AE_METER_AUTO)
		meteringmode=0;
	else if(dsc_status.ae.metering==CAM_AE_METER_AVERAGE)
		meteringmode=1;
	else if(dsc_status.ae.metering==CAM_AE_METER_CENTRAL)
		meteringmode=2;
	else if(dsc_status.ae.metering==CAM_AE_METER_SPOT)
		meteringmode=3;
	else
		meteringmode=0;

	if(isp_preview_config_data.wb_mode==CAM_WB_AUTO)
		lightsource=0;
	else if(isp_preview_config_data.wb_mode==CAM_WB_DAYLIGHT)
		lightsource=1;
	else if(isp_preview_config_data.wb_mode==CAM_WB_FLUORESCENT)
		lightsource=2;
	else if(isp_preview_config_data.wb_mode==CAM_WB_TUNGSTEN)
		lightsource=3;
	else if(isp_preview_config_data.wb_mode==CAM_WB_INCANDESCENCE)
		lightsource=4;
	else 
		lightsource=0;

	if(dsc_status.dscmode==CAM_AUTO_DSC)
		scenetype=0;
	if(dsc_status.dscmode==CAM_LANDSCAPE)
		scenetype=1;
	if(dsc_status.dscmode==CAM_PORTRAIT)
		scenetype=2;
	if(dsc_status.dscmode==CAM_NIGHTSCENE)
		scenetype=3;
	else
		scenetype=0;

	/* Exif IFD default values */
	if (CAM_ISO_MODE == dsc_status.dscmode)
	{
		if (eShutter*isp_pregain >= BaseShutter*120*64)
		{
			exif_para->ExposureTime[0]=eShutter*isp_pregain/(120*64*BaseShutter);
			exif_para->ExposureTime[1]=1;
		}
		else
		{
			exif_para->ExposureTime[0]=1;
			exif_para->ExposureTime[1]=BaseShutter*120*64/(eShutter*isp_pregain);
		}	
	}
	else
	{
		if (eShutter >= BaseShutter*120)
		{
			exif_para->ExposureTime[0]=eShutter/(120*BaseShutter);
			exif_para->ExposureTime[1]=1;
		}
		else
		{
			exif_para->ExposureTime[0]=1;
			exif_para->ExposureTime[1]=BaseShutter*120/eShutter;
		}
	}
//	exif_para->FNumber[0]=0;
//	exif_para->FNumber[1]=0;

	exif_para->ExposureProgram=2;

//	exif_para->ISOSpeedRatings=100;
	exif_para->ISOSpeedRatings=exif_ISO_speed_cal();

	
	exif_para->ExposureBiasValue[0]=ev_level;
	exif_para->ExposureBiasValue[1]=1;
	
	exif_para->MeteringMode=meteringmode;
	
	exif_para->LightSource=lightsource;

   if( flashlight_operation_state==FLASHLIGHT_MAIN_STROBE_STATE )	   
      exif_para->Flash=KAL_TRUE;
   else
	   exif_para->Flash=KAL_FALSE;

	exif_para->PixelXDimension=exif_isp_target_width;
	exif_para->PixelYDimension=exif_isp_target_height;
		
	exif_para->DigitalZoomRatio[0]=isp_digital_zoom_factor;
	exif_para->DigitalZoomRatio[1]=10;

	exif_para->SceneCaptureType=scenetype;
}
#endif	

#if (!defined(DRV_ISP_6219_SERIES))/* AE smooth */
/* init default para & output data table */
void AE_Smooth_Init(void)
{
	camera_oper_data.AE_Smooth_Enable = KAL_FALSE;
	/* init preview para by default */
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Median_Filter_Tape = 3;//0~AE_Smooth_Filter_Max_Tape
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Normal_Last_Weight = 100;//0~128
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Normal_Max_Step = 1;//0~AE_Normal_Max_Step_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Last_Weight = 5;//0~128
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Max_Step = 65;//0~AE_Smooth_Fast_Max_Step_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Min_Step =3;//AE_Smooth_Fast_Min_Step_bound~AE_Smooth_Fast_Max_step
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Check_Count = 1;//0~AE_Smooth_Fast_Check_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Transition_Count = 0;//0~AE_Smooth_Fast_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Back_Count = 3;//0~AE_Smooth_Fast_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_TH_Fast = 12;//AE_Smooth_Fast_TH_Normal~AE_Smooth_Fast_TH_Fast_Bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_TH_Normal = 2;//AE_Smooth_Fast_TH_Normal_Bound~AE_Smooth_Fast_TH_Fast
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Gap_Ratio = 96;//Converge fast with target gap 0~128	
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Gap_TH = 7;//Converge fast larger than TH = 0.7
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Last_Weight = 48;//0~128
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Max_Step = 2;//AE_Smooth_Speed_Min_step~AE_Smooth_Speed_Max_step_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Check_Count = 2;//0~AE_Smooth_Speed_Check_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Transition_Count = 2;//0~AE_Smooth_Speed_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Back_Count = 2;//0~AE_Smooth_Speed_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Target_Diff_TH_Speed = 1;//0~AE_Smooth_Speed_Target_Diff_TH_Normal
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Target_Diff_TH_Normal = 2;//0~AE_Smooth_Speed_Target_Diff_TH_Normal_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_dEv_Normal = 4;//AE_Smooth_Speed_Stop_dEv_bound~AE_Smooth_Fast_TH_Fast
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Last_Weight = 48;//0~128
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Max_Step = 2;//0~AE_Smooth_Ramp_Max_Step_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Check_Count = 4;//0~AE_Smooth_Ramp_Check_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Transition_Count = 2;//0~AE_Smooth_Ramp_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Back_Count = 2;//0~AE_Smooth_Ramp_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_TH_Ramp = 4;//AE_Smooth_Ramp_TH_Normal~AE_Smooth_Ramp_TH_Ramp_Bound
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_TH_Normal = 2;//AE_Smooth_Ramp_TH_Normal_Bound~AE_Smooth_Ramp_TH_Ramp
	camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Final_Tol = 64;//0~256,0.1 Ev one step, divide by 256
	/* init video para by default */
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Median_Filter_Tape = 3;//0~AE_Smooth_Filter_Max_Tape
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Normal_Last_Weight = 110;//0~128
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Normal_Max_Step = 1;//0~AE_Normal_Max_Step_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Last_Weight = 5;//0~128
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Max_Step = 25;//0~AE_Smooth_Fast_Max_Step_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Min_Step = 2;//AE_Smooth_Fast_Min_Step_bound~AE_Smooth_Fast_Max_step
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Check_Count = 2;//0~AE_Smooth_Fast_Check_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Transition_Count = 1;//0~AE_Smooth_Fast_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Back_Count = 3;//0~AE_Smooth_Fast_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_TH_Fast = 12;//AE_Smooth_Fast_TH_Normal~AE_Smooth_Fast_TH_Fast_Bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_TH_Normal = 5;//AE_Smooth_Fast_TH_Normal_Bound~AE_Smooth_Fast_TH_Fast
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Gap_Ratio = 96;//Converge fast with target gap 0~128	
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Gap_TH = 7;//Converge fast larger than TH = 0.7
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Last_Weight = 96;//0~128
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Max_Step = 1;//AE_Smooth_Speed_Min_step~AE_Smooth_Speed_Max_step_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Check_Count = 4;//0~AE_Smooth_Speed_Check_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Transition_Count = 2;//0~AE_Smooth_Speed_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Back_Count = 2;//0~AE_Smooth_Speed_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Target_Diff_TH_Speed = 0;//0~AE_Smooth_Speed_Target_Diff_TH_Normal
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Target_Diff_TH_Normal = 1;//0~AE_Smooth_Speed_Target_Diff_TH_Normal_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_dEv_Normal = 4;//AE_Smooth_Speed_Stop_dEv_bound~AE_Smooth_Fast_TH_Fast
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Last_Weight = 96;//0~128
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Max_Step = 1;//0~AE_Smooth_Ramp_Max_Step_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Check_Count = 8;//0~AE_Smooth_Ramp_Check_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Transition_Count = 2;//0~AE_Smooth_Ramp_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Back_Count = 2;//0~AE_Smooth_Ramp_Transition_Count_bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_TH_Ramp = 6;//AE_Smooth_Ramp_TH_Normal~AE_Smooth_Ramp_TH_Ramp_Bound
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_TH_Normal = 4;//AE_Smooth_Ramp_TH_Normal_Bound~AE_Smooth_Ramp_TH_Ramp
	camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Final_Tol = 64;//0~256,0.1 Ev one step, divide by 256
}

void init_ae_smooth_custom_para(AE_SMOOTH_MODE_INDEX mode)
{
	if (AE_SMOOTH_VIDEO == mode)
	{
		/* update by custom para */
		Filter_para.AE_Smooth_Median_Filter_Tape = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Median_Filter_Tape;
		Filter_para.AE_Smooth_Normal_Last_Weight = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Normal_Last_Weight;
		Filter_para.AE_Smooth_Normal_Max_Step = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Normal_Max_Step;
		Filter_para.AE_Smooth_Fast_Last_Weight = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Last_Weight;
		Filter_para.AE_Smooth_Fast_Max_Step = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Max_Step;
		Filter_para.AE_Smooth_Fast_Min_Step =camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Min_Step;
		Filter_para.AE_Smooth_Fast_Check_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Check_Count;
		Filter_para.AE_Smooth_Fast_Transition_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Transition_Count;
		Filter_para.AE_Smooth_Fast_Back_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Back_Count;
		Filter_para.AE_Smooth_Fast_TH_Fast = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_TH_Fast;
		Filter_para.AE_Smooth_Fast_TH_Normal = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_TH_Normal;
		Filter_para.AE_Smooth_Fast_Gap_Ratio = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Gap_Ratio;
		Filter_para.AE_Smooth_Fast_Gap_TH = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Fast_Gap_TH;
		Filter_para.AE_Smooth_Speed_Last_Weight = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Last_Weight;
		Filter_para.AE_Smooth_Speed_Max_Step = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Max_Step;
		Filter_para.AE_Smooth_Speed_Check_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Check_Count;
		Filter_para.AE_Smooth_Speed_Transition_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Transition_Count;
		Filter_para.AE_Smooth_Speed_Back_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Back_Count;
		Filter_para.AE_Smooth_Speed_Target_Diff_TH_Speed = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Target_Diff_TH_Speed;
		Filter_para.AE_Smooth_Speed_Target_Diff_TH_Normal = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_Target_Diff_TH_Normal;
		Filter_para.AE_Smooth_Speed_dEv_Normal = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Speed_dEv_Normal;
		Filter_para.AE_Smooth_Ramp_Last_Weight = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Last_Weight;
		Filter_para.AE_Smooth_Ramp_Max_Step = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Max_Step;
		Filter_para.AE_Smooth_Ramp_Check_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Check_Count;
		Filter_para.AE_Smooth_Ramp_Transition_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Transition_Count;
		Filter_para.AE_Smooth_Ramp_Back_Count = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_Back_Count;
		Filter_para.AE_Smooth_Ramp_TH_Ramp = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_TH_Ramp;
		Filter_para.AE_Smooth_Ramp_TH_Normal = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Ramp_TH_Normal;
		Filter_para.AE_Smooth_Final_Tol = camera_oper_data.Smooth_Filter_Para_Video.AE_Smooth_Final_Tol;
	}
	else
	{
		/* update by custom para */
		Filter_para.AE_Smooth_Median_Filter_Tape = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Median_Filter_Tape;
		Filter_para.AE_Smooth_Normal_Last_Weight = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Normal_Last_Weight;
		Filter_para.AE_Smooth_Normal_Max_Step = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Normal_Max_Step;
		Filter_para.AE_Smooth_Fast_Last_Weight = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Last_Weight;
		Filter_para.AE_Smooth_Fast_Max_Step = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Max_Step;
		Filter_para.AE_Smooth_Fast_Min_Step =camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Min_Step;
		Filter_para.AE_Smooth_Fast_Check_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Check_Count;
		Filter_para.AE_Smooth_Fast_Transition_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Transition_Count;
		Filter_para.AE_Smooth_Fast_Back_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Back_Count;
		Filter_para.AE_Smooth_Fast_TH_Fast = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_TH_Fast;
		Filter_para.AE_Smooth_Fast_TH_Normal = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_TH_Normal;
		Filter_para.AE_Smooth_Fast_Gap_Ratio = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Gap_Ratio;
		Filter_para.AE_Smooth_Fast_Gap_TH = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Fast_Gap_TH;
		Filter_para.AE_Smooth_Speed_Last_Weight = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Last_Weight;
		Filter_para.AE_Smooth_Speed_Max_Step = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Max_Step;
		Filter_para.AE_Smooth_Speed_Check_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Check_Count;
		Filter_para.AE_Smooth_Speed_Transition_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Transition_Count;
		Filter_para.AE_Smooth_Speed_Back_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Back_Count;
		Filter_para.AE_Smooth_Speed_Target_Diff_TH_Speed = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Target_Diff_TH_Speed;
		Filter_para.AE_Smooth_Speed_Target_Diff_TH_Normal = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_Target_Diff_TH_Normal;
		Filter_para.AE_Smooth_Speed_dEv_Normal = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Speed_dEv_Normal;
		Filter_para.AE_Smooth_Ramp_Last_Weight = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Last_Weight;
		Filter_para.AE_Smooth_Ramp_Max_Step = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Max_Step;
		Filter_para.AE_Smooth_Ramp_Check_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Check_Count;
		Filter_para.AE_Smooth_Ramp_Transition_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Transition_Count;
		Filter_para.AE_Smooth_Ramp_Back_Count = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_Back_Count;
		Filter_para.AE_Smooth_Ramp_TH_Ramp = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_TH_Ramp;
		Filter_para.AE_Smooth_Ramp_TH_Normal = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Ramp_TH_Normal;
		Filter_para.AE_Smooth_Final_Tol = camera_oper_data.Smooth_Filter_Para_Preview.AE_Smooth_Final_Tol;
	}
	AE_Smooth_Check_Input_Clear_Table();
}

void ae_iso_priority_Init(void)
{
	camera_oper_data.AE_ISO_Highlight_Comp_Enable = KAL_FALSE;
	camera_oper_data.AE_ISO_Lowlight_Comp_Enable = KAL_FALSE;	
	camera_oper_data.AE_ISO_EXIF_Report_Standard_Enable = KAL_TRUE;
}

/* check idx max & min for ISO mode impact */
void ae_lut_max_min_idx_iso_update(kal_uint8 cam_mode, kal_uint8 iso_mode)
{
	kal_int32 i, j;
	kal_int32 high, low;
	kal_int32 k, m, temp_gain, current_gain;
	if ((CAM_ISO_MODE != cam_mode) ||
		((CAM_ISO_MODE == cam_mode) && (CAM_ISO_AUTO == iso_mode)))
	{
		ae_min_idx = 0;
		for (i=1;i<device_support_info.ae.lutsize;i++)
		{
			if (AE_LUT[i-1].shutter == AE_LUT[i].shutter)
			{
				if (AE_LUT[i-1].sensorgain == AE_LUT[i].sensorgain)
				{
					if (AE_LUT[i-1].ispgain == AE_LUT[i].ispgain)
					{
						ae_min_idx	= i;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}	
		}
		ae_max_idx = device_support_info.ae.lutsize - 1;
		for (i=device_support_info.ae.lutsize-2;i>=0;i--)
		{
			if (AE_LUT[i+1].shutter == AE_LUT[i].shutter)
			{
				if (AE_LUT[i+1].sensorgain == AE_LUT[i].sensorgain)
				{
					if (AE_LUT[i+1].ispgain == AE_LUT[i].ispgain)
					{
						ae_max_idx	= i;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}	
			else
			{
				break;
			}	
		}	
	}
	else/* ISO 100, 200, 400 */
	{
		/* check sensor gain array allocated correctly */
		if (ae_iso_sensor_gain_info.ISO_sensor_gain_no != device_support_info.ae.lutsize)
		{
			ASSERT(0);/* sensor gain array of camera_info.c not allocated correctly */
		}
		if (ae_iso_sensor_gain_info.ISO_sensor_gain == 0)
		{
			ASSERT(0);/* sensor gain array of camera_info.c not allocated correctly */		
		}
		if (ae_iso_sensor_gain_info.ISO_sensor_gain_no == 0)
		{
			ASSERT(0);/* sensor gain array of camera_info.c not allocated correctly */		
		}
		/* check sensor gain */
		if (CAM_ISO_200 == iso_mode)
		{
			for (i=0;i<ae_iso_sensor_gain_info.ISO_sensor_gain_no;i++)
			{
				ae_iso_sensor_gain_info.ISO_sensor_gain[i] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[1];
			}
			current_gain = camera_para.ISO_PRIORITY_INFO.ISO_Gain[1];
		}
		else if (CAM_ISO_400 == iso_mode)
		{
			for (i=0;i<ae_iso_sensor_gain_info.ISO_sensor_gain_no;i++)
			{
				ae_iso_sensor_gain_info.ISO_sensor_gain[i] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[2];
			}
			current_gain = camera_para.ISO_PRIORITY_INFO.ISO_Gain[2];
		}
		else
		{
			for (i=0;i<ae_iso_sensor_gain_info.ISO_sensor_gain_no;i++)
			{
				ae_iso_sensor_gain_info.ISO_sensor_gain[i] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[0];
			}
			current_gain = camera_para.ISO_PRIORITY_INFO.ISO_Gain[0];				
		}
		low = -1;
		if (camera_oper_data.AE_ISO_Highlight_Comp_Enable == KAL_TRUE)
		{						
			for (i=0;i<ae_iso_sensor_gain_info.ISO_sensor_gain_no-1;i++)
			{
				if ((AE_LUT[i].shutter != AE_LUT[i+1].shutter)||(AE_LUT[i].ispgain != AE_LUT[i+1].ispgain))
				{
					low = i-1;
					break;
				}
			}	
		}
		high = ae_iso_sensor_gain_info.ISO_sensor_gain_no;			
		if (camera_oper_data.AE_ISO_Lowlight_Comp_Enable == KAL_TRUE)
		{
			for (i=ae_iso_sensor_gain_info.ISO_sensor_gain_no-1;i>=1;i--)
			{
				if ((AE_LUT[i].shutter != AE_LUT[i-1].shutter)||(AE_LUT[i].ispgain != AE_LUT[i-1].ispgain))
				{
					high = i+1;
					break;
				}
			}
		}
		/* set low sensor gain */	
		m = ae_iso_sensor_gain_info.ISO_sensor_gain_no-1;
		temp_gain = current_gain;
		for (j=low;j>=0;j--)
		{
			for (k=m;k>=0;k--)
			{
				if (temp_gain < AE_LUT[k].sensorgain)
				{
					temp_gain = AE_LUT[k].sensorgain;
					ae_iso_sensor_gain_info.ISO_sensor_gain[j] = AE_LUT[k].sensorgain;
					m = k;
					break;
				}
				if (k == 0)
				{
					ae_iso_sensor_gain_info.ISO_sensor_gain [j] = temp_gain;
					m = 0;
				}
			}
		}
		/* set high sensor gain */
		m = 0;
		temp_gain = current_gain;
		for (j=high;j<ae_iso_sensor_gain_info.ISO_sensor_gain_no;j++)
		{
			for (k=m;k<ae_iso_sensor_gain_info.ISO_sensor_gain_no;k++)
			{
				if (temp_gain > AE_LUT[k].sensorgain)
				{
					temp_gain = AE_LUT[k].sensorgain;
					ae_iso_sensor_gain_info.ISO_sensor_gain[j] = AE_LUT[k].sensorgain;
					m = k;
					break;
				}
				if (k == ae_iso_sensor_gain_info.ISO_sensor_gain_no - 1)
				{
					ae_iso_sensor_gain_info.ISO_sensor_gain [j] = temp_gain;
					m = ae_iso_sensor_gain_info.ISO_sensor_gain_no - 1;
				}
			}
		}
		/* check idx boundary */
		ae_min_idx = 0;
		for (i=1;i<ae_iso_sensor_gain_info.ISO_sensor_gain_no;i++)
		{
			if (AE_LUT[i-1].shutter == AE_LUT[i].shutter)
			{
				if (ae_iso_sensor_gain_info.ISO_sensor_gain[i-1] == ae_iso_sensor_gain_info.ISO_sensor_gain[i])
				{
					if (AE_LUT[i-1].ispgain == AE_LUT[i].ispgain)
					{
						ae_min_idx	= i;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}	
		}
		ae_max_idx = ae_iso_sensor_gain_info.ISO_sensor_gain_no - 1;
		for (i=ae_iso_sensor_gain_info.ISO_sensor_gain_no-2;i>=0;i--)
		{
			if (AE_LUT[i+1].shutter == AE_LUT[i].shutter)
			{
				if (ae_iso_sensor_gain_info.ISO_sensor_gain[i+1] == ae_iso_sensor_gain_info.ISO_sensor_gain[i])
				{
					if (AE_LUT[i+1].ispgain == AE_LUT[i].ispgain)
					{
						ae_max_idx	= i;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}	
			else
			{
				break;
			}	
		}	
	}
}
#endif

/****************************************************************************
 *          Flash Light	Control 											 *
 ****************************************************************************/
extern kal_uint32	window_pixel_num;
/*************************************************************************
* FUNCTION
*	flashlight_ae_cal
*
* DESCRIPTION
*	Flash light cal ae process. 
*
* PARAMETERS
*	None
*
* RETURNS
*	lum when flash on
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32  flashlight_ae_cal(void)
{
#if (defined(LED_FLASHLIGHT_SUPPORT)||defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
    kal_uint32  i, j;           	    
    kal_uint32  tmp_lum=0;
    #if (defined(DRV_ISP_6227_SERIES))
    for(i=0;i<9;i++)
        tmp_lum += (lum[i]>>8)/(window_pixel_num<<4);
    tmp_lum = (tmp_lum*21)/9;       	/* Check Factor : 21/16 */                
    #elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	for(i=0;i<7;i++)
		for(j=0;j<8;j++)	/* total 9, use 8 windows */
			tmp_lum += (ae_result[i][j]/window_pixel_num);
    tmp_lum = ((tmp_lum*21)>>4)/56;		    		
    #endif
    
    return tmp_lum;
#else
    return 0;
#endif
}

kal_uint32  flashlight_ae_proc(void)
{
#if (defined(LED_FLASHLIGHT_SUPPORT))		    
    kal_uint32  i;
    /* Cal pre strobe lum */
    if((avglum>expo_level)&&(flashlight_lum>avglum))
        flashlight_lum -= (avglum-expo_level);
	for(i=FLASHLIGHT_CENTER_AE_NUM; i<=FLASHLIGHT_MAX_AE_NUM; i++)
	{
		if(flashlight_lum <= ((EVSTEP_FLASH_01[i]*expo_level)>>7))
		{
			flashlight_idx += (i-FLASHLIGHT_CENTER_AE_NUM);
			fake_sub_flash_frame_flag = KAL_FALSE;
			break;
		}
	}   
	/* if avglum < normal lum when flash off, check over sat */
    if( avglum<((EVSTEP_FLASH_01[FLASHLIGHT_CENTER_AE_NUM-1]*expo_level)>>7) )
    {   /* When over brightness */
        if((flashlight_lum > ((EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_NUM]*expo_level)>>7))&&(AE_INDEX==0))
        {
    		for(i=FLASHLIGHT_MIN_AE_NUM; i<=FLASHLIGHT_CENTER_AE_NUM; i++)
    		{
    			if(avglum <= ((EVSTEP_FLASH_01[i]*expo_level)>>7))
    			{
   				    flashlight_idx += (FLASHLIGHT_CENTER_AE_NUM-i);
    				fake_sub_flash_frame_flag = KAL_FALSE;    				        				
    				break;
    			}
    	    }
            /* env is much darker */
    	    if((i==FLASHLIGHT_MIN_AE_NUM)&&(flashlight_lum>((EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_RANGE]*expo_level)>>7)))
		        flashlight_idx += (FLASHLIGHT_MAX_AE_RANGE-FLASHLIGHT_CENTER_AE_NUM);
        }
        else if(flashlight_idx>0)    
        {   /* Need more brightness */
            flashlight_idx--;
        }
    }
    
    /* check if main strobe needed, and then update shutter/gain */
    if(fake_sub_flash_frame_flag==KAL_FALSE) 
    {         		          
        /* Cal Peak Strobe */
    	if(camera_oper_data.flashlight_mode==FLASHLIGHT_LED_PEAK)
        {                    
            if(flashlight_lum>avglum)
                flashlight_main_lum = ((camera_oper_data.flashlight_delta_main_lum*(flashlight_lum-avglum))>>6) + avglum;
            else        
                flashlight_main_lum = flashlight_lum;                                           
    		for(i=FLASHLIGHT_CENTER_AE_NUM; i<=FLASHLIGHT_MAX_AE_NUM; i++)
    		{
    			if(flashlight_main_lum <= ((EVSTEP_FLASH_01[i]*expo_level)>>7))
    			{
    				flashlight_main_idx = i-FLASHLIGHT_CENTER_AE_NUM;
    				if( ((AE_INDEX+flashlight_main_idx)<=device_support_info.autoflash.lutidx)&&
                        ((AE_LUT[AE_INDEX+flashlight_main_idx].shutter)>=sensor_config_data.flashlight_offset) )
                    {                                    
                        fake_main_flash_frame_flag = KAL_FALSE;                                
                    }    
    				break;
    			}        			
            }    
        }       
    }
    /* update shutter/gain by compensate flashlight on lum */
    if((flashlight_idx+AE_INDEX)<=(device_support_info.ae.lutsize-1))
    {
        if((fake_main_flash_frame_flag == KAL_FALSE)&&(flashlight_idx<flashlight_main_idx))
            AE_INDEX += flashlight_main_idx;                                                        
        else
            AE_INDEX += flashlight_idx;
    }
    else
        AE_INDEX = (device_support_info.ae.lutsize-1);                
    return AE_INDEX;       
// END_OF_(LED_FLASHLIGHT_SUPPORT or LED_ONOFF_SUPPORT)    
#elif (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))		
    kal_uint32  i;
    /* Cal main strobe lum */
    flash_ae_info = 0;
    fake_sub_flash_frame_flag = KAL_FALSE;    
    flashlight_main_idx = 0;    
    flashlight_idx = 0;
    if(flashlight_lum<avglum)
        flashlight_lum = avglum;
    flashlight_main_lum=((camera_oper_data.flashlight_delta_main_lum*(flashlight_lum-avglum))>>6) + avglum;   
    // 1. check if pre-strobe over max detect range
    if(flashlight_lum>=((EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_NUM]*expo_level)>>7))
    {   // check  avglum is in target range
        if(avglum<=((EVSTEP_FLASH_01[FLASHLIGHT_CENTER_AE_NUM-1]*expo_level)>>7))
    {
            if( flashlight_lum>
                (((EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_RANGE]+EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_RANGE-1])>>1)*expo_level)>>7)
                flashlight_main_idx += 6;
            else
                flashlight_main_idx += 3;  
            flash_ae_info += 1;        
    }       
        else // if(avglum>((EVSTEP_FLASH_01[FLASHLIGHT_CENTER_AE_NUM-1]*expo_level)>>7))
    {
        	for(i=FLASHLIGHT_MAX_AE_NUM; i<=FLASHLIGHT_MAX_AE_RANGE; i++)        
    	{
            flashlight_main_idx += 3;
    		if(flashlight_lum < ((EVSTEP_FLASH_01[i]*expo_level)>>7))
    			break;
    	}
            flash_ae_info += 10;            	
        }
	}     
    // 2. check main-strobe
	for(i=FLASHLIGHT_CENTER_AE_NUM; i<=FLASHLIGHT_MAX_AE_NUM; i++)
	{
		if(flashlight_main_lum <= ((EVSTEP_FLASH_01[i]*expo_level)>>7))
		{
			flashlight_main_idx += (i-FLASHLIGHT_CENTER_AE_NUM);
            flash_ae_info += 100;
            if( (flashlight_main_idx>3)&&
                (flashlight_lum<((EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_NUM]*expo_level)>>7)))
            {   // this should be 
                flashlight_main_idx -= 3;
            }                                
			break;
		}
	}       
	// 3. check main-strobe over max flash ae step	  
    if(i==FLASHLIGHT_MAX_AE_NUM+1)
    {   // use pre-strobe for ae detect
    	for(i=FLASHLIGHT_CENTER_AE_NUM; i<=FLASHLIGHT_MAX_AE_NUM; i++)
    	{
    		if(flashlight_lum <= ((EVSTEP_FLASH_01[i]*expo_level)>>7))
    		{
    			flashlight_main_idx += (i-FLASHLIGHT_CENTER_AE_NUM)+1;
                flash_ae_info += 1000;
    			break;
    		}
    	}         
    	// if pre-strobe over max detect, too
        if(i==(FLASHLIGHT_MAX_AE_NUM+1))
    {
		flashlight_main_idx += (FLASHLIGHT_MAX_AE_NUM-FLASHLIGHT_CENTER_AE_NUM)+1;
            flash_ae_info += 10000;
      		// if main-strobe over max detect range and pre-strobe over max ae step
        if(flashlight_main_lum>((EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_RANGE]*expo_level)>>7))
        {
                if(flashlight_lum>((EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_RANGE]*expo_level)>>7))
    		flashlight_main_idx += 3;
    		    else
    		        flashlight_main_idx += 2;
                flash_ae_info += 100000;
	}    
	}    
	/* if avglum < normal lum when flash off, check over exp */
        if( (avglum<((EVSTEP_FLASH_01[FLASHLIGHT_CENTER_AE_NUM-1]*expo_level)>>7))&&(AE_INDEX==0)&&
            (flashlight_lum > ((EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_RANGE]*expo_level)>>7)))
    {  
            flash_ae_info += 1000000;		                    
    		for(i=FLASHLIGHT_MIN_AE_NUM; i<=FLASHLIGHT_CENTER_AE_NUM; i++)
    		{
    			if(avglum <= ((EVSTEP_FLASH_01[i]*expo_level)>>7))
    			{
   				    flashlight_main_idx += (FLASHLIGHT_CENTER_AE_NUM-i+1);
                    flash_ae_info += 10000000;   				    
    				break;
    			}
    	    }
        }
		    }
		    if(flashlight_main_idx>device_support_info.autoflash.lutidx)
		    {
		        flashlight_main_idx = device_support_info.autoflash.lutidx;
        flash_ae_info += 8;		        		        
            }
    /* 4. update AE Index */
    AE_INDEX += flashlight_main_idx;                                                        
    if(AE_INDEX>device_support_info.autoflash.lutidx)
    {
        if((AE_INDEX_Backup<device_support_info.autoflash.lutidx)&&
            (avglum<((EVSTEP_FLASH_01[FLASHLIGHT_CENTER_AE_NUM-1]*expo_level)>>7)))
        {
            AE_INDEX = device_support_info.autoflash.lutidx;
            flash_ae_info += 80;		        		                            
        }
        else
        {
            AE_INDEX = AE_INDEX_Backup;
            flashlight_main_idx = 0;
    }     	
    }
    // 5 .update flash flag
    if(flashlight_main_idx!=0)
    {
		fake_sub_flash_frame_flag = KAL_FALSE;        
        fake_main_flash_frame_flag = KAL_FALSE;                
    }    
    if(fake_main_flash_frame_flag==KAL_FALSE)    
        fake_sub_flash_frame_flag=KAL_FALSE;    
    return AE_INDEX;       
#else  // (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))		      
    return 0;
#endif

}

#endif /*(!defined(DRV_ISP_6225_SERIES))*/
#endif /* MT6219||MT6228||MT6226||MT6227||MT6229 */
