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
 * dt_create.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DT task create function and message handler 
 *   entry point.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
#define  DT_CREATE_C

#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       	/* Event scheduler */
#include "stack_timer.h"      	/* Stack timer */

#include "dt_common_enum.h"
#include "uart_sw.h"
#include "dt_context.h"

#include "dt_utility.h"
#include "dt_analyzer.h"

//#include "dt_aux_msg_hdlr.h"

void dt_task_main( task_entry_struct *task_entry_ptr);
extern kal_bool dt_init( task_indx_type task_indx );
extern void dt_main( ilm_struct *ilm_ptr);
extern kal_bool dt_reset( task_indx_type task_indx ); 

/*************************************************************************
* FUNCTION                                                            
*	dt_create
* DESCRIPTION                                                           
*  This function is used to create DT task
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
kal_bool dt_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct dt_handler_info = 
	{
		dt_task_main,			/* task entry function */
		dt_init,			/* task initialization function */
		NULL,		/* task configuration function */
		dt_reset,				/* task reset handler */
		NULL,				/* task termination handler */
	};

	*handle = (comptask_handler_struct *) &dt_handler_info;
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	dt_task_main
* DESCRIPTION                                                           
*  This function is used to be DT task entry point
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void dt_task_main( task_entry_struct *task_entry_ptr)
{
	ilm_struct current_ilm;
	kal_uint32 my_index;

	kal_get_my_task_index(&my_index);

	while (1) 
   {

		receive_msg_ext_q( 
			task_info_g[task_entry_ptr->task_indx].task_ext_qid, 
			&current_ilm);
		stack_set_active_module_id( my_index, current_ilm.dest_mod_id );

		dt_main((void *) &current_ilm);
				
		free_ilm( &current_ilm);

      		if (DT_PTR->uart_input_queue.length > 0)
      		{
      			dt_process_one_cmd();
      		}
//#ifdef DATA_DOWNLOAD
//#if !(defined(__SLIM_AT__) || defined( __EM_AT_ONLY__))
		if ((DT_PTR->printingDownloadData_flag == KAL_TRUE) && (DT_PTR->uart_stop_send_flag == KAL_FALSE))
		//(!(DT_PTR->uart_stop_send_flag & (0x01 << 0))))
		{		
			dt_eq_fs_read_req();
		}
//#endif
//#endif

	}
} 


