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
 *   These are interface with FT for CCT/DeviceTool
 *
 * Author:
 * -------
 *
 *   UW Wang (mtk01051)
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
#if (defined(ISP_SUPPORT)&&(!defined(DRV_ISP_6225_SERIES))&&(!defined(DRV_ISP_6219_SERIES)))
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
#include "med_api.h"
#include "isp_device_if.h"
#include "af.h"
#include "isp_flashlight.h"

extern kal_eventgrpid camera_isp_event_id;
extern ae_lut_info_struct lut_info;
extern kal_uint32  avgall_lum;
/* AE bypass free run mode parameters */
kal_bool    ae_enable_flag_restore;          // for restore ae flag
/* backup bypass gamma flag for ISO priority */
kal_uint32 isp_device_backup_gamma_enable;
/*************************************************
 * INFO Interface 
 **************************************************/
/* Mode support get/update function (for MMI/Manu) */
dsc_info_struct *isp_device_get_dsc_info(void ) 
{
	return &dsc_support_info;
}				
	
/* AE/FlashLight device info get/update function (for AE/FlashLight) */	
device_info_struct *isp_device_get_device_info(void) 
{
	return &device_support_info;
}

/* Iris device support get/update function (for AE) */	
void isp_device_get_iris_info(kal_bool iris[AV_NO])
{
	memcpy(iris, aperture_pri_info, AV_NO*sizeof(kal_bool));
}

void isp_device_set_iris_info(const kal_bool iris[AV_NO])
{
	memcpy(aperture_pri_info, iris, AV_NO*sizeof(kal_bool));
}

/*************************************************
 * AE Interface 	
 **************************************************/
/*
 * use get_ae_lut to get ae table:
 *	const exposure_lut_struct *get_ae_lut(ae_lut_info_struct info);
 *	const kal_uint8 *get_iris_lut(ae_lut_info_struct info);
*/

/* 
 * AE Verify Functions 
 * Set AE to some idx by mode
 * Tool will adject LSB and take a picture with idx (repeat from idx=min_idx~max_idx) 
 */
kal_uint8 isp_device_set_ae_EV(ae_lut_info_struct ae_lut_info, kal_uint16 EV)
{
	kal_uint8 idx;
	
	if(EV<device_support_info.ae.minEv)
		ASSERT(0);
	if(device_support_info.ae.step==0)
		ASSERT(0);
	idx = (EV-device_support_info.ae.minEv)/device_support_info.ae.step;
	return isp_device_set_ae_idx(ae_lut_info, idx);
}

kal_uint8 isp_device_set_ae_idx(ae_lut_info_struct ae_lut_info, kal_uint8 idx)
{	
    kal_uint32 save_irq_mask;
    
	save_irq_mask=SaveAndSetIRQMask();    
    ae_enable_flag_restore  = ae_enable_flag;		
    ae_on_off(KAL_FALSE);
	RestoreIRQMask(save_irq_mask);    
	
	/* Load AE Table */
	AE_LUT=get_ae_lut(ae_lut_info);	
	image_sensor_func->set_sensor_eshutter(AE_LUT[idx].shutter);
	image_sensor_func->set_sensor_gain(AE_LUT[idx].sensorgain);
	isp_pregain = AE_LUT[idx].ispgain;
	ae_set_isp_pregain();
	
	save_irq_mask=SaveAndSetIRQMask();    	
    ae_on_off(ae_enable_flag_restore);      	
	RestoreIRQMask(save_irq_mask);        
	return KAL_TRUE;
}

kal_uint8 isp_device_set_ae_value(kal_uint32 shutter, kal_uint32 sensorgain, kal_uint32 ispgain)
{
    kal_uint32 save_irq_mask;
    
	save_irq_mask=SaveAndSetIRQMask();        
    ae_enable_flag_restore  = ae_enable_flag;	
    ae_on_off(KAL_FALSE);
	RestoreIRQMask(save_irq_mask);    
	    
	/* Load AE Table */
	image_sensor_func->set_sensor_eshutter((kal_uint16)shutter);
	image_sensor_func->set_sensor_gain((kal_uint16)sensorgain);
	isp_pregain = (kal_uint8)ispgain;
	ae_set_isp_pregain();	
	
	save_irq_mask=SaveAndSetIRQMask();        
    ae_on_off(ae_enable_flag_restore);      		
	RestoreIRQMask(save_irq_mask);        
	return KAL_TRUE;	
}

void set_ae_period_data(const camera_ae_period_para_struct *period_data)
{
    kal_uint32 save_irq_mask;
    
	save_irq_mask=SaveAndSetIRQMask();        
    ae_enable_flag_restore  = ae_enable_flag;	
    ae_on_off(KAL_FALSE);
	RestoreIRQMask(save_irq_mask);    
    
	// Update AE Period
	camera_oper_data.ae_awb_cal_period = period_data->ae_awb_cal_period;
	camera_oper_data.ae_setting_gain_delay_frame = period_data->ae_setting_gain_delay_frame;
	camera_oper_data.ae_setting_sensor_gain_delay_frame = period_data->ae_setting_sensor_gain_delay_frame;
	camera_oper_data.ae_setting_shut_delay_frame = period_data->ae_setting_shut_delay_frame;
	camera_oper_data.ae_setting_cal_delay_frame = period_data->ae_setting_cal_delay_frame;            

	save_irq_mask=SaveAndSetIRQMask();        
    ae_on_off(ae_enable_flag_restore);      		
	RestoreIRQMask(save_irq_mask);        	
}

void get_ae_period_data(camera_ae_period_para_struct *period_data)
{
	period_data->ae_awb_cal_period = camera_oper_data.ae_awb_cal_period;
	period_data->ae_setting_gain_delay_frame = camera_oper_data.ae_setting_gain_delay_frame;
	period_data->ae_setting_sensor_gain_delay_frame = camera_oper_data.ae_setting_sensor_gain_delay_frame;
	period_data->ae_setting_shut_delay_frame = camera_oper_data.ae_setting_shut_delay_frame;
	period_data->ae_setting_cal_delay_frame = camera_oper_data.ae_setting_cal_delay_frame;            	
}

void ae_bypass_mode_on_off(kal_bool flag)
{
	ae_bypass_enable_flag=flag;
}
/*************************************************************************
* FUNCTION
*	isp_device_ae_bypass_freerun_process
*
* DESCRIPTION
*	This function is for free run ae but bypass ae cal
*	Before call this function, AE should be turned off.
*	After ae bypass ready, AE should be turn on again to active ae freerun
*
* PARAMETERS
*	freerun_para:	indicate free run dsc mode, idx range and delay time
*	freerun_result:	AE freerun result lum for each idx
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 isp_device_ae_bypass_freerun_process( 
                    camera_ae_bypass_freerun_struct *freerun_para, 
                    camera_ae_bypass_freerun_result_struct *freerun_result )
{
    kal_uint32  curr_idx, ticks;
    ticks = ((freerun_para->timer_ms)*1000)/4615;
    
    ae_enable_flag_restore  = ae_enable_flag;
    AE_LUT = freerun_para->lut;	               /* Assign AE Table */   	
    IRIS_LUT = freerun_para->iris_lut;
    AE_BYPASS_INDEX = freerun_para->start_idx;  /* Set AE bypass Index */		
    
    ae_bypass_mode_on_off(KAL_TRUE);   
    ae_on_off(KAL_TRUE);                  
    for(curr_idx=freerun_para->start_idx; curr_idx<=freerun_para->end_idx; curr_idx++)
    {
        AE_BYPASS_INDEX = curr_idx; /* Set AE bypass Index */		
        kal_sleep_task(ticks);
        freerun_result->resultLum[curr_idx] = avgall_lum;
    }   
    ae_on_off(ae_enable_flag_restore);      
    ae_bypass_mode_on_off(KAL_FALSE);    
    return KAL_TRUE;
}

kal_uint32 get_lum_info(void)
{
	return avglum;
}

/*************************************************
 * AF Interface 	
 **************************************************/
/* AF Calibration finction :	Search AF Best Pos */	
kal_uint8 isp_device_af_calibration(kal_uint32 *pos, kal_uint32 *atf_value)
{
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	kal_uint32 event_group;	
	kal_uint32 p, start_p, end_p;
	kal_uint32 curr_atf=0, best_atf=0, best_pos;
	kal_uint32 grab_x_start,grab_x_end,grab_y_start,grab_y_end;
	kal_uint16 offsetX,offsetY;
	
	DISABLE_VIEW_FINDER_MODE;
	/* config AF window */
	grab_x_start=((REG_ISP_TG_GRAB_RANGE_PIXEL_CONFIG)&0xFFFF0000)>>16;
	grab_x_end=((REG_ISP_TG_GRAB_RANGE_PIXEL_CONFIG)&0x0000FFFF);
	grab_y_start=((REG_ISP_TG_GRAB_RANGE_LINE_CONFIG)&0xFFFF0000)>>16;
	grab_y_end=((REG_ISP_TG_GRAB_RANGE_LINE_CONFIG)&0x0000FFFF);
	offsetX=((grab_x_end-grab_x_start)>>1) - AF_WINDOW_W;
	offsetY=((grab_y_end-grab_y_start)>>1) - AF_WINDOW_H;
	af_window_config(1,AF_WINDOW_W,AF_WINDOW_H,offsetX,offsetY);
	/* init pos */
	start_p = camera_lens.INFO.af_me_home_pos;
	end_p = camera_lens.INFO.af_me_macro_pos;
	if(camera_lens.INFO.af_me_home_pos > camera_lens.INFO.af_me_macro_pos)
	{
		start_p = camera_lens.INFO.af_me_macro_pos;	
		end_p = camera_lens.INFO.af_me_home_pos;		
	}
	lens_func->lens_af_move_to(start_p);		
	best_pos = start_p;
	/* init isp */
	ENABLE_CMOS_SESNOR;	
	ENABLE_CAMERA_IDLE_INT;		
	SET_CAMERA_CAPTURE_MODE;
	SET_CAMERA_FRAME_RATE(0);
	ENABLE_VIEW_FINDER_MODE;
	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);
                          
	/* start search best ATF value */                          	
	for(p=start_p;p<=end_p;p++)
	{
		/* Move AF pos */
		lens_func->lens_af_move_to(p);	
		/* Wait Stable */
	   DISABLE_VIEW_FINDER_MODE;
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;

   	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
      	                    &event_group,KAL_SUSPEND);
		/* Get ATF value */
	   DISABLE_VIEW_FINDER_MODE;
	   kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
		ENABLE_VIEW_FINDER_MODE;

   	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
      	                    &event_group,KAL_SUSPEND);      	                    
	   DISABLE_VIEW_FINDER_MODE;
		curr_atf = AF_Result0;	
		if(best_atf < curr_atf)
		{
			best_atf = curr_atf;
			best_pos = p;
		}			
	}	
	
	*pos = best_pos;
	*atf_value = best_atf;
	lens_func->lens_af_move_to(best_pos);		
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

/* AF Verify finction :	Move AF to idx pos */	
kal_uint8 isp_device_set_af_idx(kal_uint8 idx)
{
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	if(lens_func!=NULL)
		lens_func->lens_af_move_to(camera_lens.AF[idx].pos);	
	return KAL_TRUE;		
#else
	return KAL_FALSE;
#endif
}

/* AF Verify finction :	Move AF to pos */	
kal_uint8 isp_device_set_af_pos(kal_uint32 pos)
{
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	if(lens_func!=NULL)
		lens_func->lens_af_move_to(pos);	
	return KAL_TRUE;				
#else
	return KAL_FALSE;
#endif
}

//=============================================================================
// Flash Light Function
//=============================================================================
flashlight_cdt_capture_struct isp_cdt_data;
flashlight_cdt_strobe_struct isp_strobe_data;
/*********************************************************************
 * Flash Light Interface 	
 * call by tool when user press "gen" flash light 
 *  keep capture from tool and Stop capture by tool when: 
 *	1. target_lum == curr_lum
 *	2. user stop process
 *	3. camera_strobe_capture_cct return KAL_FALSE (flash light limit) 
 **********************************************************************/
kal_uint8 adjust_flashlight_param(kal_uint32 curr_lum, kal_uint32 target_lum)
{
	kal_uint8 ret_code=KAL_TRUE;
	kal_uint16 isp_capture_pregain = BASEGAIN;
	
	if( (curr_lum>0xFF) || (target_lum==0) )	/* Init Flash light Capture */
		return KAL_TRUE;
	if( curr_lum == 0 )
		curr_lum = 1;
	
	if((device_support_info.autoflash.sensorgain!=sensor_pregain)||(device_support_info.autoflash.ispgain!=isp_pregain))
	{
		sensor_pregain=device_support_info.autoflash.sensorgain;		
		isp_pregain=device_support_info.autoflash.ispgain;
		image_sensor_func->set_sensor_gain(sensor_pregain);
		ae_set_isp_pregain();
		isp_capture_pregain=sensor_pregain*isp_pregain/0x40;
	}
	/* FlashLight Shutter Config */	
	if(curr_lum < target_lum)
	{		
		/* increase shutter */		
		if(device_support_info.autoflash.shutter < device_support_info.autoflash.max_shutter)
		{
			device_support_info.autoflash.shutter = (device_support_info.autoflash.shutter*target_lum)/curr_lum;
			if(device_support_info.autoflash.shutter>device_support_info.autoflash.max_shutter)
				device_support_info.autoflash.shutter = device_support_info.autoflash.max_shutter;
		}				
		/* increase gain */				
		else if(isp_capture_pregain < camera_oper_data.pregain_max)
		{
			isp_capture_pregain=isp_capture_pregain*target_lum/curr_lum;
			if(isp_capture_pregain>camera_oper_data.pregain_max)
				isp_capture_pregain=camera_oper_data.pregain_max;
			
			ae_set_pregain(isp_capture_pregain);			
			device_support_info.autoflash.sensorgain=sensor_pregain;		
			device_support_info.autoflash.ispgain=isp_pregain;
		}
		else
			ret_code = KAL_FALSE;
	}		
	else 
	{		
		/* decrease gain first */						
		if(isp_capture_pregain > camera_oper_data.pregain_min)
		{
			isp_capture_pregain=isp_capture_pregain*target_lum/curr_lum;
			if(isp_capture_pregain<camera_oper_data.pregain_min)
				isp_capture_pregain=camera_oper_data.pregain_min;
			
			ae_set_pregain(isp_capture_pregain);	
			device_support_info.autoflash.sensorgain=sensor_pregain;		
			device_support_info.autoflash.ispgain=isp_pregain;
		}				
		/* decrease shutter */								
		else if(device_support_info.autoflash.shutter > device_support_info.autoflash.min_shutter)
		{
			device_support_info.autoflash.shutter = device_support_info.autoflash.shutter*target_lum/curr_lum;
			if(device_support_info.autoflash.shutter<device_support_info.autoflash.min_shutter)
				device_support_info.autoflash.shutter = device_support_info.autoflash.min_shutter;
		}						
		/* decrease duty */			
		else if(device_support_info.autoflash.duty > 0)		
		{
			device_support_info.autoflash.duty = device_support_info.autoflash.duty*target_lum/curr_lum;
			if(device_support_info.autoflash.duty == 0)
				device_support_info.autoflash.duty = 1;			
		}			
		else
			ret_code = KAL_FALSE;		
	}	
	return ret_code;		
}

/* ISO priority */
/* call this function before capture image of ISO mode */
kal_bool isp_device_iso_capture_set(kal_uint8 select)
{
	isp_device_backup_gamma_enable= REG_ISP_COLOR_PROCESS_STAGE_CTRL2;
	if (0 == select)/* SRGB method */
	{
		DISABLE_GAMMA_FUNCTION_BYPASS;
	}	
	else/* linear domain */
	{
		ENABLE_GAMMA_FUNCTION_BYPASS;
	}
	return KAL_TRUE;
}

/* must call this function before end of capture image of ISO mode */
kal_bool isp_device_iso_capture_restore(void)
{
	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 = isp_device_backup_gamma_enable;
	return KAL_TRUE;	
}

kal_bool isp_device_iso_set_gain(const kal_uint16 gain[3])
{
	camera_para.ISO_PRIORITY_INFO.ISO_Gain[0] = gain[0];
	camera_para.ISO_PRIORITY_INFO.ISO_Gain[1] = gain[1];
	camera_para.ISO_PRIORITY_INFO.ISO_Gain[2] = gain[2];	
	return KAL_TRUE;
}

kal_bool isp_device_iso_get_gain(kal_uint16 gain[3]) 
{
	gain[0] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[0];
	gain[1] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[1];
	gain[2] = camera_para.ISO_PRIORITY_INFO.ISO_Gain[2];
	return KAL_TRUE;
}

kal_bool isp_device_iso_set_value(const kal_uint16 value[3])
{
	camera_para.ISO_PRIORITY_INFO.ISO_Value[0] = value[0];
	camera_para.ISO_PRIORITY_INFO.ISO_Value[1] = value[1];
	camera_para.ISO_PRIORITY_INFO.ISO_Value[2] = value[2];	
	return KAL_TRUE;
}

kal_bool isp_device_iso_get_value(kal_uint16 value[3]) 
{
	value[0] = camera_para.ISO_PRIORITY_INFO.ISO_Value[0];
	value[1] = camera_para.ISO_PRIORITY_INFO.ISO_Value[1];
	value[2] = camera_para.ISO_PRIORITY_INFO.ISO_Value[2];
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	isp_cdt_get_flashlight_charge_level_count
*
* DESCRIPTION
*	This function is to get flashlight charge level count
*
* PARAMETERS
*	none
*
* RETURNS
*	0: do not need charge ; others: charge level count   
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32  isp_cdt_get_flashlight_charge_level_count(void)
{
    kal_uint32 count=0;
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
    if( (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_SCR)||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_IGBT))
    {
        count = p_xenon_func->xenon_get_charge_level_count();
    }
#endif
    return count;                	
}

/*************************************************************************
* FUNCTION
*	isp_cdt_set_flashlight_charge_level_count
*
* DESCRIPTION
*	This function is to set flashlight charge level count
*
* PARAMETERS
*	level: set charge level
*
* RETURNS
*	KAL_TRUE/KAL_FALSE: success/fail
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool isp_cdt_set_flashlight_charge_level_count(kal_uint32 level)
{
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
    if( (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_SCR)||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_IGBT))
    {
        return KAL_TRUE;
    }
#endif
    return KAL_FALSE;
}


/*************************************************************************
* FUNCTION
*	isp_cdt_set_flashlight_ae_index
*
* DESCRIPTION
*	This function is to set flashlight ae index
*
* PARAMETERS
*	ae_index: set ae index
*
* RETURNS
*	KAL_TRUE/KAL_FALSE: success/fail
*
* GLOBALS AFFECTED
*
*************************************************************************/
exposure_lut_struct isp_cdt_set_flashlight_ae_index(kal_uint8 ae_index)
{       
    AE_INDEX = ae_index;    
	eShutter=AE_LUT[AE_INDEX].shutter;		
	sensor_pregain=AE_LUT[AE_INDEX].sensorgain;
	isp_pregain=AE_LUT[AE_INDEX].ispgain;		    
	pregain=(sensor_pregain*isp_pregain)>>6;		                        
    /* update flash light shutter/gain */          
	image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
	image_sensor_func->set_sensor_gain(sensor_pregain);           	
	ae_set_isp_pregain();    				
     
    return AE_LUT[AE_INDEX];
}

/*************************************************************************
* FUNCTION
*	isp_cdt_set_flashlight_ae_index
*
* DESCRIPTION
*	This function is to set flashlight ae index
*
* PARAMETERS
*	ae_index: set ae index
*
* RETURNS
*	KAL_TRUE/KAL_FALSE: success/fail
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 isp_cdt_get_current_ae_index(void)
{       
    return AE_INDEX;
}

/*************************************************************************
* FUNCTION
*	isp_cdt_get_flashlight_mode
*
* DESCRIPTION
*	This function is return FLASHLIGHT_TYPE
*
* PARAMETERS
*	NONE
*
* RETURNS
*	flash light mode(FLASHLIGHT_TYPE)
*   FLASHLIGHT_NONE = 0,
*	FLASHLIGHT_LED_ONOFF,           // LED always on/off
*	FLASHLIGHT_LED_CONSTANT,	    // CONSTANT type LED
*	FLASHLIGHT_LED_PEAK,	        // peak strobe type LED	
*	FLASHLIGHT_XENON_SCR,	        // SCR strobe type Xenon		
*	FLASHLIGHT_XENON_IGBT	        // IGBT strobe type Xenon			
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8  isp_cdt_get_flashlight_mode(void)
{
    kal_uint8   mode;
    mode = camera_oper_data.flashlight_mode;
    // Error Check
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
    if((mode!=FLASHLIGHT_XENON_SCR)&&(mode!=FLASHLIGHT_XENON_IGBT))
        mode = FLASHLIGHT_NONE;                   
#else          	
    if((mode==FLASHLIGHT_XENON_SCR)||(mode==FLASHLIGHT_XENON_IGBT))
        mode = FLASHLIGHT_NONE;                   
#endif            
    
    return mode;
}

/*************************************************************************
* FUNCTION
*	isp_device_xenon_flashligh_charge
*
* DESCRIPTION
*	This function is to start/stop charge xenon flash
*
* PARAMETERS
*	flashlight_cdt_charge_struct:
*       charge_on   -   charge status after charge ready
*       timeout_ms  -   timeout(ms), stop charge if timeout
*
* RETURNS
*	charge time, ms
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 isp_device_flashligh_charge(flashlight_cdt_charge_struct *isp_charge_data)
{
    kal_uint32 charge_time=0;      
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
	kal_uint32 start_time;
	kal_uint32 ret_code;
	xenon_para_struct para;
	
	para.voltage = 0xffff;	
    ret_code = p_xenon_func->xenon_charge(KAL_TRUE, &para);    
    if(ret_code==KAL_FALSE)
    {   // charge fail
        return isp_charge_data->timeout_ms;        
    }
	start_time = drv_get_current_time();        
	while(1)
	{
        ret_code = p_xenon_func->get_xenon_ready_status(&para);
        charge_time = drv_get_duration_ms(start_time);
        if(ret_code == XENON_RETCODE_READY)
            break;
        else if(charge_time>=(isp_charge_data->timeout_ms))
        {
	        charge_time = isp_charge_data->timeout_ms;            
	        break;
        }            
    }
    if(isp_charge_data->charge_on == KAL_FALSE)
    {
        p_xenon_func->xenon_charge(KAL_FALSE, &para);   
    }
    else
    {
        p_xenon_func->xenon_charge(KAL_TRUE, &para);   
    }    
#endif    
    return charge_time;
}

/*************************************************************************
* FUNCTION
*	isp_device_flashligh_strobe
*
* DESCRIPTION
*	This function is to start/stop charge xenon flash
*
* PARAMETERS
*	flashlight_cdt_strobe_struct
*   timeout_ms - timeout(ms), stop charge if timeout
*
* RETURNS
*	charge time ,ms
*
* GLOBALS AFFECTED
*
*************************************************************************/
void isp_device_flashligh_strobe(flashlight_cdt_strobe_struct *strobe_data)
{
    kal_bool    switch_mode=KAL_FALSE;
	kal_uint32 event_group;	        
    kal_uint32  grab_pixel, grab_line; 
    DISABLE_VIEW_FINDER_MODE;                    

    grab_pixel = REG_ISP_TG_GRAB_RANGE_PIXEL_CONFIG;
    grab_line = REG_ISP_TG_GRAB_RANGE_LINE_CONFIG;            	
    if( (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_CONSTANT) ||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_PEAK) )
    {   /* Turn on LED */
        if(image_sensor_func->set_flashlight!=0)
            image_sensor_func->set_flashlight(KAL_TRUE);                 
    }        

    if( (strobe_data->strobe_width > exposure_window.exposure_window_width)||
        (strobe_data->strobe_height > exposure_window.exposure_window_height) )
    {
        exposure_window.digital_zoom_factor=10;
        image_sensor_func->sensor_capture_setting(&exposure_window,&sensor_config_data);
        //image_sensor_func->set_sensor_eshutter(strobe_data->strobe_offset);
        // Modify Grab window
        SET_TG_GRAB_PIXEL(exposure_window.grab_start_x,exposure_window.exposure_window_width);
        SET_TG_GRAB_LINE(exposure_window.grab_start_y,exposure_window.exposure_window_height);
        
        switch_mode=KAL_TRUE;
    }

    kal_set_eg_events(camera_isp_event_id,0,KAL_AND);      
    DISABLE_FLASH_LIGHT;                    
    flash_config(strobe_data->strobe_offset, strobe_data->strobe_duty);

    ENABLE_FLASH_LIGHT;
    ENABLE_VIEW_FINDER_MODE;          
    kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
            &event_group,KAL_SUSPEND);                

        /* Wait 2 Frames*/        
        kal_set_eg_events(camera_isp_event_id,0,KAL_AND);              
        kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
            &event_group,KAL_SUSPEND);                
    kal_set_eg_events(camera_isp_event_id,0,KAL_AND);              
    kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
        &event_group,KAL_SUSPEND);                                    
    if(switch_mode==KAL_TRUE)
    {
        image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);
        //image_sensor_func->set_sensor_eshutter(eShutter);        
        // restore grab window
        REG_ISP_TG_GRAB_RANGE_PIXEL_CONFIG = grab_pixel;
        REG_ISP_TG_GRAB_RANGE_LINE_CONFIG = grab_line;        
    }

    if( (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_CONSTANT) ||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_PEAK) )
    {   /* Turn off LED */
        if(image_sensor_func->set_flashlight!=0)
            image_sensor_func->set_flashlight(KAL_FALSE);                 
    }              
    DISABLE_FLASH_LIGHT;                            
}

/*************************************************************************
* FUNCTION
*	isp_device_flashligh_capture_config
*
* DESCRIPTION
*	This function is to start/stop charge xenon flash
*
* PARAMETERS
*   isp_cdt_data - flashlight_cdt_capture_struct
*
* RETURNS
*	strobe times
*
* GLOBALS AFFECTED
*
*************************************************************************/
exposure_lut_struct isp_device_flashligh_capture_config(flashlight_cdt_capture_struct *pData)
{
    memcpy(&isp_cdt_data, pData, sizeof(flashlight_cdt_capture_struct));
    AE_INDEX = isp_cdt_data.ae_index;

    // bypass gamma        
    ENABLE_GAMMA_FUNCTION_BYPASS;
    // bypass CCM
    SET_COLOR_MATRIX1(0x20, 0x80, 0x80);
    SET_COLOR_MATRIX2(0x80, 0x20, 0x80);
    SET_COLOR_MATRIX3(0x80, 0x80, 0x20);        
    // disable edge
    DISABLE_RGB_EDGE_GAIN;
    DISABLE_Y_EDGE;
    // restore sat
    SET_HUE_U_GAIN(0x20);
    SET_HUE_V_GAIN(0x20);
    
    return AE_LUT[AE_INDEX];
}

/*************************************************************************
*	isp device flashligh capture related functions
*************************************************************************/
kal_uint8 isp_device_flashligh_prestrobe(camera_capture_cct_struct *isp_cct_data)
{    // Pre Strobe    
	kal_uint32 event_group;	            
    isp_cct_data->grab_width = isp_cdt_data.strobe_width;
    isp_cct_data->grab_height= isp_cdt_data.strobe_height;    
    
    if(isp_cdt_data.prestrobe_en == KAL_FALSE)
        return KAL_FALSE;
    if( (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_CONSTANT) ||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_PEAK) ||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_IGBT) )
    {
        if(isp_cdt_data.prestrobe_duty>0)        
        {
            int i;            
            DISABLE_FLASH_LIGHT;                    
            flash_config(exposure_window.exposure_window_height, isp_cdt_data.prestrobe_duty); 
            for(i=0;i<isp_cdt_data.prestrobe_times;i++)            
            {            
                DISABLE_FLASH_LIGHT;                                        
                kal_set_eg_events(camera_isp_event_id,0,KAL_AND);              
                kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
                    &event_group,KAL_SUSPEND);                                            
                    
                ENABLE_FLASH_LIGHT;        
                ENABLE_VIEW_FINDER_MODE;            
                kal_set_eg_events(camera_isp_event_id,0,KAL_AND);              
                kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
                    &event_group,KAL_SUSPEND);                            
                // Wait 2 Frames                  	                    
                kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
                kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
                    &event_group,KAL_SUSPEND);                            
            }
        }
    }
    return KAL_TRUE;    
}

kal_uint8 isp_device_flashligh_aeawb(camera_capture_cct_struct *isp_cct_data)
{
    kal_uint8   ret_code = KAL_FALSE;
   
    // Update AWB
    if(isp_cdt_data.is_awb_apply==KAL_TRUE)
    {
        if(isp_cdt_data.rgain<128)
            AWB_Rgain = 128;
        else            
    	    AWB_Rgain = isp_cdt_data.rgain; 	
        if(isp_cdt_data.ggain<128)
            AWB_GRgain = AWB_GBgain = 128;
        else            
    	    AWB_GRgain = AWB_GBgain = isp_cdt_data.ggain; 		
        if(isp_cdt_data.bgain<128)
            AWB_Bgain = 128;            
        else            
    	    AWB_Bgain = isp_cdt_data.bgain;
    	    awb_set_gain();
    }
    // Update AE
    AE_INDEX = isp_cdt_data.ae_index;
	eShutter=AE_LUT[AE_INDEX].shutter;		
	sensor_pregain=AE_LUT[AE_INDEX].sensorgain;
	isp_pregain=AE_LUT[AE_INDEX].ispgain;		    
	pregain=(sensor_pregain*isp_pregain)>>6;		                        	
    /* update flash light shutter/gain */   
	image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
	image_sensor_func->set_sensor_gain(sensor_pregain);           	
	ae_set_isp_pregain();    				

	return ret_code;
}

kal_uint8 isp_device_flashligh_mainstrobe(camera_capture_cct_struct *isp_cct_data)
{   // Anti-RedEye and MainStrobe    
	kal_uint32 event_group;    
    if( (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_CONSTANT) ||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_PEAK) )
    {    
    	if(sensor_config_data.enable_flashlight_tansfer == KAL_TRUE)	
    		flash_config(device_support_info.autoflash.offset,device_support_info.autoflash.duty);							
    	// FlashLight Trigger & Enable Pin Config
    	ENABLE_FLASH_LIGHT;
    	if(image_sensor_func->set_flashlight!=0)
    		image_sensor_func->set_flashlight(KAL_TRUE);		
    }
    else if((camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_SCR) ||
            (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_IGBT) )
    {    
        // Red Eye
        if((isp_cdt_data.redeye_en==KAL_TRUE) && (isp_cdt_data.redeye_duty>0))
        {   
    	    DISABLE_VIEW_FINDER_MODE;        
        	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);	    
            DISABLE_FLASH_LIGHT;                    
            flash_config(isp_cdt_data.redeye_offset, isp_cdt_data.redeye_duty);
	
            ENABLE_FLASH_LIGHT;        
            ENABLE_VIEW_FINDER_MODE;            
            kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
              	                    &event_group,KAL_SUSPEND);                       
            DISABLE_VIEW_FINDER_MODE;
            kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
            ENABLE_VIEW_FINDER_MODE;            
            kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                                &event_group,KAL_SUSPEND);
            DISABLE_FLASH_LIGHT;                                        
        }
        // Main Strobe
        if(isp_cdt_data.mainstrobe_duty>0)
        {
    	    DISABLE_VIEW_FINDER_MODE;        
        	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);	    
            DISABLE_FLASH_LIGHT;                    
            flash_config(isp_cdt_data.strobe_height, isp_cdt_data.mainstrobe_duty);               
            ENABLE_FLASH_LIGHT;        
            ENABLE_VIEW_FINDER_MODE;            
            kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
              	                    &event_group,KAL_SUSPEND);                       
        	DISABLE_VIEW_FINDER_MODE;
        	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);          	                    
        }
    }    
    return KAL_TRUE;
}

void isp_device_flashligh_enable(kal_bool on)
{    // Open/Close Strobe
    if(on==KAL_TRUE)
    {
        if(image_sensor_func->set_flashlight!=0)
            image_sensor_func->set_flashlight(KAL_TRUE);
    }
    else
    {   /* FlashLight Disnable Pin Config */	
        DISABLE_FLASH_LIGHT;
        if(image_sensor_func->set_flashlight!=0)
            image_sensor_func->set_flashlight(KAL_FALSE);        
    }
}
#endif  // defined(ISP_SUPPORT)
