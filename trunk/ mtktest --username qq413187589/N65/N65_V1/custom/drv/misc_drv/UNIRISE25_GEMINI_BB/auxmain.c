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
 *    auxmain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the AUX task
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef __L1_STANDALONE__
#include 	"kal_release.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"syscomp_config.h"
#include 	"task_config.h"
#include 	"stacklib.h"
#include    "stack_timer.h"      /*stack_timer_struct....definitions*/
#include 	"drv_comm.h"
#include    "reg_base.h"
#include    "adc.h"
#include    "drvsignals.h"
#include    "eint.h"
#include    "batvalue.h"
#include     "afe.h"
#include     "intrctrl.h"
#include     "uart_sw.h"
#include     "bmt.h"
kal_bool                aux_state = LEVEL_LOW;
extern const kal_uint8 AUX_EINT_NO;
#if (defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))
void CLAM_EINT_HISR(void);
extern const kal_uint8 CLAMDET_EINT_NO;
#endif

kal_bool                clam_state = LEVEL_LOW;

void AUX_EINT_HISR(void);
/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool 	aux_create(comptask_handler_struct **handle);
static void aux_task_main(task_entry_struct *task_entry_ptr);
static kal_bool	aux_task_reset(task_indx_type task_indx);
static kal_bool 	aux_task_end(task_indx_type task_indx);
stack_timer_struct  aux_timer;
static kal_bool aux_timer_open=0;
static kal_bool poll_timer=KAL_FALSE;
static kal_bool aux_detect_mode=KAL_FALSE;
extern void EINT_Mask(kal_uint8 eintno);
extern void EINT_UnMask(kal_uint8 eintno);
extern kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);
extern kal_uint8 adc_sche_create_object(module_type ownerid, kal_uint8 adc_channel,kal_uint32 period, kal_uint8 evaluate_count, kal_bool send_primitive);
/*UART Detection*/
extern void   L1SM_SleepEnable( kal_uint8 handle );
extern void   L1SM_SleepDisable( kal_uint8 handle );
extern kal_uint8 L1SM_GetHandle(void);
kal_uint8  aux_PDNhandle;
kal_uint16 check_uart1=KAL_FALSE;
kal_uint16 check_uart2=KAL_FALSE;
kal_uint16 check_uart3=KAL_FALSE;

#define UART_ADC                    9999999
#define NORMAL_EARPHONE_ADC_HIGH    2800000
#define NORMAL_EARPHONE_ADC_LOW      500000/*0.5~2.8*/ 
#define SINGLE_EARPHONE_ADC_HIGH    2800000
#define SINGLE_EARPHONE_ADC_LOW      500000/*0.5~2.8*/
#define SENDKEY_ADC                  300000
#define POLLING_INTERVAL         50 /*polling interval*/
#define TURN_ON_BIAS_INTERVAL    10 /*measure adc interval*/    
#define PLUGIN_DEBOUNCE_TIME     100 /*unit=10ms*/
#define PLUGOUT_DEBOUNCE_TIME    100
#define VOLTAGE_MEASURE_TIME     450      
#ifdef __CUST_NEW__
   extern const char gpio_afe_amplifier_pin;
   #define GPIO_AUDIO_OP_EN_PIN   gpio_afe_amplifier_pin
#else
   #define GPIO_AUDIO_OP_EN_PIN   5
#endif
#undef  AUX_DEBUG


/*************************************************************************
* FUNCTION
*	aux_create
*
* DESCRIPTION
*	This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
aux_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct aux_handler_info = 
	{
		aux_task_main,			/* task entry function */
		NULL,		  	/* task initialization function */
		NULL, 	/* task configuration function */
		aux_task_reset,		/* task reset handler */
		aux_task_end			/* task termination handler */
	};

	*handle = (comptask_handler_struct *)&aux_handler_info;
	return KAL_TRUE;
}

#ifdef  __MTK_TARGET__
// Huyanwei Add It 
extern void AFE_TurnOnExtAmplifier(void);
extern void AFE_TurnOffExtAmplifier(void);
#endif


//Huyanwei mark earphone
int aux_plug_in_state = 0 ;

void AUX_EINT_HISR(void)
{
   ilm_struct *aux_ilm;
   
      if (aux_state == LEVEL_HIGH)
      {
         #ifdef AUX_DEBUG
         dbg_print(" Interrupt: Plugout \n\r");
         #endif 

 	#if 0
	//Huyanwei Add It 
	AFE_TurnOnExtAmplifier();
	#endif
	  aux_plug_in_state = 0;
	
         aux_timer_open=0;	
         AFE_TurnOffMicBias();
         stack_stop_timer(&aux_timer);
         //GPIO_WriteIO(1,GPIO_AUDIO_OP_EN_PIN);
         DRV_BuildPrimitive(aux_ilm,
                           MOD_EINT_HISR,
                           MOD_AUX,
                           MSG_ID_AUX_PLUGOUT,
                           NULL);
        EINT_SW_Debounce_Modify(AUX_EINT_NO,PLUGIN_DEBOUNCE_TIME);                              
        aux_state = !aux_state;
        EINT_Set_Polarity(AUX_EINT_NO,aux_state); 		
      }
      else
      {
         #ifdef AUX_DEBUG
         dbg_print(" Interrupt: Plugin \n\r");
         #endif 
#ifdef __MTK_TARGET__		 
	  /* 2009.xx.xx added by huyanwei + */
	  AFE_TurnOffExtAmplifier();
	  /* 2009.xx.xx added by huyanwei - */
#endif 
	  aux_plug_in_state = 1 ;
	  
         aux_timer_open=1;		                           
         aux_detect_mode=AFE_TurnOnMicBias();            
         //GPIO_WriteIO(0,GPIO_AUDIO_OP_EN_PIN);
         stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL);            
         DRV_BuildPrimitive(aux_ilm,
                           MOD_EINT_HISR,
                           MOD_AUX,
                           MSG_ID_AUX_PLUGIN,
                           NULL);      
         EINT_SW_Debounce_Modify(AUX_EINT_NO,PLUGOUT_DEBOUNCE_TIME);
         aux_state = !aux_state;
         EINT_Set_Polarity(AUX_EINT_NO,aux_state);
      }
      msg_send_ext_queue(aux_ilm);
}



void aux_read_adc_channel(kal_uint8 logic_id)
{
   ilm_struct        *aux_ilm;
   bmt_adc_add_item_req_struct *aux_adc_item;
   aux_adc_item = (bmt_adc_add_item_req_struct*)
				   construct_local_para(sizeof(bmt_adc_add_item_req_struct), TD_CTRL);
				   
   aux_adc_item->adc_sche_id = logic_id;
   
   DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_BMT,
                      MSG_ID_BMT_ADC_ADD_ITEM_REQ,
                      aux_adc_item);
                      
   msg_send_ext_queue(aux_ilm);
}

void aux_remove_adc_channel(kal_uint8 logic_id)
{
   ilm_struct        *aux_ilm;
   bmt_adc_remove_item_req_struct *aux_adc_remove_item;
   aux_adc_remove_item = (bmt_adc_remove_item_req_struct*)
	   construct_local_para(sizeof(bmt_adc_remove_item_req_struct), TD_CTRL);
   
   aux_adc_remove_item->adc_sche_id = logic_id;
   DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_BMT,
                      MSG_ID_BMT_ADC_REMOVE_ITEM_REQ,
                      aux_adc_remove_item);

   msg_send_ext_queue(aux_ilm);
}
/*************************************************************************
* FUNCTION
*	aux_read_result
*
* DESCRIPTION
*	This function is to read adc result and send msg to UEM and TST_READER accoding 
*  different adc value
*
* PARAMETERS
*  pre_id   : 
*  logic_id : adc logic channel 
*  buf      : local parameter of ilm 
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void aux_read_result(AUX_ID *pre_id,kal_uint8 aux_adc_logic_id,local_para_struct *buf)
{
   bmt_adc_measure_done_conf_struct *ptr=(bmt_adc_measure_done_conf_struct *)buf;
   kal_int32                       aux_volt_result;
   aux_id_struct                   *aux_id_data;
   ilm_struct                      *aux_ilm;
   AUX_ID                    aux_id_no=AUX_ID_PLUGOUT;
   
  
   if(0==aux_timer_open)
      return;
   aux_volt_result = (kal_int32)ptr->volt;
     
   if ((aux_volt_result > UART_ADC)&&(*pre_id!=AUX_ID_EARPHONE)&&(*pre_id!=AUX_ID_KEY_PRESS)&&(*pre_id!=AUX_ID_KEY_PRESS))
   {         
      #ifdef AUX_DEBUG         
      dbg_print("UART \n\r");
      dbg_print("AUX voltage = %d\n\r",aux_volt_result);
      #endif 
      aux_id_no = AUX_ID_UART;
      #ifndef __CUST_NEW__
      //GPIO_WriteIO(1,3);/*Turn on UART*/     
      #endif /* __CUST_NEW__ */
   }  
   if(aux_id_no!=AUX_ID_UART) 
   {
      if(aux_detect_mode==KAL_FALSE)/*normal mode */
      {
         #ifdef AUX_DEBUG
          dbg_print("Normal mode 2.2V \n\r");           
         #endif 
         if(((NORMAL_EARPHONE_ADC_LOW <aux_volt_result)&& (aux_volt_result< NORMAL_EARPHONE_ADC_HIGH) )||(aux_volt_result< SENDKEY_ADC)) 
         {  
            #ifdef AUX_DEBUG
            dbg_print("Earphone  \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            //L1SM_SleepEnable(aux_PDNhandle);
            if(*pre_id==AUX_ID_EARPHONE||*pre_id==AUX_ID_KEY_PRESS||*pre_id==AUX_ID_KEY_RELEASE)     
            {
            	if(aux_volt_result< SENDKEY_ADC)
            	{ 
            	   aux_id_no = AUX_ID_KEY_PRESS;  
            	}
            	else
            	{
            	   aux_id_no = AUX_ID_KEY_RELEASE;
            	}
            }
            else
            	 aux_id_no =AUX_ID_EARPHONE;	
         }
         else
         {
            #ifdef AUX_DEBUG
            dbg_print("Abnormal mode \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            aux_id_no= AUX_ID_PLUGOUT;
         }
      }
      else if(aux_detect_mode==KAL_TRUE) /*Single mode*/
      {
         #ifdef AUX_DEBUG
         dbg_print("Single mode 1.9V \n\r");   
         #endif
         if(((SINGLE_EARPHONE_ADC_LOW <aux_volt_result)&& (aux_volt_result< SINGLE_EARPHONE_ADC_HIGH) )||(aux_volt_result< SENDKEY_ADC)) 
         {           
            #ifdef AUX_DEBUG
            dbg_print("Earphone  \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            if(*pre_id==AUX_ID_EARPHONE||*pre_id==AUX_ID_KEY_PRESS||*pre_id==AUX_ID_KEY_RELEASE)     
            {
            	if(aux_volt_result< SENDKEY_ADC)
            	{ 
            	   aux_id_no = AUX_ID_KEY_PRESS;  
            	}
            	else
            	{
            	   aux_id_no = AUX_ID_KEY_RELEASE;
            	}
            }
            else
            	 aux_id_no =AUX_ID_EARPHONE;	
         }
         else
         {
            #ifdef AUX_DEBUG
            dbg_print("Abnormal mode \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            aux_id_no= AUX_ID_PLUGOUT;
         }
      }                   
   }
   if ((*pre_id != aux_id_no) )
   {      
      if((aux_id_no!=AUX_ID_KEY_RELEASE)&&(aux_id_no!=AUX_ID_PLUGOUT))
      {
         #ifdef AUX_DEBUG
         dbg_print("Send EARPHONE msg to MMI \n\r");
         dbg_print("AUX ID  = %d\n\r",aux_id_no);
         #endif
         aux_id_data = (aux_id_struct*)
		      construct_local_para(sizeof(aux_id_struct), TD_CTRL);	   
         aux_id_data->aux_id = aux_id_no;
                  
            DRV_BuildPrimitive(aux_ilm,
                            MOD_AUX,
                            MOD_UEM,
                            MSG_ID_AUX_ID,
                            aux_id_data);
         
         msg_send_ext_queue(aux_ilm);         
       }
       if(aux_id_no!=AUX_ID_PLUGOUT) 
          *pre_id = aux_id_no;      
   }
   
   /*error state or poll timer on */
   if(aux_id_no==AUX_ID_PLUGOUT)
      stack_start_timer(&aux_timer, 1, POLLING_INTERVAL);/*start polling timer*/ 
   else if(poll_timer==KAL_TRUE)
      stack_start_timer(&aux_timer, 1, POLLING_INTERVAL);/*start polling timer*/           
   
}

#if (defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))
void CLAM_EINT_HISR(void)
{
   ilm_struct           *clam_ilm;
   aux_id_struct        *aux_id_data;
   
      if (clam_state == LEVEL_LOW)
      {
         aux_id_data = (aux_id_struct*)
				   construct_local_para(sizeof(aux_id_struct), TD_CTRL);

         aux_id_data->aux_id = AUX_ID_CLAM_CLOSE;     

         DRV_BuildPrimitive(clam_ilm,
                            MOD_EINT_HISR,
                            MOD_UEM,
                            MSG_ID_AUX_ID,
                            aux_id_data);
      }
      else
      {
         aux_id_data = (aux_id_struct*)
				   construct_local_para(sizeof(aux_id_struct), TD_CTRL);

         aux_id_data->aux_id = AUX_ID_CLAM_OPEN;

         DRV_BuildPrimitive(clam_ilm,
                            MOD_EINT_HISR,
                            MOD_UEM,
                            MSG_ID_AUX_ID,       
                            aux_id_data);
      }
      msg_send_ext_queue(clam_ilm);
      
      clam_state = !clam_state;
   EINT_Set_Polarity(CLAMDET_EINT_NO,clam_state);
}
#endif


#if (defined(G_SENSOR_SUPPORT) || defined(DOUBLE_BATTERY_SUPPORT))
	//Huyanwei Add It For Message Macro 
	#define MYQUEUE         ilm_struct
	#define oslMsgqid       kal_msgqid
	#define oslModuleType   module_type
	#define oslMsgType      msg_type
	#define oslParaType     local_para_struct
	#define oslSrcId        src_mod_id
	#define oslDestId       dest_mod_id
	#define oslMsgId        msg_id
	#define oslSapId        sap_id
	#define oslDataPtr      local_para_ptr
	#define oslPeerBuffPtr  peer_buff_ptr
	#define OSLWAITMODE     kal_wait_mode
	#define OSL_NO_WAIT     KAL_NO_WAIT
	#define OSL_INFINITE_WAIT   KAL_INFINITE_WAIT

	#define OslMsgSendExtQueue(Message) \
	            OslIntMsgSendExtQueue(Message)
#endif



#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 

const unsigned char G_SENSOR_EINT_NO = 6 ; // EINT6
kal_bool   g_sensor_init_state = LEVEL_HIGH;
#define    G_SENSOR_DEBOUNCE_TIME 10

extern void ClearInterrupt_GSensor(void);
//extern void mma745x_IICWrite(VUINT8 RegAdd, VUINT8 Data) ;
extern void LCD_Delayms(kal_uint8 time);

void G_SENSOR_EINT_HISR(void)
{
#if 0
	//Huyanwei Modify it 

	static int mutex = 0 ;
	MYQUEUE Message;	

	if(mutex == 0)
	{
		mutex = 1 ;
		if (g_sensor_init_state == LEVEL_LOW)
		{	
			EINT_SW_Debounce_Modify(G_SENSOR_EINT_NO,G_SENSOR_DEBOUNCE_TIME);
			g_sensor_init_state = !g_sensor_init_state;
			EINT_Set_Polarity(G_SENSOR_EINT_NO,g_sensor_init_state);
			#if 1
			Message.oslSrcId = MOD_MMI;
			Message.oslDestId =MOD_MMI;
			Message.oslMsgId = MSG_ID_GSENSOR_UP;
			Message.oslDataPtr = NULL;
			Message.oslPeerBuffPtr = NULL;
			OslMsgSendExtQueue(&Message);
			#endif
		}
		else
		{		
			EINT_SW_Debounce_Modify(G_SENSOR_EINT_NO,G_SENSOR_DEBOUNCE_TIME);
			g_sensor_init_state = !g_sensor_init_state;
			EINT_Set_Polarity(G_SENSOR_EINT_NO,g_sensor_init_state);
			#if 1
			Message.oslSrcId = MOD_MMI;
			Message.oslDestId =MOD_MMI;
			Message.oslMsgId = MSG_ID_GSENSOR_DOWN;
			Message.oslDataPtr = NULL;
			Message.oslPeerBuffPtr = NULL;
			OslMsgSendExtQueue(&Message);
			#endif
		}
		mutex = 0 ;
	}

	ClearInterrupt_GSensor();
	//LCD_Delayms(10);
	//mma745x_IICWrite(0x1A,0x0A);	
	
#endif
}


#endif


#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It For Interrupt 

const unsigned char EINT4_BATT_DET = 5; 

extern const kal_uint8 ADC6_M_BATT ;
extern const kal_uint8 ADC4_S_BATT ;

//extern const unsigned char EINT4_BATT_DET;
kal_bool  g_ex_batt_init_state = LEVEL_HIGH;

void EX_BATT_EINT4_HISR(void);

kal_uint8  g_ex_batt_state =0 ;

#define BATT_DEBOUNCE_TIME 10

#define EX_BATT_INSET 1
#define EX_BATT_OUT    2

kal_uint8 ExistSubBattery()
{
#if 1
	extern kal_uint16 g_adc_value_low ;
	extern kal_uint16 g_adc_value_high;
	kal_uint16 adc4_vol = 0,vol_temp = 0  ;
	if(g_ex_batt_state == EX_BATT_INSET  )
	{
		return 1;
	}
	else if(g_ex_batt_state == EX_BATT_OUT  )
	{
		return 0 ;
	}
	else		
	{
			#ifndef WIN32
			//Huyanwei Add It 
			adc4_vol = ADC_GetData(ADC4_S_BATT);
			#endif
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
				
				if (vol_temp < 32)
				{
					return 0 ;
				}
				else 
				{
					return 1 ;
				}
			}
			return 0; 
	}
#endif	
}

void EX_BATT_EINT4_HISR(void)
{
#if 1
	MYQUEUE Message;	

	if (g_ex_batt_init_state == LEVEL_LOW)
	{
		g_ex_batt_state = EX_BATT_INSET;
		
		EINT_SW_Debounce_Modify(EINT4_BATT_DET,BATT_DEBOUNCE_TIME);
		g_ex_batt_init_state = !g_ex_batt_init_state;
		EINT_Set_Polarity(EINT4_BATT_DET,g_ex_batt_init_state);
#if 1
		Message.oslSrcId = MOD_MMI;
		Message.oslDestId =MOD_MMI;
		Message.oslMsgId = MSG_ID_BATTERYII_PLUG_IN ;
		Message.oslDataPtr = NULL;
		Message.oslPeerBuffPtr = NULL;
		OslMsgSendExtQueue(&Message);
#endif
	}
	else
	{
		g_ex_batt_state = EX_BATT_OUT;				
		EINT_SW_Debounce_Modify(EINT4_BATT_DET,BATT_DEBOUNCE_TIME);
		g_ex_batt_init_state = !g_ex_batt_init_state;
		EINT_Set_Polarity(EINT4_BATT_DET,g_ex_batt_init_state);
#if 1
		Message.oslSrcId = MOD_MMI;
		Message.oslDestId =MOD_MMI;
		Message.oslMsgId = MSG_ID_BATTERYII_PLUG_OUT ;
		Message.oslDataPtr = NULL;
		Message.oslPeerBuffPtr = NULL;
		OslMsgSendExtQueue(&Message);
#endif
	}
#endif

}

#endif

/* 2009.04.14 added by hongzhe.liu for motion sensor + */
#if defined(__DIRECTION_SENSOR_SUPPORT__)
	extern void EINT_Motion_Sensor_Registration();
#endif
/* 2009.04.14 added by hongzhe.liu for motion sensor - */


/*************************************************************************
* FUNCTION                                                            
*	aux_task_main
*
* DESCRIPTION                                                           
*	This function implements xyz task's entry function
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void aux_task_main( task_entry_struct * task_entry_ptr )
{
   ilm_struct	      current_ilm;
   ilm_struct          *aux_ilm ;
   aux_id_struct        *aux_id_data;
   kal_uint8            aux_adc_logic_id;
   AUX_ID              pre_id = AUX_ID_PLUGOUT;              
   /*Engineering mode logic id*/
   kal_uint8            vbat_adc_logic_id;
   kal_uint8            visense_adc_logic_id;
   kal_uint8            vcharger_adc_logic_id;
   kal_uint8            vbattemp_adc_logic_id;
   kal_uint8            vaux_adc_logic_id;   
   /*Engineering mode result*/
   kal_int32           vbat_value;
   kal_int32           visense_value;
   kal_int32           vcharger_value;
   kal_int32           vbattemp_value;
   kal_int32           vaux_value;
   bmt_adc_measure_done_conf_struct *mea_done_ptr;
   adc_all_channel_struct *adc_all_channel_result;
   kal_uint16            adc_measure_count=0;
   stack_timer_struct               *check_timer_index; 
   
    stack_init_timer(&aux_timer, "AUX_TIMER", MOD_AUX);
   /*40*4.615ms=18ms*/
   aux_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_ACCESSORYID,40,1, KAL_TRUE);
   
   /*Engineering mode*/   
   vbat_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_VBAT,40,1, KAL_TRUE);
   visense_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_VISENSE,40,1, KAL_TRUE);
   vcharger_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_VCHARGER,40,1, KAL_TRUE);
   vbattemp_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_VBATTMP,40,1, KAL_TRUE);
   vaux_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_ACCESSORYID,40,1, KAL_TRUE);



#if defined(G_SENSOR_SUPPORT)
  //Huyanwei Add It For Interrupt
  #if 0
   g_sensor_init_state = LEVEL_HIGH;
#if defined(NOKE_DEBUG)
   noke_dbg_printf("\r\nHuyanwei Debug Regedit G Sensor Interrupt ......\r\n");
#endif
   EINT_Registration(G_SENSOR_EINT_NO,KAL_TRUE,g_sensor_init_state,G_SENSOR_EINT_HISR, KAL_TRUE);
   EINT_SW_Debounce_Modify(G_SENSOR_EINT_NO,G_SENSOR_DEBOUNCE_TIME);
   EINT_Set_Polarity(G_SENSOR_EINT_NO,g_sensor_init_state);
#endif
#endif

#if defined(DOUBLE_BATTERY_SUPPORT)
   #if 1
   //Huyanwei Add It For Interrupt
   g_ex_batt_init_state = LEVEL_HIGH;   
   EINT_Registration(EINT4_BATT_DET,KAL_TRUE,g_ex_batt_init_state,EX_BATT_EINT4_HISR, KAL_TRUE);
   EINT_SW_Debounce_Modify(EINT4_BATT_DET,BATT_DEBOUNCE_TIME);
   EINT_Set_Polarity(EINT4_BATT_DET,g_ex_batt_init_state); 
   #endif
#endif
		  
   /*Enable External interrupt*/
   EINT_Registration(AUX_EINT_NO,KAL_TRUE,aux_state,AUX_EINT_HISR, KAL_TRUE);      
#if (defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))
   EINT_Registration(CLAMDET_EINT_NO,KAL_TRUE,clam_state,CLAM_EINT_HISR, KAL_TRUE);
#endif
   
/* 2009.04.14 added by hongzhe.liu for motion sensor + */
#if defined(__DIRECTION_SENSOR_SUPPORT__)
	EINT_Motion_Sensor_Registration();
#endif
/* 2009.04.14 added by hongzhe.liu for motion sensor - */

   while(1)
   {
      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
      
      switch(current_ilm.msg_id)
      {
         case MSG_ID_AUX_CALL_SETUP_REQ_IND:                        
               poll_timer=KAL_TRUE;  
            if(aux_timer_open==1)
            {   
               aux_detect_mode=AFE_TurnOnMicBias();/*voltage source*/  
               stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL); 
            }    
            break;
         case MSG_ID_AUX_CALL_DISCONNECT_REQ_IND:
            poll_timer=KAL_FALSE;
            AFE_TurnOffMicBias();/*voltage source*/  
            break;         
         case MSG_ID_AUX_PLUGIN:
            break;
         
         case MSG_ID_AUX_PLUGOUT:   
            /*Notify MMI the aux is plugout*/   
                                                   
               pre_id = AUX_ID_PLUGOUT;            
               aux_id_data = (aux_id_struct*)
				      construct_local_para(sizeof(aux_id_struct), TD_CTRL);
               
               aux_id_data->aux_id = AUX_ID_PLUGOUT;
               
               DRV_BuildPrimitive(aux_ilm,
                         MOD_AUX,
                         MOD_UEM,
                         MSG_ID_AUX_ID,
                         aux_id_data);
                      
            msg_send_ext_queue(aux_ilm);
            
            /*remove the adc item*/
            aux_remove_adc_channel(aux_adc_logic_id);
            break;
         
         case MSG_ID_READ_ALL_ADC_CHANNEL_REQ:
            adc_measure_count=0;
            vbat_value = 0;
            aux_read_adc_channel(vbat_adc_logic_id);
            visense_value = 0;
            aux_read_adc_channel(visense_adc_logic_id);
            vcharger_value = 0;
            aux_read_adc_channel(vcharger_adc_logic_id);
            vbattemp_value = 0;
            aux_read_adc_channel(vbattemp_adc_logic_id);
            vaux_value = 0;
            aux_read_adc_channel(vaux_adc_logic_id);
            break;
            
         case MSG_ID_BMT_ADC_MEASURE_DONE_CONF:
            
            mea_done_ptr = (bmt_adc_measure_done_conf_struct *)current_ilm.local_para_ptr;
            if (mea_done_ptr->adc_sche_id == aux_adc_logic_id) /*normal mode*/
            {
               aux_remove_adc_channel(aux_adc_logic_id);
                if(poll_timer!=KAL_TRUE)  /*not turn off microbias when talking*/
                   AFE_TurnOffMicBias();
               aux_read_result(&pre_id,aux_adc_logic_id,current_ilm.local_para_ptr);
            }
            if (mea_done_ptr->adc_sche_id == vbat_adc_logic_id)
            {
               adc_measure_count++;
               vbat_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(vbat_adc_logic_id);
            }
            else if (mea_done_ptr->adc_sche_id == visense_adc_logic_id)
            {
               adc_measure_count++;
               visense_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(visense_adc_logic_id);
            }
            else if (mea_done_ptr->adc_sche_id == vcharger_adc_logic_id)
            {
               adc_measure_count++;
               vcharger_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(vcharger_adc_logic_id);
            }
            else if (mea_done_ptr->adc_sche_id == vbattemp_adc_logic_id)
            {
               adc_measure_count++;
               vbattemp_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(vbattemp_adc_logic_id);
            }
            else if (mea_done_ptr->adc_sche_id == vaux_adc_logic_id)
            {
               adc_measure_count++;
               vaux_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(vaux_adc_logic_id);
            }
            
           if(adc_measure_count==5)
           {
               adc_measure_count=0;
               adc_all_channel_result = (adc_all_channel_struct*)
				      construct_local_para(sizeof(adc_all_channel_struct), TD_CTRL);

               adc_all_channel_result->vbat = vbat_value;
               adc_all_channel_result->bat_temp=volt2temp(vbattemp_value);               
               adc_all_channel_result->vaux = vaux_value;
               adc_all_channel_result->charge_current = (visense_value - vbat_value)*bmt_custom_chr_def.ADC_ISENSE_RESISTANCE_FACTOR;
               adc_all_channel_result->vcharger = vcharger_value;

               DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_UEM,
                      MSG_ID_ADC_ALL_CHANNEL_CONF,
                      adc_all_channel_result);
                      
               msg_send_ext_queue(aux_ilm);
            }
            break;
         case MSG_ID_TIMER_EXPIRY:/*Timer*/
            check_timer_index = (stack_timer_struct *) current_ilm.local_para_ptr;
            switch(check_timer_index->timer_indx)
            {
               case 0:/*20ms timer*/
                  if((aux_timer_open==1))            
                     aux_read_adc_channel(aux_adc_logic_id);
                  else
                     aux_remove_adc_channel(aux_adc_logic_id);
                  break;
               case 1:/*500ms timer*/                                    
                  aux_detect_mode=AFE_TurnOnMicBias();/*voltage source*/      
                  stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL);
                  break;            
               default:
                  break;   
            }     
            break; 
         default:
            break;
      }
      free_ilm(&current_ilm);
   }
}

/*************************************************************************
* FUNCTION                                                            
*	aux_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
aux_task_reset(task_indx_type task_indx)
{
  	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	aux_task_end
*
* DESCRIPTION
*	This function implements xyz's termination handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
aux_task_end(task_indx_type task_indx)
{
  	/* Do task's termination here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_end() will do. */
	return KAL_TRUE;
}
/*UART Detection*/
void UART_Detection_Enable(UART_PORT port, kal_bool enable_flag)
{
   switch(port)
   {
      case uart_port1:
         check_uart1=enable_flag;
         break;
      case uart_port2:
         check_uart2=enable_flag;
         break;
      default:
         break;
   }
}

kal_bool Get_UART_Detection_Status(UART_PORT port)
{
   switch(port)
   {
      case uart_port1:
         return check_uart1;
         break;
      case uart_port2:
         return check_uart2;
         break;
      default:
         return KAL_FALSE;
         break;
   }
}

#endif /*__L1_STANDALONE__*/
