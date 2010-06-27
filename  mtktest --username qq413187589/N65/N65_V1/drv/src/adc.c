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
 *    adc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the auxiliary ADC driver and adaption layer.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "adc.h"
#include "drvpdn.h"
#include "rtc_hw.h"
#include "bmt.h"
#ifdef __MULTI_BOOT__
#include "kal_release.h"
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/
#include    "pwic.h"

#if defined(DRV_ADC_TDMA_TIME)
extern void adc_tdma_time_setup(kal_uint16 idle_time, kal_uint16 trx_time);
#endif   /*DRV_ADC_TDMA_TIME*/
extern kal_bool adc_sync_mode_on;
extern kal_uint16 adc_imm_mode_cnt;

/*
* FUNCTION                                                            
*	ADC_GetData
*
* DESCRIPTION                                                           
*   	This function is to run ADC, and obtain the measured data
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*	
* RETURNS
*	return the value of ADC output
*
* GLOBALS AFFECTED
*   external_global
*/
/*must add power on function before this function*/
kal_uint16 ADC_GetData(kal_uint8 sel)
{
   kal_uint16 data;
   kal_uint16 i;
   kal_uint32 savedMask;
   
   #ifdef __MULTI_BOOT__
      //ASSERT(stack_query_boot_mode() == FACTORY_BOOT);
   #endif   /*__MULTI_BOOT__*/
   ASSERT(sel < ADC_MAX_CHANNEL);
   
#if defined(DRV_ADC_NO_IMM) || defined(FPGA)
   savedMask = SaveAndSetIRQMask();	
   adc_pwrdown_disable();
   DRV_WriteReg(AUXADC_CTRL,sel);
   adc_imm_mode_cnt++;
   RestoreIRQMask(savedMask);
   while(!(DRV_Reg(AUXADC_STAT) & AUXADC_STAT_RDY));
   data = DRV_Reg(AUXADC_DATA);
#endif   /*(DRV_ADC_NO_IMM,FPGA)*/
#if defined(DRV_ADC_IMM)
   savedMask = SaveAndSetIRQMask();	
   adc_imm_mode_cnt++;
   pmic_adpt_adc_measure(KAL_TRUE);
   RestoreIRQMask(savedMask);
   savedMask = SaveAndSetIRQMask();	
   adc_pwrdown_disable();
   DRV_Reg(AUXADC_IMM) = 0;
   DRV_Reg(AUXADC_IMM) |= (1<<sel);
   RestoreIRQMask(savedMask);
   for(i=0;i<100;i++);		/* delay for avoid reading invalid status bit */   
   while((DRV_Reg(AUXADC_CON) & AUXADC_CON_RUN));
   data = DRV_Reg(AUXADC_DAT(sel));
#endif   /*DRV_ADC_IMM*/
   savedMask = SaveAndSetIRQMask();	
   adc_imm_mode_cnt--;
   if ((((volatile kal_uint16)adc_imm_mode_cnt) == 0) && (((volatile kal_bool)adc_sync_mode_on) == KAL_FALSE))
   {
      adc_pwrdown_enable();
   }
   RestoreIRQMask(savedMask);
   savedMask = SaveAndSetIRQMask();	
   if ((((volatile kal_uint16)adc_imm_mode_cnt) == 0) && (((volatile kal_bool)adc_sync_mode_on) == KAL_FALSE))
   {
      pmic_adpt_adc_measure(KAL_FALSE);
   }
   RestoreIRQMask(savedMask);

   return data;
}

/*
* FUNCTION                                                            
*	ADC_GetMeaData
*
* DESCRIPTION                                                           
*   	This function is to run ADC, and obtain the average value of measured data
*     Note that: This function only called before other tasks are running.
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*  meacount: measure count
*	
* RETURNS
*	return the average value of ADC output
*
* GLOBALS AFFECTED
*   None
*/
kal_uint32 ADC_GetMeaData(kal_uint8 sel, kal_uint16 meacount)
{
   kal_uint16 index;
   kal_uint32 sum=0;
   #ifdef __MULTI_BOOT__
      ASSERT(stack_query_boot_mode() == FACTORY_BOOT);
   #endif   /*__MULTI_BOOT__*/
   //DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
   //adc_pwrdown_disable();
   for(index=0;index<meacount;index++)
   {
      sum += (kal_uint32)ADC_GetData(sel);
   }
   //DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
   //adc_pwrdown_enable();
   sum = sum/meacount;
   return sum;
}

/*
* FUNCTION                                                            
*	ADC_GetData2Meta
*
* DESCRIPTION                                                           
*   	This function is called by META, and return the sum value.
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*  meacount: measure count
*	
* RETURNS
*	return the average value of ADC output
*
* GLOBALS AFFECTED
*   None
*/
kal_uint32 ADC_GetData2Meta(kal_uint8 sel, kal_uint16 meacount)
{
   kal_uint16 index;
   kal_uint32 sum=0;
   #ifdef __MULTI_BOOT__
      ASSERT(stack_query_boot_mode() == FACTORY_BOOT);
   #endif   /*__MULTI_BOOT__*/
   //DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
   //adc_pwrdown_disable();
   for(index=0;index<meacount;index++)
   {
      sum += (kal_uint32)ADC_GetData(sel);
   }
   //DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
   //adc_pwrdown_enable();
   return sum;
}

void ADC_Init(void)
{
#if defined(DRV_ADC_TDMA_TIME)
   adc_tdma_time_setup(0,6000);
   DRV_WriteReg(AUXADC_CON,(AUXADC_CON_AUTOCLR0|AUXADC_CON_AUTOCLR1|AUXADC_CON_PUWAIT_EN|AUXADC_CON_TESTDACMON|0x0018));
   #if defined(DRV_RTC_XOSC_DEF_8)
      DRV_WriteReg(RTC_XOSCCAL,0x8);
   #else
      DRV_WriteReg(RTC_XOSCCAL,0x1f);
   #endif
#if defined(DRV_AUX_AC_CON_DEF_F)
   /*AUX_AC_CON*/
   DRV_WriteReg(0x80500700,0x00f);
#endif   
#if defined(DRV_AUX_AC_CON_DEF_0)
   /*AUX_AC_CON*/
   DRV_WriteReg(0x80500700,0x0);
#endif   

#if defined(DRV_AUX_AC_CON_DEF_X)
   /*AUX_AC_CON*/
   if(DRV_Reg(0x80500004)==0x8c01)
   {      
      DRV_WriteReg(0x80500700,0xf);
   } 
   else if(DRV_Reg(0x80500004)==0x8d00)
   {
      DRV_WriteReg(0x80500700,0x0);
   }
   else if(DRV_Reg(0x80500004)==0x8d01)
   {
      DRV_WriteReg(0x80500700,0x0);
   }
         
#endif   /*DRV_AUX_AC_CON_DEF_X*/

#endif   /*DRV_ADC_TDMA_TIME*/
}

