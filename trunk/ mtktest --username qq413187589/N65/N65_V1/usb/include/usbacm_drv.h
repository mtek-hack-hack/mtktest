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
 *    usbacm_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for usb CDC ACM class driver definitions
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
 
#ifndef USBACM_DRV_H
#define USBACM_DRV_H

#include "uart_sw.h"
#include "usb_custom.h"

/***********************************************
	acm class specific command definition
************************************************/

#define USB_ACM_DEVICE_CODE			0x02
#define USB_ACM_SUBCLASS_CODE			0x00
#define USB_ACM_PROTOCOL_CODE			0x00
#define USB_ACM_COMM_INTERFACE_CLASS_CODE 	0x02
#define USB_ACM_COMM_INTERFACE_SUBCLASS_CODE 	0x02
#define USB_ACM_COMM_INTERFACE_PROTOCOL_CODE 	0x01
#define USB_ACM_DATA_INTERFACE_CLASS_CODE 	0x0a
#define USB_ACM_DATA_INTERFACE_SUBCLASS_CODE 	0x00
#define USB_ACM_DATA_INTERFACE_PROTOCOL_CODE 	0x00

#define USB_CDC_IF_LENGTH     			28   /* standard plus class */

/* Class-Specfic Codes ,EP0*/
#define USB_ACM_SEND_ENCAPSULATED_COMMAND	0x00
#define USB_ACM_GET_ENCAPSULATED_RESPONSE	0x01
#define USB_ACM_SET_COMM_FEATURE		0x02
#define USB_ACM_GET_COMM_FEATURE		0x03
#define USB_ACM_CLEAR_COMM_FEATURE		0x04
#define USB_ACM_SET_LINE_CODING			0x20
#define USB_ACM_GET_LINE_CODING			0x21
#define USB_ACM_SET_CONTROL_LINE_STATE		0x22
#define USB_ACM_SEND_BREAK			0x23

/*Notifications, interrupt pipe*/
#define USB_ACM_NOTIF_NETWORK_CONNECTION	0x00
#define USB_ACM_NOTIF_RESPONSE_AVAILABLE	0x01
#define USB_ACM_NOTIF_SERIAL_STATE		0x20

/* UART state bitmap values */
#define SERIAL_STATE_BRXCARRIER			0x01


/*USB_ACM_SET_CONTROL_LINE_STATE*/    /*  not use anywhere  */
#define CONTROL_LINE_SIGNAL_RTS			0x02  /*DCE's RTS,DTE's CTS*/
#define CONTROL_LINE_SIGNAL_DTR			0x01  /*DCE's DTR,DTE's DSR*/


/***********************************************
	implement definition
************************************************/

#define USB_CDC_ACM_COMM_EP_NUMBER     		1  /*interrupt pipe*/
#define USB_CDC_ACM_DATA_EP_NUMBER     		2

#define USBACM_RING_BUFFER_TIMEOUT			50

/***********************************************
	acm class specific descriptor structure
************************************************/

/* CDC ACM communication interface descriptor element */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bInterfaceNumber;
	kal_uint8    bAlternateSetting;
	kal_uint8    bNumEndpoints;
	kal_uint8    bInterfaceClass;
	kal_uint8    bInterfaceSubClass;
	kal_uint8    bInterfaceProtocol;
	kal_uint8    iInterface;

	kal_uint8    HFbFunctionLength;		/*Header Functional Descriptor*/
	kal_uint8    HFbDescriptorType;
	kal_uint8    HFbDescriptorSubtype;
	kal_uint16   bcdCDC;

	kal_uint8    ACMFbFunctionLength;	/*Abstract Control Management Functional Descriptor*/
	kal_uint8    ACMFbDescriptorType;
	kal_uint8    ACMFbDescriptorSubtype;
	kal_uint8    ACMFbmCapabilities;

	kal_uint8    UFbFunctionLength;		/*Union Functional Descriptor*/
	kal_uint8    UFbDescriptorType;
	kal_uint8    UFbDescriptorSubtype;
	kal_uint8    bMasterInterface;
	kal_uint8    bSlaveInterface0;

	kal_uint8    CMFbFunctionLength;	/*Call Management Descriptor*/
	kal_uint8    CMFbDescriptorType;
	kal_uint8    CMFbDescriptorSubtype;
	kal_uint8    CMFbmCapabilities;
	kal_uint8    bDataInterface;
} Usb_Cdc_If_Dscr;


/*  ACM line coding element */
typedef struct
{
	kal_uint32  dwDTERate;
	kal_uint8   bCharFormat;
	kal_uint8   bParityType;
	kal_uint8   bDataBits;
} UsbAcm_Line_Coding;


/* ACM interrupt packet structure */
typedef struct
{
	kal_uint8		bmRequestType;
	kal_uint8		bRequest;
	kal_uint16	wValue;
	kal_uint16	wIndex;
	kal_uint16	wLength;
	kal_uint16	Data;
}UsbAcm_Intr_Pkt;


/***********************************************
	implement enum and structure 
************************************************/

/* transmit buffer type */
typedef enum 
{
	USBTRX_MEM_UNKOWN = 0,
	USBTRX_MEM_ISR,
	USBTRX_MEM_TASK,
	USBTRX_MEM_MAX_TYPE
} USBTRX_MEM_TYPE;

typedef enum 
{
	ACM_INTR_IDLE = 0,
	ACM_INTR_SEND_ONE_PKT,
	ACM_INTR_SEND_LAST_PKT
}USB_ACM_INTR_PIPE_STATE;


/* current acm driver owner application*/
typedef enum
{
	USB_ACM_OWNER_UART = 0,
	USB_ACM_OWNER_FT, 
	USB_ACM_OWNER_DSP
}USB_ACM_OWNER_TYPE;

typedef void (*usb_acm_rx_ptr)(void);

/* ACM device structure */
typedef struct
{
	Usb_EpBIn_Status	*txpipe;		/* bulk in EP, Data interface */
	Usb_EpBOut_Status	*rxpipe;		/* bulk out EP, Data interface */
	Usb_EpBIn_Status	*intrpipe;		/* interrupt EP, Communication Interface */
	UsbAcm_Line_Coding	line_coding;		/* current line coding, just used to reply to host */
	UsbAcm_Intr_Pkt		intr_pkt;
	kal_uint8		handle;    		/*GPT handle*/
	kal_uint8		ring_buffer_handle;	/* ring buffer's GPT handle */

	USB_ACM_INTR_PIPE_STATE	intr_state;				/* interrupt pipe state machine */

	Usb_Ep_Info			*comm_ep_intr_info;
	Usb_Ep_Info			*data_ep_in_info;
	Usb_Ep_Info			*data_ep_out_info;
	Usb_Interface_Info	*comm_if_info;
	Usb_Interface_Info	*data_if_info;

	kal_uint8		data_interface_id;
	kal_bool 		break_detect;
	kal_uint32 		break_number;
	kal_bool		out_pipe_race;
	kal_bool 		send_Txilm;
	kal_bool 		send_Rxilm;
	kal_bool		send_UARTilm;
	kal_bool		config_send_Txilm;
	kal_bool		ring_buffer_timer_counting;		/* flag to check ring buffer timer running or not */
	kal_bool		threshold_enable;				/* enable ring buffer threshold and time out mechanism */
//	kal_bool		force_ISR_buffer;				/* when true means that ISR buffer must be transmitted at DMA call back */
	kal_bool		setup_dma;						/* a flag to record DMA is triggered or not */
	kal_bool		is_intr_pending_pkt;				/* interrupt pipe has pending packet */

	/* ft mode param */
	USB_ACM_OWNER_TYPE	acm_owner;
#ifdef USB_20_ENABLE
	kal_uint8			ft_data[USB_EP_BULK_MAXP_HS];
#else
	kal_uint8			ft_data[USB_EP_BULK_MAXP];
#endif
	kal_uint16			ft_data_len;
	usb_acm_rx_ptr		ft_rx_cb;

	/* customizable variables*/
	const USB_ACM_PARAM	*acm_param;
} UsbAcm_Struct;


/***********************************************
	function and global variable
************************************************/
extern UARTStruct USB2UARTPort;
extern UsbAcm_Struct g_UsbACM;

extern void USB2UART_LineCoding2DCB(UsbAcm_Line_Coding *pline_coding, UARTDCBStruct *pDCB);
extern void UART2USB_DCB2LineCoding(UARTDCBStruct *pDCB, UsbAcm_Line_Coding *pline_coding);

extern void USB2UART_Timeout(void *parameter);

extern void USB2UART_Dafault_Tx_Callback(UART_PORT port);
extern void USB2UART_Dafault_Rx_Callback(UART_PORT port);
extern void USB_Acm_Ring_Buffer_Threshold_Enable(kal_bool bset, module_type ownerid);

extern void USB2UART_Polling_Flush_Transmit_Data(void);
extern void USB2UART_Polling_Recv_Data(void);
extern void USB2UART_DMATransmit(kal_uint8 ep_num, kal_bool b_force_isr_buffer);
extern void USB_Acm_Rx_ClrFifo(void);

extern void USB_Acm_CommIf_Create(void *ifname);
extern void USB_Acm_CommIf_Reset(void);
extern void USB_Acm_CommIf_Speed_Reset(kal_bool b_other_speed);
extern void USB_Acm_DataIf_Create(void *ifname);
extern void USB_Acm_DataIf_Reset(void);
extern void USB_Acm_DataIf_Speed_Reset(kal_bool b_other_speed);

extern void USB_Init_Acm_Status(void);
extern void USB_Release_Acm_Status(void);

extern void USB_Acm_FT_Register_Rx_Cb(usb_acm_rx_ptr cb);

#endif /* USBACM_DRV_H */

