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
 *    usbms_utils.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb mass storage class debug buffer definitions
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
 
#ifndef USBMS_UTILS_H
#define USBMS_UTILS_H

/***********************************************
	implement definition
************************************************/

//#define ENABLE_MS_UTIL_DBG

#define DBG_DATA_SIZE   1024

typedef enum 
{
      USB_DBG_USBMS_CMD_Read_1 = 1,
      USB_DBG_USBMS_CMD_Read_2,
      USB_DBG_USBMS_CMD_Write_1,
      USB_DBG_USBMS_CMD_Write_2,
      USB_DBG_USBMS_CMD_Write_3,
      USB_DBG_USBMS_RESET,
      USB_DBG_USBMS_RESET_TASK,
      USB_DBG_USBMS_CMD_READ,
      USB_DBG_USBMS_CMD_WRITE,
      USB_DBG_USBMS_CMD_PREV_MEDIA_REMOVAL,
      USB_DBG_USBMS_CMD_INQUIRY,
      USB_DBG_USBMS_CMD_FORMAT,
      USB_DBG_CHECKMEDIA_EXIST,
      USB_DBG_GENERATE_CSW,
      USB_DBG_USBMS_CMD_READ_CAPACITY,
      USB_DBG_USBMS_CMD_READ_FORMATCAPACITY,
      USB_DBG_USBMS_CMD_REQUESTSENSE,
      USB_DBG_USBMS_CMD_VERIFY,
      USB_DBG_USBMS_CMD_MODESENSE6,
      USB_DBG_USBMS_UNKNOW_CMD,
      USB_DBG_CMD,
      USB_DBG_CMD_TESTUNITREADY,
      USB_DBG_REC_CALLBACK,
      USB_DBG_TRX_CALLBACK,
      USB_DBG_BUILDrecREQ,
      USB_DBG_BUILDtrxREQ,
      USB_DBG_USBMS_CMD_Write_ERROR,
      USB_DBG_USBMS_CMD_Write_ERROR2,
      USB_DBG_USBMS_CMD_Write_ERROR3,
      USB_DBG_USBMS_CMD_Write_ERROR_Residue,
      USB_DBG_USBMS_CMD_Read_ERROR,
      USB_DBG_EINT_HISR,
      USB_DBG_TASK_TXOK,
      USB_DBG_TASK_RXOK,
      USB_DBG_RXDMA_STATE1,
      USB_DBG_RXDMA_STATE2,
      USB_DBG_MS_MAX
}USBMS_DBG_INFO;



/***********************************************
	implement enum and structure 
************************************************/

typedef struct
{
	USBMS_DBG_INFO	tag;
	kal_uint32	parameter;
}UsbMs_Dbg_Data;

typedef struct
{
	UsbMs_Dbg_Data	dbg_data[DBG_DATA_SIZE];
	kal_uint16 	dbg_data_idx;
}UsbMs_Dbg_Struct;


/***********************************************
	function and global variable
************************************************/

extern void USB_Ms_Util_Init(void);
extern void USB_Ms_Util_Release(void);
extern void USB_Ms_Dbg_Trace(USBMS_DBG_INFO tag, kal_uint32 parameter);

#endif /* USBMS_UTILS_H */

