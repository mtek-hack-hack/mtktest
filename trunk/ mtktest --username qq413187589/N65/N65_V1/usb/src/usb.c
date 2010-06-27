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
 *    usb.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb1.1 driver
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
#include "drv_comm.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "reg_base.h"
#include "drvsignals.h"
  
#include "app_buff_alloc.h"
#include "drvpdn.h"
#include "intrCtrl.h"
#include "gpio_sw.h"

#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usb_resource.h"
#include "usbms_drv.h"
#include "usbacm_drv.h"
#include "usbvideo_drv.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"

#include "fs_type.h"
#include "fs_func.h"

#ifdef __OTG_ENABLE__
#include "otg_drv.h"
#endif

#ifdef PICTBRIDGE_SUPPORT
#include "usbimage_drv.h"
#include "ptp_state.h"
#endif

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#include "fctycomp_config.h"
#endif /* __MULTI_BOOT__ */

/* Device structure, handle usb level data */
Usb_Device gUsbDevice;

#ifndef  __PRODUCTION_RELEASE__	
kal_uint32    g_usb_reset_times; /*  for debug information */
#endif

/* static fuctions */
static void USB_Clear_All_EP_Data_Tog(void);
static void USB_Reset(void);
static void USB_Disable_Charging(void);
static void USB_Suspend(void);
static void USB_Resume(void);
static void USB_Initialize(void);
static kal_bool USB_Cmd_SetAddress(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_GetDescriptor(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_SetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_GetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_SetFeature(Usb_Command *pcmd, kal_bool bset);
static kal_bool USB_Cmd_GetStatus(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Stdcmd(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Endpoint0_Idle (void);
static void USB_Endpoint0_Rx(void);
static void USB_Endpoint0_Tx(void);
static void USB_Endpoint0_Hdlr(void);


/************************************************************
	gUsbDevice initialize and release functions
*************************************************************/

/* initialize the  global variable gUsbDevice */
void USB_Init_Device_Status(void)
{
	kal_uint8 index = 0;

	kal_mem_set(&gUsbDevice.cfgdscr, 0, sizeof(Usb_Cfg_Dscr));
 
	for( index = 0; index < USB_MAX_INTERFACE; index++)
	{
		kal_mem_set(&gUsbDevice.if_info[index], 0, sizeof(Usb_Interface_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_TX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulk_tx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_RX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulk_rx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_INTR_TX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_intr_tx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_STRING; index++)
	{
		gUsbDevice.resource_string[index] = NULL;
	}

#ifdef USB_20_ENABLE	
	gUsbDevice.usb_enter_test_mode = KAL_FALSE;
#endif
	gUsbDevice.conf = NULL;
	gUsbDevice.device_type = USB_UNKOWN;
	gUsbDevice.nDevState = DEVSTATE_DEFAULT;
	gUsbDevice.remoteWk = KAL_FALSE;
	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.config_num = 0;
	gUsbDevice.interface_num = 0;
	gUsbDevice.ep0_rx_handler = NULL;
	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_FALSE;

   	gUsbDevice.resource_ep_bulk_tx_number = 0;
   	gUsbDevice.resource_ep_bulk_rx_number = 0;
   	gUsbDevice.resource_ep_intr_tx_number = 0;
   	gUsbDevice.resource_interface_number = 0;
   	gUsbDevice.resource_string_number = 0; 
}


/* release the already get memory, and reset some parameter,
    note that hisr should not be reset to NULL since it may already be created*/
void USB_Release_Device_Status(void)
{
	kal_uint8 index = 0;

	kal_mem_set(&gUsbDevice.cfgdscr, 0, sizeof(Usb_Cfg_Dscr));
	
	for( index = 0; index < USB_MAX_INTERFACE; index++)
	{
		kal_mem_set(&gUsbDevice.if_info[index], 0, sizeof(Usb_Interface_Info));
	}
	
	for( index = 0; index < USB_MAX_EP_BULK_TX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulk_tx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_RX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulk_rx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_INTR_TX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_intr_tx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_STRING; index++)
	{
		gUsbDevice.resource_string[index] = NULL;
	}

	if(gUsbDevice.conf != NULL)
		free_ctrl_buffer(gUsbDevice.conf);
	gUsbDevice.conf = NULL;
#ifdef USB_20_ENABLE	
	gUsbDevice.usb_enter_test_mode = KAL_FALSE;	
#endif
	gUsbDevice.nDevState = DEVSTATE_DEFAULT;
	gUsbDevice.remoteWk = KAL_FALSE;
	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.config_num = 0;
	gUsbDevice.interface_num = 0;
	gUsbDevice.device_type = USB_UNKOWN;
	gUsbDevice.ep0_rx_handler = NULL;
	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_FALSE;

	gUsbDevice.resource_ep_bulk_tx_number = 0;		
   	gUsbDevice.resource_ep_bulk_rx_number = 0;		
   	gUsbDevice.resource_ep_intr_tx_number = 0;
   	gUsbDevice.resource_interface_number = 0;
   	gUsbDevice.resource_string_number = 0; 
}



/************************************************************
	EP0 functions
*************************************************************/

/* register EP0 rx OUT token data handler */
void USB_Register_EP0_RxHdlr(usb_ep0_rx_ptr handler)
{
	gUsbDevice.ep0_rx_handler = handler;
}

void USB_Register_EP0_Class_CmdHdlr(kal_uint8 cmd, usb_ep0_cmd_ptr handler)
{
	gUsbDevice.ep0_class_cmd_handler.cmd = cmd;
	gUsbDevice.ep0_class_cmd_handler.ep0_cmd_hdlr = handler;
	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_TRUE;
}

/* prepare TX data infomration for pep0state, data is actually sent out in TX state handler */
void USB_Generate_EP0Data(Usb_Ep0_Status*pep0state, Usb_Command*pcmd, void *data, kal_int32 len)
{
	pep0state->nBytesLeft = len;
	pep0state->pData = (void*)data;
	/* only transmit at most command request */
	if (pcmd->wLength < pep0state->nBytesLeft)
		pep0state->nBytesLeft = pcmd->wLength;
	/* EP0 go to TX state */
	gUsbDevice.ep0_state = USB_EP0_TX;
}

/************************************************************
	system ctrl functions
*************************************************************/

/* init function, called when user select usb type, 
    entry function for task , B_eanble is D+ detection enable */
void USB_Init(USB_DEVICE_TYPE type, kal_bool b_enable)
{
#ifndef __USB_ENABLE__
	EXT_ASSERT(0, 0, 0, 0);
#endif
	
#if defined(DRV_USB_MCU_52M)
	#ifndef MCU_52M
		EXT_ASSERT(0, 0, 0, 0);  /* Must 52M */
	#endif   /* MCU_52M */
#endif 	/* MT6218||MT6218B||MT6219 */

	USB_Init_Drv_Info();			/*initialize driver parameters*/
	USB_Init_Device_Status();	/*initialize global variable gUsbDevice*/
	if(type == USB_MASS_STORAGE)
	{
		USB_Init_Ms_Status();
	}
	else if(type == USB_CDC_ACM)
	{
		USB_Init_Acm_Status();
	}
#ifdef WEBCAM_SUPPORT	
	else if(type == USB_VIDEO)
	{
		USB_Init_Video_Status();	
	}
#endif	
#ifdef PICTBRIDGE_SUPPORT
	else if(type == USB_IMAGE)
	{
		USB_Init_Image_Status();	
	}
#endif
	else if(type == USB_COMPOSITE)
	{
		USB_Init_Ms_Status();
		USB_Init_Acm_Status();
	}
	else
	{
		EXT_ASSERT(0, type, 0, 0);	
	}
	gUsbDevice.device_type = type;
			
	/* register reset and ep0 interrupt handler to driver info*/
	USB_Register_Drv_Info(USB_DRV_HDLR_RESET, 0, USB_Reset);
	USB_Register_Drv_Info(USB_DRV_HDLR_EP0, 0, USB_Endpoint0_Hdlr);
	USB_Register_Drv_Info(USB_DRV_HDLR_SUSPEND, 0, USB_Suspend);
	USB_Register_Drv_Info(USB_DRV_HDLR_RESUME, 0, USB_Resume);


	/* create descriptors */
	USB_Software_Create();

#ifdef __USB_RAMDISK__
	if (type != USB_CDC_ACM)
	{
		FAT_Init();
	}
#endif   /*__USB_RAMDISK__*/

	if(b_enable == KAL_TRUE)
	{
		/* enable USB power, host can detect USB device*/
		USB_PDNmode(KAL_FALSE);
	}

	/* reset and initialize system initial value and registers*/
	USB_Reset_Drv();  /* reset hw power register */
	USB_Initialize_Drv();

	/* initailize according to application*/
	USB_Initialize();

/* if __OTG_ENABLE__, only activate OTG ISR*/
#ifdef __OTG_ENABLE__
	OTG_Drv_Activate_ISR();

	if(b_enable == KAL_TRUE)
		OTG_Enable_Device();
#else
	/* LISR should be unmask after all initialize and enable any USB interrupt */
	USB_Drv_Activate_ISR();
#endif	/* __OTG_ENABLE__ */

#if defined(DRV_USB_IP_V3)
	USBDMA_Drv_Activate_ISR();
#endif
}

void USB_Release(void)
{
	USB_Release_Drv();
}

static void USB_Clear_All_EP_Data_Tog(void)
{
	kal_uint32  index;


	for(index = 1; index <= gUsbDevice.resource_ep_bulk_tx_number; index++)
		USB_TxEPClearDataTog(index);

	for(index = 1; index <= gUsbDevice.resource_ep_bulk_rx_number; index++)
		USB_RxEPClearDataTog(index);

	if(gUsbDevice.resource_ep_intr_tx_number != 0)
		USB_TxEPClearDataTog(3);
}


/* Reset device, called when receive reset interrupt */
static void USB_Reset(void)
{
	kal_uint8 ep_num;

	gUsbDevice.is_configured_now = KAL_FALSE;
	USB_Disable_Charging();

#ifndef  __PRODUCTION_RELEASE__	
	g_usb_reset_times++;
	kal_prompt_trace(MOD_USB, "USB reset %d", g_usb_reset_times);
	USB_Dbg_Trace(USB_RESET, drv_get_current_time(), g_usb_reset_times, 0);
#endif /* __PRODUCTION_RELEASE__ */

	// initialize driver info and system interrupt
	USB_ResetDrv_Info();
	USB_Initialize_Drv();
	USB_Initialize();        /* call class reset function */

	for(ep_num = 0; ep_num < gUsbDevice.resource_ep_bulk_tx_number; ep_num++)
	{
		if(gUsbDevice.ep_bulk_tx_info[ep_num].ep_reset)
			gUsbDevice.ep_bulk_tx_info[ep_num].ep_reset();
	}

	for(ep_num = 0; ep_num < gUsbDevice.resource_ep_bulk_rx_number; ep_num++)
	{
		if(gUsbDevice.ep_bulk_rx_info[ep_num].ep_reset)
			gUsbDevice.ep_bulk_rx_info[ep_num].ep_reset();
	}

	for(ep_num = 0; ep_num < gUsbDevice.resource_ep_intr_tx_number; ep_num++)
	{
		if(gUsbDevice.ep_intr_tx_info[ep_num].ep_reset)
			gUsbDevice.ep_intr_tx_info[ep_num].ep_reset();
	}

#ifdef __OTG_ENABLE__
	OTG_B_EnDis_HNP(KAL_FALSE);
#endif	
}

static void USB_Disable_Charging(void)
{
	ilm_struct *ilm_charge;
	bmt_usb_ind_struct *ind;


	if((gUsbDevice.config_num != 0)&&(INT_BootMode() != MTK_FACTORY_MODE))
	{
		ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);
#ifdef __USB_MULTI_CHARGE_CURRENT__
		ind->usb_ind = (kal_uint8) (USB_DEVDSC_CONFIGS); /* usb not charging */
#else
		ind->usb_ind = (BMT_USB_100);
#endif
		DRV_BuildPrimitive(ilm_charge, MOD_DRV_HISR, MOD_BMT, MSG_ID_BMT_USB_IND, ind);
		msg_send_ext_queue(ilm_charge);
	}
}

static void USB_Suspend(void)
{
	USB_Disable_Charging();

#ifdef PICTBRIDGE_SUPPORT
	if(gUsbDevice.device_type == USB_IMAGE)
	{
		USB_Image_Suspend_Hdlr();
	}
#endif

#ifndef  __PRODUCTION_RELEASE__
	USB_Dbg_Trace(USB_SUSPEND, drv_get_current_time(), 0, 0);
	kal_prompt_trace(MOD_USB, "USB suspend");
#endif
}


static void USB_Resume(void)
{
	ilm_struct *ilm_charge;
	bmt_usb_ind_struct *ind;


	if((gUsbDevice.config_num != 0)&&(INT_BootMode() != MTK_FACTORY_MODE))
	{
		ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);
#ifdef __USB_MULTI_CHARGE_CURRENT__
		ind->usb_ind = gUsbDevice.config_num-1;
#else
		ind->usb_ind = BMT_USB_500;	   			   
#endif
		DRV_BuildPrimitive(ilm_charge, MOD_DRV_HISR, MOD_BMT, MSG_ID_BMT_USB_IND, ind);
		msg_send_ext_queue(ilm_charge);      	
	}

#ifndef  __PRODUCTION_RELEASE__
	USB_Dbg_Trace(USB_RESUME, drv_get_current_time(), 0, 0);
	kal_prompt_trace(MOD_USB, "USB resume");
#endif
}


/* initialize system */
static void USB_Initialize(void)
{
	kal_uint32 index_ep;
	kal_uint16 wMaxPacketSize;


	gUsbDevice.nDevState = DEVSTATE_DEFAULT;
#ifdef USB_20_ENABLE	
	/* initial class specific speed-related endpoint, and re-prepare descriptor */
	USB_Software_Speed_Init(KAL_FALSE);
#endif

#if defined(DRV_USB_IP_V3)
	USB_Reset_FIFO();
#endif

#ifdef  __USB_EP_TEST__

	for(index_ep = 1; index_ep < gUsbDevice.resource_ep_bulk_tx_number; index_ep++)
	{
		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
		wMaxPacketSize <<= 8;
		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];
		
		USB_TxEPInit((gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)), 
						wMaxPacketSize, USB_ENDPT_BULK);
		gUsbDevice.ep_bulk_tx_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}

	for(index_ep = 1; index_ep < gUsbDevice.resource_ep_bulk_rx_number; index_ep++)
	{
		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
		wMaxPacketSize <<= 8;
		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];
			
		USB_RxEPInit((gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)), 
						wMaxPacketSize, USB_ENDPT_BULK);
		gUsbDevice.ep_bulk_rx_info[index_ep].ep_status.epout_status.nBuffLen = 0;
		gUsbDevice.ep_bulk_rx_info[index_ep].ep_status.epout_status.nBytesRecv = 0;
	}
#else /* __USB_EP_TEST__ */

	for(index_ep = 0; index_ep < gUsbDevice.resource_ep_bulk_tx_number; index_ep++)
	{
		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
		wMaxPacketSize <<= 8;
		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];
		
		USB_TxEPInit((gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)), 
						wMaxPacketSize, USB_ENDPT_BULK);
		gUsbDevice.ep_bulk_tx_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}

	for(index_ep = 0; index_ep < gUsbDevice.resource_ep_bulk_rx_number; index_ep++)
	{
		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
		wMaxPacketSize <<= 8;
		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];
			
		USB_RxEPInit((gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)), 
						wMaxPacketSize, USB_ENDPT_BULK);
		gUsbDevice.ep_bulk_rx_info[index_ep].ep_status.epout_status.nBuffLen = 0;
		gUsbDevice.ep_bulk_rx_info[index_ep].ep_status.epout_status.nBytesRecv = 0;
	}
#endif /* __USB_EP_TEST__ */

	for(index_ep = 0; index_ep < gUsbDevice.resource_ep_intr_tx_number; index_ep++)
	{
		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_intr_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
		wMaxPacketSize <<= 8;
		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_intr_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];
			
		USB_TxEPInit((gUsbDevice.ep_intr_tx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)), 
						wMaxPacketSize, USB_ENDPT_INTR);
		gUsbDevice.ep_intr_tx_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}

	/* Clear current configuration pointer */
	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.remoteWk = KAL_FALSE;
	gUsbDevice.config_num = 0;        /*  set configuration command value  */
	gUsbDevice.interface_num = 0;    /*  set inferface command value  */
	gUsbDevice.ep0_state = USB_EP0_IDLE;
	gUsbDevice.ep0info.byFAddr = 0xff;   /*  device (function) address, no use, at HW still set 0x00 */

	/* initial class specific interface functions*/
	USB_Software_Init();
}

/************************************************************
	EP0 functions
*************************************************************/

/* parse command Set Address */
static kal_bool USB_Cmd_SetAddress(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;

	/* Store device function address until status stage of request */
	if (pcmd->bmRequestType != USB_CMD_STDDEVOUT)
	{
		bError = KAL_TRUE;
	}
	else
	{
		if (gUsbDevice.nDevState <= DEVSTATE_ADDRESS)
		{
			pep0state->byFAddr = (kal_uint8)pcmd->wValue;
			if ((gUsbDevice.nDevState == DEVSTATE_DEFAULT) && (pep0state->byFAddr<=127))
			{
				gUsbDevice.nDevState = DEVSTATE_SET_ADDRESS;
				USB_SetAddress(pep0state->byFAddr, USB_SET_ADDR_DATA);
			}
			else
			{
				gUsbDevice.nDevState = DEVSTATE_DEFAULT;
			}
		}
		else
		{
			bError = KAL_TRUE;
		}	
	}
	return bError;
}

/* parse command Get Descriptor */
static kal_bool USB_Cmd_GetDescriptor(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	kal_uint8 byConfig;
	kal_uint8 bystr;
	Usb_Cfg_Dscr *pcfg;


	/* Decode the required descriptor from the command */
	if (pcmd->bmRequestType != USB_CMD_STDDEVIN)
	{
		bError = KAL_TRUE;
	}
	else 
	{
		switch (pcmd->wValue & USB_CMD_DESCMASK) 
		{
		case USB_CMD_DEVICE:
			/* First get device descriptor will only get 8 bytes */
			if(pcmd->wLength == 64)
				gUsbDevice.ep0_send_one_pkt = KAL_TRUE;
			else
				gUsbDevice.ep0_send_one_pkt = KAL_FALSE;
			/* Prepare to return Standard Device Descriptor */
			USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.devdscr, sizeof(Usb_Dev_Dscr));
			break;
		case USB_CMD_CONFIG:
	#ifdef USB_20_ENABLE	
			USB_Software_Speed_Init(KAL_FALSE);
	#endif
			byConfig = (kal_uint8)(pcmd->wValue & 0x00FF);
			if (byConfig >= gUsbDevice.devdscr.bNumConfigurations)
			{
				bError = KAL_TRUE;
			}
			else 
			{
				/* Get pointer to request configuration descriptor */
				pcfg = (Usb_Cfg_Dscr*)gUsbDevice.conf;
				
	#ifdef  __USB_MULTI_CHARGE_CURRENT__
		#if (defined(MT6305)||defined(MT6318)||defined(MT6238PMU))
				/*  memory copy to modify descriptor */
//				kal_mem_cpy((kal_uint8*) &(pcfg->bConfigurationValue), 
//							(kal_uint8*) &gUsbDevice.multi_configuration_value[byConfig], 1);
				kal_mem_cpy((kal_uint8*) &(pcfg->bMaxPower), 
							(kal_uint8*) &gUsbDevice.multi_Max_Power[byConfig], 1);
  
				if(byConfig == (USB_DEVDSC_CONFIGS-1))
				{
					/* return self power */
					kal_mem_set((kal_uint8*) &(pcfg->bmAttributes), (USB_CFGDSC_ATTR_SELFPOWER|USB_CFGDSC_ATTR_NATURE), 1);
				}
				else
				{
					/* return bus power */
					kal_mem_set((kal_uint8*) &(pcfg->bmAttributes), USB_CFGDSC_ATTR_NATURE, 1);
				}
		#endif
	#endif

				if(pcmd->wLength == 8)
					gUsbDevice.ep0_send_one_pkt = KAL_TRUE;
				else
					gUsbDevice.ep0_send_one_pkt = KAL_FALSE;

				/* Prepare to return Configuration Descriptors */
				USB_Generate_EP0Data(pep0state, pcmd, pcfg, pcfg->wTotalLength);
			}
			break;    
		case USB_CMD_STRING:
			bystr = (kal_uint8)(pcmd->wValue & 0x00FF);
			if (bystr >= gUsbDevice.resource_string_number)
			{
				bError = KAL_TRUE;
			}
			else
			{
				/* Get pointer to requested string descriptor */
				USB_Generate_EP0Data(pep0state, pcmd, (void *)gUsbDevice.resource_string[bystr], 
							(*(kal_uint8 *)gUsbDevice.resource_string[bystr]));
			}
			break;
	#ifdef USB_20_ENABLE
		case USB_CMD_DEVICE_QUALIFIER:
			/* Prepare to return Standard Device_Qualifier Descriptor */
			USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.dev_qual_dscr, sizeof(Usb_Dev_Qual_Dscr));
			break;
		case USB_CMD_OTHER_SPEED:
			USB_Software_Speed_Init(KAL_TRUE);
			byConfig = (kal_uint8)(pcmd->wValue & 0x00FF);
			if (byConfig >= gUsbDevice.devdscr.bNumConfigurations)
			{
				bError = KAL_TRUE;
			}
			else
			{
				/* Get pointer to requested configuration descriptor */
				pcfg = (Usb_Cfg_Dscr*)gUsbDevice.conf;

		#ifdef  __USB_MULTI_CHARGE_CURRENT__
			#if ( defined(MT6305) || defined(MT6318) )
				/*  memory copy to modify descriptor */ 
			      kal_mem_cpy( (kal_uint8*) &(pcfg->bConfigurationValue), 
							(kal_uint8*) &gUsbDevice.multi_configuration_value[byConfig], 1);
  		  	      kal_mem_cpy( (kal_uint8*) &(pcfg->bMaxPower), 
							(kal_uint8*) &gUsbDevice.multi_Max_Power[byConfig], 1);
			#endif
		#endif
				/* Prepare to return Configuration Descriptors */
				USB_Generate_EP0Data(pep0state, pcmd, pcfg, pcfg->wTotalLength);
			}
			break;
	#endif
		default: 
			bError = KAL_TRUE;
			break;
		}
	}

	return bError;
}


/* Parse command Set Configuration */
static kal_bool USB_Cmd_SetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	kal_uint8 byConfig;
	ilm_struct *ilm;

	/* add for usb charging */
	ilm_struct *ilm_charge;				
	bmt_usb_ind_struct *ind;
	/* uart plug in ind*/
	uart_plugin_ind_struct *ilm_uart_plug_in;

	
//	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.is_configured_now = KAL_FALSE;
	
	byConfig = (kal_uint8)(pcmd->wValue & 0x00FF);

	USB_Dbg_Trace(USB_EP0_SET_CONFIGURATION, drv_get_current_time(), 0, byConfig);

	if (gUsbDevice.nDevState == DEVSTATE_DEFAULT)
	{
		bError = KAL_TRUE;
	}	
	/* Assumes configurations are numbered from 1 to NumConfigurations */
	else 
	{
		if (byConfig > gUsbDevice.devdscr.bNumConfigurations)
		{
			bError = KAL_TRUE;
		}
		else if (byConfig == 0)
		{
			USB_Disable_Charging();
			gUsbDevice.nDevState = DEVSTATE_ADDRESS;
			gUsbDevice.config_num = 0;
		}
		else 
		{
#ifndef  __PRODUCTION_RELEASE__	
			kal_prompt_trace(MOD_USB, "USB config\n");
#endif /* __PRODUCTION_RELEASE__ */		
			USB_Clear_All_EP_Data_Tog();
			gUsbDevice.nDevState = DEVSTATE_CONFIG;		
			gUsbDevice.is_configured_now = KAL_TRUE;
			gUsbDevice.config_num = byConfig;	
#ifdef  __USB_MULTI_CHARGE_CURRENT__
			if(byConfig == USB_DEVDSC_CONFIGS)
			{
				gUsbDevice.self_powered = KAL_TRUE;
			}
			else
			{
				gUsbDevice.self_powered = KAL_FALSE;
			}
#endif
		}
	}

	if (INT_BootMode() != MTK_FACTORY_MODE)	
	{
		/* add for usb charging	*/						  	
		ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);
#ifdef __USB_MULTI_CHARGE_CURRENT__
		ind->usb_ind = (byConfig != 0)?(byConfig-1):(USB_DEVDSC_CONFIGS);
#else
		ind->usb_ind = (byConfig != 0)?(BMT_USB_500):(BMT_USB_100);
#endif
		DRV_BuildPrimitive( ilm_charge, MOD_DRV_HISR, MOD_BMT, MSG_ID_BMT_USB_IND, ind);
		msg_send_ext_queue(ilm_charge);      			      		      	
	}
	else
	{
		/* meta mode, notify ft task */			   			   
		DRV_BuildPrimitive(ilm, MOD_DRV_HISR, MOD_FT, MSG_ID_USB_FT_IND, NULL);
		msg_send_ext_queue(ilm);     
	}

	/* notify UART owner that virtual UART is plug in*/
	if((gUsbDevice.nDevState == DEVSTATE_CONFIG) && (gUsbDevice.device_type == USB_CDC_ACM))
	{
	#ifdef __DSPIRDBG__
		if(g_UsbACM.acm_owner == USB_ACM_OWNER_DSP)
		{
			/* notify usb task to start IRDBG*/			   			   
			DRV_BuildPrimitive(ilm, MOD_DRV_HISR, MOD_USB, MSG_ID_USB_IRDGB_START_IND, NULL);
			msg_send_ext_queue(ilm);    
		}
		else 
	#endif /* __DSPIRDBG__ */
		{
			if(USB2UARTPort.ownerid != MOD_DRV_HISR)
			{	
				ilm_uart_plug_in = (uart_plugin_ind_struct*)construct_local_para(sizeof(uart_plugin_ind_struct), TD_CTRL);
				ilm_uart_plug_in->port = USB2UARTPort.port_no;
				DRV_BuildPrimitive(ilm,
						MOD_DRV_HISR,
						USB2UARTPort.ownerid,
						MSG_ID_UART_PLUGIN_IND,
						ilm_uart_plug_in);
				msg_send_ext_queue(ilm);
				g_UsbACM.send_UARTilm = KAL_TRUE;
	
				if (g_UsbACM.config_send_Txilm == KAL_TRUE )
				{
					g_UsbACM.send_Txilm = KAL_TRUE;
					/* if someone PutBytes once, then issue ready-to-write message */
					if(USB2UARTPort.tx_cb!=NULL)
						USB2UARTPort.tx_cb(uart_port_usb);
				}
				else
				{
					g_UsbACM.send_Txilm = KAL_FALSE;
				}
			}
		}	
	}	
	return bError;
}


/* parse command Get Configuration */
static kal_bool USB_Cmd_GetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	
#ifdef __OTG_ENABLE__
	/* Prepare to return configuration value */
	USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.config_num, 1);	
#else
//	Usb_Cfg_Dscr *pcfg;

	if( (gUsbDevice.nDevState == DEVSTATE_ADDRESS) && (!pcmd->wValue))
	{
		/* Prepare to return zero */
		USB_Generate_EP0Data(pep0state, pcmd, &pcmd->wValue, 1);
	}
	else if( gUsbDevice.nDevState == DEVSTATE_CONFIG) 
	{
		/* Prepare to return configuration value */
		//pcfg = (Usb_Cfg_Dscr *)gUsbDevice.pCurCfg;
		//USB_Generate_EP0Data(pep0state, pcmd, &pcfg->bConfigurationValue, 1);
		USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.config_num, 1);
	}
	else
	{
		bError = KAL_TRUE;
	}
#endif
	return bError;
}

/* parse command Set Interface */
static kal_bool USB_Cmd_SetInterface(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	
	gUsbDevice.interface_num = pcmd->wValue & 0x00FF;
	
	return bError;
}

/* parse command Get Interface */
static kal_bool USB_Cmd_GetInterface(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	
	USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.interface_num, 1);
	
	return bError;
}


/* parse command Set/Clear Feature */
/* bset  true means command SET_FETURE, false means command CLEAR_FEATURE */
static kal_bool USB_Cmd_SetFeature(Usb_Command *pcmd, kal_bool bset)
{
	kal_bool bError = KAL_FALSE;
	ilm_struct *usb_ilm;
	
	switch (pcmd->bmRequestType) 
	{
	/* device */
	case USB_CMD_STDDEVOUT:
		switch (pcmd->wValue) 
		{
		case USB_FTR_DEVREMWAKE:
			gUsbDevice.remoteWk = bset;
			break;
#ifdef USB_20_ENABLE
		case USB_FTR_TEST_MODE:
			gUsbDevice.usb_enter_test_mode = KAL_TRUE;
			switch ((pcmd->wIndex)>>8)
			{
			case USB_TEST_J:
				gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_J;
				break;
			case USB_TEST_K:
				gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_K;
				break;
			case USB_TEST_SE0_NAK:
				gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_SE0_NAK;
				break;
			case USB_TEST_PACKET:
				gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_PACKET;
				break;
			default:
				bError = KAL_TRUE;
				break;
			}
			break;
#endif

#ifdef __OTG_ENABLE__
	case USB_FTR_B_HNP_ENB:	
			OTG_B_EnDis_HNP(KAL_TRUE);
			break;
	case USB_FTR_A_HNP_SUPPORT:	
	case USB_FTR_A_ALT_HNP_SUPPORT:	
			break;
#endif
		default:
			bError = KAL_TRUE;
			break;
		}
		break;
	/* endpoint */	
	case USB_CMD_STDEPOUT:
		switch (pcmd->wValue) 
		{
		case USB_FTR_EPHALT:
			if (pcmd->wIndex == 0)
			{
				/* endpoint 0 */
			}
			else
			{
				/* command EP direction zero indicate OUT EP */
				if(pcmd->wIndex&0x80)
				{
					/* In EP*/
					if((pcmd->wIndex&0x0f) > MAX_INTR_EP_NUM)
					{
		#ifdef  __PRODUCTION_RELEASE__
						bError = KAL_TRUE;
		#else
						EXT_ASSERT(0, (pcmd->wIndex& 0x0f), gUsbDevice.resource_ep_bulk_tx_number, 0)	
		#endif
					}
					else
					{
						if((gUsbDevice.device_type == USB_MASS_STORAGE)&&(bset == KAL_FALSE)&&(g_UsbMS.cmd_is_vaild == KAL_FALSE))
						{
							/* Ignore this cmd, and still return stall */
						}
						else
						{
							if((gUsbDevice.device_type == USB_MASS_STORAGE)&&(bset == KAL_FALSE)&&
								(USB_Get_EP_Stall_Status(pcmd->wIndex&0x0f, USB_TX_EP_TYPE) == KAL_TRUE))
							{
								DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB, MSG_ID_USB_MSDRV_CLEAR_STALL_REQ, NULL);
								msg_send_ext_queue(usb_ilm);
							}
							USB_CtrlEPStall((pcmd->wIndex& 0x0f), USB_TX_EP_TYPE, bset, USB_CTRL_STALL_ENTRY_1);
						}
					}
				}
				else
				{
					/* Out EP*/
					if((pcmd->wIndex&0x0f) > MAX_INTR_EP_NUM)
					{
		#ifdef  __PRODUCTION_RELEASE__	
						bError = KAL_TRUE;
		#else
						EXT_ASSERT(0, (pcmd->wIndex&0x0f), gUsbDevice.resource_ep_bulk_rx_number, 0)	
		#endif
					}
					else
					{
						if((gUsbDevice.device_type == USB_MASS_STORAGE)&&(bset == KAL_FALSE)&&(g_UsbMS.cmd_is_vaild == KAL_FALSE))
						{
							/* Ignore this cmd, and still return stall */
						}
						else
						{
							if((gUsbDevice.device_type == USB_MASS_STORAGE)&&(bset == KAL_FALSE)&&
										(USB_Get_EP_Stall_Status(pcmd->wIndex&0x0f, USB_RX_EP_TYPE) == KAL_TRUE))
							{
								DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB, MSG_ID_USB_MSDRV_CLEAR_STALL_REQ, NULL);
								msg_send_ext_queue(usb_ilm);
							}
							USB_CtrlEPStall((pcmd->wIndex& 0x0f), USB_RX_EP_TYPE, bset, USB_CTRL_STALL_ENTRY_1);
						}
					}
				}
			}
			break;
		default:
			bError = KAL_TRUE;
			break;
		}
		break;
	case USB_CMD_STDIFOUT:
	default:
		bError = KAL_TRUE;
		break;
	}

	return bError;
}

/* parse command Get Status */
static kal_bool USB_Cmd_GetStatus(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	static kal_uint16 status = 0;
	switch (pcmd->bmRequestType) 
	{
	case USB_CMD_STDDEVIN:
		status = (kal_uint16)((gUsbDevice.remoteWk<<1)|(gUsbDevice.self_powered));
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break;
	case USB_CMD_STDIFIN:
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break; 
	case USB_CMD_STDEPIN:
		if(pcmd->wIndex & 0x80)
		{
			/* In EP*/
			status = (kal_uint16)USB_Get_EP_Stall_Status((pcmd->wIndex & 0x000f), USB_TX_EP_TYPE);
		}
		else
		{
			/* Out EP*/
			status = (kal_uint16)USB_Get_EP_Stall_Status((pcmd->wIndex & 0x000f), USB_RX_EP_TYPE);
		}
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break;
	default:
		bError = KAL_TRUE;
		break;
	}

	return bError;
}

/* parse usb standard command */
static void USB_Stdcmd(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool   bError = KAL_FALSE;

	switch (pcmd->bRequest) 
	{
	case USB_SET_ADDRESS:
		bError = USB_Cmd_SetAddress(pep0state, pcmd);
		break;
	case USB_GET_DESCRIPTOR:
		bError = USB_Cmd_GetDescriptor(pep0state, pcmd);
		break;
	case USB_SET_CONFIGURATION:
		bError = USB_Cmd_SetConfiguration(pep0state, pcmd);
		break;
	case USB_SET_INTERFACE:
		bError = USB_Cmd_SetInterface(pep0state, pcmd);
		break;
	case USB_GET_CONFIGURATION:
		bError = USB_Cmd_GetConfiguration(pep0state, pcmd);
		break;
	case USB_GET_INTERFACE:
		bError = USB_Cmd_GetInterface(pep0state, pcmd);
		break;
	case USB_SET_FEATURE:
		bError = USB_Cmd_SetFeature(pcmd, KAL_TRUE);
		break;
	case USB_CLEAR_FEATURE:
		bError = USB_Cmd_SetFeature(pcmd, KAL_FALSE);
		break;
	case USB_GET_STATUS:
		bError = USB_Cmd_GetStatus(pep0state, pcmd);
		break;
	/* Stall the command if an unrecognized request is received */	
	case USB_SYNCH_FRAME:   /*Only support for Isoc traffic*/
	case USB_SET_DESCRIPTOR:
	default:
		bError = KAL_TRUE;
//		ASSERT(0);
		break;
	}


	if (gUsbDevice.ep0_state == USB_EP0_IDLE)	/* no data to transmit */
	{
		gUsbDevice.ep0_state = USB_EP0_RX_STATUS;
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);

	#ifdef USB_20_ENABLE
		if((gUsbDevice.usb_test_type == USB_TEST_MODE_TYPE_PACKET)&&(gUsbDevice.usb_enter_test_mode == KAL_TRUE))
		{
			kal_uint8 packet_test[] = {
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
					0xAA, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 
					0xEE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
					0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xBF, 0xDF,
					0xEF, 0xF7, 0xFB, 0xFD, 0xFC, 0x7E, 0xBF, 0xDF,
					0xEF, 0xF7, 0xFB, 0xFD, 0x7E};
			USB_EPFIFOWrite (0, 53, packet_test);

			USB_Update_EP0_State(USB_EP0_DRV_STATE_WRITE_RDY, KAL_FALSE, KAL_FALSE);
		}
	#endif

		if((gUsbDevice.ep0_class_cmd_handler.b_enable == KAL_TRUE) &&
			(gUsbDevice.ep0_class_cmd_handler.cmd == pcmd->bRequest) ) 
		{
			/* Besides standard cmd, still need to do extra this, like webcam halt feature*/
			gUsbDevice.ep0_class_cmd_handler.ep0_cmd_hdlr(pcmd);
		}	
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
}


/* parse EP0 requested command */
static void USB_Endpoint0_Idle (void)
{
	/* read ep0 data*/
	USB_EPFIFORead(0, 8, &gUsbDevice.cmd);
	
	/* Check request type */
	switch (gUsbDevice.cmd.bmRequestType & USB_CMD_TYPEMASK) 
	{
	case USB_CMD_STDREQ:
		/* standard request */
		USB_Stdcmd(&gUsbDevice.ep0info, &gUsbDevice.cmd);
		break;
	case USB_CMD_CLASSREQ:
		/* class specific request */
		if((gUsbDevice.cmd.bmRequestType == USB_CMD_CLASSIFIN) || (gUsbDevice.cmd.bmRequestType == USB_CMD_CLASSIFOUT))
		{
			if(gUsbDevice.if_info[(gUsbDevice.cmd.wIndex & 0xff)].if_class_specific_hdlr != NULL)
			{
				gUsbDevice.if_info[(gUsbDevice.cmd.wIndex & 0xff)].if_class_specific_hdlr(&gUsbDevice.ep0info, &gUsbDevice.cmd);
			}
			else
			{
				/* error occur, stall endpoint*/
				USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
			}
		}
		else
		{
		#ifndef  __PRODUCTION_RELEASE__	
			/* not support now*/
			EXT_ASSERT(0, gUsbDevice.cmd.bmRequestType, 0, 0);
		#endif
			/* error occur, stall endpoint*/
			USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
		}
		break;
	case USB_CMD_VENDREQ:
	default:
		/* Stall the command if a reserved request is received */
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
		break;
	}
}


/* EP0 RX handler, called when EP0 interrupt happened and in RX state */
static void USB_Endpoint0_Rx(void)
{
	if (gUsbDevice.ep0_rx_handler != NULL)
	{
		/* called rx handler to get data*/
		gUsbDevice.ep0_rx_handler(&gUsbDevice.ep0info);
	}
	else
	{
		/* this should not happened, user should register rx handler when set EP0 into RX state */
		/* error occur, stall endpoint*/
		ASSERT(0);
//		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
	}
}


/* EP0 TX handler, called when EP0 interrupt happened and in TX state, 
     or EP0 just translate from IDLE to TX state */
static void USB_Endpoint0_Tx(void)
{
	kal_int32 nBytes;

	/* Determine number of bytes to send */
	if (gUsbDevice.ep0info.nBytesLeft <= USB_EP0_MAXP) 
	{
		nBytes = gUsbDevice.ep0info.nBytesLeft;
		gUsbDevice.ep0info.nBytesLeft = 0;
	}
	else 
	{
		nBytes = USB_EP0_MAXP;
		gUsbDevice.ep0info.nBytesLeft -= USB_EP0_MAXP;
	}

	/* send out data */
	USB_EPFIFOWrite (0, nBytes, gUsbDevice.ep0info.pData);

	/* update data pointer and  prepare for next transaction */
	gUsbDevice.ep0info.pData = (kal_uint8 *)gUsbDevice.ep0info.pData + nBytes;
	
	if((nBytes < USB_EP0_MAXP)||(gUsbDevice.ep0_send_one_pkt == KAL_TRUE))
	{
		gUsbDevice.ep0_state = USB_EP0_IDLE;
		/* last data, set end as true*/
		USB_Update_EP0_State(USB_EP0_DRV_STATE_WRITE_RDY, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_WRITE_RDY, KAL_FALSE, KAL_FALSE);
	}
}


/* EP0 interrupt handler called by USB_HISR */
static void USB_Endpoint0_Hdlr(void)
{
	kal_bool b_transaction_end;
	kal_bool b_sent_stall;
	kal_uint32 nCount;

	USB_Get_EP0_Status(&b_transaction_end, &b_sent_stall);

	/* Check for SentStall */
	/* SentStall && SetupEnd are impossible to occur together*/
	if (b_sent_stall == KAL_TRUE) 
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_CLEAR_SENT_STALL, KAL_FALSE, KAL_FALSE);
		gUsbDevice.ep0_state = USB_EP0_IDLE;
	}

	/* Check for SetupEnd */
	if (b_transaction_end == KAL_TRUE) 
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_TRANSACTION_END, KAL_FALSE, KAL_FALSE);
		gUsbDevice.ep0_state = USB_EP0_IDLE;
	}

	/* Call relevant routines for endpoint 0 state */
	if (gUsbDevice.ep0_state == USB_EP0_IDLE)
	{
		/* receive command request */
		nCount = USB_EP0_Pkt_Len();

		if (nCount > 0) 
		{
			/* idle state handler */
			USB_Endpoint0_Idle();
		}
	}
	else if (gUsbDevice.ep0_state == USB_EP0_RX)
	{
		/* Rx state handler */
		USB_Endpoint0_Rx();
	}
	else if (gUsbDevice.ep0_state == USB_EP0_RX_STATUS)
	{
		/* Data stage is RX, status stage is TX*/
		if(gUsbDevice.nDevState == DEVSTATE_SET_ADDRESS)
		{
			USB_SetAddress(gUsbDevice.ep0info.byFAddr, USB_SET_ADDR_STATUS);
			gUsbDevice.nDevState = DEVSTATE_ADDRESS;
		}

	#ifdef USB_20_ENABLE
		if(gUsbDevice.usb_enter_test_mode == KAL_TRUE)
		{
			/* After status complete, target must transmit to test mode in 3ms */
			USB_Enter_Test_Mode(gUsbDevice.usb_test_type);
			return;
		}
	#endif

		gUsbDevice.ep0_state = USB_EP0_IDLE;
		
		/* In case next setup followed the previous status very fast and interrupt only happens once*/
		/* receive command request */
		nCount = USB_EP0_Pkt_Len();

		if (nCount > 0) 
		{
			/* idle state handler */
			USB_Endpoint0_Idle();
		}
	}

	/* must use if, not else if, EP0 may enter TX state in previous IDLE state handler */
	if (gUsbDevice.ep0_state == USB_EP0_TX)
	{
		/* Tx state handler */
		USB_Endpoint0_Tx();
	}
}




