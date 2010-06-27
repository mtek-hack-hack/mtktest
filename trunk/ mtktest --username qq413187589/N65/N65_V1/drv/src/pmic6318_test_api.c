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
 *    pmic6318_test_api.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines 6318 API that engineer/meta mode use
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
#include 	"pmic6318_hw.h"
#include 	"pmic6318_sw.h"
#include 	"b2psi_hw.h"
#include 	"b2psi_sw.h"
#include 	"intrCtrl.h"
#include	   "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include	   "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "eint.h"
#include    "drvsignals.h"

#if ( (defined(MT6318))  )
extern kal_uint8 pmic_reg_save[PMIC_MAX_REG];
/*
* FUNCTION                                                            
*	pmic_reg_write
*
* DESCRIPTION                                                           
*  write data to PMIC
*
* CALLS  
*  used to write data to PMIC
*
* PARAMETERS
*	data: write data
*	register_index: register index
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_reg_write(kal_uint8 data, kal_uint16 register_index)
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   B2PSI_write(data, register_index);
   RestoreIRQMask(savedMask);
}
/*
* FUNCTION                                                            
*	pmic_reg_read
*
* DESCRIPTION                                                           
*  read data from PMIC
*
* CALLS  
*  used to read data from PMIC 
*
* PARAMETERS
*	register_index: register index
*	
* RETURNS
*	read data
*
* GLOBALS AFFECTED
*   external_global
*/   
/*register read*/
kal_uint8 pmic_reg_read(kal_uint16 register_index)
{
   kal_uint8 data=0;
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   data=B2PSI_read(register_index);
   RestoreIRQMask(savedMask);
   return data;
}
/*
* FUNCTION                                                            
*	pmic_get_speaker_stat
*
* DESCRIPTION                                                           
*  get audio amplifier status
*
* CALLS  
*  used to get audio amplifier status
*
* PARAMETERS
*	None
*	
* RETURNS
*	Audio amplifier status
*
* GLOBALS AFFECTED
*   external_global
*/
/*read speaker status*/
kal_uint8 pmic_get_speaker_stat(void)
{   
   kal_uint8 data=0;
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
   data&=SPEAKER_ON;
   return (data>>1);
}
/*
* FUNCTION                                                            
*	pmic_get_speaker_gain
*
* DESCRIPTION                                                           
*  get speaker gain
*
* CALLS  
*  used to get speaker gain status
*
* PARAMETERS
*	None
*	
* RETURNS
*	speaker gain
*
* GLOBALS AFFECTED
*   external_global
*/
/*read speaker gain*/   
kal_uint8 pmic_get_speaker_gain(void)
{
   kal_uint8 data=0;
   data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];
   data&=SPK_GAIN_MASK;
   data=data>>SPK_GAIN_SHIFT;
   return (data*3);
} 
/*
* FUNCTION                                                            
*	pmic_get_LED_stat
*
* DESCRIPTION                                                           
*  get R/G/B/KP/BL LED status
*
* CALLS  
*  used to get R/G/B/KP/BL LED status
*
* PARAMETERS
*	type: LED type
*	
* RETURNS
*	LED on or off
*
* GLOBALS AFFECTED
*   external_global
*/  
/*R/G/B/KP/BL LED status*/
kal_uint8 pmic_get_LED_stat(pmic_led_type type)
{
   kal_uint8 data=0;
   data=pmic_reg_save[(type>>PMIC_SHIFT_BITS)];
   data&=LED_ON;   
   data=data>>7;
   return data;
} 
/*
* FUNCTION                                                            
*	pmic_get_LED_config
*
* DESCRIPTION                                                           
*  
*
* CALLS  
*  used to get R/G/B/KP/BL LED configuration
*
* PARAMETERS
*	duty: duty cycle
*  Current: LED current
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/  
/*current/duty*/
void pmic_get_LED_config(pmic_led_type    type, 
                         kal_uint8        *duty,  
                         kal_uint32 *current)
{
   kal_uint8 data=0;
   
   data=pmic_reg_save[(type>>PMIC_SHIFT_BITS)];
   if(type==KP_LED||type==BL_LED)   
      *current=0;      
   else   
      *current=((data&0x60)>>5)*4+12;               
   
   *duty=(((data&0x1f)+1)*100)>>5;                     
} 
/*
* FUNCTION                                                            
*	pmic_get_rgb_dim
*
* DESCRIPTION                                                           
*  get R/G/B/KP DIM clock and charge pump configuration
*
* CALLS  
*  used to get R/G/B/KP DIM clock and charge pump configuration
*
* PARAMETERS
*	pump_enable: charge pump on/off
*  pump_current: charge pump current
*	clk: dim clock
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/  
void pmic_get_rgb_dim(kal_bool   *pump_enable, 
                      kal_uint32 *pump_current, 
                      kal_uint32 *clk)
{
   kal_uint8 data1=0, data2=0;
   
   data2=pmic_reg_save[(PMIC_DIM_CLOCK>>PMIC_SHIFT_BITS)];
   *clk=(data2&0xf);
   *clk=1000/(*clk+1);
   
   data1=pmic_reg_save[(PMIC_CHARGE_PUMP>>PMIC_SHIFT_BITS)];
   *pump_enable=(data1&CHR_PUMP_ON)>>7;   
   /*?????*/
   *pump_current=(((data1&0x60)>>5)+1)*50;
}   
/*
* FUNCTION                                                            
*	pmic_get_BL_dim
*
* DESCRIPTION                                                           
*  get BL dim clock setting
*
* CALLS  
*  used to get BL dim clock setting
*
* PARAMETERS
*	div_enable: bypass divider or not
*  clk: BL dim clock
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_get_BL_dim(kal_bool *div_enable, kal_uint32 *clk)
{
   kal_uint8 data1=0, data2=0;
   data1=pmic_reg_save[(PMIC_BLLED_DRIVER>>PMIC_SHIFT_BITS)];
   *div_enable=(data1&BL_DIV_BYPASS)>>5;
   data2=pmic_reg_save[(PMIC_DIM_CLOCK>>PMIC_SHIFT_BITS)];
   *clk=(data2&0xf0)>>4;
   if(*div_enable==KAL_TRUE) 
      *clk=25000/(*clk+1);
   else
      *clk=1000/(*clk+1);
      
}   
/*
* FUNCTION                                                            
*	pmic_get_ac_usb_status
*
* DESCRIPTION                                                           
*  get AC/USB charging current
*
* CALLS  
*  used to get AC/USB charging current
*
* PARAMETERS
*	type: AC or USB
*  chr_enable: charge enable or not
*  current: charging current
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_get_ac_usb_status(chr_type   type, 
                            kal_bool   *chr_enable,
                            kal_uint32 *current)
{
   kal_uint8 data1=0, data2=0;
   
   data1=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];
   
   if(type==USB_CHR)
   {
      data2=pmic_reg_save[(PMIC_CHARGE_PUMP>>PMIC_SHIFT_BITS)];
      *chr_enable=data2&0x1;
   }
   else
   {
      *chr_enable=(data1&0x80)>>7;
   }   
      
   
   data1&=0x7;
   switch(data1)
   {
       case 0:
         *current=50;
         break;  
       case 1:
         *current=90;
         break;  
       case 2:
         *current=150;
         break;  
       case 3:
         *current=225;
         break;                                
       case 4:
         *current=300;
         break;  
       case 5:
         *current=450;
         break;  
       case 6:
         *current=650;
         break;
       case 7:
         *current=800;
         break;  
   }   
}   
/*
* FUNCTION                                                            
*	pmic_get_misc_ldo_stat
*
* DESCRIPTION                                                           
*  get LDO status
*
* CALLS  
*  used to get LDO status
*
* PARAMETERS
*	type: LDO type
*  enable: enable or not
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_get_misc_ldo_stat(pmic_misc_stat type, kal_bool *enable)
{
   kal_uint8 data;  
     
   switch(type)
   {
      case MISC_STAT_VIRBRATOR:
         data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
         *enable=data&0x1;
         break;
      case MISC_STAT_VIRBRATOR_SEL:
         data=pmic_reg_save[(PMIC_CHARGE_PUMP>>PMIC_SHIFT_BITS)];
         *enable=(data&0x2)>>1;
         break;   
      case MISC_STAT_MC:   
         data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
         *enable=(data&0x8)>>3;
         break;
      case MISC_STAT_MC_SEL:   
         data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];
         *enable=(data&0x8)>>3;
         break;
      case MISC_STAT_VASW:
         data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
         *enable=(data&0x40)>>6;   
         break;
      case MISC_STAT_VASW_SEL:   
         data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];
         *enable=(data&0x80)>>7;
         break;
      case MISC_STAT_USB_PWR:   
         data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];
         *enable=(data&0x8)>>3;
         break;               
      case MISC_STAT_VBOUT:   
         data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];
         *enable=(data&0x20)>>5;
         break;
      case MISC_STAT_VISENSE:   
         data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];
         *enable=(data&0x40)>>6;
         break;       
   }   
  
}   

#ifdef MT6318_DEBUG
   kal_uint8 dbgdata;
   kal_uint8 dbgduty;
   kal_uint32 dbgcurrent;
   kal_bool dbgenable;
   kal_uint32 dbgclock;
   kal_uint32 dbgcurrent2;
   
void pmic_test_mode_test(void)
{ 
   //dbgdata=pmic_reg_read(0x3000);
   //pmic_reg_write(0xff, 0x3000);
   //dbgdata=pmic_reg_read(0x3000);
   //pmic_reg_write(0x55, 0x3000);
   //dbgdata=pmic_reg_read(0x3000);

   /*pmic charger status*/
   dbgdata=pmic_chr_status(CHR_STAT_OV);
   dbgdata=pmic_chr_status(CHR_STAT_CHRDET);
   dbgdata=pmic_chr_status(CHR_STAT_BAT_ON);
   dbgdata=pmic_chr_status(CHR_STAT_AC_DET);
   dbgdata=pmic_chr_status(CHR_STAT_USB_DET);   
   dbgdata=pmic_chr_status(CHR_STAT_CV);
   dbgdata=pmic_chr_status(CHR_STAT_CHRG_DIS);
   /*charger control*/
   pmic_get_ac_usb_status(AC_CHR, &dbgenable, &dbgcurrent);
   pmic_get_ac_usb_status(USB_CHR, &dbgenable, &dbgcurrent);
   
   /*audio*/
   dbgdata=pmic_get_speaker_stat();
   dbgdata=pmic_get_speaker_gain();
   
   /*R/G/B/KP/BL*/
   dbgdata=pmic_get_LED_stat(R_LED);
   dbgdata=pmic_get_LED_stat(G_LED);
   dbgdata=pmic_get_LED_stat(B_LED);
   dbgdata=pmic_get_LED_stat(KP_LED);
   dbgdata=pmic_get_LED_stat(BL_LED);
   pmic_get_LED_config(R_LED, &dbgduty, &dbgcurrent2);
   pmic_get_LED_config(G_LED, &dbgduty, &dbgcurrent2);
   pmic_get_LED_config(B_LED, &dbgduty, &dbgcurrent2);
   pmic_get_LED_config(KP_LED, &dbgduty, &dbgcurrent2);
   pmic_get_LED_config(BL_LED, &dbgduty, &dbgcurrent2);
   
   pmic_get_rgb_dim(&dbgenable, &dbgcurrent, &dbgclock);
   pmic_get_BL_dim(&dbgenable, &dbgclock);
   /*msic ldo status*/
   pmic_get_misc_ldo_stat(MISC_STAT_VISENSE, &dbgenable);
   pmic_get_misc_ldo_stat(MISC_STAT_VBOUT, &dbgenable);
   pmic_get_misc_ldo_stat(MISC_STAT_USB_PWR, &dbgenable);
   pmic_get_misc_ldo_stat(MISC_STAT_VASW_SEL, &dbgenable);
   pmic_get_misc_ldo_stat(MISC_STAT_VASW, &dbgenable);
   pmic_get_misc_ldo_stat(MISC_STAT_MC_SEL, &dbgenable);
   pmic_get_misc_ldo_stat(MISC_STAT_MC, &dbgenable);
   pmic_get_misc_ldo_stat(MISC_STAT_VIRBRATOR, &dbgenable);   
}   
#endif/*MT6318_DEBUG*/

#endif/*MT6318*/
 