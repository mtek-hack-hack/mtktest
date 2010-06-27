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
 *    usbd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb1.1 host driver
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
#include "usb_hcd.h"
#include "usb.h"
#include "usbd.h"

#ifdef __OTG_ENABLE__

USBD_Struct	gUsbHost;

static void USBD_Attatch(USB_HCD_STATUS result, kal_uint32 param);
static void USBD_Set_Address(kal_uint8 address);
static void USBD_Get_Descriptor(kal_uint16 type_index, kal_uint16 lang_id, kal_uint16 buflen, kal_uint8 *buffer);
static void USBD_Set_Configuration(kal_uint16 config_value);
static void USBD_Ch9_Callback(USB_HCD_STATUS result, kal_uint32 param);
static void USBD_EP0_Hdlr(USB_HCD_STATUS result, kal_uint32 param);

/************************************************************
	gUsbHost initialize and release functions
*************************************************************/

/* Initialize USBD information */
void USBD_Init_Status(void)
{
	kal_uint32 index;

	gUsbHost.desc_info.cfg_number = 0;
	for(index = 0; index < USBD_MAX_CFG_NUM; index++)
	{
		gUsbHost.desc_info.cfg_info[index].interface_number = 0;
		gUsbHost.desc_info.p_otg_desc[index] = NULL;
	}	
	for(index = 0; index < USBD_MAX_INTERFACE_NUM; index++)
		gUsbHost.desc_info.interface_info[index].ep_number= 0;

	gUsbHost.ep0_state = USBD_EP0_NONE;
	gUsbHost.ep0_status.max_packet_size = USBD_EP0_MAX_PKT_SIZE;
	gUsbHost.ch9_state = USBD_CH9_START;
		
	gUsbHost.current_class_driver = -1;
	gUsbHost.total_class_driver = 0;
}

/* Release USBD information */
void USBD_Release_Status(void)
{
	kal_uint32 index;

	/* release all resource in case no detatch interrupt before disable interrupt */
	USBD_Detach(USB_HCD_DETATCH, 0);
	
	gUsbHost.desc_info.cfg_number = 0;
	for(index = 0; index < USBD_MAX_CFG_NUM; index++)
	{
		gUsbHost.desc_info.cfg_info[index].interface_number = 0;
		gUsbHost.desc_info.p_otg_desc[index] = NULL;
	}
	for(index = 0; index < USBD_MAX_INTERFACE_NUM; index++)
		gUsbHost.desc_info.interface_info[index].ep_number= 0;

	gUsbHost.ch9_state = USBD_CH9_START;
	
	gUsbHost.current_class_driver = -1;
	gUsbHost.total_class_driver = 0;
}

/* Register class specific driver structre */
void USBD_Register_Class_Driver(USBD_ClassDriver_Struct *class_driver_ptr)
{
	if(gUsbHost.total_class_driver==USBD_MAX_CLASS_DRIVER)
		EXT_ASSERT(0, gUsbHost.total_class_driver, 0, 0);

	gUsbHost.class_driver_ptr[gUsbHost.total_class_driver] = class_driver_ptr;
	gUsbHost.total_class_driver++;
}

/* Deregister all class specific driver structre */
void USBD_Derigister_Class_Driver(void)
{
	gUsbHost.total_class_driver = 0;	
}

/* After class driver is startup, it should register its own EP0 handler.
    Class specific erquest and standard request are all transfered to class EP0 handler */
void USBD_Register_EP0_Callback(usbd_ep0_callback callback)
{
	gUsbHost.ep0_callback = callback;
}

/************************************************************
	system ctrl functions
*************************************************************/

/* Initialize USBD(Host) */
void USBD_Init(void)
{
	/* Init HCD driver */
	USB_HCD_Init_Drv_Info();
	USB_HCD_Register_Drv_Info(USB_HCD_HDLR_ATTACH, 0, USBD_Attatch);
	USB_HCD_Register_Drv_Info(USB_HCD_HDLR_DETACH, 0, USBD_Detach);
	USB_HCD_Register_Drv_Info(USB_HCD_HDLR_TOKEN_DONE, 0, USBD_EP0_Hdlr);

	USB_HCD_Initialize_Drv();
	USB_HCD_EP0En();
}

/* Release USBD(Host)*/
void USBD_Release(void)
{
	USB_HCD_Release_Drv();
}

/* Attatch interrupt handler*/
static void USBD_Attatch(USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint32 index;
	
	gUsbHost.ch9_state=USBD_CH9_START;
	for(index = 0; index < USBD_MAX_CFG_NUM; index++)
	{
		gUsbHost.desc_info.p_otg_desc[index] = NULL;
	}
	gUsbHost.support_hnp = KAL_FALSE;
	/* Register EP0 handler */
	USBD_Register_EP0_Callback(USBD_Ch9_Callback);
	/* Start CH9 state machine*/
	USBD_Ch9_Callback(result, param);
}

/* Detach interrupt handler*/
void USBD_Detach(USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint32 index;
	
	gUsbHost.ch9_state=USBD_CH9_START;
	if(gUsbHost.current_class_driver!=-1)
		gUsbHost.class_driver_ptr[gUsbHost.current_class_driver]->detach();
	gUsbHost.current_class_driver = -1;
	gUsbHost.ch9_error_count = 0;
	for(index = 0; index < USBD_MAX_CFG_NUM; index++)
	{
		if(gUsbHost.desc_info.p_conf_data[index]!=NULL)
			free_ctrl_buffer(gUsbHost.desc_info.p_conf_data[index]);
		gUsbHost.desc_info.p_conf_data[index] = NULL;
		gUsbHost.desc_info.p_otg_desc[index] = NULL;
	}	
	gUsbHost.support_hnp = KAL_FALSE;
}


/************************************************************
	EP0 functions
*************************************************************/
/* Set Address request */
static void USBD_Set_Address(kal_uint8 address)
{ 
	gUsbHost.ep0_status.setup_cmd.bmRequestType = USB_CMD_STDDEVOUT;
	gUsbHost.ep0_status.setup_cmd.bRequest = USB_SET_ADDRESS;
	gUsbHost.ep0_status.setup_cmd.wValue = address;
	gUsbHost.ep0_status.setup_cmd.wIndex = 0;
	gUsbHost.ep0_status.setup_cmd.wLength = 0;
	
	gUsbHost.ep0_state = USBD_EP0_SETUP;
	gUsbHost.ep0_status.data_ptr= NULL;
	gUsbHost.ep0_status.ep0_data_dir = USBD_EP0_DATA_SEND;
	gUsbHost.ep0_status.sofar = 0;
	gUsbHost.ep0_status.todo = 0;
	
	USB_HCD_EP0_Setup_Req(8, &gUsbHost.ep0_status.setup_cmd);
} 

/* Get Descriptor request */
static void USBD_Get_Descriptor(kal_uint16 type_index, kal_uint16 lang_id, kal_uint16 buflen, kal_uint8 *buffer)
{ 
	gUsbHost.ep0_status.setup_cmd.bmRequestType = USB_CMD_STDDEVIN;
	gUsbHost.ep0_status.setup_cmd.bRequest = USB_GET_DESCRIPTOR;
	gUsbHost.ep0_status.setup_cmd.wValue = type_index;
	gUsbHost.ep0_status.setup_cmd.wIndex = lang_id;
	gUsbHost.ep0_status.setup_cmd.wLength = buflen;
	
	gUsbHost.ep0_state = USBD_EP0_SETUP;
	gUsbHost.ep0_status.data_ptr= buffer;
	gUsbHost.ep0_status.ep0_data_dir = USBD_EP0_DATA_RECV;
	gUsbHost.ep0_status.sofar = 0;
	gUsbHost.ep0_status.todo = buflen;
	
	USB_HCD_EP0_Setup_Req(8, &gUsbHost.ep0_status.setup_cmd);
} 

/* Set Configuration request */
static void USBD_Set_Configuration(kal_uint16 config_value)
{ 
	gUsbHost.ep0_status.setup_cmd.bmRequestType = USB_CMD_STDDEVOUT;
	gUsbHost.ep0_status.setup_cmd.bRequest = USB_SET_CONFIGURATION;
	gUsbHost.ep0_status.setup_cmd.wValue = config_value;
	gUsbHost.ep0_status.setup_cmd.wIndex = 0;
	gUsbHost.ep0_status.setup_cmd.wLength = 0;
	
	gUsbHost.ep0_state = USBD_EP0_SETUP;
	gUsbHost.ep0_status.data_ptr= NULL;
	gUsbHost.ep0_status.ep0_data_dir = USBD_EP0_DATA_SEND;
	gUsbHost.ep0_status.sofar = 0;
	gUsbHost.ep0_status.todo = 0;
	
	USB_HCD_EP0_Setup_Req(8, &gUsbHost.ep0_status.setup_cmd);
} 

/* Set Feature request */
void USBD_Set_Feature(kal_uint16 feature_value)
{ 
	gUsbHost.ep0_status.setup_cmd.bmRequestType = USB_CMD_STDDEVOUT;
	gUsbHost.ep0_status.setup_cmd.bRequest = USB_SET_FEATURE;
	gUsbHost.ep0_status.setup_cmd.wValue = feature_value;
	gUsbHost.ep0_status.setup_cmd.wIndex = 0;
	gUsbHost.ep0_status.setup_cmd.wLength = 0;
	
	gUsbHost.ep0_state = USBD_EP0_SETUP;
	gUsbHost.ep0_status.data_ptr= NULL;
	gUsbHost.ep0_status.ep0_data_dir = USBD_EP0_DATA_SEND;
	gUsbHost.ep0_status.sofar = 0;
	gUsbHost.ep0_status.todo = 0;
	
	USB_HCD_EP0_Setup_Req(8, &gUsbHost.ep0_status.setup_cmd);
} 

/* Clear Stall request */
void USBD_Clear_Stall(kal_uint8 ep_num, USB_EP_TYPE ep_type)
{ 
	gUsbHost.ep0_status.setup_cmd.bmRequestType = USB_CMD_STDEPOUT;
	gUsbHost.ep0_status.setup_cmd.bRequest = USB_CLEAR_FEATURE;
	gUsbHost.ep0_status.setup_cmd.wValue = USB_FTR_EPHALT;
	gUsbHost.ep0_status.setup_cmd.wIndex = ep_num;
	if(ep_type == USB_RX_EP_TYPE)
		gUsbHost.ep0_status.setup_cmd.wIndex |= 0x80;
	gUsbHost.ep0_status.setup_cmd.wLength = 0;
	
	gUsbHost.ep0_state = USBD_EP0_SETUP;
	gUsbHost.ep0_status.data_ptr= NULL;
	gUsbHost.ep0_status.ep0_data_dir = USBD_EP0_DATA_NULL;
	gUsbHost.ep0_status.sofar = 0;
	gUsbHost.ep0_status.todo = 0;
	
	USB_HCD_EP0_Setup_Req(8, &gUsbHost.ep0_status.setup_cmd);
} 

kal_bool USBD_Get_HNP_Support(void)
{
	return gUsbHost.support_hnp;
}

/* CH9 state machine. Each time EP0 setup, data, status complete, this callback functio will be called */
static void USBD_Ch9_Callback(USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint32 data_size;
	kal_uint32 data_offset;
	kal_uint32 ep_index;
	kal_uint32 if_index;
	kal_uint32 index;
	kal_uint32 index2;
	Usb_If_Dscr *p_interface_desc;
	static kal_uint8 set_cfg_number = 0;
	static kal_uint8 get_cfg9_number = 0;
	static kal_uint8 get_cfg_number = 0;
	static kal_uint8 parse_cfg_number = 0;
		
	 if(((result==USB_HCD_NO_RESPONSE)||(result==USB_HCD_TIMEOUT) || (result==USB_HCD_STALL))
	 	&&(gUsbHost.ch9_state!=USBD_CH9_START))
	 {
	 	/* error handling */
	 	gUsbHost.ch9_error_count++;
	 	if(gUsbHost.ch9_state == USBD_CH9_SET_HNP_ENABLE)
	 	{
			USBD_Set_Configuration(1);
			gUsbHost.support_hnp = KAL_FALSE;
			gUsbHost.ch9_state = USBD_CH9_SET_CONF;
			return;
	 	}
	 	else if(gUsbHost.ch9_error_count>=3)
	 	{
			kal_mem_set(&gUsbHost.desc_info, 0, sizeof(gUsbHost.desc_info));

			//find matched driver, it will match to default driver
			for(index = 0; index< gUsbHost.total_class_driver; index++)
			{
				if((gUsbHost.class_driver_ptr[index]->match(&gUsbHost.desc_info, &set_cfg_number))==KAL_TRUE)
					break;
			}
			gUsbHost.current_class_driver = index;	

			// call the startup function
			gUsbHost.class_driver_ptr[gUsbHost.current_class_driver]->startup(set_cfg_number);

			return;
	 	}
	 	else
	 	{
	 		/* error count dose not exceed limitation, so restart enumeration*/
	 		USB_HCD_Set_UnMask_Irq(KAL_FALSE);
	 		/* re-start enumeration after delay timeout */
	 		USB_HCD_Delay_Reset_Device(result, USBD_ERROR_DELAY);
	 		return;
	 	}
	 }

	if(gUsbHost.ch9_state==USBD_CH9_START)
	{
		USB_HCD_Set_EP_Max_Pkt(0, gUsbHost.ep0_status.max_packet_size);
		USBD_Set_Address(1);
		gUsbHost.ch9_state = USBD_CH9_SET_ADDR;
	}
	else if(gUsbHost.ch9_state==USBD_CH9_SET_ADDR)
	{
		USB_HCD_SetAddress(1);
		USBD_Get_Descriptor(USB_DEVICE<<8, 0, 8, 
									(kal_uint8*)&gUsbHost.desc_info.dev_desc);
		get_cfg9_number = 0;
		get_cfg_number = 0;
		parse_cfg_number = 0;
		gUsbHost.ch9_state = USBD_CH9_GET_DEV_DESC_8;
	}
	else if(gUsbHost.ch9_state==USBD_CH9_GET_DEV_DESC_8)
	{
		gUsbHost.ep0_status.max_packet_size = gUsbHost.desc_info.dev_desc.bMaxPacketSize0;
		USB_HCD_Set_EP_Max_Pkt(0, gUsbHost.ep0_status.max_packet_size);
		USBD_Get_Descriptor(USB_DEVICE<<8, 0, sizeof(gUsbHost.desc_info.dev_desc), 
									(kal_uint8*)&gUsbHost.desc_info.dev_desc);
		gUsbHost.ch9_state = USBD_CH9_GET_DEV_DESC;
	}
	else if(gUsbHost.ch9_state==USBD_CH9_GET_DEV_DESC)
	{
		if(get_cfg9_number==0)
		{
			gUsbHost.desc_info.cfg_number = gUsbHost.desc_info.dev_desc.bNumConfigurations;
			if(gUsbHost.desc_info.cfg_number > USBD_MAX_CFG_NUM)
				gUsbHost.desc_info.cfg_number = USBD_MAX_CFG_NUM;
		}
		
		gUsbHost.desc_info.p_conf_data[get_cfg9_number] = (kal_uint8 *)get_ctrl_buffer(sizeof(Usb_Cfg_Dscr));
		USBD_Get_Descriptor((USB_CONFIG<<8)+get_cfg9_number, 0, 9, gUsbHost.desc_info.p_conf_data[get_cfg9_number]);
		
		get_cfg9_number++;
		if(get_cfg9_number>gUsbHost.desc_info.cfg_number)
			EXT_ASSERT(0, get_cfg9_number, gUsbHost.desc_info.cfg_number, 0);
		if(get_cfg9_number==gUsbHost.desc_info.cfg_number)
			gUsbHost.ch9_state = USBD_CH9_GET_CONF_DESC_9;
	}
	else if(gUsbHost.ch9_state==USBD_CH9_GET_CONF_DESC_9)
	{
		data_size = ((Usb_Cfg_Dscr*)gUsbHost.desc_info.p_conf_data[get_cfg_number])->wTotalLength;
		free_ctrl_buffer(gUsbHost.desc_info.p_conf_data[get_cfg_number]);
		gUsbHost.desc_info.p_conf_data[get_cfg_number] = (kal_uint8 *)get_ctrl_buffer(data_size);
		USBD_Get_Descriptor((USB_CONFIG<<8)+get_cfg_number, 0, data_size, gUsbHost.desc_info.p_conf_data[get_cfg_number]);
		get_cfg_number++;
		if(get_cfg_number>gUsbHost.desc_info.cfg_number)
			EXT_ASSERT(0, get_cfg_number, gUsbHost.desc_info.cfg_number, 0);
		if(get_cfg_number==gUsbHost.desc_info.cfg_number)
			gUsbHost.ch9_state = USBD_CH9_GET_CONF_DESC;
	}
	else if(gUsbHost.ch9_state==USBD_CH9_GET_CONF_DESC)
	{
		ep_index = 1;
		if_index = 0;
		for(parse_cfg_number=0; parse_cfg_number<gUsbHost.desc_info.cfg_number; parse_cfg_number++)
		{	
			/* reset otg descriptor*/
			gUsbHost.desc_info.p_otg_desc[parse_cfg_number] = NULL;
			/* configuration descriptor */
			gUsbHost.desc_info.cfg_info[parse_cfg_number].p_cfg_desc = (Usb_Cfg_Dscr*)gUsbHost.desc_info.p_conf_data[parse_cfg_number];
			/* interface descriptor */
			data_size = gUsbHost.desc_info.cfg_info[parse_cfg_number].p_cfg_desc->wTotalLength;
			data_offset = gUsbHost.desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bLength;
			gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number= 0;
			while((data_offset<data_size)&&(gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number<USBD_MAX_IF_PER_CFG)
				&& ((gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number==0)||
					(gUsbHost.desc_info.cfg_info[parse_cfg_number].p_interface_info[gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number-1]==NULL)||
					(gUsbHost.desc_info.cfg_info[parse_cfg_number].p_interface_info[gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number-1]->ep_number<USBD_MAX_EP_PER_IF)))
			{
				if(ep_index>=USBD_MAX_EP_NUM)
					EXT_ASSERT(0, ep_index, USBD_MAX_EP_NUM, parse_cfg_number);
				if(if_index>=USBD_MAX_INTERFACE_NUM)
					EXT_ASSERT(0, if_index, USBD_MAX_INTERFACE_NUM, parse_cfg_number);	
					
				p_interface_desc = (Usb_If_Dscr*)&gUsbHost.desc_info.p_conf_data[parse_cfg_number][data_offset];
				if(p_interface_desc->bDescriptorType==USB_INTERFACE)
				{
					gUsbHost.desc_info.interface_info[if_index].p_interface_desc = (Usb_If_Dscr*)p_interface_desc;
					gUsbHost.desc_info.cfg_info[parse_cfg_number].p_interface_info[gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number] = &gUsbHost.desc_info.interface_info[if_index];
					data_offset+=gUsbHost.desc_info.interface_info[if_index].p_interface_desc->bLength;
					if_index++;
					gUsbHost.desc_info.cfg_info[parse_cfg_number].p_interface_info[gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number]->ep_number = 0;
					gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number++;
				}
				else if(p_interface_desc->bDescriptorType==USB_ENDPOINT)
				{
					if(gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number==0)
						EXT_ASSERT(0, parse_cfg_number, data_size, data_offset);
					gUsbHost.desc_info.ep_info[ep_index].p_stdep = (Usb_Ep_Dscr*)p_interface_desc;
					gUsbHost.desc_info.cfg_info[parse_cfg_number].p_interface_info[gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number-1]->p_ep_info[gUsbHost.desc_info.cfg_info[parse_cfg_number].p_interface_info[gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number-1]->ep_number] = &gUsbHost.desc_info.ep_info[ep_index];
					data_offset+=gUsbHost.desc_info.ep_info[ep_index].p_stdep->bLength;
					ep_index++;
					gUsbHost.desc_info.cfg_info[parse_cfg_number].p_interface_info[gUsbHost.desc_info.cfg_info[parse_cfg_number].interface_number-1]->ep_number++;
				}
				else if(p_interface_desc->bDescriptorType==USB_OTG_DESC)
				{
					// 0520 temp not check
					gUsbHost.desc_info.p_otg_desc[parse_cfg_number] = (Usb_Otg_Dscr*)p_interface_desc;
					data_offset+=p_interface_desc->bLength;
				}
				else
				{
					data_offset+=p_interface_desc->bLength;
				}
			}
		}	

		//find matched friver
		for(index = 0; index< gUsbHost.total_class_driver; index++)
		{
			if((gUsbHost.class_driver_ptr[index]->match(&gUsbHost.desc_info, &set_cfg_number))==KAL_TRUE)
				break;
		}
		gUsbHost.current_class_driver = index;	

		if((gUsbHost.desc_info.p_otg_desc[set_cfg_number]!=NULL) && (gUsbHost.desc_info.p_otg_desc[set_cfg_number]->bAttribute&USB_OTG_HNP_SUPPORT))
		{
			USBD_Set_Feature(USB_FTR_B_HNP_ENB);
			gUsbHost.support_hnp = KAL_FALSE;
			gUsbHost.ch9_state = USBD_CH9_SET_HNP_ENABLE;
		}
		else
		{
			USBD_Set_Configuration(set_cfg_number);
			gUsbHost.support_hnp = KAL_FALSE;
			gUsbHost.ch9_state = USBD_CH9_SET_CONF;
		}				
	}
	else if(gUsbHost.ch9_state == USBD_CH9_SET_HNP_ENABLE)
	{
		USBD_Set_Configuration(set_cfg_number);
		gUsbHost.support_hnp = KAL_TRUE;
		gUsbHost.ch9_state = USBD_CH9_SET_CONF;
	}
	else if(gUsbHost.ch9_state==USBD_CH9_SET_CONF)
	{
		// call the startup function
		gUsbHost.class_driver_ptr[gUsbHost.current_class_driver]->startup(set_cfg_number);
		/* enumeration is completed. reset errot count to zero*/
		gUsbHost.ch9_error_count = 0;
		gUsbHost.ch9_state = USBD_CH9_ENUM_OK;
	}
}

/* EP0 hander. The SETUP, DATA, STATUS state is handled in this handler */
static void USBD_EP0_Hdlr(USB_HCD_STATUS result, kal_uint32 param)
{
	if(result==USB_HCD_OK)
	{
		if(gUsbHost.ep0_state==USBD_EP0_SETUP)
		{
			if(gUsbHost.ep0_status.todo!=0)
			{
				/* Have data to send/recv*/
				if(gUsbHost.ep0_status.ep0_data_dir==USBD_EP0_DATA_RECV)
					USB_HCD_EP0_Data_Req(USB_HCD_PIPE_DIR_IN, gUsbHost.ep0_status.todo, gUsbHost.ep0_status.data_ptr);
				else
					USB_HCD_EP0_Data_Req(USB_HCD_PIPE_DIR_OUT, gUsbHost.ep0_status.todo, gUsbHost.ep0_status.data_ptr);	

				gUsbHost.ep0_state = USBD_EP0_DATA;
			}
			else
			{
				/* request for the status*/
				USB_HCD_EP0_Status_Req(USB_HCD_PIPE_DIR_IN);
				gUsbHost.ep0_state = USBD_EP0_STATUS;
			}
		}
		else if(gUsbHost.ep0_state==USBD_EP0_DATA)
		{
			gUsbHost.ep0_status.sofar = param;
			/* request for the status*/
			if(gUsbHost.ep0_status.ep0_data_dir==USBD_EP0_DATA_RECV)
				USB_HCD_EP0_Status_Req(USB_HCD_PIPE_DIR_OUT);
			else
				USB_HCD_EP0_Status_Req(USB_HCD_PIPE_DIR_IN);	

			gUsbHost.ep0_state = USBD_EP0_STATUS;
		}
		else if(gUsbHost.ep0_state==USBD_EP0_STATUS)
		{
			gUsbHost.ep0_state = USBD_EP0_NONE;
			gUsbHost.ep0_callback(result, gUsbHost.ep0_status.sofar);
		}
		else
		{
			ASSERT(0);
		}
	} /* result==USB_HCD_OK */
	else if((result==USB_HCD_NO_RESPONSE) || (result==USB_HCD_TIMEOUT) || (result==USB_HCD_STALL))
	{
		// no matter it is in which state, return to NONE
		gUsbHost.ep0_state = USBD_EP0_NONE;
		gUsbHost.ep0_callback(result, param);
	}
}

#endif /* __OTG_ENABLE__*/

