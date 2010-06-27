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
 *    usb_hcd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb host hardware related functions
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

#include "usb_hw.h"
#include "usb_hcd.h"
#include "usb_hcd_pri.h"
#include "otg_drv.h"


#ifdef __OTG_ENABLE__

USB_HCD_Struct g_UsbHcdInfo;


static void USB_HCD_Reset_Recovery_Timeout(void *parameter);
static void USB_HCD_Reset_Timeout(void *parameter);
static void USB_HCD_Reset_Device(USB_HCD_STATUS reset_reason);
static void  USB_HCD_Delay_Reset_Timeout(void *parameter);
static void USB_HCD_Debounce_Timeout(void *parameter);
static void USB_HCD_Debounce_Attach(void);
static void USB_HCD_Process_Attach(void);
static void USB_HCD_Process_Detach(void);

static void USB_HCD_Send_Setup (kal_uint8 index);
static void USB_HCD_Send_Data (kal_uint8 index);
static void USB_HCD_Recv_Data (kal_uint8 index);

static void USB_HCD_Queue_Pkt(kal_uint8 index);
static void USB_HCD_Remove_Pkt(kal_uint8 index);
static kal_int8 USB_HCD_Get_Pending_Pkts(void);
static void USB_HCD_Sched_Pending_Pkts(void);
static void USB_HCD_Update_Interval(void);

static void USB_HCD_DMA_Callback(void);

/************************************************************
	driver info functions
*************************************************************/

void USB_HCD_Init_Drv_Info(void)
{
	kal_uint32 index;
	
	/* init BDT ptr and addr*/
	/* BDT */
	WRITE_EP0_BDT(USB_BDT_RX, USB_BDT_EVEN, (USB_BDT_PTR)USB_BDT_RX0_EVEN);
	WRITE_EP0_BDT(USB_BDT_RX, USB_BDT_ODD, (USB_BDT_PTR)USB_BDT_RX0_ODD);
	WRITE_EP0_BDT(USB_BDT_TX, USB_BDT_EVEN, (USB_BDT_PTR)USB_BDT_TX0_EVEN);
	WRITE_EP0_BDT(USB_BDT_TX, USB_BDT_ODD, (USB_BDT_PTR)USB_BDT_TX0_ODD);

	/* interrupt handler */
	g_UsbHcdInfo.attach_hdlr = NULL;
	g_UsbHcdInfo.detach_hdlr = NULL;
	g_UsbHcdInfo.resume_hdlr = NULL;
	for(index = 0; index < USB_HCD_MAX_EP_NUM; index++)
	{
		g_UsbHcdInfo.ep_hdlr[index] = NULL;
		g_UsbHcdInfo.ep_info[index].b_in_use = KAL_FALSE;
		g_UsbHcdInfo.ep_info[index].b_enable = KAL_FALSE;
	}
	g_UsbHcdInfo.ep0_setup = KAL_FALSE;
	g_UsbHcdInfo.rx_even_odd = 0;
 	g_UsbHcdInfo.tx_even_odd = 0;	

	g_UsbHcdInfo.rx_curent_index = -1;
	g_UsbHcdInfo.tx_curent_index = -1;

	if (g_UsbHcdInfo.gpt_handle == 0)
		GPTI_GetHandle(&g_UsbHcdInfo.gpt_handle);
	
	/* may be omit */
	g_UsbHcdInfo.resume_timer = 0;

	g_UsbHcdInfo.processing_ep_id = -1;
	g_UsbHcdInfo.iso_pipe_head = -1;
	g_UsbHcdInfo.iso_pipe_tail = -1;
	g_UsbHcdInfo.intr_pipe_head = -1;
	g_UsbHcdInfo.intr_pipe_tail = -1;
	g_UsbHcdInfo.ctrl_pipe_head = -1;
	g_UsbHcdInfo.ctrl_pipe_tail = -1;
	g_UsbHcdInfo.bulk_pipe_head = -1;
	g_UsbHcdInfo.bulk_pipe_tail = -1;

	g_UsbHcdInfo.dma_index = -1;
	g_UsbHcdInfo.dma_port = 0;
   	g_UsbHcdInfo.dma_pktrdy = KAL_FALSE;
   	g_UsbHcdInfo.dma_running = KAL_FALSE;
   	g_UsbHcdInfo.dma_callback_upd_run = KAL_FALSE;
//  g_UsbHcdInfo.dma_callback = NULL;
	g_UsbHcdInfo.dma_pktlength = 0;
	
	g_UsbHcdInfo.dma_tx_ep = 0;
	g_UsbHcdInfo.dma_res_tx_ep = 0;
	g_UsbHcdInfo.fast_mode_tx_ep= 0;
	
	g_UsbHcdInfo.b_unmask_irq = KAL_TRUE;
}


void USB_HCD_Register_Drv_Info(USB_HCD_HDLR_TYPE type, kal_uint32 ep_num, usb_hcd_intr_handler_ptr hdlr)
{
	if(ep_num > USB_HCD_MAX_EP_NUM)
		EXT_ASSERT(0, ep_num, USB_HCD_MAX_EP_NUM, 0);
	
	switch(type)
	{
	case USB_HCD_HDLR_ATTACH:
		g_UsbHcdInfo.attach_hdlr = hdlr;
		break;
	case USB_HCD_HDLR_DETACH:
		g_UsbHcdInfo.detach_hdlr = hdlr;
		break;
	case USB_HCD_HDLR_RESUME:
		g_UsbHcdInfo.resume_hdlr = hdlr;
		break;
	case USB_HCD_HDLR_TOKEN_DONE:
		g_UsbHcdInfo.ep_hdlr[ep_num] = hdlr;
		break;
	default:
		ASSERT(0);	
		break;
	}
}

kal_uint8 USB_HCD_Get_FM_Pkt_Size(void)
{
	return USB_HCD_FASTMODE_PKT_SIZE;
}

/* set unmask variable to control if unmask USB interruput when leaving USB HISR*/
void USB_HCD_Set_UnMask_Irq(kal_bool set)
{
	g_UsbHcdInfo.b_unmask_irq = set;
}

kal_bool USB_HCD_Get_UnMask_Irq(void)
{
	return g_UsbHcdInfo.b_unmask_irq;
}

void USB_HCD_Dis_Attach(void)
{
	g_UsbHcdInfo.b_disable_attach = KAL_TRUE;
}

void USB_HCD_En_Attach(void)
{
	g_UsbHcdInfo.b_disable_attach = KAL_FALSE;
}

/************************************************************
	system ctrl functions
*************************************************************/

void USB_HCD_Initialize_Drv(void)
{
	DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_CTL, 0x0);					/* Disable VUSB */
	DRV_WriteReg8(USB_INT_ENB, 0x0);				/* Mask all interupts */
	DRV_WriteReg8(USB_INT_STAT, 0xff);			/* Clear all interupts */
	DRV_WriteReg8(USB_CTL, VUSB_CTL_ODD_RST);	/* Disable VUSB */
	DRV_WriteReg8(USB_ADDR, 0x0);

	/* initialize BDT */
	DRV_WriteReg8(USB_BDT_PAGE_01, 0xBD);
	DRV_WriteReg8(USB_BDT_PAGE_02, 0xBD);
	DRV_WriteReg8(USB_BDT_PAGE_03, 0xBD);

	/* Use 64 byts FIFO for host mode*/
	WRITE_EP0_BDT_ADDR(USB_BDT_RX, USB_BDT_EVEN, USB_FIFO_RX1);
	WRITE_EP0_BDT_ADDR(USB_BDT_RX, USB_BDT_ODD, USB_FIFO_RX1);
	WRITE_EP0_BDT_ADDR(USB_BDT_TX, USB_BDT_EVEN, USB_FIFO_TX1);
	WRITE_EP0_BDT_ADDR(USB_BDT_TX, USB_BDT_ODD, USB_FIFO_TX1);

	/* Set all PID as 0. Unlike device mode, the receive PID is set just before host send IN token*/
	WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN, 0);
	WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD, 0);
	WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 0);
	WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 0);

	/* Enable the host mode */   
	DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN);	

	/* Typical value for 64 bytes packets is 74 so we keep enough time for 
	** the transaction to complete 
	*/
	DRV_WriteReg8(USB_SOF_THLD, 0x74);	

	/* Enable Attach interrupt only */            
	DRV_WriteReg8(USB_INT_ENB, VUSB_INT_ENB_ATTACH);	


	/* disable Fast mode*/
	if(DRV_Reg8(USB_FM_CTL)&VUSB_FM_CTL_SUCERREN)
		DRV_WriteReg8(USB_FM_CTL, (DRV_Reg8(USB_FM_CTL)&(~VUSB_FM_CTL_FMENB)&(~VUSB_FM_CTL_SUCERREN)));
	else
		DRV_WriteReg8(USB_FM_CTL, (DRV_Reg8(USB_FM_CTL)&(~VUSB_FM_CTL_FMENB)));

	/* disable phy suspend*/
	DRV_WriteReg8(USB_PHY_EXTRA, 0);
}

void USB_HCD_Release_Drv(void)
{
	DRV_WriteReg8(USB_INT_ENB, 0);
	DRV_WriteReg8(USB_INT_STAT, 0xff);
}
	

/* set address for hw*/
void USB_HCD_SetAddress(kal_uint8 addr)
{
	DRV_WriteReg8(USB_ADDR, addr);
}

void USB_HCD_Resume(void)
{
	/* Bus control*/
	USB_HCD_Bus_Control(USB_HCD_BUS_ASSERT_RESUME);

//	USB_Ms_Dbg_Trace(OTG_HOST_ASSERT_RESUME, 0);

	/* Add for OTG function*/
	if(OTG_Get_Plug_Type()==OTG_PLUG_A)
		OTG_Set_Status(OTG_STATUS_A_DETECT_B_RESUME, KAL_TRUE);
	else
		OTG_Set_Status(OTG_STATUS_B_DETECT_A_RESUME, KAL_TRUE);
		
	if(g_UsbHcdInfo.resume_hdlr!=NULL)
		g_UsbHcdInfo.resume_hdlr(USB_HCD_OK, 0);
}

void USB_HCD_Suspend(void)
{
}


/* GPT timeout function*/
static void USB_HCD_Reset_Recovery_Timeout(void *parameter)
{
	GPTI_StopItem(g_UsbHcdInfo.gpt_handle);
	
	/* Enable the token done, SOF and reset interrupts */   
	DRV_WriteReg8(USB_INT_ENB, VUSB_INT_ENB_TOKEN_DONE | VUSB_INT_ENB_RESET |
					VUSB_INT_ENB_SOF | VUSB_INT_ENB_STALL|VUSB_INT_ENB_ERROR);

	/* Clear all interrupt. Note that token done has 4 fifo depth */
	DRV_WriteReg8(USB_INT_STAT, 0xff);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);	
	
	/* reset even odd setting*/
	g_UsbHcdInfo.rx_even_odd = 0;
 	g_UsbHcdInfo.tx_even_odd = 0;	
 	

	/* Call the callback function of there was one register for the attach 
	** event 
	*/
	if(g_UsbHcdInfo.attach_hdlr==NULL)
		EXT_ASSERT(0, 0, 0, 0);
	g_UsbHcdInfo.attach_hdlr(g_UsbHcdInfo.reset_reason, 0);

	/* unmask USB IRQ*/
	g_UsbHcdInfo.b_unmask_irq = KAL_TRUE;
	IRQUnmask(IRQ_USB_CODE);
}

/* GPT timeout function*/
static void USB_HCD_Reset_Timeout(void *parameter)
{
	GPTI_StopItem(g_UsbHcdInfo.gpt_handle);
	
	/* End the reset */
	DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN);

	/* Enable host mode and start generating SOFs */ 
	DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN |VUSB_CTL_SOF_EN);	

	/* Delay for the reset recovery period */
	GPTI_StartItem(g_UsbHcdInfo.gpt_handle, USB_HCD_RESET_RECOVERY_DELAY,
				USB_HCD_Reset_Recovery_Timeout, &g_UsbHcdInfo); 
}

/* Send reset signal to device*/
static void USB_HCD_Reset_Device(USB_HCD_STATUS reset_reason)
{ 
	/* reset addr as 0 */
	DRV_WriteReg8(USB_ADDR, 0);

	/* Set the ODD/EVEN BDT to even */
	DRV_WriteReg8(USB_CTL, VUSB_CTL_ODD_RST);
	
	/* assert reset on the USB */
	DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN | VUSB_CTL_RESET);	

	g_UsbHcdInfo.reset_reason = reset_reason;

	/* Delay for the reset process to complete */
	GPTI_StartItem(g_UsbHcdInfo.gpt_handle, USB_HCD_RESET_DELAY,
				USB_HCD_Reset_Timeout, &g_UsbHcdInfo);
} 

/* GPT timeout function*/
static void  USB_HCD_Delay_Reset_Timeout(void *parameter)
{
	kal_uint32 reset_reason = (kal_uint32)parameter;
	
	GPTI_StopItem(g_UsbHcdInfo.gpt_handle);

	USB_HCD_Reset_Device((USB_HCD_STATUS)reset_reason);
}

/* Reset after timeout, note that timeout unit is 10ms */
void  USB_HCD_Delay_Reset_Device(USB_HCD_STATUS reset_reason, kal_uint32 timeout)
{
	if(timeout>0)
		GPTI_StartItem(g_UsbHcdInfo.gpt_handle, timeout,
					USB_HCD_Delay_Reset_Timeout, (void*)reset_reason);
	else
		USB_HCD_Reset_Device(reset_reason);
}

/* GPT timeout function*/
static void USB_HCD_Debounce_Timeout(void *parameter)
{
	GPTI_StopItem(g_UsbHcdInfo.gpt_handle);

	if(g_UsbHcdInfo.b_disable_attach==KAL_TRUE)
	{
		GPTI_StartItem(g_UsbHcdInfo.gpt_handle, USB_HCD_DEBOUNCE_DELAY,
					USB_HCD_Debounce_Timeout, &g_UsbHcdInfo);
	}
	else
	{
		USB_HCD_Debounce_Attach();
	}
}

static void USB_HCD_Debounce_Attach(void)
{
	kal_uint8 control_value;

	control_value = DRV_Reg8(USB_CTL);

	DRV_WriteReg8(USB_ADDR, 0);

	 /* currently full speed */
	if (control_value & VUSB_CTL_SINGLE_ENDED_0) 
	{
		// add error handling
		//ASSERT(0);		
		USB_HCD_Process_Detach();
		if(g_UsbHcdInfo.b_unmask_irq == KAL_FALSE)
		{
			/* unmask USB IRQ*/
			g_UsbHcdInfo.b_unmask_irq = KAL_TRUE;
			IRQUnmask(IRQ_USB_CODE);
		}	
		return;
	} 
	else 
	{
		DRV_WriteReg8(USB_ADDR, 0);
		/* Add for OTG function*/
		if(OTG_Get_Plug_Type()==OTG_PLUG_A)
			OTG_Set_Status(OTG_STATUS_A_DETECT_B_CONN, KAL_TRUE);
		else
			OTG_Set_Status(OTG_STATUS_B_DETECT_A_CONN, KAL_TRUE);
	} 

	/* enable ep0 */   
	DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_CONTROL);

	/* Reset the device */
	USB_HCD_Reset_Device(USB_HCD_OK);
}

static void USB_HCD_Process_Attach(void)
{ 
	OTG_STATE otg_state;
	
	/* Enable all errors */
	DRV_WriteReg8(USB_ERR_ENB, 0xff);	
	
	/* Zero the control register. It is okay to do this because JSTATE 
	** and SE0 are read-only bits 
	*/
	DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN);	

	otg_state = OTG_Get_State();
	if(((otg_state!=OTG_STATE_A_SUSPEND) && (otg_state!=OTG_STATE_B_WAIT_ACON))
		|| (g_UsbHcdInfo.b_disable_attach==KAL_TRUE))
	{
		GPTI_StartItem(g_UsbHcdInfo.gpt_handle, USB_HCD_DEBOUNCE_DELAY,
					USB_HCD_Debounce_Timeout, &g_UsbHcdInfo);
		g_UsbHcdInfo.b_unmask_irq = KAL_FALSE;
	}
	else
	{
		USB_HCD_Debounce_Attach();
	}
} 


static void USB_HCD_Process_Detach(void)
{ 

	/* Cancel if there are any pending tokens */
	g_UsbHcdInfo.processing_ep_id = -1;


	/* Reset all the attached device specific values */
	DRV_WriteReg8(USB_ADDR, 0);
	
	if(OTG_Get_State()==OTG_STATE_B_IDLE)
		return;
	
	/* enable ep0 */   
	DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_CONTROL);  

	/* Set the ODD/EVEN BDT to even and enable the host mode */   
	DRV_WriteReg8(USB_CTL, VUSB_CTL_ODD_RST);
	DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN);

	/* Clear all interrupts */
	DRV_WriteReg8(USB_INT_STAT, 0xff);

	/* Enable attach interrupt */
	DRV_WriteReg8(USB_INT_ENB, VUSB_INT_ENB_ATTACH);

	/* Add for OTG function*/
	if(OTG_Get_Plug_Type()==OTG_PLUG_A)
		OTG_Set_Status(OTG_STATUS_A_DETECT_B_CONN, KAL_FALSE);
	else
		OTG_Set_Status(OTG_STATUS_B_DETECT_A_CONN, KAL_FALSE);

	/* Call the callback function if there was one registered for a detach 
	** event 
	*/
	if(g_UsbHcdInfo.detach_hdlr==NULL)
		EXT_ASSERT(0, 0, 0, 0);
	g_UsbHcdInfo.detach_hdlr(USB_HCD_OK, 0);
   
} /* Endbody */

void USB_HCD_Bus_Control(USB_HCD_BUS_TYPE type)
{
	switch(type)
	{
	case USB_HCD_BUS_SUSPEND_SOF:
		DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN);
		/* Enable the resume interrupt when suspended */
		DRV_WriteReg8(USB_INT_ENB, DRV_Reg8(USB_INT_ENB)|VUSB_INT_ENB_RESUME);
		break;
	case USB_HCD_BUS_RESUME_SOF:
	case USB_HCD_BUS_DEASSERT_RESUME:
		DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN|VUSB_CTL_SOF_EN);
		/* disable the resume interrupt when resumed */
		DRV_WriteReg8(USB_INT_ENB, DRV_Reg8(USB_INT_ENB)&(~VUSB_INT_ENB_RESUME));
		break;
	case USB_HCD_BUS_ASSERT_RESUME:
		DRV_WriteReg8(USB_CTL, VUSB_CTL_HOST_MODE_EN|VUSB_CTL_RESUME);
		/* disable the resume interrupt when resumed */
		DRV_WriteReg8(USB_INT_ENB, DRV_Reg8(USB_INT_ENB)&(~VUSB_INT_ENB_RESUME));
		break;
	default:
		ASSERT(0);
		break;
	}
}

/************************************************************
	EP ctrl functinos
*************************************************************/

kal_uint8 USB_HCD_Get_EP_Channel(void)
{
	kal_uint32 index;
	for(index=1; index<USB_HCD_MAX_EP_NUM; index++)
	{
		if(g_UsbHcdInfo.ep_info[index].b_in_use==KAL_FALSE)
		{
			g_UsbHcdInfo.ep_info[index].b_in_use = KAL_TRUE;
			g_UsbHcdInfo.ep_info[index].b_enable = KAL_FALSE;
			break;
		}
	}

	if(index>=USB_HCD_MAX_EP_NUM)
		EXT_ASSERT(0, index, 0, 0);

	return index;
}

void USB_HCD_Free_EP_Channel(void)
{
	kal_uint32 index;
	for(index=1; index<USB_HCD_MAX_EP_NUM; index++)
	{
		g_UsbHcdInfo.ep_info[index].b_in_use=KAL_FALSE;
		g_UsbHcdInfo.ep_info[index].b_enable = KAL_FALSE;
	}
}

void USB_HCD_Set_EP_Max_Pkt(kal_uint8 index, kal_uint16 max_pkt_size)
{
	g_UsbHcdInfo.ep_info[index].max_packet_size = max_pkt_size;
}

void USB_HCD_Clear_Data01(kal_uint8 index)
{
	g_UsbHcdInfo.ep_info[index].data01 = 0;
}

void USB_HCD_EP0En(void)
{
	g_UsbHcdInfo.ep_info[0].b_in_use = KAL_TRUE;
	g_UsbHcdInfo.ep_info[0].b_enable = KAL_TRUE;
	g_UsbHcdInfo.ep_info[0].ep_type = USB_HCD_ENDPT_CTRL;
	g_UsbHcdInfo.ep_info[0].ep_num = 0;
	g_UsbHcdInfo.ep_info[0].data01 = 0;
	g_UsbHcdInfo.ep_info[0].interval = 2048;
	g_UsbHcdInfo.ep_info[0].current_interval = g_UsbHcdInfo.ep_info[0].interval;
	g_UsbHcdInfo.ep_info[0].no_response_count = 0;
}	

/* Note that the interval unit is 64ms */
void USB_HCD_InEPEn(kal_uint8 index, kal_uint8 no, USB_HCD_ENDPT_TYPE ep_type, kal_uint8 interval, kal_bool bDMA)
{
	if((index>=USB_HCD_MAX_EP_NUM) || (g_UsbHcdInfo.ep_info[index].b_in_use==KAL_FALSE))
		EXT_ASSERT(0, index, 0, 0);
	
	g_UsbHcdInfo.ep_info[index].b_enable = KAL_TRUE;
	g_UsbHcdInfo.ep_info[index].ep_type = ep_type;
	g_UsbHcdInfo.ep_info[index].ep_num = no;
	g_UsbHcdInfo.ep_info[index].data01 = 0;
	g_UsbHcdInfo.ep_info[index].direction = USB_HCD_PIPE_DIR_IN;
	if(bDMA==KAL_FALSE)
		g_UsbHcdInfo.ep_info[index].interval = interval*64;
	else
	g_UsbHcdInfo.ep_info[index].interval = interval;
	g_UsbHcdInfo.ep_info[index].current_interval = g_UsbHcdInfo.ep_info[index].interval;
	g_UsbHcdInfo.ep_info[index].no_response_count = 0;

	g_UsbHcdInfo.ep_info[index].b_fast_mode_enable = bDMA;
}

void USB_HCD_OutEPEn(kal_uint8 index, kal_uint8 no, USB_HCD_ENDPT_TYPE ep_type, kal_uint8 interval, kal_bool bDMA)
{
	if((index>=USB_HCD_MAX_EP_NUM) || (g_UsbHcdInfo.ep_info[index].b_in_use==KAL_FALSE))
		EXT_ASSERT(0, index, 0, 0);
	
	g_UsbHcdInfo.ep_info[index].b_enable = KAL_TRUE;
	g_UsbHcdInfo.ep_info[index].ep_type = ep_type;
	g_UsbHcdInfo.ep_info[index].ep_num = no;
	g_UsbHcdInfo.ep_info[index].data01 = 0;
	g_UsbHcdInfo.ep_info[index].direction = USB_HCD_PIPE_DIR_OUT;
	if(bDMA==KAL_FALSE)
		g_UsbHcdInfo.ep_info[index].interval = interval*64;
	else
	g_UsbHcdInfo.ep_info[index].interval = interval;
	g_UsbHcdInfo.ep_info[index].current_interval = g_UsbHcdInfo.ep_info[index].interval;
	g_UsbHcdInfo.ep_info[index].no_response_count = 0;

	g_UsbHcdInfo.ep_info[index].b_fast_mode_enable = bDMA;
}

void USB_HCD_InEPDis(kal_uint8 index)
{
	if((index>=USB_HCD_MAX_EP_NUM) || (g_UsbHcdInfo.ep_info[index].b_in_use==KAL_FALSE))
		EXT_ASSERT(0, index, 0, 0);
	
	g_UsbHcdInfo.ep_info[index].b_enable = KAL_FALSE;
}

void USB_HCD_OutEPDis(kal_uint8 index)
{
	if((index>=USB_HCD_MAX_EP_NUM) || (g_UsbHcdInfo.ep_info[index].b_in_use==KAL_FALSE))
		EXT_ASSERT(0, index, 0, 0);
	
	g_UsbHcdInfo.ep_info[index].b_enable = KAL_FALSE;
}

kal_bool USB_HCD_Recv_Req(kal_uint8 index, kal_uint16 nBytes, void *pDst)
{
	if((index>=USB_HCD_MAX_EP_NUM) || (g_UsbHcdInfo.ep_info[index].b_in_use==KAL_FALSE)
		|| (g_UsbHcdInfo.ep_info[index].b_enable==KAL_FALSE))
		return KAL_FALSE;
	
	g_UsbHcdInfo.ep_info[index].p_data = pDst;
	g_UsbHcdInfo.ep_info[index].data_length = nBytes;
	g_UsbHcdInfo.ep_info[index].current_interval = g_UsbHcdInfo.ep_info[index].interval;
	g_UsbHcdInfo.ep_info[index].no_response_count = 0;
	g_UsbHcdInfo.ep_info[index].sofar = 0;

	//queue to scheduler
	USB_HCD_Queue_Pkt(index);

	return KAL_TRUE;
}

kal_bool USB_HCD_Send_Req(kal_uint8 index, kal_uint16 nBytes, void *pSrc)
{
	if((index>=USB_HCD_MAX_EP_NUM) || (g_UsbHcdInfo.ep_info[index].b_in_use==KAL_FALSE)
		|| (g_UsbHcdInfo.ep_info[index].b_enable==KAL_FALSE))
		return KAL_FALSE;
	
	g_UsbHcdInfo.ep_info[index].p_data = pSrc;
	g_UsbHcdInfo.ep_info[index].data_length = nBytes;
	g_UsbHcdInfo.ep_info[index].current_interval = g_UsbHcdInfo.ep_info[index].interval;
	g_UsbHcdInfo.ep_info[index].no_response_count = 0;
	g_UsbHcdInfo.ep_info[index].sofar = 0;

	//queue to scheduler
	USB_HCD_Queue_Pkt(index);

	return KAL_TRUE;
}

void USB_HCD_EP0_Setup_Req(kal_uint16 nBytes, void *pSrc)
{
	g_UsbHcdInfo.ep0_setup = KAL_TRUE;
	g_UsbHcdInfo.ep_info[0].data01 = 0;
	g_UsbHcdInfo.ep_info[0].p_data = pSrc;
	g_UsbHcdInfo.ep_info[0].data_length = nBytes;
	g_UsbHcdInfo.ep_info[0].current_interval = g_UsbHcdInfo.ep_info[0].interval;
	g_UsbHcdInfo.ep_info[0].no_response_count = 0;
	g_UsbHcdInfo.ep_info[0].sofar = 0;

	
	//queue to scheduler	
	USB_HCD_Queue_Pkt(0);
}

void USB_HCD_EP0_Data_Req(USB_HCD_PIPE_DIRECTION direction, kal_uint16 nBytes, void *pData)
{
	g_UsbHcdInfo.ep0_setup = KAL_FALSE;
	g_UsbHcdInfo.ep_info[0].direction = direction;
	g_UsbHcdInfo.ep_info[0].p_data = pData;
	g_UsbHcdInfo.ep_info[0].data_length = nBytes;
	g_UsbHcdInfo.ep_info[0].current_interval = g_UsbHcdInfo.ep_info[0].interval;
	g_UsbHcdInfo.ep_info[0].no_response_count = 0;
	g_UsbHcdInfo.ep_info[0].sofar = 0;
	
	//queue to scheduler	
	USB_HCD_Queue_Pkt(0);
}

void USB_HCD_EP0_Status_Req(USB_HCD_PIPE_DIRECTION direction)
{
	g_UsbHcdInfo.ep0_setup = KAL_FALSE;
	g_UsbHcdInfo.ep_info[0].direction = direction;
	g_UsbHcdInfo.ep_info[0].data01 = 1;
	g_UsbHcdInfo.ep_info[0].p_data = NULL;
	g_UsbHcdInfo.ep_info[0].data_length = 0;
	g_UsbHcdInfo.ep_info[0].current_interval = g_UsbHcdInfo.ep_info[0].interval;
	g_UsbHcdInfo.ep_info[0].no_response_count = 0;
	g_UsbHcdInfo.ep_info[0].sofar = 0;
	
	//queue to scheduler	
	USB_HCD_Queue_Pkt(0);
}

static void USB_HCD_Send_Setup (kal_uint8 index)
{
	kal_uint8 ep_ctrl_type;

#ifdef  __PRODUCTION_RELEASE__	
	while(DRV_Reg8(USB_CTL)&VUSB_CTL_TOKEN_BUSY)
	{
		/* wait until the previous done*/
	}
#else
	if(DRV_Reg8(USB_CTL)&VUSB_CTL_TOKEN_BUSY)
	{
		// token should be sent only when the previous has been completed
		ASSERT(0);
	}	
#endif

	/* make sure no other tx EP is processing*/
	if(g_UsbHcdInfo.tx_curent_index != -1)
		EXT_ASSERT(0, g_UsbHcdInfo.tx_curent_index, 0, 0);

	g_UsbHcdInfo.tx_curent_index = index;
	g_UsbHcdInfo.ep_info[index].sofar = 0;

	/* copy data to FIFO*/
	kal_mem_cpy((void*)READ_EP0_BDT_ADDR(USB_BDT_TX, g_UsbHcdInfo.tx_even_odd),
					g_UsbHcdInfo.ep_info[index].p_data, g_UsbHcdInfo.ep_info[index].data_length);

	/* setup bdt. include own bit. */
	WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbHcdInfo.tx_even_odd,
						(g_UsbHcdInfo.ep_info[index].data_length<<VUSB_BDT_BC_SHIFT)
						|(g_UsbHcdInfo.ep_info[index].data01<<VUSB_BDT_DATA01_SHIFT)|VUSB_BDT_OWNS_BIT);

	/* toggel data01*/
	g_UsbHcdInfo.ep_info[index].data01^=1;

	/* determine endpoint control type*/
	if(g_UsbHcdInfo.ep_info[index].ep_type!=USB_HCD_ENDPT_CTRL)
		EXT_ASSERT(0, index, g_UsbHcdInfo.ep_info[index].ep_type, 0);

	ep_ctrl_type = VUSB_ENDPT_CONTROL;

	DRV_WriteReg8(USB_ENDPT_CTL(0), ep_ctrl_type);

	/* send token in the last step*/
	DRV_WriteReg8(USB_TOKEN, VUSB_TOKEN_SETUP|(g_UsbHcdInfo.ep_info[index].ep_num&VUSB_TOKEN_ENDPT));
}

static void USB_HCD_Send_Data (kal_uint8 index)
{
	kal_uint8 ep_ctrl_type;
	kal_uint16 todo;

#ifdef  __PRODUCTION_RELEASE__	
	while(DRV_Reg8(USB_CTL)&VUSB_CTL_TOKEN_BUSY)
	{
		/* wait until the previous done*/
	}
#else
	if(DRV_Reg8(USB_CTL)&VUSB_CTL_TOKEN_BUSY)
	{
		// token should be sent only when the previous has been completed
		ASSERT(0);
	}	
#endif

	/* make sure no other tx EP is processing*/
	if(g_UsbHcdInfo.tx_curent_index != -1)
		EXT_ASSERT(0, g_UsbHcdInfo.tx_curent_index, 0, 0);

	g_UsbHcdInfo.tx_curent_index = index;

	if(g_UsbHcdInfo.ep_info[index].b_fast_mode_enable==KAL_TRUE)
	{
		USB_HCD_DMA_Setup(index, USB_TX_EP_TYPE, (kal_uint32)g_UsbHcdInfo.ep_info[index].p_data, 
							g_UsbHcdInfo.ep_info[index].data_length, KAL_FALSE);
	}
	else
	{
		if((g_UsbHcdInfo.ep_info[index].data_length-g_UsbHcdInfo.ep_info[index].sofar)
			>g_UsbHcdInfo.ep_info[index].max_packet_size)
			todo = g_UsbHcdInfo.ep_info[index].max_packet_size;
		else
			todo = g_UsbHcdInfo.ep_info[index].data_length-g_UsbHcdInfo.ep_info[index].sofar;

		/* copy data to FIFO*/
		kal_mem_cpy((void*)READ_EP0_BDT_ADDR(USB_BDT_TX, g_UsbHcdInfo.tx_even_odd),
						&g_UsbHcdInfo.ep_info[index].p_data[g_UsbHcdInfo.ep_info[index].sofar], todo);

		/* setup bdt. include own bit. */
		WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbHcdInfo.tx_even_odd,
							(todo<<VUSB_BDT_BC_SHIFT)
							|(g_UsbHcdInfo.ep_info[index].data01<<VUSB_BDT_DATA01_SHIFT)|VUSB_BDT_OWNS_BIT);

		/* toggel data01*/
		g_UsbHcdInfo.ep_info[index].data01^=1;

		/* determine endpoint control type*/
		switch(g_UsbHcdInfo.ep_info[index].ep_type)
		{
		case USB_HCD_ENDPT_CTRL:
			ep_ctrl_type = VUSB_ENDPT_CONTROL;
			break;
		case USB_HCD_ENDPT_BULK:
			ep_ctrl_type = VUSB_ENDPT_BULK_TX;
			break;
		case USB_HCD_ENDPT_INTR:
			ep_ctrl_type = VUSB_ENDPT_BULK_TX;
			break;
		case USB_HCD_ENDPT_ISO:
			ep_ctrl_type = VUSB_ENDPT_ISO_TX;
			break;	
		default:
			ep_ctrl_type = 0;
			ASSERT(0);	
			break;
		}

		DRV_WriteReg8(USB_ENDPT_CTL(0), ep_ctrl_type);

		/* send token in the last step*/
		DRV_WriteReg8(USB_TOKEN, VUSB_TOKEN_OUT|(g_UsbHcdInfo.ep_info[index].ep_num&VUSB_TOKEN_ENDPT));
	}
}

static void USB_HCD_Recv_Data (kal_uint8 index)
{
	kal_uint8 ep_ctrl_type;
	kal_uint16 todo;

#ifdef  __PRODUCTION_RELEASE__	
	while(DRV_Reg8(USB_CTL)&VUSB_CTL_TOKEN_BUSY)
	{
		/* wait until the previous done*/
	}
#else
	if(DRV_Reg8(USB_CTL)&VUSB_CTL_TOKEN_BUSY)
	{
		// token should be sent only when the previous has been completed
		ASSERT(0);
	}	
#endif

	/* make sure no other tx EP is processing*/
	if(g_UsbHcdInfo.rx_curent_index != -1)
		EXT_ASSERT(0, g_UsbHcdInfo.rx_curent_index, 0, 0);

	g_UsbHcdInfo.rx_curent_index = index;


	if(g_UsbHcdInfo.ep_info[index].b_fast_mode_enable==KAL_TRUE)
	{
		USB_HCD_DMA_Setup(index, USB_RX_EP_TYPE, (kal_uint32)g_UsbHcdInfo.ep_info[index].p_data, 
							g_UsbHcdInfo.ep_info[index].data_length, KAL_FALSE);
	}
	else
	{
		if((g_UsbHcdInfo.ep_info[index].data_length-g_UsbHcdInfo.ep_info[index].sofar)
			>g_UsbHcdInfo.ep_info[index].max_packet_size)
			todo = g_UsbHcdInfo.ep_info[index].max_packet_size;
		else
			todo = g_UsbHcdInfo.ep_info[index].data_length-g_UsbHcdInfo.ep_info[index].sofar;
		
		/* setup bdt. include own bit. */
		WRITE_EP0_BDT_PID(USB_BDT_RX, g_UsbHcdInfo.rx_even_odd,
							(todo<<VUSB_BDT_BC_SHIFT)
							|(g_UsbHcdInfo.ep_info[index].data01<<VUSB_BDT_DATA01_SHIFT)|VUSB_BDT_OWNS_BIT);

		/* toggel data01*/
		g_UsbHcdInfo.ep_info[index].data01^=1;

		/* determine endpoint control type*/
		switch(g_UsbHcdInfo.ep_info[index].ep_type)
		{
		case USB_HCD_ENDPT_CTRL:
			ep_ctrl_type = VUSB_ENDPT_CONTROL;
			break;
		case USB_HCD_ENDPT_BULK:
			ep_ctrl_type = VUSB_ENDPT_BULK_RX;
			break;
		case USB_HCD_ENDPT_INTR:
			ep_ctrl_type = VUSB_ENDPT_BULK_RX;
			break;
		case USB_HCD_ENDPT_ISO:
			ep_ctrl_type = VUSB_ENDPT_ISO_RX;
			break;	
		default:
			ep_ctrl_type = 0;
			ASSERT(0);	
			break;
		}

		DRV_WriteReg8(USB_ENDPT_CTL(0), ep_ctrl_type);

		/* send token in the last step*/
		DRV_WriteReg8(USB_TOKEN, VUSB_TOKEN_IN|(g_UsbHcdInfo.ep_info[index].ep_num&VUSB_TOKEN_ENDPT));
	}
}


static void USB_HCD_Queue_Pkt(kal_uint8 index)
{
	kal_int8 *p_head;
	kal_int8 *p_tail;
	
	switch(g_UsbHcdInfo.ep_info[index].ep_type)
	{
	case USB_HCD_ENDPT_BULK:
		p_head = &g_UsbHcdInfo.bulk_pipe_head;
		p_tail = &g_UsbHcdInfo.bulk_pipe_tail;
		break;
	case USB_HCD_ENDPT_CTRL:
		p_head = &g_UsbHcdInfo.ctrl_pipe_head;
		p_tail = &g_UsbHcdInfo.ctrl_pipe_tail;
		break;	
	case USB_HCD_ENDPT_INTR:
		p_head = &g_UsbHcdInfo.intr_pipe_head;
		p_tail = &g_UsbHcdInfo.intr_pipe_tail;
		break;
	case USB_HCD_ENDPT_ISO:
		p_head = &g_UsbHcdInfo.iso_pipe_head;
		p_tail = &g_UsbHcdInfo.iso_pipe_tail;
		break;	
	default:
		p_head = 0;
		p_tail = 0;
		EXT_ASSERT(0, index, g_UsbHcdInfo.ep_info[index].ep_type, 0);
		break;
	}

	if((*p_head)==-1)
	{
		g_UsbHcdInfo.ep_info[index].next_ep_id = -1;
		*p_head = index;
		*p_tail = index;
	}
	else
	{
		g_UsbHcdInfo.ep_info[*p_tail].next_ep_id = index;
		g_UsbHcdInfo.ep_info[index].next_ep_id = -1;
		*p_tail = index;
	}
}

static void USB_HCD_Remove_Pkt(kal_uint8 index)
{
	kal_int8 *p_head;
	kal_int8 *p_tail;
	
	switch(g_UsbHcdInfo.ep_info[index].ep_type)
	{
	case USB_HCD_ENDPT_BULK:
		p_head = &g_UsbHcdInfo.bulk_pipe_head;
		p_tail = &g_UsbHcdInfo.bulk_pipe_tail;
		break;
	case USB_HCD_ENDPT_CTRL:
		p_head = &g_UsbHcdInfo.ctrl_pipe_head;
		p_tail = &g_UsbHcdInfo.ctrl_pipe_tail;
		break;	
	case USB_HCD_ENDPT_INTR:
		p_head = &g_UsbHcdInfo.intr_pipe_head;
		p_tail = &g_UsbHcdInfo.intr_pipe_tail;
		break;
	case USB_HCD_ENDPT_ISO:
		p_head = &g_UsbHcdInfo.iso_pipe_head;
		p_tail = &g_UsbHcdInfo.iso_pipe_tail;
		break;	
	default:
		p_head = 0;
		p_tail = 0;
		EXT_ASSERT(0, index, g_UsbHcdInfo.ep_info[index].ep_type, 0);
		break;
	}

	if(g_UsbHcdInfo.ep_info[index].next_ep_id==-1)
	{
		*p_head = -1;
		*p_tail = -1;
	}
	else
	{
		*p_head = g_UsbHcdInfo.ep_info[index].next_ep_id;
		g_UsbHcdInfo.ep_info[index].next_ep_id = -1;
	}
}

static kal_int8 USB_HCD_Get_Pending_Pkts(void)
{
	kal_int8	head = -1;

	if(g_UsbHcdInfo.iso_pipe_head!=-1)
	{
		head = g_UsbHcdInfo.iso_pipe_head;
		// note that it needs to modified if more than one iso pipe	
		if(head!=-1)
		{
			if(g_UsbHcdInfo.ep_info[head].current_interval!=0)
				head = -1;
		}
	}
	else if(g_UsbHcdInfo.intr_pipe_head!=-1)
	{
		// note that it needs to modified if more than one intr pipe
		head = g_UsbHcdInfo.intr_pipe_head;
		if(head!=-1)
		{
			if(g_UsbHcdInfo.ep_info[head].current_interval!=0)
				head = -1;
		}
	}
	else if(g_UsbHcdInfo.ctrl_pipe_head!=-1)
	{
		head = g_UsbHcdInfo.ctrl_pipe_head;
		if(head!=-1)
		{
			if(g_UsbHcdInfo.ep_info[head].current_interval==0)
			{
				USB_HCD_Remove_Pkt(head);
				/* callback to USB stack, timeout error*/
				if(g_UsbHcdInfo.ep_hdlr[head]!=NULL)
					g_UsbHcdInfo.ep_hdlr[head](USB_HCD_TIMEOUT, g_UsbHcdInfo.ep_info[head].sofar);
				head = -1;
			}	
		}
	}
	else if(g_UsbHcdInfo.bulk_pipe_head!=-1)
	{
		head = g_UsbHcdInfo.bulk_pipe_head;
		if(head!=-1)
		{
			if((g_UsbHcdInfo.ep_info[head].current_interval==0) && (g_UsbHcdInfo.ep_info[head].b_fast_mode_enable==KAL_FALSE))
			{
				USB_HCD_Remove_Pkt(head);
				/* callback to USB stack, timeout error*/
				if(g_UsbHcdInfo.ep_hdlr[head]!=NULL)
					g_UsbHcdInfo.ep_hdlr[head](USB_HCD_TIMEOUT, g_UsbHcdInfo.ep_info[head].sofar);
				head = -1;
			}	
		}
	}

	return head;
}

static void USB_HCD_Sched_Pending_Pkts(void)
{
	kal_int8	head = -1;

	head = USB_HCD_Get_Pending_Pkts();
	
	g_UsbHcdInfo.processing_ep_id = head;

	if((head==0) && (g_UsbHcdInfo.ep0_setup==KAL_TRUE))
	{
		USB_HCD_Send_Setup(head);
	}
	else if(head!=-1)
	{
		if(g_UsbHcdInfo.ep_info[head].direction==USB_HCD_PIPE_DIR_IN)
		{
			USB_HCD_Recv_Data(head);
		}
		else
		{
			USB_HCD_Send_Data(head);
		}
	}
}

/* return value means if there is any pipe timeout*/
static void USB_HCD_Update_Interval(void)
{
	kal_int8	pipe_id;

	pipe_id = g_UsbHcdInfo.iso_pipe_head;
	while(pipe_id!=-1)
	{
		if(g_UsbHcdInfo.ep_info[pipe_id].current_interval!=0)
		{
			g_UsbHcdInfo.ep_info[pipe_id].current_interval--;
		}
		pipe_id = g_UsbHcdInfo.ep_info[pipe_id].next_ep_id;
	}

	pipe_id = g_UsbHcdInfo.intr_pipe_head;
	while(pipe_id!=-1)
	{
		if(g_UsbHcdInfo.ep_info[pipe_id].current_interval!=0)
		{
			g_UsbHcdInfo.ep_info[pipe_id].current_interval--;
		}
		pipe_id = g_UsbHcdInfo.ep_info[pipe_id].next_ep_id;
	}

	pipe_id = g_UsbHcdInfo.ctrl_pipe_head;
	while(pipe_id!=-1)
	{
		if(g_UsbHcdInfo.ep_info[pipe_id].current_interval!=0)
		{
			g_UsbHcdInfo.ep_info[pipe_id].current_interval--;
		}
		pipe_id = g_UsbHcdInfo.ep_info[pipe_id].next_ep_id;
	}

	pipe_id = g_UsbHcdInfo.bulk_pipe_head;
	while(pipe_id!=-1)
	{
		if(g_UsbHcdInfo.ep_info[pipe_id].current_interval!=0)
		{
			g_UsbHcdInfo.ep_info[pipe_id].current_interval--;
		}
		pipe_id = g_UsbHcdInfo.ep_info[pipe_id].next_ep_id;
	}

}


/************************************************************
	Fast mode (DMA) functions
*************************************************************/

/* get dma channel for logical endpoint. Only one channel is needed becuase host knows each transfer direction */
void USB_HCD_Get_DMA_Channel(void)
{
	g_UsbHcdInfo.dma_port = DMA_GetChannel(DMA_USB1TX);
}

/* stop DMA channel*/
void USB_HCD_Stop_DMA_Channel(void)
{
	kal_uint32 savedMask;
	kal_uint32 fm_dma_index;

	/* Stop generic DMA */
	if(g_UsbHcdInfo.dma_port != 0)
	{
		if (DMA_CheckRunStat(g_UsbHcdInfo.dma_port))
		{
			DMA_Stop(g_UsbHcdInfo.dma_port);
		}
	
		savedMask = SaveAndSetIRQMask();
		if (DMA_CheckITStat(g_UsbHcdInfo.dma_port))
		{	
			DMA_ACKI(g_UsbHcdInfo.dma_port);
			IRQClearInt(IRQ_DMA_CODE);
		}
		RestoreIRQMask(savedMask);
	}

	/* stop USB DMA actions. Disable DMA*/
	if(g_UsbHcdInfo.dma_dir == USB_TX_EP_TYPE)
		fm_dma_index = VUSB_FM_DMA_TX1;
	else
		fm_dma_index = VUSB_FM_DMA_RX1;
	DRV_WriteReg8(USB_DMA_DIS, 1<<fm_dma_index);

	g_UsbHcdInfo.dma_pktrdy= KAL_FALSE;
	g_UsbHcdInfo.dma_running = KAL_FALSE;

	g_UsbHcdInfo.dma_tx_ep = 0;
	g_UsbHcdInfo.dma_res_tx_ep = 0;
	g_UsbHcdInfo.fast_mode_tx_ep= 0;
	g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
	g_UsbHcdInfo.b_wait_fm_done = KAL_FALSE;
}

/* stop and free DMA channel resource*/
void USB_HCD_Free_DMA_Channel(void)
{
	if(g_UsbHcdInfo.dma_port != 0)
	{
		USB_HCD_Remove_Pkt(g_UsbHcdInfo.dma_index);
		USB_HCD_Stop_DMA_Channel();
		g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
		DMA_FreeChannel(g_UsbHcdInfo.dma_port);
	}	

	g_UsbHcdInfo.dma_port = 0;
}


/* DMA callback */
static void USB_HCD_DMA_Callback(void)
{
	kal_uint32	fm_dma_index;

	/* disable USB DMA*/
	if(g_UsbHcdInfo.dma_dir == USB_TX_EP_TYPE)
		fm_dma_index = VUSB_FM_DMA_TX1;
	else
		fm_dma_index = VUSB_FM_DMA_RX1;
	DRV_WriteReg8(USB_DMA_DIS, 1<<fm_dma_index);

	/* the last pkt length not multiple of MAX_PKT_LEN, send the last pkt if needed */	
	if (g_UsbHcdInfo.dma_pktrdy)
	{	
		if(g_UsbHcdInfo.dma_dir == USB_TX_EP_TYPE)
		{
			/* tx, config the last one packet */
			/* Note that even if fast mode is used, the tx_even_odd is right here because all data has been
			    sent to FIFO, so even_odd calculation when configuring DMA is right */
			WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbHcdInfo.tx_even_odd,
								(g_UsbHcdInfo.ep_info[g_UsbHcdInfo.dma_index].data_length<<VUSB_BDT_BC_SHIFT) |
								(g_UsbHcdInfo.ep_info[g_UsbHcdInfo.dma_index].data01<<VUSB_BDT_DATA01_SHIFT)|VUSB_BDT_OWNS_BIT);

			/* next data01 (data01 is changed before sent out), and even_odd is changed after token done */
			g_UsbHcdInfo.ep_info[g_UsbHcdInfo.dma_index].data01^=1;

			DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_BULK_TX);
			/* send token in the last step*/
			DRV_WriteReg8(USB_TOKEN, VUSB_TOKEN_OUT|(g_UsbHcdInfo.ep_info[g_UsbHcdInfo.dma_index].ep_num&VUSB_TOKEN_ENDPT));
		}
		else
		{
			/* rx, the last one already recevd (short pkt)*/
			/* nothing need to do */
		}
		g_UsbHcdInfo.dma_pktrdy = KAL_FALSE;
	}

	/* if application callback function dose not request to clear drv_runnung set by itself, clear running state here*/
	if(g_UsbHcdInfo.dma_callback_upd_run== KAL_FALSE)
		g_UsbHcdInfo.dma_running = KAL_FALSE;

	if(g_UsbHcdInfo.dma_res_tx_ep==0)
	{
		/* If not tx res, both tx and rx need to check both DMA and USB token done interrupt is handled */
		if(g_UsbHcdInfo.b_wait_fm_done == KAL_FALSE)
		{
			/* fast mode token done has been handled */
			if(g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index]!=NULL)
				g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index](USB_HCD_OK, g_UsbHcdInfo.fast_mode_data_size);
		}
		g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
	}
}

/* DMA setupt function */ 
/* If the last one "callback_upd_run" parameter true => 
     application decides to clear "driver dma running status" by itself*/
void USB_HCD_DMA_Setup(kal_uint32 index, USB_EP_TYPE  type, kal_uint32 addr, kal_uint32 length, 
						kal_bool callback_upd_run)
{
	DMA_INPUT		dma_input;
   	DMA_HWMENU	dma_menu;
	kal_uint32		fm_pkt_num;
	kal_uint32		fm_dma_index;


	ASSERT(g_UsbHcdInfo.dma_running == KAL_FALSE);
	g_UsbHcdInfo.dma_running = KAL_TRUE;

	ASSERT(g_UsbHcdInfo.dma_port!=0);

	g_UsbHcdInfo.dma_callback_upd_run= callback_upd_run;
	g_UsbHcdInfo.dma_dir= type;
   	
	/*DMA_CONFIG*/
	/* single mode */
	dma_menu.TMOD.burst_mode = 0;

	if(type == USB_TX_EP_TYPE)
	{
		dma_menu.master = DMA_USB1TX; 
		fm_dma_index = VUSB_FM_DMA_TX1;
		g_UsbHcdInfo.fast_mode_tx_ep = index;
		g_UsbHcdInfo.dma_res_tx_ep = index;
		g_UsbHcdInfo.dma_tx_ep = index;
	}
	else
	{
		dma_menu.master = DMA_USB1RX; 
		fm_dma_index = VUSB_FM_DMA_RX1;
		g_UsbHcdInfo.fast_mode_tx_ep = 0;	
		g_UsbHcdInfo.dma_res_tx_ep = 0;
		g_UsbHcdInfo.dma_tx_ep = 0;
	}

	dma_input.callback = USB_HCD_DMA_Callback;

	dma_menu.addr = (kal_uint32)addr;
	
	/* half channel */
	if(type == USB_TX_EP_TYPE)
		dma_input.type = DMA_HWTX;
	else
		dma_input.type = DMA_HWRX;
	dma_input.menu = &dma_menu;


	/**** Configure generic DMA *****/
	if(addr&0x3)
	{
		/* address is not 4 bytes aignment, use B2W to copy data */
		dma_menu.TMOD.burst_mode = KAL_TRUE;
		dma_menu.TMOD.cycle = 4;
		dma_input.size = DMA_BYTE; 
		/* must pad length to multile of 4, this is hardware limitation */
		/* copy multiple of 4 bytes to FIFO, but still fill BDT as real packet size */ 
		if((length & 0x3) != 0)
		{
			/* Note that length must be multiple of 4, 
			    so the application receive buffer must be padding to multiple of 4.
			    If not, assert it because it may override the remaining buffer */
			if(type == USB_RX_EP_TYPE)
				EXT_ASSERT(0, type, length, 0);
			/* In tx, just padding the DMA length to multiple of 4
			    The really sent length is determined by BDT but not DMA length */
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
		/* must pad length to multile of 4, this is hardware limit */
		/* copy multiple of 4 bytes to FIFO, but still fill BDT as real packet size */ 
		if((length & 0x3) != 0)
		{
			/* Note that length must be multiple of 4, 
			    so the application receive buffer must be padding to multiple of 4.
			    If not, assert it because it may override the remaining buffer */
			if(type == USB_RX_EP_TYPE)
				EXT_ASSERT(0, type, length, 0);
			/* In tx, just padding the DMA length to multiple of 4
			    The really sent length is determined by BDT but not DMA length */
			dma_input.count = (length + (4-(length & 0x3)))>>2;
		}
		else
		{
			dma_input.count = length>>2;
		}
	}
	
	/* see if it is mutiple of max packet length*/
	/* length % 64 */	
	if(length & 0x3f)
	{
		g_UsbHcdInfo.dma_pktrdy = KAL_TRUE;
		/* the last residue packet size */
		g_UsbHcdInfo.dma_pktlength = length&0x3f;
	}
	else
	{
		g_UsbHcdInfo.dma_res_tx_ep = 0;
		/* do not need one more packet for the residue of 64 bytes*/
		g_UsbHcdInfo.dma_pktrdy = KAL_FALSE;
		/* the last residue packet size */
		g_UsbHcdInfo.dma_pktlength = 0;
	}
	/* Configure DMA */
	DMA_Config_B2W(g_UsbHcdInfo.dma_port, &dma_input, KAL_TRUE, dma_menu.TMOD.burst_mode);
	
	/**** Configure Fast mode *****/
	/* length/64*/
	fm_pkt_num = length >> 6 ;
	/* for rx less than 64 bytes packet, pad to receive 64 bytes*/
	if((g_UsbHcdInfo.dma_pktrdy == KAL_TRUE) && (type == USB_RX_EP_TYPE))
		fm_pkt_num += 1;
		
	/* Setup BDT */
	if(type == USB_TX_EP_TYPE)	 
	{
		WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbHcdInfo.tx_even_odd,
								(USB_EP_BULK_MAXP << VUSB_BDT_BC_SHIFT) |
								(g_UsbHcdInfo.ep_info[index].data01<<VUSB_BDT_DATA01_SHIFT) |VUSB_BDT_OWNS_BIT);
		/* Update data toggle flag*/
		if(fm_pkt_num&0x1)
			g_UsbHcdInfo.ep_info[index].data01^=1;
	}
	else
	{
		WRITE_EP0_BDT_PID(USB_BDT_RX, g_UsbHcdInfo.rx_even_odd,
								(USB_EP_BULK_MAXP << VUSB_BDT_BC_SHIFT) |
								(g_UsbHcdInfo.ep_info[index].data01<<VUSB_BDT_DATA01_SHIFT) |VUSB_BDT_OWNS_BIT);
		/* Update data toggle flag*/
		if(fm_pkt_num&0x1)
			g_UsbHcdInfo.ep_info[index].data01^=1;
	}
	
	/* Set transfer number*/
	DRV_WriteReg8(USB_FM_PKT_NUML, fm_pkt_num&0xff);
	DRV_WriteReg8(USB_FM_PKT_NUMH, (fm_pkt_num>>8)&0xff);
	DRV_WriteReg8(USB_FM_PKT_CNTL, 0);
	DRV_WriteReg8(USB_FM_PKT_CNTH, 0);

	g_UsbHcdInfo.dma_index = index;
	g_UsbHcdInfo.fast_mode_data_size = 0;

	g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
	g_UsbHcdInfo.b_wait_fm_done = KAL_FALSE;

	/* Enable fast mode only if fm_count > 0*/
	if(fm_pkt_num > 0)
	{
		/* Note that this should set before enable DMA */
		g_UsbHcdInfo.b_wait_dma = KAL_TRUE;
		g_UsbHcdInfo.b_wait_fm_done = KAL_TRUE;
		// set IN-NAK timeout as interval * 64 ms
		/* Select DMA channel of fm engine*/
		DRV_WriteReg8(USB_DMA_FM_SELECT, fm_dma_index);
		DRV_WriteReg8(USB_FM_TIMEOUT, g_UsbHcdInfo.ep_info[index].interval);
		if(DRV_Reg8(USB_FM_CTL)&VUSB_FM_CTL_SUCERREN)
			DRV_WriteReg8(USB_FM_CTL, (VUSB_FM_CTL_SUCERREN|VUSB_FM_CTL_FMENB)&(~VUSB_FM_CTL_SUCERREN));
		else
			DRV_WriteReg8(USB_FM_CTL, VUSB_FM_CTL_SUCERREN|VUSB_FM_CTL_FMENB);
	}
	else
	{
		/* Enable DMA only for tx with fm_count==0 */
		/* If tx packet length is less than 64 bytes, this conditionis matched */
		g_UsbHcdInfo.fast_mode_tx_ep = 0;
		DRV_WriteReg8(USB_DMA_ENB, 1<<fm_dma_index);
	}
		
	if(type == USB_RX_EP_TYPE)
	{
		DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_BULK_RX);
		
		/* send token in the last step*/
		DRV_WriteReg8(USB_TOKEN, VUSB_TOKEN_IN|(g_UsbHcdInfo.ep_info[index].ep_num&VUSB_TOKEN_ENDPT));
	}
	else if((fm_pkt_num > 0) && (type == USB_TX_EP_TYPE))
	{
		/* for only tx res condition, let DMA done handler to send the token*/
		DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_BULK_TX);

		/* send token in the last step*/
		DRV_WriteReg8(USB_TOKEN, VUSB_TOKEN_OUT|(g_UsbHcdInfo.ep_info[index].ep_num&VUSB_TOKEN_ENDPT));
	}	
}



/************************************************************
	HCD HISR
*************************************************************/

void USB_HCD_HISR(void)
{
	volatile kal_uint8	IntrStatus;
	volatile kal_uint8	ErrorStatus;
	volatile kal_uint8	FastErrorStatus;
	volatile kal_uint8	direction;
	volatile kal_uint8	even_odd;
	volatile kal_uint32	status;
	volatile kal_uint8	fm_even_odd;
	kal_uint8			current_ep_index;
	kal_uint8	pkt_length;
	kal_bool			b_fast_mode = KAL_FALSE;
	kal_bool	b_schedule = KAL_FALSE;
	kal_bool	b_dis_schedule = KAL_FALSE;

	g_UsbHcdInfo.b_unmask_irq = KAL_TRUE;

	IntrStatus = DRV_Reg8(USB_INT_STAT)&DRV_Reg8(USB_INT_ENB);
	ErrorStatus = DRV_Reg8(USB_ERR_STAT)&DRV_Reg8(USB_ERR_ENB);
	FastErrorStatus = DRV_Reg8(USB_FM_ERR_STAT);

	/* Get the direction and status of the transfer before clear interrupt status*/      
	direction = (DRV_Reg8(USB_STAT) >> 3) & 0x01;
	even_odd = (DRV_Reg8(USB_STAT) >> 2) & 0x01;
		
	/* Clear interrupt*/
	if(FastErrorStatus&(VUSB_FM_ERR_SHORT_ERR|VUSB_FM_ERR_NAK_ERR|VUSB_FM_ERR_SUC_ERR))
	{
		/* Should handle short packet here */
		DRV_WriteReg8(USB_FM_ERR_STAT, FastErrorStatus&(VUSB_FM_ERR_SHORT_ERR|VUSB_FM_ERR_NAK_ERR|VUSB_FM_ERR_SUC_ERR));
	}
	DRV_WriteReg8(USB_INT_STAT, IntrStatus);
	DRV_WriteReg8(USB_ERR_STAT, ErrorStatus);

	/* Software should not control to happen this*/
	if(FastErrorStatus&USB_FM_ERR_STA_OVR_FLW)
		EXT_ASSERT(0, FastErrorStatus, 0, 0);

	if (IntrStatus & VUSB_INT_STAT_RESET)
	{
		if(g_UsbHcdInfo.dma_running==KAL_TRUE)
		{
			if((g_UsbHcdInfo.dma_index==-1) || (g_UsbHcdInfo.dma_index!=g_UsbHcdInfo.processing_ep_id))
				EXT_ASSERT(0, g_UsbHcdInfo.dma_index, g_UsbHcdInfo.processing_ep_id, 0);
			if(g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index]!=NULL)
				g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index](USB_HCD_DETATCH, 0);
			USB_HCD_Remove_Pkt(g_UsbHcdInfo.dma_index);
			USB_HCD_Stop_DMA_Channel();
			g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
			 g_UsbHcdInfo.processing_ep_id = -1;
		}

		/* Remove and notify all queued endpoints */
		{
			kal_int8 queue_index = -1;
			queue_index = USB_HCD_Get_Pending_Pkts();
			while(queue_index!=-1)
			{
				USB_HCD_Remove_Pkt(queue_index);
				if(g_UsbHcdInfo.ep_hdlr[queue_index]!=NULL)
					g_UsbHcdInfo.ep_hdlr[queue_index](USB_HCD_DETATCH, 0);
				queue_index = USB_HCD_Get_Pending_Pkts();
			}
		}	
		
		USB_HCD_Process_Detach();
		g_UsbHcdInfo.rx_curent_index = -1;
		g_UsbHcdInfo.tx_curent_index = -1;
		g_UsbHcdInfo.processing_ep_id = -1;
 		
		return;
	} /* End VUSB_INT_STAT_RESET */


	if(IntrStatus&VUSB_INT_STAT_TOKEN_DONE)
	{
		/* update scheduler*/
		current_ep_index = g_UsbHcdInfo.processing_ep_id;
		USB_HCD_Remove_Pkt(g_UsbHcdInfo.processing_ep_id);
		g_UsbHcdInfo.processing_ep_id = -1;
		
		if(direction==USB_BDT_RX)
		{
			status = READ_EP0_BDT_PID(USB_BDT_RX, even_odd)&VUSB_BDT_PID_MASKS;
		}
		else
		{
			status = READ_EP0_BDT_PID(USB_BDT_TX, even_odd)&VUSB_BDT_PID_MASKS;
		}

		/* re-queue the NAK or error packets to the end*/
		if((g_UsbHcdInfo.ep_info[current_ep_index].ep_type!=USB_HCD_ENDPT_ISO)
			&& ((status==VUSB_BDT_BUS_TIMEOUT_PID) || (status == VUSB_BDT_NAK_PID) ||
				(status == VUSB_BDT_ERROR_PID) || (status == VUSB_BDT_STALL_PID) || (ErrorStatus)))
		{
			if(direction==USB_BDT_RX)
			{
				g_UsbHcdInfo.rx_curent_index = -1;
				/* next even odd */
				g_UsbHcdInfo.rx_even_odd = even_odd^1;
			}
			else
			{
				g_UsbHcdInfo.tx_curent_index = -1;
				/* next even odd */
				g_UsbHcdInfo.tx_even_odd = even_odd^1;
			}
			/* toggel data 01, return to original data 01*/
			g_UsbHcdInfo.ep_info[current_ep_index].data01^=1;

			/* fast mode timeout error */
			if(FastErrorStatus&(VUSB_FM_ERR_NAK_ERR|VUSB_FM_ERR_SUC_ERR))
			{
				USB_HCD_Stop_DMA_Channel();
				g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
				/* the actaul size that fast mode complete */
				g_UsbHcdInfo.fast_mode_data_size = 
					(DRV_Reg8(USB_FM_PKT_CNTL) + (DRV_Reg8(USB_FM_PKT_CNTH)<<8)) << 6;

				/* decide the next even/odd BDT*/
				if(direction==USB_BDT_RX)
				{
					fm_even_odd = (DRV_Reg8(USB_FM_CTL)&(1<<VUSB_FM_CTL_EP_RX_ODD_SHIFT))>>VUSB_FM_CTL_EP_RX_ODD_SHIFT;
					g_UsbHcdInfo.rx_even_odd = fm_even_odd;
				}
				else
				{
					fm_even_odd = (DRV_Reg8(USB_FM_CTL)&(1<<VUSB_FM_CTL_EP_TX_ODD_SHIFT))>>VUSB_FM_CTL_EP_TX_ODD_SHIFT;
					g_UsbHcdInfo.tx_even_odd = fm_even_odd;
				}
				/* this data01 is nak by device, so next data01 is this one*/
				g_UsbHcdInfo.ep_info[current_ep_index].data01 = (DRV_Reg8(USB_FM_CTL)&(1<<VUSB_FM_CTL_EP_TOG_BIT_SHIFT))>>VUSB_FM_CTL_EP_TOG_BIT_SHIFT;
					
				/* Since it is timeout, there should not be short error */
				if(FastErrorStatus&VUSB_FM_ERR_SHORT_ERR)
				{
					EXT_ASSERT(0, FastErrorStatus, g_UsbHcdInfo.fast_mode_data_size, 0);
				}	

				/* callback to application */
				if(g_UsbHcdInfo.ep_hdlr[current_ep_index]!=NULL)
					g_UsbHcdInfo.ep_hdlr[current_ep_index](USB_HCD_TIMEOUT, g_UsbHcdInfo.fast_mode_data_size);
			}	
			else if(status==VUSB_BDT_STALL_PID)
			{
				/* If in fast mode, stop DMA */
				if(g_UsbHcdInfo.dma_running==KAL_TRUE)
				{
					USB_HCD_Stop_DMA_Channel();
					g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
					
					/* the actaul size that fast mode complete */
					g_UsbHcdInfo.fast_mode_data_size = 
						(DRV_Reg8(USB_FM_PKT_CNTL) + (DRV_Reg8(USB_FM_PKT_CNTH)<<8)) << 6;

					b_fast_mode = KAL_TRUE;
						
					/* decide the next even/odd BDT*/
					if(direction==USB_BDT_RX)
					{
						fm_even_odd = (DRV_Reg8(USB_FM_CTL)&(1<<VUSB_FM_CTL_EP_RX_ODD_SHIFT))>>VUSB_FM_CTL_EP_RX_ODD_SHIFT;
						g_UsbHcdInfo.rx_even_odd = fm_even_odd;
					}
					else
					{
						fm_even_odd = (DRV_Reg8(USB_FM_CTL)&(1<<VUSB_FM_CTL_EP_TX_ODD_SHIFT))>>VUSB_FM_CTL_EP_TX_ODD_SHIFT;
						g_UsbHcdInfo.tx_even_odd = fm_even_odd;
					}
				}
				
				/* callback to USB stack, stall error*/
				if(g_UsbHcdInfo.ep_hdlr[current_ep_index]!=NULL)
				{
					if(b_fast_mode==KAL_TRUE)
						g_UsbHcdInfo.ep_hdlr[current_ep_index](USB_HCD_STALL, g_UsbHcdInfo.fast_mode_data_size);	
					else
						g_UsbHcdInfo.ep_hdlr[current_ep_index](USB_HCD_STALL, g_UsbHcdInfo.ep_info[current_ep_index].sofar);
				}	
			}
			/* if ep0 dose not response*/
			else if(status==VUSB_BDT_BUS_TIMEOUT_PID)
			{
				/* When plug out cable and dma done but not doing DMA HISR , it may happen for fast mode*/
				if(g_UsbHcdInfo.dma_running==KAL_TRUE)
				{
					/*  g_UsbHcdInfo.processing_ep_id may be set to -1 in TOKEN_DONE intr handler */
					if(g_UsbHcdInfo.dma_index==-1)
						EXT_ASSERT(0, g_UsbHcdInfo.dma_index, g_UsbHcdInfo.processing_ep_id, 0);
					if(g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index]!=NULL)
						g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index](USB_HCD_NO_RESPONSE, 0);
					USB_HCD_Stop_DMA_Channel();
					g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
			 		g_UsbHcdInfo.processing_ep_id = -1;
				}
				else
				{
					g_UsbHcdInfo.ep_info[current_ep_index].no_response_count++;
					if(g_UsbHcdInfo.ep_info[current_ep_index].no_response_count>=3)
					{
						if(g_UsbHcdInfo.ep_hdlr[current_ep_index]!=NULL)
							g_UsbHcdInfo.ep_hdlr[current_ep_index](USB_HCD_NO_RESPONSE, g_UsbHcdInfo.ep_info[current_ep_index].sofar);
				
						/* do not queue this packet*/	
					}
					else
					{
						/* queue to the end */
						USB_HCD_Queue_Pkt(current_ep_index);
					}
				}	
			}
			else	 /* may be NAK */
			{
				if(g_UsbHcdInfo.dma_running==KAL_TRUE)
				{
					/*  g_UsbHcdInfo.processing_ep_id may be set to -1 in TOKEN_DONE intr handler */
					if(g_UsbHcdInfo.dma_index==-1)
						EXT_ASSERT(0, g_UsbHcdInfo.dma_index, g_UsbHcdInfo.processing_ep_id, 0);
					if(g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index]!=NULL)
						g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index](USB_HCD_NO_RESPONSE, 0);
					USB_HCD_Stop_DMA_Channel();
					g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
			 		g_UsbHcdInfo.processing_ep_id = -1;
				}	
				else
				{
					/* queue to the end */
					USB_HCD_Queue_Pkt(current_ep_index);
				}	
			}	
			
			//b_schedule = KAL_TRUE;
			b_dis_schedule = KAL_TRUE;
		}
		else	 /*VUSB_BDT_BUS_TIMEOUT_PID || VUSB_BDT_NAK_PID || VUSB_BDT_ERROR_PID */
		{
			/* Token done without error status */
			/* update status and copy to user memory*/
			if(direction==USB_BDT_RX)
			{
				if(g_UsbHcdInfo.rx_curent_index==-1)
					EXT_ASSERT(0, 0, 0, 0);
				current_ep_index = g_UsbHcdInfo.rx_curent_index;
				g_UsbHcdInfo.rx_curent_index = -1;

				if(current_ep_index == g_UsbHcdInfo.dma_index)
				{
					/* fast mode packet */
					if(g_UsbHcdInfo.dma_dir != USB_RX_EP_TYPE)
						EXT_ASSERT(0, g_UsbHcdInfo.dma_dir, g_UsbHcdInfo.dma_index, 0);

					/* decide the next even/odd BDT*/
					fm_even_odd = (DRV_Reg8(USB_FM_CTL)&(1<<VUSB_FM_CTL_EP_RX_ODD_SHIFT))>>VUSB_FM_CTL_EP_RX_ODD_SHIFT;
					g_UsbHcdInfo.rx_even_odd = fm_even_odd;

					/* calculate the received packet size */
					/* fast mode size = fast count *64*/
					g_UsbHcdInfo.fast_mode_data_size = 
								(DRV_Reg8(USB_FM_PKT_CNTL) + (DRV_Reg8(USB_FM_PKT_CNTH)<<8)) << 6;
					/* the last received packet size */
					if(FastErrorStatus&VUSB_FM_ERR_SHORT_ERR)
					{
						/* got the short packet length according to current BDT */
						pkt_length = (READ_EP0_BDT_PID(USB_BDT_RX, fm_even_odd^1)&VUSB_BDT_BC_MASK)
									>>VUSB_BDT_BC_SHIFT;
						/* The short one should be subtracted */
						g_UsbHcdInfo.fast_mode_data_size -= 64;
						g_UsbHcdInfo.fast_mode_data_size += pkt_length;

						/* this data01 is sent by device, so next data01 is this one*/
						g_UsbHcdInfo.ep_info[current_ep_index].data01 = (DRV_Reg8(USB_FM_CTL)&(1<<VUSB_FM_CTL_EP_TOG_BIT_SHIFT))>>VUSB_FM_CTL_EP_TOG_BIT_SHIFT;
					}	

					if(g_UsbHcdInfo.fast_mode_data_size==0)
					{
						/* no need DMA, stop it. Otherwise it will hang */
						USB_HCD_Stop_DMA_Channel();
						g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
					}
											
					if( (DRV_Reg8(USB_FM_PKT_NUML) + (DRV_Reg8(USB_FM_PKT_NUMH)<<8))
						!=(DRV_Reg8(USB_FM_PKT_CNTL) + (DRV_Reg8(USB_FM_PKT_CNTH)<<8)) )
					{
						/* no need DMA, stop it. Otherwise it will hang */
						USB_HCD_Stop_DMA_Channel();
						g_UsbHcdInfo.b_wait_dma = KAL_FALSE;
							
					}
											
					if(g_UsbHcdInfo.b_wait_dma == KAL_FALSE)
					{
						if(g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index]!=NULL)
							g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index](USB_HCD_OK, g_UsbHcdInfo.fast_mode_data_size );

						//b_schedule = KAL_TRUE;
						b_dis_schedule = KAL_TRUE;
					}
					g_UsbHcdInfo.b_wait_fm_done = KAL_FALSE;
				}
				else
				{
					/* normal mode, copy to user memory */
					pkt_length = (READ_EP0_BDT_PID(USB_BDT_RX, even_odd)&VUSB_BDT_BC_MASK)
								>>VUSB_BDT_BC_SHIFT;
					if(pkt_length>g_UsbHcdInfo.ep_info[current_ep_index].data_length)
					{
						EXT_ASSERT(0, current_ep_index, pkt_length, 
									g_UsbHcdInfo.ep_info[current_ep_index].data_length);
					}
					if((g_UsbHcdInfo.ep_info[current_ep_index].sofar+pkt_length)>g_UsbHcdInfo.ep_info[current_ep_index].data_length)
					{
						EXT_ASSERT(0, current_ep_index, g_UsbHcdInfo.ep_info[current_ep_index].sofar, 
									g_UsbHcdInfo.ep_info[current_ep_index].data_length);
					}

					kal_mem_cpy(&g_UsbHcdInfo.ep_info[current_ep_index].p_data[g_UsbHcdInfo.ep_info[current_ep_index].sofar], 
					(void*)READ_EP0_BDT_ADDR(USB_BDT_RX, even_odd), pkt_length);	

					g_UsbHcdInfo.ep_info[current_ep_index].sofar+=pkt_length;
					
					/* This one is recvd, software will fill next packet*/
					g_UsbHcdInfo.rx_even_odd = even_odd^1;

					if((g_UsbHcdInfo.ep_info[current_ep_index].sofar==g_UsbHcdInfo.ep_info[current_ep_index].data_length)
						|| (pkt_length<g_UsbHcdInfo.ep_info[current_ep_index].max_packet_size))
					{
						/* callback to USB stack*/
						if(g_UsbHcdInfo.ep_hdlr[current_ep_index]!=NULL)
							g_UsbHcdInfo.ep_hdlr[current_ep_index](USB_HCD_OK, g_UsbHcdInfo.ep_info[current_ep_index].sofar);
					}
					else
					{
						//queue to scheduler
						USB_HCD_Queue_Pkt(current_ep_index);
					}
					//b_schedule = KAL_TRUE;
					b_dis_schedule = KAL_TRUE;
				}	
			}
			else
			{
				if(g_UsbHcdInfo.tx_curent_index==-1)
					EXT_ASSERT(0, 0, 0, 0);
				current_ep_index = g_UsbHcdInfo.tx_curent_index;
				g_UsbHcdInfo.tx_curent_index = -1;

				if(current_ep_index == g_UsbHcdInfo.dma_index)
				{
					/* fast mode packet */
					if(g_UsbHcdInfo.dma_dir != USB_TX_EP_TYPE)
						EXT_ASSERT(0, g_UsbHcdInfo.dma_dir, g_UsbHcdInfo.dma_index, 0);

					if(g_UsbHcdInfo.fast_mode_tx_ep != 0)
					{
						/* This is Fast mode token done intr */
						g_UsbHcdInfo.fast_mode_tx_ep = 0;

						/* calculate the sent packet size */
						/* fast mode size = fast count *64*/
						g_UsbHcdInfo.fast_mode_data_size = 
									(DRV_Reg8(USB_FM_PKT_CNTL) + (DRV_Reg8(USB_FM_PKT_CNTH)<<8)) << 6;
						/* tx should not send short pkt, the last one should use tx_res method */
						if(FastErrorStatus&VUSB_FM_ERR_SHORT_ERR)
						{
							EXT_ASSERT(0, FastErrorStatus, g_UsbHcdInfo.fast_mode_data_size, current_ep_index);
						}
	
						if(g_UsbHcdInfo.dma_res_tx_ep==0)
						{
							/* No TX data residue */

							/* decide the next even odd */
							fm_even_odd = (DRV_Reg8(USB_FM_CTL)&(1<<VUSB_FM_CTL_EP_TX_ODD_SHIFT))>>VUSB_FM_CTL_EP_TX_ODD_SHIFT;
							g_UsbHcdInfo.tx_even_odd = fm_even_odd;	

							if(g_UsbHcdInfo.b_wait_dma == KAL_FALSE)
							{
								if(g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index]!=NULL)
									g_UsbHcdInfo.ep_hdlr[g_UsbHcdInfo.dma_index](USB_HCD_OK, g_UsbHcdInfo.fast_mode_data_size );
								//b_schedule = KAL_TRUE;
								b_dis_schedule = KAL_TRUE;
							}
							g_UsbHcdInfo.b_wait_fm_done = KAL_FALSE;
						}
					}
					else if(g_UsbHcdInfo.dma_res_tx_ep != 0)
					{
						/* This is the last residue packet token done intr*/
						g_UsbHcdInfo.dma_res_tx_ep = 0;
				
						//read the sent packet length
						pkt_length = (READ_EP0_BDT_PID(USB_BDT_TX, even_odd)&VUSB_BDT_BC_MASK)
									>>VUSB_BDT_BC_SHIFT;
						g_UsbHcdInfo.fast_mode_data_size+=pkt_length;
						if(g_UsbHcdInfo.fast_mode_data_size>g_UsbHcdInfo.ep_info[current_ep_index].data_length)
						{
							EXT_ASSERT(0, current_ep_index, pkt_length, 
										g_UsbHcdInfo.ep_info[current_ep_index].data_length);
						}	

						/* This one is transmitted, software will fill next packet*/
						/* Note that the last res packet is sent in normal mode so use BDT even odd indication*/
						g_UsbHcdInfo.tx_even_odd = even_odd^1;
							
						if(g_UsbHcdInfo.ep_hdlr[current_ep_index]!=NULL)
							g_UsbHcdInfo.ep_hdlr[current_ep_index](USB_HCD_OK, g_UsbHcdInfo.fast_mode_data_size);
						
						//b_schedule = KAL_TRUE;
						b_dis_schedule = KAL_TRUE;
					}
				}
				else
				{
					/* Normal mode */
					
					//read the sent packet length
					pkt_length = (READ_EP0_BDT_PID(USB_BDT_TX, even_odd)&VUSB_BDT_BC_MASK)
								>>VUSB_BDT_BC_SHIFT;
					if(pkt_length>g_UsbHcdInfo.ep_info[current_ep_index].data_length)
					{
						EXT_ASSERT(0, current_ep_index, pkt_length, 
									g_UsbHcdInfo.ep_info[current_ep_index].data_length);
					}	
					if((g_UsbHcdInfo.ep_info[current_ep_index].sofar+pkt_length)>g_UsbHcdInfo.ep_info[current_ep_index].data_length)
					{
						EXT_ASSERT(0, current_ep_index, g_UsbHcdInfo.ep_info[current_ep_index].sofar, 
									g_UsbHcdInfo.ep_info[current_ep_index].data_length);
					}

					g_UsbHcdInfo.ep_info[current_ep_index].sofar+=pkt_length;
					
					/* This one is transmitted, software will fill next packet*/
					g_UsbHcdInfo.tx_even_odd = even_odd^1;

					if((g_UsbHcdInfo.ep_info[current_ep_index].sofar==g_UsbHcdInfo.ep_info[current_ep_index].data_length)
						|| (pkt_length<g_UsbHcdInfo.ep_info[current_ep_index].max_packet_size))
					{
						/* callback to USB stack*/
						if(g_UsbHcdInfo.ep_hdlr[current_ep_index]!=NULL)
							g_UsbHcdInfo.ep_hdlr[current_ep_index](USB_HCD_OK, g_UsbHcdInfo.ep_info[current_ep_index].sofar);
					}
					else
					{
						//queue to scheduler
						USB_HCD_Queue_Pkt(current_ep_index);
					}
					
					//b_schedule = KAL_TRUE;
					b_dis_schedule = KAL_TRUE;
				}	
			}
		}	/* End  VUSB_BDT_BUS_TIMEOUT_PID || VUSB_BDT_NAK_PID || VUSB_BDT_ERROR_PID */
	} /* End VUSB_INT_STAT_TOKEN_DONE*/

	if(IntrStatus&VUSB_INT_STAT_SOF)
	{
		 USB_HCD_Update_Interval();
		if((g_UsbHcdInfo.processing_ep_id==-1) 
			&& (g_UsbHcdInfo.b_wait_dma==KAL_FALSE) && (g_UsbHcdInfo.b_wait_fm_done == KAL_FALSE))
		{
			b_schedule = KAL_TRUE;
		}	
	} /* End VUSB_INT_STAT_SOF*/

	if((OTG_Get_State()==OTG_STATE_A_WAIT_BCON) || (OTG_Get_State()==OTG_STATE_B_WAIT_ACON))
	{
		if(IntrStatus&VUSB_INT_STAT_ATTACH)
		{
			if(DRV_Reg8(USB_CTL)&VUSB_CTL_JSTATE)
			{
				DRV_WriteReg8(USB_INT_ENB, DRV_Reg8(USB_INT_ENB)&(~VUSB_INT_ENB_ATTACH));
				USB_HCD_Process_Attach();
			}	
			g_UsbHcdInfo.rx_curent_index = -1;
			g_UsbHcdInfo.tx_curent_index = -1;
			g_UsbHcdInfo.processing_ep_id = -1;
		} /* End VUSB_INT_STAT_ATTACH*/
	}
	
	if(IntrStatus&VUSB_INT_STAT_RESUME)
	{
		USB_HCD_Resume();
	} /* End VUSB_INT_STAT_RESUME*/
	
	if (IntrStatus & VUSB_INT_STAT_SLEEP)
	{
		USB_HCD_Suspend();
	} /* End VUSB_INT_STAT_SLEEP */

	if (IntrStatus & VUSB_INT_STAT_ERROR)
	{
	
	}/* End VUSB_INT_STAT_ERROR */


	if((b_schedule==KAL_TRUE) &&(b_dis_schedule==KAL_FALSE))
		USB_HCD_Sched_Pending_Pkts();

}

#endif	/* __OTG_ENABLE__ */
 
