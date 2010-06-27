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
 *   usbvideo_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for usb video class driver definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USBVIDEO_DRV_H
#define USBVIDEO_DRV_H


#include "usbvideo_custom.h"
#include "usbvideo_if.h"

//#define WEBCAM_TEST_DMA_DELAY


/***********************************************
	video class specific command definition
************************************************/ 

/* device descriptor parameter */
#define USBVIDEO_DEVICE_CODE						0xEF
#define USBVIDEO_SUBCLASS_CODE					0x02
#define USBVIDEO_PROTOCOL_CODE					0x01

/*Scriptor length*/
#define USBVIDEO_VC_INTERFACE_LENGTH				13
#define USBVIDEO_VC_CT_LENGTH						17
#define USBVIDEO_VC_OT_LENGTH						9
#define USBVIDEO_VC_PU_LENGTH						11
//#define USBVIDEO_VC_PU_LENGTH						12	/* for 1.1 version*/
#define USBVIDEO_VC_INTR_LENGTH					5

#define USBVIDEO_VS_INTERFACE_LENGTH				14
#define USBVIDEO_VS_MJPEG_FORMAT_LENGTH			11
#define USBVIDEO_VS_MJPEG_FRAME_LENGTH			38
#define USBVIDEO_VS_STILL_LENGTH					6
#define USBVIDEO_VS_COLOR_MATCHING_LENGTH		6

/* video interface class code */
#define USBVIDEO_CC_VIDEO		 					0x0e

/* video interface subclass code */
#define USBVIDEO_SC_UNDEFINED		 				0x00
#define USBVIDEO_SC_VIDEOCONTROL					0x01
#define USBVIDEO_SC_VIDEOSTREAMING				0x02
#define USBVIDEO_SC_VIDEO_INTERFACE_COLLECTION	0x03

/* video interface protocol code */
#define USBVIDEO_PC_PROTOCOL_UNDEFINED			0x00

/* class specific descriptor types*/
#define USBVIDEO_CS_UNDEFINED						0x20
#define USBVIDEO_CS_DEVICE							0x21
#define USBVIDEO_CS_CONFIGURATION				0x22
#define USBVIDEO_CS_STRING							0x23
#define USBVIDEO_CS_INTERFACE						0x24
#define USBVIDEO_CS_ENDPOINT						0x25

/* class specifiv VC interface descriptor subtypes*/
#define USBVIDEO_VC_DESCRIPTOR_UNDEFINED		0x00
#define USBVIDEO_VC_HEADER						0x01
#define USBVIDEO_VC_INPUT_TERMINAL				0x02
#define USBVIDEO_VC_OUTPUT_TERMINAL				0x03
#define USBVIDEO_VC_SELECTOR_UNIT					0x04
#define USBVIDEO_VC_PROCESSING_UNIT				0x05
#define USBVIDEO_VC_EXTENSION_UNIT				0x06

/* class specifiv VS interface descriptor subtypes*/
#define USBVIDEO_VS_UNDEFINED						0x00
#define USBVIDEO_VS_INPUT_HEADER					0x01
#define USBVIDEO_VS_OUTPUT_HEADER				0x02
#define USBVIDEO_VS_STILL_IMAGE_FRAME			0x03
#define USBVIDEO_VS_FORMAT_UNCOMPRESSED			0x04
#define USBVIDEO_VS_FRAME_UNCOMPRESSED			0x05
#define USBVIDEO_VS_FORMAT_MJPEG					0x06
#define USBVIDEO_VS_FRAME_MJPEG					0x07
#define USBVIDEO_VS_FORMAT_MPEG1					0x08
#define USBVIDEO_VS_FORMAT_MPEG2PS				0x09
#define USBVIDEO_VS_FORMAT_MPEG2TS				0x0a
#define USBVIDEO_VS_FORMAT_MPEG4SL				0x0b
#define USBVIDEO_VS_FORMAT_DV						0x0c
#define USBVIDEO_VS_COLORFORMAT					0x0d
#define USBVIDEO_VS_FORMAT_VENDOR				0x0e
#define USBVIDEO_VS_FRAME_VENDOR					0x0f

/* USB terminal types */
#define USBVIDEO_TT_VENDOR_SPECIFIC				0x0100
#define USBVIDEO_TT_STREAMING						0x0101

/* input terminal types */
#define USBVIDEO_ITT_VENDOR_SPECIFIC				0x0200	
#define USBVIDEO_ITT_CAMERA						0x0201
#define USBVIDEO_ITT_MEDIA_TANSPORT_INPUT		0x0202

/* still image capture method */
#define USBVIDEO_STILL_CAPTURE_METHOD_1			1
#define USBVIDEO_STILL_CAPTURE_METHOD_2			2
#define USBVIDEO_STILL_CAPTURE_METHOD_3			3

/* hardware trigger usage*/
#define USBVIDEO_HARDWARE_TRIGGER_NOT_SUPPORT	0
#define USBVIDEO_HARDWARE_TRIGGER_SUPPORT		1
#define USBVIDEO_HARDWARE_TRIGGER_STILL			0
#define USBVIDEO_HARDWARE_TRIGGER_GENERAL		1

/* MJPEG format descriptor param */
#define USBVIDEO_FIXED_SIZE_SAMPLES				1

/* request code */
#define USBVIDEO_RC_UNDEFINED        	 			0x00
#define USBVIDEO_SET_CUR	    		 				0x01
#define USBVIDEO_GET_CUR	    		 				0x81
#define USBVIDEO_GET_MIN	    		 				0x82
#define USBVIDEO_GET_MAX	    		 				0x83
#define USBVIDEO_GET_RES	    		 				0x84
#define USBVIDEO_GET_LEN	    		 				0x85
#define USBVIDEO_GET_INFO	    		 				0x86
#define USBVIDEO_GET_DEF	    		 				0x87

/* VideoControl Interface Control Selectors */
#define USBVIDEO_VC_CONTROL_UNDEFINED				0x00
#define USBVIDEO_VC_VIDEO_POWER_MODE_CONTROL		0x01
#define USBVIDEO_VC_REQUEST_ERROR_CODE_CONTROL		0x02

/* RequestErrorCode */
#define USBVIDEO_VC_REQUEST_ERROR_NO_ERROR				0x00
#define USBVIDEO_VC_REQUEST_ERROR_NOT_READY			0x01
#define USBVIDEO_VC_REQUEST_ERROR_WRONG_STATE			0x02
#define USBVIDEO_VC_REQUEST_ERROR_POWER					0x03
#define USBVIDEO_VC_REQUEST_ERROR_OUT_OF_RANGE			0x04
#define USBVIDEO_VC_REQUEST_ERROR_INVALID_UNIT			0x05
#define USBVIDEO_VC_REQUEST_ERROR_INVALID_CONTROL		0x06
#define USBVIDEO_VC_REQUEST_ERROR_INVALID_REQUEST		0x07
#define USBVIDEO_VC_REQUEST_ERROR_UNKNOWN				0xff

/* videostreaming interface control selectors */
#define USBVIDEO_VS_US_CONTROL_UNDEFINED			0x0000
#define USBVIDEO_VS_PROBE_CONTROL					0x0100
#define USBVIDEO_VS_COMMIT_CONTROL					0x0200
#define USBVIDEO_VS_STILL_PROBE_CONTROL				0x0300
#define USBVIDEO_VS_STILL_COMMIT_CONTROL				0x0400
#define USBVIDEO_VS_STILL_IMAGE_TRIGGER_CONTROL		0x0500
#define USBVIDEO_VS_STREAM_ERROR_CODE_CONTROL		0x0600
#define USBVIDEO_VS_GENERATE_KEY_FRAME_CONTROL		0x0700
#define USBVIDEO_VS_UPDATE_FRAME_SEGMENT_CONTROL	0x0800
#define USBVIDEO_VS_SYNC_DELAY_CONTROL				0x0900

/* payload header info offset */
#define USBVIDEO_PAYLOAD_FRAME_ID				0
#define USBVIDEO_PAYLOAD_EOF						1
#define USBVIDEO_PAYLOAD_PTS						2
#define USBVIDEO_PAYLOAD_SCR						3
#define USBVIDEO_PAYLOAD_RESVD					4
#define USBVIDEO_PAYLOAD_STILL					5
#define USBVIDEO_PAYLOAD_ERR						6
#define USBVIDEO_PAYLOAD_EOH						7

/* the setting of still image trigger control */
#define USBVIDEO_STILL_IMAGE_NORMAL_OPERATION		0
#define USBVIDEO_STILL_IMAGE_TRANSMIT				1
#define USBVIDEO_STILL_IMAGE_TRANSMIT_DEDICATED		2
#define USBVIDEO_STILL_IMAGE_ABORT					3

/* status type for status packet */
#define USBVIDEO_STATUS_TYPE_RESERVED			0
#define USBVIDEO_STATUS_TYPE_VC					1
#define USBVIDEO_STATUS_TYPE_VS					2

#define USBVIDEO_STATUS_VC_ATTRIBUTRE_CONTROL_VALUE_CHANGE 		0x00
#define USBVIDEO_STATUS_VC_ATTRIBUTRE_CONTROL_INFO_CHANGE 		0x01
#define USBVIDEO_STATUS_VC_ATTRIBUTRE_CONTROL_FAILURE_CHANGE 	0x02

#define USBVIDEO_STATUS_VS_EVENT_BUTTOM_PRS	0x00
#define USBVIDEO_STATUS_VS_EVENT_STREAM_ERR		0x01

#define USBVIDEO_STATUS_VS_VALUE_BUTTOM_REL		0x00
#define USBVIDEO_STATUS_VS_VALUE_BUTTOM_PRS	0x01

/* Attribute information(capability) offset*/
#define USBVIDEO_ATTR_INFO_SUPPORT_GET			0
#define USBVIDEO_ATTR_INFO_SUPPORT_SET			1
#define USBVIDEO_ATTR_INFO_DISBALE				2
#define USBVIDEO_ATTR_INFO_AUTO_UPDATE			3
#define USBVIDEO_ATTR_INFO_ASYNC_CTRL			4

/***********************************************
	implement definition
************************************************/

#define USBVIDEO_VC_EP_NUMBER     					1  /*interrupt pipe*/
#define USBVIDEO_VS_EP_NUMBER     					1

#define USBVIDEO_IF_LENGTH     						258
#define USBVIDEO_IF_NUMBER      						2


#define USBVIDEO_CLOCK_FREQUENCY					1000

#define USBVIDEO_CT_ID								1
#define USBVIDEO_OT_ID								2
#define USBVIDEO_PU_ID								3

#define USBVIDEO_MAX_PAYLOAD_LENGTH				1024

#define USBVIDEO_VIDEO_BUFFER_NUMBER				3

#define USBVIDEO_PAYLOAD_HEADER_LENGTH			12

#define USBVIDEO_MAX_ATTR_VALUE_SIZE				16

/***********************************************
	video class specific descriptor structure
************************************************/
/* class specific VC interface descriptor */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bcdUSB[2];
	kal_uint8    wTotalLength[2];
	kal_uint8    dwClockFrequency[4];
	kal_uint8    bInCollection;
	kal_uint8    baInterfaceNr;
} USBVideo_Class_VC_If_Dscr;

/* class specific VC input(camera) terminal descriptor */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bTerminalID;
	kal_uint8    wTerminalType[2];
	kal_uint8    bAssocTerminal;
	kal_uint8    iTerminal;
	kal_uint8    wObjectiveFocalLengthMin[2];
	kal_uint8    wObjectiveFocalLengthMax[2];
	kal_uint8    wOcularFocalLength[2];
	kal_uint8    bControlSize;
	kal_uint8    bmControls[2];
} USBVideo_CT_Dscr;

/* class specific VC output terminal descriptor */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bTerminalID;
	kal_uint8    wTerminalType[2];
	kal_uint8    bAssocTerminal;
	kal_uint8    bSourceID;
	kal_uint8    iTerminal;
} USBVideo_OT_Dscr;

/* class specific VC processing unit descriptor */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bUintID;
	kal_uint8    bSourceID;
	kal_uint8    wMaxMultiplier[2];
	kal_uint8    bControlSize;
	kal_uint8    bmControls[2];
	kal_uint8    iProcessing;
	//kal_uint8	   bmVideoStandards;
} USBVideo_PU_Dscr;


/* class specific interrupt endpoint descriptor */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    wMaxTransferSize[2];
} USBVideo_Intr_Ep_Dscr;


/* class specific VS interface descriptor */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bNumFormats;
	kal_uint8    wTotalLength[2];
	kal_uint8    bEndpointAddress;
	kal_uint8    bmInfo;
	kal_uint8    bTerminalLink;
	kal_uint8    bStillCaptureMethod;
	kal_uint8    bTriggerSupport;
	kal_uint8    bTriggerUsage;
	kal_uint8    bControlSize;
	kal_uint8    bmaControls;	
} USBVideo_Class_VS_If_Dscr;

/* MJPEG video format descriptor */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bFormatIndex;
	kal_uint8    bNumFrameDescriptors;
	kal_uint8    bmFlags;
	kal_uint8    bDefaultFrameIndex;
	kal_uint8    bAspectRatioX;	
	kal_uint8    bAspectRatioY;
	kal_uint8    bmInterlaceFlags;	
	kal_uint8    bCopyProtect;
} USBVideo_MJPEG_Format_Dscr;

/* MJPEG video frame descriptor */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bFrameIndex;
	kal_uint8    bmCapabilities;
	kal_uint8    wWidth[2];
	kal_uint8    wHeight[2];
	kal_uint8    dwMinBitRate[4];
	kal_uint8    dwMaxBitRate[4];
	kal_uint8    dwMaxVideoFrameBufferSize[4];
	kal_uint8    dwDefaultFrameInterval[4];	
	kal_uint8    bFrameIntervalType;
	kal_uint8    dwMinFrameInterval[4];	
	kal_uint8    dwMaxFrameInterval[4];	
	kal_uint8    dwFrameIntervalStep[4];	
} USBVideo_MJPEG_Frame_Dscr;

/* still size structure */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct
{
	kal_uint8  wWidth[2];
	kal_uint8  wHeight[2];
}USBVideo_Still_Size;

/* Still image frame descriptor */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bEndpointAddress;
	kal_uint8    bNumImageSizePatterns;
	USBVideo_Still_Size *p_image_patterns;
	kal_uint8    bNumCompressionPattern;
	kal_uint8    *p_compression_patterns;
} USBVideo_Still_Frame_Dscr;

/* Color matching descriptor */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bDescriptorSubType;
	kal_uint8    bColorPrimaries;
	kal_uint8    bTransferCharacteristics;
	kal_uint8    bMatrixCoefficients;
} USBVideo_Color_Dscr;

/* video probe and commit setting */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct
{
	kal_uint8		bmHint[2];
	kal_uint8		bFormatIndex;
	kal_uint8		bFrameIndex;
	kal_uint8		dwFrameInterval[4];
	kal_uint8		wKeyFrameRate[2];
	kal_uint8		wPFrameRate[2];
	kal_uint8		wCompQuality[2];
	kal_uint8		wCompWindowSize[2];
	kal_uint8		wDelay[2];
	kal_uint8 	dwMaxVideoFrameSize[4];
	kal_uint8		dwMaxPayloadTransferSize[4];
	//kal_uint8		dwClockFrequency[4];
	//kal_uint8		bmFramingInfo;
	//kal_uint8		bPreferedVersion;
	//kal_uint8		bMinVersion;
	//kal_uint8		bMaxVersion;
}USBVideo_Probe_Commit_Struct;

/* still probe and commit setting */
/* Note that the kal_uint8[2] array can not modify to kal_uint16 
    It is bacause align issue */
typedef struct
{
	kal_uint8		bFormatIndex;
	kal_uint8		bFrameIndex;
	kal_uint8		bCompressionIndex;	
	kal_uint8 	dwMaxVideoFrameSize[4];
	kal_uint8		dwMaxPayloadTransferSize[4];
}USBVideo_Still_Probe_Commit_Struct;

typedef struct
{
	kal_uint8		bHeaderLength;
	kal_uint8		bmHeaderInfo;
	kal_uint8		dwPTS[4];
	kal_uint8		dwSCR[6];
}USBVideo_Payload_Header;

typedef struct
{
	kal_uint8		bStuausType;
	kal_uint8		bOriginator;
	kal_uint8		bEvent;
	kal_uint8		bValue;
}USBVideo_VS_Status_Pkt_Struct;

typedef struct
{
	kal_uint8		bStuausType;
	kal_uint8		bOriginator;
	kal_uint8		bEvent;
	kal_uint8		bSelector;
	kal_uint8		bAttribute;
	kal_uint8		bValue;
}USBVideo_VC_Status_Pkt_Struct;

/***********************************************
	implement enum and structure 
************************************************/

typedef enum
{
	/* msg between media and USB */
	USBVIDEO_MSG_MED_START_SUCCESS_CNF,
	USBVIDEO_MSG_MED_START_FAIL_CNF,
	USBVIDEO_MSG_MED_CHANGE_VIDEO_IND,
	USBVIDEO_MSG_MED_STILL_CAPTURE_IND,
	USBVIDEO_MSG_MED_START_IND,
	USBVIDEO_MSG_MED_DEVICE_STILL_CNF,
	USBVIDEO_MSG_MED_PAUSE_CNF,
	USBVIDEO_MSG_MED_RESUME_SUCCESS_CNF,
	USBVIDEO_MSG_MED_RESUME_FAIL_CNF,
	USBVIDEO_MSG_MED_STOP_IND,
	USBVIDEO_MSG_MED_STOP_CNF,
	USBVIDEO_MSG_MED_ABORT_IND,

	/* msg used in internal USB driver */
	USBVIDEO_MSG_USB_ENUM_DONE,
	USBVIDEO_MSG_USB_COMPLETE_VIDEO,
	USBVIDEO_MSG_USB_DMA_DONE,
	USBVIDEO_MSG_USB_CHANGE_SIZE,
	USBVIDEO_MSG_USB_STILL_CAPTURE,
	USBVIDEO_MSG_USB_COMPLETE_STILL,
	USBVIDEO_MSG_USB_STILL_DMA_DONE,
	USBVIDEO_MSG_USB_STILL_DMA_PARTIAL,
	USBVIDEO_MSG_USB_INCALL_DMA_DONE,
	USBVIDEO_MSG_USB_INCALL_TIMEOUT,
	USBVIDEO_MSG_USB_INCALL_CHANGE_SIZE, 
	USBVIDEO_MSG_USB_ABORT
}USBVIDEO_MSG_TYPE;

typedef enum
{
	USBVIDEO_STATE_STOP,
	USBVIDEO_STATE_SEND,
	USBVIDEO_STATE_DROP,
	USBVIDEO_STATE_STILL,
	USBVIDEO_STATE_PRE_PAUSE,	
	USBVIDEO_STATE_PAUSE
}USBVIDEO_STATE;

typedef enum
{
	USBVIDEO_PROBE_NONE,
	USBVIDEO_PROBE_IN,
	USBVIDEO_PROBE_DONE,
	USBVIDEO_COMMIT_IN,
	USBVIDEO_COMMIT_DONE
}USBVIDEO_PROBE_STATE;

typedef enum
{
	USBVIDEO_START_NONE,
	USBVIDEO_START_RECV_MED_REQ,
	USBVIDEO_START_RECV_COMMIT,
	USBVIDEO_START_DONE
}USBVIDEO_START_STATE;

typedef enum
{
	USBVIDEO_DMA_VIDEO,
	USBVIDEO_DMA_STILL,
	USBVIDEO_DMA_INCALL_JPEG,
	USBVIDEO_DMA_NONE
}USBVIDEO_DMA_TYPE;

typedef enum
{
	USBVIDEO_DMA_DONE_COMPLETE,
	USBVIDEO_DMA_DONE_STOP  /* DMA stop because of timeout, clear halt feature ,or commit but does not change size */
}USBVIDEO_DMA_DONE_TYPE;


typedef enum
{
	USBVIDEO_NO_ERROR = 0,
	USBVIDEO_ERROR_NOT_READY,
	USBVIDEO_ERROR_WRONG_STATE,
	USBVIDEO_ERROR_POWER,
	USBVIDEO_ERROR_OUT_OF_RANGE,
	USBVIDEO_ERROR_INVALID_UNIT,
	USBVIDEO_ERROR_INVAILD_CONTROL,
	USBVIDEO_ERROR_INVAILD_REQUEST,
	USBVIDEO_ERROR_UNKNOWN
}USBVideo_ERROR_CODE;


typedef struct
{
	kal_uint8			subtype;
	kal_uint8			length;
}USBVideo_Attr_Sub_Map;

typedef struct
{
	USBVIDEO_ATTRIBUTE_TYPE	attr_type;
	kal_uint32 					shift;
	kal_uint8						length;
	const USBVideo_Attr_Sub_Map		*subtype_table;
}USBVideo_Attr_Map;

typedef struct
{
	kal_uint32		video_size[USBVIDEO_VIDEO_BUFFER_NUMBER];  /* complete video size returned by camera */
	kal_uint8			*video_buffer_addr[USBVIDEO_VIDEO_BUFFER_NUMBER];  /* buffer start address */
	kal_uint32		video_buffer_size;  /* each buffer size */
	kal_uint8			video_buffer_read_index;  /* read pointer */
	kal_uint8			video_buffer_write_index;  /* write pointer */
	kal_bool			video_buffer_full;  /* full flag */
	kal_bool			send_video_msg;  /* indicate whether complete function should send complete msg to USB task */
	kal_uint32		sent_video_size;  /* already sent size for the current transmitting buffer */
	kal_uint8			video_frame_id;  /* even/odd id filled in payload header */

	kal_uint32		still_size;
	kal_uint8			still_count;

	kal_uint8			*incall_jpeg_addr;
	kal_uint32 		incall_jpeg_size;
	kal_uint8			*incall_jpeg_buff;
		
	USBVIDEO_DMA_TYPE	dma_type;
	USBVIDEO_DMA_DONE_TYPE	dma_done_type;
//	kal_bool				b_processing_dma;  /* be set at DMA callback*/

	kal_uint8			timer_handle;
	kal_bool			b_stop_timer;   /* TRUE when clear halt cmd */

	const USBVideo_Video_Size_Info	*p_video_size_info;     /*  be set at USBVideo_VS_If_Create() */
	const USBVideo_Still_Size_Info	*p_still_size_info;
	kal_uint8	video_size_num;
	kal_uint8	still_size_num;

	kal_uint32 default_jpeg_max_size[USBVIDEO_VIDEO_SIZE_MAX];          /* be set by MMI */
	kal_bool b_set_default_jpeg_max_size[USBVIDEO_VIDEO_SIZE_MAX];
}USBVideo_Control_Struct;


typedef struct
{
	Usb_EpBIn_Status	*intrpipe;		/* interrupt EP, VC Interface */
	Usb_EpBIn_Status	*txpipe;			/* Bulk IN EP, VS Interface */

	Usb_Ep_Info		*vc_ep_intr_info;
	Usb_Ep_Info		*vs_ep_in_info;
	Usb_Interface_Info	*vc_if_info;
	Usb_Interface_Info	*vs_if_info;
	Usb_IAD_Dscr		*iad_desc;


	USBVideo_Probe_Commit_Struct	vs_probe_control;
	USBVideo_Probe_Commit_Struct  vs_recv_probe_control;
	kal_uint8	commit_video_index;
	kal_uint8 video_compression_index;
	USBVIDEO_PROBE_STATE 		probe_state;

	USBVideo_Still_Probe_Commit_Struct vs_still_probe_control;
	USBVideo_Still_Probe_Commit_Struct vs_recv_still_probe_control;
	kal_uint8	commit_still_index;
	kal_uint8 commit_still_compression_index;
	USBVIDEO_PROBE_STATE 		still_probe_state;
	USBVideo_VS_Status_Pkt_Struct	vs_status_pkt;
	USBVideo_VC_Status_Pkt_Struct	vc_status_pkt;
	USBVIDEO_START_STATE	video_start_state;
	USBVideo_Control_Struct	video_control;
	USBVideo_Attr_Value 		set_attr_value;  /* be used at set attr value*/
	USBVideo_ERROR_CODE 	error_code;
	USBVIDEO_STATE state;

	kal_uint32		vc_ct_support;
	kal_uint32		vc_ct_set;
	kal_uint32		vc_pu_support;
	kal_uint32		vc_pu_set;
	kal_uint8			vc_ct_subtype_cnf[USBVIDEO_ATTRIBUTE_CT_MAX];
	kal_uint8			vc_pu_subtype_cnf[USBVIDEO_ATTRIBUTE_PU_MAX-0x80];
	kal_uint8			vs_interface_id;
	kal_bool			vc_intr_done;  /*decide if issue interrupt  */
	kal_bool			vc_set_white_balance_temp_intr;
	kal_bool			vc_white_balance_error_setting;
	kal_bool			usb_video_dma_stop;
	kal_bool			is_get_buffer_after_change_size;

	/* default jpeg provided by MMI */
	usbvideo_default_JPEG_Info  *default_jpeg_info;   /* incall JPEG, get from media task when pause request  */
	kal_uint8				default_jpeg_num;

	/* customizable variables*/
   	const USB_VIDEO_PARAM		*custom_param;
	const USBVideo_Camera_Param 	*camera_param;
	//const USBVideo_MMI_Param		*mmi_param;


#ifdef WEBCAM_TEST_DMA_DELAY
	kal_uint8			test_timer_handle;
	kal_bool			test_enable;
#endif	
} USBVideo_Struct;

typedef struct 
{
	LOCAL_PARA_HDR
	kal_uint8 	index;
}usbvideo_still_dma_struct; 


/***********************************************
	function and global variable
************************************************/
extern USBVideo_Struct g_USBVideo;

extern void USBVideo_Send_Msg(USBVIDEO_MSG_TYPE msg_type, kal_uint32 param1, kal_uint32 param2);
extern kal_bool USBVideo_Get_Attr_WBalanceTmp_Auto_Cur_Value(void);
extern void USBVideo_VC_If_Create(void *ifname);
extern void USBVideo_VC_If_Reset(void);
extern void USBVideo_VC_If_Speed_Reset(kal_bool b_other_speed);
extern void USBVideo_VS_If_Create(void *ifname);
extern void USBVideo_VS_If_Reset(void);
extern void USBVideo_VS_If_Speed_Reset(kal_bool b_other_speed);

extern void USB_Init_Video_Status(void);
extern void USB_Release_Video_Status(void);

extern kal_bool USBVideo_Send_Intr(void *addr,kal_uint32 len);

extern void USBVideo_Send_Incall_JPEG(void);
extern void USBVideo_Send_Video(void);


/*********************************
		Debug utility
************************************/

#define USBVIDEO_DBG_DATA_SIZE 1024

typedef enum 
{
      UV_DBG_INCALL_DMA_CALLBACK,
      UV_DBG_TX_DMA_CALLBACK,
      UV_DBG_CLR_FEATURE_CALLBACK,
      UV_DBG_START_VIDEO_REQ_HDLR,
      UV_DBG_VIDEO_DMA_DONE_HDLR,
      UV_DBG_STILL_DMA_DONE_HDLR,
      UV_DBG_PRE_PAUSE_TIMEOUT_HDLR,
      UV_DBG_PAUSE_REQ_HDLR,
      UV_DBG_INCALL_DMA_DONE_HDLR,
      UV_DBG_RESUME_REQ_HDLR,
      UV_DBG_IS_BUFFER_EMPTY,
      UV_DBG_COMPLETE_VIDEO_BUFFER,
      UV_DBG_SEND_COMPLETE_VIDEO_MSG,
      UV_DBG_COMPLETE_VIDEO_HDLR,
      UV_DBG_SEND_ATTR_CNF_MSG,
      UV_DBG_MSG_TYPE,
      UV_DBG_USB_TASK_MSG_TYPE,
      UV_DBG_SEND_COMPLETE_VIDEO_MSG_INTERNAL,
      UV_DBG_SEND_SET_ATTR_REQ_MSG,
      UV_DBG_CUSTOM_TASK_MSG_TYPE,
      UV_DBG_MAX
} USBVIDEO_DBG_INFO;

typedef struct
{
	USBVIDEO_DBG_INFO	tag;
	kal_uint32	parameter;
}USBVideo_Dbg_Data;

typedef struct
{
	USBVideo_Dbg_Data	dbg_data[USBVIDEO_DBG_DATA_SIZE];
	kal_uint16 	dbg_data_idx;
}USBVideo_Dbg_Struct;

extern void USBVideo_Util_Init(void);
extern void USBVideo_Util_Release(void);
extern void USBVideo_Dbg_Trace(USBVIDEO_DBG_INFO tag, kal_uint32 parameter);

#endif /* USBVIDEO_DRV_H */

