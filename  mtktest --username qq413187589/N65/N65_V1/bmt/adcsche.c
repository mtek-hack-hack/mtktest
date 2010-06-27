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
 *    adcsche.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines ADC scheduler.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

static kal_uint8 adc_sche_id_no;
static kal_uint32 adc_reg_status;
/*compute from adc_sche_sum and adc_sche_count*/
double ADC_RESULT[MAX_CHANNEL];
kal_int32 VOL_RESULT[MAX_CHANNEL];
kal_uint8 adc_sche_vbat_id;   /*special*/
MeasParameter adc_parameters[MAX_CHANNEL];
kal_uint32 adc_sche_sum[MAX_CHANNEL];	
kal_uint32 adc_sche_count[MAX_CHANNEL];

kal_uint32 adc_sche_rw_status;
kal_bool adc_sync_mode_on = KAL_TRUE;
kal_uint16 adc_imm_mode_cnt = 0;

#ifdef MT6205
   kal_bool adc_sche_start_measure;
   kal_uint8 adc_sche_channel;   /*just for debug*/
   extern kal_bool l1_adc_start_measure;  /*for L1 Measure*/
#endif   /*MT6205*/

extern void adc_pwrdown_enable(void);
extern void adc_pwrdown_disable(void);
extern void adc_sche_timer_init(void);
extern event_scheduler     *adc_sche_event_scheduler_ptr;
extern kal_int32 adc_adc2vol(kal_uint8 chann,double adcVoltage);
//extern const kal_uint16 adc_volt_factor[ADC_MAX_CHANNEL];
extern void adc_sche_stop_timer(kal_uint8 adc_sche_id);
extern void adc_sche_set_timer(kal_uint8 adc_sche_id, kal_uint32 tick, kal_timer_func_ptr call_func);
extern MeasParameter adc_parameters[MAX_CHANNEL];

/*
* FUNCTION
*	   adc_sche_measure
*
* DESCRIPTION                                                           
*   	This function is to measure ADC channel.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_measure(void* msg_ptr)
{
   MeasParameter *adc_param = (MeasParameter *)msg_ptr;

#if ( (defined(MT6205B))||defined(MT6226M) || (defined(MT6218))|| (defined(MT6218B))|| (defined(MT6219))|| (defined(MT6217))|| (defined(MT6225))|| (defined(MT6228))|| (defined(MT6229))|| (defined(MT6230))|| (defined(MT6226))|| (defined(MT6227)))
   #ifdef BMT_DEBUG
   //dbg_printWithTime("mea,%d..\r\n",adc_param->adc_logic_id);
   #endif
   #if 0
/* under construction !*/
/* under construction !*/
   #endif
   adc_parameters[adc_param->adc_logic_id].adc_sche_event_id = NULL;
   
   if (adc_parameters[adc_param->adc_logic_id].conti_measure)
   {
      #if !defined(__CHARGER_WITH_IMMEDIMATE_ADC__)   
      kal_uint32 savedMask;

      savedMask = SaveAndSetIRQMask();	
      adc_sync_mode_on = KAL_TRUE;
      adc_pwrdown_disable();
      DRV_Reg(AUXADC_SYNC) |= (1<<adc_param->adc_phy_id);
      RestoreIRQMask(savedMask);
      #endif
      adc_sche_rw_status |= (1 << adc_param->adc_logic_id);
      adc_sche_set_timer(adc_param->adc_logic_id,1,adc_sche_readback);
   }
#endif      /*MT6205B,MT6218, MT6218B*/
}
/*Specific measure function for BMT*/
void bmt_adc_sche_measure(void* msg_ptr)
{
   MeasParameter *adc_param = (MeasParameter *)msg_ptr;
   static kal_uint8 bmt_measure_count=0;
   static kal_uint8 bmt_measure_channels=0; 
   kal_uint8 index=0;
#if ( (defined(MT6205B))||defined(MT6226M) || (defined(MT6218))|| (defined(MT6218B))|| (defined(MT6219))|| (defined(MT6217))|| (defined(MT6225))|| (defined(MT6228))|| (defined(MT6229))|| (defined(MT6230))|| (defined(MT6226))|| (defined(MT6227)))

   adc_parameters[adc_param->adc_logic_id].adc_sche_event_id = NULL;
      
   if (adc_parameters[adc_param->adc_logic_id].conti_measure)
   {
      bmt_measure_count++;
      adc_sche_rw_status |= (1 << adc_param->adc_logic_id);
      bmt_measure_channels|= (1<<adc_param->adc_phy_id);
      if(bmt_measure_count>=BMT_MAX_CHANNEL) 
      {
         #if !defined(__CHARGER_WITH_IMMEDIMATE_ADC__)   
         kal_uint32 savedMask;

         savedMask = SaveAndSetIRQMask();	
         adc_sync_mode_on = KAL_TRUE;
         adc_pwrdown_disable();
         DRV_Reg(AUXADC_SYNC) |= bmt_measure_channels;      
         RestoreIRQMask(savedMask);
         #endif
         for(index=0;index<BMT_MAX_CHANNEL;index++)
	      {  
	         adc_sche_set_timer(bmt_bmtid_adcscheid[index],1,bmt_adc_sche_readback);
         }
         bmt_measure_count=0;
         bmt_measure_channels=0;
      }   
   }
#endif      /*MT6205B,MT6218,MT6218B*/
}



/*
* FUNCTION
*	   adc_sche_readback
*
* DESCRIPTION                                                           
*   	This function is to readback the value from ADC channel.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
#if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)
static kal_int32 Pre_VOL_RESULT[ADC_MAX_CHANNEL]={0};
static kal_uint16 adc_filter_count=0;
#define ADC_FILTER_RANGE 300000
#define ADC_FILTER_COUNT 10
#endif
void adc_sche_readback(void* msg_ptr)
{
   kal_uint32 savedMask;
   MeasParameter *adc_param = (MeasParameter *)msg_ptr;
   kal_uint16 data;
   #if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)
   kal_int32 volt, diff;
   #endif

#if ( (defined(MT6205B))||defined(MT6226M) || (defined(MT6218))|| (defined(MT6218B))|| (defined(MT6219))|| (defined(MT6217))|| (defined(MT6225))|| (defined(MT6228))|| (defined(MT6229))|| (defined(MT6230))|| (defined(MT6226))|| (defined(MT6227)))

   adc_parameters[adc_param->adc_logic_id].adc_sche_event_id = NULL;
   #if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)   
   //adc_pwrdown_disable();
   data = ADC_GetData(adc_param->adc_phy_id);	
	volt = (kal_int32)((adc_adc2vol(adc_param->adc_phy_id, (double)data)/100)*bmt_charing_para->adc_volt_factor[adc_param->adc_phy_id]);
   
	if(Pre_VOL_RESULT[adc_param->adc_phy_id]==0)
	{
		Pre_VOL_RESULT[adc_param->adc_phy_id]=volt;
	}
	else
	{
		diff=Pre_VOL_RESULT[adc_param->adc_phy_id]-volt;
		if(diff>ADC_FILTER_RANGE||diff<-ADC_FILTER_RANGE)
		{
			adc_filter_count++;						
			kal_prompt_trace(MOD_BMT,"phy id: %d", adc_param->adc_phy_id);
			kal_prompt_trace(MOD_BMT,"volt: %d", Pre_VOL_RESULT[adc_param->adc_phy_id]);
			kal_prompt_trace(MOD_BMT,"curr volt: %d", volt);			
			if(adc_filter_count>=ADC_FILTER_COUNT)
				Pre_VOL_RESULT[adc_param->adc_phy_id]=0;
			adc_sche_set_timer(adc_param->adc_logic_id,1,adc_sche_readback);				
			return;
		}
		adc_filter_count=0;								
		Pre_VOL_RESULT[adc_param->adc_phy_id]=volt;
	}		
   #else
   while(DRV_Reg(AUXADC_SYNC)&(1<<adc_param->adc_phy_id));
   data = DRV_Reg(AUXADC_DAT(adc_param->adc_phy_id));
   #endif
   adc_sche_rw_status &= ~(1 << adc_param->adc_logic_id);

   savedMask = SaveAndSetIRQMask();
   if ((DRV_Reg(AUXADC_SYNC)==0) && 
       ((DRV_Reg(AUXADC_SYN) & AUXADC_SYN_BIT)==0)
      )
   {
      adc_sync_mode_on = KAL_FALSE;
      if (adc_imm_mode_cnt == 0)
      {
         adc_pwrdown_enable();
      }
   }
   RestoreIRQMask(savedMask);

 	if (adc_parameters[adc_param->adc_logic_id].conti_measure)
 	{
 	   adc_sche_sum[adc_param->adc_logic_id] += data;
 	   adc_sche_count[adc_param->adc_logic_id]++;
 	   adc_sche_set_timer(adc_param->adc_logic_id,adc_parameters[adc_param->adc_logic_id].period,adc_sche_measure);
 	}
#endif      /*MT6205B,MT6218,MT6218B*/
   
 	if (adc_sche_count[adc_param->adc_logic_id] >= adc_parameters[adc_param->adc_logic_id].evaluate_count)
 	{
 	   ADC_RESULT[adc_param->adc_logic_id] = (double)((double)adc_sche_sum[adc_param->adc_logic_id]/(double)adc_sche_count[adc_param->adc_logic_id] );
 	   VOL_RESULT[adc_param->adc_logic_id] = (kal_int32)((adc_adc2vol(adc_param->adc_phy_id,ADC_RESULT[adc_param->adc_logic_id])/100)*bmt_charing_para->adc_volt_factor[adc_param->adc_phy_id]);

 	   adc_sche_count[adc_param->adc_logic_id] = 0;
 	   adc_sche_sum[adc_param->adc_logic_id] = 0;
 	   if ((adc_parameters[adc_param->adc_logic_id].complete != NULL) && (adc_parameters[adc_param->adc_logic_id].conti_measure == KAL_TRUE))
 	      adc_parameters[adc_param->adc_logic_id].complete(adc_param->adc_logic_id);
 	      /* VOL_RESULT[adc_sche_id],ADC_RESULT[adc_sche_id] */
 	}
}
/*BMT readback function*/
void bmt_adc_sche_readback(void* msg_ptr)
{
   kal_uint32 savedMask;
   MeasParameter *adc_param = (MeasParameter *)msg_ptr;
   kal_uint16 data;
   #if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)
   kal_int32 volt, diff;
   #endif

#if ( (defined(MT6205B))||defined(MT6226M) || (defined(MT6218))|| (defined(MT6218B))|| (defined(MT6219))|| (defined(MT6217))|| (defined(MT6225))|| (defined(MT6228))|| (defined(MT6229))|| (defined(MT6230))|| (defined(MT6226))|| (defined(MT6227)))

   adc_parameters[adc_param->adc_logic_id].adc_sche_event_id = NULL;   
   #if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)   
   //adc_pwrdown_disable();
   data = ADC_GetData(adc_param->adc_phy_id);	
	volt = (kal_int32)((adc_adc2vol(adc_param->adc_phy_id, (double)data)/100)*bmt_charing_para->adc_volt_factor[adc_param->adc_phy_id]);
   
	if(Pre_VOL_RESULT[adc_param->adc_phy_id]==0)
	{
		Pre_VOL_RESULT[adc_param->adc_phy_id]=volt;
	}
	else
	{
		diff=Pre_VOL_RESULT[adc_param->adc_phy_id]-volt;
		if(diff>ADC_FILTER_RANGE||diff<-ADC_FILTER_RANGE)
		{
			adc_filter_count++;
			if(adc_filter_count>=ADC_FILTER_COUNT)
				Pre_VOL_RESULT[adc_param->adc_phy_id]=0;
			kal_prompt_trace(MOD_BMT,"phy id: %d", adc_param->adc_phy_id);
			kal_prompt_trace(MOD_BMT,"pre volt: %d", Pre_VOL_RESULT[adc_param->adc_phy_id]);
			kal_prompt_trace(MOD_BMT,"curr volt: %d", volt);
			adc_sche_set_timer(adc_param->adc_logic_id,1,bmt_adc_sche_readback);				
			return;
		}			
		adc_filter_count=0;		
		Pre_VOL_RESULT[adc_param->adc_phy_id]=volt;
	}		   		
   #else
   while(DRV_Reg(AUXADC_SYNC)&(1<<adc_param->adc_phy_id));
      data = DRV_Reg(AUXADC_DAT(adc_param->adc_phy_id));
   #endif   
      
   adc_sche_rw_status &= ~(1 << adc_param->adc_logic_id);

   savedMask = SaveAndSetIRQMask();
   if ((DRV_Reg(AUXADC_SYNC)==0) && 
       ((DRV_Reg(AUXADC_SYN) & AUXADC_SYN_BIT)==0)
      )
   {
      adc_sync_mode_on = KAL_FALSE;
      if (adc_imm_mode_cnt == 0)
      {
         adc_pwrdown_enable();
      }
   }
  	RestoreIRQMask(savedMask);

 	if (adc_parameters[adc_param->adc_logic_id].conti_measure)
 	{
 	   adc_sche_sum[adc_param->adc_logic_id] += data;
 	   adc_sche_count[adc_param->adc_logic_id]++;
 	   adc_sche_set_timer(adc_param->adc_logic_id,adc_parameters[adc_param->adc_logic_id].period,bmt_adc_sche_measure);
 	}
#endif      /*MT6205B,MT6218,MT6218B*/
   
 	if (adc_sche_count[adc_param->adc_logic_id] >= adc_parameters[adc_param->adc_logic_id].evaluate_count)
 	{
 	   ADC_RESULT[adc_param->adc_logic_id] = (double)((double)adc_sche_sum[adc_param->adc_logic_id]/(double)adc_sche_count[adc_param->adc_logic_id] );
 	   VOL_RESULT[adc_param->adc_logic_id] = (kal_int32)((adc_adc2vol(adc_param->adc_phy_id,ADC_RESULT[adc_param->adc_logic_id])/100)*bmt_charing_para->adc_volt_factor[adc_param->adc_phy_id]);

 	   adc_sche_count[adc_param->adc_logic_id] = 0;
 	   adc_sche_sum[adc_param->adc_logic_id] = 0;
 	   if ((adc_parameters[adc_param->adc_logic_id].complete != NULL) && (adc_parameters[adc_param->adc_logic_id].conti_measure == KAL_TRUE))
 	      adc_parameters[adc_param->adc_logic_id].complete(adc_param->adc_logic_id);
 	      /* VOL_RESULT[adc_sche_id],ADC_RESULT[adc_sche_id] */
 	}
}
/*
* FUNCTION
*	   adc_sche_create_object
*
* DESCRIPTION                                                           
*   	This function is to create a measure object and 
*  return a logical channel id.
*
* CALLS  
*
* PARAMETERS
*	   msgid: owner id;
*	   adc_channel: ADC channel no.
*	   period: The period of ADC measure.
*	   evaluate_count: Evaluate Count;
*	   send_primitive: Decide whether send primitive
*           (MSG_ID_BMT_ADC_MEASURE_DONE_CONF) to owner task.
*	
* RETURNS
*	   logical channel id.
*
* GLOBALS AFFECTED
*     None
*/
/*return the adc_sche_id*/
kal_uint8 adc_sche_create_object(module_type ownerid, kal_uint8 adc_channel,kal_uint32 period, kal_uint8 evaluate_count, kal_bool send_primitive)
{
   kal_uint8 adc_id;
   
   
   adc_id = adc_sche_id_no++;
   
   ASSERT(adc_id < MAX_CHANNEL);
   
   if (adc_channel == ADC_VBAT)
      adc_sche_vbat_id = adc_id;
      
   adc_parameters[adc_id].adc_phy_id = adc_channel;
   adc_parameters[adc_id].adc_logic_id = adc_id;
   adc_parameters[adc_id].ownerid = ownerid;
   adc_parameters[adc_id].period = period;
   adc_parameters[adc_id].evaluate_count = evaluate_count;
   adc_parameters[adc_id].send_primitive = send_primitive;
   adc_parameters[adc_id].complete = NULL;
   adc_parameters[adc_id].adc_sche_event_id = 0;
   
   adc_sche_sum[adc_id] = 0;
   adc_sche_count[adc_id] = 0;
   return adc_id;
}

/*
* FUNCTION
*	   adc_sche_modify_parameters
*
* DESCRIPTION                                                           
*   	This function is to modify the parameter of the measure object.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	   period: measure period.
*	   evaluate_count: Evaluate Count;
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_modify_parameters(kal_uint8 adc_sche_id, kal_uint32 period, kal_uint8 evaluate_count)
{
   ASSERT(adc_sche_id < adc_sche_id_no);
   adc_parameters[adc_sche_id].period = period;
   adc_parameters[adc_sche_id].evaluate_count = evaluate_count;
}

/*
* FUNCTION
*	   adc_sche_add_item
*
* DESCRIPTION                                                           
*   	This function is to add a measure object to adc scheduler.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	   mea_complete: callback when measure complete.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_add_item(kal_uint8 adc_sche_id, void (*mea_complete)(kal_uint8 adc_sche_id), kal_timer_func_ptr mea_Callback)
{
   ASSERT(adc_sche_id < adc_sche_id_no);
      
	if (adc_reg_status & (1<<adc_sche_id))
	   return;

	adc_reg_status |= (1<<adc_sche_id);
	adc_parameters[adc_sche_id].conti_measure = KAL_TRUE;
	adc_parameters[adc_sche_id].complete = mea_complete;
	adc_sche_sum[adc_sche_id] = 0;
   adc_sche_count[adc_sche_id] = 0;
   adc_sche_set_timer(adc_sche_id,1,mea_Callback);
}

/*
* FUNCTION
*	   adc_sche_remove_item
*
* DESCRIPTION                                                           
*   	This function is to remove a measure object from adc scheduler.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_remove_item(kal_uint8 adc_sche_id)
{
   ASSERT(adc_sche_id < adc_sche_id_no);
   if (adc_reg_status & (1<<adc_sche_id))
   {
      adc_parameters[adc_sche_id].conti_measure = KAL_FALSE;
      adc_reg_status &= ~(1<<adc_sche_id);
      adc_sche_sum[adc_sche_id] = 0;
      adc_sche_count[adc_sche_id] = 0;
      adc_sche_rw_status &= ~(1 << adc_parameters[adc_sche_id].adc_logic_id);
      adc_sche_stop_timer(adc_sche_id);
	}
}

/*
* FUNCTION
*	   adc_sche_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the adc scheduler.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_init(void)
{
	kal_uint8 index;
	
	adc_sche_timer_init();
	for(index=0;index<MAX_CHANNEL;index++)
	{
	   VOL_RESULT[index] = 0xffffffff;
		adc_sche_sum[index] = 0;
		adc_sche_count[index] = 0;
	}
	adc_sche_rw_status  = 0;
}

#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add it 
const kal_uint8 ADC6_M_BATT = 6 ;
const kal_uint8 ADC4_S_BATT  =  4 ; 

extern  kal_uint16 g_adc_value_high ;
extern  kal_uint16 g_adc_value_low  ;

#define RANGEVALUE 10


_BATTI_STS_GROUP_ENUM_ get_main_batt_sta(void)
{
	kal_uint16 adc6_vol =0 ;
       kal_uint16   vol_temp;
	kal_uint8  state = BATT_STATE_LEVEL0; 
	kal_uint8 index = 0 ; 
	kal_uint8 result = 0 ; 
	static 	kal_uint8 LastVol = 0 ; 
	static 	kal_uint8 LastLevel = 0 ; 
	#ifndef WIN32   
	//Huyanwei Add It 
	adc6_vol = ADC_GetData(ADC6_M_BATT);
	#endif
#if defined(NOKE_DEBUG)
	noke_dbg_printf("main bat adc6_vol = %d\n\r ",adc6_vol);   
#endif
	if (adc6_vol)
	{
		if( g_adc_value_low <= g_adc_value_high )
		{
			vol_temp = (adc6_vol+78)/2;
#if defined(NOKE_DEBUG)
			noke_dbg_printf("Default Method\r\n");
#endif
		}
		else
		{
			vol_temp = 340+(kal_uint16) ((80.0*(adc6_vol-g_adc_value_high))/(g_adc_value_low-g_adc_value_high)) ;
		}

#if defined(NOKE_DEBUG)
		noke_dbg_printf("main bat vol_temp = %d\n\r ",vol_temp);
#endif
		if (vol_temp < 100)
		{
			state = BATT_STATE_NO_BAT; 
			LastVol = 0 ;
			LastLevel = BATT_STATE_NO_BAT;
			while( (vol_temp < 100 ) && ( index < 5))
			{
			#ifndef WIN32   
				//Huyanwei Add It 
				adc6_vol = ADC_GetData(ADC6_M_BATT);
			#endif
				if(adc6_vol)
				{
					if( g_adc_value_low <= g_adc_value_high )
					{
						vol_temp = (adc6_vol+78)/2;
					}
					else
					{
						vol_temp = 340+(kal_uint16) ((80.0*(adc6_vol-g_adc_value_high))/(g_adc_value_low-g_adc_value_high)) ;
					}
					if(vol_temp < 100)
					{
						result++;
					}
					else
					{
						if ((vol_temp >= 320)&&(vol_temp <= 350))
						{
							if( (vol_temp - LastVol  >= RANGEVALUE)  ||  ( LastVol - vol_temp  >=  RANGEVALUE) )
							{
								state = BATT_STATE_LEVEL1;
								LastLevel = BATT_STATE_LEVEL1 ;
								LastVol = vol_temp ;
							}
							else
							{
								state = LastLevel ;
							}
						}
						else if ((vol_temp >= 350)&&(vol_temp <= 370))
						{
							if( (vol_temp - LastVol  >= RANGEVALUE)  ||  ( LastVol - vol_temp  >=  RANGEVALUE) )
							{
								state = BATT_STATE_LEVEL2;
								LastLevel = BATT_STATE_LEVEL2 ;
								LastVol = vol_temp ;
							}
							else
							{
								state = LastLevel ;
							}
						}
						else if ((vol_temp >= 370)&&(vol_temp <= 390))
						{
							if( (vol_temp - LastVol  >= RANGEVALUE)  ||  ( LastVol - vol_temp  >= RANGEVALUE) )
							{
								state = BATT_STATE_LEVEL3;
								LastLevel = BATT_STATE_LEVEL3 ;
								LastVol = vol_temp ;
							}
							else
							{
								state = LastLevel ;
							}
						}
						else if ((vol_temp >= 390))
						{
							if( (vol_temp - LastVol  >= RANGEVALUE)  ||  ( LastVol - vol_temp  >=  RANGEVALUE) )
							{
								state = BATT_STATE_LEVEL4;
								LastLevel = BATT_STATE_LEVEL4 ;
								LastVol = vol_temp ;
							}
							else
							{
								state = LastLevel ;
							}
						}
					}
					if(result >= 3)
					{
						state = BATT_STATE_NO_BAT; 
						LastLevel = BATT_STATE_NO_BAT;
						LastVol = 0 ;
						break ;
					}
				}
				index ++ ;
			}
		}
		else 
		{
			if ((vol_temp >= 320)&&(vol_temp < 350))
			{
				if ( (vol_temp - LastVol > RANGEVALUE ) || (LastVol - vol_temp) > RANGEVALUE)
				{
					state = BATT_STATE_LEVEL1;
					LastLevel = BATT_STATE_LEVEL1;
					LastVol = vol_temp ;
				}
				else
				{
					state = LastLevel ;
				}
			}
			else if ((vol_temp >= 350)&&(vol_temp < 370))
			{
				if ( (vol_temp - LastVol > RANGEVALUE ) || (LastVol - vol_temp) > RANGEVALUE)
				{
					state = BATT_STATE_LEVEL2;
					LastLevel = BATT_STATE_LEVEL2;
					LastVol = vol_temp ;
				}
				else
				{
					state = LastLevel ;
				}
			}
			else if ((vol_temp >= 370)&&(vol_temp < 390))
			{
				if ( (vol_temp - LastVol > RANGEVALUE ) || (LastVol - vol_temp) > RANGEVALUE)
				{
					state = BATT_STATE_LEVEL3;
					LastLevel = BATT_STATE_LEVEL3;
					LastVol = vol_temp ;
				}
				else
				{
					state = LastLevel ;
				}

			}
			else if ((vol_temp >= 390))
			{
				if ( (vol_temp - LastVol > RANGEVALUE ) || (LastVol - vol_temp) > RANGEVALUE)
				{
					state = BATT_STATE_LEVEL4;
					LastLevel = BATT_STATE_LEVEL4;
					LastVol = vol_temp ;
				}
				else
				{
					state = LastLevel ;
				}
			}
		}
		
	}
#if defined(NOKE_DEBUG)
	noke_dbg_printf("main bat voltage level = %d\n\r ",state);
#endif
	return state;
}


_BATTI_STS_GROUP_ENUM_ get_sub_batt_sta(void)
{
	
	kal_uint16 adc4_vol = 0;
	kal_uint16   vol_temp;
	kal_uint8  state = BATT_STATE_LEVEL0;
	kal_uint8 index = 0 ; 
	static 	kal_uint8 LastVol = 0 ; 
	static 	kal_uint8 LastLevel = 0 ; 
	#ifndef WIN32   
	//Huyanwei Add It 
       	adc4_vol = ADC_GetData(ADC4_S_BATT);
	#endif
#if defined(NOKE_DEBUG)
	noke_dbg_printf("sub bat adc4_vol = %d\n\r ",adc4_vol); 
#endif
	if (adc4_vol)
	{
		if( g_adc_value_low <= g_adc_value_high )
		{
			vol_temp = (adc4_vol+78)/2;
#if defined(NOKE_DEBUG)
			noke_dbg_printf("Default Method\r\n");
#endif
		}
		else
		{
			vol_temp = 340+(kal_uint16) ((80.0*(adc4_vol-g_adc_value_high))/(g_adc_value_low-g_adc_value_high)) ;
		}
		
#if defined(NOKE_DEBUG)		
		noke_dbg_printf("sub bat vol_temp = %d\n\r ",vol_temp); 
#endif
		#if 0
		if (vol_temp < 10)
		{
			while( (vol_temp < 10) && (index < 3) )
			{
				adc4_vol = ADC_GetData(ADC4_S_BATT);
				if (adc4_vol)
				{
					if( g_adc_value_low <= g_adc_value_high )
					{
						vol_temp = (adc4_vol+78)/20;
					}
					else
					{
						vol_temp = 34+(kal_uint16) ((8.0*(adc4_vol-g_adc_value_high))/(g_adc_value_low-g_adc_value_high)) ;
					}
				}	
				index ++ ;
			}
			state = BATT_STATE_NO_BAT; 
		}
		#else
		if(0 == ExistSubBattery())
		{
			state = BATT_STATE_NO_BAT; 
			LastLevel = BATT_STATE_NO_BAT ; 
			LastVol     = 0 ; 
		}
		#endif
		else
		{
			if ((vol_temp >= 320)&&(vol_temp < 350))
			{
				if( (vol_temp - LastVol  >= RANGEVALUE)  ||  ( LastVol - vol_temp  >=  RANGEVALUE) )
				{
					state = BATT_STATE_LEVEL1;
					LastLevel = BATT_STATE_LEVEL1 ;
					LastVol = vol_temp ;
				}
				else
				{
					state = LastLevel ;
				}
			}
			else if ((vol_temp >= 350)&&(vol_temp < 370))
			{
				if( (vol_temp - LastVol  >= RANGEVALUE)  ||  ( LastVol - vol_temp  >=  RANGEVALUE) )
				{
					state = BATT_STATE_LEVEL2;
					LastLevel = BATT_STATE_LEVEL2 ;
					LastVol = vol_temp ;					
				}
				else
				{
					state = LastLevel ;
				}

			}
			else if ((vol_temp >= 370)&&(vol_temp < 390))
			{
				if( (vol_temp - LastVol  >= RANGEVALUE)  ||  ( LastVol - vol_temp  >=  RANGEVALUE) )
				{
					state = BATT_STATE_LEVEL3;
					LastLevel = BATT_STATE_LEVEL3 ;
					LastVol = vol_temp ;					
				}
				else
				{
					state = LastLevel ;
				}
			}
			else if ((vol_temp >= 390))
			{
				if( (vol_temp - LastVol  >= RANGEVALUE)  ||  ( LastVol - vol_temp  >=  RANGEVALUE) )
				{
					state = BATT_STATE_LEVEL4;
					LastLevel = BATT_STATE_LEVEL4 ;
					LastVol = vol_temp ;					
				}
				else
				{
					state = LastLevel ;
				}
			}
		}
	}
#if defined(NOKE_DEBUG)
	noke_dbg_printf("sub bat voltage level = %d\n\r ",state);
#endif
	return state;
}
#endif



