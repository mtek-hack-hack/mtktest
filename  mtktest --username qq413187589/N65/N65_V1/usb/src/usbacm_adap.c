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
 *    usbacm_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb adaption layer for UART API
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
#include "intrCtrl.h"
#include "kal_release.h"
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"  
#include "app_buff_alloc.h"
#include "drv_comm.h"
#include "gpt_sw.h"
#include "uart_sw.h"

#include "usb_comm.h"
#include "usb_drv.h"
#include "usb_trc.h"
#include "usb.h"
#include "usbacm_drv.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"


/* Exception flag*/
extern kal_uint8 INT_Exception_Enter; 

/* UART driver structure*/
static const UartDriver_strcut USB2UartDriver;

/* static functions*/
static kal_bool USB2UART_open(UART_PORT port, module_type owner);
static void USB2UART_close(UART_PORT port, module_type owner);
static void USB2UART_ClrRxBuffer(UART_PORT port, module_type owner);
static kal_uint16 USB2UART_GetRxAvail(UART_PORT port);
static kal_uint16 USB2UART_GetBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, 
					kal_uint8 *status, module_type ownerid);
static void USB2UART_ClrTxBuffer(UART_PORT port, module_type owner);
static kal_uint16 USB2UART_GetTxRoomLeft(UART_PORT port);
static kal_uint16 USB2UART_PutBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
static kal_uint16 USB2UART_SendData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,
					kal_uint8 mode,kal_uint8 escape_char , module_type ownerid);
static kal_uint16 USB2UART_GetTxISRRoomLeft(UART_PORT port);
static kal_uint16 USB2UART_PutISRBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
static kal_uint16 USB2UART_SendISRData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,kal_uint8 mode, 
					kal_uint8 escape_char, module_type ownerid);
static void USB2UART_setowner(UART_PORT port, kal_uint8 owner);
static module_type USB2UART_GetOwnerID(UART_PORT port);
static void USB2UART_ConfigEscape(UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type owner);
static void USB2UART_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type owner);
static void USB2UART_Purge(UART_PORT port, UART_buffer dir, module_type owner);
static void USB2UART_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type owner);
static void USB2UART_CtrlDCD(UART_PORT port, IO_level SDCD, module_type owner);
static void USB2UART_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type owner);
static void USB2UART_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type owner);
static void USB2UART_SetAutoBaud_Div(UART_PORT port, module_type owner);
static void USB2UART_Register_TX_Callback(UART_PORT port, module_type ownerid, UART_TX_FUNC func);
static void USB2UART_Register_RX_Callback(UART_PORT port, module_type ownerid, UART_RX_FUNC func);


/************************************************************
	communication with UART owner and initialize functions
*************************************************************/

/* send ilm to UART owner */
void USB2UART_Sendilm(msg_type msgid)
{
	ilm_struct *USB2UART_ilm;
	void *port_ptr = NULL;      
	
	if (USB2UARTPort.ownerid == MOD_DRV_HISR)
		return;
			
	switch(msgid)
	{
	case MSG_ID_UART_READY_TO_READ_IND:	   		 	
		{
			uart_ready_to_read_ind_struct *tmp;      
   			tmp = (uart_ready_to_read_ind_struct *) 
   					construct_local_para(sizeof(uart_ready_to_read_ind_struct),TD_UL);
   			tmp->port = USB2UARTPort.port_no;   		
   			port_ptr = tmp;   		
   		}
   		break;	
   		
   	case MSG_ID_UART_READY_TO_WRITE_IND:     
   		{ 		
   			uart_ready_to_write_ind_struct *tmp;      
   			tmp = (uart_ready_to_write_ind_struct *) 
   					construct_local_para(sizeof(uart_ready_to_write_ind_struct),TD_UL);
   			tmp->port = USB2UARTPort.port_no;   		
   			port_ptr = tmp;
   		}
   		break;
   		
   	case MSG_ID_UART_ESCAPE_DETECTED_IND:   	
   		{
   			uart_escape_detected_ind_struct *tmp;      
   			tmp = (uart_escape_detected_ind_struct *) 
   					construct_local_para(sizeof(uart_escape_detected_ind_struct),TD_UL);
   			tmp->port = USB2UARTPort.port_no;   		
   			port_ptr = tmp;   		
   		}
   		break;
   		
   	default:
   		EXT_ASSERT(0, msgid, 0, 0);
   		break;   	
   	}   

	if (USB2UARTPort.ownerid == MOD_DRV_HISR)
		EXT_ASSERT(0, USB2UARTPort.ownerid, 0, 0);
	
	DRV_BuildPrimitive(USB2UART_ilm, MOD_DRV_HISR,
					USB2UARTPort.ownerid, msgid, port_ptr);
	msg_send_ext_queue(USB2UART_ilm);
}

/* initialize USB2UART setting, called when driver initialize, no matter user select as UART or not */
void USB2UART_init(void)
{
#ifndef __USB_ENABLE__
	ASSERT(0);
#endif
	
	/* Setup N81,(UART_WLS_8 | UART_NONE_PARITY | UART_1_STOP) = 0x03 */
	/* BaudRate and autoflowcontrol */
	UARTDCBStruct  UART_DefaultConfig =
	{
		UART_BAUD_115200,    /* baud; */
		len_8,               /* dataBits; */
		sb_1,                /*stopBits; */
		pa_none,             /* parity; */
		fc_none,             /*no flow control*/
		0x11,                /* xonChar; */
		0x13,                /* xoffChar; */
		KAL_FALSE
	};

	g_UsbACM.acm_param = USB_GetCustomFunc()->get_acm_param_func();
	
	/* get memory for ring buffer and initialize it */
	if (USB2UARTPort.RingBuffers.rx_buffer == NULL)
		USB2UARTPort.RingBuffers.rx_buffer = (kal_uint8 *)g_UsbACM.acm_param->rx_ringbuff;

	if (USB2UARTPort.RingBuffers.tx_buffer == NULL)
		USB2UARTPort.RingBuffers.tx_buffer = (kal_uint8 *)g_UsbACM.acm_param->tx_ringbuff;

	if (USB2UARTPort.RingBuffers.txISR_buffer == NULL)
		USB2UARTPort.RingBuffers.txISR_buffer = (kal_uint8 *)g_UsbACM.acm_param->txisr_ringbuff;

	Buf_init(&(USB2UARTPort.Rx_Buffer),(kal_uint8 *)(USB2UARTPort.RingBuffers.rx_buffer), 
			g_UsbACM.acm_param->rx_ringbuff_size);
   	Buf_init(&(USB2UARTPort.Tx_Buffer),(kal_uint8 *)(USB2UARTPort.RingBuffers.tx_buffer), 
   			g_UsbACM.acm_param->tx_ringbuff_size);
   	Buf_init(&(USB2UARTPort.Tx_Buffer_ISR),(kal_uint8 *)(USB2UARTPort.RingBuffers.txISR_buffer), 
   			g_UsbACM.acm_param->txisr_ringbuff_size);
   	
	/* set UART setting to USB2UARTPort.DCB and g_UsbACM.line_coding */
	USB2UARTPort.UART_id = MOD_DRV_HISR;
	kal_mem_cpy(&USB2UARTPort.DCB, &UART_DefaultConfig, sizeof(UARTDCBStruct));
	if (USB2UARTPort.ownerid == 0)
	{
		USB2UARTPort.ownerid = MOD_DRV_HISR;
		UART2USB_DCB2LineCoding(&USB2UARTPort.DCB, &g_UsbACM.line_coding);
	}

	/* register UART and get GPT handler */
	if (USB2UARTPort.handle == 0)
		GPTI_GetHandle(&USB2UARTPort.handle);
	
	UART_Register(uart_port_usb, USB_TYPE, (UartDriver_strcut*)&USB2UartDriver);

	g_UsbACM.send_Txilm = KAL_FALSE;
	g_UsbACM.send_Rxilm = KAL_TRUE;

	drv_trace0(TRACE_FUNC, USBACM_INIT_READY_TO_READ_FLAG);
//	kal_prompt_trace(MOD_USB, "init RDY R");

	g_UsbACM.config_send_Txilm = KAL_FALSE;
	USB2UARTPort.tx_cb = USB2UART_Dafault_Tx_Callback;
	USB2UARTPort.rx_cb = USB2UART_Dafault_Rx_Callback;
	USB2UARTPort.port_no = uart_port_usb;
}


/* Clear Tx Ring buffer */
void USB2UART_Clear_Tx_Buffer(void)
{
	USB2UART_ClrTxBuffer(uart_port_usb, USB2UARTPort.ownerid);
}

/* clear tx isr buffer */
void USB2UART_Clear_Tx_ISR_Buffer(void)
{
	kal_uint32 savedMask;


	drv_trace0(TRACE_FUNC, USBACM_CLEAR_TX_ISR_BUF);
//	kal_prompt_trace(MOD_USB, "clrTxISR");


	savedMask = SaveAndSetIRQMask();
	USB2UARTPort.Tx_Buffer_ISR.Write = 0;
	USB2UARTPort.Tx_Buffer_ISR.Read = 0;
	USB_Stop_DMA_Channel(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE);	
	RestoreIRQMask(savedMask);
}

/* clear rx buffer */
void USB2UART_Clear_Rx_Buffer(void)
{
	USB2UART_ClrRxBuffer(uart_port_usb, USB2UARTPort.ownerid);
}



/************************************************************
	UART driver  functions
*************************************************************/

/* open USB2UART port , actually port is no use because only support one USB port */
static kal_bool USB2UART_open(UART_PORT port, module_type owner)
{
#ifndef __USB_ENABLE__
	ASSERT(0);
#endif

	if(g_UsbACM.acm_owner == USB_ACM_OWNER_DSP)
	{
		ASSERT(0);
	}

	if(g_UsbACM.acm_owner == USB_ACM_OWNER_FT)
	{
#ifdef __USB_DOWNLOAD__
		if(gUsbDevice.is_usb_download_mode == KAL_FALSE)
			ASSERT(0);
#else
		ASSERT(0);
#endif
	}
		
	/* It cannot be opened if uart owner did not close it before */
	if(USB2UARTPort.ownerid != MOD_DRV_HISR)
	{
		return KAL_FALSE;
	}

#ifndef  __PRODUCTION_RELEASE__
	if(INT_Exception_Enter != 0)
	{
	drv_trace0(TRACE_FUNC, USBACM_OPEN);
//	kal_prompt_trace(MOD_USB, "USB Open");
	}
#endif /* __PRODUCTION_RELEASE__ */
	USB2UARTPort.initialized = KAL_TRUE;
	USB2UARTPort.ownerid = owner;

	g_UsbACM.send_Txilm = KAL_FALSE;
	g_UsbACM.send_Rxilm = KAL_TRUE;

	if(INT_Exception_Enter != 0)
	{
	drv_trace1(TRACE_FUNC, USBACM_OPEN_READY_TO_READ_FLAG, owner);
//	kal_prompt_trace(MOD_USB, "open RDY R %d", owner);
	}

	g_UsbACM.config_send_Txilm = KAL_FALSE;
	g_UsbACM.threshold_enable = KAL_FALSE;

	if( (USB2UARTPort.RingBuffers.rx_buffer==NULL) || (USB2UARTPort.RingBuffers.tx_buffer==NULL) ||
		(USB2UARTPort.RingBuffers.txISR_buffer==NULL) )
	{
		EXT_ASSERT(0, (kal_uint32)USB2UARTPort.RingBuffers.rx_buffer, (kal_uint32)USB2UARTPort.RingBuffers.tx_buffer, 
					(kal_uint32)USB2UARTPort.RingBuffers.txISR_buffer);
	}

	Buf_init(&(USB2UARTPort.Rx_Buffer),(kal_uint8 *)(USB2UARTPort.RingBuffers.rx_buffer), 
			g_UsbACM.acm_param->rx_ringbuff_size);
	Buf_init(&(USB2UARTPort.Tx_Buffer),(kal_uint8 *)(USB2UARTPort.RingBuffers.tx_buffer), 
			g_UsbACM.acm_param->tx_ringbuff_size);
	Buf_init(&(USB2UARTPort.Tx_Buffer_ISR),(kal_uint8 *)(USB2UARTPort.RingBuffers.txISR_buffer), 
			g_UsbACM.acm_param->txisr_ringbuff_size);
			
	if(g_UsbACM.ring_buffer_timer_counting == KAL_TRUE)
	{
		GPTI_StopItem(g_UsbACM.ring_buffer_handle);
		g_UsbACM.ring_buffer_timer_counting = KAL_FALSE;
	}

	if ((gUsbDevice.device_type == USB_CDC_ACM)&&(gUsbDevice.nDevState==DEVSTATE_CONFIG))
	{
		/* Only out EP needs to be enabled since IN EP will use DMA polling*/
		USB_TxEPEn(g_UsbACM.txpipe->byEP, KAL_TRUE);
		USB_RxEPEn(g_UsbACM.rxpipe->byEP, KAL_FALSE);
		USB_Set_UnMask_Irq(KAL_TRUE);
	}		

	return KAL_TRUE;
}

/* close  USB2UART port */
static void USB2UART_close(UART_PORT port, module_type ownerid)
{
#ifndef __USB_ENABLE__
	ASSERT(0);
#endif

#ifndef  __PRODUCTION_RELEASE__	
	if(ownerid != USB2UARTPort.ownerid)
	{
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif	

	if(INT_Exception_Enter != 0)
	{
	drv_trace1(TRACE_FUNC, USBACM_CLOSE, ownerid);
//	kal_prompt_trace(MOD_USB, "USB Close %d", ownerid);
	}
	
	g_UsbACM.send_Txilm = KAL_FALSE;
	g_UsbACM.config_send_Txilm = KAL_FALSE;
	USB2UARTPort.initialized = KAL_FALSE;
	USB2UARTPort.ownerid = MOD_DRV_HISR;
	g_UsbACM.threshold_enable = KAL_FALSE;

	if ((gUsbDevice.device_type == USB_CDC_ACM)&&(gUsbDevice.nDevState==DEVSTATE_CONFIG))
	{
	        /* disable endpoint interrupt */
		USB_TxEPDis(g_UsbACM.txpipe->byEP, KAL_TRUE);
		USB_RxEPDis(g_UsbACM.rxpipe->byEP, KAL_FALSE);
	}

	Buf_init(&(USB2UARTPort.Rx_Buffer),(kal_uint8 *)(USB2UARTPort.RingBuffers.rx_buffer), 
			g_UsbACM.acm_param->rx_ringbuff_size);
	Buf_init(&(USB2UARTPort.Tx_Buffer),(kal_uint8 *)(USB2UARTPort.RingBuffers.tx_buffer), 
			g_UsbACM.acm_param->tx_ringbuff_size);
	Buf_init(&(USB2UARTPort.Tx_Buffer_ISR),(kal_uint8 *)(USB2UARTPort.RingBuffers.txISR_buffer), 
			g_UsbACM.acm_param->txisr_ringbuff_size);

	if(g_UsbACM.ring_buffer_timer_counting == KAL_TRUE)
	{
		GPTI_StopItem(g_UsbACM.ring_buffer_handle);
		g_UsbACM.ring_buffer_timer_counting = KAL_FALSE;
	}
	
	USB2UART_ConfigEscape(port, 0xff, 0, MOD_DRV_HISR);
}

/* clear rx buffer */
static void USB2UART_ClrRxBuffer(UART_PORT port, module_type ownerid)
{
	kal_uint32 savedMask;
	

#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}

#endif
	drv_trace0(TRACE_FUNC, USBACM_CLEAR_RX_BUF);
//	kal_prompt_trace(MOD_USB, "clrRx");

	/* clear hardware fifo if current status is CDC ACM*/
	if ( (gUsbDevice.device_type == USB_CDC_ACM) && (USB2UARTPort.initialized == KAL_TRUE) 
		&&(gUsbDevice.nDevState==DEVSTATE_CONFIG) )
	{
		/* clear rx fifo*/
		USB_Acm_Rx_ClrFifo();
	    /* clear interrupt mask variable */
	    USB_Set_UnMask_Irq(KAL_TRUE);
	}
	
	savedMask = SaveAndSetIRQMask();	
	/* clear ring buffer*/
	USB2UARTPort.Rx_Buffer.Write = 0;
	USB2UARTPort.Rx_Buffer.Read = 0;
	g_UsbACM.send_Rxilm = KAL_TRUE;
	RestoreIRQMask(savedMask);

	drv_trace1(TRACE_FUNC, USBACM_CLEAR_RX_BUF_READY_TO_READ_FLAG, ownerid);
//	kal_prompt_trace(MOD_USB, "clr RDY R %d", ownerid);

}

/* get available bytes in rx buffer */
static kal_uint16 USB2UART_GetRxAvail(UART_PORT port)
{
	kal_uint16 real_count;
	kal_uint32 savedMask;


	savedMask = SaveAndSetIRQMask();
	Buf_GetBytesAvail(&(USB2UARTPort.Rx_Buffer),real_count);
	RestoreIRQMask(savedMask);
	return real_count;
}

/* get bytes from rx buffer, parameter status shows escape and break status 
     return value is the actually get bytes */
static kal_uint16 USB2UART_GetBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, 
					kal_uint8 *status, module_type ownerid)
{
	kal_uint16  real_count;
//	kal_uint16  index;
	kal_uint16  RoomLeft;
	kal_uint32 savedMask;
	kal_uint32 error_count;
	kal_int32 	remain;
	BUFFER_INFO 	*rx_info = &(USB2UARTPort.Rx_Buffer);
	

	if(ownerid != USB2UARTPort.ownerid)
	{
#ifdef  __PRODUCTION_RELEASE__
		return 0;
#else /* __PRODUCTION_RELEASE__ */
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
#endif
	}

	/* return directly if not match condition */
	if ( (gUsbDevice.device_type != USB_CDC_ACM) || 
		(USB2UARTPort.initialized == KAL_FALSE) || (gUsbDevice.nDevState!=DEVSTATE_CONFIG))
		return 0;

	/* determine real data count */
	/* Note that the area to determine send_Rxilm must also contain in critical section.
	   Otherwise if USB HISR activated before send_Rxilm setting as true, 
	   this message will be lost */
	savedMask = SaveAndSetIRQMask();

	Buf_GetBytesAvail(rx_info, real_count);

	if(real_count >= length)
	{
		real_count = length;
	}
	else
	{
		g_UsbACM.send_Rxilm = KAL_TRUE;  /*After this time get byte, buffer will be empty */
	}
	RestoreIRQMask(savedMask);	

#ifndef  __PRODUCTION_RELEASE__
	if(g_UsbACM.send_Rxilm == KAL_TRUE)
	{
		drv_trace1(TRACE_FUNC, USBACM_GET_BYTES_BUF_EMPTY, ownerid);
//		kal_prompt_trace(MOD_USB, "RDY R %d", ownerid);
	}
#endif

	if(real_count != 0)
	{
		remain = (BRead(rx_info) + real_count) - BLength(rx_info);

		if(remain < 0)
		{
			/* dest, src, len */
			kal_mem_cpy(buffaddr, BuffRead(rx_info), real_count);
			BRead(rx_info) += real_count;
		}
		else
		{
			kal_mem_cpy(buffaddr, BuffRead(rx_info), real_count-remain);
			kal_mem_cpy((kal_uint8 *)(buffaddr+real_count-remain), BStartAddr(rx_info), remain);
			BRead(rx_info) = remain;
		}
	}

	/* pop data from ring buffer to caller buffer */
/*
	for (index = 0; index < real_count; index++)
	{
		Buf_Pop(rx_info, *(buffaddr+index));
	}
*/

	/* update status */
	if (status != NULL)
	{
		*status = 0;
		if (USB2UARTPort.EscFound)
		{
			*status |= UART_STAT_EscDet;
			USB2UARTPort.EscFound = KAL_FALSE;
		}
		if (USB2UARTPort.breakDet)
		{
			*status |= UART_STAT_Break;
			USB2UARTPort.breakDet = KAL_FALSE;
		}
	}

	IRQMask(IRQ_USB_CODE);
	Buf_GetRoomLeft(rx_info, RoomLeft);

#ifdef USB_20_ENABLE
	/* only unmask IRQ if ring buffer room left >= MAX BULK PKT SIZE */
	if((USB_Is_High_Speed() == KAL_TRUE)&&(RoomLeft >= USB_EP_BULK_MAXP_HS)
			||(USB_Is_High_Speed() == KAL_FALSE)&&(RoomLeft >= USB_EP_BULK_MAXP_FS))
	{
		error_count = USB_Get_HW_Error_Count();

		if(error_count <= 8)
		{
			USB_Set_UnMask_Irq(KAL_TRUE);
			IRQUnmask(IRQ_USB_CODE);
		}
		else
		{
			drv_trace0(TRACE_FUNC, USBACM_FAIL_NOT_UNMASK);
//			kal_prompt_trace(MOD_USB, "UNMASK USB FAIL");
		}
	}

#else
	/* only unmask IRQ if ring buffer room left >= 64 */
	if(RoomLeft >= USB_EP_BULK_MAXP)
	{
		error_count = USB_Get_HW_Error_Count();

		if(error_count <= 8)
		{
			USB_Set_UnMask_Irq(KAL_TRUE);
			IRQUnmask(IRQ_USB_CODE);
		}
		else
		{
			drv_trace0(TRACE_FUNC, USBACM_FAIL_NOT_UNMASK);
//			kal_prompt_trace(MOD_USB, "UNMASK USB FAIL");
		}
	}
#endif

#ifndef  __PRODUCTION_RELEASE__
	if(ownerid != USB2UARTPort.ownerid)
	{
		EXT_ASSERT( 0, (kal_uint32) ownerid, (kal_uint32)USB2UARTPort.ownerid, 0);
	}

	drv_trace1(TRACE_FUNC, USBACM_GET_BYTES, real_count);
//	kal_prompt_trace(MOD_USB, "Get %d", real_count);
#endif /* __PRODUCTION_RELEASE__ */

	return real_count;
}

/* clear tx buffer */
static void USB2UART_ClrTxBuffer(UART_PORT port, module_type ownerid)
{
	kal_uint32 savedMask;


#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif

	drv_trace0(TRACE_FUNC, USBACM_CLEAR_TX_BUF);
//	kal_prompt_trace(MOD_USB, "clrTx\n");

	/* stop dma channel if current status is CDC ACM*/
	if ( (gUsbDevice.device_type == USB_CDC_ACM) && (USB2UARTPort.initialized == KAL_TRUE)
		 &&(gUsbDevice.nDevState==DEVSTATE_CONFIG))
	{
		USB_Stop_DMA_Channel(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE);	
	}
	
	savedMask = SaveAndSetIRQMask();
	USB2UARTPort.Tx_Buffer.Write = 0;
	USB2UARTPort.Tx_Buffer.Read = 0;			
	g_UsbACM.send_Txilm = KAL_TRUE;	
	RestoreIRQMask(savedMask);

	drv_trace1(TRACE_FUNC, USBACM_CLEAR_TX_BUF_READY_TO_READ_FLAG, ownerid);
//	kal_prompt_trace(MOD_USB, "clr RDY W %d", ownerid);

}

/*get the left bytes for tx buffer*/
static kal_uint16 USB2UART_GetTxRoomLeft(UART_PORT port)
{
	kal_uint16 real_count;
	kal_uint32  savedMask;


	savedMask = SaveAndSetIRQMask();
	Buf_GetRoomLeft(&(USB2UARTPort.Tx_Buffer),real_count);
	RestoreIRQMask(savedMask);
	return real_count;
}

/*put bytes to tx buffer, return value is the actually put out bytes*/
static kal_uint16 USB2UART_PutBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid)
{
	kal_uint16  real_count;
//	kal_uint16  index;
	kal_uint32  savedMask;
	kal_uint8  ep_num = 0;
	kal_bool  setup_dma = KAL_FALSE;
	kal_int32 	remain;
	BUFFER_INFO 	*tx_info = &(USB2UARTPort.Tx_Buffer);


	if(ownerid != USB2UARTPort.ownerid)
	{
#ifdef  __PRODUCTION_RELEASE__		
		return 0;
#else /* __PRODUCTION_RELEASE__ */
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
#endif
	}

	/* return directly if not match condition */
	if ( (gUsbDevice.device_type != USB_CDC_ACM) || 
		(USB2UARTPort.initialized == KAL_FALSE) || (gUsbDevice.nDevState!=DEVSTATE_CONFIG))
	{
		if(((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.usb_comport_boot == KAL_TRUE))
			&& (USB2UARTPort.initialized == KAL_TRUE)&&(gUsbDevice.nDevState != DEVSTATE_CONFIG))
		{
			g_UsbACM.config_send_Txilm = KAL_TRUE;  /* for PC set config later then can issue the first message */
		}
		return 0;
	}

	/* The same issue as USB2UART_GetBytes() 
	   The area to determine send_Txilm must also contain in critical section.
	   Otherwise if DMA callback activated before send_Txilm setting as true, 
	   this message will be lost */
	savedMask = SaveAndSetIRQMask();

	Buf_GetRoomLeft(tx_info, real_count);

	/* determine real sent data count */
	if (real_count > length)
	{
		real_count = length;
	}
	else
	{
		g_UsbACM.send_Txilm = KAL_TRUE;  /*After this time put bytes, buffer will be full */
		g_UsbACM.config_send_Txilm = KAL_TRUE; /* if be reseted, then it can issue the message waited for*/
	}
	RestoreIRQMask(savedMask);	


	if(g_UsbACM.send_Txilm == KAL_TRUE)
	{
		if(ownerid != MOD_TST_READER)
		{
		drv_trace1(TRACE_FUNC, USBACM_PUT_BYTES_BUF_FULL, ownerid);
//		kal_prompt_trace(MOD_USB, "RDY W %d", ownerid);
        	}
	}


	if(real_count != 0)
	{
		remain = (BWrite(tx_info) + real_count) - BLength(tx_info);

		if(remain < 0)
		{
			/* dest, src, len */
			kal_mem_cpy(BuffWrite(tx_info), buffaddr, real_count);
			BWrite(tx_info) += real_count;
		}
		else
		{
			kal_mem_cpy(BuffWrite(tx_info), buffaddr, real_count-remain);
			kal_mem_cpy(BStartAddr(tx_info), (kal_uint8 *)(buffaddr+real_count-remain), remain);
			BWrite(tx_info) = remain;
		}
	}


	/* push data from caller buffer to ring buffer */
/*
	for (index = 0; index < real_count; index++)
	{
		Buf_Push(&(USB2UARTPort.Tx_Buffer), *(buffaddr+index));
	}
*/

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
		USB_Dbg_Trace(USB_ACM_DMA_SETUP_1, drv_get_current_time(), ep_num, 0);
		USB2UART_DMATransmit(ep_num, KAL_FALSE);
	}

#ifndef  __PRODUCTION_RELEASE__
	if(ownerid != USB2UARTPort.ownerid)
	{
		EXT_ASSERT( 0, (kal_uint32) ownerid, (kal_uint32)USB2UARTPort.ownerid, 0);
	}

	if(ownerid != MOD_TST_READER)
	{
		drv_trace1(TRACE_FUNC, USBACM_PUT_BYTES, real_count);
//		kal_prompt_trace(MOD_USB, "Put %d", real_count);
	}
#endif

	return real_count;
}

/*put bytes to tx buffer, return value is the actually put out bytes*/
static kal_uint16 USB2UART_SendData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,
					kal_uint8 mode,kal_uint8 escape_char , module_type ownerid)
{
	/* caller handle special character already, so do not need to handle it */
	return USB2UART_PutBytes(port, buffaddr, length, ownerid);
}

/*get the left bytes for tx buffer*/
static kal_uint16 USB2UART_GetTxISRRoomLeft(UART_PORT port)
{
	kal_uint16 real_count;
	kal_uint32  savedMask;
	

	savedMask = SaveAndSetIRQMask();
	Buf_GetRoomLeft(&(USB2UARTPort.Tx_Buffer_ISR),real_count);
	RestoreIRQMask(savedMask);
	return real_count;
}

/* put bytes to ISR tx buffer, return value is the actually put out bytes */
static kal_uint16 USB2UART_PutISRBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid)
{
	kal_uint16  real_count;
//	kal_uint16  index;
	kal_uint32  savedMask;
	kal_uint8  ep_num = 0;
	kal_bool  setup_dma = KAL_FALSE;
	kal_int32 	remain;
	BUFFER_INFO 	*tx_isr_info = &(USB2UARTPort.Tx_Buffer_ISR);


	if(ownerid != USB2UARTPort.ownerid)
	{
#ifdef  __PRODUCTION_RELEASE__		
		return 0;
#else /* __PRODUCTION_RELEASE__ */
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
#endif
	}
	
	if ( (gUsbDevice.device_type != USB_CDC_ACM) || 
		(USB2UARTPort.initialized == KAL_FALSE) || (gUsbDevice.nDevState!=DEVSTATE_CONFIG))
		return 0;

	savedMask = SaveAndSetIRQMask();
	Buf_GetRoomLeft(tx_isr_info, real_count);
	RestoreIRQMask(savedMask);
	
	/* determine real sent data count */
	if (real_count > length)
		real_count = length;

	if(real_count != 0)
	{
		remain = (BWrite(tx_isr_info) + real_count) - BLength(tx_isr_info);

		if(remain < 0)
		{
			/* dest, src, len */
			kal_mem_cpy(BuffWrite(tx_isr_info), buffaddr, real_count);
			BWrite(tx_isr_info) += real_count;
		}
		else
		{
			kal_mem_cpy(BuffWrite(tx_isr_info), buffaddr, real_count-remain);
			kal_mem_cpy(BStartAddr(tx_isr_info), (kal_uint8 *)(buffaddr+real_count-remain), remain);
			BWrite(tx_isr_info) = remain;
		}
	}

	/* push data from caller buffer to ring buffer */
/*
	for (index = 0; index < real_count; index++)
	{
		Buf_Push(tx_isr_info, *(buffaddr+index));
	}
*/

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
		USB_Dbg_Trace(USB_ACM_DMA_SETUP_2, drv_get_current_time(), ep_num, 0);
		USB2UART_DMATransmit(ep_num, KAL_FALSE);
	}

#ifndef  __PRODUCTION_RELEASE__	
	if(ownerid != USB2UARTPort.ownerid)
	{
		EXT_ASSERT( 0, (kal_uint32) ownerid, (kal_uint32)USB2UARTPort.ownerid, 0);
	}

#endif

	if(ownerid != MOD_TST_READER)
	{
		drv_trace1(TRACE_FUNC, USBACM_PUT_ISR_BYTES, real_count);
//		kal_prompt_trace(MOD_USB, "PutISR %d", real_count);
	}

	return real_count;
}

/* put bytes to ISR tx buffer, handle the special character in this function(add escape character)
    return value is the actually put out bytes*/
static kal_uint16 USB2UART_SendISRData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,
					kal_uint8 mode, kal_uint8 escape_char, module_type ownerid)
{
	kal_int16  real_count, index;
	kal_uint8  data;
	kal_uint32 savedMask;
	kal_uint8  ep_num = 0;
	kal_bool  setup_dma = KAL_FALSE;
	BUFFER_INFO 	*tx_isr_info = &(USB2UARTPort.Tx_Buffer_ISR);


	if(ownerid != USB2UARTPort.ownerid)
	{
#ifdef  __PRODUCTION_RELEASE__		
		return 0;
#else
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
#endif
	}

	if ( (gUsbDevice.device_type != USB_CDC_ACM) || 
		(USB2UARTPort.initialized == KAL_FALSE) || (gUsbDevice.nDevState!=DEVSTATE_CONFIG))
		return 0;

	if (mode == 0)
	{
		real_count = USB2UART_PutISRBytes(port, buffaddr, length, ownerid);
	}
	else
	{
		savedMask = SaveAndSetIRQMask();
		Buf_GetRoomLeft(tx_isr_info, real_count);
		RestoreIRQMask(savedMask);
		
		/* determine real sent data count */
		if (real_count > length)
			real_count = length;

		for (index = 0; index < real_count; index++)
		{
			kal_uint16 roomleft;
			
			savedMask = SaveAndSetIRQMask();
			Buf_GetRoomLeft(tx_isr_info, roomleft);
			RestoreIRQMask(savedMask);
			
			data = *(buffaddr + index);
			/* if the character is special character, translate it. PC has the ability to distinguish it*/
			if (data == USB2UARTPort.DCB.xonChar)
			{
				if ( roomleft >= 2 )
				{
					Buf_Push(tx_isr_info, escape_char);
					Buf_Push(tx_isr_info, 0x01);
				}
				else
				{
					break;
				}
			}
			else if (data == USB2UARTPort.DCB.xoffChar)
			{
				if ( roomleft >= 2 )
				{
					Buf_Push(tx_isr_info, escape_char);
					Buf_Push(tx_isr_info, 0x02);
				}
				else
				{
					break;
				}
			}
			else if (data == escape_char)
			{
				if ( roomleft >= 2 )
				{
					Buf_Push(tx_isr_info, escape_char);
					Buf_Push(tx_isr_info, 0x03);
				}
				else
				{
					break;
				}
			}
			else
			{
				if (roomleft)
				{
					Buf_Push(tx_isr_info, data);
				}
				else
				{
					break;
				}
			}
		}
		
		real_count = index;

		savedMask = SaveAndSetIRQMask();
		/* in case usb is plugged out just before this critical section */
		if(gUsbDevice.device_type == USB_CDC_ACM)
		{
//			if(USB_DMA_Get_Run_Status(g_UsbACM.txpipe->byEP) == KAL_FALSE)
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
			USB_Dbg_Trace(USB_ACM_DMA_SETUP_3, drv_get_current_time(), ep_num, 0);
			USB2UART_DMATransmit(ep_num, KAL_FALSE);
		}
	}

#ifndef  __PRODUCTION_RELEASE__	
	if(ownerid != USB2UARTPort.ownerid)
	{
		EXT_ASSERT( 0, (kal_uint32) ownerid, (kal_uint32)USB2UARTPort.ownerid, 0);
	}


#endif
	if(ownerid != MOD_TST_READER)
	{
		drv_trace1(TRACE_FUNC, USBACM_SEND_ISR_DATA, real_count);
//		kal_prompt_trace(MOD_USB, "SendISR %d", real_count);
	}
	
	return real_count;
}

/* set owner for UART port */
static void USB2UART_setowner(UART_PORT port, kal_uint8 owner)
{
	if(g_UsbACM.acm_owner == USB_ACM_OWNER_DSP)
	{
		ASSERT(0);
	}

	if(g_UsbACM.acm_owner == USB_ACM_OWNER_FT)
	{
#ifdef __USB_DOWNLOAD__
		if(gUsbDevice.is_usb_download_mode == KAL_FALSE)
			ASSERT(0);
#else
		ASSERT(0);
#endif
	}


	drv_trace1(TRACE_FUNC, USBACM_SET_OWNER, owner);
//	kal_prompt_trace(MOD_USB, "setowner %d", owner);


	USB2UARTPort.ownerid = owner;
}

/* get current UART owner id */
static module_type USB2UART_GetOwnerID(UART_PORT port)
{
	return USB2UARTPort.ownerid;
}

/* config escape charater and guard time */
static void USB2UART_ConfigEscape(UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif

	USB2UARTPort.ESCDet.EscChar = EscChar;
	USB2UARTPort.ESCDet.GuardTime = ESCGuardtime;
	if (USB2UARTPort.ESCDet.GuardTime)
	{
		USB2UARTPort.Rec_state = UART_RecNormal;
		GPTI_StartItem(USB2UARTPort.handle, (USB2UARTPort.ESCDet.GuardTime/10),
					USB2UART_Timeout, &USB2UARTPort);
	}
}


static void USB2UART_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
	
	kal_mem_cpy(&USB2UARTPort.DCB, UART_Config, sizeof(UARTDCBStruct));
}


static void USB2UART_Purge(UART_PORT port, UART_buffer dir, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
}

static void USB2UART_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid)    
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
} 

static void USB2UART_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid)
{
	kal_uint32 savedMask;
	kal_bool  b_set_intr;
	kal_uint8  ep_num = 0;
#ifdef USB_20_ENABLE
	kal_uint32 max_intr_pkt_size;
#endif


#ifndef  __PRODUCTION_RELEASE__		
	USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT, drv_get_current_time(), g_UsbACM.intr_state, 0);

	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif

	savedMask = SaveAndSetIRQMask();
	if((g_UsbACM.intr_state == ACM_INTR_IDLE)&&(gUsbDevice.is_configured_now == KAL_TRUE))
	{
		b_set_intr = KAL_TRUE;
		g_UsbACM.is_intr_pending_pkt = KAL_FALSE;
		ep_num = g_UsbACM.intrpipe->byEP;
	}
	else
	{
		b_set_intr = KAL_FALSE;
		g_UsbACM.is_intr_pending_pkt = KAL_TRUE;
	}

	if(SDCD == io_high)
		g_UsbACM.intr_pkt.Data = SERIAL_STATE_BRXCARRIER;
	else if (SDCD == io_low)
		g_UsbACM.intr_pkt.Data = 0x00;
	else
		ASSERT(0);
	RestoreIRQMask(savedMask);

	if(b_set_intr == KAL_TRUE)
	{
#ifdef USB_20_ENABLE	
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_intr_pkt_size = USB_EP_INTR_MAXP_HS;
	else
		max_intr_pkt_size = USB_EP_INTR_MAXP_FS;

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
//			kal_prompt_trace(MOD_USB, "ACM INTR %d", g_UsbACM.intr_pkt.Data);
	#endif
			USB_EPFIFOWrite(ep_num, sizeof(UsbAcm_Intr_Pkt), (kal_uint8 *)&g_UsbACM.intr_pkt);
			USB_EP_Bulk_Tx_Ready(ep_num);
		}
		else
		{
			g_UsbACM.intr_state = ACM_INTR_SEND_ONE_PKT;

	#ifndef  __PRODUCTION_RELEASE__
			/* send one max packet */
			USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT1, drv_get_current_time(), g_UsbACM.intr_state, 0);
			drv_trace1(TRACE_FUNC, USBACM_INTR, g_UsbACM.intr_pkt.Data);
//			kal_prompt_trace(MOD_USB, "ACM INTR %d", g_UsbACM.intr_pkt.Data);
	#endif
	#ifdef USB_20_ENABLE
			USB_EPFIFOWrite(ep_num, max_intr_pkt_size, (kal_uint8 *)&g_UsbACM.intr_pkt);
	#else
			USB_EPFIFOWrite(ep_num, USB_EP_INTR_MAXP, (kal_uint8 *)&g_UsbACM.intr_pkt);
	#endif
			USB_EP_Bulk_Tx_Ready(ep_num);
		}
	}
} 

static void USB2UART_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
}

static void USB2UART_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
}

static void USB2UART_SetAutoBaud_Div(UART_PORT port, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
}

static void USB2UART_Register_TX_Callback(UART_PORT port, module_type ownerid, UART_TX_FUNC func)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
	USB2UARTPort.tx_cb = func;   
}
  
static void USB2UART_Register_RX_Callback(UART_PORT port, module_type ownerid, UART_RX_FUNC func)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif	
	USB2UARTPort.rx_cb = func;   
} 

/* This function is only used for retrive exception log*/
static kal_uint8 USB2UART_GetUARTByte(UART_PORT port)
{
	kal_uint32 real_count = 0;
	kal_uint32 RoomLeft = 0;
	kal_uint8 data;
	

	/* This function can only be called after exception*/
	if(INT_Exception_Enter == 0)
		ASSERT(0);
	
	if ((gUsbDevice.device_type != USB_CDC_ACM)||(USB2UARTPort.initialized == KAL_FALSE))
	{
		/* This function should only be called when assertion, if not CDC_ACM type, trap in while loop*/
		while(1);
	}

	Buf_GetBytesAvail(&(USB2UARTPort.Rx_Buffer),real_count);
	
	while(real_count==0)
	{
		/* polling received data*/
		USB2UART_Polling_Recv_Data();
		Buf_GetBytesAvail(&(USB2UARTPort.Rx_Buffer),real_count);
	}

	Buf_Pop(&(USB2UARTPort.Rx_Buffer),data);   /* one byte at a time */

	/* set unmask flag if room left is larger than USB_EP_BULK_MAXP */
	Buf_GetRoomLeft(&(USB2UARTPort.Rx_Buffer),RoomLeft);

	/* only unmask IRQ if ring buffer romm left >= MAX BULK PKt SIZE */
#ifdef USB_20_ENABLE
	if(USB_Is_High_Speed() == KAL_TRUE)
	{
		if(RoomLeft >= USB_EP_BULK_MAXP_HS)
		{
			USB_Set_UnMask_Irq(KAL_TRUE);
		}
	}
	else
	{
		if(RoomLeft >= USB_EP_BULK_MAXP_FS)
		{
			USB_Set_UnMask_Irq(KAL_TRUE);
		}
	}
#else
	if(RoomLeft >= USB_EP_BULK_MAXP)
	{
		USB_Set_UnMask_Irq(KAL_TRUE);
	}
#endif

	return data;
}

/* This function is only used for retrive exception log*/
static void USB2UART_PutUARTByte(UART_PORT port, kal_uint8 data)
{
	/* This function can only be called after exception*/
	if(INT_Exception_Enter == 0)
		ASSERT(0);
			
	if ((gUsbDevice.device_type != USB_CDC_ACM)||(USB2UARTPort.initialized == KAL_FALSE))
	{
		/* This function should only be called when assertion, if not CDC_ACM type, return it directly*/
		return;
	}
		
	/* flush previous data first*/
	USB2UART_Polling_Flush_Transmit_Data();

	/* put data to tx queue*/
	/* push data from caller buffer to ring buffer */
	Buf_Push(&(USB2UARTPort.Tx_Buffer), data);
	
	/* flush the tx queue*/
	USB2UART_Polling_Flush_Transmit_Data();
}

/* This function is only used for retrive exception log*/
static void USB2UART_PutUARTBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length)
{
	kal_uint32 index;
	kal_uint16 data_length = 0;
	kal_uint16 offset = 0;
	

	/* This function can only be called after exception*/
	if(INT_Exception_Enter == 0)
		ASSERT(0);

	if ( (gUsbDevice.device_type != USB_CDC_ACM)||(USB2UARTPort.initialized == KAL_FALSE))
	{
		/* This function should only be called when assertion, if not CDC_ACM type, return it directly*/
		return;
	}

	/* flush previous data first*/
	USB2UART_Polling_Flush_Transmit_Data();

	/* If data length is larger than TX ring buffer, seperate to send as seceral times*/
	do
	{
		if((Length - offset) > g_UsbACM.acm_param->tx_ringbuff_size)	
		{
			data_length = g_UsbACM.acm_param->tx_ringbuff_size;
		}
		else
		{
			data_length = Length - offset;
		}
		/* put data to tx queue*/
		/* push data from caller buffer to ring buffer */
		for (index = 0; index < data_length; index++)
		{
			Buf_Push(&(USB2UARTPort.Tx_Buffer),*(Buffaddr+offset+index));
		}
		offset+=data_length;
		/* flush the tx queue*/
		USB2UART_Polling_Flush_Transmit_Data();		
	}while(offset<Length);	
}

static void USB2UART_ReadDCBConfig(UART_PORT port, UARTDCBStruct *DCB)
{
	kal_mem_cpy(DCB, &USB2UARTPort.DCB, sizeof(UARTDCBStruct));
}

static void USB2UART_CtrlRI (UART_PORT port, IO_level SRI, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
}

static void USB2UART_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid)
{
#ifndef  __PRODUCTION_RELEASE__		
	if(ownerid != USB2UARTPort.ownerid)
	{	
		EXT_ASSERT( 0, (kal_uint32) ownerid, USB2UARTPort.ownerid, 0);
	}
#endif
}

static void USB2UART_ReadHWStatus(UART_PORT port, IO_level *SDSR, IO_level *SCTS)
{
	kal_mem_set(SDSR, 0, sizeof(IO_level));
	kal_mem_set(SCTS, 0, sizeof(IO_level));
}


static const UartDriver_strcut USB2UartDriver = 
{
	USB2UART_open,
	USB2UART_close,
	USB2UART_GetBytes,
	USB2UART_PutBytes,
	USB2UART_GetRxAvail,
	USB2UART_GetTxRoomLeft,
	USB2UART_PutISRBytes,
	USB2UART_GetTxISRRoomLeft,
	USB2UART_Purge,
	USB2UART_setowner,
	USB2UART_SetFlowCtrl,	
	USB2UART_ConfigEscape,
	USB2UART_SetDCBConfig,
	USB2UART_CtrlDCD,	
	USB2UART_CtrlBreak,
	USB2UART_ClrRxBuffer,
	USB2UART_ClrTxBuffer,
	USB2UART_SetBaudRate,	
	USB2UART_SendISRData,
	USB2UART_SendData,
	USB2UART_GetOwnerID,
	USB2UART_SetAutoBaud_Div,
	USB2UART_Register_TX_Callback,        
	USB2UART_Register_RX_Callback,
	/* Add for retrive exception log */
	USB2UART_GetUARTByte,
	USB2UART_PutUARTByte,
	USB2UART_PutUARTBytes, 
	USB2UART_ReadDCBConfig,
	USB2UART_CtrlRI,
	USB2UART_CtrlDTR,
	USB2UART_ReadHWStatus
};

