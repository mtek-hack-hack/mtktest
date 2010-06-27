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
 *    gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the GPIO driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"

#if !defined(__FUE__)
   #define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
   #define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
   #define SAVEANDSETIRQMASK()      0
   #define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/

#ifdef __CUST_NEW__
extern const kal_uint32  gpio_mode_allowed[][4];
extern const kal_uint32  gpio_dir_out_allowed[];
extern const kal_uint32  gpio_dir_in_allowed[];
extern const kal_uint16  gpo_mode_allowed[];
extern kal_bool   gpio_debug_enable;
#endif /* __CUST_NEW__ */

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;

      modeno = pin/8;
      remainder = pin % 8;
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);
   }
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
      kal_uint16 mode; 
      kal_uint32 savedMask;
      
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_Reg(GPI_O_MODE);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_WriteReg(GPI_O_MODE,mode);
      RESTOREIRQMASK(savedMask);
   }
#endif   /*DRV_GPIO_6208_FUNC, FPGA*/

#if defined(DRV_GPIO_6205_FUNC)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint32 savedMask;
      
      modeno = pin/8;
      remainder = pin % 8;
      
      savedMask = SAVEANDSETIRQMASK();
      *(GPIO_MODE(modeno)) &= ~(0x0003 << (remainder*2));
      *(GPIO_MODE(modeno)) |= (conf_dada << (remainder*2));
      RESTOREIRQMASK(savedMask);
   }
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
      kal_uint16 mode; 
      kal_uint32 savedMask;
      
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_Reg(GPIO_MODE4);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_WriteReg(GPIO_MODE4,mode);
      RESTOREIRQMASK(savedMask);
   }
#endif   /*DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;
      
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);

      //DRV_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
   }
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
      kal_uint16 mode; 
      kal_uint32 savedMask;

      #ifdef __CUST_NEW__   	
      pin &= (~GPO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
         ASSERT((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f)));
      }
      #endif /* __CUST_NEW__ */
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_Reg(GPIO_MODE4);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_WriteReg(GPIO_MODE4,mode);
      RESTOREIRQMASK(savedMask);

      //DRV_WriteReg(GPIO_MODE4_CLR,(0x0003 << (pin*2)));
      //DRV_WriteReg(GPIO_MODE4_SET,(conf_dada << (pin*2)));
   }
#endif   /*DRV_GPIO_6205B_FUNC*/


#if defined(DRV_GPIO_FULL_FUNC)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;

      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      #if defined(DRV_GPIO_MODE8_SPECIAL_POS)
      if(pin>=56)/*special case  */
      {
         kal_uint16 mode; 

         savedMask = SAVEANDSETIRQMASK();
         mode = DRV_Reg(GPIO_MODE8);
         mode &= ~(0x0003 << (remainder*2));
         mode |= (conf_dada << (remainder*2));
         DRV_WriteReg(GPIO_MODE8,mode);
         RESTOREIRQMASK(savedMask);
         //DRV_WriteReg(GPIO_MODE8_CLR,(0x0003 << (remainder*2)));
         //DRV_WriteReg(GPIO_MODE8_SET,(conf_dada << (remainder*2)));
         return;
      }
      #endif                  
      
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
#ifdef DRV_GPIO_REG_AS_6223
      if ((modeno == 5) && (pin != 44))
         data ^= 0x0100; //mode44 LSB: set and clear are inversed in MT6223.
      else if ((modeno == 6) && (pin != 50))
         data ^= 0x0010; //mode50 LSB: set and clear are inversed in MT6223.
#endif
      DRV_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);

      //DRV_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
   }
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
   #if !defined(DRV_GPIO_WO_GPO)
      kal_uint16 mode; 
      kal_uint32 savedMask;

      #ifdef __CUST_NEW__   	
      pin &= (~GPO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
         ASSERT((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f)));
      }
      #endif /* __CUST_NEW__ */
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_Reg(GPO_MODE);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_WriteReg(GPO_MODE,mode);
      RESTOREIRQMASK(savedMask);

      //DRV_WriteReg(GPO_MODE_CLR,(0x0003 << (pin*2)));
      //DRV_WriteReg(GPO_MODE_SET,(conf_dada << (pin*2)));
   #endif /* !defined(DRV_GPIO_WO_GPO) */
   }
/*
* FUNCTION                                                            
*	GPIO_PullenSetup
*
* DESCRIPTION                                                           
*   	This function is to enable or disable the pull up/down of the related GPIO pin.
*		You can not decide to pull up or down, it is set inside the chip.
*		And, the setting is different from pin by pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the pull up/down
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
   void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable)
   {
      kal_uint16 modeno;
      kal_uint16 remainder;
      
      #ifdef __CUST_NEW__   	
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
      modeno = pin/16;
      remainder = pin % 16;

		if(enable)
      	DRV_WriteReg(GPIO_PULLEN_SET(modeno), 1 << remainder);
      else
      	DRV_WriteReg(GPIO_PULLEN_CLR(modeno), 1 << remainder);
   }
/*
* FUNCTION                                                            
*	GPIO_DinvSetup
*
* DESCRIPTION                                                           
*   	This function is to enable data invert of the related GPIO pin
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the data inversion
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
   void GPIO_DinvSetup(kal_uint16 pin, kal_bool enable)
   {
      kal_uint16 modeno;
      kal_uint16 remainder;
      
      #ifdef __CUST_NEW__   	
      //ASSERT(pin&GPIO_MAGIC_NUM);
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
      modeno = pin/16;
      remainder = pin % 16;

		if(enable)
      	DRV_Reg(GPIO_DINV_ADRS(modeno)) |= (1 << remainder);
      else
      	DRV_Reg(GPIO_DINV_ADRS(modeno)) &= ~(1 << remainder);
   }
   
#endif   /*DRV_GPIO_FULL_FUNC*/

/*
* FUNCTION                                                            
*	GPIO_PullSelSetup
*
* DESCRIPTION                                                           
*   	This function is to select pull up/down of the related GPIO pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the pull up/down
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up)
{
#if defined(DRV_GPIO_PULL_SEL)
   kal_uint16 modeno;
   kal_uint16 remainder;
   
   #ifdef __CUST_NEW__   	
   pin &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   modeno = pin/16;
   remainder = pin % 16;

	if(pull_up)
      DRV_WriteReg(GPIO_PULLSEL_SET(modeno), 1 << remainder);
   else
      DRV_WriteReg(GPIO_PULLSEL_CLR(modeno), 1 << remainder);
#endif /*defined(DRV_GPIO_PULL_SEL)*/
}


/*
* FUNCTION                                                            
*	GPIO_InitIO
*
* DESCRIPTION                                                           
*   	This function is to initialize one GPIO pin as INPUT or OUTPUT
*
* CALLS  
*	Initialize one GPIO pin as INPUT or OUTPUT
*
* PARAMETERS
*	direction: INPUT or OUTPUT
*	port: pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_InitIO(char direction, char port)
{
#if defined(DRV_GPIO_6205_FUNC)
   if (direction == OUTPUT)
	{
	   if (port < 16)
		   DRV_Reg(GPIO_DIR) |= (1 << port);
      else
         DRV_Reg(GPIO_DIR2) |= (1 << (port-16));
	}
	else
	{
	   if (port < 16)
		   DRV_Reg(GPIO_DIR) &= ~(1 << port);
		else
		   DRV_Reg(GPIO_DIR2) &= ~(1 << (port-16));
	}
#endif /*DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPIO_MAGIC_NUM);
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
         ASSERT((gpio_dir_in_allowed[port>>5]) & (1 << (port & 0x1f)));
      }
      else
      {
         ASSERT((gpio_dir_out_allowed[port>>5]) & (1 << (port & 0x1f)));
      }
   }
   #endif /* __CUST_NEW__ */
   if (direction == OUTPUT)
	{
	   if (port < 16)
	      DRV_WriteReg(GPIO_DIR_SET,(1 << port));
      else
         DRV_WriteReg(GPIO_DIR2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
		   DRV_WriteReg(GPIO_DIR_CLR,(1 << port));
		else
		   DRV_WriteReg(GPIO_DIR2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPIO_MAGIC_NUM);
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
         ASSERT((gpio_dir_in_allowed[port>>5]) & (1 << (port & 0x1f)));
      }
      else
      {
         ASSERT((gpio_dir_out_allowed[port>>5]) & (1 << (port & 0x1f)));
      }
   }
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (direction == OUTPUT)
      DRV_WriteReg(GPIO_DIR_SET(no),(1 << remainder));
	else
      DRV_WriteReg(GPIO_DIR_CLR(no),(1 << remainder));
#endif   /*DRV_GPIO_FULL_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (direction == OUTPUT)
	{
		DRV_Reg(GPIO_DIR) |= (1 << port);
	}
	else
	{
		DRV_Reg(GPIO_DIR) &= ~(1 << port);
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
}

/*
* FUNCTION                                                            
*	GPIO_ReadIO
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPIO pin
*
* CALLS  
*	Read data from one GPIO pin
*
* PARAMETERS
*	port: pin number
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReadIO(char port)
{
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPIO_MAGIC_NUM);
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
   }
   #endif /* __CUST_NEW__ */
   if (port < 16)
	   return((DRV_Reg(GPIO_DIN) >> port) & 1);
	else
	   return((DRV_Reg(GPIO_DIN2) >> (port-16)) & 1);
#endif /*DRV_GPIO_6205_FUNC, DRV_GPIO_6205B_FUNC*/
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   return((DRV_Reg(GPIO_DIN) >> port) & 1);
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
#if defined(DRV_GPIO_FULL_FUNC)
#if defined(DRV_GPIO_DIN_DISCONT)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPIO_MAGIC_NUM);
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
   }
   #endif /* __CUST_NEW__ */
   if (port < 16)
	   return((DRV_Reg(GPIO_DIN1) >> port) & 1);
	else if (port < 32)
	   return((DRV_Reg(GPIO_DIN2) >> (port-16)) & 1);
	else if (port < 48)
	   return((DRV_Reg(GPIO_DIN3) >> (port-32)) & 1);
	#if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6225)
	else if (port < 54)
	   return((DRV_Reg(GPIO_DIN4) >> (port-48)) & 1);
	#endif
   else
   {
      ASSERT(0);
      return 0;
   }
#endif /* DRV_GPIO_DIN_DISCONT*/
#if defined(DRV_GPIO_DIN_CONTI)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPIO_MAGIC_NUM);
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
   #if defined(DRV_GPIO_REG_AS_MT6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
         ASSERT(GPIO_ReturnMode(port) == 1);
      }
      else
   #endif /* DRV_GPIO_REG_AS_MT6228 */
      {
         ASSERT(GPIO_ReturnMode(port) == 0);
      }
      ASSERT(GPIO_ReturnDir(port) == 0);
   }
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
         		
   data=DRV_Reg(GPIO_DIN(no));   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (kal_uint8)data;
   
#endif   /*DRV_GPIO_DIN_CONTI*/
#else /* DRV_GPIO_FULL_FUNC */
   return 0;
#endif /* DRV_GPIO_FULL_FUNC */
}


/*
* FUNCTION                                                            
*	GPIO_WriteIO
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpio pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/

#ifdef __BT_RDA5868__	
#include "..\..\custom\drv\bt_rda5868\rda5868.h"
kal_uint8 rda5868_init_flag;
#endif
void GPIO_WriteIO(char data, char port)
{
#if defined(DRV_GPIO_6205_FUNC)

	#error "111111111111111111111"
	if (data == 1)
	{
	   if (port < 16)
		   DRV_Reg(GPIO_DOUT) |= (1 << port);
		else
		   DRV_Reg(GPIO_DOUT2) |= (1 << (port-16));
	}
	else
	{
	   if (port < 16)
		   DRV_Reg(GPIO_DOUT) &= ~(1 << port);
		else
		   DRV_Reg(GPIO_DOUT2) &= ~(1 << (port-16));
	}
#endif /*(DRV_GPIO_6205_FUNC)*/

#if defined(DRV_GPIO_6205B_FUNC)
   #error "22222222222222222222222"
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPIO_MAGIC_NUM);
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 1);
   }
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   if (port < 16)
	      DRV_WriteReg(GPIO_DOUT_SET,(1 << port));
		else
		   DRV_WriteReg(GPIO_DOUT2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
	      DRV_WriteReg(GPIO_DOUT_CLR,(1 << port));
		else
		   DRV_WriteReg(GPIO_DOUT2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	#error "333333333333333333333333"
	if (data == 1)
	{
		DRV_Reg(GPIO_DOUT) |= (1 << port);
	}
	else
	{
		DRV_Reg(GPIO_DOUT) &= ~(1 << port);
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/

#if defined(DRV_GPIO_FULL_FUNC)
   //Huyanwei Touch Here
   kal_uint16 no;
   kal_uint16 remainder;

   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPIO_MAGIC_NUM);
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
   #if defined(DRV_GPIO_REG_AS_MT6228)
   #error "5555555555555555555555"
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
         ASSERT(GPIO_ReturnMode(port) == 1);
      }
      else
   #endif /*DRV_GPIO_REG_AS_MT6228*/
      {
         ASSERT(GPIO_ReturnMode(port) == 0);
      }
      ASSERT(GPIO_ReturnDir(port) == 1);
   }
   #endif /* __CUST_NEW__ */
   #ifdef __BT_RDA5868__	
   if(((port == RDA5868_POWER_EN) || (port== RDA5868_RESET) )&& (rda5868_init_flag == 1)){
   	return;
   }
   #endif   
   no = port/16;
   remainder = port % 16;
   if (data == 1)
      DRV_WriteReg(GPIO_DOUT_SET(no),(1 << remainder));
	else
      DRV_WriteReg(GPIO_DOUT_CLR(no),(1 << remainder));
#endif   /*DRV_GPIO_FULL_FUNC*/
}

/*
* FUNCTION                                                            
*	GPI_O_ReadIO
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPI pin
*
* CALLS  
*	Read data from one GPI pin
*
* PARAMETERS
*	None
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
char GPI_ReadIO(void)
{
	return((DRV_Reg(GPI_O_DIO) >> 15) & 1);
}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
/*
* FUNCTION                                                            
*	GPI_O_WriteIO
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPO pin
*
* CALLS  
*	Write data to one GPO pin
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpo pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

void GPO_WriteIO(char data,char port)
{
#if !defined(DRV_GPIO_WO_GPO)
#if defined(DRV_GPIO_6205_FUNC)
	if (data == 1)
	{
		DRV_Reg(GPO_DOUT) |= (1 << port);
	}
	else
	{
		DRV_Reg(GPO_DOUT) &= ~(1 << port);
	}
#endif   /*(DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPO_MAGIC_NUM);
   }

   port &= (~GPO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(GPO_ReturnMode(port)== 0);
   }
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   DRV_WriteReg(GPO_DOUT_SET,(1 << port));
	}
	else
	{
	   DRV_WriteReg(GPO_DOUT_CLR,(1 << port));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(port & GPO_MAGIC_NUM);
   }
   port &= (~GPO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(GPO_ReturnMode(port)== 0);
   }
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   DRV_WriteReg(GPO_DOUT_SET,(1 << port));
	}
	else
	{
	   DRV_WriteReg(GPO_DOUT_CLR,(1 << port));
	}
#endif   /*DRV_GPIO_FULL_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (data == 1)
	{
		DRV_Reg(GPI_O_DIO) |= (1 << port);
	}
	else
	{
		DRV_Reg(GPI_O_DIO) &= ~(1 << port);
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
#endif /*!defined(DRV_GPIO_WO_GPO)*/
}

/*
* FUNCTION                                                            
*	GPO_WriteAll
*
* DESCRIPTION                                                           
*   	This function is to write data to all GPO pins
*
* CALLS  
*	Write data to all GPO pins
*
* PARAMETERS
*	write_data: expected GPO data to all pins
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPO_WriteAll(kal_uint16 write_data)
{
#if !defined(DRV_GPIO_WO_GPO)
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   DRV_WriteReg(GPO_DOUT,write_data);
#endif   /*(DRV_GPIO_6205_FUNC,DRV_GPIO_6205B_FUNC)*/
#if defined(DRV_GPIO_FULL_FUNC)
   DRV_WriteReg(GPO_DOUT,write_data);
#endif   /*DRV_GPIO_FULL_FUNC*/
#if ( (defined(DRV_GPIO_6208_FUNC)) || (defined(FPGA)) )
   DRV_WriteReg(GPI_O_DIO,write_data);
#endif   /*(MT6208,FPGA)*/
#endif /*!defined(DRV_GPIO_WO_GPO)*/
}

/*
* FUNCTION                                                            
*	GPIO_ReturnDout
*
* DESCRIPTION                                                           
*   	This function is to report GPIO output value
*
* CALLS  
*	Report GPIO output value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO output value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnDout(char port)
{
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __CUST_NEW__
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;

#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   if(0==no)
      data=DRV_Reg(GPIO_DOUT); 
   else if(1==no)
      data=DRV_Reg(GPIO_DOUT2); 
#endif

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_Reg(GPIO_DOUT); 	
#endif

#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_Reg(GPIO_DOUT(no)); 
#endif   
   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (kal_uint8)data;
}
/*
* FUNCTION                                                            
*	GPO_ReturnDout
*
* DESCRIPTION                                                           
*   	This function is to report GPO output value
*
* CALLS  
*	Report GPO output value accoding to input pin
*
* PARAMETERS
*	GPO pin 
*	
* RETURNS
*	GPO output value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPO_ReturnDout(char port)
{
#if !defined(DRV_GPIO_WO_GPO)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __CUST_NEW__
   port &= (~GPO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;


#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_Reg(GPI_O_DIO); 	
#endif

#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)||defined(DRV_GPIO_FULL_FUNC)
   data=DRV_Reg(GPO_DOUT); 
#endif   

   data=data&(1 << remainder);
   data=(data >> remainder);
   return (kal_uint8)data;
#else /* !defined(DRV_GPIO_WO_GPO) */   
   return 0;
#endif /* !defined(DRV_GPIO_WO_GPO) */   
}
/*
* FUNCTION                                                            
*	GPIO_ReturnDir
*
* DESCRIPTION                                                           
*   	This function is to report GPIO direction value
*
* CALLS  
*	Report GPIO direction value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO direction value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnDir(char port)
{
	
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __CUST_NEW__
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   if(0==no)
      data=DRV_Reg(GPIO_DIR); 
   else if(1==no)
      data=DRV_Reg(GPIO_DIR2); 
#endif
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_Reg(GPIO_DIR); 	
#endif
#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_Reg(GPIO_DIR(no)); 
#endif   
   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (kal_uint8)data;

}
/*
* FUNCTION                                                            
*	GPIO_ReturnMode
*
* DESCRIPTION                                                           
*   	This function is to report GPIO mode value
*
* CALLS  
*	Report GPIO mode value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO mode value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnMode(char port)
{
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/8;
   remainder = port % 8;
   
 
   data=DRV_Reg(GPIO_MODE(no)); 
   data=data&(0x3 << (2*remainder));
   data=(data >> (2*remainder));
   return (kal_uint8)data;
   
}

/*
* FUNCTION                                                            
*	GPO_ReturnMode
*
* DESCRIPTION                                                           
*   	This function is to report GPO mode value
*
* CALLS  
*	Report GPO mode value accoding to input pin
*
* PARAMETERS
*	GPO pin 
*	
* RETURNS
*	GPO mode value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPO_ReturnMode(char port)
{
#if !defined(DRV_GPIO_WO_GPO)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/8;
   remainder = port % 8;

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
    data=DRV_Reg(GPIO_MODE2); 
#endif      
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
    data=DRV_Reg(GPIO_MODE4); 
#endif   
#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_Reg(GPO_MODE); 
#endif   
   data=data&(0x3 << (2*remainder));
   data=(data >> (2*remainder));
   return (kal_uint8)data;
#else /* !defined(DRV_GPIO_WO_GPO) */   
   return 0;
#endif /* !defined(DRV_GPIO_WO_GPO) */   
}   

void GPIO_SetDebugMode(kal_bool enable)
{
#if defined(DRV_GPIO_DEBUG_MODE)
   if (enable == KAL_TRUE)
   {
      DRV_WriteReg(GPIO_BANK,0);
   }
   else
   {
      DRV_WriteReg(GPIO_BANK,1);
   }
#endif /* DRV_GPIO_DEBUG_MODE */
}

/* clk_num = 0~5*/
/* When clk_num is 0, it represents CLK ouput 1. */
void GPIO_SetClkOut(char clk_num, gpio_clk_mode mode)
{
#if defined(DRV_GPIO_CLK_OUT)
   if ((clk_num >= CLKO_NUM) || (mode >= mode_max_num))
      return;
   DRV_WriteReg(CLKO_MODE(clk_num), mode);
#endif /* DRV_GPIO_CLK_OUT */
}

void GPIO_TMDir(kal_bool pad_oe)
{
#if defined(DRV_GPIO_TM_DIR)
   if (pad_oe == KAL_TRUE)
      DRV_WriteReg(GPIO_TM,1);
   else
      DRV_WriteReg(GPIO_TM,0);
#endif /* DRV_GPIO_CLK_OUT */
}


#ifdef __CUST_NEW__

void GPIO_InitIO_FAST(char direction, char port)
{
#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
         ASSERT((gpio_dir_in_allowed[port>>5]) & (1 << (port & 0x1f)));
      }
      else
      {
         ASSERT((gpio_dir_out_allowed[port>>5]) & (1 << (port & 0x1f)));
      }
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   if (direction == OUTPUT)
	{
	   if (port < 16)
	      DRV_WriteReg(GPIO_DIR_SET,(1 << port));
      else
         DRV_WriteReg(GPIO_DIR2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
		   DRV_WriteReg(GPIO_DIR_CLR,(1 << port));
		else
		   DRV_WriteReg(GPIO_DIR2_CLR,(1 << (port-16)));
	}
#endif   /*(DRV_GPIO_6205B_FUNC)*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
         ASSERT((gpio_dir_in_allowed[port>>5]) & (1 << (port & 0x1f)));
      }
      else
      {
         ASSERT((gpio_dir_out_allowed[port>>5]) & (1 << (port & 0x1f)));
      }
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   no = port/16;
   remainder = port % 16;
   if (direction == OUTPUT)
      DRV_WriteReg(GPIO_DIR_SET(no),(1 << remainder));
	else
      DRV_WriteReg(GPIO_DIR_CLR(no),(1 << remainder));
#endif   /*MT6218, MT6218B, MT6219, MT6217, MT6228, MT6229*/

}

char GPIO_ReadIO_FAST(char port)
{
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   if (port < 16)
	   return((DRV_Reg(GPIO_DIN) >> port) & 1);
	else
	   return((DRV_Reg(GPIO_DIN2) >> (port-16)) & 1);
#endif /*(DRV_GPIO_6205_FUNC,DRV_GPIO_6205B_FUNC)*/
#if defined(DRV_GPIO_FULL_FUNC)
#if defined(DRV_GPIO_DIN_DISCONT)
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   if (port < 16)
	   return((DRV_Reg(GPIO_DIN1) >> port) & 1);
	else if (port < 32)
	   return((DRV_Reg(GPIO_DIN2) >> (port-16)) & 1);
	else if (port < 48)
	   return((DRV_Reg(GPIO_DIN3) >> (port-32)) & 1);
	#if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6225)
	else if (port < 54)
	   return((DRV_Reg(GPIO_DIN4) >> (port-48)) & 1);
	#endif
   else
   {
      ASSERT(0);
      return 0;
   }
#endif
#if defined(DRV_GPIO_DIN_CONTI)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
   #if defined(DRV_GPIO_REG_AS_MT6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
         ASSERT(GPIO_ReturnMode(port) == 1);
      }
      else
   #endif /* (defined(MT6228))*/
      {
         ASSERT(GPIO_ReturnMode(port) == 0);
      }
      ASSERT(GPIO_ReturnDir(port) == 0);
   }
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __GPIO_FAST_DEBUB__ */
   no = port/16;
   remainder = port % 16;
         		
   data=DRV_Reg(GPIO_DIN(no));   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (kal_uint8)data;
   
#endif   /*DRV_GPIO_DIN_CONTI*/
#else /* DRV_GPIO_FULL_FUNC */
   return 0;
#endif /* DRV_GPIO_FULL_FUNC */
}

void GPIO_WriteIO_FAST(char data, char port)
{
#ifdef DRV_GPIO_6205B_FUNC
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 1);
   }
   #endif /* __GPIO_FAST_DEBUB__ */
	if (data == 1)
	{
	   if (port < 16)
	      DRV_WriteReg(GPIO_DOUT_SET,(1 << port));
		else
		   DRV_WriteReg(GPIO_DOUT2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
	      DRV_WriteReg(GPIO_DOUT_CLR,(1 << port));
		else
		   DRV_WriteReg(GPIO_DOUT2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
   #if defined(DRV_GPIO_REG_AS_MT6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
         ASSERT(GPIO_ReturnMode(port) == 1);
      }
      else
   #endif /*DRV_GPIO_REG_AS_MT6228*/
      {
         ASSERT(GPIO_ReturnMode(port) == 0);
      }
      ASSERT(GPIO_ReturnDir(port) == 1);
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   no = port/16;
   remainder = port % 16;
   if (data == 1)
      DRV_WriteReg(GPIO_DOUT_SET(no),(1 << remainder));
	else
      DRV_WriteReg(GPIO_DOUT_CLR(no),(1 << remainder));
#endif   /*MT6218, MT6218B, MT6219, MT6217, MT6228, MT6229*/
}

#endif /* __CUST_NEW__ */

