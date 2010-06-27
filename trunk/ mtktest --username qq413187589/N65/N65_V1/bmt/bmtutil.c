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
 *    bmtutil.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the interface between BMT and ADC scheduler.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_comm.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include    "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include    "event_shed.h"       /* Event scheduler */
#include    "stack_timer.h"     /*Timer*/
#include    "reg_base.h"
#include    "adc.h"
#include    "adcsche.h"
#include    "bmt.h"
#include    "adc_channel.h"
#include    "drvsignals.h"
#include		"bmt_trc.h"
#include 	"pmic6318_sw.h"
ADC_FUNC    bmt_measure_complete1[BMT_MAX_CHANNEL_TOTAL];   //Drop one sample
kal_uint8  bmt_bmtid_adcscheid[BMT_MAX_CHANNEL_TOTAL];
static kal_uint8  bmt_sche_vbat_id;
static kal_uint8  bmt_sche_visense_id;
static kal_uint8  bmt_sche_vbatemp_id;
static kal_uint8  bmt_sche_vcharger_id;
kal_uint16  bmt_complete_status;
kal_uint16  bmt_complete_flag;
#ifdef MTK_SLEEP_ENABLE
static kal_uint8 bmt_sm_handle;
#endif
extern kal_uint8 adc_sche_create_object(module_type ownerid, kal_uint8 adc_channel,kal_uint32 period, kal_uint8 evaluate_count, kal_bool send_primitive);
extern void adc_sche_modify_parameters(kal_uint8 adc_sche_id, kal_uint32 period, kal_uint8 evaluate_count);
extern void adc_sche_add_item(kal_uint8 adc_sche_id, void (*mea_complete)(kal_uint8 adc_sche_id), kal_timer_func_ptr mea_Callback);
extern void adc_sche_remove_item(kal_uint8 adc_sche_id);
extern void bmt_stop_timer_init(void);
extern void bmt_measure_done(void);
extern void BMT_Charge(char data);  /*in drv directory*/
extern void adc_sche_set_timer_page_align(kal_bool page_align);
extern void bmt_stop_stoptimer(void);
extern kal_bool USB_GetCableStatus(void);
extern kal_uint32 adc_sche_sum[MAX_CHANNEL];
extern kal_uint32 adc_sche_count[MAX_CHANNEL];
extern BMTStruct BMT;
extern stack_timer_struct      ChargeTimeout_timer;
static kal_uint32 bmt_charge_time_value;
//extern const kal_uint32 bmt_measure_discard_time;
extern kal_uint8 SaftyTimer_Flag; 
extern kal_uint8 low_charger_count;
extern kal_uint8 low_current_count;
extern kal_uint8 low_temper_count;
extern kal_uint8 over_temper_count;

/*
* FUNCTION
*	   bmt_gen_complete_flag
*
* DESCRIPTION                                                           
*   	This function is to generate the measure complete flag for charging algorithm
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_gen_complete_flag(void)
{
   kal_uint8 index;
   bmt_complete_flag = 0;
   for(index=0;index<BMT_MAX_CHANNEL;index++)
   {
      bmt_complete_flag |= (1<<index);
   }
}

/*
* FUNCTION
*	   bmt_timer_config
*
* DESCRIPTION                                                           
*   	This function is to configure the measure timer
*
* CALLS  
*
* PARAMETERS
*	   time: on/off time interval. (1 tick = 4.615ms)
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_timer_config(kal_uint32 time) /*time unit is second*/
{
   kal_uint8 index;
   kal_uint32  adc_bmt_tick;
   kal_uint32 discard_time;
   
	adc_bmt_tick = (kal_uint32)(time/bmt_evaluate_value);
	adc_bmt_tick++;
	bmt_charge_time_value = adc_bmt_tick;
	
	if (bmt_charing_para->bmt_measure_discard_time != 0)
      discard_time = bmt_charing_para->bmt_measure_discard_time;
   else
      discard_time = 1;
	
	#ifdef BMT_DEBUG
      //dbg_printWithTime("adc_bmt_tick = %d\r\n",adc_bmt_tick);	
	#endif
	for(index=0;index<BMT_MAX_CHANNEL;index++)
	{
      adc_sche_modify_parameters(bmt_bmtid_adcscheid[index],discard_time,1);
	   adc_sche_add_item(bmt_bmtid_adcscheid[index],bmt_measure_complete1[index], bmt_adc_sche_measure);
   }
}

/*
* FUNCTION
*	   bmt_measure_complete_vbat
*
* DESCRIPTION                                                           
*   	This function is the callback function when vbat is measured done.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_measure_complete_vbat(kal_uint8 adc_sche_id)
{
   #ifdef BMT_DEBUG
      //dbg_printWithTime("bmt_measure_complete_vbat\r\n");	
	#endif
	
   bmt_complete_status |= (1<<ADC_BMT_VBAT);
   adc_sche_remove_item(adc_sche_id);
   if(bmt_complete_status == bmt_complete_flag)
   {
      bmt_complete_status = 0;
      bmt_measure_done();
   }
}
void bmt_measure_complete_vbat1(kal_uint8 adc_sche_id)
{
   #ifdef BMT_DEBUG
      //dbg_printWithTime("bmt_measure_complete_vbat1\r\n");	
	#endif
	adc_sche_remove_item(adc_sche_id);
   adc_sche_modify_parameters(adc_sche_id,bmt_charge_time_value,bmt_evaluate_value);
   adc_sche_add_item(adc_sche_id,bmt_measure_complete_vbat, bmt_adc_sche_measure);
}
/*
* FUNCTION
*	   bmt_measure_complete_visense
*
* DESCRIPTION                                                           
*   	This function is the callback function when visense is measured done.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_measure_complete_visense(kal_uint8 adc_sche_id)
{
   #ifdef BMT_DEBUG
      //dbg_printWithTime("bmt_measure_complete_visense\r\n");	
	#endif
	
   bmt_complete_status |= (1<<ADC_BMT_VISENSE);
   adc_sche_remove_item(adc_sche_id);
   if(bmt_complete_status == bmt_complete_flag)
   {
      bmt_complete_status = 0;
      bmt_measure_done();
   }
}
void bmt_measure_complete_visense1(kal_uint8 adc_sche_id)
{
   #ifdef BMT_DEBUG
      //dbg_printWithTime("bmt_measure_complete_visense1\r\n");	
	#endif
	adc_sche_remove_item(adc_sche_id);
   adc_sche_modify_parameters(adc_sche_id,bmt_charge_time_value,bmt_evaluate_value);
   adc_sche_add_item(adc_sche_id,bmt_measure_complete_visense, bmt_adc_sche_measure);
}
/*
* FUNCTION
*	   bmt_measure_complete_vbatemp
*
* DESCRIPTION                                                           
*   	This function is the callback function when visense is measured done.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_measure_complete_vbatemp(kal_uint8 adc_sche_id)
{
   #ifdef BMT_DEBUG
      //dbg_printWithTime("bmt_measure_complete_vbatemp\r\n");	
	#endif
   bmt_complete_status |= (1<<ADC_BMT_VBATTMP);
   adc_sche_remove_item(adc_sche_id);
   if(bmt_complete_status == bmt_complete_flag)
   {
      bmt_complete_status = 0;
      bmt_measure_done();
   }
}

void bmt_measure_complete_vbatemp1(kal_uint8 adc_sche_id)
{
   #ifdef BMT_DEBUG
      //dbg_printWithTime("bmt_measure_complete_vbatemp1\r\n");	
	#endif
	adc_sche_remove_item(adc_sche_id);
   adc_sche_modify_parameters(adc_sche_id,bmt_charge_time_value,bmt_evaluate_value);
   adc_sche_add_item(adc_sche_id,bmt_measure_complete_vbatemp, bmt_adc_sche_measure);
}
/*
* FUNCTION
*	   bmt_measure_complete_vcharger
*
* DESCRIPTION                                                           
*   	This function is the callback function when vcharge is measured done.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_measure_complete_vcharger(kal_uint8 adc_sche_id)
{
   bmt_complete_status |= (1<<ADC_BMT_VCHARGER);
   adc_sche_remove_item(adc_sche_id);
   if(bmt_complete_status == bmt_complete_flag)
   {
      bmt_complete_status = 0;
      bmt_measure_done();
   }
}

void bmt_measure_complete_vcharger1(kal_uint8 adc_sche_id)
{
   adc_sche_remove_item(adc_sche_id);
   adc_sche_modify_parameters(adc_sche_id,bmt_charge_time_value,bmt_evaluate_value);
   adc_sche_add_item(adc_sche_id,bmt_measure_complete_vcharger, bmt_adc_sche_measure);
}
/*
* FUNCTION
*	   bmt_adc_init
*
* DESCRIPTION                                                           
*   	This function is the charge initial function
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
/*if add more measure parameters, just need modify bmt_adc_init*/
void bmt_adc_init(void)
{
   kal_uint8 ADC_VBAT_channel, ADC_VISENSE_channel, ADC_VBATTMP_channel;
   kal_uint8 ADC_VCHARGER_channel;

   #ifdef MTK_SLEEP_ENABLE
   bmt_sm_handle = L1SM_GetHandle();
   #endif
   bmt_stop_timer_init();
   BMT.VBAT_UEM = VBAT_UEM_CHR_OUT;
   /*to get customized ADC channel*/
   ADC_VBAT_channel=custom_adc_get_channel(vbat_adc_channel);
   ADC_VISENSE_channel=custom_adc_get_channel(visense_adc_channel);
      
   bmt_sche_vbat_id = adc_sche_create_object(MOD_BMT,ADC_VBAT_channel,10,bmt_evaluate_value,KAL_FALSE);
   bmt_bmtid_adcscheid[ADC_BMT_VBAT] = bmt_sche_vbat_id;
   bmt_measure_complete1[ADC_BMT_VBAT] = bmt_measure_complete_vbat1;
   
   bmt_sche_visense_id = adc_sche_create_object(MOD_BMT,ADC_VISENSE_channel,10,bmt_evaluate_value,KAL_FALSE);
   bmt_bmtid_adcscheid[ADC_BMT_VISENSE] = bmt_sche_visense_id;
   bmt_measure_complete1[ADC_BMT_VISENSE] = bmt_measure_complete_visense1;

 
	ADC_VBATTMP_channel=custom_adc_get_channel(vbattmp_adc_channel);
   bmt_sche_vbatemp_id = adc_sche_create_object(MOD_BMT,ADC_VBATTMP_channel,10,bmt_evaluate_value,KAL_FALSE);
   bmt_bmtid_adcscheid[ADC_BMT_VBATTMP] = bmt_sche_vbatemp_id;
   bmt_measure_complete1[ADC_BMT_VBATTMP] = bmt_measure_complete_vbatemp1;
   
	ADC_VCHARGER_channel=custom_adc_get_channel(vcharger_adc_channel);
   bmt_sche_vcharger_id = adc_sche_create_object(MOD_BMT,ADC_VCHARGER_channel,10,bmt_evaluate_value,KAL_FALSE);
   bmt_bmtid_adcscheid[ADC_BMT_VCHARGER] = bmt_sche_vcharger_id;
   bmt_measure_complete1[ADC_BMT_VCHARGER] = bmt_measure_complete_vcharger1;

   bmt_gen_complete_flag();

}

/*
* FUNCTION
*	   bmt_charge_start
*
* DESCRIPTION                                                           
*   	This function is to start charging algorithm.
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_charge_start(void)
{
   kal_uint8 index;
   BMT_Charge(KAL_FALSE);
   BMT.pmictrl_state = PMIC_CHARGEOFF;
   BMT.bat_state = CHR_PRE;
   BMT.VBAT_UEM= VBAT_UEM_CHR_IN_FISRT;
   bmt_charge_time_value = 10;
   low_charger_count = 0;
   low_current_count = 0;
   low_temper_count = 0;
   over_temper_count = 0;
   
   #ifdef MTK_SLEEP_ENABLE
   L1SM_SleepDisable(bmt_sm_handle);
   #endif
   for(index=0;index<BMT_MAX_CHANNEL;index++)
   {
      adc_sche_modify_parameters(bmt_bmtid_adcscheid[index],1,1);
	   adc_sche_add_item(bmt_bmtid_adcscheid[index],bmt_measure_complete1[index], bmt_adc_sche_measure);
	}
	
	adc_sche_set_timer_page_align(KAL_FALSE);

	stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*60*6);
	#ifdef BMT_KAL_DEBUG   
	   kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_START_TRC);
	#endif   
   SaftyTimer_Flag = BMT_SaftyTimer_On; 
   #if defined(MT6318)
      #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
   if(pmic_is_chr_det(AC_CHR))
      pmic_charging_currnet_ctrl(pmic_return_current(AC_CHR));
   #ifdef __USB_MULTI_CHARGE_CURRENT__
      else if (bmt_support_usb_charge()) /* If not support, charging current is not set here. */
         pmic_charging_currnet_ctrl(pmic_return_current(USB_CHR));   
   #else /* __USB_MULTI_CHARGE_CURRENT__ */
   else
      pmic_charging_currnet_ctrl(pmic_return_current(USB_CHR));   
   #endif /* __USB_MULTI_CHARGE_CURRENT__ */
      #else/*defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)*/
         if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT)                                   
            pmic_charging_currnet_ctrl(pmic_return_current(AC_CHR));   
         else if(chr_usb_detect.chr_usb_present == USB_PRESENT)                                                                                             
         {  
            #ifdef __USB_MULTI_CHARGE_CURRENT__
            if (bmt_support_usb_charge()) /* If not support, charging current is not set here. */
                pmic_charging_currnet_ctrl(pmic_return_current(USB_CHR));   
            #else /* __USB_MULTI_CHARGE_CURRENT__ */             
                pmic_charging_currnet_ctrl(pmic_return_current(USB_CHR));   
             #endif /* __USB_MULTI_CHARGE_CURRENT__ */
         }
      #endif   
   #endif /* defined(MT6318) */
}

/*
* FUNCTION
*	   bmt_charge_end
*
* DESCRIPTION                                                           
*   	This function is to stop charging when charger is plugged out 
*     or serious error in charging stage.
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_charge_end(void)
{
	kal_uint8 index;
	BMT.pmictrl_state = PMIC_CHARGEOFF;
   	BMT.VBAT_UEM= VBAT_UEM_CHR_OUT_FIRST;
	BMT_Charge(KAL_FALSE);
	for(index=0;index<BMT_MAX_CHANNEL;index++)
	   adc_sche_remove_item(bmt_bmtid_adcscheid[index]);

	adc_sche_set_timer_page_align(KAL_TRUE);
	bmt_stop_stoptimer();
	stack_stop_timer(&ChargeTimeout_timer);
	#ifdef BMT_KAL_DEBUG   
	   kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_STOP_TRC);
	#endif   
   SaftyTimer_Flag = BMT_SaftyTimer_Off; 
   #ifdef MTK_SLEEP_ENABLE
   L1SM_SleepEnable(bmt_sm_handle);
   #endif
}

/*
* FUNCTION
*	   IsUSBorCharger
*
* DESCRIPTION                                                           
*   	It tells whether the a AC charger or a USB cable  plugged in. 
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
#ifdef __USB_ENABLE__

bmt_usb_charger_enum IsUSBorCharger(void)
{
	kal_bool isUSB;

	#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	isUSB = USB_GetCableStatus();
	#else
	isUSB = (chr_usb_detect.chr_usb_present == USB_PRESENT);
	#endif
	
	return (isUSB)?BMT_USB_IN:BMT_AC_IN; 
}
#endif


