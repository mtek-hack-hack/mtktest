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
 *   ptp_state.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements the PICTURE TRANSFER PROTOCOL definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef PTP_STATE_H
#define PTP_STATE_H

#include "usb_custom.h"
#include "fat_fs.h"


/***********************************************
	PTP specific command definitions
************************************************/ 
/* Operation Codes */
#define PTP_GET_DEVICE_INFO				0x1001
#define PTP_OPEN_SESSION					0x1002
#define PTP_CLOSE_SESSION					0x1003
#define PTP_GET_STORAGE_IDS				0x1004
#define PTP_GET_STORAGE_INFO				0x1005
#define PTP_GET_NUM_OBJECTS				0x1006
#define PTP_GET_OBJECT_HANDLES			0x1007
#define PTP_GET_OBJECT_INFO				0x1008
#define PTP_GET_OBJECT						0x1009
#define PTP_GET_THUMB						0x100A
#define PTP_SEND_OBJECT_INFO				0x100C
#define PTP_SEND_OBJECT					0x100D
#define PTP_GET_PARTIAL_OBJECT				0x101B

/* Response Codes */
#define PTP_OK								0x2001
#define PTP_GENERAL_ERROR					0x2002
#define PTP_SESSION_NOT_OPEN				0x2003
#define PTP_OPERATION_NOT_SUPPORTED		0x2005	
#define PTP_PARAMETER_NOT_SUPPORTED		0x2006
#define PTP_NO_THUMBNAIL_PRESENT			0x2010
#define PTP_DEVICE_BUSY					0x2019
#define PTP_TRANSACTION_CANCELLED		0x201F

/* Event Codes */
#define PTP_CANCEL_TRANSACTION			0x4001
#define PTP_OBJECT_ADDED					0x4002
#define PTP_OBJECT_REMOVED					0x4003
#define PTP_STORE_ADDED					0x4004
#define PTP_STORE_REMOVED					0x4005
#define PTP_OBJECT_INFO_CHAGNED			0x4007
#define PTP_REQUEST_OBJECT_TRANSFER		0x4009


/* Object Format Codes*/
#define PTP_ASSOCIATION					0x3001
#define PTP_SCRIPT							0x3002
#define PTP_DPOF							0x3006
#define PTP_EXIF_JPEG						0x3801
#define PTP_TIFF_EP							0x3802
#define PTP_BMP								0x3804
#define PTP_CIFF								0x3805
#define PTP_GIF								0x3807
#define PTP_JFIF								0x3808
#define PTP_PNG								0x380B
#define PTP_TIFF								0x380D
#define PTP_TIFF_IT							0x380E

/* Functional Mode Values*/
#define PTP_STANDARD_MODE					0x0000
#define PTP_SLEEP_STATE					0x0001

/*  ObjectInfo ProtectionStatus Values*/
#define PTP_NO_PROTECTION					0x0000
#define PTP_READ_ONLY						0x0001

/*  Storage Types */
#define PTP_FIXED_ROM						0x0001
#define PTP_REMOVABLE_ROM					0x0002
#define PTP_FIXED_RAM						0x0003
#define PTP_REMOVABLE_RAM					0x0004

/*  File System Type Values */
#define PTP_GENERIC_FLAT					0x0001
#define PTP_GENERIC_HIERARCHICAL			0x0002
#define PTP_DCF								0x0003

/*  StorageInfo AccessCapability Values */
#define PTP_READ_WRITE						0x0000
#define PTP_READ_ONLY_WITHOUT_DELETION	0x0001
#define PTP_READ_ONLY_WITH_DELETION		0x0002

/* Association Types */
#define PTP_GENERIC_FOLDER					0x0001
#define PTP_ALBUM							0x0002
#define PTP_TIME_SEQUENCE					0x0003
#define PTP_HORIZONTAL_PANORAMIC			0x0004
#define PTP_VERTICAL_PANORAMIC			0x0005
#define PTP_2D_PANORAMIC					0x0006
#define PTP_ANCILLARY						0x0007

/***********************************************
	implement definition
************************************************/
#define	PTP_MAX_OPERATION_CODE_SIZE				13
#define	PTP_MAX_EVENT_CODE_SIZE					7
#define	PTP_MAX_OBJECT_FORMAT_CODE_SIZE		2
#define	PTP_MAX_OBJECT_HANDLES					6
#define	PTP_OBJECT_INFO_SIZE					94

#define   PTP_SCRIPT_STORAGE_ID			0x00000000
#define   PTP_IMAGE_STORAGE_ID				0x00010001
#define   PTP_ALL_STORAGE_ID				0x0001FFFF

/* Script object handle */
#define	DDISCVRY_DPS   		 				0xC1000000
#define	HDISCVRY_DPS    					0xC1000001
#define	DREQUEST_DPS   					0xC1000002
#define	DRSPONSE_DPS  						0xC1000003
#define	HREQUEST_DPS    					0xC1000004
#define	HRSPONSE_DPS   					0xC1000005

/* Script object flag shift */
#define	DDISCVRY  		 							0
#define	HDISCVRY    									1
#define	DREQUEST  									2
#define	DRSPONSE									3
#define	HREQUEST    									4
#define	HRSPONSE  									5

#define	PTP_NO_HANDLE								-1

#define   PTP_MAX_INTERRUPT_PKT					5

/***********************************************
	implement enum and structure 
************************************************/
typedef enum 
{
	PTP_CMD_RX = 0,  			/* Initial Idle Phase, Receive Command */
	PTP_DATA_TX,  				/* Transmit Data Phase */
	PTP_DATA_RX,				/* Receive Data Phase*/
	PTP_RESPONSE 	 			/* Transmit Response phase*/
}PTP_STATE;

typedef struct
{
	kal_uint32	ContainerLength;
	kal_uint16	ContainerType;
	kal_uint16	Code;
	kal_uint32	TransactionID;
	kal_uint32	Parameter1;
	kal_uint32	Parameter2;
	kal_uint32	Parameter3;	
} PTP_CONTAINER;

typedef struct
{
	kal_uint32	ContainerLength;
	kal_uint16	ContainerType;
	kal_uint16	Code;
	kal_uint32	TransactionID;
	kal_uint32	Parameter1;
}PTP_EVENT_CONTAINER;

typedef struct
{
	kal_uint16	StandardVersion;
	kal_uint16	VenderExtensionID[2];
	kal_uint16	VenderExtensionVersion;
	kal_uint8		VendorExtensionDesc;				/* empty string */
	kal_uint8 	FunctionalMode[2];
	kal_uint8	       OperationsSupportedSize[4];
	kal_uint8		OperationsSupported[PTP_MAX_OPERATION_CODE_SIZE][2];
	kal_uint8		EventsSupportedSize[4];
	kal_uint8		EventsSupported[PTP_MAX_EVENT_CODE_SIZE][2];
	kal_uint8		DevicePropertiesSupportedSize[4];	/* empty array*/
	kal_uint8		CaptureFormatsSize[4];				/* empty array*/
	kal_uint8		ImageFormatsSize[4];
	kal_uint8		ImageFormats[PTP_MAX_OBJECT_FORMAT_CODE_SIZE][2];
	kal_uint8		padding;	
} PTPDeviceInfo_Struct;


typedef struct
{
	kal_uint16	StorageType;
	kal_uint16	FilesystemType;
	kal_uint16	AccessCapability;
	kal_uint16	MaxCapacity[4];
	kal_uint16	FreeSpaceInBytes[4];
	kal_uint16	FreeSpaceInImages[2];
} PTPStorageInfo_Struct;


typedef struct
{
	kal_uint32	StorageID;
	kal_uint16	ObjectFormat;
	kal_uint16	ProtectionStatus;
	kal_uint32	ObjectCompressedSize;
	kal_uint16	ThumbFormat;
	kal_uint16	ThumbCompressedSize[2];
	kal_uint16	ThumbPixWidth[2];
	kal_uint16	ThumbPixHeight[2];
	kal_uint16	ImagePixWidth[2];
	kal_uint16	ImagePixHeight[2];
	kal_uint16	ImageBitDepth[2];
	kal_uint16	ParentObject[2];
	kal_uint16	AssociationType;
	kal_uint32	AssociationDesc;
	kal_uint32	SequenceNumber;
}PTPObjectInfo_Struct;


typedef struct
{
	PTP_STATE					state; 					/* PTP state machine */
	USB_IMAGE_INTR_PIPE_STATE	intr_state;				/* interrupt pipe state machine */
	Usb_EpBIn_Status				*txpipe;
	Usb_EpBOut_Status			*rxpipe;
	Usb_EpBIn_Status				*intrpipe;

	Usb_Ep_Info					*image_ep_in_info;
	Usb_Ep_Info					*image_ep_out_info;
	Usb_Ep_Info					*image_ep_intr_info;
	Usb_Interface_Info				*image_if_info;

	/* pointer to buffer for XML packet transmission operation*/
//	kal_uint8						*dps_tx_data;
	kal_uint8						*dps_request_tx_data;
	kal_uint8						*dps_response_tx_data;	
	kal_uint8						*dps_request_rx_data;
	kal_uint8						*dps_response_rx_data;

	/* the PTP container  */
	PTP_CONTAINER				image_cmd;
	PTP_CONTAINER				image_response;
	PTP_EVENT_CONTAINER		image_event;

	/* buffer for data/image transmission operation*/
	USB_IMAGE_BUFFER			*image_buffer;

	/* buffer for data/image's info transmission operation */
	kal_uint8						*image_info_buffer;

	/*  Image class ep0 cmd structure */
	USB_IMAGE_BLOCK_STRUCT		cancel_block;
	USB_IMAGE_DEVICE_STATUS_STRUCT	device_status;

	/* PTP dataset structure */
	PTPDeviceInfo_Struct			image_deviceinfo;
	PTPStorageInfo_Struct			image_storageinfo;
	PTPObjectInfo_Struct			image_objectinfo;

	PTP_EVENT_CONTAINER		image_event_array[PTP_MAX_INTERRUPT_PKT];
	
	kal_uint32					current_transactionID;
	kal_uint32					total_rx_bytes;
	kal_uint32					current_rx_bytes;
	kal_uint32					total_tx_bytes;
	kal_uint32					current_tx_bytes;
	kal_uint32					rw_bytes;				/* R/W bytes for FS R/W*/
	kal_uint32					received_xml_size;
	kal_uint32					send_dps_request_xml_size;
	kal_uint32					send_dps_response_xml_size;
	FS_HANDLE					current_file_handle;		/* current file handle opened by USB  */

//	kal_uint8   					dps_discovery_timeout_handle;
	kal_uint8						dps_rx_buffer_index;	/* Rx XML buffer index */
	kal_uint8						script_flag;				/* XML script flag */
	kal_uint8						rw_buffer_index;		/*  buffer index for double buffer */
	kal_uint8						intr_read_ptr;
	kal_uint8						intr_write_ptr;


	kal_bool						dps_discovery;
	kal_bool						error;					/*  a flag to check if there is any error happened at the file system operation of image file  */
	kal_bool						host_cancel_flag;		/*  a flag for ep0 get device status cmd to return response code  */
	kal_bool						send_ptp_reset_ilm; 		 /*  a flag to check whether it needs to send the reset message */
	kal_bool						mmi_start_job;			/* a flag to check if it is doing a job now*/
//	kal_bool						intr_done;				/*  a flag to check whether the interrupt packet has been ACKed */
	kal_bool						next_xml_is_start_job;
	kal_bool						is_start_job_xml;
	kal_bool						ptp_stop;
	kal_bool						is_suspend_state;
	kal_bool						out_pipe_race;
	kal_bool						is_wait_host_respone;
	kal_bool						is_session_open;


	/* customizable variables*/
   	const USB_IMAGE_PARAM		*image_param;
} PTP_Struct;


/***********************************************
	function and global variable
************************************************/
extern PTP_Struct	g_USBImage;

extern void PTP_Parse_MMI_Meg(ilm_struct *p_recv_ilm);
extern void PTP_Parse_USB_Meg(ilm_struct *p_recv_ilm);


#endif /* PTP_STATE_H */


