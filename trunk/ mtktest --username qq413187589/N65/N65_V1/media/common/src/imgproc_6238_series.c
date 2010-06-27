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
 *    imgporc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Driver of image processor
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

#include "Drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "reg_base.h"
#include "stack_config.h"
#include "intrCtrl.h"
#include "visual_comm.h"
#include "visualhisr.h"
#include "imgproc.h"
#include "drvpdn.h"
#include "img_comm.h"

/*
NOTE:
1. open
2. select mode
3. set pixel effect or set mask(option)
3. set parameters(option)
4. start
5. stop
6. close

II. CBA and HSA will take effect simutaneously, reset the parameters before
	input the parameters.
*/

/*
* FUNCTION
*	   IMGPROC_Init
*
* DESCRIPTION
*   	Initialize the IMGPROC driver and it should be called only once.
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
kal_int32 IMGPROC_Init(void)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_Open
*
* DESCRIPTION
*   	Set owner of the IMGPROC. While one owner open the IMGPROC, no one
*	is allowed to use IMGPROC untile the owern close it.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     imgproc_dcb.owner
*/
kal_int32 IMGPROC_Open(MMDI_SCENERIO_ID owner)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_Close
*
* DESCRIPTION
*   	Release the ownership of IMGPORC
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     imgproc_dcb.owner
*/
kal_int32 IMGPROC_Close(MMDI_SCENERIO_ID owner)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SelectMode
*
* DESCRIPTION
*   	Selet operation mode for image processor.
*		It determines the color space conversion
*		It must be called before start
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     imgproc_dcb.gmode
*
* NOTE
* RGB->YUV
* RGB->RGB (Memory effect, GIF decoder)
* YUV->YUV, RGB (MPEG4 encoder)
* YUV->YUV (JPEG encoder)
* YUV->RGB (preview, JPEG decoder, MPEG4 dedocer)
*/
kal_int32 IMGPROC_SelectMode(IMGPROC_MODE_ENUM mode, MMDI_SCENERIO_ID owner)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetEffect_Pixel
*
* DESCRIPTION
*   	enable pixel effects
*		set all member to zero to disable all effects
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     imgproc_dcb.feature
*/
kal_int32 IMGPROC_SetPixelEffect(IMGPROC_PIXEL_EFFECT_STURCT *s, MMDI_SCENERIO_ID owner)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetFeature
*
* DESCRIPTION
*   	enable filter effect or pixel effect(cannot function simutaneously)
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
kal_int32 IMGPROC_SetMask(IMGPROC_FILTER_ENUM mask, MMDI_SCENERIO_ID owner)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_Start
*
* DESCRIPTION
*   	Trigger the image processor to work(for both pixel mode and filter mode)
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
kal_int32 IMGPROC_Start(MMDI_SCENERIO_ID owner)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_Stop
*
* DESCRIPTION
*   	1. for pixel mode, it stops all effects
*		2. for filter mode, it stops the process of the filtering
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
kal_int32 IMGPROC_Stop(MMDI_SCENERIO_ID owner)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_WaitComplete
*
* DESCRIPTION
*   	Wait the filtering process to complete(stands for filter mode)
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
// blocking function
kal_int32 IMGPROC_WaitComplete(MMDI_SCENERIO_ID owner)
{
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetHUE
*
* DESCRIPTION
*   	set the parameters for HUE adjustment
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
kal_int32 IMGPROC_SetHUE(MMDI_SCENERIO_ID owner, IMGPROC_HUE_STURCT* s)
{
	if (current_image_data_path_owner!=owner)
  {
		ASSERT(0);
  }
  
	DRV_WriteReg(REG_IMGPROC_HUE11, s->c11);
	DRV_WriteReg(REG_IMGPROC_HUE12, s->c12);
	DRV_WriteReg(REG_IMGPROC_HUE21, s->c21);
	DRV_WriteReg(REG_IMGPROC_HUE22, s->c22);

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetSAT
*
* DESCRIPTION
*   	set the saturations
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
kal_int32 IMGPROC_SetSAT(MMDI_SCENERIO_ID owner, kal_uint8 sat)
{
	if (current_image_data_path_owner!=owner)
  {
		ASSERT(0);
  }
  
	DRV_WriteReg(REG_IMGPROC_SATADJ, sat);
  
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetBrightContrast
*
* DESCRIPTION
*   	Set the parameters for brightness and contrast
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
kal_int32 IMGPROC_SetBrightContrast(MMDI_SCENERIO_ID owner, IMGPROC_BRI_CON_STURCT* s)
{
	if (current_image_data_path_owner!=owner)
  {
		ASSERT(0);
  }
  
	DRV_WriteReg(REG_IMGPROC_BRIADJ1, s->bright);
	DRV_WriteReg(REG_IMGPROC_BRIADJ2, s->dark);
	DRV_WriteReg(REG_IMGPROC_CONADJ, s->contrast);

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetMask
*
* DESCRIPTION
*   	Set the content of the mask(for filtering mode)
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
kal_int32 IMGPROC_SetMaskContent(MMDI_SCENERIO_ID owner, IMGPROC_MASK_STURCT* s)
{
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
  
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetMaskScaleDown
*
* DESCRIPTION
*   	set the parameter of mask scale down
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
kal_int32 IMGPROC_SetMaskScaleDown(MMDI_SCENERIO_ID owner, kal_uint8 scale)
{
	if (current_image_data_path_owner!=owner)
  {
		ASSERT(0);
  }
  
	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetColorize
*
* DESCRIPTION
*   	Set the parameters for colorization
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
kal_int32 IMGPROC_SetColorize(MMDI_SCENERIO_ID owner, IMGPROC_COLORIZE_STRUCT* s)
{
	if (current_image_data_path_owner!=owner)
  {
		ASSERT(0);
  }
  
	DRV_WriteReg(REG_IMGPROC_COLOR1R_OFFX,s->r1x);
	DRV_WriteReg(REG_IMGPROC_COLOR2R_OFFX,s->r2x);
	DRV_WriteReg(REG_IMGPROC_COLOR1G_OFFX,s->g1x);
	DRV_WriteReg(REG_IMGPROC_COLOR2G_OFFX,s->g2x);
	DRV_WriteReg(REG_IMGPROC_COLOR1B_OFFX,s->b1x);
	DRV_WriteReg(REG_IMGPROC_COLOR2B_OFFX,s->b2x);
	DRV_WriteReg(REG_IMGPROC_COLOR1R_OFFY,s->r1y);
	DRV_WriteReg(REG_IMGPROC_COLOR2R_OFFY,s->r2y);
	DRV_WriteReg(REG_IMGPROC_COLOR1G_OFFY,s->g1y);
	DRV_WriteReg(REG_IMGPROC_COLOR2G_OFFY,s->g2y);
	DRV_WriteReg(REG_IMGPROC_COLOR1B_OFFY,s->b1y);
	DRV_WriteReg(REG_IMGPROC_COLOR2B_OFFY,s->b2y);
	DRV_WriteReg(REG_IMGPROC_COLOR0R_SLP,s->r0slp);
	DRV_WriteReg(REG_IMGPROC_COLOR1R_SLP,s->r1slp);
	DRV_WriteReg(REG_IMGPROC_COLOR2R_SLP,s->r2slp);
	DRV_WriteReg(REG_IMGPROC_COLOR0G_SLP,s->g0slp);
	DRV_WriteReg(REG_IMGPROC_COLOR1G_SLP,s->g1slp);
	DRV_WriteReg(REG_IMGPROC_COLOR2G_SLP,s->g2slp);
	DRV_WriteReg(REG_IMGPROC_COLOR0B_SLP,s->b0slp);
	DRV_WriteReg(REG_IMGPROC_COLOR1B_SLP,s->b1slp);
	DRV_WriteReg(REG_IMGPROC_COLOR2B_SLP,s->b2slp);

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGPROC_SetGamma
*
* DESCRIPTION
*   	Set the parameters for gamma correction
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
kal_int32 IMGPROC_SetGamma(MMDI_SCENERIO_ID owner, IMGPROC_GAMMA_STRUCT* s)
{
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
  
	DRV_WriteReg(REG_IMGPROC_GAMMA_CON,s->gamma);
	DRV_WriteReg(REG_IMGPROC_GAMMA_OFF0,s->off0);
	DRV_WriteReg(REG_IMGPROC_GAMMA_OFF1,s->off1);
	DRV_WriteReg(REG_IMGPROC_GAMMA_OFF2,s->off2);
	DRV_WriteReg(REG_IMGPROC_GAMMA_OFF3,s->off3);
	DRV_WriteReg(REG_IMGPROC_GAMMA_OFF4,s->off4);
	DRV_WriteReg(REG_IMGPROC_GAMMA_OFF5,s->off5);
	DRV_WriteReg(REG_IMGPROC_GAMMA_OFF6,s->off6);
	DRV_WriteReg(REG_IMGPROC_GAMMA_OFF7,s->off7);

	DRV_WriteReg(REG_IMGPROC_GAMMA_SLP0,s->slp0);
	DRV_WriteReg(REG_IMGPROC_GAMMA_SLP1,s->slp1);
	DRV_WriteReg(REG_IMGPROC_GAMMA_SLP2,s->slp2);
	DRV_WriteReg(REG_IMGPROC_GAMMA_SLP3,s->slp3);
	DRV_WriteReg(REG_IMGPROC_GAMMA_SLP4,s->slp4);
	DRV_WriteReg(REG_IMGPROC_GAMMA_SLP5,s->slp5);
	DRV_WriteReg(REG_IMGPROC_GAMMA_SLP6,s->slp6);
	DRV_WriteReg(REG_IMGPROC_GAMMA_SLP7,s->slp7);

	return NO_ERROR;
}

#endif
