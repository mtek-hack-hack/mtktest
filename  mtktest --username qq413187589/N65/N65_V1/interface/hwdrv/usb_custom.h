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
 *    usb_custom.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for  usb customization parameter definition
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
#ifndef USB_CUSTOM_H
#define USB_CUSTOM_H

/* custom parameter for usb device*/
typedef struct
{
	const kal_uint8 	cable_plugin_level;
	const kal_uint16 	desc_vendor;
	const kal_uint16 	*manufacture_string;
	const kal_uint8 	manufacture_size;
	const kal_uint16 	*product_string;
	const kal_uint8 	product_size;
}USB_DEVICE_PARAM;

/* custom parameter for mass storage device*/
typedef struct
{
	const kal_uint16 	desc_product;
	const kal_uint8 	*inquire_data;
	const kal_uint8 	inquire_size;
	const kal_uint16 	*interface_string;
	const kal_uint8 	interface_size;
}USB_MS_PARAM;

/* custom parameter for acm device*/
typedef struct
{
	const kal_uint16 	desc_product;
	const kal_uint16 	*comm_interface_string;
	const kal_uint8 	comm_interface_size;
	const kal_uint16 	*data_interface_string;
	const kal_uint8 	data_interface_size;
	const kal_uint16 	rx_ringbuff_size;
	const kal_uint16 	tx_ringbuff_size;
	const kal_uint16 	txisr_ringbuff_size;
	const kal_uint8		*rx_ringbuff;
	const kal_uint8		*tx_ringbuff;
	const kal_uint8		*txisr_ringbuff;
}USB_ACM_PARAM;

/* custom parameter for video device*/
typedef struct
{
	const kal_uint16 	desc_product;
	const kal_uint16	*iad_function_string;
	const kal_uint8 	iad_function_size;
	const kal_uint16 	*vc_interface_string;
	const kal_uint8 	vc_interface_size;
	const kal_uint16	*vc_camera_string;
	const kal_uint8 	vc_camera_size;
	const kal_uint16	*vc_output_string;
	const kal_uint8 	vc_output_size;
	const kal_uint16	*vc_processing_unit_string;
	const kal_uint8 	vc_processing_unit_size;
	const kal_uint16 	*vs_interface_string;
	const kal_uint8 	vs_interface_size;
}USB_VIDEO_PARAM;

/* custom parameter for image device*/
typedef struct
{
	const kal_uint16 	desc_product;
	const kal_uint16 	*image_interface_string;
	const kal_uint8 	image_interface_size;
	const kal_uint16 	*image_manufacturer_string;
	const kal_uint8 	image_manufacturer_size;
	const kal_uint16 	*image_model_string;
	const kal_uint8 	image_model_size;
	const kal_uint16 	*image_device_version_string;
	const kal_uint8 	image_device_version_size;
	const kal_uint16 	*image_serial_number_string;
	const kal_uint8 	image_serial_number_size;
}USB_IMAGE_PARAM;


/* get parameter functions pointer*/
typedef const USB_DEVICE_PARAM* (*usb_get_device_param_func)(void);
typedef const USB_MS_PARAM* (*usb_get_ms_param_func)(void);
typedef const USB_ACM_PARAM* (*usb_get_acm_param_func)(void);
typedef const USB_VIDEO_PARAM* (*usb_get_video_param_func)(void);
typedef const USB_IMAGE_PARAM* (*usb_get_image_param_func)(void);


/* get parameter functions*/
typedef struct 
{
	usb_get_device_param_func	get_device_param_func;
	usb_get_ms_param_func		get_ms_param_func;
	usb_get_acm_param_func		get_acm_param_func;
#ifdef WEBCAM_SUPPORT	
	usb_get_video_param_func	get_video_param_func;
#endif	
#ifdef PICTBRIDGE_SUPPORT	
	usb_get_image_param_func	get_image_param_func;
#endif
} USB_CUSTOM_FUNC;

extern const USB_CUSTOM_FUNC* USB_GetCustomFunc(void);

/* usb power control, parameter true means power on, false means power off*/
extern void USB_PowerControl(kal_bool enable);

#ifdef __USB_AND_UART_WITH_ONE_GPIO__
/* We must call this function in USB_EINT_HISR() in the case that USB and UART with one GPIO */
extern void USB_Switch_Gpio_to_USB_And_PowerControl(kal_bool enable);
#endif

#ifdef __OTG_ENABLE__
extern kal_uint16 USBD_Get_Max_Power(void);
extern void OTG_VBusControl(kal_bool enable);
#endif

#endif

