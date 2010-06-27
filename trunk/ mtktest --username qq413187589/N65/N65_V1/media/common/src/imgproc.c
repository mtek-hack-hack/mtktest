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
#if (defined(DRV_IDP_6219_SERIES)||defined(DRV_IDP_6228_SERIES))
#include "reg_base.h"
#include "stack_config.h"
#include "intrCtrl.h"
#include "visual_comm.h"
#include "visualhisr.h"
#include"imgproc.h"
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

// global variables
#if (defined(DRV_IDP_6219_SERIES))
static IMGPROC_DCB_STRUCT imgproc_dcb;
#endif
static kal_eventgrpid IMGPROC_Events = 0;

/*
* FUNCTION
*	   IMGPROC_HISR_Entry
*
* DESCRIPTION
*   	Hisr for image processor(stands for filter mode)
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     imgproc_dcb.state
*/
void INTERN IMGPROC_HISR_Entry(void)
{
	kal_uint32 reg = DRV_Reg32(IMGPROC_INTR);
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(imgproc_dcb.mask != FILTER_NONE);
	ASSERT(imgproc_dcb.state == IMGPROC_BUSY);

	if(reg & IMGPROC_INTR_INT)
	{
	   if(imgproc_dcb.cb)
	   	imgproc_dcb.cb();
	   else
	   	kal_set_eg_events(IMGPROC_Events,IMGPROC_EVENT,KAL_OR);
	}
	else
		ASSERT(0);

	imgproc_dcb.state = IMGPROC_READY;
#elif (defined(DRV_IDP_6228_SERIES))
	if(reg & IMGPROC_INTR_INT)
	 	kal_set_eg_events(IMGPROC_Events,IMGPROC_EVENT,KAL_OR);
	else
		ASSERT(0);
#endif
	IRQClearInt(IRQ_IMGPROC_CODE);
	IRQUnmask(IRQ_IMGPROC_CODE);
}

/*
* FUNCTION
*	   IMGPROC_LISR_Entry
*
* DESCRIPTION
*   	Lisr for image processor(stands for filter mode)
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
void INTERN IMGPROC_LISR_Entry(void)
{
   IRQMask(IRQ_IMGPROC_CODE);
   visual_active_hisr(VISUAL_IMGPROC_HISR_ID);
}

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
kal_int32 API IMGPROC_Init(void)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(IMGPROC_Events == 0);
	IMGPROC_Events = kal_create_event_group("IMGPROC Events");
	VISUAL_Register_HISR(VISUAL_IMGPROC_HISR_ID,IMGPROC_HISR_Entry);
   IRQ_Register_LISR(IRQ_IMGPROC_CODE, IMGPROC_LISR_Entry,"IMGPROC");
	IRQSensitivity(IRQ_IMGPROC_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_IMGPROC_CODE);
	kal_mem_set(&imgproc_dcb,0,sizeof(IMGPROC_DCB_STRUCT));
#elif (defined(DRV_IDP_6228_SERIES))
	IMGPROC_Events = kal_create_event_group("IMGPROC Events");
	VISUAL_Register_HISR(VISUAL_IMGPROC_HISR_ID,IMGPROC_HISR_Entry);
   IRQ_Register_LISR(IRQ_IMGPROC_CODE, IMGPROC_LISR_Entry,"IMGPROC");
	IRQSensitivity(IRQ_IMGPROC_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_IMGPROC_CODE);
#endif
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
kal_int32 API IMGPROC_Open(MMDI_SCENERIO_ID owner)
{
#if (defined(DRV_IDP_6219_SERIES))
	ENTER_CRITICAL();
	ASSERT(imgproc_dcb.owner == SCENARIO_UNKNOW_ID);
	imgproc_dcb.owner = owner;
	EXIT_CRITICAL();
   DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_IMGPROC,PDN_IMGPROC);
#endif
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
kal_int32 API IMGPROC_Close(MMDI_SCENERIO_ID owner)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(imgproc_dcb.owner == owner);
	IMGPROC_Stop(owner);
	IMGPROC_RESET();
	IMGPROC_DISABLE_INT();
	kal_mem_set(&imgproc_dcb,0,sizeof(IMGPROC_DCB_STRUCT));
   DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_IMGPROC,PDN_IMGPROC);
#endif
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
kal_int32 API IMGPROC_SelectMode(IMGPROC_MODE_ENUM mode, MMDI_SCENERIO_ID owner)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(imgproc_dcb.owner == owner);
	ASSERT(imgproc_dcb.state != IMGPROC_BUSY);
	imgproc_dcb.gmode = mode;
	imgproc_dcb.state = IMGPROC_READY;
#endif
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
kal_int32 API IMGPROC_SetPixelEffect(IMGPROC_PIXEL_EFFECT_STURCT *s, MMDI_SCENERIO_ID owner)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(imgproc_dcb.owner == owner);
	ASSERT(imgproc_dcb.state != IMGPROC_BUSY);
	imgproc_dcb.feature = (s->hsa) | (s->cba << 3) | (s->inv << 4) |(s->clr << 5) |
			(s->gma << 6);
#endif
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
kal_int32 API IMGPROC_SetMask(IMGPROC_FILTER_ENUM mask, MMDI_SCENERIO_ID owner)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(imgproc_dcb.owner == owner);
	ASSERT(imgproc_dcb.state != IMGPROC_BUSY);
	imgproc_dcb.mask = mask;
#endif
	return NO_ERROR;
}
#if 0
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
kal_int32 API IMGPROC_Start(MMDI_SCENERIO_ID owner)
{
#if (defined(DRV_IDP_6219_SERIES))
	kal_uint32 reg = 0;

	ASSERT(imgproc_dcb.owner == owner);
	ASSERT(imgproc_dcb.state == IMGPROC_READY);
	if(imgproc_dcb.mask != FILTER_NONE && imgproc_dcb.feature != 0)
		ASSERT(0);
	imgproc_dcb.state = IMGPROC_BUSY;
	reg = (imgproc_dcb.feature) | (imgproc_dcb.mask) | (imgproc_dcb.gmode);
	DRV_WriteReg(IMGPROC_IMAGE_CON, reg);
	if(imgproc_dcb.mask != FILTER_NONE)
	{
		IMGPROEC_ENABLE_INT();
		IMGPROC_START_FILTER();
	}
#endif
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
kal_int32 API IMGPROC_Stop(MMDI_SCENERIO_ID owner)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(imgproc_dcb.owner == owner);
	if(imgproc_dcb.mask == FILTER_NONE)
	{	// pixel
		DRV_Reg(IMGPROC_IMAGE_CON) &= 0xff00;
	}
	else // filtering
	{
		IMGPROC_STOP_FILTER();
	}
	imgproc_dcb.state = IMGPROC_READY;
#endif
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
kal_int32 API IMGPROC_WaitComplete(MMDI_SCENERIO_ID owner)
{
	kal_uint32 flags;
	kal_status status;
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(owner == imgproc_dcb.owner);
	ASSERT(imgproc_dcb.mask != FILTER_NONE);
	status = kal_retrieve_eg_events(IMGPROC_Events,IMGPROC_EVENT ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);
	ASSERT(status == KAL_SUCCESS);
#elif (defined(DRV_IDP_6228_SERIES))
	status = kal_retrieve_eg_events(IMGPROC_Events,IMGPROC_EVENT ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);
	if (status!=KAL_SUCCESS)
		ASSERT(0);
#endif
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
kal_int32 API IMGPROC_SetHUE(MMDI_SCENERIO_ID owner, IMGPROC_HUE_STURCT* s)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(owner == imgproc_dcb.owner);
#elif (defined(DRV_IDP_6228_SERIES))
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
#endif

	DRV_WriteReg(IMGPROC_HUE11,s->c11);
	DRV_WriteReg(IMGPROC_HUE12,s->c12);
	DRV_WriteReg(IMGPROC_HUE21,s->c21);
	DRV_WriteReg(IMGPROC_HUE22,s->c22);

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
kal_int32 API IMGPROC_SetSAT(MMDI_SCENERIO_ID owner, kal_uint8 sat)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(owner == imgproc_dcb.owner);
#elif (defined(DRV_IDP_6228_SERIES))
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
#endif
	DRV_WriteReg(IMGPROC_SAT,sat);
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
kal_int32 API IMGPROC_SetBrightContrast(MMDI_SCENERIO_ID owner, IMGPROC_BRI_CON_STURCT* s)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(owner == imgproc_dcb.owner);
#elif (defined(DRV_IDP_6228_SERIES))
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
#endif
	DRV_WriteReg(IMGPROC_BRIADJ1,s->bright);
	DRV_WriteReg(IMGPROC_BRIADJ2,s->dark);
	DRV_WriteReg(IMGPROC_CONADJ,s->contrast);

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
kal_int32 API IMGPROC_SetMaskContent(MMDI_SCENERIO_ID owner, IMGPROC_MASK_STURCT* s)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(owner == imgproc_dcb.owner);
#elif (defined(DRV_IDP_6228_SERIES))
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
#endif
	DRV_WriteReg(IMGPROC_MASK11,s->c11);
	DRV_WriteReg(IMGPROC_MASK12,s->c12);
	DRV_WriteReg(IMGPROC_MASK13,s->c13);
	DRV_WriteReg(IMGPROC_MASK21,s->c21);
	DRV_WriteReg(IMGPROC_MASK22,s->c22);
	DRV_WriteReg(IMGPROC_MASK23,s->c23);
	DRV_WriteReg(IMGPROC_MASK31,s->c31);
	DRV_WriteReg(IMGPROC_MASK32,s->c32);
	DRV_WriteReg(IMGPROC_MASK33,s->c33);

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
kal_int32 API IMGPROC_SetMaskScaleDown(MMDI_SCENERIO_ID owner, kal_uint8 scale)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(owner == imgproc_dcb.owner);
#elif (defined(DRV_IDP_6228_SERIES))
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
#endif
	DRV_WriteReg(IMGPROC_SCALE,scale);

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
kal_int32 API IMGPROC_SetColorize(MMDI_SCENERIO_ID owner, IMGPROC_COLORIZE_STRUCT* s)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(owner == imgproc_dcb.owner);
#elif (defined(DRV_IDP_6228_SERIES))
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
#endif
	DRV_WriteReg(IMGPROC_COLOR1R_OFFX,s->r1x);
	DRV_WriteReg(IMGPROC_COLOR2R_OFFX,s->r2x);
	DRV_WriteReg(IMGPROC_COLOR1G_OFFX,s->g1x);
	DRV_WriteReg(IMGPROC_COLOR2G_OFFX,s->g2x);
	DRV_WriteReg(IMGPROC_COLOR1B_OFFX,s->b1x);
	DRV_WriteReg(IMGPROC_COLOR2B_OFFX,s->b2x);
	DRV_WriteReg(IMGPROC_COLOR1R_OFFY,s->r1y);
	DRV_WriteReg(IMGPROC_COLOR2R_OFFY,s->r2y);
	DRV_WriteReg(IMGPROC_COLOR1G_OFFY,s->g1y);
	DRV_WriteReg(IMGPROC_COLOR2G_OFFY,s->g2y);
	DRV_WriteReg(IMGPROC_COLOR1B_OFFY,s->b1y);
	DRV_WriteReg(IMGPROC_COLOR2B_OFFY,s->b2y);
	DRV_WriteReg(IMGPROC_COLOR0R_SLP,s->r0slp);
	DRV_WriteReg(IMGPROC_COLOR1R_SLP,s->r1slp);
	DRV_WriteReg(IMGPROC_COLOR2R_SLP,s->r2slp);
	DRV_WriteReg(IMGPROC_COLOR0G_SLP,s->g0slp);
	DRV_WriteReg(IMGPROC_COLOR1G_SLP,s->g1slp);
	DRV_WriteReg(IMGPROC_COLOR2G_SLP,s->g2slp);
	DRV_WriteReg(IMGPROC_COLOR0B_SLP,s->b0slp);
	DRV_WriteReg(IMGPROC_COLOR1B_SLP,s->b1slp);
	DRV_WriteReg(IMGPROC_COLOR2B_SLP,s->b2slp);

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
kal_int32 API IMGPROC_SetGamma(MMDI_SCENERIO_ID owner, IMGPROC_GAMMA_STRUCT* s)
{
#if (defined(DRV_IDP_6219_SERIES))
	ASSERT(owner == imgproc_dcb.owner);
#elif (defined(DRV_IDP_6228_SERIES))
	if (current_image_data_path_owner!=owner)
		ASSERT(0);
#endif
	DRV_WriteReg(IMGPROC_GAMMA_CON,s->gamma);
	DRV_WriteReg(IMGPROC_GAMMA_OFF0,s->off0);
	DRV_WriteReg(IMGPROC_GAMMA_OFF1,s->off1);
	DRV_WriteReg(IMGPROC_GAMMA_OFF2,s->off2);
	DRV_WriteReg(IMGPROC_GAMMA_OFF3,s->off3);
	DRV_WriteReg(IMGPROC_GAMMA_OFF4,s->off4);
	DRV_WriteReg(IMGPROC_GAMMA_OFF5,s->off5);
	DRV_WriteReg(IMGPROC_GAMMA_OFF6,s->off6);
	DRV_WriteReg(IMGPROC_GAMMA_OFF7,s->off7);

	DRV_WriteReg(IMGPROC_GAMMA_SLP0,s->slp0);
	DRV_WriteReg(IMGPROC_GAMMA_SLP1,s->slp1);
	DRV_WriteReg(IMGPROC_GAMMA_SLP2,s->slp2);
	DRV_WriteReg(IMGPROC_GAMMA_SLP3,s->slp3);
	DRV_WriteReg(IMGPROC_GAMMA_SLP4,s->slp4);
	DRV_WriteReg(IMGPROC_GAMMA_SLP5,s->slp5);
	DRV_WriteReg(IMGPROC_GAMMA_SLP6,s->slp6);
	DRV_WriteReg(IMGPROC_GAMMA_SLP7,s->slp7);

	return NO_ERROR;
}

#endif /* MT6219 */

