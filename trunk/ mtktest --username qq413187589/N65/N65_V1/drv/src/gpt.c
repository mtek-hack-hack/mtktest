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
 *    gpt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the GPT driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "gpt_hw.h"
#include "gpt_sw.h"
#include "intrCtrl.h"
#include "gpio_sw.h"
#include "drvpdn.h"
#include "drv_hisr.h"
#include "lpwr.h"

#define GPT_INTERNAL_SRAM
#define GPT_DRVPDN_FAST

#ifdef GPT_INTERNAL_SRAM
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif
static GPTStruct GPTTimer;
#ifdef GPT_INTERNAL_SRAM
#pragma arm section rwdata, rodata , zidata
#endif

//extern void dbg_print(char *fmt,...);

/*
* FUNCTION                                                            
*	GPT_clock
*
* DESCRIPTION                                                           
*   	This function is to setup GPT clock
*
* CALLS  
*	It is called to setup GPT clock
*
* PARAMETERS
*	timerNum = 1(GPT1) or 2(GPT2)
*	clock = clk_16k,
*		clk_8k,
*		clk_4k,
*		clk_2k,
*		clk_1k,
*		clk_500,
*		clk_250,
*		clk_125
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPT_clock(kal_uint8 timerNum ,gpt_clock clock)
{
	kal_uint16 *ptr_addr=0;
	if ( timerNum == 1)
	{
		ptr_addr = (kal_uint16 *)GPT1_PRESCALER;
	}
	if ( timerNum == 2)
	{
		ptr_addr = (kal_uint16 *)GPT2_PRESCALER;
	}
	
	switch(clock)
	{
		case clk_16k:
		   DRV_WriteReg(ptr_addr,GPT_PRESCALER_div2);
			break;
			
		case clk_8k:
		   DRV_WriteReg(ptr_addr,GPT_PRESCALER_div4);
			break;			
			
		case clk_4k:
		   DRV_WriteReg(ptr_addr,GPT_PRESCALER_div8);
			break;			
			
		case clk_2k:
		   DRV_WriteReg(ptr_addr,GPT_PRESCALER_div16);
			break;			
			
		case clk_1k:
		   DRV_WriteReg(ptr_addr,GPT_PRESCALER_div32);
			break;			
			
		case clk_500:
		   DRV_WriteReg(ptr_addr,GPT_PRESCALER_div64);
			break;			
			
		case clk_250:
		   DRV_WriteReg(ptr_addr,GPT_PRESCALER_div128);
			break;			
			
		case clk_125:
		   DRV_WriteReg(ptr_addr,GPT_PRESCALER_div256);
			break;
			
		default:
			break;
	}
}

/*
* FUNCTION                                                            
*	GPT_ResetTimer
*
* DESCRIPTION                                                           
*   	This function is to setup GPT parameters
*
* CALLS  
*	It is called to setup GPT parameters
*
* PARAMETERS
*	timerNum = 1(GPT1) or 2(GPT2)
*	countValue = GPT count
*	autoReload = KAL_TRUE,autoReload mode
*		     KAL_FALSE, Single shot mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPT_ResetTimer(kal_uint8 timerNum,kal_uint16 countValue,kal_bool autoReload)
{
	if (timerNum == 1)
	{
	   DRV_WriteReg(GPT1_LEN,countValue);
		if (autoReload == KAL_TRUE)
		{
			DRV_Reg(GPT1_CTRL) |= GPT_CTRL_AUTOMODE;
		}
		else
		{
			DRV_Reg(GPT1_CTRL) &= ~GPT_CTRL_AUTOMODE;
		}
	}

	if (timerNum == 2)
	{
	   DRV_WriteReg(GPT2_LEN,countValue);
		if (autoReload == KAL_TRUE)
		{
			DRV_Reg(GPT2_CTRL) |= GPT_CTRL_AUTOMODE;
		}
		else
		{
			DRV_Reg(GPT2_CTRL) &= ~GPT_CTRL_AUTOMODE;
		}		
	}
}

#ifdef GPT_INTERNAL_SRAM
#pragma arm section code = "INTERNCODE"
#endif

/*
* FUNCTION                                                            
*	GPT_Stop
*
* DESCRIPTION                                                           
*   	Stop GPT timer
*
* CALLS  
*	It is called to stop GPT timer
*
* PARAMETERS
*	timerNum = 1(GPT1) or 2(GPT2)
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPT_Stop(kal_uint8 timerNum)
{
   kal_uint16 gpt_ctrl1;
   kal_uint16 gpt_ctrl2;
#if defined(DRV_GPT_GPT3)
   kal_uint16 gpt_ctrl3;
#endif   
   gpt_ctrl1 = DRV_Reg(GPT1_CTRL);
   gpt_ctrl2 = DRV_Reg(GPT2_CTRL);
#if defined(DRV_GPT_GPT3)
   gpt_ctrl3 = DRV_Reg(GPT3_CTRL);
#endif   
	if (timerNum == 1)
	{
	   gpt_ctrl1 &= ~GPT_CTRL_Enable;
		DRV_WriteReg(GPT1_CTRL,gpt_ctrl1);
	}
	if (timerNum == 2)
	{
	   gpt_ctrl2 &= ~GPT_CTRL_Enable;
		DRV_WriteReg(GPT2_CTRL,gpt_ctrl2);
	}
#if defined(DRV_GPT_GPT3)
   if (timerNum == 3)
	{
	   gpt_ctrl3 =(kal_uint16) ~GPT3_ENABLE;
		DRV_WriteReg(GPT3_CTRL,gpt_ctrl3);
	}
		
   if ( (((gpt_ctrl1|gpt_ctrl2)&GPT_CTRL_Enable)==0)&& (!(gpt_ctrl3&GPT3_ENABLE)))
#else
	if ( ((gpt_ctrl1|gpt_ctrl2)&GPT_CTRL_Enable)==0  )
#endif	   
   {
	   kal_uint16 GPT_Status;

	   GPT_Status = DRV_Reg(GPT_STS);
      IRQMask(IRQ_GPT_CODE);
      IRQClearInt(IRQ_GPT_CODE);
   #ifdef GPT_DRVPDN_FAST
	   DRVPDN_ENABLE2(DRVPDN_CON1,DRVPDN_CON1_GPT,PDN_GPT);	   
   #else
	   DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_GPT,PDN_GPT);	  
   #endif
   }
}

/*
* FUNCTION                                                            
*	GPT_Start
*
* DESCRIPTION                                                           
*   	Start GPT timer
*
* CALLS  
*	It is called to start GPT timer
*
* PARAMETERS
*	timerNum = 1(GPT1) or 2(GPT2)
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPT_Start(kal_uint8 timerNum)
{
	if (timerNum == 1)
	{
		DRV_Reg(GPT1_CTRL) |= GPT_CTRL_Enable;
	}
	if (timerNum == 2)
	{
		DRV_Reg(GPT2_CTRL) |= GPT_CTRL_Enable;
	}
#if defined(DRV_GPT_GPT3)
   if (timerNum == 3)
	{
		DRV_Reg(GPT3_CTRL) |= GPT3_ENABLE;
	}
#endif	
   #ifdef GPT_DRVPDN_FAST
      DRVPDN_DISABLE2(DRVPDN_CON1,DRVPDN_CON1_GPT,PDN_GPT);
   #else
		DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_GPT,PDN_GPT);
   #endif
   IRQUnmask(IRQ_GPT_CODE);
}
#ifdef GPT_INTERNAL_SRAM
#pragma arm section code
#endif

/*
* FUNCTION                                                            
*	GPT_LISR
*
* DESCRIPTION                                                           
*   	GPT interrupt handler
*
* CALLS  
*	It is called when GPT interrupt is coming
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPT_LISR(void)
{
	kal_uint16 GPT_Status;

   IRQMask(IRQ_GPT_CODE);
	GPT_Status = DRV_Reg(GPT_STS);
	
	if (GPT_Status & GPT_STS_1)
	{
		GPTTimer.GPT_FUNC.gpt1_func();
	}
	if (GPT_Status & GPT_STS_2)
	{
		GPTTimer.GPT_FUNC.gpt2_func();
	}
   IRQClearInt(IRQ_GPT_CODE);
   IRQUnmask(IRQ_GPT_CODE);
}

/*
* FUNCTION                                                            
*	GPT_init
*
* DESCRIPTION                                                           
*   	GPT initial function
*
* CALLS  
*	Initialize the GPT module
*
* PARAMETERS
*	timerNum = 1(GPT1) or 2(GPT2)
*	GPT_Callback = callback function, called when GPT intr. is coming
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPT_init(kal_uint8 timerNum, void (*GPT_Callback)(void))
{
   IRQ_Register_LISR(IRQ_GPT_CODE, GPT_LISR,"GPT handler");
   
	if (timerNum == 1)
	{
		GPTTimer.GPT_FUNC.gpt1_func = GPT_Callback;
		GPT_clock(1,clk_1k);
		
		IRQSensitivity(IRQ_GPT_CODE,LEVEL_SENSITIVE);
		IRQUnmask(IRQ_GPT_CODE);
	}
	if (timerNum == 2)
	{
		GPTTimer.GPT_FUNC.gpt2_func = GPT_Callback;
		GPT_clock(2,clk_16k);
		
		IRQSensitivity(IRQ_GPT_CODE,LEVEL_SENSITIVE);
		IRQUnmask(IRQ_GPT_CODE);
	}
}

/*
* FUNCTION                                                            
*	GPTI_GetHandle
*
* DESCRIPTION                                                           
*   	GPT handle function, each module should get handle once(only one).
*
* CALLS  
*	   
*
* PARAMETERS
*	*handle = handle value
*
* RETURNS
*	KAL_TRUE, Action is ok.
*  KAL_FALSE, Action is failed.
*
* GLOBALS AFFECTED
*   external_global
*/
/*actual value = 0~31*/
kal_uint8 GPTI_GetHandle(kal_uint8 *handle)
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   *handle = GPTTimer.MAX_GPTIMER_ITEMS;
   GPTTimer.MAX_GPTIMER_ITEMS++;
   RestoreIRQMask(savedMask);
   if (GPTTimer.MAX_GPTIMER_ITEMS <= 32)
      return KAL_TRUE;
   else
   {
      GPTTimer.MAX_GPTIMER_ITEMS = 32;
      ASSERT(0);
      return KAL_FALSE;
   }
}

#ifdef GPT_INTERNAL_SRAM
#pragma arm section code = "INTERNCODE"
#endif

/*
* FUNCTION                                                            
*	GPTI_StartItem
*
* DESCRIPTION                                                           
*   	GPT start a item.
*
* CALLS  
*
* PARAMETERS
*	moudle = UART_Module, SIM_Module, GPT_Module
*	tick = the delay(the unit is 10ms)
*  gptimer_func = the callback function when the tick is reached.
*  parameter = the parameter inputed into gptimer_func
*
* RETURNS
*	KAL_TRUE, start item successfully
*  KAL_FALSE, start item fail
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
   kal_uint32 savedMask;
   if (GPTTimer.status & (1<<module))
   {
      return KAL_FALSE;
   }
   
   GPTTimer.GPTItems[module].tick = GPTTimer.GPT_TICK+tick;
   GPTTimer.GPTItems[module].gptimer_func = gptimer_func;
   GPTTimer.GPTItems[module].parameter = parameter;
   savedMask = SaveAndSetIRQMask();
   //if (tick == 0)
   //   tick =1;

   GPTTimer.status |= (1<<module);
   if(GPTTimer.GPTSTOP == KAL_TRUE)
   {
      GPTTimer.GPTSTOP = KAL_FALSE;
      RestoreIRQMask(savedMask);
      savedMask = SaveAndSetIRQMask();
      if (((volatile kal_bool)GPTTimer.GPTSTOP) == KAL_FALSE)
         GPT_Start(gptimer_num);
   }
   
   RestoreIRQMask(savedMask);
   return KAL_TRUE;
}

/*
* FUNCTION                                                            
*	GPTI_StopItem
*
* DESCRIPTION                                                           
*   	GPT stop a item.
*
* CALLS  
*
* PARAMETERS
*	moudle = UART_Module, SIM_Module, GPT_Module
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPTI_StopItem(kal_uint8 module)
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   GPTTimer.status &= ~(1<<module);
   if (GPTTimer.status == 0)
   {
      GPTTimer.GPTSTOP = KAL_TRUE;
      GPTTimer.GPT_TICK = 0;
      RestoreIRQMask(savedMask);
      savedMask = SaveAndSetIRQMask();
      if (((volatile kal_bool)GPTTimer.GPTSTOP) == KAL_TRUE)
         GPT_Stop(gptimer_num);
   }
   RestoreIRQMask(savedMask);
}
#ifdef GPT_INTERNAL_SRAM
#pragma arm section code
#endif

/*
* FUNCTION                                                            
*	GPTI_HISR
*
* DESCRIPTION                                                           
*   	GPTI HISR
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPTI_HISR(void)
{
   kal_uint8 index;
   
   for (index = 0;index < GPTTimer.MAX_GPTIMER_ITEMS;index++)
   {
      GPTProcess(index);
   }
   
   GPTTimer.GPT_TICK++;
   
   if (GPTTimer.status == 0)
   {
      GPTTimer.GPTSTOP = KAL_TRUE;
      GPTTimer.GPT_TICK = 0;
      GPT_Stop(gptimer_num);
   }
}

/*
* FUNCTION                                                            
*	GPTI_Callback
*
* DESCRIPTION                                                           
*   	GPT1 LISR
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPTI_Callback(void)
{
   //kal_activate_hisr(GPTTimer.hisr);
     drv_active_hisr(DRV_GPT_HISR_ID);
}

/*
* FUNCTION                                                            
*	GPTI_init
*
* DESCRIPTION                                                           
*   	Initialize the GPTI module with GPT
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPTI_init(void)
{
   if (GPTTimer.hisr == NULL)
   {
      //GPTTimer.hisr = kal_create_hisr("GPTIMER",2,512,GPTI_HISR,NULL);
      GPTTimer.hisr= (void*)0x1234;
      DRV_Register_HISR(DRV_GPT_HISR_ID, GPTI_HISR);
   }   
   GPT_init(gptimer_num,GPTI_Callback);
   GPT_ResetTimer(gptimer_num,gptimer_interval-1,KAL_TRUE);
   GPTTimer.GPT_TICK = 0;
   GPTTimer.MAX_GPTIMER_ITEMS = 0;
   GPTTimer.GPTSTOP = KAL_TRUE;
   GPTTimer.status =0;
}

/*
* FUNCTION                                                            
*	GPTI_BusyWait
*
* DESCRIPTION                                                           
*   	Use GPT2 as a counter to perform a busy waiting
*
* CALLS
*
* PARAMETERS
*	len: length of the counter in unit of 1ms
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   
*/
void GPTI_BusyWait(kal_uint16 len)
{
	// disable PDN
   #if defined(DRV_MISC_PDN_NO_SET_CLR)
		DRV_Reg(DRVPDN_CON1) &= ~DRVPDN_CON1_GPT;
	#else
		DRV_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_GPT);
	#endif
	
	DRV_WriteReg(GPT2_LEN, len);
	DRV_WriteReg(GPT2_PRESCALER, clk_1k); // 1K HZ
	// one shot
	DRV_WriteReg(GPT2_CTRL, GPT_CTRL_Enable);
	while(!(DRV_Reg(GPT_STS) & GPT_STS_2));
	
	// set PDN
   #if defined(DRV_MISC_PDN_NO_SET_CLR)
		DRV_Reg(DRVPDN_CON1) |= DRVPDN_CON1_GPT;
	#else
		DRV_WriteReg(DRVPDN_CON1_SET, DRVPDN_CON1_GPT);
	#endif	
	
	
	
}

#if defined(DRV_GPT_GPT3)
void GPT3_Init(void)
{
   DRV_WriteReg(GPT3_PRESCALER,GPT_PRESCALER_div32);  
}   

kal_uint16 GPT_return_current_count(void)
{
   kal_uint16 current_count;
   current_count=DRV_Reg(GPT3_LEN);
   return current_count;      
}   
#endif


