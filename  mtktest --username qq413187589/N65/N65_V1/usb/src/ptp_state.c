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
*  A. Patent Notice:
*  The software delivered hereunder, including any and all updates and upgrades, 
*  might be subject to patent rights of standard-setting organizations, patent pools 
*  or their respective patent owners, that will be necessarily infringed by the use 
*  and distribution of the products incorporating all or part of this software.  
*  According to the licensing terms of these patent holders, it is your sole 
*  obligation to obtain the necessary patent licenses from these patent holders 
*  before you can use or distribute the products incorporating all or part of this 
*  software. MediaTek shall not be liable for your failure to obtain or maintain such 
*  licenses.
*  
*    As a courtesy to our customers, the following are some of the software that might 
*    contain such patent licenses, but MediaTek does not warrant the accuracy or
*    completeness of the information below.  
*    (1) MPEG4/AAC/AACPLUS/AACVPLUSV2: essential patents license must be obtained
*        from Via Licensing: <www.vialicensing.com>
*    (2) WAP/MMS security RC5 algorithm belongs to RSA Data Security: 
*        <www.rsasecurity.com> 
*    Notice: Please contact RSA to get this license before shipping the products to 
*    USA which include RC5 security algorithm.
*  
*  B. In addition, customers must contact the respective licensors to obtain 
*  necessary software licenses before it can use or distribute the licensed 
*  products. 
*  
*    As a courtesy to our customers, the following are some of the software licensers 
*    and the notice or disclaimer required by their licenses, but MediaTek does not 
*    warrant the accuracy or completeness of the information below.  
*    (1) Microsoft Windows Media (WMA software): 
*        Microsoft: <www.microsoft.com> 
*        Approved OEM Manufacturers: <wmlicense.smdisp.net/oem_approved/>
*        Sample Windows Media Licensing Agreements: 
*        <www.microsoft.com/windows/windowsmedia/licensing/agreements.aspx>
*    Notice in header or documentation: "This product is protected by certain 
*    intellectual property rights of Microsoft and cannot be used or further 
*    distributed without a license from Microsoft."
*    
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ptp_state.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements the PICTURE TRANSFER PROTOCOL state machine and related functions
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
#include "fat_fs.h"
#include "fs_type.h"
#include "exif.h"

#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usb_resource.h"

#include "usb_custom.h"
#include "usbimage_drv.h"
#include "ptp_state.h"
#include "usb_debug_tool.h"

#include "drm_gprot.h"

#ifdef PICTBRIDGE_SUPPORT

/* global variables */
PTP_Struct			g_USBImage;
static   kal_uint32		g_objecthandles[PTP_MAX_OBJECT_HANDLES];

/* static functions */
static void PTP_Image_DATA_RX_Hdlr(void);
static void PTP_Image_DMA_TX_Hdlr(void);

static void PTP_Copy_From_PTP_String(void *pdest, const kal_uint16 *source_string, kal_uint8 string_num);
static void PTP_Copy_From_PTP_Handle_Array(void *pdest, kal_uint32 *source_array, kal_uint32 array_num);
static void PTP_Date_to_String(void *pdest, FS_DOSDateTime time);
static void PTP_Close_File(void);

static void PTP_Image_Operation(void);
static void PTP_Cmd_Get_Device_Info(void);
static void PTP_Cmd_Open_Session(void);
static void PTP_Cmd_Close_Session(void);
static void PTP_Cmd_Get_Storage_Ids(void);
static void PTP_Cmd_Get_Storage_Info(void);
static void PTP_Cmd_Get_Num_Objects(void);
static void PTP_Cmd_Get_Object_Handles(void);
static void PTP_Cmd_Get_Object_Info(void);
static void PTP_Cmd_Get_Object(void);
static void PTP_Cmd_Get_Thumb(void);
static void PTP_Cmd_Get_Partial_Object(void);
static void PTP_Get_Object_Hdlr(void);
static void PTP_Send_Object_Hdlr(void);
static void PTP_Cmd_Unknown(void);

/* extern functions */
extern FS_HANDLE mmi_pict_return_print_file_handle_with_filepath(kal_uint32 obj_handle,  kal_uint16 *filepath, kal_uint16 *max_filepath_length);
extern FS_HANDLE mmi_pict_return_print_file_handle_with_filename(kal_uint32 obj_handle, kal_uint16 *filename, kal_uint16 *max_filename_length);
#ifdef __DRM_SUPPORT__
extern int mmi_pict_return_current_print_file_info(FS_DOSDirEntry *info);
#endif

/************************************************************
	Parse all messages to USB task for PTP state
*************************************************************/
void PTP_Parse_MMI_Meg(ilm_struct *p_recv_ilm)
{
	usb_image_xml_struct *ptr = (usb_image_xml_struct *)p_recv_ilm->local_para_ptr;

	switch(p_recv_ilm->msg_id)
	{
	case MSG_ID_MMI_USB_DPS_HREQUEST_CONF:
		USB_Dbg_Trace(USB_DBG_DPS_HREQUEST_CONF, drv_get_current_time(), 0, 0);
		if((g_USBImage.script_flag&(1<<HREQUEST)) == 0)
		{
			/* Remove assert because MMI's priority is lower than USB, so it just handles every message */
			/* Printer send two HREQUESTs to target */
//			EXT_ASSERT(0, g_USBImage.script_flag, 0, 0);
		#ifndef  __PRODUCTION_RELEASE__
			USB_Dbg_Trace(USB_DBG_DPS_HREQUEST_CONF_CANCEL, drv_get_current_time(), 0, 0);
			kal_prompt_trace(MOD_USB, "WARNING!! 2 HREQUEST");
		#endif
		}
		else
		{
			g_USBImage.script_flag &= ~(1<<HREQUEST);

			g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
			g_USBImage.image_event.Code = PTP_OBJECT_REMOVED;
			g_USBImage.image_event.TransactionID = 0xffffffff;
			g_USBImage.image_event.Parameter1 = 	HREQUEST_DPS;
//			USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
			USB_Image_Send_Intr();	
		}
		break;

	case MSG_ID_MMI_USB_DPS_HRESPONSE_CONF:
		USB_Dbg_Trace(USB_DBG_DPS_HRESPONSE_CONF, drv_get_current_time(), 0, 0);
		if((g_USBImage.script_flag&(1<<HRSPONSE)) == 0)
			EXT_ASSERT(0, g_USBImage.script_flag, 0, 0);
		
		g_USBImage.script_flag &= ~(1<<HRSPONSE);

		g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
		g_USBImage.image_event.Code = PTP_OBJECT_REMOVED;
		g_USBImage.image_event.TransactionID = 0xffffffff;
		g_USBImage.image_event.Parameter1 = 	HRSPONSE_DPS;
//		USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
		USB_Image_Send_Intr();	
		break;

	case MSG_ID_MMI_USB_DPS_DREQUEST_REQ:
		USB_Dbg_Trace(USB_DBG_DPS_DREQUEST_REQ, drv_get_current_time(), 0, 0);

#ifndef  __PRODUCTION_RELEASE__
		/* When printer hang, it will not receive XML, so we canno assert here */
		if((g_USBImage.script_flag&(1<<DREQUEST)) != 0)
		{
//			EXT_ASSERT(0, g_USBImage.script_flag, 0, 0);
			kal_prompt_trace(MOD_USB, "WARNING!! 2 DREQUEST");
			USB_Dbg_Trace(USB_DBG_DPS_2_DREQUEST_REQ_WARNING, drv_get_current_time(), 0, 0);
		}
#endif
		
		if(g_USBImage.next_xml_is_start_job == KAL_TRUE)
		{
			g_USBImage.is_start_job_xml = KAL_TRUE;
//			g_USBImage.next_xml_is_start_job = KAL_FALSE;
		}

		g_USBImage.script_flag |= 1<<DREQUEST;
		g_USBImage.is_wait_host_respone = KAL_TRUE;
		g_USBImage.send_dps_request_xml_size = ptr->xml_packet_size;
		
		g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
		g_USBImage.image_event.Code = PTP_OBJECT_ADDED;
		g_USBImage.image_event.TransactionID = 0xffffffff;
		g_USBImage.image_event.Parameter1 = DREQUEST_DPS;
//		USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
		USB_Image_Send_Intr();	
		
		/* second interrupt packet */
		g_USBImage.image_event.Code = PTP_REQUEST_OBJECT_TRANSFER;
//		USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
		USB_Image_Send_Intr();	
		break;

	case MSG_ID_MMI_USB_DPS_DRESPONSE_REQ:
		USB_Dbg_Trace(USB_DBG_DPS_DRESPONSE_REQ, drv_get_current_time(), 0, 0);
		/* When DPS response, it cannot have a DPS request */
//		if((g_USBImage.script_flag&(1<<DRSPONSE)) != 0)
		if((g_USBImage.script_flag&((1<<DRSPONSE)|(1<<DREQUEST))) != 0)
			EXT_ASSERT(0, g_USBImage.script_flag, 0, 0);
		
		g_USBImage.script_flag |= 1<<DRSPONSE;
		g_USBImage.send_dps_response_xml_size = ptr->xml_packet_size;
		
		g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
		g_USBImage.image_event.Code = PTP_OBJECT_ADDED;
		g_USBImage.image_event.TransactionID = 0xffffffff;
		g_USBImage.image_event.Parameter1 = DRSPONSE_DPS;
//		USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
		USB_Image_Send_Intr();		
		/* second interrupt packet */
		g_USBImage.image_event.Code = PTP_REQUEST_OBJECT_TRANSFER;
//		USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
		USB_Image_Send_Intr();	
		break;

	case MSG_ID_MMI_USB_PTP_HOST_RESET_CNF:
		g_USBImage.ptp_stop = KAL_FALSE;

		if(g_USBImage.dps_discovery == KAL_TRUE)
			USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_DISCOVERY_IND, 0, 0);
		break;

		/*  USB receive this message before start job xml */
	case MSG_ID_MMI_USB_START_JOB_REQ:
		USB_Dbg_Trace(USB_DBG_DPS_START_JOB_REQ, drv_get_current_time(), 0, 0);
		if(g_USBImage.mmi_start_job == KAL_TRUE)
			ASSERT(0);
		
		g_USBImage.mmi_start_job = KAL_TRUE;
		g_USBImage.next_xml_is_start_job = KAL_TRUE;
		g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
		g_USBImage.image_event.Code = PTP_STORE_ADDED;
		g_USBImage.image_event.TransactionID = 0xffffffff;
		g_USBImage.image_event.Parameter1 = PTP_IMAGE_STORAGE_ID;
//		USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
		USB_Image_Send_Intr();
		break;

		/*  USB receive this message after job done or aborted */
	case MSG_ID_MMI_USB_CLOSE_JOB_REQ:
		USB_Dbg_Trace(USB_DBG_DPS_CLOSE_JOB_REQ, drv_get_current_time(), 0, 0);
		if(g_USBImage.mmi_start_job == KAL_FALSE)
			ASSERT(0);
		
		g_USBImage.mmi_start_job = KAL_FALSE;		
		g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
		g_USBImage.image_event.Code = PTP_STORE_REMOVED;
		g_USBImage.image_event.TransactionID = 0xffffffff;
		g_USBImage.image_event.Parameter1 = PTP_ALL_STORAGE_ID;
//		USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
		USB_Image_Send_Intr();

		if(g_USBImage.current_file_handle != PTP_NO_HANDLE	)
		{
	#ifdef __DRM_SUPPORT__
			DRM_close_file(g_USBImage.current_file_handle);
	#else
			FS_Close(g_USBImage.current_file_handle);
	#endif
			g_USBImage.current_file_handle = PTP_NO_HANDLE;
		}
		break;

	default:
		EXT_ASSERT(0, p_recv_ilm->msg_id, (kal_uint32)g_USBImage.state, 0);
		break;
	}
}


void PTP_Parse_USB_Meg(ilm_struct *p_recv_ilm)
{
	switch(p_recv_ilm->msg_id)
	{
	case MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF:
		/* received data from USB_HISR */
		PTP_Image_DATA_RX_Hdlr();
		break;
	case MSG_ID_USB_PTPIMAGE_DMA_TX_DONE_CONF:
		/* transmitted data from DMA callback*/
		PTP_Image_DMA_TX_Hdlr();
		break;
	case MSG_ID_USB_PTPIMAGE_RESET_IND:
		/* reset from reset signal */
		g_USBImage.state = PTP_CMD_RX;

		if(g_USBImage.dps_discovery == KAL_TRUE)
		{
			g_USBImage.ptp_stop = KAL_TRUE;
		}

		USB_Image_Reset_Hdlr();
		break;
	default:
		EXT_ASSERT(0, p_recv_ilm->msg_id, (kal_uint32)g_USBImage.state, 0);
		break;
	}
}


/* RX path state machine */
static void PTP_Image_DATA_RX_Hdlr(void)
{
	switch(g_USBImage.state)
	{
	case PTP_CMD_RX:
		/* parse PTP cmd */
		PTP_Image_Operation();
		break;
	case PTP_RESPONSE:
		g_USBImage.state = PTP_CMD_RX;
		/* Send object (info) handler and send response to host */
		PTP_Send_Object_Hdlr();
		break;
	case PTP_DATA_RX:
	case PTP_DATA_TX:
	default:
		EXT_ASSERT(0, (kal_uint32)g_USBImage.state, 0, 0);
		break;
	}
}


/* TX path state machine */
static void PTP_Image_DMA_TX_Hdlr(void)
{
	switch(g_USBImage.state)
	{
	/* Send Response */
	case PTP_RESPONSE:
		g_USBImage.state = PTP_CMD_RX;

		if(g_USBImage.error == KAL_FALSE)
		{
			/* Send message to notify MMI that XML packet has sent to host */
			if(g_USBImage.image_cmd.Code == PTP_GET_OBJECT)
			{
				if(g_USBImage.image_cmd.Parameter1 == DREQUEST_DPS)
				{
					USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_DREQUEST_CONF, 0, 0);

					if((g_USBImage.script_flag&(1<<DREQUEST)) == 0)
						EXT_ASSERT(0, g_USBImage.script_flag, 0, 0);
		
					g_USBImage.script_flag &= ~(1<<DREQUEST);

					if((g_USBImage.next_xml_is_start_job == KAL_TRUE)&&(g_USBImage.is_start_job_xml == KAL_TRUE))
					{
						g_USBImage.is_start_job_xml = KAL_FALSE;
						g_USBImage.next_xml_is_start_job = KAL_FALSE;
					}
				}
				else if(g_USBImage.image_cmd.Parameter1 == DRSPONSE_DPS)
				{
					USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_DRESPONSE_CONF, 0, 0);
			
					if((g_USBImage.script_flag&(1<<DRSPONSE)) == 0)
						EXT_ASSERT(0, g_USBImage.script_flag, 0, 0);
			
					g_USBImage.script_flag &= ~(1<<DRSPONSE);
				}
				g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
				g_USBImage.image_event.Code = PTP_OBJECT_REMOVED;
				g_USBImage.image_event.TransactionID = 0xffffffff;
				g_USBImage.image_event.Parameter1 = 	g_USBImage.image_cmd.Parameter1;
//				USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
				USB_Image_Send_Intr();
			}

		#ifdef USB_20_ENABLE	
			/*  Check if already sent out the (max pkt size)*N bytes */
			if(USB_Is_High_Speed() == KAL_TRUE)
			{
				/*  Check if sent out the 512N bytes */
				if((g_USBImage.total_tx_bytes%USB_EP_BULK_MAXP_HS) == 0)
				{
					USB_Send_Null_Packet(g_USBImage.txpipe->byEP);
				}
			}
			else
			{
				/*  Check if sent out the 64N bytes */
				if((g_USBImage.total_tx_bytes%USB_EP_BULK_MAXP_FS) == 0)
				{
					USB_Send_Null_Packet(g_USBImage.txpipe->byEP);
				}
			}
		#else
			/*  Check if sent out the (max pkt size)*N bytes */
			if((g_USBImage.total_tx_bytes%USB_EP_BULK_MAXP) == 0)
			{
				USB_Send_Null_Packet(g_USBImage.txpipe->byEP);
			}
		#endif

			if(g_USBImage.image_cmd.Code == PTP_GET_PARTIAL_OBJECT)
			{
				g_USBImage.image_response.ContainerLength = USB_IMAGE_RES_1_PARA;
				g_USBImage.image_response.Parameter1 = g_USBImage.total_tx_bytes - USB_IMAGE_CONTAINER_LENGTH;
			}
			else
			{
				g_USBImage.image_response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
			}

			g_USBImage.image_response.Code = PTP_OK;
			g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;
			USB_Image_ReturnTx(&g_USBImage.image_response, g_USBImage.image_response.ContainerLength);
		}
		else
		{
			g_USBImage.error = KAL_FALSE;
			USB_Image_Cancel_By_Device();
/*
			g_USBImage.image_response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
			g_USBImage.image_response.Code = PTP_GENERAL_ERROR;
			g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;
			USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_CONTAINER_LENGTH);
*/
		}
		
		break;
	case PTP_DATA_TX:
		PTP_Get_Object_Hdlr();
		break;
	case PTP_CMD_RX:
	case PTP_DATA_RX:
	default:
		EXT_ASSERT(0, (kal_uint32)g_USBImage.state, 0, 0);
		break;
	}
}

/************************************************************
	Utility functions
*************************************************************/
static void PTP_Copy_From_PTP_String(void *pdest, const kal_uint16 *source_string, kal_uint8 string_num)
{
	kal_uint8		*index;
	kal_uint32	count;
	kal_uint16	temp_value;


	kal_mem_set(pdest , string_num, 1);
	index = (kal_uint8 *)pdest + 1;

	for(count = 0; count < string_num; count++)
	{
		temp_value = source_string[count];
		kal_mem_cpy((kal_uint8*)index, (kal_uint8*) &temp_value , 2);
		index = index + 2;
	}
}


static void PTP_Copy_From_PTP_Handle_Array(void *pdest, kal_uint32 *source_array, kal_uint32 array_num)
{
	kal_uint8		*index;
	kal_uint32 	num = array_num;
	kal_uint32	temp_value;
	kal_uint32	count;


	kal_mem_cpy(pdest, (kal_uint8*)&num, 4);
	index = (kal_uint8 *)pdest + 4;

	for(count = 0; count < num; count++)
	{
		temp_value = source_array[count];
		kal_mem_cpy((kal_uint8*) index, (kal_uint8*) &temp_value , 4);
		index = index + 4;
	}
}


static void PTP_Date_to_String(void *pdest, FS_DOSDateTime time)
{
	kal_uint8 *index = (kal_uint8 *)pdest;
	kal_uint8  temp1, temp2, temp3;

	kal_mem_set(index, 16, 1);   /* string element number  */
	index++;
	kal_mem_set(index, 0x00, 32);

	if(time.Year1980 < 20)
	{
		kal_mem_set(index, '1', 1);
		index += 2;
		kal_mem_set(index, '9', 1);		
		index += 2;
		temp1 = (time.Year1980+80)/10 + '0';
		temp2 = (time.Year1980+80)%10 + '0';
		kal_mem_set(index, temp1, 1);
		index += 2;
		kal_mem_set(index, temp2, 1);	
		index += 2;
	}
	else if(time.Year1980 < 120)
	{
		kal_mem_set(index, '2', 1);
		index += 2;
		kal_mem_set(index, '0', 1);		
		index += 2;
		temp1 = (time.Year1980-20)/10 + '0';
		temp2 = (time.Year1980-20)%10 + '0';		
		kal_mem_set(index, temp1, 1);
		index += 2;
		kal_mem_set(index, temp2, 1);	
		index += 2;
	}
	else
	{
		kal_mem_set(index, '2', 1);
		index += 2;
		temp1 = (time.Year1980-20)/100 + '0';
		temp2 = ((time.Year1980-20)-(temp1-'0')*100)/10+ '0';
		temp3 = ((time.Year1980-20)-(temp1-'0')*100)%10+ '0';
 		kal_mem_set(index, temp1, 1);
		index += 2;	
		kal_mem_set(index, temp2, 1);
		index += 2;
		kal_mem_set(index, temp3, 1);	
		index += 2;
	}

	temp1 = time.Month/10 + '0';
	temp2 = time.Month%10 + '0';
	kal_mem_set(index, temp1, 1);
	index += 2;
	kal_mem_set(index, temp2, 1);
	index += 2;

	temp1 = time.Day/10 + '0';
	temp2 = time.Day%10 + '0';
	kal_mem_set(index, temp1, 1);
	index += 2;
	kal_mem_set(index, temp2, 1);
	index += 2;

	kal_mem_set(index, 'T', 1);
	index += 2;
	
	temp1 = time.Hour/10 + '0';
	temp2 = time.Hour%10 + '0';	
	kal_mem_set(index, temp1, 1);
	index += 2;
	kal_mem_set(index, temp2, 1);
	index += 2;

	temp1 = time.Minute/10 + '0';
	temp2 = time.Minute%10 + '0';
	kal_mem_set(index, temp1, 1);
	index += 2;
	kal_mem_set(index, temp2, 1);
	index += 2;

	temp1 = (time.Second2*2)/10 + '0';
	temp2 = (time.Second2*2)%10 + '0';		
	kal_mem_set(index, temp1, 1);
	index += 2;
	kal_mem_set(index, temp2, 1);
}

static void PTP_Close_File(void)
{
#ifdef __DRM_SUPPORT__
	DRM_close_file(g_USBImage.current_file_handle);
#else
	FS_Close(g_USBImage.current_file_handle);
#endif
	g_USBImage.current_file_handle = PTP_NO_HANDLE;
	USB_Image_Cancel_By_Device();
}

/************************************************************
	Parse PTP command functions
*************************************************************/
/* Parse PTP operations */
static void PTP_Image_Operation(void)
{
	if(g_USBImage.image_cmd.ContainerType != USB_IMAGE_COMMAND_BLOCK)
	{
		EXT_ASSERT(0, g_USBImage.image_cmd.ContainerType, 0, 0);
	}

	if((g_USBImage.is_session_open == KAL_FALSE)&&( 
		(g_USBImage.image_cmd.Code != PTP_GET_DEVICE_INFO)&&(g_USBImage.image_cmd.Code != PTP_OPEN_SESSION)))
	{
		USB_Dbg_Trace(USB_DBG_IMAGE_SESSION_NOT_OPEN_ERROR, drv_get_current_time(), 0, 0);
		/* Only Send Response */
		g_USBImage.state = PTP_CMD_RX;

		g_USBImage.image_response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
		g_USBImage.image_response.Code = PTP_SESSION_NOT_OPEN;
		g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;
		USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_CONTAINER_LENGTH);
		return;
	}

	/* Parse PTP commands */
	switch(g_USBImage.image_cmd.Code)
	{
	case PTP_GET_DEVICE_INFO:
		USB_Dbg_Trace(USB_DBG_PTP_GET_DEVICE_INFO, drv_get_current_time(), 0, 0);
		PTP_Cmd_Get_Device_Info();
		break;
	case PTP_OPEN_SESSION:
		USB_Dbg_Trace(USB_DBG_PTP_OPEN_SESSION, drv_get_current_time(), 0, 0);
		PTP_Cmd_Open_Session();
		break;
	case PTP_CLOSE_SESSION:
		USB_Dbg_Trace(USB_DBG_PTP_CLOSE_SESSION, drv_get_current_time(), 0, 0);
		PTP_Cmd_Close_Session();
		break;
	case PTP_GET_STORAGE_IDS:
		USB_Dbg_Trace(USB_DBG_PTP_GET_STORAGE_IDS, drv_get_current_time(), 0, 0);
		PTP_Cmd_Get_Storage_Ids();
		break;
	case PTP_GET_STORAGE_INFO:
		USB_Dbg_Trace(USB_DBG_PTP_GET_STORAGE_INFO, drv_get_current_time(),  g_USBImage.image_cmd.Parameter1, 0);
		PTP_Cmd_Get_Storage_Info();
		break;
	case PTP_GET_NUM_OBJECTS:
		USB_Dbg_Trace(USB_DBG_PTP_GET_NUM_OBJECTS, drv_get_current_time(),  g_USBImage.image_cmd.Parameter1,  g_USBImage.image_cmd.Parameter2);
		PTP_Cmd_Get_Num_Objects();
		break;
	case PTP_GET_OBJECT_HANDLES:
		USB_Dbg_Trace(USB_DBG_PTP_GET_OBJECT_HANDLES, drv_get_current_time(), g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
		PTP_Cmd_Get_Object_Handles();
		break;
	case PTP_GET_OBJECT_INFO:
		USB_Dbg_Trace(USB_DBG_PTP_GET_OBJECT_INFO, drv_get_current_time(), g_USBImage.image_cmd.Parameter1, 0);
		PTP_Cmd_Get_Object_Info();
		break;
	case PTP_GET_OBJECT:
		USB_Dbg_Trace(USB_DBG_PTP_GET_OBJECT, drv_get_current_time(), g_USBImage.image_cmd.Parameter1, 0);
		PTP_Cmd_Get_Object();
		break;
	case PTP_GET_PARTIAL_OBJECT:
		USB_Dbg_Trace(USB_DBG_PTP_GET_PARTIAL_OBJECT, drv_get_current_time(), g_USBImage.image_cmd.Parameter1, 0);
		PTP_Cmd_Get_Partial_Object();
		break;
	case PTP_GET_THUMB:		
		USB_Dbg_Trace(USB_DBG_PTP_GET_THUMB, drv_get_current_time(), g_USBImage.image_cmd.Parameter1, 0);
		PTP_Cmd_Get_Thumb();
		break;
	case PTP_SEND_OBJECT_INFO:
	case PTP_SEND_OBJECT:
		EXT_ASSERT(0, g_USBImage.image_cmd.Code, 0, 0);
		break;
	default:
		PTP_Cmd_Unknown();
		break;
	}
}

static void PTP_Cmd_Get_Device_Info(void)
{
	PTP_CONTAINER 	*data = (PTP_CONTAINER *)g_USBImage.image_info_buffer;
	kal_uint8 		*index;
 	kal_uint8			element_num1 = sizeof(PTPDeviceInfo_Struct)/sizeof(kal_uint8) -1; 
 	kal_uint8	 		element_num2 = g_USBImage.image_param->image_manufacturer_size;
 	kal_uint8			element_num3 = g_USBImage.image_param->image_model_size;
  	kal_uint8			element_num4 = g_USBImage.image_param->image_device_version_size;
   	kal_uint8			element_num5 =  g_USBImage.image_param->image_serial_number_size;

	g_USBImage.state = PTP_RESPONSE;
	
	data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num1
		+ 4 + (element_num2 + element_num3 + element_num4 + element_num5)*2;

	if(data->ContainerLength > USB_IMAGE_MAX_OBJECT_INFO)
	{
		EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_OBJECT_INFO, 0);
	}

	data->ContainerType = USB_IMAGE_DATA_BLOCK;
	data->Code = PTP_GET_DEVICE_INFO;
	data->TransactionID = g_USBImage.current_transactionID;
	
	index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;

	kal_mem_cpy(index, &g_USBImage.image_deviceinfo, element_num1);
	index += element_num1;
	
	PTP_Copy_From_PTP_String((void *)index, g_USBImage.image_param->image_manufacturer_string, element_num2);
	index += element_num2*2 + 1;
	
	PTP_Copy_From_PTP_String((void *)index, g_USBImage.image_param->image_model_string, element_num3);
	index += element_num3*2 + 1;
	
	PTP_Copy_From_PTP_String((void *)index, g_USBImage.image_param->image_device_version_string, element_num4);
	index += element_num4*2 + 1;

	PTP_Copy_From_PTP_String((void *)index, g_USBImage.image_param->image_serial_number_string, element_num5);
	g_USBImage.total_tx_bytes = data->ContainerLength;
	USB_Image_BuildTx((void *)g_USBImage.image_info_buffer, data->ContainerLength);
}

static void PTP_Cmd_Open_Session(void)
{
	/* Only Send Response */
	g_USBImage.state = PTP_CMD_RX;
	
	g_USBImage.is_session_open = KAL_TRUE;
	
	g_USBImage.image_response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USBImage.image_response.Code = PTP_OK;
	g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;
	USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_CONTAINER_LENGTH);
}

static void PTP_Cmd_Close_Session(void)
{
	/* Only Send Response */
	g_USBImage.state = PTP_CMD_RX;
	
	g_USBImage.is_session_open = KAL_FALSE;

	g_USBImage.image_response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USBImage.image_response.Code = PTP_OK;
	g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;
	/* Only clear Device send SCRIPT flags */
	g_USBImage.script_flag &= ~((1<<DREQUEST)|(1<<DRSPONSE));

	USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_CONTAINER_LENGTH);

	if(g_USBImage.current_file_handle != PTP_NO_HANDLE)
	{
	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif
		g_USBImage.current_file_handle = PTP_NO_HANDLE;
	}
}

static void PTP_Cmd_Get_Storage_Ids(void)
{
	PTP_CONTAINER 	*data = (PTP_CONTAINER *)g_USBImage.image_info_buffer;
 	kal_uint8 		*index;
//	kal_uint32		storgae_id[3] = {2,  PTP_SCRIPT_STORAGE_ID, PTP_IMAGE_STORAGE_ID};
	kal_uint32		storgae_id[2] = {1,  PTP_SCRIPT_STORAGE_ID};
	

	g_USBImage.state = PTP_RESPONSE;
	
	data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + (sizeof(storgae_id)/sizeof(kal_uint8));
	data->ContainerType = USB_IMAGE_DATA_BLOCK;
	data->Code = PTP_GET_STORAGE_IDS;
	data->TransactionID = g_USBImage.current_transactionID;
	
	index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;
	kal_mem_cpy(index, &storgae_id, sizeof(storgae_id)/sizeof(kal_uint8));
	g_USBImage.total_tx_bytes = data->ContainerLength;
	USB_Image_BuildTx((void *)g_USBImage.image_info_buffer, data->ContainerLength);
}


static void PTP_Cmd_Get_Storage_Info(void)
{
	PTP_CONTAINER 	*data = (PTP_CONTAINER *)g_USBImage.image_info_buffer;
 	kal_uint8 		*index;
	kal_uint8			element_num1 = sizeof(PTPStorageInfo_Struct)/sizeof(kal_uint8);
//	kal_uint16		storage_descriptor[] = {'C', 'E', 'L', 'L','P','H','O','N','E','\0'};
//	kal_uint16		volume_label[] = {'K', '\0'};
//	kal_uint8			element_num2 = sizeof(storage_descriptor)/sizeof(kal_uint16);
//	kal_uint8			element_num3 = sizeof(volume_label)/sizeof(kal_uint16);

	g_USBImage.state = PTP_RESPONSE;

	data->ContainerType = USB_IMAGE_DATA_BLOCK;
	data->Code =  PTP_GET_STORAGE_INFO;
	data->TransactionID = g_USBImage.current_transactionID;

	index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;

	if(g_USBImage.image_cmd.Parameter1 == PTP_SCRIPT_STORAGE_ID)
	{
		data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num1 + 2;	
		g_USBImage.image_storageinfo.MaxCapacity[0] = 0xffff;
		g_USBImage.image_storageinfo.MaxCapacity[1] = 0xffff;
		g_USBImage.image_storageinfo.MaxCapacity[2] = 0xffff;
		g_USBImage.image_storageinfo.MaxCapacity[3] = 0xffff;
		g_USBImage.image_storageinfo.FreeSpaceInBytes[0] = 0xffff;
		g_USBImage.image_storageinfo.FreeSpaceInBytes[1] = 0xffff;
		g_USBImage.image_storageinfo.FreeSpaceInBytes[2] = 0xffff;
		g_USBImage.image_storageinfo.FreeSpaceInBytes[3] = 0xffff;

		kal_mem_cpy(index, &g_USBImage.image_storageinfo, element_num1);
		index += element_num1;
		kal_mem_set((void *)index, 0x00, 2);			/* two empty strings  */	
	}
	else
	{
		EXT_ASSERT(0, g_USBImage.image_cmd.Parameter1, 0 ,0);
	}
/*
	else if (g_USBImage.image_cmd.Parameter1 == PTP_IMAGE_STORAGE_ID)
	{
		//data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num1 + 2;	

		data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num1
						+ 2 + (element_num2 + element_num3)*2;	

		g_USBImage.image_storageinfo.MaxCapacity[0] = 0;
		g_USBImage.image_storageinfo.MaxCapacity[1] = 0;
		g_USBImage.image_storageinfo.MaxCapacity[2] = 5;
		g_USBImage.image_storageinfo.MaxCapacity[3] = 5;
		g_USBImage.image_storageinfo.FreeSpaceInBytes[0] = 0;
		g_USBImage.image_storageinfo.FreeSpaceInBytes[1] = 0;
		g_USBImage.image_storageinfo.FreeSpaceInBytes[2] = 2;
		g_USBImage.image_storageinfo.FreeSpaceInBytes[3] = 4;
		
		kal_mem_cpy(index, &g_USBImage.image_storageinfo, element_num1);
		index += element_num1;
		
		//kal_mem_set(index, 0x00, 2); 			// empty string 	
	
		PTP_Copy_From_PTP_String((void *)index, storage_descriptor, element_num2);
		index += element_num2*2 +1;
	
		PTP_Copy_From_PTP_String((void *)index, volume_label, element_num3);	
	}
*/
	g_USBImage.total_tx_bytes = data->ContainerLength;
	USB_Image_BuildTx((void *)g_USBImage.image_info_buffer, data->ContainerLength);
}

static void PTP_Cmd_Get_Num_Objects(void)
{
	kal_uint8		count;
	kal_uint32 	num = 0;
	
	/* Send Response */
	g_USBImage.state = PTP_CMD_RX;

	g_USBImage.image_response.ContainerLength = USB_IMAGE_RES_1_PARA;
	g_USBImage.image_response.Code = PTP_OK;
	g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;

	/* find number of script type */
	if (g_USBImage.image_cmd.Parameter2 == PTP_SCRIPT)
	{
		for(count = 0; count < 6; count++)
		{
			if((g_USBImage.script_flag&(1<<count)) != 0)
			{
				g_objecthandles[num] = 0xC1000000 + count;
				num++;
			}
		}
		
		g_USBImage.image_response.Parameter1 = num;
	}
	else
	{
		/* only for test with PC  */
		g_USBImage.image_response.Parameter1 = 0;
	}
	USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_RES_1_PARA);
}


static void PTP_Cmd_Get_Object_Handles(void)
{
	PTP_CONTAINER 	*data = (PTP_CONTAINER *)g_USBImage.image_info_buffer;
 	kal_uint8 		*index;
  	kal_uint32 		num = 0;
	kal_uint32		count;
	
	index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;
	g_USBImage.state = PTP_RESPONSE;

	if (g_USBImage.image_cmd.Parameter2 == PTP_SCRIPT)
	{
		for(count = 0; count < 6; count++)
		{
			if((g_USBImage.script_flag&(1<<count)) != 0)
			{
				g_objecthandles[num] = 0xC1000000 + count;
				num++;
			}
		}
		
		data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + (num+1)*4;
		PTP_Copy_From_PTP_Handle_Array(index, g_objecthandles, num);
	}
	else
	{	
		/* only for test with PC  */
		data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + 4;
		kal_mem_set(index, 0x00, 4); 			// empty Array	
	}

	data->ContainerType = USB_IMAGE_DATA_BLOCK;
	data->Code =  PTP_GET_OBJECT_HANDLES;
	data->TransactionID = g_USBImage.current_transactionID;
	g_USBImage.total_tx_bytes = data->ContainerLength;	
	USB_Image_BuildTx((void *)g_USBImage.image_info_buffer, data->ContainerLength);
}


static void PTP_Cmd_Get_Object_Info(void)
{
	PTP_CONTAINER 	*data;
	kal_uint8 	*index;
	kal_uint8		element_num = sizeof(PTPObjectInfo_Struct)/sizeof(kal_uint8);	
	kal_uint16	filename_element_num;
	kal_uint16	*file_ptr;

	
	g_USBImage.state = PTP_RESPONSE;

	if((g_USBImage.image_cmd.Parameter1>>24) == 0xC1)		/* script type*/
	{
		/* Prepare file name */
		if(g_USBImage.image_cmd.Parameter1 == DRSPONSE_DPS)
		{
			kal_uint16	filename[] = {'D','R','S','P','O','N','S','E','.','D','P','S','\0'};
			filename_element_num = sizeof(filename)/sizeof(kal_uint16);
			file_ptr = (kal_uint16 *)filename;
			g_USBImage.image_objectinfo.ObjectCompressedSize = g_USBImage.send_dps_response_xml_size;
		}
		else if(g_USBImage.image_cmd.Parameter1 == DREQUEST_DPS)
		{
			kal_uint16	filename[] = {'D','R','E','Q','U','E','S','T','.','D','P','S','\0'};
			filename_element_num = sizeof(filename)/sizeof(kal_uint16);
			file_ptr = (kal_uint16 *)filename;
			g_USBImage.image_objectinfo.ObjectCompressedSize = g_USBImage.send_dps_request_xml_size;
		}
		else if(g_USBImage.image_cmd.Parameter1 == DDISCVRY_DPS)
		{
			kal_uint16	filename[] = {'D','D','I','S','C','V','R','Y','.','D','P','S','\0'};
			filename_element_num = sizeof(filename)/sizeof(kal_uint16);
			file_ptr = (kal_uint16 *)filename;
			g_USBImage.image_objectinfo.ObjectCompressedSize = 0;
		}
		else
		{
			file_ptr = NULL;
			EXT_ASSERT(0, g_USBImage.image_cmd.Parameter1, 0, 0);
		}

		data = (PTP_CONTAINER *)g_USBImage.image_info_buffer;
		data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num + filename_element_num*2 + 4;

		if(data->ContainerLength > USB_IMAGE_MAX_OBJECT_INFO)
		{
			EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_OBJECT_INFO, 0);
		}
		
		data->ContainerType = USB_IMAGE_DATA_BLOCK;
		data->Code =  PTP_GET_OBJECT_INFO;
		data->TransactionID = g_USBImage.current_transactionID;
		
		g_USBImage.image_objectinfo.StorageID = PTP_SCRIPT_STORAGE_ID;
		g_USBImage.image_objectinfo.ObjectFormat = PTP_SCRIPT;
		g_USBImage.image_objectinfo.ThumbFormat = 0x3000;			/* undefined*/
		g_USBImage.image_objectinfo.ThumbCompressedSize[0] = 0x0000;
		g_USBImage.image_objectinfo.ThumbCompressedSize[1] = 0x0000;
		g_USBImage.image_objectinfo.ThumbPixWidth[0] = 0x0000;
		g_USBImage.image_objectinfo.ThumbPixWidth[1] = 0x0000;
		g_USBImage.image_objectinfo.ThumbPixHeight[0] = 0x0000;
		g_USBImage.image_objectinfo.ThumbPixHeight[1] = 0x0000;
		g_USBImage.image_objectinfo.ImagePixWidth[0] = 0x0000;
		g_USBImage.image_objectinfo.ImagePixWidth[1] = 0x0000;
		g_USBImage.image_objectinfo.ImagePixHeight[0] = 0x0000;
		g_USBImage.image_objectinfo.ImagePixHeight[1] = 0x0000;

 		index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;
		kal_mem_cpy(index, &g_USBImage.image_objectinfo, element_num);
		index += element_num;

		PTP_Copy_From_PTP_String((void *)index, file_ptr, filename_element_num);
		index += filename_element_num*2 + 1;

		kal_mem_set(index, 0x00, 3); 			/* three empty string */	
		g_USBImage.total_tx_bytes = data->ContainerLength;
		USB_Image_BuildTx((void *)g_USBImage.image_info_buffer, data->ContainerLength);
	}
	else
	{
		/* image file's handle */
	#ifdef __DRM_SUPPORT__
		FS_DOSDirEntry file_dir_entry;
	#else
		FS_FileInfo	file_info;
	#endif
		kal_int32		fs_result;
		kal_uint16  	filenpath_element_num = 260;
		kal_bool 		result;
		exif_header_info_struct  jpeg_info;
		
		filename_element_num = 41;
		file_ptr = (kal_uint16 *)g_USBImage.image_buffer;

		if(g_USBImage.is_start_job_xml == KAL_TRUE)
			ASSERT(0);

		data = (PTP_CONTAINER *)g_USBImage.image_info_buffer;
		data->ContainerType = USB_IMAGE_DATA_BLOCK;
		data->Code =  PTP_GET_OBJECT_INFO;
		data->TransactionID = g_USBImage.current_transactionID;

		/* use the handle (g_USBImage.image_cmd.Parameter1) to get "file path" from MMI */
		g_USBImage.current_file_handle = mmi_pict_return_print_file_handle_with_filepath(
					g_USBImage.image_cmd.Parameter1, file_ptr, &filenpath_element_num);

		if (g_USBImage.current_file_handle <0)
		{
			USB_Image_Cancel_By_Device();
			return;
		}

		result = exif_parse_jpeg_header(file_ptr, &jpeg_info);

		if(result == KAL_FALSE)
		{
			/* May user open .bmp, not . jpg */
			USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_OPEN_FILE_FAIL_IND, 0 ,0);

			/*  return the fake width and height */
			jpeg_info.image_width = 120;
			jpeg_info.image_height = 160;
		}

		g_USBImage.image_objectinfo.ThumbPixWidth[0] = jpeg_info.image_width&0xffff;
		g_USBImage.image_objectinfo.ThumbPixWidth[1] = (jpeg_info.image_width>>16)&0xffff;
		g_USBImage.image_objectinfo.ThumbPixHeight[0] = jpeg_info.image_height&0xffff;
		g_USBImage.image_objectinfo.ThumbPixHeight[1] = (jpeg_info.image_height>>16)&0xffff;
		g_USBImage.image_objectinfo.ImagePixWidth[0] = jpeg_info.image_width&0xffff;
		g_USBImage.image_objectinfo.ImagePixWidth[1] = (jpeg_info.image_width>>16)&0xffff;
		g_USBImage.image_objectinfo.ImagePixHeight[0] = jpeg_info.image_height&0xffff;
		g_USBImage.image_objectinfo.ImagePixHeight[1] = (jpeg_info.image_height>>16)&0xffff;

	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif

		/* use the handle (g_USBImage.image_cmd.Parameter1) to get file name from MMI */
		g_USBImage.current_file_handle = mmi_pict_return_print_file_handle_with_filename(
					g_USBImage.image_cmd.Parameter1, file_ptr, &filename_element_num);

		if(g_USBImage.current_file_handle < 0)
		{
			USB_Image_Cancel_By_Device();
			return;
		}
		
	#ifdef __DRM_SUPPORT__
		fs_result = DRM_file_size(g_USBImage.current_file_handle, &g_USBImage.image_objectinfo.ObjectCompressedSize);
	#else
		fs_result = FS_GetFileSize(g_USBImage.current_file_handle, &g_USBImage.image_objectinfo.ObjectCompressedSize);
	#endif

		if(fs_result != FS_NO_ERROR) 
		{
			PTP_Close_File();
			return;
		}

		g_USBImage.image_objectinfo.StorageID = PTP_IMAGE_STORAGE_ID;
		g_USBImage.image_objectinfo.ObjectFormat = PTP_EXIF_JPEG;
		g_USBImage.image_objectinfo.ThumbFormat = PTP_EXIF_JPEG; 
		g_USBImage.image_objectinfo.ThumbCompressedSize[0] = g_USBImage.image_objectinfo.ObjectCompressedSize&0xffff;
		g_USBImage.image_objectinfo.ThumbCompressedSize[1] = (g_USBImage.image_objectinfo.ObjectCompressedSize>>16)&0xffff;

		index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;
		kal_mem_cpy(index, &g_USBImage.image_objectinfo, element_num);
		index += element_num;
		
		PTP_Copy_From_PTP_String((void *)index, file_ptr, filename_element_num);
		index += filename_element_num*2 + 1;

	#ifdef __DRM_SUPPORT__
		fs_result = mmi_pict_return_current_print_file_info(&file_dir_entry); //DRM_file_info(g_USBImage.current_file_handle, &file_info); 
	#else
		fs_result = FS_GetFileInfo(g_USBImage.current_file_handle, &file_info);
	#endif

		if(fs_result != FS_NO_ERROR)
		{
			PTP_Close_File();
			return;
		}

	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif

		g_USBImage.current_file_handle = PTP_NO_HANDLE;

	#ifdef __DRM_SUPPORT__
		PTP_Date_to_String(index, file_dir_entry.CreateDateTime);
		index += 33;   /* 33 == 16*2 +1 */
		PTP_Date_to_String(index, file_dir_entry.DateTime);	/* last modification date */
		index += 33;
	#else
		PTP_Date_to_String(index, file_info.DirEntry->CreateDateTime);
		index += 33;   /* 33 == 16*2 +1 */
		PTP_Date_to_String(index, file_info.DirEntry->DateTime);	/* last modification date */
		index += 33;
 	#endif

		kal_mem_set(index, 0x00, 1); 		/* empty string for key word */
		data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num + 
							(filename_element_num +32)*2 + 4;

		if(data->ContainerLength > USB_IMAGE_MAX_OBJECT_INFO)
		{
			EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_OBJECT_INFO, 0);
		}

		g_USBImage.total_tx_bytes = data->ContainerLength;
		USB_Image_BuildTx((void *)g_USBImage.image_info_buffer, data->ContainerLength);
	}
}


static void PTP_Get_Object_Hdlr(void)
{
	kal_uint32	total_tx_file_size = g_USBImage.total_tx_bytes;
	kal_uint32	receive_file_size;
	kal_int32		fs_result;

	USB_Image_BuildTx((void *)g_USBImage.image_buffer->data_buffer[g_USBImage.rw_buffer_index], g_USBImage.rw_bytes);

	g_USBImage.current_tx_bytes += g_USBImage.rw_bytes;

	if(g_USBImage.current_tx_bytes == total_tx_file_size)
	{	
		g_USBImage.state = PTP_RESPONSE;
	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif
		g_USBImage.current_file_handle = PTP_NO_HANDLE;	
		return;
	}

	if((total_tx_file_size - g_USBImage.current_tx_bytes) > USB_IMAGE_MAX_TX_BUFFERSIZE)
		g_USBImage.rw_bytes = USB_IMAGE_MAX_TX_BUFFERSIZE;
	else
		g_USBImage.rw_bytes = total_tx_file_size - g_USBImage.current_tx_bytes;

	g_USBImage.rw_buffer_index ^= 1;

#ifdef __DRM_SUPPORT__
	fs_result = DRM_read_file(g_USBImage.current_file_handle, g_USBImage.image_buffer->data_buffer[g_USBImage.rw_buffer_index], 
				g_USBImage.rw_bytes, &receive_file_size);
#else
	fs_result = FS_Read(g_USBImage.current_file_handle, g_USBImage.image_buffer->data_buffer[g_USBImage.rw_buffer_index], 
				g_USBImage.rw_bytes, &receive_file_size);
#endif

	if(fs_result != FS_NO_ERROR) 
	{
	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif
		g_USBImage.current_file_handle = PTP_NO_HANDLE;

		g_USBImage.error = KAL_TRUE;
		g_USBImage.state = PTP_RESPONSE;
		return;
	}

	if(receive_file_size != g_USBImage.rw_bytes)
	{
		EXT_ASSERT(0, receive_file_size, g_USBImage.rw_bytes, 0);	
	}

	if(g_USBImage.is_start_job_xml == KAL_TRUE)
		ASSERT(0);
}


static void PTP_Cmd_Get_Object(void)
{
	if(g_USBImage.image_cmd.Parameter1 == DREQUEST_DPS)
	{
		PTP_CONTAINER 	*data = (PTP_CONTAINER *)g_USBImage.dps_request_tx_data;
		g_USBImage.state = PTP_RESPONSE;
		data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + g_USBImage.send_dps_request_xml_size;

		/* Should add size check here */
		if(g_USBImage.is_start_job_xml == KAL_TRUE)
		{
			if(data->ContainerLength > USB_IMAGE_MAX_START_JOB_XMLBUFFERSIZE)
				EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_START_JOB_XMLBUFFERSIZE, 0);
		}
		else
		{
			if(data->ContainerLength > USB_IMAGE_MAX_XMLBUFFERSIZE)
				EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_XMLBUFFERSIZE, 0);
		}

		data->ContainerType = USB_IMAGE_DATA_BLOCK;
		data->Code =  PTP_GET_OBJECT;
		data->TransactionID = g_USBImage.current_transactionID;
		g_USBImage.total_tx_bytes = data->ContainerLength;
		USB_Image_BuildTx((void *)g_USBImage.dps_request_tx_data, data->ContainerLength);
	}
	else if(g_USBImage.image_cmd.Parameter1 == DRSPONSE_DPS)
	{
		PTP_CONTAINER 	*data = (PTP_CONTAINER *)g_USBImage.dps_response_tx_data;
		g_USBImage.state = PTP_RESPONSE;
		data->ContainerLength = USB_IMAGE_CONTAINER_LENGTH + g_USBImage.send_dps_response_xml_size;

		if(data->ContainerLength > USB_IMAGE_MAX_XMLBUFFERSIZE)
		{
			EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_XMLBUFFERSIZE, 0);
		}

		data->ContainerType = USB_IMAGE_DATA_BLOCK;
		data->Code =  PTP_GET_OBJECT;
		data->TransactionID = g_USBImage.current_transactionID;
		g_USBImage.total_tx_bytes = data->ContainerLength;
		USB_Image_BuildTx((void *)g_USBImage.dps_response_tx_data, data->ContainerLength);
	}
	else
	{
		PTP_CONTAINER 	*data = (PTP_CONTAINER *)g_USBImage.image_buffer;
		kal_uint8 	*index;
		kal_uint32	receive_file_size;
		kal_int32		fs_result;
		kal_uint16	filename_element_num = 41;
		kal_uint32	total_tx_file_size;

		if(g_USBImage.is_start_job_xml == KAL_TRUE)
			ASSERT(0);

		/* use the handle (g_USBImage.image_cmd.Parameter1) to get file name from MMI */
		g_USBImage.current_file_handle = mmi_pict_return_print_file_handle_with_filename(
				g_USBImage.image_cmd.Parameter1, (kal_uint16 *)g_USBImage.image_buffer, &filename_element_num);

		if(g_USBImage.current_file_handle <0)
		{
			USB_Image_Cancel_By_Device();
			return;
		}

	#ifdef __DRM_SUPPORT__
		fs_result = DRM_file_size(g_USBImage.current_file_handle, &g_USBImage.total_tx_bytes);
	#else
		fs_result = FS_GetFileSize(g_USBImage.current_file_handle, &g_USBImage.total_tx_bytes);
	#endif

		if(fs_result != FS_NO_ERROR) 
		{
			PTP_Close_File();
			return;
		}
		
		g_USBImage.total_tx_bytes += USB_IMAGE_CONTAINER_LENGTH;
		total_tx_file_size = g_USBImage.total_tx_bytes;

 		data->ContainerLength = total_tx_file_size;
		data->ContainerType = USB_IMAGE_DATA_BLOCK;
		data->Code =  PTP_GET_OBJECT;
		data->TransactionID = g_USBImage.current_transactionID;
 		index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;

		if(total_tx_file_size > USB_IMAGE_MAX_TX_BUFFERSIZE)
		{
			g_USBImage.rw_buffer_index = 0;
			g_USBImage.current_tx_bytes = 0;
			g_USBImage.rw_bytes = USB_IMAGE_MAX_TX_BUFFERSIZE;
					
		#ifdef __DRM_SUPPORT__
			fs_result = DRM_read_file(g_USBImage.current_file_handle, index, 
					USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
		#else
			fs_result = FS_Read(g_USBImage.current_file_handle, index, 
					USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
		#endif

			if(fs_result != FS_NO_ERROR) 
			{
				PTP_Close_File();
				return;
			}

			if(receive_file_size != USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH)
			{
				EXT_ASSERT(0, receive_file_size, USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, 0);	
			}

			g_USBImage.state = PTP_DATA_TX;
			PTP_Get_Object_Hdlr();
		}
		else
		{
		#ifdef __DRM_SUPPORT__
			fs_result = DRM_read_file(g_USBImage.current_file_handle, index, 
					total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
		#else
			fs_result = FS_Read(g_USBImage.current_file_handle, index, 
					total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
		#endif

			if(fs_result != FS_NO_ERROR) 
			{
				PTP_Close_File();
				return;			
			}

			if(receive_file_size != total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH)
			{
				EXT_ASSERT(0, receive_file_size, total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, 0);	
			}

			g_USBImage.state = PTP_RESPONSE;
			USB_Image_BuildTx((void *)g_USBImage.image_buffer, total_tx_file_size);
	#ifdef __DRM_SUPPORT__
			DRM_close_file(g_USBImage.current_file_handle);
	#else
			FS_Close(g_USBImage.current_file_handle);
	#endif
			g_USBImage.current_file_handle = PTP_NO_HANDLE;			
		}
	}
}

static void PTP_Cmd_Get_Thumb(void)
{
	PTP_CONTAINER 	*data = (PTP_CONTAINER *)g_USBImage.image_buffer;
	kal_uint8 	*index;
	kal_uint32	receive_file_size;
	kal_int32		fs_result;
	kal_uint16  	filename_element_num = 41;
	kal_uint32	total_tx_file_size;

	if(g_USBImage.is_start_job_xml == KAL_TRUE)
		ASSERT(0);

	/* use the handle (g_USBImage.image_cmd.Parameter1) to get file name from MMI */
	g_USBImage.current_file_handle = mmi_pict_return_print_file_handle_with_filename(
			g_USBImage.image_cmd.Parameter1, (kal_uint16 *)g_USBImage.image_buffer, &filename_element_num);

	if (g_USBImage.current_file_handle <0)
	{
		USB_Image_Cancel_By_Device();
		return;
	}
	
#ifdef __DRM_SUPPORT__
	fs_result = DRM_file_size(g_USBImage.current_file_handle, &g_USBImage.total_tx_bytes);
#else
	fs_result = FS_GetFileSize(g_USBImage.current_file_handle, &g_USBImage.total_tx_bytes);
#endif
	
	if(fs_result != FS_NO_ERROR) 
	{
		PTP_Close_File();
		return;		
	}

	g_USBImage.total_tx_bytes += USB_IMAGE_CONTAINER_LENGTH;

	total_tx_file_size = g_USBImage.total_tx_bytes;

 	data->ContainerLength = total_tx_file_size;
	data->ContainerType = USB_IMAGE_DATA_BLOCK;
	data->Code = PTP_GET_THUMB;
	data->TransactionID = g_USBImage.current_transactionID;
 	index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;

	if(total_tx_file_size > USB_IMAGE_MAX_TX_BUFFERSIZE)
	{
		g_USBImage.rw_buffer_index = 0;
		g_USBImage.current_tx_bytes = 0;
		g_USBImage.rw_bytes = USB_IMAGE_MAX_TX_BUFFERSIZE;
		
#ifdef __DRM_SUPPORT__
		fs_result = DRM_read_file(g_USBImage.current_file_handle, index, 
				USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
#else
		fs_result = FS_Read(g_USBImage.current_file_handle, index, 
				USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
#endif
	
		if(fs_result != FS_NO_ERROR) 
		{
			PTP_Close_File();
			return;				
		}

		if(receive_file_size != USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH)
		{
			EXT_ASSERT(0, receive_file_size, USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, 0);	
		}

		g_USBImage.state = PTP_DATA_TX;
		PTP_Get_Object_Hdlr();
	}
	else
	{
#ifdef __DRM_SUPPORT__
		fs_result = DRM_read_file(g_USBImage.current_file_handle, index, 
				total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
#else
		fs_result = FS_Read(g_USBImage.current_file_handle, index, 
				total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
#endif

		if(fs_result != FS_NO_ERROR) 
		{
			PTP_Close_File();
			return;
		}

		if(receive_file_size != total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH)
		{
			EXT_ASSERT(0, receive_file_size, total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, 0);	
		}

		g_USBImage.state = PTP_RESPONSE;
		USB_Image_BuildTx((void *)g_USBImage.image_buffer, total_tx_file_size);
	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif
		g_USBImage.current_file_handle = PTP_NO_HANDLE;
	}
}


static void PTP_Cmd_Get_Partial_Object(void)
{
 	PTP_CONTAINER *data = (PTP_CONTAINER *)g_USBImage.image_buffer;
	kal_uint8 	*index;
	kal_uint32	receive_file_size;
	kal_uint32	total_file_size;
	kal_uint32	total_tx_file_size;
	kal_int32		fs_result;
	kal_uint16  	filename_element_num = 41;


	if(g_USBImage.is_start_job_xml == KAL_TRUE)
		ASSERT(0);

	/* use the handle (g_USBImage.image_cmd.Parameter1) to get file name from MMI */
	g_USBImage.current_file_handle = mmi_pict_return_print_file_handle_with_filename(
			g_USBImage.image_cmd.Parameter1, (kal_uint16 *)g_USBImage.image_buffer, &filename_element_num);
	
	if(g_USBImage.current_file_handle <0)
	{
		USB_Image_Cancel_By_Device();
		return;		
	}

	/* Parameter2 is image file offset */
	if(g_USBImage.image_cmd.Parameter2 != 0)
	{
	#ifdef __DRM_SUPPORT__
		fs_result = DRM_seek_file(g_USBImage.current_file_handle, g_USBImage.image_cmd.Parameter2, FS_FILE_BEGIN);
	#else
		fs_result = FS_Seek(g_USBImage.current_file_handle, g_USBImage.image_cmd.Parameter2, FS_FILE_BEGIN);
	#endif

		/* For FS_Seek return value, it cannot be FS_NO_ERROR */
		if(fs_result < 0)
		{
			PTP_Close_File();
			return;
		}
	}

	/* Check file actual total size is >= offset (para2) + max bytes to get (para3) */
#ifdef __DRM_SUPPORT__
	fs_result = DRM_file_size(g_USBImage.current_file_handle, &receive_file_size);
#else
	fs_result = FS_GetFileSize(g_USBImage.current_file_handle, &receive_file_size);
#endif

	if(fs_result != FS_NO_ERROR) 
	{
		PTP_Close_File();
		return;
	}

	total_file_size = receive_file_size;

	if(total_file_size >= (g_USBImage.image_cmd.Parameter2 + g_USBImage.image_cmd.Parameter3))
	{
		g_USBImage.total_tx_bytes = g_USBImage.image_cmd.Parameter3 + USB_IMAGE_CONTAINER_LENGTH;
	}
	else
	{
		g_USBImage.total_tx_bytes = total_file_size - g_USBImage.image_cmd.Parameter2 + USB_IMAGE_CONTAINER_LENGTH;
	}
	
	total_tx_file_size = g_USBImage.total_tx_bytes;

	data->ContainerLength = total_tx_file_size;	
	data->ContainerType = USB_IMAGE_DATA_BLOCK;
	data->Code =  PTP_GET_PARTIAL_OBJECT;
	data->TransactionID = g_USBImage.current_transactionID;
 	index = (kal_uint8 *)data + USB_IMAGE_CONTAINER_LENGTH;

	if(total_tx_file_size > USB_IMAGE_MAX_TX_BUFFERSIZE)
	{
		g_USBImage.rw_buffer_index = 0;
		g_USBImage.current_tx_bytes = 0;
		g_USBImage.rw_bytes = USB_IMAGE_MAX_TX_BUFFERSIZE;
		
#ifdef __DRM_SUPPORT__
		fs_result = DRM_read_file(g_USBImage.current_file_handle, index, 
				USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
#else
		fs_result = FS_Read(g_USBImage.current_file_handle, index, 
				USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
#endif

		if(fs_result != FS_NO_ERROR) 
		{
			PTP_Close_File();
			return;				
		}

		total_file_size = receive_file_size;

		if(total_file_size != USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH)
		{
			EXT_ASSERT(0, total_file_size, USB_IMAGE_MAX_TX_BUFFERSIZE-USB_IMAGE_CONTAINER_LENGTH, 0);	
		}

		g_USBImage.state = PTP_DATA_TX;
		PTP_Get_Object_Hdlr();
	}
	else
	{
#ifdef __DRM_SUPPORT__
		fs_result = DRM_read_file(g_USBImage.current_file_handle, index, 
				total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
#else
		fs_result = FS_Read(g_USBImage.current_file_handle, index, 
				total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, &receive_file_size);
#endif

		if(fs_result != FS_NO_ERROR) 
		{
			PTP_Close_File();
			return;
		}

		total_file_size = receive_file_size;

		if(total_file_size != total_tx_file_size - USB_IMAGE_CONTAINER_LENGTH)
		{
			EXT_ASSERT(0, total_file_size, total_tx_file_size-USB_IMAGE_CONTAINER_LENGTH, 0);
		}

		g_USBImage.state = PTP_RESPONSE;
		USB_Image_BuildTx((void *)g_USBImage.image_buffer, total_tx_file_size);
	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif
		g_USBImage.current_file_handle = PTP_NO_HANDLE;
	}
}


static void PTP_Send_Object_Hdlr(void)
{
	if(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)
	{
		kal_uint8 *index = (kal_uint8*)g_USBImage.image_info_buffer + USB_IMAGE_CONTAINER_LENGTH;
		PTPObjectInfo_Struct *data = (PTPObjectInfo_Struct *)index;
		kal_uint8	*fifth_file_letter;

		g_USBImage.image_response.ContainerLength = USB_IMAGE_RES_3_PARA;
		g_USBImage.image_response.Code = PTP_OK;
		g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;
		g_USBImage.image_response.Parameter1 = PTP_SCRIPT_STORAGE_ID;
		g_USBImage.image_response.Parameter2 = 0xffffffff;

		fifth_file_letter = index +(sizeof(PTPObjectInfo_Struct)/sizeof(kal_uint8) + 9);

		switch(*fifth_file_letter)	/* the fifth word  */
		{
		case 'C':	
			g_USBImage.image_response.Parameter3 = HDISCVRY_DPS;
			USB_Dbg_Trace(USB_DBG_PTP_SEND_OBJECT_INFO, drv_get_current_time(), HDISCVRY_DPS, 0);
			USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_RES_3_PARA);

			g_USBImage.dps_discovery = KAL_TRUE;
			USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_DISCOVERY_IND, 0, 0);

			/* send a remove all storages interrupt packet */
			g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
			g_USBImage.image_event.Code = PTP_STORE_REMOVED;
			g_USBImage.image_event.TransactionID = 0xffffffff;
			g_USBImage.image_event.Parameter1 = 	PTP_ALL_STORAGE_ID;
//			USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
			USB_Image_Send_Intr();
			break;
		case 'U':
			g_USBImage.image_response.Parameter3 = HREQUEST_DPS;
			USB_Dbg_Trace(USB_DBG_PTP_SEND_OBJECT_INFO, drv_get_current_time(), HREQUEST_DPS, 0);

			g_USBImage.dps_rx_buffer_index = 1;

			/* Remove it because it is normal */
//			if((g_USBImage.script_flag&(1<<HREQUEST)) != 0)
//				EXT_ASSERT(0, g_USBImage.script_flag, 0, 0);
		
			g_USBImage.script_flag |= 1<<HREQUEST;
			g_USBImage.received_xml_size = data->ObjectCompressedSize;
			USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_RES_3_PARA);
			break;
		case 'O':
			g_USBImage.image_response.Parameter3 = HRSPONSE_DPS;
			USB_Dbg_Trace(USB_DBG_PTP_SEND_OBJECT_INFO, drv_get_current_time(), HRSPONSE_DPS, 0);

			if(g_USBImage.is_wait_host_respone == KAL_TRUE)
			{
				if((g_USBImage.script_flag&(1<<HRSPONSE)) != 0)
					EXT_ASSERT(0, g_USBImage.script_flag, 0, 0);

				g_USBImage.script_flag |= 1<<HRSPONSE;
			}
			
			/* prepare for next send xml paccket */
			g_USBImage.dps_rx_buffer_index = 0;
			g_USBImage.received_xml_size = data->ObjectCompressedSize;

			USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_RES_3_PARA);
			break;
		default:
			EXT_ASSERT(0, *fifth_file_letter, 0, 0);
			break;
		}
	}
	else if(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT)
	{
		USB_Dbg_Trace(USB_DBG_PTP_SEND_OBJECT, drv_get_current_time(), 0, 0);
		g_USBImage.image_response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
		g_USBImage.image_response.Code = PTP_OK;
		g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;

		if((g_USBImage.total_rx_bytes-USB_IMAGE_CONTAINER_LENGTH) !=  g_USBImage.received_xml_size)
		{
			EXT_ASSERT(0, g_USBImage.total_rx_bytes, g_USBImage.received_xml_size, 0);
		}
		
		if(g_USBImage.dps_rx_buffer_index == 1)
		{
			USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_HREQUEST_IND, 0, 0);	
		}
		else if(g_USBImage.dps_rx_buffer_index == 0)
		{
			if(g_USBImage.is_wait_host_respone == KAL_TRUE)
			{
				g_USBImage.is_wait_host_respone = KAL_FALSE;
				USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_HRESPONSE_IND, 0, 0);	
			}
		}
		else
		{
			EXT_ASSERT(0, g_USBImage.dps_rx_buffer_index, 0, 0);
		}

		USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_RES_3_PARA);
	}

	/* Clear OutPktRdy */
//	USB_EP_Bulk_Out_Ready(g_USBImage.rxpipe->byEP);
//	USB_Image_ReturnTx(&g_USBImage.image_response, g_USBImage.image_response.ContainerLength);
}


static void PTP_Cmd_Unknown(void)
{
#ifdef  __PRODUCTION_RELEASE__
	/* Send Response */
	g_USBImage.state = PTP_CMD_RX;
	g_USBImage.image_response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USBImage.image_response.Code = PTP_OPERATION_NOT_SUPPORTED;	
	g_USBImage.image_response.TransactionID = g_USBImage.current_transactionID;
	USB_Image_ReturnTx(&g_USBImage.image_response, USB_IMAGE_CONTAINER_LENGTH);

	g_USBImage.image_event.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USBImage.image_event.Code = PTP_CANCEL_TRANSACTION;
	g_USBImage.image_event.TransactionID = g_USBImage.current_transactionID;
//	USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_CONTAINER_LENGTH);
	USB_Image_Send_Intr();
#else
	ASSERT(0);
#endif
}

#endif  /* PICTBRIDGE_SUPPORT */

