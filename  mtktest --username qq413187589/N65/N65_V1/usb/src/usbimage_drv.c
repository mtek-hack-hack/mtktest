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
 *   usbimage_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb IMAGE class driver
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
#include "drm_gprot.h"

#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usb_resource.h"

#include "usb_custom.h"
#include "usbimage_drv.h"
#include "ptp_state.h"
#include "usb_debug_tool.h"

/*This will be removed when change back to media task*/
#include "custom_config.h"


#ifdef PICTBRIDGE_SUPPORT

/* static variables */
static kal_bool intr_pkt_buf_is_full = KAL_FALSE;
static kal_bool g_intr_pipe_is_running = KAL_FALSE;

/* static functions */
//static void USB_Image_Timeout_hdlr(void *parameter);
static void	USB_Image_Tx_DMA_Callback(void);
static void 	USB_Image_Ep0_Cancel_Hdlr(void *data);
static void	USB_Image_Ep0_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void	USB_Image_IntrIn_Reset(void);
static void	USB_Image_BulkIn_Reset(void);
static void	USB_Image_BulkOut_Reset(void);
static void	USB_Image_Cmd_Reset(void);
static void	USB_Image_IntrIn_Hdlr(void);
static void 	USB_Image_BulkOut_Hdr(void );

/************************************************************
	USB image suspend handler
*************************************************************/
void USB_Image_Suspend_Hdlr(void)
{
	g_USBImage.is_suspend_state = KAL_TRUE;
}


/************************************************************
	interface initialization functions
*************************************************************/
/* interface create function, prepare descriptor */
void USB_Image_If_Create(void *ifname)
{
	kal_uint8		ep_in_id;
	kal_uint8		ep_out_id;
	kal_uint8		ep_intr_id;			/* interrupt point*/
	kal_uint8		if_id;
	kal_uint32	index;


	/* get resource number and register to gUsbDevice */
	g_USBImage.image_if_info = USB_Get_Interface_Number(&if_id);
	g_USBImage.image_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_in_id);
	g_USBImage.image_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_out_id);
	g_USBImage.image_ep_intr_info = USB_Get_Intr_Ep(&ep_intr_id); 			/* number is 3  */
	
	/* record interface name and interface descriptor length */
	g_USBImage.image_if_info->interface_name_ptr = (kal_char *)ifname;
	g_USBImage.image_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_USBImage.image_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_intr_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler */
	g_USBImage.image_if_info->ep_info[0] = (Usb_Ep_Info*)g_USBImage.image_ep_in_info;
	g_USBImage.image_if_info->ep_info[1] = (Usb_Ep_Info*)g_USBImage.image_ep_out_info;
	g_USBImage.image_if_info->ep_info[2] = (Usb_Ep_Info*)g_USBImage.image_ep_intr_info;
	g_USBImage.image_if_info->if_class_specific_hdlr = USB_Image_Ep0_Command;

	/* standard interface descriptor */
	g_USBImage.image_if_info->ifdscr.stdif.bLength = USB_IFDSC_LENGTH;
	g_USBImage.image_if_info->ifdscr.stdif.bDescriptorType = USB_INTERFACE;
	g_USBImage.image_if_info->ifdscr.stdif.bInterfaceNumber = if_id;
	g_USBImage.image_if_info->ifdscr.stdif.bAlternateSetting = 0;
	g_USBImage.image_if_info->ifdscr.stdif.bNumEndpoints = USB_IMAGE_EP_NUMBER;
	g_USBImage.image_if_info->ifdscr.stdif.bInterfaceClass = USB_IMAGE_INTERFACE_CLASS_CODE;
	g_USBImage.image_if_info->ifdscr.stdif.bInterfaceSubClass = USB_IMAGE_INTERFACE_SUBCLASS_CODE;
	g_USBImage.image_if_info->ifdscr.stdif.bInterfaceProtocol = USB_IMAGE_INTERFACE_PROTOCOL_CODE;
	g_USBImage.image_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_USBImage.image_param->image_interface_string); 

	/* endpoint handler */
	g_USBImage.image_ep_in_info->ep_reset = USB_Image_BulkIn_Reset;
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_in_id, NULL);

	g_USBImage.image_ep_out_info->ep_reset = USB_Image_BulkOut_Reset;
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_out_id, USB_Image_BulkOut_Hdr);
	
	g_USBImage.image_ep_intr_info->ep_reset = USB_Image_IntrIn_Reset;
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_intr_id, USB_Image_IntrIn_Hdlr);

	/* endpoint descriptor */
	g_USBImage.image_ep_in_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_in_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_USBImage.image_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_in_id);	/*InPipe*/
	g_USBImage.image_ep_in_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef USB_20_ENABLE
	g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
	g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
#endif
	g_USBImage.image_ep_in_info->epdesc.stdep.bInterval = 0;
	g_USBImage.image_ep_in_info->ep_status.epin_status.byEP = ep_in_id;
	g_USBImage.image_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	
	g_USBImage.image_ep_out_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_out_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_USBImage.image_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT | ep_out_id);	/*OutPipe*/
	g_USBImage.image_ep_out_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef USB_20_ENABLE
	g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
	g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
#endif
	g_USBImage.image_ep_out_info->epdesc.stdep.bInterval = 0;
	g_USBImage.image_ep_out_info->ep_status.epout_status.byEP = ep_out_id;

	g_USBImage.image_ep_intr_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_intr_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_USBImage.image_ep_intr_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_intr_id);	/*IntrPipe*/
	g_USBImage.image_ep_intr_info->epdesc.stdep.bmAttributes = USB_EP_INTR;
#ifndef USB_20_ENABLE
	g_USBImage.image_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP&0xff; 		/*HW-dependent*/
	g_USBImage.image_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_INTR_MAXP>>8)&0xff; 
#endif
	g_USBImage.image_ep_intr_info->epdesc.stdep.bInterval = 1;
	g_USBImage.image_ep_intr_info->ep_status.epin_status.byEP = ep_intr_id;
	g_USBImage.image_ep_intr_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

	USB_Get_DMA_Channel(ep_in_id, USB_TX_EP_TYPE, KAL_FALSE); 

	/* Prepare the DeviceInfo Dataset */
	g_USBImage.image_deviceinfo.StandardVersion = 100;
	g_USBImage.image_deviceinfo.VenderExtensionID[0] = 0;
	g_USBImage.image_deviceinfo.VenderExtensionID[1] = 0;
	g_USBImage.image_deviceinfo.VenderExtensionVersion = 0;
	g_USBImage.image_deviceinfo.VendorExtensionDesc = 0x00;	/* empty string */
	g_USBImage.image_deviceinfo.FunctionalMode[0] = PTP_STANDARD_MODE&0xff;
	g_USBImage.image_deviceinfo.FunctionalMode[1] = (PTP_STANDARD_MODE>>8)&0xff;

	g_USBImage.image_deviceinfo.OperationsSupportedSize[0] = PTP_MAX_OPERATION_CODE_SIZE&0xff;
	g_USBImage.image_deviceinfo.OperationsSupportedSize[1] = (PTP_MAX_OPERATION_CODE_SIZE>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupportedSize[2] = (PTP_MAX_OPERATION_CODE_SIZE>>16)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupportedSize[3] = (PTP_MAX_OPERATION_CODE_SIZE>>24)&0xff;
	
	g_USBImage.image_deviceinfo.OperationsSupported[0][0] = PTP_GET_DEVICE_INFO&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[0][1] = (PTP_GET_DEVICE_INFO>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[1][0] = PTP_OPEN_SESSION&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[1][1] = (PTP_OPEN_SESSION>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[2][0] = PTP_CLOSE_SESSION&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[2][1] = (PTP_CLOSE_SESSION>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[3][0] = PTP_GET_STORAGE_IDS&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[3][1] = (PTP_GET_STORAGE_IDS>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[4][0] = PTP_GET_STORAGE_INFO&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[4][1] = (PTP_GET_STORAGE_INFO>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[5][0] = PTP_GET_NUM_OBJECTS&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[5][1] = (PTP_GET_NUM_OBJECTS>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[6][0] = PTP_GET_OBJECT_HANDLES&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[6][1] = (PTP_GET_OBJECT_HANDLES>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[7][0] = PTP_GET_OBJECT_INFO&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[7][1] = (PTP_GET_OBJECT_INFO>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[8][0] = PTP_GET_OBJECT&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[8][1] = (PTP_GET_OBJECT>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[9][0] = PTP_GET_THUMB&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[9][1] = (PTP_GET_THUMB>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[10][0] = PTP_SEND_OBJECT_INFO&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[10][1] = (PTP_SEND_OBJECT_INFO>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[11][0] = PTP_SEND_OBJECT&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[11][1] = (PTP_SEND_OBJECT>>8)&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[12][0] = PTP_GET_PARTIAL_OBJECT&0xff;
	g_USBImage.image_deviceinfo.OperationsSupported[12][1] = (PTP_GET_PARTIAL_OBJECT>>8)&0xff;	

	g_USBImage.image_deviceinfo.EventsSupportedSize[0] = PTP_MAX_EVENT_CODE_SIZE&0xff;
	g_USBImage.image_deviceinfo.EventsSupportedSize[1] = (PTP_MAX_EVENT_CODE_SIZE>>8)&0xff;
	g_USBImage.image_deviceinfo.EventsSupportedSize[2] = (PTP_MAX_EVENT_CODE_SIZE>>16)&0xff;
	g_USBImage.image_deviceinfo.EventsSupportedSize[3] = (PTP_MAX_EVENT_CODE_SIZE>>24)&0xff;

	g_USBImage.image_deviceinfo.EventsSupported[0][0] = PTP_CANCEL_TRANSACTION&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[0][1] = (PTP_CANCEL_TRANSACTION>>8)&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[1][0] = PTP_STORE_ADDED&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[1][1] = (PTP_STORE_ADDED>>8)&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[2][0] = PTP_STORE_REMOVED&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[2][1] = (PTP_STORE_REMOVED>>8)&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[3][0] = PTP_OBJECT_ADDED&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[3][1] = (PTP_OBJECT_ADDED>>8)&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[4][0] = PTP_OBJECT_REMOVED&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[4][1] = (PTP_OBJECT_REMOVED>>8)&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[5][0] = PTP_OBJECT_INFO_CHAGNED&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[5][1] = (PTP_OBJECT_INFO_CHAGNED>>8)&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[6][0] = PTP_REQUEST_OBJECT_TRANSFER&0xff;
	g_USBImage.image_deviceinfo.EventsSupported[6][1] = (PTP_REQUEST_OBJECT_TRANSFER>>8)&0xff;

	g_USBImage.image_deviceinfo.DevicePropertiesSupportedSize[0] = 0;		/* empty array */
	g_USBImage.image_deviceinfo.DevicePropertiesSupportedSize[1] = 0;
	g_USBImage.image_deviceinfo.DevicePropertiesSupportedSize[2] = 0;
	g_USBImage.image_deviceinfo.DevicePropertiesSupportedSize[3] = 0;
	g_USBImage.image_deviceinfo.CaptureFormatsSize[0] = 0;				/* empty array */
	g_USBImage.image_deviceinfo.CaptureFormatsSize[1] = 0;
	g_USBImage.image_deviceinfo.CaptureFormatsSize[2] = 0;
	g_USBImage.image_deviceinfo.CaptureFormatsSize[3] = 0;
	g_USBImage.image_deviceinfo.ImageFormatsSize[0] = PTP_MAX_OBJECT_FORMAT_CODE_SIZE&0xff;
	g_USBImage.image_deviceinfo.ImageFormatsSize[1] = (PTP_MAX_OBJECT_FORMAT_CODE_SIZE>>8)&0xff;
	g_USBImage.image_deviceinfo.ImageFormatsSize[2] = (PTP_MAX_OBJECT_FORMAT_CODE_SIZE>>16)&0xff;
	g_USBImage.image_deviceinfo.ImageFormatsSize[3] = (PTP_MAX_OBJECT_FORMAT_CODE_SIZE>>24)&0xff;

	g_USBImage.image_deviceinfo.ImageFormats[0][0] = PTP_EXIF_JPEG&0xff;
	g_USBImage.image_deviceinfo.ImageFormats[0][1] = (PTP_EXIF_JPEG>>8)&0xff;
	g_USBImage.image_deviceinfo.ImageFormats[1][0] = PTP_SCRIPT&0xff;
	g_USBImage.image_deviceinfo.ImageFormats[1][1] = (PTP_SCRIPT>>8)&0xff;
//	g_USBImage.image_deviceinfo.ImageFormats[2][0] = PTP_TIFF_EP&0xff;
//	g_USBImage.image_deviceinfo.ImageFormats[2][1] = (PTP_TIFF_EP>>8)&0xff;

	/* Prepare the StorageInfo Dataset */
	g_USBImage.image_storageinfo.StorageType = PTP_FIXED_RAM;
	g_USBImage.image_storageinfo.FilesystemType = PTP_GENERIC_FLAT;
	g_USBImage.image_storageinfo.AccessCapability = PTP_READ_WRITE;
//	g_USBImage.image_storageinfo.FreeSpaceInImages[0] = 0x0034;
//	g_USBImage.image_storageinfo.FreeSpaceInImages[1] = 0x0000;
	g_USBImage.image_storageinfo.FreeSpaceInImages[0] = 0xffff;
	g_USBImage.image_storageinfo.FreeSpaceInImages[1] = 0xffff;

	/* Prepare the ObjectInfo Dataset */
	g_USBImage.image_objectinfo.ProtectionStatus = PTP_NO_PROTECTION;
	g_USBImage.image_objectinfo.ImageBitDepth[0] = 0;			/* no use */
	g_USBImage.image_objectinfo.ImageBitDepth[1]= 0;
	g_USBImage.image_objectinfo.ParentObject[0] = 0;
	g_USBImage.image_objectinfo.ParentObject[1] = 0;
	g_USBImage.image_objectinfo.AssociationType = 0;			/* no use */
	g_USBImage.image_objectinfo.AssociationDesc = 0;			/* no use */
	g_USBImage.image_objectinfo.SequenceNumber =	0;			/* no use */

	/* two never change assignments */
	g_USBImage.image_response.ContainerType = USB_IMAGE_RESPONSE_BLOCK;
//	g_USBImage.image_event.ContainerType = USB_IMAGE_EVENT_BLOCK;

	for(index = 0; index <= PTP_MAX_INTERRUPT_PKT; index++)
	{
		g_USBImage.image_event_array[index].ContainerType = USB_IMAGE_EVENT_BLOCK;
	}
 

	/* Initail file handle */
	g_USBImage.current_file_handle = PTP_NO_HANDLE;	

//	if(g_USBImage.dps_discovery_timeout_handle == 0)
//		GPTI_GetHandle(&g_USBImage.dps_discovery_timeout_handle);
}

/* interface reset function, enable EP*/
void USB_Image_If_Reset(void)
{
	g_USBImage.txpipe = &g_USBImage.image_ep_in_info->ep_status.epin_status;
	g_USBImage.rxpipe = &g_USBImage.image_ep_out_info->ep_status.epout_status;
	g_USBImage.intrpipe = &g_USBImage.image_ep_intr_info->ep_status.epin_status;

	USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE);
	USB_Clear_Tx_EP_FIFO(g_USBImage.txpipe->byEP);	
	USB_Clear_Rx_EP_FIFO(g_USBImage.rxpipe->byEP);
	USB_Clear_Tx_EP_FIFO(g_USBImage.intrpipe->byEP);

	/* configure DMA setting for EP */
	USB_TxEPEn(g_USBImage.txpipe->byEP, KAL_TRUE);

	/*Non-DMA*/
	USB_RxEPEn(g_USBImage.rxpipe->byEP, KAL_FALSE);
	USB_TxEPEn(g_USBImage.intrpipe->byEP, KAL_FALSE);

	g_USBImage.is_suspend_state = KAL_FALSE;

	/* initialize state machine*/
	/* send reset message to usb task, task handles the PTP state machine*/
	if (g_USBImage.send_ptp_reset_ilm == KAL_TRUE)
	{
		kal_uint32 	src_mod;
		ilm_struct 	*usb_ilm;

		/* avoid sending too many messages to USB task */
	 	g_USBImage.send_ptp_reset_ilm = KAL_FALSE;
		USB_Dbg_Trace(USB_DBG_IMAGE_SEND_RESET_MSG, drv_get_current_time(), 0, 0);

		if(g_USBImage.dps_discovery == KAL_TRUE)
			USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_HOST_RESET_IND, 0, 0);

		if(kal_if_hisr() == KAL_TRUE)
			src_mod = MOD_DRV_HISR;
		else
			src_mod = MOD_USB;	

	 	DRV_BuildPrimitive(usb_ilm, src_mod,
	 		MOD_USB, MSG_ID_USB_PTPIMAGE_RESET_IND, NULL);
	 	msg_send_ext_queue(usb_ilm);
	}
}


void USB_Image_If_Speed_Reset(kal_bool b_other_speed)
{


}

/************************************************************
	USB image reset function
*************************************************************/
void USB_Image_Reset_Hdlr(void)
{
//	GPTI_StopItem(g_USBImage.dps_discovery_timeout_handle);
	
	g_USBImage.host_cancel_flag = KAL_FALSE;
	g_USBImage.send_ptp_reset_ilm = KAL_TRUE;
	g_USBImage.mmi_start_job = KAL_FALSE;
	g_USBImage.next_xml_is_start_job = KAL_FALSE;
	g_USBImage.is_start_job_xml = KAL_FALSE;
//	g_USBImage.intr_done = KAL_TRUE;
	g_USBImage.is_wait_host_respone = KAL_FALSE;
	g_USBImage.is_session_open = KAL_FALSE;

	g_USBImage.script_flag = (1<<DDISCVRY);

	if(g_USBImage.current_file_handle != PTP_NO_HANDLE)
	{
	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif
		g_USBImage.current_file_handle = PTP_NO_HANDLE;	
	}

	g_USBImage.dps_discovery = KAL_FALSE;
	g_USBImage.intr_state = IMAGE_INTR_IDLE;
	g_USBImage.intr_read_ptr = 0;
	g_USBImage.intr_write_ptr = 0;
	g_USBImage.error = KAL_FALSE;
	g_USBImage.total_rx_bytes = 0;
	g_USBImage.current_rx_bytes = 0;
	g_USBImage.total_tx_bytes = 0;
	g_USBImage.current_tx_bytes = 0;
	g_USBImage.rw_bytes = 0;
	g_USBImage.received_xml_size = 0;
	g_USBImage.send_dps_request_xml_size = 0;
	g_USBImage.send_dps_response_xml_size = 0;
}

/************************************************************
	global variable g_USBImage initialize and release functions
*************************************************************/
/* initialize global variable g_USBImage */
void USB_Init_Image_Status(void)
{
	g_USBImage.txpipe = NULL;
	g_USBImage.rxpipe = NULL;
	g_USBImage.intrpipe = NULL;
	g_USBImage.ptp_stop = KAL_FALSE;

	USB_Image_Reset_Hdlr();

	/* register handler to handle the EP0 Rx handler  */
	USB_Register_EP0_RxHdlr(USB_Image_Ep0_Cancel_Hdlr);
}

/* release global variable g_USBImage */
void USB_Release_Image_Status(void)
{
	g_USBImage.txpipe = NULL;
	g_USBImage.rxpipe = NULL;
	g_USBImage.intrpipe = NULL;
	g_USBImage.ptp_stop = KAL_FALSE;

	USB_Image_Reset_Hdlr();

	/* release the EP0 Rx handler   */
	USB_Register_EP0_RxHdlr(NULL);	
}


/************************************************************
	TX path DMA callback function
*************************************************************/
/* TX DMA callback function */
static void USB_Image_Tx_DMA_Callback(void)
{
	if(gUsbDevice.is_configured_now == KAL_TRUE)
	{
		ilm_struct *usb_ilm;

		g_USBImage.txpipe->nBytesLeft = USB_EP_NODATA;

		/*send a message to usb task, let PTP state machine handle the transmitted data*/
		DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,
						MSG_ID_USB_PTPIMAGE_DMA_TX_DONE_CONF, NULL);
		msg_send_ext_queue(usb_ilm);
	}
}

/************************************************************
	TX path build functions(use DMA)
*************************************************************/
/* prepare to transmit Tx packet from addr and length len */	
void USB_Image_BuildTx(void *addr, kal_uint32 len)
{
	/* stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE);

	/* initialize Tx pipe*/
	g_USBImage.txpipe->pData = (kal_uint8 *)addr;
	g_USBImage.txpipe->nBytesLeft = len;

	/* dma running state is "NOT" cleared inside the USB_Image_Tx_DMA_Callback function */
//	USB_DMA_Setup(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE, (kal_uint32)addr, len, 
//										USB_Image_Tx_DMA_Callback, KAL_FALSE);

	USB_DMA_Setup(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)addr, len, 
			USB_Image_Tx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
}

/* prepare to transmit Tx response packet from addr and length len */	
void USB_Image_ReturnTx(void *addr, kal_uint32 len)
{
	/* stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE);

	/* initialize Tx pipe*/
	g_USBImage.txpipe->pData = (kal_uint8 *)addr;
	g_USBImage.txpipe->nBytesLeft = len;

	/* dma running state is "NOT" cleared inside the USB_Image_Tx_DMA_Callback function */
//	USB_DMA_Setup(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE, (kal_uint32)addr, len, 
//										NULL, KAL_FALSE);

	USB_DMA_Setup(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE, USB_ENDPT_BULK, (kal_uint32)addr, len, 
				NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
}


/************************************************************
	Utility functions
*************************************************************/
void USB_Send_Null_Packet(kal_uint8 ep_num)
{
	kal_bool		bEPEmpty;
	kal_uint8 	count = 0;

	/* make sure that previous packets are already sent out
	maybe last DMA data has triggered DMA done but data are still in FIFO*/
	bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(ep_num);

	/* If cable plug out at this time, add timeout to avoid looping here */
	while((bEPEmpty == KAL_FALSE)&&(count != 300)&&(gUsbDevice.is_configured_now == KAL_TRUE)&&(gUsbDevice.usb_cable_in == KAL_TRUE))
	{
		count++;	
		kal_sleep_task(1);	
		bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(ep_num);
	}
	
	if(gUsbDevice.is_configured_now == KAL_FALSE)
	{
		/* cable is plugged out, so USB reset */
		USB_Dbg_Trace(USB_DBG_IMAGE_DEVICE_RESET, drv_get_current_time(), gUsbDevice.usb_cable_in, 0);
		return;
	}

	if(gUsbDevice.usb_cable_in == KAL_FALSE)
	{
		USB_Dbg_Trace(USB_DBG_IMAGE_CABLE_PLUG_OUT, drv_get_current_time(), gUsbDevice.is_configured_now, 0);
		return;
	}

	if(bEPEmpty == KAL_FALSE)
	{
		/* time out */
		USB_Dbg_Trace(USB_DBG_IMAGE_NULL_PKT_TIME_OUT, drv_get_current_time(), 0, 0);
		return;
	}

	/* send out a NULL packet */
	USB_EPFIFOWrite(ep_num, 0, NULL);
	USB_EP_Bulk_Tx_Ready(ep_num);
		
	/* mak sure previous NULL pkt has been sent out
	avoid next DMA data in FIFO sent out instead of previos NULL pkt.*/
	bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(ep_num);

	/* If cable plug out at this time, add timeout to avoid looping here */
	count = 0;
	while((bEPEmpty == KAL_FALSE)&&(count != 300)&&(gUsbDevice.is_configured_now == KAL_TRUE)&&(gUsbDevice.usb_cable_in == KAL_TRUE))
	{
		count++;	
		kal_sleep_task(1);
		bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(ep_num);
	}

	if(gUsbDevice.is_configured_now == KAL_FALSE)
	{
		/* cable is plugged out, so USB reset */
		USB_Dbg_Trace(USB_DBG_IMAGE_DEVICE_RESET, drv_get_current_time(), gUsbDevice.usb_cable_in, 0);
		return;
	}

	if(gUsbDevice.usb_cable_in == KAL_FALSE)
	{
		USB_Dbg_Trace(USB_DBG_IMAGE_CABLE_PLUG_OUT, drv_get_current_time(), gUsbDevice.is_configured_now, 0);
		return;
	}

	if(bEPEmpty == KAL_FALSE)
	{
		/* time out */
		USB_Dbg_Trace(USB_DBG_IMAGE_NULL_PKT_TIME_OUT, drv_get_current_time(), 0, 0);
		return;
	}
}


/* Send interrupt endpoint status packet */
//void USB_Image_Send_Intr(void *addr, kal_uint32 len)
void USB_Image_Send_Intr(void)
{
//	kal_uint32 	count = 0;
//	kal_uint32 	temp_num = 0;
//	kal_uint8		*index = (kal_uint8*)addr;
	kal_uint32 	savedMask;
	kal_bool		start_intr_pipe = KAL_FALSE;
#ifdef USB_20_ENABLE	
	kal_uint32 	max_intr_pkt_size;
#endif

	USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT, drv_get_current_time(), g_USBImage.intr_write_ptr, g_USBImage.intr_read_ptr);

	if(gUsbDevice.is_configured_now == KAL_FALSE)
	{
		/* cable is plugged out, so USB reset */
		USB_Dbg_Trace(USB_DBG_IMAGE_DEVICE_RESET, drv_get_current_time(), gUsbDevice.usb_cable_in, 0);
		return;
	}

	if(gUsbDevice.usb_cable_in == KAL_FALSE)
	{
		USB_Dbg_Trace(USB_DBG_IMAGE_CABLE_PLUG_OUT, drv_get_current_time(), gUsbDevice.is_configured_now, 0);
		return;
	}

	if(intr_pkt_buf_is_full == KAL_TRUE)
	{
		USB_Dbg_Trace(USB_DBG_IMAGE_INTERRUPT_PKT_FULL, drv_get_current_time(), 0, 0);

		if(g_USBImage.is_suspend_state == KAL_TRUE)
		{
			USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_HOST_RESET_IND, 0, 0);
			g_USBImage.ptp_stop = KAL_TRUE;
		}
		return;
	}

	g_USBImage.image_event_array[g_USBImage.intr_write_ptr].ContainerLength = g_USBImage.image_event.ContainerLength;
	g_USBImage.image_event_array[g_USBImage.intr_write_ptr].Code = g_USBImage.image_event.Code;
	g_USBImage.image_event_array[g_USBImage.intr_write_ptr].TransactionID = g_USBImage.image_event.TransactionID;
	g_USBImage.image_event_array[g_USBImage.intr_write_ptr].Parameter1 = g_USBImage.image_event.Parameter1;

	savedMask = SaveAndSetIRQMask();

	g_USBImage.intr_write_ptr++;

	if(g_USBImage.intr_write_ptr == PTP_MAX_INTERRUPT_PKT)
		g_USBImage.intr_write_ptr = 0;

	if(g_USBImage.intr_write_ptr == g_USBImage.intr_read_ptr)
{
		intr_pkt_buf_is_full = KAL_TRUE;
	}

	if(g_intr_pipe_is_running == KAL_FALSE)
	{
		g_intr_pipe_is_running = KAL_TRUE;
		start_intr_pipe = KAL_TRUE;
	}

	RestoreIRQMask(savedMask);


#ifdef USB_20_ENABLE	
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_intr_pkt_size = USB_EP_INTR_MAXP_HS;
	else
		max_intr_pkt_size = USB_EP_INTR_MAXP_FS;
#endif

	if(start_intr_pipe == KAL_TRUE)
	{
		if(g_USBImage.intr_state != IMAGE_INTR_IDLE)
			EXT_ASSERT(0, g_USBImage.intr_state, 0, 0);

		g_USBImage.intr_state = IMAGE_INTR_SEND_ONE_PKT;
	#ifdef USB_20_ENABLE	
		USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT1, drv_get_current_time(), max_intr_pkt_size, 0);
		USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, max_intr_pkt_size, (kal_uint8 *)&g_USBImage.image_event_array[g_USBImage.intr_read_ptr]);
	#else
		USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT1, drv_get_current_time(), USB_EP_INTR_MAXP, 0);
		USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, USB_EP_INTR_MAXP, (kal_uint8 *)&g_USBImage.image_event_array[g_USBImage.intr_read_ptr]);
	#endif
		USB_EP_Bulk_Tx_Ready(g_USBImage.intrpipe->byEP);
	}
	

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


void USB_Image_Cancel_By_Device(void)
{
	USB_Dbg_Trace(USB_DBG_IMAGE_CANCEL_BY_DEVICE1, drv_get_current_time(), 0, 0);
	USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_OPEN_FILE_FAIL_IND, 0 ,0);

	g_USBImage.state = PTP_CMD_RX;
	g_USBImage.host_cancel_flag = KAL_FALSE;

	USB_Dbg_Trace(USB_DBG_IMAGE_CANCEL_BY_DEVICE2, drv_get_current_time(), 0, 0);
	/* cancel transaction interrupt, if cancel transaction, then bulk pipe will stop */
	g_USBImage.image_event.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USBImage.image_event.Code = PTP_CANCEL_TRANSACTION;
	g_USBImage.image_event.TransactionID = g_USBImage.current_transactionID;
//	USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_CONTAINER_LENGTH);
	USB_Image_Send_Intr();

/*
	USB_Dbg_Trace(USB_DBG_IMAGE_CANCEL_BY_DEVICE3, drv_get_current_time(), 0, 0);
	g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
	g_USBImage.image_event.Code = PTP_OBJECT_REMOVED;
	g_USBImage.image_event.TransactionID = 0xffffffff;
	g_USBImage.image_event.Parameter1 = 	g_USBImage.image_cmd.Parameter1;
	USB_Image_Send_Intr(&g_USBImage.image_event, USB_IMAGE_RES_1_PARA);
*/
}


/************************************************************
	EP0 command parse functions
*************************************************************/
/* class specific reset command handler */
static void USB_Image_Cmd_Reset(void)
{
	USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE);
	/* cannot clear FIFO */
//	USB_Clear_Tx_EP_FIFO(g_USBImage.txpipe->byEP);	
//	USB_Clear_Rx_EP_FIFO(g_USBImage.rxpipe->byEP);
//	USB_Clear_Tx_EP_FIFO(g_USBImage.intrpipe->byEP);	

	/* reset from reset signal or class specific EP0 RESET command */
	g_USBImage.state = PTP_CMD_RX;
	g_USBImage.host_cancel_flag = KAL_FALSE;
	g_USBImage.send_ptp_reset_ilm = KAL_TRUE;

	if(g_USBImage.current_file_handle != PTP_NO_HANDLE)
	{
	#ifdef __DRM_SUPPORT__
		DRM_close_file(g_USBImage.current_file_handle);
	#else
		FS_Close(g_USBImage.current_file_handle);
	#endif
		g_USBImage.current_file_handle = PTP_NO_HANDLE;	
	}

/*
	g_USBImage.script_flag = (1<<DDISCVRY);


	if (g_USBImage.send_ptp_reset_ilm == KAL_TRUE)
	{
		ilm_struct *usb_ilm;

	 	g_USBImage.send_ptp_reset_ilm = KAL_FALSE;
		g_USBImage.dps_discovery = KAL_FALSE;
		USB_Dbg_Trace(USB_DBG_IMAGE_SEND_RESET_MSG2, drv_get_current_time(), 0, 0);
		USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_HOST_RESET_IND, 0, 0);
	 	DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB, MSG_ID_USB_PTPIMAGE_RESET_IND, NULL);
	 	msg_send_ext_queue(usb_ilm);
	}
*/
}


/* handle the class specific cancellation request */
static void USB_Image_Ep0_Cancel_Hdlr(void *data)
{
	kal_uint16	nCount;
	kal_uint32	cancel_transaction_ID;


	/* read the cancel request data block*/
	nCount = (kal_uint16)USB_EP0_Pkt_Len();
	
	if(nCount == 6)
	{
		USB_EPFIFORead(0, 6, &g_USBImage.cancel_block);
		
		if (g_USBImage.cancel_block.Cancellation_Code != PTP_CANCEL_TRANSACTION)
			ASSERT(0);

		cancel_transaction_ID = (kal_uint16)g_USBImage.cancel_block.TransactionID[1];
		cancel_transaction_ID <<= 16;
		cancel_transaction_ID |= (kal_uint16)g_USBImage.cancel_block.TransactionID[0];
		
		if (cancel_transaction_ID != g_USBImage.current_transactionID)
		{
			EXT_ASSERT(0, g_USBImage.current_transactionID, cancel_transaction_ID, 0);
		}
		else
		{
			g_USBImage.host_cancel_flag = KAL_TRUE;
			USB_Image_Cmd_Reset();
			USB_Image_BulkIn_Reset();
			USB_Image_BulkOut_Reset();	
		}
		gUsbDevice.ep0_state = USB_EP0_RX_STATUS;
   		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		EXT_ASSERT(0, nCount, 0, 0);	
	}
}


/* Parse image class specific commands */
static void USB_Image_Ep0_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_uint8  bError = KAL_FALSE;

	switch (pcmd->bRequest)
	{
		case  USB_IMAGE_RESET:
			if( (pcmd->bmRequestType != USB_CMD_CLASSIFOUT) ||(pcmd->wValue != 0) ||(pcmd->wIndex != 0) )
			{
				bError = KAL_TRUE;
#ifndef  __PRODUCTION_RELEASE__			
				EXT_ASSERT(0, (kal_uint32)pcmd->bmRequestType, (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
#endif
			}
			else
			{
				USB_Dbg_Trace(USB_DBG_IMAGE_EP0_RESET, drv_get_current_time(), 0, 0);
				USB_Image_Cmd_Reset();
				USB_Image_BulkIn_Reset();
				USB_Image_BulkOut_Reset();
				USB_Image_IntrIn_Reset();
			}
			break;
		case  USB_IMAGE_CANCEL:
			if( (pcmd->bmRequestType != USB_CMD_CLASSIFOUT) ||(pcmd->wValue != 0) ||(pcmd->wIndex != 0)||(pcmd->wLength != 6))
			{
				bError = KAL_TRUE;
#ifndef  __PRODUCTION_RELEASE__				
				EXT_ASSERT(0, (kal_uint32)pcmd->bmRequestType, (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
#endif
			}
			else
			{
				USB_Dbg_Trace(USB_DBG_IMAGE_EP0_CANCEL, drv_get_current_time(), 0, 0);
				gUsbDevice.ep0_state = USB_EP0_RX;
			}
			break;
		case  USB_IMAGE_GET_DEVICE_STATUS:
			if( (pcmd->bmRequestType != USB_CMD_CLASSIFIN) ||(pcmd->wValue != 0) ||(pcmd->wIndex != 0) )
			{
				bError = KAL_TRUE;
#ifndef  __PRODUCTION_RELEASE__				
				EXT_ASSERT(0, (kal_uint32)pcmd->bmRequestType, (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
#endif
			}
			else
			{
				if(g_USBImage.host_cancel_flag == KAL_TRUE)
				{
					USB_Dbg_Trace(USB_DBG_IMAGE_EP0_GET_DEVICE_STATUS1, drv_get_current_time(), 0, 0);
					g_USBImage.device_status.wLength = 4;
					g_USBImage.device_status.Code = PTP_DEVICE_BUSY;
					USB_Generate_EP0Data(pep0state, pcmd, &g_USBImage.device_status, 4);
				}
//				else if(g_USBImage.device_cancel_flag == KAL_TRUE)
//				{
//					g_USBImage.device_status.wLength = 10;
//					g_USBImage.device_status.Code = PTP_TRANSACTION_CANCELLED;
//					g_USBImage.device_status.Num_para = 1;
//					g_USBImage.device_status.Para_size = 2;
//					g_USBImage.device_status.endpoint = (g_USBImage.txpipe->byEP |USB_EP_DIR_IN);
//					USB_Generate_EP0Data(pep0state, pcmd, &g_USBImage.device_status, 10);
//				}
				else
				{
					USB_Dbg_Trace(USB_DBG_IMAGE_EP0_GET_DEVICE_STATUS2, drv_get_current_time(), 0, 0);
					g_USBImage.device_status.wLength = 4;
					g_USBImage.device_status.Code = PTP_OK;
					USB_Generate_EP0Data(pep0state, pcmd, &g_USBImage.device_status, 4);
				}
			}
			break;
		default:
			bError = KAL_TRUE;
#ifndef  __PRODUCTION_RELEASE__			
			EXT_ASSERT(0, pcmd->bRequest, 0, 0);
#endif
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

/************************************************************
	endpoint reset  functions
*************************************************************/
/* Bulk In endpoint reset function */
static void USB_Image_BulkIn_Reset(void)
{
	return;
}

/* Bulk Out endpoint reset function */
static void USB_Image_BulkOut_Reset(void)
{
	return;
}

/* Interrupt endpoint reset function */
static void USB_Image_IntrIn_Reset(void)
{
//	g_USBImage.intr_done = KAL_TRUE;
	g_USBImage.intr_state = IMAGE_INTR_IDLE;
	intr_pkt_buf_is_full = KAL_FALSE;
	g_intr_pipe_is_running = KAL_FALSE;
}

/************************************************************
	Interrupt EP IN handle functions
*************************************************************/

/* Interrupt endpoint done handler */
static void USB_Image_IntrIn_Hdlr(void)
{
	kal_uint32  len;
	kal_uint8   *addr;
	kal_uint32   read_ptr = g_USBImage.intr_read_ptr;
#ifdef USB_20_ENABLE	
	kal_uint32   max_intr_pkt_size;
#endif


	USB_Dbg_Trace(USB_DBG_IMAGE_INTERRUPT_HANDLER, drv_get_current_time(), g_USBImage.intr_state, read_ptr);

	if(gUsbDevice.is_configured_now == KAL_FALSE)
	{
		/* USB reset */
		USB_Dbg_Trace(USB_DBG_IMAGE_DEVICE_RESET, drv_get_current_time(), 0, 0);
		return;
	}

#ifdef USB_20_ENABLE	
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_intr_pkt_size = USB_EP_INTR_MAXP_HS;
	else
		max_intr_pkt_size = USB_EP_INTR_MAXP_FS;
#endif


	switch(g_USBImage.intr_state)
	{
	case IMAGE_INTR_SEND_ONE_PKT:
#ifdef USB_20_ENABLE	
		addr = (kal_uint8 *)(kal_uint32)&g_USBImage.image_event_array[read_ptr] + max_intr_pkt_size;

		if((g_USBImage.image_event_array[read_ptr].ContainerLength - max_intr_pkt_size) != max_intr_pkt_size)
#else
		addr = (kal_uint8 *)(kal_uint32)&g_USBImage.image_event_array[read_ptr] + USB_EP_INTR_MAXP;

		if((g_USBImage.image_event_array[read_ptr].ContainerLength - USB_EP_INTR_MAXP) != USB_EP_INTR_MAXP)
#endif
		{
			g_USBImage.intr_state = IMAGE_INTR_SEND_LAST_PKT;
	#ifdef USB_20_ENABLE	
			len = g_USBImage.image_event_array[read_ptr].ContainerLength - max_intr_pkt_size;
	#else
			len = g_USBImage.image_event_array[read_ptr].ContainerLength - USB_EP_INTR_MAXP;
	#endif
			/* send last null or short packet */
			USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT3, drv_get_current_time(), len, (kal_uint32)addr);
			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, len, addr);
			USB_EP_Bulk_Tx_Ready(g_USBImage.intrpipe->byEP);
		}
		else
		{
			g_USBImage.intr_state = IMAGE_INTR_SEND_TWO_PKT;
		#ifdef USB_20_ENABLE	
			USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT2, drv_get_current_time(), max_intr_pkt_size, (kal_uint32)addr);
			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, max_intr_pkt_size, addr);
		#else
			USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT2, drv_get_current_time(), USB_EP_INTR_MAXP, (kal_uint32)addr);
			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, USB_EP_INTR_MAXP, addr);
		#endif
			USB_EP_Bulk_Tx_Ready(g_USBImage.intrpipe->byEP);
		}
		break;
	case IMAGE_INTR_SEND_TWO_PKT:
		g_USBImage.intr_state = IMAGE_INTR_SEND_LAST_PKT;

		/* send last null packet */
		USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT3, drv_get_current_time(), 0, 0);
		USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, 0, NULL);
		USB_EP_Bulk_Tx_Ready(g_USBImage.intrpipe->byEP);
		break;
	case IMAGE_INTR_SEND_LAST_PKT:
		g_USBImage.intr_state = IMAGE_INTR_IDLE;
		intr_pkt_buf_is_full = KAL_FALSE;
		g_USBImage.intr_read_ptr++;

		if(g_USBImage.intr_read_ptr == PTP_MAX_INTERRUPT_PKT)
			g_USBImage.intr_read_ptr = 0;

		if(g_USBImage.intr_write_ptr == g_USBImage.intr_read_ptr)
		{
			/* No interrupt pkt queue */
			g_intr_pipe_is_running = KAL_FALSE;
		}
		else
		{
			g_intr_pipe_is_running = KAL_TRUE;
			g_USBImage.intr_state = IMAGE_INTR_SEND_ONE_PKT;
	#ifdef USB_20_ENABLE	
			USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT1, drv_get_current_time(), max_intr_pkt_size, 0);
			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, max_intr_pkt_size, (kal_uint8 *)&g_USBImage.image_event_array[g_USBImage.intr_read_ptr]);
	#else
			USB_Dbg_Trace(USB_DBG_IMAGE_SEND_INTERRUPT1, drv_get_current_time(), USB_EP_INTR_MAXP, 0);
			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, USB_EP_INTR_MAXP, (kal_uint8 *)&g_USBImage.image_event_array[g_USBImage.intr_read_ptr]);
	#endif
			USB_EP_Bulk_Tx_Ready(g_USBImage.intrpipe->byEP);
		}
		break;
	case IMAGE_INTR_IDLE:
	default:
		EXT_ASSERT(0, (kal_uint32)g_USBImage.intr_state, 0, 0);
		break;
	}


	/* To do is to set interrupt done flag */
//	g_USBImage.intr_done = KAL_TRUE;
//	USB_Dbg_Trace(USB_DBG_IMAGE_INTERRUPT_HANDLER, drv_get_current_time(), g_USBImage.intr_done, 0);
}

/************************************************************
	Bulk EP OUT handle functions
*************************************************************/
/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_Image_BulkOut_Hdr(void)
{
	kal_uint32	nCount;
	ilm_struct 	*usb_ilm;
	PTP_CONTAINER	*data;

	ASSERT(g_USBImage.out_pipe_race == KAL_FALSE);
	g_USBImage.out_pipe_race = KAL_TRUE;

	/* check data length */
	nCount = USB_EP_Rx_Pkt_Len(g_USBImage.rxpipe->byEP);
	
	if(nCount == 0)
	{
		USB_EP_Bulk_Rx_Ready(g_USBImage.rxpipe->byEP);
		g_USBImage.out_pipe_race = KAL_FALSE;
		return;
	}

#ifndef  __PRODUCTION_RELEASE__
	kal_prompt_trace(MOD_USB, "Printer rx %d", nCount);
#endif

	if(g_USBImage.state == PTP_CMD_RX)
	{
		/* Read the data out */
		USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, &g_USBImage.image_cmd);
		g_USBImage.current_transactionID = g_USBImage.image_cmd.TransactionID;

		if((g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)||(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT))
		{	
			/* no message send to PTP state machine */
			g_USBImage.state = PTP_DATA_RX;
			g_USBImage.current_rx_bytes = 0;

			if(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)
			{
				if((g_USBImage.image_cmd.Parameter1|g_USBImage.image_cmd.Parameter2) != 0x00000000)
				{
#ifndef  __PRODUCTION_RELEASE__			
					EXT_ASSERT(0, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2, 0);
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
				}
			}
		}
		else
		{
			DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB, 
							MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF, NULL);
			msg_send_ext_queue(usb_ilm);
		}
	}
	else if(g_USBImage.state == PTP_DATA_RX)
	{
		if(g_USBImage.current_rx_bytes == 0)			/* begin to receive data packet */
		{		
			if(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT)
			{
				if(g_USBImage.dps_rx_buffer_index == 1)  
				{
					/* read the data out */
					USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, g_USBImage.dps_request_rx_data);
					data = (PTP_CONTAINER*)g_USBImage.dps_request_rx_data;
					g_USBImage.total_rx_bytes = data->ContainerLength;

					if(data->ContainerLength > USB_IMAGE_MAX_XMLHREQUESTSIZE)
					{
						EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_XMLHREQUESTSIZE, 0);
					}
				}
				else if(g_USBImage.dps_rx_buffer_index == 0)
				{
					/* read the data out */
					USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, g_USBImage.dps_response_rx_data);
					data = (PTP_CONTAINER*)g_USBImage.dps_response_rx_data;
					g_USBImage.total_rx_bytes = data->ContainerLength;

					if(data->ContainerLength > USB_IMAGE_MAX_XMLHRSPONSESIZE)
					{
						EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_XMLHRSPONSESIZE, 0);
					}
				}
				else
				{
					EXT_ASSERT(0, g_USBImage.dps_rx_buffer_index, 0, 0);
				}
			}
			else if (g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)
			{
				/* read the data out */
				USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, g_USBImage.image_info_buffer);
				data = (PTP_CONTAINER*)g_USBImage.image_info_buffer;
				g_USBImage.total_rx_bytes = data->ContainerLength;

				if(data->ContainerLength > USB_IMAGE_MAX_OBJECT_INFO)
				{
					EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_MAX_OBJECT_INFO, 0);
				}
			}
			else
			{
				EXT_ASSERT(0, g_USBImage.image_cmd.Code, 0, 0);
			}
		}
		else
		{
			if(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT)
			{
				if(g_USBImage.dps_rx_buffer_index == 1)  
				{
					USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, 
						g_USBImage.dps_request_rx_data + g_USBImage.current_rx_bytes);	
				}
				else if(g_USBImage.dps_rx_buffer_index == 0)
				{
					USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, 
						g_USBImage.dps_response_rx_data + g_USBImage.current_rx_bytes);	
				}
				else
				{
					EXT_ASSERT(0, g_USBImage.dps_rx_buffer_index, 0, 0);
				}
			}
			else if (g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)
			{
				USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, 
					(kal_uint8 *)g_USBImage.image_info_buffer + g_USBImage.current_rx_bytes);
			}
			else
			{
				EXT_ASSERT(0, g_USBImage.image_cmd.Code, 0, 0);
			}
		}
			
		g_USBImage.current_rx_bytes += nCount;

		if(g_USBImage.current_rx_bytes < g_USBImage.total_rx_bytes)
		{
			/* Clear OutPktRdy */
//			USB_EP_Bulk_Rx_Ready(g_USBImage.rxpipe->byEP);
		}
		else if(g_USBImage.current_rx_bytes == g_USBImage.total_rx_bytes)
		{
			g_USBImage.state = PTP_RESPONSE;
			DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB, 
							MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF, NULL);
			msg_send_ext_queue(usb_ilm);
		}
		else
		{
			EXT_ASSERT(0, g_USBImage.current_rx_bytes, g_USBImage.total_rx_bytes, 0);
		}
	}
	else
	{
		EXT_ASSERT(0, g_USBImage.state, 0, 0);
	}

	/* Clear OutPktRdy */
	USB_EP_Bulk_Rx_Ready(g_USBImage.rxpipe->byEP);
	g_USBImage.out_pipe_race = KAL_FALSE;
}

/************************************************************
	Send message functions used by the whole image class driver 
*************************************************************/
void USB_Image_Send_Msg(USBIMAGE_MSG_TYPE msg_type, kal_uint32 param1, kal_uint32 param2)
{
	usb_image_xml_struct		*xml_receive_ind;
	usb_mmi_dps_discovery_ind_struct		*dps_xml_ind;
	ilm_struct 				*usb_ilm;
	module_type 				src_mod;
	module_type 				dest_mod;
	

	if(g_USBImage.ptp_stop == KAL_TRUE)
		return;

#if (defined(__PICTBRIDGE_USB_TEST__) )
	dest_mod = MOD_CUSTOM1;
#else
	dest_mod = MOD_MMI;
#endif

	if(kal_if_hisr() == KAL_TRUE)
		src_mod = MOD_DRV_HISR;
	else
		src_mod = MOD_USB;

	if(msg_type == USB_IMAGE_MSG_MMI_DISCOVERY_IND)
	{
		dps_xml_ind = (usb_mmi_dps_discovery_ind_struct*)construct_local_para(
							sizeof(usb_mmi_dps_discovery_ind_struct), TD_CTRL);

		dps_xml_ind->dps_xml_request_address = g_USBImage.dps_request_tx_data + USB_IMAGE_CONTAINER_LENGTH;
		dps_xml_ind->dps_xml_request_buffer_size = USB_IMAGE_MAX_XMLBUFFERSIZE - USB_IMAGE_CONTAINER_LENGTH;
		dps_xml_ind->dps_xml_response_address = g_USBImage.dps_response_tx_data + USB_IMAGE_CONTAINER_LENGTH;
		dps_xml_ind->dps_xml_response_buffer_size = USB_IMAGE_MAX_XMLBUFFERSIZE - USB_IMAGE_CONTAINER_LENGTH;
		dps_xml_ind->dps_xml_start_job_buffer_size = USB_IMAGE_MAX_START_JOB_XMLBUFFERSIZE - USB_IMAGE_CONTAINER_LENGTH;

		/* send a message to mmi, let it know the addresses can be placed xml packet  */
		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod, 
				MSG_ID_USB_MMI_DPS_DISCOVERY_IND, dps_xml_ind);
		msg_send_ext_queue(usb_ilm);
	}
	else if(msg_type == USB_IMAGE_MSG_MMI_HREQUEST_IND)
	{
		xml_receive_ind = (usb_image_xml_struct*)construct_local_para(
							sizeof(usb_image_xml_struct), TD_CTRL);

		xml_receive_ind->xml_address = g_USBImage.dps_request_rx_data + USB_IMAGE_CONTAINER_LENGTH;
		xml_receive_ind->xml_packet_size = g_USBImage.received_xml_size;
	
		/* send a message to mmi, let it know a request xml packet arrive */
		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod, 
				MSG_ID_USB_MMI_DPS_HREQUEST_IND, xml_receive_ind);
		msg_send_ext_queue(usb_ilm);
	}
	else if (msg_type == USB_IMAGE_MSG_MMI_HRESPONSE_IND)
	{
		xml_receive_ind = (usb_image_xml_struct*)construct_local_para(
							sizeof(usb_image_xml_struct), TD_CTRL);

		xml_receive_ind->xml_address = g_USBImage.dps_response_rx_data + USB_IMAGE_CONTAINER_LENGTH;
		xml_receive_ind->xml_packet_size = g_USBImage.received_xml_size;

		/* send a message to mmi, let it know a response xml packet arrive */
		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod, 
				MSG_ID_USB_MMI_DPS_HRESPONSE_IND, xml_receive_ind);
		msg_send_ext_queue(usb_ilm);
	}
	else if (msg_type == USB_IMAGE_MSG_MMI_DREQUEST_CONF)
	{
		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod, 
				MSG_ID_USB_MMI_DPS_DREQUEST_CONF, NULL);
		msg_send_ext_queue(usb_ilm);
	}
	else if (msg_type == USB_IMAGE_MSG_MMI_DRESPONSE_CONF)
	{
		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod, 
				MSG_ID_USB_MMI_DPS_DRESPONSE_CONF, NULL);
		msg_send_ext_queue(usb_ilm);
	}
/*
	else if (msg_type == USB_IMAGE_MSG_MMI_CONNECT_TO_PC_IND)
	{
		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod, 
				MSG_ID_USB_MMI_PTP_CONNECT_TO_PC_IND, NULL);
		msg_send_ext_queue(usb_ilm);
	}
*/
	else if (msg_type == USB_IMAGE_MSG_MMI_OPEN_FILE_FAIL_IND)
	{
		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod, 
				MSG_ID_USB_MMI_PTP_OPEN_FILE_FAIL_IND, NULL);
		msg_send_ext_queue(usb_ilm);
	}
	else if (msg_type == USB_IMAGE_MSG_MMI_HOST_RESET_IND)
	{
		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod, 
				MSG_ID_USB_MMI_PTP_HOST_RESET_IND, NULL);
		msg_send_ext_queue(usb_ilm);
	}
}


#endif   /* PICTBRIDGE_SUPPORT */

