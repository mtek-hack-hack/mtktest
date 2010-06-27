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
 *   usbvideo_state.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb video class state machine
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "drv_comm.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"  
#include "app_buff_alloc.h"
#include "drvsignals.h"
#include "gpt_sw.h"

#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usb_resource.h"

#include "usbvideo_drv.h"
#include "usbvideo_state.h"
#include "usb_custom.h"
#include "usbvideo_if.h"
#include "usbvideo_custom.h"

/*This will be removed when change back to media task*/
#include "custom_config.h"


#ifdef WEBCAM_SUPPORT

/*****************************************************
		task message handler 
******************************************************/

/* Handler for attribute confirm from media task */
static void USBVideo_Attr_Cnf_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	usbvideo_attr_msg_struct *attr_req_cnf;
	kal_bool  bSendMsg;
	kal_bool  bSendIntr;
	kal_uint8 count = 0;
	kal_uint8 info = 0;
	kal_uint32   attr_temp;

	/* send attr done to host */
	bSendMsg = KAL_FALSE;
	attr_req_cnf=(usbvideo_attr_msg_struct *)p_recv_ilm->local_para_ptr;


	if(g_USBVideo.vc_white_balance_error_setting == KAL_TRUE)
	{
		g_USBVideo.vc_white_balance_error_setting = KAL_FALSE;
		return;
	}

	if((attr_req_cnf->attr_value.type&0x80) == 0)
	{
		/* camera terminal attribute */
		if(g_USBVideo.vc_ct_subtype_cnf[attr_req_cnf->attr_value.type - 1] != 0)
		{
			g_USBVideo.vc_ct_subtype_cnf[attr_req_cnf->attr_value.type - 1] &= (~(1<<attr_req_cnf->attr_value.subtype));
		}
		if(g_USBVideo.vc_ct_subtype_cnf[attr_req_cnf->attr_value.type - 1] == 0)
		{
			gUsbDevice.ep0_state = USB_EP0_RX_STATUS;
	 	  	USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);
			bSendMsg = KAL_TRUE;
		}
	}
	else
	{
		/* processing unit attribute */
		if(g_USBVideo.vc_pu_subtype_cnf[(attr_req_cnf->attr_value.type&(~0x80)) - 1]!=0)
		{
			g_USBVideo.vc_pu_subtype_cnf[(attr_req_cnf->attr_value.type&(~0x80)) - 1] &= (~(1<<attr_req_cnf->attr_value.subtype));
		}
		if(g_USBVideo.vc_pu_subtype_cnf[(attr_req_cnf->attr_value.type&(~0x80)) - 1]==0)
		{
			gUsbDevice.ep0_state = USB_EP0_RX_STATUS;
	 	  	USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);

			/* for USB UVC compliance test tool !! */
			bSendMsg = KAL_FALSE;

			if(g_USBVideo.vc_set_white_balance_temp_intr == KAL_TRUE)
			{
				bSendMsg = KAL_TRUE;
			}
		}
	}

	if(bSendMsg == KAL_TRUE)
	{
		/* send set attribute confirm to PC when "all" subtypes confirm are received */
		g_USBVideo.vc_status_pkt.bStuausType = USBVIDEO_STATUS_TYPE_VC;

		if((attr_req_cnf->attr_value.type&0x80) == 0)
		{
			g_USBVideo.vc_status_pkt.bOriginator = USBVIDEO_CT_ID;
		}
		else
		{
			g_USBVideo.vc_status_pkt.bOriginator = USBVIDEO_PU_ID;
		}

		g_USBVideo.vc_status_pkt.bEvent = 0x00;

		if(g_USBVideo.vc_set_white_balance_temp_intr == KAL_TRUE)
		{
			g_USBVideo.vc_status_pkt.bSelector = (USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP&(0x7f));
			g_USBVideo.vc_status_pkt.bAttribute = USBVIDEO_STATUS_VC_ATTRIBUTRE_CONTROL_INFO_CHANGE;

			if((g_USBVideo.vc_pu_support&(1<<(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP&(0x7f)))) != 0)
				info |= 1<<USBVIDEO_ATTR_INFO_SUPPORT_GET;

			if((g_USBVideo.vc_pu_set&(1<<(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP&(0x7f)))) != 0)
				info |= 1<<USBVIDEO_ATTR_INFO_SUPPORT_SET;

			attr_temp = USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO&(0x7f);
			if((g_USBVideo.vc_pu_support&(1<<attr_temp)) != 0)
			{
				info |= 1<<USBVIDEO_ATTR_INFO_AUTO_UPDATE;

				if(USBVideo_Get_Attr_WBalanceTmp_Auto_Cur_Value() == KAL_TRUE)
				{
					info |= 1<<USBVIDEO_ATTR_INFO_DISBALE;
				}
			}
			else if((g_USBVideo.vc_pu_set&(1<<attr_temp)) != 0)
			{
//				info |= (1<<USBVIDEO_ATTR_INFO_ASYNC_CTRL);
			}
			g_USBVideo.vc_status_pkt.bValue = info;
		}
		else
		{
			g_USBVideo.vc_status_pkt.bSelector = (attr_req_cnf->attr_value.type&(~0x80));
			g_USBVideo.vc_status_pkt.bAttribute = USBVIDEO_STATUS_VC_ATTRIBUTRE_CONTROL_VALUE_CHANGE;
			g_USBVideo.vc_status_pkt.bValue = attr_req_cnf->attr_value.value;
		}


		/* add some delay to confirm that interrupt must be sent after status packet */
		kal_sleep_task(1);

		bSendIntr = USBVideo_Send_Intr(&g_USBVideo.vc_status_pkt, sizeof(USBVideo_VC_Status_Pkt_Struct));

		/* If cable is plugged out at this time, add timeout to avoid looping here */
		while((bSendIntr == KAL_FALSE)&&(count<100))
		{
			count++;	
			kal_sleep_task(1);
			bSendIntr = USBVideo_Send_Intr(&g_USBVideo.vc_status_pkt,sizeof(USBVideo_VC_Status_Pkt_Struct));
		}
	}	
}



/* Handler for enumeration done(size commit) from USB HISR */
static void USBVideo_Enum_Done_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	if(g_USBVideo.state == USBVIDEO_STATE_SEND)
	{
		/* This may happen when USB queue already have media start_req msg,
		   but USB_HISR receive commit again at this time, so it send enum done again
		   because state is still in stop state */
		   /* Notify media task to change video size */	
		g_USBVideo.state = USBVIDEO_STATE_DROP;
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_CHANGE_VIDEO_IND, g_USBVideo.commit_video_index, g_USBVideo.video_compression_index);	   	
	}
	else if(g_USBVideo.state != USBVIDEO_STATE_STOP)
	{
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);
	}

	/* enum done should be received before cable plug out msg
		if plug out first, then no enum done message, but plug out msg should already sent confirm fail to media task */
	if(device_type!=USB_VIDEO)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, (kal_uint32)device_type, 0);
	
	/* check state */
	if(g_USBVideo.video_start_state == USBVIDEO_START_NONE)
		g_USBVideo.video_start_state = USBVIDEO_START_RECV_COMMIT;
	else if(g_USBVideo.video_start_state == USBVIDEO_START_RECV_COMMIT)
	{
		/* This may happen because USB HISR send this enum done msg twice because PC send twice commit msg*/
		//kal_prompt_trace(MOD_USB, "video_start_state USBVIDEO_START_RECV_COMMIT\n");
	}	
	else if(g_USBVideo.video_start_state == USBVIDEO_START_RECV_MED_REQ)
	{
		/* Send confirm message to media task if host has commit the video*/
		g_USBVideo.video_start_state = USBVIDEO_START_DONE;
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_START_SUCCESS_CNF, g_USBVideo.commit_video_index, g_USBVideo.video_compression_index);
		g_USBVideo.state = USBVIDEO_STATE_SEND;
	}
	else
	{
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_start_state, 0, 0);
	}
}

/* Handler for start video request from media task */
static void USBVideo_Start_Video_Req_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	usbvideo_video_req_struct *video_req;
	const USBVideo_Video_Size_Info *p_video_size_param;
	const USBVideo_Still_Size_Info *p_still_size_param;
	kal_uint8 video_size_num;
	kal_uint8 still_size_num;
	kal_uint32 index;

	if(g_USBVideo.state != USBVIDEO_STATE_STOP)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);

	if(device_type!=USB_VIDEO)
	{
		/* cable may have been plugged out, send fail confirm to media task*/
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_START_FAIL_CNF, 0, 0);
		return;
	}
	
	video_req=(usbvideo_video_req_struct *)p_recv_ilm->local_para_ptr;
	g_USBVideo.video_control.video_buffer_read_index = 0;
	g_USBVideo.video_control.video_buffer_write_index = 0;
	g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
	g_USBVideo.video_control.send_video_msg = KAL_TRUE;
	g_USBVideo.video_control.sent_video_size = 0;
	g_USBVideo.video_control.video_frame_id = 0;
	/* 4-bytes align, the jpeg need 4-bytes alignment buffer */
	g_USBVideo.video_control.video_buffer_addr[0] = (kal_uint8*)(((kal_uint32)video_req->buffer_addr + (4-1))&(~(4-1)));	
	g_USBVideo.video_control.video_buffer_size = (video_req->buffer_size - ((4-1)*USBVIDEO_VIDEO_BUFFER_NUMBER))/USBVIDEO_VIDEO_BUFFER_NUMBER;
	/* 4-bytes align, the jpeg need 4-bytes alignment buffer */
	g_USBVideo.video_control.video_buffer_size = (g_USBVideo.video_control.video_buffer_size + (4-1))& (~(4-1));	
	p_video_size_param = g_USBVideo.camera_param->usbvideo_get_video_size_info(&video_size_num);
	p_still_size_param = g_USBVideo.camera_param->usbvideo_get_still_size_info(&still_size_num);

	/* check the video buffer size larger than all custom camera video buffer, and still size also */
	for(index = 0; index < video_size_num; index++)
	{
		if(g_USBVideo.video_control.video_buffer_size < (p_video_size_param[index].max_frame_size+USBVIDEO_PAYLOAD_HEADER_LENGTH))
		{
			EXT_ASSERT(0, g_USBVideo.video_control.video_buffer_size, index, p_video_size_param[index].max_frame_size);
		}			
	}

	for(index = 0; index < still_size_num; index++)
	{
		if(video_req->buffer_size < (p_still_size_param[index].max_frame_size+USBVIDEO_PAYLOAD_HEADER_LENGTH))
		{
			EXT_ASSERT(0, video_req->buffer_size, index, p_still_size_param[index].max_frame_size);
		}			
	}

	/* calculate each buffer start address */
	for(index = 1; index < USBVIDEO_VIDEO_BUFFER_NUMBER; index++)
	{
		g_USBVideo.video_control.video_buffer_addr[index] = g_USBVideo.video_control.video_buffer_addr[index - 1] + g_USBVideo.video_control.video_buffer_size;
	}

	/* check state */
	//if(g_USBVideo.state != USBVIDEO_STATE_STOP)
		//EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);
	
	if(g_USBVideo.video_start_state == USBVIDEO_START_NONE)
		g_USBVideo.video_start_state = USBVIDEO_START_RECV_MED_REQ;
	else if(g_USBVideo.video_start_state == USBVIDEO_START_RECV_COMMIT)
	{
		/* Send confirm message to media task if host has commit the video*/
		g_USBVideo.video_start_state = USBVIDEO_START_DONE;
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_START_SUCCESS_CNF, g_USBVideo.commit_video_index, g_USBVideo.video_compression_index);
		g_USBVideo.state = USBVIDEO_STATE_SEND;
	}
	else
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_start_state, 0, 0);
}

/* Handler for change video size request from USB HISR */
static void USBVideo_Change_Video_Size_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_uint32 savedMask;

	if((g_USBVideo.state==USBVIDEO_STATE_PRE_PAUSE) || (g_USBVideo.state==USBVIDEO_STATE_PAUSE)
		||(g_USBVideo.state==USBVIDEO_STATE_STOP) || (g_USBVideo.state==USBVIDEO_STATE_STILL))
	{
		/* do nothing, new size will be get each time send this JPEG*/
		return;
	}
	
	/* clear buffer and wait DMA done */
	savedMask = SaveAndSetIRQMask();
	if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE) == KAL_TRUE)
	{
		if(g_USBVideo.video_control.dma_type==USBVIDEO_DMA_VIDEO)
		{
			/* Not that for incall dma case, some resume cnf has been sent to media task already
			   So the handler is the same as video */
		
			/* DMA is running, after DMA done read pointer will increment */
			if(g_USBVideo.video_control.video_buffer_read_index==(USBVIDEO_VIDEO_BUFFER_NUMBER-1))
				g_USBVideo.video_control.video_buffer_write_index = 0;
			else
				g_USBVideo.video_control.video_buffer_write_index = g_USBVideo.video_control.video_buffer_read_index+1;
			g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		}
		else if((g_USBVideo.video_control.dma_type==USBVIDEO_DMA_STILL) 
			||(g_USBVideo.video_control.dma_type==USBVIDEO_DMA_INCALL_JPEG))
		{
			g_USBVideo.video_control.video_buffer_write_index = 0;
			g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		}
		else
		{
			EXT_ASSERT(0, g_USBVideo.video_control.dma_type, g_USBVideo.state, 0);
		}
	}
	else
	{
		/* clear the buffer */
		g_USBVideo.video_control.video_buffer_read_index = g_USBVideo.video_control.video_buffer_write_index;
		g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		g_USBVideo.video_control.sent_video_size = 0;
		/* buffer is empty, send msg for next complete buffer */
		g_USBVideo.video_control.send_video_msg = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);
	
	/* Notify media task to change video size */	
	g_USBVideo.state = USBVIDEO_STATE_DROP;
	USBVideo_Send_Msg(USBVIDEO_MSG_MED_CHANGE_VIDEO_IND, g_USBVideo.commit_video_index, g_USBVideo.video_compression_index);	
	
}

/* Handler for complete video buffer filling from camera HISR */
static void USBVideo_Video_Complete_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_uint8 commit_still_index = g_USBVideo.commit_still_index;
	
	if((g_USBVideo.state==USBVIDEO_STATE_PRE_PAUSE) || (g_USBVideo.state==USBVIDEO_STATE_PAUSE))
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state,g_USBVideo.video_control.video_buffer_read_index, 
					g_USBVideo.video_control.video_buffer_write_index);

	if((g_USBVideo.state==USBVIDEO_STATE_STOP) 
		||((g_USBVideo.state==USBVIDEO_STATE_STILL)&&(commit_still_index!=0)))
		return;

	if(g_USBVideo.state==USBVIDEO_STATE_STILL)
	{
	#ifndef  __PRODUCTION_RELEASE__
		if(commit_still_index==0)
			ASSERT(0);
	#endif	
		g_USBVideo.state = USBVIDEO_STATE_SEND;
	}

	g_USBVideo.video_control.dma_type = USBVIDEO_DMA_VIDEO;
	USBVideo_Send_Video();
}

/* Handler for video DMA done from DMA HISR */
static void USBVideo_Video_DMA_Done_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_bool	bBufferEmpty = KAL_FALSE;
	kal_uint32 savedMask;
	usbvideo_default_JPEG_Info*p_default_jpeg;
	kal_uint32 total_size;
	kal_bool bEPEmpty;
	kal_uint32 count;
	kal_uint8 commit_still_index = g_USBVideo.commit_still_index;
	// for debug 
	static kal_uint8 dmadone_video_buff_write_index;
	static kal_uint8 dmadone_video_buff_read_index;
	static kal_bool dmadone_video_buff_full_flag;

	if(g_USBVideo.state==USBVIDEO_STATE_PAUSE)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);

	if(g_USBVideo.state==USBVIDEO_STATE_STOP)
		return;

	if(g_USBVideo.video_control.dma_done_type == USBVIDEO_DMA_DONE_COMPLETE)
	{
		/* send NULL packet only when dma done type is complete, not stop */
		total_size = g_USBVideo.video_control.video_size[g_USBVideo.video_control.video_buffer_read_index]; 
		count = total_size/(USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH);

		if(total_size%(USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH)!=0)
			count++;

		if(((total_size+count*USBVIDEO_PAYLOAD_HEADER_LENGTH)%USB_EP_BULK_MAXP) == 0)
		{
			/* multiple of 64 bytes */
	
			/* make sure previous packets are already sent out
			   maybe last DMA data has triggered DMA done but data are still in FIFO*/
			bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			/* If cable plug out at this time, add timeout to avoid looping here */
			while((bEPEmpty == KAL_FALSE)&&(count<100))
			{
				count++;	
				kal_sleep_task(1);	
				bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			}
	
			/* send out a NULL packet */
			USB_EPFIFOWrite(g_USBVideo.txpipe->byEP, 0, NULL);
			USB_EP_Bulk_Tx_Ready(g_USBVideo.txpipe->byEP);
		
			/* mak sure previous NULL pkt has been sent out
			   avoid next DMA data in FIFO sent out instead of previos NULL pkt.*/
		
			bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			/* If cable plug out at this time, add timeout to avoid looping here */
			count = 0;
			while((bEPEmpty == KAL_FALSE)&&(count<100))
			{
				count++;	
				kal_sleep_task(1);	
				bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			}
		}
	}	
	
	if(g_USBVideo.state == USBVIDEO_STATE_PRE_PAUSE)
	{
		/* stop pre-pause timer */
		GPTI_StopItem(g_USBVideo.video_control.timer_handle);
		g_USBVideo.state = USBVIDEO_STATE_PAUSE;	
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_PAUSE_CNF, (kal_uint32)KAL_TRUE, 0);
		//p_default_jpeg = g_USBVideo.mmi_param->usbvideo_get_incall_jpeg_info(&incall_size_num);
		p_default_jpeg = g_USBVideo.default_jpeg_info;
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.still_count = 0;
		g_USBVideo.video_control.sent_video_size = 0;
		g_USBVideo.video_control.incall_jpeg_addr = p_default_jpeg[g_USBVideo.commit_video_index - 1].start_addr;
		g_USBVideo.video_control.incall_jpeg_size = p_default_jpeg[g_USBVideo.commit_video_index - 1].size;
		RestoreIRQMask(savedMask);
		g_USBVideo.video_control.dma_type = USBVIDEO_DMA_INCALL_JPEG;
		USBVideo_Send_Incall_JPEG();
	}
	else if((g_USBVideo.state==USBVIDEO_STATE_STILL)&&(commit_still_index!=0))
	{
		/* Send still capture request to media task*/
		savedMask = SaveAndSetIRQMask();	
		g_USBVideo.video_control.sent_video_size = 0;
		g_USBVideo.video_control.video_buffer_read_index = 0;
		g_USBVideo.video_control.video_buffer_write_index = 0;
		g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		g_USBVideo.video_control.send_video_msg = KAL_TRUE;
		RestoreIRQMask(savedMask);
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_STILL_CAPTURE_IND, commit_still_index, g_USBVideo.commit_still_compression_index);	
	}
	else
	{
		if(g_USBVideo.state==USBVIDEO_STATE_STILL)   /*  commit_still_index == 0  */
		{
		#ifndef  __PRODUCTION_RELEASE__
			if(commit_still_index==0)
				ASSERT(0);
		#endif	
			g_USBVideo.state = USBVIDEO_STATE_SEND;
		}
		
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.sent_video_size = 0;
		g_USBVideo.video_control.video_buffer_read_index++;
		if(g_USBVideo.video_control.video_buffer_read_index==USBVIDEO_VIDEO_BUFFER_NUMBER)
			g_USBVideo.video_control.video_buffer_read_index = 0;
		if(g_USBVideo.video_control.video_buffer_full==KAL_TRUE)
		{
			if(g_USBVideo.video_control.video_buffer_read_index==g_USBVideo.video_control.video_buffer_write_index)
				EXT_ASSERT(0, g_USBVideo.video_control.video_buffer_read_index,
							g_USBVideo.video_control.video_buffer_write_index, 0);	
			g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		}

		if(g_USBVideo.video_control.video_buffer_read_index==g_USBVideo.video_control.video_buffer_write_index)
		{
			/* buffer empty */
			bBufferEmpty = KAL_TRUE;
			g_USBVideo.video_control.send_video_msg = KAL_TRUE;
		}
		
		dmadone_video_buff_write_index = g_USBVideo.video_control.video_buffer_write_index;
		dmadone_video_buff_read_index = g_USBVideo.video_control.video_buffer_read_index;
		dmadone_video_buff_full_flag = g_USBVideo.video_control.video_buffer_full;
	
		RestoreIRQMask(savedMask);
		
		kal_prompt_trace(MOD_USB, "dma done v buff r %d, w%d, f %d\n", dmadone_video_buff_read_index, 
					dmadone_video_buff_write_index, dmadone_video_buff_full_flag);
					
		if(bBufferEmpty==KAL_FALSE)
		{
			g_USBVideo.video_control.dma_type = USBVIDEO_DMA_VIDEO;
			USBVideo_Send_Video();
		}	
	}	
}

/* Handler for still DMA done from DMA HISR */
static void USBVideo_Still_DMA_Done_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_uint32 savedMask;
	usbvideo_default_JPEG_Info*p_default_jpeg;
	kal_uint32 total_size;
	kal_bool bEPEmpty;
	kal_uint32 count;
	kal_uint8 commit_still_index = g_USBVideo.commit_still_index;

	if(g_USBVideo.state==USBVIDEO_STATE_PAUSE)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);

	if(g_USBVideo.state==USBVIDEO_STATE_STOP)
		return;	

	if(g_USBVideo.video_control.dma_done_type == USBVIDEO_DMA_DONE_COMPLETE)
	{
		/* send NULL packet only when dma done type is complete */
		total_size = g_USBVideo.video_control.still_size;
		count = total_size/(USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH);
		if(total_size%(USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH)!=0)
			count++;
		if(((total_size+count*USBVIDEO_PAYLOAD_HEADER_LENGTH)%USB_EP_BULK_MAXP) == 0)
		{
			/* multiple of 64 bytes */
			
			/* make sure previous packets are already sent out
			   maybe last DMA data has triggered DMA done but data are still in FIFO*/
			bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			/* If cable plug out at this time, add timeout to avoid looping here */
			while((bEPEmpty == KAL_FALSE)&&(count<100))
			{
				count++;	
				kal_sleep_task(1);	
				bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			}
	
			/* send out a NULL packet */
			USB_EPFIFOWrite(g_USBVideo.txpipe->byEP, 0, NULL);
			USB_EP_Bulk_Tx_Ready(g_USBVideo.txpipe->byEP);
		
			/* mak sure previous NULL pkt has been sent out
			   avoid next DMA data in FIFO sent out instead of previos NULL pkt.*/
	
			bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			/* If cable plug out at this time, add timeout to avoid looping here */
			count = 0;
			while((bEPEmpty == KAL_FALSE)&&(count<100))
			{
				count++;	
				kal_sleep_task(1);	
				bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			}
		}
	}		

	if(g_USBVideo.state == USBVIDEO_STATE_PRE_PAUSE)
	{
		/* stop pre-pause timer */
		GPTI_StopItem(g_USBVideo.video_control.timer_handle);
		g_USBVideo.state = USBVIDEO_STATE_PAUSE;	
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_PAUSE_CNF, (kal_uint32)KAL_TRUE, 0);
		//p_incall_param = g_USBVideo.mmi_param->usbvideo_get_incall_jpeg_info(&incall_size_num);
		p_default_jpeg = g_USBVideo.default_jpeg_info;
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.still_count = 0;
		g_USBVideo.video_control.sent_video_size = 0;
		g_USBVideo.video_control.send_video_msg = KAL_TRUE;
		g_USBVideo.video_control.incall_jpeg_addr = p_default_jpeg[g_USBVideo.commit_video_index - 1].start_addr;
		g_USBVideo.video_control.incall_jpeg_size = p_default_jpeg[g_USBVideo.commit_video_index - 1].size;
		RestoreIRQMask(savedMask);
		g_USBVideo.video_control.dma_type = USBVIDEO_DMA_INCALL_JPEG;
		USBVideo_Send_Incall_JPEG();
	}
	else if((g_USBVideo.state == USBVIDEO_STATE_SEND) || (g_USBVideo.state == USBVIDEO_STATE_DROP))
	{
		/* already enter send state when still partial done */
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.sent_video_size = 0;
		g_USBVideo.video_control.send_video_msg = KAL_TRUE;
		/* update read pointer so that video can start to capture in this buffer */
		g_USBVideo.video_control.video_buffer_read_index = 0;
		g_USBVideo.video_control.video_buffer_full = KAL_FALSE;	
		RestoreIRQMask(savedMask);
	}
	else if(g_USBVideo.state == USBVIDEO_STATE_STILL)
	{
		if((g_USBVideo.video_control.still_count>0) && (commit_still_index!=0))
		{
			/* send still image again */
			savedMask = SaveAndSetIRQMask();
			g_USBVideo.video_control.sent_video_size = 0;
			g_USBVideo.video_control.video_buffer_read_index = 0;
			g_USBVideo.video_control.video_buffer_write_index = 0;
			g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
			g_USBVideo.video_control.send_video_msg = KAL_TRUE;
			RestoreIRQMask(savedMask);
			g_USBVideo.video_control.still_count--;
			USBVideo_Send_Msg(USBVIDEO_MSG_MED_STILL_CAPTURE_IND, commit_still_index, g_USBVideo.commit_still_compression_index);
		}
		else
		{
		#ifndef  __PRODUCTION_RELEASE__
			if((g_USBVideo.video_control.still_count>0) && (commit_still_index==0))
			{
				ASSERT(0);
			}
		#endif	
			g_USBVideo.video_control.still_count = 0;
			
			savedMask = SaveAndSetIRQMask();
			g_USBVideo.video_control.sent_video_size = 0;
			g_USBVideo.video_control.send_video_msg = KAL_TRUE;
			RestoreIRQMask(savedMask);
			/* there are two conditions that STILL_DMA_DONE without STILL_DMA_PARTIAL
			     1 : Still image is stopped by USB HISR receiving clear EP Halt feature
			     2:  Still image size is less than one video buffer size */
			g_USBVideo.state = USBVIDEO_STATE_SEND;
			USBVideo_Send_Msg(USBVIDEO_MSG_MED_START_IND, g_USBVideo.commit_video_index, g_USBVideo.video_compression_index);
		}
	}
}

/* Handler for still DMA partial done(complete of some video buffer size) from DMA HISR */
static void USBVideo_Still_DMA_Partial_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	usbvideo_still_dma_struct *still_dma;
	kal_uint32 savedMask;

	if(g_USBVideo.state==USBVIDEO_STATE_PAUSE)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);
	
	if((g_USBVideo.state == USBVIDEO_STATE_PRE_PAUSE) || (g_USBVideo.state == USBVIDEO_STATE_STOP))
		return;

	if(g_USBVideo.video_control.still_count==0)
	{
		still_dma = (usbvideo_still_dma_struct *)p_recv_ilm->local_para_ptr;
		savedMask = SaveAndSetIRQMask();
		/* update read pointer so that video can start to capture in this buffer */
		g_USBVideo.video_control.video_buffer_read_index = still_dma->index;/* update read  pointer 1, so only can be written pointer 0*/
		g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		RestoreIRQMask(savedMask);
		if(still_dma->index==1)
		{
			g_USBVideo.state = USBVIDEO_STATE_SEND;
			USBVideo_Send_Msg(USBVIDEO_MSG_MED_START_IND, g_USBVideo.commit_video_index, g_USBVideo.video_compression_index);
		}	
	}
}

/* Handler for still capture request(PC request) from USB HISR */
static void USBVideo_Still_Capture_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_bool  bSendMsg = KAL_FALSE;
	kal_uint32 savedMask;
	kal_uint8 commit_still_index = g_USBVideo.commit_still_index;

#ifndef  __PRODUCTION_RELEASE__
	if(commit_still_index==0)
	{
		ASSERT(0);
	}
#endif	

	/* Do not assert because still capture msg is triggered by USB HISR, but pause request is triggered by media task */
	if((g_USBVideo.state==USBVIDEO_STATE_PRE_PAUSE) || (g_USBVideo.state==USBVIDEO_STATE_PAUSE)
		|| (g_USBVideo.state==USBVIDEO_STATE_STOP) || (commit_still_index==0))
		return;
			
	if(g_USBVideo.state != USBVIDEO_STATE_STILL) /* SEND or DROP */
	{
		g_USBVideo.state = USBVIDEO_STATE_STILL;
		g_USBVideo.video_control.still_count = 0;
		savedMask = SaveAndSetIRQMask();
		if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE) == KAL_FALSE)
		{	
			g_USBVideo.video_control.video_buffer_read_index = 0;
			g_USBVideo.video_control.video_buffer_write_index = 0;
			g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
			g_USBVideo.video_control.send_video_msg = KAL_TRUE;
			bSendMsg = KAL_TRUE;	
		}
		/* else wait DMA_DONE */
		RestoreIRQMask(savedMask);
		if(bSendMsg == KAL_TRUE)
		{
			USBVideo_Send_Msg(USBVIDEO_MSG_MED_STILL_CAPTURE_IND, commit_still_index, g_USBVideo.commit_still_compression_index);
		}
		else
		{
			/* In the mechanism that buffer can be released as video when the first part of still image is transmitted,
			     it may happens that: STILL_DMA_PARTIAL has been received so state change to SEND,
			     before the whole still image transmitted, this still capture request is received again */
			 if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_STILL)
			{
				g_USBVideo.video_control.still_count++;
			}
		}
	}
	else
	{
		g_USBVideo.video_control.still_count++;
	}
}

/* Handler for complete still buffer filling from camera HISR */
static void USBVideo_Still_Complete_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_uint32 savedMask;
	
	if(g_USBVideo.state==USBVIDEO_STATE_STOP)
		return;

	if(g_USBVideo.state!=USBVIDEO_STATE_STILL)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state,g_USBVideo.video_control.video_buffer_read_index, 
					g_USBVideo.video_control.video_buffer_write_index);

	savedMask = SaveAndSetIRQMask();
	/* In case video complete msg is sent after still DMA partial done but before still DMA done*/
	g_USBVideo.video_control.send_video_msg = KAL_FALSE;	
	RestoreIRQMask(savedMask);
	g_USBVideo.video_control.dma_type = USBVIDEO_DMA_STILL;
	USBVideo_Send_Video();
}

/* Handler for device request still image from media task */
static void USBVideo_Dev_Still_Req_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_bool  bSendMsg;

	if(g_USBVideo.state==USBVIDEO_STATE_STOP)
	{
		/* cable may have been plug out, return error to media task*/
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_DEVICE_STILL_CNF, (kal_uint32)KAL_FALSE, 0);
		return;
	}
	
	if((g_USBVideo.state == USBVIDEO_STATE_PRE_PAUSE) || (g_USBVideo.state == USBVIDEO_STATE_PAUSE))
	{
		/* return error to media task */
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_DEVICE_STILL_CNF, (kal_uint32)KAL_FALSE, 0);
	}
	else if(g_USBVideo.still_probe_state == USBVIDEO_COMMIT_DONE)
	{
		/* send buttom press interrupt to host */
		g_USBVideo.vs_status_pkt.bStuausType = USBVIDEO_STATUS_TYPE_VS;
		g_USBVideo.vs_status_pkt.bOriginator = g_USBVideo.vs_interface_id;
		g_USBVideo.vs_status_pkt.bEvent = USBVIDEO_STATUS_VS_EVENT_BUTTOM_PRS;
		g_USBVideo.vs_status_pkt.bValue = USBVIDEO_STATUS_VS_VALUE_BUTTOM_PRS;
		bSendMsg = USBVideo_Send_Intr(&g_USBVideo.vs_status_pkt,sizeof(USBVideo_VS_Status_Pkt_Struct));
		/* return succuess to media task */
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_DEVICE_STILL_CNF, (kal_uint32)bSendMsg, 0);
	}
	else
	{
		/* return error to media task, may because still probe is not commit */
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_DEVICE_STILL_CNF, (kal_uint32)KAL_FALSE, 0);
	}
}

/* GPT timeout function for pre pause timeout */
/* It may be happened when pause request recvd but host application does not open and does not ask for video */
static void USBVideo_PrePause_Timeout(void *parameter)
{
//	kal_uint32 savedMask;
	kal_bool b_sendmsg = KAL_FALSE;
	USBVIDEO_DMA_TYPE dma_type = USBVIDEO_DMA_NONE;
	
	
	GPTI_StopItem(g_USBVideo.video_control.timer_handle);
	
	/* Avoid race condition with DMA or USB HISR */
//	savedMask = SaveAndSetIRQMask();

	/* GPT HISR has lower priority than DMA HISR, so there should be no GPT preempt DMA case
	     If the priority is changed, the whole part of DMA callback should disable intereupt */
/*
	if(g_USBVideo.video_control.b_processing_dma == KAL_TRUE)
			EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.b_processing_dma, 
						(kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state);
*/
	/* stop DMA if it is on */
	if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE) == KAL_TRUE)
	{
		USB_Stop_DMA_Channel(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE);

		#ifdef WEBCAM_TEST_DMA_DELAY
			g_USBVideo.test_enable = KAL_FALSE;
		#endif

		/* clear FIFO, if not clear it, the next packet may be false */
		USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP);
		
		/* clear dma running state here*/
		USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE, KAL_FALSE);

		g_USBVideo.video_control.sent_video_size = 0;

		/* Notify state machine to update state */
		if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_VIDEO)
		{
			b_sendmsg = KAL_TRUE;
			dma_type = USBVIDEO_DMA_VIDEO;
		}
		else if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_STILL)
		{
			b_sendmsg = KAL_TRUE;
			dma_type = USBVIDEO_DMA_STILL;
		}
		else if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_INCALL_JPEG)
		{
			/* Note that if pause and then resume, without open PC application, and then pause again, pre_pause state may happen */
			b_sendmsg = KAL_TRUE;
			dma_type = USBVIDEO_DMA_INCALL_JPEG;
		}
		else 
			ASSERT(0);
	}	

//	RestoreIRQMask(savedMask);	

	if(b_sendmsg==KAL_TRUE)
	{
		g_USBVideo.video_control.dma_done_type = USBVIDEO_DMA_DONE_STOP;

		if(dma_type == USBVIDEO_DMA_VIDEO)
		{
			USBVideo_Send_Msg(USBVIDEO_MSG_USB_DMA_DONE, MOD_GPT_HISR, 0);
		}
		else if(dma_type == USBVIDEO_DMA_STILL)
		{
			USBVideo_Send_Msg(USBVIDEO_MSG_USB_STILL_DMA_DONE, MOD_GPT_HISR, 0);
		}
		else if(dma_type == USBVIDEO_DMA_INCALL_JPEG)
		{
			USBVideo_Send_Msg(USBVIDEO_MSG_USB_INCALL_DMA_DONE, MOD_GPT_HISR, 0);
		}
	}
}

/* Handler for pause request from media task */
static void USBVideo_Pause_Req_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	usbvideo_default_JPEG_struct *video_default_jpeg_info;
	kal_bool  bSendMsg;
	kal_uint32 savedMask;
	usbvideo_default_JPEG_Info*p_default_jpeg;
	kal_uint8 video_size_num;
	const USBVideo_Video_Size_Info *p_video_size_param;
	kal_uint32 index;

	if((g_USBVideo.state==USBVIDEO_STATE_PRE_PAUSE) || (g_USBVideo.state==USBVIDEO_STATE_PAUSE))
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);	
	
	if(g_USBVideo.state==USBVIDEO_STATE_STOP)
	{
		/* cable may have been plug out, return error */
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_PAUSE_CNF, (kal_uint32)KAL_FALSE, 0);
		return;
	}

	video_default_jpeg_info=(usbvideo_default_JPEG_struct *)p_recv_ilm->local_para_ptr;
	g_USBVideo.default_jpeg_info = video_default_jpeg_info->jpeg_info;
	g_USBVideo.default_jpeg_num = video_default_jpeg_info->size;
     /* The in-call JPEG information is no needed in descriptor
	    Add here just for checking image size matches video size */
	p_video_size_param = g_USBVideo.camera_param->usbvideo_get_video_size_info(&video_size_num);    

	if(g_USBVideo.default_jpeg_num != video_size_num)
		EXT_ASSERT(0, g_USBVideo.default_jpeg_num, video_size_num, 0);

	for(index = 0; index < g_USBVideo.default_jpeg_num; index++)
	{
		if(g_USBVideo.default_jpeg_info[index].width != p_video_size_param[index].width)
			EXT_ASSERT(0, index, g_USBVideo.default_jpeg_info[index].width, p_video_size_param[index].width);
		if(g_USBVideo.default_jpeg_info[index].height!= p_video_size_param[index].height)
			EXT_ASSERT(0, index, g_USBVideo.default_jpeg_info[index].height, p_video_size_param[index].height);
	}
	
	savedMask = SaveAndSetIRQMask();
	if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE) == KAL_TRUE)
	{
		g_USBVideo.state = USBVIDEO_STATE_PRE_PAUSE;
		g_USBVideo.video_control.b_stop_timer = KAL_FALSE;
		GPTI_StartItem(g_USBVideo.video_control.timer_handle, USBVIDEO_PRE_PAUSE_TIMEOUT, USBVideo_PrePause_Timeout, NULL);
		bSendMsg = KAL_FALSE;
	}
	else
	{
		g_USBVideo.state = USBVIDEO_STATE_PAUSE;	
		bSendMsg = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);
	
	if(bSendMsg == KAL_TRUE)
	{
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_PAUSE_CNF, (kal_uint32)KAL_TRUE, 0);
		//p_default_jpeg = g_USBVideo.mmi_param->usbvideo_get_incall_jpeg_info(&incall_size_num);
		p_default_jpeg = g_USBVideo.default_jpeg_info;
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.still_count = 0;
		g_USBVideo.video_control.sent_video_size = 0;
		g_USBVideo.video_control.incall_jpeg_addr = p_default_jpeg[g_USBVideo.commit_video_index - 1].start_addr;
		g_USBVideo.video_control.incall_jpeg_size = p_default_jpeg[g_USBVideo.commit_video_index - 1].size;
		RestoreIRQMask(savedMask);
		g_USBVideo.video_control.dma_type = USBVIDEO_DMA_INCALL_JPEG;
		USBVideo_Send_Incall_JPEG();
	}
}

/* Handler for incall  timeout from GPT HISR*/
static void USBVideo_InCall_Timeout_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_uint32 savedMask;
	usbvideo_default_JPEG_Info*p_default_jpeg;

	/* This is executed in USB task, incase this msg is handled after resume handler (may change to send state),
	    so no state check here */
	if(g_USBVideo.state==USBVIDEO_STATE_PAUSE)
	{
		//p_incall_param = g_USBVideo.mmi_param->usbvideo_get_incall_jpeg_info(&incall_size_num);
		p_default_jpeg = g_USBVideo.default_jpeg_info;
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.incall_jpeg_addr = p_default_jpeg[g_USBVideo.commit_video_index - 1].start_addr;
		g_USBVideo.video_control.incall_jpeg_size = p_default_jpeg[g_USBVideo.commit_video_index - 1].size;
		RestoreIRQMask(savedMask);
		g_USBVideo.video_control.dma_type = USBVIDEO_DMA_INCALL_JPEG;
		USBVideo_Send_Incall_JPEG();	
	}
}

/* GPT timeout function for incall setting*/
static void USBVideo_Incall_Timeout(void *parameter)
{
	GPTI_StopItem(g_USBVideo.video_control.timer_handle);
	USBVideo_Send_Msg(USBVIDEO_MSG_USB_INCALL_TIMEOUT, 0, 0);
}

/* Handler for incall JPEG DMA done from DMA HISR */
static void USBVideo_InCall_DMA_Done_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_bool	bBufferEmpty = KAL_FALSE;
	kal_uint32 savedMask;
	usbvideo_default_JPEG_Info*p_default_jpeg;
	kal_uint32 total_size;
	kal_bool bEPEmpty;
	kal_uint32 count;

	if(g_USBVideo.state==USBVIDEO_STATE_STILL)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);	
	
	if(g_USBVideo.state == USBVIDEO_STATE_STOP)
		return;

	if(g_USBVideo.video_control.dma_done_type == USBVIDEO_DMA_DONE_COMPLETE)
	{
		/* send NULL packet only when dma done type is complete */
		p_default_jpeg = g_USBVideo.default_jpeg_info;		
		total_size = p_default_jpeg[g_USBVideo.commit_video_index - 1].size;
		count = total_size/(USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH);
		if(total_size%(USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH)!=0)
			count++;
		if(((total_size+count*USBVIDEO_PAYLOAD_HEADER_LENGTH)%USB_EP_BULK_MAXP) == 0)
		{
			/* multiple of 64 bytes */
		
			/* make sure previous packets are already sent out
			   maybe last DMA data has triggered DMA done but data are still in FIFO*/
			bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			/* If cable plug out at this time, add timeout to avoid looping here */
			while((bEPEmpty == KAL_FALSE)&&(count<100))
			{
				count++;	
				kal_sleep_task(1);	
				bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			}
		
			/* send out a NULL packet */
			USB_EPFIFOWrite(g_USBVideo.txpipe->byEP, 0, NULL);
			USB_EP_Bulk_Tx_Ready(g_USBVideo.txpipe->byEP);
		
			/* mak sure previous NULL pkt has been sent out
			   avoid next DMA data in FIFO sent out instead of previos NULL pkt.*/
		
			bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			/* If cable plug out at this time, add timeout to avoid looping here */
			count = 0;
			while((bEPEmpty == KAL_FALSE)&&(count<100))
			{
				count++;	
				kal_sleep_task(1);	
				bEPEmpty = USB_Is_EP_Bulk_Tx_Empty(g_USBVideo.txpipe->byEP);
			}
		}
	}			
	
	/* Note that if pause and then resume, without open PC application, and then pause again, pre_pause state may happen */
	if(g_USBVideo.state == USBVIDEO_STATE_PRE_PAUSE)
	{
		/* stop pre-pause timer */
		GPTI_StopItem(g_USBVideo.video_control.timer_handle);
		g_USBVideo.state = USBVIDEO_STATE_PAUSE;	
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_PAUSE_CNF, (kal_uint32)KAL_TRUE, 0);
		//p_default_jpeg = g_USBVideo.mmi_param->usbvideo_get_incall_jpeg_info(&incall_size_num);
		p_default_jpeg = g_USBVideo.default_jpeg_info;
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.still_count = 0;
		g_USBVideo.video_control.sent_video_size = 0;
		g_USBVideo.video_control.incall_jpeg_addr = p_default_jpeg[g_USBVideo.commit_video_index - 1].start_addr;
		g_USBVideo.video_control.incall_jpeg_size = p_default_jpeg[g_USBVideo.commit_video_index - 1].size;
		RestoreIRQMask(savedMask);
		g_USBVideo.video_control.dma_type = USBVIDEO_DMA_INCALL_JPEG;
		USBVideo_Send_Incall_JPEG();
	}
	else if(g_USBVideo.state==USBVIDEO_STATE_PAUSE)
	{
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.sent_video_size = 0;
		RestoreIRQMask(savedMask);
		/* start a timer to periodicaly send this image to PC */
		if(g_USBVideo.video_control.b_stop_timer == KAL_FALSE)
			GPTI_StartItem(g_USBVideo.video_control.timer_handle, USBVIDEO_INCALL_JPEG_TIMEOUT, USBVideo_Incall_Timeout, NULL);
	}
	else if((g_USBVideo.state==USBVIDEO_STATE_SEND) ||(g_USBVideo.state==USBVIDEO_STATE_DROP))
	{
		savedMask = SaveAndSetIRQMask();
		g_USBVideo.video_control.sent_video_size = 0;
		/* receive resume msg and back to send state */
		if(g_USBVideo.video_control.video_buffer_read_index==g_USBVideo.video_control.video_buffer_write_index)
		{
			/* buffer empty */
			bBufferEmpty = KAL_TRUE;
			g_USBVideo.video_control.send_video_msg = KAL_TRUE;
		}
		RestoreIRQMask(savedMask);
		if(bBufferEmpty==KAL_FALSE)
		{
			g_USBVideo.video_control.dma_type = USBVIDEO_DMA_VIDEO;
			USBVideo_Send_Video();
		}	
	}
}

static void USBVideo_InCall_Change_Size_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	kal_uint32 savedMask;
	kal_bool b_sendmsg = KAL_FALSE;
	
	if(g_USBVideo.state != USBVIDEO_STATE_PAUSE)
		return;

	savedMask = SaveAndSetIRQMask();
	/* If DMA is running, there will be done message trigger next image */
	if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE) == KAL_FALSE)
	{
		g_USBVideo.video_control.b_stop_timer = KAL_FALSE;
		GPTI_StopItem(g_USBVideo.video_control.timer_handle);
		b_sendmsg = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);

	if(b_sendmsg==KAL_TRUE)
		USBVideo_Send_Msg(USBVIDEO_MSG_USB_INCALL_TIMEOUT, 0, 0);
}

/* Handler for resume request from media task */
static void USBVideo_Resume_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	usbvideo_video_req_struct *video_req;
	kal_uint32 savedMask;
	const USBVideo_Video_Size_Info *p_video_size_param;
	const USBVideo_Still_Size_Info *p_still_size_param;
	kal_uint8 video_size_num;
	kal_uint8 still_size_num;
	kal_uint32 index;

	if((g_USBVideo.state==USBVIDEO_STATE_SEND)  || (g_USBVideo.state==USBVIDEO_STATE_STILL) 
		|| (g_USBVideo.state==USBVIDEO_STATE_DROP) || (g_USBVideo.state==USBVIDEO_STATE_PRE_PAUSE))
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, 0, 0);	
	
	if(g_USBVideo.state == USBVIDEO_STATE_STOP)
	{
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_RESUME_FAIL_CNF, 0, 0);
		return;
	}
	
	/* The resume requset must wait for pause request confirm no matter success or not */
	//if((g_USBVideo.state==USBVIDEO_STATE_PAUSE) || (g_USBVideo.state==USBVIDEO_STATE_PRE_PAUSE) )
	if(g_USBVideo.state==USBVIDEO_STATE_PAUSE)
	{
		GPTI_StopItem(g_USBVideo.video_control.timer_handle);
		g_USBVideo.state = USBVIDEO_STATE_SEND;

		savedMask = SaveAndSetIRQMask();
		if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_TX_EP_TYPE) == KAL_FALSE)
			g_USBVideo.video_control.send_video_msg = KAL_TRUE;
		else
			g_USBVideo.video_control.send_video_msg = KAL_FALSE; /* let incall dma done to start video */
		video_req=(usbvideo_video_req_struct *)p_recv_ilm->local_para_ptr;
		g_USBVideo.video_control.video_buffer_read_index = 0;
		g_USBVideo.video_control.video_buffer_write_index = 0;
		g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		g_USBVideo.video_control.sent_video_size = 0;
		//g_USBVideo.video_control.video_frame_id = 0;
		/* 4-bytes align, the jpeg need 4-bytes alignment buffer */
		g_USBVideo.video_control.video_buffer_addr[0] = (kal_uint8*)(((kal_uint32)video_req->buffer_addr + (4-1))&(~(4-1)));
		g_USBVideo.video_control.video_buffer_size = (video_req->buffer_size - ((4-1)*USBVIDEO_VIDEO_BUFFER_NUMBER))/USBVIDEO_VIDEO_BUFFER_NUMBER;
		/* 4-bytes align, the jpeg need 4-bytes alignment buffer */
		g_USBVideo.video_control.video_buffer_size = (g_USBVideo.video_control.video_buffer_size + (4-1))& (~(4-1));	
		for(index = 1; index < USBVIDEO_VIDEO_BUFFER_NUMBER; index++)
		{
			g_USBVideo.video_control.video_buffer_addr[index] = g_USBVideo.video_control.video_buffer_addr[index - 1] + g_USBVideo.video_control.video_buffer_size;
		}
		
		RestoreIRQMask(savedMask);
		
		/* chek the video buffer size larger than all custom camera video buffer, and still size also */
		p_video_size_param = g_USBVideo.camera_param->usbvideo_get_video_size_info(&video_size_num);
		p_still_size_param = g_USBVideo.camera_param->usbvideo_get_still_size_info(&still_size_num);
		for(index = 0; index < video_size_num; index++)
		{
			if(g_USBVideo.video_control.video_buffer_size < (p_video_size_param[index].max_frame_size+USBVIDEO_PAYLOAD_HEADER_LENGTH))
			{
				EXT_ASSERT(0, g_USBVideo.video_control.video_buffer_size, index, p_video_size_param[index].max_frame_size);
			}			
		}
		for(index = 0; index < still_size_num; index++)
		{
			if(video_req->buffer_size < (p_still_size_param[index].max_frame_size+USBVIDEO_PAYLOAD_HEADER_LENGTH))
			{
				EXT_ASSERT(0, video_req->buffer_size, index, p_still_size_param[index].max_frame_size);
			}			
		}

		USBVideo_Send_Msg(USBVIDEO_MSG_MED_RESUME_SUCCESS_CNF, g_USBVideo.commit_video_index, g_USBVideo.video_compression_index);
	}	
}

/* Handler for stop request from media task */
static void USBVideo_Stop_Req_Hdlr(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	g_USBVideo.state = USBVIDEO_STATE_STOP;
	USBVideo_Send_Msg(USBVIDEO_MSG_MED_STOP_CNF, (kal_uint32)KAL_TRUE, 0);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* Handler for USB cable plug out indication from EINT HISR */
void USBVideo_Plug_Out_Hdlr(void)
{
	if(g_USBVideo.video_start_state == USBVIDEO_START_RECV_MED_REQ)
	{
		/* media task is waiting for this fail confirm*/
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_START_FAIL_CNF, 0, 0);
		g_USBVideo.video_start_state = USBVIDEO_START_NONE;
	}

	if(g_USBVideo.state==USBVIDEO_STATE_PRE_PAUSE)
	{
		GPTI_StopItem(g_USBVideo.video_control.timer_handle);
		USBVideo_Send_Msg(USBVIDEO_MSG_MED_PAUSE_CNF, (kal_uint32)KAL_FALSE, 0);
	}

	g_USBVideo.state = USBVIDEO_STATE_STOP;
	USBVideo_Send_Msg(USBVIDEO_MSG_MED_STOP_IND, 0, 0);
}

/* Parse all messages from USB HISR, DMA HISR, camera HISR, and media task */
void USBVideo_Parse_Med_Msg(ilm_struct *p_recv_ilm, USB_DEVICE_TYPE device_type)
{
	switch(p_recv_ilm->msg_id)
	{
	case MSG_ID_USB_MED_SET_CAMERA_ATTR_CNF:
		USBVideo_Attr_Cnf_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_USB_ENUM_DONE:
		USBVideo_Enum_Done_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_MED_USB_START_VIDEO_REQ:
		USBVideo_Start_Video_Req_Hdlr(p_recv_ilm, device_type);
		break;	
	case MSG_ID_USB_VIDEO_CHANGE_SIZE:
		USBVideo_Change_Video_Size_Hdlr(p_recv_ilm, device_type);
		break;	
	case MSG_ID_USB_VIDEO_COMPLETE:
		USBVideo_Video_Complete_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_USB_VIDEO_DMA_DONE:
		USBVideo_Video_DMA_Done_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_USB_VIDEO_STILL_DMA_DONE:
		USBVideo_Still_DMA_Done_Hdlr(p_recv_ilm, device_type);
		break;	
	case MSG_ID_USB_VIDEO_STILL_DMA_PARTIAL:
		USBVideo_Still_DMA_Partial_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_USB_STILL_CAPTURE:
		USBVideo_Still_Capture_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_USB_STILL_COMPLETE:
		USBVideo_Still_Complete_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_MED_USB_DEVICE_STILL_REQ:
		USBVideo_Dev_Still_Req_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_MED_USB_PAUSE_REQ:
		USBVideo_Pause_Req_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_USB_VIDEO_INCALL_TIMEOUT:
		USBVideo_InCall_Timeout_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_USB_VIDEO_INCALL_DMA_DONE:
		USBVideo_InCall_DMA_Done_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_USB_VIDEO_INCALL_CHANGE_SIZE:
		USBVideo_InCall_Change_Size_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_MED_USB_RESUME_VIDEO_REQ:
		USBVideo_Resume_Hdlr(p_recv_ilm, device_type);
		break;
	case MSG_ID_MED_USB_STOP_REQ:
		USBVideo_Stop_Req_Hdlr(p_recv_ilm, device_type);
		break;	
	case MSG_ID_USB_VIDEO_ABORT:
//		USBVideo_Abort_Hdlr(p_recv_ilm, device_type);
		break;
	default:
		EXT_ASSERT(0, p_recv_ilm->msg_id, (kal_uint32)g_USBVideo.state, 0);
		break;
	}
	
}

#endif /* WEBCAM_SUPPORT */

