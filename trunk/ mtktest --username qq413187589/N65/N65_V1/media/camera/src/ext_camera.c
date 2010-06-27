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
 *    ext_camera.c
 *
 *  Project:
 * --------
 *   Maui_Software
 *
 * Description:
 *  ------------
 *   This file implements external camera module interface function (API)
 *
 * Author:
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
 * Refactoring.
 * Reduce EXT_CAMERA_VIDEO_RECORD_STATE.
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * lcd_power_up/down->lcd_power_ctrl
 *
 * removed!
 * removed!
 * Add ext_camera_para_struct member continue_capture for keeping continue shot state
 *
 * removed!
 * removed!
 * Modify clock control procedure when power off
 *
 * removed!
 * removed!
 * Check system init state before get/free NFI bus
 *
 * removed!
 * removed!
 *
 *    Rev 1.41   Mar 04 2005 16:34:40   mtk00548
 * Add LCM update request check during video clipping period.
 * Resolution for 10079: [Ext Camera][Bug fix] Modify the video clip function to server lcd update during video clip period
 *
 *    Rev 1.30   Nov 27 2004 17:56:38   mtk00747
 * Add new design for camera backend with lcd panel
 *
 *    Rev 1.29   Nov 22 2004 19:00:48   mtk00548
 * Update frame buffer to LCM while external camera preview ready check even no image ready.
 *
 *
 *    Rev 1.7   Apr 12 2004 15:46:12   mtk00548
 * 1. Change the include file from ait102n1.h to ait102n.h
 * 2. Set LCD_CMD_COMPLETE_EVENT event at the frame boundary for unblock MMI.
 *
 *    Rev 1.5   Apr 08 2004 13:39:52   mtk00548
 * Change the polling procedure of external camera reset status.
 * Resolution for 93: Camera- Preview cannot work after backlight is off
 *
 *    Rev 1.3   Apr 02 2004 17:46:40   mtk00548
 * Add module ID for frame buffer update while external camera preview frame ready.
 *
 *    Rev 1.0   Mar 02 2004 11:14:20   admin
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#include "kal_release.h"
#include "lcd_if.h"

#if (defined (CAMERA_MODULE))
#include "jpeg.h"
#include "cam_module.h"
#include "med_api.h"
#include "ext_camera.h"

#include "l1sm_public.h"
#include "drv_comm.h"



typedef enum
{
   EXT_CAM_POWER_OFF_STATE=0,
   EXT_CAM_INITIAL_STATE,
   EXT_CAM_STANDBY_STATE,
   EXT_CAM_PREVIEW_STATE,
   EXT_CAM_CAPTURE_STATE
} ENUM_ExternalCameraState;



struct {
   ENUM_ExternalCameraState state;
   kal_uint8 lcd;
} ext_cam;



lcd_frame_update_struct ext_camera_preview_lcd_data;
extern lcd_frame_update_struct sub_lcd_fb_update_para;

#ifdef CAMERA_MODULE_WITH_LCD
lcd_frame_update_to_mem_struct ext_cam_lcd_to_mem_param;
ext_camera_osd_para_struct ext_cam_osd_param;
#endif

kal_uint8 camera_sleep_mode_handler = 0xFF;

kal_uint8 burst_snapshot_number;
ext_camera_para_struct ext_camera_config_data;
ext_cam_module_func *ext_cam_func;

kal_bool engineering_mode_setting = KAL_FALSE;
kal_uint8 ext_cam_reg_setting[0x100];
kal_uint16 ext_cam_reg_value[0x100];
kal_bool video_clip_mode = KAL_FALSE;

#if (!defined(ISP_SUPPORT))
kal_uint8 cam_command_map[CAM_NO_OF_PARAM];
kal_uint8 cam_ev_param_map[CAM_NO_OF_EV];
kal_uint8 cam_zoom_param_map[CAM_NO_OF_ZOOM];
kal_uint8 cam_effect_param_map[CAM_NO_OF_EFFECT_ENC];
kal_uint8 cam_jpg_qty_param_map[CAM_NO_OF_JPG_QTY];
kal_uint8 cam_wb_param_map[CAM_NO_OF_WB];
kal_uint8 cam_banding_param_map[CAM_NO_OF_BANDING];
#endif



/**
 * Initialize external camera module status.
 */
void ext_cam_init(void)
{
   kal_uint16 i;

   ext_cam.state = EXT_CAM_POWER_OFF_STATE;

   if (camera_sleep_mode_handler==0xFF) {
      camera_sleep_mode_handler = L1SM_GetHandle();
   }

   cam_module_func_config();

   if (KAL_FALSE == kal_query_systemInit()) {
      get_NFI_bus();
      ext_cam_func->cam_module_cmd_mapping();
      free_NFI_bus();
   } else {
      /// system in initialization stage
      ext_cam_func->cam_module_cmd_mapping();
   }

   video_clip_mode = KAL_FALSE;

   for (i=0;i<0x100;i++) {
      ext_cam_reg_setting[i]=0;
   }
}



kal_bool ext_cam_is_running(void)
{
   return (ext_cam.state!=EXT_CAM_POWER_OFF_STATE);
}



/**
 * Turn on the power of external camera module.
 */
void ext_cam_power_on(void)
{
   ASSERT( (EXT_CAM_POWER_OFF_STATE == ext_cam.state) ||
           (EXT_CAM_INITIAL_STATE == ext_cam.state));

   if (EXT_CAM_POWER_OFF_STATE == ext_cam.state) {
      #if (defined(CAMERA_MODULE_WITH_LCD))
         #ifdef DUAL_LCD
            ASSERT( (LCD_STANDBY_STATE == main_lcd_operation_state)) &&
                    (LCD_STANDBY_STATE == sub_lcd_operation_state) );
            sub_lcd_operation_state = LCD_CAMERA_ACTIVE_STATE;
         #else
            ASSERT(LCD_STANDBY_STATE == main_lcd_operation_state);
         #endif
         main_lcd_operation_state = LCD_CAMERA_ACTIVE_STATE;
      #endif
      lcd_power_ctrl(KAL_TRUE);
      get_NFI_bus();
      ext_cam_func->cam_module_power_on();
      free_NFI_bus();
      ext_cam.state = EXT_CAM_INITIAL_STATE;
      lcd_power_ctrl(KAL_FALSE);
   }
}



/**
 * Check the reset status of external camera module.
 * The upper layer task should call this function periodically to check
 * the reset status of external camera module.
 *
 * @return KAL_TRUE : external camera module initialize complete.
 * KAL_FALSE: external camera module is initializing.
 */
kal_bool ext_cam_is_ready(void)
{
   kal_uint32 i;
   kal_uint32 data;

   lcd_power_ctrl(KAL_TRUE);
   get_NFI_bus();
   if (ext_cam_func->cam_module_reset_status()) {
      ext_cam.state = EXT_CAM_STANDBY_STATE;
      if (KAL_TRUE == engineering_mode_setting) {
         for (i=0;i<0x100;i++) {
            if (ext_cam_reg_setting[((kal_uint8)i)]==1) {
               do {
                  ext_cam_func->cam_module_write_para(i,ext_cam_reg_value[((kal_uint8) i)]);
                  data=ext_cam_func->cam_module_read_para(i);
               } while (data!=ext_cam_reg_value[((kal_uint8)i)]);
            }
         }
      }
      free_NFI_bus();
      lcd_power_ctrl(KAL_FALSE);
      return KAL_TRUE;
   }
   free_NFI_bus();
   lcd_power_ctrl(KAL_FALSE);
   return KAL_FALSE;
}



#if (defined(CAMERA_MODULE_WITH_LCD))
void wait_lcd_update(void)
{
#ifdef DUAL_LCD
   while ((main_lcd_operation_state == LCD_CAMERA_ACTIVE_UPDATE_STATE)||
          (sub_lcd_operation_state == LCD_CAMERA_ACTIVE_UPDATE_STATE))
#else
   while (main_lcd_operation_state == LCD_CAMERA_ACTIVE_UPDATE_STATE)
#endif
   {
      kal_sleep_task(1);
   }
}
#endif



/**
 * check whether a preview image from external camera module is ready to send to baseband.
 *
 * @return KAL_TRUE : ready
 * KAL_FALSE: not yet
 */
kal_bool ext_cam_is_preview_ready(void)
{
   ASSERT(EXT_CAM_PREVIEW_STATE == ext_cam.state);

   get_NFI_bus();

#ifndef CAMERA_MODULE_WITH_LCD
   if (ext_cam_func->cam_module_preview_ready_check()) {
      #ifndef DUAL_LCD
         if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
      #else
         if ((LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)||
            (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state))
      #endif
      {
         if (MAIN_LCD == ext_cam.lcd) {
            main_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
         } else if (SUB_LCD == ext_cam.lcd) {
            sub_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &sub_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
         }
      }
      #ifndef DUAL_LCD
      else if (LCD_CAMERA_UPDATE_STATE == main_lcd_operation_state)
      #else
      else if ((LCD_CAMERA_UPDATE_STATE == main_lcd_operation_state)||
               (LCD_CAMERA_UPDATE_STATE == sub_lcd_operation_state))
      #endif
      {
         lcd_fb_update((lcd_frame_update_struct *) &ext_camera_preview_lcd_data);
      } else {
         ASSERT(0);
      }
      free_NFI_bus();
      return KAL_TRUE;
   } else {
      #ifndef DUAL_LCD
      if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
      #else
      if ((LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)||
          (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state))
      #endif
      {
         if (MAIN_LCD == ext_cam.lcd) {
            main_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
         } else if (ext_cam.lcd==SUB_LCD) {
            sub_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &sub_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
         }
      }
   }
   free_NFI_bus();
   return KAL_FALSE;

#else

   if (ext_cam_func->cam_module_preview_ready_check()) {
      #ifndef DUAL_LCD
      if (main_lcd_operation_state==LCD_CAMERA_CMD_QUEUE_STATE)
      #else
      if ((main_lcd_operation_state==LCD_CAMERA_CMD_QUEUE_STATE)||
          (sub_lcd_operation_state==LCD_CAMERA_CMD_QUEUE_STATE))
      #endif
      {
         wait_lcd_update();

         if (KAL_FALSE == ext_camera_config_data.video_rec_mode) {
            /// camera preview mode
            ext_cam_osd_param.lcd_id=ext_camera_preview_lcd_data.lcd_id;
            ext_cam_osd_param.lcm_start_x=ext_camera_preview_lcd_data.lcm_start_x;
            ext_cam_osd_param.lcm_start_y=ext_camera_preview_lcd_data.lcm_start_y;
            ext_cam_osd_param.lcm_end_x=ext_camera_preview_lcd_data.lcm_end_x;
            ext_cam_osd_param.lcm_end_y=ext_camera_preview_lcd_data.lcm_end_y;
            ext_cam_osd_param.dest_buffer_address=(kal_uint32)ext_camera_config_data.image_buffer_ptr;
            ext_cam_osd_param.dest_buffer_size=ext_camera_config_data.image_buffer_size;
            ext_cam_osd_param.force_update = 0;

            if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state) {
               lcd_fb_update_to_memory(&ext_cam_lcd_to_mem_param);
               ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
               kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
            }
            #ifdef DUAL_LCD
            else if (sub_lcd_operation_state==LCD_CAMERA_CMD_QUEUE_STATE) {
               lcd_fb_update_to_memory(&ext_cam_lcd_to_mem_param);
               ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
               kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
            }
            #endif
         } else {
            /// video record mode
            ext_cam_osd_param.lcm_start_x=main_lcd_fb_update_para.lcm_start_x;
            ext_cam_osd_param.lcm_start_y=main_lcd_fb_update_para.lcm_start_y;
            ext_cam_osd_param.lcm_end_x=main_lcd_fb_update_para.lcm_end_x;
            ext_cam_osd_param.lcm_end_y=main_lcd_fb_update_para.lcm_end_y;
            ext_cam_osd_param.dest_buffer_address=(kal_uint32)ext_camera_config_data.image_buffer_ptr;
            ext_cam_osd_param.dest_buffer_size=ext_camera_config_data.image_buffer_size;
            ext_cam_osd_param.force_update=1;

            ext_cam_lcd_to_mem_param.roi_width=main_lcd_fb_update_para.lcm_end_x-main_lcd_fb_update_para.lcm_start_x+1;
            ext_cam_lcd_to_mem_param.roi_height=main_lcd_fb_update_para.lcm_end_y-main_lcd_fb_update_para.lcm_start_y+1;
            ext_cam_lcd_to_mem_param.roi_offset_x=main_lcd_fb_update_para.roi_offset_x;
            ext_cam_lcd_to_mem_param.roi_offset_y=main_lcd_fb_update_para.roi_offset_y;

            if (main_lcd_operation_state==LCD_CAMERA_CMD_QUEUE_STATE) {
               lcd_fb_update_to_memory(&ext_cam_lcd_to_mem_param);
               ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
               kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);

               ext_cam_osd_param.lcd_id=ext_camera_preview_lcd_data.lcd_id;
               ext_cam_osd_param.lcm_start_x=ext_camera_preview_lcd_data.lcm_start_x;
               ext_cam_osd_param.lcm_start_y=ext_camera_preview_lcd_data.lcm_start_y;
               ext_cam_osd_param.lcm_end_x=ext_camera_preview_lcd_data.lcm_end_x;
               ext_cam_osd_param.lcm_end_y=ext_camera_preview_lcd_data.lcm_end_y;
               ext_cam_osd_param.dest_buffer_address=(kal_uint32)ext_camera_config_data.image_buffer_ptr;
               ext_cam_osd_param.dest_buffer_size=ext_camera_config_data.image_buffer_size;
               ext_cam_osd_param.force_update=0;

               ext_cam_lcd_to_mem_param.roi_width=ext_camera_preview_lcd_data.lcm_end_x-ext_camera_preview_lcd_data.lcm_start_x+1;
               ext_cam_lcd_to_mem_param.roi_height=ext_camera_preview_lcd_data.lcm_end_y-ext_camera_preview_lcd_data.lcm_start_y+1;
               ext_cam_lcd_to_mem_param.roi_offset_x=ext_camera_preview_lcd_data.roi_offset_x;
               ext_cam_lcd_to_mem_param.roi_offset_y=ext_camera_preview_lcd_data.roi_offset_y;

               lcd_fb_update_to_memory(&ext_cam_lcd_to_mem_param);
               ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
            }
         }
      }
      free_NFI_bus();
      return KAL_TRUE;
   }
   free_NFI_bus();
   return KAL_FALSE;
#endif   /* CAMERA_MODULE_WITH_LCD */
}



kal_uint32 ext_cam_get_capture_size(void)
{
   kal_uint32 jpeg_file_size;

   get_NFI_bus();

#ifndef CAMERA_MODULE_WITH_LCD
   ASSERT(EXT_CAM_CAPTURE_STATE == ext_cam.state);

   jpeg_file_size = ext_cam_func->cam_module_capture_ready_check();
   if (jpeg_file_size!=NULL_JPEG_FILE) {
      if ((ext_camera_config_data.snapshot_number!=1) &&
          (ext_camera_config_data.captured_picture!=burst_snapshot_number)) {
         ext_camera_config_data.snapshot_number=burst_snapshot_number-ext_camera_config_data.captured_picture;
         ext_camera_config_data.jpeg_buffer_ptr=(kal_uint8 *) (((kal_uint32)ext_camera_config_data.jpeg_buffer_ptr)+jpeg_file_size);
         ext_camera_config_data.image_buffer_size=ext_camera_config_data.image_buffer_size-jpeg_file_size;
         ext_camera_config_data.total_file_size+=jpeg_file_size;
         ext_cam_func->cam_module_capture(&ext_camera_config_data);
         free_NFI_bus();
         return (NULL_JPEG_FILE);
      } else {
         L1SM_SleepEnable(camera_sleep_mode_handler);
         ext_cam.state = EXT_CAM_STANDBY_STATE;
         ext_camera_config_data.total_file_size+=jpeg_file_size;
         if (MAIN_LCD == ext_cam.lcd) {
            main_lcd_operation_state = LCD_STANDBY_STATE;
         } else if (SUB_LCD == ext_cam.lcd) {
            sub_lcd_operation_state = LCD_STANDBY_STATE;
         }
         free_NFI_bus();
         return (ext_camera_config_data.total_file_size);
      }
   } else {
      free_NFI_bus();
      return (NULL_JPEG_FILE);
   }
#else
   ASSERT(EXT_CAM_CAPTURE_STATE == ext_cam.state);

   jpeg_file_size=ext_cam_func->cam_module_capture_ready_check();
   if (jpeg_file_size!=NULL_JPEG_FILE) {
      L1SM_SleepEnable(camera_sleep_mode_handler);
      ext_cam.state = EXT_CAM_STANDBY_STATE;
      ext_camera_config_data.total_file_size+=jpeg_file_size;

      main_lcd_operation_state = LCD_CAMERA_ACTIVE_STATE;
      sub_lcd_operation_state = LCD_CAMERA_ACTIVE_STATE;
      free_NFI_bus();
      return (ext_camera_config_data.total_file_size);
   } else {
      free_NFI_bus();
      return (NULL_JPEG_FILE);
   }
#endif   /* CAMERA_MODULE_WITH_LCD */
}



void ext_cam_power_off(void)
{
   lcd_power_ctrl(KAL_TRUE);
   if ((EXT_CAM_PREVIEW_STATE == ext_cam.state) ||
       (EXT_CAM_CAPTURE_STATE == ext_cam.state))
   {
      #ifndef DUAL_LCD
         if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
      #else
         if ((LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state) ||
             (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state))
      #endif
      {
         #if (defined(CAMERA_MODULE_WITH_LCD))
            if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
         #else
            if (MAIN_LCD == ext_cam.lcd)
         #endif
         {
            main_lcd_fb_update_para.module_id = LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
         }
         #if (defined(CAMERA_MODULE_WITH_LCD))
            else if (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state)
         #else
            else if (SUB_LCD == ext_cam.lcd)
         #endif
         {
            sub_lcd_fb_update_para.module_id = LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &sub_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
         }
      }

      if (MAIN_LCD == ext_cam.lcd) {
         main_lcd_operation_state = LCD_STANDBY_STATE;
      } else if (SUB_LCD == ext_cam.lcd) {
         sub_lcd_operation_state = LCD_STANDBY_STATE;
      }
   }

   #if (defined(CAMERA_MODULE_WITH_LCD))
      wait_lcd_update();
   #endif

   get_NFI_bus();
   ext_cam_func->cam_module_power_off();
   free_NFI_bus();

   #if (defined(CAMERA_MODULE_WITH_LCD))
      main_lcd_operation_state = LCD_STANDBY_STATE;
      sub_lcd_operation_state = LCD_STANDBY_STATE;
   #endif
   lcd_power_ctrl(KAL_FALSE);

   L1SM_SleepEnable(camera_sleep_mode_handler);
   ext_cam.state = EXT_CAM_POWER_OFF_STATE;
}



void ext_cam_start_preview(ext_camera_para_struct *ext_cam_para, lcd_frame_update_struct *lcd_para)
{
   ASSERT(EXT_CAM_STANDBY_STATE == ext_cam.state);

   lcd_power_ctrl(KAL_TRUE);

   ext_cam.lcd = lcd_para->lcd_id;
   ext_camera_preview_lcd_data.module_id = LCD_UPDATE_MODULE_EXT_CAMERA;
   ext_camera_preview_lcd_data.lcd_id = ext_cam.lcd;
   ext_camera_preview_lcd_data.fb_update_mode = lcd_para->fb_update_mode;
   ext_camera_preview_lcd_data.lcm_start_x = lcd_para->lcm_start_x;
   ext_camera_preview_lcd_data.lcm_start_y = lcd_para->lcm_start_y;
   ext_camera_preview_lcd_data.lcm_end_x = lcd_para->lcm_end_x;
   ext_camera_preview_lcd_data.lcm_end_y = lcd_para->lcm_end_y;
   ext_camera_preview_lcd_data.roi_offset_x = lcd_para->roi_offset_x;
   ext_camera_preview_lcd_data.roi_offset_y = lcd_para->roi_offset_y;
   ext_camera_preview_lcd_data.update_layer = lcd_para->update_layer;

   if (MAIN_LCD == ext_cam.lcd) {
      main_lcd_operation_state = LCD_CAMERA_UPDATE_STATE;
   } else if (SUB_LCD == ext_cam.lcd) {
      sub_lcd_operation_state = LCD_CAMERA_UPDATE_STATE;
   } else {
      ASSERT(0);
   }

   L1SM_SleepDisable(camera_sleep_mode_handler);

   ext_camera_config_data.image_width = ext_cam_para->image_width;
   ext_camera_config_data.image_height = ext_cam_para->image_height;
   ext_camera_config_data.preview_width = ext_cam_para->preview_width;
   ext_camera_config_data.preview_height = ext_cam_para->preview_height;
   ext_camera_config_data.white_balance_mode1 = ext_cam_para->white_balance_mode1;
   ext_camera_config_data.ev_value = ext_cam_para->ev_value;
   ext_camera_config_data.gamma_table = ext_cam_para->gamma_table;
   ext_camera_config_data.image_effect1 = ext_cam_para->image_effect1;
   ext_camera_config_data.frame_rate = ext_cam_para->frame_rate;
   ext_camera_config_data.image_buffer_ptr = ext_cam_para->image_buffer_ptr;
   ext_camera_config_data.buffer_width = ext_cam_para->buffer_width;
   ext_camera_config_data.buffer_height = ext_cam_para->buffer_height;
   ext_camera_config_data.preview_offset_x = ext_cam_para->preview_offset_x;
   ext_camera_config_data.preview_offset_y = ext_cam_para->preview_offset_y;
   ext_camera_config_data.preview_rotate = ext_cam_para->preview_rotate;
   ext_camera_config_data.snapshot_number = ext_cam_para->snapshot_number;
   ext_camera_config_data.banding_freq = ext_cam_para->banding_freq;
   ext_camera_config_data.image_buffer_ptr = ext_cam_para->image_buffer_ptr;
   ext_camera_config_data.zoom_factor = ext_cam_para->zoom_factor;
   ext_camera_config_data.total_file_size = 0;
   ext_camera_config_data.captured_picture = 0;
   ext_camera_config_data.continue_capture = ext_cam_para->continue_capture;

#ifdef CAMERA_MODULE_WITH_LCD

   ext_camera_config_data.lcd_id = lcd_para->lcd_id;
   ext_camera_config_data.src_key_color = ext_cam_para->src_key_color;
   ext_camera_config_data.preview_offset_x = ext_cam_para->preview_offset_x+lcd_para->lcm_start_x;
   ext_camera_config_data.preview_offset_y = ext_cam_para->preview_offset_y+lcd_para->lcm_start_y;
   ext_camera_config_data.video_rec_mode = ext_cam_para->video_rec_mode;

   ext_cam_lcd_to_mem_param.fb_update_mode = LCD_SW_TRIGGER_MODE;
   ext_cam_lcd_to_mem_param.block_mode = LCD_WM_CONT_MODE;
   ext_cam_lcd_to_mem_param.dest_block_width = lcd_para->lcm_end_x-lcd_para->lcm_start_x+1;
   ext_cam_lcd_to_mem_param.dest_buffer_address = (kal_uint32)ext_cam_para->image_buffer_ptr;
   ext_cam_lcd_to_mem_param.dest_buffer_size = ext_cam_para->image_buffer_size;
   ext_cam_lcd_to_mem_param.roi_offset_x = lcd_para->roi_offset_x;
   ext_cam_lcd_to_mem_param.roi_offset_y = lcd_para->roi_offset_y;
   ext_cam_lcd_to_mem_param.roi_width = lcd_para->lcm_end_x-lcd_para->lcm_start_x+1;
   ext_cam_lcd_to_mem_param.roi_height = lcd_para->lcm_end_y-lcd_para->lcm_start_y+1;
   ext_cam_lcd_to_mem_param.update_layer = lcd_para->update_layer;
   ext_cam_lcd_to_mem_param.hw_update_layer = 0;

   wait_lcd_update();

   ext_cam_osd_param.lcd_id=ext_camera_preview_lcd_data.lcd_id;
   ext_cam_osd_param.lcm_start_x=ext_camera_preview_lcd_data.lcm_start_x;
   ext_cam_osd_param.lcm_start_y=ext_camera_preview_lcd_data.lcm_start_y;
   ext_cam_osd_param.lcm_end_x=ext_camera_preview_lcd_data.lcm_end_x;
   ext_cam_osd_param.lcm_end_y=ext_camera_preview_lcd_data.lcm_end_y;
   ext_cam_osd_param.dest_buffer_address=(kal_uint32)ext_camera_config_data.image_buffer_ptr;
   ext_cam_osd_param.dest_buffer_size=ext_camera_config_data.image_buffer_size;
   ext_cam_osd_param.src_key_color=ext_camera_config_data.src_key_color;
   ext_cam_osd_param.force_update=0;
   lcd_fb_update_to_memory(&ext_cam_lcd_to_mem_param);

   get_NFI_bus();
   ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
   free_NFI_bus();
#endif

   ext_cam.state = EXT_CAM_PREVIEW_STATE;

   get_NFI_bus();
   ext_cam_func->cam_module_preview(&ext_camera_config_data);
   free_NFI_bus();
   lcd_power_ctrl(KAL_FALSE);
}



void ext_cam_stop_preview(void)
{
   ASSERT(EXT_CAM_PREVIEW_STATE == ext_cam.state);

   ext_cam.state = EXT_CAM_STANDBY_STATE;

   lcd_power_ctrl(KAL_TRUE);

   L1SM_SleepEnable(camera_sleep_mode_handler);

#if (defined(CAMERA_MODULE_WITH_LCD))
   wait_lcd_update();
   #ifndef DUAL_LCD
   if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
   #else
   if ((LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state) ||
       (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state))
   #endif
   {
      ext_cam_osd_param.lcd_id=ext_camera_preview_lcd_data.lcd_id;
      ext_cam_osd_param.lcm_start_x=ext_camera_preview_lcd_data.lcm_start_x;
      ext_cam_osd_param.lcm_start_y=ext_camera_preview_lcd_data.lcm_start_y;
      ext_cam_osd_param.lcm_end_x=ext_camera_preview_lcd_data.lcm_end_x;
      ext_cam_osd_param.lcm_end_y=ext_camera_preview_lcd_data.lcm_end_y;
      ext_cam_osd_param.dest_buffer_address=(kal_uint32)ext_camera_config_data.image_buffer_ptr;
      ext_cam_osd_param.dest_buffer_size=ext_camera_config_data.image_buffer_size;
      ext_cam_osd_param.force_update=0;

      if (MAIN_LCD == ext_cam.lcd) {
         lcd_fb_update_to_memory(&ext_cam_lcd_to_mem_param);
         get_NFI_bus();
         ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
         free_NFI_bus();
         kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
      }
      else if (SUB_LCD == ext_cam.lcd) {
         lcd_fb_update_to_memory(&ext_cam_lcd_to_mem_param);
         get_NFI_bus();
         ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
         free_NFI_bus();
         kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
      }
   }
   main_lcd_operation_state = LCD_CAMERA_ACTIVE_STATE;
   sub_lcd_operation_state = LCD_CAMERA_ACTIVE_STATE;

   if (ext_cam_func->exit_cam_module_preview!=NULL)
   {
      get_NFI_bus();
      ext_cam_func->exit_cam_module_preview();
      free_NFI_bus();
   }

#else // !CAMERA_MODULE_WITH_LCD

   if (ext_cam_func->exit_cam_module_preview!=NULL)
   {
      get_NFI_bus();
      ext_cam_func->exit_cam_module_preview();
      free_NFI_bus();
   }

   #ifndef DUAL_LCD
   if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
   #else
   if ((LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)||
       (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state))
   #endif
   {
      if (MAIN_LCD == ext_cam.lcd) {
         main_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_EXT_CAMERA;
         lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
         kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
      } else if (ext_cam.lcd==SUB_LCD) {
         sub_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_EXT_CAMERA;
         lcd_fb_update((lcd_frame_update_struct *) &sub_lcd_fb_update_para);
         kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
      }
   }

   if (MAIN_LCD == ext_cam.lcd) {
      main_lcd_operation_state = LCD_STANDBY_STATE;
   } else if (SUB_LCD == ext_cam.lcd) {
      sub_lcd_operation_state = LCD_STANDBY_STATE;
   }
#endif

   lcd_power_ctrl(KAL_FALSE);
}



void ext_cam_capture(ext_camera_para_struct *ext_cam_para)
{
   ASSERT (EXT_CAM_PREVIEW_STATE == ext_cam.state);

   lcd_power_ctrl(KAL_TRUE);

   burst_snapshot_number=ext_cam_para->snapshot_number;

   ext_camera_config_data.burst_capture_ptr=ext_cam_para->burst_capture_ptr;
   ext_camera_config_data.image_width=ext_cam_para->image_width;
   ext_camera_config_data.image_height=ext_cam_para->image_height;
   ext_camera_config_data.jpeg_compression_ratio=ext_cam_para->jpeg_compression_ratio;
   ext_camera_config_data.snapshot_number=ext_cam_para->snapshot_number;
   ext_camera_config_data.jpeg_buffer_ptr=ext_cam_para->jpeg_buffer_ptr;
   ext_camera_config_data.image_buffer_size=ext_cam_para->image_buffer_size;
   ext_camera_config_data.total_file_size=0;
   ext_camera_config_data.captured_picture=0;
   ext_camera_config_data.sticker_capture=0;
   ext_camera_config_data.continue_capture = ext_cam_para->continue_capture;

   get_NFI_bus();
   ext_cam_func->cam_module_capture(&ext_camera_config_data);
   free_NFI_bus();
   ext_cam.state = EXT_CAM_CAPTURE_STATE;
   lcd_power_ctrl(KAL_FALSE);
}



kal_uint8 ext_cam_get_frame_rate(void)
{
   volatile kal_uint8 result;

   get_NFI_bus();
   result=ext_cam_func->cam_module_frame_rate();
   free_NFI_bus();
   return (result);
}



kal_uint32 ext_cam_video_clip(ext_camera_para_struct *ext_cam_para)
{
   kal_uint32 jpeg_file_size;

#ifndef CAMERA_MODULE_WITH_LCD
   if (ext_cam_func->cam_module_jpeg_encode!=NULL) {
      video_clip_mode = KAL_TRUE;
      lcd_power_ctrl(KAL_TRUE);
      ASSERT(EXT_CAM_PREVIEW_STATE == ext_cam.state);

      get_NFI_bus();
      while (KAL_FALSE == ext_cam_func->cam_module_preview_ready_check())
      {
         free_NFI_bus();
         kal_sleep_task(1);
         if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
         {
            if (MAIN_LCD == ext_cam.lcd)
            {
               main_lcd_fb_update_para.module_id = LCD_UPDATE_MODULE_EXT_CAMERA;
               lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
               kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
            }
         }
         get_NFI_bus();
      };
      free_NFI_bus();

      ext_cam_para->image_width = ext_camera_config_data.preview_width;
      ext_cam_para->image_height = ext_camera_config_data.preview_height;
      ext_cam_para->buffer_width = ext_camera_config_data.buffer_width;

      get_NFI_bus();
      ext_cam_func->cam_module_jpeg_encode(ext_cam_para,KAL_TRUE);
      free_NFI_bus();

      #ifndef DUAL_LCD
      if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
      #else
      if ((LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)||
          (LCD_CAMERA_CMD_QUEUE_STATE == sub_lcd_operation_state))
      #endif
      {
         if (MAIN_LCD == ext_cam.lcd) {
            main_lcd_fb_update_para.module_id = LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
         } else if (SUB_LCD == ext_cam.lcd) {
            sub_lcd_fb_update_para.module_id = LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &sub_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT, KAL_OR);
         }
      }
      #ifndef DUAL_LCD
      else if (LCD_CAMERA_UPDATE_STATE == main_lcd_operation_state)
      #else
      else if ((LCD_CAMERA_UPDATE_STATE == main_lcd_operation_state) ||
            (LCD_CAMERA_UPDATE_STATE == sub_lcd_operation_state))
      #endif
      {
         lcd_fb_update((lcd_frame_update_struct *) &ext_camera_preview_lcd_data);
      }
      else {
         ASSERT(0);
      }

      do
      {
         kal_sleep_task(1);
         if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state)
         {
            if (MAIN_LCD == ext_cam.lcd)
            {
               main_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_EXT_CAMERA;
               lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
               kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT,KAL_OR);
            }
         }
         get_NFI_bus();
         jpeg_file_size=ext_cam_func->cam_module_capture_ready_check();
         free_NFI_bus();
      }  while (jpeg_file_size==NULL_JPEG_FILE);
      kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT,KAL_OR);
      lcd_power_ctrl(KAL_FALSE);
      video_clip_mode = KAL_FALSE;
      return jpeg_file_size;
   } else {
      return NULL_JPEG_FILE;
   }

#else
   ext_cam_capture((ext_camera_para_struct *)&ext_cam_para);
   do {
      if (LCD_CAMERA_CMD_QUEUE_STATE == main_lcd_operation_state) {
         if (MAIN_LCD == ext_cam.lcd) {
            main_lcd_fb_update_para.module_id=LCD_UPDATE_MODULE_EXT_CAMERA;
            lcd_fb_update((lcd_frame_update_struct *) &main_lcd_fb_update_para);
            kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT,KAL_OR);
         }
      }

      kal_sleep_task(1);
      get_NFI_bus();
      jpeg_file_size=ext_cam_func->cam_module_capture_ready_check();
      free_NFI_bus();
   }  while (NULL_JPEG_FILE == jpeg_file_size);
   return jpeg_file_size;
#endif
}



kal_uint32 ext_cam_sticker_capture(ext_camera_para_struct *ext_cam_para, lcd_frame_update_to_mem_struct *lcd_para)
{
   kal_uint32 jpeg_file_size;

#ifndef CAMERA_MODULE_WITH_LCD
   if (ext_cam_func->cam_module_jpeg_encode!=NULL) {
      lcd_power_ctrl(KAL_TRUE);
      /* for testing */
      lcd_para->fb_update_mode=LCD_SW_TRIGGER_MODE;
      lcd_para->block_mode=LCD_WM_CONT_MODE;
      lcd_para->hw_update_layer=0;

      get_NFI_bus();
      while (!ext_cam_func->cam_module_preview_ready_check()) {};
      free_NFI_bus();

      if (MAIN_LCD == ext_cam.lcd) {
         main_lcd_operation_state = LCD_STANDBY_STATE;
      } else if (SUB_LCD == ext_cam.lcd) {
         sub_lcd_operation_state = LCD_STANDBY_STATE;
      }
      lcd_fb_update_to_memory(lcd_para);
      lcd_power_ctrl(KAL_TRUE);

      ext_cam_para->image_buffer_ptr = (kal_uint16 *) lcd_para->dest_buffer_address;

      ext_cam_para->image_width = lcd_para->roi_width;
      ext_cam_para->image_height = lcd_para->roi_height;
      ext_cam_para->buffer_width = lcd_para->roi_width;

      get_NFI_bus();
      ext_cam_func->cam_module_jpeg_encode(ext_cam_para,KAL_FALSE);
      free_NFI_bus();

      do
      {
         get_NFI_bus();
         jpeg_file_size=ext_cam_func->cam_module_capture_ready_check();
         free_NFI_bus();
      }  while (jpeg_file_size==NULL_JPEG_FILE);

      lcd_power_ctrl(KAL_FALSE);
      L1SM_SleepEnable(camera_sleep_mode_handler);
      ext_cam.state = EXT_CAM_STANDBY_STATE;
      return jpeg_file_size;
   } else {
      return NULL_JPEG_FILE;
   }

#else

   /* update sticker */
   wait_lcd_update();
   ext_cam_osd_param.lcm_start_x=lcd_para->roi_offset_x;
   ext_cam_osd_param.lcm_start_y=lcd_para->roi_offset_y;
   ext_cam_osd_param.lcm_end_x=lcd_para->roi_offset_x+lcd_para->roi_width-1;
   ext_cam_osd_param.lcm_end_y=lcd_para->roi_offset_y+lcd_para->roi_height-1;
   ext_cam_osd_param.dest_buffer_address=lcd_para->dest_buffer_address;
   ext_cam_osd_param.dest_buffer_size=lcd_para->dest_buffer_size;
   ext_cam_osd_param.force_update=0;
   lcd_fb_update_to_memory(lcd_para);
   get_NFI_bus();
   ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
   free_NFI_bus();

   ext_camera_config_data.burst_capture_ptr=ext_cam_para->burst_capture_ptr;
   ext_camera_config_data.image_width=ext_cam_para->image_width;
   ext_camera_config_data.image_height=ext_cam_para->image_height;
   ext_camera_config_data.jpeg_compression_ratio=ext_cam_para->jpeg_compression_ratio;
   ext_camera_config_data.snapshot_number=ext_cam_para->snapshot_number;
   ext_camera_config_data.jpeg_buffer_ptr=ext_cam_para->jpeg_buffer_ptr;
   ext_camera_config_data.image_buffer_size=ext_cam_para->image_buffer_size;
   ext_camera_config_data.total_file_size=0;
   ext_camera_config_data.captured_picture=0;
   ext_camera_config_data.sticker_capture=1;
   ext_camera_config_data.continue_capture = ext_cam_para->continue_capture;

   get_NFI_bus();
   ext_cam_func->cam_module_capture(&ext_camera_config_data);
   free_NFI_bus();
   ext_cam.state = EXT_CAM_CAPTURE_STATE;
   do {
      get_NFI_bus();
      jpeg_file_size=ext_cam_func->cam_module_capture_ready_check();
      free_NFI_bus();
   }  while (NULL_JPEG_FILE == jpeg_file_size);
   main_lcd_operation_state=LCD_CAMERA_ACTIVE_STATE;
   sub_lcd_operation_state=LCD_CAMERA_ACTIVE_STATE;
   ext_cam.state = EXT_CAM_STANDBY_STATE;
   return jpeg_file_size;
#endif
}



void ext_cam_set_parameter(kal_uint8 cmd, kal_uint8 para)
{
   lcd_power_ctrl(KAL_TRUE);
   get_NFI_bus();
   ext_cam_func->cam_module_set_para(cmd, para);
   free_NFI_bus();
   lcd_power_ctrl(KAL_FALSE);
}



kal_bool write_ext_camera(kal_uint16 cmd, kal_uint16 para)
{
   engineering_mode_setting = KAL_TRUE;
   ext_cam_reg_setting[((kal_uint8)cmd)] = 1;
   ext_cam_reg_value[((kal_uint8)cmd)] = para;
   return KAL_TRUE;
}



kal_bool read_ext_camera(kal_uint16 cmd, kal_uint16 *para)
{
   kal_uint8 current_lcd_state;

   current_lcd_state = main_lcd_operation_state;
   lcd_power_ctrl(KAL_TRUE);
   /// temp state to prevent lcd interface power down
   main_lcd_operation_state = LCD_CAMERA_UPDATE_STATE;

   if (EXT_CAM_POWER_OFF_STATE == ext_cam.state) {
      get_NFI_bus();
      ext_cam_func->cam_module_power_on();
      free_NFI_bus();
      ext_cam.state = EXT_CAM_INITIAL_STATE;
   }

   while (ext_cam_is_ready()!=KAL_TRUE) {};

   if (ext_cam_func->cam_module_read_para!=NULL)
   {
      get_NFI_bus();
      *para=ext_cam_func->cam_module_read_para(cmd);
      free_NFI_bus();
      main_lcd_operation_state = current_lcd_state;
      lcd_power_ctrl(KAL_FALSE);
      ext_cam_power_off();
      return KAL_TRUE;
   }
   else
   {
      main_lcd_operation_state = current_lcd_state;
      lcd_power_ctrl(KAL_FALSE);
      ext_cam_power_off();
      return KAL_FALSE;
   }
}



void ext_cam_set_osd_buffer(kal_uint32 osd_addr, kal_uint32 osd_size)
{
#ifdef CAMERA_MODULE_WITH_LCD
   ext_cam_lcd_to_mem_param.dest_buffer_address=osd_addr;
   ext_cam_lcd_to_mem_param.dest_buffer_size=osd_size;
   ext_cam_osd_param.dest_buffer_address=osd_addr;
   ext_cam_osd_param.dest_buffer_size=osd_size;
#endif
}



void ext_cam_update_backend_lcd_buffer(lcd_frame_update_struct *ext_camera_osd_data)
{
#ifdef CAMERA_MODULE_WITH_LCD
   kal_uint32 save_irq_mask;

   if (MAIN_LCD == ext_camera_osd_data->lcd_id) {
      if ((main_lcd_operation_state!=LCD_CAMERA_ACTIVE_STATE) &&
          (main_lcd_operation_state!=LCD_CAMERA_UPDATE_STATE))
      {
         ASSERT(0);
      }
   } else if (SUB_LCD == ext_camera_osd_data->lcd_id) {
      if ((sub_lcd_operation_state!=LCD_CAMERA_ACTIVE_STATE) &&
          (sub_lcd_operation_state!=LCD_CAMERA_UPDATE_STATE))
      {
         ASSERT(0);
      }
   }

   save_irq_mask=SaveAndSetIRQMask();
   if (MAIN_LCD == ext_camera_osd_data->lcd_id) {
      main_lcd_operation_state = LCD_CAMERA_ACTIVE_UPDATE_STATE;
   } else if (SUB_LCD == ext_camera_osd_data->lcd_id) {
      sub_lcd_operation_state = LCD_CAMERA_ACTIVE_UPDATE_STATE;
   }
   RestoreIRQMask(save_irq_mask);

   ext_cam_lcd_to_mem_param.fb_update_mode=ext_camera_osd_data->fb_update_mode;
   ext_cam_lcd_to_mem_param.block_mode=LCD_WM_CONT_MODE;
   ext_cam_lcd_to_mem_param.roi_offset_x=ext_camera_osd_data->roi_offset_x;
   ext_cam_lcd_to_mem_param.roi_offset_y=ext_camera_osd_data->roi_offset_y;
   ext_cam_lcd_to_mem_param.roi_width=ext_camera_osd_data->lcm_end_x-ext_camera_osd_data->lcm_start_x+1;
   ext_cam_lcd_to_mem_param.roi_height=ext_camera_osd_data->lcm_end_y-ext_camera_osd_data->lcm_start_y+1;
   ext_cam_lcd_to_mem_param.update_layer=ext_camera_osd_data->update_layer;

   ext_cam_osd_param.lcd_id=ext_camera_osd_data->lcd_id;
   ext_cam_osd_param.lcm_start_x=ext_camera_osd_data->lcm_start_x;
   ext_cam_osd_param.lcm_start_y=ext_camera_osd_data->lcm_start_y;
   ext_cam_osd_param.lcm_end_x=ext_camera_osd_data->lcm_end_x;
   ext_cam_osd_param.lcm_end_y=ext_camera_osd_data->lcm_end_y;
   ext_cam_osd_param.force_update=1;

   ext_cam_osd_param.dest_buffer_address=ext_cam_lcd_to_mem_param.dest_buffer_address;

   lcd_fb_update_to_memory(&ext_cam_lcd_to_mem_param);
   get_NFI_bus();
   ext_cam_func->cam_module_write_lcdfb(&ext_cam_osd_param);
   free_NFI_bus();

   save_irq_mask=SaveAndSetIRQMask();

   main_lcd_operation_state=LCD_CAMERA_ACTIVE_STATE;
   sub_lcd_operation_state=LCD_CAMERA_ACTIVE_STATE;
   RestoreIRQMask(save_irq_mask);

   kal_set_eg_events(lcd_event_id, LCD_CMD_COMPLETE_EVENT,KAL_OR);
#endif
}



void ext_cam_start_video_encode(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para)
{
#ifdef CAMERA_MODULE_WITH_LCD
   get_NFI_bus();
   ext_cam_func->cam_module_start_video_encode(ext_camera_retrieve_video_para);
   free_NFI_bus();
#endif
}



void ext_cam_retrieve_video_data(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para)
{
#ifdef CAMERA_MODULE_WITH_LCD
   get_NFI_bus();
   ext_cam_func->cam_module_retrieve_video_data(ext_camera_retrieve_video_para);
   free_NFI_bus();
#endif
}



void ext_cam_pause_video_encode(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para)
{
#ifdef CAMERA_MODULE_WITH_LCD
   get_NFI_bus();
   ext_cam_func->cam_module_pause_video_encode(ext_camera_retrieve_video_para);
   free_NFI_bus();
#endif
}



void ext_cam_resume_video_encode(void)
{
#ifdef CAMERA_MODULE_WITH_LCD
   get_NFI_bus();
   ext_cam_func->cam_module_resume_video_encode();
   free_NFI_bus();
#endif
}



void ext_cam_stop_video_encode(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para)
{
#ifdef CAMERA_MODULE_WITH_LCD
   get_NFI_bus();
   ext_cam_func->cam_module_stop_video_encode(ext_camera_retrieve_video_para);
   free_NFI_bus();
#endif
}

#endif /* CAMERA_MODULE */
