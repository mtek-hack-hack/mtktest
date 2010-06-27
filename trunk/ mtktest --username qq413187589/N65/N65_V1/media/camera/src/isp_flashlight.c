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
 *   isp_flashlight.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   flash light control
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h"
#if ((defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))&&defined(ISP_SUPPORT))
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
#include "isp_flashlight.h"

/**************   FLASH LIGHT DECLARATION    ***************************************/
extern kal_eventgrpid camera_isp_event_id;
extern kal_bool ae_counting_flag;

FLASHLIGHT_OPERATION_STATE_ENUM flashlight_operation_state=FLASHLIGHT_STANDBY_STATE;
kal_uint16	AWB_Rgain_Backup,AWB_GRgain_Backup,AWB_Bgain_Backup,AWB_GBgain_Backup;
kal_uint8 AE_INDEX_Backup;
kal_bool fake_main_flash_frame_flag, fake_sub_flash_frame_flag;
kal_int32  flashlight_idx, flashlight_main_idx; 
kal_uint32 flashlight_lum, flashlight_main_lum;
kal_uint16  flashlight_sensor_gain, flashlight_isp_gain;
kal_uint8   flashlight_awb_idx, flashlight_awb_weight;
kal_uint16  flashlight_awb_r_backup, flashlight_awb_g_backup, flashlight_awb_b_backup;
kal_uint32  flash_ae_info = 0;

int flashlight_miss_count = 0;

const kal_uint16 EVSTEP_FLASH_01[FLASHLIGHT_MAX_AE_RANGE+1]={    
    23, 24, 26, 27, 29, 32, 34, 37, 40, 42, 45, 49, 52, 56, 59,     // 0~14
    65, 70, 73, 80, 85, 91, 98, 104, 112, 120, 128,                 // 15~25
    137, 148, 158, 169, 181, 195, 208, 223, 240, 257, 274, 294, 315, 337, 361, 387, 414};

// Customize Sensor Driver Parameters
flashlight_preview_para_struct flashlight_preview_para;
flashlight_capture_para_struct flashlight_capture_para;

/****************************************************************************
 *          Flash Light	Control 											 *
 ****************************************************************************/
/*************************************************************************
* FUNCTION
*	flash_config
*
* DESCRIPTION
*	Config flash light offset and duty
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
void flash_config(kal_uint16 delay_line,kal_uint16 duty_line)
{
    kal_uint32   line_number;
	/* Delay time setting since Vsync occured */
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))	
	if( delay_line >= 2048)
		delay_line = 2047;
	REG_ISP_INT_ENABLE &= ~0xFF0000;
	REG_ISP_INT_ENABLE |= ((delay_line>>3)<<16);
#elif (defined(DRV_ISP_6227_SERIES))
	REG_ISP_INT_ENABLE &= ~0xFFF0000;
	REG_ISP_INT_ENABLE |= ((delay_line&0xFFF)<<16);
#endif	
    line_number = (duty_line/((duty_line>>8)+1));
    if(line_number>0)   // line number start with 0
        line_number = line_number-1;
	/* Flash turn on time setting */
	SET_FLASH_LINE_UNIT(duty_line>>8);
	SET_FLASH_LINE_NUMBER(line_number);
}


/*************************************************************************
* FUNCTION
*	init_flashlight
*
* DESCRIPTION
*	Initial flash light GPIO and state machine
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
void init_flashlight(void)
{
    flashlight_operation_state = FLASHLIGHT_STANDBY_STATE;
	if(dsc_support_info.dsccomp.flashlight==KAL_TRUE)
	{	
      if((camera_oper_data.flashlight_mode==FLASHLIGHT_LED_ONOFF) || 
         (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_CONSTANT) )
      {
         DISABLE_FLASH_LIGHT;	        
      }
      else if( (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_PEAK)||
               (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_SCR)|| 
               (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_IGBT))
      {
#if (defined(DRV_ISP_6227_SERIES))
        #ifndef __CUST_NEW__
         GPIO_ModeSetup(6,3);	/* Flash Triger Pin */
        #endif /* __CUST_NEW__ */
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
        #ifndef __CUST_NEW__
         GPIO_ModeSetup(0,1);	/* Flash Triger Pin */
        #endif /* __CUST_NEW__ */
#endif
         DISABLE_FLASH_LIGHT;
         SET_FLASH_STARTPNT_LOW;
         SET_FLASH_FRAME_DELAY(1);
         flash_config(device_support_info.autoflash.offset,device_support_info.autoflash.duty);
         if(device_support_info.autoflash.strobe_pol==1)
         {
            SET_FLASH_POL_HIGH;
         }
         else
         {
            SET_FLASH_POL_LOW;
         }
      }
      else  // default
        camera_oper_data.flashlight_mode = FLASHLIGHT_LED_PEAK;      
   }	    	       
}

/*************************************************************************
* FUNCTION
*	flashlight_pre_process
*
* DESCRIPTION
*	Pre strobe Entry point
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
void flashlight_pre_process(void)
{
	/* store AWB setting */
	AWB_Rgain_Backup = AWB_Rgain;			
	AWB_GRgain_Backup = AWB_GRgain;			
	AWB_Bgain_Backup = AWB_Bgain;			
	AWB_GBgain_Backup = AWB_GBgain;		        
    AE_INDEX_Backup = AE_INDEX; 	
    sensor_config_data.enable_flashlight_tansfer = KAL_FALSE;
    flashlight_miss_count = 0;    
    /* FlashLight Shutter Config */	
    if( (dsc_support_info.dsccomp.flashlight==KAL_TRUE)&&
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
        (isp_preview_config_data.wb_mode!=CAM_WB_MANUAL)&& 
#endif        
       (dsc_status.ae.flash!=CAM_FLASH_OFF)&&
       ((camera_oper_data.flashlight_mode==FLASHLIGHT_LED_CONSTANT) ||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_LED_PEAK) ||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_SCR) ||
        (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_IGBT)) )
        {
            if( (dsc_status.ae.flash==CAM_FLASH_ON) ||
                ((dsc_status.ae.flash==CAM_FLASH_AUTO||dsc_status.ae.flash==CAM_FLASH_REDEYE)&&
                (AE_INDEX<=device_support_info.autoflash.lutidx)))    
            {
                awb_fast_method(KAL_TRUE);                            
                flashlight_prestrobe();                                         
                flashlight_operation_state = FLASHLIGHT_MAIN_STROBE_STATE;                     
            }   
            else
            {
                sensor_config_data.enable_flashlight_tansfer = KAL_FALSE;                                           
                flashlight_operation_state = FLASHLIGHT_STANDBY_STATE;
            }       
   }
   else
   {
      fake_sub_flash_frame_flag = KAL_TRUE; 
      flashlight_operation_state = FLASHLIGHT_STANDBY_STATE;      
   }
}

/*************************************************************************
* FUNCTION
*	flashlight_redeye_process
*
* DESCRIPTION
*	Flash light anti-redeye control and capture stable loop
*
* PARAMETERS
*	capture_delay_frame
*
* RETURNS
*	redeye strobe or not
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool flashlight_redeye_process(kal_uint32  capture_delay_frame)
{
    kal_uint32  event_group;    
    
    // If not strobe state, return
    if(flashlight_operation_state == FLASHLIGHT_STANDBY_STATE)
        return KAL_FALSE;
    
    return flashlight_redeye(capture_delay_frame);
}

/*************************************************************************
* FUNCTION
*	flashlight_post_process
*
* DESCRIPTION
*	Flash light post control for capture timing switch
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
void flashlight_post_process(void)
{
    // If not strobe state, return
    if(flashlight_operation_state == FLASHLIGHT_STANDBY_STATE)
        return;
    flashlight_poststrobe();
    awb_fast_method(KAL_FALSE);        
}

/*************************************************************************
* FUNCTION
*	flashlight_trigger_process
*
* DESCRIPTION
*	Flash light trigger process. 
*   This function should right before open image data base.
*   From trigger process to enable capture should < 1 frame time.
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
void flashlight_trigger_process(void)
{    
    // If not strobe state, return
    if(flashlight_operation_state == FLASHLIGHT_STANDBY_STATE)
        return;
    // FlashLight Trigger & Enable Pin Config
    if((dsc_support_info.dsccomp.flashlight==KAL_TRUE)&&(dsc_status.ae.flash!=CAM_FLASH_OFF))
    {       
        flashlight_trigger();
    }    
}

/*************************************************************************
* FUNCTION
*	flashlight_stop_process
*
* DESCRIPTION
*	Flash light stop process. 
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
void flashlight_stop_process(void)
{    
    // If not strobe state, return
    if(flashlight_operation_state == FLASHLIGHT_STANDBY_STATE)
        return;
        
        SET_CAMERA_FRAME_RATE(0);			    
		DISABLE_FLASH_LIGHT;
		if(image_sensor_func->set_flashlight!=0)
			image_sensor_func->set_flashlight(KAL_FALSE);
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
		if(p_xenon_func->xenon_strobe!=0) 
            p_xenon_func->xenon_strobe(KAL_FALSE);
#endif            
		set_isp_interrupt_trigger_delay_lines(isp_tg_delay_lines);				
    
    if(fake_sub_flash_frame_flag == KAL_FALSE)       
        {  	/* store AE/AWB setting */
        	AWB_Rgain = AWB_Rgain_Backup;
        	AWB_GRgain = AWB_GRgain_Backup;			
        	AWB_Bgain = AWB_Bgain_Backup;			
        	AWB_GBgain = AWB_GBgain_Backup;
        	AE_INDEX = AE_INDEX_Backup;
        	eShutter=AE_LUT[AE_INDEX].shutter;		
        	sensor_pregain = ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);
        	isp_pregain=AE_LUT[AE_INDEX].ispgain;
        	pregain=sensor_pregain*isp_pregain/0x40;
        	image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
            image_sensor_func->set_sensor_gain(sensor_pregain);
            ae_set_isp_pregain();        	
            awb_set_gain();  
        }    	
		flashlight_operation_state = FLASHLIGHT_STANDBY_STATE;    	
}

#if (!(defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT)))		
/*****************************************************************************/
/*                           LED Flash Functions                             */
/*****************************************************************************/
/*************************************************************************
* FUNCTION
*	flashlight_prestrobe (LED)
*
* DESCRIPTION
*	LED Pre strobe AE/AWB control
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
void flashlight_prestrobe(void)
{  
    kal_uint32  event_group;
    
    /* Turn on LED */
    if(image_sensor_func->set_flashlight!=0)
        image_sensor_func->set_flashlight(KAL_TRUE);         

    /* Wait 1 AE AWB HW CAL Stable */            
    DISABLE_VIEW_FINDER_MODE;            
    kal_set_eg_events(camera_isp_event_id,0,KAL_AND);                        	    
    fake_main_flash_frame_flag = fake_sub_flash_frame_flag = KAL_TRUE;    		    
    flashlight_main_lum = flashlight_main_idx = 0;
    flashlight_lum = flashlight_idx = 0;                            
    ENABLE_VIEW_FINDER_MODE;            
    kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
            &event_group,KAL_SUSPEND);

    /* Set FLASHLIGHT_PRE_STROBE_STATE to trigger flashlight HISR */ 
    DISABLE_VIEW_FINDER_MODE;         
    kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
    IRQMask(IRQ_CAMERA_CODE);    	    
    flashlight_operation_state = FLASHLIGHT_PRE_STROBE_STATE;
    IRQUnmask(IRQ_CAMERA_CODE);            
    ENABLE_VIEW_FINDER_MODE;            
    kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
            &event_group,KAL_SUSPEND);
    DISABLE_VIEW_FINDER_MODE;      
    /* Check frame end */               
    kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);        
    
    if(fake_sub_flash_frame_flag == KAL_FALSE)       
	    image_sensor_func->set_sensor_gain(sensor_pregain);                    
    if(fake_main_flash_frame_flag == KAL_FALSE)
        sensor_config_data.enable_flashlight_tansfer = KAL_TRUE;                                                      
}

/*************************************************************************
* FUNCTION
*	flashlight_poststrobe (LED)
*
* DESCRIPTION
*	LED Post strobe AE/AWB control
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
void flashlight_poststrobe(void)
{
    kal_uint32  event_group;    
    // LED flash strobe   
    if(fake_sub_flash_frame_flag == KAL_TRUE)       
        return;
    
    // when sensor change shutter line number for capture timing, check if need compensate gain for it
        flashlight_sensor_gain = sensor_pregain;
        flashlight_isp_gain = isp_pregain;    
        if( sensor_config_data.enable_flashlight_tansfer==KAL_TRUE )    
        {
            if( sensor_config_data.flashlight_duty>0 )
            {
                if(sensor_config_data.flashlight_shut_factor!=BASEGAIN)            
                {
                    flashlight_sensor_gain = (sensor_pregain*BASEGAIN)/sensor_config_data.flashlight_shut_factor;
                    if(flashlight_sensor_gain >= device_support_info.ae.sensor_basegain)   
                	    image_sensor_func->set_sensor_gain(flashlight_sensor_gain);            
                    else
                    {           
                        flashlight_sensor_gain = device_support_info.ae.sensor_basegain;
                	    image_sensor_func->set_sensor_gain(flashlight_sensor_gain);
                        if(flashlight_isp_gain>BASEGAIN)
                        {
                            flashlight_isp_gain = ((isp_pregain*sensor_pregain)<<6)/
                                                  (flashlight_sensor_gain*sensor_config_data.flashlight_shut_factor);
                            if(flashlight_isp_gain < BASEGAIN)
                                flashlight_isp_gain = BASEGAIN;
                   			isp_pregain=flashlight_isp_gain;		                        
                           	ae_set_isp_pregain();    			            
                        }                    
                    }                
                }                
            }            
            else
            {   /* Turn off Main strobe */
                AE_INDEX -= flashlight_main_idx;            
                AE_INDEX += flashlight_idx;            
                sensor_config_data.enable_flashlight_tansfer=KAL_FALSE;
                fake_main_flash_frame_flag = KAL_TRUE;
                /* update flash light gain to cover index shift */
    			sensor_pregain=ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);
    			isp_pregain = (AE_LUT[AE_INDEX].ispgain)*(AE_LUT[AE_INDEX].shutter)/eShutter ;			
			pregain=(sensor_pregain*isp_pregain)>>6;		                        
            	image_sensor_func->set_sensor_gain(sensor_pregain);
            	ae_set_isp_pregain();    			
            }
        }    	

        /* cal AWB and Wait 1 frame for AWB and AE stable */    	
        DISABLE_VIEW_FINDER_MODE;
   		awb_proc();                				                
    	awb_set_gain();           		            
        kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
        ENABLE_VIEW_FINDER_MODE;            
        kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                        &event_group,KAL_SUSPEND);        	                          
    }        

/*************************************************************************
* FUNCTION
*	flashlight_redeye
*
* DESCRIPTION
*	Flash light anti-redeye control and capture stable loop
*
* PARAMETERS
*	capture_delay_frame
*
* RETURNS
*	redeye strobe or not
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool flashlight_redeye(kal_uint32  capture_delay_frame)
{
    return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*	flashlight_trigger (LED)
*
* DESCRIPTION
*	Flash light trigger process. 
*   This function should right before open image data base.
*   From trigger process to enable capture should < 1 frame time.
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
void flashlight_trigger(void)
{    
    kal_uint32  event_group;    
        if(fake_sub_flash_frame_flag == KAL_TRUE)   
        {   /* turn off sub flash light */
     		if(image_sensor_func->set_flashlight!=0)
    			image_sensor_func->set_flashlight(KAL_FALSE);           
        }        
        else
        {   /* turn on main flash light */
            if( (fake_main_flash_frame_flag==KAL_FALSE)&&
                (sensor_config_data.enable_flashlight_tansfer == KAL_TRUE))	
            {
                DISABLE_VIEW_FINDER_MODE;
                kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
                flashlight_operation_state = FLASHLIGHT_TRIGGER_STATE;                
                ENABLE_VIEW_FINDER_MODE;                
                kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
      	                    &event_group,KAL_SUSPEND);      	                    
            }                
            flashlight_operation_state = FLASHLIGHT_MAIN_STROBE_STATE;
        }  
}

/*************************************************************************
* FUNCTION
*	flashlight_hisr (LED Flash)
*
* DESCRIPTION
*	Entry function of Flash light HISR
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
void flashlight_hisr(void)
{
    if(flashlight_operation_state == FLASHLIGHT_TRIGGER_STATE)
    {
        flash_config(sensor_config_data.flashlight_offset, sensor_config_data.flashlight_duty);        
        SET_CAMERA_FRAME_RATE(1);
    	DISABLE_CAMERA_VD_DONE_INT;
        ENABLE_FLASH_LIGHT;
        flashlight_operation_state = FLASHLIGHT_TRIGGER_DONE_STATE;
    }
    else
    {
    	#if (defined(DRV_ISP_6227_SERIES))
    	if(ae_counting_flag==KAL_TRUE) //Avoid ae get accumulation frame
    	#else	// MT6228||MT6229
    	if(AE_FRAME_COUNT==1) //Avoid ae get accumulation frame
    	#endif
    	{   /* get valid ae/awb data */
            flashlight_lum = flashlight_ae_cal();    	
            AE_INDEX = flashlight_ae_proc();
            /* check if main strobe needed, and then update shutter/gain */
            if(fake_sub_flash_frame_flag==KAL_FALSE) 
            {         		                   
    			eShutter=AE_LUT[AE_INDEX].shutter;		
    			sensor_pregain = ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);
    			isp_pregain=AE_LUT[AE_INDEX].ispgain;		
    			pregain=(sensor_pregain*isp_pregain)>>6;		                        
                /* update flash light shutter/gain */          
            	image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
                image_sensor_func->set_sensor_gain(sensor_pregain);            	
            	ae_set_isp_pregain();    			
            }   // fake_sub_flash_frame_flag==KAL_FALSE
            flashlight_operation_state = FLASHLIGHT_PRE_STROBE_DONE_STATE;        
        }   // AE_FRAME_COUNT = 1
        else
        {
            flashlight_miss_count++;
            if(flashlight_miss_count>12)
            {
                fake_sub_flash_frame_flag = KAL_TRUE;  
                fake_main_flash_frame_flag = KAL_TRUE;                  
                flashlight_operation_state = FLASHLIGHT_PRE_STROBE_DONE_STATE;                        
            }                
        }
    }   // FLASHLIGHT_PRE_STROBE_STATE
}
            
/*****************************************************************************/
/*                       Customize Sensor Interface                          */
/*****************************************************************************/
void flashlight_sensor_preview_config( flashlight_preview_para_struct *para,
                                image_sensor_config_struct *sensor_config_data)
{  
}

kal_uint32 flashlight_sensor_capture_config(   flashlight_capture_para_struct *para,
                                        image_sensor_config_struct *sensor_config_data)
{
    kal_uint32  shutter = para->shutter;    
#if (!defined(DRV_ISP_6219_SERIES))	
	/*Flash Light Shutter/Duty */		
	if(sensor_config_data->enable_flashlight_tansfer==KAL_TRUE)
	{
		kal_uint32 ori_shutter = shutter;				
		/* cal offset: valid line after VD falling edge */
  		sensor_config_data->flashlight_offset = para->lines;
		/* cal shutter and factor, must > flashlight_offset */
	    sensor_config_data->flashlight_shut_factor = BASEGAIN;         /* /1 */ 
        if((shutter<<1)>(sensor_config_data->flashlight_offset))
            sensor_config_data->flashlight_shut_factor = BASEGAIN*2;   /* /2 */
        else if((shutter*3)>(sensor_config_data->flashlight_offset))
            sensor_config_data->flashlight_shut_factor = BASEGAIN*3;   /* /3 */        
        else if((shutter<<2)>(sensor_config_data->flashlight_offset))
            sensor_config_data->flashlight_shut_factor = BASEGAIN*4;  /* /4, if shutter*4 still < flashlight offset, disable */
        shutter = shutter*(sensor_config_data->flashlight_shut_factor)/BASEGAIN;        
		/* cal duty , can't > device_support_info.autoflash.duty */
		if(shutter>sensor_config_data->flashlight_offset)
		{
		    kal_uint32 pixelclk, duty; 
    		if((REG_ISP_TG_PHASE_COUNTER & REG_TGPC_PIXEL_CLK_SELECT_BIT)!= 0)
    			pixelclk=((kal_uint32)(48000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));		    
            else
    		    pixelclk=((kal_uint32)(52000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));		                			
            duty = device_support_info.autoflash.duty*(pixelclk/(para->default_pclk));
            sensor_config_data->flashlight_duty = shutter - (sensor_config_data->flashlight_offset);		            
            if(sensor_config_data->flashlight_duty<1)                                            
                sensor_config_data->flashlight_duty = 1;
    		if(sensor_config_data->flashlight_duty > duty )
    		    sensor_config_data->flashlight_duty = duty;
		}
		else
		{
            sensor_config_data->flashlight_duty = 0;
            sensor_config_data->flashlight_shut_factor = BASEGAIN;            
            shutter = ori_shutter;
		}			
	}	// sensor_config_data->enable_flashlight_tansfer==KAL_TRUE	
#endif  // #if (!defined(DRV_ISP_6219_SERIES))	
    return shutter;
}
#endif //(!(defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT)))		

#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))		
/**************   FLASH LIGHT DECLARATION    ***************************************/
xenon_info_struct *p_xenon_info;
kal_bool xenon_prestrobe_flag = KAL_FALSE;
kal_uint32 xenon_prestrobe_duty_line=0;

/*****************************************************************************/
/*                          Xenon Flash Functions                            */
/*****************************************************************************/
/*************************************************************************
* FUNCTION
*	isp_xenon_flashlight_charge
*
* DESCRIPTION
*	This function is to start/stop charge xenon flash
*
* PARAMETERS
*	on - KAL_TRUE/KAL_FALSE = ON/OFF
*   voltage - current system voltage
*   info - return info
*
* RETURNS
*	charge status XENON_RETCODE_ENUM
*
* GLOBALS AFFECTED
*
*************************************************************************/
xenon_info_struct *isp_xenon_flashlight_charge(kal_bool on, xenon_para_struct *para)
{
    kal_uint8   ret_code;
    ret_code = p_xenon_func->xenon_charge(on, para);    
    return p_xenon_func->get_xenon_info();
}

/*************************************************************************
* FUNCTION
*	isp_get_xenon_flashlight_status
*
* DESCRIPTION
*	get current xenon flash charge status
*
* PARAMETERS
*	None
*
* RETURNS
*	
*
* GLOBALS AFFECTED
*
*************************************************************************/
xenon_info_struct *isp_xenon_flashlight_ready_check(xenon_para_struct *para)
{
    p_xenon_func->get_xenon_ready_status(para);
    return p_xenon_func->get_xenon_info();
}

/*************************************************************************
* FUNCTION
*	get_isp_xenon_flashlight_info
*
* DESCRIPTION
*	get current xenon flash info
*
* PARAMETERS
*	None
*
* RETURNS
*	
*
* GLOBALS AFFECTED
*
*************************************************************************/
xenon_info_struct *get_isp_xenon_flashlight_info(void)
{    
    return p_xenon_func->get_xenon_info();    
}


/*************************************************************************
* FUNCTION
*	flashlight_conv_ae (Xenon Flash)
*
* DESCRIPTION
*	Xenon Pre strobe AE index convert to target exp. target index
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
kal_bool flashlight_conv_ae(kal_uint8 curr_idx, kal_uint8 target_idx)
{
    kal_bool ret = KAL_FALSE;
    kal_uint32  curr_ae_lum, target_ae_lum, factor;
    kal_uint8   ae_index_backup = AE_INDEX;
    if((curr_idx<=device_support_info.autoflash.lutidx)&&(AE_LUT[target_idx].shutter>0))
    {
        AE_INDEX = curr_idx;
      	eShutter=AE_LUT[target_idx].shutter;		                
        factor = ((kal_uint32)AE_LUT[curr_idx].shutter<<6)/AE_LUT[target_idx].shutter;        
    	sensor_pregain = ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);
    	isp_pregain=((kal_uint32)AE_LUT[curr_idx].ispgain*factor)>>6;		            
        if(isp_pregain>0xFF)// ISP gain max 255
        {
            isp_pregain=0xFF;		                        
            sensor_pregain = (  (kal_uint32)sensor_pregain*
                                (factor*AE_LUT[curr_idx].ispgain/isp_pregain))>>6;
        }
        pregain=(sensor_pregain*isp_pregain)>>6;
        /* update flash light shutter/gain */          
    	image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
        image_sensor_func->set_sensor_gain(sensor_pregain);
        ae_set_isp_pregain();
   	    ret = KAL_TRUE;            
    }
    AE_INDEX = ae_index_backup;    
    return ret;
}

/*************************************************************************
* FUNCTION
*	flashlight_update_ae (Xenon Flash)
*
* DESCRIPTION
*	Xenon Pre strobe restore AE index
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
kal_bool flashlight_update_ae(kal_uint8 target_idx)
{
    AE_INDEX = target_idx; 
	eShutter=AE_LUT[AE_INDEX].shutter;		
	sensor_pregain = ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);
    isp_pregain=AE_LUT[AE_INDEX].ispgain;
    pregain=(sensor_pregain*isp_pregain)>>6;
    /* update flash light shutter/gain */          
	image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
    image_sensor_func->set_sensor_gain(sensor_pregain);
  	ae_set_isp_pregain();    			
   	return KAL_TRUE;
}

void flashlight_prestrobe(void)
{  
    kal_uint32  event_group;
    
    // Update Xenon flash info    
    p_xenon_info = p_xenon_func->get_xenon_info();
    if(p_xenon_func==NULL)
        ASSERT(0);
        
    // pre-strobe
    if(p_xenon_func->xenon_strobe(KAL_TRUE)==KAL_FALSE)        
    {
        fake_sub_flash_frame_flag = KAL_TRUE;            
        fake_main_flash_frame_flag = KAL_TRUE;            
    }        
    else if(camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_SCR)
    {
        fake_sub_flash_frame_flag = KAL_FALSE;            
        fake_main_flash_frame_flag = KAL_FALSE;    
    }    
    else if(camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_IGBT)
    {   /* Set FLASHLIGHT_PRE_STROBE_STATE to trigger flashlight HISR */ 
        if(AE_INDEX<=device_support_info.autoflash.lutidx)
        {   // update flash shutter and wait 1 frame
            ENABLE_VIEW_FINDER_MODE;            
            kal_set_eg_events(camera_isp_event_id,0,KAL_AND);                           	                           
            if(flashlight_conv_ae(AE_INDEX, device_support_info.autoflash.lutidx)==KAL_TRUE)
            {
            kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
                    &event_group,KAL_SUSPEND);
            }
        }     
        // Wait one more frame for start pre-strobe
            kal_set_eg_events(camera_isp_event_id,0,KAL_AND);                           	                                               
        ENABLE_VIEW_FINDER_MODE;                    
            kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
                    &event_group,KAL_SUSPEND);            
        DISABLE_VIEW_FINDER_MODE;         
        fake_main_flash_frame_flag = KAL_TRUE;
        flashlight_main_lum = flashlight_main_idx = 0;
        flashlight_lum = flashlight_idx = 0;                            
        xenon_prestrobe_duty_line = 0;
                
        IRQMask(IRQ_CAMERA_CODE);    	    
        flashlight_operation_state = FLASHLIGHT_PRE_STROBE_STATE;
        xenon_prestrobe_flag = KAL_TRUE;
        IRQUnmask(IRQ_CAMERA_CODE);       

    	ENABLE_CAMERA_IDLE_INT;
        kal_set_eg_events(camera_isp_event_id,0,KAL_AND);    	
        ENABLE_VIEW_FINDER_MODE;            
        kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR_CONSUME,
                &event_group,KAL_SUSPEND);
        DISABLE_VIEW_FINDER_MODE;      

        // check frame end
        kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                &event_group,KAL_SUSPEND);        
        DISABLE_CAMERA_IDLE_INT                
    }    
    
    if(fake_sub_flash_frame_flag==KAL_FALSE) 
    {
	    xenon_prestrobe_duty_line = sensor_config_data.flashlight_duty;
        if(fake_main_flash_frame_flag == KAL_FALSE)
            sensor_config_data.enable_flashlight_tansfer = KAL_TRUE;
	}	 
	if(fake_main_flash_frame_flag==KAL_TRUE) 
	{   // fake main strobe, restore AE index
        flashlight_update_ae(AE_INDEX_Backup);	    
	    xenon_prestrobe_duty_line = sensor_config_data.flashlight_duty;
        sensor_config_data.enable_flashlight_tansfer = KAL_FALSE;
    }
}

/*************************************************************************
* FUNCTION
*	flashlight_poststrobe (Xenon Flash)
*
* DESCRIPTION
*	Xenon Post strobe AE/AWB control
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
void flashlight_poststrobe(void)
{   // Xenon Flash Post Strobe
    kal_uint8   i = 0, startTick, durationTick, waitTick;    
    kal_uint32  event_group;    
    DISABLE_FLASH_LIGHT;	            

    //  Fake Strobe Here!           
	if(fake_main_flash_frame_flag==KAL_TRUE)
    {
        DISABLE_VIEW_FINDER_MODE;              
        DISABLE_FLASH_LIGHT;                    
        // fake strobe
        //flash_config(sensor_config_data.flashlight_offset, xenon_prestrobe_duty_line);
        flash_config(p_xenon_info->pre_strobe_duty, 1);
        ENABLE_FLASH_LIGHT;
    
    	ENABLE_CAMERA_IDLE_INT;
        kal_set_eg_events(camera_isp_event_id,0,KAL_AND);          	
        ENABLE_VIEW_FINDER_MODE;          
        // check frame end
        kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                &event_group,KAL_SUSPEND);                
        // Wait 2 Frames  
        DISABLE_VIEW_FINDER_MODE;      
        kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
        ENABLE_VIEW_FINDER_MODE;        
        kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                &event_group,KAL_SUSPEND);        
    }                    
       
}

/*************************************************************************
* FUNCTION
*	flashlight_redeye_trigger (Xenon Flash)
*
* DESCRIPTION
*	Xenon flash strobe for anti-red-eye
*
* PARAMETERS
*	None
*
* RETURNS
*	anti-red-eye/pre-strobe
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool flashlight_redeye_trigger(void)
{   // IGBT red eye           
    kal_uint32  event_group, duty=1;    
    DISABLE_FLASH_LIGHT;
    if((p_xenon_info->redeye_strobe_duty!=0)&&(p_xenon_info->pre_strobe_duty!=0))            
        duty = xenon_prestrobe_duty_line*(p_xenon_info->redeye_strobe_duty)/
                                         (p_xenon_info->pre_strobe_duty);
    flash_config(p_xenon_info->redeye_strobe_offset, duty);
    ENABLE_FLASH_LIGHT; 
    
    DISABLE_VIEW_FINDER_MODE;
    kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
    ENABLE_VIEW_FINDER_MODE;
    
    kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                        &event_group,KAL_SUSPEND);            
    return KAL_TRUE;           
}

kal_bool flashlight_redeye(kal_uint32  capture_delay_frame)
{
    kal_uint32  event_group;    

    // If not strobe state, return
    if(flashlight_operation_state == FLASHLIGHT_STANDBY_STATE)
        return KAL_FALSE;
    /* FlashLight Shutter Config */	
    if( (camera_oper_data.flashlight_mode==FLASHLIGHT_XENON_IGBT)&&          
        (dsc_status.ae.flash==CAM_FLASH_REDEYE))
    {   // wait stable and strobe for anti-red-eye
        kal_uint32  delay_frame = capture_delay_frame;
        kal_uint32  i;
        p_xenon_info = p_xenon_func->get_xenon_info();        
        if(delay_frame==0)
            delay_frame = 1;    
    	for(i=0;i<delay_frame;i++)
    	{
            if((i+1)==delay_frame)                                
                flashlight_redeye_trigger();                                            	    
            DISABLE_VIEW_FINDER_MODE;
            kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
            ENABLE_VIEW_FINDER_MODE;
            
            kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                                &event_group,KAL_SUSPEND);
        }     
        // wait frames for main strobe
        for(i=0;i<p_xenon_info->redeye_strobe_wait_frame ;i++)          
        {
            DISABLE_VIEW_FINDER_MODE;
            kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
            ENABLE_VIEW_FINDER_MODE;
            
            kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                                &event_group,KAL_SUSPEND);            
        }
        return KAL_TRUE;
    }
    return KAL_FALSE;
}
/*************************************************************************
* FUNCTION
*	flashlight_trigger (Xenon Flash)
*
* DESCRIPTION
*	LED strobe
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
void flashlight_trigger(void)
{
    kal_uint32  event_group, i;

    if(fake_sub_flash_frame_flag == KAL_TRUE)   
    {   // turn off sub flash light
 		if(image_sensor_func->set_flashlight!=0)
			image_sensor_func->set_flashlight(KAL_FALSE);           
    }        
    else
    {   // turn on main flash light
        if(fake_main_flash_frame_flag==KAL_FALSE)
        {   // capture mode, wait IDLE
            DISABLE_VIEW_FINDER_MODE;
            kal_set_eg_events(camera_isp_event_id,0,KAL_AND);    
            
            DISABLE_FLASH_LIGHT;                    
            flash_config(sensor_config_data.flashlight_offset, sensor_config_data.flashlight_duty);        
            SET_CAMERA_FRAME_RATE(1);
        	DISABLE_CAMERA_VD_DONE_INT;            
            ENABLE_FLASH_LIGHT;
            flashlight_operation_state = FLASHLIGHT_TRIGGER_DONE_STATE;
    
            ENABLE_VIEW_FINDER_MODE;            
            kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
              	                    &event_group,KAL_SUSPEND);                             	                    
        }                
        flashlight_operation_state = FLASHLIGHT_MAIN_STROBE_STATE;
    }      
}

/*************************************************************************
* FUNCTION
*	flashlight_hisr (Xenon Flash)
*
* DESCRIPTION
*	Entry function of Flash light HISR
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
void flashlight_hisr(void)
{    
    if( (xenon_prestrobe_flag==KAL_TRUE)&&(AE_FRAME_COUNT==1))	        
    {
        xenon_prestrobe_flag = KAL_FALSE;	        
        DISABLE_FLASH_LIGHT;	        
        flash_config(sensor_config_data.flashlight_offset, sensor_config_data.flashlight_duty);        
        ENABLE_FLASH_LIGHT;
    }                
#if (defined(DRV_ISP_6227_SERIES))
    else if((ae_counting_flag==KAL_TRUE)&&(xenon_prestrobe_flag==KAL_FALSE)) //Avoid ae get accumulation frame
#else	// MT6228||MT6229
    else if((AE_FRAME_COUNT==1)&&(xenon_prestrobe_flag==KAL_FALSE)) //Avoid ae get accumulation frame
#endif
	{   /* get valid ae/awb data */          
	    flashlight_lum = flashlight_ae_cal();
	    AE_INDEX = flashlight_ae_proc();
        /* check if main strobe needed, and then update shutter/gain */
        if( (fake_main_flash_frame_flag==KAL_FALSE) &&
            (AE_INDEX<=device_support_info.autoflash.lutidx))
            {
            flashlight_update_ae(AE_INDEX);          
        	flashlight_awb_proc();
        }   
            flashlight_operation_state = FLASHLIGHT_PRE_STROBE_DONE_STATE;        
        }   // AE_FRAME_COUNT = 1
        else
        {
            flashlight_miss_count++;
            if(flashlight_miss_count>12)
            {
                fake_sub_flash_frame_flag = KAL_TRUE;  
                fake_main_flash_frame_flag = KAL_TRUE;                  
                flashlight_operation_state = FLASHLIGHT_PRE_STROBE_DONE_STATE;                        
            }                
        }
}

/*****************************************************************************/
/*                       Customize Sensor Interface                          */
/*****************************************************************************/
void flashlight_sensor_preview_config( flashlight_preview_para_struct *para,
                                image_sensor_config_struct *sensor_config_data)
{
	/* Update Xenon Flash Duty Time by Sensor Clock */	
	if(p_xenon_func!=NULL)
	{
	    kal_uint32 pclk; 
		if((REG_ISP_TG_PHASE_COUNTER & REG_TGPC_PIXEL_CLK_SELECT_BIT)!= 0)
			pclk=((kal_uint32)(48/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));		    
        else
		    pclk=((kal_uint32)(52/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));		                			
	    
        p_xenon_info = p_xenon_func->get_xenon_info();	
        sensor_config_data->flashlight_offset = para->lines;
        sensor_config_data->flashlight_duty = (p_xenon_info->pre_strobe_duty*pclk)/(para->pixels);
        if(sensor_config_data->flashlight_duty<1)                                            
            sensor_config_data->flashlight_duty = 1;
    }
}

kal_uint32 flashlight_sensor_capture_config(   flashlight_capture_para_struct *para,
                                        image_sensor_config_struct *sensor_config_data)
{
    kal_uint32  shutter = para->shutter;    
#if (!defined(DRV_ISP_6219_SERIES))	
	/*Flash Light Shutter/Duty */		
	if(sensor_config_data->enable_flashlight_tansfer==KAL_TRUE)
	{
	    kal_uint32 max_factor, shut_factor;
		kal_uint32 ori_shutter = shutter;				

		// cal max_factor from sensor_pregain/isp_pregain, and let max_factor as 64x
        sensor_pregain = ae_get_sensor_gain(dsc_status.dscmode, dsc_status.ae.iso);
        flashlight_sensor_gain = sensor_pregain;
        isp_pregain = AE_LUT[AE_INDEX].ispgain;    		        
        flashlight_isp_gain  = isp_pregain;
		max_factor = ((flashlight_sensor_gain*flashlight_isp_gain)>>6)&0xFFFFFFC0;
		
		/* cal offset: valid line after VD falling edge */
  		sensor_config_data->flashlight_offset = para->lines;
		/* cal shutter and factor, must > flashlight_offset */
		shut_factor = (sensor_config_data->flashlight_offset<<6)/shutter;
		sensor_config_data->flashlight_shut_factor = BASEGAIN;
		if((shut_factor>64)&&(shut_factor<=max_factor))
		{
		    sensor_config_data->flashlight_shut_factor = BASEGAIN*((shut_factor+BASEGAIN)/BASEGAIN);
    		//sensor_config_data->flashlight_shut_factor = max_factor;
            shutter = shutter*(sensor_config_data->flashlight_shut_factor)/BASEGAIN;        
        }        
		/* cal duty , can't > device_support_info.autoflash.duty */
		if(shutter>sensor_config_data->flashlight_offset)
		{
		    kal_uint32 pixelclk, duty; 
    		if((REG_ISP_TG_PHASE_COUNTER & REG_TGPC_PIXEL_CLK_SELECT_BIT)!= 0)
    			pixelclk=((kal_uint32)(48000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));		    
            else
    		    pixelclk=((kal_uint32)(52000000/(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));		                			
            duty = device_support_info.autoflash.duty*(pixelclk/(para->default_pclk));
        	if(p_xenon_func!=NULL)
        	{
                p_xenon_info = p_xenon_func->get_xenon_info();	                                                               
                sensor_config_data->flashlight_duty = 
                        (p_xenon_info->main_strobe_duty*(pixelclk/1000))/
                        (para->pixels*1000);                                                                            
            }  
            if(sensor_config_data->flashlight_duty<1)                                            
                sensor_config_data->flashlight_duty = 1;
    		if(sensor_config_data->flashlight_duty > duty )
    		    sensor_config_data->flashlight_duty = duty;
		}
		else
		{
            sensor_config_data->flashlight_duty = 0;
            sensor_config_data->flashlight_shut_factor = BASEGAIN;            
            shutter = ori_shutter;
		}		

        // compensate gain when sensor change shutter line number for capture timing 
        if( sensor_config_data->flashlight_duty>0 )
        {
            if(sensor_config_data->flashlight_shut_factor!=BASEGAIN)            
            {
                flashlight_sensor_gain = (sensor_pregain*BASEGAIN)/sensor_config_data->flashlight_shut_factor;
                if( (device_support_info.ae.sensor_basegain!=BASEGAIN)||
                    (flashlight_sensor_gain < BASEGAIN))
                {   // sensor gain is not enough, use isp gain
                    flashlight_sensor_gain = device_support_info.ae.sensor_basegain;
                    if(flashlight_isp_gain>BASEGAIN)
                    {
                        flashlight_isp_gain = ((sensor_pregain*isp_pregain)<<6)/
                                              (flashlight_sensor_gain*sensor_config_data->flashlight_shut_factor);
                        if(flashlight_isp_gain < BASEGAIN)
                            flashlight_isp_gain = BASEGAIN;
	                }	
	                else
                        fake_main_flash_frame_flag = KAL_TRUE;
                }    
                // Update Gain
                if(fake_main_flash_frame_flag == KAL_FALSE)             
                {
                    sensor_pregain = flashlight_sensor_gain;
               			isp_pregain=flashlight_isp_gain;		                        
                    pregain=(flashlight_sensor_gain*flashlight_isp_gain)>>6;
                    image_sensor_func->set_sensor_gain(flashlight_sensor_gain);                
                       	ae_set_isp_pregain();    			            
	                }	
                }                
        }
        else
        {
            fake_main_flash_frame_flag = KAL_TRUE;
        }   
	}	// sensor_config_data->enable_flashlight_tansfer==KAL_TRUE	
#endif  // #if (!defined(DRV_ISP_6219_SERIES))	
    return shutter;
}
#endif  // END_IF_XENON_FLASHLIGHT_ANTI_RED_EYE || XENON_FLASHLIGHT

#endif /* MT6228||MT6226||MT6227||MT6229 && ISP_SUPPORT*/
