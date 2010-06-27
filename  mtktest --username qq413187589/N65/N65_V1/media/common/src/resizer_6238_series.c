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
 *   mt6238_resizer.c
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *   resizer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "resizer_6238_series.h"
#include "intrCtrl.h"

/** \brief Initialize the DRZ subsystem.
 *
 * \ingroup drz
 *
 * This functino will setup the interrupt for the DRZ
 * to level sensitive, and unmask all the interrupts for the
 * DRZ.
 */
void
RESZ_DRZInit(void)
{
  IRQSensitivity(IRQ_RESIZER_DRZ_CODE, LEVEL_SENSITIVE);
  IRQUnmask(IRQ_RESIZER_DRZ_CODE);
}

/** \brief Programmers can use this function to config DRZ.
 *
 * \ingroup drz
 *
 * Before using this function, DRZ should be turned off.
 *
 * \param drz_struct DRZ config structure
 */
void
RESZ_DRZConfig(RESZ_DRZ_STRUCT const * const drz_struct)
{
  ASSERT((KAL_FALSE == IS_DRZ_START()) &&
         "You should turn off DRZ before calling this function.");
  
  REG_DRZ_CONFIG = 0;
  
  if (RESZ_SOURCE_IBW3 == drz_struct->image_src)
  {
    SET_DRZ_SRC_IBW3_DMA();
  }
  else if (RESZ_SOURCE_MPEG4_ENCODE_DMA == drz_struct->image_src)
  {
    SET_DRZ_SRC_VIDEO_ENCODE_DMA();
  }
  else
  {
    ASSERT(0);
  }
  
  if (KAL_TRUE == drz_struct->auto_restart)
  {
    ENABLE_DRZ_AUTO_RESTART();
  }
  else
  {
    DISABLE_DRZ_AUTO_RESTART();
  }
  
  if (KAL_TRUE == drz_struct->int_en)
  {
    ENABLE_DRZ_INT();
  }
  else
  {
    DISABLE_DRZ_INT();
  }
  
  REG_DRZ_SOURCE_IMAGE_SIZE = 
    ((drz_struct->src_height - 1) << 16) | (drz_struct->src_width - 1);
  REG_DRZ_TARGET_IMAGE_SIZE =
    ((drz_struct->tar_height - 1) << 16) | (drz_struct->tar_width - 1);
  
  REG_DRZ_H_RATIO =
    ((drz_struct->src_width / drz_struct->tar_width) << 16) |
    ((drz_struct->src_width % drz_struct->tar_width));
  REG_DRZ_V_RATIO =
    ((drz_struct->src_height / drz_struct->tar_height) << 16) |
    ((drz_struct->src_height % drz_struct->tar_height));
}

/** \brief Initialize the CRZ subsystem.
 *
 * \ingroup crz
 *
 * This functino will setup the interrupt for the CRZ
 * to level sensitive, and unmask all the interrupts for the
 * CRZ.
 */
void
RESZ_CRZInit(void)
{
  IRQSensitivity(IRQ_RESIZER_CRZ_CODE, LEVEL_SENSITIVE);
  IRQUnmask(IRQ_RESIZER_CRZ_CODE);
}

/** \brief Programmers can use this function to config CRZ.
 *
 * \ingroup crz
 *
 * Before using this function, CRZ should be turned off. In
 * MT6238, TK6516, MT6516, CRZ can only use internal memory
 * (dedicated memory).
 *
 * \param crz_struct CRZ config structure
 */
void
RESZ_CRZConfig(RESZ_CRZ_STRUCT const * const crz_struct)
{
  kal_uint32 lbmax = 0, min_width;
  
  ASSERT((KAL_FALSE == IS_CRZ_START()) &&
         "You should turn off CRZ before calling this function.");
  
  REG_CRZ_CTRL = 0;
  SET_CRZ_DEDICATED_MEMORY();
  
  if (crz_struct->src_width >= crz_struct->tar_width)
  {
    min_width = crz_struct->tar_width; 
  } 
  else
  {
    min_width = crz_struct->src_width; 
  } 
  min_width = min_width + min_width % 2; 
  
  lbmax = (2048 / min_width) * 6;
  
  if (lbmax > 1023)
  {
    lbmax = 1023;
  }
  
  SET_CRZ_LBMAX(lbmax);
  
  if (KAL_TRUE == crz_struct->continous)
  {
    SET_CRZ_CONT_RUN_MODE();
  }
  else
  {
    SET_CRZ_SINGLE_RUN_MODE();
  }
  
  switch (crz_struct->image_src)
  {
  case RESZ_SOURCE_ISP:
    SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_CAMERA_ISP);
    break;
    
  case RESZ_SOURCE_ROTATOR:
    SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_IMAGE_ROTATOR_0);
    break;
    
  case RESZ_SOURCE_MP4_DEBLOCKING:
    SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_MPEG4_DEBLOCKING);
    break;
    
  case RESZ_SOURCE_PRZ:
    SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_PRZ);
    break;
    
  case RESZ_SOURCE_R2Y:
    SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_R2Y_0);
    break;
    
  default:
    ASSERT(0);
    break;  	   
  }
  
  {
    kal_uint32 output_module = 0;
    
    if (crz_struct->output_to_OVL)
    {
      output_module |= CRZ_OUTPUT_OVL;
    }
    if (crz_struct->output_to_IPP1)
    {
      output_module |= CRZ_OUTPUT_IPP1;
    }
    if (crz_struct->output_to_Y2R1)
    {
      output_module |= CRZ_OUTPUT_Y2R1;
    }
    
    SET_CRZ_OUTPUT(output_module);
  }
  
  if (KAL_TRUE == crz_struct->int_en)
  {
    ENABLE_CRZ_INT();
  }
  else
  {
    DISABLE_CRZ_INT();
  }
  
  SET_CRZ_SRC_SIZE(crz_struct->src_width, crz_struct->src_height);
  /* set target size as the multiples of overlay frame buffer */
  SET_CRZ_TARGET_SIZE(crz_struct->tar_width, crz_struct->tar_height);	
  
  if (crz_struct->src_width >= crz_struct->tar_width)
  {
    REG_CRZ_H_RATIO =
      ((crz_struct->tar_width - 1) * (1 << RESZ_H_RATIO_SHIFT_BITS) +
       (crz_struct->src_width - 1) / 2) / ((crz_struct->src_width - 1));
  }
  else
  {
    REG_CRZ_H_RATIO =
      ((crz_struct->src_width - 1) * (1 << RESZ_H_RATIO_SHIFT_BITS) +
       (crz_struct->tar_width - 1) / 2) / ((crz_struct->tar_width - 1));
  }
  
  if (crz_struct->src_height >= crz_struct->tar_height)
  {
    REG_CRZ_V_RATIO =
      ((crz_struct->tar_height - 1) * (1 << RESZ_V_RATIO_SHIFT_BITS) +
       (crz_struct->src_height - 1) / 2) / ((crz_struct->src_height - 1));
  }
  else
  {
    REG_CRZ_V_RATIO =
      ((crz_struct->src_height - 1) * (1 << RESZ_V_RATIO_SHIFT_BITS) +
       (crz_struct->tar_height - 1) / 2) / ((crz_struct->tar_height - 1));
  }
  
  RESET_CRZ();
}

void
RESZ_CRZ_change_size(kal_uint32 const src_width, kal_uint32 const src_height,
                     kal_uint32 const tar_width, kal_uint32 const tar_height)
{
  SET_CRZ_SRC_SIZE(src_width, src_height);
  /* set target size as the multiples of overlay frame buffer */
  SET_CRZ_TARGET_SIZE(tar_width, tar_height);	
  
  if (src_width >= tar_width)
  {
    REG_CRZ_H_RATIO =
      ((tar_width - 1) * (1 << RESZ_H_RATIO_SHIFT_BITS) +
       (src_width - 1) / 2) / ((src_width - 1));
  }
  else
  {
    REG_CRZ_H_RATIO =
      ((src_width - 1) * (1 << RESZ_H_RATIO_SHIFT_BITS) +
       (tar_width - 1) / 2) / ((tar_width - 1));
  }
  
  if (src_height >= tar_height)
  {
    REG_CRZ_V_RATIO =
      ((tar_height - 1) * (1 << RESZ_V_RATIO_SHIFT_BITS) +
       (src_height - 1) / 2) / ((src_height - 1));
  }
  else
  {
    REG_CRZ_V_RATIO =
      ((src_height - 1) * (1 << RESZ_V_RATIO_SHIFT_BITS) +
       (tar_height - 1) / 2) / ((tar_height - 1));
  }
}

/** \brief Initialize the PRZ subsystem.
 *
 * \ingroup prz
 *
 * This functino will setup the interrupt for the PRZ
 * to level sensitive, and unmask all the interrupts for the
 * PRZ.
 */
void
RESZ_PRZInit(void)
{
  IRQSensitivity(IRQ_RESIZER_PRZ_CODE, LEVEL_SENSITIVE);
  IRQUnmask(IRQ_RESIZER_PRZ_CODE);
}

/** \brief Programmers can use this function to config PRZ.
 *
 * \ingroup prz
 *
 * Before using this function, PRZ should be turned off.
 *
 * \param prz_struct PRZ config structure
 */
void
RESZ_PRZConfig(RESZ_PRZ_STRUCT const * const prz_struct)
{         
  ASSERT((KAL_FALSE == IS_PRZ_START()) &&
         "You should turn off PRZ before calling this function.");
  
  REG_PRZ_CONFIG = 0;
  REG_PRZ_FINE_RESIZE_CFG = 0;
  
  switch (prz_struct->image_src)
  {      
  case RESZ_SOURCE_ROTATOR:
    SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_IMAGE_ROTATOR);
    break;
    
  case RESZ_SOURCE_MP4_DEBLOCKING:
    SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_MP4_DEBLOCKING);
    break;
    
  case RESZ_SOURCE_IBW4:
    SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_IBW4_DMA);
    break;
    
  case RESZ_SOURCE_R2Y:
    SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_R2Y);
    break;
    
  case RESZ_SOURCE_JPEG_DECODER:
    SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_JPEG_DECODER);
    break;
    
  default:
    ASSERT(0);
    break;
  }
  
  if (KAL_TRUE == prz_struct->dedicate_memory)
  {
    SET_PRZ_DEDICATED_MEMORY();
    REG_PRZ_WORK_MEM_ADDR = 0x40000000;
  }
  else
  {
    SET_PRZ_SHARED_MEMORY();
    REG_PRZ_WORK_MEM_ADDR = prz_struct->work_mem_addr;
  }
  
  SET_PRZ_FINE_RESIZE_WORK_MEM_SIZE(prz_struct->work_mem_line);
  
  if (KAL_TRUE == prz_struct->continous)
  {
    SET_PRZ_CONT_RUN_MODE();
  }   
  else
  {
    SET_PRZ_SINGLE_RUN_MODE();
  }
  
  if (KAL_TRUE == prz_struct->int_en)
  {
    ENABLE_PRZ_H_RESIZE_INT();
    ENABLE_PRZ_V_RESIZE_INT();
  }   
  else
  {
    DISABLE_PRZ_H_RESIZE_INT();
    DISABLE_PRZ_V_RESIZE_INT();
  }
  
  {
    kal_uint32 output_module = 0;
    
    if (prz_struct->output_to_CRZ)
    {
      output_module |= PRZ_OUTPUT_CRZ;
    }
    if (prz_struct->output_to_IPP1)
    {
      output_module |= PRZ_OUTPUT_IPP1;
    }
    if (prz_struct->output_to_Y2R1)
    {
      output_module |= PRZ_OUTPUT_Y2R1;
    }
    
    SET_PRZ_OUTPUT(output_module);    
  }
  
  if (KAL_TRUE == prz_struct->coarse_en)
  {
    SET_PRZ_BLOCK_MODE();
    
    SET_PRZ_BLOCK_CS_FACTOR(prz_struct->coarse_ratio);
    SET_PRZ_BLOCK_CS_Y_H_FACTOR(prz_struct->y_h_factor);
    SET_PRZ_BLOCK_CS_Y_V_FACTOR(prz_struct->y_v_factor);
    SET_PRZ_BLOCK_CS_U_H_FACTOR(prz_struct->u_h_factor);
    SET_PRZ_BLOCK_CS_U_V_FACTOR(prz_struct->u_v_factor);
    SET_PRZ_BLOCK_CS_V_H_FACTOR(prz_struct->v_h_factor);
    SET_PRZ_BLOCK_CS_V_V_FACTOR(prz_struct->v_v_factor);
    REG_PRZ_Y_LINE_BUFFER_ADDR = (kal_uint32)prz_struct->y_line_buff_addr;
    REG_PRZ_U_LINE_BUFFER_ADDR = (kal_uint32)prz_struct->u_line_buff_addr;
    REG_PRZ_V_LINE_BUFFER_ADDR = (kal_uint32)prz_struct->v_line_buff_addr;
    SET_PRZ_FINE_RESIZE_LINE_BUFFER(prz_struct->y_line_buff_size);
  }
  else   
  {
    SET_PRZ_PIXEL_MODE();
  }
  
  SET_PRZ_SRC_SIZE(prz_struct->src_width, prz_struct->src_height);
  SET_PRZ_TARGET_SIZE(prz_struct->tar_width, prz_struct->tar_height);
  
  if (prz_struct->src_width == prz_struct->tar_width)
  {
    REG_PRZ_H_RATIO = 1 << RESZ_H_RATIO_SHIFT_BITS;
  }
  else
  {
    REG_PRZ_H_RATIO =
      ((1 << RESZ_H_RATIO_SHIFT_BITS) / prz_struct->tar_width) * prz_struct->src_width;
  }
  
  if (prz_struct->src_height == prz_struct->tar_height)
  {
    REG_PRZ_V_RATIO = (1 << RESZ_V_RATIO_SHIFT_BITS);
  }
  else
  {
    REG_PRZ_V_RATIO =
      ((1 << RESZ_V_RATIO_SHIFT_BITS) / prz_struct->tar_height) * prz_struct->src_height;
  }
  
  REG_PRZ_H_RESIDUAL = prz_struct->src_width % prz_struct->tar_width;
  REG_PRZ_V_RESIDUAL = prz_struct->src_height % prz_struct->tar_height;                        
  
  /* HW issue of PRZ src switch==>reset again */
  RESET_PRZ;
}

kal_uint32
RESZ_PRZGetWorkingMem(kal_bool use_internal_mem,
                      kal_uint32 const output_width)
{
  kal_uint32 const size = output_width * 2 * 4;
  
  if (KAL_TRUE == use_internal_mem)
  {
    return (kal_uint32)intmem_get_buffer(size);
  }
  else
  {
    return (kal_uint32)extmem_get_buffer(size);
  }
}

#endif
