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
 *    otg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements otg application functions
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
#include "reg_base.h" 
#include "drvpdn.h"
#include "intrCtrl.h"
#include "gpio_sw.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "gpt_sw.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */

#include "usb_comm.h"
#include "usb.h"
#include "usb_resource.h"
#include "usb_drv.h"
#include "usbms_drv.h"
#include "usbacm_drv.h"

#include "usb_hcd.h"
#include "usbd.h"
#include "usb_host_default_drv.h"
#include "usb_host_ms_drv.h"

#include "otg_drv.h"
#include "otg.h"

#include "syscomp_config.h"
#include "usb_task.h"
#include "usb_mode.h"

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */


#ifdef __OTG_ENABLE__

#ifdef OTG_NORMAL_APP_FIXED
extern kal_uint32  g_USB_Mass_Buffer[32*1024/4];
#endif

OTG_Struct gUsbOtg;

/* get system boot mode*/
extern kal_bool INT_USBBoot(void);
/* modify external interrupt debiunce time */
extern kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);

static void OTG_Host_Up_Hdlr(void);
static void OTG_Host_Down_Hdlr(void);
static void OTG_Device_Up_Hdlr(void);
static void OTG_Device_Down_Hdlr(void);
static void OTG_A_VRise_Fail_Hdlr(void);
static void OTG_A_HNP_Fail_Hdlr(void);
static void OTG_A_HNP_Stop_Hdlr(void);
static void OTG_A_No_Response_Hdlr(void);
static void OTG_B_HNP_Fail_Hdlr(void);
static void OTG_B_SRP_Fail_Hdlr(void);
static void OTG_B_SRP_Stop_Hdlr(void);

/* Iniailize function, init all OTG resource */
void OTG_Init(otg_intr_handler_ptr hdlr_a_host_stop)
{
	gUsbOtg.b_check_srp = KAL_FALSE;
	gUsbOtg.hnp_srp_type = USB_UNKOWN;
		
	OTG_Init_Drv_Info();
	OTG_Register_Drv_Info(OTG_DRV_HDLR_HOST_UP, OTG_Host_Up_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_HOST_DOWN, OTG_Host_Down_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_DEVICE_UP, OTG_Device_Up_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_DEVICE_DOWN, OTG_Device_Down_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_VRISE_FAIL, OTG_A_VRise_Fail_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_HNP_FAIL, OTG_A_HNP_Fail_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_HNP_STOP, OTG_A_HNP_Stop_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_NO_RESPONSE, OTG_A_No_Response_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_B_HNP_FAIL, OTG_B_HNP_Fail_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_B_SRP_FAIL, OTG_B_SRP_Fail_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_B_SRP_STOP, OTG_B_SRP_Stop_Hdlr);
	if(hdlr_a_host_stop!=NULL)
		OTG_Register_Drv_Info(OTG_DRV_HDLR_A_HOST_STOP, hdlr_a_host_stop);

	OTG_Init_Drv();

	OTG_Drv_Activate_ISR();
}

void OTG_Start_SRP(void)
{
	/* enable USB power */
	if(g_UsbMode.b_usb_pdnmode==KAL_TRUE)
	{
		g_UsbMode.b_usb_pdnmode = KAL_FALSE;
		USB_PDNmode(KAL_FALSE);
		OTG_Init(NULL);
	}	

	g_UsbMode.b_start_srp = KAL_TRUE;
	OTG_B_Set_Session_Valid(KAL_FALSE);
}

void OTG_Config_SRP(USB_DEVICE_TYPE type, kal_uint32 *parameter)
{
	/* sleep for stable */
	kal_sleep_task(5);
	gUsbOtg.hnp_srp_type = type;
	gUsbOtg.hnp_srp_parameter = parameter;
	gUsbOtg.b_check_srp = KAL_TRUE;
	/* config request */
	USB_Config_Type(gUsbOtg.hnp_srp_type, KAL_FALSE, gUsbOtg.hnp_srp_parameter);
//	#ifndef _USB_VBUS_DETECT_WITH_NIRQ_	
//		EINT_SW_Debounce_Modify(gUsbOtg.eint_no, 0);	
//	#endif
	OTG_Display_Message(OTG_DISPLAY_MSG_CONNECTING);
	OTG_B_Start_SRP();
}


void OTG_Config_HNP(USB_DEVICE_TYPE type, kal_uint32 *parameter)
{
	gUsbOtg.hnp_srp_type = type;
	gUsbOtg.hnp_srp_parameter = parameter;
	g_UsbMode.b_start_hnp = KAL_FALSE;
	OTG_A_Start_HNP();	
}

static void OTG_Host_Up_Hdlr(void)
{
	USBD_Init_Status();
	USBD_Register_Class_Driver(&USB_Host_Ms_Drv);
	USBD_Register_Class_Driver(&USB_Host_Default_Drv);
	USBD_Init();
	return;
}

static void OTG_Host_Down_Hdlr(void)
{
	USBD_Release_Status();
	USBD_Derigister_Class_Driver();
	USBD_Release();
	return;
}

static void OTG_Device_Up_Hdlr(void)
{	
	if(OTG_Get_Plug_Type()==OTG_PLUG_B)
	{
		if(gUsbOtg.b_check_srp== KAL_TRUE)
		{			
			OTG_Enable_Device();

		#ifndef OTG_SRP_HNP_APP_FIXED
			/* Notify UEM*/
			USB_Send_Msg(USB_SEND_MSG_CONFIG_CNF, gUsbOtg.hnp_srp_type, KAL_TRUE);
		#endif

			/* SRP success */
			gUsbOtg.b_check_srp = KAL_FALSE;
			gUsbOtg.hnp_srp_type = USB_UNKOWN;
		}
		else
		{
			if(INT_BootMode() == MTK_FACTORY_MODE)
			{
				USB_Init_ACM_In_Meta();	
			}
			else if(INT_USBBoot() == KAL_TRUE)
			{
				if(kal_if_hisr()==KAL_FALSE)
				{
					USB_Init_Ms(g_UsbMS.b_ms_first_plugin);
					g_UsbMS.b_ms_first_plugin = KAL_FALSE; 
				}
				else
				{
					OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_INIT_MS, 0, KAL_FALSE);
				}
			}
			else
			{
				/* When B_HOST, it is HNP second phase */
				//if((OTG_Get_State()!=OTG_STATE_B_HOST) && (OTG_Get_State()!=OTG_STATE_B_WAIT_ACON))
				//{
				#ifdef OTG_NORMAL_APP_FIXED
					USB_Config_Type(USB_MASS_STORAGE, KAL_TRUE, g_USB_Mass_Buffer);
				#else
					/* Notify UEM*/
					USB_Send_Msg(USB_SEND_MSG_PLUG_IN, 0, KAL_TRUE);
				#endif
				//}	
				//else
				//{
				//	USB_Config_Type(USB_CDC_ACM, KAL_TRUE, NULL);
				//}
			}	
		}	
	}	
	else if(OTG_Get_Plug_Type()==OTG_PLUG_A)
	{
		/* This must come from HNP */
		USB_Config_Type(gUsbOtg.hnp_srp_type, KAL_TRUE, gUsbOtg.hnp_srp_parameter);
#ifndef OTG_SRP_HNP_APP_FIXED		
		/* Notify UEM*/
		USB_Send_Msg(USB_SEND_MSG_CONFIG_CNF, gUsbOtg.hnp_srp_type, KAL_TRUE);
#endif
		gUsbOtg.hnp_srp_type = USB_UNKOWN;		
	}
	else
	{
		EXT_ASSERT(0, (kal_uint32)OTG_Get_Plug_Type(), 0, 0);
	}
	return;
}

static void OTG_Device_Down_Hdlr(void)
{
	if(INT_BootMode() == MTK_FACTORY_MODE)
	{
		USB_Release_Type(KAL_FALSE, KAL_FALSE);
	}
	else
	{
		USB_Release_Type(KAL_FALSE, KAL_TRUE);
	}		
			
	return;
}

static void OTG_A_VRise_Fail_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT);
	return;
}

static void OTG_A_HNP_Fail_Hdlr(void)
{
#ifndef OTG_SRP_HNP_APP_FIXED
	/* Notify UEM*/
	if(gUsbOtg.hnp_srp_type!=USB_UNKOWN)
		USB_Send_Msg(USB_SEND_MSG_CONFIG_CNF, gUsbOtg.hnp_srp_type, KAL_FALSE);
	USB_Send_Msg(USB_SEND_MSG_PLUG_OUT, 0, KAL_TRUE);
#endif	
	OTG_Display_Message(OTG_DISPLAY_MSG_HNP_STOP);
	gUsbOtg.hnp_srp_type = USB_UNKOWN;
	return;
}

static void OTG_A_HNP_Stop_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_HNP_STOP);
}

static void OTG_A_No_Response_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE);
	return;
}

static void OTG_B_HNP_Fail_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE);
	return;
}

static void OTG_B_SRP_Fail_Hdlr(void)
{
	if(gUsbOtg.b_check_srp==KAL_TRUE)
	{
//#ifndef _USB_VBUS_DETECT_WITH_NIRQ_	
//		EINT_SW_Debounce_Modify(gUsbOtg.eint_no, gUsbOtg.eint_time_delay);
//#endif

#ifndef OTG_SRP_HNP_APP_FIXED
		/* Notify UEM*/
		USB_Send_Msg(USB_SEND_MSG_CONFIG_CNF, gUsbOtg.hnp_srp_type, KAL_FALSE);
		OTG_Device_Down_Hdlr();
#else
		gUsbDevice.device_type = USB_UNKOWN;
		USB_Free_DMA_Channel(g_UsbMS.txpipe->byEP);
		/* release global variable g_UsbACM resource*/
		USB_Release_Ms_Status();
		OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_END_NORMAL_MS, 0, KAL_FALSE);
		/* If cable is plug out second time in mass storage mode, do not send these msgs */
		USB_DeRegister_CreateFunc();
		USB_DeRegister_Device_Code();
		/* release global variable gUsbDevice resource*/	
		USB_Release_Device_Status();
		USB_Release();
#endif

		/* reset to default */
		gUsbOtg.hnp_srp_type = USB_UNKOWN;

		gUsbOtg.b_check_srp = KAL_FALSE;

		OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE);
	}
}

static void OTG_B_SRP_Stop_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_STOP_CONNECTING);
}

void OTG_Init_SRP(void)
{
	kal_uint32	src_mod	;	
	ilm_struct 	*usb_ilm;
	
	src_mod = stack_int_get_active_module_id();
	
	DRV_BuildPrimitive(usb_ilm,
				src_mod,
				MOD_USB,
				MSG_ID_SRP_INIT,
				NULL);
	msg_send_ext_queue(usb_ilm); 	
}

void OTG_Display_Message(OTG_DISPLAY_MSG_TYPE msg_type)
{
	kal_uint32		src_mod	;
	ilm_struct 		*usb_ilm;
	otg_display_struct *display_ind;
	
	if(kal_if_hisr()==KAL_TRUE)
		src_mod = MOD_DRV_HISR;
	else
		src_mod = MOD_USB;	

	display_ind = (otg_display_struct*)construct_local_para(
					sizeof(otg_display_struct), TD_CTRL);
	display_ind->type = msg_type;
	DRV_BuildPrimitive(usb_ilm,
				src_mod,
				MOD_FMT,
				MSG_ID_OTG_DISPLAY_IND,
				display_ind);
	msg_send_ext_queue(usb_ilm);
}

void OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_TYPE type, kal_uint32* parameter, kal_bool b_param)
{
	ilm_struct 		*usb_ilm;
	otg_hdr_ind_struct *hdlr_ind;

	/* This function is used for OTG HISR to notify task */
	if(kal_if_hisr()!=KAL_TRUE)
		EXT_ASSERT(0, 0, 0, 0);

	hdlr_ind = (otg_hdr_ind_struct*)construct_local_para(
					sizeof(otg_hdr_ind_struct), TD_CTRL);
	hdlr_ind->type = type;
	hdlr_ind->parameter = parameter;
	hdlr_ind->b_param = b_param;
	DRV_BuildPrimitive(usb_ilm,
				MOD_DRV_HISR,
				MOD_USB,
				MSG_ID_OTG_HDLR_IND,
				hdlr_ind);
	msg_send_ext_queue(usb_ilm);
}

#endif

