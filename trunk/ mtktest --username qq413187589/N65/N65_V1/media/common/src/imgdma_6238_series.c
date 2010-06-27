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
 *   imgdma_6238_series.c
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *   image DMA
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"
#include "drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "kal_non_specific_general_types.h"
#include "imgdma_6238_series.h"
#include "intrCtrl.h"
#include "img_comm.h"

/** \brief Initialize the image DMA subsystem.
 *
 * \ingroup imgdma
 *
 * This functino will setup the interrupt for the image DMA
 * to level sensitive, and unmask all the interrupts for the
 * image DMA.
 */
//PLease Wei help check
void image_dma_LISR(void);
void
IMGDMA_Init(void)
{
  IRQ_Register_LISR(IRQ_IMGDMA_CODE, image_dma_LISR, "IMGDMA");
  IRQSensitivity(IRQ_IMGDMA_CODE, LEVEL_SENSITIVE);
  IRQUnmask(IRQ_IMGDMA_CODE);
}

/** \brief Programmers can use this function to config IBW1.
 *
 * \ingroup imgdma_ibw1
 *
 * Before using this function, IBW1 should be turned off.
 *
 * \param ibw1_struct IBW1 config structure
 */
void
IMGDMA_IBW1Config(IMGDMA_IBW1_STRUCT const * const ibw1_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_IBW1_START()) &&
         "You should turn off IBW1 before calling this function.");
  
  REG_IMGDMA_IBW1_CTRL = 0;
  
  if (KAL_TRUE == ibw1_struct->auto_restart)
  {
    ENABLE_IBW1_AUTO_RESTART();
  }
  else
  {
    DISABLE_IBW1_AUTO_RESTART();
  }

  if (KAL_TRUE == ibw1_struct->int_enable)
  {
    ENABLE_IBW1_INT();
  }
  else
  {
    DISABLE_IBW1_INT();
  }
  
  if (KAL_TRUE == ibw1_struct->pitch_enable)
  {
    ENABLE_IBW1_DEST_PITCH();
    
    REG_IMGDMA_IBW1_DEST_PITCH1 = ibw1_struct->pitch1_bytes;
    REG_IMGDMA_IBW1_DEST_PITCH2 = ibw1_struct->pitch2_bytes;
  }
  else
  {
    DISABLE_IBW1_DEST_PITCH();
  }
  
  if (KAL_TRUE == ibw1_struct->lcd_trigger)
  {
    ENABLE_IBW1_TRIGGER_LCD();
    
    if (KAL_TRUE == ibw1_struct->dc_couple)
    {
      ENABLE_IBW1_DC();
    }
    else
    {
      DISABLE_IBW1_DC();
    }
  }
  else
  {
    DISABLE_IBW1_TRIGGER_LCD();
  }
  
  if (KAL_TRUE == ibw1_struct->pan)
  {
    ENABLE_IBW1_PAN();
    
    REG_IMGDMA_IBW1_CLIP_LEFT_RIGHT =
      (ibw1_struct->clip_left << 16) | ibw1_struct->clip_right;
    
    REG_IMGDMA_IBW1_CLIP_TOP_BOTTOM =
      (ibw1_struct->clip_top << 16) | ibw1_struct->clip_bottom;
  }
  else
  {
    DISABLE_IBW1_PAN();
  }
  
  SET_IBW1_OUTPUT_FORMAT(ibw1_struct->output_format);
  REG_IMGDMA_IBW1_ALPHA = ibw1_struct->alpha;

  REG_IMGDMA_IBW1_BASE_ADDR1 = ibw1_struct->base1_addr;
  REG_IMGDMA_IBW1_BASE_ADDR2 = ibw1_struct->base1_addr;
  
  REG_IMGDMA_IBW1_WIDTH = (ibw1_struct->width - 1);
  REG_IMGDMA_IBW1_HEIGHT = (ibw1_struct->height - 1);
}

/** \brief Programmers can use this function to config IBR1.
 *
 * \ingroup imgdma_ibr1
 *
 * Before using this function, IBR1 should be turned off.
 *
 * \param ibr1_struct IBR1 config structure
 */
void
IMGDMA_IBR1Config(IMGDMA_IBR1_STRUCT const * const ibr1_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_IBR1_START()) &&
         "You should turn off IBR1 before calling this function.");

  REG_IMGDMA_IBR1_CTRL = 0;
  
  switch (ibr1_struct->data_type)
  {
  case IBR1_TYPE_RGB565:
    SET_IMGDMA_IBR1_DATA_RGB565;
    break;

  case IBR1_TYPE_RGB888:
    SET_IMGDMA_IBR1_DATA_RGB888;
    break;

  default:
    ASSERT(0 && "Wrong ibr1 source input data type.");
    break;
  }

  switch (ibr1_struct->data_order)
  {
  case IBR1_ORDER_BGR888:
    SET_IMGDMA_IBR1_DATA_ORDER_BGR888;
    break;

  case IBR1_ORDER_RGB888:
    SET_IMGDMA_IBR1_DATA_ORDER_RGB888;
    break;

  default:
    ASSERT(0 && "Wrong ibr1 source input data order.");
    break;
  }

  if (KAL_FALSE == ibr1_struct->int_en)
  {
    DISABLE_IMGDMA_IBR1_INT;
  }
  else
  {
    ENABLE_IMGDMA_IBR1_INT;
  }

  REG_IMGDMA_IBR1_BASE_ADDR = ibr1_struct->base_addr;
  REG_IMGDMA_IBR1_PIXEL_NUMBER = ibr1_struct->pixel_number - 1;
}

/** \brief Programmers can use this function to config IBR2.
 *
 * \ingroup imgdma_ibr2
 *
 * Before using this function, IBR2 should be turned off.
 *
 * \param ibr2_struct IBR2 config structure
 */
void
IMGDMA_IBR2Config(IMGDMA_IBR2_STRUCT const * const ibr2_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_IBR2_START()) &&
         "You should turn off IBR2 before calling this function.");
  
  REG_IMGDMA_IBR2_CTRL = 0;
  
  if (KAL_FALSE == ibr2_struct->int_en)
  {
    DISABLE_IMGDMA_IBR2_INT();
  }
  else
  {
    ENABLE_IMGDMA_IBR2_INT();
  }

  if (KAL_FALSE == ibr2_struct->auto_restart)
  {
    DISABLE_IMGDMA_IBR2_RESTART();
  }
  else
  {
    ENABLE_IMGDMA_IBR2_RESTART();
  }
  
  if (KAL_FALSE == ibr2_struct->flip)
  {
    DISABLE_IMGDMA_IBR2_FLIP();
  }
  else
  {
    ENABLE_IMGDMA_IBR2_FLIP();
  }
  
  SET_IMGDMA_IBR2_ROTATE(ibr2_struct->rotate);
  SET_IMGDMA_IBR2_LCD_FMT(ibr2_struct->fmt);
  
  REG_IMGDMA_IBR2_BASE_ADDR = ibr2_struct->base1_addr;
  REG_IMGDMA_IBR2_BASE2_ADDR = ibr2_struct->base2_addr;
  REG_IMGDMA_IBR2_WIDTH = ibr2_struct->width;
  REG_IMGDMA_IBR2_HEIGHT = ibr2_struct->height;
  REG_IMGDMA_IBR2_PIXEL_NUMBER = ibr2_struct->pixel_number;
}

/** \brief Use this function to setup the overlay palette
 * content.
 *
 * \ingroup imgdma_ovl
 *
 * \param palette_size palette size in 4 bytes
 * \param palette_addr_ptr palette starting address
 */
void
IMGDMA_OVLSetPalette(kal_uint8 const palette_size,
                     kal_uint32 const * const palette_addr_ptr)
{
  kal_uint16 i;
  
  ENABLE_IMGDMA_OVL_PAL();
  
  for (i = 0; i <= palette_size; ++i)
  {
    *((volatile kal_uint32 *)(IMGDMA_OVL_COLOR_PALETTE_BASE + (i << 2))) =
      *(palette_addr_ptr + i);
  }
}

void
set_overlay_palette(
  kal_uint8 const palette_size,
  kal_uint32 * const palette_addr_ptr)
{
  /// Turn on image DMA clock
	DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_IMGDMA;
  
  IMGDMA_OVLSetPalette(palette_size, palette_addr_ptr);
  
	if (SCENARIO_UNKNOW_ID == current_image_data_path_owner)
	{
		/// Turn on image DMA clock
		DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_IMGDMA;
	}
}

/** \brief Programmers can use this function to config OVL (overlay).
 *
 * \ingroup imgdma_ovl
 *
 * Before using this function, OVL should be turned off.
 *
 * \param ovl_struct OVL config structure
 */
void
IMGDMA_OVLConfig(IMGDMA_OVL_STRUCT const * const ovl_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_OVL_START()) &&
         "You should turn off OVL before calling this function.");
  
  REG_IMGDMA_OVL_CTRL = 0;
  
  if (KAL_FALSE == ovl_struct->int_en)
  {
    DISABLE_IMGDMA_OVL_INT();
  }
  else
  {
    ENABLE_IMGDMA_OVL_INT();
  }
  
  if (KAL_FALSE == ovl_struct->restart)
  {
    DISABLE_IMGDMA_OVL_AUTO_RESATRT();
  }
  else
  {
    ENABLE_IMGDMA_OVL_AUTO_RESATRT();
  }
  
  if (PIXEL_ENGINE_IPP1 == ovl_struct->pixel_engine)
  {
    SET_IMGDMA_OVL_SRC_IPP1();
  }
  else if(ovl_struct->pixel_engine==PIXEL_ENGINE_CRZ)
  {
    SET_IMGDMA_OVL_SRC_CRZ();
  }
  
  {
    /* configure output module */
    kal_uint32 output_module = 0;
    
    if (KAL_TRUE == ovl_struct->output_vdoenc)
    {
      output_module |= IMGDMA_OVL_OUTPUT_VDOENC_BIT;
    }
  
    if (KAL_TRUE == ovl_struct->ouput_jpeg)
    {
      output_module |= IMGDMA_OVL_OUTPUT_JPEG_BIT;
    }
  
    if (KAL_TRUE == ovl_struct->ouput_y2r0)
    {
      output_module |= IMGDMA_OVL_OUTPUT_Y2R0_BIT;
    }
  
    if (KAL_TRUE == ovl_struct->ouput_drz)
    {
      output_module |= IMGDMA_OVL_OUTPUT_DRZ_BIT;
    }
  
    if (KAL_TRUE == ovl_struct->ouput_prz)
    {
      output_module |= IMGDMA_OVL_OUTPUT_PRZ_BIT;
    }
  
    SET_OVL_OUTPUT_MODULE(output_module);
  }
  
  if (KAL_TRUE == ovl_struct->overlay_frame_mode)
  {
    ENABLE_IMGDMA_OVL_OVERLAY();
    
    SET_OVL_OVERLAY_MODE(ovl_struct->overlay_color_depth);
    
    REG_IMGDMA_OVL_BASE_ADDR = ovl_struct->overlay_frame_buffer_address;
    SET_IMGDMA_OVL_SRC_KEY(ovl_struct->overlay_frame_source_key);
    
    if (((ovl_struct->overlay_frame_target_height %
          ovl_struct->overlay_frame_height) != 0) ||
        ((ovl_struct->overlay_frame_target_width %
          ovl_struct->overlay_frame_width) != 0))
    {
      ASSERT(0 &&
             "The image's width & height which is operated by OVL should \
be muptiple of the overlay's width & height.");
    }
    
    {
      kal_uint32 const v_ratio =
        ovl_struct->overlay_frame_target_height /
        ovl_struct->overlay_frame_height;
      
      kal_uint32 const h_ratio = 
        ovl_struct->overlay_frame_target_width /
        ovl_struct->overlay_frame_width;
      
      ASSERT(v_ratio <= 15);
      ASSERT(h_ratio <= 15);
      
      SET_IMGDMA_OVL_V_RATIO(v_ratio);
      SET_IMGDMA_OVL_H_RATIO(h_ratio);
    }
    
    REG_IMGDMA_OVL_WIDTH = ovl_struct->overlay_frame_width;
    REG_IMGDMA_OVL_HEIGHT = ovl_struct->overlay_frame_height;
  }
  else
  {
    DISABLE_IMGDMA_OVL_OVERLAY();
  }
}

/** \brief Programmers can use this function to config JPEG DMA.
 *
 * \ingroup imgdma_jpeg
 *
 * Before using this function, JPEG DMA should be turned off.
 *
 * \param jpeg_dma_struct JPEG DMA config structure
 */
void
IMGDMA_JPEGDMAConfig(IMGDMA_JPEG_DMA_STRUCT const * const jpeg_dma_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_JPEG_START()) &&
         "You should turn off JPEG DMA before calling this function.");
  
  REG_IMGDMA_JPEG_CTRL = 0;
  
  switch (jpeg_dma_struct->jpeg_yuv_mode)
  {
  case IMGDMA_JPEG_FORMAT_YUV420:
    SET_IMGDMA_JPEG_YUV420();
    break;
    
  case IMGDMA_JPEG_FORMAT_YUV411:
    SET_IMGDMA_JPEG_YUV411();
    break;
    
  case IMGDMA_JPEG_FORMAT_YUV422:
    SET_IMGDMA_JPEG_YUV422();
    break;
    
  case IMGDMA_JPEG_FORMAT_GRAY:
    SET_IMGDMA_JPEG_GRAY();
    break;
    
  default:
    ASSERT(0);
    break;
  }
  
  if (KAL_TRUE == jpeg_dma_struct->restart)
  {
    ENABLE_IMGDMA_JPEG_AUTO_RESTART();
  }
  else
  {
    DISABLE_IMGDMA_JPEG_AUTO_RESTART();
  }
  
  if (KAL_TRUE == jpeg_dma_struct->int_enable)
  {
    ENABLE_IMGDMA_JPEG_INT();
  }
  else
  {
    DISABLE_IMGDMA_JPEG_INT();
  }
  
  REG_IMGDMA_JPEG_BASE_ADDR =
    (kal_uint32)jpeg_dma_struct->jpeg_file_buffer_address;
  
  if (IMGDMA_JPEG_FORMAT_YUV420 == jpeg_dma_struct->jpeg_yuv_mode)
  {
    REG_IMGDMA_JPEG_FIFO_LENGTH =
      JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER >> 1;
  }
  else
  {
    REG_IMGDMA_JPEG_FIFO_LENGTH =
      JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER;
  }
  
  REG_IMGDMA_JPEG_WIDTH = jpeg_dma_struct->target_width - 1;
  REG_IMGDMA_JPEG_HEIGHT = jpeg_dma_struct->target_height - 1;
}

kal_uint32
IMGDMA_JPEGDMAGetWorkingMem(kal_bool const use_internal_mem,
                            kal_uint8 const mode,
                            kal_uint32 const width)
{
  kal_uint32 size;
  
  switch (mode)
  {
  case JPEG_FORMAT_GRAY:
    {
      kal_uint32 tmp_a;
      
      if ((width & 0x7) != 0)
      {
        tmp_a = tmp_a / 8 + 1;
      }
      else
      {
        tmp_a = tmp_a / 8;
      }
      
      tmp_a *= 8;
      
      size = tmp_a * JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER;
    }
    break;
    
  case JPEG_FORMAT_YUV422:
    {
      kal_uint32 tmp_a;
        
      if ((width & 0xF) != 0)
      {
        tmp_a = tmp_a / 16 + 1;
      }
      else
      {
        tmp_a = tmp_a / 16;
      }
        
      tmp_a *= 16;
        
      size = tmp_a * JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER * 2;
    }
    break;
    
  case JPEG_FORMAT_YUV420:
    {
      kal_uint32 tmp_a;
        
      if ((width & 0xF) != 0)
      {
        tmp_a = tmp_a / 16 + 1;
      }
      else
      {
        tmp_a = tmp_a / 16;
      }
        
      tmp_a *= 16;
        
      size = tmp_a * JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER * 3;
    }
    break;
    
  case JPEG_FORMAT_YUV411:
    {
      kal_uint32 tmp_a;
        
      if ((width & 0x1F) != 0)
      {
        tmp_a = tmp_a / 32 + 1;
      }
      else
      {
        tmp_a = tmp_a / 32;
      }
        
      tmp_a *= 32;
        
      size = tmp_a * JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER * 3 / 2;
    }
    break;
    
  default:
    ASSERT(0);
    break;
  }
  
  if (KAL_TRUE == use_internal_mem)
  {
    return (kal_uint32)intmem_get_buffer(size);
  }
  else
  {
    return (kal_uint32)extmem_get_buffer(size);
  }
}

/** \brief Programmers can use this function to config video
 * encode DMA.
 *
 * \ingroup imgdma_video_encode
 *
 * Before using this function, video encode DMA should be
 * turned off.
 *
 * \param video_encode_dma_struct video encode DMA config
 * structure
 */
void
IMGDMA_VIDEOENCODE_DMAConfig(
  IMGDMA_VIDEO_ENCODE_STRUCT const * const video_encode_dma_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_VIDEO_ENCODE_START()) &&
         "You should turn off video encode DMA before calling this function.");
  
  REG_IMGDMA_VIDEO_ENCODE_CTRL = 0;
  
  if (KAL_TRUE == video_encode_dma_struct->wrtie_done_int)
  {
    ENABLE_VIDEO_ENCODE_W_INT();
  }
  else
  {
    DISABLE_VIDEO_ENCODE_W_INT();
  }
  
  /* trigger read DMA or not */
  if (KAL_TRUE == video_encode_dma_struct->w_trigger_r)
  {
    ENABLE_VIDEO_ENCODE_W_TRIGGER_R();
    
    if (KAL_TRUE == video_encode_dma_struct->flip)
    {
      ENABLE_VIDEO_ENCODE_FLIP();
    }
    else
    {
      DISABLE_VIDEO_ENCODE_FLIP();
    }
    
    if (KAL_TRUE == video_encode_dma_struct->bypass)
    {
      ENABLE_VIDEO_ENCODE_BYPASS();
    }
    else
    {
      DISABLE_VIDEO_ENCODE_BYPASS();
    }
    
    SET_VIDEO_ENCODE_ROT(video_encode_dma_struct->rot);
  }
  else
  {
    DISABLE_VIDEO_ENCODE_W_TRIGGER_R();
  }
  
  if (KAL_TRUE == video_encode_dma_struct->restart)
  {
    ENABLE_VIDEO_ENCODE_AUTO_RESTART();
  }
  else
  {
    DISABLE_VIDEO_ENCODE_AUTO_RESTART();
  }
  
  if (KAL_TRUE == video_encode_dma_struct->read_done_int)
  {
    ENABLE_VIDEO_ENCODE_R_INT();
  }
  else
  {
    DISABLE_VIDEO_ENCODE_R_INT();
  }
  
  REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1 =
    (kal_uint32)video_encode_dma_struct->y_base_addr1;
  REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1 =
    (kal_uint32)video_encode_dma_struct->u_base_addr1;
  REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1 =
    (kal_uint32)video_encode_dma_struct->v_base_addr1;
  REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2 =
    (kal_uint32)video_encode_dma_struct->y_base_addr2;
  REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2 =
    (kal_uint32)video_encode_dma_struct->u_base_addr2;
  REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2 =
    (kal_uint32)video_encode_dma_struct->v_base_addr2;
  
  ASSERT(0 == (video_encode_dma_struct->encode_width % 16));
  ASSERT(0 == (video_encode_dma_struct->encode_height % 16));
  
  REG_IMGDMA_VIDEO_ENCODE_WIDTH =
    video_encode_dma_struct->encode_width;
  REG_IMGDMA_VIDEO_ENCODE_HEIGHT =
    video_encode_dma_struct->encode_height;
  REG_IMGDMA_VIDEO_ENCODE_PXLNUM =
    video_encode_dma_struct->encode_width * video_encode_dma_struct->encode_height;
}

/** \brief Programmers can use this function to config video
 * decode DMA.
 *
 * \ingroup imgdma_video_decode
 *
 * Before using this function, video decode DMA should be
 * turned off.
 *
 * \param video_decode_dma_struct video decode DMA config
 * structure
 */
void
IMGDMA_VIDEODECODE_DMAConfig(
  IMGDMA_VIDEO_DECODE_STRUCT const * const video_decode_dma_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_VIDEO_DECODE_START()) &&
         "You should turn off video decode DMA before calling this function.");
  
  REG_IMGDMA_VIDEO_DECODE_CTRL = 0;
  
  if (KAL_TRUE == video_decode_dma_struct->decode_done_int)
  {
    ENABLE_VIDEO_DECODE_INT();
  }
  else
  {
    DISABLE_VIDEO_DECODE_INT();
  }
  
  /* h.264 or mp4 buffer */
  if (KAL_TRUE == video_decode_dma_struct->buf_h264)
  {
    SET_VIDEO_DECODE_H264_BUF();
  }
  else
  {
    SET_VIDEO_DECODE_MPEG4_BUF();
  }
  
  if (KAL_TRUE == video_decode_dma_struct->flip) /* flip */
  {
    ENABLE_VIDEO_DECODE_FLIP();
  }
  else
  {
    DISABLE_VIDEO_DECODE_FLIP();
  }

  if (KAL_TRUE == video_decode_dma_struct->bypass_irt0) /* bypass irt0 */
  {
    BYPASS_VIDEO_DECODE_TO_IRT0();
  }
  else
  {
    NOTBYPASS_VIDEO_DECODE_TO_IRT0();
  }
  
  SET_VIDEO_DECODE_ROTATE(video_decode_dma_struct->rot);
  
  REG_IMGDMA_VIDEO_DECODE_WIDTH = video_decode_dma_struct->width;
  REG_IMGDMA_VIDEO_DECODE_HEIGHT = video_decode_dma_struct->height;
  SET_IMGDMA_VIDEO_DEC_PIXNUM(video_decode_dma_struct->width *
                              video_decode_dma_struct->height);
  
  /* only one buffer, the second is removed */
  REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR = video_decode_dma_struct->y_base_addr;
  REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR = video_decode_dma_struct->u_base_addr;
  REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR = video_decode_dma_struct->v_base_addr;
}

/** \brief Programmers can use this function to config
 * IBW2.
 *
 * \ingroup imgdma_ibw2
 *
 * Before using this function, IBW2 should be turned off.
 *
 * \param ibw2_struct IBW2 config structure
 */
void
IMGDMA_IBW2Config(IMGDMA_IBW2_STRUCT const * const ibw2_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_IBW2_START()) &&
         "You should turn off IBW2 before calling this function.");
  
  REG_IMGDMA_IBW2_CTRL = 0;
  
  REG_IMGDMA_IBW2_WIDTH = ibw2_struct->width - 1;
  REG_IMGDMA_IBW2_HEIGHT = ibw2_struct->height - 1;
  
  if (KAL_TRUE == ibw2_struct->lcd_trigger)
  {
    ENABLE_IBW2_TRIGGER_LCD();
  }
  else
  {
    DISABLE_IBW2_TRIGGER_LCD();
  }
  
  if (KAL_TRUE == ibw2_struct->int_en)
  {
    ENABLE_IBW2_INT();
  }
  else
  {
    DISABLE_IBW2_INT();
  }
  
  if (KAL_TRUE == ibw2_struct->pan)
  {
    ENABLE_IBW2_PAN();
    
    REG_IMGDMA_IBW2_CLIP_LEFT_RIGHT =
      (ibw2_struct->clip_left << 16) | ibw2_struct->clip_right;
    REG_IMGDMA_IBW2_CLIP_TOP_BOTTOM =
      (ibw2_struct->clip_top << 16) | ibw2_struct->clip_bottom;
  }
  else
  {
    DISABLE_IBW2_PAN();
  }
  
  if (KAL_TRUE == ibw2_struct->direct_couple)
  {
    ENABLE_IBW2_DC();
  }
  else
  {
    DISABLE_IBW2_DC();
  }

  if (KAL_TRUE == ibw2_struct->restart)
  {
    ENABLE_IBW2_AUTO_RESTART();
  }
  else
  {
    DISABLE_IBW2_AUTO_RESTART();
  }

  if (KAL_TRUE == ibw2_struct->output_IRT1)
  {
    ENABLE_IBW2_OUT2IRT1();
  }
  else
  {
    DISABLE_IBW2_OUT2IRT1();
  }
}

kal_uint32
IMGDMA_IRT0GetWorkingMem(
  kal_bool const use_internal_mem,
  kal_uint32 const width,
  kal_uint32 const height,
  IMGDMA_IRT0_ROT_ENUM const rot,
  kal_uint32 const fifo_length)
{
  kal_uint32 size;
  
  ASSERT((fifo_length >= 8) &&
         (0 == (fifo_length % 8)));
  
  if ((IRT0_ROT_OFF == rot) || (IRT0_ROT_180 == rot))
  {
    size = (width * fifo_length * 3) / 2;
  }
  else
  {
    size = (height * fifo_length * 3) / 2;
  }
  
  if (KAL_TRUE == use_internal_mem)
  {
    return (kal_uint32)intmem_get_buffer(size);
  }
  else
  {
    return (kal_uint32)extmem_get_buffer(size);
  }
}

/** \brief Programmers can use this function to config
 * IRT0.
 *
 * \ingroup imgdma_irt0
 *
 * Before using this function, IRT0 should be turned off.
 *
 * \param irt0_struct IRT0 config structure
 */
void
IMGDMA_IRT0Config(IMGDMA_IRT0_STRUCT const * const irt0_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_IRT0_START()) &&
         "You should turn off IRT0 before calling this function.");
  
  REG_IMGDMA_IRT0_CTRL = 0;
  
  if (KAL_TRUE == irt0_struct->int_en)
  {
    ENABLE_IRT0_INT();
  }
  else
  {
    DISABLE_IRT0_INT();
  }
  
  if (KAL_TRUE == irt0_struct->restart)
  {
    ENABLE_IRT0_AUTOSTART();
  }
  else
  {
    DISABLE_IRT0_AUTOSTART();
  }

  if (KAL_TRUE == irt0_struct->src_video_dec)
  {
    SET_IRT0_SRC_VIDEO_DEC_DMA();
  }
  else
  {
    SET_IRT0_SRC_VIDEO_ENC_DMA();
  }

  if (KAL_TRUE == irt0_struct->buf_h264)
  {
    SET_IRT0_SRC_H264_BUFFER();
  }
  else
  {
    SET_IRT0_SRC_MPEG4_BUFFER();
  }

  if (KAL_TRUE == irt0_struct->flip)
  {
    ENABLE_IRT0_FLIP();
  }
  else
  {
    DISABLE_IRT0_FLIP();
  }
  
  if (KAL_TRUE == irt0_struct->bypass)
  {
    BYPASS_IRT0_ROTATE();
  }
  else
  {
    NOTBYPASS_IRT0_ROTATE();
  }
  
  switch (irt0_struct->output)
  {
  case IRT0_OUTPUT_CRZ:
    SET_IRT0_OUTPUT_MOD(irt0_struct->output);
    break;
    
  case IRT0_OUTPUT_PRZ:
    SET_IRT0_OUTPUT_MOD(irt0_struct->output);
    break;
    
  case IRT0_OUTPUT_IPP1:
    SET_IRT0_OUTPUT_MOD(irt0_struct->output);
    break;
    
  case IRT0_OUTPUT_MP4DEBLK:
    SET_IRT0_OUTPUT_MOD(irt0_struct->output);
    break;
    
  default:
    ASSERT(0 &&
           "Wrong value of irt0_struct->output.");
    break;
  }
  
  SET_IMGDMA_IRT0_LINE_BUFFER_ADDR(irt0_struct->fifo_base);
  
  SET_IRT0_ROTATE_DIR(irt0_struct->rotate);
  SET_IMGDMA_IRT0_WIDTH(irt0_struct->width);
  SET_IMGDMA_IRT0_HEIGHT(irt0_struct->height);

  SET_IMGDMA_IRT0_PIXNUM(irt0_struct->pix_num);
  
  //ASSERT((irt0_struct->fifo_len >= 8) && //Please Wei help check
    //     (0 == (irt0_struct->fifo_len % 8)));
  
  SET_IMGDMA_IRT0_FIFOLEN(irt0_struct->fifo_len);
}

/** \brief Programmers can use this function to config
 * IRT1.
 *
 * \ingroup imgdma_irt1
 *
 * Before using this function, IRT1 should be turned off.
 *
 * \param irt1_struct IRT1 config structure
 */
void
IMGDMA_IRT1Config(IMGDMA_IRT1_STRUCT const * const irt1_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_IRT1_START()) &&
         "You should turn off IRT1 before calling this function.");
  
  REG_IMGDMA_IRT1_CTRL = 0;
  
  if (KAL_TRUE == irt1_struct->int_en) /* enable int or not */
  {
    ENABLE_IRT1_INT();
  }
  else
  {
    DISABLE_IRT1_INT();
  }

  if (KAL_TRUE == irt1_struct->restart) /* restart or not */
  {
    ENABLE_IRT1_AUTOSTART();
  }
  else
  {
    DISABLE_IRT1_AUTOSTART();
  }

  SET_IRT1_ROTATE_DIR(irt1_struct->rotate);
  
  if (irt1_struct->rotate != IRT1_ROT_OFF)
  {
    SET_IMGDMA_IRT1_BUFF1_FRAME_PITCH(irt1_struct->buf1_frame_pitch);
    SET_IMGDMA_IRT1_BUFF2_FRAME_PITCH(irt1_struct->buf2_frame_pitch);
  }
  
  if (KAL_TRUE == irt1_struct->flip) /* flip or not */
  {
    ENABLE_IRT1_FLIP();
  }
  else
  {
    DISABLE_IRT1_FLIP();
  }

  SET_IRT1_OUTPUT_FMT(irt1_struct->fmt);

  if (KAL_TRUE == irt1_struct->pitch_enable)
  {
    ENABLE_IRT1_PITCH();

    /* buf1 line pitch */
    SET_IMGDMA_IRT1_BUFF1_LINE_PITCH(irt1_struct->buf1_line_pitch);

    /* buf2 line pitch */
    SET_IMGDMA_IRT1_BUFF2_LINE_PITCH(irt1_struct->buf2_line_pitch);

    SET_IMGDMA_IRT1_BUFF1_FRAME_PITCH(irt1_struct->buf1_frame_pitch);
    SET_IMGDMA_IRT1_BUFF2_FRAME_PITCH(irt1_struct->buf2_frame_pitch);
  }
  else
  {
    DISABLE_IRT1_PITCH();
  }

  if (KAL_TRUE == irt1_struct->trigger_lcd)
  {
    ENABLE_IRT1_LCD_TRIGGER();
  }
  else
  {
    DISABLE_IRT1_LCD_TRIGGER();
  }

  SET_IMGDMA_IRT1_FIFO_ADDR(irt1_struct->fifo_base_addr);
  SET_IMGDMA_IRT1_FIFOLEN(irt1_struct->fifo_len);
  SET_IMGDMA_IRT1_WIDTH(irt1_struct->width);
  SET_IMGDMA_IRT1_HEIGHT(irt1_struct->height);

  SET_IMGDMA_IRT1_BUFF1_ADDR(irt1_struct->frame1_base_addr);
  SET_IMGDMA_IRT1_BUFF2_ADDR(irt1_struct->frame2_base_addr);
  
  SET_IMGDMA_IRT1_ALPHA(irt1_struct->alpha);
}

kal_uint32
IMGDMA_IRT1GetWorkingMem(kal_bool const use_internal_mem,
                         kal_uint32 const width,
                         kal_uint32 const bpp,
                         kal_uint32 const fifo_length)
{
  kal_uint32 tmp_a = width * bpp;
  kal_uint32 tmp_b;
  kal_uint32 size;
  
  if ((tmp_a & 0x3) != 0)
  {
    tmp_a = (tmp_a / 4) + 1;
  }
  else
  {
    tmp_a /= 4;
  }
  
  tmp_b = tmp_a * 4;
  
  size = tmp_b * fifo_length;
  
  if (KAL_TRUE == use_internal_mem)
  {
    return (kal_uint32)intmem_get_buffer(size);
  }
  else
  {
    return (kal_uint32)extmem_get_buffer(size);
  }
}

/** \brief Programmers can use this function to config
 * IRT2.
 *
 * \ingroup imgdma_irt2
 *
 * Before using this function, IRT2 should be turned off.
 *
 * \param irt2_struct IRT2 config structure
 */
void
IMGDMA_IRT2Config(IMGDMA_IRT2_STRUCT const * const irt2_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_IRT2_START()) &&
         "You should turn off IRT2 before calling this function.");
  
  REG_IMGDMA_IRT2_CTRL = 0;
  
  if (KAL_TRUE == irt2_struct->int_en) /* enable int or not */
  {
    ENABLE_IRT2_INT();
  }
  else
  {
    DISABLE_IRT2_INT();
  }

  if (KAL_TRUE == irt2_struct->restart) /* restart or not */
  {
    ENABLE_IRT2_AUTOSTART();
  }
  else
  {
    DISABLE_IRT2_AUTOSTART();
  }

  SET_IRT2_ROTATE_DIR(irt2_struct->rotate);
  
  if (KAL_TRUE == irt2_struct->flip) /* flip or not */
  {
    ENABLE_IRT2_FLIP();
  }
  else
  {
    DISABLE_IRT2_FLIP();
  }

  SET_IRT2_OUTPUT_FMT(irt2_struct->out_fmt);
  SET_IRT2_INPUT_FMT(irt2_struct->in_fmt);

  if (IRT2_OUTPUT_R2Y0 == irt2_struct->output)
  {
     SET_IRT2_OUT2Y2R0();
  }
  else if (IRT2_OUTPUT_LCD == irt2_struct->output)
  {
     SET_IRT2_OUT2LCD();
  }
  
  if (KAL_TRUE == irt2_struct->trigger_lcd)
  {
    ENABLE_IRT2_LCD_TRIGGER();
  }
  else
  {
    DISABLE_IRT2_LCD_TRIGGER();
  }

  SET_IMGDMA_IRT2_FIFO_ADDR(irt2_struct->fifo_base_addr);
  SET_IMGDMA_IRT2_FIFOLEN(irt2_struct->fifo_len);
  SET_IMGDMA_IRT2_WIDTH(irt2_struct->width-1);
  SET_IMGDMA_IRT2_HEIGHT(irt2_struct->height-1);

  SET_IMGDMA_IRT2_ALPHA(irt2_struct->alpha);
}

/** \brief Programmers can use this function to config
 * IRT3.
 *
 * \ingroup imgdma_irt3
 *
 * Before using this function, IRT3 should be turned off.
 *
 * \param irt3_struct IRT3 config structure
 */
void
IMGDMA_IRT3Config(IMGDMA_IRT3_STRUCT const * const irt3_struct)
{
  ASSERT((KAL_FALSE == IS_IMGDMA_IRT3_START()) &&
         "You should turn off IRT3 before calling this function.");
  
  REG_IMGDMA_IRT3_CTRL = 0;
  
  if (KAL_TRUE == irt3_struct->int_en) /* enable int or not */
  {
    ENABLE_IRT3_INT();
  }
  else
  {
    DISABLE_IRT3_INT();
  }

  if (KAL_TRUE == irt3_struct->restart) /* restart or not */
  {
    ENABLE_IRT3_AUTOSTART();
  }
  else
  {
    DISABLE_IRT3_AUTOSTART();
  }

  SET_IRT3_ROTATE_DIR(irt3_struct->rotate);
  
  if (irt3_struct->rotate != IRT3_ROT_OFF)
  {
    SET_IMGDMA_IRT3_BUFF1_FRAME_PITCH(irt3_struct->buf1_frame_pitch);
    SET_IMGDMA_IRT3_BUFF2_FRAME_PITCH(irt3_struct->buf2_frame_pitch);
  }
  
  if (KAL_TRUE == irt3_struct->flip)
  {
    ENABLE_IRT3_FLIP();
  }
  else
  {
    DISABLE_IRT3_FLIP();
  }

  SET_IRT3_OUTPUT_FMT(irt3_struct->fmt);

  if (KAL_TRUE == irt3_struct->pitch_enable)
  {
    ENABLE_IRT3_PITCH();

    SET_IMGDMA_IRT3_BUFF1_LINE_PITCH(irt3_struct->buf1_line_pitch);
    SET_IMGDMA_IRT3_BUFF2_LINE_PITCH(irt3_struct->buf2_line_pitch);
  }
  else
  {
    DISABLE_IRT3_PITCH();
  }
  
  SET_IMGDMA_IRT3_FIFO_ADDR(irt3_struct->fifo_base_addr);
  SET_IMGDMA_IRT3_FIFOLEN(irt3_struct->fifo_len);
  SET_IMGDMA_IRT3_WIDTH(irt3_struct->width);
  SET_IMGDMA_IRT3_HEIGHT(irt3_struct->height);

  SET_IMGDMA_IRT3_BUFF1_ADDR(irt3_struct->frame1_base_addr);
  SET_IMGDMA_IRT3_BUFF2_ADDR(irt3_struct->frame2_base_addr);

  SET_IMGDMA_IRT3_ALPHA(irt3_struct->alpha);
}

void image_dma_LISR(void)
{
	kal_uint32 reg;
  
  IRQMask(IRQ_IMGDMA_CODE);
  reg = DRV_Reg32(IMGDMA_STATUS_REG);
	ASSERT(reg != 0);
  
	// first run of VDO
 	if (reg & IMGDMA_STATUS_IBW2_INT_BIT)
	{
    ACK_IMGDMA_IBW2_INT;
    
#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
    SLA_HWLogging("BW2", SA_stop);
    SLA_HWLogging("LCD", SA_start);
#endif
    
    if (ibw2_cb != NULL)
    {
	   	ibw2_cb();
    }
	}
  else if (reg & IMGDMA_STATUS_IRT1_INT_BIT)
  {
    ACK_IMGDMA_IRT1_INT;
    
    if (irt1_cb != NULL)
    {
	   	irt1_cb();
    }
  }
	// interrupts may occur simutaneusly
	else if(reg & IMGDMA_STATUS_IBW1_INT_BIT)
	{
    ACK_IMGDMA_IBW1_INT;
    
    if (ibw1_cb != NULL)
    {
	   	ibw1_cb();
    }
	}
	else if (reg & IMGDMA_STATUS_VIDEO_ENC_W_INT_BIT)
	{
		ACK_IMGDMA_VIDEO_ENCODE_W_INT;
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    ASSERT(0);
#endif
    
		++current_video_buffer_count;
		current_video_buffer_count &= 0x1;

		if (vid_enc_w_cb != NULL)
    {
			vid_enc_w_cb();
    }
    
		if (vid_enc_r_cb != NULL)
    {
			vid_enc_r_cb(KAL_FALSE);
    }
    
#ifdef __3G_VIDEO_CALL__
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
#endif/* __3G_VIDEO_CALL__*/
	}
	else if (reg & IMGDMA_STATUS_VIDEO_ENC_R_INT_BIT)
	{
		ACK_IMGDMA_VIDEO_ENCODE_R_INT;
	}
	else if (reg & IMGDMA_STATUS_VIDEO_DEC_INT_BIT)
	{
		ACK_IMGDMA_VIDEO_DECODE_INT;
	}
	else if (reg & IMGDMA_STATUS_IBR1_INT_BIT)
	{
		ACK_IMGDMA_IBR1_INT;
	}
	else if (reg & IMGDMA_STATUS_IBR2_INT_BIT)
	{
		ACK_IMGDMA_IBR2_INT;
	}
  
	IRQUnmask(IRQ_IMGDMA_CODE);
}	/* image_dma_LISR() */

#endif
