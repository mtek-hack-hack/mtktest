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
 *   img_comm.c
 *
 * Project:
 * --------
 *    MT6219, MT6226, MT6227, MT6228, MT6229 and MT6230
 *
 * Description:
 * ------------
 *   MT6219, MT6226, MT6227 Resizer, Image processor and Image DMA configuration function
 *   MT6228, MT6229, MT6230 image data path configuration
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
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
 * Fix 6225 compile error.
 * Phase out 6218B.
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
 * lcd_power_up->lcd_power_ctrl
 *
 * removed!
 * removed!
 * get_lcd_status->lcd_is_busy
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
 * Fix video zoom in grab window setting error
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
 *    Rev 1.30   Aug 15 2005 11:57:48   mtk00548
 * Modify some configuration for MT6228 iamge data path and TV output
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.29   Jul 25 2005 21:58:18   mtk00548
 * Modify Video decode TV output function.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.28   Jul 25 2005 17:56:24   mtk00548
 * Modify TV output configuration for video display.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.27   Jul 18 2005 14:53:46   mtk00548
 * Modify some codes for MT6228 multimedia function  integrate.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.26   Jul 11 2005 11:16:30   mtk00548
 * Mapping camera capture call back function
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.25   Jul 04 2005 09:33:20   mtk00548
 * Modify image data path procedure for video decode and encode.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.24   Jun 24 2005 20:59:58   mtk00548
 * 1. Modify MT6228 image data path.
 * 2. Add MT6228 image effect data path configuration and close.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.23   Jun 20 2005 17:24:04   mtk00548
 * 1. Modify close_image_data_path() function.
 * 2. Modify image data path of video encode and decode.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.22   Jun 17 2005 08:58:28   mtk00548
 * Remove Linke error
 *
 *    Rev 1.21   Jun 13 2005 18:08:38   mtk00548
 * Modify MT6228 image data path driver codes.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.20   Jun 07 2005 19:25:32   mtk00548
 * Remove compiler error
 *
 *    Rev 1.19   Jun 07 2005 13:58:02   mtk00548
 * Remove compiler error
 *
 *    Rev 1.18   Jun 06 2005 13:50:04   mtk00548
 * Add MT6228 image data path driver codes.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.17   May 17 2005 00:58:28   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.16   Mar 30 2005 20:13:58   mtk00747
 * Enable CBA in config_image_processor()
 *
 *    Rev 1.15   Jan 18 2005 00:49:04   BM
 * append new line in W05.04
 *
 *    Rev 1.14   Nov 08 2004 17:22:18   mtk00548
 * Modify the working memory buffer size allocation of resizer for JPEG encode scenario.
 * Resolution for 8651: [Resizer][Bug fix] Modify the buffer size allocation of resizer working memory
 *
 *    Rev 1.13   Nov 05 2004 20:41:04   mtk00548
 * Modify line buffer size assignment for image resize function
 * Resolution for 8557: [Resizer][Add Feature] Add Image resize function
 *
 *    Rev 1.12   Nov 03 2004 09:12:02   mtk00548
 * Add codes for image resize function
 * Resolution for 8557: [Resizer][Add Feature] Add Image resize function
 *
 *    Rev 1.11   Oct 29 2004 18:54:12   mtk00548
 * Add JPEG decoder image clip function
 * Resolution for 8482: [JPEG] [Add Feature] Add JPEG decoder image clip function
 *
 *    Rev 1.10   Oct 04 2004 18:10:54   mtk00548
 * Modify the JPEG encoder line buffer allocation.
 * Resolution for 8064: [JPEG][Bug fix] Solve memory corrupt problem during JPEG encoder
 *
 *    Rev 1.9   Aug 27 2004 16:37:30   mtk00548
 * Remove compiler warnings.
 *
 *    Rev 1.8   Aug 06 2004 19:00:20   mtk00548
 * Add codes for snapshot JPEG encode feature.
 *
 *    Rev 1.7   Aug 02 2004 18:53:54   mtk00548
 * Clean the registers of image processor before use image processor for each scenario.
 *
 *    Rev 1.6   Jul 16 2004 20:28:02   mtk00548
 * Turn on hue and saturation function of image processor for camera preview, capture and mepg4 encode.
 * Resolution for 6430: [LCD][Add feature] Support MT6205B LCD interface on GPRS branch and Main trunk
 *
 *    Rev 1.5   May 31 2004 19:02:56   mtk00548
 * Add ISP_SUPPORT compiler option to excludes image sensor
 * correlated codes
 *
 *    Rev 1.4   May 07 2004 20:16:28   mtk00548
 * Modify the configuration of image DMA since we change LCD update of camera preview and mpeg4 encode from direct couple to hardware trigger with buffer.
 *
 *    Rev 1.3   Apr 30 2004 17:13:26   mtk00548
 * Calculate the buffer address offset of camera preview
 * Resolution for 5197: [ISP][Modify] Modify MT6219 ISP preview control flow
 *
 *    Rev 1.2   Apr 22 2004 18:07:58   mtk00548
 * Modify the jpeg_decoe_cb function to active a HISR instead of call callback function directly.
 *
 *    Rev 1.1   Apr 02 2004 18:33:06   mtk00548
 * 1. Add function description
 * 2. Chnage the callback function for jpeg decode
 *
 *    Rev 1.0   Apr 01 2004 18:18:18   admin
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "reg_base.h"
#include "drv_comm.h"

#if (defined(MT6217)|| defined(MT6223) || defined(MT6223P) || defined(DRV_IDP_6219_SERIES) || defined(DRV_IDP_6225_SERIES) || defined(DRV_IDP_6228_SERIES)||defined(DRV_IDP_6238_SERIES))
#include "jpeg.h"

#if (defined(EXIF_SUPPORT))
#include "exif.h"
#endif

#include "visual_comm.h"
#include "visualhisr.h"
#include "imgproc.h"
#include "resizer.h"
#include "isp_if.h"
#include "image_effect.h"
#include "lcd_if.h"
#include "2d_engine.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "med_status.h"
#include "bmd.h"
#include "video_dec_glb.h"
#include "video_enc_glb.h"
#include "video_glb.h"
#include "img_comm.h"
#include "imgdma.h"
#include "eint.h"
#include "lcd_sw_inc.h"
#if (defined(DRV_IDP_6228_SERIES)||defined(DRV_IDP_6238_SERIES))
#include "tv_out.h"
#include "upll_ctrl.h"
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) ) */
#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"
#endif
#if (defined(ISP_SUPPORT))
#include "ae_awb.h"
#endif

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
#include "SST_sla.h"
#endif

kal_bool img_dma_ibw2_int = KAL_FALSE;
kal_uint32 mpeg4_video_buffer[2];
kal_uint8 current_video_buffer_count = 0;
extern volatile kal_uint32 isp_int_status;


#if (!defined(MT6217) && !defined(MT6223)&& !defined(MT6223P) && !defined(MT6225)&& !defined(MT6235))
extern camera_capture_barcode_struct isp_capture_barcode_data;
resize_struct image_resize_data;
#endif

#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )
MMDI_SCENERIO_ID current_image_data_path_owner;
#endif

#ifdef __SYNC_LCM_SW_SUPPORT__
extern void preview_frame_ready_cb(void);
#endif

#if defined(DRV_IDP_6228_SERIES)||defined(DRV_IDP_6238_SERIES)
extern camera_preview_data_path_struct ipp_preview_data;
camera_preview_data_path_struct camera_preview_config_data;
camera_capture_jpeg_data_path_struct camera_capture_jpeg_config_data;
camera_capture_barcode_data_path_struct camera_capture_barcode_config_data;
camera_capture_mem_data_path_struct camera_capture_mem_config_data;
video_encode_data_path_struct video_encode_config_data;
volatile kal_uint8 current_captured_file_number;
#ifdef MTK_SLEEP_ENABLE
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
kal_uint8 image_data_path_sleep_mode_handler = 0xFF;
#endif

kal_uint8 video_decode_lcd_id;
kal_bool video_display;

g2d_buffer_struct g2d_tv_output_dest_buff;
g2d_buffer_struct g2d_tv_output_src_buff;
g2d_bitblt_struct g2d_tv_output_bitblt;
kal_uint8 current_g2d_tv_output_bitblt_buffer;

void (*ibw1_cb) (void);
void (*ibw2_cb) (void);
void (*irt1_cb) (void);
void (*vid_enc_w_cb) (void);
void (*vid_enc_w_cb1) (kal_uint32 yuv_address);
void (*vid_enc_r_cb) (kal_uint8 update_mode);
void mpeg4_vid_enc_r_cb(kal_uint8 update_mode);
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) ) */

/*****************************************************************************
 * FUNCTION
 *  jpeg_decode_cb
 * DESCRIPTION
 *  This function is intermediate callback function for MT6219 image dma
 *  while decode a jpeg file
 * CALLS
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//PLease Wei help remove it to jpeg
void jpeg_decode_cb(void)
{
  visual_active_hisr(VISUAL_JPEG_DEC_CB_HISR_ID);
}   /* jpeg_decode_cb() */

#if (defined(DRV_IDP_6228_SERIES)||defined(DRV_IDP_6238_SERIES))
extern video_encode_data_path_struct ipp_video_encode_data;
kal_uint8 video_record_frame = 0;
#endif
/*****************************************************************************
 * FUNCTION
 *  isp_ibw2_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void isp_ibw2_cb(void)
{
  kal_uint32 save_irq_mask;

  save_irq_mask = SaveAndSetIRQMask();
  if (img_dma_ibw2_int == KAL_TRUE)
  {
    RestoreIRQMask(save_irq_mask);
    return;
  }
  else
  {
    img_dma_ibw2_int = KAL_TRUE;
    RestoreIRQMask(save_irq_mask);
  }   

#if (defined(ISP_SUPPORT))
#if (defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D))
#ifdef __SYNC_LCM_SW_SUPPORT__
  if ((sync_lcm_enable_mode==KAL_TRUE)&&(isp_digital_zoom_flag==KAL_FALSE))
  {
    video_encode_update_flag=KAL_TRUE;
    ENABLE_IBW2_INT;
  }
#endif

#if defined(ANALOG_TV_SUPPORT)&&defined(__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__)
 if(mmi_get_analog_tv_current_state()==KAL_TRUE)
{
  if ((isp_in_idle_int==KAL_TRUE)&&(isp_operation_state==ISP_MPEG4_ENCODE_STATE)&&
		 (isp_enter_exit_process_flag==KAL_FALSE))
	{
	
		if ((isp_int_status & ISP_INT_IDLE)==0)
			return ;


		SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
		SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
		RESZ_Stop(SCENARIO_MPEG_ENCODE_ID);
		stop_image_dma(SCENARIO_MPEG_ENCODE_ID);
		IMGDMA_Close(SCENARIO_MPEG_ENCODE_ID);
	        DISABLE_IBW2_INT;
	        STOP_LCD_TRANSFER;
	        START_LCD_TRANSFER;
		video_enc_reset_buffer_counter();
		config_image_dma(SCENARIO_MPEG_ENCODE_ID,mpeg4_encode_data.image_target_width,mpeg4_encode_data.image_target_height);
		RESZ_SetSize(mpeg4_encode_data.image_source_width,mpeg4_encode_data.image_source_height,
						 mpeg4_encode_data.mpeg4_image_width,mpeg4_encode_data.mpeg4_image_height,
						 SCENARIO_MPEG_ENCODE_ID);
		RESZ_Start(SCENARIO_MPEG_ENCODE_ID);

		ENABLE_CMOS_SESNOR;
		DISABLE_CAMERA_IDLE_INT;
		ENABLE_VIEW_FINDER_MODE;
		if(ae_count==0)
		    ae_count++;
		hist_idx=0;
	}
         img_dma_ibw2_int=KAL_FALSE;
	 isp_in_idle_int=KAL_FALSE;
}
 else 	
#endif /*__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__*/

  if ((isp_digital_zoom_flag==KAL_TRUE)&&(isp_operation_state==ISP_MPEG4_ENCODE_STATE)&&
      (isp_enter_exit_process_flag==KAL_FALSE))
  {
#ifdef __SYNC_LCM_SW_SUPPORT__
    if ((isp_int_status & ISP_INT_IDLE)==0)
    {
      img_dma_ibw2_int=KAL_FALSE;
      return ;
    }   
#endif
		      
#if (defined(YUV_SENSOR_SUPPORT))
    SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
    SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
#else
		SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
		SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
#endif
    ae_config(isp_grab_width,isp_grab_height);

    ENABLE_VERTICAL_SUB_SAMPLE;
    ENABLE_HORIZONTAL_SUB_SAMPLE;
		SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));
		SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
    SET_HSUB_DST_SIZE(mpeg4_encode_data.image_source_width);
    SET_VSUB_DST_SIZE(mpeg4_encode_data.image_source_height);

    RESZ_Stop(SCENARIO_MPEG_ENCODE_ID);
    stop_image_dma(SCENARIO_MPEG_ENCODE_ID);
    IMGDMA_Close(SCENARIO_MPEG_ENCODE_ID);
#ifndef __SYNC_LCM_SW_SUPPORT__
    DISABLE_IBW2_INT;
#endif
    video_enc_reset_buffer_counter();
    config_image_dma(SCENARIO_MPEG_ENCODE_ID,mpeg4_encode_data.image_target_width,mpeg4_encode_data.image_target_height);
    RESZ_SetSize(mpeg4_encode_data.image_source_width,mpeg4_encode_data.image_source_height,
                 mpeg4_encode_data.mpeg4_image_width,mpeg4_encode_data.mpeg4_image_height,
                 SCENARIO_MPEG_ENCODE_ID);
    RESZ_Start(SCENARIO_MPEG_ENCODE_ID);
    isp_digital_zoom_flag=KAL_FALSE;
    ENABLE_CMOS_SESNOR;
    DISABLE_CAMERA_IDLE_INT;
    ENABLE_VIEW_FINDER_MODE;
    if(ae_count==0)
      ae_count++;
    hist_idx=0;
#ifdef __SYNC_LCM_SW_SUPPORT__
    video_encode_update_flag=KAL_FALSE;
#endif
  }
  img_dma_ibw2_int=KAL_FALSE;
#elif (defined(DRV_IDP_6228_SERIES))
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    if ((isp_digital_zoom_flag==KAL_TRUE)&&
        (isp_operation_state==ISP_MPEG4_ENCODE_STATE)&&
        (isp_enter_exit_process_flag==KAL_FALSE))
#endif//__3G_VIDEO_CALL__
    {
#ifdef __SYNC_LCM_SW_SUPPORT__
      if ((isp_int_status & ISP_INT_IDLE)==0)
      {
        img_dma_ibw2_int=KAL_FALSE;
        return ;
      }   
#endif

#if (defined(YUV_SENSOR_SUPPORT))
      SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
      SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
#else
			SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
			SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
#endif
      ae_config(isp_grab_width,isp_grab_height);
      ENABLE_VERTICAL_SUB_SAMPLE;
      ENABLE_HORIZONTAL_SUB_SAMPLE;
			SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));
			SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
      SET_HSUB_DST_SIZE(ipp_video_encode_data.image_src_width);
      SET_VSUB_DST_SIZE(ipp_video_encode_data.image_src_height);
			if (isp_operation_state==ISP_MPEG4_ENCODE_STATE)			
			{
        reconfig_video_encode_data_path(SCENARIO_MPEG_ENCODE_ID,&ipp_video_encode_data);
        video_enc_reset_buffer_counter();
        DISABLE_IBW2_INT;
			}			
#ifdef __3G_VIDEO_CALL__		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//__3G_VIDEO_CALL__		
			
      isp_digital_zoom_flag=KAL_FALSE;
      ENABLE_CMOS_SESNOR;
      DISABLE_CAMERA_IDLE_INT;
      ENABLE_VIEW_FINDER_MODE;
      if(ae_count==0)
        ae_count++;
      hist_idx=0;
#ifdef __SYNC_LCM_SW_SUPPORT__
      video_record_frame=1;
#endif
    }
#ifdef __SYNC_LCM_SW_SUPPORT__
  if ((sync_lcm_enable_mode==KAL_TRUE)&&(video_encode_dc_flag==KAL_FALSE))
  {
    video_encode_update_flag=KAL_TRUE;
    ENABLE_IBW2_INT;
  }
#endif//__SYNC_LCM_SW_SUPPORT__
	   
  img_dma_ibw2_int=KAL_FALSE;
#else //6219
  visual_active_hisr(VISUAL_CAMERA_HISR_ID);
#endif
#endif   /* ISP_SUPPORT */
  //   RestoreIRQMask(save_irq_mask);
}  /* isp_ibw2_cb() */

#if defined(DRV_IDP_6228_SERIES)

/*****************************************************************************
 * FUNCTION
 *  preview_tv_buffer_rotate_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void preview_tv_buffer_rotate_cb(void)
{
#if defined(TV_OUT_SUPPORT) && defined(__MTK_TARGET__)
  if (current_g2d_tv_output_bitblt_buffer == 0)
  {
    tv_fb_update(TV_OUT_OWNER_LCD, camera_preview_config_data.tv_rotate_buffer1_address);
    g2d_tv_output_dest_buff.base_address = camera_preview_config_data.tv_rotate_buffer2_address;
    current_g2d_tv_output_bitblt_buffer = 1;
  }
  else if (current_g2d_tv_output_bitblt_buffer == 1)
  {
    tv_fb_update(TV_OUT_OWNER_LCD, camera_preview_config_data.tv_rotate_buffer2_address);
    g2d_tv_output_dest_buff.base_address = camera_preview_config_data.tv_rotate_buffer1_address;
    current_g2d_tv_output_bitblt_buffer = 0;
  }
  g2d_set_dest_buffer(G2D_OWNER_LCD, &g2d_tv_output_dest_buff);
#endif
}   /* preview_tv_buffer_rotate_cb() */
/*****************************************************************************
 * FUNCTION
 *  mpeg4_vid_enc_w_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mpeg4_vid_enc_w_cb(void)
{
#ifdef TV_OUT_SUPPORT
  if (tv_output_owner == TV_OUT_OWNER_VID_DMA_W)
  {
    if (tv_out_current_fb == 0)
      tv_fb_update(TV_OUT_OWNER_VID_DMA_W, video_encode_config_data.tv_output_buffer1_address);
    else
      tv_fb_update(TV_OUT_OWNER_VID_DMA_W, video_encode_config_data.tv_output_buffer2_address);
    tv_out_current_fb++;
    tv_out_current_fb &= 0x01;
  }
#endif/*#ifdef TV_OUT_SUPPORT */
}   /* mpeg4_vid_enc_w_cb() */

/*****************************************************************************
 * FUNCTION
 *  mpeg4_vid_enc_r_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mpeg4_vid_enc_r_cb(kal_uint8 update_mode)
{   /* in direct couple mode, trigger LCD update */
  kal_bool video_dc_update_flag;

  video_dc_update_flag=KAL_FALSE;
#ifdef __SYNC_LCM_SW_SUPPORT__
  if (sync_lcm_enable_mode==KAL_TRUE)
  {
    kal_uint32 save_irq_mask;
    save_irq_mask = SaveAndSetIRQMask();
    if (update_mode==KAL_FALSE)       /* video encode read DMA interrupt */
    {
      if (video_record_frame == 0)
      {
        REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1;
        REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1;
        REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1;
      }
      else
      {
        REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2;
        REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2;
        REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2;
      }
      video_record_frame++;
      video_record_frame &= 0x01;

      if (video_encode_dc_flag==KAL_FALSE)
      {  /* hardware trigger, output the data to IBW2 image buffer */
        STOP_IBW2;
        STOP_IMGDMA_VIDEO_DECODE;
        START_IBW2;
        START_IMGDMA_VIDEO_DECODE;
      }
      else
        video_encode_update_flag=KAL_TRUE;
    }
    else if (update_mode==KAL_TRUE)   /* sync LCM interrupt */
    {
      if (!lcd_is_busy())
      {  /* do not display the frame */
        STOP_IBW2;
        STOP_IMGDMA_VIDEO_DECODE;
        if (REG_LCD_ROI_HW_CTRL != 0)
        {
          START_IBW2;
          START_IMGDMA_VIDEO_DECODE;
        }
      }
    }
    RestoreIRQMask(save_irq_mask);
  }
  else
    video_dc_update_flag=KAL_TRUE;
#else
  video_dc_update_flag=KAL_TRUE;
#endif
  if (video_dc_update_flag==KAL_TRUE)
  {
    if (lcd_is_busy())
    { /* do not display the frame */
      video_record_frame++;
      video_record_frame &= 0x01;
    }
    else
    {
      STOP_IBW2;
      STOP_IMGDMA_VIDEO_DECODE;
      if (video_record_frame == 0)
      {
        REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1;
        REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1;
        REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1;
      }
      else
      {
        REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2;
        REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2;
        REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR1 = REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2;
      }
      video_record_frame++;
      video_record_frame &= 0x01;
      if (REG_LCD_ROI_HW_CTRL != 0)
      {
        START_IBW2;
        START_IMGDMA_VIDEO_DECODE;
      }
    }
  }
}  /* mpeg4_vid_enc_r_cb() */
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230)) */

#if defined(DRV_IDP_6219_SERIES)
/*****************************************************************************
 * FUNCTION
 *  config_pixel_resizer
 * DESCRIPTION
 *  This function is to configure MT6219 resizer for each multi-media scenario
 * CALLS
 *
 * PARAMETERS
 *  scenario_id     [IN]        which scenario will be applied by resizer
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 config_pixel_resizer(MMDI_SCENERIO_ID scenario_id)
{
  RESZ_DCB_STRUCT resizer_dcb;
  RESZ_PXL_CFG_STRUCT resizer_cfg;
  kal_uint16 src_width=0, src_height=0, target_width=0, target_height=0;

  if (scenario_id == SCENARIO_MPEG_SNAPSHOT_ID)
    resizer_dcb.owner = SCENARIO_MPEG_DECODE_ID;
  else
    resizer_dcb.owner = scenario_id;
  RESZ_Open(resizer_dcb.owner);

  switch (scenario_id)
  {
#if (defined(ISP_SUPPORT))
  case SCENARIO_CAMERA_PREVIEW_ID:
    resizer_dcb.cfg.src1 = SRC_CAMERA;
    resizer_dcb.cfg.pcontinue = 1;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 0;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width = isp_preview_config_data.source_width;
    src_height = isp_preview_config_data.source_height;
    target_width = isp_preview_config_data.target_width;
    target_height = isp_preview_config_data.target_height;
    resizer_cfg.wmbase = (kal_uint32) intmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER * 3));
    break;
#if (defined(WEBCAM_SUPPORT))
  case SCENARIO_USBVIDEO_CAPTURE_JPEG_ID:
    resizer_dcb.cfg.src1 = SRC_CAMERA;
    resizer_dcb.cfg.pcontinue = 0;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 0;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width = g_usbvideo_camera_data.source_width;
    src_height = g_usbvideo_camera_data.source_height;
    target_width = g_usbvideo_camera_data.target_width;
    target_height = g_usbvideo_camera_data.target_height;
    resizer_cfg.wmbase = (kal_uint32) intmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER * 3));
    break;
#endif /* (defined(WEBCAM_SUPPORT)) */
  case SCENARIO_CAMERA_CAPTURE_JPEG_ID:
#if (defined(DRV_IDP_6219_SERIES))
    if (isp_capture_jpeg_data.source_height == isp_capture_jpeg_data.target_height)
      (*((volatile unsigned int*)0x80610090)) = 0x00000200;
#endif /* (defined(MT6219) || defined(MT6226) || defined(MT6226M) || defined(MT6227)||defined(MT6227D)||defined(MT6226D)) */
    resizer_dcb.cfg.src1 = SRC_CAMERA;
    resizer_dcb.cfg.pcontinue = 0;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 0;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width = isp_capture_jpeg_data.source_width;
    src_height = isp_capture_jpeg_data.source_height;
    target_width = isp_capture_jpeg_data.target_width;
    target_height = isp_capture_jpeg_data.target_height;
    resizer_cfg.wmbase = (kal_uint32) intmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER * 3));
    break;
  case SCENARIO_MPEG_ENCODE_ID:
    resizer_dcb.cfg.src1 = SRC_CAMERA;
    resizer_dcb.cfg.pcontinue = 1;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 1;
    resizer_dcb.cfg.src2 = SRC_MPEG4;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width = mpeg4_encode_data.image_source_width;
    src_height = mpeg4_encode_data.image_source_height;
    target_width = mpeg4_encode_data.mpeg4_image_width;
    target_height = mpeg4_encode_data.mpeg4_image_height;
    if(mpeg4_encode_data.init_mem == KAL_TRUE)
    {            	
      resizer_cfg.wmbase=(kal_uint32) intmem_get_buffer(IDP_VR_MAXIMUM_RESZ_WM_SIZE);	
    }
    else/*not get buffer again, use the old one*/
    {
      resizer_cfg.wmbase=DRV_Reg32(RESZ_PRWMBASE);
    }
    break;
  case SCENARIO_CAMERA_CAPTURE_MEM_ID:
    resizer_dcb.cfg.src1 = SRC_CAMERA;
    resizer_dcb.cfg.pcontinue = 0;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 0;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width = isp_capture_mem_data.source_width;
    src_height = isp_capture_mem_data.source_height;
    target_width = isp_capture_mem_data.target_width;
    target_height = isp_capture_mem_data.target_height;
    resizer_cfg.wmbase = (kal_uint32) intmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER * 3));
    break;
    /*XXXXX add for barcode*/
  case SCENARIO_CAMERA_CAPTURE_BARCODE_ID:
    resizer_dcb.cfg.src1 = SRC_CAMERA;
    resizer_dcb.cfg.pcontinue = 1;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 0;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width = isp_capture_barcode_data.source_width;/*ISP output size*/
    src_height = isp_capture_barcode_data.source_height;

    if ((get_lcd_hw_layer_rotate_value(isp_capture_barcode_data.hw_update_layer)==LCD_LAYER_ROTATE_NORMAL) &&
        ((current_lcd_rotate_value==LCD_LAYER_ROTATE_NORMAL) ||
         (current_lcd_rotate_value==LCD_LAYER_ROTATE_180) ||
         (current_lcd_rotate_value==LCD_LAYER_MIRROR) ||
         (current_lcd_rotate_value==LCD_LAYER_MIRROR_ROTATE_180)))
    {
      target_width=  isp_capture_barcode_data.lcm_end_x-isp_capture_barcode_data.lcm_start_x+1;
      target_height= isp_capture_barcode_data.lcm_end_y-isp_capture_barcode_data.lcm_start_y+1;
    }
    else
    {
      target_height= isp_capture_barcode_data.lcm_end_x-isp_capture_barcode_data.lcm_start_x+1;
      target_width=  isp_capture_barcode_data.lcm_end_y-isp_capture_barcode_data.lcm_start_y+1;
    }
    resizer_cfg.wmbase = (kal_uint32) intmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER * 3));
    break;
  case SCENARIO_CAMERA_CAPTURE_BARCODE_SAVE_ID:
    resizer_dcb.cfg.src1 = SRC_CAMERA;
    resizer_dcb.cfg.pcontinue = 0;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 0;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width =  isp_capture_barcode_data.source_width;
    src_height = isp_capture_barcode_data.source_height;
    target_width = isp_capture_barcode_data.target_width;
    target_height = isp_capture_barcode_data.target_height;
    resizer_cfg.wmbase = (kal_uint32) intmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER * 3));
    break;

#endif /* (defined(ISP_SUPPORT)) */
  case SCENARIO_JPEG_ENCODE_ID:
  case SCENARIO_MPEG_SNAPSHOT_ID:
    resizer_dcb.cfg.src1 = SRC_MEM;
    resizer_dcb.cfg.pcontinue = 0;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 0;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width = jpeg_encode_config_data.image_width;
    src_height = jpeg_encode_config_data.image_height;
    target_width = jpeg_encode_config_data.target_width;
    target_height = jpeg_encode_config_data.target_height;
    if (scenario_id == SCENARIO_JPEG_ENCODE_ID)
    {
      resizer_cfg.wmbase=(kal_uint32) intmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER*3));
    }
#if (defined(MP4_CODEC))
    else
    {
      resizer_cfg.wmbase = video_dec_get_snapshot_resize_mem();
      if (resizer_cfg.wmbase == NULL)
      {
        resizer_cfg.wmbase=(kal_uint32) extmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER*3));
        video_dec_set_snapshot_resize_mem(resizer_cfg.wmbase);
      }
    }
#endif /* (defined(MP4_CODEC)) */
    break;
  case SCENARIO_RESIZE_ID:
    resizer_dcb.cfg.src1 = SRC_MEM;
    resizer_dcb.cfg.pcontinue = 0;
    resizer_dcb.cfg.pixel_sel = 1;
    resizer_dcb.cfg.run2 = 0;

    resizer_cfg.wmsize = RESIZER_WORKING_MEM_LINE_NUMBER;
    src_width = image_resize_data.src_pitch;
    src_height = image_resize_data.src_height;
    target_width = image_resize_data.target_pitch;
    target_height = image_resize_data.target_height;
    resizer_cfg.wmbase = (kal_uint32) intmem_get_buffer((target_width * RESIZER_WORKING_MEM_LINE_NUMBER * 3));
    break;
  }
  RESZ_Config((RESZ_CFG_STRUCT*) & resizer_dcb.cfg, &resizer_cfg, resizer_dcb.owner);

  RESZ_SetSize(src_width, src_height, target_width, target_height, resizer_dcb.owner);

  if (scenario_id == SCENARIO_MPEG_ENCODE_ID)
    RESZ_SetSize2(target_width, target_height, mpeg4_encode_data.image_target_width,
                  mpeg4_encode_data.image_target_height,resizer_dcb.owner);

  RESZ_Start(resizer_dcb.owner);

  return KAL_TRUE;
}   /* config_pixel_resizer() */
/*****************************************************************************
 * FUNCTION
 *  config_image_processor
 * DESCRIPTION
 *  This function is to configure MT6219 image processor for each multi-media scenario
 * CALLS
 *
 * PARAMETERS
 *  scenario_id     [IN]        which scenario will be applied by image processor
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 config_image_processor(MMDI_SCENERIO_ID scenario_id)
{
  MMDI_SCENERIO_ID scenario_id1 = SCENARIO_UNKNOW_ID;
  IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;
  IMGPROC_MODE_ENUM image_proc_mode=0;

  switch (scenario_id)
  {
#if (defined(ISP_SUPPORT))
  case SCENARIO_CAMERA_PREVIEW_ID:
    image_proc_mode = IMGPROC_DECODE;
    break;
#if (defined(WEBCAM_SUPPORT))
  case SCENARIO_USBVIDEO_CAPTURE_JPEG_ID:
#endif
  case SCENARIO_CAMERA_CAPTURE_JPEG_ID:
    image_proc_mode = IMGPROC_CAPTURE;
    break;
  case SCENARIO_MPEG_ENCODE_ID:
    image_proc_mode = IMGPROC_MPEG_ENCODE;
    break;
  case SCENARIO_CAMERA_CAPTURE_MEM_ID:
    image_proc_mode = IMGPROC_DECODE;
    break;
    /*XXXXX add for barcode*/
  case SCENARIO_CAMERA_CAPTURE_BARCODE_ID:/*XXXXX add for barcode*/
    image_proc_mode = IMGPROC_DECODE;
    break;
  case SCENARIO_CAMERA_CAPTURE_BARCODE_SAVE_ID:/*XXXXX add for barcode*/
    image_proc_mode = IMGPROC_DECODE;
    break;
#endif /* (defined(ISP_SUPPORT)) */
  case SCENARIO_JPEG_DECODE_ID:
    image_proc_mode = IMGPROC_DECODE;
    break;
  case SCENARIO_MPEG_SNAPSHOT_ID:
    image_proc_mode = IMGPROC_ENCODE;
    scenario_id = SCENARIO_MPEG_DECODE_ID;
    scenario_id1 = SCENARIO_MPEG_SNAPSHOT_ID;
    break;
  case SCENARIO_JPEG_ENCODE_ID:
    image_proc_mode = IMGPROC_ENCODE;
    break;
  case SCENARIO_RESIZE_ID:
    image_proc_mode = IMGPROC_EFFECT;
    break;
  }
  IMGPROC_Open(scenario_id);
#if (defined(ISP_SUPPORT))
  clean_imgprc_coefficient(scenario_id);
#endif
  IMGPROC_SelectMode(image_proc_mode, scenario_id);
  if (((scenario_id == SCENARIO_CAMERA_PREVIEW_ID) ||
#if (defined(WEBCAM_SUPPORT))
       (scenario_id == SCENARIO_USBVIDEO_CAPTURE_JPEG_ID) ||
#endif
       (scenario_id == SCENARIO_CAMERA_CAPTURE_JPEG_ID) ||
       (scenario_id == SCENARIO_CAMERA_CAPTURE_MEM_ID) ||
       /*XXXXX add for barcode*/
       (scenario_id == SCENARIO_CAMERA_CAPTURE_BARCODE_ID) ||
       (scenario_id == SCENARIO_CAMERA_CAPTURE_BARCODE_SAVE_ID) ||
       (scenario_id == SCENARIO_MPEG_ENCODE_ID)) && (scenario_id1 == SCENARIO_UNKNOW_ID))
  {
    pixel_effect_para.hsa = IMGPROC_HSA_HUE_SAT;    /* turn on Hue and Saturation function */
    pixel_effect_para.cba = 1;
    pixel_effect_para.inv = 0;
    pixel_effect_para.clr = 0;
    pixel_effect_para.gma = 0;
    IMGPROC_SetPixelEffect(&pixel_effect_para, scenario_id);
  }
  IMGPROC_Start(scenario_id);
  return KAL_TRUE;
}   /* config_image_processor() */
/*****************************************************************************
 * FUNCTION
 *  config_image_dma
 * DESCRIPTION
 *  This function is to configure MT6219 image dma for each multi-media scenario
 * CALLS
 *
 * PARAMETERS
 *  scenario_id     [IN]        which scenario will be applied by image dma
 *  tar_width       [IN]
 *  tar_height      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 config_image_dma(MMDI_SCENERIO_ID scenario_id, kal_uint16 tar_width, kal_uint16 tar_height)
{
  kal_uint8 buffer_ptr[40];
  IMGDMA_IBW2_STRUCT *ibw2_para = (IMGDMA_IBW2_STRUCT*) buffer_ptr;
  IMGDMA_IBR1_STRUCT *ibr1_para = (IMGDMA_IBR1_STRUCT*) buffer_ptr;
  IMGDMA_JPEG_STRUCT *jpeg_idma_para = (IMGDMA_JPEG_STRUCT*) buffer_ptr;
  IMGDMA_VDO_STRUCT *video_dma_para = (IMGDMA_VDO_STRUCT*) buffer_ptr;

  if (scenario_id == SCENARIO_MPEG_SNAPSHOT_ID)
    IMGDMA_Open(SCENARIO_MPEG_DECODE_ID);
  else
    IMGDMA_Open(scenario_id);

  switch (scenario_id)
  {
#if (defined(ISP_SUPPORT))
  case SCENARIO_CAMERA_PREVIEW_ID:
    ibw2_para->twice = 0;
    ibw2_para->restart = 1;
    ibw2_para->lcd_hk = 1;
    ibw2_para->couple = 0;
    ibw2_para->pan = 0;
    ibw2_para->bs1 = isp_preview_config_data.frame_buffer_address;
    ibw2_para->bs2 = isp_preview_config_data.frame_buffer_address1;
    ibw2_para->width = tar_width;
    ibw2_para->height = tar_height;
    ibw2_para->cb = NULL;
#ifdef __SYNC_LCM_SW_SUPPORT__
    preview_buffer1_address=isp_preview_config_data.frame_buffer_address;
    preview_buffer2_address=isp_preview_config_data.frame_buffer_address1;

    switch (isp_preview_config_data.hw_update_layer)
    {
    case LCD_LAYER0_ENABLE:
      preview_layer_base_address=LCD_LAYER0_BUFF_ADDR_REG;
      break;
    case LCD_LAYER1_ENABLE:
      preview_layer_base_address=LCD_LAYER1_BUFF_ADDR_REG;
      break;
    case LCD_LAYER2_ENABLE:
      preview_layer_base_address=LCD_LAYER2_BUFF_ADDR_REG;
      break;
    case LCD_LAYER3_ENABLE:
      preview_layer_base_address=LCD_LAYER3_BUFF_ADDR_REG;
      break;
    }

    preview_frame_buffer_swap=0;
    preview_frame_update_flag=KAL_FALSE;
    sync_lcm_enable_mode=KAL_TRUE;
    EINT_UnMask(sync_lcm_channel_number);
    sync_lcm_update_cb=sync_lcm_preview_update_cb;
    ibw2_para->lcd_hk = 0;
    ibw2_para->cb = preview_frame_ready_cb;
#endif
    IMGDMA_IBW2Config(ibw2_para, 1, scenario_id);
    break;
  case SCENARIO_MPEG_ENCODE_ID:
    current_video_buffer_count = 0;
    video_dma_para->dir = 1;
    video_dma_para->twice = 1;
    video_dma_para->restart = 1;
    video_dma_para->bs1 = mpeg4_encode_data.video_buffer1_address;
    video_dma_para->bs2 = mpeg4_encode_data.video_buffer2_address;
    mpeg4_video_buffer[0] = video_dma_para->bs1;
    mpeg4_video_buffer[1] = video_dma_para->bs2;
    video_dma_para->width = mpeg4_encode_data.mpeg4_image_width;
    video_dma_para->height = mpeg4_encode_data.mpeg4_image_height;
    video_dma_para->cb1 = mpeg4_encode_data.mpeg4_encode_cb;
    video_dma_para->cb2 = NULL;

    IMGDMA_VdoConfig(video_dma_para, 1, scenario_id);

    ibw2_para->twice = 1;
    ibw2_para->restart = 1;
    ibw2_para->lcd_hk = 1;
    ibw2_para->couple = 0;
    ibw2_para->pan = 0;
    ibw2_para->bs1 = (kal_uint32) (mpeg4_encode_data.frame_buffer_address +
                                   ((mpeg4_encode_data.mpeg4_offset_y * tar_width +
                                     mpeg4_encode_data.mpeg4_offset_x) << 1));
    ibw2_para->bs2 = ibw2_para->bs1;

    ibw2_para->width = tar_width;
    ibw2_para->height = tar_height;
    ibw2_para->cb = isp_ibw2_cb;
#ifdef __SYNC_LCM_SW_SUPPORT__
    video_encode_dc_flag=KAL_FALSE;
    sync_lcm_update_cb=sync_lcm_video_encode_update_cb;
    sync_lcm_enable_mode=KAL_TRUE;
    EINT_UnMask(sync_lcm_channel_number);
    ibw2_para->lcd_hk = 0;
#endif
    IMGDMA_IBW2Config(ibw2_para, 1, scenario_id);
#ifndef __SYNC_LCM_SW_SUPPORT__
    *(volatile unsigned int*)0x80690404 &= ~1; /* disable IBW2 interrupt forcely for
                                                  digital zoom during MPEG4 recording */
#endif
    break;
#if (defined(WEBCAM_SUPPORT))
  case SCENARIO_USBVIDEO_CAPTURE_JPEG_ID:
#endif
  case SCENARIO_CAMERA_CAPTURE_JPEG_ID:
    jpeg_idma_para->fifo = JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER;
    jpeg_idma_para->width = tar_width;
    jpeg_idma_para->height = tar_height;
    jpeg_idma_para->gray = jpeg_encode_config_data.jpeg_gray_mode;
    jpeg_idma_para->bs= (kal_uint32) intmem_get_buffer((jpeg_idma_para->fifo*((jpeg_idma_para->width&0xFFF0)+16))<<1);
    jpeg_idma_para->cb = NULL;
    IMGDMA_JpegConfig(jpeg_idma_para, 1, scenario_id);
    break;
  case SCENARIO_CAMERA_CAPTURE_MEM_ID:
    ibw2_para->twice = 0;
    ibw2_para->restart = 0;
    ibw2_para->lcd_hk = 1;
    ibw2_para->couple = 0;
    ibw2_para->pan = 0;
    ibw2_para->bs1 = isp_capture_mem_data.imgdma_buffer_address;
    ibw2_para->bs2 = isp_capture_mem_data.imgdma_buffer_address;

    ibw2_para->width = tar_width;
    ibw2_para->height = tar_height;
    ibw2_para->cb = NULL;
    IMGDMA_IBW2Config(ibw2_para, 1, scenario_id);
    break;
    /*XXXXX add for barcode*/
  case SCENARIO_CAMERA_CAPTURE_BARCODE_ID:
    ibw2_para->twice = 0;
    ibw2_para->restart = 1;
    ibw2_para->lcd_hk = 1;
    ibw2_para->couple = 0;
    ibw2_para->pan = 0;
    ibw2_para->bs1 = isp_capture_barcode_data.frame_buffer_address;
    ibw2_para->bs2 = isp_capture_barcode_data.frame_buffer_address1;

    if ((get_lcd_hw_layer_rotate_value(isp_capture_barcode_data.hw_update_layer)==LCD_LAYER_ROTATE_NORMAL) &&
        ((current_lcd_rotate_value==LCD_LAYER_ROTATE_NORMAL) ||
         (current_lcd_rotate_value==LCD_LAYER_ROTATE_180) ||
         (current_lcd_rotate_value==LCD_LAYER_MIRROR) ||
         (current_lcd_rotate_value==LCD_LAYER_MIRROR_ROTATE_180)))
    {
      ibw2_para->width= isp_capture_barcode_data.lcm_end_x-isp_capture_barcode_data.lcm_start_x+1;
      ibw2_para->height=   isp_capture_barcode_data.lcm_end_y-isp_capture_barcode_data.lcm_start_y+1;
    }
    else
    {
      ibw2_para->height=   isp_capture_barcode_data.lcm_end_x-isp_capture_barcode_data.lcm_start_x+1;
      ibw2_para->width= isp_capture_barcode_data.lcm_end_y-isp_capture_barcode_data.lcm_start_y+1;
    }

    ibw2_para->cb = NULL;
    IMGDMA_IBW2Config(ibw2_para, 1, scenario_id);
    break;
  case SCENARIO_CAMERA_CAPTURE_BARCODE_SAVE_ID:
    ibw2_para->twice = 0;
    ibw2_para->restart = 0;
    ibw2_para->lcd_hk = 0;
    ibw2_para->couple = 0;
    ibw2_para->pan = 0;
    ibw2_para->bs1 = isp_capture_barcode_data.barcode_buffer_address;
    ibw2_para->bs2 = isp_capture_barcode_data.barcode_buffer_address;

    ibw2_para->width = tar_width;
    ibw2_para->height = tar_height;
    ibw2_para->cb = NULL;
    IMGDMA_IBW2Config(ibw2_para, 1, scenario_id);
    break;
#endif /* (defined(ISP_SUPPORT)) */
  case SCENARIO_JPEG_ENCODE_ID:
  case SCENARIO_MPEG_SNAPSHOT_ID:
    if (scenario_id == SCENARIO_MPEG_SNAPSHOT_ID)
      scenario_id = SCENARIO_MPEG_DECODE_ID;
    jpeg_idma_para->fifo = JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER;
    jpeg_idma_para->width = jpeg_encode_config_data.target_width;
    jpeg_idma_para->height = jpeg_encode_config_data.target_height;
    jpeg_idma_para->gray = jpeg_encode_config_data.jpeg_gray_mode;

    if (scenario_id == SCENARIO_JPEG_ENCODE_ID)
    {
      jpeg_idma_para->bs= (kal_uint32) intmem_get_buffer((jpeg_idma_para->fifo*((jpeg_idma_para->width&0xFFF0)+16))<<1);
    }
#if (defined(MP4_CODEC))
    else
    {
      jpeg_idma_para->bs = video_dec_get_snapshot_imgdma_mem();
      if (jpeg_idma_para->bs == NULL)
      {
        jpeg_idma_para->bs= (kal_uint32) extmem_get_buffer((jpeg_idma_para->fifo*((jpeg_idma_para->width&0xFFF0)+16))<<1);
        video_dec_set_snapshot_imgdma_mem(jpeg_idma_para->bs);
      }
    }
#endif /* (defined(MP4_CODEC)) */
    jpeg_idma_para->cb = NULL;
    IMGDMA_JpegConfig(jpeg_idma_para, 1, scenario_id);

    ibr1_para->type = jpeg_encode_config_data.type;
    ibr1_para->order = jpeg_encode_config_data.data_order;
    ibr1_para->bs = jpeg_encode_config_data.image_buffer_address;
    ibr1_para->pxlnum = jpeg_encode_config_data.image_width * jpeg_encode_config_data.image_height;
    ibr1_para->cb = NULL;

    IMGDMA_IBR1Config(ibr1_para, 0, scenario_id);
    break;
  case SCENARIO_JPEG_DECODE_ID:
    ibw2_para->twice = 0;
    ibw2_para->restart = 0;
    ibw2_para->lcd_hk = 0;
    ibw2_para->couple = 0;
    ibw2_para->pan = 1;
    ibw2_para->bs1 = jpeg_decode_config_data.image_buffer_address;
    ibw2_para->width = tar_width;
    ibw2_para->height = tar_height;
    ibw2_para->hpitch1 = jpeg_decode_config_data.image_clip_x1;
    ibw2_para->hpitch2 = jpeg_decode_config_data.image_clip_x2;
    ibw2_para->vpitch1 = jpeg_decode_config_data.image_clip_y1;
    ibw2_para->vpitch2 = jpeg_decode_config_data.image_clip_y2;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    ibw2_para->cb = jpeg_decode_cb;
    IMGDMA_IBW2Config(ibw2_para, 1, scenario_id);
    break;
  case SCENARIO_RESIZE_ID:
    ibw2_para->twice = 0;
    ibw2_para->restart = 0;
    ibw2_para->lcd_hk = 0;
    ibw2_para->couple = 0;
    ibw2_para->pan = 1;
    ibw2_para->bs1 = image_resize_data.dest_image_address;
    ibw2_para->bs2 = ibw2_para->bs1;
    ibw2_para->width = image_resize_data.target_pitch;
    ibw2_para->height = image_resize_data.target_height;
    ibw2_para->hpitch1 = image_resize_data.image_clip_x1;
    ibw2_para->hpitch2 = image_resize_data.image_clip_x2;
    ibw2_para->vpitch1 = image_resize_data.image_clip_y1;
    ibw2_para->vpitch2 = image_resize_data.image_clip_y2;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    ibw2_para->cb = NULL;
    IMGDMA_IBW2Config(ibw2_para, 1, scenario_id);

    ibr1_para->type = image_resize_data.type;
    ibr1_para->order = image_resize_data.data_order;
    ibr1_para->bs = image_resize_data.src_image_address;
    ibr1_para->pxlnum = image_resize_data.src_pitch * image_resize_data.src_height;
    ibr1_para->cb = NULL;

    IMGDMA_IBR1Config(ibr1_para, 1, scenario_id);
    break;
  }

  return KAL_TRUE;
}   /* config_image_dma() */
/*****************************************************************************
 * FUNCTION
 *  stop_image_dma
 * DESCRIPTION
 *  This function is to stop MT6219 image dma for each multi-media scenario
 * CALLS
 *
 * PARAMETERS
 *  scenario_id     [IN]        which image dma scenario will be stopped
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 stop_image_dma(MMDI_SCENERIO_ID scenario_id)
{
  IMGDMA_CHANNEL_ENUM idma_ch1, idma_ch2;
  IMGDMA_STOP_ENUM idma_stop_mode;
#ifdef __SYNC_LCM_SW_SUPPORT__
  extern kal_timerid sync_lcm_timer_handle;
#endif

  switch (scenario_id)
  {
#if (defined(ISP_SUPPORT))
  case SCENARIO_CAMERA_PREVIEW_ID:
    idma_ch1 = IMGDMA_IBW2_CH;
    idma_stop_mode = IMGDMA_STOP_NOW;
    IMGDMA_Stop(idma_ch1, idma_stop_mode, NULL, scenario_id);
#ifdef __SYNC_LCM_SW_SUPPORT__
    EINT_Mask(sync_lcm_channel_number);
    sync_lcm_enable_mode=KAL_FALSE;
    sync_lcm_update_cb=NULL;
    sync_lcm_delay_flag=KAL_FALSE;
#endif
    break;
  case SCENARIO_MPEG_ENCODE_ID:
    idma_ch1 = IMGDMA_VDO_CH;
    idma_ch2 = IMGDMA_IBW2_CH;
    idma_stop_mode = IMGDMA_STOP_NOW;
    IMGDMA_Stop(idma_ch1, idma_stop_mode, NULL, scenario_id);
    IMGDMA_Stop(idma_ch2, idma_stop_mode, NULL, scenario_id);
#ifdef __SYNC_LCM_SW_SUPPORT__
    EINT_Mask(sync_lcm_channel_number);
    sync_lcm_enable_mode=KAL_FALSE;
    sync_lcm_update_cb=NULL;
    sync_lcm_delay_flag=KAL_FALSE;				
#endif
    break;
#if (defined(WEBCAM_SUPPORT))
  case SCENARIO_USBVIDEO_CAPTURE_JPEG_ID:
#endif
  case SCENARIO_CAMERA_CAPTURE_JPEG_ID:
    idma_ch1 = IMGDMA_JPEG_CH;
    idma_stop_mode = IMGDMA_STOP_NOW;
    IMGDMA_Stop(idma_ch1, idma_stop_mode, NULL, scenario_id);
    break;
    /*XXXXX add for barcode*/
  case SCENARIO_CAMERA_CAPTURE_BARCODE_ID:
    idma_ch1 = IMGDMA_IBW2_CH;
    idma_stop_mode = IMGDMA_STOP_NOW;
    IMGDMA_Stop(idma_ch1, idma_stop_mode, NULL, scenario_id);
    break;
#endif /* (defined(ISP_SUPPORT)) */
  case SCENARIO_JPEG_ENCODE_ID:
  case SCENARIO_MPEG_SNAPSHOT_ID:
    if (scenario_id == SCENARIO_MPEG_SNAPSHOT_ID)
      scenario_id = SCENARIO_MPEG_DECODE_ID;
    idma_ch1 = IMGDMA_IBR1_CH;
    idma_ch2 = IMGDMA_JPEG_CH;
    idma_stop_mode = IMGDMA_STOP_NOW;
    IMGDMA_Stop(idma_ch1, idma_stop_mode, NULL, scenario_id);
    IMGDMA_Stop(idma_ch2, idma_stop_mode, NULL, scenario_id);
    break;
  case SCENARIO_JPEG_DECODE_ID:
    idma_ch1 = IMGDMA_IBW2_CH;
    idma_stop_mode = IMGDMA_STOP_NOW;
    IMGDMA_Stop(idma_ch1, idma_stop_mode, NULL, scenario_id);
    break;
  case SCENARIO_RESIZE_ID:
    idma_ch1 = IMGDMA_IBR1_CH;
    idma_ch2 = IMGDMA_IBW2_CH;
    idma_stop_mode = IMGDMA_STOP_NOW;
    IMGDMA_Stop(idma_ch1, idma_stop_mode, NULL, scenario_id);
    IMGDMA_Stop(idma_ch2, idma_stop_mode, NULL, scenario_id);
    break;
  }
  return KAL_TRUE;
}   /* stop_image_dma() */

extern camera_capture_barcode_struct isp_capture_barcode_data;
/*****************************************************************************
 * FUNCTION
 *  get_barcode_image
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void get_barcode_image(void)
{
  kal_uint32 event_group;
  MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_CAPTURE_BARCODE_SAVE_ID;
  lcd_frame_update_to_mem_struct lcd_data;

  lcd_data.fb_update_mode=LCD_HW_TRIGGER_MODE;
  lcd_data.block_mode=KAL_FALSE;
  // lcd_data.dest_block_width=;
  lcd_data.dest_buffer_address=isp_capture_barcode_data.barcode_buffer_address;
  lcd_data.dest_buffer_size=isp_capture_barcode_data.barcode_buffer_size;
  lcd_data.roi_offset_x=isp_capture_barcode_data.roi_offset_x;
  lcd_data.roi_offset_y=isp_capture_barcode_data.roi_offset_y;
  lcd_data.roi_width=isp_capture_barcode_data.lcm_end_x-isp_capture_barcode_data.lcm_start_x+1;
  lcd_data.roi_height=isp_capture_barcode_data.lcm_end_y-isp_capture_barcode_data.lcm_start_y+1;
  lcd_data.update_layer=isp_capture_barcode_data.update_layer;
  lcd_data.hw_update_layer=isp_capture_barcode_data.hw_update_layer;
  lcd_data.roi_background_color=0xFFFFFF;

  pause_camera_capture_barcode_process();

  // get barcode image
  intmem_init((kal_uint32 *) isp_capture_barcode_data.intmem_start_address,
              isp_capture_barcode_data.intmem_size);
  extmem_init((kal_uint32 *) isp_capture_barcode_data.extmem_start_address,
              isp_capture_barcode_data.extmem_size);
  
//  lcd_fb_update_to_memory(&lcd_data);
  config_image_dma(scene_id,isp_capture_barcode_data.target_width,isp_capture_barcode_data.target_height);
  config_image_processor(scene_id);
  config_pixel_resizer(scene_id);

  //kal_set_eg_events(lcd_event_id,0,KAL_AND);
  //test
  ENABLE_CMOS_SESNOR;
  SET_CAMERA_CAPTURE_MODE;
  ENABLE_VIEW_FINDER_MODE;
  
  while (IMGDMA_CheckBusy(IMGDMA_IBW2_CH, SCENARIO_CAMERA_CAPTURE_BARCODE_SAVE_ID))
  {
  }
  
  kal_sleep_task(15);
  DISABLE_VIEW_FINDER_MODE;
  
  RESZ_Stop(scene_id);
  RESZ_Close(scene_id);
#if (defined(ISP_SUPPORT))
  clean_imgprc_coefficient(scene_id);
#endif
  IMGPROC_Stop(scene_id);
  IMGPROC_Close(scene_id);
  stop_image_dma(scene_id);
  IMGDMA_Close(scene_id);
  intmem_deinit();
  extmem_deinit();

  resume_camera_capture_barcode_process();
}
#endif /* (defined(MT6219) || defined(MT6226) || defined(MT6226M) || defined(MT6227)||defined(MT6227D)||defined(MT6226D)) */ /* MT6219, MT6226, MT6227 */

#if defined(DRV_RGB_RESIZE_SUPPORT)
/*************************************************************************
 * FUNCTION
 *     image_resize_process
 *
 * DESCRIPTION
 *     This function resize one RGB image as RGB format.
 *
 * PARAMETERS
 *
 *  resize_para    the parameters the for image resize process
 *
 * RETURNS
 *   return_code : the image resize process error code
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_uint8 image_resize_process(resize_struct *resize_para)
{
#if (defined(DRV_IDP_6219_SERIES) || defined(DRV_IDP_6225_SERIES) || defined(DRV_IDP_6228_SERIES))
  image_resize_process_legacy_series(resize_para);
#elif defined(DRV_IDP_6238_SERIES)
  image_resize_process_6238_series(resize_para);  
#endif
}  /* image_resize_process() */
#endif //(defined(DRV_RGB_RESIZE_SUPPORT))

#if defined(DRV_IDP_6228_SERIES)
/*****************************************************************************
 * FUNCTION
 *  image_data_path_reset_delay
 * DESCRIPTION
 *  This function is to cover image data path hw reset bug, especially in TV out.
 * PARAMETERS
 *  scenario_id     [IN]
 * RETURNS
 *
 *****************************************************************************/
void image_data_path_reset_delay(kal_uint32 delay)
{
#ifdef TV_OUT_SUPPORT
  kal_uint32 i;

  for(i=0;i<delay;i++)
  {
  }
#endif
}/*image_data_path_reset_delay*/


/*translate RGB888/565 to YUV 420*/

#endif /* (defined(DRV_IDP_6228_SERIES)) */

#endif /* (defined(MT6217) ||defined(MT6223) || defined(MT6223P)|| defined(DRV_IDP_6219_SERIES) || defined(DRV_IDP_6228_SERIES)) */

#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )

/*****************************************************************************
 * FUNCTION
 *  idp_register_app
 * DESCRIPTION
 *    provide an interface for upper layer registeration
 * PARAMETERS
 *  new_app: new scenerio id
 *  old_app: original scenerio id
 * RETURNS
 *  KAL_TURE: success
 *  KAL_False: fail
 *****************************************************************************/
kal_bool idp_register_app(MMDI_SCENERIO_ID new_app, MMDI_SCENERIO_ID *old_app)
{
#if (defined(DRV_IDP_6219_SERIES) || defined(DRV_IDP_6225_SERIES) || defined(DRV_IDP_6228_SERIES))
  idp_register_app_legacy_series(new_app, old_app);
#elif defined(DRV_IDP_6238_SERIES)
  idp_register_app_6238_series(new_app, old_app);  
#endif
}   /* init_image_data_path() */

#endif

/*****************************************************************************
 * FUNCTION
 *  image_data_path_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void image_data_path_init(void)
{
#if (defined(DRV_IDP_6219_SERIES) || defined(DRV_IDP_6225_SERIES) || defined(DRV_IDP_6228_SERIES))
  image_data_path_init_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  image_data_path_init_6238_series();
#endif
}   /* init_image_data_path() */

#if (defined(DRV_IDP_6228_SERIES)||defined(DRV_IDP_6238_SERIES))

/*****************************************************************************
 * FUNCTION
 *  config_jpeg_resize_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 *  jpeg_para       [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_jpeg_resize_data_path(MMDI_SCENERIO_ID scenario_id, jpeg_file_resize_struct *jpeg_para)
{
#if defined(DRV_IDP_6228_SERIES)
  config_jpeg_resize_data_path_legacy_series(scenario_id, jpeg_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_jpeg_resize_data_path_6238_series(scenario_id, jpeg_para);
#endif
}   /* config_jpeg_resize_data_path() */

/*****************************************************************************
 * FUNCTION
 *  close_jpeg_resize_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_jpeg_resize_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)
  close_jpeg_resize_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  close_jpeg_resize_data_path_6238_series();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  close_image_resize_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_image_resize_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)
  close_image_resize_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  close_image_resize_data_path_6238_series();
#endif
}   /* close_image_resize_data_path() */

/*****************************************************************************
 * FUNCTION
 *  close_video_encode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_video_encode_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)
  close_video_encode_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  close_video_encode_data_path_6238_series();
#endif
}   /* close_video_encode_data_path() */

/*****************************************************************************
 * FUNCTION
 *  close_video_decode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_video_decode_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)
  close_video_decode_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  close_video_decode_data_path_6238_series();
#endif
}   /* close_video_decode_data_path() */

/*****************************************************************************
 * FUNCTION
 *  close_image_effect_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_image_effect_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)
  close_image_effect_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  close_image_effect_data_path_6238_series();
#endif
}

void config_RGB2YUV420_data_path(MMDI_SCENERIO_ID scenario_id, RGB2YUV420_struct  *rgb2yuv420_struct)
{   
#if defined(DRV_IDP_6228_SERIES)      
  config_RGB2YUV420_data_path_legacy_series(scenario_id,rgb2yuv420_struct);
#elif defined(DRV_IDP_6238_SERIES)      
  config_RGB2YUV420_data_path_6238_series(scenario_id,rgb2yuv420_struct);
#endif  
}   

/*****************************************************************************
 * FUNCTION
 *  stop_RGB2YUV420_data_path
 * DESCRIPTION
 *  This function is to stop translating RGB to YUV 
 * PARAMETERS
 *  scenario_id: scenario id
 *  rgb2yuv420_struct: 
 * RETURNS
 *  None
 *****************************************************************************/
void stop_RGB2YUV420_data_path(void)
{    
#if defined(DRV_IDP_6228_SERIES)      
  stop_RGB2YUV420_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)      
  stop_RGB2YUV420_data_path_6238_series();
#endif  
}   

/*****************************************************************************
 * FUNCTION
 *  config_camera_capture_mem_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  capture_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_camera_capture_mem_data_path(
  MMDI_SCENERIO_ID scenario_id,
  camera_capture_mem_data_path_struct *capture_para)
{
#if defined(DRV_IDP_6228_SERIES)      
  config_camera_capture_mem_data_path_legacy_series(scenario_id,capture_para);
#elif defined(DRV_IDP_6238_SERIES)      
  config_camera_capture_mem_data_path_6238_series(scenario_id,capture_para);
#endif
}   /* config_camera_capture_memory_data_path() */
/*****************************************************************************
 * FUNCTION
 *  close_camera_capture_mem_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_camera_capture_mem_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)
  close_camera_capture_mem_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  close_camera_capture_mem_data_path_6238_series();
#endif
    
}   /* close_image_capture_mem_data_path() */

/*****************************************************************************
 * FUNCTION
 *  config_camera_preview_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  preview_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_camera_preview_data_path(MMDI_SCENERIO_ID scenario_id, camera_preview_data_path_struct *preview_para)
{
#if defined(DRV_IDP_6228_SERIES)      
  config_camera_preview_data_path_legacy_series(scenario_id,preview_para);
#elif defined(DRV_IDP_6238_SERIES)      
  config_camera_preview_data_path_6238_series(scenario_id,preview_para);
#endif    
  return 0;
}   /* config_camera_preview_data_path() */

/*****************************************************************************
 * FUNCTION
 *  reconfig_camera_preview_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  preview_para        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void reconfig_camera_preview_data_path(MMDI_SCENERIO_ID scenario_id, camera_preview_data_path_struct *preview_para)
{
#if defined(DRV_IDP_6228_SERIES)      
  reconfig_camera_preview_data_path_legacy_series(scenario_id,preview_para);
#elif defined(DRV_IDP_6238_SERIES)      
  reconfig_camera_preview_data_path_6238_series(scenario_id,preview_para);
#endif   
}   /* reconfig_camera_preview_data_path() */
/*****************************************************************************
 * FUNCTION
 *  close_camera_preview_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_camera_preview_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)      
  close_camera_preview_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)      
  close_camera_preview_data_path_6238_series();
#endif
}   /* close_camera_preview_data_path() */
/*****************************************************************************
 * FUNCTION
 *  config_camera_capture_jpeg_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  capture_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_camera_capture_jpeg_data_path(
  MMDI_SCENERIO_ID scenario_id,
  camera_capture_jpeg_data_path_struct *capture_para)
{
#if defined(DRV_IDP_6228_SERIES)      
  config_camera_capture_jpeg_data_path_legacy_series(scenario_id,capture_para);
#elif defined(DRV_IDP_6238_SERIES)      
  config_camera_capture_jpeg_data_path_6238_series(scenario_id,capture_para);
#endif  
}   /* config_camera_capture_jpeg_data_path() */
/*****************************************************************************
 * FUNCTION
 *  close_camera_capture_jpeg_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_camera_capture_jpeg_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)      
  close_camera_capture_jpeg_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)      
  close_camera_capture_jpeg_data_path_6238_series();
#endif  
}                                                       /* close_camera_capture_jpeg_data_path() */
/*****************************************************************************
 * FUNCTION
 *  config_camera_capture_barcode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  capture_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_camera_capture_barcode_data_path(MMDI_SCENERIO_ID scenario_id, camera_capture_barcode_data_path_struct *capture_para)
{

#if defined(DRV_IDP_6228_SERIES)      
  config_camera_capture_barcode_data_path_legacy_series(scenario_id, capture_para);
#elif defined(DRV_IDP_6238_SERIES)      
  config_camera_capture_barcode_data_path_6238_series(scenario_id, capture_para);
#endif  

  return 0;
}   /* config_camera_capture_barcode_data_path() */
/*****************************************************************************
 * FUNCTION
 *  get_barcode_image
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void get_barcode_image(void)
{
#if defined(DRV_IDP_6228_SERIES)      
  get_barcode_image_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)      
  get_barcode_image_6238_series();
#endif  
}
/*****************************************************************************
 * FUNCTION
 *  close_camera_capture_barcode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_camera_capture_barcode_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)      
  close_camera_capture_barcode_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)      
  close_camera_capture_barcode_data_path_6238_series();
#endif  
}   /* close_camera_capture_barcode_data_path() */

/*****************************************************************************
 * FUNCTION
 *  config_video_decode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 *  video_para      [?]
 *  lcd_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_video_decode_data_path(
  MMDI_SCENERIO_ID scenario_id,
  video_decode_data_path_struct *video_para,
  lcd_frame_update_struct *lcd_para)
{
#if (defined(DRV_IDP_6228_SERIES))
  config_video_decode_data_path_legacy_series(scenario_id, video_para, lcd_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_video_decode_data_path_6238_series(scenario_id, video_para, lcd_para);
#endif
}   /* config_video_decode_data_path() */
/*****************************************************************************
 * FUNCTION
 *  config_video_encode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 *  video_para      [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_video_encode_data_path(MMDI_SCENERIO_ID scenario_id, video_encode_data_path_struct *video_para)
{
#if (defined(DRV_IDP_6228_SERIES))
  config_video_encode_data_path_legacy_series(scenario_id, video_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_video_encode_data_path_6238_series(scenario_id, video_para);
#endif
}   /* config_video_encode_data_path() */

/*****************************************************************************
 * FUNCTION
 *  config_image_resize_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 *  resize_para     [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_image_resize_data_path(MMDI_SCENERIO_ID scenario_id, resize_struct *resize_para)
{
#if (defined(DRV_IDP_6228_SERIES))
  config_image_resize_data_path_legacy_series(scenario_id, resize_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_image_resize_data_path_6238_series(scenario_id, resize_para);
#endif
}   /* config_image_resize_data_path() */

/*****************************************************************************
 * FUNCTION
 *  reconfig_video_encode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 *  video_para      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void reconfig_purevideo_encode_data_path(MMDI_SCENERIO_ID scenario_id, video_encode_data_path_struct *video_para)
{
#if (defined(DRV_IDP_6228_SERIES))
  reconfig_purevideo_encode_data_path_legacy_series(scenario_id, video_para);
#elif defined(DRV_IDP_6238_SERIES)
  reconfig_purevideo_encode_data_path_6238_series(scenario_id, video_para);
#endif
}   /* reconfig_video_encode_data_path() */

void reconfig_video_encode_data_path(MMDI_SCENERIO_ID scenario_id, video_encode_data_path_struct *video_para)
{   
  kal_uint16 crz_out_width, crz_out_height;
 
  if (scenario_id == SCENARIO_MPEG_ENCODE_ID)
  {
    reconfig_purevideo_encode_data_path(scenario_id, video_para);
  }
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//__3G_VIDEO_CALL__
}   /* reconfig_video_encode_data_path() */

/*****************************************************************************
 * FUNCTION
 *  video_decode_display
 * DESCRIPTION
 *
 * PARAMETERS
 *  video_para      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void video_decode_display(video_decode_data_path_struct *video_para)
{   /* display video playback */
#if defined(DRV_IDP_6228_SERIES)
  video_decode_display_legacy_series(video_para);
#elif defined(DRV_IDP_6238_SERIES)
  video_decode_display_6238_series(video_para);
#endif
}   /* video_decode_display() */

/*****************************************************************************
 * FUNCTION
 *  config_filter_effect_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  ipp_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_filter_effect_data_path(ipp_effect_struct *ipp_para)
{
#if defined(DRV_IDP_6228_SERIES)
  config_filter_effect_data_path_legacy_series(ipp_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_filter_effect_data_path_6238_series(ipp_para);
#endif
}   /* config_filter_effect_data_path() */

/*****************************************************************************
 * FUNCTION
 *  config_pixel_effect_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  ipp_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_pixel_effect_data_path(ipp_effect_struct *ipp_para)
{
#if defined(DRV_IDP_6228_SERIES)
  config_pixel_effect_data_path_legacy_series(ipp_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_pixel_effect_data_path_6238_series(ipp_para);
#endif
}   /* config_pixel_effect_data_path() */

/*****************************************************************************
 * FUNCTION
 *  open_image_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool open_image_data_path(MMDI_SCENERIO_ID scenario_id)
{
#if defined(DRV_IDP_6228_SERIES)
  open_image_data_path_legacy_series(scenario_id);
#elif defined(DRV_IDP_6238_SERIES)
  open_image_data_path_6238_series(scenario_id);
#endif
}   /* open_image_data_path() */

/*****************************************************************************
 * FUNCTION
 *  close_image_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void close_image_data_path(MMDI_SCENERIO_ID scenario_id)
{
#if defined(DRV_IDP_6228_SERIES)
  close_image_data_path_legacy_series(scenario_id);
#elif defined(DRV_IDP_6238_SERIES)
  close_image_data_path_6238_series(scenario_id);
#endif
}   /* close_image_data_path() */

/*****************************************************************************
 * FUNCTION
 *  config_jpeg_encode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 *  jpeg_para       [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_jpeg_encode_data_path(MMDI_SCENERIO_ID scenario_id, jpeg_encode_process_struct *jpeg_para)
{
#if defined(DRV_IDP_6228_SERIES)
  config_jpeg_encode_data_path_legacy_series(scenario_id, jpeg_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_jpeg_encode_data_path_6238_series(scenario_id, jpeg_para);
#endif
}   /* config_jpeg_encode_data_path() */

/*****************************************************************************
 * FUNCTION
 *  close_jpeg_encode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_jpeg_encode_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)
  close_jpeg_encode_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  close_jpeg_encode_data_path_6238_series();
#endif
}                               

/*****************************************************************************
 * FUNCTION
 *  config_jpeg_decode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id     [IN]
 *  jpeg_para       [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_jpeg_decode_data_path(MMDI_SCENERIO_ID scenario_id, jpeg_decode_process_struct *jpeg_para)
{
#if defined(DRV_IDP_6228_SERIES)
  config_jpeg_decode_data_path_legacy_series(scenario_id, jpeg_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_jpeg_decode_data_path_6238_series(scenario_id, jpeg_para);
#endif
}   /* config_jpeg_decode_data_path() */

/*****************************************************************************
 * FUNCTION
 *  close_jpeg_decode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_jpeg_decode_data_path(void)
{
#if defined(DRV_IDP_6228_SERIES)
  close_jpeg_decode_data_path_legacy_series();
#elif defined(DRV_IDP_6238_SERIES)
  close_jpeg_decode_data_path_6238_series();
#endif
}                                                       /* close_jpeg_decode_data_path() */
/*****************************************************************************
 * FUNCTION
 *  config_camera_usbvideo_jpeg_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  capture_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_camera_usbvideo_jpeg_data_path(
  MMDI_SCENERIO_ID scenario_id,
  camera_capture_jpeg_data_path_struct *capture_para)
{
#if defined(DRV_IDP_6228_SERIES)
  config_camera_usbvideo_jpeg_data_path_legacy_series(scenario_id, capture_para);
#elif defined(DRV_IDP_6238_SERIES)
  config_camera_usbvideo_jpeg_data_path_6238_series(scenario_id, capture_para);
#endif
  return 0;
}   /* config_camera_usbvideo_jpeg_data_path() */
#endif
