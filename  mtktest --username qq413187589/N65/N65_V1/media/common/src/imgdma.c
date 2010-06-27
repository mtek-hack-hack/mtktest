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
 *    imgdma.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Driver of image dma
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "Drv_comm.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "visual_comm.h"
#include "imgproc.h"
#include "imgdma.h"
#include "visualhisr.h"
#include "drvpdn.h"
#include "img_comm.h"

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
   #include "SST_sla.h"
#endif

extern kal_bool MPEG4_RECODE_START;

extern kal_uint8 current_video_buffer_count;
extern kal_uint32 mpeg4_video_buffer[2];

void video_enc_reset_buffer_counter(void)
{
	current_video_buffer_count=0;
}

#if (defined(DRV_IDP_6219_SERIES)||defined(DRV_IDP_6228_SERIES))
   static void image_dma_LISR(void);

   #if (defined(DRV_IDP_6219_SERIES))
      IMGDMA_DCB_STRUCT imgdma_dcb;
   #endif
#endif

#if defined(DRV_IDP_6219_SERIES)||defined(DRV_IDP_6228_SERIES)
/*
* FUNCTION
*	   IMGDMA_Init
*
* DESCRIPTION
*   	initialize the IMGDMA software blocks
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
void API
IMGDMA_Init(void)
{
  void (*LISR_entry)(void);

#if (defined(DRV_IDP_6219_SERIES)||defined(DRV_IDP_6228_SERIES))
  LISR_entry = image_dma_LISR;
#endif

  IRQ_Register_LISR(IRQ_IMGDMA_CODE, LISR_entry, "IMGDMA");
  IRQSensitivity(IRQ_IMGDMA_CODE, LEVEL_SENSITIVE);
  IRQUnmask(IRQ_IMGDMA_CODE);

#if (defined(DRV_IDP_6219_SERIES))
  kal_mem_set(&imgdma_dcb, 0, sizeof(IMGDMA_DCB_STRUCT));
#endif
}
#endif

#if (defined(DRV_IDP_6219_SERIES))

/*
Note:
1. Interrupt is always enabled after configuration
2. IMGDMA_Init should be called first and only once.
3. Open the IMGDMA with owner id
4. allocate the control sturcture blocks(permanent)for the related channels
4. Call the config function to initialize the related channel before start
5. start the IMGDMA
6. stop immediately
7. Close the IMGDMA

*/

/*
* FUNCTION
*	   IMGDMA_LISR_Entry
*
* DESCRIPTION
*   	lisr function fo IMGDMA
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
static void image_dma_LISR(void)
{
	kal_uint32 reg;

   IRQMask(IRQ_IMGDMA_CODE);
   reg = DRV_Reg32(IMGDMA_STA);
	ASSERT(reg != 0);
	// first run of VDO
 	if (reg & IMGDMA_STA_TWCIT)
	{
      #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
         SLA_HWLogging("BW2", SA_start);
      #endif
	   IMGDMA_ACKI(IMGDMA_STA_TWCIT);
  		if (MPEG4_RECODE_START==KAL_TRUE)
		{
		   if (imgdma_dcb.cb[IMGDMA_ALL_CH] != NULL) {
            imgdma_dcb.cb[IMGDMA_ALL_CH](mpeg4_video_buffer[current_video_buffer_count]);
         }
		}
		current_video_buffer_count++;
		current_video_buffer_count &= 0x1;
	}
	// interrupts may occur simutaneusly
	else if(reg & IMGDMA_STA_JPEGIT)
	{
	   IMGDMA_ACKI(IMGDMA_STA_JPEGIT);
	   imgdma_dcb.state[IMGDMA_JPEG_CH] = IMGDMA_READY;
	   if (imgdma_dcb.cb[IMGDMA_JPEG_CH] != NULL) {
	   imgdma_dcb.cb[IMGDMA_JPEG_CH]();
	   }
	   imgdma_dcb.stop_cb[IMGDMA_JPEG_CH] = KAL_FALSE;

	}
	else if(reg & IMGDMA_STA_IBW2IT)
	{
      #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
         SLA_HWLogging("BW2", SA_stop);
         SLA_HWLogging("LCD", SA_start);
      #endif
	   IMGDMA_ACKI(IMGDMA_STA_IBW2IT);
	   imgdma_dcb.state[IMGDMA_IBW2_CH] = IMGDMA_READY;
	   if (imgdma_dcb.cb[IMGDMA_IBW2_CH] != NULL) {
		   imgdma_dcb.cb[IMGDMA_IBW2_CH]();
		}
	   imgdma_dcb.stop_cb[IMGDMA_IBW2_CH] = KAL_FALSE;
	}
	else if(reg & IMGDMA_STA_IBW1IT)
	{
	   IMGDMA_ACKI(IMGDMA_STA_IBW1IT);
	   imgdma_dcb.state[IMGDMA_IBW1_CH] = IMGDMA_READY;
	   if (imgdma_dcb.cb[IMGDMA_IBW1_CH] != NULL) {
         imgdma_dcb.cb[IMGDMA_IBW1_CH]();
      }
	   imgdma_dcb.stop_cb[IMGDMA_IBW1_CH] = KAL_FALSE;
	}
	else if(reg & IMGDMA_STA_IBR1IT)
	{
	   IMGDMA_ACKI(IMGDMA_STA_IBR1IT);
	   imgdma_dcb.state[IMGDMA_IBR1_CH] = IMGDMA_READY;
	   if (imgdma_dcb.cb[IMGDMA_IBR1_CH] != NULL) {
		   imgdma_dcb.cb[IMGDMA_IBR1_CH]();
		}
	   imgdma_dcb.stop_cb[IMGDMA_IBR1_CH] = KAL_FALSE;
	}
	// second run of resizing
	else if(reg & IMGDMA_STA_VDOIT)
	{
	   IMGDMA_ACKI(IMGDMA_STA_VDOIT);
	   imgdma_dcb.state[IMGDMA_VDO_CH] = IMGDMA_READY;
	   if (imgdma_dcb.cb[IMGDMA_VDO_CH] != NULL) {
	      imgdma_dcb.cb[IMGDMA_VDO_CH]();
	   }
	   imgdma_dcb.stop_cb[IMGDMA_VDO_CH] = KAL_FALSE;
	}
	IRQUnmask(IRQ_IMGDMA_CODE);
}

/*
* FUNCTION
*	   IMGDMA_JpegConfig
*
* DESCRIPTION
*   	configure the jpeg channel
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
kal_int32 API IMGDMA_JpegConfig(IMGDMA_JPEG_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner)
{
	kal_uint32 reg = 0;

	ASSERT(owner == imgdma_dcb.owner);
	ASSERT(imgdma_dcb.state[IMGDMA_JPEG_CH] != IMGDMA_BUSY);
	imgdma_dcb.cb[IMGDMA_JPEG_CH] = s->cb;
	if(s->cb)
		reg = IMGDMA_JPEG_CON_IT;
	if(s->gray)
		reg |= IMGDMA_JPEG_CON_GRAY;
	DRV_WriteReg32(IMGDMA_JPEG_CON,reg);

	DRV_WriteReg32(IMGDMA_JPEG_BSADDR, s->bs);
	DRV_WriteReg32(IMGDMA_JPEG_HSIZE, s->width-1);
	DRV_WriteReg32(IMGDMA_JPEG_VSIZE, s->height-1);
	DRV_WriteReg32(IMGDMA_JPEG_FIFOLEN, s->fifo);
	imgdma_dcb.state[IMGDMA_JPEG_CH] = IMGDMA_READY;

	if(start)
	{
		IMGDMA_Start(IMGDMA_JPEG_CH, owner);
	}

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGDMA_VdoConfig
*
* DESCRIPTION
*   	configure the vdo channel
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
kal_int32 API IMGDMA_VdoConfig(IMGDMA_VDO_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner)
{
	kal_uint32 reg = 0;

	ASSERT(owner == imgdma_dcb.owner);
	ASSERT(imgdma_dcb.state[IMGDMA_VDO_CH] != IMGDMA_BUSY);

	if(s->cb1)
	{
		reg = IMGDMA_VDO_CON_TWCIT;
		imgdma_dcb.cb[IMGDMA_ALL_CH] = s->cb1;
	}
	else if(s->cb2)
	{
		reg = IMGDMA_VDO_CON_DONEIT;
		imgdma_dcb.cb[IMGDMA_VDO_CH] = s->cb2;
	}

	if(s->dir == IMGDMA_MPEG4_ENCODE)
		reg |= IMGDMA_VDO_CON_DIR;
	if(s->twice)
	{
		reg |= IMGDMA_VDO_CON_TWC;
		imgdma_dcb.twice = KAL_TRUE;
	}
	if(s->restart)
		reg |= IMGDMA_VDO_CON_AUTORSTR;

	//reg |= IMGDMA_VDO_CON_TWCIT;
	DRV_WriteReg32(IMGDMA_VDO_CON, reg);

	DRV_WriteReg32(IMGDMA_VDO_BSADDR1, s->bs1);
	DRV_WriteReg32(IMGDMA_VDO_BSADDR2, s->bs2);
	DRV_WriteReg32(IMGDMA_VDO_HSIZE, s->width);
	DRV_WriteReg32(IMGDMA_VDO_VSIZE, s->height);
	imgdma_dcb.state[IMGDMA_VDO_CH] = IMGDMA_READY;

	if(start)
	{
		IMGDMA_Start(IMGDMA_VDO_CH, owner);
	}

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGDMA_IBW1Config
*
* DESCRIPTION
*   	configure the IBW1 channel
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
kal_int32 API IMGDMA_IBW1Config(IMGDMA_IBW1_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner)
{
	ASSERT(owner == imgdma_dcb.owner);
	ASSERT(imgdma_dcb.state[IMGDMA_IBW1_CH] != IMGDMA_BUSY);
	imgdma_dcb.cb[IMGDMA_IBW1_CH] = s->cb;
	if(s->cb)
		DRV_WriteReg32(IMGDMA_IBW1_CON, IMGDMA_IBW1_CON_IT);
	DRV_WriteReg32(IMGDMA_IBW1_BSADDR, s->bs);
	DRV_WriteReg32(IMGDMA_IBW1_PXLNUM, s->pxlnum-1);
	imgdma_dcb.state[IMGDMA_IBW1_CH] = IMGDMA_READY;

	if(start)
	{
		IMGDMA_Start(IMGDMA_IBW1_CH, owner);
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
kal_int32 API IMGDMA_IBW2Config(IMGDMA_IBW2_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner)
{
	kal_uint32 reg = 0;

	ASSERT(owner == imgdma_dcb.owner);
	ASSERT(imgdma_dcb.state[IMGDMA_IBW2_CH] != IMGDMA_BUSY);
	imgdma_dcb.cb[IMGDMA_IBW2_CH] = s->cb;
	if(s->cb)
	{
		reg = IMGDMA_IBW2_CON_IT;
   }

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
   reg = IMGDMA_IBW2_CON_IT;
#endif

	if(s->twice)
	{
		imgdma_dcb.twice = KAL_TRUE;
		reg |= IMGDMA_IBW2_CON_TWC;
	}
	if(s->lcd_hk)
		reg |= IMGDMA_IBW2_CON_LCD;
	if(s->restart)
		reg |= IMGDMA_IBW2_CON_ATUORSTR;
	if(s->couple)
		reg |= IMGDMA_IBW2_CON_DC;
	if(s->pan)
	{
		reg |= IMGDMA_IBW2_CON_PAN;
		DRV_WriteReg32(IMGDMA_IBW2_HPITCH1, s->hpitch1);
		DRV_WriteReg32(IMGDMA_IBW2_HPITCH2, s->hpitch2);
		DRV_WriteReg32(IMGDMA_IBW2_VPITCH1, s->vpitch1);
		DRV_WriteReg32(IMGDMA_IBW2_VPITCH2, s->vpitch2);
	}
	DRV_WriteReg32(IMGDMA_IBW2_CON, reg);
	DRV_WriteReg32(IMGDMA_IBW2_BSADDR1, s->bs1);
	DRV_WriteReg32(IMGDMA_IBW2_BSADDR2, s->bs2);
	DRV_WriteReg32(IMGDMA_IBW2_HSIZE, s->width-1);
	DRV_WriteReg32(IMGDMA_IBW2_VSIZE, s->height-1);
	imgdma_dcb.state[IMGDMA_IBW2_CH] = IMGDMA_READY;

	if(start)
	{
		IMGDMA_Start(IMGDMA_IBW2_CH, owner);
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
kal_int32 API IMGDMA_IBR1Config(IMGDMA_IBR1_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner)
{
	kal_uint32 reg = 0;

	ASSERT(owner == imgdma_dcb.owner);
	ASSERT(imgdma_dcb.state[IMGDMA_IBR1_CH] != IMGDMA_BUSY);
	imgdma_dcb.cb[IMGDMA_IBR1_CH] = s->cb;
	if(s->cb)
		reg = IMGDMA_IBR1_CON_IT;
	if(s->type == IBR1_TYPE_RGB888)
	{
		reg |= IMGDMA_IBR1_CON_FMT;
		if(s->order == IBR1_ORDER_RGB888)
			reg |= IMGDMA_IBR1_CON_FMT;
	}
	DRV_WriteReg32(IMGDMA_IBR1_CON, reg);
	DRV_WriteReg32(IMGDMA_IBR1_PXLNUM, s->pxlnum-1);
	DRV_WriteReg32(IMGDMA_IBR1_BSADDR, s->bs);
	imgdma_dcb.state[IMGDMA_IBR1_CH] = IMGDMA_READY;

	if(start)
	{
		IMGDMA_Start(IMGDMA_IBR1_CH, owner);
	}

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGDMA_CheckBusy
*
* DESCRIPTION
*   	Check the specified channel is busy
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
kal_bool API IMGDMA_CheckBusy(IMGDMA_CHANNEL_ENUM ch, MMDI_SCENERIO_ID owner)
{
	kal_uint32 reg;

	ASSERT(owner == imgdma_dcb.owner);
	reg = DRV_Reg32(IMGDMA_STA) >> 16;

	if(reg & (1 << ch))
		return KAL_TRUE;

	return KAL_FALSE;
}

/*
* FUNCTION
*	   IMGDMA_Open
*
* DESCRIPTION
*   	Obtain the owner ship of the IMGDMA
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
kal_int32 API IMGDMA_Open(MMDI_SCENERIO_ID owner)
{
	ENTER_CRITICAL();
	ASSERT(imgdma_dcb.owner == SCENARIO_UNKNOW_ID);
	imgdma_dcb.owner = owner;
	EXIT_CRITICAL();
   DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_IMGDMA,PDN_IMGDMA);

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGDMA_Close
*
* DESCRIPTION
*   	Release the ownership of the IMGDMA
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
kal_int32 API IMGDMA_Close(MMDI_SCENERIO_ID owner)
{
	kal_uint32 i;

	ASSERT(imgdma_dcb.owner == owner);
	kal_mem_set(&imgdma_dcb,0,sizeof(IMGDMA_DCB_STRUCT));
	for(i=0;i<IMGDMA_ALL_CH;i++)
	{
		DRV_Reg(IMGDMA_STR(i)) = 0;
		DRV_Reg(IMGDMA_CON(i)) = 0;
	}
   DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_IMGDMA,PDN_IMGDMA);

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGDMA_Start
*
* DESCRIPTION
*   	start the specified channel to funciotn
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
kal_int32 API IMGDMA_Start(IMGDMA_CHANNEL_ENUM ch, MMDI_SCENERIO_ID owner)
{
	ASSERT(imgdma_dcb.state[ch] == IMGDMA_READY);
	ASSERT(owner == imgdma_dcb.owner);
	imgdma_dcb.state[ch] = IMGDMA_BUSY;
	IMGDMA_START(ch);

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGDMA_Stop
*
* DESCRIPTION
*   	stop the specified channel with various method
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
kal_int32 API IMGDMA_Stop(IMGDMA_CHANNEL_ENUM ch, IMGDMA_STOP_ENUM stop, IDMA_Callback stop_cb, MMDI_SCENERIO_ID owner)
{
	kal_bool busy;
	kal_uint16 auto_rstr;

	ASSERT(owner == imgdma_dcb.owner);

	switch(stop)
	{
		case IMGDMA_STOP_NOW:
			IMGDMA_STOP(ch);
			break;
		case IMGDMA_STOP_CALLBACK:
			// It should be used wihtout enabling auto restart.
			ASSERT(stop_cb != NULL);
			if(ch == IMGDMA_VDO_CH)
			{
				ASSERT((DRV_Reg(IMGDMA_CON(ch))& IMGDMA_VDO_CON_AUTORSTR) == 0);
			}
			else if(ch == IMGDMA_IBW2_CH)
			{
				ASSERT((DRV_Reg(IMGDMA_CON(ch))& IMGDMA_IBW2_CON_ATUORSTR) == 0);
			}
			busy = IMGDMA_CheckBusy(ch,owner);
			if(busy == KAL_TRUE)
			{
				imgdma_dcb.stop_cb[ch] = KAL_TRUE;
				imgdma_dcb.cb[ch] = stop_cb;
				IMGDMA_ENABLE_INT(ch);
				busy = IMGDMA_CheckBusy(ch,owner);
				if(busy == KAL_FALSE && imgdma_dcb.stop_cb[ch] == KAL_TRUE)
				{
					IMGDMA_STOP(ch);
					IMGDMA_DISABLE_INT(ch);
					stop_cb();
				}
			}
			else
				stop_cb();
			break;
		case IMGDMA_STOP_AT_FRAME_BOUNDARY:
			// It will make sure IMGDMA will stop at the frame bounday
			// Stop IMGDMA first and then the ISP source, the remain data will be dropped by IMGDMA
			// The worse case is that it may block for a frame time.
			ASSERT(ch == IMGDMA_VDO_CH || ch == IMGDMA_IBW2_CH);
			auto_rstr = (ch == IMGDMA_VDO_CH)?IMGDMA_VDO_CON_AUTORSTR:IMGDMA_IBW2_CON_ATUORSTR;
			DRV_Reg(IMGDMA_CON(ch))&= ~auto_rstr;
			while(IMGDMA_IS_BUSY(ch));
			break;
		case IMGDMA_STOP_IDLE:
			break;
		default:
			ASSERT(0);
			break;
	}
	imgdma_dcb.state[ch] = IMGDMA_READY;

	return NO_ERROR;
}

/*
* FUNCTION
*	   IMGDMA_VdoSetBS1
*
* DESCRIPTION
*   	Set the bass address for VDO channel ( for MPEG4 decode)
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
kal_int32 API IMGDMA_VdoSetBS1(kal_uint32 bs, MMDI_SCENERIO_ID owner)
{
	ASSERT(imgdma_dcb.state[IMGDMA_VDO_CH] == IMGDMA_READY);
	ASSERT(owner == imgdma_dcb.owner);

	DRV_WriteReg32(IMGDMA_VDO_BSADDR1, bs);

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
#endif /* MT6219, MT6226, MT6227 */

#if (defined(DRV_IDP_6228_SERIES))
void set_overlay_palette(kal_uint8 palette_size,kal_uint32 *palette_addr_ptr)
{
	kal_uint16 i;

   /// Turn on image DMA clock
	DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_IMGDMA;

	ENABLE_IMGDMA_IBR2_PALETTE;
	for (i=0;i<=palette_size;i++)
	{
		*((volatile kal_uint32 *) (IMGDMA_IBR2_COLOR_PALETTE_BASE+ (i<<2)))= *(palette_addr_ptr+i);
	}

	if (current_image_data_path_owner==SCENARIO_UNKNOW_ID)
	{
		/// Turn on image DMA clock
		DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_IMGDMA;
	}
}

static void image_dma_LISR(void)
{
	kal_uint32 reg;

   IRQMask(IRQ_IMGDMA_CODE);
   reg = DRV_Reg32(IMGDMA_STATUS_REG);
	ASSERT(reg != 0);
	// first run of VDO
 	if (reg & IMGDMA_IBW2_INT_STATUS_BIT)
	{
	   ACK_IMGDMA_IBW2_INT;

      #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
         SLA_HWLogging("BW2", SA_stop);
         SLA_HWLogging("LCD", SA_start);
      #endif

	   if(ibw2_cb!=NULL)
	   	ibw2_cb();
	}
	// interrupts may occur simutaneusly
	else if(reg & IMGDMA_IBW1_INT_STATUS_BIT)
	{
	   ACK_IMGDMA_IBW1_INT;
	}
	else if (reg & IMGDMA_VIDEO_ENCODE_W_INT_STATUS_BIT)
	{
		ACK_IMGDMA_VIDEO_ENCODE_W_INT;
		if (MPEG4_RECODE_START==KAL_TRUE)
		{
			if (vid_enc_w_cb1!=NULL)
				vid_enc_w_cb1(mpeg4_video_buffer[current_video_buffer_count]);
		}
		current_video_buffer_count++;
		current_video_buffer_count &= 0x1;

		if (vid_enc_w_cb!=NULL)
			vid_enc_w_cb();

		if (vid_enc_r_cb!=NULL)
			vid_enc_r_cb(KAL_FALSE);
              
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
      #endif/* __3G_VIDEO_CALL__*/
	}
	else if (reg & IMGDMA_VIDEO_ENCODE_R_INT_STATUS_BIT)
	{
		ACK_IMGDMA_VIDEO_ENCODE_R_INT;
	}
	else if (reg & IMGDMA_VIDEO_DECODE_INT_STATUS_BIT)
	{
		ACK_IMGDMA_VIDEO_DECODE_INT;
	}
	else if (reg & IMGDMA_IBR1_INT_STATUS_BIT)
	{
		ACK_IMGDMA_IBR1_INT;
	}
	else if (reg & IMGDMA_IBR2_INT_STATUS_BIT)
	{
		ACK_IMGDMA_IBR2_INT;
	}
	else if (reg & IMGDMA_IBW3_INT_STATUS_BIT)
	{
		if (wait_ibw3_complete==KAL_TRUE)
		{
			ibw3_complete_flag=KAL_TRUE;
		}
		ACK_IMGDMA_IBW3_INT;
	}
	else if (reg & IMGDMA_IBW4_INT_STATUS_BIT)
	{
	   #if 1
	   if (wait_ibw4_complete==KAL_TRUE)
		{
			ibw4_complete_flag=KAL_TRUE;
		}
		#endif
		ACK_IMGDMA_IBW4_INT;
	}

	IRQUnmask(IRQ_IMGDMA_CODE);
}	/* image_dma_LISR() */

/*the following defines the control part of IMGDMA*/
void IMGDMA_IBW1Config(IMGDMA_IBW1_STRUCT *ibw1_struct)
{
   STOP_IBW1;
	REG_IMGDMA_IBW1_CTRL=0;

	switch(ibw1_struct->pixel_engine)
	{
	   case PIXEL_ENGINE_IPP1:
	      SET_IBW1_PIXEL_SRC_IPP1;
	   break;
	   case PIXEL_ENGINE_IPP2:
	      SET_IBW1_PIXEL_SRC_IPP2;
	   break;
	   case PIXEL_ENGINE_CRZ:
	      SET_IBW1_PIXEL_SRC_CRZ;
	   break;
	   case PIXEL_ENGINE_PRZ:
	      SET_IBW1_PIXEL_SRC_PRZ;
	   break;
	   default:
	      ASSERT(0);
	   break;
	}
	if(ibw1_struct->output_format==IMGDMA_OUTPUT_TYPE_RGB565)
	{
	   SET_IBW1_OUTPUT_RGB565;
	}
	else
	{
	   SET_IBW1_OUTPUT_RGB888;
	}

	if (ibw1_struct->auto_restart==KAL_FALSE)
	{
		DISABLE_IBW1_AUTO_RESTART;
	}
	else
	{
		ENABLE_IBW1_AUTO_RESTART;
	}

	REG_IMGDMA_IBW1_BASE_ADDR1=ibw1_struct->bs;
	REG_IMGDMA_IBW1_WIDTH=ibw1_struct->width;
	REG_IMGDMA_IBW1_HEIGHT=ibw1_struct->height;
	START_IBW1;
}

void IMGDMA_IBW3Config(IMGDMA_IBW3_STRUCT *ibw3_struct)
{
   STOP_IBW3;
	REG_IMGDMA_IBW3_CTRL=0;

	switch(ibw3_struct->pixel_engine)
	{
	   case PIXEL_ENGINE_IPP1:
	      SET_IBW3_PIXEL_SRC_IPP1;
	   break;
	   case PIXEL_ENGINE_IPP2:
	      SET_IBW3_PIXEL_SRC_IPP2;
	   break;
	   case PIXEL_ENGINE_CRZ:
	      SET_IBW3_PIXEL_SRC_CRZ;
	   break;
	   case PIXEL_ENGINE_PRZ:
	      SET_IBW3_PIXEL_SRC_PRZ;
	   break;
	   default:
	      ASSERT(0);
	   break;
	}
   if (ibw3_struct->auto_restart==KAL_FALSE)
	{
		DISABLE_IBW3_AUTO_RESTART;
	}
	else
	{
		ENABLE_IBW3_AUTO_RESTART;
	}
	if(ibw3_struct->int_en)
	{
	   ENABLE_IBW3_INT;
	}
	else
	{
	   DISABLE_IBW3_INT;
	}

	REG_IMGDMA_IBW3_WIDTH=ibw3_struct->width;
	REG_IMGDMA_IBW3_HEIGHT=ibw3_struct->height;
	START_IBW3;
}
void IMGDMA_IBW4Config(IMGDMA_IBW4_STRUCT *ibw4_struct)
{
   STOP_IBW4;
	REG_IMGDMA_IBW4_CTRL=0;

	switch(ibw4_struct->pixel_engine)
	{
	   case PIXEL_ENGINE_IPP1:
	      SET_IBW4_PIXEL_SRC_IPP1;
	   break;
	   case PIXEL_ENGINE_IPP2:
	      SET_IBW4_PIXEL_SRC_IPP2;
	   break;
	   case PIXEL_ENGINE_CRZ:
	      SET_IBW4_PIXEL_SRC_CRZ;
	   break;
	   case PIXEL_ENGINE_PRZ:
	      SET_IBW4_PIXEL_SRC_PRZ;
	   break;
	   default:
	      ASSERT(0);
	   break;
	}
   if (ibw4_struct->auto_restart==KAL_FALSE)
	{
		DISABLE_IBW4_AUTO_RESTART;
	}
	else
	{
		ENABLE_IBW4_AUTO_RESTART;
	}
	if(ibw4_struct->int_en)
	{
	   ENABLE_IBW4_INT;
	}
	else
	{
	   DISABLE_IBW4_INT;
	}

	REG_IMGDMA_IBW4_WIDTH=ibw4_struct->width;
	REG_IMGDMA_IBW4_HEIGHT=ibw4_struct->height;
	START_IBW4;
}

void IMGDMA_IBR1Config(IMGDMA_IBR1_STRUCT *ibr1_struct)
{
   STOP_IBR1;
	if (ibr1_struct->data_type==IBR1_TYPE_RGB565)
	{
		SET_IMGDMA_IBR1_DATA_RGB565;
	}
	else if (ibr1_struct->data_type==IBR1_TYPE_RGB888)
	{
		SET_IMGDMA_IBR1_DATA_RGB888;
	}
	if (ibr1_struct->data_order==IBR1_ORDER_BGR888)
	{
		SET_IMGDMA_IBR1_DATA_ORDER_BGR888;
	}
	else if (ibr1_struct->data_order==IBR1_ORDER_RGB888)
	{
		SET_IMGDMA_IBR1_DATA_ORDER_RGB888;
	}
	if(ibr1_struct->int_en==KAL_FALSE)
	{
	   DISABLE_IMGDMA_IBR1_INT;
	}
	else
	{
	   ENABLE_IMGDMA_IBR1_INT;
	}

	REG_IMGDMA_IBR1_BASE_ADDR=ibr1_struct->base_addr;
	REG_IMGDMA_IBR1_PIXEL_NUMBER=ibr1_struct->pixel_number;
}

void IMGDMA_IBR2Config(IMGDMA_IBR2_STRUCT *ibr2_struct)
{
   STOP_IBR2;

	switch(ibr2_struct->pixel_engine)
	{
	   case PIXEL_ENGINE_CRZ:
	      SET_IMGDMA_IBR2_SRC_CRZ;
	   break;
	   case PIXEL_ENGINE_PRZ:
	      SET_IMGDMA_IBR2_SRC_PRZ;
	   break;
	   default:
	      ASSERT(0);
	   break;
	}
	if(ibr2_struct->restart==KAL_FALSE)
	{
	   DISABLE_IMGDMA_IBR2_AUTO_RESTART;
	}
	else
	{
      ENABLE_IMGDMA_IBR2_AUTO_RESTART;
   }
   if(ibr2_struct->int_en==KAL_FALSE)
   {
	   DISABLE_IMGDMA_IBR2_INT;
	}
	else
	{
	   ENABLE_IMGDMA_IBR2_INT;
	}

	if(ibr2_struct->overlay_frame_mode==KAL_TRUE)
	{
		ENABLE_IMGDMA_IBR2_PALETTE;
		SET_IMGDMA_IBR2_PHOTO_FRAME_DEPTH(ibr2_struct->overlay_color_depth);
		REG_IMGDMA_IBR2_BASE_ADDR=ibr2_struct->overlay_frame_buffer_address;
		SET_IMGDMA_IBR2_SRC_KEY(ibr2_struct->overlay_frame_source_key);

		if(((ibr2_struct->overlay_frame_target_height%ibr2_struct->overlay_frame_height)!=0)
		|| ((ibr2_struct->overlay_frame_target_width%ibr2_struct->overlay_frame_width)!=0) )
		   ASSERT(0);

		SET_IMGDMA_IBR2_V_RATIO((ibr2_struct->overlay_frame_target_height/ibr2_struct->overlay_frame_height));
		SET_IMGDMA_IBR2_H_RATIO((ibr2_struct->overlay_frame_target_width/ibr2_struct->overlay_frame_width));

		REG_IMGDMA_IBR2_WIDTH=ibr2_struct->overlay_frame_width;
		REG_IMGDMA_IBR2_HEIGHT=ibr2_struct->overlay_frame_height;
		START_IBR2;
	}
	else
	{
		DISABLE_IMGDMA_IBR2_PALETTE;
	}
}

void IMGDMA_JPEGDMAConfig(IMGDMA_JPEG_DMA_STRUCT *jpeg_dma_struct)
{

   STOP_IMGDMA_JPEG;
	REG_IMGDMA_JPEG_CTRL=0;

	switch(jpeg_dma_struct->pixel_engine)
	{
	   case PIXEL_ENGINE_CRZ:
	      SET_IMGDMA_JPEG_SRC_CRZ;
	   break;
	   case PIXEL_ENGINE_PRZ:
	      SET_IMGDMA_JPEG_SRC_PRZ;
	   break;
	   default:
	      ASSERT(0);
	   break;
	}

	if (jpeg_dma_struct->jpeg_yuv_mode==JPEG_FORMAT_YUV420)
	{
		SET_IMGDMA_JPEG_YUV420;
	}
	else if (jpeg_dma_struct->jpeg_yuv_mode==JPEG_FORMAT_YUV422)
	{
		SET_IMGDMA_JPEG_YUV422;
	}
	else if (jpeg_dma_struct->jpeg_yuv_mode==JPEG_FORMAT_GRAY)
	{
		SET_IMGDMA_JPEG_GRAY;
	}

	if (jpeg_dma_struct->restart==KAL_TRUE)
	{
	   ENABLE_IMGDMA_JPEG_AUTO_RESTART;
	}
	else
	{
	   DISABLE_IMGDMA_JPEG_AUTO_RESTART;
	}


	REG_IMGDMA_JPEG_BASE_ADDR=(kal_uint32)jpeg_dma_struct->jpeg_file_buffer_address;

	if (jpeg_dma_struct->jpeg_yuv_mode==JPEG_FORMAT_YUV420)
      REG_IMGDMA_JPEG_FIFO_LENGTH=JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER>>1;
   else
      REG_IMGDMA_JPEG_FIFO_LENGTH=JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER;

	REG_IMGDMA_JPEG_WIDTH=jpeg_dma_struct->target_width-1;
	REG_IMGDMA_JPEG_HEIGHT=jpeg_dma_struct->target_height-1;
	START_IMGDMA_JPEG;
}

void IMGDMA_VIDEOENCODE_DMAConfig(IMGDMA_VIDEO_ENCODE_STRUCT *video_encode_dma_struct)
{
   STOP_IMGDMA_VIDEO_ENCODE;
   REG_IMGDMA_VIDEO_ENCODE_CTRL=0;

	switch(video_encode_dma_struct->wdma_pixel_engine)
	{
	   case PIXEL_ENGINE_CRZ:
	      SET_VIDEO_ENCODE_SRC_CRZ;
	   break;
	   case PIXEL_ENGINE_PRZ:
	      SET_VIDEO_ENCODE_SRC_PRZ;
	   break;
	   default:
	      ASSERT(0);
	   break;
	}
	switch(video_encode_dma_struct->rdma_destination_engine)
	{
	   case PIXEL_ENGINE_DRZ:
	      SET_VIDEO_ENCODE_R_DEST_DRZ;
	   break;
	   case PIXEL_ENGINE_PRZ:
	      SET_VIDEO_ENCODE_R_DEST_PRZ;
	   break;
	   default:
	   break;
	}
	if(video_encode_dma_struct->restart==KAL_TRUE)
	{
	   ENABLE_VIDEO_ENCODE_AUTO_RESTART;
	}
	else
	{
	   DISABLE_VIDEO_ENCODE_AUTO_RESTART;
	}
	if(video_encode_dma_struct->wrtie_done_int==KAL_TRUE)
	{
	   ENABLE_VIDEO_ENCODE_W_INT;
   }
	else
	{
	   DISABLE_VIDEO_ENCODE_W_INT
	}
	if(video_encode_dma_struct->read_done_int==KAL_TRUE)
	{
	   ENABLE_VIDEO_ENCODE_R_INT;
   }
	else
	{
	   DISABLE_VIDEO_ENCODE_R_INT;
	}
	if(video_encode_dma_struct->w_trigger_r==KAL_TRUE)
	{
	   ENABLE_VIDEO_ENCODE_W_TRIGGER_R;
	}
	else
	{
	   DISABLE_VIDEO_ENCODE_W_TRIGGER_R;
	}


	REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1=(kal_uint32) video_encode_dma_struct->y_base_addr1;
	REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1=(kal_uint32) video_encode_dma_struct->u_base_addr1;
	REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1=(kal_uint32) video_encode_dma_struct->v_base_addr1;
	REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2=(kal_uint32) video_encode_dma_struct->y_base_addr2;
	REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2=(kal_uint32) video_encode_dma_struct->u_base_addr2;
	REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2=(kal_uint32) video_encode_dma_struct->v_base_addr2;
	REG_IMGDMA_VIDEO_ENCODE_WIDTH=video_encode_dma_struct->encode_width;
	REG_IMGDMA_VIDEO_ENCODE_HEIGHT=video_encode_dma_struct->encode_height;
	START_IMGDMA_VIDEO_ENCODE;
}

void IMGDMA_VIDEODECODE_DMAConfig(IMGDMA_VIDEO_DECODE_STRUCT *video_decode_dma_struct)
{
   if(video_decode_dma_struct->decode_done_int==KAL_TRUE)
   {
      ENABLE_VIDEO_DECODE_INT;
   }
   else
   {
 	   DISABLE_VIDEO_DECODE_INT;
 	}
	REG_IMGDMA_VIDEO_DECODE_WIDTH=video_decode_dma_struct->width;
	REG_IMGDMA_VIDEO_DECODE_HEIGHT=video_decode_dma_struct->height;
}

void IMGDMA_IBW2Config(IMGDMA_IBW2_STRUCT *ibw2_struct)
{
   STOP_IBW2;

	REG_IMGDMA_IBW2_BASE_ADDR1=ibw2_struct->frame1_base_addr;
	REG_IMGDMA_IBW2_BASE_ADDR2=ibw2_struct->frame2_base_addr;

	REG_IMGDMA_IBW2_WIDTH=ibw2_struct->width-1;
	REG_IMGDMA_IBW2_HEIGHT=ibw2_struct->height-1;

   if(ibw2_struct->pitch==KAL_TRUE)
   {
      REG_IMGDMA_IBW2_DEST_PITCH1=ibw2_struct->pitch1_bytes;
		REG_IMGDMA_IBW2_DEST_PITCH2=ibw2_struct->pitch2_bytes;
	   ENABLE_IBW2_DEST_PITCH;
   }
   else
   {
      DISABLE_IBW2_DEST_PITCH;
   }

	if (ibw2_struct->dest_color_mode==IMGDMA_IBW_OUTPUT_RGB565)
	{
		SET_IBW2_OUTPUT_RGB565;
	}
	else if (ibw2_struct->dest_color_mode==IMGDMA_IBW_OUTPUT_RGB888)
	{
		SET_IBW2_OUTPUT_RGB888;
	}
	if (ibw2_struct->lcd_trigger==KAL_TRUE)
	{
	   ENABLE_IBW2_TRIGGER_LCD;
	}
	else
	{
	   DISABLE_IBW2_TRIGGER_LCD;
	}
	if (ibw2_struct->int_en==KAL_TRUE)
	{
	   ENABLE_IBW2_INT;
	}
	else
	{
	   DISABLE_IBW2_INT;
	}
	if (ibw2_struct->pan==KAL_TRUE)
	{
	   ENABLE_IBW2_PAN;
	   REG_IMGDMA_IBW2_CLIP_LEFT_RIGHT=(ibw2_struct->clip_left<<16)|ibw2_struct->clip_right;
		REG_IMGDMA_IBW2_CLIP_TOP_BUTTOM=(ibw2_struct->clip_top<<16)|ibw2_struct->clip_bottom;
	}
	else
	{
	   DISABLE_IBW2_PAN;
	}
	if (ibw2_struct->direct_couple==KAL_TRUE)
   {
	   ENABLE_IBW2_DC;
	}
	else
	{
	   DISABLE_IBW2_DC;
	}
	if (ibw2_struct->restart==KAL_TRUE)
	{
	   ENABLE_IBW2_AUTO_RESTART;
	}
	else
	{
	   DISABLE_IBW2_AUTO_RESTART;
	}

	switch(ibw2_struct->pixel_engine)
	{
	   case PIXEL_ENGINE_IPP1:
	      SET_IBW2_PIXEL_SRC_IPP1;
	   break;
	   case PIXEL_ENGINE_IPP2:
	      SET_IBW2_PIXEL_SRC_IPP2;
	   break;
	   case PIXEL_ENGINE_PRZ:
	      SET_IBW2_PIXEL_SRC_PRZ;
	   break;
	   case PIXEL_ENGINE_CRZ:
	      SET_IBW2_PIXEL_SRC_CRZ;
	   break;
	}

	ibw2_cb=ibw2_struct->cb;
	if (ibw2_struct->enable_IBW2==KAL_TRUE)
	{
	   START_IBW2;
	}
}


#endif	/* MT6228, MT6229 MT6230*/


