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
 *    pwic.h
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef PWIC_H
#define PWIC_H

#if defined(MT6318)
   #include "pmic6318_sw.h"
   #define PMIC_DET_USB_CHR
   #define PMIC_USB_SEND_PLUG_ILM
   #define PMIC_VSIM_SEL
   #define PMIC_AUDIO_AMP
   #ifndef PMIC_PRESENT
   #define PMIC_PRESENT
   #endif
#elif defined(MT6305)
   #ifndef PMIC_PRESENT
   #define PMIC_PRESENT
   #endif

#elif defined(MT6223PMU)
   #include "pmu_sw.h"
   #define PMIC_FIXED_3_ADC_CH
   #define PMIC_FIXED_CHR_EINT
   #ifndef PMIC_PRESENT
   #define PMIC_PRESENT
   #endif

   #if defined(__USB_ENABLE__)
   #error "Error!! PMIC MT6223P doesn't support USB. "
   #endif

#elif defined(MT6238PMU)
   #include "pmu_sw.h"
   #define PMIC_FIXED_3_ADC_CH
   #define PMIC_FIXED_CHR_EINT
   #ifndef PMIC_PRESENT
   #define PMIC_PRESENT
   #endif

#endif

#if defined(PMIC_DET_USB_CHR)
   #define PMIC_WAIT_USB_FOR_CHARGING
#endif

#if defined(PMIC_FIXED_3_ADC_CH)
/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */
#define PMIC_ADC_VCHARGER_CH_NUM     PMU_ADC_VCHARGER_CH_NUM
#define PMIC_ADC_VISENSE_CH_NUM      PMU_ADC_VISENSE_CH_NUM
#define PMIC_ADC_VBAT_CH_NUM         PMU_ADC_VBAT_CH_NUM

/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMIC_ADC_FACTOR_VBAT      PMU_ADC_FACTOR_VBAT
#define PMIC_ADC_FACTOR_VISENSE   PMU_ADC_FACTOR_VISENSE
#define PMIC_ADC_FACTOR_VCHARGER  PMU_ADC_FACTOR_VCHARGER

#endif

#if defined(PMIC_FIXED_CHR_EINT)
#define PMIC_CHR_EINT_PIN      PMU_CHR_EINT_PIN
#endif

typedef enum 
{
   PMIC_AC_CHR=0,
   PMIC_USB_CHR
}pmic_chr_type;

typedef enum 
{   
   PMIC_VSIM_1_8=0,
   PMIC_VSIM_3_0
}pmic_adpt_vsim_volt;

extern kal_bool DRV_POWERON(void);
extern void DRV_POWEROFF(void);
extern void PW_SetEINT1Conf(kal_uint8 state);
extern void PW_PowerInit(void);
extern void BMT_Charge(char data);
extern void PW_update_flags(void);
kal_bool bmt_is_chr_exist(kal_uint8 power_on);

/* PMIC adaptation Function*/
extern void pmic_adpt_init(void);
extern void pmic_adpt_adc_measure(kal_bool on);
extern void pmic_adpt_set_chr_current(void);
extern void pmic_adpt_reg_chr_usb(void);
extern void pmic_adpt_reg_usb_int(kal_bool ACT_Polarity, void (reg_hisr)(void));
extern void pmic_adpt_set_usb_polarity(kal_bool ACT_Polarity);
extern kal_bool pmic_adpt_is_chr_det(pmic_chr_type type);
extern kal_bool pmic_adpt_is_chr_valid(void);
extern void pmic_adpt_set_vsim(pmic_adpt_vsim_volt  volt);
extern void pmic_adpt_speaker_enable(kal_bool enable);
extern void pmic_adpt_usb_ldo_enable(kal_bool enable);

#endif   /* PWIC_H */

