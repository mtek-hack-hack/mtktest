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
 *	dt_rspfmttr.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
*****************************************************************************/

#define DT_RSPFMTTR_C

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

#include "dt_trc.h"

#include "uart_sw.h"
#include "dt_common_enum.h"
#include "dt_context.h"

#include "dt_utility.h"
#include "dt_rspfmttr.h"

extern void UART_ClrRxBuffer(UART_PORT port, module_type ownerid);
extern void UART_ClrTxBuffer(UART_PORT port, module_type ownerid);
extern int UART_GetOwnerID(UART_PORT port);
/*****************************************************************************
* FUNCTION
*  dt_uart_send_data
*
* DESCRIPTION
*   This is dt_uart_send_data function of L4C module.
*   pass data from rmmi output queue to uart
*
* PARAMETERS
*  none.
*
* RETURNS
*  count    number of bytes sent to uart
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
kal_uint16 dt_uart_send_data (kal_uint8 port)
{
   kal_uint16 result;
   kal_uint16 temp;
   kal_uint16 len;

#ifndef UART_ENABLE
   FILE *output;
#endif
   kal_trace(TRACE_FUNC, FUNC_DT_UART_SEND_DATA_ENTRY);

   len = DT_PTR->uart_output_queue.length;

   if ((DT_PTR->uart_output_queue.head + len) > DT_MAX_DATA_OUTPUT_QUEUE_LENGTH)
   {
      temp = DT_MAX_DATA_OUTPUT_QUEUE_LENGTH - DT_PTR->uart_output_queue.head;

#ifdef UART_ENABLE
      result = DT_UART_PutBytes (port,
                              &(DT_PTR->uart_output_queue.data
                              [DT_PTR->uart_output_queue.head]), temp, MOD_DT);
#else
      output = fopen ("c:\\mcu_out.log", "a");
      result = fprintf (output, "%s",
      DT_PTR->uart_output_queue.data+DT_PTR->uart_output_queue.head);

#endif /* UART_ENABLE */

      len -= temp;

#ifdef UART_ENABLE
	if(result<temp)
	{
	      DT_PTR->uart_output_queue.head += result;
	      DT_PTR->uart_output_queue.length -= result;
	      return result;
	}
      result += DT_UART_PutBytes (port,
                               DT_PTR->uart_output_queue.data, len,MOD_DT);
#else
      result += fprintf (output, "%s", DT_PTR->uart_output_queue.data);
      fclose (output);
#endif /* UART_ENABLE */

      DT_PTR->uart_output_queue.head =
      		(DT_PTR->uart_output_queue.head + result) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH ;
      DT_PTR->uart_output_queue.length -= result;
   }
   else
   {
#ifdef UART_ENABLE
      result = DT_UART_PutBytes (port,
                              &(DT_PTR->uart_output_queue.data
                              [DT_PTR->uart_output_queue.head]),
                           len, MOD_DT);
#else
      output = fopen ("c:\\mcu_out.log", "a");
      result = fprintf (output, "%s",
         DT_PTR->uart_output_queue.data+DT_PTR->uart_output_queue.head);
      fclose (output);
#endif /* UART_ENABLE */

      DT_PTR->uart_output_queue.head += result;
      DT_PTR->uart_output_queue.length -= result;
   }
   return result;
}


void dt_uart_write_data(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff, kal_uint8 cid, kal_uint8 port)
{
   	kal_uint16 i;
   	kal_uint16 tail;
   	kal_uint16 temp;
   	kal_uint16 actual_write;

	kal_trace(TRACE_FUNC, FUNC_DT_UART_WRITE_DATA_ENTRY);
	
   	/* we will clear our uart queue if we can not write to rmmi queue */
   	if(DT_MAX_DATA_OUTPUT_QUEUE_LENGTH - DT_PTR->uart_output_queue.length <= length)
   	{
#ifdef UART_ENABLE
		kal_print("RMMI: ClrTxBuffer");
      		DT_UART_ClrTxBuffer(port, MOD_DT);
#endif
     		DT_PTR->uart_output_queue.head = 0;
     		DT_PTR->uart_output_queue.length = 0;
   	}
   	tail = (DT_PTR->uart_output_queue.head +
           	DT_PTR->uart_output_queue.length) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH ;

   	if (stuff == KAL_TRUE)
   	{
            //for module: Maui_sw 9943
   	    if(DT_PTR->rsp_mode.format != DT_NUM_PARTIAL_HEAD_TAIL) 
            {
      		DT_PTR->uart_output_queue.data
            		[(tail+0)% DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = DT_PTR->s_reg.s3;
      		DT_PTR->uart_output_queue.data
            		[(tail+1) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = DT_PTR->s_reg.s4;

	      for (i=0; i<length; i++)
	      {
	         DT_PTR->uart_output_queue.data
	            [(tail+2+i) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = *((kal_uint8 *)buffer+i);
	      }

	      DT_PTR->uart_output_queue.data
	            [(tail+2+length) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = DT_PTR->s_reg.s3;
	      DT_PTR->uart_output_queue.data
	            [(tail+3+length) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = DT_PTR->s_reg.s4;

	      DT_PTR->uart_output_queue.length += 4;
   	    }
   	    else
            { //for module: Maui_sw 9943
	    	for (i=0; i<length; i++)
	      {
	         DT_PTR->uart_output_queue.data
	            [(tail+i) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = *((kal_uint8 *)buffer+i);
	      }

	      DT_PTR->uart_output_queue.data
	            [(tail+0+length) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = DT_PTR->s_reg.s3;
#ifdef __WINCE__
	      //RMMI_PTR->uart_output_queue[cid].data
	      //      [(tail+1+length) % MAX_DATA_QUEUE_LENGTH] = RMMI_PTR->s_reg.s4;

	      (DT_PTR->uart_output_queue.length) ++;
#else
	      DT_PTR->uart_output_queue.data
	            [(tail+1+length) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = DT_PTR->s_reg.s4;

	      DT_PTR->uart_output_queue.length += 2;
#endif	    
	    }//for module: Maui_sw 9943
   	}
   	else
   	{
      		for (i=0; i<length; i++)
	      {
	         DT_PTR->uart_output_queue.data
	            [(tail+i) % DT_MAX_DATA_OUTPUT_QUEUE_LENGTH] = *((kal_uint8 *)buffer+i);
	      }
   	}
   	DT_PTR->uart_output_queue.length += length;

   	//if ((DT_PTR->uart_stop_send_flag & (0x01 << cid)) == 0)
	if(DT_PTR->uart_stop_send_flag == KAL_FALSE)   	
   	{
      		temp = DT_PTR->uart_output_queue.length;
      		actual_write = dt_uart_send_data(port);
      		if (actual_write < temp)
      		{
         		//DT_PTR->uart_stop_send_flag |= (0x01 << cid);
         		DT_PTR->uart_stop_send_flag = KAL_TRUE;
         		
      		}
   	}

   	return;
}


/*****************************************************************************
* FUNCTION
*  dt_write_to_uart
*
* DESCRIPTION
*   This is dt_write_to_uart function of L4C module.
*   continue write until uart has no available space
*   or rmmi output queue is empty
*
* PARAMETERS
*  buffer      IN    data to be write to uart
*  length      IN    number of bytes to be write to uart
*  stuff       IN    need to pad CR & LF in front and back of data or not
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_write_to_uart (kal_uint8 *buffer, kal_uint16 length, kal_bool stuff)
{
   //kal_uint8 port;
   kal_uint8 cid= 0;

   kal_trace(TRACE_FUNC, FUNC_DT_WRITE_TO_UART_ENTRY);
#if 0
#ifdef __SATC3__
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   if(UART_GetOwnerID(DT_PTR->transfered_port) != MOD_DT)
   {
	 kal_trace(TRACE_ERROR, ERROR_DT_UART_OWNER_IS_NOT_DT);
	 return;
   }

   dt_uart_write_data(buffer, length, stuff, cid, DT_PTR->transfered_port);
}



/*****************************************************************************
* FUNCTION
*  dt_read_from_uart
*
* DESCRIPTION
*   This is dt_read_from_uart function of L4C module.
*   calculate available space in rmmi input queue for
*   reading data from uart, continue read until no space
*   or uart has no more data
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
void dt_read_from_uart (kal_uint8 port)
{
   kal_uint16 space;
   kal_uint16 actual_read=0;
   kal_uint16 temp_read = 0; /* to print more detail trace information */

   kal_trace(TRACE_FUNC, FUNC_DT_READ_FROM_UART_ENTRY);

   if (port == uart_port_null)
      return;
   
   DT_PTR->transfered_port = port;//mtk00924_051021
   
//   if (RMMI_PTR->cmux_enable == KAL_FALSE)
//   {
	  if(UART_GetOwnerID(port) != MOD_DT)
	  {
	  	kal_trace(TRACE_ERROR, ERROR_DT_UART_OWNER_IS_NOT_DT);
      	 	return;
	  }
// }

//#ifdef __BTVCSR_HP__
//   /* we do not allow the other channel when BT is used as serial port ,
//       Note that we do not read data from UART here, so we have to clear the RX buffer
//       when BT is no longer used as serial port : rmmi_bt_crfcstat_hdlr */
//   if ((RMMI_PTR->BT_as_serial_port == KAL_TRUE) && (port != PS_UART_PORT))
//   	return;
//#endif

// cid = rmmi_port_2_cid(port);
// ASSERT(cid != 0xff);

   space = DT_MAX_DATA_INPUT_QUEUE_LENGTH - DT_PTR->uart_input_queue.length;
   while (space > 0)
   {
      temp_read += actual_read ;/* only to print more detail trace information */
      if (space > DT_MAX_UART_LENGTH)
      {
         actual_read = dt_uart_read_data (port, DT_MAX_UART_LENGTH);
         if (actual_read < DT_MAX_UART_LENGTH)
            break;
      }
      else
      {
         actual_read = dt_uart_read_data (port , space);
         if (actual_read < space)
            break;
      }
      space = DT_MAX_DATA_INPUT_QUEUE_LENGTH - DT_PTR->uart_input_queue.length;
   }

   space = DT_MAX_DATA_INPUT_QUEUE_LENGTH - DT_PTR->uart_input_queue.length;
   temp_read += actual_read ;/* to print more detail trace information */
   {
#ifdef UART_ENABLE
   	extern kal_uint8 send_Rxilm[2];
   	kal_trace (TRACE_INFO, INFO_DT_INPUT,
      				DT_PTR->uart_input_queue.length, space, temp_read,
			      send_Rxilm[port]);
#endif
   }

   if ((space == 0) ||
       (DT_PTR->uart_input_queue.length == DT_MAX_DATA_INPUT_QUEUE_LENGTH))
   {
   	kal_print("Warning: DT uart_input_queue Full!");
   	/* mtk00714: the data of +CMGS,+CMGW should not be too long. force to abort the short message */

#if 0   	
/* under construction !*/
/* under construction !*/
 #ifdef __BTVCSR_HP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef UART_ENABLE
      DT_UART_ClrRxBuffer(port, MOD_DT);
#endif
      	DT_PTR->uart_input_queue.length = 0;
	DT_PTR->uart_input_queue.head = 0;
   }
   return;
}


/*****************************************************************************
* FUNCTION
*  dt_uart_read_data
*
* DESCRIPTION
*   This is dt_uart_read_data function of L4C module.
*   get data from uart to rmmi input queue
*
* PARAMETERS
*  none.
*
* RETURNS
*  count    number of bytes read from uart
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
kal_uint16 dt_uart_read_data (kal_uint8 port, kal_uint16 len)
{
   	kal_uint16 result;
   	kal_uint16 tail;
   	kal_uint16 i;
   	kal_uint8 buffer[DT_MAX_UART_LENGTH];

#ifndef UART_ENABLE
   	FILE *input;
#endif

   	kal_trace(TRACE_FUNC, FUNC_DT_UART_READ_DATA_ENTRY);

#ifdef UART_ENABLE
	/* here's we really read the data from UART*/
   	result = DT_UART_GetBytes (port, (kal_uint8 *)buffer, len, NULL, MOD_DT);
#else
   	input = fopen ("c:\\mcu_in.log", "r");
   	fgets ((kal_char *)buffer, len, input);
   	result = strlen ((kal_char *)buffer);
   	fclose (input);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
#endif
//#ifdef __BTVCSR_HP__
//	/* When Bluetooth is on,
//		if (cid==1), the data is write to bluetooth port.
//		if (cid==0), the data is write to PS UART PORT. */
//	if (cid == 1)
//	   	DT_PTR->BT_port = KAL_TRUE;
//	else
//	   	DT_PTR->BT_port = KAL_FALSE;
//#endif

   for (i=0; i<result; i++)
   {
      if (buffer[i] == DT_PTR->s_reg.s5)
      {
	      // Backspace :
	      // we have to check uart_input_queue length.
	      // if there's nothing in uart_input_queue (length == 0),
	      // then Backspace is ignored.
	      if (DT_PTR->uart_input_queue.length > 0)
	      	{
     			DT_PTR->uart_input_queue.length--;
		      	if ((DT_PTR->rsp_mode.echo_flag /*& (0x01 << cid)*/))
			{   	dt_write_to_uart(&buffer[i], 1, KAL_FALSE);}
	      	}
      }
#ifdef __BT_SUPPORT__     
      else
#else      	
      else if((buffer[i]>=0x0a)&&(buffer[i]<0x80)) //for module: Maui_sw 9943
#endif
      {
      		// Other charactors except Backspace

      		//generate echo
		if ((DT_PTR->rsp_mode.echo_flag /*& (0x01 << cid)*/))
		{   	dt_write_to_uart(&buffer[i], 1, KAL_FALSE);}

		//put the char in uart_input_queue
		tail = (DT_PTR->uart_input_queue.head +
		           DT_PTR->uart_input_queue.length) % DT_MAX_DATA_INPUT_QUEUE_LENGTH ;
         	DT_PTR->uart_input_queue.data[tail] = buffer[i];
         	DT_PTR->uart_input_queue.length++;
      }
   }


//#ifdef __BTVCSR_HP__
//	if (DT_PTR->BT_port == KAL_TRUE)
//   		DT_PTR->BT_port = KAL_FALSE;	//clear the Bluetooth information

	/* begin: only for debugging */
	//uart 3 : we copy BT chip command to uart 1 for debugging
//	#ifdef __RMMI_BT_DEBUG__
//	if ((cid == 1) && (DT_PTR->BT_as_serial_port == KAL_FALSE))
//	{
//   		for (i=0; i<result; i++)
//   		{
//	   		rmmi_write_to_uart(&buffer[i], 1, KAL_FALSE);
// 		}
//	}
//	#endif
	/* end : only for debugging */
//#endif

   return result;
}


kal_uint16  dt_fast_string_print (
                                   kal_uint8 *buff_ptr,
                                   kal_uint8  *fmt,
                                   void *arg_list[],
                                   kal_uint8 nos_arg
                                  )
{
    kal_int32   digit = 0;
    // kal_int16   digit = 0;
    kal_uint8   character;
    kal_uint8   dec_val[15];
    /* array to store decimal number in the form of string */
    //kal_uint8   *str_ptr;
    kal_uint8   index = 0;
    kal_uint16   buffer_length = 0;
    kal_uint8   arg_indx = 0;
    kal_bool    int_str_ptr_flag = KAL_FALSE;
    kal_bool    negative_flag  = KAL_FALSE;

    kal_trace(TRACE_FUNC, FUNC_DT_FAST_STRING_PRINT_ENTRY);
    while( *fmt )
    {
      /* store into the buffer if we find any non '%' character */
      if (*fmt != DT_CHAR_PERCENT || nos_arg == 0)
      {
        /*increment the buffer index and input string index by one*/
        *buff_ptr++ = *fmt++;
        buffer_length++;
        continue;
      }

      /* If we find '%' character then we require to see for
       * corresponding conversion specifier like d (for integer)
       *                                        c (for character )
       *                                        s (for string )
       * this is analyzed using switch - case  statement */
      switch ( *++fmt )
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
/* under construction !*/
/* under construction !*/
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
        /* String print a kal_uint16 type variable */
        case dt_char_u  :
        {
          /* Get the integer value from the string format */
          digit = *((kal_uint16 *)arg_list[arg_indx++]);
          int_str_ptr_flag = KAL_TRUE;
          break;
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
#endif
        /* String print a kal_uint8 type variable */
        case dt_char_d  :
        {
          /* Get the integer value from the string format */
          digit = *((kal_uint8 *)arg_list[arg_indx++]);
          int_str_ptr_flag = KAL_TRUE;
          break;
        }

        case dt_char_c  :
        {
          /* get the character from the given string format */
          character = *((kal_uint8 *)arg_list[arg_indx++]);

          /* update the buffer */
          *buff_ptr++ = character;
          buffer_length++;
          break;
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
#endif
        default   :
        {
         /* if no conversion specifier is found  after '%' character
          * store that character as it is  in to the buffer  */
          *buff_ptr++ = *fmt;
          buffer_length++;
          break;
        }
      } /* end switch */

      if( int_str_ptr_flag == KAL_TRUE )
      {
        if (digit < 0)
        {
          negative_flag = KAL_TRUE;
          digit = digit *( -1);
        }

        dt_int_to_ascii_converter ( digit, dec_val );
                                  /*convert the integer into string*/
        index = 0;
        /* store converted decimal value into the buffer */
        if (  negative_flag == KAL_TRUE )
        {
          *buff_ptr++ = DT_CHAR_MINUS;
          buffer_length++;
        }

        while(dec_val[index] != DT_END_OF_STRING_CHAR)
        {
          *buff_ptr++ = dec_val[index++];
          buffer_length++;
        }
        int_str_ptr_flag = KAL_FALSE;
      }

      fmt++;
    }

      /* finish string with \0 */
      *buff_ptr = *fmt;
/*
    SME_FN_EXIT_LOG(
                    MOD_ATCI,
                     ATCI_FUNC_ATCIFASTSTRINGPRINT_EXIT_SUBOP
                   );
*/
      return buffer_length;
}



/*****************************************************************************
* FUNCTION
*  dt_result_code_fmttr
*
* DESCRIPTION
*  Spec 07.07 Sec 9.2
* PARAMETERS
*  kal_uint8	rsp_type :  rmmi_rsp_type_enum
*  kal_uint16  cause : rmmi_err_id_enum
* RETURNS
*  none.
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_result_code_fmttr(kal_uint8 rsp_type, kal_uint16 cause)
{
   kal_uint8 buffer[DT_MAX_UART_LENGTH];
   kal_uint16 string_length = 0;
//   kal_uint8 cid;

	kal_trace(TRACE_FUNC, FUNC_DT_RESULT_CODE_FMTTR_ENTRY);

	if(DT_PTR->transfered_port == 0xff)
	{
		kal_trace(TRACE_ERROR, ERROR_DT_UART_OWNER_IS_NOT_DT);
		return;
	}
	
   	if (rsp_type != DT_RCODE_ERROR)
   		kal_trace(TRACE_GROUP_3, DT_RESULT_CODE_FMTTR, rsp_type);
   	else
		kal_trace(TRACE_GROUP_3, DT_RESULT_CODE_ERROR, rsp_type, cause);

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
   switch (rsp_type)
   {
      case DT_RCODE_OK:


         //if (DT_PTR->rsp_mode.format == DT_NUM_PARTIAL_HEAD_TAIL)
         //{
         //   DT_PTR->arg_list[0] = (void *)&rsp_type;
         //   string_length = dt_fast_string_print (
         //                           buffer,
         //                           (kal_uint8 *)"%d",
         //                           DT_PTR->arg_list,
         //                           1
         //                          );
         //}
         //else
         //{
            string_length = dt_fast_string_print (
                                    buffer,
                                    (kal_uint8 *)"OK",
                                    DT_PTR->arg_list,
                                    0
                                   );
         //}
         break;

      case DT_RCODE_ERROR:

         //if (DT_PTR->error_report_mode == DT_SIMPLE_ERROR)
         //{
         //   if (DT_PTR->rsp_mode.format == DT_NUM_PARTIAL_HEAD_TAIL)
         //   {
         //      DT_PTR->arg_list[0] = (void *)&rsp_type;
         //      string_length = dt_fast_string_print (
         //                           buffer,
         //                           (kal_uint8 *)"%d",
         //                           DT_PTR->arg_list,
         //                           1
         //                          );
         //   }
         //   else
         //   {
               string_length = dt_fast_string_print (
                                    buffer,
                                    (kal_uint8 *)"ERROR",
                                    DT_PTR->arg_list,
                                    0
                                   );
          //  }
          //}
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
/* under construction !*/
/* under construction !*/
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
//	  if (cid < RMMI_MAX_CHANNEL_NUMBER)
//	  {
#ifdef UART_ENABLE
//   		kal_uint8 port;
//	        port = rmmi_cid_2_port(cid);
         DT_UART_ClrRxBuffer (DT_PTR->transfered_port, MOD_DT);
#endif
         	DT_PTR->uart_input_queue.head = 0;
         	DT_PTR->uart_input_queue.length = 0;
//	  }
         break;

      default:
         break;

   }

#if 0
#ifdef __SATC3__ // mtk00714 : __SATC3__
/* under construction !*/
#endif/* __SATC3__ */
#endif
   dt_write_to_uart((kal_uint8 *)buffer, string_length, KAL_TRUE);
#if 0
#ifdef __BTVCSR_HP__
/* under construction !*/
/* under construction !*/
#endif
#endif
   return;
}



/*****************************************************************************
* FUNCTION
*  dt_final_rsp_generator
* DESCRIPTION
*  the function generates the information response and final result code to DTE.
* PARAMETERS
*  kal_uint8 	src_id : l4c_source_enum (channel)
*  kal_bool	ret_val :  OK/ERROR
*  kal_uint8* 	buffer
*  kal_uint8	string_length:  the length of buffer.
* RETURNS
*  none.
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_final_rsp_generator(kal_uint8 src_id, kal_bool ret_val, kal_uint8* buffer, kal_uint16 string_length)
{
    if (ret_val == KAL_TRUE)
    {
    	if(string_length>0)
    	{
        	dt_write_to_uart((kal_uint8 *)buffer, string_length, KAL_TRUE);
    	}
        dt_result_code_fmttr (DT_RCODE_OK, DT_NO_ERR);
    }
    else
    {
        dt_result_code_fmttr(DT_RCODE_ERROR, DT_PTR->cmee_err);
        DT_PTR->cmee_err = DT_ERR_UNSPECIFIED;  //back to initial value.
    }
}


#ifdef DATA_DOWNLOAD
/******************************************************************
 * FUNCTION
 *    dt_eq_fs_read_rrsp
 * DESCRIPTION
 *    This function is used to handle the response of reading download files from MT.
 * PARAMETERS
 *
 * RETURNS
 *
 * GLOBALS AFFECTED
 *
 ******************************************************************/
void dt_eq_fs_read_rrsp( kal_uint8 * download_ptr,dt_app_type_enum app_type,kal_uint32 length,
										kal_uint8 eof_flag, kal_uint16 loop)
{
#if !(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))
       kal_uint16 string_length;
   	kal_uint8 buffer[DT_SHORT_RSP_LEN];
	kal_uint32 i; //using to convert each element in *data byte stream
	kal_char  buff[512]; //using to store the hex character and end of string character
	kal_uint32 out_len; //using to keep write len
	kal_uint32 offset=0;
	kal_uint16 data_len;
	kal_uint8 data1;
       kal_uint8 data2;

	kal_trace(TRACE_FUNC, FUNC_DT_EQ_READ_RRSP_ENTRY);

	out_len = length;
	if(out_len==0) /* only possible when eof_flag=1 */
	{
		DT_PTR->arg_list[0] = (void *)&loop;
	       DT_PTR->arg_list[1] = (void *)&eof_flag;

	    	if(app_type == DT_IMAGE)
	    	{
	       	string_length = dt_fast_string_print (
				        	buffer,
				        	(kal_uint8 *)"+EIMG: %u, %d, 0",
				        	DT_PTR->arg_list,
				        	2
				        	);
	    	}
		else if((app_type == DT_IMELODY)||(app_type == DT_SOUND_OTHER))
		{
			string_length = dt_fast_string_print (
				        	buffer,
				        	(kal_uint8 *)"%c%c+EMDY: %u, %d, 0",
				        	DT_PTR->arg_list,
				        	2
				        	);
		}
		else
		{
			string_length = dt_fast_string_print (
				        	buffer,
				        	(kal_uint8 *)"%c%c+EFSR: %u, %d, 0",
				        	DT_PTR->arg_list,
				        	2
				        	);
		}
		
		dt_write_to_uart((kal_uint8 *)buffer, string_length, KAL_TRUE);

	}
	
	while (out_len >0 )
	{
		 if(out_len<=DT_DOWNLOAD_SIZE)//cage_read
		 {
			data_len=out_len;
		 }
		 else		//each +EIMG or +EMDY print at most 64 bytes
		 {
		 	data_len=DT_DOWNLOAD_SIZE;//cage_read
		 }
 		 DT_PTR->arg_list[0] = (void *)&DT_PTR->s_reg.s3;
 		 DT_PTR->arg_list[1] = (void *)&DT_PTR->s_reg.s4;
		 DT_PTR->arg_list[2] = (void *)&loop;
	        DT_PTR->arg_list[3] = (void *)&eof_flag;
	        DT_PTR->arg_list[4] = (void *)&data_len;

		 if(app_type == DT_IMAGE)
		 {
	       		string_length = dt_fast_string_print (
					        	buffer,
					        	(kal_uint8 *)"%c%c+EIMG: %u, %d, %u, \"",
					        	DT_PTR->arg_list,
					        	5
					        	);
		 }
		else if((app_type == DT_IMELODY)||(app_type == DT_SOUND_OTHER))
		{
				string_length = dt_fast_string_print (
					        	buffer,
					        	(kal_uint8 *)"%c%c+EMDY: %u, %d, %u, \"",
					        	DT_PTR->arg_list,
					        	5
					        	);
		}
		else
		{
				string_length = dt_fast_string_print (
					        	buffer,
					        	(kal_uint8 *)"%c%c+EFSR: %u, %d, %u, \"",
					        	DT_PTR->arg_list,
					        	5
					        	);
		}
		
		dt_write_to_uart((kal_uint8 *)buffer, string_length, KAL_FALSE);

		for (i=offset; i<(offset+DT_DOWNLOAD_SIZE); i++) //transfer each byte into hex string, each time print at most 64 bytes//cage_read
	   	{
	   		if( i==length) break;

	   		data1 = (download_ptr[i] & 0xF0) >> 4;
			data2 = (download_ptr[i] & 0x0F);

			if(data1 <= 9)      
			 	data1 += 0x30;
			else if((data1 >= 0xA) && (data1 <= 0xF))      
			   	data1 += 0x37;

			if(data2 <= 9)      
			   	data2 += 0x30;
			else if((data2 >= 0xA) && (data2 <= 0xF))      
			   	data2 += 0x37;

                     buff[2*i]=data1;
                     buff[2*i+1]=data2;
	      		out_len--;
   		}
	
                dt_write_to_uart((kal_uint8 *)buff, (kal_uint16)(length*2), KAL_FALSE); 

		offset=i;
	   	DT_PTR->arg_list[0] = (void *)&DT_PTR->s_reg.s3;
		DT_PTR->arg_list[1] = (void *)&DT_PTR->s_reg.s4;
     		string_length = dt_fast_string_print (buffer,
									        (kal_uint8 *)"\"%c%c",
									        DT_PTR->arg_list,
									        2
									        );
    		
	      dt_write_to_uart((kal_uint8 *)buffer, string_length, KAL_FALSE);
	}
#endif
}

#endif /* DATA_DOWNLOAD*/

