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
 *   mt6238_mp4_deblk.c
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *   MPEG4 deblocking filter
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "mp4_deblk_6238_series.h"
#include "intrCtrl.h"

/** \brief Initialize the MPEG4 deblocking subsystem.
 *
 * \ingroup mp4_deblk
 *
 * This functino will setup the interrupt for the MPEG4
 * deblocking to level sensitive, and unmask all the
 * interrupts for the MPEG4 deblocking.
 */
void
MP4_DEBLK_Init(void)
{
  IRQSensitivity(IRQ_MP4_DEBLK_CODE, LEVEL_SENSITIVE);
  IRQUnmask(IRQ_MP4_DEBLK_CODE);
}

kal_uint32
MP4_DEBLK_GetWorkingMem(
  kal_bool const use_internal_mem,
  IMGDMA_IRT0_ROT_ENUM const rot,
  kal_uint32 const width,
  kal_uint32 const height)
{
  kal_uint32 size;
  
  /* MP4 DEBLK must use the internal memory as its working
   * memory.
   */
  ASSERT(KAL_TRUE == use_internal_mem);
  
  if ((IRT0_ROT_OFF == rot) || (IRT0_ROT_180 == rot))
  {
    size = (width * 8 * 3) / 2;
  }
  else
  {
    size = (height * 8 * 3) / 2;
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



/** \brief Programmers can use this function to config MPEG4
 * deblocking.
 *
 * \ingroup mp4_deblk
 *
 * Before using this function, MPEG4 deblocking should be
 * turned off.
 *
 * \param mp4_deblk_struct MPEG4 deblocking config
 * structure
 */
void
MP4_DEBLK_Config(
  MP4_DEBLK_STRUCT const * const mp4_deblk_struct)
{
  kal_uint32 before_rot_width, before_rot_height;
  kal_uint32 x_limit, y_limit, mb_x,mb_y, quant_diff;
  
  ASSERT((KAL_FALSE == IS_MP4_DEBLK_START()) &&
         "You should turn off MPEG4 deblocking before calling this function.");
  
  switch (mp4_deblk_struct->rot)
  {
  case MP4_DEBLK_ROT_OFF:
  case MP4_DEBLK_ROT_180:
    before_rot_width = mp4_deblk_struct->width;
    before_rot_height = mp4_deblk_struct->height;
    break;
    
  case MP4_DEBLK_ROT_90:
  case MP4_DEBLK_ROT_270:
    before_rot_width = mp4_deblk_struct->height;
    before_rot_height = mp4_deblk_struct->width;
    break;
    
  default:
    ASSERT(0);
    break;                                    
  }         
  
  REG_MP4_DEBLK_CONF = 0;
  
  ENABLE_MP4_DEBLK_CORE_RST();
  ENABLE_MP4_DEBLK_APB_RST();   
  
  ENABLE_MP4_DEBLK_FILTER();
  
  if (KAL_TRUE == mp4_deblk_struct->int_enable)
  {
    ENABLE_MP4_DEBLK_IRQ();
  }
  else
  {
    DISABLE_MP4_DEBLK_IRQ();
  }
  
  if (KAL_TRUE == mp4_deblk_struct->output_crz)
  {
    ENABLE_MP4_DEBLK_OUTPUT_CRZ();   
  }
  else
  {
    DISABLE_MP4_DEBLK_OUTPUT_CRZ();
  }      
  
  if (KAL_TRUE == mp4_deblk_struct->output_prz)
  {
    ENABLE_MP4_DEBLK_OUTPUT_PRZ();   
  }
  else
  {
    DISABLE_MP4_DEBLK_OUTPUT_PRZ();
  }      
  
  if (KAL_TRUE == mp4_deblk_struct->output_ipp)
  {
    ENABLE_MP4_DEBLK_OUTPUT_IPP();   
  }
  else
  {
    DISABLE_MP4_DEBLK_OUTPUT_IPP();
  }      
  
  if (0 == (before_rot_width % 16))
  {      
    x_limit = (before_rot_width) / 16;
  }
  else
  {
    x_limit = (before_rot_width / 16 + 1);
  }  
  
  SET_MP4_DEBLK_XLIMIT(x_limit);  
  
  if (0 == (x_limit % 4))   
  {      
    mb_x = x_limit / 4;
  }
  else
  {
    mb_x = (x_limit / 4 + 1);
  }  
  
  mb_x *= 4;
  
  if (0 == (before_rot_height % 16))   
  {      
    y_limit = before_rot_height / 16;
  }
  else
  {
    y_limit = (before_rot_height / 16 + 1);
  }  
  SET_MP4_DEBLK_YLIMIT(y_limit);    
  
  if (0 == (y_limit % 4))   
  {      
    mb_y = y_limit / 4;
  }
  else
  {
    mb_y = (y_limit / 4 + 1);
  }  
  
  mb_y *= 4;
  if (KAL_TRUE == mp4_deblk_struct->flip_enable)
  {
    ENABLE_MP4_DEBLK_FLIP();   
    
    switch (mp4_deblk_struct->rot)
    {
    case MP4_DEBLK_ROT_OFF:
      quant_diff = (x_limit - 1);
      break;
      
    case MP4_DEBLK_ROT_90:
      quant_diff = 0;
      break;
      
    case MP4_DEBLK_ROT_180:
      quant_diff = mb_x * (y_limit - 1);
      break;
      
    case MP4_DEBLK_ROT_270:
      quant_diff = mb_x * (y_limit - 1) + (x_limit - 1);
      break;
      
    default:
      break;                                    
    }         
  }
  else
  {
    DISABLE_MP4_DEBLK_FLIP();
    
    switch (mp4_deblk_struct->rot)
    {
    case MP4_DEBLK_ROT_OFF:
      quant_diff = 0;
      break;
      
    case MP4_DEBLK_ROT_90:
      quant_diff = mb_x * (y_limit - 1);
      break;
      
    case MP4_DEBLK_ROT_180:
      quant_diff = mb_x * (y_limit - 1) + (x_limit - 1);
      break;
      
    case MP4_DEBLK_ROT_270:
      quant_diff = (x_limit - 1);
      break;
      
    default:
      break;                                    
    }         
  }      
  
  SET_MP4_DEBLK_ROTATE(mp4_deblk_struct->rot);
  
  {
    ASSERT(0 == (mp4_deblk_struct->fifo_addr % 4));
    
    REG_MP4_DEBLK_LIN_BUF_ADDR = mp4_deblk_struct->fifo_addr;
  }
  
  REG_MP4_DEBLK_QUANT_ADDR = mp4_deblk_struct->quant_addr + quant_diff;
}   
/** @} */

#endif
