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
 *    pmic6318.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines functions that PMIC 6318 can support
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
#include    "bmt.h"
#include    "drvsignals.h"
#include    "custom_hw_default.h"

#if ( (defined(MT6318))  )
#define PMIC_INTERNAL_SRAM

#if !defined(__FUE__)
   #define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
   #define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
   #define SAVEANDSETIRQMASK()      0
   #define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/

typedef  struct
{
   kal_int16       tq_start;
   kal_int16       max_start;
   kal_int16       max_end;
   kal_int16       max_diff;

}  sMTMAXTIME;
sMTMAXTIME  pmic_duration;
    
pmic_chrdect_callbac_struct PMIC_CHRDET;    
    
#ifdef PMIC_INTERNAL_SRAM
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif
kal_uint8 pmic_reg_save[PMIC_MAX_REG];
kal_uint16 pmic_max_bl_clk;
#ifdef PMIC_INTERNAL_SRAM
#pragma arm section rwdata, rodata , zidata
#endif
   
/* For LCD backlight PWM */
static kal_uint8  PMIC_PWM_LEVEL_SAVE;   /*for MMI usage*/
static pmic_led_type  bl_pwm_type;

void pmic_chr_pump_enable_internal(kal_bool enable);
   
/*
* FUNCTION                                                            
*	pmic_init
*
* DESCRIPTION                                                           
*   PMIC6318 driver initial function
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
void pmic_init(void)
{  
   kal_uint8 index ;
   extern void pmic_customization_init(void);
   /*????need remove*/   
   for(index=0;index<PMIC_MAX_REG;index++)
   {
      pmic_reg_save[index]=B2PSI_read((index<<PMIC_SHIFT_BITS));  
   }     
   pmic_adc_measure_div2(KAL_TRUE);
   pmic_adc_measure_sel(PMIC_ADC_ISENSE);
   pmic_adc_measure_sel(PMIC_ADC_VBAT);  
   pmic_charge_pump_init((CHARGE_PUMP_LEVEL3|CHARGE_PUMP_CTRL_SET));
   pmic_audio_diffential_enable(KAL_TRUE);
   pmic_customization_init();  
   /*temp, force LCD on*/
   //B2PSI_write(0xff,PMIC_LDO_STAT);  
   B2PSI_write(0x63,PMIC_EXTRAS);       

   /* Get PWM type for control LCD backlight. */
   bl_pwm_type = pmic_custom_get_bl_pmw_type();
}   

/*
* FUNCTION                                                            
*	pmic_led_config
*
* DESCRIPTION                                                           
*  Adjust LED driver current and duty cycle
*
* CALLS  
*	It is called by UEM
*
* PARAMETERS
*	led_conf: current and duty cycle setting
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
/*LED control*/
void pmic_led_config(pmic_led_struct *led_conf)
{   
   kal_uint8 pwm_d=0;
   kal_uint8 data;
   kal_uint32 savedMask;
    
   pwm_d=((led_conf->duty_cycle*32)/100);
   if(pwm_d<1) 
       pwm_d=0;
   else    
      pwm_d--;
   pwm_d=pwm_d&0x1f;
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(led_conf->type>>PMIC_SHIFT_BITS)];
   if(led_conf->type==KP_LED||led_conf->type==BL_LED) 
   {
      data=(data&0xE0)|pwm_d;
   }
   else
   {
      data=(data&0x80)|(pwm_d|led_conf->current);
   }
   B2PSI_write_fast(data, led_conf->type);
   RESTOREIRQMASK(savedMask);
}
/*
* FUNCTION                                                            
*	pmic_dim_enable
*
* DESCRIPTION                                                           
*  Turn on or turn DIM clock
*
* CALLS  
*	
*
* PARAMETERS
*  enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_dim_enable(kal_bool enable)
{
   kal_uint8 data;  
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_LDO_STAT>>PMIC_SHIFT_BITS)];
   
   if(enable==KAL_TRUE)
   {      
      data|=DIM_ON;               
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~DIM_ON;                  
   }      
   B2PSI_write_fast(data,PMIC_LDO_STAT);   
   RESTOREIRQMASK(savedMask);            
}   

/*
* FUNCTION                                                            
*	pmic_led_enable
*
* DESCRIPTION                                                           
*  Turn on or turn off LED 
*
* CALLS  
*	It is called by UEM
*
* PARAMETERS
*	type: LED type
*  enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
/*start and stop*/
kal_uint16 led_status=0;
#define RGBK_LED_MASK  ((1<<(R_LED>>PMIC_SHIFT_BITS)) | (1<<(G_LED>>PMIC_SHIFT_BITS)) | (1<<(B_LED>>PMIC_SHIFT_BITS))\
                        | (1<<(KP_LED>>PMIC_SHIFT_BITS)))
void pmic_led_enable(pmic_led_type type, kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(type>>PMIC_SHIFT_BITS)];
   
   if(enable==KAL_TRUE)
   {
      data|=LED_ON;   
      led_status|=(1<<(type>>PMIC_SHIFT_BITS));
   }   
   else
   {
      data&=~LED_ON;
      led_status&=~(1<<(type>>PMIC_SHIFT_BITS));            
   }   
   B2PSI_write_fast(data,type);
   RESTOREIRQMASK(savedMask);            

   if(enable==KAL_TRUE)
   {
      pmic_dim_enable(KAL_TRUE);/*turn on dim first.*/
      pmic_chr_pump_enable(KAL_TRUE);
   }
   savedMask = SAVEANDSETIRQMASK();
   if(((volatile kal_uint16)led_status)==0)  
   {
      RESTOREIRQMASK(savedMask);
      pmic_chr_pump_enable(KAL_FALSE);      
      pmic_dim_enable(KAL_FALSE);                  
   }
   else if((((volatile kal_uint16)led_status) & RGBK_LED_MASK)==0)  
   {
      RESTOREIRQMASK(savedMask);
      pmic_chr_pump_enable(KAL_FALSE);      
   }      
   else
   {
      RESTOREIRQMASK(savedMask);            
   }   
}   

/*
* FUNCTION                                                            
*	pmic_rgb_dim_clk_setting
*
* DESCRIPTION                                                           
*  Adjust dim clock
*
* CALLS  
*	It is called adjust dim clock
*
* PARAMETERS
*	clk: dim clock
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
/*This only for R/G/B/KP */
/*Note the maximum clk is 1K*/
void pmic_rgb_dim_clk_setting(kal_uint32 clk)
{
   kal_uint8 div;
   kal_uint8 data;
   kal_uint32 savedMask;
   if(clk>=1000)
      clk=1000;
   if(clk==0)
      clk=1;   
      
   div=(1000/clk)-1;
   div=div&0xf;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_DIM_CLOCK>>PMIC_SHIFT_BITS)];   
   data&=0xf0;
   div=data|div;
   B2PSI_write_fast(div, PMIC_DIM_CLOCK);
   RESTOREIRQMASK(savedMask); 
} 

/*????new bl setting*/
void pmic_bl_div_bypass(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_BLLED_DRIVER>>PMIC_SHIFT_BITS)];

   if(enable==KAL_TRUE)
   {
      data|=BL_DIV_BYPASS;   
      pmic_max_bl_clk=25000;/*25K*/
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~BL_DIV_BYPASS;
      pmic_max_bl_clk=1000;/*1K*/
   }            
   B2PSI_write_fast(data, PMIC_BLLED_DRIVER);    
   RESTOREIRQMASK(savedMask);      
}
void pmic_bl_dim_clk_setting(kal_uint32 clk)
{
   kal_uint8 div=1;
   kal_uint8 data;
   kal_uint32 savedMask;      
   
   if(pmic_max_bl_clk==25000)
   {
      if(clk>=25000)
         clk=25000; 
      div=(25000/clk)-1;      
   }   
   else if(pmic_max_bl_clk==1000)
   {
      if(clk>=1000)
         clk=1000;       
      div=(1000/clk)-1;      
   }      
   
   div=div&0xf;
   div=div<<4;   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_DIM_CLOCK>>PMIC_SHIFT_BITS)];   
   data&=0x0f;
   div=data|div;
   B2PSI_write_fast(div, PMIC_DIM_CLOCK);
   RESTOREIRQMASK(savedMask); 
}
/*????new adc control*/
void pmic_adc_measure_div2(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];
   /**/
   if(enable==KAL_TRUE)
   {
      data&=~VBHSEL_DIV2;      
   }   
   else if(enable==KAL_FALSE)
   {      
      data|=VBHSEL_DIV2;         
   }            
   B2PSI_write_fast(data, PMIC_EXTRAS);    
   RESTOREIRQMASK(savedMask);      
}
void pmic_adc_measure_sel(adc_type sel)
{
   
   kal_uint8 data;
   kal_uint32 savedMask; 
   
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];
   sel=sel<<5;
   //data=data&0x9f;
   if (sel==PMIC_ADC_OFF)
      data=data&0x9f;
   data=data|sel;
   /**/   
   B2PSI_write_fast(data, PMIC_EXTRAS);    
   RESTOREIRQMASK(savedMask);      
}

#ifdef PMIC_INTERNAL_SRAM
#pragma arm section code = "INTERNCODE"
#endif
void pmic_adc_measure_sel_fast(adc_type sel)
{   
   kal_uint8 data;
   
   data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];
   sel=sel<<5;
   //data=data&0x9f;
   if (sel==PMIC_ADC_OFF)
      data=data&0x9f;
   data=data|sel;
   /**/   
   B2PSI_write_fast(data, PMIC_EXTRAS);    
}
#ifdef PMIC_INTERNAL_SRAM
#pragma arm section code
#endif

/*
* FUNCTION                                                            
*	pmic_charge_current_offset
*
* DESCRIPTION                                                           
*  Configure charging current offser
*
* CALLS  
*	It is called by BMT task
*
* PARAMETERS
*	offset: current offset (0~7)
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/     
void pmic_charge_current_offset(kal_uint8 offset)
{
   kal_uint32 savedMask;
   kal_uint8 data;
   
   offset&=0x07;
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_CTRL2>>PMIC_SHIFT_BITS)];
   data&=0xf8;
   data|=offset;
   B2PSI_write_fast(data, PMIC_CHARGER_CTRL2);    
   RESTOREIRQMASK(savedMask);
} 

void pmic_clear_ov(void)
{
   kal_uint32 savedMask;
   kal_uint8 data;
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_CTRL2>>PMIC_SHIFT_BITS)];
   data&=~0x8;
   B2PSI_write_fast(data, PMIC_CHARGER_CTRL2);    
   RESTOREIRQMASK(savedMask);
}   

/*
* FUNCTION                                                            
*	pmic_vibrator_enable
*
* DESCRIPTION                                                           
*  Turn on or turn off Vibrator 
*
* CALLS  
*	It is called by UEM
*
* PARAMETERS
*	enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/  
void pmic_vibrator_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
   if(enable==KAL_TRUE)
   {
      data|=VIBRATOR_ON;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~VIBRATOR_ON;
   }            
   B2PSI_write_fast(data, PMIC_MISC);    
   RESTOREIRQMASK(savedMask);      
} 
/*
* FUNCTION                                                            
*	pmic_speker_enable
*
* DESCRIPTION                                                           
*  Turn on or turn off speaker amp
*
* CALLS  
*	It is called by audio driver
*
* PARAMETERS
*	enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/  
void pmic_speaker_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   /*audio invoke this in LISR, dont disable interrupt*/
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
   if(enable==KAL_TRUE)
   {
      data|=SPEAKER_ON;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~SPEAKER_ON;
   }            
   //L1D_MeasureMaxDuration_Start( &pmic_duration );
   B2PSI_write_fast(data, PMIC_MISC);          
   //L1D_MeasureMaxDuration_Stop( &pmic_duration );
   RESTOREIRQMASK(savedMask);
}   
/*
* FUNCTION                                                            
*	pmic_vsim_sel
*
* DESCRIPTION                                                           
*  Adjust vsim voltage source
*
* CALLS  
*	Adjust vsim voltage source
*
* PARAMETERS
*	vol: sim voltage source
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
/*VIM 1.8V/3.0V sel*/
void pmic_vsim_sel(sim_vol vol)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];

   if(vol==VSIM_3)        
   {
      data|=VSIM_SEL_3;   
   }   
   else if(vol==VSIM_1_8)
   {
      data&=~VSIM_SEL_3;/*1.8V*/
   }            
   B2PSI_write_fast(data, PMIC_MISC);  
   RESTOREIRQMASK(savedMask);        
}
/*
* FUNCTION                                                            
*	pmic_vmc_enable
*
* DESCRIPTION                                                           
*  Turn on or turn off VM LDO
*
* CALLS  
*	It is called by MSDC driver
*
* PARAMETERS
*	enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_vmc_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
    savedMask = SAVEANDSETIRQMASK();
    data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
   
   if(enable==KAL_TRUE)
   {
      data|=VMC_ON;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~VMC_ON;
   }            
   B2PSI_write_fast(data, PMIC_MISC);          
   RESTOREIRQMASK(savedMask); 
}
void pmic_vmc_sel(vmc_sel_enum sel)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();   
   
   data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];   
      
   if(sel==VMC_3V)
   {
      data|=VMC_SEL_MASK;   
   }   
   else if(sel==VMC_2_8V)
   {
      data&=~VMC_SEL_MASK;
   }            
   B2PSI_write_fast(data, PMIC_EXTRAS);          
   RESTOREIRQMASK(savedMask); 
}

/*
* FUNCTION                                                            
*	pmic_vb_sel
*
* DESCRIPTION                                                           
*  Adjust vd voltage source
*
* CALLS  
*	
*
* PARAMETERS
*	sel: vd voltage source selection
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
/*the same as VASEL*/
void pmic_vb_sel(vb_vol sel)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];

   if(sel==VB_VTCXO)
   {
      data|=VASEL_VTCXO;/*sleep mode*/   
   }   
   else if(sel==VB_VD)
   {
      data&=~VASEL_VTCXO;/*normal mode*/
   }            
   B2PSI_write_fast(data, PMIC_MISC);
   RESTOREIRQMASK(savedMask);           
}     

/*
* FUNCTION                                                            
*	pmic_vd_sel
*
* DESCRIPTION                                                           
*  Adjust vd voltage source
*
* CALLS  
*	
*
* PARAMETERS
*	sel: vd voltage source selection
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_vd_sel(vd_sel sel)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
   
   if(sel==VD_0_9)
   {
      data|=VD_0_9V;/*sleep mode*/   
   }   
   else if(sel==VD_NORMAL)
   {
      data&=~VD_0_9V;/*normal mode*/
   }            
   B2PSI_write_fast(data, PMIC_MISC);
   RESTOREIRQMASK(savedMask);          
}     
  /*
* FUNCTION                                                            
*	pmic_vasw_enable
*
* DESCRIPTION                                                           
*  Turn on or Turn off VASW LDO
*
* CALLS  
*	It is called by external module that uses VASW LDO
*
* PARAMETERS
*	enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/   

void pmic_vasw_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
   
   if(enable==KAL_TRUE)
   {
      data|=VASW_ON;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~VASW_ON;
   }            
   B2PSI_write_fast(data, PMIC_MISC); 
   RESTOREIRQMASK(savedMask);          
}
/*
* FUNCTION                                                            
*	pmic_chr_pump_enable
*
* DESCRIPTION                                                           
*  Turn on or turn off charge pump
*
* CALLS  
*	It is called by PMIC6318 driver
*
* PARAMETERS
*	enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
/*chr_pump on/off*/
void pmic_chr_pump_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];
   
   if(enable==KAL_TRUE)
   {
      data|=CHR_PUMP_ON;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~CHR_PUMP_ON;
   }            
   B2PSI_write_fast(data, PMIC_MISC);
   RESTOREIRQMASK(savedMask);          
}


/*
* FUNCTION                                                            
*	pmic_chr_enable
*
* DESCRIPTION                                                           
*   start or pause charging process
*
* CALLS  
*	It is called by BMT task 
*
* PARAMETERS
*	enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
/*charge control*/
void pmic_chr_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];

   if(enable==KAL_TRUE)
   {
      data|=CHR_ON;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~CHR_ON;/*pause mode*/
   }                 
   B2PSI_write_fast(data, PMIC_CHARGER_SPEAKER_CTRL); 
   RESTOREIRQMASK(savedMask);
}
void pmic_usb_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];

   if(enable==KAL_TRUE)
   {
      data|=CHR_ON;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~CHR_ON;/*pause mode*/
   }                 
   B2PSI_write_fast(data, PMIC_CHARGER_SPEAKER_CTRL); 
   RESTOREIRQMASK(savedMask);
}
/*
* FUNCTION                                                            
*	pmic_speaker_gain
*
* DESCRIPTION                                                           
*  adjust audio amplifier gain
*
* CALLS  
*	It is called by audio driver
*
* PARAMETERS
*	gain: audio amplifier gain
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_speaker_gain(kal_uint8 gain)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   if(gain>=MAX_SPK_GAIN)
      gain=MAX_SPK_GAIN;   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];
   gain=gain/3;
   gain=(gain<<SPK_GAIN_SHIFT);
   data&=~SPK_GAIN_MASK;   
   data|= gain;   
   B2PSI_write_fast(data, PMIC_CHARGER_SPEAKER_CTRL); 
   RESTOREIRQMASK(savedMask);
} 
/*
* FUNCTION                                                            
*	pmic_usb_regulator_enable
*
* DESCRIPTION                                                           
*   	turn on or turn off USB LDO
*
* CALLS  
*	It is called by USB task
*
* PARAMETERS
*	enable: on or off
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/      
/*usb regulator on/off*/
void pmic_usb_regulator_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];
      
   if(enable==KAL_TRUE) 
   {
      data|=USB_PWR_ON;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~USB_PWR_ON;
   }            
   B2PSI_write_fast(data, PMIC_CHARGER_SPEAKER_CTRL); 
   RESTOREIRQMASK(savedMask);     
} 
/*
* FUNCTION                                                            
*	pmic_ac_currnet_ctrl
*
* DESCRIPTION                                                           
*   adjust usb charging current
*
* CALLS  
*	It is called by BMT task
*
* PARAMETERS
*	current: AC charging current
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/  
/*ac current control*/
void pmic_ac_currnet_ctrl(ac_current current)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];

   data&=~AC_CURRENT_MASK;
   data|=current;
   B2PSI_write_fast(data, PMIC_CHARGER_SPEAKER_CTRL);    
   RESTOREIRQMASK(savedMask);     
}
void pmic_charging_currnet_ctrl(pmic_charging_current current)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];

   data&=~CHR_CURRENT_MASK;
   data|=current;
   B2PSI_write_fast(data, PMIC_CHARGER_SPEAKER_CTRL);    
   RESTOREIRQMASK(savedMask);     
}
/*
* FUNCTION                                                            
*	pmic_usb_current_ctrl
*
* DESCRIPTION                                                           
*  adjust usb charging current  	
*
* CALLS  
*	It is called by BMT task
*
* PARAMETERS
*	current: usb charging current(90 or 450mA)
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

void pmic_usb_current_ctrl(usb_current current)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGER_SPEAKER_CTRL>>PMIC_SHIFT_BITS)];   
   data&=~USB_CURRENT_MASK;
   data|=current;
   B2PSI_write_fast(data, PMIC_CHARGER_SPEAKER_CTRL);         
   RESTOREIRQMASK(savedMask);     
}       


void pmic_charge_pump_init(kal_uint8 value)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGE_PUMP>>PMIC_SHIFT_BITS)];   
   value&=0x1f;   
   data&=~0xf8;
   data|=(value<<3);
   B2PSI_write_fast(data, PMIC_CHARGE_PUMP);         
   RESTOREIRQMASK(savedMask);     
}       
/*
* FUNCTION                                                            
*	pmic_ldo_status
*
* DESCRIPTION                                                           
*   	Report currnt LDO status
*
* CALLS  
*	It is called to get current LDO status
*
* PARAMETERS
*	ldo: LDO type
*	
* RETURNS
*	LDO status
*
* GLOBALS AFFECTED
*   external_global
*/
/*LDO status */
kal_uint8 pmic_ldo_status(pmic_ldo ldo)
{
   kal_uint8 data;
   data=B2PSI_read(PMIC_LDO_STAT);   
   
   switch(ldo)
   {
      case VSIM_LDO:
         return (data&LDO_VSIM_MASK);
         break;             
      case VTCXO_LDO:
         return(data&LDO_VTCXO_MASK);
         break;
      case VRTC_LDO:
         return(data&LDO_VRTC_MASK);
         break;         
      case VM_LDO:
         return(data&LDO_VM_MASK);
         break;
      case VA_LDO:
         return(data&LDO_VA_MASK);
         break;
      case VD_LDO:
         return(data&LDO_VD_MASK);
         break;   
      default:
         return(0);
         break;
   }
}      
/*
* FUNCTION                                                            
*	pmic_chr_status
*
* DESCRIPTION                                                           
*   	Read charging control status
*
* CALLS  
*	
*
* PARAMETERS
*	status: status user wants to know
*	
* RETURNS
*	current charging status
*
* GLOBALS AFFECTED
*   external_global
*/
/*charger status, not export to others */
kal_uint8 pmic_chr_status(pmic_chr_stat status)
{
   kal_uint8 data=0, result=0;   
   data=pmic_reg_save[PMIC_CHARGER_STAT];      
   switch(status)
   {
      case CHR_STAT_OV:
         return ((data&OV_MASK)>>7);
         break;             
      case CHR_STAT_CHRDET:
         return((data&CHRDET_MASK)>>6);
         break;
      case CHR_STAT_BAT_ON:
         if(((data&BAT_ON_MASK)>>5))
            result=0;
         else
            result=1;     
         return result;         
         break;
      case CHR_STAT_AC_DET:
         return((data&AC_DET_MASK)>>4);
         break;
      case CHR_STAT_USB_DET:
         return((data&USB_DET_MASK)>>3);
         break;                           
      case CHR_STAT_CV:
         data=B2PSI_read(PMIC_CHARGER_STAT);
         return((data&CV_STATUS_MASK)>>1);
         break;
      case CHR_STAT_CHRG_DIS:
         data=B2PSI_read(PMIC_CHARGER_STAT);
         if(data&CHR_STATUS_MASK)
            result=0;
         else
            result=1;   
         return result;  
      default:
         return(0);
         break;
   }
   
}
/*
* FUNCTION                                                            
*	pmic_write_to_register_save
*
* DESCRIPTION                                                           
*  write data to pmic_register_save
*
* CALLS  
*	It is called by B2PSI to write data to pmic_register_save
*
* PARAMETERS
*	None
*	
* RETURNS
*	data: data that be written
*  register_index: register index  
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_write_to_register_save(kal_uint8 data, kal_uint16 register_index)
{
   pmic_reg_save[(register_index>>PMIC_SHIFT_BITS)]=data;     
}   
/*
* FUNCTION                                                            
*	pmic_is_chr_det
*
* DESCRIPTION                                                           
*   	to check if AC or USB is plug-in
*
* CALLS  
*	It is called by PWIC
*
* PARAMETERS
*	type: charger type(USB or AC)
*
* RETURNS
*	AC or USB exists or not 
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool pmic_is_chr_det(chr_type type)
{
   kal_bool status=0;
   switch(type)
   {
      case AC_CHR: 
         status=pmic_chr_status(CHR_STAT_AC_DET);      
         break;
      case USB_CHR: 
         status=pmic_chr_status(CHR_STAT_USB_DET);   
         break;
      default:
         ASSERT(0);
         break;   
   }       
   if(status==0)
      return KAL_FALSE;
   else
      return KAL_TRUE;         
   
}


/*
* FUNCTION                                                            
*	pmic_is_chr_valid
*
* DESCRIPTION                                                           
*   	to check if AC or USB charger is valid 
*
* CALLS  
*	It is called by BMT
*
* PARAMETERS
*  None
*
* RETURNS
*	AC or USB is valid or not 
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool pmic_is_chr_valid(void)
{
   kal_bool status;
   status=pmic_chr_status(CHR_STAT_CHRDET);      
   
   return(status);      
}
/*
* FUNCTION                                                            
*	PMIC_ChrDet_Registration
*
* DESCRIPTION                                                           
*   	Charger detecion register fucntion
*
* CALLS  
*	It is called by USB and BMT to register their detection handler 
*
* PARAMETERS
*	type: charger type(USB or AC)
*  Callback: detection handler	
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void PMIC_ChrDet_Registration(chr_type type, void (*Callback)(void))
{
   if(type==AC_CHR)
   {
      PMIC_CHRDET.pmic_ac_det=Callback;
   }
   else if (type==USB_CHR)
   {
      PMIC_CHRDET.pmic_usb_det=Callback;
   }
   else
      ASSERT(0);      

}
/*
* FUNCTION                                                            
*	pmic_pump_delay
*
* DESCRIPTION                                                           
*  charge pump delay selection
*
* CALLS  
*  used to charge pump delay selection
*
* PARAMETERS
*	delay: pump delay
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_pump_delay(charge_pumpdelay_enum delay)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   
   savedMask = SAVEANDSETIRQMASK();   
   data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];      
   data&=~0x3;
   data|=delay;
   B2PSI_write_fast(data, PMIC_EXTRAS);         
   RESTOREIRQMASK(savedMask);   
}   
/*
* FUNCTION                                                            
*	pmic_sim_leveltype
*
* DESCRIPTION                                                           
*   SIM circuit selection
*
* CALLS  
*  used to change SIM circuit
*
* PARAMETERS
*	enable: KAL_TRUE : type 1
           KAL_FALSE : type 0
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_sim_leveltype(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   savedMask = SAVEANDSETIRQMASK();   
   data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];      
   if(enable==KAL_TRUE)
      data|=0x4;
   else
      data&=~0x4;
   B2PSI_write_fast(data, PMIC_EXTRAS);         
   RESTOREIRQMASK(savedMask);      
}
/*
* FUNCTION                                                            
*	pmic_sw_sel
*
* DESCRIPTION                                                           
*   auxiliary analog output voltage selection
*
* CALLS  
*  used to change auxiliary analog output voltage
*
* PARAMETERS
*	value:VASW_3_3V or VASW_2_8V
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_sw_sel(vasw_a_sel_enum value)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   savedMask = SAVEANDSETIRQMASK();   
   data=pmic_reg_save[(PMIC_EXTRAS>>PMIC_SHIFT_BITS)];      
   if(value==VASW_2_8V)
      data&=~0x80;
   else if(value==VASW_3_3V)      
      data|=0x80;
   else
      ASSERT(0);   
   B2PSI_write_fast(data, PMIC_EXTRAS);         
   RESTOREIRQMASK(savedMask);         
}   
/*
* FUNCTION                                                            
*	pmic_vibrator_sel
*
* DESCRIPTION                                                           
*  vibrator voltage selection
*
* CALLS  
*  used to change vibrator voltage
*
* PARAMETERS
*	value:VIBRATOR_1_8V or VIBRATOR_3_2V
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_vibrator_sel(vibrator_sel_enum value)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   savedMask = SAVEANDSETIRQMASK();   
   data=pmic_reg_save[(PMIC_CHARGE_PUMP>>PMIC_SHIFT_BITS)];      
   if(value==VIBRATOR_1_8V)
      data&=~0x2;
   else if(value==VIBRATOR_3_2V)      
      data|=0x2;
   else
      ASSERT(0);      
   B2PSI_write_fast(data, PMIC_CHARGE_PUMP);         
   RESTOREIRQMASK(savedMask);         
   
}  
/*
* FUNCTION                                                            
*	pmic_chr_pump_current_level
*
* DESCRIPTION                                                           
*  configure charge pump current
*
* CALLS  
*  used to change vibrator voltage
*
* PARAMETERS
*	current level 0~3
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_chr_pump_current_level(kal_uint32 level)
{
   kal_uint8 data;
   kal_uint32 savedMask;
   savedMask = SAVEANDSETIRQMASK();   
   data=pmic_reg_save[(PMIC_CHARGE_PUMP>>PMIC_SHIFT_BITS)];      
   if (level>3)
   	level=3;
   data&=~(3<<5);
   data|=(level<<5);	
   
   B2PSI_write_fast(data, PMIC_CHARGE_PUMP);         
   RESTOREIRQMASK(savedMask);         
   
}
/*
* FUNCTION                                                            
*	pmic_usb_chr_enable
*
* DESCRIPTION                                                           
*   	USB charging enable/disable
*
* CALLS  
*   	USB charging enable/disable
*
* PARAMETERS
*	enable: KAL_TRUE or KAL_FALSE
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_usb_chr_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_CHARGE_PUMP>>PMIC_SHIFT_BITS)];

   if(enable==KAL_TRUE)
   {
      data|=0x1;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~0x1;/*pause mode*/
   }                 
   B2PSI_write_fast(data, PMIC_CHARGE_PUMP); 
   RESTOREIRQMASK(savedMask);
}

/*
* FUNCTION                                                            
*	pmic_set_UV_vol
*
* DESCRIPTION                                                           
*   	set UV voltage
*
* CALLS  
*   	
*
* PARAMETERS
*	enable: KAL_TRUE or KAL_FALSE
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_set_UV_vol(UV_voltage_enum voltage)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_BANDGAP_SETTING>>PMIC_SHIFT_BITS)];

   data&=0xf3;/*clear original setting*/
   data|=voltage;
   
   B2PSI_write_fast(data, PMIC_BANDGAP_SETTING); 
   RESTOREIRQMASK(savedMask);
}

/*
* FUNCTION                                                            
*	pmic_power_save_enable
*
* DESCRIPTION                                                           
*   	enable power save or not
*
* CALLS  
*   	
*
* PARAMETERS
*	enable: KAL_TRUE or KAL_FALSE
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_power_save_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_MISC>>PMIC_SHIFT_BITS)];

   if(enable==KAL_TRUE)
   {
      data|=0x20;   
   }   
   else if(enable==KAL_FALSE)
   {
      data&=~0x20;/*pause mode*/
   }                 
   B2PSI_write_fast(data, PMIC_MISC); 
   RESTOREIRQMASK(savedMask);
}


/*
* FUNCTION                                                            
*	pmic_audio_diffential_enable
*
* DESCRIPTION                                                           
*   	enable differential mode or not
*
* CALLS  
*   	
*
* PARAMETERS
*	enable: KAL_TRUE or KAL_FALSE
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void pmic_audio_diffential_enable(kal_bool enable)
{
   kal_uint8 data;
   kal_uint32 savedMask;

   savedMask = SAVEANDSETIRQMASK();
   data=pmic_reg_save[(PMIC_LDO_STAT>>PMIC_SHIFT_BITS)];

   if(enable==KAL_FALSE)
   {
      data|=0x2;   
   }   
   else if(enable==KAL_TRUE)
   {
      data&=~0x2;
   }                 
   B2PSI_write_fast(data, PMIC_LDO_STAT); 
   RESTOREIRQMASK(savedMask);
}

/*
* FUNCTION                                                            
*	PMIC_HISR
*
* DESCRIPTION                                                           
*   	PMIC6318 HISR
*
* CALLS  
*	It is called by EINT_LISR to handle interrupt
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
void PMIC_HISR(void)
{
	kal_uint8 status, diff;
	static kal_uint8 intcount=0; 
	kal_uint32 savedMask;
#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(__FUE__)
   kal_bool unmask_eint = KAL_TRUE;
   extern chr_usb_detect_struct chr_usb_detect;
#endif
   
	intcount++;
	savedMask = SAVEANDSETIRQMASK();
   status = B2PSI_read(PMIC_CHARGER_STAT);
   RESTOREIRQMASK(savedMask);   
   /*compare the difference with the previous status*/
   diff=pmic_reg_save[PMIC_CHARGER_STAT]^status;
   /*save the current status*/
   pmic_reg_save[PMIC_CHARGER_STAT]=status;
	if (diff & OV_MASK)
	{		  
	   pmic_clear_ov();
	}	
	if (diff & BAT_ON_MASK)
	{	   
	}
	if (diff & AC_DET_MASK)
	{	
		#if 0			      			   	   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	   #endif 	      	        	   
	   /*plug in */	   
	   if(PMIC_CHRDET.pmic_ac_det!=NULL) 
      {
	      PMIC_CHRDET.pmic_ac_det();	     	       
#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(__FUE__)
         unmask_eint = KAL_FALSE;
#endif
      }
	}	
	if (diff& USB_DET_MASK)
	{		  	   
	   //dbg_print("USB det \r\n");	   
	   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	   #endif    
	   if(PMIC_CHRDET.pmic_usb_det!=NULL) 
	      PMIC_CHRDET.pmic_usb_det();	   	   	         
	}
#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(__FUE__)
   if (KAL_TRUE == unmask_eint)
	   EINT_UnMask(chr_usb_detect.chr_usb_eint);
#endif
}

/* the following are for LCD backlight PWM and for MMI. */
void pmic_pwm_level(kal_uint8 level)
{
   pmic_led_struct pmic_set;

   ASSERT(level <= 5);
   
   PMIC_PWM_LEVEL_SAVE = level;
   if ((bl_pwm_type != BL_LED) && (bl_pwm_type != KP_LED))
      return;
   if (level)
   {
      pmic_set.type=bl_pwm_type;
      pmic_set.current=0;
      pmic_set.duty_cycle=PMIC6318_PWM_Level_Info[level-1][1];
      pmic_led_config(&pmic_set);
      if (bl_pwm_type == BL_LED)
      {
         if (PMIC6318_PWM_Level_Info[level-1][0] >= 1000)
            pmic_bl_div_bypass(KAL_TRUE);
         else
            pmic_bl_div_bypass(KAL_FALSE);
         pmic_bl_dim_clk_setting(PMIC6318_PWM_Level_Info[level-1][0]);
      }
      else if (bl_pwm_type == KP_LED)
      {
         pmic_rgb_dim_clk_setting(PMIC6318_PWM_Level_Info[level-1][0]);
      }
      pmic_led_enable(bl_pwm_type, KAL_TRUE);
   }
   else
   {
      pmic_led_enable(bl_pwm_type, KAL_FALSE);
   }
}

kal_uint8 pmic_pwm_current_level(void)
{
   return PMIC_PWM_LEVEL_SAVE;
}

void pmic_pwm_configure(kal_uint32 freq, kal_uint8 duty)
{
   pmic_led_struct pmic_set;

   if ((bl_pwm_type != BL_LED) && (bl_pwm_type != KP_LED))
      return;
   if (duty > 100)
      duty = 100;
   pmic_set.type=bl_pwm_type;
   pmic_set.current=0;
   pmic_set.duty_cycle=duty;
   pmic_led_config(&pmic_set);

   if (bl_pwm_type == BL_LED)
   {
      if (freq >= 1000)
         pmic_bl_div_bypass(KAL_TRUE);
      else
         pmic_bl_div_bypass(KAL_FALSE);
      pmic_bl_dim_clk_setting(freq);
   }
   else if (bl_pwm_type == KP_LED)
   {
      pmic_rgb_dim_clk_setting(freq);
   }
}

void pmic_pwm_start(void)
{
   if ((bl_pwm_type != BL_LED) && (bl_pwm_type != KP_LED))
      return;
   pmic_led_enable(bl_pwm_type, KAL_TRUE);
}

/*the following are for PMIC test*/
#ifdef MT6318_DEBUG

void LED_clock_config(kal_uint32 count)
{
   kal_uint32 result;
   result=count%2;
   
   
}   
void LED_test(kal_uint8 currnet, kal_uint8 duty)
{
   pmic_led_struct pmic_set;  
   kal_uint8    status;    
   pmic_set.type=R_LED;
   pmic_set.current=currnet;
   pmic_set.duty_cycle=duty;      
   pmic_led_enable(R_LED, KAL_TRUE);
   pmic_led_config(&pmic_set);   
   status=B2PSI_read(PMIC_RLED_DRIVER);
   status=status&0x1f;
   status=(status+1)*100/32;
   dbg_print("R LED duty= %d\r\n",(status));
   
   pmic_set.type=G_LED;
   pmic_led_enable(G_LED, KAL_TRUE);
   pmic_led_config(&pmic_set);   
   status=B2PSI_read(PMIC_GLED_DRIVER); 
   status=status&0x1f;
   status=(status+1)*100/32;  
   dbg_print("G LED duty= %d\r\n",(status));
      
   pmic_set.type=B_LED;
   pmic_led_enable(B_LED, KAL_TRUE);
   pmic_led_config(&pmic_set);
   status=B2PSI_read(PMIC_GLED_DRIVER);   
   status=status&0x1f;
   status=(status+1)*100/32;  
   dbg_print("B LED duty= %d\r\n",(status));
   
   pmic_set.type=KP_LED;
   pmic_led_enable(KP_LED, KAL_TRUE);
   pmic_led_config(&pmic_set);
   status=B2PSI_read(PMIC_KPLED_DRIVER);
   status=status&0x1f;
   status=(status+1)*100/32;  
   dbg_print("KP LED duty= %d\r\n",(status));
   
   pmic_set.type=BL_LED;
   pmic_led_enable(BL_LED, KAL_TRUE);
   pmic_led_config(&pmic_set);
   status=B2PSI_read(PMIC_BLLED_DRIVER);    
   status=status&0x1f;
   status=(status+1)*100/32;  
   dbg_print("BL LED duty= %d\r\n",(status));   
}   
void LED_turnoff(void)
{
   pmic_led_enable(R_LED, KAL_FALSE);
   pmic_led_enable(G_LED, KAL_FALSE);
   pmic_led_enable(B_LED, KAL_FALSE);
   pmic_led_enable(KP_LED, KAL_FALSE);
   pmic_led_enable(BL_LED, KAL_FALSE);
}   
void DIM_test(kal_uint32 clk)
{
   kal_uint32 div;
   pmic_rgb_dim_clk_setting(clk);
   pmic_bl_dim_clk_setting(clk);
   div=B2PSI_read(PMIC_DIM_CLOCK);   
   div=div&0xf;
   //div=32000/(div+1);
   dbg_print("DIV= %d\r\n",div);
}   
void current_offset_test(kal_int8 current_off)
{
   kal_int8 offset;
   pmic_charge_current_offset(current_off);
   offset=B2PSI_read(PMIC_CHARGER_CTRL2);  
   offset=4*(offset-4); 
   dbg_print("offset = %d\r\n",offset);
   
}   
void spk_test(kal_uint8 gain)
{  
   kal_uint8 data;   
   //dbg_print("spk ctrl before= %d\r\n",gain);    
   pmic_speaker_gain(gain);   
   data=B2PSI_read(PMIC_CHARGER_SPEAKER_CTRL);  
   data=data&SPK_GAIN_MASK;
   data=2*(data>>4);
   dbg_print("spk ctrl after= %d\r\n",data);       
}   
void charging_current_test(pmic_charging_current current)
{
   kal_uint8 data;
   data=B2PSI_read(PMIC_CHARGER_SPEAKER_CTRL);  
   //dbg_print("ac ctrl before= %d\r\n",data); 
   //dbg_print("ac current= %d\r\n",current);    
   //pmic_ac_currnet_ctrl(current);   
   pmic_charging_currnet_ctrl(current);
   data=B2PSI_read(PMIC_CHARGER_SPEAKER_CTRL);  
   data=data&(0x7);
   //dbg_print("ac ctrl after= %d\r\n",data);    
   switch (data)
   {
      case 0:
         dbg_print("charing current 50mA\r\n");    
         break;
      case 1:
         dbg_print("charing current 90mA\r\n");    
         break;
      case 2:
         dbg_print("charing current 150mA\r\n");    
         break;
      case 3:
         dbg_print("charing current 225mA\r\n");    
         break;
       case 4:
         dbg_print("charing current 300mA\r\n");    
         break;
       case 5:
         dbg_print("charing current 450mA\r\n");    
         break;
      case 6:
         dbg_print("charing current 650mA\r\n");    
         break;
      case 7:
         dbg_print("charing current 800mA\r\n");    
         break;          
      default:
         break; 
    }                                            
}


void usb_test(kal_bool on, usb_current current)
{
   kal_uint8 data;
   pmic_usb_regulator_enable(on);
   pmic_chr_enable(on);
   pmic_usb_current_ctrl(current);      
   data=B2PSI_read(PMIC_CHARGER_SPEAKER_CTRL);
}   
      
void misc_test(kal_bool on)
{
   pmic_vasw_enable(on);   
   pmic_vd_sel(on);
   //pmic_vb_sel(on);
   pmic_usb_regulator_enable(on);
   pmic_vmc_enable(on);
   pmic_vsim_sel(on);
   pmic_speaker_enable(on);   
   pmic_vibrator_enable(on);
}  

void LDO_test(void)
{  
   kal_uint8 i;
   kal_uint8 status;
   for(i=0;i<6;i++)
   {
      status=pmic_ldo_status(i);
      status=status>>(i+2);
      switch(i)
      {
         case VSIM_LDO:
            dbg_print("VSIM_LDO=");             
            break;             
         case VTCXO_LDO:
            dbg_print("VTCXO_LDO=");             
            break;
         case VRTC_LDO:
            dbg_print("VRTC_LDO=");             
            break;         
         case VM_LDO:
            dbg_print("VM_LDO=");             
            break;
         case VA_LDO:
            dbg_print("VA_LDO=");             
            break;
         case VD_LDO:
            dbg_print("VD_LDO=");             
            break;   
         default:            
            break;
      }
      dbg_print("%d\r\n",status);                         
   }   
   
      
}  
kal_uint32 pmic_test_count=0; 
kal_uint8 duty=100;
kal_uint8  led_mode=0;
kal_uint8 spk_gain=0; 
void pmic_test(void)
{   
     
   if(pmic_test_count==0)
   {  
      B2PSI_init();  
      pmic_init(); 
      pmic_led_enable(BL_LED, KAL_TRUE);
      
      pmic_vibrator_sel(VIBRATOR_1_8V);
      pmic_vibrator_sel(VIBRATOR_3_2V);
      pmic_vibrator_sel(VIBRATOR_1_8V);
      pmic_usb_chr_enable(KAL_TRUE);
      pmic_usb_chr_enable(KAL_FALSE);
      pmic_usb_chr_enable(KAL_TRUE);
   }
   /*spk gain control*/ 
   spk_gain=2*(pmic_test_count%8);   
	spk_test(spk_gain);
	misc_test((pmic_test_count%2));			
	duty=duty-5;
	if(duty==0)
	{
	   duty=100;
	   led_mode++;
	   led_mode=led_mode%4;
	   /*current offset*/
	   current_offset_test((led_mode*4));			   			   
	   LED_turnoff();			   
	}   
	/*LED test*/
  switch(led_mode)
  {
     case 0:
        dbg_print("LED current: 24mA\r\n");
        LED_test(LED_CURRENT_24, duty);   
        DIM_test(1000);            
        break;
     case 1:
        dbg_print("LED current: 20mA\r\n");
        LED_test(LED_CURRENT_20, duty);
        DIM_test(200);            
        break;
     case 2:
        dbg_print("LED current: 16mA\r\n");
        LED_test(LED_CURRENT_16, duty);
        DIM_test(50);            
        break;
     case 3:
        dbg_print("LED current: 12mA\r\n");
        LED_test(LED_CURRENT_12, duty);
        DIM_test(1);            
        break;                              
     default:
		break;   
  }      		
	pmic_test_count++;			
	pmic_test_mode_test();
}    

void pmic_module_test(void)
{      
            
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_B2SPI,PDN_B2PSI);
   B2PSI_init();
   pmic_init();
   pmic_usb_regulator_enable(KAL_TRUE);
   pmic_usb_enable(KAL_TRUE);
   pmic_chr_pump_enable(KAL_TRUE);
   pmic_vasw_enable(KAL_TRUE);
   pmic_vmc_enable(KAL_TRUE);
   pmic_speaker_enable(KAL_TRUE);
   pmic_vibrator_enable(KAL_TRUE);
   spk_test(100);
   misc_test(KAL_TRUE);   
   pmic_vibrator_sel(VIBRATOR_1_8V);    
   pmic_usb_chr_enable(KAL_TRUE);
       
   LED_test(LED_CURRENT_24, 100); 
   B2PSI_write(0xff, 0X7000);
   B2PSI_write(0xff, 0X3000);   
   
}
#endif/*MT6318_DEBUG*/

#endif/*MT6318*/   

