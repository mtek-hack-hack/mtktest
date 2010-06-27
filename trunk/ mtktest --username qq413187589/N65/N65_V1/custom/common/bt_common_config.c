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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	 bt_common_config.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains common configuration for Bluetooth customization
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"      	/* Basic data type */
#include "gpio_sw.h"
#include "eint.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#ifdef MT6318
#include "pmic6318_sw.h"
#endif
#include "GlobalDefs.h"
#ifdef __BT_USE_UART2__
#include "uart_sw.h"
#endif

/* Maximum bit rate of A2DP profile used,
   depends on the headset capability and the transmission distance, 
   232 ~ 478 is suggested to trasfer SBC bitstream */
kal_uint16 BT_A2DP_MAX_BIT_RATE = 345;

//Maxium length for this pattern is 20
//For example: this pattern could be MTKGameStartReq
kal_uint8 SPPClientFirstConnDataPattern[20]={"MTKSPPForMMI"};
//This len is actually length of this pattern
kal_uint8 SPPClientFirstConnDataPatternLen = 12;

#if defined(__BTMODULE_MT6601__)
kal_uint8 BT_CHIP_ID = 0x11;
#elif defined(__BTMODULE_MT6611__)
kal_uint8 BT_CHIP_ID = 0x12;
#elif defined(__BTMODULE_RFMD3500__)
kal_uint8 BT_CHIP_ID = 0x21;
#elif defined(__BTMODULE_RFMD4020__)
kal_uint8 BT_CHIP_ID = 0x22;
#else 
kal_uint8 BT_CHIP_ID = 0;
#endif 

#if defined (__BTMODULE_MT6601__) || defined (__BTMODULE_MT6611__) || defined(__BT_RDA5868__)

typedef  struct {
	unsigned char num_poweronBT;
	unsigned char pol_poweronBT;
	unsigned char num_resetBT;
	unsigned char pol_resetBT;
	unsigned char num_wakeupHost;
	unsigned char pol_wakeupHost;
	unsigned char num_lpoclk;
	unsigned char mode_lpoclk;
	unsigned char num_urxd3;
	unsigned char num_utxd3;
	unsigned char num_ucts3;
	unsigned char num_urts3;
	unsigned char num_pcmclk;
	unsigned char num_pcmsync;
	unsigned char num_pcmout;
	unsigned char num_pcmin;
} sGPIO4BT;

#ifdef __CUST_NEW__
extern const char gpio_bt_power_pin;
/*** Notice!!! Please use gpio_bt_reset_pin for BT reset ***/
//extern const char gpio_bt_wakeup_pin;
extern const char gpio_bt_reset_pin;
extern const char gpio_bt_32k_pin;
extern const char gpio_bt_utxd3_pin;
extern const char gpio_bt_urxd3_pin;
extern const char gpio_bt_ucts3_pin;
extern const char gpio_bt_urts3_pin;
extern const char gpio_bt_pcmclk_pin;
extern const char gpio_bt_pcmsync_pin;
extern const char gpio_bt_pcmin_pin;
extern const char gpio_bt_pcmout_pin;
extern const unsigned char  BT_EINT_NO;
#else
#define BT_GPO_MAGIC_NUM	100

extern const unsigned char bt_gpio_setting[16];
#endif

extern void BtRadio_EintIsr(void);


void BtRadio_SetupGPIO(char val, unsigned char pin)
{
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		GPIO_ModeSetup(pin, val);
	}
	else
	{
		GPO_ModeSetup(pin, val);
	}
#else
	if (pin >= BT_GPO_MAGIC_NUM)
	{
		GPO_ModeSetup((pin - BT_GPO_MAGIC_NUM), val);
	}
	else
	{
		GPIO_ModeSetup(pin, val);
	}
#endif
}

void BtRadio_InitGPIO(char val, unsigned char pin)
{
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		GPIO_InitIO(val, pin);
	}
#else
	if (pin < BT_GPO_MAGIC_NUM)
	{
		GPIO_InitIO(val, pin);
	}
#endif
}

void BtRadio_WriteGPIO(char val, unsigned char pin)
{
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		GPIO_WriteIO(val, pin);
	}
	else
	{
		GPO_WriteIO(val, pin);
	}
#else
	if (pin >= BT_GPO_MAGIC_NUM)
	{
		GPO_WriteIO(val, (pin - BT_GPO_MAGIC_NUM));
	}
	else
	{
		GPIO_WriteIO(val, pin);
	}
#endif
}


#ifdef __BT_RDA5868__
extern void RDA_bt_Power_Off(void);
extern void rdabt_poweron_init(void);
#endif

void BtRadio_PowerOn(kal_uint8 polBT, kal_uint8 numBT)
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("hongzhe.liu : BtRadio_PowerOn");
#endif
#ifdef __BT_RDA5868__
	rdabt_poweron_init();
#else
#if 0
	if (numBT == 0xFF)
	{
#if (defined(MT6318))
		pmic_vmc_sel(VMC_2_8V);
		pmic_vmc_enable(KAL_TRUE);
#endif
	}
	else
	{
		BtRadio_WriteGPIO(polBT, numBT);  // turn on BT regulator
	}
#endif	
	GPIO_WriteIO(1,gpio_bt_power_pin);
#endif
}

void BtRadio_PowerOff(kal_uint8 polBT, kal_uint8 numBT)
{
#ifdef __BT_RDA5868__
	RDA_bt_Power_Off();
#else
#if 0
	if (numBT == 0xFF)
	{
#if (defined(MT6318))
		pmic_vmc_enable(KAL_FALSE);
#endif
	}
	else
	{
		BtRadio_WriteGPIO((1 - polBT), numBT);  // turn off BT regulator
	}
#endif
       GPIO_WriteIO(0,gpio_bt_power_pin);
#endif
}

#ifdef __CUST_NEW__
kal_uint8 BtRadio_GetLpoMode(kal_uint8 numLpo)
{
	kal_uint8 modeLpo = 0xFF;

#if defined(MT6217) || defined(MT6218B)
{
	modeLpo = 2;
}
#elif defined(MT6219) || defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
{
	modeLpo = 3;
}
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
{
	if (numLpo == (GPIO_MAGIC_NUM | 8))
		modeLpo = 1;
	else
		modeLpo = 3;
}
#elif defined(MT6225)
{
	if ((numLpo == (GPIO_MAGIC_NUM | 6)) || (numLpo == (GPO_MAGIC_NUM | 2)))
		modeLpo = 2;
	else
		modeLpo = 3;
}
#elif defined(MT6223) || defined(MT6223P)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 21):
			modeLpo = 3;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(0, 4);
#endif
			break;
		case (GPIO_MAGIC_NUM | 22):
			modeLpo = 3;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(1, 4);
#endif
			break;
		case (GPIO_MAGIC_NUM | 23):
			modeLpo = 3;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(2, 4);
#endif
			break;
		case (GPIO_MAGIC_NUM | 47):
			modeLpo = 3;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(3, 4);
#endif
			break;
		case (GPIO_MAGIC_NUM | 48):
			modeLpo = 3;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(4, 4);
#endif
			break;
		case (GPIO_MAGIC_NUM | 49):
			modeLpo = 3;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(5, 4);
#endif
			break;
	}
}

#elif defined(MT6238)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 57):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(0, 6);
#endif
			break;
		case (GPIO_MAGIC_NUM | 58):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(1, 6);
#endif
			break;
		case (GPIO_MAGIC_NUM | 65):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(2, 6);
#endif
			break;
		case (GPIO_MAGIC_NUM | 66):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(3, 6);
#endif
			break;
		case (GPIO_MAGIC_NUM | 8):
			modeLpo = 3;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(3, 6);
#endif
			break;
		case (GPIO_MAGIC_NUM | 77):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(4, 6);
#endif
			break;
		case (GPIO_MAGIC_NUM | 78):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(5, 6);
#endif
			break;
		case (GPIO_MAGIC_NUM | 50):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(6, 6);
#endif
			break;
		case (GPIO_MAGIC_NUM | 55):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			GPIO_SetClkOut(7, 6);
#endif
			break;
	}
}
#endif

	return modeLpo;
}
#endif

#ifdef __BT_USE_UART2__
extern kal_uint8 bt_uart_port;
#endif

void BtRadio_AssignGpioPins(sGPIO4BT *gpio)
{
  char errStr[255];
#ifdef __CUST_NEW__
	

	// power on pin
#ifdef __BT_RDA5868__
	gpio->num_poweronBT = 0xFF;
#else
	if (gpio_bt_power_pin != 0xFF)
	{
		gpio->num_poweronBT = gpio_bt_power_pin;
	}
	else
	{
		gpio->num_poweronBT = 0xFF;
	}
#endif
	gpio->pol_poweronBT = 1;

	// reset pin
#ifdef __BT_RDA5868__
	gpio->num_resetBT = 0xFF;
#else	
	if (gpio_bt_reset_pin == 0xFF)
	{
		AnsiiToUnicodeString(&errStr, "Please assign the gpio_bt_reset_pin!");
		DisplayPopup(errStr, IMG_GLOBAL_ERROR, 0, 5000, 0);
	}
	else
	{
		gpio->num_resetBT = gpio_bt_reset_pin;
	}
#endif	
	gpio->pol_resetBT = 1;

	// wakeup host pin
	if (BT_EINT_NO != EINT_CHANNEL_NOT_EXIST)
	{
		gpio->num_wakeupHost = BT_EINT_NO;
	}
	else
	{
		AnsiiToUnicodeString(&errStr, "Please assign the BT_EINT_NO!");
		DisplayPopup(errStr, IMG_GLOBAL_ERROR, 0, 5000, 0);
	}

	gpio->pol_wakeupHost = 1;

	// UART pin
	gpio->num_urxd3 = gpio_bt_urxd3_pin;
	gpio->num_utxd3 = gpio_bt_utxd3_pin;

	gpio->num_ucts3 = 0xFF;		// Non flow control
	gpio->num_urts3 = 0xFF;		// Non flow control

	// lpo clock pin
	gpio->num_lpoclk = gpio_bt_32k_pin;
	gpio->mode_lpoclk = BtRadio_GetLpoMode(gpio_bt_32k_pin);

	if (gpio->mode_lpoclk == 0xFF)
	{
		AnsiiToUnicodeString(&errStr, "Please check the 32KHz clock setting!");
		DisplayPopup(errStr, IMG_GLOBAL_ERROR, 0, 5000, 0);
	}

	// PCM pin
	gpio->num_pcmclk = gpio_bt_pcmclk_pin;
	gpio->num_pcmsync = gpio_bt_pcmsync_pin;
	gpio->num_pcmout = gpio_bt_pcmout_pin;
	gpio->num_pcmin = gpio_bt_pcmin_pin;
#else
	// power on pin
	gpio->num_poweronBT = bt_gpio_setting[0];
	gpio->pol_poweronBT = bt_gpio_setting[1];
	// reset pin
	gpio->num_resetBT = bt_gpio_setting[2];
	gpio->pol_resetBT = bt_gpio_setting[3];
	// wake up host pin
	gpio->num_wakeupHost = bt_gpio_setting[4];
	gpio->pol_wakeupHost = bt_gpio_setting[5];
	// UART pin
	gpio->num_urxd3 = bt_gpio_setting[6];
	gpio->num_utxd3 = bt_gpio_setting[7];
	gpio->num_ucts3 = bt_gpio_setting[8];
	gpio->num_urts3 = bt_gpio_setting[9];
	// lpo clock pin
	gpio->num_lpoclk = bt_gpio_setting[10];
	gpio->mode_lpoclk = bt_gpio_setting[11];
	// PCM pin
	gpio->num_pcmclk = bt_gpio_setting[12];
	gpio->num_pcmsync = bt_gpio_setting[13];
	gpio->num_pcmout = bt_gpio_setting[14];
	gpio->num_pcmin = bt_gpio_setting[15];
 #endif

	if (gpio->num_poweronBT != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_poweronBT);		// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_poweronBT);		// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_poweronBT);		// set ouput low
	}

	if(gpio->num_resetBT != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_resetBT);			// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_resetBT);			// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_resetBT);			// set ouput low
	}

	BtRadio_InitGPIO(1, gpio->num_urxd3);					// set direction (output)
	BtRadio_SetupGPIO(0, gpio->num_urxd3);				// set to gpio mode
	BtRadio_WriteGPIO(0, gpio->num_urxd3);				// set ouput low

	BtRadio_InitGPIO(1, gpio->num_utxd3);					// set direction (output)
	BtRadio_SetupGPIO(0, gpio->num_utxd3);				// set to gpio mode
	BtRadio_WriteGPIO(0, gpio->num_utxd3);				// set ouput low

	if(gpio->num_ucts3 != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_ucts3);				// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_ucts3);			// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_ucts3);			// set ouput low

		BtRadio_InitGPIO(1, gpio->num_urts3);				// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_urts3);			// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_urts3);			// set ouput low
	}

	if(gpio->num_lpoclk != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_lpoclk);				// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_lpoclk);			// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_lpoclk);			// set ouput low
	}

	if(gpio->num_pcmclk != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_pcmclk);			// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_pcmclk);			// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_pcmclk);			// set ouput low

		BtRadio_InitGPIO(1, gpio->num_pcmsync);			// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_pcmsync);		// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_pcmsync);		// set ouput low

		BtRadio_InitGPIO(1, gpio->num_pcmout);			// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_pcmout);			// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_pcmout);			// set ouput low

		BtRadio_InitGPIO(1, gpio->num_pcmin);			// set direction (output)
		BtRadio_SetupGPIO(0, gpio->num_pcmin);			// set to gpio mode
		BtRadio_WriteGPIO(0, gpio->num_pcmin);			// set ouput low
	}
	// To prevent use wrong EINT
	if (gpio->num_wakeupHost != EINT_CHANNEL_NOT_EXIST)
	{
#if defined(MT6238)
			switch (gpio->num_wakeupHost)
			{
					case 0:
	        	/* GPIO77 = ModeA(EINT0) */
	        	DRV_Reg(GPIO_MODE5)&=0xF3FF;
	        	DRV_Reg(GPIO_MODE5)|=0x0400;
						break;
					case 1:
	        	/* GPIO78 = ModeA(EINT1) */
	        	DRV_Reg(GPIO_MODE5)&=0xCFFF;
	        	DRV_Reg(GPIO_MODE5)|=0x1000;
						break;
					case 2:
	        	/* GPIO79 = ModeA(EINT2) */
	        	DRV_Reg(GPIO_MODE5)&=0x3FFF;
	        	DRV_Reg(GPIO_MODE5)|=0x4000;
						break;
					case 3:
	        	/* GPIO33 = Mode5(EINT3) */
	        	DRV_Reg(GPIO_MODE5)&=0xFFF3;
	        	DRV_Reg(GPIO_MODE5)|=0x0004;
						break;
					case 4:
	        	/* GPIO34 = Mode5(EINT4) */
	        	DRV_Reg(GPIO_MODE5)&=0xFFCF;
	        	DRV_Reg(GPIO_MODE5)|=0x0010;
						break;
					case 5:
	        	/* GPIO35 = Mode5(EINT5) */
	        	DRV_Reg(GPIO_MODE5)&=0xFF3F;
	        	DRV_Reg(GPIO_MODE5)|=0x0040;
						break;
					case 6:
	        	/* GPIO36 = Mode5(EINT6) */
	        	DRV_Reg(GPIO_MODE5)&=0xFCFF;
	        	DRV_Reg(GPIO_MODE5)|=0x0100;
						break;
					case 7:
	        	/* GPIO37 = Mode5(EINT7) */
	        	DRV_Reg(GPIO_MODE5)&=0xF3FF;
	        	DRV_Reg(GPIO_MODE5)|=0x0400;
						break;
			}
#elif defined (MT6223) || defined(MT6223P)
    if (gpio->num_wakeupHost > 1)
		{
		  /* Check chip allowed EINT2~7(6223) for level trigger. */
		  if (gpio->num_wakeupHost < 8)
		  {
        switch (gpio->num_wakeupHost)
        {
        case 2:
        	/* GPIO42 = Mode1(EINT2) */
        	DRV_Reg(GPIO_MODE6)&=0xFFFC;
        	DRV_Reg(GPIO_MODE6)|=0x0001;
          break;
        case 3:
        	/* GPIO43 = Mode1(EINT3) */
        	DRV_Reg(GPIO_MODE6)&=0xFFF3;
        	DRV_Reg(GPIO_MODE6)|=0x0004;
          break;
        case 4:
        	/* GPIO26 = Mode2(EINT4) */
        	DRV_Reg(GPIO_MODE4)&=0xFFCF;
        	DRV_Reg(GPIO_MODE4)|=0x0020;
          break;
        case 5:
        	/* GPIO27 = Mode2(EINT5) */
        	DRV_Reg(GPIO_MODE4)&=0xFF3F;
        	DRV_Reg(GPIO_MODE4)|=0x0080;
        	break;
        case 6:
        	/* GPIO28 = Mode2(EINT6) */
        	DRV_Reg(GPIO_MODE4)&=0xFCFF;
        	DRV_Reg(GPIO_MODE4)|=0x0200;
        	break;
        case 7:
        	/* GPIO14 = Mode3(EINT7) */
        	DRV_Reg(GPIO_MODE5)&=0xCFFF;
        	DRV_Reg(GPIO_MODE5)|=0x3000;
        	break;
        default:
        	/* only handle EINT2~7*/
        	break;
        }		  
		  }
		  else
		  {  
		    AnsiiToUnicodeString(&errStr, "Please assign BT_EINT_NO < 8!");
		    DisplayPopup(errStr, IMG_GLOBAL_ERROR, 0, 5000, 0);
		  }
		}
#else
		if (gpio->num_wakeupHost > 3)
		{
		  /* Check chip allowed EINT4~7 for level trigger. */
		  if (gpio->num_wakeupHost < 8)
		  {
#if defined(MT6226) || defined(MT6227) || defined(MT6226M) 
        switch (gpio->num_wakeupHost)
        {
        case 4:
        	/* GPIO36 = Mode3(EINT4) */
        	DRV_Reg(GPIO_MODE5)&=0xFCFF;
        	DRV_Reg(GPIO_MODE5)|=0x0300;
          break;
        case 5:
        	/* GPIO34 = Mode2(EINT5) */
        	DRV_Reg(GPIO_MODE5)&=0xFFCF;
        	DRV_Reg(GPIO_MODE5)|=0x0020;
        	break;
        case 6:
        	/* GPIO35 = Mode3(EINT6) */
        	DRV_Reg(GPIO_MODE5)&=0xFF3F;
        	DRV_Reg(GPIO_MODE5)|=0x00C0;
        	break;
        case 7:
        	/* GPIO33 = Mode2(EINT7) */
        	DRV_Reg(GPIO_MODE5)&=0xFFF3;
        	DRV_Reg(GPIO_MODE5)|=0x000C;
        	break;
        default:
        	/* only handle EINT4~7*/
        	break;
        }
#elif defined(MT6225) 
        switch (gpio->num_wakeupHost)
        {
        case 4:
        	/* GPIO0 = MODE3(EINT4) */
        	DRV_Reg(GPIO_MODE1)&=0xFFFC;
        	DRV_Reg(GPIO_MODE1)|=0x0003;
          break;
        case 5:
        	/* GPIO1 = MODE3(EINT5) */
        	DRV_Reg(GPIO_MODE1)&=0xFFF3;
        	DRV_Reg(GPIO_MODE1)|=0x000C;
        	break;
        case 6:
        	/* GPIO2 = MODE3(EINT6) */
        	DRV_Reg(GPIO_MODE1)&=0xFFCF;
        	DRV_Reg(GPIO_MODE1)|=0x0030;
        	break;
        case 7:
        	/* GPIO3 = MODE3(EINT7) */
        	DRV_Reg(GPIO_MODE1)&=0xFF3F;
        	DRV_Reg(GPIO_MODE1)|=0x00C0;
        	break;
        default:
        	/* only handle EINT4~7*/
        	break;
        }
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
        switch (gpio->num_wakeupHost)
        {
        case 4:
        	/* no EINT4 */
        	AnsiiToUnicodeString(&errStr, "Do not use EINT4 on this chip!");
		      DisplayPopup(errStr, IMG_GLOBAL_ERROR, 0, 5000, 0);
          break;
        case 5:
        	/* GPIO35 = MODE0(GPIO input = EINT5) */
        	GPIO_ModeSetup(35, 0);
        	GPIO_InitIO(0, 35);/* 0=input, 1=output*/
        	break;
        case 6:
        	/* GPIO37 = MODE1(UART2 RXD = EINT5) */
        	GPIO_ModeSetup(37, 1);
        	//GPIO_InitIO(0, 37);/* 0=input, 1=output*/
        	break;
        case 7:
        	/* GPIO8 = MODE0(GPIO input = EINT7) */
        	GPIO_ModeSetup(8, 0);
        	GPIO_InitIO(0, 8);/* 0=input, 1=output*/
        	break;
        default:
        	/* only handle EINT4~7*/
        	break;
        }
#else
       AnsiiToUnicodeString(&errStr, "Do not use EINT4-7 on this chip!");
		   DisplayPopup(errStr, IMG_GLOBAL_ERROR, 0, 5000, 0);
#endif		   
		  }/*if (gpio->num_wakeupHost < 8)*/
		  else
		  {  
		    AnsiiToUnicodeString(&errStr, "Please assign BT_EINT_NO < 8!");
		    DisplayPopup(errStr, IMG_GLOBAL_ERROR, 0, 5000, 0);
		  }
	  }/*if (gpio->num_wakeupHost > 3)*/
#endif
	}/*if (gpio->num_wakeupHost != EINT_CHANNEL_NOT_EXIST)*/

	if (gpio->num_wakeupHost != 0xFF)
	{
		EINT_Registration(gpio->num_wakeupHost, KAL_TRUE/*no debounce*/, gpio->pol_wakeupHost, BtRadio_EintIsr, 0/*no auto unmask*/);
	}

#ifdef __BT_USE_UART2__
	bt_uart_port = uart_port2;
#endif
}

#if 1
//Huyanwei Add it 

void BlueTooth_Init_Pin(const unsigned char pin)
{
	if( pin != 0xFF)
	{
		BtRadio_InitGPIO(1, pin);				// set direction (output)
		BtRadio_SetupGPIO(0, pin);				// set to gpio mode
		BtRadio_WriteGPIO(0, pin);				// set ouput low
	}
}

void BlueTooth_Init_GPO_Pin(const unsigned char pin)
{
	if( pin != 0xFF)
	{
		GPO_ModeSetup( pin,0);				// set to gpio mode
		GPO_WriteIO(0, pin);				// set ouput low
	}
}


void BlueTooth_Init_Gpio(void)
{
	char errStr[255];

#ifdef __BT_RDA5868__

/* 2009.3.30 modified by hongzhe.liu for e203 + */
	GPIO_ModeSetup(gpio_bt_power_pin,0);
	GPIO_InitIO(1, gpio_bt_power_pin);		
	GPIO_WriteIO(0, gpio_bt_power_pin);
/* 2009.3.30 modified by hongzhe.liu for e203 - */

#else

	#if 1
	BlueTooth_Init_Pin(gpio_bt_power_pin); 	//Power 
	#else
	BlueTooth_Init_GPO_Pin(gpio_bt_power_pin); 	//Power 
	#endif
#endif
	BlueTooth_Init_Pin(gpio_bt_reset_pin);	//Reset

	BlueTooth_Init_Pin(gpio_bt_urxd3_pin);	//Uart rx
	BlueTooth_Init_Pin(gpio_bt_utxd3_pin);	//Uart tx

	BlueTooth_Init_Pin(gpio_bt_32k_pin);		//32K


	//PCM
	BlueTooth_Init_Pin(gpio_bt_pcmclk_pin);
	BlueTooth_Init_Pin(gpio_bt_pcmsync_pin);
	BlueTooth_Init_Pin(gpio_bt_pcmout_pin);
	BlueTooth_Init_Pin(gpio_bt_pcmin_pin);
	
	// To prevent use wrong EINT
	if (BT_EINT_NO != EINT_CHANNEL_NOT_EXIST)
	{
	
#if defined(MT6238)
			switch (BT_EINT_NO)
			{
					case 0:
					        	/* GPIO77 = ModeA(EINT0) */
					        	DRV_Reg(GPIO_MODE5)&=0xF3FF;
					        	DRV_Reg(GPIO_MODE5)|=0x0400;
						break;
					case 1:
					        	/* GPIO78 = ModeA(EINT1) */
					        	DRV_Reg(GPIO_MODE5)&=0xCFFF;
					        	DRV_Reg(GPIO_MODE5)|=0x1000;
						break;
					case 2:
					        	/* GPIO79 = ModeA(EINT2) */
					        	DRV_Reg(GPIO_MODE5)&=0x3FFF;
					        	DRV_Reg(GPIO_MODE5)|=0x4000;
						break;
					case 3:
					        	/* GPIO33 = Mode5(EINT3) */
					        	DRV_Reg(GPIO_MODE5)&=0xFFF3;
					        	DRV_Reg(GPIO_MODE5)|=0x0004;
						break;
					case 4:
					        	/* GPIO34 = Mode5(EINT4) */
					        	DRV_Reg(GPIO_MODE5)&=0xFFCF;
					        	DRV_Reg(GPIO_MODE5)|=0x0010;
						break;
					case 5:
					        	/* GPIO35 = Mode5(EINT5) */
					        	DRV_Reg(GPIO_MODE5)&=0xFF3F;
					        	DRV_Reg(GPIO_MODE5)|=0x0040;
						break;
					case 6:
					        	/* GPIO36 = Mode5(EINT6) */
					        	DRV_Reg(GPIO_MODE5)&=0xFCFF;
					        	DRV_Reg(GPIO_MODE5)|=0x0100;
						break;
					case 7:
					        	/* GPIO37 = Mode5(EINT7) */
					        	DRV_Reg(GPIO_MODE5)&=0xF3FF;
					        	DRV_Reg(GPIO_MODE5)|=0x0400;
						break;
			}
#elif defined (MT6223) || defined(MT6223P)
  	if (BT_EINT_NO > 1)
	{
		  /* Check chip allowed EINT2~7(6223) for level trigger. */
		  if (BT_EINT_NO < 8)
		  {
			        switch (BT_EINT_NO)
			        {
			        case 2:
				        	/* GPIO42 = Mode1(EINT2) */
				        	DRV_Reg(GPIO_MODE6)&=0xFFFC;
				        	DRV_Reg(GPIO_MODE6)|=0x0001;
			      		break;
			        case 3:
				        	/* GPIO43 = Mode1(EINT3) */
				        	DRV_Reg(GPIO_MODE6)&=0xFFF3;
				        	DRV_Reg(GPIO_MODE6)|=0x0004;
			        		break;
			        case 4:
				        	/* GPIO26 = Mode2(EINT4) */
				        	DRV_Reg(GPIO_MODE4)&=0xFFCF;
				        	DRV_Reg(GPIO_MODE4)|=0x0020;
				          break;
			        case 5:
				        	/* GPIO27 = Mode2(EINT5) */
				        	DRV_Reg(GPIO_MODE4)&=0xFF3F;
				        	DRV_Reg(GPIO_MODE4)|=0x0080;
				        	break;
			        case 6:
				        	/* GPIO28 = Mode2(EINT6) */
				        	DRV_Reg(GPIO_MODE4)&=0xFCFF;
				        	DRV_Reg(GPIO_MODE4)|=0x0200;
				        	break;
			        case 7:
				        	/* GPIO14 = Mode3(EINT7) */
				        	DRV_Reg(GPIO_MODE5)&=0xCFFF;
				        	DRV_Reg(GPIO_MODE5)|=0x3000;
				        	break;
			        default:
			        	/* only handle EINT2~7*/
			        	break;
			        }		  
		  }
	}
#else
	if (BT_EINT_NO > 3)
	{
		  /* Check chip allowed EINT4~7 for level trigger. */
		 if (BT_EINT_NO < 8)
		 {
		#if defined(MT6226) || defined(MT6227) || defined(MT6226M) 
		        switch (BT_EINT_NO)
		        {
		        case 4:
			        	/* GPIO36 = Mode3(EINT4) */
			        	DRV_Reg(GPIO_MODE5)&=0xFCFF;
			        	DRV_Reg(GPIO_MODE5)|=0x0300;
		          break;
		        case 5:
			        	/* GPIO34 = Mode2(EINT5) */
			        	DRV_Reg(GPIO_MODE5)&=0xFFCF;
			        	DRV_Reg(GPIO_MODE5)|=0x0020;
			        	break;
		        case 6:
			        	/* GPIO35 = Mode3(EINT6) */
			        	DRV_Reg(GPIO_MODE5)&=0xFF3F;
			        	DRV_Reg(GPIO_MODE5)|=0x00C0;
			        	break;
		        case 7:
			        	/* GPIO33 = Mode2(EINT7) */
			        	DRV_Reg(GPIO_MODE5)&=0xFFF3;
			        	DRV_Reg(GPIO_MODE5)|=0x000C;
			        	break;
		        default:
		        	/* only handle EINT4~7*/
		        	break;
		        }
		#elif defined(MT6225) 
		        switch (BT_EINT_NO)
		        {
		        case 4:
			        	/* GPIO0 = MODE3(EINT4) */
			        	DRV_Reg(GPIO_MODE1)&=0xFFFC;
			        	DRV_Reg(GPIO_MODE1)|=0x0003;
		          break;
		        case 5:
			        	/* GPIO1 = MODE3(EINT5) */
			        	DRV_Reg(GPIO_MODE1)&=0xFFF3;
			        	DRV_Reg(GPIO_MODE1)|=0x000C;
		        	break;
		        case 6:
			        	/* GPIO2 = MODE3(EINT6) */
			        	DRV_Reg(GPIO_MODE1)&=0xFFCF;
			        	DRV_Reg(GPIO_MODE1)|=0x0030;
		        	break;
		        case 7:
			        	/* GPIO3 = MODE3(EINT7) */
			        	DRV_Reg(GPIO_MODE1)&=0xFF3F;
			        	DRV_Reg(GPIO_MODE1)|=0x00C0;
		        	break;
		        default:
		        	/* only handle EINT4~7*/
		        	break;
		        }
		#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
		        switch (BT_EINT_NO)
		        {
		        case 4:
		        	/* no EINT4 */
		          break;
		        case 5:
			        	/* GPIO35 = MODE0(GPIO input = EINT5) */
			        	GPIO_ModeSetup(35, 0);
			        	GPIO_InitIO(0, 35);/* 0=input, 1=output*/
		        	break;
		        case 6:
			        	/* GPIO37 = MODE1(UART2 RXD = EINT5) */
			        	GPIO_ModeSetup(37, 1);
			        	//GPIO_InitIO(0, 37);/* 0=input, 1=output*/
		        	break;
		        case 7:
			        	/* GPIO8 = MODE0(GPIO input = EINT7) */
			        	GPIO_ModeSetup(8, 0);
			        	GPIO_InitIO(0, 8);/* 0=input, 1=output*/
		        	break;
		        default:
		        	/* only handle EINT4~7*/
		        	break;
		        }
		#else
			
		#endif		   
		  }/*if (gpio->num_wakeupHost < 8)*/
	  }/*if (gpio->num_wakeupHost > 3)*/
#endif

	}/*if (gpio->num_wakeupHost != EINT_CHANNEL_NOT_EXIST)*/

if (BT_EINT_NO != 0xFF)
{
/* 2009.04.24 added by hongzhe.liu for some 5868 coused power on reset + */
#if !defined(__BT_RDA5868__)
	//EINT_Registration(BT_EINT_NO, 1/*no debounce*/, 1, BtRadio_EintIsr, 0/*no auto unmask*/);
#endif
/* 2009.04.24 added by hongzhe.liu for some 5868 coused power on reset - */
}
	
#ifdef __BT_USE_UART2__
	bt_uart_port = uart_port2;
#endif

}

void BT_init(void)
{
#if 1
	BlueTooth_Init_Gpio();
#else
 sGPIO4BT bt_gpio ;
 BtRadio_AssignGpioPins( &bt_gpio) ;
#endif
}

#endif


kal_uint8* BtGet_SPPClientFirstConnDataPattern(kal_uint8* len)
{
    if(SPPClientFirstConnDataPatternLen == 0)
    {
        //Using default setting; pattern = MTKSPPForMMI;
        memset(SPPClientFirstConnDataPattern,0,20);
        SPPClientFirstConnDataPatternLen = strlen("MTKSPPForMMI");
        memcpy(SPPClientFirstConnDataPattern,"MTKSPPForMMI",SPPClientFirstConnDataPatternLen); 
        
    }
    *len = SPPClientFirstConnDataPatternLen; 
    return SPPClientFirstConnDataPattern;
}

#endif

#if defined(__BTMTK__)
kal_uint8 BT_MODULE_ID = 3;
#else
kal_uint8 BT_MODULE_ID = 0;
#endif

#if defined (__BTMODULE_RFMD3500__)
typedef  struct {
	unsigned char num_powronBT;
	unsigned char pol_powronBT;
	unsigned char num_gsm2bt;
	unsigned char pol_gsm2bt;
	unsigned char num_bt2gsm;
	unsigned char pol_bt2gsm;
	unsigned char num_lpoclk;
	unsigned char mode_lpoclk;
	unsigned char num_urxd3;
	unsigned char num_utxd3;
	unsigned char num_ucts3;
	unsigned char num_urts3;
	unsigned char num_pcmclk;
	unsigned char num_pcmsync;
	unsigned char num_pcmout;
	unsigned char num_pcmin;
} sGPIO4BT;

#ifdef __CUST_NEW__
extern const char gpio_bt_power_pin;
extern const char gpio_bt_wakeup_pin;
extern const char gpio_bt_32k_pin;
extern const char gpio_bt_utxd3_pin;
extern const char gpio_bt_urxd3_pin;
extern const char gpio_bt_ucts3_pin;
extern const char gpio_bt_urts3_pin;
extern const char gpio_bt_pcmclk_pin;
extern const char gpio_bt_pcmsync_pin;
extern const char gpio_bt_pcmin_pin;
extern const char gpio_bt_pcmout_pin;
#endif

extern const unsigned char bt_gpio_setting[16];

extern void GPIO_WriteIO(char, char);

void BtRadio_AssignGpioPins(sGPIO4BT *gpio)
{
 #ifdef __CUST_NEW__
       if (bt_gpio_setting[0] != 0xFF)
           gpio->num_powronBT = gpio_bt_power_pin; // power_on_pin;
       else
           gpio->num_powronBT = bt_gpio_setting[0]; // power_on_pin;
       gpio->num_gsm2bt   = gpio_bt_wakeup_pin; // bt_reset_pin;
       gpio->num_urxd3    = gpio_bt_urxd3_pin; // urxd3_pin;
       gpio->num_utxd3    = gpio_bt_utxd3_pin; // utxd3_pin;
       if(bt_gpio_setting[8]!=0xFF)
       {
           gpio->num_ucts3    = gpio_bt_ucts3_pin; // ucts3_pin;
           gpio->num_urts3    = gpio_bt_urts3_pin; // urts3_pin;
       }
       else
       {
           gpio->num_ucts3    = bt_gpio_setting[8]; // ucts3_pin;
           gpio->num_urts3    = bt_gpio_setting[9]; // urts3_pin;
       }
       if((bt_gpio_setting[10]!=0xFF) || (bt_gpio_setting[11]!=0xFF))
       {
           gpio->num_lpoclk   = gpio_bt_32k_pin; // lpoclk_pin
       }
	else
	{
           gpio->num_lpoclk   = bt_gpio_setting[10]; // lpoclk_pin;
	}
       if(bt_gpio_setting[12]>0)
       {
           gpio->num_pcmclk   = gpio_bt_pcmclk_pin; // pcmclk_pin;
           gpio->num_pcmsync  = gpio_bt_pcmsync_pin; // pcmsync_pin;
           gpio->num_pcmout   = gpio_bt_pcmout_pin; // pcmout_pin;
           gpio->num_pcmin    = gpio_bt_pcmin_pin; // pcmin_pin;
       }
       else
       {
           gpio->num_pcmclk   = bt_gpio_setting[12]; // pcmclk_pin;
           gpio->num_pcmsync  = bt_gpio_setting[13]; // pcmsync_pin;
           gpio->num_pcmout   = bt_gpio_setting[14]; // pcmout_pin;
           gpio->num_pcmin    = bt_gpio_setting[15]; // pcmin_pin;
       }
 #else
       gpio->num_powronBT = bt_gpio_setting[0]; // power_on_pin;
       gpio->num_gsm2bt   = bt_gpio_setting[2]; // bt_reset_pin;
       gpio->num_urxd3    = bt_gpio_setting[6]; // urxd3_pin;
       gpio->num_utxd3    = bt_gpio_setting[7]; // utxd3_pin;
       gpio->num_ucts3    = bt_gpio_setting[8]; // ucts3_pin;
       gpio->num_urts3    = bt_gpio_setting[9]; // urts3_pin;
       gpio->num_lpoclk   = bt_gpio_setting[10]; // lpoclk_pin
       gpio->mode_lpoclk  = bt_gpio_setting[11]; // lpoclk_mode
       gpio->num_pcmclk   = bt_gpio_setting[12]; // pcmclk_pin;
       gpio->num_pcmsync  = bt_gpio_setting[13]; // pcmsync_pin;
       gpio->num_pcmout   = bt_gpio_setting[14]; // pcmout_pin;
       gpio->num_pcmin    = bt_gpio_setting[15]; // pcmin_pin;
 #endif
}

void BtRadio_PowerOn(kal_uint8 polBT, kal_uint8 numBT)
{
	volatile int n;
	n = 500000;
       if (numBT == 0xFF)
       {
#if (defined(MT6318))
           pmic_vmc_enable(KAL_FALSE);
           while(n)  n--;
           pmic_vmc_sel(VMC_2_8V);
           pmic_vmc_enable(KAL_TRUE);
#endif
       }
       else
       {
           GPIO_WriteIO(1-polBT, numBT);  // turn on BT regulator
           while(n)  n--;
           GPIO_WriteIO(polBT, numBT);  // turn on BT regulator
       }
}

void BtRadio_PowerOff(kal_uint8 polBT, kal_uint8 numBT)
{
        if (numBT == 0xFF)
        {
#if (defined(MT6318))
            pmic_vmc_enable(KAL_FALSE);
#endif
        }
        else
            GPIO_WriteIO(1-polBT, numBT);  // turn off BT regulator
}

kal_uint8* BtGet_SPPClientFirstConnDataPattern(kal_uint8* len)
{
    if(SPPClientFirstConnDataPatternLen == 0)
    {
        //Using default setting; pattern = MTKSPPForMMI;
        memset(SPPClientFirstConnDataPattern,0,20);
        SPPClientFirstConnDataPatternLen = strlen("MTKSPPForMMI");
        memcpy(SPPClientFirstConnDataPattern,"MTKSPPForMMI",SPPClientFirstConnDataPatternLen); 
        
    }
    *len = SPPClientFirstConnDataPatternLen; 
    return SPPClientFirstConnDataPattern;
}
#endif

