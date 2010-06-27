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
 *    usbacm_dsp.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb adaption layer for DSP API
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_comm.h"
#include "intrCtrl.h"
#include "usb_drv.h"
#include "irdbg_drv.h"
#include "irdbg_hw.h"
#include "usb_comm.h"
#include "usb.h"
#include "usb_resource.h"
#include "usbacm_drv.h"
#include "usbacm_dsp.h"

#ifdef __DSPIRDBG__

/* Exception flag*/
extern kal_uint8 INT_Exception_Enter; 

USB_DSPIRDBG_Struct g_USB_DSPLog;
static void USB_DSPIRDBG_DMA_Callback(void);
static void USB_DSPIRDBG_Hdlr(void);
static void USB_DSPIRDBG_Update_Write_Status(void);
static void USB_DSPIRDBG_Update_Read_Status(void);
static void USB_DSPIRDBG_Update_Transmit_Status(void);


/* call at IRDBG_HISR */
static void USB_DSPIRDBG_Update_Write_Status(void)
{
#if defined(DRV_USB_IRDBG_V1)

/*
	if(g_USB_DSPLog.buffer_full_index&(IRDBG_BUF_INDEX<<(g_USB_DSPLog.dma_write_index)) != 0)
		EXT_ASSERT(0, g_USB_DSPLog.buffer_full_index, IRDBG_BUF_INDEX<<(g_USB_DSPLog.dma_write_index), 0);
	
	g_USB_DSPLog.buffer_full_index |= IRDBG_BUF_INDEX<<(g_USB_DSPLog.dma_write_index);
	g_USB_DSPLog.dma_write_index = (g_USB_DSPLog.dma_write_index+1)%g_USB_DSPLog.buff_num;
*/
#elif defined(DRV_USB_IRDBG_V2)
	kal_uint16  buffer_status;
	kal_uint32   current_write_ptr = 255;
	kal_uint32   index;


	buffer_status = DRV_Reg(IRDBG_STA);

	/* find current write pointer */
	for (index = 0; index < g_USB_DSPLog.buff_num ; index++)
	{
		if((buffer_status&(IRDBG_BUF_INDEX<<index)) != 0)
		{
			current_write_ptr = index;
			break;
		}
	}

	if (current_write_ptr == 255)
		ASSERT(0);

	if(g_USB_DSPLog.dma_write_index <= current_write_ptr)
	{
		for (index = g_USB_DSPLog.dma_write_index; index <= current_write_ptr ; index++)
		{
			if((g_USB_DSPLog.buffer_full_index&(IRDBG_BUF_INDEX<<index)) != 0)
				EXT_ASSERT(0, g_USB_DSPLog.buffer_full_index, IRDBG_BUF_INDEX<<index, 0);

			g_USB_DSPLog.buffer_full_index |= IRDBG_BUF_INDEX<<index;
		}
	}
	else
	{
		for (index = g_USB_DSPLog.dma_write_index; index < g_USB_DSPLog.buff_num ; index++)
		{
			if((g_USB_DSPLog.buffer_full_index&(IRDBG_BUF_INDEX<<index)) != 0)
				EXT_ASSERT(0, g_USB_DSPLog.buffer_full_index, IRDBG_BUF_INDEX<<index, 0);

			g_USB_DSPLog.buffer_full_index |= IRDBG_BUF_INDEX<<index;
		}
		
		for (index = 0; index <= current_write_ptr ; index++)
		{
			if((g_USB_DSPLog.buffer_full_index&(IRDBG_BUF_INDEX<<index)) != 0)
				EXT_ASSERT(0, g_USB_DSPLog.buffer_full_index, IRDBG_BUF_INDEX<<index, 0);

			g_USB_DSPLog.buffer_full_index |= IRDBG_BUF_INDEX<<index;
		}
	}

	/* update write pointer */
//	g_USB_DSPLog.dma_write_index = (current_write_ptr+1)%g_USB_DSPLog.buff_num;

	if((current_write_ptr+1) == g_USB_DSPLog.buff_num)
		g_USB_DSPLog.dma_write_index = 0;
	else
		g_USB_DSPLog.dma_write_index = (current_write_ptr+1);
#endif
}


/* Only be called at DMA call back */
static void USB_DSPIRDBG_Update_Read_Status(void)
{
	kal_uint32   index;
	
	for(index = g_USB_DSPLog.dma_read_index; index < (g_USB_DSPLog.dma_read_index + g_USB_DSPLog.transmit_count); index++)
	{
		if(IRDBG_Check_Buff_Full(index) == KAL_FALSE)
			EXT_ASSERT(0, g_USB_DSPLog.buffer_full_index, IRDBG_BUF_INDEX<<index, 0);

		IRDBG_Clear_Buff(index);
	}

	if((g_USB_DSPLog.dma_read_index + g_USB_DSPLog.transmit_count) > g_USB_DSPLog.buff_num)
		EXT_ASSERT(0, g_USB_DSPLog.dma_read_index + g_USB_DSPLog.transmit_count, g_USB_DSPLog.buff_num, 0);
	
//	g_USB_DSPLog.dma_read_index = (g_USB_DSPLog.dma_read_index + g_USB_DSPLog.transmit_count)%g_USB_DSPLog.buff_num;
	if((g_USB_DSPLog.dma_read_index + g_USB_DSPLog.transmit_count) == g_USB_DSPLog.buff_num)
		g_USB_DSPLog.dma_read_index = 0;
	else
		g_USB_DSPLog.dma_read_index += g_USB_DSPLog.transmit_count;
}

static void USB_DSPIRDBG_Update_Transmit_Status(void)
{
	kal_uint32   index;

	g_USB_DSPLog.transmit_count = 1;

	if(IRDBG_Check_Buff_Full(g_USB_DSPLog.dma_read_index) == KAL_FALSE)
		EXT_ASSERT(0, g_USB_DSPLog.buffer_full_index, IRDBG_BUF_INDEX<<g_USB_DSPLog.dma_read_index, 0);

	for (index = (g_USB_DSPLog.dma_read_index+1); index < g_USB_DSPLog.buff_num; index++)
	{
		if(IRDBG_Check_Buff_Full(index) == KAL_TRUE)
			g_USB_DSPLog.transmit_count++;
		else
			break;
	}
}


/* DMA callback function for TX sent out data */
static void USB_DSPIRDBG_DMA_Callback(void)
{
	kal_uint32 savedMask;
	kal_uint8* buff_addr;
	kal_uint32  count;
	kal_bool bDMA = KAL_FALSE;	

	USB_DMA_Set_Run_Status(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, KAL_FALSE);

	if( (g_USB_DSPLog.dma_owner!=USB_DSPIRDBG_DMA_OWNER_DMA) 
		&& (g_USB_DSPLog.dma_owner!=USB_DSPIRDBG_DMA_OWNER_DSP))
	{
		EXT_ASSERT(0, g_USB_DSPLog.dma_owner, g_USB_DSPLog.dma_write_index, g_USB_DSPLog.dma_read_index);   
	}
	
	USB_DSPIRDBG_Update_Read_Status();
	g_USB_DSPLog.dma_owner = USB_DSPIRDBG_DMA_OWNER_NONE;

	savedMask = SaveAndSetIRQMask();
	/* in case usb cable is plugged out just before this critical section*/
	if(gUsbDevice.device_type == USB_CDC_ACM)
	{
		if((g_USB_DSPLog.dma_owner==USB_DSPIRDBG_DMA_OWNER_NONE) && 
			 (IRDBG_Check_Buff_Full(g_USB_DSPLog.dma_read_index)==KAL_TRUE))
		{
			/* decide to trigger DMA */
			USB_DSPIRDBG_Update_Transmit_Status();		
			g_USB_DSPLog.dma_owner = USB_DSPIRDBG_DMA_OWNER_DMA;
			bDMA = KAL_TRUE;		
		}
	}
	RestoreIRQMask(savedMask);

	if(bDMA==KAL_TRUE)
	{
		if(g_USB_DSPLog.dma_owner!= USB_DSPIRDBG_DMA_OWNER_DMA)
		{
			EXT_ASSERT(0, g_USB_DSPLog.dma_owner, g_USB_DSPLog.dma_write_index, g_USB_DSPLog.dma_read_index);
		}

		buff_addr = IRDBG_Get_Buff_Addr(g_USB_DSPLog.dma_read_index);
		count = g_USB_DSPLog.buff_size*g_USB_DSPLog.transmit_count;
//		USB_DMA_Setup(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, (kal_uint32)buff_addr, count, USB_DSPIRDBG_DMA_Callback, KAL_TRUE);
		USB_DMA_Setup(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)buff_addr, count, USB_DSPIRDBG_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
	}
}

/* IRDBG_HISR */
static void USB_DSPIRDBG_Hdlr(void)
{
	kal_uint32  savedMask;
	kal_uint8* buff_addr;
	kal_uint32  count;
	kal_bool bDMA = KAL_FALSE;


	USB_DSPIRDBG_Update_Write_Status();
	
	savedMask = SaveAndSetIRQMask();
	/* in case usb is plugged out just before this critical section*/
	if(gUsbDevice.device_type == USB_CDC_ACM)
	{
		if(g_USB_DSPLog.dma_owner==USB_DSPIRDBG_DMA_OWNER_NONE)	
		{
			/* decide to trigger DMA */
			USB_DSPIRDBG_Update_Transmit_Status();
			g_USB_DSPLog.dma_owner = USB_DSPIRDBG_DMA_OWNER_DSP;
			bDMA = KAL_TRUE;		
		}
	}
	RestoreIRQMask(savedMask);
	
	if(bDMA==KAL_TRUE)
	{	
		if(g_USB_DSPLog.dma_owner!= USB_DSPIRDBG_DMA_OWNER_DSP)
		{
			EXT_ASSERT(0, g_USB_DSPLog.dma_owner, g_USB_DSPLog.dma_write_index, g_USB_DSPLog.dma_read_index);
		}

		buff_addr = IRDBG_Get_Buff_Addr(g_USB_DSPLog.dma_read_index);
		count = g_USB_DSPLog.buff_size*g_USB_DSPLog.transmit_count;

//		USB_DMA_Setup(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, (kal_uint32)buff_addr, count, USB_DSPIRDBG_DMA_Callback, KAL_TRUE);
		USB_DMA_Setup(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)buff_addr, count, USB_DSPIRDBG_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
	}	
#if defined(DRV_USB_IRDBG_V2)
	IRQClearInt(IRQ_IRDBG_CODE);
	IRQUnmask(IRQ_IRDBG_CODE);
#endif
}

/* Be called when USB configure type */
void USB_DSPIRDBG_Init(void)
{	
	if(g_USB_DSPLog.b_not_first_time==KAL_FALSE)
	{	
		g_USB_DSPLog.b_not_first_time = KAL_TRUE;
		g_USB_DSPLog.buff_num = IRDBG_Get_Buff_Num();
		g_USB_DSPLog.buff_size = IRDBG_Get_Buff_Size();
		g_USB_DSPLog.dma_owner = USB_DSPIRDBG_DMA_OWNER_NONE;
		g_USB_DSPLog.dma_read_index = 0;
		g_USB_DSPLog.dma_write_index = 0;
		g_USB_DSPLog.transmit_count = 0;
		g_USB_DSPLog.buffer_full_index = 0;

		IRDBG_Init(USB_DSPIRDBG_Hdlr);
	}
	else
	{
		/* Do not reset read and write index because DSP has already sent data to buffer */
		g_USB_DSPLog.dma_owner = USB_DSPIRDBG_DMA_OWNER_NONE;	
	}	
}

/* Be called when PC configure USB */
void USB_DSPIRDBG_Start(void)
{
//	kal_uint8* buff_addr;

	
	/* send the previous time data before plug out cable */
//	if(IRDBG_Check_Buff_Full(g_USB_DSPLog.dma_read_index) == KAL_TRUE)
//	{
//		g_USB_DSPLog.dma_owner = USB_DSPIRDBG_DMA_OWNER_DMA;
//		buff_addr = IRDBG_Get_Buff_Addr(g_USB_DSPLog.dma_read_index);
//		USB_DMA_Setup(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, (kal_uint32)buff_addr, g_USB_DSPLog.buff_size, USB_DSPIRDBG_DMA_Callback, KAL_TRUE);
//	}
	
	IRDBG_Start();
}

/* Be called when plugging out cable */
void USB_DSPIRDBG_Stop(void)
{
	IRDBG_Stop();
}

// for test
static kal_bool b_test_pattern = KAL_TRUE;

void USB_DSPIRDBG_Flush_Data(void)
{
	kal_uint32  index;
	kal_uint8 *buff_addr;
	static kal_uint8 dummy_data = 0xff;	
		
	if(INT_Exception_Enter == 0)
		ASSERT(0);

	if ( (gUsbDevice.device_type != USB_CDC_ACM) || (g_UsbACM.acm_owner != USB_ACM_OWNER_DSP))
	{
		/* This function should only be called when assertion, if not CDC_ACM type, return it directly*/
		return;
	}
		
	/* wait for the running DMA done */
	USB_Polling_Transmit_Done(g_UsbACM.txpipe->byEP);

	for(index = 0; index < g_USB_DSPLog.buff_num; index++)
	{
//		buff_addr = IRDBG_Get_Buff_Addr((g_USB_DSPLog.dma_read_index+index)%g_USB_DSPLog.buff_num);
		if((g_USB_DSPLog.dma_read_index + index) == g_USB_DSPLog.buff_num)
			buff_addr = IRDBG_Get_Buff_Addr(0);
		else
			buff_addr = IRDBG_Get_Buff_Addr(g_USB_DSPLog.dma_read_index + index);
		
		if(b_test_pattern==KAL_TRUE)
		{
			// add only for test
			buff_addr[0] = 0x77;
			buff_addr[1] = 0x88;
			buff_addr[2] = index;
		}	
		
//		USB_Polling_Transmit_Data(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)buff_addr, g_USB_DSPLog.buff_size, NULL, KAL_FALSE);	
		USB_Polling_Transmit_Data(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)buff_addr, g_USB_DSPLog.buff_size, NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}	

	// send one byte dummy data
	USB_Polling_Transmit_Data(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)&dummy_data, 1, NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
}



#endif /*__DSPIRDBG__ */

