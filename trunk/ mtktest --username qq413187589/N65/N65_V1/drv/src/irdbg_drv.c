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
 *    irdbg_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file implements irdbg hardware related functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
#include "reg_base.h"

#include "drvpdn.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "irdbg_hw.h"
#include "irdbg_drv.h"
#include "usbacm_dsp.h"
#ifdef __DSPIRDBG__

static IRDBG_Struct	g_irdbg;

#pragma arm section zidata = "EXTRAM_RXDATA"
__align(4) kal_uint8	g_irdbg_buff[IRDBG_BUFFER_NUM][IRDBG_BUFFER_SIZE];
#pragma arm section zidata

#if  !defined(DRV_USB_IRDBG_V1)
static void IRDBG_LISR(void);
#endif
static void IRDBG_HISR(void);

/* IRDMA default handle */
static kal_uint8 g_usb_irdma_handle = 255;

kal_uint8 IRDBG_Get_Buff_Num(void)
{
	return IRDBG_BUFFER_NUM;
}

kal_uint32 IRDBG_Get_Buff_Size(void)
{
	return IRDBG_BUFFER_SIZE;
}

kal_uint8* IRDBG_Get_Buff_Addr(kal_uint8 index)
{
	if(index>=IRDBG_BUFFER_NUM)
		EXT_ASSERT(0, index, 0, 0);
	
	return g_irdbg_buff[index];
}

kal_bool IRDBG_Check_Buff_Full(kal_uint8 index)
{
	kal_bool b_ret = KAL_FALSE;

#if  defined(DRV_USB_IRDBG_V1)
	switch(index)
	{
	case 0:
		if((*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_1)==1)	
			b_ret = KAL_TRUE;
		break;
	case 1:
		if((*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_2)==1)	
			b_ret = KAL_TRUE;
		break;
	case 2:	
		if((*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_3)==1)	
			b_ret = KAL_TRUE;
		break;
	default:
		EXT_ASSERT(0, index, 0, 0);
		break;
	}
#elif defined(DRV_USB_IRDBG_V2)

	if((g_USB_DSPLog.buffer_full_index&(IRDBG_BUF_INDEX<<index)) != 0)
		b_ret = KAL_TRUE;

#endif	
	return b_ret;
}

void IRDBG_Clear_Buff(kal_uint8 index)
{
#if defined(DRV_USB_IRDBG_V2)
	g_USB_DSPLog.buffer_full_index &= ~(IRDBG_BUF_INDEX<<index);
#endif	
	
	switch(index)
	{
	case 0:
		*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_1 = 0;
		break;
	case 1:
		*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_2 = 0;
		break;
	case 2:	
		*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_3 = 0;
		break;
	default:
		EXT_ASSERT(0, index, 0, 0);
		break;
	}
}

/* This part is only memory space, not HW address, we could see then as SW flags  */
void IRDBG_Init(irdbg_handler_ptr hdlr)
{
	/* Register DSP IO callback */
#if defined(DRV_USB_IRDBG_V2)
	*(volatile kal_uint16 *)IRDBG_DSP_BUFF_SIZE = 0;
#endif	
	*(volatile kal_uint16 *)IRDBG_DSP_BASE_ADDR_1 = 0;
	*(volatile kal_uint16 *)IRDBG_DSP_BASE_ADDR_2 = 0;
	*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_1 = 0;
	*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_2 = 0;
	*(volatile kal_uint16 *)IRDBG_DSP_BUFF_IND_3 = 0;
	*(volatile kal_uint16 *)IRDBG_DSP_START_IND = 0;

	if(g_usb_irdma_handle == 255)
		g_usb_irdma_handle = L1D_IRDMA_Power_GetHandle();
	if(g_usb_irdma_handle == 255)
		EXT_ASSERT(0, g_usb_irdma_handle, 0, 0);

	DRV_Register_HISR(DRV_IRDBG_HISR_ID, IRDBG_HISR);

	if(hdlr == NULL)
		ASSERT(0);
	
	g_irdbg.hdlr = hdlr;
}

/* Configure DSP to start IRDBG logging */
void IRDBG_Start(void)
{
	/* Fill DSP Sherif about buffer address and notify it to start */
#if defined(DRV_USB_IRDBG_V2)
	*(volatile kal_uint16 *)IRDBG_DSP_BUFF_SIZE = IRDBG_BUFFER_SIZE/8;
#endif	
	*(volatile kal_uint16 *)IRDBG_DSP_BASE_ADDR_1 = (kal_uint16)(((kal_uint32)g_irdbg_buff)&0xffff);
	*(volatile kal_uint16 *)IRDBG_DSP_BASE_ADDR_2 = (kal_uint16)(((kal_uint32)g_irdbg_buff>>16)&0xffff);
	*(volatile kal_uint16 *)IRDBG_DSP_START_IND = 1;
	L1D_IRDMA_Power_On(g_usb_irdma_handle);
}

/* Configure DSP to stop IRDBG logging */
void IRDBG_Stop(void)
{
	/* Fill DSP Sherif to notify it to stop */
	*(volatile kal_uint16 *)IRDBG_DSP_START_IND = 0;
	L1D_IRDMA_Power_Off(g_usb_irdma_handle);	
}

static void IRDBG_HISR(void)
{
	if(g_irdbg.hdlr == NULL)
		ASSERT(0);

	g_irdbg.hdlr();
}
	
#if  defined(DRV_USB_IRDBG_V1)
/* MT6229/MT6230 call back function from L1*/
void IRDBG_Callback(void)
{
	drv_active_hisr(DRV_IRDBG_HISR_ID);
}
#elif defined(DRV_USB_IRDBG_V2)
/* IRDBG LISR */
static void IRDBG_LISR(void)
{
	IRQMask(IRQ_IRDBG_CODE);
	drv_active_hisr(DRV_IRDBG_HISR_ID);
}

void IRDBG_Drv_Create_ISR(void)
{
	IRQ_Register_LISR(IRQ_IRDBG_CODE, IRDBG_LISR, "IRDBG");
	DRV_Register_HISR(DRV_IRDBG_HISR_ID, IRDBG_HISR);
}

/* acivate IRDBG interrput */
void IRDBG_Drv_Activate_ISR(void)
{
	IRQSensitivity(IRQ_IRDBG_CODE, LEVEL_SENSITIVE);
	IRQUnmask(IRQ_IRDBG_CODE);
}
#endif

#endif /* __DSPIRDBG__ */

