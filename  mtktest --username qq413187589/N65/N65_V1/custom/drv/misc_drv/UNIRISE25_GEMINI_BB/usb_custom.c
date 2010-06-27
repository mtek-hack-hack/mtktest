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
 *    usb_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb customer support
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "eint.h"
#include "gpio_sw.h"
#include "usb_custom.h"

#ifdef MT6318
#include "pmic6318_sw.h"
#endif

/************************************************************
	device descriptor parameters
*************************************************************/

static const kal_uint16 USB_MANUFACTURER_STRING[] = 
{
	0x031a,
	'M',
	'e',
	'd',
	'i',
	'a',
	'T',
	'e',
	'k',
	' ',
	'I',
	'n',
	'c'
};

static const kal_uint16 USB_PRODUCT_STRING[] = 
{
	0x0310,
	'M',
	'T',
	'6',
	'2',
	'2',
	'5',
	' '
};


static const USB_DEVICE_PARAM usb_device_param = 
{
	LEVEL_HIGH,			/* cable plugin level */
	0x0e8d,				/* vendor id */	
	USB_MANUFACTURER_STRING,
	sizeof(USB_MANUFACTURER_STRING)/sizeof(kal_uint16),
	USB_PRODUCT_STRING,
	sizeof(USB_PRODUCT_STRING)/sizeof(kal_uint16)
};

 /************************************************************
	mass storage parameters
*************************************************************/

 /*USB mass storage customize*/

/* Inquire data explanation
   The length byte(Byte 4) should be always not changed, the mass storage spec define it
   Byte 8 to 15 is Vendor Information
   Byte 16 to 31 is Product Identification
   Byte 32 to 35 is Product Revision Level */   
__align(4) const kal_uint8 INQUIRE_DATA[] =
{
	0x00,
	0x80,
	0x00,
	0x01,
	0x1f, /*length*/
	0x00,
	0x00,
	0x00,
	'M',   
	'E',
	'D',
	'I',
	'A',
	'T',
	'E',
	'K',
	' ',
	'F',
	'L',
	'A',
	'S',
	'H',
	' ',
	'D',
	'I',
	'S',
	'K',
	' ',
	' ',
	' ',
	' ',
	' ',
	'6',
	'2',
	'2',
	'5'
};

static const kal_uint16  USB_MS_INTERFACE_STRING[] = 
{
	0x031c,
	'6',
	'2',
	'2',
	'5',
	'-',
	'-',
	'S',
	't',
	'o',
	'r',
	'a',
	'g',
	'e'
};


static const USB_MS_PARAM usb_ms_param = 
{
	0x0002,			/* Mass storage Product ID */
	INQUIRE_DATA,
	sizeof(INQUIRE_DATA)/sizeof(kal_uint8),
	USB_MS_INTERFACE_STRING,
	sizeof(USB_MS_INTERFACE_STRING)/sizeof(kal_uint16)
};

/************************************************************
	CDC ACM parameters
*************************************************************/

static const kal_uint16 USB_ACM_COMM_INTERFACE_STRING[] = 
{
	0x0326,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'C',
	'O',
	'M',
	'(',
	'c',   
	'o',
	'm',
	'm',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16  USB_ACM_DATA_INTERFACE_STRING[] = 
{
	0x0326,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'C',
	'O',
	'M',
	'(',
	'd',
	'a',
	't',
	'a',
	'_',
	'i',
	'f',
	')'
};

static kal_uint8 USB_RX_RING_BUFFER[2048];
static kal_uint8 USB_TX_RING_BUFFER[2048];
static kal_uint8 USB_TXISR_RING_BUFFER[3072];

static const USB_ACM_PARAM usb_acm_param =
{
	0x0003,				/* CDC ACM Product ID */
	USB_ACM_COMM_INTERFACE_STRING,
	sizeof(USB_ACM_COMM_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_ACM_DATA_INTERFACE_STRING,
	sizeof(USB_ACM_DATA_INTERFACE_STRING)/sizeof(kal_uint16),
	sizeof(USB_RX_RING_BUFFER)/sizeof(kal_uint8),		/* rx ring buffer size */
	sizeof(USB_TX_RING_BUFFER)/sizeof(kal_uint8),		/* tx ring buffer size */
	sizeof(USB_TXISR_RING_BUFFER)/sizeof(kal_uint8),	/* tx isr ring buffer size */
	USB_RX_RING_BUFFER,
	USB_TX_RING_BUFFER,
	USB_TXISR_RING_BUFFER
};


#ifdef WEBCAM_SUPPORT

/************************************************************
	VIDEO parameters
*************************************************************/

static const kal_uint16 USB_VIDEO_IAD_INTERFACE_STRING[] = 
{
	0x0328,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'I',
	'A',
	'D',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_VC_INTERFACE_STRING[] = 
{
	0x0326,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'V',
	'C',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_CT_INTERFACE_STRING[] = 
{
	0x0326,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'C',
	'T',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_OUTPUT_INTERFACE_STRING[] = 
{
	0x032e,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'o',
	'u',
	't',
	'p',
	'u',
	't',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_PU_INTERFACE_STRING[] = 
{
	0x0326,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'P',
	'U',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_VS_INTERFACE_STRING[] = 
{
	0x0326,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'V',
	'S',
	'_',
	'i',
	'f',
	')'
};

static const USB_VIDEO_PARAM usb_video_param = 
{
	0x0004,			/* video Product ID */
	USB_VIDEO_IAD_INTERFACE_STRING,
	sizeof(USB_VIDEO_IAD_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_VC_INTERFACE_STRING,
	sizeof(USB_VIDEO_VC_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_CT_INTERFACE_STRING,
	sizeof(USB_VIDEO_CT_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_OUTPUT_INTERFACE_STRING,
	sizeof(USB_VIDEO_OUTPUT_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_PU_INTERFACE_STRING,
	sizeof(USB_VIDEO_PU_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_VS_INTERFACE_STRING,
	sizeof(USB_VIDEO_VS_INTERFACE_STRING)/sizeof(kal_uint16)
};
#endif /* WEBCAM_SUPPORT */

#ifdef PICTBRIDGE_SUPPORT
/************************************************************
	IMAGE parameters
*************************************************************/
static const kal_uint16 USB_IMAGE_INTERFACE_STRING[] = 
{
	0x0318,
	'6',
	'2',
	'2',
	'5',
	' ',
	' ',
	'I',
	'M',
	'A',
	'G',
	'E'
};

/* Must have NULL termination */
static const kal_uint16 PTP_IMAGE_MANUFACTURER_STRING[] = 
{
	'M',
	'e',
	'd',
	'i',
	'a',
	'T',
	'e',
	'k',
	' ',
	'I',
	'n',
	'c',
	'.',
	'\0'
};

/* Must have NULL termination */
static const kal_uint16 PTP_IMAGE_MODEL_STRING[] = 
{
	'M',
	'T',
	'K',
	' ',
	'M',
	'T',
	'6',
	'2',
	'2',
	'5',
	'\0'
};

/* Must have NULL termination */
static const kal_uint16 PTP_IMAGE_DEVICE_VERSION_STRING[] = 
{
	'1',
	'.',
	'0',
	'0',
	'\0'
};

/* Must have NULL termination */
static const kal_uint16 PTP_IMAGE_SERIAL_NUMBER_STRING[] = 
{
	'5',
	'6',
	'7',
	'0',
	'7',
	'6',
	'6',
	'\0'
};



static const USB_IMAGE_PARAM usb_image_param =
{
	0x0005,			/* image Product ID */
	USB_IMAGE_INTERFACE_STRING,
	sizeof(USB_IMAGE_INTERFACE_STRING)/sizeof(kal_uint16),
	PTP_IMAGE_MANUFACTURER_STRING,
	sizeof(PTP_IMAGE_MANUFACTURER_STRING)/sizeof(kal_uint16),
	PTP_IMAGE_MODEL_STRING,
	sizeof(PTP_IMAGE_MODEL_STRING)/sizeof(kal_uint16),	
	PTP_IMAGE_DEVICE_VERSION_STRING,
	sizeof(PTP_IMAGE_DEVICE_VERSION_STRING)/sizeof(kal_uint16),
	PTP_IMAGE_SERIAL_NUMBER_STRING,
	sizeof(PTP_IMAGE_SERIAL_NUMBER_STRING)/sizeof(kal_uint16)
};

#endif /* PICTBRIDGE_SUPPORT */

/************************************************************
	customization functinos
*************************************************************/
#ifdef __CUST_NEW__
#if (defined(__USB_ENABLE__) && !defined(MT6318))
extern const char gpio_usb_enable_pin;
#endif
#endif /* __CUST_NEW__ */

/* get general USB device parameter function*/
const USB_DEVICE_PARAM *USB_GetDeviceParam(void)
{
	return (&usb_device_param);
}

/* get mass storage USB device parameter function*/
const USB_MS_PARAM *USB_GetMsParam(void)
{
	return (&usb_ms_param);
}

/* get CDC ACM USB device parameter function*/
const USB_ACM_PARAM *USB_GetAcmParam(void)
{
	return (&usb_acm_param);
}

#ifdef WEBCAM_SUPPORT
/* get VIDEO USB device parameter function*/
const USB_VIDEO_PARAM *USB_GetVideoParam(void)
{
	return (&usb_video_param);
}
#endif /* WEBCAM_SUPPORT */

#ifdef PICTBRIDGE_SUPPORT
/* get IMAGE USB device parameter function*/
const USB_IMAGE_PARAM *USB_GetImageParam(void)
{
	return (&usb_image_param);
}
#endif /* PICTBRIDGE_SUPPORT */


/* get USB custom parameter function*/
static const USB_CUSTOM_FUNC USB_CustomFunc = 
{
	USB_GetDeviceParam,
	USB_GetMsParam,
	USB_GetAcmParam,
#ifdef WEBCAM_SUPPORT	
	USB_GetVideoParam,
#endif
#ifdef PICTBRIDGE_SUPPORT
	USB_GetImageParam
#endif
};

const USB_CUSTOM_FUNC* USB_GetCustomFunc(void)
{
	return(&USB_CustomFunc);
}

/* power control function, enable == KAL_TRUE turn on the power*/
void USB_PowerControl(kal_bool enable)
{
#ifdef __USB_ENABLE__
	#ifdef MT6318
		pmic_usb_regulator_enable(enable);
	#else
		#ifdef __CUST_NEW__
		if (enable == KAL_TRUE)
			GPIO_WriteIO(1,gpio_usb_enable_pin);
		else
			GPIO_WriteIO(0,gpio_usb_enable_pin);
        	#else /* __CUST_NEW__ */
		if (enable == KAL_TRUE)
			GPIO_WriteIO(1,1);
		else
			GPIO_WriteIO(0,1);
        	#endif /* __CUST_NEW__ */
	#endif	/* MT6318 */			
#endif   /*__USB_ENABLE__*/
}


