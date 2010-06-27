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
 *    usbd.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for usb1.1 host definitions.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USBD_H
#define USBD_H

#include "usb_hcd.h"


#define USBD_MAX_CFG_NUM			8
#define USBD_MAX_IF_PER_CFG			5
#define USBD_MAX_INTERFACE_NUM			(USBD_MAX_CFG_NUM * USBD_MAX_IF_PER_CFG)
#define USBD_MAX_EP_PER_IF			5 
#define USBD_MAX_EP_NUM				(USBD_MAX_INTERFACE_NUM * USBD_MAX_EP_PER_IF)
#define USBD_MAX_CLASS_DRIVER		2

#define USBD_EP0_MAX_PKT_SIZE		64

#define USBD_ERROR_DELAY			100  /* 10ms unit*/

typedef enum
{
	USBD_CH9_START,
	USBD_CH9_SET_ADDR,
	USBD_CH9_GET_DEV_DESC_8,
	USBD_CH9_GET_DEV_DESC,
	USBD_CH9_GET_CONF_DESC_9,
	USBD_CH9_GET_CONF_DESC,
	USBD_CH9_SET_CONF,
	//USBD_CH9_SET_INTF,
	USBD_CH9_SET_HNP_ENABLE,
	USBD_CH9_ENUM_OK
}USBD_CH9_STATE;

typedef enum
{
	USBD_EP0_SETUP,
	USBD_EP0_DATA,
	USBD_EP0_STATUS,
	USBD_EP0_NONE
}USBD_EP0_STATE;

typedef enum
{
	USBD_EP0_DATA_RECV,
	USBD_EP0_DATA_SEND,
	USBD_EP0_DATA_NULL	/* no data phase is needed */
}USBD_EP0_DATA_DIR;


/* EP0 status */
typedef struct 
{
	kal_uint8				device_addr;		/* new function address */
	kal_uint8				max_packet_size;	
	Usb_Command				setup_cmd;			/* setup packet address */
	kal_uint8				*data_ptr;			/* data packet address */
	USBD_EP0_DATA_DIR		ep0_data_dir;		/* data phase direction */
	kal_uint32				sofar;				/* number of bytes sent/recv'd so far */
   	kal_uint32				todo;				/* number of bytes to send/recv */								
} USBD_EP0_Status;

/* Bulk IN endpoint status */
typedef struct 
{
	kal_uint8				max_packet_size;	
	kal_uint8				*data_ptr;			/* data packet address */
	kal_uint32				sofar;				/* number of bytes sent/recv'd so far */
   	kal_uint32				todo;				/* number of bytes to send/recv */		
} USBD_EPIN_Status;

/* Bulk OUT endpoint status */
typedef struct 
{
	kal_uint8				max_packet_size;	
	kal_uint8				*data_ptr;			/* data packet address */
	kal_uint32				sofar;				/* number of bytes sent/recv'd so far */
   	kal_uint32				todo;				/* number of bytes to send/recv */		
} USBD_EPOUT_Status;

/* endpoint information, including endpoint status */
typedef struct 
{
	Usb_Ep_Dscr				*p_stdep;			/* ep descriptor */
	union 
	{
		USBD_EPIN_Status	epin_status;
		USBD_EPOUT_Status	epout_status;
	}ep_status;			
} USBD_EP_Info;

typedef struct
{
	Usb_If_Dscr				*p_interface_desc;
	USBD_EP_Info			*p_ep_info[USBD_MAX_EP_PER_IF];
	kal_uint8				ep_number;
}USBD_IF_Info;

typedef struct
{
	Usb_Cfg_Dscr			*p_cfg_desc;
	USBD_IF_Info			*p_interface_info[USBD_MAX_IF_PER_CFG];
	kal_uint8			interface_number;
}USBD_CFG_Info;

typedef struct
{
	Usb_Dev_Dscr			dev_desc;
	Usb_Otg_Dscr			*p_otg_desc[USBD_MAX_CFG_NUM];
	kal_uint8			*p_conf_data[USBD_MAX_CFG_NUM];
	//Usb_Cfg_Dscr			*p_cfg_desc[USBD_MAX_CFG_NUM];
	kal_uint8			cfg_number;
	USBD_CFG_Info			cfg_info[USBD_MAX_CFG_NUM];
	USBD_IF_Info			interface_info[USBD_MAX_INTERFACE_NUM];
	USBD_EP_Info			ep_info[USBD_MAX_EP_NUM];
}USBD_Desc_Info;

typedef struct
{
	kal_bool (* match)(USBD_Desc_Info *p_desc_info, kal_uint8 *p_cfg_num);
	void (* startup)(kal_uint8 cfg_num);
	void (* detach)();
}USBD_ClassDriver_Struct;

typedef void (*usbd_ep0_callback)(USB_HCD_STATUS result, kal_uint32 param);

typedef struct 
{
	USBD_Desc_Info			desc_info;
	USBD_EP0_STATE			ep0_state;	//states machine
	USBD_EP0_Status			ep0_status;	
	USBD_CH9_STATE			ch9_state;
	kal_uint8				ch9_error_count;
	kal_bool				support_hnp;
	kal_int8				current_class_driver;	
	kal_uint8				total_class_driver;
	USBD_ClassDriver_Struct	*class_driver_ptr[USBD_MAX_CLASS_DRIVER];
	usbd_ep0_callback		ep0_callback;
} USBD_Struct;

extern USBD_Struct	gUsbHost;

extern void USBD_Init_Status(void);
extern void USBD_Release_Status(void);
extern void USBD_Register_Class_Driver(USBD_ClassDriver_Struct *class_driver_ptr);
extern void USBD_Derigister_Class_Driver(void);
extern void USBD_Register_EP0_Callback(usbd_ep0_callback callback);

extern void USBD_Init(void);
extern void USBD_Release(void);
extern void USBD_Detach(USB_HCD_STATUS result, kal_uint32 param);

extern void USBD_Set_Feature(kal_uint16 feature_value);
extern void USBD_Clear_Stall(kal_uint8 ep_num, USB_EP_TYPE ep_type);

extern kal_bool USBD_Get_HNP_Support(void);
	

#endif /* USBD_H*/

