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
 *    wdt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the WDT driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "wdt_hw.h"
#include "wdt_sw.h"
#include "adc.h"
#include "bmt.h"
#include "keypad_hw.h"
#include  "keypad_sw.h"

kal_bool  WDT_RST;
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
kal_uint8  TargetReset = 0;
extern BMTStruct BMT;
#endif


/*
* FUNCTION                                                            
*	WDT_SetValue
*
* DESCRIPTION                                                           
*   	This function is to set WDT count value
*
* CALLS  
*
* PARAMETERS
*	value: WDT count value
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_SetValue(kal_uint16 value)
{
	kal_uint16 tmp = (kal_uint16)value;
#if defined(DRV_WDT_LENGTH_11BITS)
   ASSERT(tmp <= 0x7ff);
   tmp = tmp << 5;
#else
   ASSERT(tmp <= 0xff);
	tmp = tmp << 8;
#endif
	DRV_WriteReg(WDT_LENGTH,(tmp | WDT_LENGTH_KEY));
}

/*
* FUNCTION                                                            
*	WDT_Enable
*
* DESCRIPTION                                                           
*   	This function is to enable WDT timer
*
* CALLS  
*
* PARAMETERS
*	en: KAL_TRUE, enable WDT
*	    FASLE, disable WDT
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_Enable(kal_bool en)
{
	kal_uint16 tmp = DRV_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (en == KAL_TRUE)
	{
		tmp |= WDT_MODE_ENABLE;
	}
	else
	{
		tmp &= ~WDT_MODE_ENABLE;
	}
	DRV_WriteReg(WDT_MODE,tmp);
}

/*
* FUNCTION                                                            
*	WDT_Enable
*
* DESCRIPTION                                                           
*   	This function is to set ploarity of external pin
*
* CALLS  
*
* PARAMETERS
*	extpol: KAL_TRUE, polarity = 1
*	        FASLE, polarity = 0
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_SetExtpol(IO_level extpol)
{
	kal_uint16 tmp = DRV_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (extpol == io_high)
	{
		tmp |= WDT_MODE_EXTPOL;
	}
	else
	{
		tmp &= ~WDT_MODE_EXTPOL;
	}
	DRV_WriteReg(WDT_MODE,tmp);
}

/*
* FUNCTION                                                            
*	WDT_SetExten
*
* DESCRIPTION                                                           
*   	This function is to generate an external watchdog reset signal
*
* CALLS  
*
* PARAMETERS
*	en: KAL_TRUE, generate an external watchdog reset signal when couter=0
*	    KAL_FALSE, not generate an external watchdog reset signal when couter=0
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_SetExten(kal_bool en)
{
	kal_uint16 tmp = DRV_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (en == KAL_TRUE)
	{
		tmp |= WDT_MODE_EXTEN;
	}
	else
	{
		tmp &= ~WDT_MODE_EXTEN;
	}
	DRV_WriteReg(WDT_MODE,tmp);
}

/*
* FUNCTION                                                            
*	WDT_Config
*
* DESCRIPTION                                                           
*   	This function is to configure WDT only called in WDT_init
*
* CALLS  
*
* PARAMETERS
*	extpol: KAL_TRUE, polarity = 1
*	        FASLE, polarity = 0
*	exten: KAL_TRUE, generate an external watchdog reset signal when couter=0
*	    KAL_FALSE, not generate an external watchdog reset signal when couter=0
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_Config(IO_level extpol, kal_bool exten)
{
	kal_uint16 tmp = DRV_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	tmp &= ~WDT_MODE_ENABLE;
	
	if (extpol == io_high)
	{
		tmp |= WDT_MODE_EXTPOL;
	}
	else
	{
		tmp &= ~WDT_MODE_EXTPOL;
	}
	
	if (exten == KAL_TRUE)
	{
		tmp |= WDT_MODE_EXTEN;
	}
	else
	{
		tmp &= ~WDT_MODE_EXTEN;
	}
	tmp |= WDT_MODE_KEY;
	DRV_WriteReg(WDT_MODE,tmp);
}

/*
* FUNCTION
*	WDT_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the WDT module
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
*   None
*/
void WDT_init(void)
{
   WDT_RST = (DRV_Reg(WDT_STATUS) & WDT_STATUS_BITMASK)?(KAL_TRUE):(KAL_FALSE);  
   WDT_SetValue(255);
   WDT_Config(io_low,KAL_TRUE);
   DRV_WriteReg(WDT_RSTINTERVAL,WDT_RSTINTERVAL_VALUE);
}

/*
* FUNCTION
*	   DRV_RESET
*
* DESCRIPTION                                                           
*   	This function is to reset our system
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
void DRV_RESET(void)
{
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
kal_uint16 powerkey_status;
   //#ifdef PMIC_PRESENT
   #if ( (defined(MT6318))|| (defined(MT6305)) )
      if (BMT.PWRon != CHRPWRON)
      {
            switch(Pwrkey_Position)
   {
       case low_key:
         powerkey_status= DRV_Reg(KP_LOW_KEY);
         break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif          
      case high_key:
         powerkey_status= DRV_Reg(KP_HI_KEY);
         break;
      default:
         ASSERT(0);
         break;     
   }      
         if(PowerKey_Pressed())     
         {
            TargetReset = 1;
         }
         else
         {
            SaveAndSetIRQMask();

            WDT_SetValue(1);
            WDT_Restart();
            WDT_Enable(KAL_TRUE);
            while(1);
         }
      }
      else
      {
         SaveAndSetIRQMask();
       
         WDT_SetValue(1);
         WDT_Restart();
         WDT_Enable(KAL_TRUE);
         while(1);
      }
   #else /*PMIC_PRESENT*/
      SaveAndSetIRQMask();

      WDT_SetValue(1);
      WDT_Restart();
      WDT_Enable(KAL_TRUE);
      while(1);
   #endif   /*PMIC_PRESENT*/
#else /*!DRV_WDT_RESET_PKEY_RELEASE*/
   
   	kal_uint16 REG_COMM2;
   	kal_uint16 index;   
   	
      SaveAndSetIRQMask();

      for(index=0;index<1000;index++);
      REG_COMM2 = DRV_Reg(DRV_COMM_REG2);
      REG_COMM2 |= DRV_COMM_REG2_NORMAL_RESET;
      DRV_WriteReg(DRV_COMM_REG2,REG_COMM2);    
   #if !defined(DRV_WDT_SWRST)
      WDT_SetValue(1);
      WDT_Restart();
      WDT_Enable(KAL_TRUE);
      while(1);
   #else
      *(volatile kal_uint16 *)0x80000108 = 0;
      DRV_WriteReg(WDT_SWRST,WDT_SWRST_KEY);
      while(1);
   #endif
#endif   /*!DRV_WDT_RESET_PKEY_RELEASE*/
}

void DRV_ABN_RESET(void)
{
   SaveAndSetIRQMask();
   #if defined(DRV_RTC_REG_COMM)
      DRV_Reg(DRV_COMM_REG2) &= ~DRV_COMM_REG2_NORMAL_RESET;
   #endif   /*DRV_RTC_REG_COMM*/
   #if defined(DRV_WDT_SWRST)
      *(volatile kal_uint16 *)0x80000108 = 0;
   #endif
   WDT_SetValue(1);
   WDT_Restart();
   WDT_Enable(KAL_TRUE);
   while(1);
}

void WDT_Restart2(void)
{
   DRV_WriteReg(WDT_RESTART,WDT_RESTART_KEY);
}

/*
* FUNCTION                                                            
*	WDT_CheckStat
*
* DESCRIPTION                                                           
*   	This function is to check whether reset is due to WDT
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE, Reset due to that WDT Timer time-out period is reached.
*	KAL_FALSE, Reset not due to WDT
*
* GLOBALS AFFECTED
*   external_global
*/
#ifdef DRV_WDT_6205_CHECK_STAT
kal_uint8 WDT_CheckStat(void)
{
   kal_uint8 status;
   status = DRV_Reg(WDT_STATUS);
   return status;
}
#endif   /*DRV_WDT_6205_CHECK_STAT*/

