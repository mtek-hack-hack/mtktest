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
 *    usb_host_ms_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for host mass storage class driver definitions
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
 
#ifndef USB_HOST_MS_DRV_H
#define USB_HOST_MS_DRV_H

#include "usbms_drv.h"

/************************************************************
	MS class parameter definition
*************************************************************/

/* string size in INQUERY data format */
#define USBMS_INQUIRY_VENDOR_INFO_LEN		8
#define USBMS_INQUIRY_PRODUCT_IDEN_LEN		16
#define USBMS_INQUIRY_PRODUCT_REV_LEN		4

/* command and adta length for each ms command */
#define USBMS_INQUIRY_CMD_LEN				6
#define USBMS_INQUIRY_DATA_LEN				36
#define USBMS_READ_FORMATCAPACITY_CMD_LEN	10
#define USBMS_READ_FORMATCAPACITY_DATA_LEN	60
#define USBMS_READ_CAPACITY_CMD_LEN			10
#define USBMS_READ_CAPACITY_DATA_LEN		8
#define USBMS_MODE_SENSE6_CMD_LEN			6
#define USBMS_MODE_SENSE6_DATA_LEN			12
#define USBMS_MODE_SENSE_CMD_LEN			10
#define USBMS_MODE_SENSE_DATA_LEN			12
#define USBMS_REQUESTSENSE_CMD_LEN			12
#define USBMS_REQUESTSENSE_DATA_LEN			18
#define USBMS_TEST_UNIT_READY_CMD_LEN		6
#define USBMS_TEST_UNIT_READY_DATA_LEN		0
#define USBMS_READ_CMD_LEN					10
#define USBMS_WRITE_CMD_LEN					10

#define USBMS_CBW_LENGTH					31
#define USBMS_CSW_LENGTH					13


/************************************************************
	Implementation definition
*************************************************************/
/* State machine polling periord*/
#define USB_HOST_MS_QUERY_PERIOD			10  /* 10ms unit */
/* Maxumum buffer size for CBW command and DATA except READ and WRITE command */
#define USBMS_MAX_CMD_LEN					32
#define USBMS_MAX_DATA_LEN					64	

/* Event flag. (CBW, DATA, CSW) is handled in HISR level
    This event is used when state complete to retrive waiting task*/
#define EVENT_USB_MS_DONE					((kal_uint32)0x00000001)
#define EVENT_USB_MS_DETATCH				((kal_uint32)0x00000002)

/* This is constraint by both secotr size and device DMA length */
/* DMA length can not exceed 0xffff=>65535 */
#define USBMS_MAX_DATA_LENGTH				32*1024

/* Bulk endpoint state*/
typedef enum
{
	USB_HOST_MS_NONE,
	USB_HOST_MS_CBW,
	USB_HOST_MS_DATA,
	USB_HOST_MS_CSW,
	USB_HOST_MS_CBW_CLEAR_STALL,
	USB_HOST_MS_DATA_CLEAR_STALL,
	USB_HOST_MS_CSW_CLEAR_STALL
}USB_HOST_MS_STATE;

/* DATA stage direction */
typedef enum
{
	USB_HOST_MS_DATA_NONE, /* no data phase is needed */
	USB_HOST_MS_DATA_RECV,
	USB_HOST_MS_DATA_SEND	
}USB_HOST_MS_DATA_DIR;

/* Result of the CBW, DATA, CSW state */
typedef enum
{
	USB_HOST_MS_RESULT_OK,
	USB_HOST_MS_RESULT_CSW_FAIL,
	USB_HOST_MS_RESULT_TIMEOUT,
	USB_HOST_MS_RESULT_STALL,
	USB_HOST_MS_RESULT_FORMAT_ERROR
}USB_HOST_MS_RESULT;

/* Ctrl EP commands that may used after MS class driver is started 
    Note that it contains both standard and class specific request */
typedef enum
{
	USB_HOST_MS_EP0_CMD_NONE,
	USB_HOST_MS_EP0_CMD_RESET,
	USB_HOST_MS_EP0_CMD_GET_LUN,
	USB_HOST_MS_EP0_CMD_CLEAR_STALL_IN,
	USB_HOST_MS_EP0_CMD_CLEAR_STALL_OUT
}USB_HOST_MS_EP0_CMD;


/* The MS device status */
typedef enum
{
	USB_HOST_MS_DEV_STATE_READY,	
	USB_HOST_MS_DEV_STATE_ERROR
}USB_HOST_MS_DEV_STATE;

/* The media state for each LUN */
typedef enum
{
	USB_HOST_MS_MEDIA_STATE_ABSENT,	
	USB_HOST_MS_MEDIA_STATE_READY,
	USB_HOST_MS_MEDIA_STATE_WR_PROTECT,
	USB_HOST_MS_MEDIA_STATE_CHANGED,
	USB_HOST_MS_MEDIA_STATE_ERROR
}USB_HOST_MS_MEDIA_STATE;

typedef enum
{
	USB_HOST_MS_MSG_MEDIA_CHANGE,
	USB_HOST_MS_MSG_PLUG_IN,
	USB_HOST_MS_MSG_PLUG_OUT
}USB_HOST_MS_MSG_TYPE;


/************************************************************
	Implementation structures
*************************************************************/

/* CBW and DATA related parameters */
typedef struct
{
	kal_uint8				lun;
	kal_uint32				cmd_len;
	kal_uint8				*cmd_buff;
	kal_uint32				data_len;
	kal_uint8				*data_buff;
	USB_HOST_MS_DATA_DIR	data_dir;
}USBH_Ms_Cmd_Struct;

/* Media information for each LUN */
typedef struct
{
	kal_uint32 				sec_size;
	kal_uint32 				sec_num;
	USB_HOST_MS_MEDIA_STATE state;
	USB_HOST_MS_MEDIA_STATE pre_state;

	kal_uint8				vendor_info[USBMS_INQUIRY_VENDOR_INFO_LEN];
	kal_uint8				product_iden[USBMS_INQUIRY_PRODUCT_IDEN_LEN];
	kal_uint8				product_rev[USBMS_INQUIRY_PRODUCT_REV_LEN];
}USBH_Ms_Media_Struct;

typedef struct
{
	/* device level resource */	
	kal_uint8				ep_in_num;			/* IN EP number in USB protocol */
	kal_uint8				ep_in_index;		/* IN EP index in implementation (resource number) */
	kal_uint16				ep_in_max_pkt_size;
	kal_uint8				ep_out_num;			/* OUT EP number in USB protocol */
	kal_uint8				ep_out_index;		/* OUT EP index in implementation (resource number) */
	kal_uint16				ep_out_max_pkt_size;
	kal_eventgrpid			event_id;			/* event used for (CBW, DATA, CSW) state machine to retrive waiting task */
   	kal_mutexid				mutex_id;			/* mutex used to protect ms command. 
   													When USB task is polling state machine, 
   									   				read/write action from application task should be protected */
   	kal_uint8				gpt_handle;			/* gpt handle to query device status */


	/* CBW, DATA CSW state information*/
	kal_uint32				CBWdata[32/4];		/* CBW data */
	UsbMs_CSW				CSW;				/* CSW data*/
	kal_uint8*				data;				/* DATA stage buffer address*/
	kal_uint32				data_length;		/* DATA stage size */
	USB_HOST_MS_DATA_DIR	data_dir;			/* DATA stage direction */
	/* DATA stage parameters. If data length application request is larger than DMA can support,
	    CBW, DATA, CSW state machine should divide it to multiple request */
   	kal_uint32				remain_data_length;		
   	kal_uint32				sending_data_length;
   	kal_uint32				sent_data_length;
   	USBH_Ms_Cmd_Struct  	ms_cmd_data;		/* Used to store all CBW, DATA related information */
   	USB_HOST_MS_STATE		ms_state;			/* State in the state machine of CBW, DATA, CSW */
   	USB_HOST_MS_RESULT		result;				/* CBW, DATA, CSW state result */
   	kal_bool				b_rw_result;		/* read/write result for READ and WRITE action */

	/* EP0 information*/
	USB_HOST_MS_EP0_CMD		ms_cmd;				/* Current EP0 command */

	/* media information */
   	kal_uint8				total_lun;				/* total lun number in the attached device */
	kal_uint8				support_lun;			/* supported lun defined in custom */
	USBH_Ms_Media_Struct	*media_info;			/* media information for each LUN*/
	kal_uint8				*media_handle;			/* media handle communicated with file system */
	kal_uint32				*media_msg_array;		/* message array communicated with FMT */			
	kal_uint32				media_state_change;		/* keep information about whether each lun state is changed or not */

	/* device information*/
	USB_HOST_MS_DEV_STATE	dev_state;				/* device status*/
	kal_bool				dev_attatch;
	kal_uint8				dev_error_count;		/* device error count */		
	kal_bool				b_sending_change_ilm;	/* Check it can send message to indicate FMT*/
	kal_bool				b_sending_plugout_ilm;
}USB_Host_Ms_Struct;


/************************************************************
	extern variables and functions
*************************************************************/

 extern USBD_ClassDriver_Struct USB_Host_Ms_Drv;
 extern USB_Host_Ms_Struct g_UsbHostMs;

extern void USB_Host_Ms_SendInd(USB_HOST_MS_MSG_TYPE msg);
extern void USB_Host_Ms_Get_Media_Resource(void);
extern void USB_Host_Ms_Free_Media_Resource(void);
extern void USB_Host_Ms_Dis_Device(void);
extern void USB_Host_Ms_En_Device(void);
extern void USB_Host_Ms_Get_LUN(void);
extern void USB_Host_Ms_Reset(void);
extern USB_HOST_MS_RESULT USB_Host_Ms_Request_Sense(kal_uint8 lun);
extern USB_HOST_MS_RESULT USB_Host_Ms_Inquiry(kal_uint8 lun);
extern USB_HOST_MS_RESULT USB_Host_Ms_Read_Format_Capacity(kal_uint8 lun);
extern USB_HOST_MS_RESULT USB_Host_Ms_Read_Capacity(kal_uint8 lun);
extern USB_HOST_MS_RESULT USB_Host_Ms_Test_Unit_Ready(kal_uint8 lun);
extern USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense6(kal_uint8 lun);
extern USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense6_All_Mode(kal_uint8 lun);
extern USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense10_All_Mode(kal_uint8 lun);
extern USB_HOST_MS_RESULT USB_Host_Ms_Read(kal_uint8 lun, kal_uint32 sec_start, kal_uint16 sec_num, kal_uint8* data);
extern USB_HOST_MS_RESULT USB_Host_Ms_Write(kal_uint8 lun, kal_uint32 sec_start, kal_uint16 sec_num, kal_uint8* data);

#endif	/* USB_HOST_MS_DRV_H */ 
 
