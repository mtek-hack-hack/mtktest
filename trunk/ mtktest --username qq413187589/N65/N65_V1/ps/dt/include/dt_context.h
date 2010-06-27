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
 * Filename:
 * ---------
 *	dt_context.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DT global context.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef _DT_CONTEXT_H
#define _DT_CONTEXT_H

#define DT_UART_SetOwner UART_SetOwner
#define DT_UART_GetBytes UART_GetBytes
#define DT_UART_PutBytes UART_PutBytes
#define DT_UART_ClrTxBuffer UART_ClrTxBuffer
#define DT_UART_ClrRxBuffer UART_ClrRxBuffer



//#ifdef DATA_DOWNLOAD
#include "fat_fs.h"

//#define DT_IMELODY_DIR L"c:\\USER\\sound\\imelody"
//#define DT_SOUND_OTHER_DIR L"c:\\USER\\sound\\other"
//#define DT_IMAGE_DIR L"c:\\USER\\image\\standard"

//#endif/* DATA_DOWNLOAD */


#define dt_skip_spaces(source_string_ptr)                               \
      while( source_string_ptr->string_ptr[ source_string_ptr->index ]    \
                                 == DT_SPACE )                          \
      {                                                                   \
        source_string_ptr->index++;                                          \
      }

#define dt_skip_none_a(source_string_ptr, length)                               \
      while( (source_string_ptr->index < length) && !((source_string_ptr->string_ptr[ source_string_ptr->index ] == DT_CHAR_A) ||\
             (source_string_ptr->string_ptr[ source_string_ptr->index ] == dt_char_a)) ) \
      {                                                                   \
        source_string_ptr->index++;                                          \
      }

#define DT_IS_LOWER( alpha_char )   \
  ( ( (alpha_char >= dt_char_a) && (alpha_char <= dt_char_z) ) ?  1 : 0 )

#define DT_IS_UPPER( alpha_char )   \
   ( ( (alpha_char >= DT_CHAR_A) && (alpha_char <= DT_CHAR_Z) ) ? 1 : 0 )      
#define DT_IS_NUMBER( alpha_char )   \
   ( ( (alpha_char >= DT_CHAR_0) && (alpha_char <= DT_CHAR_9) ) ? 1 : 0 )

#define DT_IS_ALPHA( alpha_char )   \
   ( ( DT_IS_UPPER(alpha_char) || DT_IS_LOWER(alpha_char) ) ? 1 : 0 )

#define DT_IS_SYMBOL( alpha_char )   \
   ( ( (alpha_char == DT_CHAR_PLUS) || (alpha_char == DT_CHAR_STAR) || \
       (alpha_char == DT_CHAR_POUND) || (alpha_char == DT_COMMA) || \
       (alpha_char == DT_CHAR_DOT) || (alpha_char == DT_FORWARD_SLASH) || \
       (alpha_char == DT_COLON) || (alpha_char == DT_HAT) || \
       (alpha_char == DT_CHAR_MINUS) || \
       (alpha_char == DT_L_SQ_BRACKET) || \
       (alpha_char == DT_R_SQ_BRACKET) || \
       (alpha_char == DT_L_ANGLE_BRACKET) || \
        (alpha_char == DT_CHAR_ULINE) || \
         (alpha_char == DT_SPACE) || \
           (alpha_char == DT_SEMICOLON) || \
       (alpha_char == DT_R_ANGLE_BRACKET) \
     ) ? 1 : 0 )      

typedef struct
{
   kal_uint8   s0;   /* auto answer */
   kal_uint8   s3;   /* CR */
   kal_uint8   s4;   /* LF */
   kal_uint8   s5;   /* backspace */
   kal_uint8   s6;   /* pause before dialing */
   kal_uint8   s7;   /* connect timeout */
   kal_uint8   s8;   /* , pause time */
   kal_uint8   s10;  /* disconnect timeout */

} dt_s_register_struct;


typedef struct 
{
   kal_bool   echo_flag;        /* rmmi_cmd_echo_enum */
   kal_uint8   suppress_flag;    /* rmmi_result_code_suppress_enum */
   kal_uint8   format;           /* rmmi_result_code_format */   
} dt_rsp_mode_struct;

typedef struct 
{
   kal_uint16  head;
   kal_uint16  length;
   kal_uint8   data[DT_MAX_DATA_INPUT_QUEUE_LENGTH];

} dt_uart_input_queue_struct;

typedef struct 
{
   kal_uint16  head;
   kal_uint16  length;
   kal_uint8   data[DT_MAX_DATA_OUTPUT_QUEUE_LENGTH];

} dt_uart_output_queue_struct;

typedef struct
{
   dt_rsp_mode_struct       	rsp_mode;
   kal_uint8    		error_report_mode; ///* +CMEE <mode>: rmmi_error_report_mode_enum */   
/* Begin of normal case: only one channel for physical UART*/
   dt_uart_input_queue_struct     		uart_input_queue;
   dt_uart_output_queue_struct     	uart_output_queue;

//#ifdef DATA_DOWNLOAD
	FS_HANDLE   fd[2];
	kal_uint32    data_buf_len;
	kal_uint8      data_folder;
 	kal_bool       printingDownloadData_flag ;  /* use to indicate unfinished task of printing download data, rtw_ind will check this */
 	kal_uint16    printingDownloadData_loopCount;
	kal_wchar * downloadFilename;
	kal_wchar*  downloadFullpath;
	//kal_wchar*  data_rename_path[2];
	
#ifdef FMT_NOT_PRESENT 								
	kal_wchar data_filename[50];
#endif /*FMT_NOT_PRESENT*/

//#endif /*DATA_DOWNLOAD*/

   eventid                       event_id[2]; /* 0: keypad
                                                           1: gprs
                                                           2: gprs
                                                           3: retry
                                                           4: hz */
   event_scheduler              *event_scheduler_ptr;
   stack_timer_struct            base_timer;                                                           
   kal_uint16		 	       cmee_err; // error value for +CME:<err>
   void*                       	       arg_list[DT_MAX_ARG_NUM];
   kal_bool                   	       uart_stop_send_flag;
   dt_s_register_struct     	s_reg;
   kal_uint8 	                     transfered_port;
   dt_transfer_type_enum     transfer_type;
   dt_app_type_enum           app_type;
   kal_uint16                        write_data_size;
   kal_uint8                  	       char_set;
   dt_transfer_state_enum     transfer_state;
   kal_bool                           request_from_l4c;/*if request from L4C, after download, upload, and abort, DT should send confirm back 
   											to L4C and let L4C print the result code, if not, DT should print result code by itself.
   											if L4C transfer uart owner to DT, this flag should not be set*/
   kal_wchar 	                    *download_filename; 											
   kal_bool 				abort_download;										
   kal_bool 				download_complete;	  
   #ifdef __GEMINI__
   module_type			src_mod_id;//mtk01616_071114
   #endif
}dt_context_struct;


typedef struct dt_string_struct
{
   kal_uint16   index;
   kal_uint8   *string_ptr;
   kal_uint8   *ip_string; 
   kal_uint8	src_id;
   kal_uint8	cmd_mode;
   //kal_uint16	cmd_index; 
} dt_string_struct;

extern dt_context_struct  dt_context_g;
#define DT_PTR   (&dt_context_g)


#endif /* _DT_CONTEXT_H */

