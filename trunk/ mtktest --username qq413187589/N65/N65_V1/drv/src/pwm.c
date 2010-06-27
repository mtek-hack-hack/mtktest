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
 *    pwm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the PWM driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "pwm_hw.h"
#include "pwm_sw.h"
#include "drvpdn.h"
#include "custom_hw_default.h"
#include "uart_sw.h"
#include "swdbg_sw.h"

#if !defined(DRV_PWM_RWG)
static kal_uint8  PWM1_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM1_FRE_SAVE;   /*for MMI usage*/
static kal_uint32 PWM2_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM1_DUTY_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_DUTY_SAVE;   /*for MMI usage*/
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
static kal_uint8 PWM1_PDNhandle, PWM2_PDNhandle;
#endif
/*
* FUNCTION                                                            
*	PWM_Init
*
* DESCRIPTION                                                           
*   	PWM initial function
*
* CALLS  
*	It is called before access the PWM.
*
* PARAMETERS
*	Clock:	pwmclk_1MHZ,
*		pwmclk_2MHZ,
*		pwmclk_4MHZ,
*		pwmclk_8MHZ 
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void PWM_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div)
{
   /*clk_sel only actived in MT6205B or later*/
	kal_uint16 tmp;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	PWM1_PDNhandle = L1SM_GetHandle();
	#endif
	tmp = DRV_Reg(PWM1_CTRL);
	switch(Clock_div)
	{
	   case pwmclk_1MHZ:
	      tmp |= PWM_CTRL_CLK_1;
	      break;
	      
	   case pwmclk_2MHZ:
	      tmp |= PWM_CTRL_CLK_2;
	      break;
      
      case pwmclk_4MHZ:
	      tmp |= PWM_CTRL_CLK_4;
	      break;
	      
	   case pwmclk_8MHZ:
	      tmp |= PWM_CTRL_CLK_8;
	      break;
	}

#if defined(DRV_PWM_CLK_SEL)
	switch(clk_sel)
	{
	   case pwmclk_13M:
	      tmp &= ~PWM_CTRL_CLKSEL;
	      break;
	      
	   case pwmclk_32k:
	      tmp |= PWM_CTRL_CLKSEL;
	      break;
	      
	   default:
	      break;
	}
#endif /*DRV_PWM_CLK_SEL*/
	DRV_WriteReg(PWM1_CTRL,tmp);
}

/*level = 1~5, level = 0, close PWM*/
void PWM_level(kal_uint8 level)
{
   if (level > 5)
      ASSERT(0);
   
   PWM1_LEVEL_SAVE = level;
   if (level)
   {
      PWM1_Configure(PWM1_Level_Info[level-1][0],PWM1_Level_Info[level-1][1]);
      PWM1_Start();
   }
   else
   {
      PWM1_Stop();
   }
}

#if defined(DRV_PWM_PWM2)
void PWM2_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div)
{
   /*clk_sel only actived in MT6205B or later*/
	kal_uint16 tmp;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	PWM2_PDNhandle = L1SM_GetHandle();
	#endif
	tmp = DRV_Reg(PWM2_CTRL);
	switch(Clock_div)
	{
	   case pwmclk_1MHZ:
	      tmp |= PWM_CTRL_CLK_1;
	      break;
	      
	   case pwmclk_2MHZ:
	      tmp |= PWM_CTRL_CLK_2;
	      break;
      
      case pwmclk_4MHZ:
	      tmp |= PWM_CTRL_CLK_4;
	      break;
	      
	   case pwmclk_8MHZ:
	      tmp |= PWM_CTRL_CLK_8;
	      break;
	}

	switch(clk_sel)
	{
	   case pwmclk_13M:
	      tmp &= ~PWM_CTRL_CLKSEL;
	      break;
	      
	   case pwmclk_32k:
	      tmp |= PWM_CTRL_CLKSEL;
	      break;
	      
	   default:
	      break;
	}
	DRV_WriteReg(PWM2_CTRL,tmp);
}

void PWM2_level(kal_uint8 level)
{
   if (level > 5)
      ASSERT(0);
   
   PWM2_LEVEL_SAVE = level;
   if (level)
   {
      PWM2_Configure(PWM2_Level_Info[level-1][0],PWM2_Level_Info[level-1][1]);
      PWM2_Start();
   }
   else
   {
      PWM2_Stop();
   }
}
#endif   /*DRV_PWM_PWM2*/

void PWM1_Configure(kal_uint32 freq, kal_uint8 duty)
{
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   
     
  
      
   ASSERT(duty <= 100);
   PWM1_FRE_SAVE=freq;
   PWM1_DUTY_SAVE=duty;
   reg = DRV_Reg(PWM1_CTRL);
   
   clkdiv = (1 << (reg & 0x0003));
   
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   clock = clock/clkdiv;
   
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 
   
   tmp--;
   DRV_WriteReg(PWM1_COUNT,(kal_uint16)tmp);
   tmp = ((tmp+1)*duty)/100;
   DRV_WriteReg(PWM1_THRESHOLD,(kal_uint16)tmp);
}

/*duty=50 ==> 50%*/
void PWM1_Start(void)
{
#if defined(DRV_PWM_CLK_SEL)
   kal_uint16 reg; 
   kal_uint32 clock;
   reg = DRV_Reg(PWM1_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   if(clock == 13000000)
      L1SM_SleepDisable(PWM1_PDNhandle);
   #endif   
   DRV_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM);
#else /*!(MT6205B,MT6218, MT6218B, MT6219, MT6217, MT6228,MT6229)*/
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   DRV_Reg(DRVPDN_CON1) &= ~DRVPDN_CON1_PWM;
   RestoreIRQMask(savedMask);
#endif   /*DRV_PWM_CLK_SEL*/
}

void PWM1_Stop(void)
{
#if defined(DRV_PWM_CLK_SEL)
   kal_uint16 reg; 
   kal_uint32 clock;
   reg = DRV_Reg(PWM1_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   DRV_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM);
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   if(clock == 13000000)   
      L1SM_SleepEnable(PWM1_PDNhandle);
   #endif    
#else /*!(DRV_PWM_CLK_SEL)*/
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   DRV_Reg(DRVPDN_CON1) |= DRVPDN_CON1_PWM;
   RestoreIRQMask(savedMask);
#endif   /*DRV_PWM_CLK_SEL*/
}

kal_uint8 PWM1_GetCurrentLevel(void)
{
   return PWM1_LEVEL_SAVE;
}
kal_uint32 PMW1_GetCurrentFreq(void)
{   
   return PWM1_FRE_SAVE;   
}   
kal_uint8 PMW1_GetCurrentDuty(void)
{   
   return PWM1_DUTY_SAVE;     
}
#if defined(DRV_PWM_PWM2)
void PWM2_Configure(kal_uint32 freq, kal_uint8 duty)
{
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   

   ASSERT(duty <= 100);
   PWM2_FRE_SAVE=freq;
   PWM2_DUTY_SAVE=duty;
   reg = DRV_Reg(PWM2_CTRL);
   
   clkdiv = (1 << (reg & 0x0003));
   
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   clock = clock/clkdiv;
   
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 
   
   tmp--;
   DRV_WriteReg(PWM2_COUNT,(kal_uint16)tmp);
   tmp = ((tmp+1)*duty)/100;
   DRV_WriteReg(PWM2_THRESHOLD,(kal_uint16)tmp);
}

/*duty=50 ==> 50%*/
void PWM2_Start(void)
{
   kal_uint16 reg; 
   kal_uint32 clock;
   reg = DRV_Reg(PWM2_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   if(clock == 13000000)   
      L1SM_SleepDisable(PWM2_PDNhandle);
   #endif   
   DRV_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM2);
   /*to cover HW issue*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__)
   swdbg_pwr_up();
   #endif
   #endif
}

void PWM2_Stop(void)
{
   kal_uint16 reg; 
   kal_uint32 clock;
   reg = DRV_Reg(PWM2_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   if(clock == 13000000)         
      L1SM_SleepEnable(PWM2_PDNhandle);
   #endif   
   DRV_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM2);
   #if defined(DRV_PWM_PWM2_SWDBG)
   #if !defined(__FUE__)
   swdbg_pwr_down();
   #endif
   #endif
}

kal_uint8 PWM2_GetCurrentLevel(void)
{
   return PWM2_LEVEL_SAVE;
}
kal_uint32 PMW2_GetCurrentFreq(void)
{
   return PWM2_FRE_SAVE;      
}   
kal_uint8 PMW2_GetCurrentDuty(void)
{
   return PWM2_DUTY_SAVE;      
}   
#endif   /*DRV_PWM_PWM2*/

#endif  /* !defined(DRV_PWM_RWG) */
