/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	isp_if_622x_series_hw.h
 *
 * Project:
 * --------
 *   MT6219,MT6227_,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _ISP_IF_622X_SERIES_HW_H_
#define _ISP_IF_622X_SERIES_HW_H_

#include "drv_features.h"
#include "reg_base.h"

#if (!(defined(DRV_ISP_6219_SERIES)||defined(MT6238)))
#define CAMERA_base                 (0x80620000)   /* Camera Interface */
#endif

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))

#if (defined(DRV_ISP_6219_SERIES))	
enum
{
   BAYER_Gr=0,
   BAYER_R,
   BAYER_B,
   BAYER_Gb
};
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
enum
{
	BAYER_B=0,
	BAYER_Gb,
	BAYER_Gr,
	BAYER_R
};
#elif (defined(DRV_ISP_6228_SERIES))
enum
{
	BAYER_R=0,
	BAYER_Gr,
	BAYER_Gb,
	BAYER_B
};
#endif
	
enum
{
	INPUT_BAYER=0,
	INPUT_YUV422=1,
	INPUT_RGB=2,
	INPUT_YCbCr=5	
};

enum
{
	INPUT_ORDER_CbYCrY1=0,
	INPUT_ORDER_CrYCbY1,
	INPUT_ORDER_YCbY1Cr,
	INPUT_ORDER_YCrY1Cb	
};
	
enum
{
   ISP_DRIVING_2MA=0,
   ISP_DRIVING_4MA,
	ISP_DRIVING_6MA,
	ISP_DRIVING_8MA
};

#define ISP_INT_FRAME_READY		0x0001
#define ISP_INT_IDLE					0x0002
#define ISP_INT_RESIZER_OVERRUN	0x0004
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ISP_INT_ISP_DONE			0x0010
#define ISP_INT_AE_DONE				0x0020
#define ISP_INT_ATF_DONE			0x0040
#define ISP_INT_TG_DONE				0x0080
#define ISP_INT_VD_DONE				0x0100
#endif

#define ISP_TG_PHASE_COUNTER_REG					(CAMERA_base + 0x0000)
#define ISP_CMOS_SENSOR_SIZE_CONFIG_REG 		(CAMERA_base + 0x0004)
#define ISP_TG_GRAB_RANGE_PIXEL_CONFIG_REG	(CAMERA_base + 0x0008)
#define ISP_TG_GRAB_RANGE_LINE_CONFIG_REG		(CAMERA_base + 0x000C)
#define ISP_CMOS_SENSOR_MODE_CONFIG_REG		(CAMERA_base + 0x0010)
#define ISP_RGB_OFFSET_ADJUS_REG					(CAMERA_base + 0x0014)
#define ISP_VIEW_FINDER_MODE_CTRL_REG			(CAMERA_base + 0x0018)
#define ISP_INT_ENABLE_REG             	   (CAMERA_base + 0x001C)
#define ISP_INT_STATUS_REG     	            (CAMERA_base + 0x0020)
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))                        
#define ISP_PATH_CONFIG_REG	     	         (CAMERA_base + 0x0024)
#define ISP_INPUT_ADDR_REG    	 	         (CAMERA_base + 0x0028)
#define ISP_OUTPUT_ADDR_REG     		         (CAMERA_base + 0x002C)
#endif                                       
#define ISP_PREPROCESS_CTRL1_REG					(CAMERA_base + 0x0030)
#define ISP_RGB_GAIN_CTRL1_REG					(CAMERA_base + 0x0034)
#define ISP_RGB_GAIN_CTRL2_REG					(CAMERA_base + 0x0038)
#define ISP_HISTOGRAM_BOUNDARY_CTRL1_REG		(CAMERA_base + 0x003C)
#define ISP_HISTOGRAM_BOUNDARY_CTRL2_REG		(CAMERA_base + 0x0040)
#define ISP_PREPROCESS_CTRL2_REG					(CAMERA_base + 0x0044)
#if (!(defined(DRV_ISP_6228_SERIES)))                      
#define ISP_AE_WINDOW1_REG							(CAMERA_base + 0x0048)
#define ISP_AE_WINDOW2_REG							(CAMERA_base + 0x004C)
#define ISP_AE_WINDOW3_REG							(CAMERA_base + 0x0050)
#define ISP_AE_WINDOW4_REG							(CAMERA_base + 0x0054)
#endif                                       
#define ISP_AE_WINDOW5_REG							(CAMERA_base + 0x0058)
#define ISP_AE_WINDOW6_REG							(CAMERA_base + 0x005C)
#define ISP_AE_WINDOW7_REG							(CAMERA_base + 0x0060)
#define ISP_AE_WINDOW8_REG							(CAMERA_base + 0x0064)
#define ISP_AE_WINDOW9_REG							(CAMERA_base + 0x0068)
#define ISP_AWB_WINDOW_REG							(CAMERA_base + 0x006C)
#define ISP_COLOR_PROCESS_STAGE_CTRL1_REG		(CAMERA_base + 0x0070)
#define ISP_INTERPOLATION1_REG					(CAMERA_base + 0x0074)
#define ISP_INTERPOLATION2_REG					(CAMERA_base + 0x0078)
#define ISP_EDGE_CORE_REG							(CAMERA_base + 0x007C)
#define ISP_EDGE_GAIN1_REG							(CAMERA_base + 0x0080)
#define ISP_EDGE_GAIN2_REG							(CAMERA_base + 0x0084)
#define ISP_EDGE_THRESHOLD_REG					(CAMERA_base + 0x0088)
#define ISP_EDGE_VERTICAL_CTRL_REG				(CAMERA_base + 0x008C)
#define ISP_AXIS_RGB_GAIN_REG						(CAMERA_base + 0x0090)
#define ISP_OPD_CONFIG_REG							(CAMERA_base + 0x0094)
#define ISP_OPD_COMP_PARAMETER_REG				(CAMERA_base + 0x0098)
#define ISP_COLOR_MATRIX1_REG						(CAMERA_base + 0x009C)
#define ISP_COLOR_MATRIX2_REG						(CAMERA_base + 0x00A0)
#define ISP_COLOR_MATRIX3_REG						(CAMERA_base + 0x00A4)
#define ISP_COLOR_MATRIX_RGB_GAIN_REG			(CAMERA_base + 0x00A8)
#define ISP_COLOR_PROCESS_STAGE_CTRL2_REG		(CAMERA_base + 0x00AC)
#define ISP_AWB_GAIN_REG							(CAMERA_base + 0x00B0)
#define ISP_GAMMA_RGB_FLARE_REG					(CAMERA_base + 0x00B4)
#define ISP_Y_CH_CONFIG_REG						(CAMERA_base + 0x00B8)
#define ISP_UV_CH_CONFIG_REG						(CAMERA_base + 0x00BC)
#define ISP_SPACE_CONVERT_YUV1_REG				(CAMERA_base + 0x00C0)
#define ISP_SPACE_CONVERT_YUV2_REG				(CAMERA_base + 0x00C4)
#define ISP_GAMMA_OPERATION1_REG					(CAMERA_base + 0x00C8)
#define ISP_GAMMA_OPERATION2_REG					(CAMERA_base + 0x00CC)
#define ISP_GAMMA_OPERATION3_REG					(CAMERA_base + 0x00D0)
#define ISP_OPD_Y_RESULT_REG						(CAMERA_base + 0x00D4)
#define ISP_OPD_MG_RESULT_REG						(CAMERA_base + 0x00D8)
#define ISP_OPD_RB_RESULT_REG						(CAMERA_base + 0x00DC)
#define ISP_OPD_PIXEL_COUNT_REG					(CAMERA_base + 0x00E0)
#if (!defined(DRV_ISP_6228_SERIES))                       
#define ISP_AE_WINDOW1_RESULT_REG				(CAMERA_base + 0x00E4)
#define ISP_AE_WINDOW2_RESULT_REG				(CAMERA_base + 0x00E8)
#define ISP_AE_WINDOW3_RESULT_REG				(CAMERA_base + 0x00EC)
#define ISP_AE_WINDOW4_RESULT_REG				(CAMERA_base + 0x00F0)
#endif                                       
#define ISP_AE_WINDOW5_RESULT_REG				(CAMERA_base + 0x00F4)
#define ISP_AE_WINDOW6_RESULT_REG				(CAMERA_base + 0x00F8)
#define ISP_AE_WINDOW7_RESULT_REG				(CAMERA_base + 0x00FC)
#define ISP_AE_WINDOW8_RESULT_REG				(CAMERA_base + 0x0100)
#define ISP_AE_WINDOW9_RESULT_REG				(CAMERA_base + 0x0104)
#define ISP_AE_A_NUMBER_RESULT_REG				(CAMERA_base + 0x0108)
#define ISP_AE_B_NUMBER_RESULT_REG				(CAMERA_base + 0x010C)
#define ISP_AE_C_NUMBER_RESULT_REG				(CAMERA_base + 0x0110)
#define ISP_AE_D_NUMBER_RESULT_REG				(CAMERA_base + 0x0114)
#define ISP_AE_E_NUMBER_RESULT_REG				(CAMERA_base + 0x0118)
#define ISP_LPF_CTRL_REG							(CAMERA_base + 0x011C)
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))                        
#define ISP_Y_LPF_CTRL_REG							(CAMERA_base + 0x0120)
#define ISP_CBCR_LPF_CTRL_REG						(CAMERA_base + 0x0124)
#define ISP_VERTICAL_SUB_SAMPLE_CTRL_REG		(CAMERA_base + 0x0128)
#define ISP_HORIZONTAL_SUB_SAMPLE_CTRL_REG	(CAMERA_base + 0x012C)
#define ISP_SENSOR_GAMMA_R0_REG					(CAMERA_base + 0x0130)
#define ISP_SENSOR_GAMMA_R1_REG					(CAMERA_base + 0x0134)
#define ISP_SENSOR_GAMMA_R2_REG					(CAMERA_base + 0x0138)
#if(!(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES)))
#define ISP_SENSOR_GAMMA_G0_REG					(CAMERA_base + 0x013C)
#define ISP_SENSOR_GAMMA_G1_REG					(CAMERA_base + 0x0140)
#define ISP_SENSOR_GAMMA_G2_REG					(CAMERA_base + 0x0144)
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ISP_SENSOR_GAMMA_GR0_REG					(CAMERA_base + 0x013C)
#define ISP_SENSOR_GAMMA_GR1_REG					(CAMERA_base + 0x0140)
#define ISP_SENSOR_GAMMA_GR2_REG					(CAMERA_base + 0x0144)
#define ISP_SENSOR_GAMMA_GB0_REG					(CAMERA_base + 0x0160)
#define ISP_SENSOR_GAMMA_GB1_REG					(CAMERA_base + 0x0164)
#define ISP_SENSOR_GAMMA_GB2_REG					(CAMERA_base + 0x0168)
#endif
#define ISP_SENSOR_GAMMA_B0_REG					(CAMERA_base + 0x0148)
#define ISP_SENSOR_GAMMA_B1_REG					(CAMERA_base + 0x014C)
#define ISP_SENSOR_GAMMA_B2_REG					(CAMERA_base + 0x0150)
#define ISP_DEFECT_PIXEL_CONFIG_REG				(CAMERA_base + 0x0154)
#define ISP_DEFECT_PIXEL_TABLE_ADDR_REG		(CAMERA_base + 0x0158)
#define ISP_DEFECT_PIXEL_TABLE_DEBUG_REG		(CAMERA_base + 0x015C)
#endif                                       
#if(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ISP_RAW_GAIN_CTRL1_REG					(CAMERA_base + 0x016C)
#define ISP_RAW_GAIN_CTRL2_REG					(CAMERA_base + 0x0170)
#endif

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
#define ISP_RESULT_WINDOW_V_SIZE_REG			(CAMERA_base + 0x0174)
#define ISP_RESULT_WINDOW_H_SIZE_REG			(CAMERA_base + 0x0178)
#endif
#define ISP_DEBUG_CTRL_REG							(CAMERA_base + 0x0180)
#define ISP_DEBUG_WRITE_OUT_ADDR_REG			(CAMERA_base + 0x0184)
#define ISP_DEBUG_LAST_WRITE_OUT_ADDR_REG		(CAMERA_base + 0x0188)
#define ISP_DEBUG_FB_OUT_COUNT_REG				(CAMERA_base + 0x018C)
#define ISP_DEBUG_CONFIG1_REG						(CAMERA_base + 0x0190)
#define ISP_DEBUG_CONFIG2_REG						(CAMERA_base + 0x0194)
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ISP_AE_ADDRESS_REG							(CAMERA_base + 0x01A0)
#define ISP_AE_WINDOW_SIZE_REG					(CAMERA_base + 0x01A4)
#define ISP_AE_WEIGHT0_REG							(CAMERA_base + 0x01A8)
#define ISP_AE_WEIGHT1_REG							(CAMERA_base + 0x01AC)
#define ISP_AE_WEIGHT2_REG							(CAMERA_base + 0x01B0)
#define ISP_AE_WEIGHT3_REG							(CAMERA_base + 0x01B4)
#define ISP_AE_WEIGHT4_REG							(CAMERA_base + 0x01B8)
#define ISP_AE_WEIGHT5_REG							(CAMERA_base + 0x01BC)
#define ISP_AE_WEIGHT6_REG							(CAMERA_base + 0x01C0)
#define ISP_AE_WEIGHT7_REG							(CAMERA_base + 0x01C4)
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ISP_AE_AREA_REG								(CAMERA_base + 0x01C8)
#define ISP_AUTO_DEFECT_CTRL1_REG				(CAMERA_base + 0x01CC)
#define ISP_AUTO_DEFECT_CTRL2_REG				(CAMERA_base + 0x01D0)
#define ISP_FLASH_CTRL_REG							(CAMERA_base + 0x01D4)
#define ISP_RESET_REG								(CAMERA_base + 0x01D8)
#define ISP_TG_STATUS_REG							(CAMERA_base + 0x01DC)
#define ISP_HISTOGRAM_BOUNDARY_CTRL3_REG		(CAMERA_base + 0x01E0)
#define ISP_HISTOGRAM_BOUNDARY_CTRL4_REG		(CAMERA_base + 0x01E4)
#define ISP_HISTOGRAM_BOUNDARY_CTRL5_REG		(CAMERA_base + 0x01E8)
#define ISP_HISTOGRAM_RESULT5_REG				(CAMERA_base + 0x01EC)
#define ISP_HISTOGRAM_RESULT6_REG				(CAMERA_base + 0x01F0)
#define ISP_HISTOGRAM_RESULT7_REG				(CAMERA_base + 0x01F4)
#define ISP_HISTOGRAM_RESULT8_REG				(CAMERA_base + 0x01F8)
#define ISP_HISTOGRAM_RESULT9_REG				(CAMERA_base + 0x01FC)
#define ISP_HISTOGRAM_RESULTA_REG				(CAMERA_base + 0x0200)
#define ISP_HISTOGRAM_RESULTB_REG				(CAMERA_base + 0x0204)
#define ISP_HISTOGRAM_RESULTC_REG				(CAMERA_base + 0x0208)
#define ISP_HISTOGRAM_RESULTD_REG				(CAMERA_base + 0x020C)
#define ISP_HISTOGRAM_RESULTE_REG				(CAMERA_base + 0x0210)
#define ISP_SHADING_CTRL1_REG						(CAMERA_base + 0x0214)
#define ISP_SHADING_CTRL2_REG						(CAMERA_base + 0x0218)
#define ISP_SHADING_R_CURVE1_REG					(CAMERA_base + 0x021C)
#define ISP_SHADING_R_CURVE2_REG					(CAMERA_base + 0x0220)
#define ISP_SHADING_R_CURVE3_REG					(CAMERA_base + 0x0224)
#define ISP_SHADING_G_CURVE1_REG					(CAMERA_base + 0x0228)
#define ISP_SHADING_G_CURVE2_REG					(CAMERA_base + 0x022C)
#define ISP_SHADING_G_CURVE3_REG					(CAMERA_base + 0x0230)
#define ISP_SHADING_B_CURVE1_REG					(CAMERA_base + 0x0234)
#define ISP_SHADING_B_CURVE2_REG					(CAMERA_base + 0x0238)
#define ISP_SHADING_B_CURVE3_REG					(CAMERA_base + 0x023C)
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ISP_IMGPROC_HUE0_REG						(CAMERA_base + 0x0240)
#define ISP_IMGPROC_HUE1_REG						(CAMERA_base + 0x0244)
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ISP_DEBUG_REG								(CAMERA_base + 0x0248)
#endif  
#if (defined(DRV_ISP_6228_SERIES))
#define ISP_VERSION_REG								(CAMERA_base + 0x024C)
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ISP_ATF_WINDOW1_REG						(CAMERA_base + 0x024C)
#define ISP_ATF_WINDOW2_REG						(CAMERA_base + 0x0250)
#define ISP_ATF_WINDOW3_REG						(CAMERA_base + 0x0254)
#define ISP_ATF_WINDOW4_REG						(CAMERA_base + 0x0258)
#define ISP_ATF_WINDOW5_REG						(CAMERA_base + 0x025c)
#define ISP_ATF_RESULT1_REG						(CAMERA_base + 0x0260)
#define ISP_ATF_RESULT2_REG						(CAMERA_base + 0x0264)
#define ISP_ATF_RESULT3_REG						(CAMERA_base + 0x0268)
#define ISP_ATF_RESULT4_REG						(CAMERA_base + 0x026C)
#define ISP_ATF_RESULT5_REG						(CAMERA_base + 0x0270)
#define ISP_VERSION_REG								(CAMERA_base + 0x0274)
#define ISP_GAMMA_TABLE_START_ADDR_REG			(CAMERA_base + 0x1000)
#endif  
        
#define REG_ISP_TG_PHASE_COUNTER					*((volatile unsigned int *) (CAMERA_base + 0x0000))
#define REG_ISP_CMOS_SENSOR_SIZE_CONFIG 		*((volatile unsigned int *) (CAMERA_base + 0x0004))
#define REG_ISP_TG_GRAB_RANGE_PIXEL_CONFIG	*((volatile unsigned int *) (CAMERA_base + 0x0008))
#define REG_ISP_TG_GRAB_RANGE_LINE_CONFIG		*((volatile unsigned int *) (CAMERA_base + 0x000C))
#define REG_ISP_CMOS_SENSOR_MODE_CONFIG		*((volatile unsigned int *) (CAMERA_base + 0x0010))
#define REG_ISP_RGB_OFFSET_ADJUS					*((volatile unsigned int *) (CAMERA_base + 0x0014))
#define REG_ISP_VIEW_FINDER_MODE_CTRL			*((volatile unsigned int *) (CAMERA_base + 0x0018))
#define REG_ISP_INT_ENABLE             	   *((volatile unsigned int *) (CAMERA_base + 0x001C))
#define REG_ISP_INT_STATUS     	            *((volatile unsigned int *) (CAMERA_base + 0x0020))
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_PATH_CONFIG     	            *((volatile unsigned int *) (CAMERA_base + 0x0024)) 
#define REG_ISP_INPUT_ADDR     	            *((volatile unsigned int *) (CAMERA_base + 0x0028)) 
#define REG_ISP_OUTPUT_ADDR     	            *((volatile unsigned int *) (CAMERA_base + 0x002C)) 
#endif
#define REG_ISP_PREPROCESS_CTRL1					*((volatile unsigned int *) (CAMERA_base + 0x0030))
#define REG_ISP_RGB_GAIN_CTRL1					*((volatile unsigned int *) (CAMERA_base + 0x0034))
#define REG_ISP_RGB_GAIN_CTRL2					*((volatile unsigned int *) (CAMERA_base + 0x0038))
#define REG_ISP_HISTOGRAM_BOUNDARY_CTRL1		*((volatile unsigned int *) (CAMERA_base + 0x003C))
#define REG_ISP_HISTOGRAM_BOUNDARY_CTRL2		*((volatile unsigned int *) (CAMERA_base + 0x0040))
#define REG_ISP_PREPROCESS_CTRL2					*((volatile unsigned int *) (CAMERA_base + 0x0044))
#if (!(defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES)))
#define REG_ISP_AE_WINDOW1							*((volatile unsigned int *) (CAMERA_base + 0x0048))
#define REG_ISP_AE_WINDOW2							*((volatile unsigned int *) (CAMERA_base + 0x004C))
#define REG_ISP_AE_WINDOW3							*((volatile unsigned int *) (CAMERA_base + 0x0050))
#define REG_ISP_AE_WINDOW4							*((volatile unsigned int *) (CAMERA_base + 0x0054))
#endif
#define REG_ISP_AE_WINDOW5							*((volatile unsigned int *) (CAMERA_base + 0x0058))
#define REG_ISP_AE_WINDOW6							*((volatile unsigned int *) (CAMERA_base + 0x005C))
#define REG_ISP_AE_WINDOW7							*((volatile unsigned int *) (CAMERA_base + 0x0060))
#define REG_ISP_AE_WINDOW8							*((volatile unsigned int *) (CAMERA_base + 0x0064))
#define REG_ISP_AE_WINDOW9							*((volatile unsigned int *) (CAMERA_base + 0x0068))
#define REG_ISP_AWB_WINDOW							*((volatile unsigned int *) (CAMERA_base + 0x006C))
#define REG_ISP_COLOR_PROCESS_STAGE_CTRL1		*((volatile unsigned int *) (CAMERA_base + 0x0070))
#define REG_ISP_INTERPOLATION1					*((volatile unsigned int *) (CAMERA_base + 0x0074))
#define REG_ISP_INTERPOLATION2					*((volatile unsigned int *) (CAMERA_base + 0x0078))
#define REG_ISP_EDGE_CORE							*((volatile unsigned int *) (CAMERA_base + 0x007C))
#define REG_ISP_EDGE_GAIN1							*((volatile unsigned int *) (CAMERA_base + 0x0080))
#define REG_ISP_EDGE_GAIN2							*((volatile unsigned int *) (CAMERA_base + 0x0084))
#define REG_ISP_EDGE_THRESHOLD					*((volatile unsigned int *) (CAMERA_base + 0x0088))
#define REG_ISP_EDGE_VERTICAL_CTRL				*((volatile unsigned int *) (CAMERA_base + 0x008C))
#define REG_ISP_AXIS_RGB_GAIN						*((volatile unsigned int *) (CAMERA_base + 0x0090))
#define REG_ISP_OPD_CONFIG							*((volatile unsigned int *) (CAMERA_base + 0x0094))
#define REG_ISP_OPD_COMP_PARAMETER				*((volatile unsigned int *) (CAMERA_base + 0x0098))
#define REG_ISP_COLOR_MATRIX1						*((volatile unsigned int *) (CAMERA_base + 0x009C))
#define REG_ISP_COLOR_MATRIX2						*((volatile unsigned int *) (CAMERA_base + 0x00A0))
#define REG_ISP_COLOR_MATRIX3						*((volatile unsigned int *) (CAMERA_base + 0x00A4))
#define REG_ISP_COLOR_MATRIX_RGB_GAIN			*((volatile unsigned int *) (CAMERA_base + 0x00A8))
#define REG_ISP_COLOR_PROCESS_STAGE_CTRL2		*((volatile unsigned int *) (CAMERA_base + 0x00AC))
#define REG_ISP_AWB_GAIN							*((volatile unsigned int *) (CAMERA_base + 0x00B0))
#define REG_ISP_GAMMA_RGB_FLARE					*((volatile unsigned int *) (CAMERA_base + 0x00B4))
#define REG_ISP_Y_CH_CONFIG						*((volatile unsigned int *) (CAMERA_base + 0x00B8))
#define REG_ISP_UV_CH_CONFIG						*((volatile unsigned int *) (CAMERA_base + 0x00BC))
#define REG_ISP_SPACE_CONVERT_YUV1				*((volatile unsigned int *) (CAMERA_base + 0x00C0))
#define REG_ISP_SPACE_CONVERT_YUV2				*((volatile unsigned int *) (CAMERA_base + 0x00C4))
#define REG_ISP_GAMMA_OPERATION1					*((volatile unsigned int *) (CAMERA_base + 0x00C8))
#define REG_ISP_GAMMA_OPERATION2					*((volatile unsigned int *) (CAMERA_base + 0x00CC))
#define REG_ISP_GAMMA_OPERATION3					*((volatile unsigned int *) (CAMERA_base + 0x00D0))
#define REG_ISP_OPD_Y_RESULT						*((volatile unsigned int *) (CAMERA_base + 0x00D4))
#define REG_ISP_OPD_MG_RESULT						*((volatile unsigned int *) (CAMERA_base + 0x00D8))
#define REG_ISP_OPD_RB_RESULT						*((volatile unsigned int *) (CAMERA_base + 0x00DC))
#define REG_ISP_OPD_PIXEL_COUNT					*((volatile unsigned int *) (CAMERA_base + 0x00E0))
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_AE_WINDOW1_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x00E4))
#define REG_ISP_AE_WINDOW2_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x00E8))
#define REG_ISP_AE_WINDOW3_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x00EC))
#define REG_ISP_AE_WINDOW4_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x00F0))
#define REG_ISP_AE_WINDOW5_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x00F4))
#define REG_ISP_AE_WINDOW6_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x00F8))
#define REG_ISP_AE_WINDOW7_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x00FC))
#define REG_ISP_AE_WINDOW8_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x0100))
#define REG_ISP_AE_WINDOW9_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x0104))
#else
#define REG_ISP_AF_RESULT1							*((volatile unsigned int *) (CAMERA_base + 0x00F4))
#define REG_ISP_AF_RESULT2							*((volatile unsigned int *) (CAMERA_base + 0x00F8))
#define REG_ISP_AF_RESULT3							*((volatile unsigned int *) (CAMERA_base + 0x00FC))
#define REG_ISP_AF_RESULT4							*((volatile unsigned int *) (CAMERA_base + 0x0100))
#define REG_ISP_AF_RESULT5							*((volatile unsigned int *) (CAMERA_base + 0x0104))
#endif
#define REG_ISP_AE_A_NUMBER_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x0108))
#define REG_ISP_AE_B_NUMBER_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x010C))
#define REG_ISP_AE_C_NUMBER_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x0110))
#define REG_ISP_AE_D_NUMBER_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x0114))
#define REG_ISP_AE_E_NUMBER_RESULT				*((volatile unsigned int *) (CAMERA_base + 0x0118))
#define REG_ISP_LPF_CTRL							*((volatile unsigned int *) (CAMERA_base + 0x011C))
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_Y_LPF_CTRL							*((volatile unsigned int *) (CAMERA_base + 0x0120)) 
#define REG_ISP_CBCR_LPF_CTRL						*((volatile unsigned int *) (CAMERA_base + 0x0124)) 
#define REG_ISP_VERTICAL_SUB_SAMPLE_CTRL		*((volatile unsigned int *) (CAMERA_base + 0x0128)) 
#define REG_ISP_HORIZONTAL_SUB_SAMPLE_CTRL	*((volatile unsigned int *) (CAMERA_base + 0x012C)) 
#define REG_ISP_SNR_GAMMA_R0						*((volatile unsigned int *) (CAMERA_base + 0x0130)) 
#define REG_ISP_SNR_GAMMA_R1						*((volatile unsigned int *) (CAMERA_base + 0x0134)) 
#define REG_ISP_SNR_GAMMA_R2						*((volatile unsigned int *) (CAMERA_base + 0x0138)) 
#if(!(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES)))
#define REG_ISP_SNR_GAMMA_G0						*((volatile unsigned int *) (CAMERA_base + 0x013C)) 
#define REG_ISP_SNR_GAMMA_G1						*((volatile unsigned int *) (CAMERA_base + 0x0140)) 
#define REG_ISP_SNR_GAMMA_G2						*((volatile unsigned int *) (CAMERA_base + 0x0144)) 
#endif
#if(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_SNR_GAMMA_GR0						*((volatile unsigned int *) (CAMERA_base + 0x013C)) 
#define REG_ISP_SNR_GAMMA_GR1						*((volatile unsigned int *) (CAMERA_base + 0x0140)) 
#define REG_ISP_SNR_GAMMA_GR2						*((volatile unsigned int *) (CAMERA_base + 0x0144)) 
#define REG_ISP_SNR_GAMMA_GB0						*((volatile unsigned int *) (CAMERA_base + 0x0160)) 
#define REG_ISP_SNR_GAMMA_GB1						*((volatile unsigned int *) (CAMERA_base + 0x0164)) 
#define REG_ISP_SNR_GAMMA_GB2						*((volatile unsigned int *) (CAMERA_base + 0x0168)) 
#endif
#define REG_ISP_SNR_GAMMA_B0						*((volatile unsigned int *) (CAMERA_base + 0x0148)) 
#define REG_ISP_SNR_GAMMA_B1						*((volatile unsigned int *) (CAMERA_base + 0x014C)) 
#define REG_ISP_SNR_GAMMA_B2						*((volatile unsigned int *) (CAMERA_base + 0x0150)) 
#define REG_ISP_DEFECT_PIXEL_CONFIG				*((volatile unsigned int *) (CAMERA_base + 0x0154)) 
#define REG_ISP_DEFECT_PIXEL_TABLE_ADDR		*((volatile unsigned int *) (CAMERA_base + 0x0158)) 
#define REG_ISP_DEFECT_PIXEL_TABLE_DEBUG		*((volatile unsigned int *) (CAMERA_base + 0x015C)) 
#endif
#if(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_RAW_GAIN_CTRL1					*((volatile unsigned int *) (CAMERA_base + 0x016C)) 
#define REG_ISP_RAW_GAIN_CTRL2					*((volatile unsigned int *) (CAMERA_base + 0x0170)) 
#endif
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
#define REG_ISP_RESULT_WINDOW_V_SIZE			*((volatile unsigned int *) (CAMERA_base + 0x0174))
#define REG_ISP_RESULT_WINDOW_H_SIZE			*((volatile unsigned int *) (CAMERA_base + 0x0178))
#endif
#define REG_ISP_DEBUG_CTRL							*((volatile unsigned int *) (CAMERA_base + 0x0180))
#define REG_ISP_DEBUG_WRITE_OUT_ADDR			*((volatile unsigned int *) (CAMERA_base + 0x0184))
#define REG_ISP_DEBUG_LAST_WRITE_OUT_ADDR		*((volatile unsigned int *) (CAMERA_base + 0x0188))
#define REG_ISP_DEBUG_FB_OUT_COUNT				*((volatile unsigned int *) (CAMERA_base + 0x018C))
#define REG_ISP_DEBUG_CONFIG1						*((volatile unsigned int *) (CAMERA_base + 0x0190))
#define REG_ISP_DEBUG_CONFIG2						*((volatile unsigned int *) (CAMERA_base + 0x0194))
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_AE_ADDRESS							*((volatile unsigned int *) (CAMERA_base + 0x01A0))
#define REG_ISP_AE_WINDOW_SIZE					*((volatile unsigned int *) (CAMERA_base + 0x01A4))
#define REG_ISP_AE_WEIGHT0							*((volatile unsigned int *) (CAMERA_base + 0x01A8))
#define REG_ISP_AE_WEIGHT1							*((volatile unsigned int *) (CAMERA_base + 0x01AC))
#define REG_ISP_AE_WEIGHT2							*((volatile unsigned int *) (CAMERA_base + 0x01B0))
#define REG_ISP_AE_WEIGHT3							*((volatile unsigned int *) (CAMERA_base + 0x01B4))
#define REG_ISP_AE_WEIGHT4							*((volatile unsigned int *) (CAMERA_base + 0x01B8))
#define REG_ISP_AE_WEIGHT5							*((volatile unsigned int *) (CAMERA_base + 0x01BC))
#define REG_ISP_AE_WEIGHT6							*((volatile unsigned int *) (CAMERA_base + 0x01C0))
#define REG_ISP_AE_WEIGHT7							*((volatile unsigned int *) (CAMERA_base + 0x01C4))
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_AE_AREA								*((volatile unsigned int *) (CAMERA_base + 0x01C8))
#define REG_ISP_AUTO_DEFECT_CTRL1				*((volatile unsigned int *) (CAMERA_base + 0x01CC))
#define REG_ISP_AUTO_DEFECT_CTRL2				*((volatile unsigned int *) (CAMERA_base + 0x01D0))
#define REG_ISP_FLASH_CTRL							*((volatile unsigned int *) (CAMERA_base + 0x01D4))
#define REG_ISP_RESET								*((volatile unsigned int *) (CAMERA_base + 0x01D8))
#define REG_ISP_TG_STATUS							*((volatile unsigned int *) (CAMERA_base + 0x01DC))
#define REG_ISP_HISTOGRAM_BOUNDARY_CTRL3		*((volatile unsigned int *) (CAMERA_base + 0x01E0))
#define REG_ISP_HISTOGRAM_BOUNDARY_CTRL4		*((volatile unsigned int *) (CAMERA_base + 0x01E4))
#define REG_ISP_HISTOGRAM_BOUNDARY_CTRL5		*((volatile unsigned int *) (CAMERA_base + 0x01E8))
#define REG_ISP_HISTOGRAM_RESULT5				*((volatile unsigned int *) (CAMERA_base + 0x01EC))
#define REG_ISP_HISTOGRAM_RESULT6				*((volatile unsigned int *) (CAMERA_base + 0x01F0))
#define REG_ISP_HISTOGRAM_RESULT7				*((volatile unsigned int *) (CAMERA_base + 0x01F4))
#define REG_ISP_HISTOGRAM_RESULT8				*((volatile unsigned int *) (CAMERA_base + 0x01F8))
#define REG_ISP_HISTOGRAM_RESULT9				*((volatile unsigned int *) (CAMERA_base + 0x01FC))
#define REG_ISP_HISTOGRAM_RESULTA				*((volatile unsigned int *) (CAMERA_base + 0x0200))
#define REG_ISP_HISTOGRAM_RESULTB				*((volatile unsigned int *) (CAMERA_base + 0x0204))
#define REG_ISP_HISTOGRAM_RESULTC				*((volatile unsigned int *) (CAMERA_base + 0x0208))
#define REG_ISP_HISTOGRAM_RESULTD				*((volatile unsigned int *) (CAMERA_base + 0x020C))
#define REG_ISP_HISTOGRAM_RESULTE				*((volatile unsigned int *) (CAMERA_base + 0x0210))
#define REG_ISP_SHADING_CTRL1						*((volatile unsigned int *) (CAMERA_base + 0x0214))
#define REG_ISP_SHADING_CTRL2						*((volatile unsigned int *) (CAMERA_base + 0x0218))
#define REG_ISP_SHADING_R_CURVE1					*((volatile unsigned int *) (CAMERA_base + 0x021C))
#define REG_ISP_SHADING_R_CURVE2					*((volatile unsigned int *) (CAMERA_base + 0x0220))
#define REG_ISP_SHADING_R_CURVE3					*((volatile unsigned int *) (CAMERA_base + 0x0224))
#define REG_ISP_SHADING_G_CURVE1					*((volatile unsigned int *) (CAMERA_base + 0x0228))
#define REG_ISP_SHADING_G_CURVE2					*((volatile unsigned int *) (CAMERA_base + 0x022C))
#define REG_ISP_SHADING_G_CURVE3					*((volatile unsigned int *) (CAMERA_base + 0x0230))
#define REG_ISP_SHADING_B_CURVE1					*((volatile unsigned int *) (CAMERA_base + 0x0234))
#define REG_ISP_SHADING_B_CURVE2					*((volatile unsigned int *) (CAMERA_base + 0x0238))
#define REG_ISP_SHADING_B_CURVE3					*((volatile unsigned int *) (CAMERA_base + 0x023C))
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_IMGPROC_HUE0						*((volatile unsigned int *) (CAMERA_base + 0x0240))
#define REG_ISP_IMGPROC_HUE1						*((volatile unsigned int *) (CAMERA_base + 0x0244))
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_DEBUG								*((volatile unsigned int *) (CAMERA_base + 0x0248))
#endif
#if (defined(DRV_ISP_6228_SERIES))
#define REG_ISP_VERSION								*((volatile unsigned int *) (CAMERA_base + 0x024C))
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_ISP_ATF_WINDOW1						*((volatile unsigned int *) (CAMERA_base + 0x024C))
#define REG_ISP_ATF_WINDOW2						*((volatile unsigned int *) (CAMERA_base + 0x0250))
#define REG_ISP_ATF_WINDOW3						*((volatile unsigned int *) (CAMERA_base + 0x0254))
#define REG_ISP_ATF_WINDOW4						*((volatile unsigned int *) (CAMERA_base + 0x0258))
#define REG_ISP_ATF_WINDOW5						*((volatile unsigned int *) (CAMERA_base + 0x025C))
#define REG_ISP_ATF_RESULT1						*((volatile unsigned int *) (CAMERA_base + 0x0260))
#define REG_ISP_ATF_RESULT2						*((volatile unsigned int *) (CAMERA_base + 0x0264))
#define REG_ISP_ATF_RESULT3						*((volatile unsigned int *) (CAMERA_base + 0x0268))
#define REG_ISP_ATF_RESULT4						*((volatile unsigned int *) (CAMERA_base + 0x026C))
#define REG_ISP_ATF_RESULT5						*((volatile unsigned int *) (CAMERA_base + 0x0270))
#define REG_ISP_VERSION								*((volatile unsigned int *) (CAMERA_base + 0x0274))
#define REG_ISP_GAMMA_TABLE_START_ADDR			*((volatile unsigned int *) (CAMERA_base + 0x0278))
#endif

/* bit mapping of Camera TG phase counter register */
#define REG_TGPC_PHASE_COUNTER_ENABLE_BIT		0x80000000
#define REG_TGPC_CLK_OUTPUT_ENABLE_BIT			0x20000000
#define REG_TGPC_CLK_POLARITY_CTRL_BIT			0x10000000
#define REG_TGPC_CLK_OUTPUT_DIV_MASK			0x0F000000
#define REG_TGPC_RISING_EDGE_CLK_CNT_MASK		0x00F00000
#define REG_TGPC_FALLING_EDGE_CLK_CNT_MASK	0x000F0000
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_TGPC_HVALID_ENABLE_BIT				0x00008000
#define REG_TGPC_SENSOR_CLKIN_MONITOR_BIT		0x00004000
#define REG_TGPC_PIXEL_CLK_INV_BIT				0x00002000
#define REG_TGPC_PIXEL_CLKIN_ENABLE_BIT		0x00001000
#define REG_TGPC_PIXEL_CLK_SELECT_BIT			0x00000100
#endif
#define REG_TGPC_PIXEL_CLK_DIV_MASK				0x000000F0
#define REG_TGPC_DATA_LATCH_POSITION_MASK		0x0000000F

/* bit mapping of Camera CMOS sensor size configuration register */
#define REG_CMOS_SENSOR_SIZE_WIDTH_MASK		0x0FFF0000
#define REG_CMOS_SENSOR_SIZE_HEIGHT_MASK		0x00000FFF

/* bit mapping of TG grab range start/end pixel configuration register */
#define REG_TG_GRAB_RANGE_START_PIXEL_MASK	0x0FFF0000
#define REG_TG_GRAB_RANGE_END_PIXEL_MASK		0x00000FFF

/* bit mapping of TG grab start/end line configuration register */
#define REG_TG_GRAB_RANGE_START_LINE_MASK		0x0FFF0000
#define REG_TG_GRAB_RANBE_END_LINE_MASK		0x00000FFF

/* bit mapping of CMOS sensor mode configuration register */
#define REG_CMOS_SENSOR_VSYNC_POLARITY_BIT	0x00000080
#define REG_CMOS_SENSOR_HSYNC_POLARITY_BIT	0x00000040
#define REG_CMOS_SENSOR_POWER_ON_BIT			0x00000020
#define REG_CMOS_SENSOR_RESET_BIT				0x00000010
#define REG_CMOS_SENSOR_AUTO_SYNC_ENABLE_BIT	0x00000008
#define REG_CMOS_SENSOR_ENABLE_BIT				0x00000001

/* bit mapping of component R, Gr, B, Gb offset adjustment register */
#define REG_COMP_R_OFFSET_ADJ_SIGN_BIT			0x80000000
#define REG_COMP_R_OFFSET_ADJ_MASK				0x7F000000
#define REG_COMP_GR_OFFSET_ADJ_SIGN_BIT		0x00800000
#define REG_COMP_GR_OFFSET_ADJ_MASK				0x007F0000
#define REG_COMP_B_OFFSET_ADJ_SIGN_BIT			0x00008000
#define REG_COMP_B_OFFSET_ADJ_MASK				0x00007F00
#define REG_COMP_GB_OFFSET_ADJ_SIGN_BIT		0x00000080
#define REG_COMP_GB_OFFSET_ADJ_MASK				0x0000007F

/* bit mapping of camera view finder mode control register */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_VIEW_FINDER_MODE_SP_DELAY_MASK		0x00000700	
#endif
#define REG_VIEW_FINDER_MODE_DATA_ENABLE_BIT		0x00000040
#define REG_VIEW_FINDER_MODE_CAPTURE_MODE_BIT	0x00000080
#define REG_VIEW_FINDER_MODE_FRAME_RATE_MASK		0x00000007

/* bit mapping of Camera module interrupt enable register */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_CAMERA_INT_VD_DONE_ENABLE_BIT				0x80000080
#define REG_CAMERA_INT_FLASH_SEL_ENABLE_BIT			0x80000000
#define REG_CAMERA_INT_FLASH_LINENO_MASK				0x0FFF0000
#define REG_CAMERA_INT_AVSYNC_ENABLE_BIT				0x00000100
#define REG_CAMERA_INT_FLASH_DONE_ENABLE_BIT			0x00000080
#elif (defined(DRV_ISP_6228_SERIES))
#define REG_CAMERA_INT_VD_DONE_ENABLE_BIT				0x01000080
#define REG_CAMERA_INT_VSYNC_ENABLE_BIT				0x01000000
#define REG_CAMERA_INT_TG_LINENO_MASK					0x00FF0000
#define REG_CAMERA_INT_TG_DONE_ENABLE_BIT				0x00000080
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_CAMERA_INT_ATF_DONE_ENABLE_BIT			0x00000040
#define REG_CAMERA_INT_AE_DONE_ENABLE_BIT				0x00000020
#define REG_CAMERA_INT_ISP_DONE_ENABLE_BIT			0x00000010
#endif
#define REG_CAMERA_INT_IDLE_ENABLE_BIT					0x00000008
#define REG_CAMERA_INT_GMC_OVERRUN_ENABLE_BIT		0x00000004
#define REG_CAMERA_INT_RESIZER_OVERRUN_ENABLE_BIT	0x00000002
#define REG_CAMERA_INT_FRAME_READY_ENABLE_BIT   	0x00000001

/* bit mapping of Camera module interrupt status register */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_CAMERA_INT_AE_DONE_STATUS_BIT				0x00000020
#define REG_CAMERA_INT_ISP_DONE_STATUS_BIT			0x00000010
#endif
#define REG_CAMERA_INT_IDLE_STATUS_BIT					0x00000008
#define REG_CAMERA_INT_GMC_OVERRUN_STATUS_BIT		0x00000004
#define REG_CAMERA_INT_RESIZER_OVERRUN_STATUS_BIT	0x00000002
#define REG_CAMERA_INT_FRAME_READY_STATUS_BIT   	0x00000001

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* bit mapping of Camera path config register */
#define REG_CAMERA_PATH_CNTON_BIT						0x80000000
#define REG_CAMERA_PATH_CNTMODE_MASK					0x60000000
#if (defined(DRV_ISP_6228_SERIES))
#define REG_CAMERA_PATH_WRITE_LEVEL_MASK				0x1F000000
#else
#define REG_CAMERA_PATH_WRITE_LEVEL_MASK				0x1E000000
#define REG_CAMERA_PATH_BAYER10_OUT_BIT				    0x01000000
#endif
#define REG_CAMERA_PATH_REZ_DISCONN_BIT				0x00800000
#define REG_CAMERA_PATH_REZ_LPF_OFF_BIT				0x00400000
#define REG_CAMERA_PATH_OUTPATH_TYPE_MASK				0x00300000
#define REG_CAMERA_PATH_BURSTW_TYPE_MASK				0x000E0000
#define REG_CAMERA_PATH_OUTPATH_EN_BIT					0x00010000
#define REG_CAMERA_PATH_INORDER_SEL_MASK			0x00003000
#define REG_CAMERA_PATH_INDATA_FORMAT_MASK			0x00000800
#define REG_CAMERA_PATH_INTYPE_SEL_MASK				0x00000700
#define REG_CAMERA_PATH_INPATH_RATE_MASK				0x000000F0
#define REG_CAMERA_PATH_INPATH_THROTTLE_BIT			0x00000002
#define REG_CAMERA_PATH_INPATH_SEL_BIT					0x00000001
#endif

/* bit mapping of preprocessing control register 1 */
#define REG_PREPROCESS1_GAIN_COMPENSATION_MASK	0xFF000000
#define REG_PREPROCESS1_PIXEL_LIMIT_MASK			0x00FF0000
#define REG_PREPROCESS1_BYPASS_PREGAIN_BIT		0x00008000
#define REG_PREPROCESS1_LID_POLARITY_BIT			0x00002000
#define REG_PREPROCESS1_PID_POLARITY_BIT			0x00001000
#define REG_PREPROCESS1_PREGAIN_INT_PART_MASK	0x00000300
#define REG_PREPROCESS1_PREGAIN_FRAC_PART_MASK	0x000000FF

/* bit mapping of G and B component gain control register */
#define REG_COMP_B_GAIN_CTRL_MASK				0x01FF0000
#if (defined(DRV_ISP_6219_SERIES))
#define REG_COMP_G_GAIN_CTRL_MASK				0x000001FF
#else
#define REG_COMP_GB_GAIN_CTRL_MASK				0x000001FF
#endif

/* bit mapping of R component gain control register */
#define REG_COMP_R_GAIN_CTRL_MASK				0x01FF0000
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_COMP_GR_GAIN_CTRL_MASK				0x000001FF
#endif

/* bit mapping of histogram boundary control register */
#define REG_HISTORGRAM_BOUNDARY1_MASK			0xFF000000
#define REG_HISTORGRAM_BOUNDARY2_MASK			0x00FF0000
#define REG_HISTORGRAM_BOUNDARY3_MASK			0x0000FF00
#define REG_HISTORGRAM_BOUNDARY4_MASK			0x000000FF
#define REG_HISTORGRAM_BOUNDARY5_MASK			0xFF000000
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_HISTORGRAM_BOUNDARY6_MASK			0xFF000000
#define REG_HISTORGRAM_BOUNDARY7_MASK			0x00FF0000
#define REG_HISTORGRAM_BOUNDARY8_MASK			0x0000FF00
#define REG_HISTORGRAM_BOUNDARY9_MASK			0x000000FF
#define REG_HISTORGRAM_BOUNDARYA_MASK			0xFF000000
#define REG_HISTORGRAM_BOUNDARYB_MASK			0x00FF0000
#define REG_HISTORGRAM_BOUNDARYC_MASK			0x0000FF00
#define REG_HISTORGRAM_BOUNDARYD_MASK			0x000000FF
#define REG_HISTORGRAM_BOUNDARYE_MASK			0xFF000000
#define REG_HISTORGRAM_BOUNDARYF_MASK			0x00FF0000
#endif

/* bit mapping of preprocessing control register 2 */
#define REG_PREPROCESS2_AE_AREA_ALL_ENABLE_BIT	0x00800000
#define ERG_PREPROCESS2_AE_COUNT_ENABLE_BIT		0x00400000
#define REG_PREPROCESS2_AE_PID_POLARITY_BIT		0x00200000
#define REG_PREPROCESS2_AE_GID_POLARITY_BIT		0x00100000
#define REG_PREPROCESS2_AE_COUNT_CLEAR_BIT		0x00080000
#define REG_PREPROCESS2_AE_GM_SEL_MASK				0x00060000
#define REG_PREPROCESS2_AE_PATH_SEL_BIT			0x00010000
#define REG_PREPROCESS2_ATF_EDGE_ENABLE_BIT		0x00008000
#define REG_PREPROCESS2_ATF_AREA_ALL_ENABLE_BIT	0x00004000
#define REG_PREPROCESS2_AWB_AREA_ALL_ENABLE_BIT	0x00000800
#define REG_PREPROCESS2_AE_GREEN_ONLY_BIT			0x00000200
#define REG_PREPROCESS2_RLEN_BIT						0x00000100
#define REG_PREPROCESS2_INTER_TOP_ENABLE_BIT		0x00000040	/* INTERPOLATION MODULE */

/* bit mapping of AE window 1~9 registers */
#define REG_AE_WINDOW_LEFT_MASK				0xFF000000
#define REG_AE_WINDOW_RIGHT_MASK				0x00FF0000
#define REG_AE_WINDOW_TOP_MASK				0x0000FF00
#define REG_AE_WINDOW_BOTTOM_MASK			0x000000FF

/* bit mapping of AWB window register */
#define REG_EDGE_V_CTRL_HPEN_BIT				0x80000000
#define ERG_EDGE_V_CTRL_E_TH1_V_MASK		0x7F000000
#define REG_EDGE_V_CTRL_HALF_V_MASK			0x003F0000
#define REG_EDGE_V_CTRL_SUP_V_MASK			0x0000C000
#define REG_EDGE_V_CTRL_SDN_V_MASK			0x00003000
#define REG_EDGE_V_CTRL_E_TH3_V_MASK		0X000000FF

/* bit mapping of Color processing stage control register 1 */
#define REG_CPS1_BYPASS_INTERPOLATION_BIT		0x00000080
#define ERG_CPS1_NONLINEAR_MODE_ENABLE_BIT	0x00000008
#define REG_CPS1_LINE_EDGE_ENABLE_BIT			0x00000002
#define REG_CPS1_LINE_JUDGE_ENABLE_BIT			0x00000001

/* bit mapping of interpolation register*/
#define REG_INTERPOLATION1_THRESHOLD_V_MASK		0x3F000000
#define REG_INTERPOLATION1_THRESHOLD_SM_MASK		0x001F0000
#define REG_INTERPOLATION1_THRESHOLD_DHV_MASK	0x00003F00
#define REG_INTERPOLATION1_THRESHOLD_RT_MASK		0x0000001F
#define REG_INTERPOLATION2_THRESHOLD_LEDGE_MASK	0x0000007F

/* bit mapping of Edge core register */
#define REG_EDGE_CORE_COREH_MASK				0x7F000000
#define REG_EDGE_CORE_EMBOSS1_BIT			0x00800000
#define REG_EDGE_CORE_EMBOSS2_BIT			0x00400000
#define REG_EDGE_CORE_COREH2_MASK			0x003F0000
#define REG_EDGE_CORE_COREV_MASK				0x00000F00
#define REG_EDGE_CORE_TOP_SLOPE_BIT			0x00000080
#define REG_EDGE_CORE_CORE_CON_MASK			0x0000007F

/* bit mapping of edge gain register 1*/
#define REG_EDGE_GAIN1_SPECIGAIN_MASK		0xC0000000
#define REG_EDGE_GAIN1_SPECIPONLY_MASK		0x30000000
#define REG_EDGE_GAIN1_EGAIN_H_MASK			0x0F000000
#define REG_EDGE_GAIN1_EGAIN_H2_MASK		0x000F0000
#define REG_EDGE_GAIN1_EGAIN_VB_MASK		0x00000F00
#define REG_EDGE_GAIN1_OILEN_BIT				0x00000080
#define REG_EDGE_GAIN1_KNEESEL_MASK			0x00000030
#define REG_EDGE_GAIN1_EGAINLINE_MASK		0x0000000F

/* bit mapping of edge gain register 2*/
#define REG_EDGE_GAIN2_SPECIABS_BIT			0x00000080
#define REG_EDGE_GAIN2_SPECIINV_BIT			0x00000040
#define REG_EDGE_GAIN2_EGAIN_HC_MASK		0x0000001F
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_EDGE_GAIN2_EGAIN_VC_MASK		0x001F0000
#define REG_EDGE_GAIN2_EGAIN_VA_MASK		0x0F000000
#endif

/* bit mapping of Edge threshold register */
#define REG_EDGE_THRESHOLD_ETH3_MASK				0xFF000000
#define REG_EDGE_THRESHOLD_ETH_CON_MASK			0x00FF0000
#define REG_EDGE_THRESHOLD_ONLYC_BIT				0x00008000
#define REG_EDGE_THRESHOLD_THRE_EDGE_SUP_MASK	0x00007F00
#define REG_EDGE_THRESHOLD_THRL_EDGE_SUP_MASK	0x0000007F

/* bit mapping of Edge vertical control register */
#define REG_EDGE_VERTICAL_HPEN_BIT				0x80000000
#define REG_EDGE_VERTICAL_E_TH1_V_MASK			0x7F000000
#define REG_EDGE_VERTICAL_HALF_V_MASK			0x003F0000
#define REG_EDGE_VERTICAL_SUP_V_MASK			0x00000C00
#define REG_EDGE_VERTICAL_SDN_V_MASK			0x00000300
#define REG_EDGE_VERTICAL_E_TH3_V_MASK			0x000000FF

/* bit mapping of Axis RGB gain register */
#define REG_AXIS_RGB_GAIN_R_GAIN_MASK			0x003F0000
#define REG_AXIS_RGB_GAIN_G_GAIN_MASK			0x00003F00
#define REG_AXIS_RGB_GAIN_B_GAIN_MASK			0x0000003F

/* bit mapping of OPD configuration register */
#define REG_OPD_CONFIG_OPD_ENABLE_BIT			0x80000000
#define REG_OPD_CONFIG_OPD_CLEAR_BIT			0x40000000
#define REG_OPD_CONFIG_COLOR_SUP_SEL_MASK		0x07000000
#define REG_OPD_CONFIG_U_GAIN_MASK				0x001F0000
#define REG_OPD_CONFIG_V_GAIN_MASK				0x00001F00
#define REG_OPD_CONFIG_Y_LIMIT_MASK				0x0000000F

/* bit mapping of OPD configuration parameter register */
#define REG_OPD_CONFIG_PARA_S_RB_P_MASK		0x7F000000
#define REG_OPD_CONFIG_PARA_S_RB_N_MASK		0x007F0000
#define REG_OPD_CONFIG_PARA_S_MG_P_MASK		0x00007F00
#define REG_OPD_CONFIG_PARA_S_MG_N_MASK		0x0000007F

/* bit mapping of color matrix 1~3 registers */
#define REG_COLOR_MATRIX_M1_MASK				0x00FF0000
#define REG_COLOR_MATRIX_M2_MASK				0x0000FF00
#define REG_COLOR_MATRIX_M3_MASK				0x000000FF

/* bit mapping of color matrix gain registers */
#define REG_COLOR_MATRIX_R_GAIN_MASK			0x003F0000
#define REG_COLOR_MATRIX_G_GAIN_MASK			0x00003F00
#define REG_COLOR_MATRIX_B_GAIN_MASK			0x0000003F

/* bit mapping of Color processing stage control register 1 */
#define REG_CPS2_BYPASS_GAMMA_BIT				0x00000080
#define REG_CPS2_RGB_EDGE_ENABLE_BIT			0x00000040
#define REG_CPS2_Y_EDGE_ENABLE_BIT				0x00000020
#define REG_CPS2_OPDGB_IVT_BIT					0x00000010
#define REG_CPS2_Y_EDGE_GAIN_MASK				0x0000000F

/* bit mapping of AWB RGB gain register */
#define REG_AWB_RGB_GAIN_R_GAIN_MASK			0x00FF0000
#define REG_AWB_RGB_GAIN_G_GAIN_MASK			0x0000FF00
#define REG_AWB_RGB_GAIN_B_GAIN_MASK			0x000000FF

/* bit mapping of Gamma RGB flare register */
#define REG_GAMMA_RGB_FLARE_SIGN_R_BIT			0x00800000
#define REG_GAMMA_RGB_FLARE_FLARE_R_MASK		0x003F0000
#define REG_GAMMA_RGB_FLARE_SIGN_G_BIT			0x00008000
#define REG_GAMMA_RGB_FLARE_FLARE_G_MASK		0x00003F00
#define REG_GAMMA_RGB_FLARE_SIGN_B_BIT			0x00000080
#define REG_GAMMA_RGB_FLARE_FLARE_B_MASK		0x0000003F

/* bit mapping of Y channel configuration register */
#define REG_Y_CH_CONFIG_CONTRAST_GAIN_MASK	0x007F0000
#define REG_Y_CH_ONFIG_BRIGHT_SIGN_BIT			0x00008000
#define REG_Y_CH_CONFIG_BRIGHT_OFFSET_MASK	0x00007F00
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_VSUP_ENABLE_MASK						0x00000080
#define REG_UV_CH_LOW_PASS_ENABLE_MASK			0x00000020
#endif
#define REG_Y_CH_CONFIG_CSUP_EDGE_GAIN_MASK	0x0000001F

/* bit mapping of UV channel configuration register */
#define REG_UV_CH_CONFIG_U11_MASK				0xFF000000
#define REG_UV_CH_CONFIG_V11_MASK				0x00FF0000
#define REG_UV_CH_CONFIG_U_OFFSET_MASK			0x0000FF00
#define REG_UV_CH_CONFIG_V_OFFSET_MASK			0x000000FF

/* bit mapping of space convert YUV register 1~2 */
#define REG_SPACE_CVT_YUV_Y_GAIN_MASK			0x00FF0000
#define REG_SPACE_CVT_YUV_U_GAIN_MASK			0x0000FF00
#define REG_SPACE_CVT_YUV_V_GAIN_MASK			0x000000FF
#define REG_SPACE_CVT_YUV_Y_OFFSET_MASK		0x00FF0000
#define REG_SPACE_CVT_YUV_U_OFFSET_MASK		0x0000FF00
#define REG_SPACE_CVT_YUV_V_OFFSET_MASK		0x000000FF

/* bit mapping of Gamma operation register 1~3 */
#define REG_GAMMA_OPERATION_GAMMA_B1_MASK		0xFF000000
#define REG_GAMMA_OPERATION_GAMMA_B2_MASK		0x00FF0000
#define REG_GAMMA_OPERATION_GAMMA_B3_MASK		0x0000FF00
#define REG_GAMMA_OPERATION_GAMMA_B4_MASK		0x000000FF
#define REG_GAMMA_OPERATION_GAMMA_B5_MASK		0xFF000000
#define REG_GAMMA_OPERATION_GAMMA_B6_MASK		0x00FF0000
#define REG_GAMMA_OPERATION_GAMMA_B7_MASK		0x0000FF00
#define REG_GAMMA_OPERATION_GAMMA_B8_MASK		0x000000FF
#define REG_GAMMA_OPERATION_GAMMA_B9_MASK		0xFF000000
#define REG_GAMMA_OPERATION_GAMMA_B10_MASK	0x00FF0000
#define REG_GAMMA_OPERATION_GAMMA_B11_MASK	0x0000FF00

/* bit mapping of 1024 Gamma table */
#define REG_GAMMA_OPERATION_1024_ENABLE_BIT	0x00000001
#define INTMEM_GAMMA_1024_BYTE1_MASK			0xFF000000
#define INTMEM_GAMMA_1024_BYTE2_MASK			0x00FF0000
#define INTMEM_GAMMA_1024_BYTE3_MASK			0x0000FF00
#define INTMEM_GAMMA_1024_BYTE4_MASK			0x000000FF

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* bit mapping of Sensor Gamma R register 1~3 */
#define REG_SENSOR_GAMMA_ENABLE_MASK	0x10000000
#define REG_SENSOR_GAMMA_IVT_MASK		0x01000000
#define REG_SENSOR_GAMMA_R_B1_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_R_B2_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_R_B3_MASK		0x000000FF
#define REG_SENSOR_GAMMA_R_B4_MASK		0xFF000000
#define REG_SENSOR_GAMMA_R_B5_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_R_B6_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_R_B7_MASK		0x000000FF
#define REG_SENSOR_GAMMA_R_B8_MASK		0xFF000000
#define REG_SENSOR_GAMMA_R_B9_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_R_B10_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_R_B11_MASK		0x000000FF
#if(!(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES)))                                       
/* bit mapping of Sensor Gamma G register 1~3 */
#define REG_SENSOR_GAMMA_G_B1_MASK		0xFF000000
#define REG_SENSOR_GAMMA_G_B2_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_G_B3_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_G_B4_MASK		0x000000FF
#define REG_SENSOR_GAMMA_G_B5_MASK		0xFF000000
#define REG_SENSOR_GAMMA_G_B6_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_G_B7_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_G_B8_MASK		0x000000FF
#define REG_SENSOR_GAMMA_G_B9_MASK		0xFF000000
#define REG_SENSOR_GAMMA_G_B10_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_G_B11_MASK		0x0000FF00
#endif

#if(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
/* bit mapping of Sensor Gamma G register 1~3 */
#define REG_SENSOR_GAMMA_GR_B1_MASK		0xFF000000
#define REG_SENSOR_GAMMA_GR_B2_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_GR_B3_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_GR_B4_MASK		0x000000FF
#define REG_SENSOR_GAMMA_GR_B5_MASK		0xFF000000
#define REG_SENSOR_GAMMA_GR_B6_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_GR_B7_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_GR_B8_MASK		0x000000FF
#define REG_SENSOR_GAMMA_GR_B9_MASK		0xFF000000
#define REG_SENSOR_GAMMA_GR_B10_MASK	0x00FF0000
#define REG_SENSOR_GAMMA_GR_B11_MASK	0x0000FF00

#define REG_SENSOR_GAMMA_GB_B1_MASK		0xFF000000
#define REG_SENSOR_GAMMA_GB_B2_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_GB_B3_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_GB_B4_MASK		0x000000FF
#define REG_SENSOR_GAMMA_GB_B5_MASK		0xFF000000
#define REG_SENSOR_GAMMA_GB_B6_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_GB_B7_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_GB_B8_MASK		0x000000FF
#define REG_SENSOR_GAMMA_GB_B9_MASK		0xFF000000
#define REG_SENSOR_GAMMA_GB_B10_MASK	0x00FF0000
#define REG_SENSOR_GAMMA_GB_B11_MASK	0x0000FF00
#endif
                                               
/* bit mapping of Sensor Gamma B register 1~3 */
#define REG_SENSOR_GAMMA_B_B1_MASK		0xFF000000
#define REG_SENSOR_GAMMA_B_B2_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_B_B3_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_B_B4_MASK		0x000000FF
#define REG_SENSOR_GAMMA_B_B5_MASK		0xFF000000
#define REG_SENSOR_GAMMA_B_B6_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_B_B7_MASK		0x0000FF00
#define REG_SENSOR_GAMMA_B_B8_MASK		0x000000FF
#define REG_SENSOR_GAMMA_B_B9_MASK		0xFF000000
#define REG_SENSOR_GAMMA_B_B10_MASK		0x00FF0000
#define REG_SENSOR_GAMMA_B_B11_MASK		0x0000FF00

/* bit mapping of defect pixel register */
#define REG_DEFECT_ENABLE_BIT					0x01000000

/* ae area register */
#define REG_AE_AREACNT_MASK					0x0000003F
#define REG_AE_FRAMECNT_MASK					0x0000FF00
#define REG_AE_HOFFSET_MASK					0x00FF0000
#define REG_AE_VOFFSET_MASK					0xFF000000
#endif

/* bit mapping of LPF control register */
#if (defined(DRV_ISP_6219_SERIES))
#define REG_LPF_Y_LPF_ENABLE_BIT				0x00004000
#define REG_LPF_Y_LPF_TYPE_MASK				0x00003000
#define REG_LPF_C_LPF_ENABLE_BIT				0x00000800
#define REG_LPF_C_LPF_TYPE_MASK				0x00000600
#define REG_LPF_SUB_SAMPLE_MASK				0x00000007
#define REG_LPF_SUB_SAMPLE_1_8				0x00000004
#define REG_LPF_SUB_SAMPLE_1_4				0x00000002
#define REG_LPF_SUB_SAMPLE_1_2				0x00000001
#define REG_LPF_SUB_SAMPLE_1_1				0x00000000

#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define REG_LPF_V_LPF_ENABLE_BIT				0x00010000
#define REG_LPF_Y_LPF_ENABLE_BIT				0x00008000
#define REG_LPF_C_LPF_ENABLE_BIT				0x00001000
/* bit mapping of Y LPF control register */
#define REG_Y_LPF_WEIGHT0_MASK				0xFF000000
#define REG_Y_LPF_WEIGHT1_MASK				0x00FF0000
#define REG_Y_LPF_WEIGHT2_MASK				0x0000FF00
#define REG_Y_LPF_WEIGHT3_MASK				0x000000FF

/* bit mapping of CBCR LPF control register */
#define REG_C_LPF_WEIGHT0_MASK				0xFF000000
#define REG_C_LPF_WEIGHT1_MASK				0x00FF0000
#define REG_C_LPF_WEIGHT2_MASK				0x0000FF00
#define REG_C_LPF_WEIGHT3_MASK				0x000000FF

/* bit mapping of vertical sub-sample control register */
#define REG_VERTICAL_SUB_V_SUB_EN_BIT		0x10000000
#define REG_VERTICAL_SUB_V_SUB_IN_MASK		0x0FFF0000
#define REG_VERTICAL_SUB_V_SUB_OUT_MASK	0x00000FFF

/* bit mapping of horizontal sub-sample control register */
#define REG_HORIZONTAL_SUB_H_SUB_EN_BIT	0x10000000
#define REG_HORIZONTAL_SUB_H_SUB_IN_MASK	0x0FFF0000
#define REG_HORIZONTAL_SUB_H_SUB_OUT_MASK	0x00000FFF
#endif

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
/* bit mapping of result window register */
#define REG_RESULT_WINDOW_ENABLE_BIT		0x10000000
#define REG_RESULT_WINDOW_START_MASK		0x0FFF0000
#define REG_RESULT_WINDOW_END_MASK			0x00000FFF
#endif

/* bit mapping of Camera interface debug mode control register */
#define REG_DEBUG_GMC_ENABLE_BIT				0x00000080
#define REG_DEBUG_GMC_MODE_BIT				0x00000040
#define REG_DEBUG_DATA_COUNT_ENABLE_BIT	0x00000020
#define REG_DEBUG_DATA_COUNT_MODE_MASK		0x00000018

#define REG_DEBUG_RAW_RGB_OUTPUT_COUNT		0
#define REG_DEBUG_YCBCR_OUPUT_COUNT			1
#define REG_DEBUG_GMC_OUTPUT_COUNT			2
#define REG_DEBUG_RESIZER_ACK_COUNT			3

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* bit mapping of shading control register */
#define REG_SHADING_RANGE_ENABLE_BIT		0x20000000
#define REG_SHADING_ENABLE_BIT				0x10000000
#define REG_SHADING_CENTERY_MASK				0x0FFF0000
#define REG_SHADING_K_FACTOR_MASK			0x0000C000
#define REG_SHADING_RADIUS_FACTOR_MASK		0x00003000
#define REG_SHADING_CENTERX_MASK				0x00000FFF

#define REG_SHADING_KR_MASK					0xFF000000
#define REG_SHADING_KG_MASK					0x00FF0000
#define REG_SHADING_KB_MASK					0x0000FF00
#define REG_SHADING_RANGE_MASK				0x000000FF

#define REG_SHADING_CURVE_ENABLE_BIT		0x10000000
#define REG_SHADING_CURVE_IVT_MASK			0x04000000
#define REG_SHADING_CURVE_SEL_MASK			0x03000000
#define REG_SHADING_CURVE_R_B1_MASK			0x00FF0000
#define REG_SHADING_CURVE_R_B2_MASK			0x0000FF00
#define REG_SHADING_CURVE_R_B3_MASK			0x000000FF
#define REG_SHADING_CURVE_R_B4_MASK			0xFF000000
#define REG_SHADING_CURVE_R_B5_MASK			0x00FF0000
#define REG_SHADING_CURVE_R_B6_MASK			0x0000FF00
#define REG_SHADING_CURVE_R_B7_MASK			0x000000FF
#define REG_SHADING_CURVE_R_B8_MASK			0xFF000000
#define REG_SHADING_CURVE_R_B9_MASK			0x00FF0000
#define REG_SHADING_CURVE_R_B10_MASK		0x0000FF00
#define REG_SHADING_CURVE_R_B11_MASK		0x000000FF
#define REG_SHADING_CURVE_G_B1_MASK			0xFF000000
#define REG_SHADING_CURVE_G_B2_MASK			0x00FF0000
#define REG_SHADING_CURVE_G_B3_MASK			0x0000FF00
#define REG_SHADING_CURVE_G_B4_MASK			0x000000FF
#define REG_SHADING_CURVE_G_B5_MASK			0xFF000000
#define REG_SHADING_CURVE_G_B6_MASK			0x00FF0000
#define REG_SHADING_CURVE_G_B7_MASK			0x0000FF00
#define REG_SHADING_CURVE_G_B8_MASK			0x000000FF
#define REG_SHADING_CURVE_G_B9_MASK			0xFF000000
#define REG_SHADING_CURVE_G_B10_MASK		0x00FF0000
#define REG_SHADING_CURVE_G_B11_MASK		0x0000FF00
#define REG_SHADING_CURVE_B_B1_MASK			0xFF000000
#define REG_SHADING_CURVE_B_B2_MASK			0x00FF0000
#define REG_SHADING_CURVE_B_B3_MASK			0x0000FF00
#define REG_SHADING_CURVE_B_B4_MASK			0x000000FF
#define REG_SHADING_CURVE_B_B5_MASK			0xFF000000
#define REG_SHADING_CURVE_B_B6_MASK			0x00FF0000
#define REG_SHADING_CURVE_B_B7_MASK			0x0000FF00
#define REG_SHADING_CURVE_B_B8_MASK			0x000000FF
#define REG_SHADING_CURVE_B_B9_MASK			0xFF000000
#define REG_SHADING_CURVE_B_B10_MASK		0x00FF0000
#define REG_SHADING_CURVE_B_B11_MASK		0x0000FF00
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* bit mapping of AE window size register */
#define REG_AE_VSIZE_MASK						0xFFFF0000
#define REG_AE_HSIZE_MASK						0x0000FFFF

/* bit mapping of AE weight register */
#define REG_AE_WEIGHT00_MASK					0xF0000000
#define REG_AE_WEIGHT01_MASK					0x0F000000
#define REG_AE_WEIGHT02_MASK					0x00F00000
#define REG_AE_WEIGHT03_MASK					0x000F0000
#define REG_AE_WEIGHT04_MASK					0x0000F000
#define REG_AE_WEIGHT05_MASK					0x00000F00
#define REG_AE_WEIGHT06_MASK					0x000000F0
#define REG_AE_WEIGHT07_MASK					0x0000000F
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* bit mapping of auto defect control register */
#define REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK	0xFFFF0000
#define REG_AUTO_DEFECT_ADC_EN_BIT			0x80000000
#define REG_AUTO_DEFECT_ADL_EN_BIT			0x40000000
#define REG_AUTO_DEFECT_ADR_EN_BIT			0x20000000
#define REG_AUTO_DEFECT_ADU_EN_BIT			0x10000000
#define REG_AUTO_DEFECT_ADD_EN_BIT			0x08000000
#define REG_AUTO_DEFECT_DEADCHECK_BIT		0x04000000
#define REG_AUTO_DEFECT_GCHECK_SEL_MASK	0x03000000
#define REG_AUTO_DEFECT_RBCHECK_SEL_MASK	0x00C00000
#define REG_AUTO_DEFECT_BRIGHTTHD_MASK		0x00380000
#define REG_AUTO_DEFECT_BLACKTHD_MASK		0x00070000
#define REG_AUTO_DEFECT_AE_INTERVAL_MASK	0x0000FF00

#define REG_AUTO_DEFECT_GCHECKTHD_MASK		0xFF000000
#define REG_AUTO_DEFECT_RBCHECKTHD_MASK	0x00FF0000
#define REG_AUTO_DEFECT_GCORRECTTHD_MASK	0x0000FF00
#define REG_AUTO_DEFECT_RBCORRECTTHD_MASK	0x000000FF

/* bit mapping of flash control register */
#define REG_FLASH_OUT_BIT						0x80000000
#define REG_FLASH_EN_BIT						0x10000000
#define REG_FLASH_STARTPNT_BIT				0x01000000
#define REG_FLASH_POL_BIT						0x00100000
#define REG_FLASH_LNUNIT_MASK					0x000F0000
#define REG_FLASH_LNUNIT_NO_MASK				0x0000FF00
#define REG_FLASH_FRAME_DELAY_MASK			0x00000003

/* bit mapping of CAM reset register */
#define REG_CAM_RESET_ISP_FRAME_COUNT_MASK		0x0000FF00
#define REG_CAM_RESET_ISP_RESET_BIT					0x00000001

/* bit mapping of TG status register */
#define REG_TG_STATUS_MASK								0x0000003F
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* bit mapping of imageproc hue register */
#define REG_IMGPROC_HUE_ENABLE_BIT					0x00010000
#define REG_IMGPROC_HUE_HUE11_MASK					0x0000FF00
#define REG_IMGPROC_HUE_HUE12_MASK					0x000000FF
#define REG_IMGPROC_HUE_HUE21_MASK					0xFF000000
#define REG_IMGPROC_HUE_HUE22_MASK					0x00FF0000
#endif

/* macros of TG phase counter register */
#define ENABLE_CAMERA_TG_PHASE_COUNTER			REG_ISP_TG_PHASE_COUNTER |= REG_TGPC_PHASE_COUNTER_ENABLE_BIT;
#define DISABLE_CAMERA_TG_PHASE_COUNTER		REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_PHASE_COUNTER_ENABLE_BIT;
#define ENABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS	REG_ISP_TG_PHASE_COUNTER |= REG_TGPC_CLK_OUTPUT_ENABLE_BIT;
#define DISABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS	REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_CLK_OUTPUT_ENABLE_BIT;
#define SET_CMOS_CLOCK_POLARITY_HIGH			REG_ISP_TG_PHASE_COUNTER |= REG_TGPC_CLK_POLARITY_CTRL_BIT;
#define SET_CMOS_CLOCK_POLARITY_LOW				REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_CLK_POLARITY_CTRL_BIT;
#define SET_TG_OUTPUT_CLK_DIVIDER(n)			REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_CLK_OUTPUT_DIV_MASK; \
															REG_ISP_TG_PHASE_COUNTER |= (n<<24);
#define SET_CMOS_RISING_EDGE(n)	 				REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_RISING_EDGE_CLK_CNT_MASK; \
															REG_ISP_TG_PHASE_COUNTER |= (n<<20);
#define SET_CMOS_FALLING_EDGE(n) 				REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_FALLING_EDGE_CLK_CNT_MASK; \
															REG_ISP_TG_PHASE_COUNTER |= (n<<16);
#define SET_TG_PIXEL_CLK_DIVIDER(n)				REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_PIXEL_CLK_DIV_MASK; \
															REG_ISP_TG_PHASE_COUNTER |= (n<<4);
#define SET_CMOS_DATA_LATCH(n)					REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_DATA_LATCH_POSITION_MASK;\
															REG_ISP_TG_PHASE_COUNTER |= n;
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ENABLE_CAMERA_SENSOR_HVALID_HREF		REG_ISP_TG_PHASE_COUNTER |= REG_TGPC_HVALID_ENABLE_BIT;
#define DISABLE_CAMERA_SENSOR_HVALID_HREF		REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_HVALID_ENABLE_BIT;
#define ENABLE_CAMERA_SENSOR_CLKIN_MONITOR	REG_ISP_TG_PHASE_COUNTER |= REG_TGPC_SENSOR_CLKIN_MONITOR_BIT;
#define DISABLE_CAMERA_SENSOR_CLKIN_MONITOR	REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_SENSOR_CLKIN_MONITOR_BIT;
#define ENABLE_CAMERA_PIXEL_CLK_INV				REG_ISP_TG_PHASE_COUNTER |= REG_TGPC_PIXEL_CLK_INV_BIT;
#define DISABLE_CAMERA_PIXEL_CLK_INV			REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_PIXEL_CLK_INV_BIT;
#define ENABLE_CAMERA_PIXEL_CLKIN_ENABLE		REG_ISP_TG_PHASE_COUNTER |= REG_TGPC_PIXEL_CLKIN_ENABLE_BIT;
#define DISABLE_CAMERA_PIXEL_CLKIN_ENABLE		REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_PIXEL_CLKIN_ENABLE_BIT;
#define ENABLE_CAMERA_TG_CLK_48M					REG_ISP_TG_PHASE_COUNTER |= REG_TGPC_PIXEL_CLK_SELECT_BIT;
#define DISABLE_CAMERA_TG_CLK_48M				REG_ISP_TG_PHASE_COUNTER &= ~REG_TGPC_PIXEL_CLK_SELECT_BIT;
#endif
/* macros of CMOS sensor size configuration register */
#define SET_CMOS_SENSOR_SIZE(width, height)	REG_ISP_CMOS_SENSOR_SIZE_CONFIG = ((width<<16)|height);

/* macros of TG grab start/end pixel configuration register */
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define SET_TG_GRAB_PIXEL(start,pixel)		REG_ISP_TG_GRAB_RANGE_PIXEL_CONFIG =((start<<16) | (pixel+start-1+6));
#else
#define SET_TG_GRAB_PIXEL(start,pixel)		REG_ISP_TG_GRAB_RANGE_PIXEL_CONFIG =((start<<16) | (pixel+start-1+4));
#endif
/* macros of TG grab start/end line configuration register */
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define SET_TG_GRAB_LINE(start,line)		REG_ISP_TG_GRAB_RANGE_LINE_CONFIG =((start<<16) | (line+start-1+6));
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES))
#define SET_TG_GRAB_LINE(start,line)		REG_ISP_TG_GRAB_RANGE_LINE_CONFIG =((start<<16) | (line+start-1+4));
#else
#define SET_TG_GRAB_LINE(start,line)		REG_ISP_TG_GRAB_RANGE_LINE_CONFIG =((start<<16) | (line+start-1+2));
#endif
/* macros of YUV TG grab start/end pixel and line configuration register */
#if (!defined(DRV_ISP_6219_SERIES))
#define SET_YUV_TG_GRAB_PIXEL(start,pixel)	REG_ISP_TG_GRAB_RANGE_PIXEL_CONFIG =((start<<16) | ((pixel<<1)+start-1));
#define SET_YUV_TG_GRAB_LINE(start,line)		REG_ISP_TG_GRAB_RANGE_LINE_CONFIG =((start<<16) | (line+start-1));
#endif
/* macros of CMOS sensor mode configuration register */
#define SET_VSYNC_POLARITY_HIGH			REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_VSYNC_POLARITY_BIT;
#define SET_VSYNC_POLARITY_LOW			REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_VSYNC_POLARITY_BIT;
#define SET_HSYNC_POLARITY_HIGH			REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_HSYNC_POLARITY_BIT;
#define SET_HSYNC_POLARITY_LOW			REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_HSYNC_POLARITY_BIT;
#define POWER_ON_CMOS_SENSOR				REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT;
#define POWER_OFF_CMOS_SENSOR				REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_POWER_ON_BIT;
#define RESET_CMOS_SENSOR					REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;\
													REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;
#define RESET_CMOS_SENSOR_MODE1			REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;\
													REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;
#define RESET_CMOS_SENSOR_MODE2			REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;\
													REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;

#define ENABLE_AUTO_HSYNC_PIXEL_CAL		REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_AUTO_SYNC_ENABLE_BIT;
#define DISABLE_AUTO_HSYNC_PIXEL_CAL	REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_AUTO_SYNC_ENABLE_BIT;
#define ENABLE_CMOS_SESNOR					REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_ENABLE_BIT;
#define DISABLE_CMOS_SESNOR				REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_ENABLE_BIT;

/* macros of camera interface R/B, Gr/Gb offset adjustment register */
#define SET_RAW_DATA_R_NEG_SIGN			REG_ISP_RGB_OFFSET_ADJUS |= REG_COMP_R_OFFSET_ADJ_SIGN_BIT;
#define SET_RAW_DATA_R_POS_SIGN			REG_ISP_RGB_OFFSET_ADJUS &= ~REG_COMP_R_OFFSET_ADJ_SIGN_BIT;
#define SET_RAW_DATA_R_OFFSET_ADJ(n)	REG_ISP_RGB_OFFSET_ADJUS &= ~REG_COMP_R_OFFSET_ADJ_MASK;\
													REG_ISP_RGB_OFFSET_ADJUS |= (n<<24);
#define SET_RAW_DATA_GR_NEG_SIGN			REG_ISP_RGB_OFFSET_ADJUS |= REG_COMP_GR_OFFSET_ADJ_SIGN_BIT;
#define SET_RAW_DATA_GR_POS_SIGN			REG_ISP_RGB_OFFSET_ADJUS &= ~REG_COMP_GR_OFFSET_ADJ_SIGN_BIT;
#define SET_RAW_DATA_GR_OFFSET_ADJ(n)	REG_ISP_RGB_OFFSET_ADJUS &= ~REG_COMP_GR_OFFSET_ADJ_MASK;\
													REG_ISP_RGB_OFFSET_ADJUS |= (n<<16);
#define SET_RAW_DATA_B_NEG_SIGN			REG_ISP_RGB_OFFSET_ADJUS |= REG_COMP_B_OFFSET_ADJ_SIGN_BIT;
#define SET_RAW_DATA_B_POS_SIGN			REG_ISP_RGB_OFFSET_ADJUS &= ~REG_COMP_B_OFFSET_ADJ_SIGN_BIT;
#define SET_RAW_DATA_B_OFFSET_ADJ(n)	REG_ISP_RGB_OFFSET_ADJUS &= ~REG_COMP_B_OFFSET_ADJ_MASK;\
													REG_ISP_RGB_OFFSET_ADJUS |= (n<<8);
#define SET_RAW_DATA_GB_NEG_SIGN			REG_ISP_RGB_OFFSET_ADJUS |= REG_COMP_GB_OFFSET_ADJ_SIGN_BIT;
#define SET_RAW_DATA_GB_POS_SIGN			REG_ISP_RGB_OFFSET_ADJUS &= ~REG_COMP_GB_OFFSET_ADJ_SIGN_BIT;
#define SET_RAW_DATA_GB_OFFSET_ADJ(n)	REG_ISP_RGB_OFFSET_ADJUS &= ~REG_COMP_GB_OFFSET_ADJ_MASK;\
													REG_ISP_RGB_OFFSET_ADJUS |= n;

/* macros of camera interface view finder mode control register */
#define ENABLE_VIEW_FINDER_MODE		REG_ISP_VIEW_FINDER_MODE_CTRL |= REG_VIEW_FINDER_MODE_DATA_ENABLE_BIT;
#define DISABLE_VIEW_FINDER_MODE		REG_ISP_VIEW_FINDER_MODE_CTRL &= ~REG_VIEW_FINDER_MODE_DATA_ENABLE_BIT;
#define VIEW_FINDER_MODE_IS_ENABLE	(REG_ISP_VIEW_FINDER_MODE_CTRL & REG_VIEW_FINDER_MODE_DATA_ENABLE_BIT)
#define SET_CAMERA_PREVIEW_MODE		REG_ISP_VIEW_FINDER_MODE_CTRL &= ~REG_VIEW_FINDER_MODE_CAPTURE_MODE_BIT;
#define SET_CAMERA_CAPTURE_MODE		REG_ISP_VIEW_FINDER_MODE_CTRL |= REG_VIEW_FINDER_MODE_CAPTURE_MODE_BIT;
#define SET_CAMERA_FRAME_RATE(n)		REG_ISP_VIEW_FINDER_MODE_CTRL &= ~REG_VIEW_FINDER_MODE_FRAME_RATE_MASK;\
												REG_ISP_VIEW_FINDER_MODE_CTRL |= n;
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define SET_CAMERA_CAPTURE_DELAY(n)	REG_ISP_VIEW_FINDER_MODE_CTRL &= ~REG_VIEW_FINDER_MODE_SP_DELAY_MASK;\
												REG_ISP_VIEW_FINDER_MODE_CTRL |= (n<<8);
#endif

/* macros of Camera interface interrupt enable register */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ENABLE_CAMERA_VD_DONE_INT				REG_ISP_INT_ENABLE |= REG_CAMERA_INT_VD_DONE_ENABLE_BIT;
#define DISABLE_CAMERA_VD_DONE_INT				REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_VD_DONE_ENABLE_BIT;
#define SEL_CAMERA_FLASH_START_FROM_VD			REG_ISP_INT_ENABLE |= REG_CAMERA_INT_FLASH_SEL_ENABLE_BIT;
#define SEL_CAMERA_FLASH_START_FROM_LINENO	REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_FLASH_SEL_ENABLE_BIT;
#define ENABLE_CAMERA_AVSYNC_DONE_INT			REG_ISP_INT_ENABLE |= REG_CAMERA_INT_AVSYNC_ENABLE_BIT;
#define DISABLE_CAMERA_AVSYNC_DONE_INT			REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_AVSYNC_ENABLE_BIT;
#define ENABLE_CAMERA_FLASH_DONE_INT			REG_ISP_INT_ENABLE |= REG_CAMERA_INT_FLASH_DONE_ENABLE_BIT;
#define DISABLE_CAMERA_FLASH_DONE_INT			REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_FLASH_DONE_ENABLE_BIT;
#define SET_CAMERA_FLASH_START_LINENO(n)		REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_FLASH_LINENO_MASK;\
															REG_ISP_INT_ENABLE |= (n<<16);
#elif (defined(DRV_ISP_6228_SERIES))
#define ENABLE_CAMERA_VD_DONE_INT				REG_ISP_INT_ENABLE |= REG_CAMERA_INT_VD_DONE_ENABLE_BIT;
#define DISABLE_CAMERA_VD_DONE_INT				REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_VD_DONE_ENABLE_BIT;
#define ENABLE_CAMERA_TG_DONE_INT				REG_ISP_INT_ENABLE |= REG_CAMERA_INT_TG_DONE_ENABLE_BIT;
#define DISABLE_CAMERA_TG_DONE_INT				REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_TG_DONE_ENABLE_BIT;
#define SET_CAMERA_TG_START_LINENO(n)			REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_TG_LINENO_MASK;\
															REG_ISP_INT_ENABLE |= (n<<16);
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ENABLE_CAMERA_ATF_DONE_INT				REG_ISP_INT_ENABLE |= REG_CAMERA_INT_ATF_DONE_ENABLE_BIT;
#define DISABLE_CAMERA_ATF_DONE_INT				REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_ATF_DONE_ENABLE_BIT;
#define ENABLE_CAMERA_AE_DONE_INT				REG_ISP_INT_ENABLE |= REG_CAMERA_INT_AE_DONE_ENABLE_BIT;
#define DISABLE_CAMERA_AE_DONE_INT				REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_AE_DONE_ENABLE_BIT;
#define ENABLE_CAMERA_ISP_DONE_INT				REG_ISP_INT_ENABLE |= REG_CAMERA_INT_ISP_DONE_ENABLE_BIT;
#define DISABLE_CAMERA_ISP_DONE_INT				REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_ISP_DONE_ENABLE_BIT;
#endif
#define ENABLE_CAMERA_IDLE_INT					REG_ISP_INT_ENABLE |= REG_CAMERA_INT_IDLE_ENABLE_BIT;
#define DISABLE_CAMERA_IDLE_INT					REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_IDLE_ENABLE_BIT;
#define ENABLE_CAMERA_GMC_OVERRUN_INT  	 	REG_ISP_INT_ENABLE |= REG_CAMERA_INT_GMC_OVERRUN_ENABLE_BIT;
#define DISABLE_CAMERA_GMC_OVERRUN_INT  		REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_GMC_OVERRUN_ENABLE_BIT;
#define ENABLE_CAMERA_RESIZER_OVERRUN_INT		REG_ISP_INT_ENABLE |= REG_CAMERA_INT_RESIZER_OVERRUN_ENABLE_BIT;
#define DISABLE_CAMERA_RESIZER_OVERRUN_INT  	REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_RESIZER_OVERRUN_ENABLE_BIT;
#define ENABLE_CAMERA_FRAME_READY_INT   		REG_ISP_INT_ENABLE |= REG_CAMERA_INT_FRAME_READY_ENABLE_BIT;
#define DISABLE_CAMERA_FRAME_READY_INT  		REG_ISP_INT_ENABLE &= ~REG_CAMERA_INT_FRAME_READY_ENABLE_BIT;

/* macros of CAMERA interface interrupt status register */
#define CAMERA_FRAME_READY				(REG_ISP_INT_STATUS & REG_CAMERA_INT_FRAME_READY_STATUS_BIT)
#define CAMERA_RESIZER_OVERRUN      (REG_ISP_INT_STATUS & REG_CAMERA_INT_RESIZER_OVERRUN_STATUS_BIT)
#define CAMERA_GMC_OVERRUN				(REG_ISP_INT_STATUS & REG_CAMERA_INT_GMC_OVERRUN_STATUS_BIT)
#define CAMERA_IDLE						(REG_ISP_INT_STATUS & REG_CAMERA_INT_IDLE_STATUS_BIT)
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define CAMERA_ISP_DONE					(REG_ISP_INT_STATUS & REG_CAMERA_INT_ISP_DONE_STATUS_BIT)
#define CAMERA_AE_DONE					(REG_ISP_INT_STATUS & REG_CAMERA_INT_AE_DONE_STATUS_BIT)

/* macros of camera path config register */
#define ENABLE_DATA_COUNTER				REG_ISP_PATH_CONFIG |= REG_CAMERA_PATH_CNTON_BIT;
#define DISABLE_DATA_COUNTER				REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_CNTON_BIT;
#define SET_DATA_COUNTER_MODE(n)			REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_CNTMODE_MASK;\
													REG_ISP_PATH_CONFIG |= (n<<29);
#define SET_WRITE_FIFO_THD_LEVEL(n)		REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_WRITE_LEVEL_MASK;\
													REG_ISP_PATH_CONFIG |= (n<<24);
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ENABLE_BAYER10_OUT					REG_ISP_PATH_CONFIG |= REG_CAMERA_PATH_BAYER10_OUT_BIT;
#define DISABLE_BAYER10_OUT				REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_BAYER10_OUT_BIT;																									
#endif
#define ENABLE_REZ_DISCONN					REG_ISP_PATH_CONFIG |= REG_CAMERA_PATH_REZ_DISCONN_BIT;
#define DISABLE_REZ_DISCONN				REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_REZ_DISCONN_BIT;
#define DISABLE_REZ_LPF						REG_ISP_PATH_CONFIG |= REG_CAMERA_PATH_REZ_LPF_OFF_BIT;
#define ENABLE_REZ_LPF						REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_REZ_LPF_OFF_BIT;
#define SET_OUTPUT_PATH_TYPE(n)			REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_OUTPATH_TYPE_MASK;\
													REG_ISP_PATH_CONFIG |= (n<<20);
#define ENABLE_CAMERA_OUTPUT_TO_MEM		REG_ISP_PATH_CONFIG |= REG_CAMERA_PATH_OUTPATH_EN_BIT;
#define DISABLE_CAMERA_OUTPUT_TO_MEM	REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_OUTPATH_EN_BIT;
#define ENABLE_CAMERA_INDATA_FORMAT		REG_ISP_PATH_CONFIG |= REG_CAMERA_PATH_INDATA_FORMAT_MASK;
#define DISABLE_CAMERA_INDATA_FORMAT	REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_INDATA_FORMAT_MASK;
#define SET_CAMERA_INPUT_TYPE(n)			REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_INTYPE_SEL_MASK;\
													REG_ISP_PATH_CONFIG |= (n<<8);
#define SET_CAMERA_INPUT_ORDER(n)			REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_INORDER_SEL_MASK;\
													REG_ISP_PATH_CONFIG |= (n<<12);													
#define SET_CAMERA_INPUT_RATE(n)			REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_INPATH_RATE_MASK;\
													REG_ISP_PATH_CONFIG |= (n<<4);
#define ENABLE_CAMERA_INPATH_THROTTLE	REG_ISP_PATH_CONFIG |= REG_CAMERA_PATH_INPATH_THROTTLE_BIT;
#define DISABLE_CAMERA_INPATH_THROTTLE	REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_INPATH_THROTTLE_BIT;
#define ENABLE_CAMERA_INPUT_FROM_MEM	REG_ISP_PATH_CONFIG |= REG_CAMERA_PATH_INPATH_SEL_BIT;
#define DISABLE_CAMERA_INPUT_FROM_MEM	REG_ISP_PATH_CONFIG &= ~REG_CAMERA_PATH_INPATH_SEL_BIT;
#endif                                 
                                       
/* macros of Camera interface preprocessing control register 1*/
#define SET_PREPROCESS_GAIN(n) 			REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_GAIN_COMPENSATION_MASK;\
													REG_ISP_PREPROCESS_CTRL1 |= (n<<24);
#define SET_PREPROCESS_PIXEL_LIMIT(n) 	REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_PIXEL_LIMIT_MASK;\
													REG_ISP_PREPROCESS_CTRL1 |= (n<<16);
#define ENABLE_BYPASS_PRE_GAIN_MOD		REG_ISP_PREPROCESS_CTRL1	|= REG_PREPROCESS1_BYPASS_PREGAIN_BIT;
#define DISABLE_BYPASS_PRE_GAIN_MOD		REG_ISP_PREPROCESS_CTRL1	&= ~REG_PREPROCESS1_BYPASS_PREGAIN_BIT;
#define SET_PRE_GAIN_LID_POLARITY_HIGH	REG_ISP_PREPROCESS_CTRL1 |= REG_PREPROCESS1_LID_POLARITY_BIT;
#define SET_PRE_GAIN_LID_POLARITY_LOW	REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_LID_POLARITY_BIT;
#define SET_PRE_GAIN_PID_POLARITY_HIGH	REG_ISP_PREPROCESS_CTRL1 |= REG_PREPROCESS1_PID_POLARITY_BIT;
#define SET_PRE_GAIN_PID_POLARITY_LOW	REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_PID_POLARITY_BIT;
#define SET_FIRST_GRAB_COLOR(n)		   REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_PID_POLARITY_BIT;\
												   REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_LID_POLARITY_BIT;\
												   REG_ISP_PREPROCESS_CTRL1 |= (n<<12);
#define SET_PRE_GAIN_INTEGER_PART(n)	REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_PREGAIN_INT_PART_MASK;\
													REG_ISP_PREPROCESS_CTRL1 |= (n<<8);
#define SET_PRE_GAIN_FRAC_PART(n)		REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_PREGAIN_FRAC_PART_MASK;\
													REG_ISP_PREPROCESS_CTRL1 |= n;

/* macros of component R, G, B gain control register */
#define SET_INTER_STAGE1_B_GAIN(n)	REG_ISP_RGB_GAIN_CTRL1 &= ~REG_COMP_B_GAIN_CTRL_MASK;\
												REG_ISP_RGB_GAIN_CTRL1 |= (n<<16);
#if (defined(DRV_ISP_6219_SERIES))
#define SET_INTER_STAGE1_G_GAIN(n)	REG_ISP_RGB_GAIN_CTRL1 &= ~REG_COMP_G_GAIN_CTRL_MASK;\
												REG_ISP_RGB_GAIN_CTRL1 |= n;
#else
#define SET_INTER_STAGE1_GB_GAIN(n)	REG_ISP_RGB_GAIN_CTRL1 &= ~REG_COMP_GB_GAIN_CTRL_MASK;\
												REG_ISP_RGB_GAIN_CTRL1 |= n;
#define SET_INTER_STAGE1_GR_GAIN(n)	REG_ISP_RGB_GAIN_CTRL2 &= ~REG_COMP_GR_GAIN_CTRL_MASK;\
												REG_ISP_RGB_GAIN_CTRL2 |= n;
#endif
#define SET_INTER_STAGE1_R_GAIN(n)	REG_ISP_RGB_GAIN_CTRL2 &= ~REG_COMP_R_GAIN_CTRL_MASK;\
												REG_ISP_RGB_GAIN_CTRL2 |= (n<<16);

/* macros of higtogram boundary control register 1 */
#define SET_HISTOGRAM_BOUNDARY1(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL1 &= ~REG_HISTORGRAM_BOUNDARY1_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL1 |= (n<<24);
#define SET_HISTOGRAM_BOUNDARY2(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL1 &=	~REG_HISTORGRAM_BOUNDARY2_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL1 |= (n<<16);
#define SET_HISTOGRAM_BOUNDARY3(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL1 &= ~REG_HISTORGRAM_BOUNDARY3_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL1 |= (n<<8);
#define SET_HISTOGRAM_BOUNDARY4(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL1 &= ~REG_HISTORGRAM_BOUNDARY4_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL1 |= n;
#define SET_HISTOGRAM_BOUNDARY5(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL2 &= ~REG_HISTORGRAM_BOUNDARY5_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL2 |= (n<<24);
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define SET_HISTOGRAM_BOUNDARY6(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3 &= ~REG_HISTORGRAM_BOUNDARY6_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL3 |= (n<<24);                	
#define SET_HISTOGRAM_BOUNDARY7(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3 &=	~REG_HISTORGRAM_BOUNDARY7_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL3 |= (n<<16);                	
#define SET_HISTOGRAM_BOUNDARY8(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3 &= ~REG_HISTORGRAM_BOUNDARY8_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL3 |= (n<<8);                 	
#define SET_HISTOGRAM_BOUNDARY9(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3 &= ~REG_HISTORGRAM_BOUNDARY9_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL3 |= n;                      	
#define SET_HISTOGRAM_BOUNDARYA(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4 &= ~REG_HISTORGRAM_BOUNDARYA_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL4 |= (n<<24);                	
#define SET_HISTOGRAM_BOUNDARYB(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4 &= ~REG_HISTORGRAM_BOUNDARYB_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL4 |= (n<<16);                	
#define SET_HISTOGRAM_BOUNDARYC(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4 &=	~REG_HISTORGRAM_BOUNDARYC_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL4 |= (n<<8);;                	
#define SET_HISTOGRAM_BOUNDARYD(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4 &= ~REG_HISTORGRAM_BOUNDARYD_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL4 |= n;                      	
#define SET_HISTOGRAM_BOUNDARYE(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL5 &= ~REG_HISTORGRAM_BOUNDARYE_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL5 |= (n<<24);                     	
#define SET_HISTOGRAM_BOUNDARYF(n)	REG_ISP_HISTOGRAM_BOUNDARY_CTRL5 &= ~REG_HISTORGRAM_BOUNDARYF_MASK;\
												REG_ISP_HISTOGRAM_BOUNDARY_CTRL5 |= (n<<16);
#endif

/* macros of preprocessing control register 2 */
#define ENABLE_AE_AREA_ALL				REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_AREA_ALL_ENABLE_BIT;
#define DISABLE_AE_AREA_ALL			REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_AREA_ALL_ENABLE_BIT;
#define ENABLE_AE_COUNT					REG_ISP_PREPROCESS_CTRL2 |= ERG_PREPROCESS2_AE_COUNT_ENABLE_BIT;
#define DISABLE_AE_COUNT				REG_ISP_PREPROCESS_CTRL2 &= ~ERG_PREPROCESS2_AE_COUNT_ENABLE_BIT;
#define SET_AE_PID_POLARITY_HIGH		REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_PID_POLARITY_BIT;
#define SET_AE_PID_POLARITY_LOW		REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_PID_POLARITY_BIT;
#define SET_AE_GID_POLARITY_HIGH		REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_GID_POLARITY_BIT;
#define SET_AE_GID_POLARITY_LOW		REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_GID_POLARITY_BIT;
#define CLEAR_AE_COUNT					REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_COUNT_CLEAR_BIT;
#define SET_AE_GM_SEL(n)				REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_GM_SEL_MASK;\
												REG_ISP_PREPROCESS_CTRL2 |= (n<<17);
#define SET_AE_PATH_SEL_HIGH			REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_PATH_SEL_BIT;
#define SET_AE_PATH_SEL_LOW			REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_PATH_SEL_BIT;
#define ENABLE_ATF_EDGE					REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_ATF_EDGE_ENABLE_BIT;
#define DISABLE_ATF_EDGE				REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_ATF_EDGE_ENABLE_BIT;
#define ENABLE_ATF_AREA_ALL			REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_ATF_AREA_ALL_ENABLE_BIT;
#define DISABLE_ATF_AREA_ALL			REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_ATF_AREA_ALL_ENABLE_BIT;
#define ENABLE_AWB_AREA_ALL			REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AWB_AREA_ALL_ENABLE_BIT;
#define DISABLE_AWB_AREA_ALL			REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AWB_AREA_ALL_ENABLE_BIT;
#define ENABLE_AE_ONLY_G_COLOR		REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_AE_GREEN_ONLY_BIT;
#define DISABLE_AE_ONLY_G_COLOR		REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_AE_GREEN_ONLY_BIT;
#define ENABLE_HISTOGRAM_RLEN			REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_RLEN_BIT;
#define DISABLE_HISTOGRAM_RLEN		REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_RLEN_BIT;
#define ENABLE_INTER_TOP_MOD			REG_ISP_PREPROCESS_CTRL2 |= REG_PREPROCESS2_INTER_TOP_ENABLE_BIT;
#define DISABLE_INTER_TOP_MOD			REG_ISP_PREPROCESS_CTRL2 &= ~REG_PREPROCESS2_INTER_TOP_ENABLE_BIT;

/* macros of AE window register */
#define SET_AE_WINDOW(n, left, top, right, bottom)	\
{\
	volatile kal_uint32 *reg_addr;\
	\
	reg_addr=(volatile unsigned int *) (CAMERA_base+0x48+((n-1)<<2));\
	*reg_addr=((left<<24)|(top<<8)|(right<<16)|(bottom));\
}

#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES))
/* macros of AF window register */
#define SET_AF_WINDOW(n, left, top, right, bottom)	\
{\
	volatile kal_uint32 *reg_addr;\
	\
	reg_addr=(volatile unsigned int *) (CAMERA_base+0x58+((n-1)<<2));\
	*reg_addr=((left<<24)|(top<<8)|(right<<16)|(bottom));\
}
#else
/* macros of AF window register */
#define SET_AF_WINDOW(n, left, top, right, bottom)	\
{\
	volatile kal_uint32 *reg_addr;\
	\
	reg_addr=(volatile unsigned int *) (CAMERA_base+0x024C+((n-1)<<2));\
	*reg_addr=((left<<24)|(top<<8)|(right<<16)|(bottom));\
}
#endif

/* macros of AWB window register */
#define SET_AWB_WINDOW(left,top,right,bottom)	REG_ISP_AWB_WINDOW=((left<<24)|(top<<8)|(right<<16)|(bottom));

/* macros of color processing stage control register */
#define ENABLE_BYPASS_INTERPOLATION_MOD	REG_ISP_COLOR_PROCESS_STAGE_CTRL1 |= REG_CPS1_BYPASS_INTERPOLATION_BIT;
#define DISABLE_BYPASS_INTERPOLATION_MOD	REG_ISP_COLOR_PROCESS_STAGE_CTRL1 &= ~REG_CPS1_BYPASS_INTERPOLATION_BIT;
#define ENABLE_NON_LINEAR_MODE				REG_ISP_COLOR_PROCESS_STAGE_CTRL1 |= ERG_CPS1_NONLINEAR_MODE_ENABLE_BIT;
#define DISABLE_NON_LINEAR_MODE				REG_ISP_COLOR_PROCESS_STAGE_CTRL1 &= ~ERG_CPS1_NONLINEAR_MODE_ENABLE_BIT;
#define ENABLE_LINE_EDGE						REG_ISP_COLOR_PROCESS_STAGE_CTRL1 |= REG_CPS1_LINE_EDGE_ENABLE_BIT;
#define DISABLE_LINE_EDGE						REG_ISP_COLOR_PROCESS_STAGE_CTRL1 &= ~REG_CPS1_LINE_EDGE_ENABLE_BIT;
#define ENABLE_LINE_JUDGE						REG_ISP_COLOR_PROCESS_STAGE_CTRL1 |= REG_CPS1_LINE_JUDGE_ENABLE_BIT;
#define DISABLE_LINE_JUDGE						REG_ISP_COLOR_PROCESS_STAGE_CTRL1 &= ~REG_CPS1_LINE_JUDGE_ENABLE_BIT;

/* 	macros of interpolation register */
#define SET_INTERPOLATION_THRE_V(n)			REG_ISP_INTERPOLATION1 &= ~REG_INTERPOLATION1_THRESHOLD_V_MASK;\
														REG_ISP_INTERPOLATION1 |= (n<<24);
#define SET_INTERPOLATION_THRE_SM(n)		REG_ISP_INTERPOLATION1 &= ~REG_INTERPOLATION1_THRESHOLD_SM_MASK;\
														REG_ISP_INTERPOLATION1 |= (n<<16);
#define SET_INTERPOLATION_THRE_DHV(n)		REG_ISP_INTERPOLATION1 &= ~REG_INTERPOLATION1_THRESHOLD_DHV_MASK;\
														REG_ISP_INTERPOLATION1 |= (n<<8);
#define SET_INTERPOLATION_THRE_RT(n)		REG_ISP_INTERPOLATION1 &= ~REG_INTERPOLATION1_THRESHOLD_RT_MASK;\
														REG_ISP_INTERPOLATION1 |= n;
#define SET_INTERPOLATION_THRE_LEDGE(n)	REG_ISP_INTERPOLATION2 &= ~REG_INTERPOLATION2_THRESHOLD_LEDGE_MASK;\
														REG_ISP_INTERPOLATION2 |= n;

/* macros of Edge core register */
#define SET_EDGE_CORE_H(n)		REG_ISP_EDGE_CORE &= ~REG_EDGE_CORE_COREH_MASK;\
										REG_ISP_EDGE_CORE |= (n<<24);
#define ENABLE_EMBOSS1			REG_ISP_EDGE_CORE |= REG_EDGE_CORE_EMBOSS1_BIT;
#define DISABLE_EMBOSS1			REG_ISP_EDGE_CORE &= ~REG_EDGE_CORE_EMBOSS1_BIT;
#define ENABLE_EMBOSS2			REG_ISP_EDGE_CORE |= REG_EDGE_CORE_EMBOSS2_BIT;
#define DISABLE_EMBOSS2			REG_ISP_EDGE_CORE &= ~REG_EDGE_CORE_EMBOSS2_BIT;
#define SET_EDGE_CORE_H2(n)	REG_ISP_EDGE_CORE &= ~REG_EDGE_CORE_COREH2_MASK;\
										REG_ISP_EDGE_CORE |= (n<<16);
#define SET_EDGE_CORE_V(n)		REG_ISP_EDGE_CORE &= ~REG_EDGE_CORE_COREV_MASK;\
										REG_ISP_EDGE_CORE |= (n<<8);
#define SET_TOP_SLOPE_HIGH		REG_ISP_EDGE_CORE |= REG_EDGE_CORE_TOP_SLOPE_BIT;
#define SET_TOP_SLOPE_LOW		REG_ISP_EDGE_CORE &= ~REG_EDGE_CORE_TOP_SLOPE_BIT;
#define SET_EDGE_CORE_CON(n)	REG_ISP_EDGE_CORE &= ~REG_EDGE_CORE_CORE_CON_MASK;\
										REG_ISP_EDGE_CORE |= n;

/* macros of edge gain register 1*/
#define SET_EDGE_SPECI_GAIN(n)	REG_ISP_EDGE_GAIN1 &= ~REG_EDGE_GAIN1_SPECIGAIN_MASK;\
											REG_ISP_EDGE_GAIN1 |= (n<<30);
#define SET_EDGE_SPECI_PONLY(n)	REG_ISP_EDGE_GAIN1 &= ~REG_EDGE_GAIN1_SPECIPONLY_MASK;\
											REG_ISP_EDGE_GAIN1 |= (n<<28);
#define SET_EDGE_GAIN_H(n)			REG_ISP_EDGE_GAIN1 &= ~REG_EDGE_GAIN1_EGAIN_H_MASK;\
											REG_ISP_EDGE_GAIN1 |= (n<<24);
#define SET_EDGE_GAIN_H2(n)		REG_ISP_EDGE_GAIN1 &= ~REG_EDGE_GAIN1_EGAIN_H2_MASK;\
											REG_ISP_EDGE_GAIN1 |= (n<<16);
#define SET_EDGE_GAIN_VB(n)		REG_ISP_EDGE_GAIN1 &= ~REG_EDGE_GAIN1_EGAIN_VB_MASK;\
											REG_ISP_EDGE_GAIN1 |= (n<<8);
#define ENABLE_EDGE_EFFECT_OIL	REG_ISP_EDGE_GAIN1 |= REG_EDGE_GAIN1_OILEN_BIT;
#define DISABLE_EDGE_EFFECT_OIL	REG_ISP_EDGE_GAIN1 &= ~REG_EDGE_GAIN1_OILEN_BIT;
#define SET_EDGE_GAIN_KNEESEL(n)	REG_ISP_EDGE_GAIN1 &= ~REG_EDGE_GAIN1_KNEESEL_MASK;\
											REG_ISP_EDGE_GAIN1 |= (n<<4);
#define SET_EDGE_GAIN_LINE(n)		REG_ISP_EDGE_GAIN1 &= ~REG_EDGE_GAIN1_EGAINLINE_MASK;\
											REG_ISP_EDGE_GAIN1 |= n;

/* macros of edge gain register 2 */
#define ENABLE_EDGE_GAIN_SPECIABS		REG_ISP_EDGE_GAIN2 |= REG_EDGE_GAIN2_SPECIABS_BIT;
#define DISABLE_EDGE_GAIN_SPECIABS		REG_ISP_EDGE_GAIN2 &= ~REG_EDGE_GAIN2_SPECIABS_BIT;
#define ENABLE_EDGE_GAIN_SPECIINV		REG_ISP_EDGE_GAIN2 |= REG_EDGE_GAIN2_SPECIINV_BIT;
#define DISABLE_EDGE_GAIN_SPECIINV		REG_ISP_EDGE_GAIN2 &= ~REG_EDGE_GAIN2_SPECIINV_BIT;
#define SET_EDGE_GAIN_HC(n)				REG_ISP_EDGE_GAIN2 &= ~REG_EDGE_GAIN2_EGAIN_HC_MASK;\
													REG_ISP_EDGE_GAIN2 |= n;
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define SET_EDGE_GAIN_VC(n)				REG_ISP_EDGE_GAIN2 &= ~REG_EDGE_GAIN2_EGAIN_VC_MASK;\
													REG_ISP_EDGE_GAIN2 |= (n<<16);
#define SET_EDGE_GAIN_VA(n)				REG_ISP_EDGE_GAIN2 &= ~REG_EDGE_GAIN2_EGAIN_VA_MASK;\
													REG_ISP_EDGE_GAIN2 |= (n<<24);
#endif

/* macros of Edge threshold register */
#define SET_EDGE_THRESHOLD_ETH3(n)				REG_ISP_EDGE_THRESHOLD &= ~REG_EDGE_THRESHOLD_ETH3_MASK;\
															REG_ISP_EDGE_THRESHOLD |= (n<<24);
#define SET_EDGE_THRESHOLD_ETH_CON(n)			REG_ISP_EDGE_THRESHOLD &= ~REG_EDGE_THRESHOLD_ETH_CON_MASK;\
															REG_ISP_EDGE_THRESHOLD |= (n<<16);
#define SET_EDGE_THRESHOLD_ONLYC_HIGH			REG_ISP_EDGE_THRESHOLD |= REG_EDGE_THRESHOLD_ONLYC_BIT;
#define SET_EDGE_THRESHOLD_ONLYC_LOW			REG_ISP_EDGE_THRESHOLD &= ~REG_EDGE_THRESHOLD_ONLYC_BIT;
#define SET_EDGE_THRESHOLD_THRE_EDGE_SUP(n)	REG_ISP_EDGE_THRESHOLD &= ~REG_EDGE_THRESHOLD_THRE_EDGE_SUP_MASK;\
															REG_ISP_EDGE_THRESHOLD |= (n<<8);
#define SET_EDGE_THRESHOLD_THRL_EDGE_SUP(n)	REG_ISP_EDGE_THRESHOLD &= ~REG_EDGE_THRESHOLD_THRL_EDGE_SUP_MASK;\
															REG_ISP_EDGE_THRESHOLD |= n;

/* macros of Edge vertical control register */
#define ENABLE_EDGE_V_CTRL_HP			REG_ISP_EDGE_VERTICAL_CTRL |= REG_EDGE_VERTICAL_HPEN_BIT;
#define DISABLE_EDGE_V_CTRL_HP		REG_ISP_EDGE_VERTICAL_CTRL &= ~REG_EDGE_VERTICAL_HPEN_BIT;
#define SET_EDGE_V_CTRL_E_TH1_V(n)	REG_ISP_EDGE_VERTICAL_CTRL &= ~REG_EDGE_VERTICAL_E_TH1_V_MASK;\
												REG_ISP_EDGE_VERTICAL_CTRL |= (n<<24);
#define SET_EDGE_V_CTRL_HALF_V(n)	REG_ISP_EDGE_VERTICAL_CTRL &= ~REG_EDGE_VERTICAL_HALF_V_MASK;\
												REG_ISP_EDGE_VERTICAL_CTRL |= (n<<16);
#define SET_EDGE_V_CTRL_SUP_V(n)		REG_ISP_EDGE_VERTICAL_CTRL &= ~REG_EDGE_VERTICAL_SUP_V_MASK;\
												REG_ISP_EDGE_VERTICAL_CTRL |= (n<<10);
#define SET_EDGE_V_CTRL_SDN_V(n)		REG_ISP_EDGE_VERTICAL_CTRL &= ~REG_EDGE_VERTICAL_SDN_V_MASK;\
												REG_ISP_EDGE_VERTICAL_CTRL |= (n<<8);
#define SET_EDGE_V_CTRL_E_TH3_V(n)	REG_ISP_EDGE_VERTICAL_CTRL &= ~REG_EDGE_VERTICAL_E_TH3_V_MASK;\
												REG_ISP_EDGE_VERTICAL_CTRL |= n;

/* macros of Axis RGB gain register */
#define SET_AXIS_R_GAIN(n)		REG_ISP_AXIS_RGB_GAIN &= ~REG_AXIS_RGB_GAIN_R_GAIN_MASK;\
										REG_ISP_AXIS_RGB_GAIN |= (n<<16);
#define SET_AXIS_G_GAIN(n)		REG_ISP_AXIS_RGB_GAIN &= ~REG_AXIS_RGB_GAIN_G_GAIN_MASK;\
										REG_ISP_AXIS_RGB_GAIN |= (n<<8);
#define SET_AXIS_B_GAIN(n)		REG_ISP_AXIS_RGB_GAIN &= ~REG_AXIS_RGB_GAIN_B_GAIN_MASK;\
										REG_ISP_AXIS_RGB_GAIN |= n;

/* macros of OPD configuration register */
#define ENABLE_OPD_COUNTER			REG_ISP_OPD_CONFIG |= REG_OPD_CONFIG_OPD_ENABLE_BIT;
#define DISABLE_OPD_COUNTER		REG_ISP_OPD_CONFIG &= ~REG_OPD_CONFIG_OPD_ENABLE_BIT;
#define CLEAR_OPD_COUNTER			REG_ISP_OPD_CONFIG |= REG_OPD_CONFIG_OPD_CLEAR_BIT;
#define SEL_COLOR_SUP_MODE(n)		REG_ISP_OPD_CONFIG &= ~REG_OPD_CONFIG_COLOR_SUP_SEL_MASK;\
											REG_ISP_OPD_CONFIG |=(n<<24);
#define SET_OPD_MOD_U_GAIN(n)		REG_ISP_OPD_CONFIG &= ~REG_OPD_CONFIG_U_GAIN_MASK;\
											REG_ISP_OPD_CONFIG |= (n<<16);
#define SET_OPD_MOD_V_GAIN(n)		REG_ISP_OPD_CONFIG &= ~REG_OPD_CONFIG_V_GAIN_MASK;\
											REG_ISP_OPD_CONFIG |= (n<<8);
#define SET_OPD_MOD_Y_LIMIT(n)	REG_ISP_OPD_CONFIG &= ~REG_OPD_CONFIG_Y_LIMIT_MASK;\
											REG_ISP_OPD_CONFIG |= n;

/* macros of OPD component parameter register */
#define SET_OPD_PARA_S_RB_P(n)	REG_ISP_OPD_COMP_PARAMETER &= ~REG_OPD_CONFIG_PARA_S_RB_P_MASK;\
											REG_ISP_OPD_COMP_PARAMETER |= (n<<24);
#define SET_OPD_PARA_S_RB_N(n)	REG_ISP_OPD_COMP_PARAMETER &= ~REG_OPD_CONFIG_PARA_S_RB_N_MASK;\
											REG_ISP_OPD_COMP_PARAMETER |= (n<<16);
#define SET_OPD_PARA_S_MG_P(n)	REG_ISP_OPD_COMP_PARAMETER &= ~REG_OPD_CONFIG_PARA_S_MG_P_MASK;\
											REG_ISP_OPD_COMP_PARAMETER |= (n<<8);
#define SET_OPD_PARA_S_MG_N(n)	REG_ISP_OPD_COMP_PARAMETER &= ~REG_OPD_CONFIG_PARA_S_MG_N_MASK;\
											REG_ISP_OPD_COMP_PARAMETER |= n;

/* macros of color matrix register */
#define SET_COLOR_MATRIX1(m11,m12,m13)	REG_ISP_COLOR_MATRIX1 =0;\
													REG_ISP_COLOR_MATRIX1 = (m11<<16)|(m12<<8)|m13;
#define SET_COLOR_MATRIX2(m11,m12,m13)	REG_ISP_COLOR_MATRIX2 =0;\
													REG_ISP_COLOR_MATRIX2 = (m11<<16)|(m12<<8)|m13;
#define SET_COLOR_MATRIX3(m11,m12,m13)	REG_ISP_COLOR_MATRIX3 =0;\
													REG_ISP_COLOR_MATRIX3 = (m11<<16)|(m12<<8)|m13;

/* macros of color matrix RGB gain register */
#define SET_COLOR_MATRIX_R_GAIN(n)	REG_ISP_COLOR_MATRIX_RGB_GAIN &= ~REG_COLOR_MATRIX_R_GAIN_MASK;\
												REG_ISP_COLOR_MATRIX_RGB_GAIN |= (n<<16);
#define SET_COLOR_MATRIX_G_GAIN(n)	REG_ISP_COLOR_MATRIX_RGB_GAIN &= ~REG_COLOR_MATRIX_G_GAIN_MASK;\
												REG_ISP_COLOR_MATRIX_RGB_GAIN |= (n<<8);
#define SET_COLOR_MATRIX_B_GAIN(n)	REG_ISP_COLOR_MATRIX_RGB_GAIN &= ~REG_COLOR_MATRIX_B_GAIN_MASK;\
												REG_ISP_COLOR_MATRIX_RGB_GAIN |= n;

/* macros of color process stage control register 2 */
#define ENABLE_GAMMA_FUNCTION_BYPASS		REG_ISP_COLOR_PROCESS_STAGE_CTRL2 |= REG_CPS2_BYPASS_GAMMA_BIT;
#define DISABLE_GAMMA_FUNCTION_BYPASS		REG_ISP_COLOR_PROCESS_STAGE_CTRL2 &= ~REG_CPS2_BYPASS_GAMMA_BIT;
#define ENABLE_RGB_EDGE_GAIN					REG_ISP_COLOR_PROCESS_STAGE_CTRL2 |= REG_CPS2_RGB_EDGE_ENABLE_BIT;
#define DISABLE_RGB_EDGE_GAIN					REG_ISP_COLOR_PROCESS_STAGE_CTRL2 &= ~REG_CPS2_RGB_EDGE_ENABLE_BIT;
#define ENABLE_Y_EDGE							REG_ISP_COLOR_PROCESS_STAGE_CTRL2 |= REG_CPS2_Y_EDGE_ENABLE_BIT;
#define DISABLE_Y_EDGE							REG_ISP_COLOR_PROCESS_STAGE_CTRL2 &= ~REG_CPS2_Y_EDGE_ENABLE_BIT;
#define ENABLE_OPD_GAMMA_OUT_INVERSION		REG_ISP_COLOR_PROCESS_STAGE_CTRL2 |= REG_CPS2_OPDGB_IVT_BIT;
#define DISABLE_OPD_GAMMA_OUT_INVERSION	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 &= ~REG_CPS2_OPDGB_IVT_BIT;
#define SET_Y_EDGE_GAIN(n)						REG_ISP_COLOR_PROCESS_STAGE_CTRL2 &= ~REG_CPS2_Y_EDGE_GAIN_MASK;\
														REG_ISP_COLOR_PROCESS_STAGE_CTRL2 |=(n);

/* macros of AWB RGB gain register */
#define SET_AWB_R_GAIN(n)	REG_ISP_AWB_GAIN &= ~REG_AWB_RGB_GAIN_R_GAIN_MASK;\
									REG_ISP_AWB_GAIN |= (n<<16);
#define SET_AWB_G_GAIN(n)	REG_ISP_AWB_GAIN &= ~REG_AWB_RGB_GAIN_G_GAIN_MASK;\
									REG_ISP_AWB_GAIN |= (n<<8);
#define SET_AWB_B_GAIN(n)	REG_ISP_AWB_GAIN &= ~REG_AWB_RGB_GAIN_B_GAIN_MASK;\
									REG_ISP_AWB_GAIN |= n;

/* macros of Gamma RGB Flare register */
#define SET_GAMMA_RGB_FLARE_SIGN_R_HIGH	REG_ISP_GAMMA_RGB_FLARE |= REG_GAMMA_RGB_FLARE_SIGN_R_BIT;
#define SET_GAMMA_RGB_FLARE_SIGN_R_LOW		REG_ISP_GAMMA_RGB_FLARE &= ~REG_GAMMA_RGB_FLARE_SIGN_R_BIT;
#define SET_GAMMA_RGB_FLARE_R(n)				REG_ISP_GAMMA_RGB_FLARE &= ~REG_GAMMA_RGB_FLARE_FLARE_R_MASK;\
														REG_ISP_GAMMA_RGB_FLARE |= (n<<16);
#define SET_GAMMA_RGB_FLARE_SIGN_G_HIGH	REG_ISP_GAMMA_RGB_FLARE |= REG_GAMMA_RGB_FLARE_SIGN_G_BIT;
#define SET_GAMMA_RGB_FLARE_SIGN_G_LOW		REG_ISP_GAMMA_RGB_FLARE &= ~REG_GAMMA_RGB_FLARE_SIGN_G_BIT;
#define SET_GAMMA_RGB_FLARE_G(n)				REG_ISP_GAMMA_RGB_FLARE &= ~REG_GAMMA_RGB_FLARE_FLARE_G_MASK;\
														REG_ISP_GAMMA_RGB_FLARE |= (n<<8);
#define SET_GAMMA_RGB_FLARE_SIGN_B_HIGH	REG_ISP_GAMMA_RGB_FLARE |= REG_GAMMA_RGB_FLARE_SIGN_B_BIT;
#define SET_GAMMA_RGB_FLARE_SIGN_B_LOW		REG_ISP_GAMMA_RGB_FLARE &= ~REG_GAMMA_RGB_FLARE_SIGN_B_BIT;
#define SET_GAMMA_RGB_FLARE_B(n)				REG_ISP_GAMMA_RGB_FLARE &= ~REG_GAMMA_RGB_FLARE_FLARE_B_MASK;\
														REG_ISP_GAMMA_RGB_FLARE |= n;

/* macros of Y channel configuration register */
#define SET_Y_CONTRAST_GAIN(n)	REG_ISP_Y_CH_CONFIG &= ~REG_Y_CH_CONFIG_CONTRAST_GAIN_MASK;\
											REG_ISP_Y_CH_CONFIG |= (n<<16);
#define SET_Y_BRIGHT_POS_SIGN		REG_ISP_Y_CH_CONFIG &= ~REG_Y_CH_ONFIG_BRIGHT_SIGN_BIT;
#define SET_Y_BRIGHT_NEG_SIGN		REG_ISP_Y_CH_CONFIG |= REG_Y_CH_ONFIG_BRIGHT_SIGN_BIT;
#define SET_Y_BRIGHT_OFFSET(n)	REG_ISP_Y_CH_CONFIG &= ~REG_Y_CH_CONFIG_BRIGHT_OFFSET_MASK;\
											REG_ISP_Y_CH_CONFIG |= (n<<8);
#define SET_Y_CSUP_EDGE_GAIN(n)	REG_ISP_Y_CH_CONFIG &= ~REG_Y_CH_CONFIG_CSUP_EDGE_GAIN_MASK;\
											REG_ISP_Y_CH_CONFIG |= n;
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ENABLE_VSUP					REG_ISP_Y_CH_CONFIG |= REG_VSUP_ENABLE_MASK;	
#define DISABLE_VSUP					REG_ISP_Y_CH_CONFIG &= ~REG_VSUP_ENABLE_MASK;	
#define ENABLE_UV_LOW_PASS			REG_ISP_Y_CH_CONFIG |= REG_UV_CH_LOW_PASS_ENABLE_MASK;	
#define DISABLE_UV_LOW_PASS		REG_ISP_Y_CH_CONFIG &= ~REG_UV_CH_LOW_PASS_ENABLE_MASK;	
#endif

/* macros of UV channel configuration register */
#define SET_HUE_U_GAIN(n)		REG_ISP_UV_CH_CONFIG &= ~REG_UV_CH_CONFIG_U11_MASK;\
										REG_ISP_UV_CH_CONFIG |= (n<<24);
#define SET_HUE_V_GAIN(n)		REG_ISP_UV_CH_CONFIG &= ~REG_UV_CH_CONFIG_V11_MASK;\
										REG_ISP_UV_CH_CONFIG |= (n<<16);
#define SET_HUE_U_OFFSET(n)	REG_ISP_UV_CH_CONFIG &= ~REG_UV_CH_CONFIG_U_OFFSET_MASK;\
										REG_ISP_UV_CH_CONFIG |= (n<<8);
#define SET_HUE_V_OFFSET(n)	REG_ISP_UV_CH_CONFIG &= ~REG_UV_CH_CONFIG_V_OFFSET_MASK;\
										REG_ISP_UV_CH_CONFIG |= n;

/* macros of space convert YUV register */
#define SET_YUV2YCBCR_Y_GAIN(n)		REG_ISP_SPACE_CONVERT_YUV1 &= ~REG_SPACE_CVT_YUV_Y_GAIN_MASK;\
												REG_ISP_SPACE_CONVERT_YUV1 |= (n<<16);
#define SET_YUV2YCBCR_U_GAIN(n)		REG_ISP_SPACE_CONVERT_YUV1 &= ~REG_SPACE_CVT_YUV_U_GAIN_MASK;\
												REG_ISP_SPACE_CONVERT_YUV1 |= (n<<8);
#define SET_YUV2YCBCR_V_GAIN(n)		REG_ISP_SPACE_CONVERT_YUV1 &= ~REG_SPACE_CVT_YUV_V_GAIN_MASK;\
												REG_ISP_SPACE_CONVERT_YUV1 |= n;
#define SET_YUV2YCBCR_Y_OFFSET(n)	REG_ISP_SPACE_CONVERT_YUV2 &= ~REG_SPACE_CVT_YUV_Y_OFFSET_MASK;\
												REG_ISP_SPACE_CONVERT_YUV2 |= (n<<16);
#define SET_YUV2YCBCR_U_OFFSET(n)	REG_ISP_SPACE_CONVERT_YUV2 &= ~REG_SPACE_CVT_YUV_U_OFFSET_MASK;\
												REG_ISP_SPACE_CONVERT_YUV2 |= (n<<8);
#define SET_YUV2YCBCR_V_OFFSET(n)	REG_ISP_SPACE_CONVERT_YUV2 &= ~REG_SPACE_CVT_YUV_V_OFFSET_MASK;\
												REG_ISP_SPACE_CONVERT_YUV2 |= n;

/* macros of Gamma operation register */
#define SET_GAMMA_B1(n)		REG_ISP_GAMMA_OPERATION1 &= ~REG_GAMMA_OPERATION_GAMMA_B1_MASK;\
									REG_ISP_GAMMA_OPERATION1 |= (n<<24);
#define SET_GAMMA_B2(n)		REG_ISP_GAMMA_OPERATION1 &= ~REG_GAMMA_OPERATION_GAMMA_B2_MASK;\
									REG_ISP_GAMMA_OPERATION1 |= (n<<16);
#define SET_GAMMA_B3(n)		REG_ISP_GAMMA_OPERATION1 &= ~REG_GAMMA_OPERATION_GAMMA_B3_MASK;\
									REG_ISP_GAMMA_OPERATION1 |= (n<<8);
#define SET_GAMMA_B4(n)		REG_ISP_GAMMA_OPERATION1 &= ~REG_GAMMA_OPERATION_GAMMA_B4_MASK;\
									REG_ISP_GAMMA_OPERATION1 |= n;
#define SET_GAMMA_B5(n)		REG_ISP_GAMMA_OPERATION2 &= ~REG_GAMMA_OPERATION_GAMMA_B5_MASK;\
									REG_ISP_GAMMA_OPERATION2 |= (n<<24);
#define SET_GAMMA_B6(n)		REG_ISP_GAMMA_OPERATION2 &= ~REG_GAMMA_OPERATION_GAMMA_B6_MASK;\
									REG_ISP_GAMMA_OPERATION2 |= (n<<16);
#define SET_GAMMA_B7(n)		REG_ISP_GAMMA_OPERATION2 &= ~REG_GAMMA_OPERATION_GAMMA_B7_MASK;\
									REG_ISP_GAMMA_OPERATION2 |= (n<<8);
#define SET_GAMMA_B8(n)		REG_ISP_GAMMA_OPERATION2 &= ~REG_GAMMA_OPERATION_GAMMA_B8_MASK;\
									REG_ISP_GAMMA_OPERATION2 |= n;
#define SET_GAMMA_B9(n)		REG_ISP_GAMMA_OPERATION3 &= ~REG_GAMMA_OPERATION_GAMMA_B9_MASK;\
									REG_ISP_GAMMA_OPERATION3 |= (n<<24);
#define SET_GAMMA_B10(n)	REG_ISP_GAMMA_OPERATION3 &= ~REG_GAMMA_OPERATION_GAMMA_B10_MASK;\
									REG_ISP_GAMMA_OPERATION3 |= (n<<16);
#define SET_GAMMA_B11(n)	REG_ISP_GAMMA_OPERATION3 &= ~REG_GAMMA_OPERATION_GAMMA_B11_MASK;\
									REG_ISP_GAMMA_OPERATION3 |= (n<<8);
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
/* macros of 1024 Gamma table register */
#define ENABLE_1024_GAMMA_TABLE	REG_ISP_GAMMA_OPERATION3 |= REG_GAMMA_OPERATION_1024_ENABLE_BIT;
#define DISABLE_1024_GAMMA_TABLE	REG_ISP_GAMMA_OPERATION3 &= ~REG_GAMMA_OPERATION_1024_ENABLE_BIT;
#define INTMEM_GAMMA_1024(n)	*((volatile unsigned int *) (CAMERA_base+ n*4 + 0x1000))
#endif

/* macros of Sensor Gamma R register */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ENABLE_SENSOR_GAMMA			REG_ISP_SNR_GAMMA_R0 |= REG_SENSOR_GAMMA_ENABLE_MASK;
#define DISABLE_SENSOR_GAMMA			REG_ISP_SNR_GAMMA_R0 &= ~REG_SENSOR_GAMMA_ENABLE_MASK;
#define ENABLE_SENSOR_GAMMA_IVT		REG_ISP_SNR_GAMMA_R0 |= REG_SENSOR_GAMMA_IVT_MASK;
#define DISABLE_SENSOR_GAMMA_IVT		REG_ISP_SNR_GAMMA_R0 &= ~REG_SENSOR_GAMMA_IVT_MASK;

#define SET_SENSOR_GAMMA_R_B1(n)		REG_ISP_SNR_GAMMA_R0 &= ~REG_SENSOR_GAMMA_R_B1_MASK;\
												REG_ISP_SNR_GAMMA_R0 |= (n<<16);
#define SET_SENSOR_GAMMA_R_B2(n)		REG_ISP_SNR_GAMMA_R0 &= ~REG_SENSOR_GAMMA_R_B2_MASK;\
												REG_ISP_SNR_GAMMA_R0 |= (n<<8);
#define SET_SENSOR_GAMMA_R_B3(n)		REG_ISP_SNR_GAMMA_R0 &= ~REG_SENSOR_GAMMA_R_B3_MASK;\
												REG_ISP_SNR_GAMMA_R0 |= n;
#define SET_SENSOR_GAMMA_R_B4(n)		REG_ISP_SNR_GAMMA_R1 &= ~REG_SENSOR_GAMMA_R_B4_MASK;\
												REG_ISP_SNR_GAMMA_R1 |= (n<<24);
#define SET_SENSOR_GAMMA_R_B5(n)		REG_ISP_SNR_GAMMA_R1 &= ~REG_SENSOR_GAMMA_R_B5_MASK;\
												REG_ISP_SNR_GAMMA_R1 |= (n<<16);
#define SET_SENSOR_GAMMA_R_B6(n)		REG_ISP_SNR_GAMMA_R1 &= ~REG_SENSOR_GAMMA_R_B6_MASK;\
												REG_ISP_SNR_GAMMA_R1 |= (n<<8);
#define SET_SENSOR_GAMMA_R_B7(n)		REG_ISP_SNR_GAMMA_R1 &= ~REG_SENSOR_GAMMA_R_B7_MASK;\
												REG_ISP_SNR_GAMMA_R1 |= n;
#define SET_SENSOR_GAMMA_R_B8(n)		REG_ISP_SNR_GAMMA_R2 &= ~REG_SENSOR_GAMMA_R_B8_MASK;\
												REG_ISP_SNR_GAMMA_R2 |= (n<<24);
#define SET_SENSOR_GAMMA_R_B9(n)		REG_ISP_SNR_GAMMA_R2 &= ~REG_SENSOR_GAMMA_R_B9_MASK;\
												REG_ISP_SNR_GAMMA_R2 |= (n<<16);
#define SET_SENSOR_GAMMA_R_B10(n)	REG_ISP_SNR_GAMMA_R2 &= ~REG_SENSOR_GAMMA_R_B10_MASK;\
												REG_ISP_SNR_GAMMA_R2 |= (n<<8);
#define SET_SENSOR_GAMMA_R_B11(n)	REG_ISP_SNR_GAMMA_R2 &= ~REG_SENSOR_GAMMA_R_B11_MASK;\
												REG_ISP_SNR_GAMMA_R2 |= n;

/* macros of Sensor Gamma G register */	//MT6228 New
#if(!(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES)))
#define SET_SENSOR_GAMMA_G_B1(n)		REG_ISP_SNR_GAMMA_G0 &= ~REG_SENSOR_GAMMA_G_B1_MASK;\
												REG_ISP_SNR_GAMMA_G0 |= (n<<24);  
#define SET_SENSOR_GAMMA_G_B2(n)		REG_ISP_SNR_GAMMA_G0 &= ~REG_SENSOR_GAMMA_G_B2_MASK;\
												REG_ISP_SNR_GAMMA_G0 |= (n<<16);  
#define SET_SENSOR_GAMMA_G_B3(n)		REG_ISP_SNR_GAMMA_G0 &= ~REG_SENSOR_GAMMA_G_B3_MASK;\
												REG_ISP_SNR_GAMMA_G0 |= (n<<8);  
#define SET_SENSOR_GAMMA_G_B4(n)		REG_ISP_SNR_GAMMA_G0 &= ~REG_SENSOR_GAMMA_G_B4_MASK;\
												REG_ISP_SNR_GAMMA_G0 |= n;  
#define SET_SENSOR_GAMMA_G_B5(n)		REG_ISP_SNR_GAMMA_G1 &= ~REG_SENSOR_GAMMA_G_B5_MASK;\
												REG_ISP_SNR_GAMMA_G1 |= (n<<24);  
#define SET_SENSOR_GAMMA_G_B6(n)		REG_ISP_SNR_GAMMA_G1 &= ~REG_SENSOR_GAMMA_G_B6_MASK;\
												REG_ISP_SNR_GAMMA_G1 |= (n<<16);  
#define SET_SENSOR_GAMMA_G_B7(n)		REG_ISP_SNR_GAMMA_G1 &= ~REG_SENSOR_GAMMA_G_B7_MASK;\
												REG_ISP_SNR_GAMMA_G1 |= (n<<8);  
#define SET_SENSOR_GAMMA_G_B8(n)		REG_ISP_SNR_GAMMA_G1 &= ~REG_SENSOR_GAMMA_G_B8_MASK;\
												REG_ISP_SNR_GAMMA_G1 |= n;  
#define SET_SENSOR_GAMMA_G_B9(n)		REG_ISP_SNR_GAMMA_G2 &= ~REG_SENSOR_GAMMA_G_B9_MASK;\
												REG_ISP_SNR_GAMMA_G2 |= (n<<24);  
#define SET_SENSOR_GAMMA_G_B10(n)	REG_ISP_SNR_GAMMA_G2 &= ~REG_SENSOR_GAMMA_G_B10_MASK;\
												REG_ISP_SNR_GAMMA_G2 |= (n<<16);  
#define SET_SENSOR_GAMMA_G_B11(n)	REG_ISP_SNR_GAMMA_G2 &= ~REG_SENSOR_GAMMA_G_B11_MASK;\
												REG_ISP_SNR_GAMMA_G2 |= (n<<8);  
#endif
#if(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#define SET_SENSOR_GAMMA_GR_B1(n)		REG_ISP_SNR_GAMMA_GR0 &= ~REG_SENSOR_GAMMA_GR_B1_MASK;\
												REG_ISP_SNR_GAMMA_GR0 |= (n<<24);  
#define SET_SENSOR_GAMMA_GR_B2(n)		REG_ISP_SNR_GAMMA_GR0 &= ~REG_SENSOR_GAMMA_GR_B2_MASK;\
												REG_ISP_SNR_GAMMA_GR0 |= (n<<16);  
#define SET_SENSOR_GAMMA_GR_B3(n)		REG_ISP_SNR_GAMMA_GR0 &= ~REG_SENSOR_GAMMA_GR_B3_MASK;\
												REG_ISP_SNR_GAMMA_GR0 |= (n<<8);  
#define SET_SENSOR_GAMMA_GR_B4(n)		REG_ISP_SNR_GAMMA_GR0 &= ~REG_SENSOR_GAMMA_GR_B4_MASK;\
												REG_ISP_SNR_GAMMA_GR0 |= n;  
#define SET_SENSOR_GAMMA_GR_B5(n)		REG_ISP_SNR_GAMMA_GR1 &= ~REG_SENSOR_GAMMA_GR_B5_MASK;\
												REG_ISP_SNR_GAMMA_GR1 |= (n<<24);  
#define SET_SENSOR_GAMMA_GR_B6(n)		REG_ISP_SNR_GAMMA_GR1 &= ~REG_SENSOR_GAMMA_GR_B6_MASK;\
												REG_ISP_SNR_GAMMA_GR1 |= (n<<16);  
#define SET_SENSOR_GAMMA_GR_B7(n)		REG_ISP_SNR_GAMMA_GR1 &= ~REG_SENSOR_GAMMA_GR_B7_MASK;\
												REG_ISP_SNR_GAMMA_GR1 |= (n<<8);  
#define SET_SENSOR_GAMMA_GR_B8(n)		REG_ISP_SNR_GAMMA_GR1 &= ~REG_SENSOR_GAMMA_GR_B8_MASK;\
												REG_ISP_SNR_GAMMA_GR1 |= n;  
#define SET_SENSOR_GAMMA_GR_B9(n)		REG_ISP_SNR_GAMMA_GR2 &= ~REG_SENSOR_GAMMA_GR_B9_MASK;\
												REG_ISP_SNR_GAMMA_GR2 |= (n<<24);  
#define SET_SENSOR_GAMMA_GR_B10(n)	REG_ISP_SNR_GAMMA_GR2 &= ~REG_SENSOR_GAMMA_GR_B10_MASK;\
												REG_ISP_SNR_GAMMA_GR2 |= (n<<16);  
#define SET_SENSOR_GAMMA_GR_B11(n)	REG_ISP_SNR_GAMMA_GR2 &= ~REG_SENSOR_GAMMA_GR_B11_MASK;\
												REG_ISP_SNR_GAMMA_GR2 |= (n<<8);  

#define SET_SENSOR_GAMMA_GB_B1(n)		REG_ISP_SNR_GAMMA_GB0 &= ~REG_SENSOR_GAMMA_GB_B1_MASK;\
												REG_ISP_SNR_GAMMA_GB0 |= (n<<24);  
#define SET_SENSOR_GAMMA_GB_B2(n)		REG_ISP_SNR_GAMMA_GB0 &= ~REG_SENSOR_GAMMA_GB_B2_MASK;\
												REG_ISP_SNR_GAMMA_GB0 |= (n<<16);  
#define SET_SENSOR_GAMMA_GB_B3(n)		REG_ISP_SNR_GAMMA_GB0 &= ~REG_SENSOR_GAMMA_GB_B3_MASK;\
												REG_ISP_SNR_GAMMA_GB0 |= (n<<8);  
#define SET_SENSOR_GAMMA_GB_B4(n)		REG_ISP_SNR_GAMMA_GB0 &= ~REG_SENSOR_GAMMA_GB_B4_MASK;\
												REG_ISP_SNR_GAMMA_GB0 |= n;  
#define SET_SENSOR_GAMMA_GB_B5(n)		REG_ISP_SNR_GAMMA_GB1 &= ~REG_SENSOR_GAMMA_GB_B5_MASK;\
												REG_ISP_SNR_GAMMA_GB1 |= (n<<24);  
#define SET_SENSOR_GAMMA_GB_B6(n)		REG_ISP_SNR_GAMMA_GB1 &= ~REG_SENSOR_GAMMA_GB_B6_MASK;\
												REG_ISP_SNR_GAMMA_GB1 |= (n<<16);  
#define SET_SENSOR_GAMMA_GB_B7(n)		REG_ISP_SNR_GAMMA_GB1 &= ~REG_SENSOR_GAMMA_GB_B7_MASK;\
												REG_ISP_SNR_GAMMA_GB1 |= (n<<8);  
#define SET_SENSOR_GAMMA_GB_B8(n)		REG_ISP_SNR_GAMMA_GB1 &= ~REG_SENSOR_GAMMA_GB_B8_MASK;\
												REG_ISP_SNR_GAMMA_GB1 |= n;  
#define SET_SENSOR_GAMMA_GB_B9(n)		REG_ISP_SNR_GAMMA_GB2 &= ~REG_SENSOR_GAMMA_GB_B9_MASK;\
												REG_ISP_SNR_GAMMA_GB2 |= (n<<24);  
#define SET_SENSOR_GAMMA_GB_B10(n)	REG_ISP_SNR_GAMMA_GB2 &= ~REG_SENSOR_GAMMA_GB_B10_MASK;\
												REG_ISP_SNR_GAMMA_GB2 |= (n<<16);  
#define SET_SENSOR_GAMMA_GB_B11(n)	REG_ISP_SNR_GAMMA_GB2 &= ~REG_SENSOR_GAMMA_GB_B11_MASK;\
												REG_ISP_SNR_GAMMA_GB2 |= (n<<8);  
#endif



/* macros of Sensor Gamma B register */	//MT6228 New
#define SET_SENSOR_GAMMA_B_B1(n)		REG_ISP_SNR_GAMMA_B0 &= ~REG_SENSOR_GAMMA_B_B1_MASK;\
												REG_ISP_SNR_GAMMA_B0 |= (n<<24);   
#define SET_SENSOR_GAMMA_B_B2(n)		REG_ISP_SNR_GAMMA_B0 &= ~REG_SENSOR_GAMMA_B_B2_MASK;\
												REG_ISP_SNR_GAMMA_B0 |= (n<<16);   
#define SET_SENSOR_GAMMA_B_B3(n)		REG_ISP_SNR_GAMMA_B0 &= ~REG_SENSOR_GAMMA_B_B3_MASK;\
												REG_ISP_SNR_GAMMA_B0 |= (n<<8);   
#define SET_SENSOR_GAMMA_B_B4(n)		REG_ISP_SNR_GAMMA_B0 &= ~REG_SENSOR_GAMMA_B_B4_MASK;\
												REG_ISP_SNR_GAMMA_B0 |= n;   
#define SET_SENSOR_GAMMA_B_B5(n)		REG_ISP_SNR_GAMMA_B1 &= ~REG_SENSOR_GAMMA_B_B5_MASK;\
												REG_ISP_SNR_GAMMA_B1 |= (n<<24);   
#define SET_SENSOR_GAMMA_B_B6(n)		REG_ISP_SNR_GAMMA_B1 &= ~REG_SENSOR_GAMMA_B_B6_MASK;\
												REG_ISP_SNR_GAMMA_B1 |= (n<<16);   
#define SET_SENSOR_GAMMA_B_B7(n)		REG_ISP_SNR_GAMMA_B1 &= ~REG_SENSOR_GAMMA_B_B7_MASK;\
												REG_ISP_SNR_GAMMA_B1 |= (n<<8);   
#define SET_SENSOR_GAMMA_B_B8(n)		REG_ISP_SNR_GAMMA_B1 &= ~REG_SENSOR_GAMMA_B_B8_MASK;\
												REG_ISP_SNR_GAMMA_B1 |= n;   
#define SET_SENSOR_GAMMA_B_B9(n)		REG_ISP_SNR_GAMMA_B2 &= ~REG_SENSOR_GAMMA_B_B9_MASK;\
												REG_ISP_SNR_GAMMA_B2 |= (n<<24);   
#define SET_SENSOR_GAMMA_B_B10(n)	REG_ISP_SNR_GAMMA_B2 &= ~REG_SENSOR_GAMMA_B_B10_MASK;\
												REG_ISP_SNR_GAMMA_B2 |= (n<<16);   
#define SET_SENSOR_GAMMA_B_B11(n)	REG_ISP_SNR_GAMMA_B2 &= ~REG_SENSOR_GAMMA_B_B11_MASK;\
												REG_ISP_SNR_GAMMA_B2 |= (n<<8);  
#endif

/* macros of LPF control register */
#define ENABLE_Y_LPF					REG_ISP_LPF_CTRL |= REG_LPF_Y_LPF_ENABLE_BIT;
#define DISABLE_Y_LPF				REG_ISP_LPF_CTRL &= ~REG_LPF_Y_LPF_ENABLE_BIT;
#define ENABLE_C_LPF					REG_ISP_LPF_CTRL |= REG_LPF_C_LPF_ENABLE_BIT;
#define DISABLE_C_LPF				REG_ISP_LPF_CTRL &= ~REG_LPF_C_LPF_ENABLE_BIT;
#if (defined(DRV_ISP_6219_SERIES))
#define SET_Y_LPF_TYPE(n) 			REG_ISP_LPF_CTRL &= ~REG_LPF_Y_LPF_TYPE_MASK;\
											REG_ISP_LPF_CTRL |= (n<<12);
#define SET_C_LPF_TYPE(n) 			REG_ISP_LPF_CTRL &= ~REG_LPF_C_LPF_TYPE_MASK;\
											REG_ISP_LPF_CTRL |= (n<<9);
#define SET_SUB_SAMPLE_MODE(n)	REG_ISP_LPF_CTRL &= ~REG_LPF_SUB_SAMPLE_MASK;\
											REG_ISP_LPF_CTRL |= n;
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define ENABLE_VERTICAL_LPF		REG_ISP_LPF_CTRL |= REG_LPF_V_LPF_ENABLE_BIT;	
#define DISABLE_VERTICAL_LPF		REG_ISP_LPF_CTRL &= ~REG_LPF_V_LPF_ENABLE_BIT;	

/* macros of Y LPF control register */
#define SET_Y_LPF_WEIGHT0(n) 			REG_ISP_Y_LPF_CTRL &= ~REG_Y_LPF_WEIGHT0_MASK;\
												REG_ISP_Y_LPF_CTRL |= (n<<24);
#define SET_Y_LPF_WEIGHT1(n) 			REG_ISP_Y_LPF_CTRL &= ~REG_Y_LPF_WEIGHT1_MASK;\
												REG_ISP_Y_LPF_CTRL |= (n<<16);
#define SET_Y_LPF_WEIGHT2(n) 			REG_ISP_Y_LPF_CTRL &= ~REG_Y_LPF_WEIGHT2_MASK;\
												REG_ISP_Y_LPF_CTRL |= (n<<8);
#define SET_Y_LPF_WEIGHT3(n) 			REG_ISP_Y_LPF_CTRL &= ~REG_Y_LPF_WEIGHT3_MASK;\
												REG_ISP_Y_LPF_CTRL |= n;

/* macros of CBCR LPF control register */
#define SET_CBCR_LPF_WEIGHT0(n)		REG_ISP_CBCR_LPF_CTRL &= ~REG_C_LPF_WEIGHT0_MASK;\
												REG_ISP_CBCR_LPF_CTRL |= (n<<24);
#define SET_CBCR_LPF_WEIGHT1(n)		REG_ISP_CBCR_LPF_CTRL &= ~REG_C_LPF_WEIGHT1_MASK;\
												REG_ISP_CBCR_LPF_CTRL |= (n<<16);
#define SET_CBCR_LPF_WEIGHT2(n)		REG_ISP_CBCR_LPF_CTRL &= ~REG_C_LPF_WEIGHT2_MASK;\
												REG_ISP_CBCR_LPF_CTRL |= (n<<8);
#define SET_CBCR_LPF_WEIGHT3(n)		REG_ISP_CBCR_LPF_CTRL &= ~REG_C_LPF_WEIGHT3_MASK;\
												REG_ISP_CBCR_LPF_CTRL |= n;

/* macros of vertical sub-sample register */
#define ENABLE_VERTICAL_SUB_SAMPLE		REG_ISP_VERTICAL_SUB_SAMPLE_CTRL |= REG_VERTICAL_SUB_V_SUB_EN_BIT;	
#define DISABLE_VERTICAL_SUB_SAMPLE		REG_ISP_VERTICAL_SUB_SAMPLE_CTRL &= ~REG_VERTICAL_SUB_V_SUB_EN_BIT;	
#define SET_VSUB_SRC_SIZE(n) 				REG_ISP_VERTICAL_SUB_SAMPLE_CTRL &= ~REG_VERTICAL_SUB_V_SUB_IN_MASK;\
													REG_ISP_VERTICAL_SUB_SAMPLE_CTRL |= (n<<16);
#define SET_VSUB_DST_SIZE(n) 				REG_ISP_VERTICAL_SUB_SAMPLE_CTRL &= ~REG_VERTICAL_SUB_V_SUB_OUT_MASK;\
													REG_ISP_VERTICAL_SUB_SAMPLE_CTRL |= n;

/* macros of horizontal sub-sample register */
#define ENABLE_HORIZONTAL_SUB_SAMPLE		REG_ISP_HORIZONTAL_SUB_SAMPLE_CTRL |= REG_HORIZONTAL_SUB_H_SUB_EN_BIT;	
#define DISABLE_HORIZONTAL_SUB_SAMPLE		REG_ISP_HORIZONTAL_SUB_SAMPLE_CTRL &= ~REG_HORIZONTAL_SUB_H_SUB_EN_BIT;	
#define SET_HSUB_SRC_SIZE(n) 					REG_ISP_HORIZONTAL_SUB_SAMPLE_CTRL &= ~REG_HORIZONTAL_SUB_H_SUB_IN_MASK;\
														REG_ISP_HORIZONTAL_SUB_SAMPLE_CTRL |= (n<<16);
#define SET_HSUB_DST_SIZE(n) 					REG_ISP_HORIZONTAL_SUB_SAMPLE_CTRL &= ~REG_HORIZONTAL_SUB_H_SUB_OUT_MASK;\
														REG_ISP_HORIZONTAL_SUB_SAMPLE_CTRL |= n;

/* macros of defect pixel register */
#define ENABLE_DEFECT_CORRECTION		REG_ISP_DEFECT_PIXEL_CONFIG |= REG_DEFECT_ENABLE_BIT;		
#define DISABLE_DEFECT_CORRECTION	REG_ISP_DEFECT_PIXEL_CONFIG &= ~REG_DEFECT_ENABLE_BIT;	
#endif
#if (!defined(DRV_ISP_6219_SERIES))
/* macros of AE area register */
#define AE_AREA_COUNT					(REG_ISP_AE_AREA & REG_AE_AREACNT_MASK)			
#define AE_FRAME_COUNT					((REG_ISP_AE_AREA & REG_AE_FRAMECNT_MASK)>>8)	
#define SET_AE_H_OFFSET(n)				REG_ISP_AE_AREA &= ~REG_AE_HOFFSET_MASK;\
												REG_ISP_AE_AREA |= (n<<16);
#define SET_AE_V_OFFSET(n)				REG_ISP_AE_AREA &= ~REG_AE_VOFFSET_MASK;\
												REG_ISP_AE_AREA |= (n<<24);
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* macros of shading register */
#define ENABLE_SHADING_RANGE				REG_ISP_SHADING_CTRL1 |= REG_SHADING_RANGE_ENABLE_BIT;	
#define DISABLE_SHADING_RANGE				REG_ISP_SHADING_CTRL1 &= ~REG_SHADING_RANGE_ENABLE_BIT;	
#define ENABLE_SHADING_COMPENSATION		REG_ISP_SHADING_CTRL1 |= REG_SHADING_ENABLE_BIT;		
#define DISABLE_SHADING_COMPENSATION	REG_ISP_SHADING_CTRL1 &= ~REG_SHADING_ENABLE_BIT;		
#define SET_SHADING_CENTERY(n)			REG_ISP_SHADING_CTRL1 &= ~REG_SHADING_CENTERY_MASK;\
													REG_ISP_SHADING_CTRL1 |= (n<<16);   
#define SET_SHADING_K_FACTOR(n)			REG_ISP_SHADING_CTRL1 &= ~REG_SHADING_K_FACTOR_MASK;\
													REG_ISP_SHADING_CTRL1 |= (n<<14);   													
#define SET_SHADING_RADIUS_FACTOR(n)	REG_ISP_SHADING_CTRL1 &= ~REG_SHADING_RADIUS_FACTOR_MASK;\
													REG_ISP_SHADING_CTRL1 |= (n<<12);   
#define SET_SHADING_CENTERX(n)			REG_ISP_SHADING_CTRL1 &= ~REG_SHADING_CENTERX_MASK;\
													REG_ISP_SHADING_CTRL1 |= n;   
#define SET_SHADING_KR(n)					REG_ISP_SHADING_CTRL2 &= ~REG_SHADING_KR_MASK;\
													REG_ISP_SHADING_CTRL2 |= (n<<24);   
#define SET_SHADING_KG(n)					REG_ISP_SHADING_CTRL2 &= ~REG_SHADING_KG_MASK;\
													REG_ISP_SHADING_CTRL2 |= (n<<16);   
#define SET_SHADING_KB(n)					REG_ISP_SHADING_CTRL2 &= ~REG_SHADING_KB_MASK;\
													REG_ISP_SHADING_CTRL2 |= (n<<8);   
#define SET_SHADING_RANGE(n)				REG_ISP_SHADING_CTRL2 &= ~REG_SHADING_RANGE_MASK;\
													REG_ISP_SHADING_CTRL2 |= n;   

#define ENABLE_SHADING_CURVE			REG_ISP_SHADING_R_CURVE1 |= REG_SHADING_CURVE_ENABLE_BIT;
#define DISABLE_SHADING_CURVE			REG_ISP_SHADING_R_CURVE1 &= ~REG_SHADING_CURVE_ENABLE_BIT;
#define ENABLE_SHADING_CURVE_IVT		REG_ISP_SHADING_R_CURVE1 |= REG_SHADING_CURVE_IVT_MASK;
#define DISABLE_SHADING_CURVE_IVT	REG_ISP_SHADING_R_CURVE1 &= ~REG_SHADING_CURVE_IVT_MASK;
#define SET_SHADING_CURVE_SEL(n)		REG_ISP_SHADING_R_CURVE1 &= ~REG_SHADING_CURVE_SEL_MASK;\
												REG_ISP_SHADING_R_CURVE1 |= (n<<24);   
												
#define SET_SHADING_CURVE_R_B1(n)	REG_ISP_SHADING_R_CURVE1 &= ~REG_SHADING_CURVE_R_B1_MASK;\
												REG_ISP_SHADING_R_CURVE1 |= (n<<16);
#define SET_SHADING_CURVE_R_B2(n)	REG_ISP_SHADING_R_CURVE1 &= ~REG_SHADING_CURVE_R_B2_MASK;\
												REG_ISP_SHADING_R_CURVE1 |= (n<<8);
#define SET_SHADING_CURVE_R_B3(n)	REG_ISP_SHADING_R_CURVE1 &= ~REG_SHADING_CURVE_R_B3_MASK;\
												REG_ISP_SHADING_R_CURVE1 |= n;
#define SET_SHADING_CURVE_R_B4(n)	REG_ISP_SHADING_R_CURVE2 &= ~REG_SHADING_CURVE_R_B4_MASK;\
												REG_ISP_SHADING_R_CURVE2 |= (n<<24);
#define SET_SHADING_CURVE_R_B5(n)	REG_ISP_SHADING_R_CURVE2 &= ~REG_SHADING_CURVE_R_B5_MASK;\
												REG_ISP_SHADING_R_CURVE2 |= (n<<16);
#define SET_SHADING_CURVE_R_B6(n)	REG_ISP_SHADING_R_CURVE2 &= ~REG_SHADING_CURVE_R_B6_MASK;\
												REG_ISP_SHADING_R_CURVE2 |= (n<<8);
#define SET_SHADING_CURVE_R_B7(n)	REG_ISP_SHADING_R_CURVE2 &= ~REG_SHADING_CURVE_R_B7_MASK;\
												REG_ISP_SHADING_R_CURVE2 |= n;
#define SET_SHADING_CURVE_R_B8(n)	REG_ISP_SHADING_R_CURVE3 &= ~REG_SHADING_CURVE_R_B8_MASK;\
												REG_ISP_SHADING_R_CURVE3 |= (n<<24);
#define SET_SHADING_CURVE_R_B9(n)	REG_ISP_SHADING_R_CURVE3 &= ~REG_SHADING_CURVE_R_B9_MASK;\
												REG_ISP_SHADING_R_CURVE3 |= (n<<16);
#define SET_SHADING_CURVE_R_B10(n)	REG_ISP_SHADING_R_CURVE3 &= ~REG_SHADING_CURVE_R_B10_MASK;\
												REG_ISP_SHADING_R_CURVE3 |= (n<<8);
#define SET_SHADING_CURVE_R_B11(n)	REG_ISP_SHADING_R_CURVE3 &= ~REG_SHADING_CURVE_R_B11_MASK;\
												REG_ISP_SHADING_R_CURVE3 |= n;

#define SET_SHADING_CURVE_G_B1(n)	REG_ISP_SHADING_G_CURVE1 &= ~REG_SHADING_CURVE_G_B1_MASK;\
												REG_ISP_SHADING_G_CURVE1 |= (n<<16);
#define SET_SHADING_CURVE_G_B2(n)	REG_ISP_SHADING_G_CURVE1 &= ~REG_SHADING_CURVE_G_B2_MASK;\
												REG_ISP_SHADING_G_CURVE1 |= (n<<8);
#define SET_SHADING_CURVE_G_B3(n)	REG_ISP_SHADING_G_CURVE1 &= ~REG_SHADING_CURVE_G_B3_MASK;\
												REG_ISP_SHADING_G_CURVE1 |= n;
#define SET_SHADING_CURVE_G_B4(n)	REG_ISP_SHADING_G_CURVE2 &= ~REG_SHADING_CURVE_G_B4_MASK;\
												REG_ISP_SHADING_G_CURVE2 |= (n<<24);
#define SET_SHADING_CURVE_G_B5(n)	REG_ISP_SHADING_G_CURVE2 &= ~REG_SHADING_CURVE_G_B5_MASK;\
												REG_ISP_SHADING_G_CURVE2 |= (n<<16);
#define SET_SHADING_CURVE_G_B6(n)	REG_ISP_SHADING_G_CURVE2 &= ~REG_SHADING_CURVE_G_B6_MASK;\
												REG_ISP_SHADING_G_CURVE2 |= (n<<8);
#define SET_SHADING_CURVE_G_B7(n)	REG_ISP_SHADING_G_CURVE2 &= ~REG_SHADING_CURVE_G_B7_MASK;\
												REG_ISP_SHADING_G_CURVE2 |= n;
#define SET_SHADING_CURVE_G_B8(n)	REG_ISP_SHADING_G_CURVE3 &= ~REG_SHADING_CURVE_G_B8_MASK;\
												REG_ISP_SHADING_G_CURVE3 |= (n<<24);
#define SET_SHADING_CURVE_G_B9(n)	REG_ISP_SHADING_G_CURVE3 &= ~REG_SHADING_CURVE_G_B9_MASK;\
												REG_ISP_SHADING_G_CURVE3 |= (n<<16);
#define SET_SHADING_CURVE_G_B10(n)	REG_ISP_SHADING_G_CURVE3 &= ~REG_SHADING_CURVE_G_B10_MASK;\
												REG_ISP_SHADING_G_CURVE3 |= (n<<8);
#define SET_SHADING_CURVE_G_B11(n)	REG_ISP_SHADING_G_CURVE3 &= ~REG_SHADING_CURVE_G_B11_MASK;\
												REG_ISP_SHADING_G_CURVE3 |= n;

#define SET_SHADING_CURVE_B_B1(n)	REG_ISP_SHADING_B_CURVE1 &= ~REG_SHADING_CURVE_B_B1_MASK;\
												REG_ISP_SHADING_B_CURVE1 |= (n<<16);
#define SET_SHADING_CURVE_B_B2(n)	REG_ISP_SHADING_B_CURVE1 &= ~REG_SHADING_CURVE_B_B2_MASK;\
												REG_ISP_SHADING_B_CURVE1 |= (n<<8);
#define SET_SHADING_CURVE_B_B3(n)	REG_ISP_SHADING_B_CURVE1 &= ~REG_SHADING_CURVE_B_B3_MASK;\
												REG_ISP_SHADING_B_CURVE1 |= n;
#define SET_SHADING_CURVE_B_B4(n)	REG_ISP_SHADING_B_CURVE2 &= ~REG_SHADING_CURVE_B_B4_MASK;\
												REG_ISP_SHADING_B_CURVE2 |= (n<<24);
#define SET_SHADING_CURVE_B_B5(n)	REG_ISP_SHADING_B_CURVE2 &= ~REG_SHADING_CURVE_B_B5_MASK;\
												REG_ISP_SHADING_B_CURVE2 |= (n<<16);
#define SET_SHADING_CURVE_B_B6(n)	REG_ISP_SHADING_B_CURVE2 &= ~REG_SHADING_CURVE_B_B6_MASK;\
												REG_ISP_SHADING_B_CURVE2 |= (n<<8);
#define SET_SHADING_CURVE_B_B7(n)	REG_ISP_SHADING_B_CURVE2 &= ~REG_SHADING_CURVE_B_B7_MASK;\
												REG_ISP_SHADING_B_CURVE2 |= n;
#define SET_SHADING_CURVE_B_B8(n)	REG_ISP_SHADING_B_CURVE3 &= ~REG_SHADING_CURVE_B_B8_MASK;\
												REG_ISP_SHADING_B_CURVE3 |= (n<<24);
#define SET_SHADING_CURVE_B_B9(n)	REG_ISP_SHADING_B_CURVE3 &= ~REG_SHADING_CURVE_B_B9_MASK;\
												REG_ISP_SHADING_B_CURVE3 |= (n<<16);
#define SET_SHADING_CURVE_B_B10(n)	REG_ISP_SHADING_B_CURVE3 &= ~REG_SHADING_CURVE_B_B10_MASK;\
												REG_ISP_SHADING_B_CURVE3 |= (n<<8);
#define SET_SHADING_CURVE_B_B11(n)	REG_ISP_SHADING_B_CURVE3 &= ~REG_SHADING_CURVE_B_B11_MASK;\
												REG_ISP_SHADING_B_CURVE3 |= n;
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* macros of AE window size register */
#define SET_AE_WINDOW_VSIZE(n)			REG_ISP_AE_WINDOW_SIZE &= ~REG_AE_VSIZE_MASK;\
													REG_ISP_AE_WINDOW_SIZE |= ((n-1)<<16); 
#define SET_AE_WINDOW_HSIZE(n)			REG_ISP_AE_WINDOW_SIZE &= ~REG_AE_HSIZE_MASK;\
													REG_ISP_AE_WINDOW_SIZE |= (n-1); 
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define SET_AE_FRAME_INTERVAL(n)			REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_AE_INTERVAL_MASK;\
													REG_ISP_AUTO_DEFECT_CTRL1 |= (n<<8); 
#endif
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* macros of auto defect control register */
#define DISABLE_AUTO_DEFECT_ALL						REG_ISP_AUTO_DEFECT_CTRL1 &= ~0xF8000000;	
#define ENABLE_AUTO_DEFECT_CENTRAL_CELL			REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_ADC_EN_BIT;		
#define DISABLE_AUTO_DEFECT_CENTRAL_CELL			REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_ADC_EN_BIT;	
#define ENABLE_AUTO_DEFECT_LEFT_CELL				REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_ADL_EN_BIT;		
#define DISABLE_AUTO_DEFECT_LEFT_CELL				REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_ADL_EN_BIT;	
#define ENABLE_AUTO_DEFECT_RIGHT_CELL				REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_ADR_EN_BIT;		
#define DISABLE_AUTO_DEFECT_RIGHT_CELL				REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_ADR_EN_BIT;	
#define ENABLE_AUTO_DEFECT_UP_CELL					REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_ADU_EN_BIT;		
#define DISABLE_AUTO_DEFECT_UP_CELL					REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_ADU_EN_BIT;	
#define ENABLE_AUTO_DEFECT_DOWN_CELL				REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_ADD_EN_BIT;		
#define DISABLE_AUTO_DEFECT_DOWN_CELL				REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_ADD_EN_BIT;	
#define ENABLE_AUTO_DEFECT_CHECK_DEADPIXEL		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_DEADCHECK_BIT;		
#define DISABLE_AUTO_DEFECT_CHECK_DEADPIXEL		REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_DEADCHECK_BIT;	
#define SET_AUTO_DEFECT_GPIXEL_CHECK_METHOD(n)	REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_GCHECK_SEL_MASK;\
																REG_ISP_AUTO_DEFECT_CTRL1 |= (n<<24);   
#define SET_AUTO_DEFECT_RBPIXEL_CHECK_METHOD(n)	REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_RBCHECK_SEL_MASK;\
																REG_ISP_AUTO_DEFECT_CTRL1 |= (n<<22);   
#define SET_AUTO_DEFECT_BRIGHTPIXEL_THD(n)		REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_BRIGHTTHD_MASK;\
																REG_ISP_AUTO_DEFECT_CTRL1 |= (n<<19);   
#define SET_AUTO_DEFECT_BLACKPIXEL_THD(n)			REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_BLACKTHD_MASK;\
																REG_ISP_AUTO_DEFECT_CTRL1 |= (n<<16);   

#define SET_AUTO_DEFECT_GPIXEL_CHECK_THD(n)		REG_ISP_AUTO_DEFECT_CTRL2 &= ~REG_AUTO_DEFECT_GCHECKTHD_MASK;\
																REG_ISP_AUTO_DEFECT_CTRL2 |= (n<<24);   
#define SET_AUTO_DEFECT_RBPIXEL_CHECK_THD(n)		REG_ISP_AUTO_DEFECT_CTRL2 &= ~REG_AUTO_DEFECT_RBCHECKTHD_MASK;\
																REG_ISP_AUTO_DEFECT_CTRL2 |= (n<<16);   
#define SET_AUTO_DEFECT_GPIXEL_CORRECT_THD(n)	REG_ISP_AUTO_DEFECT_CTRL2 &= ~REG_AUTO_DEFECT_GCORRECTTHD_MASK;\
																REG_ISP_AUTO_DEFECT_CTRL2 |= (n<<8);   
#define SET_AUTO_DEFECT_RBPIXEL_CORRECT_THD(n)	REG_ISP_AUTO_DEFECT_CTRL2 &= ~REG_AUTO_DEFECT_RBCORRECTTHD_MASK;\
																REG_ISP_AUTO_DEFECT_CTRL2 |= n;   
                                               
/* macros of flash register */
#define FLASH_OUT_STATUS					((REG_ISP_FLASH_CTRL & REG_FLASH_OUT_BIT)>>31)		
#define ENABLE_FLASH_LIGHT					REG_ISP_FLASH_CTRL |= REG_FLASH_EN_BIT;				
#define DISABLE_FLASH_LIGHT				REG_ISP_FLASH_CTRL &= ~REG_FLASH_EN_BIT;				
#define SET_FLASH_STARTPNT_HIGH			REG_ISP_FLASH_CTRL |= REG_FLASH_STARTPNT_BIT;		
#define SET_FLASH_STARTPNT_LOW			REG_ISP_FLASH_CTRL &= ~REG_FLASH_STARTPNT_BIT;		
#define SET_FLASH_POL_HIGH					REG_ISP_FLASH_CTRL |= REG_FLASH_POL_BIT;		
#define SET_FLASH_POL_LOW					REG_ISP_FLASH_CTRL &= ~REG_FLASH_POL_BIT;		
#define SET_FLASH_LINE_UNIT(n)			REG_ISP_FLASH_CTRL &= ~REG_FLASH_LNUNIT_MASK;\
													REG_ISP_FLASH_CTRL |= (n<<16);   
#define SET_FLASH_LINE_NUMBER(n)			REG_ISP_FLASH_CTRL &= ~REG_FLASH_LNUNIT_NO_MASK;\
													REG_ISP_FLASH_CTRL |= (n<<8);   
#define SET_FLASH_FRAME_DELAY(n)			REG_ISP_FLASH_CTRL &= ~REG_FLASH_FRAME_DELAY_MASK;\
													REG_ISP_FLASH_CTRL |= n;   

/* macros of CAM reset register */
#define RESET_ISP								REG_ISP_RESET |= REG_CAM_RESET_ISP_RESET_BIT;		
#define CLEAR_RESET_ISP						REG_ISP_RESET &= ~REG_CAM_RESET_ISP_RESET_BIT;		
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/* macros of imageproc hue register */
#define ENABLE_IMGPROC_HUE					REG_ISP_IMGPROC_HUE0 |= REG_IMGPROC_HUE_ENABLE_BIT;		
#define DISABLE_IMGPROC_HUE				REG_ISP_IMGPROC_HUE0 &= ~REG_IMGPROC_HUE_ENABLE_BIT;		
#if (!defined(MT6238))
#define SET_IMGPROC_HUE11(n)				REG_ISP_IMGPROC_HUE0 &= ~REG_IMGPROC_HUE_HUE11_MASK;\
													REG_ISP_IMGPROC_HUE0 |= (n<<8);   
#define SET_IMGPROC_HUE12(n)				REG_ISP_IMGPROC_HUE0 &= ~REG_IMGPROC_HUE_HUE12_MASK;\
													REG_ISP_IMGPROC_HUE0 |= n;   
#define SET_IMGPROC_HUE21(n)				REG_ISP_IMGPROC_HUE1 &= ~REG_IMGPROC_HUE_HUE21_MASK;\
													REG_ISP_IMGPROC_HUE1 |= (n<<24);   
#define SET_IMGPROC_HUE22(n)				REG_ISP_IMGPROC_HUE1 &= ~REG_IMGPROC_HUE_HUE22_MASK;\
													REG_ISP_IMGPROC_HUE1 |= (n<<16);   
#endif
#endif

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
/* macros of result window register */
#define ENABLE_RESULT_WINDOW				REG_ISP_RESULT_WINDOW_V_SIZE |= REG_RESULT_WINDOW_ENABLE_BIT;
#define DISABLE_RESULT_WINDOW				REG_ISP_RESULT_WINDOW_V_SIZE &= ~REG_RESULT_WINDOW_ENABLE_BIT;
#define SET_RESULT_WINDOW_V_START(n)	REG_ISP_RESULT_WINDOW_V_SIZE &= ~REG_RESULT_WINDOW_START_MASK;\
													REG_ISP_RESULT_WINDOW_V_SIZE |= (n<<16);
#define SET_RESULT_WINDOW_V_END(n)		REG_ISP_RESULT_WINDOW_V_SIZE &= ~REG_RESULT_WINDOW_END_MASK;\
													REG_ISP_RESULT_WINDOW_V_SIZE |= (n);
#define SET_RESULT_WINDOW_H_START(n)	REG_ISP_RESULT_WINDOW_H_SIZE &= ~REG_RESULT_WINDOW_START_MASK;\
													REG_ISP_RESULT_WINDOW_H_SIZE |= (n<<16);
#define SET_RESULT_WINDOW_H_END(n)		REG_ISP_RESULT_WINDOW_H_SIZE &= ~REG_RESULT_WINDOW_END_MASK;\
													REG_ISP_RESULT_WINDOW_H_SIZE |= (n);
#define SET_RESULT_WINDOW_VERTICAL_SIZE(start,line)		REG_ISP_RESULT_WINDOW_V_SIZE =((start<<16) | (line+start));
#define SET_RESULT_WINDOW_HORIZONTAL_SIZE(start,pixel)	REG_ISP_RESULT_WINDOW_H_SIZE =((start<<16) | (pixel+start));
#endif

/* macros of Camera interface debug mode control register */
#define ENABLE_GMC_DEBUG_OUTPUT		REG_ISP_DEBUG_CTRL |= REG_DEBUG_GMC_ENABLE_BIT;
#define DISABLE_GMC_DEBUG_OUTPUT		REG_ISP_DEBUG_CTRL &= ~REG_DEBUG_GMC_ENABLE_BIT;
#define SET_GMC_RAW_RGB_MODE			REG_ISP_DEBUG_CTRL &= ~REG_DEBUG_GMC_MODE_BIT;
#define SET_GMC_RGB565_MODE			REG_ISP_DEBUG_CTRL |= REG_DEBUG_GMC_MODE_BIT;
#define ENABLE_DEBUG_DATA_COUNTER	REG_ISP_DEBUG_CTRL |= REG_DEBUG_DATA_COUNT_ENABLE_BIT;
#define DISABLE_DEBUG_DATA_COUNTER	REG_ISP_DEBUG_CTRL &= ~REG_DEBUG_DATA_COUNT_ENABLE_BIT;
#define SET_DEBUG_OUTPUT_MODE(n)		REG_ISP_DEBUG_CTRL &= ~REG_DEBUG_DATA_COUNT_MODE_MASK;\
												REG_ISP_DEBUG_CTRL |= (n<<3);
#endif /* MT6219||MT6228||MT6226||MT6227||MT6229 */
#endif /* _ISP_IF_622X_SERIES_HW_H_ */
