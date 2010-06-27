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
/*******************************************************************************
 *
 * Filename:
 * ---------
 *	dt_msg_hdlr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for handler of messages from L4C and UART.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
*****************************************************************************/

#define DT_MSG_HDLR_C



#include <stdio.h>
#include <string.h>
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "app_buff_alloc.h"
#include "stack_timer.h"
#include "event_shed.h"
#include "stack_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "tst_buff_pool.h"
#include "sysconf_statistics.h"

#include "dt_common_enum.h"
#include "uart_sw.h"
#include "dt_context.h"
#include "l4c2dt_struct.h"

#include "dt_utility.h"

#include "dt_rspfmttr.h"
#include "dt_trc.h"
#include "device.h"

#include "dt_aux_msg_hdlr.h"

void l4cdt_download_req_hdlr (local_para_struct  *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr)
{	
	l4cdt_download_req_struct * dt_download_req_ptr;
       kal_bool   ret_val;

	dt_download_req_ptr = (l4cdt_download_req_struct*)local_para_ptr;

	DT_UART_SetOwner(dt_download_req_ptr->port, MOD_DT);

	DT_PTR->transfer_type = dt_download_req_ptr->transfer_type;
	DT_PTR->app_type = dt_download_req_ptr->app_type;	
	DT_PTR->transfered_port = dt_download_req_ptr->port;
	DT_PTR->transfer_state = DT_DOWNLOAD_STATE;	
	DT_PTR->download_filename = dt_download_req_ptr->filename;
	
//#ifdef FMT_NOT_PRESENT 								
//		ret_val = dt_eq_fs_access_req(dt_download_req_ptr->src_id, DT_FS_READ, dt_download_req_ptr->app_type, 
//									(kal_wchar *)dt_download_req_ptr->filename, NULL,0);
//#else
	ret_val = dt_eq_general_fs_access_req(DT_FS_READ, dt_download_req_ptr->app_type, 
											(kal_wchar *)dt_download_req_ptr->filename, NULL,0);
	if(ret_val == KAL_FALSE)
	{

		//if (dt_download_req_ptr->filename!= NULL)
		if (DT_PTR->download_filename!= NULL)
		{
			free_ctrl_buffer(DT_PTR->download_filename);//filename is allocated in l4c and free here
			DT_PTR->download_filename = NULL;
		}
		
		dt_send_l4c_download_cnf(DT_PTR->cmee_err);
		dt_reset_state(); //reset DT context
		
	}
	//else
	//{
	//	if(DT_PTR->printingDownloadData_flag == KAL_FALSE)
	//	{
	//		if (dt_download_req_ptr->filename!= NULL)
	//		{
	//			free_ctrl_buffer(dt_download_req_ptr->filename);//allocate in l4c and free here
	//		}
	//	}
	//}	
//#endif
	return; 

}

void l4cdt_upload_req_hdlr (local_para_struct  *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr)
{
	l4cdt_upload_req_struct * dt_upload_req_ptr;
	kal_bool   ret_val;
	
	dt_upload_req_ptr = (l4cdt_upload_req_struct*)local_para_ptr;	

	DT_UART_SetOwner(dt_upload_req_ptr->port, MOD_DT);

	DT_PTR->transfer_type = dt_upload_req_ptr->transfer_type;
	DT_PTR->app_type = dt_upload_req_ptr->app_type;
	DT_PTR->transfered_port = dt_upload_req_ptr->port;
	DT_PTR->transfer_state = DT_UPLOAD_STATE;

	ret_val = dt_eq_general_fs_access_req(DT_FS_OPEN, dt_upload_req_ptr->app_type, 
											(kal_wchar *)dt_upload_req_ptr->filename, NULL, 0);

	if(ret_val == KAL_TRUE)//open success
	{
		dt_result_code_fmttr (DT_RCODE_OK, DT_NO_ERR);
	}
	else//open fail
	{
		dt_send_l4c_upload_cnf(DT_PTR->cmee_err);
		dt_reset_state();
	}

	if(dt_upload_req_ptr->filename != NULL)
	{
		free_ctrl_buffer(dt_upload_req_ptr->filename);
	}
	//ready to receiving +EFSW, +EMDY, or +EIMG form uart port
}

void l4cdt_filelist_req_hdlr (local_para_struct  *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr)
{
	l4cdt_filelist_req_struct * dt_filelist_req_ptr;
       kal_bool   ret_val;

	dt_filelist_req_ptr = (l4cdt_filelist_req_struct*)local_para_ptr;

	DT_UART_SetOwner(dt_filelist_req_ptr->port, MOD_DT);
	DT_PTR->transfered_port = dt_filelist_req_ptr->port;
	DT_PTR->transfer_state = DT_FILELIST_STATE;

	ret_val = dt_eq_fs_filelist_req(dt_filelist_req_ptr->src_id , (kal_wchar *)dt_filelist_req_ptr->foldername);

	if(ret_val == KAL_FALSE)
	{
		dt_send_l4c_filelist_cnf(DT_PTR->cmee_err);
		dt_reset_state();
	}
	
	if(dt_filelist_req_ptr->foldername != NULL)
	{
		free_ctrl_buffer(dt_filelist_req_ptr->foldername);
	}
}

void l4cdt_uart_transfer_req_hdlr (local_para_struct  *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr)
{
	l4cdt_uart_transfer_req_struct * dt_uart_transfer_req_ptr;
	dt_uart_transfer_req_ptr = (l4cdt_uart_transfer_req_struct*)local_para_ptr;
	
	DT_PTR->transfered_port = dt_uart_transfer_req_ptr->port;
	DT_UART_SetOwner(dt_uart_transfer_req_ptr->port, MOD_DT);
}

void dt_uart_ready_to_read_ind_hdlr (local_para_struct  *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr)
{
//	if (local_para_ptr == NULL)
//	{
//		/* the old version, port information was not in the message */
//   		rmmi_read_from_uart(PS_UART_PORT);
//	}
//	else
//	{
		uart_ready_to_read_ind_struct* msg_ptr = NULL;
		msg_ptr = (uart_ready_to_read_ind_struct*)local_para_ptr;

		kal_trace(TRACE_FUNC, FUNC_DT_UART_RTR_IND_HDLR_ENTRY);

   		dt_read_from_uart((kal_uint8)msg_ptr->port);
//	}
   	return;
}

void dt_uart_ready_to_write_ind_hdlr (local_para_struct  *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr)
{
   kal_uint16 actual_write;
   kal_uint16 length;
   UART_PORT	port ;
   uart_ready_to_write_ind_struct* msg_ptr = NULL;
   msg_ptr = (uart_ready_to_write_ind_struct*)local_para_ptr;
   port = msg_ptr->port;

   kal_trace(TRACE_FUNC, FUNC_DT_UART_RTW_IND_HDLR_ENTRY);

   //RMMI_PTR->uart_stop_send_flag &= ~(0x01 << cid );
   DT_PTR->uart_stop_send_flag = KAL_FALSE;

   if (DT_PTR->uart_output_queue.length == 0)
   {
      return;
   }
   else
   {
   	/*
      while (RMMI_PTR->uart_output_queue[cid].length > MAX_UART_LENGTH)
      {
         actual_write = rmmi_uart_send_data (port);

         if (actual_write < MAX_UART_LENGTH)
         {
            RMMI_PTR->uart_stop_send_flag |= (0x01 << cid);
            return;
         }
      }
      */

      length = DT_PTR->uart_output_queue.length;
      actual_write = dt_uart_send_data ((kal_uint8)port);

      if (actual_write < length)
      {
            //DT_PTR->uart_stop_send_flag |= (0x01 << cid);
            DT_PTR->uart_stop_send_flag = KAL_TRUE;

      }
      else
      {
//#ifdef DATA_DOWNLOAD
	      /* add by mtk00714 : for PC suite data download */
	      if(DT_PTR->printingDownloadData_flag == KAL_TRUE)
	      {
	      		if(DT_PTR->fd[0] != 0)
	      		{
				dt_eq_fs_read_req();
				return;
	      		}
	      }
	      else if (DT_PTR->fd[1]!= 0)
      		{
      			dt_eq_fs_efsl_next();
			return;	
      		}

	      if(DT_PTR->download_complete == KAL_TRUE)
	      {/*mtk00924_060416: send download_cnf when put all data form dt_output_queue to UART buffer*/
			dt_send_l4c_download_cnf(DT_NO_ERR);
			dt_reset_state();
			DT_PTR->download_complete = KAL_FALSE;
	      }
      	}

      /* add by mtk00714 */
//#endif
      return;
   }
}

//#ifdef __USB_ENABLE__
void dt_usb_plugout_ind_hdlr (local_para_struct  *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr)
{

		if(DT_PTR->transfer_state == DT_DOWNLOAD_STATE)
		{
	      		/* clear download pause timer */
			dt_clear_download_timer();	     

			if(DT_PTR->fd[0] !=0)
			{
			   	/* close the file handle and clear the stored infomation*/
				FS_Close(DT_PTR->fd[0]);
				DT_PTR->fd[0] = 0;
				DT_PTR->data_folder=0;
				DT_PTR->printingDownloadData_flag = KAL_FALSE;
				DT_PTR->printingDownloadData_loopCount = 0;							
			 }
			 DT_PTR->uart_stop_send_flag = KAL_FALSE;//If not reset to FALSE, the next download will stop because of this flag 

			 //clear DT uart output queue, or next download will print redundant data
			 DT_PTR->uart_output_queue.head = 0;
     		 	 DT_PTR->uart_output_queue.length = 0;	

			if (DT_PTR->download_filename!= NULL)
			{
				free_ctrl_buffer(DT_PTR->download_filename);//filename is allocated in l4c and free here
				DT_PTR->download_filename = NULL;
			}
		
			 dt_send_l4c_download_cnf(DT_ERR_USB_PLUGOUT);
			 dt_reset_state();
		}
		else if (DT_PTR->transfer_state == DT_UPLOAD_STATE)
		{
			 dt_send_l4c_upload_cnf(DT_ERR_USB_PLUGOUT);	
			 dt_reset_state();
		}
		else if (DT_PTR->transfer_state == DT_FILELIST_STATE)
		{
			//mtk01616_071003
			if(DT_PTR->fd[1] !=0)
			{
				FS_Close(DT_PTR->fd[1]);
				DT_PTR->fd[1] = 0;
			}
			
			DT_PTR->uart_stop_send_flag = KAL_FALSE;//If not reset to FALSE, the next download will stop because of this flag 

			//clear DT uart output queue, or next download will print redundant data
			DT_PTR->uart_output_queue.head = 0;
     		 	DT_PTR->uart_output_queue.length = 0;	
				 
			dt_send_l4c_filelist_cnf(DT_ERR_USB_PLUGOUT);	
			dt_reset_state();
		}
		else
		{
			kal_trace(TRACE_INFO, INFO_DT_CURRENT_STATE, DT_PTR->transfer_state);
		}
		return;			 	
}
//#endif /*__USB_ENABLE__*/

/*************************************************************************
* FUNCTION                                                            
*	cc_timer_expiry_hdlr
* DESCRIPTION                                                           
*
*  This is used to handle stack timer expiry and call each timer expiry
*  handler associated with each time-out event
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void dt_timer_expiry_hdlr(ilm_struct *ilm_ptr) 
{

   if(stack_is_time_out_valid(&DT_PTR->base_timer)) 
   {	
      evshed_timer_handler(DT_PTR->event_scheduler_ptr);    
   }

   stack_process_time_out(&DT_PTR->base_timer);

   return;

}	/* End of cc_timer_expiry_hdlr */


