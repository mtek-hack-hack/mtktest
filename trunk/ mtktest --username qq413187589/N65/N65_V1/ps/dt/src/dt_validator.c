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
 *	dt_validator.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
*****************************************************************************/

#define DT_VALIDATOR_C

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
#include "dt_context.h"

#include "dt_trc.h"

#include "dt_rspfmttr.h"
#include "dt_utility.h"
#include "dt_aux_msg_hdlr.h"


//#ifdef FMT_NOT_PRESENT 								
//#define DT_MAX_IMAGE_FILE_NAME 30 
//#define DT_MAX_MELODY_FILE_NAME 30 
//#else
#define DT_MAX_IMAGE_FILE_NAME 250 
#define DT_MAX_MELODY_FILE_NAME 250 
//#endif


#ifdef DATA_DOWNLOAD
/*****************************************************************************
* FUNCTION
*  dt_efsw_hdlr
*
* DESCRIPTION
*   This is rmmi function handler for PC tool to delete a file
*   from file system.
*   mtk00714 add on 04/04/30
*
* PARAMETERS
*  source_string_ptr		IN		at cmd string
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_efsw_hdlr (dt_string_struct *source_string_ptr)
{
    kal_bool      ret_val = KAL_FALSE;
     kal_uint8		result;
    kal_uint8		op;
    kal_uint16 		data_len;
    kal_uint8 		eof_flag;
    //kal_uint8	   tempdata[DT_UPLOAD_SIZE*2];
    //kal_uint8 	   data[DT_UPLOAD_SIZE];
    kal_uint8    *tempdata = NULL;
    kal_uint8	   *data = NULL;
    kal_uint8		error_cause;
    kal_uint16      write_data_size;
    kal_uint8 const  *rsp_str = NULL;
    kal_uint8        buffer[DT_SHORT_RSP_LEN];
    kal_uint16 string_length = 0;      
    kal_trace(TRACE_GROUP_4, FUNC_DT_EFSW_HDLR_ENTRY);
     
	switch (source_string_ptr->cmd_mode)
    	{
			/* checking the command mode */
	      	case DT_TEST_MODE :
	      	{
	      		ret_val = KAL_TRUE;
	        	break;
	      	}
		case DT_READ_MODE : 
	      	{
 			write_data_size = DT_PTR->write_data_size;
			ret_val = KAL_TRUE;
			DT_PTR->arg_list[0] = (void *)&write_data_size;
			string_length = dt_fast_string_print (
			                               buffer,
			                               (kal_uint8 *)"+EFSW: %u",
			                               DT_PTR->arg_list,
			                               1
			                              );
			        	rsp_str = &buffer[0];
	        	break;
	      	}	
	      	case DT_SET_OR_EXECUTE_MODE : 
      		{
			op = (kal_uint8)dt_int_validator_ext( &error_cause, source_string_ptr, (kal_uint8)DT_COMMA);				                      
      			switch(op)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
	      			case 1:
	      			{
					ret_val = dt_eq_general_fs_access_req(DT_FS_CLOSE, DT_APP_UNKNOWN, NULL, NULL, 0);
					if(ret_val == KAL_TRUE)
					{
						dt_send_l4c_upload_cnf(DT_NO_ERR);
						dt_reset_state();
						return;
					}
					else
					{
						dt_send_l4c_upload_cnf(DT_PTR->cmee_err);							
						dt_reset_state();
						return;
					}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		      		}
		      		break;
		      		case 2:
		      		{
	     				eof_flag = (kal_uint8)dt_int_validator( source_string_ptr, (kal_uint8)DT_COMMA);
	     				if(eof_flag>1)
	     				{
						break;
		 	        	}
	     				
        				data_len = (kal_uint16)dt_int_validator(source_string_ptr,(kal_uint8)DT_COMMA);
	     				if(data_len>DT_UPLOAD_SIZE)
	     				{
						break;
		 	        	}

					ASSERT((kal_uint16)(DT_UPLOAD_SIZE*2)<2048);

					tempdata = get_ctrl_buffer(DT_UPLOAD_SIZE*2+1);
					data = get_ctrl_buffer(DT_UPLOAD_SIZE);				

					result = dt_string_validator( source_string_ptr, (kal_uint8)DT_PTR->s_reg.s3, 
																(kal_uint16)(data_len*2+1), (kal_uint8 *)tempdata);
					if(result == DT_VALIDATOR_ERROR)
     					{

						if(tempdata!=NULL)	
							free_ctrl_buffer(tempdata);
						if(data!=NULL)	
							free_ctrl_buffer(data);	
		     					
						break;
		 	        	}
					dt_check_hex_value(tempdata, (kal_uint8 *)data);
					ret_val = dt_eq_general_fs_access_req(DT_FS_WRITE,DT_APP_UNKNOWN, NULL,(kal_uint8 *)data,data_len);					

					if(tempdata!=NULL)	
						free_ctrl_buffer(tempdata);
					if(data!=NULL)	
						free_ctrl_buffer(data); 
 
					if(ret_val == KAL_FALSE)
					{
						dt_send_l4c_upload_cnf(DT_PTR->cmee_err);							
						dt_reset_state();
						return;
					}
					break;
		      		}
		      		break;
	      			default:
	      			{
					break;
      				}
      			}
      			break;
	      	}
         	default :
         	{
            		/* unrecognized format of AT command line */
            		break;
         	}
    	}/* end of the switch */
    	dt_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8*)rsp_str, string_length);
}


/*****************************************************************************
* FUNCTION
*  dt_efsr_hdlr
*
* DESCRIPTION
*   This is rmmi function handler for PC tool to read a file
*   from file system.
*   mtk00714 add on 04/04/30
*
* PARAMETERS
*  source_string_ptr		IN		at cmd string
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_efsr_hdlr (dt_string_struct *source_string_ptr)
{
    kal_bool      ret_val = KAL_FALSE;
    
    kal_trace(TRACE_GROUP_4, FUNC_DT_EFSR_HDLR_ENTRY);
          
    switch (source_string_ptr->cmd_mode)
    {
			/* checking the command mode */
	      case DT_TEST_MODE :
	      {
	      		ret_val = KAL_TRUE;
	        	break;
	      }
	      case DT_ACTIVE_MODE:
	      {
		  	if(DT_PTR->transfer_state != DT_DOWNLOAD_STATE)
		  	{
		  		kal_trace(TRACE_WARNING,WARNING_DT_NOT_DOWNLOAD_STATE,DT_PTR->transfer_state);
				return;
		  	}
			
	      			/* clear download pause timer */
				dt_clear_download_timer();	     

			if(DT_PTR->uart_stop_send_flag == KAL_FALSE)
			{
			   	if(DT_PTR->fd[0] != 0)
			   	{
			   		/* close the file handle and clear the stored infomation*/
			   		kal_prompt_trace(MOD_DT,"dt_efsr_hdlr: close DT_PTR->fd[0]");

					FS_Close(DT_PTR->fd[0]);
					DT_PTR->fd[0] = 0;
					DT_PTR->data_folder= 0;
					DT_PTR->printingDownloadData_flag = KAL_FALSE;
					DT_PTR->printingDownloadData_loopCount = 0;							
			   	}

			   	if(DT_PTR->fd[1] !=0)
			   	{
			   		kal_prompt_trace(MOD_DT,"dt_efsr_hdlr: close DT_PTR->fd[1]");
			   		/* close the file handle and clear the stored infomation*/
					FS_Close(DT_PTR->fd[1]);
					DT_PTR->fd[1] = 0;					
			   	}		

				if (DT_PTR->download_filename!= NULL)
				{
					free_ctrl_buffer(DT_PTR->download_filename);//filename is allocated in l4c and free here
					DT_PTR->download_filename = NULL;
				}
				
				//mtk01616_071003
				if(DT_PTR->transfer_state == DT_DOWNLOAD_STATE)
				        dt_send_l4c_download_cnf(DT_ERR_USER_ABORT);	
				else if(DT_PTR->transfer_state == DT_FILELIST_STATE)
					dt_send_l4c_filelist_cnf(DT_ERR_USER_ABORT);	
					
				dt_reset_state();
			}
			else
			{     /*mtk00924_060320: user abort during waiting for uart_ready_to_write_ind, 
			          sending download_cnf when finishing last run of +EFSR*/
				kal_trace(TRACE_WARNING, WARNING_DT_USER_ABORT_WHEN_UART_FULL);
				DT_PTR->abort_download = KAL_TRUE;
			}
				return;

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
#endif	      
         	default :
         	{
            		/* unrecognized format of AT command line */
            		break;
         	}
    	}/* end of the switch */

    dt_final_rsp_generator(source_string_ptr->src_id, ret_val, NULL, 0);
}



void dt_download_hdlr(dt_string_struct *source_string_ptr, kal_uint16 action)
{
    kal_bool         ret_val = KAL_FALSE;
    kal_uint8 		op,type =0;
    kal_uint8	   	*img_file_name = NULL;//using for get ascii code frm PC
    kal_uint8		*file_name= NULL;/* save ucs2 format for UEM*/

    //kal_uint8	   tempdata[DT_UPLOAD_SIZE*2+1];
    //kal_uint8 	   img_data[DT_UPLOAD_SIZE];
    kal_uint8    *tempdata = NULL;
    kal_uint8	   *img_data= NULL;
    
    kal_uint8 const  *rsp_str = NULL; /*response string and initialization */
    kal_uint16 string_length=0; /* string length variable */
    kal_uint8 result;
    kal_uint16 data_len = 0;
    kal_uint8 eof_flag;
    kal_uint8 error_cause;
    
	switch (source_string_ptr->cmd_mode)
    	{
//    	#ifdef __test_mode__
		/* checking the command mode */
	      case DT_TEST_MODE :/* at+eimg=? or at+emdy=? */
	      {
	      		if (action == DT_EIMG)
			        rsp_str=(kal_uint8 const *)"+EIMG: (0-7)"; /*prepare the response string */
	      		else
			        rsp_str=(kal_uint8 const *)"+EMDY: (0-7)"; /*prepare the response string */
	        	string_length = strlen ((char *)rsp_str); /* type casting */
	        	ret_val = KAL_TRUE;
	        	break;
	      }
//	#endif /*__test_mode__*/
	      case DT_SET_OR_EXECUTE_MODE : /* at+eimg = */
      	  	{
			DT_PTR->cmee_err = DT_ERR_SYNTEX_ERROR; //default error cause
			
               	/* Get <op> */
		       op = (kal_uint8)dt_int_validator(
		                        source_string_ptr,
		                        (kal_uint8)DT_COMMA
		                       );
	              if(op >7)
	              	break;

			  /* parse following syntax field */
       	       switch(op)
              	{
				case 0://open file
				case 3: //read file
				case 4: //delete file
				case 5: //play file
				case 6: //stop playing file
			   	{
				    	img_file_name = get_ctrl_buffer(DT_MAX_IMAGE_FILE_NAME * 2);
				    	file_name = get_ctrl_buffer(DT_MAX_IMAGE_FILE_NAME);
				    	kal_mem_set(file_name, 0 , DT_MAX_IMAGE_FILE_NAME);
					result = dt_string_validator_ext(
											&error_cause,
			       		                			source_string_ptr,
			                     		   			(kal_uint8)DT_COMMA,
											DT_MAX_IMAGE_FILE_NAME*2, 
											(kal_uint8 *)img_file_name);
					
					if(result != DT_VALIDATOR_ERROR)
					{
						dt_check_hex_value(img_file_name, (kal_uint8 *)file_name);
						free_ctrl_buffer(img_file_name);
						img_file_name = NULL;
					}
					else
					{
						free_ctrl_buffer(img_file_name);
						img_file_name = NULL;
						break;
					}

					type = (kal_uint8)dt_int_validator_ext(
												&error_cause,
				                        					source_string_ptr,
				       					              (kal_uint8)DT_PTR->s_reg.s3);				                       					
								
					if(type==DT_VALIDATOR_ERROR)
					{
							break;
					}				
				    	else
				    	{
	      					if (action == DT_EIMG)
	      					{
							if(type !=0) break;
	      					}
						else
						{
							if(type > 1) break; //+EMDY has 2 type: mid and imy
						}
				    	}
					    	
					ret_val=KAL_TRUE;
					break;
				}
				case 2: //write(download)
			     	{
    					//kal_mem_set(img_data, 0 , DT_UPLOAD_SIZE);
		        		data_len = (kal_uint16)dt_int_validator(
						                        source_string_ptr,
						                        (kal_uint8)DT_COMMA
						                       );
		        		if(data_len>DT_UPLOAD_SIZE) break;

		        		eof_flag = (kal_uint8)dt_int_validator(
						                        source_string_ptr,
						                        (kal_uint8)DT_COMMA
						                       );
	      				if(eof_flag>1) break;

					ASSERT((kal_uint16)(DT_UPLOAD_SIZE*2+1)<2048);

					tempdata = get_ctrl_buffer(DT_UPLOAD_SIZE*2+1);
					img_data = get_ctrl_buffer(DT_UPLOAD_SIZE); 			
					kal_mem_set(img_data, 0 , DT_UPLOAD_SIZE);

					result = dt_string_validator(
					                        			source_string_ptr,
					                        			(kal_uint8)DT_PTR->s_reg.s3,  /* separator */
											(kal_uint16)(data_len*2+1), 
											(kal_uint8 *)tempdata);
					if(result == DT_VALIDATOR_ERROR)
					{

						if(tempdata!=NULL)	
							free_ctrl_buffer(tempdata);
						if(img_data!=NULL)	
							free_ctrl_buffer(img_data); 
 
						break;
					}
					dt_check_hex_value(tempdata, (kal_uint8 *)img_data);
								
					ret_val=KAL_TRUE;
		                	break;
				}
				case 7: //list files in specified folder
				{
					type = (kal_uint8)dt_int_validator_ext(
											&error_cause,
                       								 source_string_ptr,
							                        (kal_uint8)DT_PTR->s_reg.s3
                       								);								
					if(type==DT_VALIDATOR_ERROR)
					{
							break;
					}				
				    	else
				    	{
	      					if (action == DT_EIMG)
	      					{
							if(type !=0) break;
	      					}
						else
						{
							if(type > 1) break;
						}
				    	}

					ret_val=KAL_TRUE;
				    	break;
				}
				default:
					ret_val= KAL_TRUE;
              	}

			if(ret_val==KAL_TRUE) //no parse Error
			{
	      			if ((action == DT_EIMG) && (type == 0))
					type = DT_IMAGE;
	      			//if action == DT_EMDY , type : 0 and 1
                		switch(op)
                		{
							case 0://open middy filey
							{
						
//#ifdef FMT_NOT_PRESENT 								
//								ret_val = l4c_eq_fs_access_req(source_string_ptr->src_id, 
//												RMMI_FS_OPEN, type,(kal_wchar *)file_name,NULL,0);
//#else
								ret_val = dt_eq_general_fs_access_req(DT_FS_OPEN, (dt_app_type_enum)type,(kal_wchar *)file_name,NULL,0);
//#endif
								break;
							}
							case 1://close middy
							{
//#ifdef FMT_NOT_PRESENT 								
//								ret_val = l4c_eq_fs_access_req(source_string_ptr->src_id, RMMI_FS_CLOSE, type , NULL, NULL, 0);
//#else
								ret_val = dt_eq_general_fs_access_req(DT_FS_CLOSE, (dt_app_type_enum)type , NULL, NULL, 0);
//#endif
								if(ret_val == KAL_TRUE)
								{
									dt_send_l4c_upload_cnf(DT_NO_ERR);	
									dt_reset_state();
									return;
								}
								else
								{
									dt_send_l4c_upload_cnf(DT_PTR->cmee_err);						
									dt_reset_state();
									return;
								}
//								if (ret_val ==KAL_TRUE) return;
//									else break;
							}
						       case 2://download / write
						   	{
//#ifdef FMT_NOT_PRESENT 								
//						    		ret_val = l4c_eq_fs_access_req(source_string_ptr->src_id, 
//						    						RMMI_FS_WRITE,type,NULL,(kal_uint8 *)img_data,data_len);
//#else
						    		ret_val = dt_eq_general_fs_access_req(DT_FS_WRITE,(dt_app_type_enum)type,NULL,(kal_uint8 *)img_data,data_len);
//#endif

								if(tempdata!=NULL)	
									free_ctrl_buffer(tempdata);
								if(img_data!=NULL)	
									free_ctrl_buffer(img_data); 


								if(ret_val == KAL_FALSE)
								{
									dt_send_l4c_upload_cnf(DT_PTR->cmee_err);						
									dt_reset_state();
									return;
								}
								
								break;
						   	}
						   	case 3://retrive			
						   	{

//#ifdef FMT_NOT_PRESENT 								
//						    		ret_val = l4c_eq_fs_access_req(source_string_ptr->src_id, RMMI_FS_READ, type, (kal_wchar *)file_name, NULL,0);
//#else
						    		ret_val = dt_eq_general_fs_access_req(DT_FS_READ, (dt_app_type_enum)type, (kal_wchar *)file_name, NULL,0);
//#endif
								if (file_name!= NULL)
									free_ctrl_buffer(file_name);
								return; 
						   	}
						   	case 4://delete
						   	{
//#ifdef FMT_NOT_PRESENT 							
//						    		ret_val = l4c_eq_fs_access_req(source_string_ptr->src_id, RMMI_FS_DELETE, type ,(kal_wchar *)file_name, NULL,0);
//#else
						    		ret_val = dt_eq_general_fs_access_req(DT_FS_DELETE, (dt_app_type_enum)type ,(kal_wchar *)file_name, NULL,0);
//#endif
								if (ret_val ==KAL_TRUE)
								{
									if (file_name!= NULL)
										free_ctrl_buffer(file_name);
									return;
								}
								else break;
						   	}
							case 5://show
							{
//#ifdef FMT_NOT_PRESENT 
//NO File manager -> inform MMI DOWNLOAD folder to play
//								if (action == DT_EIMG)
//					 				//mmi_ind_ft[FS_FILE_EXECUTE_IND][LMMI_SRC](L4C_IMAGE_STD, (kal_uint8*)file_name, L4C_FILE_EXECUTE_PLAY);
//					 				l4c_eq_data_dl_execute_req_lind(L4C_IMAGE_STD, (kal_uint8*)file_name, L4C_FILE_EXECUTE_PLAY);        	
//				   				else if(type==0)
//					 				//mmi_ind_ft[FS_FILE_EXECUTE_IND][LMMI_SRC](L4C_AUDIO_IMELODY, (kal_uint8*)file_name, L4C_FILE_EXECUTE_PLAY);    
//					 				l4c_eq_data_dl_execute_req_lind(L4C_AUDIO_IMELODY, (kal_uint8*)file_name, L4C_FILE_EXECUTE_PLAY);        	
//		   						else
//				 					//mmi_ind_ft[FS_FILE_EXECUTE_IND][LMMI_SRC](L4C_AUDIO_OTHER, (kal_uint8*)file_name, L4C_FILE_EXECUTE_PLAY);
//				 					l4c_eq_data_dl_execute_req_lind(L4C_AUDIO_OTHER, (kal_uint8*)file_name, L4C_FILE_EXECUTE_PLAY);      	
//
//								if (file_name!= NULL)
//									free_ctrl_buffer(file_name);
//								return;
//#else			
								ret_val = KAL_FALSE;
								DT_PTR->cmee_err = DT_ERR_OPERATION_NOT_SUPPORTED;
								break;
//#endif		
							}
							case 6://stop showing
							{
//#ifdef FMT_NOT_PRESENT 
//NO File manager -> inform MMI DOWNLOAD folder to stop
//								if (action == DT_EIMG)
//				 					//mmi_ind_ft[FS_FILE_EXECUTE_IND][LMMI_SRC](L4C_IMAGE_STD, (kal_uint8*)file_name, L4C_FILE_EXECUTE_STOP);        	
//				 					l4c_eq_data_dl_execute_req_lind(L4C_IMAGE_STD, (kal_uint8*)file_name, L4C_FILE_EXECUTE_STOP);
//				   				if(type==0)
//						 			//mmi_ind_ft[FS_FILE_EXECUTE_IND][LMMI_SRC](L4C_AUDIO_IMELODY, (kal_uint8*)file_name, L4C_FILE_EXECUTE_STOP);        	
//						 			l4c_eq_data_dl_execute_req_lind(L4C_AUDIO_IMELODY, (kal_uint8*)file_name, L4C_FILE_EXECUTE_STOP);
//				   				else
//						 			//mmi_ind_ft[FS_FILE_EXECUTE_IND][LMMI_SRC](L4C_AUDIO_OTHER, (kal_uint8*)file_name, L4C_FILE_EXECUTE_STOP);        	
//						 			l4c_eq_data_dl_execute_req_lind(L4C_AUDIO_OTHER, (kal_uint8*)file_name, L4C_FILE_EXECUTE_STOP);
//
//								if (file_name!= NULL)
//									free_ctrl_buffer(file_name);
//								return;
//#else			
								ret_val = KAL_FALSE;
								DT_PTR->cmee_err = DT_ERR_OPERATION_NOT_SUPPORTED;
								break;
//#endif								
							}
					case 7://dir
							{
//#ifdef FMT_NOT_PRESENT 
//						    		ret_val = l4c_eq_fs_access_req(source_string_ptr->src_id, RMMI_FS_DIR, type ,NULL, NULL, 0);
//#else
						    		ret_val = dt_eq_general_fs_access_req(DT_FS_DIR, (dt_app_type_enum)type ,NULL, NULL, 0);
								if(ret_val == KAL_FALSE)
									break;
//#endif
								return;
							}
                			}
				 }
             			break;
	      	}
          	default : //unrcognized command mode
          	{
	            	/* unrecognized format of AT command line */
	        	break;
          	}
    }/* end of the switch */

    if (file_name!= NULL)
	free_ctrl_buffer(file_name);

    dt_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8 *)rsp_str, string_length);
    return;

}


/*****************************************************************************
* FUNCTION
*  dt_emdy_hdlr
*
* DESCRIPTION
*   This is rmmi function handler for PC tool to download melody data to and 
*   from file system.
*   mtk00468 add on 09/09
*
* PARAMETERS
*  source_string_ptr		IN		at cmd string
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_emdy_hdlr (dt_string_struct *source_string_ptr)
{
	dt_download_hdlr(source_string_ptr, DT_EMDY);
    	return;
}

/*****************************************************************************
* FUNCTION
*  dt_eimg_hdlr
*
* DESCRIPTION
*   This is rmmi function handler for PC tool to download image data to and 
*   from file system.
*   mtk00468 add on 09/09
*
* PARAMETERS
*  source_string_ptr		IN		at cmd string
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_eimg_hdlr (dt_string_struct *source_string_ptr)
{
	dt_download_hdlr(source_string_ptr, DT_EIMG);
    	return;
}

#endif /*DATA_DOWNLOAD*/
