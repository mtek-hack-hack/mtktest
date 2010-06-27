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
 *    usb_hcd_pri.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb host hardware related function definitions. Only use for hardware driver.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USB_HCD_PRI_H
#define USB_HCD_PRI_H

#include "usb_drv.h"

#define  USB_HCD_DEBOUNCE_DELAY			(10)	 /* 10ms unit */
#define  USB_HCD_RESET_RECOVERY_DELAY	(1)
#define  USB_HCD_RESET_DELAY			(6)

#define USB_HCD_BDT_NUMBER				4
#define USB_HCD_MAX_PIPES				5

#define USB_HCD_FASTMODE_PKT_SIZE		64

/* BDT structure */
typedef struct
{
	kal_uint32	PID_OWN_DATA01_BC;
	kal_uint32	ADDRESS;
} USB_BDT, *USB_BDT_PTR;

/* BDT macro*/
#define USB_BDT_RX		0
#define USB_BDT_TX		1
#define USB_BDT_EVEN	0
#define USB_BDT_ODD		1
#define WRITE_EP0_BDT(direction, even_odd, value)  g_UsbHcdInfo.bdt_ptr[direction][even_odd] = value

#define WRITE_EP0_BDT_PID(direction, even_odd, value)	g_UsbHcdInfo.bdt_ptr[direction][even_odd]->PID_OWN_DATA01_BC = value
#define READ_EP0_BDT_PID(direction, even_odd)	g_UsbHcdInfo.bdt_ptr[direction][even_odd]->PID_OWN_DATA01_BC

#define WRITE_EP0_BDT_ADDR(direction, even_odd, value)	g_UsbHcdInfo.bdt_ptr[direction][even_odd]->ADDRESS = value
#define READ_EP0_BDT_ADDR(direction, even_odd)	g_UsbHcdInfo.bdt_ptr[direction][even_odd]->ADDRESS


/* endpoint information*/
typedef struct
{
	kal_bool					b_in_use;
	kal_bool					b_enable;
	USB_HCD_ENDPT_TYPE			ep_type;			/* Control, interrupt, bulk or   */
	kal_uint8					ep_num;
	USB_HCD_PIPE_DIRECTION		direction;			/* For control endpoint, this indicates data direction*/
	kal_uint8					data01;
	kal_uint16					interval;			/* For interrupt/isochronous, this is polling frequency
												     For bulk/control, this is NAK limit*/
	kal_uint16					current_interval;

	kal_uint8					no_response_count;										     

	/* keep send/recv buffer addr, wait for scheduler*/
	kal_uint8					*p_data;
	kal_uint16					data_length;
	/* If normal mode and data length > max pkt size */
	kal_uint16					max_packet_size;
	kal_uint16					sofar;

	kal_int8					next_ep_id;

	kal_bool					b_fast_mode_enable;
}USB_HCD_EP_INFO;

typedef struct 
{
	USB_BDT_PTR					bdt_ptr[USB_HCD_BDT_NUMBER/2][2];

	USB_HCD_STATUS				reset_reason;

	/* interrupt handler */
	usb_hcd_intr_handler_ptr	attach_hdlr;
	usb_hcd_intr_handler_ptr	detach_hdlr;
	usb_hcd_intr_handler_ptr	resume_hdlr;

	/* endpoint related information*/
	usb_hcd_intr_handler_ptr	ep_hdlr[USB_HCD_MAX_PIPES];	/* includes EP0*/
	USB_HCD_EP_INFO				ep_info[USB_HCD_MAX_PIPES];

	kal_bool					ep0_setup;

	kal_uint8					rx_even_odd;
 	kal_uint8					tx_even_odd;	

	/* attach/detach debounce time*/
	kal_uint8					gpt_handle;    /*GPT handle*/
	
	/* may be omit */
	kal_uint32					resume_timer; 	

	/* read/write synchronize*/
	kal_int8					rx_curent_index;
	kal_int8					tx_curent_index;

	/* For scheduler*/
	kal_int8					processing_ep_id;
	
	kal_int8					iso_pipe_head;	/* -1 means no pipe */
	kal_int8					iso_pipe_tail;
	kal_int8					intr_pipe_head;
	kal_int8					intr_pipe_tail;
	kal_int8					ctrl_pipe_head;	
	kal_int8					ctrl_pipe_tail;	
	kal_int8					bulk_pipe_head;	
	kal_int8					bulk_pipe_tail;

	kal_bool					b_unmask_irq;

	USB_EP_TYPE					dma_dir;
	kal_int8					dma_index;
	kal_uint8					dma_port;  
   	kal_bool					dma_pktrdy;
   	kal_bool					dma_running;
   	kal_bool					dma_callback_upd_run;
   	//usb_dma_callback			dma_callback;
	kal_uint8					dma_pktlength;

	/* dma and fast mode sequnce control parameters*/
	kal_uint8					dma_tx_ep;
 	kal_uint8					dma_res_tx_ep;
 	kal_uint8					fast_mode_tx_ep;

	//kal_bool					b_wait_rx_dma;
	//kal_bool					b_wait_rx_fm_done;
	kal_bool					b_wait_dma;
	kal_bool					b_wait_fm_done;
	
 	kal_uint32					fast_mode_data_size;

 	kal_bool					b_disable_attach;
} USB_HCD_Struct;

#endif /* USB_HCD_PRI_H */

