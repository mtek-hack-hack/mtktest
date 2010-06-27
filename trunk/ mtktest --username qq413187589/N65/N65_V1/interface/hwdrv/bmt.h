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
 *    bmt.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for Battery Management Task.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef _BMT_H
#define _BMT_H

#include "adc.h"
/*3 is for charging*/
#define BMT_MAX_CHANNEL_TOTAL    4
/*
#ifdef __BMT_CHECK_CHARGER__
#define BMT_MAX_CHANNEL    4
#else
#define BMT_MAX_CHANNEL    3
#endif
*/
#define MAX_CHANNEL     (ADC_MAX_CHANNEL*2+BMT_MAX_CHANNEL_TOTAL) /*engineering mode, chargeing mode, and MMI mode*/

#define ADC_BMT_VBAT          0
#define ADC_BMT_VISENSE       1
#define ADC_BMT_VBATTMP       2
#define ADC_BMT_VCHARGER	   3

/*precharge threshold*/
#define BMT_PRECHARGE_THRESHOLD  3300000


typedef void (* CHR_FUNC)(void);
typedef void (* ADC_FUNC)(kal_uint8 adc_sche_id);

/*Power key position*/

#if 0
#ifndef CANNON
/* under construction !*/
#else
/* under construction !*/
#endif
#endif 


typedef enum{
	PWRKEYPWRON = 0,
	CHRPWRON	= 1,
	RTCPWRON = 2,
	CHRPWROFF = 3,
	WDTRESET = 4, /*NORMAL*/
	ABNRESET = 5,  /*ABNORMAL RESET*/
	USBPWRON = 6,  
	USBPWRON_WDT = 7,
	PRECHRPWRON = 8,
	UNKNOWN_PWRON = 0xF9	
}power_on_enum;
/*BatType*/
#define  LIBAT                            0
#define  NIBAT                            1

/*extern charger state*/
#define  DETECTCHRIN                      0x0
#define  DETECTCHROUT                     !DETECTCHRIN

/*bat_state*/
#define  CHR_PRE                          0
#define  CHR_FAST                         1
#define  CHR_TOPOFF                       2
#define  CHR_BATFULL                      3
#define  CHR_ERROR                        4
#define  CHR_HOLD                         5

/*BMT Minor STATE. When Charger is plugged in, charge is enable or not?*/
#define  PMIC_CHARGEOFF                   0   /*pmictrl_state*/
#define  PMIC_CHARGEON                    1   

/**/
#define idle_mode                         0
#define talk_mode                         1
#define swoff_mode                        2

/*TON,TOFF*/
#define  CHRTON                           0
#define  CHRTOFF                          1

#define BMT_SaftyTimer_On  1
#define BMT_SaftyTimer_Off 0 

#define  bmt_evaluate_value		10

/*power on factors*/
typedef enum{
 	PWR_FACTOR_POWER_KEY = 0,
	PWR_FACTOR_CHARGER_IN,
 	PWR_FACTOR_USB_IN,
 	PWR_FACTOR_RTC_EXPIRE,
 	PWR_FACTOR_WDT_RESET,
 	PWR_FACTOR_NORMAL_RESET_FLG,
 	PWR_FACTOR_CHRPWRON_FLG,
 	PWR_FACTOR_USBMS_PWRON_FLG,
 	PWR_FACTOR_RTCPWRON_FLG,
 	PWR_FACTOR_PRECHRPWRON_FLG,
 	PWR_FACTOR_FOTAPWRON_FLG,

 	PWR_FACTOR_MAX
}pwr_factor_enum;

typedef enum{
	CHARGER_PRESENT,
#if defined(__CHINA_CHARGER_STANDARD__)
	CHARGER_PRESENT_NON,
#endif
	USB_PRESENT,
	NO_PRESENT
}charger_usb_present_enum;

typedef struct{
	void (*measure_func)(kal_uint8);
	void (*read_back)(kal_uint8); 
}BMT_MeasFuncs;

typedef enum {
	bmt_chr_in=0,
   bmt_chr_out 
}Charger_Status;


typedef enum{
	BMT_AC_IN,
	BMT_USB_IN	
}bmt_usb_charger_enum;

typedef enum{	
	USB_IN_STATE,
	USB100_STATE,
	USB500_STATE,
	USB_OUT_STATE,
	AC_IN_STATE,
	AC_OUT_STATE,
	USB_INIT_STATE
}bmt_usb_state_enum;

typedef enum {
	VBAT_UEM_CHR_OUT=0,
	VBAT_UEM_CHR_OUT_FIRST=1,
	VBAT_UEM_CHR_IN=2,
	VBAT_UEM_CHR_IN_FISRT=3
}VBAT_UEM_CHR_ENUM;
/*Engineering mode*/
typedef enum {
   vbat_adc_channel=0,
   visense_adc_channel,
   vbattmp_adc_channel,
   battype_adc_channel,
   vcharger_adc_channel,
   pcbtmp_adc_channel,
   aux_adc_channel,
   chr_usb_adc_channel,
   otg_vbus_adc_channel,
   rftmp_adc_channel
} adc_channel_type;

typedef struct {
   kal_uint8               bat_state;
   kal_uint8               pmictrl_state;   /*pmic control on,off*/
   kal_uint8               call_state;   /*mobile state*/
   kal_uint8               PWRon;
   kal_uint8               BatType;
   kal_uint8               EINT2STATE;
   kal_uint8               highfull;
   VBAT_UEM_CHR_ENUM		     VBAT_UEM; // state of UEM VBAT measurement 
   kal_hisrid              hisr;
} BMTStruct;

typedef struct {
   kal_uint8    TON;/*sec*/
   kal_uint8    TOFF;/*sec*/
} CHRTStruct;

typedef struct {
   kal_int32 VBAT;
   kal_int32 ICHARGE;
   kal_int32 BATTMP;
   kal_int32 VCHARGER;
   //kal_uint8 BATTYPE;
} BATPHYStruct;

typedef struct {
   kal_int32  TEMPA12;   
   kal_int32  TEMPA23;  
   kal_int32  TEMPM12;
   kal_int32  TEMPM23;
   kal_int32  TEMPSCALE;
} VolToTempStruct;

/*Customizae Keypad*/
typedef struct {
/*GPIO control*/   
#ifndef  __CUST_NEW__
   kal_uint8 GPIO_CHRCTRL;
   kal_uint8 GPIO_BATDET;
   kal_uint8 GPIO_VIBRATOR;
#endif  /* __CUST_NEW__ */
/*Check Phy parameters,Maybe changed*/
   kal_int32 Typical_LI_BATTYPE;
   kal_int32 Typical_NI_BATTYPE;
   kal_int32 ICHARGE_ON_HIGH;
   kal_int32 ICHARGE_ON_LOW;
   kal_int32 ICHARGE_OFF_HIGH; //??50000
   kal_int32 V_FAST2TOPOFF_THRES;
   kal_int32 BATTMP_MINUS_40C;
   kal_int32 BATTMP_0C;
   kal_int32 BATTMP_45C;
   kal_int32 MAX_VBAT_LI;
   kal_int32 MAX_VBAT_NI;
   kal_int32 V_PRE2FAST_THRES;
   kal_int32 I_TOPOFF2FAST_THRES; /*250ma,TOPOFF->FAST*/
   kal_int32 I_TOPOFF2FULL_THRES;  /*120ma,TOPOFF->BATFULL*/
   kal_int32 V_FULL2FAST_THRES; /*BATFULL->FAST*/
   kal_int32 V_TEMP_FAST2FULL_THRES_NI;  /*50oC,FAST->BATFULL*/
   kal_int32 V_FULL2FAST_THRES_NI;
   kal_int32 FAST_ICHARGE_HIGHLEVEL; /*600ma,for table search*/
   kal_int32 FAST_ICHARGE_LOWLEVEL;  /*400ma,for table search*/
   kal_int32 V_PROTECT_HIGH_LI;
   kal_int32 V_PROTECT_LOW_LI;
   kal_int32 VCHARGER_HIGH;
   kal_int32 VCHARGER_LOW;
   /*Time delay*/
   /* PRE CHARGE ,search table*/
   /*TON = 3s,TOFF=2s*/
   kal_uint32 PRE_TON;
   kal_uint32 PRE_TOFF;

/* FAST CHARGE ,search table*/
/*TON = 3s,TOFF=0s*/
   kal_uint32 TOPOFF_TON;
   kal_uint32 TOPOFF_TOFF;
   
   kal_uint32 BATFULL_TON_LI;  /*unit : second*/
   kal_uint32 BATFULL_TOFF_LI;
   kal_uint32 BATFULL_TON_NI;  /*unit : second*/
   kal_uint32 BATFULL_TOFF_NI;
   kal_uint32 BATFULL_TOFF;
   kal_uint32 BATHOLD_OFF;
   
   double  ADC_ISENSE_RESISTANCE_FACTOR;        /*1/0.4*/
   kal_uint32 bmt_measure_discard_time; /*24 ticks*/

   ADC_CALIDATA adc_cali_param;
/*ratio = adc_volt_factor/100*/
   kal_uint16 adc_volt_factor[ADC_MAX_CHANNEL];   
   kal_uint8 TONOFFTABLE[6][2];
   kal_int32 CurrOffset[3];
   kal_bool  bmt_check_temp;
   kal_bool	 bmt_check_charger;   
} bmt_customized_struct;

#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
typedef struct{
	kal_bool chr_usb_state;	// indicate cable is plugged in or not for eint trigger level setting
	volatile charger_usb_present_enum chr_usb_present;	// is charger or usb presnet or not
	kal_uint8 chr_usb_adc_logical_id;	// logical id of adc scheduler
	kal_uint8 chr_usb_eint;	// eint number for charger and usb
	kal_uint8 chr_usb_adc;	// adc channel to measure charger or usb
	kal_int32 chr_usb_volt;	// voltage to distinguish between charger with usb
}chr_usb_detect_struct;
#endif

extern void adc_sche_readback(void* msg_ptr);
extern void adc_sche_measure(void* msg_ptr);
extern void bmt_adc_sche_measure(void* msg_ptr);/*For BMT */
extern void bmt_adc_sche_readback(void* msg_ptr);/*For BMTs*/ 
extern kal_int32 volt2temp(kal_int32 _volt);
extern kal_uint8  bmt_bmtid_adcscheid[BMT_MAX_CHANNEL_TOTAL];
/*To provide customized data*/
extern kal_uint8 custom_adc_get_channel(adc_channel_type type);

/*usb charge*/
extern kal_bool bmt_support_usb_charge(void);
/*voltage to temperature*/
extern VolToTempStruct *bmt_get_customized_volTOtemp(void);    
/*charing parameters*/
extern bmt_customized_struct *bmt_get_customized_chr_para(void);  
extern kal_int32 bmt_get_chr_usb_detect_volt(void);
extern kal_int32 adc_adc2vol(kal_uint8 chann,double adcVoltage);
extern void adc_sche_set_timer_page_align(kal_bool page_align);
extern bmt_usb_charger_enum IsUSBorCharger(void);
extern void adc_pwrdown_enable(void);
extern void adc_pwrdown_disable(void);
extern kal_bool bmt_is_wdt_power(void);
extern bmt_customized_struct *bmt_charing_para; 
extern kal_uint8 BMT_MAX_CHANNEL;
extern kal_uint32 adc_sche_rw_status;
#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
extern chr_usb_detect_struct chr_usb_detect;
#endif
extern BMTStruct BMT;
#endif


