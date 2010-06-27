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
 *   isp_cct_if.h
 *
 * Project:
 * --------
 *   MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   These are interface with FT for CCT/DeviceTool
 *
 * Author:
 * -------
 *   
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
 ****************************************************************************/
#ifndef _ISP_DEVICE_IF_H
#define _ISP_DEVICE_IF_H

#include "drv_features.h"
#include "isp_cct_if.h"
#include "isp_qc_if.h"
#include "ae_awb.h"
#if (defined(ISP_SUPPORT)&&(!defined(DRV_ISP_6225_SERIES)))
/*************************************************
 * INFO Interface 
 **************************************************/
dsc_info_struct *isp_device_get_dsc_info(void); 
device_info_struct *isp_device_get_device_info(void); 
void isp_device_get_iris_info(kal_bool iris[AV_NO]);
void isp_device_set_iris_info(const kal_bool iris[AV_NO]);

/*************************************************
 * AE Interface 	
 **************************************************/
typedef struct
{
    exposure_lut_struct *lut;
    kal_uint8   *iris_lut;
    kal_uint16  start_idx;
    kal_uint16  end_idx;
    kal_uint32  timer_ms;    
}camera_ae_bypass_freerun_struct;

typedef struct
{
    kal_uint32 *resultLum;
}camera_ae_bypass_freerun_result_struct;    

typedef struct
{
	kal_uint8	ae_awb_cal_period;					/* AE AWB calculation period */
	kal_uint8	ae_setting_gain_delay_frame;		/* The frame of setting gain */
	kal_uint8	ae_setting_shut_delay_frame;		/* The frame of setting shutter */
	kal_uint8	ae_setting_cal_delay_frame;		    /* The frame of calculation */
	kal_uint8	ae_setting_sensor_gain_delay_frame;	/* The frame of setting sensor gain */
}camera_ae_period_para_struct;

extern const exposure_lut_struct *get_ae_lut(ae_lut_info_struct info);
extern const kal_uint8 *get_iris_lut(ae_lut_info_struct info);
kal_uint8 isp_device_set_ae_idx(ae_lut_info_struct ae_lut_info, kal_uint8 idx);
kal_uint8 isp_device_set_ae_value(kal_uint32 shutter, kal_uint32 sensorgain, kal_uint32 ispgain);

void set_ae_period_data(const camera_ae_period_para_struct *period_data);
void get_ae_period_data(camera_ae_period_para_struct *period_data);
kal_uint8 isp_device_ae_bypass_freerun_process(camera_ae_bypass_freerun_struct *freerun_para, camera_ae_bypass_freerun_result_struct *freerun_result);
kal_uint32 get_lum_info(void);

/*************************************************
 * AF Interface 	
 **************************************************/
kal_uint8 isp_device_af_calibration(kal_uint32 *pos, kal_uint32 *atf_value);
kal_uint8 isp_device_set_af_idx(kal_uint8 idx);
kal_uint8 isp_device_set_af_pos(kal_uint32 pos);

/*************************************************
 * Flash Light Interface 	
 **************************************************/
enum
{
	FLASHLIGHT_STROBE_NONE,    
	FLASHLIGHT_STROBE_PRE,
	FLASHLIGHT_STROBE_MAIN,			
	FLASHLIGHT_STROBE_REDEYE
};

typedef struct
{
    kal_bool    charge_on;              /* charge status after charge ready */
    kal_uint32  timeout_ms;             /* Charge timout limit*/
} flashlight_cdt_charge_struct;

typedef struct
{
    kal_uint16   strobe_width;           /* the image width */  
    kal_uint16   strobe_height;          /* the image height */  
    kal_uint32  strobe_offset;          /* strobe offset */    
    kal_uint32  strobe_duty;            /* strobe duty */ 
} flashlight_cdt_strobe_struct;

typedef struct
{
    kal_bool    prestrobe_en;           /* enable pre-strobe */        
    kal_uint16  prestrobe_duty;	    	/* pre-strobe duty(us) */       
    kal_uint16  prestrobe_times;        /* pre-strobe times */         
    kal_bool    redeye_en;              /* enable red eye */            
    kal_uint16  redeye_duty;	    	/* red eye duty(us) */       
    kal_uint16  redeye_offset;   	    /* red-eye-strobe offset(line) */        
    kal_uint16  strobe_width;           /* the image width */  
    kal_uint16  strobe_height;          /* the image height */  
    kal_uint16  mainstrobe_duty;	    /* main-strobe duty(us) */       
    kal_uint16  ae_index;               /* ae index when capture */
    kal_bool    is_awb_apply;           /* apply r/g/b gain or not */    
    kal_uint16  rgain;	                /* rgain when capture */
    kal_uint16  ggain;	                /* ggain when capture */           
    kal_uint16  bgain;	                /* bgain when capture */                   
} flashlight_cdt_capture_struct;

kal_uint8 adjust_flashlight_param(kal_uint32 curr_lum, kal_uint32 target_lum);
kal_bool  isp_device_is_flashtype_supported(kal_uint8 mode);
kal_uint32 isp_device_flashligh_charge(flashlight_cdt_charge_struct *isp_charge_data);
void isp_device_flashligh_strobe(flashlight_cdt_strobe_struct *isp_strobe_data);

exposure_lut_struct isp_device_flashligh_capture_config(flashlight_cdt_capture_struct *pData);

kal_uint8 isp_device_flashligh_prestrobe(camera_capture_cct_struct *isp_cct_data);
kal_uint8 isp_device_flashligh_mainstrobe(camera_capture_cct_struct *isp_cct_data);
kal_uint8 isp_device_flashligh_aeawb(camera_capture_cct_struct *isp_cct_data);
void isp_device_flashligh_enable(kal_bool on);

kal_uint32  isp_cdt_get_flashlight_charge_level_count(void);
kal_bool isp_cdt_set_flashlight_charge_level_count(kal_uint32 level);
exposure_lut_struct isp_cdt_set_flashlight_ae_index(kal_uint8 ae_index);
kal_uint8 isp_cdt_get_current_ae_index(void);
#endif

#endif
