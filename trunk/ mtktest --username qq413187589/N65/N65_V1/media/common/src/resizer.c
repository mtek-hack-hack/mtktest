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
 *    resizer.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Driver of image resizer
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "reg_base.h"
#include "Drv_comm.h"
#if (defined(DRV_IDP_6219_SERIES)||defined(DRV_IDP_6225_SERIES)||defined(DRV_IDP_6228_SERIES))
#include "intrCtrl.h"
#include "visual_comm.h"
#include "imgproc.h"
#include "stack_config.h"
#include "resizer.h"
#include "drvpdn.h"

#if (defined(DRV_IDP_6219_SERIES))
// global variable
static RESZ_DCB_STRUCT resz_dcb;

/*
* FUNCTION
*	   RESZ_Init
*
* DESCRIPTION
*   	reset the control block of resizer
*
* CALLS
*
* PARAMETERS
*	   owner
*
* RETURNS
*		status
*
* GLOBALS AFFECTED
*     resz_dcb.owner
*/
kal_int32 API RESZ_Init(void)
{
	kal_mem_set(&resz_dcb,0,sizeof(RESZ_DCB_STRUCT));
	return NO_ERROR;
}
/*
* FUNCTION
*	   RESZ_Open
*
* DESCRIPTION
*   	Obtain the ownership of resizer. Only the owner can control it.
*
* CALLS
*
* PARAMETERS
*	   owner
*
* RETURNS
*		status
*
* GLOBALS AFFECTED
*     resz_dcb.owner
*/
kal_int32 API RESZ_Open(MMDI_SCENERIO_ID owner)
{
	ENTER_CRITICAL();
	ASSERT(resz_dcb.owner == SCENARIO_UNKNOW_ID);
	resz_dcb.owner = owner;
	EXIT_CRITICAL();
   DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_RESZ,PDN_RESZ);

	return NO_ERROR;
}

/*
* FUNCTION
*	   RESZ_Close
*
* DESCRIPTION
*   	Release the ownership of resizer.
*
* CALLS
*
* PARAMETERS
*	   None
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 API RESZ_Close(MMDI_SCENERIO_ID owner)
{
	ASSERT(resz_dcb.owner == owner);
	DRV_WriteReg32(RESZ_CON, 0);
	kal_mem_set(&resz_dcb,0,sizeof(RESZ_DCB_STRUCT));
   DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_RESZ,PDN_RESZ);

	return NO_ERROR;
}

/*
* FUNCTION
*	   RESZ_Config
*
* DESCRIPTION
*   	Set RESZ_CFG register about global configuration
*
* CALLS
*		None
*
* PARAMETERS
*	cfg:
*	   src1: pixel-based image source
*		pcontinue: specify if pixel-based resizing continues
*		pixel_sel: determine if pixel-based image or block-based image is serviced
*		run2: indicate if twice resizing is enabed
*		src2: specify the image source of second run
*	s:
*		for pixel mode => RESZ_PXL_CFG_STRUCT
*		for block mode => RESZ_BLK_CFG_STRUCT
* RETURNS
*	   NO_ERROR
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 API RESZ_Config(RESZ_CFG_STRUCT *cfg, void* s, MMDI_SCENERIO_ID owner)
{
	kal_uint32 reg = 0;

	ASSERT(owner == resz_dcb.owner);
	ASSERT(resz_dcb.state != RESZ_BUSY);

	DRV_WriteReg32(RESZ_CON, RESZ_ALL_RST);
	DRV_WriteReg32(RESZ_CON, 0);

	reg = (cfg->src1)|(cfg->pcontinue << 4)|(cfg->pixel_sel << 5)|
				(cfg->run2 << 6)|(cfg->src2 << 8);
	DRV_WriteReg32(RESZ_CFG, reg);

	resz_dcb.cfg = *cfg;
	if(cfg->pixel_sel)
	{
		RESZ_PXL_CFG_STRUCT *p;

		p = (RESZ_PXL_CFG_STRUCT *)s;
		RESZ_SetWMSize(p->wmsize,KAL_TRUE);
		RESZ_SET_WMBASE_PXL(p->wmbase);
	}
	else
	{
		RESZ_BLK_CFG_STRUCT *p;

		p = (RESZ_BLK_CFG_STRUCT *)s;
		reg = 0;
		reg =  (p->csf)|(p->hy << 4)|(p->vy << 6)|(p->hu << 8)|
				(p->vu << 10)|(p->hv << 12)|(p->vv << 14);
		DRV_WriteReg32(RESZ_BLKCSCFG, reg);

		RESZ_SetWMSize(p->wmsize,KAL_FALSE);
	#if (defined(MT6219))
		RESZ_SET_WMBASE_BLK(p->ywmbase,p->uwmbase,p->vwmbase);
		RESZ_SET_LMBASE_BLK(p->ylmbase,p->ulmbase,p->vlmbase);
		RESZ_SET_LBSIZE_BLK(p->ylbsize,p->ulbsize,p->vlbsize);
	#elif (defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D))
		RESZ_SET_WMBASE_PXL(p->ywmbase);
		RESZ_SET_LMBASE_BLK(p->ylmbase,p->ulmbase,p->vlmbase);
		RESZ_SET_LBSIZE_BLK(p->ylbsize,p->ulbsize,p->vlbsize);
	#endif
	}

	resz_dcb.state = RESZ_READY;

	return NO_ERROR;
}

/*
* FUNCTION
*	   RESZ_SetWMSize
*
* DESCRIPTION
*   	Setting the working memory size.It specifies how many lines can be
		filled into working memory for each color component in the block-based mode
		In pixel based-mode, the register specifies how many lines can be filled into
		working memory.
*
* CALLS
*
* PARAMETERS
*	   size: lines can be filled into working memory
*	   pixel: is pixel mode
*
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 INTERN RESZ_SetWMSize(kal_uint16 size, kal_bool pixel)
{
	if(pixel)
	{
		ASSERT((size < 17) && (size > 3));
	}
	else
	{
		ASSERT((size & 1) == 0);	// must be even for block mode
		ASSERT(size < 2047);			// maximum = 2046
	}
	DRV_Reg32(RESZ_FRCFG) &= 0xffff;
	DRV_Reg32(RESZ_FRCFG) |= (size << 16);

	return NO_ERROR;
}

/*
* FUNCTION
*	   RESZ_SetSize
*
* DESCRIPTION
*   	setting the source width and height and target ones
*
* CALLS
*
* PARAMETERS
*	   src_w: width of source image
*	   src_h: height of source image
*	   tar_w: width of target image
*	   tar_h: height of target image
*		run: src indicate first or second run(0: first, 1: sencond)
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 API RESZ_SetSize(kal_uint32 src_w, kal_uint32 src_h, kal_uint32 tar_w, kal_uint32 tar_h, MMDI_SCENERIO_ID owner)
{
	kal_uint32 reg;

	ASSERT(owner == resz_dcb.owner);
	ASSERT(resz_dcb.state != RESZ_BUSY);

	if( (src_w > 2047)||(src_w > 2047)||(src_w > 2047)||(src_w > 2047))
		return RESZ_ERR_INVALID_SIZE;

/* Hardware limitation */
	if (resz_dcb.owner==SCENARIO_IMG_EFFECT_ID||resz_dcb.owner==SCENARIO_JPEG_ENCODE_ID)
		*((volatile unsigned int *) 0x80610090) &= ~0x200;	
	else
	{
		if (src_h==tar_h)
			*((volatile unsigned int *) 0x80610090) |= 0x200;
		else
			*((volatile unsigned int *) 0x80610090) &= ~0x200;
	}		
	reg = ((src_h<<16)|src_w);
	DRV_WriteReg32(RESZ_SRCSZ1, reg);
	reg = ((tar_h<<16)|tar_w);
	DRV_WriteReg32(RESZ_TARSZ1, reg);

	// set ratios
	reg = (kal_uint32)((src_w<<RESZ_H_RATIO_SHIFT_BITS)/tar_w);
	DRV_WriteReg32(RESZ_HRATIO1, reg);
	reg = (kal_uint32)((src_h<<RESZ_V_RATIO_SHIFT_BITS)/tar_h);
	DRV_WriteReg32(RESZ_VRATIO1, reg);

	// set residual
	reg = (kal_uint16)(src_w%tar_w);
	if(reg > RESZ_HRES1_MAX)
		return RESZ_ERR_INVALID_SIZE;
//	DRV_WriteReg32(RESZ_HRES1, reg);
	DRV_WriteReg32(RESZ_HRES1, 0);
	reg = (kal_uint16)(src_h%tar_h);
	if(reg > RESZ_VRES1_MAX)
		return RESZ_ERR_INVALID_SIZE;
//	DRV_WriteReg32(RESZ_VRES1, reg);
	DRV_WriteReg32(RESZ_VRES1, 0);

	return NO_ERROR;
}

/*
* FUNCTION
*	   RESZ_SetSize2
*
* DESCRIPTION
*   	setting the source width and height and target ones for twice resizing
*
* CALLS
*
* PARAMETERS
*	   src_w: width of source image
*	   src_h: height of source image
*	   tar_w: width of target image
*	   tar_h: height of target image
*		run: src indicate first or second run(0: first, 1: sencond)
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 API RESZ_SetSize2(kal_uint32 src_w, kal_uint32 src_h, kal_uint32 tar_w, kal_uint32 tar_h, MMDI_SCENERIO_ID owner)
{
	kal_uint32 reg;

	ASSERT(resz_dcb.state != RESZ_BUSY);

	if( (src_w > 2047)||(src_w > 2047)||(src_w > 2047)||(src_w > 2047))
		return RESZ_ERR_INVALID_SIZE;

	reg = ((src_h<<16)|src_w);
	DRV_WriteReg32(RESZ_SRCSZ2, reg);
	reg = ((tar_h<<16)|tar_w);
	DRV_WriteReg32(RESZ_TARSZ2, reg);

	// set ratios
	reg = (kal_uint32)((src_w<<RESZ_H_RATIO_SHIFT_BITS)/tar_w);
	DRV_WriteReg32(RESZ_HRATIO2, reg);
	reg = (kal_uint32)((src_h<<RESZ_V_RATIO_SHIFT_BITS)/tar_h);
	DRV_WriteReg32(RESZ_VRATIO2, reg);

	// set residual
	reg = (kal_uint16)(src_w%tar_w);
	if(reg > RESZ_HRES1_MAX)
		return RESZ_ERR_INVALID_SIZE;
//	DRV_WriteReg32(RESZ_HRES2, reg);
	DRV_WriteReg32(RESZ_HRES2, 0);
	reg = (kal_uint16)(src_h%tar_h);
	if(reg > RESZ_VRES1_MAX)
		return RESZ_ERR_INVALID_SIZE;
//	DRV_WriteReg32(RESZ_VRES2, reg);
	DRV_WriteReg32(RESZ_VRES2, 0);

	return NO_ERROR;
}

/*
* FUNCTION
*	   RESZ_Start
*
* DESCRIPTION
*   	Trigger the resizing process
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 API RESZ_Start(MMDI_SCENERIO_ID owner)
{
	ASSERT(owner == resz_dcb.owner);

	ASSERT(resz_dcb.state == RESZ_READY);
	resz_dcb.state = RESZ_BUSY;

	DRV_WriteReg32(RESZ_CON, 0);
	if(resz_dcb.cfg.pixel_sel)
		DRV_WriteReg32(RESZ_CON, RESZ_PXL_EN);
	else
		DRV_WriteReg32(RESZ_CON, RESZ_BLK_EN);

	return NO_ERROR;
}

/*
* FUNCTION
*	   RESZ_Stop
*
* DESCRIPTION
*   	stop the resizing process.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 API RESZ_Stop(MMDI_SCENERIO_ID owner)
{
	ASSERT(owner == resz_dcb.owner);

	DRV_WriteReg32(RESZ_CON, RESZ_ALL_RST);
	resz_dcb.state = RESZ_READY;

	return NO_ERROR;
}

/*
* FUNCTION
*	   RESZ_Stop
*
* DESCRIPTION
*   	stop the resizing process.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
kal_bool API RESZ_CheckBusy(void)
{
	kal_uint32 reg;

	reg = DRV_Reg32(RESZ_STA);

	if(reg != 0)
		return KAL_TRUE;

	return KAL_FALSE;
}
#elif (defined(DRV_IDP_6228_SERIES))

void RESZ_DRZConfig(RESZ_DRZ_STRUCT *drz_struct)
{
   STOP_DRZ;
   if(drz_struct->image_src==RESZ_SOURCE_IBW3)
   {
	   SET_DRZ_SRC_IBW3_DMA;
	}   
	else if(drz_struct->image_src==RESZ_SOURCE_MPEG4_ENCODE_DMA)
	{
	   SET_DRZ_SRC_VIDEO_ENCODE_DMA;   
	}   
	else
	   ASSERT(0);
	if(drz_struct->auto_restart==KAL_TRUE)   
	{
	   ENABLE_DRZ_AUTO_RESTART;
   }
	else
	{
	   DISABLE_DRZ_AUTO_RESTART;
	}   
	if(drz_struct->int_en==KAL_TRUE)   
	{
	   ENABLE_DRZ_INT;
	}
	else
	{
	   DISABLE_DRZ_INT;
   }   
   
	REG_DRZ_SOURCE_IMAGE_SIZE=((drz_struct->src_height-1)<<16)|(drz_struct->src_width-1);
	REG_DRZ_TARGET_IMAGE_SIZE=((drz_struct->tar_height-1)<<16)|(drz_struct->tar_width-1);
	
	REG_DRZ_H_RATIO =((drz_struct->src_width/drz_struct->tar_width)<<16)|((drz_struct->src_width%drz_struct->tar_width));
	REG_DRZ_V_RATIO =((drz_struct->src_height/drz_struct->tar_height)<<16)|((drz_struct->src_height%drz_struct->tar_height));
	
	START_DRZ;
}   

void RESZ_CRZConfig(RESZ_CRZ_STRUCT *crz_struct)
{
   RESET_CRZ;
	REG_CRZ_CTRL=0;
	if(crz_struct->dedicate_memory==KAL_TRUE)
	{
	   SET_CRZ_DEDICATED_MEMORY;
	   REG_CRZ_WORK_MEM_ADDR=0x40000000;	/* dummy for hardware issue */
	}
	else
	{
	   SET_CRZ_SHARED_MEMORY;  
	   REG_CRZ_WORK_MEM_ADDR=crz_struct->work_mem_addr;
	}      
	
	SET_CRZ_PIXEL_BASED_IMAGE;
	
   if(crz_struct->continous==KAL_TRUE)
   {
	   SET_CRZ_CONT_RUN_MODE;
	}   
	else
	{
	   SET_CRZ_SINGLE_RUN_MODE;
   }   
   
   switch(crz_struct->image_src)
   {
      case RESZ_SOURCE_ISP:
         SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_CAMERA_ISP);
      break;
      case RESZ_SOURCE_MPEG4_ENCODE_DMA:
         SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_MPEG4_ENCODE_DMA);
      break;
      case RESZ_SOURCE_MPEG4_DECODE_DMA:
         SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_MPEG4_DECODE_DMA);
      break;
      case RESZ_SOURCE_IBW4:
         SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_IBW_DMA);
      break;
      case RESZ_SOURCE_IPP:
         SET_CRZ_PIXEL_BASED_SRC(CRZ_CONFIG_PIXEL_SRC_IPP);
      break;
      default:
         ASSERT(0);
      break;         	   
   }
   
   if(crz_struct->int_en==KAL_TRUE)
   {
	   ENABLE_CRZ_H_RESIZE_INT;
	   ENABLE_CRZ_V_RESIZE_INT;
	}
	else
	{
	   DISABLE_CRZ_H_RESIZE_INT;
	   DISABLE_CRZ_V_RESIZE_INT;
	}      
   
   SET_CRZ_SRC_SIZE(crz_struct->src_width, crz_struct->src_height);
	/* set target size as the multiples of overlay frame buffer */
	SET_CRZ_TARGET_SIZE(crz_struct->tar_width,crz_struct->tar_height);	
	
	if (crz_struct->src_width==crz_struct->tar_width)
		REG_CRZ_H_RATIO=1<<RESZ_H_RATIO_SHIFT_BITS;
	else
		REG_CRZ_H_RATIO=((1<<RESZ_H_RATIO_SHIFT_BITS)/crz_struct->tar_width)*crz_struct->src_width;
		
	if (crz_struct->src_height==crz_struct->tar_height)
		REG_CRZ_V_RATIO=(1<<RESZ_V_RATIO_SHIFT_BITS);
	else
		REG_CRZ_V_RATIO=((1<<RESZ_V_RATIO_SHIFT_BITS)/crz_struct->tar_height)*crz_struct->src_height;

	REG_CRZ_H_RESIDUAL=crz_struct->src_width%crz_struct->tar_width;
	REG_CRZ_V_RESIDUAL=crz_struct->src_height%crz_struct->tar_height;
	
	REG_CRZ_FINE_RESIZE_CFG=0;
	SET_CRZ_FINE_RESIZE_WORK_MEM_SIZE(crz_struct->work_mem_line);
	
	ENABLE_CRZ;         
}   

void RESZ_PRZConfig(RESZ_PRZ_STRUCT *prz_struct)
{         
   RESET_PRZ;   
   REG_PRZ_CONFIG=0;
   REG_PRZ_FINE_RESIZE_CFG=0;
   
   switch(prz_struct->image_src)
   {
      case RESZ_SOURCE_MPEG4_ENCODE_DMA:
          SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_MPEG4_ENCODE_DMA);
      break;
      case RESZ_SOURCE_MPEG4_DECODE_DMA:
         SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_MPEG4_DECODE_DMA);
      break;
      case RESZ_SOURCE_IBW4:
         SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_IBW4_DMA);
      break;
      case RESZ_SOURCE_IPP:
         SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_IPP);
      break;
      case RESZ_SOURCE_JPEG_DECODER:
         SET_PRZ_SRC(PRZ_CONFIG_PIXEL_SRC_JPEG_DECODER);
      break;      
      default:
         ASSERT(0);
      break;   
   }
   if(prz_struct->dedicate_memory==KAL_TRUE)
   {
      SET_PRZ_DEDICATED_MEMORY;
      REG_PRZ_WORK_MEM_ADDR=0x40000000;
   }
   else
   {
      SET_PRZ_SHARED_MEMORY;
      REG_PRZ_WORK_MEM_ADDR=prz_struct->work_mem_addr;
   }   
   SET_PRZ_FINE_RESIZE_WORK_MEM_SIZE(prz_struct->work_mem_line);
   if(prz_struct->continous==KAL_TRUE)
   {
      SET_PRZ_CONT_MODE;
   }      
   else
   {
      SET_PRZ_SINGLE_MODE;
   }   
   if(prz_struct->int_en==KAL_TRUE)
   {
      
   }      
   else
   {
      
   }   
   if(prz_struct->output_2_IPP==KAL_TRUE)
   {
      SET_PRZ_FINE_RESIZE_OUTPUT_IPP;
   }
   if(prz_struct->coarse_en==KAL_TRUE)
   {
      SET_PRZ_BLOCK_MODE;
      SET_PRZ_BLOCK_CS_FACTOR(prz_struct->coarse_ratio);
      SET_PRZ_BLOCK_CS_Y_H_FACTOR(prz_struct->y_h_factor);
      SET_PRZ_BLOCK_CS_Y_V_FACTOR(prz_struct->y_v_factor);
      SET_PRZ_BLOCK_CS_U_H_FACTOR(prz_struct->u_h_factor);
		SET_PRZ_BLOCK_CS_U_V_FACTOR(prz_struct->u_v_factor);
		SET_PRZ_BLOCK_CS_V_H_FACTOR(prz_struct->v_h_factor);
		SET_PRZ_BLOCK_CS_V_V_FACTOR(prz_struct->v_v_factor);
		REG_PRZ_Y_LINE_BUFFER_ADDR=(kal_uint32)prz_struct->y_line_buff_addr;
		REG_PRZ_U_LINE_BUFFER_ADDR=(kal_uint32)prz_struct->u_line_buff_addr;
		REG_PRZ_V_LINE_BUFFER_ADDR=(kal_uint32)prz_struct->v_line_buff_addr;
		SET_PRZ_FINE_RESIZE_LINE_BUFFER(prz_struct->y_line_buff_size);
   }
   else   
   {
      SET_PRZ_PIXEL_MODE;
   }   
      
   SET_PRZ_SRC_SIZE(prz_struct->src_width,prz_struct->src_height);
	SET_PRZ_TARGET_SIZE(prz_struct->tar_width,prz_struct->tar_height);
	
	if (prz_struct->src_width==prz_struct->tar_width)
		REG_PRZ_H_RATIO=1<<RESZ_H_RATIO_SHIFT_BITS;
	else
		REG_PRZ_H_RATIO=((1<<RESZ_H_RATIO_SHIFT_BITS)/prz_struct->tar_width)*prz_struct->src_width;
		
	if (prz_struct->src_height==prz_struct->tar_height)
		REG_PRZ_V_RATIO=(1<<RESZ_V_RATIO_SHIFT_BITS);
	else
		REG_PRZ_V_RATIO=((1<<RESZ_V_RATIO_SHIFT_BITS)/prz_struct->tar_height)*prz_struct->src_height;

	REG_PRZ_H_RESIDUAL=prz_struct->src_width%prz_struct->tar_width;
	REG_PRZ_V_RESIDUAL=prz_struct->src_height%prz_struct->tar_height;                                              
   
   /* HW issue of PRZ src switch==>reset again */
	RESET_PRZ;
	if(prz_struct->coarse_en==KAL_TRUE)
	{
	   ENABLE_PRZ;   
	}
	else
	{
	   ENABLE_PRZ_H_LINE;
	   ENABLE_PRZ_V_LINE;      
	}      
}  
#elif defined(DRV_IDP_6225_SERIES)
 
/*This file is to implement MT6225 Resizer driver*/

#include "intrCtrl.h"
#include "visual_comm.h"
#include "imgproc.h" 
#include "stack_config.h"
#include "resizer.h"
#include "drvpdn.h"   
#include "isp_if.h"   
#include "visualhisr.h"
#include "lcd_if.h"

RESZ_DCB_STRUCT resz_dcb;
kal_uint32 resize_preview_buffer=0;
kal_bool resize_buffer1_is_valid=KAL_TRUE;
kal_bool resize_buffer2_is_valid=KAL_TRUE;
#ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO
static kal_uint32 resize_wait_zoom_update_count=0;
static kal_uint32 resize_wait_zoom_update_max=4;
static kal_bool resize_wait_zoom_update=KAL_FALSE;
#endif

/*internal use function*/
#ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO
static void RESZ_sync_lcm_update(void)//XXXXXO, add in 6225
{
   extern kal_uint8 preview_frame_update_flag;
   if(resz_dcb.owner==SCENARIO_MJPEG_ENCODE_ID)
   {      
	   LCD_recode_preview(mjpeg_encode_data.hw_update_layer,
	                      mjpeg_encode_data.frame_buffer_address);  
	}
	else
   {      
      LCD_preview(isp_preview_config_data.hw_update_layer,
	               isp_preview_config_data.frame_buffer_address, 
	               isp_preview_config_data.frame_buffer_address);	                         
   }   
	                  
   preview_frame_update_flag=KAL_FALSE;
   
} 
  
#endif

void RESZ_start_zoom(void)
{
#ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO
   kal_uint32 save_irq_mask=0;
         
   save_irq_mask=SaveAndSetIRQMask();   
   if (KAL_TRUE==sync_lcm_enable_mode)
   {      
      resize_wait_zoom_update=KAL_TRUE;      
      sync_lcm_enable_mode=KAL_FALSE;
   }   
   RestoreIRQMask(save_irq_mask);
#endif   //__SYNC_LCM_SW_SUPPORT__       
}   
#ifdef MT6225_IDP_DEBUG
kal_uint32 dbg_time1=0;
#endif
static void RESZ_config_rgb_buffer(kal_uint32 buffer1, kal_uint32 buffer2)
{
   DRV_WriteReg32(RESZ_TMBASE_RGB1,buffer1);
   DRV_WriteReg32(RESZ_TMBASE_RGB2,buffer2); 
}
static void RESZ_mjpeg_update_lcd_buffer(void)
{   
   kal_uint32 save_irq_mask=0;
   kal_uint32 addr;
   if(resz_dcb.owner==SCENARIO_MJPEG_ENCODE_ID)
   {  
	   /*for video recode*/
      if (resize_preview_buffer==0)
      {  
         #ifdef __SW_JPEG_CODEC_SUPPORT__
         if(is_jpeg_sw_rgb565_buff_release())      
         #else
            if(1)
         #endif       
         {
            #ifdef MT6225_IDP_DEBUG
            kal_prompt_trace(MOD_BMT,"jpeg free"); 
            #endif
            addr=mjpeg_encode_data.frame_buffer_address1;                     
            resize_preview_buffer=1;	                         
         }   
         else
         {
            #ifdef MT6225_IDP_DEBUG 
            kal_prompt_trace(MOD_BMT,"jpeg busy"); 
            #endif
            addr=mjpeg_encode_data.frame_buffer_address;                        
         }      
         RESZ_config_rgb_buffer(addr, addr);	      
         #ifndef __SYNC_LCM_SW_SUPPORT__
         if(1) 
         #else
         if(KAL_FALSE==sync_lcm_enable_mode)
         #endif       
         {
            /*update LCD*///XXXXXO, remove to EINT
         #ifdef MT6225_IDP_DEBUG
	      dbg_time1=drv_get_current_time();
         kal_prompt_trace(MOD_BMT,"resizer interrupt time %d",dbg_time1); 
         kal_prompt_trace(MOD_BMT,"buf1"); 
         #endif         
	      LCD_recode_preview(mjpeg_encode_data.hw_update_layer,
	                         mjpeg_encode_data.frame_buffer_address);             
      }
      else
      {
	         #ifdef __SYNC_LCM_SW_SUPPORT__
	         preview_frame_ready_cb(); //preview_frame_update_flag=KAL_TRUE;           
            #endif           
	      }   	                     
      }
      else
      {
         #ifdef __SW_JPEG_CODEC_SUPPORT__
         if(is_jpeg_sw_rgb565_buff_release())      
         #else
            if(1)
         #endif 
         {
            #ifdef MT6225_IDP_DEBUG 
            kal_prompt_trace(MOD_BMT,"jpeg free"); 
            #endif
            addr=mjpeg_encode_data.frame_buffer_address;                     
            resize_preview_buffer=0;	                         
         }   
         else
         {
            #ifdef MT6225_IDP_DEBUG  
            kal_prompt_trace(MOD_BMT,"jpeg busy"); 
            #endif
            addr=mjpeg_encode_data.frame_buffer_address1;                        
         }
         RESZ_config_rgb_buffer(addr, addr);	   
         #ifndef __SYNC_LCM_SW_SUPPORT__
         if(1) 
         #else
         if(KAL_FALSE==sync_lcm_enable_mode)
         #endif
         {
            /*update LCD*///XXXXXO, remove to EINT HISR
         #ifdef MT6225_IDP_DEBUG
	      dbg_time1=drv_get_current_time();
         kal_prompt_trace(MOD_BMT,"resizer interrupt time %d",dbg_time1); 
         kal_prompt_trace(MOD_BMT,"buf2"); 
         #endif         	      	 
	      LCD_recode_preview(mjpeg_encode_data.hw_update_layer,
	                         mjpeg_encode_data.frame_buffer_address1);         
	         #ifdef __SYNC_LCM_SW_SUPPORT__
	         save_irq_mask=SaveAndSetIRQMask();   	         	         
	         if(KAL_TRUE==resize_wait_zoom_update)
	         {
	            sync_lcm_enable_mode=KAL_TRUE;	            
	            resize_wait_zoom_update=KAL_FALSE;
      }            
	         RestoreIRQMask(save_irq_mask);   
	         #endif
   }
   else 
   {	   
            #ifdef __SYNC_LCM_SW_SUPPORT__
            preview_frame_ready_cb();  //preview_frame_update_flag=KAL_TRUE;          
            #endif        
         }             	                         
      }            	   	   	      	 
   }      	               	      
}   
static void RESZ_preview_update_lcd_buffer(void)
{   
   kal_uint32 save_irq_mask=0;
   kal_uint32 addr;      
      #if 1/*use sw to configure resizer buffer addrs to make sure LCD and resizer use
             different buffer*/
         if(resize_preview_buffer==0)
	      {
      #ifdef MT6225_IDP_DEBUG 
      dbg_time1=drv_get_current_time();
      kal_prompt_trace(MOD_BMT,"resizer interrupt time %d",dbg_time1); 
            kal_prompt_trace(MOD_BMT,"buf1"); 
      #endif            
      
           resize_preview_buffer=1;                   
	        addr=isp_preview_config_data.frame_buffer_address1;
	        RESZ_config_rgb_buffer(addr, addr);
	      #ifndef __SYNC_LCM_SW_SUPPORT__
         if(1) 
         #else
         if(KAL_FALSE==sync_lcm_enable_mode)
         #endif
         {
            //XXXXXO, remove to EINT HISR          
	   LCD_preview(isp_preview_config_data.hw_update_layer,
	               isp_preview_config_data.frame_buffer_address, 
	                     isp_preview_config_data.frame_buffer_address);
                #ifdef MT6225_IDP_DEBUG 
	        kal_prompt_trace(MOD_BMT,"update address%d", isp_preview_config_data.frame_buffer_address);                     	                               
	        kal_prompt_trace(MOD_BMT,"chanage resz add%d", addr);                    
                #endif 
	      }
	      else
	      {
            #ifdef __SYNC_LCM_SW_SUPPORT__
            preview_frame_ready_cb();//preview_frame_update_flag=KAL_TRUE;
            #endif  
         }              
	   }
	   else
	   {
            #ifdef MT6225_IDP_DEBUG
	         dbg_time1=drv_get_current_time();
            kal_prompt_trace(MOD_BMT,"resizer interrupt time %d",dbg_time1); 
            kal_prompt_trace(MOD_BMT,"buf2"); 
            #endif
            resize_preview_buffer=0;                           
            addr=isp_preview_config_data.frame_buffer_address;
            RESZ_config_rgb_buffer(addr, addr);	               
                        
         
         #ifndef __SYNC_LCM_SW_SUPPORT__
         if(1) 
         #else         
         if(KAL_FALSE==sync_lcm_enable_mode)
         #endif
         {
            //XXXXXO, remove to EINT HISR                      
	         LCD_preview(isp_preview_config_data.hw_update_layer,
	                     isp_preview_config_data.frame_buffer_address1,
	                     isp_preview_config_data.frame_buffer_address1);
	         #ifdef __SYNC_LCM_SW_SUPPORT__
	            save_irq_mask=SaveAndSetIRQMask();   	         
	            if(KAL_TRUE==resize_wait_zoom_update)
	            {	            
	               if (resize_wait_zoom_update_count>resize_wait_zoom_update_max)
	               {
	                  sync_lcm_enable_mode=KAL_TRUE;	            
	                  resize_wait_zoom_update=KAL_FALSE;	   
	                  resize_wait_zoom_update_count=0;            
	               }
	               else
	               {
	                  resize_wait_zoom_update_count++;
	               }      
	            }   	            	            	         
	            RestoreIRQMask(save_irq_mask);              
	         #endif
	         	         
	        #ifdef MT6225_IDP_DEBUG              
	         kal_prompt_trace(MOD_BMT,"update address%d", isp_preview_config_data.frame_buffer_address1);                    
	                            
            kal_prompt_trace(MOD_BMT,"chanage resz add%d", addr);                           
                #endif
	      }               
         else
         {               
            #ifdef __SYNC_LCM_SW_SUPPORT__
            preview_frame_ready_cb(); //preview_frame_update_flag=KAL_TRUE;           
            #endif        
         }                                          
	}               
      #else /*In 6225 HW the buffer order is 2->1->2->1 instead of 1->2->1->2*/               
         #ifdef MT6225_IDP_DEBUG 
/* under construction !*/
/* under construction !*/
         #endif            
/* under construction !*/
/* under construction !*/
/* under construction !*/
	   #endif               
   }	               	      

static void RESZ_update_lcd_buffer(void)
{   
   kal_uint32 save_irq_mask=0;
   kal_uint32 addr;
   if(resz_dcb.owner==SCENARIO_MJPEG_ENCODE_ID)
   {
      RESZ_mjpeg_update_lcd_buffer();
   }
   else 
   {
      RESZ_preview_update_lcd_buffer();
   }      	               	      
}   

kal_bool mjpeg_get_encode_buffer(kal_uint32 *buf)
{
   if(resz_dcb.owner==SCENARIO_MJPEG_ENCODE_ID)
   {
      
      IRQMask(IRQ_RESZ_CODE);
      if(resize_preview_buffer==0)
      {
         *buf=mjpeg_encode_data.frame_buffer_address1;         
      }
      else
      {
         *buf=mjpeg_encode_data.frame_buffer_address;         
}   
      #ifdef __SW_JPEG_CODEC_SUPPORT__                 
      set_jpeg_sw_rgb565_buff_occupied();                
      #endif   

      IRQUnmask(IRQ_RESZ_CODE);
      return KAL_TRUE;         
   }
   else
      return KAL_FALSE;         
}   
/**
 * Resize HISR.
 *
 * @param None.
 *
 * @return None.
 */
void RESZ_HISR(void)
{
#if defined(MT6225)	
	kal_uint32 reg;
   reg = DRV_Reg32(RESZ_INT);
   		  
 	if (reg & RESZ_INT_PELHRINT)
	{	   	     		
	}	
	if(reg & RESZ_INT_PELVRINT)
	{
	   if(mjpeg_is_encode_enable())/**/
	   {
	      if(resz_dcb.cfg.resize_cb!=NULL) 
	      {
	         resz_dcb.cfg.resize_cb(0);
	      }  	   	   	   
	   }   
	   #if (defined (WEBCAM_SUPPORT))
	   /*web camera*/
	   if(resz_dcb.owner==SCENARIO_USBVIDEO_CAPTURE_JPEG_ID)
	   {
	      if(resz_dcb.cfg.resize_cb!=NULL) 
	      {
	         resz_dcb.cfg.resize_cb(0);
	      }  	   	   	   
	   }   
	   #endif/*web camera*/
	   /*update LCD*/
	   RESZ_update_lcd_buffer();         	   
	}
	if(reg & RESZ_INT_Y2RINT)
	{
	   
	}	
	IRQUnmask(IRQ_RESZ_CODE);
#elif defined(MT6235)	
	kal_uint32 reg;
   reg = DRV_Reg32(RESZ_INT_STATUS);
   		  
 	if (reg & RESZ_FRAME_START_INT_BIT)
	{	   	     		
	}	
	if(reg & RESZ_FRAME_END_INT_BIT)
	{
	   if(mjpeg_is_encode_enable())/**/
	   {
	      if(resz_dcb.cfg.resize_cb!=NULL) 
	      {
	         resz_dcb.cfg.resize_cb(0);
	      }  	   	   	   
	   }   
	   #if (defined (WEBCAM_SUPPORT))
	   /*web camera*/
	   if(resz_dcb.owner==SCENARIO_USBVIDEO_CAPTURE_JPEG_ID)
	   {
	      if(resz_dcb.cfg.resize_cb!=NULL) 
	      {
	         resz_dcb.cfg.resize_cb(0);
	      }  	   	   	   
	   }   
	   #endif/*web camera*/
	   /*update LCD*/
	   RESZ_update_lcd_buffer();         	   
	}
	IRQUnmask(IRQ_RESZ_CODE);
#endif
}
/*XXXXX just for debug, this function should be provided by JPEG codec*/
kal_bool resize_buff_debug=KAL_TRUE;
/**
 * use to check if buffer is release.
 *
 * @param buffer buffer address 
 *
 * @return None.
 */
kal_bool RESZ_is_buffer_release(kal_uint32 buffer)
{
   return resize_buff_debug;
}   
/**
 * Resize LISR.
 *
 * @param None.
 *
 * @return None.
 */
void RESZ_LISR(void)
{	
   IRQMask(IRQ_RESZ_CODE);
   visual_active_hisr(VISUAL_RESIZER_HISR_ID);  
}
/**
 * Resize initial function.
 *
 * @param None.
 *
 * @return NO_ERROR, OK.
 */
kal_int32 RESZ_Init(void)
{
   IRQ_Register_LISR(IRQ_RESZ_CODE, RESZ_LISR,"RESIZER");
	IRQSensitivity(IRQ_RESZ_CODE,LEVEL_SENSITIVE);
	VISUAL_Register_HISR(VISUAL_RESIZER_HISR_ID,RESZ_HISR);
	IRQUnmask(IRQ_RESZ_CODE);	
	kal_mem_set(&resz_dcb,0,sizeof(RESZ_DCB_STRUCT));
	return NO_ERROR;
}
/**
 * Resize open function.
 *
 * @param owner resizer scenario ID.
 *
 * @return NO_ERROR, OK.
 */
kal_int32 RESZ_Open(MMDI_SCENERIO_ID owner)
{
	ENTER_CRITICAL();
	ASSERT(resz_dcb.owner == SCENARIO_UNKNOW_ID);
	resz_dcb.owner = owner;
	EXIT_CRITICAL();
   DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_RESZ,PDN_RESZ);

	return NO_ERROR;
}
/**
 * Resize stop function.
 *
 * @param owner resizer scenario ID.
 *
 * @return NO_ERROR, OK.
 */
/*resizer stop function*/
kal_int32 RESZ_Stop(MMDI_SCENERIO_ID owner)
{
   #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO, add in 6225   
   extern kal_uint8 preview_frame_update_flag;
   #endif
	ASSERT(owner == resz_dcb.owner);

   #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO, stop update, wait next frame ready
		 preview_frame_update_flag=KAL_FALSE;
   #endif
   lcd_reset_preview();
   if(resz_dcb.owner==SCENARIO_MJPEG_ENCODE_ID)
   {
      RESZ_config_rgb_buffer(mjpeg_encode_data.frame_buffer_address, mjpeg_encode_data.frame_buffer_address);
      resize_preview_buffer=0; 	 
   }   
   if(resz_dcb.owner==SCENARIO_CAMERA_PREVIEW_ID)
   {
      RESZ_config_rgb_buffer(isp_preview_config_data.frame_buffer_address, isp_preview_config_data.frame_buffer_address);
      resize_preview_buffer=0; 	 
   }   
   
	RESET_RESZ();	
	resz_dcb.state = RESZ_READY;

	return NO_ERROR;
}
/**
 * Resize start function.
 *
 * @param owner resizer scenario ID.
 *
 * @return NO_ERROR, OK.
 */
/*resizer stop function*/
kal_int32 RESZ_Start(MMDI_SCENERIO_ID owner)
{
	ASSERT(owner == resz_dcb.owner);

	ASSERT(resz_dcb.state == RESZ_READY);
	resz_dcb.state = RESZ_BUSY;

	RESET_RESZ();		 
	RESZ_START();   

	return NO_ERROR;
}
/**
 * Resize close function.
 *
 * @param owner resizer scenario ID.
 *
 * @return NO_ERROR, OK.
 */
/*resizer close function*/
kal_int32 RESZ_Close(MMDI_SCENERIO_ID owner)
{
   #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO, add in 6225   
   extern void (*sync_lcm_update_cb) (void);   
   #endif
   
	ASSERT(resz_dcb.owner == owner);
	RESZ_Stop(owner);
	
	#ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO, add in 6225		
		EINT_Mask(sync_lcm_channel_number);
      sync_lcm_enable_mode=KAL_FALSE;
      sync_lcm_update_cb=NULL;		
   #endif
	DRV_WriteReg32(RESZ_CON, 0);
	kal_mem_set(&resz_dcb,0,sizeof(RESZ_DCB_STRUCT));
   DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_RESZ,PDN_RESZ);

	return NO_ERROR;
}
/**
 * Resize config function.
 *
 * @param resize_struct resizer configuration parameter.
 *
 * @return NO_ERROR, OK.
 */
void RESZ_Config(RESZ_CFG_STRUCT *resize_struct)
{
#if defined(MT6225)
   kal_uint32 config_reg=0;
   kal_uint32 horizontal_ratio=0, vertical_ratio=0;
   kal_uint32 horizontal_res=0, vertical_res=0;
       
   RESET_RESZ()
      
   config_reg|=RESZ_CFG_PSEL;   
   if(resize_struct->continous==KAL_TRUE)
      config_reg|=RESZ_CFG_PCON;
         
   DRV_WriteReg32(RESZ_CFG,config_reg);   
      
   if(resize_struct->yuv_to_rgb==KAL_TRUE)
   { 
      DRV_WriteReg32(RESZ_TMBASE_RGB1,resize_struct->rgb_tar_base1);
      DRV_WriteReg32(RESZ_TMBASE_RGB2,resize_struct->rgb_tar_base2); 
      RESZ_RGB_2_YUB_ENABLE();
   }
   else
   {
     
      DRV_WriteReg32(RESZ_TMBASE_Y,resize_struct->y_tar_base);
      DRV_WriteReg32(RESZ_TMBASE_U,resize_struct->u_tar_base);     
      DRV_WriteReg32(RESZ_TMBASE_V,resize_struct->v_tar_base);     
      RESZ_RGB_2_YUB_DISABLE(); 
   }  
   
   if(resize_struct->int_en==KAL_TRUE)
   { 
      RESZ_HR_INT_ENABLE();
      RESZ_VR_INT_ENABLE();     
      RESZ_RGB2YUV_INT_ENABLE();
   }
   else
   {
      RESZ_HR_INT_DISABLE();
      RESZ_VR_INT_DISABLE();     
      RESZ_RGB2YUV_INT_DISABLE(); 
   }       
   
   switch(resize_struct->coarse_resize)
   {
      case RESZ_COARSE_NONE:
         SET_RESZ_COARSE_RESIZE_NONE;
         break;
      case RESZ_COARSE_1_2:
         SET_RESZ_COARSE_RESIZE_1_2;
         break;
      case RESZ_COARSE_1_4:
         SET_RESZ_COARSE_RESIZE_1_4;
         break;
      case RESZ_COARSE_1_8:
         SET_RESZ_COARSE_RESIZE_1_8;
         break;
      default:
         SET_RESZ_COARSE_RESIZE_NONE;
         break;            
   }   
   
      
   SET_RESZ_SRC_SIZE(resize_struct->source_width,resize_struct->source_height);      
   SET_RESZ_TARGET_SIZE(resize_struct->target_width,resize_struct->target_height);      
   	
   /*width ratio*/	
   if(resize_struct->source_width==resize_struct->target_width)
      horizontal_ratio=(1<<RESZ_H_RATIO_SHIFT_BITS);
   else
   {      
      horizontal_ratio=((1<<RESZ_H_RATIO_SHIFT_BITS)*(kal_uint32)resize_struct->source_width/(kal_uint32)resize_struct->target_width);
   }   
      
   if(resize_struct->source_height==resize_struct->target_height)
      vertical_ratio=(1<<RESZ_V_RATIO_SHIFT_BITS);
   else
      vertical_ratio=((1<<RESZ_V_RATIO_SHIFT_BITS)*(kal_uint32)resize_struct->source_height/(kal_uint32)resize_struct->target_height);   
      
   horizontal_res=resize_struct->source_width%resize_struct->target_width;
   vertical_res=resize_struct->source_height%resize_struct->target_height;
         
   DRV_WriteReg32(RESZ_HRATIO1,horizontal_ratio);
   DRV_WriteReg32(RESZ_VRATIO1,vertical_ratio);   
   DRV_WriteReg32(RESZ_HRES1, horizontal_res);
   DRV_WriteReg32(RESZ_VRES1, vertical_res);   
         
   SET_RESZ_FINE_RESIZE_WORK_MEM_SIZE(resize_struct->wmsize);   
   DRV_WriteReg32(RESZ_PRWMBASE, resize_struct->wmbase);   
      
   DRV_WriteReg32(RESZ_TMBASE_RGB1,resize_struct->rgb_tar_base1);
   DRV_WriteReg32(RESZ_TMBASE_RGB2,resize_struct->rgb_tar_base2);    
   resz_dcb.state = RESZ_READY;
 	//Jeff add
 	resz_dcb.cfg.resize_cb=resize_struct->resize_cb;
   
   //RESZ_START();   
#elif defined(MT6235)  
  kal_uint32 lbmax=0, min_width;
      
  REG_RESZ_CTRL=0;
  
  SET_RESZ_DEDICATED_MEMORY();
  SET_RESZ_OUTPUT_FMT(RESZ_struct->fmt);
  if(RESZ_struct->fmt==RESZ_OUTPUT_FMT_RGB565)
  {
      ENABLE_RESZ_RGB_DOUBLE_BUF();
      REG_RESZ_RGB_BASE1=RESZ_struct->rgb_tar_base1;
      REG_RESZ_RGB_BASE2=RESZ_struct->rgb_tar_base2;      
  }
  else if((RESZ_struct->fmt==RESZ_OUTPUT_FMT_YUV420)||
          (RESZ_struct->fmt==RESZ_OUTPUT_FMT_YUV422))
  {
      REG_RESZ_Y_BASE=RESZ_struct->y_tar_base;
      REG_RESZ_U_BASE=RESZ_struct->u_tar_base;
      REG_RESZ_V_BASE=RESZ_struct->v_tar_base;
  } 
   
  #if 1
  lbmax=6; 
  SET_RESZ_LBMAX(lbmax);
  #else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #endif
	
  if (KAL_TRUE == RESZ_struct->continous)
   {
    SET_RESZ_CONT_RUN_MODE();
	}   
	else
	{
    SET_RESZ_SINGLE_RUN_MODE();
   }             
  
  if (KAL_TRUE == RESZ_struct->int_en)
   {
      ENABLE_RESZ_FS_INT();    
      ENABLE_RESZ_FE_INT();    
	}
	else
	{
      DISABLE_RESZ_FS_INT();
      DISABLE_RESZ_FE_INT();
	}       
   
   SET_RESZ_SRC_SIZE(RESZ_struct->source_width, RESZ_struct->source_height);
	/* set target size as the multiples of overlay frame buffer */
	SET_RESZ_TARGET_SIZE(RESZ_struct->target_width,RESZ_struct->target_height);	
		
	if (RESZ_struct->source_width>=RESZ_struct->target_width)
  {
    REG_RESZ_H_RATIO =
      ((RESZ_struct->target_width - 1) * (1 << RESZ_H_RATIO_SHIFT_BITS) +
       (RESZ_struct->source_width - 1) / 2) / ((RESZ_struct->source_width - 1));
  }
	else
  {
    REG_RESZ_H_RATIO =
      ((RESZ_struct->source_width - 1) * (1 << RESZ_H_RATIO_SHIFT_BITS) +
       (RESZ_struct->target_width - 1) / 2) / ((RESZ_struct->target_width - 1));
  }
		
	if (RESZ_struct->source_height>=RESZ_struct->target_height)
  {
    REG_RESZ_V_RATIO =
      ((RESZ_struct->target_height - 1) * (1 << RESZ_V_RATIO_SHIFT_BITS) +
       (RESZ_struct->source_height - 1) / 2) / ((RESZ_struct->source_height - 1));
  }
	else
  {
    REG_RESZ_V_RATIO =
      ((RESZ_struct->source_height - 1) * (1 << RESZ_V_RATIO_SHIFT_BITS) +
       (RESZ_struct->target_height - 1) / 2) / ((RESZ_struct->target_height - 1));
  }		
  RESET_RESZ();
  //ENABLE_RESZ(); 
#endif
   
}
/**
 * to set resize .
 *
 * @param src_w resizer source width.
 * @param src_h resizer source height.
 * @param tar_w resizer target widht.
 * @param tar_h resizer target height.
 * @param owner resizer scenario ID.
 *
 * @return NO_ERROR, OK.
 */
/*resize size config function, used in cameara digital zoom */
kal_int32 RESZ_SetSize(kal_uint32 src_w, kal_uint32 src_h, 
                       kal_uint32 tar_w, kal_uint32 tar_h, MMDI_SCENERIO_ID owner)
{   
#if defined(MT6225)   	
   kal_uint32 horizontal_ratio=0, vertical_ratio=0;
   kal_uint32 horizontal_res=0, vertical_res=0;
                
   ASSERT(owner == resz_dcb.owner);
                
   SET_RESZ_SRC_SIZE(src_w,src_h);      
   SET_RESZ_TARGET_SIZE(tar_w,tar_h);      
   	
   /*width ratio*/	
   if(tar_w==src_w)
      horizontal_ratio=(1<<RESZ_H_RATIO_SHIFT_BITS);
   else
   {      
      horizontal_ratio=((1<<RESZ_H_RATIO_SHIFT_BITS)*(kal_uint32)src_w/(kal_uint32)tar_w);
   }   
      
   if(src_h==tar_h)
      vertical_ratio=(1<<RESZ_V_RATIO_SHIFT_BITS);
   else
      vertical_ratio=((1<<RESZ_V_RATIO_SHIFT_BITS)*(kal_uint32)src_h/(kal_uint32)tar_h);   
      
   horizontal_res=src_w%tar_w;
   vertical_res=src_h%tar_h;
         
   DRV_WriteReg32(RESZ_HRATIO1,horizontal_ratio);
   DRV_WriteReg32(RESZ_VRATIO1,vertical_ratio);   
   DRV_WriteReg32(RESZ_HRES1, horizontal_res);
   DRV_WriteReg32(RESZ_VRES1, vertical_res);                     
#elif defined(MT6235)
  if (src_width>=tar_width)                                         
  {                                                                 
    REG_RESZ_H_RATIO =                                              
      ((tar_width - 1) * (1 << RESZ_H_RATIO_SHIFT_BITS) +           
       (src_width - 1) / 2) / ((src_width - 1));                    
  }                                                                 
	else                                                            
  {                                                                 
    REG_RESZ_H_RATIO =                                              
      ((src_width - 1) * (1 << RESZ_H_RATIO_SHIFT_BITS) +           
       (tar_width - 1) / 2) / ((tar_width - 1));                    
  }                                                                 
   
	if (src_height>=tar_height)                                     
  {                                                                 
    REG_RESZ_V_RATIO =                                              
      ((tar_height - 1) * (1 << RESZ_V_RATIO_SHIFT_BITS) +          
       (src_height - 1) / 2) / ((src_height - 1));                  
  }                                                                 
	else                                                            
  {                                                                 
    REG_RESZ_V_RATIO =                                              
      ((src_height - 1) * (1 << RESZ_V_RATIO_SHIFT_BITS) +          
       (tar_height - 1) / 2) / ((tar_height - 1));                  
  }		                                                            
  SET_RESZ_SRC_SIZE(src_width, src_height);	                        
  SET_RESZ_TARGET_SIZE(tar_width,tar_height);	                    

#endif   
   return NO_ERROR;
}   
/**
 * to set resizer configuration according to different scenarios .
 * 
 * @param owner resizer scenario ID.
 *
 * @return KAL_TRUE, OK.
 */
kal_uint8 config_pixel_resizer(MMDI_SCENERIO_ID scenario_id)
{
   #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO, add in 6225
   extern void (*sync_lcm_update_cb) (void);   
   #endif
    RESZ_DCB_STRUCT resizer_dcb;
    RESZ_CFG_STRUCT resize_struct;    
     
    resizer_dcb.owner = scenario_id;
    RESZ_Open(resizer_dcb.owner);

    kal_mem_set(&resize_struct,0,sizeof(RESZ_CFG_STRUCT));
    switch (scenario_id)
    {    
        case SCENARIO_CAMERA_PREVIEW_ID:                    
           #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO
           sync_lcm_update_cb=RESZ_sync_lcm_update;
           //DRV_WriteReg(0x80120150,0x000f);           
           sync_lcm_enable_mode=KAL_TRUE;
           EINT_UnMask(sync_lcm_channel_number);
           #endif //__SYNC_LCM_SW_SUPPORT__
           resize_struct.yuv_to_rgb=KAL_TRUE;
           resize_struct.rgb_tar_base1=(kal_uint32)isp_preview_config_data.frame_buffer_address;
           resize_struct.rgb_tar_base2=(kal_uint32)isp_preview_config_data.frame_buffer_address1;
           resize_struct.source_width=isp_preview_config_data.source_width;
           resize_struct.source_height=isp_preview_config_data.source_height;
           resize_struct.target_width=isp_preview_config_data.target_width;;
           resize_struct.target_width&=0xfffffffe;   
           resize_struct.target_height=isp_preview_config_data.target_height;
           resize_struct.target_height&=0xfffffffe;
           resize_struct.continous=KAL_TRUE;
           resize_struct.wmbase=(kal_uint32) intmem_get_buffer(IDP_CP_MAXIMUM_RESZ_WM_SIZE);   
           resize_struct.wmsize=4;//(IDP_CP_MAXIMUM_RESZ_WM_SIZE/(resize_struct.target_width*3));//g_wmsize;//24                      
           resize_struct.int_en=KAL_TRUE;
           break;    
        case SCENARIO_MJPEG_ENCODE_ID:
           #ifdef __SYNC_LCM_SW_SUPPORT__//XXXXXO
           sync_lcm_update_cb=RESZ_sync_lcm_update;
            //DRV_WriteReg(0x80120150,0x000f);           
           sync_lcm_enable_mode=KAL_TRUE;
           EINT_UnMask(sync_lcm_channel_number);
           #endif //__SYNC_LCM_SW_SUPPORT__
           
           /*XXXXX need to config*/
           resize_struct.yuv_to_rgb=KAL_TRUE;
           resize_struct.rgb_tar_base1=(kal_uint32)mjpeg_encode_data.frame_buffer_address;
           resize_struct.rgb_tar_base2=(kal_uint32)mjpeg_encode_data.frame_buffer_address1;
           resize_struct.source_width=mjpeg_encode_data.source_width;
           resize_struct.source_height=mjpeg_encode_data.source_height;
           resize_struct.target_width=mjpeg_encode_data.target_width;;
           resize_struct.target_width&=0xfffffffe;   
           resize_struct.target_height=mjpeg_encode_data.target_height;
           resize_struct.target_height&=0xfffffffe;
           resize_struct.continous=KAL_TRUE;
           resize_struct.wmbase=(kal_uint32) intmem_get_buffer(IDP_VR_MAXIMUM_RESZ_WM_SIZE);   
           resize_struct.wmsize=4;//(IDP_VR_MAXIMUM_RESZ_WM_SIZE/(resize_struct.target_width*3));//g_wmsize;//24                      
           resize_struct.int_en=KAL_TRUE;
           resize_struct.resize_cb=mjpeg_encode_data.mjpeg_encode_cb;
           
           break;        
        case SCENARIO_CAMERA_CAPTURE_JPEG_ID:                        
           
           resize_struct.yuv_to_rgb=KAL_FALSE;
           resize_struct.y_tar_base=(kal_uint32)isp_capture_jpeg_data.y_address;
           resize_struct.u_tar_base=(kal_uint32)isp_capture_jpeg_data.u_address;
           resize_struct.v_tar_base=(kal_uint32)isp_capture_jpeg_data.v_address;           
           
           resize_struct.source_width=isp_capture_jpeg_data.source_width;
           resize_struct.source_height=isp_capture_jpeg_data.source_height;
           resize_struct.target_width=isp_capture_jpeg_data.target_width;;
           resize_struct.target_width&=0xfffffffe;   
           resize_struct.target_height=isp_capture_jpeg_data.target_height;
           resize_struct.target_height&=0xfffffffe;
           resize_struct.continous=KAL_FALSE;
           resize_struct.wmbase=(kal_uint32) intmem_get_buffer(IDP_IC_MAXIMUM_RESZ_WM_SIZE);   
           resize_struct.wmsize=4;//g_wmsize;//24
           resize_struct.int_en=KAL_FALSE;
           resize_struct.yuv_to_rgb=KAL_FALSE;                                 
           break;    
        #if (defined(WEBCAM_SUPPORT))
        case SCENARIO_USBVIDEO_CAPTURE_JPEG_ID:
           resize_struct.yuv_to_rgb=KAL_FALSE;
           resize_struct.y_tar_base=(kal_uint32)isp_capture_jpeg_data.y_address;
           resize_struct.u_tar_base=(kal_uint32)isp_capture_jpeg_data.u_address;
           resize_struct.v_tar_base=(kal_uint32)isp_capture_jpeg_data.v_address;           
           
           resize_struct.source_width=isp_capture_jpeg_data.source_width;
           resize_struct.source_height=isp_capture_jpeg_data.source_height;
           resize_struct.target_width=isp_capture_jpeg_data.target_width;;
           resize_struct.target_width&=0xfffffffe;   
           resize_struct.target_height=isp_capture_jpeg_data.target_height;
           resize_struct.target_height&=0xfffffffe;
           resize_struct.continous=KAL_FALSE;
           resize_struct.wmbase=(kal_uint32) intmem_get_buffer(IDP_IC_MAXIMUM_RESZ_WM_SIZE);   
           resize_struct.wmsize=4;//(IDP_IC_MAXIMUM_RESZ_WM_SIZE/(resize_struct.target_width*3));//g_wmsize;//24                      
           resize_struct.yuv_to_rgb=KAL_FALSE;                       
           resize_struct.int_en=KAL_TRUE;
           resize_struct.resize_cb=isp_capture_jpeg_data.cam_capture_jpeg_cb;          
           break;    
        #endif      
        case SCENARIO_CAMERA_CAPTURE_MEM_ID:                                       
           resize_struct.yuv_to_rgb=KAL_TRUE;
           resize_struct.rgb_tar_base1=(kal_uint32)isp_capture_mem_data.imgdma_buffer_address;
           resize_struct.rgb_tar_base2=(kal_uint32)isp_capture_mem_data.imgdma_buffer_address;
           resize_struct.source_width=isp_capture_mem_data.source_width;
           resize_struct.source_height=isp_capture_mem_data.source_height;
           resize_struct.target_width=isp_capture_mem_data.target_width;;
           resize_struct.target_width&=0xfffffffe;   
           resize_struct.target_height=isp_capture_mem_data.target_height;
           resize_struct.target_height&=0xfffffffe;
           resize_struct.continous=KAL_FALSE;
           resize_struct.wmbase=(kal_uint32) intmem_get_buffer(IDP_IC_MAXIMUM_RESZ_WM_SIZE);   
           resize_struct.wmsize=4;//(IDP_IC_MAXIMUM_RESZ_WM_SIZE/(resize_struct.target_width*3));//g_wmsize;//24                      
           resize_struct.int_en=KAL_FALSE;
           break;    
    }        
             
    RESZ_Config((RESZ_CFG_STRUCT *) &resize_struct);            
    RESZ_Start(scenario_id);      

    return KAL_TRUE;
}   /* config_pixel_resizer() */

/**
 * to set resizer configuration according to different scenarios .
 * 
 * @param owner resizer scenario ID.
 *
 * @return KAL_TRUE, OK.
 */
kal_bool RESZ_CheckBusy(void)
{
	kal_uint32 reg;

	reg = DRV_Reg32(RESZ_STA);
	
	if((reg&0xe))
		return KAL_TRUE;
	
	return KAL_FALSE;
}
 
#endif   /* MT6225,MT6235 */
#endif
