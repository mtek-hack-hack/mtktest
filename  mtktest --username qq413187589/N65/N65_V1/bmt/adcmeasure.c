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
 *    adcmeasure.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the adaption layer for KAL and HW interface.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include    "app_buff_alloc.h"   /*buffer*/
#include    "reg_base.h"
#include    "adc.h"
#include    "adcsche.h"
#include    "bmt.h"
#include    "batvalue.h"
#include    "bmt_trc.h"
#include    "pmic6318_sw.h"
#ifdef __MULTI_BOOT__
#include "kal_release.h"
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/

#if ( (defined(MT6218B))||defined(MT6226M)|| (defined(MT6219))|| (defined(MT6217))|| (defined(MT6225))|| (defined(MT6228))|| (defined(MT6229))|| (defined(MT6230))|| (defined(MT6226))|| (defined(MT6227)) )
#define MT6218
#endif
#ifdef MT6205
   /*for L1 measurement*/
   extern kal_bool adc_sche_start_measure;
   kal_bool l1_adc_start_measure_bak;
   kal_bool l1_adc_start_measure;
   kal_uint16 l1_adc_channel_bak;
#endif   /*MT6205*/
extern void evshed_unset_aligned_timer(void *timer_id);
extern void evshed_set_aligned_timer(void *timer_id, kal_uint8 max_delay);
//extern kal_uint8 PDNhandle[12];
//extern ADC_CALIDATA adc_cali_param;
extern MeasParameter adc_parameters[MAX_CHANNEL];
extern kal_uint16 adc_imm_mode_cnt;
extern kal_bool adc_sync_mode_on;
#ifdef MT6318
extern void pmic_adc_measure_sel_fast(adc_type sel);
#endif

stack_timer_struct      adcsche_timer;
stack_timer_struct      stopcharge_timer;
stack_timer_struct      *timer_adcsche;   /*Normal Measure, only monitor VBAT*/
stack_timer_struct      *timer_stopcharge;
event_scheduler     *adc_sche_event_scheduler_ptr;
stack_timer_struct      ChargeTimeout_timer;

void adc_sche_start_base_timer(void *base_timer_ptr,kal_uint32 time_out)
{
   kal_uint32 time = time_out;
   if (time == 0)
      time = 1;
   stack_start_timer((stack_timer_struct *)base_timer_ptr, 0, time);
}

void adc_sche_stop_base_timer(void *base_timer_ptr)
{
   stack_stop_timer((stack_timer_struct *)base_timer_ptr);
}

/*
* FUNCTION
*	   adc_adc2vol
*
* DESCRIPTION                                                           
*   	This function is to translate ADC value to voltage.(uV)
*
* CALLS  
*
* PARAMETERS
*	   chann: ADC channel.
*     adcVoltage: ADC value
*	
* RETURNS
*	   voltage value(uV)
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 adc_adc2vol(kal_uint8 chann,double adcVoltage)
{
	double result;
   
   result = (double)((adcVoltage*(double)bmt_charing_para->adc_cali_param.ADCSlope[chann])+(double)bmt_charing_para->adc_cali_param.ADCOffset[chann]);
   return ((kal_int32)result);
}

void adc_sche_stop_timer(kal_uint8 adc_sche_id)
{
   #ifdef BMT_DEBUG
   //dbg_printWithTime("stop,%d\r\n",adc_sche_id);
   #endif
   evshed_cancel_event(adc_sche_event_scheduler_ptr,
                           &adc_parameters[adc_sche_id].adc_sche_event_id);
}

void adc_sche_set_timer(kal_uint8 adc_sche_id, kal_uint32 tick, kal_timer_func_ptr call_func)
{
   #ifdef BMT_DEBUG
   //dbg_printWithTime("set,%d, %d\r\n",adc_sche_id,tick);
   #endif
	adc_parameters[adc_sche_id].adc_sche_event_id = evshed_set_event(adc_sche_event_scheduler_ptr,
                                                        (kal_timer_func_ptr)call_func, &adc_parameters[adc_sche_id], tick);
}

/*
* FUNCTION
*	   adc_sche_set_timer_page_align
*
* DESCRIPTION                                                           
*   	This function is to set up timer as page align or not.
*
* CALLS  
*
* PARAMETERS
*	   page_align: KAL_TRUE or KAL_FALSE;
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_set_timer_page_align(kal_bool page_align)
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
#ifdef DONT_SET_PAGE_ALIGN
      evshed_unset_aligned_timer(timer_adcsche);
#else
   if (page_align)
      evshed_set_aligned_timer(timer_adcsche, 255);
   else
      evshed_unset_aligned_timer(timer_adcsche);
#endif
   RestoreIRQMask(savedMask);
}

/*
* FUNCTION
*	   adc_sche_timer_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the timer of ADC scheduler.
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
void adc_sche_timer_init(void)
{
	timer_adcsche = &adcsche_timer;
   stack_init_timer(timer_adcsche, "ADC Sche Timer", MOD_BMT);

   adc_sche_event_scheduler_ptr = new_evshed(timer_adcsche,
                                                adc_sche_start_base_timer,
                                                adc_sche_stop_base_timer,
                                                0 , kal_evshed_get_mem, kal_evshed_free_mem, 255);

   adc_sche_set_timer_page_align(KAL_TRUE);
}

/*
* FUNCTION
*	   adc_pwrdown_enable
*
* DESCRIPTION                                                           
*   	This function is to enable adc power down control
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
*     Note that this function must be called between SaveAndSetIRQMask()
*   and RestoreIRQMask().
*/
void adc_pwrdown_enable(void)
{
   #ifndef MT6208
   if((adc_sche_rw_status==0)&&!(DRV_Reg(AUXADC_CON) & AUXADC_CON_RUN))
   #endif
   {
      DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
      #if defined(MT6318) 
      pmic_adc_measure_sel_fast(PMIC_ADC_OFF);
      #endif
   }
}

/*
* FUNCTION
*	   adc_pwrdown_disable
*
* DESCRIPTION                                                           
*   	This function is to disable adc power down control
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
*     Note that this function must be called between SaveAndSetIRQMask()
*   and RestoreIRQMask().
*/
void adc_pwrdown_disable(void)
{
   #if defined(MT6318)
   pmic_adc_measure_sel_fast(PMIC_ADC_ISENSE_VBAT);
   #endif
	DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
}

/*
* FUNCTION
*	   bmt_stop_timer_init
*
* DESCRIPTION
*   	This function is to stop the bmt_stop timer in bmt task.
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
/*charge mode*/
void bmt_stop_timer_init(void)
{
   timer_stopcharge = &stopcharge_timer;
   stack_init_timer(timer_stopcharge, "chrstop_timer", MOD_BMT);
}

/*
* FUNCTION
*	   bmt_stop_timer_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the bmt_stop timer in bmt task.
*
* CALLS  
*
* PARAMETERS
*	   tick: timer tick(1 tick=4.615ms)
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_set_stoptimer(kal_uint32 tick)
{
   #ifdef BMT_KAL_DEBUG   
	   kal_trace(TRACE_FUNC, BMT_STOP_TIMER_START_TRC);
   #endif	
	stack_start_timer(timer_stopcharge, 0, tick);
}

/*
* FUNCTION
*	   bmt_stop_stoptimer
*
* DESCRIPTION                                                           
*   	This function is to stop the bmt_stop timer in bmt task.
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
void bmt_stop_stoptimer(void)
{
   #ifdef BMT_KAL_DEBUG    
   	kal_trace(TRACE_FUNC, BMT_STOP_TIMER_STOP_TRC);
   #endif 	
	stack_stop_timer(timer_stopcharge);
}

/*These two functions only for L1 only*/
/*Called in L1D*/
void l1_adc_measure(kal_uint8 channel)
{
#ifdef MT6205
   l1_adc_start_measure_bak = adc_sche_start_measure;
   if (!l1_adc_start_measure_bak)
   {
      DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);      
   }
   l1_adc_channel_bak = DRV_Reg(AUXADC_CTRL);
   
   DRV_WriteReg(AUXADC_CTRL,channel);
   adc_sche_start_measure = KAL_TRUE;
   l1_adc_start_measure = KAL_TRUE;
#endif   /*MT6205*/
#if ( (defined(MT6205B)) || (defined(MT6218)))
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();	
   adc_sync_mode_on = KAL_TRUE;
   DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);   
   DRV_Reg(AUXADC_SYNC) |= (1<<channel);
   RestoreIRQMask(savedMask);
#endif   /*MT6205B,MT6218*/
}

/*Called in L1D*/
kal_uint16 l1_adc_readback(kal_uint8 channel)
{
   kal_uint16  data;
#ifdef MT6205
   ASSERT((DRV_Reg(AUXADC_CTRL) == channel) && (l1_adc_start_measure==KAL_TRUE));
   data = DRV_Reg(AUXADC_DATA);
   adc_sche_start_measure = l1_adc_start_measure_bak;
   
   l1_adc_start_measure = KAL_FALSE;
   if (!l1_adc_start_measure_bak)
   {
 	   DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC); 	
 	}
 	else
 	   DRV_WriteReg(AUXADC_CTRL,l1_adc_channel_bak);
 	return data;
#endif   /*MT6205*/
#if ( (defined(MT6205B)) || (defined(MT6218)))
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();	
   data = DRV_Reg(AUXADC_DAT(channel));
   if ((DRV_Reg(AUXADC_SYNC)==0) &&
       (DRV_Reg(AUXADC_SYN)==0)
      )
   {
      if (adc_imm_mode_cnt == 0)
      {
         DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);    
      }
      adc_sync_mode_on = KAL_FALSE;
   }
   RestoreIRQMask(savedMask);
   return data;
#endif   /*MT6205B,MT6218*/
   return 0;
}

void adc_parameter_modify(void *data)
{
   
}

#if ( (defined(MT6205B)) || (defined(MT6218)))
void adc_tdma_time_setup(kal_uint16 idle_time, kal_uint16 trx_time)
{
   DRV_WriteReg(AUXADC_TDMA_EVENT0,trx_time);
   DRV_WriteReg(AUXADC_TDMA_EVENT1,idle_time);
   DRV_WriteReg(AUXADC_TDMA_EN,(AUXADC_TDMA_EN_EVT0|AUXADC_TDMA_EN_EVT1));
}

/*Called in L1D*/
void adc_rach_measure_start(void)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif
}
#endif   /*MT6205B,MT6218*/

void l1_adc_imm_measure(kal_uint8 channel)
{
#ifdef MT6205
   l1_adc_start_measure_bak = adc_sche_start_measure;
   if (!l1_adc_start_measure_bak)
   {
      DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);      
   }
   l1_adc_channel_bak = DRV_Reg(AUXADC_CTRL);

   DRV_WriteReg(AUXADC_CTRL,channel);
   adc_sche_start_measure = KAL_TRUE;
   l1_adc_start_measure = KAL_TRUE;
#endif   /*MT6205*/
#if ( (defined(MT6205B)) || (defined(MT6218)))
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();	
   DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC); 
   adc_imm_mode_cnt++;
   DRV_Reg(AUXADC_IMM) |= (1<<channel);
   RestoreIRQMask(savedMask);
#endif   /*MT6205B,MT6218*/
}

/*Called in L1D*/
kal_uint16 l1_adc_imm_readback(kal_uint8 channel)
{
   kal_uint16  data;
#ifdef MT6205
   ASSERT((DRV_Reg(AUXADC_CTRL) == channel) && (l1_adc_start_measure==KAL_TRUE));
   data = DRV_Reg(AUXADC_DATA);
   adc_sche_start_measure = l1_adc_start_measure_bak;

   l1_adc_start_measure = KAL_FALSE;
   if (!l1_adc_start_measure_bak)
   {
 	   DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC); 	   
 	}
 	else
 	   DRV_WriteReg(AUXADC_CTRL,l1_adc_channel_bak);
 	return data;
#endif   /*MT6205*/
#if ( (defined(MT6205B)) || (defined(MT6218)))
   kal_uint32 savedMask;

   data = DRV_Reg(AUXADC_DAT(channel));
   savedMask = SaveAndSetIRQMask();	
   DRV_Reg(AUXADC_IMM) &= ~(1<<channel);
   adc_imm_mode_cnt--;
   if ((DRV_Reg(AUXADC_SYNC)==0) &&
       (DRV_Reg(AUXADC_SYN)==0)
      )
   {
      if (adc_imm_mode_cnt == 0)
      {
         DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);   
         adc_sync_mode_on = KAL_FALSE;
      }
   }
   RestoreIRQMask(savedMask);
   return data;
#endif   /*MT6205B,MT6218*/
   return 0;
}
/*
* FUNCTION
*	   volt2temp
*
* DESCRIPTION                                                           
*   	This function is to translate voltage to temperatrure
*
* CALLS  
*
* PARAMETERS
*	   voltage(uV)
*	
* RETURNS
*	   temperature(m'C)
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 volt2temp(kal_int32 _volt)
{
   VolToTempStruct *vol_temp_slope;
   vol_temp_slope=bmt_get_customized_volTOtemp();
   if(_volt>TEMPV2)
           return ((vol_temp_slope->TEMPA12+(_volt*vol_temp_slope->TEMPM12/vol_temp_slope->TEMPSCALE))/1000);
   else
           return ((vol_temp_slope->TEMPA23+(_volt*vol_temp_slope->TEMPM23/vol_temp_slope->TEMPSCALE))/1000);

//   return ((76576100-(_volt*634/10))/1000);
}	 


