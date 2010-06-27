/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   lcd_isr_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This function implements LCD LISR and HISR
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
 * $Revision$
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
 * Add LCD driver feature: background color and memory output
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
 * Update header.
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "lcd_if.h"
#include "drv_hisr.h"

#ifdef DRV_IDP_SUPPORT
   #include "visual_comm.h"
   #include "img_comm.h"
   #include "imgproc.h"
   #include "imgdma.h"
   #if (defined(ISP_SUPPORT))
      #include "isp_if.h"
   #endif
   #ifdef TV_OUT_SUPPORT
      #include "tv_out.h"
      #include "2d_engine.h"
   #endif
#endif/* DRV_IDP_SUPPORT*/
#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
   #include "SST_sla.h"
#endif

#ifdef TV_OUT_SUPPORT
   extern kal_uint32 tv_output_replace_data;
   extern g2d_buffer_struct g2d_tv_output_dest_buff;
   extern g2d_buffer_struct g2d_tv_output_src_buff;
   extern g2d_bitblt_struct g2d_tv_output_bitblt;
   extern kal_uint8 current_g2d_tv_output_bitblt_buffer;
#endif

#ifdef __SYNC_LCM_SW_SUPPORT__
   extern kal_uint8 wait_lcd_restore_config_flag;
#endif



/**
 * LCD interface LISR entry
 *
 * @param None.
 *
 * @return None.
 */
void lcd_LISR(void)
{
#if (!defined(MT6205B)&&!defined(MT6208)) 
   kal_uint32 interrupt_status;

   if (DRV_Reg(DRVPDN_CON1) & DRVPDN_CON1_LCD)
   {
      ASSERT(0);
   }
   IRQMask(IRQ_LCD_CODE);
   interrupt_status=DRV_Reg(LCD_INT_STATUS_REG);

   #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
      if (interrupt_status & LCD_INT_STATUS_COMPLETE_BIT) {
         SLA_HWLogging("LCD", SA_stop);
      }
   #endif

#if !defined(DRV_IDP_SUPPORT)
   lcd_transfer_complete = KAL_TRUE;
   drv_active_hisr(DRV_LCD_HISR_ID);
#elif defined(DRV_IDP_SUPPORT)
   if (interrupt_status & LCD_INT_STATUS_COMPLETE_BIT)
   {
   #ifdef __SYNC_LCM_SW_SUPPORT__
      if ((KAL_TRUE == sync_lcm_enable_mode) &&
          (LCD_HW_CMD_QUEUE_STATE == main_lcd_operation_state) &&
          (KAL_FALSE == wait_lcd_restore_config_flag)) {
         lcd_cmd_latch_complete = KAL_TRUE;
      } else if (KAL_TRUE == wait_lcd_restore_config_flag) {
         wait_lcd_restore_config_flag=KAL_FALSE;
      }
      /* wait one more lcd update trigger to make sure MMI's icon/menu is updated */
   #endif
   lcd_transfer_complete = KAL_TRUE;
   #ifdef TV_OUT_SUPPORT
      /*for TVout, configure TVout buffer address and LCD memory output address*/
      if (TV_OUT_OWNER_LCD == tv_output_owner)
      {
         kal_bool update_next_buffer = KAL_TRUE;
         if (0 == tv_out_current_fb)
         {
            if (tv_full_screen>1) /*MMI size*/
            {
               if (*((volatile unsigned int *) tv_output_buffer_offset_address1)!=tv_output_replace_data)
               {
                  if (TV_OUTPUT_MODE1 == tv_output_config_data.tv_output_mode) {
                     tv_fb_update(TV_OUT_OWNER_LCD,tv_output_buffer_base_address1);
                  } else if (TV_OUTPUT_MODE4 == tv_output_config_data.tv_output_mode) {
                     tv_output_buffer_rotate=1;
                  }
                  lcd_mem_out_address_shadow1=tv_output_buffer_offset_address2;
                  *((volatile unsigned int *) tv_output_buffer_offset_address2)=tv_output_replace_data;
                  tv_full_screen--;
               }
               else
                  update_next_buffer = KAL_FALSE;
            } else {
               /// back to video size
               if (TV_OUTPUT_MODE1 == tv_output_config_data.tv_output_mode) {
                  tv_fb_update(TV_OUT_OWNER_LCD,tv_output_buffer_base_address1);
               } else if (TV_OUTPUT_MODE4 == tv_output_config_data.tv_output_mode) {
                  tv_output_buffer_rotate=1;
               }
               lcd_mem_out_address_shadow1=main_lcd_fb_update_para.tv_output_frame_buffer2_address;
            }
         }
         else
         {
            if (tv_full_screen>1)/*MMI size*/
            {
               if (*((volatile unsigned int *) tv_output_buffer_offset_address2)!=tv_output_replace_data)
               {
                  if (tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE1)
                     tv_fb_update(TV_OUT_OWNER_LCD,tv_output_buffer_base_address2);
                  else if (tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE4)
                     tv_output_buffer_rotate=2;
                  lcd_mem_out_address_shadow1=tv_output_buffer_offset_address1;
                  *((volatile unsigned int *) tv_output_buffer_offset_address1)=tv_output_replace_data;
                  tv_full_screen--;
               }
               else
                  update_next_buffer = KAL_FALSE;
            }
            else/*back to video size*/
            {
               if (tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE1)
                  tv_fb_update(TV_OUT_OWNER_LCD,tv_output_buffer_base_address2);
               else if (tv_output_config_data.tv_output_mode==TV_OUTPUT_MODE4)
                  tv_output_buffer_rotate=2;
               lcd_mem_out_address_shadow1=main_lcd_fb_update_para.tv_output_frame_buffer1_address;
            }
         }
         if (KAL_TRUE == update_next_buffer)
         {
            tv_out_current_fb++;
            tv_out_current_fb&=0x01;
            tv_output_buffer_count++;
            if (0xFF == tv_output_buffer_count)
            {
               tv_output_buffer_count=3;
            }
            /*When back to video size, we modify memory out addr in the HISR with ROI setting.
              This can avoid video update issue(ROI and memory content are not sync) before
              finishing ROI setting*/
            if (tv_output_buffer_count!=2)
            {
            REG_LCD_ROI_WMEM_ADDR=lcd_mem_out_address_shadow1;
            #ifdef __SYNC_LCM_SW_SUPPORT__
            if (sync_lcm_enable_mode==KAL_TRUE)
            {
                if ((main_lcd_operation_state!=LCD_HW_CMD_QUEUE_STATE)||                
                    (main_lcd_operation_state!=LCD_HW_UPDATE_SLEEP_STATE))
                {
                	START_LCD_TRANSFER;
                } 	
            }
            else
            {
            	START_LCD_TRANSFER;
            } 	                
            #else 
               START_LCD_TRANSFER;
            #endif//__SYNC_LCM_SW_SUPPORT__
         }
      }
      }
   #endif
   }
   if (interrupt_status & LCD_INT_ENABLE_CMD_COMPLETE_BIT)
   {
      lcd_cmd_latch_complete=KAL_TRUE;
   }
   drv_active_hisr(DRV_LCD_HISR_ID);
#endif//DRV_IDP_SUPPORT
#endif//(!defined(MT6205B)&&!defined(MT6208)) 
}  /* lcd_LISR() */



/**
 * LCD interface HISR entry
 *
 * @param None.
 *
 * @return None.
 */
#ifdef MT6225_IDP_DEBUG
kal_uint32 dbg_time3=0;
#endif
void lcd_HISR(void)
{
#if (!defined(MT6205B)&&!defined(MT6208))
   kal_uint32 save_irq_mask;   
   kal_uint8 i;
   volatile kal_uint16 j;   

   #if !defined(DRV_IDP_SUPPORT)

   #ifdef MT6225_IDP_DEBUG
   dbg_time3=drv_get_current_time();
   kal_prompt_trace(MOD_BMT,"lcd int= %d", dbg_time3);
   #endif
   kal_set_eg_events(lcd_event_id,LCD_TRANSFER_COMPLETE_EVENT,KAL_OR);
   save_irq_mask=SaveAndSetIRQMask();
   lcd_transfer_complete=KAL_FALSE;
   RestoreIRQMask(save_irq_mask);
   if (bWaitForLCDUpdate==KAL_TRUE)
   {  /* for software udpate only */
      bWaitForLCDUpdate=KAL_FALSE;
      if (main_lcd_operation_state==LCD_SW_UPDATE_STATE)
         main_lcd_operation_state=LCD_STANDBY_STATE;
   #ifdef DUAL_LCD
      if (sub_lcd_operation_state==LCD_SW_UPDATE_STATE)
         sub_lcd_operation_state=LCD_STANDBY_STATE;
   #endif
      config_lcd_layer_window_queue();
      if (lcd_prev_run_block_cb!=NULL)
         lcd_prev_run_block_cb();
   }
   IRQUnmask(IRQ_LCD_CODE);
   #elif defined(DRV_IDP_SUPPORT)
   if (current_update_lcd==MAIN_LCD)
   {
      if (lcd_transfer_complete==KAL_TRUE)
      {
         if ((main_lcd_operation_state==LCD_SW_UPDATE_STATE)||
             (main_lcd_operation_state==LCD_WAIT_LAST_UPDATE_STATE)||
             (main_lcd_operation_state==LCD_MEM_UPDATE_STATE))
         {
            kal_set_eg_events(lcd_event_id,LCD_TRANSFER_COMPLETE_EVENT,KAL_OR);
            #ifdef __VIDEO_EDITOR__
            /*video editor*/
            if(is_video_editor_running()==KAL_TRUE)
            {
               video_editor_data_path2();
               main_lcd_operation_state=temp_main_lcd_operation_state;
            }
            #endif
         }
         save_irq_mask=SaveAndSetIRQMask();
         lcd_transfer_complete=KAL_FALSE;
         RestoreIRQMask(save_irq_mask);
         if (bWaitForLCDUpdate==KAL_TRUE)
         {  /* for software udpate only */
            bWaitForLCDUpdate=KAL_FALSE;
            if (main_lcd_operation_state==LCD_SW_UPDATE_STATE)
               main_lcd_operation_state=LCD_STANDBY_STATE;
            config_lcd_layer_window_queue();
            if (lcd_prev_run_block_cb!=NULL)
               lcd_prev_run_block_cb();
         }
      }

      if (lcd_cmd_latch_complete==KAL_TRUE)/*set TRUE in LCD_LISR*/
      {
         if (lcd_hw_trigger_flag==KAL_TRUE)
         {
            #ifdef TV_OUT_SUPPORT
            if ((tv_output_owner == TV_OUT_OWNER_LCD) && (tv_output_buffer_count<2))
            {
               IRQUnmask(IRQ_LCD_CODE);
               return;
            }
            #endif
            lcd_hw_trigger_flag=KAL_FALSE;
            if ((main_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)||
                (main_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||/*back to video size*/
                (main_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE)||
                (main_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE)||
                (main_lcd_operation_state==LCD_HW_SLEEP_CMD_QUEUE_STATE)||
                (main_lcd_operation_state==LCD_DC_SLEEP_CMD_QUEUE_STATE))
            {
               for (j=0;j<50;j++);
               #ifdef TV_OUT_SUPPORT
                  if (tv_output_owner == TV_OUT_OWNER_LCD)
                  {
                     if (tv_out_current_fb==0)
                        lcd_mem_out_address_shadow1=main_lcd_fb_update_para.tv_output_frame_buffer1_address;
                     else
                        lcd_mem_out_address_shadow1=main_lcd_fb_update_para.tv_output_frame_buffer2_address;
                  }
               #endif               
               DRV_WriteReg32(LCD_ROI_CTRL_REG,lcd_hw_trigger_roi_ctrl);
               DRV_WriteReg32(LCD_ROI_OFFSET_REG,lcd_hw_trigger_roi_offset);
               DRV_WriteReg32(LCD_ROI_SIZE_REG,lcd_hw_trigger_roi_size);
               #ifdef TV_OUT_SUPPORT
                  DRV_WriteReg32(LCD_ROI_WMEM_ADDR_REG,lcd_mem_out_address_shadow1);
               #endif
               for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++)
                  *((volatile unsigned int *) (LCD_CMD_PARAMETER_ADDR+(i<<2)))=lcd_hw_trigger_para[i];               
            #ifdef __SYNC_LCM_SW_SUPPORT__
               if ((sync_lcm_enable_mode==KAL_TRUE)&&
                   ((main_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)||
                    (main_lcd_operation_state==LCD_HW_SLEEP_CMD_QUEUE_STATE)))
               {
                  kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
                  save_irq_mask=SaveAndSetIRQMask();
                  lcd_cmd_latch_complete=KAL_FALSE;
                  RestoreIRQMask(save_irq_mask);
               }
               else
               {
                  START_LCD_TRANSFER;
                  for (j=0;j<30;j++);
               }
            #else
               START_LCD_TRANSFER;
               for (j=0;j<30;j++);
            #endif
            }
            else
               kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);

            #ifdef TV_OUT_SUPPORT
               if (tv_output_owner!=TV_OUT_OWNER_LCD) {
                  DISABLE_LCD_TRANSFER_COMPLETE_INT;
               }
            #else
               DISABLE_LCD_TRANSFER_COMPLETE_INT;
            #endif
         }
         else /*lcd_hw_trigger_flag==KAL_FALSE*/
         {
            if ((main_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)||
                (main_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
                (main_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE)||
                (main_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE)||
                (main_lcd_operation_state==LCD_HW_SLEEP_CMD_QUEUE_STATE)||
                (main_lcd_operation_state==LCD_DC_SLEEP_CMD_QUEUE_STATE))
            {
               kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            }
            save_irq_mask=SaveAndSetIRQMask();
            lcd_cmd_latch_complete=KAL_FALSE;
            RestoreIRQMask(save_irq_mask);
         }
      }
   }
   #ifdef TV_OUT_SUPPORT
   if (tv_output_buffer_rotate==1)
   {
   		#if defined(DRV_TVOUT_6228_SERIES)
      g2d_tv_output_src_buff.base_address=tv_output_buffer_base_address1;
      g2d_bitblt1(G2D_OWNER_LCD, &g2d_tv_output_bitblt);
      #elif defined(DRV_TVOUT_6238_SERIES)
         //KKKKK,OK
      	//not necessary in 6238 because we use IRT3      	      	
      #endif
      tv_output_buffer_rotate=0;
   }
   else if (tv_output_buffer_rotate==2)
   {
   		#if defined(DRV_TVOUT_6228_SERIES)
      g2d_tv_output_src_buff.base_address=tv_output_buffer_base_address2;
      g2d_bitblt1(G2D_OWNER_LCD,&g2d_tv_output_bitblt);
      #elif defined(DRV_TVOUT_6238_SERIES)
      	//KKKKK,OK
      	//not necessary in 6238 because we use IRT3      	      	
      #endif 	
      tv_output_buffer_rotate=0;
   }
   #endif
   #ifdef DUAL_LCD/*almost the same as the main LCD part, except TVout.*/
   else if (current_update_lcd==SUB_LCD)
   {
      if (lcd_transfer_complete==KAL_TRUE)
      {
         if ((sub_lcd_operation_state==LCD_SW_UPDATE_STATE)||
             (sub_lcd_operation_state==LCD_WAIT_LAST_UPDATE_STATE))
            kal_set_eg_events(lcd_event_id,LCD_TRANSFER_COMPLETE_EVENT,KAL_OR);
         save_irq_mask=SaveAndSetIRQMask();
         lcd_transfer_complete=KAL_FALSE;
         RestoreIRQMask(save_irq_mask);

         if (bWaitForLCDUpdate==KAL_TRUE)
         {  /* for software udpate only */
            bWaitForLCDUpdate=KAL_FALSE;
            if (sub_lcd_operation_state==LCD_SW_UPDATE_STATE)
               sub_lcd_operation_state=LCD_STANDBY_STATE;
            config_lcd_layer_window_queue();
            if (lcd_prev_run_block_cb!=NULL)
               lcd_prev_run_block_cb();
         }
      }

      if (lcd_cmd_latch_complete==KAL_TRUE)
      {
         if (lcd_hw_trigger_flag==KAL_TRUE)
         {
            lcd_hw_trigger_flag=KAL_FALSE;
            if ((sub_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)||
                (sub_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
                (sub_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE)||
                (sub_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE)||
                (sub_lcd_operation_state==LCD_HW_SLEEP_CMD_QUEUE_STATE)||
                (sub_lcd_operation_state==LCD_DC_SLEEP_CMD_QUEUE_STATE))
            {
               for (j=0;j<100;j++);
               DRV_WriteReg32(LCD_ROI_CTRL_REG,lcd_hw_trigger_roi_ctrl);
               DRV_WriteReg32(LCD_ROI_OFFSET_REG,lcd_hw_trigger_roi_offset);
               DRV_WriteReg32(LCD_ROI_SIZE_REG,lcd_hw_trigger_roi_size);
               for (i=0;i<LCD_CMD_QUEUE_LENGTH;i++)
                  DRV_WriteReg32(LCD_CMD_PARAMETER_ADDR+(i<<2),lcd_hw_trigger_para[i]);
            #ifdef __SYNC_LCM_SW_SUPPORT__
               if ((sync_lcm_enable_mode==KAL_TRUE)&&
                   ((sub_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)||
                    (sub_lcd_operation_state==LCD_HW_SLEEP_CMD_QUEUE_STATE)))
               {
                  kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
                  save_irq_mask=SaveAndSetIRQMask();
                  lcd_cmd_latch_complete=KAL_FALSE;
                  RestoreIRQMask(save_irq_mask);
               }
               else
               {
                  START_LCD_TRANSFER;
                  for (j=0;j<30;j++);
               }
            #else
               START_LCD_TRANSFER;
               for (j=0;j<30;j++);
            #endif
            }
            else
               kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            #ifdef TV_OUT_SUPPORT
               if (tv_output_owner!=TV_OUT_OWNER_LCD) {
                  DISABLE_LCD_TRANSFER_COMPLETE_INT;
               }
            #else
               DISABLE_LCD_TRANSFER_COMPLETE_INT;
            #endif
         }
         else
         {
            if ((sub_lcd_operation_state==LCD_HW_CMD_QUEUE_STATE)||
                (sub_lcd_operation_state==LCD_DC_CMD_QUEUE_STATE)||
                (sub_lcd_operation_state==LCD_HW_UPDATE_SLEEP_STATE)||
                (sub_lcd_operation_state==LCD_DC_UPDATE_SLEEP_STATE)||
                (sub_lcd_operation_state==LCD_HW_SLEEP_CMD_QUEUE_STATE)||
                (sub_lcd_operation_state==LCD_DC_SLEEP_CMD_QUEUE_STATE))
               kal_set_eg_events(lcd_event_id,LCD_CMD_COMPLETE_EVENT,KAL_OR);
            save_irq_mask=SaveAndSetIRQMask();
            lcd_cmd_latch_complete=KAL_FALSE;
            RestoreIRQMask(save_irq_mask);
         }
      }
   }
   #endif   /* DUAL_LCD */
   IRQUnmask(IRQ_LCD_CODE);
   #endif   /* MT6219 */
#endif /* MT6219 */
}  /* lcd_HISR() */
