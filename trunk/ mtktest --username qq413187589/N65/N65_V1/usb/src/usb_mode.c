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
 *    usb_mode.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb mode selection
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
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "reg_base.h"
#include "drvsignals.h"
#include "eint.h" 
#include "kal_release.h"	

#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usb_resource.h"
#include "usbms_utils.h"
#include "usbms_drv.h"
#include "usbms_state.h"
#include "usbms_adap.h"
#include "usb_msdisk.h"
#include "usbacm_drv.h"
#include "usbacm_ft.h"
#ifdef __DSPIRDBG__
#include "usbacm_dsp.h"
#include "irdbg_drv.h"
#endif
#ifdef WEBCAM_SUPPORT
#include "usbvideo_if.h"
#include "usbvideo_drv.h"
#include "usbvideo_state.h"
#endif

#ifdef PICTBRIDGE_SUPPORT
#include "usbimage_drv.h"
#include "ptp_state.h"
#endif

#ifdef __OTG_ENABLE__
#include "otg_drv.h"
#include "otg.h"
#include "usbd.h"
#include "usb_host_default_drv.h"
#include "usb_host_ms_state.h"
#include "gpio_sw.h"
#endif
#include "usb_task.h"
#include "usb_mode.h"
#include "usb_custom.h"

#include "app_buff_alloc.h"
#include "nvram.h"
#include "nvram_interface.h"
#include "nvram_user_defs.h"
#include "usb_trc.h"

#ifdef MT6318
#include "pmic6318_sw.h"
#endif

#include "fat_fs.h"
#include "rtfiles.h"

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */


#ifdef __OTG_ENABLE__
static void OTG_Host_Stop_Hdlr(void);
#ifdef OTG_NORMAL_APP_FIXED
/* for compliance test */
kal_uint32  g_USB_Mass_Buffer[32*1024/4];
#endif
#endif


Usb_Mode_Struct g_UsbMode;

/* extern functions */
extern kal_uint16 INT_BootMode(void);
extern kal_bool INT_USBBoot(void);

/* static functions */
#ifdef __USB_IN_NORMAL_MODE__
static FS_DEVICE_TYPE_ENUM USB_Ms_Dev_To_Fs_Type(USB_STORAGE_DEV_TYPE type);
static void USB_Init_Normal_Mode_Ms(kal_uint32* mem_addr, kal_bool b_enable);
static void USB_End_Normal_Mode_Ms(void);
#endif
static void USB_End_Ms(void);

/************************************************************
	mode selection  functions
*************************************************************/
void USB_Init_Mode(void)
{
#ifndef __OTG_ENABLE__
	EXT_ASSERT(0, 0, 0, 0);
#endif	

	g_UsbMode.mode_param = 0;
	g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
	g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
	g_UsbMode.b_start_srp = KAL_FALSE;
	g_UsbMode.b_start_hnp = KAL_FALSE;
	g_UsbMode.b_usb_pdnmode = KAL_TRUE;
}


void USB_Mode_Selection(void)
{
#ifdef __OTG_ENABLE__
	EXT_ASSERT(0, 0, 0, 0);
#endif

#ifndef __OTG_ENABLE__
	if(g_UsbMode.cable_type==USB_MODE_CABLE_A_PLUGIN)
		EXT_ASSERT(0, 0, 0, 0);

	if (INT_BootMode() == MTK_FACTORY_MODE)
	{
		if(((g_UsbMode.mode_param&USB_MODE_NVRAM_READ_DONE)!=0) 
			&&((g_UsbMode.mode_param&USB_MODE_FT_START_DONE)!=0))
			USB_Init_ACM_In_Meta();			
		return;	
	}
	
	/*  Normal mode */
	if ((INT_USBBoot() == KAL_FALSE) && (g_UsbMode.cable_type!=USB_MODE_CABLE_PLUGOUT)
		&&((g_UsbMode.mode_param&USB_MODE_NVRAM_READ_DONE)!=0)
		&&(gUsbDevice.usb_comport_boot == KAL_FALSE))
	{
		#ifdef OTG_NORMAL_APP_FIXED
		USB_Config_Type(USB_MASS_STORAGE, KAL_TRUE, g_USB_Mass_Buffer);
		#else
		/* Notify UEM*/
		USB_Send_Msg(USB_SEND_MSG_PLUG_IN, 0, KAL_TRUE);
		#endif
	}

	/*  MS mode */
	if ((INT_USBBoot() == KAL_TRUE) && (g_UsbMode.cable_type!=USB_MODE_CABLE_PLUGOUT) 
		&&((g_UsbMode.mode_param&USB_MODE_BMT_READ_DONE)!=0)
		&&(gUsbDevice.usb_comport_boot == KAL_FALSE))
	{
		/* init in mass storage mode */
		USB_Init_Ms(g_UsbMS.b_ms_first_plugin);/* initial as true */
		g_UsbMS.b_ms_first_plugin = KAL_FALSE;
	}	
		
	if((g_UsbMode.cable_type==USB_MODE_CABLE_PLUGOUT) && (g_UsbMode.previous_cable_type != USB_MODE_CABLE_PLUGOUT))
	{
		USB_Release_Type(KAL_TRUE, KAL_TRUE);	
	}
#endif	
}

void OTG_Mode_Selection(void)
{	
#ifndef __OTG_ENABLE__
	EXT_ASSERT(0, 0, 0, 0);
#endif	

#ifdef __OTG_ENABLE__
	if (INT_BootMode() == MTK_FACTORY_MODE)
	{
		if(((g_UsbMode.mode_param&USB_MODE_NVRAM_READ_DONE)!=0) 
			&&((g_UsbMode.mode_param&USB_MODE_FT_START_DONE)!=0))
		{
			/* enable USB power */
			if(g_UsbMode.b_usb_pdnmode==KAL_TRUE)
			{
				g_UsbMode.b_usb_pdnmode = KAL_FALSE;
				USB_PDNmode(KAL_FALSE);
				OTG_Init(OTG_Host_Stop_Hdlr);
			}	 

			if(OTG_Get_Plug_Type()==OTG_PLUG_B)
			{
				OTG_B_Set_Session_Valid(KAL_TRUE);	
			}	
		}			
		return;	
	}
	
	if ((INT_USBBoot() == KAL_FALSE) && (g_UsbMode.cable_type!=USB_MODE_CABLE_PLUGOUT)
		&&((g_UsbMode.mode_param&USB_MODE_NVRAM_READ_DONE)!=0) && (g_UsbMode.b_start_srp==KAL_FALSE))
	{
		/* enable USB power */
		if(g_UsbMode.b_usb_pdnmode==KAL_TRUE)
		{
			g_UsbMode.b_usb_pdnmode = KAL_FALSE;
			USB_PDNmode(KAL_FALSE);
			OTG_Init(OTG_Host_Stop_Hdlr);
		}	 

		if(OTG_Get_Plug_Type()==OTG_PLUG_B)
		{
			OTG_B_Set_Session_Valid(KAL_TRUE);	
		}
	}

	if ((INT_USBBoot() == KAL_TRUE) && (g_UsbMode.cable_type!=USB_MODE_CABLE_PLUGOUT) 
		&&((g_UsbMode.mode_param&USB_MODE_BMT_READ_DONE)!=0) )
	{						
		/* enable USB power */
		if(g_UsbMode.b_usb_pdnmode==KAL_TRUE)
		{
			g_UsbMode.b_usb_pdnmode = KAL_FALSE;
			USB_PDNmode(KAL_FALSE);
			OTG_Init(OTG_Host_Stop_Hdlr);
		}	

		if(OTG_Get_Plug_Type()==OTG_PLUG_B)
			OTG_B_Set_Session_Valid(KAL_TRUE);
		else
			EXT_ASSERT(0, 0, 0, 0);
	}		
	
	//if((INT_USBBoot() == KAL_FALSE))
	if(1)
	{
		if((g_UsbMode.cable_type==USB_MODE_CABLE_PLUGOUT) && (g_UsbMode.previous_cable_type != USB_MODE_CABLE_PLUGOUT))
		{
			g_UsbMode.b_start_hnp = KAL_FALSE;		
			g_UsbMode.b_start_srp = KAL_FALSE;
			
			OTG_Process_Exceptions();
			/* power down USB */
			if(g_UsbMode.b_usb_pdnmode==KAL_FALSE)
			{
				g_UsbMode.b_usb_pdnmode = KAL_TRUE;
				USB_PDNmode(KAL_TRUE);
			}
		}

		if((g_UsbMode.b_start_srp==KAL_TRUE) && (INT_USBBoot() == KAL_FALSE))
		{
			if(g_UsbMode.cable_type==USB_MODE_CABLE_B_PLUGIN) 
			{
				g_UsbMode.b_start_srp = KAL_FALSE;
			}
			else if(g_UsbMode.cable_type==USB_MODE_CABLE_A_PLUGIN) 
			{
				g_UsbMode.b_start_srp = KAL_FALSE;
				/* In case original B plug is plug in and during SRP procedure
				    then A plug is inserted at this time */			
				    OTG_Process_Exceptions();
			}
		}	
	}	
#endif	
}

/************************************************************
	configure mode  functions
*************************************************************/

/* The enable parameter decides whether to turn on D+ at this time */
void USB_Config_Type(USB_DEVICE_TYPE type, kal_bool b_enable, kal_uint32 *parameter)
{
	gUsbDevice.usb_config_result = KAL_TRUE;

	if(gUsbDevice.usb_comport_boot == KAL_TRUE)
	{
		/* STOP_MS is for USB boot up mode */
		if((type != USB_STOP_MS)&&(type != USB_CDC_ACM)&&(type != USB_CDC_ACM_IRDBG))
			EXT_ASSERT(0, type, 0, 0);
	}
	else
	{
		if((INT_USBBoot() == KAL_TRUE)&&(type != USB_STOP_MS))
			EXT_ASSERT(0, type, 0, 0);
	}

	/* avoid UEM send to request, the second one will be no use*/
	if (((type == USB_CDC_ACM)||(type == USB_CDC_ACM_IRDBG)) && (gUsbDevice.device_type != USB_CDC_ACM))
	{
#ifdef __DSPIRDBG__
		if(type == USB_CDC_ACM_IRDBG)
		{
			g_UsbACM.acm_owner = USB_ACM_OWNER_DSP;
			/* Reset owner id, to avoid UART owner still use USB com port after USB had config as logging mode */
			USB2UARTPort.UART_id = MOD_DRV_HISR;
			USB_DSPIRDBG_Init();
	#if defined(DRV_USB_IRDBG_V2)
			IRDBG_Drv_Activate_ISR();
	#endif
		}
		else
		{
			g_UsbACM.acm_owner = USB_ACM_OWNER_UART;
		}
#endif	/* __DSPIRDBG__ */
	
		/* Add for USB in MS mode but user still choose USB as com port at Engineering mode */
		if((gUsbDevice.usb_comport_boot == KAL_TRUE)&&(INT_USBBoot() == KAL_TRUE)&&(g_UsbMS.b_ms_first_plugin == KAL_TRUE))
		{
			USB_Get_Serial_Value();
			g_UsbMS.b_ms_first_plugin = KAL_FALSE;
		}

		/* initailize CDC_ACM */
		USB_Register_CreateFunc("ACM DATA", USB_Acm_DataIf_Create, USB_Acm_DataIf_Reset, USB_Acm_DataIf_Speed_Reset);
		USB_Register_CreateFunc("ACM COMMU.", USB_Acm_CommIf_Create, USB_Acm_CommIf_Reset, USB_Acm_CommIf_Speed_Reset);
		USB_Register_Device_Code(USB_ACM_DEVICE_CODE, USB_ACM_SUBCLASS_CODE, 
									USB_ACM_PROTOCOL_CODE, g_UsbACM.acm_param->desc_product);
		
		USB_Init(USB_CDC_ACM, b_enable);
	}
	else if (type == USB_MASS_STORAGE)
	{	
#ifdef __USB_IN_NORMAL_MODE__	
		if(kal_if_hisr()==KAL_FALSE)
		{
			USB_Init_Normal_Mode_Ms(parameter, b_enable); 
		}
		else
		{
		#ifdef __OTG_ENABLE__	
			OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_INIT_NOMAL_MS, parameter, b_enable);
		#else
			EXT_ASSERT(0, 0, 0, 0);
		#endif		
		}
#endif
	}
#ifdef WEBCAM_SUPPORT
	else if ((type == USB_VIDEO) && (gUsbDevice.device_type != USB_VIDEO))
	{
		USB_Register_CreateFunc("USBVIDEO VC", USBVideo_VC_If_Create, USBVideo_VC_If_Reset, USBVideo_VC_If_Speed_Reset);
		USB_Register_CreateFunc("USBVIDEO VS", USBVideo_VS_If_Create, USBVideo_VS_If_Reset, USBVideo_VS_If_Speed_Reset);
		USB_Register_Device_Code(USBVIDEO_DEVICE_CODE, USBVIDEO_SUBCLASS_CODE, 
									USBVIDEO_PROTOCOL_CODE, g_USBVideo.custom_param->desc_product);
		USB_Init(USB_VIDEO, b_enable);
	}
#endif /* WEBCAM_SUPPORT */	
	else if (type == USB_STOP_MS)
	{
#ifdef __NVRAM_IN_USB_MS__		
		/* This can not be executed in HISR*/
		if(kal_if_hisr()== KAL_TRUE)
		{
			ASSERT(0);
		}

		if(INT_USBBoot() == KAL_TRUE)
		{
			if(gUsbDevice.usb_comport_boot == KAL_FALSE)
			{
				/* Prevent USB still communicate with PC before handset power down */
				gUsbDevice.device_type = USB_UNKOWN;
				gUsbDevice.is_configured_now = KAL_FALSE;
				USB_PDNmode(KAL_TRUE);   /* power down USB, disable D+ pull high */
				USB_Free_DMA_Channel(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE);
				USB_Release_Ms_Status();
				USB_End_Ms();
			}
		}
		else
		{
	#ifdef __USB_IN_NORMAL_MODE__	
			gUsbDevice.device_type = USB_UNKOWN;
			gUsbDevice.is_configured_now = KAL_FALSE;
			USB_PDNmode(KAL_TRUE);   /* power down USB, disable D+ pull high */
			USB_Free_DMA_Channel(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE);
			USB_Release_Ms_Status();
			USB_End_Normal_Mode_Ms();
	#else
			ASSERT(0);
	#endif
		}
#endif
	}
#ifdef PICTBRIDGE_SUPPORT
	else if ((type == USB_IMAGE) && (gUsbDevice.device_type != USB_IMAGE))
	{
		/* initailize IMAGE class */
		USB_Register_CreateFunc("IMAGE", USB_Image_If_Create, USB_Image_If_Reset, USB_Image_If_Speed_Reset);
		USB_Register_Device_Code(USB_IMAGE_DEVICE_CODE, USB_IMAGE_SUBCLASS_CODE, 
									USB_IMAGE_PROTOCOL_CODE, g_USBImage.image_param->desc_product);
		/* get 4-byte alignment image buffer and xml buffer */
		/* We divide 32KB buffer into several segments */

		g_USBImage.dps_response_rx_data= (kal_uint8 *)parameter;
		g_USBImage.dps_request_rx_data = (kal_uint8 *)g_USBImage.dps_response_rx_data + USB_IMAGE_MAX_XMLHRSPONSESIZE;
		g_USBImage.dps_response_tx_data = (kal_uint8 *)g_USBImage.dps_request_rx_data + USB_IMAGE_MAX_XMLHREQUESTSIZE;
		g_USBImage.dps_request_tx_data = (kal_uint8 *)g_USBImage.dps_response_tx_data + USB_IMAGE_MAX_XMLBUFFERSIZE;
		g_USBImage.image_buffer = (USB_IMAGE_BUFFER *)((kal_uint32)g_USBImage.dps_request_tx_data + USB_IMAGE_MAX_XMLBUFFERSIZE);
		g_USBImage.image_info_buffer = (kal_uint8 *)g_USBImage.dps_request_tx_data + USB_IMAGE_MAX_START_JOB_XMLBUFFERSIZE;
		USB_Init(USB_IMAGE, b_enable);
	}
#endif
	else
	{
		EXT_ASSERT(0, type, gUsbDevice.device_type, 0);
	}
}


/* The enable parameter decides whether to turn off D+ at this time */
void USB_Release_Type(kal_bool b_enable, kal_bool b_plugout)
{
	USB_DEVICE_TYPE device_type;
	
	device_type = gUsbDevice.device_type;
	gUsbDevice.is_configured_now = KAL_FALSE;

	/* note that device type should be set to unknown here, 
	in case UART owner uses other UART functions */
	gUsbDevice.device_type = USB_UNKOWN;

	if(b_enable == KAL_TRUE)
	{
		/* power down USB */
		USB_PDNmode(KAL_TRUE);   /*  disable D+ pull high */
	}	

	/* stop and release resource*/
	if (device_type == USB_MASS_STORAGE)
	{
		USB_Free_DMA_Channel(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE);
		USB_Release_Ms_Status();

		if(INT_USBBoot() == KAL_FALSE) /* normal mode */
		{
#ifdef __USB_IN_NORMAL_MODE__	
			if(kal_if_hisr() == KAL_FALSE)
			{
				USB_End_Normal_Mode_Ms();	
			}
			else
			{
	#ifdef __OTG_ENABLE__	
				OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_END_NORMAL_MS, 0, KAL_FALSE);
	#else
				EXT_ASSERT(0, 0, 0, 0);
	#endif
			}
#else
			EXT_ASSERT(0, 0, 0, 0);
#endif			
		}
		else
		{
#ifdef __NVRAM_IN_USB_MS__
			if(kal_if_hisr() == KAL_FALSE)
			{
				USB_End_Ms();
			}
			else
			{
	#ifdef __OTG_ENABLE__	
				OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_END_MS, 0, KAL_FALSE);
	#else
				EXT_ASSERT(0, 0, 0, 0);
	#endif	
			}
#endif	
		}
	}
	else if(device_type == USB_CDC_ACM)
	{
#ifdef __DSPIRDBG__	
		if(g_UsbACM.acm_owner == USB_ACM_OWNER_DSP)
		{
			USB_DSPIRDBG_Stop();
		}
		else
#endif /* __DSPIRDBG__*/
		{
			/* notify UART owner that virtual UART cable is plug out*/
			/* Note that this should be called before release ACM status */
			if((g_UsbACM.send_UARTilm == KAL_TRUE) && (USB2UARTPort.ownerid != MOD_DRV_HISR))	
			{
				USB_Send_Msg(USB_SEND_MSG_UART_PLUG_OUT, 0, KAL_TRUE);
			}
		}	
		
		USB_Free_DMA_Channel(g_UsbACM.txpipe->byEP, USB_TX_EP_TYPE);
		/* release global variable g_UsbACM resource*/
		USB_Release_Acm_Status();
	}
#ifdef WEBCAM_SUPPORT
	else if(device_type == USB_VIDEO)
	{
		if(g_UsbMode.cable_type==USB_MODE_CABLE_PLUGOUT)/*real plug out, not these two messages result in*/
		{
			/* Update video state machine */
			USBVideo_Plug_Out_Hdlr();
		}
		
		USB_Free_DMA_Channel(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE);
		USB_Release_Video_Status();
	}
#endif  /* WEBCAM_SUPPORT */
#ifdef  PICTBRIDGE_SUPPORT
	else if(device_type == USB_IMAGE)
	{
		USB_Free_DMA_Channel(g_USBImage.txpipe->byEP, USB_TX_EP_TYPE);
		USB_Release_Image_Status();
	}
#endif  /* PICTBRIDGE_SUPPORT */

	if(device_type!=USB_UNKOWN)
	{
		/* If cable is plug out second time in mass storage mode, do not send these msgs */
		USB_DeRegister_CreateFunc();
		USB_DeRegister_Device_Code();
		/* release global variable gUsbDevice resource*/	
		USB_Release_Device_Status();	
	}				

	if(b_plugout == KAL_TRUE)
	{
		drv_trace0(TRACE_FUNC, USB_PLUG_OUT);
//		kal_prompt_trace(MOD_USB, "USB plug out");

		USB_Release();

		if((gUsbDevice.usb_comport_boot == KAL_FALSE)||(INT_USBBoot() == KAL_TRUE))
		{
#ifndef OTG_NORMAL_APP_FIXED
			/* Notify UEM, MS mode must send this message to shut down */
			USB_Send_Msg(USB_SEND_MSG_PLUG_OUT, 0, KAL_TRUE);
#endif
		}
	}
}


#ifdef __OTG_ENABLE__
static void OTG_Host_Stop_Hdlr(void)
{
	USBD_Detach(USB_HCD_DETATCH, 0);
	if(g_UsbMode.b_start_hnp == KAL_TRUE)
	{
#ifndef OTG_NORMAL_APP_FIXED
		/*Notify UEM*/
		USB_Send_Msg(USB_SEND_MSG_PLUG_OUT, 0, KAL_TRUE);	
#endif
	}
	return;
}

void OTG_Hdlr_Select(OTG_HDLR_TASK_TYPE type, kal_uint32 *parameter, kal_bool b_param)	
{
	switch(type)
	{
	case OTG_HDLR_TASK_INIT_MS:
		USB_Init_Ms(g_UsbMS.b_ms_first_plugin);
		g_UsbMS.b_ms_first_plugin = KAL_FALSE;
		break;
	case OTG_HDLR_TASK_END_MS:
		USB_End_Ms();
		break;
	case OTG_HDLR_TASK_INIT_NOMAL_MS:
		USB_Init_Normal_Mode_Ms(parameter, b_param);
		break;
	case OTG_HDLR_TASK_END_NORMAL_MS:
		USB_End_Normal_Mode_Ms();
		break;	
	default:
		break;
	}
}
#endif
/************************************************************
	mass storage mode functions
*************************************************************/
#ifdef __USB_IN_NORMAL_MODE__
static FS_DEVICE_TYPE_ENUM USB_Ms_Dev_To_Fs_Type(USB_STORAGE_DEV_TYPE type)
{
	FS_DEVICE_TYPE_ENUM fs_type = FS_DEVICE_TYPE_MAX_VALUE;
	
	switch(type)
	{
	case USB_STORAGE_DEV_NOR:
		fs_type = FS_DEVICE_TYPE_NOR;
		break;
 	case USB_STORAGE_DEV_NAND:
 		fs_type = FS_DEVICE_TYPE_NAND;
 		break;
 	case USB_STORAGE_DEV_CARD:
 		fs_type = FS_DEVICE_TYPE_CARD;
 		break;
 	default:
 		EXT_ASSERT(0, type, 0, 0);
 		break;
	}
	return fs_type;
}

#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
static kal_bool usbms_read_sysdrv( void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_uint32  received_file_size;
	kal_int32	   result;

	result = FS_Seek(g_UsbMS.system_drive_handle, (LBA*512), FS_FILE_BEGIN);

	if(result < 0)
		EXT_ASSERT(0, result, 0, 0);

	result = FS_Read(g_UsbMS.system_drive_handle, data, (sec_len*512), &received_file_size);

	if(result != FS_NO_ERROR)
		EXT_ASSERT(0, result, 0, 0);

	return KAL_TRUE;
}


static kal_bool usbms_write_sysdrv(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_uint32  file_size;
	kal_int32	   result;
	
	result = FS_GetFileSize(g_UsbMS.system_drive_handle, &file_size);
	if(result != FS_NO_ERROR)
		EXT_ASSERT(0, result, 0, 0);
	
	if((LBA + sec_len)*512 >  (file_size) )
		EXT_ASSERT(0, (LBA + sec_len)*512, file_size, 0);
	
	result = FS_Seek(g_UsbMS.system_drive_handle, (LBA*512), FS_FILE_BEGIN);

	if(result < 0)
		EXT_ASSERT(0, result, 0, 0);
	
	result = FS_Write(g_UsbMS.system_drive_handle, data, (sec_len*512), &file_size);

	if(result != FS_NO_ERROR)
		EXT_ASSERT(0, result, 0, 0);

	return KAL_TRUE;
}

static kal_bool usbms_read_capacity_sysdrv(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
	kal_uint32  lba = 512;
	kal_int32	   result;

	*sec_len = 512;
	result = FS_GetFileSize(g_UsbMS.system_drive_handle, &lba);

	if(result != FS_NO_ERROR)
		EXT_ASSERT(0, result, 0, 0);

	*max_lba = (lba/512) - 1;
   
	return KAL_TRUE;
}

static kal_uint8 usbms_checkmedia_exit_sysdrv(void)
{
	return 0;
}

static kal_bool usbms_format_sysdrv()
{
	return KAL_TRUE;  
}

static kal_bool usbms_prevmedia_removal_sysdrv(kal_bool enable)
{
	return KAL_TRUE;
}

/*
static kal_bool usbms_read_formatcapacity_sysdrv(kal_uint32 *no_of_blks, kal_uint32 *blk_len)
{
	return KAL_TRUE;
}
*/

static USB_STORAGE_DEV_TYPE usbms_dev_type_sysdrv(void)
{
	/* it must be NAND or NOR flash */
	if(g_UsbMS.device_type >= USB_STORAGE_DEV_CARD)
		EXT_ASSERT(0, g_UsbMS.device_type, 0, 0);

	return g_UsbMS.device_type;
}

/* If we want to export the drive which system drive in the same disk, then we need to build this fake MS APIs to replace NOR or NAND flash APIs */
USB_DiskDriver_STRUCT USB_SYSTEM_drv = 
{
	usbms_read_sysdrv,
	usbms_write_sysdrv,
	usbms_format_sysdrv,
	usbms_checkmedia_exit_sysdrv,
	usbms_prevmedia_removal_sysdrv,
	usbms_read_capacity_sysdrv,
//	usbms_read_formatcapacity_sysdrv,
	usbms_dev_type_sysdrv
};
#endif


static void USB_Init_Normal_Mode_Ms(kal_uint32* mem_addr, kal_bool b_enable)
{
	kal_int32 index;
	USB_STORAGE_DEV_TYPE dev_type;
	FS_DEVICE_TYPE_ENUM fs_type;	
	kal_int32	result;
	kal_uint8 max_lun = USB_Ms_Get_Max_LUN();

	/* This function can not be executed in HISR*/
	if(kal_if_hisr() == KAL_TRUE)
	{
		ASSERT(0);
	}

	/* get disk buffer */
	g_UsbMS.disk_buffer = (void*)mem_addr;

	/* lock file system */
	result = FS_LockFAT(FS_EXPORT_ENUM);

	if(result < 0)
	{
		gUsbDevice.usb_config_result = KAL_FALSE;
		return;
	}

	/* query whether each device can be exported or not (system driver disk)*/
	for(index = max_lun; index >= 0; index--)
	{
		/* get each device type and translate to file system type */
		dev_type = USB_Ms_Dev_Type(index);
		fs_type = USB_Ms_Dev_To_Fs_Type(dev_type);
		/* query whether it can be exported or not */
		result = FS_GetDevStatus(fs_type, FS_EXPORT_STATE_ENUM);
		
		if(result == FS_NO_ERROR)
		{
			/* device is not exported, means it is system drive inside */
#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
			WCHAR  temp_path1[] = L"x:\\";
			WCHAR  temp_path2[] = L"\\\\.\\x:";
			kal_int16   drvLetter;

/*
			result = FS_GetDevPartitions(fs_type);
			if (result <= 1)
			{
				// There're no partition on this physical device
				EXT_ASSERT(0, result, fs_type, 0);
			}
*/

			/* get the drive letter we want to export */
			drvLetter = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
			temp_path1[0] = drvLetter;

			if (fs_type != FS_GetDevType(temp_path1))
			{
				drvLetter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_NO_ALT_DRIVE);
				temp_path1[0] = drvLetter;

				if (fs_type != FS_GetDevType(temp_path1))
					EXT_ASSERT(0, fs_type, FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE), 
											FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_NO_ALT_DRIVE));
			}

			temp_path2[4] = drvLetter;
			g_UsbMS.system_drive_handle = FS_Open(temp_path2, FS_READ_WRITE);
			if(g_UsbMS.system_drive_handle < 0)
			{
				EXT_ASSERT(0, g_UsbMS.system_drive_handle, 0, 0);
			}
			
			g_UsbMS.device_type = dev_type;
			USB_Ms_Change_Register_DiskDriver(index, &USB_SYSTEM_drv);
#else
			USB_Ms_DeRegister_DiskDriver(index);
#endif /* __USB_IN_NORMAL_MODE_IMPROVE__ */
		}
		else if(result != FS_DEVICE_EXPORTED_ERROR)
		{
			EXT_ASSERT(0, result, dev_type, fs_type);
		}
	}

	/* Initialize storage function */
	USB_Register_CreateFunc("MASS STORAGE", USB_Ms_If_Create, USB_Ms_If_Reset, USB_Ms_If_Speed_Reset);
	USB_Register_Device_Code(USB_MS_DEVICE_CODE, USB_MS_SUBCLASS_CODE, 
											USB_MS_PROTOCOL_CODE, g_UsbMS.ms_param->desc_product);

	/* initialize MASS STORAGE MODE */
	USB_Init(USB_MASS_STORAGE, b_enable);
}

static void USB_End_Normal_Mode_Ms(void)
{
	/* This function can not be executed in HISR*/
	if(kal_if_hisr()==KAL_TRUE)
		EXT_ASSERT(0, 0, 0, 0);
#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
	FS_Close(g_UsbMS.system_drive_handle);
	/* for debugging */
	g_UsbMS.system_drive_handle = -1;
#endif
	FS_LockFAT(FS_REMOUNT_ENUM);
}

#endif  /* __USB_IN_NORMAL_MODE__ */

void USB_Init_Ms(kal_bool bFirst)
{
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif

	/* This function can not be executed in HISR*/
	if(kal_if_hisr() == KAL_TRUE)
		EXT_ASSERT(0, 0, 0, 0);

#ifdef OTG_NORMAL_APP_FIXED
	ASSERT(0);
#endif

#ifdef __NVRAM_IN_USB_MS__
	/* Notify UEM*/
	USB_Send_Msg(USB_SEND_MSG_PLUG_IN, 0, KAL_TRUE);
#else
	if(bFirst)
	{
		/* Notify UEM*/
		USB_Send_Msg(USB_SEND_MSG_PLUG_IN, 0, KAL_TRUE);
	}	
#endif

	/* If not first time plug in, only notify UEM*/	
	if(bFirst)
	{
		/* get unique string from nvram and construct serial string*/
		USB_Get_Serial_Value();
	
#ifdef __P_PROPRIETARY_COPYRIGHT__
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

		/* must lock file system before turn on USB power */
		FS_LockFAT(FS_LOCK_USB_ENUM);	//lock file system in ms mode

		USB_Register_CreateFunc("MASS STORAGE", USB_Ms_If_Create, USB_Ms_If_Reset, USB_Ms_If_Speed_Reset);
		USB_Register_Device_Code(USB_MS_DEVICE_CODE, USB_MS_SUBCLASS_CODE, 
											USB_MS_PROTOCOL_CODE, g_UsbMS.ms_param->desc_product);

		/* initialize MASS STORAGE MODE */
		USB_Init(USB_MASS_STORAGE, KAL_TRUE);
	}	
}

static void USB_End_Ms(void)
{
#ifdef __NVRAM_IN_USB_MS__
	/* This function can not be executed in HISR*/
	if(kal_if_hisr()==KAL_TRUE)
		EXT_ASSERT(0, 0, 0, 0);
	
	FS_LockFAT(FS_UNLOCK_USB_ENUM);
#else
	EXT_ASSERT(0, 0, 0, 0);	
#endif
}

void USB_Init_ACM_In_Meta(void)
{
	static kal_bool b_init_acm_meta = KAL_FALSE;
	
	if(b_init_acm_meta==KAL_FALSE)
	{
                b_init_acm_meta = KAL_TRUE;

		/* init ft acm parameters*/
		USB_Acm_FT_Init();
	
		/* initailize CDC_ACM */
		USB_Register_CreateFunc("ACM DATA", USB_Acm_DataIf_Create, USB_Acm_DataIf_Reset, USB_Acm_DataIf_Speed_Reset);
		USB_Register_CreateFunc("ACM COMMU.", USB_Acm_CommIf_Create, USB_Acm_CommIf_Reset, USB_Acm_CommIf_Speed_Reset);
		USB_Register_Device_Code(USB_ACM_DEVICE_CODE, USB_ACM_SUBCLASS_CODE, 
										USB_ACM_PROTOCOL_CODE, g_UsbACM.acm_param->desc_product);
		USB_Init(USB_CDC_ACM, KAL_TRUE);	
	}	
}



