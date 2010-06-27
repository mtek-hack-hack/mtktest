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
 *   camera_para.h
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   Camera Parameter Header File
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
 *
 ****************************************************************************/
#ifndef _CAMERA_PARA_H
#define _CAMERA_PARA_H

#include "drv_features.h"

#if !defined(ISP_SUPPORT)
	// DO NOT delete this section!!! 
	// When ISP_SUPPORT is not defined, NVRAM still need the dummy structure 
	// and default value to initialize NVRAM_EF_CAMERA_PARA_LID.             
	typedef struct {
		kal_uint32		dummy;
	} nvram_camera_para_struct;
	extern const nvram_camera_para_struct CAMERA_PARA_DEFAULT_VALUE;

#if (!defined(DRV_ISP_6219_SERIES))
	typedef struct {
		kal_uint32		dummy;
	} nvram_camera_defect_struct;
	extern const nvram_camera_defect_struct CAMERA_DEFECT_DEFAULT_VALUE;
	typedef struct {
		kal_uint32		dummy;
	} nvram_camera_lens_struct;
	extern const nvram_camera_lens_struct CAMERA_LENS_DEFAULT_VALUE;
#endif	

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
	typedef struct {
		kal_uint32		dummy;
	} nvram_camera_gamma_struct;
	extern const nvram_camera_gamma_struct CAMERA_GAMMA_DEFAULT_VALUE;
#endif	

#else

#include "image_sensor.h"
#include "ae_awb.h"
#include "af.h"
#include "isp_flashlight.h"

#define BASEGAIN	0x40
#define AF_NO		32

typedef struct
{
#if (defined(DRV_ISP_6219_SERIES))
	kal_uint32	reg[72];
#elif (defined(DRV_ISP_6228_SERIES))
	kal_uint32	reg[132];
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	kal_uint32	reg[144];	
#elif (defined(DRV_ISP_6229_SERIES))
	kal_uint32	reg[152];
#endif
}isp_para_struct;

typedef struct
{
	kal_uint8	gamma_select;	
	kal_uint8	gamma[9][11];	
}isp_predefine_gamma_struct;

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
typedef struct
{
	kal_uint32	gamma[256];	
}nvram_camera_gamma_struct;
#endif

typedef struct
{
	kal_uint16	iniShutter;
	kal_uint8	TargetLum;
	kal_uint8	StepperEV;
#if (!defined(DRV_ISP_6219_SERIES))
	kal_uint8	iniExpoIdx;
#endif
}ae_para_struct;

typedef struct
{
#if (defined(DRV_ISP_6219_SERIES))
	kal_uint16	LightSource[5][4];	/* {color_temperature, Rgain, Ggain, Bgain} */
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
	kal_uint16	LightSource[5][5];	/* {color_temperature, Rgain, GRgain, Bgain, GBgain} */	
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	kal_uint16	LightSource[6][5];	/* {color_temperature, Rgain, GRgain, Bgain, GBgain} */	
#endif	
	kal_uint16	AWB_rgain_max;
	kal_uint16	AWB_ggain_max;
	kal_uint16	AWB_bgain_max;
}awb_para_struct;

#if (!defined(DRV_ISP_6219_SERIES))
typedef struct
{
	kal_uint32		shading_cap[11];
	kal_uint32		autodefect_pre_low[2];
	kal_uint32		autodefect_cap_nor[2];
	kal_uint32		autodefect_cap_low[2];
	kal_uint32		shading_spare_1[11];
	kal_uint32		shading_spare_2[11];
}isp_comp_struct;

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
#define Shading_Reg1_ID			125
#define AutoDefect_Reg1_ID		107
#elif(defined(DRV_ISP_6228_SERIES))
#define Shading_Reg1_ID			117
#define AutoDefect_Reg1_ID		99
#elif (defined(DRV_ISP_6229_SERIES))
#define Shading_Reg1_ID			133
#define AutoDefect_Reg1_ID		115
#endif

#endif

#if (!defined(DRV_ISP_6219_SERIES))
/* ISO priority */
typedef struct
{
	kal_uint16	ISO_Gain[3];
	kal_uint16	ISO_Value[3];
}ae_iso_struct;

typedef struct
{
	kal_uint8		ISO_sensor_gain_no;
	kal_uint16	*ISO_sensor_gain;
}ae_iso_sensor_gain_struct;

#endif

typedef struct
{
	isp_para_struct				ISP;
	isp_predefine_gamma_struct	PREDGAMMA;
#if (!defined(DRV_ISP_6219_SERIES))
	isp_comp_struct		COMP;//shading & auto defect compensation
#endif	
	ae_para_struct					AE;
	awb_para_struct				AWB;
	sensor_data_struct			SENSOR;
#if (!defined(DRV_ISP_6219_SERIES))
	ae_iso_struct		ISO_PRIORITY_INFO;
#endif		
}nvram_camera_para_struct;

//-----------------------Defect table interface-------------------------	
#define	MAX_DEFECT_NUM			(256)
#define	MAX_PV_DEFECT_NUM		(240)
#define	MAX_DEFECT_INFO_NUM	(MAX_DEFECT_NUM+MAX_PV_DEFECT_NUM)
typedef struct
{
	kal_uint32	defect[MAX_DEFECT_INFO_NUM];		
}nvram_camera_defect_struct;

// lens parameter structure
typedef struct {
	kal_uint8		af_table_num;	
	kal_uint16		af_home_idx;
	kal_uint16		af_macro_idx;		
	kal_uint16		af_infinite_idx;		
	kal_uint16		af_hyper_pos;		
	kal_uint16		af_me_home_pos;		// For Stepping Motor Use	
	kal_uint16		af_me_macro_pos;		// For Stepping Motor Use	
	kal_uint16		af_calibration_offset;
} lens_info_struct;

typedef struct {
	kal_uint32	pos;	
	kal_uint32	distance;
} af_table_struct;

typedef struct
{
   lens_info_struct	INFO;
	af_table_struct	AF[AF_NO];	
}nvram_camera_lens_struct;

enum
{
	CAMERA_PARA_INIT_MODE=0,
	CAMERA_PARA_PREVIEW_MODE,
	CAMERA_PARA_CAPTURE_MODE,
	CAMERA_PARA_NIGHT_MODE,
	CAMERA_PARA_VIDEO_MODE,
	CAMERA_PARA_AUTO_LOWLIGHT_MODE,
	CAMERA_PARA_VIDEO_AUTO_LOWLIGHT_MODE,
	CAMERA_PARA_AF_NORMAL_MODE,
	CAMERA_PARA_AF_LOWLIGHT_MODE
};

typedef enum
{
	/* must to keep w/o compiler option for meta API */
	CAMERA_COMP_PREVIEW_NORMAL_SET=0,
	CAMERA_COMP_PREVIEW_LOWLIGHT_SET,
	CAMERA_COMP_CAPTURE_NORMAL_SET,	
	CAMERA_COMP_CAPTURE_LOWLIGHT_SET,
	CAMERA_COMP_END
	/* new mode should insert before CAMERA_COMP_END */
} camera_comp_set_num;

typedef enum
{
	/* must to keep w/o compiler option for meta API */
	CAMERA_AUTO_DEFECT_LEVEL_0=0,
	CAMERA_AUTO_DEFECT_LEVEL_1,
	CAMERA_AUTO_DEFECT_LEVEL_2,	
	CAMERA_AUTO_DEFECT_LEVEL_3,
	CAMERA_AUTO_DEFECT_END
	/* new mode should insert before CAMERA_COMP_END */
} camera_auto_defect_set_num;

typedef struct
{
	kal_uint8		band;
	kal_bool		videomode;
	kal_uint8	dscmode;
}ae_lut_info_struct;

typedef struct
{
	kal_bool	autodsc;
	kal_bool	portrait;
	kal_bool	landscape;
	kal_bool	sport;
	kal_bool flower;
	kal_bool	nightscene;
	kal_bool	tvmode;
	kal_bool	avmode;
	kal_bool	isomode;
}dsc_mode_info_struct;

typedef struct
{
	kal_bool	flashlight;
	kal_bool	autofocus;
}dsc_comp_info_struct;

typedef struct
{
	kal_bool	autoflash;
	kal_bool	forceon;
	kal_bool	forceoff;
	kal_bool	antiredeye;
}flash_mode_info_struct;

typedef struct
{
	kal_bool	automode;
	kal_bool	macro;
	kal_bool	infinite;
	kal_bool	manual;
}af_mode_info_struct;

typedef struct
{
	dsc_mode_info_struct		dscmode;
	dsc_comp_info_struct		dsccomp;
	flash_mode_info_struct	flashlight;
	af_mode_info_struct		af;
}dsc_info_struct;

typedef struct
{
	kal_uint8	lutsize;
	kal_uint16	step;		//Ev_step*1000, ex:0.1 -> 100
	kal_uint16	minEv;	//Ev*1000
	kal_uint16	maxEv;	//Ev*1000
	kal_uint8	iris;		//No. of Iris
	kal_uint8	sensor_basegain;	// Sensor base gain, bypass capture compensate when != 0x40 
}ae_info_struct;

typedef struct
{
	kal_bool		strobe_pol;
	kal_uint8	lutidx;
	kal_uint16	duty;
	kal_uint16	offset;
	kal_uint16	shutter;
	kal_uint16	min_shutter;
	kal_uint16	max_shutter;
	kal_uint16	fwb_rgain;
	kal_uint16	fwb_ggain;
	kal_uint16	fwb_bgain;
	kal_uint16	sensorgain;
	kal_uint8	ispgain;
}flash_info_struct;

typedef struct
{
	ae_info_struct			ae;
	flash_info_struct		autoflash;
}device_info_struct;

// lens id definition
typedef enum _LENS_TYPE {
	VCM_AF_LENS=0,
	PIEZO_AF_LENS,
	STEP_MOTOR_AF_LENS
} LENS_TYPE;
#define LENS_VCM_LEBRO_ID			{ 201, VCM_AF_LENS	}
#define LENS_PIEZO_LITEON_ID		{ 202, PIEZO_AF_LENS	}

// lens af driver status
enum LENS_AF_STATUS
{
	AF_STATUS_READY,				/* AF Ready */
	AF_STATUS_OPERATING,			/* AF is operating/Busy */	
	AF_STATUS_FIXED				/* Low battary, AF Fixed */
};
// sensor id definition
#define OV7660_OMNIVISION			{ 101, CMOS_SENSOR }
#define OV9650_OMNIVISION			{ 102, CMOS_SENSOR }
#define MT9MX11_MICRON				{ 103, CMOS_SENSOR }
#define S5K3AAEA_SAMSUNG			{ 104, CMOS_SENSOR }
#define PO3030K_PIXELPLUS			{ 105, CMOS_SENSOR }
#define PO3130D_PIXELPLUS			{ 106, CMOS_SENSOR }
#define HV7131RP_HYNIX				{ 107, CMOS_SENSOR }
#define NOON130PC20_SILICONFILE	    { 108, CMOS_SENSOR }
#define MT9D011_MICRON				{ 109, CMOS_SENSOR }
#define S5K3BAFB_SAMSUNG			{ 110, CMOS_SENSOR }	
#define OV2630_OMNIVISION			{ 111, CMOS_SENSOR }
#define NOON200PC11_SILICONFILE	    { 112, CMOS_SENSOR }
#define S5K83AFX_SAMSUNG			{ 113, CMOS_SENSOR }	
#define OM6802_PHILIPS				{ 114, CMOS_SENSOR }
#define S5K53BEX_SAMSUNG			{ 115, CMOS_SENSOR }
#define OV7670_OMNIVISION			{ 116, CMOS_SENSOR }		
#define OV9655_OMNIVISION			{ 117, CMOS_SENSOR }
#define OV3630_OMNIVISION			{ 118, CMOS_SENSOR }
#define NOON200PC20_SILICONFILE	    { 119, CMOS_SENSOR }
#define OV2640_OMNIVISION			{ 120, CMOS_SENSOR }
#define MC501CA_MAGNACHIP		    { 121, CMOS_SENSOR }
#define MT9T012_MICRON		        { 122, CMOS_SENSOR }
#define MT9V112_MICRON		        { 123, CMOS_SENSOR }
#define ET8EF2_TOSHIBA  		    { 124, CMOS_SENSOR }
#define ET8EE6_TOSHIBA  		    { 125, CMOS_SENSOR }
#define S5K4BAFX_SAMSUNG 		    { 126, CMOS_SENSOR }
#define OV3640_OMNIVISION			{ 127, CMOS_SENSOR }
#define OV7680_OMNIVISION			{ 123, CMOS_SENSOR } 	/* yangyaojia add */
#define BF3403_BYD					{ 128, CMOS_SENSOR } /* Huyanwei Add It */


// interface to apply/update camera_para to/from ISP, AE&AWB and SENSOR 
void apply_camera_para_to_reg(void);
void update_camera_para_from_reg(void);

// interface to apply camera_para to ISP, AE&AWB 
void load_camera_para(void);

// interface to apply/update camera_para to/from ISP 
void camera_para_to_isp(void);
void isp_to_camera_para(void);

// interface to apply/update camera_para to/from AE&AWB 
void camera_para_to_ae(void);

// interface to get/set camera_para global variable 
nvram_camera_para_struct *get_camera_para(void);
void set_camera_para(const nvram_camera_para_struct *p_cam_para);
#if (!defined(DRV_ISP_6219_SERIES))
void apply_camera_shading_to_reg(camera_comp_set_num p_set_mode);
void update_camera_shading_from_reg(camera_comp_set_num p_set_mode);
void apply_camera_autodefect_to_reg(camera_comp_set_num p_set_mode);
void update_camera_autodefect_from_reg(camera_comp_set_num p_set_mode);
nvram_camera_defect_struct *get_camera_defect(void);
void set_camera_defect(const nvram_camera_defect_struct *p_cam_defect);
nvram_camera_lens_struct *get_camera_lens(void);
void set_camera_lens(const nvram_camera_lens_struct *p_cam_lens);
kal_uint8 Set_camera_shading_mode(camera_shading_mode_set_num p_shading_set);
kal_uint8 Get_camera_shading_mode(void);
#endif
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
nvram_camera_gamma_struct *get_camera_gamma(void);
void set_camera_gamma(const nvram_camera_gamma_struct *p_cam_gamma);
#endif

// interface to get default hardcoded camera_para 
const nvram_camera_para_struct *get_default_camera_para(void);

// interface to set f/w data
void init_camera_operation_para(camera_operation_para_struct *oper_data);
#if (defined(AF_SUPPORT)&&(!defined(DRV_ISP_6219_SERIES)))
extern float	lens_step_scaling;
void init_af_operation_para(af_operation_para_struct *oper_data);
#endif

// interface to set camera para in differnt mode
void set_camera_mode_para(kal_uint8 mode);
void set_anti_low_light_para(kal_uint8 aeidx);

/* Extern Global Variable */
extern nvram_camera_para_struct	camera_para;
extern const nvram_camera_para_struct CAMERA_PARA_DEFAULT_VALUE;

#if (!defined(DRV_ISP_6219_SERIES))
const nvram_camera_defect_struct *get_default_camera_defect(void);
const nvram_camera_lens_struct *get_default_camera_lens(void);
void load_defect_table_para(kal_uint8	table_id);

extern nvram_camera_defect_struct	camera_defect;
extern nvram_camera_lens_struct	camera_lens;
extern const nvram_camera_defect_struct CAMERA_DEFECT_DEFAULT_VALUE;
extern const nvram_camera_lens_struct CAMERA_LENS_DEFAULT_VALUE;
#endif

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
const nvram_camera_gamma_struct *get_default_camera_gamma(void);

extern nvram_camera_gamma_struct	camera_gamma;
extern const nvram_camera_gamma_struct CAMERA_GAMMA_DEFAULT_VALUE;
#endif
	
#if (!defined(DRV_ISP_6219_SERIES))
const exposure_lut_struct *get_ae_lut(ae_lut_info_struct info);
const kal_uint8 *get_iris_lut(ae_lut_info_struct info);
extern dsc_info_struct		dsc_support_info;
extern device_info_struct	device_support_info;
extern ae_iso_sensor_gain_struct ae_iso_sensor_gain_info;
#endif

extern kal_uint8 	camera_horizontal_flag;

// preview rotation flag 
extern kal_uint8	g_CCT_PreviewImageMirror;

//gamma 1024 software flag
#define gamma_global_1024_no 	52
void apply_take_image_with_gamma_1024_by_flag(void);//chip compiler option inside API
void recover_preview_with_gamma_1024_disabled(void);//chip compiler option inside API

#endif
#endif /* _CAMERA_PARA_H */

