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
 *    motion_sensor.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for motion sensor driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "custom_config.h"
#include "gpio_sw.h"
#include "drv_comm.h"
#include "motion_sensor.h"
#if defined(MOTION_SENSOR_SUPPORT)
#include "motion_sensor_custom.h"
#include "motion_sensor_buff.h"
#include "gpt_sw.h"
#include "intrCtrl.h"
#include "eint.h"

/*Variable Declaration*/
MotionSensorStruct motion_sensor_data;
MotionSensorBufferStruct motion_sensor_buff;
MotionSensor_customize_function_struct *motion_sensor_custom_fp;
MotionSensor_custom_data_struct *motion_sensor_custom_dp;
kal_int16 acc_x_plus_g_adc=2000, acc_x_minus_g_adc=2000;
kal_int16 acc_y_plus_g_adc=2000, acc_y_minus_g_adc=2000;
kal_int16 acc_z_plus_g_adc=2000, acc_z_minus_g_adc=2000;
kal_bool acc_execute_cali=KAL_FALSE;
/*Motion main function*/
/*
* FUNCTION                                                            
*	motion_sensor_start_cali
*
* DESCRIPTION                                                           
*   	This function is to start calibration
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/
void motion_sensor_start_cali(void)
{
   acc_execute_cali=KAL_TRUE;   
}
/*
* FUNCTION                                                            
*	motion_sensor_cancel_cali
*
* DESCRIPTION                                                           
*   	This function is to cancel calibration
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/   
void motion_sensor_cancel_cali(void)
{
   /*user cancel calibration, don't calculate it*/
   acc_execute_cali=KAL_FALSE;
   /*use zerog as reference*/
   acc_x_plus_g_adc=motion_sensor_data.cali.x_offset;
   acc_x_minus_g_adc=motion_sensor_data.cali.x_offset;
   acc_y_plus_g_adc=motion_sensor_data.cali.y_offset;
   acc_y_minus_g_adc=motion_sensor_data.cali.y_offset;
   acc_z_plus_g_adc=motion_sensor_data.cali.z_offset;
   acc_z_minus_g_adc=motion_sensor_data.cali.z_offset;
} 
/*
* FUNCTION                                                            
*	motion_sensor_read_cali
*
* DESCRIPTION                                                           
*   	This function is to read calibration data
*
* CALLS  
*
* PARAMETERS
*	cali: calibration data 
*	
* RETURNS
*	None
*/  
void motion_sensor_read_cali(MotionSensorCaliStruct *cali)
{
   *cali=motion_sensor_data.cali;
}
/*
* FUNCTION                                                            
*	motion_sensor_set_cali
*
* DESCRIPTION                                                           
*   	This function is to configure calibration data
*
* CALLS  
*
* PARAMETERS
*	cali: calibration data
*	
* RETURNS
*	None
*/   
void motion_sensor_set_cali(MotionSensorCaliStruct cali)
{
   motion_sensor_data.cali=cali;
} 
/*
* FUNCTION                                                            
*	motion_sensor_complete_cali
*
* DESCRIPTION                                                           
*   	This function is to calculate calibration data
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/  
//MotionSensorCaliStruct test_cali;
void motion_sensor_complete_cali(void)
{
   acc_execute_cali=KAL_FALSE;
   /*offset*/
   motion_sensor_data.cali.x_offset=(acc_x_plus_g_adc+ acc_x_minus_g_adc)>>1;
   motion_sensor_data.cali.y_offset=(acc_y_plus_g_adc+acc_y_minus_g_adc)>>1;
   motion_sensor_data.cali.z_offset=(acc_z_plus_g_adc+ acc_z_minus_g_adc)>>1;
   /*gain*/
   motion_sensor_data.cali.x_gain=(acc_x_plus_g_adc-acc_x_minus_g_adc)>>1;
   motion_sensor_data.cali.y_gain=(acc_y_plus_g_adc-acc_y_minus_g_adc)>>1;
   motion_sensor_data.cali.z_gain=(acc_z_plus_g_adc-acc_z_minus_g_adc)>>1;
   
   if(motion_sensor_data.cali.x_gain==0)
   {
      motion_sensor_data.cali.x_gain=0;      
   }   
   else
      motion_sensor_data.cali.x_gain=(1000<<10)/(motion_sensor_data.cali.x_gain);
   if(motion_sensor_data.cali.y_gain==0)
   {
      motion_sensor_data.cali.y_gain=0;
   }   
   else
      motion_sensor_data.cali.y_gain=(1000<<10)/(motion_sensor_data.cali.y_gain);
   if(motion_sensor_data.cali.z_gain==0)
   {
      motion_sensor_data.cali.z_gain=0;   
   }   
   else
      motion_sensor_data.cali.z_gain=(1000<<10)/(motion_sensor_data.cali.z_gain);  
   /*use zerog as reference*/
   acc_x_plus_g_adc=motion_sensor_data.cali.x_offset;
   acc_x_minus_g_adc=motion_sensor_data.cali.x_offset;
   acc_y_plus_g_adc=motion_sensor_data.cali.y_offset;
   acc_y_minus_g_adc=motion_sensor_data.cali.y_offset;
   acc_z_plus_g_adc=motion_sensor_data.cali.z_offset;
   acc_z_minus_g_adc=motion_sensor_data.cali.z_offset;
   //motion_sensor_read_cali(&test_cali);
}   
/*
* FUNCTION                                                            
*	motion_sensor_check_cali
*
* DESCRIPTION                                                           
*   	This function is to check calibration data
*
* CALLS  
*
* PARAMETERS
*	x: ADC in X-axis
*	y: ADC in Y-axis
*	z: ADC in Z-axis
*	
* RETURNS
*	None
*/
void motion_sensor_check_cali(kal_int16 x, kal_int16 y, kal_int16 z)
{
   if(acc_execute_cali==KAL_TRUE)
   {
      if(x>acc_x_plus_g_adc)
         acc_x_plus_g_adc=x;
      else if(x<acc_x_minus_g_adc)   
         acc_x_minus_g_adc =x;
         
      if(y>acc_y_plus_g_adc)
         acc_y_plus_g_adc=y;
      else if(y<acc_y_minus_g_adc)   
         acc_y_minus_g_adc =y;   
      
      if(z>acc_z_plus_g_adc)
         acc_z_plus_g_adc=z;
      else if(z<acc_z_minus_g_adc)   
         acc_z_minus_g_adc =z;      
   }         
}   
/*
* FUNCTION                                                            
*	motion_sensor_power
*
* DESCRIPTION                                                           
*   	This function is to enable or disable motion sensor module
*
* CALLS  
*
* PARAMETERS
*	enable: enable or disable
*	
* RETURNS
*	None
*/
kal_bool motion_sensor_power(kal_bool enable)
{
   if(enable)
   {      
      motion_sensor_custom_fp->ms_power_up();
   }   
   else   
   {     
     motion_sensor_custom_fp->ms_power_down();
     motion_sensor_sample(KAL_FALSE);
     motion_sensor_reset();
   }  
   return KAL_TRUE;
}
/*
* FUNCTION                                                            
*	motion_sensor_conf_sample_period
*
* DESCRIPTION                                                           
*   	This function is to configure sample period
*
* CALLS  
*
* PARAMETERS
*	period: sample period
*	
* RETURNS
*	None
*/
void motion_sensor_conf_sample_period(kal_uint32 period) 
{
   motion_sensor_data.sample_period=(kal_uint8)period;
} 
/*
* FUNCTION                                                            
*	motion_sensor_eint_hisr
*
* DESCRIPTION                                                           
*   	This function is to handle low-g and high-g interrupt
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/
void motion_sensor_eint_hisr(void)
{
   kal_uint32 savedMask;
   kal_bool low_g, high_g;
   if(motion_sensor_custom_dp->int_support==KAL_TRUE)
   {
      savedMask = SaveAndSetIRQMask();
      motion_sensor_custom_fp->ms_read_int_status(&low_g, &high_g);
      motion_sensor_custom_fp->ms_clear_int_status();
      
      if(low_g!=KAL_FALSE&&motion_sensor_data.low_g_cb!=NULL)
         motion_sensor_data.low_g_cb();
      if(high_g!=KAL_FALSE&&motion_sensor_data.high_g_cb!=NULL)
         motion_sensor_data.high_g_cb();
      RestoreIRQMask(savedMask);
   }
   else /*interrupt should not be triggered*/
      ASSERT(0);         
}  
/*
* FUNCTION                                                            
*	motion_sensor_init
*
* DESCRIPTION                                                           
*   	This function is to initialize motion sensor driver
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/
void motion_sensor_init(void)
{
   /*get customization functin data and function pointr*/  
   motion_sensor_custom_fp=ms_GetFunc();
   motion_sensor_custom_fp->ms_custom_init();
   motion_sensor_custom_dp=motion_sensor_custom_fp->ms_get_data();
   //motion_sensor_cb_registration(acc_test_cb, NULL);
      
   GPTI_GetHandle(&motion_sensor_data.gpt_handle); 
   motion_sensor_conf_sample_period(2); 
   motion_sensor_conf_filter(10); 
   /*interrupt*/
   if(motion_sensor_custom_dp->int_support==KAL_TRUE)
   {
      extern kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);      
      motion_sensor_custom_fp->ms_configure_low_g(1,100);
      motion_sensor_custom_fp->ms_configure_high_g(1,1000);
      EINT_SW_Debounce_Modify(motion_sensor_custom_dp->int_chan, 10);
      EINT_Mask(motion_sensor_custom_dp->int_chan);
      EINT_Registration(motion_sensor_custom_dp->int_chan, KAL_TRUE, 
                       motion_sensor_custom_dp->int_level,motion_sensor_eint_hisr, KAL_TRUE);         
      
   }  
   /*calibration*/
   motion_sensor_data.cali.x_offset=motion_sensor_custom_dp->x_0g_adc;
   motion_sensor_data.cali.y_offset=motion_sensor_custom_dp->y_0g_adc;   
   motion_sensor_data.cali.z_offset=motion_sensor_custom_dp->z_0g_adc;
   motion_sensor_data.cali.x_gain=
   (motion_sensor_custom_dp->x_1g_adc-motion_sensor_custom_dp->x_minus1g_adc)>>1;
   motion_sensor_data.cali.y_gain=
   (motion_sensor_custom_dp->y_1g_adc-motion_sensor_custom_dp->y_minus1g_adc)>>1;   
   motion_sensor_data.cali.z_gain=
   (motion_sensor_custom_dp->z_1g_adc-motion_sensor_custom_dp->z_minus1g_adc)>>1;   
   
   if(motion_sensor_data.cali.x_gain==0)
   {
      motion_sensor_data.cali.x_gain=0;      
   }   
   else
      motion_sensor_data.cali.x_gain=(1000<<10)/(motion_sensor_data.cali.x_gain);
   if(motion_sensor_data.cali.y_gain==0)
   {
      motion_sensor_data.cali.y_gain=0;
   }   
   else
      motion_sensor_data.cali.y_gain=(1000<<10)/(motion_sensor_data.cali.y_gain);
   if(motion_sensor_data.cali.z_gain==0)
   {
      motion_sensor_data.cali.z_gain=0;   
   }   
   else
      motion_sensor_data.cali.z_gain=(1000<<10)/(motion_sensor_data.cali.z_gain);
      
  /*use zerog as reference*/
   acc_x_plus_g_adc=motion_sensor_data.cali.x_offset;
   acc_x_minus_g_adc=motion_sensor_data.cali.x_offset;
   acc_y_plus_g_adc=motion_sensor_data.cali.y_offset;
   acc_y_minus_g_adc=motion_sensor_data.cali.y_offset;
   acc_z_plus_g_adc=motion_sensor_data.cali.z_offset;
   acc_z_minus_g_adc=motion_sensor_data.cali.z_offset;   
}     
/*
* FUNCTION                                                            
*	motion_sensor_flush_buff
*
* DESCRIPTION                                                           
*   	This function is to flush data buffer
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/
void motion_sensor_flush_buff(void)
{
   motion_flush_data_buffer();   
}   
/*
* FUNCTION                                                            
*	motion_sensor_conf_filter
*
* DESCRIPTION                                                           
*   	This function is to configure filter offset 
*
* CALLS  
*
* PARAMETERS
*	acc_offset: offset
*	
* RETURNS
*	None
*/
void motion_sensor_conf_filter(kal_uint32 acc_offset)
{
   motion_sensor_data.acc_offset=acc_offset;
}                                    
/*
* FUNCTION                                                            
*	motion_sensor_cb_registration
*
* DESCRIPTION                                                           
*   	This function is to register callback function for new data
*
* CALLS  
*
* PARAMETERS
*	cb_fun:callback function 
*	para: parameter of callback function
*
* RETURNS
*	None
*/
void motion_sensor_cb_registration(MS_DATA_FUNC cb_fun, void *para)
{
   motion_sensor_data.cb_func=cb_fun;
   motion_sensor_data.para=para;
}   
/*
* FUNCTION                                                            
*	motion_sensor_cb_registration
*
* DESCRIPTION                                                           
*   	This function is to register callback function for low-g/high-g interrupt
*
* CALLS  
*
* PARAMETERS
*	low_g_cb_fun: low-g interrupt callback function 
*	high_g_cb_fun: low-g interrupt callback function 
*
* RETURNS
*	None
*/
void motion_sensor_int_cb_registration(MS_INT_CB_FUNC low_g_cb_fun, MS_INT_CB_FUNC high_g_cb_fun)
{
   motion_sensor_data.low_g_cb=low_g_cb_fun;
   motion_sensor_data.high_g_cb=high_g_cb_fun;
}   
/*
* FUNCTION                                                            
*	motion_sensor_cb_registration
*
* DESCRIPTION                                                           
*   	This function is to configure debounce time and threshold of low_g and high_g 
*     interrupts
*
* CALLS  
*
* PARAMETERS
*	low_g_level: low-g interrupt threshold (mg)
*	high_g_level: high-g interrupt threshold (mg)
*  low_g_debounce: low-g interrupt debounce (ms)
*  high_g_debounce: high-g interrupt debounce (ms)
*
* RETURNS
*	None
*/
void motion_sensor_int_config(kal_uint32 low_g_level, kal_uint32 high_g_level,
                              kal_uint32 low_g_debounce, kal_uint32 high_g_debounce)
{      
   motion_sensor_data.low_g_level=low_g_level;    
   motion_sensor_data.high_g_level=high_g_level;   
   motion_sensor_data.low_g_debounce=low_g_debounce; 
   motion_sensor_data.high_g_debounce=high_g_debounce;
   
   if(motion_sensor_custom_dp->int_support==KAL_TRUE)
   {
      motion_sensor_custom_fp->ms_configure_low_g(low_g_debounce,low_g_level);
      motion_sensor_custom_fp->ms_configure_high_g(high_g_debounce,high_g_level);
   }      
}   
/*
* FUNCTION                                                            
*	motion_sensor_int
*
* DESCRIPTION                                                           
*   	This function is to enable/disable low/high g interrupt
*
* CALLS  
*
* PARAMETERS
*	enable
*
* RETURNS
*	None
*/
void motion_sensor_int_enable(kal_bool enable)
{
   if(enable==KAL_TRUE)   
      EINT_UnMask(motion_sensor_custom_dp->int_chan);
   else
      EINT_Mask(motion_sensor_custom_dp->int_chan);
}                                    
/*
* FUNCTION                                                            
*	motion_sensor_get_data
*
* DESCRIPTION                                                           
*   	This function is to get acceleration data
*
* CALLS  
*
* PARAMETERS
*	ms_data: data pointer
*	
* RETURNS
*	None
*/
kal_bool motion_sensor_get_data(MotionSensorDataStruct  *ms_data)
{
   kal_bool result, send_kbdilm;

   IRQMask(IRQ_GPT_CODE);   
   if (motion_sensor_buff.motion_sensor_rindex != motion_sensor_buff.motion_sensor_windex)
   {      
      motion_pop_data_from_buffer(*ms_data);      
      result = KAL_TRUE;
   }
   else
   {
      send_kbdilm = KAL_TRUE;
      result = KAL_FALSE;
   }      
   IRQUnmask(IRQ_GPT_CODE);
   return result;
} 
/*
* FUNCTION                                                            
*	motion_sensor_filter
*
* DESCRIPTION                                                           
*   	This function is to filter unnecessary data
*
* CALLS  
*
* PARAMETERS
*	data: acceleration data
*	
* RETURNS
*	None
*/  
kal_bool motion_sensor_filter(MotionSensorDataStruct data)
{   	
	kal_int16 x_diff, y_diff, z_diff;
   /*X axis*/
   if(data.x_acc>motion_sensor_data.pre.x_acc)   
      x_diff=data.x_acc-motion_sensor_data.pre.x_acc;
   else
      x_diff=motion_sensor_data.pre.x_acc-data.x_acc;   
   /*Y axis*/   
   if(data.y_acc>motion_sensor_data.pre.y_acc)   
      y_diff=data.y_acc-motion_sensor_data.pre.y_acc;
   else
      y_diff=motion_sensor_data.pre.y_acc-data.y_acc;      
   /*Z axis*/      
   if(data.z_acc>motion_sensor_data.pre.z_acc)   
      z_diff=data.z_acc-motion_sensor_data.pre.z_acc;
   else
      z_diff=motion_sensor_data.pre.z_acc-data.z_acc;   
          
   
   if((x_diff>=motion_sensor_data.acc_offset)||
      (y_diff>=motion_sensor_data.acc_offset)||
      (z_diff>=motion_sensor_data.acc_offset))          
      return KAL_TRUE;          
   else
      return KAL_FALSE;      
} 
/*
* FUNCTION                                                            
*	motion_sensor_sample_cb
*
* DESCRIPTION                                                           
*   	This function is callback function to sample data
*
* CALLS  
*
* PARAMETERS
*	parameter: gpt timer parameter
*	
* RETURNS
*	None
*/ 
//kal_uint32 motion_sensor_ponit1, motion_sensor_ponit2, motion_sensor_ponit3, motion_sensor_ponit4; 
//kal_uint32 motion_sensor_ponit5; 
void motion_sensor_sample_cb(void *parameter)
{
   MotionSensorDataStruct data;
   kal_uint16 x_adc, y_adc, z_adc;
   kal_uint16 roomleft;
   //kal_uint32 savedMask;
 	
	
	//savedMask = SaveAndSetIRQMask();
	//motion_sensor_ponit1=DRV_Reg(0x80200000);
   ms_get_buf_roomleft(roomleft);
   if(roomleft!=0)      
   {
              
      motion_sensor_custom_fp->ms_read_adc(&x_adc,&y_adc,&z_adc);   
      //motion_sensor_get_tilt(x_adc, y_adc, z_adc);
      motion_sensor_check_cali(x_adc, y_adc, z_adc);
      //motion_sensor_ponit2=DRV_Reg(0x80200000);
      motion_sensor_get_acc(&data, x_adc, y_adc, z_adc);
      //motion_sensor_ponit3=DRV_Reg(0x80200000);
      if(motion_sensor_filter(data))
      {
         motion_push_data_to_buffer(data);
         motion_sensor_data.pre=data;
      }   
      //motion_sensor_ponit4=DRV_Reg(0x80200000);
   }      
   GPTI_StartItem(motion_sensor_data.gpt_handle,
                  motion_sensor_data.sample_period,
                  motion_sensor_sample_cb,
                  NULL); 
  //motion_sensor_ponit5=DRV_Reg(0x80200000);
  //RestoreIRQMask(savedMask);
} 
/*
* FUNCTION                                                            
*	motion_sensor_sample
*
* DESCRIPTION                                                           
*   	This function is to enable or disable sample function
*
* CALLS  
*
* PARAMETERS
*	enable: enable or disable
*	
* RETURNS
*	None
*/  
void motion_sensor_sample(kal_bool enable)
{
   if(enable)/*ON*/
   {
      GPTI_StartItem(motion_sensor_data.gpt_handle,
                     motion_sensor_data.sample_period,
                     motion_sensor_sample_cb,
                     NULL);      
   }  
   else/*OFF*/
   {
      GPTI_StopItem(motion_sensor_data.gpt_handle);      
   }   
}   
/*
* FUNCTION                                                            
*	motion_sensor_get_acc
*
* DESCRIPTION                                                           
*   	This function is to get acceleration
*
* CALLS  
*
* PARAMETERS
*	acc_data: acceleration data pointer
*  x_adc: ADC value in X-axis
*  y_adc: ADC value in Y-axis
*  z_adc: ADC value in Z-axis
*	
* RETURNS
*	None
*/
void motion_sensor_get_acc(MotionSensorDataStruct *acc_data,
                           kal_uint16 x_adc, kal_uint16 y_adc, kal_uint16 z_adc)
{  
   /*X acceleration*/
   if(x_adc>=motion_sensor_data.cali.x_offset)
   {
      acc_data->x_acc=((x_adc-motion_sensor_data.cali.x_offset)*motion_sensor_data.cali.x_gain)>>10;      
   }   
   else
   {
      acc_data->x_acc=-(((motion_sensor_data.cali.x_offset-x_adc)*motion_sensor_data.cali.x_gain)>>10);      
   }      
   /*Y acceleration*/
   if(y_adc>=motion_sensor_data.cali.y_offset)
   {
      acc_data->y_acc=(((y_adc-motion_sensor_data.cali.y_offset)*motion_sensor_data.cali.y_gain)>>10);      
   }   
   else
   {
      acc_data->y_acc=-(((motion_sensor_data.cali.y_offset-y_adc)*motion_sensor_data.cali.y_gain)>>10);      
   }      
   
   /*Z acceleration*/
   if(z_adc>=motion_sensor_data.cali.z_offset)
   {
      acc_data->z_acc=(((z_adc-motion_sensor_data.cali.z_offset)*motion_sensor_data.cali.z_gain)>>10);      
   }   
   else
   {
      acc_data->z_acc=-(((motion_sensor_data.cali.z_offset-z_adc)*motion_sensor_data.cali.z_gain)>>10);      
   }   	
}   
/*
* FUNCTION                                                            
*	motion_sensor_reset
*
* DESCRIPTION                                                           
*   	This function is to reset motion sensor driver
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/  
void motion_sensor_reset(void)   
{
   IRQMask(IRQ_GPT_CODE);   
   if(motion_sensor_custom_dp->int_support==KAL_TRUE)
      EINT_Mask(motion_sensor_custom_dp->int_chan);   
   motion_sensor_flush_buff();
   acc_execute_cali=KAL_FALSE;
   /*use zerog as reference*/
   acc_x_plus_g_adc=motion_sensor_data.cali.x_offset;
   acc_x_minus_g_adc=motion_sensor_data.cali.x_offset;
   acc_y_plus_g_adc=motion_sensor_data.cali.y_offset;
   acc_y_minus_g_adc=motion_sensor_data.cali.y_offset;
   acc_z_plus_g_adc=motion_sensor_data.cali.z_offset;
   acc_z_minus_g_adc=motion_sensor_data.cali.z_offset;  
   /*reset previous acc as 0*/
   motion_sensor_data.pre.x_acc=0;
   motion_sensor_data.pre.y_acc=0;
   motion_sensor_data.pre.z_acc=0;   
   if(motion_sensor_custom_dp->int_support==KAL_TRUE)
      EINT_UnMask(motion_sensor_custom_dp->int_chan);  
   IRQUnmask(IRQ_GPT_CODE);
}

#ifdef __MOTION_SENSOR_TILT_SUPPORT__
kal_uint16 asin_value[SIN_INTERVAL_NUM]=
{
SIN_0 , SIN_1 , SIN_2 , SIN_3 , SIN_4 , SIN_5 , SIN_6 , SIN_7 , SIN_8 , SIN_9 , 
SIN_10, SIN_11, SIN_12, SIN_13, SIN_14, SIN_15, SIN_16, SIN_17, SIN_18, SIN_19, 
SIN_20, SIN_21, SIN_22, SIN_23, SIN_24, SIN_25, SIN_26, SIN_27, SIN_28, SIN_29, 
SIN_30, SIN_31, SIN_32, SIN_33, SIN_34, SIN_35, SIN_36, SIN_37, SIN_38, SIN_39,
SIN_40, SIN_41, SIN_42, SIN_43, SIN_44, SIN_45, SIN_46, SIN_47, SIN_48, SIN_49,
SIN_50, SIN_51, SIN_52, SIN_53, SIN_54, SIN_55, SIN_56, SIN_57, SIN_58, SIN_59,
SIN_60, SIN_61, SIN_62, SIN_63, SIN_64, SIN_65, SIN_66, SIN_67, SIN_68, SIN_69,
SIN_70, SIN_71, SIN_72, SIN_73, SIN_74, SIN_75, SIN_76, SIN_77, SIN_78, SIN_79,
SIN_80, SIN_81, SIN_82, SIN_83, SIN_84, SIN_85, SIN_86, SIN_87, SIN_88, SIN_89,
SIN_90};
/*
* FUNCTION                                                            
*	motion_sensor_get_angle
*
* DESCRIPTION                                                           
*   	This function is to get angle
*
* CALLS  
*
* PARAMETERS
*	enable: enable or disable
*	
* RETURNS
*	None
*/                   
kal_uint16 motion_sensor_get_angle(kal_uint16 value)
{        
   kal_int16 i;
   #if 1
     
   for(i=(SIN_INTERVAL_NUM-1);i>=0;i--)
   {     
     if(value>=asin_value[i])
      return  (i*1);
   }     
      return  0;
   #endif   
}        
/*
* FUNCTION                                                            
*	motion_sensor_get_tilt
*
* DESCRIPTION                                                           
*   	This function is to get tilt
*
* CALLS  
*
* PARAMETERS
*	enable: enable or disable
*	
* RETURNS
*	None
*/          
void motion_sensor_get_tilt(kal_uint16 x, kal_uint16 y, kal_uint16 z)
{
   kal_int16 x_tilt, y_tilt, z_tilt;
   /*X tilt*/
   if(x>=motion_sensor_data.cali.x_offset)
   {
      x_tilt=motion_sensor_get_angle((x-motion_sensor_data.cali.x_offset));      
   }   
   else
   {
      x_tilt=-motion_sensor_get_angle((motion_sensor_data.cali.x_offset-x));      
   }      
   /*Y tilt*/
   if(y>=motion_sensor_data.cali.y_offset)
   {
      y_tilt=-motion_sensor_get_angle((y-motion_sensor_data.cali.y_offset));      
   }   
   else
   {
      y_tilt=motion_sensor_get_angle((motion_sensor_data.cali.y_offset-y));      
   }        
   /*Z tilt*/
   if(z>=motion_sensor_data.cali.z_offset)
   {
      z_tilt=-motion_sensor_get_angle((z-motion_sensor_data.cali.z_offset));      
   }   
   else
   {
      z_tilt=motion_sensor_get_angle((motion_sensor_data.cali.z_offset-z));      
   }
   #ifdef ACC_KAL_DEBUG		
   dbg_printWithTime("X, Y, Z tilt = %d,%d,%d\r\n", x_tilt, y_tilt, z_tilt);
   #endif
} 
#endif
#endif
