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
 *    usb_task.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb task
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
#include "usb_msdisk.h"
#include "usbacm_drv.h"
#include "usbacm_ft.h"

#ifdef WEBCAM_SUPPORT
#include "usbvideo_if.h"
#include "usbvideo_drv.h"
#include "usbvideo_state.h"
#endif
#ifdef __OTG_ENABLE__
#include "otg_drv.h"
#include "otg.h"
#include "usbd.h"
#include "usb_host_default_drv.h"
#include "usb_host_ms_state.h"
#include "gpio_sw.h"
#endif
#include "usb_mode.h"
#include "usb_task.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"
#ifdef   PICTBRIDGE_SUPPORT
#include "usbimage_drv.h"
#include "ptp_state.h"
#endif
#include "app_buff_alloc.h"
#include "nvram.h"
#include "nvram_interface.h"
#include "nvram_user_defs.h"

#ifdef __DSPIRDBG__
#include "usbacm_dsp.h"
#include "irdbg_drv.h"
#include "device.h"
#endif

#include "pwic.h"

#include "fat_fs.h"
#include "rtfiles.h"

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */

#ifdef OTG_NORMAL_APP_FIXED
extern kal_uint32  g_USB_Mass_Buffer[32*1024/4];
#endif
// only 6238 E1
#include "usb_hw.h"
/************************************************************
        extern  functions
*************************************************************/
/* function to get buffer for usb boot mode*/
extern void *kal_tmp_mem_alloc(kal_uint32 size);
/* get eint number*/
extern kal_uint8 custom_eint_get_channel(eint_channel_type type);
/* init eint */
extern void clear_ext_intr_init(kal_uint8 eint_no);
/* get USB boot mode */
extern kal_bool INT_USBBoot(void);
/* modify external interrupt debounce time */
extern kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);
/* On EVB board, there may be no PMIC. */
extern void BMT_sendMes2UEM(BMT_CHR_STAT status);
/* get target boot mode */
extern kal_uint16 INT_BootMode(void);
/* Com port nvram API */
extern void nvram_get_tst(kal_uint8 *port, kal_uint32 *baudrate);
extern void nvram_get_tst_l1(kal_uint8 *port, kal_uint32 *baudrate);
extern void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate);
extern void nvram_get_cti(kal_uint8 *port, kal_uint32 *baudrate);
#ifdef __DSPIRDBG__
extern void nvram_get_swdbg(kal_uint8 *swdbg_profile);
#endif

extern void custom_usb_ms_init(void);

#if defined(__SIM_PLUS__)
/* Used for sim+ */
extern kal_bool nvram_external_read_data(kal_uint8 LID,kal_uint8 rec_index, kal_uint8* buffer, kal_uint16 buffer_size);
/* global variables */
kal_bool g_usb_ms_simplus_exist;
#endif

/************************************************************
        local  functions
*************************************************************/
void USB_EINT_HISR(void);
static kal_bool usb_task_init(task_indx_type task_indx);
static kal_bool usb_task_reset(task_indx_type task_indx);
static kal_bool usb_task_end(task_indx_type task_indx);
static void usb_task_main( task_entry_struct * task_entry_ptr );
static void USB_Store_Serial_Value(ilm_struct *lim_ptr);
static kal_uint16 USB_Convert_String(kal_uint8 val);
static void USB_Constrct_Serial_String(kal_uint8 *pdu_ptr, kal_uint16 len);

static kal_uint8 g_usb_cable_state;
static kal_uint8 g_usb_eint_no;

#ifdef __DSPIRDBG__
static kal_bool g_usb_boot_as_irdbg = KAL_FALSE;
#endif

//#ifdef __OTG_ENABLE__
//static kal_uint8 *eint_sw_debounce_time_delay;
//#endif

/*************************************************************************
* FUNCTION                                                            
*	usb_create
*
* DESCRIPTION                                                           
*	This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool usb_create(comptask_handler_struct **handle)
{
#ifndef __USB_ENABLE__
	EXT_ASSERT(0, 0, 0, 0);
#endif

	static const comptask_handler_struct usb_handler_info = 
	{
		usb_task_main,			/* task entry function */
		usb_task_init,		  	/* task initialization function */
		NULL, 				/* task configuration function */
		usb_task_reset,			/* task reset handler */
		usb_task_end			/* task termination handler */
	};

	g_usb_eint_no = custom_eint_get_channel(usb_eint_chann);
	// remove to avoid affecting touch panel function
	//clear_ext_intr_init(g_usb_eint_no);

	*handle = (comptask_handler_struct *)&usb_handler_info;
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	usb_task_init
*
* DESCRIPTION
*	This function implements xyz's init handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_bool usb_task_init(task_indx_type task_indx)
{
#ifndef __USB_ENABLE__
	EXT_ASSERT(0, 0, 0, 0);
#endif

#if defined(__SIM_PLUS__)
	kal_uint8 	nvram_buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE]; 
#endif
	kal_uint32 buff_size = 0;
	kal_uint8		port_num;
	kal_uint32	baudrate;
#ifdef __DSPIRDBG__
	kal_uint8       usb_is_irdbg;
#endif
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif
#ifdef WEBCAM_SUPPORT
	kal_uint32 index;
#endif
	
#ifdef __OTG_ENABLE__
	OTG_Drv_Create_ISR();
#else
	USB_Drv_Create_ISR();   /*   Register USB_HISR, not active, ensure we have enough memory space  */
#endif

#if defined(DRV_USB_IP_V3)
	USBDMA_Drv_Create_ISR();
#endif

#ifdef __DSPIRDBG__
	#if defined(DRV_USB_IRDBG_V2)
	IRDBG_Drv_Create_ISR();
	#endif
#endif

#if defined(__SIM_PLUS__)
	/* Check SIM PLUS card exist or not in NVRAM column 4, */
	nvram_external_read_data(NVRAM_EF_SYS_CACHE_OCTET_LID, 
		NVRAM_SYS_SIM_PLUS_SETTING, nvram_buffer, NVRAM_EF_SYS_CACHE_OCTET_SIZE);

	g_usb_ms_simplus_exist = nvram_buffer[0];
#endif

	custom_usb_ms_init();

	/* check engineering mode com port setting */
	gUsbDevice.usb_comport_boot = KAL_FALSE;
	nvram_get_tst(&port_num, &baudrate);
	if (port_num == uart_port_usb)
		gUsbDevice.usb_comport_boot = KAL_TRUE;
	nvram_get_tst_l1(&port_num, &baudrate);
	if (port_num == uart_port_usb)
		gUsbDevice.usb_comport_boot = KAL_TRUE;
	nvram_get_ps(&port_num, &baudrate);
	if (port_num == uart_port_usb)
		gUsbDevice.usb_comport_boot = KAL_TRUE;
	nvram_get_cti(&port_num, &baudrate);
	if (port_num == uart_port_usb)
		gUsbDevice.usb_comport_boot = KAL_TRUE;

#ifdef __DSPIRDBG__
	nvram_get_swdbg(&usb_is_irdbg);
	if((usb_is_irdbg -1) == EM_SWDBG_MCU_DSP_IRDBG)
	{
		g_usb_boot_as_irdbg = KAL_TRUE;
		gUsbDevice.usb_comport_boot = KAL_TRUE;
	}
#endif

  	/* Do task's init here.*/
	if((INT_USBBoot() == KAL_TRUE)&&(gUsbDevice.usb_comport_boot == KAL_FALSE))   /* MS mode */  	
  	{
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
		buff_size = sizeof(Usb_Disk_Buffer);
#endif
 		
  		/* get the buffer at initialize time for USB boot mode*/	
  		g_UsbMS.disk_buffer = NULL;	
  		g_UsbMS.disk_buffer = kal_tmp_mem_alloc(buff_size);
  		if(g_UsbMS.disk_buffer == NULL)
			EXT_ASSERT(0, buff_size, 0, 0);	
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif			
  	}
  	
  	/* get customize parameters*/
	gUsbDevice.device_param = USB_GetCustomFunc()->get_device_param_func();
	g_UsbMS.ms_param = USB_GetCustomFunc()->get_ms_param_func();
	g_UsbACM.acm_param = USB_GetCustomFunc()->get_acm_param_func();
#ifdef WEBCAM_SUPPORT	
	g_USBVideo.custom_param = USB_GetCustomFunc()->get_video_param_func();
	g_USBVideo.camera_param = USBVideo_Get_Camera_Param();

	for(index = 0; index < USBVIDEO_VIDEO_SIZE_MAX; index++)
	{
		g_USBVideo.video_control.default_jpeg_max_size[index] = 0;
		g_USBVideo.video_control.b_set_default_jpeg_max_size[index] = KAL_FALSE;
	}
#endif
#ifdef  PICTBRIDGE_SUPPORT
	g_USBImage.image_param = USB_GetCustomFunc()->get_image_param_func();
#endif
	return KAL_TRUE;
}


/*************************************************************************
* FUNCTION                                                            
*	usb_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_bool usb_task_reset(task_indx_type task_indx)
{
  	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}



/*************************************************************************
* FUNCTION                                                            
*	usb_task_end
*
* DESCRIPTION
*	This function implements xyz's termination handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_bool usb_task_end(task_indx_type task_indx)
{
  	/* Do task's termination here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_end() will do. */
	return KAL_TRUE;
}



/*************************************************************************
* FUNCTION
*	usb_task_main
*
* DESCRIPTION
*	This function implements xyz task's entry function
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void usb_task_main( task_entry_struct * task_entry_ptr )
{
#ifdef IC_MODULE_TEST
	ilm_struct current_ilm;
	volatile kal_uint32 id;
	
	while(1)
	{
		receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
		id = current_ilm.msg_id;
		free_ilm(&current_ilm);
	}	
#else /* IC_MODULE_TEST */
	ilm_struct current_ilm;
	kal_uint32 my_index;
	drvuem_usbcfg_req_struct *usbcfg;

#ifndef __USB_ENABLE__
	EXT_ASSERT(0, 0, 0, 0);
#endif

	/* for adding module id*/
   	kal_get_my_task_index( &my_index );     
   	stack_set_active_module_id( my_index, MOD_USB);

	gUsbDevice.device_type = USB_UNKOWN;
	g_UsbMS.b_ms_first_plugin = KAL_TRUE;

	/* set external interrupt polarity and register it */
	g_usb_cable_state = gUsbDevice.device_param->cable_plugin_level;
	
#ifdef __OTG_ENABLE__	

#ifndef __USB_IN_NORMAL_MODE__
	/* OTG enable must be with normal mode compile option */
	EXT_ASSERT(0, 0, 0, 0);
#endif

        OTG_VBusControl(KAL_FALSE);

	USB_Init_Mode();
	OTG_Init_A_Plug_Detect();
	
//	gUsbOtg.eint_no = g_usb_eint_no;	
//	eint_sw_debounce_time_delay = custom_config_eint_sw_debounce_time_delay();
//	gUsbOtg.eint_time_delay= eint_sw_debounce_time_delay[g_usb_eint_no];
#endif /* __OTG_ENABLE__ */
	
	if(INT_BootMode() != MTK_FACTORY_MODE)
	{
	#if defined(DRV_USB_IP_V3)
		USB_PDNDisable(USB_PDN_OWNER_USB);
		/* 6318 LDO for D+ */
		/* Only for 6238 E1 version */
		USB_PowerControl(KAL_TRUE);
		DRV_WriteReg32(USB_PHY_CON4, (DRV_Reg32(USB_PHY_CON4)|0x4f00));
		DRV_WriteReg32(USB_PHY_CON5, (DRV_Reg32(USB_PHY_CON5)&~USB_PHY_CON5_FORCE_SUSPENDM));
		DRV_WriteReg32(USB_PHY_CON5, (DRV_Reg32(USB_PHY_CON5)|USB_PHY_CON5_FORCE_IDPULLUP));
		DRV_WriteReg32(USB_PHY_INTF1, (DRV_Reg32(USB_PHY_INTF1)|USB_PHY_INTF1_IDPULLUP));

//		USB_PDNEnable(USB_PDN_OWNER_USB);
	#endif
		pmic_adpt_reg_usb_int(g_usb_cable_state, USB_EINT_HISR);
	}

	/* request for unique string to construct serial string*/
	if(INT_USBBoot() == KAL_FALSE)
	{
		USB_Send_Msg(USB_SEND_MSG_READ_UNIQUE_STRING, 0, KAL_TRUE);
	}
	
	while(1)
	{
		receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

		switch(current_ilm.msg_id)
		{
		case MSG_ID_USB_FT_START_REQ:
			g_UsbMode.mode_param |= USB_MODE_FT_START_DONE;
			#ifdef __OTG_ENABLE__
				OTG_Mode_Selection();
			#else
				USB_Mode_Selection();
			#endif	
			break;
		case MSG_ID_NVRAM_READ_CNF:
			g_UsbMode.mode_param |= USB_MODE_NVRAM_READ_DONE;	
			/* store the string value got from NVRAM */
			USB_Store_Serial_Value(&current_ilm); /* store in gUsbDevice.serial_string   */
			
				#ifdef __OTG_ENABLE__
				OTG_Mode_Selection();
			#else
				USB_Mode_Selection();
			#endif		
			break;
			
		case MSG_ID_BMT_USB_READ_CALI_DONE_IND:
			g_UsbMode.mode_param |= USB_MODE_BMT_READ_DONE;	
			
			#ifdef __OTG_ENABLE__
				OTG_Mode_Selection();
			#else
				USB_Mode_Selection();
			#endif		
			break;

		case MSG_ID_USB_A_PLUGIN_IND:
			#ifdef __OTG_ENABLE__
				if((OTG_Get_Plug_Type()==OTG_PLUG_A)&&(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT))
				{
					g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
					g_UsbMode.cable_type = USB_MODE_CABLE_A_PLUGIN;
					OTG_Mode_Selection();
				}	
			#else
				EXT_ASSERT(0, 0, 0, 0);
			#endif
			break;
			
		case MSG_ID_USB_B_PLUGIN_IND:
			#ifdef __OTG_ENABLE__
				if((OTG_Get_Plug_Type()==OTG_PLUG_B)&&(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT))
				{
					g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
					g_UsbMode.cable_type = USB_MODE_CABLE_B_PLUGIN;
					OTG_Mode_Selection();
					gUsbDevice.usb_cable_in = KAL_TRUE;
				}
			#else
				if(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT)
				{
					g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
					g_UsbMode.cable_type = USB_MODE_CABLE_B_PLUGIN;

					/* Configure USB as CDC ACM at plug in message if this flag as ture*/
					if(gUsbDevice.usb_comport_boot == KAL_TRUE)
					{
				#ifdef __DSPIRDBG__
						if(g_usb_boot_as_irdbg == KAL_TRUE)
							USB_Config_Type(USB_CDC_ACM_IRDBG, KAL_TRUE, NULL);
						else
							USB_Config_Type(USB_CDC_ACM, KAL_TRUE, NULL);
				#else
						USB_Config_Type(USB_CDC_ACM, KAL_TRUE, NULL);
				#endif
					}
					else
					{
						USB_Mode_Selection();
					}
					gUsbDevice.usb_cable_in = KAL_TRUE;
				}
			#endif		
			break;

		case MSG_ID_USB_A_PLUGOUT_IND:
			#ifdef __OTG_ENABLE__	
				if(g_UsbMode.cable_type == USB_MODE_CABLE_A_PLUGIN)
				{
					g_UsbMode.previous_cable_type = USB_MODE_CABLE_A_PLUGIN;
					g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
					OTG_Mode_Selection();
				}		
			#else
				EXT_ASSERT(0, 0, 0, 0);
			#endif
			break;

		case MSG_ID_USB_B_PLUGOUT_IND:
			#ifdef __OTG_ENABLE__	
				if(g_UsbMode.cable_type == USB_MODE_CABLE_B_PLUGIN)
				{
					g_UsbMode.previous_cable_type = USB_MODE_CABLE_B_PLUGIN;
					g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
					OTG_B_Set_Session_Valid(KAL_FALSE);
					OTG_Mode_Selection();
				}	
			#else
				if(g_UsbMode.cable_type == USB_MODE_CABLE_B_PLUGIN)
				{
					g_UsbMode.previous_cable_type = USB_MODE_CABLE_B_PLUGIN;
					g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
					USB_Mode_Selection();
				}
			#endif
			break;

		case MSG_ID_DRVUEM_USBCFG_REQ:
			usbcfg=(drvuem_usbcfg_req_struct *)current_ilm.local_para_ptr;
			#ifdef __OTG_ENABLE__
				#ifdef OTG_NORMAL_APP_FIXED
					/* should not recive this msg*/
					ASSERT(0);
				#endif
				if(g_UsbMode.b_start_hnp==KAL_TRUE)
				{
					OTG_Config_HNP(usbcfg->mode, usbcfg->parameter);
				}
				else if (g_UsbMode.b_start_srp==KAL_TRUE)
				{
					/* For SRP function all the software resource initialization should be configured before SRP,
					    After A device provide VBUS, B device should connect D+ within 1 sec*/
					OTG_Config_SRP(usbcfg->mode, usbcfg->parameter);
				}
				else
				{
					/* config request from MMI*/
					if(g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT)
					{
						USB_Config_Type(usbcfg->mode, KAL_TRUE, usbcfg->parameter);			
						USB_Send_Msg(USB_SEND_MSG_CONFIG_CNF, usbcfg->mode, gUsbDevice.usb_config_result);						
					}
					else
					{
						USB_Send_Msg(USB_SEND_MSG_CONFIG_CNF, usbcfg->mode, KAL_FALSE);
					}
				}
			#else /* __OTG_ENABLE__ */				
				/* config request from MMI*/
				if(g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT)
				{
					//USB_Config_Type(usbcfg->mode, KAL_TRUE, (kal_uint32*)usbcfg->reserved);
					USB_Config_Type(usbcfg->mode, KAL_TRUE, usbcfg->parameter);
					USB_Send_Msg(USB_SEND_MSG_CONFIG_CNF, usbcfg->mode, gUsbDevice.usb_config_result);						
				}
				else
				{
					USB_Send_Msg(USB_SEND_MSG_CONFIG_CNF, usbcfg->mode, KAL_FALSE);
				}
			#endif /* __OTG_ENABLE__ */	
			break;

		case MSG_ID_OTG_HDLR_IND:
			#ifdef __OTG_ENABLE__	
			{
				otg_hdr_ind_struct *hdlr_ind=(otg_hdr_ind_struct *)current_ilm.local_para_ptr;
				OTG_Hdlr_Select(hdlr_ind->type, hdlr_ind->parameter, hdlr_ind->b_param);
			}
			#else
				EXT_ASSERT(0, 0, 0, 0);
			#endif		
			break;

		case MSG_ID_USBD_START_HNP:
			#ifdef __OTG_ENABLE__	
				#ifdef OTG_SRP_HNP_APP_FIXED
					OTG_Config_HNP(USB_MASS_STORAGE, g_USB_Mass_Buffer);
				#else	
					g_UsbMode.b_start_hnp = KAL_TRUE;
					/* Notify UEM*/
					USB_Send_Msg(USB_SEND_MSG_PLUG_IN, 0, KAL_TRUE);
				#endif
			#else
				EXT_ASSERT(0, 0, 0, 0);
			#endif		
			break;

		// add for SRP test, In real case, this should check OTG status first
		case MSG_ID_SRP_INIT:	
			#ifdef __OTG_ENABLE__
				if(	(OTG_Get_Plug_Type()==OTG_PLUG_B) && 
					((OTG_Get_State()==OTG_STATE_START) || (OTG_Get_State()==OTG_STATE_B_IDLE)))
				{
					if(g_UsbMode.b_start_srp==KAL_TRUE)
					{
						/* It means user select to start SRP 
						   but not config function(MS, CDC ACM)*/
						#ifndef OTG_NORMAL_APP_FIXED   
						/* Notify UEM plug out first, otherwise next plug in will make MMI assert */
						USB_Send_Msg(USB_SEND_MSG_PLUG_OUT, 0, KAL_TRUE);	
						#endif
					}
			
					OTG_Start_SRP();

				#ifdef OTG_SRP_HNP_APP_FIXED
					OTG_Config_SRP(USB_MASS_STORAGE, g_USB_Mass_Buffer);
				#else	
					/* Notify UEM*/
					USB_Send_Msg(USB_SEND_MSG_PLUG_IN, 0, KAL_TRUE);
				#endif
				}
			#else
				EXT_ASSERT(0, 0, 0, 0);
			#endif	
			break;
		
		/* mass storage client messages */	
		case MSG_ID_USB_MSDRV_REC_DONE_CONF:
		case MSG_ID_USB_MSDRV_TRX_DONE_CONF:
		case MSG_ID_USB_MSDRV_CLEAR_STALL_REQ:
			/* After USB_reset HISR and before stop DMA, a DMA callbcak happen, 
			this callback message may come after reset message, and make MS state machine error */
			if (gUsbDevice.nDevState != DEVSTATE_CONFIG)
				break;
				
		case MSG_ID_USB_MSDRV_RESET_IND:
			if (gUsbDevice.device_type == USB_MASS_STORAGE)
			{
				USB_Ms_State_Main(&current_ilm);
			}
			else if (gUsbDevice.device_type != USB_UNKOWN) /* be configured as MS_STOP mode */
			{
				EXT_ASSERT(0, gUsbDevice.device_type, 0, 0);
			}	
			break;	
			
		/* mass storage host messages */	
		case MSG_ID_USB_MSHOST_START_IND:
			#ifdef __OTG_ENABLE__
				USB_Host_Ms_State_Start();
			#else
				EXT_ASSERT(0, 0, 0, 0);
			#endif	
			break;
		case MSG_ID_USB_MSHOST_QUERY_IND:
			#ifdef __OTG_ENABLE__
				USB_Host_Ms_State_Main();
			#else
				EXT_ASSERT(0, 0, 0, 0);
			#endif	
			break;	
			
	#ifdef WEBCAM_SUPPORT
		/* video class related messages */			
		case MSG_ID_USB_MED_SET_CAMERA_ATTR_CNF:	
		case MSG_ID_USB_ENUM_DONE:
		case MSG_ID_MED_USB_START_VIDEO_REQ:
		case MSG_ID_USB_VIDEO_COMPLETE:
		case MSG_ID_USB_VIDEO_DMA_DONE:
		case MSG_ID_USB_VIDEO_CHANGE_SIZE:	
		case MSG_ID_USB_STILL_CAPTURE:	
		case MSG_ID_USB_STILL_COMPLETE:
		case MSG_ID_USB_VIDEO_STILL_DMA_DONE:
		case MSG_ID_USB_VIDEO_STILL_DMA_PARTIAL:	
		case MSG_ID_MED_USB_DEVICE_STILL_REQ:	
		case MSG_ID_MED_USB_PAUSE_REQ:	
		case MSG_ID_USB_VIDEO_INCALL_DMA_DONE:
		case MSG_ID_USB_VIDEO_INCALL_TIMEOUT:	
		case MSG_ID_USB_VIDEO_INCALL_CHANGE_SIZE:
		case MSG_ID_MED_USB_RESUME_VIDEO_REQ:	
			/* If device type is no longer video because of plugging out cable, still return error message to media task*/
			USBVideo_Parse_Med_Msg(&current_ilm, gUsbDevice.device_type);
			break;	
		case MSG_ID_USB_VIDEO_ABORT:	/* OS sleep and then wakeup, reset USB, called at USBVideo_VS_If_Reset() */ 
		case MSG_ID_MED_USB_STOP_REQ:	 /*  media task want to stop webcam */
			if(gUsbDevice.device_type == USB_VIDEO)  /* USB cable does not be plugged out */
			{
				USB_Release_Type(KAL_TRUE, KAL_FALSE);		/* disable D+ pull high, but plug out is false */
			}	
			/* In order to return corresponding error message to media task */
			USBVideo_Parse_Med_Msg(&current_ilm, gUsbDevice.device_type);/*device type as UNKNOWN */
			break;
	#endif /* WEBCAM_SUPPORT */	

	#ifdef PICTBRIDGE_SUPPORT
		case MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF:
		case MSG_ID_USB_PTPIMAGE_DMA_TX_DONE_CONF:
			if (gUsbDevice.nDevState != DEVSTATE_CONFIG)
				break;
				
		case MSG_ID_USB_PTPIMAGE_RESET_IND:
			if((gUsbDevice.device_type == USB_IMAGE)||(gUsbDevice.device_type == USB_UNKOWN))
			{
				/* When USB cable is plugged out and then plugged in quickly, 
					the reset interrupt may issue because USB task does not handle plug out msg yet, so GPIO(D+) is still high */
				PTP_Parse_USB_Meg(&current_ilm);
			}
			else
			{
				EXT_ASSERT(0, gUsbDevice.device_type, 0, 0);
			}
			break;

		case MSG_ID_MMI_USB_DPS_HREQUEST_CONF:
		case MSG_ID_MMI_USB_DPS_HRESPONSE_CONF:
		case MSG_ID_MMI_USB_DPS_DREQUEST_REQ:
		case MSG_ID_MMI_USB_DPS_DRESPONSE_REQ:
		case MSG_ID_MMI_USB_START_JOB_REQ:
		case MSG_ID_MMI_USB_CLOSE_JOB_REQ:
			if((gUsbDevice.nDevState != DEVSTATE_CONFIG)||(g_USBImage.ptp_stop == KAL_TRUE))
				break;

			if (gUsbDevice.device_type == USB_IMAGE)
			{
				PTP_Parse_MMI_Meg(&current_ilm);
			}
			else
			{
				EXT_ASSERT(0, gUsbDevice.device_type, 0, 0);
			}
			break;
		
		case MSG_ID_MMI_USB_PTP_HOST_RESET_CNF:
			if((gUsbDevice.device_type == USB_IMAGE)||(gUsbDevice.device_type == USB_UNKOWN))
			{
				PTP_Parse_MMI_Meg(&current_ilm);
			}
			else
			{
				EXT_ASSERT(0, gUsbDevice.device_type, 0, 0);
			}
			break;

	#endif /* PICTBRIDGE_SUPPORT */
	#ifdef __DSPIRDBG__
		case MSG_ID_USB_IRDGB_START_IND:
			USB_DSPIRDBG_Start();
			break;
	#endif /* __DSPIRDBG__*/
		default:
			EXT_ASSERT(0, current_ilm.msg_id, 0, 0);	
			break;
		}
		free_ilm(&current_ilm);
	}
#endif /* IC_MODULE_TEST */
}



/************************************************************
	serial string  functions
*************************************************************/

/*store unique data to serial string*/
/*this function is used for normal mode, NVRAM task respondes the string by message*/
static void USB_Store_Serial_Value(ilm_struct *ilm_ptr)
{
	kal_uint16     len;
	nvram_read_cnf_struct *parm_ptr = (nvram_read_cnf_struct *) ilm_ptr->local_para_ptr;
	kal_uint8 *pdu_ptr = get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len);

	if( (parm_ptr->result == NVRAM_IO_ERRNO_OK) || (parm_ptr->result ==NVRAM_IO_ERRNO_INIT) )
	{
		//construct serial string
		USB_Constrct_Serial_String(pdu_ptr, len);
	}
	else
	{
		ASSERT(0);
	}
}
			
/*get and store unique data to serial string*/
/*this function is used for mass storage mode because NAVRAM task not created in mass storage mode*/
void USB_Get_Serial_Value(void)
{
	kal_uint8 *serial_buf;
	kal_uint16 record, size;

	if(nvram_get_info(UNI_ID, &record, &size)!=NVRAM_ERRNO_SUCCESS)
		EXT_ASSERT(0, 0, 0, 0);

	serial_buf = get_ctrl_buffer(size);

	/* read unique string data from NVRAM, and construct USB serial string before init mass sotrage*/
	if( nvram_usb_read_data(UNI_ID, serial_buf, size) == KAL_TRUE )
	{
		USB_Constrct_Serial_String(serial_buf, size);
	}
	else
	{
		ASSERT(0);
	}

	free_ctrl_buffer(serial_buf);
}

/* convert from val to string type (ascii code)*/
static kal_uint16 USB_Convert_String(kal_uint8 val)
{
	kal_uint16 ret;
	
	if(val>0xf)
		ASSERT(0);

	/* convert to a-f ascii code*/
	if(val>=0xa)
		ret = val - 0xa + 0x61;
	/* convert to 0-9 ascii code*/
	else
		ret = val + 0x30;

	return ret;
		
}

/* convert from unique charaters to serial string for USB*/
static void USB_Constrct_Serial_String(kal_uint8 *pdu_ptr, kal_uint16 len)
{
	kal_uint32 i;
	kal_uint32 serial_len;

	if(len==0)
		ASSERT(0);

	/* length must be even */
	if((USB_SERIAL_STRING_LEN&0x1)!=0)
		EXT_ASSERT(0, USB_SERIAL_STRING_LEN, 0, 0);
		
	serial_len = (len< (USB_SERIAL_STRING_LEN>>1)) ? len:(USB_SERIAL_STRING_LEN>>1);

	/* string type and length*/
	gUsbDevice.serial_string[0] = 0x0320;

	/* conver from pdu_ptr to USB serial string*/
	for(i=0; i<(serial_len-1); i++)
	{
		gUsbDevice.serial_string[(i<<1)+1] = USB_Convert_String((pdu_ptr[i]&0xf0)>>4);
		gUsbDevice.serial_string[(i<<1)+2] = USB_Convert_String(pdu_ptr[i]&0xf);
	}
	gUsbDevice.serial_string[((serial_len-1)<<1)+1] = USB_Convert_String((pdu_ptr[(serial_len-1)]&0xf0)>>4);
}


/************************************************************
	cable and message uitility  functions
*************************************************************/

/* send message to other tasks*/
void USB_Send_Msg(USB_SEND_MSG_TYPE msg_type, kal_uint8 mode, kal_bool result)
{
	drvuem_usbdetect_ind_struct *usbdetect_req;
	uart_plugout_ind_struct *uart_plug_out_ind;
	local_para_struct *local_ptr = NULL;
	ilm_struct *USB_ilm;
	drvuem_usbcfg_cnf_struct *USB_Prim;
	kal_uint16 record, size;
	module_type 	src_mod;

	if(kal_if_hisr() == KAL_TRUE)
		src_mod = MOD_DRV_HISR;
	else
		src_mod = MOD_USB;


	if(msg_type == USB_SEND_MSG_PLUG_IN)
	{
		/*Notify UEM*/ 
		/* for USB_UNKOWN, show selection screen*/
		/* for USB_MASS_STORAGE, UEM latch power*/
#ifndef __L1_STANDALONE__
		usbdetect_req = (drvuem_usbdetect_ind_struct*)construct_local_para(
							sizeof(drvuem_usbdetect_ind_struct), TD_CTRL);
		usbdetect_req->action = DETECT_ACTION_PLUGIN;
		DRV_BuildPrimitive(USB_ilm,
						MOD_USB,
						MOD_UEM,
						MSG_ID_DRVUEM_USBDETECT_IND,
						usbdetect_req);

		msg_send_ext_queue(USB_ilm);
#endif
	}
	else if(msg_type == USB_SEND_MSG_PLUG_OUT)
	{
		/*Notify UEM cable plug out*/
#ifndef __L1_STANDALONE__
		usbdetect_req = (drvuem_usbdetect_ind_struct*)construct_local_para(
						sizeof(drvuem_usbdetect_ind_struct), TD_CTRL);
		usbdetect_req->action = DETECT_ACTION_PLUGOUT;
		DRV_BuildPrimitive(USB_ilm,
						MOD_USB,
						MOD_UEM,
						MSG_ID_DRVUEM_USBDETECT_IND,
						usbdetect_req);
		msg_send_ext_queue(USB_ilm);
#endif
	}
	else if(msg_type == USB_SEND_MSG_UART_PLUG_OUT)
	{
		/* Notify UART owner plug out*/
		uart_plug_out_ind = (uart_plugout_ind_struct*)construct_local_para(sizeof(uart_plugout_ind_struct), TD_CTRL);
		uart_plug_out_ind->port = USB2UARTPort.port_no;
		DRV_BuildPrimitive(USB_ilm,
						src_mod,
						USB2UARTPort.ownerid,
						MSG_ID_UART_PLUGOUT_IND,
						uart_plug_out_ind);
		msg_send_ext_queue(USB_ilm);
	}
	else if(msg_type == USB_SEND_MSG_READ_UNIQUE_STRING)
	{
		/* Send msg to NVRAM, read serial string data*/
		if(nvram_get_info(UNI_ID, &record, &size)!=NVRAM_ERRNO_SUCCESS)
			ASSERT(0);
		
		local_ptr = construct_local_para(size, TD_CTRL);

		((nvram_read_req_struct *)local_ptr)->file_idx = UNI_ID;
		((nvram_read_req_struct *)local_ptr)->para = NVRAM_SYS_AUTO_DETECT;

		DRV_BuildPrimitive(USB_ilm,
						MOD_USB,
						MOD_NVRAM,
						MSG_ID_NVRAM_READ_REQ,
						local_ptr);
		msg_send_ext_queue(USB_ilm);
	}
        else if(msg_type == USB_SEND_MSG_CONFIG_CNF) 
	{
		/*Notify UEM*/
		USB_Prim = (drvuem_usbcfg_cnf_struct*)
					construct_local_para(sizeof(drvuem_usbcfg_cnf_struct), TD_CTRL);
		USB_Prim->mode= mode;
		USB_Prim->result= result;

		DRV_BuildPrimitive(USB_ilm,
						MOD_USB,
						MOD_UEM,
						MSG_ID_DRVUEM_USBCFG_CNF,
						USB_Prim);
		msg_send_ext_queue(USB_ilm);
	}
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
#endif	
	else
	{
		ASSERT(0);
	}
}

/* add for usb charging, check the cable status */
kal_bool USB_GetCableStatus(void)
{	
	return (g_usb_cable_state!=gUsbDevice.device_param->cable_plugin_level)?(KAL_TRUE):(KAL_FALSE);
}

/* external interrupt HISR */
void USB_EINT_HISR(void)
{
#ifndef __USB_ENABLE__
	ASSERT(0);
#endif

	ilm_struct *usb_hisr_ilm;

//	USB_Ms_Dbg_Trace(USB_DBG_EINT_HISR,g_usb_cable_state);
	
//#ifdef __OTG_ENABLE__
//	#ifndef _USB_VBUS_DETECT_WITH_NIRQ_
//		/* NIRQ not modify the debounce time */
//		EINT_SW_Debounce_Modify(g_usb_eint_no, gUsbOtg.eint_time_delay);
//	#endif
//#endif

	if (g_usb_cable_state!= gUsbDevice.device_param->cable_plugin_level) /*Must modify for different level, plug out*/
	{
		USB_Dbg_Trace(USB_DBG_CABLE_PLUG_OUT, drv_get_current_time(), 0, 0);
		gUsbDevice.usb_cable_in = KAL_FALSE;

		DRV_BuildPrimitive(usb_hisr_ilm,
						MOD_EINT_HISR,
						MOD_USB,
						MSG_ID_USB_B_PLUGOUT_IND,
						NULL);
		msg_send_ext_queue(usb_hisr_ilm);				
						
		#ifdef MT6318
		DRV_BuildPrimitive(usb_hisr_ilm,
						MOD_EINT_HISR,
						MOD_BMT,
						MSG_ID_USB_B_PLUGOUT_IND,
						NULL);
		msg_send_ext_queue(usb_hisr_ilm);				
      		#elif (!defined(MT6305))
      		/* On EVB board, there may be no PMIC. */
      		{
         		BMT_sendMes2UEM(BMT_USB_NO_CHARGING_OUT);
      		}
		#endif	/* MT6318*/			
	}
	else  /* first time USB cable plug in  */
	{
		USB_Dbg_Trace(USB_DBG_CABLE_PLUG_IN, drv_get_current_time(), 0, 0);

#ifdef __OTG_ENABLE__	
		if(gUsbOtg.b_check_srp == KAL_TRUE)
		{
			OTG_B_Set_Session_Valid(KAL_TRUE);
		}
#endif

#ifdef __USB_AND_UART_WITH_ONE_GPIO__
		/* We must call this function in USB_EINT_HISR() in the case that USB and UART with one GPIO */
		USB_Switch_Gpio_to_USB_And_PowerControl(KAL_FALSE);
#endif

		DRV_BuildPrimitive(usb_hisr_ilm,
						MOD_EINT_HISR,
						MOD_USB,
						MSG_ID_USB_B_PLUGIN_IND,
						NULL);
		msg_send_ext_queue(usb_hisr_ilm);
		
		#ifdef MT6318
		DRV_BuildPrimitive(usb_hisr_ilm,
						MOD_EINT_HISR,
						MOD_BMT,
						MSG_ID_USB_B_PLUGIN_IND,
						NULL);
		msg_send_ext_queue(usb_hisr_ilm);				
      		#elif (!defined(MT6305))
      		/* On EVB board, there may be no PMIC. */
      		{
         		BMT_sendMes2UEM(BMT_USB_NO_CHARGING_IN);
      		}
		#endif	/* MT6318*/			
	}

	g_usb_cable_state = !g_usb_cable_state;

	/* for charger USB, charger will handle this part */	
	#if !defined(MT6318) && !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(_USB_VBUS_DETECT_WITH_NIRQ_)
	EINT_Set_Polarity(g_usb_eint_no,g_usb_cable_state);
	#endif /* MT6318*/
}

