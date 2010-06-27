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
 *    pmic_custom.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if ( (defined(MT6318))  )
#include 	"kal_release.h"
#include 	"pmic6318_sw.h"

#if defined(__CHINA_CHARGER_STANDARD__)
#include    "bmt.h"
extern kal_uint16 standard_chr_flg; 
#endif
#define AUDIO_AMP_GAIN        14                /*0~21*/
#define CHARGE_PUMP_DELAY     DEALY_600u        /*DEALY_600u, DEALY_500u, DEALY_400u, DEALY_200u*/
#define CHARGE_CURRENT_OFFSET 3                 /*1~5*/
#define AC_CHR_CURRENT        CHR_CURRENT_650   /*CHR_CURRENT_800/650/450/300/225/150/90/50*/
#define USB_CHR_CURRENT       CHR_CURRENT_450   /*CHR_CURRENT_450/300/225/150/90/50*/
#define BL_CLK_DIV            KAL_TRUE          /*KAL_TRUE: BL_DIM_CLK max. 25000 Hz, KAL_FALSE: BL_DIM_CLK max. 1000 Hz*/
#define BL_DIM_CLK            25000             /*MAX 25000*/
#define RGB_DIM_CLK           1000              /*MAX 1000*/
#define UV_VOLTAGE            UV_290            /*UV_290, UV_275, UV_260, UV_250*/
#define POWER_SAVE_MODE       KAL_TRUE       
#define VIBRATOR_VOLTAGE      VIBRATOR_1_8V     /*VIBRATOR_1_8V, VIBRATOR_3_2V*/
#define VA_SW_VOLTAGE         VASW_2_8V			/*VASW_3_3V, VASW_2_8V*/
#define VMC_VOLTAGE           VMC_2_8V          /*VMC_2_8V, VMC_3V*/

/*
* FUNCTION 
*  pmic_customization_init
*
* DESCRIPTION
*     This function is to initialize setting of PMIC
*
* CALLS
*  None
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

void pmic_customization_init(void)
{
   pmic_led_struct r_cfg; 
  /*customization*/     
   /*charge pump initialization*/
   pmic_pump_delay(CHARGE_PUMP_DELAY);
   /*adc measure divider*/
 
   /*charging current offset*/
   pmic_charge_current_offset(CHARGE_CURRENT_OFFSET);   
   pmic_speaker_gain(AUDIO_AMP_GAIN);   
   /**/    
   /*BL setting*/
   /*on/off is removed to cusotm_equipment.c*/
   pmic_bl_div_bypass(BL_CLK_DIV);/*bypass divider*/
   pmic_bl_dim_clk_setting(BL_DIM_CLK);
   /*R/G/B setting*/   
   /*on/off is removed to cusotm_equipment.c*/
   pmic_rgb_dim_clk_setting(RGB_DIM_CLK);

   /*vibrator */
   pmic_vibrator_sel(VIBRATOR_VOLTAGE);
   /*set UV voltage*/
   pmic_set_UV_vol(UV_VOLTAGE);
   
   /*enable power save or not*/
   pmic_power_save_enable(/*POWER_SAVE_MODE*/KAL_FALSE);
   /*enable audio differential mode or not*/

   /* set Va_sw output voltage. */
   pmic_sw_sel(VA_SW_VOLTAGE);

   /* set VMC output voltage. */
   pmic_vmc_sel(VMC_VOLTAGE);

   r_cfg.type 		 = R_LED;
   r_cfg.current	 = LED_CURRENT_20;
   r_cfg.duty_cycle = 20;
   pmic_led_config(&r_cfg);   
   /*end of customization*/
}   
    
/*This function is used to return charging current according to 
charger(AC or USB) type */
pmic_charging_current pmic_return_current(chr_type chr)
{
   switch(chr)
   {
      case AC_CHR:
#if defined(__CHINA_CHARGER_STANDARD__)
        if(standard_chr_flg == 1)
         return AC_CHR_CURRENT;  
        else if( standard_chr_flg ==2)
         return USB_CHR_CURRENT; 
        else 
         return AC_CHR_CURRENT;
#else
         return AC_CHR_CURRENT;  

#endif
         break; 
      case USB_CHR:       
         return USB_CHR_CURRENT;
         break;
      default:
         return USB_CHR_CURRENT;
         break;          
   }        
}   
  
#endif

