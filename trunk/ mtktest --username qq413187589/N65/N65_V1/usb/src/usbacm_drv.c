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
 *    usbacm_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb CDC ACM class driver
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "stack_common.h"
#include 	"stack_msgs.h"
#include "drv_comm.h"
#include "gpt_sw.h"
#include "syscomp_config.h"
#include "usb_task.h"
#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usb_resource.h"
#include "usbacm_drv.h"
#include "usbacm_adap.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"

/* global variables */
UARTStruct USB2UARTPort;
UsbAcm_Struct g_UsbACM;

/* Exception flag */
extern kal_uint8 INT_Exception_Enter; 

/* for DMA tx buffer and tx_isr buffer to differentiate */
static USBTRX_MEM_TYPE USB2Uart_MemType;
static kal_uint32  USB2Uart_WriteLength;

/* static functions */
static kal_uint32 USB2UART_Check_Transmit_Data(kal_uint32* addr, kal_bool b_check);
static void USB2UART_Update_Transmit_Data(void);
static void USB2UART_Tx_DMA_Callback(void);
static void USB_Acm_Break_Timeout(void *parameter);
static void USB_Acm_Ring_Buffer_Timeout(void *parameter);
static void USB_Acm_Ep0_SetLineCoding(void *data);
static void USB_Acm_Ep0_Command(Usb_Ep0_Status* pep0state,Usb_Command* pcmd);
static void USB_Acm_BulkOut_Hdr(void);
static void USB_Acm_BulkIn_Reset(void);
static void USB_Acm_BulkOut_Reset(void);
static void USB_Acm_IntrIn_Hdlr(void);
static void USB_Acm_IntrIn_Reset(void);
static void USB_Acm_FT_BulkOut_Hdr(void );


/*************************************************************
  translate ACM and UART setting functions
**************************************************************/

/* translate ACM line coding to UART DCB */
void USB2UART_LineCoding2DCB(UsbAcm_Line_Coding *pline_coding, UARTDCBStruct *pDCB)
{
	 pDCB->baud = pline_coding->dwDTERate;
	 pDCB->stopBits = pline_coding->bCharFormat+1; 
	 pDCB->parity = pline_coding->bParityType;
	 pDCB->dataBits = pline_coding->bDataBits;
}

/* translate UART DCB to ACM line coding */
void UART2USB_DCB2LineCoding(UARTDCBStruct *pDCB, UsbAcm_Line_Coding *pline_coding)
{
	  pline_coding->dwDTERate = pDCB->baud;
	  pline_coding->bCharFormat = pDCB->stopBits-1;
	  pline_coding->bParityType = pDCB->parity;
	  pline_coding->bDataBits = pDCB->dataBits;
}

/************************************************************
	GPT timeout handle escape character detect
*************************************************************/

/* GPT timer handler for Escape character detect */
void USB2UART_Timeout(void *parameter)
{
	UARTStruct *UARTData=(UARTStruct *)parameter;
	GPTI_StopItem(UARTData->handle);

	switch(UARTData->Rec_state)
	{
	case UART_Get3EscChar:
		/* escape detect */
		UARTData->EscFound = KAL_TRUE;
		UARTData->Rec_state = UART_RecNormal;
		UARTData->EscCount = 0;
		USB2UART_Sendilm(MSG_ID_UART_ESCAPE_DETECTED_IND);
		break;
	case UART_RecNormal:
		/* first timeout, start to check escape character */
		UARTData->Rec_state = UART_StartCheckESC;
		UARTData->EscCount = 0;
		break;
	case UART_StartCheckESC:
		UARTData->Rec_state = UART_RecNormal;
		UARTData->EscCount = 0;
		break;
	}
}

/************************************************************
	Default UART callback function. Send ilm to UART owner
*************************************************************/

void USB2UART_Dafault_Tx_Callback(UART_PORT port)
{
	if(g_UsbACM.send_Txilm == KAL_TRUE)
	{
		/* send message to UART owner*/
		USB2UART_Sendilm(MSG_ID_UART_READY_TO_WRITE_IND);
		g_UsbACM.send_Txilm = KAL_FALSE;
		g_UsbACM.config_send_Txilm = KAL_FALSE;
	}   
}

void USB2UART_Dafault_Rx_Callback(UART_PORT port)
{
	if (g_UsbACM.send_Rxilm == KAL_TRUE)
	{
		/* send ready to read message to UART onwer if needed*/
		USB2UART_Sendilm(MSG_ID_UART_READY_TO_READ_IND);
		g_UsbACM.send_Rxilm = KAL_FALSE;
	} 
}

/************************************************************
	Bulk EP IN handle functions (DMA setup and callback functions)
*************************************************************/

/* 
    Determine transmit data
    If return value is large than 0, the caller should send the data in parameter.
     This function and "USB2UART_Update_Transmit_Data" function must be pair.
*/
static kal_uint32 USB2UART_Check_Transmit_Data(kal_uint32* addr, kal_bool b_check)
{
	kal_uint32 length = 0;
	kal_uint32 savedMask;


//	g_UsbACM.force_ISR_buffer = KAL_FALSE;

	if(g_UsbACM.ring_buffer_timer_counting == KAL_TRUE)
	{
		GPTI_StopItem(g_UsbACM.ring_buffer_handle);
		g_UsbACM.ring_buffer_timer_counting = KAL_FALSE;
	}
	
	/* First, check if TX ISR buffer has "enough" data to send out */
	/* The data in the ISR TX buffer must be sent out all at one time. Otherwise, the catcher cannot decode the log correctly */
	savedMask = SaveAndSetIRQMask();
	if (USB2UARTPort.Tx_Buffer_ISR.Write != USB2UARTPort.Tx_Buffer_ISR.Read)
	{
		/* used for callback function to know sent source */
		USB2Uart_MemType = USBTRX_MEM_ISR;
		*addr = (kal_uint32)USB2UARTPort.Tx_Buffer_ISR.CharBuffer+USB2UARTPort.Tx_Buffer_ISR.Read;

		if (USB2UARTPort.Tx_Buffer_ISR.Write >= USB2UARTPort.Tx_Buffer_ISR.Read)
		{
			length = USB2UARTPort.Tx_Buffer_ISR.Write - USB2UARTPort.Tx_Buffer_ISR.Read;

			if(b_check == KAL_TRUE)
			{
				if(length <= (g_UsbACM.acm_param->txisr_ringbuff_size/2))
				{
					length = 0;
					g_UsbACM.ring_buffer_timer_counting = KAL_TRUE;
				}
			}
		}
		else
		{
			/* ISR TX buffer must have data to send out */
			length = USB2UARTPort.Tx_Buffer_ISR.Length - USB2UARTPort.Tx_Buffer_ISR.Read;
		}
	}

	/* check if TX buffer has enough data to send out */
	if((USB2UARTPort.Tx_Buffer.Write != USB2UARTPort.Tx_Buffer.Read) && (length == 0))
	{
		g_UsbACM.ring_buffer_timer_counting = KAL_FALSE;
		/* used for callback function to know sent source */
		USB2Uart_MemType = USBTRX_MEM_TASK;
		*addr = (kal_uint32)USB2UARTPort.Tx_Buffer.CharBuffer+USB2UARTPort.Tx_Buffer.Read;

		if(USB2UARTPort.Tx_Buffer.Write >= USB2UARTPort.Tx_Buffer.Read)
		{
			length = USB2UARTPort.Tx_Buffer.Write - USB2UARTPort.Tx_Buffer.Read;
#ifndef __L1_STANDALONE__
			if(b_check == KAL_TRUE)
			{
				if(length <= (g_UsbACM.acm_param->tx_ringbuff_size/2))
				{
					length = 0;
					g_UsbACM.ring_buffer_timer_counting = KAL_TRUE;
				}
			}
#endif
		}
		else
		{
			length = USB2UARTPort.Tx_Buffer.Length - USB2UARTPort.Tx_Buffer.Read;
		}
	}
	RestoreIRQMask(savedMask);

	if(g_UsbACM.ring_buffer_timer_counting == KAL_TRUE)
	{
		USB2Uart_MemType = USBTRX_MEM_UNKOWN;
		GPTI_StartItem(g_UsbACM.ring_buffer_handle, USBACM_RING_BUFFER_TIMEOUT, USB_Acm_Ring_Buffer_Timeout, NULL);
	}

	/* If the packet size is multiple of 64, make the last one to be less than 64.
		Otherwise the last packet may not be seen on WinXP */
	if(((length&0x3f) == 0) && (length != 0))
		USB2Uart_WriteLength = length - 1;
	else	
		USB2Uart_WriteLength = length;
	
	return USB2Uart_WriteLength;
}

/* 
    Update the buffer information after transmit done
    Note that "USB2Uart_WriteLength" will be reset to 0.
    This function and "USB2UART_Check_Transmit_Data" function must be pair.
*/
static void USB2UART_Update_Transmit_Data(void)
{
	/* update buffer information */
	if (USB2Uart_MemType == USBTRX_MEM_ISR)
	{
		USB2UARTPort.Tx_Buffer_ISR.Read += USB2Uart_WriteLength;
		ASSERT(USB2UARTPort.Tx_Buffer_ISR.Read <= USB2UARTPort.Tx_Buffer_ISR.Length);
		if (USB2UARTPort.Tx_Buffer_ISR.Read == USB2UARTPort.Tx_Buffer_ISR.Length)
			USB2UARTPort.Tx_Buffer_ISR.Read = 0;
	}
	else if (USB2Uart_MemType == USBTRX_MEM_TASK)
	{
		USB2UARTPort.Tx_Buffer.Read += USB2Uart_WriteLength;
		ASSERT(USB2UARTPort.Tx_Buffer.Read <= USB2UARTPort.Tx_Buffer.Length);
		if (USB2UARTPort.Tx_Buffer.Read == USB2UARTPort.Tx_Buffer.Length)
			USB2UARTPort.Tx_Buffer.Read = 0;
	}
	else
	{
		EXT_ASSERT(0, USB2Uart_MemType, 0, 0); 
	}

	/* reset to 0*/
	USB2Uart_WriteLength = 0;
}

/* 
    Flush all data in TX ring buffer, use polling method
    Note that this is special for sending exception log since interrupt is disabled when exception occurs
    It must not be used in normal time 
*/
void USB2UART_Polling_Flush_Transmit_Data(void)
{
	kal_uint32 addr;
	kal_uint32 length=0;

	/* avoid sending ilm to UART owner*/
	g_UsbACM.send_Txilm = KAL_FALSE;
	g_UsbACM.send_Rxilm = KAL_FALSE;

	/* wait for the running DMA done */
	USB_Polling_Transmit_Done(g_UsbACM.txpipe->byEP);

	if (USB2Uart_MemType != USBTRX_MEM_UNKOWN) /* make sure that SW buffer have data */
	USB2UART_Update_Transmit_Data();

	/* flush the data in TX buffer*/
	length = USB2UART_Check_Transmit_Data(&addr, KAL_FALSE);
	while(length)
	{
		/* used for callback function to know sent bytes */
//		USB_Polling_Transmit_Data(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, addr, length, NULL, KAL_FALSE);
		USB_Polling_Transmit_Data(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, addr, length, NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		USB2UART_Update_Transmit_Data();
		length = USB2UART_Check_Transmit_Data(&addr, KAL_FALSE);
	}
}


/* determine what buffer has data to send and call DMA setup function*/
void USB2UART_DMATransmit(kal_uint8 ep_num, kal_bool b_force_isr_buffer)
{
	kal_uint32 addr;
	kal_uint32 length=0;
//	kal_uint32 savedMask;


//	savedMask = SaveAndSetIRQMask();
	if(b_force_isr_buffer == KAL_TRUE)
	{
		length = USB2UART_Check_Transmit_Data(&addr, KAL_FALSE);
	}
	else
	{
		length = USB2UART_Check_Transmit_Data(&addr, g_UsbACM.threshold_enable);
	}
//	RestoreIRQMask(savedMask);

	if (length)
	{	
		USB_Dbg_Trace(USB_ACM_DMA_SETUP, drv_get_current_time(), length, USB2Uart_MemType);
		/* dma running state is cleared by USB2UART_Tx_DMA_Callback */
//		USB_DMA_Setup(ep_num, USB_TX_EP_TYPE, addr, length, USB2UART_Tx_DMA_Callback, KAL_TRUE);
		USB_DMA_Setup(ep_num, USB_TX_EP_TYPE, USB_ENDPT_BULK, addr, length, USB2UART_Tx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
	else
	{
		g_UsbACM.setup_dma = KAL_FALSE;
	}
}


/* DMA callback function for TX sent out data */
static void USB2UART_Tx_DMA_Callback(void)
{
	kal_uint32 savedMask;
	kal_uint8  ep_num = 0;
	kal_bool  setup_dma = KAL_FALSE;
	kal_bool  b_force_isr_buffer = KAL_FALSE;


	if(USB2UARTPort.ownerid != MOD_TST_READER)
	{
		drv_trace1(TRACE_FUNC, USBACM_DMA_CALLBACK, USB2Uart_WriteLength);
//		kal_prompt_trace(MOD_USB, "DMA %d", USB2Uart_WriteLength);
	}


	/* tx complete callback*/
	USB2UARTPort.tx_cb(uart_port_usb);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	

	/*update read pointer  for previously sent out buffer */
	savedMask = SaveAndSetIRQMask();
	USB2UART_Update_Transmit_Data();
	RestoreIRQMask(savedMask);

	/* USB2Uart_MemType and USB2Uart_WriteLength are updated, so clear dma running state here*/
	g_UsbACM.setup_dma = KAL_FALSE;
//	USB_DMA_Set_Run_Status(g_UsbACM.txpipe->byEP, KAL_FALSE);

	if(USB2UARTPort.Tx_Buffer_ISR.Read == USB2UARTPort.Tx_Buffer_ISR.Write)
	{
		/* no more data to send */
		if(USB2UARTPort.Tx_Buffer.Read == USB2UARTPort.Tx_Buffer.Write)
			return;
	}
	/* must send ISR buffer again */
	else if(USB2Uart_MemType == USBTRX_MEM_ISR)
	{
		b_force_isr_buffer = KAL_TRUE;
	}

	/* send data again in TX buffer or TXISR buffer */
	savedMask = SaveAndSetIRQMask();
	/* in case usb is plugged out just before this critical section */
	if(gUsbDevice.device_type == USB_CDC_ACM)
	{
//		if(USB_DMA_Get_Run_Status(g_UsbACM.txpipe->byEP) == KAL_FALSE)
		if(g_UsbACM.setup_dma == KAL_FALSE)
		{
			g_UsbACM.setup_dma = KAL_TRUE;
			setup_dma = KAL_TRUE;
			ep_num = g_UsbACM.txpipe->byEP;
		}
	}
	RestoreIRQMask(savedMask);

	if(setup_dma == KAL_TRUE)
	{
		USB_Dbg_Trace(USB_ACM_DMA_CALLBACK, drv_get_current_time(), ep_num, 0);
		USB2UART_DMATransmit(ep_num, b_force_isr_buffer);
	}


//	savedMask = SaveAndSetIRQMask();
	/* in case usb is plugged out just before this critical section*/
//	if(gUsbDevice.device_type == USB_CDC_ACM)
//	{
//		if(USB_DMA_Get_Run_Status(g_UsbACM.txpipe->byEP) == KAL_FALSE)
//		{		
//			USB2UART_DMATransmit(g_UsbACM.txpipe->byEP);
//		}
//	}
//	RestoreIRQMask(savedMask);
}

/************************************************************
	Bulk EP OUT handle functions (clear rx fifo data, read them out and drop)
*************************************************************/
void USB_Acm_Rx_ClrFifo(void)
{
	kal_uint32        nCount;
#ifdef USB_20_ENABLE
	kal_uint32	max_bulk_pkt_size;
	kal_uint8         data[USB_EP_BULK_MAXP_HS];
#else
	kal_uint8         data[USB_EP_BULK_MAXP];
#endif
	
	/* check if data received */
	nCount = USB_EP_Rx_Pkt_Len(g_UsbACM.rxpipe->byEP);

#ifdef USB_20_ENABLE	
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_bulk_pkt_size = USB_EP_BULK_MAXP_HS;
	else
		max_bulk_pkt_size = USB_EP_BULK_MAXP_FS;

	#ifdef  __PRODUCTION_RELEASE__	
	if(nCount > max_bulk_pkt_size)
	{
		nCount = max_bulk_pkt_size;
	}
	#else
	EXT_ASSERT((nCount <= max_bulk_pkt_size), nCount, max_bulk_pkt_size, 0);
	#endif
#else  /* USB_20_ENABLE */
	#ifdef  __PRODUCTION_RELEASE__	
	if(nCount > USB_EP_BULK_MAXP)
	{
		nCount = USB_EP_BULK_MAXP;
	}
	#else
	EXT_ASSERT((nCount <= USB_EP_BULK_MAXP), nCount, USB_EP_BULK_MAXP, 0);
	#endif
#endif  /* USB_20_ENABLE */


	if(nCount>0)
	{
		/* get the data from fifo */
		USB_EPFIFORead(g_UsbACM.rxpipe->byEP, nCount, data);

		/* Clear RxPktRdy */
		USB_EP_Bulk_Rx_Ready(g_UsbACM.rxpipe->byEP);
	}
}


/************************************************************
	interface initialization functions
*************************************************************/

/* communication interface create function, prepare descriptor */
void USB_Acm_CommIf_Create(void *ifname)
{
	kal_uint8 ep_id;
	kal_uint8 if_id;


	/* get resource number and register to gUsbDevice */
	g_UsbACM.comm_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbACM.comm_ep_intr_info = USB_Get_Intr_Ep(&ep_id); /* number is 3  */

	/* record interface name and interface descriptor length */
	g_UsbACM.comm_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM.comm_if_info->ifdscr_size = USB_CDC_IF_LENGTH;
	g_UsbACM.comm_ep_intr_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler*/
	g_UsbACM.comm_if_info->ep_info[0] = (Usb_Ep_Info*)g_UsbACM.comm_ep_intr_info;
	g_UsbACM.comm_if_info->if_class_specific_hdlr = USB_Acm_Ep0_Command;

	/* standard interface descriptor */
//	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bLength = USB_CDC_IF_LENGTH;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bLength = USB_IFDSC_LENGTH;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bDescriptorType = USB_INTERFACE;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bInterfaceNumber = if_id;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bAlternateSetting = 0;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bNumEndpoints = USB_CDC_ACM_COMM_EP_NUMBER;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bInterfaceClass = USB_ACM_COMM_INTERFACE_CLASS_CODE;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bInterfaceSubClass = USB_ACM_COMM_INTERFACE_SUBCLASS_CODE;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bInterfaceProtocol = USB_ACM_COMM_INTERFACE_PROTOCOL_CODE;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->iInterface = 
		USB_Get_String_Number((void *)g_UsbACM.acm_param->comm_interface_string);   
	/*Header Functional Descriptor*/
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->HFbFunctionLength = 0x05;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->HFbDescriptorType = 0x24;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->HFbDescriptorSubtype = 0x00;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bcdCDC = 0x0110;
	/*Abstract Control Management Functional Descriptor*/
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->ACMFbFunctionLength = 0x04;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->ACMFbDescriptorType = 0x24;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->ACMFbDescriptorSubtype = 0x02;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->ACMFbmCapabilities = 0x0f;
	/*Union Functional Descriptor*/
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->UFbFunctionLength = 0x05;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->UFbDescriptorType = 0x24;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->UFbDescriptorSubtype = 0x06;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bMasterInterface = if_id;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bSlaveInterface0 = g_UsbACM.data_interface_id;
	/*Call Management Descriptor*/
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->CMFbFunctionLength = 0x05;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->CMFbDescriptorType = 0x24;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->CMFbDescriptorSubtype = 0x01;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->CMFbmCapabilities = 0x03;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bDataInterface = g_UsbACM.data_interface_id;

	/* endpoint handler*/
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USB_Acm_IntrIn_Hdlr);
	g_UsbACM.comm_ep_intr_info->ep_reset = USB_Acm_IntrIn_Reset;

//	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, NULL);
//	g_UsbACM.comm_ep_intr_info->ep_reset = NULL;
	
	/* endpoint descriptor */
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_id);	/*InPipe*/
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bmAttributes = USB_EP_INTR;
#ifndef USB_20_ENABLE
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP&0xff; 		/*HW-dependent*/
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_INTR_MAXP>>8)&0xff; 
#endif
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bInterval = 3;
	g_UsbACM.comm_ep_intr_info->ep_status.epin_status.byEP = ep_id;
	g_UsbACM.comm_ep_intr_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

	g_UsbACM.intr_pkt.bmRequestType = USB_CMD_CLASSIFIN;
	g_UsbACM.intr_pkt.bRequest = USB_ACM_NOTIF_SERIAL_STATE;
	g_UsbACM.intr_pkt.wValue = 0;
	g_UsbACM.intr_pkt.wIndex = if_id;
	g_UsbACM.intr_pkt.wLength = 2;

	if (g_UsbACM.handle == 0)
		GPTI_GetHandle(&g_UsbACM.handle);   /*for break use!!*/

	if (g_UsbACM.ring_buffer_handle == 0)
		GPTI_GetHandle(&g_UsbACM.ring_buffer_handle);   /* for ring buffer time out use!!*/
}

/* communication interface reset function, should enable EP, but we do not use this interrupt EP so not enable it */
void USB_Acm_CommIf_Reset(void)
{
	g_UsbACM.intrpipe = &g_UsbACM.comm_ep_intr_info->ep_status.epin_status;

	/*Non-DMA*/
	USB_TxEPEn(g_UsbACM.intrpipe->byEP, KAL_FALSE);
}


/* communication interface speed reset function, enable EP's speed-specific descriptor */
void USB_Acm_CommIf_Speed_Reset(kal_bool b_other_speed)
{
#ifdef USB_20_ENABLE
	#ifdef  __INTR_HB__
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP_HB&0xff; 		/*HW-dependent*/
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_INTR_MAXP_HB>>8)&0xff; 
	#else
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP_HS&0xff; 		/*HW-dependent*/
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_INTR_MAXP_HS>>8)&0xff; 
	#endif
#endif
}


/* data interface create function, prepare descriptor */
void USB_Acm_DataIf_Create(void *ifname)
{
	kal_uint8 ep_in_id;
	kal_uint8 ep_out_id;
	kal_uint8 if_id;
	

	/* get resource number and register to gUsbDevice */
	g_UsbACM.data_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbACM.data_interface_id = if_id;
	g_UsbACM.data_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_in_id);
	g_UsbACM.data_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_out_id);

	/* record interface name and interface descriptor length */
	g_UsbACM.data_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM.data_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbACM.data_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_UsbACM.data_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler*/
	g_UsbACM.data_if_info->ep_info[0] = g_UsbACM.data_ep_in_info;
	g_UsbACM.data_if_info->ep_info[1] = (Usb_Ep_Info*)g_UsbACM.data_ep_out_info;
	g_UsbACM.data_if_info->if_class_specific_hdlr = NULL;

	/* standard interface descriptor */
	g_UsbACM.data_if_info->ifdscr.stdif.bLength = USB_IFDSC_LENGTH;
	g_UsbACM.data_if_info->ifdscr.stdif.bDescriptorType = USB_INTERFACE;
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceNumber = if_id;
	g_UsbACM.data_if_info->ifdscr.stdif.bAlternateSetting = 0;
	g_UsbACM.data_if_info->ifdscr.stdif.bNumEndpoints = USB_CDC_ACM_DATA_EP_NUMBER;
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceClass = USB_ACM_DATA_INTERFACE_CLASS_CODE;
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceSubClass = USB_ACM_DATA_INTERFACE_SUBCLASS_CODE;
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceProtocol = USB_ACM_DATA_INTERFACE_PROTOCOL_CODE; 
	g_UsbACM.data_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM.acm_param->data_interface_string);   

	/* endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_in_id, NULL);
	g_UsbACM.data_ep_in_info->ep_reset = USB_Acm_BulkIn_Reset;
	
	if(g_UsbACM.acm_owner==USB_ACM_OWNER_DSP)
	{
#ifdef __DSPIRDBG__
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_out_id, NULL);
#else
		EXT_ASSERT(0, g_UsbACM.acm_owner, 0, 0);
#endif
	}
	else if(g_UsbACM.acm_owner==USB_ACM_OWNER_FT)
	{
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_out_id, USB_Acm_FT_BulkOut_Hdr);
	}
	else
	{
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_out_id, USB_Acm_BulkOut_Hdr);
	}

	g_UsbACM.data_ep_out_info->ep_reset = USB_Acm_BulkOut_Reset;

	/* endpoint descriptor */
	g_UsbACM.data_ep_in_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbACM.data_ep_in_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbACM.data_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_in_id);   /*InPipe*/
	g_UsbACM.data_ep_in_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef USB_20_ENABLE
	g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
	g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
#endif
	g_UsbACM.data_ep_in_info->epdesc.stdep.bInterval = 0;
	g_UsbACM.data_ep_in_info->ep_status.epin_status.byEP = ep_in_id;
	g_UsbACM.data_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	g_UsbACM.data_ep_out_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbACM.data_ep_out_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbACM.data_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT | ep_out_id);   /*OutPipe*/
	g_UsbACM.data_ep_out_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef USB_20_ENABLE
	g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
	g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
#endif
	g_UsbACM.data_ep_out_info->epdesc.stdep.bInterval = 0;
	g_UsbACM.data_ep_out_info->ep_status.epout_status.byEP = ep_out_id;

	USB_Get_DMA_Channel(ep_in_id, USB_TX_EP_TYPE, KAL_FALSE);
}

/* data interface reset function, enable EP*/
void USB_Acm_DataIf_Reset(void)
{
	g_UsbACM.txpipe = &g_UsbACM.data_ep_in_info->ep_status.epin_status;
	g_UsbACM.rxpipe = &g_UsbACM.data_ep_out_info->ep_status.epout_status;

	/*DMA*/
	USB_TxEPEn(g_UsbACM.data_ep_in_info->ep_status.epin_status.byEP, KAL_TRUE);
	/*Non-DMA*/
	USB_RxEPEn(g_UsbACM.data_ep_out_info->ep_status.epout_status.byEP, KAL_FALSE);

	if((g_UsbACM.send_UARTilm == KAL_TRUE)&&(USB2UARTPort.ownerid != MOD_DRV_HISR))	
	{
		g_UsbACM.send_UARTilm = KAL_FALSE;
		USB_Send_Msg(USB_SEND_MSG_UART_PLUG_OUT, 0, KAL_TRUE);
	}
}

/* data interface speed reset function, enable EP's speed-specific descriptor */
void USB_Acm_DataIf_Speed_Reset(kal_bool b_other_speed)
{
#ifdef USB_20_ENABLE
	if(USB_Is_High_Speed() == KAL_TRUE)
	{
		if(b_other_speed == KAL_FALSE)
		{
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
		}
		else
		{
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
		}
	}
	else
	{
		if(b_other_speed == KAL_FALSE)
		{
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
		}
		else
		{
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
		}
	}
#endif
}


/************************************************************
	global variable g_UsbACM initialize and release functions
*************************************************************/

/* initialize global variable g_UsbACM */
void USB_Init_Acm_Status(void)
{
	g_UsbACM.txpipe = NULL;
	g_UsbACM.rxpipe = NULL;
	g_UsbACM.intrpipe = NULL;
	g_UsbACM.data_interface_id = 0;
	g_UsbACM.break_detect = KAL_FALSE;
	g_UsbACM.break_number = 0;
	g_UsbACM.out_pipe_race = KAL_FALSE;
	g_UsbACM.send_Txilm = KAL_FALSE;
	g_UsbACM.send_Rxilm = KAL_TRUE;
	g_UsbACM.send_UARTilm = KAL_FALSE;
	g_UsbACM.ring_buffer_timer_counting = KAL_FALSE;
	g_UsbACM.intr_state = ACM_INTR_IDLE;
	g_UsbACM.setup_dma = KAL_FALSE;
}

/* release global variable g_UsbACM */
void USB_Release_Acm_Status(void)
{
	g_UsbACM.txpipe = NULL;
	g_UsbACM.rxpipe = NULL;
	g_UsbACM.intrpipe = NULL;
	g_UsbACM.data_interface_id = 0;
	g_UsbACM.break_detect = KAL_FALSE;
	g_UsbACM.break_number = 0;
	g_UsbACM.out_pipe_race = KAL_FALSE;
	g_UsbACM.send_Txilm = KAL_FALSE;
	g_UsbACM.send_Rxilm = KAL_TRUE;
	g_UsbACM.send_UARTilm = KAL_FALSE;
	g_UsbACM.config_send_Txilm = KAL_FALSE;
	g_UsbACM.intr_state = ACM_INTR_IDLE;
	g_UsbACM.setup_dma = KAL_FALSE;

	if(g_UsbACM.ring_buffer_timer_counting == KAL_TRUE)
	{
		GPTI_StopItem(g_UsbACM.ring_buffer_handle);
		g_UsbACM.ring_buffer_timer_counting = KAL_FALSE;
	}
}



/***********************************************************
   	GPT timer handle break signal
************************************************************/

/* GPT timer handler for break signal */
static void USB_Acm_Break_Timeout(void *parameter)
{
	GPTI_StopItem(g_UsbACM.handle);
	g_UsbACM.break_detect = KAL_FALSE;
	g_UsbACM.break_number++;
	USB2UARTPort.breakDet = KAL_TRUE;
}

/************************************************************
	Ring buffer threshold and time out mechanism APIs
************************************************************/
/* GPT timer handler for ring buffer time out  */
static void USB_Acm_Ring_Buffer_Timeout(void *parameter)
{
	kal_uint32 	addr;
	kal_uint32	length = 0;
	kal_uint32 	savedMask;
	kal_uint8 	ep_num = 0;
	kal_bool 	setup_dma = KAL_FALSE;


	if(INT_Exception_Enter != 0)
		ASSERT(0);

	savedMask = SaveAndSetIRQMask();		
	/* in case usb is plugged out just before this critical section */
	if(gUsbDevice.device_type == USB_CDC_ACM)
	{
//		if(USB_DMA_Get_Run_Status(g_UsbACM.txpipe->byEP) == KAL_FALSE)
		if(g_UsbACM.setup_dma == KAL_FALSE)
		{
			g_UsbACM.setup_dma = KAL_TRUE;
			setup_dma = KAL_TRUE;
			ep_num = g_UsbACM.txpipe->byEP;
		}
	}
	RestoreIRQMask(savedMask);

	if(setup_dma == KAL_TRUE)
	{
		savedMask = SaveAndSetIRQMask();		
		length = USB2UART_Check_Transmit_Data(&addr, KAL_FALSE);
		RestoreIRQMask(savedMask);

		if (length)
		{
			USB_Dbg_Trace(USB_ACM_DMA_SETUP_4, drv_get_current_time(), length, USB2Uart_MemType);
			/* dma running state is cleared by USB2UART_Tx_DMA_Callback */
//			USB_DMA_Setup(ep_num, USB_TX_EP_TYPE, addr, length, USB2UART_Tx_DMA_Callback, KAL_TRUE);
//			USB_DMA_Setup(ep_num, USB_TX_EP_TYPE, addr, length, USB2UART_Tx_DMA_Callback, KAL_FALSE);
			USB_DMA_Setup(ep_num, USB_TX_EP_TYPE, USB_ENDPT_BULK, addr, length, USB2UART_Tx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
		else
		{
			g_UsbACM.setup_dma = KAL_FALSE;
		}
	}
}

void USB_Acm_Ring_Buffer_Threshold_Enable(kal_bool bset, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__	
	if(ownerid != USB2UARTPort.ownerid)
	{
		EXT_ASSERT( 0, (kal_uint32) ownerid, (kal_uint32)USB2UARTPort.ownerid, 0);
	}
#endif /* __PRODUCTION_RELEASE__ */

	g_UsbACM.threshold_enable = bset;

	if(bset == KAL_TRUE)
	{
		drv_trace0(TRACE_FUNC, USBACM_THRESHOLD_ON);
//		kal_prompt_trace(MOD_USB, "Threshold is ON");
	}
	else
	{
		drv_trace0(TRACE_FUNC, USBACM_THRESHOLD_OFF);
//		kal_prompt_trace(MOD_USB, "Threshold is OFF");
	}
}


/************************************************************
	EP0 handle functions
************************************************************/

/* set USB request line coding to UART DCB structure */
static void USB_Acm_Ep0_SetLineCoding(void *data)
{
	kal_uint32 nCount;

	/* read setting and set to UART structure*/
	nCount = USB_EP0_Pkt_Len();
	if(nCount > 0)
	{
		USB_EPFIFORead(0, nCount, &g_UsbACM.line_coding);
   		USB2UART_LineCoding2DCB(&g_UsbACM.line_coding, &USB2UARTPort.DCB);
   		gUsbDevice.ep0_state = USB_EP0_RX_STATUS;

   		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);
	}	
}


/* parse class specific request */
static void USB_Acm_Ep0_Command(Usb_Ep0_Status* pep0state,Usb_Command* pcmd)
{
	kal_uint8 bError = KAL_FALSE;

	switch (pcmd->bRequest)
	{
	case USB_ACM_SET_LINE_CODING:
		/* register handler to handle the get data*/
		USB_Register_EP0_RxHdlr(USB_Acm_Ep0_SetLineCoding);
		gUsbDevice.ep0_state =USB_EP0_RX;
		break;
	case USB_ACM_GET_LINE_CODING:
		/* tell host the current setting */
		USB_Generate_EP0Data(pep0state, pcmd, &g_UsbACM.line_coding, 7);
		break;
	case USB_ACM_SET_CONTROL_LINE_STATE:
		/* do not need to do anything */
		break;
	case USB_ACM_SEND_BREAK:
		/* break behavior */
		switch(pcmd->wValue)
		{
		case 0xffff:
			g_UsbACM.break_detect = KAL_TRUE;
			break;
		case 0x0:
			g_UsbACM.break_detect = KAL_FALSE;
			g_UsbACM.break_number++;
			USB2UARTPort.breakDet = KAL_TRUE;
			break;
		default:
			GPTI_StopItem(g_UsbACM.handle);
			g_UsbACM.break_detect = KAL_TRUE;
			GPTI_StartItem(g_UsbACM.handle, (pcmd->wValue/10),
						USB_Acm_Break_Timeout, NULL);
			break;
		}
		break;
	case USB_ACM_SEND_ENCAPSULATED_COMMAND:
	case USB_ACM_GET_ENCAPSULATED_RESPONSE:
	case USB_ACM_SET_COMM_FEATURE:
	case USB_ACM_GET_COMM_FEATURE:
	case USB_ACM_CLEAR_COMM_FEATURE:
	default:
#ifdef  __PRODUCTION_RELEASE__	
		bError = KAL_TRUE;
#else
		ASSERT(0);
#endif
		break;
	}

	/* Stall command if an error occured */
	if (gUsbDevice.ep0_state == USB_EP0_IDLE)
	{
		gUsbDevice.ep0_state = USB_EP0_RX_STATUS;
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
}


/************************************************************
	Bulk EP OUT handle functions
*************************************************************/

/* 
    Used to retreive exception log, all interrupts are disabled 
    Note that this is special for sending exception log since interrupt is disabled when exception occurs
    It must not be used in normal time 
*/
void USB2UART_Polling_Recv_Data(void)
{
	/* avoid sending ilm to UART owner*/
	g_UsbACM.send_Txilm = KAL_FALSE;
	g_UsbACM.send_Rxilm = KAL_FALSE;
	
	USB_Polling_Recv_Data(g_UsbACM.rxpipe->byEP);
}

/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_Acm_BulkOut_Hdr(void )
{
	kal_int32        RoomLeft;
	kal_uint32         nCount;
	kal_uint32	index;	
	kal_uint8         data[3];
//	kal_uint8         data[USB_EP_BULK_MAXP];
	kal_int32 	remain;
	BUFFER_INFO 	*rx_info = &(USB2UARTPort.Rx_Buffer);
#ifdef USB_20_ENABLE
	kal_uint32	max_bulk_pkt_size;
#endif


	/* Check that this function can not be re-entry */
	ASSERT(g_UsbACM.out_pipe_race == KAL_FALSE);
	g_UsbACM.out_pipe_race = KAL_TRUE;

	/* Stop escape GPT timer */
	if (USB2UARTPort.ESCDet.GuardTime != 0)
		GPTI_StopItem(USB2UARTPort.handle);

	/* check data length and ring buffer empty length*/
	nCount = USB_EP_Rx_Pkt_Len(g_UsbACM.rxpipe->byEP);


	/* This log cannot be executed when assertion because the system stack will overflow */
	if(INT_Exception_Enter == 0)
	{
		drv_trace1(TRACE_FUNC, USBACM_PC_SENT, nCount);
//		kal_prompt_trace(MOD_USB, "PC send %d", nCount);
	}

	
	Buf_GetRoomLeft(&(USB2UARTPort.Rx_Buffer),RoomLeft);

	if(nCount > 0)
	{
		/* rx complete callback*/
		USB2UARTPort.rx_cb(uart_port_usb);

#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef USB_20_ENABLE
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_bulk_pkt_size = USB_EP_BULK_MAXP_HS;
	else
		max_bulk_pkt_size = USB_EP_BULK_MAXP_FS;

	#ifdef  __PRODUCTION_RELEASE__	
		if(nCount > max_bulk_pkt_size)
		{
			nCount = max_bulk_pkt_size;
		}

		if(RoomLeft < nCount)
		{
			nCount = RoomLeft;
		}
	#else
		EXT_ASSERT((nCount <= max_bulk_pkt_size), nCount, max_bulk_pkt_size, 0);
		EXT_ASSERT((RoomLeft >= nCount), RoomLeft, nCount, 0);
	#endif
#else  /* USB_20_ENABLE */
	#ifdef  __PRODUCTION_RELEASE__	
		if(nCount > USB_EP_BULK_MAXP)
		{
			nCount = USB_EP_BULK_MAXP;
		}

		if(RoomLeft < nCount)
		{
			nCount = RoomLeft;
		}
	#else
		EXT_ASSERT((nCount <= USB_EP_BULK_MAXP), nCount, USB_EP_BULK_MAXP, 0);
		EXT_ASSERT((RoomLeft >= nCount), RoomLeft, nCount, 0);
	#endif
#endif  /* USB_20_ENABLE */

		/* Update roomleft parameter*/
		RoomLeft -= nCount;

#ifdef USB_20_ENABLE
		if(RoomLeft < max_bulk_pkt_size)
#else  /* USB_20_ENABLE */
		if(RoomLeft < USB_EP_BULK_MAXP)
#endif  /* USB_20_ENABLE */
		{
			/* rx buffer is less than one max packet size, so mask the IRQ until UART owner get bytes,
			    and than enough room to put a complete packet */
			USB_Set_UnMask_Irq(KAL_FALSE);
		}
		else
		{
			/* make sure that buffer left more than 64 bytes so that next receive it can push to buffer at a time */
			USB_Set_UnMask_Irq(KAL_TRUE);
		}

		if(nCount <= 3)
		{
			USB_EPFIFORead(g_UsbACM.rxpipe->byEP, nCount, data);

			/* Check escape character */
			if(USB2UARTPort.ESCDet.GuardTime != 0)
			{
				/* need to check escape charater */
				for(index = 0; index < nCount; index++)
				{
					/* detect escape sequence  */
					if (USB2UARTPort.Rec_state != UART_RecNormal)
					{
						if (data[index] == USB2UARTPort.ESCDet.EscChar)
						{
							USB2UARTPort.EscCount++;
							if(USB2UARTPort.EscCount == 3)
							{
								USB2UARTPort.Rec_state = UART_Get3EscChar;
							}
							else if(USB2UARTPort.EscCount > 3)
							{
								USB2UARTPort.Rec_state = UART_RecNormal;
								USB2UARTPort.EscCount = 0;
							}
						}
						else
						{
							USB2UARTPort.Rec_state = UART_RecNormal;
							USB2UARTPort.EscCount = 0;
						}
					}
				}
			}

			/* Push all the received data into rx ring buffer */
			for(index = 0; index < nCount; index++)
			{
				Buf_Push(rx_info, data[index]);
			}
		}
		else
		{
			remain = (BWrite(rx_info) + nCount) - BLength(rx_info);

			if(remain < 0)
			{
				USB_EPFIFORead(g_UsbACM.rxpipe->byEP, nCount, BuffWrite(rx_info));
				BWrite(rx_info) += nCount;
			}
			else
			{
				USB_EPFIFORead(g_UsbACM.rxpipe->byEP, (nCount-remain), BuffWrite(rx_info));
				USB_EPFIFORead_Shift(g_UsbACM.rxpipe->byEP, remain, BStartAddr(rx_info), (nCount-remain));
				BWrite(rx_info) = remain;
			}
		}


	}
	
		/* Clear RxPktRdy */
		USB_EP_Bulk_Rx_Ready(g_UsbACM.rxpipe->byEP);

	/* re-start escape GPT timer */
	if (USB2UARTPort.ESCDet.GuardTime != 0)
	{
		GPTI_StartItem(USB2UARTPort.handle, (USB2UARTPort.ESCDet.GuardTime/10),
					USB2UART_Timeout, &USB2UARTPort);
	}

	g_UsbACM.out_pipe_race = KAL_FALSE;
}

/* EP Bulk In reset handler */
static void USB_Acm_BulkIn_Reset(void)
{
	if(g_UsbACM.acm_owner == USB_ACM_OWNER_DSP)
	{
		return;
	}

	if(g_UsbACM.acm_owner == USB_ACM_OWNER_FT)
	{
#ifdef __USB_DOWNLOAD__
		if(gUsbDevice.is_usb_download_mode == KAL_FALSE)
			return;
#else
		return;
#endif
	}

	g_UsbACM.txpipe = &g_UsbACM.data_ep_in_info->ep_status.epin_status;

	USB2UART_Clear_Tx_Buffer(); /* set g_UsbACM.send_Txilm = KAL_TRUE here*/
	USB2UART_Clear_Tx_ISR_Buffer();

/*
	if(g_UsbACM.send_Txilm == KAL_TRUE)
	{
		USB2UART_Sendilm(MSG_ID_UART_READY_TO_WRITE_IND);
		g_UsbACM.send_Txilm = KAL_FALSE;
	}
*/
}


/* EP Bulk Out reset handler */
static void USB_Acm_BulkOut_Reset(void)
{
	if(g_UsbACM.acm_owner == USB_ACM_OWNER_DSP)
	{
		return;
	}

	if(g_UsbACM.acm_owner == USB_ACM_OWNER_FT)
	{
#ifdef __USB_DOWNLOAD__
		if(gUsbDevice.is_usb_download_mode == KAL_FALSE)
			return;
#else
		return;
#endif
	}

	g_UsbACM.rxpipe = &g_UsbACM.data_ep_out_info->ep_status.epout_status;
	g_UsbACM.send_Rxilm = KAL_TRUE;

	drv_trace0(TRACE_FUNC, USBACM_RESET_READY_TO_READ_FLAG);
//	kal_prompt_trace(MOD_USB, "reset RDY R");

	USB2UART_Clear_Rx_Buffer();
}


/* When PC return ACK, handle ACM intr pipe state machine */
static void USB_Acm_IntrIn_Hdlr(void)
{
	kal_int32  len;
#ifdef USB_20_ENABLE	
	kal_uint32  max_intr_pkt_size;
#endif


#ifndef  __PRODUCTION_RELEASE__
	USB_Dbg_Trace(USB_ACM_INTERRUPT_HANDLER, drv_get_current_time(), g_UsbACM.intr_state, 0);
#endif

	if(gUsbDevice.is_configured_now == KAL_FALSE)
	{
		/* USB reset */
		USB_Dbg_Trace(USB_ACM_INTERRUPT_RESET, drv_get_current_time(), 0, 0);
		g_UsbACM.intr_state = ACM_INTR_IDLE;
		return;
	}

#ifdef USB_20_ENABLE	
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_intr_pkt_size = USB_EP_INTR_MAXP_HS;
	else
		max_intr_pkt_size = USB_EP_INTR_MAXP_FS;
#endif

	switch(g_UsbACM.intr_state)
	{
	case ACM_INTR_SEND_ONE_PKT:
		g_UsbACM.intr_state = ACM_INTR_SEND_LAST_PKT;
	#ifdef USB_20_ENABLE
		len = ((kal_int32)sizeof(UsbAcm_Intr_Pkt)) -max_intr_pkt_size;
	#else
		len = ((kal_int32)sizeof(UsbAcm_Intr_Pkt)) - USB_EP_INTR_MAXP;
	#endif


#ifndef  __PRODUCTION_RELEASE__
		/* send last short packet */
		USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT2, drv_get_current_time(), g_UsbACM.intr_state, 0);
		drv_trace1(TRACE_FUNC, USBACM_INTR, g_UsbACM.intr_pkt.Data);
//		kal_prompt_trace(MOD_DRV_HISR, "ACM INTR %d", g_UsbACM.intr_pkt.Data);
#endif
	#ifdef USB_20_ENABLE
		USB_EPFIFOWrite(g_UsbACM.intrpipe->byEP, len, (kal_uint8 *)(kal_uint32)&g_UsbACM.intr_pkt+max_intr_pkt_size);
	#else
		USB_EPFIFOWrite(g_UsbACM.intrpipe->byEP, len, (kal_uint8 *)(kal_uint32)&g_UsbACM.intr_pkt + USB_EP_INTR_MAXP);
	#endif
		USB_EP_Bulk_Tx_Ready(g_UsbACM.intrpipe->byEP);
		break;

	case ACM_INTR_SEND_LAST_PKT:
		g_UsbACM.intr_state = ACM_INTR_IDLE;

		/* Send another intr pkt */
		if(g_UsbACM.is_intr_pending_pkt == KAL_TRUE)
		{
			g_UsbACM.is_intr_pending_pkt = KAL_FALSE;
	#ifdef USB_20_ENABLE
			if(max_intr_pkt_size > sizeof(UsbAcm_Intr_Pkt))
	#else
			if(USB_EP_INTR_MAXP > sizeof(UsbAcm_Intr_Pkt))
	#endif
			{
				g_UsbACM.intr_state = ACM_INTR_SEND_LAST_PKT;

			#ifndef  __PRODUCTION_RELEASE__
				/* send only one short packet */
				USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT2, drv_get_current_time(), g_UsbACM.intr_state, 0);
				drv_trace1(TRACE_FUNC, USBACM_INTR, g_UsbACM.intr_pkt.Data);
//				kal_prompt_trace(MOD_DRV_HISR, "ACM INTR %d", g_UsbACM.intr_pkt.Data);
			#endif
				USB_EPFIFOWrite(g_UsbACM.intrpipe->byEP, sizeof(UsbAcm_Intr_Pkt), (kal_uint8 *)&g_UsbACM.intr_pkt);
				USB_EP_Bulk_Tx_Ready(g_UsbACM.intrpipe->byEP);
			}
			else
			{
				g_UsbACM.intr_state = ACM_INTR_SEND_ONE_PKT;

			#ifndef  __PRODUCTION_RELEASE__
				/* send one max packet */
				USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT1, drv_get_current_time(), g_UsbACM.intr_state, 0);
				drv_trace1(TRACE_FUNC, USBACM_INTR, g_UsbACM.intr_pkt.Data);
//				kal_prompt_trace(MOD_DRV_HISR, "ACM INTR %d", g_UsbACM.intr_pkt.Data);
			#endif
		#ifdef USB_20_ENABLE
				USB_EPFIFOWrite(g_UsbACM.intrpipe->byEP, max_intr_pkt_size, (kal_uint8 *)&g_UsbACM.intr_pkt);
		#else
				USB_EPFIFOWrite(g_UsbACM.intrpipe->byEP, USB_EP_INTR_MAXP, (kal_uint8 *)&g_UsbACM.intr_pkt);
		#endif
				USB_EP_Bulk_Tx_Ready(g_UsbACM.intrpipe->byEP);
			}
		}

		break;

	case ACM_INTR_IDLE:
	default:
		EXT_ASSERT(0, (kal_uint32)g_UsbACM.intr_state, 0, 0);
		break;
	}
}


static void USB_Acm_IntrIn_Reset(void)
{
	g_UsbACM.intr_state = ACM_INTR_IDLE;
}

/************************************************************
	FT mode rx functions
************************************************************/

/* register callback function for rx data */
void USB_Acm_FT_Register_Rx_Cb(usb_acm_rx_ptr cb)
{
	g_UsbACM.ft_rx_cb = cb;
}

/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_Acm_FT_BulkOut_Hdr(void )
{
	kal_uint32	nCount;

	/* check that this function can not be re-entry */
	ASSERT((g_UsbACM.out_pipe_race==KAL_FALSE));
	
	g_UsbACM.out_pipe_race = KAL_TRUE;

	/* check data lendth and ring buffer empty length*/
	nCount = USB_EP_Rx_Pkt_Len(g_UsbACM.rxpipe->byEP);

	if(nCount > 0)
	{
		USB_EPFIFORead(g_UsbACM.rxpipe->byEP, nCount, g_UsbACM.ft_data);

		g_UsbACM.ft_data_len = nCount;

		/* Clear OutPktRdy */
	//	USB_EP_Bulk_Rx_Ready(g_UsbACM.rxpipe->byEP);

		/* notify FT task */
		if(g_UsbACM.ft_rx_cb==NULL)
			ASSERT(0);

		g_UsbACM.ft_rx_cb();

		/* rx buffer is less than one max packet size, so unmask the IRQ until UART owner get bytes,
		    and enough room to put a complete packet */
		USB_Set_UnMask_Irq(KAL_FALSE);
	}

	   	USB_EP_Bulk_Rx_Ready(g_UsbACM.rxpipe->byEP);
	   
	g_UsbACM.out_pipe_race = KAL_FALSE;
}


