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
 *    usb_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb hardware related functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
#include "reg_base.h"
  
#include "drvpdn.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "gpio_sw.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "upll_ctrl.h"

#include "usb_hw.h"
#include "usb_drv.h"
#include "usb_drv_pri.h"
#include "usb_custom.h"

#include "otg_drv.h"
#include "usb_debug_tool.h"

#ifdef _USB_VBUS_DETECT_WITH_NIRQ_
#include "isrentry.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "gpt_sw.h"
#endif

/* usb pdn owner */
static kal_uint8 g_usb_pdn_owner = 0;

#ifdef DCM_ENABLE
/*DCM control*/
extern kal_uint8 DCM_GetHandle(void);
extern void DCM_Disable(kal_uint8 handle);	
extern void DCM_Enable(kal_uint8 handle);
/* DCM default handle */
static kal_uint8 g_usb_dcm_handle = 255;
#endif

#ifdef __USB_ENABLE__

/* Exception flag*/
extern kal_uint8 INT_Exception_Enter;

/* usb driver information*/
static USB_Drv_Info g_UsbDrvInfo;

#if defined(DRV_USB_IP_V3)
/* EP0's FIFO address is fixed from 0~63 */
static kal_uint32 g_FIFOadd = USB_FIFO_START_ADDRESS;


/* static functions*/
static kal_uint8 USB_Get_DMA_Channel_Num(kal_uint8 ep_num, USB_EP_TYPE direction);
static void USBDMA_HISR(void);
static void USBDMA_LISR(void);
static void USB_DMA_Callback(kal_uint8 dma_chan);
static void USB_Enable_DMA_Timer_Count(kal_uint8 dma_chan, kal_bool  enable);
static void USB_High_Speed_Enable(void);
static void USB_Set_DP_Pull_Up(kal_bool bset);
#if  0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#else
/* static functions*/
static void USB_DMA_Callback_EP1(void);
	#ifdef USB_SUPPORT_MUTIPLE_APP
static void USB_DMA_Callback_EP2(void);
	#endif /*  USB_SUPPORT_MUTIPLE_APP */
#endif


#ifndef __OTG_ENABLE__
/* interrupt handler */
static void USB_LISR(void);
#endif

static void USB_EnSysIntr(void);
/* resume device */
static void USB_Drv_Resume(void);
/* suspend device */
static void USB_Drv_Suspend(void);



#ifdef _USB_VBUS_DETECT_WITH_NIRQ_
static void USB_NIRQ_Timer_Callback(void *data);
static void USB_NIRQ_HISR(void);
#endif

/************************************************************
	driver info functions
*************************************************************/

/* initialize usb driver information, called at USB_Init() */
void USB_Init_Drv_Info(void)
{
	kal_uint32 index;
	
	g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
	g_UsbDrvInfo.is_unMaskUSB = KAL_TRUE;
	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;
	g_UsbDrvInfo.reset_hdlr = NULL;
	g_UsbDrvInfo.ep0_hdlr = NULL;

	for(index=0; index< MAX_INTR_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_tx_hdlr[index] = NULL;
		g_UsbDrvInfo.ep_rx_hdlr[index] = NULL;
		g_UsbDrvInfo.ep_tx_stall_status[index] = KAL_FALSE;
		g_UsbDrvInfo.ep_rx_stall_status[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V3)
		g_UsbDrvInfo.dma_port[USB_TX_EP_TYPE][index] = 0;
		g_UsbDrvInfo.dma_port[USB_RX_EP_TYPE][index] = 0;
#endif
	}

	for(index=0; index<MAX_DMA_EP_NUM; index++)
	{
#if defined(DRV_USB_IP_V3)
		g_UsbDrvInfo.dma_pktrdy[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_running[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback_upd_run[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_ep_num[index] = 0;
//		g_UsbDrvInfo.dma_is_pp[index] = KAL_FALSE;
//		g_UsbDrvInfo.dma_is_running[0][index] = KAL_FALSE; 
//		g_UsbDrvInfo.dma_is_running[1][index] = KAL_FALSE; 
#else
		g_UsbDrvInfo.dma_port[index] = 0;
		g_UsbDrvInfo.dma_pktrdy[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_running[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback_upd_run[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V2)
		g_UsbDrvInfo.dma_pktlength[index] = 0;
#endif
#endif
	}

#if defined(DRV_USB_IP_V2)
	/* dma and fast mode sequence parametes */
	g_UsbDrvInfo.dma_tx_ep = 0;
	g_UsbDrvInfo.dma_res_tx_ep = 0;
	g_UsbDrvInfo.fast_mode_tx_ep = 0;

	/* Error record */
	g_UsbDrvInfo.error_count = 0;
	g_UsbDrvInfo.error_reason = 0;
	g_UsbDrvInfo.fm_error_reason = 0;

	/* BDT */
	WRITE_EP0_BDT(USB_BDT_RX, USB_BDT_EVEN, (USB_BDT_PTR)USB_BDT_RX0_EVEN);
	WRITE_EP0_BDT(USB_BDT_RX, USB_BDT_ODD, (USB_BDT_PTR)USB_BDT_RX0_ODD);
	WRITE_EP0_BDT(USB_BDT_TX, USB_BDT_EVEN, (USB_BDT_PTR)USB_BDT_TX0_EVEN);
	WRITE_EP0_BDT(USB_BDT_TX, USB_BDT_ODD, (USB_BDT_PTR)USB_BDT_TX0_ODD);
	WRITE_EPN_BDT(1, USB_BDT_RX, (USB_BDT_PTR)USB_BDT_RX1);
	WRITE_EPN_BDT(1, USB_BDT_TX, (USB_BDT_PTR)USB_BDT_TX1);
	WRITE_EPN_BDT(2, USB_BDT_RX, (USB_BDT_PTR)USB_BDT_RX2);
	WRITE_EPN_BDT(2, USB_BDT_TX, (USB_BDT_PTR)USB_BDT_TX2);
	WRITE_EPN_BDT(3, USB_BDT_RX, (USB_BDT_PTR)USB_BDT_RX3);
	WRITE_EPN_BDT(3, USB_BDT_TX, (USB_BDT_PTR)USB_BDT_TX3);

	/* EP0 parametes */
	g_UsbDrvInfo.ep0_rx_even_odd = 0;
	g_UsbDrvInfo.ep0_tx_even_odd = 0;
	g_UsbDrvInfo.ep0_current_dir = 0;
	g_UsbDrvInfo.ep0_tx_data01 = 0;
	g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;

	/* EPn parametes */
	for(index=0; index< MAX_INTR_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_in_enb_state[index] = USB_EP_DIS;
		g_UsbDrvInfo.ep_out_enb_state[index] = USB_EP_DIS;
		g_UsbDrvInfo.ep_in_max_data_size[index] = 0;
		g_UsbDrvInfo.ep_out_max_data_size[index] = 0;
		g_UsbDrvInfo.ep_in_data01[index] = 0;
		g_UsbDrvInfo.ep_out_data01[index] = 0;
	}
#endif	
}

void USB_ResetDrv_Info(void)
{
	kal_uint32 index;
#if !defined(DRV_USB_IP_V3)
	kal_uint32 savedMask;
#endif
	
	g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
	g_UsbDrvInfo.is_unMaskUSB = KAL_TRUE;
	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;

	for(index=0; index< MAX_INTR_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_tx_stall_status[index] = KAL_FALSE;
		g_UsbDrvInfo.ep_rx_stall_status[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V3)
		USBDMA_Stop(index+1);
//		USBDMA_PPStop(index+1);
#endif
	}

#if defined(DRV_USB_IP_V3)
	//clear interrupt. write 0 clear
	DRV_WriteReg32(USB_DMAINTR, 0x00);
#endif

	for(index=0; index<MAX_DMA_EP_NUM; index++)
	{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V2))
		if(g_UsbDrvInfo.dma_port[index]!=0)
		{
			if (DMA_CheckRunStat(g_UsbDrvInfo.dma_port[index]))
			{
				DMA_Stop(g_UsbDrvInfo.dma_port[index]);
			}
	
			savedMask = SaveAndSetIRQMask();
			if (DMA_CheckITStat(g_UsbDrvInfo.dma_port[index]))  /* check if interrupt is pending and waiting for service */
			{	
				DMA_ACKI(g_UsbDrvInfo.dma_port[index]);
				IRQClearInt(IRQ_DMA_CODE);
			}
			RestoreIRQMask(savedMask);	
		}	
#endif

#if defined(DRV_USB_IP_V3)
		g_UsbDrvInfo.dma_pktrdy[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_running[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback_upd_run[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback[index] = KAL_FALSE;
//		g_UsbDrvInfo.dma_is_pp[index] = KAL_FALSE;
//		g_UsbDrvInfo.dma_is_running[0][index] = KAL_FALSE;
//		g_UsbDrvInfo.dma_is_running[1][index] = KAL_FALSE;
#else
		g_UsbDrvInfo.dma_pktrdy[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_running[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback_upd_run[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V2)
		g_UsbDrvInfo.dma_pktlength[index] = 0;
#endif
#endif
	}

#if defined(DRV_USB_IP_V2)
	/* dma and fast mode sequence parametes */
	g_UsbDrvInfo.dma_tx_ep = 0;
	g_UsbDrvInfo.dma_res_tx_ep = 0;
	g_UsbDrvInfo.fast_mode_tx_ep = 0;

	/* Error record */
	g_UsbDrvInfo.error_count = 0;
	g_UsbDrvInfo.error_reason = 0;
	g_UsbDrvInfo.fm_error_reason = 0;

	/* EP0 parametes */
	g_UsbDrvInfo.ep0_rx_even_odd = 0;
	g_UsbDrvInfo.ep0_tx_even_odd = 0;
	g_UsbDrvInfo.ep0_current_dir = 0;
	g_UsbDrvInfo.ep0_tx_data01 = 0;
	g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;

	/* EPn parametes */
	for(index=0; index< MAX_INTR_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_in_enb_state[index] = USB_EP_DIS;
		g_UsbDrvInfo.ep_out_enb_state[index] = USB_EP_DIS;
		g_UsbDrvInfo.ep_in_max_data_size[index] = 0;
		g_UsbDrvInfo.ep_out_max_data_size[index] = 0;
		g_UsbDrvInfo.ep_in_data01[index] = 0;
		g_UsbDrvInfo.ep_out_data01[index] = 0;
	}	
#endif	
}

/* register interrupt handler*/
void USB_Register_Drv_Info(USB_DRV_HDLR_TYPE type, kal_uint32 ep_num, usb_drv_intr_handler_ptr hdlr)
{
	if(ep_num > MAX_INTR_EP_NUM)
		EXT_ASSERT(0, ep_num, MAX_INTR_EP_NUM, 0);
	
	switch(type)
	{
	case USB_DRV_HDLR_RESET:
		g_UsbDrvInfo.reset_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_SUSPEND:
		g_UsbDrvInfo.suspend_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_RESUME:
		g_UsbDrvInfo.resume_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_EP0:
		g_UsbDrvInfo.ep0_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_EP_TX:
		g_UsbDrvInfo.ep_tx_hdlr[ep_num-1]= hdlr;
		break;
	case USB_DRV_HDLR_EP_RX:
		g_UsbDrvInfo.ep_rx_hdlr[ep_num-1]= hdlr;
		break;	
	}
}

kal_uint32 USB_Get_HW_Error_Count(void)
{
#if defined(DRV_USB_IP_V3)
	return 0;
#elif defined(DRV_USB_IP_V2)
	return g_UsbDrvInfo.error_count;
#elif defined(DRV_USB_IP_V1)
	return 0;
#endif
}


/* set unmask variable to control if unmask USB interruput when leaving USB HISR*/
void USB_Set_UnMask_Irq(kal_bool set)
{
	g_UsbDrvInfo.is_unMaskUSB = set;
}

/* get the irq status */
kal_bool USB_Get_UnMask_Irq(void)
{
	return g_UsbDrvInfo.is_unMaskUSB;
}

/* get variable about if USB HISR has chance to execute at the current time */
kal_bool USB_Get_Pro_USB_HISR(void)
{
	return g_UsbDrvInfo.is_ProUSBHISR;
}

/* get stall status for endpoint */
kal_bool USB_Get_EP_Stall_Status(kal_uint8 ep_num, USB_EP_TYPE direction)
{
	if(ep_num > MAX_INTR_EP_NUM)
		EXT_ASSERT(0, ep_num, MAX_INTR_EP_NUM, 0);
	
	if(direction == USB_TX_EP_TYPE)
	{
		return g_UsbDrvInfo.ep_tx_stall_status[ep_num-1];
	}
	else
	{
		return g_UsbDrvInfo.ep_rx_stall_status[ep_num-1];
	}
}

/* if __OTG_ENABLE__, only activate OTG ISR*/
#ifndef __OTG_ENABLE__

void USB_Drv_Create_ISR(void)
{
	IRQ_Register_LISR(IRQ_USB_CODE, USB_LISR,"USB");
	DRV_Register_HISR(DRV_USB_HISR_ID, USB_HISR);
}

/* acivate USB interrput (LISR and HISR) */
void USB_Drv_Activate_ISR(void)
{
	IRQSensitivity(IRQ_USB_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_USB_CODE);
}
#endif

#if defined(DRV_USB_IP_V3)

void USBDMA_Drv_Create_ISR(void)
{
	IRQ_Register_LISR(IRQ_USBDMA_CODE, USBDMA_LISR, "USBDMA");
	DRV_Register_HISR(DRV_USBDMA_HISR_ID, USBDMA_HISR);
}

/* activate DMA interrput (LISR and HISR) */
void USBDMA_Drv_Activate_ISR(void)
{
	IRQSensitivity(IRQ_USBDMA_CODE, LEVEL_SENSITIVE);
	IRQUnmask(IRQ_USBDMA_CODE);
}

#endif

/************************************************************
	system ctrl functions
*************************************************************/

/* control usb power, pdn_en KAL_TRUE means power off */
void USB_PDNmode(kal_bool pdn_en)
{
	volatile kal_uint32 delay;
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V3))
	kal_uint16  IntrStatus;
#endif

	if(pdn_en)
	{
		/* power down */
		IRQMask(IRQ_USB_CODE);
#if defined(DRV_USB_IP_V3)
		IRQMask(IRQ_USBDMA_CODE);

		/* disable sequence:1. GPIO(D+), 2. USB(USB register), 3. PDN_USB(USB power), 4. UPLL */
		USB_Set_DP_Pull_Up(KAL_FALSE);
#else
		USB_PowerControl(KAL_FALSE);
#endif

#if defined(DRV_USB_IP_V2)
		DRV_WriteReg8(USB_CTL, 0);
		DRV_WriteReg8(USB_INT_ENB, 0);
		DRV_WriteReg8(OTG_INT_EN, 0);
		DRV_WriteReg8(USB_SOFT_RST, VUSB_SOFT_RST_EN);
		for(delay=0;delay<10;delay++);	/* wait for stable*/
#elif defined(DRV_USB_IP_V1)
		DRV_WriteReg8(USB_ENABLE, USB_ENABLE_DIS);
#endif
		USB_PDNEnable(USB_PDN_OWNER_USB);
		UPLL_Disable(UPLL_OWNER_USB);
#ifdef DCM_ENABLE
		/* Prevent from USB cable have been plugged out before configuring any USB type */
		if(g_usb_dcm_handle != 255)
		{
			DCM_Enable(g_usb_dcm_handle);
		}
#endif
	}
	else
	{
#ifdef DCM_ENABLE
		if(g_usb_dcm_handle == 255)
			g_usb_dcm_handle = DCM_GetHandle();
		if(g_usb_dcm_handle == 255)
			EXT_ASSERT(0, g_usb_dcm_handle, 0, 0);	
		DCM_Disable(g_usb_dcm_handle);
#endif		
		/* Enable sequence: 1. UPLL, 2.PDN_USB(USB power), 3.USB(USB register), 4.GPIO(D+) */
		UPLL_Enable(UPLL_OWNER_USB);
		for(delay = 0; delay < 500; delay++) ; /* wait for power stable */
		USB_PDNDisable(USB_PDN_OWNER_USB);

#if defined(DRV_USB_IP_V3)
//		USB_PowerControl(KAL_TRUE);
		DRV_WriteReg(USB_PHY_CON1, DRV_Reg(USB_PHY_CON1)|USB_PHY_CON1_PLL_EN);

		IntrStatus = DRV_Reg8(USB_INTRUSB);
		IntrStatus = DRV_Reg(USB_INTRTX);
		// write 0 clear
		DRV_WriteReg(USB_INTRRX, 0);
		IntrStatus = DRV_Reg(USB_DEVCTL);
#elif defined(DRV_USB_IP_V1)
		// clear interrupt before previous power down PDN, the interrupts are read then clear
		IntrStatus = DRV_Reg8(USB_INTRUSB);
		IntrStatus = DRV_Reg8(USB_INTRIN1);
		IntrStatus = DRV_Reg8(USB_INTROUT1);

		DRV_WriteReg8(USB_ENABLE, USB_ENABLE_EN);
#endif

#if defined(DRV_USB_IP_V3)
		USB_High_Speed_Enable();
		USB_Set_DP_Pull_Up(KAL_TRUE);
#else
		/*  turn on D+ power, or pull up GPIO */
		USB_PowerControl(KAL_TRUE);
#endif
	}
}

/* reset hw power*/
void USB_Reset_Drv(void)
{
#if defined(DRV_USB_IP_V3)
	/* Enable software reset, USB IP only can be reset by SW when detecting reset signal from bus */
	DRV_WriteReg(USB_SWRST, USB_SWRST_DISUSBRESET);
	DRV_WriteReg8(USB_RSTINFO, 0xA6);
	/* Because softconn has be decided to set or not */
	DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)|USB_POWER_ISOUPDATE|USB_POWER_ENABLESUSPENDM));
//	DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)|USB_POWER_ISOUPDATE));
#elif defined(DRV_USB_IP_V2)
	WRITE_EP0_BDT_ADDR(USB_BDT_RX, USB_BDT_EVEN, USB_FIFO_RX0_EVEN);
	WRITE_EP0_BDT_ADDR(USB_BDT_RX, USB_BDT_ODD, USB_FIFO_RX0_ODD);
	WRITE_EP0_BDT_ADDR(USB_BDT_TX, USB_BDT_EVEN, USB_FIFO_TX0_ODD);
	WRITE_EP0_BDT_ADDR(USB_BDT_TX, USB_BDT_ODD, USB_FIFO_TX0_ODD);
	WRITE_EPN_BDT_ADDR(1, USB_BDT_RX, USB_FIFO_RX1);
	WRITE_EPN_BDT_ADDR(1, USB_BDT_TX, USB_FIFO_TX1);
	WRITE_EPN_BDT_ADDR(2, USB_BDT_RX, USB_FIFO_RX2);
	WRITE_EPN_BDT_ADDR(2, USB_BDT_TX, USB_FIFO_TX2);
	WRITE_EPN_BDT_ADDR(3, USB_BDT_RX, USB_FIFO_RX3);
	WRITE_EPN_BDT_ADDR(3, USB_BDT_TX, USB_FIFO_TX3);
	
	DRV_WriteReg8(USB_CTL, 0);
	DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(1), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(2), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(3), VUSB_ENDPT_DISABLE);

#elif defined(DRV_USB_IP_V1)
	/* enable software reset, USB IP only can be reset by SW when detecting reset signal from bus */
	DRV_WriteReg8(USB_POWER, USB_POWER_SETSUSPEND|USB_POWER_SWRSTENAB);
#endif
}

/* initialize drv registers, including system global interrupt and EP0 interrupt*/
void USB_Initialize_Drv(void)
{
#if defined(DRV_USB_IP_V3)
	/* software reset */
	DRV_WriteReg(USB_SWRST, (USB_SWRST_DISUSBRESET|USB_SWRST_SWRST));
	/* enable system interrupts, but disable all ep interrupts */
	USB_EnSysIntr();
	DRV_WriteReg8(USB_INDEX, 0);
	/* flush ep0 FIFO */
	DRV_WriteReg(USB_CSR0, USB_CSR0_FLUSHFIFO);
	/* enable EP0 interrupt */
	USB_EP0En();
#elif defined(DRV_USB_IP_V2)
	kal_uint32 index;

	/*  
	This hardware has special hardware token done of 4 bytes deep FIFO
	Clear the status FIFOs
	*/
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);

	/* FIFO deep 4*/
	DRV_WriteReg8(USB_FM_ERR_STAT, VUSB_FM_ERR_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_FM_ERR_STAT, VUSB_FM_ERR_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_FM_ERR_STAT, VUSB_FM_ERR_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_FM_ERR_STAT, VUSB_FM_ERR_STAT_TOKEN_DONE);

	/* clear all interrupts*/
	DRV_WriteReg8(USB_INT_STAT, 0xff);

	/* clear all endpoint ctrl */
	for(index=0; index<=MAX_INTR_EP_NUM; index++)
		DRV_WriteReg8(USB_ENDPT_CTL(index), 0);
	
	/* USB addr=0 (default) */
	DRV_WriteReg8(USB_ADDR, 0x00);

	WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN, 
							(USB_EP0_MAXP<<VUSB_BDT_BC_SHIFT)|VUSB_BDT_OWNS_BIT);
	WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD, 
							(USB_EP0_MAXP<<VUSB_BDT_BC_SHIFT)|VUSB_BDT_OWNS_BIT);
	WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, USB_EP0_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, USB_EP0_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(1, USB_BDT_RX, USB_EP_BULK_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(1, USB_BDT_TX, USB_EP_BULK_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(2, USB_BDT_RX, USB_EP_BULK_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(2, USB_BDT_TX, USB_EP_BULK_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(3, USB_BDT_RX, USB_EP_INTR_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(3, USB_BDT_TX, USB_EP_INTR_MAXP<<VUSB_BDT_BC_SHIFT);

	DRV_WriteReg8(USB_BDT_PAGE_01, 0xBD);
	DRV_WriteReg8(USB_BDT_PAGE_02, 0xBD);
	DRV_WriteReg8(USB_BDT_PAGE_03, 0xBD);

	DRV_WriteReg8(USB_CTL, VUSB_CTL_ODD_RST|VUSB_CTL_USB_EN);
	DRV_WriteReg8(USB_CTL, VUSB_CTL_USB_EN);

	/* disable Fast mode*/
	DRV_WriteReg8(USB_FM_CTL, (DRV_Reg8(USB_FM_CTL)&(~VUSB_FM_CTL_FMENB)));
	DRV_WriteReg8(USB_FM_PKT_NUML, 0);
	DRV_WriteReg8(USB_FM_PKT_NUMH, 0);
	DRV_WriteReg8(USB_FM_PKT_CNTL, 0);
	DRV_WriteReg8(USB_FM_PKT_CNTH, 0);
	
	USB_EnSysIntr();
	USB_EP0En();	/* enable EP0 */
#elif defined(DRV_USB_IP_V1)
	/* software reset */
	DRV_WriteReg8(USB_RSTCTRL, USB_RSTCTRL_SWRST);
	DRV_WriteReg8(USB_RSTCTRL, 0);	
	/* When mcu set SWRST, the USB_POWER register will be clear as 0 */
	DRV_WriteReg8(USB_POWER, USB_POWER_SETSUSPEND|USB_POWER_SWRSTENAB);
	USB_EnSysIntr();
	USB_EP0En();	/* enable EP0 */
#endif
}

void USB_Release_Drv(void)
{
#if defined(DRV_USB_IP_V2)
	DRV_WriteReg8(USB_INT_ENB, 0);
	DRV_WriteReg8(USB_INT_STAT, 0xff);
#endif	
}

/* enable system global interrupt*/
static void USB_EnSysIntr(void)
{
#if defined(DRV_USB_IP_V3)
	DRV_WriteReg(USB_INTRTXE, 0);
	DRV_WriteReg(USB_INTRRXE, 0);
	DRV_WriteReg8(USB_INTRUSBE, 0);
	DRV_WriteReg8(USB_INTRUSBE, (USB_INTRUSBE_SUSPEND|USB_INTRUSBE_RESUME|USB_INTRUSBE_RESET|USB_INTRUSBE_DISCON));
//	DRV_WriteReg8(USB_INTRUSBE, ~USB_INTRUSB_SOF);
#elif defined(DRV_USB_IP_V2)
	DRV_WriteReg8(USB_INT_ENB, 0xff&(~(VUSB_INT_ENB_SOF|VUSB_INT_ENB_RESUME)));
	DRV_WriteReg8(USB_ERR_ENB, 0xff);
	DRV_WriteReg8(USB_PHY_EXTRA, VUSB_PHY_RESUME_INT_ENB);
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INTRIN1E, 0);
	DRV_WriteReg8(USB_INTROUT1E, 0);
	DRV_WriteReg8(USB_INTRUSBE, 0);
	DRV_WriteReg8(USB_INTRUSBE, (USB_INTRUSBE_SUSPEND|USB_INTRUSBE_RESUME|USB_INTRUSBE_RESET));
#endif
}


/* Resume device */
static void USB_Drv_Resume(void)
{
	g_UsbDrvInfo.resume_hdlr();
#if defined(DRV_USB_IP_V2)
#ifdef __OTG_ENABLE__
	/* Add for OTG function*/
	if(OTG_Get_Plug_Type()==OTG_PLUG_A)
		OTG_Set_Status(OTG_STATUS_A_DETECT_B_SUSPEND, KAL_FALSE);
	else
		OTG_Set_Status(OTG_STATUS_B_DETECT_A_SUSPEND, KAL_FALSE);
#endif	
#endif
}


/* Suspend device */
static void USB_Drv_Suspend(void)
{
	g_UsbDrvInfo.suspend_hdlr();
#if defined(DRV_USB_IP_V2)
#ifdef __OTG_ENABLE__
	/* Add for OTG function*/
	if(OTG_Get_Plug_Type()==OTG_PLUG_A)
		OTG_Set_Status(OTG_STATUS_A_DETECT_B_SUSPEND, KAL_TRUE);
	else
		OTG_Set_Status(OTG_STATUS_B_DETECT_A_SUSPEND, KAL_TRUE);
#endif	
#endif
}


/* set address for hw*/
void USB_SetAddress(kal_uint8 addr, UBS_SET_ADDR_STATE state)
{
#if defined(DRV_USB_IP_V3)
	if(state == USB_SET_ADDR_STATUS)	
		DRV_WriteReg8(USB_FADDR, addr);
#elif defined(DRV_USB_IP_V2)
	if(state==USB_SET_ADDR_STATUS)	
		DRV_WriteReg8(USB_ADDR, addr);
#elif defined(DRV_USB_IP_V1)
	if(state==USB_SET_ADDR_DATA)	
	DRV_WriteReg8(USB_FADDR, addr);
#endif
}

kal_uint16 USB_GetFrameCount(void)
{
#if !defined(DRV_USB_IP_V3)
	kal_uint8 count;
#endif
	kal_uint16 sof;

#if defined(DRV_USB_IP_V3)
	sof =  DRV_Reg(USB_FRAME);
#elif defined(DRV_USB_IP_V2)
	count = DRV_Reg8(USB_FRM_NUML);
	sof = (kal_uint16)count;
	count = DRV_Reg8(USB_FRM_NUMH);
	sof+=(count<<8);
#elif defined(DRV_USB_IP_V1)
	count = DRV_Reg8(USB_FRAME1);
	sof = (kal_uint16)count;
	count = DRV_Reg8(USB_FRAME2);
	sof+=(count<<8);
#endif
	return sof;
}


/************************************************************
	EP ctrl functinos
*************************************************************/

/* initialize EP IN */
void USB_TxEPInit(kal_uint8 epno,kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type)
{
#if defined(DRV_USB_IP_V3)
	if(epno == 0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX, epno);
	/* double buffers, so flush twice */
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	DRV_WriteReg(USB_TXMAXP, data_size);

	/* set FIFO address here */
	if(type == USB_ENDPT_BULK)
	{
#if 1
//double  buffer
		DRV_WriteReg8(USB_TXFIFOSZ, (USB_FIFOSZ_SIZE_512|USB_FIFOSZ_DPB));
		DRV_WriteReg(USB_TXFIFOADD, (g_FIFOadd/8));
		g_FIFOadd += USB_BULK_FIFO_UNIT_SIZE*2;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	}
	else if (type == USB_ENDPT_INTR)
	{
#ifdef __INTR_HB__
		DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_4096);
		DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_INTR_FIFO_UNIT_SIZE;
#else
 	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#else
		DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_1024);
		DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_INTR_FIFO_UNIT_SIZE;
	#endif
#endif
	}
	else if (type == USB_ENDPT_ISO)
	{
#ifdef __ISO_HB__
		DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_4096);
		DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
#else
 	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#else
		DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_1024);
		DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
	#endif
#endif
	}

	if(g_FIFOadd > 4096)
		ASSERT(0);

#elif defined(DRV_USB_IP_V2)
	kal_uint8	epctl_value;

	if(epno == 0)
		EXT_ASSERT(0, epno, 0, 0);

	/* check the packet size, FIFO only 8 bytes*/
	if(epno == 3)
		ASSERT(data_size == 8);

	switch(type)
	{
	case USB_ENDPT_BULK:
		epctl_value = VUSB_ENDPT_BULK_TX;
		break;
	case USB_ENDPT_INTR:
		epctl_value = VUSB_ENDPT_BULK_TX;
		break;
	/* not support */
	case USB_ENDPT_CTRL:
	case USB_ENDPT_ISO:
		ASSERT(0);
		break;
	}

	g_UsbDrvInfo.ep_in_max_data_size[epno-1] =  (kal_uint8)data_size;

	DRV_WriteReg8(USB_ENDPT_CTL(epno), DRV_Reg8(USB_ENDPT_CTL(epno))|epctl_value);

#elif defined(DRV_USB_IP_V1)
	if(epno == 0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX,epno);
	DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
	DRV_WriteReg8(USB_INMAXP, (kal_uint8)(data_size/8));
#endif
}


/* initialize EP OUT */
void USB_RxEPInit(kal_uint8 epno,kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type)
{
#if defined(DRV_USB_IP_V3)
	if(epno == 0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX, epno);
	DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	DRV_WriteReg(USB_RXMAXP, data_size);

	/* set FIFO address here */
	if(type == USB_ENDPT_BULK)
	{
#if 1
//double buffer
		DRV_WriteReg8(USB_RXFIFOSZ, (USB_FIFOSZ_SIZE_512|USB_FIFOSZ_DPB));
		DRV_WriteReg(USB_RXFIFOADD, (g_FIFOadd/8));
		g_FIFOadd += USB_BULK_FIFO_UNIT_SIZE*2;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	}
	else if(type == USB_ENDPT_ISO)
	{
#ifdef __ISO_HB__
		DRV_WriteReg8(USB_RXFIFOSZ, USB_FIFOSZ_SIZE_4096);
		DRV_WriteReg(USB_RXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
#else
 	#ifdef	 __ISO_2FIFO__
		DRV_WriteReg8(USB_RXFIFOSZ, (USB_FIFOSZ_SIZE_1024|USB_FIFOSZ_DPB));
		DRV_WriteReg(USB_RXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE*2;
	#else
		DRV_WriteReg8(USB_RXFIFOSZ, USB_FIFOSZ_SIZE_1024);
		DRV_WriteReg(USB_RXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
	#endif
#endif
	}
	else
	{
		ASSERT(0);
	}

	if(g_FIFOadd > 4096)
		ASSERT(0);

#elif defined(DRV_USB_IP_V2)
	kal_uint8	epctl_value;

	if(epno==0)
		ASSERT(0);
	/* check the packet size, FIFO only 8 bytes*/
	if(epno==3)
		ASSERT(data_size==8);

	switch(type)
	{
	case USB_ENDPT_BULK:
		epctl_value = VUSB_ENDPT_BULK_RX;
		break;
	case USB_ENDPT_INTR:
		epctl_value = VUSB_ENDPT_BULK_RX;
		break;
	/* not support */
	case USB_ENDPT_CTRL:
	case USB_ENDPT_ISO:
		ASSERT(0);
		break;
	}

	g_UsbDrvInfo.ep_out_max_data_size[epno-1] =  (kal_uint8)data_size;
	
	DRV_WriteReg8(USB_ENDPT_CTL(epno), DRV_Reg8(USB_ENDPT_CTL(epno))|epctl_value);
	
#elif defined(DRV_USB_IP_V1)
	if(epno == 0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX,epno);
	DRV_WriteReg8(USB_OUTCSR1,(USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));
	DRV_WriteReg8(USB_OUTMAXP, (kal_uint8)(data_size/8));
#endif
}


void USB_EP0En(void)
{
#if defined(DRV_USB_IP_V3)
	/* default address is from 0 to 63  */
	DRV_WriteReg(USB_INTRTXE, DRV_Reg(USB_INTRTXE)|USB_INTRE_EPEN);
#elif defined(DRV_USB_IP_V2)
	DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_CONTROL);
#elif defined(DRV_USB_IP_V1)
	DRV_Reg8(USB_INTRIN1E) |= USB_INTRIN1E_EPEN;
#endif
}


void USB_TxEPEn(kal_uint8 epno, kal_bool bDMA)
{
	if(epno == 0)
		ASSERT(0);

#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, epno);
	/* double buffers, so flush twice  */
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));

	DRV_Reg(USB_INTRTXE) |= USB_INTRE_EPEN<<epno;
	/* Only configure as multiple packet DMA TX mode */
	DRV_WriteReg(USB_TXCSR, USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE);
#elif defined(DRV_USB_IP_V2)
	if(bDMA == KAL_TRUE)
	{
		g_UsbDrvInfo.ep_in_enb_state[epno-1] = USB_EP_ENB_DMA;
	}	
	else
        {
		g_UsbDrvInfo.ep_in_enb_state[epno-1] = USB_EP_ENB_NORMAL;
	}
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX, epno);

	if(bDMA == KAL_TRUE)
	{
		DRV_Reg8(USB_INTRIN1E) = DRV_Reg8(USB_INTRIN1E) & (~(USB_INTRIN1E_EPEN << epno));
		DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_INCSR2,0);
		DRV_WriteReg8(USB_INCSR2,(USB_INCSR2_AUTOSET | USB_INCSR2_DMAENAB));
	}
	else
	{
		DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_INCSR2,0);
		DRV_Reg8(USB_INTRIN1E) |= (USB_INTRIN1E_EPEN << epno);
	}
#endif	
}


void USB_TxEPDis(kal_uint8 epno, kal_bool bDMA)
{
	if(epno == 0)
		ASSERT(0);

#if defined(DRV_USB_IP_V3)
	USB_Stop_DMA_Channel(epno, USB_TX_EP_TYPE);
	DRV_Reg(USB_INTRTXE) &= ~(USB_INTRE_EPEN<<epno);
	DRV_WriteReg8(USB_INDEX, epno);
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
#elif defined(DRV_USB_IP_V2)
	if(g_UsbDrvInfo.ep_in_enb_state[epno-1]==USB_EP_ENB_DMA)
		USB_Stop_DMA_Channel(epno, USB_TX_EP_TYPE);
	g_UsbDrvInfo.ep_in_enb_state[epno-1] = USB_EP_DIS;
	WRITE_EPN_BDT_PID(epno, USB_BDT_TX, 0);
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX, epno);
	
	if(bDMA==KAL_TRUE)
        {
		USB_Stop_DMA_Channel(epno, USB_TX_EP_TYPE);	
		DRV_Reg8(USB_INTRIN1E) = DRV_Reg8(USB_INTRIN1E) & (~(USB_INTRIN1E_EPEN<<epno));
		DRV_WriteReg8(USB_INCSR2,0);
	}
	else
	{
		DRV_Reg8(USB_INTRIN1E) = DRV_Reg8(USB_INTRIN1E) & (~(USB_INTRIN1E_EPEN<<epno));
		DRV_WriteReg8(USB_INCSR2,0);
	}
#endif	
}

void USB_RxEPEn(kal_uint8 epno, kal_bool bDMA)
{
	if(epno == 0)
		ASSERT(0);

#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, epno);

	/* maybe double buffer, so flush twice  */
	DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	DRV_Reg(USB_INTRRXE) |= USB_INTRE_EPEN<<epno;

#elif defined(DRV_USB_IP_V2)
	if(bDMA == KAL_TRUE)
	{
		g_UsbDrvInfo.ep_out_enb_state[epno-1] = USB_EP_ENB_DMA;
		/* The first expect received packet is data0*/
		g_UsbDrvInfo.ep_out_data01[epno-1] = 0;
	}	
	else
	{
		g_UsbDrvInfo.ep_out_enb_state[epno-1] = USB_EP_ENB_NORMAL;
		/* The first expect received packet is data0*/
		g_UsbDrvInfo.ep_out_data01[epno-1] = 0;
		// configure BDT to receive data
		WRITE_EPN_BDT_PID(epno, USB_BDT_RX, 
			(g_UsbDrvInfo.ep_out_max_data_size[epno-1] << VUSB_BDT_BC_SHIFT) |
			(g_UsbDrvInfo.ep_out_data01[epno-1]<<VUSB_BDT_DATA01_SHIFT) |
			VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
		g_UsbDrvInfo.ep_out_data01[epno-1] ^= 1;
	}
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX, epno);

	if(bDMA == KAL_TRUE)
	{
		DRV_Reg8(USB_INTROUT1E) = DRV_Reg8(USB_INTROUT1E) & (~(USB_INTROUT1E_EP0<<epno));
		DRV_WriteReg8(USB_OUTCSR1,(USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_OUTCSR1,(USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_OUTCSR2,0);
		DRV_WriteReg8(USB_OUTCSR2,(USB_OUTCSR2_AUTOCLEAR | USB_OUTCSR2_DMAENAB));
	}
	else
	{
		DRV_WriteReg8(USB_OUTCSR1,(USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_OUTCSR1,(USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));	
		DRV_WriteReg8(USB_OUTCSR2,0);
		DRV_Reg8(USB_INTROUT1E) |= USB_INTROUT1E_EP0<<epno;
	}
#endif	
}
	
void USB_RxEPDis(kal_uint8 epno, kal_bool bDMA)
{
	if(epno == 0)
		ASSERT(0);

#if defined(DRV_USB_IP_V3)
	USB_Stop_DMA_Channel(epno, USB_RX_EP_TYPE);
	DRV_Reg(USB_INTRRXE) &= ~(USB_INTRE_EPEN << epno);
	DRV_WriteReg8(USB_INDEX, epno);
	DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
#elif defined(DRV_USB_IP_V2)
	if(g_UsbDrvInfo.ep_out_enb_state[epno-1]==USB_EP_ENB_DMA)
		USB_Stop_DMA_Channel(epno, USB_RX_EP_TYPE);
	g_UsbDrvInfo.ep_out_enb_state[epno-1] = USB_EP_DIS;
	WRITE_EPN_BDT_PID(epno, USB_BDT_RX, 0);
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX, epno);
	
	if(bDMA==KAL_TRUE)
	{
		USB_Stop_DMA_Channel(epno, USB_RX_EP_TYPE);	
		DRV_Reg8(USB_INTROUT1E) = DRV_Reg8(USB_INTROUT1E) & (~(USB_INTROUT1E_EP0 << epno));
		DRV_WriteReg8(USB_OUTCSR2,0);
	}
	else
	{
		DRV_Reg8(USB_INTROUT1E) = DRV_Reg8(USB_INTROUT1E) & (~(USB_INTROUT1E_EP0 << epno));
		DRV_WriteReg8(USB_OUTCSR2,0);
	}
#endif	
}	


void USB_TxEPClearDataTog(kal_uint8 epno)
{
#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, epno);
	DRV_WriteReg(USB_TXCSR, DRV_Reg(USB_TXCSR)|USB_TXCSR_CLRDATATOG);
#elif defined(DRV_USB_IP_V2)

#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX, epno);
	DRV_WriteReg8(USB_INCSR1, DRV_Reg8(USB_INCSR1)|USB_INCSR1_CLRDATATOG);
#endif
}


void USB_RxEPClearDataTog(kal_uint8 epno)
{
#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, epno);
	DRV_WriteReg(USB_RXCSR, DRV_Reg(USB_RXCSR)|USB_RXCSR_CLRDATATOG);
#elif defined(DRV_USB_IP_V2)

#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX, epno);
	DRV_WriteReg8(USB_OUTCSR1, DRV_Reg8(USB_OUTCSR1)|USB_OUTCSR1_CLRDATATOG);
#endif
}


/* Clear EP data01, note that ep0 can not use this function */
void USB_TxEPClearData01(kal_uint8 epno)
{
	if(epno == 0)
		ASSERT(0);
#if defined(DRV_USB_IP_V2)
	g_UsbDrvInfo.ep_in_data01[epno-1] = 0;
#endif	
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_USB_IP_V2)
/* under construction !*/
#endif	
/* under construction !*/
#endif

/*  read FIFO data from EP nEP with sfift */
void USB_EPFIFORead_Shift(kal_uint8 nEP, kal_uint16 nBytes, void *pDst, kal_uint32 shift)
{
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V3)
	kal_uint16  nCount = nBytes;
	kal_uint8   *pby;
	kal_uint32  nAddr;
#endif


	if((nBytes != 0)&&(pDst == NULL))
		EXT_ASSERT(0, (kal_uint32)nBytes, 0, 0);
	
#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, nEP);
	nAddr = USB_EP0 + nEP*4;
	pby = (kal_uint8 *)pDst;

	/* read byte by byte */
	while (nCount) 
	{
		*pby++ = DRV_Reg8(nAddr); 
		nCount--;
	}
#elif defined(DRV_USB_IP_V2)
	// make sure this endpoint status belong to MCU
	if(nEP==0)
	{
		if((READ_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd)&VUSB_BDT_OWNS_BIT)!=0)
			ASSERT(0);

		kal_mem_cpy(pDst, (void*)(READ_EP0_BDT_ADDR(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd) + shift), nBytes);
	}
	else
	{
		ASSERT(g_UsbDrvInfo.ep_out_enb_state[nEP-1] != USB_EP_DIS);
		ASSERT(nBytes <= g_UsbDrvInfo.ep_out_max_data_size[nEP-1]);
		
		if((READ_EPN_BDT_PID(nEP, USB_BDT_RX)&VUSB_BDT_OWNS_BIT)!=0)
			ASSERT(0);

		kal_mem_cpy(pDst, (void*)(READ_EPN_BDT_ADDR(nEP, USB_BDT_RX) + shift), nBytes);
	}
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX,nEP);
	nAddr = USB_EP0+nEP*4;
	pby = (kal_uint8 *)pDst;

	/* read byte by byte */
	while (nCount) 
	{
		*pby++ = DRV_Reg8(nAddr); 
		nCount--;
	}
#endif	
}


/* Read fifo data from EP nEP*/
void USB_EPFIFORead(kal_uint8 nEP, kal_uint16 nBytes, void *pDst)
{
	USB_EPFIFORead_Shift(nEP, nBytes, pDst, 0);
}


/*  write data to fifo EP nEP*/
void USB_EPFIFOWrite (kal_uint8 nEP, kal_uint16 nBytes, void *pSrc)
{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V3))
	kal_uint16 nCount = nBytes;
	kal_uint8 *pby;
	kal_uint32 nAddr;
#endif

	if((nBytes != 0)&&(pSrc == NULL))
		EXT_ASSERT(0, (kal_uint32)nBytes, 0, 0);

#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, nEP);
	nAddr = USB_EP0 + nEP*4;
	pby = (kal_uint8 *)pSrc;

	/* write byte by byte */
	while (nCount) 
	{
		DRV_WriteReg8(nAddr, *pby++);
		nCount--;
	}
#elif defined(DRV_USB_IP_V2)
	if(nEP==0)
	{
		// make sure this endpoint status belong to MCU
		if((READ_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd)&VUSB_BDT_OWNS_BIT)!=0)
			ASSERT(0);
		kal_mem_cpy((void*)READ_EP0_BDT_ADDR(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd),
					pSrc, nBytes);
		WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd, nBytes<<VUSB_BDT_BC_SHIFT);
	}
	else
	{
		ASSERT(g_UsbDrvInfo.ep_in_enb_state[nEP-1]!=USB_EP_DIS);
		ASSERT(nBytes<=g_UsbDrvInfo.ep_in_max_data_size[nEP-1]);
		
		// make sure this endpoint status belong to MCU
		if((READ_EPN_BDT_PID(nEP, USB_BDT_TX)&VUSB_BDT_OWNS_BIT)!=0)
			ASSERT(0);
		kal_mem_cpy((void*)READ_EPN_BDT_ADDR(nEP, USB_BDT_TX), pSrc, nBytes);
		WRITE_EPN_BDT_PID(nEP, USB_BDT_TX, nBytes<<VUSB_BDT_BC_SHIFT);
	}
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX,nEP);
	nAddr = USB_EP0+nEP*4;
	pby = (kal_uint8 *)pSrc;

	/* write by byte */
	while (nCount) 
	{
		DRV_WriteReg8(nAddr,*pby++);
		nCount--;
	}
#endif	
}


/* type == USB_TX_EP_TYPE or USB_RX_EP_TYPE 
    en == KAL_TRUE means stall this endpoint */
void USB_CtrlEPStall(kal_uint8 EPno, USB_EP_TYPE direction, kal_bool en, USB_CTRL_STALL_ENTRY entry)
{
#if defined(DRV_USB_IP_V3)
	kal_uint16  CSR;
#elif defined(DRV_USB_IP_V1)
	kal_uint8 CSR1;
#endif

	if((EPno == 0)||(EPno > MAX_INTR_EP_NUM))
		EXT_ASSERT(0, (kal_uint32)EPno, (kal_uint32)entry, 0);

#if defined(DRV_USB_IP_V3)
	if (en == KAL_TRUE)
	{
		/* stall endpoint */
		if(direction == USB_RX_EP_TYPE)
		{
			DRV_WriteReg8(USB_INDEX,  EPno);
			CSR = DRV_Reg(USB_RXCSR);
			DRV_WriteReg(USB_RXCSR, (CSR|USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_SENDSTALL));
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_TRUE;
		}
		else
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR = DRV_Reg(USB_TXCSR);
			DRV_WriteReg(USB_TXCSR, (CSR|USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG|USB_TXCSR_SENDSTALL));
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_TRUE;
		}
	}
	else
	{
		/* clear stall */
		if (direction == USB_RX_EP_TYPE)
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR = DRV_Reg(USB_RXCSR);
			CSR &= ~USB_RXCSR_SENDSTALL;			
			DRV_WriteReg(USB_RXCSR, (CSR|USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_FALSE;
		}
		else
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR = DRV_Reg(USB_TXCSR);
			CSR &= ~USB_TXCSR_SENDSTALL;
			DRV_WriteReg(USB_TXCSR,(CSR|USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_FALSE;
		}
	}
#elif defined(DRV_USB_IP_V2)
	if (en == KAL_TRUE)
	{
		/* stall endpoint */
		if (direction == USB_RX_EP_TYPE)
		{
			WRITE_EPN_BDT_PID(EPno, USB_BDT_RX, VUSB_BDT_OWNS_BIT|VUSB_BDT_STALL_BIT);
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_TRUE;
			g_UsbDrvInfo.ep_out_data01[EPno-1] = 0;
 		}
		else
		{
			WRITE_EPN_BDT_PID(EPno, USB_BDT_TX, VUSB_BDT_OWNS_BIT|VUSB_BDT_STALL_BIT);
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_TRUE;
			g_UsbDrvInfo.ep_in_data01[EPno-1] = 0;
		}
	}
	else
	{
		/* clear stall */
		if (direction == USB_RX_EP_TYPE)
		{
			WRITE_EPN_BDT_PID(EPno, USB_BDT_RX, 0);
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_FALSE;
			g_UsbDrvInfo.ep_out_data01[EPno-1] = 0;
		}
		else
		{
			WRITE_EPN_BDT_PID(EPno, USB_BDT_TX, 0);
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_FALSE;
			g_UsbDrvInfo.ep_in_data01[EPno-1] = 0;
		}
	}
#elif defined(DRV_USB_IP_V1)

	if (en == KAL_TRUE)
	{
		/* stall endpoint */
		if (direction == USB_RX_EP_TYPE)
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR1 = DRV_Reg8(USB_OUTCSR1);
			CSR1 |= USB_OUTCSR1_SENDSTALL;
			DRV_WriteReg8(USB_OUTCSR1,(CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			DRV_WriteReg8(USB_OUTCSR1, (CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_TRUE;
		}
		else
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR1 = DRV_Reg8(USB_INCSR1);
			CSR1 |= USB_INCSR1_SENDSTALL;
			DRV_WriteReg8(USB_INCSR1,(CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			DRV_WriteReg8(USB_INCSR1, (CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_TRUE;
		}
	}
	else
	{
		/* clear stall */
		if (direction == USB_RX_EP_TYPE)
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR1 = DRV_Reg8(USB_OUTCSR1);
			CSR1 &= ~USB_OUTCSR1_SENDSTALL;
			DRV_WriteReg8(USB_OUTCSR1,(CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			DRV_WriteReg8(USB_OUTCSR1, (CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_FALSE;
		}
		else
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR1 = DRV_Reg8(USB_INCSR1);
			CSR1 &= ~USB_INCSR1_SENDSTALL;
			DRV_WriteReg8(USB_INCSR1,(CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			DRV_WriteReg8(USB_INCSR1, (CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_FALSE;
		}
	}
#endif	
}

/* get endpoint 0 status. (if transaction end or sent stall interrupt received)  */
void USB_Get_EP0_Status(kal_bool *p_transaction_end, kal_bool *p_sent_stall)
{
#if defined(DRV_USB_IP_V3)
	kal_uint16  	CSR0;

	DRV_WriteReg8(USB_INDEX, 0);
	CSR0 = DRV_Reg(USB_CSR0);

	if (CSR0 & USB_CSR0_SENTSTALL) 
		*p_sent_stall = KAL_TRUE;
	else
		*p_sent_stall = KAL_FALSE;
	
	if (CSR0 & USB_CSR0_SETUPEND) 
		*p_transaction_end = KAL_TRUE;
	else
		*p_transaction_end = KAL_FALSE;
#elif defined(DRV_USB_IP_V2)
	if((READ_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd^1) &VUSB_BDT_STALL_BIT) 
		&& (DRV_Reg8(USB_CTL)&VUSB_CTL_TXD_SUSPEND))
		*p_sent_stall = KAL_TRUE;
	else
		*p_sent_stall = KAL_FALSE;

	if(g_UsbDrvInfo.ep0_transaction_type == USB_EP0_TRANS_END)
		*p_transaction_end = KAL_TRUE;
	else
		*p_transaction_end = KAL_FALSE;
#elif defined(DRV_USB_IP_V1)
	kal_uint8 byCSR0;
	
	DRV_WriteReg8(USB_INDEX,0);
	byCSR0 = DRV_Reg8(USB_CSR0);

	if (byCSR0 & USB_CSR0_SENTSTALL) 
		*p_sent_stall = KAL_TRUE;
	else
		*p_sent_stall = KAL_FALSE;
	
	if (byCSR0 & USB_CSR0_SETUPEND) 
		*p_transaction_end = KAL_TRUE;
	else
		*p_transaction_end = KAL_FALSE;
#endif	
}


/* control endpoint 0 registers according to USB_EP0_DRV_STATE */
void USB_Update_EP0_State(USB_EP0_DRV_STATE state, kal_bool stall, kal_bool end)
{
#if defined(DRV_USB_IP_V3)
	kal_uint8   reg_state;
	kal_uint16   CSR0;

	/* clear sent stall */
	if(state == USB_EP0_DRV_STATE_CLEAR_SENT_STALL)
	{
		DRV_WriteReg8(USB_INDEX, 0);   
		CSR0 = DRV_Reg(USB_CSR0);
		DRV_WriteReg(USB_CSR0, CSR0&(~USB_CSR0_SENTSTALL));
		return;
	}

	/* clear transaction end*/
	if(state == USB_EP0_DRV_STATE_TRANSACTION_END)
	{
		DRV_WriteReg8(USB_INDEX, 0);   
		DRV_WriteReg(USB_CSR0, (USB_CSR0_SERVICEDSETUPEND));
		return;
	}

	/* ep0 read end or write ready*/
	if(state == USB_EP0_DRV_STATE_READ_END)
	{
		reg_state = USB_CSR0_SERVICEDRXPKTRDY;
	}
	else
	{
		reg_state = USB_CSR0_TXPKTRDY;
	}

	/* error occured, sent stall*/
	if(stall == KAL_TRUE)
	{
		reg_state |= USB_CSR0_SENDSTALL; 
	}

	/* last data for this transaction, set data end bit*/
	if(end == KAL_TRUE)
	{
		reg_state |= USB_CSR0_DATAEND; 
	}
	
	DRV_WriteReg8(USB_INDEX, 0);
	DRV_WriteReg(USB_CSR0, reg_state);

#elif defined(DRV_USB_IP_V2)
	/* clear sent stall*/
	if(state ==USB_EP0_DRV_STATE_CLEAR_SENT_STALL)
	{
		WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN)&(~VUSB_BDT_STALL_BIT));
		WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD)&(~VUSB_BDT_STALL_BIT));
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 
							READ_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN)&(~VUSB_BDT_STALL_BIT));
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 
							READ_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD)&(~VUSB_BDT_STALL_BIT));
		return;
	}

	/* clear transaction end*/
	if(state ==USB_EP0_DRV_STATE_TRANSACTION_END)
	{
		EXT_ASSERT((g_UsbDrvInfo.ep0_current_dir==0), 0, 0, 0);
		/* clear the data in sent buffer */
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 0);
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 0);
		WRITE_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd, 
							(USB_EP0_MAXP << VUSB_BDT_BC_SHIFT) |VUSB_BDT_OWNS_BIT);
		g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;
		return;
	}

	/* ep0 read end or write ready*/
	if((state == USB_EP0_DRV_STATE_READ_END) && (stall==KAL_FALSE))
	{
		/* clear tx suspend for setupt packet*/
		if(DRV_Reg8(USB_CTL)&VUSB_CTL_TXD_SUSPEND)
		{
			g_UsbDrvInfo.ep0_tx_data01 = 0;
			/* clear the data in sent buffer */
			WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 0);
			WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 0);
			DRV_Reg8(USB_CTL) = DRV_Reg8(USB_CTL)&(~VUSB_CTL_TXD_SUSPEND);
		}	

		WRITE_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd, 
							(USB_EP0_MAXP << VUSB_BDT_BC_SHIFT) |VUSB_BDT_OWNS_BIT);
		g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_RX_DATA;
	}
	else if((state == USB_EP0_DRV_STATE_WRITE_RDY) && (stall==KAL_FALSE))
	{
		/* toggle DATA01*/
		g_UsbDrvInfo.ep0_tx_data01^=1;
		WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd, 
							(READ_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd)&VUSB_BDT_BC_MASK) 
							|(g_UsbDrvInfo.ep0_tx_data01<<VUSB_BDT_DATA01_SHIFT) 
							| VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
		g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_TX_DATA;
	}
	
	/* error occured, sent stall*/	
	if(stall == KAL_TRUE)
	{
		WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN)|VUSB_BDT_STALL_BIT);
		WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD)|VUSB_BDT_STALL_BIT);
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN)|VUSB_BDT_STALL_BIT);
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD)|VUSB_BDT_STALL_BIT);
		g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;
	}
	/* last data for this transaction, set data end bit*/
	else if(end == KAL_TRUE)
	{
		if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_RX_DATA)
		{
			/* status data01 always 1*/
			g_UsbDrvInfo.ep0_tx_data01 = 1;
			/* byte count 0 */
			WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd, 
								(g_UsbDrvInfo.ep0_tx_data01<<VUSB_BDT_DATA01_SHIFT) |
								VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
			g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_RX_STATUS;
		}
		else if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_DATA)
		{					
			g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_TX_DATA_END;
		}
		else
		{
			EXT_ASSERT(0, g_UsbDrvInfo.ep0_transaction_type, state, stall);
		}
	}
#elif defined(DRV_USB_IP_V1)
	kal_uint8   reg_state;
	kal_uint8   byCSR0;

	/* clear sent stall*/
	if(state ==USB_EP0_DRV_STATE_CLEAR_SENT_STALL)
	{
		DRV_WriteReg8(USB_INDEX,0);   
		byCSR0 = DRV_Reg8(USB_CSR0);
		DRV_WriteReg8(USB_CSR0, byCSR0&(~USB_CSR0_SENTSTALL));
		return;
	}

	/* clear transaction end*/
	if(state ==USB_EP0_DRV_STATE_TRANSACTION_END)
	{
		DRV_WriteReg8(USB_INDEX,0);   
		DRV_WriteReg8(USB_CSR0, (USB_CSR0_SERVICESETUPEND));
		return;
	}

	/* ep0 read end or write ready*/
	if(state == USB_EP0_DRV_STATE_READ_END)
	{
		reg_state = USB_CSR0_SERVICEDOUTPKTRDY;
	}
	else
	{
		reg_state = USB_CSR0_INPKTRDY;
	}

	/* error occured, sent stall*/	
	if(stall == KAL_TRUE)
	{
		reg_state |= USB_CSR0_SENDSTALL; 
	}
	/* last data for this transaction, set data end bit*/
	if(end == KAL_TRUE)
	{
		reg_state |= USB_CSR0_DATAEND; 
	}
	
	DRV_WriteReg8(USB_INDEX,0);   
	DRV_WriteReg8(USB_CSR0, reg_state);
#endif		
}

/* return packet length for endpoint 0*/
kal_uint32 USB_EP0_Pkt_Len(void)
{
	kal_uint32 nCount = 0;
	
#if defined(DRV_USB_IP_V3)
	kal_uint16  CSR0;
	
	DRV_WriteReg8(USB_INDEX, 0);
	CSR0 = DRV_Reg(USB_CSR0);
	
	if(CSR0&USB_CSR0_RXPKTRDY)
		nCount = (kal_uint32)DRV_Reg8(USB_COUNT0);
#elif defined(DRV_USB_IP_V2)
	if((READ_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd) &VUSB_BDT_OWNS_BIT)==0)
	{
		nCount = (READ_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd) & VUSB_BDT_BC_MASK)
				>>VUSB_BDT_BC_SHIFT;
	}
#elif defined(DRV_USB_IP_V1)
	kal_uint8 byCSR0;
	
	DRV_WriteReg8(USB_INDEX,0);
	byCSR0 = DRV_Reg8(USB_CSR0);
	
	if(byCSR0 & USB_CSR0_OUTPKTRDY)
	{
		nCount = (kal_uint32)DRV_Reg8(USB_COUNT0);
	}
#endif

	return nCount;
}

/* ep in data prepared ready, set ready bit */
void USB_EP_Bulk_Tx_Ready(kal_uint8 ep_num)
{
	if((ep_num==0)||(ep_num>MAX_INTR_EP_NUM))
		EXT_ASSERT(0, ep_num, 0, 0);

#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg(USB_TXCSR, DRV_Reg(USB_TXCSR)|USB_TXCSR_TXPKTRDY);	
#elif defined(DRV_USB_IP_V2)
	WRITE_EPN_BDT_PID(ep_num, USB_BDT_TX, 
							(READ_EPN_BDT_PID(ep_num, USB_BDT_TX) & VUSB_BDT_BC_MASK) |
							(g_UsbDrvInfo.ep_in_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
							VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
	g_UsbDrvInfo.ep_in_data01[ep_num-1]^=1;
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX,ep_num);
	DRV_WriteReg8(USB_INCSR1, USB_INCSR1_INPKTRDY);
#endif
}

/* return ep out received packet length*/
kal_uint32 USB_EP_Rx_Pkt_Len(kal_uint8 ep_num)
{
#if defined(DRV_USB_IP_V3)
	kal_uint16 CSR;
#elif defined(DRV_USB_IP_V1)
	kal_uint8 byCSR;
#endif
	kal_uint32 nCount = 0;
	
	if((ep_num==0)||(ep_num>MAX_INTR_EP_NUM))
		EXT_ASSERT(0, ep_num, 0, 0);
	
#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, ep_num);
	CSR = DRV_Reg(USB_RXCSR);
	
	if(CSR&USB_RXCSR_RXPKTRDY)
		nCount = (kal_uint32)DRV_Reg(USB_RXCOUNT);
#elif defined(DRV_USB_IP_V2)
	if((READ_EPN_BDT_PID(ep_num, USB_BDT_RX)&VUSB_BDT_OWNS_BIT)==0)
	{
		nCount = (READ_EPN_BDT_PID(ep_num, USB_BDT_RX)&VUSB_BDT_BC_MASK) 
				>> VUSB_BDT_BC_SHIFT;
	}
#elif defined(DRV_USB_IP_V1)	
	DRV_WriteReg8(USB_INDEX,ep_num);
	byCSR = DRV_Reg8(USB_OUTCSR1);
	
	if(byCSR & USB_OUTCSR1_OUTPKTRDY)
	{
		nCount = (kal_uint32)DRV_Reg8(USB_OUTCOUNT1);
	}
#endif
	return nCount;
}	


/* ep out data already read out, clear the data*/
void USB_EP_Bulk_Rx_Ready(kal_uint8 ep_num)
{
	if((ep_num==0)||(ep_num>MAX_INTR_EP_NUM))
		EXT_ASSERT(0, ep_num, 0, 0);

#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg(USB_RXCSR, DRV_Reg(USB_RXCSR)&(~USB_RXCSR_RXPKTRDY));
#elif defined(DRV_USB_IP_V2)
	WRITE_EPN_BDT_PID(ep_num, USB_BDT_RX, 
								(g_UsbDrvInfo.ep_out_max_data_size[ep_num-1] << VUSB_BDT_BC_SHIFT) |
								(g_UsbDrvInfo.ep_out_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
								VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
	g_UsbDrvInfo.ep_out_data01[ep_num-1]^=1;
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX,ep_num);
	DRV_WriteReg8(USB_OUTCSR1, 0);
#endif
}

/* Get status. See if ep in fifo is empty. 
   If false, it means some data in fifo still wait to send out */
kal_bool USB_Is_EP_Bulk_Tx_Empty(kal_uint8 ep_num)
{
#if defined(DRV_USB_IP_V3)
	kal_uint16  	CSR;
#elif defined(DRV_USB_IP_V1)
	kal_uint8 byCSR;
#endif
	kal_bool bRet;
	
	if((ep_num==0)||(ep_num>MAX_INTR_EP_NUM))
		EXT_ASSERT(0, ep_num, 0, 0);

#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, ep_num);	
	CSR = DRV_Reg(USB_TXCSR);
	if(CSR&USB_TXCSR_FIFONOTEMPTY)
		return  KAL_FALSE;
	else
		return  KAL_TRUE;	
#elif defined(DRV_USB_IP_V2)
	/* own bit 1 means the data is still not sent out */
	if((READ_EPN_BDT_PID(ep_num, USB_BDT_TX)&VUSB_BDT_OWNS_BIT)!=0)
		bRet = KAL_FALSE;
	else
		bRet = KAL_TRUE;	
#elif defined(DRV_USB_IP_V1)	
	DRV_WriteReg8(USB_INDEX, ep_num);	
	byCSR = DRV_Reg8(USB_INCSR1);
	if(byCSR&USB_INCSR1_FIFONOTEMPTY)
		bRet = KAL_FALSE;
	else
		bRet = KAL_TRUE;	
#endif
	
	return bRet;
}


/* Clear the FIFO for TX ep */
void USB_Clear_Tx_EP_FIFO(kal_uint8 ep_num)
{
#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg(USB_TXCSR, DRV_Reg(USB_TXCSR)|USB_TXCSR_FLUSHFIFO);
	DRV_WriteReg(USB_TXCSR, DRV_Reg(USB_TXCSR)|USB_TXCSR_FLUSHFIFO);
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg8(USB_INCSR1, (DRV_Reg8(USB_INCSR1)|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
	DRV_WriteReg8(USB_INCSR1, (DRV_Reg8(USB_INCSR1)|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
//	DRV_WriteReg8(USB_INCSR1, USB_INCSR1_FLUSHFIFO);
//	DRV_WriteReg8(USB_INCSR1, USB_INCSR1_FLUSHFIFO);
#endif
}


/* clear the fifo for ep OUT*/
void USB_Clear_Rx_EP_FIFO(kal_uint8 ep_num)
{
#if defined(DRV_USB_IP_V3)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg(USB_RXCSR, DRV_Reg(USB_RXCSR)|USB_RXCSR_FLUSHFIFO);
	DRV_WriteReg(USB_RXCSR, DRV_Reg(USB_RXCSR)|USB_RXCSR_FLUSHFIFO);
#elif defined(DRV_USB_IP_V1)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg8(USB_OUTCSR1, (DRV_Reg8(USB_OUTCSR1)|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
	DRV_WriteReg8(USB_OUTCSR1, (DRV_Reg8(USB_OUTCSR1)|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
//	DRV_WriteReg8(USB_OUTCSR1, USB_OUTCSR1_FLUSHFIFO);
//	DRV_WriteReg8(USB_OUTCSR1, USB_OUTCSR1_FLUSHFIFO);
#endif
}

/************************************************************
	DMA functions
*************************************************************/

/* Get DMA channel for logical endpoint, including ep0 */
void USB_Get_DMA_Channel(kal_uint8 ep_num, USB_EP_TYPE direction, kal_bool same_chan)
{
#if defined(DRV_USB_IP_V3)
	g_UsbDrvInfo.dma_channel++;

	if(g_UsbDrvInfo.dma_channel > MAX_DMA_EP_NUM)
		EXT_ASSERT(0, g_UsbDrvInfo.dma_channel, MAX_DMA_EP_NUM, 0);

	if(same_chan == KAL_TRUE)
	{
		g_UsbDrvInfo.two_ep_with_one_dma[ep_num-1] = KAL_TRUE;
		/* the same channel */
		g_UsbDrvInfo.dma_port[USB_TX_EP_TYPE][ep_num-1] = g_UsbDrvInfo.dma_channel;
		g_UsbDrvInfo.dma_port[USB_RX_EP_TYPE][ep_num-1] = g_UsbDrvInfo.dma_channel;
		g_UsbDrvInfo.dma_ep_num[g_UsbDrvInfo.dma_channel-1] = ep_num;
	}
	else
	{
		g_UsbDrvInfo.two_ep_with_one_dma[ep_num-1] = KAL_FALSE;
		g_UsbDrvInfo.dma_port[direction][ep_num-1] = g_UsbDrvInfo.dma_channel;
		g_UsbDrvInfo.dma_ep_num[g_UsbDrvInfo.dma_channel-1] = ep_num;
		g_UsbDrvInfo.dma_dir[g_UsbDrvInfo.dma_channel-1] = direction;
	}
#else
	switch (ep_num)
	{
	case 1:
		g_UsbDrvInfo.dma_port[ep_num - 1] = DMA_GetChannel(DMA_USB1TX);
		break;
#ifdef USB_SUPPORT_MUTIPLE_APP		
	case 2:
		g_UsbDrvInfo.dma_port[ep_num- 1] = DMA_GetChannel(DMA_USB2TX);
		break;
#endif /* USB_SUPPORT_MUTIPLE_APP */		
	default:
		EXT_ASSERT(0, ep_num, 0 , 0);
		break;
	}
#endif
}




/* stop DMA channel*/
void USB_Stop_DMA_Channel(kal_uint8 ep_num, USB_EP_TYPE  direction)
{
#if defined(DRV_USB_IP_V3)

//	kal_uint32 	savedMask;
	kal_uint8 	dma_chan;


	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

//	savedMask = SaveAndSetIRQMask();
	/* stop DMA channel */
	USBDMA_Stop(dma_chan);
//	USBDMA_PPStop(dma_chan);
//	RestoreIRQMask(savedMask);

	/* Clear pending DMA interrupts */
	// write 0 clear
	DRV_WriteReg32(USB_DMAINTR, ~((1<<(dma_chan-1))|(0xC000<<(dma_chan*2))));

	g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_FALSE;
	g_UsbDrvInfo.dma_running[dma_chan-1] = KAL_FALSE;
#else  /* defined(DRV_USB_IP_V3) */

	kal_uint32 savedMask;
#if defined(DRV_USB_IP_V2)		
	kal_uint32 fm_pkt_num = 0;
	kal_uint32 fm_pkt_cnt = 0;
#endif	

	if(ep_num>MAX_DMA_EP_NUM)
		EXT_ASSERT(0, ep_num, 0, 0);

	if(g_UsbDrvInfo.dma_port[ep_num - 1] != 0)
	{
		if (DMA_CheckRunStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
		{
			DMA_Stop(g_UsbDrvInfo.dma_port[ep_num - 1]);
		}
	
		savedMask = SaveAndSetIRQMask();
		if (DMA_CheckITStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
		{	
			DMA_ACKI(g_UsbDrvInfo.dma_port[ep_num - 1]);
			IRQClearInt(IRQ_DMA_CODE);
		}
		RestoreIRQMask(savedMask);
}

		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;
		g_UsbDrvInfo.dma_running[ep_num - 1] = KAL_FALSE;
#endif  /* defined(DRV_USB_IP_V3) */

#if defined(DRV_USB_IP_V2)	

	/* disable Fast mode*/
	DRV_WriteReg8(USB_FM_CTL, (DRV_Reg8(USB_FM_CTL)&(~VUSB_FM_CTL_FMENB)));

	fm_pkt_num = DRV_Reg8(USB_FM_PKT_NUML) + (DRV_Reg8(USB_FM_PKT_NUMH)<<8);
	fm_pkt_cnt = DRV_Reg8(USB_FM_PKT_CNTL) + (DRV_Reg8(USB_FM_PKT_CNTH)<<8);
	
	if(fm_pkt_num>0)
	{
		/* check whether any packet is sent or not */
		if(DRV_Reg(DMA_COUNT(g_UsbDrvInfo.dma_port[ep_num - 1]))==DRV_Reg(DMA_RLCT(g_UsbDrvInfo.dma_port[ep_num - 1])))
		{
			/* Fast mode is start but no any packet is transmitted */	
			/* restore data01 according to fast mode round */
			if(fm_pkt_num&0x1)
			{
				if(g_UsbDrvInfo.dma_tx_ep!=0)
					g_UsbDrvInfo.ep_in_data01[ep_num-1]^=1; 
				else
					g_UsbDrvInfo.ep_out_data01[ep_num-1]^=1; 
			}		
		}
		else
		{
			/* Fast mode has sent some packet, so data01 can be known from register */
			if((fm_pkt_num-fm_pkt_cnt)&0x1)
			{
				if(g_UsbDrvInfo.dma_tx_ep!=0)
					g_UsbDrvInfo.ep_in_data01[ep_num-1]^=1; 
				else
					g_UsbDrvInfo.ep_out_data01[ep_num-1]^=1; 
			}		
		}
	}	

	g_UsbDrvInfo.dma_tx_ep = 0;
	g_UsbDrvInfo.dma_res_tx_ep = 0;
	g_UsbDrvInfo.fast_mode_tx_ep= 0;
#endif	
}


/* stop and free DMA channel resource */
void USB_Free_DMA_Channel(kal_uint8 ep_num, USB_EP_TYPE  direction)
{
#if defined(DRV_USB_IP_V3)
	kal_uint8 	dma_chan;


	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);
	
	USB_Stop_DMA_Channel(ep_num, direction);
	g_UsbDrvInfo.dma_ep_num[dma_chan-1] = 0;

	if(g_UsbDrvInfo.two_ep_with_one_dma[ep_num-1] == KAL_TRUE)
	{
		g_UsbDrvInfo.dma_port[USB_TX_EP_TYPE][ep_num-1] = 0;
		g_UsbDrvInfo.dma_port[USB_RX_EP_TYPE][ep_num-1] = 0;
	}
	else
	{
		g_UsbDrvInfo.dma_port[direction][ep_num-1] = 0;
	}
#else
	if(ep_num > MAX_DMA_EP_NUM)
		EXT_ASSERT(0, ep_num, 0, 0);
	
	if(g_UsbDrvInfo.dma_port[ep_num - 1] != 0)
	{
		USB_Stop_DMA_Channel(ep_num, direction);
		DMA_FreeChannel(g_UsbDrvInfo.dma_port[ep_num - 1]);
	}	

	g_UsbDrvInfo.dma_port[ep_num - 1] = 0;
#endif
}


/* DMA setup function.
The last one "callback_upd_run" parameter true => application decides to clear "driver dma running status" by itself */
void USB_DMA_Setup(kal_uint8 ep_num, USB_EP_TYPE  direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
				usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type)
{
#if defined(DRV_USB_IP_V3)
	kal_uint16  dma_ctrl;
	kal_uint8    dma_chan;
	kal_uint16  CSR;


	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

	if(g_UsbDrvInfo.two_ep_with_one_dma[ep_num-1] == KAL_TRUE)
	{
		g_UsbDrvInfo.dma_dir[dma_chan-1] = direction;
	}
	else if(g_UsbDrvInfo.dma_dir[dma_chan-1] != direction)
	{
		EXT_ASSERT(0, dma_chan, g_UsbDrvInfo.dma_dir[dma_chan-1], direction);
	}

	g_UsbDrvInfo.dma_running[dma_chan-1] = KAL_TRUE;
	g_UsbDrvInfo.dma_callback[dma_chan-1] = callback;
	g_UsbDrvInfo.dma_callback_upd_run[dma_chan-1] = callback_upd_run;
	g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_FALSE;

#if 0
/* under construction !*/
/* under construction !*/
	#ifdef __USB_AUTO_SET__
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
		#ifdef __INTR_HB__
/* under construction !*/
/* under construction !*/
		#else
/* under construction !*/
/* under construction !*/
		#endif
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
		#ifdef __ISO_HB__
/* under construction !*/
/* under construction !*/
		#else
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#else
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
		#ifdef __INTR_HB__
/* under construction !*/
/* under construction !*/
		#else
/* under construction !*/
/* under construction !*/
		#endif
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
		#ifdef __ISO_HB__
/* under construction !*/
/* under construction !*/
		#else
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
#endif

	if(ep_type == USB_ENDPT_BULK)
	{
		if(USB_Is_High_Speed() == KAL_TRUE)
		{
			if (length%USB_EP_BULK_MAXP_HS)
				g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
		}
		else
		{
			if (length%USB_EP_BULK_MAXP_FS)
				g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;;
		}
	}
	else if(ep_type == USB_ENDPT_INTR)
	{
		if(USB_Is_High_Speed() == KAL_TRUE)
		{
	#ifdef __INTR_HB__
			if (length%USB_EP_INTR_MAXP_HB_HS)
				g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
	#else
			if (length%USB_EP_INTR_MAXP_HS)
				g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
	#endif
		}
		else
		{
			if (length%USB_EP_INTR_MAXP_FS)
				g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;;
		}
	}
	else if(ep_type == USB_ENDPT_ISO)
	{
		if(USB_Is_High_Speed() == KAL_TRUE)
		{
	#ifdef __ISO_HB__
			if (length%USB_EP_ISO_MAXP_HB_HS)
				g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
	#else
			if (length%USB_EP_ISO_MAXP_HS)
				g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
	#endif
		}
		else
		{
			if (length%USB_EP_ISO_MAXP_FS)
				g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;;
		}
	}

	DRV_WriteReg8(USB_INDEX, ep_num);

	/* DMA_CONFIG */
	if(dma_type == USB_DMA0_TYPE)
	{
		if(direction == USB_RX_EP_TYPE)
		{
			/* Clear RXCSR setting */
			DRV_WriteReg(USB_RXCSR, USB_RXCSR_RXPKTRDY);
		}
		else
		{
			ASSERT(0);
		}

		DRV_WriteReg32(USB_DMAADDR(dma_chan), addr);
		DRV_WriteReg32(USB_DMACNT(dma_chan), length);

		dma_ctrl = USB_DMACNTL_INTEN|USB_DMACNTL_BURSTMODE_MASK|(ep_num<<4)|USB_DMACNTL_DMAEN;

		if(direction == USB_TX_EP_TYPE)
		{
			dma_ctrl |= USB_DMACNTL_DMADIR;
		}

		DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);
	}
	else if(dma_type == USB_DMA1_TYPE)
	{
		if(direction == USB_TX_EP_TYPE)
		{
	#ifdef __USB_AUTO_SET__
			if(((ep_num == 1)&&(dma_chan == 2))||((ep_num == 2)&&(dma_chan == 3))||((ep_num == 3)&&(dma_chan == 4)))
			{
				if(ep_type == USB_ENDPT_ISO)
				{
					DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_AUTOSET_SPKT|USB_TXCSR_ISO));
				}
				else if(ep_type == USB_ENDPT_INTR)
				{
					DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_FRCDATATOG|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_AUTOSET_SPKT));
				}
				else
				{
					DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_AUTOSET_SPKT));
				}
			}
			else
			{
				if(ep_type == USB_ENDPT_ISO)
				{
					DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_ISO));
				}
				else if(ep_type == USB_ENDPT_INTR)
				{
					DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_FRCDATATOG|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE));
				}
				else
				{
					DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE));
				}
			}
	#else
			if(ep_type == USB_ENDPT_ISO)
			{
				DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_ISO));
			}
			else if(ep_type == USB_ENDPT_INTR)
			{
				DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_FRCDATATOG|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE));
			}
			else
			{
				DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE));
			}
	#endif

			DRV_WriteReg32(USB_DMAADDR(dma_chan), addr);
			DRV_WriteReg32(USB_DMACNT(dma_chan), length);

			dma_ctrl = USB_DMACNTL_DMADIR|USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|USB_DMACNTL_BURSTMODE_MASK|(ep_num<<4)|USB_DMACNTL_DMAEN;
			DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);
		}
		else if(direction == USB_RX_EP_TYPE)
		{
			/* stop DMA channel */
			USBDMA_Stop(dma_chan);
//			USBDMA_PPStop(dma_chan);

			if(known_size == KAL_TRUE)
			{
				if(ep_type == USB_ENDPT_ISO)
				{
//					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOCLREN_SPKT|USB_RXCSR_ISO;
					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_ISO;
				}
				else
				{
//					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOCLREN_SPKT;
					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB;
				}

				DRV_WriteReg(USB_RXCSR, CSR);
			}
			else
			{
		#ifdef  __DMA_UNKNOWN_RX__
				/* Only unknown size Rx need this !! */
				g_UsbDrvInfo.dma_addr[ep_num-1] = addr;
				g_UsbDrvInfo.dma_length[ep_num-1] = length;

				if(ep_type == USB_ENDPT_ISO)
				{
					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQMODE|USB_RXCSR_DMAREQENAB|USB_RXCSR_ISO;
				}
				else
				{
					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQMODE|USB_RXCSR_DMAREQENAB;
				}

				DRV_WriteReg(USB_RXCSR, CSR);
				USB_Enable_DMA_Timer_Count(dma_chan, KAL_TRUE);

		#else   /* __DMA_UNKNOWN_RX__ */
				ASSERT(0);
		#endif  /* __DMA_UNKNOWN_RX__ */
			}

			DRV_WriteReg32(USB_DMAADDR(dma_chan), addr);
			DRV_WriteReg32(USB_DMACNT(dma_chan), length);

			dma_ctrl = USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|USB_DMACNTL_BURSTMODE_MASK|(ep_num<<4)|USB_DMACNTL_DMAEN;
			DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);
		}
	}
	else if(dma_type == USB_DMA2_TYPE)
	{
		if(direction == USB_RX_EP_TYPE)
		{
			if(known_size == KAL_TRUE)
			{
				/* stop DMA channel */
				USBDMA_Stop(dma_chan);
//				USBDMA_PPStop(dma_chan);

				if(ep_type == USB_ENDPT_ISO)
				{
//					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOCLREN_SPKT|USB_RXCSR_ISO;
					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_ISO;

				}
				else
				{
//					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOCLREN_SPKT;
					CSR = USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB;
				}

				DRV_WriteReg(USB_RXCSR, CSR);
			}
			else
			{
				ASSERT(0);
			}

			DRV_WriteReg32(USB_DMAADDR(dma_chan), addr);
			DRV_WriteReg32(USB_DMACNT(dma_chan), length);
			
			dma_ctrl = USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|USB_DMACNTL_BURSTMODE_MASK
						|(ep_num<<4)|USB_DMACNTL_DMAEN|USB_DMACNTL_ENDMAMODE2;
			DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);
		}
		else if(direction == USB_TX_EP_TYPE)
		{
			ASSERT(0);
		}
	}
#else  /* defined(DRV_USB_IP_V3) */


	DMA_INPUT		dma_input;
   	DMA_HWMENU	dma_menu;
#if defined(DRV_USB_IP_V2)
	kal_uint32		fm_ep;
	kal_uint32		fm_pkt_num;
	kal_uint32		fm_dma_index = 4;  /* Cannot be 4 */
#endif

	if((ep_num > MAX_DMA_EP_NUM)||(ep_num == 0))
		EXT_ASSERT(0, ep_num, 0, 0);

	ASSERT(g_UsbDrvInfo.dma_running[ep_num - 1]==KAL_FALSE);
	g_UsbDrvInfo.dma_running[ep_num - 1] = KAL_TRUE;
	
	ASSERT(g_UsbDrvInfo.dma_port[ep_num - 1] !=0);

	g_UsbDrvInfo.dma_callback[ep_num - 1] = callback;
	g_UsbDrvInfo.dma_callback_upd_run[ep_num - 1] = callback_upd_run;
	g_UsbDrvInfo.dma_dir[ep_num - 1] = direction;
   	
	/*DMA_CONFIG*/
	/* single mode */
	dma_menu.TMOD.burst_mode = 0;

	if (ep_num == 1)
	{
		if(direction == USB_TX_EP_TYPE)
		{
			dma_menu.master = DMA_USB1TX; 
#if defined(DRV_USB_IP_V2)
			fm_dma_index = VUSB_FM_DMA_TX1;
			g_UsbDrvInfo.fast_mode_tx_ep = 1;
			g_UsbDrvInfo.dma_res_tx_ep = 1;
			g_UsbDrvInfo.dma_tx_ep = 1;
#endif
		}
		else
		{
			dma_menu.master = DMA_USB1RX; 
#if defined(DRV_USB_IP_V2)
			fm_dma_index = VUSB_FM_DMA_RX1;
#endif			
		}
		dma_input.callback = USB_DMA_Callback_EP1;
	}
#ifdef USB_SUPPORT_MUTIPLE_APP	
	else if (ep_num == 2)
	{
		if(direction == USB_TX_EP_TYPE)
		{
			dma_menu.master = DMA_USB2TX; 
#if defined(DRV_USB_IP_V2)
			fm_dma_index = VUSB_FM_DMA_TX2;
			g_UsbDrvInfo.fast_mode_tx_ep = 2;
			g_UsbDrvInfo.dma_res_tx_ep = 2;
			g_UsbDrvInfo.dma_tx_ep = 2;
#endif
		}
		else
		{
			dma_menu.master = DMA_USB2RX; 
#if defined(DRV_USB_IP_V2)
			fm_dma_index = VUSB_FM_DMA_RX2;
#endif			
		}
		dma_input.callback = USB_DMA_Callback_EP2;
	}
#endif /* USB_SUPPORT_MUTIPLE_APP*/	
	else
	{
		EXT_ASSERT(0, ep_num, 0, 0);
	}
	
	dma_menu.addr = (kal_uint32)addr;

	/* half channel */
	if(direction == USB_TX_EP_TYPE)
		dma_input.type = DMA_HWTX;
	else
		dma_input.type = DMA_HWRX;
	dma_input.menu = &dma_menu;

#if defined(DRV_USB_IP_V2)

	if(fm_dma_index == 4)
		ASSERT(0);

	/**** Configure generic DMA *****/
	if(addr&0x3)
	{
		/* address is not 4 bytes alignment, use B2W to copy data */
		dma_menu.TMOD.burst_mode = KAL_TRUE;
		dma_menu.TMOD.cycle = 4;
		dma_input.size = DMA_BYTE; 
		/* must pad length to multiple of 4, this is hardware limit */
		/* copy multiple of 4 bytes to FIFO, but still fill BDT as real packet size */ 
		if((length & 0x3) != 0)
		{
			dma_input.count= length + (4-(length & 0x3));
		}
		else
		{
			dma_input.count = length;
		}	
	}
	else 
	{
		/*address is 4 byts alignment, use word to copy data */
		dma_input.size = DMA_LONG; 
		/* must pad length to multiple of 4, this is hardware limit */
		/* copy multiple of 4 bytes to FIFO, but still fill BDT as real packet size */ 
		if((length & 0x3) != 0)
		{
			dma_input.count = (length + (4-(length & 0x3)))>>2;
		}
		else
		{
			dma_input.count = length>>2;
		}
	}
	
	/* see if it is multiple of max packet length*/
	/* length % 64 */	
	if(length & 0x3f)
	{
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_TRUE;
		/* the last residue packet size */
		g_UsbDrvInfo.dma_pktlength[ep_num - 1] = length&0x3f;
	}
	else
	{
		/* do not need one more packet for the residue of 64 bytes*/
		g_UsbDrvInfo.dma_res_tx_ep = 0;
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;
		/* the last residue packet size */
		g_UsbDrvInfo.dma_pktlength[ep_num - 1] = 0;
	}
	/* Configure DMA */
	DMA_Config_B2W(g_UsbDrvInfo.dma_port[ep_num - 1], &dma_input, KAL_TRUE, dma_menu.TMOD.burst_mode);
	
	/**** Configure Fast mode *****/
	/* length/64*/
	fm_pkt_num = length >> 6 ;
	/* for rx less than 64 bytes packet, pad to receive 64 bytes*/
	if((g_UsbDrvInfo.dma_pktrdy[ep_num - 1] ==KAL_TRUE) && (direction == USB_RX_EP_TYPE))
		fm_pkt_num++;

	/* Setup BDT */
	if(direction == USB_TX_EP_TYPE)	 
	{
		/* Must not set own bit, fast mode engine set it automatically.
		    If own bit is set here, it will cause race condition */
		WRITE_EPN_BDT_PID(ep_num, USB_BDT_TX, 
								(USB_EP_BULK_MAXP << VUSB_BDT_BC_SHIFT) |
								(g_UsbDrvInfo.ep_in_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
								VUSB_BDT_DTS_BIT);
		/* Update data toggle flag*/
		if(fm_pkt_num&0x1)
			g_UsbDrvInfo.ep_in_data01[ep_num-1]^=1;
	}
	else
	{
		/* Must not set own bit, fast mode engine set it automatically.
		    If own bit is set here, it will cause race condition */
		WRITE_EPN_BDT_PID(ep_num, USB_BDT_RX, 
								(USB_EP_BULK_MAXP << VUSB_BDT_BC_SHIFT) |
								(g_UsbDrvInfo.ep_out_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
								VUSB_BDT_DTS_BIT);
		/* Update data toggle flag*/
		if(fm_pkt_num&0x1)
			g_UsbDrvInfo.ep_out_data01[ep_num-1]^=1;
	}
	
	/* Select DMA channel of fm engine*/
	DRV_WriteReg8(USB_DMA_FM_SELECT, fm_dma_index);
	
	/* Set fm endpoint */
	fm_ep = ep_num;
	if(direction == USB_TX_EP_TYPE)
	{
		/* TX endpint */
		fm_ep |= VUSB_FM_EP_TX;
		/* The last packet is not 64 byte */
		if(g_UsbDrvInfo.dma_pktrdy[ep_num - 1] ==KAL_TRUE)
		{
			fm_ep |= VUSB_FM_EP_TX_RES;
		}	
	}

	DRV_WriteReg8(USB_FM_ENDPT, fm_ep);
	
	/* Set transfer number*/
	DRV_WriteReg8(USB_FM_PKT_NUML, fm_pkt_num&0xff);
	DRV_WriteReg8(USB_FM_PKT_NUMH, (fm_pkt_num>>8)&0xff);
	DRV_WriteReg8(USB_FM_PKT_CNTL, 0);
	DRV_WriteReg8(USB_FM_PKT_CNTH, 0);

	/* Enable fast mode only if fm_count > 0*/
	if(fm_pkt_num > 0)
	{
		DRV_WriteReg8(USB_FM_CTL, VUSB_FM_CTL_FMENB);
	}
	else
	{
		/* Enable DMA only for tx with fm_count==0 */
		/* If TX packet length is less than 64 bytes, this conditionis matched */
		g_UsbDrvInfo.fast_mode_tx_ep = 0;
		DRV_WriteReg8(USB_DMA_ENB, 1<<fm_dma_index);
	}
#elif defined(DRV_USB_IP_V1)
	// moduler 4
	if ((length&0x3) || (addr&0x3))
	{
		/* byte transfer */
		dma_input.size = DMA_BYTE; 
		dma_input.count = length;
	}
	else
	{
		/* word transfer */
		dma_input.size = DMA_LONG; 
		dma_input.count = length>>2;
	}

	/* judge if it is mutiple of max packet length*/
	if (length % USB_EP_BULK_MAXP)
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_TRUE;
	else
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;
	
	/* Configure DMA */
	DMA_Config(g_UsbDrvInfo.dma_port[ep_num - 1], &dma_input, KAL_TRUE);
#endif
#endif  /* defined(DRV_USB_IP_V3) */
}


/* get SW DMA running status */
kal_bool USB_DMA_Get_Run_Status(kal_uint8 ep_num, USB_EP_TYPE direction)
{
#if defined(DRV_USB_IP_V3)
	kal_uint8   dma_chan;

	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

	return g_UsbDrvInfo.dma_running[dma_chan-1];
#else
	if(ep_num > MAX_DMA_EP_NUM)
		EXT_ASSERT(0, ep_num, 0, 0);
	return g_UsbDrvInfo.dma_running[ep_num-1];
#endif
}


/* set dma SW running status */
void USB_DMA_Set_Run_Status(kal_uint8 ep_num, USB_EP_TYPE  direction, kal_bool status)
{
#if defined(DRV_USB_IP_V3)
	kal_uint8   dma_chan;

	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

	g_UsbDrvInfo.dma_running[dma_chan-1] = status;
#else
	if(ep_num>MAX_DMA_EP_NUM)
		EXT_ASSERT(0, ep_num, 0, 0);
	g_UsbDrvInfo.dma_running[ep_num-1] = status;
#endif
}


kal_uint32 USB_Get_DMA_Rx_Count(kal_uint8 ep_num)
{
#if defined(DRV_USB_IP_V3)
	return 0;
#elif defined(DRV_USB_IP_V2)
	return 0;
#elif defined(DRV_USB_IP_V1)
	return g_UsbDrvInfo.dma_rx_count[ep_num-1];
#endif
}


#if defined(DRV_USB_IP_V3)
/************************************************************
	USB 2.0 utilities
*************************************************************/
/* Check is high speed or full speed mode, only vaild when USB reset completely */
kal_bool USB_Is_High_Speed(void)
{
	kal_uint8	  usbpower = DRV_Reg8(USB_POWER);

	if((usbpower&USB_POWER_HSMODE) != 0)
		return KAL_TRUE;
	else
		return KAL_FALSE;	
}

static void USB_High_Speed_Enable(void)
{
	DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)|USB_POWER_HSENAB));
}


/* USB soft connect/disconnect */
static void USB_Set_DP_Pull_Up(kal_bool bset)
{
	if(bset == KAL_TRUE)
		DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)|USB_POWER_SOFTCONN));
	else
		DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)&(~USB_POWER_SOFTCONN)));
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
void USB_Enter_Test_Mode(USB_TEST_MODE_TYPE test_selector)
{
	if(test_selector == USB_TEST_MODE_TYPE_J)
		DRV_WriteReg8(USB_TESTMODE, USB_TESTMODE_TESTJ);
	else if(test_selector == USB_TEST_MODE_TYPE_K)
		DRV_WriteReg8(USB_TESTMODE, USB_TESTMODE_TESTK);
	else if(test_selector == USB_TEST_MODE_TYPE_SE0_NAK)
		DRV_WriteReg8(USB_TESTMODE, USB_TESTMODE_TESTSE0NAK);
	else if(test_selector == USB_TEST_MODE_TYPE_PACKET)
		DRV_WriteReg8(USB_TESTMODE, USB_TESTMODE_TESTPACKET);
	else
		ASSERT(0);
}

void USB_Reset_FIFO(void)
{
	g_FIFOadd = USB_FIFO_START_ADDRESS;
}


/************************************************************
        DMA contorl functions
*************************************************************/

static kal_uint8 USB_Get_DMA_Channel_Num(kal_uint8 ep_num, USB_EP_TYPE  direction)
{
	kal_uint8  dma_chan;

	dma_chan = g_UsbDrvInfo.dma_port[direction][ep_num-1];

	if((dma_chan == 0)||(dma_chan > MAX_DMA_EP_NUM)||(ep_num == 0))
		EXT_ASSERT(0, ep_num, MAX_DMA_EP_NUM, 0);

	return dma_chan;
}

static void USB_DMA_Callback(kal_uint8 dma_chan)
{
	usb_dma_callback callback = g_UsbDrvInfo.dma_callback[dma_chan-1];
	g_UsbDrvInfo.dma_callback[dma_chan-1] = NULL;

	USB_Dbg_Trace(USB_DBG_DMA_CALLBACK, drv_get_current_time(), dma_chan, 0);

	if(dma_chan != 0)
	{
		/* ep0 do not do this */
		if(g_UsbDrvInfo.dma_pktrdy[dma_chan-1])
		{
			if(g_UsbDrvInfo.dma_dir[dma_chan-1] == USB_TX_EP_TYPE)
			{
				USB_EP_Bulk_Tx_Ready(g_UsbDrvInfo.dma_ep_num[dma_chan-1]);
#ifdef __USB_AUTO_SET__
				if(((g_UsbDrvInfo.dma_ep_num[dma_chan-1] == 1)&&(dma_chan == 2))||
					((g_UsbDrvInfo.dma_ep_num[dma_chan-1] == 2)&&(dma_chan == 3))||  
						((g_UsbDrvInfo.dma_ep_num[dma_chan-1] == 3)&&(dma_chan == 4))) 
				{
					ASSERT(0);
				}
#endif
			}
			else if(g_UsbDrvInfo.dma_dir[dma_chan-1] == USB_RX_EP_TYPE)
			{
				/* not assert in unknow size RX*/
//				ASSERT(0);
				USB_EP_Bulk_Rx_Ready(g_UsbDrvInfo.dma_ep_num[dma_chan-1]);
			}
		}
	}


	g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_FALSE;

	/* if application callback function does not request to clear drv_running set by itself, clear running state here*/
	if(g_UsbDrvInfo.dma_callback_upd_run[dma_chan-1] == KAL_FALSE)
	{
		g_UsbDrvInfo.dma_running[dma_chan-1] = KAL_FALSE;
	}

	if(callback != NULL)
		callback();

//	if(g_UsbDrvInfo.dma_callback[dma_chan-1] != NULL)
//		g_UsbDrvInfo.dma_callback[dma_chan-1]();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __DMA_UNKNOWN_RX__
/* This function only be used at RX pipe to receive unknown size */
kal_uint32 USB_DMA_Get_Rx_Count(kal_uint8 ep_num)
{
	kal_uint8   dma_chan;
	kal_uint32  rx_byte;

	dma_chan = USB_Get_DMA_Channel_Num(ep_num, USB_RX_EP_TYPE);

	rx_byte = g_UsbDrvInfo.dma_length[ep_num-1] -DRV_Reg32(USB_DMACNT(dma_chan));

	return rx_byte;
}

kal_uint32 USB_DMA_Get_Rx_Address(kal_uint8 ep_num)
{
	return g_UsbDrvInfo.dma_addr[ep_num-1];
}

#endif


#ifdef __DMA_PP_ENABLE__

kal_uint32 USB_Get_DMA_PP_Real_Count(kal_uint8 ep_num, USB_EP_TYPE  direction)
{
	return DRV_Reg32(USB_DMA_PP_REALCNT(g_UsbDrvInfo.dma_port[direction][ep_num-1]));
}


/* get DMA PP SW running status */
kal_bool USB_DMA_Get_PP_Run_Status(kal_uint8 ep_num, USB_EP_TYPE  direction, kal_bool is_dma_pp_b)
{
	kal_uint8   dma_chan;

	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

	return g_UsbDrvInfo.dma_is_running[is_dma_pp_b][dma_chan];
}


kal_uint32 USB_Get_DMA_PP_Real_Count(kal_uint8 ep_num, USB_EP_TYPE direction)
{
	return DRV_Reg32(USB_DMA_PP_REALCNT(g_UsbDrvInfo.dma_port[direction][ep_num-1]));
}

void USB_Set_DMA_Serve_Ptr(kal_uint8 ep_num, USB_EP_TYPE  direction, kal_bool set)
{
	kal_uint8  dma_channel;

	dma_channel = USB_Get_DMA_Channel_Num(ep_num, direction);
	ASSERT(dma_channel != 0);

	g_UsbDrvInfo.dma_is_pp[dma_channel] = set;
}


kal_bool USB_DMA_Is_Serve_PP(kal_uint8 ep_num, USB_EP_TYPE  direction)
{
	kal_uint8  dma_channel;

	dma_channel = USB_Get_DMA_Channel_Num(ep_num, direction);
	ASSERT(dma_channel != 0);

	return g_UsbDrvInfo.dma_is_pp[dma_channel];
}


kal_bool USB_Check_Is_DMA_Pendding_Interrupt(kal_uint8 ep_num, USB_EP_TYPE  direction)
{
	kal_uint8  dma_channel;
	kal_uint8  dma_intr;

	dma_channel = USB_Get_DMA_Channel_Num(ep_num, direction);
	ASSERT(dma_channel != 0);

	g_UsbDrvInfo.dma_status1 = DRV_Reg8(USB_DMAINTR);

	if((g_UsbDrvInfo.dma_status1&(0x01<<(dma_channel-1))) == 0)
		return KAL_FALSE;
	else
		return KAL_TRUE;
}


void USB_Clear_DMA_Interrupt(kal_uint8 ep_num, USB_EP_TYPE direction)
{
	kal_uint8  dma_channel;

	dma_channel = USB_Get_DMA_Channel_Num(ep_num, direction);
	ASSERT(dma_channel != 0);

	DRV_WriteReg32(USB_DMAINTR, ~(0x01<<(dma_channel-1)));
//	DRV_WriteReg8(USB_DMAINTR, ~(0x01<<(dma_channel-1)));
	g_UsbDrvInfo.dma_status2 = DRV_Reg8(USB_DMAINTR);
}


void USB_Clear_DMA_HW_Run_Status(kal_uint8 ep_num, USB_EP_TYPE direction)
{
	kal_uint8  dma_channel;

	dma_channel = USB_Get_DMA_Channel_Num(ep_num, direction);
	ASSERT(dma_channel != 0);

	g_UsbDrvInfo.dma_finish_status1 = DRV_Reg32(USB_DMAINTR);
	DRV_WriteReg32(USB_DMAINTR, ~(0x010000<<((dma_channel-1)*2)));
	g_UsbDrvInfo.dma_finish_status2 = DRV_Reg32(USB_DMAINTR);


//	g_UsbDrvInfo.dma_finish_status1 = DRV_Reg(USB_DMAPPINTR);
//	DRV_WriteReg(USB_DMAPPINTR, ~(0x01<<((dma_channel-1)*2)));
//	g_UsbDrvInfo.dma_finish_status2 = DRV_Reg(USB_DMAPPINTR);
}


kal_bool USB_Get_DMA_HW_Run_Status(kal_uint8 ep_num, USB_EP_TYPE direction)
{
	kal_uint8    dma_channel;
	kal_uint32   dma_finish_status;

	dma_channel = USB_Get_DMA_Channel_Num(ep_num, direction);
	ASSERT(dma_channel != 0);

	dma_finish_status = DRV_Reg32(USB_DMAINTR);
//	dma_finish_status = DRV_Reg(USB_DMAPPINTR);
	g_UsbDrvInfo.dma_finish_status1 = dma_finish_status;

//	if((dma_finish_status&(0x01<<((dma_channel-1)*2))) == 0)
	if((dma_finish_status&(0x010000<<((dma_channel-1)*2))) == 0)
		return  KAL_TRUE;
	else
		return  KAL_FALSE;
}


void USB_Clear_DMA_PP_HW_Run_Status(kal_uint8 ep_num, USB_EP_TYPE direction)
{
	kal_uint8  dma_channel;

	dma_channel = USB_Get_DMA_Channel_Num(ep_num, direction);
	ASSERT(dma_channel != 0);

	g_UsbDrvInfo.dma_finish_status1 = DRV_Reg32(USB_DMAINTR);
	DRV_WriteReg32(USB_DMAINTR, ~(0x010000<<((dma_channel*2)-1)));
	g_UsbDrvInfo.dma_finish_status2 = DRV_Reg32(USB_DMAINTR);

//	g_UsbDrvInfo.dma_finish_status1 = DRV_Reg(USB_DMAPPINTR);
//	DRV_WriteReg(USB_DMAPPINTR, ~(0x01<<((dma_channel*2)-1)));
//	g_UsbDrvInfo.dma_finish_status2 = DRV_Reg(USB_DMAPPINTR);
}


kal_bool USB_Get_DMA_PP_HW_Run_Status(kal_uint8 ep_num, USB_EP_TYPE direction)
{
	kal_uint8  dma_channel;
	kal_uint32  dma_finish_status;

	dma_channel = USB_Get_DMA_Channel_Num(ep_num, direction);
	ASSERT(dma_channel != 0);

	dma_finish_status = DRV_Reg32(USB_DMAINTR);

//	dma_finish_status = DRV_Reg(USB_DMAPPINTR);
//	if((dma_finish_status&(0x01<<((dma_channel*2)-1))) == 0)
	if((dma_finish_status&(0x010000<<((dma_channel*2)-1))) == 0)
		return  KAL_TRUE;
	else
		return  KAL_FALSE;
}


void USB_DMA_PP_Setup(kal_uint8 ep_num, USB_EP_TYPE direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr1, kal_uint32 length1, 
			kal_uint32 addr2, kal_uint32 length2, usb_dma_callback callback, kal_bool callback_upd_run, 
					USB_DMA_TYPE dma_type, kal_bool first_time, kal_bool set_a_first)
{
	kal_uint16  dma_ctrl;
	kal_uint8    dma_chan;
	kal_uint16  CSR;
	kal_uint16  IntrOut;
	kal_uint32  savedMask;


	usb_device_dma_burst_mode++;


	if(direction == USB_TX_EP_TYPE)
	{
		if(ep_num > USB_MAX_EP_BULK_IN)
			ASSERT(0);
	}
	else if(direction == USB_RX_EP_TYPE)
	{
		if(ep_num > USB_MAX_EP_BULK_OUT)
			ASSERT(0);
	}

	if((ep_num != 0)&&(ep_type == USB_ENDPT_CTRL))
	{
		dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);
		ASSERT(dma_chan != 0);
	
		if(dma_chan > MAX_DMA_EP_NUM)
			EXT_ASSERT(0, ep_num, MAX_DMA_EP_NUM, 0);	

		if(g_UsbDrvInfo.ep_with_one_dma[ep_num-1] == KAL_TRUE)
		{
			g_UsbDrvInfo.dma_dir[dma_chan-1] = direction;
		}
		else
		{
			if(g_UsbDrvInfo.dma_dir[dma_chan-1] != direction)
				EXT_ASSERT(0, dma_chan-1, g_UsbDrvInfo.dma_dir[dma_chan-1], direction);
		}
	}
	else
	{
		ASSERT(0);
	}

#if 0
/* under construction !*/
#endif

	ASSERT(g_UsbDrvInfo.dma_running[dma_chan-1] == KAL_FALSE);
	g_UsbDrvInfo.dma_running[dma_chan-1] = KAL_TRUE;
	g_UsbDrvInfo.dma_callback[dma_chan-1] = callback;
	g_UsbDrvInfo.dma_callback_upd_run[dma_chan-1] = callback_upd_run;
	g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_FALSE;
	g_UsbDrvInfo.dma_is_running[0][dma_chan] = KAL_FALSE;
	g_UsbDrvInfo.dma_is_running[1][dma_chan] = KAL_FALSE;


#ifndef __USB_AUTO_SET__
	ASSERT(0);
#endif

//#ifndef __USB_AUTO_CLEAR__
//	ASSERT(0);
//#endif


	// auto clear can use on all channels
	// auto set only can use on "ep1 with channel 2", "ep2 with channel 3", and "ep3 with channel 4"
	/* Judge if it is multiple of max packet length */
	if(direction == USB_TX_EP_TYPE)
	{
		if(((ep_num != 1)||(dma_chan != 2))&&((ep_num != 2)||(dma_chan != 3))&&((ep_num != 3)||(dma_chan != 4)))
		{
			ASSERT(0);
		}
	}


	/* DMA_CONFIG */
	if(direction == USB_TX_EP_TYPE)
	{
//			g_UsbDrvInfo.TXCSR = DRV_Reg(USB_TXCSR);
//			g_UsbDrvInfo.RXCSR = DRV_Reg(USB_RXCSR);

		if(length1 != 0)
		{
			g_UsbDrvInfo.dma_is_running[0][dma_chan] = KAL_TRUE; 	/* is PP A running */
			DRV_WriteReg32(USB_DMAADDR(dma_chan), addr1);
			DRV_WriteReg32(USB_DMACNT(dma_chan), length1);
		}

		if(length2 != 0)
		{
			g_UsbDrvInfo.dma_is_running[1][dma_chan] = KAL_TRUE;  /* is PP B running */
			DRV_WriteReg32(USB_DMAPPADDR(dma_chan), addr2);
			DRV_WriteReg32(USB_DMAPPCNT(dma_chan), length2);
		}


		if(first_time == KAL_TRUE)
		{
			g_UsbDrvInfo.dma_is_pp[dma_chan] = KAL_FALSE; 		/* initial is PP A */
			// short pkt auto set
			DRV_WriteReg8(USB_INDEX, ep_num);

			if(ep_type == USB_ENDPT_ISO)
			{
				DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_AUTOSET_SPKT|USB_TXCSR_ISO));
			}
			else 
			{
				DRV_WriteReg(USB_TXCSR, (USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_AUTOSET_SPKT));
			}
			dma_ctrl = USB_DMACNTL_DMADIR|USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|USB_DMACNTL_BURSTMODE_MASK;
			dma_ctrl |= ((usb_device_dma_burst_mode&0x03)<<9);
			dma_ctrl |= (ep_num<<4)|USB_DMACNTL_DMAEN|USB_DMACNTL_PPEN|USB_DMACNTL_PPRST;
		}
		else
		{
			dma_ctrl = DRV_Reg(USB_DMACNTL(dma_chan));
			dma_ctrl &= ~(USB_DMACNTL_PPRST);
			dma_ctrl |= USB_DMACNTL_DMAEN;
		}

		savedMask = SaveAndSetIRQMask();

		if(g_UsbDrvInfo.dma_is_running[0][dma_chan] == KAL_TRUE)
			DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);

		if(g_UsbDrvInfo.dma_is_running[1][dma_chan] == KAL_TRUE)
			DRV_WriteReg(USB_DMAPPCNTL(dma_chan), USB_DMACNTL_DMAEN);

		RestoreIRQMask(savedMask);
	}
	else	 if(direction == USB_RX_EP_TYPE)
	{
		if(length1 != 0)
		{
			g_UsbDrvInfo.dma_is_running[0][dma_chan] = KAL_TRUE; 	/* is PP A running */
			DRV_WriteReg32(USB_DMAADDR(dma_chan), addr1);
			DRV_WriteReg32(USB_DMACNT(dma_chan), length1);
		}

		if(length2 != 0)
		{
			g_UsbDrvInfo.dma_is_running[1][dma_chan] = KAL_TRUE; 	/* is PP B running */
			DRV_WriteReg32(USB_DMAPPADDR(dma_chan), addr2);
			DRV_WriteReg32(USB_DMAPPCNT(dma_chan), length2);
		}

		if(first_time == KAL_TRUE)
		{
			DRV_WriteReg8(USB_INDEX, ep_num);

			if(ep_type == USB_ENDPT_ISO)
			{
//				DRV_WriteReg(USB_RXCSR, USB_RXCSR_AUTOCLREN_SPKT|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOCLEAR|USB_RXCSR_ISO);
				DRV_WriteReg(USB_RXCSR, USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOCLEAR|USB_RXCSR_ISO);

			}
			else
			{
//				DRV_WriteReg(USB_RXCSR, USB_RXCSR_AUTOCLREN_SPKT|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOCLEAR);
				DRV_WriteReg(USB_RXCSR, USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOCLEAR);
			}

			g_UsbDrvInfo.dma_is_pp[dma_chan] = KAL_FALSE; 			/* initial is PP A */		
			dma_ctrl = USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|USB_DMACNTL_BURSTMODE_MASK|USB_DMACNTL_PPEN|USB_DMACNTL_PPRST;
			dma_ctrl |= ((usb_device_dma_burst_mode&0x03)<<9);

			if(dma_type == USB_DMA2_TYPE)
			{
				dma_ctrl |= (ep_num<<4)|USB_DMACNTL_DMAEN|USB_DMACNTL_ENDMAMODE2;
			}
			else if (dma_type == USB_DMA1_TYPE)
			{
				dma_ctrl |= (ep_num<<4)|USB_DMACNTL_DMAEN;
			}
		}
		else
		{
			dma_ctrl = DRV_Reg(USB_DMACNTL(dma_chan));
			dma_ctrl &= ~(USB_DMACNTL_PPRST);
			dma_ctrl |= USB_DMACNTL_DMAEN;		
		}

		savedMask = SaveAndSetIRQMask();

		if(g_UsbDrvInfo.dma_is_running[0][dma_chan] == KAL_TRUE)
			DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);

		if(g_UsbDrvInfo.dma_is_running[1][dma_chan] == KAL_TRUE)
			DRV_WriteReg(USB_DMAPPCNTL(dma_chan), USB_DMACNTL_DMAEN);

		RestoreIRQMask(savedMask);
	}
}



#endif


#else  /* defined(DRV_USB_IP_V3)  */



/* DMA callback for endpoint 1*/
static void USB_DMA_Callback_EP1(void)
{
	kal_uint32 ep_num = 1;
	usb_dma_callback callback = g_UsbDrvInfo.dma_callback[ep_num-1];

#if defined(DRV_USB_IP_V2)
	kal_uint32 		fm_dma_index;
#endif

	if(g_UsbDrvInfo.dma_dir[ep_num-1] == USB_RX_EP_TYPE)
	{
		g_UsbDrvInfo.dma_rx_count[ep_num-1] = USB_EP_Rx_Pkt_Len(ep_num);
	}

#if defined(DRV_USB_IP_V2)
	/* clear tx dma ep flag */
	g_UsbDrvInfo.dma_tx_ep = 0;
	
	if(g_UsbDrvInfo.dma_dir[ep_num-1] == USB_TX_EP_TYPE)
		fm_dma_index = VUSB_FM_DMA_TX1;
	else
		fm_dma_index = VUSB_FM_DMA_RX1;

	/* disable DMA*/
	DRV_WriteReg8(USB_DMA_DIS, 1<<fm_dma_index);
#endif

	USB_Dbg_Trace(USB_DBG_DMA_CALLBACK, drv_get_current_time(), 0, 0);

	g_UsbDrvInfo.dma_callback[ep_num-1] = NULL;

	/* the last one pkt length not multiple of MAX_PKT_LEN, clear corresponding bits*/	
	if (g_UsbDrvInfo.dma_pktrdy[ep_num-1])
	{
#if defined(DRV_USB_IP_V2)
		if(g_UsbDrvInfo.dma_dir[ep_num-1] == USB_TX_EP_TYPE)
	{
			/* tx, config the last one packet */
			WRITE_EPN_BDT_PID(ep_num, USB_BDT_TX, 
									(g_UsbDrvInfo.dma_pktlength[ep_num-1] << VUSB_BDT_BC_SHIFT) |
									(g_UsbDrvInfo.ep_in_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
									VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
			g_UsbDrvInfo.ep_in_data01[ep_num-1]^=1;
		}
		else
		{
			/* rx, the last one already recevd*/
			/* nothing need to do */
		}
#elif defined(DRV_USB_IP_V1)	
		if(g_UsbDrvInfo.dma_dir[ep_num-1] == USB_TX_EP_TYPE)
		{
			USB_EP_Bulk_Tx_Ready(ep_num);
		}
		else
		{
			USB_EP_Bulk_Rx_Ready(ep_num);
		}
#endif		
	}

	g_UsbDrvInfo.dma_pktrdy[ep_num-1] = KAL_FALSE;

	/* if application callback function does not request to clear drv_running set by itself, clear running state here*/
	if(g_UsbDrvInfo.dma_callback_upd_run[ep_num-1] == KAL_FALSE)
		g_UsbDrvInfo.dma_running[ep_num-1] = KAL_FALSE;

#if defined(DRV_USB_IP_V2)
	if((g_UsbDrvInfo.dma_res_tx_ep==0)&&(g_UsbDrvInfo.fast_mode_tx_ep==0)&&(callback!=NULL))
	{
		callback();
	}
	else
	{
		//re-save callbcak function, wait until fast mode complete intr or the last pkt token done intr
		g_UsbDrvInfo.dma_callback[ep_num-1] = callback;	
	}
#elif defined(DRV_USB_IP_V1)
	if(callback != NULL)
		callback();
#endif	
}

#ifdef USB_SUPPORT_MUTIPLE_APP
/* DMA callback for endpoint 2*/
static void USB_DMA_Callback_EP2(void)
{
	kal_uint32 ep_num = 2;
	usb_dma_callback callback = g_UsbDrvInfo.dma_callback[ep_num-1];

#if defined(DRV_USB_IP_V2)
	kal_uint32 		fm_dma_index;

	g_UsbDrvInfo.dma_tx_ep = 0;

	if(g_UsbDrvInfo.dma_dir[ep_num-1] == USB_TX_EP_TYPE)
		fm_dma_index = VUSB_FM_DMA_TX2;
	else
		fm_dma_index = VUSB_FM_DMA_RX2;

	/* disable DMA*/
	DRV_WriteReg8(USB_DMA_DIS, 1<<fm_dma_index);
#endif

	g_UsbDrvInfo.dma_callback[ep_num-1] = NULL;

	/* the last one pkt length not multiple of MAX_PKT_LEN, clear corresponding bits*/	
	if (g_UsbDrvInfo.dma_pktrdy[ep_num-1])
	{
#if defined(DRV_USB_IP_V2)	
		if(g_UsbDrvInfo.dma_dir[ep_num-1] == USB_TX_EP_TYPE)
	{
			/* tx, config the last one packet */
			/* tx, config the last one packet */
			WRITE_EPN_BDT_PID(ep_num, USB_BDT_TX, 
									(g_UsbDrvInfo.dma_pktlength[ep_num-1] << VUSB_BDT_BC_SHIFT) |
									(g_UsbDrvInfo.ep_in_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
									VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
			g_UsbDrvInfo.ep_in_data01[ep_num-1]^=1;
		}
		else
		{
			/* rx, the last one already recevd*/
			/* nothing need to do */
		}
#elif defined(DRV_USB_IP_V1)	
		if(g_UsbDrvInfo.dma_dir[ep_num-1] == USB_TX_EP_TYPE)
			USB_EP_Bulk_Tx_Ready(ep_num);
		else
			USB_EP_Bulk_Rx_Ready(ep_num);
#endif		
	}

	g_UsbDrvInfo.dma_pktrdy[ep_num-1] = KAL_FALSE;

	/* if application callback function dose not request to clear drv_runnung set by itself, clear running state here*/
	if(g_UsbDrvInfo.dma_callback_upd_run[ep_num-1] == KAL_FALSE)
		g_UsbDrvInfo.dma_running[ep_num-1] = KAL_FALSE;

#if defined(DRV_USB_IP_V2)
	if((g_UsbDrvInfo.dma_res_tx_ep==0)&&(g_UsbDrvInfo.fast_mode_tx_ep==0)&&(callback!=NULL))
	{
		callback();
	}
	else
	{
		//re-save callbcak function, wait until fast mode complete intr or the last pkt token done intr
		g_UsbDrvInfo.dma_callback[ep_num-1] = callback;	
	}
#elif defined(DRV_USB_IP_V1)
	if(callback != NULL)
		callback();
#endif
}
#endif /* USB_SUPPORT_MUTIPLE_APP */


#endif   /* defined(DRV_USB_IP_V3)  */


/************************************************************
	polling functions (used for exception log) 
*************************************************************/

/* 
    Add for retrive exception log 
    If there is data under transmitting, polling it and block until transmit done  
*/
void USB_Polling_Transmit_Done(kal_uint8 ep_num)
{
#if defined(DRV_USB_IP_V3)
	kal_uint8   dma_chan;
#elif defined(DRV_USB_IP_V2)
	volatile kal_uint32	delay;
	kal_uint32 		fm_dma_index;
#endif

	/* This function can only be called after exception*/
	if(INT_Exception_Enter == 0)
		EXT_ASSERT(0, 0, 0, 0);
		
#if defined (DRV_USB_IP_V3)
	dma_chan = USB_Get_DMA_Channel_Num(ep_num, USB_TX_EP_TYPE);

	/* error case, should it?? */
	if(g_UsbDrvInfo.dma_port[USB_TX_EP_TYPE][ep_num - 1] == 0)
		return;

	/* polling until DMA done */
	while (USBDMA_CheckRunStat(dma_chan))
	{
		/* check if other interrupt received */
		g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
		USB_HISR();
	}

	DRV_WriteReg8(USB_DMAINTR, ~(0x01<<(dma_chan-1)));

#else
	/* error case*/
	if(g_UsbDrvInfo.dma_port[ep_num - 1] == 0)
		return;

	/* polling until DMA done */
	while (DMA_CheckRunStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
	{
		/* check if other interrupt received*/
		g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
		USB_HISR();
	}

	if (DMA_CheckITStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
	{	
		DMA_ACKI(g_UsbDrvInfo.dma_port[ep_num - 1]);
	}
#endif

#if defined(DRV_USB_IP_V2)
	for(delay=0; delay<100; delay++)
	{}

	/* clear tx dma ep flag */
	g_UsbDrvInfo.dma_tx_ep = 0;
	if(g_UsbDrvInfo.dma_dir[ep_num-1] == USB_TX_EP_TYPE)
		fm_dma_index = VUSB_FM_DMA_TX1;
	else
		fm_dma_index = VUSB_FM_DMA_RX1;
	/* disable DMA*/
	DRV_WriteReg8(USB_DMA_DIS, 1<<fm_dma_index);
#endif

	/* the last one pkt length not multiple of MAX_PKT_LEN, clear corresponding bits*/	
	if (g_UsbDrvInfo.dma_pktrdy[ep_num - 1])
	{
		if(g_UsbDrvInfo.dma_dir[ep_num-1] != USB_TX_EP_TYPE)
		{
			EXT_ASSERT(0, g_UsbDrvInfo.dma_dir[ep_num-1], 0, 0);	
		}
#if defined(DRV_USB_IP_V3)
		USB_EP_Bulk_Tx_Ready(ep_num);
#elif defined(DRV_USB_IP_V2)	
		/* TX, config the last one packet */
		WRITE_EPN_BDT_PID(ep_num, USB_BDT_TX, 
				(g_UsbDrvInfo.dma_pktlength[ep_num-1] << VUSB_BDT_BC_SHIFT) |
				(g_UsbDrvInfo.ep_in_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
				VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);

		g_UsbDrvInfo.ep_in_data01[ep_num-1] ^= 1;
#elif defined(DRV_USB_IP_V1)
		USB_EP_Bulk_Tx_Ready(ep_num);
#endif
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;
	}
	else
	{
#if defined(DRV_USB_IP_V2)
		/* wait fm done for USB module */
		while(g_UsbDrvInfo.fast_mode_tx_ep!=0)
		{
			g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
			USB_HISR();
		}
#endif		
	}
	
#if defined(DRV_USB_IP_V3)
	while(USB_Is_EP_Bulk_Tx_Empty(ep_num) == KAL_FALSE)
#elif defined(DRV_USB_IP_V2)
	while((USB_Is_EP_Bulk_Tx_Empty(ep_num)==KAL_FALSE)||(g_UsbDrvInfo.dma_res_tx_ep!=0))
#elif defined(DRV_USB_IP_V1)
	/* polling the last packet*/
	while(USB_Is_EP_Bulk_Tx_Empty(ep_num)==KAL_FALSE)
#endif		
	{
		/* check if other interrupt received*/
		g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
		USB_HISR();
	}
	
	g_UsbDrvInfo.dma_running[ep_num-1] = KAL_FALSE;
}

/* 
    Add for retrive exception log 
    Config DMA to transmit data and polling until it is done
*/
void USB_Polling_Transmit_Data(kal_uint8 ep_num, USB_EP_TYPE  direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
				usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type)
{		
	/* config DMA to transmit data*/
	USB_DMA_Setup(ep_num, direction, ep_type, addr, length, callback, callback_upd_run, known_size, dma_type);

	/* wait for transmit done*/
	USB_Polling_Transmit_Done(ep_num);
}

/* 
    Add for retrive exception log 
    Polling if there is any data received or other interrupts
*/
void USB_Polling_Recv_Data(kal_uint8 ep_num)
{
	/* This function can only be called after exception*/
	if(INT_Exception_Enter == 0)
		EXT_ASSERT(0, 0, 0, 0);
		
	g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
	USB_HISR();
}


/************************************************************
	HISR/LISR   interrupt handler
*************************************************************/

#if defined(DRV_USB_IP_V3)
static void USBDMA_HISR(void)
{
	kal_uint8  	DMAIntr;
	kal_uint32  	index;
	kal_uint16  	dma_ctrl;

	
	DMAIntr = DRV_Reg8(USB_DMAINTR);

	if(DMAIntr == 0)
		ASSERT(0);

	do
	{
		for (index = 0; index < MAX_DMA_EP_NUM; index++)
		{
			if((DMAIntr&(1<<index)) != 0)
			{
				// write 0 clear first, then do call back function, order is very important !!!
				DRV_WriteReg8(USB_DMAINTR, ~(0x01<<index));

				/* DMA channel index+1 have interrupt */
#ifdef __DMA_PP_ENABLE__

				USB_DMA_Callback(index+1);

#else  /* __DMA_PP_ENABLE__ */

				if((DRV_Reg32(USB_DMA_REALCNT(index+1))) != 0)
				{
					USB_DMA_Callback(index+1);
				}
				else
				{
					// DMA timer time out
					if(index == 0)
					{
						// set address
						USB_DMA_Callback(index+1);
					}
					else
					{
						dma_ctrl = DRV_Reg(USB_DMACNTL(index+1));
						DRV_WriteReg(USB_DMACNTL(index+1), (dma_ctrl|USB_DMACNTL_DMAEN));
					}
				}
#endif  /* __DMA_PP_ENABLE__ */
			}
		}

		/* Read register again to see if any interrupt is generated again */
		/* if pong pong buffer serve done, then we do call back function here */
		DMAIntr = DRV_Reg8(USB_DMAINTR);
	}while(DMAIntr != 0);

	IRQClearInt(IRQ_USBDMA_CODE);
	IRQUnmask(IRQ_USBDMA_CODE);
}


static void USBDMA_LISR(void)
{
	IRQMask(IRQ_USBDMA_CODE);
	drv_active_hisr(DRV_USBDMA_HISR_ID);
}

#endif


void USB_HISR(void)
{
#if defined(DRV_USB_IP_V3)
	kal_uint8    IntrUSB;
	kal_uint16  IntrTx;
	kal_uint16  IntrRx;
	kal_uint32  ep_num;


	// read and clear!!
	IntrUSB = DRV_Reg8(USB_INTRUSB);
	IntrTx = DRV_Reg(USB_INTRTX);
	// Write 0 clear
	IntrRx = DRV_Reg(USB_INTRRX);
	if(IntrRx != 0)
		DRV_WriteReg(USB_INTRRX, ~IntrRx);

	USB_Dbg_Trace(USB_DBG_HISR, drv_get_current_time(), 0, 0);

	// Reset must be the highest priority ISR
	/* Check for reset interrupt */
	if(IntrUSB&USB_INTRUSB_RESET)
	{
		if(g_UsbDrvInfo.reset_hdlr == NULL)
			ASSERT(0);
		g_UsbDrvInfo.reset_hdlr();
	}

	if(IntrUSB & USB_INTRUSB_DISCON)
	{
		USB_Dbg_Trace(USB_HISR_DISCON, drv_get_current_time(), 0, 0);
	}

	/* Check for resume from suspend mode */
	if (IntrUSB & USB_INTRUSB_RESUME)
	{
		USB_Drv_Resume();
   		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
   	}

	/* Check for endpoint 0 interrupt */
   	if (IntrTx&USB_INTRTX_EP0)
   	{
		if(g_UsbDrvInfo.ep0_hdlr == NULL)
			ASSERT(0);
		g_UsbDrvInfo.ep0_hdlr();
   	}

	/* Check for Bulk TX interrupt */
	for(ep_num = 1; ep_num <= MAX_INTR_EP_NUM; ep_num++)	
	{
		if (IntrTx&(0x01 <<ep_num))
		{
			if(g_UsbDrvInfo.ep_tx_hdlr[ep_num-1] != NULL)
			{
				g_UsbDrvInfo.ep_tx_hdlr[ep_num -1]();
			}
			else
			{
#ifdef  __PRODUCTION_RELEASE__			
				USB_CtrlEPStall(ep_num, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_4);
#else
				/* Save debug info */
				DRV_WriteReg8(USB_INDEX, ep_num);
				g_UsbDrvInfo.CSR = DRV_Reg(USB_TXCSR);
				g_UsbDrvInfo.INTRE = DRV_Reg8(USB_INTRTXE);
				/* if EP dose not support ep_hdr, its interrupt should not be triggered */
				EXT_ASSERT(0, ep_num, 0, 0); 
#endif
			}
		}
	}

	/* Check for Bulk out interrupt */
	for(ep_num = 1; ep_num < MAX_INTR_EP_NUM; ep_num++)
	{
		if(IntrRx&(0x01<<ep_num))
		{
			if(g_UsbDrvInfo.ep_rx_hdlr[ep_num-1] != NULL)
			{
				g_UsbDrvInfo.ep_rx_hdlr[ep_num -1]();
			}
			else
			{
#ifdef  __PRODUCTION_RELEASE__			
				USB_CtrlEPStall(ep_num, USB_RX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_4);
#else
				/* Save debug info */
				DRV_WriteReg8(USB_INDEX, ep_num);
				g_UsbDrvInfo.CSR = DRV_Reg(USB_RXCSR);
				g_UsbDrvInfo.INTRE = DRV_Reg8(USB_INTRRXE);
				/* if EP dose not support ep_hdr, its interrupt should not be triggered */
				EXT_ASSERT(0, ep_num, 0, 0); 
#endif
			}
		}
	}

	/* Check for suspend mode */
	if (IntrUSB&USB_INTRUSB_SUSPEND)
	{
		USB_Drv_Suspend();
		g_UsbDrvInfo.power_state = USB_STATE_SUSPEND;
	}
   	
	/* clear interrupt and unmask interrupt if application agree on it */
	IRQClearInt(IRQ_USB_CODE);
	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;

	if (g_UsbDrvInfo.is_unMaskUSB == KAL_TRUE)
		IRQUnmask(IRQ_USB_CODE);

#elif defined(DRV_USB_IP_V2)
	volatile kal_uint8	IntrStatus;
	volatile kal_uint8	FMStatus;
	volatile kal_uint8	ErrorStatus;
	volatile kal_uint8	PhyStatus;
	volatile kal_uint8	direction;
	volatile kal_uint8	even_odd;
	volatile kal_uint8	ep_num;	
	volatile kal_uint8	usb_ctrl;
	volatile kal_bool	fast_mode_enable;	  
	usb_dma_callback	callback;


	fast_mode_enable = (DRV_Reg8(USB_FM_CTL)&VUSB_FM_CTL_FMENB) ? KAL_TRUE : KAL_FALSE;
	IntrStatus = DRV_Reg8(USB_INT_STAT);
	FMStatus = DRV_Reg8(USB_FM_ERR_STAT);
	ErrorStatus = DRV_Reg8(USB_ERR_STAT);
	PhyStatus = DRV_Reg8(USB_PHY_EXTRA);

//	USB_Ms_Dbg_Trace(OTG_DEVICE_INTR, IntrStatus);
	USB_Dbg_Trace(USB_DBG_HISR, drv_get_current_time(), IntrStatus, 0);

	if (PhyStatus & VUSB_PHY_RESUME_INT)
	{
		DRV_WriteReg8(USB_PHY_EXTRA, PhyStatus & (~VUSB_PHY_SUSPEND));
 		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;		
 		USB_Drv_Resume();
	} /* End resume */

	if (IntrStatus & VUSB_INT_STAT_RESET)
	{
		USB_Drv_Resume();
		USB_Initialize_Drv();
		if(g_UsbDrvInfo.reset_hdlr == NULL)
			EXT_ASSERT(0, 0, 0, 0);
   		g_UsbDrvInfo.reset_hdlr();

		/* Clear interrupt */
		DRV_WriteReg8(USB_FM_ERR_STAT, FMStatus&(0x07));
		DRV_WriteReg8(USB_ERR_STAT, ErrorStatus);		
		DRV_WriteReg8(USB_INT_STAT, IntrStatus);

	#ifndef __OTG_ENABLE__
		/* clear interrupt and unmask interrupt if application agree on it */
   		IRQClearInt(IRQ_USB_CODE);
   		if (g_UsbDrvInfo.is_unMaskUSB==KAL_TRUE)
   			IRQUnmask(IRQ_USB_CODE);
	#endif 
		return;
	} /* End VUSB_INT_STAT_RESET */

#ifdef __OTG_ENABLE__	
	if((OTG_Get_State()==OTG_STATE_A_PERIPHERAL) || (OTG_Get_State()==OTG_STATE_B_PERIPHERAL))
	{
#endif	
		/* Ignore VUSB_INT_STAT_TOKEN_DONE in fast mode */
		if(((IntrStatus&VUSB_INT_STAT_TOKEN_DONE)&&(fast_mode_enable==KAL_FALSE)) || (FMStatus&VUSB_FM_ERR_STAT_TOKEN_DONE))
		{
			/* Parse FM status first */		
			if(FMStatus&VUSB_FM_ERR_STAT_TOKEN_DONE)
			{
				direction = (DRV_Reg8(USB_FM_ADDITNL_STAT) >> 3) & 0x01;
				even_odd = (DRV_Reg8(USB_FM_ADDITNL_STAT) >> 2) & 0x01;
				ep_num = (DRV_Reg8(USB_FM_ADDITNL_STAT) >> 4) & 0x0f;
			}
			else
			{
				direction = (DRV_Reg8(USB_STAT) >> 3) & 0x01;
				even_odd = (DRV_Reg8(USB_STAT) >> 2) & 0x01;
				ep_num = (DRV_Reg8(USB_STAT) >> 4) & 0x0f;
			}

			/* Note that token done should be cleared here in case FM is set during ep handler, 
			     so that intr will move to fm_intr*/
			/* Ignore token done in fast mode, so no clear its intr status in FM */
			/* First handle VUSB_FM_ERR_STAT_TOKEN_DONE, so do not clear token done intr status */
			if((fast_mode_enable==KAL_TRUE) || (FMStatus&VUSB_FM_ERR_STAT_TOKEN_DONE)) 
			{
				DRV_WriteReg8(USB_FM_ERR_STAT, FMStatus);
			}
			else
			{
				DRV_WriteReg8(USB_INT_STAT, (IntrStatus&VUSB_INT_STAT_TOKEN_DONE));
			}
			
			if(ep_num==0)
			{
				g_UsbDrvInfo.ep0_current_dir = direction;
				/* Receive*/
				if(direction==USB_BDT_RX)
				{
					/* This one is received, software should handle this packet*/
					g_UsbDrvInfo.ep0_rx_even_odd = even_odd;

					if((g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_DATA)
						||(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_DATA_END))
					{
						/* Host send status stage before Device expects*/
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_END;
					}	

					if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_STATUS)
					{
						/* Host send status stage and match Device's expection */
						WRITE_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd, 
											(USB_EP0_MAXP << VUSB_BDT_BC_SHIFT) |VUSB_BDT_OWNS_BIT);
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;
					}
				}
				else
				{
					/* This one is transmitted, software will fill next packet*/
					g_UsbDrvInfo.ep0_tx_even_odd = even_odd^1;	

					if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_RX_DATA)
					{
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_END;
					}	

					if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_DATA_END)
					{
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_TX_STATUS;
					}
					
					if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_RX_STATUS)
					{
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;
					}
				}

				if(g_UsbDrvInfo.ep0_hdlr == NULL)
					EXT_ASSERT(0, 0, 0, 0);
   				g_UsbDrvInfo.ep0_hdlr();
			}
			else if(direction == USB_BDT_RX)    /* Receive*/
			{
				if(g_UsbDrvInfo.ep_rx_hdlr[ep_num-1] != NULL)
   					g_UsbDrvInfo.ep_rx_hdlr[ep_num -1]();
   				/* Not handle else because the fm token done may happen here */	
			}
			else	 	/* Send */
			{
				if(g_UsbDrvInfo.ep_tx_hdlr[ep_num-1] != NULL)
   					g_UsbDrvInfo.ep_tx_hdlr[ep_num -1]();
				/* Not handle else because the fm token done may happen here */		

				if(g_UsbDrvInfo.fast_mode_tx_ep == ep_num)
				{
					/* This is Fast mode token done intr */
					g_UsbDrvInfo.fast_mode_tx_ep = 0;	

					if((g_UsbDrvInfo.dma_res_tx_ep==0)&&(g_UsbDrvInfo.dma_tx_ep ==0))
					{
						/* No TX data residue, and DMA callback function has been done */
						callback = g_UsbDrvInfo.dma_callback[ep_num-1];
						g_UsbDrvInfo.dma_callback[ep_num-1] = NULL;
						if(callback!=NULL)
							callback();
					}
				}
				else if(g_UsbDrvInfo.dma_res_tx_ep == ep_num)
				{
					/* This is the last residue packet token done intr*/
					g_UsbDrvInfo.dma_res_tx_ep = 0;
					
					callback = g_UsbDrvInfo.dma_callback[ep_num-1];
					g_UsbDrvInfo.dma_callback[ep_num-1] = NULL;
					if(callback!=NULL)
						callback();
				}
			}	
		} /* End VUSB_INT_STAT_TOKEN_DONE*/
#ifdef __OTG_ENABLE__	
	}
#endif

	if (IntrStatus & VUSB_INT_STAT_SLEEP)
	{
		g_UsbDrvInfo.power_state = USB_STATE_SUSPEND;
		DRV_WriteReg8(USB_PHY_EXTRA, PhyStatus |VUSB_PHY_SUSPEND);
		//if(g_UsbDrvInfo.power_state != USB_STATE_SUSPEND)
		USB_Drv_Suspend();
	} /* End VUSB_INT_STAT_SLEEP */

	if (IntrStatus & VUSB_INT_STAT_ERROR)
	{
		g_UsbDrvInfo.error_count++;
		g_UsbDrvInfo.error_reason = ErrorStatus;
		g_UsbDrvInfo.fm_error_reason = FMStatus;
		USB_Dbg_Trace(USB_DBG_HISR_ERROR_REASON, drv_get_current_time(), ErrorStatus, FMStatus);
		kal_prompt_trace(MOD_DRV_HISR, "HW ERROR: %d, fast mode: %d", ErrorStatus, FMStatus);

		/* Check if target is in host mode */
		usb_ctrl = DRV_Reg8(USB_CTL);
		if((usb_ctrl&VUSB_CTL_HOST_MODE_EN) != 0)
		{
			kal_prompt_trace(MOD_DRV_HISR, "HW ERROR in host mode");
			USB_Dbg_Trace(USB_DBG_IN_HOST_MODE, drv_get_current_time(), 0, 0);
		}

		if((g_UsbDrvInfo.error_count%8) == 0)
		{
			/* pull down D+ */
			USB_PowerControl(KAL_FALSE);
			kal_prompt_trace(MOD_DRV_HISR, "HW ERROR D+ down");
			g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
		}
	}
	else
	{
		g_UsbDrvInfo.error_count = 0;
	}

	if (IntrStatus & VUSB_INT_STAT_STALL)
	{
	}/* End VUSB_INT_STAT_STALL */

	/* Clear error interrupt other than token done */
	DRV_WriteReg8(USB_FM_ERR_STAT, FMStatus&(0x07));
	DRV_WriteReg8(USB_ERR_STAT, ErrorStatus);
	DRV_WriteReg8(USB_INT_STAT, (IntrStatus&(~VUSB_INT_STAT_TOKEN_DONE)));

/* if define OTG_ENABLE,  OTG HISR will unmask if it is needed*/
#ifndef __OTG_ENABLE__
	/* clear interrupt and unmask interrupt if application agree on it */
   	IRQClearInt(IRQ_USB_CODE);
        g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;
   	if (g_UsbDrvInfo.is_unMaskUSB==KAL_TRUE)
   		IRQUnmask(IRQ_USB_CODE);
#endif  	

#elif defined(DRV_USB_IP_V1)

	kal_uint8    IntrUSB;
	kal_uint8    IntrIn;
	kal_uint8    IntrOut;
	kal_uint32  ep_num;

	IntrUSB = DRV_Reg8(USB_INTRUSB);
	IntrIn = DRV_Reg8(USB_INTRIN1);
	IntrOut = DRV_Reg8(USB_INTROUT1);
   
	USB_Dbg_Trace(USB_DBG_HISR, drv_get_current_time(), IntrUSB, IntrOut);
   
   	/* Check for resume from suspend mode */
   	if (IntrUSB & USB_INTRUSB_RESUME)
   	{
		USB_Drv_Resume();
   		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
   	}

	/* Check for reset interrupts */
	if (IntrUSB & USB_INTRUSB_RESET)
	{
//		USB_Initialize_Drv();
		if(g_UsbDrvInfo.reset_hdlr == NULL)
			ASSERT(0);
		g_UsbDrvInfo.reset_hdlr();
	}

	/* Check for endpoint 0 interrupt */
	if (IntrIn&USB_INTRIN1_EP0)
	{
		if(g_UsbDrvInfo.ep0_hdlr == NULL)
			EXT_ASSERT(0, 0, 0, 0);
		g_UsbDrvInfo.ep0_hdlr();
	}

	/* Check for Bulk in interrupt */
	for(ep_num = 1; ep_num <= MAX_INTR_EP_NUM; ep_num++)	
	{
		if (IntrIn & (0x01 <<ep_num))
   		{
   			if(g_UsbDrvInfo.ep_tx_hdlr[ep_num-1] != NULL)
   			{
   				g_UsbDrvInfo.ep_tx_hdlr[ep_num -1]();
   			}
   			else
   			{
	#ifdef  __PRODUCTION_RELEASE__			
				USB_CtrlEPStall(ep_num, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_4);
	#else
				/* if EP does not support ep_hdr, its interrupt should not be triggered */
				/* Save debug info */
				DRV_WriteReg8(USB_INDEX, ep_num);
				g_UsbDrvInfo.CSR = DRV_Reg8(USB_INCSR1);
				g_UsbDrvInfo.INTRE = DRV_Reg8(USB_INTRIN1E);
				EXT_ASSERT(0, ep_num, 0, 0); 
	#endif
			}
		}
	}

	/* Check for Bulk out interrupt */
	for(ep_num = 1; ep_num <= MAX_INTR_EP_NUM; ep_num++)
	{
		if (IntrOut & (0x01 <<ep_num))
		{
			if(g_UsbDrvInfo.ep_rx_hdlr[ep_num-1]!=NULL)
			{
				g_UsbDrvInfo.ep_rx_hdlr[ep_num -1]();
			}
			else
			{
   	#ifdef  __PRODUCTION_RELEASE__			
				USB_CtrlEPStall(ep_num, USB_RX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_4);
   	#else
				/* if EP does not support ep_hdr, its interrupt should not be triggered */
				/* Save debug info */
				DRV_WriteReg8(USB_INDEX, ep_num);
				g_UsbDrvInfo.CSR = DRV_Reg8(USB_OUTCSR1);
				g_UsbDrvInfo.INTRE = DRV_Reg8(USB_INTROUT1E);
				EXT_ASSERT(0, ep_num, 0, 0); 
   	#endif
			}
		}
	}

   	/* Check for suspend mode */
   	if (IntrUSB &  USB_INTRUSB_SUSPEND)
   	{
		USB_Drv_Suspend();
		g_UsbDrvInfo.power_state = USB_STATE_SUSPEND;
   	}
   	
	/* clear interrupt and unmask interrupt if application agree on it */
   	IRQClearInt(IRQ_USB_CODE);
	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;
   	if (g_UsbDrvInfo.is_unMaskUSB==KAL_TRUE)
   		IRQUnmask(IRQ_USB_CODE);
#endif   	 	
}

#ifndef __OTG_ENABLE__
static void USB_LISR(void)
{
	IRQMask(IRQ_USB_CODE);
	g_UsbDrvInfo.is_ProUSBHISR = KAL_TRUE;
	drv_active_hisr(DRV_USB_HISR_ID);
}
#endif


#ifdef _USB_VBUS_DETECT_WITH_NIRQ_
void USB_NIRQ_Registration(void (reg_hisr)(void))
{
#if defined(DRV_USB_IP_V2)
	g_UsbDrvInfo.vbus_callback = reg_hisr;
	g_UsbDrvInfo.vbus_intr_allow = KAL_FALSE;

	if (g_UsbDrvInfo.vbus_timer_handle == 0)
		GPTI_GetHandle(&g_UsbDrvInfo.vbus_timer_handle);   

	IRQMask(IRQ_GPII_CODE);
    #ifndef __CUST_NEW__
	GPIO_ModeSetup(36, 0x01);
	/* inverse, plug in detect high*/
	DRV_WriteReg(GPIO_DINV3, DRV_Reg(GPIO_DINV3)|0x0010);
    #endif /* __CUST_NEW__ */
	nIRQ_Registration(LEVEL_SENSITIVE, USB_NIRQ_HISR, KAL_FALSE);
   	IRQUnmask(IRQ_GPII_CODE);
#else
	EXT_ASSERT(0, 0, 0, 0);
#endif
 }

static void USB_NIRQ_Timer_Callback(void *data)
{
	GPTI_StopItem(g_UsbDrvInfo.vbus_timer_handle);

	g_UsbDrvInfo.vbus_intr_allow = (g_UsbDrvInfo.vbus_intr_allow == KAL_TRUE)? KAL_FALSE: KAL_TRUE;

   /*
    * This timer is to avoid if interrupt status is changed but 
    * sw_debounce->eint_intr_allow is still in KAL_TRUE state
    * because of no interrupt
    */
	if (g_UsbDrvInfo.vbus_intr_allow) 
	{
		GPTI_StartItem(g_UsbDrvInfo.vbus_timer_handle, 5,  USB_NIRQ_Timer_Callback, data);
	}

	IRQUnmask(IRQ_GPII_CODE);  	
}

static void USB_NIRQ_HISR(void)
{
	GPTI_StopItem(g_UsbDrvInfo.vbus_timer_handle);
       if ( g_UsbDrvInfo.vbus_intr_allow == KAL_FALSE)
       {
		 GPTI_StartItem(g_UsbDrvInfo.vbus_timer_handle, 5, USB_NIRQ_Timer_Callback, &g_UsbDrvInfo.vbus_timer_handle);
		 IRQClearInt(IRQ_GPII_CODE);
       }
       else
       {
       	g_UsbDrvInfo.vbus_intr_allow = KAL_FALSE;
       
		if(DRV_Reg(GPIO_DINV3)&0x0010)
		{
			/* inverse */
            #ifdef __CUST_NEW__
			GPIO_DinvSetup(36, KAL_FALSE);
            #else /* __CUST_NEW__ */
			DRV_WriteReg(GPIO_DINV3, DRV_Reg(GPIO_DINV3)&(~0x0010));
            #endif /* __CUST_NEW__ */
			if(g_UsbDrvInfo.vbus_callback==NULL)
				EXT_ASSERT(0, 0, 0, 0);
			g_UsbDrvInfo.vbus_callback();
		}
		else
		{
			/* inverse */
            #ifdef __CUST_NEW__
			GPIO_DinvSetup(36, KAL_TRUE);
            #else /* __CUST_NEW__ */
			DRV_WriteReg(GPIO_DINV3, DRV_Reg(GPIO_DINV3)|0x0010);
            #endif /* __CUST_NEW__ */
			if(g_UsbDrvInfo.vbus_callback==NULL)
				EXT_ASSERT(0, 0, 0, 0);
			g_UsbDrvInfo.vbus_callback();
		}

		IRQClearInt(IRQ_GPII_CODE);
	   	IRQUnmask(IRQ_GPII_CODE);  	
       }	 	
}
#endif /*  _USB_VBUS_DETECT_WITH_NIRQ_*/

#endif /* __USB_ENABLE__*/

#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V2)||defined(DRV_USB_IP_V3))

/************************************************************
	Functions that is used when USB_ENABLE_ is turned off 
*************************************************************/

/* USB PDN enable, other modules may need USB PDN*/
void USB_PDNEnable(USB_PDN_OWNER owner)
{
	kal_uint32 savedMask;
	kal_bool disable_power = KAL_FALSE;

	savedMask = SaveAndSetIRQMask();
	g_usb_pdn_owner &= (~(1<<owner));          
	if(g_usb_pdn_owner == 0)
	{
		disable_power = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);

	if(disable_power == KAL_TRUE)
	{
		DRVPDN_Enable(DRVPDN_CON0, DRVPDN_CON0_USB, PDN_USB);  
	}
}

/* USB PDN disable, other modules may need USB PDN*/
void USB_PDNDisable(USB_PDN_OWNER owner)
{
	kal_uint32 savedMask;
	kal_bool enable_power = KAL_FALSE;

	savedMask = SaveAndSetIRQMask();   
	if(g_usb_pdn_owner == 0)
	{
		enable_power = KAL_TRUE;
	}
	g_usb_pdn_owner |= (1<<owner);    
	RestoreIRQMask(savedMask);

	if(enable_power == KAL_TRUE)
	{
		DRVPDN_Disable(DRVPDN_CON0, DRVPDN_CON0_USB, PDN_USB); 
	}
}

#endif




