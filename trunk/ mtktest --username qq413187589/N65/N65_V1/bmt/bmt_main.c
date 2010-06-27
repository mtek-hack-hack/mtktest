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
 *    BMT_main.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines main function of the BMT task.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include    "syscomp_config.h"   /*MOD_BMT*/
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include    "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include    "event_shed.h"       /* Event scheduler */
#include    "stack_timer.h"     /*Timer*/
#include    "app_buff_alloc.h"   /*buffer*/
#include    "task_config.h"      /* Task creation */
#include    "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include    "reg_base.h"
#include    "pwic.h"
#include    "adc.h"
#include    "bmt.h"
#include    "adcsche.h"
#include    "batvalue.h"
#include    "nvram_struct.h"
#include    "nvram_enums.h"
#include    "nvram_data_items.h"
#include    "nvram.h"
#include    "nvram_interface.h"
#include    "nvram_user_defs.h"
#include		"bmt_trc.h"
#include		"eint.h"
#include    "drvsignals.h"
#include 	"gpt_sw.h"
#if defined(MT6318)
#include 	"pmic6318_sw.h"
#include 	"b2psi_sw.h"
extern pmic_chrdect_callbac_struct PMIC_CHRDET;   
#endif
extern const kal_uint8 gCHRDET_EINT_NO;
#if ( defined(MT6218B)||defined(MT6226M) || defined(MT6219)|| (defined(MT6217))|| (defined(MT6225))|| (defined(MT6228))|| (defined(MT6229))|| defined(MT6230)|| (defined(MT6226))|| (defined(MT6227)) )
   #if (defined(__GSM_MODE__) && defined(__GPRS_MODE__))
      #define PERIOD_RST_TO_DRVINT 1000
   #else
      #define PERIOD_RST_TO_DRVINT 100
   #endif
#endif
extern void WDT_Enable(kal_bool en);
extern void adc_sche_init(void);
extern void bmt_adc_init(void);
extern void bmt_charge_start(void);
extern void bmt_charge_end(void);
extern void BMT_CHARSTOP(void);
extern void CHRDET_HISR(void);
extern kal_bool INT_USBBoot(void);
extern Customer_Period_Period(void);

extern BMTStruct BMT;
extern stack_timer_struct      *timer_adcsche;   /*Normal Measure, only monitor VBAT*/
extern stack_timer_struct      *timer_stopcharge;
extern MeasParameter adc_parameters[MAX_CHANNEL];
extern double ADC_RESULT[MAX_CHANNEL];
extern kal_int32 VOL_RESULT[MAX_CHANNEL];
extern event_scheduler     *adc_sche_event_scheduler_ptr;
extern kal_uint32 VBAT_OFF;
extern double ADCBAT_OFF;
extern void adc_sche_modify_parameters(kal_uint8 adc_sche_id, kal_uint32 period, kal_uint8 evaluate_count);
extern void adc_sche_add_item(kal_uint8 adc_sche_id, void (*mea_complete)(kal_uint8 adc_sche_id), kal_timer_func_ptr mea_Callback);
extern void adc_sche_remove_item(kal_uint8 adc_sche_id);
extern kal_uint8 adc_sche_create_object(module_type ownerid, kal_uint8 adc_channel,kal_uint32 period, kal_uint8 evaluate_count, kal_bool send_primitive);
//extern ADC_CALIDATA adc_cali_param;
extern void chrdet_level_config(kal_uint8 state);
extern stack_timer_struct      ChargeTimeout_timer;
//#ifdef PMIC_PRESENT
#if ( (defined(MT6318))|| (defined(MT6305)) )
static Charger_Status previous_chr_status=0xff;
#endif
static Charger_Status chr_status;
static kal_uint8 chr_read_flag;
#if defined(__USB_ENABLE__)
static bmt_usb_state_enum bmt_usb_state = USB_INIT_STATE;

// KAL_TRUE: enable usb charging without host's grant. 
// KAL_FALSE: enable usb charging with host's permission.
//extern const kal_bool enable_usb_charge;
#ifdef __USB_MULTI_CHARGE_CURRENT__
extern void usb_set_chr_current(kal_uint8 index);
extern const kal_uint8 USB_GetChargeCurrentTableSize(void);
#endif /* __USB_MULTI_CHARGE_CURRENT__ */

#endif

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
extern void USB_EINT_HISR(void);
extern void CHRDET_HISR(void);
chr_usb_detect_struct chr_usb_detect;
#endif //__CHARGER_USB_DETECT_WIHT_ONE_EINT__

bmt_customized_struct *bmt_charing_para;

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
/*************************************************************************
* FUNCTION
*	charger_or_usb
*
* DESCRIPTION
*	1. call back function of adc scheduler 
*	2. judge if charger or usb plugged in by adc measurement
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
static void check_charger_or_usb(kal_uint8 sche_id)
{
   #if defined(MT6305) || defined(MT6318)
   extern charger_usb_present_enum bmt_check_ac_usb(kal_int32 vol);
	kal_int32 volt;	
	charger_usb_present_enum state;	
	adc_sche_remove_item(chr_usb_detect.chr_usb_adc_logical_id);
	volt= VOL_RESULT[chr_usb_detect.chr_usb_adc_logical_id];
	USB_PowerControl(KAL_FALSE);
	kal_prompt_trace(MOD_BMT,"volt: %d", volt);
	state=bmt_check_ac_usb(volt);
	//if(volt<chr_usb_detect.chr_usb_volt)
	if(BMT.PWRon==USBPWRON||BMT.PWRon==USBPWRON_WDT||state==USB_PRESENT)
	{
		kal_prompt_trace(MOD_BMT,"USB IN");
		chr_usb_detect.chr_usb_present = USB_PRESENT;
		CHRDET_HISR();
		USB_EINT_HISR();		
	}
	else if (BMT.PWRon==CHRPWRON||BMT.PWRon==PRECHRPWRON||state==CHARGER_PRESENT)
	{
		kal_prompt_trace(MOD_BMT,"AC IN");
		chr_usb_detect.chr_usb_present = CHARGER_PRESENT;
		CHRDET_HISR();
	}
	
	EINT_UnMask(chr_usb_detect.chr_usb_eint);	
	
	#endif
	
	#if 0 //defined(MT6318)/*XXXXX*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
}	

/*************************************************************************
* FUNCTION
*	CHRDET_USB_HISR
*
* DESCRIPTION
*	1. HISR of charger and usb external interrupt
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
static void CHR_USB_EINT_HISR(void)
{
   #if defined(MT6305) || defined(MT6318)
   #if defined(MT6305)
	EINT_Set_Polarity(chr_usb_detect.chr_usb_eint,chr_usb_detect.chr_usb_state);
   #endif /* MT6305 */
	
	chr_usb_detect.chr_usb_state = !chr_usb_detect.chr_usb_state;	
	if(chr_usb_detect.chr_usb_state)
	{	
		kal_prompt_trace(MOD_BMT,"CHR_USB IN");
		USB_PowerControl(KAL_TRUE);
		adc_sche_set_timer_page_align(KAL_FALSE);
		adc_sche_add_item(chr_usb_detect.chr_usb_adc_logical_id,check_charger_or_usb,adc_sche_measure);
	}
	else
	{
		kal_prompt_trace(MOD_BMT,"CHR_USB OUT");
		if(chr_usb_detect.chr_usb_present == USB_PRESENT)
		{
			CHRDET_HISR();
			USB_EINT_HISR();
		}
		else if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT)
			CHRDET_HISR();
		else
			ASSERT(0);	
		chr_usb_detect.chr_usb_present = NO_PRESENT;
		adc_sche_set_timer_page_align(KAL_TRUE);
		EINT_UnMask(chr_usb_detect.chr_usb_eint);	
	}   
	#endif
   
	#if 0 //defined(MT6318)/*XXXXX*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}

#endif //__CHARGER_USB_DETECT_WIHT_ONE_EINT__

void adc_sche_task_complete_callback(kal_uint8 adc_sche_id)
{
#ifndef L4_NOT_PRESENT
   ilm_struct *BMT_ilm;

	bmt_adc_measure_done_conf_struct *BMT_Prim;
	
	if (adc_parameters[adc_sche_id].send_primitive)
	{
	   BMT_Prim = (bmt_adc_measure_done_conf_struct*)
				   construct_local_para(sizeof(bmt_adc_measure_done_conf_struct), TD_CTRL);
		BMT_Prim->adc_sche_id = adc_sche_id;
	 	if(adc_parameters[adc_sche_id].adc_phy_id == ADC_BMT_VBAT &&
	 		adc_parameters[adc_sche_id].ownerid == MOD_UEM)
	 	{
	 		switch(BMT.VBAT_UEM)
	 		{
	 		case VBAT_UEM_CHR_OUT:
      			BMT_Prim->volt= VOL_RESULT[adc_sche_id];
      			BMT_Prim->adc_value = ADC_RESULT[adc_sche_id];			 
	 			break;
	 		case VBAT_UEM_CHR_IN:
			      BMT_Prim->volt= VBAT_OFF;
			      BMT_Prim->adc_value = ADCBAT_OFF;	
	 			break;	 		
	 		case VBAT_UEM_CHR_IN_FISRT:
			      BMT_Prim->volt= VOL_RESULT[adc_sche_id];
			      BMT_Prim->adc_value = ADC_RESULT[adc_sche_id];	
			      BMT.VBAT_UEM = VBAT_UEM_CHR_IN;
	 			break;
	 		case VBAT_UEM_CHR_OUT_FIRST:
			      BMT_Prim->volt= VBAT_OFF;
			      BMT_Prim->adc_value = ADCBAT_OFF;	
			      BMT.VBAT_UEM = VBAT_UEM_CHR_OUT;
	 			break;	 			
	 		}
	 	}
	 	else
	 	{	
		      BMT_Prim->volt= VOL_RESULT[adc_sche_id];
		      BMT_Prim->adc_value = ADC_RESULT[adc_sche_id];
		}
		if (adc_parameters[adc_sche_id].ownerid == MOD_L1)
		{
	      DRV_SendPrimitive(BMT_ilm,
                            MOD_BMT,
                            adc_parameters[adc_sche_id].ownerid,
                            MSG_ID_BMT_ADC_MEASURE_DONE_CONF,
                            BMT_Prim,
                            DRIVER_L1_SAP);
         msg_send_ext_queue(BMT_ilm);
        	} 
      		
      		else
      		{
	   DRV_BuildPrimitive(BMT_ilm,
                         MOD_BMT,
                         adc_parameters[adc_sche_id].ownerid,
                         MSG_ID_BMT_ADC_MEASURE_DONE_CONF,
                         BMT_Prim);
      msg_send_ext_queue(BMT_ilm);
   }
   }
#endif   /*L4_NOT_PRESENT*/
}


/*
* FUNCTION
*	   BMT_sendMes
*
* DESCRIPTION                                                           
*   	This function is used to send message to BMT task
*
* CALLS  
*
* PARAMETERS
*	   queue: BMT_QUEUE
*     message_id: the message id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
/*send to BMT task*/
void BMT_sendMes(module_type srcid, msg_type msgid)
{
   ilm_struct *BMT_ilm;
   
   DRV_BuildPrimitive(BMT_ilm,
                      srcid,
                      MOD_BMT,
                      msgid,
                      NULL);

   msg_send_ext_queue(BMT_ilm);
}

void BMT_sendMes2UEM(BMT_CHR_STAT status)
{
#ifndef L4_NOT_PRESENT
   ilm_struct *BMT_ilm;

	drvuem_pmic_ind_struct *BMT_Prim;

	BMT_Prim = (drvuem_pmic_ind_struct*)
				   construct_local_para(sizeof(drvuem_pmic_ind_struct), TD_CTRL);
   BMT_Prim->status= status;
   
   DRV_BuildPrimitive(BMT_ilm,
                      MOD_BMT,
                      MOD_UEM,
                      MSG_ID_DRVUEM_PMIC_IND,
                      BMT_Prim);
   
   msg_send_ext_queue(BMT_ilm);
#endif  /*L4_NOT_PRESENT*/
}

void bmt_set_chr_status(Charger_Status status)
{
   chr_status = status;
   if (chr_read_flag == 0)
   {
   	chr_read_flag = 1;
      BMT_sendMes(MOD_EINT_HISR/*MOD_BMT*/,MSG_ID_BMT_CHARGER_IND);
   }
}

Charger_Status bmt_read_chr_status(void)
{
   chr_read_flag = 0;
   return chr_status;
}

void bmt_adc_sche_add_item(local_para_struct *buf)
{
   bmt_adc_add_item_req_struct *ptr=(bmt_adc_add_item_req_struct *)buf;
   adc_sche_add_item(ptr->adc_sche_id,adc_sche_task_complete_callback, adc_sche_measure);
}

void bmt_adc_sche_remove_item(local_para_struct *buf)
{
   bmt_adc_remove_item_req_struct *ptr=(bmt_adc_remove_item_req_struct *)buf;
   adc_sche_remove_item(ptr->adc_sche_id);
}

void bmt_adc_sche_modify_parameters(local_para_struct *buf)
{
   bmt_adc_modify_parameters_req_struct *ptr=(bmt_adc_modify_parameters_req_struct *)buf;
   adc_sche_modify_parameters(ptr->adc_sche_id, ptr->period, ptr->evaluate_count);
}

#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) )
void bmt_adc_set_adc_calibration_data(ilm_struct *lim_ptr)
{
   kal_uint16     len;
   nvram_read_cnf_struct *parm_ptr = (nvram_read_cnf_struct *) lim_ptr->local_para_ptr;
   ADC_CALIDATA *pdu_ptr = (ADC_CALIDATA *)get_pdu_ptr(lim_ptr->peer_buff_ptr, &len);

   if( (parm_ptr->result == NVRAM_IO_ERRNO_OK) || (parm_ptr->result ==NVRAM_IO_ERRNO_INIT) )
   {
     if( parm_ptr->length != sizeof(ADC_CALIDATA) )
      ASSERT(0);

      kal_mem_cpy( &bmt_charing_para->adc_cali_param, pdu_ptr, sizeof(ADC_CALIDATA) );
   }
   else
      ASSERT(0);
}
#endif   /*(!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL))*/
void bmt_read_calibration_data(void)
{
   #ifdef __USB_ENABLE__   
   ADC_CALIDATA   pdu_ptr;
   ADC_CALIDATA   *adc_cali;
   kal_bool       result;   
   ilm_struct     *BMT_ilm;
   
   if(Drv_query_boot_mode()==USBMS_BOOT)
   {               
      //result=nvram_usb_get_bmt_cal((kal_uint8*) &pdu_ptr, sizeof(ADC_CALIDATA));      
      extern kal_bool nvram_usb_read_data(kal_uint8 LID, kal_uint8* buffer, kal_uint16 buffer_size);
      result=nvram_usb_read_data(NVRAM_EF_ADC_LID,(kal_uint8*) &pdu_ptr, sizeof(ADC_CALIDATA));            
      if(result==KAL_FALSE)
         ASSERT(0);
      adc_cali=(ADC_CALIDATA *)&pdu_ptr;
      #ifdef BMT_DEBUG
      dbg_printWithTime("ADC read cali result = %d\r\n", result);
      for(index=0;index<ADC_MAX_CHANNEL;index++)
      {
           dbg_printWithTime("ADC %d Slope= %d\r\n",index, adc_cali->ADCSlope[index]);
           dbg_printWithTime("ADC %d Offset= %d\r\n",index, adc_cali->ADCOffset[index]);
      }           
      #endif         
      kal_mem_cpy( &bmt_charing_para->adc_cali_param, adc_cali, sizeof(ADC_CALIDATA) );            
      DRV_BuildPrimitive(BMT_ilm,
                         MOD_BMT,
                         MOD_USB,
                         MSG_ID_BMT_USB_READ_CALI_DONE_IND,
                         NULL);
      
      msg_send_ext_queue(BMT_ilm);
   }   
   #endif
}
/*
* FUNCTION
*	   bmt_check_poweron
*
* DESCRIPTION                                                           
*   	This function is to check if AC/USB exists at CHRPWRON/USBPWRON
*
* CALLS  
*
* PARAMETERS
*	  
*	
* RETURNS
*	   Receive primitive from the specified queue.
*
* GLOBALS AFFECTED
*     None
*/


void bmt_check_poweron(kal_uint8 power_on)
{      
   kal_bool state=KAL_FALSE;
               
   state=bmt_is_chr_exist(power_on);
   
   if(power_on==CHRPWRON||power_on==PRECHRPWRON||
      power_on==USBPWRON||power_on==USBPWRON_WDT)   
   {           
      if(state==KAL_FALSE)
      {
       	while(1)
      	{
      		kal_uint32 delay=0;
         DRV_POWEROFF();
         	for(delay=0;delay<5000;delay++){};
         }	
      }   
   }             
}   

/*
* FUNCTION
*	   BMT_Task
*
* DESCRIPTION                                                           
*   	This function is used to send message to BMT task.
*     This Module defines main function of the BMT task.
*
* CALLS  
*
* PARAMETERS
*	  
*	
* RETURNS
*	   Receive primitive from the specified queue.
*
* GLOBALS AFFECTED
*     None
*/
void bmt_task_main(task_entry_struct *task_entry_ptr)
{
   ilm_struct	current_ilm;
   ilm_struct *BMT_ilm;
   drvuem_power_on_ind_struct *power_on_ind;
   kal_uint16    UEM_RECEIVE_PWR_IND=2012;    
#ifdef BMT_ACTIVE_TO_READ_NVRAM_DATA
   nvram_read_req_struct* nvram_read_req;
#endif   /*BMT_ACTIVE_TO_READ_NVRAM_DATA*/
#ifdef BMT_KAL_DEBUG   
   kal_trace(TRACE_FUNC, BMT_TASK_MAIN_TRC);
#endif   
   #ifdef BMT_DEBUG   
   dbg_printWithTime("=====================BMT_task_main=====================\r\n");
   #endif   /*BMT_DEBUG*/



#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (!defined(MT6305)) && (!defined(MT6318)))
   //if( INT_USBBoot() == KAL_FALSE )
   {
      #if ( defined(MT6218B)||defined(MT6226M) || defined(MT6219) || (defined(MT6217))|| (defined(MT6225))|| (defined(MT6228))|| (defined(MT6229))|| defined(MT6230)|| (defined(MT6226))|| (defined(MT6227)))		
      UEM_RECEIVE_PWR_IND=GPT_return_current_count()+PERIOD_RST_TO_DRVINT;
      GPT_Stop(3);
      #endif   
		power_on_ind = (drvuem_power_on_ind_struct *) construct_local_para(sizeof(drvuem_power_on_ind_struct),TD_UL);		    
		power_on_ind->power_on = BMT.PWRon;
	   if (UEM_RECEIVE_PWR_IND>Customer_Period_Period())
	      power_on_ind->poweron_time_left=0;
	   else
	      power_on_ind->poweron_time_left=Customer_Period_Period()-UEM_RECEIVE_PWR_IND;
      DRV_BuildPrimitive(BMT_ilm,
                         MOD_BMT,
                         MOD_UEM,
                         MSG_ID_DRVUEM_POWER_ON_IND,
                         power_on_ind);
      msg_send_ext_queue(BMT_ilm);
   		
   }
#endif   /*!L4_NOT_PRESENT&&!!DUMMY_PROTOCOL*/
#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (defined(MT6305)||defined(MT6318)) )
	#if !defined(__PRODUCTION_RELEASE__)
	ASSERT(BMT.PWRon != ABNRESET);
	#endif
   #if ( defined(MT6218B)||defined(MT6226M) || defined(MT6219) || (defined(MT6217))|| (defined(MT6225))|| (defined(MT6228))|| (defined(MT6229))|| defined(MT6230)|| (defined(MT6226))|| (defined(MT6227)))		
   UEM_RECEIVE_PWR_IND=GPT_return_current_count()+PERIOD_RST_TO_DRVINT;
   GPT_Stop(3);
   #endif   
   bmt_check_poweron(BMT.PWRon);      
   
	power_on_ind = (drvuem_power_on_ind_struct *) construct_local_para(sizeof(drvuem_power_on_ind_struct),TD_UL);		    
	power_on_ind->power_on = BMT.PWRon;
	if(BMT.PWRon == PWRKEYPWRON)
	{
	   if (UEM_RECEIVE_PWR_IND>Customer_Period_Period())
	      power_on_ind->poweron_time_left=0;
	   else
	      power_on_ind->poweron_time_left=Customer_Period_Period()-UEM_RECEIVE_PWR_IND;
	
	}
	else
	{
		power_on_ind->poweron_time_left = 0;
	}
	
   DRV_BuildPrimitive(BMT_ilm,
                      MOD_BMT,
                      MOD_UEM,
                      MSG_ID_DRVUEM_POWER_ON_IND,
                      power_on_ind);
   msg_send_ext_queue(BMT_ilm);
#ifdef BMT_ACTIVE_TO_READ_NVRAM_DATA
   /*send to read the ADC calibration data req.*/
   nvram_read_req = (nvram_read_req_struct*)construct_local_para(
                                             sizeof(nvram_read_req_struct), 
                                             TD_CTRL);
   nvram_read_req->file_idx = NVRAM_EF_ADC_LID;
   nvram_read_req->para = 1;
   nvram_read_req->access_id = 0;
   
   DRV_BuildPrimitive(BMT_ilm,
                      MOD_BMT,
                      MOD_NVRAM,
                      MSG_ID_NVRAM_READ_REQ,
                      nvram_read_req);
   msg_send_ext_queue(BMT_ilm);
#endif   /*BMT_ACTIVE_TO_READ_NVRAM_DATA*/
#endif   /*(!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL))*/
   
#ifdef BMT_DEBUG
   //WDT_Enable(KAL_TRUE);    /*aa,OS code should be modified,too*/
#endif   /*BMT_DEBUG*/

#if ( (defined(MT6318))|| (defined(MT6305)) )
   /*ADC scheduler initial*/
   adc_sche_init();
#endif   /*PMIC_PRESENT*/

#if ( (defined(MT6318))|| (defined(MT6305)) )
   /*Charging algorithm initial*/
   bmt_adc_init();
   
   #if defined(MT6318)/*XXXXX*/
   /*PMIC initilaizeation*/
   //pmic_customization_init();
   #if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
   /* Create adc object first here. */
	chr_usb_detect.chr_usb_adc_logical_id = adc_sche_create_object(MOD_BMT, chr_usb_detect.chr_usb_adc,10,3, KAL_TRUE);
   #endif
   /*PMIC uses charger's interrupt*/
   #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
   PMIC_ChrDet_Registration(AC_CHR, CHRDET_HISR);
   #else
   PMIC_ChrDet_Registration(AC_CHR, CHR_USB_EINT_HISR);   
   #endif
   
   if(pmic_is_chr_det(AC_CHR)) 
      PMIC_CHRDET.pmic_ac_det();	     	       
      
   if(pmic_is_chr_det(USB_CHR)) 
   {
   	  if(PMIC_CHRDET.pmic_usb_det!=NULL) 	
      	 PMIC_CHRDET.pmic_usb_det();	   	   	         
   }   
   
   #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
   EINT_Registration(gCHRDET_EINT_NO,KAL_TRUE,LEVEL_LOW,PMIC_HISR, KAL_TRUE);      
   #else
   EINT_Registration(chr_usb_detect.chr_usb_eint,KAL_TRUE,LEVEL_LOW,PMIC_HISR, KAL_TRUE);      
   #endif
   #else //MT6318
   #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
   EINT_Registration(gCHRDET_EINT_NO,KAL_TRUE,LEVEL_HIGH,CHRDET_HISR, KAL_TRUE);
   //#endif //__CHARGER_USB_DETECT_WIHT_ONE_EINT__
   #else
     // #ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
   EINT_Registration(chr_usb_detect.chr_usb_eint,KAL_TRUE,LEVEL_HIGH,CHR_USB_EINT_HISR, KAL_FALSE);
	chr_usb_detect.chr_usb_adc_logical_id = adc_sche_create_object(MOD_BMT, chr_usb_detect.chr_usb_adc,10,3, KAL_TRUE);
	#endif
   #endif //MT6318
   
   
   
#endif   /*PMIC_PRESENT*/
#ifdef BMT_KAL_DEBUG    
   kal_trace(TRACE_FUNC, BMT_PWRON_TRC,BMT.PWRon);
#endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("BMT.PWRon = %d\r\n",BMT.PWRon);
   #endif   /*BMT_DEBUG*/
   bmt_read_calibration_data();
   stack_init_timer(&ChargeTimeout_timer, "chr timeout timer", MOD_BMT);
   while(1)
   {
      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
      
      switch(current_ilm.msg_id)
      {
//#ifdef PMIC_PRESENT
#if ( (defined(MT6318))|| (defined(MT6305)) )
         case MSG_ID_TIMER_EXPIRY:
            #ifdef BMT_DEBUG
            /*dbg_printWithTime("MSG_ID_TIMER_EXPIRY!!\r\n");*/
            #endif   /*BMT_DEBUG*/
         
            if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)timer_adcsche))
            {
               /* Check if the base timer is stopped or not */
               if (stack_is_time_out_valid(timer_adcsche)) 
               {
                  /* Execute event's timeout handler */
                  evshed_timer_handler(adc_sche_event_scheduler_ptr);
               }
               /* Shoulbe be paired with stack_is_time_out_valid() */
               stack_process_time_out(timer_adcsche);
            }
         
            if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)timer_stopcharge))
            {
               if (stack_is_time_out_valid(timer_stopcharge)) 
               {
                  #ifdef BMT_KAL_DEBUG 
	                  kal_trace(TRACE_FUNC, BMT_STOP_TIMER_EXPIRE_TRC);	
	               #endif   
	               BMT_CHARSTOP();
               }
               stack_process_time_out(timer_stopcharge);            	

            }
            if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)&ChargeTimeout_timer))
            {
               if (stack_is_time_out_valid(&ChargeTimeout_timer)) 
               {
                  #ifdef BMT_KAL_DEBUG 
	                  kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_EXPIRE_TRC);
	               #endif   
	               BMT_sendMes2UEM(BMT_CHARGE_TIMEOUT);
	               bmt_charge_end();
               }
               stack_process_time_out(&ChargeTimeout_timer);                 	
                              
            }         
         break;
         
         case MSG_ID_BMT_CHARGER_IND:
         	//dbg_print("receive MSG_ID_BMT_CHARGER_IND\r\n");
            if (bmt_read_chr_status() == bmt_chr_in)
            {
            	//dbg_print("bmt_chr_in \r\n");
               if ( (previous_chr_status == 0xff) || (previous_chr_status != bmt_chr_in) )
               {
               	previous_chr_status = bmt_chr_in;
	            	
	            	#if defined(__USB_ENABLE__)
	            	   /*06102004 TY*/	            		
	            		#if defined(MT6318)
	            		#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	            		if(pmic_is_chr_det(AC_CHR))/*AC exists*/
	            		#else
	            	   if(IsUSBorCharger() != BMT_USB_IN)		            	
	            		#endif
	            		{
	            	      if(pmic_is_chr_valid())/*check if it's a valid charger*/
	            	      {	            	       
	            	      	//pmic_charging_currnet_ctrl(CHR_CURRENT_650);	         	       
	                        BMT_sendMes2UEM(BMT_CHARGER_IN);
	                        bmt_charge_start();
	            		      kal_prompt_trace(MOD_BMT,"AC IN and start charge!");	                  
	            		   }
	            		   else
	            		   {	            		    
	            		      bmt_charge_end();
	            	         BMT_sendMes2UEM(BMT_INVALID_CHARGER);
	            	         kal_prompt_trace(MOD_BMT,"InvalidAC IN and start charging!");	                  
	            		   }   
	            		}   
	            		#else/*!=MT6318*/
	            	// check USB or AC 
	            	if(IsUSBorCharger() == BMT_USB_IN)
            		{
            			//dbg_print("BMT_USB_IN \r\n");            			
            			// a USB cable is plugged in            			
            		   bmt_usb_state = USB_IN_STATE;
   		      		kal_prompt_trace(MOD_BMT,"USB IN");
            		   if(bmt_support_usb_charge())
            		   {   		      			
   		      			bmt_charge_start();  
   		      			BMT_sendMes2UEM(BMT_USB_CHARGER_IN);
   		      			kal_prompt_trace(MOD_BMT,"USB Charge start!"); 		      			
   		      		}
   		      		
            		}
	            	else
	            	{
	            		//dbg_print("AC_IN_STATE and bmt_charge_start \r\n");
	            		bmt_usb_state = AC_IN_STATE;
							// a AC charger is plugged in 	                  
	                  BMT_sendMes2UEM(BMT_CHARGER_IN);
	                  bmt_charge_start();
	            		kal_prompt_trace(MOD_BMT,"AC IN and start charge!");	                  
	            	}
	            	   #endif/*MT6318*/
	            	#else // __USB_ENABLE__
	            	   /*06102004 TY*/
	            	   #if defined(MT6318)
	  	               if(pmic_is_chr_det(AC_CHR))/*AC exists*/
	            		{
	            	      if(pmic_is_chr_valid())/*check if it's a valid charger*/
	            	      {	            	         
	            	         //pmic_charging_currnet_ctrl(CHR_CURRENT_650);	    	            	         
	                        BMT_sendMes2UEM(BMT_CHARGER_IN);
	                        bmt_charge_start();
	            		      kal_prompt_trace(MOD_BMT,"AC IN and start charge!");	                  
	            		   }
	            		   else
	            		   {	            		      
	            		      bmt_charge_end();
	            	         BMT_sendMes2UEM(BMT_INVALID_CHARGER);
	            	         kal_prompt_trace(MOD_BMT,"InvalidAC IN and start charging!");	                  
	            		   }   
	            		}    
	            	   #else/*!=MT6318*/
	                  BMT_sendMes2UEM(BMT_CHARGER_IN);	                  
	                  bmt_charge_start();	           
	                  #endif 	
	            	#endif  // __USB_ENABLE__	            	
               }
            }
            else if(bmt_read_chr_status() == bmt_chr_out)
            {
            	//dbg_print("bmt_chr_out \r\n");
               if ( (previous_chr_status == 0xff) || (previous_chr_status != bmt_chr_out) )
               {
                  previous_chr_status = bmt_chr_out;
               
               	#if defined(__USB_ENABLE__)
               	   #if defined(MT6318)
               	   if(KAL_FALSE==pmic_is_chr_det(AC_CHR))
               	   {
               	      BMT_sendMes2UEM(BMT_CHARGER_OUT);            			
               	      if(bmt_support_usb_charge())/*without host's grant*/
               	      {
               	         if(bmt_usb_state==USB_IN_STATE)
               	         {
               	            /*inform MMI keep showing charging animation*/
               	            BMT_sendMes2UEM(BMT_USB_CHARGER_IN);
               	            kal_prompt_trace(MOD_BMT,"AC OUT but USB_IN exists: keep charging!");            					            				      	         
               	         }   
               	         else
               	         {
               	            bmt_charge_end();
            				      kal_prompt_trace(MOD_BMT,"AC OUT % stop charging");      
               	         }   
               	      }
               	      else if(KAL_FALSE==bmt_support_usb_charge())/*with host's grant*/       
               	      {
               	         if(bmt_usb_state==USB500_STATE)
               	            kal_prompt_trace(MOD_BMT,"AC OUT but USB(500) exists: keep charging!");            					            				      	         
               	         else
               	         {
               	            bmt_charge_end();
            				      kal_prompt_trace(MOD_BMT,"AC OUT % stop charging");      
               	         }      
               	      }   
               	      
               	   }                  	   
               	   #else/*!=MT6318*/
               	// current sate != previous state
               	switch(bmt_usb_state)
            		{
            			case AC_IN_STATE:        
            				//dbg_print("AC_CHARGER_OUT \r\n");
            				bmt_usb_state = AC_OUT_STATE;
            				BMT_sendMes2UEM(BMT_CHARGER_OUT);
            				bmt_charge_end();
            				kal_prompt_trace(MOD_BMT,"AC OUT & charge stop!");
            				break;
            			case USB500_STATE:
            				//dbg_print("USB_OUT_STATE \r\n"); 	
            				if(KAL_FALSE==bmt_support_usb_charge())
            				{			
	            				bmt_usb_state = USB_OUT_STATE;
	            				BMT_sendMes2UEM(BMT_USB_CHARGER_OUT);
	            				bmt_charge_end();
	            				kal_prompt_trace(MOD_BMT,"USB500 Out & Charge Stop!");            				
	            			}
	            			else
	            				ASSERT(0);
            				break;            				
            			case USB100_STATE:
            				//dbg_print("USB_OUT_STATE \r\n"); 	
            				if(KAL_FALSE==bmt_support_usb_charge())
            				{			
	            				bmt_usb_state = USB_OUT_STATE;
	            				BMT_sendMes2UEM(BMT_USB_NO_CHARGING_OUT);
	            				kal_prompt_trace(MOD_BMT,"USB100 Out!");            				
	            			}
	            			else
	            				ASSERT(0);
            				break;            				
            			case USB_IN_STATE:
            				if(bmt_support_usb_charge())
            				{
               				bmt_usb_state = USB_OUT_STATE;
               				BMT_sendMes2UEM(BMT_USB_CHARGER_OUT);
               				bmt_charge_end();
               				kal_prompt_trace(MOD_BMT,"USB100 Out & Charge Stop!");	 
               			}
               			//dbg_print("USB_OUT_STATE \r\n");
            				kal_prompt_trace(MOD_BMT,"USB OUT !");	            				
            				break;            				
            			default:
            				break;
              		} 
               	   #endif
               	#else // __USB_ENABLE__
            				BMT_sendMes2UEM(BMT_CHARGER_OUT);
            				bmt_charge_end();
                	#endif //__USB_ENABLE__               	
               }
            }
            else
               ASSERT(0);
            break;
         #if defined (__USB_ENABLE__)
         #if defined(MT6318)
         case MSG_ID_USB_B_PLUGOUT_IND:            
            if(KAL_FALSE==bmt_support_usb_charge())/*with host's grant*/
            {
               if(bmt_usb_state==USB500_STATE)
               {
                  if(KAL_FALSE==pmic_is_chr_det(USB_CHR))/*check if USB exists*/
                  {                     
	            		BMT_sendMes2UEM(BMT_USB_CHARGER_OUT);	            					            	   			         		
	            		if(KAL_FALSE==pmic_is_chr_det(AC_CHR))/*check if AC exists*/
	            		{
	            		   bmt_charge_end();
	            		   kal_prompt_trace(MOD_BMT,"USB OUT & charge stop!");            					            				      	         
	            		}
	            		else
	            		   kal_prompt_trace(MOD_BMT,"USB OUT but AC exists: keep charging!");            					            				      	         
	            	}	
               }               	   
               else if(bmt_usb_state==USB100_STATE)
               {
                  if(KAL_FALSE==pmic_is_chr_det(USB_CHR))/*check if USB exists*/
                  {                     
	            		BMT_sendMes2UEM(BMT_USB_NO_CHARGING_OUT);
	            		kal_prompt_trace(MOD_BMT,"USB100 OUT!");
	            	}	
               }               	   
            }
            else/*without host's grant*/
            {
               if(bmt_usb_state==USB_IN_STATE)
               {
                  if(KAL_FALSE==pmic_is_chr_det(USB_CHR))/*check if USB exists*/
                  {            
	            		BMT_sendMes2UEM(BMT_USB_CHARGER_OUT);	            					            	   			         		
	            		if(KAL_FALSE==pmic_is_chr_det(AC_CHR))/*check if AC exists*/
	            		{
	            		   bmt_charge_end();
	            		   kal_prompt_trace(MOD_BMT,"USB OUT & charge stop!");            					            				      	         
	            		}
	            		else
	            		   kal_prompt_trace(MOD_BMT,"USB OUT but AC exists: keep charging!");            					            				      	         
	            	}	
               }
            }      
            bmt_usb_state = USB_OUT_STATE;
            break;
         #endif    
         #if defined(MT6318)
         case MSG_ID_USB_B_PLUGIN_IND:             
		      bmt_usb_state = USB_IN_STATE;
		      if(bmt_support_usb_charge())/*without host's grant*/
		         BMT_sendMes2UEM(BMT_USB_CHARGER_IN);
		      
		      
		      #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)		      
		      if(pmic_is_chr_det(AC_CHR))/*check if AC exists*/
		      #else		      
		      if(IsUSBorCharger() != BMT_USB_IN)		            	
		      #endif
		      {
		         kal_prompt_trace(MOD_BMT,"BMT_USB_IN but AC exists");		      			   
		         /*change state but not charge*/
		      }
		      else		      
		      {
		         if(bmt_support_usb_charge())/*without host's grant*/
		         {
		            kal_prompt_trace(MOD_BMT,"BMT_USB_IN & charge start");		      			   
		            bmt_charge_start();
		         }
		         else /*with host's grant*/
		           kal_prompt_trace(MOD_BMT,"BMT_USB_IN & wait USB_500");		      			            
		       }    		      
            break;            
         #endif // MT6318      
         case MSG_ID_BMT_USB_IND:
         	//dbg_print("receive MSG_ID_BMT_USB_IND \r\n");
         	if(KAL_FALSE==bmt_support_usb_charge())
	         {
         	   //EXT_ASSERT((bmt_usb_state == USB_IN_STATE),bmt_usb_state,0,0);
         	   bmt_usb_ind_struct *ind = (bmt_usb_ind_struct*)current_ilm.local_para_ptr;
               #ifdef __USB_MULTI_CHARGE_CURRENT__
               /* This message may send again, so we have to deal with this case. */
	            if((bmt_usb_state == USB_IN_STATE) || (bmt_usb_state == USB500_STATE) || (bmt_usb_state == USB100_STATE))
               #else /* __USB_MULTI_CHARGE_CURRENT__ */
   	         if(bmt_usb_state == USB_IN_STATE)
               #endif /* __USB_MULTI_CHARGE_CURRENT__ */
               {
                  #ifdef __USB_MULTI_CHARGE_CURRENT__
                  /* If chargin current is allowed. */
		            if((ind->usb_ind + 1) < USB_GetChargeCurrentTableSize())
                  #else /* __USB_MULTI_CHARGE_CURRENT__ */
		            if(ind->usb_ind == BMT_USB_500)
                  #endif /* __USB_MULTI_CHARGE_CURRENT__ */
		      		{
		      		   /*06102004 TY*/
		      		   #if defined(MT6318)
		      			   #ifdef __USB_MULTI_CHARGE_CURRENT__
                        /* If state is from USB_IN_STATE or USB100_STATE to USB500_STATE. */
                        if (bmt_usb_state != USB500_STATE)
                        {
		      			   #endif /* __USB_MULTI_CHARGE_CURRENT__ */
		      		         bmt_usb_state = USB500_STATE;
		      			      BMT_sendMes2UEM(BMT_USB_CHARGER_IN);
		      		         if(pmic_is_chr_det(AC_CHR))/*check if AC exists*/
		      		         {
		      		            kal_prompt_trace(MOD_BMT,"BMT_USB_500 but AC exists");		      			   
		      		            /*change state but not charge*/
		      			      }
		      			      else
		      			      {
		      			         kal_prompt_trace(MOD_BMT,"BMT_USB_500 & charge start");		      			   
		      			         bmt_charge_start();
		      			      }      
		      			   #ifdef __USB_MULTI_CHARGE_CURRENT__
                        }
                        /* Set the allowed current index for USB. */
                        usb_set_chr_current(ind->usb_ind);
		      			   #endif /* __USB_MULTI_CHARGE_CURRENT__ */
		      		   #else /* defined(MT6318) */        	   
		      			   //dbg_print("receive MSG_ID_BMT_USB_IND with BMT_USB_500  \r\n");
		      			   #ifdef __USB_MULTI_CHARGE_CURRENT__
                        /* If state is from USB_IN_STATE or USB100_STATE to USB500_STATE. */
                        if (bmt_usb_state != USB500_STATE)
                        {
		      			   #endif /* __USB_MULTI_CHARGE_CURRENT__ */
		      			      kal_prompt_trace(MOD_BMT,"BMT_USB_500 & charge start");
		      			      bmt_usb_state = USB500_STATE;
		      			      // modify for test
		      			      BMT_sendMes2UEM(BMT_USB_CHARGER_IN);
		      			      bmt_charge_start();
		      			   #ifdef __USB_MULTI_CHARGE_CURRENT__
                        }
                        /* Set the allowed current index for USB. */
                        usb_set_chr_current(ind->usb_ind);
		      			   #endif /* __USB_MULTI_CHARGE_CURRENT__ */
		      			#endif /* defined(MT6318) */
		      		}
		         	else
		      		{
		      			//dbg_print("receive MSG_ID_BMT_USB_IND with BMT_USB_100  \r\n");
		      			#ifdef __USB_MULTI_CHARGE_CURRENT__
                     /* If state is from USB_IN_STATE or USB500_STATE to USB100_STATE. */
                     if (bmt_usb_state != USB100_STATE)
                     {
   		      		   #if defined(MT6318)
                        /* If state is from USB500_STATE and there's no AC, charging should stop. */
                        if((KAL_FALSE==pmic_is_chr_det(AC_CHR)) && (bmt_usb_state == USB500_STATE))
                        #else
                        /* If state is from USB500_STATE(usb charging), charging should stop. */
                        if(bmt_usb_state == USB500_STATE)
                        #endif
                        {
             	            bmt_charge_end();
           				      kal_prompt_trace(MOD_BMT,"USB charging current not supported % stop charging");      
                        }
		      			#endif /* __USB_MULTI_CHARGE_CURRENT__ */
		      			kal_prompt_trace(MOD_BMT,"BMT_USB_100");
		      			bmt_usb_state = USB100_STATE;      			
		      			BMT_sendMes2UEM(BMT_USB_NO_CHARGING_IN);
		      			#ifdef __USB_MULTI_CHARGE_CURRENT__
                     }
		      			#endif /* __USB_MULTI_CHARGE_CURRENT__ */
		         	}
	         	}
	         }
				break;                     
         #endif // __USB_ENABLE__ 
         /***********ADC scheduler***********/
         case MSG_ID_BMT_ADC_ADD_ITEM_REQ:
            bmt_adc_sche_add_item(current_ilm.local_para_ptr);
            break;
         
         case MSG_ID_BMT_ADC_REMOVE_ITEM_REQ:
            bmt_adc_sche_remove_item(current_ilm.local_para_ptr);
            break;
            
         case MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ:
            bmt_adc_sche_modify_parameters(current_ilm.local_para_ptr);
            break;
#endif /*PMIC_PRESENT*/

#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) )
         case MSG_ID_NVRAM_READ_CNF:
               bmt_adc_set_adc_calibration_data(&current_ilm);
            break;
#endif   /*(!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL))*/
        
         default:
            break;
      }
      free_ilm(&current_ilm);
   }
}


