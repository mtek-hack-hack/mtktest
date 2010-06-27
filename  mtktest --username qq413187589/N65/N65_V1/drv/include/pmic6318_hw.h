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

#ifndef _PMIC6318_HW_H
#define _PMIC6318_HW_H

#define PMIC_MAX_REG                 16
#define PMIC_SHIFT_BITS              12 
/*PMIC register index*/
#define PMIC_CHARGER_STAT            0x0000
#define PMIC_CHARGER_SPEAKER_CTRL    0x1000
#define PMIC_LDO_STAT                0x2000  
#define PMIC_RLED_DRIVER             0x3000     
#define PMIC_GLED_DRIVER             0x4000 
#define PMIC_BLED_DRIVER             0x5000
#define PMIC_KPLED_DRIVER            0x6000
#define PMIC_BLLED_DRIVER            0x7000 
#define PMIC_MISC                    0x8000 
#define PMIC_DIM_CLOCK               0x9000
#define PMIC_CHARGER_CTRL2           0xa000
#define PMIC_BANDGAP_SETTING         0xb000
#define PMIC_CHARGE_PUMP             0xe000
#define PMIC_EXTRAS                  0xf000


/*charger status*/
#define OV_MASK         0x80
#define CHRDET_MASK     0x40
#define BAT_ON_MASK     0x20
#define AC_DET_MASK     0x10
#define USB_DET_MASK    0x8
#define CH_COMPL_MASK   0x4
#define CHR_STAT_MASK   0x3
#define CV_STATUS_MASK  0x2
#define CHR_STATUS_MASK 0x1


/*charger control*/
#define CHR_ON            0x80  
#define CHR_PAUSE         0x0
#define SPK_GAIN_SHIFT    4
#define SPK_GAIN_MASK     0x70
#define USB_PWR_ON        0x8
#define AC_CURRENT_MASK   0x6
#define AC_CURRENT_SHIFT  0x1
#define USB_CURRENT_MASK  0x1
#define CHR_CURRENT_MASK  0x7
#define CHARGE_PUMP_MASK  0xf8

/*LDO status*/
#define LDO_VD_MASK       0x80
#define LDO_VA_MASK       0x40  
#define LDO_VM_MASK       0x20
#define LDO_VRTC_MASK     0x10
#define LDO_VTCXO_MASK    0x8
#define LDO_VSIM_MASK     0x4

/*R/G/B/KP/BL LED driver*/
#define LED_ON            0x80
#define DIM_ON            0x1
#define LED_PWMD_MASK     0x1f
#define BL_DIV_BYPASS     0x20

/*Misccellaneous*/
#define CHR_PUMP_ON       0x80 
#define VASW_ON           0x40
#define VD_0_9V           0x20
#define VASEL_VTCXO       0x10
#define VMC_ON            0x8
#define VMC_SEL_MASK      0x8
#define VSIM_SEL_3        0x4
#define VSIM_SEL_1_8      0x0
#define SPEAKER_ON        0x2
#define VIBRATOR_ON       0x1
/*DIM CLK*/
#define DIM_CLK_MASK      0xf
/*Charger control register2*/
#define CHOSFT_MASK       0x7 
/*Extras*/
#define VBHSEL_DIV2       0x10

/*max speker gain*/
#define MAX_SPK_GAIN      21
#endif  

