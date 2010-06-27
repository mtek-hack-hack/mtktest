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
 *    b2psi.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PMIC 6318 driver.
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

#ifndef _PMIC6318_SW_H
#define _PMIC6318_SW_H

typedef enum 
{
	R_LED=0x3000,
	G_LED=0x4000,
	B_LED=0x5000,
	KP_LED=0x6000,
	BL_LED=0x7000 
}pmic_led_type;
typedef enum 
{
   LED_CURRENT_12=0x0,
   LED_CURRENT_16=0x20,
   LED_CURRENT_20=0x40,
   LED_CURRENT_24=0x60
}pmic_led_current;
typedef enum 
{
   VB_VD=0,
   VB_VTCXO   
}vb_vol;

typedef enum 
{   
   VSIM_1_8=0,
   VSIM_3   
}sim_vol;
typedef enum 
{
   VD_NORMAL=0,
   VD_0_9   
}vd_sel;

typedef enum 
{
   CHR_CURRENT_50=0,
   CHR_CURRENT_90,
   CHR_CURRENT_150,
   CHR_CURRENT_225,
   CHR_CURRENT_300,
   CHR_CURRENT_450,
   CHR_CURRENT_650,
   CHR_CURRENT_800
}pmic_charging_current;

typedef enum 
{
   VSIM_LDO=0,
   VTCXO_LDO,
   VRTC_LDO,   
   VM_LDO,
   VA_LDO,
   VD_LDO   
}pmic_ldo;

typedef enum 
{
   MISC_STAT_VISENSE=0,
   MISC_STAT_VBOUT,
   MISC_STAT_USB_PWR,
   MISC_STAT_VASW_SEL,
   MISC_STAT_VASW,   
   MISC_STAT_MC_SEL,
   MISC_STAT_MC,
   MISC_STAT_VIRBRATOR,
   MISC_STAT_VIRBRATOR_SEL
}pmic_misc_stat;

typedef enum 
{
   CHR_STAT_OV=0,   //0
   CHR_STAT_CHRDET,//1
   CHR_STAT_BAT_ON,//2
   CHR_STAT_AC_DET,//3
   CHR_STAT_USB_DET,//4   
   CHR_STAT_CV,//5
   CHR_STAT_CHRG_DIS //6
}pmic_chr_stat;

typedef enum 
{
   NO_CHARGING=0,
   CC_MODE,
   CV_MODE      
}pmic_chr_mode;
typedef enum 
{
   AC_CURRENT_50=0,
   AC_CURRENT_875=1,
   AC_CURRENT_150=2,
   AC_CURRENT_225=3,
   AC_CURRENT_300=4,
   AC_CURRENT_450=5,
   AC_CURRENT_650=6,
   AC_CURRENT_800=7   
}ac_current;
typedef enum 
{
   USB_CURRENT_50=0,
   USB_CURRENT_875=1,
   USB_CURRENT_150=2,
   USB_CURRENT_225=3,
   USB_CURRENT_300=4,
   USB_CURRENT_450=5,
   USB_CURRENT_650=6,
   USB_CURRENT_800=7
}usb_current;


typedef enum 
{
   AC_CHR=0,
   USB_CHR
}chr_type;

typedef enum 
{
   PMIC_ADC_OFF=0,
   PMIC_ADC_ISENSE,
   PMIC_ADC_VBAT,
   PMIC_ADC_ISENSE_VBAT
}adc_type;
typedef enum 
{
   DEALY_200u=0,
   DEALY_400u,
   DEALY_500u,
   DEALY_600u      
}charge_pumpdelay_enum;

typedef enum 
{
   VASW_3_3V =0,
   VASW_2_8V
}vasw_a_sel_enum;

typedef enum 
{
   VMC_2_8V =0,
   VMC_3V
}vmc_sel_enum;


typedef enum 
{
   VIBRATOR_1_8V =0,
   VIBRATOR_3_2V
}vibrator_sel_enum;

typedef enum 
{
   CHARGE_PUMP_LEVEL3 =0,
   CHARGE_PUMP_LEVEL2 =4,   
   CHARGE_PUMP_LEVEL1 =8
}charge_pump_current_enum;

typedef enum
{
   CHARGE_PUMP_CTRL_CLR =0,
   CHARGE_PUMP_CTRL_SET =16
}charge_pump_ctrl_enum;

typedef enum 
{
   UV_290 =0,
   UV_275 =1,
   UV_260 =2,
   UV_250 =3
}UV_voltage_enum;

typedef struct
{
   pmic_led_type type;
   pmic_led_current current;
   kal_uint8 duty_cycle;   
}pmic_led_struct;

typedef struct 
{
	void (*pmic_ac_det)(void);
	void (*pmic_usb_det)(void); 
}pmic_chrdect_callbac_struct;


/*Function*/
extern void pmic_init(void);
extern kal_uint8 pmic_chr_status(pmic_chr_stat status);
extern kal_uint8 pmic_ldo_status(pmic_ldo ldo);
extern void pmic_usb_current_ctrl(usb_current current);
extern void pmic_ac_currnet_ctrl(ac_current current);
extern void pmic_usb_regulator_enable(kal_bool enable);
extern void pmic_speaker_gain(kal_uint8 gain);
extern void pmic_chr_enable(kal_bool enable);
extern void pmic_usb_enable(kal_bool enable);
extern void pmic_chr_pump_enable(kal_bool enable);
extern void pmic_vasw_enable(kal_bool enable);
extern void pmic_vd_sel(vd_sel sel);
extern void pmic_vb_sel(vb_vol sel);
extern void pmic_vmc_enable(kal_bool enable);
extern void pmic_vsim_sel(sim_vol vol);
extern void pmic_speker_enable(kal_bool enable);
extern void pmic_vibrator_enable(kal_bool enable);
extern void pmic_charge_current_offset(kal_uint8 offset);
extern void pmic_rgb_dim_clk_setting(kal_uint32 clk);
extern void pmic_led_enable(pmic_led_type type, kal_bool enable);
extern void pmic_led_config(pmic_led_struct *led_conf);
extern kal_bool pmic_is_chr_det(chr_type type);
extern kal_bool pmic_is_chr_valid(void);
extern void pmic_write_to_register_save(kal_uint8 data, kal_uint16 register_index);
extern void PMIC_ChrDet_Registration(chr_type type, void (*Callback)(void));
extern void PMIC_HISR(void);
extern void pmic_charge_pump_init(kal_uint8 value);
extern void pmic_adc_measure_div2(kal_bool enable);
extern void pmic_clear_ov(void);
extern void pmic_pump_delay(charge_pumpdelay_enum delay);
extern void pmic_sim_leveltype(kal_bool enable);
extern void pmic_sw_sel(vasw_a_sel_enum value);
extern void pmic_vibrator_sel(vibrator_sel_enum value);
extern void pmic_usb_chr_enable(kal_bool enable);
extern void pmic_customization_init(void);
extern void pmic_adc_measure_sel(adc_type sel);
extern void pmic_adc_measure_sel_fast(adc_type sel);
extern void pmic_bl_div_bypass(kal_bool enable);
extern void pmic_bl_dim_clk_setting(kal_uint32 clk);
extern void pmic_chr_pump_current_level(kal_uint32 level);
extern void pmic_power_save_enable(kal_bool enable);
extern void pmic_set_UV_vol(UV_voltage_enum voltage);
extern void pmic_audio_diffential_enable(kal_bool enable);
extern void pmic_charging_currnet_ctrl(pmic_charging_current current);
extern void pmic_speaker_enable(kal_bool enable);
extern void pmic_vmc_sel(vmc_sel_enum sel);

/* the following are for LCD backlight PWM and for MMI. */
extern void pmic_pwm_level(kal_uint8 level);
extern kal_uint8 pmic_pwm_current_level(void);
extern void pmic_pwm_configure(kal_uint32 freq, kal_uint8 duty);
extern void pmic_pwm_start(void);

/* the following are declared in pmic6318_test_api.c. */
extern void pmic_get_ac_usb_status(chr_type type, kal_bool *chr_enable, kal_uint32 *current);
extern void pmic_get_LED_config(pmic_led_type type, kal_uint8 *duty, kal_uint32 *current);
extern void pmic_get_rgb_dim(kal_bool *pump_enable, kal_uint32 *pump_current, kal_uint32 *clk);
extern void pmic_get_BL_dim(kal_bool *div_enable, kal_uint32 *clk);
extern kal_uint8 pmic_get_speaker_stat(void);
extern kal_uint8 pmic_get_speaker_gain(void);
extern void pmic_get_misc_ldo_stat(pmic_misc_stat type, kal_bool *enable);
extern kal_uint8 pmic_reg_read(kal_uint16 register_index);
extern void pmic_reg_write(kal_uint8 data, kal_uint16 register_index);

#endif  

