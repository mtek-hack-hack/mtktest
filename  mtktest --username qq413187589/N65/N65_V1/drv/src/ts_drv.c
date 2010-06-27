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
 *    tp_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for touch screen driver
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
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#if defined(DRV_ADC_TOUCH_SCREEN) && (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING))
#include "eint.h"
//#include "touch_panel_custom.h"
#include "touch_panel.h"
//#include    "touch_panel_spi.h"
#include "drv_hisr.h"
#include "ts_hw.h"
#include "intrCtrl.h"
#include "drvpdn.h"
//#include "gpt_sw.h"
extern kal_bool    touch_panel_state;
extern const kal_int16 touch_panel_filter_thresold;
extern const kal_uint16 touch_pressure_threshold_high;
extern const kal_uint16 touch_pressure_threshold_low;

kal_hisrid ts_hisr;

static kal_uint16  ts_read_adc(kal_uint16 pos)
{
   kal_uint16  reg;

   DRV_WriteReg(DRVPDN_CON1+0x20,(kal_uint16)DRVPDN_CON1_TRC);
   reg = pos|TS_CMD_MODE_10BIT|TS_CMD_DIFFERENTIAL|TS_CMD_PD_YDRV_SH;
   DRV_WriteReg(AUX_TS_CMD, reg);
   DRV_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
   while(TS_CON_SPL_MASK & DRV_Reg(AUX_TS_CON))
   {
   }
   reg = DRV_Reg(AUX_TS_DATA0);
   DRV_WriteReg(DRVPDN_CON1+0x10,(kal_uint16)DRVPDN_CON1_TRC);
   return (reg<<2);
}

void tp_read_adc(kal_uint16 *x, kal_uint16 *y)
{
#define TOTAL_CNT    10   
   kal_uint8 retry;        
   kal_int16 temp_x=0, temp_y=0, diff_x=0, diff_y=0;
   
   for(retry=0;retry<TOTAL_CNT;retry++)
   {
      /*Y ADC*/
      *y=ts_read_adc(TS_CMD_ADDR_Y);
   
      /*X ADC*/
      *x=ts_read_adc(TS_CMD_ADDR_X);
      if(temp_x==0&&temp_y==0)
      {
         temp_x=*x;
         temp_y=*y;
      }
      else
      {
         diff_x=temp_x-*x;
         diff_y=temp_y-*y;
         if(diff_x>touch_panel_filter_thresold||diff_x<-touch_panel_filter_thresold
            ||diff_y>touch_panel_filter_thresold||diff_y<-touch_panel_filter_thresold)
         {
            temp_x=*x;
            temp_y=*y;
            *x=4095;                  
            *y=4095;            
         }
         else
         {
         	if(*x!=4095&&*y!=4095)
            	return;
         }                        
      }
   }
}

#ifdef TOUCH_PANEL_PRESSURE
kal_bool tp_pressure_check(void)
{
   
   kal_uint8 command=0, retry;        
   kal_int16 x, z1, z2;
   kal_uint32 pressure;
   
   for(retry=0;retry<1/*TOUCH_PANEL_RETRY*/;retry++)
   {
      /*X ADC*/
      x=ts_read_adc(TS_CMD_ADDR_X);
      //kal_prompt_trace(MOD_TP_TASK, "pressure x value: %d", x);

      /*Z1 ADC*/
      z1=ts_read_adc(TS_CMD_ADDR_Z1);
      //kal_prompt_trace(MOD_TP_TASK, "pressure z1 value: %d", z1);

      /*Z2 ADC*/
      z2=ts_read_adc(TS_CMD_ADDR_Z2);
      //kal_prompt_trace(MOD_TP_TASK, "pressure z2 value: %d", z2);
      if((z1 > 0) && (z2 > z1))
      {
         pressure = (x*(z2-z1)/z1) >> 2; /* Rx*x/4096*(z2/z1 - 1), assume Rx=1024 */
         //kal_prompt_trace(MOD_TP_TASK, "pressure: %d", pressure);
         //if (pressure > TOUCH_PRESSURE_THRESHOLD2)
           // kal_prompt_trace(MOD_TP_TASK, "pressure is above %d. value: %d", TOUCH_PRESSURE_THRESHOLD2, pressure);
         if ((pressure > touch_pressure_threshold_high) || (pressure <= touch_pressure_threshold_low))
            return KAL_FALSE; 
         else
            return KAL_TRUE; 
      }
   }
   //kal_prompt_trace(MOD_TP_TASK, "pressure: 0 (no value)");
   return KAL_FALSE;
}
#endif /*TOUCH_PANEL_PRESSURE*/

void tp_irq_enable(kal_bool on)
{
}    

void TS_LISR(void)
{
   IRQMask(IRQ_AUXADC_CODE);
   //kal_activate_hisr(ts_hisr);
   drv_active_hisr(DRV_AUXADC_HISR_ID);
}

void TS_HISR(void)
{
	kal_uint16 status;
//#define DRV_TP_STATIS_DELAY
#if defined(DRV_TP_STATIS_DELAY)
	kal_uint16 i;

   for (i=0;i<35000;i++);
#endif
   touch_panel_state = !touch_panel_state;
   //status = DRV_Reg(AUX_TS_CON);
   //if (status & TS_CON_STATUS_MASK)
   if (touch_panel_state==touch_down_level)/*low*/
   {
      kal_set_eg_events(TP.event,1,KAL_OR);
      /* touch screen pressed. */
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("touch down\r\n");            
      #endif
      TP.state=DOWN;
   }
   else
   {
      kal_set_eg_events(TP.event,1,KAL_OR);
      /* touch screen release. */
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("touch up\r\n");            
      #endif
      TP.state=UP;
   }
	IRQClearInt(IRQ_AUXADC_CODE);
	IRQUnmask(IRQ_AUXADC_CODE);
}

#define  TS_DEBOUNCE_TIME     (10*32)  //10ms
void ts_drv_init(void)
{
   kal_uint16  x;
   if (ts_hisr == NULL)
   {
      //ts_hisr = kal_create_hisr("TS_HISR",2,512,TS_HISR,NULL);
      ts_hisr=(void*)0x1234;
      DRV_Register_HISR(DRV_AUXADC_HISR_ID, TS_HISR);
   }
   DRV_WriteReg(AUX_TS_DEBT, TS_DEBOUNCE_TIME);
   //DRV_WriteReg(AUX_TS_CMD, TS_CMD_PD_IRQ_SH);
   IRQ_Register_LISR(IRQ_AUXADC_CODE, TS_LISR,"TS Handler");
   IRQSensitivity(IRQ_AUXADC_CODE,EDGE_SENSITIVE);
   IRQUnmask(IRQ_AUXADC_CODE);
   x=ts_read_adc(TS_CMD_ADDR_X);
   x = DRV_Reg(AUX_TS_CON);
   if (x & TS_CON_STATUS_MASK)
      touch_panel_state=touch_down_level;
   else
      touch_panel_state=touch_up_level;
}

#if defined(DRV_TP_NO_EXT_EINT)
void ts_mask_int(void)
{
   IRQMask(IRQ_AUXADC_CODE);
}

void ts_unmask_int(void)
{
   IRQUnmask(IRQ_AUXADC_CODE);
}
#endif


#endif