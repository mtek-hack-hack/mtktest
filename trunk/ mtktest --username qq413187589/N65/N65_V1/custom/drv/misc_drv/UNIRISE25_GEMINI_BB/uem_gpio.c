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
 *   uem_gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of custom component module configuration
 *   variables, and routines handle for equipment device.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CUST_NEW__
#ifndef __L1_STANDALONE__

/*
**   Includes
*/
#include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"

#include "device.h"
#include "custom_equipment.h"
#include "custom_hw_default.h"
#include "custom_em.h"

/*
**   Typedefs
*/

/*
**   Defines
*/

/*
**   Extern Functions
*/
extern void GPIO_WriteIO(char data, char port);
extern void GPIO_WriteIO_FAST(char data, char port);
extern void PWM_level(kal_uint8 level);
extern void PWM2_level(kal_uint8 level);
extern void PWM2_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM2_Start(void);
extern void PWM2_Stop(void);
//extern void Alter_level(kal_uint8 level);
#if (defined(TOUCH_PAD_SUPPORT) && defined(__MTK_TARGET__))
extern void Touchpad_PowerOn(const kal_bool bOn);
#endif
#ifdef KEY_ENTER_BACKLIGHT_SUPPORT
#if defined(HORSERACE_SUPPORT)
extern void noke_drv_horse_race_keyenter_round_light_on(gpio_device_keyenter_backlight_typedef style);
#endif
#endif
/*
**   Extern Varibales
*/
extern const char gpio_led_mainbl_en_pin;
extern const char gpio_led_keybl_en_pin;
extern const char gpio_led_keybl2_en_pin;
extern const char gpio_vibrator_en_pin;
/*
**   Globol Varibales
*/

/*
**   Local Functions
*/

/*
**   Local Variables
*/
/***********************************************************
  **
  **  GPIO SETTTING
  **
  ***********************************************************/



/*
*   Function
*      custom_cfg_outward_gpio_port
*   DESCRIPTION
*      The function is used to handle the port number of the outward gpio device.
*     And it will be call by audio manager.
*   PARAMETERS
*     gpio_device_id      IN
*     port_num            IN/OUT
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*/
kal_uint8 custom_cfg_outward_gpio_port(  kal_uint8  gpio_device_id /* gpio_device_enum */)
{
   if( (gpio_device_id < GPIO_LABELID_MAX) && (gpio_map_tbl[gpio_device_id].vaild != GPIO_INVAILD) )
      return gpio_map_tbl[gpio_device_id].port;
   else
      return 0;
}
void Led_delay(kal_uint32 time)
{
       kal_uint16 i;
	for(i=0;i<time;i++);      
}
void Led_Start(void)
{
	Led_delay(400);
}
void Led_Down(void)
{
	Led_delay(40000);
}


kal_uint8 g_LCD_level=LED_LIGHT_LEVEL0;
kal_uint8 g_Led_Impulse = 0;
kal_uint8 g_LCD_power_off=1;

#if defined(HORSERACE_SUPPORT)
extern int  HorseRaceThreadTaskFlag(void);
extern void HorseRace_KeyPadBackLightOff(void);
extern void HorseRace_KeyPadBackLightOn(void);
#endif

void noke_drv_cfg_aw9364(kal_uint8 gpio_dev_level, int pulse_count)
{
	kal_uint32 savedMask;
	kal_uint8 iPulse = 0, BL_Port = 21, BL_Port2;
	BL_Port2 = gpio_led_mainbl_en_pin & ~(0x80);
	GPIO_ModeSetup(gpio_led_mainbl_en_pin,0);


	switch(gpio_dev_level)
	{
	case LED_LIGHT_LEVEL0:
		g_LCD_power_off = 1;
		GPIO_WriteIO(GPIO_OFF, gpio_led_mainbl_en_pin);
		GPIO_WriteIO(GPIO_OFF, gpio_led_mainbl_en_pin);
		savedMask = SaveAndSetIRQMask(); //disable interrupt
		GPIO_WriteIO_FAST(GPIO_OFF, BL_Port2);
		RestoreIRQMask(savedMask); // turn on interrupt			   
		break;

	case LED_LIGHT_LEVEL1:
	case LED_LIGHT_LEVEL2:
	case LED_LIGHT_LEVEL3:
	case LED_LIGHT_LEVEL4:
	case LED_LIGHT_LEVEL5:
		if(g_LCD_power_off==1)
		{
			GPIO_WriteIO(GPIO_ON, gpio_led_mainbl_en_pin);
			Led_Start();
		}

		g_LCD_power_off = 0;

		savedMask = SaveAndSetIRQMask(); //disable interrupt
		for(iPulse=0;iPulse<pulse_count;iPulse++)
		{
			GPIO_WriteIO_FAST(GPIO_ON ,BL_Port2);
			Led_delay(10);
			GPIO_WriteIO_FAST(GPIO_OFF, BL_Port2);
			Led_delay(10);
		}
		GPIO_WriteIO_FAST(GPIO_ON ,BL_Port2);	
		RestoreIRQMask(savedMask); // turn on interrupt			   
		break;
	case LED_LIGHT_LEVEL_MAX:
		g_LCD_power_off = 0;
		GPIO_WriteIO(GPIO_ON, gpio_led_mainbl_en_pin);
		GPIO_WriteIO(GPIO_ON, gpio_led_mainbl_en_pin);
		savedMask = SaveAndSetIRQMask(); //disable interrupt
		GPIO_WriteIO_FAST(GPIO_ON, BL_Port2);
		RestoreIRQMask(savedMask); // turn on interrupt					
		break;
	}
}

kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level )
{
	static kal_uint8 is_first = 1;
	volatile kal_uint16 j, iDelay;
	kal_uint8 iPulse = 0, BL_Port = 21, BL_Port2;
	kal_uint32 savedMask;
	kal_uint8 temp_IPulse = 0;
	
	switch(gpio_dev_type)
	{
	case GPIO_DEV_LED_MAINLCD:
		if( is_first == 1)
		{
			Led_Down();
			Led_Down();
			Led_Down();
			Led_Down();
			is_first = 0;
		}
		BL_Port2 = gpio_led_mainbl_en_pin & ~(0x80);
		GPIO_ModeSetup(gpio_led_mainbl_en_pin,0);

		if(g_LCD_level!=gpio_dev_level)
		{
			temp_IPulse = 16 - 3*(gpio_dev_level - g_LCD_level);
			noke_drv_cfg_aw9364(gpio_dev_level, temp_IPulse);
		}
		g_LCD_level=gpio_dev_level;
		break;

	case GPIO_DEV_LED_SUBLCD:
		break;

	case GPIO_DEV_LED_STATUS_1:
		break;

	case GPIO_DEV_LED_STATUS_2:
		break;

	case GPIO_DEV_LED_STATUS_3:
		break;

	case GPIO_DEV_LED_KEY:
#if defined(HORSERACE_SUPPORT)
		if( 0 == HorseRaceThreadTaskFlag()  )	
		{
			if (gpio_dev_level == LED_LIGHT_LEVEL0) 
				HorseRace_KeyPadBackLightOff();
			else			
				HorseRace_KeyPadBackLightOn();
		}
#else
		if (gpio_dev_level == LED_LIGHT_LEVEL0) {
			GPIO_WriteIO(GPIO_OFF, gpio_led_keybl_en_pin);
		}else {
			GPIO_WriteIO(GPIO_ON, gpio_led_keybl_en_pin);
		}
		//  PWM2_level(gpio_dev_level);
#endif
		break;

	case GPIO_DEV_VIBRATOR:
		if (gpio_dev_level == VIBRATOR_OFF)
		{
			GPIO_WriteIO(GPIO_OFF, gpio_vibrator_en_pin);
		}
		else
		{
			GPIO_WriteIO(GPIO_ON, gpio_vibrator_en_pin);
		}
		break;
/* 2009.07.20 added by hongzhe.liu for keyenter backlight + */
#ifdef KEY_ENTER_BACKLIGHT_SUPPORT
	case GPIO_DEV_KEYENTER_BACKLIGHT:
		#if defined(HORSERACE_SUPPORT)
		noke_drv_horse_race_keyenter_round_light_on(gpio_dev_level);
		#else
		//Nothing to be done!
		#endif
		break;
#endif
/* 2009.07.20 added by hongzhe.liu for keyenter backlight - */
	default:
		/* error undefine */
		return KAL_FALSE;
	}

	return KAL_TRUE;

}

void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty)
{
   /*
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, ((red_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, ((green_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, ((blue_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));

   PWM2_Configure(PWM2_Level_Info[0][0], duty);
   PWM2_Start();
   */
}

void custom_stop_flashlight(void)
{
   /*
   custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
   custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
   custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);

   PWM2_Stop();
   */
}

#endif /* !__L1_STANDALONE__ */

#endif /* __CUST_NEW__ */


