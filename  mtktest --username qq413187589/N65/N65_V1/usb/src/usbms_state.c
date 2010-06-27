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
 *    usbms_state.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file implements usb mass storage state machine
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "drv_comm.h"
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"  
#include "drvsignals.h"

#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usbms_utils.h"
#include "usbms_drv.h"
#include "usbms_adap.h"
#include "usbms_state.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"


/* sense code */
static const kal_uint8 senseOk[] = {0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const kal_uint8 senseNoMedia[] = {0x70, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 
						0x00, 0x00, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00};
static const kal_uint8 senseMediaChanged[] = {0x70, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 
						0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00};
static const kal_uint8 senseInvalidFieldInCDB[] = {0x70, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 
							0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00};
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif							

static void USB_Ms_Recv_Data(local_para_struct *buf);
static void USB_Ms_Transmit_Data(local_para_struct *buf);
static void USB_Ms_Generate_Csw(UsbMs_CSW *CSW, UsbMs_CBW *CBW);
static void USB_Ms_MemInverse(void *src, void *dst, kal_uint16 len);
static void USB_Ms_Cmd(void *data);
//static void USB_Ms_Cmd_Format(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_State_Checkmedia_Exist(kal_uint8 LUN);
static void USB_Ms_Cmd_Inquiry(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Test_Unit_Ready(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Prev_Media_Removal(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Read_Capacity(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Read_FormatCapacity(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_RequestSense(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Verify(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_ModeSense(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_ModeSense6(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Unknown(UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Read(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Handle_Read(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Read_Fail_Handler(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Write(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Handle_Write(kal_uint8 LUN, UsbMs_CBW *CBW, kal_uint8 sector_num);

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/************************************************************
        Tx/Rx path state machine functions
*************************************************************/
void USB_Ms_State_Main(ilm_struct *p_recv_ilm)
{
	UsbMs_CBW *CBW = (UsbMs_CBW*)g_UsbMS.CBWdata;
	
	switch(p_recv_ilm->msg_id)
	{
	case MSG_ID_USB_MSDRV_REC_DONE_CONF:
		/* receive data from DMA callback*/
		USB_Ms_Recv_Data(p_recv_ilm->local_para_ptr);
		break;
		
	case MSG_ID_USB_MSDRV_TRX_DONE_CONF:
		/* transmitted data from DMA callback*/
		USB_Ms_Transmit_Data(p_recv_ilm->local_para_ptr);
		break;

	case MSG_ID_USB_MSDRV_CLEAR_STALL_REQ:
		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWStatusError = 0x01;
		USB_Ms_Generate_Csw(&g_UsbMS.CSW, CBW);
		USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
		break;

	case MSG_ID_USB_MSDRV_RESET_IND:
		/* reset from reset signal or class specific EP0 RESET command*/
		USB_Dbg_Trace(USB_MS_BUILD_DMA_RX_BY_RESET_MSG, drv_get_current_time(), 0, 0);
		g_UsbMS.nState = USBMS_IDLE;
		USB_Ms_BuildRx(g_UsbMS.CBWdata, 31);
		g_UsbMS.is_send_usb_reset_ilm = KAL_TRUE;
		break;
	}
}


/* RX path state machine */
static void USB_Ms_Recv_Data(local_para_struct *buf)
{
	UsbMs_CBW   *CBW;
	kal_uint8   *CBWCB;
	kal_uint8   sector_num;
	usb_ms_rec_done_conf_struct *ptr=(usb_ms_rec_done_conf_struct *)buf;


	switch(g_UsbMS.nState)
	{
	case USBMS_IDLE:
		if (ptr->nBytesRecv != 31)
		{
			EXT_ASSERT(0, ptr->nBytesRecv, 0, 0);
		}
		USB_Ms_Cmd(g_UsbMS.CBWdata);
		break;
	case USBMS_RX:
		CBW = (UsbMs_CBW*)g_UsbMS.CBWdata;
		CBWCB = (kal_uint8 *)CBW->CBWCB;
		if((CBWCB[0] == USBMS_WRITE10)||(CBWCB[0] == USBMS_WRITE12))
		{
			sector_num = ptr->nBytesRecv/512;	
			USB_Ms_Handle_Write(g_UsbMS.current_LUN, CBW, sector_num);		
		}
		else  /*if (CBWCB[0] == USBMS_CMD_Write)*/
		{
			EXT_ASSERT(0, (kal_uint32)CBW->CBWCB[0], 0, 0);
		}
		break;
	case USBMS_GETNEXTCMD:
	case USBMS_ACK:
	case USBMS_TX:
	default:
		EXT_ASSERT(0, (kal_uint32)g_UsbMS.nState, 0, 0);
		break;
	}
}


/* TX path state machine */
static void USB_Ms_Transmit_Data(local_para_struct *buf)
{
	UsbMs_CBW *CBW = (UsbMs_CBW*)g_UsbMS.CBWdata;


	switch(g_UsbMS.nState)
	{
	case USBMS_GETNEXTCMD:
		g_UsbMS.nState = USBMS_IDLE;
		USB_Ms_BuildRx(g_UsbMS.CBWdata, 31);
		break;
	case USBMS_ACK:
		/*Send CSW*/
		g_UsbMS.nState = USBMS_GETNEXTCMD;
		USB_Ms_Generate_Csw(&g_UsbMS.CSW, CBW);
		USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
		break;
	case USBMS_TX:
		if((CBW->CBWCB[0] == USBMS_READ10)||(CBW->CBWCB[0] == USBMS_READ12))
		{
			USB_Ms_Handle_Read(g_UsbMS.current_LUN, CBW);
		}
		else
		{
			EXT_ASSERT(0, (kal_uint32)CBW->CBWCB[0], 0, 0);
		}
		break;
	case USBMS_IDLE:
	case USBMS_RX:
	default:
		EXT_ASSERT(0, (kal_uint32)g_UsbMS.nState, 0, 0);
		break;
	}
}


/************************************************************
        utility functions
*************************************************************/

/* generate CSW element according to CBW and kept status */
static void USB_Ms_Generate_Csw(UsbMs_CSW *CSW, UsbMs_CBW *CBW)
{
//	USB_Ms_Dbg_Trace(USB_DBG_GENERATE_CSW, 0);
	CSW->dCSWSignature = 0x53425355;
	CSW->dCSWTag = CBW->dCBWTag;
	CSW->dCSWDataResidue = g_UsbMS.CSWDataResidue;
	CSW->bmCSWStatus = g_UsbMS.CSWStatusError;
	g_UsbMS.CSWStatusError = 0x00;
	g_UsbMS.CSWDataResidue = 0;
}

/* inverse scr to dst, total len*/
static void USB_Ms_MemInverse(void *src, void *dst, kal_uint16 len)
{
	kal_uint8 index;
	kal_uint8 *li_data = (kal_uint8 *)src;
	kal_uint8 *bi_data = (kal_uint8 *)dst;
	li_data += (len-1);
	for(index = 0; index < len; index++)
	{
		*(bi_data+index) = *(li_data-index);
	}
}


/************************************************************
        CBW parse command functions
*************************************************************/

/* parse CBW command */
static void USB_Ms_Cmd(void *data)
{
	UsbMs_CBW *CBW = (UsbMs_CBW *)data;
	kal_uint8   *CBWCB;


	CBWCB = (kal_uint8*)CBW->CBWCB;

	if((CBW->dCBWSignature != 0x43425355)||(CBW->bCBWLUN > g_UsbMS.max_LUN) ||(USB_Get_DMA_Rx_Count(g_UsbMS.rxpipe->byEP) != 0))
	{
		g_UsbMS.cmd_is_vaild = KAL_FALSE;
		USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
		USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
		return;
	}

	/* keep current LUN */
	g_UsbMS.current_LUN = CBW->bCBWLUN;

	/* determine state */
	if (CBW->dCBWDataTransferLength!=0)
	{
		if (CBW->bmCBWFlags & USBMS_DIR_IN)
			g_UsbMS.nState = USBMS_TX;
		else
			g_UsbMS.nState = USBMS_RX;
	}

//	USB_Ms_Dbg_Trace(USB_DBG_CMD, CBWCB[0]);

	/* parse command */
	switch(CBWCB[0])
	{
//	case USBMS_FORMAT_UNIT:
//		USB_Ms_Cmd_Format(CBW->bCBWLUN, CBW);
//		break;
	case USBMS_INQUIRY:
		USB_Dbg_Trace(USB_MS_CMD_INQUIRY, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_Inquiry(CBW->bCBWLUN, CBW);
		break;
	case USBMS_TEST_UNIT_READY:
		USB_Dbg_Trace(USB_MS_CMD_TESTUNITREADY, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_Test_Unit_Ready(CBW->bCBWLUN, CBW);
		break;
	case USBMS_PREVALLOW_MEDIA_REMOVL:
		USB_Dbg_Trace(USB_MS_CMD_PREVALLOW_MEDIA_REMOVL, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_Prev_Media_Removal(CBW->bCBWLUN, CBW);
		break;
	case USBMS_WRITE10:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_WRITE10, drv_get_current_time(), 0, 0);
		USB_Ms_MemInverse(&CBWCB[7], &g_UsbMS.rw_cmd.BlkLen, 2);
		USB_Ms_Cmd_Write(CBW->bCBWLUN, CBW);
		break;
	case USBMS_WRITE12:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_WRITE12, drv_get_current_time(), 0, 0);
		USB_Ms_MemInverse(&CBWCB[6], &g_UsbMS.rw_cmd.BlkLen, 4);
		USB_Ms_Cmd_Write(CBW->bCBWLUN,CBW);
		break;
	case USBMS_READ10:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_READ10, drv_get_current_time(), 0, 0);
		USB_Ms_MemInverse(&CBWCB[7], &g_UsbMS.rw_cmd.BlkLen, 2);
		USB_Ms_Cmd_Read(CBW->bCBWLUN, CBW);
		break;
	case USBMS_READ12:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_READ12, drv_get_current_time(), 0, 0);
		USB_Ms_MemInverse(&CBWCB[6], &g_UsbMS.rw_cmd.BlkLen, 4);
		USB_Ms_Cmd_Read(CBW->bCBWLUN,CBW);
		break;
	case USBMS_READ_CAPACITY:
		USB_Dbg_Trace(USB_MS_CMD_READ_CAPACITY, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_Read_Capacity(CBW->bCBWLUN, CBW);
		break;
	case USBMS_READ_FORMATCAPACITY:
		USB_Dbg_Trace(USB_MS_CMD_READ_FORMATCAPACITY, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_Read_FormatCapacity(CBW->bCBWLUN, CBW);
		break;
	case USBMS_REQUESTSENSE:
		USB_Dbg_Trace(USB_MS_CMD_REQUESTSENSE, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_RequestSense(CBW->bCBWLUN, CBW);
		break;
	case USBMS_VERIFY:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_VERIFY, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_Verify(CBW->bCBWLUN, CBW);
		break;
	case USBMS_MODE_SENSE:      /* Mode Sense */
		USB_Dbg_Trace(USB_MS_CMD_MODE_SENSE, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_ModeSense(CBW->bCBWLUN, CBW);
		break;
	case USBMS_MODE_SENSE6:      /*Mode Sense*/
		USB_Dbg_Trace(USB_MS_CMD_MODE_SENSE6, drv_get_current_time(), 0, 0);
		USB_Ms_Cmd_ModeSense6(CBW->bCBWLUN, CBW);
		break;
	case USBMS_START_STOP_UNIT:
	case USBMS_MODE_SELECT:
	case USBMS_MODE_SELECT6:
	default:
		USB_Ms_Cmd_Unknown(CBW);
		break;
	}
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
#endif

/* check media status and generate correspongind status for CSW */
static void USB_Ms_State_Checkmedia_Exist(kal_uint8 LUN)
{
	kal_uint8   msdc_status;

//	USB_Ms_Dbg_Trace(USB_DBG_CHECKMEDIA_EXIST, 0);
	msdc_status = USB_Ms_Checkmedia_Exist(LUN);

	switch(msdc_status)
	{
	case USB_STORAGE_DEV_STATUS_OK:
	case USB_STORAGE_DEV_STATUS_WP:
		g_UsbMS.sensePtr = (kal_uint8 *)senseOk;
		g_UsbMS.CSWStatusError = 0x00;
		break;
	case USB_STORAGE_DEV_STATUS_MEDIA_CHANGE:
		g_UsbMS.sensePtr = (kal_uint8 *)senseMediaChanged;
		g_UsbMS.CSWStatusError = 0x01;
		break;
	case USB_STORAGE_DEV_STATUS_NOMEDIA:
		g_UsbMS.sensePtr = (kal_uint8 *)senseNoMedia;
		g_UsbMS.CSWStatusError = 0x01;
		break;
	default:
		ASSERT(0);
//		g_UsbMS.sensePtr = (kal_uint8 *)senseNoMedia;
//		g_UsbMS.CSWStatusError = 0x01;
		break;
	}
}

/* handle CBW USBMS_INQUIRY command */
static void USB_Ms_Cmd_Inquiry(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	USB_Dbg_Trace(USB_MS_CMD_INQUIRY, drv_get_current_time(), 0, 0);
//	USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_INQUIRY, 0);

	if(CBW->dCBWDataTransferLength == 0)
	{
		USB_Ms_State_Checkmedia_Exist(LUN);
		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWDataResidue = 0;
		USB_Ms_Generate_Csw(&g_UsbMS.CSW, CBW);
		USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
	}
	else
	{
		if(CBW->dCBWDataTransferLength <= g_UsbMS.ms_param->inquire_size)
		{
			g_UsbMS.sensePtr = (kal_uint8 *)senseOk;
			g_UsbMS.CSWStatusError = 0x00;
			g_UsbMS.nState = USBMS_ACK;
			g_UsbMS.CSWDataResidue = 0;
			USB_Ms_BuildTx((kal_uint8 *)g_UsbMS.ms_param->inquire_data, CBW->dCBWDataTransferLength);
		}
		else
		{
			g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
			USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
		}
	}
}


/* handle CBW USBMS_TEST_UNIT_READY command */
static void USB_Ms_Cmd_Test_Unit_Ready(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	USB_Dbg_Trace(USB_MS_CMD_TESTUNITREADY, drv_get_current_time(), 0, 0);
//	USB_Ms_Dbg_Trace(USB_DBG_CMD_TESTUNITREADY, LUN);

	if(CBW->dCBWDataTransferLength != 0)
	{
		if(g_UsbMS.nState == USBMS_RX)
		{
			USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
			g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		}
		else
		{
			USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
			g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		}
	}
	else
	{
		USB_Ms_State_Checkmedia_Exist(LUN);
		g_UsbMS.nState = USBMS_GETNEXTCMD;
		USB_Ms_Generate_Csw(&g_UsbMS.CSW,CBW);
		USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
	}
}

/* handle CBW USBMS_PREVALLOW_MEDIA_REMOVL command */
static void USB_Ms_Cmd_Prev_Media_Removal(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_bool msdc_status;

//	USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_PREV_MEDIA_REMOVAL, 0);
	USB_Ms_State_Checkmedia_Exist(LUN);
	if (g_UsbMS.CSWStatusError == 0x00)
	{
		msdc_status = USB_Ms_Prevmedia_Removal(LUN, KAL_TRUE);
		if (msdc_status == KAL_FALSE)
			USB_Ms_State_Checkmedia_Exist(LUN);
	}
	g_UsbMS.nState = USBMS_GETNEXTCMD;
	USB_Ms_Generate_Csw(&g_UsbMS.CSW,CBW);
	USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
}

/* handle CBW USBMS_READ_CAPACITY command */
static void USB_Ms_Cmd_Read_Capacity(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint32 LBA;
	kal_uint32 len;
	kal_bool msdc_status;
	Read_Capacity_Info Capacity_Info;

	USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_READ_CAPACITY, LUN);

	USB_Ms_State_Checkmedia_Exist(LUN);
	if (g_UsbMS.CSWStatusError == 0x00)
	{
		msdc_status = USB_Ms_Read_Capacity(LUN, &LBA, &len);
		if (msdc_status)
		{
			USB_Ms_MemInverse(&LBA, &Capacity_Info.LastBA, 4);
			USB_Ms_MemInverse(&len, &Capacity_Info.BlkLen, 4);
			g_UsbMS.nState = USBMS_ACK;
			USB_Ms_BuildTx(&Capacity_Info, 8);
			return;
		}
		else
		{
			/* device exist but not ready yet, must return error */
			g_UsbMS.CSWStatusError = 0x01;
//			USB_Ms_State_Checkmedia_Exist(LUN);
		}
	}

	/*Fail case*/
	LBA = 0x400000;
	len = 0x200;
	USB_Ms_MemInverse(&LBA,&Capacity_Info.LastBA, 4);
	USB_Ms_MemInverse(&len,&Capacity_Info.BlkLen, 4);
	g_UsbMS.nState = USBMS_ACK;
	USB_Ms_BuildTx(&Capacity_Info, 8);
}

/* handle CBW USBMS_READ_FORMATCAPACITY command */
static void USB_Ms_Cmd_Read_FormatCapacity(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint32 msdc_blk_no;
	kal_uint32 msdc_blk_len;
	kal_uint32 len;
//	kal_uint32 length;
//	kal_bool msdc_status;
//	kal_uint8 ReadformatCapacity_Data[20];
	kal_uint8 ReadformatCapacity_Data[12];
	kal_uint8 *CBWCB = CBW->CBWCB;

	USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_READ_FORMATCAPACITY, LUN);

	len = (kal_uint16)CBWCB[7];
	len <<= 8;
	len |= (kal_uint16)CBWCB[8];

//	USB_Ms_State_Checkmedia_Exist(LUN);

//	if (g_UsbMS.CSWStatusError == KAL_FALSE)
//	{
//		msdc_status = USB_Ms_Read_FormatCapacity(LUN, &msdc_blk_no,&msdc_blk_len);
//		if (msdc_status == KAL_TRUE)
//		{
//			kal_mem_set(ReadformatCapacity_Data, 0x00, 20);
//			ReadformatCapacity_Data[3] = 0x10;
//			USB_Ms_MemInverse(&msdc_blk_no, &ReadformatCapacity_Data[4], 4);
//			USB_Ms_MemInverse(&msdc_blk_len, &ReadformatCapacity_Data[9], 3);
//			USB_Ms_MemInverse(&msdc_blk_no, &ReadformatCapacity_Data[12], 4);
//			USB_Ms_MemInverse(&msdc_blk_len, &ReadformatCapacity_Data[17], 3);
//			ReadformatCapacity_Data[8] = 0x02;
//			if (len >= 20)
//				USB_Ms_BuildTx(ReadformatCapacity_Data,20);
//			else
//				USB_Ms_BuildTx(ReadformatCapacity_Data,len);
//			g_UsbMS.nState = USBMS_ACK;
//			return;
//		}
//		else
//		{
//			USB_Ms_State_Checkmedia_Exist(LUN);
//		}
//	}

	kal_mem_set(ReadformatCapacity_Data, 0x00, 12);
	ReadformatCapacity_Data[3] = 0x08;
	msdc_blk_no = 0xffffffff;
	msdc_blk_len = 0x03000200;
	g_UsbMS.CSWStatusError = 0x00;
	USB_Ms_MemInverse(&msdc_blk_no, &ReadformatCapacity_Data[4], 4);
	USB_Ms_MemInverse(&msdc_blk_len, &ReadformatCapacity_Data[8], 4);

//	USB_Ms_MemInverse(&msdc_blk_no, &ReadformatCapacity_Data[12], 4);
//	USB_Ms_MemInverse(&msdc_blk_len, &ReadformatCapacity_Data[17], 3);
//	ReadformatCapacity_Data[8] = 0x02;
			
//	length = 8; //12-4 = 8
//	msdc_blk_no = 0x400000;
//	msdc_blk_len = 0x03000200;
//	g_UsbMS.CSWStatusError = 0;
//	USB_Ms_MemInverse(&length, &ReadformatCapacity_Data[0], 4);
//	USB_Ms_MemInverse(&msdc_blk_no, &ReadformatCapacity_Data[4], 4);
//	USB_Ms_MemInverse(&msdc_blk_len, &ReadformatCapacity_Data[8], 4);
	g_UsbMS.nState = USBMS_ACK;

	if (len >= 12)
		USB_Ms_BuildTx(ReadformatCapacity_Data, 12);
	else
		USB_Ms_BuildTx(ReadformatCapacity_Data, len);
}

/* handle CBW USBMS_REQUESTSENSE command */
static void USB_Ms_Cmd_RequestSense(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	if(CBW->dCBWDataTransferLength == 0)
	{
		USB_Ms_State_Checkmedia_Exist(LUN);
		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWDataResidue = 0;
		USB_Ms_Generate_Csw(&g_UsbMS.CSW, CBW);
		USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
	}
	else
	{
		if(CBW->dCBWDataTransferLength <= 18)
		{
			g_UsbMS.CSWStatusError = 0x00;
			g_UsbMS.nState = USBMS_ACK;
			g_UsbMS.CSWDataResidue = 0;
			USB_Ms_BuildTx(g_UsbMS.sensePtr, CBW->dCBWDataTransferLength);
		}
		else
		{
			USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
			g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		}
	}
}


/* handle CBW USBMS_VERIFY command */
static void USB_Ms_Cmd_Verify(kal_uint8 LUN, UsbMs_CBW *CBW)
{
//	USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_VERIFY, 0);

	USB_Ms_State_Checkmedia_Exist(LUN);
	USB_Ms_Generate_Csw(&g_UsbMS.CSW,CBW);
	g_UsbMS.nState = USBMS_GETNEXTCMD;
	USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
}

/* handle CBW USBMS_MODE_SENSE6 command */
static void USB_Ms_Cmd_ModeSense(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint8 result;
	kal_uint8 ModeSense_Data[8];

//	USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_MODESENSE6, 0);
	USB_Ms_State_Checkmedia_Exist(LUN);
	result = USB_Ms_Checkmedia_Exist(LUN);

	if(result == USB_STORAGE_DEV_STATUS_WP)
	{
		/* Write Protect */
		ModeSense_Data[0] = 0x00;
		ModeSense_Data[1] = 0x06;
		ModeSense_Data[2] = 0x00;
		ModeSense_Data[3] = 0x80;
		ModeSense_Data[4] = 0x00;
		ModeSense_Data[5] = 0x00;
		ModeSense_Data[6] = 0x00;
		ModeSense_Data[7] = 0x00;
	}
	else
	{
		ModeSense_Data[0] = 0x00;
		ModeSense_Data[1] = 0x06;
		ModeSense_Data[2] = 0x00;
		ModeSense_Data[3] = 0x00;
		ModeSense_Data[4] = 0x00;
		ModeSense_Data[5] = 0x00;
		ModeSense_Data[6] = 0x00;
		ModeSense_Data[7] = 0x00;
	}
	g_UsbMS.nState = USBMS_ACK;
	USB_Ms_BuildTx(ModeSense_Data, 8);
}


/* handle CBW USBMS_MODE_SENSE6 command */
static void USB_Ms_Cmd_ModeSense6(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint8 result;
	kal_uint8 ModeSense6_Data[4];

//	USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_MODESENSE6, 0);
	USB_Ms_State_Checkmedia_Exist(LUN);
	result = USB_Ms_Checkmedia_Exist(LUN);

	if (result == USB_STORAGE_DEV_STATUS_WP)     
	{
		/* Write Protect */
		ModeSense6_Data[0] = 0x03;
		ModeSense6_Data[1] = 0x00;
		ModeSense6_Data[2] = 0x80;
		ModeSense6_Data[3] = 0x00;
	}
	else
	{
		ModeSense6_Data[0] = 0x03;
		ModeSense6_Data[1] = 0x00;
		ModeSense6_Data[2] = 0x00;
		ModeSense6_Data[3] = 0x00;
	}
	g_UsbMS.nState = USBMS_ACK;
	USB_Ms_BuildTx(ModeSense6_Data,4);
}

/* handle CBW unknown command */
static void USB_Ms_Cmd_Unknown(UsbMs_CBW *CBW)
{
//	USB_Ms_Dbg_Trace(USB_DBG_USBMS_UNKNOW_CMD, 0);
	g_UsbMS.sensePtr = (kal_uint8 *)senseInvalidFieldInCDB;
	g_UsbMS.CSWStatusError = 0x01;
	USB_Ms_Generate_Csw(&g_UsbMS.CSW,CBW);
	g_UsbMS.nState = USBMS_GETNEXTCMD;
	USB_Ms_BuildTx(&g_UsbMS.CSW,13);
}


/* handle CBW USBMS_READ command */
static void USB_Ms_Cmd_Read(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint8 *CBWCB = CBW->CBWCB;


	USB_Ms_State_Checkmedia_Exist(LUN);

	USB_Ms_MemInverse(&CBWCB[2], &g_UsbMS.rw_cmd.LBA, 4);
//	USB_Ms_MemInverse(&CBWCB[7], &g_UsbMS.rw_cmd.BlkLen, 2);


	if(g_UsbMS.nState == USBMS_RX)
	{
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
		return;
	}

	if(CBW->dCBWDataTransferLength == 0)
	{
		/* Host expects no data transfers */
		g_UsbMS.CSWStatusError = 0x02;
		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWDataResidue = 0;
		USB_Ms_Generate_Csw(&g_UsbMS.CSW, CBW);
		USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
	}
	else if (g_UsbMS.rw_cmd.BlkLen == 0)
	{
		/* Device expects no data transfers */
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
	}
	else
	{
		if(g_UsbMS.CSWStatusError == 0x00)
		{
			if((g_UsbMS.rw_cmd.BlkLen*512) != CBW->dCBWDataTransferLength)
			{
				USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
				g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
			}
			else
			{
				//USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_READ, g_UsbMS.rw_cmd.BlkLen);
				g_UsbMS.rw_cmd.rwindex = 0;
				g_UsbMS.rw_cmd.msdc_rwindex = 0;
				g_UsbMS.rw_cmd.rw_buffer_index = 0;
				g_UsbMS.rw_cmd.rw_error_status = KAL_FALSE;

				USB_Ms_Handle_Read(LUN, CBW);
			}
		}
		else
		{
			USB_Ms_Read_Fail_Handler(LUN, CBW);
		}
	}
}


static void USB_Ms_Handle_Read(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	static kal_bool 	read_status;
	static kal_uint32	readlen = 0;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	

	if(g_UsbMS.rw_cmd.rwindex == 0)		/* the first time to read */
	{
		if ((g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex) <= USBMS_TX_MAX_SECTOR)
			readlen = g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex;
		else
			readlen = USBMS_TX_MAX_SECTOR;
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
#else
		read_status = USB_Ms_Read(LUN, g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], 
					(g_UsbMS.rw_cmd.LBA + g_UsbMS.rw_cmd.msdc_rwindex), readlen);

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
#endif
	}/*(g_UsbMS.rw_cmd.rwindex == 0)*/

	if (read_status == KAL_TRUE)
	{
		g_UsbMS.rw_cmd.msdc_rwindex += readlen;
		USB_Ms_BuildTx((void *)g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], (512 * readlen));
		g_UsbMS.rw_cmd.rwindex += readlen;

		if (g_UsbMS.rw_cmd.rwindex == g_UsbMS.rw_cmd.BlkLen)
		{
			g_UsbMS.nState = USBMS_ACK;
			return;
		}
	}
	else
	{
		USB_Ms_Read_Fail_Handler(LUN, CBW);
		return;
	}

	if ((g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex) <= USBMS_TX_MAX_SECTOR)
		readlen = g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex;
	else
		readlen = USBMS_TX_MAX_SECTOR;

	g_UsbMS.rw_cmd.rw_buffer_index ^= 1;

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
#else
	read_status = USB_Ms_Read(LUN, g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], 
				(g_UsbMS.rw_cmd.LBA + g_UsbMS.rw_cmd.msdc_rwindex), readlen);
#endif
}

/* handle read error condition */
static void USB_Ms_Read_Fail_Handler(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_bool bEPEmpty;
	kal_uint8 count = 0;
		
	/* make sure previous packets are already sent out
	   maybe last DMA data has triggered DMA done but data are still in FIFO*/
	bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_UsbMS.txpipe->byEP);
	/* If cable plug out at this time, add timeout to avoid looping here */
	while((bEPEmpty == KAL_FALSE)&&(count<100))
	{
		count++;	
		kal_sleep_task(1);	
		bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_UsbMS.txpipe->byEP);
	}
	
	/* send out a NULL packet */
	USB_EPFIFOWrite (g_UsbMS.txpipe->byEP, 0, NULL);
	USB_EP_Bulk_Tx_Ready(g_UsbMS.txpipe->byEP);
	
	/* make sure previous NULL pkt has been sent out
	   avoid next DMA data in FIFO sent out instead of previos NULL pkt.*/
	/* To avoid "IN token received after next DMA(below part) has moved data into FIFO"
	If this happens, MTK device will send CSW of 13 bytes out to PC, 
	and it will cause PC to wait for next data(about 10 seconds) and reset USB after that.
	Disk will show on PC until this condition disappear*/
	bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_UsbMS.txpipe->byEP);
	/* If cable plug out at this time, add timeout to avoid looping here */
	count = 0;
	while((bEPEmpty == KAL_FALSE)&&(count<100))
	{
		count++;	
		kal_sleep_task(1);	
		bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_UsbMS.txpipe->byEP);
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
#else
	USB_Ms_State_Checkmedia_Exist(LUN);
#endif	
	
	g_UsbMS.CSWDataResidue = (g_UsbMS.rw_cmd.BlkLen-g_UsbMS.rw_cmd.msdc_rwindex)*512;
	g_UsbMS.CSWStatusError = 0x01;
	USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_Read_ERROR, g_UsbMS.CSWDataResidue);
	USB_Ms_Generate_Csw(&g_UsbMS.CSW, CBW);
	g_UsbMS.nState = USBMS_GETNEXTCMD;
	USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
}

/* handle CBW USBMS_WRITE command */
static void USB_Ms_Cmd_Write(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint8   *CBWCB = CBW->CBWCB;
	kal_uint8   msdc_status;

	msdc_status = USB_Ms_Checkmedia_Exist(LUN);

	USB_Ms_MemInverse(&CBWCB[2], &g_UsbMS.rw_cmd.LBA, 4);
//	USB_Ms_MemInverse(&CBWCB[7], &g_UsbMS.rw_cmd.BlkLen, 2);

	if(g_UsbMS.nState == USBMS_TX)
	{
		USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_TX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		return;
	}

	if(CBW->dCBWDataTransferLength == 0)
	{
		g_UsbMS.CSWStatusError = 0x02;
		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWDataResidue = 0;
		USB_Ms_Generate_Csw(&g_UsbMS.CSW, CBW);
		USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
	}
	else if(g_UsbMS.rw_cmd.BlkLen == 0)
	{
		/* Device expects no data transfers */
		USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
	}
	else
	{
		if((g_UsbMS.rw_cmd.BlkLen*512) != CBW->dCBWDataTransferLength)
		{
			USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_RX_EP_TYPE, KAL_TRUE, USB_CTRL_STALL_ENTRY_3);
			g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		}
		else
		{
			g_UsbMS.rw_cmd.rwindex = 0;
			g_UsbMS.rw_cmd.msdc_rwindex = 0;
			g_UsbMS.rw_cmd.rw_buffer_index = 0;

			if (msdc_status == USB_STORAGE_DEV_STATUS_OK)
				g_UsbMS.rw_cmd.rw_error_status = KAL_FALSE;
			else
				g_UsbMS.rw_cmd.rw_error_status = KAL_TRUE;

//			USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_WRITE, g_UsbMS.rw_cmd.BlkLen);

			USB_Ms_Handle_Write(LUN, CBW, 0);
		}
	}
}
			
static void USB_Ms_Handle_Write(kal_uint8 LUN, UsbMs_CBW *CBW, kal_uint8 sector_num)
{
	kal_uint32 writelen;
	kal_bool write_status;
	kal_bool write_data = KAL_FALSE;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	/* determine if it has data to write, if yes and msdc ok then write it*/
	if((g_UsbMS.rw_cmd.rwindex != 0) && (g_UsbMS.rw_cmd.rw_error_status == KAL_FALSE))
	{
		write_data = KAL_TRUE;
	}

	/* last data*/
	if (g_UsbMS.rw_cmd.rwindex == g_UsbMS.rw_cmd.BlkLen)
	{
		/* write the last one data*/
		g_UsbMS.rw_cmd.rw_buffer_index ^= 1; 
		if(write_data == KAL_TRUE)
		{
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
			write_status= USB_Ms_Write(g_UsbMS.current_LUN, g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], 
							(g_UsbMS.rw_cmd.LBA + g_UsbMS.rw_cmd.msdc_rwindex), sector_num);
			
			if(write_status == KAL_TRUE)
			{
#ifdef __P_PROPRIETARY_COPYRIGHT__	
/* under construction !*/
#endif
				g_UsbMS.rw_cmd.msdc_rwindex+=sector_num;
			}
			else
			{
				g_UsbMS.rw_cmd.rw_error_status = KAL_TRUE;
				USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_Write_ERROR, g_UsbMS.rw_cmd.rwindex);
				USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_Write_ERROR2, g_UsbMS.rw_cmd.msdc_rwindex);
				USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_Write_ERROR3,  g_UsbMS.rw_cmd.BlkLen);
			}
		}	
		
		/* RX done */
		g_UsbMS.nState = USBMS_GETNEXTCMD;

		/*Send CSW*/
		g_UsbMS.CSWDataResidue = (g_UsbMS.rw_cmd.BlkLen-g_UsbMS.rw_cmd.msdc_rwindex)*512;
		USB_Ms_Checkmedia_Exist(g_UsbMS.current_LUN);
		if(g_UsbMS.CSWDataResidue != 0)
		{
			g_UsbMS.CSWStatusError = 0x01;
			USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_Write_ERROR_Residue,  g_UsbMS.CSWDataResidue);
		}
		g_UsbMS.rw_cmd.rw_error_status = KAL_FALSE;
		USB_Ms_Generate_Csw(&g_UsbMS.CSW, CBW);
		USB_Ms_BuildTx(&g_UsbMS.CSW, 13);
	}
	else		/* more data to receive, or ready to receive the first one data packet*/
	{
		/* determine the length to be received*/
		if ((g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex) <=USBMS_RX_MAX_SECTOR)
		{
			writelen = g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex;
		}
		else
		{
			writelen = USBMS_RX_MAX_SECTOR;
		}

		USB_Ms_BuildRx((void *)g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], (512 * writelen));
		g_UsbMS.rw_cmd.rwindex += writelen;

		/* write flash while receive another packet*/
		g_UsbMS.rw_cmd.rw_buffer_index ^= 1;  /*  toggle buffer index */
		if(write_data == KAL_TRUE)
		{
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

			write_status= USB_Ms_Write(g_UsbMS.current_LUN, g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], 
								(g_UsbMS.rw_cmd.LBA + g_UsbMS.rw_cmd.msdc_rwindex), sector_num);

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

			if(write_status == KAL_TRUE)
			{
#ifdef __P_PROPRIETARY_COPYRIGHT__	
/* under construction !*/
#endif
				g_UsbMS.rw_cmd.msdc_rwindex+=sector_num;
			}
			else
			{
				g_UsbMS.rw_cmd.rw_error_status = KAL_TRUE;
				USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_Write_ERROR, g_UsbMS.rw_cmd.rwindex);
				USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_Write_ERROR2, g_UsbMS.rw_cmd.msdc_rwindex);
				USB_Ms_Dbg_Trace(USB_DBG_USBMS_CMD_Write_ERROR3,  g_UsbMS.rw_cmd.BlkLen);
			}	
		}
	}
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
#endif /* __P_PROPRIETARY_COPYRIGHT__ */


