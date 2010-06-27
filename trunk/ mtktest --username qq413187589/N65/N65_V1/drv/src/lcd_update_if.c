/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003-2007
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
 *   lcd_update_if.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Lcd update interface
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * solve compile error.
 *
 * removed!
 * removed!
 * separate lcd_fb_update for different series of chips.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * fix compile error for sub lcd.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * Add LCD driver feature: background color and memory output
 *
 * removed!
 * removed!
 * deprecate lcd_power_[up|down], use lcd_power_ctrl instead.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * Phase out 6218B.
 *
 * removed!
 * removed!
 * Update header to log check-in records.
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "lcd_sw_inc.h"
#include "lcd_hw.h"
#include "lcd_sw.h"
#include "lcd_if.h"
#include "visual_comm.h"
#include "drv_hisr.h"

#ifdef __SYNC_LCM_SW_SUPPORT__
extern MMDI_SCENERIO_ID current_image_data_path_owner;
#endif

/// for external camera
#include "ext_camera.h"

#include "img_comm.h"
#if defined(DRV_IDP_SUPPORT)
   #include "visual_comm.h"
   #include "imgproc.h"
   #include "imgdma.h"
   #if (defined(ISP_SUPPORT))
      #include "isp_if.h"
   #endif
   #ifdef TV_OUT_SUPPORT
      #include "tv_out.h"
      #include "2d_engine.h"
   #endif
#endif

#include "msdc_lsd.h"

extern kal_bool lcd_assert_fail;

#ifdef TV_OUT_SUPPORT
   kal_uint32 tv_output_replace_data;
   extern g2d_buffer_struct g2d_tv_output_dest_buff;
   extern g2d_buffer_struct g2d_tv_output_src_buff;
   extern g2d_bitblt_struct g2d_tv_output_bitblt;
   extern kal_uint8 current_g2d_tv_output_bitblt_buffer;
#endif

kal_uint32 lcd_preview_count = 0;
kal_uint8 lcd_fw_update_layer = 0;
kal_bool  lcd_wait_fw_update_event=KAL_FALSE;

#ifdef __SYNC_LCM_SW_SUPPORT__
   kal_uint8 wait_lcd_config_flag = KAL_FALSE;
   kal_uint8 wait_lcd_restore_config_flag = KAL_FALSE;
#endif



#if ((!defined(MT6205B))&&(!defined(MT6208)))
static void _lcd_wait_for_lcd_ready(void)
{
   /// wait until LCD complete
   if (KAL_TRUE == bWaitForLCDUpdate) {
      lcd_busy_waiting();
      /// XXX: why not wait until bWaitForLCDUpdate is KAL_FALSE
      IRQMask(IRQ_LCD_CODE);
      if (KAL_TRUE == bWaitForLCDUpdate) {
         bWaitForLCDUpdate = KAL_FALSE;
         if (LCD_SW_UPDATE_STATE == main_lcd_operation_state) {
            main_lcd_operation_state = LCD_STANDBY_STATE;
         }
         if (LCD_SW_UPDATE_STATE == sub_lcd_operation_state) {
            sub_lcd_operation_state = LCD_STANDBY_STATE;
         }
         config_lcd_layer_window_queue();
         if (lcd_prev_run_block_cb != NULL) {
            lcd_prev_run_block_cb();
         }
      }
      IRQUnmask(IRQ_LCD_CODE);
   }
}
#endif



/**
 * if all of the layers to be updated reside in internal memory,
 * bLCDBufferInINTRAM will be KAL_TRUE;
 * otherwise, it will be KAL_FALSE.
 *
 */
#if ((!defined(MT6205B))&&(!defined(MT6208)))
static void _lcd_check_lcd_buffer_in_intram(lcd_frame_update_struct *lcd_para)
{
   bLCDBufferInINTRAM = KAL_TRUE;

   if (lcd_para->update_layer & LCD_LAYER0_ENABLE) {
      if (!(REG_LCD_LAYER0_BUFF_ADDR & 0x40000000)) {
         bLCDBufferInINTRAM = KAL_FALSE;
      }
   }
   if (lcd_para->update_layer & LCD_LAYER1_ENABLE) {
      if (!(REG_LCD_LAYER1_BUFF_ADDR & 0x40000000)) {
         bLCDBufferInINTRAM = KAL_FALSE;
      }
   }
   if (lcd_para->update_layer & LCD_LAYER2_ENABLE) {
      if (!(REG_LCD_LAYER2_BUFF_ADDR & 0x40000000)) {
         bLCDBufferInINTRAM = KAL_FALSE;
      }
   }
   if (lcd_para->update_layer & LCD_LAYER3_ENABLE) {
      if (!(REG_LCD_LAYER3_BUFF_ADDR & 0x40000000)) {
         bLCDBufferInINTRAM = KAL_FALSE;
      }
   }
   #if (DRV_LAYER_TOTAL_COUNT > 4)
   if (lcd_para->update_layer & LCD_LAYER4_ENABLE) {
      if (!(REG_LCD_LAYER4_BUFF_ADDR & 0x40000000)) {
         bLCDBufferInINTRAM = KAL_FALSE;
      }
   }
   if (lcd_para->update_layer & LCD_LAYER5_ENABLE) {
      if (!(REG_LCD_LAYER5_BUFF_ADDR & 0x40000000)) {
         bLCDBufferInINTRAM = KAL_FALSE;
      }
   }
   #endif
}
#endif



#if (defined(MT6217)||defined(MT6223)||defined(MT6223P)||defined(MT6225))
static void _lcd_prepare_update_para(lcd_frame_update_struct *lcd_para)
{
   if ((MAIN_LCD == jpeg_video_play_lcd_id)||
       (MAIN_LCD == current_update_lcd)) {
      ASSERT(MAIN_LCD == lcd_para->lcd_id);
      main_lcd_fb_update_para.lcd_id = MAIN_LCD;
      main_lcd_fb_update_para.module_id = lcd_para->module_id;
      main_lcd_fb_update_para.fb_update_mode = lcd_para->fb_update_mode;
      /// make sure MMI update must exceed FW update size
      if (main_lcd_fb_update_para.lcm_start_x < lcd_para->lcm_start_x) {
         lcd_para->lcm_start_x = main_lcd_fb_update_para.lcm_start_x;
      }
      if (main_lcd_fb_update_para.lcm_start_y<lcd_para->lcm_start_y) {
         lcd_para->lcm_start_y = main_lcd_fb_update_para.lcm_start_y;
      }
      if (main_lcd_fb_update_para.lcm_end_x>lcd_para->lcm_end_x) {
         lcd_para->lcm_end_x = main_lcd_fb_update_para.lcm_end_x;
      }
      if (main_lcd_fb_update_para.lcm_end_y>lcd_para->lcm_end_y) {
         lcd_para->lcm_end_y = main_lcd_fb_update_para.lcm_end_y;
      }
      if (main_lcd_fb_update_para.roi_offset_x<lcd_para->roi_offset_x) {
         lcd_para->roi_offset_x = main_lcd_fb_update_para.roi_offset_x;
      }
      if (main_lcd_fb_update_para.roi_offset_y<lcd_para->roi_offset_y) {
         lcd_para->roi_offset_y = main_lcd_fb_update_para.roi_offset_y;
      }
      main_lcd_fb_update_para.lcm_start_x = lcd_para->lcm_start_x;
      main_lcd_fb_update_para.lcm_start_y = lcd_para->lcm_start_y;
      main_lcd_fb_update_para.lcm_end_x = lcd_para->lcm_end_x;
      main_lcd_fb_update_para.lcm_end_y = lcd_para->lcm_end_y;
      main_lcd_fb_update_para.roi_offset_x = lcd_para->roi_offset_x;
      main_lcd_fb_update_para.roi_offset_y = lcd_para->roi_offset_y;
      main_lcd_fb_update_para.update_layer = lcd_para->update_layer;
      #ifdef DRV_LCD_ROI_BACKGROUND_COLOR
         main_lcd_fb_update_para.roi_background_color=lcd_para->roi_background_color;
      #endif
      if (LCD_FW_UPDATE_STATE == main_lcd_operation_state) {
         main_lcd_operation_state = LCD_FW_CMD_QUEUE_STATE;
      } else if (LCD_JPEG_VIDEO_UPDATE_STATE == main_lcd_operation_state){
         main_lcd_operation_state = LCD_JPEG_VIDEO_CMD_QUEUE_STATE;
      }
      lcd_wait_fw_update_event=KAL_TRUE;
   } else if ((SUB_LCD == jpeg_video_play_lcd_id) ||
              (SUB_LCD == current_update_lcd)) {
      ASSERT(SUB_LCD == lcd_para->lcd_id);
      sub_lcd_fb_update_para.lcd_id = SUB_LCD;
      sub_lcd_fb_update_para.module_id = lcd_para->module_id;
      sub_lcd_fb_update_para.fb_update_mode=lcd_para->fb_update_mode;
      /// make sure MMI update must exceed FW update size
      if (sub_lcd_fb_update_para.lcm_start_x < lcd_para->lcm_start_x) {
         lcd_para->lcm_start_x = sub_lcd_fb_update_para.lcm_start_x;
      }
      if (sub_lcd_fb_update_para.lcm_start_y < lcd_para->lcm_start_y) {
         lcd_para->lcm_start_y = sub_lcd_fb_update_para.lcm_start_y;
      }
      if (sub_lcd_fb_update_para.lcm_end_x > lcd_para->lcm_end_x) {
         lcd_para->lcm_end_x = sub_lcd_fb_update_para.lcm_end_x;
      }
      if (sub_lcd_fb_update_para.lcm_end_y > lcd_para->lcm_end_y) {
         lcd_para->lcm_end_y = sub_lcd_fb_update_para.lcm_end_y;
      }
      if (sub_lcd_fb_update_para.roi_offset_x < lcd_para->roi_offset_x) {
         lcd_para->roi_offset_x = sub_lcd_fb_update_para.roi_offset_x;
      }
      if (sub_lcd_fb_update_para.roi_offset_y < lcd_para->roi_offset_y) {
         lcd_para->roi_offset_y = sub_lcd_fb_update_para.roi_offset_y;
      }

      sub_lcd_fb_update_para.lcm_start_x = lcd_para->lcm_start_x;
      sub_lcd_fb_update_para.lcm_start_y = lcd_para->lcm_start_y;
      sub_lcd_fb_update_para.lcm_end_x = lcd_para->lcm_end_x;
      sub_lcd_fb_update_para.lcm_end_y = lcd_para->lcm_end_y;
      sub_lcd_fb_update_para.roi_offset_x = lcd_para->roi_offset_x;
      sub_lcd_fb_update_para.roi_offset_y = lcd_para->roi_offset_y;
      sub_lcd_fb_update_para.update_layer = lcd_para->update_layer;
      #ifdef DRV_LCD_ROI_BACKGROUND_COLOR
        sub_lcd_fb_update_para.roi_background_color = lcd_para->roi_background_color;
      #endif
      if (LCD_FW_UPDATE_STATE == sub_lcd_operation_state) {
         sub_lcd_operation_state = LCD_FW_CMD_QUEUE_STATE;
      } else if (LCD_JPEG_VIDEO_UPDATE_STATE == sub_lcd_operation_state){
         sub_lcd_operation_state = LCD_JPEG_VIDEO_CMD_QUEUE_STATE;
      }
      lcd_wait_fw_update_event = KAL_TRUE;
   }
}

static void lcd_fb_update_17_23_25_series(lcd_frame_update_struct *lcd_para)
{
   kal_uint32 temp_reg;
   kal_uint32 i;
   volatile kal_uint32 j;
   kal_uint32 save_irq_mask;
   kal_uint32 event_group;

   if (LCD_UPDATE_MODULE_MMI == lcd_para->module_id) {
      save_irq_mask = SaveAndSetIRQMask();
      if ((LCD_JPEG_VIDEO_UPDATE_STATE == main_lcd_operation_state) ||
          (LCD_JPEG_VIDEO_CMD_QUEUE_STATE == main_lcd_operation_state) ||
          (LCD_FW_UPDATE_STATE == main_lcd_operation_state) ||
          (LCD_FW_CMD_QUEUE_STATE == main_lcd_operation_state) ||
          (LCD_JPEG_VIDEO_UPDATE_STATE == sub_lcd_operation_state)||
          (LCD_JPEG_VIDEO_CMD_QUEUE_STATE == sub_lcd_operation_state)||
          (LCD_FW_UPDATE_STATE == sub_lcd_operation_state)||
          (LCD_FW_CMD_QUEUE_STATE == sub_lcd_operation_state)) {

         _lcd_prepare_update_para(lcd_para);

         RestoreIRQMask(save_irq_mask);

         kal_set_eg_events(lcd_event_id, 0, KAL_AND);
         kal_retrieve_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR_CONSUME,
                                &event_group, KAL_SUSPEND);
         lcd_wait_fw_update_event = KAL_FALSE;
         return;
      } else {
         RestoreIRQMask(save_irq_mask);
      }
   }

   #if defined(DRV_LCD_FW_UPDATE_SUPPORT)
      if (LCD_UPDATE_MODULE_MEDIA == lcd_para->module_id) {

         if((LCD_HW_TRIGGER_MODE == lcd_para->fb_update_mode)||
            (LCD_DIRECT_COUPLE_MODE == lcd_para->fb_update_mode)) {
            #ifndef DUAL_LCD
               if (LCD_SW_UPDATE_STATE == main_lcd_operation_state) {
                  do {
                     kal_sleep_task(1);
                  } while (main_lcd_operation_state != LCD_STANDBY_STATE);
               }
            #else
               if ((LCD_SW_UPDATE_STATE == main_lcd_operation_state)||
                   (LCD_SW_UPDATE_STATE == sub_lcd_operation_state)) {
                  do {
                     kal_sleep_task(1);
                  } while ((main_lcd_operation_state != LCD_STANDBY_STATE)||
                           (sub_lcd_operation_state != LCD_STANDBY_STATE));
               }
            #endif

            if (MAIN_LCD == lcd_para->lcd_id) {
               main_lcd_operation_state = LCD_FW_CMD_QUEUE_STATE;
            }
            #ifdef DUAL_LCD
               else if (SUB_LCD == lcd_para->lcd_id) {
                  sub_lcd_operation_state = LCD_FW_CMD_QUEUE_STATE;
               }
            #endif
         }

         switch(lcd_para->hw_update_layer) {
         case LCD_LAYER0_ENABLE:
            lcd_fw_update_layer=LCD_LAYER0;
            break;
         case LCD_LAYER1_ENABLE:
            lcd_fw_update_layer=LCD_LAYER1;
            break;
         case LCD_LAYER2_ENABLE:
            lcd_fw_update_layer=LCD_LAYER2;
            break;
         case LCD_LAYER3_ENABLE:
            lcd_fw_update_layer=LCD_LAYER3;
            break;
         }
      }
   #endif/*MT6225*/

   #if (defined(CAMERA_MODULE))
      if (LCD_UPDATE_MODULE_MMI == lcd_para->module_id) {
         #ifdef CAMERA_MODULE_WITH_LCD
            save_irq_mask=SaveAndSetIRQMask();
            if (LCD_CAMERA_ACTIVE_STATE == main_lcd_operation_state) {
               RestoreIRQMask(save_irq_mask);
                  ext_cam_update_backend_lcd_buffer(lcd_para);
               return;
            } else {
               RestoreIRQMask(save_irq_mask);
            }
         #endif
         kal_set_eg_events(lcd_event_id, 0, KAL_AND);
         save_irq_mask = SaveAndSetIRQMask();
         #ifndef DUAL_LCD
            if ((LCD_CAMERA_UPDATE_STATE == main_lcd_operation_state) ||
                (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state))
         #else
            if ((LCD_CAMERA_UPDATE_STATE == main_lcd_operation_state) ||
                (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state) ||
                (LCD_CAMERA_UPDATE_STATE == sub_lcd_operation_state) ||
                (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state))
         #endif
         {
            if (MAIN_LCD == current_update_lcd) {
               /// do not check while LCD is mount on external camera
               #ifndef CAMERA_MODULE_WITH_LCD
                  ASSERT(MAIN_LCD == lcd_para->lcd_id);
               #endif
               main_lcd_fb_update_para.lcd_id=MAIN_LCD;
               main_lcd_fb_update_para.module_id=lcd_para->module_id;
               main_lcd_fb_update_para.fb_update_mode=lcd_para->fb_update_mode;
               main_lcd_fb_update_para.lcm_start_x=lcd_para->lcm_start_x;
               main_lcd_fb_update_para.lcm_start_y=lcd_para->lcm_start_y;
               main_lcd_fb_update_para.lcm_end_x=lcd_para->lcm_end_x;
               main_lcd_fb_update_para.lcm_end_y=lcd_para->lcm_end_y;
               main_lcd_fb_update_para.roi_offset_x=lcd_para->roi_offset_x;
               main_lcd_fb_update_para.roi_offset_y=lcd_para->roi_offset_y;
               main_lcd_fb_update_para.update_layer=lcd_para->update_layer;
               main_lcd_operation_state = LCD_CAMERA_CMD_QUEUE_STATE;
            } else if (SUB_LCD == current_update_lcd) {
               /// do not check while LCD is mount on external camera
               #ifndef CAMERA_MODULE_WITH_LCD
                  ASSERT(SUB_LCD == lcd_para->lcd_id);
               #endif
               sub_lcd_fb_update_para.lcd_id=SUB_LCD;
               sub_lcd_fb_update_para.module_id=lcd_para->module_id;
               sub_lcd_fb_update_para.fb_update_mode=lcd_para->fb_update_mode;
               sub_lcd_fb_update_para.lcm_start_x=lcd_para->lcm_start_x;
               sub_lcd_fb_update_para.lcm_start_y=lcd_para->lcm_start_y;
               sub_lcd_fb_update_para.lcm_end_x=lcd_para->lcm_end_x;
               sub_lcd_fb_update_para.lcm_end_y=lcd_para->lcm_end_y;
               sub_lcd_fb_update_para.roi_offset_x=lcd_para->roi_offset_x;
               sub_lcd_fb_update_para.roi_offset_y=lcd_para->roi_offset_y;
               sub_lcd_fb_update_para.update_layer=lcd_para->update_layer;
               sub_lcd_operation_state=LCD_CAMERA_CMD_QUEUE_STATE;
            }
            RestoreIRQMask(save_irq_mask);
            kal_retrieve_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR_CONSUME,
                                   &event_group, KAL_SUSPEND);
            if ((MAIN_LCD == current_update_lcd) &&
                (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state) &&
                (main_lcd_operation_state!=LCD_STANDBY_STATE)) {
               main_lcd_operation_state = LCD_CAMERA_UPDATE_STATE;
            } else if ((SUB_LCD == current_update_lcd) &&
                       (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state) &&
                       (sub_lcd_operation_state!=LCD_STANDBY_STATE)) {
                       sub_lcd_operation_state = LCD_CAMERA_UPDATE_STATE;
            }
            return;
         } else {
            RestoreIRQMask(save_irq_mask);
         }
      }
   #endif /* CAMERA_MODULE */
/* 2009.05.09 opened by hongzhe.liu for tv reset + */
	while(LCD_IS_RUNNING){ kal_sleep_task(1);};
/* 2009.05.09 opened by hongzhe.liu for tv reset - */
	    ASSERT(0 == LCD_IS_RUNNING);

   lcd_power_ctrl(KAL_TRUE);
   ENABLE_LCD_TRANSFER_COMPLETE_INT;
   lcd_transfer_complete = KAL_FALSE;
   #ifdef DRV_LCD_ROI_BACKGROUND_COLOR
      REG_LCD_ROI_BACKGROUND_COLOR = lcd_para->roi_background_color;
   #endif
   SET_LCD_ROI_WINDOW_OFFSET(lcd_para->roi_offset_x, lcd_para->roi_offset_y);
   SET_LCD_ROI_WINDOW_SIZE(lcd_para->lcm_end_x-lcd_para->lcm_start_x+1,
                           lcd_para->lcm_end_y-lcd_para->lcm_start_y+1);
   SET_LCD_ENABLE_LAYER(lcd_para->update_layer);
   DISABLE_LCD_ROI_CTRL_W2MEM;

   switch (lcd_para->lcd_id) {
   case MAIN_LCD:
      switch (main_lcd_operation_state) {
      case LCD_SLEEP_STATE:
         lcd_power_ctrl(KAL_FALSE);
         return;
      case LCD_CAMERA_CMD_QUEUE_STATE:
         config_lcd_layer_window_queue();
         main_lcd_operation_state = LCD_CAMERA_UPDATE_STATE;
         break;
      case LCD_JPEG_VIDEO_CMD_QUEUE_STATE:
         config_lcd_layer_window_queue();
         main_lcd_operation_state = LCD_JPEG_VIDEO_UPDATE_STATE;
         break;
      case LCD_FW_CMD_QUEUE_STATE:
         config_lcd_layer_window_queue();
         main_lcd_operation_state = LCD_FW_UPDATE_STATE;
         break;
      }
      save_irq_mask=SaveAndSetIRQMask();
      #if (defined(CAMERA_MODULE))
         if ((main_lcd_operation_state!=LCD_CAMERA_UPDATE_STATE) &&
             (main_lcd_operation_state!=LCD_JPEG_VIDEO_UPDATE_STATE) &&
             (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
            main_lcd_operation_state=LCD_SW_UPDATE_STATE;
         }
      #else
         if ((main_lcd_operation_state!=LCD_JPEG_VIDEO_UPDATE_STATE) &&
            (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
            main_lcd_operation_state=LCD_SW_UPDATE_STATE;
         }
      #endif   /* CAMERA_MODULE */
      RestoreIRQMask(save_irq_mask);

      SET_LCD_ROI_CTRL_OUTPUT_FORMAT(MAIN_LCD_OUTPUT_FORMAT);
      DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
      DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
      LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
      MainLCD->BlockWrite(lcd_para->lcm_start_x,lcd_para->lcm_start_y,
                          lcd_para->lcm_end_x,lcd_para->lcm_end_y);
      #if defined(DRV_LCD_FW_UPDATE_SUPPORT)/*support LCD_FW_UPDATE_STATE*/
         if((LCD_HW_TRIGGER_MODE == lcd_para->fb_update_mode)||
            (LCD_DIRECT_COUPLE_MODE == lcd_para->fb_update_mode)) {
            lcd_hw_trigger_layer=lcd_para->hw_update_layer;
            lcd_hw_trigger_roi_offset=DRV_Reg32(LCD_ROI_OFFSET_REG);
            lcd_hw_trigger_roi_size=DRV_Reg32(LCD_ROI_SIZE_REG);
            lcd_hw_trigger_roi_ctrl=DRV_Reg32(LCD_ROI_CTRL_REG);
            lcd_hw_trigger_flag=KAL_FALSE;
            for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++) {
               lcd_hw_trigger_para[i]=DRV_Reg32(LCD_CMD_PARAMETER_ADDR+(i<<2));
            }
            main_lcd_fb_update_para.lcm_start_x=lcd_para->lcm_start_x;
            main_lcd_fb_update_para.lcm_start_y=lcd_para->lcm_start_y;
            main_lcd_fb_update_para.lcm_end_x=lcd_para->lcm_end_x;
            main_lcd_fb_update_para.lcm_end_y=lcd_para->lcm_end_y;
            main_lcd_fb_update_para.roi_offset_x=lcd_para->roi_offset_x;
            main_lcd_fb_update_para.roi_offset_y=lcd_para->roi_offset_y;
         }
      #endif
      for (j=0;j<100;j++);

      break;
   #ifdef DUAL_LCD
      case SUB_LCD:
         switch(sub_lcd_operation_state) {
         case LCD_SLEEP_STATE:
            lcd_power_ctrl(KAL_FALSE);
            return;
         case LCD_CAMERA_CMD_QUEUE_STATE:
            config_lcd_layer_window_queue();
            sub_lcd_operation_state = LCD_CAMERA_UPDATE_STATE;
            break;
         case LCD_JPEG_VIDEO_CMD_QUEUE_STATE:
            config_lcd_layer_window_queue();
            sub_lcd_operation_state = LCD_JPEG_VIDEO_UPDATE_STATE;
            break;
         }
         #if (defined(CAMERA_MODULE))
            if ((sub_lcd_operation_state!=LCD_CAMERA_UPDATE_STATE) &&
                (sub_lcd_operation_state!=LCD_FW_UPDATE_STATE) &&
                (sub_lcd_operation_state!=LCD_JPEG_VIDEO_UPDATE_STATE)) {
               sub_lcd_operation_state=LCD_SW_UPDATE_STATE;
            }
         #else
            if ((sub_lcd_operation_state!=LCD_JPEG_VIDEO_UPDATE_STATE) &&
                (sub_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
               sub_lcd_operation_state=LCD_SW_UPDATE_STATE;
            }
         #endif
         SET_LCD_ROI_CTRL_OUTPUT_FORMAT(SUB_LCD_OUTPUT_FORMAT);
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG, SUB_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG, SUB_LCD_DATA_ADDR);
         SubLCD->BlockWrite(lcd_para->lcm_start_x, lcd_para->lcm_start_y,
                            lcd_para->lcm_end_x, lcd_para->lcm_end_y);
         #if defined(DRV_LCD_FW_UPDATE_SUPPORT)/*support LCD_FW_UPDATE_STATE*/
            if((LCD_HW_TRIGGER_MODE == lcd_para->fb_update_mode) ||
               (LCD_DIRECT_COUPLE_MODE == lcd_para->fb_update_mode)) {
               lcd_hw_trigger_layer=lcd_para->hw_update_layer;
               lcd_hw_trigger_roi_offset=DRV_Reg32(LCD_ROI_OFFSET_REG);
               lcd_hw_trigger_roi_size=DRV_Reg32(LCD_ROI_SIZE_REG);
               lcd_hw_trigger_roi_ctrl=DRV_Reg32(LCD_ROI_CTRL_REG);
               lcd_hw_trigger_flag=KAL_FALSE;
               for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++) {
                  lcd_hw_trigger_para[i]=DRV_Reg32(LCD_CMD_PARAMETER_ADDR+(i<<2));
               }

               sub_lcd_fb_update_para.lcm_start_x=lcd_para->lcm_start_x;
               sub_lcd_fb_update_para.lcm_start_y=lcd_para->lcm_start_y;
               sub_lcd_fb_update_para.lcm_end_x=lcd_para->lcm_end_x;
               sub_lcd_fb_update_para.lcm_end_y=lcd_para->lcm_end_y;
               sub_lcd_fb_update_para.roi_offset_x=lcd_para->roi_offset_x;
               sub_lcd_fb_update_para.roi_offset_y=lcd_para->roi_offset_y;
            }
         #endif
         for (j=0;j<10;j++);
         break;
   #endif   /* DUAL_LCD */
   }

   current_update_lcd = lcd_para->lcd_id;

   if (KAL_TRUE == lcd_para->block_mode_flag) {
      IRQMask(IRQ_LCD_CODE);
      bWaitForLCDUpdate = KAL_FALSE;
      IRQUnmask(IRQ_LCD_CODE);

      lcd_busy_waiting();
      temp_reg=DRV_Reg(LCD_INT_STATUS_REG);

      if (MAIN_LCD == current_update_lcd) {
         if (LCD_SW_UPDATE_STATE == main_lcd_operation_state) {
            main_lcd_operation_state = LCD_STANDBY_STATE;
         }
      } else {
         if (LCD_SW_UPDATE_STATE == sub_lcd_operation_state) {
            sub_lcd_operation_state = LCD_STANDBY_STATE;
         }
      }
   } else {
      lcd_prev_run_block_cb = lcd_para->lcd_block_mode_cb;
      IRQMask(IRQ_LCD_CODE);
      bWaitForLCDUpdate = KAL_TRUE;
      IRQUnmask(IRQ_LCD_CODE);
   }

   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_FALSE);
}
#endif



#if defined(DRV_IDP_SUPPORT)//(defined(MT6219)||defined(MT6226)||defined(MT6226D)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6228)||defined(MT6229)||defined(MT6230)||defined(MT6268T))
static void lcd_fb_update_19_26_28_series(lcd_frame_update_struct *lcd_para)
{
   kal_uint32 temp_reg;
   kal_uint32 i;
   volatile kal_uint32 j;
   kal_uint32 save_irq_mask;
   kal_uint32 roi_width, roi_height;
   kal_uint32 roi_mem_out_width, roi_mem_out_height;

   lcd_power_ctrl(KAL_TRUE);
   lcd_roi_offset_shadow = DRV_Reg32(LCD_ROI_OFFSET_REG);
   lcd_roi_ctrl_shadow = DRV_Reg32(LCD_ROI_CTRL_REG);
   lcd_roi_ctrl_shadow |= LCD_ROI_CTRL_CMD_ENABLE_BIT;
   lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_W2MEM_BIT;
   lcd_roi_size_shadow = DRV_Reg32(LCD_ROI_SIZE_REG);
   #if (defined(DRV_LCD_MEMORY_OUTPUT))
      lcd_mem_out_address_shadow=DRV_Reg32(LCD_ROI_WMEM_ADDR_REG);
      lcd_mem_out_ctrl_shadow=DRV_Reg32(LCD_ROI_WMEM_CTRL_REG);
   #endif

   /// only SW trigger mode is permitted for MMI task
   if (LCD_UPDATE_MODULE_MMI == lcd_para->module_id) {
      ASSERT(LCD_SW_TRIGGER_MODE == lcd_para->fb_update_mode);
   }

   if ((LCD_HW_TRIGGER_MODE == lcd_para->fb_update_mode)||
       (LCD_DIRECT_COUPLE_MODE == lcd_para->fb_update_mode)) {
      /// only accept when both MAIN_LCD and SUB_LCD in LCD_STANDBY_STATE for
      /// LCD_HW_TRIGGER_MODE and LCD_DIRECT_COUPLE_MODE
      #ifndef DUAL_LCD
         if (LCD_SW_UPDATE_STATE == main_lcd_operation_state) {
            do {
               kal_sleep_task(1);
            } while (main_lcd_operation_state != LCD_STANDBY_STATE);
         }
      #else
         if ((LCD_SW_UPDATE_STATE == main_lcd_operation_state) ||
             (LCD_SW_UPDATE_STATE == sub_lcd_operation_state)) {
            do {
               kal_sleep_task(1);
            } while ((main_lcd_operation_state != LCD_STANDBY_STATE)||
                     (sub_lcd_operation_state != LCD_STANDBY_STATE));
         }
      #endif
      #ifdef TV_OUT_SUPPORT
         #ifndef DUAL_LCD
            if ((main_lcd_operation_state!=LCD_STANDBY_STATE)&&
                (main_lcd_operation_state!=LCD_SLEEP_STATE)) {
               ASSERT(0);
            }
         #else
            if (((main_lcd_operation_state!=LCD_STANDBY_STATE)&&
                 (main_lcd_operation_state!=LCD_SLEEP_STATE))||
                ((sub_lcd_operation_state!=LCD_STANDBY_STATE)&&
                 (sub_lcd_operation_state!=LCD_SLEEP_STATE))) {
               ASSERT(0);
            }
         #endif
      #else
         #ifndef DUAL_LCD
            ASSERT(LCD_STANDBY_STATE == main_lcd_operation_state);
         #else
            ASSERT((LCD_STANDBY_STATE == main_lcd_operation_state) &&
                   (LCD_STANDBY_STATE == sub_lcd_operation_state));
         #endif
      #endif
   } else if (LCD_SW_TRIGGER_MODE == lcd_para->fb_update_mode) {
      #ifndef DUAL_LCD
         #if (!defined(DRV_LCD_MEMORY_OUTPUT))
            if (main_lcd_operation_state==LCD_SLEEP_STATE)
         #else
            if ((main_lcd_operation_state==LCD_SLEEP_STATE)&&(lcd_para->memory_output==KAL_FALSE))
         #endif
         {
            lcd_power_ctrl(KAL_FALSE);
            return;
         }
         if ((main_lcd_operation_state!=LCD_STANDBY_STATE)&&
             (main_lcd_operation_state!=LCD_SLEEP_STATE)&&
             (main_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
             #ifdef TV_OUT_SUPPORT
                (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                (main_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
             #endif
             (main_lcd_operation_state!=LCD_DC_UPDATE_STATE)) {
            ASSERT(0);
         }
         #ifdef __VIDEO_EDITOR__
         if (LCD_MEM_UPDATE_STATE == main_lcd_operation_state) {
            do {
               kal_sleep_task(1);
            } while (main_lcd_operation_state != LCD_MEM_UPDATE_STATE);
         }
         #endif
      #else
         if (MAIN_LCD == lcd_para->lcd_id) {
            #if (!defined(DRV_LCD_MEMORY_OUTPUT))
               if (LCD_SLEEP_STATE == main_lcd_operation_state)
            #else
               if ((LCD_SLEEP_STATE == main_lcd_operation_state)&&
                   (KAL_FALSE == lcd_para->memory_output))
            #endif
            {
               lcd_power_ctrl(KAL_FALSE);
               return;
            }
            if ((sub_lcd_operation_state!=LCD_STANDBY_STATE) &&
                (sub_lcd_operation_state!=LCD_SLEEP_STATE)) {
               ASSERT(0);
            }

            if ((main_lcd_operation_state!=LCD_SLEEP_STATE)&&
                (main_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
                (main_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                #ifdef TV_OUT_SUPPORT
                   (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                   (main_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
                #endif
                (main_lcd_operation_state!=LCD_STANDBY_STATE)) {
               ASSERT(0);
            }
            #ifdef __VIDEO_EDITOR__
               if (LCD_MEM_UPDATE_STATE == main_lcd_operation_state) {
                  do {
                     kal_sleep_task(1);
                  } while (main_lcd_operation_state != LCD_MEM_UPDATE_STATE);
               }
            #endif
         } else if (SUB_LCD == lcd_para->lcd_id) {
            #if (!defined(DRV_LCD_MEMORY_OUTPUT))
               if (LCD_SLEEP_STATE == sub_lcd_operation_state)
            #else
               if ((LCD_SLEEP_STATE == sub_lcd_operation_state)&&
                   (KAL_FALSE == lcd_para->memory_output))
            #endif
               {
                  lcd_power_ctrl(KAL_FALSE);
                  return;
               }
            ASSERT((LCD_STANDBY_STATE == main_lcd_operation_state) ||
                   (LCD_SLEEP_STATE == main_lcd_operation_state));

            if ((sub_lcd_operation_state!=LCD_HW_UPDATE_STATE)&&
                (sub_lcd_operation_state!=LCD_DC_UPDATE_STATE)&&
                #ifdef TV_OUT_SUPPORT
                   (sub_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE)&&
                   (sub_lcd_operation_state!=LCD_DC_UPDATE_SLEEP_STATE)&&
                #endif
                (sub_lcd_operation_state!=LCD_STANDBY_STATE)) {
               ASSERT(0);
            }
            #ifdef __VIDEO_EDITOR__
               if (LCD_MEM_UPDATE_STATE == sub_lcd_operation_state) {
                  do {
                     kal_sleep_task(1);
                  } while (sub_lcd_operation_state != LCD_MEM_UPDATE_STATE);
               }
            #endif
         }
      #endif /* DUAL_LCD */
   }

   kal_set_eg_events(lcd_event_id, 0, KAL_AND);
   ENABLE_LCD_TRANSFER_COMPLETE_INT;
   lcd_transfer_complete = KAL_FALSE;

   /// Begin of check lcm start/end, roi offset
   if (MAIN_LCD == lcd_para->lcd_id) {
      if ((LCD_HW_UPDATE_STATE == main_lcd_operation_state)||
          (LCD_DC_UPDATE_STATE == main_lcd_operation_state)) {
         if (main_lcd_fb_update_para.lcm_start_x<lcd_para->lcm_start_x) {
            lcd_para->lcm_start_x=main_lcd_fb_update_para.lcm_start_x;
         }
         if (main_lcd_fb_update_para.lcm_start_y<lcd_para->lcm_start_y) {
            lcd_para->lcm_start_y=main_lcd_fb_update_para.lcm_start_y;
         }
         if (main_lcd_fb_update_para.lcm_end_x>lcd_para->lcm_end_x) {
            lcd_para->lcm_end_x=main_lcd_fb_update_para.lcm_end_x;
         }
         if (main_lcd_fb_update_para.lcm_end_y>lcd_para->lcm_end_y) {
            lcd_para->lcm_end_y=main_lcd_fb_update_para.lcm_end_y;
         }
         if (main_lcd_fb_update_para.roi_offset_x<lcd_para->roi_offset_x) {
            lcd_para->roi_offset_x=main_lcd_fb_update_para.roi_offset_x;
         }
         if (main_lcd_fb_update_para.roi_offset_y<lcd_para->roi_offset_y) {
            lcd_para->roi_offset_y=main_lcd_fb_update_para.roi_offset_y;
         }
      }
   } else {
      if ((LCD_HW_UPDATE_STATE == sub_lcd_operation_state)||
          (LCD_DC_UPDATE_STATE == sub_lcd_operation_state)) {
         if (sub_lcd_fb_update_para.lcm_start_x<lcd_para->lcm_start_x) {
            lcd_para->lcm_start_x=sub_lcd_fb_update_para.lcm_start_x;
         }
         if (sub_lcd_fb_update_para.lcm_start_y<lcd_para->lcm_start_y) {
            lcd_para->lcm_start_y=sub_lcd_fb_update_para.lcm_start_y;
         }
         if (sub_lcd_fb_update_para.lcm_end_x>lcd_para->lcm_end_x) {
            lcd_para->lcm_end_x=sub_lcd_fb_update_para.lcm_end_x;
         }
         if (sub_lcd_fb_update_para.lcm_end_y>lcd_para->lcm_end_y) {
            lcd_para->lcm_end_y=sub_lcd_fb_update_para.lcm_end_y;
         }
         if (sub_lcd_fb_update_para.roi_offset_x<lcd_para->roi_offset_x) {
            lcd_para->roi_offset_x=sub_lcd_fb_update_para.roi_offset_x;
         }
         if (sub_lcd_fb_update_para.roi_offset_y<lcd_para->roi_offset_y) {
            lcd_para->roi_offset_y=sub_lcd_fb_update_para.roi_offset_y;
         }
      }
   }

   roi_width = lcd_para->lcm_end_x-lcd_para->lcm_start_x+1;
   roi_height = lcd_para->lcm_end_y-lcd_para->lcm_start_y+1;
   lcd_roi_offset_shadow = (lcd_para->roi_offset_y<<16) | lcd_para->roi_offset_x;

   if ((LCD_LAYER_ROTATE_90 == current_lcd_rotate_value) ||
       (LCD_LAYER_ROTATE_270 == current_lcd_rotate_value) ||
       (LCD_LAYER_MIRROR_ROTATE_90 == current_lcd_rotate_value) ||
       (LCD_LAYER_MIRROR_ROTATE_270 == current_lcd_rotate_value)) {
      lcd_roi_size_shadow= (roi_width<<16)|roi_height;
      roi_mem_out_width=roi_height;
      roi_mem_out_height=roi_width;
   } else {
      lcd_roi_size_shadow= (roi_height<<16)|roi_width;
      roi_mem_out_width=roi_width;
      roi_mem_out_height=roi_height;
   }

   lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_LAYER_MASK;
   lcd_roi_ctrl_shadow |= lcd_para->update_layer;

   #if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
      REG_LCD_ROI_BACKGROUND_COLOR=lcd_para->roi_background_color;
   #endif

   /// Beginning of memory out configuration
   #if defined(DRV_LCD_MEMORY_OUTPUT)
      if ((LCD_UPDATE_MODULE_MMI == lcd_para->module_id) &&
          (KAL_TRUE == lcd_para->memory_output)) {
         #if defined(DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT)//888 support means support 565
               lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CTRL_FORMAT;
         switch(lcd_para->memory_data_format)
         {
            case LCD_WMEM_RGB565:
               lcd_mem_out_ctrl_shadow |= LCD_WMEM_RGB565;
               break;
            case LCD_WMEM_RGB888:
               lcd_mem_out_ctrl_shadow |= LCD_WMEM_RGB888;
               break;
            #if defined(DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT)
            case LCD_WMEM_ARGB8888:
               lcd_mem_out_ctrl_shadow |= LCD_WMEM_ARGB8888;
               break;
            #endif /*DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT*/
            default:
               break;
            }
         #endif /*DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT*/
         if (LCD_WM_BLOCK_MODE == lcd_para->block_mode) {
            #if defined(DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT)
               if (LCD_WMEM_RGB565 == lcd_para->memory_data_format) {
                  if ((lcd_para->memory_output_buffer_size)<((lcd_para->memory_block_width * roi_mem_out_height)<<1)) {
                     ASSERT(0);
                  }

               } else if (LCD_WMEM_RGB888 == lcd_para->memory_data_format) {
                  if ((lcd_para->memory_output_buffer_size)<((lcd_para->memory_block_width * roi_mem_out_height)*3)) {
                     ASSERT(0);
                  }
               }
               #if defined(DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT)
               else if (LCD_WMEM_ARGB8888 == lcd_para->memory_data_format) {
                  if ((lcd_para->memory_output_buffer_size)<((lcd_para->memory_block_width * roi_mem_out_height)*4)) {
                     ASSERT(0);
                  }
               }
               #endif //DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT

            #else
               if ((lcd_para->memory_output_buffer_size)<((lcd_para->memory_block_width * roi_mem_out_height)<<1)) {
                  ASSERT(0);
               }
            #endif
            lcd_mem_out_ctrl_shadow |= LCD_ROI_WMEM_CONT_BIT;

            SET_LCD_MAIN_WINDOW_SIZE(lcd_para->memory_block_width,roi_height+lcd_para->roi_offset_y);
         } else if (LCD_WM_CONT_MODE == lcd_para->block_mode) {
            #if defined(DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT)
               if (LCD_WMEM_RGB565 == lcd_para->memory_data_format) {
                  if ((lcd_para->memory_output_buffer_size)<((roi_width * roi_height)<<1)) {
                     ASSERT(0);
                  }
               } else if (LCD_WMEM_RGB888 == lcd_para->memory_data_format) {
                  if ((lcd_para->memory_output_buffer_size)<((roi_width * roi_height)*3)) {
                     ASSERT(0);
                  }
               }
               #if defined(DRV_LCD_MEMORY_OUTPUT_ARGB888_SUPPORT)
               else if (LCD_WMEM_ARGB8888 == lcd_para->memory_data_format) {
                  if ((lcd_para->memory_output_buffer_size)<((roi_width * roi_height)*4)) {
                     ASSERT(0);
                  }
               #endif //DRV_LCD_MEMORY_OUTPUT_ARGB888_SUPPORT
            #else
               if ((lcd_para->memory_output_buffer_size)<((roi_width * roi_height)<<1)) {
                  ASSERT(0);
               }
            #endif
            lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CONT_BIT;
         }
         lcd_mem_out_address_shadow = lcd_para->memory_output_buffer_address;
         lcd_roi_ctrl_shadow |= LCD_ROI_CTRL_W2MEM_BIT;

         if (MAIN_LCD == lcd_para->lcd_id) {
            if ((KAL_TRUE ==lcd_output_mode) &&
                (KAL_TRUE == main_lcd_hw_trigger_output_mode) &&
                (main_lcd_operation_state!=LCD_SLEEP_STATE)) {
               lcd_mem_out_ctrl_shadow |= LCD_ROI_WMEM_CTRL_TO_LCM;
            } else {
               lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CTRL_TO_LCM;
            }
         }
         #ifdef DUAL_LCD
            else if (SUB_LCD == lcd_para->lcd_id) {
               if ((KAL_TRUE == lcd_output_mode) &&
                   (KAL_TRUE == sub_lcd_hw_trigger_output_mode) &&
                   (sub_lcd_operation_state!=LCD_SLEEP_STATE)) {
                  lcd_mem_out_ctrl_shadow |= LCD_ROI_WMEM_CTRL_TO_LCM;
               } else {
                  lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CTRL_TO_LCM;
               }
            }
         #endif
      } else {/*clean ROI memory out*/
            lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_W2MEM_BIT;
         }
   #endif
   /// End of memory out configuration

   /*Beginning of TV out configuration*/
   #ifdef TV_OUT_SUPPORT
   if ((lcd_para->module_id!=LCD_UPDATE_MODULE_MMI)&&(KAL_TRUE == lcd_para->tv_output)) {
      if ((lcd_para->tv_output_frame_buffer_size)<(roi_width*roi_height*2)) {
         ASSERT(0);
      }

      #if ((!defined(__MAUI_BASIC__))&& (!defined(__L1_STANDALONE__)))
         if ((KAL_TRUE == lcd_para->tv_output) &&
             (TV_OUTPUT_MODE4 == tv_output_config_data.tv_output_mode)) {
            #if defined(DRV_IDP_6228_SERIES)
            current_g2d_tv_output_bitblt_buffer=0;
            g2d_begin(G2D_OWNER_LCD, preview_tv_buffer_rotate_cb);
            g2d_tv_output_dest_buff.base_address=camera_preview_config_data.tv_rotate_buffer1_address;
            g2d_tv_output_dest_buff.x=0;
            g2d_tv_output_dest_buff.y=0;
            g2d_tv_output_dest_buff.pitch=lcd_para->tv_output_width;
            g2d_tv_output_dest_buff.width=lcd_para->tv_output_width;
            g2d_tv_output_dest_buff.height=lcd_para->tv_output_height;
            g2d_tv_output_dest_buff.color_mode=FIRE_DEST_COLOR_16BPP_RGB565;
            g2d_tv_output_dest_buff.clip_x1=0;
            g2d_tv_output_dest_buff.clip_x2=lcd_para->tv_output_width-1;
            g2d_tv_output_dest_buff.clip_y1=0;
            g2d_tv_output_dest_buff.clip_y2=lcd_para->tv_output_height-1;

            g2d_tv_output_src_buff.base_address=lcd_para->tv_output_frame_buffer1_address;
            g2d_tv_output_src_buff.x=0;
            g2d_tv_output_src_buff.y=0;
            g2d_tv_output_src_buff.pitch=lcd_para->tv_output_height;
            g2d_tv_output_src_buff.width=lcd_para->tv_output_height;
            g2d_tv_output_src_buff.height=lcd_para->tv_output_width;
            g2d_tv_output_src_buff.color_mode=FIRE_SRC_COLOR_16BPP_RGB565;
            g2d_tv_output_src_buff.clip_x1=0;
            g2d_tv_output_src_buff.clip_x2=lcd_para->tv_output_height-1;
            g2d_tv_output_src_buff.clip_y1=0;
            g2d_tv_output_src_buff.clip_y2=lcd_para->tv_output_width-1;

            g2d_tv_output_bitblt.tilt_mode=KAL_FALSE;
            g2d_tv_output_bitblt.src_key_mode = KAL_FALSE;
            g2d_tv_output_bitblt.blt_direction = BITBLT_TRANSFORM_DIRECTION_LT_CORNER;
            g2d_tv_output_bitblt.src_key_color= 0;
            g2d_tv_output_bitblt.alpha_blending_mode=KAL_FALSE;
            g2d_tv_output_bitblt.rop_mode=KAL_FALSE;
            g2d_tv_output_bitblt.transform_value = BITBLT_TRANSFORM_ROTATE_270;
            g2d_tv_output_bitblt.src_list=&g2d_tv_output_src_buff;
            g2d_tv_output_bitblt.list_count=1;
            g2d_set_dest_buffer(G2D_OWNER_LCD,&g2d_tv_output_dest_buff);
            #elif defined(DRV_IDP_6238_SERIES)
            	//KKKKK, need more think,
            	{
            	   IMGDMA_IRT3_STRUCT irt3_struct;

            	   memset(&irt3_struct, 0 , sizeof(IMGDMA_IRT3_STRUCT));

            	   irt3_struct.int_en=KAL_TRUE;
            	   irt3_struct.restart=KAL_TRUE;
            	   irt3_struct.pitch_enable=KAL_FALSE; /*not necessary*/

            	   irt3_struct.width=lcd_para->tv_output_width; /*source width before rotate*/
            	   irt3_struct.height=lcd_para->tv_output_height; /*source height before rotate*/
            	   irt3_struct.fifo_len=8; /*min*/
            	   /*?????*/
            	   /*need to think how to get it*/
            	   irt3_struct.fifo_base_addr=(kal_uint32) intmem_get_buffer(irt3_struct.fifo_len*2*irt3_struct.height);
            	   /*???? need to think how to get it*/
            	   //irt3_struct.frame1_base_addr=camera_preview_config_data.tv_rotate_buffer1_address;
            	   //irt3_struct.frame2_base_addr=camera_preview_config_data.tv_rotate_buffer2_address;
            	   irt3_struct.buf1_line_pitch=irt3_struct.width*2; /**< buf1 line pitch */
            	   irt3_struct.buf2_line_pitch=irt3_struct.width*2; /**< buf2 line pitch */
            	   irt3_struct.buf1_frame_pitch=irt3_struct.width*irt3_struct.height*2; /*frame pitch */
            	   irt3_struct.buf2_frame_pitch=irt3_struct.width*irt3_struct.height*2; /**frame pitch */
            	   irt3_struct.alpha=0; /*not necessary, because TV only support RGB565*/
            	   irt3_struct.fmt=IRT3_OUTPUT_FMT_RGB565;
            	   irt3_struct.rotate=IRT3_ROT_270; /*rotate 270*/
            	   irt3_struct.flip=KAL_FALSE; /*not flip */

            	   IMGDMA_IRT3Config(&irt3_struct);
            	}

            #endif

         }

         tv_output_buffer_base_address1=lcd_para->tv_output_frame_buffer1_address;
         tv_output_buffer_base_address2=lcd_para->tv_output_frame_buffer2_address;
         main_lcd_fb_update_para.tv_output_frame_buffer1_address=lcd_para->tv_output_frame_buffer1_address +
                                                                 (lcd_para->tv_output_offset_y*lcd_para->tv_output_width+
                                                                  lcd_para->tv_output_offset_x)*2;
         main_lcd_fb_update_para.tv_output_frame_buffer2_address=lcd_para->tv_output_frame_buffer2_address+
                                                                 (lcd_para->tv_output_offset_y*lcd_para->tv_output_width+
                                                                  lcd_para->tv_output_offset_x)*2;

         tv_output_owner = TV_OUT_OWNER_LCD;
         tv_out_current_fb=0;
         set_tv_src_size(TV_OUT_OWNER_LCD,lcd_para->tv_output_width,lcd_para->tv_output_height);

         lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CTRL_FORMAT;

         if (TV_OUTPUT_MODE4 == tv_output_config_data.tv_output_mode) {
            if (roi_width==lcd_para->tv_output_height) {
               lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CONT_BIT;
            } else if (roi_width<lcd_para->tv_output_height) {
               lcd_mem_out_ctrl_shadow |= LCD_ROI_WMEM_CONT_BIT;
               SET_LCD_MAIN_WINDOW_SIZE(lcd_para->tv_output_height,roi_height+lcd_para->roi_offset_y);
            } else {
               ASSERT(0);
            }
         } else {
            if (roi_width==lcd_para->tv_output_width) {
               lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CONT_BIT;
            } else if (roi_width<lcd_para->tv_output_width) {
               lcd_mem_out_ctrl_shadow |= LCD_ROI_WMEM_CONT_BIT;
               SET_LCD_MAIN_WINDOW_SIZE(lcd_para->tv_output_width,roi_height+lcd_para->roi_offset_y);
            }
            else {
               ASSERT(0);
            }
         }
      #else
         lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CTRL_FORMAT;
         if (roi_width==lcd_para->tv_output_width) {
            lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CONT_BIT;
         } else if (roi_width<lcd_para->tv_output_width) {
            lcd_mem_out_ctrl_shadow |= LCD_ROI_WMEM_CONT_BIT;
            SET_LCD_MAIN_WINDOW_SIZE(lcd_para->tv_output_width,roi_height+lcd_para->roi_offset_y);
         } else {
            ASSERT(0);
         }
      #endif

      lcd_mem_out_address_shadow = main_lcd_fb_update_para.tv_output_frame_buffer1_address;
      lcd_roi_ctrl_shadow |= LCD_ROI_CTRL_W2MEM_BIT;

      if (MAIN_LCD == lcd_para->lcd_id) {
         if ((KAL_TRUE == lcd_output_mode) &&
             (KAL_TRUE == main_lcd_hw_trigger_output_mode)) {
            lcd_mem_out_ctrl_shadow |= LCD_ROI_WMEM_CTRL_TO_LCM;
         } else {
            lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CTRL_TO_LCM;
         }
      }
      #ifdef DUAL_LCD
         else if (SUB_LCD == lcd_para->lcd_id) {
            if ((KAL_TRUE == lcd_output_mode) &&
                (KAL_TRUE == sub_lcd_hw_trigger_output_mode)) {
               lcd_mem_out_ctrl_shadow |= LCD_ROI_WMEM_CTRL_TO_LCM;
            } else {
               lcd_mem_out_ctrl_shadow &= ~LCD_ROI_WMEM_CTRL_TO_LCM;
            }
         }
      #endif
   }
   #endif
   /*End of TV out configuration*/

   switch (lcd_para->lcd_id) {
   case MAIN_LCD:
      if ((LCD_STANDBY_STATE == main_lcd_operation_state)||
          (LCD_SLEEP_STATE == main_lcd_operation_state)) {
         lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_DATA_FORMAT_MASK;
         lcd_roi_ctrl_shadow |= MAIN_LCD_OUTPUT_FORMAT;

         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
         switch (lcd_para->fb_update_mode) {
         case LCD_SW_TRIGGER_MODE: /*MMI*/
            /*to prevent MED preempt*/
            save_irq_mask=SaveAndSetIRQMask();
            if (LCD_STANDBY_STATE == main_lcd_operation_state) {
               main_lcd_operation_state=LCD_SW_UPDATE_STATE;
               DISABLE_LCD_HW_TRIGGER_UPDATE;
               RestoreIRQMask(save_irq_mask);
               kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            } else {
               lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_CMD_ENABLE_BIT;/*not output to LCD*/
               RestoreIRQMask(save_irq_mask);
            }

            if (KAL_FALSE == lcd_para->block_mode_flag) {
               lcd_prev_run_block_cb=lcd_para->lcd_block_mode_cb;
               IRQMask(IRQ_LCD_CODE);
               bWaitForLCDUpdate=KAL_TRUE;
               IRQUnmask(IRQ_LCD_CODE);
            } else {
               IRQMask(IRQ_LCD_CODE);
               bWaitForLCDUpdate=KAL_FALSE;
               IRQUnmask(IRQ_LCD_CODE);
            }
            break;

         case LCD_HW_TRIGGER_MODE:/*MED*/
            #if defined(DRV_IDP_6228_SERIES)
               if (LCD_HW_TRIGGER_IBW2 == lcd_para->hw_trigger_src) {
                  SET_LCD_IBW2_TRIGGER_LAYER(lcd_para->hw_update_layer);
               } else {
                  SET_LCD_IBW1_TRIGGER_LAYER(lcd_para->hw_update_layer);
               }
            #elif defined(DRV_IDP_6238_SERIES)
               /*KKKKK,OK select HW trigger source*/
               switch(lcd_para->hw_trigger_src)
               {
                  case LCD_HW_TRIGGER_IRT1:
                     SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT1);
                     break;
                  case LCD_HW_TRIGGER_IBW1:
                     SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW1);
                     break;
                  case LCD_HW_TRIGGER_IRT2:
                     SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT2);
                     break;
                  case LCD_HW_TRIGGER_IBW2:
                     SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW2);
                     break;
                  default:
                     ASSERT(0);
                     break;
               }
            #endif //DRV_IDP_6238_SERIES
            #ifdef TV_OUT_SUPPORT
               if (LCD_SLEEP_STATE == main_lcd_operation_state) {
                  main_lcd_operation_state=LCD_HW_UPDATE_SLEEP_STATE;
               } else if (LCD_STANDBY_STATE == main_lcd_operation_state) {
                  main_lcd_operation_state=LCD_HW_UPDATE_STATE;
               }
            #else
               main_lcd_operation_state=LCD_HW_UPDATE_STATE;
            #endif //TV_OUT_SUPPORT
            SET_LCD_HW_TRIGGER_LAYER(lcd_para->hw_update_layer);
            ENABLE_LCD_HW_TRIGGER_UPDATE;
            #ifdef __SYNC_LCM_SW_SUPPORT__
               switch (lcd_para->hw_update_layer) {
               case LCD_LAYER0_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER0_ROTATE;
                  break;
               case LCD_LAYER1_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER1_ROTATE;
                  break;
               case LCD_LAYER2_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER2_ROTATE;
                  break;
               case LCD_LAYER3_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER3_ROTATE;
                  break;
               #if (DRV_LAYER_TOTAL_COUNT>4)
                   case LCD_LAYER4_ENABLE:
                      sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER4_ROTATE;
                      break;
                   case LCD_LAYER5_ENABLE:
                      sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER5_ROTATE;
                      break;
               #endif
               }

               if (KAL_TRUE == sync_lcm_enable_mode) {
                  DISABLE_LCD_HW_TRIGGER_UPDATE;
                  DISABLE_LCD_CMD_COMPLETE_INT;
               }
            #endif
            break;
         case LCD_DIRECT_COUPLE_MODE:/*MED*/
            #if defined(DRV_IDP_6228_SERIES)
               if (LCD_HW_TRIGGER_IBW2 == lcd_para->hw_trigger_src) {
                  SET_LCD_IBW2_TRIGGER_LAYER(lcd_para->hw_update_layer);
               } else {
                  SET_LCD_IBW1_TRIGGER_LAYER(lcd_para->hw_update_layer);
               }
            #elif defined(DRV_IDP_6238_SERIES)
               /*KKKKK, OK selec new DC source*/
               /*KKKKK,OK select HW trigger source*/
               {
                   LCD_LAYER_ENUM layer=LCD_LAYER0;
                   switch(lcd_para->hw_update_layer)
                   {
                      case LCD_LAYER0_ENABLE:
                         layer=LCD_LAYER0;
                         break;
                      case LCD_LAYER1_ENABLE:
                         layer=LCD_LAYER1;
                         break;
                      case LCD_LAYER2_ENABLE:
                         layer=LCD_LAYER2;
                         break;
                      case LCD_LAYER3_ENABLE:
                         layer=LCD_LAYER4;
                         break;
                      case LCD_LAYER4_ENABLE:
                         layer=LCD_LAYER4;
                         break;
                      case LCD_LAYER5_ENABLE:
                         layer=LCD_LAYER5;
                         break;
                      default:
                         ASSERT(0);
                         break;
                   }

                   switch(lcd_para->hw_trigger_src)
                   {
                      case LCD_HW_TRIGGER_IBW1:
                         SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IBW1,layer);
                         SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW1);
                         break;
                      case LCD_HW_TRIGGER_IRT2:
                         SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IRT2,layer);
                         SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT2);
                         break;
                      case LCD_HW_TRIGGER_IBW2:
                         SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IBW2,layer);
                         SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW2);
                         break;
                      default:
                         ASSERT(0);
                         break;
                   }
               }
            #endif //DRV_IDP_6238_SERIES
               set_lcd_dc_layer_format(lcd_para->hw_update_layer,KAL_TRUE);
            #ifdef TV_OUT_SUPPORT
               if (LCD_SLEEP_STATE == main_lcd_operation_state) {
                  main_lcd_operation_state=LCD_DC_UPDATE_SLEEP_STATE;
               } else if (main_lcd_operation_state==LCD_STANDBY_STATE) {
                  main_lcd_operation_state=LCD_DC_UPDATE_STATE;
               }
            #else
               main_lcd_operation_state=LCD_DC_UPDATE_STATE;
            #endif //TV_OUT_SUPPORT
            SET_LCD_DIRECT_COUPLE_LAYER((lcd_para->hw_update_layer));
            ENABLE_LCD_HW_TRIGGER_UPDATE;
            break;
         }
         lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_LAYER_MASK;
         lcd_roi_ctrl_shadow |= lcd_para->update_layer;

         lcd_hard_trigger_flag=0;/*XXXXX remove ?*/
         save_irq_mask=SaveAndSetIRQMask();
         #if (defined(DRV_LCD_MEMORY_OUTPUT))
            DRV_WriteReg32(LCD_ROI_WMEM_CTRL_REG, lcd_mem_out_ctrl_shadow);
            DRV_WriteReg32(LCD_ROI_WMEM_ADDR_REG, lcd_mem_out_address_shadow);
         #endif
         DRV_WriteReg32(LCD_ROI_CTRL_REG, lcd_roi_ctrl_shadow);
         DRV_WriteReg32(LCD_ROI_OFFSET_REG, lcd_roi_offset_shadow);
         DRV_WriteReg32(LCD_ROI_SIZE_REG, lcd_roi_size_shadow);
         RestoreIRQMask(save_irq_mask);

         if (main_lcd_operation_state!=LCD_SLEEP_STATE) {
            MainLCD->BlockWrite(lcd_para->lcm_start_x,lcd_para->lcm_start_y,
                             lcd_para->lcm_end_x,lcd_para->lcm_end_y);
         } else {
            START_LCD_TRANSFER;
         }
         lcd_hard_trigger_flag=1;/*XXXXX remove ?*/
         for (j=0;j<10;j++);
         if ((LCD_HW_TRIGGER_MODE == lcd_para->fb_update_mode)||
             (LCD_DIRECT_COUPLE_MODE == lcd_para->fb_update_mode)) {
            lcd_hw_trigger_layer=lcd_para->hw_update_layer;
            lcd_hw_trigger_roi_offset=DRV_Reg32(LCD_ROI_OFFSET_REG);
            lcd_hw_trigger_roi_size=DRV_Reg32(LCD_ROI_SIZE_REG);
            lcd_hw_trigger_roi_ctrl=DRV_Reg32(LCD_ROI_CTRL_REG);
            lcd_hw_trigger_flag=KAL_FALSE;
            for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++) {
               lcd_hw_trigger_para[i]=DRV_Reg32(LCD_CMD_PARAMETER_ADDR+(i<<2));
            }
            main_lcd_fb_update_para.lcm_start_x=lcd_para->lcm_start_x;
            main_lcd_fb_update_para.lcm_start_y=lcd_para->lcm_start_y;
            main_lcd_fb_update_para.lcm_end_x=lcd_para->lcm_end_x;
            main_lcd_fb_update_para.lcm_end_y=lcd_para->lcm_end_y;
            main_lcd_fb_update_para.roi_offset_x=lcd_para->roi_offset_x;
            main_lcd_fb_update_para.roi_offset_y=lcd_para->roi_offset_y;
         }

         current_update_lcd=lcd_para->lcd_id;
         if ((LCD_SW_UPDATE_STATE == main_lcd_operation_state)||
             (LCD_SLEEP_STATE == main_lcd_operation_state)) {
            if (KAL_TRUE == lcd_para->block_mode_flag) {
               lcd_busy_waiting();
               for (j=0;j<10;j++);
               temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
               for (j=0;j<10;j++);

               if (LCD_SW_UPDATE_STATE == main_lcd_operation_state) {
                  main_lcd_operation_state=LCD_STANDBY_STATE;
               }
               DISABLE_LCD_ROI_CTRL_W2MEM;
            }
         }
      }
      else if ((LCD_HW_UPDATE_STATE == main_lcd_operation_state) ||
               (LCD_DC_UPDATE_STATE == main_lcd_operation_state)) {
         ASSERT(LCD_SW_TRIGGER_MODE == lcd_para->fb_update_mode);

         lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_LAYER_MASK;
         lcd_roi_ctrl_shadow |= (lcd_para->update_layer );

         lcd_cmd_latch_complete=KAL_FALSE;
         ENABLE_LCD_CMD_COMPLETE_INT;

         current_update_lcd=lcd_para->lcd_id;
         lcd_hw_trigger_flag=KAL_TRUE;
         #ifdef TV_OUT_SUPPORT
            IRQMask(IRQ_LCD_CODE);
            if (TV_OUT_OWNER_LCD == tv_output_owner) {
               lcd_roi_ctrl_shadow |= LCD_ROI_CTRL_W2MEM_BIT;
               if ((roi_mem_out_width>(lcd_para->tv_output_width-lcd_para->tv_output_offset_x))||
                   (roi_mem_out_height>(lcd_para->tv_output_height-lcd_para->tv_output_offset_y))) {
                  ASSERT(0);
               }
               tv_output_buffer_offset_address1=tv_output_buffer_base_address1 +
                                                (lcd_para->tv_output_offset_y*lcd_para->tv_output_width +
                                                 lcd_para->tv_output_offset_x) * 2;
               tv_output_buffer_offset_address2=tv_output_buffer_base_address2 +
                                                (lcd_para->tv_output_offset_y*lcd_para->tv_output_width +
                                                 lcd_para->tv_output_offset_x) * 2;
               tv_output_replace_data=*((volatile unsigned int *) tv_output_buffer_offset_address1)+0x10001;
               if (0 == tv_out_current_fb) {
                  lcd_mem_out_address_shadow = tv_output_buffer_offset_address1;
                  *((volatile unsigned int *) tv_output_buffer_offset_address1)=tv_output_replace_data;
               } else {
                  lcd_mem_out_address_shadow = tv_output_buffer_offset_address2;
                  *((volatile unsigned int *) tv_output_buffer_offset_address2)=tv_output_replace_data;
               }
               tv_output_buffer_count = 0;
               tv_full_screen=2;
            } else {
               tv_output_buffer_count = 2;
               tv_full_screen=0;
            }
         #endif

         save_irq_mask=SaveAndSetIRQMask();
         if (LCD_HW_UPDATE_STATE == main_lcd_operation_state) {
            main_lcd_operation_state=LCD_HW_CMD_QUEUE_STATE;
         } else if (LCD_DC_UPDATE_STATE == main_lcd_operation_state) {
            main_lcd_operation_state=LCD_DC_CMD_QUEUE_STATE;
         }
         #if (defined(DRV_LCD_MEMORY_OUTPUT))
            DRV_WriteReg32(LCD_ROI_WMEM_CTRL_REG,lcd_mem_out_ctrl_shadow);
            DRV_WriteReg32(LCD_ROI_WMEM_ADDR_REG,lcd_mem_out_address_shadow);
         #endif
         DRV_WriteReg32(LCD_ROI_CTRL_REG,lcd_roi_ctrl_shadow);
         DRV_WriteReg32(LCD_ROI_OFFSET_REG,lcd_roi_offset_shadow);
         DRV_WriteReg32(LCD_ROI_SIZE_REG,lcd_roi_size_shadow);
         lcd_is_changing_roi=KAL_TRUE;
         RestoreIRQMask(save_irq_mask);
         #ifdef __SYNC_LCM_SW_SUPPORT__
            if ((LCD_HW_CMD_QUEUE_STATE == main_lcd_operation_state) &&
                (KAL_TRUE == sync_lcm_enable_mode)) {
               DISABLE_LCD_CMD_COMPLETE_INT;
               ENABLE_LCD_HW_TRIGGER_UPDATE;
               wait_lcd_restore_config_flag=KAL_TRUE;
            }
         #endif
         MainLCD->BlockWrite(lcd_para->lcm_start_x, lcd_para->lcm_start_y,
                             lcd_para->lcm_end_x, lcd_para->lcm_end_y);
         #ifdef __SYNC_LCM_SW_SUPPORT__
            if ((LCD_HW_CMD_QUEUE_STATE == main_lcd_operation_state) &&
                (KAL_TRUE == sync_lcm_enable_mode)) {
               STOP_LCD_TRANSFER;
               DISABLE_LCD_HW_TRIGGER_UPDATE;
            }
            wait_lcd_config_flag = KAL_FALSE;
         #endif
         lcd_is_changing_roi=KAL_FALSE;
         IRQUnmask(IRQ_LCD_CODE);
         for (j=0;j<20;j++);
         if((LCD_HW_CMD_QUEUE_STATE == main_lcd_operation_state)||
            (LCD_DC_CMD_QUEUE_STATE == main_lcd_operation_state)) {
            lcd_wait_command_latch();
            if (LCD_HW_CMD_QUEUE_STATE == main_lcd_operation_state) {
               main_lcd_operation_state=LCD_HW_UPDATE_STATE;
            } else if (LCD_DC_CMD_QUEUE_STATE == main_lcd_operation_state) {
               main_lcd_operation_state=LCD_DC_UPDATE_STATE;
            }
         }

         ENABLE_LCD_TRANSFER_COMPLETE_INT;

         #ifdef TV_OUT_SUPPORT
            if (tv_output_owner!=TV_OUT_OWNER_LCD) {
               DISABLE_LCD_CMD_COMPLETE_INT;
            } else {
               ENABLE_LCD_CMD_COMPLETE_INT;
            }
         #else
            DISABLE_LCD_CMD_COMPLETE_INT;
         #endif
      }
      #ifdef TV_OUT_SUPPORT
      else if ((LCD_HW_UPDATE_SLEEP_STATE == main_lcd_operation_state)||
               (LCD_DC_UPDATE_SLEEP_STATE == main_lcd_operation_state)) {
         ASSERT(LCD_SW_TRIGGER_MODE == lcd_para->fb_update_mode);

         ASSERT(LCD_UPDATE_MODULE_MMI == lcd_para->module_id);

         if (TV_OUT_OWNER_LCD == tv_output_owner) {
            lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_LAYER_MASK;
            lcd_roi_ctrl_shadow |= (lcd_para->update_layer );

            lcd_cmd_latch_complete=KAL_FALSE;
            ENABLE_LCD_CMD_COMPLETE_INT;

            current_update_lcd=lcd_para->lcd_id;
            lcd_hw_trigger_flag=KAL_TRUE;
            IRQMask(IRQ_LCD_CODE);
            tv_output_buffer_offset_address1=tv_output_buffer_base_address1;
            tv_output_buffer_offset_address2=tv_output_buffer_base_address2;
            tv_output_replace_data=*((volatile unsigned int *) tv_output_buffer_offset_address1)+0x10001;
            if (0 == tv_out_current_fb) {
               lcd_mem_out_address_shadow = tv_output_buffer_offset_address1;
               *((volatile unsigned int *) tv_output_buffer_offset_address1)=tv_output_replace_data;
            } else {
               lcd_mem_out_address_shadow = tv_output_buffer_offset_address2;
               *((volatile unsigned int *) tv_output_buffer_offset_address2)=tv_output_replace_data;
            }
            tv_output_buffer_count = 0;
            tv_full_screen=2;
            lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_CMD_ENABLE_BIT;/*not output to LCD*/
            lcd_roi_ctrl_shadow |= LCD_ROI_CTRL_W2MEM_BIT;
            save_irq_mask=SaveAndSetIRQMask();
            if (main_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE) {
               main_lcd_operation_state=LCD_HW_SLEEP_CMD_QUEUE_STATE;
            } else if (main_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE) {
               main_lcd_operation_state=LCD_DC_SLEEP_CMD_QUEUE_STATE;
            }
            DRV_WriteReg32(LCD_ROI_WMEM_CTRL_REG,lcd_mem_out_ctrl_shadow);
            DRV_WriteReg32(LCD_ROI_WMEM_ADDR_REG,lcd_mem_out_address_shadow);
            DRV_WriteReg32(LCD_ROI_CTRL_REG,lcd_roi_ctrl_shadow);
            DRV_WriteReg32(LCD_ROI_OFFSET_REG,lcd_roi_offset_shadow);
            DRV_WriteReg32(LCD_ROI_SIZE_REG,lcd_roi_size_shadow);
            RestoreIRQMask(save_irq_mask);
            START_LCD_TRANSFER;
            IRQUnmask(IRQ_LCD_CODE);
            while (2 == tv_full_screen)
            {
               kal_uint32 loop_count=0;
               kal_sleep_task(1);
               loop_count++;
               if(loop_count>2000)/*~9 seconds*/
               {
                  #ifdef __PRODUCTION_RELEASE__
                     break;
                  #else
                     ASSERT(0);
                  #endif
               }
            }
            if (LCD_HW_SLEEP_CMD_QUEUE_STATE == main_lcd_operation_state) {
               main_lcd_operation_state=LCD_HW_UPDATE_SLEEP_STATE;
            } else if (LCD_DC_SLEEP_CMD_QUEUE_STATE == main_lcd_operation_state) {
               main_lcd_operation_state=LCD_DC_UPDATE_SLEEP_STATE;
            }
         }
      }
      #endif /* TV_OUT_SUPPORT */
      break;
   #ifdef DUAL_LCD
   case SUB_LCD:
      if (LCD_STANDBY_STATE == sub_lcd_operation_state) {
         lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_DATA_FORMAT_MASK;
         lcd_roi_ctrl_shadow |= SUB_LCD_OUTPUT_FORMAT;

         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
         switch (lcd_para->fb_update_mode) {
         case LCD_SW_TRIGGER_MODE:
            DISABLE_LCD_HW_TRIGGER_UPDATE;
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            sub_lcd_operation_state=LCD_SW_UPDATE_STATE;
            if (KAL_FALSE == lcd_para->block_mode_flag) {
               lcd_prev_run_block_cb=lcd_para->lcd_block_mode_cb;
               IRQMask(IRQ_LCD_CODE);
               bWaitForLCDUpdate=KAL_TRUE;
               IRQUnmask(IRQ_LCD_CODE);
            } else {
               IRQMask(IRQ_LCD_CODE);
               bWaitForLCDUpdate=KAL_FALSE;
               IRQUnmask(IRQ_LCD_CODE);
            }
            break;
         case LCD_HW_TRIGGER_MODE:
            #if (defined(DRV_IDP_6228_SERIES))
               if (LCD_HW_TRIGGER_IBW2 == lcd_para->hw_trigger_src) {
                  SET_LCD_IBW2_TRIGGER_LAYER(lcd_para->hw_update_layer);
               } else {
                  SET_LCD_IBW1_TRIGGER_LAYER(lcd_para->hw_update_layer);
               }
            #elif defined(DRV_IDP_6238_SERIES)
               /*KKKKK,OK select HW trigger source*/
               switch(lcd_para->hw_trigger_src)
               {
                  case LCD_HW_TRIGGER_IRT1:
                     SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT1);
                     break;
                  case LCD_HW_TRIGGER_IBW1:
                     SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW1);
                     break;
                  case LCD_HW_TRIGGER_IRT2:
                     SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT2);
                     break;
                  case LCD_HW_TRIGGER_IBW2:
                     SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW2);
                     break;
                  default:
                     ASSERT(0);
                     break;
               }
            #endif //DRV_IDP_6238_SERIES
            #ifdef TV_OUT_SUPPORT
               if (LCD_SLEEP_STATE == sub_lcd_operation_state) {
                  sub_lcd_operation_state=LCD_HW_UPDATE_SLEEP_STATE;
               } else if (sub_lcd_operation_state==LCD_STANDBY_STATE) {
                  sub_lcd_operation_state=LCD_HW_UPDATE_STATE;
               }
            #else
               sub_lcd_operation_state=LCD_HW_UPDATE_STATE;
            #endif //TV_OUT_SUPPORT
            SET_LCD_HW_TRIGGER_LAYER(lcd_para->hw_update_layer);
            ENABLE_LCD_HW_TRIGGER_UPDATE;
            break;
         case LCD_DIRECT_COUPLE_MODE:
            #if (defined(DRV_IDP_6228_SERIES))
               if (LCD_HW_TRIGGER_IBW2 == lcd_para->hw_trigger_src) {
                  SET_LCD_IBW2_TRIGGER_LAYER(lcd_para->hw_update_layer);
               } else {
                  SET_LCD_IBW1_TRIGGER_LAYER(lcd_para->hw_update_layer);
               }
               set_lcd_dc_layer_format(lcd_para->hw_update_layer,KAL_TRUE);
            #elif defined(DRV_IDP_6238_SERIES)
               /*KKKKK, OK selec new DC source*/
               /*KKKKK,OK select HW trigger source*/
               {
                   LCD_LAYER_ENUM layer=LCD_LAYER0;
                   switch(lcd_para->hw_update_layer)
                   {
                      case LCD_LAYER0_ENABLE:
                         layer=LCD_LAYER0;
                         break;
                      case LCD_LAYER1_ENABLE:
                         layer=LCD_LAYER1;
                         break;
                      case LCD_LAYER2_ENABLE:
                         layer=LCD_LAYER2;
                         break;
                      case LCD_LAYER3_ENABLE:
                         layer=LCD_LAYER4;
                         break;
                      case LCD_LAYER4_ENABLE:
                         layer=LCD_LAYER4;
                         break;
                      case LCD_LAYER5_ENABLE:
                         layer=LCD_LAYER5;
                         break;
                      default:
                         ASSERT(0);
                         break;
                   }

                   switch(lcd_para->hw_trigger_src)
                   {
                      case LCD_HW_TRIGGER_IBW1:
                         SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IBW1,layer);
                         SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW1);
                         break;
                      case LCD_HW_TRIGGER_IRT2:
                         SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IRT2,layer);
                         SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT2);
                         break;
                      case LCD_HW_TRIGGER_IBW2:
                         SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IBW2,layer);
                         SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW2);
                         break;
                      default:
                         ASSERT(0);
                         break;
                   }
               }
            #endif //DRV_IDP_6228_SERIES
               set_lcd_dc_layer_format(lcd_para->hw_update_layer,KAL_TRUE);

            #ifdef TV_OUT_SUPPORT
               if (LCD_SLEEP_STATE == sub_lcd_operation_state) {
                  sub_lcd_operation_state=LCD_DC_UPDATE_SLEEP_STATE;
               } else if (LCD_STANDBY_STATE == sub_lcd_operation_state) {
                  sub_lcd_operation_state=LCD_DC_UPDATE_STATE;
               }
            #else
               sub_lcd_operation_state=LCD_DC_UPDATE_STATE;
            #endif //TV_OUT_SUPPORT
            SET_LCD_DIRECT_COUPLE_LAYER((lcd_para->hw_update_layer));
            #ifdef __SYNC_LCM_SW_SUPPORT__
               switch (lcd_para->hw_update_layer) {
               case LCD_LAYER0_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER0_ROTATE;
                  break;
               case LCD_LAYER1_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER1_ROTATE;
                  break;
               case LCD_LAYER2_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER2_ROTATE;
                  break;
               case LCD_LAYER3_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER3_ROTATE;
                  break;
               #if (DRV_LAYER_TOTAL_COUNT>4)
               case LCD_LAYER4_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER4_ROTATE;
                  break;
               case LCD_LAYER5_ENABLE:
                  sync_lcm_hw_update_layer_rotate_value=GET_LCD_LAYER5_ROTATE;
                  break;
               #endif
               }

               if (KAL_TRUE == sync_lcm_enable_mode) {
                  DISABLE_LCD_HW_TRIGGER_UPDATE;
               } else {
                  ENABLE_LCD_HW_TRIGGER_UPDATE;
               }
            #else
               ENABLE_LCD_HW_TRIGGER_UPDATE;
            #endif
            break;
         }
         lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_LAYER_MASK;
         lcd_roi_ctrl_shadow |= lcd_para->update_layer;

         save_irq_mask=SaveAndSetIRQMask();
         #if (defined(DRV_LCD_MEMORY_OUTPUT))
            DRV_WriteReg32(LCD_ROI_WMEM_CTRL_REG,lcd_mem_out_ctrl_shadow);
            DRV_WriteReg32(LCD_ROI_WMEM_ADDR_REG,lcd_mem_out_address_shadow);
         #endif
         DRV_WriteReg32(LCD_ROI_CTRL_REG,lcd_roi_ctrl_shadow);
         DRV_WriteReg32(LCD_ROI_OFFSET_REG,lcd_roi_offset_shadow);
         DRV_WriteReg32(LCD_ROI_SIZE_REG,lcd_roi_size_shadow);
         RestoreIRQMask(save_irq_mask);
         SubLCD->BlockWrite(lcd_para->lcm_start_x, lcd_para->lcm_start_y,
                            lcd_para->lcm_end_x, lcd_para->lcm_end_y);
         if ((LCD_HW_TRIGGER_MODE == lcd_para->fb_update_mode)||
             (LCD_DIRECT_COUPLE_MODE == lcd_para->fb_update_mode)) {
            lcd_hw_trigger_layer=lcd_para->hw_update_layer;
            lcd_hw_trigger_roi_offset=DRV_Reg32(LCD_ROI_OFFSET_REG);
            lcd_hw_trigger_roi_size=DRV_Reg32(LCD_ROI_SIZE_REG);
            lcd_hw_trigger_roi_ctrl=DRV_Reg32(LCD_ROI_CTRL_REG);
            lcd_hw_trigger_flag=KAL_FALSE;
            for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++) {
               lcd_hw_trigger_para[i]=DRV_Reg32(LCD_CMD_PARAMETER_ADDR+(i<<2));
            }
         }
         current_update_lcd=lcd_para->lcd_id;
         if (LCD_SW_UPDATE_STATE == sub_lcd_operation_state) {
            if (KAL_TRUE == lcd_para->block_mode_flag) {
               lcd_busy_waiting();
               temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
               sub_lcd_operation_state=LCD_STANDBY_STATE;
               DISABLE_LCD_ROI_CTRL_W2MEM;
            }
         }
      } else if ((LCD_HW_UPDATE_STATE == sub_lcd_operation_state) ||
                 (LCD_DC_UPDATE_STATE == sub_lcd_operation_state)) {
         ASSERT(LCD_SW_TRIGGER_MODE == lcd_para->fb_update_mode);

         lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_LAYER_MASK;
         lcd_roi_ctrl_shadow |= (lcd_para->update_layer );

         lcd_cmd_latch_complete=KAL_FALSE;
         ENABLE_LCD_CMD_COMPLETE_INT;
         if (sub_lcd_operation_state==LCD_HW_UPDATE_STATE) {
            sub_lcd_operation_state=LCD_HW_CMD_QUEUE_STATE;
         } else if (sub_lcd_operation_state==LCD_DC_UPDATE_STATE) {
            sub_lcd_operation_state=LCD_DC_CMD_QUEUE_STATE;
         }
         current_update_lcd=lcd_para->lcd_id;

         save_irq_mask=SaveAndSetIRQMask();
         #if (defined(DRV_LCD_MEMORY_OUTPUT))
            DRV_WriteReg32(LCD_ROI_WMEM_CTRL_REG,lcd_mem_out_ctrl_shadow);
            DRV_WriteReg32(LCD_ROI_WMEM_ADDR_REG,lcd_mem_out_address_shadow);
         #endif
         DRV_WriteReg32(LCD_ROI_CTRL_REG,lcd_roi_ctrl_shadow);
         DRV_WriteReg32(LCD_ROI_OFFSET_REG,lcd_roi_offset_shadow);
         DRV_WriteReg32(LCD_ROI_SIZE_REG,lcd_roi_size_shadow);
         RestoreIRQMask(save_irq_mask);

         SubLCD->BlockWrite(lcd_para->lcm_start_x, lcd_para->lcm_start_y,
                            lcd_para->lcm_end_x, lcd_para->lcm_end_y);
         lcd_hw_trigger_flag=KAL_TRUE;
         if((LCD_HW_CMD_QUEUE_STATE == sub_lcd_operation_state) ||
            (LCD_DC_CMD_QUEUE_STATE == sub_lcd_operation_state)) {
            if(REG_LCD_ROI_HW_CTRL!=0) {
               lcd_wait_command_latch();
            }
            if (LCD_HW_CMD_QUEUE_STATE == sub_lcd_operation_state) {
               sub_lcd_operation_state=LCD_HW_UPDATE_STATE;
            } else if (LCD_DC_CMD_QUEUE_STATE == sub_lcd_operation_state) {
               sub_lcd_operation_state=LCD_DC_UPDATE_STATE;
            }
         }

         ENABLE_LCD_TRANSFER_COMPLETE_INT;

         #ifdef TV_OUT_SUPPORT
            if (tv_output_owner!=TV_OUT_OWNER_LCD) {
               DISABLE_LCD_CMD_COMPLETE_INT;
            } else {
               ENABLE_LCD_CMD_COMPLETE_INT;
            }
         #else
            DISABLE_LCD_CMD_COMPLETE_INT;
         #endif
      }
      #ifdef TV_OUT_SUPPORT
      else if ((LCD_HW_UPDATE_SLEEP_STATE == sub_lcd_operation_state) ||
               (LCD_DC_UPDATE_SLEEP_STATE == sub_lcd_operation_state)) {
         ASSERT(LCD_SW_TRIGGER_MODE == lcd_para->fb_update_mode);

         if ((LCD_UPDATE_MODULE_MMI == lcd_para->module_id)&&
            ((KAL_TRUE == lcd_para->tv_output)||
             (KAL_TRUE == lcd_para->memory_output))) {
            lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_LAYER_MASK;
            lcd_roi_ctrl_shadow |= (lcd_para->update_layer );
            /// not output to LCD
            lcd_roi_ctrl_shadow &= ~LCD_ROI_CTRL_CMD_ENABLE_BIT;

            save_irq_mask=SaveAndSetIRQMask();
            DRV_WriteReg32(LCD_ROI_WMEM_CTRL_REG,lcd_mem_out_ctrl_shadow);
            DRV_WriteReg32(LCD_ROI_WMEM_ADDR_REG,lcd_mem_out_address_shadow);
            DRV_WriteReg32(LCD_ROI_CTRL_REG,lcd_roi_ctrl_shadow);
            DRV_WriteReg32(LCD_ROI_OFFSET_REG,lcd_roi_offset_shadow);
            DRV_WriteReg32(LCD_ROI_SIZE_REG,lcd_roi_size_shadow);
            RestoreIRQMask(save_irq_mask);
            START_LCD_TRANSFER;
         }
      }
      #endif
      break;
   #endif   /* DUAL_LCD */
   }
   lcd_power_ctrl(KAL_FALSE);
}
#endif



/**
 * Trigger LCD interface to update the display RAM of LCM in specified area
 *
 * @param lcd_para the parameters for lcd frame buffer update
 *
 * @return None.
 */
void lcd_fb_update(lcd_frame_update_struct *lcd_para)
{
   if (INT_QueryExceptionStatus()) {
      return;
   }

   ////// Basic Check - Begin

   ASSERT( (MAIN_LCD == lcd_para->lcd_id) || (SUB_LCD == lcd_para->lcd_id));

   if (MAIN_LCD == lcd_para->lcd_id) {
      ASSERT ((lcd_para->lcm_start_x < LCD_WIDTH) && (lcd_para->lcm_end_x < LCD_WIDTH) &&
              (lcd_para->lcm_start_y < LCD_HEIGHT) && (lcd_para->lcm_end_y < LCD_HEIGHT));
   }
   #if (defined(DUAL_LCD))
      else {
         ASSERT ((lcd_para->lcm_start_x < SUBLCD_WIDTH) && (lcd_para->lcm_end_x < SUBLCD_WIDTH) &&
             (lcd_para->lcm_start_y < SUBLCD_HEIGHT) && (lcd_para->lcm_end_y < SUBLCD_HEIGHT));
      }
   #endif

   #ifdef DRV_LCD_MEMORY_OUTPUT
      ASSERT((KAL_TRUE == lcd_para->memory_output) || (KAL_FALSE == lcd_para->memory_output));
   #endif

   #ifdef TV_OUT_SUPPORT
      ASSERT((KAL_TRUE == lcd_para->tv_output) || (KAL_FALSE == lcd_para->tv_output));
   #endif

   ////// Basic Check - End

   #if ((!defined(MT6205B))&&(!defined(MT6208)))
      ASSERT((lcd_para->roi_offset_x<1024) && (lcd_para->roi_offset_y<1024));

      if (LCD_UPDATE_MODULE_MMI == lcd_para->module_id) {
         if (KAL_FALSE == lcd_para->block_mode_flag) {
            ASSERT(lcd_para->lcd_block_mode_cb!=NULL);
         }
         #ifdef TV_OUT_SUPPORT
            ASSERT(KAL_FALSE == lcd_para->tv_output);
         #endif
      } else {
         lcd_para->block_mode_flag = KAL_TRUE;
         lcd_para->lcd_block_mode_cb = NULL;
         #if (defined(DRV_LCD_MEMORY_OUTPUT))
            lcd_para->memory_output = KAL_FALSE;
         #endif
      }

      _lcd_wait_for_lcd_ready();
      _lcd_check_lcd_buffer_in_intram(lcd_para);
   #endif

   #if (defined(MT6217)||defined(MT6223)||defined(MT6223P)||defined(MT6225))

      lcd_fb_update_17_23_25_series(lcd_para);

   #elif defined(DRV_IDP_SUPPORT)

      lcd_fb_update_19_26_28_series(lcd_para);

   #elif (defined(MT6205B)||defined(MT6208))
      lcd_power_ctrl(KAL_TRUE);
      if (MAIN_LCD == lcd_para->lcd_id) {
         MainLCD->BlockWrite(lcd_para->lcm_start_x, lcd_para->lcm_start_y,
                             lcd_para->lcm_end_x, lcd_para->lcm_end_y);
      } else if (SUB_LCD == lcd_para->lcd_id) {
         SubLCD->BlockWrite(lcd_para->lcm_start_x, lcd_para->lcm_start_y,
                            lcd_para->lcm_end_x, lcd_para->lcm_end_y);
      }
      lcd_power_ctrl(KAL_FALSE);
   #endif
}  /* lcd_fb_update() */



/**
 * Trigger LCD interface to output the MMI screen to one buffer
 *
 * @param lcd_para the parameters for lcd frame buffer update to memory
 *
 * @return None.
 */
#if (!defined(MT6205B)&&!defined(MT6208))
void lcd_fb_update_to_memory(lcd_frame_update_to_mem_struct *lcd_para)
{
   kal_uint16 temp_reg;
   volatile kal_uint16 i;
   kal_uint8 temp_lcd_state;

   if (INT_QueryExceptionStatus()) {
      return;
   }

   if (KAL_TRUE == bWaitForLCDUpdate) {
      lcd_busy_waiting();
      IRQMask(IRQ_LCD_CODE);
      if (KAL_TRUE == bWaitForLCDUpdate) {
         bWaitForLCDUpdate = KAL_FALSE;
         if (LCD_SW_UPDATE_STATE == main_lcd_operation_state) {
            main_lcd_operation_state = LCD_STANDBY_STATE;
         }
         if (LCD_SW_UPDATE_STATE == sub_lcd_operation_state) {
            sub_lcd_operation_state = LCD_STANDBY_STATE;
         }
         config_lcd_layer_window_queue();
         if (lcd_prev_run_block_cb!=NULL) {
            lcd_prev_run_block_cb();
         }
      }
      IRQUnmask(IRQ_LCD_CODE);
   }; /* wait until LCD complete */

   temp_lcd_state=main_lcd_operation_state;
   #ifdef __VIDEO_EDITOR__
      temp_main_lcd_operation_state=main_lcd_operation_state;
   #endif

   /// make sure LCD state is correct.
   /// the state must be idle/stanby/sw trigger update
   #if (defined(CAMERA_MODULE))
      if ((main_lcd_operation_state!=LCD_STANDBY_STATE) &&
          (main_lcd_operation_state!=LCD_SLEEP_STATE)&&
          (main_lcd_operation_state!=LCD_CAMERA_UPDATE_STATE)&&
          (main_lcd_operation_state!=LCD_CAMERA_CMD_QUEUE_STATE)&&
          (main_lcd_operation_state!=LCD_CAMERA_ACTIVE_STATE)&&
          (main_lcd_operation_state!=LCD_CAMERA_ACTIVE_UPDATE_STATE)) {
         ASSERT(0);
      }
      #ifdef DUAL_LCD
      if ((sub_lcd_operation_state!=LCD_STANDBY_STATE) &&
          (sub_lcd_operation_state!=LCD_SLEEP_STATE)&&
          (sub_lcd_operation_state!=LCD_CAMERA_UPDATE_STATE)&&
          (sub_lcd_operation_state!=LCD_CAMERA_CMD_QUEUE_STATE)&&
          (sub_lcd_operation_state!=LCD_CAMERA_ACTIVE_STATE)&&
          (sub_lcd_operation_state!=LCD_CAMERA_ACTIVE_UPDATE_STATE)) {
         ASSERT(0);
      }
      #endif
   #else
      if ((main_lcd_operation_state!=LCD_STANDBY_STATE) &&
          (main_lcd_operation_state!=LCD_SLEEP_STATE)&&
          (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)&&
          (main_lcd_operation_state!=LCD_FW_CMD_QUEUE_STATE)) {
         ASSERT(0);
      }
      #ifdef DUAL_LCD
      if ((sub_lcd_operation_state!=LCD_STANDBY_STATE) &&
          (sub_lcd_operation_state!=LCD_SLEEP_STATE)&&
          (sub_lcd_operation_state!=LCD_FW_UPDATE_STATE)&&
          (sub_lcd_operation_state!=LCD_FW_CMD_QUEUE_STATE)) {
         ASSERT(0);
      }
      #endif
   #endif

   ASSERT(lcd_para->block_mode<=LCD_WM_BLOCK_MODE);

   if (LCD_WM_CONT_MODE == lcd_para->block_mode)
   {
      ASSERT((lcd_para->dest_buffer_size)>=((lcd_para->roi_width * lcd_para->roi_height)<<1));
   }
   else
   {
      ASSERT((lcd_para->dest_buffer_size)>=((lcd_para->dest_block_width * lcd_para->roi_height)<<1));
   }

   ASSERT(0 == (lcd_para->update_layer & (~LCD_LAYER_MASK)));
   ASSERT(0 == (lcd_para->hw_update_layer & (~LCD_LAYER_MASK)));

   lcd_power_ctrl(KAL_TRUE);

   #if !defined(DRV_LCD_MEMORY_OUTPUT)
      SET_LCD_ROI_CTRL_OUTPUT_FORMAT(LCM_16BIT_16_BPP_RGB565_1);
   #elif defined(DRV_LCD_MEMORY_OUTPUT)
      LCD_WRITE_MEM_ONLY;
      REG_LCD_ROI_BACKGROUND_COLOR = lcd_para->roi_background_color;
      #if defined(DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT)//888 support means support 565
      switch(lcd_para->memory_data_format)
      {
         case LCD_WMEM_RGB565:
            LCD_WRITE_MEM_RGB565;
            break;
         case LCD_WMEM_RGB888:
            LCD_WRITE_MEM_RGB888;
            break;
         #if defined(DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT)
         case LCD_WMEM_ARGB8888:
            LCD_WRITE_MEM_ARGB8888;
            break;
         #endif /*DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT*/
         default:
            ASSERT(0);
            break;
         }
      #endif /*DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT*/
   #endif
   SET_LCD_MAIN_WINDOW_SIZE(lcd_para->dest_block_width,lcd_para->roi_height+lcd_para->roi_offset_y);
   SET_LCD_ROI_WINDOW_OFFSET(lcd_para->roi_offset_x,lcd_para->roi_offset_y);
   SET_LCD_ROI_WINDOW_SIZE(lcd_para->roi_width,lcd_para->roi_height);
   SET_LCD_ENABLE_LAYER(lcd_para->update_layer);
   ENABLE_LCD_ROI_CTRL_W2MEM;

   #if defined(DRV_LCD_MEMORY_OUTPUT)
      FIX_LCD_ROI_CTRL_W2MEM_BUG;
      LCD_WRITE_MEM_ONLY;
      DRV_WriteReg32(LCD_ROI_WMEM_ADDR_REG,lcd_para->dest_buffer_address);
   #else
      DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,lcd_para->dest_buffer_address);
   #endif

   DISABLE_LCD_ROI_CTRL_CMD_FIRST;
   if (LCD_WM_BLOCK_MODE == lcd_para->block_mode) {
      SET_LCD_ROI_CTRL_W2MEM_DISCONT;
   } else if (lcd_para->block_mode==LCD_WM_CONT_MODE) {
      SET_LCD_ROI_CTRL_W2MEM_CONT;
   }

   #if defined(DRV_IDP_SUPPORT)
      ENABLE_LCD_CMD_COMPLETE_INT;
      ENABLE_LCD_TRANSFER_COMPLETE_INT;
   #endif

   switch (lcd_para->fb_update_mode) {
   case LCD_SW_TRIGGER_MODE:
      #if (defined(CAMERA_MODULE))
         START_LCD_TRANSFER;
      #else
         #if defined(DRV_IDP_SUPPORT)
            DISABLE_LCD_HW_TRIGGER_UPDATE;
         #endif
         START_LCD_TRANSFER;
         main_lcd_operation_state=LCD_MEM_UPDATE_STATE;
      #endif
      for (i=0;i<10;i++) {};
      lcd_busy_waiting();
      temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
      DISABLE_LCD_ROI_CTRL_W2MEM;
      main_lcd_operation_state=temp_lcd_state;
      break;
   #if defined(DRV_IDP_SUPPORT)
      case LCD_HW_TRIGGER_MODE:
         #if defined(DRV_IDP_6228_SERIES)
         if (LCD_HW_TRIGGER_IBW2 == lcd_para->hw_trigger_src) {
            SET_LCD_IBW2_TRIGGER_LAYER(lcd_para->hw_update_layer);
         } else {
            SET_LCD_IBW1_TRIGGER_LAYER(lcd_para->hw_update_layer);
         }
         #elif defined(DRV_IDP_6238_SERIES)
             /*KKKKK,OK select HW trigger source*/
             switch(lcd_para->hw_trigger_src)
             {
                case LCD_HW_TRIGGER_IRT1:
                   SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT1);
                   break;
                case LCD_HW_TRIGGER_IBW1:
                   SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW1);
                   break;
                case LCD_HW_TRIGGER_IRT2:
                   SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT2);
                   break;
                case LCD_HW_TRIGGER_IBW2:
                   SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW2);
                   break;
                default:
                   ASSERT(0);
                   break;
             }
         #endif
         SET_LCD_HW_TRIGGER_LAYER(lcd_para->hw_update_layer);
         ENABLE_LCD_HW_TRIGGER_UPDATE;
         main_lcd_operation_state=LCD_MEM_UPDATE_STATE;
         START_LCD_TRANSFER;  /* latch the command */
         for (i=0;i<10;i++);
         break;
      case LCD_DIRECT_COUPLE_MODE:
         #if defined(DRV_IDP_6228_SERIES)
         if (lcd_para->hw_trigger_src==LCD_HW_TRIGGER_IBW2) {
            SET_LCD_IBW2_TRIGGER_LAYER(lcd_para->hw_update_layer);
         } else {
            SET_LCD_IBW1_TRIGGER_LAYER(lcd_para->hw_update_layer);
         }

         #elif defined(DRV_IDP_6238_SERIES)
             /*KKKKK,OK selec new DC source*/
             {
                 LCD_LAYER_ENUM layer=LCD_LAYER0;
                 switch(lcd_para->hw_update_layer)
                 {
                    case LCD_LAYER0_ENABLE:
                       layer=LCD_LAYER0;
                       break;
                    case LCD_LAYER1_ENABLE:
                       layer=LCD_LAYER1;
                       break;
                    case LCD_LAYER2_ENABLE:
                       layer=LCD_LAYER2;
                       break;
                    case LCD_LAYER3_ENABLE:
                       layer=LCD_LAYER4;
                       break;
                    case LCD_LAYER4_ENABLE:
                       layer=LCD_LAYER4;
                       break;
                    case LCD_LAYER5_ENABLE:
                       layer=LCD_LAYER5;
                       break;
                    default:
                       ASSERT(0);
                       break;
                 }

                 switch(lcd_para->hw_trigger_src)
                 {
                    case LCD_HW_TRIGGER_IBW1:
                       SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IBW1,layer);
                       SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW1);
                       break;
                    case LCD_HW_TRIGGER_IRT2:
                       SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IRT2,layer);
                       SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IRT2);
                       break;
                    case LCD_HW_TRIGGER_IBW2:
                       SET_LCD_DC_COUPLE_SRC(LCD_IDMA_TRIGGER_SRC_IBW2,layer);
                       SET_LCD_HW_TRIGGER_SRC(LCD_IDMA_TRIGGER_SRC_IBW2);
                       break;
                    default:
                       ASSERT(0);
                       break;
                 }
             }
         #endif
         set_lcd_dc_layer_format(lcd_para->hw_update_layer,KAL_TRUE);
         SET_LCD_DIRECT_COUPLE_LAYER((lcd_para->hw_update_layer));
         ENABLE_LCD_HW_TRIGGER_UPDATE;
         main_lcd_operation_state=LCD_MEM_UPDATE_STATE;
         START_LCD_TRANSFER;  /* latch the command */
         for (i=0;i<10;i++);
         break;
   #endif
   #if defined(DRV_LCD_FW_UPDATE_SUPPORT)
      case LCD_HW_TRIGGER_MODE:
         START_LCD_TRANSFER;
         main_lcd_operation_state = LCD_MEM_UPDATE_STATE;
         for (i=0;i<10;i++);
         lcd_busy_waiting();
         temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
         DISABLE_LCD_ROI_CTRL_W2MEM;
         main_lcd_operation_state = temp_lcd_state;
         break;
   #endif
   }
   lcd_power_ctrl(KAL_FALSE);
}  /* lcd_fb_update_to_memory() */
#endif



/**
 * Stop the hardware trigger LCD update operation.
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 *
 * @return None.
 */
void lcd_stop_hw_update(kal_uint8 lcd_id)
{
   #if defined(DRV_IDP_SUPPORT)
      kal_uint16 temp_reg;
      kal_uint32 hw_layer;
      volatile kal_uint16 i;
      kal_uint32 save_irq_mask;

      #ifdef __SYNC_LCM_SW_SUPPORT__
         lcd_hw_trigger_flag=KAL_FALSE;
         if (sync_lcm_enable_mode==KAL_TRUE) {
            lcd_power_ctrl(KAL_TRUE);
            switch (lcd_id) {
            case MAIN_LCD:
               switch (main_lcd_operation_state) {
               case LCD_HW_UPDATE_STATE:
               case LCD_DC_UPDATE_STATE:
                  while (LCD_IS_RUNNING) {};
                  for (i=0;i<10;i++){};
                  DISABLE_LCD_HW_TRIGGER_UPDATE;
                  if (main_lcd_operation_state==LCD_DC_UPDATE_STATE)
                     set_lcd_dc_layer_format(lcd_hw_trigger_layer,KAL_FALSE);
                  temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
                  main_lcd_operation_state=LCD_STANDBY_STATE;
                  break;
               case LCD_HW_CMD_QUEUE_STATE:
               case LCD_DC_CMD_QUEUE_STATE:
                  save_irq_mask=SaveAndSetIRQMask();
                  RestoreIRQMask(save_irq_mask);
                  while (LCD_IS_RUNNING){};
                  DISABLE_LCD_HW_TRIGGER_UPDATE;
                  STOP_LCD_TRANSFER;
                  DISABLE_LCD_TRANSFER_COMPLETE_INT;
                  /*wake up MMI*/
                  if (main_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)
                     set_lcd_dc_layer_format(lcd_hw_trigger_layer,KAL_FALSE);
                  kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
                  main_lcd_operation_state=LCD_STANDBY_STATE;
                  break;
               #ifdef TV_OUT_SUPPORT
               case LCD_HW_UPDATE_SLEEP_STATE:
                  lcd_sleeping_state=KAL_FALSE;
                  main_lcd_operation_state=LCD_SLEEP_STATE;
               #endif
               case LCD_SLEEP_STATE:
               case LCD_STANDBY_STATE:
                  while (LCD_IS_RUNNING){};
                  STOP_LCD_TRANSFER;
                  temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
                  kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
                  break;
               default:
                  ASSERT(0);
                  break;
               }
               break;
            #ifdef DUAL_LCD
            case SUB_LCD:
               switch (sub_lcd_operation_state) {
               case LCD_HW_UPDATE_STATE:
                  while (LCD_IS_RUNNING) {};
                  temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
                  sub_lcd_operation_state=LCD_STANDBY_STATE;
                  break;
               #ifdef TV_OUT_SUPPORT
               case LCD_HW_UPDATE_SLEEP_STATE:
               case LCD_DC_UPDATE_SLEEP_STATE:
                  lcd_sleeping_state=KAL_FALSE;
                  sub_lcd_operation_state=LCD_SLEEP_STATE;
               #endif
               case LCD_SLEEP_STATE:
               case LCD_STANDBY_STATE:
                  while (LCD_IS_RUNNING){};
                  STOP_LCD_TRANSFER;
                  temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
                  kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
               break;
               default:
                  ASSERT(0);
                  break;
               }
               break;
            #endif /* DUAL_LCD */
            default:
               ASSERT(0);
               break;
            }
            #if (!defined(__MAUI_BASIC__))&& !defined(__L1_STANDALONE__)
                  if ((SCENARIO_MPEG_ENCODE_ID == current_image_data_path_owner)||
                   (SCENARIO_MPEG_DECODE_ID == current_image_data_path_owner)) {
                  #if defined(DRV_IDP_6228_SERIES)
                  STOP_IBW2;
                  STOP_IMGDMA_VIDEO_DECODE;
               #elif defined(DRV_IDP_6238_SERIES)
                     /*KKKKK,OK not necessary in 6238, because these two function will be closed in IDP*/
               #endif //DRV_IDP_6238_SERIES
               }

            #endif //(!defined(__MAUI_BASIC__))&& !defined(__L1_STANDALONE__))
            DISABLE_LCD_ROI_CTRL_W2MEM;
            lcd_power_ctrl(KAL_FALSE);
            return ;
         }
      #endif /* __SYNC_LCM_SW_SUPPORT__ */

      #ifdef TV_OUT_SUPPORT
         if (((main_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)||(main_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
              (main_lcd_operation_state==LCD_DC_SLEEP_CMD_QUEUE_STATE)||(main_lcd_operation_state==LCD_HW_SLEEP_CMD_QUEUE_STATE))&&
              (lcd_hard_trigger_flag==1)) {

            while (tv_full_screen>0) {
               if ((current_image_data_path_owner==SCENARIO_MPEG_ENCODE_ID)||
                   (current_image_data_path_owner==SCENARIO_MPEG_DECODE_ID)) {
                        #if defined(DRV_IDP_6228_SERIES)
                  STOP_IBW2;
                  STOP_IMGDMA_VIDEO_DECODE;
                  START_IBW2;
                  START_IMGDMA_VIDEO_DECODE;
                        #elif defined(DRV_IDP_6238_SERIES)
                        //KKKKK, need to check
                           STOP_IBW2();
                           STOP_IMGDMA_VIDEO_DECODE();
                           START_IBW2();
                           START_IMGDMA_VIDEO_DECODE();
                        #endif
                  for (i=0;i<10000;i++);
                  lcd_busy_waiting();
                  save_irq_mask=SaveAndSetIRQMask();
                  if (tv_full_screen>0) {
                     tv_full_screen--;
                  }
                  RestoreIRQMask(save_irq_mask);
               } else {
                  break;
               }
            }
            if (main_lcd_operation_state==LCD_HW_SLEEP_CMD_QUEUE_STATE) {
               main_lcd_operation_state=LCD_HW_UPDATE_SLEEP_STATE;
            } else if (main_lcd_operation_state==LCD_DC_SLEEP_CMD_QUEUE_STATE) {
               main_lcd_operation_state=LCD_DC_UPDATE_SLEEP_STATE;
            }
         }
      #endif

      lcd_power_ctrl(KAL_TRUE);

      switch (lcd_id) {
      case MAIN_LCD:
         switch (main_lcd_operation_state) {
         case LCD_HW_UPDATE_STATE:
         case LCD_MEM_UPDATE_STATE:
         case LCD_DC_UPDATE_STATE:
            lcd_busy_waiting();
            for (i=0;i<10;i++){};
            temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
            DISABLE_LCD_HW_TRIGGER_UPDATE;
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            if (main_lcd_operation_state==LCD_DC_UPDATE_STATE) {
               set_lcd_dc_layer_format(lcd_hw_trigger_layer,KAL_FALSE);
            }
            main_lcd_operation_state=LCD_STANDBY_STATE;
            break;
         case LCD_HW_CMD_QUEUE_STATE:
         case LCD_DC_CMD_QUEUE_STATE:
            kal_sleep_task(1);
            save_irq_mask=SaveAndSetIRQMask();
            lcd_hw_trigger_flag=KAL_FALSE;
            RestoreIRQMask(save_irq_mask);
            if (LCD_HW_CMD_QUEUE_STATE == main_lcd_operation_state) {
               hw_layer= GET_LCD_HW_TRIGGER_LAYER;
               lcd_busy_waiting();
            } else {
               hw_layer= GET_LCD_DIRECT_COUPLE_LAYER;
            }
            for (i=0;i<6000;i++){};
            DISABLE_LCD_HW_TRIGGER_UPDATE;
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            STOP_LCD_TRANSFER;
            DISABLE_LCD_TRANSFER_COMPLETE_INT;
            #if defined(DRV_IDP_6219_SERIES)
            switch (hw_layer) {
            case LCD_LAYER0_ENABLE:
               REG_LCD_LAYER0_BUFF_ADDR=DRV_Reg32(IMGDMA_IBW2_BSADDR1);
               break;
            case LCD_LAYER1_ENABLE:
               REG_LCD_LAYER1_BUFF_ADDR=DRV_Reg32(IMGDMA_IBW2_BSADDR1);
               break;
            case LCD_LAYER2_ENABLE:
               REG_LCD_LAYER2_BUFF_ADDR=DRV_Reg32(IMGDMA_IBW2_BSADDR1);
               break;
            case LCD_LAYER3_ENABLE:
               REG_LCD_LAYER3_BUFF_ADDR=DRV_Reg32(IMGDMA_IBW2_BSADDR1);
               break;
            }
            #elif defined(DRV_IDP_6238_SERIES)
                //KKKKK
               /*ask MMI to fill layer address*/
            #endif
            if (LCD_DC_CMD_QUEUE_STATE == main_lcd_operation_state) {
               set_lcd_dc_layer_format(lcd_hw_trigger_layer,KAL_FALSE);
            }
            /*wake up MMI*/
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            main_lcd_operation_state=LCD_STANDBY_STATE;
            break;
         #ifdef TV_OUT_SUPPORT
         case LCD_DC_UPDATE_SLEEP_STATE:
         case LCD_HW_UPDATE_SLEEP_STATE:
            lcd_sleeping_state=KAL_FALSE;
            main_lcd_operation_state=LCD_SLEEP_STATE;
         #endif
         case LCD_SLEEP_STATE:
         case LCD_STANDBY_STATE:
            DISABLE_LCD_HW_TRIGGER_UPDATE;
            lcd_busy_waiting();
            STOP_LCD_TRANSFER;
            temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            break;

         case LCD_FW_UPDATE_STATE:
         case LCD_FW_CMD_QUEUE_STATE:
            lcd_busy_waiting();
            main_lcd_operation_state=LCD_STANDBY_STATE;
            break;
         default:
            ASSERT(0);
            break;
      }
      break;
      #ifdef DUAL_LCD
      case SUB_LCD:
         switch (sub_lcd_operation_state) {
         case LCD_HW_UPDATE_STATE:
         case LCD_MEM_UPDATE_STATE:
            lcd_busy_waiting();
         case LCD_DC_UPDATE_STATE:
            for (i=0;i<10;i++){};
            temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
            DISABLE_LCD_HW_TRIGGER_UPDATE;
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            if (LCD_DC_UPDATE_STATE == sub_lcd_operation_state) {
               set_lcd_dc_layer_format(lcd_hw_trigger_layer,KAL_FALSE);
            }
            sub_lcd_operation_state=LCD_STANDBY_STATE;
            break;
         #ifdef TV_OUT_SUPPORT
         case LCD_DC_UPDATE_SLEEP_STATE:
         case LCD_HW_UPDATE_SLEEP_STATE:
            lcd_sleeping_state=KAL_FALSE;
            sub_lcd_operation_state=LCD_SLEEP_STATE;
         #endif
         case LCD_SLEEP_STATE:
         case LCD_STANDBY_STATE:
            DISABLE_LCD_HW_TRIGGER_UPDATE;
            lcd_busy_waiting();
            STOP_LCD_TRANSFER;
            temp_reg=DRV_Reg(LCD_INT_STATUS_REG);
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            break;
         default:
            ASSERT(0);
            break;
         }
         break;
      #endif /* DUAL_LCD */
      default:
         ASSERT(0);
         break;
      }
      #if (!defined(__MAUI_BASIC__)&& !defined(__L1_STANDALONE__))
         #if defined(DRV_IDP_6228_SERIES)
         if ((SCENARIO_MPEG_ENCODE_ID == current_image_data_path_owner)||
             (SCENARIO_MPEG_DECODE_ID == current_image_data_path_owner)) {
            STOP_IBW2;
            STOP_IMGDMA_VIDEO_DECODE;
         }
         #elif defined(DRV_IDP_6238_SERIES)
            /*KKKKK,OK not necessary in 6238, because these two function will be closed in IDP*/
         #endif //DRV_IDP_6238_SERIES
      #endif //(!defined(__MAUI_BASIC__))&& !defined(__L1_STANDALONE__))

      DISABLE_LCD_ROI_CTRL_W2MEM;
      lcd_power_ctrl(KAL_FALSE);
   #elif defined(DRV_LCD_FW_UPDATE_SUPPORT)
      switch (lcd_id) {
      case MAIN_LCD:
         lcd_busy_waiting();
         kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
         main_lcd_operation_state=LCD_STANDBY_STATE;
         lcd_preview_count=0;
         lcd_wait_fw_update_event=KAL_FALSE;
         break;
      #ifdef DUAL_LCD
      case SUB_LCD:
         lcd_busy_waiting();
         kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
         sub_lcd_operation_state=LCD_STANDBY_STATE;
         lcd_preview_count=0;
         lcd_wait_fw_update_event=KAL_FALSE;
         break;
      #endif
      }
   #endif
}  /* lcd_stop_hw_update() */



void lcd_reset_preview(void)
{
   #if defined(DRV_LCD_FW_UPDATE_SUPPORT)
      lcd_preview_count=0;
      kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
      lcd_hw_trigger_flag=KAL_FALSE;
   #endif
}



/**
 * Dump the information to LCD panel when an assert occurs
 *
 * @param lcd_id  MAIN_LCD or SUB_LCD
 * @param start_x start x of LCD panel
 * @param start_y start y of LCD panel
 * @param end_x   end x of LCD panel
 * @param end_y   end y of LCD panel
 * @param roi_offset_x ROI window offset x
 * @param roi_offset_y ROI window offset y
 * @param update_layer LCD update layers
 *
 * @return None.
 */
void assert_lcd_fb_update(kal_uint8 lcd_id, kal_uint16 start_x, kal_uint16 start_y, kal_uint16 end_x,
                          kal_uint16 end_y,kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint32 update_layer)

{
   volatile kal_uint32 i;
   lcd_power_ctrl(KAL_TRUE);

   #if (!defined(MT6205B)&&!defined(MT6208))
      REG_LCD_START=0;
      CLEAR_LCD_CTRL_RESET_PIN;
      for (i=0;i<0x100000;i++);
      SET_LCD_CTRL_RESET_PIN;
      for (i=0;i<0x100000;i++);

      set_lcd_layer_roate(update_layer,LCD_LAYER_ROTATE_NORMAL);

      #if (defined(DRV_LCD_HW_TRIGGER_SUPPORT))
         DISABLE_LCD_HW_TRIGGER_UPDATE;
      #endif
   #elif (defined(MT6205B))
      DRV_WriteReg(LCD_START,LCD_STOP_BIT);
      DRV_WriteReg(LCD_PCON,(0x0000));
   #endif
   #if (!defined(__MAUI_BASIC__)&& !defined(__L1_STANDALONE__))
      #if defined(DRV_IDP_6228_SERIES)
      STOP_IBW2;
         if ((current_image_data_path_owner==SCENARIO_MPEG_ENCODE_ID)||
         (current_image_data_path_owner==SCENARIO_MPEG_DECODE_ID)) {
            SET_LCD_LAYER0_WINDOW_SIZE(end_x-start_x+1,end_y-start_y+1);
         }
      #elif defined(DRV_IDP_6238_SERIES)
         /*KKKKK,OK stop all hw trigger module*/
         DISABLE_IRT1();
         STOP_IBW1();
      if ((current_image_data_path_owner==SCENARIO_MPEG_ENCODE_ID)||
       (current_image_data_path_owner==SCENARIO_MPEG_DECODE_ID)) {
         SET_LCD_LAYER0_WINDOW_SIZE(end_x-start_x+1,end_y-start_y+1);
      }
      #endif //DRV_IDP_6238_SERIES

   #endif //(!defined(__MAUI_BASIC__))&& !defined(__L1_STANDALONE__))
   MainLCD->Init(0xFFFF, 0);
   lcd_assert_fail=KAL_FALSE;
   #if defined(CAMERA_MODULE)
      ext_cam_func->cam_module_power_off();
   #endif
   #if (!defined(MT6205B)&&!defined(MT6208))
      SET_LCD_ROI_CTRL_OUTPUT_FORMAT(MAIN_LCD_OUTPUT_FORMAT);
      DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
      DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
      SET_LCD_ROI_WINDOW_OFFSET(roi_offset_x,roi_offset_y);
      SET_LCD_ROI_WINDOW_SIZE(end_x-start_x+1,end_y-start_y+1);
      SET_LCD_ENABLE_LAYER(update_layer);
   #endif
   MainLCD->BlockWrite(start_x,start_y,end_x,end_y);
}

/*Begin: the following functions are for LCD fw update driver*/
/**
 * Config lcd layer address for FW update layer
 *
 * @param addr LCD layer addr
 *
 * @return None.
 */
kal_bool lcd_debug=KAL_TRUE;
void LCD_config_fw_layer_address(kal_uint32 addr)
{
   #if defined(DRV_LCD_FW_UPDATE_SUPPORT)
      if(lcd_debug==KAL_TRUE) {
         kal_uint32 lcd_layer_base_addr=LCD_LAYER0_BASE_ADDR;

         lcd_layer_base_addr+=lcd_fw_update_layer*LCD_LAYER_ADDR_OFFSET;
         DRV_WriteReg32((lcd_layer_base_addr+0x08),addr);
      }
   #endif
}

/*Begin: the following functions are for 3G324M*/
/**
 * Config lcd layer address for 3G324M
 *
 * @param addr LCD layer addr
 *
 * @return None.
 */
void LCD_config_fullvideo_layer_address(kal_uint32 layer, kal_uint32 addr)
{
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__3G_VIDEO_CALL__
}

#ifdef MT6225_IDP_DEBUG
   kal_uint32 dbg_time4=0;
#endif



/**
 * Config the address of specified lcd layer and start LCD transfer
 *
 * @param layer LCD layer
 * @param addr  address of LCD layer
 *
 * @return None.
 */
static void _lcd_fb_update_fw(kal_uint8 lcd_layer, kal_uint32 addr)
{
#if defined(DRV_LCD_FW_UPDATE_SUPPORT)
   kal_uint32 lcd_layer_base_addr=LCD_LAYER0_BASE_ADDR;
   kal_uint32 save_irq_mask;
   kal_uint8 i;

   if (LCD_IS_RUNNING) {
       /*not update because LCD is busy*/
      #ifdef MT6225_IDP_DEBUG
         kal_prompt_trace(MOD_BMT,"drop frame");
      #endif
      return;
   }
   lcd_layer_base_addr+=lcd_fw_update_layer*LCD_LAYER_ADDR_OFFSET;
   DRV_WriteReg32((lcd_layer_base_addr+0x08),addr);
   if (LCD_FW_CMD_QUEUE_STATE == main_lcd_operation_state) {
      main_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_JPEG_VIDEO;
      if (MAIN_LCD == current_update_lcd) {
         lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
         lcd_hw_trigger_flag=KAL_TRUE;
      }
      #ifdef DUAL_LCD
      else if (SUB_LCD == current_update_lcd)
      {
         lcd_fb_update((lcd_frame_update_struct *) &sub_lcd_fb_update_para);
         lcd_hw_trigger_flag=KAL_TRUE;
      }
      #endif
      kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
   } else {
      #ifdef MT6225_IDP_DEBUG
         dbg_time4=drv_get_current_time();
         kal_prompt_trace(MOD_BMT,"enable LCD=%d",dbg_time4);
      #endif
      if (KAL_TRUE == lcd_hw_trigger_flag) {
         /*back to normal LCD update(video size) size*/
         DRV_WriteReg32(LCD_ROI_CTRL_REG,lcd_hw_trigger_roi_ctrl);
         DRV_WriteReg32(LCD_ROI_OFFSET_REG,lcd_hw_trigger_roi_offset);
         DRV_WriteReg32(LCD_ROI_SIZE_REG,lcd_hw_trigger_roi_size);
         for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++) {
            *((volatile unsigned int *) (LCD_CMD_PARAMETER_ADDR+(i<<2)))=lcd_hw_trigger_para[i];
         }
         START_LCD_TRANSFER;
         lcd_hw_trigger_flag=KAL_FALSE;
      } else {
         START_LCD_TRANSFER;
      }

      if (KAL_TRUE == lcd_wait_fw_update_event) {
         kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
      }
   }
#endif
}
#ifdef MT6225_IDP_DEBUG
kal_uint32 dbg_time2=0;
#endif



/**
 * Update LCD in camera preview
 *
 * @param layer   LCD layer
 * @param buffer1 buffer1 addr
 * @param buffer2 buffer2 addr
 *
 * @return None.
 */
void LCD_preview(kal_uint32 layer, kal_uint32 buffer1, kal_uint32 buffer2 )
{
#if defined(DRV_LCD_FW_UPDATE_SUPPORT)

   #ifndef DUAL_LCD
   if (MAIN_LCD == current_update_lcd) {
      if ((main_lcd_operation_state!=LCD_FW_CMD_QUEUE_STATE)&&
          (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
         return;
      }
   }
   #else
   if (MAIN_LCD == current_update_lcd) {
      if ((main_lcd_operation_state!=LCD_FW_CMD_QUEUE_STATE)&&
          (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
         return;
      }
   } else if(SUB_LCD == current_update_lcd) {
      if((sub_lcd_operation_state!=LCD_FW_CMD_QUEUE_STATE)&&
         (sub_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
         return;
      }
   }
   #endif
   #ifdef MT6225_IDP_DEBUG
      dbg_time2=drv_get_current_time();
   #endif
   if(lcd_preview_count==0) {
      #ifdef MT6225_IDP_DEBUG
      kal_prompt_trace(MOD_BMT,"buf 1=%d",dbg_time2);
      #endif
      _lcd_fb_update_fw(lcd_fw_update_layer, buffer1);
      lcd_preview_count=1;
   } else {
      #ifdef MT6225_IDP_DEBUG
      kal_prompt_trace(MOD_BMT,"buf 2=%d", dbg_time2);
      #endif
      _lcd_fb_update_fw(lcd_fw_update_layer, buffer2);
      lcd_preview_count=0;
   }
#endif
}



/**
 * Update LCD in video recoder
 *
 * @param layer   LCD layer
 * @param buffer  buffer addr
 *
 * @return None.
 */
void LCD_recode_preview(kal_uint32 layer, kal_uint32 buffer)
{

   #ifndef DUAL_LCD
   if (MAIN_LCD == current_update_lcd) {
      if ((main_lcd_operation_state!=LCD_FW_CMD_QUEUE_STATE)&&
          (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
         return;
      }
   }
   #else
   if (MAIN_LCD == current_update_lcd) {
      if((main_lcd_operation_state!=LCD_FW_CMD_QUEUE_STATE)&&
         (main_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
         return;
      }
   } else if(SUB_LCD == current_update_lcd) {
      if((sub_lcd_operation_state!=LCD_FW_CMD_QUEUE_STATE)&&
         (sub_lcd_operation_state!=LCD_FW_UPDATE_STATE)) {
         return;
      }
   }
   #endif

   _lcd_fb_update_fw(lcd_fw_update_layer, buffer);

}

/*End: the following functions are for LCD fw update driver*/



/*Begin: the following functions are for play mjpeg*/

/**
 * Stop playing MJPEG
 *
 * @param lcd_id  MAIN_LCD or SUB_LCD
 *
 * @return None.
 */
void lcd_stop_jpeg_video_play(kal_uint8 lcd_id)
{
   #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXX?, need check in 6225
      extern kal_timerid sync_lcm_timer_handle;
   #endif
   #ifdef MJPG_SUPPORT
   kal_uint32 save_irq_mask;
   lcd_power_ctrl(KAL_TRUE);

   save_irq_mask=SaveAndSetIRQMask();
   if (lcd_id==MAIN_LCD)
      main_lcd_operation_state=LCD_STANDBY_STATE;
   #ifdef DUAL_LCD
   else if (lcd_id==SUB_LCD)
      sub_lcd_operation_state=LCD_STANDBY_STATE;
   #endif
   RestoreIRQMask(save_irq_mask);
   kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
   kal_prompt_trace(MOD_BMT,"lcd_stop_jpeg_video_play() state=%d",main_lcd_operation_state);

   #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO, add in 6225
		EINT_Mask(sync_lcm_channel_number);
      sync_lcm_enable_mode=KAL_FALSE;
      sync_lcm_update_cb=NULL;
		kal_cancel_timer(sync_lcm_timer_handle);
   #endif

   lcd_power_ctrl(KAL_FALSE);
   #endif/*MJPG_SUPPORT*/
}



#ifdef __SYNC_LCM_SW_SUPPORT__//XXXXX?, need check in 6225
void sync_lcm_jpeg_video_play_cb(void)//XXXXX?, need to check in 6225
{
#ifdef MJPG_SUPPORT
   extern lcd_frame_update_struct jpeg_video_play_lcd_data;

   if (KAL_TRUE == preview_frame_update_flag){
      #ifndef DUAL_LCD
      if (main_lcd_operation_state==LCD_JPEG_VIDEO_CMD_QUEUE_STATE)
      #else
      if ((main_lcd_operation_state==LCD_JPEG_VIDEO_CMD_QUEUE_STATE)||
            (sub_lcd_operation_state==LCD_JPEG_VIDEO_CMD_QUEUE_STATE))
      #endif
      {
         if (LCD_JPEG_VIDEO_CMD_QUEUE_STATE == main_lcd_operation_state)
         {
            main_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_JPEG_VIDEO;
            kal_prompt_trace(MOD_BMT,"MMI start:lcd_jpeg_video_play() state=%d, time=%d",main_lcd_operation_state,drv_get_current_time());
            lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            kal_prompt_trace(MOD_BMT,"MMI end:lcd_jpeg_video_play() state=%d, time=%d",main_lcd_operation_state,drv_get_current_time());
         }
      #ifdef DUAL_LCD
         else  if (LCD_JPEG_VIDEO_CMD_QUEUE_STATE == sub_lcd_operation_state)
         {
            sub_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_JPEG_VIDEO;
            lcd_fb_update((lcd_frame_update_struct *) &sub_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
         }
      #endif
      }
      else if ((LCD_JPEG_VIDEO_UPDATE_STATE == main_lcd_operation_state) ||
          (LCD_JPEG_VIDEO_UPDATE_STATE == sub_lcd_operation_state)) {
         kal_prompt_trace(MOD_BMT,"MJPEG start:lcd_jpeg_video_play() state=%d, time=%d",main_lcd_operation_state,drv_get_current_time());
         lcd_fb_update((lcd_frame_update_struct *) &jpeg_video_play_lcd_data);
         kal_prompt_trace(MOD_BMT,"MJPEG end:lcd_jpeg_video_play() state=%d, time=%d",main_lcd_operation_state,drv_get_current_time());
         preview_frame_update_flag=KAL_FALSE;
         if (KAL_TRUE == lcd_wait_fw_update_event) {
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
         }
      }

//      preview_frame_update_flag=KAL_FALSE;
   }
#endif /*MJPG_SUPPORT*/
}
#endif//__SYNC_LCM_SW_SUPPORT__
/**
 * Play MJPEG
 *
 * @param display_jpeg display decoded jpeg file or not(lcd_para)
 * @param lcd_para     lcd updata parameter
 *
 * @return None.
 */
void lcd_jpeg_video_play(kal_bool display_jpeg, lcd_frame_update_struct *lcd_para)
{
#ifdef MJPG_SUPPORT


   #ifdef  __SYNC_LCM_SW_SUPPORT__//XXXXX?, need to check in 6225
      if (KAL_FALSE == sync_lcm_enable_mode){
   #else
      if (1){
   #endif
   #ifndef DUAL_LCD
   if (main_lcd_operation_state==LCD_JPEG_VIDEO_CMD_QUEUE_STATE)
   #else
   if ((main_lcd_operation_state==LCD_JPEG_VIDEO_CMD_QUEUE_STATE)||
         (sub_lcd_operation_state==LCD_JPEG_VIDEO_CMD_QUEUE_STATE))
   #endif
   {
      if (LCD_JPEG_VIDEO_CMD_QUEUE_STATE == main_lcd_operation_state)
      {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
         main_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_JPEG_VIDEO;
#if 0
/* under construction !*/
#endif
         lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
#if 0
/* under construction !*/
/* under construction !*/
#endif
         kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
         kal_prompt_trace(MOD_BMT,"1:lcd_jpeg_video_play() state=%d",main_lcd_operation_state);
      }
   #ifdef DUAL_LCD
      else  if (LCD_JPEG_VIDEO_CMD_QUEUE_STATE == sub_lcd_operation_state)
      {
         sub_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_JPEG_VIDEO;
         lcd_fb_update((lcd_frame_update_struct *) &sub_lcd_fb_update_para);
         kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
      }
   #endif
   }

   if (KAL_TRUE == display_jpeg) {
      if ((LCD_JPEG_VIDEO_UPDATE_STATE == main_lcd_operation_state) ||
          (LCD_JPEG_VIDEO_UPDATE_STATE == sub_lcd_operation_state)) {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
         lcd_fb_update((lcd_frame_update_struct *) lcd_para);
#if 0
/* under construction !*/
/* under construction !*/
#endif
         kal_prompt_trace(MOD_BMT,"2:lcd_jpeg_video_play() state=%d",main_lcd_operation_state);
         if (KAL_TRUE == lcd_wait_fw_update_event) {
            kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
         }
      }
   }
      }
      #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXX?, need to check in 6225
      else if (KAL_TRUE == sync_lcm_enable_mode){
         preview_frame_update_flag=KAL_TRUE;
      }
      #endif // __SYNC_LCM_SW_SUPPORT__
#endif /*MJPG_SUPPORT*/
}



/**
 * Start to play MJPEG
 *
 * @param lcd_para     lcd updata parameter
 *
 * @return None.
 */
void lcd_start_jpeg_video_play(lcd_frame_update_struct *lcd_para)
{
#ifdef MJPG_SUPPORT
   lcd_power_ctrl(KAL_TRUE);

   #ifndef DUAL_LCD
      while (main_lcd_operation_state!=LCD_STANDBY_STATE)
   #else
      while ((main_lcd_operation_state!=LCD_STANDBY_STATE)||
             (sub_lcd_operation_state!=LCD_STANDBY_STATE))
   #endif
   {
      kal_sleep_task(1);
   }

   if (MAIN_LCD == lcd_para->lcd_id)
   {
      main_lcd_operation_state = LCD_JPEG_VIDEO_UPDATE_STATE;
      main_lcd_fb_update_para.lcm_start_x = lcd_para->lcm_start_x;
      main_lcd_fb_update_para.lcm_start_y = lcd_para->lcm_start_y;
      main_lcd_fb_update_para.lcm_end_x = lcd_para->lcm_end_x;
      main_lcd_fb_update_para.lcm_end_y = lcd_para->lcm_end_y;
      main_lcd_fb_update_para.roi_offset_x = lcd_para->roi_offset_x;
      main_lcd_fb_update_para.roi_offset_y = lcd_para->roi_offset_y;
   } else if (SUB_LCD == lcd_para->lcd_id) {
      sub_lcd_operation_state = LCD_JPEG_VIDEO_UPDATE_STATE;
      sub_lcd_operation_state = LCD_JPEG_VIDEO_UPDATE_STATE;
      sub_lcd_fb_update_para.lcm_start_x = lcd_para->lcm_start_x;
      sub_lcd_fb_update_para.lcm_start_y = lcd_para->lcm_start_y;
      sub_lcd_fb_update_para.lcm_end_x = lcd_para->lcm_end_x;
      sub_lcd_fb_update_para.lcm_end_y = lcd_para->lcm_end_y;
      sub_lcd_fb_update_para.roi_offset_x = lcd_para->roi_offset_x;
      sub_lcd_fb_update_para.roi_offset_y = lcd_para->roi_offset_y;
   } else {
      ASSERT(0);
   }
   kal_prompt_trace(MOD_BMT, "lcd_start_jpeg_video_play() state=%d",main_lcd_operation_state);

   #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO
       sync_lcm_update_cb=sync_lcm_jpeg_video_play_cb;
       sync_lcm_enable_mode=KAL_TRUE;
       EINT_UnMask(sync_lcm_channel_number);
   #endif //__SYNC_LCM_SUPPORT
   lcd_power_ctrl(KAL_FALSE);
#endif
}

