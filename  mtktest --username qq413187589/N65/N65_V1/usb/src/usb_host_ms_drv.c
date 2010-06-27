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
 *    usb_host_ms_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host mass storage class driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "drv_comm.h"
#include "gpt_sw.h"
#include "app_buff_alloc.h"
#include "usb_comm.h"
#include "usb.h"
#include "usb_custom.h"
#include "usbd.h"
#include "otg_drv.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */

#include "usbms_state.h"
#include "usb_host_ms_drv.h"
#include "usb_host_ms_if.h"
#include "usb_host_ms_custom.h"
#include "usb_host_ms_adap.h"

/* for debig only*/
//#include "usb_hcd_pri.h"
//extern USB_HCD_Struct g_UsbHcdInfo;

#ifdef __OTG_ENABLE__

/* The command and data (exepct read and write use this shared buffer)*/
/* Only one command and one data will be executed at one time */
static kal_uint8 g_usb_ms_cmd[USBMS_MAX_CMD_LEN];
static kal_uint8 g_usb_ms_data[USBMS_MAX_DATA_LEN];

static kal_bool	USB_Host_Ms_Match(USBD_Desc_Info *p_desc_info, kal_uint8 *p_cfg_num);
static void USB_Host_Ms_Startup(kal_uint8 cfg_num);
static void USB_Host_Ms_Detach(void);

static kal_bool USB_Host_Ms_Send_Cmd(USBH_Ms_Cmd_Struct *ms_cmd);
static void USB_Host_Ms_Hdlr(USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_Ctrl_EP_Hdlr(USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_Bulk_EP_Hdlr(USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_CBW_Hdler(USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_DATA_Hdler(USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_CSW_Hdler(USB_HCD_STATUS result, kal_uint32 param);

USB_Host_Ms_Struct g_UsbHostMs;

USBD_ClassDriver_Struct USB_Host_Ms_Drv = 
{
	USB_Host_Ms_Match,
	USB_Host_Ms_Startup,
	USB_Host_Ms_Detach
};

/************************************************************
	ms class register  functions (match, startup, detatch)
*************************************************************/

static kal_bool	USB_Host_Ms_Match(USBD_Desc_Info *p_desc_info, kal_uint8 *p_cfg_num)
{
	kal_bool b_match = KAL_FALSE;
	kal_uint32 index = 0;
	kal_uint32 index2 = 0;
	kal_uint16 max_support_power = USBD_Get_Max_Power();
	
	max_support_power = max_support_power/2;
	*p_cfg_num = 0;
	
	while(index < p_desc_info->cfg_number)
	{
		if((p_desc_info->dev_desc.bDeviceClass == USB_MS_DEVICE_CODE) 
			&& (p_desc_info->cfg_info[index].p_cfg_desc->bMaxPower<=max_support_power)
			&& (p_desc_info->cfg_info[index].p_interface_info[0]->p_interface_desc->bInterfaceClass== USB_MS_INTERFACE_CLASS_CODE)
			&& ((p_desc_info->cfg_info[index].p_interface_info[0]->p_interface_desc->bInterfaceSubClass  == USB_MS_INTERFACE_SUBCLASS_CODE) 
				|| (p_desc_info->cfg_info[index].p_interface_info[0]->p_interface_desc->bInterfaceSubClass  == USB_MS_INTERFACE_SUBCLASS_CODE_2))	
			&& (p_desc_info->cfg_info[index].p_interface_info[0]->p_interface_desc->bInterfaceProtocol  == USB_MS_INTERFACE_PROTOCOL_CODE) )
		{
			b_match = KAL_TRUE;
		
			for(index2 = 0; index2 < p_desc_info->cfg_info[index].p_interface_info[0]->ep_number; index2++)
			{
				if(((p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->bEndpointAddress & USB_EP_DIR) == USB_EP_DIR_IN)
					&& (p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->bmAttributes == USB_EP_BULK))
				{
					g_UsbHostMs.ep_in_num = p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->bEndpointAddress & (~USB_EP_DIR);
					g_UsbHostMs.ep_in_max_pkt_size = p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->wMaxPacketSize[0]
										+ (p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->wMaxPacketSize[1]<<8);
					if(g_UsbHostMs.ep_in_max_pkt_size>USB_HCD_Get_FM_Pkt_Size())
						b_match = KAL_FALSE;
				}
				else if(((p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->bEndpointAddress & USB_EP_DIR) == USB_EP_DIR_OUT)
					&& (p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->bmAttributes == USB_EP_BULK))
				{
					g_UsbHostMs.ep_out_num = p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->bEndpointAddress & (~USB_EP_DIR);	
					g_UsbHostMs.ep_out_max_pkt_size = p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->wMaxPacketSize[0]
										+ (p_desc_info->cfg_info[index].p_interface_info[0]->p_ep_info[index2]->p_stdep->wMaxPacketSize[1]<<8);
					if(g_UsbHostMs.ep_in_max_pkt_size>USB_HCD_Get_FM_Pkt_Size())
						b_match = KAL_FALSE;
				}	
			}
		}
		
		if(b_match==KAL_TRUE)
		{
			*p_cfg_num = p_desc_info->cfg_info[index].p_cfg_desc->bConfigurationValue;
			break;		
		}
		index++;	
	}
	
	return b_match;
}

static void USB_Host_Ms_Startup(kal_uint8 cfg_num)
{
	kal_uint8 ep_index;
	kal_uint8 index;
	ilm_struct *usb_ilm;
	kal_uint32 event_group;

	ep_index = USB_HCD_Get_EP_Channel( );
	USB_HCD_Set_EP_Max_Pkt(ep_index, g_UsbHostMs.ep_in_max_pkt_size);
	g_UsbHostMs.ep_in_index = ep_index;
	ep_index = USB_HCD_Get_EP_Channel( );
	USB_HCD_Set_EP_Max_Pkt(ep_index, g_UsbHostMs.ep_out_max_pkt_size);
	g_UsbHostMs.ep_out_index = ep_index;

	g_UsbHostMs.total_lun = 0;
	g_UsbHostMs.media_handle = USBHost_Get_Media_Hanle(&g_UsbHostMs.support_lun);
	/* Initailize media handle */
	for(index = 0; index < g_UsbHostMs.support_lun; index++)
		g_UsbHostMs.media_handle[index] = index;
	USB_Host_Ms_Get_Media_Resource();
	if((g_UsbHostMs.support_lun==0) || (g_UsbHostMs.media_info==NULL) || (g_UsbHostMs.media_msg_array==NULL))
		EXT_ASSERT(0, (kal_uint32)g_UsbHostMs.support_lun,  (kal_uint32)g_UsbHostMs.media_info, 
					(kal_uint32)g_UsbHostMs.media_msg_array);
	for(index = 0; index < g_UsbHostMs.support_lun; index++)
	{
		g_UsbHostMs.media_info[index].pre_state = USB_HOST_MS_MEDIA_STATE_ABSENT;
	}
	g_UsbHostMs.dev_error_count = 0;
	g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_READY;
	g_UsbHostMs.dev_attatch = KAL_TRUE;
	
	USB_HCD_Register_Drv_Info(USB_HCD_HDLR_TOKEN_DONE, g_UsbHostMs.ep_in_index, USB_Host_Ms_Hdlr);
	USB_HCD_Register_Drv_Info(USB_HCD_HDLR_TOKEN_DONE, g_UsbHostMs.ep_out_index, USB_Host_Ms_Hdlr);
	
	if(g_UsbHostMs.ep_in_max_pkt_size==USB_HCD_Get_FM_Pkt_Size())
		USB_HCD_InEPEn(g_UsbHostMs.ep_in_index, g_UsbHostMs.ep_in_num, USB_HCD_ENDPT_BULK, 100, KAL_TRUE);
	else
		USB_HCD_InEPEn(g_UsbHostMs.ep_in_index, g_UsbHostMs.ep_in_num, USB_HCD_ENDPT_BULK, 0xff, KAL_FALSE);
	if(g_UsbHostMs.ep_out_max_pkt_size==USB_HCD_Get_FM_Pkt_Size())
		USB_HCD_OutEPEn(g_UsbHostMs.ep_out_index, g_UsbHostMs.ep_out_num, USB_HCD_ENDPT_BULK, 100, KAL_TRUE);
	else
		USB_HCD_OutEPEn(g_UsbHostMs.ep_out_index, g_UsbHostMs.ep_out_num, USB_HCD_ENDPT_BULK, 0xff, KAL_FALSE);


	USBD_Register_EP0_Callback(USB_Host_Ms_Hdlr);
	//USBD_Register_EP0_Callback(USB_Host_Ms_EP0_Callback);
	
	USB_HCD_Get_DMA_Channel();

	if(g_UsbHostMs.event_id!=0)
	{
		/* rereive all events that may exist after previous detatch */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
							KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);
	}
	
	/* send msg to USB task, start ms state machine */
	DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,
					MOD_USB, MSG_ID_USB_MSHOST_START_IND, NULL);
	msg_send_ext_queue(usb_ilm);
	
	USB_Host_Ms_SendInd(USB_HOST_MS_MSG_PLUG_IN);
}

static void USB_Host_Ms_Detach(void)
{
	kal_uint32 index;
	kal_bool b_send_msg = KAL_FALSE;

	GPTI_StopItem(g_UsbHostMs.gpt_handle);
	USB_HCD_Free_DMA_Channel();
	USB_HCD_Free_EP_Channel();

	for(index=0; index<g_UsbHostMs.total_lun; index++)
	{
		/* If original state is READY, set state change as true */
		if(((g_UsbHostMs.media_info[index].state==USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
			||(g_UsbHostMs.media_info[index].state==USB_HOST_MS_MEDIA_STATE_READY))
			&& (g_UsbHostMs.media_info[index].sec_size!=0))
		{
			g_UsbHostMs.media_state_change |= (1<<index);
		}
		
		/* Set all the media state to error */
		g_UsbHostMs.media_info[index].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
	}

	g_UsbHostMs.dev_attatch = KAL_FALSE;

	/* wake up wating task */
	g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DETATCH, KAL_OR);

	USB_Host_Ms_Dis_Device();

	/* Notify FMT about media change */
	if((g_UsbHostMs.media_state_change != 0) && (g_UsbHostMs.b_sending_change_ilm == KAL_FALSE))
	{
		for(index=0; index<g_UsbHostMs.total_lun; index++)
		{
			if((g_UsbHostMs.media_state_change&(1<<index))!=0)
			{
				if(g_UsbHostMs.media_info[index].state != g_UsbHostMs.media_info[index].pre_state)
				{
					g_UsbHostMs.media_info[index].pre_state = g_UsbHostMs.media_info[index].state;
					g_UsbHostMs.media_msg_array[index] = (kal_uint32)&g_UsbHostMs.media_handle[index];
					b_send_msg = KAL_TRUE;
				}
				else
				{
					g_UsbHostMs.media_msg_array[index] = NULL;
				}
			}
			else
			{
				g_UsbHostMs.media_msg_array[index] = NULL;
			}
		}
		g_UsbHostMs.media_state_change = 0;
		if(b_send_msg == KAL_TRUE)
		{
			USB_Host_Ms_SendInd(USB_HOST_MS_MSG_MEDIA_CHANGE);
		}
	}

	USB_Host_Ms_SendInd(USB_HOST_MS_MSG_PLUG_OUT);
}


/************************************************************
	ms utilities (send msg to FMT task. Indicate card status change)
*************************************************************/
#include "custom_config.h"

/* send card change indication to FMT task */
void USB_Host_Ms_SendInd(USB_HOST_MS_MSG_TYPE msg)
{
	ilm_struct *usb_ilm;
	usb_host_ms_media_struct *change_ind;
	usb_host_ms_drive_struct *drive_ind;

	switch(msg)
	{
	case USB_HOST_MS_MSG_MEDIA_CHANGE:
		if(g_UsbHostMs.b_sending_change_ilm==KAL_TRUE)
			ASSERT(0);
		g_UsbHostMs.b_sending_change_ilm = KAL_TRUE;
		change_ind = (usb_host_ms_media_struct*)construct_local_para(
						sizeof(usb_host_ms_media_struct) + (sizeof(kal_uint32*)*g_UsbHostMs.support_lun-1) , TD_CTRL);
		change_ind->media_size = g_UsbHostMs.support_lun;
		kal_mem_cpy(&change_ind->media_array, g_UsbHostMs.media_msg_array, sizeof(kal_uint32*)*g_UsbHostMs.support_lun);
		DRV_BuildPrimitive(usb_ilm,
					MOD_DRV_HISR,
					MOD_FMT,	
					MSG_ID_OTG_CARD_DETECT_IND,
					change_ind);
		msg_send_ext_queue(usb_ilm);
		break;
	case USB_HOST_MS_MSG_PLUG_IN:
		drive_ind = (usb_host_ms_drive_struct*)construct_local_para(
							sizeof(usb_host_ms_drive_struct), TD_CTRL);
		drive_ind->drive = (void*)&FS_OTGDrv;
		drive_ind->media_size = g_UsbHostMs.support_lun;
		DRV_BuildPrimitive(usb_ilm,
						MOD_DRV_HISR,
						MOD_FMT,
						MSG_ID_OTG_MS_INSERT_IND,
						drive_ind);
		msg_send_ext_queue(usb_ilm);
		break;
	case USB_HOST_MS_MSG_PLUG_OUT:
		if(g_UsbHostMs.b_sending_plugout_ilm==KAL_TRUE)
			ASSERT(0);
		g_UsbHostMs.b_sending_plugout_ilm = KAL_TRUE;
		drive_ind = (usb_host_ms_drive_struct*)construct_local_para(
							sizeof(usb_host_ms_drive_struct), TD_CTRL);
		drive_ind->drive = (void*)&FS_OTGDrv;
		drive_ind->media_size = g_UsbHostMs.support_lun;
		DRV_BuildPrimitive(usb_ilm,
						MOD_DRV_HISR,
						MOD_FMT,
						MSG_ID_OTG_MS_REMOVE_IND,
						drive_ind);
		msg_send_ext_queue(usb_ilm);
		break;
	default:
		EXT_ASSERT(0, msg, g_UsbHostMs.dev_state, 0);
		break;	
	}
}

void USB_Host_Ms_Get_Media_Resource(void)
{
	kal_uint8 index;
	g_UsbHostMs.media_info = (USBH_Ms_Media_Struct*)get_ctrl_buffer(sizeof(USBH_Ms_Media_Struct)*g_UsbHostMs.support_lun);
	g_UsbHostMs.media_msg_array = get_ctrl_buffer(sizeof(kal_uint32)*g_UsbHostMs.support_lun);
	for(index = 0; index < g_UsbHostMs.support_lun; index++)
		g_UsbHostMs.media_msg_array[index] = NULL;
}

void USB_Host_Ms_Free_Media_Resource(void)
{
	free_ctrl_buffer((USBH_Ms_Media_Struct*)g_UsbHostMs.media_info);
	g_UsbHostMs.media_info = NULL;

	free_ctrl_buffer((kal_uint32*)g_UsbHostMs.media_msg_array);
	g_UsbHostMs.media_msg_array = NULL;
}

void USB_Host_Ms_Dis_Device(void)
{
	USB_HCD_Dis_Attach();
}	

void USB_Host_Ms_En_Device(void)
{
	USB_HCD_En_Attach();
}	

 /************************************************************
	ms class ep0 class specific functions (Control endpoint functions)
*************************************************************/
/* class specific Get LUN request. 
     It is a block function, the transfer is completed when return
     Note that this function must be used in task contex */
void USB_Host_Ms_Get_LUN(void)
{ 
	kal_uint32 event_group;
	
	gUsbHost.ep0_status.setup_cmd.bmRequestType = USB_CMD_CLASSIFIN;
	gUsbHost.ep0_status.setup_cmd.bRequest = USB_MS_GETMAXLUN;
	gUsbHost.ep0_status.setup_cmd.wValue = 0;
	gUsbHost.ep0_status.setup_cmd.wIndex = 0;
	gUsbHost.ep0_status.setup_cmd.wLength = 1;
	
	gUsbHost.ep0_state = USBD_EP0_SETUP;
	gUsbHost.ep0_status.data_ptr= &g_UsbHostMs.total_lun;
	gUsbHost.ep0_status.ep0_data_dir = USBD_EP0_DATA_RECV;
	gUsbHost.ep0_status.sofar = 0;
	gUsbHost.ep0_status.todo = 1;

	g_UsbHostMs.ms_cmd = USB_HOST_MS_EP0_CMD_GET_LUN;
	
	USB_HCD_EP0_Setup_Req(8, &gUsbHost.ep0_status.setup_cmd);

	if(g_UsbHostMs.dev_attatch == KAL_TRUE)
	{
		/* wait for transfer complete */
		/* LUN number information is stored in g_UsbHostMs when event is retrieved*/
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
	
		/* Device status is error if result not OK in EP0 command */
		if(g_UsbHostMs.result != USB_HOST_MS_RESULT_OK)
			g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		else
			g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_READY;
	}
	
} 

/* class specific reset request, not the whole device reset */
void USB_Host_Ms_Reset(void)
{ 
	kal_uint32 event_group;
	
	gUsbHost.ep0_status.setup_cmd.bmRequestType = USB_CMD_CLASSIFOUT;
	gUsbHost.ep0_status.setup_cmd.bRequest = USB_MS_RESET;
	gUsbHost.ep0_status.setup_cmd.wValue = 0;
	gUsbHost.ep0_status.setup_cmd.wIndex = 0;
	gUsbHost.ep0_status.setup_cmd.wLength = 0;
	
	gUsbHost.ep0_state = USBD_EP0_SETUP;
	gUsbHost.ep0_status.data_ptr= &g_UsbHostMs.total_lun;
	gUsbHost.ep0_status.ep0_data_dir = USBD_EP0_DATA_NULL;
	gUsbHost.ep0_status.sofar = 0;
	gUsbHost.ep0_status.todo = 0;

	g_UsbHostMs.ms_cmd = USB_HOST_MS_EP0_CMD_RESET;
	
	USB_HCD_EP0_Setup_Req(8, &gUsbHost.ep0_status.setup_cmd);

	if(g_UsbHostMs.dev_attatch== KAL_TRUE)
	{
		/* wait for transfer complete */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
	
		/* Device status is error if result not OK in EP0 command */	
		if(g_UsbHostMs.result != USB_HOST_MS_RESULT_OK)
			g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		else
			g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_READY;
	}	
} 


/************************************************************
	ms class state functions (Bulk endpoint functions)
*************************************************************/

/* REQUEST SENSE command (03h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Request_Sense(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs.media_info[lun].state;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_REQUESTSENSE;
	g_usb_ms_cmd[4] = USBMS_REQUESTSENSE_DATA_LEN;

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_REQUESTSENSE_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = USBMS_REQUESTSENSE_DATA_LEN;
	g_UsbHostMs.ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;
	
	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE) && (g_UsbHostMs.dev_attatch== KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer  */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			/* translate sense data to media state */
			if(g_usb_ms_data[2] ==0x00)
			{
				if(g_UsbHostMs.media_info[lun].state!=USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
					g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
			}
			else if(g_usb_ms_data[2] ==0x06)
			{
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_CHANGED;
				/* update sector size to 0, it should be set in next read capacify command */
				/* it is used in case test unit ready change state to USB_HOST_MS_MEDIA_STATE_READY,
				    but read capacity is not yet issued */
				g_UsbHostMs.media_info[lun].sec_size = 0;
			}
			else if(g_usb_ms_data[2] ==0x02)
			{
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
				/* update sector size to 0, it should be set in next read capacify command */
				g_UsbHostMs.media_info[lun].sec_size = 0;
			}
			else
			{
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_ERROR;
				/* update sector size to 0, it should be set in next read capacify command */
				g_UsbHostMs.media_info[lun].sec_size = 0;
			}	
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* Do not request sense again to avoid looping */
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL  do not handle it*/

		if(media_state!=g_UsbHostMs.media_info[lun].state)
		{
			if( (media_state == USB_HOST_MS_MEDIA_STATE_ABSENT) && 
				 (g_UsbHostMs.media_info[lun].state == USB_HOST_MS_MEDIA_STATE_CHANGED) )
			{
				//If only from absent to state change, do no notify FMT.
				//Otherwise some mass storage may first mount fail, and then success,
				//user may see plug out and then plug in 
			}
			else
			{
				//g_UsbHostMs.b_state_change = KAL_TRUE;
				g_UsbHostMs.media_state_change |= (1<<lun);
			}
		}
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}
	
	return g_UsbHostMs.result;

}

/* INQUIRY command (12h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Inquiry(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_INQUIRY;
	g_usb_ms_cmd[4] = USBMS_INQUIRY_DATA_LEN;

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_INQUIRY_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = USBMS_INQUIRY_DATA_LEN;
	g_UsbHostMs.ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;
	
	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch== KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer  */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			kal_mem_cpy(g_UsbHostMs.media_info[lun].vendor_info, &g_usb_ms_data[8], USBMS_INQUIRY_VENDOR_INFO_LEN);
			kal_mem_cpy(g_UsbHostMs.media_info[lun].product_iden, &g_usb_ms_data[16], USBMS_INQUIRY_PRODUCT_IDEN_LEN);
			kal_mem_cpy(g_UsbHostMs.media_info[lun].product_rev, &g_usb_ms_data[32], USBMS_INQUIRY_PRODUCT_REV_LEN);		
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* reset venfor and product string info as 0*/
			kal_mem_set(g_UsbHostMs.media_info[lun].vendor_info, 0, USBMS_INQUIRY_VENDOR_INFO_LEN);
			kal_mem_set(g_UsbHostMs.media_info[lun].product_iden, 0, USBMS_INQUIRY_PRODUCT_IDEN_LEN);
			kal_mem_set(g_UsbHostMs.media_info[lun].product_rev, 0, USBMS_INQUIRY_PRODUCT_REV_LEN);	
		
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL  do not handle it */
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}
	
	return g_UsbHostMs.result;
}

/* READ FORMAT CAPACITY command (23h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Read_Format_Capacity(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_READ_FORMATCAPACITY;
	g_usb_ms_cmd[8] = USBMS_READ_FORMATCAPACITY_DATA_LEN;

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_READ_FORMATCAPACITY_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = USBMS_READ_FORMATCAPACITY_DATA_LEN;
	g_UsbHostMs.ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;
	
	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch== KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer  */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL) 
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL  do not handle it */
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}
	
	return g_UsbHostMs.result;
}

/* READ CAPACITY command (25h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Read_Capacity(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_READ_CAPACITY;

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_READ_CAPACITY_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = USBMS_READ_CAPACITY_DATA_LEN;
	g_UsbHostMs.ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;
	
	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch== KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer  */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			/* store sector size and sector number info */
			g_UsbHostMs.media_info[lun].sec_num = (g_usb_ms_data[0]<<24) + (g_usb_ms_data[1]<<16)
												+ (g_usb_ms_data[2]<<8) + (g_usb_ms_data[3]<<0); 
			g_UsbHostMs.media_info[lun].sec_num++;
			g_UsbHostMs.media_info[lun].sec_size = (g_usb_ms_data[4]<<24) + (g_usb_ms_data[5]<<16)
												+ (g_usb_ms_data[6]<<8) + (g_usb_ms_data[7]<<0); 	
			/* Add error check */
			if(g_UsbHostMs.media_info[lun].sec_num>=0x400000)
			{
				g_UsbHostMs.media_info[lun].sec_num = 0;
				g_UsbHostMs.media_info[lun].sec_size = 0;	
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
				g_UsbHostMs.result = USB_HOST_MS_RESULT_FORMAT_ERROR;
			}									
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			g_UsbHostMs.media_info[lun].sec_num = 0;
			g_UsbHostMs.media_info[lun].sec_size = 0;
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL  do not handle it */
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}
	
	return g_UsbHostMs.result;
}

/* TEST UNIT READY command (00h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Test_Unit_Ready(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs.media_info[lun].state;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_TEST_UNIT_READY;

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_TEST_UNIT_READY_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = USBMS_TEST_UNIT_READY_DATA_LEN;
	g_UsbHostMs.ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_NONE;
	
	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch== KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			/* If data state is USB_HOST_MS_MEDIA_STATE_WR_PROTECT, it means data state is not changed,
			    do not change it to ready state */
			if(g_UsbHostMs.media_info[lun].state!=USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			/* media state will be changed in request sense handler */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL do not handle it */
	
		if(media_state!=g_UsbHostMs.media_info[lun].state)
		{
			if( (media_state == USB_HOST_MS_MEDIA_STATE_ABSENT) && 
				 (g_UsbHostMs.media_info[lun].state == USB_HOST_MS_MEDIA_STATE_CHANGED) )
			{
				//If only from absent to state change, do no notify FMT.
				//Otherwise some mass storage may first mount fail, and then success,
				//user may see plug out and then plug in 
			}
			else
			{
				//g_UsbHostMs.b_state_change = KAL_TRUE;
				g_UsbHostMs.media_state_change |= (1<<lun);
			}
		}
	}
	else
	{
		g_UsbHostMs.result = 	USB_HOST_MS_RESULT_TIMEOUT;
	}
	
	return g_UsbHostMs.result;
}

/* MODE SENSE6 command (1ah)*/
USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense6(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs.media_info[lun].state;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_MODE_SENSE6;
	g_usb_ms_cmd[2] = 0x1c;
	g_usb_ms_cmd[4] = USBMS_MODE_SENSE6_DATA_LEN;

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_MODE_SENSE6_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = USBMS_MODE_SENSE6_DATA_LEN;
	g_UsbHostMs.ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;
	
	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
	
		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			/* determine it is write protect or not */
			if((g_usb_ms_data[2]&0x80)!=0)
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_WR_PROTECT;
			else
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL) 
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL do not handle it */

		if(media_state!=g_UsbHostMs.media_info[lun].state)
		{
			if( (media_state == USB_HOST_MS_MEDIA_STATE_ABSENT) && 
				 (g_UsbHostMs.media_info[lun].state == USB_HOST_MS_MEDIA_STATE_CHANGED) )
			{
				//If only from absent to state change, do no notify FMT.
				//Otherwise some mass storage may first mount fail, and then success,
				//user may see plug out and then plug in 
			}
			else
			{
				//g_UsbHostMs.b_state_change = KAL_TRUE;
				g_UsbHostMs.media_state_change |= (1<<lun);
			}
		}
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}
	
	return g_UsbHostMs.result;

}

/* MODE SENSE6 All mode command (1ah)*/
USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense6_All_Mode(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs.media_info[lun].state;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_MODE_SENSE6;
	g_usb_ms_cmd[2] = 0x3f;
	g_usb_ms_cmd[4] = USBMS_MODE_SENSE6_DATA_LEN;

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_MODE_SENSE6_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = USBMS_MODE_SENSE6_DATA_LEN;
	g_UsbHostMs.ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;
	
	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
	
		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			/* determine it is write protect or not */
			if((g_usb_ms_data[2]&0x80)!=0)
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_WR_PROTECT;
			else
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL do not handle it */

		if(media_state!=g_UsbHostMs.media_info[lun].state)
		{
			if( (media_state == USB_HOST_MS_MEDIA_STATE_ABSENT) && 
				 (g_UsbHostMs.media_info[lun].state == USB_HOST_MS_MEDIA_STATE_CHANGED) )
			{
				//If only from absent to state change, do no notify FMT.
				//Otherwise some mass storage may first mount fail, and then success,
				//user may see plug out and then plug in 
			}
			else
			{
				//g_UsbHostMs.b_state_change = KAL_TRUE;
				g_UsbHostMs.media_state_change |= (1<<lun);
			}
		}
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}

	return g_UsbHostMs.result;

}

/* MODE SENSE6 All mode command (5ah)*/
USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense10_All_Mode(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs.media_info[lun].state;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_MODE_SENSE;
	g_usb_ms_cmd[2] = 0x3f;
	g_usb_ms_cmd[4] = USBMS_MODE_SENSE_DATA_LEN;

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_MODE_SENSE_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = USBMS_MODE_SENSE_DATA_LEN;
	g_UsbHostMs.ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;
	
	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
	
		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			/* determine it is write protect or not */
			if((g_usb_ms_data[2]&0x80)!=0)
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_WR_PROTECT;
			else
				g_UsbHostMs.media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL do not handle it */

		if(media_state!=g_UsbHostMs.media_info[lun].state)
		{
			if( (media_state == USB_HOST_MS_MEDIA_STATE_ABSENT) && 
				 (g_UsbHostMs.media_info[lun].state == USB_HOST_MS_MEDIA_STATE_CHANGED) )
			{
				//If only from absent to state change, do no notify FMT.
				//Otherwise some mass storage may first mount fail, and then success,
				//user may see plug out and then plug in 
			}
			else
			{
				//g_UsbHostMs.b_state_change = KAL_TRUE;
				g_UsbHostMs.media_state_change |= (1<<lun);
			}
		}
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}

	return g_UsbHostMs.result;

}

/* READ command (28h)*/
/* The received data will be stored in data parameter */
USB_HOST_MS_RESULT USB_Host_Ms_Read(kal_uint8 lun, kal_uint32 sec_start, kal_uint16 sec_num, kal_uint8* data)
{
	kal_bool b_send_result;
	kal_uint32 event_group;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_READ10;
	g_usb_ms_cmd[2] = (sec_start>>24)&0xff;
	g_usb_ms_cmd[3] = (sec_start>>16)&0xff;
	g_usb_ms_cmd[4] = (sec_start>>8)&0xff;
	g_usb_ms_cmd[5] = sec_start&0xff;	

	g_usb_ms_cmd[7] = (sec_num>>8)&0xff;
	g_usb_ms_cmd[8] = sec_num&0xff;	

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_READ_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = sec_num*g_UsbHostMs.media_info[lun].sec_size; 
	g_UsbHostMs.ms_cmd_data.data_buff = data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		g_UsbHostMs.b_rw_result = KAL_FALSE;
		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			/* In the application layer, result may be OK because of next request sense result is OK */
			/* This is used to indicate whether the whole data are read back successfully */
			g_UsbHostMs.b_rw_result = KAL_TRUE;
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL  do not handle it */
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}

	return g_UsbHostMs.result;
}

/* WRITE command (2ah)*/
/* The data parameter will be sent out */
USB_HOST_MS_RESULT USB_Host_Ms_Write(kal_uint8 lun, kal_uint32 sec_start, kal_uint16 sec_num, kal_uint8* data)
{
	kal_bool b_send_result;
	kal_uint32 event_group;

	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_WRITE10;
	g_usb_ms_cmd[2] = (sec_start>>24)&0xff;
	g_usb_ms_cmd[3] = (sec_start>>16)&0xff;
	g_usb_ms_cmd[4] = (sec_start>>8)&0xff;
	g_usb_ms_cmd[5] = sec_start&0xff;	

	g_usb_ms_cmd[7] = (sec_num>>8)&0xff;
	g_usb_ms_cmd[8] = sec_num&0xff;	

	g_UsbHostMs.ms_cmd_data.lun = lun;
	g_UsbHostMs.ms_cmd_data.cmd_len = USBMS_WRITE_CMD_LEN;
	g_UsbHostMs.ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs.ms_cmd_data.data_len = sec_num*g_UsbHostMs.media_info[lun].sec_size; 
	g_UsbHostMs.ms_cmd_data.data_buff = data;
	g_UsbHostMs.ms_cmd_data.data_dir = USB_HOST_MS_DATA_SEND;

	b_send_result = USB_Host_Ms_Send_Cmd(&g_UsbHostMs.ms_cmd_data);

	if((b_send_result==KAL_TRUE)&&(g_UsbHostMs.dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		g_UsbHostMs.b_rw_result = KAL_FALSE;
		if(g_UsbHostMs.result == USB_HOST_MS_RESULT_OK)
		{
			/* In the application layer, result may be OK because of next request sense result is OK */
			/* This is used to indicate whether the whole data are written out  successfully */
			g_UsbHostMs.b_rw_result = KAL_TRUE;
		}
		else if(g_UsbHostMs.result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs.result = USB_Host_Ms_Request_Sense(lun);
		}
		/* else USB_HOST_MS_RESULT_TIMEOUT and USB_HOST_MS_RESULT_STALL  do not handle it */
	}
	else
	{
		g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
	}
	
	return g_UsbHostMs.result;
}

/* Construct the CBW format, and send command to scheduling queue*/ 
static kal_bool USB_Host_Ms_Send_Cmd(USBH_Ms_Cmd_Struct *ms_cmd)
{ 
	UsbMs_CBW *CBW = (UsbMs_CBW*)g_UsbHostMs.CBWdata;

	/* construct CBW according to to the aommand request */
	CBW->dCBWSignature = 0x43425355;
	CBW->dCBWTag = g_UsbHostMs.CBWdata[1] +1;  /* increment tag in each command */
	CBW->dCBWDataTransferLength = ms_cmd->data_len;
	if(ms_cmd->data_dir==USB_HOST_MS_DATA_RECV)
		CBW->bmCBWFlags = USBMS_DIR_IN;
	else
		CBW->bmCBWFlags = USBMS_DIR_OUT;
	CBW->bCBWLUN = ms_cmd->lun;
	CBW->bCBWCBLength = ms_cmd->cmd_len;
	/* the CBWCB comes from each command. ex READ, WRITE, TEST UNIT READY.*/
	/* the format is different according to each command */
	kal_mem_set(CBW->CBWCB, 0, USBMS_CBW_LENGTH);
	kal_mem_cpy(CBW->CBWCB, ms_cmd->cmd_buff, ms_cmd->cmd_len);

	/* assign the data buffer */
	/* In OUT direction, the data will be sent during transfer */
	/* In IN direction, the received data will be stored in this buffer */
	g_UsbHostMs.data = ms_cmd->data_buff;
	g_UsbHostMs.data_length = ms_cmd->data_len;
	g_UsbHostMs.data_dir = ms_cmd->data_dir;
	/* Note that in the recv direction, receive buffer must be pad to multiple of 4 */
	if((g_UsbHostMs.data_dir==USB_HOST_MS_DATA_RECV)&&(g_UsbHostMs.data_length&0x3))
	{
		g_UsbHostMs.data_length = g_UsbHostMs.data_length
							+ (4-(USBMS_REQUESTSENSE_DATA_LEN & 0x3));;
	}

	g_UsbHostMs.ms_state = USB_HOST_MS_CBW;

	/* Queue command to scheduling buffer*/
	/* Note that CBW, DATA, CSW transfer is handled in HISR level,
	    And when the transfer complete, it will retrive the event to wake up waiting task */
	return USB_HCD_Send_Req(g_UsbHostMs.ep_out_index, USBMS_CBW_LENGTH, CBW);
} 



/************************************************************
	ms class handler. Note that it is executed in OTG HIST context
*************************************************************/

/* This is callback function for both control EP and bulk EP */
/* The control EP part handles class specific EP0 command
     The bulk EP part handles CBW, DATA, CSW state machine */
static void USB_Host_Ms_Hdlr(USB_HCD_STATUS result, kal_uint32 param)
{
	if(g_UsbHostMs.ms_cmd != USB_HOST_MS_EP0_CMD_NONE)
	{
		USB_Host_Ms_Ctrl_EP_Hdlr(result, param);

	}

	else 

	{

		USB_Host_Ms_Bulk_EP_Hdlr(result, param);

	}	
}

/* handler for control endpoint */
/* It handles both standard and class specific EP0 command*/
static void USB_Host_Ms_Ctrl_EP_Hdlr(USB_HCD_STATUS result, kal_uint32 param)
{
	/* store the command because it will be chaneg immediatly*/
	USB_HOST_MS_EP0_CMD ms_cmd = g_UsbHostMs.ms_cmd;
	kal_bool tr_result;

	/* Unless another EP0 command is issued, the command should be set to NONE*/
	g_UsbHostMs.ms_cmd = USB_HOST_MS_EP0_CMD_NONE;

	if(result!=USB_HCD_OK)
	{
		/* translate the result */
		/* for EP0 error, the handler dose not do error handling,
		    the error handling is done in the upper layer state */
		if(result == USB_HCD_STALL)
			g_UsbHostMs.result = USB_HOST_MS_RESULT_STALL;
		else
			g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
		kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);		
	}		
	else
	{
		/* result is OK */
		switch(ms_cmd)
		{
		case USB_HOST_MS_EP0_CMD_RESET:

			g_UsbHostMs.result = USB_HOST_MS_RESULT_OK;

			kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);		

			break;
		case USB_HOST_MS_EP0_CMD_GET_LUN:
			g_UsbHostMs.result = USB_HOST_MS_RESULT_OK;
			kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);		
			break;
		case USB_HOST_MS_EP0_CMD_CLEAR_STALL_IN:
		case USB_HOST_MS_EP0_CMD_CLEAR_STALL_OUT:
			/* Clear IN or clear OUT stall are completed,
			    The next action is determined according to the previous state before STALL*/
			if(g_UsbHostMs.ms_state==USB_HOST_MS_CBW_CLEAR_STALL)

			{
				/* The CBW is stalled. Do not issue DATA or CSW any more.
				    Return STALL result and let upper layer state machine handle it */

				g_UsbHostMs.result = USB_HOST_MS_RESULT_STALL;

				kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);		

			}	

			else if(g_UsbHostMs.ms_state==USB_HOST_MS_DATA_CLEAR_STALL)

			{
				/* DATA is stalled. Clear STALL and attepmt to receive CSW */

				/* Send CSW */

				tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, sizeof(g_UsbHostMs.CSW)/sizeof(kal_uint8), &g_UsbHostMs.CSW);

				if(tr_result==KAL_TRUE)
				{
					g_UsbHostMs.ms_state = USB_HOST_MS_CSW;
				}
				else
				{
					g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
					kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
				}

			}

			else if(g_UsbHostMs.ms_state==USB_HOST_MS_CSW_CLEAR_STALL)

			{
				/* CSW is stalled. Clear STALL and attepmt to receive CSW */

				/* send CSW */

				tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, sizeof(g_UsbHostMs.CSW)/sizeof(kal_uint8), &g_UsbHostMs.CSW);

				if(tr_result==KAL_FALSE)
				{
					g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
					kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
				}

			}

			else

			{
				/* In all other states, it should not come to EP0 handler */

				EXT_ASSERT(0, ms_cmd, g_UsbHostMs.ms_state, 0);

			}

			break;

		}	

	}	
}


/* handler for ctrl endpoint */
/* It handles CBW, DATA, CSW state machine */
static void USB_Host_Ms_Bulk_EP_Hdlr(USB_HCD_STATUS result, kal_uint32 param)
{
	if(g_UsbHostMs.ms_state == USB_HOST_MS_CBW)
	{
		USB_Host_Ms_CBW_Hdler(result, param);
	}
	else if(g_UsbHostMs.ms_state == USB_HOST_MS_DATA)
	{
		USB_Host_Ms_DATA_Hdler(result, param);
	}
	else if((g_UsbHostMs.ms_state == USB_HOST_MS_CSW) || (g_UsbHostMs.ms_state == USB_HOST_MS_CSW_CLEAR_STALL))
	{
		USB_Host_Ms_CSW_Hdler(result, param);
	}
	else
	{
		/* Note that in USB_HOST_MS_CBW_CLEAR_STALL and USB_HOST_MS_DATA_CLEAR_STALL state,
		    only ctrl EP handler should be called, but not enter this bulk EP handler*/
		EXT_ASSERT(0, g_UsbHostMs.ms_state, 0, 0);
	}
}


/* Ctrl EP CBW handler, handle the state mcahine */
static void USB_Host_Ms_CBW_Hdler(USB_HCD_STATUS result, kal_uint32 param)
{
	kal_bool tr_result;
		
	if(result==USB_HCD_OK)

	{

		/* chek the real sent out length */	
		if(param!=USBMS_CBW_LENGTH)

			EXT_ASSERT(0, param, 0, 0);

		

		if(g_UsbHostMs.data_length !=0)

		{
			/* DATA state should be the following state */

			/* Since data length is not zero, data direction must not NONE */

			if(g_UsbHostMs.data_dir == USB_HOST_MS_DATA_NONE)

				EXT_ASSERT(0, g_UsbHostMs.data_dir, g_UsbHostMs.data_length, 0);

				

			if(g_UsbHostMs.data_dir ==USB_HOST_MS_DATA_RECV)

			{
				/* Receive data */

				if(g_UsbHostMs.data_length > USBMS_MAX_DATA_LENGTH)

				{	
					/* DMA length has limit, so each transfer request should should have size limit */

					tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, USBMS_MAX_DATA_LENGTH, g_UsbHostMs.data);

					if(tr_result==KAL_TRUE)
					{
						g_UsbHostMs.sending_data_length = USBMS_MAX_DATA_LENGTH;
						g_UsbHostMs.remain_data_length = g_UsbHostMs.data_length - USBMS_MAX_DATA_LENGTH;
						g_UsbHostMs.sent_data_length = 0;
					}
					else
					{
						g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
						kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
					}	
				}

				else

				{
					/* Prepare to recieve the whole data */

					tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, g_UsbHostMs.data_length, g_UsbHostMs.data);

					if(tr_result==KAL_TRUE)
					{
						g_UsbHostMs.sending_data_length = g_UsbHostMs.data_length;
						g_UsbHostMs.remain_data_length = 0;
						g_UsbHostMs.sent_data_length = 0;
					}
					else
					{
						g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
						kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
					}
				}	

			}

			else

			{

				/* Send data*/
				if(g_UsbHostMs.data_length > USBMS_MAX_DATA_LENGTH)

				{
					/* DMA length has limit, so each transfer request should should have size limit */

					tr_result = USB_HCD_Send_Req(g_UsbHostMs.ep_out_index, USBMS_MAX_DATA_LENGTH, g_UsbHostMs.data);

					if(tr_result==KAL_TRUE)
					{
						g_UsbHostMs.sending_data_length = USBMS_MAX_DATA_LENGTH;
						g_UsbHostMs.remain_data_length = g_UsbHostMs.data_length - USBMS_MAX_DATA_LENGTH;
						g_UsbHostMs.sent_data_length = 0;
					}
					else
					{
						g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
						kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
					}
				}

				else

				{
					/* Send the whole data out */

					tr_result = USB_HCD_Send_Req(g_UsbHostMs.ep_out_index, g_UsbHostMs.data_length, g_UsbHostMs.data);

					if(tr_result==KAL_TRUE)
					{
						g_UsbHostMs.sending_data_length = g_UsbHostMs.data_length;
						g_UsbHostMs.remain_data_length = 0;
						g_UsbHostMs.sent_data_length = 0;
					}
					else
					{
						g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
						kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
					}
				}

			}

			/* change to DATA state */

			g_UsbHostMs.ms_state = USB_HOST_MS_DATA;

		}

		else

		{
			/* CSW state should be the following state */

			/* Send CSW */

			tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, sizeof(g_UsbHostMs.CSW)/sizeof(kal_uint8), &g_UsbHostMs.CSW);

			if(tr_result==KAL_TRUE)
				g_UsbHostMs.ms_state = USB_HOST_MS_CSW;
			else
			{
				g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
				kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
			}

		}
	}
	else if(result == USB_HCD_STALL)
	{
		/* CBW is OUT endpoint, so clear STALL OUT */
		g_UsbHostMs.ms_state = USB_HOST_MS_CBW_CLEAR_STALL;

		g_UsbHostMs.ms_cmd = USB_HOST_MS_EP0_CMD_CLEAR_STALL_OUT;

		/* clear data01 */
		USB_HCD_Clear_Data01(g_UsbHostMs.ep_out_index);
		
		USBD_Clear_Stall(g_UsbHostMs.ep_out_num, USB_TX_EP_TYPE);
	}
	else
	{
		if(result==USB_HCD_DETATCH)
		{
			g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
		}
		else
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
		}

		kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
	}
}

/* Ctrl EP DATA handler, handle the state mcahine */
static void USB_Host_Ms_DATA_Hdler(USB_HCD_STATUS result, kal_uint32 param)
{
	kal_bool tr_result;

	if(result==USB_HCD_OK)

	{

		g_UsbHostMs.sent_data_length+=param;

				
		/* In case some device may return 0 first and then real data, so check sent data length */
		if((g_UsbHostMs.sending_data_length!=param) &&(g_UsbHostMs.sent_data_length!=0))

		{
			/* The real send/receive length is not the expected length */

			/* No matter the remaining data length, end the data phase directly*/

			/* Check whether the data is CSW or not, if yes, enter CSW Hdler directly*/
			if((param == USBMS_CSW_LENGTH) && (g_UsbHostMs.data[0] == 0x55) && (g_UsbHostMs.data[1] == 0x53)
				&& (g_UsbHostMs.data[2] == 0x42) && (g_UsbHostMs.data[3] == 0x53))
			{
				kal_mem_cpy((kal_uint8*)&g_UsbHostMs.CSW, g_UsbHostMs.data, USBMS_CSW_LENGTH);
				USB_Host_Ms_CSW_Hdler(result, param);
				return;
			}

			/* Send CSW, and enter CSW state */

			tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, sizeof(g_UsbHostMs.CSW)/sizeof(kal_uint8), &g_UsbHostMs.CSW);

			if(tr_result==KAL_TRUE)
				g_UsbHostMs.ms_state = USB_HOST_MS_CSW;
			else
			{
				g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
				kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
			}
		}

		else

		{

			/* In case some device may return 0 first and then real data, so check sent data length */
			if(g_UsbHostMs.sent_data_length==0)
				g_UsbHostMs.remain_data_length+=g_UsbHostMs.sending_data_length;
				
			if(g_UsbHostMs.remain_data_length!=0)

			{
				/* More data need to send/receive */

				if(g_UsbHostMs.data_dir == USB_HOST_MS_DATA_NONE)

					EXT_ASSERT(0, g_UsbHostMs.data_dir, g_UsbHostMs.data_length, g_UsbHostMs.remain_data_length);

					

				if(g_UsbHostMs.data_dir ==USB_HOST_MS_DATA_RECV)

				{
					/* Receive data */

					if(g_UsbHostMs.remain_data_length > USBMS_MAX_DATA_LENGTH)

					{
						/* DMA length has limit, so each transfer request should should have size limit */

						tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, USBMS_MAX_DATA_LENGTH, (g_UsbHostMs.data+g_UsbHostMs.sent_data_length));

						if(tr_result==KAL_TRUE)
						{
							g_UsbHostMs.sending_data_length = USBMS_MAX_DATA_LENGTH;
							g_UsbHostMs.remain_data_length = g_UsbHostMs.remain_data_length - USBMS_MAX_DATA_LENGTH;
						}
						else
						{
							g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
							kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
						}
					}

					else

					{
						/* Prepare to recieve the whole data */

						tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, g_UsbHostMs.remain_data_length, (g_UsbHostMs.data+g_UsbHostMs.sent_data_length));

						if(tr_result == KAL_TRUE)
						{
							g_UsbHostMs.sending_data_length = g_UsbHostMs.remain_data_length;
							g_UsbHostMs.remain_data_length = 0;
						}
						else
						{
							g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
							kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
						}
					}

				}

				else

				{
					/* Send data */

					if(g_UsbHostMs.remain_data_length > USBMS_MAX_DATA_LENGTH)

					{
						/* DMA length has limit, so each transfer request should should have size limit */

						tr_result = USB_HCD_Send_Req(g_UsbHostMs.ep_out_index, USBMS_MAX_DATA_LENGTH, (g_UsbHostMs.data+g_UsbHostMs.sent_data_length));

						if(tr_result==KAL_TRUE)
						{
							g_UsbHostMs.sending_data_length = USBMS_MAX_DATA_LENGTH;	
							g_UsbHostMs.remain_data_length = g_UsbHostMs.remain_data_length - USBMS_MAX_DATA_LENGTH;
						}
						else
						{
							g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
							kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
						}
					}

					else

					{
						/* Send the whole data out */

						tr_result = USB_HCD_Send_Req(g_UsbHostMs.ep_out_index, g_UsbHostMs.remain_data_length, (g_UsbHostMs.data+g_UsbHostMs.sent_data_length));

						if(tr_result==KAL_TRUE)
						{
							g_UsbHostMs.sending_data_length = g_UsbHostMs.remain_data_length;
							g_UsbHostMs.remain_data_length = 0;
						}
						else
						{
							g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
							kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
						}
					}

				}

				/* Still in DATA state */

				g_UsbHostMs.ms_state = USB_HOST_MS_DATA;

			}

			else

			{

				/* CSW state should be the following state */

				/* Send CSW */

				tr_result = USB_HCD_Recv_Req(g_UsbHostMs.ep_in_index, sizeof(g_UsbHostMs.CSW)/sizeof(kal_uint8), &g_UsbHostMs.CSW);
								
				if(tr_result ==KAL_TRUE)
					g_UsbHostMs.ms_state = USB_HOST_MS_CSW;					
				else
				{
					g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
					kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
				}
			}	

		}	
	}
	else if(result == USB_HCD_STALL)
	{
		/* Clear data stall acoording to data direction */
		if(g_UsbHostMs.data_dir ==USB_HOST_MS_DATA_RECV)
		{
			g_UsbHostMs.ms_state = USB_HOST_MS_DATA_CLEAR_STALL;

			g_UsbHostMs.ms_cmd = USB_HOST_MS_EP0_CMD_CLEAR_STALL_IN;

			/* clear data01 */
			USB_HCD_Clear_Data01(g_UsbHostMs.ep_in_index);
		
			USBD_Clear_Stall(g_UsbHostMs.ep_in_num, USB_RX_EP_TYPE);	
		}
		else
		{
			g_UsbHostMs.ms_state = USB_HOST_MS_DATA_CLEAR_STALL;

			g_UsbHostMs.ms_cmd = USB_HOST_MS_EP0_CMD_CLEAR_STALL_OUT;

			/* clear data01 */
			USB_HCD_Clear_Data01(g_UsbHostMs.ep_out_index);
		
			USBD_Clear_Stall(g_UsbHostMs.ep_out_num, USB_TX_EP_TYPE);
		}
	}
	else
	{
		if(result==USB_HCD_DETATCH)
		{
			g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
		}
		else
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
		}

		kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
	}
}	

/* Ctrl EP CSW handler, handle the state mcahine */
static void USB_Host_Ms_CSW_Hdler(USB_HCD_STATUS result, kal_uint32 param)
{
	if(result==USB_HCD_OK)

	{
		/* translate state to be NONE */
	
		g_UsbHostMs.ms_state = USB_HOST_MS_NONE;

		/* chek the real received length */	

		if(param!=USBMS_CSW_LENGTH)
		{
			//EXT_ASSERT(0, param, 0, 0);	
			g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
		}
		else
		{
			/* Check CSW result */
	
			if(g_UsbHostMs.CSW.bmCSWStatus == KAL_TRUE)

				g_UsbHostMs.result = USB_HOST_MS_RESULT_CSW_FAIL;

			else

				g_UsbHostMs.result = USB_HOST_MS_RESULT_OK;
		}

		/* Notify application that the whole CBW, DATA, CSW is completed */

		kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
	}
	else if(result == USB_HCD_STALL)
	{
		 if(g_UsbHostMs.ms_state == USB_HOST_MS_CSW)
		{
			/* Receive STALL in the first CSW, clear stall and try CSW again after clear stall */

			g_UsbHostMs.ms_state = USB_HOST_MS_CSW_CLEAR_STALL;

			g_UsbHostMs.ms_cmd = USB_HOST_MS_EP0_CMD_CLEAR_STALL_IN;

			/* clear data01 */
			USB_HCD_Clear_Data01(g_UsbHostMs.ep_in_index);
			
			USBD_Clear_Stall(g_UsbHostMs.ep_in_num, USB_RX_EP_TYPE);

		}

		else if(g_UsbHostMs.ms_state == USB_HOST_MS_CSW_CLEAR_STALL)

		{
			/* Receive STALL in the second CSW. Do not issue CSW any more
			     Notify application to handle the STALL result */

			g_UsbHostMs.result = USB_HOST_MS_RESULT_STALL;

			kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);

		}
	}
	else
	{
		if(result==USB_HCD_DETATCH)
		{
			g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
		}
		else
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs.result = USB_HOST_MS_RESULT_TIMEOUT;
		}

		kal_set_eg_events(g_UsbHostMs.event_id, EVENT_USB_MS_DONE, KAL_OR);
	}
}


#endif  /* __OTG_ENABLE__ */

 
