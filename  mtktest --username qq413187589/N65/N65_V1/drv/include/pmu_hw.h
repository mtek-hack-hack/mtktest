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
 *    pmu_hw.h
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

#ifndef _PMU_HW_H
#define _PMU_HW_H

/*PMIC register index*/
#if defined(MT6223PMU) || defined(MT6238PMU)
#define PMIC_CON0                    (MIXED_base+0x0800)
#define PMIC_CON1                    (MIXED_base+0x0804)
#define PMIC_CON2                    (MIXED_base+0x0808)
#define PMIC_CON3                    (MIXED_base+0x080C)
#define PMIC_CON4                    (MIXED_base+0x0810)
#define PMIC_CON5                    (MIXED_base+0x0814)
#define PMIC_CON6                    (MIXED_base+0x0818)
#define PMIC_CON7                    (MIXED_base+0x081C)
#if defined(MT6238PMU)
#define PMIC_CON8                    (MIXED_base+0x0820)
#define PMIC_CON9                    (MIXED_base+0x0824)
#define PMIC_CONA                    (MIXED_base+0x0828)
#define PMIC_CONB                    (MIXED_base+0x082C)
#define PMIC_CONC                    (MIXED_base+0x0830)
#define PMIC_COND                    (MIXED_base+0x0834)
#define PMIC_CONE                    (MIXED_base+0x0838)
#define PMIC_CONF                    (MIXED_base+0x083C)
#define PMIC_CONG                    (MIXED_base+0x0840)
#endif

/* PMIC_CON0: Control LDC of Vrf and test setting */
#define VRF_STATUS         0x0001
   #define VRF_STATUS_SHIFT      0
#define VRF_EN             0x0002
   #define VRF_EN_SHIFT          1
#define VRF_EN_FORCE       0x0004
   #define VRF_EN_FORCE_SHIFT    2
#define VRF_PLNMOS_DIS     0x0008
   #define VRF_PLNMOS_DIS_SHIFT  3     
#define ICALRF_EN          0x0030
   #define ICALRF_EN_SHIFT       4
#define VRF_CAL            0x03C0
   #define VRF_CAL_SHIFT         6
#if defined(MT6238PMU)
   #define VRF_ON_SEL      0x0400
      #define VRF_ON_SEL_SHIFT   10
#endif
#define TPSEL              0xF000
   #define TPSEL_SHIFT           12

/* PMIC_CON1: Control LDO of Vcore, Vrtc, and status of Vio and Vm */
#define VCORE_EN_FORCE     0x0001
   #define VCORE_EN_FORCE_SHIFT  0

#if defined(MT6223PMU)
#define ICALCORE_EN        0x0006
   #define ICALCORE_EN_SHIFT     1
#define VCORE_SEL          0x0018
   #define VCORE_SEL_SHIFT       3
#define VCORE_CAL          0x01E0
   #define VCORE_CAL_SHIFT       5
#define VCTXO_PWRSAVE_EN   0x0200
   #define VCTXO_PWRSAVE_EN_SHIFT 9
#define VRF_PWRSAVE_EN     0x0400
   #define VRF_PWRSAVE_EN_SHIFT  10

#elif defined(MT6238PMU)
#define ADC_IN_EDGE        0x0002
   #define ADC_IN_EDGE_SHIFT     1
#define FAST_SLOW          0x0004
   #define FAST_SLOW_SHIFT       2
#define PWMB               0x0008
   #define PWMB_SHIFT            3
#define ACC_OUT_INIT       0x00F0
   #define ACC_OUT_INIT_SHIFT    4

#endif /*MT6223PMU*/

#define VRTC_STATUS        0x1000
   #define VRTC_STATUS_SHIFT     12
#define VRTC_EN_FORE       0x2000
   #define VRTC_EN_FORE_SHIFT    13
#define VIO_STATUS         0x4000
   #define VIO_STATUS_SHIFT      14

#if defined(MT6223PMU)
#define VM_STATUS          0x8000
   #define VM_STATUS_SHIFT       15
#endif /* MT6223PMU*/

/* PMIC_CON2: Control LDO of Vio and Vm */
#define VIO_EN_FORCE       0x0001
   #define VIO_EN_FORCE_SHIFT    0
#define VCALIO_EN          0x0006
   #define VCALIO_EN_SHIFT       1
#define ANTIUDSH_IO_DN     0x0008
   #define ANTIUDSH_IO_DN_SHIFT  3
#define VIO_CAL            0x00F0
   #define VIO_CAL_SHIFT         4
#define VM_EN_FORCE        0x0100
   #define VM_EN_FORCE_SHIFT     8
#define ICALM_EN           0x0600
   #define ICALM_EN_SHIFT        9
#define ANTIUDSH_M_DN      0x0800
   #define ANTIUDSH_M_DN_SHIFT   11
#define VM_CAL             0xF000
   #define VM_CAL_SHIFT          12

/* PMIC_CON3: Control and Status of LDO of Vsim, Calibration of Vrtc */
#define VSIM_STATUS        0x0001
   #define VSIM_STATUS_SHIFT     0
#define VSIM_EN_FORCE      0x0002
   #define VSIM_EN_FORCE_SHIFT   1
#define ICALSIM_EN         0x000C
   #define ICALSIM_EN_SHIFT      2
#define ANTIUDSH_SIM_DN    0x0010
   #define ANTIUDSH_SIM_DN_SHIFT 4
#define VSIM_PLNMOS_DIS    0x0020
   #define VSIM_PLNMOS_DIS_SHIFT 5
#define VSIM_CAL           0x03C0
   #define VSIM_CAL_SHIFT        6
#define VRTC_STEP1_CAL     0x1C00
   #define VRTC_STEP1_CAL_SHIFT  10
#define VRTC_STEP2_CAL     0xE000
   #define VRTC_STEP2_CAL_SHIFT  13

/* PMIC_CON4: Control and Status of LDC of Vctxo and Va*/
#define VCTXO_STATUS       0x0001
   #define VCTXO_STATUS_SHIFT    0
#define VCTXO_EN_FORCE     0x0002
   #define VCTXO_EN_FORCE_SHIFT  1
#define VCTXO_EN           0x0004
   #define VCTXO_EN_SHIFT        2
#define VCTXO_PLNMOS_DIS   0x0008
   #define VCTXO_PLNMOS_DIS_SHIFT   3
#define VCTXO_CAL          0x00F0
   #define VCTXO_CAL_SHIFT       4
#define VA_STATUS          0x0100
   #define VA_STATUS_SHIFT       8
#define VA_EN_FORCE        0x0200
   #define VA_EN_FORCE_SHIFT     9
#define VA_EN_SEL          0x0400
   #define VA_EN_SEL_SHIFT       10
#define VA_CAL             0x7800
   #define VA_CAL_SHIFT          11
#define VRTC_CAL_LATCH_EN  0x8000
   #define VRTC_CAL_LATCH_EN_SHIFT  15

/* PMIC_CON5: Driver Control and Charger Staus */
#define VIBR_EN            0x0001
   #define VIBR_EN_SHIFT         0
#define KPLEN_EN           0x0002
   #define KPLEN_EN_SHIFT        1
#define RLED_EN            0x0004
   #define RLED_EN_SHIFT         2
#define GLEN_EN            0x0008
   #define GLEN_EN_SHIFT         3
#define BLEN_EN            0x0010
   #define BLEN_EN_SHIFT         4
#define INT_NODE_MUX       0x00E0
#define INT_NODE_MUX_MSB   0x0080
   #define INT_NODE_MUX_SHIFT    5
#define VSIM_EN            0x0100
   #define VSIM_EN_SHIFT         8
#define VSIM_SEL           0x0200
   #define VSIM_SEL_SHIFT        9
#define OVP                0x0400
   #define OVP_SHIFT             10
#define CHR_DET            0x0800
   #define CHR_DET_SHIFT         11
#define BAT_ON             0x1000
   #define BAT_ON_SHIFT          12
#define AC_DET             0x2000
   #define AC_DET_SHIFT          13
#define CV                 0x4000
   #define CV_SHIFT              14
#define CHRG_DIS           0x8000
   #define CHRG_DIS_SHIFT        15

/* PMIC_CON6: Charger Control */
#define CHR_EN             0x0001
   #define CHR_EN_SHIFT          0
#define CHOFST             0x000E
   #define CHOFST_SHIFT          1
#define CLASS_D            0x0070
   #define CLASS_D_SHIFT         4
#define CHRON_FORCE        0x0080
   #define CHRON_FORCE_SHIFT     7

#if defined(MT6223PMU)
#define CHR_AUX            0xFF00
   #define CHR_AUX_SHIFT         8
   #define CHR_AUX_THERMAL       0x8800
      #define CHR_AUX_THERMAL_SHIFT    11
   #define CHR_AUX_REF_VOLT      0x7000
      #define CHR_AUX_REF_VOLT_SHIFT   12
   #define CHR_AUX_CV_VOLT       0x0700
      #define CHR_AUX_CV_VOLT_SHIFT    8

#elif defined(MT6238PMU)
#define CV_RT              0x0300
   #define CV_RT_SHIFT              8
#define CV_TUNE            0x1C00
   #define CV_TUNE_SHIFT            10
#define MTV_EN             0x4000
   #define MTV_EN_SHIFT             14
#define GPIO_DRV           0x8000
   #define GPIO_DRV_SHIFT           15

#endif

/* PMIC_CON7: Start Up*/
#define UV_SEL             0x0003
   #define UV_SEL_SHIFT          0
#define RBGSEL               0x001C
   #define RBGSEL_SHIFT            2
#define IBGSEL               0x0060
   #define IBGSEL_SHIFT            5
#define OSCDIS              0x0080
   #define OSCDIS_SHIFT          7
#define CKSEL              0x0100
   #define CKSEL_SHIFT           8
#define VBSSEL             0x0600
   #define VBSSEL_SHIFT          9

#if defined(MT6223PMU)
#define RESET_DRV          0x0800
   #define RESET_DRV_SHIFT       11

#elif defined(MT6238PMU)
#define BIAS_GEN_FORCE      0x0800
   #define BIAS_GEN_FORCE_SHIFT  11

#endif

#define OV_HYS_ENB         0x1000
   #define OV_HYS_ENB_SHIFT      12
#define OV_THFREEZE        0x2000
   #define OV_THFREEZE_SHIFT     13
#define PWRKEY_DEB         0x8000
   #define PWRKEY_DEB_SHIFT      15


#if defined(MT6238PMU)

/* PMIC_CON8: DC-DC controller VCORE */
#define SDM_ORDER             0x0001
   #define SDM_ORDER_SHIFT          0
#define GAIN_P                0x000E
   #define GAIN_P_SHIFT             1
#define GAIN                  0x0007
   #define GAIN_SHIFT               4
#define GAIN_D                0x0380
   #define GAIN_D_SHIFT             7
#define DUTY_INIT             0x3C00
   #define DUTY_INIT_SHIFT          10
#define VOSEL                 0x4000
   #define VOSEL_SHIFT              14
#define SDM_FB_EN             0x8000
   #define SDM_FB_EN_SHIFT          15

/* PMIC_CON9: DC-DC controller VCORE */
#define VFBADJ                0x000F
   #define VFBADJ_SHIFT             0
#define DIRECT_CTRL_EN        0x0010
   #define DIRECT_CTRL_EN_SHIFT     4
#define DCV_CK_SEL            0x0020
   #define DCV_CK_SEL_SHIFT         5
#define ISEL                  0x00C0
   #define ISEL_SHIFT               6
#define ADJCKSEL              0x0700
   #define ADJCKSEL_SHIFT           8
#define MODESET               0x0800
   #define MODESET_SHIFT            11
#define MODEEN0               0x1000
   #define MODEEN0_SHIFT            12
#define MODECMP               0x2000
   #define MODECMP_SHIFT            13
#define MODESEL1A             0x4000
   #define MODESEL1A_SHIFT          14
#define DCV_TEST_EN           0x8000
   #define DCV_TEST_EN_SHIFT        15

/* PMIC_CONA: DC-DC controller VCORE */
#define PFMSEL_CURRENT        0x000F
   #define PFMSEL_CURRENT_SHIFT     0
#define PFMSEL_RESISTOR       0x0070
   #define PFMSEL_RESISTOR_SHIFT    4
#define NCDOF                 0x0180
   #define NCDOF_SHIFT              7
#define DCVTRIM               0x0E00
   #define DCVTRIM_SHIFT            9
#define IASEL                 0x3000
   #define IASEL_SHIFT              12
#define RSEL                  0xC000
   #define RSEL_SHIFT               14

/* PMIC_CONB: Control and Status of LDO of Vusb */
#define VUSB_STAUS            0x0001
   #define VUSB_STAUS_SHIFT         0
#define VUSB_EN_FORCE         0x0002
   #define VUSB_EN_FORCE_SHIFT      1
#define VUSB_EN               0x0004
   #define VUSB_EN_SHIFT            2
#define ICALUSB_EN            0x0018
   #define ICALUSB_EN_SHIFT         3
#define ANTIUDSH_USB_DN       0x0020
   #define ANTIUDSH_USB_DN_SHIFT    5
#define VUSB_PLNMOS_DIS       0x0040
   #define VUSB_PLNMOS_DIS_SHIFT    6
#define VUSB_CAL              0x0780
   #define VUSB_CAL_SHIFT           7
#define MODEEN1               0x0800
   #define MODEEN1_SHIFT            11
#define VFBADJ_SLP            0xF000
   #define VFBADJ_SLP_SHIFT         12

/* PMIC_CONC: Control and Status of LDO of Vsim2 */
#define VSIM2_STAUS            0x0001
   #define VSIM2_STAUS_SHIFT         0
#define VSIM2_EN_FORCE         0x0002
   #define VSIM2_EN_FORCE_SHIFT      1
#define ICALSIM2_EN            0x000C
   #define ICALSIM2_EN_SHIFT         2
#define ANTIUDSH_SIM2_DN       0x0010
   #define ANTIUDSH_SIM2_DN_SHIFT    4
#define VSIM2_PLNMOS_DIS       0x0020
   #define VSIM2_PLNMOS_DIS_SHIFT    5
#define VSIM2_CAL              0x03C0
   #define VSIM2_CAL_SHIFT           6
#define CLK_SOURCE_SEL         0x0400
   #define CLK_SOURCE_SEL_SHIFT      10
#define VTCXO_ON_SEL           0x0800
   #define VTCXO_ON_SEL_SHIFT        11
#define VSIM_PWR_SAVING        0x1000
   #define VSIM_PWR_SAVING_SHIFT     12
#define VSIM2_EN               0x4000
   #define VSIM2_EN_SHIFT            14
#define VSIM2_SEL              0x8000
   #define VSIM2_SEL_SHIFT           15

/* PMIC_COND: Control and Status of LDO of Vmc */
#define VMC_STAUS            0x0001
   #define VMC_STAUS_SHIFT         0
#define VMC_EN_FORCE         0x0002
   #define VMC_EN_FORCE_SHIFT      1
#define ICALMC_EN            0x000C
   #define ICALMC_EN_SHIFT         2
#define ANTIUDSH_MC_DN       0x0010
   #define ANTIUDSH_MC_DN_SHIFT    4
#define VMC_PLNMOS_DIS       0x0020
   #define VMC_PLNMOS_DIS_SHIFT    5
#define VMC_CAL              0x03C0
   #define VMC_CAL_SHIFT           6
#define VMC_EN               0x4000
   #define VMC_EN_SHIFT            14
#define VMC_SEL              0x8000
   #define VMC_SEL_SHIFT           15

/* PMIC_CONE: Control and Status of LDO of Vcamera */
#define VCAMERA_STAUS            0x0001
   #define VCAMERA_STAUS_SHIFT         0
#define VCAMERA_EN_FORCE         0x0002
   #define VCAMERA_EN_FORCE_SHIFT      1
#define ICALCAMERA_EN            0x000C
   #define ICALCAMERA_EN_SHIFT         2
#define ANTIUDSH_CAMERA_DN       0x0010
   #define ANTIUDSH_CAMERA_DN_SHIFT    4
#define VCAMERA_PLNMOS_DIS       0x0020
   #define VCAMERA_PLNMOS_DIS_SHIFT    5
#define VCAMERA_CAL              0x03C0
   #define VCAMERA_CAL_SHIFT           6
#define DCV_SLEW_CTRL            0x1C00
   #define DCV_SLEW_CTRL_SHIFT         10
#define VCAMERA_EN               0x2000
   #define VCAMERA_EN_SHIFT            13
#define VCAMERA_SEL              0xC000
   #define VCAMERA_SEL_SHIFT           14

/* PMIC_CONF: Control and Status of LDO of Vswa, Vtcxo, Va */
#define VSW_A_STAUS            0x0001
   #define VSW_A_STAUS_SHIFT         0
#define VSW_A_EN_FORCE         0x0002
   #define VSW_A_EN_FORCE_SHIFT      1
#define ICALSW_EN            0x000C
   #define ICALSW_EN_SHIFT         2
#define VSW_A_SEL            0x0030
   #define VSW_A_SEL_SHIFT         4
#define VSW_A_CAL            0x03C0
   #define VSW_A_CAL_SHIFT         6
#define ICALA_EN             0x0C00
   #define ICALA_EN_SHIFT          10
#define ICALTCXO_EN           0x3000
   #define ICALTCXO_EN_SHIFT        12
#define VSW_A_EN             0x4000
   #define VSW_A_EN_SHIFT          14
#define OC_FOLD_EN           0x8000
   #define OC_FOLD_EN_SHIFT        15

/* PMIC_CONG: Start Up & AUXADC Related Control Register 2 */
#define VREF_BG              0x0007
   #define VREF_BG_SHIFT           0
#define THR_SEL              0x0018
   #define THR_SEL_SHIFT           3
#define LDO_SOFT_ST          0x0020
   #define LDO_SOFT_ST_SHIFT       5
#define TPSEL_LED            0x0F00
   #define TPSEL_LED_SHIFT         8
#define ISENSE_OUT_EN        0x1000
   #define ISENSE_OUT_EN_SHIFT     12
#define VBAT_OUT_EN          0x2000
   #define VBAT_OUT_EN_SHIFT       13

#endif /*MT6238PMU*/

#endif /* defined(MT6223PMU) || defined(MT6238PMU) */

#endif  

