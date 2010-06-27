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
 *    pmu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines functions that Power Management Unit can support
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
#include 	"kal_release.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"drv_comm.h"
#include    "drvsignals.h"
#include 	"reg_base.h"
#include 	"pmu_hw.h"
#include 	"pmu_sw.h"
#include 	"intrCtrl.h"
#include	   "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include	   "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "eint.h"
#include    "drvsignals.h"
#include    "custom_hw_default.h"

#if defined(MT6223PMU) || defined(MT6238PMU)
  
/*
* FUNCTION                                                            
*	pmu_init
*
* DESCRIPTION                                                           
*   MT6223 Power Management Uint(PMU) driver initial function
*
* CALLS  
*	
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmu_init(void)
{  
   extern void pmu_customization_init(void);
   pmu_set_vrf_plnmos_dis(KAL_TRUE);
   pmu_set_cksel(CK_SEL_10KHZ);
#if defined(MT6223PMU)
   pmu_reset_drv(KAL_FALSE);
#endif
   pmu_customization_init();  
}   

pmu_chr_cur_level pmu_ret_chr_current(void)
{
   /* This value should be customized. */
   return CHR_CUR_650;
}

#if defined(MT6238PMU)
pmu_chr_cur_level pmu_ret_usb_current(void)
{
   /* This value should be customized. */
   return CHR_CUR_450;
}
#endif


/******************************************************************
         PMIC_CON0 API 
******************************************************************/
/*
* FUNCTION                                                            
*	pmu_get_vrf_status
*
* DESCRIPTION                                                           
*  To get RF LDO status
*
* CALLS  
*	
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: RF LDO is enable. KAL_FALSE: RF LDO is disable
*
* GLOBALS AFFECTED
*   external_global
*/     
kal_bool pmu_get_vrf_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON0);
   if (reg_val16 & VRF_STATUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vrf(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON0);
   if (enable == KAL_TRUE)
      reg_val16 |= VRF_EN;
   else
      reg_val16 &= (~VRF_EN);
   DRV_WriteReg(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vrf_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON0);
   if (enable == KAL_TRUE)
      reg_val16 |= VRF_EN_FORCE;
   else
      reg_val16 &= (~VRF_EN_FORCE);
   DRV_WriteReg(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vrf_plnmos_dis(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON0);
   if (enable == KAL_TRUE)
      reg_val16 |= VRF_PLNMOS_DIS;
   else
      reg_val16 &= (~VRF_PLNMOS_DIS);
   DRV_WriteReg(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalrf(pmu_icalrf_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON0);
   reg_val16 &= (~ICALRF_EN);
   reg_val16 |= ((code<<ICALRF_EN_SHIFT) & ICALRF_EN);
   DRV_WriteReg(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);      
}

#if defined(MT6223PMU)
void pmu_set_vrf_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON0);
   reg_val16 &= (~VRF_CAL);
   reg_val16 |= ((value<<VRF_CAL_SHIFT) & VRF_CAL);
   DRV_WriteReg(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);      
}
#endif /* MT6223PMU */

#if defined(MT6238PMU)
void pmu_vrf_on_enable(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON0);
   if (enable == KAL_TRUE)
      reg_val16 |= VRF_ON_SEL;
   else
      reg_val16 &= (~VRF_ON_SEL);
   DRV_WriteReg(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);      
}
#endif /* MT6238PMU */

void pmu_set_tpsel(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON0);
   reg_val16 &= (~TPSEL);
   reg_val16 |= ((value<<TPSEL_SHIFT) & TPSEL);
   DRV_WriteReg(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CON1 API 
******************************************************************/
void pmu_set_vcore_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   if (enable == KAL_TRUE)
      reg_val16 |= VCORE_EN_FORCE;
   else
      reg_val16 &= (~VCORE_EN_FORCE);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

#if defined(MT6223PMU)
void pmu_set_icalcore(pmu_icalcore_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   reg_val16 &= (~ICALCORE_EN);
   reg_val16 |= ((code<<ICALCORE_EN_SHIFT) & ICALCORE_EN);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vcore_sel(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   reg_val16 &= (~VCORE_SEL);
   reg_val16 |= ((value<<VCORE_SEL_SHIFT) & VCORE_SEL);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vcore_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   reg_val16 &= (~VCORE_CAL);
   reg_val16 |= ((value<<VCORE_CAL_SHIFT) & VCORE_CAL);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vtcxo_pwrsave(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   if (enable == KAL_TRUE)
      reg_val16 |= VCTXO_PWRSAVE_EN;
   else
      reg_val16 &= (~VCTXO_PWRSAVE_EN);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vrf_pwrsave(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   if (enable == KAL_TRUE)
      reg_val16 |= VRF_PWRSAVE_EN;
   else
      reg_val16 &= (~VRF_PWRSAVE_EN);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}
#endif /*MT6223PMU*/

#if defined(MT6238PMU)
void pmu_set_adc_in_edge(kal_bool positive)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   if (positive == KAL_TRUE)
      reg_val16 |= ADC_IN_EDGE;
   else
      reg_val16 &= (~ADC_IN_EDGE);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_fast_slow(kal_bool fast)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   if (fast == KAL_TRUE)
      reg_val16 |= FAST_SLOW;
   else
      reg_val16 &= (~FAST_SLOW);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_pwmb_resol(kal_bool four_bits)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   if (four_bits == KAL_TRUE)
      reg_val16 |= PWMB_SHIFT;
   else
      reg_val16 &= (~PWMB_SHIFT);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_acc_out_init(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   reg_val16 &= (~ACC_OUT_INIT);
   reg_val16 |= ((value<<ACC_OUT_INIT_SHIFT) & ACC_OUT_INIT);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

#endif /*MT6238PMU*/

kal_bool pmu_get_vrtc_staus(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON1);
   if (reg_val16 & VRTC_STATUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vrtc_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON1);
   if (enable == KAL_TRUE)
      reg_val16 |= VRTC_EN_FORE;
   else
      reg_val16 &= (~VRTC_EN_FORE);
   DRV_WriteReg(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);      
}

kal_bool pmu_get_vio_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON1);
   if (reg_val16 & VIO_STATUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

#if defined(MT6223PMU)
kal_bool pmu_get_vm_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON1);
   if (reg_val16 & VM_STATUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}
#endif /*MT6223PMU*/

/******************************************************************
         PMIC_CON2 API 
******************************************************************/
void pmu_set_vio_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON2);
   if (enable == KAL_TRUE)
      reg_val16 |= VIO_EN_FORCE;
   else
      reg_val16 &= (~VIO_EN_FORCE);
   DRV_WriteReg(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalio(pmu_icalio_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON2);
   reg_val16 &= (~VCALIO_EN);
   reg_val16 |= ((code<<VCALIO_EN_SHIFT) & VCALIO_EN);
   DRV_WriteReg(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_antiudsh_io_dn(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON2);
   if (enable == KAL_TRUE)
      reg_val16 |= ANTIUDSH_IO_DN;
   else
      reg_val16 &= (~ANTIUDSH_IO_DN);
   DRV_WriteReg(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vio_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON2);
   reg_val16 &= (~VIO_CAL);
   reg_val16 |= ((value<<VIO_CAL_SHIFT) & VIO_CAL);
   DRV_WriteReg(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vm_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON2);
   if (enable == KAL_TRUE)
      reg_val16 |= VM_EN_FORCE;
   else
      reg_val16 &= (~VM_EN_FORCE);
   DRV_WriteReg(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalm(pmu_icalm_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON2);
   reg_val16 &= (~ICALM_EN);
   reg_val16 |= ((code<<ICALM_EN_SHIFT) & ICALM_EN);
   DRV_WriteReg(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_antiudsh_m_dn(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON2);
   if (enable == KAL_TRUE)
      reg_val16 |= ANTIUDSH_M_DN;
   else
      reg_val16 &= (~ANTIUDSH_M_DN);
   DRV_WriteReg(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vm_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON2);
   reg_val16 &= (~VM_CAL);
   reg_val16 |= ((value<<VM_CAL_SHIFT) & VM_CAL);
   DRV_WriteReg(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CON3 API 
******************************************************************/
kal_bool pmu_get_vsim_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON3);
   if (reg_val16 & VSIM_STATUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vsim_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON3);
   if (enable == KAL_TRUE)
      reg_val16 |= VSIM_EN_FORCE;
   else
      reg_val16 &= (~VSIM_EN_FORCE);
   DRV_WriteReg(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalsim(pmu_icalsim_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON3);
   reg_val16 &= (~ICALSIM_EN);
   reg_val16 |= ((code<<ICALSIM_EN_SHIFT) & ICALSIM_EN);
   DRV_WriteReg(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_antiudsh_sim_dn(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON3);
   if (enable == KAL_TRUE)
      reg_val16 |= ANTIUDSH_SIM_DN;
   else
      reg_val16 &= (~ANTIUDSH_SIM_DN);
   DRV_WriteReg(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim_plnmos_dis(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON3);
   if (enable == KAL_TRUE)
      reg_val16 |= VSIM_PLNMOS_DIS;
   else
      reg_val16 &= (~VSIM_PLNMOS_DIS);
   DRV_WriteReg(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON3);
   reg_val16 &= (~VSIM_CAL);
   reg_val16 |= ((value<<VSIM_CAL_SHIFT) & VSIM_CAL);
   DRV_WriteReg(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vrtc_step1_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON3);
   reg_val16 &= (~VRTC_STEP1_CAL);
   reg_val16 |= ((value<<VRTC_STEP1_CAL_SHIFT) & VRTC_STEP1_CAL);
   DRV_WriteReg(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vrtc_step2_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON3);
   reg_val16 &= (~VRTC_STEP2_CAL);
   reg_val16 |= ((value<<VRTC_STEP2_CAL_SHIFT) & VRTC_STEP2_CAL);
   DRV_WriteReg(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CON4 API 
******************************************************************/
kal_bool pmu_get_vtcxo_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON4);
   if (reg_val16 & VCTXO_STATUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vtcxo_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON4);
   if (enable == KAL_TRUE)
      reg_val16 |= VCTXO_EN_FORCE;
   else
      reg_val16 &= (~VCTXO_EN_FORCE);
   DRV_WriteReg(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vtcxo(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON4);
   if (enable == KAL_TRUE)
      reg_val16 |= VCTXO_EN;
   else
      reg_val16 &= (~VCTXO_EN);
   DRV_WriteReg(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vtcxo_plnmos_dis(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON4);
   if (enable == KAL_TRUE)
      reg_val16 |= VCTXO_PLNMOS_DIS;
   else
      reg_val16 &= (~VCTXO_PLNMOS_DIS);
   DRV_WriteReg(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vtcxo_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON4);
   reg_val16 &= (~VCTXO_CAL);
   reg_val16 |= ((value<<VCTXO_CAL_SHIFT) & VCTXO_CAL);
   DRV_WriteReg(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);      
}

kal_bool pmu_get_va_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON4);
   if (reg_val16 & VA_STATUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_va_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON4);
   if (enable == KAL_TRUE)
      reg_val16 |= VA_EN_FORCE;
   else
      reg_val16 &= (~VA_EN_FORCE);
   DRV_WriteReg(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_va(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON4);
   if (enable == KAL_TRUE)
      reg_val16 |= VA_EN_SEL;
   else
      reg_val16 &= (~VA_EN_SEL);
   DRV_WriteReg(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_va_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON4);
   reg_val16 &= (~VA_CAL);
   reg_val16 |= ((value<<VA_CAL_SHIFT) & VA_CAL);
   DRV_WriteReg(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vrtc_cal_latch(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON4);
   if (enable == KAL_TRUE)
      reg_val16 |= VRTC_CAL_LATCH_EN;
   else
      reg_val16 &= (~VRTC_CAL_LATCH_EN);
   DRV_WriteReg(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CON5 API 
******************************************************************/
void pmu_set_vibr(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON5);
   if (enable == KAL_TRUE)
      reg_val16 |= VIBR_EN;
   else
      reg_val16 &= (~VIBR_EN);
   DRV_WriteReg(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_kpled(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON5);
   if (enable == KAL_TRUE)
      reg_val16 |= KPLEN_EN;
   else
      reg_val16 &= (~KPLEN_EN);
   DRV_WriteReg(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_rled(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON5);
   if (enable == KAL_TRUE)
      reg_val16 |= RLED_EN;
   else
      reg_val16 &= (~RLED_EN);
   DRV_WriteReg(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_gled(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON5);
   if (enable == KAL_TRUE)
      reg_val16 |= GLEN_EN;
   else
      reg_val16 &= (~GLEN_EN);
   DRV_WriteReg(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_bled(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON5);
   if (enable == KAL_TRUE)
      reg_val16 |= BLEN_EN;
   else
      reg_val16 &= (~BLEN_EN);
   DRV_WriteReg(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON5);
   if (enable == KAL_TRUE)
      reg_val16 |= VSIM_EN;
   else
      reg_val16 &= (~VSIM_EN);
   DRV_WriteReg(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim_sel(pmu_vsim_volt volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON5);
   reg_val16 &= (~VSIM_SEL);
   reg_val16 |= ((volt<<VSIM_SEL_SHIFT) & VSIM_SEL);
   DRV_WriteReg(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);      
}

kal_bool pmu_is_ovp_occurred(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON5);
   if (reg_val16 & OVP)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

kal_bool pmu_is_chr_det(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON5);
   if (reg_val16 & CHR_DET)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

kal_bool pmu_is_bat_on(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON5);
   if (reg_val16 & BAT_ON)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

kal_bool pmu_is_cv_mode(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON5);
   if (reg_val16 & CV)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}


void pmu_set_adc_meas_on(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
#if defined(MT6238PMU)
   reg_val16 = DRV_Reg(PMIC_CONG);
   if (enable == KAL_TRUE)
      reg_val16 |= (ISENSE_OUT_EN|VBAT_OUT_EN);
   else
      reg_val16 &= (~(ISENSE_OUT_EN|VBAT_OUT_EN));
   DRV_WriteReg(PMIC_CONG, reg_val16);
#elif defined(MT6223PMU)
   reg_val16 = DRV_Reg(PMIC_CON5);
   if (enable == KAL_TRUE)
      reg_val16 |= INT_NODE_MUX_MSB;
   else
      reg_val16 &= (~INT_NODE_MUX_MSB);
   DRV_WriteReg(PMIC_CON5, reg_val16);
#endif
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CON6 API 
******************************************************************/
void pmu_set_chron(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   if (enable == KAL_TRUE)
      reg_val16 |= CHR_EN;
   else
      reg_val16 &= (~CHR_EN);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_chr_cur_offset(pmu_chr_cur_offset offset)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   reg_val16 &= (~CHOFST);
   reg_val16 |= ((offset<<CHOFST_SHIFT) & CHOFST);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_chr_cur_level(pmu_chr_cur_level level)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   reg_val16 &= (~CLASS_D);
   reg_val16 |= ((level<<CLASS_D_SHIFT) & CLASS_D);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_chron_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   if (enable == KAL_TRUE)
      reg_val16 |= CHRON_FORCE;
   else
      reg_val16 &= (~CHRON_FORCE);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

#if defined(MT6223PMU)
void pmu_set_chr_thermal_thres(pmu_chr_thermal_thres thres)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   reg_val16 &= (~CHR_AUX_THERMAL);
   reg_val16 |= ((thres<<CHR_AUX_THERMAL_SHIFT) & CHR_AUX_THERMAL);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_chr_ref_volt(pmu_ref_volt_step step)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   reg_val16 &= (~CHR_AUX_REF_VOLT);
   reg_val16 |= ((step<<CHR_AUX_REF_VOLT_SHIFT) & CHR_AUX_REF_VOLT);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}
#endif /*MT6223PMU*/

void pmu_set_chr_cv_volt(pmu_vbg_volt volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
#if defined(MT6223PMU)
   reg_val16 &= (~CHR_AUX_CV_VOLT);
   reg_val16 |= ((volt<<CHR_AUX_CV_VOLT_SHIFT) & CHR_AUX_CV_VOLT);
#elif defined(MT6238PMU)
   reg_val16 &= (~CV_TUNE);
   reg_val16 |= ((volt<<CV_TUNE_SHIFT) & CV_TUNE);
#endif
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

#if defined(MT6238PMU)
void pmu_set_cv_rt(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   reg_val16 &= (~CV_RT);
   reg_val16 |= ((value<<CV_RT_SHIFT) & CV_RT);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_mtv_enable(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   if (enable == KAL_TRUE)
      reg_val16 |= MTV_EN;
   else
      reg_val16 &= (~MTV_EN);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_gpio_drv(pmu_gpio_drv_strength strength)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON6);
   reg_val16 &= (~GPIO_DRV);
   reg_val16 |= ((strength<<GPIO_DRV_SHIFT) & GPIO_DRV);
   DRV_WriteReg(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);      
}

#endif /*MT6238PMU*/

/******************************************************************
         PMIC_CON7 API 
******************************************************************/
void pmu_set_uv_sel(pmu_uvlo_volt volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   reg_val16 &= (~UV_SEL);
   reg_val16 |= ((volt<<UV_SEL_SHIFT) & UV_SEL);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_rbgsel(pmu_rbgsel sel)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   reg_val16 &= (~RBGSEL);
   reg_val16 |= ((sel<<RBGSEL_SHIFT) & RBGSEL);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_ibgsel(pmu_ibgsel sel)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   reg_val16 &= (~IBGSEL);
   reg_val16 |= ((sel<<IBGSEL_SHIFT) & IBGSEL);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_osc(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   if (enable == KAL_TRUE)
      reg_val16 &= (~OSCDIS);
   else
      reg_val16 |= OSCDIS;
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_cksel(pmu_cksel sel)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   reg_val16 &= (~CKSEL);
   reg_val16 |= ((sel<<CKSEL_SHIFT) & CKSEL);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vbssel(pmu_vbssel sel)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   reg_val16 &= (~VBSSEL);
   reg_val16 |= ((sel<<VBSSEL_SHIFT) & VBSSEL);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

#if defined(MT6223PMU)
void pmu_reset_drv(kal_bool reset)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   if (reset == KAL_TRUE)
      reg_val16 |= RESET_DRV;
   else
      reg_val16 &= (~RESET_DRV);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}
#endif /*MT6223PMU*/

#if defined(MT6238PMU)
void pmu_set_bias_gen_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   if (enable == KAL_TRUE)
      reg_val16 |= BIAS_GEN_FORCE;
   else
      reg_val16 &= (~BIAS_GEN_FORCE);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

#endif /*MT6238PMU*/

void pmu_set_ov_hys_enb(pmu_ov_hys_enb value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   reg_val16 &= (~OV_HYS_ENB);
   reg_val16 |= ((value<<OV_HYS_ENB_SHIFT) & OV_HYS_ENB);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_ov_thfreeze(pmu_ov_thfreeze value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON7);
   reg_val16 &= (~OV_THFREEZE);
   reg_val16 |= ((value<<OV_THFREEZE_SHIFT) & OV_THFREEZE);
   DRV_WriteReg(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);      
}

kal_bool pmu_is_pwrkey_deb_disable(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CON7);
   if (reg_val16 & PWRKEY_DEB)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

#if defined(MT6238PMU)
/******************************************************************
         PMIC_CON8 API 
******************************************************************/
void pmu_set_sdm_order(pmu_sdm_order order)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON8);
   reg_val16 &= (~SDM_ORDER);
   reg_val16 |= ((order<<SDM_ORDER_SHIFT) & SDM_ORDER);
   DRV_WriteReg(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_pid_gain_p(pmu_pid_gain_p gain)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON8);
   reg_val16 &= (~GAIN_P);
   reg_val16 |= ((gain<<GAIN_P_SHIFT) & GAIN_P);
   DRV_WriteReg(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_pid_gain(pmu_pid_gain gain)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON8);
   reg_val16 &= (~GAIN);
   reg_val16 |= ((gain<<GAIN_SHIFT) & GAIN);
   DRV_WriteReg(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_pid_gain_d(pmu_pid_gain_d gain)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON8);
   reg_val16 &= (~GAIN_D);
   reg_val16 |= ((gain<<GAIN_D_SHIFT) & GAIN_D);
   DRV_WriteReg(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_duty_init(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON8);
   reg_val16 &= (~DUTY_INIT);
   reg_val16 |= ((value<<DUTY_INIT_SHIFT) & DUTY_INIT);
   DRV_WriteReg(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vcore_volt(pmu_vcore_volt volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON8);
   reg_val16 &= (~VOSEL);
   reg_val16 |= ((volt<<VOSEL_SHIFT) & VOSEL);
   DRV_WriteReg(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_sdm_fb_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON8);
   if (enable == KAL_TRUE)
      reg_val16 &= (~SDM_FB_EN);
   else
      reg_val16 |= SDM_FB_EN;
   DRV_WriteReg(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CON9 API 
******************************************************************/
void pmu_set_vfbadj(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   reg_val16 &= (~VFBADJ);
   reg_val16 |= ((value<<VFBADJ_SHIFT) & VFBADJ);
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_direct_ctrl_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   if (enable == KAL_TRUE)
      reg_val16 &= (~DIRECT_CTRL_EN);
   else
      reg_val16 |= DIRECT_CTRL_EN;
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_dcv_ck(pmu_dcv_ck clk)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   reg_val16 &= (~DCV_CK_SEL);
   reg_val16 |= ((clk<<DCV_CK_SEL_SHIFT) & DCV_CK_SEL);
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_isel(pmu_isel sel)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   reg_val16 &= (~ISEL);
   reg_val16 |= ((sel<<ISEL_SHIFT) & ISEL);
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_adjcksel(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   reg_val16 &= (~ADJCKSEL);
   reg_val16 |= ((value<<ADJCKSEL_SHIFT) & ADJCKSEL);
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_manual_mode(pmu_mode_set mode)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   reg_val16 &= (~MODESET);
   reg_val16 |= ((mode<<MODESET_SHIFT) & MODESET);
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_auto_mode_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   if (enable == KAL_TRUE)
      reg_val16 &= (~MODEEN0);
   else
      reg_val16 |= MODEEN0;
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}


void pmu_set_mode_cmp(pmu_mode_cmp cmp)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   reg_val16 &= (~MODECMP);
   reg_val16 |= ((cmp<<MODECMP_SHIFT) & MODECMP);
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_ave_current_mode(pmu_mode_ave_current mode)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   reg_val16 &= (~MODESEL1A);
   reg_val16 |= ((mode<<MODESEL1A_SHIFT) & MODESEL1A);
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_dcv_test_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CON9);
   if (enable == KAL_TRUE)
      reg_val16 &= (~DCV_TEST_EN);
   else
      reg_val16 |= DCV_TEST_EN;
   DRV_WriteReg(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CONA API 
******************************************************************/
void pmu_set_pfm_max_current(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONA);
   reg_val16 &= (~PFMSEL_CURRENT);
   reg_val16 |= ((value<<PFMSEL_CURRENT_SHIFT) & PFMSEL_CURRENT);
   DRV_WriteReg(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_pfm_resistor(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONA);
   reg_val16 &= (~PFMSEL_RESISTOR);
   reg_val16 |= ((value<<PFMSEL_RESISTOR_SHIFT) & PFMSEL_RESISTOR);
   DRV_WriteReg(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_ndc_offset(pmu_ndc_offset offset)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONA);
   reg_val16 &= (~NCDOF);
   reg_val16 |= ((offset<<NCDOF_SHIFT) & NCDOF);
   DRV_WriteReg(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_dcv_trim(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONA);
   reg_val16 &= (~DCVTRIM);
   reg_val16 |= ((value<<DCVTRIM_SHIFT) & DCVTRIM);
   DRV_WriteReg(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_iasel(pmu_iasel volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONA);
   reg_val16 &= (~IASEL);
   reg_val16 |= ((volt<<IASEL_SHIFT) & IASEL);
   DRV_WriteReg(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_rsel(pmu_rsel sel)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONA);
   reg_val16 &= (~RSEL);
   reg_val16 |= ((sel<<RSEL_SHIFT) & RSEL);
   DRV_WriteReg(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CONB API 
******************************************************************/
kal_bool pmu_get_vusb_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CONB);
   if (reg_val16 & VUSB_STAUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vusb_en_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONB);
   if (enable == KAL_TRUE)
      reg_val16 |= VUSB_EN_FORCE;
   else
      reg_val16 &= (~VUSB_EN_FORCE);
   DRV_WriteReg(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vusb_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONB);
   if (enable == KAL_TRUE)
      reg_val16 |= VUSB_EN;
   else
      reg_val16 &= (~VUSB_EN);
   DRV_WriteReg(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalusb(pmu_icalusb_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONB);
   reg_val16 &= (~ICALUSB_EN);
   reg_val16 |= ((code<<ICALUSB_EN_SHIFT) & ICALUSB_EN);
   DRV_WriteReg(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_antiudsh_usb_dn(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONB);
   if (enable == KAL_TRUE)
      reg_val16 |= ANTIUDSH_USB_DN;
   else
      reg_val16 &= (~ANTIUDSH_USB_DN);
   DRV_WriteReg(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vusb_plnmos_dis(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONB);
   if (enable == KAL_TRUE)
      reg_val16 |= VUSB_PLNMOS_DIS;
   else
      reg_val16 &= (~VUSB_PLNMOS_DIS);
   DRV_WriteReg(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vusb_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONB);
   reg_val16 &= (~VUSB_CAL);
   reg_val16 |= ((value<<VUSB_CAL_SHIFT) & VUSB_CAL);
   DRV_WriteReg(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vfbadj_slp(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONB);
   reg_val16 &= (~VFBADJ_SLP);
   reg_val16 |= ((value<<VFBADJ_SLP_SHIFT) & VFBADJ_SLP);
   DRV_WriteReg(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CONC API 
******************************************************************/
kal_bool pmu_get_vsim2_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CONC);
   if (reg_val16 & VSIM2_STAUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vsim2_en_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   if (enable == KAL_TRUE)
      reg_val16 |= VSIM2_EN_FORCE;
   else
      reg_val16 &= (~VSIM2_EN_FORCE);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalsim2(pmu_icalsim2_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   reg_val16 &= (~ICALSIM2_EN);
   reg_val16 |= ((code<<ICALSIM2_EN_SHIFT) & ICALSIM2_EN);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_antiudsh_sim2_dn(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   if (enable == KAL_TRUE)
      reg_val16 |= ANTIUDSH_SIM2_DN;
   else
      reg_val16 &= (~ANTIUDSH_SIM2_DN);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim2_plnmos_dis(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   if (enable == KAL_TRUE)
      reg_val16 |= VSIM2_PLNMOS_DIS;
   else
      reg_val16 &= (~VSIM2_PLNMOS_DIS);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim2_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   reg_val16 &= (~VSIM2_CAL);
   reg_val16 |= ((value<<VSIM2_CAL_SHIFT) & VSIM2_CAL);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_clk_source_sel(pmu_clk_src_sel source)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   reg_val16 &= (~CLK_SOURCE_SEL);
   reg_val16 |= ((source<<CLK_SOURCE_SEL_SHIFT) & CLK_SOURCE_SEL);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vtcxo_on_sel(pmu_vtcxo_on_sel sel)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   reg_val16 &= (~VTCXO_ON_SEL);
   reg_val16 |= ((sel<<VTCXO_ON_SEL_SHIFT) & VTCXO_ON_SEL);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim_pwr_saving_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   if (enable == KAL_TRUE)
      reg_val16 |= VSIM_PWR_SAVING;
   else
      reg_val16 &= (~VSIM_PWR_SAVING);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim2_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   if (enable == KAL_TRUE)
      reg_val16 |= VSIM2_EN;
   else
      reg_val16 &= (~VSIM2_EN);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsim2_sel(pmu_vsim_volt volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONC);
   reg_val16 &= (~VSIM2_SEL);
   reg_val16 |= ((volt<<VSIM2_SEL_SHIFT) & VSIM2_SEL);
   DRV_WriteReg(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_COND API 
******************************************************************/
kal_bool pmu_get_vmc_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_COND);
   if (reg_val16 & VMC_STAUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vmc_en_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_COND);
   if (enable == KAL_TRUE)
      reg_val16 |= VMC_EN_FORCE;
   else
      reg_val16 &= (~VMC_EN_FORCE);
   DRV_WriteReg(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalmc(pmu_icalmc_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_COND);
   reg_val16 &= (~ICALMC_EN);
   reg_val16 |= ((code<<ICALMC_EN_SHIFT) & ICALMC_EN);
   DRV_WriteReg(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_antiudsh_mc_dn(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_COND);
   if (enable == KAL_TRUE)
      reg_val16 |= ANTIUDSH_MC_DN;
   else
      reg_val16 &= (~ANTIUDSH_MC_DN);
   DRV_WriteReg(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vmc_plnmos_dis(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_COND);
   if (enable == KAL_TRUE)
      reg_val16 |= VMC_PLNMOS_DIS;
   else
      reg_val16 &= (~VMC_PLNMOS_DIS);
   DRV_WriteReg(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vmc_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_COND);
   reg_val16 &= (~VMC_CAL);
   reg_val16 |= ((value<<VMC_CAL_SHIFT) & VMC_CAL);
   DRV_WriteReg(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vmc_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_COND);
   if (enable == KAL_TRUE)
      reg_val16 |= VMC_EN;
   else
      reg_val16 &= (~VMC_EN);
   DRV_WriteReg(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vmc_sel(pmu_vmc_volt volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_COND);
   reg_val16 &= (~VMC_SEL);
   reg_val16 |= ((volt<<VMC_SEL_SHIFT) & VMC_SEL);
   DRV_WriteReg(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CONE API 
******************************************************************/
kal_bool pmu_get_vcamera_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CONE);
   if (reg_val16 & VCAMERA_STAUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vcamera_en_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONE);
   if (enable == KAL_TRUE)
      reg_val16 |= VCAMERA_EN_FORCE;
   else
      reg_val16 &= (~VCAMERA_EN_FORCE);
   DRV_WriteReg(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalcamera(pmu_icalcamera_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONE);
   reg_val16 &= (~ICALCAMERA_EN);
   reg_val16 |= ((code<<ICALCAMERA_EN_SHIFT) & ICALCAMERA_EN);
   DRV_WriteReg(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_antiudsh_camera_dn(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONE);
   if (enable == KAL_TRUE)
      reg_val16 |= ANTIUDSH_CAMERA_DN;
   else
      reg_val16 &= (~ANTIUDSH_CAMERA_DN);
   DRV_WriteReg(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vcamera_plnmos_dis(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONE);
   if (enable == KAL_TRUE)
      reg_val16 |= VCAMERA_PLNMOS_DIS;
   else
      reg_val16 &= (~VCAMERA_PLNMOS_DIS);
   DRV_WriteReg(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vcamera_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONE);
   reg_val16 &= (~VCAMERA_CAL);
   reg_val16 |= ((value<<VCAMERA_CAL_SHIFT) & VCAMERA_CAL);
   DRV_WriteReg(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_dcv_slew_ctrl(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONE);
   reg_val16 &= (~DCV_SLEW_CTRL);
   reg_val16 |= ((value<<DCV_SLEW_CTRL_SHIFT) & DCV_SLEW_CTRL);
   DRV_WriteReg(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vcamera_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONE);
   if (enable == KAL_TRUE)
      reg_val16 |= VCAMERA_EN;
   else
      reg_val16 &= (~VCAMERA_EN);
   DRV_WriteReg(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vcamera_sel(pmu_vcamera_volt volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONE);
   reg_val16 &= (~VCAMERA_SEL);
   reg_val16 |= ((volt<<VCAMERA_SEL_SHIFT) & VCAMERA_SEL);
   DRV_WriteReg(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CONF API 
******************************************************************/
kal_bool pmu_get_vsw_a_status(void)
{
   kal_uint16  reg_val16;

   reg_val16 = DRV_Reg(PMIC_CONF);
   if (reg_val16 & VSW_A_STAUS)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void pmu_set_vsw_a_en_force(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONF);
   if (enable == KAL_TRUE)
      reg_val16 |= VSW_A_EN_FORCE;
   else
      reg_val16 &= (~VSW_A_EN_FORCE);
   DRV_WriteReg(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icalsw(pmu_icalsw_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONF);
   reg_val16 &= (~ICALSW_EN);
   reg_val16 |= ((code<<ICALSW_EN_SHIFT) & ICALSW_EN);
   DRV_WriteReg(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsw_a_sel(pmu_vsw_a_volt volt)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONF);
   reg_val16 &= (~VSW_A_SEL);
   reg_val16 |= ((volt<<VSW_A_SEL_SHIFT) & VSW_A_SEL);
   DRV_WriteReg(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsw_a_cal(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONF);
   reg_val16 &= (~VSW_A_CAL);
   reg_val16 |= ((value<<VSW_A_CAL_SHIFT) & VSW_A_CAL);
   DRV_WriteReg(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icala(pmu_icala_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONF);
   reg_val16 &= (~ICALA_EN);
   reg_val16 |= ((code<<ICALA_EN_SHIFT) & ICALA_EN);
   DRV_WriteReg(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_icaltcxo(pmu_icaltcxo_code code)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONF);
   reg_val16 &= (~ICALTCXO_EN);
   reg_val16 |= ((code<<ICALTCXO_EN_SHIFT) & ICALTCXO_EN);
   DRV_WriteReg(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vsw_a_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONF);
   if (enable == KAL_TRUE)
      reg_val16 |= VSW_A_EN;
   else
      reg_val16 &= (~VSW_A_EN);
   DRV_WriteReg(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_oc_fold_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONF);
   if (enable == KAL_TRUE)
      reg_val16 |= OC_FOLD_EN;
   else
      reg_val16 &= (~OC_FOLD_EN);
   DRV_WriteReg(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);      
}

/******************************************************************
         PMIC_CONG API 
******************************************************************/
void pmu_set_vref_bg(pmu_vref_bg value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONG);
   reg_val16 &= (~VREF_BG);
   reg_val16 |= ((value<<VREF_BG_SHIFT) & VREF_BG);
   DRV_WriteReg(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_thr_sel(pmu_thr_sel value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONG);
   reg_val16 &= (~THR_SEL);
   reg_val16 |= ((value<<THR_SEL_SHIFT) & THR_SEL);
   DRV_WriteReg(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_ldo_soft_st_dis(kal_bool disable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONG);
   if (disable == KAL_TRUE)
      reg_val16 |= LDO_SOFT_ST;
   else
      reg_val16 &= (~LDO_SOFT_ST);
   DRV_WriteReg(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_tpsel_led(kal_uint8 value)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONG);
   reg_val16 &= (~TPSEL_LED);
   reg_val16 |= ((value<<TPSEL_LED_SHIFT) & TPSEL_LED);
   DRV_WriteReg(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_isense_out_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONG);
   if (enable == KAL_TRUE)
      reg_val16 |= ISENSE_OUT_EN;
   else
      reg_val16 &= (~ISENSE_OUT_EN);
   DRV_WriteReg(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);      
}

void pmu_set_vbat_out_en(kal_bool enable)
{
   kal_uint16  reg_val16;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = DRV_Reg(PMIC_CONG);
   if (enable == KAL_TRUE)
      reg_val16 |= VBAT_OUT_EN;
   else
      reg_val16 &= (~VBAT_OUT_EN);
   DRV_WriteReg(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);      
}

#endif /*MT6238PMU*/


#endif /* defined(MT6223PMU) || defined(MT6238PMU) */