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
 *    pmu_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for Power Management Unit driver.
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

#ifndef _PMU_SW_H
#define _PMU_SW_H

typedef enum 
{
	ICAL_RF_1_0=0,
	ICAL_RF_0_5=1,
	ICAL_RF_2_0=2,
	ICAL_RF_3_0=3
}pmu_icalrf_code;

typedef enum 
{
	ICAL_CORE_1_0=0,
	ICAL_CORE_0_5=1,
	ICAL_CORE_2_0=2,
	ICAL_CORE_3_0=3
}pmu_icalcore_code;

typedef enum 
{
	ICAL_IO_1_0=0,
	ICAL_IO_0_5=1,
	ICAL_IO_2_0=2,
	ICAL_IO_3_0=3
}pmu_icalio_code;

typedef enum 
{
	ICAL_M_1_0=0,
	ICAL_M_0_5=1,
	ICAL_M_2_0=2,
	ICAL_M_3_0=3
}pmu_icalm_code;

typedef enum 
{
	ICAL_SIM_1_0=0,
	ICAL_SIM_0_5=1,
	ICAL_SIM_2_0=2,
	ICAL_SIM_3_0=3
}pmu_icalsim_code;

typedef enum 
{   
   VSIM_SEL_1_8=0,
   VSIM_SEL_3_0
}pmu_vsim_volt;



typedef enum 
{
   CHR_CUR_OFFSET_NONE=0,
   CHR_CUR_OFFSET_PLUS_1=1,
   CHR_CUR_OFFSET_PLUS_2=2,
   CHR_CUR_OFFSET_MINUS_2=6,
   CHR_CUR_OFFSET_MINUS_1=7
}pmu_chr_cur_offset;

typedef enum 
{
   CHR_CUR_50=0,
   CHR_CUR_87_5=1,
   CHR_CUR_150=2,
   CHR_CUR_225=3,
   CHR_CUR_300=4,
   CHR_CUR_450=5,
   CHR_CUR_650=6,
   CHR_CUR_800=7
}pmu_chr_cur_level;


typedef enum 
{
   THERMAL_THRES_INIT=0x0000,
   THERMAL_THRES_PLUS_10C=0x0001,
   THERMAL_THRES_MINUS_20C=0x0010,
   THERMAL_THRES_MINUS_10C=0x0011
}pmu_chr_thermal_thres;

typedef enum 
{
   VOLT_STEP_INIT=0,
   VOLT_STEP_MINUS_1=1,
   VOLT_STEP_MINUS_2=2,
   VOLT_STEP_MINUS_3=3,
   VOLT_STEP_PLUS_4=4,
   VOLT_STEP_PLUS_3=5,
   VOLT_STEP_PLUS_2=6,
   VOLT_STEP_PLUS_1=7
}pmu_ref_volt_step;

typedef enum 
{
   VBG_VOLT_1_2_V = 0,
   VBG_VOLT_1_205_V = 1,
   VBG_VOLT_1_210_V = 2,
   VBG_VOLT_1_215_V = 3,
   VBG_VOLT_1_180_V = 4,
   VBG_VOLT_1_185_V = 5,
   VBG_VOLT_1_190_V = 6,
   VBG_VOLT_1_195_V = 7
}pmu_vbg_volt;

typedef enum 
{
   GPIO_DRV_8MA = 0,
   GPIO_DRV_4MA = 1
}pmu_gpio_drv_strength;

typedef enum 
{
   UVLO_VOLT_2_9_V=0,
   UVLO_VOLT_2_75_V=1,
   UVLO_VOLT_2_6_V=2,
   UVLO_VOLT_AS_DDLO=3
}pmu_uvlo_volt;

typedef enum 
{
   RBGSEL_INIT=0,
   RBGSEL_PLUS_1_STEP=1,
   RBGSEL_PLUS_2_STEP=2,
   RBGSEL_PLUS_3_STEP=3,
   RBGSEL_MINUS_4_STEP=4,
   RBGSEL_MINUS_3_STEP=5,
   RBGSEL_MINUS_2_STEP=6,
   RBGSEL_MINUS_1_STEP=7
}pmu_rbgsel;

typedef enum 
{
   IBGSEL_INIT=0,
   IBGSEL_PLUS_1_STEP=1,
   IBGSEL_MINUS_2_STEP=2,
   IBGSEL_MINUS_1_STEP=3
}pmu_ibgsel;

typedef enum 
{
   CK_SEL_10KHZ=0,
   CK_SEL_5KHZ=1
}pmu_cksel;

typedef enum 
{
   VBS_SEL_1200K=0,
   VBS_SEL_1320K=1,
   VBS_SEL_960K=2,
   VBS_SEL_1080K=3
}pmu_vbssel;

typedef enum 
{
   OV_HYS_ENB_LOWER=0,
   OV_HYS_ENB_HIGHER=1
}pmu_ov_hys_enb;

typedef enum 
{
   OV_THFREEZE_AUTO=0,
   OV_THFREEZE_FIXED=1
}pmu_ov_thfreeze;

typedef enum 
{
   SDM_1ST_ORDER = 0,
   SDM_2ND_ORDER = 1
}pmu_sdm_order;

typedef enum 
{
   PID_GAIN_P_0_25 = 0,
   PID_GAIN_P_0_375 = 1,
   PID_GAIN_P_0_5 = 2,
   PID_GAIN_P_0_75 = 3,
   PID_GAIN_P_1 = 4,
   PID_GAIN_P_1_5 = 5,
   PID_GAIN_P_2 = 6,
   PID_GAIN_P_3 = 7
}pmu_pid_gain_p;

typedef enum 
{
   PID_GAIN_0_015625 = 0,
   PID_GAIN_0_0234375 = 1,
   PID_GAIN_0_03125 = 2,
   PID_GAIN_0_046875 = 3,
   PID_GAIN_0_0625 = 4,
   PID_GAIN_0_09375 = 5,
   PID_GAIN_0_125 = 6,
   PID_GAIN_0_1875 = 7
}pmu_pid_gain;

typedef enum 
{
   PID_GAIN_D_2 = 0,
   PID_GAIN_D_3 = 1,
   PID_GAIN_D_4 = 2,
   PID_GAIN_D_6 = 3,
   PID_GAIN_D_8 = 4,
   PID_GAIN_D_12 = 5,
   PID_GAIN_D_16 = 6,
   PID_GAIN_D_24 = 7
}pmu_pid_gain_d;

typedef enum 
{
   VCORE_1_8V = 0,
   VCORE_1_2V = 1
}pmu_vcore_volt;

typedef enum 
{
   DCV_INTERNAL = 0,
   DCV_CLK_TCXO = 1
}pmu_dcv_ck;

typedef enum 
{
   ISEL_0_25 = 0,
   ISEL_1_5 = 1,
   ISEL_1 = 2,
   ISEL_2 = 3
}pmu_isel;

typedef enum 
{
   MODE_SET_PFM = 0,
   MODE_SET_PWM = 1
}pmu_mode_set;

typedef enum 
{
   MODE_CMP_LOW_OFFSET = 0,
   MODE_CMP_AUTO_ZERO = 1
}pmu_mode_cmp;

typedef enum 
{
   MODE_NDC = 0,
   MODE_AVE_CURRENT = 1
}pmu_mode_ave_current;

/* PFM max load current select. Can OR together. */
#define   PFM_MAX_160_MA_EN  0x08
#define   PFM_MAX_80_MA_EN   0x04
#define   PFM_MAX_40_MA_EN   0x02
#define   PFM_MAX_20_MA_EN   0x01

/* PFM max load resistor select. Can OR together*/
#define   PFM_RESISTOR_50_OHM 0x04
#define   PFM_RESISTOR_100_OHM 0x02
#define   PFM_RESISTOR_200_OHM 0x01

typedef enum 
{
   NDC_OFFSET_MINUS_3mV = 0,
   NDC_OFFSET_5mV = 1,
   NDC_OFFSET_12mV = 2,
   NDC_OFFSET_17mV = 3
}pmu_ndc_offset;

typedef enum 
{
   IASEL_50mV = 0,
   IASEL_100mV = 1,
   IASEL_150mV = 2,
   IASEL_200mV = 3
}pmu_iasel;

typedef enum 
{
   RSEL_32k = 0,
   RSEL_28k = 1,
   RSEL_24k = 2,
   RSEL_18k = 3
}pmu_rsel;

typedef enum 
{
	ICAL_USB_1_0=0,
	ICAL_USB_0_5=1,
	ICAL_USB_2_0=2,
	ICAL_USB_3_0=3
}pmu_icalusb_code;

typedef enum 
{
	CLK_SRC_FROM_CLKSQ=0,
	CLK_SRC_FROM_TCXO26M_CK=1
}pmu_clk_src_sel;

typedef enum 
{
	VTCXO_LDO_WITH_VTCXO_EN=0,
	VTCXO_LDO_WITH_RG_VTCXO_EN=1
}pmu_vtcxo_on_sel;

typedef enum 
{
	ICAL_SIM2_1_0=0,
	ICAL_SIM2_0_5=1,
	ICAL_SIM2_2_0=2,
	ICAL_SIM2_3_0=3
}pmu_icalsim2_code;

typedef enum 
{
	ICAL_MC_1_0=0,
	ICAL_MC_0_5=1,
	ICAL_MC_2_0=2,
	ICAL_MC_3_0=3
}pmu_icalmc_code;

typedef enum 
{   
   VMC_SEL_1_8=0,
   VMC_SEL_3_0
}pmu_vmc_volt;

typedef enum 
{
	ICAL_CAMERA_1_0=0,
	ICAL_CAMERA_0_5=1,
	ICAL_CAMERA_2_0=2,
	ICAL_CAMERA_3_0=3
}pmu_icalcamera_code;

typedef enum 
{   
   VCAMERA_SEL_2_8=0,
   VCAMERA_SEL_1_3
}pmu_vcamera_volt;

typedef enum 
{
	ICAL_SW_1_0=0,
	ICAL_SW_0_5=1,
	ICAL_SW_2_0=2,
	ICAL_SW_3_0=3
}pmu_icalsw_code;

typedef enum 
{   
   VSW_A_SEL_2_8=0,
   VSW_A_SEL_1_3
}pmu_vsw_a_volt;

typedef enum 
{
	ICAL_A_1_0=0,
	ICAL_A_0_5=1,
	ICAL_A_2_0=2,
	ICAL_A_3_0=3
}pmu_icala_code;

typedef enum 
{
	ICAL_TCXO_1_0=0,
	ICAL_TCXO_0_5=1,
	ICAL_TCXO_2_0=2,
	ICAL_TCXO_3_0=3
}pmu_icaltcxo_code;

typedef enum 
{
	VREF_BG_INIT=0,
	VREF_BG_PLUS_1_STEP=1,
	VREF_BG_PLUS_2_STEP=2,
	VREF_BG_PLUS_3_STEP=3,
   VREF_BG_MINUS_4_STEP=4,
   VREF_BG_MINUS_3_STEP=5,
   VREF_BG_MINUS_2_STEP=6,
   VREF_BG_MINUS_1_STEP=7
}pmu_vref_bg;

typedef enum 
{
	THR_SEL_INIT=0,
	THR_SEL_PLUS_10C=1,
	THR_SEL_MINUS_20C=2,
	THR_SEL_MINUS_10C=3
}pmu_thr_sel;

/* Charger external interrupt is fixed to 7. */
#if defined(MT6223PMU)
#define PMU_CHR_EINT_PIN      7
#elif defined(MT6238PMU)
#define PMU_CHR_EINT_PIN      8
#endif

/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */
#if defined(MT6223PMU)
#define PMU_ADC_VCHARGER_CH_NUM  4
#define PMU_ADC_VISENSE_CH_NUM   5
#define PMU_ADC_VBAT_CH_NUM      6
#elif defined(MT6238PMU)
#define PMU_ADC_VBAT_CH_NUM      4
#define PMU_ADC_VISENSE_CH_NUM   5
#define PMU_ADC_VCHARGER_CH_NUM  6
#endif

/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100
#define PMU_ADC_FACTOR_VCHARGER  250

/*Function*/
extern void pmu_init(void);
extern pmu_chr_cur_level pmu_ret_chr_current(void);
#if defined(MT6238PMU)
extern pmu_chr_cur_level pmu_ret_usb_current(void);
#endif /*MT6223PMU*/
extern kal_bool pmu_get_vrf_status(void);
extern void pmu_set_vrf(kal_bool enable);
extern void pmu_set_vrf_force(kal_bool enable);
extern void pmu_set_vrf_plnmos_dis(kal_bool enable);
extern void pmu_set_icalrf(pmu_icalrf_code code);
#if defined(MT6223PMU)
extern void pmu_set_vrf_cal(kal_uint8 value);
#endif /*MT6223PMU*/
#if defined(MT6238PMU)
extern void pmu_vrf_on_enable(kal_bool enable);
#endif /*MT6238PMU*/
extern void pmu_set_tpsel(kal_uint8 value);
extern void pmu_set_vcore_force(kal_bool enable);
#if defined(MT6223PMU)
extern void pmu_set_icalcore(pmu_icalcore_code code);
extern void pmu_set_vcore_sel(kal_uint8 value);
extern void pmu_set_vcore_cal(kal_uint8 value);
extern void pmu_set_vtcxo_pwrsave(kal_bool enable);
extern void pmu_set_vrf_pwrsave(kal_bool enable);
#endif /*MT6223PMU*/
#if defined(MT6238PMU)
extern void pmu_set_adc_in_edge(kal_bool positive);
extern void pmu_set_fast_slow(kal_bool fast);
extern void pmu_set_pwmb_resol(kal_bool four_bits);
extern void pmu_set_acc_out_init(kal_uint8 value);
#endif /*MT6238PMU*/
extern kal_bool pmu_get_vrtc_staus(void);
extern void pmu_set_vrtc_force(kal_bool enable);
extern kal_bool pmu_get_vio_status(void);
#if defined(MT6223PMU)
extern kal_bool pmu_get_vm_status(void);
#endif /*MT6223PMU*/
extern void pmu_set_vio_force(kal_bool enable);
extern void pmu_set_icalio(pmu_icalio_code code);
extern void pmu_set_antiudsh_io_dn(kal_bool enable);
extern void pmu_set_vio_cal(kal_uint8 value);
extern void pmu_set_vm_force(kal_bool enable);
extern void pmu_set_icalm(pmu_icalm_code code);
extern void pmu_set_antiudsh_m_dn(kal_bool enable);
extern void pmu_set_vm_cal(kal_uint8 value);
extern kal_bool pmu_get_vsim_status(void);
extern void pmu_set_vsim_force(kal_bool enable);
extern void pmu_set_icalsim(pmu_icalsim_code code);
extern void pmu_set_antiudsh_sim_dn(kal_bool enable);
extern void pmu_set_vsim_plnmos_dis(kal_bool enable);
extern void pmu_set_vsim_cal(kal_uint8 value);
extern void pmu_set_vrtc_step1_cal(kal_uint8 value);
extern void pmu_set_vrtc_step2_cal(kal_uint8 value);
extern kal_bool pmu_get_vtcxo_status(void);
extern void pmu_set_vtcxo_force(kal_bool enable);
extern void pmu_set_vtcxo(kal_bool enable);
extern void pmu_set_vtcxo_plnmos_dis(kal_bool enable);
extern void pmu_set_vtcxo_cal(kal_uint8 value);
extern kal_bool pmu_get_va_status(void);
extern void pmu_set_va_force(kal_bool enable);
extern void pmu_set_va(kal_bool enable);
extern void pmu_set_va_cal(kal_uint8 value);
extern void pmu_set_vrtc_cal_latch(kal_bool enable);
extern void pmu_set_vibr(kal_bool enable);
extern void pmu_set_kpled(kal_bool enable);
extern void pmu_set_rled(kal_bool enable);
extern void pmu_set_gled(kal_bool enable);
extern void pmu_set_bled(kal_bool enable);
extern void pmu_set_vsim(kal_bool enable);
extern void pmu_set_vsim_sel(pmu_vsim_volt  volt);
extern kal_bool pmu_is_ovp_occurred(void);
extern kal_bool pmu_is_chr_det(void);
extern kal_bool pmu_is_bat_on(void);
extern kal_bool pmu_is_cv_mode(void);
extern void pmu_set_adc_meas_on(kal_bool enable);
extern void pmu_set_chron(kal_bool enable);
extern void pmu_set_chr_cur_offset(pmu_chr_cur_offset offset);
extern void pmu_set_chr_cur_level(pmu_chr_cur_level level);
extern void pmu_set_chron_force(kal_bool enable);
#if defined(MT6223PMU)
extern void pmu_set_chr_thermal_thres(pmu_chr_thermal_thres thres);
extern void pmu_set_chr_ref_volt(pmu_ref_volt_step step);
#endif /*MT6223PMU*/
extern void pmu_set_chr_cv_volt(pmu_vbg_volt volt);
#if defined(MT6238PMU)
extern void pmu_set_cv_rt(kal_uint8 value);
extern void pmu_set_mtv_enable(kal_bool enable);
extern void pmu_set_gpio_drv(pmu_gpio_drv_strength strength);
#endif /*MT6238PMU*/
extern void pmu_set_uv_sel(pmu_uvlo_volt volt);
extern void pmu_set_rbgsel(pmu_rbgsel sel);
extern void pmu_set_ibgsel(pmu_ibgsel sel);
extern void pmu_set_osc(kal_bool enable);
extern void pmu_set_cksel(pmu_cksel sel);
extern void pmu_set_vbssel(pmu_vbssel sel);
#if defined(MT6223PMU)
extern void pmu_reset_drv(kal_bool reset);
#endif /*MT6223PMU*/
#if defined(MT6238PMU)
extern void pmu_set_bias_gen_force(kal_bool enable);
#endif /*MT6238PMU*/
extern void pmu_set_ov_hys_enb(pmu_ov_hys_enb value);
extern void pmu_set_ov_thfreeze(pmu_ov_thfreeze value);
extern kal_bool pmu_is_pwrkey_deb_disable(void);

#if defined(MT6238PMU)
extern void pmu_set_sdm_order(pmu_sdm_order order);
extern void pmu_set_pid_gain_p(pmu_pid_gain_p gain);
extern void pmu_set_pid_gain(pmu_pid_gain gain);
extern void pmu_set_pid_gain_d(pmu_pid_gain_d gain);
extern void pmu_set_duty_init(kal_uint8 value);
extern void pmu_set_vcore_volt(pmu_vcore_volt volt);
extern void pmu_set_sdm_fb_en(kal_bool enable);
extern void pmu_set_vfbadj(kal_uint8 value);
extern void pmu_set_direct_ctrl_en(kal_bool enable);
extern void pmu_set_dcv_ck(pmu_dcv_ck clk);
extern void pmu_set_isel(pmu_isel sel);
extern void pmu_set_adjcksel(kal_uint8 value);
extern void pmu_set_manual_mode(pmu_mode_set mode);
extern void pmu_set_auto_mode_en(kal_bool enable);
extern void pmu_set_mode_cmp(pmu_mode_cmp cmp);
extern void pmu_set_ave_current_mode(pmu_mode_ave_current mode);
extern void pmu_set_dcv_test_en(kal_bool enable);
extern void pmu_set_pfm_max_current(kal_uint8 value);
extern void pmu_set_pfm_resistor(kal_uint8 value);
extern void pmu_set_ndc_offset(pmu_ndc_offset offset);
extern void pmu_set_dcv_trim(kal_uint8 value);
extern void pmu_set_iasel(pmu_iasel volt);
extern void pmu_set_rsel(pmu_rsel sel);
extern kal_bool pmu_get_vusb_status(void);
extern void pmu_set_vusb_en_force(kal_bool enable);
extern void pmu_set_vusb_en(kal_bool enable);
extern void pmu_set_icalusb(pmu_icalusb_code code);
extern void pmu_set_antiudsh_usb_dn(kal_bool enable);
extern void pmu_set_vusb_plnmos_dis(kal_bool enable);
extern void pmu_set_vusb_cal(kal_uint8 value);
extern void pmu_set_vfbadj_slp(kal_uint8 value);
extern kal_bool pmu_get_vsim2_status(void);
extern void pmu_set_vsim2_en_force(kal_bool enable);
extern void pmu_set_icalsim2(pmu_icalsim2_code code);
extern void pmu_set_antiudsh_sim2_dn(kal_bool enable);
extern void pmu_set_vsim2_plnmos_dis(kal_bool enable);
extern void pmu_set_vsim2_cal(kal_uint8 value);
extern void pmu_set_clk_source_sel(pmu_clk_src_sel source);
extern void pmu_set_vtcxo_on_sel(pmu_vtcxo_on_sel sel);
extern void pmu_set_vsim_pwr_saving_en(kal_bool enable);
extern void pmu_set_vsim2_en(kal_bool enable);
extern void pmu_set_vsim2_sel(pmu_vsim_volt volt);
extern kal_bool pmu_get_vmc_status(void);
extern void pmu_set_vmc_en_force(kal_bool enable);
extern void pmu_set_icalmc(pmu_icalmc_code code);
extern void pmu_set_antiudsh_mc_dn(kal_bool enable);
extern void pmu_set_vmc_plnmos_dis(kal_bool enable);
extern void pmu_set_vmc_cal(kal_uint8 value);
extern void pmu_set_vmc_en(kal_bool enable);
extern void pmu_set_vmc_sel(pmu_vmc_volt volt);
extern kal_bool pmu_get_vcamera_status(void);
extern void pmu_set_vcamera_en_force(kal_bool enable);
extern void pmu_set_icalcamera(pmu_icalcamera_code code);
extern void pmu_set_antiudsh_camera_dn(kal_bool enable);
extern void pmu_set_vcamera_plnmos_dis(kal_bool enable);
extern void pmu_set_vcamera_cal(kal_uint8 value);
extern void pmu_set_dcv_slew_ctrl(kal_uint8 value);
extern void pmu_set_vcamera_en(kal_bool enable);
extern void pmu_set_vcamera_sel(pmu_vcamera_volt volt);
extern kal_bool pmu_get_vsw_a_status(void);
extern void pmu_set_vsw_a_en_force(kal_bool enable);
extern void pmu_set_icalsw(pmu_icalsw_code code);
extern void pmu_set_vsw_a_sel(pmu_vsw_a_volt volt);
extern void pmu_set_vsw_a_cal(kal_uint8 value);
extern void pmu_set_icala(pmu_icala_code code);
extern void pmu_set_icaltcxo(pmu_icaltcxo_code code);
extern void pmu_set_vsw_a_en(kal_bool enable);
extern void pmu_set_oc_fold_en(kal_bool enable);
extern void pmu_set_vref_bg(pmu_vref_bg value);
extern void pmu_set_thr_sel(pmu_thr_sel value);
extern void pmu_set_ldo_soft_st_dis(kal_bool disable);
extern void pmu_set_tpsel_led(kal_uint8 value);
extern void pmu_set_isense_out_en(kal_bool enable);
extern void pmu_set_vbat_out_en(kal_bool enable);

#endif /*MT6238PMU*/

#endif  /*_PMU_SW_H*/

