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
 *    irda_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements irda customer support
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 #ifdef __IRDA_SUPPORT__
#include "drv_comm.h"
#include "gpio_sw.h"
#include "irda_sw.h"
/************************************************************
	device descriptor parameters
*************************************************************/
kal_uint8 device_info[17] = { 
/* hint bits set for COMM, OBEX, LAN, IRMC, TRAN-P 
*/
      0xb1,  /* set pnp, Modem, Fax and extension bit */ 
      0x25,  /* set IrOBEX hint bit and IrCOMM hint bit */ 
      0x00,  /* char set = 0 */
      //'W','C','P','1','C','S','I','I','I',' ', 0x00,  
      'M','e','d','i','a','T','e','k',' ','I','n','c',' ',0x00,  
};
/************************************************************
	customization functinos
*************************************************************/
kal_uint8 *irda_get_device_info(void) 
{
   return (device_info);
}
kal_uint16 irda_get_device_info_size(void) 
{
   return (sizeof(device_info));
}
/*The following are for SIR/MIR/FIR mode switch according to 
  different IRDA transceiver*/
#define IR_TRANSCEIVER_PDN 0x801a003c
//#define __IRDA_AGILENT_3220__
#undef __IRDA_AGILENT_3220__
#if defined(__IRDA_VISHAY_6102__)
   #ifdef __CUST_NEW__
      extern const char gpio_irda_mode_switch_pin;
      #define IRDA_GPIO_MODE_SWITCH   gpio_irda_mode_switch_pin
   #else /* __CUST_NEW__ */
      #define IRDA_GPIO_MODE_SWITCH 40
   #endif /* __CUST_NEW__ */
#endif /* defined(__IRDA_VISHAY_6102__) */

//kal_uint32 test_delay=20;
#define irda_test_delay 20
kal_uint8 irda_get_mode_gpio(void) 
{   
#if defined(__IRDA_VISHAY_6102__)
   return (IRDA_GPIO_MODE_SWITCH);
#else
   return 0;
#endif /* defined(__IRDA_VISHAY_6102__) */
}

void irda_delay(kal_uint32 count)
{
   kal_uint32 i;
   for(i=0;i<count;i++){};      
}   
void irda_switch_to_sir(void)
{
	#if defined(__IRDA_VISHAY_6102__)
	/*Vishay 6614*/
   #ifndef __CUST_NEW__
   GPIO_ModeSetup(IRDA_GPIO_MODE_SWITCH, 0);
   GPIO_InitIO(OUTPUT, IRDA_GPIO_MODE_SWITCH);   	
   #endif /* __CUST_NEW__ */
	GPIO_WriteIO(0, IRDA_GPIO_MODE_SWITCH);			
	#elif defined(__IRDA_AGILENT_3220__)||defined(__IRDA_VISHAY_6614__)	
		
	
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x1);   
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x5);   
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x4);         
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x0);
   #endif
}	
void irda_switch_to_mir(void)
{
	/*Vishay 6614*/
	#if defined(__IRDA_VISHAY_6102__)
	GPIO_WriteIO(1, IRDA_GPIO_MODE_SWITCH);	
	#elif defined(__IRDA_VISHAY_6614__)
	DRV_WriteReg(IR_TRANSCEIVER_PDN,0x1);	
	irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x7);   
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x6);   	   
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x4);   
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x0);
	#endif
}
void irda_switch_to_fir(void)
{	
	#if defined(__IRDA_VISHAY_6102__)
	/*Vishay 6614*/
	GPIO_WriteIO(1, IRDA_GPIO_MODE_SWITCH);
	/*Vishay 6102, Anilent 3220*/
	#elif defined(__IRDA_AGILENT_3220__)||defined(__IRDA_VISHAY_6614__)
	DRV_WriteReg(IR_TRANSCEIVER_PDN,0x1);	
	irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x7);   
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x6);   	   
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x4);   
   irda_delay(irda_test_delay);
   DRV_WriteReg(IR_TRANSCEIVER_PDN,0x0);
   #endif
}   

const irda_customize_function_struct irda_custom_func=
{
   irda_switch_to_sir,
   irda_switch_to_mir, 
   irda_switch_to_fir
};       

const irda_customize_function_struct *irda_GetFunc(void)
{
   return (&irda_custom_func);  
}   

#endif
