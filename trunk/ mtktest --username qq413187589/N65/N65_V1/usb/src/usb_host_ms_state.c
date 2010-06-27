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
 *    usb_host_ms_state.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host mass storage class state machine 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "drv_comm.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "gpt_sw.h"
#include "usb_comm.h"
#include "usb.h"
#include "usbd.h"
#include "otg_drv.h"
#include "otg.h"

#include "usbms_state.h"
#include "usb_host_ms_drv.h"
#include "usb_host_ms_state.h"

#ifdef __OTG_ENABLE__

static void USB_Host_Ms_State_Timeout(void *parameter);
static void USB_Host_MS_Query_Media(kal_uint8 lun);
static void USB_Host_MS_Check_Media(kal_uint8 lun);
static kal_bool USB_Host_Ms_Error_Check(void);
static void USB_Host_Ms_Error_Handler(void);
static kal_bool USB_Host_Ms_Comp_Get_LUN(void);
static kal_bool USB_Host_Ms_Query_All_Media(void);
static kal_bool USB_Host_Ms_Check_All_Media(void);


/************************************************************
	ms class state functions. Matintain the state of each LUN 
*************************************************************/

/* Query media info for lun parameter */
/* This query function should be called when first detect the lun plug in */
static void USB_Host_MS_Query_Media(kal_uint8 lun)
{
	USB_HOST_MS_RESULT result;

	g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_READY;

	/* Send INQUIRY request to device */
	result = USB_Host_Ms_Inquiry(lun);
	if(result!=USB_HOST_MS_RESULT_OK)
	{
		/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
		g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		return;
	}	
	
	/* Send READ FORMAT CAPACITY request to device */
	result = USB_Host_Ms_Read_Format_Capacity(lun);
	if(result!=USB_HOST_MS_RESULT_OK)
	{
		/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
		g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		return;
	}	
	
	/* Send READ CAPACITY request to device */
	result = USB_Host_Ms_Read_Capacity(lun);
	if(result!=USB_HOST_MS_RESULT_OK)
	{
		/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
		g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		return;
	}	
}

/* Check media info for lun parameter */
/* This check function should be called periodically when slot is still attched */
static void USB_Host_MS_Check_Media(kal_uint8 lun)
{
	USB_HOST_MS_RESULT result;
	kal_bool b_state_change = KAL_FALSE;
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs.media_info[lun].state;

	g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_READY;

	/* Send TEST UNIT READY request to device */
	result = USB_Host_Ms_Test_Unit_Ready(lun);
	if(result!=USB_HOST_MS_RESULT_OK)
	{
		/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
		g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		return;
	}	

	/* state may change from READY->CHANGED at this step, and CHANGED->READY at next step  */
	if(media_state!=g_UsbHostMs.media_info[lun].state)
		b_state_change = KAL_TRUE;

	if(g_UsbHostMs.media_info[lun].state==USB_HOST_MS_MEDIA_STATE_CHANGED)
	{
		/* If card is plug in in caed reader, the previous state would be state changed, so query state again*/
		/* If this request finds media state cahnge to READY, then capacity can be queried in the following step directly */
		result = USB_Host_Ms_Test_Unit_Ready(lun);
		if(result!=USB_HOST_MS_RESULT_OK)
		{
			/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
			g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
			return;
		}	
	}
		
	if(media_state!=g_UsbHostMs.media_info[lun].state)
		b_state_change = KAL_TRUE;
		
	if((b_state_change==KAL_TRUE) && (g_UsbHostMs.media_info[lun].state==USB_HOST_MS_MEDIA_STATE_READY))
	{
		/* state cahnge from NON_READY to READY*/
	
		/* Send READ CAPACITY request to device */
		result = USB_Host_Ms_Read_Capacity(lun);
		if(result!=USB_HOST_MS_RESULT_OK)
		{
			/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
			if(result!=USB_HOST_MS_RESULT_FORMAT_ERROR)
			{
				g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
			}	
			return;
		}	
	
		/* Send MODE SENSE6 request to device. Query whether the device is write protected or not */
		result = USB_Host_Ms_Mode_Sense6(lun);
		if(result!=USB_HOST_MS_RESULT_OK)
		{
			/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
			g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
			return;
		}
		
		if(g_UsbHostMs.media_info[lun].state == USB_HOST_MS_MEDIA_STATE_ERROR)
		{
			/* Send READ CAPACITY request to device */
			result = USB_Host_Ms_Read_Capacity(lun);
			if(result!=USB_HOST_MS_RESULT_OK)
			{
				/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
				if(result!=USB_HOST_MS_RESULT_FORMAT_ERROR)
				{
					g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
				}
				return;
			}	
		
			/* Try all mode again */
			result = USB_Host_Ms_Mode_Sense6_All_Mode(lun);
			if(result!=USB_HOST_MS_RESULT_OK)
			{
				/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
				g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
				return;
			}
		}

		if(g_UsbHostMs.media_info[lun].state == USB_HOST_MS_MEDIA_STATE_ERROR)
		{
			/* Try mode sense 10 again */
			result = USB_Host_Ms_Mode_Sense10_All_Mode(lun);
			if(result!=USB_HOST_MS_RESULT_OK)
			{
				/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
				g_UsbHostMs.dev_state = USB_HOST_MS_DEV_STATE_ERROR;
				return;
			}
		}
	}	
}


/* Return true means error happens*/
/* In this function, try to issue ms class specific reset command and see if error count exceed limit */
static kal_bool USB_Host_Ms_Error_Check(void)
{
	while(g_UsbHostMs.dev_error_count<3)
	{
		/* At most reset 3 times */
		USB_Host_Ms_Reset();
		if(g_UsbHostMs.dev_state==USB_HOST_MS_DEV_STATE_ERROR)
			g_UsbHostMs.dev_error_count++;
		else
			break;	
	}	
	
	if((g_UsbHostMs.dev_error_count>=3) ||(g_UsbHostMs.dev_attatch==KAL_FALSE))
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/* Serious error happens and it can not be recovered from error handling mechanism in ms class */
/* Stop the MS action and turn off OTG  power */
static void USB_Host_Ms_Error_Handler(void)
{
	kal_uint32 index;
	kal_bool b_send_msg = KAL_FALSE;
	
	GPTI_StopItem(g_UsbHostMs.gpt_handle);

	for(index=0; index<g_UsbHostMs.total_lun; index++)
	{
		/* If original state is READY, set state change as true */
		if(((g_UsbHostMs.media_info[index].state==USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
			||(g_UsbHostMs.media_info[index].state==USB_HOST_MS_MEDIA_STATE_READY))
			&& (g_UsbHostMs.media_info[index].sec_size!=0))
		{
			//g_UsbHostMs.b_state_change = KAL_TRUE;
			g_UsbHostMs.media_state_change |= (1<<index);
		}
		
		/* Set all the media state to error */
		g_UsbHostMs.media_info[index].state = USB_HOST_MS_MEDIA_STATE_ERROR;
	}

	/* Stop OTG action */
	if(OTG_Get_Plug_Type()==OTG_PLUG_A)
	{
		OTG_A_Stop_Host();
	}
	else
	{
		OTG_B_Stop_Host(); 
	}

	/* Notify FMT about media change */
	//if(g_UsbHostMs.b_state_change==KAL_TRUE)
	//{
	//	g_UsbHostMs.b_state_change = KAL_FALSE;
	//	USB_Host_Ms_SendInd(USB_HOST_MS_MSG_MEDIA_CHANGE);
	//}

	if(g_UsbHostMs.dev_attatch==KAL_TRUE)
	{
		if((g_UsbHostMs.media_state_change != 0) && (g_UsbHostMs.b_sending_change_ilm == KAL_FALSE))
		{
			for(index=0; index<g_UsbHostMs.total_lun; index++)
			{
				if((g_UsbHostMs.media_state_change&(1<<index))!=0)
				{
					if(g_UsbHostMs.media_info[index].state != g_UsbHostMs.media_info[index].pre_state)
					{
						g_UsbHostMs.media_info[index].pre_state = g_UsbHostMs.media_info[index].state;
						g_UsbHostMs.media_msg_array[index] = (kal_uint32)&g_UsbHostMs.media_handle[index];
						b_send_msg = KAL_TRUE;
					}
					else
					{
						g_UsbHostMs.media_msg_array[index] = NULL;
					}
				}
				else
				{
					g_UsbHostMs.media_msg_array[index] = NULL;
				}
			}
			g_UsbHostMs.media_state_change = 0;
			if(b_send_msg == KAL_TRUE)
			{
				USB_Host_Ms_SendInd(USB_HOST_MS_MSG_MEDIA_CHANGE);
			}
		}
	
		OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT);
	}	
}	

/************************************************************
	ms class state functions. Matintain the state of all LUN 
*************************************************************/

/* Get device LUN. It contains the total error handling. 
     If result is fail, the host function is turned off in this function */
static kal_bool USB_Host_Ms_Comp_Get_LUN(void)
{
	/* Send class specific GET_LUN EP0 command to device*/
	USB_Host_Ms_Get_LUN();
	if(g_UsbHostMs.dev_state==USB_HOST_MS_DEV_STATE_ERROR)
	{
		g_UsbHostMs.dev_error_count++;
		if(USB_Host_Ms_Error_Check()==KAL_TRUE)
		{
			/* It means reset is no use or error count exceed limit */
			/* some device may not implement this command, but PC can detect it */
			//USB_Host_Ms_Error_Handler();
		}
		else
		{
			/* reset is complete, so GET_LUN again */
			/* Error handling is in the recursive function */
			USB_Host_Ms_Comp_Get_LUN();
		}
	}


	if((g_UsbHostMs.dev_error_count>=3) ||(g_UsbHostMs.dev_attatch==KAL_FALSE))
	{
		/* Error count exceed limit, host function has been turned off in error handler */
		return KAL_FALSE;
	}
	else
	{
		/* Reset error count. Avoid error count propagete */
		g_UsbHostMs.dev_error_count = 0;
		return KAL_TRUE;
	}		
}


/* Query all LUN media. It contains the total error handling. 
     If result is fail, the host function is turned off in this function */
static kal_bool USB_Host_Ms_Query_All_Media(void)
{
	kal_uint32 index;
	kal_uint32 index2;
	for(index = 0; index < g_UsbHostMs.total_lun; index++)
	{
		/* query the dedicated LUN*/
		USB_Host_MS_Query_Media(index);
		if(g_UsbHostMs.dev_state==USB_HOST_MS_DEV_STATE_ERROR)
		{
			g_UsbHostMs.dev_error_count++;

			/* reset all media state */
			for(index2 = 0; index2 < g_UsbHostMs.total_lun; index2++)
				g_UsbHostMs.media_info[index2].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
			
			if(USB_Host_Ms_Error_Check()==KAL_TRUE)
			{
				/* It means reset is no use or error count exceed limit */
				USB_Host_Ms_Error_Handler();
				break;
			}
			else
			{
				/* reset is complete, so Query all media again */
				/* Error handling is in the recursive function */				
				USB_Host_Ms_Query_All_Media();
				break;
			}
		}
	}

	if((g_UsbHostMs.dev_error_count>=3)||(g_UsbHostMs.dev_attatch==KAL_FALSE))
	{
		/* Error count exceed limit, host function has been turned off in error handler */
		return KAL_FALSE;
	}
	else
	{
		/* Reset error count. Avoid error count propagete */
		g_UsbHostMs.dev_error_count = 0;
		return KAL_TRUE;
	}	
}

/* Query all LUN media. It contains the total error handling. 
     If result is fail, the host function is turned off in this function */
static kal_bool USB_Host_Ms_Check_All_Media(void)
{
	kal_uint32 index;
	kal_uint32 index2; 
	for(index = 0; index < g_UsbHostMs.total_lun; index++)
	{
		/* Note that task and give the mutex in lun level. To reduce the latency in application read and write */
		kal_take_mutex(g_UsbHostMs.mutex_id);
		/* check the dedicated LUN*/
		USB_Host_MS_Check_Media(index);
		if(g_UsbHostMs.dev_state==USB_HOST_MS_DEV_STATE_ERROR)
		{
			g_UsbHostMs.dev_error_count++;

			/* reset all media state */
			for(index2 = 0; index2 < g_UsbHostMs.total_lun; index2++)
				g_UsbHostMs.media_info[index2].state = USB_HOST_MS_MEDIA_STATE_ABSENT;

			/* should modify to dev error, reset device */
			if(USB_Host_Ms_Error_Check()==KAL_TRUE)
			{
				/* It means reset is no use or error count exceed limit */
				USB_Host_Ms_Error_Handler();
				kal_give_mutex(g_UsbHostMs.mutex_id);
				break;
			}
			else
			{
				/* reset is complete, so check all media again */
				/* Error handling is in the recursive function */	
				kal_give_mutex(g_UsbHostMs.mutex_id);
				USB_Host_Ms_Check_All_Media();
				break;
			}
		}
		else
			kal_give_mutex(g_UsbHostMs.mutex_id);
	}	

	if((g_UsbHostMs.dev_error_count>=3) ||(g_UsbHostMs.dev_attatch==KAL_FALSE) )
	{
		/* Error count exceed limit, host function has been turned off in error handler */
		return KAL_FALSE;
	}
	else
	{
		/* Reset error count. Avoid error count propagete */
		g_UsbHostMs.dev_error_count = 0;
		return KAL_TRUE;
	}	
}


/************************************************************
	state machine entry functions 
*************************************************************/

/* GPT timeout function*/
/* This GPT timer is used to periodically checking media status*/
static void USB_Host_Ms_State_Timeout(void *parameter)
{
	ilm_struct *usb_ilm;
	
	GPTI_StopItem(g_UsbHostMs.gpt_handle);
	
	/* Send msg to USB task, in order to start ms state machine */
	DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,
					MOD_USB, MSG_ID_USB_MSHOST_QUERY_IND, NULL);
	msg_send_ext_queue(usb_ilm);
}


/* Start ms state. Initialize state info and query each slot info */
/* Note that this function should be called when first detect ms device*/
void USB_Host_Ms_State_Start(void)
{
	kal_uint32 index;
	kal_bool result;
	kal_bool b_send_msg = KAL_FALSE;
	
	/* Initailize the information */
	if(g_UsbHostMs.event_id==0)
		g_UsbHostMs.event_id = kal_create_event_group("USB_MS_EVEVT");

	if(g_UsbHostMs.mutex_id==0)
		g_UsbHostMs.mutex_id = kal_create_mutex("USB_MS_MUTEX");
			
	if (g_UsbHostMs.gpt_handle == 0)
		GPTI_GetHandle(&g_UsbHostMs.gpt_handle);

	g_UsbHostMs.total_lun=0;

	/* Get LUN, it contains the error handling */
	result = USB_Host_Ms_Comp_Get_LUN();
	/* If result is fail, ms has been detached*/
	if(result==KAL_TRUE)
	{
		/* The got LUN is total lun - 1 */
		g_UsbHostMs.total_lun++;
		/* If LUN number is larger than we can support, onlt the first N can be detected */
		if(g_UsbHostMs.total_lun>g_UsbHostMs.support_lun)
			g_UsbHostMs.total_lun = g_UsbHostMs.support_lun;
		/* Set all the LUN state to absent state */
		for(index = 0; index<g_UsbHostMs.total_lun; index++)
			g_UsbHostMs.media_info[index].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
	}	
	else
	{
		result = KAL_TRUE;
		/* when device not implement this command, it is only one LUN */
		g_UsbHostMs.dev_error_count = 0;
		g_UsbHostMs.total_lun = 1;	
		/* Set all the LUN state to absent state */
		for(index = 0; index<g_UsbHostMs.total_lun; index++)
			g_UsbHostMs.media_info[index].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
	}
	
	if(result==KAL_TRUE)
	{
		/* Get LUN is succuss, continue to query each LUN info*/
		result = USB_Host_Ms_Query_All_Media();
		/* If result is fail, ms has been detached*/
	}	
	
	if(result==KAL_TRUE)
	{
		/* Query each LUN is succuss, continue to check whether each LUN is in card slot or not*/
		result = USB_Host_Ms_Check_All_Media();
		/* If result is fail, ms has been detached*/
	}	

	if( (result==KAL_TRUE) && (g_UsbHostMs.media_state_change != 0) 
		&& (g_UsbHostMs.b_sending_change_ilm == KAL_FALSE))
	{
		/* Send message to FMT task about card state change */
		for(index=0; index<g_UsbHostMs.total_lun; index++)
		{
			if((g_UsbHostMs.media_state_change&(1<<index))!=0)
			{
				if(g_UsbHostMs.media_info[index].state != g_UsbHostMs.media_info[index].pre_state)
				{
					g_UsbHostMs.media_info[index].pre_state = g_UsbHostMs.media_info[index].state;
					g_UsbHostMs.media_msg_array[index] = (kal_uint32)&g_UsbHostMs.media_handle[index];
					b_send_msg = KAL_TRUE;
				}
				else
				{
					g_UsbHostMs.media_msg_array[index] = NULL;
				}
			}
			else
			{
				g_UsbHostMs.media_msg_array[index] = NULL;
			}
		}
		g_UsbHostMs.media_state_change = 0;
		if(b_send_msg == KAL_TRUE)
		{
			USB_Host_Ms_SendInd(USB_HOST_MS_MSG_MEDIA_CHANGE);
		}
	}


	if(result==KAL_TRUE)
	{
		/* start timer to query device state */
		GPTI_StartItem(g_UsbHostMs.gpt_handle, USB_HOST_MS_QUERY_PERIOD,
					USB_Host_Ms_State_Timeout, &g_UsbHostMs);
	}	

}

/* ms class main state machine of each LUN */
/* Note that this is called periodically when ms is active */
void USB_Host_Ms_State_Main(void)
{
	kal_uint8 index;
	kal_bool result;
	kal_bool b_send_msg = KAL_FALSE;

	result = USB_Host_Ms_Check_All_Media();	
	/* If result is fail, ms has been detached*/
		
	if( (result==KAL_TRUE) && (g_UsbHostMs.media_state_change != 0) 
		&& (g_UsbHostMs.b_sending_change_ilm == KAL_FALSE))
	{
		/* Send message to FMT task about card state change */
		for(index=0; index<g_UsbHostMs.total_lun; index++)
		{
			if((g_UsbHostMs.media_state_change&(1<<index))!=0)
			{
				if(g_UsbHostMs.media_info[index].state != g_UsbHostMs.media_info[index].pre_state)
				{
					g_UsbHostMs.media_info[index].pre_state = g_UsbHostMs.media_info[index].state;
					g_UsbHostMs.media_msg_array[index] = (kal_uint32)&g_UsbHostMs.media_handle[index];
					b_send_msg = KAL_TRUE;
				}
				else
				{
					g_UsbHostMs.media_msg_array[index] = NULL;
				}
			}
			else
			{
				g_UsbHostMs.media_msg_array[index] = NULL;
			}
		}
		g_UsbHostMs.media_state_change = 0;
		if(b_send_msg == KAL_TRUE)
		{
			USB_Host_Ms_SendInd(USB_HOST_MS_MSG_MEDIA_CHANGE);
		}
	}

	if(result==KAL_TRUE)
	{
		/* start timer to start query device state */
		GPTI_StartItem(g_UsbHostMs.gpt_handle, USB_HOST_MS_QUERY_PERIOD,
					USB_Host_Ms_State_Timeout, &g_UsbHostMs);
	}	
}

#endif  /* __OTG_ENABLE__ */
 
