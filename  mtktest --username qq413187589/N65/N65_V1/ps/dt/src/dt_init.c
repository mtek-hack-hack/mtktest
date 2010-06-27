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
 *	dt_init.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains all the functions that to be called at init phase,
 *    reset phase, and de-init phase.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *
 *******************************************************************************/


 
#define DT_INIT_C

#include <stdlib.h>
#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"
#include "event_shed.h"

#include "uart_sw.h"
#include "dt_common_enum.h"
#include "dt_context.h"
#include "l4c_common_enum.h"
/*Declarations for Global variable*/
dt_context_struct dt_context_g;


/*****************************************************************************
* FUNCTION
*  dt_start_base_timer
*
* DESCRIPTION
*   This is dt_start_base_timer function of L4C module.
*   provide the function pointer for create a event scheduler
*
* PARAMETERS
*  base_timer_ptr     IN       pointer to timer
*  time_out           IN       time out value
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_start_base_timer(void *base_timer_ptr,unsigned int time_out)
{
	stack_start_timer((stack_timer_struct *)base_timer_ptr, 0, time_out);
	return;
}


/*****************************************************************************
* FUNCTION
*  dt_stop_base_timer
*
* DESCRIPTION
*   This is dt_stop_base_timer function of L4C module.
*   provide the function pointer for create a event scheduler
*
* PARAMETERS
*  base_timer_ptr     IN       pointer to timer
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_stop_base_timer(void *base_timer_ptr)
 {
	stack_stop_timer((stack_timer_struct *)base_timer_ptr);
	return;
}


/*************************************************************************
* FUNCTION                                                            
*	dt_init_context
* DESCRIPTION                                                           
*  This function should be called to reset the DT Context. 
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/

void dt_init_context(void)
{
#ifdef __GEMINI__
kal_uint8 dual_sim_mode_setting, dual_sim_inserted_status, dual_sim_uart_setting;
#endif

//#ifdef DATA_DOWNLOAD
DT_PTR->fd[0] = 0;
DT_PTR->fd[1] = 0;
DT_PTR->printingDownloadData_flag = KAL_FALSE;
DT_PTR->printingDownloadData_loopCount = 0;
DT_PTR->downloadFilename = NULL;
DT_PTR->downloadFullpath = NULL;
//DT_PTR->data_rename_path[0]= NULL;
//DT_PTR->data_rename_path[1] = NULL;	
	
//#ifdef FMT_NOT_PRESENT 								
//  	kal_mem_set((kal_wchar *)L4C_PTR->data_filename, 0, sizeof(kal_wchar)*50);
//#endif	
//#endif /*  DATA_DOWNLOAD*/
DT_PTR->s_reg.s0 = 0;
DT_PTR->s_reg.s3 = 13;
DT_PTR->s_reg.s4 = 10;
DT_PTR->s_reg.s5 = 8;
DT_PTR->s_reg.s6 = 2;
DT_PTR->s_reg.s7 = 0;
DT_PTR->s_reg.s8 = 2;
DT_PTR->s_reg.s10 = 0;

DT_PTR->rsp_mode.echo_flag = KAL_FALSE;
DT_PTR->error_report_mode = DT_SIMPLE_ERROR;
DT_PTR->rsp_mode.format = DT_VERBOSE_FULL_HEAD_TAIL;

DT_PTR->uart_stop_send_flag = KAL_FALSE;
DT_PTR->transfered_port = 0xff;
DT_PTR->transfer_type = DT_NO_TRANSFER_TYPE;
DT_PTR->app_type = DT_NO_APP_TYPE;
DT_PTR->write_data_size = DT_UPLOAD_SIZE;//cage_write
DT_PTR->char_set = DT_CHSET_UCS2; /* default value */
DT_PTR->transfer_state = DT_IDLE_STATE;
DT_PTR->request_from_l4c = KAL_FALSE;

DT_PTR->uart_output_queue.head = 0;
DT_PTR->uart_output_queue.length = 0;	

DT_PTR->uart_input_queue.head = 0;
DT_PTR->uart_input_queue.length = 0;

DT_PTR->download_filename = NULL;
DT_PTR->abort_download = KAL_FALSE;
DT_PTR->download_complete = KAL_FALSE;


//stack_init_timer (&DT_PTR->base_timer, "DT_Base_Timer", MOD_DT);

//DT_PTR->event_scheduler_ptr = new_evshed(&DT_PTR->base_timer,
//               dt_start_base_timer, dt_stop_base_timer,
//               0 , kal_evshed_get_mem, kal_evshed_free_mem, 255);

//return KAL_TRUE;
}


/*************************************************************************
* FUNCTION                                                            
*	dt_reset
* DESCRIPTION                                                           
*  This function should be called to reset the DT Context to 
*  Its initial state. 
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
kal_bool dt_reset(task_indx_type task_indx) 
{

   
   /* reset dt module context */
   dt_init_context();

   return KAL_TRUE;

}	/* End of cc_reset */

/*************************************************************************
* FUNCTION                                                            
*	dt_init
* DESCRIPTION                                                           
*  This function should be called to Initialize the DT Module:
*  2. Initializes Module Context Structure default value
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
kal_bool dt_init(task_indx_type task_indx) 
{
   kal_uint32 my_index;;
   
   kal_get_my_task_index( &my_index );
   stack_set_active_module_id( my_index, MOD_DT );  

   stack_init_timer (&DT_PTR->base_timer, "DT_Base_Timer", MOD_DT);
   
   DT_PTR->event_scheduler_ptr = new_evshed(&DT_PTR->base_timer,
				  dt_start_base_timer, dt_stop_base_timer,
				  0 , kal_evshed_get_mem, kal_evshed_free_mem, 255);

   /* init context default value */
   dt_init_context();
   return KAL_TRUE;

}	/* End of cc_init */




