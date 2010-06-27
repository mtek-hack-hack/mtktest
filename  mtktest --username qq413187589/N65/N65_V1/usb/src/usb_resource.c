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
 *    usb_resource.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb resource management
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
 
#include "drv_comm.h"
#include "app_buff_alloc.h"
#include "gpt_sw.h"
#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usb_resource.h"
#include "usb_custom.h"

static const kal_uint16 USB_Language_String[] = 
{
   0x0304,
   0x0409
};

/* interface specific create and init functions */
static Usb_IfCreate_Info usb_ifcreate_tbl[USB_MAX_INTERFACE];
static kal_uint8 usb_ifcreate_number = 0;
/* device code */
static Usb_Device_Code usb_device_code;

/* static functions */
static void USB_Resource_Reset(void);


/* register class specific create functions,  class specific create function should create interface descriptor*/
void USB_Register_CreateFunc(kal_char* if_name, usb_create_if_func_ptr if_create_func, VOID_FUNC if_init_func, usb_speed_if_func_ptr if_speed_func)
{
	if((usb_ifcreate_number >= USB_MAX_INTERFACE)||(if_create_func == NULL)||(if_init_func == NULL)||(if_speed_func == NULL))
		EXT_ASSERT(0, usb_ifcreate_number, (kal_uint32)if_create_func, (kal_uint32)if_init_func);

	usb_ifcreate_tbl[usb_ifcreate_number].if_name_ptr = if_name;
	usb_ifcreate_tbl[usb_ifcreate_number].if_create_func = if_create_func;
	usb_ifcreate_tbl[usb_ifcreate_number].if_init_func = if_init_func;
#ifdef USB_20_ENABLE
	usb_ifcreate_tbl[usb_ifcreate_number].if_speed_func = if_speed_func;
#endif
	usb_ifcreate_number++;	
}


/* register class specific device and product code*/
void USB_Register_Device_Code(kal_uint8 device_code, kal_uint8 subclass_code, 
									kal_uint8 protocol_code, kal_uint16 product_code)
{
	ASSERT(usb_device_code.b_registerd == KAL_FALSE);
	usb_device_code.device_code = device_code;
	usb_device_code.subclass_code = subclass_code;
	usb_device_code.protocol_code = protocol_code;
	usb_device_code.product_code= product_code;
	usb_device_code.b_registerd= KAL_TRUE;
}


/* deregister class specific create functions, should be called when cable plug out */
void USB_DeRegister_CreateFunc(void)
{
	usb_ifcreate_number = 0;
}


/* deregister class specific device and product code, should be called when cable plug out */
void USB_DeRegister_Device_Code(void)
{
	usb_device_code.b_registerd = KAL_FALSE;	
}


/* get interrupt endpoint number and endpoint info pointer */
Usb_Ep_Info* USB_Get_Intr_Ep(kal_uint8 *p_num)
{
	/* interrupt must EP 3 or 4 */
	gUsbDevice.resource_ep_intr_tx_number++;

	if(gUsbDevice.resource_ep_intr_tx_number > USB_MAX_EP_INTR_TX)
	{
		EXT_ASSERT(0, gUsbDevice.resource_ep_intr_tx_number, USB_MAX_EP_INTR_TX, 0);
	}
#if defined(DRV_USB_IP_V3)
	*p_num = 4;
#else
	*p_num = 3;
#endif
	return (&gUsbDevice.ep_intr_tx_info[0]);
}


/* get bulk TX endpoint number and endpoint info pointer */
Usb_Ep_Info* USB_Get_Bulk_Tx_Ep(kal_uint8 *p_num)
{
#ifdef __ENDPOINT_TEST__
	gUsbDevice.resource_ep_bulk_tx_number = 2;
	*p_num = gUsbDevice.resource_ep_bulk_tx_number;
	return (&gUsbDevice.ep_bulk_tx_info[gUsbDevice.resource_ep_bulk_tx_number - 1]);
#else
	gUsbDevice.resource_ep_bulk_tx_number++;
	if(gUsbDevice.resource_ep_bulk_tx_number > USB_MAX_EP_BULK_TX)
	{
		EXT_ASSERT(0, gUsbDevice.resource_ep_bulk_tx_number, USB_MAX_EP_BULK_TX, 0);
	}
	*p_num = gUsbDevice.resource_ep_bulk_tx_number;
	return (&gUsbDevice.ep_bulk_tx_info[gUsbDevice.resource_ep_bulk_tx_number - 1]);
#endif
}


/* get bulk out endpoint number and endpoint info pointer */
Usb_Ep_Info* USB_Get_Bulk_Rx_Ep(kal_uint8 *p_num)
{
#ifdef __ENDPOINT_TEST__
	gUsbDevice.resource_ep_bulk_rx_number = 2;
	*p_num = gUsbDevice.resource_ep_bulk_rx_number;
	return (&gUsbDevice.ep_bulk_rx_info[gUsbDevice.resource_ep_bulk_rx_number - 1]);
#else
	gUsbDevice.resource_ep_bulk_rx_number++;
	if(gUsbDevice.resource_ep_bulk_rx_number > USB_MAX_EP_BULK_RX)
	{
		EXT_ASSERT(0, gUsbDevice.resource_ep_bulk_rx_number, USB_MAX_EP_BULK_RX, 0);
	}
	*p_num = gUsbDevice.resource_ep_bulk_rx_number;
	return (&gUsbDevice.ep_bulk_rx_info[gUsbDevice.resource_ep_bulk_rx_number - 1]);
#endif
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
#endif

/* get interface number and interface info pointer */
Usb_Interface_Info* USB_Get_Interface_Number(kal_uint8 *p_num)
{
	gUsbDevice.resource_interface_number++;
	if(gUsbDevice.resource_interface_number > USB_MAX_INTERFACE)
	{
		EXT_ASSERT(0, gUsbDevice.resource_interface_number, USB_MAX_INTERFACE, 0);
	}
	*p_num = gUsbDevice.resource_interface_number - 1;
	return (&gUsbDevice.if_info[gUsbDevice.resource_interface_number - 1]);
}

/* get string number and point device recource_string to real string pointer */
kal_uint8 USB_Get_String_Number(void *usb_string)
{
	Usb_String_Dscr *string = (Usb_String_Dscr *)usb_string;
	gUsbDevice.resource_string_number++;

	if(gUsbDevice.resource_string_number > USB_MAX_STRING)
	{
		EXT_ASSERT(0, gUsbDevice.resource_string_number, USB_MAX_STRING, 0);
	}
	gUsbDevice.resource_string[gUsbDevice.resource_string_number - 1] = string;
	return (gUsbDevice.resource_string_number - 1);
}

Usb_IAD_Dscr* USB_Get_IAD_Number(kal_uint8 *p_num)
{
	gUsbDevice.resource_iad_number++;
	if(gUsbDevice.resource_iad_number > USB_MAX_IAD)
	{
		EXT_ASSERT(0, gUsbDevice.resource_iad_number, USB_MAX_IAD, 0);
	}
	*p_num = gUsbDevice.resource_iad_number - 1;
	return (&gUsbDevice.iad_desc[gUsbDevice.resource_iad_number - 1]);
}

/* create all descriptors, including device and class specific */
void USB_Software_Create(void)
{
	kal_uint32  index_if;
	kal_uint32  index_ep;
	kal_uint32  if_len = 0;
#ifdef __USB_MULTI_CHARGE_CURRENT__
	#if (defined(MT6305)||defined(MT6318)||defined(MT6238PMU))
	kal_uint32  conf_no;
	#endif
#endif
#if 0
/* under construction !*/
#endif


	/* initial resource number */
	USB_Resource_Reset();

#ifdef __USB_MULTI_CHARGE_CURRENT__
	#if (defined(MT6305)||defined(MT6318)||defined(MT6238PMU))
	for (conf_no = 0; conf_no < USB_DEVDSC_CONFIGS; conf_no++)
	{
//		gUsbDevice.multi_configuration_value[conf_no] = conf_no+1;
		gUsbDevice.multi_Max_Power[conf_no] = (kal_uint8) (USB_CHARGE_CURRENT[conf_no]/2);
		if  ( conf_no > 0)
		{
			ASSERT (gUsbDevice.multi_Max_Power[conf_no-1] > gUsbDevice.multi_Max_Power[conf_no] );
		}
	} 

	if (gUsbDevice.multi_Max_Power[0] > USB_CFGDSC_MAXPOWER)
	{
			EXT_ASSERT(0,gUsbDevice.multi_Max_Power[0],USB_CFGDSC_MAXPOWER,0);
	}
	/* The last item must be 0 */
	ASSERT (gUsbDevice.multi_Max_Power[USB_DEVDSC_CONFIGS-1] == 0); 
	#endif
#endif
	
	/* string descriptor */
	USB_Get_String_Number((void *)USB_Language_String);   /*  index 0 */

	/* check class has registered create function and device code */
	if((usb_ifcreate_number == 0) || (usb_device_code.b_registerd == KAL_FALSE))
		EXT_ASSERT(0, usb_ifcreate_number, usb_device_code.b_registerd, 0);

	/* call the create function for each class */
	for(index_if=0; index_if<usb_ifcreate_number; index_if++)
	{
		if(usb_ifcreate_tbl[index_if].if_create_func == NULL)
			EXT_ASSERT(0, 0, 0, 0);
		usb_ifcreate_tbl[index_if].if_create_func(usb_ifcreate_tbl[index_if].if_name_ptr);

		if(gUsbDevice.if_info[index_if].ifdscr_size == 0)
			EXT_ASSERT(0, 0, 0, 0);
	}

	/* Initialise the Standard Device Descriptor */
	gUsbDevice.devdscr.bLength = USB_DEVDSC_LENGTH;
	gUsbDevice.devdscr.bDescriptorType = USB_DEVICE;
#ifdef USB_20_ENABLE
	gUsbDevice.devdscr.bcdUSB = 0x0200; /* USB spec rev is 2.0 */
#else
	gUsbDevice.devdscr.bcdUSB = 0x0110; /* USB spec rev is 1.1 */
#endif
	gUsbDevice.devdscr.bDeviceClass = usb_device_code.device_code;
	gUsbDevice.devdscr.bDeviceSubClass = usb_device_code.subclass_code; 
	gUsbDevice.devdscr.bDeviceProtocol = usb_device_code.protocol_code;
	gUsbDevice.devdscr.bMaxPacketSize0 = USB_EP0_MAXP; /* USB_EP0_MAXP == 8 or 64*/
	gUsbDevice.devdscr.idVendor = gUsbDevice.device_param->desc_vendor;
	gUsbDevice.devdscr.idProduct = usb_device_code.product_code;
	gUsbDevice.devdscr.bcdDevice = USB_DEVDSC_BCDDEVICE;
	gUsbDevice.devdscr.iManufacturer = USB_Get_String_Number((void *)gUsbDevice.device_param->manufacture_string);  
	gUsbDevice.devdscr.iProduct = USB_Get_String_Number((void *)gUsbDevice.device_param->product_string);       
	/* serial string is got during initialization procedure */
	gUsbDevice.devdscr.iSerialNumber = USB_Get_String_Number((void *)gUsbDevice.serial_string);  

	if(gUsbDevice.device_type != USB_IMAGE)
	{
		gUsbDevice.devdscr.bNumConfigurations = USB_DEVDSC_CONFIGS;
	}
	else
	{
		gUsbDevice.devdscr.bNumConfigurations = 1;
	}

#ifdef __USB_MULTI_CHARGE_CURRENT__ 
	#if (defined(MT6305)||defined(MT6318)||defined(MT6238PMU))
		ASSERT(USB_DEVDSC_CONFIGS <= USB_MAX_CONFIG);
	#endif
#endif

 
	/* Initialise the descriptors for main configuration 1 */
//	gUsbDevice.cfg_info.cfg_name_ptr = "USB Main Config";
	gUsbDevice.cfgdscr.bLength = USB_CFGDSC_LENGTH;
	gUsbDevice.cfgdscr.bDescriptorType = USB_CONFIG;
	gUsbDevice.cfgdscr.bNumInterfaces = gUsbDevice.resource_interface_number;
	gUsbDevice.cfgdscr.bConfigurationValue = 0+1;   /*0+1=1, the value = (cfg index+1), select this config's number*/
	gUsbDevice.cfgdscr.iConfiguration = 0;
	gUsbDevice.cfgdscr.bmAttributes = USB_CFGDSC_ATTR_NATURE;

//	if(gUsbDevice.remoteWk == KAL_TRUE)
//		gUsbDevice.cfgdscr.bmAttributes |= USB_CFGDSC_ATTR_REMOTEWAKEUP;

//	if(gUsbDevice.self_powered == KAL_TRUE)
//		gUsbDevice.cfgdscr.bmAttributes |= USB_CFGDSC_ATTR_SELFPOWER;

#ifdef  __USB_MULTI_CHARGE_CURRENT__
	#if ( defined(MT6305) || defined(MT6318) )
	gUsbDevice.cfgdscr.bMaxPower = gUsbDevice.multi_Max_Power[0];
	#else
	gUsbDevice.cfgdscr.bMaxPower = (kal_uint8) (66/2);
	#endif
#else
	gUsbDevice.cfgdscr.bMaxPower = USB_CFGDSC_MAXPOWER;
#endif

#ifdef __OTG_ENABLE__
	if(INT_USBBoot() == KAL_FALSE)
	{
		gUsbDevice.otgdscr.bLength = USB_OTGDSC_LENGTH;
		gUsbDevice.otgdscr.bDescriptorType = USB_OTG_DESC;
		gUsbDevice.otgdscr.bAttribute = (USB_OTG_HNP_SUPPORT | USB_OTG_SRP_SUPPORT);
	}	
#endif	

	/* configuration length */
	for(index_if = 0; index_if < gUsbDevice.resource_iad_number; index_if++)
	{
		if_len = gUsbDevice.iad_desc[index_if].bLength;
	}
	
	for(index_if = 0; index_if < gUsbDevice.resource_interface_number; index_if++)
	{
		if_len += gUsbDevice.if_info[index_if].ifdscr_size;

		for(index_ep = 0; index_ep<gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
		{
			if_len += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
		}

#if  0
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

#ifdef __OTG_ENABLE__
	if(INT_USBBoot() == KAL_FALSE)
		gUsbDevice.cfgdscr.wTotalLength = (USB_CFGDSC_LENGTH + if_len + USB_OTGDSC_LENGTH);
	else
		gUsbDevice.cfgdscr.wTotalLength = (USB_CFGDSC_LENGTH + if_len);
#else	
        gUsbDevice.cfgdscr.wTotalLength = (USB_CFGDSC_LENGTH + if_len);
#endif	
	/* allocate configuration descriptor memory */
	ASSERT(gUsbDevice.conf == NULL);
	gUsbDevice.conf = (kal_uint8 *)get_ctrl_buffer(gUsbDevice.cfgdscr.wTotalLength);

#ifdef USB_20_ENABLE
	/* Initialise the Standard Device_Qualiifier Descriptor */
	gUsbDevice.dev_qual_dscr.bLength = USB_DEV_QUA_DSC_LENGTH;
	gUsbDevice.dev_qual_dscr.bDescriptorType = USB_DEVICE_QUALIFIER;
	gUsbDevice.dev_qual_dscr.bcdUSB = 0x0200; /* USB spec rev is 2.0 */
   	gUsbDevice.dev_qual_dscr.bDeviceClass = usb_device_code.device_code;
	gUsbDevice.dev_qual_dscr.bDeviceSubClass = usb_device_code.subclass_code; 
	gUsbDevice.dev_qual_dscr.bDeviceProtocol = usb_device_code.protocol_code;
	gUsbDevice.dev_qual_dscr.bMaxPacketSize0 = USB_EP0_MAXP; /* USB_EP0_MAXP == 64*/
	gUsbDevice.dev_qual_dscr.bNumConfigurations = gUsbDevice.devdscr.bNumConfigurations;
	gUsbDevice.dev_qual_dscr.bReserved = 0x00;

	/* Initialise the descriptors for other speed configuration */
	gUsbDevice.other_speed_cfg_dscr.bLength = USB_OTHER_CFGDSC_LENGTH;
	gUsbDevice.other_speed_cfg_dscr.bDescriptorType = USB_OTHER_SPEED;
	gUsbDevice.other_speed_cfg_dscr.wTotalLength = gUsbDevice.cfgdscr.wTotalLength;
	gUsbDevice.other_speed_cfg_dscr.bNumInterfaces = gUsbDevice.cfgdscr.bNumInterfaces;
	gUsbDevice.other_speed_cfg_dscr.bConfigurationValue = 0+1;   /*0+1=1, the value = (cfg index+1), select this config's number*/
	gUsbDevice.other_speed_cfg_dscr.iConfiguration = 0;
	gUsbDevice.other_speed_cfg_dscr.bmAttributes = gUsbDevice.cfgdscr.bmAttributes;
	gUsbDevice.other_speed_cfg_dscr.MaxPower = gUsbDevice.cfgdscr.bMaxPower;
#else
	USB_Software_Speed_Init(KAL_FALSE);
#endif
}


void USB_Software_Speed_Init(kal_bool b_other_speed)
{
	kal_uint32  index_if;
	kal_uint32  index_ep;
	kal_uint32  Conf_index;
#ifdef USB_20_ENABLE
	kal_uint32  index;
#endif
#if 0
/* under construction !*/
#endif


	/* check class has registered init function */
	ASSERT(usb_ifcreate_number != 0);

#ifdef USB_20_ENABLE
	/* decide EP is high speed or full speed descriptors */
	for(index = 0; index < usb_ifcreate_number; index++)
	{
		if(usb_ifcreate_tbl[index].if_speed_func != NULL)
			usb_ifcreate_tbl[index].if_speed_func(b_other_speed);
		else
			ASSERT(0);
	}
#endif

	ASSERT(gUsbDevice.conf != NULL);

	/* re-construct configuration descriptor */
	/* kal_mem_cpy(dst,src,len) */
#ifdef USB_20_ENABLE
	if(b_other_speed == KAL_FALSE)
	{
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.cfgdscr, USB_CFGDSC_LENGTH);
		Conf_index = USB_CFGDSC_LENGTH;
	}
	else
	{
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.other_speed_cfg_dscr, USB_OTHER_CFGDSC_LENGTH);
		Conf_index = USB_OTHER_CFGDSC_LENGTH;
	}
#else
	kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.cfgdscr, USB_CFGDSC_LENGTH);
	Conf_index = USB_CFGDSC_LENGTH;
#endif

	for(index_if = 0; index_if < gUsbDevice.resource_iad_number; index_if++)
	{
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.iad_desc[index_if], gUsbDevice.iad_desc[index_if].bLength);
		Conf_index += gUsbDevice.iad_desc[index_if].bLength;
	}

	for(index_if = 0; index_if < gUsbDevice.resource_interface_number; index_if++)
	{
		if((gUsbDevice.device_type == USB_VIDEO)&&(index_if == 1))
		{
			/* Modify in order to pass USB UVC compliance test tool */
			kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), 
				(kal_uint8*)&gUsbDevice.if_info[index_if].ifdscr.stdif, USB_IFDSC_LENGTH);
			Conf_index += USB_IFDSC_LENGTH;

			for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
			{
				kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
					(kal_uint8 *)&(gUsbDevice.if_info[index_if].ep_info[index_ep]->epdesc.stdep),
						gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size);
				Conf_index += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
			}

			kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), 
				(kal_uint8 *)(((kal_uint32)&gUsbDevice.if_info[index_if].ifdscr.stdif)+USB_IFDSC_LENGTH), 
				gUsbDevice.if_info[index_if].ifdscr_size-USB_IFDSC_LENGTH);

			Conf_index += gUsbDevice.if_info[index_if].ifdscr_size-USB_IFDSC_LENGTH;

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
#endif

		}
		else
		{
			kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.if_info[index_if].ifdscr.stdif, 
				gUsbDevice.if_info[index_if].ifdscr_size);
			Conf_index += gUsbDevice.if_info[index_if].ifdscr_size;

			for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
			{
				kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8 *)&(gUsbDevice.if_info[index_if].ep_info[index_ep]->epdesc.stdep),
					gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size);
				Conf_index += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
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
#endif
		}		
	}

#ifdef __OTG_ENABLE__	
	if(INT_USBBoot() == KAL_FALSE)
	{
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.otgdscr, USB_OTGDSC_LENGTH);
		Conf_index+=USB_OTGDSC_LENGTH;
	}	
#endif
	ASSERT(Conf_index == gUsbDevice.cfgdscr.wTotalLength);
}


/* init EP of each interface (class specific) */
void USB_Software_Init(void)
{
	kal_uint32 index;
	
	for(index=0;index<usb_ifcreate_number;index++)
	{
		if(usb_ifcreate_tbl[index].if_init_func != NULL)
		usb_ifcreate_tbl[index].if_init_func();
		else
			ASSERT(0);
	}
}


/* Reset the resource maintain in this file */
static void USB_Resource_Reset(void)
{
#if 0
/* under construction !*/
#endif

	gUsbDevice.resource_ep_bulk_tx_number = 0;
   	gUsbDevice.resource_ep_bulk_rx_number = 0;
   	gUsbDevice.resource_ep_intr_tx_number = 0;
   	gUsbDevice.resource_interface_number = 0;

#if 0
/* under construction !*/
/* under construction !*/
#endif
   	gUsbDevice.resource_string_number = 0; 		
   	gUsbDevice.resource_iad_number = 0;
}

