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
 *   usb_debug_tool.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb common driver debug buffer definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef USB_DEBUG_TOOL_H
#define USB_DEBUG_TOOL_H

/***********************************************
	implement definition
************************************************/

#define USB_DBG_DATA_SIZE   512

typedef enum
{
	USB_EP0_SET_CONFIGURATION = 1,
	USB_RESET,
	USB_SUSPEND,
	USB_RESUME,
	USB_MS_BUILD_DMA_TX,
	USB_MS_BUILD_DMA_TX_CALLBACK,
	USB_MS_BUILD_DMA_RX,
	USB_MS_BUILD_DMA_RX_CALLBACK,
	USB_MS_BUILD_DMA_RX_START_TIMER,
	USB_MS_BUILD_DMA_RX_STOP_TIMER,
	USB_MS_BUILD_DMA_RX_TIMEOUT,
	USB_MS_ERROR_CMD,
	USB_MS_EP0_RESET,
	USB_MS_BUILD_DMA_RX_BY_RESET_MSG,
	USB_MS_GET_MAX_LUN,
	USB_MS_CMD_TESTUNITREADY,
	USB_MS_CMD_INQUIRY,
	USB_MS_CMD_PREVALLOW_MEDIA_REMOVL,
	USB_MS_CMD_USBMS_WRITE10,
	USB_MS_CMD_USBMS_WRITE12,
	USB_MS_CMD_USBMS_READ10,
	USB_MS_CMD_USBMS_READ12,
	USB_MS_CMD_READ_CAPACITY,
	USB_MS_CMD_READ_FORMATCAPACITY,
	USB_MS_CMD_REQUESTSENSE,
	USB_MS_CMD_USBMS_VERIFY,
	USB_MS_CMD_MODE_SENSE,
	USB_MS_CMD_MODE_SENSE6,
	USB_ACM_DMA_SETUP,
	USB_ACM_DMA_SETUP_1,
	USB_ACM_DMA_SETUP_2,
	USB_ACM_DMA_SETUP_3,
	USB_ACM_DMA_SETUP_4,
	USB_ACM_DMA_CALLBACK,
	USB_ACM_SEND_INTERRUPT,
	USB_ACM_SEND_INTERRUPT1,
	USB_ACM_SEND_INTERRUPT2,
	USB_ACM_INTERRUPT_HANDLER,
	USB_ACM_INTERRUPT_RESET,
	USB_DBG_PTP_GET_DEVICE_INFO,
	USB_DBG_PTP_OPEN_SESSION,
	USB_DBG_PTP_CLOSE_SESSION,
	USB_DBG_PTP_GET_STORAGE_IDS,
	USB_DBG_PTP_GET_STORAGE_INFO,
	USB_DBG_PTP_GET_NUM_OBJECTS,
	USB_DBG_PTP_GET_OBJECT_HANDLES,
	USB_DBG_PTP_GET_OBJECT_INFO,
	USB_DBG_PTP_GET_OBJECT,
	USB_DBG_PTP_GET_THUMB,
	USB_DBG_PTP_GET_PARTIAL_OBJECT,
	USB_DBG_PTP_SEND_OBJECT_INFO,
	USB_DBG_PTP_SEND_OBJECT,
	USB_DBG_IMAGE_SEND_INTERRUPT,
	USB_DBG_IMAGE_SEND_INTERRUPT1,
	USB_DBG_IMAGE_SEND_INTERRUPT2,
	USB_DBG_IMAGE_SEND_INTERRUPT3,
	USB_DBG_IMAGE_INTERRUPT_PKT_FULL,
	USB_DBG_IMAGE_NULL_PKT_TIME_OUT,
	USB_DBG_IMAGE_CABLE_PLUG_OUT,
	USB_DBG_IMAGE_INTERRUPT_HANDLER,
	USB_DBG_DPS_HREQUEST_CONF,
	USB_DBG_DPS_HREQUEST_CONF_CANCEL,
	USB_DBG_DPS_HRESPONSE_CONF,
	USB_DBG_DPS_DREQUEST_REQ,
	USB_DBG_DPS_2_DREQUEST_REQ_WARNING,
	USB_DBG_DPS_DRESPONSE_REQ,
	USB_DBG_DPS_START_JOB_REQ,
	USB_DBG_DPS_CLOSE_JOB_REQ,
	USB_DBG_IMAGE_SESSION_NOT_OPEN_ERROR,
	USB_DBG_IMAGE_CANCEL_BY_DEVICE1,
	USB_DBG_IMAGE_CANCEL_BY_DEVICE2,
	USB_DBG_IMAGE_CANCEL_BY_DEVICE3,
	USB_DBG_IMAGE_EP0_RESET,
	USB_DBG_IMAGE_DEVICE_RESET,
	USB_DBG_IMAGE_EP0_CANCEL,
	USB_DBG_IMAGE_EP0_GET_DEVICE_STATUS1,
	USB_DBG_IMAGE_EP0_GET_DEVICE_STATUS2,
	USB_DBG_IMAGE_SEND_RESET_MSG,
	USB_DBG_CABLE_PLUG_IN,
	USB_DBG_CABLE_PLUG_OUT,
	USB_DBG_HISR,
	USB_DBG_HISR_ERROR_REASON,
	USB_DBG_IN_HOST_MODE,
	USB_DBG_DMA_CALLBACK,
	USB_VIDEO_PROBE_DONE,
	USB_VIDEO_PROBE_COMMIT_DONE,
	USB_VIDEO_STILL_PROBE_NONE,
	USB_VIDEO_STILL_PROBE_DONE,
	USB_VIDEO_STILL_PROBE_COMMIT_DONE,
	USB_HISR_DISCON,
	USB_DBG_MAX
}USB_DBG_INFO;


/***********************************************
	implement enum and structure
************************************************/

typedef struct
{
	USB_DBG_INFO	tag;
	kal_uint32      time;
	kal_uint32      data1;
	kal_uint32      data2;
}Usb_Dbg_Data;


typedef struct
{
	Usb_Dbg_Data	dbg_data[USB_DBG_DATA_SIZE];
	kal_uint16 	dbg_data_idx;
}Usb_Dbg_Struct;


/***********************************************
	function and global variable
************************************************/
extern void USB_Dbg_Trace(USB_DBG_INFO tag, kal_uint32 time, kal_uint32 data1, kal_uint32 data2);


#endif /* USB_DEBUG_TOOL_H */

