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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "gpio_def.h"
#include "gpio_drv.h"


NOKE_DRV_GPIO_SETTING_TABLE noke_drv_gpio_setting_tbl[] = {
    
	{GPIO_PORT_0,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_1,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_2,  GPIO_PORT_VAILD,  MODE_3,   PULL_DISABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_3,  GPIO_PORT_VAILD,  MODE_3,   PULL_DISABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_4,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_5,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_6,  GPIO_PORT_VAILD,  MODE_2,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_7,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},

	{GPIO_PORT_8,  GPIO_PORT_VAILD,  MODE_1,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_8,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_9,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_10,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_11,  GPIO_PORT_VAILD,  MODE_1,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_12,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_13,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_14,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_15,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},

	{GPIO_PORT_16,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_17,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_18,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_19,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_20,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_21,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_22,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_23,  GPIO_PORT_INVAILD,  MODE_0,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},

	{GPIO_PORT_24,  GPIO_PORT_INVAILD,  MODE_0,   PULL_DISABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_25,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_26,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_27,  GPIO_PORT_VAILD,  MODE_3,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_28,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_29,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_30,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_31,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},

	{GPIO_PORT_32,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_33,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_34,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_35,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_36,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_37,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_38,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_39,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},

	{GPIO_PORT_40,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_41,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_42,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_43,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_44,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_45,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_INPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_46,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_47,  GPIO_PORT_VAILD,  MODE_0,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},

	{GPIO_PORT_48,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_49,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_50,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_51,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_52,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_53,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_54,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},

	{GPO_PORT_0,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPO_PORT_1,  GPIO_PORT_VAILD,  MODE_1,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPO_PORT_2,  GPIO_PORT_VAILD,  MODE_2,   PULL_DISABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPO_PORT_3,  GPIO_PORT_VAILD,  MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL},
	{GPIO_PORT_MAX, GPIO_PORT_INVAILD, MODE_0,   PULL_ENABLE,  DIR_OUTPUT,  INV_DISABLE,  NULL}
};













#ifdef __CUST_NEW__
extern void GPIO_setting_init(void);

#ifdef __PRODUCTION_RELEASE__
kal_bool   gpio_debug_enable = KAL_FALSE;
#else /* __PRODUCTION_RELEASE__ */
kal_bool   gpio_debug_enable = KAL_FALSE;
#endif /* __PRODUCTION_RELEASE__ */

#ifdef __USB_ENABLE__
extern const char gpio_usb_enable_pin;
#endif

#endif /*__CUST_NEW__*/


extern void BT_init(void);

#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add it 
extern const char  gpio_ent4_pin;
extern const char gpio_power_sw_pin ;
#endif

/*********************************************************************
*
*
*
*                      MISC GPIO DRV
*
*
*
*********************************************************************/
void noke_drv_gpio_setting_init()
{
	int i;
	while( GPIO_PORT_MAX != GPIO_PORT_MAX & noke_drv_gpio_setting_tbl[i].Port )
	{
		if(GPIO_PORT_VAILD == noke_drv_gpio_setting_tbl[i].Valid )
		{
			if(  GPIO_MAGIC_NUM == GPIO_MAGIC_NUM & noke_drv_gpio_setting_tbl[i].Port )
			{
				GPIO_ModeSetup(noke_drv_gpio_setting_tbl[i].Port, noke_drv_gpio_setting_tbl[i].Mode);
				GPIO_PullenSetup(noke_drv_gpio_setting_tbl[i].Port, noke_drv_gpio_setting_tbl[i].Pull);
				GPIO_InitIO(noke_drv_gpio_setting_tbl[i].Dir, noke_drv_gpio_setting_tbl[i].Port);
				GPIO_DinvSetup(noke_drv_gpio_setting_tbl[i].Port, noke_drv_gpio_setting_tbl[i].Inv);	
			}else if(GPO_MAGIC_NUM == GPO_MAGIC_NUM & noke_drv_gpio_setting_tbl[i].Port){

			}else{
				#ifdef NOKE_DEBUG
					noke_dbg_printf("\r Hongzhe.liu :  noke_drv_gpio_setting_init : gpio port number error !\n");
				#endif
				ASSERT(0);
			}
		}
	}

	
}


#if defined(__FLASH_LIGHT_SUPPORT__)

/* flashlight */
extern const char gpio_flashlight_en_pin;
#ifndef __COUNTERFEIT_MONEY_LAMP_SUPPORT__
extern const char gpio_counterfeit_money_lamp_en_pin;
#endif
void noke_drv_flash_light_on(kal_bool light_on)
{
	GPIO_ModeSetup(gpio_flashlight_en_pin, 0); 
	GPIO_InitIO(1, gpio_flashlight_en_pin); 	
	if( light_on == KAL_TRUE)
	{
		GPIO_WriteIO(1, gpio_flashlight_en_pin); 
	}
	else
	{
		GPIO_WriteIO(0, gpio_flashlight_en_pin); 				
	}	

#ifndef __COUNTERFEIT_MONEY_LAMP_SUPPORT__
	GPIO_ModeSetup(gpio_counterfeit_money_lamp_en_pin, 0); 
	GPIO_InitIO(1, gpio_counterfeit_money_lamp_en_pin); 	
	if( light_on == KAL_TRUE)
	{
		GPIO_WriteIO(1, gpio_counterfeit_money_lamp_en_pin); 
	}
	else
	{
		GPIO_WriteIO(0, gpio_counterfeit_money_lamp_en_pin); 				
	}	

#endif
}
#endif /* __FLASH_LIGHT_SUPPORT__ */

#if defined(__COUNTERFEIT_MONEY_LAMP_SUPPORT__)

/* lamp Counterfeit Money  */
extern const char gpio_counterfeit_money_lamp_en_pin;

void noke_drv_counterfeit_money_lamp_on(kal_bool light_on)
{
	GPIO_ModeSetup(gpio_counterfeit_money_lamp_en_pin, 0); 
	GPIO_InitIO(1, gpio_counterfeit_money_lamp_en_pin); 	
	if( light_on == KAL_TRUE)
	{
		GPIO_WriteIO(1, gpio_counterfeit_money_lamp_en_pin); 
	}
	else
	{
		GPIO_WriteIO(0, gpio_counterfeit_money_lamp_en_pin); 				
	}	
}
#endif /* __COUNTERFEIT_MONEY_LAMP_SUPPORT__ */

#ifdef __MAIN_CAMERA_WITH_FLASH__
/* photo_flashlight  */
extern void noke_drv_camera_flash_light_on(kal_bool light_on);
#endif /* __MAIN_CAMERA_WITH_FLASH__ */

/*
* FUNCTION                                                            
*	GPIO_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the GPIO pins as all GPIO,
*	and configure them as output.
*
* CALLS  
*	None
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
void GPIO_init(void)
{
#ifdef __CUST_NEW__
#if 1
	GPIO_setting_init();
#else
	noke_drv_gpio_setting_init();
#endif
   #ifdef __BT_SUPPORT__
   BT_init();
  #endif
   #ifdef __USB_ENABLE__
   GPO_WriteIO(0,gpio_usb_enable_pin);
   #endif	/*__USB_ENABLE__*/

#else /* __CUST_NEW__ */

#if 0
   DRV_WriteReg(GPIO_MODE1,0x2033);
   DRV_WriteReg(GPIO_MODE2,0x5555);
   DRV_WriteReg(GPIO_MODE3,0x1555);
   DRV_WriteReg(GPIO_MODE4,0x0120);
   DRV_WriteReg(GPIO_MODE5,0x5680);
   DRV_WriteReg(GPIO_MODE6,0x5515);
   DRV_WriteReg(GPIO_MODE7,0x1555);
   DRV_WriteReg(GPO_MODE,0x0001);

   DRV_Reg(GPIO_DIR1) |= 0x00BA;
   DRV_Reg(GPIO_DIR2) |= 0xEE00;
   DRV_Reg(GPIO_DIR3) |= 0x0807;

   DRV_Reg(GPIO_PULLEN1) = 0xffef;
   DRV_Reg(GPIO_PULLEN3) = 0xffe7;
   
#ifdef __USB_ENABLE__
   GPIO_WriteIO(0,1);   
#endif	/*__USB_ENABLE__*/

#ifdef  __BTMODULE_RFMD3500__ //add by shine, 2006/06/17
   GPIO_WriteIO(0,8);
   GPIO_WriteIO(0,9);
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef	__GEMINI__
	if(0 == MT6302_getSPIInterface()){
		/*set to LCD mode, following is for MT6225, customer should configure this depends on BB chip spec*/
		GPIO_ModeSetup(29, 1);/*LCD serial interface CLK*/
		GPIO_ModeSetup(31, 1);/*LCD serial interface DAT*/
		switch(MT6302_getLCDSerialInterface()){
			case 0:
				GPIO_ModeSetup(32, 1);/*set to LCD serial CS mode*/
				break;
			case 1:
				GPIO_ModeSetup(33, 1);/*set to LCD serial CS mode*/
				break;
			default:
				ASSERT(0);
				break;
		}
	}
#endif
#endif
#endif /* __CUST_NEW__ */   

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Modify It  ,Set interrupt
//GPIO_ModeSetup(gpio_G_int_pin, 3);  	
#endif

#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It 
GPIO_ModeSetup(gpio_ent4_pin, 3);  	
#endif

#if defined(__FLASH_LIGHT_SUPPORT__)
/* flashlight */
	noke_drv_flash_light_on(0);
#endif /* __FLASH_LIGHT_SUPPORT__ */
#if defined(__COUNTERFEIT_MONEY_LAMP_SUPPORT__)
/* lamp Counterfeit Money  */
	noke_drv_counterfeit_money_lamp_on(0);
#endif /* __COUNTERFEIT_MONEY_LAMP_SUPPORT__ */
#if defined( __MAIN_CAMERA_WITH_FLASH__)
/* photo_flashlight  */
	noke_drv_camera_flash_light_on(0);
#endif /* __MAIN_CAMERA_WITH_FLASH__ */


}


