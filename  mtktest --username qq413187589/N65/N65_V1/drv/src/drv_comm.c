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
 *    drv_comm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines driver common functions.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "stack_config.h"
#include "rtc_hw.h"
#include "reg_base.h"
#include "bmd.h"
#include "uart_sw.h"
#include "keypad_sw.h"
#include "gpt_sw.h"
#include "bmt.h"
#include "msdc_def.h"
#include "eint.h"
#if defined(MOTION_SENSOR_SUPPORT)
#include "motion_sensor.h"
#endif /* MOTION_SENSOR_SUPPORT */
#ifdef __SWDBG_SUPPORT__
#include "swdbg_sw.h"
#endif   /* __SWDBG_SUPPORT__ */

#ifdef __MTK_TARGET__
   #include "rtc_sw.h"
   #include "syscomp_config.h"
#ifdef __MULTI_BOOT__
   #include "multiboot_config.h"
   #include "fctycomp_config.h"
#ifdef __USB_ENABLE__
   #include "usbmscomp_config.h" 
#endif /* __USB_ENABLE__ */
#endif /* __MULTI_BOOT__ */
#endif /* __MTK_TARGET__ */
#if (defined(ISP_SUPPORT))
#include "image_sensor.h"
#endif
#include    "pwic.h"

extern void drv_hisr_init(void);
extern void DRVPDN_ini(void);
extern void UART_HWInit(UART_PORT port);
extern void GPTI_init(void);
extern void DMA_Ini(void);
extern void Kbd_Init(void);
#if defined(RTC_HW_CALIBRATION)
extern void RTC_HW_Init(void);
#endif /* RTC_HW_CALIBRATION */
extern void RTC_init(void (*RTC_TCCallback)(void),void (*RTC_ALCallback)(void));
extern void RTC_TCintr(void);
extern void RTC_ALintr(void);
extern void WDT_init(void);
extern void PW_PowerInit(void);
extern void ADC_Init(void);
extern void custom_drv_init(void);
extern void EINT_SW_Debounce_Init(void);
extern void GCU_Disable_ReverseBit(void);
extern void USB2UART_init(void);
extern void Visual_Init(void);
extern void che_hw_init(void);
extern void lpwr_init(void);
extern void lcd_system_init(void);
extern void i2c_init(void);
#ifdef __DMA_UART_VIRTUAL_FIFO__
extern void DMA_Vfifo_init(void);
#endif
#ifdef __WIFI_SUPPORT__
extern void wndrv_HWinit(void);
#endif
extern void custom_drv_deinit(void);
#ifdef DRV_PWM_RWG
extern void PWM_Init(void);
#endif
/*
extern void GPTI_BusyWait(kal_uint16 len);
extern kal_uint16 Custom_Keypress_Period ;
*/
extern BMTStruct BMT;          /*Main BMT struct*/

boot_mode_type system_boot_mode = UNKNOWN_BOOT_MODE;
extern kal_uint16 INT_BootMode(void);
extern kal_bool INT_USBBoot(void);

#ifdef IC_MODULE_TEST
   extern void IC_ModuleTest_Start(void);
#endif   /*IC_MODULE_TEST*/

typedef void (* MEMCPY_FUNC)(const void *srcaddr, void *dstaddr, kal_uint32 len);
#ifdef DRV_MISC_DMA_NO_MEMCPY
   void (* DRV_MEMCPY)(const void *srcaddr, void *dstaddr, kal_uint32 len);
#elif defined(DRV_MISC_DMA_MEMCPY)
   extern kal_bool DMA_memcpy(const void *src, const void *dst, kal_uint32 length);
   void (* DRV_MEMCPY_PTR)(const void *srcaddr, void *dstaddr, kal_uint32 len);
   void DRV_MEMCPY(const void *srcaddr, void *dstaddr, kal_uint32 len);
#endif   /**/

#ifdef __IRDA_SUPPORT__
/*TY adds this 2004/10/27*/   
extern UartDriver_strcut ircomm_uart_api;
#endif
#if defined(__BTMTK__)
extern UartDriver_strcut sppa_uart_api;
extern void bchs_host_controller_power_off(void);
#elif defined __CMUX_SUPPORT__
extern UartDriver_strcut cmux_uart_api;
#endif

#ifdef __SWDBG_SUPPORT__
extern kal_uint8 SWDBG_Profile;
#endif  /* _SWDBG_SUPPORT__ */

#ifdef  __BTMODULE_MT6601__
extern void BT_Radio_Shutdown(void);
#endif
/* 2009.04.14 added by hongzhe.liu for motion sensor + */
#if (defined(__DIRECTION_SENSOR_SUPPORT__))
extern kal_uint8  gMotionSensor_EINT_NO1;
extern kal_uint8  gMotionSensor_EINT_NO2;
#endif
/* 2009.04.14 added by hongzhe.liu for motion sensor - */
/*To get all customized data*/
void Drv_Customize_Init(void)
{
	extern bmt_customized_struct *bmt_charing_para;
	extern kal_uint8 gCHRDET_EINT_NO;
   #if defined(__USB_ENABLE__)
	extern kal_uint8 gUSB_EINT_NO;
   #endif

   uart_customize_init();
   keypad_customize_init();
   bmt_charing_para=bmt_get_customized_chr_para();
#if defined(PMIC_FIXED_CHR_EINT)
   gCHRDET_EINT_NO = PMIC_CHR_EINT_PIN;
#else
   gCHRDET_EINT_NO = custom_eint_get_channel(chrdet_eint_chann);
#endif
   
   #if defined(__USB_ENABLE__)
   gUSB_EINT_NO = custom_eint_get_channel(usb_eint_chann);
   #endif
   
   #ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
#if defined(PMIC_FIXED_CHR_EINT)
   chr_usb_detect.chr_usb_eint = PMIC_CHR_EINT_PIN;
#else
   chr_usb_detect.chr_usb_eint = custom_eint_get_channel(chr_usb_eint_chann);
#endif
   chr_usb_detect.chr_usb_adc = custom_adc_get_channel(chr_usb_adc_channel);
   chr_usb_detect.chr_usb_volt = bmt_get_chr_usb_detect_volt();
   #endif
/* 2009.04.14 added by hongzhe.liu for motion sensor + */
/********************add motion sensor**********************/
#if (defined(__DIRECTION_SENSOR_SUPPORT__))
   gMotionSensor_EINT_NO1 = custom_eint_get_channel(motion_senosr_eint1_chann);
   gMotionSensor_EINT_NO2 = custom_eint_get_channel(motion_senosr_eint2_chann);
   #endif
/******************************end************************/
/* 2009.04.14 added by hongzhe.liu for motion sensor - */
   
}   

/*************************************************************************
* FUNCTION
*   Drv_query_boot_mode
*
* DESCRIPTION
*   Return boot mode.
*
* PARAMETERS
*
* RETURNS
*   FACTORY_BOOT, NORMAL_BOOT and USBMS_BOOT
*
* GLOBALS AFFECTED
*
*************************************************************************/
boot_mode_type Drv_query_boot_mode(void)
{
	
#ifdef __MULTI_BOOT__

   if( INT_BootMode() == MTK_FACTORY_MODE )
      return FACTORY_BOOT;
   
#ifdef __USB_ENABLE__

   if( INT_USBBoot() == KAL_TRUE )
      return USBMS_BOOT;
      
#endif /* __USB_ENABLE__ */   

#endif /* __MULTI_BOOT__ */   

   return NORMAL_BOOT;
}



/*
* FUNCTION
*  Drv_Init_Phase1
*
* DESCRIPTION
*     This function is the NFB phase1 (Primary ROM) initial function for 
*     all device drivers.
*     This function is called once to initialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*
* NOTE XXX
*   All sub functions reference by this function should be placed on 
*   Primary ROM for NFB projects. Or it cannot boot up because Drv_Init()
*   executed before Secondary ROM loaded.
*   Please make sure all sub-functions under custom.lib that referenced by
*   Drv_Init() list in NFB scatter file.
*/

void Drv_Init_Phase1(void)
{
   drv_hisr_init();
   lpwr_init();
   DRVPDN_ini();
#ifdef DRV_PWM_RWG
   PWM_Init();
#endif
   /*To get all customized data*/
   Drv_Customize_Init();
   custom_drv_init();
   #if defined(DRV_GPT_GPT3)
   /*turn on gpt3 to count powen on period*/
   GPT3_Init();
   GPT_Start(3);   
   #endif
   
   #if !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)
      #if ( (defined(MULTIMEDIA_INIT_MT6217_SERIES)) || (defined(MULTIMEDIA_INIT_MT6219_SERIES))  )
      Visual_Init();
      #endif   /*MULTIMEDIA_INIT_MT6217_SERIES, MULTIMEDIA_INIT_MT6219_SERIES*/
   #endif /*!defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)*/
   
#if defined(DRV_TIMING_DEBUG) && defined(DRV_GPT_6218B_GPT3_TIMING_DEBUG)
   DRV_WriteReg(0x8010001c,1);
   DRV_WriteReg(0x80100024,0x04);
   //DRV_WriteReg(0x80100024,1); // (1/16K)
#endif

   #ifdef DRV_MISC_DMA_NO_MEMCPY
      DRV_MEMCPY = (MEMCPY_FUNC)0x48000150;
   #elif defined(DRV_MISC_DMA_MEMCPY)
      DRV_MEMCPY_PTR = (MEMCPY_FUNC)0x48000134;
   #endif
   
   GPTI_init();
   WDT_init();
   DMA_Ini();
   ADC_Init();
   lcd_system_init();
#ifdef DRV_RTC_HW_CALI
   RTC_HW_Init();
#endif
#ifndef __L1_STANDALONE__
   #ifdef PMIC_PRESENT
      pmic_adpt_init();
      PW_PowerInit();
#if defined(__DRV_NO_USB_CHARGER__)
      DRV_POWERON();
#endif
/*
	if(BMT.PWRon == PWRKEYPWRON)
		GPTI_BusyWait(Custom_Keypress_Period);
*/
   #else
      #ifdef __USB_ENABLE__
      {
			extern charger_usb_present_enum PW_is_charger_usb_present(void);

			switch (PW_is_charger_usb_present())
			{
			case CHARGER_PRESENT:				
				break;
#if defined(__CHINA_CHARGER_STANDARD__)
			case CHARGER_PRESENT_NON:       //non-standard china charger				
				break;
#endif
			case USB_PRESENT:
				BMT.PWRon = USBPWRON;
				break;
			case NO_PRESENT:
				break;
         } 
      }
      #endif   /*__USB_ENABLE__*/
      DRV_POWERON();
   #endif   /*PMIC_PRESENT*/
#else /*__L1_STANDALONE__*/
   DRV_POWERON();
#endif   /*__L1_STANDALONE__*/

	/* update the system boot mode */
	system_boot_mode = Drv_query_boot_mode();
	
#ifdef __DMA_UART_VIRTUAL_FIFO__
	DMA_Vfifo_init();
#endif
   UART_HWInit(uart_port1);
   #ifdef __DMA_UART_VIRTUAL_FIFO__	  
   
   if(UART_VFIFO_support[uart_port1])
      UART_Register(uart_port1,UART_TYPE,&UartDriver_VFIFO);
   else 
      UART_Register(uart_port1,UART_TYPE,&UartDriver);
   
   if(UART_VFIFO_support[uart_port2])
      UART_Register(uart_port2,UART_TYPE,&UartDriver_VFIFO);
   else
      UART_Register(uart_port2,UART_TYPE,&UartDriver);         
   #else
	UART_Register(uart_port1,UART_TYPE,&UartDriver);
   UART_Register(uart_port2,UART_TYPE,&UartDriver);         
   #endif   
   UART_Open(uart_port1,MOD_UART1_HISR);
   /*TY adds these to expand flexibility 2004/10/15*/
   UART_Register_TX_cb(uart_port1, MOD_UART1_HISR, UART_dafault_tx_cb);
   UART_Register_RX_cb(uart_port1, MOD_UART1_HISR, UART_dafault_rx_cb);
   UART_HWInit(uart_port2);
   
   UART_Open(uart_port2,MOD_UART2_HISR);
   /*TY adds these to expand flexibility 2004/10/15*/
   UART_Register_TX_cb(uart_port2, MOD_UART2_HISR, UART_dafault_tx_cb);
   UART_Register_RX_cb(uart_port2, MOD_UART2_HISR, UART_dafault_rx_cb);
   
// if platform is designed to use uart3, pls define it, default setting is turned off.    
#ifdef __UART3_SUPPORT__		 
   UART_HWInit(uart_port3);
	//UART_Register(uart_port3,UART_TYPE,&UartDriver);
	#ifdef __DMA_UART_VIRTUAL_FIFO__	  
	if(UART_VFIFO_support[uart_port3])
      UART_Register(uart_port3,UART_TYPE,&UartDriver_VFIFO);
   else
	UART_Register(uart_port3,UART_TYPE,&UartDriver);
   #else
	UART_Register(uart_port3,UART_TYPE,&UartDriver);
   #endif   
   UART_Open(uart_port3,MOD_UART3_HISR);
   /*TY adds these to expand flexibility 2004/10/15*/
   UART_Register_TX_cb(uart_port3, MOD_UART3_HISR, UART_dafault_tx_cb);
   UART_Register_RX_cb(uart_port3, MOD_UART3_HISR, UART_dafault_rx_cb);
#endif   /*__UART3_SUPPORT__*/

}



#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
extern TLG1100_PowerOff(void);
extern void AnalogTV_PowerOff_CloseLeakage(void);
extern void PowerOnForDevices(void) ;
extern void PowerOffForDevices(void);
#endif

/*
* FUNCTION
*  Drv_Init_Phase2
*
* DESCRIPTION
*     This function is the NFB phase2 (Secondary ROM) initial function for 
*     all device drivers.
*     This function is called once to initialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*
* NOTE XXX
*   All sub functions reference by this function should be placed on 
*   Secondary ROM for NFB projects. 
*/
void Drv_Init_Phase2(void)
{
#ifdef __SWDBG_SUPPORT__

   UART_Register(uart_port_swdbg, UART_TYPE, (UartDriver_strcut *)&swdbgdrv);

#endif   /* __SWDBG_SUPPORT__ */

#ifdef __USB_ENABLE__
   USB2UART_init();
#endif   /*__USB_ENABLE__*/

#ifdef __IRDA_SUPPORT__
   /*TY adds this 2004/10/27*/   
   /* Register UART API */
   UART_Register(uart_port_irda, IRDA_TYPE, &ircomm_uart_api);
#endif   
#if defined(__BTMTK__)
{
	kal_uint8 i;
	for(i = start_of_virtual_port; i < end_of_virtual_port + 1; i++)
		UART_Register(i, IRDA_TYPE, &sppa_uart_api);
}
#elif defined __CMUX_SUPPORT__
{
	kal_uint8 i;
	for(i = start_of_virtual_port; i < end_of_virtual_port + 1; i++)
		UART_Register(i, IRDA_TYPE, &cmux_uart_api);

}
#endif
   Kbd_Init();
   RTC_init(RTC_TCintr,RTC_ALintr);
   
#ifdef DRV_MULTIPLE_SIM
   sim_MT6302_init();
 #endif
 
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined (__MSDC_MSPRO__))   
   MSDC_Initialize();
   
	#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
	MSDC_Initialize2();
	#endif
#endif   
   
#ifdef IC_MODULE_TEST
   IC_ModuleTest_Start();
#endif   /*IC_MODULE_TEST*/

   EINT_SW_Debounce_Init();
#ifdef MT6218B/*only 6218B has this */   
   GCU_Disable_ReverseBit();
#endif   
#ifdef __SWDBG_SUPPORT__

   /* initialize SWDBG */
   swdbg_init();

#endif   /* __SWDBG_SUPPORT__ */
   
   /* Cipher/Hash engine initialize */
   che_hw_init();

#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It For Power 
PowerOnForDevices();
#endif
/* ISP/Camera initialize */  
#if (defined(ISP_SUPPORT))
cis_module_power_on(KAL_FALSE); 
#endif
#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
PowerOffForDevices();
//TLG1100_PowerOff();
#endif

#if defined(MOTION_SENSOR_SUPPORT)
   motion_sensor_init();
#endif   
#ifdef __WIFI_SUPPORT__
   wndrv_HWinit();
#endif

//#if (defined(_USE_SCCB_V2_DRIVER_))
#if defined(DRV_I2C_25_SERIES)
i2c_init();
#endif

}

/*
* FUNCTION
*  Drv_Deinit
*
* DESCRIPTION
*     This function is the deinitial function for all device drivers.
*     This function is called once to deinitialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void Drv_Deinit(void)
{
   /* Don't do driver deinit when still in system initialization stage. 
      Otherwise it may cause problem in NFI booting. */
   if (KAL_FALSE == kal_query_systemInit())
   {
      custom_drv_deinit();
#ifdef  __BTMODULE_MT6601__
      BT_Radio_Shutdown();
#endif
   }
}

#if defined(DRV_MISC_DMA_MEMCPY)
void DRV_MEMCPY(const void *srcaddr, void *dstaddr, kal_uint32 len)
{
   if (!DMA_memcpy(srcaddr,dstaddr,len))
      DRV_MEMCPY_PTR(srcaddr,dstaddr,len);
}
#endif   /*DRV_MISC_DMA_MEMCPY*/


kal_bool Drv_WriteReg(kal_uint32 addr, kal_uint16 data)
{
   if (addr < 0x70000000)
      return KAL_FALSE;
  
   DRV_WriteReg(addr,data);
   return KAL_TRUE;
}

kal_bool Drv_ReadReg(kal_uint32 addr, kal_uint16 *data)
{
   if (addr < 0x70000000)
      return KAL_FALSE;
      
   *data = DRV_Reg(addr);
   return KAL_TRUE;
}

kal_uint32 drv_get_current_time(void)
{
#if defined(DRV_MISC_TDMA_NO_TIME)
   ASSERT(0);
#endif   /*DRV_MISC_TDMA_NO_TIME*/

#if defined(DRV_MISC_TDMA_TIME_BASE_8200)
	return (DRV_Reg32(0x82000230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8020)
	return (DRV_Reg32(0x80200230));
#endif

}

kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
	kal_uint32 result;
#if defined(DRV_MISC_TDMA_NO_TIME)
   ASSERT(0);
#endif   /*DRV_MISC_TDMA_NO_TIME*/

	if (previous_time > current_time)
	{
//#if defined(DRV_MISC_TDMA_TIME_MAX_80000)
#if defined(DRV_MISC_TDMA_TIME_MAX_19BITS)
		result = 0x80000 - previous_time + current_time;
#elif defined(DRV_MISC_TDMA_TIME_MAX_24BITS)
      result = 0x1000000 - previous_time + current_time;
#endif
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
}

kal_uint32 drv_get_duration_ms(kal_uint32 previous_time)
{
	kal_uint32 result;
	kal_uint32 current_time;
	
	current_time = drv_get_current_time();
	result = drv_get_duration_tick(previous_time, current_time);
	result*=1000;
	result/=32768;
	return result;
}

#ifdef DRV_TIMING_DEBUG
DRV_DBG_STRUCT  DRV_DBG_INFO_DATA;

kal_uint32 drv_get_gpt_current_time(void)
{
   //0x80100020, enable!!
   #if defined(DRV_GPT_GPT3)
	return (DRV_Reg32(0x80100020));
	#else /*DRV_GPT_GPT3*/
	return (DRV_Reg32(0x80200230));
	#endif   /*DRV_GPT_GPT3*/
}

kal_uint32 drv_get_gpt_duration_tick(kal_uint32 previous_time)
{
   #if defined(DRV_GPT_GPT3)
   kal_uint32 current_time = DRV_Reg32(0x80100020);
	kal_uint32 result;
	
	if (previous_time > current_time)
	{
		result = 0x10000 - previous_time + current_time;
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
	#else /*DRV_GPT_GPT3*/
	kal_uint32 current_time = DRV_Reg32(0x80200230);
	kal_uint32 result;
	if (previous_time > current_time)
	{
		result = 0x80000 - previous_time + current_time;
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
	#endif   /*DRV_GPT_GPT3*/
}

kal_uint32 drv_get_gpt_duration_ms(kal_uint32 previous_time)
{
   #if defined(DRV_GPT_GPT3)
	kal_uint32 result;
	result = drv_get_duration_tick(previous_time);
	return result;
	#else /*DRV_GPT_GPT3*/
	kal_uint32 result;
	result = drv_get_duration_tick(previous_time);
	result*=1000;
	result/=32768;
	return result;
	#endif   /*DRV_GPT_GPT3*/
}
#endif  /*DRV_TIMING_DEBUG*/

#ifdef DRV_MEMORY_TRACE_DEBUG
DRV_DBG_STRUCT DRV_DBG_INFO_DATA;
/*drv_dbg_trace(NAND_READ_START,drv_get_current_time(),0,0);*/
void drv_dbg_trace(kal_uint16 index, kal_uint32 time, kal_uint32 data1, kal_uint32 data2)
{
   kal_uint32        savedMask;
   savedMask = SaveAndSetIRQMask();
   {
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].tag = index;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].time = time;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].data1 = data1;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].data2 = data2;
      DRV_DBG_INFO_DATA.dbg_data_idx++;
   }
   RestoreIRQMask(savedMask);
}
#endif   /*DRV_MEMORY_TRACE_DEBUG*/

/*************************************************************************
   APIs for driver debugging 
*************************************************************************/
#if (!defined(MTK_KAL_MNT))&&(!defined(KAL_ON_OSCAR))&&(!defined(MCD_DLL_EXPORT))&&(!defined(L1_SIM))
void drv_trace0(kal_int32 trc_class, kal_uint32 msg_index, const char *arg_type)
{
   ASSERT(kal_if_lisr() == KAL_FALSE);
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type);
   }
}

void drv_trace1(kal_int32 trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1)
{
   ASSERT(kal_if_lisr() == KAL_FALSE);
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type, data1);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type, data1);
   }
}

void drv_trace2(kal_int32 trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2)
{
   ASSERT(kal_if_lisr() == KAL_FALSE);
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type, data1, data2);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type, data1, data2);
   }
}

void drv_trace4(kal_int32 trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4)
{
   ASSERT(kal_if_lisr() == KAL_FALSE);
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type, data1, data2, data3, data4);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type, data1, data2, data3, data4);
   }
}

void drv_trace8(kal_int32 trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4,
                kal_uint32 data5, kal_uint32 data6, kal_uint32 data7, kal_uint32 data8)
{
   ASSERT(kal_if_lisr() == KAL_FALSE);
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type, data1, data2, data3, data4, data5, data6, data7, data8);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type, data1, data2, data3, data4, data5, data6, data7, data8);
   }
}
#endif /* (!defined(MTK_KAL_MNT))&&(!defined(KAL_ON_OSCAR))&&(!defined(MCD_DLL_EXPORT))&&(!defined(L1_SIM))*/
