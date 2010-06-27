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
 *	dt_utility.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ....
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
*****************************************************************************/

#define DT_UTILITY_C

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

#include "divider_public.h"

#include "dt_trc.h"

#include "uart_sw.h"
#include "dt_common_enum.h"
#include "dt_context.h"

#include "dt_utility.h"
#include "dt_rspfmttr.h"
#include "dt_aux_msg_hdlr.h"

extern  kal_wchar *l4c_get_download_path(void);
extern void l4c_set_download_path(kal_wchar *downlaod_path);

extern kal_wchar* custom_get_at_audio_download_folder(void);
extern kal_wchar* custom_get_at_image_download_folder(void);

kal_bool dt_eq_fs_read_req(void)
{
#if !(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))
#ifdef __FS_ON__
	  	kal_uint8 eof_flag=0;
		kal_uint8 * download_ptr;
		kal_uint32 rlen;
		kal_int32 ret_v=0;
		kal_uint16 i;
		kal_uint8 j=0;

      		kal_trace(TRACE_FUNC, FUNC_DT_FS_READ_ENTRY);
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
#endif
		download_ptr = get_ctrl_buffer(DT_DOWNLOAD_SIZE);//cage_read

     	        dt_clear_download_timer();

		for (i = 0; i< 100; i++)//cage_read
		//while(eof_flag==0)
		{
			DT_PTR->printingDownloadData_loopCount ++;
			ret_v = FS_Read(DT_PTR->fd[0], (kal_uint8 *)download_ptr, DT_DOWNLOAD_SIZE, &rlen);//cage_read
			if( ret_v != FS_NO_ERROR )	//Error occurs!!
			{
				ret_v = FS_Close(DT_PTR->fd[0]);
      				kal_trace (TRACE_GROUP_4, DT_FS_ACCESS, DT_FS_CLOSE, ret_v);
						
				/* clear the stored infomation */
			  	DT_PTR->fd[0] = 0;
			  	DT_PTR->data_folder= 0;
				DT_PTR->printingDownloadData_flag = KAL_FALSE;
				DT_PTR->printingDownloadData_loopCount = 0;
				if(download_ptr!=NULL)  free_ctrl_buffer(download_ptr);

				DT_PTR->cmee_err = DT_ERR_READ_FILE_FAILURE;

				return KAL_FALSE;
			}
					
			if( rlen<DT_DOWNLOAD_SIZE ) //cage_read
			{
				j++;
				eof_flag=1; //EOF
			}
			/* read file and print it out */
		  	dt_eq_fs_read_rrsp( download_ptr, 				
		  						DT_PTR->data_folder, 
		  						rlen, 
		  						eof_flag, 
		  						DT_PTR->printingDownloadData_loopCount );

			if(DT_PTR->abort_download == KAL_TRUE)
			{/*mtk00924_060320: user abort file download during wait for uart rtw_ind, 
			     so after finishing the last run of +EFSR, senfing download_cnf to L4C*/
			   	if(DT_PTR->fd[0] !=0)
			   	{
			   		/* close the file handle and clear the stored infomation*/
					FS_Close(DT_PTR->fd[0]);
					DT_PTR->fd[0] = 0;
					DT_PTR->data_folder= 0;
					DT_PTR->printingDownloadData_flag = KAL_FALSE;
					DT_PTR->printingDownloadData_loopCount = 0;							
			   	}
			
				if (DT_PTR->download_filename!= NULL)
				{
					free_ctrl_buffer(DT_PTR->download_filename);//filename is allocated in l4c and free here
					DT_PTR->download_filename = NULL;
				}
				
				dt_send_l4c_download_cnf(DT_ERR_USER_ABORT);	
				dt_reset_state();			
				DT_PTR->abort_download = KAL_FALSE;

				return KAL_TRUE;
			}
		
		  	if(eof_flag==1) // reach End of File, we can close filehandler  and clear stored info 
		  	{
				ret_v = FS_Close(DT_PTR->fd[0]);
				kal_trace (TRACE_GROUP_4, DT_FS_ACCESS, DT_FS_CLOSE, ret_v);

				/* clear the stored infomation */
				DT_PTR->fd[0] = 0;
				DT_PTR->data_folder= 0;
				DT_PTR->printingDownloadData_flag = KAL_FALSE;
				DT_PTR->printingDownloadData_loopCount = 0;
				
				if(download_ptr!=NULL)  free_ctrl_buffer(download_ptr);

				if (DT_PTR->download_filename!= NULL)
				{
					free_ctrl_buffer(DT_PTR->download_filename);//filename is allocated in l4c and free here
					DT_PTR->download_filename = NULL;
				}
			
				if(DT_PTR->uart_stop_send_flag == KAL_FALSE)
				{
				dt_send_l4c_download_cnf(DT_NO_ERR);
				dt_reset_state();
				}
				else
				{/*mtk00924_060416: if UART is full, do not send download_cnf but set download_complete as TRUE, 
				     and have to wait for ready_to_write_ind from UART to put all data to UART buffer and then send download_cnf*/
					kal_trace(TRACE_WARNING, WARNING_DT_DOWNLOAD_COMPLETE_WHEN_UART_FULL);
					DT_PTR->download_complete = KAL_TRUE;
				}
				return KAL_TRUE;
				
		  	}
		  	else // if(eof_flag=0)
		  	{
		  		/* check if UART is busy or not, if busy, set printingDownloadData_flag = TRUE, 
		  		and wait till UART ReadyToWrite Indication(rmmi_uart_rtw_ind_hdlr) */
				//if(DT_PTR->uart_stop_send_flag & (0x01 << 0))
				if(DT_PTR->uart_stop_send_flag == KAL_TRUE)
				{	 
					DT_PTR->printingDownloadData_flag = KAL_TRUE;
					
					if(download_ptr!=NULL)  free_ctrl_buffer(download_ptr);

					return KAL_TRUE;
				}
		  	}					
		}

		/* the file is not finished yet, but we stop for a while, so L4 task can process its external queue first.
		    use timer to trigger the resuming action */
		DT_PTR->printingDownloadData_flag = KAL_TRUE;
		//l4c_pause_download(); //Maui_sw 9922, 20050221 mark: do not use timer,
                                        //instead, resume download in layer4_task_main()

		DT_PTR->event_id[1] = evshed_set_event (DT_PTR->event_scheduler_ptr,
					      (kal_timer_func_ptr)dt_resume_download,
					            NULL, DT_DOWNLOAD_SLEEP_TIMER * KAL_TICKS_100_MSEC);
		
		if(download_ptr!=NULL)  free_ctrl_buffer(download_ptr);
			return KAL_TRUE;
#endif/*__FS_ON__*/		
#endif/*(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))*/
}



//#ifdef DATA_DOWNLOAD

/*****************************************************************************
* FUNCTION
*  dt_eq_general_fs_access_req
*
* DESCRIPTION
*   directly access file system.
* 	 for +EIMG,+EMDY: WHEN "FILE MANAGER" is enabled in MMI
*   for +EFSR, +EFSW, +EFSD.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
kal_bool dt_eq_general_fs_access_req(
                                 dt_fs_opcode_enum action,
                                 dt_app_type_enum app_type,
                                 kal_wchar *file_name,
                                 kal_uint8 *data,
                                 kal_uint16 data_len)
{
#if !(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))
#ifdef __FS_ON__
   	FS_HANDLE file_handle;
   	kal_wchar full_name[(FS_MAX_PATH)];

	kal_int8 ret_drv;
	kal_uint8 buf[30];
	kal_wchar UCS2_buf[30];
	kal_int32 ret_v;
	kal_uint16 file_path_len;

	kal_wchar *custom_audio_floder_name, *custom_image_floder_name;

	custom_audio_floder_name = custom_get_at_audio_download_folder();
	custom_image_floder_name = custom_get_at_image_download_folder();
   	
kal_trace(TRACE_FUNC, FUNC_DT_EQ_GENERAL_FS_ACCESS_REQ_ENTRY);

   	//if(src_id != RMMI_SRC)
   	//{
   	//	RMMI_PTR->cmee_err = RMMI_ERR_UNKNOWN;
   	//	return KAL_FALSE;
   	//}

	if(file_name!=NULL)
	{	
		switch(app_type)
		{
			case DT_APP_UNKNOWN: 
			/*+EFSR,+EFSW, +EFSD: PC suite give full-path*/
			{
				/* append file_name to the previous set current dir if any*/
				dt_get_downloadFullpath((kal_wchar *)file_name);

				file_path_len = kal_wstrlen((WCHAR*)file_name);

				kal_trace(TRACE_INFO,INFO_DT_U, file_path_len);
				
				if(file_path_len > (FS_MAX_PATH/2))
				{	
					DT_PTR->cmee_err = DT_ERR_FILE_PATH_EXCEEDED;
					return KAL_FALSE;
				}
				else
					kal_wsprintf((WCHAR*)full_name, "%w", (kal_wchar *)file_name);

				break;
			}
			default: 
			/* +EIMG, +EMDY: PC suite only give filename, we need to store it to default folder */
			{
				FS_DOSDirEntry fileinfo;
			   	kal_wchar filename[30];

				/* get default Drive */
				ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_ONLY_ALT_SERIAL);
				if(!((ret_drv>='A')&&(ret_drv<='Z')))
				{
					ret_drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
					if(!((ret_drv>='A')&&(ret_drv<='Z'))) 
					{	
   						DT_PTR->cmee_err = DT_ERR_GET_DRIVE_FAILURE;
				  		return KAL_FALSE;
					}
				}

				if(action==DT_FS_OPEN) //OPEN might need to create default folder.
				{
					/*
					// check if folder \USER exists, if not create it 
					kal_sprintf((char*)buf, "%c:\\USER", ret_drv);
					ascii_to_ucs2( buf, UCS2_buf );
		   			file_handle = FS_FindFirst(UCS2_buf, FS_ATTR_DIR, 0, &fileinfo, filename, 30);
		   			if(file_handle<0)
		   			{	FS_CreateDir(UCS2_buf); }						
					FS_FindClose(file_handle);
					*/
						
					/* set default folder */
			  		if(app_type==DT_IMELODY||app_type==DT_SOUND_OTHER)
					{	
                                         kal_sprintf((char*)buf, "%c:\\", ret_drv); 
					      dt_ascii_to_ucs2( buf, UCS2_buf );					
					      kal_wstrcat(UCS2_buf, custom_audio_floder_name);
                                   }
					else 
					{
	                                 kal_sprintf((char*)buf, "%c:\\", ret_drv); 
					     dt_ascii_to_ucs2( buf, UCS2_buf );					
					     kal_wstrcat(UCS2_buf, custom_image_floder_name);
                                   }					
					 //dt_ascii_to_ucs2( buf, UCS2_buf );
						
					/* check if default folder \xxx exists, if not create it */
		   			file_handle = FS_FindFirst(UCS2_buf, FS_ATTR_DIR, 0, &fileinfo, filename, 30);
		   			if(file_handle<0)
					{	FS_CreateDir(UCS2_buf); 	}
					FS_FindClose(file_handle);
				}
				else
				{	   			
					/* set default folder */
			  		if(app_type==DT_IMELODY||app_type==DT_SOUND_OTHER)
					{
	                                 kal_sprintf((char*)buf, "%c:\\", ret_drv); 
					     dt_ascii_to_ucs2( buf, UCS2_buf );					
					     kal_wstrcat(UCS2_buf, custom_audio_floder_name);					
                                   }
					else 
					{
	                                 kal_sprintf((char*)buf, "%c:\\", ret_drv); 
					     dt_ascii_to_ucs2( buf, UCS2_buf );					
					     kal_wstrcat(UCS2_buf, custom_image_floder_name);					
                                   }					
					//dt_ascii_to_ucs2( buf, UCS2_buf );
				}
				/* combine foldername & file_name to "full_name" */
				kal_wsprintf((WCHAR*)full_name, "%w\\%w", UCS2_buf, (kal_wchar *)file_name);
				break;
		  	}
		  }
	  }

     	  switch(action)
	  {
	  	/****************OPEN FILE *****************/
	  	case DT_FS_OPEN:
		{
			/* check if RMMI already still hold a open file*/
		  	if(DT_PTR->fd[0]!= 0)
		  	{
   				DT_PTR->cmee_err = DT_ERR_OPERATION_NOT_ALLOWED_ERR;
		  		return KAL_FALSE;
		  	}

		  	/* check if the file exist: we only allow to open a new file */
     	   		file_handle = FS_Open(full_name, FS_OPEN_DIR | FS_READ_ONLY );
     	   		if (file_handle >0)
     	   		{
			  	FS_Close(file_handle);
   				DT_PTR->cmee_err = DT_ERR_OPERATION_NOT_ALLOWED_ERR;
		     	   	return KAL_FALSE;
     			}
		 	FS_Close(file_handle);

     	   		/* create a file */
		  	file_handle = FS_Open(full_name, FS_CREATE|FS_READ_WRITE);
			if (file_handle < 0)
			{		 		
				kal_trace (TRACE_GROUP_4, DT_FS_ACCESS, DT_FS_OPEN, file_handle);
				DT_PTR->cmee_err = DT_ERR_UNSPECIFIED;		 		
	  			return KAL_FALSE;
			}
			else
			{
				/* open successully, store the file_handle, filename, 
					and folder for furthur write and close */
				DT_PTR->fd[0] = file_handle;
				DT_PTR->data_folder = app_type;
				
				DT_PTR->downloadFilename = (kal_wchar*)get_ctrl_buffer(FS_MAX_PATH);
				kal_mem_cpy(DT_PTR->downloadFilename, full_name, FS_MAX_PATH);
				
				//start the guard time
				dt_start_data_download_timer_hdlr();
			}
			break;
		}
		/****************CLOSE FILE *****************/
		case DT_FS_CLOSE:
		{
		  	/* check if the stored file_handle valid */
			if ((DT_PTR->fd[0] <0 ) ||(DT_PTR->fd[0] == 0))
			{
		  		kal_trace(TRACE_GROUP_4, DT_CLOSE_FILE_FAIL);
   				DT_PTR->cmee_err = DT_ERR_UNKNOWN;		 		
		  		return KAL_FALSE;
			}
			else
			{
				/* clear data download timer*/
				dt_clear_download_timer();

				/* close the file */
				file_handle = DT_PTR->fd[0];
				ret_v = FS_Close(file_handle);
				kal_trace (TRACE_GROUP_4, DT_FS_ACCESS, DT_FS_CLOSE, ret_v);
				
				/* clear the stored infomation */
			  	DT_PTR->fd[0] = 0;
			  	DT_PTR->data_folder= 0;
				if(DT_PTR->downloadFilename!=NULL)
				{
					free_ctrl_buffer(DT_PTR->downloadFilename);
					DT_PTR->downloadFilename = NULL;
				}
				//mtk00924_051021: send OK from L4C				
				/* sent "OK" to DTE after close the file */
      				//dt_result_code_fmttr (DT_RCODE_OK, DT_NO_ERR);
			}
		  	break;
	  	}
		/****************READ*****************/
		case DT_FS_READ:
		{
			kal_bool ret_val;
			file_handle = FS_Open(full_name, FS_READ_ONLY|FS_OPEN_NO_DIR);

			if (file_handle < 0)
			{
				kal_trace (TRACE_GROUP_4, DT_FS_ACCESS, DT_FS_OPEN, file_handle);
				DT_PTR->cmee_err = DT_ERR_OPEN_FILE_FAILURE;													   
				return KAL_FALSE;
			}
			else
			{
				/* store infomation for FS_READ*/
				DT_PTR->fd[0] = file_handle;
				
				DT_PTR->data_folder = app_type;
				DT_PTR->printingDownloadData_loopCount = 0;
				/* read data from file and print to PC*/
				ret_val=(kal_bool)dt_eq_fs_read_req();
				return ret_val;
			}
			break;
		  }
		 /****************WRITE*****************/
		 case DT_FS_WRITE:
		 {
			kal_uint32 len;
		 	/* check if the stored file_handle valid */
			if ((DT_PTR->fd[0] <0 ) ||(DT_PTR->fd[0] == 0))
			{
   				DT_PTR->cmee_err = DT_ERR_UNKNOWN;		 		
		 		return KAL_FALSE;
			}
			else
			{
				file_handle = DT_PTR->fd[0];
				dt_start_data_download_timer_hdlr();
			  	ret_v = FS_Write(file_handle,(kal_uint8 *)data,data_len,&len );
			  	if((data_len != len) || (ret_v != FS_NO_ERROR))
			  	{
			  		kal_trace (TRACE_GROUP_4, DT_FS_ACCESS, DT_FS_WRITE, ret_v);
				  	dt_data_download_error_hdlr();
   					DT_PTR->cmee_err = DT_ERR_UNSPECIFIED;		 		
					kal_print("Write FILE Fail!");
					return KAL_FALSE;
			  	}
			}
			break;
		  }
		/***************DELETE******************/
		  case DT_FS_DELETE:
	  	  {
			/* delete file directly from File System */	  	  	
			ret_v = FS_Delete(full_name);
			kal_trace (TRACE_GROUP_4, DT_FS_ACCESS, DT_FS_DELETE, ret_v);
			
			if(ret_v == FS_NO_ERROR) 
			{
      				dt_result_code_fmttr (DT_RCODE_OK, DT_NO_ERR);
				return KAL_TRUE;
			}
			else 
			{
      				dt_result_code_fmttr (DT_RCODE_ERROR, DT_ERR_UNSPECIFIED);			
				return KAL_FALSE;
			}
	 	  	break;
		  }
		/***************LIST FILEs in FOLDER ******************/
		  case DT_FS_DIR:
		  {
			FS_DOSDirEntry fileinfo;			
		   	kal_wchar *filename = NULL;			
			kal_uint8 *outputfile;
		      	kal_uint8 buffer[DT_MAX_DATA_OUTPUT_QUEUE_LENGTH];
		      	kal_uint16 string_length;
   			kal_uint16 sub_length;
		      	kal_uint8 i;
		      
			ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_ONLY_ALT_SERIAL);
			if(!((ret_drv>='A')&&(ret_drv<='Z'))) 
			{
				ret_drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
				if(!((ret_drv>='A')&&(ret_drv<='Z'))) 
				{	
   					DT_PTR->cmee_err = DT_ERR_UNSPECIFIED;		 		
					return KAL_FALSE;
				}
			}
			switch(app_type)
			{
				case DT_IMAGE:
					kal_sprintf((char*)buf, "%c:\\Images\\?*.*", ret_drv);
           				break;
				case DT_IMELODY:
					kal_sprintf((char*)buf, "%c:\\Audio\\?*.imy", ret_drv);
	        			break;
				case DT_SOUND_OTHER:
					kal_sprintf((char*)buf, "%c:\\Audio\\?*.mid", ret_drv);
	        			break;
				default:
   					DT_PTR->cmee_err = DT_ERR_UNKNOWN;		 		
					return KAL_FALSE;
			}
			dt_ascii_to_ucs2( buf, UCS2_buf );

	 		filename = (kal_wchar*)get_ctrl_buffer(FS_MAX_PATH);
			file_handle = FS_FindFirst(UCS2_buf, 0, 0, &fileinfo, filename, FS_MAX_PATH);  	
			if(file_handle>=0)
			{				
				outputfile= get_ctrl_buffer(FS_MAX_PATH*2+1);
				ret_v = FS_NO_ERROR;
	   			while(ret_v==FS_NO_ERROR)
	   			{
	   				/* If it's not a Directory and not Hidden */
	   				if( (fileinfo.Attributes & (FS_ATTR_DIR|FS_ATTR_HIDDEN))==0)
					{	
		   				/* +EIMG, +EMDY print reverse UCS2 to PC suite: "41004200..." */
						dt_print_hex_value((kal_uint8*)filename, outputfile);

#if 1
				 		/* Begin :
				 		this part of codes is to seperate the output filename (might be upto 1040 bytes) 
					 	so it can fit to RMMI's output queue */
					  	switch(app_type)
					  	{
							case DT_IMAGE:
	 	            					kal_sprintf((char *)buffer, "%c%c+EIMG: \"", DT_PTR->s_reg.s3, DT_PTR->s_reg.s4);
	 	            					break;
							case DT_IMELODY:
							case DT_SOUND_OTHER:
	 	            					kal_sprintf((char *)buffer, "%c%c+EMDY: \"", DT_PTR->s_reg.s3, DT_PTR->s_reg.s4);
	 	            					break;
						}
		          	 		dt_write_to_uart((kal_uint8 *)buffer, (kal_uint16)strlen ((char *)buffer), KAL_FALSE);
		                 		i=0;
		       	         	string_length = strlen((char*)outputfile);
				   		 while((string_length-i*500)>0) //the output of filename is not finished 
				   		 {
				   		 	/* determine "sub_length" which the length of sub string each time we print out. */
				   		 	if((string_length-i*500)>=500)
				   		 		sub_length = 500;	//max sub length
				   		 	else
				   		 		sub_length = string_length-i*500;
				   		 	
				   		 	kal_mem_cpy(buffer, outputfile+i*500, sub_length);
							buffer[sub_length]='\0';
					         	dt_write_to_uart((kal_uint8 *)buffer, sub_length, KAL_FALSE);	         	 
							i++;
				   		 }
			         	 	 kal_sprintf((char *)buffer, "00\"%c%c", DT_PTR->s_reg.s3, DT_PTR->s_reg.s4);
				          	 dt_write_to_uart((kal_uint8 *)buffer, (kal_uint16)strlen ((char *)buffer), KAL_FALSE);
						/* End */
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
#endif
					}							   				
   					ret_v = FS_FindNext(file_handle, &fileinfo, filename, FS_MAX_PATH);   					
   					
	   			}
	   			if(outputfile!=NULL)	
	   				free_ctrl_buffer(outputfile);
			}
			
	   		FS_FindClose(file_handle);
			if(filename!=NULL)	free_ctrl_buffer(filename);
      			dt_result_code_fmttr (DT_RCODE_OK, DT_NO_ERR);
			return KAL_TRUE;
		  	break;
		 }
		 default:	//unknown operation
   			DT_PTR->cmee_err = DT_ERR_UNKNOWN;		 		
		 	return KAL_FALSE;

   	}

#endif /* __FS_ON__*/
#endif /*(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))*/
   	return KAL_TRUE;
  
}
  
kal_bool dt_eq_fs_filelist_req(kal_uint8 src_id,
                                 kal_wchar *foldername)
{
#if !(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))
#ifdef __FS_ON__
       FS_DOSDirEntry fileinfo;
       kal_uint8 buffer[DT_SHORT_RSP_LEN];
       FS_HANDLE file_handle;
       kal_wchar *filename = NULL;
       kal_wchar *namepattern = NULL;
       kal_uint8 i;

	kal_trace(TRACE_FUNC, FUNC_DT_EQ_FS_FILELIST_REQ_ENTRY);
		
       /* append foldername to the previous set current dir if any*/
       dt_get_downloadFullpath((kal_wchar *)foldername);
	
       /* check if the foldername exist */
       filename = (kal_wchar*)get_ctrl_buffer(FS_MAX_PATH);
       file_handle = FS_FindFirst(foldername, 0, 0, &fileinfo, filename, FS_MAX_PATH);  	

       if(file_handle<0) //no such folder directory
	{	
		  	if(filename!=NULL)
				free_ctrl_buffer(filename);

			DT_PTR->cmee_err = DT_ERR_FOLDER_NOT_FOUND;
			return KAL_FALSE;
	}
	FS_FindClose(file_handle);

	/* folder directory exists: find and list files in the folder */
	namepattern = (kal_wchar*)get_ctrl_buffer(FS_MAX_PATH);
	kal_wsprintf((WCHAR*)namepattern, "%w%w", foldername, L"\\*.*");
#ifdef __RMMI_DEBUG__		
	kal_print("RMMI: FindFirst");
#endif

	file_handle = FS_FindFirst(namepattern, 0, 0, &fileinfo, filename, FS_MAX_PATH);

	if(namepattern!=NULL)
		free_ctrl_buffer(namepattern);

  	if(file_handle <0)
  	{
  			/* no file is found */
#ifdef __RMMI_DEBUG__		
		kal_print("RMMI: FindClose");
#endif
		FS_FindClose(file_handle);
  		if(filename!=NULL)	free_ctrl_buffer(filename);
       	////dt_result_code_fmttr (RMMI_RCODE_OK, L4C_NO_CAUSE);
		kal_prompt_trace(MOD_DT,"dt_eq_fs_filelist_req: no file found in the folder");
       	dt_send_l4c_filelist_cnf(DT_NO_ERR);	
		dt_reset_state();
  	}
  	else
  	{  		
  		/* file is found, print +EFSL to PC */
		dt_eq_fs_efsl_list(filename, &fileinfo);

  		if(filename!=NULL)	free_ctrl_buffer(filename);

  		/* findNext : try to find next file*/
		DT_PTR->fd[1] = file_handle;
		dt_eq_fs_efsl_next();		   	
	}
	return KAL_TRUE;
#endif			  	
#endif
	return KAL_TRUE;
}

  
/*****************************************************************************
* FUNCTION
*  dt_eq_fs_efsl_list
*
* DESCRIPTION
*  to format the +EFSL result code and write to UART
*
*****************************************************************************/
void dt_eq_fs_efsl_list(kal_wchar* filename, FS_DOSDirEntry* fileinfo)
{
#if !(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))
	kal_uint8 *outputfile = NULL;
   	kal_uint8 buffer[DT_MAX_DATA_OUTPUT_QUEUE_LENGTH];
   	kal_uint16 string_length;
   	kal_uint16 i;
   	kal_uint16 sub_length;

	kal_trace(TRACE_FUNC, FUNC_DT_EQ_FS_EFSL_LIST_ENTRY);
		
   	outputfile= (kal_uint8*)get_ctrl_buffer(FS_MAX_PATH*2+1);

	switch(DT_PTR->char_set)
	{
		case DT_CHSET_IRA:
			dt_ucs2_to_ascii(filename, outputfile);
			break;
	   	case DT_CHSET_UCS2:
	 	default:
			dt_unicode_to_string((kal_uint8*)filename, outputfile);
	 		/*
			rmmi_byte_order_reverse((kal_uint8*)filename, FS_MAX_PATH);
			rmmi_print_ucs2( (kal_uint8*)filename, outputfile);
			*/
	}
		   		
	/* Following part of codes is to seperate the output filename (might be upto 1040 bytes) 
	 so it can fit to RMMI's output queue */
	kal_sprintf((char *)buffer, "%c%c+EFSL: \"",DT_PTR->s_reg.s3, DT_PTR->s_reg.s4);
	dt_write_to_uart((kal_uint8 *)buffer, (kal_uint16)strlen ((char *)buffer), KAL_FALSE);
	i=0;
	string_length = strlen((char*)outputfile);
	 while((string_length-i*500)>0) //the output of filename is not finished 
	 {
	 	/* determine "sub_length" which the length of sub string each time we print out. */
	 	if((string_length-i*500)>=500)
	 		sub_length = 500;	//max sub length
	 	else
	 		sub_length = string_length-i*500;
		   		 	
	 	kal_mem_cpy(buffer, outputfile+i*500, sub_length);
		buffer[sub_length]='\0';
	      	dt_write_to_uart((kal_uint8 *)buffer, sub_length, KAL_FALSE);	         	 
		i++;
	 }

	 kal_sprintf((char *)buffer, "\", %u, %d%c%c", fileinfo->FileSize, fileinfo->Attributes, DT_PTR->s_reg.s3, DT_PTR->s_reg.s4);
	 dt_write_to_uart((kal_uint8 *)buffer, (kal_uint16)strlen ((char *)buffer), KAL_FALSE);

	if(outputfile!=NULL)
		free_ctrl_buffer(outputfile);
#endif	
}

  
/*****************************************************************************
* FUNCTION
*  l4c_eq_fs_efsl_next
*
* DESCRIPTION
*  to search for the next file for +EFSL
*
*****************************************************************************/
void dt_eq_fs_efsl_next(void)
{
#if !(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))
   	kal_int32  ret_v;
   	kal_wchar *filename = NULL;
  	FS_DOSDirEntry fileinfo;
	filename = (kal_wchar*)get_ctrl_buffer(FS_MAX_PATH);

	kal_trace(TRACE_FUNC, FUNC_DT_EQ_FS_EFSL_NEXT_ENTRY);

	while(1)
	{
		 ret_v = FS_FindNext(DT_PTR->fd[1], &fileinfo, filename, FS_MAX_PATH);
		 if (ret_v != FS_NO_ERROR)
		 {

			FS_FindClose(DT_PTR->fd[1]);
			DT_PTR->fd[1] = 0;
        	////	dt_result_code_fmttr (DT_RCODE_OK, DT_NO_ERR);
        		kal_prompt_trace(MOD_DT,"dt_eq_fs_efsl_next: End Filelist");
			dt_send_l4c_filelist_cnf(DT_NO_ERR);
			dt_reset_state();
		 	break;
		 }

		 // print "+EFSL" to PC
      		kal_prompt_trace(MOD_DT,"dt_eq_fs_efsl_next: Continue Filelist");
		 dt_eq_fs_efsl_list(filename, &fileinfo);
		 // UART is busy, return first, continue after receive UART_READY_TO_WRITE_IND 
		//if(DT_PTR->uart_stop_send_flag & (0x01 << 0))
		if(DT_PTR->uart_stop_send_flag == KAL_TRUE)
			break;	
	}	
	
  	if(filename!=NULL)	free_ctrl_buffer(filename);
  	return;
#endif  	
}


//#endif /*DATA_DOWNLOAD*/

//#ifdef DATA_DOWNLOAD
//#if !(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))

//this function is using to guard the data download, when open file but no any resonse
void dt_start_data_download_timer_hdlr ()
{ 
	dt_clear_download_timer();
   	DT_PTR->event_id[1] = evshed_set_event (DT_PTR->event_scheduler_ptr,
					      (kal_timer_func_ptr)dt_data_download_error_hdlr,
					            NULL, DT_DOWNLOAD_ERROR_TIMER * KAL_TICKS_100_MSEC);
}


void dt_resume_download()
{ 
	dt_clear_download_timer();
	dt_eq_fs_read_req();
	return; 
}

void dt_data_download_error_hdlr ()
{
   
	FS_HANDLE file_handle;
//   	kal_wchar * full_name;
	kal_int32 ret_v;
   	/* clear download timer */
	dt_clear_download_timer();

   	/* mtk00714: L4C_PTR->downloadFullpath is set by +EFSF=2,<folder> */
   	/* we have to clear the stored information after timeout */
      	if(DT_PTR->downloadFullpath!=NULL)
	{
		/* clear stored L4C_PTR->downloadFullpath */
		free_ctrl_buffer(DT_PTR->downloadFullpath);
		DT_PTR->downloadFullpath=NULL;
		l4c_set_download_path(DT_PTR->downloadFullpath);
      	}
	//dt_clear_rename_path();
		/* check if the stored file_handle valid */
		if ((DT_PTR->fd[0] <0 ) ||(DT_PTR->fd[0] == 0))
			{
	     		return;
			}
	  	else
	  	{
			/* close the file */
			file_handle = DT_PTR->fd[0];
			ret_v = FS_Close(file_handle);
			kal_trace(TRACE_GROUP_4, DT_FS_ACCESS,DT_FS_CLOSE,ret_v);
//#ifndef FMT_NOT_PRESENT 				
			/* delete the file in FS */
			 if(DT_PTR->downloadFilename!=NULL)
			 {
				ret_v = FS_Delete((kal_wchar *)DT_PTR->downloadFilename);
				kal_trace(TRACE_GROUP_4, DT_FS_ACCESS,DT_FS_DELETE, ret_v);
			 	free_ctrl_buffer((kal_wchar *)DT_PTR->downloadFilename);
			 	DT_PTR->downloadFilename = NULL;
			 }
//#else //mtk00924_051021: No FMT presented, can be marked
//			/* delete the file in FS */
//			if(DT_PTR->data_folder==DT_APP_UNKNOWN)
//			{
//			  	if(DT_PTR->downloadFilename!=NULL)
//			  	{
//						FS_Delete((kal_wchar *)DT_PTR->downloadFilename);
//			  			free_ctrl_buffer((kal_wchar *)DT_PTR->downloadFilename);
//			  			DT_PTR->downloadFilename = NULL;
//			  	}
//			}
//			else
//			{
//				full_name = get_ctrl_buffer(50*sizeof(kal_wchar));
//	   		  	switch(DT_PTR->data_folder)
//			  	{
//					case L4C_IMELODY:
//						kal_wsprintf(full_name, "%w\\%w", DT_IMELODY_DIR, (kal_wchar *)DT_PTR->data_filename);
//						break;
//					case L4C_SOUND_OTHER:
//						kal_wsprintf(full_name, "%w\\%w", DT_SOUND_OTHER_DIR, (kal_wchar *)DT_PTR->data_filename);
//						break;	
//					case L4C_IMAGE:
//						kal_wsprintf(full_name, "%w\\%w", DT_IMAGE_DIR, (kal_wchar *)DT_PTR->data_filename);
//						break;
//			  	}
//				FS_Delete((kal_wchar *)full_name);
//				free_ctrl_buffer(full_name);
//				kal_mem_set((kal_wchar *)DT_PTR->data_filename, 0, sizeof(kal_wchar)*50);
//			}
//#endif
			
			/* clear the stored infomation */
			DT_PTR->fd[0] = 0;
			DT_PTR->data_folder= 0;
	   	}      
}


void dt_clear_download_timer()
{
   	if (DT_PTR->event_id[1] != 0)
   	{
		kal_trace (TRACE_INFO, INFO_DT_CLEAR_DOWNLOAD_TIMER, DT_PTR->event_id[1]);
      		evshed_cancel_event (DT_PTR->event_scheduler_ptr, &(DT_PTR->event_id[1]));
	      	DT_PTR->event_id[1] = 0;
   	}
}


/*****************************************************************************
* FUNCTION
*  	dt_get_downloadFullpath
* DESCRIPTION
*  	This function is to append the input filename to the stored path and return the full-path filename.
*  	the stored path is set by +EFSF=2, <folder>.  
*  	the function might be called by +EFSR, +EFSW, +EFSL, +EFSD
* PARAMETERS
* 	IN/OUT file_name
* RETURNS
* 	none
* GLOBALS AFFECTED
*   cancel timer and free L4C_PTR->downloadFullpath.
*****************************************************************************/
void dt_get_downloadFullpath(kal_wchar * file_name)
{
	kal_trace(TRACE_FUNC, FUNC_DT_GET_DOWNLOAD_FULLPATH_ENTRY);//mtk01616_071003

	ASSERT(file_name!=NULL);

	//mtk00924_051021: downloadFullpath in DT should get from L4C
	DT_PTR->downloadFullpath = l4c_get_download_path();	
	
	if(DT_PTR->downloadFullpath!=NULL)
	{
	       /* append foldername to the previous set current dir */
		kal_wstrcat(DT_PTR->downloadFullpath, file_name);
		kal_wstrcpy(file_name, DT_PTR->downloadFullpath);

		/* clear stored L4C_PTR->downloadFullpath and release buffer which is allocated in L4C when doing FS_DIR*/
		free_ctrl_buffer(DT_PTR->downloadFullpath);
		DT_PTR->downloadFullpath=NULL;
		l4c_set_download_path(DT_PTR->downloadFullpath);
		/* clear data download timer*/
		//dt_clear_download_timer();
	}
	else
	{
		kal_prompt_trace(MOD_DT, "download path is NULL");
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
#endif

//#endif /*(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))*/
//#endif /* DATA_DOWNLOAD */


/*****************************************************************************
* FUNCTION
*  dt_unicode_to_string()
*
* DESCRIPTION
*   check hex value
*   0x1234 => "1234"
*   0x6600 => "6600"
*
* PARAMETERS
*  val		IN		hex value.
*  str		OUT	string
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_unicode_to_string (kal_uint8 *val, kal_uint8 *str)
{
   kal_uint16 i=0, j=0;

   ASSERT ((str != NULL) && (val != NULL));

   while (!((val[j] == 0)&&(val[j+1] == 0)))
   {
      i += kal_sprintf((char *)str+i, "%02X%02X", val[j+1], val[j]);
      j+=2;
   }
   str[i] = '\0';
}


/*****************************************************************************
* FUNCTION
*  dt_ascii_to_ucs2()
*
* DESCRIPTION
*   this function is using to convert ascii code to ucs2 format
*
* PARAMETERS
*  src		IN		ascii string
*  dest		OUT	ucs2 value
* RETURNS
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_ascii_to_ucs2(kal_uint8* src, kal_wchar* dest)
{
    kal_uint8 index = 0;

 while(src[index] != DT_END_OF_STRING_CHAR)
 {
		 dest[index] = src[index];
    index++;
 }
   dest[index]=0 ;

return;

}


/*****************************************************************************
* FUNCTION
*  dt_ucs2_to_ascii()
*
* DESCRIPTION
*   this function is using to convert ucs2 code to ascii format
*	 If there's a non-convertable ucs2 char, such as chinese word,
*	 KAL_FALSE will be returned.
*	 Otherwise, KAL_TRUE will be returned if successful.
* PARAMETERS
*  src		IN		ucs2 wchar
*  dest		OUT	ascii string
* RETURNS
*	kal_bool
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
kal_bool dt_ucs2_to_ascii(kal_wchar* ucs2_src, kal_uint8* ascii_dest)
{
   kal_uint8 i= 0;

   while (!(ucs2_src[i] == 0)) //while not end of UCS2 string
   {
   	if((ucs2_src[i] >> 8) != 0) // the first byte is not 0x00, cannot convert to ASCII
   	{
   		ascii_dest[i] = '\0';
   		return KAL_FALSE;
   	}
   	else								//0x00YZ, so convert dest to
   	{
			ascii_dest[i]= (kal_uint8)ucs2_src[i] ;
   	}
   	i++;
	}
   ascii_dest[i] = '\0';
	return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
*  dt_print_hex_value()
*
* DESCRIPTION
*  This function print the hex value to ascii.
*  Note that UCS2 should use rmmi_print_ucs2(). not this function!!
*   check hex value
*   0x1234 => "1234"
*
* PARAMETERS
*  val		IN		hex value.
*  str		OUT	string
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_print_hex_value (kal_uint8 *val, kal_uint8 *str)
{
   kal_uint16 i=0, j=0;

   ASSERT ((str != NULL) && (val != NULL));

   while (!((val[j] == 0)&&(val[j+1] == 0)))
   {
      i += kal_sprintf((char *)str+i, "%02X", val[j]);
      j++;
   }
   str[i] = '\0';
}


void dt_toUpper (kal_uint8 *str)
{
   kal_uint8 *ptr;

   kal_trace(TRACE_FUNC, FUNC_DT_TOUPPER_ENTRY);
   ASSERT (str != NULL);
   ptr = str;
   while (*ptr != 0)
   {
      if (DT_IS_LOWER(*ptr))
      {
         *ptr += DT_CHAR_A-dt_char_a;
      }
      ptr++;
   }
}

/*****************************************************************************
* FUNCTION
*  check_hex_value()
*
* DESCRIPTION
*   check hex value
*
* PARAMETERS
*  str		IN		string
*  val		OUT	hex value.
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_check_hex_value (kal_uint8 *str, kal_uint8 *val)
{
   kal_uint16 i=0, j=0;
   kal_uint16 temp;

   kal_trace(TRACE_FUNC, FUNC_DT_CHECK_HEX_VALUE_ENTRY);
   ASSERT ((str != NULL) && (val != NULL));
   dt_toUpper (str);

   while (str[i] != DT_END_OF_STRING_CHAR)
   {
      if (DT_IS_NUMBER(str[i]))
         temp = str[i] - DT_CHAR_0;
      else
         temp = (str[i] - DT_CHAR_A) + 10;

      if (DT_IS_NUMBER(str[i+1]))
         temp = (temp<<4) + (str[i+1] - DT_CHAR_0);
      else
         temp = (temp<<4) + ((str[i+1] - DT_CHAR_A) + 10);

      val[j] = temp;
      i+= 2;
      j++;
   }
}



void dt_int_to_ascii_converter (
                                  kal_uint32 digit,
                                  kal_uint8 *buff_ptr
                                 )
{
    kal_uint8 divisor = 10;
    kal_uint8 tmp;
    kal_uint8 index1;
    kal_uint8 index2;

    kal_trace(TRACE_FUNC, FUNC_DT_INT_TO_ASCII_CONVERTER_ENTRY);
    for ( index1 = 0; digit >= 10; index1++ )
    {
      /* Get last digit of given integer number*/
      *( buff_ptr + index1) = MODULO (digit, divisor);
      /* remove the last digit from the given number & restore the
       * remaining number into the same variable */
      digit = DIVIDE ((digit - (*(buff_ptr + index1))), divisor);
      /* convert the last digit into ASCII Equivalent value */
      *( buff_ptr + index1 ) += DT_CHAR_0;
    }

    /* Incorporate last digit */
    *( buff_ptr + index1 ) = DT_CHAR_0 + digit;

    /* Now invert the string.Because digits are extracted from the
     * number from right to left direction */
    for ( index2 = 0; index2 <= (index1>>1); index2++ )
    {
      tmp                           = *( buff_ptr + index2 );
      *( buff_ptr + index2 )        = *( buff_ptr+index1 - index2 );
      *( buff_ptr + index1 - index2 ) = tmp;
    }

    /* Finish the string */
    *( buff_ptr + index1 + 1 ) = DT_END_OF_STRING_CHAR;
/*
    l4_fn_exit(
                MOD_ATCI,
                FUNC_ATCI_INT_TO_ASCII_CONVERTER_SUBOP
               );
*/
    return;
}


kal_uint32 dt_int_validator_ext(kal_uint8 *error_cause, dt_string_struct *source_string_ptr, 
								kal_uint8 delimiter)
{
    kal_uint32 ret_val        = DT_VALIDATOR_ERROR;
    kal_int32 value           = 0;
    kal_uint16 length;
    kal_bool error_flag       = KAL_FALSE;
    kal_bool some_char_found  = KAL_FALSE;

    kal_trace(TRACE_FUNC, FUNC_DT_INT_VALIDATOR_EXT_ENTRY);
    ASSERT (source_string_ptr != NULL);
    length = strlen ((char *)source_string_ptr->string_ptr);

    /* If there are some leading white spaces, ignore them */
    dt_skip_spaces( source_string_ptr );

    /* we have to initial the error so that we can using again and
    again even if any error occur. so we dont have to init before
    enter this function
    */
    *error_cause = DT_PARSE_OK;

    /* Start checking for the integer, till the delimiter which may
     * be a comma, a dot etc.
     */

    while ((source_string_ptr->string_ptr[source_string_ptr->index]
                                                      != delimiter)
                                                      &&
           (source_string_ptr->string_ptr[source_string_ptr->index]
                                             != DT_PTR->s_reg.s3)
                                                      &&
           (source_string_ptr->index < length))
    {
      /* It means we found something between two commas(,)  */
      some_char_found = KAL_TRUE;

      /* check whether the character is in 0 - 9 range. If so,
       * store corresponding integer value for that character
       */
      if ( ( source_string_ptr->string_ptr[source_string_ptr->index]
                                                 >= DT_CHAR_0 ) &&
          ( source_string_ptr->string_ptr[source_string_ptr->index]
                                                 <= DT_CHAR_9 )
         )
      {
        value = value * 10 +
         (source_string_ptr->string_ptr[source_string_ptr->index]
                                                     - DT_CHAR_0);
      }
      else  /* out of range, return immediately */
      {
        error_flag = KAL_TRUE;
        break;
      }
      /*If the character is a valid part of integer, then continue*/
      source_string_ptr->index++;
    } /* end of the while loop */

    if (error_flag == KAL_TRUE)
    {
      /* Value is not in the valid range. It can also be due to
       * white space in between two digits, because such white
       * spaces are not allowed
       */
       /* mark for solve correct input but incorrect end for 1,2,2, */
     /* rmmi_result_code_fmttr (  RMMI_RCODE_ERROR,
                        INVALID_CHARACTERS_IN_TEXT_ERRSTRING_ERR );*/
      ret_val = DT_VALIDATOR_ERROR;
      *error_cause = (kal_uint8)DT_PARSE_ERROR;
    }
    else if ( some_char_found == KAL_FALSE )
    {
      /* Nothing is present before the delimiter */
      ret_val = DT_VALIDATOR_ERROR;
      *error_cause = (kal_uint8)DT_PARSE_NOT_FOUND;

      /* Increment the string sliding index to point to the next
       * character after delimiter, i.e. the next field in the
       * command line
       */
      source_string_ptr->index++;
    }
    /* If some thing is present and check for the valid range as
     * specified by the calling function
     */
    else
    {
      ret_val = value;
      /* Increment the string sliding index to point to the next
       * character after delimiter, i.e. the next field in the
       * command line
       */
       if (source_string_ptr->string_ptr[source_string_ptr->index] == delimiter)
       {
	      source_string_ptr->index++;
    		dt_skip_spaces( source_string_ptr );
      		if (source_string_ptr->string_ptr[source_string_ptr->index] == DT_PTR->s_reg.s3)
      		{
		      ret_val = DT_VALIDATOR_ERROR;
		      *error_cause = (kal_uint8)DT_PARSE_ERROR;
      		}
       }
       else
	      source_string_ptr->index++;
    }
    return ret_val;
}



kal_uint32 dt_int_validator(
                             dt_string_struct *source_string_ptr,
                             kal_uint8         delimiter
                            )
{
    kal_uint32 ret_val        = DT_VALIDATOR_ERROR;
    kal_int32 value           = 0;
    kal_uint16 length;
    kal_bool error_flag       = KAL_FALSE;
    kal_bool some_char_found  = KAL_FALSE;

    kal_trace(TRACE_FUNC, FUNC_DT_INT_VALIDATOR_ENTRY);
    ASSERT (source_string_ptr != NULL);
    length = strlen ((char *)source_string_ptr->string_ptr);
    /* If there are some leading white spaces, ignore them */
    dt_skip_spaces( source_string_ptr );

    /* Start checking for the integer, till the delimiter which may
     * be a comma, a dot etc.
     */

    while ((source_string_ptr->string_ptr[source_string_ptr->index]
                                                      != delimiter)
                                                      &&
           (source_string_ptr->string_ptr[source_string_ptr->index]
                                             != DT_PTR->s_reg.s3)
                                                      &&
           (source_string_ptr->index < length))
    {
      /* It means we found something between two commas(,)  */
      some_char_found = KAL_TRUE;

      /* check whether the character is in 0 - 9 range. If so,
       * store corresponding integer value for that character
       */
      if ( ( source_string_ptr->string_ptr[source_string_ptr->index]
                                                 >= DT_CHAR_0 ) &&
          ( source_string_ptr->string_ptr[source_string_ptr->index]
                                                 <= DT_CHAR_9 )
         )
      {
        value = value * 10 +
         (source_string_ptr->string_ptr[source_string_ptr->index]
                                                     - DT_CHAR_0);
      }
      else  /* out of range, return immediately */
      {
        error_flag = KAL_TRUE;
        break;
      }
      /*If the character is a valid part of integer, then continue*/
      source_string_ptr->index++;
    } /* end of the while loop */

    if (error_flag == KAL_TRUE)
    {
      /* Value is not in the valid range. It can also be due to
       * white space in between two digits, because such white
       * spaces are not allowed
       */
       /* mark for solve correct input but incorrect end for 1,2,2, */
     /* rmmi_result_code_fmttr (  RMMI_RCODE_ERROR,
                        INVALID_CHARACTERS_IN_TEXT_ERRSTRING_ERR );*/
      ret_val = DT_VALIDATOR_ERROR;
    }
    else if ( some_char_found == KAL_FALSE )
    {
      /* Nothing is present before the delimiter */
      ret_val = DT_VALIDATOR_ERROR;
      /* Increment the string sliding index to point to the next
       * character after delimiter, i.e. the next field in the
       * command line
       */
      source_string_ptr->index++;
    }
    /* If some thing is present and check for the valid range as
     * specified by the calling function
     */
    else
    {
      ret_val = value;
      /* Increment the string sliding index to point to the next
       * character after delimiter, i.e. the next field in the
       * command line
       */
      source_string_ptr->index++;
    }

    return ret_val;
}


/*****************************************************************************
* FUNCTION
*  dt_string_validator_ext
* DESCRIPTION
*  this function extends dt_string_validator_ext().
*	addtionally it passes the error_cause back, and here <CR> acts as delimiter as well
* PARAMETERS
*
* RETURNS
*   if string is correctly parsed: ret_val = RMMI_DEF_VALUE.
*	 otherwise : ret_val = RMMI_VALIDATOR ERROR. there are 3 possible cases:
*    1. no string is found by delimiter or <CR> ==> error_cause = RMMI_PARSE_NOT_FOUND
*    2. string is invalid syntax or too long      ==> error_cause = RMMI_PARSE_ERROR
*	  3. string is a null string (the case "" )     ==> error_cause = RMMI_PARSE_OK
* GLOBALS AFFECTED
*   source_string_ptr->index will be increased
*****************************************************************************/
kal_uint8 dt_string_validator_ext (kal_uint8 * error_cause,
											dt_string_struct *source_string_ptr,
                                 kal_uint8 delimiter,
                                 kal_uint16 max_length,
                                 kal_uint8 *str)
{
    kal_uint8 ret_val         = DT_VALIDATOR_ERROR;
    kal_uint16 	index = 0;
    kal_uint8 error_flag      = 0;
    kal_bool some_char_found  = KAL_FALSE;
    kal_uint16 length;

    kal_trace(TRACE_FUNC, FUNC_DT_STRING_VALIDATOR_ENTRY);
    ASSERT ((str != NULL) && (source_string_ptr != NULL) && (error_cause!= NULL) );

    *error_cause = DT_PARSE_OK;

    length = strlen ((char *)source_string_ptr->string_ptr);
    if (source_string_ptr->index >= length)
    {
    	*((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
		*error_cause = DT_PARSE_NOT_FOUND;
		return ret_val;
    }

    /* check the first char (but skip space first ) */
	while (1)
	{
	    /* If there are some leading white spaces, ignore them */
		dt_skip_spaces( source_string_ptr );

		/* if double_quote found: string begins */
		if (source_string_ptr->string_ptr[source_string_ptr->index]
										      == DT_DOUBLE_QUOTE)
		{
			source_string_ptr->index++;
			break;
		}
		/* if delimiter found: error cause = RMMI_PARSE_NOT_FOUND */
		else if ((source_string_ptr->string_ptr[source_string_ptr->index]
										      == delimiter) ||
						(source_string_ptr->string_ptr[source_string_ptr->index]
										      == DT_PTR->s_reg.s3))
		{
			source_string_ptr->index++;  /* point to the next char after delimiter */
			*((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
			*error_cause = DT_PARSE_NOT_FOUND;
			return ret_val;
		}
		/* else : error cause = RMMI_PARSE_ERROR, not string type */
		else{
			*((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
			*error_cause = DT_PARSE_ERROR;
			return ret_val;
		}
	}


    while (source_string_ptr->string_ptr[source_string_ptr->index]
                                            != DT_DOUBLE_QUOTE)

    {
      /* It means we found something after "  */
      some_char_found = KAL_TRUE;

         if (index >= (max_length-1)) /* length is too long , break */
         {
            error_flag = DT_ERR_TEXT_ERRSTRING_TOO_LONG_ERR;
            break;
         }

         /*append the char to str except backslash '\'    */
         if(source_string_ptr->string_ptr[source_string_ptr->index]!='\\')
         {
         *((kal_uint8 *)str+index) =
			   source_string_ptr->string_ptr[source_string_ptr->index];
		   index ++;
		      source_string_ptr->index++;
         }
         else //according to v.25ter sec 5.4.2.2
         {
         	kal_uint8 temp;
         	kal_uint8 ch;

		      source_string_ptr->index++;
		      ch = source_string_ptr->string_ptr[source_string_ptr->index];

		      if (DT_IS_NUMBER(ch))
		         temp = ch - DT_CHAR_0;
		      else if((ch>= DT_CHAR_A) && (ch<= DT_CHAR_F))
		         temp = ch - DT_CHAR_A + 10;
		      else if((ch>= dt_char_a) && (ch<= dt_char_f))
		         temp = ch - dt_char_a+ 10;
		      else //not hex format
		      {
        			error_flag = DT_ERR_INVALID_CHARACTERS_IN_TEXT_ERRSTRING_ERR;
		      	break;
		      }

		      source_string_ptr->index++;
		      ch = source_string_ptr->string_ptr[source_string_ptr->index];

		      if (DT_IS_NUMBER(ch))
		         temp = (temp<<4) + (ch - DT_CHAR_0);
		      else if((ch>= DT_CHAR_A) && (ch<= DT_CHAR_F))
		         temp = (temp<<4) + ((ch - DT_CHAR_A) + 10);
		      else if((ch>= dt_char_a) && (ch<= dt_char_f))
		         temp = (temp<<4) + ((ch - dt_char_a) + 10);
		      else //not hex format
		      {
        			error_flag = DT_ERR_INVALID_CHARACTERS_IN_TEXT_ERRSTRING_ERR;
		      	break;
		      }

		      *((kal_uint8 *)str+index)= temp;
		       index ++;
		      source_string_ptr->index++;
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
#endif
    } /* end of the while loop */

    if (error_flag != 0)
    {
      if(error_flag==DT_ERR_TEXT_ERRSTRING_TOO_LONG_ERR)
      	*error_cause = DT_PARSE_TEXT_TOO_LONG;
      else
      	*error_cause = DT_PARSE_ERROR;   /* Value is not in the valid range.  */

	   *((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
      ret_val = DT_VALIDATOR_ERROR;
      return ret_val;
    }
    else if ( some_char_found == KAL_FALSE )
    {
      /* Null string: "" : set error_cause = RMMI_PARSE_OK (ret_val= RMMI_VALIDATOR_ERROR) */
      *error_cause = DT_PARSE_OK;
      ret_val = DT_VALIDATOR_ERROR;
	   *((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;

      /* Increment the string sliding index to point to the next
       * character after DOUBLE_QUOTE */
      source_string_ptr->index++;
    }
    else
    {
      /* If some thing is present between 2 double quotes: "xxx" */
      ret_val = DT_DEF_VALUE;
	   *((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
      /* Increment the string sliding index to point to the next
       * character after DOUBLE_QUOTE */
      source_string_ptr->index++;
    }

   /* final check the delimiter and increase index to skip it */
	while (1)
	{
	    /* If there are some leading white spaces, ignore them */
		dt_skip_spaces( source_string_ptr );

	   /* if delimiter found: increase index and break(thus return)*/
		if ((source_string_ptr->string_ptr[source_string_ptr->index]
										      == delimiter) ||
					(source_string_ptr->string_ptr[source_string_ptr->index]
										      == DT_PTR->s_reg.s3))
		{
			source_string_ptr->index++;
			break;
		}
		/* no delimiter nor <CR> : ret_val = RMMI_VALIDATOR_ERROR */
		else
		{
			*((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
			*error_cause = DT_PARSE_ERROR;
			ret_val = DT_VALIDATOR_ERROR;
			return ret_val;
		}
	}
   return ret_val;

}

kal_uint8 dt_string_validator (dt_string_struct *source_string_ptr,
                                 kal_uint8 delimiter,
                                 kal_uint16 max_length,
                                 kal_uint8 *str)
{
    kal_uint8 ret_val         = DT_VALIDATOR_ERROR;
	 kal_uint16 index = 0;
    kal_uint8 error_flag      = 0;
    kal_bool some_char_found  = KAL_FALSE;

    kal_trace(TRACE_FUNC, FUNC_DT_STRING_VALIDATOR_ENTRY);
    ASSERT ((str != NULL) && (source_string_ptr != NULL));
    /* Start checking for the integer, till the delimiter which may
     * be a comma, a dot etc.
     */
	while (1)
	{
	    /* If there are some leading white spaces, ignore them */
		dt_skip_spaces( source_string_ptr );

		if (source_string_ptr->string_ptr[source_string_ptr->index]
										      == DT_DOUBLE_QUOTE)
		{
			source_string_ptr->index++;
			break;
		}
		else
		{
         if (source_string_ptr->string_ptr[source_string_ptr->index]
										      == delimiter)
         {
            source_string_ptr->index++;
         }
			*((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
			return ret_val;
		}
	}

    while (source_string_ptr->string_ptr[source_string_ptr->index]
                                            != DT_DOUBLE_QUOTE )
    {
      /* It means we found something between two commas(,)  */
      some_char_found = KAL_TRUE;
      //rmmi_skip_spaces( source_string_ptr );

      /* check whether the character is in 0 - 9 range. If so,
       * store corresponding integer value for that character
       */
      if (DT_IS_NUMBER(
				source_string_ptr->string_ptr[source_string_ptr->index]) ||
		  DT_IS_ALPHA (
				source_string_ptr->string_ptr[source_string_ptr->index]) ||
		  DT_IS_SYMBOL (
				source_string_ptr->string_ptr[source_string_ptr->index])
         )
      {
         if (index >= (max_length-1))
         {
            error_flag = DT_ERR_TEXT_ERRSTRING_TOO_LONG_ERR;
            break;
         }
         *((kal_uint8 *)str+index) =
			   source_string_ptr->string_ptr[source_string_ptr->index];
		   index ++;
      }
      else  /* out of range, return immediately */
      {
        error_flag = DT_ERR_INVALID_CHARACTERS_IN_TEXT_ERRSTRING_ERR;
        break;
      }
      /*If the character is a valid part of integer, then continue*/
      source_string_ptr->index++;
    } /* end of the while loop */

    if (error_flag != 0)
    {
      /* Value is not in the valid range. It can also be due to
       * white space in between two digits, because such white
       * spaces are not allowed
       */
	   *((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
     // rmmi_result_code_fmttr (  RMMI_RCODE_ERROR, error_flag );
      ret_val = DT_VALIDATOR_ERROR;
    }
    else if ( some_char_found == KAL_FALSE )
    {
      /* Nothing is present before the delimiter */
      ret_val = DT_VALIDATOR_ERROR;
	   *((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
      /* Increment the string sliding index to point to the next
       * character after delimiter, i.e. the next field in the
       * command line
       */
      source_string_ptr->index++;
    }
    /* If some thing is present and check for the valid range as
     * specified by the calling function
     */
    else
    {
      ret_val = DT_DEF_VALUE;
	   *((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
      /* Increment the string sliding index to point to the next
       * character after delimiter, i.e. the next field in the
       * command line
       */
      source_string_ptr->index++;
    }

	while (1)
	{
	    /* If there are some leading white spaces, ignore them */
		dt_skip_spaces( source_string_ptr );

		if (source_string_ptr->string_ptr[source_string_ptr->index]
										      == delimiter)
		{
			source_string_ptr->index++;
			break;
		}
		else
		{
			*((kal_uint8 *)str+index) = DT_END_OF_STRING_CHAR;
			ret_val = DT_VALIDATOR_ERROR;
			return ret_val;
		}
	}
    return ret_val;

}

kal_uint8 dt_find_cmd_mode (dt_string_struct *source_string_ptr)
{
    kal_uint8   ret_val =  DT_WRONG_MODE;

    kal_trace(TRACE_FUNC, FUNC_DT_FIND_CMD_MODE_ENTRY);
    ASSERT (source_string_ptr != NULL);
    /* Skip all leading white spaces */
    dt_skip_spaces( source_string_ptr );

    /* First check for the READ command format
     * Eg:"AT+CGATT?\r" Here we first search for '?' character */
    if ( source_string_ptr->string_ptr[source_string_ptr->index]
                            == DT_QUESTION_MARK )
    {
      source_string_ptr->index++;
      dt_skip_spaces ( source_string_ptr );

      /* Check for the end of line character ('\r'). there may be
       * spaces between the question mark and the command line
       * termination character.
       */
      if ( source_string_ptr-> string_ptr[source_string_ptr->index]
                                 == DT_PTR->s_reg.s3 )
      {
        /* If the above two conditions are passed then return
         * READ_MODE */
        ret_val = DT_READ_MODE;
      }
      /* else, return RMMI_WRONG_MODE */
      return ret_val;
    }

    /* If not read mode, then check for the TEST/SET/EXECUTE mode.
     * Symbol '=' is common for both SET/EXECUTE and TEST command;
     * so first check for the '=' symbol.
     */
    if ( source_string_ptr->string_ptr[source_string_ptr->index]
                             == DT_EQUAL )
    {
      /* If we find '?' after the '=' symbol, then we decide that
       * given command is TEST command. Else it is assumed to be
       * either a SET or an EXECUTE command
       */
      source_string_ptr->index++;
      /* Skip white spaces after the '=' symbol */
     dt_skip_spaces(source_string_ptr);
      if (source_string_ptr->string_ptr[source_string_ptr->index]
              == DT_QUESTION_MARK )
      {
        /* Since question mark is also found, check whether the
         * string is terminated properly by a termination character.
         * White spaces may be present between the question mark and
         * the termination character.
         */
        source_string_ptr->index++;
        dt_skip_spaces(source_string_ptr);

        if ( source_string_ptr->string_ptr[source_string_ptr->index]
                                  == DT_PTR->s_reg.s3 )
        {
          ret_val = DT_TEST_MODE;
        }
      }
      /* If didn't find '?' after the '=' symbol then we decide that
       * given command is SET/EXECUTE command */
      else
      {
        ret_val = DT_SET_OR_EXECUTE_MODE;
      }
    }/* mtk00468 add for some extend command has no parameter */
    else if((source_string_ptr->string_ptr[source_string_ptr->index] == DT_PTR->s_reg.s3)||
    	      	( source_string_ptr->string_ptr[source_string_ptr->index] == DT_PTR->s_reg.s4 ))

    {
		ret_val = DT_ACTIVE_MODE;
    }

    return ret_val;
}

void dt_reset_state()
{
	DT_PTR->transfer_type = DT_NO_TRANSFER_TYPE;
	DT_PTR->app_type = DT_NO_APP_TYPE;	
	DT_PTR->transfered_port = 0xff;	
	DT_PTR->transfer_state = DT_IDLE_STATE;		

	return;
}

void dt_clear_uart_queue(void)
{
    DT_PTR->uart_input_queue.length = 0;
    DT_PTR->uart_input_queue.head = 0;
    DT_PTR->uart_output_queue.head = 0;
    DT_PTR->uart_output_queue.length = 0;
}

#ifdef __GEMINI__
void dt_set_src_mod_id(module_type uart_owner)
{
	kal_prompt_trace(MOD_DT,"Set DT src mod id=%d",uart_owner);
	DT_PTR->src_mod_id = uart_owner;
}
#endif

