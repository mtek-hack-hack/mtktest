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
 *    bmt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines charging algorithm.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include    "batvalue.h"
#include    "drvsignals.h"
#include    "kal_release.h"
#include		"bmt_trc.h"
#include		"pwic.h"


extern void BMT_Charge(char data);  /*in drv directory*/
extern void bmt_set_stoptimer(kal_uint32 tick);
extern void bmt_stop_stoptimer(void);
extern void bmt_charge_end(void);
extern void BMT_sendMes2UEM(BMT_CHR_STAT status);
extern void bmt_timer_config(kal_uint32 time);
extern void adc_sche_remove_item(kal_uint8 adc_sche_id);
extern kal_int32 VOL_RESULT[MAX_CHANNEL];
extern double ADC_RESULT[MAX_CHANNEL];
extern kal_uint8  bmt_bmtid_adcscheid[BMT_MAX_CHANNEL_TOTAL];
extern stack_timer_struct      ChargeTimeout_timer;

static kal_uint8 BATFULL_index = 0;
static CHRTStruct  BATTime;
BMTStruct BMT;          /*Main BMT struct*/
static kal_uint32 VBATtmp;
kal_uint32 VBAT_OFF = 3900000;
double ADCBAT_OFF = 0;
kal_uint8 low_charger_count = 0;
kal_uint8 low_current_count = 0;
kal_uint8 low_temper_count = 0;
kal_uint8 over_temper_count = 0;
kal_uint8 over_current_count=0;
kal_uint8 BMT_MAX_CHANNEL = BMT_MAX_CHANNEL_TOTAL;

static void BMT_CHRPRE_ON(void);
static void BMT_CHRPRE_OFF(void);
static void BMT_CHRFAST_ON(void);
static void BMT_CHRFAST_OFF(void);
static void BMT_CHRTOPOFF_ON(void);
static void BMT_CHRTOPOFF_OFF(void);
static void BMT_CHRBATFULL_ON(void);
static void BMT_CHRBATFULL_OFF(void);
static void BMT_CHRHOLD(void);
static void BMT_MeasureStop(void);
static void BMT_CtrlCharge(kal_uint8 ON, kal_uint32 VBAT);
kal_uint8 SaftyTimer_Flag = 0;

const CHR_FUNC  BMT_CHRFUNC[6][2] = 
{
   //{BMT_CHRDIS,BMT_CHRDIS},
   {BMT_CHRPRE_OFF, BMT_CHRPRE_ON},
   {BMT_CHRFAST_OFF, BMT_CHRFAST_ON},
   {BMT_CHRTOPOFF_OFF, BMT_CHRTOPOFF_ON},
   {BMT_CHRBATFULL_OFF, BMT_CHRBATFULL_ON},
   {BMT_MeasureStop,BMT_MeasureStop},
   {BMT_CHRHOLD,BMT_CHRHOLD}
};

/*
* FUNCTION
*	   bmt_measure_done
*
* DESCRIPTION                                                           
*   	This function is called when all parameters that charge algorithm needs
*  are all measured done.
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
/*total channel measure done*/
void bmt_measure_done(void)
{
   /*change charge state*/
   BMT_CHRFUNC[BMT.bat_state][BMT.pmictrl_state]();
}  

/*
* FUNCTION
*	   BMT_CallState
*
* DESCRIPTION                                                           
*   	This function is called by MMI to nodify talk/idle state to BMT task.
*
* CALLS  
*
* PARAMETERS
*	   callState: 1, talk mode.
*                0, idel mode.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void BMT_CallState(kal_uint8 callState)
{
   BMT.call_state = callState;   /*Talk time=1, otherwise = 0*/
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_CALL_STATE_TRC, callState);
   #endif   
   #ifdef BMT_DEBUG
   	dbg_printWithTime("BMT_CallState: callState = %d\r\n",callState);
   #endif
}

/*
* FUNCTION
*	   BMT_TONOFF
*
* DESCRIPTION                                                           
*   	This function is to obtain the TON/TOFF paramters in CHR_FAST mode.
*
* CALLS  
*
* PARAMETERS
*	   PHY: measured physical parameters
*     BATTime: the structure of TON/TOFF parameters
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
static void BMT_TONOFF(BATPHYStruct *PHY,CHRTStruct *BATTime)////======
{
   if(BMT.call_state == talk_mode)
   {

  	   if (PHY->ICHARGE > bmt_charing_para->FAST_ICHARGE_HIGHLEVEL)
      {
         BATTime->TON=bmt_charing_para->TONOFFTABLE[3][CHRTON];
         BATTime->TOFF=bmt_charing_para->TONOFFTABLE[3][CHRTOFF];
      }
      else
      {
         if (PHY->ICHARGE < bmt_charing_para->FAST_ICHARGE_LOWLEVEL)
         {
            BATTime->TON=bmt_charing_para->TONOFFTABLE[5][CHRTON];
            BATTime->TOFF=bmt_charing_para->TONOFFTABLE[5][CHRTOFF];
         }
         else
         {
            BATTime->TON=bmt_charing_para->TONOFFTABLE[4][CHRTON];
            BATTime->TOFF=bmt_charing_para->TONOFFTABLE[4][CHRTOFF];
         }
      }   
   }
   else
   {	 	
   	if (PHY->ICHARGE > bmt_charing_para->FAST_ICHARGE_HIGHLEVEL)
   	{
   	   BATTime->TON=bmt_charing_para->TONOFFTABLE[0][CHRTON];
   	   BATTime->TOFF=bmt_charing_para->TONOFFTABLE[0][CHRTOFF];
   	}
   	else
   	{
   	   if (PHY->ICHARGE < bmt_charing_para->FAST_ICHARGE_LOWLEVEL)
   	   {
   	      BATTime->TON=bmt_charing_para->TONOFFTABLE[2][CHRTON];
   	      BATTime->TOFF=bmt_charing_para->TONOFFTABLE[2][CHRTOFF];
   	   }
   	   else
   	   {
   	      BATTime->TON=bmt_charing_para->TONOFFTABLE[1][CHRTON];
   	      BATTime->TOFF=bmt_charing_para->TONOFFTABLE[1][CHRTOFF];
   	   }
   	}
    }	
}

/*
* FUNCTION
*	   BMT_CtrlCharge
*
* DESCRIPTION                                                           
*   	This function is called to control the SW of charge
*
* CALLS  
*
* PARAMETERS
*	   ON: 1, charge on     0, charge off
*     VBAT: the measured voltage of battery.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
static void BMT_CtrlCharge(kal_uint8 ON, kal_uint32 VBAT)
{
   /*Prevent Charge Li Battery at CV mode*/
   if (((ON == KAL_TRUE) && 
       (BMT.call_state == talk_mode) &&
       (VBAT >= bmt_charing_para->V_PROTECT_HIGH_LI) &&	
       (BMT.BatType == LIBAT)) || (BMT.bat_state == CHR_ERROR)
      )
   {
      BMT.pmictrl_state = PMIC_CHARGEOFF;
      BMT_Charge(KAL_FALSE);
      return;
   }

   if (ON == KAL_TRUE)
   {
      BMT.pmictrl_state = PMIC_CHARGEON;
      BMT_Charge(KAL_TRUE);
   }
   else
   {
      BMT.pmictrl_state = PMIC_CHARGEOFF;
      BMT_Charge(KAL_FALSE);
   }
}

/*
* FUNCTION
*	   BMT_PhyCheck
*
* DESCRIPTION                                                           
*   	This function is to check whether the measured physical
*     parameters is over the physical limitation.
*
* CALLS  
*
* PARAMETERS
*	   Data: None
*	
* RETURNS
*	   BATPHYS: measured physical parameters
*
* GLOBALS AFFECTED
*     None
*/
static void BMT_PhyCheck(BATPHYStruct *BATPHYS)
{
   #ifdef BMT_DEBUG
   /*dbg_printWithTime("BMT_PhyCheck\r\n");*/
   #endif   /*BMT_DEBUG*/
   
   if(bmt_charing_para->bmt_check_charger)
   {
   if(BATPHYS->VCHARGER> bmt_charing_para->VCHARGER_HIGH || BATPHYS->VCHARGER< bmt_charing_para->VCHARGER_LOW)
   {
	   	if( (BATPHYS->VCHARGER < bmt_charing_para->VCHARGER_LOW) && (low_charger_count <= 5))
	   	{
	   		low_charger_count++;
	   	}
	   	else
   		{	      
   			low_charger_count = 0;
   			#ifdef BMT_KAL_DEBUG 
               kal_trace(TRACE_FUNC, BMT_INVALID_CHARGER_TRC);
            #endif   
            #ifdef BMT_DEBUG
               dbg_printWithTime("Invalid Charger\r\n");
            #endif   /*BMT_DEBUG*/
            BMT_sendMes2UEM(BMT_INVALID_CHARGER);
            BMT.bat_state = CHR_ERROR;
            return;
         }
   }
   else
   	low_charger_count = 0;
   }
   
   if (BMT.pmictrl_state == PMIC_CHARGEOFF)
   {
      if(BATPHYS->ICHARGE > bmt_charing_para->ICHARGE_OFF_HIGH)
      {
         if(over_current_count <= 3)
	      {
	         over_current_count++;
	      }
	      else
	      {         	
	         over_current_count = 0;   
	         #ifdef BMT_KAL_DEBUG       
      	      kal_trace(TRACE_FUNC, BMT_ICHARGE_OVER_TRC);
      	   #endif   
            #ifdef BMT_DEBUG         
               dbg_printWithTime("ICHARGE over\r\n");
            #endif   /*BMT_DEBUG*/
            BMT_sendMes2UEM(BMT_OVERCHARGECURRENT);
            BMT.bat_state = CHR_ERROR;
            return;
            //Send message!!
         }
      }
      else  
         over_current_count = 0;
   }
   else
   {
      if(BATPHYS->ICHARGE > bmt_charing_para->ICHARGE_ON_HIGH)
      {
         if(over_current_count <= 3)
	      {
	         over_current_count++;
	      }
	      else
	      {         	
	         over_current_count = 0;     
	         #ifdef BMT_KAL_DEBUG     
      	      kal_trace(TRACE_FUNC, BMT_ICHARGE_OVER_TRC);
      	   #endif   
            #ifdef BMT_DEBUG         
               dbg_printWithTime("ICHARGE over\r\n");
            #endif   /*BMT_DEBUG*/
            BMT_sendMes2UEM(BMT_OVERCHARGECURRENT);
            BMT.bat_state = CHR_ERROR;
            return;
            //Send message!!
         }   

      }
      else
         over_current_count = 0;
   
      if ( (BMT.bat_state == CHR_FAST)) //|| (BMT.bat_state == CHR_PRE) )
      {
         if(BATPHYS->ICHARGE < bmt_charing_para->ICHARGE_ON_LOW)
         {
	         if(low_current_count <= 5)
	         {
	         	low_current_count++;
	         }
	         else
	         {         	
	            low_current_count = 0;
	            #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_ICHARGE_LOW_TRC);
               #endif   
               #ifdef BMT_DEBUG
               dbg_printWithTime("ICHARGE too low\r\n");
               #endif   /*BMT_DEBUG*/
               BMT_sendMes2UEM(BMT_LOWCHARGECURRENT);
               BMT.bat_state = CHR_ERROR;
               return;
               //Send message!!
	         }
      	}
         else
         {
         	low_current_count = 0;
         }
      }
   }
   
   if((BATPHYS->VBAT > bmt_charing_para->MAX_VBAT_LI) && (BMT.BatType == LIBAT) )
   {
      #ifdef BMT_KAL_DEBUG 
         kal_trace(TRACE_FUNC, BMT_VBAT_OVER_TRC);
      #endif   
      #ifdef BMT_DEBUG
         dbg_printWithTime("OVERVOLPROTECT \r\n");
      #endif   /*BMT_DEBUG*/
      BMT_sendMes2UEM(BMT_OVERVOLPROTECT);
      BMT.bat_state = CHR_ERROR;
      return;
   }
   
   if((BATPHYS->VBAT > bmt_charing_para->MAX_VBAT_NI) && (BMT.BatType == NIBAT) )
   {
      #ifdef BMT_KAL_DEBUG 
         kal_trace(TRACE_FUNC, BMT_VBAT_OVER_TRC);
      #endif   
      #ifdef BMT_DEBUG
      dbg_printWithTime("OVERVOLPROTECT \r\n");
      #endif   /*BMT_DEBUG*/
      BMT_sendMes2UEM(BMT_OVERVOLPROTECT);
      BMT.bat_state = CHR_ERROR;
      return;
   }

   if(bmt_charing_para->bmt_check_temp)
   {
   /*y=69.65-47.4x*/
   if (BATPHYS->BATTMP < bmt_charing_para->BATTMP_45C)   /*battery temperature > 45C*/
   {
   	if(over_temper_count < 5)
   	{
   		over_temper_count++;
   	}
   	else
   	{
   		over_temper_count = 0;
   		#ifdef BMT_KAL_DEBUG 
            kal_trace(TRACE_FUNC, BMT_VTEMP_OVER_TRC);
         #endif   
         #ifdef BMT_DEBUG
            dbg_printWithTime("OVERBATTEMP \r\n");
         #endif   /*BMT_DEBUG*/
         BMT_sendMes2UEM(BMT_OVERBATTEMP);
         BMT.bat_state = CHR_ERROR;
         return;
   }
   }
   else
   	over_temper_count = 0;
   
   if (BATPHYS->BATTMP > bmt_charing_para->BATTMP_MINUS_40C)
   {
        BMT_sendMes2UEM(BMT_BATTERY_BAD_CONTACT);
         BMT.bat_state = CHR_ERROR;
         return;
   }
       
   if(BATPHYS->BATTMP > bmt_charing_para->BATTMP_0C && BATPHYS->BATTMP < bmt_charing_para->BATTMP_MINUS_40C)  /*battery temperature < 0C*/
   {
   	if( low_temper_count < 5)
   	{
   		low_temper_count++;
   	}
   	else
   	{
   		low_temper_count = 0;
   	   #ifdef BMT_KAL_DEBUG 	
            kal_trace(TRACE_FUNC, BMT_VTEMP_LOW_TRC);
         #endif   
         #ifdef BMT_DEBUG
            dbg_printWithTime("LOWBATTEMP \r\n");
         #endif   /*BMT_DEBUG*/
         BMT_sendMes2UEM(BMT_LOWBATTEMP);
         BMT.bat_state = CHR_ERROR;
         return;
      }
   }
   else
   	low_temper_count = 0;
   }   	


   if ((BMT.call_state == talk_mode) && (SaftyTimer_Flag == BMT_SaftyTimer_On))
     {	
				stack_stop_timer(&ChargeTimeout_timer);
		  #ifdef BMT_KAL_DEBUG 	
			  kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_STOP_TRC);				
		  #endif		
        SaftyTimer_Flag = BMT_SaftyTimer_Off; 
     }  
      
   if ((BMT.call_state != talk_mode) && (SaftyTimer_Flag == BMT_SaftyTimer_Off))
     {	
		  stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*60*6);
		  #ifdef BMT_KAL_DEBUG 	
			  kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_START_TRC);
		  #endif		
        SaftyTimer_Flag = BMT_SaftyTimer_On; 
     }   
   
   if ((BMT.call_state == talk_mode) &&
       (BATPHYS->VBAT >= bmt_charing_para->V_PROTECT_HIGH_LI) &&
       (BMT.BatType == LIBAT) )
   {
   	if(BMT.pmictrl_state == PMIC_CHARGEOFF ||
   		(BMT.pmictrl_state == PMIC_CHARGEON) &&
   		(BMT.bat_state == CHR_TOPOFF || BMT.bat_state == CHR_BATFULL))
   {
      #ifdef BMT_KAL_DEBUG 
         kal_trace(TRACE_FUNC, BMT_CHR_HOLD_TRC);
      #endif   
      #ifdef BMT_DEBUG
         dbg_printWithTime("CHR_HOLD \r\n");
      #endif   /*BMT_DEBUG*/
      BMT.bat_state = CHR_HOLD;
      return;
   }
}

}
/*
* FUNCTION
*	   BMT_ObtainBMTPHYSTAT
*
* DESCRIPTION                                                           
*   	This function is used to obtain the ADC measure result.
*     Average the received Phy. data
*
* CALLS  
*
* PARAMETERS
*	   Data: None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
kal_bool BMT_ObtainBMTPHYSTAT(BATPHYStruct *BATPHYS)
{
   kal_uint32 III;
   
   BATPHYS->VBAT = VOL_RESULT[bmt_bmtid_adcscheid[ADC_BMT_VBAT]];
   BATPHYS->ICHARGE = VOL_RESULT[bmt_bmtid_adcscheid[ADC_BMT_VISENSE]];
   if(bmt_charing_para->bmt_check_temp)
   	BATPHYS->BATTMP = VOL_RESULT[bmt_bmtid_adcscheid[ADC_BMT_VBATTMP]];
   
   if(bmt_charing_para->bmt_check_charger)
	   BATPHYS->VCHARGER = VOL_RESULT[bmt_bmtid_adcscheid[ADC_BMT_VCHARGER]];
   
   #ifdef BMT_DEBUG
   dbg_printWithTime("1Measure result: the VBAT = %d\r\n",BATPHYS->VBAT);
   dbg_printWithTime("1the BATTMP = %d\r\n",BATPHYS->BATTMP);
   dbg_printWithTime("1Measure result: the ICHARGE = %d\r\n",BATPHYS->ICHARGE);
   #endif   /*BMT_DEBUG*/
   
   III = (BATPHYS->ICHARGE-BATPHYS->VBAT);
         
   BATPHYS->ICHARGE = (kal_int32)((BATPHYS->ICHARGE-BATPHYS->VBAT)*bmt_charing_para->ADC_ISENSE_RESISTANCE_FACTOR);
   BATPHYS->ICHARGE -= bmt_charing_para->CurrOffset[BMT.call_state];
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_VBAT_TRC, BATPHYS->VBAT);
      kal_trace(TRACE_FUNC, BMT_ICHARGE_TRC, BATPHYS->ICHARGE);
   if(bmt_charing_para->bmt_check_temp)
      kal_trace(TRACE_FUNC, BMT_BATTMP_TRC, BATPHYS->BATTMP);      
   if(bmt_charing_para->bmt_check_charger)
      kal_trace(TRACE_FUNC, BMT_VCHARGER_TRC, BATPHYS->VCHARGER);      
   #endif
         
   #ifdef BMT_DEBUG
   dbg_printWithTime("Measure result: the VBAT = %d\r\n",BATPHYS->VBAT);
   dbg_printWithTime("the BATTMP = %d\r\n",BATPHYS->BATTMP);
   dbg_printWithTime("Measure result: the ICHARGE = %d\r\n",BATPHYS->ICHARGE);
   #endif   /*BMT_DEBUG*/
	if ((BMT.pmictrl_state == PMIC_CHARGEOFF)  ||
		(BMT.pmictrl_state == PMIC_CHARGEON ) &&
		( (BMT.bat_state == CHR_TOPOFF) || (BMT.bat_state == CHR_BATFULL) ))
	{
		VBAT_OFF = BATPHYS->VBAT;
		ADCBAT_OFF = ADC_RESULT[bmt_bmtid_adcscheid[ADC_BMT_VBAT]];
	}
   return KAL_TRUE;
}

/*
* FUNCTION
*	   BMT_CHRPRE_ON
*
* DESCRIPTION                                                           
*   	This function is called when charger is on, and BMT charge module 
*     is at CHR_PRE state.
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
static void BMT_CHRPRE_ON(void)
{
   BATPHYStruct BATPHYS;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_CHRPRE_ON_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRPRE_ON\r\n");
   #endif   /*BMT_DEBUG*/
   if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
   {
      BMT_PhyCheck(&BATPHYS);
      BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);   //Turn off Charge
   }
   bmt_timer_config(bmt_charing_para->PRE_TOFF*KAL_TICKS_1_SEC);
}

/*
* FUNCTION
*	   BMT_CHRPRE_OFF
*
* DESCRIPTION                                                           
*   	This function is called when charger is off, and BMT charge module 
*     is at CHR_PRE state.
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
static void BMT_CHRPRE_OFF(void)
{
   BATPHYStruct BATPHYS;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_CHRPRE_OFF_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRPRE_OFF\r\n");
   #endif   /*BMT_DEBUG*/
   
   if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is off period
   {
      BMT_PhyCheck(&BATPHYS);
      
      if( ((BATPHYS.VBAT) > bmt_charing_para->V_PRE2FAST_THRES) && (BMT.bat_state !=CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
      {
         BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);
         BMT.bat_state = CHR_FAST;
         if(BMT.PWRon == PRECHRPWRON)//PRECHRPWRON
         {
            ilm_struct *BMT_ilm;            
            /*change power on type as charger power on*/                   
            BMT.PWRon = CHRPWRON;
            #ifndef L4_NOT_PRESENT
            #if ( (defined(MT6318))|| (defined(MT6305)) )
            PW_update_flags();           
            #endif
            #endif
            DRV_BuildPrimitive(BMT_ilm, MOD_BMT, MOD_UEM, 
                              MSG_ID_BMT_LEAVE_PRECHARGE_IND,NULL);
                              
            msg_send_ext_queue(BMT_ilm);                              
         }                     
         #ifdef BMT_KAL_DEBUG 
            kal_trace(TRACE_FUNC, BMT_FAST_CHARGE_CHANGE_TRC);
         #endif   
         #ifdef BMT_DEBUG
         dbg_printWithTime(">>>>>>>>>>>>>>>>>>>>>>>>>chage state to FAST_CHARGE\r\n");
         #endif   /*BMT_DEBUG*/
      }
      else
      {
         BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);   //Turn on Charge
      }
   }
   bmt_timer_config(bmt_charing_para->PRE_TON*KAL_TICKS_1_SEC);
}

/*
* FUNCTION
*	   BMT_CHRFAST_ON
*
* DESCRIPTION                                                           
*   	This function is called when charger is on, and BMT charge module 
*     is at CHR_FAST state.
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
static void BMT_CHRFAST_ON(void)
{
   BATPHYStruct BATPHYS;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_FAST_ON_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRFAST_ON\r\n");
   #endif   /*BMT_DEBUG*/
   if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
   {
      BMT_PhyCheck(&BATPHYS);
      BMT_TONOFF(&BATPHYS,&BATTime);
      if(BMT.bat_state != CHR_ERROR)
      {
         //Change state
         if (BMT.BatType == NIBAT)
         {
            if ( ((VBATtmp - BATPHYS.VBAT) > 100000) && (VBATtmp != 0) )
            {
               BMT.bat_state = CHR_BATFULL;
               bmt_stop_stoptimer();
               stack_stop_timer(&ChargeTimeout_timer);
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_STOP_TRC);
               #endif   
               /*30min*/
               bmt_set_stoptimer(KAL_TICKS_1_MIN*30);
			      VBATtmp = 0;
               BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);
               BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
               #ifdef BMT_KAL_DEBUG                
                  kal_trace(TRACE_FUNC, BMT_CHR_BATFULL_CHANGE_TRC);
               #endif   
               #ifdef BMT_DEBUG
               dbg_printWithTime(">>>>>>>>>>>>>>>>>>>>>>>>>chage state to CHR_BATFULL\r\n");   
               #endif   /*BMT_DEBUG*/
               bmt_timer_config(BATTime.TOFF*KAL_TICKS_1_SEC);
               return;
            }

            if (BATPHYS.BATTMP < bmt_charing_para->V_TEMP_FAST2FULL_THRES_NI)
            {
               BMT.bat_state = CHR_BATFULL;
               bmt_stop_stoptimer();
               stack_stop_timer(&ChargeTimeout_timer);
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_STOP_TRC);
               #endif   
               /*30min*/
               bmt_set_stoptimer(KAL_TICKS_1_MIN*30);
               BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);
               BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
               bmt_timer_config(BATTime.TOFF*KAL_TICKS_1_SEC);
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_CHR_BATFULL_CHANGE_TRC);
               #endif   
               #ifdef BMT_DEBUG
               dbg_printWithTime(">>>>>>>>>>>>>>>>>>>>>>>>>chage state to CHR_BATFULL\r\n");   
               #endif   /*BMT_DEBUG*/
               return;
            }

            VBATtmp = BATPHYS.VBAT;
         }
      }
      BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);   //Turn off Charge
   }
   bmt_timer_config(BATTime.TOFF*KAL_TICKS_1_SEC);
}

/*
* FUNCTION
*	   BMT_CHRFAST_OFF
*
* DESCRIPTION                                                           
*   	This function is called when charger is off, and BMT charge module 
*     is at CHR_FAST state.
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
static void BMT_CHRFAST_OFF(void)
{
   BATPHYStruct BATPHYS;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_FAST_OFF_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRFAST_OFF\r\n");
   #endif   /*BMT_DEBUG*/
   if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
   {
      BMT_PhyCheck(&BATPHYS);

      if((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
      {
         if ((BMT.BatType == LIBAT) &&
             (BATPHYS.VBAT > bmt_charing_para->V_FAST2TOPOFF_THRES)
            )
         {
            BMT.bat_state = CHR_TOPOFF;
            BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);
            #ifdef BMT_KAL_DEBUG 
               kal_trace(TRACE_FUNC, BMT_CHR_TOPOFF_CHANGE_TRC);
            #endif   
            #ifdef BMT_DEBUG
            dbg_printWithTime(">>>>>>>>>>>>>>>>>>>>>>>>>chage state to CHR_TOPOFF\r\n");
            #endif   /*BMT_DEBUG*/
            bmt_timer_config(BATTime.TON*KAL_TICKS_1_SEC);
            return;
         }
         
         if ((BMT.BatType == NIBAT) &&
             (BATPHYS.BATTMP < bmt_charing_para->V_TEMP_FAST2FULL_THRES_NI)
            )
         {
            BMT.bat_state = CHR_BATFULL;
            BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);
            bmt_stop_stoptimer();
            stack_stop_timer(&ChargeTimeout_timer);
            #ifdef BMT_KAL_DEBUG 
               kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_STOP_TRC);
            #endif   
            /*30min*/
            bmt_set_stoptimer(KAL_TICKS_1_MIN*30);
            BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
            #ifdef BMT_KAL_DEBUG 
               kal_trace(TRACE_FUNC, BMT_CHR_BATFULL_CHANGE_TRC);
            #endif   
            #ifdef BMT_DEBUG
            dbg_printWithTime(">>>>>>>>>>>>>>>>>>>>>>>>>chage state to CHR_BATFULL\r\n");   
            #endif   /*BMT_DEBUG*/
         }
         BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);   //Turn on Charge
      }
   }
   bmt_timer_config(BATTime.TON*KAL_TICKS_1_SEC);
}

/*
* FUNCTION
*	   BMT_CHRTOPOFF_ON
*
* DESCRIPTION                                                           
*   	This function is called when charger is on, and BMT charge module 
*     is at CHR_TOPOFF state.
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
static void BMT_CHRTOPOFF_ON(void)     //CV
{
   BATPHYStruct BATPHYS;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_CHRTOPOFF_ON_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRTOPOFF_ON\r\n");
   #endif   /*BMT_DEBUG*/
   if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
   {
      BMT_PhyCheck(&BATPHYS);
      if(BMT.bat_state != CHR_ERROR)
      {
         if (BATPHYS.ICHARGE < bmt_charing_para->I_TOPOFF2FULL_THRES)
         {
            BATFULL_index++;
            if (BATFULL_index == 6)
            {
               BATFULL_index = 0;	
               BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);
               BMT.bat_state = CHR_BATFULL;
               bmt_stop_stoptimer();
               stack_stop_timer(&ChargeTimeout_timer);
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_SAFETY_TIMER_STOP_TRC);
               #endif   
               /*30min*/
               bmt_set_stoptimer(KAL_TICKS_1_MIN*30);
               BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_CHR_BATFULL_CHANGE_TRC);
               #endif   
               #ifdef BMT_DEBUG
               dbg_printWithTime(">>>>>>>>>>>>>>>>>>>>>>>>>chage state to CHR_BATFULL\r\n");   
               #endif   /*BMT_DEBUG*/
            }
            else
            {
               BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);
            }
         }
         else
         {
            BATFULL_index = 0;
            BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);
         }
      }
   }
   bmt_timer_config(bmt_charing_para->TOPOFF_TON*KAL_TICKS_1_SEC);
}

/*
* FUNCTION
*	   BMT_CHRTOPOFF_OFF
*
* DESCRIPTION                                                           
*   	This function is called when charger is off, and BMT charge module 
*     is at CHR_TOPOFF state.
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
static void BMT_CHRTOPOFF_OFF(void)
{
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_CHRTOPOFF_OFF_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRTOPOFF_OFF\r\n");
   #endif   /*BMT_DEBUG*/
}

/*
* FUNCTION
*	   BMT_CHRBATFULL_ON
*
* DESCRIPTION                                                           
*   	This function is called when charger is on, and BMT charge module 
*     is at CHR_BATFULL state.
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
static void BMT_CHRBATFULL_ON(void)
{
   BATPHYStruct BATPHYS;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_CHRBATFULL_ON_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRBATFULL_ON\r\n");
   #endif   /*BMT_DEBUG*/
   
   if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
   {
      BMT_PhyCheck(&BATPHYS);
      if(BMT.bat_state != CHR_ERROR)
      {
         if (BMT.BatType == LIBAT)
         {
            if ((BATPHYS.VBAT) < bmt_charing_para->V_FULL2FAST_THRES)
            {
               BMT.bat_state = CHR_FAST;
               bmt_stop_stoptimer();
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_CHR_FAST_CHANGE_TRC);
               #endif   
               #ifdef BMT_DEBUG
                  dbg_printWithTime("Change state to CHR_FAST\r\n");
               #endif   /*BMT_DEBUG*/
            }
            BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);
            bmt_timer_config(bmt_charing_para->BATFULL_TON_LI*KAL_TICKS_1_SEC);
         }
         
         if (BMT.BatType == NIBAT)
         {
            if ((BATPHYS.VBAT) < bmt_charing_para->V_FULL2FAST_THRES_NI)
            {
               BMT.bat_state = CHR_FAST;
               bmt_stop_stoptimer();
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_CHR_FAST_CHANGE_TRC);
               #endif   
               #ifdef BMT_DEBUG
                  dbg_printWithTime("Change state to CHR_FAST\r\n");
               #endif   /*BMT_DEBUG*/
            }
            BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);
            bmt_timer_config(bmt_charing_para->BATFULL_TOFF_NI*KAL_TICKS_1_SEC);
         }
      }
      else
      {
         BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);
         bmt_timer_config(1*KAL_TICKS_1_SEC);         
      }      
   }
}

/*
* FUNCTION
*	   BMT_CHRBATFULL_OFF
*
* DESCRIPTION                                                           
*   	This function is called when charger is off, and BMT charge module 
*     is at CHR_BATFULL state.
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
*/
static void BMT_CHRBATFULL_OFF(void) 
{
   BATPHYStruct BATPHYS;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_CHRBATFULL_OFF_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRBATFULL_OFF\r\n");
   #endif   /*BMT_DEBUG*/
   
   if (BMT.highfull)
   {
      #ifdef BMT_KAL_DEBUG 
         kal_trace(TRACE_FUNC, BMT_HIGH_BAT_FULL_TRC);
      #endif   
      #ifdef BMT_DEBUG
      dbg_print("High Battery Full!!\r\n");
      #endif   /*BMT_DEBUG*/
      if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
      {
         BMT_PhyCheck(&BATPHYS);
         if((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
         {
            if((BMT.BatType == LIBAT) &&
               ((BATPHYS.VBAT) < bmt_charing_para->V_FULL2FAST_THRES)
            )
            {
               BMT.bat_state = CHR_FAST;
               bmt_stop_stoptimer();
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_CHR_FAST_CHANGE_TRC);
               #endif   
               #ifdef BMT_DEBUG
               dbg_printWithTime("Change state to CHR_FAST\r\n");
               #endif   /*BMT_DEBUG*/
               BMT.highfull = 0;
            }
         
            if( (BMT.BatType == NIBAT) &&
               ((BATPHYS.VBAT) < bmt_charing_para->V_FULL2FAST_THRES_NI)
               )
            {
               BMT.bat_state = CHR_FAST;
               bmt_stop_stoptimer();
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_CHR_FAST_CHANGE_TRC);
               #endif   
               #ifdef BMT_DEBUG
               dbg_printWithTime("Change state to CHR_FAST\r\n");
               #endif   /*BMT_DEBUG*/
               BMT.highfull = 0;
            }
         }
      }
      BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);
      bmt_timer_config(bmt_charing_para->BATFULL_TOFF*KAL_TICKS_1_SEC);
      return;
   }
   
   if (BMT.BatType == NIBAT)
   {
      if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
      {
         BMT_PhyCheck(&BATPHYS);
         if(BMT.bat_state != CHR_ERROR)
         {
            if( (BMT.BatType == NIBAT) &&
                ((BATPHYS.VBAT) < bmt_charing_para->V_FULL2FAST_THRES_NI)
               )
            {
               BMT.bat_state = CHR_FAST;
               bmt_stop_stoptimer();
               #ifdef BMT_KAL_DEBUG 
                  kal_trace(TRACE_FUNC, BMT_CHR_FAST_CHANGE_TRC);
               #endif   
               #ifdef BMT_DEBUG
               dbg_printWithTime("Change state to CHR_FAST\r\n");
               #endif   /*BMT_DEBUG*/
            }
         }
      }
      if(BMT.bat_state != CHR_ERROR)
         BMT_CtrlCharge(KAL_TRUE, BATPHYS.VBAT);
      bmt_timer_config(bmt_charing_para->BATFULL_TON_NI*KAL_TICKS_1_SEC);
   }
}

/*
* FUNCTION
*	   BMT_CHARSTOP
*
* DESCRIPTION                                                           
*   	This function is called if charge is complete and run after 30 min
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
*/
void BMT_CHARSTOP(void)  /*30 min*/
{
   kal_uint8 index;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_MEASURE_STOP_TRC);
   #endif   
   #ifdef BMT_DEBUG   
   dbg_print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>bmt_chrstop\r\n");
   #endif   /*BMT_DEBUG*/
   BMT_CtrlCharge(KAL_FALSE, 4200000);   //Stop Charge!!
   BMT.highfull = 1;
   for(index=0;index<BMT_MAX_CHANNEL;index++)
	   adc_sche_remove_item(bmt_bmtid_adcscheid[index]);
   bmt_timer_config(bmt_charing_para->BATFULL_TOFF*KAL_TICKS_1_SEC);
}

/*
* FUNCTION
*	   BMT_CHRHOLD
*
* DESCRIPTION                                                           
*   	This function is called when BMT charge module 
*     is at CHR_HOLD state.
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
static void BMT_CHRHOLD(void)
{
   BATPHYStruct BATPHYS;
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_CHRHOLD_STATE_TRC);
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BMT_CHRHOLD\r\n");
   #endif   /*BMT_DEBUG*/
   if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
   {
      BMT_PhyCheck(&BATPHYS);
      if(((BATPHYS.VBAT) < bmt_charing_para->V_PROTECT_LOW_LI) || (BMT.call_state == 0))
      {
         BMT.bat_state = CHR_FAST;
         bmt_stop_stoptimer();
         #ifdef BMT_KAL_DEBUG 
            kal_trace(TRACE_FUNC, BMT_FAST_CHARGE_CHANGE_TRC);
         #endif   
         #ifdef BMT_DEBUG
            dbg_printWithTime("Change state to CHR_FAST\r\n");
         #endif   /*BMT_DEBUG*/
      }
   }
   BMT_CtrlCharge(KAL_FALSE, BATPHYS.VBAT);
   bmt_timer_config(bmt_charing_para->BATHOLD_OFF*KAL_TICKS_1_SEC);
}

/*
* FUNCTION
*	   BMT_MeasureStop
*
* DESCRIPTION                                                           
*   	This function is used to stop the charge measure, and restart normal measure.
*     Besides, this function is called when BMT charge module 
*     is at CHR_ERROR state.
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
void BMT_MeasureStop(void)
{
   #ifdef BMT_KAL_DEBUG 
      kal_trace(TRACE_FUNC, BMT_MEASURE_STOP_TRC);   
   #endif   
   #ifdef BMT_DEBUG
   dbg_printWithTime("BMT_MeasureStop\r\n");
   #endif   /*BMT_DEBUG*/
   VBATtmp = 0;
   BMT.pmictrl_state = PMIC_CHARGEOFF;
   bmt_charge_end();
}

