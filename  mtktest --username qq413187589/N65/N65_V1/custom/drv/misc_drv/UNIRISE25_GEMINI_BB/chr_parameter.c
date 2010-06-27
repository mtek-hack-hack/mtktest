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
 *    chr_parameter.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for charging parameters.
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
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "adc.h"
#include "bmt.h"
#include "batvalue.h"
#include "bmt.h"
#include "gpio_sw.h"
#if (defined(MT6318))
#include "pmic6318_sw.h"
#endif
#define _ADC_DETECT_USB_CHARGER_
//#define _GPIO_DETECT_USB_CHARGER_
#if defined (__CHINA_CHARGER_STANDARD__)
kal_uint16 standard_chr_flg;
#endif

/*GPIO control*/
bmt_customized_struct  bmt_custom_chr_def = 
{ 
#ifndef  __CUST_NEW__
   43,/*GPIO_CHRCTRL*/
   3,/*GPIO_BATDET*/
   4,/*GPIO_VIBRATOR*/
#endif  /* __CUST_NEW__ */

/*charing parameters*/
/*Check Phy parameters,Maybe changed*/
   1100000,/*Typical_LI_BATTYPE*/
   1100000,/*Typical_NI_BATTYPE*/
   1000000,/*ICHARGE_ON_HIGH*/
   20000,/*ICHARGE_ON_LOW*/
   1000000,/*ICHARGE_OFF_HIGH*/  //??50000
   4050000,/*V_FAST2TOPOFF_THRES*/
   2500000,/*BATTMP_MINUS_40C*/
   1469409,/*BATTMP_0C*/
   520042,/*BATTMP_45C*/ 
   6000000,/*MAX_VBAT_LI*/ 
   5500000,/*MAX_VBAT_NI*/ 
   3400000,/*V_PRE2FAST_THRES*/ 
   250000,/*I_TOPOFF2FAST_THRES*/  /*250ma,TOPOFF->FAST*/
   120000,/*I_TOPOFF2FULL_THRES*/   /*120ma,TOPOFF->BATFULL*/
   4110000,/*V_FULL2FAST_THRES*/  /*BATFULL->FAST*/
   414557,/*V_TEMP_FAST2FULL_THRES_NI*/   /*50oC,FAST->BATFULL*/
   4050000,/*V_FULL2FAST_THRES_NI*/ 
   600000,/*FAST_ICHARGE_HIGHLEVEL*/  /*600ma,for table search*/
   400000,/*FAST_ICHARGE_LOWLEVEL*/   /*400ma,for table search*/
   4050000,/*V_PROTECT_HIGH_LI*/
   3800000,/*V_PROTECT_LOW_LI*/
   6500000,/*VCHARGER_HIGH*/
   0,/*VCHARGER_LOW*/
/*Time delay*/
/* PRE CHARGE ,search table*/
/*TON = 3s,TOFF=2s*/
   3,/*PRE_TON*/
   2,/*PRE_TOFF*/

/* FAST CHARGE ,search table*/
/*TON = 3s,TOFF=0s*/
   3,/*TOPOFF_TON*/
   0,/*TOPOFF_TOFF*/

   6,/*BATFULL_TON_LI*/   /*unit : second*/
   0,/*BATFULL_TOFF_LI*/
   1,/*BATFULL_TON_NI*/   /*unit : second*/
   9,/*BATFULL_TOFF_NI*/
   6,/*BATFULL_TOFF*/
   10,/*BATHOLD_OFF*/

   2.5,/*ADC_ISENSE_RESISTANCE_FACTOR*/         /*1/0.4*/
   24, /*bmt_measure_discard_time*/ /*24 ticks*/

   //ADC_CALIDATA adc_cali_param 
   {
      {
         5524,
         5524,
         5524,
         5524,
         5524,
         5524,
         5524
      },
      {
         (23286),
         (23286),
         (23286),
         (23286),
      (23286),
      (23286),
         (23286)
      }
   },
   
   /*ratio = adc_volt_factor/100*/
   //const kal_uint16 adc_volt_factor[ADC_MAX_CHANNEL] 
   {
      100,
      100,
       50,
      250,
       50,
      50,/*NC*/
      100 /*NC*/
   },
   
   //const kal_uint8 TONOFFTABLE[6][2] = 
   {
      {7,1},
      {8,1},
      {9,1},
      {7,1},/*talk */
      {8,1},/*talk */
      {9,1}/*talk */
   },
   
   //const kal_int32 CurrOffset[3] =
   {
      100000, //100ma
      100000,
      100000
   },
   KAL_FALSE, /* enable checking temperature while charging */
   KAL_FALSE /* enable checking charging voltage while charging */	   
};

bmt_customized_struct *bmt_get_customized_chr_para(void)         
{
   return (&bmt_custom_chr_def);
}   
/*voltage to temperature*/
#define T1  0*1000000   /*0C*/
#define T2  25*1000000  /*25C*/
#define T3  50*1000000  /*50C*/

#define NTCR1 26490.0   /*resistor at 0C*/
#define NTCR2 10000.0   /*resistor at 25C*/
#define NTCR3 4171.0    /*resistor at 50C*/

#define PUR 24000.0      /*orginal registor*/
#define AVDD 2800000.0
#define SCALE 10.0

#define V1 (AVDD*(NTCR1/(NTCR1+PUR))) /*voltage at 0C*/
#define V2 (AVDD*(NTCR2/(NTCR2+PUR))) /*voltage at 25C*/
#define V3 (AVDD*(NTCR3/(NTCR3+PUR))) /*voltage at 50C*/

#define M12 (((T1-T2)*SCALE)/(V1-V2))  /*T1T2's slope */
#define M23 (((T2-T3)*SCALE)/(V2-V3))  /*T2T3's slppe*/

const kal_int32 TEMPM12  = M12;      /*T1T2's slope */
const kal_int32 TEMPM23  = M23;      /*T2T3's slppe*/

const kal_int32 TEMPV2 = V2;         /*boundary*/
const kal_int32 TEMPSCALE = SCALE;

const kal_int32 TEMPA12  = T1-M12/SCALE*V1;  /*T1T2's offset*/
const kal_int32 TEMPA23  = T2-M23/SCALE*V2;  /*T2T3's offset*/

VolToTempStruct  bmt_custom_volTotemp_def = { 
        T1-M12/SCALE*V1,/*T1T2's offset*/
        T2-M23/SCALE*V2,/*T2T3's offset*/
        M12,/*T1T2's slope */
        M23,/*T2T3's slppe*/
        SCALE
};        
         
VolToTempStruct *bmt_get_customized_volTOtemp(void)         
{
   return (&bmt_custom_volTotemp_def);
}   

/*usb charging*/
#if defined(__USB_ENABLE__)
const kal_bool enable_usb_charge = KAL_TRUE;
#else
const kal_bool enable_usb_charge = KAL_FALSE;
#endif

kal_bool bmt_support_usb_charge(void)
{
   // KAL_TRUE: charging directly without host's grant, KAL_FALSE: charging with host's grant
   return (enable_usb_charge);
}   
/*************************************************************************
* FUNCTION
*	bmt_charger_action
*
* DESCRIPTION
*	This function is to do something whenever AC is plug-in
*
* PARAMETERS
*	AC plug in or plug out
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __CUST_NEW__
   //#define BMT_CHARGER_ACTION_WITH_GPIO
   #undef BMT_CHARGER_ACTION_WITH_GPIO
   #ifdef BMT_CHARGER_ACTION_WITH_GPIO
   extern const char gpio_bmt_charger_action_pin;
   #endif
#endif /* __CUST_NEW__ */
void bmt_charger_action(kal_bool in)
{
   #ifdef __CUST_NEW__
      #ifdef BMT_CHARGER_ACTION_WITH_GPIO
      if(in==KAL_TRUE)
         GPIO_WriteIO(1, gpio_bmt_charger_action_pin);
      else
         GPIO_WriteIO(0, gpio_bmt_charger_action_pin);   
      #endif /*BMT_CHARGER_ACTION_WITH_GPIO*/
   #else /* __CUST_NEW__ */
   kal_uint16 gpio_pin=0xff;
      
   if(gpio_pin!=0xff)
   { 
      GPIO_ModeSetup(gpio_pin, 0);
      GPIO_InitIO(OUTPUT, gpio_pin);        
      if(in==KAL_TRUE)
         GPIO_WriteIO(1, gpio_pin);
      else
         GPIO_WriteIO(0, gpio_pin);   
   }      
   #endif /* __CUST_NEW__ */
}   
#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
#ifdef __CUST_NEW__
#if defined(_GPIO_DETECT_USB_CHARGER_) 
extern const char gpio_bmt_check_ac_usb_pin;
#endif /* defined(_GPIO_DETECT_USB_CHARGER_) */
#endif /* __CUST_NEW__ */
#if defined(__CHINA_CHARGER_STANDARD__) 
// usb is plugged in if  < 1V, otherwise AC charger non-standard 1~2V, standard >2V.
static const kal_int32	chr_usb_detect_volt = 1000000;//2000000;  
static const kal_int32	chr_detect_volt = 2000000;//2000000;  
#else
// usb is plugged in if  < 1.4V, otherwise it is charger.
static const kal_int32	chr_usb_detect_volt = 1400000;  
#endif
kal_int32 bmt_get_chr_usb_detect_volt(void)
{
   return (kal_int32)(chr_usb_detect_volt);
}   
/*************************************************************************
* FUNCTION
*	bmt_check_ac_usb
*
* DESCRIPTION
*	This function is to tell USB and AC
*
* PARAMETERS
*	measurement voltage
*
* RETURNS
*  AC or USB
*
* GLOBALS AFFECTED
*
*************************************************************************/
charger_usb_present_enum bmt_check_ac_usb(kal_int32 vol)
{
   kal_uint16 gpio_pin;
   kal_uint8  gpio_state;
   #ifdef _ADC_DETECT_USB_CHARGER_
   // use ADC to get voltage value (Analog method)
   /*use voltage to tell AC/USB*/
#if defined(__CHINA_CHARGER_STANDARD__)
   if(vol<chr_usb_detect_volt)      
      return USB_PRESENT;
   else if(vol< chr_detect_volt & vol>chr_usb_detect_volt)
   {
      standard_chr_flg = 2;
      return CHARGER_PRESENT_NON;
   }
   else 
   {
      standard_chr_flg = 1;     
      return CHARGER_PRESENT;  
   }
#else
   if(vol<chr_usb_detect_volt)      
      return USB_PRESENT;
   else 
      return CHARGER_PRESENT;  

#endif
   #elif defined(_GPIO_DETECT_USB_CHARGER_) 
   #ifdef __CUST_NEW__
   gpio_state=GPIO_ReadIO(gpio_bmt_check_ac_usb_pin);
   #else /* __CUST_NEW__ */
   /*use GPIO to tell AC/USB*/
   gpio_pin=1;/*GPIO port number*/
   GPIO_ModeSetup(gpio_pin, 0);
   GPIO_InitIO(INPUT, gpio_pin);
   gpio_state=GPIO_ReadIO(gpio_pin);
   #endif /* __CUST_NEW__ */
   if(gpio_state)      
      return USB_PRESENT;
   else 
      return CHARGER_PRESENT;        
   #endif                   
}   
#endif // __CHARGER_USB_DETECT_WIHT_ONE_EINT__

#ifdef __USB_ENABLE__
#ifdef __USB_MULTI_CHARGE_CURRENT__

#if defined(MT6305)
/* The max number is 8, and must be in strict-decreasing order.
   The maximun value must not be larger than 500 and the last
   value in the array must be zero.
*/
const kal_uint16  USB_CHARGE_CURRENT [] =
{
	 (450),
	 (0) /* zero must be in the last item. means no charging for USB. */
};

#define USB_CHARGE_CURRENT_TABLE_SIZE	(sizeof(USB_CHARGE_CURRENT) / sizeof(kal_uint16))
/*************************************************************************
* FUNCTION
*	usb_set_chr_current
*
* DESCRIPTION
*	This function is to set usb charging current. This can be customized
* by the board layout.
*
* PARAMETERS
*	index for USB_CHARGE_CURRENT []
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void usb_set_chr_current(kal_uint8 index)
{
	ASSERT(index < (USB_CHARGE_CURRENT_TABLE_SIZE -1));
    switch(index)
	{	
	case 0: /* 450 mA*/
		/* Set USB charging current for 450mA here. */
		break;
	default:
		break;
	}
	return;
}


const kal_uint8 USB_GetChargeCurrentTableSize(void)
{
	return USB_CHARGE_CURRENT_TABLE_SIZE;
}
#endif /* defined(MT6305) */

/* Below is just reference codes for MT6318 */
#if defined(MT6318)
extern void pmic_charging_currnet_ctrl(pmic_charging_current current);

/* The max number is 8, and must be in strict-decreasing order.
   The maximun value must not be larger than 500 and the last
   value in the array must be zero.
*/
const kal_uint16  USB_CHARGE_CURRENT [] =
{
	 (450),
	 (300),
	 (225),
	 (150),
	 (90),
	 (50),
	 (0) /* zero must be in the last item. means no charging for USB. */
};

#define USB_CHARGE_CURRENT_TABLE_SIZE	(sizeof(USB_CHARGE_CURRENT) / sizeof(kal_uint16))
static const pmic_charging_current  PMIC6318_USB_CHARGE_CURRENT[USB_CHARGE_CURRENT_TABLE_SIZE - 1] =
{
   CHR_CURRENT_450,
   CHR_CURRENT_300,
   CHR_CURRENT_225,
   CHR_CURRENT_150,
   CHR_CURRENT_90,
   CHR_CURRENT_50
};
void usb_set_chr_current(kal_uint8 index)
{
	pmic_charging_current   current;

	ASSERT(index < (USB_CHARGE_CURRENT_TABLE_SIZE - 1));
	pmic_charging_currnet_ctrl(PMIC6318_USB_CHARGE_CURRENT[index]);
	return;
}


const kal_uint8 USB_GetChargeCurrentTableSize(void)
{
	return USB_CHARGE_CURRENT_TABLE_SIZE;
}
#endif /* defined(MT6318) */

#endif /* __USB_MULTI_CHARGE_CURRENT__ */
#endif /* __USB_ENABLE__ */
