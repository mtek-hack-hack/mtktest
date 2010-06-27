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
 *	dt_analyzer.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
*****************************************************************************/

#define DT_ANALYZER_C

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
#include "dt_msg_hdlr.h"
#include "dt_rspfmttr.h"
#include "dt_validator.h"

#include "dt_utility.h"

/*****************************************************************************
* FUNCTION
*  dt_cmd_processor
*
* DESCRIPTION
*   This is dt_cmd_processor function of L4C module.
*   It uses recursive method to process the mutliple cmd string:
*   	seperate each command by ';' ,
*   	classify each command type(BASIC, EXTEND, PREVIOS, or CUSTOMER),
* 	and then call appropriate process function: rmmi_extended_cmd_processor()/ rmmi_basic_cmd_processer()
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
void dt_cmd_processor (dt_string_struct *source_string_ptr, kal_uint16 cmd_length)
{
    kal_uint32	actual_length;/* we filter te string which is not AT command */
    kal_char 	*source_string_copy = NULL;/* uing to duplicate this stinng so that we can copy to our RMMI context*/
    char cmd_name[15];
    kal_uint8 index = 3; // we start parsing index after the CUSTOM_SYMBOL 
    kal_uint8 tmp_idx = 0;    

    kal_trace(TRACE_FUNC, FUNC_DT_CMD_PROCESSOR_ENTRY);
    ASSERT (source_string_ptr != NULL);

    /***********************************************/
    /* here we check: AT command should have prefix "AT" */
	
    /* skip none 'A' or 'a' character before CR form UART */
    dt_skip_none_a(source_string_ptr,cmd_length);

    /* skip not "AT" */
    while ( source_string_ptr->string_ptr[source_string_ptr->index+1] != dt_char_t && 
   	  	   source_string_ptr->string_ptr[source_string_ptr->index+1] != DT_CHAR_T && 
   	  	     source_string_ptr->index < cmd_length )
    {
         source_string_ptr->index+=2;/* skip to the next next index ex: a~~~at */
         dt_skip_none_a(source_string_ptr,cmd_length);
    }    

    /* count actual length which start from "AT" */
    actual_length = cmd_length - source_string_ptr->index; 

    //mtk00468 040411 add to fixed stack overflow when uart had transfer to L4C but PC send lots of data to MS
    if (actual_length <2)
        return;
    
    //memory allocate for source string copy
    ASSERT(actual_length+1 <2048);

    source_string_copy = get_ctrl_buffer(actual_length+1);/* additional 1 byte for NULL terminated */
  
    /* copy content to source_string_copy: the full command string starts from "AT", ex: "AT+CGATT=?;+CREG?<CR>" */
    kal_mem_cpy(source_string_copy, &source_string_ptr->string_ptr[source_string_ptr->index], actual_length);
    source_string_copy[actual_length]='\0';     /* add NULL terminate */

    /* debug information */
    kal_trace(TRACE_GROUP_3, DT_AT_CMD_STRING, source_string_copy[0],source_string_copy[1],
											   source_string_copy[2],source_string_copy[3],
											   source_string_copy[4],source_string_copy[5],
											   source_string_copy[6],source_string_copy[7],
											   source_string_copy[8],source_string_copy[9],
											   source_string_copy[10],source_string_copy[11]);
    //kal_print((kal_char*)source_string_copy);    
    //index = strcspn((kal_char *)source_string_copy, ";");

    kal_mem_cpy((kal_uint8 *)source_string_ptr->string_ptr, 
	    	    (kal_uint8 *)source_string_copy, strlen(source_string_copy)*sizeof(kal_uint8)+1);
    source_string_ptr->index = 0;

    if(source_string_copy != NULL)
    {
    	free_ctrl_buffer(source_string_copy);
    }
	
    //process AT and return OK
    if((source_string_ptr->string_ptr[source_string_ptr->index] == dt_char_a ||
    	source_string_ptr->string_ptr[source_string_ptr->index] == DT_CHAR_A)
    	&&(source_string_ptr->string_ptr[source_string_ptr->index+1] == dt_char_t ||
    	source_string_ptr->string_ptr[source_string_ptr->index+1] == DT_CHAR_T)
    	&&(source_string_ptr->string_ptr[source_string_ptr->index+2] == DT_PTR->s_reg.s3))    
    {
	dt_result_code_fmttr (DT_RCODE_OK, DT_NO_ERR);
	return;
    }

    while ((source_string_ptr->string_ptr[index] != '=' ) &&  //might be TEST command or EXE command
			(source_string_ptr->string_ptr[index] != '?' ) && // might be READ command
			(source_string_ptr->string_ptr[index] != 13 ) &&
			(source_string_ptr->string_ptr[index] != DT_SPACE ))  //carriage return
    {
		cmd_name[tmp_idx] = source_string_ptr->string_ptr[index] ;
		tmp_idx ++;
		index ++;
    }
    cmd_name[tmp_idx] = '\0' ;

    while ( ( source_string_ptr->string_ptr[source_string_ptr->index]
            != DT_EQUAL ) &&
            ( source_string_ptr->string_ptr[source_string_ptr->index]
            != DT_QUESTION_MARK ) &&
            ( source_string_ptr->string_ptr[source_string_ptr->index]
            != DT_COMMA) &&
            ( source_string_ptr->string_ptr[source_string_ptr->index]
            != DT_PTR->s_reg.s3 ) &&
            ( source_string_ptr->string_ptr[source_string_ptr->index]
            != DT_PTR->s_reg.s4 ))
    {
    		source_string_ptr->index ++;
    }

    source_string_ptr->cmd_mode = dt_find_cmd_mode ( source_string_ptr );
	
    if (strcmp(cmd_name, "EFSW") == 0)
    {		
    	dt_efsw_hdlr(source_string_ptr);    
    }
    else if (strcmp(cmd_name, "EFSR") == 0)
    {
    	dt_efsr_hdlr(source_string_ptr);
    }
    else if (strcmp(cmd_name, "EMDY") == 0)
    {
    	dt_emdy_hdlr(source_string_ptr);    
    }
    else if (strcmp(cmd_name, "EIMG") == 0)
    {
    	dt_eimg_hdlr(source_string_ptr);    
    }	
    else
    {
       /* unrecognized command */
       kal_trace(TRACE_ERROR, ERROR_DT_INVALID_CMD);   
	kal_print((kal_char*)source_string_copy);
	
	if(DT_PTR->transfer_state != DT_IDLE_STATE)
	{
		/*ingore invalid command when UPLOAD or DOWNLOAD*/
		kal_trace(TRACE_INFO, INFO_DT_CURRENT_STATE, DT_PTR->transfer_state);				
	}
	else		
	{
		/*otherwise, return ERROR when state is IDLE*/
    		dt_result_code_fmttr (DT_RCODE_ERROR, DT_ERR_INVALID_CMD);
	}
    }
    

    return;
}



/*****************************************************************************
* FUNCTION
*  dt_process_one_cmd
*
* DESCRIPTION
*   This is dt_process_one_cmd function of L4C module.
*   detect CR to identify a full cmd line and then process
*   that line of at cmd
*
* PARAMETERS
*  none.
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_process_one_cmd (void)
{
   kal_bool full_cmd = KAL_FALSE;
   kal_uint16 i, j, index;
   dt_string_struct temp_struct;

   kal_trace(TRACE_FUNC, FUNC_DT_PROCESS_ONE_CMD_ENTRY);

#if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __BTVCSR_HP__ /* bluetooth : 2 physical uart */
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef l4c_autobaud
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

   /* skip the beginnig Null terminaters (PC always throw a lot Null when query the modem. */
   for (i=0; i<DT_PTR->uart_input_queue.length; i++)
   {
      	index = (DT_PTR->uart_input_queue.head + i) % DT_MAX_DATA_INPUT_QUEUE_LENGTH ;
	if (DT_PTR->uart_input_queue.data[index] != DT_END_OF_STRING_CHAR
	&& DT_PTR->uart_input_queue.data[index] != 13
	&& DT_PTR->uart_input_queue.data[index] != 10)
		break; //we found the first charactor.
   }
   
   DT_PTR->uart_input_queue.head =
            (DT_PTR->uart_input_queue.head+i) % DT_MAX_DATA_INPUT_QUEUE_LENGTH;
   DT_PTR->uart_input_queue.length -= i;
   
   for (i=0; i<DT_PTR->uart_input_queue.length; i++)
   {
      index = (DT_PTR->uart_input_queue.head + i) % DT_MAX_DATA_INPUT_QUEUE_LENGTH ;
      if ((DT_PTR->uart_input_queue.data[index] == 13) ||
          (DT_PTR->uart_input_queue.data[index] == 10))
      	{
	         i++;
	         full_cmd = KAL_TRUE;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef  __BTVCSR_HP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __BTVCSR_HP__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef  __BTVCSR_HP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


   if (full_cmd == KAL_TRUE)
   {
      if (i <= 1)
      {
         DT_PTR->uart_input_queue.head =
            (DT_PTR->uart_input_queue.head+i) % DT_MAX_DATA_INPUT_QUEUE_LENGTH;
         DT_PTR->uart_input_queue.length -= i;
         return;
      }
      temp_struct.index = 0;
      ASSERT(i+1 <2048);
      temp_struct.string_ptr = get_ctrl_buffer((kal_uint16)(i+1));

      kal_mem_set (temp_struct.string_ptr, 0, sizeof (kal_uint8) * (i+1));

      for (j=0; j<i-1; j++)
      {
         temp_struct.string_ptr[j] =
                     DT_PTR->uart_input_queue.data
                           [(DT_PTR->uart_input_queue.head+j) % DT_MAX_DATA_INPUT_QUEUE_LENGTH];
      }
      temp_struct.string_ptr[i-1] = DT_PTR->s_reg.s3;
      DT_PTR->uart_input_queue.head =
            (DT_PTR->uart_input_queue.head+i) % DT_MAX_DATA_INPUT_QUEUE_LENGTH ;
      DT_PTR->uart_input_queue.length -= i;

      temp_struct.src_id = 0xff/*src_id*/;
//#ifdef  __BTVCSR_HP__
//	if (cid == 1)
//		 DT_PTR->BT_port = KAL_TRUE;
//	else
//		 DT_PTR->BT_port = KAL_FALSE;
//#endif
      dt_cmd_processor (&temp_struct, i);
//#ifdef __BTVCSR_HP__
//	if (DT_PTR->BT_port == KAL_TRUE)
//   		DT_PTR->BT_port = KAL_FALSE;
//#endif
      free_ctrl_buffer (temp_struct.string_ptr);
   }
   return;
}

