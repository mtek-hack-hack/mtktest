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
 *    pwic.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines PWIC driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include    "drv_features.h"
#include    "drv_comm.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include    "app_buff_alloc.h"   /*buffer*/
#include    "stack_timer.h"     /*Timer*/
#include    "reg_base.h"
#include    "gpio_hw.h"
#include    "gpio_sw.h"
#include    "rtc_hw.h"
#include    "rtc_sw.h"
#include    "pwic.h"
#include    "intrCtrl.h"
#include    "adc.h"
#include    "bmt.h"
#include    "keypad_hw.h"
#include    "keypad_sw.h"
#include    "eint.h"
#include    "batvalue.h"
#include    "custom_hw_default.h"
#include		"drvsignals.h"
#ifdef __MULTI_BOOT__
#include "kal_release.h"
   #include "syscomp_config.h"
   #include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/
#include    "b2psi_sw.h"
#include 	"pmic6318_sw.h"
#if defined(MT6223PMU)
#include "pmu_sw.h"
#endif

#if !defined(__FUE__)
   extern BMTStruct BMT;          /*Main BMT struct*/

   extern kal_bool  WDT_RST;

   #if defined(__USB_ENABLE__)
   kal_uint8 gUSB_EINT_NO;
   #endif
   kal_uint8 gCHRDET_EINT_NO;

   #ifdef __CUST_NEW__
   #if defined(DRV_MISC_CHR_CTRL_GPIO)
      #if (!defined(MT6318))&&(!defined(MT6223PMU))&&(!defined(MT6238PMU))
   extern const char gpio_bmt_chr_ctrl_pin;
   #endif
      #endif /* DRV_MISC_CHR_CTRL_GPIO */
   #endif /* __CUST_NEW__ */
   #if defined(MT6318)
      extern pmic_chrdect_callbac_struct PMIC_CHRDET;
   #endif
#endif /*!defined(__FUE__)*/

extern void RTC_setBBPU(kal_uint16 data);
#if !defined(__FUE__)
   extern void DRV_RESET(void);
   #ifndef L1_NOT_PRESENT
   extern void L1T_Exit(void);
   #endif /* L1_NOT_PRESENT */
   extern void EINT_Mask(kal_uint8 eintno);
   extern void GPIO_WriteIO(char data, char port);
   extern void BMT_sendMes(module_type srcid, msg_type msgid);
   extern kal_uint32 VOL_RESULT[ADC_MAX_CHANNEL];
   extern void EINT_UnMask(kal_uint8 eintno);
   extern void bmt_set_chr_status(Charger_Status status);
   extern void Drv_Deinit(void);
   extern void USB_PowerControl(kal_bool enable);
   extern void adc_sche_add_item(kal_uint8 adc_sche_id, void (*mea_complete)(kal_uint8 adc_sche_id), kal_timer_func_ptr mea_Callback);
   extern void adc_sche_remove_item(kal_uint8 adc_sche_id);
   extern kal_uint8 adc_sche_create_object(module_type ownerid, kal_uint8 adc_channel,kal_uint32 period, kal_uint8 evaluate_count, kal_bool send_primitive);

   void CHRDET_HISR(void);
   void chrdet_level_config(kal_uint8 state);
#endif /*!defined(__FUE__)*/

#if !defined(__FUE__)
#if defined(DRV_MISC_TDMA_32K_CALI)
#define  SM_CTRL                 (TDMA_base+0x218)
#define  SM_STAT                 (TDMA_base+0x21c)
#define  SM_FMDURATION           (TDMA_base+0x220)
#define  SM_FM_RESULT_LOW        (TDMA_base+0x228)
#define  SM_FM_RESULT_HIGH       (TDMA_base+0x224)
#define  SM_CTRL_FM_START        0x0001
#define  SM_STAT_FM_RDY          0x0002
#define  SM_FM_RESULT_HIGH_MASK  0x03ff
kal_uint32 wait_32k_count = 80000;

/*
* FUNCTION
*	wait_32k_start
*
* DESCRIPTION                                                           
*   	This function use 13M to calibrate 32k clock
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
void wait_32k_start(void)
{
   kal_uint32 result;
   kal_uint16 result_low;
   kal_uint16 result_high;
   kal_uint32 count;

   DRV_Reg(DRVPDN_CON2) &= ~DRVPDN_CON2_TDMA;   
   DRV_WriteReg(SM_FMDURATION,0);
       
   count = 0;
   while(count < wait_32k_count)
   {
      DRV_Reg(SM_CTRL) |= SM_CTRL_FM_START;
      while(!(DRV_Reg(SM_STAT) & SM_STAT_FM_RDY));
      result_low = DRV_Reg(SM_FM_RESULT_LOW);
      result_high = DRV_Reg(SM_FM_RESULT_HIGH) & SM_FM_RESULT_HIGH_MASK;
      result = (result_low | (result_high << 16));
      if ((result < 950) && (result > 650))
         break;
      count++;
   }
   DRV_Reg(DRVPDN_CON2) |= DRVPDN_CON2_TDMA;
}
#endif   /*DRV_MISC_TDMA_32K_CALI*/
/*
* FUNCTION
*	   bmt_is_wdt_power
*
* DESCRIPTION                                                           
*   	This function is to check if phone is power on because WDT.
*
* CALLS  
*
* PARAMETERS
*	  None
*	
* RETURNS
*	   
*
* GLOBALS AFFECTED
*     None
*/
kal_bool is_wdt_power=KAL_FALSE;
kal_bool bmt_is_wdt_power(void)
{
   return is_wdt_power;
}
/*
* FUNCTION
*	   bmt_is_chr_exist
*
* DESCRIPTION                                                           
*   	This function is to check if AC/USB exists at CHRPWRON/USBPWRON
*
* CALLS  
*
* PARAMETERS
*	  power_on: power on type
*	
* RETURNS
*	   
*
* GLOBALS AFFECTED
*     None
*/

kal_bool bmt_is_chr_exist(kal_uint8 power_on)
{
      
   #if defined(MT6305)  
   kal_uint8 eint=0;
   kal_uint32 delay=0;      
   kal_uint16 status=0;
   
      #if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
         eint = chr_usb_detect.chr_usb_eint;
      #else
         kal_bool  usb_eint_mask = KAL_TRUE;

         if(power_on==CHRPWRON||power_on==PRECHRPWRON)  
            eint=gCHRDET_EINT_NO;
         #if defined(__USB_ENABLE__)   
         else if(power_on==USBPWRON||power_on==USBPWRON_WDT) 
            eint=gUSB_EINT_NO;
         #endif         
      #endif
      #ifdef _USB_VBUS_DETECT_WITH_NIRQ_
      /* For USB using NIRQ, we just return KAL_TRUE. 
         It's too risky and tricky to peek on NIRQ status. */
      if (power_on==USBPWRON||power_on==USBPWRON_WDT)
      {
         return KAL_TRUE;
      }
      else
      {
      #endif /* _USB_VBUS_DETECT_WITH_NIRQ_ */
      IRQMask(IRQ_EIT_CODE);
      #if defined(__USB_ENABLE__) && !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
         /* To check if USB EINT has been unmasked by USB task. ie, record the mask state*/
         if ((eint==gUSB_EINT_NO) &&  (!((*EINT_MASK) & EINT_MASK_EINT(eint)) ) )
               usb_eint_mask = KAL_FALSE;
      #endif
      *EINT_MASK &= (kal_uint16)(~EINT_MASK_EINT(eint));   
      EINTaddr(eint) = EINT_CON_HIGHLEVEL;    
      *EINT_INTACK = EINT_INTACK_EINT(eint);
      for(delay=0;delay<500;delay++);
      status = *EINT_STATUS;
      #if defined(__USB_ENABLE__) && !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
      /* Determine if the USB EINT should be masked. */
      if (usb_eint_mask == KAL_TRUE)
      #endif
      EINT_Mask(eint);
      *EINT_INTACK = EINT_INTACK_EINT(eint);   
      IRQClearInt(IRQ_EIT_CODE);
      IRQUnmask(IRQ_EIT_CODE);   
      if (status & EINT_STATUS_EINT(eint))
         return KAL_TRUE;
      else
         return KAL_FALSE;      
      #ifdef _USB_VBUS_DETECT_WITH_NIRQ_
      }
      #endif /* _USB_VBUS_DETECT_WITH_NIRQ_ */
         
   #elif defined(MT6318)/*XXXXX*/

      #if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
         kal_bool status=KAL_FALSE;         
         #if !defined(__USB_ENABLE__)   
         if(power_on==CHRPWRON||power_on==PRECHRPWRON)  
         #else
         if(power_on==CHRPWRON||power_on==PRECHRPWRON||
            power_on==USBPWRON||power_on==USBPWRON_WDT) 
         #endif
            status=pmic_is_chr_det(AC_CHR);    
         return status;         
      #else
      kal_bool status=KAL_FALSE;
      //eint = chr_usb_detect.chr_usb_eint;
      if(power_on==CHRPWRON||power_on==PRECHRPWRON)  
         status=pmic_is_chr_det(AC_CHR); 
      #if defined(__USB_ENABLE__)   
      else if(power_on==USBPWRON||power_on==USBPWRON_WDT) 
         status=pmic_is_chr_det(USB_CHR); 
      #endif               
      
      return status;
      #endif/*one EINT*/
   #elif defined(MT6223PMU)
      kal_bool status;

      status = pmu_is_chr_det();
      return status;
   #elif defined(MT6238PMU) /*XXXXX*/
      #if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
         kal_bool status=KAL_FALSE;         
         if(power_on==CHRPWRON||power_on==PRECHRPWRON||
            power_on==USBPWRON||power_on==USBPWRON_WDT) 
            status = pmu_is_chr_det();
         return status;         
      #else /*__CHARGER_USB_DETECT_WIHT_ONE_EINT__*/
         kal_bool status=KAL_FALSE;
         //eint = chr_usb_detect.chr_usb_eint;
         if(power_on==CHRPWRON||power_on==PRECHRPWRON)  
            status = pmu_is_chr_det(); 
         #if defined(__USB_ENABLE__)   
         else if(power_on==USBPWRON||power_on==USBPWRON_WDT)
         {
            kal_uint8 eint=0;
            kal_uint32 delay=0;
            kal_uint16 reg_value=0;

            eint=gUSB_EINT_NO;
            IRQMask(IRQ_EIT_CODE);
            *EINT_MASK &= (kal_uint16)(~EINT_MASK_EINT(eint));   
            EINTaddr(eint) = EINT_CON_HIGHLEVEL;    
            *EINT_INTACK = EINT_INTACK_EINT(eint);
            for(delay=0;delay<500;delay++);
            reg_value = *EINT_STATUS;
            EINT_Mask(eint);
            *EINT_INTACK = EINT_INTACK_EINT(eint);   
            IRQClearInt(IRQ_EIT_CODE);
            IRQUnmask(IRQ_EIT_CODE);   
            status =  (reg_value & EINT_STATUS_EINT(eint))? KAL_TRUE: KAL_FALSE;
         }
         #endif /*__USB_ENABLE__*/
      
         return status;
      #endif/*__CHARGER_USB_DETECT_WIHT_ONE_EINT__*/
   #endif/*MT6238PMU*/ 
} 
#endif /*!defined(__FUE__)*/
  
/*
* FUNCTION
*	DRV_POWEROFF
*
* DESCRIPTION
*   	This function is to power off the targer.
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
void DRV_POWEROFF(void)  /*PW_KEYPRESS*/
{
#if defined(DRV_RTC_NO_REG_COMM) || defined(FPGA)
   //#ifdef PMIC_PRESENT
   #if ( (defined(MT6318))|| (defined(MT6305)) )
      kal_uint16 BBPU;
   #endif   /*PMIC_PRESENT*/
#endif   /*DRV_RTC_NO_REG_COMM,FPGA*/
#if defined(DRV_RTC_REG_COMM)
    //#ifdef PMIC_PRESENT	
    #if ( (defined(MT6318))|| (defined(MT6305))|| defined(MT6223PMU)|| defined(MT6238PMU) )
	kal_uint16 REG_COMM2;
	kal_uint16 BBPU;
    #endif
#endif	/*DRV_RTC_REG_COMM*/
   kal_uint16 index;
   

#if !defined(__FUE__)
   Drv_Deinit();
   #ifdef ORDNANCE
   *IRQ_MASK = (kal_uint16)(~(1 << IRQ_KPAD_CODE));
   #endif	/*ORDNANCE*/
   
   #ifndef L1_NOT_PRESENT
   L1T_Exit();
   #endif /* !L1_NOT_PRESENT */
   
   /* for BBPU can't be modify twice in a very short period*/
   #if defined(DRV_RTC_NO_REG_COMM) || defined(FPGA)
   if (BMT.EINT2STATE == DETECTCHROUT)
   	return;
   #endif
   	
   for(index=0;index<1000;index++);
   
   #ifdef BMT_DEBUG
   {
      kal_uint32 count=0;
      dbg_printWithTime("DRV_POWEROFF..\r\n");
      while(count++ < 1000000);
   }
   #endif   /*BMT_DEBUG*/
   
   IRQMask(IRQ_RTC_CODE);
#endif /*!defined(__FUE__)*/
//#ifdef PMIC_PRESENT
#if ( (defined(MT6318))|| (defined(MT6305))|| defined(MT6223PMU)|| defined(MT6238PMU))
   #if defined(DRV_RTC_NO_REG_COMM) || defined(FPGA)
      BBPU = DRV_Reg(RTC_BBPU);
      BBPU |= (RTC_BBPU_KEY | RTC_BBPU_PWR_POLARITY | RTC_BBPU_PDN_XOSC32K);
      BBPU &= ~RTC_BBPU_PWR_SW;     //RTC_setPWRSW(KAL_TRUE);
      DRV_WriteReg(RTC_BBPU,BBPU);
   #endif   /*DRV_RTC_NO_REG_COMM,FPGA*/
   #if defined(DRV_RTC_REG_COMM)
   	REG_COMM2 = DRV_Reg(DRV_COMM_REG2);
      REG_COMM2 |= DRV_COMM_REG2_NORMAL_RESET;
      REG_COMM2 &= ~(DRV_COMM_REG2_RTCPWRON);/*TY add 0218*/
      DRV_WriteReg(DRV_COMM_REG2,REG_COMM2);    
      BBPU = DRV_Reg(RTC_BBPU);/*0227 TY modifies*/
      #if defined(DRV_RTC_WRITE_ENABLE)
      BBPU |= (RTC_BBPU_AUTOPDN|RTC_BBPU_KEY);      
      BBPU &= ~RTC_BBPU_WRITE_EN;/*close RTC interface*/
      #else
      BBPU |= (RTC_BBPU_PWR_POLARITY|RTC_BBPU_AUTOPDN|RTC_BBPU_KEY);      
      #endif
      BBPU &= ~RTC_BBPU_PWR_SW; 
      DRV_WriteReg(RTC_BBPU,BBPU);      
      #if defined(DRV_RTC_HW_CALI)
         RTC_write_trigger();
      #endif /*DRV_RTC_HW_CALI*/
      
   #endif   /*DRV_RTC_REG_COMM*/
#endif   /*PMIC_PRESENT*/
}

/*
* FUNCTION
*	DRV_POWERON
*
* DESCRIPTION                                                           
*   	This function is to power on the targer.
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: MS is first power on of RTC has been reset
*	KAL_FALSE: otherwise.
*
* GLOBALS AFFECTED
*   None
*/
kal_bool DRV_POWERON(void)  /*PW_KEYPRESS*/
{
   kal_uint32 BBPU;
   kal_uint16 status;
   t_rtc time;
   kal_bool isFirstOn = KAL_FALSE;
   kal_uint32 count;
   
   #ifdef BMT_DEBUG
      dbg_printWithTime("DRV_POWERON..\r\n");
   #endif   /*BMT_DEBUG*/

   //Power ON
#ifdef _SIMULATION
   if (1)
#else
   if (RTC_isFisrtOn()||(KAL_FALSE==RTC_is_config_valid()))
#endif
   {
   	isFirstOn = KAL_TRUE;
      time.rtc_sec=0; 
	   time.rtc_min=0;
	   time.rtc_hour=0;
	   time.rtc_day=DEFAULT_HARDWARE_DAY;
	   time.rtc_wday=1;
	   time.rtc_mon=DEFAULT_HARDWARE_MON; 
	   time.rtc_year = DEFAULT_HARDWARE_YEAR;
	   RTC_InitTC_Time(&time);
      #if !defined(DRV_RTC_HW_CALI)
      #if defined(DRV_RTC_TC_BUSY_CHECK)
	   while(1)
           {
              if((DRV_Reg(RTC_TC_YEA)&RTC_TIME_BUSY)==0)
              break;            
           }
           #endif         
      #endif         
	   status = DRV_Reg(RTC_IRQ_STATUS);
	   DRV_WriteReg(RTC_TC_DOW,1);
	   DRV_WriteReg(RTC_IRQ_EN,RTC_IRQ_EN_ALLOFF);
	   /*clear alarm mask*/
	   DRV_WriteReg(RTC_AL_MASK,0);
	   /*clearn BBPU alarm power on bit*/
	   BBPU = DRV_Reg(RTC_BBPU);
   	BBPU&=0xfe;
   	BBPU|=RTC_BBPU_KEY;
		DRV_WriteReg(RTC_BBPU,BBPU);		
	   RTC_setPWRKey();	   	   
      #if defined(DRV_RTC_HW_CALI)
      RTC_write_trigger_wait();
      #elif defined(DRV_RTC_POWERKEY_BUSY_CHECK)
	   while(1)
	   {
	      if((DRV_Reg(RTC_W_FLAG)&RTC_POWERKEY_BUSY)==0)
              break;	         
	   }  
           #endif
#ifdef _SIMULATION

      /*
       * When running co-sim,
       * the RTC registers are not stable soon after we set their value.
       * Thus we have to delay for a while before first access.
       */

		for (count = 0; count < 2000; count++) {
		}

#endif   /* _SIMULATION */

#if defined(DRV_RTC_INIT_POLL)
   /*HW bug fix: to cover 128ms de_bounce time*/	     
	   for(count=0;count<10000000;count++)
      {   	
      	t_rtc current_time;
      	kal_uint32 delay=0;
      	RTC_GetTime(&current_time);
      	if((time.rtc_hour==current_time.rtc_hour)&&
      	   (time.rtc_day==current_time.rtc_day)&&(time.rtc_wday==current_time.rtc_wday)&&(time.rtc_mon==current_time.rtc_mon)
      	   &&((DRV_Reg(RTC_IRQ_EN)&0x7FFF)==RTC_IRQ_EN_ALLOFF)&&
      	   (DRV_Reg(RTC_POWERKEY1)==RTC_POWERKEY1_KEY)&&(DRV_Reg(RTC_POWERKEY2)==RTC_POWERKEY2_KEY)&&
      	   ((DRV_Reg(RTC_AL_MASK)&0x7FFF)==0)&&((DRV_Reg(RTC_BBPU)&0x1)==0) )
                 break;   	  
         RTC_InitTC_Time(&time);         	
         DRV_WriteReg(RTC_AL_MASK,0);
         DRV_WriteReg(RTC_IRQ_EN,RTC_IRQ_EN_ALLOFF);
         /*clearn BBPU alarm power on bit*/
	   	BBPU = DRV_Reg(RTC_BBPU);
   		BBPU&=0xfe;
   		BBPU|=RTC_BBPU_KEY;
			DRV_WriteReg(RTC_BBPU,BBPU);
		 for(delay=0;delay<500;delay++);
	      RTC_setPWRKey();	
         #if defined(DRV_RTC_HW_CALI)
         RTC_write_trigger();
         #endif /*DRV_RTC_HW_CALI*/
      }
#endif      
	   
   } 
#ifdef BMT_DEBUG
   for(count=0;count<1000;count++);
   time.rtc_sec=0; 
   time.rtc_min=0;
   time.rtc_hour=0;
   time.rtc_day=1;
   time.rtc_wday=1;
   time.rtc_mon=1; 
   time.rtc_year = 0;
   RTC_InitTC_Time(&time);
#endif    /*BMT_DEBUG*/

#if defined(DRV_RTC_NO_LATCH_PWR_POLL) || defined(FPGA)
   BBPU = DRV_Reg(RTC_BBPU);
   BBPU |= (RTC_BBPU_KEY|RTC_BBPU_PWR_POLARITY|RTC_BBPU_PDN_XOSC32K
            |RTC_BBPU_PWR_SW|RTC_BBPU_ALARM_SW);
   DRV_WriteReg(RTC_BBPU,BBPU);
#endif   /*DRV_RTC_NO_LATCH_PWR_POLL,FPGA*/
#if defined(DRV_RTC_LATCH_PWR_POLL)
   //DRV_WriteReg(RTC_BBPU,RTC_BBPU_POWERON);
   BBPU = DRV_Reg(RTC_BBPU);/*0227 TY modifies*/
   BBPU |= RTC_BBPU_POWERON;
   DRV_WriteReg(RTC_BBPU,BBPU);   
   #if defined(DRV_RTC_HW_CALI)
   RTC_write_trigger();
   #endif /*DRV_RTC_HW_CALI*/

   for(count=1000;count>0;count--)
   {
      kal_uint32 delay_tick;
      
      if(( DRV_Reg(RTC_BBPU)&RTC_BBPU_PWR_SW)!=0)
         break;
      for (delay_tick = 10000; delay_tick >0; delay_tick--)
      {
      }
      DRV_WriteReg(RTC_BBPU,BBPU);      
      #if defined(DRV_RTC_HW_CALI)
      RTC_write_trigger();
      #endif /*DRV_RTC_HW_CALI*/
   }  
         
      BBPU = DRV_Reg(RTC_INFO1);
      BBPU &= ~0x0e; 
      BBPU |= (0x00<<1); /*2ms debounce time*/
      DRV_WriteReg(RTC_INFO1,BBPU);
#endif   /*DRV_RTC_LATCH_PWR_POLL*/
   	
   DRV_WriteReg(RTC_AL_DOW,DRV_Reg(RTC_TC_DOW));
   #if defined(DRV_RTC_HW_CALI)
   RTC_write_trigger();
   #endif /*DRV_RTC_HW_CALI*/

	return isFirstOn;
}

#if (!defined(__L1_STANDALONE__)) && (!defined(MT6208))
void PW_Set_FOTA_Flag(void)
{
   kal_uint16 REG_COMM2;

	REG_COMM2 = DRV_Reg(DRV_COMM_REG2);
   REG_COMM2 |= DRV_COMM_REG2_FOTA_PWRON;
   DRV_WriteReg(DRV_COMM_REG2,REG_COMM2);
}

void PW_Clear_FOTA_Flag(void)
{
   kal_uint16 REG_COMM2;

	REG_COMM2 = DRV_Reg(DRV_COMM_REG2);
   REG_COMM2 &= ~(DRV_COMM_REG2_FOTA_PWRON);
   DRV_WriteReg(DRV_COMM_REG2,REG_COMM2);
}
#endif /* (!defined(__L1_STANDALONE__)) && (!defined(MT6208)) */

#if !defined(__FUE__)
/*
* FUNCTION
*	DRV_NFB_POWERON
*
* DESCRIPTION                                                           
*   	This function is to power on the targer.
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: MS is first power on of RTC has been reset
*	KAL_FALSE: otherwise.
*
* GLOBALS AFFECTED
*   None
*/
kal_bool DRV_NFB_POWERON(void)  /*power function for NFB*/
{
   #ifdef _NAND_FLASH_BOOTING_
   if(BMT.PWRon == PWRKEYPWRON)
      DRV_POWERON();
   #endif   
   return KAL_TRUE;
}

/*
* FUNCTION
*	   CHRDET_HISR
*
* DESCRIPTION                                                           
*   	This function is the interrupt handler for EINT1
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
void CHRDET_HISR(void)
{
   extern void bmt_charger_action(kal_bool in);
   kal_uint8 state;
   
   BMT.EINT2STATE = !BMT.EINT2STATE;
   #if (defined(MT6305) &&  !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__))|| defined(MT6223PMU)|| defined(MT6238PMU)
   chrdet_level_config(BMT.EINT2STATE);
   #endif
   state = !BMT.EINT2STATE;
   if (state == DETECTCHRIN)
   {
      #ifdef BMT_DEBUG
      dbg_printWithTime("CHARGER_PLUGIN\r\n");
      #endif   /*BMT_DEBUG*/
      bmt_set_chr_status(bmt_chr_in);
      bmt_charger_action(KAL_TRUE);
   }
   else
   {
      #ifdef BMT_DEBUG
      dbg_printWithTime("CHARGER_PLUGOUT\r\n");
      #endif   /*BMT_DEBUG*/
      bmt_set_chr_status(bmt_chr_out);
      bmt_charger_action(KAL_FALSE);
   }
   #if (defined(MT6305) &&  !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__))|| defined(MT6223PMU)|| defined(MT6238PMU)
   EINT_UnMask(gCHRDET_EINT_NO);
   #endif
}

/*
* FUNCTION
*	   chrdet_level_config
*
* DESCRIPTION                                                           
*   	This function is setup the configuration of external interrupt 1.
*
* CALLS  
*
* PARAMETERS
*	   state: DETECTCHRIN or DETECTCHROUT
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void chrdet_level_config(kal_uint8 state)
{
#if defined(MT6223PMU)|| defined(MT6238PMU)
   if (state != DETECTCHRIN)
#else
   if (state == DETECTCHRIN)
#endif
   	EINT_Set_Polarity(gCHRDET_EINT_NO,LEVEL_HIGH);
   else
      EINT_Set_Polarity(gCHRDET_EINT_NO,LEVEL_LOW);
}


/*************************************************************************
* FUNCTION
*  PW_is_RTC_expired
*
* DESCRIPTION                                                           
*	Check if RTC alarm is expired.
*
* PARAMETERS
*	   None
*	
* RETURNS
*  KAL_TRUE:	MS is powered on with RTC alarm expired.
*	KAL_FALSE:	vise versa,

* GLOBALS AFFECTED
*	
*
*************************************************************************/
#if ( (!defined(__L1_STANDALONE__)) && (!defined(DRV_RTC_BBPU_AS_6208)) )
kal_bool PW_is_RTC_expired(void)
{
#if defined(DRV_RTC_PWRON_BBPU_POLARITY)
   kal_uint16 BBPU;
   kal_uint16 POLAR;
   kal_uint16 PWRSW;
#endif   /*DRV_RTC_PWRON_BBPU_POLARITY*/
   kal_uint32 currtime;
   kal_uint32 al_currtime;
   t_rtc  time_current;
   t_rtc  time_alarm;

#if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	// get Polarity and BBPU bit
   BBPU = DRV_Reg(RTC_BBPU);
   POLAR = BBPU & RTC_BBPU_PWR_POLARITY;
   POLAR >>= 1;
   PWRSW = BBPU & RTC_BBPU_PWR_SW;
   #if defined(DRV_RTC_BBPU_AS_6205) || defined(DRV_RTC_BBPU_AS_6218)
      PWRSW >>= 2;
   #elif defined(DRV_RTC_BBPU_AS_6208)
      PWRSW >>= 4;
   #endif   /*(MT6208)*/
#endif   /*DRV_RTC_PWRON_BBPU_POLARITY*/

	// BBPU bit is set
   #if defined(DRV_RTC_PWRON_BBPU_POLARITY)
         if (POLAR == PWRSW)
   #elif defined(DRV_RTC_PWRON_BBPU_SW)
         if (DRV_Reg(RTC_BBPU) & RTC_BBPU_PWR_SW)
   #elif ( (defined(FPGA)) )
         if (0)
   #endif   /*DRV_RTC_PWRON_BBPU_POLARITY*/
         {
                  RTC_GetTime(&time_current);
                  RTC_GetALTime(&time_alarm);
                  currtime = (kal_uint32)(time_current.rtc_hour*3600+time_current.rtc_min*60+time_current.rtc_sec);
                  al_currtime = (kal_uint32)(time_alarm.rtc_hour*3600+time_alarm.rtc_min*60+time_alarm.rtc_sec);

                  // current time >= (alarm time + 20 seconds )
                  if ((time_current.rtc_year == time_alarm.rtc_year) &&
                      (time_current.rtc_mon == time_alarm.rtc_mon) &&
                      (time_current.rtc_day == time_alarm.rtc_day) &&
                      (currtime >= (al_currtime)) &&
                      (currtime < (al_currtime+20))
                     )
                  {
                     #ifdef BMT_DEBUG
                     dbg_printWithTime("RTCPWRON\r\n");
                     #endif   /*BMT_DEBUG*/
                     return KAL_TRUE;
                  }
         }   

   return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  PW_is_charger_usb_present
*
* DESCRIPTION
*	Check if charger or usb is connected now ?
*
* PARAMETERS
*	None
*
* RETURNS
*  KAL_TRUE:	MS is powered on with RTC alarm expired.
*	KAL_FALSE:	vise versa,

* GLOBALS AFFECTED
*	None	
*
* Note
*	Charger and usb cannot exist simutaneously
*       Only use in Initialize stage
*
*************************************************************************/
kal_bool PW_is_usb_present(void)
{
   #ifdef _USB_VBUS_DETECT_WITH_NIRQ_
   kal_uint16 delay;
   kal_bool status=KAL_FALSE;
   kal_uint32 nirq_status;   
   kal_uint32 level;
   kal_uint32 saved_interrupt[2]={0,0};
   
#ifdef __OTG_ENABLE__ 
   if(OTG_PowerOn_Is_A_Plug()==KAL_TRUE)
   	return KAL_FALSE;
#endif   
   
   /*GPIO mode setting*/
    #ifdef __CUST_NEW__
    GPIO_DinvSetup(36, KAL_TRUE);
    #else
    GPIO_ModeSetup(36, 0x01);
	/* inverse, plug in detect high*/
	DRV_WriteReg(GPIO_DINV3, DRV_Reg(GPIO_DINV3)|0x0010);	   	
    #endif /* __CUST_NEW__ */
	/*level trigger*/
	level=DRV_Reg32(IRQ_SENSL);	   	   		
	if (IRQCode2Line[IRQ_GPII_CODE] <= 31){
		level=DRV_Reg32(IRQ_SENSL);
		DRV_WriteReg32(IRQ_SENSL, (level|(1 << IRQCode2Line[IRQ_GPII_CODE]) ));
	}else{
		level=DRV_Reg32(IRQ_SENSH);	   	   		
		DRV_WriteReg32(IRQ_SENSH, (level|(1 << (IRQCode2Line[IRQ_GPII_CODE] - 32) )));
	}
  /*Saved interrupt mask*/
  saved_interrupt[0]=DRV_Reg32(IRQ_MASKL);
  saved_interrupt[1]=DRV_Reg32(IRQ_MASKH);
  IRQDirectMaskAll();
   IRQUnmask(IRQ_GPII_CODE);	
	for(delay=0;delay<300;delay++);

   nirq_status=DRV_Reg32(IRQ_STS2);
   if(nirq_status==IRQCode2Line[IRQ_GPII_CODE])
   {
      status=KAL_TRUE;
      IRQClearInt(IRQ_GPII_CODE);
   }
   IRQMask(IRQ_GPII_CODE);   
   /*Restore interrupt mask*/
   DRV_WriteReg32(IRQ_MASKL, saved_interrupt[0]);
   DRV_WriteReg32(IRQ_MASKH, saved_interrupt[1]);
   
   return status;
   #else
   return KAL_TRUE;
   #endif
}
#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
charger_usb_present_enum PW_is_charger_usb_present(void)
{
	kal_uint16 status;
	kal_uint16 delay;
	
	// charger triggers CHRDET_EINT_NO
	// USB triggers CHRDET_EINT_NO and USB_EINT_NO

	#if !defined(MT6318)
   /***********External Interrupt bug fix *********************/
   /**/   *EINT_MASK &= (kal_uint16)(~EINT_MASK_EINT(gCHRDET_EINT_NO)); /**/    
   #if defined(MT6223PMU) || defined(MT6238PMU)
   /**/   EINTaddr(gCHRDET_EINT_NO) = EINT_CON_LOWLEVEL;               /**/    
   #else
   /**/   EINTaddr(gCHRDET_EINT_NO) = EINT_CON_HIGHLEVEL;               /**/    
   #endif
   /**/   /*HW bug fix*/                                              /**/       
   /**/   *EINT_INTACK = EINT_INTACK_EINT(gCHRDET_EINT_NO);            /**/     
		#ifdef __USB_ENABLE__
         if (gUSB_EINT_NO != EINT_CHANNEL_NOT_EXIST) {
   /**/   *EINT_MASK &= (kal_uint16)(~EINT_MASK_EINT(gUSB_EINT_NO)); 		
   /**/   EINTaddr(gUSB_EINT_NO) = EINT_CON_HIGHLEVEL;               		
   /**/   *EINT_INTACK = EINT_INTACK_EINT(gUSB_EINT_NO);       
         }
		#endif   
   /**/   for(delay=0;delay<500;delay++);                             /**/     
   /**/   status = *EINT_STATUS;                                      /**/       
   /**/   EINT_Mask(gCHRDET_EINT_NO);                                  /**/     
   /**/   *EINT_INTACK = EINT_INTACK_EINT(gCHRDET_EINT_NO);            /**/       
		#ifdef __USB_ENABLE__
         if (gUSB_EINT_NO != EINT_CHANNEL_NOT_EXIST) {
   /**/   EINT_Mask(gUSB_EINT_NO);                                  	
   /**/   *EINT_INTACK = EINT_INTACK_EINT(gUSB_EINT_NO);            
         }
		#endif   
   /**/   IRQClearInt(IRQ_EIT_CODE);                                  /**/         		
   /******************************External Interrupt bug fix *************/
	#endif	// !defined(MT6318)

	#if defined(MT6318)
		if(pmic_is_chr_det(AC_CHR)) 
			return CHARGER_PRESENT;
		#ifdef __USB_ENABLE__
		else if(pmic_is_chr_det(USB_CHR))
			return USB_PRESENT;
		#endif 
	#else		// MT6318
	   if (status & EINT_STATUS_EINT(gCHRDET_EINT_NO))
	   {                                                                    
			#ifdef __USB_ENABLE__
			#ifdef _USB_VBUS_DETECT_WITH_NIRQ_
			if(PW_is_usb_present())		
			#else
			if (gUSB_EINT_NO != EINT_CHANNEL_NOT_EXIST && (status & EINT_STATUS_EINT(gUSB_EINT_NO)))
			#endif
			{
				return USB_PRESENT;
			}
			#endif // __USB_ENABLE__
			return CHARGER_PRESENT;			
		}	
		#ifdef _USB_VBUS_DETECT_WITH_NIRQ_
		else if(PW_is_usb_present())			   
		{
		   return USB_PRESENT;
		}   
		#elif defined(MT6268T_EVB)
      /* For the case when USB won't trigger charger EINT. */
		else if (gUSB_EINT_NO != EINT_CHANNEL_NOT_EXIST && (status & EINT_STATUS_EINT(gUSB_EINT_NO)))
		{
		   return USB_PRESENT;
		}
		#endif
	#endif	// MT6318
	
	return NO_PRESENT;
}
#else //__CHARGER_USB_DETECT_WIHT_ONE_EINT__
#if defined(MT6223PMU)
#error USB & CHARGER use the same EINT can not work with MT6223
#endif

charger_usb_present_enum PW_is_charger_usb_present(void)
{
	#if defined(MT6305)
	kal_uint16 status, delay;
   #endif
	kal_uint16 adc=0;
	kal_int32 volt;
	kal_uint8 eint;
	kal_uint8 adc_channel;	
	extern chr_usb_detect_struct chr_usb_detect;
	
	eint = chr_usb_detect.chr_usb_eint;
	adc_channel = chr_usb_detect.chr_usb_adc;
	#if defined(MT6305)
   *EINT_MASK &= (kal_uint16)(~EINT_MASK_EINT(eint));
   EINTaddr(eint) = EINT_CON_HIGHLEVEL;    
   *EINT_INTACK = EINT_INTACK_EINT(eint);
   for(delay=0;delay<500;delay++);
   status = *EINT_STATUS;
   EINT_Mask(eint);
   *EINT_INTACK = EINT_INTACK_EINT(eint);

   if (status & EINT_STATUS_EINT(eint))
   #elif defined(MT6318)
   if(pmic_is_chr_det(AC_CHR))
   #elif defined(MT6238PMU)
   if(pmu_is_chr_det())
   #endif
	{
	   extern charger_usb_present_enum bmt_check_ac_usb(kal_int32 vol);
	   charger_usb_present_enum state;	
		// use adc to distinguish between charger & usb
		USB_PowerControl(KAL_TRUE);
		DRV_Reg(DRVPDN_CON2_CLR) = DRVPDN_CON2_AUXADC;
		if(adc_channel<ADC_MAX_CHANNEL) 
		   adc = ADC_GetData(adc_channel);
		DRV_Reg(DRVPDN_CON2_SET) = DRVPDN_CON2_AUXADC;
		volt = (kal_int32)((adc_adc2vol(adc_channel, (double)adc)/100)*bmt_charing_para->adc_volt_factor[adc_channel]);
		USB_PowerControl(KAL_FALSE);
		state=bmt_check_ac_usb(volt);
		//if(volt < chr_usb_detect.chr_usb_volt)
		if(state==USB_PRESENT)
			return USB_PRESENT;
#if defined(__CHINA_CHARGER_STANDARD__)
		else if(state==CHARGER_PRESENT_NON)     //non-standard china charger
		    return CHARGER_PRESENT_NON;
#endif
		else
			return CHARGER_PRESENT;
	}
				
   return NO_PRESENT;
}
#endif //__CHARGER_USB_DETECT_WIHT_ONE_EINT__
/*************************************************************************
* FUNCTION
*  PW_update_flags
*
* DESCRIPTION
*	Update the current state of the nonvolatile flags.
*
* PARAMETERS
*	None
*
* RETURNS
*
* GLOBALS AFFECTED
*	DRV_COMM_REG2	
*
*************************************************************************/	
void PW_update_flags(void)
{
	kal_uint16 REG_COMM2;

	REG_COMM2 = DRV_Reg(DRV_COMM_REG2);
	if(BMT.PWRon == PWRKEYPWRON || BMT.PWRon == ABNRESET)
	{
      REG_COMM2 &= ~(DRV_COMM_REG2_NORMAL_RESET|DRV_COMM_REG2_CHRPWRON|DRV_COMM_REG2_RTCPWRON);
   	#if defined(__USB_ENABLE__)
   	REG_COMM2 &= ~(DRV_COMM_REG2_USBMS_PWRON);	
   	#endif		
	}
   else if(BMT.PWRon == CHRPWRON)
   {
      REG_COMM2  &= ~(DRV_COMM_REG2_NORMAL_RESET|DRV_COMM_REG2_RTCPWRON);
		#if defined(__USB_ENABLE__)
		REG_COMM2 &= ~(DRV_COMM_REG2_USBMS_PWRON);
		#endif
      REG_COMM2 |=  DRV_COMM_REG2_CHRPWRON;      
   }
   #if defined(__USB_ENABLE__)
   else if(BMT.PWRon == USBPWRON)
	{
		// 1. set when selecting mass storage.
		// 2. USB cable is plugged in and powered on.
      REG_COMM2  &= ~(DRV_COMM_REG2_NORMAL_RESET|DRV_COMM_REG2_CHRPWRON|DRV_COMM_REG2_RTCPWRON);
      REG_COMM2 |=  DRV_COMM_REG2_USBMS_PWRON;	
	}
   #endif //__USB_ENABLE__
   else if(BMT.PWRon == RTCPWRON)
	{
      REG_COMM2 &= ~(DRV_COMM_REG2_NORMAL_RESET|DRV_COMM_REG2_CHRPWRON);
   	#if defined(__USB_ENABLE__)
   	REG_COMM2 &= ~(DRV_COMM_REG2_USBMS_PWRON);	
   	#endif	
		REG_COMM2 |= DRV_COMM_REG2_RTCPWRON;
	}
 	REG_COMM2 &= ~(DRV_COMM_REG2_FOTA_PWRON);	
   DRV_WriteReg(DRV_COMM_REG2,REG_COMM2);
 
#ifdef BMT_DEBUG
   if(BMT.PWRon == PWRKEYPWRON)
      DRV_POWERON();
#endif /*BMT_DEBUG*/
 
   BMT.BatType = LIBAT;
   #ifndef __CUST_NEW__
   //GPIO_WriteIO(KAL_FALSE,bmt_charing_para->GPIO_BATDET);
   #endif /* __CUST_NEW__ */
   /*BMT struct initialize*/
   BMT.call_state = idle_mode;
   BMT.pmictrl_state = PMIC_CHARGEOFF;
   BMT_Charge(KAL_FALSE);		
   
}
/*************************************************************************
* FUNCTION
*  PW_is_precharge_on
*
* DESCRIPTION
*	check if phone is in precharge state
*
* PARAMETERS
*	None
*
* RETURNS
*  KAL_TRUE or KAL_FALSE
*
* GLOBALS AFFECTED
*	DRV_COMM_REG2	
*
*************************************************************************/	
kal_bool PW_is_precharge_on(void)
{
   extern kal_uint8 custom_adc_get_channel(adc_channel_type type);
   kal_uint8 channel;
   kal_uint16 adc;
	kal_int32 volt;
	  
   channel=custom_adc_get_channel(vbat_adc_channel);
   #if defined(__USB_ENABLE__)
   USB_PowerControl(KAL_TRUE);
   #endif
   DRV_Reg(DRVPDN_CON2_CLR) = DRVPDN_CON2_AUXADC;	 
	adc = ADC_GetData(channel);
	DRV_Reg(DRVPDN_CON2_SET) = DRVPDN_CON2_AUXADC;
	volt = (kal_int32)((adc_adc2vol(channel, (double)adc)/100)*bmt_charing_para->adc_volt_factor[channel]);
	#if defined(__USB_ENABLE__)
   USB_PowerControl(KAL_FALSE);
   #endif
   if(volt<=BMT_PRECHARGE_THRESHOLD)
      return KAL_TRUE;
   else
      return KAL_FALSE;
      
}   

/*
* FUNCTION
*	   PW_PowerInit
*
* DESCRIPTION                                                           
*   	This function is the initial function when power on.
*     1. Check which source power on
*     2. Configure the external interrupt(Battery remove, Charger in/out)
*     3. Initialize the setting of charge module.
*		4. update the nonvolatile flags.
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
void PW_PowerInit(void)
{
   #if !defined(DRV_MISC_TDMA_32K_CALI) || defined(FPGA)
	kal_uint32 delay;
	#endif
   kal_uint8  RTC_Firston;
   kal_uint16 REG_COMM2;
   kal_bool factors[PWR_FACTOR_MAX] = {0};

   REG_COMM2 = DRV_Reg(DRV_COMM_REG2);   
   RTC_Firston = RTC_isFisrtOn();
   if (RTC_Firston)
   {    
      #if defined(DRV_RTC_REG_COMM)
         REG_COMM2 = DRV_COMM_REG2_NORMAL_RESET;
         DRV_WriteReg(DRV_COMM_REG2,REG_COMM2);
         #if defined(DRV_RTC_HW_CALI)
         DRV_WriteReg(RTC_CALI, 0);
         DRV_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
         #endif /*DRV_RTC_HW_CALI*/
      #endif   
      
      #if !defined(DRV_MISC_TDMA_32K_CALI)
      	for(delay=0;delay<22030000;delay++);
		#endif  
   }
   #if defined(DRV_MISC_TDMA_32K_CALI)
      wait_32k_start();
   #endif  
   #if defined(DRV_ADC_LIMIT_REG) || defined(FPGA)
	// initialize ADC
   DRV_WriteReg(AUXADC_CTRL2,AUXADC_CTRL2_MON);
	#endif   /*(DRV_ADC_LIMIT_REG,FPGA)*/
	
   #ifdef __MULTI_BOOT__
      if (INT_BootMode() != MTK_NORMAL_MODE)
      {
         BMT.PWRon = PWRKEYPWRON;
         DRV_POWERON();
         return;
      }
   #endif   /*__MULTI_BOOT__*/

   
   // collect all factors
	// check RTC expired
	if(PW_is_RTC_expired())
		factors[PWR_FACTOR_RTC_EXPIRE] = KAL_TRUE;		
	// check power key pressed
	if(PowerKey_Pressed())
		factors[PWR_FACTOR_POWER_KEY] = KAL_TRUE;
	// check charger or usb existence
#if !defined(__DRV_NO_USB_CHARGER__)
	switch (PW_is_charger_usb_present())
	{
	case CHARGER_PRESENT:
		factors[PWR_FACTOR_CHARGER_IN] = KAL_TRUE;
		break;
#if defined(__CHINA_CHARGER_STANDARD__)
	case CHARGER_PRESENT_NON:           //non-standard china charger
		factors[PWR_FACTOR_CHARGER_IN] = KAL_TRUE;
		break;
#endif
	case USB_PRESENT:
		factors[PWR_FACTOR_USB_IN] = KAL_TRUE;
		break;
	case NO_PRESENT:
		break;
	}
	
	/*check Precharge*/
   if (factors[PWR_FACTOR_CHARGER_IN]==KAL_TRUE)
   {
      if(PW_is_precharge_on())
         factors[PWR_FACTOR_PRECHRPWRON_FLG] = KAL_TRUE;
	}	
#endif /*  !defined(__DRV_NO_USB_CHARGER__) */
	
	
	// check watch dog reset
	if(WDT_RST)
	{
		factors[PWR_FACTOR_WDT_RESET] = KAL_TRUE;
		is_wdt_power=KAL_TRUE;/*for NFB*/
	}	
	// check flags
	if(REG_COMM2 & DRV_COMM_REG2_NORMAL_RESET)
		factors[PWR_FACTOR_NORMAL_RESET_FLG] = KAL_TRUE;
	if(REG_COMM2 & DRV_COMM_REG2_CHRPWRON)
		factors[PWR_FACTOR_CHRPWRON_FLG] = KAL_TRUE;
	if(REG_COMM2 & DRV_COMM_REG2_USBMS_PWRON)
		factors[PWR_FACTOR_USBMS_PWRON_FLG] = KAL_TRUE;
	if(REG_COMM2 & DRV_COMM_REG2_RTCPWRON)
		factors[PWR_FACTOR_RTCPWRON_FLG] = KAL_TRUE;
	if(REG_COMM2 & DRV_COMM_REG2_FOTA_PWRON)
		factors[PWR_FACTOR_FOTAPWRON_FLG] = KAL_TRUE;
	// check power on type
	// priority: PWRKEYPWRON > ABNRESET > CHRPWRON > USBPWRON_WDT > USBPWRON > RTCPWRON
	if(factors[PWR_FACTOR_PRECHRPWRON_FLG])
	{
	   BMT.PWRon = CHRPWRON;//PRECHRPWRON
   }
	else if((factors[PWR_FACTOR_POWER_KEY]&& !factors[PWR_FACTOR_CHARGER_IN]&& !factors[PWR_FACTOR_USB_IN])||
		(factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_CHARGER_IN]&& factors[PWR_FACTOR_WDT_RESET]&& factors[PWR_FACTOR_CHRPWRON_FLG])||
		(factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_USB_IN]&& factors[PWR_FACTOR_WDT_RESET]&& factors[PWR_FACTOR_USBMS_PWRON_FLG])||
		(factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_CHARGER_IN]&& !factors[PWR_FACTOR_WDT_RESET])||
		(factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_USB_IN]&& !factors[PWR_FACTOR_WDT_RESET]))
	{
		BMT.PWRon = PWRKEYPWRON;
	}
	#ifdef __PRODUCTION_RELEASE__
	else if(factors[PWR_FACTOR_WDT_RESET]&&!factors[PWR_FACTOR_CHRPWRON_FLG]&&!factors[PWR_FACTOR_USBMS_PWRON_FLG]
				&&!factors[PWR_FACTOR_RTCPWRON_FLG]&& !factors[PWR_FACTOR_NORMAL_RESET_FLG])
	{
		BMT.PWRon = ABNRESET;
	}
   #else   //__PRODUCTION_RELEASE__
   #ifdef __MA_L1__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif  /* __MA_L1__ */
	#endif	//__PRODUCTION_RELEASE__
	else if((factors[PWR_FACTOR_CHARGER_IN]&&!factors[PWR_FACTOR_POWER_KEY])||
		(factors[PWR_FACTOR_CHARGER_IN]&&factors[PWR_FACTOR_POWER_KEY]&&!factors[PWR_FACTOR_RTCPWRON_FLG]))
	{
		BMT.PWRon = CHRPWRON;		
	}
	#ifdef __USB_ENABLE__
	else if((factors[PWR_FACTOR_USB_IN]&&!factors[PWR_FACTOR_POWER_KEY]&&factors[PWR_FACTOR_WDT_RESET]&&
			!factors[PWR_FACTOR_NORMAL_RESET_FLG]&&factors[PWR_FACTOR_USBMS_PWRON_FLG]))
	{
		BMT.PWRon = USBPWRON_WDT;
	}	
	else if((factors[PWR_FACTOR_USB_IN]&&!factors[PWR_FACTOR_POWER_KEY])||
		(factors[PWR_FACTOR_USB_IN]&&factors[PWR_FACTOR_POWER_KEY]&&!factors[PWR_FACTOR_USBMS_PWRON_FLG])
		)
	{
		BMT.PWRon = USBPWRON;		
	}
	#endif // __USB_ENABLE__
	else if((factors[PWR_FACTOR_RTC_EXPIRE]&&!factors[PWR_FACTOR_RTCPWRON_FLG]))
	{
		BMT.PWRon = RTCPWRON;
	}	
   else if (factors[PWR_FACTOR_FOTAPWRON_FLG])
   {
		BMT.PWRon = PWRKEYPWRON;
   }
	else
	{
		kal_uint32 loop=0, wait=0;
      kal_uint16 mask=0;
	   #if 0
/* under construction !*/
/* under construction !*/
	   #else
      while(1)/*to cover crstal oscillates too late case*/
      {      	           
      	 mask = DRV_Reg(RTC_AL_MASK);
      	 if((mask&1) == 1)/*make sure user doesn't configure Alarm*/
      	 {
      	 	 for(loop=0;loop<10000;loop++)
      	 	 {
      	 	 	 /*Diable all alarm mask*/
	    	 	 	 DRV_WriteReg(RTC_AL_MASK,0);
                #if defined(DRV_RTC_HW_CALI)
                DRV_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
                #endif /*DRV_RTC_HW_CALI*/
	    	 	 	 for(wait=0;wait<10000;wait++){};                
	    	 	 	 mask = DRV_Reg(RTC_AL_MASK);
	    	 	 	 if(mask==0)
	    	 	 	 	 break;
	    	 	 }
	    	 }
      	 DRV_POWEROFF();
      	 for(wait=0;wait<50000;wait++){};
      }
      #endif	
	}

	
	// reset flags
	PW_update_flags();
	
}
#endif /*(!defined(__L1_STANDALONE__)) && (!defined(MT6208))*/

/*
* FUNCTION
*	   Modify_PowerOn_Type
*
* DESCRIPTION                                                           
*   	This function is to modify power on type
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
void Modify_PowerOn_Type(kal_uint8 powen_type)/*TY add 0218*/
{   
  kal_uint32 reg;
       	
   BMT.PWRon = powen_type;

   #if defined(DRV_RTC_REG_COMM)
   if(BMT.PWRon == PWRKEYPWRON)
   {
      reg = DRV_Reg(DRV_COMM_REG2);   	
      reg &= ~(DRV_COMM_REG2_RTCPWRON);
      DRV_WriteReg(DRV_COMM_REG2,reg);            
   }   
   #endif
    
}
kal_bool INT_USBBoot(void)
{
   if ((BMT.PWRon == USBPWRON) || (BMT.PWRon == USBPWRON_WDT))
      return KAL_TRUE;
   else
      return KAL_FALSE;
}
/*
* FUNCTION
*	   BMT_Charge
*
* DESCRIPTION                                                           
*   	This function is to control the switch of charge
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
void BMT_Charge(char data)
{
#if defined(DRV_GPIO_6205_FUNC)
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();	
   #ifdef __CUST_NEW__
   GPIO_WriteIO(data, gpio_bmt_chr_ctrl_pin);
   #else /* __CUST_NEW__ */
   GPIO_WriteIO(data,bmt_charing_para->GPIO_CHRCTRL);
   #endif /* __CUST_NEW__ */
	RestoreIRQMask(savedMask);
#elif defined(DRV_GPIO_6205B_FUNC) || defined(DRV_GPIO_FULL_FUNC)
   #if defined(MT6318)
      if(data==KAL_TRUE)
      { 
         if(KAL_TRUE==pmic_is_chr_det(AC_CHR))/*check if AC exists*/   
            pmic_chr_enable(data);
         if(KAL_TRUE==pmic_is_chr_det(USB_CHR)) 
         {
            pmic_usb_enable(data);
            pmic_usb_chr_enable(data);
         }   
      }
      else
      {            
            pmic_chr_enable(data);               
            pmic_usb_chr_enable(data);      
      }            
   #elif defined(MT6223PMU) || defined(MT6238PMU)
      if(data==KAL_TRUE)
      { 
         if(pmu_is_chr_det())
            pmu_set_chron(KAL_TRUE);
      }
      else
      {            
            pmu_set_chron(KAL_FALSE);
      }            
   #else
      #ifdef __CUST_NEW__	  
      GPIO_WriteIO(data, gpio_bmt_chr_ctrl_pin);
      #else /* __CUST_NEW__ */
      GPIO_WriteIO(data,bmt_charing_para->GPIO_CHRCTRL);
      #endif /* __CUST_NEW__ */
   #endif
#endif
}
kal_uint16 clear_ext_intr_init(kal_uint8 eint_no)
{
   kal_uint16 delay;
   kal_uint16 status;
   *EINT_MASK &= (kal_uint16)(~EINT_MASK_EINT(eint_no));   
   
   *EINT_INTACK = EINT_INTACK_EINT(eint_no);
   for(delay=0;delay<500;delay++);
   status = *EINT_STATUS;
   EINT_Mask(eint_no);
   *EINT_INTACK = EINT_INTACK_EINT(eint_no);
   IRQClearInt(IRQ_EIT_CODE);
   return status;
}

/***************************************************************
           PMIC Adpatation interface
****************************************************************/

static kal_uint8 g_usb_eint_no;
#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
extern void USB_EINT_HISR(void);
extern void CHRDET_HISR(void);
extern chr_usb_detect_struct chr_usb_detect;
#if defined(MT6318)
extern pmic_charging_current pmic_return_current(chr_type chr);
static kal_bool chr_usb_in_meas = KAL_FALSE;
#endif

static void CHR_USB_PLUG_OUT(void)
{
	kal_prompt_trace(MOD_BMT,"CHR_USB OUT");
	if(chr_usb_detect.chr_usb_present == USB_PRESENT)
	{
		CHRDET_HISR();
		USB_EINT_HISR();
	}
#if defined(__CHINA_CHARGER_STANDARD__)
	else if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT)
	{
		CHRDET_HISR();
		USB_PowerControl(KAL_FALSE);
	}
	else if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT_NON)
	{
		CHRDET_HISR();
		USB_PowerControl(KAL_FALSE);
	}
#else
   else if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT)
		CHRDET_HISR();
#endif
	else
		ASSERT(0);	
	chr_usb_detect.chr_usb_present = NO_PRESENT;
	adc_sche_set_timer_page_align(KAL_TRUE);
	EINT_UnMask(chr_usb_detect.chr_usb_eint);	
}

/*************************************************************************
* FUNCTION
*	check_charger_or_usb
*
* DESCRIPTION
*	1. call back function of adc scheduler 
*	2. judge if charger or usb plugged in by adc measurement
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void check_charger_or_usb(kal_uint8 sche_id)
{
   #if defined(MT6305) || defined(MT6318) || defined(MT6238PMU)
   extern charger_usb_present_enum bmt_check_ac_usb(kal_int32 vol);
	kal_int32 volt;	
	charger_usb_present_enum state;	
   #if defined(MT6318)
   kal_uint32 savedMask;
   #endif

	adc_sche_remove_item(chr_usb_detect.chr_usb_adc_logical_id);
	volt= VOL_RESULT[chr_usb_detect.chr_usb_adc_logical_id];
	USB_PowerControl(KAL_FALSE);
	kal_prompt_trace(MOD_BMT,"volt: %d", volt);
	state=bmt_check_ac_usb(volt);
	//if(volt<chr_usb_detect.chr_usb_volt)
	if(BMT.PWRon==USBPWRON||BMT.PWRon==USBPWRON_WDT||state==USB_PRESENT)
	{
		kal_prompt_trace(MOD_BMT,"USB IN");
		chr_usb_detect.chr_usb_present = USB_PRESENT;
		CHRDET_HISR();
		USB_EINT_HISR();		
	}
	else if (BMT.PWRon==CHRPWRON||BMT.PWRon==PRECHRPWRON||state==CHARGER_PRESENT)
	{
		kal_prompt_trace(MOD_BMT,"AC IN");
		chr_usb_detect.chr_usb_present = CHARGER_PRESENT;
		CHRDET_HISR();
#if defined(__CHINA_CHARGER_STANDARD__)
#ifdef __USB_AND_UART_WITH_ONE_GPIO__
		/* We must call this function in USB_EINT_HISR() in the case that USB and UART with one GPIO */
		USB_Switch_Gpio_to_USB_And_PowerControl(KAL_FALSE);
#endif
#endif
	}
#if defined(__CHINA_CHARGER_STANDARD__)
	else if(state==CHARGER_PRESENT_NON)
	{
	    kal_prompt_trace(MOD_BMT,"non-standard AC IN");
		chr_usb_detect.chr_usb_present = CHARGER_PRESENT_NON;
		CHRDET_HISR();
#ifdef __USB_AND_UART_WITH_ONE_GPIO__
		/* We must call this function in USB_EINT_HISR() in the case that USB and UART with one GPIO */
		USB_Switch_Gpio_to_USB_And_PowerControl(KAL_FALSE);
#endif
	}
#endif
	
	EINT_UnMask(chr_usb_detect.chr_usb_eint);	
   #if defined(MT6318)
   savedMask = SaveAndSetIRQMask();
   if (chr_usb_in_meas == KAL_TRUE)
   {
      chr_usb_in_meas = KAL_FALSE;
      RestoreIRQMask(savedMask);
   }
   else
   {
      RestoreIRQMask(savedMask);
      /* Cable Plug-out has already happened. */
      CHR_USB_PLUG_OUT();
   }
   #endif /* MT6318 */

   #elif defined(MT6223PMU)
   #error USB & CHARGER use the same EINT can not work with MT6223
	#endif
	
	#if 0 //defined(MT6318)/*XXXXX*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__CHINA_CHARGER_STANDARD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
}	

/*************************************************************************
* FUNCTION
*	CHRDET_USB_HISR
*
* DESCRIPTION
*	1. HISR of charger and usb external interrupt
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void CHR_USB_EINT_HISR(void)
{
   #if defined(MT6305) || defined(MT6318) || defined(MT6238PMU)
   #if defined(MT6305) || defined(MT6238PMU)
	EINT_Set_Polarity(chr_usb_detect.chr_usb_eint,chr_usb_detect.chr_usb_state);
   #endif /* MT6305 */
	
	chr_usb_detect.chr_usb_state = !chr_usb_detect.chr_usb_state;	
	if(chr_usb_detect.chr_usb_state)
	{	
		kal_prompt_trace(MOD_BMT,"CHR_USB IN");
		USB_PowerControl(KAL_TRUE);
		adc_sche_set_timer_page_align(KAL_FALSE);
		adc_sche_add_item(chr_usb_detect.chr_usb_adc_logical_id,check_charger_or_usb,adc_sche_measure);
#if defined(MT6318)
      chr_usb_in_meas = KAL_TRUE;
#endif
	}
	else
	{
#if defined(MT6318)
      if (chr_usb_in_meas == KAL_FALSE)
      {
#endif
         CHR_USB_PLUG_OUT();
#if defined(MT6318)
      }
      else
      {
         chr_usb_in_meas = KAL_FALSE;
      }
#endif
	}   
	#endif
   
	#if 0 //defined(MT6318)/*XXXXX*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__CHINA_CHARGER_STANDARD__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}

#endif //__CHARGER_USB_DETECT_WIHT_ONE_EINT__

/*************************************************************************
* FUNCTION
*	pmic_adpt_init
*
* DESCRIPTION
*	Power Management IC or Uint driver initial function
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_init(void)
{  
   #if defined(MT6318)
   B2PSI_init();  
   pmic_init();
   #elif defined(MT6223PMU) || defined(MT6238PMU)
   pmu_init();
   #endif
   g_usb_eint_no = custom_eint_get_channel(usb_eint_chann);
}   

/*************************************************************************
* FUNCTION
*	pmic_adpt_adc_measure
*
* DESCRIPTION
*	To turn on/off circuit measured by ADC
*
* PARAMETERS
*	kal_bool
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_adc_measure(kal_bool on) 
{
   if (on == KAL_TRUE)
   {
      #if defined(MT6318)
      pmic_adc_measure_sel_fast(PMIC_ADC_ISENSE_VBAT);
      #elif defined(MT6223PMU) || defined(MT6238PMU)
      pmu_set_adc_meas_on(KAL_TRUE);
      #endif
   }
   else
   {
      #if defined(MT6318) 
      pmic_adc_measure_sel_fast(PMIC_ADC_OFF);
      #elif defined(MT6223PMU) || defined(MT6238PMU)
      pmu_set_adc_meas_on(KAL_FALSE);
      #endif
   }
}

/*************************************************************************
* FUNCTION
*	pmic_adpt_set_chr_current
*
* DESCRIPTION
*	To set the charging current value (in customized file) to PMIC
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_set_chr_current(void)
{
   #if defined(MT6318)
      #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
         if(pmic_is_chr_det(AC_CHR))
            pmic_charging_currnet_ctrl(pmic_return_current(AC_CHR));
         #ifdef __USB_MULTI_CHARGE_CURRENT__
         else if (bmt_support_usb_charge()) /* If not support, charging current is not set here. */
            pmic_charging_currnet_ctrl(pmic_return_current(USB_CHR));   
         #else /* __USB_MULTI_CHARGE_CURRENT__ */
         else
            pmic_charging_currnet_ctrl(pmic_return_current(USB_CHR));   
         #endif /* __USB_MULTI_CHARGE_CURRENT__ */
      #else/*defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)*/
         if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT)                                   
            pmic_charging_currnet_ctrl(pmic_return_current(AC_CHR));   
         #if defined(__CHINA_CHARGER_STANDARD__)
         else if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT_NON)                                   
            pmic_charging_currnet_ctrl(pmic_return_current(AC_CHR));   
         #endif
         else if(chr_usb_detect.chr_usb_present == USB_PRESENT)                                                                                             
         {  
            #ifdef __USB_MULTI_CHARGE_CURRENT__
            if (bmt_support_usb_charge()) /* If not support, charging current is not set here. */
                pmic_charging_currnet_ctrl(pmic_return_current(USB_CHR));   
            #else /* __USB_MULTI_CHARGE_CURRENT__ */             
                pmic_charging_currnet_ctrl(pmic_return_current(USB_CHR));   
             #endif /* __USB_MULTI_CHARGE_CURRENT__ */
         }
      #endif   
   #elif defined(MT6223PMU)
      if(pmu_is_chr_det())
      {
         pmu_set_chr_cur_level(pmu_ret_chr_current());
      }
   #elif defined(MT6238PMU)
      #if defined (__USB_ENABLE__)
         #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
            if(pmu_is_chr_det())
               pmu_set_chr_cur_level(pmu_ret_chr_current());
            #ifdef __USB_MULTI_CHARGE_CURRENT__
            else if (bmt_support_usb_charge()) /* If not support, charging current is not set here. */
               pmu_set_chr_cur_level(pmu_ret_usb_current());
            #else /* __USB_MULTI_CHARGE_CURRENT__ */
            else
               pmu_set_chr_cur_level(pmu_ret_usb_current());
            #endif /* __USB_MULTI_CHARGE_CURRENT__ */
         #else /*__CHARGER_USB_DETECT_WIHT_ONE_EINT__*/
         if(pmu_is_chr_det())
         {
            if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT)                                   
               pmu_set_chr_cur_level(pmu_ret_chr_current());
#if defined(__CHINA_CHARGER_STANDARD__)
            else if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT_NON)                                   
               pmu_set_chr_cur_level(pmu_ret_usb_current());
#endif
            else if(chr_usb_detect.chr_usb_present == USB_PRESENT)                                                                                             
            {  
               #ifdef __USB_MULTI_CHARGE_CURRENT__
               if (bmt_support_usb_charge()) /* If not support, charging current is not set here. */
                   pmu_set_chr_cur_level(pmu_ret_usb_current());
               #else /* __USB_MULTI_CHARGE_CURRENT__ */             
                   pmu_set_chr_cur_level(pmu_ret_usb_current());
               #endif /* __USB_MULTI_CHARGE_CURRENT__ */
            }
         }
         #endif/*defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)*/
      #else /*__USB_ENABLE__*/
         if(pmu_is_chr_det())
         {
            pmu_set_chr_cur_level(pmu_ret_chr_current());
         }
      #endif/*__USB_ENABLE__*/
   #endif /* defined(MT6238PMU) */
}

/*************************************************************************
* FUNCTION
*	pmic_adpt_reg_chr_usb
*
* DESCRIPTION
*	To register charger and usb callback function to PMIC
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_reg_chr_usb(void)
{
   #if defined(MT6318)/*XXXXX*/
      /*PMIC initilaizeation*/
      //pmic_customization_init();
      #if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
      /* Create adc object first here. */
	   chr_usb_detect.chr_usb_adc_logical_id = adc_sche_create_object(MOD_BMT, chr_usb_detect.chr_usb_adc,10,3, KAL_TRUE);
      #endif
      /*PMIC uses charger's interrupt*/
      #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
      PMIC_ChrDet_Registration(AC_CHR, CHRDET_HISR);
      #else
      PMIC_ChrDet_Registration(AC_CHR, CHR_USB_EINT_HISR);   
      #endif
   
      if(pmic_is_chr_det(AC_CHR)) 
         PMIC_CHRDET.pmic_ac_det();	     	       
      
      if(pmic_is_chr_det(USB_CHR)) 
      {
   	     if(PMIC_CHRDET.pmic_usb_det!=NULL) 	
      	    PMIC_CHRDET.pmic_usb_det();	   	   	         
      }   
   
      #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
      EINT_Registration(gCHRDET_EINT_NO,KAL_TRUE,LEVEL_LOW,PMIC_HISR, KAL_TRUE);      
      #else
      EINT_Registration(chr_usb_detect.chr_usb_eint,KAL_TRUE,LEVEL_LOW,PMIC_HISR, KAL_FALSE);
      EINT_SW_Debounce_Modify(chr_usb_detect.chr_usb_eint, 20);
      #endif
   #elif defined(MT6305)
      #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
      EINT_Registration(gCHRDET_EINT_NO,KAL_TRUE,LEVEL_HIGH,CHRDET_HISR, KAL_TRUE);
      //#endif //__CHARGER_USB_DETECT_WIHT_ONE_EINT__
      #else
        // #ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      EINT_Registration(chr_usb_detect.chr_usb_eint,KAL_TRUE,LEVEL_HIGH,CHR_USB_EINT_HISR, KAL_FALSE);
	   chr_usb_detect.chr_usb_adc_logical_id = adc_sche_create_object(MOD_BMT, chr_usb_detect.chr_usb_adc,10,3, KAL_TRUE);
	   #endif
   #elif defined(MT6238PMU)
      #if !defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
      EINT_Registration(gCHRDET_EINT_NO,KAL_TRUE,LEVEL_LOW,CHRDET_HISR, KAL_TRUE);
      #else
      EINT_Registration(chr_usb_detect.chr_usb_eint,KAL_TRUE,LEVEL_LOW,CHR_USB_EINT_HISR, KAL_FALSE);
	   chr_usb_detect.chr_usb_adc_logical_id = adc_sche_create_object(MOD_BMT, chr_usb_detect.chr_usb_adc,10,3, KAL_TRUE);
	   #endif
   #elif defined(MT6223PMU)
      #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
      EINT_Registration(gCHRDET_EINT_NO,KAL_TRUE,LEVEL_LOW,CHRDET_HISR, KAL_TRUE);
	   #endif
   #endif //MT6318
}

/*************************************************************************
* FUNCTION
*	pmic_adpt_reg_usb_int
*
* DESCRIPTION
*	To register usb ISR function.
*
* PARAMETERS
*	ACT_Polarity - - interrupt polarity (if using EINT)
*  reg_hisr       - ISR callback function to register
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_reg_usb_int(kal_bool ACT_Polarity, void (reg_hisr)(void))
{
#ifdef MT6318	
	/*XXXXX*/
	#if (!defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__))
		PMIC_ChrDet_Registration(USB_CHR, reg_hisr);   /* called by USB to register its detection handler  */
	#endif
#else
	#ifdef _USB_VBUS_DETECT_WITH_NIRQ_  /* Only in EVB because EINT is not enough, NIRQ can be seen as EINT */
		USB_NIRQ_Registration(reg_hisr);
	#else
		#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) /*if defined, than registered at bmt_task_main.c */
		EINT_Registration(g_usb_eint_no, KAL_TRUE, ACT_Polarity, reg_hisr, KAL_TRUE);
		#endif
	#endif
#endif
}

/*************************************************************************
* FUNCTION
*	pmic_adpt_set_usb_polarity
*
* DESCRIPTION
*	To set usb interrupt polarity(if using EINT)
*
* PARAMETERS
*	ACT_Polarity - - interrupt polarity
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_set_usb_polarity(kal_bool ACT_Polarity)
{
	/* for charger USB, charger will handle this part */	
	#if !defined(MT6318) && !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(_USB_VBUS_DETECT_WITH_NIRQ_)
	EINT_Set_Polarity(g_usb_eint_no,ACT_Polarity);
	#endif /* MT6318*/
}

/*************************************************************************
* FUNCTION
*	pmic_adpt_is_chr_det
*
* DESCRIPTION
*	To ask if a charger or usb is detected.
*
* PARAMETERS
*	type  - charger or usb
*
* RETURNS
*	kal_bool
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
kal_bool pmic_adpt_is_chr_det(pmic_chr_type type)
{
#if defined(MT6318)
   chr_type    chr_usb;
   
   chr_usb = (type==PMIC_AC_CHR)? AC_CHR: USB_CHR;
   return pmic_is_chr_det(chr_usb);
#else
   return KAL_FALSE;
#endif
}

/*************************************************************************
* FUNCTION
*	pmic_adpt_is_chr_valid
*
* DESCRIPTION
*	To ask if a charger is valid or not
*
* PARAMETERS
*	None
*
* RETURNS
*	kal_bool
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
kal_bool pmic_adpt_is_chr_valid(void)
{
#if defined(MT6318)
   return pmic_is_chr_valid();
#else
   return KAL_TRUE;
#endif
}

/*************************************************************************
* FUNCTION
*	pmic_adpt_set_vsim
*
* DESCRIPTION
*	To set Vsim voltage
*
* PARAMETERS
*	pmic_adpt_vsim_volt  - voltage value
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_set_vsim(pmic_adpt_vsim_volt  volt)
{
#if defined(PMIC_VSIM_SEL)
   if (volt == PMIC_VSIM_1_8)
   {
   #if defined(MT6318)
      pmic_vsim_sel(VSIM_1_8);
   #elif defined(MT6223PMU) || defined(MT6238PMU)
      pmu_set_vsim_sel(VSIM_SEL_1_8);
   #endif
   }
   else
   {
   #if defined(MT6318)
      pmic_vsim_sel(VSIM_3);
   #elif defined(MT6223PMU) || defined(MT6238PMU)
      pmu_set_vsim_sel(VSIM_SEL_3_0);
   #endif
   }
#endif
}

/*************************************************************************
* FUNCTION
*	pmic_adpt_speaker_enable
*
* DESCRIPTION
*	To enable or disable speaker
*
* PARAMETERS
*	kal_bool
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_speaker_enable(kal_bool enable)
{
#if defined(PMIC_AUDIO_AMP)
   #if defined(MT6318)
   pmic_speaker_enable(enable);
   #endif
#endif
}

#endif /*!defined(__FUE__)*/

/*************************************************************************
* FUNCTION
*	pmic_adpt_usb_ldo_enable
*
* DESCRIPTION
*	To enable or disable Vusb LDO
*
* PARAMETERS
*	kal_bool
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
* external_global
*
*************************************************************************/
void pmic_adpt_usb_ldo_enable(kal_bool enable)
{
   #if defined(MT6318)
      pmic_usb_regulator_enable(enable);
   #endif
}
