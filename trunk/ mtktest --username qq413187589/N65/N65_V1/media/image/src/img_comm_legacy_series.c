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
 *   img_comm_legacy_series.c
 *
 * Project:
 * --------
 *   Before MT6238
 *
 * Description:
 * ------------
 *   legacy image data path
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"
#include "drv_comm.h"

#if (defined(DRV_IDP_6219_SERIES) || defined(DRV_IDP_6225_SERIES) || defined(DRV_IDP_6228_SERIES))

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

#if (defined(DRV_IDP_6228_SERIES))
#include "tv_out.h"
#include "upll_ctrl.h"
#endif /* defined(DRV_IDP_6228_SERIES) ) */

#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"
#endif

#if (defined(ISP_SUPPORT))
#include "ae_awb.h"
#endif

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
#include "SST_sla.h"
#endif

#ifdef __SYNC_LCM_SW_SUPPORT__
void (*sync_lcm_update_cb) (void);
kal_uint8 preview_frame_update_flag=KAL_FALSE;
kal_uint8 video_encode_update_flag=KAL_FALSE;
kal_uint8 video_encode_dc_flag=KAL_FALSE;
kal_uint8 video_decode_update_flag=KAL_FALSE;
kal_uint8 video_decode_direct_couple=KAL_FALSE;
kal_uint32 preview_layer_base_address;
kal_uint32 preview_buffer1_address;
kal_uint32 preview_buffer2_address;
kal_uint8 preview_frame_buffer_swap=0;
kal_uint32 video_frame_buffer_address;
extern kal_uint8 wait_lcd_restore_config_flag;
extern kal_uint8 wait_lcd_config_flag;

void sync_lcm_preview_update_cb(void)
{
   if ((!(LCD_IS_RUNNING))&&(preview_frame_update_flag==KAL_TRUE)&&(wait_lcd_config_flag==KAL_FALSE))
   {
      ENABLE_LCD_TRANSFER_COMPLETE_INT;
      START_LCD_TRANSFER;
      wait_lcd_restore_config_flag=KAL_FALSE;
   }
   preview_frame_update_flag=KAL_FALSE;
}  /* sync_lcm_preview_update_cb() */

void preview_frame_ready_cb(void)
{
   kal_uint32 savedMask;

   lcd_power_ctrl(KAL_TRUE);

   savedMask = SaveAndSetIRQMask();
   #if !defined(MT6225)&&!defined(MT6235)//XXXXXO, 6225 does it in resizer.c
   if (preview_frame_buffer_swap==0)
      *((volatile unsigned int *) preview_layer_base_address)=preview_buffer1_address;
   else if (preview_frame_buffer_swap==1)
      *((volatile unsigned int *) preview_layer_base_address)=preview_buffer2_address;

   preview_frame_buffer_swap++;
   preview_frame_buffer_swap&=0x01;
   #endif   
   preview_frame_update_flag=KAL_TRUE;
   RestoreIRQMask(savedMask);
}  /* preview_frame_ready_cb()*/

void video_encode_frame_ready_cb(void)
{
}  /* video_encode_frame_ready_cb() */

void sync_lcm_video_encode_update_cb(void)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
#if (defined(DRV_IDP_6228_SERIES))
    if ((vid_enc_r_cb!=NULL) && (video_encode_update_flag==KAL_TRUE))
    {
        mpeg4_vid_enc_r_cb(KAL_TRUE);     // direct couple
    }
    else
    {                   // hardware trigger
        if ((!(LCD_IS_RUNNING))&&(video_encode_update_flag==KAL_TRUE)&&(wait_lcd_config_flag==KAL_FALSE))
        {
            ENABLE_LCD_TRANSFER_COMPLETE_INT;
            START_LCD_TRANSFER;
        }
    }
#elif (defined(MT6226)||defined(MT6227)||defined(MT6227D)||defined(MT6226D)||defined(MT6226M))
    if ((!(LCD_IS_RUNNING))&&(video_encode_update_flag==KAL_TRUE)&&(wait_lcd_config_flag==KAL_FALSE))
    {
        ENABLE_LCD_TRANSFER_COMPLETE_INT;
        START_LCD_TRANSFER;
    }
#endif
    video_encode_update_flag=KAL_FALSE;
   RestoreIRQMask(savedMask);
}  /* sync_lcm_video_encode_update_cb() */

void video_decode_ibw2_cb(void)
{
    video_decode_update_flag=KAL_TRUE;
}  /* video_decode_ibw2_cb() */

void sync_lcm_video_decode_update_cb(void)
{
#if (defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D))
    kal_uint32 savedMask;

    if (video_decode_direct_couple==KAL_TRUE)
    {
        if ((!(LCD_IS_RUNNING))&&(video_decode_update_flag==KAL_TRUE))
        {
            savedMask = SaveAndSetIRQMask();
            IMGDMA_Stop(IMGDMA_VDO_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Stop(IMGDMA_IBW2_CH, IMGDMA_STOP_NOW, NULL, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_VdoSetBS1(video_frame_buffer_address, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Start(IMGDMA_IBW2_CH, SCENARIO_MPEG_DECODE_ID);
            IMGDMA_Start(IMGDMA_VDO_CH, SCENARIO_MPEG_DECODE_ID);
            RestoreIRQMask(savedMask);
        }
    }
    else
    {
        if ((!(LCD_IS_RUNNING))&&(video_decode_update_flag==KAL_TRUE))
        {
            ENABLE_LCD_TRANSFER_COMPLETE_INT;
            START_LCD_TRANSFER;
        }
    }
#elif (defined(DRV_IDP_6228_SERIES))
    if (video_decode_direct_couple==KAL_TRUE)
    {
        if ((!(LCD_IS_RUNNING))&&(video_decode_update_flag==KAL_TRUE))
        {
            START_IBW2;
            START_IMGDMA_VIDEO_DECODE;
         }
    }
    else
    {
        if ((!(LCD_IS_RUNNING))&&(video_decode_update_flag==KAL_TRUE))
        {
            ENABLE_LCD_TRANSFER_COMPLETE_INT;
            START_LCD_TRANSFER;
        }
    }
#endif
    video_decode_update_flag=KAL_FALSE;
}  /* sync_lcm_video_encode_update_cb() */

#endif

#if defined(DRV_IDP_6228_SERIES)
/*****************************************************************************
 * FUNCTION
 *  preview_vid_enc_w_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void preview_vid_enc_w_cb(void)
{
    #ifdef TV_OUT_SUPPORT
    if (tv_output_owner == TV_OUT_OWNER_VID_DMA_W)
    {
        if (tv_out_current_fb == 0)
            tv_fb_update(TV_OUT_OWNER_VID_DMA_W, camera_preview_config_data.tv_output_buffer1_address);
        else
            tv_fb_update(TV_OUT_OWNER_VID_DMA_W, camera_preview_config_data.tv_output_buffer2_address);
        tv_out_current_fb++;
        tv_out_current_fb &= 0x01;
    }
    #endif/*#ifdef TV_OUT_SUPPORT */
}   /* preview_vid_enc_w_cb() */
kal_uint8 config_jpeg_encode_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, jpeg_encode_process_struct *jpeg_para)
{
    IMGDMA_IBW1_STRUCT ibw1_struct;
    IMGDMA_IBR1_STRUCT ibr1_struct;
    IMGDMA_IBW3_STRUCT ibw3_struct;
    IMGDMA_IBR2_STRUCT ibr2_struct;
    IMGDMA_JPEG_DMA_STRUCT jpeg_dma_struct;
   RESZ_DRZ_STRUCT drz_struct;
   RESZ_PRZ_STRUCT  prz_struct;

    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if ((scenario_id != SCENARIO_JPEG_ENCODE_ID) && (scenario_id != SCENARIO_MPEG_SNAPSHOT_ID))
    {
        ASSERT(0);
    }

    if (scenario_id == SCENARIO_JPEG_ENCODE_ID)
    {
        intmem_init((kal_uint32*) jpeg_para->intmem_start_address, jpeg_para->intmem_size);
        extmem_init((kal_uint32*) jpeg_para->extmem_start_address, jpeg_para->extmem_size);
    }

    /* HW issue of jpeg encode dma */
    if (jpeg_para->target_height & 0x0f)
    {
        jpeg_para->jpeg_yuv_mode = JPEG_FORMAT_YUV422;
    }

    /* XXXXXO config IBR1 */
    ibr1_struct.base_addr = jpeg_para->image_buffer_address;
    ibr1_struct.pixel_number = (jpeg_para->image_width * jpeg_para->image_height - 1);
    ibr1_struct.data_type = jpeg_para->type;
    ibr1_struct.data_order = jpeg_para->data_order;
    ibr1_struct.int_en = KAL_FALSE;

    IMGDMA_IBR1Config(&ibr1_struct);
    /* config IPP */
    RESET_IPP;
    ENABLE_IPP;
    DISABLE_IPP_INT;
    IPP_CTRL_REG = 0;
    SET_IPP_GRAPH_MODE(IPP_IMAGE_ENCODE_MODE);
    SET_IPP_R2Y_SRC_IMGDMA;

   /*XXXXX config PRZ */
   prz_struct.image_src=RESZ_SOURCE_IPP;
   prz_struct.dedicate_memory=KAL_TRUE;
   prz_struct.continous=KAL_FALSE;
   prz_struct.int_en=KAL_FALSE;
   prz_struct.output_2_IPP=KAL_FALSE;
   prz_struct.coarse_en=KAL_FALSE;
   prz_struct.src_height=jpeg_para->image_height;
   prz_struct.src_width=jpeg_para->image_width;
   prz_struct.tar_height=jpeg_para->target_height;
   prz_struct.tar_width=jpeg_para->target_width;
   prz_struct.work_mem_line=4;
   //prz_struct.work_mem_addr=(kal_uint32) extmem_get_buffer((video_para->display_width * RESIZER_WORKING_MEM_LINE_NUMBER *3));
   RESZ_PRZConfig(&prz_struct);

    /* XXXXXO config IBR2 */
    ibr2_struct.restart = KAL_FALSE;
    ibr2_struct.int_en = KAL_FALSE;
    ibr2_struct.pixel_engine = PIXEL_ENGINE_PRZ;
    if (jpeg_para->overlay_frame_mode == KAL_TRUE)
    {
        ibr2_struct.overlay_frame_mode = KAL_TRUE;
        ibr2_struct.overlay_frame_buffer_address = jpeg_para->overlay_frame_buffer_address;
        ibr2_struct.overlay_frame_width = jpeg_para->overlay_frame_width;
        ibr2_struct.overlay_frame_height = jpeg_para->overlay_frame_height;
        ibr2_struct.overlay_frame_target_width = jpeg_para->target_width;
        ibr2_struct.overlay_frame_target_height = jpeg_para->target_height;
        ibr2_struct.overlay_color_depth = jpeg_para->overlay_color_depth;
        ibr2_struct.overlay_frame_source_key = jpeg_para->overlay_frame_source_key;
    }
    else
    {
        ibr2_struct.overlay_frame_mode = KAL_FALSE;
    }
    IMGDMA_IBR2Config(&ibr2_struct);


    if (jpeg_para->thumbnail_mode == KAL_TRUE)
    {
        /* XXXXXO config IBW3 */
        ibw3_struct.pixel_engine = PIXEL_ENGINE_PRZ;
        ibw3_struct.auto_restart = KAL_FALSE;
        ibw3_struct.int_en = KAL_FALSE;
        ibw3_struct.width = jpeg_para->target_width - 1;
        ibw3_struct.height = jpeg_para->target_height - 1;
        IMGDMA_IBW3Config(&ibw3_struct);

      /*XXXXX config DRZ */
      drz_struct.image_src=RESZ_SOURCE_IBW3;
      drz_struct.auto_restart=KAL_FALSE;
      drz_struct.int_en=KAL_FALSE;
      drz_struct.src_height=jpeg_para->target_height;
      drz_struct.src_width=jpeg_para->target_width;
      drz_struct.tar_height=jpeg_para->thumbnail_height;
      drz_struct.tar_width=jpeg_para->thumbnail_width;

      RESZ_DRZConfig(&drz_struct);

        /* config IPP2 */
        ENABLE_THUMBNAIL_OUTPUT;

        /* XXXXXO config IBW1 */
        ibw1_struct.pixel_engine = PIXEL_ENGINE_IPP2;
        ibw1_struct.output_format = SET_IBW1_OUTPUT_RGB888;
        ibw1_struct.auto_restart = KAL_FALSE;
        ibw1_struct.bs = (jpeg_para->jpeg_file_start_address + 20);
        ibw1_struct.width = (jpeg_para->thumbnail_width - 1);
        ibw1_struct.height = (jpeg_para->thumbnail_height - 1);
        IMGDMA_IBW1Config(&ibw1_struct);
    }
    /* XXXXXO config JPEG DMA */
    jpeg_dma_struct.pixel_engine = PIXEL_ENGINE_PRZ;
    jpeg_dma_struct.jpeg_yuv_mode = jpeg_para->jpeg_yuv_mode;

    if (scenario_id == SCENARIO_JPEG_ENCODE_ID)
    {
        jpeg_dma_struct.jpeg_file_buffer_address =
            (kal_uint32)
            extmem_get_buffer((JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER * ((jpeg_para->target_width & 0xFFF0) + 16)) << 1);
    }
#if (defined(MP4_CODEC))
    else
    {   /* get memory from MPEG4 interface because the memory is occupied by MPEG4 decoder */
        jpeg_dma_struct.jpeg_file_buffer_address = video_dec_get_snapshot_imgdma_mem();
        if (jpeg_dma_struct.jpeg_file_buffer_address == 0)
        {
            jpeg_dma_struct.jpeg_file_buffer_address =
                (kal_uint32)
                extmem_get_buffer((JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER *
                                   ((jpeg_para->target_width & 0xFFF0) + 16)) << 1);
            video_dec_set_snapshot_imgdma_mem(jpeg_dma_struct.jpeg_file_buffer_address);
        }
    }
#endif /* (defined(MP4_CODEC)) */
    jpeg_dma_struct.restart = KAL_FALSE;
    jpeg_dma_struct.target_width = jpeg_para->target_width;
    jpeg_dma_struct.target_height = jpeg_para->target_height;

    IMGDMA_JPEGDMAConfig(&jpeg_dma_struct);

    config_jpeg_encode_path(jpeg_para);
    START_IBR1;
    return 0;
}   /* config_jpeg_encode_data_path() */

kal_uint8 config_jpeg_decode_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, jpeg_decode_process_struct *jpeg_para)
{
    kal_uint16 target_width, target_height;
    kal_uint32 target_buffer_size;
    kal_uint16 display_width = 0, display_height = 0;
    kal_uint16 src_width, src_height, image_width, image_height;
    kal_uint16 max_prz_width = 0, max_prz_height = 0;
    kal_uint8 dummy_pixel, dummy_line;
    kal_uint32 jpeg_decode_int_mem_size = 0, address_offset = 0;
    IMGDMA_IBW3_STRUCT ibw3_struct;
    IMGDMA_IBR2_STRUCT ibr2_struct;
    IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
    IMGDMA_IBW2_STRUCT ibw2_struct;
    RESZ_DRZ_STRUCT drz_struct;
    RESZ_PRZ_STRUCT  prz_struct;
    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_JPEG_DECODE_ID)
    {
        ASSERT(0);
    }
    /* configure PRZ */
    intmem_init((kal_uint32*) jpeg_para->intmem_start_address, jpeg_para->intmem_size);
    extmem_init((kal_uint32*) jpeg_para->extmem_start_address, jpeg_para->extmem_size);

    target_buffer_size = jpeg_para->image_buffer_size;
    if (jpeg_para->memory_output == KAL_FALSE)
    {
        display_width = jpeg_para->image_width;
        display_height = jpeg_para->image_height;
        max_prz_width = jpeg_para->image_width << 1;
        max_prz_height = jpeg_para->image_height << 1;
    }
    else if (jpeg_para->memory_output == KAL_TRUE)
    {
        display_width = jpeg_para->memory_output_width;
        display_height = jpeg_para->memory_output_height;
        max_prz_width = jpeg_para->memory_output_width << 1;
        max_prz_height = jpeg_para->memory_output_height << 1;
    }

    src_width = jpeg_file_para.jpg_decode_width;
    src_height = jpeg_file_para.jpg_decode_height;
    image_width = jpeg_file_para.jpg_width;
    image_height = jpeg_file_para.jpg_height;
    dummy_pixel = src_width - image_width;
    dummy_line = src_height - image_height;

    if (jpeg_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB565)
    {
        if ((((jpeg_para->image_clip_x2 - jpeg_para->image_clip_x1 + 1) *
              (jpeg_para->image_clip_y2 - jpeg_para->image_clip_y1 + 1)) << 1) > target_buffer_size)
        {
            return (JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH);
        }
    }
    else if (jpeg_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB888)
    {
        if ((((jpeg_para->image_clip_x2 - jpeg_para->image_clip_x1 + 1) *
              (jpeg_para->image_clip_y2 - jpeg_para->image_clip_y1 + 1)) * 3) > target_buffer_size)
        {
            return (JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH);
        }
    }

    if ((image_width != src_width) && (display_width != image_width))
    {
        target_width = (src_width * display_width / image_width) + 1;
    }
    else
    {
        target_width = src_width * display_width / image_width;
    }
    if ((image_height != src_height) && (display_height != image_height))
    {
        target_height = (src_height * display_height / image_height) + 1;
    }
    else
    {
        target_height = (src_height * display_height / image_height);
    }
    if ((target_width == 0) && (target_height == 0))
    {
        target_width = src_width;
        target_height = src_height;
    }

    dummy_pixel = (target_width * dummy_pixel) / src_width;
    dummy_line = (target_height * dummy_line) / src_height;

    if (jpeg_para->memory_output == KAL_TRUE)
    {
        if (jpeg_para->memory_output_buffer_size < ((target_width * target_height * 3) >> 1))
        {
            return (JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH);
        }
    }

   /*XXXXX config PRZ */

    prz_struct.image_src=RESZ_SOURCE_JPEG_DECODER;
    prz_struct.dedicate_memory=KAL_TRUE;
    prz_struct.continous=KAL_FALSE;
    prz_struct.int_en=KAL_FALSE;
    if (jpeg_para->memory_output == KAL_FALSE)
      prz_struct.output_2_IPP=KAL_TRUE;
    else
      prz_struct.output_2_IPP=KAL_FALSE;

   prz_struct.work_mem_line=RESIZER_WORKING_MEM_LINE_NUMBER;
   
   prz_struct.coarse_en=KAL_TRUE;
   
   if ((src_width < 2048) && (src_height < 2048))
   {
     prz_struct.coarse_ratio=BLOCK_CS_1_1;
   }
   else if (((src_width / 2) < 2048) && ((src_height / 2) < 2048))
   {
     prz_struct.coarse_ratio=BLOCK_CS_1_4;
     src_width >>= 1;
     src_height >>= 1;
   }
   else if (((src_width / 4) < 2048) && ((src_height / 4) < 2048))
   {
     prz_struct.coarse_ratio=BLOCK_CS_1_16;
     src_width >>= 2;
     src_height >>= 2;
   }
   else if (((src_width / 8) < 2048) && ((src_height / 8) < 2048))
   {
     prz_struct.coarse_ratio=BLOCK_CS_1_64;
     src_width >>= 3;
     src_height >>= 3;
   }
   
   if (src_width>2048)
      return (JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL);
   if (src_height>2048)
      return (JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL);
   if (target_width>2048)
      return (JPEG_DECODE_TARGET_WIDTH_TOO_LARGE_FAIL);
   if (target_height>2048)
      return (JPEG_DECODE_TARGET_HEIGHT_TOO_LARGE_FAIL);

   prz_struct.src_height=src_height;
   prz_struct.src_width=src_width;
   prz_struct.tar_height=target_height;
   prz_struct.tar_width=target_width;

   prz_struct.y_h_factor=jpeg_file_para.y_h_sample_factor;
   prz_struct.y_v_factor=jpeg_file_para.y_v_sample_factor;
    if (jpeg_file_para.number_of_component == 1)
    {
       /*No U, V component*/
       prz_struct.u_h_factor=6;
       prz_struct.u_v_factor=6;
       prz_struct.v_h_factor=6;
       prz_struct.v_v_factor=6;
    }
    else if (jpeg_file_para.number_of_component == 3)
    {
       /*No U, V component*/
       prz_struct.u_h_factor=jpeg_file_para.u_h_sample_factor;
       prz_struct.u_v_factor=jpeg_file_para.u_v_sample_factor;
       prz_struct.v_h_factor=jpeg_file_para.v_h_sample_factor;
       prz_struct.v_v_factor=jpeg_file_para.v_v_sample_factor;
    }

    if ((target_width > src_width) || (target_height > src_height))
    {
       jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.y_v_sample_factor<<3)+jpeg_file_para.y_v_sample_factor)) & 0xFFFFFFFC)+4);
       jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.u_v_sample_factor<<3)+jpeg_file_para.u_v_sample_factor)) & 0xFFFFFFFC)+4);
       jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.v_v_sample_factor<<3)+jpeg_file_para.v_v_sample_factor)) & 0xFFFFFFFC)+4);

       if (jpeg_decode_int_mem_size > jpeg_para->intmem_size)
       {
           return (JPEG_DECODE_INT_BUFFER_NOT_ENOUGH);
       }

       prz_struct.y_line_buff_addr=(kal_uint32) intmem_get_buffer((src_width * ((jpeg_file_para.y_v_sample_factor<<3)+jpeg_file_para.y_v_sample_factor)));
       prz_struct.u_line_buff_addr=(kal_uint32) intmem_get_buffer((src_width * ((jpeg_file_para.u_v_sample_factor<<3)+jpeg_file_para.u_v_sample_factor)));
       prz_struct.v_line_buff_addr=(kal_uint32) intmem_get_buffer((src_width * ((jpeg_file_para.v_v_sample_factor<<3)+jpeg_file_para.v_v_sample_factor)));
       prz_struct.y_line_buff_size=((jpeg_file_para.y_v_sample_factor<<3)+jpeg_file_para.y_v_sample_factor);
    }
    else
    {
       jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.y_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
       jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.u_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
       jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.v_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);

       if (jpeg_decode_int_mem_size > jpeg_para->intmem_size)
       {
           return (JPEG_DECODE_INT_BUFFER_NOT_ENOUGH);
       }

       prz_struct.y_line_buff_addr=(kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.y_v_sample_factor<<3)));
       prz_struct.u_line_buff_addr=(kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.u_v_sample_factor<<3)));
       prz_struct.v_line_buff_addr=(kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.v_v_sample_factor<<3)));
       prz_struct.y_line_buff_size=((jpeg_file_para.y_v_sample_factor<<3));
    }

   RESZ_PRZConfig(&prz_struct);

    /* hw issue of prz src switch */
    RESET_PRZ;
    ENABLE_PRZ;

    if (jpeg_para->memory_output == KAL_FALSE)
    {
        /* config IPP1 */
        RESET_IPP;
        ENABLE_IPP;
        IPP_CTRL_REG = 0;
        SET_IPP_GRAPH_MODE(IPP_PREVIEW_PLAYBACK_MODE);

        /* XXXXXO config IBW2 */
        if (jpeg_para->image_pitch_mode == KAL_TRUE)
        {
            ibw2_struct.pitch = KAL_TRUE;
            ibw2_struct.pitch1_bytes = jpeg_para->image_pitch_bytes;
            ibw2_struct.pitch2_bytes = jpeg_para->image_pitch_bytes;

            address_offset = jpeg_para->image_pitch_bytes * jpeg_para->image_clip_y1;
        }
        else
        {
            ibw2_struct.pitch = KAL_FALSE;
            if (jpeg_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB565)
            {
                address_offset = target_width * 2 * jpeg_para->image_clip_y1;
            }
            else if (jpeg_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB888)
            {
                address_offset = target_width * 3 * jpeg_para->image_clip_y1;
            }
        }

        if (address_offset > jpeg_para->image_buffer_address)
        {
            ASSERT(0);
        }

        ibw2_struct.dest_color_mode = jpeg_para->image_data_format;
        ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;
        ibw2_struct.lcd_trigger = KAL_FALSE;
        ibw2_struct.direct_couple = KAL_FALSE;
        ibw2_struct.int_en = KAL_TRUE;
        ibw2_struct.pan = KAL_TRUE;
        ibw2_struct.restart = KAL_FALSE;

        ibw2_struct.frame1_base_addr = jpeg_para->image_buffer_address - address_offset;
        ibw2_struct.frame2_base_addr = jpeg_para->image_buffer_address - address_offset;
        ibw2_struct.width = target_width;
        ibw2_struct.height = target_height;
        ibw2_struct.clip_left = jpeg_para->image_clip_x1;
        ibw2_struct.clip_right = jpeg_para->image_clip_x2;
        ibw2_struct.clip_top = jpeg_para->image_clip_y1;
        ibw2_struct.clip_bottom = jpeg_para->image_clip_y2;
        ibw2_struct.enable_IBW2 = KAL_TRUE;
        ibw2_struct.cb = jpeg_decode_cb;

        IMGDMA_IBW2Config(&ibw2_struct);

    }
    else
    {
       display_width = jpeg_para->image_width;
       display_height = jpeg_para->image_height;
       src_width = target_width;
       src_height = target_height;
       target_width = display_width * src_width / (src_width - dummy_pixel);
       target_height = display_height * src_height / (src_height - dummy_line);
       /* XXXXXO config IBR2 */
       ibr2_struct.restart = KAL_FALSE;
       ibr2_struct.int_en = KAL_FALSE;
       ibr2_struct.pixel_engine = PIXEL_ENGINE_PRZ;
       ibr2_struct.overlay_frame_mode = KAL_FALSE;

       IMGDMA_IBR2Config(&ibr2_struct);

          /* config IPP1 and IPP2 */
       RESET_IPP;
       ENABLE_IPP;
       IPP_CTRL_REG = 0;
       SET_IPP_GRAPH_MODE(IPP_CAPTURE_MODE);

       /* XXXXXO config IBW3 */
       ibw3_struct.pixel_engine = PIXEL_ENGINE_PRZ;
       ibw3_struct.auto_restart = KAL_FALSE;
       ibw3_struct.int_en = KAL_FALSE;
       ibw3_struct.width = src_width - 1;
       ibw3_struct.height = src_height - 1;
       IMGDMA_IBW3Config(&ibw3_struct);

       /*XXXXX config DRZ */
       drz_struct.image_src=RESZ_SOURCE_IBW3;
       drz_struct.auto_restart=KAL_FALSE;
       drz_struct.int_en=KAL_TRUE;
       drz_struct.src_height=src_height;
       drz_struct.src_width=src_width;
       drz_struct.tar_height=target_height;
       drz_struct.tar_width=target_width;

       RESZ_DRZConfig(&drz_struct);

       /* config IPP2 */
       ENABLE_THUMBNAIL_OUTPUT;

       /* XXXXXO config IBW2 */

       if (jpeg_para->image_pitch_mode == KAL_TRUE)
       {
           ibw2_struct.pitch = KAL_TRUE;
           ibw2_struct.pitch1_bytes = jpeg_para->image_pitch_bytes;
           ibw2_struct.pitch2_bytes = jpeg_para->image_pitch_bytes;

           address_offset = jpeg_para->image_pitch_bytes * jpeg_para->image_clip_y1;
       }
       else
       {
           ibw2_struct.pitch = KAL_FALSE;
           if (jpeg_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB565)
           {
               address_offset = target_width * 2 * jpeg_para->image_clip_y1;
           }
           else if (jpeg_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB888)
           {
               address_offset = target_width * 3 * jpeg_para->image_clip_y1;
           }
       }

       if (address_offset > jpeg_para->image_buffer_address)
       {
           ASSERT(0);
       }

       ibw2_struct.dest_color_mode = jpeg_para->image_data_format;
       ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP2;
       ibw2_struct.lcd_trigger = KAL_FALSE;
       ibw2_struct.direct_couple = KAL_FALSE;
       ibw2_struct.int_en = KAL_TRUE;
       ibw2_struct.pan = KAL_TRUE;
       ibw2_struct.restart = KAL_FALSE;

       ibw2_struct.frame1_base_addr = jpeg_para->image_buffer_address - address_offset;
       ibw2_struct.width = target_width;
       ibw2_struct.height = target_height;
       ibw2_struct.clip_left = jpeg_para->image_clip_x1;
       ibw2_struct.clip_right = jpeg_para->image_clip_x2;
       ibw2_struct.clip_top = jpeg_para->image_clip_y1;
       ibw2_struct.clip_bottom = jpeg_para->image_clip_y2;
       ibw2_struct.enable_IBW2 = KAL_TRUE;
       ibw2_struct.cb = jpeg_decode_cb;

       IMGDMA_IBW2Config(&ibw2_struct);
         /* only YUV output is supported for TV output buffer */
       /* XXXXXO config video encode DMA write */

       video_encode_dma_struct.wdma_pixel_engine = PIXEL_ENGINE_PRZ;
       video_encode_dma_struct.rdma_destination_engine = PIXEL_ENGINE_NONE;
       video_encode_dma_struct.restart = KAL_FALSE;
       video_encode_dma_struct.w_trigger_r = KAL_FALSE;

       video_encode_dma_struct.read_done_int = KAL_FALSE;
       video_encode_dma_struct.wrtie_done_int = KAL_FALSE;

       video_encode_dma_struct.y_base_addr1 = (kal_uint32) jpeg_para->memory_output_buffer_address;
       video_encode_dma_struct.u_base_addr1 = (kal_uint32) jpeg_para->memory_output_buffer_address +
           src_width * src_height;
       video_encode_dma_struct.v_base_addr1 = (kal_uint32) jpeg_para->memory_output_buffer_address +
           ((src_width * src_height * 5) >> 2);

       video_encode_dma_struct.encode_width = src_width;
       video_encode_dma_struct.encode_height = src_height;

       IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);
    }
    return 0;
}   /* config_jpeg_decode_data_path() */

kal_uint8 config_jpeg_resize_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, jpeg_file_resize_struct *jpeg_para)
{
    kal_uint16 target_width, target_height;
    kal_uint32 jpeg_decode_ext_mem_size = 0;
    kal_uint16 src_width, src_height, image_width, image_height;
    kal_uint8 dummy_pixel, dummy_line;
    IMGDMA_IBW1_STRUCT ibw1_struct;
    IMGDMA_IBW3_STRUCT ibw3_struct;
    IMGDMA_IBR2_STRUCT ibr2_struct;
    IMGDMA_JPEG_DMA_STRUCT jpeg_dma_struct;
   RESZ_DRZ_STRUCT drz_struct;
   RESZ_PRZ_STRUCT prz_struct;
    kal_uint8 thumbnail_ratio_w, thumbnail_ratio_h;

    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_JPEG_RESIZE_ID)
    {
        ASSERT(0);
    }

    if (jpeg_para->target_width * jpeg_para->target_height >= 1300000)
    {
        jpeg_para->thumbnail_mode = KAL_TRUE;
        /* make sure the thumbnail size < 160*160 */
        if ((jpeg_para->target_width % 160) == 0)
        {
            thumbnail_ratio_w = jpeg_para->target_width / 160;
        }
        else
        {
            thumbnail_ratio_w = jpeg_para->target_width / 160 + 1;
        }
        if ((jpeg_para->target_height % 120) == 0)
        {
            thumbnail_ratio_h = jpeg_para->target_height / 120;
        }
        else
        {
            thumbnail_ratio_h = jpeg_para->target_height / 120 + 1;
        }
        if (thumbnail_ratio_w < thumbnail_ratio_h)
        {
            thumbnail_ratio_w = thumbnail_ratio_h;
        }
        jpeg_para->thumbnail_width = jpeg_para->target_width / thumbnail_ratio_w;
        jpeg_para->thumbnail_height = jpeg_para->target_height / thumbnail_ratio_w;
    }
    else
    {
        jpeg_para->thumbnail_mode = KAL_FALSE;
    }

    intmem_init((kal_uint32*) jpeg_para->intmem_start_address, jpeg_para->intmem_size);
    extmem_init((kal_uint32*) jpeg_para->extmem_start_address, jpeg_para->extmem_size);

    src_width = jpeg_file_para.jpg_decode_width;
    src_height = jpeg_file_para.jpg_decode_height;
    image_width = jpeg_file_para.jpg_width;
    image_height = jpeg_file_para.jpg_height;
    dummy_pixel = src_width - image_width;
    dummy_line = src_height - image_height;

    if ((image_width != src_width) && (jpeg_para->target_width != image_width))
    {
        target_width = (src_width * jpeg_para->target_width / image_width) + 1;
    }
    else
    {
        target_width = src_width * jpeg_para->target_width / image_width;
    }

    if ((image_height != src_height) && (jpeg_para->target_height != image_height))
    {
        target_height = (src_height * jpeg_para->target_height / image_height) + 1;
    }
    else
    {
        target_height = (src_height * jpeg_para->target_height / image_height);
    }
    if ((target_width == 0) && (target_height == 0))
    {
        target_width = src_width;
        target_height = src_height;
    }

    dummy_pixel = (target_width * dummy_pixel) / src_width;
    dummy_line = (target_height * dummy_line) / src_height;

   /*XXXXX config PRZ */
   prz_struct.image_src=RESZ_SOURCE_JPEG_DECODER;
   prz_struct.dedicate_memory=KAL_TRUE;
   prz_struct.continous=KAL_FALSE;
   prz_struct.int_en=KAL_FALSE;
   prz_struct.output_2_IPP=KAL_FALSE;
   prz_struct.src_height=src_height;
   prz_struct.src_width=src_width;
   prz_struct.tar_height=jpeg_para->target_height;
   prz_struct.tar_width=jpeg_para->target_width;
   prz_struct.work_mem_line=RESIZER_WORKING_MEM_LINE_NUMBER;

   prz_struct.coarse_en=KAL_TRUE;

   prz_struct.coarse_ratio=BLOCK_CS_1_1;
   prz_struct.y_h_factor=jpeg_file_para.y_h_sample_factor;
   prz_struct.y_v_factor=jpeg_file_para.y_v_sample_factor;
   if (jpeg_file_para.number_of_component == 1)
   {
      /*No U, V component*/
      prz_struct.u_h_factor=6;
      prz_struct.u_v_factor=6;
      prz_struct.v_h_factor=6;
      prz_struct.v_v_factor=6;
   }
   else if (jpeg_file_para.number_of_component == 3)
   {
      prz_struct.u_h_factor=jpeg_file_para.u_h_sample_factor;
      prz_struct.u_v_factor=jpeg_file_para.u_v_sample_factor;
      prz_struct.v_h_factor=jpeg_file_para.v_h_sample_factor;
      prz_struct.v_v_factor=jpeg_file_para.v_v_sample_factor;
   }

   jpeg_decode_ext_mem_size += (((src_width * (jpeg_file_para.y_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
   jpeg_decode_ext_mem_size += (((src_width * (jpeg_file_para.u_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
   jpeg_decode_ext_mem_size += (((src_width * (jpeg_file_para.v_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);

   if (jpeg_decode_ext_mem_size > jpeg_para->extmem_size)
   {
       return (JPEG_DECODE_INT_BUFFER_NOT_ENOUGH);
   }

   if ((target_width > src_width) || (target_height > src_height))
   {
      prz_struct.y_line_buff_addr=(kal_uint32) extmem_get_buffer((src_width * ((jpeg_file_para.y_v_sample_factor<<3)+jpeg_file_para.y_v_sample_factor)));
      prz_struct.u_line_buff_addr=(kal_uint32) extmem_get_buffer((src_width * ((jpeg_file_para.u_v_sample_factor<<3)+jpeg_file_para.u_v_sample_factor)));
      prz_struct.v_line_buff_addr=(kal_uint32) extmem_get_buffer((src_width * ((jpeg_file_para.v_v_sample_factor<<3)+jpeg_file_para.v_v_sample_factor)));
      prz_struct.y_line_buff_size=((jpeg_file_para.y_v_sample_factor<<3)+jpeg_file_para.y_v_sample_factor);
   }
   else
   {
      prz_struct.y_line_buff_addr=(kal_uint32) extmem_get_buffer((src_width *(jpeg_file_para.y_v_sample_factor<<3)));
      prz_struct.u_line_buff_addr=(kal_uint32) extmem_get_buffer((src_width * (jpeg_file_para.u_v_sample_factor<<3)));
      prz_struct.v_line_buff_addr=(kal_uint32) extmem_get_buffer((src_width * (jpeg_file_para.v_v_sample_factor<<3)));
      prz_struct.y_line_buff_size=((jpeg_file_para.y_v_sample_factor<<3));
   }
   RESZ_PRZConfig(&prz_struct);

    src_width = jpeg_para->target_width;
    src_height = jpeg_para->target_height;

    /* XXXXXO config IBR2 */
    ibr2_struct.restart = KAL_FALSE;
    ibr2_struct.int_en = KAL_FALSE;
    ibr2_struct.pixel_engine = PIXEL_ENGINE_PRZ;

    if (jpeg_para->overlay_frame_mode == KAL_TRUE)
    {
        ibr2_struct.overlay_frame_mode = KAL_TRUE;
        ibr2_struct.overlay_frame_buffer_address = jpeg_para->overlay_frame_buffer_address;
        ibr2_struct.overlay_frame_width = jpeg_para->overlay_frame_width;
        ibr2_struct.overlay_frame_height = jpeg_para->overlay_frame_height;
        ibr2_struct.overlay_frame_target_width = jpeg_para->target_width;
        ibr2_struct.overlay_frame_target_height = jpeg_para->target_height;
        ibr2_struct.overlay_color_depth = jpeg_para->overlay_color_depth;
        ibr2_struct.overlay_frame_source_key = jpeg_para->overlay_frame_source_key;
    }
    else
    {
        ibr2_struct.overlay_frame_mode = KAL_FALSE;
    }
    IMGDMA_IBR2Config(&ibr2_struct);
    if (jpeg_para->thumbnail_mode == KAL_TRUE)
    {
        /* XXXXXO config IBW3 */
        ibw3_struct.pixel_engine = PIXEL_ENGINE_PRZ;
        ibw3_struct.auto_restart = KAL_FALSE;
        ibw3_struct.int_en = KAL_FALSE;
        ibw3_struct.width = target_width - 1;
        ibw3_struct.height = target_height - 1;
        IMGDMA_IBW3Config(&ibw3_struct);
        /*XXXXX config DRZ */
        drz_struct.image_src=RESZ_SOURCE_IBW3;
        drz_struct.auto_restart=KAL_FALSE;
        drz_struct.int_en=KAL_FALSE;
        drz_struct.src_height=target_height;
        drz_struct.src_width=target_width;
        drz_struct.tar_height=jpeg_para->thumbnail_height;
        drz_struct.tar_width=jpeg_para->thumbnail_width;

        RESZ_DRZConfig(&drz_struct);
        /* config IPP2 */
        RESET_IPP;
        ENABLE_IPP;
        IPP_CTRL_REG = 0;
        SET_IPP_GRAPH_MODE(IPP_CAPTURE_MODE);
        ENABLE_THUMBNAIL_OUTPUT;

      /*XXXXXO config IBW1 */
        ibw1_struct.pixel_engine = PIXEL_ENGINE_IPP2;
        ibw1_struct.output_format = SET_IBW1_OUTPUT_RGB888;
        ibw1_struct.auto_restart = KAL_FALSE;
        ibw1_struct.bs = (jpeg_para->target_jpeg_file_address + 20);
        ibw1_struct.width = (jpeg_para->thumbnail_width - 1);
        ibw1_struct.height = (jpeg_para->thumbnail_height - 1);
        IMGDMA_IBW1Config(&ibw1_struct);
    }
    /* XXXXXO config JPEG DMA */
    jpeg_dma_struct.pixel_engine = PIXEL_ENGINE_PRZ;
    jpeg_dma_struct.jpeg_yuv_mode = jpeg_para->jpeg_yuv_mode;
    if (jpeg_para->jpeg_yuv_mode == JPEG_FORMAT_YUV420)
    {
        jpeg_dma_struct.jpeg_file_buffer_address =
            (kal_uint32)
            extmem_get_buffer((JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER * ((jpeg_para->target_width & 0xFFF0) + 16)) * 3 /
                              2);
    }
    else
    {
        jpeg_dma_struct.jpeg_file_buffer_address =
            (kal_uint32)
            extmem_get_buffer((JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER * ((jpeg_para->target_width & 0xFFF0) + 16)) << 1);
    }
    jpeg_dma_struct.restart = KAL_FALSE;
    jpeg_dma_struct.target_width = jpeg_para->target_width;
    jpeg_dma_struct.target_height = jpeg_para->target_height;

    IMGDMA_JPEGDMAConfig(&jpeg_dma_struct);
    config_jpeg_resize_path(jpeg_para);
    return 0;
}   /* config_jpeg_resize_data_path() */

kal_uint8 config_image_resize_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, resize_struct *resize_para)
{
    kal_uint32 address_offset = 0;
    IMGDMA_IBR1_STRUCT ibr1_struct;
    IMGDMA_IBW2_STRUCT ibw2_struct;
   RESZ_PRZ_STRUCT  prz_struct;

    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_RESIZE_ID)
    {
        ASSERT(0);
    }

    intmem_init((kal_uint32*) resize_para->intmem_start_address, resize_para->intmem_size);
    extmem_init((kal_uint32*) resize_para->extmem_start_address, resize_para->extmem_size);

    /* XXXXXO config IBR1 */
    ibr1_struct.base_addr = resize_para->src_image_address;
    ibr1_struct.pixel_number = (resize_para->src_pitch * resize_para->src_height - 1);
    ibr1_struct.data_type = resize_para->type;
    ibr1_struct.data_order = resize_para->data_order;
    ibr1_struct.int_en = KAL_FALSE;

    IMGDMA_IBR1Config(&ibr1_struct);

    /* config IPP1 and IPP2 */
    RESET_IPP;
    ENABLE_IPP;
    DISABLE_IPP_INT;
    IPP_CTRL_REG = 0;
    SET_IPP_GRAPH_MODE(IPP_IMGPROC_MODE);
    SET_IPP_R2Y_SRC_IMGDMA;

   /*XXXXX config PRZ */
   prz_struct.image_src=RESZ_SOURCE_IPP;
   prz_struct.dedicate_memory=KAL_TRUE;
   prz_struct.continous=KAL_FALSE;
   prz_struct.int_en=KAL_FALSE;
   prz_struct.output_2_IPP=KAL_TRUE;
   prz_struct.coarse_en=KAL_FALSE;
   prz_struct.src_height=resize_para->src_height;
   prz_struct.src_width=resize_para->src_pitch;
   prz_struct.tar_height=resize_para->target_height;
   prz_struct.tar_width=resize_para->target_pitch;
   prz_struct.work_mem_line=4;
   //prz_struct.work_mem_addr=(kal_uint32) extmem_get_buffer((video_para->display_width * RESIZER_WORKING_MEM_LINE_NUMBER *3));

   if(prz_struct.src_height>2048||prz_struct.src_width>2048||prz_struct.tar_height>2048||prz_struct.tar_width>2048)
      return 1;

   RESZ_PRZConfig(&prz_struct);

    /* XXXXXO config IBW2 */
    if (resize_para->image_pitch_mode == KAL_TRUE)
    {
        ibw2_struct.pitch = KAL_TRUE;
        ibw2_struct.pitch1_bytes = resize_para->image_pitch_bytes;
        ibw2_struct.pitch2_bytes = resize_para->image_pitch_bytes;

        address_offset = resize_para->image_pitch_bytes * resize_para->image_clip_y1;
    }
    else
    {
        ibw2_struct.pitch = KAL_FALSE;
        if (resize_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB565)
        {
            address_offset = resize_para->target_pitch * 2 * resize_para->image_clip_y1;
        }
        else if (resize_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB888)
        {
            address_offset = resize_para->target_pitch * 3 * resize_para->image_clip_y1;
        }
    }
    if (address_offset > resize_para->dest_image_address)
    {
        ASSERT(0);
    }

    ibw2_struct.dest_color_mode = resize_para->image_data_format;
    ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;

    ibw2_struct.lcd_trigger = KAL_FALSE;
    ibw2_struct.direct_couple = KAL_FALSE;
    ibw2_struct.int_en = KAL_FALSE;
    ibw2_struct.pan = KAL_TRUE;
    ibw2_struct.restart = KAL_FALSE;

    ibw2_struct.frame1_base_addr = resize_para->dest_image_address - address_offset;
    ibw2_struct.width = resize_para->target_pitch;
    ibw2_struct.height = resize_para->target_height;
    ibw2_struct.clip_left = resize_para->image_clip_x1;
    ibw2_struct.clip_right = resize_para->image_clip_x2;;
    ibw2_struct.clip_top = resize_para->image_clip_y1;
    ibw2_struct.clip_bottom = resize_para->image_clip_y2;
    ibw2_struct.enable_IBW2 = KAL_TRUE;
    ibw2_struct.cb = NULL;

    IMGDMA_IBW2Config(&ibw2_struct);
    START_IBR1;
    return 0;
}   /* config_image_resize_data_path() */

kal_uint8 config_video_encode_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, video_encode_data_path_struct *video_para)
{
    kal_uint16 crz_out_width, crz_out_height;

    /* kal_uint8 h_ratio,v_ratio; */
    IMGDMA_IBR2_STRUCT ibr2_struct;
    IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
    IMGDMA_VIDEO_DECODE_STRUCT video_decode_dma_struct;
    IMGDMA_IBW2_STRUCT ibw2_struct;
   RESZ_CRZ_STRUCT crz_struct;
   RESZ_PRZ_STRUCT  prz_struct;
    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_MPEG_ENCODE_ID)
    {
        ASSERT(0);
    }

    current_video_buffer_count = 0;
    img_dma_ibw2_int = KAL_FALSE;

    kal_mem_cpy(&video_encode_config_data, video_para, sizeof(video_encode_data_path_struct));

    if(video_para->init_mem==KAL_TRUE)
    {
    intmem_init((kal_uint32*) video_para->intmem_start_address, video_para->intmem_size);
    extmem_init((kal_uint32*) video_para->extmem_start_address, video_para->extmem_size);
    }

    crz_out_width = video_para->encode_width;
    crz_out_height = video_para->encode_height;
   /*XXXXX config CRZ */
   crz_struct.image_src=RESZ_SOURCE_ISP;
   crz_struct.dedicate_memory=KAL_TRUE;
   crz_struct.continous=KAL_TRUE;
   crz_struct.int_en=KAL_FALSE;
   crz_struct.src_height=video_para->image_src_height;
   crz_struct.src_width=video_para->image_src_width;
   crz_struct.tar_height=crz_out_height;
   crz_struct.tar_width=crz_out_width;
   crz_struct.work_mem_line=4;
   crz_struct.work_mem_addr=0x40000000;/* dummy for hardware issue */

   RESZ_CRZConfig(&crz_struct);

    /* XXXXX Oconfig IBR2 */
    ibr2_struct.restart = KAL_TRUE;
    ibr2_struct.int_en = KAL_FALSE;
    ibr2_struct.pixel_engine = PIXEL_ENGINE_CRZ;

    if (video_para->overlay_frame_mode == KAL_TRUE)
    {
        ibr2_struct.overlay_frame_mode = KAL_TRUE;
        ibr2_struct.overlay_frame_buffer_address = video_para->overlay_frame_buffer_address;
        ibr2_struct.overlay_frame_width = video_para->overlay_frame_width;
        ibr2_struct.overlay_frame_height = video_para->overlay_frame_height;
        ibr2_struct.overlay_frame_target_width = crz_out_width;
        ibr2_struct.overlay_frame_target_height = crz_out_height;
        ibr2_struct.overlay_color_depth = video_para->overlay_color_depth;
        ibr2_struct.overlay_frame_source_key = video_para->overlay_frame_source_key;
    }
    else
    {
        ibr2_struct.overlay_frame_mode = KAL_FALSE;
    }

    IMGDMA_IBR2Config(&ibr2_struct);

    /* XXXXXO config video encode DMA Write */
    video_encode_dma_struct.rdma_destination_engine = PIXEL_ENGINE_PRZ;
    video_encode_dma_struct.wdma_pixel_engine = PIXEL_ENGINE_CRZ;
    video_encode_dma_struct.restart = KAL_TRUE;
    if (get_lcd_hw_layer_rotate_value(mpeg4_encode_data.hw_update_layer) == LCD_LAYER_ROTATE_NORMAL)
    {
        video_encode_dma_struct.w_trigger_r = KAL_FALSE;
    }
    else
    {
        video_encode_dma_struct.w_trigger_r = KAL_TRUE;
    }

    video_encode_dma_struct.read_done_int = KAL_FALSE;
    video_encode_dma_struct.wrtie_done_int = KAL_TRUE;

    if(video_para->init_mem==KAL_TRUE)
    {
      video_encode_dma_struct.y_base_addr1 = (kal_uint32) extmem_get_buffer(crz_out_width * crz_out_height);
      video_encode_dma_struct.u_base_addr1 = (kal_uint32) extmem_get_buffer((crz_out_width * crz_out_height) >> 2);
      video_encode_dma_struct.v_base_addr1 = (kal_uint32) extmem_get_buffer((crz_out_width * crz_out_height) >> 2);
      video_encode_dma_struct.y_base_addr2 = (kal_uint32) extmem_get_buffer(crz_out_width * crz_out_height);
      video_encode_dma_struct.u_base_addr2 = (kal_uint32) extmem_get_buffer((crz_out_width * crz_out_height) >> 2);
      video_encode_dma_struct.v_base_addr2 = (kal_uint32) extmem_get_buffer((crz_out_width * crz_out_height) >> 2);

    }
    else
    {
      /*use original setting*/
       video_encode_dma_struct.y_base_addr1 = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1;
       video_encode_dma_struct.u_base_addr1 = REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1;
       video_encode_dma_struct.v_base_addr1 = REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1;

       video_encode_dma_struct.y_base_addr2 = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2;
       video_encode_dma_struct.u_base_addr2 = REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2;
       video_encode_dma_struct.v_base_addr2 = REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2;
    }
    video_encode_dma_struct.encode_width = crz_out_width;
    video_encode_dma_struct.encode_height = crz_out_height;

    IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);

    if(video_para->init_mem==KAL_TRUE)
    {
    mpeg4_video_buffer[0] = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1;
    mpeg4_video_buffer[1] = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2;
    }

   /*XXXXX config PRZ */
    if (get_lcd_hw_layer_rotate_value(mpeg4_encode_data.hw_update_layer) == LCD_LAYER_ROTATE_NORMAL)
      prz_struct.image_src=RESZ_SOURCE_MPEG4_DECODE_DMA;
    else
      prz_struct.image_src=RESZ_SOURCE_MPEG4_ENCODE_DMA;

   prz_struct.dedicate_memory=KAL_FALSE;
   prz_struct.continous=KAL_TRUE;
   prz_struct.int_en=KAL_FALSE;
   prz_struct.output_2_IPP=KAL_TRUE;
   prz_struct.coarse_en=KAL_FALSE;
   prz_struct.src_height=crz_out_height;
   prz_struct.src_width=crz_out_width;
   prz_struct.tar_height=video_para->display_height;
   prz_struct.tar_width=video_para->display_width;
   prz_struct.work_mem_line=4;
    if(video_para->init_mem==KAL_TRUE)
    {
        /*get the max size memory first*/   	   
   	   prz_struct.work_mem_addr=(kal_uint32) extmem_get_buffer(IDP_VR_MAXIMUM_RESZ_WM_SIZE);
    }
    else/*use the original memory*/
   {
      prz_struct.work_mem_addr=(kal_uint32)REG_PRZ_WORK_MEM_ADDR;
   }
   RESZ_PRZConfig(&prz_struct);
    /* config IPP1 */
    RESET_IPP;
    ENABLE_IPP;
    SET_IPP_GRAPH_MODE(IPP_VIDEO_MODE);
    SET_IPP_HUE_SAT(IPP_HUE_SAT_ADJUST_EFFECT);

    /* XXXXXO config IBW2 */
    ibw2_struct.frame1_base_addr = video_para->frame_buffer_address;
    ibw2_struct.frame2_base_addr = video_para->frame_buffer_address;
    ibw2_struct.width = video_para->display_width;
    ibw2_struct.height = video_para->display_height;
    if (video_para->image_pitch_mode == KAL_TRUE)
    {
        ibw2_struct.pitch = KAL_TRUE;
        ibw2_struct.pitch1_bytes = video_para->image_pitch_bytes;
        ibw2_struct.pitch2_bytes = video_para->image_pitch_bytes;
    }
    else
    {
        ibw2_struct.pitch = KAL_FALSE;
    }

    ibw2_struct.dest_color_mode = video_para->image_data_format;
    ibw2_struct.lcd_trigger = KAL_TRUE;

    ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;
    ibw2_struct.int_en = KAL_FALSE;
    #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
       ibw2_struct.int_en = KAL_TRUE;
    #endif
    ibw2_struct.pan = KAL_FALSE;
    ibw2_struct.enable_IBW2 = KAL_TRUE;
    ibw2_struct.cb = isp_ibw2_cb;

    /* XXXXX bad code */
    vid_enc_r_cb = NULL;
    if (get_lcd_hw_layer_rotate_value(mpeg4_encode_data.hw_update_layer) == LCD_LAYER_ROTATE_NORMAL)
    {                                           /* direct couple */
        ibw2_struct.direct_couple = KAL_TRUE;   /* ENABLE_IBW2_DC; */
        /*when selecting direct couple, this bit is used to select LCD/G2D*/
        ibw2_struct.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB565;

        ibw2_struct.restart = KAL_FALSE;        /* DISABLE_IBW2_AUTO_RESTART; */
        vid_enc_r_cb = mpeg4_vid_enc_r_cb;
        video_record_frame = 0;
        ibw2_struct.enable_IBW2 = KAL_FALSE;
    }
    else
    {                                           /* hardware trigger */
        ibw2_struct.direct_couple = KAL_FALSE;  /* DISABLE_IBW2_DC; */
        ibw2_struct.restart = KAL_TRUE;         /* ENABLE_IBW2_AUTO_RESTART; */
    }
#ifdef __SYNC_LCM_SW_SUPPORT__
    if (sync_lcm_enable_mode==KAL_TRUE)
    {
        if (ibw2_struct.direct_couple==KAL_TRUE)
        {
            video_encode_dc_flag=KAL_TRUE;
            ibw2_struct.cb = NULL;
        }
        else
        {
            ibw2_struct.lcd_trigger = KAL_FALSE;
            ibw2_struct.int_en = KAL_TRUE;
            video_encode_dc_flag=KAL_FALSE;
        }
     }
     sync_lcm_update_cb=sync_lcm_video_encode_update_cb;
#endif

    IMGDMA_IBW2Config(&ibw2_struct);

    /* XXXXXO config video decode DMA */
    if (get_lcd_hw_layer_rotate_value(mpeg4_encode_data.hw_update_layer) == LCD_LAYER_ROTATE_NORMAL)
    {
        video_decode_dma_struct.decode_done_int = KAL_FALSE;
        video_decode_dma_struct.width = crz_out_width;
        video_decode_dma_struct.height = crz_out_height;
        IMGDMA_VIDEODECODE_DMAConfig(&video_decode_dma_struct);
    }

    vid_enc_w_cb1 = video_para->video_encode_cb;
    vid_enc_w_cb = NULL;
    #ifdef TV_OUT_SUPPORT
    if (video_para->tv_output == KAL_TRUE)
    {   /* config Video encode write DMA */
        tv_output_owner = TV_OUT_OWNER_VID_DMA_W;
        tv_out_current_fb = 0;
        vid_enc_w_cb = mpeg4_vid_enc_w_cb;
        video_encode_config_data.tv_output_buffer1_address = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1;
        video_encode_config_data.tv_output_buffer2_address = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2;
        set_tv_output_data_format(TV_DATA_YUV420);
        set_tv_src_size(TV_OUT_OWNER_VID_DMA_W, crz_out_width, crz_out_height);
    }
    #endif/*#ifdef TV_OUT_SUPPORT */
    return 0;
}   /* config_video_encode_data_path() */

void reconfig_purevideo_encode_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, video_encode_data_path_struct *video_para)
{
    kal_uint16 crz_out_width, crz_out_height;

    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_MPEG_ENCODE_ID)
    {
        ASSERT(0);
    }

    RESET_CRZ;
    crz_out_width = REG_CRZ_TARGET_IMAGE_SIZE & 0xFFFF;
    crz_out_height = (REG_CRZ_TARGET_IMAGE_SIZE & 0xFFFF0000) >> 16;

    /* reconfigure CRZ */
    SET_CRZ_SRC_SIZE(video_para->image_src_width, video_para->image_src_height);
    if (video_para->image_src_width == crz_out_width)
    {
        REG_CRZ_H_RATIO = 1 << RESZ_H_RATIO_SHIFT_BITS;
    }
    else
    {
        REG_CRZ_H_RATIO = ((1 << RESZ_H_RATIO_SHIFT_BITS) / crz_out_width) * video_para->image_src_width;
    }
    if (video_para->image_src_height == crz_out_height)
    {
        REG_CRZ_V_RATIO = (1 << RESZ_V_RATIO_SHIFT_BITS);
    }
    else
    {
        REG_CRZ_V_RATIO = ((1 << RESZ_V_RATIO_SHIFT_BITS) / crz_out_height) * video_para->image_src_height;
    }

    REG_CRZ_H_RESIDUAL = video_para->image_src_width % crz_out_width;
    REG_CRZ_V_RESIDUAL = video_para->image_src_height % crz_out_height;
    ENABLE_CRZ;
}   /* reconfig_video_encode_data_path() */

kal_uint8 config_video_decode_data_path_legacy_series(
            MMDI_SCENERIO_ID scenario_id,
            video_decode_data_path_struct *video_para,
            lcd_frame_update_struct *lcd_para)
{
    #if (defined(MP4_CODEC) && defined(ISP_SUPPORT))

    lcd_frame_update_struct lcd_data;
    IMGDMA_VIDEO_DECODE_STRUCT video_decode_dma_struct;
    IMGDMA_IBW2_STRUCT ibw2_struct;
    RESZ_PRZ_STRUCT  prz_struct;
    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_MPEG_DECODE_ID)
    {
        ASSERT(0);
    }

    video_decode_lcd_id = lcd_para->lcd_id;
    video_display = video_para->display;
   /*XXXXX config PRZ */
   prz_struct.image_src=RESZ_SOURCE_MPEG4_DECODE_DMA;
   prz_struct.dedicate_memory=KAL_TRUE;
   prz_struct.continous=KAL_TRUE;
   prz_struct.int_en=KAL_FALSE;
   prz_struct.output_2_IPP=KAL_TRUE;
   prz_struct.coarse_en=KAL_FALSE;
   prz_struct.src_height=video_para->video_src_height;
   prz_struct.src_width=video_para->video_src_width;


    #if 1
    prz_struct.tar_height=video_para->resize_tar_height;
    prz_struct.tar_width=video_para->resize_tar_width;
    #else
/* under construction !*/
/* under construction !*/
    #endif

   prz_struct.work_mem_line=4;

   RESZ_PRZConfig(&prz_struct);

    /* config IPP */
    RESET_IPP;
    ENABLE_IPP;
    ENABLE_IPP_CONTRAST_BRIGHT;
    SET_IPP_GRAPH_MODE(IPP_VIDEO_MODE);
    adjustment_contrast_video_decode(video_para->contrast_level);
    adjustment_brightness_video_decode(video_para->brightness_level);

    //video_para->effect=VIDEO_DECODE_EFFECT_SEPIAGREEN;
    #ifdef __VIDEO_EDITOR__
    config_video_decode_effect(video_para->effect);
    #endif
    /* XXXXXO config IBW2 */
    ibw2_struct.frame1_base_addr = video_para->frame_buffer_address;
    ibw2_struct.frame2_base_addr = video_para->frame_buffer_address;
    #if 1
    ibw2_struct.width = video_para->resize_tar_width;
    ibw2_struct.height = video_para->resize_tar_height;
    #else
/* under construction !*/
/* under construction !*/
    #endif

    if (video_para->image_pitch_mode == KAL_TRUE)
    {
        ibw2_struct.pitch = KAL_TRUE;
        ibw2_struct.pitch1_bytes = video_para->image_pitch_bytes;
        ibw2_struct.pitch2_bytes = video_para->image_pitch_bytes;
    }
    else
    {
        ibw2_struct.pitch = KAL_FALSE;
    }

    ibw2_struct.dest_color_mode = video_para->image_data_format;
    ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;
    ibw2_struct.int_en = KAL_FALSE;
    ibw2_struct.cb = NULL;
    if (video_para->display == KAL_TRUE)
    {
        ibw2_struct.lcd_trigger = KAL_TRUE;
        if (video_para->force_lcd_hw_trigger == KAL_TRUE)
        {
            ibw2_struct.direct_couple = KAL_FALSE;
        }
        else
        {
            if (get_lcd_hw_layer_rotate_value(lcd_para->hw_update_layer) == LCD_LAYER_ROTATE_NORMAL)
            {
                ibw2_struct.direct_couple = KAL_TRUE;
                /*when selecting direct couple, this bit is used to select LCD/G2D*/
                ibw2_struct.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB565;
            }
            else
            {
                ibw2_struct.direct_couple = KAL_FALSE;
            }
        }
        #ifdef __SYNC_LCM_SW_SUPPORT__
        if (sync_lcm_enable_mode==KAL_TRUE)
        {
            if (ibw2_struct.direct_couple==KAL_FALSE)
            {
                ibw2_struct.int_en = KAL_TRUE;
                ibw2_struct.lcd_trigger = KAL_FALSE;
                ibw2_struct.cb=video_decode_ibw2_cb;
                video_decode_direct_couple=KAL_FALSE;
            }
            else
            {
                video_decode_direct_couple=KAL_TRUE;
            }
            video_decode_update_flag=KAL_FALSE;
        }
        sync_lcm_update_cb=sync_lcm_video_decode_update_cb;
        #endif

    }
    else
    {
         #ifdef __SYNC_LCM_SW_SUPPORT__
         video_decode_update_flag=KAL_FALSE;
         sync_lcm_update_cb=sync_lcm_video_decode_update_cb;
         #endif
        ibw2_struct.lcd_trigger = KAL_FALSE;
        ibw2_struct.direct_couple = KAL_FALSE;
    }

    #if 1
    if(video_para->pan==KAL_TRUE)
    {
       ibw2_struct.pan = KAL_TRUE;
       ibw2_struct.clip_left=0;
       ibw2_struct.clip_right=video_para->display_width-1;
       ibw2_struct.clip_top=0;
       ibw2_struct.clip_bottom=video_para->display_height-1;
    }
    else
    {
       ibw2_struct.pan = KAL_FALSE;
    }
    #else
/* under construction !*/
    #endif
    ibw2_struct.restart = KAL_FALSE;

    ibw2_struct.enable_IBW2 = KAL_FALSE;

    IMGDMA_IBW2Config(&ibw2_struct);

    /* XXXXXO config video decode DMA */
    video_decode_dma_struct.decode_done_int = KAL_FALSE;
    video_decode_dma_struct.width = video_para->video_src_width;
    video_decode_dma_struct.height = video_para->video_src_height;
    IMGDMA_VIDEODECODE_DMAConfig(&video_decode_dma_struct);

    if (video_para->display == KAL_TRUE)
    {
        lcd_data.module_id = lcd_para->module_id;
        lcd_data.lcd_id = lcd_para->lcd_id;
        if (video_para->force_lcd_hw_trigger == KAL_TRUE)
        {
            lcd_data.fb_update_mode = LCD_HW_TRIGGER_MODE;
        }
        else
        {
            if (get_lcd_hw_layer_rotate_value(lcd_para->hw_update_layer) == LCD_LAYER_ROTATE_NORMAL)
            {
                lcd_data.fb_update_mode = LCD_DIRECT_COUPLE_MODE;
            }
            else
            {
                lcd_data.fb_update_mode = LCD_HW_TRIGGER_MODE;
            }
        }
        lcd_data.lcm_start_x = lcd_para->lcm_start_x;
        lcd_data.lcm_start_y = lcd_para->lcm_start_y;
        lcd_data.lcm_end_x = lcd_para->lcm_end_x;
        lcd_data.lcm_end_y = lcd_para->lcm_end_y;
        lcd_data.roi_offset_x = lcd_para->roi_offset_x;
        lcd_data.roi_offset_y = lcd_para->roi_offset_y;
        lcd_data.update_layer = lcd_para->update_layer;
        lcd_data.hw_update_layer = lcd_para->hw_update_layer;
        lcd_data.roi_background_color = lcd_para->roi_background_color;
        lcd_data.hw_trigger_src = LCD_HW_TRIGGER_IBW2;
        lcd_data.memory_output = KAL_FALSE;
        lcd_data.block_mode_flag = KAL_TRUE;
        lcd_data.lcd_block_mode_cb = NULL;
        #ifdef TV_OUT_SUPPORT
        if ((video_para->tv_output == KAL_TRUE) && ((tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE1) ||
                                                    (tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE4)))
        {
            lcd_data.tv_output = KAL_TRUE;
            lcd_data.tv_output_width = video_para->tv_output_width;
            lcd_data.tv_output_height = video_para->tv_output_height;
            lcd_data.tv_output_offset_x = video_para->tv_output_offset_x;
            lcd_data.tv_output_offset_y = video_para->tv_output_offset_y;
            lcd_data.tv_output_frame_buffer1_address = lcd_para->tv_output_frame_buffer1_address;
            lcd_data.tv_output_frame_buffer2_address = lcd_para->tv_output_frame_buffer2_address;
            lcd_data.tv_output_frame_buffer_size = lcd_para->tv_output_frame_buffer_size;
            tv_output_owner = TV_OUT_OWNER_MMI;
        }
        else
        {
            lcd_data.tv_output = KAL_FALSE;
        }
        #else
            lcd_data.tv_output = KAL_FALSE;
        #endif/*#ifdef TV_OUT_SUPPORT */
        lcd_fb_update(&lcd_data);
    }
    #ifdef TV_OUT_SUPPORT
    if ((video_para->tv_output == KAL_TRUE) && ((tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE2) ||
                                                (tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE3)))
    {
        lcd_data.tv_output = KAL_FALSE;
        tv_output_owner = TV_OUT_OWNER_MP4_DEC;
        set_tv_src_size(TV_OUT_OWNER_MP4_DEC, video_para->tv_output_display_width, video_para->tv_output_display_height);
    }
    #endif/*#ifdef TV_OUT_SUPPORT */
   #endif/*defined(MP4_CODEC) && defined(ISP_SUPPORT)*/
    return 0;
}   /* config_video_decode_data_path() */

void video_decode_display_legacy_series(video_decode_data_path_struct *video_para)
{   /* display video playback */
    volatile kal_uint16 i;

    kal_uint32 save_irq_mask;

    save_irq_mask = SaveAndSetIRQMask();/*to avoid race condition, Video LISR() and GPT HISR*/

    if (video_para->drop_lcm_frame == KAL_FALSE)
    {
        STOP_IBW2;
        STOP_IMGDMA_VIDEO_DECODE;
        if (video_para->discard_frame_address == KAL_FALSE)
        {
            REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1 = video_para->video_y_buffer_address;
            REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR1 = video_para->video_u_buffer_address;
            REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR1 = video_para->video_v_buffer_address;
        }
        if (lcd_sleeping_state == KAL_FALSE)
        {
        #ifdef __SYNC_LCM_SW_SUPPORT__
            if (sync_lcm_enable_mode==KAL_TRUE)
            {
                if (video_decode_direct_couple==KAL_TRUE)
                {    /* direct couple */
                    video_decode_update_flag=KAL_TRUE;
                    if (video_display==KAL_FALSE)
                    {   /* output the YUV buffer to IBW2 image buffer for MMI to update the first video frame */
                        START_IBW2;
                        START_IMGDMA_VIDEO_DECODE;
                    }
                }
                else
                {    /* hardware trigger */
                    START_IBW2;
                    START_IMGDMA_VIDEO_DECODE;
                }
            }
        #else
            if ((REG_LCD_ROI_HW_CTRL != 0) || (video_display == KAL_FALSE))
            {
                START_IBW2;
                START_IMGDMA_VIDEO_DECODE;
            }
        #endif
        }
    }
    #ifdef TV_OUT_SUPPORT
    if (video_para->tv_output == KAL_TRUE)
    {
        if ((tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE2) ||
            (tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE3))
        {
            if (video_para->discard_frame_address == KAL_FALSE)
            {
                tv_fb_update_yuv420(
                    TV_OUT_OWNER_MP4_DEC,
                    video_para->video_y_buffer_address,
                    video_para->video_u_buffer_address,
                    video_para->video_v_buffer_address);
            }
        }
    }
    #endif/*#ifdef TV_OUT_SUPPORT */
    RestoreIRQMask(save_irq_mask);
    for (i = 0; i < 0x80; i++);
}   /* video_decode_display() */

kal_uint8 config_filter_effect_data_path_legacy_series(ipp_effect_struct *ipp_para)
{
    /* config IPP */
    SET_IPP_GRAPH_MODE(IPP_IMGPROC_MODE);
    SET_IPP_MASK_FILTER(ipp_para->filter_mode);
    IPP_IMAGE_FRAME_WIDTH_REG = ipp_para->src_width;
    IPP_IMAGE_FRAME_HEIGHT_REG = ipp_para->src_height;
    IPP_IMAGE_SRC_BASE_ADDR_REG = ipp_para->src_address;
    IPP_IMAGE_DEST_BASE_ADDR_REG = ipp_para->dest_address;

    if (ipp_para->src_color_mode == IPP_COLOR_RGB565)
    {
        SET_IPP_FILTER_SRC_RGB565;
    }
    else if (ipp_para->src_color_mode == IPP_COLOR_RGB888)
    {
        SET_IPP_FILTER_SRC_RGB888;
    }

    ENABLE_IPP_INT;
    START_MASK_FILTER;
    return 0;
}   /* config_filter_effect_data_path() */

kal_uint8 config_pixel_effect_data_path_legacy_series(ipp_effect_struct *ipp_para)
{
    IMGDMA_IBR1_STRUCT ibr1_struct;
    IMGDMA_IBW2_STRUCT ibw2_struct;
    RESZ_PRZ_STRUCT    prz_struct;

    /* XXXXXO config IBR1 */
    ibr1_struct.base_addr = ipp_para->src_address;
    ibr1_struct.pixel_number = (ipp_para->src_width * ipp_para->src_height - 1);
    ibr1_struct.data_type = ipp_para->src_color_mode;
    ibr1_struct.data_order = ipp_para->src_color_order;
    ibr1_struct.int_en = KAL_FALSE;

    IMGDMA_IBR1Config(&ibr1_struct);

   /*XXXXX config PRZ */
   prz_struct.image_src=RESZ_SOURCE_IPP;
   prz_struct.dedicate_memory=KAL_TRUE;
   prz_struct.continous=KAL_FALSE;
   prz_struct.int_en=KAL_FALSE;
   prz_struct.output_2_IPP=KAL_TRUE;
   prz_struct.coarse_en=KAL_FALSE;
   prz_struct.src_height=ipp_para->src_height;
   prz_struct.src_width=ipp_para->src_width;
   prz_struct.tar_height=ipp_para->src_height;
   prz_struct.tar_width=ipp_para->src_width;
   prz_struct.work_mem_line=4;

   RESZ_PRZConfig(&prz_struct);
    /* config IPP */
    SET_IPP_GRAPH_MODE(IPP_IMGPROC_MODE);
    DISABLE_IPP_INT;
    SET_IPP_R2Y_SRC_IMGDMA;
    SET_IPP_HUE_SAT(ipp_para->pixel_effect_para.hsa);
    if (ipp_para->pixel_effect_para.cba == 1)
    {
        ENABLE_IPP_CONTRAST_BRIGHT;
    }
    else
    {
        DISABLE_IPP_CONTRAST_BRIGHT;
    }
    if (ipp_para->pixel_effect_para.inv == 1)
    {
        ENABLE_IPP_COLOR_INV;
    }
    else
    {
        DISABLE_IPP_COLOR_INV;
    }
    if (ipp_para->pixel_effect_para.clr == 1)
    {
        ENABLE_IPP_COLOR_ADJUST;
    }
    else
    {
        DISABLE_IPP_COLOR_ADJUST;
    }
    if (ipp_para->pixel_effect_para.gma == 1)
    {
        ENABLE_IPP_GAMMA_CORRECTION;
    }
    else
    {
        DISABLE_IPP_GAMMA_CORRECTION;
    }

    /* XXXXXO config IBW2 */
    ibw2_struct.frame1_base_addr = ipp_para->dest_address;
    ibw2_struct.frame2_base_addr = ipp_para->dest_address;
    ibw2_struct.width = ipp_para->src_width;
    ibw2_struct.height = ipp_para->src_height;
    ibw2_struct.dest_color_mode = ipp_para->dest_color_mode;
    ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;
    ibw2_struct.lcd_trigger = KAL_FALSE;
    ibw2_struct.int_en = KAL_TRUE;
    ibw2_struct.pan = KAL_FALSE;
    ibw2_struct.direct_couple = KAL_FALSE;
    ibw2_struct.restart = KAL_FALSE;
    ibw2_struct.pitch = KAL_FALSE;
    ibw2_struct.enable_IBW2 = KAL_TRUE;
    ibw2_struct.cb = ipp_para->ipp_effect_cb;
    IMGDMA_IBW2Config(&ibw2_struct);

    START_IBR1;
    return 0;
}   /* config_pixel_effect_data_path() */

void close_jpeg_encode_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    STOP_IBR1;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    STOP_IBR2;
    image_data_path_reset_delay(1000);
    STOP_IMGDMA_JPEG;
    image_data_path_reset_delay(1000);
    STOP_IBW3;
    image_data_path_reset_delay(1000);
    STOP_DRZ;
    image_data_path_reset_delay(1000);
    STOP_IBW1;
    image_data_path_reset_delay(1000);
    close_jpeg_module(KAL_TRUE, KAL_FALSE, KAL_TRUE);   /* decode */
}                                                       /* close_jpeg_encode_data_path() */

void close_jpeg_decode_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    STOP_IMGDMA_VIDEO_ENCODE;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
    image_data_path_reset_delay(1000);
    STOP_IBR2;
    image_data_path_reset_delay(1000);
    STOP_IBW3;
    image_data_path_reset_delay(1000);
    STOP_DRZ;
    image_data_path_reset_delay(1000);
    close_jpeg_module(KAL_FALSE, KAL_TRUE, KAL_TRUE);   /* decode */
}                                                       /* close_jpeg_decode_data_path() */

void close_jpeg_resize_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    STOP_IBR2;
    image_data_path_reset_delay(1000);
    STOP_IBW3;
    image_data_path_reset_delay(1000);
    STOP_DRZ;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    STOP_IBW1;
    image_data_path_reset_delay(1000);
    STOP_IMGDMA_JPEG;
    image_data_path_reset_delay(1000);
    close_jpeg_module(KAL_TRUE, KAL_TRUE, KAL_TRUE);    /* encode+decode */
}

void close_image_resize_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    STOP_IBR1;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
}   /* close_image_resize_data_path() */

void close_video_encode_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    RESET_CRZ;
    image_data_path_reset_delay(1000);
    STOP_IBR2;
    image_data_path_reset_delay(1000);
    STOP_IMGDMA_VIDEO_ENCODE;
    image_data_path_reset_delay(1000);
    STOP_IMGDMA_VIDEO_DECODE;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
}   /* close_video_encode_data_path() */

void close_video_decode_data_path_legacy_series(void)
{
   kal_uint32 count=0;
    while (IMGDMA_IBW2_IS_BUSY)
    {
        kal_sleep_task(1);
        count++;
        if(count>=30)/*~140 ms*/
         break;
    };

    if (video_display == KAL_TRUE)
    {
        lcd_stop_hw_update(video_decode_lcd_id);
    }
    image_data_path_reset_delay(1000);
    STOP_IMGDMA_VIDEO_DECODE;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
}   /* close_video_decode_data_path() */

void close_image_effect_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    STOP_IBR1;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
}
/*TY add*/
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
kal_uint8 config_camera_capture_mem_data_path_legacy_series(
            MMDI_SCENERIO_ID scenario_id,
            camera_capture_mem_data_path_struct *capture_para)
{
    kal_uint16 crz_out_width, crz_out_height;
    IMGDMA_IBR2_STRUCT ibr2_struct;
    IMGDMA_IBW2_STRUCT ibw2_struct;
   RESZ_CRZ_STRUCT crz_struct;
   RESZ_PRZ_STRUCT prz_struct;

    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_CAMERA_CAPTURE_MEM_ID)
    {
        ASSERT(0);
    }

    intmem_init((kal_uint32*) capture_para->intmem_start_address, capture_para->intmem_size);
    extmem_init((kal_uint32*) capture_para->extmem_start_address, capture_para->extmem_size);

    if (capture_para->overlay_frame_mode == KAL_TRUE)
    {
        crz_out_width = (capture_para->image_capture_width / capture_para->overlay_frame_width);
        crz_out_width = crz_out_width * capture_para->overlay_frame_width;
        crz_out_height = (capture_para->image_capture_height / capture_para->overlay_frame_height);
        crz_out_height = crz_out_height * capture_para->overlay_frame_height;
    }
    else
    {
        crz_out_width = capture_para->image_capture_width;
        crz_out_height = capture_para->image_capture_height;
    }

   /*XXXXX config CRZ */
   crz_struct.image_src=RESZ_SOURCE_ISP;
   crz_struct.dedicate_memory=KAL_TRUE;
   crz_struct.continous=KAL_FALSE;
   crz_struct.int_en=KAL_FALSE;
   crz_struct.src_height=capture_para->image_src_height;
   crz_struct.src_width=capture_para->image_src_width;
   crz_struct.tar_height=crz_out_height;
   crz_struct.tar_width=crz_out_width;
   crz_struct.work_mem_line=4;
   crz_struct.work_mem_addr=0x40000000;/* dummy for hardware issue */

   RESZ_CRZConfig(&crz_struct);

    /* XXXXXO config IBR2 */

    ibr2_struct.restart = KAL_FALSE;
    ibr2_struct.int_en = KAL_FALSE;
    ibr2_struct.pixel_engine = PIXEL_ENGINE_CRZ;
    if (capture_para->overlay_frame_mode == KAL_TRUE)
    {
        ibr2_struct.overlay_frame_mode = KAL_TRUE;
        ibr2_struct.overlay_frame_buffer_address = capture_para->overlay_frame_buffer_address;
        ibr2_struct.overlay_frame_width = capture_para->overlay_frame_width;
        ibr2_struct.overlay_frame_height = capture_para->overlay_frame_height;
        ibr2_struct.overlay_frame_target_width = crz_out_width;
        ibr2_struct.overlay_frame_target_height = crz_out_height;
        ibr2_struct.overlay_color_depth = capture_para->overlay_color_depth;
        ibr2_struct.overlay_frame_source_key = capture_para->overlay_frame_source_key;
    }
    else
    {
        ibr2_struct.overlay_frame_mode = KAL_FALSE;
    }
    IMGDMA_IBR2Config(&ibr2_struct);

    /* config IPP */
    RESET_IPP;
    ENABLE_IPP;
    SET_IPP_GRAPH_MODE(IPP_CAPTURE_MODE);
    SET_IPP_HUE_SAT(IPP_HUE_SAT_ADJUST_EFFECT);

    /* configure IBW4 */
    STOP_IBW4;
    SET_IBW4_PIXEL_SRC_CRZ;
    DISABLE_IBW4_AUTO_RESTART;
    DISABLE_IBW4_INT;
    REG_IMGDMA_IBW4_WIDTH = crz_out_width - 1;
    REG_IMGDMA_IBW4_HEIGHT = crz_out_height - 1;
    START_IBW4;

   /*XXXXX config PRZ */
   prz_struct.image_src=RESZ_SOURCE_IBW4;
   prz_struct.dedicate_memory=KAL_FALSE;
   prz_struct.continous=KAL_FALSE;
   prz_struct.int_en=KAL_FALSE;
   prz_struct.output_2_IPP=KAL_TRUE;
   prz_struct.coarse_en=KAL_FALSE;
   prz_struct.src_height=crz_out_height;
   prz_struct.src_width=crz_out_width;
   prz_struct.tar_height=capture_para->image_capture_height;
   prz_struct.tar_width=capture_para->image_capture_width;
   prz_struct.work_mem_line=4;
   if((prz_struct.tar_width%2)==0)
   prz_struct.work_mem_addr=(kal_uint32) intmem_get_buffer((capture_para->image_capture_width * RESIZER_WORKING_MEM_LINE_NUMBER *3));
   else
      prz_struct.work_mem_addr=(kal_uint32) intmem_get_buffer(((capture_para->image_capture_width+1) * RESIZER_WORKING_MEM_LINE_NUMBER *3));
   RESZ_PRZConfig(&prz_struct);

    /* XXXXXO config IBW2 */
    if (capture_para->image_pitch_mode == KAL_TRUE)
    {
        ibw2_struct.pitch = KAL_TRUE;
        ibw2_struct.pitch1_bytes = capture_para->image_pitch_bytes;
        ibw2_struct.pitch2_bytes = capture_para->image_pitch_bytes;
    }
    else
    {
        ibw2_struct.pitch = KAL_FALSE;
    }

    ibw2_struct.dest_color_mode = capture_para->image_data_format;
    ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;
    ibw2_struct.lcd_trigger = KAL_TRUE;
    ibw2_struct.direct_couple = KAL_FALSE;
    ibw2_struct.int_en = KAL_FALSE;
    ibw2_struct.restart = KAL_TRUE;
    ibw2_struct.frame1_base_addr = capture_para->frame_buffer_address;
    ibw2_struct.frame2_base_addr = capture_para->frame_buffer_address;
    ibw2_struct.width = capture_para->image_capture_width;
    ibw2_struct.height = capture_para->image_capture_height;
    if (capture_para->image_clip_mode == KAL_TRUE)
    {
        ibw2_struct.pan = KAL_TRUE;
        ibw2_struct.clip_left = capture_para->image_clip_x1;
        ibw2_struct.clip_right = capture_para->image_clip_x2;
        ibw2_struct.clip_top = capture_para->image_clip_y1;
        ibw2_struct.clip_bottom = capture_para->image_clip_y2;
    }
    else
    {
        ibw2_struct.pan = KAL_FALSE;
    }
    ibw2_struct.enable_IBW2 = KAL_TRUE;
    ibw2_struct.cb = NULL;

    IMGDMA_IBW2Config(&ibw2_struct);

    return 0;
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
void close_camera_capture_mem_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    RESET_CRZ;
    image_data_path_reset_delay(1000);
    STOP_IBR2;
    image_data_path_reset_delay(1000);
    STOP_IBW4;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
}   /* close_image_capture_mem_data_path_legacy_series() */


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
kal_uint8 config_camera_preview_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, camera_preview_data_path_struct *preview_para)
{
        kal_uint16 crz_out_width, crz_out_height;
   //kal_uint8 h_ratio,v_ratio;
    IMGDMA_IBW4_STRUCT ibw4_struct;
    IMGDMA_IBW2_STRUCT ibw2_struct;
    IMGDMA_IBR2_STRUCT ibr2_struct;
    IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
   RESZ_CRZ_STRUCT crz_struct;
   RESZ_PRZ_STRUCT prz_struct;

      vid_enc_w_cb = 0;
    vid_enc_w_cb1 = 0;
    if (current_image_data_path_owner != scenario_id)
        ASSERT(0);
    if (scenario_id != SCENARIO_CAMERA_PREVIEW_ID)
        ASSERT(0);
    #ifdef TV_OUT_SUPPORT
    if (preview_para->tv_output == KAL_TRUE)
    {
      if ((preview_para->tv_output_buffer_size)<((preview_para->tv_output_width * preview_para->tv_output_height*3)>>1))
            ASSERT(0);
    }
    #endif/*#ifdef TV_OUT_SUPPORT */
    kal_mem_cpy(&camera_preview_config_data, preview_para, sizeof(camera_preview_data_path_struct));

    intmem_init((kal_uint32*) preview_para->intmem_start_address, preview_para->intmem_size);
    extmem_init((kal_uint32*) preview_para->extmem_start_address, preview_para->extmem_size);

    #ifdef TV_OUT_SUPPORT
    if (preview_para->tv_output == KAL_TRUE)
    #else
    if(0)
    #endif
    {
        crz_out_width = preview_para->tv_output_width;
        crz_out_height = preview_para->tv_output_height;
    }
    else
    {
        crz_out_width = preview_para->preview_width;
        crz_out_height = preview_para->preview_height;
    }
    /* XXXXXO config IBR2 */
    ibr2_struct.restart = KAL_TRUE;
    ibr2_struct.int_en = KAL_FALSE;
    ibr2_struct.pixel_engine = PIXEL_ENGINE_CRZ;
    if (preview_para->overlay_frame_mode == KAL_TRUE)
    {
        ibr2_struct.overlay_frame_mode = KAL_TRUE;
        ibr2_struct.overlay_frame_buffer_address = preview_para->overlay_frame_buffer_address;
        ibr2_struct.overlay_frame_width = preview_para->overlay_frame_width;
        ibr2_struct.overlay_frame_height = preview_para->overlay_frame_height;
        ibr2_struct.overlay_frame_target_width = crz_out_width;
        ibr2_struct.overlay_frame_target_height = crz_out_height;
        ibr2_struct.overlay_color_depth = preview_para->overlay_color_depth;
        ibr2_struct.overlay_frame_source_key = preview_para->overlay_frame_source_key;
    }
    else
        ibr2_struct.overlay_frame_mode = KAL_FALSE;
    IMGDMA_IBR2Config(&ibr2_struct);

   /*XXXXX config CRZ */
   crz_struct.image_src=RESZ_SOURCE_ISP;
   crz_struct.dedicate_memory=KAL_TRUE;
   crz_struct.continous=KAL_TRUE;
   crz_struct.int_en=KAL_FALSE;
   crz_struct.src_height=preview_para->image_src_height;
   crz_struct.src_width=preview_para->image_src_width;
   crz_struct.tar_height=crz_out_height;
   crz_struct.tar_width=crz_out_width;
   crz_struct.work_mem_line=16;
   crz_struct.work_mem_addr=0x40000000;/* dummy for hardware issue */

   RESZ_CRZConfig(&crz_struct);

    /* XXXXXO config IBW4 */
    ibw4_struct.pixel_engine = PIXEL_ENGINE_CRZ;
    ibw4_struct.auto_restart = KAL_TRUE;
    ibw4_struct.int_en = KAL_FALSE;
    ibw4_struct.width = crz_out_width - 1;
    ibw4_struct.height = crz_out_height - 1;
    IMGDMA_IBW4Config(&ibw4_struct);

   /*XXXXX config PRZ */

   prz_struct.image_src=RESZ_SOURCE_IBW4;
   prz_struct.dedicate_memory=KAL_FALSE;
   prz_struct.continous=KAL_TRUE;
   prz_struct.int_en=KAL_FALSE;
   prz_struct.output_2_IPP=KAL_TRUE;
   prz_struct.coarse_en=KAL_FALSE;
   prz_struct.src_height=crz_out_height;
   prz_struct.src_width=crz_out_width;
   prz_struct.tar_height=preview_para->preview_height;
   prz_struct.tar_width=preview_para->preview_width;
   prz_struct.work_mem_line=4;
   if((prz_struct.tar_width%2)==0)
   prz_struct.work_mem_addr=(kal_uint32) intmem_get_buffer((preview_para->preview_width * RESIZER_WORKING_MEM_LINE_NUMBER *3));
   else
      prz_struct.work_mem_addr=(kal_uint32) intmem_get_buffer(((preview_para->preview_width+1) * RESIZER_WORKING_MEM_LINE_NUMBER *3));

   RESZ_PRZConfig(&prz_struct);

    /* configure IPP1 */
    RESET_IPP;
    ENABLE_IPP;
    IPP_CTRL_REG = 0;
    SET_IPP_GRAPH_MODE(IPP_PREVIEW_PLAYBACK_MODE);
    SET_IPP_HUE_SAT(IPP_HUE_SAT_ADJUST_EFFECT);

    /* XXXXXO config IBW2 */

    ibw2_struct.frame1_base_addr = preview_para->frame_buffer_address;
    ibw2_struct.frame2_base_addr = preview_para->frame_buffer_address1;
#ifdef __SYNC_LCM_SW_SUPPORT__
    preview_buffer1_address=preview_para->frame_buffer_address;
    preview_buffer2_address=preview_para->frame_buffer_address1;
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
      case LCD_LAYER4_ENABLE:
         preview_layer_base_address=LCD_LAYER4_BUFF_ADDR_REG;
      break;
      case LCD_LAYER5_ENABLE:
         preview_layer_base_address=LCD_LAYER5_BUFF_ADDR_REG;
      break;
    }
#endif
    ibw2_struct.width = preview_para->preview_width;
    ibw2_struct.height = preview_para->preview_height;
    if (preview_para->image_pitch_mode == KAL_TRUE)
    {
        ibw2_struct.pitch = KAL_TRUE;
        ibw2_struct.pitch1_bytes = preview_para->image_pitch_bytes;
        ibw2_struct.pitch2_bytes = preview_para->image_pitch_bytes;
    }
    else
    {
        ibw2_struct.pitch = KAL_FALSE;
    }
    ibw2_struct.dest_color_mode = preview_para->image_data_format;
    ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;
    ibw2_struct.direct_couple = KAL_FALSE;
    ibw2_struct.restart = KAL_TRUE;
    ibw2_struct.pan = KAL_FALSE;
#ifdef __SYNC_LCM_SW_SUPPORT__
   if (sync_lcm_enable_mode==KAL_TRUE)
   {
      ibw2_struct.lcd_trigger=KAL_FALSE;
      ibw2_struct.int_en=KAL_TRUE;
      ibw2_struct.cb=preview_frame_ready_cb;
      preview_frame_buffer_swap=0;
      preview_frame_update_flag=KAL_FALSE;
   }
   else
   {
      ibw2_struct.lcd_trigger=KAL_TRUE;
      ibw2_struct.int_en=KAL_FALSE;
      ibw2_struct.cb = NULL;
   }
   sync_lcm_update_cb=sync_lcm_preview_update_cb;
#else
    ibw2_struct.lcd_trigger = KAL_TRUE;
    ibw2_struct.int_en = KAL_FALSE;
    ibw2_struct.cb = NULL;
#endif

   #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
      ibw2_struct.int_en = KAL_TRUE;
   #endif
    ibw2_struct.enable_IBW2 = KAL_TRUE;

    IMGDMA_IBW2Config(&ibw2_struct);
    #ifdef TV_OUT_SUPPORT
    if (preview_para->tv_output == KAL_TRUE)
    {   /* output for LCD display */
        /* XXXXXO config Video encode DMA write */
        video_encode_dma_struct.rdma_destination_engine = PIXEL_ENGINE_NONE;
        video_encode_dma_struct.wdma_pixel_engine = PIXEL_ENGINE_CRZ;
        video_encode_dma_struct.restart = KAL_TRUE;
        video_encode_dma_struct.w_trigger_r = KAL_FALSE;

        video_encode_dma_struct.read_done_int = KAL_FALSE;
        video_encode_dma_struct.wrtie_done_int = KAL_TRUE;

        video_encode_dma_struct.y_base_addr1 = (kal_uint32) preview_para->tv_output_buffer1_address;
        video_encode_dma_struct.u_base_addr1 = (kal_uint32) preview_para->tv_output_buffer1_address +
            crz_out_width * crz_out_height;
        video_encode_dma_struct.v_base_addr1 = (kal_uint32) preview_para->tv_output_buffer1_address +
            ((crz_out_width * crz_out_height * 5) >> 2);
        video_encode_dma_struct.y_base_addr2 = (kal_uint32) preview_para->tv_output_buffer2_address;
        video_encode_dma_struct.u_base_addr2 = (kal_uint32) preview_para->tv_output_buffer2_address +
            crz_out_width * crz_out_height;
        video_encode_dma_struct.v_base_addr2 = (kal_uint32) preview_para->tv_output_buffer2_address +
            ((crz_out_width * crz_out_height * 5) >> 2);
        video_encode_dma_struct.encode_width = crz_out_width;
        video_encode_dma_struct.encode_height = crz_out_height;

        IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);

        tv_output_owner = TV_OUT_OWNER_VID_DMA_W;
        tv_out_current_fb = 0;
        vid_enc_w_cb = preview_vid_enc_w_cb;
        set_tv_output_data_format(TV_DATA_YUV420);
        set_tv_src_size(TV_OUT_OWNER_VID_DMA_W, crz_out_width, crz_out_height);
    }
    #endif/*#ifdef TV_OUT_SUPPORT */
    return 0;
}   /* config_camera_preview_data_path_legacy_series() */

kal_uint32 crz_uncount_value;
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
void reconfig_camera_preview_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, camera_preview_data_path_struct *preview_para)
{
	extern camera_preview_data_path_struct ipp_preview_data;
    kal_uint16 crz_out_width, crz_out_height;
    volatile kal_uint32 crz_count = 0, crz_count1 = 0, output_width_height;
    volatile kal_uint8 i;
    kal_uint8 reset_all_data_path_flag = KAL_FALSE;

       if (current_image_data_path_owner != scenario_id)
        ASSERT(0);
    if (scenario_id != SCENARIO_CAMERA_PREVIEW_ID)
        ASSERT(0);

    crz_out_width = REG_CRZ_TARGET_IMAGE_SIZE & 0xFFFF;
    crz_out_height = (REG_CRZ_TARGET_IMAGE_SIZE & 0xFFFF0000) >> 16;

    crz_uncount_value = *(volatile kal_uint32*)0x806A00c0;
    do
    {
        crz_count1 = crz_count;
        for (i = 0; i < 10; i++);
        output_width_height = (REG_CRZ_TARGET_IMAGE_SIZE & 0xFFFF);
        crz_count = *(volatile kal_uint32*)0x806A00c0;
        if (crz_count1 == crz_count)
            reset_all_data_path_flag = KAL_TRUE;
        /*Here are two conditon check
        1.crz_count != output_width_height
        => check if VR is finished.
        2.(reset_all_data_path_flag == KAL_FALSE)
        =>check VR status. If VR is hang, jump this loop and reset.
        */
    }
    while ((crz_count != output_width_height) && (reset_all_data_path_flag == KAL_FALSE));

    if (crz_count != output_width_height)
    {
        STOP_IBR2;
        STOP_IBW3;
        STOP_IBW4;
        STOP_IMGDMA_VIDEO_ENCODE;
        RESET_PRZ;
        STOP_DRZ;
        STOP_IBW1;
        STOP_IBW2;
        if (ipp_preview_data.overlay_frame_mode == KAL_TRUE)
            START_IBR2;
        START_IBW4;
        ENABLE_PRZ_H_LINE;
        ENABLE_PRZ_V_LINE;
        START_IBW2;
        #ifdef TV_OUT_SUPPORT
      if (ipp_preview_data.tv_output==KAL_TRUE)
            START_IMGDMA_VIDEO_ENCODE;
        #endif/*#ifdef TV_OUT_SUPPORT */
        #ifdef __SYNC_LCM_SW_SUPPORT__
        if (sync_lcm_enable_mode==KAL_TRUE)
        {
            preview_frame_buffer_swap=0;
            preview_frame_update_flag=KAL_FALSE;
        }
        #endif
   }

    RESET_CRZ;
    /* reconfigure CRZ */
    SET_CRZ_SRC_SIZE(preview_para->image_src_width, preview_para->image_src_height);
    if (preview_para->image_src_width == crz_out_width)
        REG_CRZ_H_RATIO = 1 << RESZ_H_RATIO_SHIFT_BITS;
    else
        REG_CRZ_H_RATIO = ((1 << RESZ_H_RATIO_SHIFT_BITS) / crz_out_width) * preview_para->image_src_width;
    if (preview_para->image_src_height == crz_out_height)
        REG_CRZ_V_RATIO = (1 << RESZ_V_RATIO_SHIFT_BITS);
    else
        REG_CRZ_V_RATIO = ((1 << RESZ_V_RATIO_SHIFT_BITS) / crz_out_height) * preview_para->image_src_height;
    //      REG_CRZ_H_RATIO=(preview_para->image_src_width<<RESZ_H_RATIO_SHIFT_BITS)/crz_out_width;
    //      REG_CRZ_V_RATIO=(preview_para->image_src_height<<RESZ_V_RATIO_SHIFT_BITS)/crz_out_height;
    REG_CRZ_H_RESIDUAL = preview_para->image_src_width % crz_out_width;
    REG_CRZ_V_RESIDUAL = preview_para->image_src_height % crz_out_height;
    ENABLE_CRZ;
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
void close_camera_preview_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    RESET_CRZ;
    image_data_path_reset_delay(1000);
    STOP_IBR2;
    image_data_path_reset_delay(1000);
    STOP_IBW3;
    image_data_path_reset_delay(1000);
    STOP_IBW4;
    image_data_path_reset_delay(1000);
    STOP_IMGDMA_VIDEO_ENCODE;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    *((volatile unsigned int*)0x80610090) &= ~0x200;
    image_data_path_reset_delay(1000);
    STOP_DRZ;
    image_data_path_reset_delay(1000);
    STOP_IBW1;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
#if defined(TV_OUT_SUPPORT) && defined(__MTK_TARGET__)
    if ((camera_preview_config_data.tv_output == KAL_TRUE) && (tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE4))
        g2d_end(G2D_OWNER_LCD);
    #endif
}   /* close_camera_preview_data_path_legacy_series() */
/*****************************************************************************
 * FUNCTION
 *  config_camera_capture_jpeg_data_path_legacy_series
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  capture_para        [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 config_camera_capture_jpeg_data_path_legacy_series(
            MMDI_SCENERIO_ID scenario_id,
            camera_capture_jpeg_data_path_struct *capture_para)
{
    kal_uint8 thumbnail_ratio_w, thumbnail_ratio_h;
    IMGDMA_IBW1_STRUCT ibw1_struct;
    IMGDMA_IBW2_STRUCT ibw2_struct;
    IMGDMA_IBW3_STRUCT ibw3_struct;
    IMGDMA_IBR2_STRUCT ibr2_struct;
   RESZ_DRZ_STRUCT drz_struct;
    IMGDMA_JPEG_DMA_STRUCT jpeg_dma_struct;
   RESZ_CRZ_STRUCT crz_struct;
   RESZ_PRZ_STRUCT prz_struct;

    if (current_image_data_path_owner != scenario_id)
        ASSERT(0);
    if (scenario_id != SCENARIO_CAMERA_CAPTURE_JPEG_ID)
        ASSERT(0);

    if (capture_para->image_capture_width * capture_para->image_capture_height >= 1300000)
    {
        capture_para->thumbnail_mode = KAL_TRUE;
        /* make sure the thumbnail size < 160*120 */
        if ((capture_para->image_capture_width % 160) == 0)
        {
            thumbnail_ratio_w = capture_para->image_capture_width / 160;
        }
        else
        {
            thumbnail_ratio_w = capture_para->image_capture_width / 160 + 1;
        }
        if ((capture_para->image_capture_height % 120) == 0)
        {
            thumbnail_ratio_h = capture_para->image_capture_height / 120;
        }
        else
        {
            thumbnail_ratio_h = capture_para->image_capture_height / 120 + 1;
        }
        /*use the smaller one to get the bigger thumbnail */
        if (thumbnail_ratio_w > thumbnail_ratio_h)
        {
            thumbnail_ratio_w = thumbnail_ratio_h;
        }
        /*width and height must use the same ratio, otherwise thumbnail will be strange*/
        capture_para->thumbnail_width = capture_para->image_capture_width / thumbnail_ratio_w;
        capture_para->thumbnail_height = capture_para->image_capture_height / thumbnail_ratio_w;
    }
    else
    {
        capture_para->thumbnail_mode = KAL_FALSE;
    }
    current_captured_file_number = 0;
    camera_capture_jpeg_config_data.snapshot_number = capture_para->snapshot_number;
    camera_capture_jpeg_config_data.jpeg_file_info = capture_para->jpeg_file_info;
    camera_capture_jpeg_config_data.cam_capture_jpeg_cb = capture_para->cam_capture_jpeg_cb;

    intmem_init((kal_uint32*) capture_para->intmem_start_address, capture_para->intmem_size);
    extmem_init((kal_uint32*) capture_para->extmem_start_address, capture_para->extmem_size);

   /*XXXXX config CRZ */
   crz_struct.image_src=RESZ_SOURCE_ISP;
   crz_struct.dedicate_memory=KAL_TRUE;
    if (capture_para->snapshot_number == 1)
      crz_struct.continous=KAL_FALSE;
    else
      crz_struct.continous=KAL_TRUE;
   crz_struct.int_en=KAL_FALSE;
   crz_struct.src_height=capture_para->image_src_height;
   crz_struct.src_width=capture_para->image_src_width;
   crz_struct.tar_height=capture_para->image_capture_height;
   crz_struct.tar_width=capture_para->image_capture_width;
   crz_struct.work_mem_line=4;
   crz_struct.work_mem_addr=0x40000000;/* dummy for hardware issue */

   RESZ_CRZConfig(&crz_struct);

    /* XXXXXO config IBR2 */

    if (capture_para->snapshot_number == 1)
    {
        ibr2_struct.restart = KAL_FALSE;
    }
    else
    {
        ibr2_struct.restart = KAL_TRUE;
    }
    ibr2_struct.int_en = KAL_FALSE;
    ibr2_struct.pixel_engine = PIXEL_ENGINE_CRZ;
    if (capture_para->overlay_frame_mode == KAL_TRUE)
    {
        ibr2_struct.overlay_frame_mode = KAL_TRUE;
        ibr2_struct.overlay_frame_buffer_address = capture_para->overlay_frame_buffer_address;
        ibr2_struct.overlay_frame_width = capture_para->overlay_frame_width;
        ibr2_struct.overlay_frame_height = capture_para->overlay_frame_height;
        ibr2_struct.overlay_frame_target_width = capture_para->image_capture_width;
        ibr2_struct.overlay_frame_target_height = capture_para->image_capture_height;
        ibr2_struct.overlay_color_depth = capture_para->overlay_color_depth;
        ibr2_struct.overlay_frame_source_key = capture_para->overlay_frame_source_key;
    }
    else
    {
        ibr2_struct.overlay_frame_mode = KAL_FALSE;
    }
    IMGDMA_IBR2Config(&ibr2_struct);
    /* config IPP */
    RESET_IPP;
    ENABLE_IPP;
    SET_IPP_GRAPH_MODE(IPP_CAPTURE_MODE);
    SET_IPP_HUE_SAT(IPP_HUE_SAT_ADJUST_EFFECT);
    if (capture_para->thumbnail_mode == KAL_TRUE)
    {   /* add thumbnail */
        /* XXXXXO config IBW3 */
        ibw3_struct.pixel_engine = PIXEL_ENGINE_CRZ;
        if (capture_para->snapshot_number == 1)
        {
            ibw3_struct.auto_restart = KAL_FALSE;
        }
        else
        {
            ibw3_struct.auto_restart = KAL_TRUE;
        }
        ibw3_struct.int_en = KAL_FALSE;
        ibw3_struct.width = capture_para->image_capture_width - 1;
        ibw3_struct.height = capture_para->image_capture_height - 1;
        IMGDMA_IBW3Config(&ibw3_struct);
      /*XXXXX config DRZ */
      drz_struct.image_src=RESZ_SOURCE_IBW3;
        if (capture_para->snapshot_number == 1)
            drz_struct.auto_restart=KAL_FALSE;
        else
         drz_struct.auto_restart=KAL_TRUE;

      drz_struct.int_en=KAL_FALSE;
      drz_struct.src_height=capture_para->image_capture_height;
      drz_struct.src_width=capture_para->image_capture_width;
      drz_struct.tar_height=capture_para->thumbnail_height;
      drz_struct.tar_width=capture_para->thumbnail_width;

      RESZ_DRZConfig(&drz_struct);

        /* config IPP2 */
        ENABLE_THUMBNAIL_OUTPUT;

        /* XXXXXO config IBW1 */
        ibw1_struct.pixel_engine = PIXEL_ENGINE_IPP2;
        ibw1_struct.output_format = SET_IBW1_OUTPUT_RGB888;
        if (capture_para->snapshot_number == 1)
            ibw1_struct.auto_restart = KAL_FALSE;
        else
            ibw1_struct.auto_restart = KAL_TRUE;
        ibw1_struct.bs = (capture_para->jpeg_file_start_address1 + 20);
        ibw1_struct.width = (capture_para->thumbnail_width - 1);
        ibw1_struct.height = (capture_para->thumbnail_height - 1);
        IMGDMA_IBW1Config(&ibw1_struct);
    }
    if (capture_para->display == KAL_TRUE)
    {
        /* configure IBW4 */
        STOP_IBW4;
        SET_IBW4_PIXEL_SRC_CRZ;
        if (capture_para->snapshot_number == 1)
        {
            DISABLE_IBW4_AUTO_RESTART;
        }
        else
        {
            ENABLE_IBW4_AUTO_RESTART;
        }
        DISABLE_IBW4_INT;
        REG_IMGDMA_IBW4_WIDTH = capture_para->image_capture_width - 1;
        REG_IMGDMA_IBW4_HEIGHT = capture_para->image_capture_height - 1;
        START_IBW4;

      /*XXXXX config PRZ */

      prz_struct.image_src=RESZ_SOURCE_IBW4;
      prz_struct.dedicate_memory=KAL_FALSE;
        if (capture_para->snapshot_number == 1)
         prz_struct.continous=KAL_FALSE;
        else
         prz_struct.continous=KAL_TRUE;
      prz_struct.int_en=KAL_FALSE;
      prz_struct.output_2_IPP=KAL_TRUE;
      prz_struct.coarse_en=KAL_FALSE;
      prz_struct.src_height=capture_para->image_capture_height;
      prz_struct.src_width=capture_para->image_capture_width;
      prz_struct.tar_height=capture_para->display_height;
      prz_struct.tar_width=capture_para->display_width;
      prz_struct.work_mem_line=4;
      if((prz_struct.tar_width%2)==0)
      prz_struct.work_mem_addr=(kal_uint32) intmem_get_buffer((capture_para->display_width * RESIZER_WORKING_MEM_LINE_NUMBER *3));
      else
            prz_struct.work_mem_addr=(kal_uint32) intmem_get_buffer(((capture_para->display_width+1) * RESIZER_WORKING_MEM_LINE_NUMBER *3));

      RESZ_PRZConfig(&prz_struct);

        /* XXXXXO config IBW2 */

        if (capture_para->image_pitch_mode == KAL_TRUE)
        {
            ibw2_struct.pitch = KAL_TRUE;
            ibw2_struct.pitch1_bytes = capture_para->image_pitch_bytes;
            ibw2_struct.pitch2_bytes = capture_para->image_pitch_bytes;
        }
        else
        {
            ibw2_struct.pitch = KAL_FALSE;
        }

        ibw2_struct.dest_color_mode = capture_para->image_data_format;
        ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;
        ibw2_struct.lcd_trigger = KAL_TRUE;
        ibw2_struct.direct_couple = KAL_FALSE;
        ibw2_struct.int_en = KAL_FALSE;
        if (capture_para->snapshot_number == 1)
        {
            ibw2_struct.restart = KAL_FALSE;
        }
        else
        {
            ibw2_struct.restart = KAL_TRUE;
        }
        ibw2_struct.frame1_base_addr = capture_para->frame_buffer_address;
        ibw2_struct.frame2_base_addr = capture_para->frame_buffer_address;
        ibw2_struct.width = capture_para->display_width;//image_capture_width;
        ibw2_struct.height = capture_para->display_height;//image_capture_height;
        ibw2_struct.pan = KAL_FALSE;

        ibw2_struct.enable_IBW2 = KAL_TRUE;
        ibw2_struct.cb = NULL;

        IMGDMA_IBW2Config(&ibw2_struct);
    }

    /* XXXXXO config JPEG DMA */
    jpeg_dma_struct.pixel_engine = PIXEL_ENGINE_CRZ;
    jpeg_dma_struct.jpeg_yuv_mode = capture_para->jpeg_yuv_mode;
    if (capture_para->jpeg_yuv_mode == JPEG_FORMAT_YUV420)
    {
        jpeg_dma_struct.jpeg_file_buffer_address =
            (kal_uint32)
            intmem_get_buffer((JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER *
                               ((capture_para->image_capture_width & 0xFFF0) + 16)) * 3 / 2);
    }
    else
    {
        jpeg_dma_struct.jpeg_file_buffer_address =
            (kal_uint32)
            intmem_get_buffer((JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER *
                               ((capture_para->image_capture_width & 0xFFF0) + 16)) << 1);
    }
    if (capture_para->snapshot_number > 1)
    {
        jpeg_dma_struct.restart = KAL_TRUE;
    }
    else
    {
        jpeg_dma_struct.restart = KAL_FALSE;
    }
    jpeg_dma_struct.target_width = capture_para->image_capture_width;
    jpeg_dma_struct.target_height = capture_para->image_capture_height;

    IMGDMA_JPEGDMAConfig(&jpeg_dma_struct);

    config_jpeg_capture_path(capture_para);
    return 0;
}   /* config_camera_capture_jpeg_data_path_legacy_series() */
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
void close_camera_capture_jpeg_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    RESET_CRZ;
    image_data_path_reset_delay(1000);
    STOP_IBR2;
    image_data_path_reset_delay(1000);
    STOP_IBW4;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
    image_data_path_reset_delay(1000);
    STOP_IMGDMA_JPEG;
    image_data_path_reset_delay(1000);
    STOP_IBW3;
    image_data_path_reset_delay(1000);
    STOP_DRZ;
    image_data_path_reset_delay(1000);
    STOP_IBW1;
    image_data_path_reset_delay(1000);
    close_jpeg_module(KAL_TRUE, KAL_FALSE, KAL_FALSE);  /* encode+decode, not power down */
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
 kal_uint8 config_camera_capture_barcode_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, camera_capture_barcode_data_path_struct *capture_para)
{

    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_CAMERA_CAPTURE_BARCODE_ID)
    {
        ASSERT(0);
    }

    intmem_init((kal_uint32*) capture_para->intmem_start_address, capture_para->intmem_size);
    extmem_init((kal_uint32*) capture_para->extmem_start_address, capture_para->extmem_size);

    /* config CRZ */
    RESET_CRZ;
    REG_CRZ_CTRL = 0;
    SET_CRZ_DEDICATED_MEMORY;
    SET_CRZ_PIXEL_BASED_IMAGE;
    SET_CRZ_CONT_RUN_MODE;
    SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_CAMERA_ISP);
    DISABLE_CRZ_H_RESIZE_INT;
    DISABLE_CRZ_V_RESIZE_INT;

    SET_CRZ_SRC_SIZE(capture_para->image_src_width, capture_para->image_src_height);
    /* set target size as the multiples of overlay frame buffer */
    SET_CRZ_TARGET_SIZE(capture_para->barcode_image_width, capture_para->barcode_image_height);
    if (capture_para->image_src_width == capture_para->barcode_image_width)
    {
        REG_CRZ_H_RATIO = 1 << RESZ_H_RATIO_SHIFT_BITS;
     }
    else
    {
   REG_CRZ_H_RATIO=((1<<RESZ_H_RATIO_SHIFT_BITS)/capture_para->barcode_image_width)*capture_para->image_src_width;
    }
    if (capture_para->image_src_height == capture_para->barcode_image_height)
    {
        REG_CRZ_V_RATIO = (1 << RESZ_V_RATIO_SHIFT_BITS);
     }
    else
     {
      REG_CRZ_V_RATIO=((1<<RESZ_V_RATIO_SHIFT_BITS)/capture_para->barcode_image_height)*capture_para->image_src_height;
     }
    REG_CRZ_H_RESIDUAL = capture_para->image_src_width % capture_para->barcode_image_width;
    REG_CRZ_V_RESIDUAL = capture_para->image_src_height % capture_para->barcode_image_height;
    REG_CRZ_FINE_RESIZE_CFG = 0;
    SET_CRZ_FINE_RESIZE_WORK_MEM_SIZE(16);
    REG_CRZ_WORK_MEM_ADDR = 0x40000000; /* dummy for hardware issue */
    ENABLE_CRZ;

    /* config IBR2 */
    STOP_IBR2;
    SET_IMGDMA_IBR2_SRC_CRZ;
    ENABLE_IMGDMA_IBR2_AUTO_RESTART;
    DISABLE_IMGDMA_IBR2_INT;
    DISABLE_IMGDMA_IBR2_PALETTE;

    /* config IPP */
    RESET_IPP;
    ENABLE_IPP;
    SET_IPP_GRAPH_MODE(IPP_CAPTURE_MODE);

   /* configure IBW4 */
   STOP_IBW4;
   SET_IBW4_PIXEL_SRC_CRZ;
   ENABLE_IBW4_AUTO_RESTART;//DISABLE_IBW4_AUTO_RESTART;
   ENABLE_IBW4_INT;//DISABLE_IBW4_INT;
   REG_IMGDMA_IBW4_WIDTH = capture_para->barcode_image_width-1;
   REG_IMGDMA_IBW4_HEIGHT = capture_para->barcode_image_height-1;
   START_IBW4;
   /* config PRZ */
   RESET_PRZ;
   SET_PRZ_PIXEL_MODE;
   SET_PRZ_SHARED_MEMORY;
   SET_PRZ_CONT_MODE;
   SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_IBW4_DMA);
   SET_PRZ_SRC_SIZE(capture_para->barcode_image_width, capture_para->barcode_image_height);
   SET_PRZ_TARGET_SIZE(capture_para->display_width,capture_para->display_height);

   if (capture_para->barcode_image_width==capture_para->display_width)
      REG_PRZ_H_RATIO=1<<RESZ_H_RATIO_SHIFT_BITS;
   else
      REG_PRZ_H_RATIO=((1<<RESZ_H_RATIO_SHIFT_BITS)/capture_para->display_width)*capture_para->barcode_image_width;

   if (capture_para->barcode_image_height==capture_para->display_height)
      REG_PRZ_V_RATIO=(1<<RESZ_V_RATIO_SHIFT_BITS);
   else
      REG_PRZ_V_RATIO=((1<<RESZ_V_RATIO_SHIFT_BITS)/capture_para->display_height)*capture_para->barcode_image_height;

   REG_PRZ_H_RESIDUAL=capture_para->barcode_image_width%capture_para->display_width;
   REG_PRZ_V_RESIDUAL=capture_para->barcode_image_height%capture_para->display_height;

   REG_PRZ_WORK_MEM_ADDR=(kal_uint32) intmem_get_buffer((capture_para->barcode_image_width * RESIZER_WORKING_MEM_LINE_NUMBER *3));
   REG_PRZ_FINE_RESIZE_CFG=0;
   SET_PRZ_FINE_RESIZE_OUTPUT_IPP;
   SET_PRZ_FINE_RESIZE_WORK_MEM_SIZE(RESIZER_WORKING_MEM_LINE_NUMBER);

   ENABLE_PRZ_H_LINE;
   ENABLE_PRZ_V_LINE;

    /* config IPP2 */
    ENABLE_THUMBNAIL_OUTPUT;

    /* configure IBW2 */
    STOP_IBW2;
    REG_IMGDMA_IBW2_CTRL = 0;
   SET_IBW2_PIXEL_SRC_IPP1;
    REG_IMGDMA_IBW2_BASE_ADDR1 = capture_para->frame_buffer_address;
    REG_IMGDMA_IBW2_BASE_ADDR2 = capture_para->frame_buffer_address1;
    REG_IMGDMA_IBW2_WIDTH = capture_para->display_width - 1;
    REG_IMGDMA_IBW2_HEIGHT = capture_para->display_height - 1;
    if (capture_para->image_pitch_mode == KAL_TRUE)
    {
        ENABLE_IBW2_DEST_PITCH;
        REG_IMGDMA_IBW2_DEST_PITCH1 = capture_para->image_pitch_bytes;
        REG_IMGDMA_IBW2_DEST_PITCH2 = capture_para->image_pitch_bytes;
    }
    else
    {
        DISABLE_IBW2_DEST_PITCH;
    }

    if (capture_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB565)
    {
        SET_IBW2_OUTPUT_RGB565;
    }
    else if (capture_para->image_data_format == IMGDMA_IBW_OUTPUT_RGB888)
    {
        SET_IBW2_OUTPUT_RGB888;
    }
    ENABLE_IBW2_TRIGGER_LCD;
    DISABLE_IBW2_INT;
    DISABLE_IBW2_PAN;
    DISABLE_IBW2_DC;
    ENABLE_IBW2_AUTO_RESTART;
    ibw2_cb = NULL;
    START_IBW2;

   /*capture to barcode image*/
   /*config IBW3*/
   STOP_IBW3;
   SET_IBW3_PIXEL_SRC_CRZ;
   DISABLE_IBW3_AUTO_RESTART;
   DISABLE_IBW3_INT;
   REG_IMGDMA_IBW3_WIDTH = capture_para->barcode_image_width-1;
   REG_IMGDMA_IBW3_HEIGHT = capture_para->barcode_image_height-1;

   /* config DRZ */
   STOP_DRZ;
   SET_DRZ_SRC_IBW3_DMA;
   //DISABLE_DRZ_AUTO_RESTART;
   /*to cover HW bug, otherwise it will lost some points even
     in 1:1 resize*/
   ENABLE_DRZ_AUTO_RESTART;
   DISABLE_DRZ_INT;

   REG_DRZ_SOURCE_IMAGE_SIZE=((capture_para->barcode_image_height-1)<<16)|(capture_para->barcode_image_width-1);
   REG_DRZ_TARGET_IMAGE_SIZE=((capture_para->barcode_image_height-1)<<16)|(capture_para->barcode_image_width-1);
   REG_DRZ_H_RATIO=((1)<<16)|(0);
   REG_DRZ_V_RATIO=((1)<<16)|(0);

   /* config IBW1 */
    STOP_IBW1;
    REG_IMGDMA_IBW1_CTRL = 0;
    REG_IMGDMA_IBW1_BASE_ADDR1 = capture_para->barcode_buffer_address;
    REG_IMGDMA_IBW1_BASE_ADDR2 = capture_para->barcode_buffer_address;
    REG_IMGDMA_IBW1_WIDTH = capture_para->barcode_image_width - 1;
    REG_IMGDMA_IBW1_HEIGHT = capture_para->barcode_image_height - 1;

    SET_IBW1_PIXEL_SRC_IPP2;//new

    DISABLE_IBW1_DEST_PITCH;
    SET_IBW1_OUTPUT_RGB565;
    DISABLE_IBW1_TRIGGER_LCD;
    DISABLE_IBW1_INT;
    DISABLE_IBW1_PAN;
    DISABLE_IBW1_DC;
    DISABLE_IBW1_AUTO_RESTART;

    return 0;
}   /* config_camera_capture_barcode_data_path() */

volatile kal_bool ibw3_complete_flag = KAL_FALSE;
volatile kal_bool wait_ibw3_complete = KAL_FALSE;
volatile kal_bool ibw4_complete_flag=KAL_FALSE;
volatile kal_bool wait_ibw4_complete=KAL_FALSE;
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
void get_barcode_image_legacy_series(void)
{
   kal_uint32 save_irq_mask;

   save_irq_mask=SaveAndSetIRQMask();
   wait_ibw4_complete=KAL_TRUE;
   RestoreIRQMask(save_irq_mask);
   while (ibw4_complete_flag==KAL_FALSE)
   {};
   START_IBW1;
   START_DRZ;
   START_IBW3;
   while (IMGDMA_IBW1_IS_BUSY)
   {
      kal_sleep_task(1);
   };
   save_irq_mask=SaveAndSetIRQMask();
   ibw4_complete_flag=KAL_FALSE;
   wait_ibw4_complete=KAL_FALSE;
   RestoreIRQMask(save_irq_mask);
   STOP_IBW3;
   STOP_DRZ;
   STOP_IBW1;
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
void close_camera_capture_barcode_data_path_legacy_series(void)
{
    image_data_path_reset_delay(1000);
    RESET_CRZ;
    image_data_path_reset_delay(1000);
    STOP_IBR2;
    image_data_path_reset_delay(1000);
    STOP_IBW4;
    image_data_path_reset_delay(1000);
    RESET_PRZ;
    image_data_path_reset_delay(1000);
    RESET_IPP;
    image_data_path_reset_delay(1000);
    DISABLE_IPP;
    image_data_path_reset_delay(1000);
    STOP_IBW2;
    image_data_path_reset_delay(1000);
    STOP_IBW3;
    image_data_path_reset_delay(1000);
    STOP_DRZ;
    image_data_path_reset_delay(1000);
    STOP_IBW1;
}   /* close_camera_capture_barcode_data_path() */

///web cam

kal_uint8 config_camera_usbvideo_jpeg_data_path_legacy_series(
  MMDI_SCENERIO_ID scenario_id,
  camera_capture_jpeg_data_path_struct *capture_para)
{
#if (defined(WEBCAM_SUPPORT))
  IMGDMA_IBR2_STRUCT ibr2_struct;
  IMGDMA_JPEG_DMA_STRUCT jpeg_dma_struct;
  RESZ_CRZ_STRUCT crz_struct;

  if (current_image_data_path_owner != scenario_id)
  {
    ASSERT(0);
  }

  if (scenario_id != SCENARIO_USBVIDEO_CAPTURE_JPEG_ID)
  {
    ASSERT(0);
  }
  /* configure callback function */
  camera_capture_jpeg_config_data.cam_capture_jpeg_cb = capture_para->cam_capture_jpeg_cb;

  intmem_init((kal_uint32*) capture_para->intmem_start_address, capture_para->intmem_size);
  extmem_init((kal_uint32*) capture_para->extmem_start_address, capture_para->extmem_size);

  /*XXXXX config CRZ */
  crz_struct.image_src=RESZ_SOURCE_ISP;
  crz_struct.dedicate_memory=KAL_FALSE;
  crz_struct.continous=KAL_FALSE;
  crz_struct.int_en=KAL_FALSE;
  crz_struct.src_height=capture_para->image_src_height;
  crz_struct.src_width=capture_para->image_src_width;
  crz_struct.tar_height=capture_para->image_capture_height;
  crz_struct.tar_width=capture_para->image_capture_width;
  crz_struct.work_mem_line=4;
  crz_struct.work_mem_addr=(kal_uint32) intmem_get_buffer((4*((capture_para->image_capture_width&0xFFF0)+16))*3);

  RESZ_CRZConfig(&crz_struct);

  /* XXXXXO config IBR2 */
  ibr2_struct.restart = KAL_FALSE;
  ibr2_struct.int_en = KAL_FALSE;
  ibr2_struct.pixel_engine = PIXEL_ENGINE_CRZ;
  ibr2_struct.overlay_frame_mode = KAL_FALSE;

  IMGDMA_IBR2Config(&ibr2_struct);
  /* config IPP */
  RESET_IPP;
  ENABLE_IPP;
  SET_IPP_GRAPH_MODE(IPP_CAPTURE_MODE);
  //      SET_IPP_HUE_SAT(IPP_HUE_SAT_ADJUST_EFFECT);     // No IPP effect for MT6228/9
  //      ENABLE_IPP_CONTRAST_BRIGHT;

  /* XXXXXO config JPEG DMA */
  jpeg_dma_struct.pixel_engine = PIXEL_ENGINE_CRZ;
  jpeg_dma_struct.jpeg_yuv_mode = capture_para->jpeg_yuv_mode;
  if (capture_para->jpeg_yuv_mode == JPEG_FORMAT_YUV420)
  {
    jpeg_dma_struct.jpeg_file_buffer_address =
      (kal_uint32)
      intmem_get_buffer((JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER *
                         ((capture_para->image_capture_width & 0xFFF0) + 16)) * 3 / 2);
  }
  else
  {
    jpeg_dma_struct.jpeg_file_buffer_address =
      (kal_uint32)
      intmem_get_buffer((JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER *
                         ((capture_para->image_capture_width & 0xFFF0) + 16)) << 1);
  }
  jpeg_dma_struct.restart = KAL_FALSE;
  jpeg_dma_struct.target_width = capture_para->image_capture_width;
  jpeg_dma_struct.target_height = capture_para->image_capture_height;

  IMGDMA_JPEGDMAConfig(&jpeg_dma_struct);

  config_jpeg_usbvideo_path(capture_para);
#endif /* (defined(WEBCAM_SUPPORT)) */
  return 0;
}   /* config_camera_usbvideo_jpeg_data_path() */


kal_bool open_image_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id)
{
      kal_uint32 save_irq_mask;
    /* special case because MPEG_SNAPSHOT will be active in MPEG4_DECODE period */
    if ((current_image_data_path_owner == SCENARIO_MPEG_DECODE_ID) && (scenario_id == SCENARIO_MPEG_SNAPSHOT_ID))
        return KAL_TRUE;

    if (current_image_data_path_owner != SCENARIO_UNKNOW_ID)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    /// Turn on PRZ clock
    DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_PRZ;
    /// Turn on resizer dedicated line buffer clock
    DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_RESZLB;
    /// Turn on CRZ clock
    DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_CRZ;
    /// Turn on DRZ clock
    DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_DRZ;
    /// Turn on image processor clock
    DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_IMGPROC;
    /// Turn on image DMA clock
    DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_IMGDMA;

    save_irq_mask = SaveAndSetIRQMask();
    current_image_data_path_owner = scenario_id;
    RestoreIRQMask(save_irq_mask);

#ifdef MTK_SLEEP_ENABLE
    if (image_data_path_sleep_mode_handler == 0xFF)
      image_data_path_sleep_mode_handler = L1SM_GetHandle();
    L1SM_SleepDisable(image_data_path_sleep_mode_handler);
#endif
    if ((scenario_id == SCENARIO_CAMERA_CAPTURE_JPEG_ID) ||
        (scenario_id == SCENARIO_JPEG_ENCODE_ID) ||
        (scenario_id == SCENARIO_JPEG_DECODE_ID) || (scenario_id == SCENARIO_JPEG_RESIZE_ID) ||
#if (defined(WEBCAM_SUPPORT))
        (scenario_id == SCENARIO_USBVIDEO_CAPTURE_JPEG_ID) ||
#endif
        (scenario_id == SCENARIO_MPEG_SNAPSHOT_ID))
    {
        jpeg_codec_power_up();
    }

    if (scenario_id == SCENARIO_IMG_EFFECT_ID)
    {   /* enable IPP for configure the parameters of IPP */
        RESET_IPP;
        ENABLE_IPP;
        IPP_CTRL_REG = 0;
    }

   #ifdef __SYNC_LCM_SW_SUPPORT__
   if ((scenario_id==SCENARIO_CAMERA_PREVIEW_ID)||(scenario_id==SCENARIO_MPEG_ENCODE_ID)||
       (scenario_id==SCENARIO_MPEG_DECODE_ID))
      sync_lcm_enable_mode=KAL_TRUE;
      EINT_UnMask(sync_lcm_channel_number);
   #endif

    return KAL_TRUE;
}   /* open_image_data_path() */

void close_image_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id)
{
    kal_uint32 save_irq_mask;
    kal_uint32 reg;
    if (scenario_id == SCENARIO_MPEG_SNAPSHOT_ID)
    {   /* special case because MPEG_SNAPSHOT will be active in MPEG4_DECODE period */
        close_jpeg_encode_data_path();
        current_image_data_path_owner = SCENARIO_UNKNOW_ID;
        return;
    }

    if (current_image_data_path_owner != scenario_id)
        ASSERT(0);

    switch (scenario_id)
    {
        case SCENARIO_CAMERA_PREVIEW_ID:
            close_camera_preview_data_path();
            break;
    #if (defined(WEBCAM_SUPPORT))
        case SCENARIO_USBVIDEO_CAPTURE_JPEG_ID:
    #endif
        case SCENARIO_CAMERA_CAPTURE_JPEG_ID:
            close_camera_capture_jpeg_data_path();
            break;
        case SCENARIO_CAMERA_CAPTURE_MEM_ID:
            close_camera_capture_mem_data_path();
            break;
        case SCENARIO_CAMERA_CAPTURE_BARCODE_ID:
            close_camera_capture_barcode_data_path();
            break;
        case SCENARIO_MPEG_ENCODE_ID:
            close_video_encode_data_path();
            break;
        case SCENARIO_MPEG_DECODE_ID:
            close_video_decode_data_path();
            break;
        case SCENARIO_JPEG_DECODE_ID:
            close_jpeg_decode_data_path();
            break;
        case SCENARIO_JPEG_ENCODE_ID:
            close_jpeg_encode_data_path();
            break;
        case SCENARIO_JPEG_RESIZE_ID:
            close_jpeg_resize_data_path();
            break;
        case SCENARIO_IMG_EFFECT_ID:
            close_image_effect_data_path();
            break;
        case SCENARIO_RESIZE_ID:
            close_image_resize_data_path();
            break;        
        case SCENARIO_RGB2YUV420_ID:
            stop_RGB2YUV420_data_path();
            break;
        #ifdef __VIDEO_EDITOR__        
        case SCENARIO_VIDEO_EDITOR_ID:
            close_video_editor_data_path();
            break;
        #endif    
        #ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif/*__3G_VIDEO_CALL__*/    
    }
    /* release dedicated memory */
    SET_PRZ_SHARED_MEMORY;
    SET_CRZ_SHARED_MEMORY;

    save_irq_mask = SaveAndSetIRQMask();

    /*IMGDMA*/
    reg = DRV_Reg32(IMGDMA_STATUS_REG);
    REG_IMGDMA_INT_ACK=0xffff;
    /*IMGPROC*/
    reg = DRV_Reg32(IMGPROC_INTR);
    /*PRZ*/
    reg = DRV_Reg32(PRZ_INT_STATUS_REG);
    /*CRZ*/
    reg = DRV_Reg32(CRZ_INT_STATUS_REG);
    /*DRZ*/
    REG_DRZ_INT_ACK=0xffff;

    RestoreIRQMask(save_irq_mask);

    /// Turn off PRZ clock
    DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_PRZ;
    /// Turn off resizer dedicated line buffer clock
    DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_RESZLB;
    /// Turn off CRZ clock
    DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_CRZ;
    /// Turn off DRZ clock
    DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_DRZ;
    /// Turn off image processor clock
    DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_IMGPROC;
    /// Turn off image DMA clock
    DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_IMGDMA;


    current_image_data_path_owner = SCENARIO_UNKNOW_ID;
    #ifdef TV_OUT_SUPPORT
      tv_output_owner = TV_OUT_OWNER_MMI;
    #endif  //TV_OUT_SUPPORT
    #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepEnable(image_data_path_sleep_mode_handler);
    #endif //MTK_SLEEP_ENABLE

    {
       if (scenario_id != SCENARIO_MPEG_DECODE_ID && scenario_id != SCENARIO_RGB2YUV420_ID
           && scenario_id != SCENARIO_VIDEO_EDITOR_ID)
    {
        if (scenario_id != SCENARIO_MPEG_ENCODE_ID)
        {
           intmem_deinit();
           extmem_deinit();
        }
        else
        {
           if(release_mpeg4_mem())
           {
        intmem_deinit();
        extmem_deinit();
    }
        }
    }
    }
    #ifdef __SYNC_LCM_SW_SUPPORT__
    sync_lcm_enable_mode=KAL_FALSE;
    sync_lcm_update_cb=NULL;
    EINT_Mask(sync_lcm_channel_number);
    #endif
}   /* close_image_data_path() */

#endif /* defined(DRV_IDP_6228_SERIES) */

#if (defined(DRV_IDP_6228_SERIES)||defined(DRV_IDP_6219_SERIES))
kal_uint8 image_resize_process_legacy_series(resize_struct *resize_para)
{
   MMDI_SCENERIO_ID scenario_id=SCENARIO_RESIZE_ID;

   kal_uint8 result;
   if ((resize_para->src_height==1)||(resize_para->src_width==1))
      return KAL_FALSE;       /* Hardware resize can not process the case that source image height is 1 */



#if (defined(DRV_JPG_DATA_PATH_19_SERIES))
   intmem_init((kal_uint32 *) resize_para->intmem_start_address,resize_para->intmem_size);
   extmem_init((kal_uint32 *) resize_para->extmem_start_address,resize_para->extmem_size);
#endif

   image_resize_data.type=resize_para->type;
   image_resize_data.data_order=resize_para->data_order;

   image_resize_data.src_image_address=resize_para->src_image_address;
   image_resize_data.dest_image_address=resize_para->dest_image_address;
   image_resize_data.dest_buffer_size=resize_para->dest_buffer_size;
   image_resize_data.src_width=resize_para->src_width;
   image_resize_data.src_height=resize_para->src_height;
   image_resize_data.src_pitch=resize_para->src_pitch;
   image_resize_data.target_width=resize_para->target_width;
   image_resize_data.target_height=resize_para->target_height;
   if (resize_para->src_pitch==resize_para->src_width)
      image_resize_data.target_pitch=resize_para->target_width;
   else
      image_resize_data.target_pitch=resize_para->target_width * (resize_para->src_pitch-1)/(resize_para->src_width-1)+1;
   image_resize_data.image_clip_x1=resize_para->image_clip_x1;
   image_resize_data.image_clip_x2=resize_para->image_clip_x2;
   image_resize_data.image_clip_y1=resize_para->image_clip_y1;
   image_resize_data.image_clip_y2=resize_para->image_clip_y2;
#if (defined(DRV_IMG_RGB888_OUTPUT_SUPPORT))
   image_resize_data.image_data_format=resize_para->image_data_format;
#endif

#if (defined(DRV_IMG_PITCH_MODE_SUPPORT))
   image_resize_data.image_pitch_mode=resize_para->image_pitch_mode;
   image_resize_data.image_pitch_bytes=resize_para->image_pitch_bytes;
#endif
   if ((((resize_para->image_clip_x2-resize_para->image_clip_x1+1)*
         (resize_para->image_clip_y2-resize_para->image_clip_y1+1))<<1)>resize_para->dest_buffer_size)
      ASSERT(0);

   #if (defined(DRV_JPG_DATA_PATH_19_SERIES))
   config_image_processor(scenario_id);
   config_pixel_resizer(scenario_id);
   config_image_dma(scenario_id,0,0);
   while (IMGDMA_CheckBusy(IMGDMA_IBW2_CH,scenario_id)) {};
   #elif (defined(DRV_JPG_DATA_PATH_28_SERIES))
   open_image_data_path(scenario_id);
   result=config_image_resize_data_path(scenario_id,&image_resize_data);
   if(result!=0)
   {
    close_image_data_path(scenario_id);
    return KAL_FALSE;
   }

   while (IMGDMA_IBW2_IS_BUSY) {};     /* wait until resize complete */
   #endif

   #if (defined(DRV_JPG_DATA_PATH_19_SERIES))
   stop_image_dma(scenario_id);
   IMGDMA_Close(scenario_id);

   RESZ_Stop(scenario_id);
   RESZ_Close(scenario_id);

   IMGPROC_Stop(scenario_id);
   IMGPROC_Close(scenario_id);
   intmem_deinit();
   extmem_deinit();
   #elif (defined(DRV_JPG_DATA_PATH_28_SERIES))
   close_image_data_path(scenario_id);
   #endif

   return KAL_TRUE;
}  /* image_resize_process() */
#endif

void image_data_path_init_legacy_series(void)
{
#if (defined(DRV_IDP_6219_SERIES) || defined(DRV_IDP_6228_SERIES))
    IMGDMA_Init();
#endif

#if (defined(DRV_IDP_6219_SERIES))
    RESZ_Init();
    IMGPROC_Init();
#elif (defined(DRV_IDP_6228_SERIES))
    IMGPROC_Init();
#elif defined(DRV_IDP_6225_SERIES)
    RESZ_Init();
#endif
}   /* init_image_data_path() */

kal_bool idp_register_app_legacy_series(MMDI_SCENERIO_ID new_app, MMDI_SCENERIO_ID *old_app)
{
#if (defined(DRV_IDP_6219_SERIES))
extern IMGDMA_DCB_STRUCT imgdma_dcb;

   *old_app=imgdma_dcb.owner;

   if (imgdma_dcb.owner == SCENARIO_UNKNOW_ID)/*no exist app*/
   {
      return KAL_TRUE;
   }
   else
   {
      /*MPEG decode and MPEG snapshot can coexist*/
      if ((imgdma_dcb.owner  == SCENARIO_MPEG_DECODE_ID) && (new_app == SCENARIO_MPEG_SNAPSHOT_ID))
         return KAL_TRUE;

      if ((new_app == SCENARIO_MPEG_DECODE_ID) && (imgdma_dcb.owner  == SCENARIO_MPEG_SNAPSHOT_ID))
         return KAL_TRUE;

      return KAL_FALSE;
   }


#elif (defined(DRV_IDP_6228_SERIES))

   *old_app=current_image_data_path_owner;

   if (current_image_data_path_owner == SCENARIO_UNKNOW_ID)/*no exist app*/
   {
      return KAL_TRUE;
   }
   else
   {
      /*MPEG decode and MPEG snapshot can coexist*/
      if ((current_image_data_path_owner == SCENARIO_MPEG_DECODE_ID) && (new_app == SCENARIO_MPEG_SNAPSHOT_ID))
         return KAL_TRUE;

      if ((new_app == SCENARIO_MPEG_DECODE_ID) && (current_image_data_path_owner == SCENARIO_MPEG_SNAPSHOT_ID))
         return KAL_TRUE;

      return KAL_FALSE;
   }
#elif defined(DRV_IDP_6225_SERIES)
   extern RESZ_DCB_STRUCT resz_dcb;
   *old_app=resz_dcb.owner;

   if (resz_dcb.owner == SCENARIO_UNKNOW_ID)/*no exist app*/
   {
      return KAL_TRUE;
   }
   else
   {
      return KAL_FALSE;
   }

#endif
}   /* init_image_data_path() */



#endif
