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
 *    otg_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements otg hardware related functions
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
#include "drv_hisr.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "gpt_sw.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */

#include "isrentry.h"
#include "bmt.h"
#include "eint.h" 

#include "usb_hw.h"
#include "otg_drv.h"
#include "otg_drv_pri.h"
#include "usb_hcd.h"
#include "usb_drv.h"

#ifdef __OTG_ENABLE__

static OTG_Drv_Info g_OtgInfo;

static kal_uint32 OTG_Get_VBUS_Volt(void);
static kal_bool OTG_Is_A_Bus_Valid(void);
static kal_bool OTG_Is_B_Session_Valid(void);
static kal_bool OTG_Is_B_Session_End(void);

static void OTG_Timeout_Hdlr(void *parameter);
static void OTG_Start_Timer(OTG_TIMER_TYPE type, kal_uint32 ticks);
static void OTG_Stop_Timer(void);
static kal_bool OTG_Check_Timer(void);
static kal_bool OTG_Is_TimerOut(OTG_TIMER_TYPE type);
static kal_bool OTG_Is_TimerActive(void);
static OTG_TIMER_TYPE OTG_Get_TimerType(void);
static void OTG_Process_A_Idle(void);
static void OTG_Process_A_Wait_VRise(void);
static void OTG_Process_A_Wait_BCon(void);
static void OTG_Process_A_Host(void);
static void OTG_Process_A_Suspend(void);
static void OTG_Process_A_Peripheral(void);
static void OTG_Process_A_Wait_VFall(void);
static void OTG_Process_B_Idle(void);
static void OTG_Process_B_Session_Valid(void);
static void OTG_Process_B_SRP_Init(void);
static void OTG_Process_B_Peripheral(void);
static void OTG_Process_B_Wait_ACon(void);
static void OTG_Process_B_Host(void);
static void OTG_State_Machine(void);
static void OTG_HISR(void);
static void OTG_LISR(void);
static void OTG_A_Plug_Timer_Callback(void *data);
static void OTG_A_Plug_HISR(void);

/************************************************************
	driver info functions
*************************************************************/

void OTG_Init_Drv_Info(void)
{
	g_OtgInfo.otg_state = OTG_STATE_START;

	g_OtgInfo.host_up_hdlr = NULL;
	g_OtgInfo.host_down_hdlr = NULL;
	g_OtgInfo.device_up_hdlr = NULL;
	g_OtgInfo.device_down_hdlr = NULL;
	g_OtgInfo.a_host_stop_hdlr = NULL;
	g_OtgInfo.b_hnp_fail_hdlr = NULL;
	g_OtgInfo.a_vrise_fail_hdlr = NULL;
	g_OtgInfo.b_srp_fail_hdlr = NULL;
	g_OtgInfo.b_srp_stop_hdlr = NULL;

	g_OtgInfo.a_bus_req = KAL_TRUE;
	g_OtgInfo.a_detect_b_conn = KAL_FALSE;
	g_OtgInfo.a_detect_b_suspend = KAL_FALSE;
	g_OtgInfo.a_detect_b_resume = KAL_FALSE;
	g_OtgInfo.a_suspend_req = KAL_FALSE;
	g_OtgInfo.a_resume_req = KAL_FALSE;
	g_OtgInfo.a_set_b_hnp_enable = KAL_FALSE;

	g_OtgInfo.b_suspend_req = KAL_FALSE;
	g_OtgInfo.b_detect_a_conn = KAL_FALSE;
	g_OtgInfo.b_detect_a_suspend = KAL_FALSE;
	g_OtgInfo.b_detect_a_resume = KAL_FALSE;
	g_OtgInfo.b_srp_request = KAL_FALSE;
	g_OtgInfo.b_hnp_enable = KAL_FALSE;
	
	g_OtgInfo.b_check_session = KAL_FALSE;
	
	g_OtgInfo.timer_on = KAL_FALSE;
	g_OtgInfo.timer_out = KAL_FALSE;
	g_OtgInfo.timer_type = OTG_TIMER_NONE;
	
	g_OtgInfo.device_up = KAL_FALSE;
	g_OtgInfo.host_up = KAL_FALSE;

	g_OtgInfo.b_processing = KAL_FALSE;

	g_OtgInfo.b_unmask_irq = KAL_TRUE;
	g_OtgInfo.is_ProOTGHISR = KAL_FALSE;
	
	if (g_OtgInfo.gpt_handle == 0)
		GPTI_GetHandle(&g_OtgInfo.gpt_handle);
}

void OTG_Register_Drv_Info(OTG_DRV_HDLR_TYPE type, otg_intr_handler_ptr hdlr)
{
	switch(type)
	{
	case OTG_DRV_HDLR_HOST_UP:
		g_OtgInfo.host_up_hdlr = hdlr;	
		break;
	case OTG_DRV_HDLR_HOST_DOWN:
		g_OtgInfo.host_down_hdlr = hdlr;	
		break;
	case OTG_DRV_HDLR_DEVICE_UP:
		g_OtgInfo.device_up_hdlr = hdlr;	
		break;
	case OTG_DRV_HDLR_DEVICE_DOWN:		
		g_OtgInfo.device_down_hdlr = hdlr;	
		break;
	case OTG_DRV_HDLR_A_VRISE_FAIL:
		g_OtgInfo.a_vrise_fail_hdlr = hdlr;	
		break;
	case OTG_DRV_HDLR_A_HNP_FAIL:
		g_OtgInfo.a_hnp_fail_hdlr = hdlr;	
		break;
	case OTG_DRV_HDLR_A_HNP_STOP:
		g_OtgInfo.a_hnp_stop_hdlr = hdlr;	
		break;	
	case OTG_DRV_HDLR_B_HNP_FAIL:	
		g_OtgInfo.b_hnp_fail_hdlr = hdlr;	
		break;	
	case OTG_DRV_HDLR_B_SRP_FAIL:
		g_OtgInfo.b_srp_fail_hdlr = hdlr;	
		break;
	case OTG_DRV_HDLR_B_SRP_STOP:
		g_OtgInfo.b_srp_stop_hdlr = hdlr;	
		break;
	case OTG_DRV_HDLR_A_HOST_STOP:
		g_OtgInfo.a_host_stop_hdlr = hdlr;	
		break;	
	case OTG_DRV_HDLR_A_NO_RESPONSE:
		g_OtgInfo.a_no_response_hdlr = hdlr;	
		break;	
	default:	
		ASSERT(0);
		break;
	}
}


void OTG_Drv_Create_ISR(void)
{
	IRQ_Register_LISR(IRQ_USB_CODE, OTG_LISR,"OTG");
	DRV_Register_HISR(DRV_USB_HISR_ID, OTG_HISR);
}

void OTG_Drv_Activate_ISR(void)
{
	g_OtgInfo.b_unmask_irq = KAL_TRUE;	
	IRQSensitivity(IRQ_USB_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_USB_CODE);
}


/************************************************************
	system ctrl functions
*************************************************************/

void OTG_Init_Drv(void)
{
	kal_bool	b_process_state_machine = KAL_FALSE;
	kal_uint32 savedMask;
	volatile kal_uint32 delay;

	/* mask all OTG interupts */
	DRV_WriteReg8(OTG_INT_EN, 0x0);
	/* Clear all OTG interrupts */
	DRV_WriteReg8(OTG_INT_STAT, 0x0);

	/* enable OTG*/
	DRV_WriteReg8(OTG_CTRL, OTG_CTL_OTG_ENABLE);

	DRV_WriteReg8(OTG_INT_EN, 0);

	// wait for stable
	for(delay=0; delay<50000; delay++)
	{}

	savedMask = SaveAndSetIRQMask();
	if(g_OtgInfo.b_processing == KAL_FALSE)
	{
		g_OtgInfo.b_processing = KAL_TRUE;
		b_process_state_machine = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);

	if(b_process_state_machine==KAL_TRUE)
	{
		OTG_State_Machine();
		g_OtgInfo.b_processing = KAL_FALSE;
	}

}

void OTG_Set_Plug_Type(OTG_PLUG_TYPE type)
{
	g_OtgInfo.plug_type = type;
}

OTG_PLUG_TYPE OTG_Get_Plug_Type(void)
{
	return g_OtgInfo.plug_type;
}

/* A- host can request to suspend bus without setting HNP enable
    Note that A should change to un-enumerate state when it suspend bus */
void OTG_A_Suspend_Req(void)
{
	OTG_Set_Status(OTG_STATUS_A_SUSPEND_REQUEST, KAL_TRUE);
}

/* A - host request to resume bus 
    Note that A shoule re-enumerate after it resumr the bus*/
void OTG_A_Resume_Req(void)
{
	OTG_Set_Status(OTG_STATUS_A_RESUME_REQUEST, KAL_TRUE);
}

/* This function should be called when B device is not recognized by A device 
    And B device dose not have HNP capability
    Note that this should only be called when B dose not have HNP capability
*/    
void OTG_A_Stop_Host(void)
{
	OTG_Set_Status(OTG_STATUS_A_BUS_REQUEST, KAL_FALSE);
}

/* A device set HNP enable feature to B device, then call this function to start HNP procedure */
void OTG_A_Start_HNP(void)
{
	OTG_Set_Status(OTG_STATUS_A_SET_B_HNP_ENABLE, KAL_TRUE);
}
	

/* This function should be called when B device is set HNP enabled by host */
void OTG_B_EnDis_HNP(kal_bool set)
{
	OTG_Set_Status(OTG_STATUS_B_HNP_ENABLE, set);
}


void OTG_B_Start_SRP(void)
{
	OTG_Set_Status(OTG_STATUS_B_SRP_REQUEST, KAL_TRUE);
}

void OTG_B_Stop_Host(void)
{
	OTG_Set_Status(OTG_STATUS_B_SUSPEND_REQUEST, KAL_TRUE);
}

void OTG_B_Set_Session_Valid(kal_bool set)
{
	OTG_Set_Status(OTG_STATUS_B_SESSION_VALID, set);
}

void OTG_Set_Status(OTG_STATUS_TYPE type, kal_bool set)
{
	kal_bool	b_process_state_machine = KAL_FALSE;
	kal_uint32 savedMask;

//	USB_Ms_Dbg_Trace(OTG_SET_STATUS, type);
//	USB_Ms_Dbg_Trace(OTG_SET_STATUS, set);
	
	switch(type)
	{
	case OTG_STATUS_A_BUS_REQUEST:
		g_OtgInfo.a_bus_req = set;
		break;
	case OTG_STATUS_A_DETECT_B_CONN:
		g_OtgInfo.a_detect_b_conn = set;
		break;		
	case OTG_STATUS_A_DETECT_B_SUSPEND:
		g_OtgInfo.a_detect_b_suspend = set;
		break;
	case OTG_STATUS_A_DETECT_B_RESUME:
		g_OtgInfo.a_detect_b_resume = set;	
		break;		
	case OTG_STATUS_A_DETECT_B_DATA_PLS:
		g_OtgInfo.a_detect_b_data_pls = set;	
		break;	
	case OTG_STATUS_A_SUSPEND_REQUEST:
		g_OtgInfo.a_suspend_req = set;	
		break;	
	case OTG_STATUS_A_RESUME_REQUEST:
		g_OtgInfo.a_resume_req = set;	
		break;	
	case OTG_STATUS_A_SET_B_HNP_ENABLE:
		g_OtgInfo.a_set_b_hnp_enable = set;	
		break;	
	case OTG_STATUS_B_SESSION_VALID:
		g_OtgInfo.b_session_valid = set;
		break;
	case OTG_STATUS_B_SUSPEND_REQUEST:
		g_OtgInfo.b_suspend_req = set;
		break;	
	case OTG_STATUS_B_DETECT_A_CONN:
		g_OtgInfo.b_detect_a_conn = set;
		break;		
	case OTG_STATUS_B_DETECT_A_SUSPEND:
		g_OtgInfo.b_detect_a_suspend = set;
		break;
	case OTG_STATUS_B_DETECT_A_RESUME:
		g_OtgInfo.b_detect_a_resume = set;	
		break;	
	case OTG_STATUS_B_SRP_REQUEST:
		g_OtgInfo.b_srp_request = set;	
		break;
	case OTG_STATUS_B_HNP_ENABLE:
		g_OtgInfo.b_hnp_enable = set;	
		break;
	default:
		ASSERT(0);
		break;
	}

	/* process OTG state machine*/
	savedMask = SaveAndSetIRQMask();
	if(g_OtgInfo.b_processing == KAL_FALSE)
	{
		g_OtgInfo.b_processing = KAL_TRUE;
		b_process_state_machine = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);
	if(b_process_state_machine==KAL_TRUE)
	{
		OTG_State_Machine();
		g_OtgInfo.b_processing = KAL_FALSE;
	}
	
}

OTG_STATE OTG_Get_State(void)
{
	return g_OtgInfo.otg_state;
}

void OTG_Enable_Device(void)
{
	DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|OTG_CTL_OTG_ENABLE);
	DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|OTG_CTL_DP_HIGH|OTG_CTL_DM_LOW);
}


/************************************************************
	ADC  functions
*************************************************************/
static kal_uint32 OTG_Get_VBUS_Volt(void)
{
	kal_uint8 adc_channel;
	bmt_customized_struct  *charing_para;
	kal_uint16 adc;
	kal_int32 volt;

	adc_channel = custom_adc_get_channel(otg_vbus_adc_channel);

	charing_para=bmt_get_customized_chr_para();

	adc = ADC_GetData(adc_channel);
	volt = (kal_int32)((adc_adc2vol(adc_channel, (double)adc)/100)*charing_para->adc_volt_factor[adc_channel]);

	return volt;
}

static kal_bool OTG_Is_A_Bus_Valid(void)
{
	kal_bool ret = KAL_FALSE;
	kal_uint32 volt;

	volt = OTG_Get_VBUS_Volt();

	if(volt>=4400000)
		ret = KAL_TRUE;

	return ret;
}

static kal_bool OTG_Is_B_Session_Valid(void)
{
	kal_bool ret = KAL_FALSE;
	kal_uint32 volt;

	volt = OTG_Get_VBUS_Volt();

	if(volt>=2100000)
		ret = KAL_TRUE;

	return ret;
}

static kal_bool OTG_Is_B_Session_End(void)
{
	kal_bool ret = KAL_FALSE;
	kal_uint32 volt;

	volt = OTG_Get_VBUS_Volt();

	if(volt<=800000)
		ret = KAL_TRUE;

	return ret;
}


/************************************************************
	Timer  functions
*************************************************************/

/* GPT timeout handler */
static void OTG_Timeout_Hdlr(void *parameter)
{
	kal_bool	b_process_state_machine = KAL_FALSE;
	kal_uint32 savedMask;
	kal_bool b_dev_unmask_irq = KAL_TRUE;

	GPTI_StopItem(g_OtgInfo.gpt_handle);

	/* process OTG state machine*/
	savedMask = SaveAndSetIRQMask();
	g_OtgInfo.timer_out = KAL_TRUE;

	if(g_OtgInfo.b_processing == KAL_FALSE)
	{	
		g_OtgInfo.b_processing = KAL_TRUE;
		b_process_state_machine = KAL_TRUE;
		IRQMask(IRQ_USB_CODE);
	}
	RestoreIRQMask(savedMask);
	if(b_process_state_machine==KAL_TRUE)
	{
		OTG_State_Machine();
		g_OtgInfo.b_processing = KAL_FALSE;

		if(g_OtgInfo.host_up==KAL_TRUE)
			b_dev_unmask_irq = USB_HCD_Get_UnMask_Irq();
		else if(g_OtgInfo.device_up==KAL_TRUE)
			b_dev_unmask_irq = USB_Get_UnMask_Irq();
		if((g_OtgInfo.b_unmask_irq==KAL_TRUE) && (b_dev_unmask_irq == KAL_TRUE))
		   	IRQUnmask(IRQ_USB_CODE);
	}
}


/* The tick uint is ms*/
static void OTG_Start_Timer(OTG_TIMER_TYPE type, kal_uint32 ticks)
{
	if(g_OtgInfo.timer_on==KAL_TRUE)
		EXT_ASSERT(0, (kal_uint32)g_OtgInfo.timer_on, (kal_uint32)g_OtgInfo.timer_type, (kal_uint32)g_OtgInfo.timer_out);

	g_OtgInfo.timer_type = type;
	g_OtgInfo.timer_on = KAL_TRUE;
	g_OtgInfo.timer_out = KAL_FALSE;

	/* If timer is longer than 20 ms, use GPT timer interrupt*/
	if(ticks<20)
	{
		GPT_Start(3);
		/* determine the time out value*/
		g_OtgInfo.timeout_tick = (kal_uint32)GPT_return_current_count();
		g_OtgInfo.timeout_tick+=ticks;
		g_OtgInfo.timeout_tick = g_OtgInfo.timeout_tick&0xffff;
		DRV_WriteReg8(OTG_INT_EN, DRV_Reg8(OTG_INT_EN)|OTG_INT_ENABLE_1_MSEC);
	}
	else
	{
		GPTI_StartItem(g_OtgInfo.gpt_handle, (ticks/10), OTG_Timeout_Hdlr, &g_OtgInfo);
	}	
}

/* stop the timer */
static void OTG_Stop_Timer(void)
{
	DRV_WriteReg8(OTG_INT_EN, DRV_Reg8(OTG_INT_EN)&(~OTG_INT_ENABLE_1_MSEC));	
	GPT_Stop(3);
	GPTI_StopItem(g_OtgInfo.gpt_handle);
	
	g_OtgInfo.timer_on = KAL_FALSE;
	g_OtgInfo.timer_out = KAL_FALSE;	
	g_OtgInfo.timer_type = OTG_TIMER_NONE;	
}

/* used by OTG HISR to chek if timer is timeout or not */
static kal_bool OTG_Check_Timer(void)
{
	kal_uint32 cur_timer_tick;
	kal_bool ret = KAL_FALSE;

	if(g_OtgInfo.timer_on==KAL_FALSE)
		EXT_ASSERT(0, (kal_uint32)g_OtgInfo.timer_on, (kal_uint32)g_OtgInfo.timer_type, (kal_uint32)g_OtgInfo.timer_out);
		
	cur_timer_tick = (kal_uint32)GPT_return_current_count();
	if(cur_timer_tick>=g_OtgInfo.timeout_tick)
	{
		g_OtgInfo.timer_out = KAL_TRUE;
		ret = KAL_TRUE;
	}
	else
	{
		ret = KAL_FALSE;
	}

	return ret;
}

/* return KAL_TRUE if "type" timer is timeout */
static kal_bool OTG_Is_TimerOut(OTG_TIMER_TYPE type)
{
	kal_bool ret = KAL_FALSE;
	
	if((g_OtgInfo.timer_out==KAL_TRUE)&&(g_OtgInfo.timer_type==type))
		ret = KAL_TRUE;

	return ret;
}

/* return if any timer is active*/
static kal_bool OTG_Is_TimerActive(void)
{
	kal_bool	ret = KAL_FALSE;
	
	if((g_OtgInfo.timer_on == KAL_TRUE) || (g_OtgInfo.timer_out == KAL_TRUE))
		ret = KAL_TRUE;

	return ret;
}

/* return active timer type */
static OTG_TIMER_TYPE OTG_Get_TimerType(void)
{
	return g_OtgInfo.timer_type;		
}

/************************************************************
	state machine functions
*************************************************************/
static void OTG_Process_A_Vbus_Fail(void)
{
	/* Restore interrupt. Enable Attach interrupt only */            
	DRV_WriteReg8(USB_INT_ENB, VUSB_INT_ENB_ATTACH);	
			
	g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;

	/* Turn off VBUS*/
	OTG_VBusControl(KAL_FALSE);

	if(g_OtgInfo.host_up==KAL_TRUE)
	{
		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.a_host_stop_hdlr();
		g_OtgInfo.host_down_hdlr();
	}
	if(g_OtgInfo.device_up==KAL_TRUE)
	{
		g_OtgInfo.device_up = KAL_FALSE;
		g_OtgInfo.device_down_hdlr();
	}	

	/* Notify MMI device draws too much current */
	g_OtgInfo.a_vrise_fail_hdlr();
}

static void OTG_Process_A_Idle(void)
{
	if(OTG_Get_Plug_Type()==OTG_PLUG_B)
      	{
      		g_OtgInfo.otg_state = OTG_STATE_B_IDLE;
      		OTG_Process_B_Idle();
      		return;
      	}

	if(g_OtgInfo.a_detect_b_data_pls==KAL_TRUE)
	{
		g_OtgInfo.a_detect_b_data_pls = KAL_FALSE;
		g_OtgInfo.a_process_srp = KAL_TRUE;
		OTG_Start_Timer(OTG_TIMER_A_DATA_PLS, TA_DATA_PLS);
	}
	else if(OTG_Is_TimerOut(OTG_TIMER_A_DATA_PLS)==KAL_TRUE)	
	{
		OTG_Stop_Timer();
		g_OtgInfo.a_process_srp = KAL_FALSE;

		if(((DRV_Reg8(USB_CTL)&VUSB_CTL_SINGLE_ENDED_0)==0) && (DRV_Reg8(OTG_STATUS)&OTG_STATUS_LINE_STATE_CHANGE))
   		{
   			g_OtgInfo.a_detect_b_srp = KAL_TRUE;

   			g_OtgInfo.a_bus_req = KAL_TRUE;
   		} /* Endif  */
	}
#ifdef OTG_A_NOT_INSERTION_BASE	
	else if(OTG_Is_TimerOut(OTG_TIMER_A_ATTATCH_DEBOUNCE) == KAL_TRUE)
	{
		OTG_Stop_Timer();
		if(g_OtgInfo.host_up==KAL_FALSE)
		{
			DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|(OTG_CTL_DP_LOW | OTG_CTL_DM_LOW));
			DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~(OTG_CTL_DP_HIGH | OTG_CTL_DM_HIGH)));	
			
			g_OtgInfo.host_up = KAL_TRUE;
			g_OtgInfo.host_up_hdlr();	
		
			/* Restore interrupt. Enable Attach interrupt only */            
		   DRV_WriteReg8(USB_INT_ENB, VUSB_INT_ENB_ATTACH);
		}
	}
	else if(g_OtgInfo.a_detect_b_resume == KAL_TRUE)
	{
		// compliance test
		// deassert resume	
		g_OtgInfo.a_detect_b_resume = KAL_FALSE;
		
		USB_HCD_Bus_Control(USB_HCD_BUS_DEASSERT_RESUME);
	}
#endif

	if((g_OtgInfo.a_bus_req==KAL_TRUE) || (g_OtgInfo.a_detect_b_srp==KAL_TRUE))
	{
		/* In case go here and SRP timer is still on*/
		OTG_Stop_Timer();
      		
		g_OtgInfo.a_detect_b_srp = KAL_FALSE;
		
		/* If device is up, pull it down*/
		if(g_OtgInfo.device_up==KAL_TRUE)
		{
			g_OtgInfo.device_up = KAL_FALSE;
			g_OtgInfo.device_down_hdlr();
			DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&
							(~(OTG_CTL_DP_HIGH | OTG_CTL_DM_HIGH | OTG_CTL_DP_LOW |OTG_CTL_DM_LOW)) );
		}	

		/* mask all interrupt in case interrupt happens during wating Vrise 
		interrupt will be unmasked when Vrise timer expiers*/
		DRV_WriteReg8(USB_INT_ENB, 0);

		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|(OTG_CTL_DP_LOW | OTG_CTL_DM_LOW));
		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~(OTG_CTL_DP_HIGH | OTG_CTL_DM_HIGH)));	

		/* Do not detect SRP because this system always provide power*/
		/* Turn on VBUS*/
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VRISE;
		OTG_VBusControl(KAL_TRUE);

		OTG_Start_Timer(OTG_TIMER_A_WAIT_VRISE, TA_WAIT_VRISE);
	
		OTG_Process_A_Wait_VRise();
	}	
#ifdef OTG_A_NOT_INSERTION_BASE	
	else if(g_OtgInfo.a_bus_req==KAL_FALSE)
	{
		// for compliance test	
		// start timer to debounce attatch
		if(g_OtgInfo.host_up==KAL_FALSE)
		{
			OTG_Start_Timer(OTG_TIMER_A_ATTATCH_DEBOUNCE, TA_ATTATCH_DEBOUNCE);
		}		
	}
#endif	
}

static void OTG_Process_A_Wait_VRise(void)
{
	if(OTG_Is_A_Bus_Valid()==KAL_TRUE)
	{
		OTG_Stop_Timer();
	
		/* wait for B connect forever*/
      		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;

		if(g_OtgInfo.host_up==KAL_FALSE)
		{
			g_OtgInfo.host_up = KAL_TRUE;
			g_OtgInfo.host_up_hdlr();	
		}	

		/* Restore interrupt. Enable Attach interrupt only */            
		DRV_WriteReg8(USB_INT_ENB, VUSB_INT_ENB_ATTACH);	
	
//		USB_Ms_Dbg_Trace(OTG_STATE_A_VRISE_WAIT_B_CON, 0);
	} 
	else
	{
		if(OTG_Is_TimerOut(OTG_TIMER_A_WAIT_VRISE)==KAL_TRUE)
		{
			OTG_Stop_Timer();
			
			OTG_Process_A_Vbus_Fail();
			return;
		}
	}

	/* Activate check VBUS timer */
	if(OTG_Is_TimerActive()==KAL_FALSE)
	{
		OTG_Start_Timer(OTG_TIMER_A_CHECK_VBUS, TA_CHECK_VBUS);
	}
}


static void OTG_Process_A_Wait_BCon(void)
{
	/* check whether VBUS is maintained above VBUS threshold */
	if(OTG_Is_TimerOut(OTG_TIMER_A_CHECK_VBUS)==KAL_TRUE)
	{
		OTG_Stop_Timer();
		if(OTG_Is_A_Bus_Valid()==KAL_FALSE)
		{
			OTG_Process_A_Vbus_Fail();
			return;
		}
	}
	
	if (g_OtgInfo.a_detect_b_conn==KAL_TRUE) 
      	{
 //     	USB_Ms_Dbg_Trace(OTG_STATE_A_WAIT_B_CON_HOST, 0);
      		g_OtgInfo.otg_state = OTG_STATE_A_HOST;
      	}
#ifdef OTG_A_NOT_INSERTION_BASE
	else if(OTG_Is_TimerOut(OTG_TIMER_A_WAIT_BCON)==KAL_TRUE)
	{
		OTG_Stop_Timer();
		g_OtgInfo.a_bus_req=KAL_FALSE;
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;
		USB_HCD_Bus_Control(USB_HCD_BUS_SUSPEND_SOF);
		/* Turn off VBUS*/
		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~OTG_CTL_VBUS_ON));

		g_OtgInfo.a_no_response_hdlr();
		
		OTG_Process_A_Wait_VFall();
	}
#endif	

#ifdef OTG_A_NOT_INSERTION_BASE
	if(g_OtgInfo.otg_state == OTG_STATE_A_WAIT_BCON)
	{
		if(OTG_Is_TimerActive()==KAL_TRUE)
		{
			if(OTG_Get_TimerType())
			{
				OTG_Stop_Timer();
				OTG_Start_Timer(OTG_TIMER_A_WAIT_BCON, TA_WAIT_BCON);
			}
			else
			{
				ASSERT(0);	
			}
		}
		else
		{
			OTG_Stop_Timer();
			OTG_Start_Timer(OTG_TIMER_A_WAIT_BCON, TA_WAIT_BCON);
		}
	}
	if(OTG_Is_TimerActive()==KAL_FALSE)
	{
		if(g_OtgInfo.otg_state == OTG_STATE_A_WAIT_VFALL)
		{
			OTG_Start_Timer(OTG_TIMER_A_CHECK_VFALL, TA_CHECK_VFALL);
		}
	}	
#else
	/* Activate check VBUS timer */
	if(OTG_Is_TimerActive()==KAL_FALSE)
	{
		OTG_Start_Timer(OTG_TIMER_A_CHECK_VBUS, TA_CHECK_VBUS);
	}
#endif	
}

static void OTG_Process_A_Host(void)
{
	/* check whether VBUS is maintained above VBUS threshold */
	if(OTG_Is_TimerOut(OTG_TIMER_A_CHECK_VBUS)==KAL_TRUE)
	{
		OTG_Stop_Timer();
		if(OTG_Is_A_Bus_Valid()==KAL_FALSE)
		{
			OTG_Process_A_Vbus_Fail();
			return;
		}
	}
#ifdef OTG_A_NOT_INSERTION_BASE
	if(OTG_Get_TimerType()==OTG_TIMER_A_WAIT_BCON)
	{
		OTG_Stop_Timer();
	}
#endif	
	
	/*
      	** If mini B plug is removed RESET (DETACH) interrupt will 
      	** happen on A-Device.The DETACH will processed by the host 
      	** ISR  and set a_detect_b_conn to  FALSE 
      	*/
      	if ((g_OtgInfo.a_detect_b_conn==KAL_FALSE) && (g_OtgInfo.a_detect_b_resume ==KAL_FALSE))
      	{
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;
		if(g_OtgInfo.a_host_stop_hdlr!=NULL)
			g_OtgInfo.a_host_stop_hdlr();
//		USB_Ms_Dbg_Trace(OTG_STATE_A_HOST_WAIT_B_CON, 0);
      	}
      	/************   Starting HNP **************************************
      	** When the A-device is in the a_host state and has set the dual-role 
      	** B-device's HNP enable bit (b_hnp_enable = TRUE ie, a_suspend_req
      	** = TRUE) the A-device shall place the connection to the B-device into 
      	** Suspend when it is finished using the bus.  We can go to the 
      	** suspend state also if user want to power down.
      	*/
      	else if((g_OtgInfo.a_set_b_hnp_enable==KAL_TRUE) && (g_OtgInfo.a_detect_b_resume ==KAL_FALSE))
      	{
		g_OtgInfo.otg_state = OTG_STATE_A_SUSPEND;
		USB_HCD_Bus_Control(USB_HCD_BUS_SUSPEND_SOF);

		/* stop the regilar check Vbus timer before activate another timer */
		if(OTG_Get_TimerType()==OTG_TIMER_A_CHECK_VBUS)
			OTG_Stop_Timer();
		
		OTG_Start_Timer(OTG_TIMER_A_IDLE_BDIS, TA_AIDL_BDIS);

		g_OtgInfo.a_process_hnp = KAL_TRUE;
      	}
	/* A request to suspend the bus */
      	else if(g_OtgInfo.a_suspend_req==KAL_TRUE)
      	{
		g_OtgInfo.otg_state = OTG_STATE_A_SUSPEND;
		USB_HCD_Bus_Control(USB_HCD_BUS_SUSPEND_SOF);
		g_OtgInfo.a_suspend_req = KAL_FALSE;
      	}
      	/* This may be because of B device is not supported by this A device */
      	else if(g_OtgInfo.a_bus_req==KAL_FALSE)
      	{
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;

		USB_HCD_Bus_Control(USB_HCD_BUS_SUSPEND_SOF);
		
		/* Turn off VBUS*/
		OTG_VBusControl(KAL_FALSE);
      	}
      	/* OPT remote wakeup timeout*/
	else if(OTG_Is_TimerOut(OTG_TIMER_A_REMOTE_WAKEUP) == KAL_TRUE)
	{
		OTG_Stop_Timer();

		g_OtgInfo.a_detect_b_resume = KAL_FALSE;
		
//		USB_Ms_Dbg_Trace(OTG_HOST_DEASSERT_RESUME, 0);

		//USB_HCD_Bus_Control(USB_HCD_BUS_DEASSERT_RESUME);
		USB_HCD_Bus_Control(USB_HCD_BUS_RESUME_SOF);
	}

	/* Activate check VBUS timer */
	if(OTG_Is_TimerActive()==KAL_FALSE)
	{
		OTG_Start_Timer(OTG_TIMER_A_CHECK_VBUS, TA_CHECK_VBUS);
	}
}

static void OTG_Process_A_Suspend(void)
{
	/* check whether VBUS is maintained above VBUS threshold */
	if(OTG_Is_TimerOut(OTG_TIMER_A_CHECK_VBUS)==KAL_TRUE)
	{
		OTG_Stop_Timer();
		if(OTG_Is_A_Bus_Valid()==KAL_FALSE)
		{
			OTG_Process_A_Vbus_Fail();
			return;
		}
	}
	
	/* HNP failed */
	if(OTG_Is_TimerOut(OTG_TIMER_A_IDLE_BDIS)==KAL_TRUE)
	{
		OTG_Stop_Timer();

		if(g_OtgInfo.a_process_hnp!=KAL_TRUE)
		{
			ASSERT(0);
		}

		g_OtgInfo.a_process_hnp = KAL_FALSE;

		g_OtgInfo.a_hnp_fail_hdlr();
			
		/* B device done not response for HNP, turn off VBUS at this time*/
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;
		/* Turn off VBUS*/
		OTG_VBusControl(KAL_FALSE);
	}
	
	/* a_detect_b_conn = FALSE if a RESET interrupt happens and it will set by
      	** the application; a_set_b_hnp_en is false as default and set to
      	** if the request is not stalled
      	*/
	else if((g_OtgInfo.a_detect_b_conn==KAL_FALSE)&&(g_OtgInfo.a_set_b_hnp_enable==KAL_FALSE))
	{
      		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;

//      	USB_Ms_Dbg_Trace(OTG_STATE_A_SUSPEND_WAIT_B_CON, 0);
	}
      		
      	/*
      	** If the B-device disconnects after the bus has been suspended, 
      	** then this is an indication that the B-device is attempting 
      	** to become Host. When the A-device detects the disconnect 
      	** from the B-device, it shall turn on its D+ pull-up resistor 
      	** within 3 ms (TA_BDIS_ACON max) to acknowledge
      	** the request from the B-device.
      	*/
      	else if((g_OtgInfo.a_detect_b_conn==KAL_FALSE)&&(g_OtgInfo.a_set_b_hnp_enable==KAL_TRUE))
      	{
      		/* stop OTG_TIMER_A_IDLE_BDIS timer */
      		OTG_Stop_Timer();
		
      		/* start up device*/
      		if((g_OtgInfo.host_up!=KAL_TRUE) || (g_OtgInfo.device_up!=KAL_FALSE))
      			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.host_up, (kal_uint32)g_OtgInfo.device_up, 0);

		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.host_down_hdlr();
      		g_OtgInfo.device_up = KAL_TRUE;
		g_OtgInfo.device_up_hdlr();

		//DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|(OTG_CTL_DP_HIGH | OTG_CTL_DM_LOW));
		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~(OTG_CTL_DM_HIGH | OTG_CTL_DP_LOW)));

		g_OtgInfo.otg_state = OTG_STATE_A_PERIPHERAL;
      		g_OtgInfo.a_set_b_hnp_enable = KAL_FALSE;
      		g_OtgInfo.a_process_hnp = KAL_FALSE;
      		g_OtgInfo.a_hnp_stop_hdlr();
      	} /* Endif */

      	else if (g_OtgInfo.a_resume_req==KAL_TRUE) 
      	{
      		/* stop OTG_TIMER_A_IDLE_BDIS timer */
      		OTG_Stop_Timer();
	
      		if(g_OtgInfo.a_process_hnp==KAL_TRUE)
		{
			g_OtgInfo.a_process_hnp = KAL_FALSE;

			g_OtgInfo.a_hnp_fail_hdlr();
		}
      		
      		g_OtgInfo.otg_state = OTG_STATE_A_HOST;
      		USB_HCD_Bus_Control(USB_HCD_BUS_RESUME_SOF);
      		g_OtgInfo.a_resume_req = KAL_FALSE;
      	} 
      	/* OPT remote wakeup*/
      	else if(g_OtgInfo.a_detect_b_resume == KAL_TRUE)
      	{
      		/* stop OTG_TIMER_A_IDLE_BDIS timer */
      		OTG_Stop_Timer();

      		if(g_OtgInfo.a_process_hnp==KAL_TRUE)
		{
			g_OtgInfo.a_process_hnp = KAL_FALSE;

			g_OtgInfo.a_hnp_fail_hdlr();
		}

      		g_OtgInfo.otg_state = OTG_STATE_A_HOST;
      		g_OtgInfo.a_set_b_hnp_enable = KAL_FALSE;
		OTG_Start_Timer(OTG_TIMER_A_REMOTE_WAKEUP, TA_REMOTE_WAKEUP);
      	}

      	/* Activate check VBUS timer */
	if(OTG_Is_TimerActive()==KAL_FALSE)
	{
		OTG_Start_Timer(OTG_TIMER_A_CHECK_VBUS, TA_CHECK_VBUS);
	}
}

static void OTG_Process_A_Peripheral(void)
{
	/* check whether VBUS is maintained above VBUS threshold */
	if(OTG_Is_TimerOut(OTG_TIMER_A_CHECK_VBUS)==KAL_TRUE)
	{
		OTG_Stop_Timer();
		if(OTG_Is_A_Bus_Valid()==KAL_FALSE)
		{
			OTG_Process_A_Vbus_Fail();
			return;
		}
	}
	
#if 1	/* In the curent design, do not allow host init again*/
	/*
      	** A-device detects lack of bus activity for more than 3 ms 
      	** (TA_BIDL_ADIS min) and turns off its D+ pull-up.Alternatively, 
      	** if the A-device has no further need to communicate with the 
      	** B-device, the A-device may turn off VBUS and end the session.
      	** Sleep INT will be processed by the  device ISR a_detect_b_suspend
      	** variable will be set by the application
      	** The following will be done when this happens:
      	**   
      	**   - disconnect its pull up
      	**   - allow time for the data line to discharge
      	**   - check if the B-device has connected its pull up
      	*/
      	if((g_OtgInfo.a_detect_b_suspend) && ((OTG_Is_TimerActive()==KAL_FALSE) || (OTG_Get_TimerType()==OTG_TIMER_A_CHECK_VBUS)))
      	{
      		OTG_Stop_Timer();
      		/* debounce for OPT4.5-2.9ms */
      		OTG_Start_Timer(OTG_TIMER_A_BIDLE_ADIS, TA_BIDL_ADIS);
      	}
      	else if( (g_OtgInfo.a_detect_b_suspend==KAL_FALSE) && (OTG_Is_TimerOut(OTG_TIMER_A_BIDLE_ADIS)==KAL_TRUE))
      	{
		/* resume or reset during debounce time */
		/* stop OTG_TIMER_A_BIDLE_ADIS timer */
		OTG_Stop_Timer();
      	}
      	else if(OTG_Is_TimerOut(OTG_TIMER_A_BIDLE_ADIS) == KAL_TRUE)
      	{
      		OTG_Stop_Timer();
      		
		/* start up host */
      		if((g_OtgInfo.device_up!=KAL_TRUE) || (g_OtgInfo.host_up!=KAL_FALSE))
      			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.device_up, (kal_uint32)g_OtgInfo.host_up, 0);
		
      		g_OtgInfo.device_up = KAL_FALSE;
		g_OtgInfo.device_down_hdlr();
		g_OtgInfo.host_up = KAL_TRUE;
		g_OtgInfo.host_up_hdlr();
		
		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|(OTG_CTL_DP_LOW | OTG_CTL_DM_LOW));
		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~(OTG_CTL_DP_HIGH | OTG_CTL_DM_HIGH)));

		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;

//		USB_Ms_Dbg_Trace(OTG_STATE_A_PERIPHERAL_WAIT_B_CON, 0);
      	}
#endif

	/* Activate check VBUS timer */
	if(OTG_Is_TimerActive()==KAL_FALSE)
	{
		OTG_Start_Timer(OTG_TIMER_A_CHECK_VBUS, TA_CHECK_VBUS);
	}

// official should be this , but not suitable for OPT test
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
}

static void OTG_Process_A_Wait_VFall(void)
{
	if((OTG_Is_B_Session_Valid()==KAL_FALSE)
		||(OTG_Get_Plug_Type()==OTG_PLUG_B))
	{
		g_OtgInfo.otg_state = OTG_STATE_A_IDLE;
		OTG_Stop_Timer();

		/* In current design, conditions that may go here are 
		    1. B device draws too much current
		    2. A device dose not recognize B device and B device dose not take HNP
		    3. B device return from HNP host
		*/
		g_OtgInfo.a_bus_req = KAL_FALSE;

                /* VBUS has turn off, ignore attach interrupt */
		DRV_WriteReg8(USB_INT_ENB, 0);

		OTG_Process_A_Idle();
	} /* Endif */
#ifdef OTG_A_NOT_INSERTION_BASE	
	else if(g_OtgInfo.a_detect_b_resume == KAL_TRUE)
	{
		// compliance test
		// deassert resume	
		g_OtgInfo.a_detect_b_resume = KAL_FALSE;

		USB_HCD_Bus_Control(USB_HCD_BUS_DEASSERT_RESUME);
	}
	
	if(OTG_Is_TimerOut(OTG_TIMER_A_CHECK_VFALL)==KAL_TRUE)
	{
		OTG_Stop_Timer();
		if(g_OtgInfo.otg_state == OTG_STATE_A_WAIT_VFALL)
		{
			OTG_Start_Timer(OTG_TIMER_A_CHECK_VFALL, TA_CHECK_VFALL);
		}
	}
#endif	
}

static void OTG_Process_B_Idle(void)
{
	/* reset HNP enabled state */
	g_OtgInfo.b_hnp_enable = KAL_FALSE;
	
	/* If host or device is up, pull it down*/
	if(g_OtgInfo.host_up==KAL_TRUE)
	{
		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.host_down_hdlr();
	}
	if(g_OtgInfo.device_up==KAL_TRUE)
	{
		g_OtgInfo.device_up = KAL_FALSE;
		g_OtgInfo.device_down_hdlr();
	}	
	DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&
				(~(OTG_CTL_DP_HIGH | OTG_CTL_DM_HIGH | OTG_CTL_DP_LOW |OTG_CTL_DM_LOW)) );

	/*
	** When a B-device detects that the voltage on VBUS is greater 
	** than the B-Device Session Valid threshold (VSESS_VLD), 
	** then the B-device shall consider a session to be in progress. 
	** After the VBUS voltage crosses this threshold, the B-device 
	** shall assert either the D+ or D- data-line within 100 ms.
	*/
	if(g_OtgInfo.b_session_valid==KAL_TRUE)
	{
		OTG_Process_B_Session_Valid();
	}
	else if(g_OtgInfo.b_srp_request==KAL_TRUE)
	{
		/*  ********* Starting  SRP *****************************************
		** When the B-device detects that VBUS has gone below its Session End 
		** threshold and detects that both D+ and D- have been low (SE0) for 
		** at least 2 ms (TB_SE0_SRP min), then any previous session on the 
		** A-device is over and a new session may start. The B-device may 
		** initiate the SRP any time the initial conditions of Section 5.3.2 
		** are met.
		*/
		/* activate the timer only if we want to do SRP */
		if(OTG_Is_TimerActive() == KAL_FALSE)
		{
			OTG_Start_Timer(OTG_TIMER_B_SE0_SRP, TB_SE0_SRP);

			/* mask all interrupt in case interrupt happens during SRP 
			    The only interrupt tat be be taken is session valid interrupt (by EINT)*/
			DRV_WriteReg8(USB_INT_ENB, 0);
		}

		/* timeout and below session end*/
		if((OTG_Is_TimerOut(OTG_TIMER_B_SE0_SRP)) &&
			(OTG_Is_B_Session_End()==KAL_TRUE))
		{
			OTG_Stop_Timer();

			/*
			** initial conditions are met as described above and then turns 
			** on its data line pull-up resistor (either D+ or D-) for a 
			** period of 5 ms to 10 ms (TB_DATA_PLS). A dual-role B-device is 
			** only allowed to initiate SRP at full-speed, and thus shall 
			** only pull up D+. The duration of such a data line pulse is 
			** sufficient to allow the A-device to reject spurious voltage 
			** transients on the data lines.
			*/
			DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|OTG_CTL_DP_HIGH);

			OTG_Start_Timer(OTG_TIMER_B_DATA_PLS, TB_DATA_PLS);
			
			g_OtgInfo.otg_state = OTG_STATE_B_SRP_INIT;			
			g_OtgInfo.b_check_session = KAL_TRUE;
		}	
	}
}

static void OTG_Process_B_Session_Valid(void)
{	
	if(g_OtgInfo.otg_state==OTG_STATE_B_SRP_INIT)
	{
		/* This section is executed in USB task context*/
		OTG_Stop_Timer();

      		/* DP High off*/
      		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~OTG_CTL_DP_HIGH));
      		/* VBUS charge off */
		//DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~OTG_CTL_VBUS_CHG));
		/* VBUS discharge off*/
		//DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~OTG_CTL_VBUS_DSCHG));

		/* restore the interrupt masked during SRP */
		DRV_WriteReg8(USB_INT_ENB, 0xff&(~(VUSB_INT_ENB_SOF|VUSB_INT_ENB_RESUME)));
	}
	else if(g_OtgInfo.b_srp_request==KAL_TRUE )
	{
		/* In case still measure B session end */
		/* This section is executed in USB task context*/
		OTG_Stop_Timer();

		/* restore the interrupt masked during SRP */
		DRV_WriteReg8(USB_INT_ENB, 0xff&(~(VUSB_INT_ENB_SOF|VUSB_INT_ENB_RESUME)));

		g_OtgInfo.b_srp_stop_hdlr();
	}	

	/* init device */
	if(g_OtgInfo.device_up!=KAL_FALSE)
		EXT_ASSERT(0, (kal_uint32)g_OtgInfo.device_up, 0, 0);

	g_OtgInfo.device_up = KAL_TRUE;
	g_OtgInfo.device_up_hdlr();	
	//DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|(OTG_CTL_DP_HIGH | OTG_CTL_DM_LOW));
	DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~(OTG_CTL_DM_HIGH | OTG_CTL_DP_LOW)));

	g_OtgInfo.b_srp_request = KAL_FALSE;
	g_OtgInfo.otg_state = OTG_STATE_B_PERIPHERAL;
}

static void OTG_Process_B_SRP_Init(void)
{
	volatile kal_uint32 delay = 0;
	
	if((OTG_Is_TimerActive()==KAL_FALSE) || 
	   ((OTG_Get_TimerType()!=OTG_TIMER_B_VBUS_PLS) && (OTG_Get_TimerType()!=OTG_TIMER_B_VBUS_DSCHG)) )
	{
	if(OTG_Is_B_Session_Valid()==KAL_TRUE)
		g_OtgInfo.b_session_valid = KAL_TRUE;
	}
	
	/*
	** When a B-device detects that the voltage on VBUS is greater than the 
	** B-Device Session Valid threshold (VSESS_VLD), then the B-device 
	** shall consider a session to be in progress. After the VBUS voltage
	** crosses this threshold, the B-device shall assert either the D+ or 
	** D- data-line within 100 ms(TB_SVLD_BCON max).
	*/
	//if((DRV_Reg8(OTG_STATUS)&OTG_STATUS_SESS_VLD) && (g_OtgInfo.b_check_session==KAL_TRUE))
	if((g_OtgInfo.b_session_valid==KAL_TRUE) && (g_OtgInfo.b_check_session==KAL_TRUE))
	{
		OTG_Process_B_Session_Valid();
	}
	else 
	{
		/* check_srp_activity */
		if(OTG_Is_TimerOut(OTG_TIMER_B_DATA_PLS)==KAL_TRUE)
		{
			OTG_Stop_Timer();
	
			/* DP High off*/
      			DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~OTG_CTL_DP_HIGH));

			/* An A-device is only required to respond to one of the two 
			** SRP signaling methods. A B-device shall use both methods 
			** when initiating SRP to insure that the A-device responds.
			*/
			g_OtgInfo.b_check_session = KAL_FALSE;

			/* VBUS charge */
			//DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|OTG_CTL_VBUS_CHG);
			OTG_VBusControl(KAL_TRUE);
#if 1			
			for(delay = 0; delay < 25; delay++)
			{}
			
			/* VBUS charge off */
			//DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~OTG_CTL_VBUS_CHG));
			OTG_VBusControl(KAL_FALSE);
			
			OTG_Start_Timer(OTG_TIMER_B_VBUS_DSCHG, TB_VBUS_DSCHRG);
#endif
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
		else if(OTG_Is_TimerOut(OTG_TIMER_B_VBUS_DSCHG)==KAL_TRUE)
		{
			OTG_Stop_Timer();

			/* VBUS discharge off*/
			//DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~OTG_CTL_VBUS_DSCHG));
			g_OtgInfo.b_check_session = KAL_TRUE;

			/* If session is valid then proceed */
			if(g_OtgInfo.b_session_valid==KAL_TRUE)
			{
				OTG_Process_B_Session_Valid();
			}
			else
			{
				/* start the fail timer*/
				OTG_Start_Timer(OTG_TIMER_B_SRP_FAIL, TB_SRP_FAIL);
			}
		}

		/*
		** The error call back have the following requirement:
		** After initiating SRP, the B-device is required to wait at least 
		** 5 seconds (TB_TB_SRP_FAIL min) for the A-device to respond, 
		** before informing the user that the communication attempt 
		** has failed.
		**
		*/
		else if (OTG_Is_TimerOut(OTG_TIMER_B_SRP_FAIL) == KAL_TRUE)
		{
			OTG_Stop_Timer();

			g_OtgInfo.b_srp_request = KAL_FALSE;
			
			g_OtgInfo.otg_state = OTG_STATE_B_IDLE;

			g_OtgInfo.b_srp_fail_hdlr();

			OTG_Process_B_Idle();

			/* restore the interrupt masked during SRP */
			DRV_WriteReg8(USB_INT_ENB, 0xff&(~(VUSB_INT_ENB_SOF|VUSB_INT_ENB_RESUME)));		
		}
	} 
}

static void OTG_Process_B_Peripheral(void)
{
	/* b_detect_a_suspend (SLEEP_INT) will be processed by the DEVICE ISR */
      	/*
      	** B-device detects that bus is idle for more than 3 ms 
      	** (TB_AIDL_BDIS min) and begins HNP by turning off pull-up on D+. 
      	** This allows the bus to discharge to the SE0 state. 
      	** The following will be done when this happens:
      	**   
      	**   disconnect its pull up
      	**   allow time for the data line to discharge
      	**   check if the A-device has connected its pull up
      	*/
	if((g_OtgInfo.b_hnp_enable==KAL_TRUE) && (g_OtgInfo.b_detect_a_suspend==KAL_TRUE) && 
		(OTG_Is_TimerActive()==KAL_FALSE))
	{
		OTG_Start_Timer(OTG_TIMER_A_BUS_SUSPEND, TB_A_SUSPEND);
	}
	else if(OTG_Is_TimerOut(OTG_TIMER_A_BUS_SUSPEND)==KAL_TRUE)	
	{
		OTG_Stop_Timer();

		g_OtgInfo.b_detect_a_suspend = KAL_FALSE;
		
		/* start up host */
      		if((g_OtgInfo.device_up!=KAL_TRUE) || (g_OtgInfo.host_up!=KAL_FALSE))
      			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.device_up, (kal_uint32)g_OtgInfo.host_up, 0);
		
      		g_OtgInfo.device_up = KAL_FALSE;
		g_OtgInfo.device_down_hdlr();
		g_OtgInfo.host_up = KAL_TRUE;
		g_OtgInfo.host_up_hdlr();

		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)|(OTG_CTL_DP_LOW | OTG_CTL_DM_LOW));
		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~(OTG_CTL_DP_HIGH | OTG_CTL_DM_HIGH)));

		g_OtgInfo.otg_state = OTG_STATE_B_WAIT_ACON;
		
      		/* start timer to wait A connect*/		
		OTG_Start_Timer(OTG_TIMER_B_ASE0_BRST, TB_ASE0_BRST);
	}
}

static void OTG_Process_B_Wait_ACon(void)
{
	/*
      	** After waiting long enough to insure that the D+ line 
      	** cannot be high due to the residual effect of the B-device 
      	** pull-up,(see Section 5.1.9), the B-device sees that the 
      	** D+ line is high and D- low, (i.e. J state). This indicates 
      	** that the A-device has recognized the HNP request from the 
      	** B-device. At this point, the B-device becomes Host and 
      	** asserts bus reset to start using the bus. The B-device 
      	** must assert the bus reset (SE0) within 1 ms (TB_ACON_BSE0 max) 
      	** of the time that the A-device turns on its
      	** pull-up.
      	*/
      	/* ATTACH_INT will be processed by the host ISR */
      	if (g_OtgInfo.b_detect_a_conn) 
      	{
      		OTG_Stop_Timer();
      		g_OtgInfo.b_suspend_req = KAL_FALSE;
      		g_OtgInfo.b_hnp_enable = KAL_FALSE;
      		g_OtgInfo.otg_state = OTG_STATE_B_HOST;
      		return;
      	} /* Endif */

      	/*
      	** While waiting in the b_wait_acon state, the B-device 
      	** may detect a K state on the bus. This indicates that the 
      	** A-device is signaling a resume condition and is retaining 
      	** control of the bus. In this case, the B-device will return 
      	** to the b_peripheral state.
      	*/
      	/* 
      	** b_detect_a_resume will be set by the host ISR when K state is 
      	** detected  if (b_detect_a_resume || b_ase0_brst_tmr) 
      	*/
      	else if ((g_OtgInfo.b_detect_a_resume==KAL_TRUE) || 
      		(OTG_Is_TimerOut(OTG_TIMER_B_ASE0_BRST) == KAL_TRUE)) 
      	{
		g_OtgInfo.b_detect_a_resume = KAL_FALSE;

		g_OtgInfo.b_hnp_enable = KAL_FALSE;

		
		/* HNP fail,  this is caused by A device dose not pull up D+*/
		/***********************************************************
      		OPT test 5.8 and 5.9 require that we must display a message
      		when a HNP fails. This event should allow the application
      		to know  that HNP failed with Host.            
      		***********************************************************/
      		if(OTG_Is_TimerOut(OTG_TIMER_B_ASE0_BRST) == KAL_TRUE)
		{
			/* time out */
			g_OtgInfo.b_hnp_fail_hdlr();
		}

      		/* stop the timer */
      		OTG_Stop_Timer();
		
		/* start up device*/
      		if((g_OtgInfo.host_up!=KAL_TRUE) || (g_OtgInfo.device_up!=KAL_FALSE))
      			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.host_up, (kal_uint32)g_OtgInfo.device_up, 0);

		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.host_down_hdlr();
      		g_OtgInfo.device_up = KAL_TRUE;
		g_OtgInfo.device_up_hdlr();

		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~(OTG_CTL_DM_HIGH | OTG_CTL_DP_LOW)));

		g_OtgInfo.otg_state = OTG_STATE_B_PERIPHERAL;
      	} 
}

static void OTG_Process_B_Host(void)
{
	/* 
      	** If the B-device at any time detects more than 3.125 ms of SE0 
      	** (TB_ASE0_BRST min), then this is an indication that the 
      	** A-device is remaining Host and is resetting the bus. In this 
      	** case the B-device shall return to the b_peripheral state 
      	** and start to process the bus reset before TB_ASE0_BRST max.
      	*/

	if((g_OtgInfo.b_suspend_req==KAL_TRUE) || (g_OtgInfo.b_detect_a_conn==KAL_FALSE))
	{
      		/* start up device*/
      		if((g_OtgInfo.host_up!=KAL_TRUE) || (g_OtgInfo.device_up!=KAL_FALSE))
      			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.host_up, (kal_uint32)g_OtgInfo.device_up, 0);

		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.host_down_hdlr();
      		g_OtgInfo.device_up = KAL_TRUE;
		g_OtgInfo.device_up_hdlr();

		DRV_WriteReg8(OTG_CTRL, DRV_Reg8(OTG_CTRL)&(~(OTG_CTL_DM_HIGH | OTG_CTL_DP_LOW)));

		g_OtgInfo.otg_state = OTG_STATE_B_PERIPHERAL;		
	}	
}

kal_bool  OTG_Process_Exceptions(void)
{
	OTG_STATE previous_state = g_OtgInfo.otg_state;

	/* Check exception for A device */
	if ((g_OtgInfo.otg_state < OTG_STATE_B_IDLE)) 
	{
		/* 
		** Exceptions are as follows.
		** 1. Transition to B_IDLE when id = TRUE.
		** 2. Transition to A_WAIT_VFALL when V_BUS is voltage is fallen below 
		** 3. 4 VDC or not able to set the V_BUS voltage.
		*/ 
		if((OTG_Get_Plug_Type()==OTG_PLUG_B) ||
			(OTG_Is_A_Bus_Valid()==KAL_FALSE))
		{
			/* stop any active timers*/
			/* stop the timer */
			OTG_Stop_Timer();

			if ((g_OtgInfo.otg_state== OTG_STATE_A_IDLE) && 
				(OTG_Get_Plug_Type()==OTG_PLUG_B))
			{
				g_OtgInfo.otg_state = OTG_STATE_B_IDLE;
				if(g_OtgInfo.b_srp_request==KAL_TRUE)
					g_OtgInfo.b_srp_stop_hdlr();
				g_OtgInfo.b_srp_request = KAL_FALSE;
				OTG_Process_B_Idle();
			}
			else if((g_OtgInfo.otg_state!=OTG_STATE_A_IDLE) && (g_OtgInfo.otg_state!=OTG_STATE_A_WAIT_VFALL))
			{
				if(g_OtgInfo.a_process_hnp==KAL_TRUE)
					g_OtgInfo.a_hnp_stop_hdlr();	
				g_OtgInfo.a_process_hnp = KAL_FALSE;
				
				g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;
				/* Turn off VBUS*/
				OTG_VBusControl(KAL_FALSE);
				
				OTG_Process_A_Wait_VFall();
			}
		}
	}
	else 
	{
		/*
		** Process B- device exceptions
		*/
		if((OTG_Get_Plug_Type()==OTG_PLUG_A)||
			((g_OtgInfo.b_session_valid==KAL_FALSE)&&(g_OtgInfo.otg_state!=OTG_STATE_B_SRP_INIT)))	
		{
			if(g_OtgInfo.b_srp_request==KAL_TRUE)
				g_OtgInfo.b_srp_stop_hdlr();
			g_OtgInfo.b_srp_request = KAL_FALSE;
	
			if(OTG_Get_Plug_Type()==OTG_PLUG_B)
			{
				g_OtgInfo.otg_state = OTG_STATE_B_IDLE;
				OTG_Process_B_Idle();
			}
			else
			{
				g_OtgInfo.otg_state = OTG_STATE_A_IDLE;
				g_OtgInfo.a_bus_req = KAL_TRUE;
				OTG_Process_A_Idle();
			}
		} 
	}

	if (g_OtgInfo.otg_state!= previous_state)
	{
		/* state changed, exception is processed*/
		return KAL_TRUE;
	}
	else 
	{
		/* state not changed, exception is not processed*/
		return KAL_FALSE;
	}
}

static void OTG_State_Machine(void)
{
	static kal_bool	b_processing = KAL_FALSE;

	if(b_processing==KAL_TRUE)
		ASSERT(0);
	b_processing = KAL_TRUE;

	switch (g_OtgInfo.otg_state) 
	{
	case OTG_STATE_START:
		if(OTG_Get_Plug_Type()==OTG_PLUG_B)
      		{
      			g_OtgInfo.otg_state = OTG_STATE_B_IDLE;
      			OTG_Process_B_Idle();
      		}
      		else 
      		{
      			/* ID is false when A device is identified */
#ifdef OTG_A_NOT_INSERTION_BASE      	
                        // for compliance test
      	                g_OtgInfo.a_bus_req = KAL_FALSE;
#else
      			g_OtgInfo.a_bus_req = KAL_TRUE;
#endif      	
      			g_OtgInfo.otg_state = OTG_STATE_A_IDLE;
      			OTG_Process_A_Idle();
      		}
		break;
	case OTG_STATE_A_IDLE:
		OTG_Process_A_Idle();
		break;
	case OTG_STATE_A_WAIT_VRISE:
		OTG_Process_A_Wait_VRise();
		break;
	case OTG_STATE_A_WAIT_BCON:
		OTG_Process_A_Wait_BCon();
		break;
	case OTG_STATE_A_HOST:
		OTG_Process_A_Host();
		break;
	case OTG_STATE_A_SUSPEND:
		OTG_Process_A_Suspend();
		break;
	case OTG_STATE_A_PERIPHERAL:
		OTG_Process_A_Peripheral();
		break;
	case OTG_STATE_A_WAIT_VFALL:
		OTG_Process_A_Wait_VFall();
		break;
	case OTG_STATE_B_IDLE:
		OTG_Process_B_Idle();
		break;
	case OTG_STATE_B_SRP_INIT:
		OTG_Process_B_SRP_Init();
		break;
	case OTG_STATE_B_PERIPHERAL:
		OTG_Process_B_Peripheral();
		break;
	case OTG_STATE_B_WAIT_ACON:
		OTG_Process_B_Wait_ACon();
		break;
	case OTG_STATE_B_HOST:
		OTG_Process_B_Host();
		break;
	default:
		ASSERT(0);
		break;
	}

	b_processing = KAL_FALSE;
}



static void OTG_HISR(void)
{
	kal_bool	b_dev_unmask_irq = KAL_TRUE;
	kal_bool	b_process_state_machine = KAL_FALSE;
	kal_uint32 savedMask;
	volatile kal_uint8	IntrStatus;

	g_OtgInfo.otg_intr_status = DRV_Reg8(OTG_INT_STAT)&DRV_Reg8(OTG_INT_EN);
	IntrStatus = DRV_Reg8(USB_INT_STAT)&DRV_Reg8(USB_INT_ENB);
	
	/* process OTG state machine*/
	if( g_OtgInfo.otg_intr_status)
	{
		if(g_OtgInfo.otg_intr_status&OTG_INT_STATUS_1_MSEC)
			OTG_Check_Timer();
		savedMask = SaveAndSetIRQMask();
		if(g_OtgInfo.b_processing == KAL_FALSE)
		{
			g_OtgInfo.b_processing = KAL_TRUE;
			b_process_state_machine = KAL_TRUE;
		}
		RestoreIRQMask(savedMask);

		if(b_process_state_machine==KAL_TRUE)
		{
			OTG_State_Machine();
			g_OtgInfo.b_processing = KAL_FALSE;
		}
	} 

	if(g_OtgInfo.host_up==KAL_TRUE)
	{
		/* Check data line pulsing by B device */
		if ((g_OtgInfo.otg_state == OTG_STATE_A_IDLE) && (g_OtgInfo.a_bus_req==KAL_FALSE) &&  
			(IntrStatus & VUSB_INT_STAT_ATTACH) && (g_OtgInfo.a_process_srp == KAL_FALSE)) 
		{
			OTG_Set_Status(OTG_STATUS_A_DETECT_B_DATA_PLS, KAL_TRUE);
			/* clear interrupt and unmask interrupt*/
		   	IRQClearInt(IRQ_USB_CODE);
			if((g_OtgInfo.b_unmask_irq==KAL_TRUE) && (USB_HCD_Get_UnMask_Irq()==KAL_TRUE))
	   			IRQUnmask(IRQ_USB_CODE);
			return ;
		} /* Endif */
			
		USB_HCD_HISR();
		b_dev_unmask_irq = USB_HCD_Get_UnMask_Irq();
	}
	else if(g_OtgInfo.device_up==KAL_TRUE)
	{
		USB_HISR();
		b_dev_unmask_irq = USB_Get_UnMask_Irq();
	}
	else
	{
		DRV_Reg8(USB_INT_STAT) = IntrStatus;
	}


	DRV_Reg8(OTG_INT_STAT) = g_OtgInfo.otg_intr_status;
	/* clear interrupt and unmask interrupt*/
   	IRQClearInt(IRQ_USB_CODE);
   	g_OtgInfo.is_ProOTGHISR = KAL_FALSE;
	if((g_OtgInfo.b_unmask_irq==KAL_TRUE) && (b_dev_unmask_irq == KAL_TRUE))
	   	IRQUnmask(IRQ_USB_CODE);
}

static void OTG_LISR(void)
{
	IRQMask(IRQ_USB_CODE);
	g_OtgInfo.is_ProOTGHISR = KAL_TRUE;
	drv_active_hisr(DRV_USB_HISR_ID);
}



/************************************************************
	A plug detection functions
*************************************************************/
#ifdef __OTG_DETECT_IDPIN_WITH_EINT__
static kal_uint8 g_otg_idpin_state; 
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __OTG_DETECT_IDPIN_WITH_EINT__
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifndef __CUST_NEW__
/* under construction !*/
/* under construction !*/
    #endif /* __CUST_NEW__ */
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
/* under construction !*/
#endif

void OTG_Init_A_Plug_Detect(void)
{
#ifdef __OTG_DETECT_IDPIN_WITH_EINT__
	kal_uint8 otg_idpin_eint = custom_eint_get_channel(otg_idpin_eint_chann);

	g_otg_idpin_state = OTG_IDPIN_CABLE_PLUGOUT_LEVEL;
	EINT_Registration(otg_idpin_eint, KAL_TRUE, OTG_IDPIN_CABLE_PLUGIN_LEVEL, OTG_A_Plug_HISR, KAL_TRUE);
#else
	#ifndef __CUST_NEW__
	/*GPIO mode setting as NFIQ*/
	GPIO_ModeSetup(63, 0x01);
	#endif /* __CUST_NEW__ */
    
	/* ID pin detection*/
	nFIQ_Init(OTG_A_Plug_HISR, KAL_TRUE, KAL_FALSE, LEVEL_SENSITIVE); /* not auto unmask*/	

	if (g_OtgInfo.a_plug_gpt_handle == 0)
		GPTI_GetHandle(&g_OtgInfo.a_plug_gpt_handle);

	g_OtgInfo.a_plug_intr_allow = KAL_FALSE;
	g_OtgInfo.plug_type = OTG_PLUG_B;
#endif
}

static void OTG_A_Plug_Timer_Callback(void *data)
{
	GPTI_StopItem(g_OtgInfo.a_plug_gpt_handle);

	g_OtgInfo.a_plug_intr_allow = (g_OtgInfo.a_plug_intr_allow == KAL_TRUE)? KAL_FALSE: KAL_TRUE;

   /*
    * This timer is to avoid if interrupt status is changed but 
    * sw_debounce->eint_intr_allow is still in KAL_TRUE state
    * because of no interrupt
    */
	if (g_OtgInfo.a_plug_intr_allow) 
	{
		GPTI_StartItem(g_OtgInfo.a_plug_gpt_handle, 5,  OTG_A_Plug_Timer_Callback, data);
	}

	IRQUnmask(IRQ_GPI_CODE);  	
}

static void OTG_A_Plug_HISR(void)
{
#ifdef __OTG_DETECT_IDPIN_WITH_EINT__
	ilm_struct *maplug_ilm;
	kal_uint8 otg_idpin_eint = custom_eint_get_channel(otg_idpin_eint_chann);

	if (g_otg_idpin_state!= OTG_IDPIN_CABLE_PLUGOUT_LEVEL) /*Must modify for different level, plug out*/
	{
		g_otg_idpin_state = OTG_IDPIN_CABLE_PLUGOUT_LEVEL;
		OTG_Set_Plug_Type(OTG_PLUG_B);
		DRV_BuildPrimitive(maplug_ilm,
						MOD_DRV_HISR,
						MOD_USB,
						MSG_ID_USB_A_PLUGOUT_IND,
						NULL);
		msg_send_ext_queue(maplug_ilm);
	}
	else  /* first time USB cable plug in  */
	{
		g_otg_idpin_state = OTG_IDPIN_CABLE_PLUGIN_LEVEL;
		OTG_Set_Plug_Type(OTG_PLUG_A);
		DRV_BuildPrimitive(maplug_ilm,
						MOD_DRV_HISR,
						MOD_USB,
						MSG_ID_USB_A_PLUGIN_IND,
						NULL);
		msg_send_ext_queue(maplug_ilm);	
	}

	EINT_Set_Polarity(otg_idpin_eint,!g_otg_idpin_state);
#else
	ilm_struct *mfiq_ilm;

	GPTI_StopItem(g_OtgInfo.a_plug_gpt_handle);
       if ( g_OtgInfo.a_plug_intr_allow == KAL_FALSE)
       {
		 GPTI_StartItem(g_OtgInfo.a_plug_gpt_handle, 5, OTG_A_Plug_Timer_Callback, &g_OtgInfo.a_plug_gpt_handle);
		 IRQClearInt(IRQ_GPI_CODE);
       }
       else
       {
       	g_OtgInfo.a_plug_intr_allow = KAL_FALSE;
       
		if(DRV_Reg(GPIO_DINV4)&0x8000)
		{
			/* inverse */
            #ifdef __CUST_NEW__
			GPIO_DinvSetup(63, KAL_FALSE);
            #else /* __CUST_NEW__ */
			DRV_WriteReg(GPIO_DINV4, DRV_Reg(GPIO_DINV4)&(~0x8000));
            #endif /* __CUST_NEW__ */
			OTG_Set_Plug_Type(OTG_PLUG_B);
			DRV_BuildPrimitive(mfiq_ilm,
							MOD_DRV_HISR,
							MOD_USB,
							MSG_ID_USB_A_PLUGOUT_IND,
							NULL);
			msg_send_ext_queue(mfiq_ilm);
		}
		else
		{
			/* inverse */
            #ifdef __CUST_NEW__
			GPIO_DinvSetup(63, KAL_TRUE);
            #else /* __CUST_NEW__ */
			DRV_WriteReg(GPIO_DINV4, DRV_Reg(GPIO_DINV4)|0x8000);
            #endif /* __CUST_NEW__ */
			OTG_Set_Plug_Type(OTG_PLUG_A);
			DRV_BuildPrimitive(mfiq_ilm,
							MOD_DRV_HISR,
							MOD_USB,
							MSG_ID_USB_A_PLUGIN_IND,
							NULL);
			msg_send_ext_queue(mfiq_ilm);
		}

		IRQClearInt(IRQ_GPI_CODE);
	   	IRQUnmask(IRQ_GPI_CODE);  	
       }	 	
#endif       
}

#endif

 
