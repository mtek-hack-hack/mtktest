/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005-2007
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
 *   lcd_if.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   LCD interface between upper application layer and driver
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * optimize lcd_dma_slow_down() and lcd_dma_recover()
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Add LCD driver feature: background color and memory output
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Remove unnecessary include files.
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * deprecate lcd_power_[up|down], use lcd_power_ctrl instead.
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Also phase out 6218B/6218.
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "gpt_sw.h"
#include "intrCtrl.h"
#include "lcd_sw_inc.h"
#include "lcd_hw.h"
#include "lcd_sw.h"
#include "lcd_if.h"
#include "visual_comm.h"
#include "drv_hisr.h"
#include "eint.h"

#ifndef __FUE__

/// for external camera
#if defined(CAMERA_MODULE)
   #include "ext_camera.h"
   #include "cam_module.h"
#endif

   #include "img_comm.h"
#if defined(DRV_IDP_SUPPORT)
   #include "imgproc.h"
   #include "imgdma.h"
   #if (defined(ISP_SUPPORT))
      #include "isp_if.h"
   #endif
   #if (defined(TV_OUT_SUPPORT))
      #include "tv_out.h"
      #include "2d_engine.h"
   #endif
#endif


#include "msdc_def.h"
#include "sd_def.h"
#include "msdc_lsd.h"


extern void LCD_FunConfig(void);
extern void init_lcd_interface(void);
#ifdef MTK_SLEEP_ENABLE
   #include "l1sm_public.h"
   kal_uint8   lcd_sleep_mode_handler=0xff;
#endif



LCD_Funcs  *MainLCD;
LCD_Funcs  *SubLCD;

volatile kal_uint8 current_update_lcd = MAIN_LCD;
volatile LCD_OPERATION_STATE_ENUM main_lcd_operation_state = LCD_IDLE_STATE;
/// video editor
volatile LCD_OPERATION_STATE_ENUM temp_main_lcd_operation_state = LCD_IDLE_STATE;
lcd_frame_update_struct main_lcd_fb_update_para;
volatile LCD_OPERATION_STATE_ENUM sub_lcd_operation_state = LCD_IDLE_STATE;
lcd_frame_update_struct sub_lcd_fb_update_para;

#ifdef __SYNC_LCM_SW_SUPPORT__
   kal_uint8 sync_lcm_channel_number;
   kal_bool sync_lcm_enable_mode=KAL_FALSE;
   kal_bool sync_lcm_signal_polarity;
   kal_bool current_sync_lcm_polarity;
   kal_timerid sync_lcm_timer_handle = 0;
   kal_uint8 sync_lcm_hw_update_layer_rotate_value;
   extern kal_uint32 drv_get_current_time(void);
   extern void custom_sync_lcm_eint_setting(kal_bool *sync_signal_polarity);
#endif

kal_uint8 lcd_dc_color_mode;
kal_uint8 lcd_rotate_value = 0;
kal_uint8 lcd_hard_trigger_flag = 0;
kal_uint32 current_lcd_hw_update_layer = 0;
kal_bool lcd_window_swap_flag = KAL_FALSE;
kal_bool bLCDBufferInINTRAM = KAL_FALSE;
kal_uint32 lcd_roi_ctrl_shadow,lcd_roi_size_shadow,lcd_roi_offset_shadow;
kal_uint32 lcd_mem_out_address_shadow,lcd_mem_out_address_shadow1, lcd_mem_out_ctrl_shadow;
kal_uint32 lcd_frame_buffer_address;
static kal_uint8 lcd_event_timer_handle;

/// HPI interface control
kal_uint16 old_lcd_cmd_period_count;
kal_uint16 hpi_cmd_period_count;
kal_bool hpi_power_on=KAL_FALSE;
kal_bool lcd_is_changing_roi=KAL_FALSE;
kal_bool lcd_wait_cmd_event=KAL_FALSE;

typedef struct
{
   kal_uint32   power_handle;
   kal_uint8    handle_count;
   
}  Lcd_PowerHandle_struct;
Lcd_PowerHandle_struct lcd_pwr_data;

#if ((!defined(MT6205B))&&(!defined(MT6208)))
   kal_uint8 jpeg_video_play_lcd_id = MAIN_LCD;
   volatile kal_uint8 lcd_transfer_complete = KAL_FALSE;
   kal_eventgrpid lcd_event_id;
   static lcd_layer_struct lcd_layer_data[LCD_TOTAL_LAYER];
   kal_uint16 lcd_cmd_period_count;

   kal_uint8 lcd_output_mode = KAL_TRUE;
   kal_uint8 main_lcd_hw_trigger_output_mode = KAL_TRUE;
   kal_uint8 sub_lcd_hw_trigger_output_mode = KAL_TRUE;
   kal_bool bWaitForLCDUpdate = KAL_FALSE;
   void (*lcd_prev_run_block_cb) (void) = NULL;
   #if defined(DRV_IDP_SUPPORT)||defined(DRV_LCD_FW_UPDATE_SUPPORT)
      volatile kal_bool lcd_cmd_latch_complete=KAL_FALSE;
      kal_uint32 lcd_hw_trigger_roi_offset,lcd_hw_trigger_roi_size,lcd_hw_trigger_roi_ctrl;
      kal_uint32 lcd_hw_trigger_layer;
      volatile kal_uint8 lcd_hw_trigger_flag=KAL_FALSE;
      kal_uint32 lcd_hw_trigger_para[LCD_CMD_QUEUE_LENGTH];
      kal_uint8 current_lcd_rotate_value=LCD_LAYER_ROTATE_NORMAL;
      kal_uint8 lcd_sleeping_state=KAL_FALSE;
      #ifdef TV_OUT_SUPPORT         
         kal_uint32 lcd_hw_trigger_reg=0;
         kal_uint32 lcd_roi_size_reg=0;
         kal_uint32 lcd_ctrl_reg=0;
         kal_uint32 lcd_cmq_para[LCD_CMD_QUEUE_LENGTH];
         kal_uint8 tv_output_buffer_count=0xFF;
         volatile kal_uint8 tv_full_screen=0;
         kal_uint32 tv_output_buffer_base_address1;
         kal_uint32 tv_output_buffer_base_address2;
         kal_uint32 tv_output_buffer_offset_address1;
         kal_uint32 tv_output_buffer_offset_address2;
         kal_uint8 tv_output_buffer_rotate=0;
      #endif
   #endif
#endif



#ifdef __LCD_ESD_RECOVERY__
/**
 * Check whether LCM is corrupted by ESD.
 *
 * @param None.
 *
 * @return KAL_FALSE, if ESD happens. KAL_TRUE, otherwise.
 */

kal_bool lcd_ESD_check(void)
{
   kal_bool ESD_check_result;

   #if (defined(CAMERA_MODULE))
      /// if external camera is running, do not disturb it
      if (ext_cam_is_running())
      {
         kal_prompt_trace(MOD_ENG, "LCD_ESD external camera running");
         return KAL_TRUE;
      }
   #endif

   #ifndef DUAL_LCD
      if (LCD_STANDBY_STATE == main_lcd_operation_state) {
         lcd_power_ctrl(KAL_TRUE);         
         LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/            
         ESD_check_result = MainLCD->CheckESD();         
         LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/            
         lcd_power_ctrl(KAL_FALSE);
         if (ESD_check_result == KAL_FALSE) {
            main_lcd_operation_state = LCD_IDLE_STATE;//force to do the cool reset
         }
         return ESD_check_result;
      } else {
         /// LCD is not running in the STANDBY_STATE, avoid to disturb the LCD work
         return KAL_TRUE;
      }
   #else
      if ((LCD_STANDBY_STATE == main_lcd_operation_state) &&
          (LCD_STANDBY_STATE == sub_lcd_operation_state)) {

         kal_prompt_trace(MOD_ENG, "LCD_ESD LCD state hit, both main/sub in standby state");

         lcd_power_ctrl(KAL_TRUE);         
         LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/            
         ESD_check_result = MainLCD->CheckESD();         
         LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/            
         if (ESD_check_result == KAL_FALSE) {
            lcd_power_ctrl(KAL_FALSE);
            /// force to do the cool reset
            main_lcd_operation_state=LCD_IDLE_STATE;
            sub_lcd_operation_state=LCD_IDLE_STATE;
            return KAL_FALSE;
         }

         ESD_check_result = SubLCD->CheckESD();
         if (ESD_check_result == KAL_FALSE) {
            lcd_power_ctrl(KAL_FALSE);
            /// force to do the cool reset
            main_lcd_operation_state=LCD_IDLE_STATE;
            sub_lcd_operation_state=LCD_IDLE_STATE;
            return KAL_FALSE;
         }

         lcd_power_ctrl(KAL_FALSE);
         return KAL_TRUE;
      } else {
         /// LCD is not running in the STANDBY_STATE, avoid to disturb the LCD work
         kal_prompt_trace(MOD_ENG, "LCD_ESD LCD state miss main %d sub %d", main_lcd_operation_state,sub_lcd_operation_state);
         return KAL_TRUE;
      }
   #endif /* DUAL_LCD */
}
#endif /* __LCD_ESD_RECOVERY__ */



/**
 * Get the status of LCD interface.
 *
 * Not support 6205B/6208.
 *
 * @param None.
 *
 * @return KAL_TRUE, if LCD interface is busy. KAL_FALSE, otherwise.
 */
kal_bool lcd_is_busy(void)
{
   #if ((!defined(MT6205B)) && (!defined(MT6208)))
      if ((LCD_IS_RUNNING)||(KAL_TRUE == lcd_is_changing_roi)) {
         return KAL_TRUE;
      } else {
         return KAL_FALSE;
      }
   #else
      ASSERT(KAL_FALSE);
      return KAL_TRUE;
   #endif
}

static void lcd_turn_on_clock_l1d(void)
{
   /// Turn on LCD clock
   DRV_Reg(DRVPDN_CON1_CLR) = DRVPDN_CON1_LCD;   
}

static void lcd_turn_off_clock_l1d(void)
{   
   volatile kal_uint8 i;
   kal_uint16 temp_reg;
   
   #if ((!defined(MT6205B))&&(!defined(MT6208)))
      if (KAL_FALSE == bWaitForLCDUpdate) {
         STOP_LCD_TRANSFER;
      }
   #endif   
   #ifndef DUAL_LCD
      if (((LCD_STANDBY_STATE == main_lcd_operation_state)||
           (LCD_SLEEP_STATE == main_lcd_operation_state))&&
           (KAL_FALSE == hpi_power_on)&&
           (0==lcd_pwr_data.power_handle)
           ) {
         /// make sure there is no interrupt before turning off LCD clock
         temp_reg=DRV_Reg(LCD_INT_STATUS_REG);

         /// Turn off LCD clock
         DRV_Reg(DRVPDN_CON1_SET) = DRVPDN_CON1_LCD;
         
      }
   #else
      if ((((LCD_STANDBY_STATE == main_lcd_operation_state)||
            (LCD_SLEEP_STATE == main_lcd_operation_state))&&
           ((LCD_STANDBY_STATE == sub_lcd_operation_state)||
            (LCD_SLEEP_STATE == sub_lcd_operation_state)))&&
           (KAL_FALSE == hpi_power_on)&&
           (0==lcd_pwr_data.power_handle)) {
         /// make sure there is no interrupt before turning off LCD clock
         temp_reg=DRV_Reg(LCD_INT_STATUS_REG);

         /// Turn off LCD clock
         DRV_Reg(DRVPDN_CON1_SET) = DRVPDN_CON1_LCD;
         
      }
   #endif   
}  /* lcd_turn_off_clock_l1d() */


static void lcd_turn_on_clock(void)
{
   /// Turn on LCD clock
   DRV_Reg(DRVPDN_CON1_CLR) = DRVPDN_CON1_LCD;

   #ifdef MTK_SLEEP_ENABLE
      ASSERT(lcd_sleep_mode_handler!=0xff);
      L1SM_SleepDisable(lcd_sleep_mode_handler);
   #endif
}



static void lcd_turn_off_clock(void)
{
   kal_uint32 save_irq_mask;
   volatile kal_uint8 i;
   kal_uint16 temp_reg;

   #if defined(DRV_IDP_SUPPORT)||defined(DRV_LCD_FW_UPDATE_SUPPORT)
      #ifndef DUAL_LCD
         if ((LCD_SW_UPDATE_STATE == main_lcd_operation_state)||(LCD_FW_UPDATE_STATE == main_lcd_operation_state)
           ||(LCD_FW_CMD_QUEUE_STATE == main_lcd_operation_state)) {
            return;
         }

         #if defined(DRV_IDP_SUPPORT)
            if ((main_lcd_operation_state!=LCD_HW_UPDATE_STATE)&& (main_lcd_operation_state!=LCD_DC_UPDATE_STATE)) {
               lcd_busy_waiting();
               for (i=0;i<10;i++);
            }
         #endif
      #else
         if ((LCD_SW_UPDATE_STATE == main_lcd_operation_state)||(LCD_SW_UPDATE_STATE == sub_lcd_operation_state)||
             (LCD_FW_UPDATE_STATE == main_lcd_operation_state)||(LCD_FW_UPDATE_STATE == sub_lcd_operation_state)||
             (LCD_FW_CMD_QUEUE_STATE == main_lcd_operation_state)||(LCD_FW_CMD_QUEUE_STATE == sub_lcd_operation_state)) {
            return;
         }

         #if defined(DRV_IDP_SUPPORT)
            if ((main_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&(main_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                (sub_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&(sub_lcd_operation_state!=LCD_DC_UPDATE_STATE)) {
               lcd_busy_waiting();
               for (i=0;i<10;i++);
            }
         #endif
      #endif
   #endif
   #if ((!defined(MT6205B))&&(!defined(MT6208)))
      if (KAL_FALSE == bWaitForLCDUpdate) {
         STOP_LCD_TRANSFER;
      }
   #endif
   save_irq_mask=SaveAndSetIRQMask();
   #ifndef DUAL_LCD
      if (((LCD_STANDBY_STATE == main_lcd_operation_state)||
           (LCD_SLEEP_STATE == main_lcd_operation_state))&&
           (KAL_FALSE == hpi_power_on)&&
           (0==lcd_pwr_data.power_handle)
           ) {
         /// make sure there is no interrupt before turning off LCD clock
         temp_reg=DRV_Reg(LCD_INT_STATUS_REG);

         /// Turn off LCD clock
         DRV_Reg(DRVPDN_CON1_SET) = DRVPDN_CON1_LCD;

         #ifdef MTK_SLEEP_ENABLE
            L1SM_SleepEnable(lcd_sleep_mode_handler);
         #endif
      }
   #else
      if ((((LCD_STANDBY_STATE == main_lcd_operation_state)||
            (LCD_SLEEP_STATE == main_lcd_operation_state))&&
           ((LCD_STANDBY_STATE == sub_lcd_operation_state)||
            (LCD_SLEEP_STATE == sub_lcd_operation_state)))&&
           (KAL_FALSE == hpi_power_on)&&
           (0==lcd_pwr_data.power_handle)
           ) {
         /// make sure there is no interrupt before turning off LCD clock
         temp_reg=DRV_Reg(LCD_INT_STATUS_REG);

         /// Turn off LCD clock
         DRV_Reg(DRVPDN_CON1_SET) = DRVPDN_CON1_LCD;

         #ifdef MTK_SLEEP_ENABLE
            ASSERT(lcd_sleep_mode_handler!=0xff);
            L1SM_SleepEnable(lcd_sleep_mode_handler);
         #endif
      }
   #endif
   RestoreIRQMask(save_irq_mask);
}  /* lcd_turn_off_clock() */



kal_bool lcd_clk_on=KAL_FALSE;
void lcd_power_ctrl(kal_bool enable)
{
   if(KAL_TRUE == enable)
   {
      lcd_clk_on=KAL_TRUE;
      lcd_turn_on_clock();
   }
   else
   {
      lcd_clk_on=KAL_FALSE;
      lcd_turn_off_clock();
   }
}



kal_uint8 lcd_get_power_handle( void )
{	
   ASSERT(lcd_pwr_data.handle_count<32);
   return lcd_pwr_data.handle_count++;   
}

void lcd_clk_disable( kal_uint8 handle )
{   
   kal_uint32 temp;
   kal_uint32 savedMask;
   
   savedMask = SaveAndSetIRQMask();
   lcd_pwr_data.power_handle &= ~(1 << handle);   	
   RestoreIRQMask(savedMask);
   
   if ((0==lcd_pwr_data.power_handle)&&
      (KAL_FALSE == lcd_clk_on)){
   	   lcd_turn_off_clock();
   }	
}

void lcd_clk_enable( kal_uint8 handle )
{
   kal_uint32 temp;
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   lcd_pwr_data.power_handle |= (1 << handle);	
   RestoreIRQMask(savedMask);
   lcd_turn_on_clock();
}
/**
 * Provide HPI power control interface for WIFI.
 *
 * @param None.
 *
 * @return None.
 */
kal_uint8 hpi_power_handle=0;
void hpi_power_ctrl(kal_bool bTurnOnClock)
{
   kal_uint32 save_irq_mask;
   
      if (KAL_TRUE == bTurnOnClock) {      	          
         lcd_clk_enable(hpi_power_handle);
         old_lcd_cmd_period_count=lcd_cmd_period_count;
         if (hpi_cmd_period_count>old_lcd_cmd_period_count) {
            save_irq_mask=SaveAndSetIRQMask();
            SET_LCD_ROI_CTRL_CMD_LATENCY(hpi_cmd_period_count);
            RestoreIRQMask(save_irq_mask);
         }
      } else {
         ASSERT(KAL_FALSE == bTurnOnClock);
         hpi_power_on = KAL_FALSE;
         if (hpi_cmd_period_count > old_lcd_cmd_period_count) {
            save_irq_mask=SaveAndSetIRQMask();
            SET_LCD_ROI_CTRL_CMD_LATENCY(old_lcd_cmd_period_count);
            RestoreIRQMask(save_irq_mask);
         }
         /// make sure no one use LCD interface
         lcd_clk_disable(hpi_power_handle);        
      }   
}  /* hpi_power_ctrl() */



/**
 * Configure command count for WIFI.
 *
 * @param None.
 *
 * @return None.
 */
void set_hpi_low_period_count(kal_uint8 low_period)
{
#ifdef __WIFI_SUPPORT__
   hpi_cmd_period_count=low_period;
#endif
}



/**
 * Swap width and height of a specified lcd layer
 *
 * @param swap_layer lcd layer
 *
 * @return None.
 */
void lcd_layer_swap_width_height(kal_uint32 swap_layer)
{
   #if (DRV_LAYER_TOTAL_COUNT>1)
     kal_uint16 width,height;

      lcd_power_ctrl(KAL_TRUE);
      switch (swap_layer) {
      case LCD_LAYER0_ENABLE:
         width=GET_LCD_LAYER0_WINDOW_WIDTH;
         height=GET_LCD_LAYER0_WINDOW_HEIGHT;
         SET_LCD_LAYER0_WINDOW_SIZE(height,width);
         break;
      case LCD_LAYER1_ENABLE:
         width=GET_LCD_LAYER1_WINDOW_WIDTH;
         height=GET_LCD_LAYER1_WINDOW_HEIGHT;
         SET_LCD_LAYER1_WINDOW_SIZE(height,width);
         break;
      case LCD_LAYER2_ENABLE:
         width=GET_LCD_LAYER2_WINDOW_WIDTH;
         height=GET_LCD_LAYER2_WINDOW_HEIGHT;
         SET_LCD_LAYER2_WINDOW_SIZE(height,width);
         break;
      case LCD_LAYER3_ENABLE:
         width=GET_LCD_LAYER3_WINDOW_WIDTH;
         height=GET_LCD_LAYER3_WINDOW_HEIGHT;
         SET_LCD_LAYER3_WINDOW_SIZE(height,width);
         break;
      #if (DRV_LAYER_TOTAL_COUNT>4)
      case LCD_LAYER4_ENABLE:
         width=GET_LCD_LAYER4_WINDOW_WIDTH;
         height=GET_LCD_LAYER4_WINDOW_HEIGHT;
         SET_LCD_LAYER4_WINDOW_SIZE(height,width);
      break;
      case LCD_LAYER5_ENABLE:
         width=GET_LCD_LAYER5_WINDOW_WIDTH;
         height=GET_LCD_LAYER5_WINDOW_HEIGHT;
         SET_LCD_LAYER5_WINDOW_SIZE(height,width);
      break;
      #endif
   }
   #endif
}



/**
 * Set layer rotate
 *
 * @param rotate_layer layer
 * @param rotate_value rotate value
 *
 * @return None.
 */
void set_lcd_layer_roate(kal_uint32 rotate_layer,kal_uint8 rotate_value)
{
   #if (DRV_LAYER_TOTAL_COUNT>1)
      lcd_power_ctrl(KAL_TRUE);
      if (rotate_value<=LCD_LAYER_MIRROR_ROTATE_270) {
         current_lcd_hw_update_layer=rotate_layer;
         switch (rotate_layer) {
         case LCD_LAYER0_ENABLE:
            lcd_rotate_value=GET_LCD_LAYER0_ROTATE;
            SET_LCD_LAYER0_ROTATE(rotate_value);
            break;
         case LCD_LAYER1_ENABLE:
            lcd_rotate_value=GET_LCD_LAYER1_ROTATE;
            SET_LCD_LAYER1_ROTATE(rotate_value);
            break;
         case LCD_LAYER2_ENABLE:
            lcd_rotate_value=GET_LCD_LAYER2_ROTATE;
            SET_LCD_LAYER2_ROTATE(rotate_value);
            break;
         case LCD_LAYER3_ENABLE:
            lcd_rotate_value=GET_LCD_LAYER3_ROTATE;
            SET_LCD_LAYER3_ROTATE(rotate_value);
            break;
         #if (DRV_LAYER_TOTAL_COUNT>4)
         case LCD_LAYER4_ENABLE:
            lcd_rotate_value=GET_LCD_LAYER4_ROTATE;
            SET_LCD_LAYER4_ROTATE(rotate_value);
            break;
         case LCD_LAYER5_ENABLE:
            lcd_rotate_value=GET_LCD_LAYER5_ROTATE;
            SET_LCD_LAYER5_ROTATE(rotate_value);
            break;
         #endif
         }
      }
   #endif
}  /* set_lcd_layer_roate() */



/**
 * Resume layer from previous rotate
 *
 * @param rotate_layer layer
 * @param rotate_value rotate value
 *
 * @return None.
 */
void resume_lcd_layer_rotate(void)
{
   #if (DRV_LAYER_TOTAL_COUNT>1)
      lcd_power_ctrl(KAL_TRUE);
      switch (current_lcd_hw_update_layer) {
      case LCD_LAYER0_ENABLE:
         SET_LCD_LAYER0_ROTATE(lcd_rotate_value);
         break;
      case LCD_LAYER1_ENABLE:
         SET_LCD_LAYER1_ROTATE(lcd_rotate_value);
         break;
      case LCD_LAYER2_ENABLE:
         SET_LCD_LAYER2_ROTATE(lcd_rotate_value);
         break;
      case LCD_LAYER3_ENABLE:
         SET_LCD_LAYER3_ROTATE(lcd_rotate_value);
         break;
      #if (DRV_LAYER_TOTAL_COUNT>4)
      case LCD_LAYER4_ENABLE:
         SET_LCD_LAYER4_ROTATE(lcd_rotate_value);
         break;
      case LCD_LAYER5_ENABLE:
         SET_LCD_LAYER5_ROTATE(lcd_rotate_value);
         break;
      #endif
      }
      current_lcd_hw_update_layer=0;
      lcd_rotate_value=0;
#endif
}  /* resume_lcd_layer_rotate() */



/**
 * Configure the layer parameters in the layer parameter queue
 * for LCD multi-layer structure.
 *
 * @param None.
 *
 * @return None.
 */
extern kal_uint8 lcd_fw_update_layer;
void config_lcd_layer_window_queue(void)
{
   #if (!defined(MT6205B)&&!defined(MT6208))
      kal_uint8 i;
      kal_uint32 lcd_layer_base_addr=LCD_LAYER0_BASE_ADDR;
      kal_uint32 lcd_layer_ctrl_reg;

      lcd_power_ctrl(KAL_TRUE);
      for (i=0;i<LCD_TOTAL_LAYER;i++) {
         if (KAL_TRUE == lcd_layer_data[i].layer_update_queue) {
            lcd_layer_base_addr=LCD_LAYER0_BASE_ADDR+i*LCD_LAYER_ADDR_OFFSET;
            #ifndef DRV_LAYER_COLOR_FORMAT
               lcd_layer_ctrl_reg=((lcd_layer_data[i].source_key&0xFFFF)<< 16);
               lcd_layer_ctrl_reg |= ((lcd_layer_data[i].opacity_value)<<3);
               if (lcd_layer_data[i].color_palette_enable) {
                  lcd_layer_ctrl_reg |= LCD_LAYER_CTRL_LUT_ENABLE_BIT;
               }
            #else //6228~6238
               /*KKKKK*/
               lcd_layer_ctrl_reg = (lcd_layer_data[i].opacity_value);
            #endif
            lcd_layer_ctrl_reg |= (lcd_layer_data[i].rotate_value<<11);
            
            #if (DRV_PALETTE_COUNT>1)
               if (lcd_layer_data[i].color_palette_select) {
                  lcd_layer_ctrl_reg |= LCD_LAYER_CTRL_LUT1_SELECT_BIT;
               }
            #endif //DRV_PALETTE_COUNT>1
            if (lcd_layer_data[i].source_key_enable) {
               lcd_layer_ctrl_reg |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
            }

            if (lcd_layer_data[i].opacity_enable) {
               lcd_layer_ctrl_reg |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
            }

            #if defined(DRV_LAYER_COLOR_FORMAT) /*layer support ARGB hence souce key use a dedicated register*/                        
               lcd_layer_ctrl_reg |= (lcd_layer_data[i].source_color_format << 9);

               DRV_WriteReg32(lcd_layer_base_addr+0x04,(lcd_layer_data[i].source_key));
               DRV_WriteReg32(lcd_layer_base_addr+0x08,(lcd_layer_data[i].x_offset)|(lcd_layer_data[i].y_offset<<16));
               DRV_WriteReg32(lcd_layer_base_addr+0xC,lcd_layer_data[i].frame_buffer_address);
               DRV_WriteReg32(lcd_layer_base_addr+0x10,(lcd_layer_data[i].column_number)|(lcd_layer_data[i].row_number<<16));
            #else   
               DRV_WriteReg32(lcd_layer_base_addr+0x04,(lcd_layer_data[i].x_offset)|(lcd_layer_data[i].y_offset<<16));
               if((main_lcd_operation_state==LCD_FW_UPDATE_STATE)||
                  (main_lcd_operation_state==LCD_FW_CMD_QUEUE_STATE)) {
                  if(lcd_fw_update_layer!=i) {
                     DRV_WriteReg32(lcd_layer_base_addr+0x08,lcd_layer_data[i].frame_buffer_address);
                  }
               } else {
                  DRV_WriteReg32(lcd_layer_base_addr+0x08,lcd_layer_data[i].frame_buffer_address);
               }
               DRV_WriteReg32(lcd_layer_base_addr+0x0C,(lcd_layer_data[i].column_number)|(lcd_layer_data[i].row_number<<16));
            #endif //DRV_LAYER_COLOR_FORMAT
            DRV_WriteReg32(lcd_layer_base_addr,lcd_layer_ctrl_reg);
            lcd_layer_data[i].layer_update_queue=KAL_FALSE;
         }
      }
      lcd_power_ctrl(KAL_FALSE);
   #endif
}  /* config_lcd_layer_window_queue() */



/**
 * Configure the layer parameters for LCD multi-layer structure.
 *
 * @param lcd_layer LCD_LAYER[0-5]
 * @param layer_data the parameters for lcd_layer
 *
 * @return KAL_TRUE if successful
 */
kal_bool config_lcd_layer_window(kal_uint8 lcd_layer,lcd_layer_struct *layer_data)
{
   #if (!defined(MT6205B)&&!defined(MT6208))

      kal_uint32 lcd_layer_base_addr=LCD_LAYER0_BASE_ADDR;
      kal_uint32 lcd_layer_ctrl_reg=0;

      /// For excetpion, we don't need to do the following
      if (!INT_QueryExceptionStatus()) {
         ASSERT(lcd_layer<LCD_TOTAL_LAYER);

         if (layer_data->opacity_enable) {
            ASSERT(layer_data->opacity_value <= LCD_MAX_OPACITY);
         }
         #ifndef DRV_LAYER_COLOR_FORMAT
            if (layer_data->color_palette_enable) {
               #if (defined(MT6225)||defined(MT6235)||defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D))
                  ASSERT(layer_data->color_palette_select <= LCD_COLOR_PALETTE0);
               #else
                  ASSERT(layer_data->color_palette_select <= LCD_COLOR_PALETTE1);
               #endif
            }
         #endif

            #if !defined(DRV_IDP_SUPPORT)               
               if ((LCD_IS_RUNNING)&&((1<<(31-lcd_layer))&DRV_Reg(LCD_ROI_CTRL_REG))) {
               IRQMask(IRQ_LCD_CODE);
               lcd_layer_data[lcd_layer].layer_update_queue=KAL_TRUE;
               lcd_layer_data[lcd_layer].source_key_enable=layer_data->source_key_enable;
               lcd_layer_data[lcd_layer].color_palette_enable=layer_data->color_palette_enable;
               lcd_layer_data[lcd_layer].opacity_enable=layer_data->opacity_enable;
               lcd_layer_data[lcd_layer].color_palette_select=layer_data->color_palette_select;
               lcd_layer_data[lcd_layer].opacity_value=layer_data->opacity_value;
               lcd_layer_data[lcd_layer].rotate_value=layer_data->rotate_value;
               lcd_layer_data[lcd_layer].source_key=layer_data->source_key;
               lcd_layer_data[lcd_layer].x_offset=layer_data->x_offset;
               lcd_layer_data[lcd_layer].y_offset=layer_data->y_offset;
               lcd_layer_data[lcd_layer].row_number=layer_data->row_number;
               lcd_layer_data[lcd_layer].column_number=layer_data->column_number;
               lcd_layer_data[lcd_layer].frame_buffer_address=layer_data->frame_buffer_address;
               IRQUnmask(IRQ_LCD_CODE);
               return KAL_TRUE;
            }
         #elif defined(DRV_IDP_SUPPORT)             
            #ifndef DUAL_LCD
               if ((main_lcd_operation_state!=LCD_STANDBY_STATE)&&
                   (main_lcd_operation_state!=LCD_SW_UPDATE_STATE)&&
                   (main_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
                   (main_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                   #ifdef TV_OUT_SUPPORT
                      (main_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
                      (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                   #endif
                   (main_lcd_operation_state!=LCD_SLEEP_STATE)) {
                  ASSERT(0);
               }
            #else
               if (MAIN_LCD == current_update_lcd) {
                  if ((main_lcd_operation_state!=LCD_STANDBY_STATE)&&
                      (main_lcd_operation_state!=LCD_SW_UPDATE_STATE)&&
                      (main_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
                      (main_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                      #ifdef TV_OUT_SUPPORT
                         (main_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
                         (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                      #endif
                      (main_lcd_operation_state!=LCD_SLEEP_STATE)) {
                     ASSERT(0);
                  }
               } else {
                  if ((sub_lcd_operation_state!=LCD_STANDBY_STATE)&&
                      (sub_lcd_operation_state!=LCD_SW_UPDATE_STATE)&&
                      (sub_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
                      (sub_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                      #ifdef TV_OUT_SUPPORT
                         (main_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
                         (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                      #endif
                      (sub_lcd_operation_state!=LCD_SLEEP_STATE)) {
                     ASSERT(0);
                  }
               }
            #endif /* DUAL_LCD */
         #endif
      }

      lcd_power_ctrl(KAL_TRUE);
      lcd_layer_base_addr+=lcd_layer*LCD_LAYER_ADDR_OFFSET;

      #ifndef DRV_LAYER_COLOR_FORMAT
         lcd_layer_ctrl_reg = (layer_data->source_key << 16);
      #else
         lcd_layer_ctrl_reg = 0;
      #endif

      if (layer_data->source_key_enable) {
         lcd_layer_ctrl_reg |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
      }

      #ifndef DRV_LAYER_COLOR_FORMAT
         if (layer_data->color_palette_enable) {
            lcd_layer_ctrl_reg |= LCD_LAYER_CTRL_LUT_ENABLE_BIT;
         } else {
            lcd_layer_ctrl_reg &= ~LCD_LAYER_CTRL_LUT_ENABLE_BIT;
         }

         if (layer_data->color_palette_select) {
            lcd_layer_ctrl_reg |= LCD_LAYER_CTRL_LUT1_SELECT_BIT;
         }
      #endif

      if (layer_data->opacity_enable) {
         lcd_layer_ctrl_reg |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;

         #ifndef DRV_LAYER_COLOR_FORMAT
            lcd_layer_ctrl_reg |= ((layer_data->opacity_value)<<3);
         #else
            lcd_layer_ctrl_reg |= (layer_data->opacity_value);
         #endif
      }
      #ifdef DRV_LAYER_ROTATE
         ASSERT(layer_data->rotate_value <= LCD_LAYER_MIRROR_ROTATE_270);
         lcd_layer_ctrl_reg |= ((layer_data->rotate_value)<<11);
      #endif
      #if defined(DRV_LAYER_COLOR_FORMAT)         
         ASSERT(layer_data->source_color_format <= LCD_LAYER_SOURCE_MONO);
         #ifdef DUAL_LCD
            if ((main_lcd_operation_state==LCD_DC_UPDATE_STATE)||
                (main_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE)||
                (sub_lcd_operation_state==LCD_DC_UPDATE_STATE)||
                (sub_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE))
         #else
            if ((main_lcd_operation_state==LCD_DC_UPDATE_STATE)||
                (main_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE))
         #endif
            {
               if ((LCD_LAYER0_ENABLE>>lcd_layer)!=GET_LCD_DIRECT_COUPLE_LAYER) {
                  if (layer_data->source_color_format!=LCD_LAYER_SOURCE_MONO) {
                     lcd_layer_ctrl_reg |= (layer_data->source_color_format<<9);
                  }
               } else {
                  lcd_layer_ctrl_reg |= (DRV_Reg(lcd_layer_base_addr) & LCD_LAYER_CTRL_COLOR_FORMAT_MASK);
               }
            } else {
               if (layer_data->source_color_format!=LCD_LAYER_SOURCE_MONO) {
                  lcd_layer_ctrl_reg |= (layer_data->source_color_format<<9);
               }
            }
      #endif /*DRV_LAYER_COLOR_FORMAT*/
      DRV_WriteReg32(lcd_layer_base_addr,lcd_layer_ctrl_reg);

      #if defined(DRV_LAYER_COLOR_FORMAT) /*layer support ARGB hence souce key use a dedicated register*/         
         DRV_WriteReg32(lcd_layer_base_addr+0x04,layer_data->source_key);
         DRV_WriteReg32(lcd_layer_base_addr+0x08,(layer_data->x_offset)|(layer_data->y_offset<<16));
         DRV_WriteReg32(lcd_layer_base_addr+0x0C,layer_data->frame_buffer_address);
         DRV_WriteReg32(lcd_layer_base_addr+0x10,(layer_data->column_number)|(layer_data->row_number<<16));
      #else   
         DRV_WriteReg32(lcd_layer_base_addr+4,(layer_data->x_offset)|(layer_data->y_offset<<16));
         DRV_WriteReg32(lcd_layer_base_addr+8,layer_data->frame_buffer_address);
         DRV_WriteReg32(lcd_layer_base_addr+0x0C,(layer_data->column_number)|(layer_data->row_number<<16));      
      #endif //DRV_LAYER_COLOR_FORMAT

      lcd_power_ctrl(KAL_FALSE);
      return KAL_TRUE;
   #elif (defined(MT6205B)||defined(MT6208))
      lcd_frame_buffer_address=layer_data->frame_buffer_address;
   #endif
}  /* config_lcd_layer_window() */



/**
 * Configure the layer offset
 *
 * @param lcd_layer LCD_LAYER[0-5]
 * @param layer_offset_x x offset
 * @param layer_offset_y y offset
 *
 * @return KAL_TRUE if successful
 */
void config_lcd_layer_offset(kal_uint8 lcd_layer, kal_uint16 layer_offset_x, kal_uint16 layer_offset_y)
{
   #if (DRV_LAYER_TOTAL_COUNT>1)
      switch (lcd_layer) {
      case LCD_LAYER0:
         SET_LCD_LAYER0_WINDOW_OFFSET(layer_offset_x,layer_offset_y);
         break;
      case LCD_LAYER1:
         SET_LCD_LAYER1_WINDOW_OFFSET(layer_offset_x,layer_offset_y);
         break;
      case LCD_LAYER2:
         SET_LCD_LAYER2_WINDOW_OFFSET(layer_offset_x,layer_offset_y);
         break;
      case LCD_LAYER3:
         SET_LCD_LAYER3_WINDOW_OFFSET(layer_offset_x,layer_offset_y);
         break;
      #if (DRV_LAYER_TOTAL_COUNT>4)
      case LCD_LAYER4:
         SET_LCD_LAYER4_WINDOW_OFFSET(layer_offset_x,layer_offset_y);
      break;
      case LCD_LAYER5:
         SET_LCD_LAYER5_WINDOW_OFFSET(layer_offset_x,layer_offset_y);
      break;
      #endif
   }
#endif
}  /* config_lcd_layer_offset() */



#ifdef DRV_IDP_SUPPORT
void config_lcd_hw_layer(kal_uint32 hw_layer,kal_uint16 layer_offset_x,kal_uint16 layer_offset_y,
                         kal_uint16 layer_width, kal_uint16 layer_height)
{
}



/**
 * Get hw layer rotation value
 *
 * @param hw_layer LCD_LAYER[0-5]_ENABLE
 *
 * @return rotation value
 */
kal_uint8 get_lcd_hw_layer_rotate_value(kal_uint32 hw_layer)
{
   kal_uint8 rotate_value=0;

   lcd_power_ctrl(KAL_TRUE);
   switch (hw_layer) {
      case LCD_LAYER0_ENABLE:
         rotate_value=GET_LCD_LAYER0_ROTATE;
         break;
      case LCD_LAYER1_ENABLE:
         rotate_value=GET_LCD_LAYER1_ROTATE;
         break;
      case LCD_LAYER2_ENABLE:
         rotate_value=GET_LCD_LAYER2_ROTATE;
         break;
      case LCD_LAYER3_ENABLE:
         rotate_value=GET_LCD_LAYER3_ROTATE;
         break;
      #if (DRV_LAYER_TOTAL_COUNT>4)
      case LCD_LAYER4_ENABLE:
         rotate_value=GET_LCD_LAYER4_ROTATE;
         break;
      case LCD_LAYER5_ENABLE:
         rotate_value=GET_LCD_LAYER5_ROTATE;
         break;
      #endif
   }
   lcd_power_ctrl(KAL_FALSE);

   return rotate_value;
}
#endif /*DRV_IDP_SUPPORT*/



/**
 * Configure the ROI window offset and size of LCD interface.
 *
 * @param roi_x_offset ROI X offset
 * @param roi_y_offset ROI Y offset
 * @param roi_column   ROI width
 * @param roi_row      ROI height
 *
 * @return KAL_TRUE if sucessful
 */
kal_bool config_lcd_roi_window(kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint16 roi_column,
                        kal_uint16 roi_row)
{
   #if (!defined(MT6205B)&&!defined(MT6208))
      #if (!defined(DRV_LCD_FW_UPDATE_SUPPORT)&&!defined(DRV_LCD_HW_TRIGGER_SUPPORT))
         ASSERT(!LCD_IS_RUNNING);
      #elif defined(DRV_LCD_FW_UPDATE_SUPPORT)||defined(DRV_LCD_HW_TRIGGER_SUPPORT)          
         #ifndef DUAL_LCD
            if ((main_lcd_operation_state!=LCD_STANDBY_STATE)&&
                (main_lcd_operation_state!=LCD_SW_UPDATE_STATE)&&
                (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)&&
                #if (defined(DRV_IDP_SUPPORT))
                   (main_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
                   (main_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                #endif
                #ifdef TV_OUT_SUPPORT
                   (main_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
                   (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                #endif
                (main_lcd_operation_state!=LCD_SLEEP_STATE)) {
               ASSERT(0);
            }
         #else
            if (current_update_lcd==MAIN_LCD) {
               if ((main_lcd_operation_state!=LCD_STANDBY_STATE)&&
                   (main_lcd_operation_state!=LCD_SW_UPDATE_STATE)&&
                   (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)&&
                   #if (defined(DRV_IDP_SUPPORT))
                      (main_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
                      (main_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                   #endif
                   #ifdef TV_OUT_SUPPORT
                      (main_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
                      (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                   #endif
                   (main_lcd_operation_state!=LCD_SLEEP_STATE)) {
                  ASSERT(0);
               }
            } else {
               if ((sub_lcd_operation_state!=LCD_STANDBY_STATE)&&
                   (sub_lcd_operation_state!=LCD_SW_UPDATE_STATE)&&
                   (sub_lcd_operation_state!=LCD_FW_UPDATE_STATE)&&
                   #if (defined(DRV_IDP_SUPPORT))
                      (sub_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
                      (sub_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                   #endif
                   #ifdef TV_OUT_SUPPORT
                      (main_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
                      (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                   #endif
                   (sub_lcd_operation_state!=LCD_SLEEP_STATE)) {
                  ASSERT(0);
               }
            }
         #endif /* DUAL_LCD */
      #endif

      lcd_power_ctrl(KAL_TRUE);

      SET_LCD_ROI_WINDOW_OFFSET(roi_offset_x,roi_offset_y);
      SET_LCD_ROI_WINDOW_SIZE(roi_column,roi_row);

      lcd_power_ctrl(KAL_FALSE);
   #endif
   return KAL_TRUE;
}  /* config_lcd_roi_window() */



/**
 * LCD output or not
 *
 * @param lcd_output KAL_TRUE/KAL_FALSE to enable/disable LCD output.
 *
 * @return None.
 */
void config_lcd_output(kal_bool lcd_output)
{
   #if defined(TV_OUT_SUPPORT)      
      if (KAL_TRUE == lcd_output) {
         lcd_output_mode = KAL_TRUE;
      } else {
         ASSERT(KAL_FALSE == lcd_output);
         lcd_output_mode = KAL_FALSE;
      }
   #endif
}



/**
 * Set the color palette of LCD interface.
 *
 * @param color_palette_select   LCD_COLOR_PALETTE[0-1]
 * @param color_palette_addr_ptr the address ptr that points to the color with offset
 *                               (start_index) from the 0th color in color palette
 * @param start_index            the offset from the 0th color in color palette
 * @param number_of_color        number of colors in color palette will be set.
 *
 * @return None.
 */
void set_lcd_color_palette(kal_uint8 color_palette_select,kal_uint32 *color_palette_addr_ptr,
                           kal_uint8 start_index, kal_uint8 number_of_color)
{
   #if (DRV_PALETTE_COUNT>=1)
      kal_uint16 i;

      lcd_power_ctrl(KAL_TRUE);
      #if (DRV_PALETTE_COUNT==2)
         if (color_palette_select==LCD_COLOR_PALETTE0) {
            for (i=start_index;i<(start_index+number_of_color);i++) {
               SET_LUT0_COLOR(i,*(color_palette_addr_ptr+i));
            }
         } else if (color_palette_select==LCD_COLOR_PALETTE1) {
            for (i=start_index;i<(start_index+number_of_color);i++) {
               SET_LUT1_COLOR(i,*(color_palette_addr_ptr+i));
            }
         }
      #elif (DRV_PALETTE_COUNT==1)
         for (i=start_index;i<(start_index+number_of_color);i++) {
            SET_LUT0_COLOR(i,*(color_palette_addr_ptr+i));
         }
      #endif
      lcd_power_ctrl(KAL_FALSE);
   #endif
}



#ifdef __SYNC_LCM_SW_SUPPORT__
kal_uint32 sync_lcm_delay_time1,sync_lcm_delay_time2;
kal_uint8 sync_lcm_delay_flag=KAL_FALSE;
kal_uint32 min_sync_lcm_delay_time;

void sync_lcm_timer_cb(void *dummy_para)
{
   kal_uint32 delay_period;

   if (sync_lcm_delay_flag==KAL_TRUE)
   {
      sync_lcm_delay_time2=drv_get_current_time();
      delay_period=drv_get_duration_tick(sync_lcm_delay_time1,sync_lcm_delay_time2);
      if (delay_period>min_sync_lcm_delay_time)
      {  /* 32.768 delay_period = 1ms */
         sync_lcm_delay_flag=KAL_FALSE;
			if (sync_lcm_update_cb!=NULL)
         sync_lcm_update_cb();
      }
      else
      {
         kal_set_timer(sync_lcm_timer_handle,(kal_timer_func_ptr)sync_lcm_timer_cb,NULL,1,0);
      }
   }
   else
   {
		if (sync_lcm_update_cb!=NULL)
      sync_lcm_update_cb();
   }
}   /* sync_lcm_timer_cb() */



void sync_lcm_HISR(void)
{
   volatile kal_uint32 i;
   kal_uint16 roi_height;

   if (current_sync_lcm_polarity==KAL_TRUE)
      current_sync_lcm_polarity=KAL_FALSE;
   else
      current_sync_lcm_polarity=KAL_TRUE;
   EINT_Set_Polarity(sync_lcm_channel_number,current_sync_lcm_polarity);

   if (current_sync_lcm_polarity!=sync_lcm_signal_polarity)
   {

      if (sync_lcm_enable_mode==KAL_TRUE)
      {
          if ((main_lcd_operation_state==LCD_HW_UPDATE_STATE)||
              (main_lcd_operation_state==LCD_DC_UPDATE_STATE)||
              (main_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)||
              (main_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
              (main_lcd_operation_state==LCD_FW_UPDATE_STATE)||//add in 6225
              (main_lcd_operation_state==LCD_FW_CMD_QUEUE_STATE)||
              (LCD_JPEG_VIDEO_UPDATE_STATE == main_lcd_operation_state) ||
              (LCD_JPEG_VIDEO_CMD_QUEUE_STATE == main_lcd_operation_state)              
              )//add in 6225
          {   /* make sure the clock of LCD interface is turn on */
                
            if ((preview_frame_update_flag==KAL_TRUE)||
                (video_encode_update_flag==KAL_TRUE)||
                (video_decode_update_flag==KAL_TRUE))
            {
                if ((main_lcd_fb_update_para.lcm_start_y)>15)//XXXXX tmp solution, need to check if 10 is reasonable?
                {
                  sync_lcm_delay_flag=KAL_TRUE;
                  min_sync_lcm_delay_time=(main_lcd_fb_update_para.lcm_start_y*14*32)/LCD_HEIGHT;
                  /* offset_y/height * 14ms * 32.768, assume 70 fps refresh rate */
                  sync_lcm_delay_time1=drv_get_current_time();
                  kal_set_timer(sync_lcm_timer_handle,(kal_timer_func_ptr)sync_lcm_timer_cb,NULL,1,0);
                }
                else
                {
                     if (sync_lcm_update_cb!=NULL)
                    sync_lcm_update_cb();
                }
            }
         }
            else
            {
               if (sync_lcm_update_cb!=NULL)
         sync_lcm_update_cb();
      }
   }
   }
   EINT_UnMask(sync_lcm_channel_number);  
}  /* sync_lcm_LISR() */
#endif


extern kal_uint8 g_LCD_level ;

/**
 * Initialize the system related parameters of the LCD interface.
 *
 * @param None.
 *
 * @return None.
 */
void lcd_system_init(void)
{
   static kal_bool bInitialized = KAL_FALSE;

   if (KAL_TRUE == bInitialized) {
      return;
   }

   #ifdef MTK_SLEEP_ENABLE
   lcd_sleep_mode_handler = L1SM_GetHandle();
   #endif
   
   hpi_power_handle=lcd_get_power_handle();
   /// hook main/sub lcd callback function
   #if 1
   //Huyanwei Add It 
   g_LCD_level=0;
   #endif
   LCD_FunConfig();

   lcd_power_ctrl(KAL_TRUE);

   #if (!defined(MT6205B)&&!defined(MT6208))
      /// setup GPIO, LCM timing, reset LCM
      init_lcd_interface();
   #endif
   

   #if (!defined(MT6205B)&&!defined(MT6208))
      lcd_event_id=kal_create_event_group("LCD_EVT");
      IRQ_Register_LISR(IRQ_LCD_CODE, lcd_LISR, "LCD ISR");
      IRQSensitivity(IRQ_LCD_CODE, LEVEL_SENSITIVE);
      if (INT_QueryExceptionStatus()!=KAL_TRUE) {
         IRQUnmask(IRQ_LCD_CODE);
      }
      {
         kal_uint32 temp_reg;
         /// clear LCD interrupt status
         temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
      }

      DRV_Register_HISR(DRV_LCD_HISR_ID, lcd_HISR);
      GPTI_GetHandle(&lcd_event_timer_handle);
   #endif
   #ifdef TV_OUT_SUPPORT
      tv_output_owner=TV_OUT_OWNER_MMI;
   #endif
   lcd_power_ctrl(KAL_FALSE);

   #ifdef __SYNC_LCM_SW_SUPPORT__      
         sync_lcm_update_cb=NULL;
         custom_sync_lcm_eint_setting(&sync_lcm_signal_polarity);
         current_sync_lcm_polarity=sync_lcm_signal_polarity;
         sync_lcm_channel_number=custom_eint_get_channel(sync_lcm_chann);
         if ((sync_lcm_channel_number+1)>=EINT_MAX_CHANNEL) {
            EXTRA_EINT_Registration(sync_lcm_channel_number, sync_lcm_signal_polarity,sync_lcm_HISR,KAL_TRUE);
         } else {
            EINT_Registration(sync_lcm_channel_number, KAL_FALSE, sync_lcm_signal_polarity, sync_lcm_HISR, KAL_TRUE);
         }         
         EINT_Set_Sensitivity(sync_lcm_channel_number, EDGE_SENSITIVE);
         EINT_Mask(sync_lcm_channel_number);
         if (0 == sync_lcm_timer_handle) {
            sync_lcm_timer_handle=kal_create_timer("Sync LCM Timer");
         }
   #endif //__SYNC_LCM_SW_SUPPORT__        
   #ifdef __SYNC_LCM_HW_SUPPORT__
      //enable LCD TE function
   #endif //__SYNC_LCM_HW_SUPPORT_
   bInitialized = KAL_TRUE;
}  /* lcd_system_init() */



/**
 * Initialize the LCD interface and LCD module.
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param background_color RGB565 color that LCM will use to initialize its frame buffer
 *
 * @return None.
 */
void lcd_init(kal_uint8 lcd_id, kal_uint16 background_color)
{
   lcd_system_init();

   #if (!defined(MT6205B)&&!defined(MT6208))

      #if (defined(CAMERA_MODULE))
         cam_module_func_config();
         /// for AIT102N module, since the LCD interface is use the same bus with AIT102N
         /// camera module. we should set the reset pin high and power pin low to disable AIT102N
         /// before LCD interface init
         ext_cam_func->cam_module_power_off();
      #endif

      /// initialize data structures
      {
         kal_int32 i;
         for (i=0;i<LCD_TOTAL_LAYER;i++) {
            lcd_layer_data[i].layer_update_queue=KAL_FALSE;
         }
      }

      main_lcd_fb_update_para.block_mode_flag = KAL_TRUE;
      main_lcd_fb_update_para.lcd_block_mode_cb = NULL;
      sub_lcd_fb_update_para.block_mode_flag=KAL_TRUE;
      sub_lcd_fb_update_para.lcd_block_mode_cb = NULL;

      lcd_power_ctrl(KAL_TRUE);
      #ifdef DRV_LCD_MEMORY_OUTPUT
         main_lcd_fb_update_para.memory_output = KAL_FALSE;
         sub_lcd_fb_update_para.memory_output = KAL_FALSE;
         SET_LCD_ROI_WMEM_OFFSET(0,0);
      #endif
      #ifdef TV_OUT_SUPPORT
         main_lcd_fb_update_para.tv_output = KAL_FALSE;         
         sub_lcd_fb_update_para.tv_output = KAL_FALSE;         
      #endif
      #if (DRV_LCD_CMD_QUEUE_COUNT>1)
         SET_LCD_CMD_QUEUE1;
      #endif
      DISABLE_LCD_ROI_CTRL_W2MEM;
      switch (lcd_id) {
      case MAIN_LCD:
         ASSERT(LCD_IDLE_STATE == main_lcd_operation_state);
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG, MAIN_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG, MAIN_LCD_DATA_ADDR);
         SET_LCD_ROI_CTRL_OUTPUT_FORMAT(MAIN_LCD_OUTPUT_FORMAT);
         MainLCD->Init(background_color, 0);
         main_lcd_operation_state=LCD_STANDBY_STATE;
         break;
      case SUB_LCD:
         ASSERT(LCD_IDLE_STATE == sub_lcd_operation_state);
         #ifdef DUAL_LCD
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG, SUB_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG, SUB_LCD_DATA_ADDR);
         SET_LCD_ROI_CTRL_OUTPUT_FORMAT(SUB_LCD_OUTPUT_FORMAT);
         #endif
         SubLCD->Init(background_color, 0);
         sub_lcd_operation_state=LCD_STANDBY_STATE;
         break;
      default:
         ASSERT(0);
      break;
      }
      lcd_power_ctrl(KAL_FALSE);
   #elif (defined(MT6205B)||defined(MT6208))
      lcd_power_ctrl(KAL_TRUE);
      switch (lcd_id) {
      case MAIN_LCD:
         ASSERT(LCD_IDLE_STATE == main_lcd_operation_state);
         MainLCD->Init(background_color, 0);
         main_lcd_operation_state=LCD_STANDBY_STATE;
         break;
      case SUB_LCD:
         ASSERT(LCD_IDLE_STATE == sub_lcd_operation_state);
         SubLCD->Init(background_color, 0);
         sub_lcd_operation_state=LCD_STANDBY_STATE;
         break;
      default:
         ASSERT(0);
      break;
   }
#endif
}  /* lcd_init() */



/**
 * Save ROI configuration and command parameter
 *
 * @param None.
 *
 * @return None.
 */
static void save_lcd_register(void)
{
   #ifdef TV_OUT_SUPPORT
      kal_uint8 i;

      lcd_hw_trigger_reg = REG_LCD_ROI_HW_CTRL;
      lcd_roi_size_reg=REG_LCD_ROI_SIZE;
      lcd_ctrl_reg=REG_LCD_ROI_CTRL;
      for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++) {
         lcd_cmq_para[i]=DRV_Reg32(LCD_CMD_PARAMETER_ADDR+(i<<2));
      }
   #endif //TV_OUT_SUPPORT
}



/**
 * Restore ROI configuration and command parameter
 *
 * @param None.
 *
 * @return None.
 */
static void restore_lcd_register(void)
{
   #ifdef TV_OUT_SUPPORT
      kal_uint8 i;

      REG_LCD_ROI_HW_CTRL=lcd_hw_trigger_reg;
      REG_LCD_ROI_SIZE=lcd_roi_size_reg;
      REG_LCD_ROI_CTRL=lcd_ctrl_reg;
      for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++) {
         DRV_WriteReg32(LCD_CMD_PARAMETER_ADDR+(i<<2),lcd_cmq_para[i]);
      }
      START_LCD_TRANSFER;
   #endif//TV_OUT_SUPPORT
}

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
extern void EntrySleep_GSensor(void);
extern void ExitSleep_GSensor(void);
#endif

/**
 * Let LCD module enter sleep mode
 *
 * @param lcd_id selection MAIN_LCD or SUB_LCD
 *
 * @return None.
 */
void lcd_sleep_in(kal_uint8 lcd_id)
{
   kal_uint32 save_irq_mask;

   /// to simplify state machine
   if((main_lcd_operation_state==LCD_DC_UPDATE_STATE)||
      (main_lcd_operation_state==LCD_HW_UPDATE_STATE)||
      (main_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
      (main_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)) {      	
      	return;      	      	
    }

   #if defined(G_SENSOR_SUPPORT)
   //Huyanwei Add It 
   EntrySleep_GSensor();
   #endif

   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id) {
   case MAIN_LCD:
      #if (!defined(MT6205B)&&!defined(MT6208))
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
      #endif
      #ifdef TV_OUT_SUPPORT
         if((main_lcd_operation_state==LCD_DC_UPDATE_STATE)||
            (main_lcd_operation_state==LCD_HW_UPDATE_STATE)) {
            save_irq_mask=SaveAndSetIRQMask();
            lcd_sleeping_state=KAL_TRUE;
            RestoreIRQMask(save_irq_mask);
            #if defined(DRV_IDP_6228_SERIES)
            while (IMGDMA_IBW2_IS_BUSY) {};
            #elif defined(DRV_IDP_6238_SERIES)
               /*KKKKK?????, need to more check on 6238, only happened in video decode case*/
               while (IMGDMA_IBW2_IS_BUSY) {};
            #endif //DRV_IDP_6238_SERIES         

            IRQMask(IRQ_LCD_CODE);
            save_lcd_register();
            REG_LCD_ROI_HW_CTRL = 0;
            MainLCD->EnterSleepMode();
            restore_lcd_register();
            ENABLE_LCD_TRANSFER_COMPLETE_INT;
            LCD_WRITE_MEM_ONLY;
            DISABLE_LCD_ROI_CTRL_CMD_FIRST;
            lcd_hw_trigger_roi_ctrl &= ~LCD_ROI_CTRL_CMD_ENABLE_BIT;
            IRQUnmask(IRQ_LCD_CODE);
            save_irq_mask=SaveAndSetIRQMask();
            #if ((!defined(__MAUI_BASIC__))&& (!defined(__L1_STANDALONE__)))
               if (tv_output_owner == TV_OUT_OWNER_LCD)
            #endif
               {
                  lcd_sleeping_state=KAL_FALSE;
               }
            RestoreIRQMask(save_irq_mask);
            if (main_lcd_operation_state==LCD_HW_UPDATE_STATE) {
               main_lcd_operation_state=LCD_HW_UPDATE_SLEEP_STATE;
               main_lcd_hw_trigger_output_mode=KAL_FALSE;
            } else if (main_lcd_operation_state==LCD_DC_UPDATE_STATE) {
               main_lcd_operation_state=LCD_DC_UPDATE_SLEEP_STATE;
            }

         } else if ((main_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
                    (main_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE))
         {
            ASSERT(0);
         } else {         
            MainLCD->EnterSleepMode();         
            main_lcd_operation_state=LCD_SLEEP_STATE;
         }
      #else /* TV_OUT_SUPPORT */      
         LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/         
         MainLCD->EnterSleepMode();      
         LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/         
         main_lcd_operation_state=LCD_SLEEP_STATE;
      #endif
      break;
      #ifdef DUAL_LCD
      case SUB_LCD:
         #if (!defined(MT6205B)&&!defined(MT6208))
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
         #endif
         #ifdef TV_OUT_SUPPORT
            if((sub_lcd_operation_state==LCD_DC_UPDATE_STATE)||
               (sub_lcd_operation_state==LCD_HW_UPDATE_STATE)) {
               save_irq_mask=SaveAndSetIRQMask();
               lcd_sleeping_state=KAL_TRUE;
               RestoreIRQMask(save_irq_mask);
               #if defined(DRV_IDP_6228_SERIES)
               while (IMGDMA_IBW2_IS_BUSY) {};
               #elif defined(DRV_IDP_6238_SERIES)
                  /*KKKKK?????, need to more check on 6238, only happened in video decode case*/
                  while (IMGDMA_IBW2_IS_BUSY) {};
               #endif //DRV_IDP_6238_SERIES         
               
               save_lcd_register();
               REG_LCD_ROI_HW_CTRL = 0;
               SubLCD->EnterSleepMode();
               restore_lcd_register();
               LCD_WRITE_MEM_ONLY;
               DISABLE_LCD_ROI_CTRL_CMD_FIRST;
               lcd_hw_trigger_roi_ctrl &= ~LCD_ROI_CTRL_CMD_ENABLE_BIT;
               ENABLE_LCD_TRANSFER_COMPLETE_INT;
               save_irq_mask=SaveAndSetIRQMask();
               #if ((!defined(__MAUI_BASIC__))&& (!defined(__L1_STANDALONE__)))
                  if (tv_output_owner == TV_OUT_OWNER_LCD)
               #endif
                  {
                     lcd_sleeping_state=KAL_FALSE;
                  }
               RestoreIRQMask(save_irq_mask);

               if (sub_lcd_operation_state==LCD_HW_UPDATE_STATE) {
                  sub_lcd_operation_state=LCD_HW_UPDATE_SLEEP_STATE;
                  main_lcd_hw_trigger_output_mode=KAL_FALSE;
               } else if (sub_lcd_operation_state==LCD_DC_UPDATE_STATE) {
                  sub_lcd_operation_state=LCD_DC_UPDATE_SLEEP_STATE;
               }
            } else if ((sub_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
                       (sub_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)) {
               ASSERT(0);
            } else {
               /*clean memory out setting*/
               save_irq_mask=SaveAndSetIRQMask();
               REG_LCD_ROI_CTRL&=~LCD_ROI_CTRL_W2MEM_BIT;
               REG_LCD_ROI_WMEM_CTRL=0;
               RestoreIRQMask(save_irq_mask);
               SubLCD->EnterSleepMode();
               sub_lcd_operation_state=LCD_SLEEP_STATE;
            }
         #else /* no TV_OUT_SUPPORT */
            SubLCD->EnterSleepMode();
            sub_lcd_operation_state=LCD_SLEEP_STATE;
         #endif
         break;
      #endif   /* DUAL_LCD */
      default:
         ASSERT(0);
         break;
   }
   lcd_power_ctrl(KAL_FALSE);
}  /* lcd_sleep_in() */



/**
 * Let LCD module leave sleep mode
 *
 * @param lcd_id selection MAIN_LCD or SUB_LCD
 *
 * @return None.
 */
void lcd_sleep_out(kal_uint8 lcd_id)
{
   kal_uint32 save_irq_mask;

   /// to simplify state machine
   if((main_lcd_operation_state==LCD_DC_UPDATE_STATE)||
      (main_lcd_operation_state==LCD_HW_UPDATE_STATE)||
      (main_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
      (main_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)) {      	
      	return;      	      	
    }

   #if defined(G_SENSOR_SUPPORT)
   //Huyanwei Add It 
   ExitSleep_GSensor();
   #endif
   
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id) {
      case MAIN_LCD:
         #if (!defined(MT6205B)&&!defined(MT6208))
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
         #endif
         #ifdef TV_OUT_SUPPORT
            if((main_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE)||
               (main_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE)) {
               save_irq_mask=SaveAndSetIRQMask();
               lcd_sleeping_state=KAL_TRUE;
               RestoreIRQMask(save_irq_mask);
               #if defined(DRV_IDP_6228_SERIES)
               while (IMGDMA_IBW2_IS_BUSY) {};
               #elif defined(DRV_IDP_6238_SERIES)   
                  /*KKKKK?????, need to more check on 6238, only happened in video decode case*/        
               while (IMGDMA_IBW2_IS_BUSY) {};
               #endif
               IRQMask(IRQ_LCD_CODE);
               LCD_WRITE_MEM_AND_LCM;
               ENABLE_LCD_ROI_CTRL_CMD_FIRST;
               lcd_hw_trigger_roi_ctrl |= LCD_ROI_CTRL_CMD_ENABLE_BIT;
               save_lcd_register();
               REG_LCD_ROI_HW_CTRL = 0;
               MainLCD->ExitSleepMode();
               restore_lcd_register();
               IRQUnmask(IRQ_LCD_CODE);
               save_irq_mask=SaveAndSetIRQMask();
               lcd_sleeping_state=KAL_FALSE;
               RestoreIRQMask(save_irq_mask);
               main_lcd_hw_trigger_output_mode=KAL_TRUE;

               if (main_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE) {
                  main_lcd_operation_state=LCD_DC_UPDATE_STATE;
               } else if (main_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE) {
                  main_lcd_operation_state=LCD_HW_UPDATE_STATE;
               }
            } else {
            	 /*clean memory out setting*/
                 save_irq_mask=SaveAndSetIRQMask();
                 REG_LCD_ROI_CTRL&=~LCD_ROI_CTRL_W2MEM_BIT;
                 REG_LCD_ROI_WMEM_CTRL=0;
                 RestoreIRQMask(save_irq_mask);                         
               MainLCD->ExitSleepMode();            
               main_lcd_operation_state=LCD_STANDBY_STATE;
            }
         #else /* no TV_OUT_SUPPORT */         	
               LSD_TakeControl(LSD_LCDARB_LCD);            
            MainLCD->ExitSleepMode();
            main_lcd_operation_state=LCD_STANDBY_STATE;            
               LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/               
         #endif
         break;
      #ifdef DUAL_LCD
      case SUB_LCD:
         #if (!defined(MT6205B)&&!defined(MT6208))
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
         #endif
         #ifdef TV_OUT_SUPPORT
            if((sub_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE)||
               (sub_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE)) {
               save_irq_mask=SaveAndSetIRQMask();
               lcd_sleeping_state=KAL_TRUE;
               RestoreIRQMask(save_irq_mask);
               #if defined(DRV_IDP_6228_SERIES)   
               while (IMGDMA_IBW2_IS_BUSY) {};
               #elif defined(DRV_IDP_6238_SERIES)   
                  /*KKKKK?????, need to more check on 6238, only happened in video decode case*/        
               while (IMGDMA_IBW2_IS_BUSY) {};
               #endif
               LCD_WRITE_MEM_AND_LCM;
               ENABLE_LCD_ROI_CTRL_CMD_FIRST;
               lcd_hw_trigger_roi_ctrl |= LCD_ROI_CTRL_CMD_ENABLE_BIT;
               save_lcd_register();
               REG_LCD_ROI_HW_CTRL = 0;
               SubLCD->ExitSleepMode();
               restore_lcd_register();
               save_irq_mask=SaveAndSetIRQMask();
               lcd_sleeping_state=KAL_FALSE;
               RestoreIRQMask(save_irq_mask);
               sub_lcd_hw_trigger_output_mode=KAL_TRUE;
               if (sub_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE) {
                  sub_lcd_operation_state=LCD_DC_UPDATE_STATE;
               } else if (sub_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE) {
                  sub_lcd_operation_state=LCD_HW_UPDATE_STATE;
               }
            } else {
               /*clean memory out setting*/
               save_irq_mask=SaveAndSetIRQMask();
               REG_LCD_ROI_CTRL&=~LCD_ROI_CTRL_W2MEM_BIT;
               REG_LCD_ROI_WMEM_CTRL=0;
               RestoreIRQMask(save_irq_mask);
               SubLCD->ExitSleepMode();
               sub_lcd_operation_state=LCD_STANDBY_STATE;
            }
         #else /* no TV_OUT_SUPPORT */
            SubLCD->ExitSleepMode();
            sub_lcd_operation_state=LCD_STANDBY_STATE;
         #endif
         break;
      #endif   /* DUAL_LCD */
      default:
         ASSERT(0);
         break;
   }
   lcd_power_ctrl(KAL_FALSE);
}  /* lcd_sleep_out() */



/**
 * Get frame buffer address
 *
 * @param None.
 *
 * @return address of frame buffer.
 */
kal_uint32 get_lcd_frame_buffer_address(void)
{
   #if (DRV_LAYER_TOTAL_COUNT>1)
      switch (REG_LCD_ROI_CTRL&LCD_LAYER_MASK) {
      case LCD_LAYER0_ENABLE:
         lcd_frame_buffer_address=REG_LCD_LAYER0_BUFF_ADDR;
         break;
      case LCD_LAYER1_ENABLE:
         lcd_frame_buffer_address=REG_LCD_LAYER1_BUFF_ADDR;
         break;
      case LCD_LAYER2_ENABLE:
         lcd_frame_buffer_address=REG_LCD_LAYER2_BUFF_ADDR;
         break;
      case LCD_LAYER3_ENABLE:
         lcd_frame_buffer_address=REG_LCD_LAYER3_BUFF_ADDR;
         break;
      #if (DRV_LAYER_TOTAL_COUNT>4)
      case LCD_LAYER4_ENABLE:
         lcd_frame_buffer_address=REG_LCD_LAYER4_BUFF_ADDR;
         break;
      case LCD_LAYER5_ENABLE:
         lcd_frame_buffer_address=REG_LCD_LAYER5_BUFF_ADDR;
         break;
      #endif/*(DRV_LAYER_TOTAL_COUNT>4)*/
      }
   #endif/*(DRV_LAYER_TOTAL_COUNT>1)*/
   return lcd_frame_buffer_address;
} /* get_lcd_frame_buffer_address */



/**
 * Set hw update layer format
 *
 * @param hw_update_layer hw update layer
 * @param direct_couple direct couple or not
 *
 * @return address of frame buffer.
 */
void set_lcd_dc_layer_format(kal_uint32 hw_update_layer, kal_bool direct_couple)
{
   #if defined(DRV_LAYER_COLOR_FORMAT)      
      if (KAL_TRUE == direct_couple) {
         switch (hw_update_layer) {
         case LCD_LAYER0_ENABLE:
            lcd_dc_color_mode=GET_LCD_LAYER0_COLOR_MODE;
            SET_LCD_LAYER0_ARGB8888_MODE;
            break;
         case LCD_LAYER1_ENABLE:
            lcd_dc_color_mode=GET_LCD_LAYER1_COLOR_MODE;
            SET_LCD_LAYER1_ARGB8888_MODE;
            break;
         case LCD_LAYER2_ENABLE:
            lcd_dc_color_mode=GET_LCD_LAYER2_COLOR_MODE;
            SET_LCD_LAYER2_ARGB8888_MODE;
            break;
         case LCD_LAYER3_ENABLE:
            lcd_dc_color_mode=GET_LCD_LAYER3_COLOR_MODE;
            SET_LCD_LAYER3_ARGB8888_MODE;
            break;
         case LCD_LAYER4_ENABLE:
            lcd_dc_color_mode=GET_LCD_LAYER4_COLOR_MODE;
            SET_LCD_LAYER4_ARGB8888_MODE;
            break;
         case LCD_LAYER5_ENABLE:
            lcd_dc_color_mode=GET_LCD_LAYER5_COLOR_MODE;
            SET_LCD_LAYER5_ARGB8888_MODE;
            break;
         }
      } else {
         ASSERT(KAL_FALSE == direct_couple);
         switch (hw_update_layer) {
         case LCD_LAYER0_ENABLE:
            switch (lcd_dc_color_mode) {
            case LCD_LAYER_SOURCE_COLOR_8BPP_INDEX:
               SET_LCD_LAYER0_8BPP_INDEX_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB565:
               SET_LCD_LAYER0_RGB565_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB888:
               SET_LCD_LAYER0_RGB888_MODE;
               break;
            }
            break;
         case LCD_LAYER1_ENABLE:
            switch (lcd_dc_color_mode) {
            case LCD_LAYER_SOURCE_COLOR_8BPP_INDEX:
               SET_LCD_LAYER1_8BPP_INDEX_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB565:
               SET_LCD_LAYER1_RGB565_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB888:
               SET_LCD_LAYER1_RGB888_MODE;
               break;
            }
            break;
         case LCD_LAYER2_ENABLE:
            switch (lcd_dc_color_mode) {
            case LCD_LAYER_SOURCE_COLOR_8BPP_INDEX:
               SET_LCD_LAYER2_8BPP_INDEX_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB565:
               SET_LCD_LAYER2_RGB565_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB888:
               SET_LCD_LAYER2_RGB888_MODE;
               break;
            }
            break;
         case LCD_LAYER3_ENABLE:
            switch (lcd_dc_color_mode) {
            case LCD_LAYER_SOURCE_COLOR_8BPP_INDEX:
               SET_LCD_LAYER3_8BPP_INDEX_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB565:
               SET_LCD_LAYER3_RGB565_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB888:
               SET_LCD_LAYER3_RGB888_MODE;
               break;
            }
            break;
         case LCD_LAYER4_ENABLE:
            switch (lcd_dc_color_mode) {
            case LCD_LAYER_SOURCE_COLOR_8BPP_INDEX:
               SET_LCD_LAYER4_8BPP_INDEX_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB565:
               SET_LCD_LAYER4_RGB565_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB888:
               SET_LCD_LAYER4_RGB888_MODE;
               break;
            }
            break;
         case LCD_LAYER5_ENABLE:
            switch (lcd_dc_color_mode) {
            case LCD_LAYER_SOURCE_COLOR_8BPP_INDEX:
               SET_LCD_LAYER5_8BPP_INDEX_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB565:
               SET_LCD_LAYER5_RGB565_MODE;
               break;
            case LCD_LAYER_SOURCE_COLOR_RGB888:
               SET_LCD_LAYER5_RGB888_MODE;
               break;
            }
            break;
         }
      }
   #endif
}  /* set_lcd_dc_layer_format() */



/**
 * Disable hw trigger and write to memory
 *
 * @param None.
 *
 * @return None.
 */
void reset_lcd_if(void)
{
   #if (!defined(MT6205B)&&!defined(MT6208))
      lcd_power_ctrl(KAL_TRUE);
      lcd_busy_waiting();
      DISABLE_LCD_ROI_CTRL_W2MEM;
      #if defined(DRV_LCD_HW_TRIGGER_SUPPORT)
         DISABLE_LCD_HW_TRIGGER_UPDATE;
      #endif
   #endif
}



/**
 * Change the lcd DMA transfer rate to slowest rate
 *
 * @param None.
 *
 * @return None.
 */
void lcd_dma_slow_down(kal_uint8 level)
{
   
   #if (defined(MT6205B))
      kal_uint16 bLCDClockWasTurnedOff;
      bLCDClockWasTurnedOff = DRV_Reg(DRVPDN_CON1)&DRVPDN_CON1_LCD;
      if (0!=bLCDClockWasTurnedOff) {// power is not on      	
         lcd_power_ctrl(KAL_TRUE);      
      //// LCD DMA
      DRV_WriteReg(LCD_REFR,0x0fff);      
         lcd_power_ctrl(KAL_FALSE);
      }
      else {// power is on    	
      	 DRV_WriteReg(LCD_REFR,0x0fff);      
      }	
   #else       
      static const kal_uint32 latency[5] = { 0x3F, 0xFF, 0x1FF, 0x2FF, 0x3FF };

      if (KAL_FALSE == bLCDBufferInINTRAM) {
         register kal_uint16 bLCDClockWasTurnedOff = DRV_Reg(DRVPDN_CON1)&DRVPDN_CON1_LCD; /* to speed up */

         if (0!=bLCDClockWasTurnedOff) {// power is not on      	
            lcd_clk_on=KAL_TRUE;
            lcd_turn_on_clock_l1d();         
            SET_LCD_ROI_CTRL_CMD_LATENCY(latency[level]);         
            lcd_clk_on=KAL_FALSE;
            lcd_turn_off_clock_l1d();
         }         
         else {// power is on 
         		SET_LCD_ROI_CTRL_CMD_LATENCY(latency[level]);         
         } 	
         	
      }   
   #endif
}  /* lcd_dma_slow_down() */



/**
 * Change the lcd DMA transfer rate to normal rate
 *
 * @param None.
 *
 * @return None.
 */
void lcd_dma_recovery(void)
{
   #if (defined(MT6205B))
      kal_uint16 bLCDClockWasTurnedOff;
      bLCDClockWasTurnedOff = DRV_Reg(DRVPDN_CON1)&DRVPDN_CON1_LCD;
      if (0!=bLCDClockWasTurnedOff) {// power is not on      
         lcd_power_ctrl(KAL_TRUE);      
      /// LCD DMA
      DRV_WriteReg(LCD_REFR,0x0000);      
         lcd_power_ctrl(KAL_FALSE);
      }
      else {// power is on
      	DRV_WriteReg(LCD_REFR,0x0000);
     } 	
   #else 
      register kal_uint16 bLCDClockWasTurnedOff = DRV_Reg(DRVPDN_CON1)&DRVPDN_CON1_LCD; /* to speed up */
      	      
      if (0!=bLCDClockWasTurnedOff) {// power is not on
         lcd_clk_on=KAL_TRUE;
         lcd_turn_on_clock_l1d();
      	 SET_LCD_ROI_CTRL_CMD_LATENCY(lcd_cmd_period_count);      	 
         lcd_clk_on=KAL_FALSE;
         lcd_turn_off_clock_l1d();
      }      
      else {// power is on
         SET_LCD_ROI_CTRL_CMD_LATENCY(lcd_cmd_period_count);      	
      }	      
   #endif
}  /* lcd_dma_recovery() */



/**
 * Set the driving current of LCM interface
 *
 * @param current the driving current of LCM interface
 *
 * @return None.
 */
void set_lcd_driving_current(kal_uint8 current)
{
   kal_uint32 save_irq_mask;
   kal_uint16 current_value=0;

   switch (current) {
   case LCD_DRIVING_2MA:
      current_value=0;
      break;
   case LCD_DRIVING_4MA:
      current_value=0x06;
      break;
   case LCD_DRIVING_6MA:
      current_value=0x05;
      break;
   case LCD_DRIVING_8MA:
      current_value=0x07;
      break;
   }
   save_irq_mask=SaveAndSetIRQMask();
   #if ( !defined(MT6205B) && !defined(MT6208) )
      CONFIG_LCD_DRIVING_CURRNET(current);
   #endif      
   RestoreIRQMask(save_irq_mask);
}  /* set_lcd_driving_current() */



/*The following interfaces are for GAMMA table*/
/**
 * Configure gamma table
 *
 * @param start_index Update start index of gamma table (0~255)
 * @param size        How many data will be updated (0~255)
 * @param data        Gamma table content data pointer
 * @param table_id    Gamma table ID (0~2)
 *
 * @return None.
 */
void lcd_config_gamma_table(kal_uint8 start_index,
                            kal_uint8 size,
                            kal_uint8 *data,
                            kal_uint8 table_id)
{
   #if defined(DRV_LCD_GAMMA_CORRECTION_SUPPORT)
      kal_uint32 i;
      lcd_power_ctrl(KAL_TRUE);
      for(i=0;i<size;i++) {
         SET_GAMMA_TABLE(table_id,(start_index+i),*(data+i));
      }
   #endif
}
lcd_gamma_table_struct main_gamm_table, sub_gamm_table;



/**
 * Set gamma table for R/G/B color
 *
 * @param lcd_id  MAIN_LCD or SUB_LCD
 * @param r_table Gamma table ID for R channel
 * @param g_table Gamma table ID for G channel
 * @param b_table Gamma table ID for B channel
 *
 * @return None.
 */
void lcd_set_gamma_table(kal_uint8 lcd_id,
                         kal_uint8 r_table,
                         kal_uint8 g_table,
                         kal_uint8 b_table)
{
   #if defined(DRV_LCD_GAMMA_CORRECTION_SUPPORT)
      kal_uint32 lcd_addr=0;

      lcd_power_ctrl(KAL_TRUE);
      if(lcd_id==MAIN_LCD) {
         main_gamm_table.r_table = r_table;
         main_gamm_table.g_table = g_table;
         main_gamm_table.b_table = b_table;
        lcd_addr=MAIN_LCD_CMD_ADDR;
      }
      #ifdef DUAL_LCD
      else if(lcd_id==SUB_LCD) {
         sub_gamm_table.r_table = r_table;
         sub_gamm_table.g_table = g_table;
         sub_gamm_table.b_table = b_table;
         lcd_addr=SUB_LCD_CMD_ADDR;
      }
      #endif
      switch(lcd_addr) {
      case LCD_PARALLEL0_A0_LOW_ADDR:
         SET_LCD_PARALLEL_GAMMA_R_TABLE(r_table<<20);
         SET_LCD_PARALLEL_GAMMA_G_TABLE(g_table<<20);
         SET_LCD_PARALLEL_GAMMA_B_TABLE(b_table<<20);
         break;
      case LCD_PARALLEL1_A0_LOW_ADDR:
         SET_LCD_PARALLEL1_GAMMA_TABLE(r_table<<20);
         break;
      case LCD_PARALLEL2_A0_LOW_ADDR:
         SET_LCD_PARALLEL2_GAMMA_TABLE(r_table<<20);
         break;
      case LCD_SERIAL0_A0_LOW_ADDR:
      case LCD_SERIAL1_A0_LOW_ADDR:
         SET_LCD_SERIAL_GAMMA_TABLE(r_table<<20);
      break;
   }
   #endif
}



/**
 * Enable or disable LCD gamma function.
 *
 * @param lcd_id  MAIN_LCD or SUB_LCD
 * @param enable enable or disable
 *
 * @return None.
 */
void lcd_enable_gamma(kal_uint8 lcd_id, kal_bool enable)
{
   #if defined(DRV_LCD_GAMMA_CORRECTION_SUPPORT)

      kal_uint32 lcd_addr=0;
      lcd_gamma_table_struct *gamm_table;

      gamm_table=NULL;
      lcd_power_ctrl(KAL_TRUE);

      if(MAIN_LCD == lcd_id) {
         lcd_addr=MAIN_LCD_CMD_ADDR;
         gamm_table=&main_gamm_table;
      }
      #ifdef DUAL_LCD
      else {
         ASSERT(SUB_LCD == lcd_id);
         lcd_addr=SUB_LCD_CMD_ADDR;
         gamm_table=&sub_gamm_table;
      }
      #endif
      if(enable) {
         lcd_set_gamma_table(lcd_id, gamm_table->r_table,
                             gamm_table->g_table, gamm_table->b_table);
      } else {
         switch(lcd_addr) {
         case LCD_PARALLEL0_A0_LOW_ADDR:
            SET_LCD_PARALLEL_GAMMA_R_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
            SET_LCD_PARALLEL_GAMMA_G_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
            SET_LCD_PARALLEL_GAMMA_B_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
            break;
         case LCD_PARALLEL1_A0_LOW_ADDR:
            SET_LCD_PARALLEL1_GAMMA_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
            break;
         case LCD_PARALLEL2_A0_LOW_ADDR:
            SET_LCD_PARALLEL2_GAMMA_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
            break;
         case LCD_SERIAL0_A0_LOW_ADDR:
         case LCD_SERIAL1_A0_LOW_ADDR:
            SET_LCD_SERIAL_GAMMA_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
            break;
         }
      }
   #endif
}



/**
 * Wait LCD finish transfer.
 *
 * @param None.
 *
 * @return None.
 */
void lcd_busy_waiting(void)
{
   #if ( !defined(MT6205B) && !defined(MT6208) )
      kal_uint32 time1=0, diff=0;

      time1=drv_get_current_time();
      while(LCD_IS_RUNNING) {
         diff=drv_get_duration_ms(time1);
         if(diff>300) {
            break;
         }
      }
   #endif
}



/**
 * Event Timer Callback Function
 *
 * @param None.
 *
 * @return None.
 */
static void lcd_event_timer_cb(void *parameter)
{
   /// this function is valid only when LCD supporting HW/DC function
   #if defined(DRV_IDP_SUPPORT)
      if(KAL_TRUE == lcd_wait_cmd_event) {
         #ifdef __PRODUCTION_RELEASE__
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            kal_prompt_trace(MOD_MMI, "release MMI event by timer");
         #else
            /// this assert should not happened, find video or camera guy
            if (0 == REG_LCD_ROI_HW_CTRL) {
      	      kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
               kal_prompt_trace(MOD_MMI,"release MMI event by timer, REG_LCD_ROI_HW_CTRL==0");
            } else {
      	      ASSERT(0);/*this assert should not happened, find video or camera guy*/
            }
         #endif
      }
   #endif
}



/**
 * Wait command latch event.
 *
 * @param None.
 *
 * @return None.
 */
void lcd_wait_command_latch(void)
{
   /// this function is valid only when LCD supporting HW/DC function
   #if defined(DRV_IDP_SUPPORT)
      kal_uint32 event_group;
      kal_uint32 save_irq_mask;

      save_irq_mask=SaveAndSetIRQMask();
      
      #ifdef __SYNC_LCM_SW_SUPPORT__
      if (1) {            
      #else      
      if (0 != REG_LCD_ROI_HW_CTRL) {            	
      #endif //__SYNC_LCM_SW_SUPPORT__
         RestoreIRQMask(save_irq_mask);         
         GPTI_StopItem(lcd_event_timer_handle);
         GPTI_StartItem(lcd_event_timer_handle,
                        2000,/*15000ms*/
                        lcd_event_timer_cb,
                        NULL);
         kal_prompt_trace(MOD_MMI,"start event timer");
         lcd_wait_cmd_event=KAL_TRUE;
         kal_retrieve_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT,
                                KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
         kal_prompt_trace(MOD_MMI,"stop event timer");
         GPTI_StopItem(lcd_event_timer_handle);
         lcd_wait_cmd_event=KAL_FALSE;
      }
      else
      {
         RestoreIRQMask(save_irq_mask);
         kal_prompt_trace(MOD_MMI,"HW triiger==0");
      }   
         
   #endif
}
#endif// ifndef __FUE__



#ifdef __FUE__
LCD_Funcs  *MainLCD;
kal_uint16 lcd_cmd_period_count;
void init_fue_lcd(kal_uint16 buff_width, kal_uint16 buff_height, kal_uint32 buff_addr)
{
   kal_uint32 temp_reg;
   kal_uint16 lcm_startx,lcm_starty,lcm_endx,lcm_endy;

   LCD_FunConfig();

   /// power on LCD
   DRV_Reg(DRVPDN_CON1_CLR) = DRVPDN_CON1_LCD;
   #if (!defined(MT6205B)&&!defined(MT6208))
     init_lcd_interface();
   #endif

   /// remove LCD int status
   temp_reg=DRV_Reg(LCD_INT_STATUS_REG);

   REG_LCD_LAYER0_CTRL=0;/// disable all feature
   DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
   DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
   SET_LCD_ROI_CTRL_OUTPUT_FORMAT(MAIN_LCD_OUTPUT_FORMAT);
   MainLCD->Init(0,0);
   
   REG_LCD_INT_ENABLE=0;
   SET_LCD_MAIN_WINDOW_SIZE(LCD_WIDTH,LCD_HEIGHT);

   #ifdef DRV_LCD_MEMORY_OUTPUT
      REG_LCD_ROI_WMEM_OFFSET=0;
      REG_LCD_ROI_WMEM_CTRL=0;
   #endif /*DRV_LCD_MEMORY_OUTPUT*/
   REG_LCD_ROI_OFFSET=0;
   SET_LCD_ROI_WINDOW_SIZE(buff_width,buff_height);
   
   REG_LCD_ROI_CTRL |= LCD_ROI_CTRL_LAYER0_ENABLE_BIT;
   DISABLE_LCD_ROI_CTRL_W2MEM;

   #if (!defined(MT6205B)&&!defined(MT6208))
      DISABLE_LAYER0_READ_DATA_SWAP;
   #endif
   #if defined(DRV_LAYER_COLOR_FORMAT)         
      SET_LCD_LAYER0_RGB565_MODE;
   #endif   
   DISABLE_LCD_LAYER0_OPACITY;
   DISABLE_LCD_LAYER0_SOURCE_KEY;
   DISABLE_LCD_HW_TRIGGER_UPDATE;
   SET_LCD_LAYER0_ROTATE(LCD_LAYER_ROTATE_NORMAL);
   SET_LCD_LAYER0_WINDOW_OFFSET(0,0);
   SET_LCD_LAYER0_WINDOW_SIZE(buff_width,buff_height);
   REG_LCD_LAYER0_BUFF_ADDR=buff_addr;

   lcm_startx=(LCD_WIDTH-buff_width)>>1;
   lcm_endx=(lcm_startx+buff_width-1);
   lcm_starty=(LCD_HEIGHT-buff_height)>>1;
   lcm_endy=(lcm_starty+buff_height-1);
   MainLCD->BlockWrite(lcm_startx,lcm_starty,lcm_endx,lcm_endy);
   while (LCD_IS_RUNNING)
   {};
}  /* init_fue_lcd() */

void update_fue_lcd(void)
{
   START_LCD_TRANSFER;
}
#endif   /* __FUE__ */
