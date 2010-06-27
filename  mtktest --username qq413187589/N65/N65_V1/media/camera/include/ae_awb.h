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
 *   ae_awb.h
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   Auto Exposure and Auto White Balance Algorithm
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _AE_AWB_H
#define _AE_AWB_H

#include "drv_features.h" 
#if (defined(ISP_SUPPORT))

#include "exif.h"

#define	ISP_ON		1
#define	ISP_OFF		0

#define	AE_EXPO_MAX		528		/* maximum exposure line */
#define	AE_EXPO_MIN		3			/* minimum exposure line */
#define	PREGAIN_MAX		0xC0		/* pregain upper bound  */
#define	PREGAIN_MIN		0x40		/* unit gain */
#define 	PREGAIN_MIN_LIMIT	0x3C	/* pregain lower bound  */

#define	BAND_60HZ		0
#define	BAND_50HZ		1

#define	CLOUD				0
#define	DAYLIGHT			1
#define	INCANDESCENCE	2
#define	FLUORESCENT 	3
#define	TUNGSTEN			4

#define	ONE_STEP			1
#define	TWO_STEP			2
#define	THREE_STEP		3
#define	FOUR_STEP		4

#define	ISP_GAIN_PRIORITY			0
#define	SENSOR_GAIN_PRIORITY		1

#define	ISP_ONLY				0
#define	SENSOR_ONLY			1
#define	ISP_SENSOR_BOTH	2

#define	QUALITY_PRIORITY			0
#define	FRAME_RATE_PRIORITY		1

typedef enum
{
	AE_METERING_CENTER = 1,					// SPOT
	AE_METERING_EXCESSIVE_BACKLIGHT,		// WEIGHT
	AE_METERING_BACKLIGHT_WEIGHT,			// WEIGHT
	AE_METERING_AVGERAGE						// AVERAGE	
}	AE_METERING_DYNAMIC;

typedef enum
{
	TV00020=0,	TV00025,	TV00030,	TV00035,	TV00040,	TV00045,	TV00050,	TV00055,		
	TV00060,		TV00070,	TV00080,	TV00090,	TV00100,	TV00110,	TV00120,	TV00130,
	TV00140,		TV00150,	TV00170,	TV00200,	TV00240,	TV00250,	TV00300,	TV00330,		
	TV00400,		TV00500,	TV00600,	TV01000,	TV01200,	TV01250,	TV01400,	TV01600,		
	TV01750,		TV02000,	TV02500,	TV03200,	TV04000,	TV05000,	TV06400,	TV08000,		
	TV10000,		TV12000,	TV14000,	TV16000,	TV18000,	TV20000,	TV_NO
}TIME_VALUE_INDEX;

typedef enum
{
	AV020=0,	AV028, AV035, AV040, AV045, AV050, AV056, AV063, AV071, AV080, 
	AV090, 	AV100, AV110, AV130, AV140, AV160, AV180, AV200, AV220, AV_NO
}APERTURE_VALUE_INDEX;

typedef enum
{
	ISO100=0,	ISO200,	ISO400,	ISO_NO
}ISO_VALUE_INDEX;
typedef enum
{
	CAMERA_SHADING_NORMAL_SET=0,
	CAMERA_SHADING_PREVIEW_COPY2_TAKE,
	CAMERA_SHADING_TAKE_COPY2_PREVIEW,
	CAMERA_SHADING_SET_FAIL_KEEP_NORMAL_SET,	
	CAMERA_SHADING_END
} camera_shading_mode_set_num;

typedef enum
{
	AWB_NORMAL_FINISH = 0,
	AWB_PWRON_FASTRUN,
	AWB_OVER_LUM,
	AWB_FEW_COUNT,
	AWB_LOWER_VALUE,
	AWB_FASTFLAG,
	AWB_RGAIN_MAX,
	AWB_BGAIN_MAX	
}AWB_STATUS_INDEX;

typedef enum
{
    FLASHLIGHT_NONE = 0,
	FLASHLIGHT_LED_ONOFF,           // LED always on/off
	FLASHLIGHT_LED_CONSTANT,	    // CONSTANT type LED
	FLASHLIGHT_LED_PEAK,	        // peak strobe type LED	
	FLASHLIGHT_XENON_SCR,	        // SCR strobe type Xenon		
	FLASHLIGHT_XENON_IGBT	        // IGBT strobe type Xenon			
}	FLASHLIGHT_TYPE;

typedef enum
{
	AE_SMOOTH_PREVIEW = 0,
	AE_SMOOTH_VIDEO,
	AE_SMOOTH_MODE_NO
}AE_SMOOTH_MODE_INDEX;

typedef struct
{
	kal_uint16	value;	//Tv*100000
	kal_uint16	prtinfo;	//1/Tv *10
}shutter_info_struct;

typedef struct
{
	kal_uint8	value;	//Av*10
	kal_uint8	prtinfo; //Av*10
}aperture_info_struct;

typedef struct
{
	shutter_info_struct 	tv[TV_NO];
	aperture_info_struct av[AV_NO];
}tv_av_info_struct;

typedef struct
{
	kal_uint16	shutter;
	kal_uint16	sensorgain;
	kal_uint8	ispgain;
}exposure_lut_struct;

typedef struct
{
	kal_uint8	metering;
	kal_uint16	tv;
	kal_uint8	av;
	kal_uint8	iso;
	kal_uint8	flash;
}ae_operation_struct;

typedef struct
{
	kal_uint8	trigger;
	kal_uint8	index;
	kal_uint8	mode;
	kal_uint8	metering;
	kal_uint8	mfdir;
	kal_uint8	range;
}af_operation_struct;

typedef struct
{
	kal_uint8				dscmode;
	ae_operation_struct	ae;
	af_operation_struct	af;
}dsc_operation_struct;

typedef struct
{
	kal_uint32 	mwb_buffer_address;
	kal_uint16 	mwb_image_width;
	kal_uint16 	mwb_image_height;
} camera_mwb_process_struct;

typedef struct
{
	/* media filter */
	kal_uint16 AE_Smooth_Median_Filter_Tape;//0~AE_Smooth_Filter_Max_Tape
	/* normal */
	kal_uint16 AE_Smooth_Normal_Last_Weight;//0~128
	kal_uint16 AE_Smooth_Normal_Max_Step;//01~AE_Smooth_Detect_p
	/* fast */
	kal_uint16 AE_Smooth_Fast_Last_Weight;//0~128
	kal_uint16 AE_Smooth_Fast_Max_Step;//0~AE_Smooth_Fast_Max_Step_bound
	kal_uint16 AE_Smooth_Fast_Min_Step;//AE_Smooth_Fast_Min_Step_bound~AE_Smooth_Fast_Max_step
	kal_uint16 AE_Smooth_Fast_Check_Count;//0~AE_Smooth_Fast_Check_Count_bound
	kal_uint16 AE_Smooth_Fast_Back_Count;//0~AE_Smooth_Fast_Check_Count_bound
	kal_uint16 AE_Smooth_Fast_Transition_Count;//0~AE_Smooth_Fast_Transition_Count_bound
	kal_uint16 AE_Smooth_Fast_TH_Fast;//AE_Smooth_Fast_TH_Normal~AE_Smooth_Fast_TH_Fast_Bound
	kal_uint16 AE_Smooth_Fast_TH_Normal;//AE_Smooth_Fast_TH_Normal_Bound~AE_Smooth_Fast_TH_Fast
	kal_uint16 AE_Smooth_Fast_Gap_Ratio;//Converge fast with target gap 0~128
	kal_uint16 AE_Smooth_Fast_Gap_TH;//Converge fast with target gap 0.7 Ev
	/* speed */
	kal_uint16 AE_Smooth_Speed_Last_Weight;//0~128
	kal_uint16 AE_Smooth_Speed_Max_Step;//AE_Smooth_Speed_Min_step~AE_Smooth_Speed_Max_step_bound
	kal_uint16 AE_Smooth_Speed_Check_Count;//0~AE_Smooth_Speed_Check_Count_bound
	kal_uint16 AE_Smooth_Speed_Transition_Count;//0~AE_Smooth_Speed_Transition_Count_bound
	kal_uint16 AE_Smooth_Speed_Back_Count;//0~AE_Smooth_Speed_Transition_Count_bound
	kal_uint16 AE_Smooth_Speed_Target_Diff_TH_Speed;//0~AE_Smooth_Speed_Target_Diff_TH_Normal
	kal_uint16 AE_Smooth_Speed_Target_Diff_TH_Normal;//0~AE_Smooth_Speed_Target_Diff_TH_Normal_bound
	kal_uint16 AE_Smooth_Speed_dEv_Normal;//AE_Smooth_Speed_Stop_dEv_bound~AE_Smooth_Fast_TH_Fast
	/* ramp */
	kal_uint16 AE_Smooth_Ramp_Last_Weight;//0~128
	kal_uint16 AE_Smooth_Ramp_Max_Step;//0~AE_Smooth_Fast_Max_Step_bound
	kal_uint16 AE_Smooth_Ramp_Check_Count;//0~AE_Smooth_Fast_Check_Count_bound
	kal_uint16 AE_Smooth_Ramp_Transition_Count;//0~AE_Smooth_Fast_Transition_Count_bound
	kal_uint16 AE_Smooth_Ramp_Back_Count;//0~AE_Smooth_Fast_Transition_Count_bound
	kal_uint16 AE_Smooth_Ramp_TH_Ramp;//AE_Smooth_Ramp_TH_Normal~-AE_Smooth_Ramp_TH_Diff_Bound
	kal_uint16 AE_Smooth_Ramp_TH_Normal;//-AE_Smooth_Ramp_TH_Diff_Bound~0
	/* final */
	kal_uint16 AE_Smooth_Final_Tol;//0~128
	kal_uint16 AE_Smooth_Max_Ev_Range;//0~20
	kal_uint16 AE_Smooth_Min_Ev_Range;//0~Max_Ev_Range
}AE_Smooth_Filter_input_struct;

typedef struct
{
	kal_bool		ae_mode;									/* QUALITY_PRIORITY, FRAME_RATE_PRIORITY */
	kal_bool		enable_cap_shutter_compensate;	/* KAL_TRUE, KAL_FALSE */
	kal_bool		gain_priority;							/* ISP_GAIN_PRIORITY, SENSOR_GAIN_PRIORITY */
	kal_uint8	pregain_mode;							/* ISP_ONLY, SENSOR_ONLY, ISP_SENSOR_BOTH */
	kal_uint16	pregain_max;							/* Whole Camera Pregain Upper Bound */
	kal_uint16	isp_pregain_max;						/* ISP Digital Pregain Upper Bound */
	kal_uint16	sensor_pregain_max;					/* Sensor Pregain Upper Bound */
	kal_uint16	pregain_compensate_max;				/* For FRAME_RATE_PRIORITY in Preview Mode  */
	kal_uint16	shutter_compensate_max;				/* For Capture Mode  Quality*/
	kal_uint16	pregain_min;							/* ISP driver assign, 1x gain */
	kal_uint16	isp_pregain_min;						/* ISP driver assign, 1x gain */
	kal_uint16	sensor_pregain_min;					/* ISP driver assign, 1x gain */
	kal_uint8	preview_display_wait_frame;		/* Wait AE stable to display fist frame image */
	kal_uint8	ae_smooth_upper_bound;				/* Smooth range upper bound */
	kal_uint8	ae_smooth_lower_bound;				/* Smooth range lower bound */
	kal_uint8	ae_awb_cal_period;					/* AE AWB calculation period */
	kal_uint8	ae_setting_gain_delay_frame;		/* The frame of setting gain */
	kal_uint8	ae_setting_shut_delay_frame;		/* The frame of setting shutter */
	kal_uint8	ae_setting_cal_delay_frame;		/* The frame of calculation */
	kal_uint8	capture_delay_frame;					/* wait stable frame when sensor change mode (pre to cap) */
	kal_uint8	preview_delay_frame;					/* wait stable frame when sensor change mode (cap to pre) */
	kal_uint8	ae_lowlight_threshold;				/* low light threshold of luminance for camera */
	kal_uint8	ae_lowlight_off_threshold;			/* low light turn off threshold of luminance for camera */
	kal_uint8	ae_video_lowlight_threshold;		/* low light threshold of luminance for video */
	kal_uint8	ae_video_lowlight_off_threshold;	/* low light turn off threshold of luminance for video */
	kal_bool		ae_high_banding_target_enable;	/* enable/disable banding taeget (default enable) */
	kal_bool		flare_camera_enable;					/* flare algorithm enable for camera */
	kal_bool		flare_video_enable;					/* flare algorithm enable for video */
	kal_uint8	flare_lower_bound_percentage;		/* percentage of total pixel for flare lower bound */
	kal_uint8	flare_upper_bound_percentage;		/* percentage of total pixel for flare upper bound */
	kal_uint8	flare_gain_max;						/* the gain to maximize flare gain to prevent saturation earier */
	kal_uint8	ae_setting_sensor_gain_delay_frame;		/* The frame of setting sensor gain */
	kal_bool		preview_defect_table_enable;		/* KAL_TRUE or KAL_FALSE */
	kal_bool		capture_defect_table_enable;		/* KAL_TRUE or KAL_FALSE */
	camera_shading_mode_set_num	shading_table_mode_set; /* shading table mode set */
	kal_uint8	yuv_af_timeout_frame;				/* frame no of af result status checking for YUV sensor */
	kal_uint8	flashlight_mode;		            /* FLASH_LIGHT_TYPE */		
	kal_uint8	flashlight_delta_main_lum;          /* delta main lum@60cm / delta sub lum@60cm * 64 */
	kal_uint8	extreme_CT_fixWB_enable;			/*enable/disable extreme low and high color temperature to limit to A and D75*/
	kal_uint8	outdoorIdx;							/*AE index for outdoor condition*/
	kal_uint8	outdoor_fixWB_enable;				/*enable/disable outdoor fix WB*/	
	kal_uint16	out_Rgain;							/*outdoor Rgain*/	
	kal_uint16	out_GRgain;							/*outdoor GRgain*/	
	kal_uint16	out_Bgain;							/*outdoor Bgain*/	
	kal_uint16	out_GBgain;							/*outdoor GBgain*/
	AE_Smooth_Filter_input_struct Smooth_Filter_Para_Preview;/* AE smooth para for Preview */
	AE_Smooth_Filter_input_struct Smooth_Filter_Para_Video;/* AE smooth para for Video */
	kal_bool	AE_Smooth_Enable;/* AE smooth enable flag */
	kal_bool AE_ISO_Highlight_Comp_Enable;/* ISO priority highlight comp enable flag */
	kal_bool AE_ISO_Lowlight_Comp_Enable;/* ISO priority lowlight comp enable flag */	
	kal_bool AE_ISO_EXIF_Report_Standard_Enable;/* ISO priority EXIF with report real ISO gain enable flag */
}camera_operation_para_struct;

extern kal_uint8	ae_range;
extern kal_uint8	expo_level;
extern kal_uint8	high_expo_level;
extern kal_uint8	low_expo_level;
extern kal_uint8	light_band;
extern kal_uint32 eShutter;
extern kal_uint32	lum[9];
extern kal_uint8	BaseShutter;
extern kal_uint32	avglum;
extern kal_uint32	histogram[5],Rhist[5],Ghist[5],Bhist[5];
extern kal_uint8	flare_offset;
extern kal_uint8	flare_gain;
extern kal_uint8	histogram_b1,histogram_b2,histogram_b3,histogram_b4,histogram_b5;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
extern kal_uint32	ae_result[7][9];
#endif
#if (!defined(DRV_ISP_6219_SERIES))
extern dsc_operation_struct dsc_status;
#endif

extern kal_uint16	pregain; 
extern kal_uint8	isp_pregain; 
extern kal_uint16	sensor_pregain; 
extern kal_uint8 	iris_no;

#if (defined(DRV_ISP_6219_SERIES))
extern kal_uint16	AWB_Rgain,AWB_Ggain,AWB_Bgain;
extern kal_uint16	tmp_Rgain,tmp_Ggain,tmp_Bgain;
#else
extern kal_uint16	AWB_Rgain,AWB_GRgain,AWB_Bgain,AWB_GBgain;
extern kal_uint16	tmp_Rgain,tmp_GRgain,tmp_Bgain,tmp_GBgain; 
#endif
extern kal_uint16	Rgain_max,Ggain_max,Bgain_max;
extern kal_uint16	Rgain_min,Ggain_min,Bgain_min;
extern kal_uint32	Acc_R,Acc_G,Acc_B,Acc_Cnt;
extern kal_uint8	awbEntryCnt;
extern kal_bool		awbFastFlag;

extern kal_bool ae_enable_flag,awb_enable_flag;
extern camera_operation_para_struct camera_oper_data;
extern kal_uint8	ae_awb_cal_complete;

extern kal_bool ae_bypass_enable_flag;		// AE bypass mode: bypass ae cal
extern kal_uint8 AE_BYPASS_INDEX;

#if (!defined(DRV_ISP_6219_SERIES))
extern const exposure_lut_struct *AE_LUT;
extern const kal_uint8 *IRIS_LUT;
#endif

#if (!defined(DRV_ISP_6219_SERIES))
/* DSC AE */
extern const tv_av_info_struct tv_av_info;
extern kal_bool shutter_pri_60hz_info[TV_NO];
extern kal_bool shutter_pri_50hz_info[TV_NO];
extern kal_bool aperture_pri_info[AV_NO];
extern kal_bool iso_pri_info[ISO_NO];
extern kal_uint16 iso_gain_info[ISO_NO];
extern kal_uint8 AE_INDEX, AE_INDEX_C, AE_INDEX_ENV;
#endif

/* AE AWB Main */
void init_ae(void);
void init_awb(void);
void ae_awb_main(void);
void ae_on_off(kal_bool flag);
void ae_select_band(kal_uint8 band);
void awb_on_off(kal_bool flag);
void awb_fast_method(kal_bool flag);
void awb_reset(void);
void get_ae_awb_info(void);
void get_histogram_info(kal_uint8 color);
void ae_bypass_mode_on_off(kal_bool flag);
kal_uint32 get_lum_info(void);

/* Auto-Exposure */
void ae_config(kal_uint16 Hsize,kal_uint16 Vsize);
void ae_proc(void);
void ae_banding_factor(void);
void ae_cal_lum(void);
void ae_compute(void);
void cal_shutter(void);
void cal_pregain(void);
void ae_set_pregain(kal_uint16 pre_gain);
void ae_set_lut_gain(void);
void ae_set_isp_pregain(void);
void ae_set_ini_shutter(kal_uint16 shutter);
void ae_select_stepperev(kal_uint8 step);
void ae_set_expovalue(kal_uint8 target);
void ae_set_shutter(kal_uint16 lines);
void init_histogram_setting (void);
kal_int8 ae_get_ev_level(void);
kal_uint8 ae_set_ev(kal_int8 level);
kal_uint8 ae_get_totalevlevel(void);
kal_uint8 ae_get_stepperev(void);
kal_uint8 ae_get_expovalue(void);
kal_uint16 ae_get_ini_shutter(void);
kal_uint16 ae_get_current_shutter(void);
kal_uint32 get_shutter_from_time(kal_uint32 time, kal_uint16 pixel_width);
#if (!defined(DRV_ISP_6219_SERIES))
void ae_set_ini_expo_idx(kal_uint8 idx);
kal_uint8 ae_get_ini_expo_idx(void);
#endif

/* Auto-White-Balance */
void awb_config(kal_uint16 Hsize,kal_uint16 Vsize);
void awb_set_manual_gain(kal_uint8 light);
void awb_save_manual_gain(kal_uint8 light, kal_uint16 color_temp, kal_uint16 r_gain, kal_uint16 g_gain, kal_uint16 b_gain);
void awb_read_all_manual_gain(kal_uint16 manualWB[5][4]);
void awb_proc(void);
void awb_set_gain(void);
void awb_gain_max_min(void);
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
void camera_manual_wb_setting(void);
void camera_mwb_process(camera_mwb_process_struct *mwb_data);
void backup_mwb_setting(void);
void restore_mwb_setting(void);
#endif

#if (!defined(DRV_ISP_6219_SERIES))
void flash_config(kal_uint16 delay_line,kal_uint16 duty_line);
void get_shutter_priority_info(kal_uint8 tv_index, shutter_info_struct *tv_data);
void get_aperture_priority_info(kal_uint8 av_index, aperture_info_struct *av_data);
#if (defined(EXIF_SUPPORT))	
void exif_update_cam_para_struct(exif_cam_para_struct *exif_para);
#endif
#endif

#if (!defined(DRV_ISP_6219_SERIES))
/* AE smooth */
extern AE_Smooth_Filter_input_struct Filter_para;
void AE_Smooth_Init(void);
void init_ae_smooth_custom_para(AE_SMOOTH_MODE_INDEX mode);
kal_uint16 AE_Smooth_Check_Input_Clear_Table(void);
/* ISO priority */
extern kal_uint8 ae_max_idx, ae_min_idx;
void ae_iso_priority_Init(void);
kal_uint16 ae_get_sensor_gain(kal_uint8 cam_mode, kal_uint8 iso_mode);
kal_uint8	ae_apply_index_update(kal_uint8 cam_mode, kal_uint8 iso_mode, kal_uint8 env_idx);
kal_uint8	ae_env_index_offset(kal_uint8 AE_update);
void ae_lut_max_min_idx_iso_update(kal_uint8 cam_mode, kal_uint8 iso_mode);
#endif

#endif /* _AE_AWB_H */
#endif /* MT6219||MT6228||MT6226||MT6227||MT6229 ||MT6230*/

