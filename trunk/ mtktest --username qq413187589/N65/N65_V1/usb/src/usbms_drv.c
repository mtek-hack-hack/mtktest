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
 *    usbms_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb MASS STORAGE class driver
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
 
#include "drv_comm.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"  
#include "app_buff_alloc.h"
#include "drvsignals.h"
#include "gpt_sw.h"

#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usb_resource.h"

#include "usbms_utils.h"
#include "usbms_drv.h"
#include "usbms_adap.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"


UsbMs_Struct g_UsbMS;

/* static functions */
static void USB_Ms_DMA_Timeout_hdlr(void *parameter);
static void USB_Ms_Rx_DMA_Callback(void);
static void USB_Ms_Tx_DMA_Callback(void);

static void USB_Ms_Ep0_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Ms_BulkIn_Reset(void);
static void USB_Ms_BulkOut_Reset(void);
static void USB_Ms_Cmd_Reset(void);


/************************************************************
	DMA time out handler
*************************************************************/
static void USB_Ms_DMA_Timeout_hdlr(void *parameter)
{
	GPTI_StopItem(g_UsbMS.dma_timeout_handle);

#ifndef  __PRODUCTION_RELEASE__	
	USB_Dbg_Trace(USB_MS_BUILD_DMA_RX_TIMEOUT, drv_get_current_time(), 0 , 0);
	kal_prompt_trace(MOD_USB, "DMA time out");
#endif

	if((gUsbDevice.is_configured_now == KAL_TRUE)&&(gUsbDevice.device_type == USB_MASS_STORAGE))
	{
		g_UsbMS.cmd_is_vaild = KAL_FALSE;
		USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
		USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
	}
}


/************************************************************
	Tx/Rx path build functions(use DMA)
*************************************************************/

/* prepare to receive Rx packet to addr and length len */
void  USB_Ms_BuildRx(void *addr, kal_uint32 len)
{
	GPTI_StopItem(g_UsbMS.dma_timeout_handle);

	USB_Dbg_Trace(USB_MS_BUILD_DMA_RX, drv_get_current_time(), 0 , 0);

	/* stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE);

	/* initialize rxpipe data */
	g_UsbMS.rxpipe->pData = (kal_uint8 *)addr;
	g_UsbMS.rxpipe->nBytesRecv = 0;
	g_UsbMS.rxpipe->nBuffLen = len;
	//USB_Ms_Dbg_Trace(USB_DBG_BUILDrecREQ, g_UsbMS.rxpipe->nBuffLen);

	/* For ms cmd's length == 31 */
	if(len == 31)
	{
		GPTI_StartItem(g_UsbMS.dma_timeout_handle, USBMS_DMA_TIMEOUT, USB_Ms_DMA_Timeout_hdlr, NULL);
	}

	/* dma running state is NOT cleared by USB_Ms_Rx_DMA_Callback */
//	USB_DMA_Setup(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, (kal_uint32)addr, len, USB_Ms_Rx_DMA_Callback, KAL_FALSE);
	USB_DMA_Setup(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)addr, len, USB_Ms_Rx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
}


/* prepare to transmit Tx packet from addr and length len */	
void  USB_Ms_BuildTx(void *addr, kal_uint32 len)
{
	USB_Dbg_Trace(USB_MS_BUILD_DMA_TX, drv_get_current_time(), 0 , 0);

	/* stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE);

	/* initialize tx pipe*/
	g_UsbMS.txpipe->pData = (kal_uint8 *)addr;
	g_UsbMS.txpipe->nBytesLeft = len;

	/* dma running state is NOT cleared by USB_Ms_Tx_DMA_Callback */
//	USB_DMA_Setup(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, (kal_uint32)addr, len, USB_Ms_Tx_DMA_Callback, KAL_FALSE);
	USB_DMA_Setup(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)addr, len, USB_Ms_Tx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
}


/************************************************************
	interface initialization functions
*************************************************************/

/* interface create function, prepare descriptor */
void USB_Ms_If_Create(void *ifname)
{
	kal_uint8 ep_in_id;
	kal_uint8 ep_out_id;
	kal_uint8 if_id;

	/* get resource number and register to gUsbDevice */
	g_UsbMS.ms_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbMS.ms_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_in_id);
	g_UsbMS.ms_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_out_id);

	/* record interface name and interface descriptor length */
	g_UsbMS.ms_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbMS.ms_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbMS.ms_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_UsbMS.ms_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler*/
	g_UsbMS.ms_if_info->ep_info[0] = (Usb_Ep_Info*)g_UsbMS.ms_ep_in_info;
	g_UsbMS.ms_if_info->ep_info[1] = (Usb_Ep_Info*)g_UsbMS.ms_ep_out_info;
	g_UsbMS.ms_if_info->if_class_specific_hdlr = USB_Ms_Ep0_Command;

	/* standard interface descriptor */
	g_UsbMS.ms_if_info->ifdscr.stdif.bLength = USB_IFDSC_LENGTH;
	g_UsbMS.ms_if_info->ifdscr.stdif.bDescriptorType = USB_INTERFACE;
	g_UsbMS.ms_if_info->ifdscr.stdif.bInterfaceNumber = if_id;
	g_UsbMS.ms_if_info->ifdscr.stdif.bAlternateSetting = 0;
	g_UsbMS.ms_if_info->ifdscr.stdif.bNumEndpoints = USB_MS_EP_NUMBER;
	g_UsbMS.ms_if_info->ifdscr.stdif.bInterfaceClass = USB_MS_INTERFACE_CLASS_CODE;
	g_UsbMS.ms_if_info->ifdscr.stdif.bInterfaceSubClass = USB_MS_INTERFACE_SUBCLASS_CODE;
	g_UsbMS.ms_if_info->ifdscr.stdif.bInterfaceProtocol = USB_MS_INTERFACE_PROTOCOL_CODE;
	g_UsbMS.ms_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbMS.ms_param->interface_string); 

	/* endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_in_id, NULL);
	g_UsbMS.ms_ep_in_info->ep_reset = USB_Ms_BulkIn_Reset;
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_out_id, NULL);
	g_UsbMS.ms_ep_out_info->ep_reset = USB_Ms_BulkOut_Reset;
	/* endpoint descriptor */
	g_UsbMS.ms_ep_in_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbMS.ms_ep_in_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbMS.ms_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_in_id);	/*InPipe*/
	g_UsbMS.ms_ep_in_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef USB_20_ENABLE
	g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
	g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
#endif
	g_UsbMS.ms_ep_in_info->epdesc.stdep.bInterval = 0;
	g_UsbMS.ms_ep_in_info->ep_status.epin_status.byEP = ep_in_id;
	g_UsbMS.ms_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	g_UsbMS.ms_ep_out_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbMS.ms_ep_out_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbMS.ms_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT | ep_out_id);	/*OutPipe*/
	g_UsbMS.ms_ep_out_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef USB_20_ENABLE
	g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
	g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
#endif
	g_UsbMS.ms_ep_out_info->epdesc.stdep.bInterval = 0;
	g_UsbMS.ms_ep_out_info->ep_status.epout_status.byEP = ep_out_id;

	USB_Get_DMA_Channel(ep_in_id, USB_TX_EP_TYPE, KAL_TRUE); /*  in & out eps use the same DMA channel */

	if (g_UsbMS.dma_timeout_handle == 0)
		GPTI_GetHandle(&g_UsbMS.dma_timeout_handle);   /* for DMA time out use!!*/
}


/* interface reset function, enable EP*/
void USB_Ms_If_Reset(void)
{
	ilm_struct *usb_ilm;

	/*this must not exist because use this trivky to avoid reset abnormal operation when writing to flash*/
	g_UsbMS.txpipe = &g_UsbMS.ms_ep_in_info->ep_status.epin_status;
	g_UsbMS.rxpipe = &g_UsbMS.ms_ep_out_info->ep_status.epout_status;

//	USB_Ms_Dbg_Trace(USB_DBG_USBMS_RESET,0);

	 /* configure DMA setting for EP */
	USB_TxEPEn(g_UsbMS.txpipe->byEP, KAL_TRUE);
	USB_RxEPEn(g_UsbMS.rxpipe->byEP, KAL_TRUE);

//	USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_FALSE, USB_CTRL_STALL_ENTRY_2);
//	USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, KAL_FALSE, USB_CTRL_STALL_ENTRY_2);

	/* send reset message to usb task, task handle the ms state machine*/
	if(g_UsbMS.is_send_usb_reset_ilm == KAL_TRUE)
	{
		kal_uint32 	src_mod;

		g_UsbMS.is_send_usb_reset_ilm = KAL_FALSE;
		if(kal_if_hisr() == KAL_TRUE)
			src_mod = MOD_DRV_HISR;
		else
			src_mod = MOD_USB;

	 	DRV_BuildPrimitive(usb_ilm, src_mod, MOD_USB, 
	 				MSG_ID_USB_MSDRV_RESET_IND, NULL);
	 	msg_send_ext_queue(usb_ilm);
	 }
}


/* interface speed reset function, change EP's speed-specific descriptor */
void USB_Ms_If_Speed_Reset(kal_bool b_other_speed)
{
#ifdef USB_20_ENABLE

	if(USB_Is_High_Speed() == KAL_TRUE)
	{
		if(b_other_speed == KAL_FALSE)
		{
			g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
			g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
		}
		else
		{
			g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
		}
	}
	else
	{
		if(b_other_speed == KAL_FALSE)
		{
			g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
		}
		else
		{
			g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
			g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
		}
	}
#endif
}


/************************************************************
	global variable g_UsbMS initialize and release functions
*************************************************************/

/* initialize global variable g_UsbMS */
void USB_Init_Ms_Status(void)
{
	g_UsbMS.nState = USBMS_IDLE;
	g_UsbMS.txpipe = NULL;
	g_UsbMS.rxpipe = NULL;
	g_UsbMS.max_LUN = 0;
	g_UsbMS.current_LUN = 0;
	g_UsbMS.is_send_usb_reset_ilm = KAL_TRUE;
	g_UsbMS.cmd_is_vaild = KAL_TRUE;
	g_UsbMS.CSWDataResidue = 0;
	g_UsbMS.CSWStatusError = 0x00;
	g_UsbMS.sensePtr = NULL;

	/*initialize debug buffer*/
	USB_Ms_Util_Init();
}

/* release global variable g_UsbMS */
void USB_Release_Ms_Status(void)
{
	GPTI_StopItem(g_UsbMS.dma_timeout_handle);
	g_UsbMS.nState = USBMS_IDLE;
	g_UsbMS.txpipe = NULL;
	g_UsbMS.rxpipe = NULL;
	g_UsbMS.max_LUN = 0;
	g_UsbMS.current_LUN = 0;
	g_UsbMS.is_send_usb_reset_ilm = KAL_TRUE;
	g_UsbMS.cmd_is_vaild = KAL_TRUE;
	g_UsbMS.CSWDataResidue = 0;
	g_UsbMS.CSWStatusError = 0x00;
	g_UsbMS.sensePtr = NULL;

	/* release debug buffer */
	USB_Ms_Util_Release();
}


/************************************************************
	Tx/Rx path DMA callback function
*************************************************************/

/* RX DMA callback function*/
static void USB_Ms_Rx_DMA_Callback(void)
{
	if(g_UsbMS.rxpipe->nBuffLen == 31)
	{
		GPTI_StopItem(g_UsbMS.dma_timeout_handle);
	}

	if(gUsbDevice.is_configured_now == KAL_TRUE)
	{
		ilm_struct *usb_ilm;
		usb_ms_rec_done_conf_struct *rec_done_conf;

		//	USB_Ms_Dbg_Trace(USB_DBG_REC_CALLBACK,0);

		g_UsbMS.rxpipe->nBytesRecv = g_UsbMS.rxpipe->nBuffLen;

		/*send message to usb task, let ms state machine handle the received data*/
		rec_done_conf = (usb_ms_rec_done_conf_struct *)construct_local_para(
							sizeof(usb_ms_rec_done_conf_struct), TD_CTRL);
		rec_done_conf->pData = g_UsbMS.rxpipe->pData;
		rec_done_conf->nBuffLen = g_UsbMS.rxpipe->nBuffLen;
		rec_done_conf->nBytesRecv = g_UsbMS.rxpipe->nBuffLen;
		//USB_Ms_Dbg_Trace(USB_DBG_REC_CALLBACK, rec_done_conf->nBytesRecv);

		DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, 
						MOD_USB, MSG_ID_USB_MSDRV_REC_DONE_CONF, rec_done_conf);
	
		msg_send_ext_queue(usb_ilm);
	}
}


/* TX DMA callback function */
static void USB_Ms_Tx_DMA_Callback(void)
{
	if(gUsbDevice.is_configured_now == KAL_TRUE)
	{
		ilm_struct *usb_ilm;

	//	USB_Ms_Dbg_Trace(USB_DBG_TRX_CALLBACK,0);

		g_UsbMS.txpipe->nBytesLeft = USB_EP_NODATA;

		//USB_Ms_Dbg_Trace(USB_DBG_TRX_CALLBACK,0);
		/*send message to usb task, let ms state machine handle the transmitted data*/
		DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,
						MOD_USB, MSG_ID_USB_MSDRV_TRX_DONE_CONF, NULL);

		msg_send_ext_queue(usb_ilm);
	}
}


/************************************************************
	EP0 command parse functions
*************************************************************/

/* reset command handler */
static void USB_Ms_Cmd_Reset(void)
{
	ilm_struct *usb_ilm;
	
	USB_Clear_Tx_EP_FIFO(g_UsbMS.txpipe->byEP);	
	USB_Clear_Rx_EP_FIFO(g_UsbMS.rxpipe->byEP);
		
	/* send reset message to usb task, task handle the state machine*/
	if(g_UsbMS.is_send_usb_reset_ilm == KAL_TRUE)
	 {
	 	/* avoid sending too many messages to task when task is busy writing*/
	 	g_UsbMS.is_send_usb_reset_ilm = KAL_FALSE;
	 	DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,
				MOD_USB, MSG_ID_USB_MSDRV_RESET_IND, NULL);
	 	msg_send_ext_queue(usb_ilm);
	 }
}


/* parse MS class specific command */ 
static void USB_Ms_Ep0_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_uint8  bError = KAL_FALSE;

	switch (pcmd->bRequest) 
	{
	case USB_MS_RESET:
		if( (pcmd->bmRequestType != USB_CMD_CLASSIFOUT) ||(pcmd->wValue != 0) )
		{
			bError = KAL_TRUE;
#ifndef  __PRODUCTION_RELEASE__
			kal_prompt_trace(MOD_USB, "USBMS cmd error %d", pcmd->bRequest);
#endif /* __PRODUCTION_RELEASE__ */
		}
		else
		{
			g_UsbMS.cmd_is_vaild = KAL_TRUE;
			USB_Ms_Cmd_Reset();
			USB_Ms_BulkIn_Reset();
			USB_Ms_BulkOut_Reset();
		}
		break;
	case USB_MS_GETMAXLUN:
		if( (pcmd->bmRequestType != USB_CMD_CLASSIFIN) ||(pcmd->wValue != 0) )
		{
			bError = KAL_TRUE;
#ifndef  __PRODUCTION_RELEASE__
			kal_prompt_trace(MOD_USB, "USBMS cmd error %d", pcmd->bRequest);
#endif /* __PRODUCTION_RELEASE__ */
		}
		else
		{
			g_UsbMS.max_LUN = USB_Ms_Get_Max_LUN();
			USB_Generate_EP0Data(pep0state, pcmd, (void *)&g_UsbMS.max_LUN, 1);
		}
		break;
	default:
		bError = KAL_TRUE;
#ifndef  __PRODUCTION_RELEASE__
		kal_prompt_trace(MOD_USB, "USBMS cmd error %d", pcmd->bRequest);
#endif /* __PRODUCTION_RELEASE__ */
		break;
	}

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


/* bulk In endpoint reset function */
static void USB_Ms_BulkIn_Reset(void)
{
	/* Clear endpoint stall state */
	USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_FALSE, USB_CTRL_STALL_ENTRY_1);
}


/* bulk Out endpoint reset function */
static void USB_Ms_BulkOut_Reset(void)
{
	/* Clear endpoint stall state */
	USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, KAL_FALSE, USB_CTRL_STALL_ENTRY_1);
}

